const char * F_1 ( void )
{
#define F_2 64
static char system [ F_2 ] ;
static int V_1 = 0 ;
if ( V_1 == 0 ) {
V_1 = 1 ;
snprintf ( system , F_2 , L_1 ,
V_2 [ V_3 ] ) ;
}
return system ;
}
static inline void F_3 ( void )
{
V_4 = V_5 ;
V_6 = V_7 ;
V_8 = ( void * ) F_4 ( V_4 + V_9 ) ;
}
static inline void F_5 ( void )
{
V_4 = V_5 ;
V_6 = V_7 ;
V_8 = ( void * ) F_4 ( V_4 + V_9 ) ;
}
static inline void F_6 ( void )
{
V_4 = V_10 ;
V_6 = V_11 ;
V_12 = 1 ;
V_8 = ( void * ) F_4 ( V_4 + V_13 ) ;
}
static inline void F_7 ( void )
{
V_4 = V_14 ;
V_6 = V_15 ;
V_12 = 1 ;
V_16 = ( void * ) F_4 ( V_4 + V_17 ) ;
V_8 = ( void * ) F_4 ( V_4 + V_18 ) ;
}
static inline void F_8 ( void )
{
V_4 = V_19 ;
V_6 = V_15 ;
V_12 = 1 ;
V_16 = ( void * ) F_4 ( V_4 + V_17 ) ;
V_8 = ( void * ) F_4 ( V_4 + V_18 ) ;
}
void T_1 F_9 ( T_2 V_20 )
{
unsigned char V_21 , V_22 , V_23 , V_24 ;
T_2 V_25 ;
if ( ! F_10 ( V_20 ) ) {
V_25 = F_11 ( F_12 ( L_2 ) ,
( char * * ) 0 , 0 ) ;
} else {
V_25 = F_13 () ;
if ( V_25 == 0 ) {
F_14 ( L_3
L_4 ) ;
V_25 = 1 ;
}
}
V_21 = ( V_25 & 0xff000000 ) >> 24 ;
V_24 = ( V_25 & 0xff0000 ) >> 16 ;
V_22 = ( V_25 & 0xff00 ) >> 8 ;
V_23 = V_25 & 0xff ;
switch ( V_24 ) {
case V_26 :
V_3 = V_27 ;
F_3 () ;
break;
case V_28 :
V_3 = V_29 ;
F_5 () ;
break;
case V_30 :
V_3 = V_31 ;
F_6 () ;
break;
case V_32 :
V_3 = V_33 ;
F_7 () ;
break;
case V_34 :
V_3 = V_35 ;
F_8 () ;
if ( ! ( F_15 ( V_36 ) & V_37 ) )
V_3 = V_38 ;
break;
case V_39 :
V_3 = V_40 ;
F_7 () ;
break;
case V_41 :
V_3 = V_42 ;
break;
case V_43 :
V_3 = V_44 ;
break;
case V_45 :
V_3 = V_46 ;
break;
default:
V_3 = V_47 ;
break;
}
if ( V_3 == V_47 )
F_14 ( L_5 ,
V_2 [ V_3 ] , V_24 ) ;
else
F_14 ( L_6 , V_2 [ V_3 ] ) ;
}
