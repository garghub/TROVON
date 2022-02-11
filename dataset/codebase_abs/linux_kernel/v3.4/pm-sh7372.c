static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << V_4 -> V_6 ;
if ( V_4 -> V_7 ) {
int V_8 = V_4 -> V_7 () ;
if ( V_8 )
return V_8 ;
}
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
V_2 -> V_14 , V_5 , F_3 ( V_9 ) ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 , bool V_15 )
{
unsigned int V_5 = 1 << V_4 -> V_6 ;
unsigned int V_10 ;
int V_8 = 0 ;
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
V_8 = - V_19 ;
if ( ! V_4 -> V_13 )
F_6 ( L_2 ,
V_4 -> V_2 . V_14 , V_5 , F_3 ( V_9 ) ) ;
V_16:
if ( V_8 == 0 && V_4 -> V_20 && V_15 )
V_4 -> V_20 () ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) , true ) ;
}
static int F_10 ( void )
{
F_11 () ;
F_4 ( 0x300fffff , V_21 ) ;
return 0 ;
}
static bool F_12 ( struct V_22 * V_23 )
{
bool (* F_13)( struct V_22 * V_23 );
F_13 = F_14 ( V_23 ) -> V_24 . F_13 ;
return F_13 ? F_13 ( V_23 ) : true ;
}
static int F_15 ( struct V_22 * V_23 )
{
int (* F_16)( struct V_22 * V_23 );
F_16 = F_14 ( V_23 ) -> V_24 . F_16 ;
if ( F_16 ) {
int V_8 = F_16 ( V_23 ) ;
if ( V_8 )
return V_8 ;
}
return F_17 ( V_23 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
int (* F_19)( struct V_22 * V_23 );
int V_8 ;
V_8 = F_20 ( V_23 ) ;
if ( V_8 )
return V_8 ;
F_19 = F_14 ( V_23 ) -> V_24 . F_19 ;
if ( F_19 )
V_8 = F_19 ( V_23 ) ;
return V_8 ;
}
void F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_25 * V_26 = V_4 -> V_26 ;
F_22 ( V_2 , V_26 ? : & V_27 , false ) ;
V_2 -> V_28 . F_16 = F_15 ;
V_2 -> V_28 . F_19 = F_18 ;
V_2 -> V_28 . F_13 = F_12 ;
V_2 -> V_29 = true ;
V_2 -> V_30 = F_1 ;
V_2 -> V_31 = F_9 ;
F_7 ( V_4 , false ) ;
}
void F_23 ( struct V_3 * V_4 ,
struct V_32 * V_33 )
{
struct V_22 * V_23 = & V_33 -> V_23 ;
F_24 ( & V_4 -> V_2 , V_23 ) ;
if ( F_25 ( V_23 ) )
F_26 ( V_23 , NULL ) ;
}
void F_27 ( struct V_3 * V_4 ,
struct V_3 * V_34 )
{
F_28 ( & V_4 -> V_2 , & V_34 -> V_2 ) ;
}
static int F_29 ( void )
{
return - V_35 ;
}
static int F_30 ( void )
{
return V_36 ? 0 : - V_35 ;
}
static inline void F_31 ( void ) {}
static int F_32 ( unsigned long V_37 )
{
F_33 () ;
return 0 ;
}
static void F_34 ( unsigned long V_38 )
{
F_4 ( V_38 , V_39 ) ;
F_4 ( 0 , V_40 ) ;
}
static void F_35 ( void )
{
F_34 ( F_36 ( V_41 ) ) ;
F_4 ( 0x10 , V_42 ) ;
F_37 ( 0 , F_32 ) ;
F_4 ( 0 , V_42 ) ;
F_4 ( 0 , V_39 ) ;
}
static void F_38 ( int V_43 , unsigned long V_44 )
{
if ( V_43 )
F_4 ( 0 , V_45 ) ;
else
F_4 ( 1 << 28 , V_45 ) ;
F_3 ( V_46 ) ;
F_37 ( V_44 , V_47 ) ;
F_3 ( V_46 ) ;
F_4 ( 0 , V_39 ) ;
}
static int F_39 ( unsigned long * V_48 , unsigned long * V_49 )
{
unsigned long V_50 , V_51 , V_52 , V_53 , V_54 ;
unsigned long V_55 , V_56 ;
V_50 = F_3 ( V_57 ) ;
if ( ( V_50 & 0x00000003 ) != 0x00000003 ) {
F_6 ( L_3 , V_50 ) ;
return 0 ;
}
V_51 = F_3 ( V_58 ) ;
if ( ( V_51 & 0xff079b7f ) != 0xff079b7f ) {
F_6 ( L_4 , V_51 ) ;
return 0 ;
}
V_52 = F_3 ( V_59 ) ;
if ( ( V_52 & 0x000741ff ) != 0x000741ff ) {
F_6 ( L_5 , V_52 ) ;
return 0 ;
}
V_53 = F_3 ( V_60 ) ;
if ( ( V_53 & 0x1a60f010 ) != 0x1a60f010 ) {
F_6 ( L_6 , V_53 ) ;
return 0 ;
}
V_54 = F_3 ( V_61 ) ;
if ( ( V_54 & 0x00008cf0 ) != 0x00008cf0 ) {
F_6 ( L_7 , V_54 ) ;
return 0 ;
}
V_55 = 0 ;
V_56 = 0 ;
if ( ( V_52 & ( 1 << 23 ) ) == 0 )
V_55 |= 1 << 31 ;
if ( ( V_52 & ( 1 << 12 ) ) == 0 )
V_55 |= 1 << 21 ;
if ( ( V_54 & ( 1 << 3 ) ) == 0 )
V_55 |= 1 << 2 ;
if ( ( V_51 & ( 1 << 24 ) ) == 0 )
V_55 |= 1 << 1 ;
if ( ( V_53 & ( 1 << 29 ) ) == 0 )
V_55 |= 1 << 1 ;
if ( ( V_54 & ( 1 << 0 ) ) == 0 )
V_55 |= 1 << 1 ;
if ( ( V_52 & ( 1 << 13 ) ) == 0 )
V_56 |= 1 << 17 ;
* V_48 = V_55 ;
* V_49 = V_56 ;
return 1 ;
}
static void F_40 ( unsigned long V_62 , T_1 * V_63 , T_1 * V_64 )
{
T_1 V_65 , V_66 , V_67 ;
int V_68 ;
V_66 = 0 ;
V_67 = 0 ;
for ( V_68 = 0 ; V_68 <= 7 ; V_68 ++ ) {
V_65 = ( V_62 >> ( ( 7 - V_68 ) * 4 ) ) & 0xf ;
V_66 |= ( V_65 & 0x03 ) << ( V_68 * 2 ) ;
V_67 |= ( V_65 >> 2 ) << ( V_68 * 2 ) ;
}
* V_63 = V_66 ;
* V_64 = V_67 ;
}
static void F_41 ( unsigned long V_55 , unsigned long V_56 )
{
T_1 V_69 , V_70 , V_71 , V_72 ;
unsigned long V_65 ;
V_65 = F_42 ( F_43 ( V_73 ) ) ;
V_65 |= F_42 ( F_43 ( V_74 ) ) << 8 ;
V_55 = ( ~ V_55 & 0xc030000f ) | ( V_65 << 4 ) ;
F_4 ( V_55 , V_75 ) ;
F_40 ( F_3 ( V_76 ) , & V_69 , & V_71 ) ;
F_40 ( F_3 ( V_77 ) , & V_70 , & V_72 ) ;
F_4 ( ( V_70 << 16 ) | V_69 , V_78 ) ;
F_4 ( ( V_72 << 16 ) | V_71 , V_79 ) ;
V_65 = F_42 ( F_43 ( V_80 ) ) ;
V_65 |= F_42 ( F_43 ( V_81 ) ) << 8 ;
V_56 = ( ~ V_56 & 0x00030000 ) | V_65 ;
F_4 ( V_56 , V_82 ) ;
F_40 ( F_3 ( V_83 ) , & V_69 , & V_71 ) ;
F_40 ( F_3 ( V_84 ) , & V_70 , & V_72 ) ;
F_4 ( ( V_70 << 16 ) | V_69 , V_85 ) ;
F_4 ( ( V_72 << 16 ) | V_71 , V_86 ) ;
}
static void F_44 ( int V_43 )
{
F_34 ( F_36 ( V_41 ) ) ;
F_38 ( V_43 , 1 << 12 ) ;
}
static void F_45 ( int V_43 )
{
F_46 () ;
memcpy ( ( void * ) V_87 , V_41 , 0x100 ) ;
F_34 ( V_87 ) ;
F_38 ( V_43 , 1 << 10 ) ;
F_47 () ;
}
static void F_48 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = & V_89 -> V_92 [ V_89 -> V_93 ] ;
snprintf ( V_91 -> V_14 , V_94 , L_8 ) ;
strncpy ( V_91 -> V_95 , L_9 , V_96 ) ;
V_91 -> V_97 = 10 ;
V_91 -> V_98 = 20 + 10 ;
V_91 -> V_99 = V_100 ;
V_101 [ V_89 -> V_93 ] = F_35 ;
V_89 -> V_93 ++ ;
}
static void F_49 ( void )
{
V_102 = F_48 ;
}
static void F_49 ( void ) {}
static int F_50 ( T_2 V_103 )
{
unsigned long V_55 , V_56 ;
if ( F_39 ( & V_55 , & V_56 ) ) {
F_41 ( V_55 , V_56 ) ;
if ( ! V_36 &&
V_104 . V_2 . V_105 == V_106 ) {
F_6 ( L_10 ) ;
F_45 ( 0 ) ;
} else {
F_6 ( L_11 ) ;
F_44 ( 0 ) ;
}
} else {
F_6 ( L_12 ) ;
F_35 () ;
}
return 0 ;
}
static int F_51 ( struct V_107 * V_108 ,
unsigned long V_109 , void * V_37 )
{
switch ( V_109 ) {
case V_110 :
F_52 ( & V_111 . V_2 ) ;
break;
case V_112 :
F_53 () ;
break;
}
return V_113 ;
}
static void F_54 ( void )
{
V_114 . V_115 = F_50 ;
F_55 ( F_51 , 0 ) ;
}
static void F_54 ( void ) {}
void T_3 F_56 ( void )
{
F_4 ( 0x0000a500 , V_116 ) ;
F_4 ( 0x0000a501 , V_116 ) ;
F_4 ( 0x00000000 , V_117 ) ;
F_4 ( 0 , V_118 ) ;
F_54 () ;
F_49 () ;
}
