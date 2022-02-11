static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_5 = F_2 ( V_2 ) ;
switch ( V_3 -> V_8 ) {
case V_9 :
V_6 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
break;
case V_13 :
V_6 = V_14 ;
break;
default:
return - V_15 ;
}
V_3 -> V_16 = 0xff ;
if ( V_5 -> V_17 & V_18 ) {
V_7 = F_3 ( V_2 , ( V_19 * ) V_3 , V_6 ) ;
} else {
V_7 = F_4 ( V_2 , V_3 -> V_8 ,
( V_19 * ) V_3 , V_6 , V_20 ,
V_21 ) ;
}
return V_7 == V_6 ? 0 : - 1 ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_3 * V_22 ,
struct V_3 * V_23 )
{
int V_7 ;
F_6 ( & V_5 -> V_24 ) ;
V_5 -> V_25 = V_23 ;
V_5 -> V_26 = false ;
* V_23 = * V_22 ;
V_7 = F_1 ( V_5 -> V_27 , V_22 ) ;
if ( V_7 ) {
F_7 ( L_1 , V_7 ) ;
memset ( V_23 , 0 , sizeof( struct V_3 ) ) ;
goto exit;
}
if ( ! F_8 ( V_5 -> V_28 , V_5 -> V_26 ,
5 * V_29 ) ) {
F_7 ( L_2 , V_30 ) ;
memset ( V_23 , 0 , sizeof( struct V_3 ) ) ;
V_7 = - V_31 ;
}
if ( V_23 -> V_8 == V_9 &&
V_23 -> V_32 . V_33 == V_34 ) {
V_7 = V_23 -> V_32 . V_35 [ 1 ] ;
F_7 ( L_3 , V_30 , V_7 ) ;
goto exit;
}
if ( ( V_23 -> V_8 == V_11 ||
V_23 -> V_8 == V_13 ) &&
V_23 -> V_36 . V_37 == V_38 ) {
V_7 = V_23 -> V_36 . V_35 [ 1 ] ;
F_7 ( L_4 , V_30 , V_7 ) ;
goto exit;
}
exit:
F_9 ( & V_5 -> V_24 ) ;
return V_7 ;
}
static int F_10 ( struct V_4 * V_5 ,
V_19 V_39 , V_19 V_40 , V_19 * V_35 , int V_41 ,
struct V_3 * V_23 )
{
struct V_3 * V_22 ;
int V_7 ;
if ( V_41 > sizeof( V_22 -> V_36 . V_35 ) )
return - V_42 ;
V_22 = F_11 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_22 )
return - V_44 ;
if ( V_41 > ( V_12 - 4 ) )
V_22 -> V_8 = V_13 ;
else
V_22 -> V_8 = V_11 ;
V_22 -> V_36 . V_37 = V_39 ;
V_22 -> V_36 . V_40 = V_40 ;
memcpy ( & V_22 -> V_36 . V_35 , V_35 , V_41 ) ;
V_7 = F_5 ( V_5 , V_22 , V_23 ) ;
F_12 ( V_22 ) ;
return V_7 ;
}
static int F_13 ( struct V_4 * V_45 ,
V_19 V_8 , V_19 V_33 , V_19 V_46 , V_19 * V_35 , int V_41 ,
struct V_3 * V_23 )
{
struct V_3 * V_22 ;
int V_7 , V_47 ;
switch ( V_8 ) {
case V_9 :
V_47 = V_10 - 4 ;
break;
case V_11 :
V_47 = V_12 - 4 ;
break;
case V_13 :
V_47 = V_14 - 4 ;
break;
default:
return - V_42 ;
}
if ( V_41 > V_47 )
return - V_42 ;
V_22 = F_11 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_22 )
return - V_44 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_32 . V_33 = V_33 ;
V_22 -> V_32 . V_46 = V_46 ;
memcpy ( & V_22 -> V_32 . V_35 , V_35 , V_41 ) ;
V_7 = F_5 ( V_45 , V_22 , V_23 ) ;
F_12 ( V_22 ) ;
return V_7 ;
}
static void F_14 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_15 ( V_49 , struct V_4 ,
V_49 ) ;
F_16 ( V_5 ) ;
}
static inline bool F_17 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
return ( V_51 -> V_36 . V_37 == V_50 -> V_36 . V_37 ) &&
( V_51 -> V_36 . V_40 == V_50 -> V_36 . V_40 ) ;
}
static inline bool F_18 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
return ( ( V_51 -> V_32 . V_33 == V_34 ) ||
( V_51 -> V_36 . V_37 == V_38 ) ) &&
( V_51 -> V_36 . V_40 == V_50 -> V_36 . V_37 ) &&
( V_51 -> V_36 . V_35 [ 0 ] == V_50 -> V_36 . V_40 ) ;
}
static inline bool F_19 ( struct V_3 * V_52 )
{
return ( V_52 -> V_8 == V_9 ) &&
( V_52 -> V_32 . V_33 == 0x41 ) ;
}
static void F_20 ( char * * V_53 , int V_54 )
{
#define F_21 9
int V_55 ;
char * V_56 ;
if ( V_54 > F_21 &&
strncmp ( * V_53 , L_5 , F_21 ) == 0 )
return;
V_55 = F_21 + V_54 ;
V_56 = F_11 ( V_55 , V_43 ) ;
if ( ! V_56 )
return;
snprintf ( V_56 , V_55 , L_6 , * V_53 ) ;
F_12 ( * V_53 ) ;
* V_53 = V_56 ;
}
static int F_22 ( struct V_4 * V_45 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 3 ] = { 0 } ;
V_7 = F_13 ( V_45 ,
V_9 ,
V_57 ,
V_58 ,
NULL , 0 , & V_23 ) ;
if ( V_7 )
return V_7 ;
memcpy ( V_35 , V_23 . V_32 . V_35 , 3 ) ;
V_35 [ 0 ] |= F_23 ( 4 ) ;
return F_13 ( V_45 ,
V_9 ,
V_59 ,
V_58 ,
V_35 , 3 , & V_23 ) ;
}
static int F_24 ( V_19 V_60 )
{
int V_61 ;
switch ( V_60 ) {
case 1 ... 2 :
V_61 = V_62 ;
break;
case 3 ... 4 :
V_61 = V_63 ;
break;
case 5 ... 6 :
V_61 = V_64 ;
break;
case 7 :
V_61 = V_65 ;
break;
default:
V_61 = V_66 ;
}
return V_61 ;
}
static int F_25 ( V_19 V_60 )
{
int V_67 ;
switch ( V_60 ) {
case 0x00 :
V_67 = V_68 ;
break;
case 0x21 :
case 0x24 :
case 0x25 :
V_67 = V_69 ;
break;
case 0x26 :
case 0x22 :
V_67 = V_70 ;
break;
case 0x20 :
V_67 = V_71 ;
break;
default:
V_67 = V_72 ;
break;
}
return V_67 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_3 V_23 ;
int V_7 , V_67 ;
V_7 = F_13 ( V_5 ,
V_9 ,
V_57 ,
V_73 ,
NULL , 0 , & V_23 ) ;
if ( V_7 )
return V_7 ;
V_5 -> V_74 . V_61 =
F_24 ( V_23 . V_32 . V_35 [ 0 ] ) ;
V_67 = F_25 ( V_23 . V_32 . V_35 [ 1 ] ) ;
V_5 -> V_74 . V_67 = V_67 ;
V_5 -> V_74 . V_75 = V_67 == V_68 ||
V_67 == V_70 ;
return 0 ;
}
static int F_27 ( V_19 V_60 )
{
int V_67 ;
switch ( V_60 >> 6 ) {
case 0x00 :
V_67 = V_68 ;
break;
case 0x01 :
V_67 = V_69 ;
break;
case 0x02 :
V_67 = V_70 ;
break;
default:
V_67 = V_72 ;
break;
}
return V_67 ;
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_3 V_23 ;
int V_7 , V_67 ;
V_7 = F_13 ( V_5 ,
V_9 ,
V_57 ,
V_76 ,
NULL , 0 , & V_23 ) ;
if ( V_7 )
return V_7 ;
V_5 -> V_74 . V_77 = V_23 . V_32 . V_35 [ 0 ] ;
V_67 = F_27 ( V_23 . V_32 . V_35 [ 2 ] ) ;
V_5 -> V_74 . V_67 = V_67 ;
V_5 -> V_74 . V_75 = V_67 == V_68 ||
V_67 == V_70 ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 , V_19 * V_78 , int V_79 )
{
struct V_3 * V_52 = (struct V_3 * ) V_78 ;
int V_67 , V_77 , V_61 ;
bool V_80 ;
if ( V_52 -> V_8 != V_9 )
return 0 ;
switch ( V_52 -> V_32 . V_33 ) {
case V_73 :
V_77 = V_5 -> V_74 . V_77 ;
V_61 = F_24 ( V_52 -> V_81 [ 1 ] ) ;
V_67 = F_25 ( V_52 -> V_81 [ 2 ] ) ;
break;
case V_76 :
V_77 = V_52 -> V_32 . V_35 [ 0 ] ;
V_61 = V_5 -> V_74 . V_61 ;
V_67 = F_27 ( V_52 -> V_81 [ 3 ] ) ;
break;
default:
return 0 ;
}
V_80 = V_77 != V_5 -> V_74 . V_77 ||
V_61 != V_5 -> V_74 . V_61 ||
V_67 != V_5 -> V_74 . V_67 ;
V_5 -> V_74 . V_75 = V_67 == V_68 ||
V_67 == V_70 ;
if ( V_80 ) {
V_5 -> V_74 . V_61 = V_61 ;
V_5 -> V_74 . V_67 = V_67 ;
if ( V_5 -> V_74 . V_82 )
F_30 ( V_5 -> V_74 . V_82 ) ;
}
return 0 ;
}
static char * F_31 ( struct V_4 * V_45 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 1 ] = { V_83 } ;
char * V_53 ;
int V_84 ;
V_7 = F_13 ( V_45 ,
V_9 ,
V_85 ,
V_86 ,
V_35 , 1 , & V_23 ) ;
if ( V_7 )
return NULL ;
V_84 = V_23 . V_32 . V_35 [ 1 ] ;
if ( 2 + V_84 > sizeof( V_23 . V_32 . V_35 ) )
return NULL ;
V_53 = F_11 ( V_84 + 1 , V_43 ) ;
if ( ! V_53 )
return NULL ;
memcpy ( V_53 , & V_23 . V_32 . V_35 [ 2 ] , V_84 ) ;
F_20 ( & V_53 , V_84 + 1 ) ;
return V_53 ;
}
static int F_32 ( struct V_4 * V_5 , T_1 * V_87 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 1 ] = { V_88 } ;
V_7 = F_13 ( V_5 ,
V_9 ,
V_85 ,
V_86 ,
V_35 , 1 , & V_23 ) ;
if ( V_7 )
return V_7 ;
* V_87 = * ( ( T_1 * ) & V_23 . V_32 . V_35 [ 1 ] ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_27 ;
const char * V_53 ;
T_1 V_87 ;
int V_7 ;
V_7 = F_32 ( V_5 , & V_87 ) ;
if ( V_7 )
return V_7 ;
snprintf ( V_2 -> V_89 , sizeof( V_2 -> V_89 ) , L_7 ,
V_2 -> V_90 , & V_87 ) ;
F_7 ( L_8 , V_2 -> V_89 ) ;
V_53 = F_31 ( V_5 ) ;
if ( ! V_53 )
return - V_91 ;
snprintf ( V_2 -> V_53 , sizeof( V_2 -> V_53 ) , L_9 , V_53 ) ;
F_7 ( L_10 , V_53 ) ;
F_12 ( V_53 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , T_2 V_92 ,
V_19 * V_37 , V_19 * V_93 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 2 ] = { V_92 >> 8 , V_92 & 0x00FF } ;
V_7 = F_10 ( V_5 ,
V_94 ,
V_95 ,
V_35 , 2 , & V_23 ) ;
if ( V_7 )
return V_7 ;
if ( V_23 . V_36 . V_35 [ 0 ] == 0 )
return - V_96 ;
* V_37 = V_23 . V_36 . V_35 [ 0 ] ;
* V_93 = V_23 . V_36 . V_35 [ 1 ] ;
return V_7 ;
}
static int F_35 ( struct V_4 * V_5 )
{
struct V_3 V_23 ;
int V_7 ;
V_7 = F_10 ( V_5 ,
V_94 ,
V_97 ,
NULL , 0 , & V_23 ) ;
if ( V_7 == V_98 ) {
V_5 -> V_99 = 1 ;
V_5 -> V_100 = 0 ;
return 0 ;
}
if ( V_7 == V_101 )
return - V_91 ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
V_5 -> V_99 = V_23 . V_36 . V_35 [ 0 ] ;
V_5 -> V_100 = V_23 . V_36 . V_35 [ 1 ] ;
return V_7 ;
}
static bool F_37 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_35 ( V_5 ) ;
if ( ! V_7 )
F_38 ( V_5 -> V_27 , L_12 ,
V_5 -> V_99 , V_5 -> V_100 ) ;
return V_7 == 0 ;
}
static int F_39 ( struct V_4 * V_5 ,
V_19 V_37 , V_19 * V_103 )
{
struct V_3 V_23 ;
int V_7 ;
V_7 = F_10 ( V_5 , V_37 ,
V_104 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
* V_103 = V_23 . V_36 . V_35 [ 0 ] ;
return V_7 ;
}
static int F_40 ( struct V_4 * V_5 ,
V_19 V_37 , V_19 V_105 , char * V_106 , int V_107 )
{
struct V_3 V_23 ;
int V_7 , V_108 ;
int V_109 ;
V_7 = F_10 ( V_5 , V_37 ,
V_110 , & V_105 , 1 ,
& V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
switch ( V_23 . V_8 ) {
case V_13 :
V_109 = V_14 - 4 ;
break;
case V_11 :
V_109 = V_12 - 4 ;
break;
case V_9 :
V_109 = V_10 - 4 ;
break;
default:
return - V_102 ;
}
if ( V_107 < V_109 )
V_109 = V_107 ;
for ( V_108 = 0 ; V_108 < V_109 ; V_108 ++ )
V_106 [ V_108 ] = V_23 . V_36 . V_35 [ V_108 ] ;
return V_109 ;
}
static char * F_41 ( struct V_4 * V_5 )
{
V_19 V_93 ;
V_19 V_37 ;
V_19 V_111 ;
char * V_53 ;
unsigned V_112 = 0 ;
int V_7 ;
V_7 = F_34 ( V_5 , V_113 ,
& V_37 , & V_93 ) ;
if ( V_7 )
return NULL ;
V_7 = F_39 ( V_5 , V_37 ,
& V_111 ) ;
if ( V_7 )
return NULL ;
V_53 = F_11 ( V_111 + 1 , V_43 ) ;
if ( ! V_53 )
return NULL ;
while ( V_112 < V_111 ) {
V_7 = F_40 ( V_5 ,
V_37 , V_112 , V_53 + V_112 ,
V_111 - V_112 ) ;
if ( V_7 <= 0 ) {
F_12 ( V_53 ) ;
return NULL ;
}
V_112 += V_7 ;
}
F_20 ( & V_53 , V_111 + 1 ) ;
return V_53 ;
}
static int F_42 ( int V_77 )
{
if ( V_77 < 11 )
return V_62 ;
else if ( V_77 < 31 )
return V_63 ;
else if ( V_77 < 81 )
return V_64 ;
return V_114 ;
}
static int F_43 ( V_19 V_78 [ 3 ] , int * V_77 ,
int * V_115 ,
int * V_61 )
{
int V_67 ;
* V_77 = V_78 [ 0 ] ;
* V_115 = V_78 [ 1 ] ;
* V_61 = V_66 ;
switch ( V_78 [ 2 ] ) {
case 0 :
V_67 = V_68 ;
* V_61 = F_42 ( * V_77 ) ;
break;
case 1 :
V_67 = V_69 ;
break;
case 2 :
V_67 = V_69 ;
break;
case 3 :
V_67 = V_70 ;
* V_61 = V_114 ;
* V_77 = 100 ;
break;
case 4 :
V_67 = V_69 ;
break;
default:
V_67 = V_72 ;
break;
}
return V_67 ;
}
static int F_44 ( struct V_4 * V_5 ,
V_19 V_37 ,
int * V_67 ,
int * V_77 ,
int * V_115 ,
int * V_61 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_116 ,
NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
* V_67 = F_43 ( V_35 , V_77 ,
V_115 ,
V_61 ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 ,
V_19 V_37 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
unsigned int V_117 , V_118 ;
V_7 = F_10 ( V_5 , V_37 ,
V_119 ,
NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
V_117 = V_35 [ 0 ] ;
V_118 = V_35 [ 1 ] ;
if ( V_117 < 10 || ! ( V_118 & V_120 ) )
V_5 -> V_121 |= V_122 ;
else
V_5 -> V_121 |= V_123 ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 )
{
V_19 V_93 ;
int V_7 ;
int V_67 , V_77 , V_115 , V_61 ;
if ( V_5 -> V_74 . V_37 == 0xff ) {
V_7 = F_34 ( V_5 ,
V_124 ,
& V_5 -> V_74 . V_37 ,
& V_93 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_44 ( V_5 ,
V_5 -> V_74 . V_37 ,
& V_67 , & V_77 ,
& V_115 , & V_61 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_45 ( V_5 ,
V_5 -> V_74 . V_37 ) ;
if ( V_7 )
return V_7 ;
V_5 -> V_74 . V_67 = V_67 ;
V_5 -> V_74 . V_77 = V_77 ;
V_5 -> V_74 . V_61 = V_61 ;
V_5 -> V_74 . V_75 = V_67 == V_68 ||
V_67 == V_70 ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 ,
V_19 * V_78 , int V_79 )
{
struct V_3 * V_52 = (struct V_3 * ) V_78 ;
int V_67 , V_77 , V_115 , V_61 ;
bool V_80 ;
if ( V_52 -> V_36 . V_37 != V_5 -> V_74 . V_37 ||
V_52 -> V_36 . V_40 != V_125 )
return 0 ;
V_67 = F_43 ( V_52 -> V_36 . V_35 ,
& V_77 ,
& V_115 ,
& V_61 ) ;
V_5 -> V_74 . V_75 = V_67 == V_68 ||
V_67 == V_70 ;
V_80 = V_77 != V_5 -> V_74 . V_77 ||
V_61 != V_5 -> V_74 . V_61 ||
V_67 != V_5 -> V_74 . V_67 ;
if ( V_80 ) {
V_5 -> V_74 . V_61 = V_61 ;
V_5 -> V_74 . V_77 = V_77 ;
V_5 -> V_74 . V_67 = V_67 ;
if ( V_5 -> V_74 . V_82 )
F_30 ( V_5 -> V_74 . V_82 ) ;
}
return 0 ;
}
static int F_48 ( struct V_126 * V_127 ,
enum V_128 V_129 ,
union V_130 * V_131 )
{
struct V_4 * V_5 = F_49 ( V_127 ) ;
int V_7 = 0 ;
switch( V_129 ) {
case V_132 :
V_131 -> V_133 = V_5 -> V_74 . V_67 ;
break;
case V_134 :
V_131 -> V_133 = V_5 -> V_74 . V_77 ;
break;
case V_135 :
V_131 -> V_133 = V_5 -> V_74 . V_61 ;
break;
case V_136 :
V_131 -> V_133 = V_137 ;
break;
case V_138 :
V_131 -> V_133 = V_5 -> V_74 . V_75 ;
break;
case V_139 :
if ( ! strncmp ( V_5 -> V_53 , L_5 , 9 ) )
V_131 -> V_140 = V_5 -> V_53 + 9 ;
else
V_131 -> V_140 = V_5 -> V_53 ;
break;
case V_141 :
V_131 -> V_140 = L_13 ;
break;
case V_142 :
V_131 -> V_140 = V_5 -> V_27 -> V_89 ;
break;
default:
V_7 = - V_42 ;
break;
}
return V_7 ;
}
static int F_50 ( struct V_4 * V_5 )
{
struct V_3 V_23 ;
V_19 V_35 [ 2 ] = { 1 , 1 } ;
V_19 V_93 ;
int V_7 ;
if ( V_5 -> V_74 . V_37 == 0xff ) {
V_7 = F_34 ( V_5 ,
V_143 ,
& V_5 -> V_74 . V_144 ,
& V_93 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_10 ( V_5 ,
V_5 -> V_74 . V_144 ,
V_145 ,
V_35 , 2 , & V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
V_5 -> V_121 |= V_123 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_5 ,
V_19 * V_78 , int V_79 )
{
struct V_3 * V_52 = (struct V_3 * ) V_78 ;
int V_77 , V_146 , V_67 ;
V_19 V_147 ;
V_147 = V_52 -> V_36 . V_40 ;
if ( V_52 -> V_36 . V_37 != V_5 -> V_74 . V_144 ||
! ( V_147 == V_148 ||
V_147 == V_149 ||
V_147 == V_150 ) )
return 0 ;
V_77 = V_52 -> V_36 . V_35 [ 0 ] ;
switch ( V_147 ) {
case V_149 :
V_146 = ( V_52 -> V_36 . V_35 [ 1 ] << 8 ) | V_52 -> V_36 . V_35 [ 2 ] ;
if ( V_146 > 200 )
V_67 = V_69 ;
else
V_67 = V_68 ;
break;
case V_150 :
default:
if ( V_77 < V_5 -> V_74 . V_77 )
V_67 = V_68 ;
else
V_67 = V_69 ;
}
if ( V_77 == 100 )
V_67 = V_70 ;
V_5 -> V_74 . V_75 = true ;
if ( V_77 != V_5 -> V_74 . V_77 ||
V_67 != V_5 -> V_74 . V_67 ) {
V_5 -> V_74 . V_77 = V_77 ;
V_5 -> V_74 . V_67 = V_67 ;
if ( V_5 -> V_74 . V_82 )
F_30 ( V_5 -> V_74 . V_82 ) ;
}
return 0 ;
}
static int F_52 ( struct V_4 * V_5 ,
V_19 V_37 ,
struct V_151 * V_152 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_153 , & V_152 -> V_154 , 1 , & V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
V_152 -> V_155 = V_35 [ 0 ] ;
V_152 -> V_156 = V_35 [ 1 ] ;
V_152 -> V_154 = V_35 [ 2 ] ;
V_152 -> V_157 = V_35 [ 3 ] ;
return 0 ;
}
static int F_53 ( struct V_4 * V_5 ,
V_19 V_37 , struct V_158 * V_159 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_160 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , V_7 ) ;
return - V_102 ;
}
if ( V_7 )
return V_7 ;
V_159 -> V_161 = F_54 ( & V_35 [ 0 ] ) ;
V_159 -> V_162 = F_54 ( & V_35 [ 2 ] ) ;
V_159 -> V_163 = V_35 [ 4 ] ;
V_159 -> V_164 = V_35 [ 5 ] ;
V_159 -> V_165 = V_35 [ 7 ] ;
V_159 -> V_166 = V_35 [ 8 ] ;
V_159 -> V_167 = F_54 ( & V_35 [ 13 ] ) * 2 / 51 ;
return V_7 ;
}
static int F_55 ( struct V_4 * V_45 ,
V_19 V_37 , bool V_168 ,
bool V_169 )
{
struct V_3 V_23 ;
V_19 V_35 = V_168 | ( V_169 << 2 ) ;
return F_10 ( V_45 , V_37 ,
V_170 , & V_35 , 1 , & V_23 ) ;
}
static void F_56 ( V_19 * V_78 ,
struct V_171 * V_172 )
{
V_19 V_173 = V_78 [ 0 ] << 2 ;
V_19 V_174 = V_78 [ 2 ] << 2 ;
V_172 -> V_175 = V_173 << 6 | V_78 [ 1 ] ;
V_172 -> V_176 = V_174 << 6 | V_78 [ 3 ] ;
V_172 -> V_177 = V_78 [ 0 ] >> 6 ;
V_172 -> V_178 = V_78 [ 2 ] >> 6 ;
V_172 -> V_179 = V_78 [ 4 ] ;
V_172 -> V_180 = V_78 [ 5 ] ;
V_172 -> V_181 = V_78 [ 6 ] >> 4 ;
}
static void F_57 ( struct V_4 * V_45 ,
V_19 * V_78 , struct V_182 * V_183 )
{
memset ( V_183 , 0 , sizeof( struct V_182 ) ) ;
V_183 -> V_184 = V_78 [ 8 ] & 0x01 ;
V_183 -> V_185 = ( V_78 [ 8 ] >> 1 ) & 0x01 ;
V_183 -> V_186 = V_78 [ 15 ] & 0x0f ;
V_183 -> V_187 = ( V_78 [ 8 ] >> 2 ) & 0x01 ;
if ( V_183 -> V_186 ) {
F_56 ( & V_78 [ 2 ] , & V_183 -> V_188 [ 0 ] ) ;
F_56 ( & V_78 [ 9 ] , & V_183 -> V_188 [ 1 ] ) ;
}
}
static V_19 F_58 ( struct V_189 * V_78 , int V_190 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_78 -> V_191 ; V_108 ++ )
if ( V_78 -> V_192 [ V_108 ] == V_190 )
return V_108 + 1 ;
return 0 ;
}
static void F_59 ( struct V_48 * V_193 )
{
struct V_194 * V_195 = F_15 ( V_193 , struct V_194 , V_49 ) ;
struct V_189 * V_78 = V_195 -> V_78 ;
struct V_3 V_23 ;
V_19 V_196 ;
int V_7 ;
switch ( V_195 -> V_190 ) {
case V_197 :
V_195 -> V_35 [ 0 ] = V_78 -> V_198 ;
break;
case V_199 :
break;
default:
V_195 -> V_35 [ 0 ] = F_58 ( V_78 , V_195 -> V_190 ) ;
break;
}
V_7 = F_10 ( V_78 -> V_5 , V_78 -> V_37 ,
V_195 -> V_200 , V_195 -> V_35 , V_195 -> V_79 , & V_23 ) ;
if ( V_7 ) {
F_36 ( V_78 -> V_5 -> V_27 , L_14 ) ;
goto V_201;
}
switch ( V_195 -> V_200 ) {
case V_202 :
V_196 = V_23 . V_36 . V_35 [ 0 ] ;
if ( V_196 > 0 && V_196 <= V_78 -> V_191 ) {
if ( V_195 -> V_190 >= 0 )
V_78 -> V_192 [ V_196 - 1 ] = V_195 -> V_190 ;
else if ( V_195 -> V_190 >= V_197 )
V_78 -> V_198 = V_196 ;
}
break;
case V_203 :
if ( V_195 -> V_190 >= 0 )
V_78 -> V_192 [ V_195 -> V_35 [ 0 ] - 1 ] = - 1 ;
else if ( V_195 -> V_190 >= V_197 )
V_78 -> V_198 = 0 ;
break;
case V_204 :
V_78 -> V_205 = ( V_195 -> V_35 [ 0 ] << 8 ) + V_195 -> V_35 [ 1 ] ;
break;
case V_206 :
V_78 -> V_207 = ( V_195 -> V_35 [ 0 ] << 8 ) + V_195 -> V_35 [ 1 ] ;
break;
default:
break;
}
V_201:
F_60 ( & V_78 -> V_208 ) ;
F_12 ( V_195 ) ;
}
static int F_61 ( struct V_189 * V_78 , int V_190 , V_19 V_200 , V_19 * V_35 , V_19 V_79 )
{
struct V_194 * V_195 = F_11 ( sizeof( * V_195 ) , V_43 ) ;
int V_209 ;
if ( ! V_195 )
return - V_44 ;
F_62 ( & V_195 -> V_49 , F_59 ) ;
V_195 -> V_78 = V_78 ;
V_195 -> V_190 = V_190 ;
V_195 -> V_200 = V_200 ;
V_195 -> V_79 = V_79 ;
memcpy ( V_195 -> V_35 , V_35 , V_79 ) ;
F_63 ( & V_78 -> V_208 ) ;
F_64 ( V_78 -> V_210 , & V_195 -> V_49 ) ;
V_209 = F_65 ( & V_78 -> V_208 ) ;
if ( V_209 >= 20 && V_209 % 20 == 0 )
F_66 ( V_78 -> V_5 -> V_27 , L_15 , V_209 ) ;
return 0 ;
}
static int F_67 ( struct V_211 * V_212 , struct V_213 * V_214 , struct V_213 * V_215 )
{
struct V_189 * V_78 = V_212 -> V_216 -> V_217 ;
V_19 V_35 [ 20 ] ;
V_19 V_79 ;
int V_218 ;
V_35 [ 2 ] = V_214 -> V_219 . V_220 >> 8 ;
V_35 [ 3 ] = V_214 -> V_219 . V_220 & 255 ;
V_35 [ 4 ] = V_214 -> V_219 . V_221 >> 8 ;
V_35 [ 5 ] = V_214 -> V_219 . V_221 & 255 ;
switch ( V_214 -> type ) {
case V_222 :
V_218 = ( V_214 -> V_223 . V_224 . V_61 * F_68 ( ( V_214 -> V_225 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 1 ] = V_226 ;
V_35 [ 6 ] = V_218 >> 8 ;
V_35 [ 7 ] = V_218 & 255 ;
V_35 [ 8 ] = V_214 -> V_223 . V_224 . V_227 . V_228 >> 7 ;
V_35 [ 9 ] = V_214 -> V_223 . V_224 . V_227 . V_229 >> 8 ;
V_35 [ 10 ] = V_214 -> V_223 . V_224 . V_227 . V_229 & 255 ;
V_35 [ 11 ] = V_214 -> V_223 . V_224 . V_227 . V_230 >> 7 ;
V_35 [ 12 ] = V_214 -> V_223 . V_224 . V_227 . V_231 >> 8 ;
V_35 [ 13 ] = V_214 -> V_223 . V_224 . V_227 . V_231 & 255 ;
V_79 = 14 ;
F_7 ( L_16 ,
V_214 -> V_223 . V_224 . V_61 ,
V_214 -> V_225 , V_218 ) ;
F_7 ( L_17 ,
V_214 -> V_223 . V_224 . V_227 . V_228 ,
V_214 -> V_223 . V_224 . V_227 . V_229 ,
V_214 -> V_223 . V_224 . V_227 . V_230 ,
V_214 -> V_223 . V_224 . V_227 . V_231 ) ;
break;
case V_232 :
{
switch ( V_214 -> V_223 . V_233 . V_234 ) {
case V_235 :
V_35 [ 1 ] = V_236 ;
break;
case V_237 :
V_35 [ 1 ] = V_238 ;
break;
case V_239 :
V_35 [ 1 ] = V_240 ;
break;
case V_241 :
V_35 [ 1 ] = V_242 ;
break;
case V_243 :
V_35 [ 1 ] = V_244 ;
break;
default:
F_36 ( V_78 -> V_5 -> V_27 , L_18 , V_214 -> V_223 . V_233 . V_234 ) ;
return - V_42 ;
}
V_218 = ( V_214 -> V_223 . V_233 . V_245 * F_68 ( ( V_214 -> V_225 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 6 ] = V_214 -> V_223 . V_233 . V_245 >> 8 ;
V_35 [ 7 ] = V_214 -> V_223 . V_233 . V_245 & 255 ;
V_35 [ 8 ] = V_214 -> V_223 . V_233 . V_246 >> 8 ;
V_35 [ 9 ] = V_214 -> V_223 . V_233 . V_246 & 255 ;
V_35 [ 10 ] = V_214 -> V_223 . V_233 . V_247 >> 8 ;
V_35 [ 11 ] = V_214 -> V_223 . V_233 . V_247 & 255 ;
V_35 [ 12 ] = V_214 -> V_223 . V_233 . V_248 >> 8 ;
V_35 [ 13 ] = V_214 -> V_223 . V_233 . V_248 & 255 ;
V_35 [ 14 ] = V_214 -> V_223 . V_233 . V_227 . V_228 >> 7 ;
V_35 [ 15 ] = V_214 -> V_223 . V_233 . V_227 . V_229 >> 8 ;
V_35 [ 16 ] = V_214 -> V_223 . V_233 . V_227 . V_229 & 255 ;
V_35 [ 17 ] = V_214 -> V_223 . V_233 . V_227 . V_230 >> 7 ;
V_35 [ 18 ] = V_214 -> V_223 . V_233 . V_227 . V_231 >> 8 ;
V_35 [ 19 ] = V_214 -> V_223 . V_233 . V_227 . V_231 & 255 ;
V_79 = 20 ;
F_7 ( L_19 ,
V_214 -> V_223 . V_233 . V_245 , V_214 -> V_225 ,
V_214 -> V_223 . V_233 . V_246 ,
V_214 -> V_223 . V_233 . V_247 ,
V_214 -> V_223 . V_233 . V_248 ) ;
F_7 ( L_17 ,
V_214 -> V_223 . V_233 . V_227 . V_228 ,
V_214 -> V_223 . V_233 . V_227 . V_229 ,
V_214 -> V_223 . V_233 . V_227 . V_230 ,
V_214 -> V_223 . V_233 . V_227 . V_231 ) ;
break;
}
case V_249 :
V_35 [ 1 ] = V_250 ;
V_218 = ( V_214 -> V_223 . V_251 . V_252 * F_68 ( ( V_214 -> V_225 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 6 ] = V_218 >> 8 ;
V_35 [ 7 ] = V_218 & 255 ;
V_218 = ( V_214 -> V_223 . V_251 . V_253 * F_68 ( ( V_214 -> V_225 * 360 ) >> 16 ) ) >> 15 ;
V_35 [ 8 ] = V_218 >> 8 ;
V_35 [ 9 ] = V_218 & 255 ;
V_35 [ 10 ] = V_214 -> V_223 . V_251 . V_227 . V_228 >> 7 ;
V_35 [ 11 ] = V_214 -> V_223 . V_251 . V_227 . V_229 >> 8 ;
V_35 [ 12 ] = V_214 -> V_223 . V_251 . V_227 . V_229 & 255 ;
V_35 [ 13 ] = V_214 -> V_223 . V_251 . V_227 . V_230 >> 7 ;
V_35 [ 14 ] = V_214 -> V_223 . V_251 . V_227 . V_231 >> 8 ;
V_35 [ 15 ] = V_214 -> V_223 . V_251 . V_227 . V_231 & 255 ;
V_79 = 16 ;
F_7 ( L_20 ,
V_214 -> V_223 . V_251 . V_252 ,
V_214 -> V_223 . V_251 . V_253 ,
V_214 -> V_225 , V_218 ) ;
F_7 ( L_17 ,
V_214 -> V_223 . V_251 . V_227 . V_228 ,
V_214 -> V_223 . V_251 . V_227 . V_229 ,
V_214 -> V_223 . V_251 . V_227 . V_230 ,
V_214 -> V_223 . V_251 . V_227 . V_231 ) ;
break;
case V_254 :
case V_255 :
case V_256 :
case V_257 :
V_35 [ 1 ] = V_258 [ V_214 -> type - V_256 ] ;
V_35 [ 6 ] = V_214 -> V_223 . V_259 [ 0 ] . V_260 >> 9 ;
V_35 [ 7 ] = ( V_214 -> V_223 . V_259 [ 0 ] . V_260 >> 1 ) & 255 ;
V_35 [ 8 ] = V_214 -> V_223 . V_259 [ 0 ] . V_261 >> 8 ;
V_35 [ 9 ] = V_214 -> V_223 . V_259 [ 0 ] . V_261 & 255 ;
V_35 [ 10 ] = V_214 -> V_223 . V_259 [ 0 ] . V_262 >> 9 ;
V_35 [ 11 ] = ( V_214 -> V_223 . V_259 [ 0 ] . V_262 >> 1 ) & 255 ;
V_35 [ 12 ] = V_214 -> V_223 . V_259 [ 0 ] . V_263 >> 8 ;
V_35 [ 13 ] = V_214 -> V_223 . V_259 [ 0 ] . V_263 & 255 ;
V_35 [ 14 ] = V_214 -> V_223 . V_259 [ 0 ] . V_264 >> 8 ;
V_35 [ 15 ] = V_214 -> V_223 . V_259 [ 0 ] . V_264 & 255 ;
V_35 [ 16 ] = V_214 -> V_223 . V_259 [ 0 ] . V_265 >> 9 ;
V_35 [ 17 ] = ( V_214 -> V_223 . V_259 [ 0 ] . V_265 >> 1 ) & 255 ;
V_79 = 18 ;
F_7 ( L_21 ,
V_266 [ V_214 -> type - V_256 ] ,
V_214 -> V_223 . V_259 [ 0 ] . V_261 ,
V_214 -> V_223 . V_259 [ 0 ] . V_260 ,
V_214 -> V_223 . V_259 [ 0 ] . V_264 ,
V_214 -> V_223 . V_259 [ 0 ] . V_265 ) ;
F_7 ( L_22 ,
V_214 -> V_223 . V_259 [ 0 ] . V_262 ,
V_214 -> V_223 . V_259 [ 0 ] . V_263 ) ;
break;
default:
F_36 ( V_78 -> V_5 -> V_27 , L_23 , V_214 -> type ) ;
return - V_42 ;
}
return F_61 ( V_78 , V_214 -> V_267 , V_202 , V_35 , V_79 ) ;
}
static int F_69 ( struct V_211 * V_212 , int V_190 , int V_268 )
{
struct V_189 * V_78 = V_212 -> V_216 -> V_217 ;
V_19 V_35 [ 2 ] ;
V_35 [ 1 ] = V_268 ? V_269 : V_270 ;
F_7 ( L_24 , V_268 ? L_25 : L_26 , V_190 ) ;
return F_61 ( V_78 , V_190 , V_271 , V_35 , F_70 ( V_35 ) ) ;
}
static int F_71 ( struct V_211 * V_212 , int V_190 )
{
struct V_189 * V_78 = V_212 -> V_216 -> V_217 ;
V_19 V_196 = 0 ;
F_7 ( L_27 , V_190 ) ;
return F_61 ( V_78 , V_190 , V_203 , & V_196 , 1 ) ;
}
static void F_72 ( struct V_211 * V_212 , T_2 V_245 )
{
struct V_189 * V_78 = V_212 -> V_216 -> V_217 ;
V_19 V_35 [ 18 ] ;
F_7 ( L_28 , V_245 ) ;
V_35 [ 1 ] = V_272 | V_273 ;
V_35 [ 2 ] = V_35 [ 3 ] = V_35 [ 4 ] = V_35 [ 5 ] = 0 ;
V_35 [ 8 ] = V_35 [ 14 ] = V_245 >> 11 ;
V_35 [ 9 ] = V_35 [ 15 ] = ( V_245 >> 3 ) & 255 ;
V_35 [ 6 ] = V_35 [ 16 ] = V_245 >> 9 ;
V_35 [ 7 ] = V_35 [ 17 ] = ( V_245 >> 1 ) & 255 ;
V_35 [ 10 ] = V_35 [ 11 ] = V_35 [ 12 ] = V_35 [ 13 ] = 0 ;
F_61 ( V_78 , V_197 , V_202 , V_35 , F_70 ( V_35 ) ) ;
}
static void F_73 ( struct V_211 * V_212 , T_2 V_205 )
{
struct V_189 * V_78 = V_212 -> V_216 -> V_217 ;
V_19 V_35 [ 4 ] ;
F_7 ( L_29 , V_205 ) ;
V_35 [ 0 ] = V_205 >> 8 ;
V_35 [ 1 ] = V_205 & 255 ;
V_35 [ 2 ] = 0 ;
V_35 [ 3 ] = 0 ;
F_61 ( V_78 , V_199 , V_204 , V_35 , F_70 ( V_35 ) ) ;
}
static T_3 F_74 ( struct V_274 * V_212 , struct V_275 * V_276 , char * V_277 )
{
struct V_1 * V_278 = F_75 ( V_212 ) ;
struct V_279 * V_280 = F_76 ( V_278 -> V_281 . V_282 , struct V_279 , V_283 ) ;
struct V_211 * V_284 = V_280 -> V_285 ;
struct V_189 * V_78 = V_284 -> V_216 -> V_217 ;
return F_77 ( V_277 , V_286 , L_30 , V_78 -> V_207 ) ;
}
static T_3 F_78 ( struct V_274 * V_212 , struct V_275 * V_276 , const char * V_277 , T_4 V_109 )
{
struct V_1 * V_278 = F_75 ( V_212 ) ;
struct V_279 * V_280 = F_76 ( V_278 -> V_281 . V_282 , struct V_279 , V_283 ) ;
struct V_211 * V_284 = V_280 -> V_285 ;
struct V_189 * V_78 = V_284 -> V_216 -> V_217 ;
V_19 V_35 [ 2 ] ;
int V_207 = F_79 ( V_277 , NULL , 10 ) ;
V_207 = F_80 ( V_207 , 180 , 900 ) ;
V_35 [ 0 ] = V_207 >> 8 ;
V_35 [ 1 ] = V_207 & 0x00FF ;
F_61 ( V_78 , - 1 , V_206 , V_35 , F_70 ( V_35 ) ) ;
return V_109 ;
}
static void F_81 ( struct V_287 * V_216 )
{
struct V_189 * V_78 = V_216 -> V_217 ;
F_12 ( V_78 -> V_192 ) ;
}
static int F_82 ( struct V_4 * V_5 , V_19 V_37 )
{
struct V_1 * V_278 = V_5 -> V_27 ;
struct V_279 * V_280 = F_76 ( V_278 -> V_281 . V_282 , struct V_279 , V_283 ) ;
struct V_211 * V_212 = V_280 -> V_285 ;
const struct V_288 * V_289 = & ( F_83 ( V_278 ) -> V_290 ) ;
const T_2 V_291 = F_84 ( V_289 -> V_291 ) ;
struct V_287 * V_216 ;
struct V_3 V_23 ;
struct V_189 * V_78 ;
int error , V_292 , V_293 ;
V_19 V_294 ;
if ( ! V_212 ) {
F_36 ( V_278 , L_31 ) ;
return - V_42 ;
}
V_294 = V_291 & 255 ;
for ( V_292 = 0 ; V_295 [ V_292 ] >= 0 ; V_292 ++ )
F_85 ( V_295 [ V_292 ] , V_212 -> V_296 ) ;
if ( V_294 > 1 )
for ( V_292 = 0 ; V_297 [ V_292 ] >= 0 ; V_292 ++ )
F_85 ( V_297 [ V_292 ] , V_212 -> V_296 ) ;
error = F_10 ( V_5 , V_37 ,
V_298 , NULL , 0 , & V_23 ) ;
if ( error ) {
if ( error < 0 )
return error ;
F_36 ( V_5 -> V_27 , L_11 ,
V_30 , error ) ;
return - V_102 ;
}
V_293 = V_23 . V_36 . V_35 [ 0 ] - V_299 ;
error = F_86 ( V_212 , V_293 ) ;
if ( error ) {
F_36 ( V_212 , L_32 ) ;
return error ;
}
V_78 = F_11 ( sizeof( * V_78 ) , V_43 ) ;
if ( ! V_78 )
return - V_44 ;
V_78 -> V_192 = F_87 ( V_293 , sizeof( int ) , V_43 ) ;
if ( ! V_78 -> V_192 ) {
F_12 ( V_78 ) ;
return - V_44 ;
}
V_78 -> V_5 = V_5 ;
V_78 -> V_37 = V_37 ;
V_78 -> V_294 = V_294 ;
V_78 -> V_198 = 0 ;
V_78 -> V_191 = V_293 ;
for ( V_292 = 0 ; V_292 < V_293 ; V_292 ++ )
V_78 -> V_192 [ V_292 ] = - 1 ;
V_216 = V_212 -> V_216 ;
V_216 -> V_217 = V_78 ;
V_216 -> V_300 = F_67 ;
V_216 -> V_301 = F_71 ;
V_216 -> V_302 = F_69 ;
V_216 -> V_303 = F_73 ;
V_216 -> V_304 = F_72 ;
V_216 -> V_305 = F_81 ;
error = F_10 ( V_5 , V_37 ,
V_306 , NULL , 0 , & V_23 ) ;
error = F_10 ( V_5 , V_37 ,
V_307 , NULL , 0 , & V_23 ) ;
if ( error )
F_66 ( V_5 -> V_27 , L_33 ) ;
V_78 -> V_207 = error ? 900 : F_54 ( & V_23 . V_36 . V_35 [ 0 ] ) ;
error = F_88 ( & ( V_5 -> V_27 -> V_212 ) , & V_308 ) ;
if ( error )
F_66 ( V_5 -> V_27 , L_34 , error ) ;
error = F_10 ( V_5 , V_37 ,
V_309 , NULL , 0 , & V_23 ) ;
if ( error )
F_66 ( V_5 -> V_27 , L_35 ) ;
V_78 -> V_205 = error ? 0xffff : F_54 ( & V_23 . V_36 . V_35 [ 0 ] ) ;
V_78 -> V_210 = F_89 ( L_36 ) ;
F_90 ( & V_78 -> V_208 , 0 ) ;
F_72 ( V_212 , 0 ) ;
F_91 ( V_278 , L_37 , V_294 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_278 )
{
struct V_279 * V_280 = F_76 ( V_278 -> V_281 . V_282 , struct V_279 , V_283 ) ;
struct V_211 * V_212 = V_280 -> V_285 ;
struct V_189 * V_78 ;
if ( ! V_212 ) {
F_36 ( V_278 , L_38 ) ;
return - V_42 ;
}
F_91 ( V_278 , L_39 ) ;
V_78 = V_212 -> V_216 -> V_217 ;
if ( ! V_78 ) {
F_36 ( V_278 , L_40 ) ;
return - V_42 ;
}
F_93 ( V_78 -> V_210 ) ;
F_94 ( & V_278 -> V_212 , & V_308 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_279 * V_310 ,
struct V_311 * V_312 , struct V_313 * V_314 ,
unsigned long * * V_315 , int * V_316 )
{
return - 1 ;
}
static void F_96 ( struct V_4 * V_5 ,
struct V_211 * V_211 , bool V_317 )
{
struct V_318 * V_195 = V_5 -> V_319 ;
F_97 ( V_320 , V_211 -> V_321 ) ;
F_97 ( V_322 , V_211 -> V_321 ) ;
F_98 ( V_323 , V_211 -> V_321 ) ;
F_98 ( V_324 , V_211 -> V_321 ) ;
F_99 ( V_211 , V_325 , 0 , V_195 -> V_161 , 0 , 0 ) ;
F_100 ( V_211 , V_325 , V_195 -> V_326 ) ;
F_99 ( V_211 , V_327 , 0 , V_195 -> V_162 , 0 , 0 ) ;
F_100 ( V_211 , V_327 , V_195 -> V_326 ) ;
F_99 ( V_211 , V_328 , 0 , 50 , 0 , 0 ) ;
F_101 ( V_211 , V_322 , V_329 ) ;
if ( V_5 -> V_17 & V_330 )
F_101 ( V_211 , V_322 , V_331 ) ;
else
F_97 ( V_332 , V_211 -> V_333 ) ;
F_102 ( V_211 , V_195 -> V_165 , V_334 |
V_335 ) ;
V_195 -> V_285 = V_211 ;
}
static void F_103 ( struct V_318 * V_195 ,
struct V_171 * V_336 )
{
int V_196 ;
if ( ! V_336 -> V_181 || V_336 -> V_177 )
return;
V_196 = F_104 ( V_195 -> V_285 , V_336 -> V_181 ) ;
F_105 ( V_195 -> V_285 , V_196 ) ;
F_106 ( V_195 -> V_285 , V_337 ,
V_336 -> V_178 ) ;
if ( V_336 -> V_178 ) {
F_107 ( V_195 -> V_285 , V_320 , V_325 ,
V_336 -> V_175 ) ;
F_107 ( V_195 -> V_285 , V_320 , V_327 ,
V_195 -> V_338 ? V_195 -> V_162 - V_336 -> V_176 :
V_336 -> V_176 ) ;
F_107 ( V_195 -> V_285 , V_320 , V_328 ,
V_336 -> V_180 ) ;
}
}
static void F_108 ( struct V_4 * V_5 ,
struct V_182 * V_339 )
{
struct V_318 * V_195 = V_5 -> V_319 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < 2 ; V_108 ++ )
F_103 ( V_195 , & ( V_339 -> V_188 [ V_108 ] ) ) ;
if ( V_339 -> V_184 &&
! ( V_5 -> V_17 & V_330 ) )
F_107 ( V_195 -> V_285 , V_322 , V_329 , V_339 -> V_187 ) ;
if ( V_339 -> V_184 || V_339 -> V_186 <= 2 ) {
F_109 ( V_195 -> V_285 ) ;
F_110 ( V_195 -> V_285 ) ;
}
}
static int F_111 ( struct V_4 * V_5 , V_19 * V_78 )
{
struct V_318 * V_195 = V_5 -> V_319 ;
V_19 V_340 = ( ( V_78 [ 7 ] & 0xf ) * ( V_78 [ 7 ] & 0xf ) +
( V_78 [ 7 ] >> 4 ) * ( V_78 [ 7 ] >> 4 ) ) / 2 ;
V_19 V_341 = ( ( V_78 [ 13 ] & 0xf ) * ( V_78 [ 13 ] & 0xf ) +
( V_78 [ 13 ] >> 4 ) * ( V_78 [ 13 ] >> 4 ) ) / 2 ;
struct V_182 V_339 = {
. V_342 = V_78 [ 1 ] ,
. V_188 = {
{
. V_177 = 0 ,
. V_178 = ! ! V_78 [ 7 ] ,
. V_175 = F_112 ( & V_78 [ 3 ] ) ,
. V_176 = F_112 ( & V_78 [ 5 ] ) ,
. V_179 = V_340 ,
. V_180 = V_340 ,
. V_181 = V_78 [ 2 ] ,
} , {
. V_177 = 0 ,
. V_178 = ! ! V_78 [ 13 ] ,
. V_175 = F_112 ( & V_78 [ 9 ] ) ,
. V_176 = F_112 ( & V_78 [ 11 ] ) ,
. V_179 = V_341 ,
. V_180 = V_341 ,
. V_181 = V_78 [ 8 ] ,
}
} ,
. V_186 = V_195 -> V_165 ,
. V_185 = 0 ,
. V_184 = ( V_78 [ 0 ] >> 7 ) == 0 ,
. V_187 = V_78 [ 0 ] & 0x01 ,
} ;
F_108 ( V_5 , & V_339 ) ;
return 1 ;
}
static int F_113 ( struct V_1 * V_2 , V_19 * V_78 , int V_79 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_318 * V_195 = V_5 -> V_319 ;
struct V_3 * V_52 = (struct V_3 * ) V_78 ;
struct V_182 V_339 ;
if ( ! V_195 || ! V_195 -> V_285 )
return 1 ;
switch ( V_78 [ 0 ] ) {
case 0x02 :
if ( V_79 < 2 ) {
F_36 ( V_2 , L_41 ,
V_79 ) ;
return 1 ;
}
if ( V_5 -> V_17 & V_330 ) {
F_107 ( V_195 -> V_285 , V_322 , V_329 ,
! ! ( V_78 [ 1 ] & 0x01 ) ) ;
F_107 ( V_195 -> V_285 , V_322 , V_331 ,
! ! ( V_78 [ 1 ] & 0x02 ) ) ;
F_110 ( V_195 -> V_285 ) ;
return 0 ;
} else {
if ( V_79 < 21 )
return 1 ;
return F_111 ( V_5 , & V_78 [ 7 ] ) ;
}
case V_11 :
if ( ( V_52 -> V_36 . V_37 != V_195 -> V_343 ) ||
( V_52 -> V_36 . V_40 != V_344 ) )
return 1 ;
F_57 ( V_5 , V_78 + 4 , & V_339 ) ;
F_108 ( V_5 , & V_339 ) ;
return 0 ;
}
return 0 ;
}
static int F_114 ( struct V_4 * V_5 )
{
struct V_318 * V_195 = V_5 -> V_319 ;
struct V_158 V_159 = { 0 } ;
V_19 V_93 ;
int V_7 ;
V_7 = F_34 ( V_5 , V_345 ,
& V_195 -> V_343 , & V_93 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_53 ( V_5 , V_195 -> V_343 ,
& V_159 ) ;
if ( V_7 )
return V_7 ;
V_195 -> V_161 = V_159 . V_161 ;
V_195 -> V_162 = V_159 . V_162 ;
V_195 -> V_165 = V_159 . V_165 ;
V_195 -> V_338 = V_159 . V_166 == V_346 ;
V_195 -> V_326 = V_159 . V_167 ;
if ( ! V_195 -> V_326 )
V_195 -> V_326 = V_347 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 , const struct V_348 * V_267 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_318 * V_195 ;
V_195 = F_116 ( & V_2 -> V_212 , sizeof( struct V_318 ) ,
V_43 ) ;
if ( ! V_195 )
return - V_44 ;
V_5 -> V_319 = V_195 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , bool V_349 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_318 * V_195 = V_5 -> V_319 ;
int V_7 ;
if ( ! V_195 -> V_161 ) {
V_7 = F_114 ( V_5 ) ;
if ( V_7 ) {
F_36 ( V_2 , L_42 , V_7 ) ;
return V_7 ;
}
}
return F_55 ( V_5 , V_195 -> V_343 ,
true , true ) ;
}
static int F_118 ( struct V_1 * V_2 , bool V_349 )
{
struct V_3 V_23 ;
struct V_4 * V_45 ;
V_45 = F_2 ( V_2 ) ;
return F_13 (
V_45 ,
V_9 ,
V_350 ,
V_351 ,
( V_19 * ) V_352 ,
sizeof( V_352 ) ,
& V_23
) ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_353 * V_354 ;
V_354 = F_116 ( & V_2 -> V_212 , sizeof( struct V_353 ) ,
V_43 ) ;
if ( ! V_354 )
return - V_44 ;
V_5 -> V_319 = V_354 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 , V_19 * V_78 , int V_79 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_353 * V_355 = V_5 -> V_319 ;
if ( ! V_355 || ! V_355 -> V_285 ) {
F_36 ( V_2 , L_43 ) ;
return - V_42 ;
}
if ( V_79 < 7 ) {
F_36 ( V_2 , L_44 ) ;
return 0 ;
}
if ( V_78 [ 0 ] == V_11 &&
V_78 [ 2 ] == V_350 && V_78 [ 6 ] == 0x00 ) {
switch ( V_78 [ 5 ] ) {
case 0xaf :
F_121 ( V_355 -> V_285 , V_356 , 1 ) ;
break;
case 0xb0 :
F_121 ( V_355 -> V_285 , V_357 , 1 ) ;
break;
case 0xae :
F_121 ( V_355 -> V_285 , V_358 , 1 ) ;
break;
case 0x00 :
F_121 ( V_355 -> V_285 , V_358 , 0 ) ;
F_121 ( V_355 -> V_285 , V_357 , 0 ) ;
F_121 ( V_355 -> V_285 , V_356 , 0 ) ;
break;
default:
F_36 ( V_2 , L_44 ) ;
return 0 ;
}
F_110 ( V_355 -> V_285 ) ;
} else if ( V_78 [ 0 ] == 0x02 ) {
int V_359 ;
F_121 ( V_355 -> V_285 , V_329 ,
! ! ( V_78 [ 1 ] & V_360 ) ) ;
F_121 ( V_355 -> V_285 , V_331 ,
! ! ( V_78 [ 1 ] & V_361 ) ) ;
if ( V_78 [ 1 ] & V_362 )
F_122 ( V_355 -> V_285 , V_363 , - 1 ) ;
else if ( V_78 [ 1 ] & V_364 )
F_122 ( V_355 -> V_285 , V_363 , 1 ) ;
V_359 = F_123 ( F_124 ( V_2 , V_78 + 3 , 0 , 12 ) , 12 ) ;
F_122 ( V_355 -> V_285 , V_365 , V_359 ) ;
V_359 = F_123 ( F_124 ( V_2 , V_78 + 3 , 12 , 12 ) , 12 ) ;
F_122 ( V_355 -> V_285 , V_366 , V_359 ) ;
V_359 = F_123 ( V_78 [ 6 ] , 8 ) ;
F_122 ( V_355 -> V_285 , V_367 , V_359 ) ;
F_110 ( V_355 -> V_285 ) ;
}
return 1 ;
}
static void F_125 ( struct V_4 * V_5 ,
struct V_211 * V_211 , bool V_317 )
{
struct V_353 * V_355 = V_5 -> V_319 ;
V_355 -> V_285 = V_211 ;
F_97 ( V_322 , V_355 -> V_285 -> V_321 ) ;
F_97 ( V_356 , V_355 -> V_285 -> V_368 ) ;
F_97 ( V_331 , V_355 -> V_285 -> V_368 ) ;
F_97 ( V_329 , V_355 -> V_285 -> V_368 ) ;
F_97 ( V_358 , V_355 -> V_285 -> V_368 ) ;
F_97 ( V_357 , V_355 -> V_285 -> V_368 ) ;
F_97 ( V_323 , V_355 -> V_285 -> V_321 ) ;
F_97 ( V_365 , V_355 -> V_285 -> V_369 ) ;
F_97 ( V_366 , V_355 -> V_285 -> V_369 ) ;
F_97 ( V_367 , V_355 -> V_285 -> V_369 ) ;
F_97 ( V_363 , V_355 -> V_285 -> V_369 ) ;
}
static int F_126 ( struct V_1 * V_2 , struct V_279 * V_310 ,
struct V_311 * V_312 , struct V_313 * V_314 ,
unsigned long * * V_315 , int * V_316 )
{
return - 1 ;
}
static int F_127 ( struct V_4 * V_5 )
{
struct V_370 * V_371 = V_5 -> V_319 ;
struct V_151 V_152 = {} ;
int V_7 ;
V_19 V_93 ;
if ( ! V_371 -> V_37 ) {
V_7 = F_34 ( V_5 ,
V_372 ,
& V_371 -> V_37 , & V_93 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_52 ( V_5 , V_371 -> V_37 , & V_152 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_370 * V_371 ;
V_371 = F_116 ( & V_2 -> V_212 , sizeof( struct V_370 ) ,
V_43 ) ;
if ( ! V_371 )
return - V_44 ;
V_5 -> V_319 = V_371 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , bool V_349 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_373 )
return 0 ;
return F_127 ( V_5 ) ;
}
static int F_130 ( struct V_4 * V_5 )
{
V_19 V_93 ;
V_19 V_37 ;
int V_7 ;
V_7 = F_34 ( V_5 , V_374 ,
& V_37 , & V_93 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_82 ( V_5 , V_37 ) ;
if ( V_7 )
F_66 ( V_5 -> V_27 , L_45 ,
V_7 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , struct V_279 * V_310 ,
struct V_311 * V_312 , struct V_313 * V_314 ,
unsigned long * * V_315 , int * V_316 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_375 )
return F_95 ( V_2 , V_310 , V_312 , V_314 , V_315 , V_316 ) ;
else if ( V_5 -> V_17 & V_376 &&
V_312 -> V_377 != V_378 )
return F_126 ( V_2 , V_310 , V_312 , V_314 , V_315 , V_316 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , struct V_279 * V_310 ,
struct V_311 * V_312 , struct V_313 * V_314 ,
unsigned long * * V_315 , int * V_316 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_379 ) {
if ( V_314 -> type == V_320 && ( V_314 -> V_380 == V_381 ||
V_314 -> V_380 == V_382 || V_314 -> V_380 == V_383 ||
V_314 -> V_380 == V_384 ) ) {
V_312 -> V_377 = V_385 ;
}
}
return 0 ;
}
static void F_133 ( struct V_4 * V_5 ,
struct V_211 * V_285 , bool V_317 )
{
if ( V_5 -> V_17 & V_375 )
F_96 ( V_5 , V_285 , V_317 ) ;
else if ( V_5 -> V_17 & V_376 )
F_125 ( V_5 , V_285 , V_317 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_211 * V_285 = V_280 -> V_285 ;
F_133 ( V_5 , V_285 , true ) ;
return 0 ;
}
static int F_135 ( struct V_4 * V_5 , V_19 * V_78 ,
int V_79 )
{
struct V_3 * V_50 = V_5 -> V_25 ;
struct V_3 * V_51 = V_5 -> V_25 ;
struct V_3 * V_52 = (struct V_3 * ) V_78 ;
int V_7 ;
if ( F_136 ( F_137 ( & V_5 -> V_24 ) ) ) {
if ( F_17 ( V_50 , V_52 ) ||
F_18 ( V_50 , V_52 ) ) {
* V_51 = * V_52 ;
V_5 -> V_26 = true ;
F_138 ( & V_5 -> V_28 ) ;
return 1 ;
}
}
if ( F_136 ( F_19 ( V_52 ) ) ) {
F_90 ( & V_5 -> V_349 ,
! ( V_52 -> V_32 . V_35 [ 0 ] & ( 1 << 6 ) ) ) ;
if ( F_139 ( & V_5 -> V_49 ) == 0 )
F_7 ( L_46 , V_30 ) ;
return 1 ;
}
if ( V_5 -> V_121 & V_386 ) {
V_7 = F_47 ( V_5 , V_78 , V_79 ) ;
if ( V_7 != 0 )
return V_7 ;
V_7 = F_51 ( V_5 , V_78 , V_79 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( V_5 -> V_121 & V_387 ) {
V_7 = F_29 ( V_5 , V_78 , V_79 ) ;
if ( V_7 != 0 )
return V_7 ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , struct V_388 * V_52 ,
V_19 * V_78 , int V_79 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_7 = 0 ;
switch ( V_78 [ 0 ] ) {
case V_13 :
if ( V_79 != V_14 ) {
F_36 ( V_2 , L_47 ,
V_79 ) ;
return 1 ;
}
V_7 = F_135 ( V_5 , V_78 , V_79 ) ;
break;
case V_11 :
if ( V_79 != V_12 ) {
F_36 ( V_2 , L_47 ,
V_79 ) ;
return 1 ;
}
V_7 = F_135 ( V_5 , V_78 , V_79 ) ;
break;
case V_9 :
if ( V_79 != V_10 ) {
F_36 ( V_2 , L_47 ,
V_79 ) ;
return 1 ;
}
V_7 = F_135 ( V_5 , V_78 , V_79 ) ;
break;
}
if ( V_7 != 0 )
return V_7 ;
if ( V_5 -> V_17 & V_375 )
return F_113 ( V_2 , V_78 , V_79 ) ;
else if ( V_5 -> V_17 & V_376 )
return F_120 ( V_2 , V_78 , V_79 ) ;
return 0 ;
}
static int F_141 ( struct V_4 * V_5 )
{
static T_5 V_389 = F_142 ( 0 ) ;
struct V_390 V_391 = { . V_392 = V_5 } ;
struct V_393 * V_394 = & V_5 -> V_74 . V_394 ;
enum V_128 * V_395 ;
struct V_396 * V_74 ;
unsigned int V_397 ;
unsigned long V_398 ;
int V_7 ;
if ( V_5 -> V_74 . V_82 )
return 0 ;
V_5 -> V_74 . V_37 = 0xff ;
V_5 -> V_74 . V_144 = 0xff ;
if ( V_5 -> V_99 >= 2 ) {
if ( V_5 -> V_17 & V_399 )
V_7 = F_50 ( V_5 ) ;
else
V_7 = F_46 ( V_5 ) ;
if ( V_7 )
return V_7 ;
V_5 -> V_121 |= V_386 ;
} else {
V_7 = F_26 ( V_5 ) ;
if ( V_7 ) {
V_7 = F_28 ( V_5 ) ;
if ( V_7 )
return - V_96 ;
V_5 -> V_121 |= V_123 ;
} else {
V_5 -> V_121 |= V_122 ;
}
V_5 -> V_121 |= V_387 ;
}
V_395 = F_143 ( & V_5 -> V_27 -> V_212 ,
V_400 ,
sizeof( V_400 ) ,
V_43 ) ;
V_397 = F_70 ( V_400 ) - 2 ;
if ( V_5 -> V_121 & V_123 )
V_395 [ V_397 ++ ] =
V_134 ;
if ( V_5 -> V_121 & V_122 )
V_395 [ V_397 ++ ] =
V_135 ;
V_74 = & V_5 -> V_74 ;
V_398 = F_144 ( & V_389 ) - 1 ;
V_394 -> V_401 = V_395 ;
V_394 -> V_402 = V_397 ;
V_394 -> V_403 = F_48 ;
sprintf ( V_74 -> V_53 , L_48 , V_398 ) ;
V_394 -> V_53 = V_74 -> V_53 ;
V_394 -> type = V_404 ;
V_394 -> V_405 = 0 ;
V_74 -> V_82 = F_145 ( & V_5 -> V_27 -> V_212 ,
& V_74 -> V_394 ,
& V_391 ) ;
if ( F_146 ( V_74 -> V_82 ) )
return F_147 ( V_74 -> V_82 ) ;
F_148 ( V_74 -> V_82 , & V_5 -> V_27 -> V_212 ) ;
return V_7 ;
}
static void F_149 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_53 ;
if ( V_5 -> V_99 < 2 )
return;
V_53 = F_41 ( V_5 ) ;
if ( ! V_53 ) {
F_36 ( V_2 , L_49 ) ;
} else {
F_7 ( L_50 , V_53 ) ;
snprintf ( V_2 -> V_53 , sizeof( V_2 -> V_53 ) , L_9 , V_53 ) ;
}
F_12 ( V_53 ) ;
}
static int F_150 ( struct V_211 * V_212 )
{
struct V_1 * V_278 = F_151 ( V_212 ) ;
return F_152 ( V_278 ) ;
}
static void F_153 ( struct V_211 * V_212 )
{
struct V_1 * V_278 = F_151 ( V_212 ) ;
F_154 ( V_278 ) ;
}
static struct V_211 * F_155 ( struct V_1 * V_2 )
{
struct V_211 * V_211 = F_156 ( & V_2 -> V_212 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_211 )
return NULL ;
F_157 ( V_211 , V_2 ) ;
V_211 -> V_406 = F_150 ;
V_211 -> V_407 = F_153 ;
V_211 -> V_53 = V_5 -> V_53 ;
V_211 -> V_408 = V_2 -> V_408 ;
V_211 -> V_89 = V_2 -> V_89 ;
V_211 -> V_267 . V_409 = V_2 -> V_410 ;
V_211 -> V_267 . V_411 = V_2 -> V_411 ;
V_211 -> V_267 . V_90 = V_2 -> V_90 ;
V_211 -> V_267 . V_294 = V_2 -> V_294 ;
V_211 -> V_212 . V_412 = & V_2 -> V_212 ;
return V_211 ;
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_27 ;
int V_7 = 0 ;
bool V_349 = F_65 ( & V_5 -> V_349 ) ;
struct V_211 * V_285 ;
char * V_53 , * V_413 ;
if ( ! V_349 ) {
if ( V_5 -> V_74 . V_82 ) {
V_5 -> V_74 . V_75 = false ;
V_5 -> V_74 . V_67 = V_71 ;
V_5 -> V_74 . V_61 = V_66 ;
F_30 ( V_5 -> V_74 . V_82 ) ;
}
return;
}
if ( V_5 -> V_17 & V_375 ) {
V_7 = F_117 ( V_2 , V_349 ) ;
if ( V_7 )
return;
} else if ( V_5 -> V_17 & V_376 ) {
V_7 = F_118 ( V_2 , V_349 ) ;
if ( V_7 )
return;
} else if ( V_5 -> V_17 & V_414 ) {
V_7 = F_129 ( V_2 , V_349 ) ;
if ( V_7 )
return;
}
if ( ! V_5 -> V_99 ) {
V_7 = ! F_37 ( V_5 ) ;
if ( V_7 ) {
F_36 ( V_2 , L_51 ) ;
return;
}
F_91 ( V_2 , L_12 ,
V_5 -> V_99 , V_5 -> V_100 ) ;
}
if ( V_5 -> V_53 == V_2 -> V_53 && V_5 -> V_99 >= 2 ) {
V_53 = F_41 ( V_5 ) ;
if ( ! V_53 ) {
F_36 ( V_2 ,
L_49 ) ;
return;
}
V_413 = F_158 ( & V_2 -> V_212 , V_43 , L_9 , V_53 ) ;
F_12 ( V_53 ) ;
if ( ! V_413 )
return;
V_5 -> V_53 = V_413 ;
}
F_141 ( V_5 ) ;
if ( V_5 -> V_121 & V_387 ) {
F_22 ( V_5 ) ;
if ( V_5 -> V_121 & V_123 )
F_28 ( V_5 ) ;
else
F_26 ( V_5 ) ;
} else if ( V_5 -> V_121 & V_386 ) {
F_46 ( V_5 ) ;
}
if ( V_5 -> V_74 . V_82 )
F_30 ( V_5 -> V_74 . V_82 ) ;
if ( ! ( V_5 -> V_17 & V_415 ) || V_5 -> V_416 )
return;
V_285 = F_155 ( V_2 ) ;
if ( ! V_285 ) {
F_36 ( V_2 , L_52 , V_7 ) ;
return;
}
F_133 ( V_5 , V_285 , false ) ;
V_7 = F_159 ( V_285 ) ;
if ( V_7 )
F_160 ( V_285 ) ;
V_5 -> V_416 = V_285 ;
}
static int F_161 ( struct V_1 * V_2 , const struct V_348 * V_267 )
{
struct V_4 * V_5 ;
int V_7 ;
bool V_349 ;
unsigned int V_417 = V_418 ;
V_5 = F_116 ( & V_2 -> V_212 , sizeof( struct V_4 ) ,
V_43 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_27 = V_2 ;
V_5 -> V_53 = V_2 -> V_53 ;
F_162 ( V_2 , V_5 ) ;
V_5 -> V_17 = V_267 -> V_419 ;
if ( V_267 -> V_420 == V_421 )
V_5 -> V_17 |= V_422 ;
if ( V_423 ) {
V_5 -> V_17 &= ~ V_375 ;
V_5 -> V_17 &= ~ V_415 ;
}
if ( V_5 -> V_17 & V_375 ) {
V_7 = F_115 ( V_2 , V_267 ) ;
if ( V_7 )
goto V_424;
} else if ( V_5 -> V_17 & V_376 ) {
V_7 = F_119 ( V_2 ) ;
if ( V_7 )
goto V_424;
} else if ( V_5 -> V_17 & V_414 ) {
V_7 = F_128 ( V_2 ) ;
if ( V_7 )
goto V_424;
}
F_62 ( & V_5 -> V_49 , F_14 ) ;
F_163 ( & V_5 -> V_24 ) ;
F_164 ( & V_5 -> V_28 ) ;
V_7 = F_165 ( & V_2 -> V_212 . V_425 , & V_426 ) ;
if ( V_7 )
F_66 ( V_2 , L_53 ,
V_2 -> V_53 ) ;
V_7 = F_166 ( V_2 ) ;
if ( V_7 ) {
F_36 ( V_2 , L_54 , V_30 ) ;
goto V_427;
}
if ( V_5 -> V_17 & V_415 )
V_417 &= ~ V_428 ;
if ( V_5 -> V_17 & V_379 ) {
V_7 = F_167 ( V_2 , V_417 ) ;
if ( V_7 ) {
F_36 ( V_2 , L_55 ) ;
goto V_429;
}
V_7 = F_152 ( V_2 ) ;
if ( V_7 < 0 ) {
F_168 ( & V_2 -> V_212 , L_56 ,
V_30 , V_7 ) ;
F_169 ( V_2 ) ;
goto V_429;
}
}
F_170 ( V_2 ) ;
if ( V_5 -> V_17 & V_422 )
F_33 ( V_5 ) ;
V_349 = F_37 ( V_5 ) ;
F_90 ( & V_5 -> V_349 , V_349 ) ;
if ( ! ( V_5 -> V_17 & V_422 ) ) {
if ( ! V_349 ) {
V_7 = - V_15 ;
F_36 ( V_2 , L_57 ) ;
goto V_430;
}
F_91 ( V_2 , L_12 ,
V_5 -> V_99 , V_5 -> V_100 ) ;
F_149 ( V_2 ) ;
}
if ( V_349 && ( V_5 -> V_17 & V_375 ) ) {
V_7 = F_114 ( V_5 ) ;
if ( V_7 )
goto V_430;
} else if ( V_349 && ( V_5 -> V_17 & V_379 ) ) {
V_7 = F_130 ( V_5 ) ;
if ( V_7 )
goto V_430;
}
F_171 ( V_2 ) ;
if ( ! ( V_5 -> V_17 & V_379 ) ) {
V_7 = F_167 ( V_2 , V_417 ) ;
if ( V_7 ) {
F_36 ( V_2 , L_58 , V_30 ) ;
goto V_429;
}
}
F_170 ( V_2 ) ;
F_16 ( V_5 ) ;
return V_7 ;
V_430:
F_171 ( V_2 ) ;
if ( V_5 -> V_17 & V_379 ) {
F_154 ( V_2 ) ;
F_169 ( V_2 ) ;
}
V_429:
V_427:
F_172 ( & V_2 -> V_212 . V_425 , & V_426 ) ;
F_173 ( & V_5 -> V_49 ) ;
F_174 ( & V_5 -> V_24 ) ;
V_424:
F_162 ( V_2 , NULL ) ;
return V_7 ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_172 ( & V_2 -> V_212 . V_425 , & V_426 ) ;
if ( V_5 -> V_17 & V_379 ) {
F_92 ( V_2 ) ;
F_154 ( V_2 ) ;
}
F_169 ( V_2 ) ;
F_173 ( & V_5 -> V_49 ) ;
F_174 ( & V_5 -> V_24 ) ;
}
