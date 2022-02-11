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
return ! ! V_6 -> V_10 ;
}
static void * F_7 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_3 V_14 )
{
struct V_15 * V_16 = NULL ;
T_4 V_17 = ( V_13 & V_18 ) ?
V_19 : V_20 ;
switch ( V_12 ) {
case V_21 :
V_16 = F_8 ( V_14 + sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
F_9 ( V_16 , & V_6 -> V_22 ) ;
break;
case V_23 :
F_10 ( F_11 ( & V_6 -> V_22 ) ) ;
V_16 = V_6 -> V_22 . V_24 ;
F_12 ( V_16 ) ;
break;
case V_25 :
V_16 = F_8 ( V_14 + sizeof( * V_16 ) , V_17 ) ;
if ( V_16 )
F_13 ( V_16 ) ;
break;
default:
break;
}
return V_16 ? V_16 + 1 : NULL ;
}
static void * F_14 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_3 V_14 )
{
return F_7 ( V_6 , V_12 , V_13 , V_14 ) ;
}
static void * F_15 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_3 V_26 , T_3 V_14 )
{
return F_7 ( V_6 , V_12 , V_13 , V_26 * V_14 ) ;
}
static void F_16 ( enum V_11 V_12 , const void * V_27 )
{
struct V_15 * V_16 ;
if ( V_12 == V_21 )
return;
V_16 = (struct V_15 * ) V_27 - 1 ;
F_10 ( ! F_11 ( V_16 ) ) ;
F_17 ( V_16 ) ;
}
static void F_18 ( struct V_28 * V_29 )
{
V_29 -> V_30 = false ;
V_29 -> V_31 = false ;
}
static void F_19 ( struct V_28 * V_29 )
{
F_20 ( & V_29 -> V_29 ) ;
F_18 ( V_29 ) ;
}
static struct V_28 * F_21 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 )
{
struct V_28 * V_29 ;
V_29 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return NULL ;
F_19 ( V_29 ) ;
return V_29 ;
}
static void F_22 ( enum V_11 V_12 ,
struct V_28 * V_29 )
{
F_16 ( V_12 , V_29 ) ;
}
static bool F_23 ( struct V_28 * V_29 ,
unsigned long V_32 )
{
F_24 ( V_29 -> V_29 , V_29 -> V_30 , V_33 / 10 ) ;
if ( ! V_29 -> V_30 )
return false ;
return true ;
}
static void F_25 ( struct V_28 * V_29 )
{
V_29 -> V_30 = true ;
F_26 ( & V_29 -> V_29 ) ;
}
static T_5 F_27 ( const struct V_34 * V_34 , unsigned int V_35 )
{
return V_34 -> V_36 [ V_35 ] . V_35 ;
}
static T_5 F_28 ( const struct V_6 * V_6 )
{
return F_27 ( V_6 -> V_34 ,
F_29 ( V_6 -> V_37 ) ) ;
}
static T_5 F_30 ( const struct V_6 * V_6 )
{
return F_27 ( V_6 -> V_34 ,
F_31 ( V_6 -> V_37 ) ) ;
}
static int F_32 ( const struct V_34 * V_34 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
T_6 V_40 ;
T_6 V_41 ;
V_41 = F_33 () ;
V_41 >>= 1 ;
F_34 ( V_34 , V_42 , V_41 ) ;
V_40 = F_35 ( V_34 , V_42 ) ;
if ( V_40 != V_41 * 2 ) {
F_36 ( & V_39 -> V_43 , L_1 ,
V_40 , V_41 * 2 ) ;
return - V_44 ;
}
V_41 = F_33 () ;
V_41 <<= 31 ;
V_41 |= F_33 () ;
F_37 ( V_34 , V_45 , V_41 ) ;
V_40 = F_38 ( V_34 , V_45 ) ;
if ( V_40 != V_41 * 2 ) {
F_36 ( & V_39 -> V_43 , L_2 ,
V_40 , V_41 * 2 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_39 ( const struct V_34 * V_34 ,
struct V_28 * V_29 , T_5 V_46 ,
T_7 V_47 , const unsigned char * V_48 ,
const unsigned char * V_49 , T_3 V_14 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
int V_50 ;
F_18 ( V_29 ) ;
F_34 ( V_34 , V_51 , V_46 ) ;
if ( ! F_23 ( V_29 , V_33 / 10 ) ) {
F_36 ( & V_39 -> V_43 , L_3 ) ;
return - V_44 ;
}
for ( V_50 = 0 ; V_50 < V_14 ; V_50 ++ ) {
if ( V_48 [ V_50 ] != V_49 [ V_50 ] ) {
F_36 ( & V_39 -> V_43 , L_4 ,
V_48 [ V_50 ] , V_50 , V_49 [ V_50 ] ) ;
return - V_44 ;
}
}
return 0 ;
}
static int F_40 ( const struct V_34 * V_34 ,
struct V_28 * V_29 , int V_52 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
unsigned char * V_53 ;
unsigned char * V_48 ;
unsigned char * V_49 ;
T_7 V_47 ;
int V_50 ;
int V_54 ;
V_53 = F_8 ( V_55 * 2 + V_52 ,
V_20 | V_56 ) ;
if ( ! V_53 )
return - V_57 ;
V_48 = V_53 + V_52 ;
V_49 = V_48 + V_55 ;
V_47 = F_41 ( V_39 , V_48 , V_55 ,
V_58 ) ;
if ( F_42 ( V_39 , V_47 ) ) {
V_54 = - V_44 ;
goto V_59;
}
F_37 ( V_34 , V_60 , V_47 ) ;
F_34 ( V_34 , V_61 , V_55 ) ;
memset ( V_49 , V_62 , V_55 ) ;
V_54 = F_39 ( V_34 , V_29 , V_63 ,
V_47 , V_48 , V_49 ,
V_55 ) ;
if ( V_54 )
goto V_64;
memset ( V_49 , 0 , V_55 ) ;
V_54 = F_39 ( V_34 , V_29 , V_65 ,
V_47 , V_48 , V_49 ,
V_55 ) ;
if ( V_54 )
goto V_64;
F_43 ( V_48 , V_55 ) ;
for ( V_50 = 0 ; V_50 < V_55 ; V_50 ++ )
V_49 [ V_50 ] = ~ V_48 [ V_50 ] ;
V_54 = F_39 ( V_34 , V_29 , V_66 ,
V_47 , V_48 , V_49 ,
V_55 ) ;
if ( V_54 )
goto V_64;
V_64:
F_44 ( V_39 , V_47 , V_55 ,
V_58 ) ;
V_59:
F_17 ( V_53 ) ;
return V_54 ;
}
static int F_45 ( const struct V_34 * V_34 ,
struct V_28 * V_29 )
{
int V_50 ;
int V_54 ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
V_54 = F_40 ( V_34 , V_29 , V_50 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static T_8 F_46 ( int V_67 , void * V_68 )
{
struct V_28 * V_29 = V_68 ;
F_25 ( V_29 ) ;
return V_69 ;
}
static int F_47 ( const struct V_34 * V_34 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
struct V_28 V_29 ;
int V_54 ;
V_54 = F_32 ( V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_5 ) ;
return V_54 ;
}
V_54 = F_48 ( F_27 ( V_34 , V_70 ) ,
F_46 , 0 ,
V_71 , & V_29 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_6 ) ;
return V_54 ;
}
F_19 ( & V_29 ) ;
F_34 ( V_34 , V_72 , V_70 ) ;
if ( ! F_23 ( & V_29 , V_33 / 10 ) ) {
F_36 ( & V_39 -> V_43 , L_3 ) ;
V_54 = - V_44 ;
goto V_73;
}
V_54 = F_45 ( V_34 , & V_29 ) ;
if ( V_54 )
F_36 ( & V_39 -> V_43 , L_7 ) ;
V_73:
V_73 ( F_27 ( V_34 , V_70 ) , & V_29 ) ;
return V_54 ;
}
static struct V_74 * F_49 ( const struct V_74 * V_75 ,
int * V_76 )
{
int V_77 = F_50 ( V_75 -> V_78 ) ;
* V_76 -= V_77 ;
return (struct V_74 * ) ( ( char * ) V_75 + V_77 ) ;
}
static int F_51 ( const struct V_74 * V_75 , int V_76 )
{
return V_76 >= ( int ) V_79 &&
V_75 -> V_78 >= V_79 &&
V_75 -> V_78 <= V_76 ;
}
static int F_52 ( int V_80 )
{
return V_79 + V_80 ;
}
static int F_53 ( int V_80 )
{
return F_50 ( F_52 ( V_80 ) ) ;
}
static int F_54 ( int V_80 )
{
return F_53 ( V_80 ) - F_52 ( V_80 ) ;
}
static int F_55 ( const struct V_74 * V_75 )
{
return V_75 -> type ;
}
static void * F_56 ( const struct V_74 * V_75 )
{
return ( char * ) V_75 + V_79 ;
}
static int F_57 ( const struct V_74 * V_75 )
{
return V_75 -> V_78 - V_79 ;
}
static T_9 F_58 ( const struct V_74 * V_75 )
{
return * ( T_9 * ) F_56 ( V_75 ) ;
}
static T_2 F_59 ( const struct V_74 * V_75 )
{
return * ( T_2 * ) F_56 ( V_75 ) ;
}
static T_1 F_60 ( const struct V_74 * V_75 )
{
return * ( T_1 * ) F_56 ( V_75 ) ;
}
static T_5 F_61 ( const struct V_74 * V_75 )
{
return * ( T_5 * ) F_56 ( V_75 ) ;
}
static T_6 F_62 ( const struct V_74 * V_75 )
{
return * ( T_6 * ) F_56 ( V_75 ) ;
}
static void F_63 ( const struct V_74 * * V_81 , int V_82 ,
const char * V_48 , int V_83 )
{
const struct V_74 * V_75 ;
const struct V_74 * V_84 = ( const struct V_74 * ) V_48 ;
int V_85 ;
memset ( V_81 , 0 , sizeof( struct V_74 * ) * ( V_82 + 1 ) ) ;
F_64 (tlv, head, buf_len, rem) {
T_5 type = F_55 ( V_75 ) ;
if ( type > 0 && type <= V_82 )
V_81 [ type ] = V_75 ;
}
}
static void F_65 ( const struct V_74 * * V_81 , int V_82 ,
const struct V_74 * V_75 )
{
F_63 ( V_81 , V_82 , F_56 ( V_75 ) ,
F_57 ( V_75 ) ) ;
}
static void F_66 ( const struct V_74 * * V_81 , int V_82 ,
const struct V_86 * V_87 )
{
F_63 ( V_81 , V_82 , V_87 -> V_88 ,
V_87 -> V_89 -> V_90 ) ;
}
static struct V_74 * F_67 ( struct V_86 * V_87 )
{
return (struct V_74 * ) ( ( char * ) V_87 -> V_88 +
V_87 -> V_90 ) ;
}
static int F_68 ( struct V_86 * V_87 ,
int V_91 , int V_92 , const void * V_88 )
{
int V_93 = V_87 -> V_94 - V_87 -> V_90 ;
int V_95 = F_53 ( V_92 ) ;
struct V_74 * V_75 ;
if ( F_69 ( V_93 < V_95 ) )
return - V_96 ;
V_75 = F_67 ( V_87 ) ;
V_87 -> V_90 += V_95 ;
V_75 -> type = V_91 ;
V_75 -> V_78 = F_52 ( V_92 ) ;
memcpy ( F_56 ( V_75 ) , V_88 , V_92 ) ;
memset ( ( char * ) V_75 + V_75 -> V_78 , 0 , F_54 ( V_92 ) ) ;
return 0 ;
}
static int F_70 ( struct V_86 * V_87 ,
int V_91 , T_9 V_97 )
{
return F_68 ( V_87 , V_91 , sizeof( T_9 ) , & V_97 ) ;
}
static int F_71 ( struct V_86 * V_87 ,
int V_91 , T_2 V_97 )
{
return F_68 ( V_87 , V_91 , sizeof( T_2 ) , & V_97 ) ;
}
static int F_72 ( struct V_86 * V_87 ,
int V_91 , T_1 V_97 )
{
return F_68 ( V_87 , V_91 , sizeof( T_1 ) , & V_97 ) ;
}
static int F_73 ( struct V_86 * V_87 ,
int V_91 , T_5 V_97 )
{
return F_68 ( V_87 , V_91 , sizeof( T_5 ) , & V_97 ) ;
}
static int F_74 ( struct V_86 * V_87 ,
int V_91 , T_10 V_97 )
{
return F_68 ( V_87 , V_91 , sizeof( T_10 ) , & V_97 ) ;
}
static int F_75 ( struct V_86 * V_87 ,
int V_91 , T_6 V_97 )
{
return F_68 ( V_87 , V_91 , sizeof( T_6 ) , & V_97 ) ;
}
static struct V_74 *
F_76 ( struct V_86 * V_87 , int V_91 )
{
struct V_74 * V_2 = F_67 ( V_87 ) ;
if ( F_68 ( V_87 , V_91 , 0 , NULL ) < 0 )
return NULL ;
return V_2 ;
}
static void F_77 ( struct V_86 * V_87 ,
struct V_74 * V_2 )
{
V_2 -> V_78 = ( char * ) F_67 ( V_87 ) - ( char * ) V_2 ;
}
static void F_78 ( struct V_86 * V_87 ,
const struct V_74 * V_2 )
{
V_87 -> V_90 = ( const char * ) V_2 - V_87 -> V_88 ;
}
static T_5 F_79 ( T_5 V_98 , T_3 V_99 )
{
return ++ V_98 == V_99 ? 0 : V_98 ;
}
static int F_80 ( const struct V_86 * V_87 )
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
static void F_81 ( const struct V_86 * V_87 )
{
V_87 -> V_89 -> V_100 &= ~ V_101 ;
}
static bool F_82 ( const struct V_86 * V_87 )
{
T_5 V_100 = V_87 -> V_89 -> V_100 ;
return V_100 & V_101 ? true : false ;
}
static void * F_83 ( const struct V_86 * V_87 )
{
return ( void * ) ( V_117 ) V_87 -> V_89 -> V_118 ;
}
static void F_84 ( const struct V_86 * V_87 ,
void * V_119 )
{
V_87 -> V_89 -> V_118 = ( V_117 ) V_119 ;
}
static struct V_86 *
F_85 ( const struct V_120 * V_121 )
{
static struct V_86 * V_87 ;
T_5 V_84 = F_79 ( V_121 -> V_84 , V_121 -> V_14 ) ;
V_87 = & V_121 -> V_87 [ V_121 -> V_84 ] ;
if ( V_84 == V_121 -> V_122 )
return NULL ;
V_87 -> V_90 = 0 ;
return V_87 ;
}
static void F_86 ( const struct V_86 * V_87 )
{
V_87 -> V_89 -> V_123 = V_87 -> V_94 ;
V_87 -> V_89 -> V_90 = V_87 -> V_90 ;
}
static void F_87 ( const struct V_34 * V_34 ,
struct V_120 * V_121 ,
const struct V_86 * V_87 )
{
T_5 V_84 = F_79 ( V_121 -> V_84 , V_121 -> V_14 ) ;
F_10 ( V_84 == V_121 -> V_122 ) ;
F_86 ( V_87 ) ;
V_121 -> V_84 = V_84 ;
F_34 ( V_34 , F_88 ( V_121 -> type ) , V_84 ) ;
}
static struct V_86 *
F_89 ( struct V_120 * V_121 )
{
static struct V_86 * V_87 ;
if ( V_121 -> V_122 == V_121 -> V_84 )
return NULL ;
V_87 = & V_121 -> V_87 [ V_121 -> V_122 ] ;
if ( ! F_82 ( V_87 ) )
return NULL ;
V_121 -> V_122 = F_79 ( V_121 -> V_122 , V_121 -> V_14 ) ;
V_87 -> V_90 = V_87 -> V_89 -> V_90 ;
return V_87 ;
}
static void F_90 ( const struct V_34 * V_34 ,
const struct V_120 * V_121 ,
T_5 V_124 )
{
if ( V_124 )
F_34 ( V_34 , F_91 ( V_121 -> type ) , V_124 ) ;
}
static unsigned long F_92 ( T_3 V_14 )
{
return F_93 ( V_125 ,
F_94 ( F_95 ( V_14 ) , V_126 ) ) ;
}
static int F_96 ( const struct V_34 * V_34 ,
unsigned int type ,
T_3 V_14 ,
struct V_120 * V_121 )
{
int V_50 ;
F_10 ( V_14 != F_92 ( V_14 ) ) ;
V_121 -> V_14 = V_14 ;
V_121 -> type = type ;
V_121 -> V_84 = 0 ;
V_121 -> V_122 = 0 ;
V_121 -> V_87 = F_97 ( V_121 -> V_14 , sizeof( * V_121 -> V_87 ) ,
V_20 ) ;
if ( ! V_121 -> V_87 )
return - V_57 ;
V_121 -> V_89 = F_98 ( V_34 -> V_39 ,
V_121 -> V_14 * sizeof( * V_121 -> V_89 ) ,
& V_121 -> V_127 ) ;
if ( ! V_121 -> V_89 ) {
F_17 ( V_121 -> V_87 ) ;
return - V_57 ;
}
for ( V_50 = 0 ; V_50 < V_121 -> V_14 ; V_50 ++ )
V_121 -> V_87 [ V_50 ] . V_89 = & V_121 -> V_89 [ V_50 ] ;
F_34 ( V_34 , F_99 ( V_121 -> type ) ,
V_128 ) ;
F_37 ( V_34 , F_100 ( V_121 -> type ) , V_121 -> V_127 ) ;
F_34 ( V_34 , F_101 ( V_121 -> type ) , V_121 -> V_14 ) ;
return 0 ;
}
static void F_102 ( const struct V_34 * V_34 ,
const struct V_120 * V_121 )
{
F_37 ( V_34 , F_100 ( V_121 -> type ) , 0 ) ;
F_103 ( V_34 -> V_39 ,
V_121 -> V_14 * sizeof( struct V_129 ) ,
V_121 -> V_89 , V_121 -> V_127 ) ;
F_17 ( V_121 -> V_87 ) ;
}
static void F_104 ( const struct V_34 * V_34 ,
struct V_120 * V_121 )
{
int V_50 ;
F_10 ( V_121 -> V_84 || V_121 -> V_122 ) ;
for ( V_50 = 0 ; V_50 < V_121 -> V_14 - 1 ; V_50 ++ )
F_87 ( V_34 , V_121 , & V_121 -> V_87 [ V_50 ] ) ;
F_86 ( & V_121 -> V_87 [ V_50 ] ) ;
}
static int F_105 ( const struct V_34 * V_34 ,
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
V_48 = F_8 ( V_123 , V_20 | V_56 ) ;
if ( ! V_48 ) {
V_54 = - V_57 ;
goto V_131;
}
V_47 = F_41 ( V_39 , V_48 , V_123 , V_130 ) ;
if ( F_42 ( V_39 , V_47 ) ) {
F_17 ( V_48 ) ;
V_54 = - V_44 ;
goto V_131;
}
V_87 -> V_88 = V_48 ;
V_87 -> V_94 = V_123 ;
F_106 ( V_87 , V_127 , V_47 ) ;
V_89 -> V_132 = V_47 ;
V_89 -> V_123 = V_123 ;
}
return 0 ;
V_131:
for ( V_50 -- ; V_50 >= 0 ; V_50 -- ) {
const struct V_86 * V_87 = & V_121 -> V_87 [ V_50 ] ;
F_44 ( V_39 , F_107 ( V_87 , V_127 ) ,
V_87 -> V_94 , V_130 ) ;
F_17 ( V_87 -> V_88 ) ;
}
return V_54 ;
}
static void F_108 ( const struct V_34 * V_34 ,
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
F_44 ( V_39 , F_107 ( V_87 , V_127 ) ,
V_87 -> V_94 , V_130 ) ;
F_17 ( V_87 -> V_88 ) ;
}
}
static int F_109 ( struct V_34 * V_34 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
int V_54 ;
V_54 = F_96 ( V_34 , V_133 ,
V_134 ,
& V_34 -> V_135 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_8 ) ;
return V_54 ;
}
F_110 ( & V_34 -> V_136 ) ;
V_54 = F_105 ( V_34 , & V_34 -> V_135 ,
V_58 , V_137 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_9 ) ;
goto V_138;
}
V_54 = F_96 ( V_34 , V_139 ,
V_140 ,
& V_34 -> V_141 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_10 ) ;
goto V_142;
}
V_54 = F_105 ( V_34 , & V_34 -> V_141 ,
V_143 , V_137 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_11 ) ;
goto V_144;
}
F_104 ( V_34 , & V_34 -> V_141 ) ;
return 0 ;
V_144:
F_102 ( V_34 , & V_34 -> V_141 ) ;
V_142:
F_108 ( V_34 , & V_34 -> V_135 ,
V_58 ) ;
V_138:
F_102 ( V_34 , & V_34 -> V_135 ) ;
return V_54 ;
}
static void F_111 ( struct V_34 * V_34 )
{
F_108 ( V_34 , & V_34 -> V_141 ,
V_58 ) ;
F_102 ( V_34 , & V_34 -> V_141 ) ;
F_108 ( V_34 , & V_34 -> V_135 ,
V_58 ) ;
F_102 ( V_34 , & V_34 -> V_135 ) ;
}
static int F_112 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
struct V_145 * V_146 , T_3 V_83 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_38 * V_39 = V_34 -> V_39 ;
T_7 V_47 ;
V_47 = F_41 ( V_39 , V_146 -> V_88 , V_83 ,
V_143 ) ;
if ( F_42 ( V_39 , V_47 ) )
return - V_44 ;
if ( F_75 ( V_87 , V_147 , V_47 ) )
goto V_148;
if ( F_71 ( V_87 , V_149 , V_83 ) )
goto V_148;
return 0 ;
V_148:
F_44 ( V_39 , V_47 , V_83 , V_143 ) ;
V_87 -> V_90 = 0 ;
return - V_96 ;
}
static T_3 F_113 ( const struct V_6 * V_6 )
{
return V_6 -> V_43 -> V_150 + V_151 + V_152 + V_153 ;
}
static int F_114 ( const struct V_6 * V_6 ,
struct V_86 * V_87 )
{
struct V_154 * V_43 = V_6 -> V_43 ;
struct V_145 * V_146 ;
T_3 V_83 = F_113 ( V_6 ) ;
int V_54 ;
F_84 ( V_87 , NULL ) ;
V_87 -> V_90 = 0 ;
V_146 = F_115 ( V_43 , V_83 ) ;
if ( ! V_146 )
return - V_57 ;
V_54 = F_112 ( V_6 , V_87 , V_146 , V_83 ) ;
if ( V_54 ) {
F_116 ( V_146 ) ;
return V_54 ;
}
F_84 ( V_87 , V_146 ) ;
return 0 ;
}
static void F_117 ( const struct V_34 * V_34 ,
const struct V_74 * * V_155 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
T_7 V_47 ;
T_3 V_78 ;
if ( ! V_155 [ V_147 ] ||
! V_155 [ V_149 ] )
return;
V_47 = F_62 ( V_155 [ V_147 ] ) ;
V_78 = F_59 ( V_155 [ V_149 ] ) ;
F_44 ( V_39 , V_47 , V_78 , V_143 ) ;
}
static void F_118 ( const struct V_34 * V_34 ,
const struct V_86 * V_87 )
{
const struct V_74 * V_155 [ V_156 + 1 ] ;
struct V_145 * V_146 = F_83 ( V_87 ) ;
if ( ! V_146 )
return;
F_66 ( V_155 , V_156 , V_87 ) ;
F_117 ( V_34 , V_155 ) ;
F_116 ( V_146 ) ;
}
static int F_119 ( const struct V_6 * V_6 )
{
const struct V_120 * V_157 = & V_6 -> V_157 ;
const struct V_34 * V_34 = V_6 -> V_34 ;
int V_50 ;
int V_54 ;
for ( V_50 = 0 ; V_50 < V_157 -> V_14 ; V_50 ++ ) {
V_54 = F_114 ( V_6 ,
& V_157 -> V_87 [ V_50 ] ) ;
if ( V_54 )
goto V_131;
}
return 0 ;
V_131:
for ( V_50 -- ; V_50 >= 0 ; V_50 -- )
F_118 ( V_34 , & V_157 -> V_87 [ V_50 ] ) ;
return V_54 ;
}
static void F_120 ( const struct V_6 * V_6 )
{
const struct V_120 * V_157 = & V_6 -> V_157 ;
const struct V_34 * V_34 = V_6 -> V_34 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_157 -> V_14 ; V_50 ++ )
F_118 ( V_34 , & V_157 -> V_87 [ V_50 ] ) ;
}
static int F_121 ( struct V_6 * V_6 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
int V_54 ;
V_54 = F_96 ( V_34 ,
F_122 ( V_6 -> V_37 ) ,
V_158 ,
& V_6 -> V_159 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_12 ) ;
return V_54 ;
}
V_54 = F_105 ( V_34 , & V_6 -> V_159 ,
V_160 ,
V_161 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_13 ) ;
goto V_162;
}
V_54 = F_96 ( V_34 ,
F_124 ( V_6 -> V_37 ) ,
V_163 ,
& V_6 -> V_157 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_14 ) ;
goto V_164;
}
V_54 = F_105 ( V_34 , & V_6 -> V_157 ,
V_58 ,
V_165 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_15 ) ;
goto V_166;
}
V_54 = F_119 ( V_6 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_16 ) ;
goto V_167;
}
F_104 ( V_34 , & V_6 -> V_157 ) ;
return 0 ;
V_167:
F_108 ( V_34 , & V_6 -> V_157 ,
V_58 ) ;
V_166:
F_102 ( V_34 , & V_6 -> V_157 ) ;
V_164:
F_108 ( V_34 , & V_6 -> V_159 ,
V_160 ) ;
V_162:
F_102 ( V_34 , & V_6 -> V_159 ) ;
return V_54 ;
}
static void F_125 ( struct V_6 * V_6 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
F_120 ( V_6 ) ;
F_108 ( V_34 , & V_6 -> V_157 ,
V_58 ) ;
F_102 ( V_34 , & V_6 -> V_157 ) ;
F_108 ( V_34 , & V_6 -> V_159 ,
V_160 ) ;
F_102 ( V_34 , & V_6 -> V_159 ) ;
}
static void F_126 ( const struct V_6 * V_6 ,
bool V_168 )
{
T_6 V_169 = F_38 ( V_6 -> V_34 , V_170 ) ;
if ( V_168 )
V_169 |= 1ULL << V_6 -> V_171 ;
else
V_169 &= ~ ( 1ULL << V_6 -> V_171 ) ;
F_37 ( V_6 -> V_34 , V_170 , V_169 ) ;
}
static T_8 F_127 ( int V_67 , void * V_68 )
{
struct V_34 * V_34 = V_68 ;
const struct V_86 * V_87 ;
struct V_28 * V_29 ;
T_5 V_124 = 0 ;
F_128 ( & V_34 -> V_136 ) ;
while ( ( V_87 = F_89 ( & V_34 -> V_135 ) ) ) {
V_29 = F_83 ( V_87 ) ;
if ( V_29 -> V_31 ) {
F_81 ( V_87 ) ;
F_22 ( V_25 , V_29 ) ;
} else {
F_25 ( V_29 ) ;
}
V_124 ++ ;
}
F_129 ( & V_34 -> V_136 ) ;
F_90 ( V_34 , & V_34 -> V_135 , V_124 ) ;
return V_69 ;
}
static void F_130 ( const struct V_6 * V_6 )
{
F_131 ( V_6 -> V_43 ) ;
F_132 ( V_6 -> V_43 , L_17 ) ;
}
static void F_133 ( const struct V_6 * V_6 )
{
F_134 ( V_6 -> V_43 ) ;
F_132 ( V_6 -> V_43 , L_18 ) ;
}
static int F_135 ( const struct V_34 * V_34 ,
const struct V_74 * V_121 )
{
const struct V_74 * V_155 [ V_172 + 1 ] ;
unsigned int V_37 ;
bool V_173 ;
struct V_6 * V_6 ;
F_65 ( V_155 , V_172 , V_121 ) ;
if ( ! V_155 [ V_174 ] ||
! V_155 [ V_175 ] )
return - V_44 ;
V_37 =
F_61 ( V_155 [ V_174 ] ) - 1 ;
V_173 = F_58 ( V_155 [ V_175 ] ) ;
if ( V_37 >= V_34 -> V_176 )
return - V_111 ;
V_6 = V_34 -> V_177 [ V_37 ] ;
if ( F_136 ( V_6 -> V_43 ) != V_173 ) {
if ( V_173 )
F_130 ( V_6 ) ;
else
F_133 ( V_6 ) ;
}
return 0 ;
}
static int F_137 ( const struct V_34 * V_34 ,
const struct V_74 * V_121 )
{
const struct V_74 * V_155 [ V_178 + 1 ] ;
unsigned int V_37 ;
struct V_6 * V_6 ;
const unsigned char * V_179 ;
int V_13 = V_18 | V_180 ;
T_1 V_1 ;
F_65 ( V_155 , V_178 , V_121 ) ;
if ( ! V_155 [ V_181 ] ||
! V_155 [ V_182 ] ||
! V_155 [ V_183 ] )
return - V_44 ;
V_37 =
F_61 ( V_155 [ V_181 ] ) - 1 ;
V_179 = F_56 ( V_155 [ V_182 ] ) ;
V_1 = F_60 ( V_155 [ V_183 ] ) ;
if ( V_37 >= V_34 -> V_176 )
return - V_111 ;
V_6 = V_34 -> V_177 [ V_37 ] ;
if ( V_6 -> V_184 != V_185 &&
V_6 -> V_184 != V_186 )
return 0 ;
return F_138 ( V_6 , V_25 ,
V_179 , V_1 , V_13 ) ;
}
static int F_139 ( const struct V_34 * V_34 ,
const struct V_86 * V_87 )
{
const struct V_74 * V_155 [ V_187 + 1 ] ;
const struct V_74 * V_121 ;
T_2 type ;
F_66 ( V_155 , V_187 , V_87 ) ;
if ( ! V_155 [ V_188 ] ||
! V_155 [ V_189 ] )
return - V_44 ;
type = F_59 ( V_155 [ V_188 ] ) ;
V_121 = V_155 [ V_189 ] ;
switch ( type ) {
case V_190 :
return F_135 ( V_34 , V_121 ) ;
case V_191 :
return F_137 ( V_34 , V_121 ) ;
}
return - V_114 ;
}
static T_8 F_140 ( int V_67 , void * V_68 )
{
struct V_34 * V_34 = V_68 ;
const struct V_38 * V_39 = V_34 -> V_39 ;
const struct V_86 * V_87 ;
T_5 V_124 = 0 ;
int V_54 ;
while ( ( V_87 = F_89 ( & V_34 -> V_141 ) ) ) {
V_54 = F_80 ( V_87 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_19 ,
V_54 ) ;
} else {
V_54 = F_139 ( V_34 , V_87 ) ;
if ( V_54 )
F_36 ( & V_39 -> V_43 , L_20 ,
V_54 ) ;
}
F_81 ( V_87 ) ;
F_87 ( V_34 , & V_34 -> V_141 , V_87 ) ;
V_124 ++ ;
}
F_90 ( V_34 , & V_34 -> V_141 , V_124 ) ;
return V_69 ;
}
static T_8 F_141 ( int V_67 , void * V_68 )
{
struct V_6 * V_6 = V_68 ;
F_142 ( & V_6 -> V_192 ) ;
return V_69 ;
}
static T_8 F_143 ( int V_67 , void * V_68 )
{
struct V_6 * V_6 = V_68 ;
F_142 ( & V_6 -> V_193 ) ;
return V_69 ;
}
static int F_144 ( struct V_6 * V_6 ,
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
V_29 = F_21 ( V_6 , V_12 , V_13 ) ;
if ( ! V_29 )
return - V_57 ;
V_29 -> V_31 = V_31 ;
F_145 ( & V_34 -> V_136 , V_198 ) ;
V_87 = F_85 ( & V_34 -> V_135 ) ;
if ( ! V_87 ) {
F_146 ( & V_34 -> V_136 , V_198 ) ;
V_54 = - V_199 ;
goto V_200;
}
V_54 = V_194 ( V_6 , V_87 , V_195 ) ;
if ( V_54 ) {
F_146 ( & V_34 -> V_136 , V_198 ) ;
goto V_200;
}
F_84 ( V_87 , V_29 ) ;
if ( V_12 != V_21 )
F_87 ( V_34 , & V_34 -> V_135 , V_87 ) ;
F_146 ( & V_34 -> V_136 , V_198 ) ;
if ( V_31 )
return 0 ;
if ( V_12 != V_21 )
if ( ! F_23 ( V_29 , V_33 / 10 ) )
return - V_44 ;
V_54 = F_80 ( V_87 ) ;
if ( V_54 )
return V_54 ;
if ( V_196 )
V_54 = V_196 ( V_6 , V_87 , V_197 ) ;
F_81 ( V_87 ) ;
V_200:
F_22 ( V_12 , V_29 ) ;
return V_54 ;
}
static int
F_147 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_74 * V_202 ;
if ( F_71 ( V_87 , V_203 ,
V_204 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_73 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_148 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
struct V_207 * V_208 = V_201 ;
const struct V_74 * V_155 [ V_209 + 1 ] ;
const struct V_74 * V_210 [ V_211 + 1 ] ;
T_5 V_212 ;
T_9 V_213 ;
T_9 V_214 ;
F_66 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_65 ( V_210 , V_211 ,
V_155 [ V_205 ] ) ;
if ( ! V_210 [ V_215 ] ||
! V_210 [ V_216 ] ||
! V_210 [ V_217 ] )
return - V_44 ;
V_212 = F_61 ( V_210 [ V_215 ] ) ;
V_213 = F_58 ( V_210 [ V_216 ] ) ;
V_214 = F_58 ( V_210 [ V_217 ] ) ;
V_208 -> V_218 = V_219 ;
V_208 -> V_220 = V_221 ;
V_208 -> V_222 = 0xff ;
V_208 -> V_223 = V_224 ;
F_149 ( V_208 , V_212 ) ;
V_208 -> V_213 = V_213 ? V_225 : V_226 ;
V_208 -> V_214 = V_214 ? V_227 : V_228 ;
return 0 ;
}
static int
F_150 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
unsigned char * V_229 = V_201 ;
const struct V_74 * V_155 [ V_209 + 1 ] ;
const struct V_74 * V_210 [ V_211 + 1 ] ;
const struct V_74 * V_230 ;
F_66 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_65 ( V_210 , V_211 ,
V_155 [ V_205 ] ) ;
V_230 = V_210 [ V_231 ] ;
if ( ! V_230 )
return - V_44 ;
if ( F_57 ( V_230 ) != V_232 )
return - V_111 ;
F_151 ( V_229 , F_56 ( V_230 ) ) ;
return 0 ;
}
static int
F_152 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
const struct V_74 * V_210 [ V_211 + 1 ] ;
const struct V_74 * V_155 [ V_209 + 1 ] ;
struct V_233 * V_234 = V_201 ;
const struct V_74 * V_230 ;
T_3 V_50 , V_235 , V_78 ;
const char * V_236 ;
F_66 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_65 ( V_210 , V_211 ,
V_155 [ V_205 ] ) ;
V_230 = V_210 [ V_237 ] ;
if ( ! V_230 )
return - V_44 ;
V_78 = F_153 ( T_3 , F_57 ( V_230 ) , V_234 -> V_78 ) ;
V_236 = F_56 ( V_230 ) ;
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
F_154 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_207 * V_208 = V_201 ;
struct V_74 * V_202 ;
if ( F_71 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_73 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_215 ,
F_155 ( V_208 ) ) )
return - V_96 ;
if ( F_70 ( V_87 , V_216 ,
V_208 -> V_213 ) )
return - V_96 ;
if ( F_70 ( V_87 , V_217 ,
V_208 -> V_214 ) )
return - V_96 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_156 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const unsigned char * V_229 = V_201 ;
struct V_74 * V_202 ;
if ( F_71 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_73 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_231 ,
V_232 , V_229 ) )
return - V_96 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_157 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_74 * V_202 ;
if ( F_71 ( V_87 , V_203 ,
V_238 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_73 ( V_87 , V_206 ,
V_6 -> V_171 ) )
return - V_96 ;
if ( F_70 ( V_87 , V_239 ,
! ! ( V_6 -> V_240 & V_241 ) ) )
return - V_96 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_158 ( struct V_6 * V_6 ,
struct V_207 * V_208 )
{
return F_144 ( V_6 , V_25 , 0 ,
F_147 , NULL ,
F_148 ,
V_208 ) ;
}
static int F_159 ( struct V_6 * V_6 ,
unsigned char * V_229 )
{
return F_144 ( V_6 , V_25 , 0 ,
F_147 , NULL ,
F_150 ,
V_229 ) ;
}
static int F_160 ( struct V_6 * V_6 ,
struct V_207 * V_208 )
{
return F_144 ( V_6 , V_25 , 0 ,
F_154 ,
V_208 , NULL , NULL ) ;
}
static int F_161 ( struct V_6 * V_6 ,
unsigned char * V_229 )
{
return F_144 ( V_6 , V_25 , 0 ,
F_156 ,
V_229 , NULL , NULL ) ;
}
static int F_162 ( struct V_6 * V_6 ,
enum V_11 V_12 )
{
return F_144 ( V_6 , V_12 , 0 ,
F_157 ,
NULL , NULL , NULL ) ;
}
static int
F_163 ( struct V_86 * V_87 ,
const struct V_242 * V_243 )
{
if ( F_73 ( V_87 , V_244 ,
V_243 -> V_245 . V_246 . V_247 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_248 ,
V_243 -> V_245 . V_246 . V_249 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_250 ,
V_243 -> V_245 . V_246 . V_251 ) )
return - V_96 ;
return 0 ;
}
static int
F_164 ( struct V_86 * V_87 ,
const struct V_242 * V_243 )
{
if ( F_73 ( V_87 , V_244 ,
V_243 -> V_245 . V_252 . V_247 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_253 ,
V_243 -> V_245 . V_252 . V_1 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_254 ,
V_243 -> V_245 . V_252 . V_255 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_250 ,
V_243 -> V_245 . V_252 . V_251 ) )
return - V_96 ;
if ( V_243 -> V_245 . V_252 . V_256 &&
F_72 ( V_87 , V_257 ,
V_243 -> V_245 . V_252 . V_258 ) )
return - V_96 ;
return 0 ;
}
static int
F_165 ( struct V_86 * V_87 ,
const struct V_242 * V_243 )
{
if ( F_73 ( V_87 , V_244 ,
V_243 -> V_245 . V_259 . V_247 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_248 ,
V_243 -> V_245 . V_259 . V_249 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_260 ,
V_243 -> V_245 . V_259 . V_261 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_262 ,
V_232 , V_243 -> V_245 . V_259 . V_263 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_264 ,
V_232 , V_243 -> V_245 . V_259 . V_265 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_253 ,
V_243 -> V_245 . V_259 . V_1 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_254 ,
V_243 -> V_245 . V_259 . V_255 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_250 ,
V_243 -> V_245 . V_259 . V_251 ) )
return - V_96 ;
if ( V_243 -> V_245 . V_259 . V_266 &&
F_70 ( V_87 , V_267 ,
V_243 -> V_245 . V_259 . V_266 ) )
return - V_96 ;
return 0 ;
}
static int
F_166 ( struct V_86 * V_87 ,
const struct V_242 * V_243 )
{
if ( F_72 ( V_87 , V_260 ,
V_243 -> V_245 . V_268 . V_261 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_269 ,
V_243 -> V_245 . V_268 . V_270 ) )
return - V_96 ;
if ( F_74 ( V_87 , V_271 ,
V_243 -> V_245 . V_268 . V_272 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_250 ,
V_243 -> V_245 . V_268 . V_251 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_273 ,
V_243 -> V_245 . V_268 . V_274 ) )
return - V_96 ;
return 0 ;
}
static int
F_167 ( struct V_86 * V_87 ,
const struct V_242 * V_243 )
{
if ( V_243 -> V_245 . V_275 . V_276 &&
F_68 ( V_87 , V_262 ,
V_232 , V_243 -> V_245 . V_275 . V_263 ) )
return - V_96 ;
if ( V_243 -> V_245 . V_275 . V_277 &&
F_68 ( V_87 , V_264 ,
V_232 , V_243 -> V_245 . V_275 . V_265 ) )
return - V_96 ;
if ( V_243 -> V_245 . V_275 . V_1 &&
F_72 ( V_87 , V_253 ,
V_243 -> V_245 . V_275 . V_1 ) )
return - V_96 ;
if ( V_243 -> V_245 . V_275 . V_278 &&
F_73 ( V_87 , V_279 ,
V_243 -> V_245 . V_275 . V_278 ) )
return - V_96 ;
if ( F_71 ( V_87 , V_250 ,
V_243 -> V_245 . V_275 . V_251 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_273 ,
V_243 -> V_245 . V_275 . V_274 ) )
return - V_96 ;
if ( V_243 -> V_245 . V_275 . V_266 &&
F_70 ( V_87 , V_267 ,
V_243 -> V_245 . V_275 . V_266 ) )
return - V_96 ;
return 0 ;
}
static int
F_168 ( struct V_86 * V_87 ,
const struct V_242 * V_243 )
{
if ( F_73 ( V_87 , V_244 ,
V_243 -> V_245 . V_280 . V_247 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_248 ,
V_243 -> V_245 . V_280 . V_249 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_281 ,
V_232 , V_243 -> V_245 . V_280 . V_282 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_283 ,
V_232 , V_243 -> V_245 . V_280 . V_284 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_262 ,
V_232 , V_243 -> V_245 . V_280 . V_263 ) )
return - V_96 ;
if ( F_68 ( V_87 , V_264 ,
V_232 , V_243 -> V_245 . V_280 . V_265 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_260 ,
V_243 -> V_245 . V_280 . V_261 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_253 ,
V_243 -> V_245 . V_280 . V_1 ) )
return - V_96 ;
if ( F_72 ( V_87 , V_254 ,
V_243 -> V_245 . V_280 . V_255 ) )
return - V_96 ;
switch ( F_2 ( V_243 -> V_245 . V_280 . V_261 ) ) {
case V_285 :
case V_286 :
if ( F_70 ( V_87 , V_287 ,
V_243 -> V_245 . V_280 . V_288 ) )
return - V_96 ;
if ( F_70 ( V_87 ,
V_289 ,
V_243 -> V_245 . V_280 . V_290 ) )
return - V_96 ;
if ( F_70 ( V_87 , V_291 ,
V_243 -> V_245 . V_280 . V_292 & 0x3f ) )
return - V_96 ;
if ( F_70 ( V_87 ,
V_293 ,
V_243 -> V_245 . V_280 . V_294 & 0x3f ) )
return - V_96 ;
if ( F_70 ( V_87 , V_295 ,
( V_243 -> V_245 . V_280 . V_292 & 0xc0 ) >> 6 ) )
return - V_96 ;
if ( F_70 ( V_87 ,
V_296 ,
( V_243 -> V_245 . V_280 . V_294 & 0xc0 ) >> 6 ) )
return - V_96 ;
break;
}
if ( V_243 -> V_245 . V_280 . V_274 != V_297 &&
F_73 ( V_87 , V_273 ,
V_243 -> V_245 . V_280 . V_274 ) )
return - V_96 ;
return 0 ;
}
static int F_169 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const struct V_242 * V_243 = V_201 ;
struct V_74 * V_202 ;
int V_54 = 0 ;
if ( F_71 ( V_87 , V_203 , V_243 -> V_298 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_71 ( V_87 , V_299 ,
V_243 -> V_245 . V_300 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_301 ,
V_243 -> V_245 . V_302 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_303 , 0 ) )
return - V_96 ;
if ( F_75 ( V_87 , V_304 ,
V_243 -> V_118 ) )
return - V_96 ;
switch ( V_243 -> V_245 . V_300 ) {
case V_305 :
V_54 = F_163 ( V_87 , V_243 ) ;
break;
case V_306 :
V_54 = F_164 ( V_87 , V_243 ) ;
break;
case V_307 :
V_54 = F_165 ( V_87 , V_243 ) ;
break;
case V_308 :
V_54 = F_166 ( V_87 , V_243 ) ;
break;
case V_309 :
V_54 = F_167 ( V_87 , V_243 ) ;
break;
case V_310 :
V_54 = F_168 ( V_87 , V_243 ) ;
break;
default:
V_54 = - V_311 ;
break;
}
if ( V_54 )
return V_54 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_170 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const struct V_242 * V_243 = V_201 ;
struct V_74 * V_202 ;
if ( F_71 ( V_87 , V_203 , V_243 -> V_298 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_75 ( V_87 , V_304 ,
V_243 -> V_118 ) )
return - V_96 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int
F_171 ( struct V_86 * V_87 ,
struct V_312 * V_243 )
{
if ( F_73 ( V_87 , V_313 ,
F_172 ( V_243 -> V_274 ) ) )
return - V_96 ;
if ( F_70 ( V_87 , V_314 ,
V_243 -> V_315 . V_8 ) )
return - V_96 ;
return 0 ;
}
static int
F_173 ( struct V_86 * V_87 ,
const struct V_312 * V_243 )
{
if ( F_73 ( V_87 , V_316 ,
V_243 -> V_317 . V_274 ) )
return - V_96 ;
if ( ! F_174 ( V_243 -> V_317 . V_282 ) &&
F_68 ( V_87 , V_281 ,
V_232 , V_243 -> V_317 . V_282 ) )
return - V_96 ;
if ( ! F_174 ( V_243 -> V_317 . V_263 ) &&
F_68 ( V_87 , V_262 ,
V_232 , V_243 -> V_317 . V_263 ) )
return - V_96 ;
if ( V_243 -> V_317 . V_1 &&
F_72 ( V_87 , V_253 ,
V_243 -> V_317 . V_1 ) )
return - V_96 ;
return 0 ;
}
static int
F_175 ( struct V_86 * V_87 ,
const struct V_312 * V_243 )
{
int V_50 ;
struct V_74 * V_318 ;
if ( F_71 ( V_87 , V_319 ,
V_243 -> V_320 ) )
return - V_96 ;
V_318 = F_76 ( V_87 ,
V_321 ) ;
if ( ! V_318 )
return - V_96 ;
for ( V_50 = 0 ; V_50 < V_243 -> V_320 ; V_50 ++ )
if ( F_73 ( V_87 , V_50 + 1 , V_243 -> V_318 [ V_50 ] ) )
return - V_96 ;
F_77 ( V_87 , V_318 ) ;
return 0 ;
}
static int
F_176 ( struct V_86 * V_87 ,
const struct V_312 * V_243 )
{
if ( ! F_174 ( V_243 -> V_322 . V_282 ) &&
F_68 ( V_87 , V_281 ,
V_232 , V_243 -> V_322 . V_282 ) )
return - V_96 ;
if ( ! F_174 ( V_243 -> V_322 . V_263 ) &&
F_68 ( V_87 , V_262 ,
V_232 , V_243 -> V_322 . V_263 ) )
return - V_96 ;
if ( V_243 -> V_322 . V_1 &&
F_72 ( V_87 , V_253 ,
V_243 -> V_322 . V_1 ) )
return - V_96 ;
if ( F_70 ( V_87 , V_323 ,
V_243 -> V_322 . V_324 ) )
return - V_96 ;
if ( F_73 ( V_87 , V_316 ,
V_243 -> V_322 . V_274 ) )
return - V_96 ;
return 0 ;
}
static int F_177 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_312 * V_243 = V_201 ;
struct V_74 * V_202 ;
int V_54 = 0 ;
if ( F_71 ( V_87 , V_203 , V_243 -> V_298 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_73 ( V_87 , V_273 ,
V_243 -> V_274 ) )
return - V_96 ;
switch ( F_178 ( V_243 -> V_274 ) ) {
case V_325 :
V_54 = F_171 ( V_87 , V_243 ) ;
break;
case V_326 :
V_54 = F_173 ( V_87 , V_243 ) ;
break;
case V_327 :
case V_328 :
V_54 = F_175 ( V_87 , V_243 ) ;
break;
case V_329 :
V_54 = F_176 ( V_87 , V_243 ) ;
break;
default:
V_54 = - V_311 ;
break;
}
if ( V_54 )
return V_54 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_179 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
const struct V_312 * V_243 = V_201 ;
struct V_74 * V_202 ;
if ( F_71 ( V_87 , V_203 , V_243 -> V_298 ) )
return - V_96 ;
V_202 = F_76 ( V_87 , V_205 ) ;
if ( ! V_202 )
return - V_96 ;
if ( F_73 ( V_87 , V_273 ,
V_243 -> V_274 ) )
return - V_96 ;
F_77 ( V_87 , V_202 ) ;
return 0 ;
}
static int F_180 ( struct V_34 * V_34 )
{
F_181 ( V_34 -> V_330 ) ;
F_110 ( & V_34 -> V_331 ) ;
F_181 ( V_34 -> V_332 ) ;
F_110 ( & V_34 -> V_333 ) ;
F_181 ( V_34 -> V_334 ) ;
F_110 ( & V_34 -> V_335 ) ;
F_181 ( V_34 -> V_336 ) ;
F_110 ( & V_34 -> V_337 ) ;
F_181 ( V_34 -> V_338 ) ;
F_110 ( & V_34 -> V_339 ) ;
return 0 ;
}
static void F_182 ( struct V_34 * V_34 )
{
unsigned long V_13 ;
struct V_242 * V_340 ;
struct V_312 * V_341 ;
struct V_342 * V_343 ;
struct V_344 * V_345 ;
struct V_346 * V_347 ;
struct V_348 * V_349 ;
int V_350 ;
F_145 ( & V_34 -> V_331 , V_13 ) ;
F_183 (rocker->flow_tbl, bkt, tmp, flow_entry, entry)
F_184 ( & V_340 -> V_243 ) ;
F_146 ( & V_34 -> V_331 , V_13 ) ;
F_145 ( & V_34 -> V_333 , V_13 ) ;
F_183 (rocker->group_tbl, bkt, tmp, group_entry, entry)
F_184 ( & V_341 -> V_243 ) ;
F_146 ( & V_34 -> V_333 , V_13 ) ;
F_145 ( & V_34 -> V_335 , V_13 ) ;
F_183 (rocker->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_184 ( & V_343 -> V_243 ) ;
F_146 ( & V_34 -> V_335 , V_13 ) ;
F_145 ( & V_34 -> V_337 , V_13 ) ;
F_183 (rocker->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_184 ( & V_345 -> V_243 ) ;
F_146 ( & V_34 -> V_337 , V_13 ) ;
F_145 ( & V_34 -> V_339 , V_13 ) ;
F_183 (rocker->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_184 ( & V_347 -> V_243 ) ;
F_146 ( & V_34 -> V_339 , V_13 ) ;
}
static struct V_242 *
F_185 ( const struct V_34 * V_34 ,
const struct V_242 * V_351 )
{
struct V_242 * V_352 ;
T_3 V_353 = V_351 -> V_353 ? V_351 -> V_353 : sizeof( V_352 -> V_245 ) ;
F_186 (rocker->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_352 -> V_245 , & V_351 -> V_245 , V_353 ) == 0 )
return V_352 ;
}
return NULL ;
}
static int F_187 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_242 * V_351 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_242 * V_352 ;
T_3 V_353 = V_351 -> V_353 ? V_351 -> V_353 : sizeof( V_352 -> V_245 ) ;
unsigned long V_198 ;
V_351 -> V_354 = F_188 ( ~ 0 , & V_351 -> V_245 , V_353 ) ;
F_145 ( & V_34 -> V_331 , V_198 ) ;
V_352 = F_185 ( V_34 , V_351 ) ;
if ( V_352 ) {
V_351 -> V_118 = V_352 -> V_118 ;
if ( V_12 != V_21 )
F_184 ( & V_352 -> V_243 ) ;
F_16 ( V_12 , V_352 ) ;
V_352 = V_351 ;
V_352 -> V_298 = V_355 ;
} else {
V_352 = V_351 ;
V_352 -> V_118 = V_34 -> V_356 ++ ;
V_352 -> V_298 = V_357 ;
}
if ( V_12 != V_21 )
F_189 ( V_34 -> V_330 , & V_352 -> V_243 , V_352 -> V_354 ) ;
F_146 ( & V_34 -> V_331 , V_198 ) ;
return F_144 ( V_6 , V_12 , V_13 ,
F_169 , V_352 , NULL , NULL ) ;
}
static int F_190 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_242 * V_351 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_242 * V_352 ;
T_3 V_353 = V_351 -> V_353 ? V_351 -> V_353 : sizeof( V_352 -> V_245 ) ;
unsigned long V_198 ;
int V_54 = 0 ;
V_351 -> V_354 = F_188 ( ~ 0 , & V_351 -> V_245 , V_353 ) ;
F_145 ( & V_34 -> V_331 , V_198 ) ;
V_352 = F_185 ( V_34 , V_351 ) ;
if ( V_352 ) {
if ( V_12 != V_21 )
F_184 ( & V_352 -> V_243 ) ;
V_352 -> V_298 = V_358 ;
}
F_146 ( & V_34 -> V_331 , V_198 ) ;
F_16 ( V_12 , V_351 ) ;
if ( V_352 ) {
V_54 = F_144 ( V_6 , V_12 , V_13 ,
F_170 ,
V_352 , NULL , NULL ) ;
F_16 ( V_12 , V_352 ) ;
}
return V_54 ;
}
static int F_191 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_242 * V_243 )
{
if ( V_13 & V_359 )
return F_190 ( V_6 , V_12 , V_13 , V_243 ) ;
else
return F_187 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_192 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_247 , T_5 V_249 ,
enum V_360 V_251 )
{
struct V_242 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_245 . V_302 = V_361 ;
V_243 -> V_245 . V_300 = V_305 ;
V_243 -> V_245 . V_246 . V_247 = V_247 ;
V_243 -> V_245 . V_246 . V_249 = V_249 ;
V_243 -> V_245 . V_246 . V_251 = V_251 ;
return F_191 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_193 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_247 , T_1 V_1 ,
T_1 V_255 ,
enum V_360 V_251 ,
bool V_256 , T_1 V_258 )
{
struct V_242 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_245 . V_302 = V_362 ;
V_243 -> V_245 . V_300 = V_306 ;
V_243 -> V_245 . V_252 . V_247 = V_247 ;
V_243 -> V_245 . V_252 . V_1 = V_1 ;
V_243 -> V_245 . V_252 . V_255 = V_255 ;
V_243 -> V_245 . V_252 . V_251 = V_251 ;
V_243 -> V_245 . V_252 . V_256 = V_256 ;
V_243 -> V_245 . V_252 . V_258 = V_258 ;
return F_191 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_194 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
T_5 V_247 , T_5 V_249 ,
T_1 V_261 , const T_9 * V_263 ,
const T_9 * V_265 , T_1 V_1 ,
T_1 V_255 , bool V_266 ,
int V_13 )
{
struct V_242 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
if ( F_195 ( V_263 ) ) {
V_243 -> V_245 . V_302 = V_363 ;
V_243 -> V_245 . V_259 . V_251 =
V_364 ;
} else {
V_243 -> V_245 . V_302 = V_365 ;
V_243 -> V_245 . V_259 . V_251 =
V_308 ;
}
V_243 -> V_245 . V_300 = V_307 ;
V_243 -> V_245 . V_259 . V_247 = V_247 ;
V_243 -> V_245 . V_259 . V_249 = V_249 ;
V_243 -> V_245 . V_259 . V_261 = V_261 ;
F_151 ( V_243 -> V_245 . V_259 . V_263 , V_263 ) ;
F_151 ( V_243 -> V_245 . V_259 . V_265 , V_265 ) ;
V_243 -> V_245 . V_259 . V_1 = V_1 ;
V_243 -> V_245 . V_259 . V_255 = V_255 ;
V_243 -> V_245 . V_259 . V_266 = V_266 ;
return F_191 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_196 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const T_9 * V_263 , const T_9 * V_265 ,
T_1 V_1 , T_5 V_278 ,
enum V_360 V_251 ,
T_5 V_274 , bool V_266 )
{
struct V_242 * V_243 ;
T_5 V_302 ;
bool V_366 = ! ! V_1 ;
bool V_367 = ! V_263 || ( V_263 && V_265 ) ;
bool V_368 = false ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_245 . V_300 = V_309 ;
if ( V_263 ) {
V_243 -> V_245 . V_275 . V_276 = 1 ;
F_151 ( V_243 -> V_245 . V_275 . V_263 , V_263 ) ;
}
if ( V_265 ) {
V_243 -> V_245 . V_275 . V_277 = 1 ;
F_151 ( V_243 -> V_245 . V_275 . V_265 , V_265 ) ;
if ( ! F_197 ( V_265 , V_369 ) )
V_368 = true ;
}
V_302 = V_370 ;
if ( V_366 && V_367 && V_368 )
V_302 = V_371 ;
else if ( V_366 && V_367 && ! V_368 )
V_302 = V_372 ;
else if ( V_366 && ! V_367 )
V_302 = V_373 ;
else if ( ! V_366 && V_367 && V_368 )
V_302 = V_374 ;
else if ( ! V_366 && V_367 && ! V_368 )
V_302 = V_375 ;
else if ( ! V_366 && ! V_367 )
V_302 = V_376 ;
V_243 -> V_245 . V_302 = V_302 ;
V_243 -> V_245 . V_275 . V_1 = V_1 ;
V_243 -> V_245 . V_275 . V_278 = V_278 ;
V_243 -> V_245 . V_275 . V_251 = V_251 ;
V_243 -> V_245 . V_275 . V_274 = V_274 ;
V_243 -> V_245 . V_275 . V_266 = V_266 ;
return F_191 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_198 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
T_1 V_261 , T_10 V_377 ,
T_10 V_378 , T_5 V_302 ,
enum V_360 V_251 ,
T_5 V_274 , int V_13 )
{
struct V_242 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_245 . V_300 = V_308 ;
V_243 -> V_245 . V_302 = V_302 ;
V_243 -> V_245 . V_268 . V_261 = V_261 ;
V_243 -> V_245 . V_268 . V_270 = V_377 ;
V_243 -> V_245 . V_268 . V_272 = V_378 ;
V_243 -> V_245 . V_268 . V_251 = V_251 ;
V_243 -> V_245 . V_268 . V_274 = V_274 ;
V_243 -> V_353 = F_199 ( struct V_379 ,
V_268 . V_274 ) ;
return F_191 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_200 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_247 , T_5 V_249 ,
const T_9 * V_282 , const T_9 * V_284 ,
const T_9 * V_263 , const T_9 * V_265 ,
T_1 V_261 , T_1 V_1 ,
T_1 V_255 , T_9 V_288 ,
T_9 V_290 , T_9 V_292 , T_9 V_294 ,
T_5 V_274 )
{
T_5 V_302 ;
struct V_242 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_302 = V_380 ;
if ( V_263 && V_265 ) {
if ( F_197 ( V_265 , V_381 ) )
V_302 = V_382 ;
else if ( F_201 ( V_263 ) )
V_302 = V_383 ;
}
V_243 -> V_245 . V_302 = V_302 ;
V_243 -> V_245 . V_300 = V_310 ;
V_243 -> V_245 . V_280 . V_247 = V_247 ;
V_243 -> V_245 . V_280 . V_249 = V_249 ;
if ( V_282 )
F_151 ( V_243 -> V_245 . V_280 . V_282 , V_282 ) ;
if ( V_284 )
F_151 ( V_243 -> V_245 . V_280 . V_284 , V_284 ) ;
if ( V_263 )
F_151 ( V_243 -> V_245 . V_280 . V_263 , V_263 ) ;
if ( V_265 )
F_151 ( V_243 -> V_245 . V_280 . V_265 , V_265 ) ;
V_243 -> V_245 . V_280 . V_261 = V_261 ;
V_243 -> V_245 . V_280 . V_1 = V_1 ;
V_243 -> V_245 . V_280 . V_255 = V_255 ;
V_243 -> V_245 . V_280 . V_288 = V_288 ;
V_243 -> V_245 . V_280 . V_290 = V_290 ;
V_243 -> V_245 . V_280 . V_292 = V_292 ;
V_243 -> V_245 . V_280 . V_294 = V_294 ;
V_243 -> V_245 . V_280 . V_274 = V_274 ;
return F_191 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static struct V_312 *
F_202 ( const struct V_34 * V_34 ,
const struct V_312 * V_351 )
{
struct V_312 * V_352 ;
F_186 (rocker->group_tbl, found,
entry, match->group_id) {
if ( V_352 -> V_274 == V_351 -> V_274 )
return V_352 ;
}
return NULL ;
}
static void F_203 ( enum V_11 V_12 ,
struct V_312 * V_243 )
{
switch ( F_178 ( V_243 -> V_274 ) ) {
case V_327 :
case V_328 :
F_16 ( V_12 , V_243 -> V_318 ) ;
break;
default:
break;
}
F_16 ( V_12 , V_243 ) ;
}
static int F_204 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_312 * V_351 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_312 * V_352 ;
unsigned long V_198 ;
F_145 ( & V_34 -> V_333 , V_198 ) ;
V_352 = F_202 ( V_34 , V_351 ) ;
if ( V_352 ) {
if ( V_12 != V_21 )
F_184 ( & V_352 -> V_243 ) ;
F_203 ( V_12 , V_352 ) ;
V_352 = V_351 ;
V_352 -> V_298 = V_384 ;
} else {
V_352 = V_351 ;
V_352 -> V_298 = V_385 ;
}
if ( V_12 != V_21 )
F_189 ( V_34 -> V_332 , & V_352 -> V_243 , V_352 -> V_274 ) ;
F_146 ( & V_34 -> V_333 , V_198 ) ;
return F_144 ( V_6 , V_12 , V_13 ,
F_177 , V_352 , NULL , NULL ) ;
}
static int F_205 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_312 * V_351 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_312 * V_352 ;
unsigned long V_198 ;
int V_54 = 0 ;
F_145 ( & V_34 -> V_333 , V_198 ) ;
V_352 = F_202 ( V_34 , V_351 ) ;
if ( V_352 ) {
if ( V_12 != V_21 )
F_184 ( & V_352 -> V_243 ) ;
V_352 -> V_298 = V_386 ;
}
F_146 ( & V_34 -> V_333 , V_198 ) ;
F_203 ( V_12 , V_351 ) ;
if ( V_352 ) {
V_54 = F_144 ( V_6 , V_12 , V_13 ,
F_179 ,
V_352 , NULL , NULL ) ;
F_203 ( V_12 , V_352 ) ;
}
return V_54 ;
}
static int F_206 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
struct V_312 * V_243 )
{
if ( V_13 & V_359 )
return F_205 ( V_6 , V_12 , V_13 , V_243 ) ;
else
return F_204 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_207 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 , T_5 V_387 ,
int V_8 )
{
struct V_312 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_274 = F_208 ( V_1 , V_387 ) ;
V_243 -> V_315 . V_8 = V_8 ;
return F_206 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_209 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 , T_9 V_320 ,
const T_5 * V_318 , T_5 V_274 )
{
struct V_312 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_274 = V_274 ;
V_243 -> V_320 = V_320 ;
V_243 -> V_318 = F_15 ( V_6 , V_12 , V_13 ,
V_320 , sizeof( T_5 ) ) ;
if ( ! V_243 -> V_318 ) {
F_16 ( V_12 , V_243 ) ;
return - V_57 ;
}
memcpy ( V_243 -> V_318 , V_318 , V_320 * sizeof( T_5 ) ) ;
return F_206 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static int F_210 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 , T_9 V_320 ,
const T_5 * V_318 , T_5 V_274 )
{
return F_209 ( V_6 , V_12 , V_13 ,
V_320 , V_318 ,
V_274 ) ;
}
static int F_211 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_5 V_388 , const T_9 * V_389 , const T_9 * V_390 ,
T_1 V_1 , bool V_324 , T_5 V_171 )
{
struct V_312 * V_243 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
V_243 -> V_274 = F_212 ( V_388 ) ;
if ( V_389 )
F_151 ( V_243 -> V_322 . V_282 , V_389 ) ;
if ( V_390 )
F_151 ( V_243 -> V_322 . V_263 , V_390 ) ;
V_243 -> V_322 . V_1 = V_1 ;
V_243 -> V_322 . V_324 = V_324 ;
V_243 -> V_322 . V_274 = F_208 ( V_1 , V_171 ) ;
return F_206 ( V_6 , V_12 , V_13 , V_243 ) ;
}
static struct V_346 *
F_213 ( const struct V_34 * V_34 , T_10 V_391 )
{
struct V_346 * V_352 ;
F_186 (rocker->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_352 -> V_391 == V_391 )
return V_352 ;
return NULL ;
}
static void F_214 ( struct V_34 * V_34 ,
enum V_11 V_12 ,
struct V_346 * V_243 )
{
if ( V_12 != V_23 )
V_243 -> V_388 = V_34 -> V_392 ++ ;
if ( V_12 == V_21 )
return;
V_243 -> V_393 ++ ;
F_189 ( V_34 -> V_338 , & V_243 -> V_243 ,
F_215 ( V_243 -> V_391 ) ) ;
}
static void F_216 ( enum V_11 V_12 ,
struct V_346 * V_243 )
{
if ( V_12 == V_21 )
return;
if ( -- V_243 -> V_393 == 0 ) {
F_184 ( & V_243 -> V_243 ) ;
F_16 ( V_12 , V_243 ) ;
}
}
static void F_217 ( struct V_346 * V_243 ,
enum V_11 V_12 ,
const T_9 * V_263 , bool V_324 )
{
if ( V_263 ) {
F_151 ( V_243 -> V_263 , V_263 ) ;
V_243 -> V_324 = V_324 ;
} else if ( V_12 != V_21 ) {
V_243 -> V_393 ++ ;
}
}
static int F_218 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 , T_10 V_391 , const T_9 * V_263 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_346 * V_243 ;
struct V_346 * V_352 ;
unsigned long V_198 ;
T_1 V_261 = F_4 ( V_285 ) ;
enum V_360 V_251 =
V_310 ;
T_5 V_274 ;
T_5 V_302 = 0 ;
bool V_394 = ! ( V_13 & V_359 ) ;
bool V_395 ;
bool V_396 ;
int V_54 = 0 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
F_145 ( & V_34 -> V_339 , V_198 ) ;
V_352 = F_213 ( V_34 , V_391 ) ;
V_395 = V_352 && V_394 ;
V_396 = V_352 && ! V_394 ;
V_394 = ! V_352 && V_394 ;
if ( V_394 ) {
V_243 -> V_391 = V_391 ;
V_243 -> V_43 = V_6 -> V_43 ;
F_151 ( V_243 -> V_263 , V_263 ) ;
V_243 -> V_324 = true ;
F_214 ( V_34 , V_12 , V_243 ) ;
} else if ( V_396 ) {
memcpy ( V_243 , V_352 , sizeof( * V_243 ) ) ;
F_216 ( V_12 , V_352 ) ;
} else if ( V_395 ) {
F_217 ( V_352 , V_12 , V_263 , true ) ;
memcpy ( V_243 , V_352 , sizeof( * V_243 ) ) ;
} else {
V_54 = - V_104 ;
}
F_146 ( & V_34 -> V_339 , V_198 ) ;
if ( V_54 )
goto V_397;
V_54 = F_211 ( V_6 , V_12 , V_13 ,
V_243 -> V_388 ,
V_6 -> V_43 -> V_398 ,
V_243 -> V_263 ,
V_6 -> V_9 ,
V_243 -> V_324 ,
V_6 -> V_171 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_21 ,
V_54 , V_243 -> V_388 ) ;
goto V_397;
}
if ( V_394 || V_396 ) {
V_274 = F_212 ( V_243 -> V_388 ) ;
V_54 = F_198 ( V_6 , V_12 ,
V_261 , V_391 ,
F_219 ( 32 ) ,
V_302 , V_251 ,
V_274 , V_13 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 ,
L_22 ,
V_54 , & V_243 -> V_391 , V_274 ) ;
}
V_397:
if ( ! V_394 )
F_16 ( V_12 , V_243 ) ;
return V_54 ;
}
static int F_220 ( struct V_6 * V_6 ,
enum V_11 V_12 , T_10 V_391 )
{
struct V_154 * V_43 = V_6 -> V_43 ;
struct V_399 * V_26 = F_221 ( V_43 , ( V_400 T_5 ) V_391 ) ;
int V_54 = 0 ;
if ( ! V_26 ) {
V_26 = F_222 ( & V_401 , & V_391 , V_43 ) ;
if ( F_223 ( V_26 ) )
return F_223 ( V_26 ) ;
}
if ( V_26 -> V_402 & V_403 )
V_54 = F_218 ( V_6 , V_12 , 0 ,
V_391 , V_26 -> V_404 ) ;
else
F_224 ( V_26 , NULL ) ;
F_225 ( V_26 ) ;
return V_54 ;
}
static int F_226 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_10 V_391 , T_5 * V_388 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_346 * V_243 ;
struct V_346 * V_352 ;
unsigned long V_198 ;
bool V_394 = ! ( V_13 & V_359 ) ;
bool V_395 ;
bool V_396 ;
bool V_405 = true ;
int V_54 = 0 ;
V_243 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_243 ) ) ;
if ( ! V_243 )
return - V_57 ;
F_145 ( & V_34 -> V_339 , V_198 ) ;
V_352 = F_213 ( V_34 , V_391 ) ;
if ( V_352 )
* V_388 = V_352 -> V_388 ;
V_395 = V_352 && V_394 ;
V_396 = V_352 && ! V_394 ;
V_394 = ! V_352 && V_394 ;
if ( V_394 ) {
V_243 -> V_391 = V_391 ;
V_243 -> V_43 = V_6 -> V_43 ;
F_214 ( V_34 , V_12 , V_243 ) ;
* V_388 = V_243 -> V_388 ;
V_405 = false ;
} else if ( V_396 ) {
F_216 ( V_12 , V_352 ) ;
} else if ( V_395 ) {
F_217 ( V_352 , V_12 , NULL , false ) ;
V_405 = ! F_174 ( V_352 -> V_263 ) ;
} else {
V_54 = - V_104 ;
}
F_146 ( & V_34 -> V_339 , V_198 ) ;
if ( ! V_394 )
F_16 ( V_12 , V_243 ) ;
if ( V_54 )
return V_54 ;
if ( ! V_405 )
V_54 = F_220 ( V_6 , V_12 , V_391 ) ;
return V_54 ;
}
static int F_227 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
int V_13 , T_1 V_1 )
{
struct V_6 * V_406 ;
const struct V_34 * V_34 = V_6 -> V_34 ;
T_5 V_274 = F_228 ( V_1 , 0 ) ;
T_5 * V_318 ;
T_9 V_320 = 0 ;
int V_54 = 0 ;
int V_50 ;
V_318 = F_15 ( V_6 , V_12 , V_13 ,
V_34 -> V_176 , sizeof( T_5 ) ) ;
if ( ! V_318 )
return - V_57 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_406 = V_34 -> V_177 [ V_50 ] ;
if ( ! V_406 )
continue;
if ( ! F_6 ( V_406 ) )
continue;
if ( F_229 ( F_2 ( V_1 ) , V_406 -> V_407 ) ) {
V_318 [ V_320 ++ ] =
F_208 ( V_1 , V_406 -> V_171 ) ;
}
}
if ( V_320 == 0 )
goto V_408;
V_54 = F_210 ( V_6 , V_12 , V_13 , V_1 ,
V_320 , V_318 , V_274 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 ,
L_23 , V_54 ) ;
V_408:
F_16 ( V_12 , V_318 ) ;
return V_54 ;
}
static int F_230 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 , bool V_8 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_6 * V_406 ;
bool V_394 = ! ( V_13 & V_359 ) ;
T_5 V_387 ;
int V_409 = 0 ;
int V_54 ;
int V_50 ;
if ( V_6 -> V_184 == V_185 ||
V_6 -> V_184 == V_186 ) {
V_387 = V_6 -> V_171 ;
V_54 = F_207 ( V_6 , V_12 , V_13 ,
V_1 , V_387 , V_8 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_24 ,
V_54 , V_387 ) ;
return V_54 ;
}
}
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_406 = V_34 -> V_177 [ V_50 ] ;
if ( V_406 && F_229 ( F_2 ( V_1 ) , V_406 -> V_407 ) )
V_409 ++ ;
}
if ( ( ! V_394 || V_409 != 1 ) && ( V_394 || V_409 != 0 ) )
return 0 ;
V_387 = 0 ;
V_54 = F_207 ( V_6 , V_12 , V_13 ,
V_1 , V_387 , V_8 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_25 , V_54 ) ;
return V_54 ;
}
return 0 ;
}
static int F_231 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_410 * V_411 , T_1 V_1 )
{
T_5 V_247 = V_6 -> V_171 ;
T_5 V_249 = 0xffffffff ;
T_5 V_387 = 0 ;
const T_9 * V_282 = NULL ;
const T_9 * V_284 = NULL ;
T_1 V_255 = F_4 ( 0xffff ) ;
T_9 V_288 = 0 ;
T_9 V_290 = 0 ;
T_9 V_292 = 0 ;
T_9 V_294 = 0 ;
T_5 V_274 = F_208 ( V_1 , V_387 ) ;
int V_54 ;
V_54 = F_200 ( V_6 , V_12 , V_13 ,
V_247 , V_249 ,
V_282 , V_284 ,
V_411 -> V_263 , V_411 -> V_265 ,
V_411 -> V_261 ,
V_1 , V_255 ,
V_288 , V_290 ,
V_292 , V_294 ,
V_274 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 , L_26 , V_54 ) ;
return V_54 ;
}
static int F_232 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_410 * V_411 ,
T_1 V_1 )
{
enum V_360 V_251 =
V_310 ;
T_5 V_274 = F_228 ( V_1 , 0 ) ;
T_5 V_278 = 0 ;
int V_54 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_54 = F_196 ( V_6 , V_12 , V_13 ,
V_411 -> V_263 , V_411 -> V_265 ,
V_1 , V_278 ,
V_251 , V_274 , V_411 -> V_266 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 , L_27 , V_54 ) ;
return V_54 ;
}
static int F_233 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_410 * V_411 , T_1 V_1 )
{
T_5 V_249 = 0xffffffff ;
T_1 V_255 = F_4 ( 0xffff ) ;
int V_54 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_54 = F_194 ( V_6 , V_12 ,
V_6 -> V_171 , V_249 ,
V_411 -> V_261 , V_411 -> V_263 ,
V_411 -> V_265 , V_1 ,
V_255 , V_411 -> V_266 ,
V_13 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 , L_28 , V_54 ) ;
return V_54 ;
}
static int F_234 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_410 * V_411 , T_1 V_1 )
{
if ( V_411 -> V_280 )
return F_231 ( V_6 , V_12 , V_13 ,
V_411 , V_1 ) ;
if ( V_411 -> V_275 )
return F_232 ( V_6 , V_12 , V_13 ,
V_411 , V_1 ) ;
if ( V_411 -> V_412 )
return F_233 ( V_6 , V_12 , V_13 ,
V_411 , V_1 ) ;
return - V_114 ;
}
static int F_235 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 )
{
int V_54 = 0 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_413 ; V_50 ++ ) {
if ( V_6 -> V_414 [ V_50 ] ) {
V_54 = F_234 ( V_6 , V_12 , V_13 ,
& V_415 [ V_50 ] , V_1 ) ;
if ( V_54 )
return V_54 ;
}
}
return V_54 ;
}
static int F_236 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const struct V_410 * V_411 )
{
T_2 V_7 ;
int V_54 = 0 ;
for ( V_7 = 1 ; V_7 < V_416 ; V_7 ++ ) {
if ( ! F_229 ( V_7 , V_6 -> V_407 ) )
continue;
V_54 = F_234 ( V_6 , V_12 , V_13 ,
V_411 , F_4 ( V_7 ) ) ;
if ( V_54 )
break;
}
return V_54 ;
}
static int F_237 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 , T_2 V_7 )
{
enum V_360 V_251 =
V_307 ;
T_5 V_247 = V_6 -> V_171 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_255 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_256 ;
bool V_394 = ! ( V_13 & V_359 ) ;
int V_54 ;
V_9 = F_3 ( V_6 , V_7 , & V_256 ) ;
if ( V_394 && F_229 ( F_2 ( V_9 ) ,
V_6 -> V_407 ) )
return 0 ;
else if ( ! V_394 && ! F_229 ( F_2 ( V_9 ) ,
V_6 -> V_407 ) )
return 0 ;
F_238 ( F_2 ( V_9 ) , V_6 -> V_407 ) ;
if ( V_394 ) {
V_54 = F_235 ( V_6 , V_12 , V_13 ,
V_9 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_29 , V_54 ) ;
goto V_397;
}
}
V_54 = F_230 ( V_6 , V_12 , V_13 ,
V_9 , V_256 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_30 , V_54 ) ;
goto V_397;
}
V_54 = F_227 ( V_6 , V_12 , V_13 ,
V_9 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_23 , V_54 ) ;
goto V_397;
}
V_54 = F_193 ( V_6 , V_12 , V_13 ,
V_247 , V_1 , V_255 ,
V_251 , V_256 , V_9 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 ,
L_31 , V_54 ) ;
V_397:
if ( V_12 == V_21 )
F_238 ( F_2 ( V_9 ) , V_6 -> V_407 ) ;
return V_54 ;
}
static int F_239 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
enum V_360 V_251 ;
T_5 V_247 ;
T_5 V_249 ;
int V_54 ;
V_247 = 0 ;
V_249 = 0xffff0000 ;
V_251 = V_306 ;
V_54 = F_192 ( V_6 , V_12 , V_13 ,
V_247 , V_249 ,
V_251 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 ,
L_32 , V_54 ) ;
return V_54 ;
}
static void F_240 ( struct V_417 * V_418 )
{
const struct V_419 * V_420 =
F_241 ( V_418 , struct V_419 , V_418 ) ;
bool V_396 = ( V_420 -> V_13 & V_359 ) ;
bool V_421 = ( V_420 -> V_13 & V_180 ) ;
struct V_422 V_121 ;
V_121 . V_179 = V_420 -> V_179 ;
V_121 . V_7 = V_420 -> V_7 ;
if ( V_421 && V_396 )
F_242 ( V_423 ,
V_420 -> V_6 -> V_43 , & V_121 . V_121 ) ;
else if ( V_421 && ! V_396 )
F_242 ( V_424 ,
V_420 -> V_6 -> V_43 , & V_121 . V_121 ) ;
F_16 ( V_420 -> V_12 , V_418 ) ;
}
static int F_243 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
const T_9 * V_179 , T_1 V_1 )
{
struct V_419 * V_420 ;
enum V_360 V_251 =
V_310 ;
T_5 V_387 = V_6 -> V_171 ;
T_5 V_278 = 0 ;
T_5 V_274 = V_297 ;
bool V_425 = ! ! ( V_6 -> V_240 & V_426 ) ;
bool V_266 = false ;
int V_54 ;
if ( F_6 ( V_6 ) )
V_274 = F_208 ( V_1 , V_387 ) ;
if ( ! ( V_13 & V_427 ) ) {
V_54 = F_196 ( V_6 , V_12 , V_13 , V_179 ,
NULL , V_1 , V_278 , V_251 ,
V_274 , V_266 ) ;
if ( V_54 )
return V_54 ;
}
if ( ! V_425 )
return 0 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_420 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_420 ) ) ;
if ( ! V_420 )
return - V_57 ;
F_244 ( & V_420 -> V_418 , F_240 ) ;
V_420 -> V_6 = V_6 ;
V_420 -> V_12 = V_12 ;
V_420 -> V_13 = V_13 ;
F_151 ( V_420 -> V_179 , V_179 ) ;
V_420 -> V_7 = F_5 ( V_6 , V_1 ) ;
if ( V_12 == V_21 )
F_16 ( V_12 , V_420 ) ;
else
F_245 ( & V_420 -> V_418 ) ;
return 0 ;
}
static struct V_342 *
F_246 ( const struct V_34 * V_34 ,
const struct V_342 * V_351 )
{
struct V_342 * V_352 ;
F_186 (rocker->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_352 -> V_245 , & V_351 -> V_245 , sizeof( V_352 -> V_245 ) ) == 0 )
return V_352 ;
return NULL ;
}
static int F_138 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const unsigned char * V_179 ,
T_1 V_1 , int V_13 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_342 * V_428 ;
struct V_342 * V_352 ;
bool V_396 = ( V_13 & V_359 ) ;
unsigned long V_198 ;
V_428 = F_14 ( V_6 , V_12 , V_13 , sizeof( * V_428 ) ) ;
if ( ! V_428 )
return - V_57 ;
V_428 -> V_421 = ( V_13 & V_180 ) ;
V_428 -> V_245 . V_171 = V_6 -> V_171 ;
F_151 ( V_428 -> V_245 . V_179 , V_179 ) ;
V_428 -> V_245 . V_1 = V_1 ;
V_428 -> V_354 = F_188 ( ~ 0 , & V_428 -> V_245 , sizeof( V_428 -> V_245 ) ) ;
F_145 ( & V_34 -> V_335 , V_198 ) ;
V_352 = F_246 ( V_34 , V_428 ) ;
if ( V_396 && V_352 ) {
F_16 ( V_12 , V_428 ) ;
if ( V_12 != V_21 )
F_184 ( & V_352 -> V_243 ) ;
} else if ( ! V_396 && ! V_352 ) {
if ( V_12 != V_21 )
F_189 ( V_34 -> V_334 , & V_428 -> V_243 , V_428 -> V_354 ) ;
}
F_146 ( & V_34 -> V_335 , V_198 ) ;
if ( ! V_352 != ! V_396 ) {
F_16 ( V_12 , V_428 ) ;
if ( ! V_352 && V_396 )
return 0 ;
V_13 |= V_427 ;
}
return F_243 ( V_6 , V_12 , V_13 , V_179 , V_1 ) ;
}
static int F_247 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_342 * V_352 ;
unsigned long V_198 ;
struct V_348 * V_349 ;
int V_350 ;
int V_54 = 0 ;
if ( V_6 -> V_184 == V_185 ||
V_6 -> V_184 == V_186 )
return 0 ;
V_13 |= V_359 ;
F_145 ( & V_34 -> V_335 , V_198 ) ;
F_183 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_352 -> V_245 . V_171 != V_6 -> V_171 )
continue;
if ( ! V_352 -> V_421 )
continue;
V_54 = F_243 ( V_6 , V_12 , V_13 ,
V_352 -> V_245 . V_179 ,
V_352 -> V_245 . V_1 ) ;
if ( V_54 )
goto V_397;
if ( V_12 != V_21 )
F_184 ( & V_352 -> V_243 ) ;
}
V_397:
F_146 ( & V_34 -> V_335 , V_198 ) ;
return V_54 ;
}
static int F_248 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_1 V_1 )
{
T_5 V_249 = 0xffffffff ;
T_1 V_261 ;
const T_9 * V_429 = V_369 ;
T_1 V_255 = F_4 ( 0xffff ) ;
bool V_266 = false ;
int V_54 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_261 = F_4 ( V_285 ) ;
V_54 = F_194 ( V_6 , V_12 ,
V_6 -> V_171 , V_249 ,
V_261 , V_6 -> V_43 -> V_398 ,
V_429 , V_1 , V_255 ,
V_266 , V_13 ) ;
if ( V_54 )
return V_54 ;
V_261 = F_4 ( V_286 ) ;
V_54 = F_194 ( V_6 , V_12 ,
V_6 -> V_171 , V_249 ,
V_261 , V_6 -> V_43 -> V_398 ,
V_429 , V_1 , V_255 ,
V_266 , V_13 ) ;
return V_54 ;
}
static int F_249 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
bool V_8 ;
T_5 V_387 ;
T_1 V_1 ;
T_2 V_7 ;
int V_54 ;
if ( V_6 -> V_184 != V_185 &&
V_6 -> V_184 != V_186 )
V_13 |= V_359 ;
V_387 = V_6 -> V_171 ;
for ( V_7 = 1 ; V_7 < V_416 ; V_7 ++ ) {
if ( ! F_229 ( V_7 , V_6 -> V_407 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_54 = F_207 ( V_6 , V_12 , V_13 ,
V_1 , V_387 , V_8 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 ,
L_24 ,
V_54 , V_387 ) ;
return V_54 ;
}
}
return 0 ;
}
static int F_250 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 ,
T_9 V_430 )
{
bool V_431 [ V_413 ] = { 0 , } ;
bool V_432 [ V_413 ] ;
T_9 V_433 ;
int V_54 ;
int V_50 ;
if ( V_12 == V_21 ) {
memcpy ( V_432 , V_6 -> V_414 , sizeof( V_432 ) ) ;
V_433 = V_6 -> V_184 ;
}
if ( V_6 -> V_184 == V_430 )
return 0 ;
V_6 -> V_184 = V_430 ;
switch ( V_430 ) {
case V_434 :
break;
case V_435 :
case V_436 :
V_431 [ V_437 ] = true ;
break;
case V_185 :
case V_186 :
V_431 [ V_437 ] = true ;
V_431 [ V_438 ] = true ;
V_431 [ V_439 ] = true ;
if ( F_6 ( V_6 ) )
V_431 [ V_440 ] = true ;
else
V_431 [ V_441 ] = true ;
break;
}
for ( V_50 = 0 ; V_50 < V_413 ; V_50 ++ ) {
if ( V_431 [ V_50 ] != V_6 -> V_414 [ V_50 ] ) {
int V_442 = V_13 |
( V_431 [ V_50 ] ? 0 : V_359 ) ;
V_54 = F_236 ( V_6 , V_12 , V_442 ,
& V_415 [ V_50 ] ) ;
if ( V_54 )
goto V_397;
V_6 -> V_414 [ V_50 ] = V_431 [ V_50 ] ;
}
}
V_54 = F_247 ( V_6 , V_12 , V_13 ) ;
if ( V_54 )
goto V_397;
V_54 = F_249 ( V_6 , V_12 , V_13 ) ;
V_397:
if ( V_12 == V_21 ) {
memcpy ( V_6 -> V_414 , V_432 , sizeof( V_432 ) ) ;
V_6 -> V_184 = V_433 ;
}
return V_54 ;
}
static int F_251 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_250 ( V_6 , V_12 , V_13 ,
V_186 ) ;
}
static int F_252 ( struct V_6 * V_6 ,
enum V_11 V_12 , int V_13 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_250 ( V_6 , V_12 , V_13 ,
V_434 ) ;
}
static struct V_344 *
F_253 ( const struct V_34 * V_34 , int V_443 )
{
struct V_344 * V_352 ;
F_186 (rocker->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_352 -> V_443 == V_443 )
return V_352 ;
}
return NULL ;
}
static T_1 F_254 ( struct V_6 * V_6 ,
int V_443 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_344 * V_243 ;
struct V_344 * V_352 ;
unsigned long V_198 ;
int V_50 ;
V_243 = F_8 ( sizeof( * V_243 ) , V_20 ) ;
if ( ! V_243 )
return 0 ;
V_243 -> V_443 = V_443 ;
F_145 ( & V_34 -> V_337 , V_198 ) ;
V_352 = F_253 ( V_34 , V_443 ) ;
if ( V_352 ) {
F_17 ( V_243 ) ;
goto V_352;
}
V_352 = V_243 ;
F_189 ( V_34 -> V_336 , & V_352 -> V_243 , V_352 -> V_443 ) ;
for ( V_50 = 0 ; V_50 < V_444 ; V_50 ++ ) {
if ( F_255 ( V_50 , V_34 -> V_445 ) )
continue;
V_352 -> V_1 = F_4 ( V_3 + V_50 ) ;
goto V_352;
}
F_123 ( V_6 -> V_43 , L_33 ) ;
V_352:
V_352 -> V_393 ++ ;
F_146 ( & V_34 -> V_337 , V_198 ) ;
return V_352 -> V_1 ;
}
static void
F_256 ( const struct V_6 * V_6 ,
int V_443 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_344 * V_352 ;
unsigned long V_198 ;
unsigned long V_446 ;
F_145 ( & V_34 -> V_337 , V_198 ) ;
V_352 = F_253 ( V_34 , V_443 ) ;
if ( ! V_352 ) {
F_123 ( V_6 -> V_43 ,
L_34 ,
V_443 ) ;
goto V_447;
}
if ( -- V_352 -> V_393 <= 0 ) {
V_446 = F_2 ( V_352 -> V_1 ) - V_3 ;
F_257 ( V_446 , V_34 -> V_445 ) ;
F_184 ( & V_352 -> V_243 ) ;
F_17 ( V_352 ) ;
}
V_447:
F_146 ( & V_34 -> V_337 , V_198 ) ;
}
static int F_258 ( struct V_6 * V_6 ,
enum V_11 V_12 , T_10 V_377 ,
int V_448 , const struct V_449 * V_450 ,
T_5 V_451 , int V_13 )
{
const struct V_452 * V_453 ;
T_1 V_261 = F_4 ( V_285 ) ;
T_10 V_378 = F_219 ( V_448 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_5 V_302 = V_450 -> V_454 ;
enum V_360 V_251 =
V_310 ;
T_5 V_274 ;
bool V_455 ;
bool V_456 ;
T_5 V_388 ;
int V_54 ;
V_453 = V_450 -> V_452 ;
V_455 = ( V_450 -> V_457 == V_6 -> V_43 ) ;
V_456 = ! ! V_453 -> V_458 ;
if ( V_456 && V_455 ) {
V_54 = F_226 ( V_6 , V_12 , V_13 ,
V_453 -> V_458 , & V_388 ) ;
if ( V_54 )
return V_54 ;
V_274 = F_212 ( V_388 ) ;
} else {
V_274 = F_208 ( V_9 , 0 ) ;
}
V_54 = F_198 ( V_6 , V_12 , V_261 , V_377 ,
V_378 , V_302 , V_251 ,
V_274 , V_13 ) ;
if ( V_54 )
F_123 ( V_6 -> V_43 , L_35 ,
V_54 , & V_377 ) ;
return V_54 ;
}
static int F_259 ( struct V_154 * V_43 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
int V_54 ;
V_54 = F_121 ( V_6 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_48 ( F_28 ( V_6 ) ,
F_141 , 0 ,
V_71 , V_6 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_36 ) ;
goto V_459;
}
V_54 = F_48 ( F_30 ( V_6 ) ,
F_143 , 0 ,
V_71 , V_6 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_37 ) ;
goto V_460;
}
V_54 = F_251 ( V_6 , V_25 , 0 ) ;
if ( V_54 )
goto V_461;
F_261 ( & V_6 -> V_192 ) ;
F_261 ( & V_6 -> V_193 ) ;
F_126 ( V_6 , true ) ;
F_262 ( V_43 ) ;
return 0 ;
V_461:
V_73 ( F_30 ( V_6 ) , V_6 ) ;
V_460:
V_73 ( F_28 ( V_6 ) , V_6 ) ;
V_459:
F_125 ( V_6 ) ;
return V_54 ;
}
static int F_263 ( struct V_154 * V_43 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
F_264 ( V_43 ) ;
F_126 ( V_6 , false ) ;
F_265 ( & V_6 -> V_193 ) ;
F_265 ( & V_6 -> V_192 ) ;
F_252 ( V_6 , V_25 ,
V_18 ) ;
V_73 ( F_30 ( V_6 ) , V_6 ) ;
V_73 ( F_28 ( V_6 ) , V_6 ) ;
F_125 ( V_6 ) ;
return 0 ;
}
static void F_266 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_38 * V_39 = V_34 -> V_39 ;
const struct V_74 * V_155 [ V_462 + 1 ] ;
struct V_74 * V_230 ;
int V_85 ;
F_66 ( V_155 , V_462 , V_87 ) ;
if ( ! V_155 [ V_463 ] )
return;
F_267 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
const struct V_74 * V_464 [ V_465 + 1 ] ;
T_7 V_47 ;
T_3 V_78 ;
if ( F_55 ( V_230 ) != V_466 )
continue;
F_65 ( V_464 , V_465 ,
V_230 ) ;
if ( ! V_464 [ V_467 ] ||
! V_464 [ V_468 ] )
continue;
V_47 = F_62 ( V_464 [ V_467 ] ) ;
V_78 = F_59 ( V_464 [ V_468 ] ) ;
F_44 ( V_39 , V_47 , V_78 , V_469 ) ;
}
}
static int F_268 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
char * V_48 , T_3 V_83 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_38 * V_39 = V_34 -> V_39 ;
T_7 V_47 ;
struct V_74 * V_470 ;
V_47 = F_41 ( V_39 , V_48 , V_83 , V_469 ) ;
if ( F_69 ( F_42 ( V_39 , V_47 ) ) ) {
if ( F_269 () )
F_123 ( V_6 -> V_43 , L_38 ) ;
return - V_44 ;
}
V_470 = F_76 ( V_87 , V_466 ) ;
if ( ! V_470 )
goto V_471;
if ( F_75 ( V_87 , V_467 ,
V_47 ) )
goto V_472;
if ( F_71 ( V_87 , V_468 ,
V_83 ) )
goto V_472;
F_77 ( V_87 , V_470 ) ;
return 0 ;
V_472:
F_78 ( V_87 , V_470 ) ;
V_471:
F_44 ( V_39 , V_47 , V_83 , V_469 ) ;
return - V_96 ;
}
static T_13 F_270 ( struct V_145 * V_146 , struct V_154 * V_43 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_86 * V_87 ;
struct V_74 * V_473 ;
int V_50 ;
int V_54 ;
V_87 = F_85 ( & V_6 -> V_159 ) ;
if ( F_69 ( ! V_87 ) ) {
if ( F_269 () )
F_123 ( V_43 , L_39 ) ;
return V_474 ;
}
F_84 ( V_87 , V_146 ) ;
V_473 = F_76 ( V_87 , V_463 ) ;
if ( ! V_473 )
goto V_200;
V_54 = F_268 ( V_6 , V_87 ,
V_146 -> V_88 , F_271 ( V_146 ) ) ;
if ( V_54 )
goto V_472;
if ( F_272 ( V_146 ) -> V_475 > V_476 )
goto V_472;
for ( V_50 = 0 ; V_50 < F_272 ( V_146 ) -> V_475 ; V_50 ++ ) {
const T_14 * V_470 = & F_272 ( V_146 ) -> V_473 [ V_50 ] ;
V_54 = F_268 ( V_6 , V_87 ,
F_273 ( V_470 ) ,
F_274 ( V_470 ) ) ;
if ( V_54 )
goto V_477;
}
F_77 ( V_87 , V_473 ) ;
F_81 ( V_87 ) ;
F_87 ( V_34 , & V_6 -> V_159 , V_87 ) ;
V_87 = F_85 ( & V_6 -> V_159 ) ;
if ( ! V_87 )
F_264 ( V_43 ) ;
return V_478 ;
V_477:
F_266 ( V_6 , V_87 ) ;
V_472:
F_78 ( V_87 , V_473 ) ;
V_200:
F_275 ( V_146 ) ;
V_43 -> V_479 . V_480 ++ ;
return V_478 ;
}
static int F_276 ( struct V_154 * V_43 , void * V_406 )
{
struct V_481 * V_179 = V_406 ;
struct V_6 * V_6 = F_260 ( V_43 ) ;
int V_54 ;
if ( ! F_277 ( V_179 -> V_482 ) )
return - V_483 ;
V_54 = F_161 ( V_6 , V_179 -> V_482 ) ;
if ( V_54 )
return V_54 ;
memcpy ( V_43 -> V_398 , V_179 -> V_482 , V_43 -> V_484 ) ;
return 0 ;
}
static int F_278 ( struct V_154 * V_43 ,
char * V_48 , T_3 V_78 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
struct V_233 V_234 = { . V_48 = V_48 , . V_78 = V_78 } ;
int V_54 ;
V_54 = F_144 ( V_6 , V_25 , 0 ,
F_147 , NULL ,
F_152 ,
& V_234 ) ;
return V_54 ? - V_114 : 0 ;
}
static int F_279 ( struct V_154 * V_43 ,
struct V_485 * V_230 )
{
const struct V_6 * V_6 = F_260 ( V_43 ) ;
const struct V_34 * V_34 = V_6 -> V_34 ;
switch ( V_230 -> V_486 ) {
case V_487 :
V_230 -> V_488 . V_489 . V_490 = sizeof( V_34 -> V_491 . V_486 ) ;
memcpy ( & V_230 -> V_488 . V_489 . V_486 , & V_34 -> V_491 . V_486 , V_230 -> V_488 . V_489 . V_490 ) ;
break;
case V_492 :
V_230 -> V_488 . V_240 = V_6 -> V_240 ;
break;
default:
return - V_114 ;
}
return 0 ;
}
static void F_280 ( const struct V_6 * V_6 )
{
struct V_15 * V_27 , * V_349 ;
F_281 (mem, tmp, &rocker_port->trans_mem) {
F_282 ( V_27 ) ;
F_17 ( V_27 ) ;
}
}
static int F_283 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
unsigned long V_240 )
{
unsigned long V_493 ;
int V_54 = 0 ;
V_493 = V_6 -> V_240 ;
V_6 -> V_240 = V_240 ;
if ( ( V_493 ^ V_6 -> V_240 ) & V_241 )
V_54 = F_162 ( V_6 , V_12 ) ;
if ( V_12 == V_21 )
V_6 -> V_240 = V_493 ;
return V_54 ;
}
static int F_284 ( struct V_154 * V_43 ,
struct V_485 * V_230 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
int V_54 = 0 ;
switch ( V_230 -> V_12 ) {
case V_21 :
F_10 ( ! F_11 ( & V_6 -> V_22 ) ) ;
break;
case V_494 :
F_280 ( V_6 ) ;
return 0 ;
default:
break;
}
switch ( V_230 -> V_486 ) {
case V_495 :
V_54 = F_250 ( V_6 , V_230 -> V_12 ,
V_18 ,
V_230 -> V_488 . V_184 ) ;
break;
case V_492 :
V_54 = F_283 ( V_6 , V_230 -> V_12 ,
V_230 -> V_488 . V_240 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_285 ( struct V_6 * V_6 ,
enum V_11 V_12 , T_2 V_7 , T_2 V_13 )
{
int V_54 ;
V_54 = F_237 ( V_6 , V_12 , 0 , V_7 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_248 ( V_6 , V_12 , 0 , F_4 ( V_7 ) ) ;
if ( V_54 )
F_237 ( V_6 , V_12 ,
V_359 , V_7 ) ;
return V_54 ;
}
static int F_286 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const struct V_496 * V_252 )
{
T_2 V_7 ;
int V_54 ;
for ( V_7 = V_252 -> V_497 ; V_7 <= V_252 -> V_498 ; V_7 ++ ) {
V_54 = F_285 ( V_6 , V_12 ,
V_7 , V_252 -> V_13 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_287 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const struct V_499 * V_428 )
{
T_1 V_1 = F_3 ( V_6 , V_428 -> V_7 , NULL ) ;
int V_13 = 0 ;
if ( ! F_6 ( V_6 ) )
return - V_111 ;
return F_138 ( V_6 , V_12 , V_428 -> V_179 , V_1 , V_13 ) ;
}
static int F_288 ( struct V_154 * V_43 ,
struct V_500 * V_501 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
const struct V_502 * V_503 ;
int V_54 = 0 ;
switch ( V_501 -> V_12 ) {
case V_21 :
F_10 ( ! F_11 ( & V_6 -> V_22 ) ) ;
break;
case V_494 :
F_280 ( V_6 ) ;
return 0 ;
default:
break;
}
switch ( V_501 -> V_486 ) {
case V_504 :
V_54 = F_286 ( V_6 , V_501 -> V_12 ,
& V_501 -> V_488 . V_252 ) ;
break;
case V_505 :
V_503 = & V_501 -> V_488 . V_506 ;
V_54 = F_258 ( V_6 , V_501 -> V_12 ,
F_289 ( V_503 -> V_377 ) , V_503 -> V_448 ,
V_503 -> V_450 , V_503 -> V_451 , 0 ) ;
break;
case V_507 :
V_54 = F_287 ( V_6 , V_501 -> V_12 , & V_501 -> V_488 . V_428 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_290 ( struct V_6 * V_6 ,
T_2 V_7 , T_2 V_13 )
{
int V_54 ;
V_54 = F_248 ( V_6 , V_25 ,
V_359 , F_4 ( V_7 ) ) ;
if ( V_54 )
return V_54 ;
return F_237 ( V_6 , V_25 ,
V_359 , V_7 ) ;
}
static int F_291 ( struct V_6 * V_6 ,
const struct V_496 * V_252 )
{
T_2 V_7 ;
int V_54 ;
for ( V_7 = V_252 -> V_497 ; V_7 <= V_252 -> V_498 ; V_7 ++ ) {
V_54 = F_290 ( V_6 , V_7 , V_252 -> V_13 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_292 ( struct V_6 * V_6 ,
enum V_11 V_12 ,
const struct V_499 * V_428 )
{
T_1 V_1 = F_3 ( V_6 , V_428 -> V_7 , NULL ) ;
int V_13 = V_18 | V_359 ;
if ( ! F_6 ( V_6 ) )
return - V_111 ;
return F_138 ( V_6 , V_12 , V_428 -> V_179 , V_1 , V_13 ) ;
}
static int F_293 ( struct V_154 * V_43 ,
struct V_500 * V_501 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
const struct V_502 * V_503 ;
int V_54 = 0 ;
switch ( V_501 -> V_486 ) {
case V_504 :
V_54 = F_291 ( V_6 , & V_501 -> V_488 . V_252 ) ;
break;
case V_505 :
V_503 = & V_501 -> V_488 . V_506 ;
V_54 = F_258 ( V_6 , V_25 ,
F_289 ( V_503 -> V_377 ) , V_503 -> V_448 ,
V_503 -> V_450 , V_503 -> V_451 ,
V_359 ) ;
break;
case V_507 :
V_54 = F_292 ( V_6 , V_501 -> V_12 , & V_501 -> V_488 . V_428 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_294 ( const struct V_6 * V_6 ,
struct V_500 * V_501 )
{
struct V_34 * V_34 = V_6 -> V_34 ;
struct V_499 * V_428 = & V_501 -> V_488 . V_428 ;
struct V_342 * V_352 ;
struct V_348 * V_349 ;
unsigned long V_198 ;
int V_350 ;
int V_54 = 0 ;
F_145 ( & V_34 -> V_335 , V_198 ) ;
F_183 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_352 -> V_245 . V_171 != V_6 -> V_171 )
continue;
V_428 -> V_179 = V_352 -> V_245 . V_179 ;
V_428 -> V_7 = F_5 ( V_6 ,
V_352 -> V_245 . V_1 ) ;
V_54 = V_501 -> V_508 ( V_6 -> V_43 , V_501 ) ;
if ( V_54 )
break;
}
F_146 ( & V_34 -> V_335 , V_198 ) ;
return V_54 ;
}
static int F_295 ( const struct V_6 * V_6 ,
struct V_500 * V_501 )
{
struct V_496 * V_252 = & V_501 -> V_488 . V_252 ;
T_2 V_7 ;
int V_54 = 0 ;
for ( V_7 = 1 ; V_7 < V_416 ; V_7 ++ ) {
if ( ! F_229 ( V_7 , V_6 -> V_407 ) )
continue;
V_252 -> V_13 = 0 ;
if ( F_1 ( F_4 ( V_7 ) ) )
V_252 -> V_13 |= V_509 ;
V_252 -> V_497 = V_252 -> V_498 = V_7 ;
V_54 = V_501 -> V_508 ( V_6 -> V_43 , V_501 ) ;
if ( V_54 )
break;
}
return V_54 ;
}
static int F_296 ( struct V_154 * V_43 ,
struct V_500 * V_501 )
{
const struct V_6 * V_6 = F_260 ( V_43 ) ;
int V_54 = 0 ;
switch ( V_501 -> V_486 ) {
case V_507 :
V_54 = F_294 ( V_6 , V_501 ) ;
break;
case V_504 :
V_54 = F_295 ( V_6 , V_501 ) ;
break;
default:
V_54 = - V_114 ;
break;
}
return V_54 ;
}
static int F_297 ( struct V_154 * V_43 ,
struct V_207 * V_208 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
return F_158 ( V_6 , V_208 ) ;
}
static int F_298 ( struct V_154 * V_43 ,
struct V_207 * V_208 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
return F_160 ( V_6 , V_208 ) ;
}
static void F_299 ( struct V_154 * V_43 ,
struct V_510 * V_511 )
{
F_300 ( V_511 -> V_512 , V_71 , sizeof( V_511 -> V_512 ) ) ;
F_300 ( V_511 -> V_513 , V_514 , sizeof( V_511 -> V_513 ) ) ;
}
static void F_301 ( struct V_154 * V_515 , T_5 V_516 ,
T_9 * V_88 )
{
T_9 * V_406 = V_88 ;
int V_50 ;
switch ( V_516 ) {
case V_517 :
for ( V_50 = 0 ; V_50 < F_302 ( V_518 ) ; V_50 ++ ) {
memcpy ( V_406 , V_518 [ V_50 ] . V_236 , V_519 ) ;
V_406 += V_519 ;
}
break;
}
}
static int
F_303 ( const struct V_6 * V_6 ,
struct V_86 * V_87 ,
void * V_201 )
{
struct V_74 * V_520 ;
if ( F_71 ( V_87 , V_203 ,
V_521 ) )
return - V_96 ;
V_520 = F_76 ( V_87 , V_205 ) ;
if ( ! V_520 )
return - V_96 ;
if ( F_73 ( V_87 , V_522 ,
V_6 -> V_171 ) )
return - V_96 ;
F_77 ( V_87 , V_520 ) ;
return 0 ;
}
static int
F_304 ( const struct V_6 * V_6 ,
const struct V_86 * V_87 ,
void * V_201 )
{
const struct V_74 * V_155 [ V_209 + 1 ] ;
const struct V_74 * V_523 [ V_524 + 1 ] ;
const struct V_74 * V_525 ;
T_5 V_171 ;
T_6 * V_88 = V_201 ;
int V_50 ;
F_66 ( V_155 , V_209 , V_87 ) ;
if ( ! V_155 [ V_205 ] )
return - V_44 ;
F_65 ( V_523 , V_524 ,
V_155 [ V_205 ] ) ;
if ( ! V_523 [ V_522 ] )
return - V_44 ;
V_171 = F_61 ( V_523 [ V_522 ] ) ;
if ( V_171 != V_6 -> V_171 )
return - V_44 ;
for ( V_50 = 0 ; V_50 < F_302 ( V_518 ) ; V_50 ++ ) {
V_525 = V_523 [ V_518 [ V_50 ] . type ] ;
if ( ! V_525 )
continue;
V_88 [ V_50 ] = F_62 ( V_525 ) ;
}
return 0 ;
}
static int F_305 ( struct V_6 * V_6 ,
void * V_201 )
{
return F_144 ( V_6 , V_25 , 0 ,
F_303 , NULL ,
F_304 ,
V_201 ) ;
}
static void F_306 ( struct V_154 * V_43 ,
struct V_526 * V_479 , T_6 * V_88 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
if ( F_305 ( V_6 , V_88 ) != 0 ) {
int V_50 ;
for ( V_50 = 0 ; V_50 < F_302 ( V_518 ) ; ++ V_50 )
V_88 [ V_50 ] = 0 ;
}
}
static int F_307 ( struct V_154 * V_515 , int V_527 )
{
switch ( V_527 ) {
case V_517 :
return V_528 ;
default:
return - V_114 ;
}
}
static struct V_6 * F_308 ( struct V_529 * V_530 )
{
return F_241 ( V_530 , struct V_6 , V_192 ) ;
}
static int F_309 ( struct V_529 * V_530 , int V_531 )
{
struct V_6 * V_6 = F_308 ( V_530 ) ;
const struct V_34 * V_34 = V_6 -> V_34 ;
const struct V_86 * V_87 ;
T_5 V_124 = 0 ;
int V_54 ;
while ( ( V_87 = F_89 ( & V_6 -> V_159 ) ) ) {
struct V_145 * V_146 ;
V_54 = F_80 ( V_87 ) ;
if ( V_54 && F_269 () )
F_123 ( V_6 -> V_43 , L_40 ,
V_54 ) ;
F_266 ( V_6 , V_87 ) ;
V_146 = F_83 ( V_87 ) ;
if ( V_54 == 0 ) {
V_6 -> V_43 -> V_479 . V_532 ++ ;
V_6 -> V_43 -> V_479 . V_533 += V_146 -> V_78 ;
} else {
V_6 -> V_43 -> V_479 . V_534 ++ ;
}
F_116 ( V_146 ) ;
V_124 ++ ;
}
if ( V_124 && F_310 ( V_6 -> V_43 ) )
F_311 ( V_6 -> V_43 ) ;
F_312 ( V_530 ) ;
F_90 ( V_34 , & V_6 -> V_159 , V_124 ) ;
return 0 ;
}
static int F_313 ( const struct V_34 * V_34 ,
const struct V_6 * V_6 ,
struct V_86 * V_87 )
{
const struct V_74 * V_155 [ V_156 + 1 ] ;
struct V_145 * V_146 = F_83 ( V_87 ) ;
T_3 V_535 ;
if ( ! V_146 )
return - V_104 ;
F_66 ( V_155 , V_156 , V_87 ) ;
if ( ! V_155 [ V_536 ] )
return - V_111 ;
F_117 ( V_34 , V_155 ) ;
V_535 = F_59 ( V_155 [ V_536 ] ) ;
F_314 ( V_146 , V_535 ) ;
V_146 -> V_537 = F_315 ( V_146 , V_6 -> V_43 ) ;
V_6 -> V_43 -> V_479 . V_538 ++ ;
V_6 -> V_43 -> V_479 . V_539 += V_146 -> V_78 ;
F_316 ( V_146 ) ;
return F_114 ( V_6 , V_87 ) ;
}
static struct V_6 * F_317 ( struct V_529 * V_530 )
{
return F_241 ( V_530 , struct V_6 , V_193 ) ;
}
static int F_318 ( struct V_529 * V_530 , int V_531 )
{
struct V_6 * V_6 = F_317 ( V_530 ) ;
const struct V_34 * V_34 = V_6 -> V_34 ;
struct V_86 * V_87 ;
T_5 V_124 = 0 ;
int V_54 ;
while ( V_124 < V_531 &&
( V_87 = F_89 ( & V_6 -> V_157 ) ) ) {
V_54 = F_80 ( V_87 ) ;
if ( V_54 ) {
if ( F_269 () )
F_123 ( V_6 -> V_43 , L_41 ,
V_54 ) ;
} else {
V_54 = F_313 ( V_34 , V_6 ,
V_87 ) ;
if ( V_54 && F_269 () )
F_123 ( V_6 -> V_43 , L_42 ,
V_54 ) ;
}
if ( V_54 )
V_6 -> V_43 -> V_479 . V_540 ++ ;
F_81 ( V_87 ) ;
F_87 ( V_34 , & V_6 -> V_157 , V_87 ) ;
V_124 ++ ;
}
if ( V_124 < V_531 )
F_312 ( V_530 ) ;
F_90 ( V_34 , & V_6 -> V_157 , V_124 ) ;
return V_124 ;
}
static void F_319 ( const struct V_6 * V_6 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
T_6 V_541 = F_38 ( V_34 , V_542 ) ;
bool V_173 ;
V_173 = V_541 & ( 1 << V_6 -> V_171 ) ;
if ( V_173 )
F_131 ( V_6 -> V_43 ) ;
else
F_134 ( V_6 -> V_43 ) ;
}
static void F_320 ( const struct V_34 * V_34 )
{
struct V_6 * V_6 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_6 = V_34 -> V_177 [ V_50 ] ;
if ( ! V_6 )
continue;
F_239 ( V_6 , V_25 ,
V_359 ) ;
F_321 ( V_6 -> V_43 ) ;
F_322 ( V_6 -> V_43 ) ;
}
F_17 ( V_34 -> V_177 ) ;
}
static void F_323 ( struct V_6 * V_6 )
{
const struct V_34 * V_34 = V_6 -> V_34 ;
const struct V_38 * V_39 = V_34 -> V_39 ;
int V_54 ;
V_54 = F_159 ( V_6 ,
V_6 -> V_43 -> V_398 ) ;
if ( V_54 ) {
F_324 ( & V_39 -> V_43 , L_43 ) ;
F_325 ( V_6 -> V_43 ) ;
}
}
static int F_326 ( struct V_34 * V_34 , unsigned int V_37 )
{
const struct V_38 * V_39 = V_34 -> V_39 ;
struct V_6 * V_6 ;
struct V_154 * V_43 ;
T_2 V_543 = 0 ;
int V_54 ;
V_43 = F_327 ( sizeof( struct V_6 ) ) ;
if ( ! V_43 )
return - V_57 ;
V_6 = F_260 ( V_43 ) ;
V_6 -> V_43 = V_43 ;
V_6 -> V_34 = V_34 ;
V_6 -> V_37 = V_37 ;
V_6 -> V_171 = V_37 + 1 ;
V_6 -> V_240 = V_241 | V_426 ;
F_13 ( & V_6 -> V_22 ) ;
F_323 ( V_6 ) ;
V_43 -> V_544 = & V_545 ;
V_43 -> V_546 = & V_547 ;
V_43 -> V_548 = & V_549 ;
F_328 ( V_43 , & V_6 -> V_192 , F_309 ,
V_550 ) ;
F_328 ( V_43 , & V_6 -> V_193 , F_318 ,
V_550 ) ;
F_319 ( V_6 ) ;
V_43 -> V_551 |= V_552 ;
V_54 = F_329 ( V_43 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_44 ) ;
goto V_553;
}
V_34 -> V_177 [ V_37 ] = V_6 ;
F_162 ( V_6 , V_25 ) ;
V_54 = F_239 ( V_6 , V_25 , 0 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_45 ) ;
goto V_554;
}
V_6 -> V_9 =
F_254 ( V_6 , V_43 -> V_443 ) ;
V_54 = F_285 ( V_6 , V_25 ,
V_543 , 0 ) ;
if ( V_54 ) {
F_123 ( V_6 -> V_43 , L_46 ) ;
goto V_555;
}
return 0 ;
V_555:
F_239 ( V_6 , V_25 ,
V_359 ) ;
V_554:
F_321 ( V_43 ) ;
V_553:
F_322 ( V_43 ) ;
return V_54 ;
}
static int F_330 ( struct V_34 * V_34 )
{
int V_50 ;
T_3 V_556 ;
int V_54 ;
V_556 = sizeof( struct V_6 * ) * V_34 -> V_176 ;
V_34 -> V_177 = F_8 ( V_556 , V_20 ) ;
if ( ! V_34 -> V_177 )
return - V_57 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_176 ; V_50 ++ ) {
V_54 = F_326 ( V_34 , V_50 ) ;
if ( V_54 )
goto V_557;
}
return 0 ;
V_557:
F_320 ( V_34 ) ;
return V_54 ;
}
static int F_331 ( struct V_34 * V_34 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
int V_36 ;
int V_50 ;
int V_54 ;
V_36 = F_332 ( V_39 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 != F_333 ( V_34 -> V_176 ) )
return - V_111 ;
V_34 -> V_36 = F_334 ( V_36 ,
sizeof( struct V_558 ) ,
V_20 ) ;
if ( ! V_34 -> V_36 )
return - V_57 ;
for ( V_50 = 0 ; V_50 < V_36 ; V_50 ++ )
V_34 -> V_36 [ V_50 ] . V_243 = V_50 ;
V_54 = F_335 ( V_39 , V_34 -> V_36 , V_36 ) ;
if ( V_54 < 0 )
goto V_559;
return 0 ;
V_559:
F_17 ( V_34 -> V_36 ) ;
return V_54 ;
}
static void F_336 ( const struct V_34 * V_34 )
{
F_337 ( V_34 -> V_39 ) ;
F_17 ( V_34 -> V_36 ) ;
}
static int F_338 ( struct V_38 * V_39 , const struct V_560 * V_486 )
{
struct V_34 * V_34 ;
int V_54 ;
V_34 = F_8 ( sizeof( * V_34 ) , V_20 ) ;
if ( ! V_34 )
return - V_57 ;
V_54 = F_339 ( V_39 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_47 ) ;
goto V_561;
}
V_54 = F_340 ( V_39 , V_71 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_48 ) ;
goto V_562;
}
V_54 = F_341 ( V_39 , F_342 ( 64 ) ) ;
if ( ! V_54 ) {
V_54 = F_343 ( V_39 , F_342 ( 64 ) ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_49 ) ;
goto V_563;
}
} else {
V_54 = F_341 ( V_39 , F_342 ( 32 ) ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_50 ) ;
goto V_563;
}
}
if ( F_344 ( V_39 , 0 ) < V_564 ) {
F_36 ( & V_39 -> V_43 , L_51 ) ;
V_54 = - V_111 ;
goto V_565;
}
V_34 -> V_566 = F_345 ( F_346 ( V_39 , 0 ) ,
F_344 ( V_39 , 0 ) ) ;
if ( ! V_34 -> V_566 ) {
F_36 ( & V_39 -> V_43 , L_52 ) ;
V_54 = - V_44 ;
goto V_567;
}
F_347 ( V_39 ) ;
V_34 -> V_39 = V_39 ;
F_348 ( V_39 , V_34 ) ;
V_34 -> V_176 = F_35 ( V_34 , V_568 ) ;
V_54 = F_331 ( V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_53 ) ;
goto V_569;
}
V_54 = F_47 ( V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_54 ) ;
goto V_570;
}
F_34 ( V_34 , V_571 , V_572 ) ;
V_54 = F_109 ( V_34 ) ;
if ( V_54 )
goto V_573;
V_54 = F_48 ( F_27 ( V_34 , V_574 ) ,
F_127 , 0 ,
V_71 , V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_55 ) ;
goto V_575;
}
V_54 = F_48 ( F_27 ( V_34 , V_576 ) ,
F_140 , 0 ,
V_71 , V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_56 ) ;
goto V_577;
}
V_34 -> V_491 . V_486 = F_38 ( V_34 , V_578 ) ;
V_54 = F_180 ( V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_57 ) ;
goto V_579;
}
V_54 = F_330 ( V_34 ) ;
if ( V_54 ) {
F_36 ( & V_39 -> V_43 , L_58 ) ;
goto V_580;
}
F_349 ( & V_39 -> V_43 , L_59 , V_34 -> V_491 . V_486 ) ;
return 0 ;
V_580:
F_182 ( V_34 ) ;
V_579:
V_73 ( F_27 ( V_34 , V_576 ) , V_34 ) ;
V_577:
V_73 ( F_27 ( V_34 , V_574 ) , V_34 ) ;
V_575:
F_111 ( V_34 ) ;
V_573:
V_570:
F_336 ( V_34 ) ;
V_569:
F_350 ( V_34 -> V_566 ) ;
V_567:
V_565:
V_563:
F_351 ( V_39 ) ;
V_562:
F_352 ( V_39 ) ;
V_561:
F_17 ( V_34 ) ;
return V_54 ;
}
static void F_353 ( struct V_38 * V_39 )
{
struct V_34 * V_34 = F_354 ( V_39 ) ;
F_182 ( V_34 ) ;
F_34 ( V_34 , V_571 , V_572 ) ;
F_320 ( V_34 ) ;
V_73 ( F_27 ( V_34 , V_576 ) , V_34 ) ;
V_73 ( F_27 ( V_34 , V_574 ) , V_34 ) ;
F_111 ( V_34 ) ;
F_336 ( V_34 ) ;
F_350 ( V_34 -> V_566 ) ;
F_351 ( V_34 -> V_39 ) ;
F_352 ( V_34 -> V_39 ) ;
F_17 ( V_34 ) ;
}
static bool F_355 ( const struct V_154 * V_43 )
{
return V_43 -> V_544 == & V_545 ;
}
static int F_356 ( struct V_6 * V_6 ,
struct V_154 * V_275 )
{
T_2 V_543 = 0 ;
int V_54 ;
V_54 = F_290 ( V_6 , V_543 , 0 ) ;
if ( V_54 )
return V_54 ;
F_256 ( V_6 ,
V_6 -> V_43 -> V_443 ) ;
V_6 -> V_9 =
F_254 ( V_6 , V_275 -> V_443 ) ;
V_6 -> V_10 = V_275 ;
return F_285 ( V_6 , V_25 ,
V_543 , 0 ) ;
}
static int F_357 ( struct V_6 * V_6 )
{
T_2 V_543 = 0 ;
int V_54 ;
V_54 = F_290 ( V_6 , V_543 , 0 ) ;
if ( V_54 )
return V_54 ;
F_256 ( V_6 ,
V_6 -> V_10 -> V_443 ) ;
V_6 -> V_9 =
F_254 ( V_6 ,
V_6 -> V_43 -> V_443 ) ;
V_6 -> V_10 = NULL ;
V_54 = F_285 ( V_6 , V_25 ,
V_543 , 0 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_43 -> V_13 & V_581 )
V_54 = F_251 ( V_6 ,
V_25 , 0 ) ;
return V_54 ;
}
static int F_358 ( struct V_154 * V_43 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
struct V_154 * V_582 = F_359 ( V_43 ) ;
int V_54 = 0 ;
if ( V_582 && V_582 -> V_583 &&
! strcmp ( V_582 -> V_583 -> V_584 , L_60 ) )
V_54 = F_356 ( V_6 , V_582 ) ;
else if ( F_6 ( V_6 ) )
V_54 = F_357 ( V_6 ) ;
return V_54 ;
}
static int F_360 ( struct V_585 * V_586 ,
unsigned long V_587 , void * V_119 )
{
struct V_154 * V_43 ;
int V_54 ;
switch ( V_587 ) {
case V_588 :
V_43 = F_361 ( V_119 ) ;
if ( ! F_355 ( V_43 ) )
return V_589 ;
V_54 = F_358 ( V_43 ) ;
if ( V_54 )
F_362 ( V_43 ,
L_61 ,
V_54 ) ;
break;
}
return V_589 ;
}
static int F_363 ( struct V_154 * V_43 , struct V_399 * V_26 )
{
struct V_6 * V_6 = F_260 ( V_43 ) ;
int V_13 = ( V_26 -> V_402 & V_403 ? 0 : V_359 ) |
V_18 ;
T_10 V_391 = * ( T_10 * ) V_26 -> V_590 ;
return F_218 ( V_6 , V_25 ,
V_13 , V_391 , V_26 -> V_404 ) ;
}
static int F_364 ( struct V_585 * V_586 ,
unsigned long V_587 , void * V_119 )
{
struct V_154 * V_43 ;
struct V_399 * V_26 = V_119 ;
int V_54 ;
switch ( V_587 ) {
case V_591 :
if ( V_26 -> V_592 != & V_401 )
return V_589 ;
V_43 = V_26 -> V_43 ;
if ( ! F_355 ( V_43 ) )
return V_589 ;
V_54 = F_363 ( V_43 , V_26 ) ;
if ( V_54 )
F_362 ( V_43 ,
L_62 ,
V_54 ) ;
break;
}
return V_589 ;
}
static int T_15 F_365 ( void )
{
int V_54 ;
F_366 ( & V_593 ) ;
F_367 ( & V_594 ) ;
V_54 = F_368 ( & V_595 ) ;
if ( V_54 )
goto V_596;
return 0 ;
V_596:
F_369 ( & V_594 ) ;
F_370 ( & V_593 ) ;
return V_54 ;
}
static void T_16 F_371 ( void )
{
F_369 ( & V_594 ) ;
F_370 ( & V_593 ) ;
F_372 ( & V_595 ) ;
}
