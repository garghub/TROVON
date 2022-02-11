static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
do {
V_4 = F_2 ( V_1 ) ;
if ( ( V_4 & V_2 ) == V_3 )
break;
} while ( 1 );
}
static void F_3 ( unsigned char V_5 )
{
void T_1 * V_6 = ( void T_1 * ) ( F_4 ( V_7 ) ) ;
F_1 ( V_6 + V_8 * 4 , V_9 , V_9 ) ;
F_5 ( V_5 , V_6 + V_10 * 4 ) ;
F_1 ( V_6 + V_8 * 4 , V_9 , V_9 ) ;
}
static void F_6 ( unsigned char V_5 )
{
void T_1 * V_6 = ( void T_1 * ) ( F_4 ( V_11 ) ) ;
F_1 ( V_6 + V_12 , V_13 ,
V_13 ) ;
F_5 ( V_13 | V_5 , V_6 + V_12 ) ;
F_1 ( V_6 + V_12 , V_13 ,
V_13 ) ;
}
static void F_7 ( unsigned char V_5 )
{
}
static void F_8 ( void )
{
void T_1 * V_6 ;
T_2 V_14 ;
V_6 = ( void T_1 * ) ( F_4 ( V_15 ) ) ;
V_14 = F_2 ( V_6 + V_16 ) ;
V_14 &= V_17 ;
switch ( V_14 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_28 = F_3 ;
break;
case V_29 :
case V_30 :
V_28 = F_6 ;
break;
default:
V_28 = F_7 ;
break;
}
}
void F_9 ( unsigned char V_5 )
{
if ( ! V_28 )
F_8 () ;
V_28 ( V_5 ) ;
}
