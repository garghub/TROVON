static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
V_2 -> V_4 = false ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
}
static struct V_1 * F_4 ( void )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
return NULL ;
return V_2 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static bool F_8 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
F_9 ( V_2 -> V_2 , V_2 -> V_3 , V_7 / 10 ) ;
if ( ! V_2 -> V_3 )
return false ;
return true ;
}
static void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_3 = true ;
F_11 ( & V_2 -> V_2 ) ;
}
static T_1 F_12 ( const struct V_8 * V_8 , unsigned int V_9 )
{
return V_8 -> V_10 [ V_9 ] . V_9 ;
}
static T_1 F_13 ( const struct V_11 * V_11 )
{
return F_12 ( V_11 -> V_8 ,
F_14 ( V_11 -> V_12 ) ) ;
}
static T_1 F_15 ( const struct V_11 * V_11 )
{
return F_12 ( V_11 -> V_8 ,
F_16 ( V_11 -> V_12 ) ) ;
}
static int F_17 ( const struct V_8 * V_8 )
{
const struct V_13 * V_14 = V_8 -> V_14 ;
T_2 V_15 ;
T_2 V_16 ;
V_16 = F_18 () ;
V_16 >>= 1 ;
F_19 ( V_8 , V_17 , V_16 ) ;
V_15 = F_20 ( V_8 , V_17 ) ;
if ( V_15 != V_16 * 2 ) {
F_21 ( & V_14 -> V_18 , L_1 ,
V_15 , V_16 * 2 ) ;
return - V_19 ;
}
V_16 = F_18 () ;
V_16 <<= 31 ;
V_16 |= F_18 () ;
F_22 ( V_8 , V_20 , V_16 ) ;
V_15 = F_23 ( V_8 , V_20 ) ;
if ( V_15 != V_16 * 2 ) {
F_21 ( & V_14 -> V_18 , L_2 ,
V_15 , V_16 * 2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_24 ( const struct V_8 * V_8 ,
struct V_1 * V_2 , T_1 V_21 ,
T_3 V_22 , const unsigned char * V_23 ,
const unsigned char * V_24 , T_4 V_25 )
{
const struct V_13 * V_14 = V_8 -> V_14 ;
int V_26 ;
F_1 ( V_2 ) ;
F_19 ( V_8 , V_27 , V_21 ) ;
if ( ! F_8 ( V_2 , V_7 / 10 ) ) {
F_21 ( & V_14 -> V_18 , L_3 ) ;
return - V_19 ;
}
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
if ( V_23 [ V_26 ] != V_24 [ V_26 ] ) {
F_21 ( & V_14 -> V_18 , L_4 ,
V_23 [ V_26 ] , V_26 , V_24 [ V_26 ] ) ;
return - V_19 ;
}
}
return 0 ;
}
static int F_25 ( const struct V_8 * V_8 ,
struct V_1 * V_2 , int V_28 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
unsigned char * V_29 ;
unsigned char * V_23 ;
unsigned char * V_24 ;
T_3 V_22 ;
int V_26 ;
int V_30 ;
V_29 = F_5 ( V_31 * 2 + V_28 ,
V_5 | V_32 ) ;
if ( ! V_29 )
return - V_33 ;
V_23 = V_29 + V_28 ;
V_24 = V_23 + V_31 ;
V_22 = F_26 ( V_14 , V_23 , V_31 ,
V_34 ) ;
if ( F_27 ( V_14 , V_22 ) ) {
V_30 = - V_19 ;
goto V_35;
}
F_22 ( V_8 , V_36 , V_22 ) ;
F_19 ( V_8 , V_37 , V_31 ) ;
memset ( V_24 , V_38 , V_31 ) ;
V_30 = F_24 ( V_8 , V_2 , V_39 ,
V_22 , V_23 , V_24 ,
V_31 ) ;
if ( V_30 )
goto V_40;
memset ( V_24 , 0 , V_31 ) ;
V_30 = F_24 ( V_8 , V_2 , V_41 ,
V_22 , V_23 , V_24 ,
V_31 ) ;
if ( V_30 )
goto V_40;
F_28 ( V_23 , V_31 ) ;
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ )
V_24 [ V_26 ] = ~ V_23 [ V_26 ] ;
V_30 = F_24 ( V_8 , V_2 , V_42 ,
V_22 , V_23 , V_24 ,
V_31 ) ;
if ( V_30 )
goto V_40;
V_40:
F_29 ( V_14 , V_22 , V_31 ,
V_34 ) ;
V_35:
F_7 ( V_29 ) ;
return V_30 ;
}
static int F_30 ( const struct V_8 * V_8 ,
struct V_1 * V_2 )
{
int V_26 ;
int V_30 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
V_30 = F_25 ( V_8 , V_2 , V_26 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static T_5 F_31 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
F_10 ( V_2 ) ;
return V_45 ;
}
static int F_32 ( const struct V_8 * V_8 )
{
const struct V_13 * V_14 = V_8 -> V_14 ;
struct V_1 V_2 ;
int V_30 ;
V_30 = F_17 ( V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_5 ) ;
return V_30 ;
}
V_30 = F_33 ( F_12 ( V_8 , V_46 ) ,
F_31 , 0 ,
V_47 , & V_2 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_6 ) ;
return V_30 ;
}
F_2 ( & V_2 ) ;
F_19 ( V_8 , V_48 , V_46 ) ;
if ( ! F_8 ( & V_2 , V_7 / 10 ) ) {
F_21 ( & V_14 -> V_18 , L_3 ) ;
V_30 = - V_19 ;
goto V_49;
}
V_30 = F_30 ( V_8 , & V_2 ) ;
if ( V_30 )
F_21 ( & V_14 -> V_18 , L_7 ) ;
V_49:
V_49 ( F_12 ( V_8 , V_46 ) , & V_2 ) ;
return V_30 ;
}
static T_1 F_34 ( T_1 V_50 , T_4 V_51 )
{
return ++ V_50 == V_51 ? 0 : V_50 ;
}
static int F_35 ( const struct V_52 * V_53 )
{
int V_30 = V_53 -> V_54 -> V_55 & ~ V_56 ;
switch ( V_30 ) {
case V_57 :
return 0 ;
case - V_58 :
return - V_59 ;
case - V_60 :
return - V_61 ;
case - V_62 :
return - V_33 ;
case - V_63 :
return - V_64 ;
case - V_65 :
return - V_66 ;
case - V_67 :
return - V_68 ;
case - V_69 :
return - V_70 ;
case - V_71 :
return - V_72 ;
}
return - V_66 ;
}
static void F_36 ( const struct V_52 * V_53 )
{
V_53 -> V_54 -> V_55 &= ~ V_56 ;
}
static bool F_37 ( const struct V_52 * V_53 )
{
T_1 V_55 = V_53 -> V_54 -> V_55 ;
return V_55 & V_56 ? true : false ;
}
static void *
F_38 ( const struct V_52 * V_53 )
{
return ( void * ) ( V_73 ) V_53 -> V_54 -> V_74 ;
}
static void F_39 ( const struct V_52 * V_53 ,
void * V_75 )
{
V_53 -> V_54 -> V_74 = ( V_73 ) V_75 ;
}
static struct V_52 *
F_40 ( const struct V_76 * V_77 )
{
static struct V_52 * V_53 ;
T_1 V_78 = F_34 ( V_77 -> V_78 , V_77 -> V_25 ) ;
V_53 = & V_77 -> V_53 [ V_77 -> V_78 ] ;
if ( V_78 == V_77 -> V_79 )
return NULL ;
V_53 -> V_80 = 0 ;
return V_53 ;
}
static void F_41 ( const struct V_52 * V_53 )
{
V_53 -> V_54 -> V_81 = V_53 -> V_82 ;
V_53 -> V_54 -> V_80 = V_53 -> V_80 ;
}
static void F_42 ( const struct V_8 * V_8 ,
struct V_76 * V_77 ,
const struct V_52 * V_53 )
{
T_1 V_78 = F_34 ( V_77 -> V_78 , V_77 -> V_25 ) ;
F_43 ( V_78 == V_77 -> V_79 ) ;
F_41 ( V_53 ) ;
V_77 -> V_78 = V_78 ;
F_19 ( V_8 , F_44 ( V_77 -> type ) , V_78 ) ;
}
static struct V_52 *
F_45 ( struct V_76 * V_77 )
{
static struct V_52 * V_53 ;
if ( V_77 -> V_79 == V_77 -> V_78 )
return NULL ;
V_53 = & V_77 -> V_53 [ V_77 -> V_79 ] ;
if ( ! F_37 ( V_53 ) )
return NULL ;
V_77 -> V_79 = F_34 ( V_77 -> V_79 , V_77 -> V_25 ) ;
V_53 -> V_80 = V_53 -> V_54 -> V_80 ;
return V_53 ;
}
static void F_46 ( const struct V_8 * V_8 ,
const struct V_76 * V_77 ,
T_1 V_83 )
{
if ( V_83 )
F_19 ( V_8 , F_47 ( V_77 -> type ) , V_83 ) ;
}
static unsigned long F_48 ( T_4 V_25 )
{
return F_49 ( V_84 ,
F_50 ( F_51 ( V_25 ) , V_85 ) ) ;
}
static int F_52 ( const struct V_8 * V_8 ,
unsigned int type ,
T_4 V_25 ,
struct V_76 * V_77 )
{
int V_26 ;
F_43 ( V_25 != F_48 ( V_25 ) ) ;
V_77 -> V_25 = V_25 ;
V_77 -> type = type ;
V_77 -> V_78 = 0 ;
V_77 -> V_79 = 0 ;
V_77 -> V_53 = F_53 ( V_77 -> V_25 , sizeof( * V_77 -> V_53 ) ,
V_5 ) ;
if ( ! V_77 -> V_53 )
return - V_33 ;
V_77 -> V_54 = F_54 ( V_8 -> V_14 ,
V_77 -> V_25 * sizeof( * V_77 -> V_54 ) ,
& V_77 -> V_86 ) ;
if ( ! V_77 -> V_54 ) {
F_7 ( V_77 -> V_53 ) ;
return - V_33 ;
}
for ( V_26 = 0 ; V_26 < V_77 -> V_25 ; V_26 ++ )
V_77 -> V_53 [ V_26 ] . V_54 = & V_77 -> V_54 [ V_26 ] ;
F_19 ( V_8 , F_55 ( V_77 -> type ) ,
V_87 ) ;
F_22 ( V_8 , F_56 ( V_77 -> type ) , V_77 -> V_86 ) ;
F_19 ( V_8 , F_57 ( V_77 -> type ) , V_77 -> V_25 ) ;
return 0 ;
}
static void F_58 ( const struct V_8 * V_8 ,
const struct V_76 * V_77 )
{
F_22 ( V_8 , F_56 ( V_77 -> type ) , 0 ) ;
F_59 ( V_8 -> V_14 ,
V_77 -> V_25 * sizeof( struct V_88 ) ,
V_77 -> V_54 , V_77 -> V_86 ) ;
F_7 ( V_77 -> V_53 ) ;
}
static void F_60 ( const struct V_8 * V_8 ,
struct V_76 * V_77 )
{
int V_26 ;
F_43 ( V_77 -> V_78 || V_77 -> V_79 ) ;
for ( V_26 = 0 ; V_26 < V_77 -> V_25 - 1 ; V_26 ++ )
F_42 ( V_8 , V_77 , & V_77 -> V_53 [ V_26 ] ) ;
F_41 ( & V_77 -> V_53 [ V_26 ] ) ;
}
static int F_61 ( const struct V_8 * V_8 ,
const struct V_76 * V_77 ,
int V_89 , T_4 V_81 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
int V_26 ;
int V_30 ;
for ( V_26 = 0 ; V_26 < V_77 -> V_25 ; V_26 ++ ) {
struct V_52 * V_53 = & V_77 -> V_53 [ V_26 ] ;
struct V_88 * V_54 = & V_77 -> V_54 [ V_26 ] ;
T_3 V_22 ;
char * V_23 ;
V_23 = F_5 ( V_81 , V_5 | V_32 ) ;
if ( ! V_23 ) {
V_30 = - V_33 ;
goto V_90;
}
V_22 = F_26 ( V_14 , V_23 , V_81 , V_89 ) ;
if ( F_27 ( V_14 , V_22 ) ) {
F_7 ( V_23 ) ;
V_30 = - V_19 ;
goto V_90;
}
V_53 -> V_91 = V_23 ;
V_53 -> V_82 = V_81 ;
F_62 ( V_53 , V_86 , V_22 ) ;
V_54 -> V_92 = V_22 ;
V_54 -> V_81 = V_81 ;
}
return 0 ;
V_90:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- ) {
const struct V_52 * V_53 = & V_77 -> V_53 [ V_26 ] ;
F_29 ( V_14 , F_63 ( V_53 , V_86 ) ,
V_53 -> V_82 , V_89 ) ;
F_7 ( V_53 -> V_91 ) ;
}
return V_30 ;
}
static void F_64 ( const struct V_8 * V_8 ,
const struct V_76 * V_77 ,
int V_89 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_77 -> V_25 ; V_26 ++ ) {
const struct V_52 * V_53 = & V_77 -> V_53 [ V_26 ] ;
struct V_88 * V_54 = & V_77 -> V_54 [ V_26 ] ;
V_54 -> V_92 = 0 ;
V_54 -> V_81 = 0 ;
F_29 ( V_14 , F_63 ( V_53 , V_86 ) ,
V_53 -> V_82 , V_89 ) ;
F_7 ( V_53 -> V_91 ) ;
}
}
static int F_65 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
V_2 = F_4 () ;
if ( ! V_2 )
return - V_33 ;
F_39 ( V_53 , V_2 ) ;
return 0 ;
}
static void
F_66 ( const struct V_52 * V_53 )
{
struct V_1 * V_2 = F_38 ( V_53 ) ;
F_6 ( V_2 ) ;
}
static int F_67 ( const struct V_8 * V_8 )
{
const struct V_76 * V_93 = & V_8 -> V_93 ;
int V_26 ;
int V_30 ;
for ( V_26 = 0 ; V_26 < V_93 -> V_25 ; V_26 ++ ) {
V_30 = F_65 ( & V_93 -> V_53 [ V_26 ] ) ;
if ( V_30 )
goto V_90;
}
return 0 ;
V_90:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- )
F_66 ( & V_93 -> V_53 [ V_26 ] ) ;
return V_30 ;
}
static void F_68 ( const struct V_8 * V_8 )
{
const struct V_76 * V_93 = & V_8 -> V_93 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_93 -> V_25 ; V_26 ++ )
F_66 ( & V_93 -> V_53 [ V_26 ] ) ;
}
static int F_69 ( struct V_8 * V_8 )
{
const struct V_13 * V_14 = V_8 -> V_14 ;
int V_30 ;
V_30 = F_52 ( V_8 , V_94 ,
V_95 ,
& V_8 -> V_93 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_8 ) ;
return V_30 ;
}
F_70 ( & V_8 -> V_96 ) ;
V_30 = F_61 ( V_8 , & V_8 -> V_93 ,
V_34 , V_97 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_9 ) ;
goto V_98;
}
V_30 = F_67 ( V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_10 ) ;
goto V_99;
}
V_30 = F_52 ( V_8 , V_100 ,
V_101 ,
& V_8 -> V_102 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_11 ) ;
goto V_103;
}
V_30 = F_61 ( V_8 , & V_8 -> V_102 ,
V_104 , V_97 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_12 ) ;
goto V_105;
}
F_60 ( V_8 , & V_8 -> V_102 ) ;
return 0 ;
V_105:
F_58 ( V_8 , & V_8 -> V_102 ) ;
V_103:
F_64 ( V_8 , & V_8 -> V_93 ,
V_34 ) ;
V_99:
F_68 ( V_8 ) ;
V_98:
F_58 ( V_8 , & V_8 -> V_93 ) ;
return V_30 ;
}
static void F_71 ( struct V_8 * V_8 )
{
F_64 ( V_8 , & V_8 -> V_102 ,
V_34 ) ;
F_58 ( V_8 , & V_8 -> V_102 ) ;
F_68 ( V_8 ) ;
F_64 ( V_8 , & V_8 -> V_93 ,
V_34 ) ;
F_58 ( V_8 , & V_8 -> V_93 ) ;
}
static int F_72 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
struct V_106 * V_107 , T_4 V_108 )
{
const struct V_8 * V_8 = V_11 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_14 ;
T_3 V_22 ;
V_22 = F_26 ( V_14 , V_107 -> V_91 , V_108 ,
V_104 ) ;
if ( F_27 ( V_14 , V_22 ) )
return - V_19 ;
if ( F_73 ( V_53 , V_109 , V_22 ) )
goto V_110;
if ( F_74 ( V_53 , V_111 , V_108 ) )
goto V_110;
return 0 ;
V_110:
F_29 ( V_14 , V_22 , V_108 , V_104 ) ;
V_53 -> V_80 = 0 ;
return - V_68 ;
}
static T_4 F_75 ( const struct V_11 * V_11 )
{
return V_11 -> V_18 -> V_112 + V_113 + V_114 + V_115 ;
}
static int F_76 ( const struct V_11 * V_11 ,
struct V_52 * V_53 )
{
struct V_116 * V_18 = V_11 -> V_18 ;
struct V_106 * V_107 ;
T_4 V_108 = F_75 ( V_11 ) ;
int V_30 ;
F_39 ( V_53 , NULL ) ;
V_53 -> V_80 = 0 ;
V_107 = F_77 ( V_18 , V_108 ) ;
if ( ! V_107 )
return - V_33 ;
V_30 = F_72 ( V_11 , V_53 , V_107 , V_108 ) ;
if ( V_30 ) {
F_78 ( V_107 ) ;
return V_30 ;
}
F_39 ( V_53 , V_107 ) ;
return 0 ;
}
static void F_79 ( const struct V_8 * V_8 ,
const struct V_117 * * V_118 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
T_3 V_22 ;
T_4 V_119 ;
if ( ! V_118 [ V_109 ] ||
! V_118 [ V_111 ] )
return;
V_22 = F_80 ( V_118 [ V_109 ] ) ;
V_119 = F_81 ( V_118 [ V_111 ] ) ;
F_29 ( V_14 , V_22 , V_119 , V_104 ) ;
}
static void F_82 ( const struct V_8 * V_8 ,
const struct V_52 * V_53 )
{
const struct V_117 * V_118 [ V_120 + 1 ] ;
struct V_106 * V_107 = F_38 ( V_53 ) ;
if ( ! V_107 )
return;
F_83 ( V_118 , V_120 , V_53 ) ;
F_79 ( V_8 , V_118 ) ;
F_78 ( V_107 ) ;
}
static int F_84 ( const struct V_11 * V_11 )
{
const struct V_76 * V_121 = & V_11 -> V_121 ;
const struct V_8 * V_8 = V_11 -> V_8 ;
int V_26 ;
int V_30 ;
for ( V_26 = 0 ; V_26 < V_121 -> V_25 ; V_26 ++ ) {
V_30 = F_76 ( V_11 ,
& V_121 -> V_53 [ V_26 ] ) ;
if ( V_30 )
goto V_90;
}
return 0 ;
V_90:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- )
F_82 ( V_8 , & V_121 -> V_53 [ V_26 ] ) ;
return V_30 ;
}
static void F_85 ( const struct V_11 * V_11 )
{
const struct V_76 * V_121 = & V_11 -> V_121 ;
const struct V_8 * V_8 = V_11 -> V_8 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_121 -> V_25 ; V_26 ++ )
F_82 ( V_8 , & V_121 -> V_53 [ V_26 ] ) ;
}
static int F_86 ( struct V_11 * V_11 )
{
struct V_8 * V_8 = V_11 -> V_8 ;
int V_30 ;
V_30 = F_52 ( V_8 ,
F_87 ( V_11 -> V_12 ) ,
V_122 ,
& V_11 -> V_123 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_13 ) ;
return V_30 ;
}
V_30 = F_61 ( V_8 , & V_11 -> V_123 ,
V_124 ,
V_125 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_14 ) ;
goto V_126;
}
V_30 = F_52 ( V_8 ,
F_89 ( V_11 -> V_12 ) ,
V_127 ,
& V_11 -> V_121 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_15 ) ;
goto V_128;
}
V_30 = F_61 ( V_8 , & V_11 -> V_121 ,
V_34 ,
V_129 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_16 ) ;
goto V_130;
}
V_30 = F_84 ( V_11 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_17 ) ;
goto V_131;
}
F_60 ( V_8 , & V_11 -> V_121 ) ;
return 0 ;
V_131:
F_64 ( V_8 , & V_11 -> V_121 ,
V_34 ) ;
V_130:
F_58 ( V_8 , & V_11 -> V_121 ) ;
V_128:
F_64 ( V_8 , & V_11 -> V_123 ,
V_124 ) ;
V_126:
F_58 ( V_8 , & V_11 -> V_123 ) ;
return V_30 ;
}
static void F_90 ( struct V_11 * V_11 )
{
struct V_8 * V_8 = V_11 -> V_8 ;
F_85 ( V_11 ) ;
F_64 ( V_8 , & V_11 -> V_121 ,
V_34 ) ;
F_58 ( V_8 , & V_11 -> V_121 ) ;
F_64 ( V_8 , & V_11 -> V_123 ,
V_124 ) ;
F_58 ( V_8 , & V_11 -> V_123 ) ;
}
static void F_91 ( const struct V_11 * V_11 ,
bool V_132 )
{
T_2 V_133 = F_23 ( V_11 -> V_8 , V_134 ) ;
if ( V_132 )
V_133 |= 1ULL << V_11 -> V_135 ;
else
V_133 &= ~ ( 1ULL << V_11 -> V_135 ) ;
F_22 ( V_11 -> V_8 , V_134 , V_133 ) ;
}
static T_5 F_92 ( int V_43 , void * V_44 )
{
struct V_8 * V_8 = V_44 ;
const struct V_52 * V_53 ;
struct V_1 * V_2 ;
T_1 V_83 = 0 ;
F_93 ( & V_8 -> V_96 ) ;
while ( ( V_53 = F_45 ( & V_8 -> V_93 ) ) ) {
V_2 = F_38 ( V_53 ) ;
if ( V_2 -> V_4 ) {
F_36 ( V_53 ) ;
} else {
F_10 ( V_2 ) ;
}
V_83 ++ ;
}
F_94 ( & V_8 -> V_96 ) ;
F_46 ( V_8 , & V_8 -> V_93 , V_83 ) ;
return V_45 ;
}
static void F_95 ( const struct V_11 * V_11 )
{
F_96 ( V_11 -> V_18 ) ;
F_97 ( V_11 -> V_18 , L_18 ) ;
}
static void F_98 ( const struct V_11 * V_11 )
{
F_99 ( V_11 -> V_18 ) ;
F_97 ( V_11 -> V_18 , L_19 ) ;
}
static int F_100 ( const struct V_8 * V_8 ,
const struct V_117 * V_77 )
{
const struct V_117 * V_118 [ V_136 + 1 ] ;
unsigned int V_12 ;
bool V_137 ;
struct V_11 * V_11 ;
F_101 ( V_118 , V_136 , V_77 ) ;
if ( ! V_118 [ V_138 ] ||
! V_118 [ V_139 ] )
return - V_19 ;
V_12 =
F_102 ( V_118 [ V_138 ] ) - 1 ;
V_137 = F_103 ( V_118 [ V_139 ] ) ;
if ( V_12 >= V_8 -> V_140 )
return - V_66 ;
V_11 = V_8 -> V_141 [ V_12 ] ;
if ( F_104 ( V_11 -> V_18 ) != V_137 ) {
if ( V_137 )
F_95 ( V_11 ) ;
else
F_98 ( V_11 ) ;
}
return 0 ;
}
static int F_105 ( const struct V_8 * V_8 ,
const struct V_117 * V_77 )
{
const struct V_117 * V_118 [ V_142 + 1 ] ;
unsigned int V_12 ;
struct V_11 * V_11 ;
const unsigned char * V_143 ;
T_6 V_144 ;
F_101 ( V_118 , V_142 , V_77 ) ;
if ( ! V_118 [ V_145 ] ||
! V_118 [ V_146 ] ||
! V_118 [ V_147 ] )
return - V_19 ;
V_12 =
F_102 ( V_118 [ V_145 ] ) - 1 ;
V_143 = F_106 ( V_118 [ V_146 ] ) ;
V_144 = F_107 ( V_118 [ V_147 ] ) ;
if ( V_12 >= V_8 -> V_140 )
return - V_66 ;
V_11 = V_8 -> V_141 [ V_12 ] ;
return F_108 ( V_11 , V_143 , V_144 ) ;
}
static int F_109 ( const struct V_8 * V_8 ,
const struct V_52 * V_53 )
{
const struct V_117 * V_118 [ V_148 + 1 ] ;
const struct V_117 * V_77 ;
T_7 type ;
F_83 ( V_118 , V_148 , V_53 ) ;
if ( ! V_118 [ V_149 ] ||
! V_118 [ V_150 ] )
return - V_19 ;
type = F_81 ( V_118 [ V_149 ] ) ;
V_77 = V_118 [ V_150 ] ;
switch ( type ) {
case V_151 :
return F_100 ( V_8 , V_77 ) ;
case V_152 :
return F_105 ( V_8 , V_77 ) ;
}
return - V_70 ;
}
static T_5 F_110 ( int V_43 , void * V_44 )
{
struct V_8 * V_8 = V_44 ;
const struct V_13 * V_14 = V_8 -> V_14 ;
const struct V_52 * V_53 ;
T_1 V_83 = 0 ;
int V_30 ;
while ( ( V_53 = F_45 ( & V_8 -> V_102 ) ) ) {
V_30 = F_35 ( V_53 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_20 ,
V_30 ) ;
} else {
V_30 = F_109 ( V_8 , V_53 ) ;
if ( V_30 )
F_21 ( & V_14 -> V_18 , L_21 ,
V_30 ) ;
}
F_36 ( V_53 ) ;
F_42 ( V_8 , & V_8 -> V_102 , V_53 ) ;
V_83 ++ ;
}
F_46 ( V_8 , & V_8 -> V_102 , V_83 ) ;
return V_45 ;
}
static T_5 F_111 ( int V_43 , void * V_44 )
{
struct V_11 * V_11 = V_44 ;
F_112 ( & V_11 -> V_153 ) ;
return V_45 ;
}
static T_5 F_113 ( int V_43 , void * V_44 )
{
struct V_11 * V_11 = V_44 ;
F_112 ( & V_11 -> V_154 ) ;
return V_45 ;
}
int F_114 ( struct V_11 * V_11 , bool V_4 ,
T_8 V_155 , void * V_156 ,
T_9 V_157 , void * V_158 )
{
struct V_8 * V_8 = V_11 -> V_8 ;
struct V_52 * V_53 ;
struct V_1 * V_2 ;
unsigned long V_159 ;
int V_30 ;
F_115 ( & V_8 -> V_96 , V_159 ) ;
V_53 = F_40 ( & V_8 -> V_93 ) ;
if ( ! V_53 ) {
F_116 ( & V_8 -> V_96 , V_159 ) ;
return - V_160 ;
}
V_2 = F_38 ( V_53 ) ;
F_2 ( V_2 ) ;
V_2 -> V_4 = V_4 ;
V_30 = V_155 ( V_11 , V_53 , V_156 ) ;
if ( V_30 ) {
F_116 ( & V_8 -> V_96 , V_159 ) ;
return V_30 ;
}
F_42 ( V_8 , & V_8 -> V_93 , V_53 ) ;
F_116 ( & V_8 -> V_96 , V_159 ) ;
if ( V_4 )
return 0 ;
if ( ! F_8 ( V_2 , V_7 / 10 ) )
return - V_19 ;
V_30 = F_35 ( V_53 ) ;
if ( V_30 )
return V_30 ;
if ( V_157 )
V_30 = V_157 ( V_11 , V_53 , V_158 ) ;
F_36 ( V_53 ) ;
return V_30 ;
}
static int
F_117 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
void * V_161 )
{
struct V_117 * V_162 ;
if ( F_74 ( V_53 , V_163 ,
V_164 ) )
return - V_68 ;
V_162 = F_118 ( V_53 , V_165 ) ;
if ( ! V_162 )
return - V_68 ;
if ( F_119 ( V_53 , V_166 ,
V_11 -> V_135 ) )
return - V_68 ;
F_120 ( V_53 , V_162 ) ;
return 0 ;
}
static int
F_121 ( const struct V_11 * V_11 ,
const struct V_52 * V_53 ,
void * V_161 )
{
struct V_167 * V_168 = V_161 ;
const struct V_117 * V_118 [ V_169 + 1 ] ;
const struct V_117 * V_170 [ V_171 + 1 ] ;
T_1 V_172 ;
T_10 V_173 ;
T_10 V_174 ;
F_83 ( V_118 , V_169 , V_53 ) ;
if ( ! V_118 [ V_165 ] )
return - V_19 ;
F_101 ( V_170 , V_171 ,
V_118 [ V_165 ] ) ;
if ( ! V_170 [ V_175 ] ||
! V_170 [ V_176 ] ||
! V_170 [ V_177 ] )
return - V_19 ;
V_172 = F_102 ( V_170 [ V_175 ] ) ;
V_173 = F_103 ( V_170 [ V_176 ] ) ;
V_174 = F_103 ( V_170 [ V_177 ] ) ;
F_122 ( V_168 , V_178 ) ;
F_123 ( V_168 , V_178 , V_179 ) ;
V_168 -> V_180 . V_181 = 0xff ;
V_168 -> V_180 . V_182 = V_183 ;
V_168 -> V_180 . V_172 = V_172 ;
V_168 -> V_180 . V_173 = V_173 ? V_184 : V_185 ;
V_168 -> V_180 . V_174 = V_174 ? V_186 : V_187 ;
return 0 ;
}
static int
F_124 ( const struct V_11 * V_11 ,
const struct V_52 * V_53 ,
void * V_161 )
{
unsigned char * V_188 = V_161 ;
const struct V_117 * V_118 [ V_169 + 1 ] ;
const struct V_117 * V_170 [ V_171 + 1 ] ;
const struct V_117 * V_189 ;
F_83 ( V_118 , V_169 , V_53 ) ;
if ( ! V_118 [ V_165 ] )
return - V_19 ;
F_101 ( V_170 , V_171 ,
V_118 [ V_165 ] ) ;
V_189 = V_170 [ V_190 ] ;
if ( ! V_189 )
return - V_19 ;
if ( F_125 ( V_189 ) != V_191 )
return - V_66 ;
F_126 ( V_188 , F_106 ( V_189 ) ) ;
return 0 ;
}
static int
F_127 ( const struct V_11 * V_11 ,
const struct V_52 * V_53 ,
void * V_161 )
{
T_10 * V_192 = V_161 ;
const struct V_117 * V_118 [ V_169 + 1 ] ;
const struct V_117 * V_170 [ V_171 + 1 ] ;
const struct V_117 * V_189 ;
F_83 ( V_118 , V_169 , V_53 ) ;
if ( ! V_118 [ V_165 ] )
return - V_19 ;
F_101 ( V_170 , V_171 ,
V_118 [ V_165 ] ) ;
V_189 = V_170 [ V_193 ] ;
if ( ! V_189 )
return - V_19 ;
* V_192 = F_103 ( V_170 [ V_193 ] ) ;
return 0 ;
}
static int
F_128 ( const struct V_11 * V_11 ,
const struct V_52 * V_53 ,
void * V_161 )
{
const struct V_117 * V_170 [ V_171 + 1 ] ;
const struct V_117 * V_118 [ V_169 + 1 ] ;
struct V_194 * V_195 = V_161 ;
const struct V_117 * V_189 ;
T_4 V_26 , V_196 , V_119 ;
const char * V_197 ;
F_83 ( V_118 , V_169 , V_53 ) ;
if ( ! V_118 [ V_165 ] )
return - V_19 ;
F_101 ( V_170 , V_171 ,
V_118 [ V_165 ] ) ;
V_189 = V_170 [ V_198 ] ;
if ( ! V_189 )
return - V_19 ;
V_119 = F_129 ( T_4 , F_125 ( V_189 ) , V_195 -> V_119 ) ;
V_197 = F_106 ( V_189 ) ;
for ( V_26 = V_196 = 0 ; V_26 < V_119 ; ++ V_26 ) {
if ( isalnum ( V_197 [ V_26 ] ) ) {
V_195 -> V_23 [ V_196 ] = V_197 [ V_26 ] ;
V_196 ++ ;
}
}
if ( V_196 == 0 )
return - V_19 ;
V_195 -> V_23 [ V_196 ] = '\0' ;
return 0 ;
}
static int
F_130 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
void * V_161 )
{
struct V_167 * V_168 = V_161 ;
struct V_117 * V_162 ;
if ( F_74 ( V_53 , V_163 ,
V_199 ) )
return - V_68 ;
V_162 = F_118 ( V_53 , V_165 ) ;
if ( ! V_162 )
return - V_68 ;
if ( F_119 ( V_53 , V_166 ,
V_11 -> V_135 ) )
return - V_68 ;
if ( F_119 ( V_53 , V_175 ,
V_168 -> V_180 . V_172 ) )
return - V_68 ;
if ( F_131 ( V_53 , V_176 ,
V_168 -> V_180 . V_173 ) )
return - V_68 ;
if ( F_131 ( V_53 , V_177 ,
V_168 -> V_180 . V_174 ) )
return - V_68 ;
F_120 ( V_53 , V_162 ) ;
return 0 ;
}
static int
F_132 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
void * V_161 )
{
const unsigned char * V_188 = V_161 ;
struct V_117 * V_162 ;
if ( F_74 ( V_53 , V_163 ,
V_199 ) )
return - V_68 ;
V_162 = F_118 ( V_53 , V_165 ) ;
if ( ! V_162 )
return - V_68 ;
if ( F_119 ( V_53 , V_166 ,
V_11 -> V_135 ) )
return - V_68 ;
if ( F_133 ( V_53 , V_190 ,
V_191 , V_188 ) )
return - V_68 ;
F_120 ( V_53 , V_162 ) ;
return 0 ;
}
static int
F_134 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
void * V_161 )
{
int V_112 = * ( int * ) V_161 ;
struct V_117 * V_162 ;
if ( F_74 ( V_53 , V_163 ,
V_199 ) )
return - V_68 ;
V_162 = F_118 ( V_53 , V_165 ) ;
if ( ! V_162 )
return - V_68 ;
if ( F_119 ( V_53 , V_166 ,
V_11 -> V_135 ) )
return - V_68 ;
if ( F_74 ( V_53 , V_200 ,
V_112 ) )
return - V_68 ;
F_120 ( V_53 , V_162 ) ;
return 0 ;
}
static int
F_135 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
void * V_161 )
{
bool V_201 = * ( bool * ) V_161 ;
struct V_117 * V_162 ;
if ( F_74 ( V_53 , V_163 ,
V_199 ) )
return - V_68 ;
V_162 = F_118 ( V_53 , V_165 ) ;
if ( ! V_162 )
return - V_68 ;
if ( F_119 ( V_53 , V_166 ,
V_11 -> V_135 ) )
return - V_68 ;
if ( F_131 ( V_53 , V_202 ,
V_201 ) )
return - V_68 ;
F_120 ( V_53 , V_162 ) ;
return 0 ;
}
static int
F_136 ( struct V_11 * V_11 ,
struct V_167 * V_168 )
{
return F_114 ( V_11 , false ,
F_117 , NULL ,
F_121 ,
V_168 ) ;
}
static int F_137 ( struct V_11 * V_11 ,
unsigned char * V_188 )
{
return F_114 ( V_11 , false ,
F_117 , NULL ,
F_124 ,
V_188 ) ;
}
static int F_138 ( struct V_11 * V_11 ,
T_10 * V_192 )
{
return F_114 ( V_11 , false ,
F_117 , NULL ,
F_127 , V_192 ) ;
}
static int
F_139 ( struct V_11 * V_11 ,
const struct V_167 * V_168 )
{
struct V_167 V_203 ;
memcpy ( & V_203 , V_168 , sizeof( V_203 ) ) ;
return F_114 ( V_11 , false ,
F_130 ,
& V_203 , NULL , NULL ) ;
}
static int F_140 ( struct V_11 * V_11 ,
unsigned char * V_188 )
{
return F_114 ( V_11 , false ,
F_132 ,
V_188 , NULL , NULL ) ;
}
static int F_141 ( struct V_11 * V_11 ,
int V_112 )
{
return F_114 ( V_11 , false ,
F_134 ,
& V_112 , NULL , NULL ) ;
}
int F_142 ( struct V_11 * V_11 ,
bool V_201 )
{
return F_114 ( V_11 , false ,
F_135 ,
& V_201 , NULL , NULL ) ;
}
static struct V_204 * F_143 ( T_10 V_205 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_206 ; V_26 ++ )
if ( V_204 [ V_26 ] -> V_205 == V_205 )
return V_204 [ V_26 ] ;
return NULL ;
}
static int F_144 ( struct V_8 * V_8 , T_10 V_205 )
{
struct V_204 * V_207 ;
int V_30 ;
V_207 = F_143 ( V_205 ) ;
if ( ! V_207 ) {
F_21 ( & V_8 -> V_14 -> V_18 , L_22 ,
V_205 ) ;
return - V_66 ;
}
V_8 -> V_207 = V_207 ;
V_8 -> V_208 = F_5 ( V_207 -> V_209 , V_5 ) ;
if ( ! V_8 -> V_208 )
return - V_33 ;
if ( ! V_207 -> V_210 )
return 0 ;
V_30 = V_207 -> V_210 ( V_8 ) ;
if ( V_30 )
F_7 ( V_8 -> V_208 ) ;
return V_30 ;
}
static void F_145 ( struct V_8 * V_8 )
{
struct V_204 * V_207 = V_8 -> V_207 ;
if ( ! V_207 || ! V_207 -> V_211 )
return;
V_207 -> V_211 ( V_8 ) ;
F_7 ( V_8 -> V_208 ) ;
}
static int F_146 ( struct V_11 * V_11 )
{
struct V_8 * V_8 = V_11 -> V_8 ;
T_10 V_205 ;
int V_30 ;
V_30 = F_138 ( V_11 , & V_205 ) ;
if ( V_30 ) {
F_21 ( & V_8 -> V_14 -> V_18 , L_23 ) ;
return V_30 ;
}
if ( V_8 -> V_207 ) {
if ( V_8 -> V_207 -> V_205 != V_205 ) {
F_21 ( & V_8 -> V_14 -> V_18 , L_24 ) ;
return - V_66 ;
}
return 0 ;
}
return F_144 ( V_8 , V_205 ) ;
}
static int F_147 ( struct V_11 * V_11 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
int V_30 ;
V_11 -> V_208 = F_5 ( V_207 -> V_212 , V_5 ) ;
if ( ! V_11 -> V_208 )
return - V_33 ;
if ( ! V_207 -> V_213 )
return 0 ;
V_30 = V_207 -> V_213 ( V_11 ) ;
if ( V_30 )
F_7 ( V_11 -> V_208 ) ;
return 0 ;
}
static int F_148 ( struct V_11 * V_11 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_214 )
return 0 ;
return V_207 -> V_214 ( V_11 ) ;
}
static void F_149 ( struct V_11 * V_11 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_215 )
return;
V_207 -> V_215 ( V_11 ) ;
}
static void F_150 ( struct V_11 * V_11 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_216 )
return;
V_207 -> V_216 ( V_11 ) ;
F_7 ( V_11 -> V_208 ) ;
}
static int F_151 ( struct V_11 * V_11 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_217 )
return 0 ;
return V_207 -> V_217 ( V_11 ) ;
}
static void F_152 ( struct V_11 * V_11 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_218 )
return;
V_207 -> V_218 ( V_11 ) ;
}
static int F_153 ( struct V_11 * V_11 ,
T_10 V_219 ,
struct V_220 * V_221 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_222 )
return - V_70 ;
if ( F_154 ( V_221 ) )
return 0 ;
return V_207 -> V_222 ( V_11 , V_219 ) ;
}
static int
F_155 ( struct V_11 * V_11 ,
unsigned long V_223 ,
struct V_220 * V_221 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_224 )
return - V_70 ;
if ( F_154 ( V_221 ) )
return 0 ;
return V_207 -> V_224 ( V_11 , V_223 ,
V_221 ) ;
}
static int
F_156 ( const struct V_11 * V_11 ,
unsigned long * V_225 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_226 )
return - V_70 ;
return V_207 -> V_226 ( V_11 , V_225 ) ;
}
static int
F_157 ( const struct V_11 *
V_11 ,
unsigned long *
V_227 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_228 )
return - V_70 ;
return V_207 -> V_228 ( V_11 ,
V_227 ) ;
}
static int
F_158 ( struct V_11 * V_11 ,
T_1 V_229 ,
struct V_220 * V_221 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_230 )
return - V_70 ;
if ( F_154 ( V_221 ) )
return 0 ;
return V_207 -> V_230 ( V_11 , V_229 ,
V_221 ) ;
}
static int
F_159 ( struct V_11 * V_11 ,
const struct V_231 * V_232 ,
struct V_220 * V_221 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_233 )
return - V_70 ;
if ( F_154 ( V_221 ) )
return 0 ;
return V_207 -> V_233 ( V_11 , V_232 ) ;
}
static int
F_160 ( struct V_11 * V_11 ,
const struct V_231 * V_232 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_234 )
return - V_70 ;
return V_207 -> V_234 ( V_11 , V_232 ) ;
}
static int
F_161 ( struct V_11 * V_11 ,
struct V_235 * V_77 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_236 )
return - V_70 ;
return V_207 -> V_236 ( V_11 , V_77 -> V_237 , V_77 -> V_143 ) ;
}
static int
F_162 ( struct V_11 * V_11 ,
struct V_235 * V_77 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_238 )
return - V_70 ;
return V_207 -> V_238 ( V_11 , V_77 -> V_237 , V_77 -> V_143 ) ;
}
static int F_163 ( struct V_11 * V_11 ,
struct V_116 * V_239 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_240 )
return - V_70 ;
return V_207 -> V_240 ( V_11 , V_239 ) ;
}
static int F_164 ( struct V_11 * V_11 ,
struct V_116 * V_239 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_241 )
return - V_70 ;
return V_207 -> V_241 ( V_11 , V_239 ) ;
}
static int F_165 ( struct V_11 * V_11 ,
struct V_242 * V_243 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_244 )
return - V_70 ;
return V_207 -> V_244 ( V_11 , V_243 ) ;
}
static int F_166 ( struct V_11 * V_11 ,
struct V_242 * V_243 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_245 )
return - V_70 ;
return V_207 -> V_245 ( V_11 , V_243 ) ;
}
static int F_108 ( struct V_11 * V_11 ,
const unsigned char * V_143 ,
T_6 V_144 )
{
struct V_204 * V_207 = V_11 -> V_8 -> V_207 ;
if ( ! V_207 -> V_246 )
return - V_70 ;
return V_207 -> V_246 ( V_11 , V_143 , V_144 ) ;
}
static int F_167 ( struct V_8 * V_8 ,
const struct V_247 * V_248 )
{
struct V_204 * V_207 = V_8 -> V_207 ;
if ( ! V_207 -> V_249 )
return 0 ;
return V_207 -> V_249 ( V_8 , V_248 ) ;
}
static int F_168 ( struct V_8 * V_8 ,
const struct V_247 * V_248 )
{
struct V_204 * V_207 = V_8 -> V_207 ;
if ( ! V_207 -> V_250 )
return 0 ;
return V_207 -> V_250 ( V_8 , V_248 ) ;
}
static void F_169 ( struct V_8 * V_8 )
{
struct V_204 * V_207 = V_8 -> V_207 ;
if ( V_207 -> V_251 )
V_207 -> V_251 ( V_8 ) ;
}
static int F_170 ( struct V_116 * V_18 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
int V_30 ;
V_30 = F_86 ( V_11 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_33 ( F_13 ( V_11 ) ,
F_111 , 0 ,
V_47 , V_11 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_25 ) ;
goto V_252;
}
V_30 = F_33 ( F_15 ( V_11 ) ,
F_113 , 0 ,
V_47 , V_11 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_26 ) ;
goto V_253;
}
V_30 = F_151 ( V_11 ) ;
if ( V_30 ) {
F_88 ( V_11 -> V_18 , L_27 ) ;
goto V_254;
}
F_172 ( & V_11 -> V_153 ) ;
F_172 ( & V_11 -> V_154 ) ;
if ( ! V_18 -> V_255 )
F_91 ( V_11 , true ) ;
F_173 ( V_18 ) ;
return 0 ;
V_254:
V_49 ( F_15 ( V_11 ) , V_11 ) ;
V_253:
V_49 ( F_13 ( V_11 ) , V_11 ) ;
V_252:
F_90 ( V_11 ) ;
return V_30 ;
}
static int F_174 ( struct V_116 * V_18 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
F_175 ( V_18 ) ;
F_91 ( V_11 , false ) ;
F_176 ( & V_11 -> V_154 ) ;
F_176 ( & V_11 -> V_153 ) ;
F_152 ( V_11 ) ;
V_49 ( F_15 ( V_11 ) , V_11 ) ;
V_49 ( F_13 ( V_11 ) , V_11 ) ;
F_90 ( V_11 ) ;
return 0 ;
}
static void F_177 ( const struct V_11 * V_11 ,
const struct V_52 * V_53 )
{
const struct V_8 * V_8 = V_11 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_14 ;
const struct V_117 * V_118 [ V_256 + 1 ] ;
struct V_117 * V_189 ;
int V_257 ;
F_83 ( V_118 , V_256 , V_53 ) ;
if ( ! V_118 [ V_258 ] )
return;
F_178 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
const struct V_117 * V_259 [ V_260 + 1 ] ;
T_3 V_22 ;
T_4 V_119 ;
if ( F_179 ( V_189 ) != V_261 )
continue;
F_101 ( V_259 , V_260 ,
V_189 ) ;
if ( ! V_259 [ V_262 ] ||
! V_259 [ V_263 ] )
continue;
V_22 = F_80 ( V_259 [ V_262 ] ) ;
V_119 = F_81 ( V_259 [ V_263 ] ) ;
F_29 ( V_14 , V_22 , V_119 , V_264 ) ;
}
}
static int F_180 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
char * V_23 , T_4 V_108 )
{
const struct V_8 * V_8 = V_11 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_14 ;
T_3 V_22 ;
struct V_117 * V_265 ;
V_22 = F_26 ( V_14 , V_23 , V_108 , V_264 ) ;
if ( F_181 ( F_27 ( V_14 , V_22 ) ) ) {
if ( F_182 () )
F_88 ( V_11 -> V_18 , L_28 ) ;
return - V_19 ;
}
V_265 = F_118 ( V_53 , V_261 ) ;
if ( ! V_265 )
goto V_266;
if ( F_73 ( V_53 , V_262 ,
V_22 ) )
goto V_267;
if ( F_74 ( V_53 , V_263 ,
V_108 ) )
goto V_267;
F_120 ( V_53 , V_265 ) ;
return 0 ;
V_267:
F_183 ( V_53 , V_265 ) ;
V_266:
F_29 ( V_14 , V_22 , V_108 , V_264 ) ;
return - V_68 ;
}
static T_11 F_184 ( struct V_106 * V_107 , struct V_116 * V_18 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
struct V_8 * V_8 = V_11 -> V_8 ;
struct V_52 * V_53 ;
struct V_117 * V_268 ;
int V_26 ;
int V_30 ;
V_53 = F_40 ( & V_11 -> V_123 ) ;
if ( F_181 ( ! V_53 ) ) {
if ( F_182 () )
F_88 ( V_18 , L_29 ) ;
return V_269 ;
}
F_39 ( V_53 , V_107 ) ;
V_268 = F_118 ( V_53 , V_258 ) ;
if ( ! V_268 )
goto V_270;
V_30 = F_180 ( V_11 , V_53 ,
V_107 -> V_91 , F_185 ( V_107 ) ) ;
if ( V_30 )
goto V_267;
if ( F_186 ( V_107 ) -> V_271 > V_272 ) {
V_30 = F_187 ( V_107 ) ;
if ( V_30 )
goto V_273;
}
for ( V_26 = 0 ; V_26 < F_186 ( V_107 ) -> V_271 ; V_26 ++ ) {
const T_12 * V_265 = & F_186 ( V_107 ) -> V_268 [ V_26 ] ;
V_30 = F_180 ( V_11 , V_53 ,
F_188 ( V_265 ) ,
F_189 ( V_265 ) ) ;
if ( V_30 )
goto V_273;
}
F_120 ( V_53 , V_268 ) ;
F_36 ( V_53 ) ;
F_42 ( V_8 , & V_11 -> V_123 , V_53 ) ;
V_53 = F_40 ( & V_11 -> V_123 ) ;
if ( ! V_53 )
F_175 ( V_18 ) ;
return V_274 ;
V_273:
F_177 ( V_11 , V_53 ) ;
V_267:
F_183 ( V_53 , V_268 ) ;
V_270:
F_190 ( V_107 ) ;
V_18 -> V_275 . V_276 ++ ;
return V_274 ;
}
static int F_191 ( struct V_116 * V_18 , void * V_277 )
{
struct V_278 * V_143 = V_277 ;
struct V_11 * V_11 = F_171 ( V_18 ) ;
int V_30 ;
if ( ! F_192 ( V_143 -> V_279 ) )
return - V_280 ;
V_30 = F_140 ( V_11 , V_143 -> V_279 ) ;
if ( V_30 )
return V_30 ;
memcpy ( V_18 -> V_281 , V_143 -> V_279 , V_18 -> V_282 ) ;
return 0 ;
}
static int F_193 ( struct V_116 * V_18 , int V_283 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
int V_284 = F_194 ( V_18 ) ;
int V_30 ;
if ( V_284 )
F_174 ( V_18 ) ;
F_97 ( V_18 , L_30 , V_18 -> V_112 , V_283 ) ;
V_18 -> V_112 = V_283 ;
V_30 = F_141 ( V_11 , V_283 ) ;
if ( V_30 )
return V_30 ;
if ( V_284 )
V_30 = F_170 ( V_18 ) ;
return V_30 ;
}
static int F_195 ( struct V_116 * V_18 ,
char * V_23 , T_4 V_119 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
struct V_194 V_195 = { . V_23 = V_23 , . V_119 = V_119 } ;
int V_30 ;
V_30 = F_114 ( V_11 , false ,
F_117 , NULL ,
F_128 ,
& V_195 ) ;
return V_30 ? - V_70 : 0 ;
}
static int F_196 ( struct V_116 * V_18 ,
bool V_255 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
if ( V_11 -> V_18 -> V_285 & V_286 )
F_91 ( V_11 , ! V_255 ) ;
V_11 -> V_18 -> V_255 = V_255 ;
return 0 ;
}
static void F_197 ( struct V_116 * V_18 ,
struct V_242 * V_243 )
{
struct V_11 * V_11 = F_171 ( V_243 -> V_18 ) ;
int V_30 ;
V_30 = F_166 ( V_11 , V_243 ) ;
if ( V_30 )
F_198 ( V_11 -> V_18 , L_31 ,
V_30 ) ;
}
static int F_199 ( struct V_116 * V_18 ,
struct V_287 * V_189 )
{
const struct V_11 * V_11 = F_171 ( V_18 ) ;
const struct V_8 * V_8 = V_11 -> V_8 ;
int V_30 = 0 ;
switch ( V_189 -> V_288 ) {
case V_289 :
V_189 -> V_290 . V_291 . V_292 = sizeof( V_8 -> V_293 . V_288 ) ;
memcpy ( & V_189 -> V_290 . V_291 . V_288 , & V_8 -> V_293 . V_288 , V_189 -> V_290 . V_291 . V_292 ) ;
break;
case V_294 :
V_30 = F_156 ( V_11 ,
& V_189 -> V_290 . V_223 ) ;
break;
case V_295 :
V_30 = F_157 ( V_11 ,
& V_189 -> V_290 . V_296 ) ;
break;
default:
return - V_70 ;
}
return V_30 ;
}
static int F_200 ( struct V_116 * V_18 ,
const struct V_287 * V_189 ,
struct V_220 * V_221 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
int V_30 = 0 ;
switch ( V_189 -> V_288 ) {
case V_297 :
V_30 = F_153 ( V_11 ,
V_189 -> V_290 . V_298 ,
V_221 ) ;
break;
case V_294 :
V_30 = F_155 ( V_11 ,
V_189 -> V_290 . V_223 ,
V_221 ) ;
break;
case V_299 :
V_30 = F_158 ( V_11 ,
V_189 -> V_290 . V_229 ,
V_221 ) ;
break;
default:
V_30 = - V_70 ;
break;
}
return V_30 ;
}
static int F_201 ( struct V_116 * V_18 ,
const struct V_300 * V_301 ,
struct V_220 * V_221 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
int V_30 = 0 ;
switch ( V_301 -> V_288 ) {
case V_302 :
V_30 = F_159 ( V_11 ,
F_202 ( V_301 ) ,
V_221 ) ;
break;
default:
V_30 = - V_70 ;
break;
}
return V_30 ;
}
static int F_203 ( struct V_116 * V_18 ,
const struct V_300 * V_301 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
int V_30 = 0 ;
switch ( V_301 -> V_288 ) {
case V_302 :
V_30 = F_160 ( V_11 ,
F_202 ( V_301 ) ) ;
break;
default:
V_30 = - V_70 ;
break;
}
return V_30 ;
}
static void F_204 ( struct V_303 * V_304 )
{
struct V_305 * V_306 =
F_205 ( V_304 , struct V_305 , V_304 ) ;
struct V_8 * V_8 = V_306 -> V_8 ;
struct V_307 * V_308 ;
int V_30 ;
F_206 () ;
switch ( V_306 -> V_309 ) {
case V_310 :
V_30 = F_167 ( V_8 , & V_306 -> V_248 ) ;
if ( V_30 )
F_169 ( V_8 ) ;
F_207 ( V_306 -> V_248 . V_311 ) ;
break;
case V_312 :
F_168 ( V_8 , & V_306 -> V_248 ) ;
F_207 ( V_306 -> V_248 . V_311 ) ;
break;
case V_313 :
case V_314 :
V_308 = V_306 -> V_315 . V_308 ;
if ( ! F_208 ( V_308 ) )
F_169 ( V_8 ) ;
F_209 ( V_308 ) ;
break;
}
F_210 () ;
F_7 ( V_306 ) ;
}
static int F_211 ( struct V_316 * V_317 ,
unsigned long V_309 , void * V_75 )
{
struct V_8 * V_8 = F_205 ( V_317 , struct V_8 , V_318 ) ;
struct V_305 * V_306 ;
V_306 = F_5 ( sizeof( * V_306 ) , V_319 ) ;
if ( F_212 ( ! V_306 ) )
return V_320 ;
F_213 ( & V_306 -> V_304 , F_204 ) ;
V_306 -> V_8 = V_8 ;
V_306 -> V_309 = V_309 ;
switch ( V_309 ) {
case V_310 :
case V_312 :
memcpy ( & V_306 -> V_248 , V_75 , sizeof( V_306 -> V_248 ) ) ;
F_214 ( V_306 -> V_248 . V_311 ) ;
break;
case V_313 :
case V_314 :
memcpy ( & V_306 -> V_315 , V_75 , sizeof( V_306 -> V_315 ) ) ;
F_215 ( V_306 -> V_315 . V_308 ) ;
break;
}
F_216 ( V_8 -> V_321 , & V_306 -> V_304 ) ;
return V_322 ;
}
static int
F_217 ( struct V_116 * V_18 ,
struct V_167 * V_168 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
return F_136 ( V_11 , V_168 ) ;
}
static int
F_218 ( struct V_116 * V_18 ,
const struct V_167 * V_168 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
return F_139 ( V_11 , V_168 ) ;
}
static void F_219 ( struct V_116 * V_18 ,
struct V_323 * V_324 )
{
F_220 ( V_324 -> V_325 , V_47 , sizeof( V_324 -> V_325 ) ) ;
F_220 ( V_324 -> V_326 , V_327 , sizeof( V_324 -> V_326 ) ) ;
}
static void F_221 ( struct V_116 * V_328 , T_1 V_329 ,
T_10 * V_91 )
{
T_10 * V_277 = V_91 ;
int V_26 ;
switch ( V_329 ) {
case V_330 :
for ( V_26 = 0 ; V_26 < F_222 ( V_331 ) ; V_26 ++ ) {
memcpy ( V_277 , V_331 [ V_26 ] . V_197 , V_332 ) ;
V_277 += V_332 ;
}
break;
}
}
static int
F_223 ( const struct V_11 * V_11 ,
struct V_52 * V_53 ,
void * V_161 )
{
struct V_117 * V_333 ;
if ( F_74 ( V_53 , V_163 ,
V_334 ) )
return - V_68 ;
V_333 = F_118 ( V_53 , V_165 ) ;
if ( ! V_333 )
return - V_68 ;
if ( F_119 ( V_53 , V_335 ,
V_11 -> V_135 ) )
return - V_68 ;
F_120 ( V_53 , V_333 ) ;
return 0 ;
}
static int
F_224 ( const struct V_11 * V_11 ,
const struct V_52 * V_53 ,
void * V_161 )
{
const struct V_117 * V_118 [ V_169 + 1 ] ;
const struct V_117 * V_336 [ V_337 + 1 ] ;
const struct V_117 * V_338 ;
T_1 V_135 ;
T_2 * V_91 = V_161 ;
int V_26 ;
F_83 ( V_118 , V_169 , V_53 ) ;
if ( ! V_118 [ V_165 ] )
return - V_19 ;
F_101 ( V_336 , V_337 ,
V_118 [ V_165 ] ) ;
if ( ! V_336 [ V_335 ] )
return - V_19 ;
V_135 = F_102 ( V_336 [ V_335 ] ) ;
if ( V_135 != V_11 -> V_135 )
return - V_19 ;
for ( V_26 = 0 ; V_26 < F_222 ( V_331 ) ; V_26 ++ ) {
V_338 = V_336 [ V_331 [ V_26 ] . type ] ;
if ( ! V_338 )
continue;
V_91 [ V_26 ] = F_80 ( V_338 ) ;
}
return 0 ;
}
static int F_225 ( struct V_11 * V_11 ,
void * V_161 )
{
return F_114 ( V_11 , false ,
F_223 , NULL ,
F_224 ,
V_161 ) ;
}
static void F_226 ( struct V_116 * V_18 ,
struct V_339 * V_275 , T_2 * V_91 )
{
struct V_11 * V_11 = F_171 ( V_18 ) ;
if ( F_225 ( V_11 , V_91 ) != 0 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < F_222 ( V_331 ) ; ++ V_26 )
V_91 [ V_26 ] = 0 ;
}
}
static int F_227 ( struct V_116 * V_328 , int V_340 )
{
switch ( V_340 ) {
case V_330 :
return V_341 ;
default:
return - V_70 ;
}
}
static struct V_11 * F_228 ( struct V_342 * V_343 )
{
return F_205 ( V_343 , struct V_11 , V_153 ) ;
}
static int F_229 ( struct V_342 * V_343 , int V_344 )
{
struct V_11 * V_11 = F_228 ( V_343 ) ;
const struct V_8 * V_8 = V_11 -> V_8 ;
const struct V_52 * V_53 ;
T_1 V_83 = 0 ;
int V_30 ;
while ( ( V_53 = F_45 ( & V_11 -> V_123 ) ) ) {
struct V_106 * V_107 ;
V_30 = F_35 ( V_53 ) ;
if ( V_30 && F_182 () )
F_88 ( V_11 -> V_18 , L_32 ,
V_30 ) ;
F_177 ( V_11 , V_53 ) ;
V_107 = F_38 ( V_53 ) ;
if ( V_30 == 0 ) {
V_11 -> V_18 -> V_275 . V_345 ++ ;
V_11 -> V_18 -> V_275 . V_346 += V_107 -> V_119 ;
} else {
V_11 -> V_18 -> V_275 . V_347 ++ ;
}
F_78 ( V_107 ) ;
V_83 ++ ;
}
if ( V_83 && F_230 ( V_11 -> V_18 ) )
F_231 ( V_11 -> V_18 ) ;
F_232 ( V_343 ) ;
F_46 ( V_8 , & V_11 -> V_123 , V_83 ) ;
return 0 ;
}
static int F_233 ( const struct V_8 * V_8 ,
const struct V_11 * V_11 ,
struct V_52 * V_53 )
{
const struct V_117 * V_118 [ V_120 + 1 ] ;
struct V_106 * V_107 = F_38 ( V_53 ) ;
T_4 V_348 ;
T_7 V_349 = 0 ;
if ( ! V_107 )
return - V_59 ;
F_83 ( V_118 , V_120 , V_53 ) ;
if ( ! V_118 [ V_350 ] )
return - V_66 ;
if ( V_118 [ V_351 ] )
V_349 = F_81 ( V_118 [ V_351 ] ) ;
F_79 ( V_8 , V_118 ) ;
V_348 = F_81 ( V_118 [ V_350 ] ) ;
F_234 ( V_107 , V_348 ) ;
V_107 -> V_352 = F_235 ( V_107 , V_11 -> V_18 ) ;
if ( V_349 & V_353 )
V_107 -> V_354 = 1 ;
V_11 -> V_18 -> V_275 . V_355 ++ ;
V_11 -> V_18 -> V_275 . V_356 += V_107 -> V_119 ;
F_236 ( V_107 ) ;
return F_76 ( V_11 , V_53 ) ;
}
static struct V_11 * F_237 ( struct V_342 * V_343 )
{
return F_205 ( V_343 , struct V_11 , V_154 ) ;
}
static int F_238 ( struct V_342 * V_343 , int V_344 )
{
struct V_11 * V_11 = F_237 ( V_343 ) ;
const struct V_8 * V_8 = V_11 -> V_8 ;
struct V_52 * V_53 ;
T_1 V_83 = 0 ;
int V_30 ;
while ( V_83 < V_344 &&
( V_53 = F_45 ( & V_11 -> V_121 ) ) ) {
V_30 = F_35 ( V_53 ) ;
if ( V_30 ) {
if ( F_182 () )
F_88 ( V_11 -> V_18 , L_33 ,
V_30 ) ;
} else {
V_30 = F_233 ( V_8 , V_11 ,
V_53 ) ;
if ( V_30 && F_182 () )
F_88 ( V_11 -> V_18 , L_34 ,
V_30 ) ;
}
if ( V_30 )
V_11 -> V_18 -> V_275 . V_357 ++ ;
F_36 ( V_53 ) ;
F_42 ( V_8 , & V_11 -> V_121 , V_53 ) ;
V_83 ++ ;
}
if ( V_83 < V_344 )
F_239 ( V_343 , V_83 ) ;
F_46 ( V_8 , & V_11 -> V_121 , V_83 ) ;
return V_83 ;
}
static void F_240 ( const struct V_11 * V_11 )
{
const struct V_8 * V_8 = V_11 -> V_8 ;
T_2 V_358 = F_23 ( V_8 , V_359 ) ;
bool V_137 ;
V_137 = V_358 & ( 1 << V_11 -> V_135 ) ;
if ( V_137 )
F_96 ( V_11 -> V_18 ) ;
else
F_99 ( V_11 -> V_18 ) ;
}
static void F_241 ( struct V_8 * V_8 )
{
struct V_11 * V_11 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_8 -> V_140 ; V_26 ++ ) {
V_11 = V_8 -> V_141 [ V_26 ] ;
if ( ! V_11 )
continue;
F_149 ( V_11 ) ;
F_242 ( V_11 -> V_18 ) ;
F_150 ( V_11 ) ;
F_243 ( V_11 -> V_18 ) ;
}
F_145 ( V_8 ) ;
F_7 ( V_8 -> V_141 ) ;
}
static void F_244 ( struct V_11 * V_11 )
{
const struct V_8 * V_8 = V_11 -> V_8 ;
const struct V_13 * V_14 = V_8 -> V_14 ;
int V_30 ;
V_30 = F_137 ( V_11 ,
V_11 -> V_18 -> V_281 ) ;
if ( V_30 ) {
F_245 ( & V_14 -> V_18 , L_35 ) ;
F_246 ( V_11 -> V_18 ) ;
}
}
static int F_247 ( struct V_8 * V_8 , unsigned int V_12 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
struct V_11 * V_11 ;
struct V_116 * V_18 ;
int V_30 ;
V_18 = F_248 ( sizeof( struct V_11 ) ) ;
if ( ! V_18 )
return - V_33 ;
F_249 ( V_18 , & V_14 -> V_18 ) ;
V_11 = F_171 ( V_18 ) ;
V_11 -> V_18 = V_18 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_135 = V_12 + 1 ;
V_30 = F_146 ( V_11 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_36 ) ;
goto V_360;
}
F_244 ( V_11 ) ;
V_18 -> V_361 = & V_362 ;
V_18 -> V_363 = & V_364 ;
V_18 -> V_365 = & V_366 ;
F_250 ( V_18 , & V_11 -> V_153 , F_229 ,
V_367 ) ;
F_251 ( V_18 , & V_11 -> V_154 , F_238 ,
V_367 ) ;
F_240 ( V_11 ) ;
V_18 -> V_368 |= V_369 | V_370 ;
V_18 -> V_371 = V_372 ;
V_18 -> V_373 = V_374 ;
V_30 = F_147 ( V_11 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_37 ) ;
goto V_375;
}
V_30 = F_252 ( V_18 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_38 ) ;
goto V_376;
}
V_8 -> V_141 [ V_12 ] = V_11 ;
V_30 = F_148 ( V_11 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_39 ) ;
goto V_377;
}
return 0 ;
V_377:
V_8 -> V_141 [ V_12 ] = NULL ;
F_242 ( V_18 ) ;
V_376:
F_150 ( V_11 ) ;
V_375:
V_360:
F_243 ( V_18 ) ;
return V_30 ;
}
static int F_253 ( struct V_8 * V_8 )
{
int V_26 ;
T_4 V_378 ;
int V_30 ;
V_378 = sizeof( struct V_11 * ) * V_8 -> V_140 ;
V_8 -> V_141 = F_5 ( V_378 , V_5 ) ;
if ( ! V_8 -> V_141 )
return - V_33 ;
for ( V_26 = 0 ; V_26 < V_8 -> V_140 ; V_26 ++ ) {
V_30 = F_247 ( V_8 , V_26 ) ;
if ( V_30 )
goto V_379;
}
return 0 ;
V_379:
F_241 ( V_8 ) ;
return V_30 ;
}
static int F_254 ( struct V_8 * V_8 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
int V_10 ;
int V_26 ;
int V_30 ;
V_10 = F_255 ( V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 != F_256 ( V_8 -> V_140 ) )
return - V_66 ;
V_8 -> V_10 = F_257 ( V_10 ,
sizeof( struct V_380 ) ,
V_5 ) ;
if ( ! V_8 -> V_10 )
return - V_33 ;
for ( V_26 = 0 ; V_26 < V_10 ; V_26 ++ )
V_8 -> V_10 [ V_26 ] . V_381 = V_26 ;
V_30 = F_258 ( V_14 , V_8 -> V_10 , V_10 ) ;
if ( V_30 < 0 )
goto V_382;
return 0 ;
V_382:
F_7 ( V_8 -> V_10 ) ;
return V_30 ;
}
static void F_259 ( const struct V_8 * V_8 )
{
F_260 ( V_8 -> V_14 ) ;
F_7 ( V_8 -> V_10 ) ;
}
static bool F_261 ( const struct V_116 * V_18 )
{
return V_18 -> V_361 == & V_362 ;
}
static void
F_262 ( struct V_11 * V_11 ,
struct V_235 * V_383 )
{
struct V_235 V_77 ;
V_77 . V_143 = V_383 -> V_143 ;
V_77 . V_237 = V_383 -> V_237 ;
F_263 ( V_384 ,
V_11 -> V_18 , & V_77 . V_77 ) ;
}
static void F_264 ( struct V_303 * V_304 )
{
struct F_264 * V_385 =
F_205 ( V_304 , struct F_264 , V_304 ) ;
struct V_11 * V_11 = V_385 -> V_11 ;
struct V_235 * V_386 ;
int V_30 ;
F_206 () ;
switch ( V_385 -> V_309 ) {
case V_387 :
V_386 = & V_385 -> V_386 ;
V_30 = F_161 ( V_11 , V_386 ) ;
if ( V_30 ) {
F_265 ( V_11 -> V_18 , L_40 , V_30 ) ;
break;
}
F_262 ( V_11 , V_386 ) ;
break;
case V_388 :
V_386 = & V_385 -> V_386 ;
V_30 = F_162 ( V_11 , V_386 ) ;
if ( V_30 )
F_265 ( V_11 -> V_18 , L_40 , V_30 ) ;
break;
}
F_210 () ;
F_7 ( V_385 -> V_386 . V_143 ) ;
F_7 ( V_385 ) ;
F_266 ( V_11 -> V_18 ) ;
}
static int F_267 ( struct V_316 * V_389 ,
unsigned long V_309 , void * V_75 )
{
struct V_116 * V_18 = F_268 ( V_75 ) ;
struct F_264 * V_385 ;
struct V_235 * V_386 = V_75 ;
struct V_11 * V_11 ;
if ( ! F_261 ( V_18 ) )
return V_322 ;
V_11 = F_171 ( V_18 ) ;
V_385 = F_5 ( sizeof( * V_385 ) , V_319 ) ;
if ( F_212 ( ! V_385 ) )
return V_320 ;
F_213 ( & V_385 -> V_304 , F_264 ) ;
V_385 -> V_11 = V_11 ;
V_385 -> V_309 = V_309 ;
switch ( V_309 ) {
case V_387 :
case V_388 :
memcpy ( & V_385 -> V_386 , V_75 ,
sizeof( V_385 -> V_386 ) ) ;
V_385 -> V_386 . V_143 = F_5 ( V_191 , V_319 ) ;
F_126 ( ( T_10 * ) V_385 -> V_386 . V_143 ,
V_386 -> V_143 ) ;
F_269 ( V_18 ) ;
break;
default:
F_7 ( V_385 ) ;
return V_322 ;
}
F_216 ( V_11 -> V_8 -> V_321 ,
& V_385 -> V_304 ) ;
return V_322 ;
}
static int F_270 ( struct V_13 * V_14 , const struct V_390 * V_288 )
{
struct V_8 * V_8 ;
int V_30 ;
V_8 = F_5 ( sizeof( * V_8 ) , V_5 ) ;
if ( ! V_8 )
return - V_33 ;
V_30 = F_271 ( V_14 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_41 ) ;
goto V_391;
}
V_30 = F_272 ( V_14 , V_47 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_42 ) ;
goto V_392;
}
V_30 = F_273 ( V_14 , F_274 ( 64 ) ) ;
if ( ! V_30 ) {
V_30 = F_275 ( V_14 , F_274 ( 64 ) ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_43 ) ;
goto V_393;
}
} else {
V_30 = F_273 ( V_14 , F_274 ( 32 ) ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_44 ) ;
goto V_393;
}
}
if ( F_276 ( V_14 , 0 ) < V_394 ) {
F_21 ( & V_14 -> V_18 , L_45 ) ;
V_30 = - V_66 ;
goto V_395;
}
V_8 -> V_396 = F_277 ( F_278 ( V_14 , 0 ) ,
F_276 ( V_14 , 0 ) ) ;
if ( ! V_8 -> V_396 ) {
F_21 ( & V_14 -> V_18 , L_46 ) ;
V_30 = - V_19 ;
goto V_397;
}
F_279 ( V_14 ) ;
V_8 -> V_14 = V_14 ;
F_280 ( V_14 , V_8 ) ;
V_8 -> V_140 = F_20 ( V_8 , V_398 ) ;
V_30 = F_254 ( V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_47 ) ;
goto V_399;
}
V_30 = F_32 ( V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_48 ) ;
goto V_400;
}
F_19 ( V_8 , V_401 , V_402 ) ;
V_30 = F_69 ( V_8 ) ;
if ( V_30 )
goto V_403;
V_30 = F_33 ( F_12 ( V_8 , V_404 ) ,
F_92 , 0 ,
V_47 , V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_49 ) ;
goto V_405;
}
V_30 = F_33 ( F_12 ( V_8 , V_406 ) ,
F_110 , 0 ,
V_47 , V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_50 ) ;
goto V_407;
}
V_8 -> V_321 = F_281 ( V_47 ,
V_408 ) ;
if ( ! V_8 -> V_321 ) {
V_30 = - V_33 ;
goto V_409;
}
V_8 -> V_318 . V_410 = F_211 ;
V_30 = F_282 ( & V_8 -> V_318 , NULL ) ;
if ( V_30 )
goto V_411;
V_30 = F_283 ( & V_412 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_51 ) ;
goto V_413;
}
V_8 -> V_293 . V_288 = F_23 ( V_8 , V_414 ) ;
V_30 = F_253 ( V_8 ) ;
if ( V_30 ) {
F_21 ( & V_14 -> V_18 , L_52 ) ;
goto V_415;
}
F_284 ( & V_14 -> V_18 , L_53 ,
( int ) sizeof( V_8 -> V_293 . V_288 ) , & V_8 -> V_293 . V_288 ) ;
return 0 ;
V_415:
F_285 ( & V_412 ) ;
V_413:
F_286 ( & V_8 -> V_318 ) ;
V_411:
F_287 ( V_8 -> V_321 ) ;
V_409:
V_49 ( F_12 ( V_8 , V_406 ) , V_8 ) ;
V_407:
V_49 ( F_12 ( V_8 , V_404 ) , V_8 ) ;
V_405:
F_71 ( V_8 ) ;
V_403:
V_400:
F_259 ( V_8 ) ;
V_399:
F_288 ( V_8 -> V_396 ) ;
V_397:
V_395:
V_393:
F_289 ( V_14 ) ;
V_392:
F_290 ( V_14 ) ;
V_391:
F_7 ( V_8 ) ;
return V_30 ;
}
static void F_291 ( struct V_13 * V_14 )
{
struct V_8 * V_8 = F_292 ( V_14 ) ;
F_241 ( V_8 ) ;
F_285 ( & V_412 ) ;
F_286 ( & V_8 -> V_318 ) ;
F_19 ( V_8 , V_401 , V_402 ) ;
F_287 ( V_8 -> V_321 ) ;
V_49 ( F_12 ( V_8 , V_406 ) , V_8 ) ;
V_49 ( F_12 ( V_8 , V_404 ) , V_8 ) ;
F_71 ( V_8 ) ;
F_259 ( V_8 ) ;
F_288 ( V_8 -> V_396 ) ;
F_289 ( V_8 -> V_14 ) ;
F_290 ( V_8 -> V_14 ) ;
F_7 ( V_8 ) ;
}
static bool F_293 ( const struct V_116 * V_18 ,
struct V_8 * V_8 )
{
struct V_11 * V_11 ;
if ( ! F_261 ( V_18 ) )
return false ;
V_11 = F_171 ( V_18 ) ;
if ( V_11 -> V_8 != V_8 )
return false ;
return true ;
}
static int F_294 ( struct V_116 * V_416 , void * V_417 )
{
struct V_418 * V_91 = V_417 ;
int V_419 = 0 ;
if ( F_293 ( V_416 , V_91 -> V_8 ) ) {
V_91 -> V_182 = F_171 ( V_416 ) ;
V_419 = 1 ;
}
return V_419 ;
}
struct V_11 * F_295 ( struct V_116 * V_18 ,
struct V_8 * V_8 )
{
struct V_418 V_91 ;
if ( F_293 ( V_18 , V_8 ) )
return F_171 ( V_18 ) ;
V_91 . V_8 = V_8 ;
V_91 . V_182 = NULL ;
F_296 ( V_18 , F_294 , & V_91 ) ;
return V_91 . V_182 ;
}
static int F_297 ( struct V_316 * V_389 ,
unsigned long V_309 , void * V_75 )
{
struct V_116 * V_18 = F_298 ( V_75 ) ;
struct V_420 * V_77 ;
struct V_11 * V_11 ;
int V_30 ;
if ( ! F_261 ( V_18 ) )
return V_322 ;
switch ( V_309 ) {
case V_421 :
V_77 = V_75 ;
if ( ! V_77 -> V_239 )
goto V_270;
V_11 = F_171 ( V_18 ) ;
if ( V_77 -> V_422 ) {
V_30 = F_163 ( V_11 ,
V_77 -> V_423 ) ;
if ( V_30 )
F_198 ( V_18 , L_54 ,
V_30 ) ;
} else {
V_30 = F_164 ( V_11 ,
V_77 -> V_423 ) ;
if ( V_30 )
F_198 ( V_18 , L_55 ,
V_30 ) ;
}
}
V_270:
return V_322 ;
}
static int F_299 ( struct V_316 * V_389 ,
unsigned long V_309 , void * V_75 )
{
struct V_11 * V_11 ;
struct V_116 * V_18 ;
struct V_242 * V_243 = V_75 ;
int V_30 ;
switch ( V_309 ) {
case V_424 :
if ( V_243 -> V_425 != & V_426 )
return V_322 ;
V_18 = V_243 -> V_18 ;
if ( ! F_261 ( V_18 ) )
return V_322 ;
V_11 = F_171 ( V_18 ) ;
V_30 = F_165 ( V_11 , V_243 ) ;
if ( V_30 )
F_198 ( V_18 , L_56 ,
V_30 ) ;
break;
}
return V_322 ;
}
static int T_13 F_300 ( void )
{
int V_30 ;
F_301 ( & V_427 ) ;
F_302 ( & V_428 ) ;
V_30 = F_303 ( & V_429 ) ;
if ( V_30 )
goto V_430;
return 0 ;
V_430:
F_304 ( & V_428 ) ;
F_305 ( & V_427 ) ;
return V_30 ;
}
static void T_14 F_306 ( void )
{
F_304 ( & V_428 ) ;
F_305 ( & V_427 ) ;
F_307 ( & V_429 ) ;
}
