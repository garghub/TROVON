static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << V_4 -> V_6 ;
if ( V_4 -> V_7 )
V_4 -> V_7 () ;
if ( V_4 -> V_8 )
return 0 ;
if ( F_3 ( V_9 ) & V_5 ) {
unsigned int V_10 ;
F_4 ( V_5 , V_11 ) ;
for ( V_10 = V_12 ; V_10 ; V_10 -- ) {
if ( ! ( F_3 ( V_11 ) & V_5 ) )
break;
F_5 () ;
}
}
if ( ! V_4 -> V_13 )
F_6 ( L_1 ,
V_5 , F_3 ( V_9 ) ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 , bool V_14 )
{
unsigned int V_5 = 1 << V_4 -> V_6 ;
unsigned int V_10 ;
int V_15 = 0 ;
if ( V_4 -> V_8 )
goto V_16;
if ( F_3 ( V_9 ) & V_5 )
goto V_16;
F_4 ( V_5 , V_17 ) ;
for ( V_10 = 2 * V_12 ; V_10 ; V_10 -- ) {
if ( ! ( F_3 ( V_17 ) & V_5 ) )
break;
if ( V_10 > V_12 )
F_8 ( V_18 ) ;
else
F_5 () ;
}
if ( ! V_10 )
V_15 = - V_19 ;
if ( ! V_4 -> V_13 )
F_6 ( L_2 ,
V_5 , F_3 ( V_9 ) ) ;
V_16:
if ( V_15 == 0 && V_4 -> V_20 && V_14 )
V_4 -> V_20 () ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) , true ) ;
}
static void F_10 ( void )
{
F_11 () ;
F_4 ( 0x300fffff , V_21 ) ;
}
static bool F_12 ( struct V_22 * V_23 )
{
return true ;
}
static bool F_13 ( struct V_24 * V_25 )
{
return false ;
}
void F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_15 ( V_2 , V_4 -> V_26 , false ) ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = true ;
V_2 -> V_32 = F_12 ;
V_2 -> V_33 = F_1 ;
V_2 -> V_34 = F_9 ;
F_7 ( V_4 , false ) ;
}
void F_16 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_22 * V_23 = & V_36 -> V_23 ;
F_17 ( & V_4 -> V_2 , V_23 ) ;
if ( F_18 ( V_23 ) )
F_19 ( V_23 , NULL ) ;
}
void F_20 ( struct V_3 * V_4 ,
struct V_3 * V_37 )
{
F_21 ( & V_4 -> V_2 , & V_37 -> V_2 ) ;
}
static void F_22 ( void )
{
V_38 . V_8 = ! V_39 ;
}
static inline void F_22 ( void ) {}
static int F_23 ( unsigned long V_40 )
{
F_24 () ;
return 0 ;
}
static void F_25 ( void )
{
F_4 ( F_26 ( V_41 ) , V_42 ) ;
F_4 ( 0 , V_43 ) ;
F_4 ( 0x10 , V_44 ) ;
F_27 ( 0 , F_23 ) ;
F_4 ( 0 , V_44 ) ;
F_4 ( 0 , V_42 ) ;
}
static void F_28 ( int V_45 )
{
F_4 ( F_26 ( V_41 ) , V_42 ) ;
F_4 ( 0 , V_43 ) ;
if ( V_45 )
F_4 ( 0 , V_46 ) ;
else
F_4 ( 1 << 28 , V_46 ) ;
F_4 ( 0 , V_47 ) ;
F_3 ( V_48 ) ;
F_27 ( 0 , V_49 ) ;
F_3 ( V_48 ) ;
F_4 ( 0 , V_42 ) ;
}
static int F_29 ( unsigned long * V_50 , unsigned long * V_51 )
{
unsigned long V_52 , V_53 , V_54 , V_55 , V_56 ;
unsigned long V_57 , V_58 ;
V_52 = F_3 ( V_59 ) ;
if ( ( V_52 & 0x00000003 ) != 0x00000003 ) {
F_6 ( L_3 , V_52 ) ;
return 0 ;
}
V_53 = F_3 ( V_60 ) ;
if ( ( V_53 & 0xff079b7f ) != 0xff079b7f ) {
F_6 ( L_4 , V_53 ) ;
return 0 ;
}
V_54 = F_3 ( V_61 ) ;
if ( ( V_54 & 0x000741ff ) != 0x000741ff ) {
F_6 ( L_5 , V_54 ) ;
return 0 ;
}
V_55 = F_3 ( V_62 ) ;
if ( ( V_55 & 0x1a60f010 ) != 0x1a60f010 ) {
F_6 ( L_6 , V_55 ) ;
return 0 ;
}
V_56 = F_3 ( V_63 ) ;
if ( ( V_56 & 0x00008cf0 ) != 0x00008cf0 ) {
F_6 ( L_7 , V_56 ) ;
return 0 ;
}
V_57 = 0 ;
V_58 = 0 ;
if ( ( V_54 & ( 1 << 23 ) ) == 0 )
V_57 |= 1 << 31 ;
if ( ( V_54 & ( 1 << 12 ) ) == 0 )
V_57 |= 1 << 21 ;
if ( ( V_56 & ( 1 << 3 ) ) == 0 )
V_57 |= 1 << 2 ;
if ( ( V_53 & ( 1 << 24 ) ) == 0 )
V_57 |= 1 << 1 ;
if ( ( V_55 & ( 1 << 29 ) ) == 0 )
V_57 |= 1 << 1 ;
if ( ( V_56 & ( 1 << 0 ) ) == 0 )
V_57 |= 1 << 1 ;
if ( ( V_54 & ( 1 << 13 ) ) == 0 )
V_58 |= 1 << 17 ;
* V_50 = V_57 ;
* V_51 = V_58 ;
return 1 ;
}
static void F_30 ( unsigned long V_64 , T_1 * V_65 , T_1 * V_66 )
{
T_1 V_67 , V_68 , V_69 ;
int V_70 ;
V_68 = 0 ;
V_69 = 0 ;
for ( V_70 = 0 ; V_70 <= 7 ; V_70 ++ ) {
V_67 = ( V_64 >> ( ( 7 - V_70 ) * 4 ) ) & 0xf ;
V_68 |= ( V_67 & 0x03 ) << ( V_70 * 2 ) ;
V_69 |= ( V_67 >> 2 ) << ( V_70 * 2 ) ;
}
* V_65 = V_68 ;
* V_66 = V_69 ;
}
static void F_31 ( unsigned long V_57 , unsigned long V_58 )
{
T_1 V_71 , V_72 , V_73 , V_74 ;
unsigned long V_67 ;
V_67 = F_32 ( F_33 ( V_75 ) ) ;
V_67 |= F_32 ( F_33 ( V_76 ) ) << 8 ;
V_57 = ( ~ V_57 & 0xc030000f ) | ( V_67 << 4 ) ;
F_4 ( V_57 , V_77 ) ;
F_30 ( F_3 ( V_78 ) , & V_71 , & V_73 ) ;
F_30 ( F_3 ( V_79 ) , & V_72 , & V_74 ) ;
F_4 ( ( V_72 << 16 ) | V_71 , V_80 ) ;
F_4 ( ( V_74 << 16 ) | V_73 , V_81 ) ;
V_67 = F_32 ( F_33 ( V_82 ) ) ;
V_67 |= F_32 ( F_33 ( V_83 ) ) << 8 ;
V_58 = ( ~ V_58 & 0x00030000 ) | V_67 ;
F_4 ( V_58 , V_84 ) ;
F_30 ( F_3 ( V_85 ) , & V_71 , & V_73 ) ;
F_30 ( F_3 ( V_86 ) , & V_72 , & V_74 ) ;
F_4 ( ( V_72 << 16 ) | V_71 , V_87 ) ;
F_4 ( ( V_74 << 16 ) | V_73 , V_88 ) ;
}
static void F_34 ( struct V_89 * V_90 )
{
struct V_91 * V_92 = & V_90 -> V_93 [ V_90 -> V_94 ] ;
snprintf ( V_92 -> V_95 , V_96 , L_8 ) ;
strncpy ( V_92 -> V_97 , L_9 , V_98 ) ;
V_92 -> V_99 = 10 ;
V_92 -> V_100 = 20 + 10 ;
V_92 -> V_101 = V_102 ;
V_103 [ V_90 -> V_94 ] = F_25 ;
V_90 -> V_94 ++ ;
}
static void F_35 ( void )
{
V_104 = F_34 ;
}
static void F_35 ( void ) {}
static int F_36 ( T_2 V_105 )
{
unsigned long V_57 , V_58 ;
if ( F_29 ( & V_57 , & V_58 ) ) {
F_31 ( V_57 , V_58 ) ;
F_6 ( L_10 ) ;
F_28 ( 0 ) ;
} else {
F_6 ( L_11 ) ;
F_25 () ;
}
return 0 ;
}
static void F_37 ( void )
{
V_106 . V_107 = F_36 ;
}
static void F_37 ( void ) {}
void T_3 F_38 ( void )
{
F_4 ( 0x0000a500 , V_108 ) ;
F_4 ( 0x0000a501 , V_108 ) ;
F_4 ( 0x00000000 , V_109 ) ;
F_4 ( 0 , V_47 ) ;
F_22 () ;
F_37 () ;
F_35 () ;
}
