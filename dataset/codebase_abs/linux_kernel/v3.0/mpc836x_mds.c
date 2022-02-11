static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 T_3 * V_3 = NULL ;
if ( V_4 . V_5 )
V_4 . V_5 ( L_1 , 0 ) ;
V_2 = F_2 ( NULL , L_2 ) ;
if ( V_2 ) {
struct V_6 V_7 ;
F_3 ( V_2 , 0 , & V_7 ) ;
V_3 = F_4 ( V_7 . V_8 , V_7 . V_9 - V_7 . V_8 + 1 ) ;
F_5 ( V_2 ) ;
}
#ifdef F_6
F_7 (np, L_3 , L_4 )
F_8 ( V_2 ) ;
#endif
#ifdef F_9
F_10 () ;
if ( ( V_2 = F_2 ( NULL , L_5 ) ) != NULL ) {
F_11 ( V_2 ) ;
F_5 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_6 ) ) != NULL ; )
F_12 ( V_2 ) ;
#ifdef F_13
F_14 ( 1 , 2 , 1 , 0 , 3 , 0 ) ;
F_14 ( 1 , 3 , 1 , 0 , 3 , 0 ) ;
F_14 ( 1 , 8 , 1 , 0 , 1 , 0 ) ;
F_14 ( 1 , 10 , 2 , 0 , 3 , 0 ) ;
F_14 ( 1 , 9 , 2 , 1 , 3 , 0 ) ;
F_14 ( 1 , 11 , 2 , 1 , 3 , 0 ) ;
F_14 ( 2 , 20 , 2 , 0 , 1 , 0 ) ;
#endif
}
if ( ( V_2 = F_15 ( NULL , L_7 , L_8 ) )
!= NULL ) {
T_4 V_10 ;
#define F_16 0x20
F_17 ( & V_3 [ 9 ] , F_16 ) ;
F_18 ( 1000 ) ;
F_19 ( & V_3 [ 9 ] , F_16 ) ;
V_10 = F_20 ( V_11 ) ;
if ( V_10 == 0x80480021 ) {
void T_3 * V_12 ;
V_12 = F_4 ( F_21 () + 0x14a8 , 8 ) ;
F_22 ( V_12 , 0x0c003000 ) ;
F_23 ( V_12 + 4 , 0xff0 , 0xaa0 ) ;
F_24 ( V_12 ) ;
}
F_24 ( V_3 ) ;
F_5 ( V_2 ) ;
}
#endif
}
static int T_1 F_25 ( void )
{
F_26 ( NULL , V_13 , NULL ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
T_2 T_3 * V_14 ;
struct V_1 * V_2 ;
const char * V_15 ;
int V_16 = 0 ;
V_2 = F_15 ( NULL , NULL , L_9 ) ;
if ( ! V_2 )
return - V_17 ;
V_14 = F_28 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_14 )
return - V_18 ;
V_2 = F_15 ( NULL , NULL , L_10 ) ;
if ( ! V_2 ) {
V_16 = - V_17 ;
goto V_19;
}
#define F_29 (0x3 << 6)
#define F_30 (0x0 << 6)
#define F_31 (0x3 << 4)
#define F_32 (0x0 << 4)
F_33 ( & V_14 [ 8 ] , F_29 | F_31 ,
F_30 | F_32 ) ;
#define F_34 0x0f
#define F_35 0x08
#define F_36 0x04
#define F_37 0x02
#define F_38 0x01
F_33 ( & V_14 [ 13 ] , F_34 , F_36 ) ;
V_15 = F_39 ( V_2 , L_11 , NULL ) ;
if ( V_15 && ! strcmp ( V_15 , L_12 ) ) {
F_19 ( & V_14 [ 13 ] , F_38 ) ;
F_40 ( V_20 , 48000000 ) ;
} else {
F_19 ( & V_14 [ 13 ] , F_37 ) ;
F_41 ( L_13 ) ;
}
F_5 ( V_2 ) ;
V_19:
F_24 ( V_14 ) ;
return V_16 ;
}
static void T_1 F_42 ( void )
{
struct V_1 * V_2 ;
V_2 = F_43 ( NULL , L_14 ) ;
if ( ! V_2 )
return;
F_44 ( V_2 , 0 ) ;
F_45 () ;
F_5 ( V_2 ) ;
#ifdef F_9
V_2 = F_15 ( NULL , NULL , L_15 ) ;
if ( ! V_2 ) {
V_2 = F_43 ( NULL , L_16 ) ;
if ( ! V_2 )
return;
}
F_46 ( V_2 , 0 , V_21 , V_22 ) ;
F_5 ( V_2 ) ;
#endif
}
static int T_1 F_47 ( void )
{
unsigned long V_23 = F_48 () ;
return F_49 ( V_23 , L_17 ) ;
}
