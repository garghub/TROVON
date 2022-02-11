int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_2 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return ( ( V_4 + V_3 ) % 4 ) + V_5 ;
}
static void F_3 ( struct V_6 * V_7 ,
unsigned int V_8 , int V_9 )
{
union V_10 V_11 = { . V_12 = 0 } ;
V_11 . V_13 = V_9 ;
V_11 . V_14 = V_8 ;
V_11 . V_15 = V_7 -> V_16 ;
V_11 . V_17 = 1 ;
F_4 ( V_11 . V_12 , V_18 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
unsigned int V_8 , int V_9 , int V_19 , T_2 V_20 )
{
F_3 ( V_7 , V_8 , V_9 ) ;
switch ( V_19 ) {
case 1 :
F_6 ( V_20 , V_21 + ( V_9 & 3 ) ) ;
break;
case 2 :
F_7 ( V_20 , V_21 + ( V_9 & 2 ) ) ;
break;
case 4 :
F_4 ( V_20 , V_21 ) ;
break;
}
return V_22 ;
}
static int F_8 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_9 , int V_19 , T_2 * V_20 )
{
F_3 ( V_7 , V_8 , V_9 ) ;
switch ( V_19 ) {
case 1 :
* V_20 = F_9 ( V_21 + ( V_9 & 3 ) ) ;
break;
case 2 :
* V_20 = F_10 ( V_21 + ( V_9 & 2 ) ) ;
break;
case 4 :
* V_20 = F_11 ( V_21 ) ;
break;
}
return V_22 ;
}
static int T_3 F_12 ( void )
{
F_13 ( L_1 ) ;
F_14 ( V_23 ) ;
V_24 . V_25 = V_26 ;
F_15 ( & V_24 ) ;
return 0 ;
}
