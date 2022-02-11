static void T_1 F_1 ( void )
{
F_2 ( 88 , V_1 | V_2 ) ;
F_2 ( 89 , V_1 | V_2 ) ;
F_2 ( 124 , V_1 | V_2 ) ;
F_3 ( L_1 , V_1 | V_2 ) ;
if ( F_4 () ) {
F_3 ( L_2 ,
V_1 | V_2 ) ;
F_3 ( L_3 , 0 ) ;
F_3 ( L_4 , 0 ) ;
V_3 [ 5 ] = 0 ;
V_4 [ 2 ] = 15 ;
V_4 [ 6 ] = 18 ;
} else {
F_3 ( L_5 , V_1 | V_2 ) ;
F_3 ( L_6 , 0 ) ;
F_3 ( L_4 , 0 ) ;
}
F_3 ( L_7 , 0 ) ;
F_3 ( L_8 , 0 ) ;
F_3 ( L_9 , 0 ) ;
F_3 ( L_10 , 0 ) ;
F_3 ( L_11 , 0 ) ;
F_5 ( & V_5 ) ;
}
static inline void F_1 ( void )
{
}
static T_2 F_6 ( void )
{
return ( F_7 ( V_6 ) &
( V_7 | V_8 |
V_9 | V_10 |
V_11 | V_12 ) ) ;
}
static T_2 F_8 ( void )
{
T_2 V_13 ;
V_13 = F_6 () ;
if ( ( V_13 & 0xF ) == 0xd )
return 1 ;
if ( V_13 & 0x2 )
return 1 ;
else
return 0 ;
}
static inline void T_1 F_9 ( void )
{
int V_14 ;
unsigned long V_15 ;
unsigned int V_16 , V_17 ;
struct V_18 * V_19 ;
V_14 = V_20 ;
V_19 = F_10 ( NULL , L_12 ) ;
if ( F_11 ( V_19 ) ) {
F_12 ( 1 ) ;
return;
}
F_13 ( V_19 ) ;
V_17 = F_14 ( V_19 ) ;
F_15 ( V_19 ) ;
F_16 ( V_19 ) ;
if ( F_8 () )
V_16 = 0x200 ;
else
V_16 = 0 ;
F_17 ( V_14 , V_21 ,
0x00011000 | V_16 ) ;
if ( V_17 >= 160000000 ) {
F_17 ( V_14 , V_22 , 0x001f1f01 ) ;
F_17 ( V_14 , V_23 , 0x00080803 ) ;
F_17 ( V_14 , V_24 , 0x1c0b1c0a ) ;
F_17 ( V_14 , V_25 , 0x041f1F1F ) ;
F_17 ( V_14 , V_26 , 0x000004C4 ) ;
} else if ( V_17 >= 130000000 ) {
F_17 ( V_14 , V_22 , 0x001f1f00 ) ;
F_17 ( V_14 , V_23 , 0x00080802 ) ;
F_17 ( V_14 , V_24 , 0x1C091C09 ) ;
F_17 ( V_14 , V_25 , 0x041f1F1F ) ;
F_17 ( V_14 , V_26 , 0x000004C4 ) ;
} else {
F_17 ( V_14 , V_22 , 0x001f1f00 ) ;
F_17 ( V_14 , V_23 , 0x00080802 ) ;
F_17 ( V_14 , V_24 , 0x1C091C09 ) ;
F_17 ( V_14 , V_25 , 0x031A1F1F ) ;
F_17 ( V_14 , V_26 , 0x000003C2 ) ;
}
if ( F_18 ( V_14 , V_27 , & V_15 ) < 0 ) {
F_19 ( V_28 L_13 ) ;
goto V_29;
}
F_20 ( 100 ) ;
F_2 ( 92 , 0 ) ;
if ( F_21 ( V_15 , V_30 ) < 0 )
F_22 ( V_14 ) ;
V_29:
F_15 ( V_19 ) ;
F_16 ( V_19 ) ;
}
static void T_1 F_23 ( void )
{
unsigned long V_31 ;
if ( F_18 ( V_32 , V_33 , & V_31 ) < 0 ) {
F_19 ( L_14 ) ;
return;
}
V_34 . V_35 = V_31 ;
V_34 . V_36 = V_31 + V_33 - 1 ;
}
static void T_1 F_24 ( void )
{
F_25 ( V_37 , V_38 ) ;
F_1 () ;
V_39 [ 0 ] . V_40 = F_26 ( 125 ) ;
F_27 ( 1 , V_39 ,
F_28 ( V_39 ) ) ;
F_29 ( V_41 , F_28 ( V_41 ) ) ;
F_30 ( & V_42 ) ;
F_31 () ;
F_32 ( NULL , NULL ) ;
F_23 () ;
F_33 ( & V_43 ) ;
}
