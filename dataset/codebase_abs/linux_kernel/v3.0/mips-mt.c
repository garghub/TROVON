static int T_1 F_1 ( char * V_1 )
{
F_2 ( & V_1 , & V_2 ) ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
F_2 ( & V_1 , & V_3 ) ;
return 1 ;
}
void F_4 ( unsigned long V_4 )
{
unsigned long V_5 ;
unsigned long V_6 ;
unsigned long V_7 ;
int V_8 ;
int V_9 ;
int V_10 ;
int V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
#ifdef F_5
void V_14 ( void ) ;
#endif
F_6 ( V_5 ) ;
V_6 = F_7 () ;
F_8 ( L_1 ) ;
F_8 ( L_2 ) ;
F_8 ( L_3 , V_4 ) ;
F_8 ( L_4 , V_6 ) ;
F_8 ( L_5 , ( V_7 = F_9 () ) ) ;
V_8 = ( ( V_7 & V_15 ) >> V_16 ) + 1 ;
V_9 = ( ( V_7 & V_17 ) >> V_18 ) + 1 ;
F_8 ( L_6 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
F_10 ( V_11 ) ;
if ( ( F_11 () & V_19 ) == V_10 ) {
F_8 ( L_7 , V_10 ) ;
F_8 ( L_8 ,
F_12 () ) ;
F_8 ( L_9 ,
F_13 () ) ;
F_8 ( L_10 ,
V_10 , F_14 () ) ;
F_8 ( L_11 ,
V_10 , F_15 () ,
( void * ) F_15 () ) ;
F_8 ( L_12 ,
V_10 , F_16 () ) ;
F_8 ( L_13 ,
V_10 , F_17 () ) ;
break;
}
}
}
F_8 ( L_14 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
F_10 ( V_11 ) ;
if ( F_11 () == F_18 () ) {
V_12 = 0 ;
V_13 = V_5 ;
F_8 ( L_15 , V_11 ) ;
} else {
V_12 = F_19 () ;
F_20 ( 1 ) ;
V_13 = F_21 () ;
F_8 ( L_16 , V_11 ) ;
}
F_8 ( L_17 , V_13 ) ;
F_8 ( L_18 , F_11 () ) ;
F_8 ( L_19 ,
F_22 () , ( void * ) F_22 () ) ;
F_8 ( L_20 , V_12 ) ;
F_8 ( L_21 , F_23 () ) ;
if ( ! V_12 )
F_20 ( 0 ) ;
}
#ifdef F_5
V_14 () ;
#endif
F_8 ( L_22 ) ;
F_24 ( V_6 ) ;
F_25 ( V_5 ) ;
}
static int T_1 F_26 ( char * V_20 )
{
V_21 = 1 ;
return 1 ;
}
static int T_1 F_27 ( char * V_1 )
{
F_2 ( & V_1 , & V_22 ) ;
return 1 ;
}
static int T_1 F_28 ( char * V_1 )
{
F_2 ( & V_1 , & V_23 ) ;
return 1 ;
}
static int T_1 F_29 ( char * V_1 )
{
F_2 ( & V_1 , & V_24 ) ;
V_25 = 1 ;
return 1 ;
}
static int T_1 F_30 ( char * V_20 )
{
V_26 = 1 ;
return 1 ;
}
static int T_1 F_31 ( char * V_20 )
{
V_27 = 1 ;
return 1 ;
}
static int T_1 F_32 ( char * V_20 )
{
F_2 ( & V_20 , & V_28 ) ;
return 1 ;
}
static int T_1 F_33 ( char * V_20 )
{
F_2 ( & V_20 , & V_29 ) ;
return 1 ;
}
static int T_1 F_34 ( char * V_1 )
{
F_2 ( & V_1 , & V_30 ) ;
return 1 ;
}
void F_35 ( void )
{
unsigned int V_31 = F_36 () ;
unsigned int V_32 = V_31 ;
if ( V_21 ) {
F_8 ( L_23 ) ;
}
if ( V_22 >= 0 ) {
F_8 ( L_24 ,
V_22 ) ;
if ( V_22 )
V_32 |= ( 1 << 2 ) ;
else
V_32 &= ~ ( 1 << 2 ) ;
}
if ( V_23 >= 0 ) {
F_8 ( L_25 , V_23 ) ;
if ( V_23 )
V_32 |= ( 1 << 5 ) ;
else
V_32 &= ~ ( 1 << 5 ) ;
}
if ( V_25 ) {
F_8 ( L_26 , V_24 ) ;
V_32 = V_24 ;
}
if ( V_31 != V_32 ) {
T_2 V_33 ( L_27 ) ;
F_37 ( V_32 ) ;
F_38 () ;
F_8 ( L_28 , F_36 () ) ;
}
if ( V_26 )
F_8 ( L_29 ) ;
if ( V_27 )
F_8 ( L_30 ) ;
if ( V_28 != 1 )
F_8 ( L_31 , V_28 ) ;
if ( V_29 != 1 )
F_8 ( L_32 , V_29 ) ;
if ( V_30 != 0 ) {
unsigned long V_34 ;
unsigned long V_35 ;
V_34 = F_39 () ;
F_40 ( V_34 | ( 0x1 << 26 ) ) ;
F_38 () ;
#define F_41 (0x80000000)
#define F_42 (0x80000008)
F_43 ( V_36 , F_42 ) ;
F_38 () ;
V_35 = F_44 () ;
V_35 &= 0xfffe0000 ;
V_35 |= 0x00000c00 ;
F_45 ( V_35 ) ;
F_38 () ;
F_43 ( V_37 , F_42 ) ;
F_45 ( ( V_30 & 0xfffffc00 ) | 0x1 ) ;
F_38 () ;
F_43 ( V_37 , F_41 ) ;
F_40 ( V_34 ) ;
F_38 () ;
F_8 ( L_33 ,
( ( V_35 & 0x7fe00000 ) >> 20 ) , V_30 ) ;
}
}
void F_46 ( void )
{
#ifdef F_5
void V_38 ( void ) ;
V_38 () ;
#endif
}
void F_47 ( void )
{
#ifdef F_5
void V_39 ( void ) ;
V_39 () ;
#endif
}
static int T_1 F_48 ( void )
{
struct V_40 * V_41 ;
V_41 = F_49 ( V_42 , L_34 ) ;
if ( F_50 ( V_41 ) )
return F_51 ( V_41 ) ;
V_43 = V_41 ;
return 0 ;
}
