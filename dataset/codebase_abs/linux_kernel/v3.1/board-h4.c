static T_1 F_1 ( void )
{
return ( F_2 ( V_1 ) &
( V_2 | V_3 |
V_4 | V_5 |
V_6 | V_7 ) ) ;
}
static T_1 F_3 ( void )
{
T_1 V_8 ;
V_8 = F_1 () ;
if ( ( V_8 & 0xF ) == 0xd )
return 1 ;
if ( V_8 & 0x2 )
return 1 ;
else
return 0 ;
}
static inline void T_2 F_4 ( void )
{
int V_9 ;
unsigned long V_10 ;
unsigned int V_11 , V_12 ;
struct V_13 * V_14 ;
V_9 = V_15 ;
V_14 = F_5 ( NULL , L_1 ) ;
if ( F_6 ( V_14 ) ) {
F_7 ( 1 ) ;
return;
}
F_8 ( V_14 ) ;
V_12 = F_9 ( V_14 ) ;
F_10 ( V_14 ) ;
F_11 ( V_14 ) ;
if ( F_3 () )
V_11 = 0x200 ;
else
V_11 = 0 ;
F_12 ( V_9 , V_16 ,
0x00011000 | V_11 ) ;
if ( V_12 >= 160000000 ) {
F_12 ( V_9 , V_17 , 0x001f1f01 ) ;
F_12 ( V_9 , V_18 , 0x00080803 ) ;
F_12 ( V_9 , V_19 , 0x1c0b1c0a ) ;
F_12 ( V_9 , V_20 , 0x041f1F1F ) ;
F_12 ( V_9 , V_21 , 0x000004C4 ) ;
} else if ( V_12 >= 130000000 ) {
F_12 ( V_9 , V_17 , 0x001f1f00 ) ;
F_12 ( V_9 , V_18 , 0x00080802 ) ;
F_12 ( V_9 , V_19 , 0x1C091C09 ) ;
F_12 ( V_9 , V_20 , 0x041f1F1F ) ;
F_12 ( V_9 , V_21 , 0x000004C4 ) ;
} else {
F_12 ( V_9 , V_17 , 0x001f1f00 ) ;
F_12 ( V_9 , V_18 , 0x00080802 ) ;
F_12 ( V_9 , V_19 , 0x1C091C09 ) ;
F_12 ( V_9 , V_20 , 0x031A1F1F ) ;
F_12 ( V_9 , V_21 , 0x000003C2 ) ;
}
if ( F_13 ( V_9 , V_22 , & V_10 ) < 0 ) {
F_14 ( V_23 L_2 ) ;
goto V_24;
}
F_15 ( 100 ) ;
F_16 ( 92 , 0 ) ;
if ( F_17 ( V_10 , V_25 ) < 0 )
F_18 ( V_9 ) ;
V_24:
F_10 ( V_14 ) ;
F_11 ( V_14 ) ;
}
static void T_2 F_19 ( void )
{
unsigned long V_26 ;
if ( F_13 ( V_27 , V_28 , & V_26 ) < 0 ) {
F_14 ( L_3 ) ;
return;
}
V_29 . V_30 = V_26 ;
V_29 . V_31 = V_26 + V_28 - 1 ;
}
static void T_2 F_20 ( void )
{
F_21 () ;
F_22 ( NULL , NULL ) ;
}
static void T_2 F_23 ( void )
{
F_24 () ;
}
static void T_2 F_25 ( void )
{
F_26 ( V_32 , V_33 ) ;
V_34 = V_35 ;
V_36 = F_27 ( V_35 ) ;
#if F_28 ( V_37 ) || F_28 ( V_38 )
F_16 ( 88 , V_39 | V_40 ) ;
F_16 ( 89 , V_39 | V_40 ) ;
F_16 ( 124 , V_39 | V_40 ) ;
F_29 ( L_4 , V_39 | V_40 ) ;
if ( F_30 () ) {
F_29 ( L_5 ,
V_39 | V_40 ) ;
F_29 ( L_6 , 0 ) ;
F_29 ( L_7 , 0 ) ;
V_41 [ 5 ] = 0 ;
V_42 [ 2 ] = 15 ;
V_42 [ 6 ] = 18 ;
} else {
F_29 ( L_8 , V_39 | V_40 ) ;
F_29 ( L_9 , 0 ) ;
F_29 ( L_7 , 0 ) ;
}
F_29 ( L_10 , 0 ) ;
F_29 ( L_11 , 0 ) ;
F_29 ( L_12 , 0 ) ;
F_29 ( L_13 , 0 ) ;
F_29 ( L_14 , 0 ) ;
#endif
F_31 ( 1 , V_43 ,
F_27 ( V_43 ) ) ;
F_32 ( V_44 , F_27 ( V_44 ) ) ;
F_33 ( & V_45 ) ;
F_34 () ;
F_19 () ;
}
static void T_2 F_35 ( void )
{
F_36 () ;
F_37 () ;
}
