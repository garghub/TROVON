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
V_15 -> V_21 = F_10 ( & V_22 , V_16 ) ;
if ( F_11 ( V_15 -> V_21 ) )
V_15 -> V_18 |= V_23 ;
}
if ( ( V_16 = F_9 ( * V_1 ++ ) ) != ( T_2 ) - 1 ) {
V_15 -> V_24 = F_12 ( & V_22 , V_16 ) ;
if ( F_13 ( V_15 -> V_24 ) )
V_15 -> V_18 |= V_25 ;
}
if ( ( V_16 = F_9 ( * V_1 ++ ) ) != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_26 ;
V_15 -> V_27 = V_16 ;
}
V_16 = F_9 ( * V_1 ++ ) ; V_17 = F_9 ( * V_1 ++ ) ;
if ( V_16 != ( T_2 ) - 1 && V_17 != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_28 | V_29 ;
V_15 -> V_30 . V_31 = V_16 ;
V_15 -> V_30 . V_32 = V_17 * 1000 ;
}
V_16 = F_9 ( * V_1 ++ ) ; V_17 = F_9 ( * V_1 ++ ) ;
if ( V_16 != ( T_2 ) - 1 && V_17 != ( T_2 ) - 1 ) {
V_15 -> V_18 |= V_33 | V_34 ;
V_15 -> V_35 . V_31 = V_16 ;
V_15 -> V_35 . V_32 = V_17 * 1000 ;
if ( V_17 == 1000000 )
V_15 -> V_18 &= ~ ( V_29 | V_34 ) ;
}
return V_1 ;
}
static T_1 *
F_14 ( struct V_36 * V_37 , T_1 * V_1 , struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_40 * V_40 = V_3 -> V_41 ;
int type ;
struct V_42 time ;
T_2 V_43 ;
type = ( V_39 -> V_44 & V_45 ) ;
* V_1 ++ = F_15 ( V_46 [ type >> 12 ] ) ;
* V_1 ++ = F_15 ( ( T_2 ) ( V_39 -> V_44 & V_47 ) ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_48 ) ;
* V_1 ++ = F_15 ( ( T_2 ) F_16 ( & V_22 , V_39 -> V_49 ) ) ;
* V_1 ++ = F_15 ( ( T_2 ) F_17 ( & V_22 , V_39 -> V_50 ) ) ;
if ( F_18 ( type ) && V_39 -> V_51 > V_13 ) {
* V_1 ++ = F_15 ( V_13 ) ;
} else {
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_51 ) ;
}
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_52 ) ;
if ( F_19 ( type ) || F_20 ( type ) )
* V_1 ++ = F_15 ( F_21 ( V_39 -> V_53 ) ) ;
else
* V_1 ++ = F_15 ( 0xffffffff ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_54 ) ;
switch ( F_22 ( V_3 ) ) {
default:
case V_55 :
* V_1 ++ = F_15 ( F_21 ( V_39 -> V_56 ) ) ;
break;
case V_57 :
* V_1 ++ = F_15 ( ( T_2 ) V_3 -> V_58 -> V_59 ) ;
break;
case V_60 :
V_43 = ( ( T_2 * ) V_3 -> V_58 -> V_61 ) [ 0 ] ;
V_43 ^= ( ( T_2 * ) V_3 -> V_58 -> V_61 ) [ 1 ] ;
V_43 ^= ( ( T_2 * ) V_3 -> V_58 -> V_61 ) [ 2 ] ;
V_43 ^= ( ( T_2 * ) V_3 -> V_58 -> V_61 ) [ 3 ] ;
* V_1 ++ = F_15 ( V_43 ) ;
break;
}
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_62 ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_63 . V_31 ) ;
* V_1 ++ = F_15 ( V_39 -> V_63 . V_32 ? V_39 -> V_63 . V_32 / 1000 : 0 ) ;
F_23 ( V_40 -> V_64 , & time ) ;
* V_1 ++ = F_15 ( ( T_2 ) time . V_31 ) ;
* V_1 ++ = F_15 ( time . V_32 ? time . V_32 / 1000 : 0 ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> ctime . V_31 ) ;
* V_1 ++ = F_15 ( V_39 -> ctime . V_32 ? V_39 -> ctime . V_32 / 1000 : 0 ) ;
return V_1 ;
}
T_1 * F_24 ( struct V_36 * V_37 , T_1 * V_1 , struct V_2 * V_3 , struct V_38 * V_39 )
{
return F_14 ( V_37 , V_1 , V_3 , V_39 ) ;
}
int
F_25 ( struct V_36 * V_37 , T_1 * V_1 , void * V_65 )
{
return F_26 ( V_37 , V_1 ) ;
}
int
F_27 ( struct V_36 * V_37 , T_1 * V_1 , struct V_66 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_28 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_68 * args )
{
V_1 = F_1 ( V_1 , & args -> V_67 ) ;
if ( ! V_1 )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_69 ) ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_29 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_70 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_10 , & args -> V_71 ) ) )
return 0 ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_30 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_72 * args )
{
unsigned int V_71 ;
int V_73 ;
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
args -> V_74 = F_9 ( * V_1 ++ ) ;
V_71 = args -> V_75 = F_9 ( * V_1 ++ ) ;
V_1 ++ ;
if ( V_71 > V_76 )
V_71 = V_76 ;
V_73 = 0 ;
while ( V_71 > 0 ) {
struct V_77 * V_1 = * ( V_37 -> V_78 ++ ) ;
V_37 -> V_79 [ V_73 ] . V_80 = F_31 ( V_1 ) ;
V_37 -> V_79 [ V_73 ] . V_81 = V_71 < V_82 ? V_71 : V_82 ;
V_71 -= V_37 -> V_79 [ V_73 ] . V_81 ;
V_73 ++ ;
}
args -> V_83 = V_73 ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_32 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_84 * args )
{
unsigned int V_71 , V_85 , V_86 ;
int V_73 ;
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
V_1 ++ ;
args -> V_74 = F_9 ( * V_1 ++ ) ;
V_1 ++ ;
V_71 = args -> V_71 = F_9 ( * V_1 ++ ) ;
if ( V_71 > V_76 )
return 0 ;
V_85 = ( void * ) V_1 - V_37 -> V_87 . V_88 [ 0 ] . V_80 ;
V_86 = V_37 -> V_87 . V_88 [ 0 ] . V_81 + V_37 -> V_87 . V_89
- V_85 ;
if ( V_86 < F_33 ( V_71 ) * 4 )
return 0 ;
V_37 -> V_79 [ 0 ] . V_80 = ( void * ) V_1 ;
V_37 -> V_79 [ 0 ] . V_81 = V_37 -> V_87 . V_88 [ 0 ] . V_81 - V_85 ;
V_73 = 0 ;
while ( V_71 > V_37 -> V_79 [ V_73 ] . V_81 ) {
V_71 -= V_37 -> V_79 [ V_73 ] . V_81 ;
V_73 ++ ;
V_37 -> V_79 [ V_73 ] . V_80 = F_31 ( V_37 -> V_90 [ V_73 ] ) ;
V_37 -> V_79 [ V_73 ] . V_81 = V_82 ;
}
V_37 -> V_79 [ V_73 ] . V_81 = V_71 ;
args -> V_83 = V_73 + 1 ;
return 1 ;
}
int
F_34 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_91 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_10 , & args -> V_71 ) ) )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_69 ) ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_35 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_92 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_93 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_94 , & args -> V_95 ) )
|| ! ( V_1 = F_1 ( V_1 , & args -> V_96 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_97 , & args -> V_98 ) ) )
return 0 ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_36 ( struct V_36 * V_37 , T_1 * V_1 , struct V_99 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
args -> V_100 = F_31 ( * ( V_37 -> V_78 ++ ) ) ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_37 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_101 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_93 ) )
|| ! ( V_1 = F_1 ( V_1 , & args -> V_96 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_97 , & args -> V_98 ) ) )
return 0 ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_38 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_102 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_93 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_94 , & args -> V_95 ) )
|| ! ( V_1 = F_7 ( V_1 , & args -> V_97 , & args -> V_98 ) ) )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_69 ) ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_39 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_103 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_67 ) ) )
return 0 ;
args -> V_104 = F_9 ( * V_1 ++ ) ;
args -> V_75 = F_9 ( * V_1 ++ ) ;
if ( args -> V_75 > V_82 )
args -> V_75 = V_82 ;
args -> V_100 = F_31 ( * ( V_37 -> V_78 ++ ) ) ;
return F_26 ( V_37 , V_1 ) ;
}
int
F_40 ( struct V_36 * V_37 , T_1 * V_1 , void * V_65 )
{
return F_41 ( V_37 , V_1 ) ;
}
int
F_42 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_105 * V_106 )
{
V_1 = F_14 ( V_37 , V_1 , & V_106 -> V_67 , & V_106 -> V_39 ) ;
return F_41 ( V_37 , V_1 ) ;
}
int
F_43 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_107 * V_106 )
{
V_1 = F_4 ( V_1 , & V_106 -> V_67 ) ;
V_1 = F_14 ( V_37 , V_1 , & V_106 -> V_67 , & V_106 -> V_39 ) ;
return F_41 ( V_37 , V_1 ) ;
}
int
F_44 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_108 * V_106 )
{
* V_1 ++ = F_15 ( V_106 -> V_71 ) ;
F_41 ( V_37 , V_1 ) ;
V_37 -> V_109 . V_89 = V_106 -> V_71 ;
if ( V_106 -> V_71 & 3 ) {
V_37 -> V_109 . V_110 [ 0 ] . V_80 = V_1 ;
* V_1 = 0 ;
V_37 -> V_109 . V_110 [ 0 ] . V_81 = 4 - ( V_106 -> V_71 & 3 ) ;
}
return 1 ;
}
int
F_45 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_111 * V_106 )
{
V_1 = F_14 ( V_37 , V_1 , & V_106 -> V_67 , & V_106 -> V_39 ) ;
* V_1 ++ = F_15 ( V_106 -> V_75 ) ;
F_41 ( V_37 , V_1 ) ;
V_37 -> V_109 . V_89 = V_106 -> V_75 ;
if ( V_106 -> V_75 & 3 ) {
V_37 -> V_109 . V_110 [ 0 ] . V_80 = V_1 ;
* V_1 = 0 ;
V_37 -> V_109 . V_110 [ 0 ] . V_81 = 4 - ( V_106 -> V_75 & 3 ) ;
}
return 1 ;
}
int
F_46 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_112 * V_106 )
{
F_41 ( V_37 , V_1 ) ;
V_1 = V_106 -> V_100 ;
* V_1 ++ = 0 ;
* V_1 ++ = F_15 ( ( V_106 -> V_113 . V_114 == V_115 ) ) ;
V_37 -> V_109 . V_89 = ( ( ( unsigned long ) V_1 - 1 ) & ~ V_116 ) + 1 ;
return 1 ;
}
int
F_47 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_117 * V_106 )
{
struct V_118 * V_39 = & V_106 -> V_119 ;
* V_1 ++ = F_15 ( V_76 ) ;
* V_1 ++ = F_15 ( V_39 -> V_120 ) ;
* V_1 ++ = F_15 ( V_39 -> V_121 ) ;
* V_1 ++ = F_15 ( V_39 -> V_122 ) ;
* V_1 ++ = F_15 ( V_39 -> V_123 ) ;
return F_41 ( V_37 , V_1 ) ;
}
int
F_48 ( void * V_124 , const char * V_10 ,
int V_125 , T_3 V_74 , T_4 V_62 , unsigned int V_126 )
{
struct V_127 * V_128 = V_124 ;
struct V_112 * V_129 = F_49 ( V_128 , struct V_112 , V_113 ) ;
T_1 * V_1 = V_129 -> V_100 ;
int V_130 , V_131 ;
if ( V_74 > ~ ( ( T_2 ) 0 ) ) {
V_129 -> V_113 . V_114 = V_132 ;
return - V_133 ;
}
if ( V_129 -> V_74 )
* V_129 -> V_74 = F_15 ( V_74 ) ;
if ( V_125 > V_134 )
V_125 = V_134 ;
V_131 = F_33 ( V_125 ) ;
if ( ( V_130 = V_129 -> V_130 - V_131 - 4 ) < 0 ) {
V_129 -> V_113 . V_114 = V_135 ;
return - V_133 ;
}
if ( V_62 > ~ ( ( T_2 ) 0 ) ) {
V_129 -> V_113 . V_114 = V_132 ;
return - V_133 ;
}
* V_1 ++ = V_136 ;
* V_1 ++ = F_15 ( ( T_2 ) V_62 ) ;
V_1 = F_50 ( V_1 , V_10 , V_125 ) ;
V_129 -> V_74 = V_1 ;
* V_1 ++ = F_15 ( ~ 0U ) ;
V_129 -> V_130 = V_130 ;
V_129 -> V_100 = V_1 ;
V_129 -> V_113 . V_114 = V_137 ;
return 0 ;
}
int
F_51 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_66 * V_106 )
{
F_52 ( & V_106 -> V_67 ) ;
return 1 ;
}
