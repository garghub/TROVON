static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
unsigned V_5 , T_3 * V_6 )
{
int V_7 = - V_8 ;
T_1 V_9 = 4 ;
T_4 * V_10 ;
int V_11 , V_12 ;
T_5 * V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
const struct V_16 * V_18 ;
if ( ! V_6 ) return - V_19 ;
V_13 = ( T_5 * ) V_6 -> V_4 ;
if ( ! V_13 ) return - V_19 ;
if ( V_5 && V_20 > 1 ) {
F_2 ( L_1 , V_3 , V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 += 16 ) {
F_2 ( L_2 , V_11 ,
F_3 ( & V_4 [ V_11 ] ) ,
F_3 ( & V_4 [ V_11 + 4 ] ) ,
F_3 ( & V_4 [ V_11 + 8 ] ) ,
F_3 ( & V_4 [ V_11 + 12 ] ) ) ;
}
}
V_10 = ( T_4 * ) & V_13 [ 1 ] ;
V_13 -> V_21 = F_4 ( 16 ) ;
V_15 = V_2 -> V_22 ;
V_18 = F_5 ( V_15 , & V_17 ) ;
switch ( V_3 ) {
case V_23 :
F_2 ( L_3 , V_24 ) ;
V_9 = sizeof( V_25 ) ;
V_12 = V_9 / sizeof( T_1 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_10 [ V_11 ] = F_4 ( V_25 [ V_11 ] ) ;
V_7 = 0 ;
break;
case V_26 :
F_2 ( L_4 , V_24 ) ;
* V_10 = F_4 ( 0 ) ;
V_7 = 0 ;
break;
case V_27 :
F_2 ( L_5 , V_24 ) ;
* V_10 = F_4 ( V_2 -> V_28 ) ;
V_7 = 0 ;
break;
case V_29 :
F_2 ( L_6 , V_24 ) ;
* V_10 = F_4 ( V_2 -> V_28 ) ;
V_7 = 0 ;
break;
case V_30 :
F_2 ( L_7 , V_24 ) ;
if ( V_2 -> V_22 ) {
* V_10 = F_4 ( V_2 -> V_22 -> V_31 ) ;
V_7 = 0 ;
}
break;
case V_32 :
if ( V_20 > 1 )
F_2 ( L_8 , V_24 ) ;
if ( V_2 -> V_33 == V_34 )
* V_10 = F_4 ( 0 ) ;
else
* V_10 = F_4 ( V_2 -> V_35 ) ;
V_7 = 0 ;
break;
case V_36 :
F_2 ( L_9 , V_24 ) ;
if ( V_2 -> V_22 ) {
* V_10 = F_4 ( V_2 -> V_22 -> V_31 ) ;
V_7 = 0 ;
}
break;
case V_37 :
F_2 ( L_10 , V_24 ) ;
if ( V_2 -> V_22 ) {
* V_10 = F_4 ( V_2 -> V_22 -> V_31 ) ;
V_7 = 0 ;
}
break;
case V_38 :
F_2 ( L_11 , V_24 ) ;
* V_10 = F_4 ( V_2 -> V_39 ) ;
V_7 = 0 ;
break;
case V_40 :
F_2 ( L_12 , V_24 ) ;
if ( V_2 -> V_41 ) {
V_9 = strlen ( V_2 -> V_41 ) ;
memcpy ( V_10 , V_2 -> V_41 , V_9 ) ;
} else {
V_10 [ 0 ] = 0 ;
}
V_7 = 0 ;
break;
case V_42 :
F_2 ( L_13 , V_24 ) ;
* V_10 = V_43 ;
V_7 = 0 ;
break;
case V_44 :
F_2 ( L_14 , V_24 ) ;
* V_10 = F_4 ( * V_2 -> V_45 ) ;
V_7 = 0 ;
break;
case V_46 :
F_2 ( L_15 , V_24 ) ;
* V_10 = F_4 ( V_47 ) ;
V_7 = 0 ;
break;
case V_48 :
if ( V_20 > 1 )
F_2 ( L_16 , V_24 ) ;
* V_10 = F_4 ( V_2 -> V_33 ) ;
V_7 = 0 ;
break;
case V_49 :
F_2 ( L_17 , V_24 ) ;
* V_10 = F_4 ( 0 ) ;
V_7 = 0 ;
break;
case V_50 :
F_2 ( L_18 , V_24 ) ;
* V_10 = F_4 (
V_51
| V_52 ) ;
V_7 = 0 ;
break;
case V_53 :
if ( V_20 > 1 )
F_2 ( L_19 , V_24 ) ;
if ( V_18 ) {
* V_10 = F_4 ( V_18 -> V_54
- V_18 -> V_55 - V_18 -> V_56 ) ;
V_7 = 0 ;
}
break;
case V_57 :
if ( V_20 > 1 )
F_2 ( L_20 , V_24 ) ;
if ( V_18 ) {
* V_10 = F_4 ( V_18 -> V_58
- V_18 -> V_59 - V_18 -> V_60 ) ;
V_7 = 0 ;
}
break;
case V_61 :
if ( V_20 > 1 )
F_2 ( L_21 , V_24 ) ;
if ( V_18 ) {
* V_10 = F_4 ( V_18 -> V_55 ) ;
V_7 = 0 ;
}
break;
case V_62 :
if ( V_20 > 1 )
F_2 ( L_22 , V_24 ) ;
if ( V_18 ) {
* V_10 = F_4 ( V_18 -> V_59 ) ;
V_7 = 0 ;
}
break;
case V_63 :
F_2 ( L_23 , V_24 ) ;
if ( V_18 ) {
* V_10 = F_4 ( V_18 -> V_60 ) ;
V_7 = 0 ;
}
break;
case V_64 :
F_2 ( L_24 , V_24 ) ;
if ( V_2 -> V_22 ) {
V_9 = V_65 ;
memcpy ( V_10 , V_2 -> V_66 , V_9 ) ;
V_7 = 0 ;
}
break;
case V_67 :
F_2 ( L_25 , V_24 ) ;
if ( V_2 -> V_22 ) {
V_9 = V_65 ;
memcpy ( V_10 , V_2 -> V_66 , V_9 ) ;
V_7 = 0 ;
}
break;
case V_68 :
F_2 ( L_26 , V_24 ) ;
* V_10 = F_4 ( 0xE0000000 ) ;
V_7 = 0 ;
break;
case V_69 :
F_2 ( L_27 , V_24 ) ;
* V_10 = F_4 ( 1 ) ;
V_7 = 0 ;
break;
case V_70 :
F_2 ( L_28 , V_24 ) ;
* V_10 = F_4 ( 0 ) ;
V_7 = 0 ;
break;
case V_71 :
F_2 ( L_29 , V_24 ) ;
if ( V_18 ) {
* V_10 = F_4 ( V_18 -> V_72 ) ;
V_7 = 0 ;
}
break;
case V_73 :
F_2 ( L_30 , V_24 ) ;
* V_10 = F_4 ( 0 ) ;
V_7 = 0 ;
break;
case V_74 :
F_2 ( L_31 , V_24 ) ;
* V_10 = F_4 ( 0 ) ;
V_7 = 0 ;
break;
default:
F_6 ( L_32 , V_24 , V_3 ) ;
}
if ( V_7 < 0 )
V_9 = 0 ;
V_13 -> V_75 = F_4 ( V_9 ) ;
V_6 -> V_9 = V_9 + sizeof( * V_13 ) ;
V_13 -> V_76 = F_4 ( V_6 -> V_9 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_1 V_5 , T_3 * V_6 )
{
T_6 * V_13 ;
int V_11 , V_7 = - V_8 ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_6 * ) V_6 -> V_4 ;
if ( ! V_13 )
return - V_19 ;
if ( V_5 && V_20 > 1 ) {
F_2 ( L_33 , V_3 , V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 += 16 ) {
F_2 ( L_2 , V_11 ,
F_3 ( & V_4 [ V_11 ] ) ,
F_3 ( & V_4 [ V_11 + 4 ] ) ,
F_3 ( & V_4 [ V_11 + 8 ] ) ,
F_3 ( & V_4 [ V_11 + 12 ] ) ) ;
}
}
switch ( V_3 ) {
case V_44 :
* V_2 -> V_45 = ( V_77 ) F_3 ( V_4 ) ;
F_2 ( L_34 ,
V_24 , * V_2 -> V_45 ) ;
V_7 = 0 ;
if ( * V_2 -> V_45 ) {
V_2 -> V_78 = V_79 ;
F_8 ( V_2 -> V_22 ) ;
if ( F_9 ( V_2 -> V_22 ) )
F_10 ( V_2 -> V_22 ) ;
} else {
V_2 -> V_78 = V_80 ;
F_11 ( V_2 -> V_22 ) ;
F_12 ( V_2 -> V_22 ) ;
}
break;
case V_68 :
F_2 ( L_26 , V_24 ) ;
V_7 = 0 ;
break;
default:
F_6 ( L_35 ,
V_24 , V_3 , V_5 ) ;
}
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_7 * V_4 )
{
T_8 * V_13 ;
T_3 * V_6 ;
if ( ! V_2 -> V_22 )
return - V_8 ;
V_6 = F_14 ( V_2 , sizeof( T_8 ) ) ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_8 * ) V_6 -> V_4 ;
V_13 -> V_81 = F_4 ( V_82 ) ;
V_13 -> V_76 = F_4 ( 52 ) ;
V_13 -> V_83 = V_4 -> V_83 ;
V_13 -> V_84 = F_4 ( V_85 ) ;
V_13 -> V_86 = F_4 ( V_87 ) ;
V_13 -> V_88 = F_4 ( V_89 ) ;
V_13 -> V_90 = F_4 ( V_91 ) ;
V_13 -> V_92 = F_4 ( V_93 ) ;
V_13 -> V_94 = F_4 ( 1 ) ;
V_13 -> V_95 = F_4 (
V_2 -> V_22 -> V_31
+ sizeof( struct V_96 )
+ sizeof( struct V_97 )
+ 22 ) ;
V_13 -> V_98 = F_4 ( 0 ) ;
V_13 -> V_99 = F_4 ( 0 ) ;
V_13 -> V_100 = F_4 ( 0 ) ;
V_2 -> V_101 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_9 * V_4 )
{
T_5 * V_13 ;
T_3 * V_6 ;
if ( ! V_2 -> V_22 )
return - V_8 ;
V_6 = F_14 ( V_2 ,
sizeof( V_25 ) + sizeof( T_5 ) ) ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_5 * ) V_6 -> V_4 ;
V_13 -> V_81 = F_4 ( V_103 ) ;
V_13 -> V_83 = V_4 -> V_83 ;
if ( F_1 ( V_2 , F_16 ( V_4 -> V_3 ) ,
F_16 ( V_4 -> V_21 )
+ 8 + ( T_2 * ) V_4 ,
F_16 ( V_4 -> V_75 ) ,
V_6 ) ) {
V_13 -> V_84 = F_4 ( V_104 ) ;
V_13 -> V_76 = F_4 ( sizeof *V_13 ) ;
V_13 -> V_75 = F_4 ( 0 ) ;
V_13 -> V_21 = F_4 ( 0 ) ;
} else
V_13 -> V_84 = F_4 ( V_85 ) ;
V_2 -> V_101 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_10 * V_4 )
{
T_1 V_105 , V_106 ;
T_6 * V_13 ;
T_3 * V_6 ;
V_6 = F_14 ( V_2 , sizeof( T_6 ) ) ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_6 * ) V_6 -> V_4 ;
V_105 = F_16 ( V_4 -> V_75 ) ;
V_106 = F_16 ( V_4 -> V_21 ) ;
#ifdef F_18
F_2 ( L_36 , V_24 , V_105 ) ;
F_2 ( L_37 , V_24 , V_106 ) ;
F_2 ( L_38 , V_24 ) ;
for ( V_11 = 0 ; V_11 < V_105 ; V_11 ++ ) {
F_2 ( L_39 , * ( ( ( T_2 * ) V_4 ) + V_11 + 8 + V_106 ) ) ;
}
F_2 ( L_40 ) ;
#endif
V_13 -> V_81 = F_4 ( V_107 ) ;
V_13 -> V_76 = F_4 ( 16 ) ;
V_13 -> V_83 = V_4 -> V_83 ;
if ( F_7 ( V_2 , F_16 ( V_4 -> V_3 ) ,
( ( T_2 * ) V_4 ) + 8 + V_106 , V_105 , V_6 ) )
V_13 -> V_84 = F_4 ( V_104 ) ;
else
V_13 -> V_84 = F_4 ( V_85 ) ;
V_2 -> V_101 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_11 * V_4 )
{
T_12 * V_13 ;
T_3 * V_6 ;
T_2 * V_108 ;
T_1 V_9 ;
while ( ( V_108 = F_20 ( V_2 , & V_9 ) ) )
F_21 ( V_2 , V_108 ) ;
V_6 = F_14 ( V_2 , sizeof( T_12 ) ) ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_12 * ) V_6 -> V_4 ;
V_13 -> V_81 = F_4 ( V_109 ) ;
V_13 -> V_76 = F_4 ( 16 ) ;
V_13 -> V_84 = F_4 ( V_85 ) ;
V_13 -> V_110 = F_4 ( 1 ) ;
V_2 -> V_101 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
T_13 * V_4 )
{
T_14 * V_13 ;
T_3 * V_6 ;
V_6 = F_14 ( V_2 , sizeof( T_14 ) ) ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_14 * ) V_6 -> V_4 ;
V_13 -> V_81 = F_4 ( V_111 ) ;
V_13 -> V_76 = F_4 ( 16 ) ;
V_13 -> V_83 = V_4 -> V_83 ;
V_13 -> V_84 = F_4 ( V_85 ) ;
V_2 -> V_101 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_112 )
{
T_15 * V_13 ;
T_3 * V_6 ;
if ( V_2 -> V_78 == V_113 )
return - V_8 ;
V_6 = F_14 ( V_2 , sizeof( T_15 ) ) ;
if ( ! V_6 )
return - V_19 ;
V_13 = ( T_15 * ) V_6 -> V_4 ;
V_13 -> V_81 = F_4 ( V_114 ) ;
V_13 -> V_76 = F_4 ( 20 ) ;
V_13 -> V_84 = F_4 ( V_112 ) ;
V_13 -> V_115 = F_4 ( 0 ) ;
V_13 -> V_116 = F_4 ( 0 ) ;
V_2 -> V_101 ( V_2 -> V_102 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
V_2 -> V_33 = V_117 ;
return F_23 ( V_2 , V_118 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
V_2 -> V_33 = V_34 ;
return F_23 ( V_2 , V_119 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
T_2 * V_4 ;
T_1 V_9 ;
if ( ! V_2 )
return;
V_2 -> V_78 = V_113 ;
while ( ( V_4 = F_20 ( V_2 , & V_9 ) ) )
F_21 ( V_2 , V_4 ) ;
}
void F_27 ( struct V_1 * V_2 , const T_2 * V_120 )
{
V_2 -> V_66 = V_120 ;
}
int F_28 ( struct V_1 * V_2 , T_2 * V_4 )
{
T_1 V_121 , V_122 ;
T_4 * V_123 ;
if ( ! V_4 )
return - V_19 ;
V_123 = ( T_4 * ) V_4 ;
V_121 = F_3 ( V_123 ++ ) ;
V_122 = F_3 ( V_123 ++ ) ;
if ( ! V_2 )
return - V_8 ;
switch ( V_121 ) {
case V_124 :
F_2 ( L_41 ,
V_24 ) ;
V_2 -> V_78 = V_80 ;
return F_13 ( V_2 , ( T_7 * ) V_4 ) ;
case V_125 :
F_2 ( L_42 ,
V_24 ) ;
V_2 -> V_78 = V_113 ;
if ( V_2 -> V_22 ) {
F_11 ( V_2 -> V_22 ) ;
F_12 ( V_2 -> V_22 ) ;
}
return 0 ;
case V_126 :
return F_15 ( V_2 ,
( T_9 * ) V_4 ) ;
case V_127 :
return F_17 ( V_2 , ( T_10 * ) V_4 ) ;
case V_128 :
F_2 ( L_43 ,
V_24 ) ;
return F_19 ( V_2 ,
( T_11 * ) V_4 ) ;
case V_129 :
if ( V_20 > 1 )
F_2 ( L_44 ,
V_24 ) ;
return F_22 ( V_2 ,
( T_13 * )
V_4 ) ;
default:
F_6 ( L_45 ,
V_24 , V_121 , V_122 ) ;
F_29 ( V_24 , V_130 ,
V_4 , V_122 ) ;
break;
}
return - V_8 ;
}
static inline int F_30 ( void )
{
return F_31 ( & V_131 , 0 , 0 , V_132 ) ;
}
static inline void F_32 ( int V_133 )
{
F_33 ( & V_131 , V_133 ) ;
}
struct V_1 * F_34 ( void (* V_101)( void * V_102 ) , void * V_102 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ! V_101 )
return F_35 ( - V_134 ) ;
V_11 = F_30 () ;
if ( V_11 < 0 ) {
F_2 ( L_46 ) ;
return F_35 ( - V_135 ) ;
}
V_2 = F_36 ( sizeof( * V_2 ) , V_132 ) ;
if ( ! V_2 ) {
F_32 ( V_11 ) ;
return F_35 ( - V_19 ) ;
}
#ifdef F_37
{
struct V_136 * V_137 ;
char V_138 [ 20 ] ;
sprintf ( V_138 , V_139 , V_11 ) ;
V_137 = F_38 ( V_138 , 0660 , NULL ,
& V_140 , V_2 ) ;
if ( ! V_137 ) {
F_39 ( V_2 ) ;
F_32 ( V_11 ) ;
return F_35 ( - V_141 ) ;
}
}
#endif
V_2 -> V_142 = V_11 ;
V_2 -> V_143 = 1 ;
V_2 -> V_78 = V_113 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_101 = V_101 ;
V_2 -> V_102 = V_102 ;
F_40 ( & V_2 -> V_144 ) ;
F_2 ( L_47 , V_24 , V_11 ) ;
return V_2 ;
}
void F_41 ( struct V_1 * V_2 )
{
int V_11 ;
F_2 ( L_48 , V_24 ) ;
if ( ! V_2 )
return;
V_11 = V_2 -> V_142 ;
#ifdef F_37
{
char V_138 [ 20 ] ;
sprintf ( V_138 , V_139 , V_11 ) ;
F_42 ( V_138 , NULL ) ;
}
#endif
F_39 ( V_2 ) ;
F_32 ( V_11 ) ;
}
int F_43 ( struct V_1 * V_2 , struct V_14 * V_22 ,
V_77 * V_145 )
{
F_2 ( L_48 , V_24 ) ;
if ( ! V_22 )
return - V_134 ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_45 = V_145 ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_39 ,
const char * V_41 )
{
F_2 ( L_48 , V_24 ) ;
if ( ! V_41 ) return - 1 ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_41 = V_41 ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 , T_1 V_28 , T_1 V_35 )
{
F_2 ( L_49 , V_24 , V_28 , V_35 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_35 = V_35 ;
return 0 ;
}
void F_46 ( struct V_146 * V_147 )
{
struct V_97 * V_148 ;
if ( ! V_147 )
return;
V_148 = F_47 ( V_147 , sizeof( * V_148 ) ) ;
memset ( V_148 , 0 , sizeof *V_148 ) ;
V_148 -> V_81 = F_4 ( V_149 ) ;
V_148 -> V_76 = F_4 ( V_147 -> V_150 ) ;
V_148 -> V_151 = F_4 ( 36 ) ;
V_148 -> V_152 = F_4 ( V_147 -> V_150 - sizeof( * V_148 ) ) ;
}
void F_21 ( struct V_1 * V_2 , T_2 * V_4 )
{
T_3 * V_6 , * V_153 ;
F_48 (r, n, &params->resp_queue, list) {
if ( V_6 -> V_4 == V_4 ) {
F_49 ( & V_6 -> V_154 ) ;
F_39 ( V_6 ) ;
}
}
}
T_2 * F_20 ( struct V_1 * V_2 , T_1 * V_9 )
{
T_3 * V_6 , * V_153 ;
if ( ! V_9 ) return NULL ;
F_48 (r, n, &params->resp_queue, list) {
if ( ! V_6 -> V_155 ) {
V_6 -> V_155 = 1 ;
* V_9 = V_6 -> V_9 ;
return V_6 -> V_4 ;
}
}
return NULL ;
}
static T_3 * F_14 ( struct V_1 * V_2 , T_1 V_9 )
{
T_3 * V_6 ;
V_6 = F_50 ( sizeof( T_3 ) + V_9 , V_156 ) ;
if ( ! V_6 ) return NULL ;
V_6 -> V_4 = ( T_2 * ) ( V_6 + 1 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_155 = 0 ;
F_51 ( & V_6 -> V_154 , & V_2 -> V_144 ) ;
return V_6 ;
}
int F_52 ( struct V_157 * V_158 ,
struct V_146 * V_147 ,
struct V_159 * V_154 )
{
T_4 * V_123 = ( void * ) V_147 -> V_160 ;
if ( F_4 ( V_149 )
!= F_53 ( V_123 ++ ) ) {
F_54 ( V_147 ) ;
return - V_134 ;
}
V_123 ++ ;
if ( ! F_55 ( V_147 , F_3 ( V_123 ++ ) + 8 ) ) {
F_54 ( V_147 ) ;
return - V_161 ;
}
F_56 ( V_147 , F_3 ( V_123 ++ ) ) ;
F_57 ( V_154 , V_147 ) ;
return 0 ;
}
static int F_58 ( struct V_162 * V_163 , void * V_102 )
{
V_1 * V_164 = V_163 -> V_165 ;
F_59 (m,
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57 ,
param->confignr, (param->used) ? L_58 : L_59 ,
({ char *s = L_60;
switch (param->state) {
case RNDIS_UNINITIALIZED:
s = L_61; break;
case RNDIS_INITIALIZED:
s = L_62; break;
case RNDIS_DATA_INITIALIZED:
s = L_63; break;
} s; }),
param->medium,
(param->media_state) ? 0 : param->speed*100 ,
(param->media_state) ? L_64 : L_65 ,
param->vendorID, param->vendorDescr) ;
return 0 ;
}
static T_16 F_60 ( struct V_166 * V_166 , const char T_17 * V_167 ,
T_18 V_12 , T_19 * V_168 )
{
V_1 * V_169 = F_61 ( F_62 ( V_166 ) ) ;
T_1 V_35 = 0 ;
int V_11 , V_170 = 0 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
char V_171 ;
if ( F_63 ( V_171 , V_167 ) )
return - V_172 ;
switch ( V_171 ) {
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
V_170 = 1 ;
V_35 = V_35 * 10 + V_171 - '0' ;
break;
case 'C' :
case 'c' :
F_24 ( V_169 ) ;
break;
case 'D' :
case 'd' :
F_25 ( V_169 ) ;
break;
default:
if ( V_170 ) V_169 -> V_35 = V_35 ;
else F_2 ( L_66 , V_171 ) ;
break;
}
V_167 ++ ;
}
return V_12 ;
}
static int F_64 ( struct V_173 * V_173 , struct V_166 * V_166 )
{
return F_65 ( V_166 , F_58 , F_61 ( V_173 ) ) ;
}
