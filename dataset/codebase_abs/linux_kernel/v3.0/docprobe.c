static inline int T_1 F_1 ( void T_2 * V_1 , unsigned long V_2 )
{
void T_2 * V_3 = V_1 ;
unsigned char V_4 , V_5 , V_6 , V_7 ;
#ifndef F_2
unsigned char V_8 ;
#endif
#ifdef F_3
if ( F_4 ( V_3 , V_9 ) != 0x55 || F_4 ( V_3 , V_10 ) != 0xaa )
return 0 ;
#endif
#ifndef F_2
V_8 = F_4 ( V_3 , V_11 ) ;
F_5 ( V_12 | V_13 | V_14 ,
V_3 , V_11 ) ;
F_5 ( V_12 | V_13 | V_14 ,
V_3 , V_11 ) ;
F_5 ( V_12 | V_13 | V_15 ,
V_3 , V_11 ) ;
F_5 ( V_12 | V_13 | V_15 ,
V_3 , V_11 ) ;
#endif
V_7 = F_4 ( V_3 , V_7 ) ;
switch ( V_7 ) {
case V_16 :
V_4 = F_4 ( V_3 , 2k_ECCStatus ) & V_17 ;
V_5 = F_4 ( V_3 , 2k_ECCStatus ) & V_17 ;
V_6 = F_4 ( V_3 , 2k_ECCStatus ) & V_17 ;
if ( V_4 != V_5 && V_4 == V_6 )
return V_7 ;
break;
case V_18 :
F_4 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( F_4 ( V_3 , V_7 ) != V_18 )
V_7 = V_19 ;
V_4 = F_4 ( V_3 , V_20 ) & V_17 ;
V_5 = F_4 ( V_3 , V_20 ) & V_17 ;
V_6 = F_4 ( V_3 , V_20 ) & V_17 ;
if ( V_4 != V_5 && V_4 == V_6 )
return V_7 ;
break;
case V_21 :
case V_22 :
case 0 :
#ifndef F_2
for ( V_4 = 0 ; ( V_4 < 4 ) ; V_4 ++ )
F_4 ( V_3 , V_23 ) ;
V_4 = V_14 | V_13 | V_24 |
V_25 ;
F_5 ( V_4 , V_3 , V_26 ) ;
F_5 ( ~ V_4 , V_3 , V_27 ) ;
F_6 ( 1 ) ;
V_4 = V_15 | V_13 | V_24 |
V_25 ;
F_5 ( V_4 , V_3 , V_26 ) ;
F_5 ( ~ V_4 , V_3 , V_27 ) ;
F_6 ( 1 ) ;
#endif
V_7 = F_4 ( V_3 , V_7 ) ;
switch ( V_7 ) {
case V_21 :
case V_22 :
V_4 = F_4 ( V_3 , V_28 ) & V_17 ;
V_5 = F_4 ( V_3 , V_28 ) & V_17 ;
V_6 = F_4 ( V_3 , V_28 ) & V_17 ;
if ( V_4 != V_5 && V_4 == V_6 )
return V_7 ;
default:
break;
}
default:
#ifdef F_3
F_7 ( V_29 L_1 ,
V_7 , V_2 ) ;
#endif
#ifndef F_2
F_5 ( V_8 , V_3 , V_11 ) ;
#endif
return 0 ;
}
F_7 ( V_30 L_2 ) ;
#ifndef F_2
F_5 ( V_8 , V_3 , V_11 ) ;
#endif
return 0 ;
}
static void T_1 F_8 ( unsigned long V_2 )
{
void T_2 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
int V_7 ;
char V_36 [ 15 ] ;
char * V_37 = V_36 ;
void (* F_9)( struct V_34 * ) = NULL ;
V_31 = F_10 ( V_2 , V_38 ) ;
if ( ! V_31 )
return;
if ( ( V_7 = F_1 ( V_31 , V_2 ) ) ) {
if ( V_7 == V_19 ) {
F_7 ( V_39 L_3 ) ;
F_11 ( V_31 ) ;
return;
}
V_40 = 1 ;
V_35 = F_12 ( sizeof( struct V_32 ) + sizeof( struct V_34 ) , V_41 ) ;
if ( ! V_35 ) {
F_7 ( V_30 L_4 ) ;
F_11 ( V_31 ) ;
return;
}
V_33 = (struct V_32 * ) ( & V_35 [ 1 ] ) ;
memset ( ( char * ) V_35 , 0 , sizeof( struct V_34 ) ) ;
memset ( ( char * ) V_33 , 0 , sizeof( struct V_32 ) ) ;
V_35 -> V_42 = V_33 ;
V_33 -> V_43 = V_31 ;
V_33 -> V_2 = V_2 ;
V_33 -> V_7 = V_7 ;
sprintf ( V_36 , L_5 , V_7 ) ;
switch( V_7 ) {
case V_19 :
V_37 = L_6 ;
F_9 = F_13 ( V_44 ) ;
break;
case V_16 :
V_37 = L_7 ;
F_9 = F_13 ( V_44 ) ;
break;
case V_18 :
V_37 = L_8 ;
#ifdef F_14
F_9 = F_13 ( V_44 ) ;
#else
F_9 = F_13 ( V_45 ) ;
#endif
break;
case V_21 :
case V_22 :
V_37 = L_9 ;
F_9 = F_13 ( V_46 ) ;
break;
}
if ( F_9 ) {
(* F_9)( V_35 ) ;
F_15 ( F_9 ) ;
return;
}
F_7 ( V_39 L_10 , V_37 , V_2 ) ;
F_16 ( V_35 ) ;
}
F_11 ( V_31 ) ;
}
static int T_1 F_17 ( void )
{
int V_47 ;
if ( V_48 ) {
F_7 ( V_49 L_11 , V_48 ) ;
F_8 ( V_48 ) ;
} else {
for ( V_47 = 0 ; ( V_50 [ V_47 ] != 0xffffffff ) ; V_47 ++ ) {
F_8 ( V_50 [ V_47 ] ) ;
}
}
if ( ! V_40 )
F_7 ( V_49 L_12 ) ;
return - V_51 ;
}
