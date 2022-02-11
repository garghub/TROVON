static inline int F_1 ( unsigned int V_1 ,
unsigned long * V_2 , unsigned int V_3 )
{
return V_1 <= V_3 && F_2 ( V_1 , V_2 ) ;
}
static int F_3 ( int V_4 , int V_5 , int V_6 )
{
if ( V_6 ) {
if ( V_4 > V_5 - V_6 / 2 && V_4 < V_5 + V_6 / 2 )
return V_5 ;
if ( V_4 > V_5 - V_6 && V_4 < V_5 + V_6 )
return ( V_5 * 3 + V_4 ) / 4 ;
if ( V_4 > V_5 - V_6 * 2 && V_4 < V_5 + V_6 * 2 )
return ( V_5 + V_4 ) / 2 ;
}
return V_4 ;
}
static void F_4 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
F_5 () ;
V_12 = F_6 ( V_8 -> V_13 ) ;
if ( V_12 )
V_12 -> V_10 -> V_14 ( V_12 , type , V_1 , V_4 ) ;
else {
bool V_15 = false ;
F_7 (handle, &dev->h_list, d_node) {
if ( ! V_12 -> V_16 )
continue;
V_10 = V_12 -> V_10 ;
if ( ! V_10 -> V_17 ) {
if ( V_15 )
break;
V_10 -> V_14 ( V_12 , type , V_1 , V_4 ) ;
} else if ( V_10 -> V_17 ( V_12 , type , V_1 , V_4 ) )
V_15 = true ;
}
}
F_8 () ;
}
static void F_9 ( unsigned long V_18 )
{
struct V_7 * V_8 = ( void * ) V_18 ;
unsigned long V_19 ;
F_10 ( & V_8 -> V_20 , V_19 ) ;
if ( F_2 ( V_8 -> V_21 , V_8 -> V_22 ) &&
F_1 ( V_8 -> V_21 , V_8 -> V_23 , V_24 ) ) {
F_4 ( V_8 , V_25 , V_8 -> V_21 , 2 ) ;
if ( V_8 -> V_26 ) {
F_4 ( V_8 , V_27 , V_28 , 1 ) ;
}
if ( V_8 -> V_29 [ V_30 ] )
F_11 ( & V_8 -> V_31 , V_32 +
F_12 ( V_8 -> V_29 [ V_30 ] ) ) ;
}
F_13 ( & V_8 -> V_20 , V_19 ) ;
}
static void F_14 ( struct V_7 * V_8 , int V_1 )
{
if ( F_2 ( V_33 , V_8 -> V_34 ) &&
V_8 -> V_29 [ V_30 ] && V_8 -> V_29 [ V_35 ] &&
V_8 -> V_31 . V_18 ) {
V_8 -> V_21 = V_1 ;
F_11 ( & V_8 -> V_31 ,
V_32 + F_12 ( V_8 -> V_29 [ V_35 ] ) ) ;
}
}
static void F_15 ( struct V_7 * V_8 )
{
F_16 ( & V_8 -> V_31 ) ;
}
static int F_17 ( struct V_7 * V_8 ,
unsigned int V_1 , int * V_36 )
{
bool V_37 ;
int * V_38 ;
if ( V_1 == V_39 ) {
if ( * V_36 >= 0 && * V_36 < V_8 -> V_40 )
V_8 -> V_41 = * V_36 ;
return V_42 ;
}
V_37 = F_18 ( V_1 ) ;
if ( ! V_37 ) {
V_38 = & V_8 -> V_43 [ V_1 ] . V_4 ;
} else if ( V_8 -> V_44 ) {
struct V_45 * V_46 = & V_8 -> V_44 [ V_8 -> V_41 ] ;
V_38 = & V_46 -> abs [ V_1 - V_47 ] ;
} else {
V_38 = NULL ;
}
if ( V_38 ) {
* V_36 = F_3 ( * V_36 , * V_38 ,
V_8 -> V_43 [ V_1 ] . V_6 ) ;
if ( * V_38 == * V_36 )
return V_42 ;
* V_38 = * V_36 ;
}
if ( V_37 && V_8 -> V_41 != F_19 ( V_8 , V_39 ) ) {
F_20 ( V_8 , V_39 , V_8 -> V_41 ) ;
F_4 ( V_8 , V_48 , V_39 , V_8 -> V_41 ) ;
}
return V_49 ;
}
static void F_21 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
int V_50 = V_42 ;
switch ( type ) {
case V_27 :
switch ( V_1 ) {
case V_51 :
V_50 = V_52 ;
break;
case V_28 :
if ( ! V_8 -> V_26 ) {
V_8 -> V_26 = true ;
V_50 = V_49 ;
}
break;
case V_53 :
V_8 -> V_26 = false ;
V_50 = V_49 ;
break;
}
break;
case V_25 :
if ( F_1 ( V_1 , V_8 -> V_23 , V_24 ) &&
! ! F_2 ( V_1 , V_8 -> V_22 ) != V_4 ) {
if ( V_4 != 2 ) {
F_22 ( V_1 , V_8 -> V_22 ) ;
if ( V_4 )
F_14 ( V_8 , V_1 ) ;
else
F_15 ( V_8 ) ;
}
V_50 = V_49 ;
}
break;
case V_54 :
if ( F_1 ( V_1 , V_8 -> V_55 , V_56 ) &&
! ! F_2 ( V_1 , V_8 -> V_57 ) != V_4 ) {
F_22 ( V_1 , V_8 -> V_57 ) ;
V_50 = V_49 ;
}
break;
case V_48 :
if ( F_1 ( V_1 , V_8 -> V_58 , V_59 ) )
V_50 = F_17 ( V_8 , V_1 , & V_4 ) ;
break;
case V_60 :
if ( F_1 ( V_1 , V_8 -> V_61 , V_62 ) && V_4 )
V_50 = V_49 ;
break;
case V_63 :
if ( F_1 ( V_1 , V_8 -> V_64 , V_65 ) )
V_50 = V_52 ;
break;
case V_66 :
if ( F_1 ( V_1 , V_8 -> V_67 , V_68 ) &&
! ! F_2 ( V_1 , V_8 -> V_69 ) != V_4 ) {
F_22 ( V_1 , V_8 -> V_69 ) ;
V_50 = V_52 ;
}
break;
case V_70 :
if ( F_1 ( V_1 , V_8 -> V_71 , V_72 ) ) {
if ( ! ! F_2 ( V_1 , V_8 -> V_73 ) != ! ! V_4 )
F_22 ( V_1 , V_8 -> V_73 ) ;
V_50 = V_52 ;
}
break;
case V_33 :
if ( V_1 <= V_74 && V_4 >= 0 && V_8 -> V_29 [ V_1 ] != V_4 ) {
V_8 -> V_29 [ V_1 ] = V_4 ;
V_50 = V_52 ;
}
break;
case V_75 :
if ( V_4 >= 0 )
V_50 = V_52 ;
break;
case V_76 :
V_50 = V_52 ;
break;
}
if ( V_50 != V_42 && type != V_27 )
V_8 -> V_26 = false ;
if ( ( V_50 & V_77 ) && V_8 -> V_14 )
V_8 -> V_14 ( V_8 , type , V_1 , V_4 ) ;
if ( V_50 & V_49 )
F_4 ( V_8 , type , V_1 , V_4 ) ;
}
void F_23 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
unsigned long V_19 ;
if ( F_1 ( type , V_8 -> V_34 , V_78 ) ) {
F_10 ( & V_8 -> V_20 , V_19 ) ;
F_24 ( type , V_1 , V_4 ) ;
F_21 ( V_8 , type , V_1 , V_4 ) ;
F_13 ( & V_8 -> V_20 , V_19 ) ;
}
}
void F_25 ( struct V_11 * V_12 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
struct V_11 * V_13 ;
unsigned long V_19 ;
if ( F_1 ( type , V_8 -> V_34 , V_78 ) ) {
F_10 ( & V_8 -> V_20 , V_19 ) ;
F_5 () ;
V_13 = F_6 ( V_8 -> V_13 ) ;
if ( ! V_13 || V_13 == V_12 )
F_21 ( V_8 , type , V_1 , V_4 ) ;
F_8 () ;
F_13 ( & V_8 -> V_20 , V_19 ) ;
}
}
void F_26 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_43 )
V_8 -> V_43 = F_27 ( V_79 , sizeof( struct V_80 ) ,
V_81 ) ;
F_28 ( ! V_8 -> V_43 , L_1 , V_82 ) ;
}
void F_29 ( struct V_7 * V_8 , unsigned int V_83 ,
int V_84 , int V_3 , int V_6 , int V_85 )
{
struct V_80 * V_43 ;
F_26 ( V_8 ) ;
if ( ! V_8 -> V_43 )
return;
V_43 = & V_8 -> V_43 [ V_83 ] ;
V_43 -> V_86 = V_84 ;
V_43 -> V_87 = V_3 ;
V_43 -> V_6 = V_6 ;
V_43 -> V_85 = V_85 ;
V_8 -> V_58 [ F_30 ( V_83 ) ] |= F_31 ( V_83 ) ;
}
int F_32 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
int V_88 ;
V_88 = F_33 ( & V_8 -> V_89 ) ;
if ( V_88 )
return V_88 ;
if ( V_8 -> V_13 ) {
V_88 = - V_90 ;
goto V_91;
}
F_34 ( V_8 -> V_13 , V_12 ) ;
V_91:
F_35 ( & V_8 -> V_89 ) ;
return V_88 ;
}
static void F_36 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
if ( V_8 -> V_13 == V_12 ) {
F_34 ( V_8 -> V_13 , NULL ) ;
F_37 () ;
F_38 (handle, &dev->h_list, d_node)
if ( V_12 -> V_16 && V_12 -> V_10 -> V_92 )
V_12 -> V_10 -> V_92 ( V_12 ) ;
}
}
void F_39 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
F_40 ( & V_8 -> V_89 ) ;
F_36 ( V_12 ) ;
F_35 ( & V_8 -> V_89 ) ;
}
int F_41 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
int V_88 ;
V_88 = F_33 ( & V_8 -> V_89 ) ;
if ( V_88 )
return V_88 ;
if ( V_8 -> V_93 ) {
V_88 = - V_94 ;
goto V_91;
}
V_12 -> V_16 ++ ;
if ( ! V_8 -> V_95 ++ && V_8 -> V_16 )
V_88 = V_8 -> V_16 ( V_8 ) ;
if ( V_88 ) {
V_8 -> V_95 -- ;
if ( ! -- V_12 -> V_16 ) {
F_37 () ;
}
}
V_91:
F_35 ( & V_8 -> V_89 ) ;
return V_88 ;
}
int F_42 ( struct V_11 * V_12 , struct V_96 * V_96 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
int V_88 ;
V_88 = F_33 ( & V_8 -> V_89 ) ;
if ( V_88 )
return V_88 ;
if ( V_8 -> V_97 )
V_88 = V_8 -> V_97 ( V_8 , V_96 ) ;
F_35 ( & V_8 -> V_89 ) ;
return V_88 ;
}
void F_43 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
F_40 ( & V_8 -> V_89 ) ;
F_36 ( V_12 ) ;
if ( ! -- V_8 -> V_95 && V_8 -> V_98 )
V_8 -> V_98 ( V_8 ) ;
if ( ! -- V_12 -> V_16 ) {
F_37 () ;
}
F_35 ( & V_8 -> V_89 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
int V_1 ;
if ( F_1 ( V_25 , V_8 -> V_34 , V_78 ) ) {
for ( V_1 = 0 ; V_1 <= V_24 ; V_1 ++ ) {
if ( F_1 ( V_1 , V_8 -> V_23 , V_24 ) &&
F_45 ( V_1 , V_8 -> V_22 ) ) {
F_4 ( V_8 , V_25 , V_1 , 0 ) ;
}
}
F_4 ( V_8 , V_27 , V_28 , 1 ) ;
}
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
F_40 ( & V_8 -> V_89 ) ;
V_8 -> V_93 = true ;
F_35 ( & V_8 -> V_89 ) ;
F_47 ( & V_8 -> V_20 ) ;
F_44 ( V_8 ) ;
F_38 (handle, &dev->h_list, d_node)
V_12 -> V_16 = 0 ;
F_48 ( & V_8 -> V_20 ) ;
}
int F_49 ( const struct V_99 * V_100 ,
unsigned int * V_101 )
{
switch ( V_100 -> V_102 ) {
case 1 :
* V_101 = * ( ( V_103 * ) V_100 -> V_101 ) ;
break;
case 2 :
* V_101 = * ( ( V_104 * ) V_100 -> V_101 ) ;
break;
case 4 :
* V_101 = * ( ( V_105 * ) V_100 -> V_101 ) ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static unsigned int F_50 ( struct V_7 * V_8 ,
unsigned int V_107 )
{
switch ( V_8 -> V_108 ) {
case 1 :
return ( ( V_103 * ) V_8 -> V_109 ) [ V_107 ] ;
case 2 :
return ( ( V_104 * ) V_8 -> V_109 ) [ V_107 ] ;
default:
return ( ( V_105 * ) V_8 -> V_109 ) [ V_107 ] ;
}
}
static int F_51 ( struct V_7 * V_8 ,
struct V_99 * V_100 )
{
unsigned int V_107 ;
int error ;
if ( ! V_8 -> V_108 )
return - V_106 ;
if ( V_100 -> V_19 & V_110 )
V_107 = V_100 -> V_107 ;
else {
error = F_49 ( V_100 , & V_107 ) ;
if ( error )
return error ;
}
if ( V_107 >= V_8 -> V_111 )
return - V_106 ;
V_100 -> V_109 = F_50 ( V_8 , V_107 ) ;
V_100 -> V_107 = V_107 ;
V_100 -> V_102 = sizeof( V_107 ) ;
memcpy ( V_100 -> V_101 , & V_107 , sizeof( V_107 ) ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 ,
const struct V_99 * V_100 ,
unsigned int * V_112 )
{
unsigned int V_107 ;
int error ;
int V_113 ;
if ( ! V_8 -> V_108 )
return - V_106 ;
if ( V_100 -> V_19 & V_110 ) {
V_107 = V_100 -> V_107 ;
} else {
error = F_49 ( V_100 , & V_107 ) ;
if ( error )
return error ;
}
if ( V_107 >= V_8 -> V_111 )
return - V_106 ;
if ( V_8 -> V_108 < sizeof( V_100 -> V_109 ) &&
( V_100 -> V_109 >> ( V_8 -> V_108 * 8 ) ) )
return - V_106 ;
switch ( V_8 -> V_108 ) {
case 1 : {
V_103 * V_114 = ( V_103 * ) V_8 -> V_109 ;
* V_112 = V_114 [ V_107 ] ;
V_114 [ V_107 ] = V_100 -> V_109 ;
break;
}
case 2 : {
V_104 * V_114 = ( V_104 * ) V_8 -> V_109 ;
* V_112 = V_114 [ V_107 ] ;
V_114 [ V_107 ] = V_100 -> V_109 ;
break;
}
default: {
V_105 * V_114 = ( V_105 * ) V_8 -> V_109 ;
* V_112 = V_114 [ V_107 ] ;
V_114 [ V_107 ] = V_100 -> V_109 ;
break;
}
}
F_53 ( * V_112 , V_8 -> V_23 ) ;
F_54 ( V_100 -> V_109 , V_8 -> V_23 ) ;
for ( V_113 = 0 ; V_113 < V_8 -> V_111 ; V_113 ++ ) {
if ( F_50 ( V_8 , V_113 ) == * V_112 ) {
F_54 ( * V_112 , V_8 -> V_23 ) ;
break;
}
}
return 0 ;
}
int F_55 ( struct V_7 * V_8 , struct V_99 * V_100 )
{
unsigned long V_19 ;
int V_88 ;
F_10 ( & V_8 -> V_20 , V_19 ) ;
V_88 = V_8 -> V_115 ( V_8 , V_100 ) ;
F_13 ( & V_8 -> V_20 , V_19 ) ;
return V_88 ;
}
int F_56 ( struct V_7 * V_8 ,
const struct V_99 * V_100 )
{
unsigned long V_19 ;
unsigned int V_112 ;
int V_88 ;
if ( V_100 -> V_109 > V_24 )
return - V_106 ;
F_10 ( & V_8 -> V_20 , V_19 ) ;
V_88 = V_8 -> V_116 ( V_8 , V_100 , & V_112 ) ;
if ( V_88 )
goto V_91;
F_53 ( V_117 , V_8 -> V_23 ) ;
if ( F_2 ( V_25 , V_8 -> V_34 ) &&
! F_1 ( V_112 , V_8 -> V_23 , V_24 ) &&
F_45 ( V_112 , V_8 -> V_22 ) ) {
F_4 ( V_8 , V_25 , V_112 , 0 ) ;
if ( V_8 -> V_26 )
F_4 ( V_8 , V_27 , V_28 , 1 ) ;
}
V_91:
F_13 ( & V_8 -> V_20 , V_19 ) ;
return V_88 ;
}
static const struct V_118 * F_57 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
const struct V_118 * V_119 ;
int V_113 ;
for ( V_119 = V_10 -> V_120 ; V_119 -> V_19 || V_119 -> V_121 ; V_119 ++ ) {
if ( V_119 -> V_19 & V_122 )
if ( V_119 -> V_123 != V_8 -> V_119 . V_123 )
continue;
if ( V_119 -> V_19 & V_124 )
if ( V_119 -> V_125 != V_8 -> V_119 . V_125 )
continue;
if ( V_119 -> V_19 & V_126 )
if ( V_119 -> V_127 != V_8 -> V_119 . V_127 )
continue;
if ( V_119 -> V_19 & V_128 )
if ( V_119 -> V_129 != V_8 -> V_119 . V_129 )
continue;
F_58 ( V_34 , V_78 ) ;
F_58 ( V_23 , V_24 ) ;
F_58 ( V_61 , V_62 ) ;
F_58 ( V_58 , V_59 ) ;
F_58 ( V_64 , V_65 ) ;
F_58 ( V_67 , V_68 ) ;
F_58 ( V_71 , V_72 ) ;
F_58 ( V_130 , V_131 ) ;
F_58 ( V_55 , V_56 ) ;
if ( ! V_10 -> V_132 || V_10 -> V_132 ( V_10 , V_8 ) )
return V_119 ;
}
return NULL ;
}
static int F_59 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
const struct V_118 * V_119 ;
int error ;
V_119 = F_57 ( V_10 , V_8 ) ;
if ( ! V_119 )
return - V_94 ;
error = V_10 -> V_133 ( V_10 , V_8 , V_119 ) ;
if ( error && error != - V_94 )
F_60 ( L_2 ,
V_10 -> V_134 , F_61 ( & V_8 -> V_8 . V_135 ) , error ) ;
return error ;
}
static int F_62 ( char * V_136 , int V_137 ,
unsigned long V_138 , bool V_139 )
{
int V_102 = 0 ;
if ( V_140 ) {
V_105 V_141 = V_138 >> 32 ;
if ( V_141 || ! V_139 )
V_102 += snprintf ( V_136 , V_137 , L_3 , V_141 ) ;
V_141 = V_138 & 0xffffffffUL ;
if ( V_141 || ! V_139 || V_102 )
V_102 += snprintf ( V_136 + V_102 , V_3 ( V_137 - V_102 , 0 ) ,
L_4 , V_141 ) ;
} else {
if ( V_138 || ! V_139 )
V_102 += snprintf ( V_136 , V_137 , L_5 , V_138 ) ;
}
return V_102 ;
}
static int F_62 ( char * V_136 , int V_137 ,
unsigned long V_138 , bool V_139 )
{
return V_138 || ! V_139 ?
snprintf ( V_136 , V_137 , L_5 , V_138 ) : 0 ;
}
static inline void F_63 ( void )
{
V_142 ++ ;
F_64 ( & V_143 ) ;
}
static unsigned int F_65 ( struct V_96 * V_96 , T_1 * V_144 )
{
F_66 ( V_96 , & V_143 , V_144 ) ;
if ( V_96 -> V_145 != V_142 ) {
V_96 -> V_145 = V_142 ;
return V_146 | V_147 ;
}
return 0 ;
}
static void * F_67 ( struct V_148 * V_149 , T_2 * V_150 )
{
union V_151 * V_152 = (union V_151 * ) & V_149 -> V_153 ;
int error ;
F_68 ( sizeof( union V_151 ) != sizeof( V_149 -> V_153 ) ) ;
error = F_33 ( & V_154 ) ;
if ( error ) {
V_152 -> V_155 = false ;
return F_69 ( error ) ;
}
V_152 -> V_155 = true ;
return F_70 ( & V_156 , * V_150 ) ;
}
static void * F_71 ( struct V_148 * V_149 , void * V_157 , T_2 * V_150 )
{
return F_72 ( V_157 , & V_156 , V_150 ) ;
}
static void F_73 ( struct V_148 * V_149 , void * V_157 )
{
union V_151 * V_152 = (union V_151 * ) & V_149 -> V_153 ;
if ( V_152 -> V_155 )
F_35 ( & V_154 ) ;
}
static void F_74 ( struct V_148 * V_149 , const char * V_134 ,
unsigned long * V_158 , int V_3 )
{
int V_113 ;
bool V_139 = true ;
char V_136 [ 18 ] ;
F_75 ( V_149 , L_6 , V_134 ) ;
for ( V_113 = F_76 ( V_3 ) - 1 ; V_113 >= 0 ; V_113 -- ) {
if ( F_62 ( V_136 , sizeof( V_136 ) ,
V_158 [ V_113 ] , V_139 ) ) {
V_139 = false ;
F_75 ( V_149 , L_7 , V_136 , V_113 > 0 ? L_8 : L_9 ) ;
}
}
if ( V_139 )
F_77 ( V_149 , L_10 ) ;
F_78 ( V_149 , '\n' ) ;
}
static int F_79 ( struct V_148 * V_149 , void * V_157 )
{
struct V_7 * V_8 = F_80 ( V_157 , struct V_7 , V_159 ) ;
const char * V_160 = F_81 ( & V_8 -> V_8 . V_135 , V_81 ) ;
struct V_11 * V_12 ;
F_75 ( V_149 , L_11 ,
V_8 -> V_119 . V_123 , V_8 -> V_119 . V_125 , V_8 -> V_119 . V_127 , V_8 -> V_119 . V_129 ) ;
F_75 ( V_149 , L_12 , V_8 -> V_134 ? V_8 -> V_134 : L_9 ) ;
F_75 ( V_149 , L_13 , V_8 -> V_161 ? V_8 -> V_161 : L_9 ) ;
F_75 ( V_149 , L_14 , V_160 ? V_160 : L_9 ) ;
F_75 ( V_149 , L_15 , V_8 -> V_162 ? V_8 -> V_162 : L_9 ) ;
F_75 ( V_149 , L_16 ) ;
F_38 (handle, &dev->h_list, d_node)
F_75 ( V_149 , L_17 , V_12 -> V_134 ) ;
F_78 ( V_149 , '\n' ) ;
F_74 ( V_149 , L_18 , V_8 -> V_163 , V_164 ) ;
F_74 ( V_149 , L_19 , V_8 -> V_34 , V_78 ) ;
if ( F_2 ( V_25 , V_8 -> V_34 ) )
F_74 ( V_149 , L_20 , V_8 -> V_23 , V_24 ) ;
if ( F_2 ( V_60 , V_8 -> V_34 ) )
F_74 ( V_149 , L_21 , V_8 -> V_61 , V_62 ) ;
if ( F_2 ( V_48 , V_8 -> V_34 ) )
F_74 ( V_149 , L_22 , V_8 -> V_58 , V_59 ) ;
if ( F_2 ( V_63 , V_8 -> V_34 ) )
F_74 ( V_149 , L_23 , V_8 -> V_64 , V_65 ) ;
if ( F_2 ( V_66 , V_8 -> V_34 ) )
F_74 ( V_149 , L_24 , V_8 -> V_67 , V_68 ) ;
if ( F_2 ( V_70 , V_8 -> V_34 ) )
F_74 ( V_149 , L_25 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_75 , V_8 -> V_34 ) )
F_74 ( V_149 , L_26 , V_8 -> V_130 , V_131 ) ;
if ( F_2 ( V_54 , V_8 -> V_34 ) )
F_74 ( V_149 , L_27 , V_8 -> V_55 , V_56 ) ;
F_78 ( V_149 , '\n' ) ;
F_82 ( V_160 ) ;
return 0 ;
}
static int F_83 ( struct V_165 * V_165 , struct V_96 * V_96 )
{
return F_84 ( V_96 , & V_166 ) ;
}
static void * F_85 ( struct V_148 * V_149 , T_2 * V_150 )
{
union V_151 * V_152 = (union V_151 * ) & V_149 -> V_153 ;
int error ;
F_68 ( sizeof( union V_151 ) != sizeof( V_149 -> V_153 ) ) ;
error = F_33 ( & V_154 ) ;
if ( error ) {
V_152 -> V_155 = false ;
return F_69 ( error ) ;
}
V_152 -> V_155 = true ;
V_152 -> V_150 = * V_150 ;
return F_70 ( & V_167 , * V_150 ) ;
}
static void * F_86 ( struct V_148 * V_149 , void * V_157 , T_2 * V_150 )
{
union V_151 * V_152 = (union V_151 * ) & V_149 -> V_153 ;
V_152 -> V_150 = * V_150 + 1 ;
return F_72 ( V_157 , & V_167 , V_150 ) ;
}
static int F_87 ( struct V_148 * V_149 , void * V_157 )
{
struct V_9 * V_10 = F_80 ( V_157 , struct V_9 , V_159 ) ;
union V_151 * V_152 = (union V_151 * ) & V_149 -> V_153 ;
F_75 ( V_149 , L_28 , V_152 -> V_150 , V_10 -> V_134 ) ;
if ( V_10 -> V_17 )
F_77 ( V_149 , L_29 ) ;
if ( V_10 -> V_168 )
F_75 ( V_149 , L_30 , V_10 -> V_169 ) ;
F_78 ( V_149 , '\n' ) ;
return 0 ;
}
static int F_88 ( struct V_165 * V_165 , struct V_96 * V_96 )
{
return F_84 ( V_96 , & V_170 ) ;
}
static int T_3 F_89 ( void )
{
struct V_171 * V_172 ;
V_173 = F_90 ( L_31 , NULL ) ;
if ( ! V_173 )
return - V_174 ;
V_172 = F_91 ( L_32 , 0 , V_173 ,
& V_175 ) ;
if ( ! V_172 )
goto V_176;
V_172 = F_91 ( L_33 , 0 , V_173 ,
& V_177 ) ;
if ( ! V_172 )
goto V_178;
return 0 ;
V_178: F_92 ( L_32 , V_173 ) ;
V_176: F_92 ( L_31 , NULL ) ;
return - V_174 ;
}
static void F_93 ( void )
{
F_92 ( L_32 , V_173 ) ;
F_92 ( L_33 , V_173 ) ;
F_92 ( L_31 , NULL ) ;
}
static inline void F_63 ( void ) { }
static inline int F_89 ( void ) { return 0 ; }
static inline void F_93 ( void ) { }
static int F_94 ( char * V_136 , int V_179 ,
char V_134 , unsigned long * V_2 ,
unsigned int V_180 , unsigned int V_181 )
{
int V_102 = 0 , V_113 ;
V_102 += snprintf ( V_136 , V_3 ( V_179 , 0 ) , L_34 , V_134 ) ;
for ( V_113 = V_180 ; V_113 < V_181 ; V_113 ++ )
if ( V_2 [ F_30 ( V_113 ) ] & F_31 ( V_113 ) )
V_102 += snprintf ( V_136 + V_102 , V_3 ( V_179 - V_102 , 0 ) , L_35 , V_113 ) ;
return V_102 ;
}
static int F_95 ( char * V_136 , int V_179 , struct V_7 * V_119 ,
int V_182 )
{
int V_102 ;
V_102 = snprintf ( V_136 , V_3 ( V_179 , 0 ) ,
L_36 ,
V_119 -> V_119 . V_123 , V_119 -> V_119 . V_125 ,
V_119 -> V_119 . V_127 , V_119 -> V_119 . V_129 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'e' , V_119 -> V_34 , 0 , V_78 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'k' , V_119 -> V_23 , V_183 , V_24 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'r' , V_119 -> V_61 , 0 , V_62 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'a' , V_119 -> V_58 , 0 , V_59 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'm' , V_119 -> V_64 , 0 , V_65 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'l' , V_119 -> V_67 , 0 , V_68 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
's' , V_119 -> V_71 , 0 , V_72 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'f' , V_119 -> V_130 , 0 , V_131 ) ;
V_102 += F_94 ( V_136 + V_102 , V_179 - V_102 ,
'w' , V_119 -> V_55 , 0 , V_56 ) ;
if ( V_182 )
V_102 += snprintf ( V_136 + V_102 , V_3 ( V_179 - V_102 , 0 ) , L_37 ) ;
return V_102 ;
}
static T_4 F_96 ( struct V_184 * V_8 ,
struct V_185 * V_186 ,
char * V_136 )
{
struct V_7 * V_119 = F_97 ( V_8 ) ;
T_4 V_102 ;
V_102 = F_95 ( V_136 , V_187 , V_119 , 1 ) ;
return F_98 ( int , V_102 , V_187 ) ;
}
static T_4 F_99 ( struct V_184 * V_8 ,
struct V_185 * V_186 ,
char * V_136 )
{
struct V_7 * V_7 = F_97 ( V_8 ) ;
int V_102 = F_100 ( V_136 , V_187 , V_7 -> V_163 ,
V_164 , true ) ;
return F_98 ( int , V_102 , V_187 ) ;
}
static int F_100 ( char * V_136 , int V_137 , unsigned long * V_158 ,
int V_3 , int V_182 )
{
int V_113 ;
int V_102 = 0 ;
bool V_139 = true ;
for ( V_113 = F_76 ( V_3 ) - 1 ; V_113 >= 0 ; V_113 -- ) {
V_102 += F_62 ( V_136 + V_102 , V_3 ( V_137 - V_102 , 0 ) ,
V_158 [ V_113 ] , V_139 ) ;
if ( V_102 ) {
V_139 = false ;
if ( V_113 > 0 )
V_102 += snprintf ( V_136 + V_102 , V_3 ( V_137 - V_102 , 0 ) , L_8 ) ;
}
}
if ( V_102 == 0 )
V_102 = snprintf ( V_136 , V_137 , L_38 , 0 ) ;
if ( V_182 )
V_102 += snprintf ( V_136 + V_102 , V_3 ( V_137 - V_102 , 0 ) , L_37 ) ;
return V_102 ;
}
static void F_101 ( struct V_184 * V_184 )
{
struct V_7 * V_8 = F_97 ( V_184 ) ;
F_102 ( V_8 ) ;
F_103 ( V_8 ) ;
F_82 ( V_8 -> V_43 ) ;
F_82 ( V_8 ) ;
F_104 ( V_188 ) ;
}
static int F_105 ( struct V_189 * V_190 ,
const char * V_134 , unsigned long * V_158 , int V_3 )
{
int V_102 ;
if ( F_106 ( V_190 , L_39 , V_134 ) )
return - V_174 ;
V_102 = F_100 ( & V_190 -> V_136 [ V_190 -> V_191 - 1 ] ,
sizeof( V_190 -> V_136 ) - V_190 -> V_191 ,
V_158 , V_3 , false ) ;
if ( V_102 >= ( sizeof( V_190 -> V_136 ) - V_190 -> V_191 ) )
return - V_174 ;
V_190 -> V_191 += V_102 ;
return 0 ;
}
static int F_107 ( struct V_189 * V_190 ,
struct V_7 * V_8 )
{
int V_102 ;
if ( F_106 ( V_190 , L_40 ) )
return - V_174 ;
V_102 = F_95 ( & V_190 -> V_136 [ V_190 -> V_191 - 1 ] ,
sizeof( V_190 -> V_136 ) - V_190 -> V_191 ,
V_8 , 0 ) ;
if ( V_102 >= ( sizeof( V_190 -> V_136 ) - V_190 -> V_191 ) )
return - V_174 ;
V_190 -> V_191 += V_102 ;
return 0 ;
}
static int F_108 ( struct V_184 * V_184 , struct V_189 * V_190 )
{
struct V_7 * V_8 = F_97 ( V_184 ) ;
F_109 ( L_41 ,
V_8 -> V_119 . V_123 , V_8 -> V_119 . V_125 ,
V_8 -> V_119 . V_127 , V_8 -> V_119 . V_129 ) ;
if ( V_8 -> V_134 )
F_109 ( L_42 , V_8 -> V_134 ) ;
if ( V_8 -> V_161 )
F_109 ( L_43 , V_8 -> V_161 ) ;
if ( V_8 -> V_162 )
F_109 ( L_44 , V_8 -> V_162 ) ;
F_110 ( L_45 , V_8 -> V_163 , V_164 ) ;
F_110 ( L_46 , V_8 -> V_34 , V_78 ) ;
if ( F_2 ( V_25 , V_8 -> V_34 ) )
F_110 ( L_47 , V_8 -> V_23 , V_24 ) ;
if ( F_2 ( V_60 , V_8 -> V_34 ) )
F_110 ( L_48 , V_8 -> V_61 , V_62 ) ;
if ( F_2 ( V_48 , V_8 -> V_34 ) )
F_110 ( L_49 , V_8 -> V_58 , V_59 ) ;
if ( F_2 ( V_63 , V_8 -> V_34 ) )
F_110 ( L_50 , V_8 -> V_64 , V_65 ) ;
if ( F_2 ( V_66 , V_8 -> V_34 ) )
F_110 ( L_51 , V_8 -> V_67 , V_68 ) ;
if ( F_2 ( V_70 , V_8 -> V_34 ) )
F_110 ( L_52 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_75 , V_8 -> V_34 ) )
F_110 ( L_53 , V_8 -> V_130 , V_131 ) ;
if ( F_2 ( V_54 , V_8 -> V_34 ) )
F_110 ( L_54 , V_8 -> V_55 , V_56 ) ;
F_111 ( V_8 ) ;
return 0 ;
}
static void F_112 ( struct V_7 * V_8 , bool V_192 )
{
if ( ! V_8 -> V_14 )
return;
F_113 ( V_8 , V_193 , V_69 , V_192 ) ;
F_113 ( V_8 , V_194 , V_73 , V_192 ) ;
if ( V_192 && F_2 ( V_33 , V_8 -> V_34 ) ) {
V_8 -> V_14 ( V_8 , V_33 , V_30 , V_8 -> V_29 [ V_30 ] ) ;
V_8 -> V_14 ( V_8 , V_33 , V_35 , V_8 -> V_29 [ V_35 ] ) ;
}
}
void F_114 ( struct V_7 * V_8 )
{
F_40 ( & V_8 -> V_89 ) ;
if ( V_8 -> V_95 ) {
F_112 ( V_8 , true ) ;
F_47 ( & V_8 -> V_20 ) ;
F_44 ( V_8 ) ;
F_48 ( & V_8 -> V_20 ) ;
}
F_35 ( & V_8 -> V_89 ) ;
}
static int F_115 ( struct V_184 * V_8 )
{
struct V_7 * V_7 = F_97 ( V_8 ) ;
F_40 ( & V_7 -> V_89 ) ;
if ( V_7 -> V_95 )
F_112 ( V_7 , false ) ;
F_35 ( & V_7 -> V_89 ) ;
return 0 ;
}
static int F_116 ( struct V_184 * V_8 )
{
struct V_7 * V_7 = F_97 ( V_8 ) ;
F_114 ( V_7 ) ;
return 0 ;
}
static char * F_117 ( struct V_184 * V_8 , T_5 * V_195 )
{
return F_118 ( V_81 , L_55 , F_119 ( V_8 ) ) ;
}
struct V_7 * F_120 ( void )
{
struct V_7 * V_8 ;
V_8 = F_121 ( sizeof( struct V_7 ) , V_81 ) ;
if ( V_8 ) {
V_8 -> V_8 . type = & V_196 ;
V_8 -> V_8 . V_197 = & V_198 ;
F_122 ( & V_8 -> V_8 ) ;
F_123 ( & V_8 -> V_89 ) ;
F_124 ( & V_8 -> V_20 ) ;
F_125 ( & V_8 -> V_199 ) ;
F_125 ( & V_8 -> V_159 ) ;
F_126 ( V_188 ) ;
}
return V_8 ;
}
void F_127 ( struct V_7 * V_8 )
{
if ( V_8 )
F_128 ( V_8 ) ;
}
void F_129 ( struct V_7 * V_8 , unsigned int type , unsigned int V_1 )
{
switch ( type ) {
case V_25 :
F_54 ( V_1 , V_8 -> V_23 ) ;
break;
case V_60 :
F_54 ( V_1 , V_8 -> V_61 ) ;
break;
case V_48 :
F_54 ( V_1 , V_8 -> V_58 ) ;
break;
case V_63 :
F_54 ( V_1 , V_8 -> V_64 ) ;
break;
case V_54 :
F_54 ( V_1 , V_8 -> V_55 ) ;
break;
case V_66 :
F_54 ( V_1 , V_8 -> V_67 ) ;
break;
case V_70 :
F_54 ( V_1 , V_8 -> V_71 ) ;
break;
case V_75 :
F_54 ( V_1 , V_8 -> V_130 ) ;
break;
case V_76 :
break;
default:
F_60 ( L_56 ,
type , V_1 ) ;
F_130 () ;
return;
}
F_54 ( type , V_8 -> V_34 ) ;
}
static unsigned int F_131 ( struct V_7 * V_8 )
{
int V_200 ;
int V_113 ;
unsigned int V_201 ;
if ( V_8 -> V_40 ) {
V_200 = V_8 -> V_40 ;
} else if ( F_2 ( V_202 , V_8 -> V_58 ) ) {
V_200 = V_8 -> V_43 [ V_202 ] . V_87 -
V_8 -> V_43 [ V_202 ] . V_86 + 1 ,
V_200 = F_132 ( V_200 , 2 , 32 ) ;
} else if ( F_2 ( V_203 , V_8 -> V_58 ) ) {
V_200 = 2 ;
} else {
V_200 = 0 ;
}
V_201 = V_200 + 1 ;
for ( V_113 = 0 ; V_113 < V_79 ; V_113 ++ ) {
if ( F_2 ( V_113 , V_8 -> V_58 ) ) {
if ( F_133 ( V_113 ) )
V_201 += V_200 ;
else
V_201 ++ ;
}
}
for ( V_113 = 0 ; V_113 < V_204 ; V_113 ++ )
if ( F_2 ( V_113 , V_8 -> V_61 ) )
V_201 ++ ;
return V_201 ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_135 ( V_8 , V_205 , V_22 ) ;
F_135 ( V_8 , V_206 , V_207 ) ;
F_135 ( V_8 , ABS , abs ) ;
F_135 ( V_8 , V_208 , V_209 ) ;
F_135 ( V_8 , V_193 , V_69 ) ;
F_135 ( V_8 , V_194 , V_73 ) ;
F_135 ( V_8 , V_210 , V_211 ) ;
F_135 ( V_8 , V_212 , V_57 ) ;
}
int F_136 ( struct V_7 * V_8 )
{
static T_6 V_213 = F_137 ( 0 ) ;
struct V_9 * V_10 ;
const char * V_160 ;
int error ;
F_54 ( V_27 , V_8 -> V_34 ) ;
F_53 ( V_117 , V_8 -> V_23 ) ;
F_134 ( V_8 ) ;
if ( ! V_8 -> V_214 )
V_8 -> V_214 =
F_131 ( V_8 ) ;
F_138 ( & V_8 -> V_31 ) ;
if ( ! V_8 -> V_29 [ V_35 ] && ! V_8 -> V_29 [ V_30 ] ) {
V_8 -> V_31 . V_18 = ( long ) V_8 ;
V_8 -> V_31 . V_215 = F_9 ;
V_8 -> V_29 [ V_35 ] = 250 ;
V_8 -> V_29 [ V_30 ] = 33 ;
}
if ( ! V_8 -> V_115 )
V_8 -> V_115 = F_51 ;
if ( ! V_8 -> V_116 )
V_8 -> V_116 = F_52 ;
F_139 ( & V_8 -> V_8 , L_57 ,
( unsigned long ) F_140 ( & V_213 ) - 1 ) ;
error = F_141 ( & V_8 -> V_8 ) ;
if ( error )
return error ;
V_160 = F_81 ( & V_8 -> V_8 . V_135 , V_81 ) ;
F_142 ( L_58 ,
V_8 -> V_134 ? V_8 -> V_134 : L_59 ,
V_160 ? V_160 : L_60 ) ;
F_82 ( V_160 ) ;
error = F_33 ( & V_154 ) ;
if ( error ) {
F_143 ( & V_8 -> V_8 ) ;
return error ;
}
F_144 ( & V_8 -> V_159 , & V_156 ) ;
F_38 (handler, &input_handler_list, node)
F_59 ( V_8 , V_10 ) ;
F_63 () ;
F_35 ( & V_154 ) ;
return 0 ;
}
void F_145 ( struct V_7 * V_8 )
{
struct V_11 * V_12 , * V_216 ;
F_46 ( V_8 ) ;
F_40 ( & V_154 ) ;
F_146 (handle, next, &dev->h_list, d_node)
V_12 -> V_10 -> V_217 ( V_12 ) ;
F_147 ( ! F_148 ( & V_8 -> V_199 ) ) ;
F_149 ( & V_8 -> V_31 ) ;
F_150 ( & V_8 -> V_159 ) ;
F_63 () ;
F_35 ( & V_154 ) ;
F_151 ( & V_8 -> V_8 ) ;
}
int F_152 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
int V_88 ;
V_88 = F_33 ( & V_154 ) ;
if ( V_88 )
return V_88 ;
F_125 ( & V_10 -> V_199 ) ;
if ( V_10 -> V_168 != NULL ) {
if ( V_218 [ V_10 -> V_169 >> 5 ] ) {
V_88 = - V_90 ;
goto V_91;
}
V_218 [ V_10 -> V_169 >> 5 ] = V_10 ;
}
F_144 ( & V_10 -> V_159 , & V_167 ) ;
F_38 (dev, &input_dev_list, node)
F_59 ( V_8 , V_10 ) ;
F_63 () ;
V_91:
F_35 ( & V_154 ) ;
return V_88 ;
}
void F_153 ( struct V_9 * V_10 )
{
struct V_11 * V_12 , * V_216 ;
F_40 ( & V_154 ) ;
F_146 (handle, next, &handler->h_list, h_node)
V_10 -> V_217 ( V_12 ) ;
F_147 ( ! F_148 ( & V_10 -> V_199 ) ) ;
F_150 ( & V_10 -> V_159 ) ;
if ( V_10 -> V_168 != NULL )
V_218 [ V_10 -> V_169 >> 5 ] = NULL ;
F_63 () ;
F_35 ( & V_154 ) ;
}
int F_154 ( struct V_9 * V_10 , void * V_18 ,
int (* F_155)( struct V_11 * , void * ) )
{
struct V_11 * V_12 ;
int V_88 = 0 ;
F_5 () ;
F_7 (handle, &handler->h_list, h_node) {
V_88 = F_155 ( V_12 , V_18 ) ;
if ( V_88 )
break;
}
F_8 () ;
return V_88 ;
}
int F_156 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_7 * V_8 = V_12 -> V_8 ;
int error ;
error = F_33 ( & V_8 -> V_89 ) ;
if ( error )
return error ;
if ( V_10 -> V_17 )
F_157 ( & V_12 -> V_219 , & V_8 -> V_199 ) ;
else
F_158 ( & V_12 -> V_219 , & V_8 -> V_199 ) ;
F_35 ( & V_8 -> V_89 ) ;
F_158 ( & V_12 -> V_220 , & V_10 -> V_199 ) ;
if ( V_10 -> V_92 )
V_10 -> V_92 ( V_12 ) ;
return 0 ;
}
void F_159 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
F_160 ( & V_12 -> V_220 ) ;
F_40 ( & V_8 -> V_89 ) ;
F_160 ( & V_12 -> V_219 ) ;
F_35 ( & V_8 -> V_89 ) ;
F_37 () ;
}
static int F_161 ( struct V_165 * V_165 , struct V_96 * V_96 )
{
struct V_9 * V_10 ;
const struct V_221 * V_222 , * V_223 = NULL ;
int V_224 ;
V_224 = F_33 ( & V_154 ) ;
if ( V_224 )
return V_224 ;
V_10 = V_218 [ F_162 ( V_165 ) >> 5 ] ;
if ( V_10 )
V_223 = F_163 ( V_10 -> V_168 ) ;
F_35 ( & V_154 ) ;
if ( ! V_223 || ! V_223 -> V_16 ) {
F_164 ( V_223 ) ;
V_224 = - V_94 ;
goto V_91;
}
V_222 = V_96 -> V_225 ;
V_96 -> V_225 = V_223 ;
V_224 = V_223 -> V_16 ( V_165 , V_96 ) ;
if ( V_224 ) {
F_164 ( V_96 -> V_225 ) ;
V_96 -> V_225 = F_163 ( V_222 ) ;
}
F_164 ( V_222 ) ;
V_91:
return V_224 ;
}
static int T_3 F_165 ( void )
{
int V_224 ;
V_224 = F_166 ( & V_198 ) ;
if ( V_224 ) {
F_60 ( L_61 ) ;
return V_224 ;
}
V_224 = F_89 () ;
if ( V_224 )
goto V_176;
V_224 = F_167 ( V_226 , L_62 , & V_227 ) ;
if ( V_224 ) {
F_60 ( L_63 , V_226 ) ;
goto V_178;
}
return 0 ;
V_178: F_93 () ;
V_176: F_168 ( & V_198 ) ;
return V_224 ;
}
static void T_7 F_169 ( void )
{
F_93 () ;
F_170 ( V_226 , L_62 ) ;
F_168 ( & V_198 ) ;
}
