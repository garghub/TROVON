static bool F_1 ( T_1 V_1 )
{
T_2 V_2 = V_3 ;
T_2 V_4 = 0xffe ;
T_2 V_5 = F_2 ( V_1 ) ;
return ( V_5 >= V_2 && V_5 <= V_4 ) ;
}
static T_1 F_3 ( const struct V_6 * V_6 ,
T_2 V_7 , bool * V_8 )
{
T_1 V_1 ;
if ( V_8 )
* V_8 = false ;
V_1 = F_4 ( V_7 ) ;
if ( ! V_1 ) {
V_1 = V_6 -> V_9 ;
if ( V_8 )
* V_8 = true ;
}
return V_1 ;
}
static T_2 F_5 ( const struct V_6 * V_6 ,
T_1 V_1 )
{
if ( F_1 ( V_1 ) )
return 0 ;
return F_2 ( V_1 ) ;
}
static bool F_6 ( const struct V_6 * V_6 )
{
return V_6 -> V_10 &&
F_7 ( V_6 -> V_10 ) ;
}
static bool F_8 ( const struct V_6 * V_6 )
{
return V_6 -> V_10 &&
F_9 ( V_6 -> V_10 ) ;
}
static void * F_10 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_3 V_14 )
{
struct V_15 * V_16 = NULL ;
T_4 V_17 = ( V_13 & V_18 ) ?
V_19 : V_20 ;
switch ( V_12 ) {
case V_21 :
V_16 = F_11 ( V_14 + sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
F_12 ( V_16 , & V_6 -> V_22 ) ;
break;
case V_23 :
F_13 ( F_14 ( & V_6 -> V_22 ) ) ;
V_16 = V_6 -> V_22 . V_24 ;
F_15 ( V_16 ) ;
break;
case V_25 :
V_16 = F_11 ( V_14 + sizeof( * V_16 ) , V_17 ) ;
if ( V_16 )
F_16 ( V_16 ) ;
break;
default:
break;
}
return V_16 ? V_16 + 1 : NULL ;
}
static void * F_17 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_3 V_14 )
{
return F_10 ( V_6 , V_12 , V_13 , V_14 ) ;
}
static void * F_18 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_3 V_26 , T_3 V_14 )
{
return F_10 ( V_6 , V_12 , V_13 , V_26 * V_14 ) ;
}
static void F_19 ( enum V_11 V_12 , const void * V_27 )
{
struct V_15 * V_16 ;
if ( V_12 == V_21 )
return;
V_16 = (struct V_15 * ) V_27 - 1 ;
F_13 ( ! F_14 ( V_16 ) ) ;
F_20 ( V_16 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
V_29 -> V_30 = false ;
V_29 -> V_31 = false ;
}
static void F_22 ( struct V_28 * V_29 )
{
F_23 ( & V_29 -> V_29 ) ;
F_21 ( V_29 ) ;
}
static struct V_28 * F_24 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 )
{
struct V_28 * V_29 ;
V_29 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return NULL ;
F_22 ( V_29 ) ;
return V_29 ;
}
static void F_25 ( enum V_11 V_12 ,
struct V_28 * V_29 )
{
F_19 ( V_12 , V_29 ) ;
}
static bool F_26 ( struct V_28 * V_29 ,
unsigned long V_32 )
{
F_27 ( V_29 -> V_29 , V_29 -> V_30 , V_33 / 10 ) ;
if ( ! V_29 -> V_30 )
return false ;
return true ;
}
static void F_28 ( struct V_28 * V_29 )
{
V_29 -> V_30 = true ;
F_29 ( & V_29 -> V_29 ) ;
}
static T_5 F_30 ( const struct V_34 * V_34 , unsigned int V_35 )
{
return V_34 -> V_36 [ V_35 ] . V_35 ;
}
static T_5 F_31 ( const struct V_6 * V_6 )
{
return F_30 ( V_6 -> V_34 ,
F_32 ( V_6 -> V_37 ) ) ;
}
static T_5 F_33 ( const struct V_6 * V_6 )
{
return F_30 ( V_6 -> V_34 ,
F_34 ( V_6 -> V_37 ) ) ;
}
static int F_35 ( const struct V_34 * V_34 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
T_6 V_40 ;
T_6 V_41 ;
V_41 = F_36 () ;
V_41 >>= 1 ;
F_37 ( V_34 , V_42 , V_41 ) ;
V_40 = F_38 ( V_34 , V_42 ) ;
if ( V_40 != V_41 * 2 ) {
F_39 ( & V_39 -> V_43 , L_1 ,
V_40 , V_41 * 2 ) ;
return - V_44 ;
}
V_41 = F_36 () ;
V_41 <<= 31 ;
V_41 |= F_36 () ;
F_40 ( V_34 , V_45 , V_41 ) ;
V_40 = F_41 ( V_34 , V_45 ) ;
if ( V_40 != V_41 * 2 ) {
F_39 ( & V_39 -> V_43 , L_2 ,
V_40 , V_41 * 2 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_42 ( const struct V_34 * V_34 ,
struct V_28 * V_29 , T_5 V_46 ,
T_7 V_47 , const unsigned char * V_48 ,
const unsigned char * V_49 , T_3 V_14 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
int V_50 ;
F_21 ( V_29 ) ;
F_37 ( V_34 , V_51 , V_46 ) ;
if ( ! F_26 ( V_29 , V_33 / 10 ) ) {
F_39 ( & V_39 -> V_43 , L_3 ) ;
return - V_44 ;
}
for ( V_50 = 0 ; V_50 < V_14 ; V_50 ++ ) {
if ( V_48 [ V_50 ] != V_49 [ V_50 ] ) {
F_39 ( & V_39 -> V_43 , L_4 ,
V_48 [ V_50 ] , V_50 , V_49 [ V_50 ] ) ;
return - V_44 ;
}
}
return 0 ;
}
static int F_43 ( const struct V_34 * V_34 ,
struct V_28 * V_29 , int V_52 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
unsigned char * V_53 ;
unsigned char * V_48 ;
unsigned char * V_49 ;
T_7 V_47 ;
int V_50 ;
int V_54 ;
V_53 = F_11 ( V_55 * 2 + V_52 ,
V_20 | V_56 ) ;
if ( ! V_53 )
return - V_57 ;
V_48 = V_53 + V_52 ;
V_49 = V_48 + V_55 ;
V_47 = F_44 ( V_39 , V_48 , V_55 ,
V_58 ) ;
if ( F_45 ( V_39 , V_47 ) ) {
V_54 = - V_44 ;
goto V_59;
}
F_40 ( V_34 , V_60 , V_47 ) ;
F_37 ( V_34 , V_61 , V_55 ) ;
memset ( V_49 , V_62 , V_55 ) ;
V_54 = F_42 ( V_34 , V_29 , V_63 ,
V_47 , V_48 , V_49 ,
V_55 ) ;
if ( V_54 )
goto V_64;
memset ( V_49 , 0 , V_55 ) ;
V_54 = F_42 ( V_34 , V_29 , V_65 ,
V_47 , V_48 , V_49 ,
V_55 ) ;
if ( V_54 )
goto V_64;
F_46 ( V_48 , V_55 ) ;
for ( V_50 = 0 ; V_50 < V_55 ; V_50 ++ )
V_49 [ V_50 ] = ~ V_48 [ V_50 ] ;
V_54 = F_42 ( V_34 , V_29 , V_66 ,
V_47 , V_48 , V_49 ,
V_55 ) ;
if ( V_54 )
goto V_64;
V_64:
F_47 ( V_39 , V_47 , V_55 ,
V_58 ) ;
V_59:
F_20 ( V_53 ) ;
return V_54 ;
}
static int F_48 ( const struct V_34 * V_34 ,
struct V_28 * V_29 )
{
int V_50 ;
int V_54 ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
V_54 = F_43 ( V_34 , V_29 , V_50 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static T_8 F_49 ( int V_67 , void * V_68 )
{
struct V_28 * V_29 = V_68 ;
F_28 ( V_29 ) ;
return V_69 ;
}
static int F_50 ( const struct V_34 * V_34 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
struct V_28 V_29 ;
int V_54 ;
V_54 = F_35 ( V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_5 ) ;
return V_54 ;
}
V_54 = F_51 ( F_30 ( V_34 , V_70 ) ,
F_49 , 0 ,
V_71 , & V_29 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_6 ) ;
return V_54 ;
}
F_22 ( & V_29 ) ;
F_37 ( V_34 , V_72 , V_70 ) ;
if ( ! F_26 ( & V_29 , V_33 / 10 ) ) {
F_39 ( & V_39 -> V_43 , L_3 ) ;
V_54 = - V_44 ;
goto V_73;
}
V_54 = F_48 ( V_34 , & V_29 ) ;
if ( V_54 )
F_39 ( & V_39 -> V_43 , L_7 ) ;
V_73:
V_73 ( F_30 ( V_34 , V_70 ) , & V_29 ) ;
return V_54 ;
}
static struct V_74 * F_52 ( const struct V_74 * V_75 ,
int * V_76 )
{
int V_77 = F_53 ( V_75 -> V_78 ) ;
* V_76 -= V_77 ;
return (struct V_74 * ) ( ( char * ) V_75 + V_77 ) ;
}
static int F_54 ( const struct V_74 * V_75 , int V_76 )
{
return V_76 >= ( int ) V_79 &&
V_75 -> V_78 >= V_79 &&
V_75 -> V_78 <= V_76 ;
}
static int F_55 ( int V_80 )
{
return V_79 + V_80 ;
}
static int F_56 ( int V_80 )
{
return F_53 ( F_55 ( V_80 ) ) ;
}
static int F_57 ( int V_80 )
{
return F_56 ( V_80 ) - F_55 ( V_80 ) ;
}
static int F_58 ( const struct V_74 * V_75 )
{
return V_75 -> type ;
}
static void * F_59 ( const struct V_74 * V_75 )
{
return ( char * ) V_75 + V_79 ;
}
static int F_60 ( const struct V_74 * V_75 )
{
return V_75 -> V_78 - V_79 ;
}
static T_9 F_61 ( const struct V_74 * V_75 )
{
return * ( T_9 * ) F_59 ( V_75 ) ;
}
static T_2 F_62 ( const struct V_74 * V_75 )
{
return * ( T_2 * ) F_59 ( V_75 ) ;
}
static T_1 F_63 ( const struct V_74 * V_75 )
{
return * ( T_1 * ) F_59 ( V_75 ) ;
}
static T_5 F_64 ( const struct V_74 * V_75 )
{
return * ( T_5 * ) F_59 ( V_75 ) ;
}
static T_6 F_65 ( const struct V_74 * V_75 )
{
return * ( T_6 * ) F_59 ( V_75 ) ;
}
static void F_66 ( const struct V_74 * * V_81 , int V_82 ,
const char * V_48 , int V_83 )
{
const struct V_74 * V_75 ;
const struct V_74 * V_84 = ( const struct V_74 * ) V_48 ;
int V_85 ;
memset ( V_81 , 0 , sizeof( struct V_74 * ) * ( V_82 + 1 ) ) ;
F_67 (tlv, head, buf_len, rem) {
T_5 type = F_58 ( V_75 ) ;
if ( type > 0 && type <= V_82 )
V_81 [ type ] = V_75 ;
}
}
static void F_68 ( const struct V_74 * * V_81 , int V_82 ,
const struct V_74 * V_75 )
{
F_66 ( V_81 , V_82 , F_59 ( V_75 ) ,
F_60 ( V_75 ) ) ;
}
static void F_69 ( const struct V_74 * * V_81 , int V_82 ,
const struct V_86 * V_87 )
{
F_66 ( V_81 , V_82 , V_87 -> V_88 ,
V_87 -> V_89 -> V_90 ) ;
}
static struct V_74 * F_70 ( struct V_86 * V_87 )
{
return (struct V_74 * ) ( ( char * ) V_87 -> V_88 +
V_87 -> V_90 ) ;
}
static int F_71 ( struct V_86 * V_87 ,
int V_91 , int V_92 , const void * V_88 )
{
int V_93 = V_87 -> V_94 - V_87 -> V_90 ;
int V_95 = F_56 ( V_92 ) ;
struct V_74 * V_75 ;
if ( F_72 ( V_93 < V_95 ) )
return - V_96 ;
V_75 = F_70 ( V_87 ) ;
V_87 -> V_90 += V_95 ;
V_75 -> type = V_91 ;
V_75 -> V_78 = F_55 ( V_92 ) ;
memcpy ( F_59 ( V_75 ) , V_88 , V_92 ) ;
memset ( ( char * ) V_75 + V_75 -> V_78 , 0 , F_57 ( V_92 ) ) ;
return 0 ;
}
static int F_73 ( struct V_86 * V_87 ,
int V_91 , T_9 V_97 )
{
return F_71 ( V_87 , V_91 , sizeof( T_9 ) , & V_97 ) ;
}
static int F_74 ( struct V_86 * V_87 ,
int V_91 , T_2 V_97 )
{
return F_71 ( V_87 , V_91 , sizeof( T_2 ) , & V_97 ) ;
}
static int F_75 ( struct V_86 * V_87 ,
int V_91 , T_1 V_97 )
{
return F_71 ( V_87 , V_91 , sizeof( T_1 ) , & V_97 ) ;
}
static int F_76 ( struct V_86 * V_87 ,
int V_91 , T_5 V_97 )
{
return F_71 ( V_87 , V_91 , sizeof( T_5 ) , & V_97 ) ;
}
static int F_77 ( struct V_86 * V_87 ,
int V_91 , T_10 V_97 )
{
return F_71 ( V_87 , V_91 , sizeof( T_10 ) , & V_97 ) ;
}
static int F_78 ( struct V_86 * V_87 ,
int V_91 , T_6 V_97 )
{
return F_71 ( V_87 , V_91 , sizeof( T_6 ) , & V_97 ) ;
}
static struct V_74 *
F_79 ( struct V_86 * V_87 , int V_91 )
{
struct V_74 * V_2 = F_70 ( V_87 ) ;
if ( F_71 ( V_87 , V_91 , 0 , NULL ) < 0 )
return NULL ;
return V_2 ;
}
static void F_80 ( struct V_86 * V_87 ,
struct V_74 * V_2 )
{
V_2 -> V_78 = ( char * ) F_70 ( V_87 ) - ( char * ) V_2 ;
}
static void F_81 ( struct V_86 * V_87 ,
const struct V_74 * V_2 )
{
V_87 -> V_90 = ( const char * ) V_2 - V_87 -> V_88 ;
}
static T_5 F_82 ( T_5 V_98 , T_3 V_99 )
{
return ++ V_98 == V_99 ? 0 : V_98 ;
}
static int F_83 ( const struct V_86 * V_87 )
{
int V_54 = V_87 -> V_89 -> V_100 & ~ V_101 ;
switch ( V_54 ) {
case V_102 :
return 0 ;
case - V_103 :
return - V_104 ;
case - V_105 :
return - V_106 ;
case - V_107 :
return - V_57 ;
case - V_108 :
return - V_109 ;
case - V_110 :
return - V_111 ;
case - V_112 :
return - V_96 ;
case - V_113 :
return - V_114 ;
case - V_115 :
return - V_116 ;
}
return - V_111 ;
}
static void F_84 ( const struct V_86 * V_87 )
{
V_87 -> V_89 -> V_100 &= ~ V_101 ;
}
static bool F_85 ( const struct V_86 * V_87 )
{
T_5 V_100 = V_87 -> V_89 -> V_100 ;
return V_100 & V_101 ? true : false ;
}
static void * F_86 ( const struct V_86 * V_87 )
{
return ( void * ) ( V_117 ) V_87 -> V_89 -> V_118 ;
}
static void F_87 ( const struct V_86 * V_87 ,
void * V_119 )
{
V_87 -> V_89 -> V_118 = ( V_117 ) V_119 ;
}
static struct V_86 *
F_88 ( const struct V_120 * V_121 )
{
static struct V_86 * V_87 ;
T_5 V_84 = F_82 ( V_121 -> V_84 , V_121 -> V_14 ) ;
V_87 = & V_121 -> V_87 [ V_121 -> V_84 ] ;
if ( V_84 == V_121 -> V_122 )
return NULL ;
V_87 -> V_90 = 0 ;
return V_87 ;
}
static void F_89 ( const struct V_86 * V_87 )
{
V_87 -> V_89 -> V_123 = V_87 -> V_94 ;
V_87 -> V_89 -> V_90 = V_87 -> V_90 ;
}
static void F_90 ( const struct V_34 * V_34 ,
struct V_120 * V_121 ,
const struct V_86 * V_87 )
{
T_5 V_84 = F_82 ( V_121 -> V_84 , V_121 -> V_14 ) ;
F_13 ( V_84 == V_121 -> V_122 ) ;
F_89 ( V_87 ) ;
V_121 -> V_84 = V_84 ;
F_37 ( V_34 , F_91 ( V_121 -> type ) , V_84 ) ;
}
static struct V_86 *
F_92 ( struct V_120 * V_121 )
{
static struct V_86 * V_87 ;
if ( V_121 -> V_122 == V_121 -> V_84 )
return NULL ;
V_87 = & V_121 -> V_87 [ V_121 -> V_122 ] ;
if ( ! F_85 ( V_87 ) )
return NULL ;
V_121 -> V_122 = F_82 ( V_121 -> V_122 , V_121 -> V_14 ) ;
V_87 -> V_90 = V_87 -> V_89 -> V_90 ;
return V_87 ;
}
static void F_93 ( const struct V_34 * V_34 ,
const struct V_120 * V_121 ,
T_5 V_124 )
{
if ( V_124 )
F_37 ( V_34 , F_94 ( V_121 -> type ) , V_124 ) ;
}
static unsigned long F_95 ( T_3 V_14 )
{
return F_96 ( V_125 ,
F_97 ( F_98 ( V_14 ) , V_126 ) ) ;
}
static int F_99 ( const struct V_34 * V_34 ,
unsigned int type ,
T_3 V_14 ,
struct V_120 * V_121 )
{
int V_50 ;
F_13 ( V_14 != F_95 ( V_14 ) ) ;
V_121 -> V_14 = V_14 ;
V_121 -> type = type ;
V_121 -> V_84 = 0 ;
V_121 -> V_122 = 0 ;
V_121 -> V_87 = F_100 ( V_121 -> V_14 , sizeof( * V_121 -> V_87 ) ,
V_20 ) ;
if ( ! V_121 -> V_87 )
return - V_57 ;
V_121 -> V_89 = F_101 ( V_34 -> V_39 ,
V_121 -> V_14 * sizeof( * V_121 -> V_89 ) ,
& V_121 -> V_127 ) ;
if ( ! V_121 -> V_89 ) {
F_20 ( V_121 -> V_87 ) ;
return - V_57 ;
}
for ( V_50 = 0 ; V_50 < V_121 -> V_14 ; V_50 ++ )
V_121 -> V_87 [ V_50 ] . V_89 = & V_121 -> V_89 [ V_50 ] ;
F_37 ( V_34 , F_102 ( V_121 -> type ) ,
V_128 ) ;
F_40 ( V_34 , F_103 ( V_121 -> type ) , V_121 -> V_127 ) ;
F_37 ( V_34 , F_104 ( V_121 -> type ) , V_121 -> V_14 ) ;
return 0 ;
}
static void F_105 ( const struct V_34 * V_34 ,
const struct V_120 * V_121 )
{
F_40 ( V_34 , F_103 ( V_121 -> type ) , 0 ) ;
F_106 ( V_34 -> V_39 ,
V_121 -> V_14 * sizeof( struct V_129 ) ,
V_121 -> V_89 , V_121 -> V_127 ) ;
F_20 ( V_121 -> V_87 ) ;
}
static void F_107 ( const struct V_34 * V_34 ,
struct V_120 * V_121 )
{
int V_50 ;
F_13 ( V_121 -> V_84 || V_121 -> V_122 ) ;
for ( V_50 = 0 ; V_50 < V_121 -> V_14 - 1 ; V_50 ++ )
F_90 ( V_34 , V_121 , & V_121 -> V_87 [ V_50 ] ) ;
F_89 ( & V_121 -> V_87 [ V_50 ] ) ;
}
static int F_108 ( const struct V_34 * V_34 ,
const struct V_120 * V_121 ,
int V_130 , T_3 V_123 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
int V_50 ;
int V_54 ;
for ( V_50 = 0 ; V_50 < V_121 -> V_14 ; V_50 ++ ) {
struct V_86 * V_87 = & V_121 -> V_87 [ V_50 ] ;
struct V_129 * V_89 = & V_121 -> V_89 [ V_50 ] ;
T_7 V_47 ;
char * V_48 ;
V_48 = F_11 ( V_123 , V_20 | V_56 ) ;
if ( ! V_48 ) {
V_54 = - V_57 ;
goto V_131;
}
V_47 = F_44 ( V_39 , V_48 , V_123 , V_130 ) ;
if ( F_45 ( V_39 , V_47 ) ) {
F_20 ( V_48 ) ;
V_54 = - V_44 ;
goto V_131;
}
V_87 -> V_88 = V_48 ;
V_87 -> V_94 = V_123 ;
F_109 ( V_87 , V_127 , V_47 ) ;
V_89 -> V_132 = V_47 ;
V_89 -> V_123 = V_123 ;
}
return 0 ;
V_131:
for ( V_50 -- ; V_50 >= 0 ; V_50 -- ) {
const struct V_86 * V_87 = & V_121 -> V_87 [ V_50 ] ;
F_47 ( V_39 , F_110 ( V_87 , V_127 ) ,
V_87 -> V_94 , V_130 ) ;
F_20 ( V_87 -> V_88 ) ;
}
return V_54 ;
}
static void F_111 ( const struct V_34 * V_34 ,
const struct V_120 * V_121 ,
int V_130 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_121 -> V_14 ; V_50 ++ ) {
const struct V_86 * V_87 = & V_121 -> V_87 [ V_50 ] ;
struct V_129 * V_89 = & V_121 -> V_89 [ V_50 ] ;
V_89 -> V_132 = 0 ;
V_89 -> V_123 = 0 ;
F_47 ( V_39 , F_110 ( V_87 , V_127 ) ,
V_87 -> V_94 , V_130 ) ;
F_20 ( V_87 -> V_88 ) ;
}
}
static int F_112 ( struct V_34 * V_34 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
int V_54 ;
V_54 = F_99 ( V_34 , V_133 ,
V_134 ,
& V_34 -> V_135 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_8 ) ;
return V_54 ;
}
F_113 ( & V_34 -> V_136 ) ;
V_54 = F_108 ( V_34 , & V_34 -> V_135 ,
V_58 , V_137 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_9 ) ;
goto V_138;
}
V_54 = F_99 ( V_34 , V_139 ,
V_140 ,
& V_34 -> V_141 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_10 ) ;
goto V_142;
}
V_54 = F_108 ( V_34 , & V_34 -> V_141 ,
V_143 , V_137 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_11 ) ;
goto V_144;
}
F_107 ( V_34 , & V_34 -> V_141 ) ;
return 0 ;
V_144:
F_105 ( V_34 , & V_34 -> V_141 ) ;
V_142:
F_111 ( V_34 , & V_34 -> V_135 ,
V_58 ) ;
V_138:
F_105 ( V_34 , & V_34 -> V_135 ) ;
return V_54 ;
}
static void F_114 ( struct V_34 * V_34 )
{
F_111 ( V_34 , & V_34 -> V_141 ,
V_58 ) ;
F_105 ( V_34 , & V_34 -> V_141 ) ;
F_111 ( V_34 , & V_34 -> V_135 ,
V_58 ) ;
F_105 ( V_34 , & V_34 -> V_135 ) ;
}
static int F_115 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
struct V_145 * V_146 , T_3 V_83 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_38 * V_39 = V_34 -> V_39 ;
T_7 V_47 ;
V_47 = F_44 ( V_39 , V_146 -> V_88 , V_83 ,
V_143 ) ;
if ( F_45 ( V_39 , V_47 ) )
return - V_44 ;
if ( F_78 ( V_87 , V_147 , V_47 ) )
goto V_148;
if ( F_74 ( V_87 , V_149 , V_83 ) )
goto V_148;
return 0 ;
V_148:
F_47 ( V_39 , V_47 , V_83 , V_143 ) ;
V_87 -> V_90 = 0 ;
return - V_96 ;
}
static T_3 F_116 ( const struct V_6 * V_6 )
{
return V_6 -> V_43 -> V_150 + V_151 + V_152 + V_153 ;
}
static int F_117 ( const struct V_6 * V_6 ,
struct V_86 * V_87 )
{
struct V_154 * V_43 = V_6 -> V_43 ;
struct V_145 * V_146 ;
T_3 V_83 = F_116 ( V_6 ) ;
int V_54 ;
F_87 ( V_87 , NULL ) ;
V_87 -> V_90 = 0 ;
V_146 = F_118 ( V_43 , V_83 ) ;
if ( ! V_146 )
return - V_57 ;
V_54 = F_115 ( V_6 , V_87 , V_146 , V_83 ) ;
if ( V_54 ) {
F_119 ( V_146 ) ;
return V_54 ;
}
F_87 ( V_87 , V_146 ) ;
return 0 ;
}
static void F_120 ( const struct V_34 * V_34 ,
const struct V_74 * * V_155 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
T_7 V_47 ;
T_3 V_78 ;
if ( ! V_155 [ V_147 ] ||
! V_155 [ V_149 ] )
return;
V_47 = F_65 ( V_155 [ V_147 ] ) ;
V_78 = F_62 ( V_155 [ V_149 ] ) ;
F_47 ( V_39 , V_47 , V_78 , V_143 ) ;
}
static void F_121 ( const struct V_34 * V_34 ,
const struct V_86 * V_87 )
{
const struct V_74 * V_155 [ V_156 + 1 ] ;
struct V_145 * V_146 = F_86 ( V_87 ) ;
if ( ! V_146 )
return;
F_69 ( V_155 , V_156 , V_87 ) ;
F_120 ( V_34 , V_155 ) ;
F_119 ( V_146 ) ;
}
static int F_122 ( const struct V_6 * V_6 )
{
const struct V_120 * V_157 = & V_6 -> V_157 ;
const struct V_34 * V_34 = V_6 -> V_34 ;
int V_50 ;
int V_54 ;
for ( V_50 = 0 ; V_50 < V_157 -> V_14 ; V_50 ++ ) {
V_54 = F_117 ( V_6 ,
& V_157 -> V_87 [ V_50 ] ) ;
if ( V_54 )
goto V_131;
}
return 0 ;
V_131:
for ( V_50 -- ; V_50 >= 0 ; V_50 -- )
F_121 ( V_34 , & V_157 -> V_87 [ V_50 ] ) ;
return V_54 ;
}
static void F_123 ( const struct V_6 * V_6 )
{
const struct V_120 * V_157 = & V_6 -> V_157 ;
const struct V_34 * V_34 = V_6 -> V_34 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_157 -> V_14 ; V_50 ++ )
F_121 ( V_34 , & V_157 -> V_87 [ V_50 ] ) ;
}
static int F_124 ( struct V_6 * V_6 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
int V_54 ;
V_54 = F_99 ( V_34 ,
F_125 ( V_6 -> V_37 ) ,
V_158 ,
& V_6 -> V_159 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_12 ) ;
return V_54 ;
}
V_54 = F_108 ( V_34 , & V_6 -> V_159 ,
V_160 ,
V_161 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_13 ) ;
goto V_162;
}
V_54 = F_99 ( V_34 ,
F_127 ( V_6 -> V_37 ) ,
V_163 ,
& V_6 -> V_157 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_14 ) ;
goto V_164;
}
V_54 = F_108 ( V_34 , & V_6 -> V_157 ,
V_58 ,
V_165 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_15 ) ;
goto V_166;
}
V_54 = F_122 ( V_6 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_16 ) ;
goto V_167;
}
F_107 ( V_34 , & V_6 -> V_157 ) ;
return 0 ;
V_167:
F_111 ( V_34 , & V_6 -> V_157 ,
V_58 ) ;
V_166:
F_105 ( V_34 , & V_6 -> V_157 ) ;
V_164:
F_111 ( V_34 , & V_6 -> V_159 ,
V_160 ) ;
V_162:
F_105 ( V_34 , & V_6 -> V_159 ) ;
return V_54 ;
}
static void F_128 ( struct V_6 * V_6 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
F_123 ( V_6 ) ;
F_111 ( V_34 , & V_6 -> V_157 ,
V_58 ) ;
F_105 ( V_34 , & V_6 -> V_157 ) ;
F_111 ( V_34 , & V_6 -> V_159 ,
V_160 ) ;
F_105 ( V_34 , & V_6 -> V_159 ) ;
}
static void F_129 ( const struct V_6 * V_6 ,
bool V_168 )
{
T_6 V_169 = F_41 ( V_6 -> V_34 , V_170 ) ;
if ( V_168 )
V_169 |= 1ULL << V_6 -> V_171 ;
else
V_169 &= ~ ( 1ULL << V_6 -> V_171 ) ;
F_40 ( V_6 -> V_34 , V_170 , V_169 ) ;
}
static T_8 F_130 ( int V_67 , void * V_68 )
{
struct V_34 * V_34 = V_68 ;
const struct V_86 * V_87 ;
struct V_28 * V_29 ;
T_5 V_124 = 0 ;
F_131 ( & V_34 -> V_136 ) ;
while ( ( V_87 = F_92 ( & V_34 -> V_135 ) ) ) {
V_29 = F_86 ( V_87 ) ;
if ( V_29 -> V_31 ) {
F_84 ( V_87 ) ;
F_25 ( V_25 , V_29 ) ;
} else {
F_28 ( V_29 ) ;
}
V_124 ++ ;
}
F_132 ( & V_34 -> V_136 ) ;
F_93 ( V_34 , & V_34 -> V_135 , V_124 ) ;
return V_69 ;
}
static void F_133 ( const struct V_6 * V_6 )
{
F_134 ( V_6 -> V_43 ) ;
F_135 ( V_6 -> V_43 , L_17 ) ;
}
static void F_136 ( const struct V_6 * V_6 )
{
F_137 ( V_6 -> V_43 ) ;
F_135 ( V_6 -> V_43 , L_18 ) ;
}
static int F_138 ( const struct V_34 * V_34 ,
const struct V_74 * V_121 )
{
const struct V_74 * V_155 [ V_172 + 1 ] ;
unsigned int V_37 ;
bool V_173 ;
struct V_6 * V_6 ;
F_68 ( V_155 , V_172 , V_121 ) ;
if ( ! V_155 [ V_174 ] ||
! V_155 [ V_175 ] )
return - V_44 ;
V_37 =
F_64 ( V_155 [ V_174 ] ) - 1 ;
V_173 = F_61 ( V_155 [ V_175 ] ) ;
if ( V_37 >= V_34 -> V_176 )
return - V_111 ;
V_6 = V_34 -> V_177 [ V_37 ] ;
if ( F_139 ( V_6 -> V_43 ) != V_173 ) {
if ( V_173 )
F_133 ( V_6 ) ;
else
F_136 ( V_6 ) ;
}
return 0 ;
}
static int F_140 ( const struct V_34 * V_34 ,
const struct V_74 * V_121 )
{
const struct V_74 * V_155 [ V_178 + 1 ] ;
unsigned int V_37 ;
struct V_6 * V_6 ;
const unsigned char * V_179 ;
int V_13 = V_18 | V_180 ;
T_1 V_1 ;
F_68 ( V_155 , V_178 , V_121 ) ;
if ( ! V_155 [ V_181 ] ||
! V_155 [ V_182 ] ||
! V_155 [ V_183 ] )
return - V_44 ;
V_37 =
F_64 ( V_155 [ V_181 ] ) - 1 ;
V_179 = F_59 ( V_155 [ V_182 ] ) ;
V_1 = F_63 ( V_155 [ V_183 ] ) ;
if ( V_37 >= V_34 -> V_176 )
return - V_111 ;
V_6 = V_34 -> V_177 [ V_37 ] ;
if ( V_6 -> V_184 != V_185 &&
V_6 -> V_184 != V_186 )
return 0 ;
return F_141 ( V_6 , V_25 ,
V_179 , V_1 , V_13 ) ;
}
static int F_142 ( const struct V_34 * V_34 ,
const struct V_86 * V_87 )
{
const struct V_74 * V_155 [ V_187 + 1 ] ;
const struct V_74 * V_121 ;
T_2 type ;
F_69 ( V_155 , V_187 , V_87 ) ;
if ( ! V_155 [ V_188 ] ||
! V_155 [ V_189 ] )
return - V_44 ;
type = F_62 ( V_155 [ V_188 ] ) ;
V_121 = V_155 [ V_189 ] ;
switch ( type ) {
case V_190 :
return F_138 ( V_34 , V_121 ) ;
case V_191 :
return F_140 ( V_34 , V_121 ) ;
}
return - V_114 ;
}
static T_8 F_143 ( int V_67 , void * V_68 )
{
struct V_34 * V_34 = V_68 ;
const struct V_38 * V_39 = V_34 -> V_39 ;
const struct V_86 * V_87 ;
T_5 V_124 = 0 ;
int V_54 ;
while ( ( V_87 = F_92 ( & V_34 -> V_141 ) ) ) {
V_54 = F_83 ( V_87 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_19 ,
V_54 ) ;
} else {
V_54 = F_142 ( V_34 , V_87 ) ;
if ( V_54 )
F_39 ( & V_39 -> V_43 , L_20 ,
V_54 ) ;
}
F_84 ( V_87 ) ;
F_90 ( V_34 , & V_34 -> V_141 , V_87 ) ;
V_124 ++ ;
}
F_93 ( V_34 , & V_34 -> V_141 , V_124 ) ;
return V_69 ;
}
static T_8 F_144 ( int V_67 , void * V_68 )
{
struct V_6 * V_6 = V_68 ;
F_145 ( & V_6 -> V_192 ) ;
return V_69 ;
}
static T_8 F_146 ( int V_67 , void * V_68 )
{
struct V_6 * V_6 = V_68 ;
F_145 ( & V_6 -> V_193 ) ;
return V_69 ;
}
static int F_147 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_11 V_194 , void * V_195 ,
T_12 V_196 , void * V_197 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_86 * V_87 ;
struct V_28 * V_29 ;
bool V_31 = ! ! ( V_13 & V_18 ) ;
unsigned long V_198 ;
int V_54 ;
V_29 = F_24 ( V_6 , V_12 , V_13 ) ;
if ( ! V_29 )
return - V_57 ;
V_29 -> V_31 = V_31 ;
F_148 ( & V_34 -> V_136 , V_198 ) ;
V_87 = F_88 ( & V_34 -> V_135 ) ;
if ( ! V_87 ) {
F_149 ( & V_34 -> V_136 , V_198 ) ;
V_54 = - V_199 ;
goto V_200;
}
V_54 = V_194 ( V_6 , V_87 , V_195 ) ;
if ( V_54 ) {
F_149 ( & V_34 -> V_136 , V_198 ) ;
goto V_200;
}
F_87 ( V_87 , V_29 ) ;
if ( V_12 != V_21 )
F_90 ( V_34 , & V_34 -> V_135 , V_87 ) ;
F_149 ( & V_34 -> V_136 , V_198 ) ;
if ( V_31 )
return 0 ;
if ( V_12 != V_21 )
if ( ! F_26 ( V_29 , V_33 / 10 ) )
return - V_44 ;
V_54 = F_83 ( V_87 ) ;
if ( V_54 )
return V_54 ;
if ( V_196 )
V_54 = V_196 ( V_6 , V_87 , V_197 ) ;
F_84 ( V_87 ) ;
V_200:
F_25 ( V_12 , V_29 ) ;
return V_54 ;
}
static int
F_150 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 ,
V_204 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_151 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
struct V_207 * V_208 = V_201 ;
const struct V_74 * V_155 [ V_209 + 1 ] ;
const struct V_74 * V_210 [ V_211 + 1 ] ;
T_5 V_212 ;
T_9 V_213 ;
T_9 V_214 ;
F_69 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_68 ( V_210 , V_211 ,
V_155 [ V_205 ] ) ;
if ( ! V_210 [ V_215 ] ||
! V_210 [ V_216 ] ||
! V_210 [ V_217 ] )
return - V_44 ;
V_212 = F_64 ( V_210 [ V_215 ] ) ;
V_213 = F_61 ( V_210 [ V_216 ] ) ;
V_214 = F_61 ( V_210 [ V_217 ] ) ;
V_208 -> V_218 = V_219 ;
V_208 -> V_220 = V_221 ;
V_208 -> V_222 = 0xff ;
V_208 -> V_223 = V_224 ;
F_152 ( V_208 , V_212 ) ;
V_208 -> V_213 = V_213 ? V_225 : V_226 ;
V_208 -> V_214 = V_214 ? V_227 : V_228 ;
return 0 ;
}
static int
F_153 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
unsigned char * V_229 = V_201 ;
const struct V_74 * V_155 [ V_209 + 1 ] ;
const struct V_74 * V_210 [ V_211 + 1 ] ;
const struct V_74 * V_230 ;
F_69 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_68 ( V_210 , V_211 ,
V_155 [ V_205 ] ) ;
V_230 = V_210 [ V_231 ] ;
if ( ! V_230 )
return - V_44 ;
if ( F_60 ( V_230 ) != V_232 )
return - V_111 ;
F_154 ( V_229 , F_59 ( V_230 ) ) ;
return 0 ;
}
static int
F_155 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
const struct V_74 * V_210 [ V_211 + 1 ] ;
const struct V_74 * V_155 [ V_209 + 1 ] ;
struct V_233 * V_234 = V_201 ;
const struct V_74 * V_230 ;
T_3 V_50 , V_235 , V_78 ;
const char * V_236 ;
F_69 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_68 ( V_210 , V_211 ,
V_155 [ V_205 ] ) ;
V_230 = V_210 [ V_237 ] ;
if ( ! V_230 )
return - V_44 ;
V_78 = F_156 ( T_3 , F_60 ( V_230 ) , V_234 -> V_78 ) ;
V_236 = F_59 ( V_230 ) ;
for ( V_50 = V_235 = 0 ; V_50 < V_78 ; ++ V_50 ) {
if ( isalnum ( V_236 [ V_50 ] ) ) {
V_234 -> V_48 [ V_235 ] = V_236 [ V_50 ] ;
V_235 ++ ;
}
}
if ( V_235 == 0 )
return - V_44 ;
V_234 -> V_48 [ V_235 ] = '\0' ;
return 0 ;
}
static int
F_157 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_207 * V_208 = V_201 ;
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_215 ,
F_158 ( V_208 ) ) )
return - V_96 ;
if ( F_73 ( V_87 , V_216 ,
V_208 -> V_213 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_217 ,
V_208 -> V_214 ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_159 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const unsigned char * V_229 = V_201 ;
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_231 ,
V_232 , V_229 ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_160 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
int V_150 = * ( int * ) V_201 ;
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_239 ,
V_150 ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_161 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_240 ,
! ! ( V_6 -> V_241 & V_242 ) ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_162 ( struct V_6 * V_6 ,
struct V_207 * V_208 )
{
return F_147 ( V_6 , V_25 , 0 ,
F_150 , NULL ,
F_151 ,
V_208 ) ;
}
static int F_163 ( struct V_6 * V_6 ,
unsigned char * V_229 )
{
return F_147 ( V_6 , V_25 , 0 ,
F_150 , NULL ,
F_153 ,
V_229 ) ;
}
static int F_164 ( struct V_6 * V_6 ,
struct V_207 * V_208 )
{
return F_147 ( V_6 , V_25 , 0 ,
F_157 ,
V_208 , NULL , NULL ) ;
}
static int F_165 ( struct V_6 * V_6 ,
unsigned char * V_229 )
{
return F_147 ( V_6 , V_25 , 0 ,
F_159 ,
V_229 , NULL , NULL ) ;
}
static int F_166 ( struct V_6 * V_6 ,
int V_150 )
{
return F_147 ( V_6 , V_25 , 0 ,
F_160 ,
& V_150 , NULL , NULL ) ;
}
static int F_167 ( struct V_6 * V_6 ,
enum V_11 V_12 )
{
return F_147 ( V_6 , V_12 , 0 ,
F_161 ,
NULL , NULL , NULL ) ;
}
static int
F_168 ( struct V_86 * V_87 ,
const struct V_243 * V_244 )
{
if ( F_76 ( V_87 , V_245 ,
V_244 -> V_246 . V_247 . V_248 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_249 ,
V_244 -> V_246 . V_247 . V_250 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_251 ,
V_244 -> V_246 . V_247 . V_252 ) )
return - V_96 ;
return 0 ;
}
static int
F_169 ( struct V_86 * V_87 ,
const struct V_243 * V_244 )
{
if ( F_76 ( V_87 , V_245 ,
V_244 -> V_246 . V_253 . V_248 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_254 ,
V_244 -> V_246 . V_253 . V_1 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_255 ,
V_244 -> V_246 . V_253 . V_256 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_251 ,
V_244 -> V_246 . V_253 . V_252 ) )
return - V_96 ;
if ( V_244 -> V_246 . V_253 . V_257 &&
F_75 ( V_87 , V_258 ,
V_244 -> V_246 . V_253 . V_259 ) )
return - V_96 ;
return 0 ;
}
static int
F_170 ( struct V_86 * V_87 ,
const struct V_243 * V_244 )
{
if ( F_76 ( V_87 , V_245 ,
V_244 -> V_246 . V_260 . V_248 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_249 ,
V_244 -> V_246 . V_260 . V_250 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_261 ,
V_244 -> V_246 . V_260 . V_262 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_263 ,
V_232 , V_244 -> V_246 . V_260 . V_264 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_265 ,
V_232 , V_244 -> V_246 . V_260 . V_266 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_254 ,
V_244 -> V_246 . V_260 . V_1 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_255 ,
V_244 -> V_246 . V_260 . V_256 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_251 ,
V_244 -> V_246 . V_260 . V_252 ) )
return - V_96 ;
if ( V_244 -> V_246 . V_260 . V_267 &&
F_73 ( V_87 , V_268 ,
V_244 -> V_246 . V_260 . V_267 ) )
return - V_96 ;
return 0 ;
}
static int
F_171 ( struct V_86 * V_87 ,
const struct V_243 * V_244 )
{
if ( F_75 ( V_87 , V_261 ,
V_244 -> V_246 . V_269 . V_262 ) )
return - V_96 ;
if ( F_77 ( V_87 , V_270 ,
V_244 -> V_246 . V_269 . V_271 ) )
return - V_96 ;
if ( F_77 ( V_87 , V_272 ,
V_244 -> V_246 . V_269 . V_273 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_251 ,
V_244 -> V_246 . V_269 . V_252 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_274 ,
V_244 -> V_246 . V_269 . V_275 ) )
return - V_96 ;
return 0 ;
}
static int
F_172 ( struct V_86 * V_87 ,
const struct V_243 * V_244 )
{
if ( V_244 -> V_246 . V_276 . V_277 &&
F_71 ( V_87 , V_263 ,
V_232 , V_244 -> V_246 . V_276 . V_264 ) )
return - V_96 ;
if ( V_244 -> V_246 . V_276 . V_278 &&
F_71 ( V_87 , V_265 ,
V_232 , V_244 -> V_246 . V_276 . V_266 ) )
return - V_96 ;
if ( V_244 -> V_246 . V_276 . V_1 &&
F_75 ( V_87 , V_254 ,
V_244 -> V_246 . V_276 . V_1 ) )
return - V_96 ;
if ( V_244 -> V_246 . V_276 . V_279 &&
F_76 ( V_87 , V_280 ,
V_244 -> V_246 . V_276 . V_279 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_251 ,
V_244 -> V_246 . V_276 . V_252 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_274 ,
V_244 -> V_246 . V_276 . V_275 ) )
return - V_96 ;
if ( V_244 -> V_246 . V_276 . V_267 &&
F_73 ( V_87 , V_268 ,
V_244 -> V_246 . V_276 . V_267 ) )
return - V_96 ;
return 0 ;
}
static int
F_173 ( struct V_86 * V_87 ,
const struct V_243 * V_244 )
{
if ( F_76 ( V_87 , V_245 ,
V_244 -> V_246 . V_281 . V_248 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_249 ,
V_244 -> V_246 . V_281 . V_250 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_282 ,
V_232 , V_244 -> V_246 . V_281 . V_283 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_284 ,
V_232 , V_244 -> V_246 . V_281 . V_285 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_263 ,
V_232 , V_244 -> V_246 . V_281 . V_264 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_265 ,
V_232 , V_244 -> V_246 . V_281 . V_266 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_261 ,
V_244 -> V_246 . V_281 . V_262 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_254 ,
V_244 -> V_246 . V_281 . V_1 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_255 ,
V_244 -> V_246 . V_281 . V_256 ) )
return - V_96 ;
switch ( F_2 ( V_244 -> V_246 . V_281 . V_262 ) ) {
case V_286 :
case V_287 :
if ( F_73 ( V_87 , V_288 ,
V_244 -> V_246 . V_281 . V_289 ) )
return - V_96 ;
if ( F_73 ( V_87 ,
V_290 ,
V_244 -> V_246 . V_281 . V_291 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_292 ,
V_244 -> V_246 . V_281 . V_293 & 0x3f ) )
return - V_96 ;
if ( F_73 ( V_87 ,
V_294 ,
V_244 -> V_246 . V_281 . V_295 & 0x3f ) )
return - V_96 ;
if ( F_73 ( V_87 , V_296 ,
( V_244 -> V_246 . V_281 . V_293 & 0xc0 ) >> 6 ) )
return - V_96 ;
if ( F_73 ( V_87 ,
V_297 ,
( V_244 -> V_246 . V_281 . V_295 & 0xc0 ) >> 6 ) )
return - V_96 ;
break;
}
if ( V_244 -> V_246 . V_281 . V_275 != V_298 &&
F_76 ( V_87 , V_274 ,
V_244 -> V_246 . V_281 . V_275 ) )
return - V_96 ;
return 0 ;
}
static int F_174 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const struct V_243 * V_244 = V_201 ;
struct V_74 * V_202 ;
int V_54 = 0 ;
if ( F_74 ( V_87 , V_203 , V_244 -> V_299 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_74 ( V_87 , V_300 ,
V_244 -> V_246 . V_301 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_302 ,
V_244 -> V_246 . V_303 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_304 , 0 ) )
return - V_96 ;
if ( F_78 ( V_87 , V_305 ,
V_244 -> V_118 ) )
return - V_96 ;
switch ( V_244 -> V_246 . V_301 ) {
case V_306 :
V_54 = F_168 ( V_87 , V_244 ) ;
break;
case V_307 :
V_54 = F_169 ( V_87 , V_244 ) ;
break;
case V_308 :
V_54 = F_170 ( V_87 , V_244 ) ;
break;
case V_309 :
V_54 = F_171 ( V_87 , V_244 ) ;
break;
case V_310 :
V_54 = F_172 ( V_87 , V_244 ) ;
break;
case V_311 :
V_54 = F_173 ( V_87 , V_244 ) ;
break;
default:
V_54 = - V_312 ;
break;
}
if ( V_54 )
return V_54 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_175 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const struct V_243 * V_244 = V_201 ;
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 , V_244 -> V_299 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_78 ( V_87 , V_305 ,
V_244 -> V_118 ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_176 ( struct V_86 * V_87 ,
struct V_313 * V_244 )
{
if ( F_76 ( V_87 , V_314 ,
F_177 ( V_244 -> V_275 ) ) )
return - V_96 ;
if ( F_73 ( V_87 , V_315 ,
V_244 -> V_316 . V_8 ) )
return - V_96 ;
return 0 ;
}
static int
F_178 ( struct V_86 * V_87 ,
const struct V_313 * V_244 )
{
if ( F_76 ( V_87 , V_317 ,
V_244 -> V_318 . V_275 ) )
return - V_96 ;
if ( ! F_179 ( V_244 -> V_318 . V_283 ) &&
F_71 ( V_87 , V_282 ,
V_232 , V_244 -> V_318 . V_283 ) )
return - V_96 ;
if ( ! F_179 ( V_244 -> V_318 . V_264 ) &&
F_71 ( V_87 , V_263 ,
V_232 , V_244 -> V_318 . V_264 ) )
return - V_96 ;
if ( V_244 -> V_318 . V_1 &&
F_75 ( V_87 , V_254 ,
V_244 -> V_318 . V_1 ) )
return - V_96 ;
return 0 ;
}
static int
F_180 ( struct V_86 * V_87 ,
const struct V_313 * V_244 )
{
int V_50 ;
struct V_74 * V_319 ;
if ( F_74 ( V_87 , V_320 ,
V_244 -> V_321 ) )
return - V_96 ;
V_319 = F_79 ( V_87 ,
V_322 ) ;
if ( ! V_319 )
return - V_96 ;
for ( V_50 = 0 ; V_50 < V_244 -> V_321 ; V_50 ++ )
if ( F_76 ( V_87 , V_50 + 1 , V_244 -> V_319 [ V_50 ] ) )
return - V_96 ;
F_80 ( V_87 , V_319 ) ;
return 0 ;
}
static int
F_181 ( struct V_86 * V_87 ,
const struct V_313 * V_244 )
{
if ( ! F_179 ( V_244 -> V_323 . V_283 ) &&
F_71 ( V_87 , V_282 ,
V_232 , V_244 -> V_323 . V_283 ) )
return - V_96 ;
if ( ! F_179 ( V_244 -> V_323 . V_264 ) &&
F_71 ( V_87 , V_263 ,
V_232 , V_244 -> V_323 . V_264 ) )
return - V_96 ;
if ( V_244 -> V_323 . V_1 &&
F_75 ( V_87 , V_254 ,
V_244 -> V_323 . V_1 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_324 ,
V_244 -> V_323 . V_325 ) )
return - V_96 ;
if ( F_76 ( V_87 , V_317 ,
V_244 -> V_323 . V_275 ) )
return - V_96 ;
return 0 ;
}
static int F_182 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_313 * V_244 = V_201 ;
struct V_74 * V_202 ;
int V_54 = 0 ;
if ( F_74 ( V_87 , V_203 , V_244 -> V_299 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_274 ,
V_244 -> V_275 ) )
return - V_96 ;
switch ( F_183 ( V_244 -> V_275 ) ) {
case V_326 :
V_54 = F_176 ( V_87 , V_244 ) ;
break;
case V_327 :
V_54 = F_178 ( V_87 , V_244 ) ;
break;
case V_328 :
case V_329 :
V_54 = F_180 ( V_87 , V_244 ) ;
break;
case V_330 :
V_54 = F_181 ( V_87 , V_244 ) ;
break;
default:
V_54 = - V_312 ;
break;
}
if ( V_54 )
return V_54 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_184 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const struct V_313 * V_244 = V_201 ;
struct V_74 * V_202 ;
if ( F_74 ( V_87 , V_203 , V_244 -> V_299 ) )
return - V_96 ;
V_202 = F_79 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_76 ( V_87 , V_274 ,
V_244 -> V_275 ) )
return - V_96 ;
F_80 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_185 ( struct V_34 * V_34 )
{
F_186 ( V_34 -> V_331 ) ;
F_113 ( & V_34 -> V_332 ) ;
F_186 ( V_34 -> V_333 ) ;
F_113 ( & V_34 -> V_334 ) ;
F_186 ( V_34 -> V_335 ) ;
F_113 ( & V_34 -> V_336 ) ;
F_186 ( V_34 -> V_337 ) ;
F_113 ( & V_34 -> V_338 ) ;
F_186 ( V_34 -> V_339 ) ;
F_113 ( & V_34 -> V_340 ) ;
return 0 ;
}
static void F_187 ( struct V_34 * V_34 )
{
unsigned long V_13 ;
struct V_243 * V_341 ;
struct V_313 * V_342 ;
struct V_343 * V_344 ;
struct V_345 * V_346 ;
struct V_347 * V_348 ;
struct V_349 * V_350 ;
int V_351 ;
F_148 ( & V_34 -> V_332 , V_13 ) ;
F_188 (rocker->flow_tbl, bkt, tmp, flow_entry, entry)
F_189 ( & V_341 -> V_244 ) ;
F_149 ( & V_34 -> V_332 , V_13 ) ;
F_148 ( & V_34 -> V_334 , V_13 ) ;
F_188 (rocker->group_tbl, bkt, tmp, group_entry, entry)
F_189 ( & V_342 -> V_244 ) ;
F_149 ( & V_34 -> V_334 , V_13 ) ;
F_148 ( & V_34 -> V_336 , V_13 ) ;
F_188 (rocker->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_189 ( & V_344 -> V_244 ) ;
F_149 ( & V_34 -> V_336 , V_13 ) ;
F_148 ( & V_34 -> V_338 , V_13 ) ;
F_188 (rocker->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_189 ( & V_346 -> V_244 ) ;
F_149 ( & V_34 -> V_338 , V_13 ) ;
F_148 ( & V_34 -> V_340 , V_13 ) ;
F_188 (rocker->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_189 ( & V_348 -> V_244 ) ;
F_149 ( & V_34 -> V_340 , V_13 ) ;
}
static struct V_243 *
F_190 ( const struct V_34 * V_34 ,
const struct V_243 * V_352 )
{
struct V_243 * V_353 ;
T_3 V_354 = V_352 -> V_354 ? V_352 -> V_354 : sizeof( V_353 -> V_246 ) ;
F_191 (rocker->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_353 -> V_246 , & V_352 -> V_246 , V_354 ) == 0 )
return V_353 ;
}
return NULL ;
}
static int F_192 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_243 * V_352 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_243 * V_353 ;
T_3 V_354 = V_352 -> V_354 ? V_352 -> V_354 : sizeof( V_353 -> V_246 ) ;
unsigned long V_198 ;
V_352 -> V_355 = F_193 ( ~ 0 , & V_352 -> V_246 , V_354 ) ;
F_148 ( & V_34 -> V_332 , V_198 ) ;
V_353 = F_190 ( V_34 , V_352 ) ;
if ( V_353 ) {
V_352 -> V_118 = V_353 -> V_118 ;
if ( V_12 != V_21 )
F_189 ( & V_353 -> V_244 ) ;
F_19 ( V_12 , V_353 ) ;
V_353 = V_352 ;
V_353 -> V_299 = V_356 ;
} else {
V_353 = V_352 ;
V_353 -> V_118 = V_34 -> V_357 ++ ;
V_353 -> V_299 = V_358 ;
}
if ( V_12 != V_21 )
F_194 ( V_34 -> V_331 , & V_353 -> V_244 , V_353 -> V_355 ) ;
F_149 ( & V_34 -> V_332 , V_198 ) ;
return F_147 ( V_6 , V_12 , V_13 ,
F_174 , V_353 , NULL , NULL ) ;
}
static int F_195 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_243 * V_352 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_243 * V_353 ;
T_3 V_354 = V_352 -> V_354 ? V_352 -> V_354 : sizeof( V_353 -> V_246 ) ;
unsigned long V_198 ;
int V_54 = 0 ;
V_352 -> V_355 = F_193 ( ~ 0 , & V_352 -> V_246 , V_354 ) ;
F_148 ( & V_34 -> V_332 , V_198 ) ;
V_353 = F_190 ( V_34 , V_352 ) ;
if ( V_353 ) {
if ( V_12 != V_21 )
F_189 ( & V_353 -> V_244 ) ;
V_353 -> V_299 = V_359 ;
}
F_149 ( & V_34 -> V_332 , V_198 ) ;
F_19 ( V_12 , V_352 ) ;
if ( V_353 ) {
V_54 = F_147 ( V_6 , V_12 , V_13 ,
F_175 ,
V_353 , NULL , NULL ) ;
F_19 ( V_12 , V_353 ) ;
}
return V_54 ;
}
static int F_196 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_243 * V_244 )
{
if ( V_13 & V_360 )
return F_195 ( V_6 , V_12 , V_13 , V_244 ) ;
else
return F_192 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_197 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_248 , T_5 V_250 ,
enum V_361 V_252 )
{
struct V_243 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_246 . V_303 = V_362 ;
V_244 -> V_246 . V_301 = V_306 ;
V_244 -> V_246 . V_247 . V_248 = V_248 ;
V_244 -> V_246 . V_247 . V_250 = V_250 ;
V_244 -> V_246 . V_247 . V_252 = V_252 ;
return F_196 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_198 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_248 , T_1 V_1 ,
T_1 V_256 ,
enum V_361 V_252 ,
bool V_257 , T_1 V_259 )
{
struct V_243 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_246 . V_303 = V_363 ;
V_244 -> V_246 . V_301 = V_307 ;
V_244 -> V_246 . V_253 . V_248 = V_248 ;
V_244 -> V_246 . V_253 . V_1 = V_1 ;
V_244 -> V_246 . V_253 . V_256 = V_256 ;
V_244 -> V_246 . V_253 . V_252 = V_252 ;
V_244 -> V_246 . V_253 . V_257 = V_257 ;
V_244 -> V_246 . V_253 . V_259 = V_259 ;
return F_196 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_199 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
T_5 V_248 , T_5 V_250 ,
T_1 V_262 , const T_9 * V_264 ,
const T_9 * V_266 , T_1 V_1 ,
T_1 V_256 , bool V_267 ,
int V_13 )
{
struct V_243 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
if ( F_200 ( V_264 ) ) {
V_244 -> V_246 . V_303 = V_364 ;
V_244 -> V_246 . V_260 . V_252 =
V_365 ;
} else {
V_244 -> V_246 . V_303 = V_366 ;
V_244 -> V_246 . V_260 . V_252 =
V_309 ;
}
V_244 -> V_246 . V_301 = V_308 ;
V_244 -> V_246 . V_260 . V_248 = V_248 ;
V_244 -> V_246 . V_260 . V_250 = V_250 ;
V_244 -> V_246 . V_260 . V_262 = V_262 ;
F_154 ( V_244 -> V_246 . V_260 . V_264 , V_264 ) ;
F_154 ( V_244 -> V_246 . V_260 . V_266 , V_266 ) ;
V_244 -> V_246 . V_260 . V_1 = V_1 ;
V_244 -> V_246 . V_260 . V_256 = V_256 ;
V_244 -> V_246 . V_260 . V_267 = V_267 ;
return F_196 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_201 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const T_9 * V_264 , const T_9 * V_266 ,
T_1 V_1 , T_5 V_279 ,
enum V_361 V_252 ,
T_5 V_275 , bool V_267 )
{
struct V_243 * V_244 ;
T_5 V_303 ;
bool V_367 = ! ! V_1 ;
bool V_368 = ! V_264 || ( V_264 && V_266 ) ;
bool V_369 = false ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_246 . V_301 = V_310 ;
if ( V_264 ) {
V_244 -> V_246 . V_276 . V_277 = 1 ;
F_154 ( V_244 -> V_246 . V_276 . V_264 , V_264 ) ;
}
if ( V_266 ) {
V_244 -> V_246 . V_276 . V_278 = 1 ;
F_154 ( V_244 -> V_246 . V_276 . V_266 , V_266 ) ;
if ( ! F_202 ( V_266 , V_370 ) )
V_369 = true ;
}
V_303 = V_371 ;
if ( V_367 && V_368 && V_369 )
V_303 = V_372 ;
else if ( V_367 && V_368 && ! V_369 )
V_303 = V_373 ;
else if ( V_367 && ! V_368 )
V_303 = V_374 ;
else if ( ! V_367 && V_368 && V_369 )
V_303 = V_375 ;
else if ( ! V_367 && V_368 && ! V_369 )
V_303 = V_376 ;
else if ( ! V_367 && ! V_368 )
V_303 = V_377 ;
V_244 -> V_246 . V_303 = V_303 ;
V_244 -> V_246 . V_276 . V_1 = V_1 ;
V_244 -> V_246 . V_276 . V_279 = V_279 ;
V_244 -> V_246 . V_276 . V_252 = V_252 ;
V_244 -> V_246 . V_276 . V_275 = V_275 ;
V_244 -> V_246 . V_276 . V_267 = V_267 ;
return F_196 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_203 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
T_1 V_262 , T_10 V_378 ,
T_10 V_379 , T_5 V_303 ,
enum V_361 V_252 ,
T_5 V_275 , int V_13 )
{
struct V_243 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_246 . V_301 = V_309 ;
V_244 -> V_246 . V_303 = V_303 ;
V_244 -> V_246 . V_269 . V_262 = V_262 ;
V_244 -> V_246 . V_269 . V_271 = V_378 ;
V_244 -> V_246 . V_269 . V_273 = V_379 ;
V_244 -> V_246 . V_269 . V_252 = V_252 ;
V_244 -> V_246 . V_269 . V_275 = V_275 ;
V_244 -> V_354 = F_204 ( struct V_380 ,
V_269 . V_275 ) ;
return F_196 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_205 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_248 , T_5 V_250 ,
const T_9 * V_283 , const T_9 * V_285 ,
const T_9 * V_264 , const T_9 * V_266 ,
T_1 V_262 , T_1 V_1 ,
T_1 V_256 , T_9 V_289 ,
T_9 V_291 , T_9 V_293 , T_9 V_295 ,
T_5 V_275 )
{
T_5 V_303 ;
struct V_243 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_303 = V_381 ;
if ( V_264 && V_266 ) {
if ( F_202 ( V_266 , V_382 ) )
V_303 = V_383 ;
else if ( F_206 ( V_264 ) )
V_303 = V_384 ;
}
V_244 -> V_246 . V_303 = V_303 ;
V_244 -> V_246 . V_301 = V_311 ;
V_244 -> V_246 . V_281 . V_248 = V_248 ;
V_244 -> V_246 . V_281 . V_250 = V_250 ;
if ( V_283 )
F_154 ( V_244 -> V_246 . V_281 . V_283 , V_283 ) ;
if ( V_285 )
F_154 ( V_244 -> V_246 . V_281 . V_285 , V_285 ) ;
if ( V_264 )
F_154 ( V_244 -> V_246 . V_281 . V_264 , V_264 ) ;
if ( V_266 )
F_154 ( V_244 -> V_246 . V_281 . V_266 , V_266 ) ;
V_244 -> V_246 . V_281 . V_262 = V_262 ;
V_244 -> V_246 . V_281 . V_1 = V_1 ;
V_244 -> V_246 . V_281 . V_256 = V_256 ;
V_244 -> V_246 . V_281 . V_289 = V_289 ;
V_244 -> V_246 . V_281 . V_291 = V_291 ;
V_244 -> V_246 . V_281 . V_293 = V_293 ;
V_244 -> V_246 . V_281 . V_295 = V_295 ;
V_244 -> V_246 . V_281 . V_275 = V_275 ;
return F_196 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static struct V_313 *
F_207 ( const struct V_34 * V_34 ,
const struct V_313 * V_352 )
{
struct V_313 * V_353 ;
F_191 (rocker->group_tbl, found,
entry, match->group_id) {
if ( V_353 -> V_275 == V_352 -> V_275 )
return V_353 ;
}
return NULL ;
}
static void F_208 ( enum V_11 V_12 ,
struct V_313 * V_244 )
{
switch ( F_183 ( V_244 -> V_275 ) ) {
case V_328 :
case V_329 :
F_19 ( V_12 , V_244 -> V_319 ) ;
break;
default:
break;
}
F_19 ( V_12 , V_244 ) ;
}
static int F_209 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_313 * V_352 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_313 * V_353 ;
unsigned long V_198 ;
F_148 ( & V_34 -> V_334 , V_198 ) ;
V_353 = F_207 ( V_34 , V_352 ) ;
if ( V_353 ) {
if ( V_12 != V_21 )
F_189 ( & V_353 -> V_244 ) ;
F_208 ( V_12 , V_353 ) ;
V_353 = V_352 ;
V_353 -> V_299 = V_385 ;
} else {
V_353 = V_352 ;
V_353 -> V_299 = V_386 ;
}
if ( V_12 != V_21 )
F_194 ( V_34 -> V_333 , & V_353 -> V_244 , V_353 -> V_275 ) ;
F_149 ( & V_34 -> V_334 , V_198 ) ;
return F_147 ( V_6 , V_12 , V_13 ,
F_182 , V_353 , NULL , NULL ) ;
}
static int F_210 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_313 * V_352 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_313 * V_353 ;
unsigned long V_198 ;
int V_54 = 0 ;
F_148 ( & V_34 -> V_334 , V_198 ) ;
V_353 = F_207 ( V_34 , V_352 ) ;
if ( V_353 ) {
if ( V_12 != V_21 )
F_189 ( & V_353 -> V_244 ) ;
V_353 -> V_299 = V_387 ;
}
F_149 ( & V_34 -> V_334 , V_198 ) ;
F_208 ( V_12 , V_352 ) ;
if ( V_353 ) {
V_54 = F_147 ( V_6 , V_12 , V_13 ,
F_184 ,
V_353 , NULL , NULL ) ;
F_208 ( V_12 , V_353 ) ;
}
return V_54 ;
}
static int F_211 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_313 * V_244 )
{
if ( V_13 & V_360 )
return F_210 ( V_6 , V_12 , V_13 , V_244 ) ;
else
return F_209 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_212 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 , T_5 V_388 ,
int V_8 )
{
struct V_313 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_275 = F_213 ( V_1 , V_388 ) ;
V_244 -> V_316 . V_8 = V_8 ;
return F_211 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_214 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 , T_9 V_321 ,
const T_5 * V_319 , T_5 V_275 )
{
struct V_313 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_275 = V_275 ;
V_244 -> V_321 = V_321 ;
V_244 -> V_319 = F_18 ( V_6 , V_12 , V_13 ,
V_321 , sizeof( T_5 ) ) ;
if ( ! V_244 -> V_319 ) {
F_19 ( V_12 , V_244 ) ;
return - V_57 ;
}
memcpy ( V_244 -> V_319 , V_319 , V_321 * sizeof( T_5 ) ) ;
return F_211 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static int F_215 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 , T_9 V_321 ,
const T_5 * V_319 , T_5 V_275 )
{
return F_214 ( V_6 , V_12 , V_13 ,
V_321 , V_319 ,
V_275 ) ;
}
static int F_216 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_389 , const T_9 * V_390 , const T_9 * V_391 ,
T_1 V_1 , bool V_325 , T_5 V_171 )
{
struct V_313 * V_244 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
V_244 -> V_275 = F_217 ( V_389 ) ;
if ( V_390 )
F_154 ( V_244 -> V_323 . V_283 , V_390 ) ;
if ( V_391 )
F_154 ( V_244 -> V_323 . V_264 , V_391 ) ;
V_244 -> V_323 . V_1 = V_1 ;
V_244 -> V_323 . V_325 = V_325 ;
V_244 -> V_323 . V_275 = F_213 ( V_1 , V_171 ) ;
return F_211 ( V_6 , V_12 , V_13 , V_244 ) ;
}
static struct V_347 *
F_218 ( const struct V_34 * V_34 , T_10 V_392 )
{
struct V_347 * V_353 ;
F_191 (rocker->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_353 -> V_392 == V_392 )
return V_353 ;
return NULL ;
}
static void F_219 ( struct V_34 * V_34 ,
enum V_11 V_12 ,
struct V_347 * V_244 )
{
if ( V_12 != V_23 )
V_244 -> V_389 = V_34 -> V_393 ++ ;
if ( V_12 == V_21 )
return;
V_244 -> V_394 ++ ;
F_194 ( V_34 -> V_339 , & V_244 -> V_244 ,
F_220 ( V_244 -> V_392 ) ) ;
}
static void F_221 ( enum V_11 V_12 ,
struct V_347 * V_244 )
{
if ( V_12 == V_21 )
return;
if ( -- V_244 -> V_394 == 0 ) {
F_189 ( & V_244 -> V_244 ) ;
F_19 ( V_12 , V_244 ) ;
}
}
static void F_222 ( struct V_347 * V_244 ,
enum V_11 V_12 ,
const T_9 * V_264 , bool V_325 )
{
if ( V_264 ) {
F_154 ( V_244 -> V_264 , V_264 ) ;
V_244 -> V_325 = V_325 ;
} else if ( V_12 != V_21 ) {
V_244 -> V_394 ++ ;
}
}
static int F_223 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 , T_10 V_392 , const T_9 * V_264 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_347 * V_244 ;
struct V_347 * V_353 ;
unsigned long V_198 ;
T_1 V_262 = F_4 ( V_286 ) ;
enum V_361 V_252 =
V_311 ;
T_5 V_275 ;
T_5 V_303 = 0 ;
bool V_395 = ! ( V_13 & V_360 ) ;
bool V_396 ;
bool V_397 ;
int V_54 = 0 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
F_148 ( & V_34 -> V_340 , V_198 ) ;
V_353 = F_218 ( V_34 , V_392 ) ;
V_396 = V_353 && V_395 ;
V_397 = V_353 && ! V_395 ;
V_395 = ! V_353 && V_395 ;
if ( V_395 ) {
V_244 -> V_392 = V_392 ;
V_244 -> V_43 = V_6 -> V_43 ;
F_154 ( V_244 -> V_264 , V_264 ) ;
V_244 -> V_325 = true ;
F_219 ( V_34 , V_12 , V_244 ) ;
} else if ( V_397 ) {
memcpy ( V_244 , V_353 , sizeof( * V_244 ) ) ;
F_221 ( V_12 , V_353 ) ;
} else if ( V_396 ) {
F_222 ( V_353 , V_12 , V_264 , true ) ;
memcpy ( V_244 , V_353 , sizeof( * V_244 ) ) ;
} else {
V_54 = - V_104 ;
}
F_149 ( & V_34 -> V_340 , V_198 ) ;
if ( V_54 )
goto V_398;
V_54 = F_216 ( V_6 , V_12 , V_13 ,
V_244 -> V_389 ,
V_6 -> V_43 -> V_399 ,
V_244 -> V_264 ,
V_6 -> V_9 ,
V_244 -> V_325 ,
V_6 -> V_171 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_21 ,
V_54 , V_244 -> V_389 ) ;
goto V_398;
}
if ( V_395 || V_397 ) {
V_275 = F_217 ( V_244 -> V_389 ) ;
V_54 = F_203 ( V_6 , V_12 ,
V_262 , V_392 ,
F_224 ( 32 ) ,
V_303 , V_252 ,
V_275 , V_13 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 ,
L_22 ,
V_54 , & V_244 -> V_392 , V_275 ) ;
}
V_398:
if ( ! V_395 )
F_19 ( V_12 , V_244 ) ;
return V_54 ;
}
static int F_225 ( struct V_6 * V_6 ,
enum V_11 V_12 , T_10 V_392 )
{
struct V_154 * V_43 = V_6 -> V_43 ;
struct V_400 * V_26 = F_226 ( V_43 , ( V_401 T_5 ) V_392 ) ;
int V_54 = 0 ;
if ( ! V_26 ) {
V_26 = F_227 ( & V_402 , & V_392 , V_43 ) ;
if ( F_228 ( V_26 ) )
return F_228 ( V_26 ) ;
}
if ( V_26 -> V_403 & V_404 )
V_54 = F_223 ( V_6 , V_12 , 0 ,
V_392 , V_26 -> V_405 ) ;
else
F_229 ( V_26 , NULL ) ;
F_230 ( V_26 ) ;
return V_54 ;
}
static int F_231 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_10 V_392 , T_5 * V_389 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_347 * V_244 ;
struct V_347 * V_353 ;
unsigned long V_198 ;
bool V_395 = ! ( V_13 & V_360 ) ;
bool V_396 ;
bool V_397 ;
bool V_406 = true ;
int V_54 = 0 ;
V_244 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_244 ) ) ;
if ( ! V_244 )
return - V_57 ;
F_148 ( & V_34 -> V_340 , V_198 ) ;
V_353 = F_218 ( V_34 , V_392 ) ;
if ( V_353 )
* V_389 = V_353 -> V_389 ;
V_396 = V_353 && V_395 ;
V_397 = V_353 && ! V_395 ;
V_395 = ! V_353 && V_395 ;
if ( V_395 ) {
V_244 -> V_392 = V_392 ;
V_244 -> V_43 = V_6 -> V_43 ;
F_219 ( V_34 , V_12 , V_244 ) ;
* V_389 = V_244 -> V_389 ;
V_406 = false ;
} else if ( V_397 ) {
F_221 ( V_12 , V_353 ) ;
} else if ( V_396 ) {
F_222 ( V_353 , V_12 , NULL , false ) ;
V_406 = ! F_179 ( V_353 -> V_264 ) ;
} else {
V_54 = - V_104 ;
}
F_149 ( & V_34 -> V_340 , V_198 ) ;
if ( ! V_395 )
F_19 ( V_12 , V_244 ) ;
if ( V_54 )
return V_54 ;
if ( ! V_406 )
V_54 = F_225 ( V_6 , V_12 , V_392 ) ;
return V_54 ;
}
static int F_232 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 , T_1 V_1 )
{
struct V_6 * V_407 ;
const struct V_34 * V_34 = V_6 -> V_34 ;
T_5 V_275 = F_233 ( V_1 , 0 ) ;
T_5 * V_319 ;
T_9 V_321 = 0 ;
int V_54 = 0 ;
int V_50 ;
V_319 = F_18 ( V_6 , V_12 , V_13 ,
V_34 -> V_176 , sizeof( T_5 ) ) ;
if ( ! V_319 )
return - V_57 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_407 = V_34 -> V_177 [ V_50 ] ;
if ( ! V_407 )
continue;
if ( ! F_6 ( V_407 ) )
continue;
if ( F_234 ( F_2 ( V_1 ) , V_407 -> V_408 ) ) {
V_319 [ V_321 ++ ] =
F_213 ( V_1 , V_407 -> V_171 ) ;
}
}
if ( V_321 == 0 )
goto V_409;
V_54 = F_215 ( V_6 , V_12 , V_13 , V_1 ,
V_321 , V_319 , V_275 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 ,
L_23 , V_54 ) ;
V_409:
F_19 ( V_12 , V_319 ) ;
return V_54 ;
}
static int F_235 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 , bool V_8 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_6 * V_407 ;
bool V_395 = ! ( V_13 & V_360 ) ;
T_5 V_388 ;
int V_410 = 0 ;
int V_54 ;
int V_50 ;
if ( V_6 -> V_184 == V_185 ||
V_6 -> V_184 == V_186 ) {
V_388 = V_6 -> V_171 ;
V_54 = F_212 ( V_6 , V_12 , V_13 ,
V_1 , V_388 , V_8 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_24 ,
V_54 , V_388 ) ;
return V_54 ;
}
}
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_407 = V_34 -> V_177 [ V_50 ] ;
if ( V_407 && F_234 ( F_2 ( V_1 ) , V_407 -> V_408 ) )
V_410 ++ ;
}
if ( ( ! V_395 || V_410 != 1 ) && ( V_395 || V_410 != 0 ) )
return 0 ;
V_388 = 0 ;
V_54 = F_212 ( V_6 , V_12 , V_13 ,
V_1 , V_388 , V_8 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_25 , V_54 ) ;
return V_54 ;
}
return 0 ;
}
static int F_236 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_411 * V_412 , T_1 V_1 )
{
T_5 V_248 = V_6 -> V_171 ;
T_5 V_250 = 0xffffffff ;
T_5 V_388 = 0 ;
const T_9 * V_283 = NULL ;
const T_9 * V_285 = NULL ;
T_1 V_256 = F_4 ( 0xffff ) ;
T_9 V_289 = 0 ;
T_9 V_291 = 0 ;
T_9 V_293 = 0 ;
T_9 V_295 = 0 ;
T_5 V_275 = F_213 ( V_1 , V_388 ) ;
int V_54 ;
V_54 = F_205 ( V_6 , V_12 , V_13 ,
V_248 , V_250 ,
V_283 , V_285 ,
V_412 -> V_264 , V_412 -> V_266 ,
V_412 -> V_262 ,
V_1 , V_256 ,
V_289 , V_291 ,
V_293 , V_295 ,
V_275 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 , L_26 , V_54 ) ;
return V_54 ;
}
static int F_237 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_411 * V_412 ,
T_1 V_1 )
{
enum V_361 V_252 =
V_311 ;
T_5 V_275 = F_233 ( V_1 , 0 ) ;
T_5 V_279 = 0 ;
int V_54 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_54 = F_201 ( V_6 , V_12 , V_13 ,
V_412 -> V_264 , V_412 -> V_266 ,
V_1 , V_279 ,
V_252 , V_275 , V_412 -> V_267 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 , L_27 , V_54 ) ;
return V_54 ;
}
static int F_238 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_411 * V_412 , T_1 V_1 )
{
T_5 V_250 = 0xffffffff ;
T_1 V_256 = F_4 ( 0xffff ) ;
int V_54 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_54 = F_199 ( V_6 , V_12 ,
V_6 -> V_171 , V_250 ,
V_412 -> V_262 , V_412 -> V_264 ,
V_412 -> V_266 , V_1 ,
V_256 , V_412 -> V_267 ,
V_13 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 , L_28 , V_54 ) ;
return V_54 ;
}
static int F_239 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_411 * V_412 , T_1 V_1 )
{
if ( V_412 -> V_281 )
return F_236 ( V_6 , V_12 , V_13 ,
V_412 , V_1 ) ;
if ( V_412 -> V_276 )
return F_237 ( V_6 , V_12 , V_13 ,
V_412 , V_1 ) ;
if ( V_412 -> V_413 )
return F_238 ( V_6 , V_12 , V_13 ,
V_412 , V_1 ) ;
return - V_114 ;
}
static int F_240 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 )
{
int V_54 = 0 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_414 ; V_50 ++ ) {
if ( V_6 -> V_415 [ V_50 ] ) {
V_54 = F_239 ( V_6 , V_12 , V_13 ,
& V_416 [ V_50 ] , V_1 ) ;
if ( V_54 )
return V_54 ;
}
}
return V_54 ;
}
static int F_241 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_411 * V_412 )
{
T_2 V_7 ;
int V_54 = 0 ;
for ( V_7 = 1 ; V_7 < V_417 ; V_7 ++ ) {
if ( ! F_234 ( V_7 , V_6 -> V_408 ) )
continue;
V_54 = F_239 ( V_6 , V_12 , V_13 ,
V_412 , F_4 ( V_7 ) ) ;
if ( V_54 )
break;
}
return V_54 ;
}
static int F_242 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 , T_2 V_7 )
{
enum V_361 V_252 =
V_308 ;
T_5 V_248 = V_6 -> V_171 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_256 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_257 ;
bool V_395 = ! ( V_13 & V_360 ) ;
int V_54 ;
V_9 = F_3 ( V_6 , V_7 , & V_257 ) ;
if ( V_395 && F_234 ( F_2 ( V_9 ) ,
V_6 -> V_408 ) )
return 0 ;
else if ( ! V_395 && ! F_234 ( F_2 ( V_9 ) ,
V_6 -> V_408 ) )
return 0 ;
F_243 ( F_2 ( V_9 ) , V_6 -> V_408 ) ;
if ( V_395 ) {
V_54 = F_240 ( V_6 , V_12 , V_13 ,
V_9 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_29 , V_54 ) ;
goto V_398;
}
}
V_54 = F_235 ( V_6 , V_12 , V_13 ,
V_9 , V_257 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_30 , V_54 ) ;
goto V_398;
}
V_54 = F_232 ( V_6 , V_12 , V_13 ,
V_9 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_23 , V_54 ) ;
goto V_398;
}
V_54 = F_198 ( V_6 , V_12 , V_13 ,
V_248 , V_1 , V_256 ,
V_252 , V_257 , V_9 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 ,
L_31 , V_54 ) ;
V_398:
if ( V_12 == V_21 )
F_243 ( F_2 ( V_9 ) , V_6 -> V_408 ) ;
return V_54 ;
}
static int F_244 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
enum V_361 V_252 ;
T_5 V_248 ;
T_5 V_250 ;
int V_54 ;
V_248 = 0 ;
V_250 = 0xffff0000 ;
V_252 = V_307 ;
V_54 = F_197 ( V_6 , V_12 , V_13 ,
V_248 , V_250 ,
V_252 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 ,
L_32 , V_54 ) ;
return V_54 ;
}
static void F_245 ( struct V_418 * V_419 )
{
const struct V_420 * V_421 =
F_246 ( V_419 , struct V_420 , V_419 ) ;
bool V_397 = ( V_421 -> V_13 & V_360 ) ;
bool V_422 = ( V_421 -> V_13 & V_180 ) ;
struct V_423 V_121 ;
V_121 . V_179 = V_421 -> V_179 ;
V_121 . V_7 = V_421 -> V_7 ;
if ( V_422 && V_397 )
F_247 ( V_424 ,
V_421 -> V_6 -> V_43 , & V_121 . V_121 ) ;
else if ( V_422 && ! V_397 )
F_247 ( V_425 ,
V_421 -> V_6 -> V_43 , & V_121 . V_121 ) ;
F_19 ( V_421 -> V_12 , V_419 ) ;
}
static int F_248 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const T_9 * V_179 , T_1 V_1 )
{
struct V_420 * V_421 ;
enum V_361 V_252 =
V_311 ;
T_5 V_388 = V_6 -> V_171 ;
T_5 V_279 = 0 ;
T_5 V_275 = V_298 ;
bool V_426 = ! ! ( V_6 -> V_241 & V_427 ) ;
bool V_267 = false ;
int V_54 ;
if ( F_6 ( V_6 ) )
V_275 = F_213 ( V_1 , V_388 ) ;
if ( ! ( V_13 & V_428 ) ) {
V_54 = F_201 ( V_6 , V_12 , V_13 , V_179 ,
NULL , V_1 , V_279 , V_252 ,
V_275 , V_267 ) ;
if ( V_54 )
return V_54 ;
}
if ( ! V_426 )
return 0 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_421 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_421 ) ) ;
if ( ! V_421 )
return - V_57 ;
F_249 ( & V_421 -> V_419 , F_245 ) ;
V_421 -> V_6 = V_6 ;
V_421 -> V_12 = V_12 ;
V_421 -> V_13 = V_13 ;
F_154 ( V_421 -> V_179 , V_179 ) ;
V_421 -> V_7 = F_5 ( V_6 , V_1 ) ;
if ( V_12 == V_21 )
F_19 ( V_12 , V_421 ) ;
else
F_250 ( & V_421 -> V_419 ) ;
return 0 ;
}
static struct V_343 *
F_251 ( const struct V_34 * V_34 ,
const struct V_343 * V_352 )
{
struct V_343 * V_353 ;
F_191 (rocker->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_353 -> V_246 , & V_352 -> V_246 , sizeof( V_353 -> V_246 ) ) == 0 )
return V_353 ;
return NULL ;
}
static int F_141 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const unsigned char * V_179 ,
T_1 V_1 , int V_13 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_343 * V_429 ;
struct V_343 * V_353 ;
bool V_397 = ( V_13 & V_360 ) ;
unsigned long V_198 ;
V_429 = F_17 ( V_6 , V_12 , V_13 , sizeof( * V_429 ) ) ;
if ( ! V_429 )
return - V_57 ;
V_429 -> V_422 = ( V_13 & V_180 ) ;
V_429 -> V_246 . V_171 = V_6 -> V_171 ;
F_154 ( V_429 -> V_246 . V_179 , V_179 ) ;
V_429 -> V_246 . V_1 = V_1 ;
V_429 -> V_355 = F_193 ( ~ 0 , & V_429 -> V_246 , sizeof( V_429 -> V_246 ) ) ;
F_148 ( & V_34 -> V_336 , V_198 ) ;
V_353 = F_251 ( V_34 , V_429 ) ;
if ( V_397 && V_353 ) {
F_19 ( V_12 , V_429 ) ;
if ( V_12 != V_21 )
F_189 ( & V_353 -> V_244 ) ;
} else if ( ! V_397 && ! V_353 ) {
if ( V_12 != V_21 )
F_194 ( V_34 -> V_335 , & V_429 -> V_244 , V_429 -> V_355 ) ;
}
F_149 ( & V_34 -> V_336 , V_198 ) ;
if ( ! V_353 != ! V_397 ) {
F_19 ( V_12 , V_429 ) ;
if ( ! V_353 && V_397 )
return 0 ;
V_13 |= V_428 ;
}
return F_248 ( V_6 , V_12 , V_13 , V_179 , V_1 ) ;
}
static int F_252 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_343 * V_353 ;
unsigned long V_198 ;
struct V_349 * V_350 ;
int V_351 ;
int V_54 = 0 ;
if ( V_6 -> V_184 == V_185 ||
V_6 -> V_184 == V_186 )
return 0 ;
V_13 |= V_360 ;
F_148 ( & V_34 -> V_336 , V_198 ) ;
F_188 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_353 -> V_246 . V_171 != V_6 -> V_171 )
continue;
if ( ! V_353 -> V_422 )
continue;
V_54 = F_248 ( V_6 , V_12 , V_13 ,
V_353 -> V_246 . V_179 ,
V_353 -> V_246 . V_1 ) ;
if ( V_54 )
goto V_398;
if ( V_12 != V_21 )
F_189 ( & V_353 -> V_244 ) ;
}
V_398:
F_149 ( & V_34 -> V_336 , V_198 ) ;
return V_54 ;
}
static int F_253 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 )
{
T_5 V_250 = 0xffffffff ;
T_1 V_262 ;
const T_9 * V_430 = V_370 ;
T_1 V_256 = F_4 ( 0xffff ) ;
bool V_267 = false ;
int V_54 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_262 = F_4 ( V_286 ) ;
V_54 = F_199 ( V_6 , V_12 ,
V_6 -> V_171 , V_250 ,
V_262 , V_6 -> V_43 -> V_399 ,
V_430 , V_1 , V_256 ,
V_267 , V_13 ) ;
if ( V_54 )
return V_54 ;
V_262 = F_4 ( V_287 ) ;
V_54 = F_199 ( V_6 , V_12 ,
V_6 -> V_171 , V_250 ,
V_262 , V_6 -> V_43 -> V_399 ,
V_430 , V_1 , V_256 ,
V_267 , V_13 ) ;
return V_54 ;
}
static int F_254 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
bool V_8 ;
T_5 V_388 ;
T_1 V_1 ;
T_2 V_7 ;
int V_54 ;
if ( V_6 -> V_184 != V_185 &&
V_6 -> V_184 != V_186 )
V_13 |= V_360 ;
V_388 = V_6 -> V_171 ;
for ( V_7 = 1 ; V_7 < V_417 ; V_7 ++ ) {
if ( ! F_234 ( V_7 , V_6 -> V_408 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_54 = F_212 ( V_6 , V_12 , V_13 ,
V_1 , V_388 , V_8 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 ,
L_24 ,
V_54 , V_388 ) ;
return V_54 ;
}
}
return 0 ;
}
static int F_255 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_9 V_431 )
{
bool V_432 [ V_414 ] = { 0 , } ;
bool V_433 [ V_414 ] ;
T_9 V_434 ;
int V_54 ;
int V_50 ;
if ( V_12 == V_21 ) {
memcpy ( V_433 , V_6 -> V_415 , sizeof( V_433 ) ) ;
V_434 = V_6 -> V_184 ;
}
if ( V_6 -> V_184 == V_431 )
return 0 ;
V_6 -> V_184 = V_431 ;
switch ( V_431 ) {
case V_435 :
break;
case V_436 :
case V_437 :
V_432 [ V_438 ] = true ;
break;
case V_185 :
case V_186 :
if ( ! F_8 ( V_6 ) )
V_432 [ V_438 ] = true ;
V_432 [ V_439 ] = true ;
V_432 [ V_440 ] = true ;
if ( F_6 ( V_6 ) )
V_432 [ V_441 ] = true ;
else if ( F_8 ( V_6 ) )
V_432 [ V_442 ] = true ;
else
V_432 [ V_443 ] = true ;
break;
}
for ( V_50 = 0 ; V_50 < V_414 ; V_50 ++ ) {
if ( V_432 [ V_50 ] != V_6 -> V_415 [ V_50 ] ) {
int V_444 = V_13 |
( V_432 [ V_50 ] ? 0 : V_360 ) ;
V_54 = F_241 ( V_6 , V_12 , V_444 ,
& V_416 [ V_50 ] ) ;
if ( V_54 )
goto V_398;
V_6 -> V_415 [ V_50 ] = V_432 [ V_50 ] ;
}
}
V_54 = F_252 ( V_6 , V_12 , V_13 ) ;
if ( V_54 )
goto V_398;
V_54 = F_254 ( V_6 , V_12 , V_13 ) ;
V_398:
if ( V_12 == V_21 ) {
memcpy ( V_6 -> V_415 , V_433 , sizeof( V_433 ) ) ;
V_6 -> V_184 = V_434 ;
}
return V_54 ;
}
static int F_256 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_255 ( V_6 , V_12 , V_13 ,
V_186 ) ;
}
static int F_257 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_255 ( V_6 , V_12 , V_13 ,
V_435 ) ;
}
static struct V_345 *
F_258 ( const struct V_34 * V_34 , int V_445 )
{
struct V_345 * V_353 ;
F_191 (rocker->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_353 -> V_445 == V_445 )
return V_353 ;
}
return NULL ;
}
static T_1 F_259 ( struct V_6 * V_6 ,
int V_445 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_345 * V_244 ;
struct V_345 * V_353 ;
unsigned long V_198 ;
int V_50 ;
V_244 = F_11 ( sizeof( * V_244 ) , V_20 ) ;
if ( ! V_244 )
return 0 ;
V_244 -> V_445 = V_445 ;
F_148 ( & V_34 -> V_338 , V_198 ) ;
V_353 = F_258 ( V_34 , V_445 ) ;
if ( V_353 ) {
F_20 ( V_244 ) ;
goto V_353;
}
V_353 = V_244 ;
F_194 ( V_34 -> V_337 , & V_353 -> V_244 , V_353 -> V_445 ) ;
for ( V_50 = 0 ; V_50 < V_446 ; V_50 ++ ) {
if ( F_260 ( V_50 , V_34 -> V_447 ) )
continue;
V_353 -> V_1 = F_4 ( V_3 + V_50 ) ;
goto V_353;
}
F_126 ( V_6 -> V_43 , L_33 ) ;
V_353:
V_353 -> V_394 ++ ;
F_149 ( & V_34 -> V_338 , V_198 ) ;
return V_353 -> V_1 ;
}
static void
F_261 ( const struct V_6 * V_6 ,
int V_445 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_345 * V_353 ;
unsigned long V_198 ;
unsigned long V_448 ;
F_148 ( & V_34 -> V_338 , V_198 ) ;
V_353 = F_258 ( V_34 , V_445 ) ;
if ( ! V_353 ) {
F_126 ( V_6 -> V_43 ,
L_34 ,
V_445 ) ;
goto V_449;
}
if ( -- V_353 -> V_394 <= 0 ) {
V_448 = F_2 ( V_353 -> V_1 ) - V_3 ;
F_262 ( V_448 , V_34 -> V_447 ) ;
F_189 ( & V_353 -> V_244 ) ;
F_20 ( V_353 ) ;
}
V_449:
F_149 ( & V_34 -> V_338 , V_198 ) ;
}
static int F_263 ( struct V_6 * V_6 ,
enum V_11 V_12 , T_10 V_378 ,
int V_450 , const struct V_451 * V_452 ,
T_5 V_453 , int V_13 )
{
const struct V_454 * V_455 ;
T_1 V_262 = F_4 ( V_286 ) ;
T_10 V_379 = F_224 ( V_450 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_5 V_303 = V_452 -> V_456 ;
enum V_361 V_252 =
V_311 ;
T_5 V_275 ;
bool V_457 ;
bool V_458 ;
T_5 V_389 ;
int V_54 ;
V_455 = V_452 -> V_454 ;
V_457 = ( V_452 -> V_459 == V_6 -> V_43 ) ;
V_458 = ! ! V_455 -> V_460 ;
if ( V_458 && V_457 ) {
V_54 = F_231 ( V_6 , V_12 , V_13 ,
V_455 -> V_460 , & V_389 ) ;
if ( V_54 )
return V_54 ;
V_275 = F_217 ( V_389 ) ;
} else {
V_275 = F_213 ( V_9 , 0 ) ;
}
V_54 = F_203 ( V_6 , V_12 , V_262 , V_378 ,
V_379 , V_303 , V_252 ,
V_275 , V_13 ) ;
if ( V_54 )
F_126 ( V_6 -> V_43 , L_35 ,
V_54 , & V_378 ) ;
return V_54 ;
}
static int F_264 ( struct V_154 * V_43 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
int V_54 ;
V_54 = F_124 ( V_6 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_51 ( F_31 ( V_6 ) ,
F_144 , 0 ,
V_71 , V_6 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_36 ) ;
goto V_461;
}
V_54 = F_51 ( F_33 ( V_6 ) ,
F_146 , 0 ,
V_71 , V_6 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_37 ) ;
goto V_462;
}
V_54 = F_256 ( V_6 , V_25 , 0 ) ;
if ( V_54 )
goto V_463;
F_266 ( & V_6 -> V_192 ) ;
F_266 ( & V_6 -> V_193 ) ;
if ( ! V_43 -> V_464 )
F_129 ( V_6 , true ) ;
F_267 ( V_43 ) ;
return 0 ;
V_463:
V_73 ( F_33 ( V_6 ) , V_6 ) ;
V_462:
V_73 ( F_31 ( V_6 ) , V_6 ) ;
V_461:
F_128 ( V_6 ) ;
return V_54 ;
}
static int F_268 ( struct V_154 * V_43 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
F_269 ( V_43 ) ;
F_129 ( V_6 , false ) ;
F_270 ( & V_6 -> V_193 ) ;
F_270 ( & V_6 -> V_192 ) ;
F_257 ( V_6 , V_25 ,
V_18 ) ;
V_73 ( F_33 ( V_6 ) , V_6 ) ;
V_73 ( F_31 ( V_6 ) , V_6 ) ;
F_128 ( V_6 ) ;
return 0 ;
}
static void F_271 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_38 * V_39 = V_34 -> V_39 ;
const struct V_74 * V_155 [ V_465 + 1 ] ;
struct V_74 * V_230 ;
int V_85 ;
F_69 ( V_155 , V_465 , V_87 ) ;
if ( ! V_155 [ V_466 ] )
return;
F_272 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
const struct V_74 * V_467 [ V_468 + 1 ] ;
T_7 V_47 ;
T_3 V_78 ;
if ( F_58 ( V_230 ) != V_469 )
continue;
F_68 ( V_467 , V_468 ,
V_230 ) ;
if ( ! V_467 [ V_470 ] ||
! V_467 [ V_471 ] )
continue;
V_47 = F_65 ( V_467 [ V_470 ] ) ;
V_78 = F_62 ( V_467 [ V_471 ] ) ;
F_47 ( V_39 , V_47 , V_78 , V_472 ) ;
}
}
static int F_273 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
char * V_48 , T_3 V_83 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_38 * V_39 = V_34 -> V_39 ;
T_7 V_47 ;
struct V_74 * V_473 ;
V_47 = F_44 ( V_39 , V_48 , V_83 , V_472 ) ;
if ( F_72 ( F_45 ( V_39 , V_47 ) ) ) {
if ( F_274 () )
F_126 ( V_6 -> V_43 , L_38 ) ;
return - V_44 ;
}
V_473 = F_79 ( V_87 , V_469 ) ;
if ( ! V_473 )
goto V_474;
if ( F_78 ( V_87 , V_470 ,
V_47 ) )
goto V_475;
if ( F_74 ( V_87 , V_471 ,
V_83 ) )
goto V_475;
F_80 ( V_87 , V_473 ) ;
return 0 ;
V_475:
F_81 ( V_87 , V_473 ) ;
V_474:
F_47 ( V_39 , V_47 , V_83 , V_472 ) ;
return - V_96 ;
}
static T_13 F_275 ( struct V_145 * V_146 , struct V_154 * V_43 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_86 * V_87 ;
struct V_74 * V_476 ;
int V_50 ;
int V_54 ;
V_87 = F_88 ( & V_6 -> V_159 ) ;
if ( F_72 ( ! V_87 ) ) {
if ( F_274 () )
F_126 ( V_43 , L_39 ) ;
return V_477 ;
}
F_87 ( V_87 , V_146 ) ;
V_476 = F_79 ( V_87 , V_466 ) ;
if ( ! V_476 )
goto V_200;
V_54 = F_273 ( V_6 , V_87 ,
V_146 -> V_88 , F_276 ( V_146 ) ) ;
if ( V_54 )
goto V_475;
if ( F_277 ( V_146 ) -> V_478 > V_479 ) {
V_54 = F_278 ( V_146 ) ;
if ( V_54 )
goto V_480;
}
for ( V_50 = 0 ; V_50 < F_277 ( V_146 ) -> V_478 ; V_50 ++ ) {
const T_14 * V_473 = & F_277 ( V_146 ) -> V_476 [ V_50 ] ;
V_54 = F_273 ( V_6 , V_87 ,
F_279 ( V_473 ) ,
F_280 ( V_473 ) ) ;
if ( V_54 )
goto V_480;
}
F_80 ( V_87 , V_476 ) ;
F_84 ( V_87 ) ;
F_90 ( V_34 , & V_6 -> V_159 , V_87 ) ;
V_87 = F_88 ( & V_6 -> V_159 ) ;
if ( ! V_87 )
F_269 ( V_43 ) ;
return V_481 ;
V_480:
F_271 ( V_6 , V_87 ) ;
V_475:
F_81 ( V_87 , V_476 ) ;
V_200:
F_281 ( V_146 ) ;
V_43 -> V_482 . V_483 ++ ;
return V_481 ;
}
static int F_282 ( struct V_154 * V_43 , void * V_407 )
{
struct V_484 * V_179 = V_407 ;
struct V_6 * V_6 = F_265 ( V_43 ) ;
int V_54 ;
if ( ! F_283 ( V_179 -> V_485 ) )
return - V_486 ;
V_54 = F_165 ( V_6 , V_179 -> V_485 ) ;
if ( V_54 )
return V_54 ;
memcpy ( V_43 -> V_399 , V_179 -> V_485 , V_43 -> V_487 ) ;
return 0 ;
}
static int F_284 ( struct V_154 * V_43 , int V_488 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
int V_489 = F_285 ( V_43 ) ;
int V_54 ;
#define F_286 68
#define F_287 9000
if ( V_488 < F_286 || V_488 > F_287 )
return - V_111 ;
if ( V_489 )
F_268 ( V_43 ) ;
F_135 ( V_43 , L_40 , V_43 -> V_150 , V_488 ) ;
V_43 -> V_150 = V_488 ;
V_54 = F_166 ( V_6 , V_488 ) ;
if ( V_54 )
return V_54 ;
if ( V_489 )
V_54 = F_264 ( V_43 ) ;
return V_54 ;
}
static int F_288 ( struct V_154 * V_43 ,
char * V_48 , T_3 V_78 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
struct V_233 V_234 = { . V_48 = V_48 , . V_78 = V_78 } ;
int V_54 ;
V_54 = F_147 ( V_6 , V_25 , 0 ,
F_150 , NULL ,
F_155 ,
& V_234 ) ;
return V_54 ? - V_114 : 0 ;
}
static int F_289 ( struct V_154 * V_43 ,
bool V_464 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
if ( V_6 -> V_43 -> V_13 & V_490 )
F_129 ( V_6 , ! V_464 ) ;
V_6 -> V_43 -> V_464 = V_464 ;
return 0 ;
}
static void F_290 ( struct V_400 * V_26 )
{
struct V_6 * V_6 = F_265 ( V_26 -> V_43 ) ;
int V_13 = V_360 | V_18 ;
T_10 V_392 = * ( T_10 * ) V_26 -> V_491 ;
F_223 ( V_6 , V_25 ,
V_13 , V_392 , V_26 -> V_405 ) ;
}
static int F_291 ( struct V_154 * V_43 ,
struct V_492 * V_230 )
{
const struct V_6 * V_6 = F_265 ( V_43 ) ;
const struct V_34 * V_34 = V_6 -> V_34 ;
switch ( V_230 -> V_493 ) {
case V_494 :
V_230 -> V_495 . V_496 . V_497 = sizeof( V_34 -> V_498 . V_493 ) ;
memcpy ( & V_230 -> V_495 . V_496 . V_493 , & V_34 -> V_498 . V_493 , V_230 -> V_495 . V_496 . V_497 ) ;
break;
case V_499 :
V_230 -> V_495 . V_241 = V_6 -> V_241 ;
break;
default:
return - V_114 ;
}
return 0 ;
}
static void F_292 ( const struct V_6 * V_6 )
{
struct V_15 * V_27 , * V_350 ;
F_293 (mem, tmp, &rocker_port->trans_mem) {
F_294 ( V_27 ) ;
F_20 ( V_27 ) ;
}
}
static int F_295 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
unsigned long V_241 )
{
unsigned long V_500 ;
int V_54 = 0 ;
V_500 = V_6 -> V_241 ;
V_6 -> V_241 = V_241 ;
if ( ( V_500 ^ V_6 -> V_241 ) & V_242 )
V_54 = F_167 ( V_6 , V_12 ) ;
if ( V_12 == V_21 )
V_6 -> V_241 = V_500 ;
return V_54 ;
}
static int F_296 ( struct V_154 * V_43 ,
struct V_492 * V_230 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
int V_54 = 0 ;
switch ( V_230 -> V_12 ) {
case V_21 :
F_13 ( ! F_14 ( & V_6 -> V_22 ) ) ;
break;
case V_501 :
F_292 ( V_6 ) ;
return 0 ;
default:
break;
}
switch ( V_230 -> V_493 ) {
case V_502 :
V_54 = F_255 ( V_6 , V_230 -> V_12 ,
V_18 ,
V_230 -> V_495 . V_184 ) ;
break;
case V_499 :
V_54 = F_295 ( V_6 , V_230 -> V_12 ,
V_230 -> V_495 . V_241 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_297 ( struct V_6 * V_6 ,
enum V_11 V_12 , T_2 V_7 , T_2 V_13 )
{
int V_54 ;
V_54 = F_242 ( V_6 , V_12 , 0 , V_7 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_253 ( V_6 , V_12 , 0 , F_4 ( V_7 ) ) ;
if ( V_54 )
F_242 ( V_6 , V_12 ,
V_360 , V_7 ) ;
return V_54 ;
}
static int F_298 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const struct V_503 * V_253 )
{
T_2 V_7 ;
int V_54 ;
for ( V_7 = V_253 -> V_504 ; V_7 <= V_253 -> V_505 ; V_7 ++ ) {
V_54 = F_297 ( V_6 , V_12 ,
V_7 , V_253 -> V_13 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_299 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const struct V_506 * V_429 )
{
T_1 V_1 = F_3 ( V_6 , V_429 -> V_7 , NULL ) ;
int V_13 = 0 ;
if ( ! F_6 ( V_6 ) )
return - V_111 ;
return F_141 ( V_6 , V_12 , V_429 -> V_179 , V_1 , V_13 ) ;
}
static int F_300 ( struct V_154 * V_43 ,
struct V_507 * V_508 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
const struct V_509 * V_510 ;
int V_54 = 0 ;
switch ( V_508 -> V_12 ) {
case V_21 :
F_13 ( ! F_14 ( & V_6 -> V_22 ) ) ;
break;
case V_501 :
F_292 ( V_6 ) ;
return 0 ;
default:
break;
}
switch ( V_508 -> V_493 ) {
case V_511 :
V_54 = F_298 ( V_6 , V_508 -> V_12 ,
& V_508 -> V_495 . V_253 ) ;
break;
case V_512 :
V_510 = & V_508 -> V_495 . V_513 ;
V_54 = F_263 ( V_6 , V_508 -> V_12 ,
F_301 ( V_510 -> V_378 ) , V_510 -> V_450 ,
V_510 -> V_452 , V_510 -> V_453 , 0 ) ;
break;
case V_514 :
V_54 = F_299 ( V_6 , V_508 -> V_12 , & V_508 -> V_495 . V_429 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_302 ( struct V_6 * V_6 ,
T_2 V_7 , T_2 V_13 )
{
int V_54 ;
V_54 = F_253 ( V_6 , V_25 ,
V_360 , F_4 ( V_7 ) ) ;
if ( V_54 )
return V_54 ;
return F_242 ( V_6 , V_25 ,
V_360 , V_7 ) ;
}
static int F_303 ( struct V_6 * V_6 ,
const struct V_503 * V_253 )
{
T_2 V_7 ;
int V_54 ;
for ( V_7 = V_253 -> V_504 ; V_7 <= V_253 -> V_505 ; V_7 ++ ) {
V_54 = F_302 ( V_6 , V_7 , V_253 -> V_13 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_304 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const struct V_506 * V_429 )
{
T_1 V_1 = F_3 ( V_6 , V_429 -> V_7 , NULL ) ;
int V_13 = V_18 | V_360 ;
if ( ! F_6 ( V_6 ) )
return - V_111 ;
return F_141 ( V_6 , V_12 , V_429 -> V_179 , V_1 , V_13 ) ;
}
static int F_305 ( struct V_154 * V_43 ,
struct V_507 * V_508 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
const struct V_509 * V_510 ;
int V_54 = 0 ;
switch ( V_508 -> V_493 ) {
case V_511 :
V_54 = F_303 ( V_6 , & V_508 -> V_495 . V_253 ) ;
break;
case V_512 :
V_510 = & V_508 -> V_495 . V_513 ;
V_54 = F_263 ( V_6 , V_25 ,
F_301 ( V_510 -> V_378 ) , V_510 -> V_450 ,
V_510 -> V_452 , V_510 -> V_453 ,
V_360 ) ;
break;
case V_514 :
V_54 = F_304 ( V_6 , V_508 -> V_12 , & V_508 -> V_495 . V_429 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_306 ( const struct V_6 * V_6 ,
struct V_507 * V_508 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_506 * V_429 = & V_508 -> V_495 . V_429 ;
struct V_343 * V_353 ;
struct V_349 * V_350 ;
unsigned long V_198 ;
int V_351 ;
int V_54 = 0 ;
F_148 ( & V_34 -> V_336 , V_198 ) ;
F_188 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_353 -> V_246 . V_171 != V_6 -> V_171 )
continue;
V_429 -> V_179 = V_353 -> V_246 . V_179 ;
V_429 -> V_515 = V_516 ;
V_429 -> V_7 = F_5 ( V_6 ,
V_353 -> V_246 . V_1 ) ;
V_54 = V_508 -> V_517 ( V_6 -> V_43 , V_508 ) ;
if ( V_54 )
break;
}
F_149 ( & V_34 -> V_336 , V_198 ) ;
return V_54 ;
}
static int F_307 ( const struct V_6 * V_6 ,
struct V_507 * V_508 )
{
struct V_503 * V_253 = & V_508 -> V_495 . V_253 ;
T_2 V_7 ;
int V_54 = 0 ;
for ( V_7 = 1 ; V_7 < V_417 ; V_7 ++ ) {
if ( ! F_234 ( V_7 , V_6 -> V_408 ) )
continue;
V_253 -> V_13 = 0 ;
if ( F_1 ( F_4 ( V_7 ) ) )
V_253 -> V_13 |= V_518 ;
V_253 -> V_504 = V_253 -> V_505 = V_7 ;
V_54 = V_508 -> V_517 ( V_6 -> V_43 , V_508 ) ;
if ( V_54 )
break;
}
return V_54 ;
}
static int F_308 ( struct V_154 * V_43 ,
struct V_507 * V_508 )
{
const struct V_6 * V_6 = F_265 ( V_43 ) ;
int V_54 = 0 ;
switch ( V_508 -> V_493 ) {
case V_514 :
V_54 = F_306 ( V_6 , V_508 ) ;
break;
case V_511 :
V_54 = F_307 ( V_6 , V_508 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_309 ( struct V_154 * V_43 ,
struct V_207 * V_208 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
return F_162 ( V_6 , V_208 ) ;
}
static int F_310 ( struct V_154 * V_43 ,
struct V_207 * V_208 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
return F_164 ( V_6 , V_208 ) ;
}
static void F_311 ( struct V_154 * V_43 ,
struct V_519 * V_520 )
{
F_312 ( V_520 -> V_521 , V_71 , sizeof( V_520 -> V_521 ) ) ;
F_312 ( V_520 -> V_522 , V_523 , sizeof( V_520 -> V_522 ) ) ;
}
static void F_313 ( struct V_154 * V_524 , T_5 V_525 ,
T_9 * V_88 )
{
T_9 * V_407 = V_88 ;
int V_50 ;
switch ( V_525 ) {
case V_526 :
for ( V_50 = 0 ; V_50 < F_314 ( V_527 ) ; V_50 ++ ) {
memcpy ( V_407 , V_527 [ V_50 ] . V_236 , V_528 ) ;
V_407 += V_528 ;
}
break;
}
}
static int
F_315 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_74 * V_529 ;
if ( F_74 ( V_87 , V_203 ,
V_530 ) )
return - V_96 ;
V_529 = F_79 ( V_87 , V_205 ) ;
if ( ! V_529 )
return - V_96 ;
if ( F_76 ( V_87 , V_531 ,
V_6 -> V_171 ) )
return - V_96 ;
F_80 ( V_87 , V_529 ) ;
return 0 ;
}
static int
F_316 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
const struct V_74 * V_155 [ V_209 + 1 ] ;
const struct V_74 * V_532 [ V_533 + 1 ] ;
const struct V_74 * V_534 ;
T_5 V_171 ;
T_6 * V_88 = V_201 ;
int V_50 ;
F_69 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_68 ( V_532 , V_533 ,
V_155 [ V_205 ] ) ;
if ( ! V_532 [ V_531 ] )
return - V_44 ;
V_171 = F_64 ( V_532 [ V_531 ] ) ;
if ( V_171 != V_6 -> V_171 )
return - V_44 ;
for ( V_50 = 0 ; V_50 < F_314 ( V_527 ) ; V_50 ++ ) {
V_534 = V_532 [ V_527 [ V_50 ] . type ] ;
if ( ! V_534 )
continue;
V_88 [ V_50 ] = F_65 ( V_534 ) ;
}
return 0 ;
}
static int F_317 ( struct V_6 * V_6 ,
void * V_201 )
{
return F_147 ( V_6 , V_25 , 0 ,
F_315 , NULL ,
F_316 ,
V_201 ) ;
}
static void F_318 ( struct V_154 * V_43 ,
struct V_535 * V_482 , T_6 * V_88 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
if ( F_317 ( V_6 , V_88 ) != 0 ) {
int V_50 ;
for ( V_50 = 0 ; V_50 < F_314 ( V_527 ) ; ++ V_50 )
V_88 [ V_50 ] = 0 ;
}
}
static int F_319 ( struct V_154 * V_524 , int V_536 )
{
switch ( V_536 ) {
case V_526 :
return V_537 ;
default:
return - V_114 ;
}
}
static struct V_6 * F_320 ( struct V_538 * V_539 )
{
return F_246 ( V_539 , struct V_6 , V_192 ) ;
}
static int F_321 ( struct V_538 * V_539 , int V_540 )
{
struct V_6 * V_6 = F_320 ( V_539 ) ;
const struct V_34 * V_34 = V_6 -> V_34 ;
const struct V_86 * V_87 ;
T_5 V_124 = 0 ;
int V_54 ;
while ( ( V_87 = F_92 ( & V_6 -> V_159 ) ) ) {
struct V_145 * V_146 ;
V_54 = F_83 ( V_87 ) ;
if ( V_54 && F_274 () )
F_126 ( V_6 -> V_43 , L_41 ,
V_54 ) ;
F_271 ( V_6 , V_87 ) ;
V_146 = F_86 ( V_87 ) ;
if ( V_54 == 0 ) {
V_6 -> V_43 -> V_482 . V_541 ++ ;
V_6 -> V_43 -> V_482 . V_542 += V_146 -> V_78 ;
} else {
V_6 -> V_43 -> V_482 . V_543 ++ ;
}
F_119 ( V_146 ) ;
V_124 ++ ;
}
if ( V_124 && F_322 ( V_6 -> V_43 ) )
F_323 ( V_6 -> V_43 ) ;
F_324 ( V_539 ) ;
F_93 ( V_34 , & V_6 -> V_159 , V_124 ) ;
return 0 ;
}
static int F_325 ( const struct V_34 * V_34 ,
const struct V_6 * V_6 ,
struct V_86 * V_87 )
{
const struct V_74 * V_155 [ V_156 + 1 ] ;
struct V_145 * V_146 = F_86 ( V_87 ) ;
T_3 V_544 ;
T_2 V_545 = 0 ;
if ( ! V_146 )
return - V_104 ;
F_69 ( V_155 , V_156 , V_87 ) ;
if ( ! V_155 [ V_546 ] )
return - V_111 ;
if ( V_155 [ V_547 ] )
V_545 = F_62 ( V_155 [ V_547 ] ) ;
F_120 ( V_34 , V_155 ) ;
V_544 = F_62 ( V_155 [ V_546 ] ) ;
F_326 ( V_146 , V_544 ) ;
V_146 -> V_548 = F_327 ( V_146 , V_6 -> V_43 ) ;
if ( V_545 & V_549 )
V_146 -> V_550 = V_6 -> V_43 -> V_550 ;
V_6 -> V_43 -> V_482 . V_551 ++ ;
V_6 -> V_43 -> V_482 . V_552 += V_146 -> V_78 ;
F_328 ( V_146 ) ;
return F_117 ( V_6 , V_87 ) ;
}
static struct V_6 * F_329 ( struct V_538 * V_539 )
{
return F_246 ( V_539 , struct V_6 , V_193 ) ;
}
static int F_330 ( struct V_538 * V_539 , int V_540 )
{
struct V_6 * V_6 = F_329 ( V_539 ) ;
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_86 * V_87 ;
T_5 V_124 = 0 ;
int V_54 ;
while ( V_124 < V_540 &&
( V_87 = F_92 ( & V_6 -> V_157 ) ) ) {
V_54 = F_83 ( V_87 ) ;
if ( V_54 ) {
if ( F_274 () )
F_126 ( V_6 -> V_43 , L_42 ,
V_54 ) ;
} else {
V_54 = F_325 ( V_34 , V_6 ,
V_87 ) ;
if ( V_54 && F_274 () )
F_126 ( V_6 -> V_43 , L_43 ,
V_54 ) ;
}
if ( V_54 )
V_6 -> V_43 -> V_482 . V_553 ++ ;
F_84 ( V_87 ) ;
F_90 ( V_34 , & V_6 -> V_157 , V_87 ) ;
V_124 ++ ;
}
if ( V_124 < V_540 )
F_324 ( V_539 ) ;
F_93 ( V_34 , & V_6 -> V_157 , V_124 ) ;
return V_124 ;
}
static void F_331 ( const struct V_6 * V_6 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
T_6 V_554 = F_41 ( V_34 , V_555 ) ;
bool V_173 ;
V_173 = V_554 & ( 1 << V_6 -> V_171 ) ;
if ( V_173 )
F_134 ( V_6 -> V_43 ) ;
else
F_137 ( V_6 -> V_43 ) ;
}
static void F_332 ( const struct V_34 * V_34 )
{
struct V_6 * V_6 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_6 = V_34 -> V_177 [ V_50 ] ;
if ( ! V_6 )
continue;
F_244 ( V_6 , V_25 ,
V_360 ) ;
F_333 ( V_6 -> V_43 ) ;
F_334 ( V_6 -> V_43 ) ;
}
F_20 ( V_34 -> V_177 ) ;
}
static void F_335 ( struct V_6 * V_6 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
const struct V_38 * V_39 = V_34 -> V_39 ;
int V_54 ;
V_54 = F_163 ( V_6 ,
V_6 -> V_43 -> V_399 ) ;
if ( V_54 ) {
F_336 ( & V_39 -> V_43 , L_44 ) ;
F_337 ( V_6 -> V_43 ) ;
}
}
static int F_338 ( struct V_34 * V_34 , unsigned int V_37 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
struct V_6 * V_6 ;
struct V_154 * V_43 ;
T_2 V_556 = 0 ;
int V_54 ;
V_43 = F_339 ( sizeof( struct V_6 ) ) ;
if ( ! V_43 )
return - V_57 ;
V_6 = F_265 ( V_43 ) ;
V_6 -> V_43 = V_43 ;
V_6 -> V_34 = V_34 ;
V_6 -> V_37 = V_37 ;
V_6 -> V_171 = V_37 + 1 ;
V_6 -> V_241 = V_242 | V_427 ;
F_16 ( & V_6 -> V_22 ) ;
F_335 ( V_6 ) ;
V_43 -> V_557 = & V_558 ;
V_43 -> V_559 = & V_560 ;
V_43 -> V_561 = & V_562 ;
F_340 ( V_43 , & V_6 -> V_192 , F_321 ,
V_563 ) ;
F_340 ( V_43 , & V_6 -> V_193 , F_330 ,
V_563 ) ;
F_331 ( V_6 ) ;
V_43 -> V_564 |= V_565 | V_566 ;
V_54 = F_341 ( V_43 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_45 ) ;
goto V_567;
}
V_34 -> V_177 [ V_37 ] = V_6 ;
F_342 ( V_6 -> V_43 , NULL , false ) ;
F_167 ( V_6 , V_25 ) ;
V_54 = F_244 ( V_6 , V_25 , 0 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_46 ) ;
goto V_568;
}
V_6 -> V_9 =
F_259 ( V_6 , V_43 -> V_445 ) ;
V_54 = F_297 ( V_6 , V_25 ,
V_556 , 0 ) ;
if ( V_54 ) {
F_126 ( V_6 -> V_43 , L_47 ) ;
goto V_569;
}
return 0 ;
V_569:
F_244 ( V_6 , V_25 ,
V_360 ) ;
V_568:
V_34 -> V_177 [ V_37 ] = NULL ;
F_333 ( V_43 ) ;
V_567:
F_334 ( V_43 ) ;
return V_54 ;
}
static int F_343 ( struct V_34 * V_34 )
{
int V_50 ;
T_3 V_570 ;
int V_54 ;
V_570 = sizeof( struct V_6 * ) * V_34 -> V_176 ;
V_34 -> V_177 = F_11 ( V_570 , V_20 ) ;
if ( ! V_34 -> V_177 )
return - V_57 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_54 = F_338 ( V_34 , V_50 ) ;
if ( V_54 )
goto V_571;
}
return 0 ;
V_571:
F_332 ( V_34 ) ;
return V_54 ;
}
static int F_344 ( struct V_34 * V_34 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
int V_36 ;
int V_50 ;
int V_54 ;
V_36 = F_345 ( V_39 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 != F_346 ( V_34 -> V_176 ) )
return - V_111 ;
V_34 -> V_36 = F_347 ( V_36 ,
sizeof( struct V_572 ) ,
V_20 ) ;
if ( ! V_34 -> V_36 )
return - V_57 ;
for ( V_50 = 0 ; V_50 < V_36 ; V_50 ++ )
V_34 -> V_36 [ V_50 ] . V_244 = V_50 ;
V_54 = F_348 ( V_39 , V_34 -> V_36 , V_36 ) ;
if ( V_54 < 0 )
goto V_573;
return 0 ;
V_573:
F_20 ( V_34 -> V_36 ) ;
return V_54 ;
}
static void F_349 ( const struct V_34 * V_34 )
{
F_350 ( V_34 -> V_39 ) ;
F_20 ( V_34 -> V_36 ) ;
}
static int F_351 ( struct V_38 * V_39 , const struct V_574 * V_493 )
{
struct V_34 * V_34 ;
int V_54 ;
V_34 = F_11 ( sizeof( * V_34 ) , V_20 ) ;
if ( ! V_34 )
return - V_57 ;
V_54 = F_352 ( V_39 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_48 ) ;
goto V_575;
}
V_54 = F_353 ( V_39 , V_71 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_49 ) ;
goto V_576;
}
V_54 = F_354 ( V_39 , F_355 ( 64 ) ) ;
if ( ! V_54 ) {
V_54 = F_356 ( V_39 , F_355 ( 64 ) ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_50 ) ;
goto V_577;
}
} else {
V_54 = F_354 ( V_39 , F_355 ( 32 ) ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_51 ) ;
goto V_577;
}
}
if ( F_357 ( V_39 , 0 ) < V_578 ) {
F_39 ( & V_39 -> V_43 , L_52 ) ;
V_54 = - V_111 ;
goto V_579;
}
V_34 -> V_580 = F_358 ( F_359 ( V_39 , 0 ) ,
F_357 ( V_39 , 0 ) ) ;
if ( ! V_34 -> V_580 ) {
F_39 ( & V_39 -> V_43 , L_53 ) ;
V_54 = - V_44 ;
goto V_581;
}
F_360 ( V_39 ) ;
V_34 -> V_39 = V_39 ;
F_361 ( V_39 , V_34 ) ;
V_34 -> V_176 = F_38 ( V_34 , V_582 ) ;
V_54 = F_344 ( V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_54 ) ;
goto V_583;
}
V_54 = F_50 ( V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_55 ) ;
goto V_584;
}
F_37 ( V_34 , V_585 , V_586 ) ;
V_54 = F_112 ( V_34 ) ;
if ( V_54 )
goto V_587;
V_54 = F_51 ( F_30 ( V_34 , V_588 ) ,
F_130 , 0 ,
V_71 , V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_56 ) ;
goto V_589;
}
V_54 = F_51 ( F_30 ( V_34 , V_590 ) ,
F_143 , 0 ,
V_71 , V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_57 ) ;
goto V_591;
}
V_34 -> V_498 . V_493 = F_41 ( V_34 , V_592 ) ;
V_54 = F_185 ( V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_58 ) ;
goto V_593;
}
V_54 = F_343 ( V_34 ) ;
if ( V_54 ) {
F_39 ( & V_39 -> V_43 , L_59 ) ;
goto V_594;
}
F_362 ( & V_39 -> V_43 , L_60 ,
( int ) sizeof( V_34 -> V_498 . V_493 ) , & V_34 -> V_498 . V_493 ) ;
return 0 ;
V_594:
F_187 ( V_34 ) ;
V_593:
V_73 ( F_30 ( V_34 , V_590 ) , V_34 ) ;
V_591:
V_73 ( F_30 ( V_34 , V_588 ) , V_34 ) ;
V_589:
F_114 ( V_34 ) ;
V_587:
V_584:
F_349 ( V_34 ) ;
V_583:
F_363 ( V_34 -> V_580 ) ;
V_581:
V_579:
V_577:
F_364 ( V_39 ) ;
V_576:
F_365 ( V_39 ) ;
V_575:
F_20 ( V_34 ) ;
return V_54 ;
}
static void F_366 ( struct V_38 * V_39 )
{
struct V_34 * V_34 = F_367 ( V_39 ) ;
F_187 ( V_34 ) ;
F_37 ( V_34 , V_585 , V_586 ) ;
F_332 ( V_34 ) ;
V_73 ( F_30 ( V_34 , V_590 ) , V_34 ) ;
V_73 ( F_30 ( V_34 , V_588 ) , V_34 ) ;
F_114 ( V_34 ) ;
F_349 ( V_34 ) ;
F_363 ( V_34 -> V_580 ) ;
F_364 ( V_34 -> V_39 ) ;
F_365 ( V_34 -> V_39 ) ;
F_20 ( V_34 ) ;
}
static bool F_368 ( const struct V_154 * V_43 )
{
return V_43 -> V_557 == & V_558 ;
}
static int F_369 ( struct V_6 * V_6 ,
struct V_154 * V_276 )
{
T_2 V_556 = 0 ;
int V_54 ;
V_54 = F_302 ( V_6 , V_556 , 0 ) ;
if ( V_54 )
return V_54 ;
F_261 ( V_6 ,
V_6 -> V_43 -> V_445 ) ;
V_6 -> V_9 =
F_259 ( V_6 , V_276 -> V_445 ) ;
V_6 -> V_10 = V_276 ;
F_342 ( V_6 -> V_43 , V_276 , true ) ;
return F_297 ( V_6 , V_25 ,
V_556 , 0 ) ;
}
static int F_370 ( struct V_6 * V_6 )
{
T_2 V_556 = 0 ;
int V_54 ;
V_54 = F_302 ( V_6 , V_556 , 0 ) ;
if ( V_54 )
return V_54 ;
F_261 ( V_6 ,
V_6 -> V_10 -> V_445 ) ;
V_6 -> V_9 =
F_259 ( V_6 ,
V_6 -> V_43 -> V_445 ) ;
F_342 ( V_6 -> V_43 , V_6 -> V_10 ,
false ) ;
V_6 -> V_10 = NULL ;
V_54 = F_297 ( V_6 , V_25 ,
V_556 , 0 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_43 -> V_13 & V_490 )
V_54 = F_256 ( V_6 ,
V_25 , 0 ) ;
return V_54 ;
}
static int F_371 ( struct V_6 * V_6 ,
struct V_154 * V_595 )
{
int V_54 ;
V_6 -> V_10 = V_595 ;
V_54 = F_257 ( V_6 , V_25 , 0 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_256 ( V_6 , V_25 , 0 ) ;
return V_54 ;
}
static int F_372 ( struct V_6 * V_6 ,
struct V_154 * V_595 )
{
int V_54 = 0 ;
if ( F_7 ( V_595 ) )
V_54 = F_369 ( V_6 , V_595 ) ;
else if ( F_9 ( V_595 ) )
V_54 = F_371 ( V_6 , V_595 ) ;
return V_54 ;
}
static int F_373 ( struct V_6 * V_6 )
{
int V_54 = 0 ;
if ( F_6 ( V_6 ) )
V_54 = F_370 ( V_6 ) ;
else if ( F_8 ( V_6 ) )
V_54 = F_371 ( V_6 , NULL ) ;
return V_54 ;
}
static int F_374 ( struct V_596 * V_597 ,
unsigned long V_598 , void * V_119 )
{
struct V_154 * V_43 = F_375 ( V_119 ) ;
struct V_599 * V_121 ;
struct V_6 * V_6 ;
int V_54 ;
if ( ! F_368 ( V_43 ) )
return V_600 ;
switch ( V_598 ) {
case V_601 :
V_121 = V_119 ;
if ( ! V_121 -> V_595 )
goto V_200;
V_6 = F_265 ( V_43 ) ;
if ( V_121 -> V_602 ) {
V_54 = F_372 ( V_6 ,
V_121 -> V_603 ) ;
if ( V_54 )
F_376 ( V_43 , L_61 ,
V_54 ) ;
} else {
V_54 = F_373 ( V_6 ) ;
if ( V_54 )
F_376 ( V_43 , L_62 ,
V_54 ) ;
}
break;
}
V_200:
return V_600 ;
}
static int F_377 ( struct V_154 * V_43 , struct V_400 * V_26 )
{
struct V_6 * V_6 = F_265 ( V_43 ) ;
int V_13 = ( V_26 -> V_403 & V_404 ? 0 : V_360 ) |
V_18 ;
T_10 V_392 = * ( T_10 * ) V_26 -> V_491 ;
return F_223 ( V_6 , V_25 ,
V_13 , V_392 , V_26 -> V_405 ) ;
}
static int F_378 ( struct V_596 * V_597 ,
unsigned long V_598 , void * V_119 )
{
struct V_154 * V_43 ;
struct V_400 * V_26 = V_119 ;
int V_54 ;
switch ( V_598 ) {
case V_604 :
if ( V_26 -> V_605 != & V_402 )
return V_600 ;
V_43 = V_26 -> V_43 ;
if ( ! F_368 ( V_43 ) )
return V_600 ;
V_54 = F_377 ( V_43 , V_26 ) ;
if ( V_54 )
F_376 ( V_43 ,
L_63 ,
V_54 ) ;
break;
}
return V_600 ;
}
static int T_15 F_379 ( void )
{
int V_54 ;
F_380 ( & V_606 ) ;
F_381 ( & V_607 ) ;
V_54 = F_382 ( & V_608 ) ;
if ( V_54 )
goto V_609;
return 0 ;
V_609:
F_383 ( & V_607 ) ;
F_384 ( & V_606 ) ;
return V_54 ;
}
static void T_16 F_385 ( void )
{
F_383 ( & V_607 ) ;
F_384 ( & V_606 ) ;
F_386 ( & V_608 ) ;
}
