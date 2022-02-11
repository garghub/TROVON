static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 ,
V_4 , NULL ) ;
if ( V_2 ) {
F_3 ( L_1 , F_4 ( V_2 ) ) ;
V_5 = 0 ;
if ( V_2 -> V_6 [ 0 ] . V_7 & V_8 ) {
V_5 = V_2 -> V_6 [ 0 ] . V_9 ;
F_5 ( L_2 , & V_5 ) ;
}
if ( V_5 == 0 ) {
F_3 ( L_3 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
} else {
F_3 ( L_4 ) ;
return NULL ;
}
return V_2 ;
}
static int F_7 ( void * V_10 , struct V_11 * V_12 )
{
unsigned char V_13 ;
int V_14 ;
V_14 = F_8 () ;
V_13 = ( V_14 >> 8 ) & 0xFF ;
if ( V_14 & 0xFF ) {
F_9 ( V_15 . V_16 , L_5 , V_13 ) ;
F_10 ( V_12 , & V_13 ) ;
return 0 ;
}
return - V_17 ;
}
static int F_11 ( void * V_10 )
{
F_9 ( V_15 . V_16 , L_6 ) ;
return 0 ;
}
static void F_12 ( void * V_10 )
{
F_9 ( V_15 . V_16 , L_7 ) ;
}
int F_13 ( void )
{
struct V_1 * V_18 ;
int V_19 ;
V_18 = F_1 () ;
if ( V_18 == NULL )
return - V_20 ;
V_19 = F_14 ( V_18 ) ;
if ( V_19 )
goto V_21;
if ( ! F_15 () ) {
V_19 = - V_20 ;
goto V_22;
}
strcpy ( V_15 . V_23 , L_8 ) ;
V_15 . V_24 = - 1 ;
V_15 . V_25 = 8 ;
V_15 . V_26 = 10 ;
V_15 . V_10 = NULL ;
V_15 . V_27 = F_7 ;
V_15 . V_28 = F_11 ;
V_15 . V_29 = F_12 ;
V_15 . V_16 = & V_18 -> V_16 ;
V_15 . V_30 = V_31 ;
V_32 = F_16 ( & V_15 ) ;
if ( V_32 < 0 ) {
F_3 ( L_9 ) ;
V_19 = V_32 ;
goto V_33;
}
F_9 ( V_15 . V_16 , L_10 ,
V_32 ) ;
return 0 ;
V_33:
F_17 ( V_34 ) ;
V_22:
F_18 ( V_18 ) ;
V_21:
F_6 ( V_18 ) ;
return V_19 ;
}
void F_19 ( void )
{
struct V_1 * V_18 = F_20 ( V_15 . V_16 ) ;
F_21 ( V_32 ) ;
F_17 ( V_34 ) ;
F_18 ( V_18 ) ;
F_6 ( V_18 ) ;
}
static int F_15 ( void )
{
V_34 = F_22 ( V_5 + V_35 , 0x400 ) ;
if ( ! V_34 ) {
F_5 ( L_11 ) ;
return 0 ;
}
return 1 ;
}
static void F_23 ( int V_36 )
{
F_24 ( V_37 * V_36 ) ;
}
static int F_8 ( void )
{
unsigned char V_38 , V_39 ;
F_25 () ;
F_26 ( 0xAA ) ;
F_26 ( 0x01 ) ;
F_25 () ;
F_26 ( 0xAB ) ;
V_39 = F_27 () ;
V_38 = F_27 () ;
F_28 () ;
return ( V_38 << 8 ) | V_39 ;
}
static void F_25 ( void )
{
F_29 ( 3 ) ;
F_23 ( 4 ) ;
F_29 ( 1 ) ;
F_23 ( 7 ) ;
F_29 ( 0 ) ;
F_23 ( 2 ) ;
}
static void F_28 ( void )
{
unsigned char V_40 ;
V_40 = F_30 () & 0xFD ;
F_29 ( V_40 ) ;
F_23 ( 1 ) ;
V_40 |= 1 ;
F_29 ( V_40 ) ;
F_23 ( 2 ) ;
V_40 |= 2 ;
F_29 ( V_40 ) ;
V_40 = 3 ;
F_29 ( V_40 ) ;
F_23 ( 2 ) ;
}
static void F_26 ( unsigned char V_41 )
{
int V_42 ;
unsigned char V_43 ;
V_43 = F_30 () ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( V_41 & 0x80 )
V_43 |= 0x02 ;
else
V_43 &= 0xFD ;
F_29 ( V_43 ) ;
F_23 ( 1 ) ;
V_43 |= 1 ;
F_29 ( V_43 ) ;
F_23 ( 1 ) ;
V_43 &= 0xFE ;
F_29 ( V_43 ) ;
F_23 ( 1 ) ;
V_41 <<= 1 ;
}
F_23 ( 2 ) ;
V_43 |= 2 ;
F_29 ( V_43 ) ;
V_43 |= 1 ;
F_29 ( V_43 ) ;
F_23 ( 1 ) ;
F_30 () ;
V_43 &= 0xFE ;
F_29 ( V_43 ) ;
F_23 ( 3 ) ;
}
static unsigned char F_27 ( void )
{
int V_42 ;
int V_44 ;
unsigned char V_45 , V_46 ;
V_46 = F_30 () | 2 ;
F_29 ( V_46 ) ;
V_44 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_46 &= 0xFE ;
F_29 ( V_46 ) ;
F_23 ( 2 ) ;
V_46 |= 1 ;
F_29 ( V_46 ) ;
F_23 ( 1 ) ;
V_45 = F_30 () ;
if ( V_45 & 2 )
V_44 |= 1 ;
V_44 <<= 1 ;
}
V_46 = 0 ;
if ( V_45 == 0 )
V_46 |= 2 ;
F_29 ( V_46 ) ;
F_23 ( 2 ) ;
V_46 |= 1 ;
F_29 ( V_46 ) ;
F_23 ( 3 ) ;
V_46 &= 0xFE ;
F_29 ( V_46 ) ;
F_23 ( 2 ) ;
V_44 >>= 1 ;
V_44 &= 0xFF ;
return V_44 ;
}
static void F_29 ( unsigned char V_47 )
{
int V_48 ;
V_48 = F_31 ( 0x34 ) ;
if ( V_47 & 2 ) {
V_48 &= 0xFFFFFFDF ;
V_48 |= 1 ;
} else {
V_48 &= 0xFFFFFFFE ;
V_48 |= 0x20 ;
}
V_48 |= 0x10 ;
F_32 ( 0x34 , V_48 ) ;
V_48 = F_31 ( 0x31 ) ;
if ( V_47 & 1 )
V_48 |= 0x1000000 ;
else
V_48 &= 0xFEFFFFFF ;
V_48 |= 0x8000000 ;
F_32 ( 0x31 , V_48 ) ;
}
static unsigned char F_30 ( void )
{
unsigned char V_40 ;
int V_48 ;
V_48 = F_31 ( 0x34 ) ;
V_48 |= 0x10 ;
V_48 &= 0xFFFFFFDF ;
F_32 ( 0x34 , V_48 ) ;
V_48 = F_31 ( 0x34 ) ;
V_40 = 0 ;
if ( V_48 & 8 )
V_40 |= 2 ;
else
V_40 &= 0xFD ;
V_48 = F_31 ( 0x31 ) ;
if ( V_48 & 0x1000000 )
V_40 |= 1 ;
else
V_40 &= 0xFE ;
return V_40 ;
}
static unsigned int F_31 ( unsigned char V_49 )
{
unsigned char T_1 * V_50 ;
V_50 = V_34 + ( ( V_49 & 0xFF ) << 2 ) ;
return F_33 ( V_50 ) ;
}
static void F_32 ( unsigned char V_49 , unsigned int V_48 )
{
unsigned char T_1 * V_50 ;
V_50 = V_34 + ( ( V_49 & 0xFF ) << 2 ) ;
F_34 ( V_48 , V_50 ) ;
}
