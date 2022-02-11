unsigned long long int F_1 ( const char * V_1 , char * * V_2 , int V_3 )
{
unsigned long long V_4 = 0 ;
if ( V_3 > 36 )
goto V_5;
while ( * V_1 ) {
int V_6 ;
if ( * V_1 >= '0' && * V_1 <= '9' && * V_1 < '0' + V_3 )
V_6 = * V_1 - '0' ;
else if ( * V_1 >= 'A' && * V_1 < 'A' + V_3 - 10 )
V_6 = * V_1 - 'A' + 10 ;
else if ( * V_1 >= 'a' && * V_1 < 'a' + V_3 - 10 )
V_6 = * V_1 - 'a' + 10 ;
else
break;
V_4 *= V_3 ;
V_4 += V_6 ;
V_1 ++ ;
}
V_5:
if ( V_2 )
* V_2 = ( char * ) V_1 ;
return V_4 ;
}
