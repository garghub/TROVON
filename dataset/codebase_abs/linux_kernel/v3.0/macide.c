int F_1 ( T_1 * V_1 )
{
if ( * V_2 & 0x20 )
return 1 ;
return 0 ;
}
static void F_2 ( T_2 * V_3 )
{
* V_2 &= ~ 0x20 ;
}
static void T_3 F_3 ( struct V_4 * V_5 , unsigned long V_6 ,
int V_7 )
{
int V_8 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
V_5 -> V_9 [ V_8 ] = V_6 + V_8 * 4 ;
V_5 -> V_10 . V_11 = V_6 + V_12 ;
V_5 -> V_7 = V_7 ;
}
static int T_3 F_4 ( void )
{
unsigned long V_6 ;
int V_7 ;
struct V_4 V_5 , * V_13 [] = { & V_5 } ;
struct V_14 V_15 = V_16 ;
if ( ! V_17 )
return - V_18 ;
switch ( V_19 -> V_20 ) {
case V_21 :
V_6 = V_22 ;
V_7 = V_23 ;
break;
case V_24 :
V_6 = V_22 ;
V_7 = V_25 ;
break;
case V_26 :
V_6 = V_27 ;
V_15 . V_28 = NULL ;
V_7 = V_29 ;
break;
default:
return - V_18 ;
}
F_5 ( V_30 L_1 ,
V_31 [ V_19 -> V_20 - 1 ] ) ;
F_3 ( & V_5 , V_6 , V_7 ) ;
return F_6 ( & V_15 , V_13 , 1 , NULL ) ;
}
