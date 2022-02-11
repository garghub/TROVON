void F_1 ( char V_1 )
{
char * V_2 ;
* V_3 . V_4 = V_1 ;
F_2 () ;
V_2 = V_3 . V_4 + 1 ;
if ( V_2 >= V_3 . V_5 )
V_2 = V_3 . V_6 ;
V_3 . V_4 = V_2 ;
}
int F_3 ( void )
{
char V_1 ;
char * V_7 ;
if ( * V_3 . V_8 ) {
V_1 = * V_3 . V_8 ;
V_7 = V_3 . V_8 + 1 ;
if ( V_7 >= V_3 . V_9 )
V_7 = V_3 . V_10 ;
else if ( * V_7 == '\0' )
V_7 = V_3 . V_10 ;
* V_3 . V_8 = '\0' ;
F_2 () ;
V_3 . V_8 = V_7 ;
return V_1 ;
}
return - 1 ;
}
int F_4 ( void )
{
int V_1 ;
while ( 1 ) {
V_1 = F_3 () ;
if ( V_1 == - 1 )
F_5 () ;
else
break;
}
return V_1 ;
}
void F_6 ( void )
{
V_11 = F_1 ;
V_12 = F_4 ;
V_13 = F_3 ;
}
