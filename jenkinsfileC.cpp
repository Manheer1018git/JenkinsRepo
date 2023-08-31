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
                    mail to: "manheer1018@gmail.com",
                    subject: "Test result",
                    body: "Tests are successful"             
                }  
                failure{
                    mail to: "manheer1018@gmail.com",
                    subject: "Test result",
                    body: "Tests failed"
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
                    mail to: "manheer1018@gmail.com",
                    subject: "Security Scan result",
                    body: "Security Scan successful"
                }  
                failure{
                    mail to: "manheer1018@gmail.com",
                    subject: "Security Scan result",
                    body: "Security Scan failed"
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
