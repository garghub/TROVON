static void T_1 F_1 ( void )
{
unsigned long V_1 ;
if ( F_2 ( V_2 , V_3 , & V_1 ) < 0 ) {
F_3 ( V_4 L_1 ) ;
return;
}
V_5 [ 0 ] . V_6 = V_1 ;
V_5 [ 0 ] . V_7 = V_1 + V_3 - 1 ;
}
static inline void T_1 F_4 ( void )
{
unsigned long V_1 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
int V_11 ;
int V_12 ;
V_10 = F_5 ( NULL , L_2 ) ;
if ( F_6 ( V_10 ) ) {
F_7 ( 1 ) ;
return;
}
F_8 ( V_10 ) ;
V_8 = F_9 ( V_10 ) ;
V_11 = V_13 ;
F_10 ( V_11 , V_14 , 0x00011200 ) ;
if ( V_8 >= 160000000 ) {
F_10 ( V_11 , V_15 , 0x001f1f01 ) ;
F_10 ( V_11 , V_16 , 0x00080803 ) ;
F_10 ( V_11 , V_17 , 0x1c0b1c0a ) ;
F_10 ( V_11 , V_18 , 0x041f1F1F ) ;
F_10 ( V_11 , V_19 , 0x000004C4 ) ;
} else if ( V_8 >= 130000000 ) {
F_10 ( V_11 , V_15 , 0x001f1f00 ) ;
F_10 ( V_11 , V_16 , 0x00080802 ) ;
F_10 ( V_11 , V_17 , 0x1C091C09 ) ;
F_10 ( V_11 , V_18 , 0x041f1F1F ) ;
F_10 ( V_11 , V_19 , 0x000004C4 ) ;
} else {
F_10 ( V_11 , V_15 , 0x001f1f00 ) ;
F_10 ( V_11 , V_16 , 0x00080802 ) ;
F_10 ( V_11 , V_17 , 0x1C091C09 ) ;
F_10 ( V_11 , V_18 , 0x031A1F1F ) ;
F_10 ( V_11 , V_19 , 0x000003C2 ) ;
}
if ( F_2 ( V_13 , V_20 , & V_1 ) < 0 ) {
F_3 ( V_4 L_3 ) ;
goto V_21;
}
V_22 [ 0 ] . V_6 = V_1 + 0x300 ;
V_22 [ 0 ] . V_7 = V_1 + 0x30f ;
F_11 ( 100 ) ;
F_12 ( V_23 , 0 ) ;
V_12 = F_13 ( V_23 , V_24 , L_4 ) ;
if ( V_12 ) {
F_3 ( V_4 L_5 ,
V_23 ) ;
F_14 ( V_13 ) ;
}
V_21:
F_15 ( V_10 ) ;
F_16 ( V_10 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( L_6 , 0 ) ;
F_18 ( L_7 , 0 ) ;
F_18 ( L_8 , 0 ) ;
F_19 ( V_25 , F_20 ( V_25 ) ) ;
}
static void T_1 F_21 ( void )
{
T_2 V_26 ;
F_22 ( V_27 , V_28 ) ;
F_4 () ;
F_17 () ;
F_1 () ;
F_18 ( L_9 , V_29 | V_30 ) ;
F_18 ( L_10 , V_29 | V_30 ) ;
V_26 = F_23 ( V_31 ) ;
V_26 |= ( 1 << 24 ) ;
F_24 ( V_26 , V_31 ) ;
V_22 [ 1 ] . V_6 = F_25 ( V_23 ) ;
V_22 [ 1 ] . V_7 = F_25 ( V_23 ) ;
F_26 ( V_32 , F_20 ( V_32 ) ) ;
F_27 () ;
F_28 ( NULL , NULL ) ;
F_29 ( & V_33 ) ;
}
