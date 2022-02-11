static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
F_2 ( F_3 ( V_2 , V_3 , V_4 ) , 0xCF8 ) ;
switch ( V_5 ) {
case 1 :
* V_6 = F_4 ( 0xCFC + ( V_4 & 3 ) ) ;
break;
case 2 :
* V_6 = F_5 ( 0xCFC + ( V_4 & 2 ) ) ;
break;
case 4 :
* V_6 = F_6 ( 0xCFC ) ;
break;
}
return V_7 ;
}
static int
F_7 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 V_6 )
{
F_2 ( F_3 ( V_2 , V_3 , V_4 ) , 0xCF8 ) ;
switch ( V_5 ) {
case 1 :
F_8 ( V_6 , 0xCFC + ( V_4 & 3 ) ) ;
break;
case 2 :
F_9 ( V_6 , 0xCFC + ( V_4 & 2 ) ) ;
break;
case 4 :
F_2 ( V_6 , 0xCFC ) ;
break;
}
return V_7 ;
}
void T_2 F_10 ( void )
{
F_11 ( V_8 L_1 ) ;
if ( ! F_12 ( 0xA8 , 2 , L_2 ) ) {
F_11 ( V_9 L_3 ) ;
return;
}
if ( ! F_12 ( 0xCF8 , 8 , L_4 ) ) {
F_11 ( V_9 L_5 ) ;
F_13 ( 0xA8 , 2 ) ;
return;
}
F_8 ( 0x96 , 0xA8 ) ;
F_8 ( 0x18 , 0xA9 ) ;
F_8 ( 0x93 , 0xA8 ) ;
F_8 ( 0xd0 , 0xA9 ) ;
}
int T_2 F_14 ( int V_10 , struct V_11 * V_12 )
{
return ( V_10 == 0 ) ;
}
struct V_1 * T_2 F_15 ( int V_10 , struct V_11 * V_13 )
{
if ( V_10 == 0 )
return F_16 ( NULL , 0 , & V_14 , V_13 ,
& V_13 -> V_15 ) ;
return NULL ;
}
