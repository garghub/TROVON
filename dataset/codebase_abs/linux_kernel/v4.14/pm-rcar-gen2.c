static inline T_1 F_1 ( T_2 V_1 )
{
return ( V_1 >> 8 ) & 0xfffffc00 ;
}
static void T_3 F_2 ( T_1 V_2 )
{
F_3 ( 0xe6180000 , V_2 ) ;
}
static inline void F_2 ( T_1 V_2 ) {}
void T_3 F_4 ( void )
{
void T_4 * V_3 ;
T_1 V_4 ;
static int V_5 ;
struct V_6 * V_7 , * V_8 ;
bool V_9 = false ;
bool V_10 = false ;
struct V_11 V_12 ;
T_1 V_2 = 0 ;
int error ;
if ( V_5 ++ )
return;
V_8 = F_5 ( L_1 ) ;
if ( ! V_8 )
return;
F_6 (cpus, np) {
if ( F_7 ( V_7 , L_2 ) )
V_10 = true ;
else if ( F_7 ( V_7 , L_3 ) )
V_9 = true ;
}
if ( F_8 ( L_4 ) )
V_2 = 0x013111ef ;
else if ( F_8 ( L_5 ) )
V_2 = 0x00111003 ;
V_7 = F_9 ( NULL , NULL , L_6 ) ;
if ( ! V_7 ) {
V_12 = (struct V_11 ) F_10 ( V_13 ,
V_14 ) ;
goto V_15;
}
error = F_11 ( V_7 , 0 , & V_12 ) ;
if ( error ) {
F_12 ( L_7 , error ) ;
return;
}
V_15:
if ( V_12 . V_16 & ( 256 * 1024 - 1 ) ||
F_13 ( & V_12 ) < V_14 ) {
F_12 ( L_8 ) ;
return;
}
V_3 = F_14 ( V_12 . V_16 , F_13 ( & V_12 ) ) ;
if ( ! V_3 )
return;
F_15 ( V_3 , V_17 , V_14 ) ;
F_16 ( V_3 ) ;
V_3 = F_17 ( V_18 , 0x63 ) ;
V_4 = F_1 ( V_12 . V_16 ) ;
if ( V_10 ) {
F_18 ( V_4 , V_3 + V_19 ) ;
F_18 ( V_4 | V_20 , V_3 + V_19 ) ;
F_18 ( ( F_19 ( V_3 + V_21 ) &
~ V_22 ) | V_23 ,
V_3 + V_21 ) ;
}
if ( V_9 ) {
F_18 ( V_4 , V_3 + V_24 ) ;
F_18 ( V_4 | V_20 , V_3 + V_24 ) ;
F_18 ( ( F_19 ( V_3 + V_25 ) &
~ V_26 ) | V_27 ,
V_3 + V_25 ) ;
}
F_16 ( V_3 ) ;
F_2 ( V_2 ) ;
F_20 () ;
}
