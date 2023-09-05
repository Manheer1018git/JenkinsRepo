pipeline{
    agent any
    stages{
        stage('Build'){
            steps{
                echo "Building the code using Maven."
            }
        }
        stage('Unit and Integration Tests'){
            steps{
                echo "Executing unit tests using Mocha to ensure that the code functions as expected"
                echo "Executing integration tests using Mocha to ensure that the different components of the application work together as expected" 
            }
            post{
                success{
                    emailext(
                        from: "manheer1018@gmail.com",
                        subject: "Unit and Integration tests",
                        body: "Tests were successful",
                        attachLog: true,
                        to: "manheer1018@gmail.com"
                    )      
                }  
                failure{
                    emailext(
                        from: "manheer1018@gmail.com",
                        subject: "Unit and Integration tests",
                        body: "Tests failed",
                        attachLog: true,
                        to: "manheer1018@gmail.com"
                    )
                }             
            }
        }
        stage('Code Analysis'){
            steps{
                echo "Analysing the quality of the code using SonarQube to check whether it meets the industry standards"
            }
        }
        stage('Security Scan'){
            steps{
                echo "Scanning the code using OWASP ZAP to check for any vulnerabilities"
            }
            post{
                success{
                    emailext(
                        from: "manheer1018@gmail.com",
                        subject: "Security Scans",
                        body: "Security scans were successful",
                        to: "manheer1018@gmail.com"
                    )
                }  
                failure{
                    emailext(
                        from: "manheer1018@gmail.com",
                        subject: "Security Scans",
                        body: "Security scans failed",
                        to: "manheer1018@gmail.com"
                    )
                }              
            }
        }
        stage('Deploying to Staging'){
            steps{
                echo "Deploying the application using AWS CodeDeploy to the AWS EC2 instance"
            }
        }
        stage('Integration Tests on Staging'){
            steps{
                echo "Running integration tests using Postman to ensure the functioning of the applications as expected"
            }
        }
        stage('Deploy to Production'){
            steps{
                echo "Deploying code to the production environment using AWS Elastic Beanstalk"
            }
        }
    }
}
