static T_1 *
F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( V_3 , V_4 ) ;
memcpy ( & V_3 -> V_5 . V_6 , V_1 , V_4 ) ;
V_3 -> V_5 . V_7 = V_4 ;
return V_1 + ( V_4 >> 2 ) ;
}
T_1 * F_3 ( T_1 * V_1 , struct V_2 * V_3 )
{
return F_1 ( V_1 , V_3 ) ;
}
static T_1 *
F_4 ( T_1 * V_1 , struct V_2 * V_3 )
{
memcpy ( V_1 , & V_3 -> V_5 . V_6 , V_4 ) ;
return V_1 + ( V_4 >> 2 ) ;
}
static T_1 *
F_5 ( T_1 * V_1 , char * * V_8 , unsigned int * V_9 )
{
char * V_10 ;
unsigned int V_11 ;
if ( ( V_1 = F_6 ( V_1 , V_8 , V_9 , V_12 ) ) != NULL ) {
for ( V_11 = 0 , V_10 = * V_8 ; V_11 < * V_9 ; V_11 ++ , V_10 ++ ) {
if ( * V_10 == '\0' || * V_10 == '/' )
return NULL ;
}
}
return V_1 ;
}
static T_1 *
F_7 ( T_1 * V_1 , char * * V_8 , unsigned int * V_9 )
{
char * V_10 ;
unsigned int V_11 ;
if ( ( V_1 = F_6 ( V_1 , V_8 , V_9 , V_13 ) ) != NULL ) {
for ( V_11 = 0 , V_10 = * V_8 ; V_11 < * V_9 ; V_11 ++ , V_10 ++ ) {
if ( * V_10 == '\0' )
return NULL ;
}
}
return V_1 ;
}
static T_1 *
F_8 ( T_1 * V_1 , struct V_14 * V_15 )
{
T_2 V_16 , V_17 ;
V_15 -> V_18 = 0 ;
if ( ( V_16 = F_9 ( * V_1 ++ ) ) != ( T_2 ) - 1 && V_16 != 0xffff ) {
V_15 -> V_18 |= V_19 ;
V_15 -> V_20 = V_16 ;
}
if ( ( V_16 = F_9 ( * V_1 ++ ) ) != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_21 ;
V_15 -> V_22 = V_16 ;
}
if ( ( V_16 = F_9 ( * V_1 ++ ) ) != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_23 ;
V_15 -> V_24 = V_16 ;
}
if ( ( V_16 = F_9 ( * V_1 ++ ) ) != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_25 ;
V_15 -> V_26 = V_16 ;
}
V_16 = F_9 ( * V_1 ++ ) ; V_17 = F_9 ( * V_1 ++ ) ;
if ( V_16 != ( T_2 ) - 1 && V_17 != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_27 | V_28 ;
V_15 -> V_29 . V_30 = V_16 ;
V_15 -> V_29 . V_31 = V_17 * 1000 ;
}
V_16 = F_9 ( * V_1 ++ ) ; V_17 = F_9 ( * V_1 ++ ) ;
if ( V_16 != ( T_2 ) - 1 && V_17 != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_32 | V_33 ;
V_15 -> V_34 . V_30 = V_16 ;
V_15 -> V_34 . V_31 = V_17 * 1000 ;
if ( V_17 == 1000000 )
V_15 -> V_18 &= ~ ( V_28 | V_33 ) ;
}
return V_1 ;
}
static T_1 *
F_10 ( struct V_35 * V_36 , T_1 * V_1 , struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_39 * V_39 = V_3 -> V_40 ;
int type ;
struct V_41 time ;
T_2 V_42 ;
type = ( V_38 -> V_43 & V_44 ) ;
* V_1 ++ = F_11 ( V_45 [ type >> 12 ] ) ;
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_43 ) ;
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_46 ) ;
* V_1 ++ = F_11 ( ( T_2 ) F_12 ( V_36 , V_38 -> V_47 ) ) ;
* V_1 ++ = F_11 ( ( T_2 ) F_13 ( V_36 , V_38 -> V_48 ) ) ;
if ( F_14 ( type ) && V_38 -> V_49 > V_13 ) {
* V_1 ++ = F_11 ( V_13 ) ;
} else {
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_49 ) ;
}
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_50 ) ;
if ( F_15 ( type ) || F_16 ( type ) )
* V_1 ++ = F_11 ( F_17 ( V_38 -> V_51 ) ) ;
else
* V_1 ++ = F_11 ( 0xffffffff ) ;
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_52 ) ;
switch ( F_18 ( V_3 ) ) {
default:
case V_53 :
* V_1 ++ = F_11 ( F_17 ( V_38 -> V_54 ) ) ;
break;
case V_55 :
* V_1 ++ = F_11 ( ( T_2 ) V_3 -> V_56 -> V_57 ) ;
break;
case V_58 :
V_42 = ( ( T_2 * ) V_3 -> V_56 -> V_59 ) [ 0 ] ;
V_42 ^= ( ( T_2 * ) V_3 -> V_56 -> V_59 ) [ 1 ] ;
V_42 ^= ( ( T_2 * ) V_3 -> V_56 -> V_59 ) [ 2 ] ;
V_42 ^= ( ( T_2 * ) V_3 -> V_56 -> V_59 ) [ 3 ] ;
* V_1 ++ = F_11 ( V_42 ) ;
break;
}
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_60 ) ;
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> V_61 . V_30 ) ;
* V_1 ++ = F_11 ( V_38 -> V_61 . V_31 ? V_38 -> V_61 . V_31 / 1000 : 0 ) ;
F_19 ( V_39 -> V_62 , & time ) ;
* V_1 ++ = F_11 ( ( T_2 ) time . V_30 ) ;
* V_1 ++ = F_11 ( time . V_31 ? time . V_31 / 1000 : 0 ) ;
* V_1 ++ = F_11 ( ( T_2 ) V_38 -> ctime . V_30 ) ;
* V_1 ++ = F_11 ( V_38 -> ctime . V_31 ? V_38 -> ctime . V_31 / 1000 : 0 ) ;
return V_1 ;
}
T_1 * F_20 ( struct V_35 * V_36 , T_1 * V_1 , struct V_2 * V_3 )
{
struct V_37 V_38 ;
F_21 ( V_3 -> V_56 -> V_63 . V_64 , V_3 -> V_40 , & V_38 ) ;
return F_10 ( V_36 , V_1 , V_3 , & V_38 ) ;
}
int
F_22 ( struct V_35 * V_36 , T_1 * V_1 , void * V_65 )
{
return F_23 ( V_36 , V_1 ) ;
}
int
F_24 ( struct V_35 * V_36 , T_1 * V_1 , struct V_66 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_25 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_68 * args )
{
V_1 = F_1 ( V_1 , & args -> V_67 ) ;
if ( ! V_1 )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_69 ) ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_26 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_70 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_10 , & args -> V_71 ) ) )
return 0 ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_27 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_72 * args )
{
unsigned int V_71 ;
int V_73 , V_74 ;
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
args -> V_75 = F_9 ( * V_1 ++ ) ;
V_71 = args -> V_76 = F_9 ( * V_1 ++ ) ;
V_1 ++ ;
if ( V_71 > V_77 )
V_71 = V_77 ;
V_73 = 0 ;
while ( V_71 > 0 ) {
V_74 = V_36 -> V_78 ++ ;
V_36 -> V_79 [ V_73 ] . V_80 = F_28 ( V_36 -> V_81 [ V_74 ] ) ;
V_36 -> V_79 [ V_73 ] . V_82 = V_71 < V_83 ? V_71 : V_83 ;
V_71 -= V_36 -> V_79 [ V_73 ] . V_82 ;
V_73 ++ ;
}
args -> V_84 = V_73 ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_29 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_85 * args )
{
unsigned int V_71 , V_86 , V_87 ;
int V_73 ;
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
V_1 ++ ;
args -> V_75 = F_9 ( * V_1 ++ ) ;
V_1 ++ ;
V_71 = args -> V_71 = F_9 ( * V_1 ++ ) ;
if ( V_71 > V_77 )
return 0 ;
V_86 = ( void * ) V_1 - V_36 -> V_88 . V_89 [ 0 ] . V_80 ;
V_87 = V_36 -> V_88 . V_89 [ 0 ] . V_82 + V_36 -> V_88 . V_90
- V_86 ;
if ( V_87 < F_30 ( V_71 ) * 4 )
return 0 ;
V_36 -> V_79 [ 0 ] . V_80 = ( void * ) V_1 ;
V_36 -> V_79 [ 0 ] . V_82 = V_36 -> V_88 . V_89 [ 0 ] . V_82 - V_86 ;
V_73 = 0 ;
while ( V_71 > V_36 -> V_79 [ V_73 ] . V_82 ) {
V_71 -= V_36 -> V_79 [ V_73 ] . V_82 ;
V_73 ++ ;
V_36 -> V_79 [ V_73 ] . V_80 = F_28 ( V_36 -> V_91 [ V_73 ] ) ;
V_36 -> V_79 [ V_73 ] . V_82 = V_83 ;
}
V_36 -> V_79 [ V_73 ] . V_82 = V_71 ;
args -> V_84 = V_73 + 1 ;
return 1 ;
}
int
F_31 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_92 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_10 , & args -> V_71 ) ) )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_69 ) ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_32 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_93 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_94 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_95 , & args -> V_96 ) )
|| ! ( V_1 = F_1 ( V_1 , & args -> V_97 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_98 , & args -> V_99 ) ) )
return 0 ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_33 ( struct V_35 * V_36 , T_1 * V_1 , struct V_100 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
args -> V_101 = F_28 ( V_36 -> V_81 [ V_36 -> V_78 ++ ] ) ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_34 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_102 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_94 ) )
|| ! ( V_1 = F_1 ( V_1 , & args -> V_97 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_98 , & args -> V_99 ) ) )
return 0 ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_35 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_103 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_94 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_95 , & args -> V_96 ) )
|| ! ( V_1 = F_7 ( V_1 , & args -> V_98 , & args -> V_99 ) ) )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_69 ) ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_36 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_104 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
args -> V_105 = F_9 ( * V_1 ++ ) ;
args -> V_76 = F_9 ( * V_1 ++ ) ;
if ( args -> V_76 > V_83 )
args -> V_76 = V_83 ;
args -> V_101 = F_28 ( V_36 -> V_81 [ V_36 -> V_78 ++ ] ) ;
return F_23 ( V_36 , V_1 ) ;
}
int
F_37 ( struct V_35 * V_36 , T_1 * V_1 , void * V_65 )
{
return F_38 ( V_36 , V_1 ) ;
}
int
F_39 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_106 * V_107 )
{
V_1 = F_10 ( V_36 , V_1 , & V_107 -> V_67 , & V_107 -> V_38 ) ;
return F_38 ( V_36 , V_1 ) ;
}
int
F_40 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_108 * V_107 )
{
V_1 = F_4 ( V_1 , & V_107 -> V_67 ) ;
V_1 = F_10 ( V_36 , V_1 , & V_107 -> V_67 , & V_107 -> V_38 ) ;
return F_38 ( V_36 , V_1 ) ;
}
int
F_41 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_109 * V_107 )
{
* V_1 ++ = F_11 ( V_107 -> V_71 ) ;
F_38 ( V_36 , V_1 ) ;
V_36 -> V_110 . V_90 = V_107 -> V_71 ;
if ( V_107 -> V_71 & 3 ) {
V_36 -> V_110 . V_111 [ 0 ] . V_80 = V_1 ;
* V_1 = 0 ;
V_36 -> V_110 . V_111 [ 0 ] . V_82 = 4 - ( V_107 -> V_71 & 3 ) ;
}
return 1 ;
}
int
F_42 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_112 * V_107 )
{
V_1 = F_10 ( V_36 , V_1 , & V_107 -> V_67 , & V_107 -> V_38 ) ;
* V_1 ++ = F_11 ( V_107 -> V_76 ) ;
F_38 ( V_36 , V_1 ) ;
V_36 -> V_110 . V_90 = V_107 -> V_76 ;
if ( V_107 -> V_76 & 3 ) {
V_36 -> V_110 . V_111 [ 0 ] . V_80 = V_1 ;
* V_1 = 0 ;
V_36 -> V_110 . V_111 [ 0 ] . V_82 = 4 - ( V_107 -> V_76 & 3 ) ;
}
return 1 ;
}
int
F_43 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_113 * V_107 )
{
F_38 ( V_36 , V_1 ) ;
V_1 = V_107 -> V_101 ;
* V_1 ++ = 0 ;
* V_1 ++ = F_11 ( ( V_107 -> V_114 . V_115 == V_116 ) ) ;
V_36 -> V_110 . V_90 = ( ( ( unsigned long ) V_1 - 1 ) & ~ V_117 ) + 1 ;
return 1 ;
}
int
F_44 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_118 * V_107 )
{
struct V_119 * V_38 = & V_107 -> V_120 ;
* V_1 ++ = F_11 ( V_77 ) ;
* V_1 ++ = F_11 ( V_38 -> V_121 ) ;
* V_1 ++ = F_11 ( V_38 -> V_122 ) ;
* V_1 ++ = F_11 ( V_38 -> V_123 ) ;
* V_1 ++ = F_11 ( V_38 -> V_124 ) ;
return F_38 ( V_36 , V_1 ) ;
}
int
F_45 ( void * V_125 , const char * V_10 ,
int V_126 , T_3 V_75 , T_4 V_60 , unsigned int V_127 )
{
struct V_128 * V_129 = V_125 ;
struct V_113 * V_130 = F_46 ( V_129 , struct V_113 , V_114 ) ;
T_1 * V_1 = V_130 -> V_101 ;
int V_131 , V_132 ;
if ( V_75 > ~ ( ( T_2 ) 0 ) ) {
V_130 -> V_114 . V_115 = V_133 ;
return - V_134 ;
}
if ( V_130 -> V_75 )
* V_130 -> V_75 = F_11 ( V_75 ) ;
if ( V_126 > V_135 )
V_126 = V_135 ;
V_132 = F_30 ( V_126 ) ;
if ( ( V_131 = V_130 -> V_131 - V_132 - 4 ) < 0 ) {
V_130 -> V_114 . V_115 = V_136 ;
return - V_134 ;
}
if ( V_60 > ~ ( ( T_2 ) 0 ) ) {
V_130 -> V_114 . V_115 = V_133 ;
return - V_134 ;
}
* V_1 ++ = V_137 ;
* V_1 ++ = F_11 ( ( T_2 ) V_60 ) ;
V_1 = F_47 ( V_1 , V_10 , V_126 ) ;
V_130 -> V_75 = V_1 ;
* V_1 ++ = F_11 ( ~ 0U ) ;
V_130 -> V_131 = V_131 ;
V_130 -> V_101 = V_1 ;
V_130 -> V_114 . V_115 = V_138 ;
return 0 ;
}
int
F_48 ( struct V_35 * V_36 , T_1 * V_1 ,
struct V_66 * V_107 )
{
F_49 ( & V_107 -> V_67 ) ;
return 1 ;
}
