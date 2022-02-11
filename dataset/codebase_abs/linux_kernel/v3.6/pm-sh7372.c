static int F_1 ( void )
{
F_2 () ;
F_3 ( 0x300fffff , V_1 ) ;
return 0 ;
}
static int F_4 ( void )
{
return - V_2 ;
}
static int F_5 ( void )
{
return V_3 ? 0 : - V_2 ;
}
static void F_6 ( unsigned long V_4 )
{
F_3 ( V_4 , V_5 ) ;
F_3 ( 0 , V_6 ) ;
}
static void F_7 ( int V_7 , unsigned long V_8 )
{
if ( V_7 )
F_3 ( 0 , V_9 ) ;
else
F_3 ( 1 << 28 , V_9 ) ;
F_8 ( V_10 ) ;
F_9 ( V_8 , V_11 ) ;
F_8 ( V_10 ) ;
F_3 ( 0 , V_5 ) ;
}
static int F_10 ( unsigned long * V_12 , unsigned long * V_13 )
{
unsigned long V_14 , V_15 , V_16 , V_17 , V_18 ;
unsigned long V_19 , V_20 ;
V_14 = F_8 ( V_21 ) ;
if ( ( V_14 & 0x00000003 ) != 0x00000003 ) {
F_11 ( L_1 , V_14 ) ;
return 0 ;
}
V_15 = F_8 ( V_22 ) ;
if ( ( V_15 & 0xff079b7f ) != 0xff079b7f ) {
F_11 ( L_2 , V_15 ) ;
return 0 ;
}
V_16 = F_8 ( V_23 ) ;
if ( ( V_16 & 0x000741ff ) != 0x000741ff ) {
F_11 ( L_3 , V_16 ) ;
return 0 ;
}
V_17 = F_8 ( V_24 ) ;
if ( ( V_17 & 0x1a60f010 ) != 0x1a60f010 ) {
F_11 ( L_4 , V_17 ) ;
return 0 ;
}
V_18 = F_8 ( V_25 ) ;
if ( ( V_18 & 0x00008cf0 ) != 0x00008cf0 ) {
F_11 ( L_5 , V_18 ) ;
return 0 ;
}
V_19 = 0 ;
V_20 = 0 ;
if ( ( V_16 & ( 1 << 23 ) ) == 0 )
V_19 |= 1 << 31 ;
if ( ( V_16 & ( 1 << 12 ) ) == 0 )
V_19 |= 1 << 21 ;
if ( ( V_18 & ( 1 << 3 ) ) == 0 )
V_19 |= 1 << 2 ;
if ( ( V_15 & ( 1 << 24 ) ) == 0 )
V_19 |= 1 << 1 ;
if ( ( V_17 & ( 1 << 29 ) ) == 0 )
V_19 |= 1 << 1 ;
if ( ( V_18 & ( 1 << 0 ) ) == 0 )
V_19 |= 1 << 1 ;
if ( ( V_16 & ( 1 << 13 ) ) == 0 )
V_20 |= 1 << 17 ;
* V_12 = V_19 ;
* V_13 = V_20 ;
return 1 ;
}
static void F_12 ( unsigned long V_26 , T_1 * V_27 , T_1 * V_28 )
{
T_1 V_29 , V_30 , V_31 ;
int V_32 ;
V_30 = 0 ;
V_31 = 0 ;
for ( V_32 = 0 ; V_32 <= 7 ; V_32 ++ ) {
V_29 = ( V_26 >> ( ( 7 - V_32 ) * 4 ) ) & 0xf ;
V_30 |= ( V_29 & 0x03 ) << ( V_32 * 2 ) ;
V_31 |= ( V_29 >> 2 ) << ( V_32 * 2 ) ;
}
* V_27 = V_30 ;
* V_28 = V_31 ;
}
static void F_13 ( unsigned long V_19 , unsigned long V_20 )
{
T_1 V_33 , V_34 , V_35 , V_36 ;
unsigned long V_29 ;
V_29 = F_14 ( F_15 ( V_37 ) ) ;
V_29 |= F_14 ( F_15 ( V_38 ) ) << 8 ;
V_19 = ( ~ V_19 & 0xc030000f ) | ( V_29 << 4 ) ;
F_3 ( V_19 , V_39 ) ;
F_12 ( F_8 ( V_40 ) , & V_33 , & V_35 ) ;
F_12 ( F_8 ( V_41 ) , & V_34 , & V_36 ) ;
F_3 ( ( V_34 << 16 ) | V_33 , V_42 ) ;
F_3 ( ( V_36 << 16 ) | V_35 , V_43 ) ;
V_29 = F_14 ( F_15 ( V_44 ) ) ;
V_29 |= F_14 ( F_15 ( V_45 ) ) << 8 ;
V_20 = ( ~ V_20 & 0x00030000 ) | V_29 ;
F_3 ( V_20 , V_46 ) ;
F_12 ( F_8 ( V_47 ) , & V_33 , & V_35 ) ;
F_12 ( F_8 ( V_48 ) , & V_34 , & V_36 ) ;
F_3 ( ( V_34 << 16 ) | V_33 , V_49 ) ;
F_3 ( ( V_36 << 16 ) | V_35 , V_50 ) ;
}
static void F_16 ( int V_7 )
{
F_13 ( 1 << 0 , 0 ) ;
F_6 ( F_17 ( V_51 ) ) ;
F_7 ( V_7 , 1 << 12 ) ;
}
static int F_18 ( unsigned long V_52 )
{
F_19 () ;
return 0 ;
}
static void F_20 ( void )
{
F_6 ( F_17 ( V_51 ) ) ;
F_3 ( 0x10 , V_53 ) ;
F_9 ( 0 , F_18 ) ;
F_3 ( 0 , V_53 ) ;
F_3 ( 0 , V_5 ) ;
}
static void F_21 ( void )
{
F_16 ( 1 ) ;
}
static void F_22 ( void )
{
F_16 ( 0 ) ;
}
static void F_23 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = & V_55 -> V_58 [ V_55 -> V_59 ] ;
snprintf ( V_57 -> V_60 , V_61 , L_6 ) ;
strncpy ( V_57 -> V_62 , L_7 , V_63 ) ;
V_57 -> V_64 = 10 ;
V_57 -> V_65 = 20 + 10 ;
V_57 -> V_66 = V_67 ;
V_68 [ V_55 -> V_59 ] = F_20 ;
V_55 -> V_59 ++ ;
V_57 = & V_55 -> V_58 [ V_55 -> V_59 ] ;
snprintf ( V_57 -> V_60 , V_61 , L_8 ) ;
strncpy ( V_57 -> V_62 , L_9 , V_63 ) ;
V_57 -> V_64 = 20 ;
V_57 -> V_65 = 30 + 20 ;
V_57 -> V_66 = V_67 ;
V_68 [ V_55 -> V_59 ] = F_21 ;
V_55 -> V_59 ++ ;
V_57 = & V_55 -> V_58 [ V_55 -> V_59 ] ;
snprintf ( V_57 -> V_60 , V_61 , L_10 ) ;
strncpy ( V_57 -> V_62 , L_11 , V_63 ) ;
V_57 -> V_64 = 120 ;
V_57 -> V_65 = 30 + 120 ;
V_57 -> V_66 = V_67 ;
V_68 [ V_55 -> V_59 ] = F_22 ;
V_55 -> V_59 ++ ;
}
static void F_24 ( void )
{
V_69 = F_23 ;
}
static void F_24 ( void ) {}
static void F_25 ( int V_7 )
{
F_26 () ;
memcpy ( ( void * ) V_70 , V_51 , 0x100 ) ;
F_6 ( V_70 ) ;
F_7 ( V_7 , 1 << 10 ) ;
F_27 () ;
}
static int F_28 ( T_2 V_71 )
{
unsigned long V_19 , V_20 ;
if ( F_10 ( & V_19 , & V_20 ) ) {
if ( ! V_3 &&
V_72 . V_73 . V_74 == V_75 ) {
F_13 ( V_19 , V_20 ) ;
F_11 ( L_12 ) ;
F_25 ( 0 ) ;
return 0 ;
}
}
F_11 ( L_13 ) ;
F_16 ( 0 ) ;
return 0 ;
}
static int F_29 ( struct V_76 * V_77 ,
unsigned long V_78 , void * V_52 )
{
switch ( V_78 ) {
case V_79 :
F_30 ( & V_80 . V_73 ) ;
break;
case V_81 :
F_31 () ;
break;
}
return V_82 ;
}
static void F_32 ( void )
{
V_83 . V_84 = F_28 ;
F_33 ( F_29 , 0 ) ;
}
static void F_32 ( void ) {}
void T_3 F_34 ( void )
{
F_3 ( 0x0000a500 , V_85 ) ;
F_3 ( 0x0000a501 , V_85 ) ;
F_3 ( 0x00000000 , V_86 ) ;
F_3 ( 0 , V_87 ) ;
F_32 () ;
F_24 () ;
}
