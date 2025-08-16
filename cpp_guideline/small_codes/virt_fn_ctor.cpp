#include <iostream>

using namespace std;
/* Wrong way
class Transaction 
{
public:
    Transaction() 
    {
        logTransaction(); // as final action, log this transaction
    } 
    virtual void logTransaction() const = 0; // make type-dependent log entry
};

class BuyTransaction: public Transaction 
{
public:
    virtual void logTransaction() const // how to log transactions of this type
    {
        cout << "log buy transaction " << endl;
    }
};*/

class Transaction 
{
    public:
        explicit Transaction( const std::string& logInfo ) 
        {
            cout << "Transaction constructor called \n";
            logTransaction( logInfo );
        }
        void logTransaction( const std::string& logInfo ) const {
            cout << logInfo << endl;
        }
    };
    class BuyTransaction: public Transaction {
    public:
        BuyTransaction( const int parameter ): Transaction( createLogString( parameter ) ) {
            cout << "BuyTransaction constructor called \n";
        }
    private:
        static std::string createLogString( const int parameters )
        {
            return string( "bought " + to_string(parameters) );
        }
    };

int main()
{
    BuyTransaction buy( 100 );
    return 0;
}
