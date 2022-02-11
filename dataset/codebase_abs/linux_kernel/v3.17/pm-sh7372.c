static int F_1 ( void )
{
F_2 () ;
F_3 ( 0x300fffff , V_1 ) ;
return 0 ;
}
static int F_4 ( void )
{
V_2 = true ;
return - V_3 ;
}
static void F_5 ( void )
{
V_2 = false ;
}
static int F_6 ( void )
{
return V_4 ? 0 : - V_3 ;
}
void T_1 F_7 ( void )
{
F_8 ( V_5 , F_9 ( V_5 ) ) ;
F_10 ( L_1 , L_2 ) ;
F_10 ( L_3 , L_1 ) ;
F_10 ( L_4 , L_5 ) ;
F_10 ( L_4 , L_6 ) ;
}
static void F_11 ( unsigned long V_6 )
{
F_3 ( V_6 , V_7 ) ;
F_3 ( 0 , V_8 ) ;
}
static void F_12 ( int V_9 , unsigned long V_10 )
{
if ( V_9 )
F_3 ( 0 , V_11 ) ;
else
F_3 ( 1 << 28 , V_11 ) ;
F_13 ( V_12 ) ;
F_14 ( V_10 , V_13 ) ;
F_13 ( V_12 ) ;
F_3 ( 0 , V_7 ) ;
}
static int F_15 ( unsigned long * V_14 , unsigned long * V_15 )
{
unsigned long V_16 , V_17 , V_18 , V_19 , V_20 ;
unsigned long V_21 , V_22 ;
V_16 = F_13 ( V_23 ) ;
if ( ( V_16 & 0x00000003 ) != 0x00000003 ) {
F_16 ( L_7 , V_16 ) ;
return 0 ;
}
V_17 = F_13 ( V_24 ) ;
if ( ( V_17 & 0xff079b7f ) != 0xff079b7f ) {
F_16 ( L_8 , V_17 ) ;
return 0 ;
}
V_18 = F_13 ( V_25 ) ;
if ( ( V_18 & 0x000741ff ) != 0x000741ff ) {
F_16 ( L_9 , V_18 ) ;
return 0 ;
}
V_19 = F_13 ( V_26 ) ;
if ( ( V_19 & 0x1a60f010 ) != 0x1a60f010 ) {
F_16 ( L_10 , V_19 ) ;
return 0 ;
}
V_20 = F_13 ( V_27 ) ;
if ( ( V_20 & 0x00008cf0 ) != 0x00008cf0 ) {
F_16 ( L_11 , V_20 ) ;
return 0 ;
}
V_21 = 0 ;
V_22 = 0 ;
if ( ( V_18 & ( 1 << 23 ) ) == 0 )
V_21 |= 1 << 31 ;
if ( ( V_18 & ( 1 << 12 ) ) == 0 )
V_21 |= 1 << 21 ;
if ( ( V_20 & ( 1 << 3 ) ) == 0 )
V_21 |= 1 << 2 ;
if ( ( V_17 & ( 1 << 24 ) ) == 0 )
V_21 |= 1 << 1 ;
if ( ( V_19 & ( 1 << 29 ) ) == 0 )
V_21 |= 1 << 1 ;
if ( ( V_20 & ( 1 << 0 ) ) == 0 )
V_21 |= 1 << 1 ;
if ( ( V_18 & ( 1 << 13 ) ) == 0 )
V_22 |= 1 << 17 ;
* V_14 = V_21 ;
* V_15 = V_22 ;
return 1 ;
}
static void F_17 ( unsigned long V_28 , T_2 * V_29 , T_2 * V_30 )
{
T_2 V_31 , V_32 , V_33 ;
int V_34 ;
V_32 = 0 ;
V_33 = 0 ;
for ( V_34 = 0 ; V_34 <= 7 ; V_34 ++ ) {
V_31 = ( V_28 >> ( ( 7 - V_34 ) * 4 ) ) & 0xf ;
V_32 |= ( V_31 & 0x03 ) << ( V_34 * 2 ) ;
V_33 |= ( V_31 >> 2 ) << ( V_34 * 2 ) ;
}
* V_29 = V_32 ;
* V_30 = V_33 ;
}
static void F_18 ( unsigned long V_21 , unsigned long V_22 )
{
T_2 V_35 , V_36 , V_37 , V_38 ;
unsigned long V_31 ;
V_31 = F_19 ( F_20 ( V_39 ) ) ;
V_31 |= F_19 ( F_20 ( V_40 ) ) << 8 ;
V_21 = ( ~ V_21 & 0xc030000f ) | ( V_31 << 4 ) ;
F_3 ( V_21 , V_41 ) ;
F_17 ( F_13 ( V_42 ) , & V_35 , & V_37 ) ;
F_17 ( F_13 ( V_43 ) , & V_36 , & V_38 ) ;
F_3 ( ( V_36 << 16 ) | V_35 , V_44 ) ;
F_3 ( ( V_38 << 16 ) | V_37 , V_45 ) ;
V_31 = F_19 ( F_20 ( V_46 ) ) ;
V_31 |= F_19 ( F_20 ( V_47 ) ) << 8 ;
V_22 = ( ~ V_22 & 0x00030000 ) | V_31 ;
F_3 ( V_22 , V_48 ) ;
F_17 ( F_13 ( V_49 ) , & V_35 , & V_37 ) ;
F_17 ( F_13 ( V_50 ) , & V_36 , & V_38 ) ;
F_3 ( ( V_36 << 16 ) | V_35 , V_51 ) ;
F_3 ( ( V_38 << 16 ) | V_37 , V_52 ) ;
}
static void F_21 ( int V_9 )
{
F_18 ( 1 << 0 , 0 ) ;
F_11 ( F_22 ( V_53 ) ) ;
F_12 ( V_9 , 1 << 12 ) ;
}
static void F_23 ( int V_9 )
{
F_24 () ;
F_11 ( V_54 ) ;
F_12 ( V_9 , 1 << 10 ) ;
F_25 () ;
}
static void F_26 ( void )
{
V_55 = F_27 ( V_56 ) ;
memcpy ( ( void * ) V_54 , V_53 , 0x100 ) ;
}
static inline void F_26 ( void ) {}
static int F_28 ( unsigned long V_57 )
{
F_29 () ;
return 0 ;
}
static int F_30 ( struct V_58 * V_59 ,
struct V_60 * V_61 , int V_62 )
{
F_11 ( F_22 ( V_53 ) ) ;
F_3 ( 0x10 , V_63 ) ;
F_14 ( 0 , F_28 ) ;
F_3 ( 0 , V_63 ) ;
F_3 ( 0 , V_7 ) ;
return 1 ;
}
static int F_31 ( struct V_58 * V_59 ,
struct V_60 * V_61 , int V_62 )
{
F_21 ( 1 ) ;
return 2 ;
}
static int F_32 ( struct V_58 * V_59 ,
struct V_60 * V_61 , int V_62 )
{
F_21 ( 0 ) ;
return 3 ;
}
static int F_33 ( struct V_58 * V_59 ,
struct V_60 * V_61 , int V_62 )
{
unsigned long V_21 , V_22 ;
if ( ! F_15 ( & V_21 , & V_22 ) )
return F_32 ( V_59 , V_61 , V_62 ) ;
F_18 ( V_21 , V_22 ) ;
F_23 ( 0 ) ;
return 4 ;
}
static void T_1 F_34 ( void )
{
F_35 ( & V_64 ) ;
}
static void T_1 F_34 ( void ) {}
static int F_36 ( T_3 V_65 )
{
unsigned long V_21 , V_22 ;
if ( F_15 ( & V_21 , & V_22 ) && V_2 ) {
F_18 ( V_21 , V_22 ) ;
F_16 ( L_12 ) ;
F_23 ( 0 ) ;
return 0 ;
}
F_16 ( L_13 ) ;
F_21 ( 0 ) ;
return 0 ;
}
static int F_37 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_57 )
{
switch ( V_68 ) {
case V_69 :
F_38 ( L_3 ) ;
break;
case V_70 :
F_39 () ;
break;
}
return V_71 ;
}
static void F_40 ( void )
{
V_72 . V_73 = F_36 ;
F_41 ( F_37 , 0 ) ;
}
static void F_40 ( void ) {}
void T_1 F_42 ( void )
{
F_3 ( 0x0000a500 , V_74 ) ;
F_3 ( 0x0000a501 , V_74 ) ;
F_3 ( 0x00000000 , V_75 ) ;
F_3 ( 0 , V_76 ) ;
F_26 () ;
F_40 () ;
F_34 () ;
}
void T_1 F_43 ( void )
{
F_44 () ;
F_45 ( L_4 , 4 ) ;
}
