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
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_44 ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_47 ) ;
* V_1 ++ = F_15 ( ( T_2 ) F_16 ( & V_22 , V_39 -> V_48 ) ) ;
* V_1 ++ = F_15 ( ( T_2 ) F_17 ( & V_22 , V_39 -> V_49 ) ) ;
if ( F_18 ( type ) && V_39 -> V_50 > V_13 ) {
* V_1 ++ = F_15 ( V_13 ) ;
} else {
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_50 ) ;
}
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_51 ) ;
if ( F_19 ( type ) || F_20 ( type ) )
* V_1 ++ = F_15 ( F_21 ( V_39 -> V_52 ) ) ;
else
* V_1 ++ = F_15 ( 0xffffffff ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_53 ) ;
switch ( F_22 ( V_3 ) ) {
default:
case V_54 :
* V_1 ++ = F_15 ( F_21 ( V_39 -> V_55 ) ) ;
break;
case V_56 :
* V_1 ++ = F_15 ( ( T_2 ) V_3 -> V_57 -> V_58 ) ;
break;
case V_59 :
V_43 = ( ( T_2 * ) V_3 -> V_57 -> V_60 ) [ 0 ] ;
V_43 ^= ( ( T_2 * ) V_3 -> V_57 -> V_60 ) [ 1 ] ;
V_43 ^= ( ( T_2 * ) V_3 -> V_57 -> V_60 ) [ 2 ] ;
V_43 ^= ( ( T_2 * ) V_3 -> V_57 -> V_60 ) [ 3 ] ;
* V_1 ++ = F_15 ( V_43 ) ;
break;
}
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_61 ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> V_62 . V_31 ) ;
* V_1 ++ = F_15 ( V_39 -> V_62 . V_32 ? V_39 -> V_62 . V_32 / 1000 : 0 ) ;
F_23 ( F_24 ( V_40 ) , & time ) ;
* V_1 ++ = F_15 ( ( T_2 ) time . V_31 ) ;
* V_1 ++ = F_15 ( time . V_32 ? time . V_32 / 1000 : 0 ) ;
* V_1 ++ = F_15 ( ( T_2 ) V_39 -> ctime . V_31 ) ;
* V_1 ++ = F_15 ( V_39 -> ctime . V_32 ? V_39 -> ctime . V_32 / 1000 : 0 ) ;
return V_1 ;
}
T_1 * F_25 ( struct V_36 * V_37 , T_1 * V_1 , struct V_2 * V_3 , struct V_38 * V_39 )
{
return F_14 ( V_37 , V_1 , V_3 , V_39 ) ;
}
int
F_26 ( struct V_36 * V_37 , T_1 * V_1 , void * V_63 )
{
return F_27 ( V_37 , V_1 ) ;
}
int
F_28 ( struct V_36 * V_37 , T_1 * V_1 , struct V_64 * args )
{
V_1 = F_1 ( V_1 , & args -> V_65 ) ;
if ( ! V_1 )
return 0 ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_29 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_66 * args )
{
V_1 = F_1 ( V_1 , & args -> V_65 ) ;
if ( ! V_1 )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_67 ) ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_30 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_68 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_65 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_10 , & args -> V_69 ) ) )
return 0 ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_31 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_70 * args )
{
unsigned int V_69 ;
int V_71 ;
V_1 = F_1 ( V_1 , & args -> V_65 ) ;
if ( ! V_1 )
return 0 ;
args -> V_72 = F_9 ( * V_1 ++ ) ;
V_69 = args -> V_73 = F_9 ( * V_1 ++ ) ;
V_1 ++ ;
V_69 = F_32 (unsigned int, len, NFSSVC_MAXBLKSIZE_V2) ;
V_71 = 0 ;
while ( V_69 > 0 ) {
struct V_74 * V_1 = * ( V_37 -> V_75 ++ ) ;
V_37 -> V_76 [ V_71 ] . V_77 = F_33 ( V_1 ) ;
V_37 -> V_76 [ V_71 ] . V_78 = F_32 (unsigned int, len, PAGE_SIZE) ;
V_69 -= V_37 -> V_76 [ V_71 ] . V_78 ;
V_71 ++ ;
}
args -> V_79 = V_71 ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_34 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_80 * args )
{
unsigned int V_69 , V_81 , V_82 ;
struct V_83 * V_84 = V_37 -> V_85 . V_84 ;
int V_71 ;
V_1 = F_1 ( V_1 , & args -> V_65 ) ;
if ( ! V_1 )
return 0 ;
V_1 ++ ;
args -> V_72 = F_9 ( * V_1 ++ ) ;
V_1 ++ ;
V_69 = args -> V_69 = F_9 ( * V_1 ++ ) ;
if ( V_69 > V_86 )
return 0 ;
V_81 = ( void * ) V_1 - V_84 -> V_77 ;
if ( V_81 > V_84 -> V_78 )
return 0 ;
V_82 = V_84 -> V_78 + V_37 -> V_85 . V_87 - V_81 ;
if ( V_82 < F_35 ( V_69 ) * 4 )
return 0 ;
V_37 -> V_76 [ 0 ] . V_77 = ( void * ) V_1 ;
V_37 -> V_76 [ 0 ] . V_78 = V_84 -> V_78 - V_81 ;
V_71 = 0 ;
while ( V_69 > V_37 -> V_76 [ V_71 ] . V_78 ) {
V_69 -= V_37 -> V_76 [ V_71 ] . V_78 ;
V_71 ++ ;
V_37 -> V_76 [ V_71 ] . V_77 = F_33 ( V_37 -> V_88 [ V_71 ] ) ;
V_37 -> V_76 [ V_71 ] . V_78 = V_89 ;
}
V_37 -> V_76 [ V_71 ] . V_78 = V_69 ;
args -> V_79 = V_71 + 1 ;
return 1 ;
}
int
F_36 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_90 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_65 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_10 , & args -> V_69 ) ) )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_67 ) ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_37 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_91 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_92 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_93 , & args -> V_94 ) )
|| ! ( V_1 = F_1 ( V_1 , & args -> V_95 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_96 , & args -> V_97 ) ) )
return 0 ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_38 ( struct V_36 * V_37 , T_1 * V_1 , struct V_98 * args )
{
V_1 = F_1 ( V_1 , & args -> V_65 ) ;
if ( ! V_1 )
return 0 ;
args -> V_99 = F_33 ( * ( V_37 -> V_75 ++ ) ) ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_39 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_100 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_92 ) )
|| ! ( V_1 = F_1 ( V_1 , & args -> V_95 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_96 , & args -> V_97 ) ) )
return 0 ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_40 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_101 * args )
{
if ( ! ( V_1 = F_1 ( V_1 , & args -> V_92 ) )
|| ! ( V_1 = F_5 ( V_1 , & args -> V_93 , & args -> V_94 ) )
|| ! ( V_1 = F_7 ( V_1 , & args -> V_96 , & args -> V_97 ) ) )
return 0 ;
V_1 = F_8 ( V_1 , & args -> V_67 ) ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_41 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_102 * args )
{
V_1 = F_1 ( V_1 , & args -> V_65 ) ;
if ( ! V_1 )
return 0 ;
args -> V_103 = F_9 ( * V_1 ++ ) ;
args -> V_73 = F_9 ( * V_1 ++ ) ;
args -> V_73 = F_32 ( T_2 , args -> V_73 , V_89 ) ;
args -> V_99 = F_33 ( * ( V_37 -> V_75 ++ ) ) ;
return F_27 ( V_37 , V_1 ) ;
}
int
F_42 ( struct V_36 * V_37 , T_1 * V_1 , void * V_63 )
{
return F_43 ( V_37 , V_1 ) ;
}
int
F_44 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_104 * V_105 )
{
V_1 = F_14 ( V_37 , V_1 , & V_105 -> V_65 , & V_105 -> V_39 ) ;
return F_43 ( V_37 , V_1 ) ;
}
int
F_45 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_106 * V_105 )
{
V_1 = F_4 ( V_1 , & V_105 -> V_65 ) ;
V_1 = F_14 ( V_37 , V_1 , & V_105 -> V_65 , & V_105 -> V_39 ) ;
return F_43 ( V_37 , V_1 ) ;
}
int
F_46 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_107 * V_105 )
{
* V_1 ++ = F_15 ( V_105 -> V_69 ) ;
F_43 ( V_37 , V_1 ) ;
V_37 -> V_108 . V_87 = V_105 -> V_69 ;
if ( V_105 -> V_69 & 3 ) {
V_37 -> V_108 . V_109 [ 0 ] . V_77 = V_1 ;
* V_1 = 0 ;
V_37 -> V_108 . V_109 [ 0 ] . V_78 = 4 - ( V_105 -> V_69 & 3 ) ;
}
return 1 ;
}
int
F_47 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_110 * V_105 )
{
V_1 = F_14 ( V_37 , V_1 , & V_105 -> V_65 , & V_105 -> V_39 ) ;
* V_1 ++ = F_15 ( V_105 -> V_73 ) ;
F_43 ( V_37 , V_1 ) ;
V_37 -> V_108 . V_87 = V_105 -> V_73 ;
if ( V_105 -> V_73 & 3 ) {
V_37 -> V_108 . V_109 [ 0 ] . V_77 = V_1 ;
* V_1 = 0 ;
V_37 -> V_108 . V_109 [ 0 ] . V_78 = 4 - ( V_105 -> V_73 & 3 ) ;
}
return 1 ;
}
int
F_48 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_111 * V_105 )
{
F_43 ( V_37 , V_1 ) ;
V_1 = V_105 -> V_99 ;
* V_1 ++ = 0 ;
* V_1 ++ = F_15 ( ( V_105 -> V_112 . V_113 == V_114 ) ) ;
V_37 -> V_108 . V_87 = ( ( ( unsigned long ) V_1 - 1 ) & ~ V_115 ) + 1 ;
return 1 ;
}
int
F_49 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_116 * V_105 )
{
struct V_117 * V_39 = & V_105 -> V_118 ;
* V_1 ++ = F_15 ( V_86 ) ;
* V_1 ++ = F_15 ( V_39 -> V_119 ) ;
* V_1 ++ = F_15 ( V_39 -> V_120 ) ;
* V_1 ++ = F_15 ( V_39 -> V_121 ) ;
* V_1 ++ = F_15 ( V_39 -> V_122 ) ;
return F_43 ( V_37 , V_1 ) ;
}
int
F_50 ( void * V_123 , const char * V_10 ,
int V_124 , T_3 V_72 , T_4 V_61 , unsigned int V_125 )
{
struct V_126 * V_127 = V_123 ;
struct V_111 * V_128 = F_51 ( V_127 , struct V_111 , V_112 ) ;
T_1 * V_1 = V_128 -> V_99 ;
int V_129 , V_130 ;
if ( V_72 > ~ ( ( T_2 ) 0 ) ) {
V_128 -> V_112 . V_113 = V_131 ;
return - V_132 ;
}
if ( V_128 -> V_72 )
* V_128 -> V_72 = F_15 ( V_72 ) ;
V_124 = F_52 ( V_124 , V_133 ) ;
V_130 = F_35 ( V_124 ) ;
if ( ( V_129 = V_128 -> V_129 - V_130 - 4 ) < 0 ) {
V_128 -> V_112 . V_113 = V_134 ;
return - V_132 ;
}
if ( V_61 > ~ ( ( T_2 ) 0 ) ) {
V_128 -> V_112 . V_113 = V_131 ;
return - V_132 ;
}
* V_1 ++ = V_135 ;
* V_1 ++ = F_15 ( ( T_2 ) V_61 ) ;
V_1 = F_53 ( V_1 , V_10 , V_124 ) ;
V_128 -> V_72 = V_1 ;
* V_1 ++ = F_15 ( ~ 0U ) ;
V_128 -> V_129 = V_129 ;
V_128 -> V_99 = V_1 ;
V_128 -> V_112 . V_113 = V_136 ;
return 0 ;
}
int
F_54 ( struct V_36 * V_37 , T_1 * V_1 ,
struct V_64 * V_105 )
{
F_55 ( & V_105 -> V_65 ) ;
return 1 ;
}
