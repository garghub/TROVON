int F_1 ( bool V_1 )
{
if ( ! V_2 || ! V_3 )
return - V_4 ;
F_2 ( L_1 ,
V_1 ? L_2 : L_3 ) ;
if ( V_1 )
return V_2 () ;
else
return V_3 () ;
}
void F_3 ( struct V_5 * V_6 )
{
int V_7 ;
unsigned int V_8 , V_9 ;
if ( ! V_10 )
return;
V_7 = V_10 () ;
switch ( V_7 ) {
case 337500 :
V_8 = 16 ;
V_9 = 225 ;
break;
case 450000 :
default:
V_8 = 4 ;
V_9 = 75 ;
break;
case 540000 :
V_8 = 4 ;
V_9 = 90 ;
break;
case 675000 :
V_8 = 8 ;
V_9 = 225 ;
break;
}
F_4 ( V_6 , V_11 , V_8 ) ;
F_4 ( V_6 , V_12 , V_9 ) ;
}
int F_5 ( void )
{
int V_13 = 0 ;
V_2 = F_6 ( V_14 ) ;
if ( ! V_2 ) {
F_7 ( L_4 ) ;
return - V_4 ;
}
V_3 = F_6 ( V_15 ) ;
if ( ! V_3 ) {
F_8 ( V_14 ) ;
V_2 = NULL ;
return - V_4 ;
}
V_10 = F_6 ( V_16 ) ;
if ( ! V_10 )
F_7 ( L_5 ) ;
F_2 ( L_6 ) ;
return V_13 ;
}
int F_9 ( void )
{
if ( V_2 ) {
F_8 ( V_14 ) ;
V_2 = NULL ;
}
if ( V_3 ) {
F_8 ( V_15 ) ;
V_3 = NULL ;
}
if ( V_10 ) {
F_8 ( V_16 ) ;
V_10 = NULL ;
}
return 0 ;
}
