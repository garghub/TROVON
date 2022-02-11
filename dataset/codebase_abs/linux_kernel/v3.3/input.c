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
V_37 = V_1 >= V_43 && V_1 <= V_44 ;
if ( ! V_37 ) {
V_38 = & V_8 -> V_45 [ V_1 ] . V_4 ;
} else if ( V_8 -> V_46 ) {
struct V_47 * V_48 = & V_8 -> V_46 [ V_8 -> V_41 ] ;
V_38 = & V_48 -> abs [ V_1 - V_43 ] ;
} else {
V_38 = NULL ;
}
if ( V_38 ) {
* V_36 = F_3 ( * V_36 , * V_38 ,
V_8 -> V_45 [ V_1 ] . V_6 ) ;
if ( * V_38 == * V_36 )
return V_42 ;
* V_38 = * V_36 ;
}
if ( V_37 && V_8 -> V_41 != F_18 ( V_8 , V_39 ) ) {
F_19 ( V_8 , V_39 , V_8 -> V_41 ) ;
F_4 ( V_8 , V_49 , V_39 , V_8 -> V_41 ) ;
}
return V_50 ;
}
static void F_20 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
int V_51 = V_42 ;
switch ( type ) {
case V_27 :
switch ( V_1 ) {
case V_52 :
V_51 = V_53 ;
break;
case V_28 :
if ( ! V_8 -> V_26 ) {
V_8 -> V_26 = true ;
V_51 = V_50 ;
}
break;
case V_54 :
V_8 -> V_26 = false ;
V_51 = V_50 ;
break;
}
break;
case V_25 :
if ( F_1 ( V_1 , V_8 -> V_23 , V_24 ) &&
! ! F_2 ( V_1 , V_8 -> V_22 ) != V_4 ) {
if ( V_4 != 2 ) {
F_21 ( V_1 , V_8 -> V_22 ) ;
if ( V_4 )
F_14 ( V_8 , V_1 ) ;
else
F_15 ( V_8 ) ;
}
V_51 = V_50 ;
}
break;
case V_55 :
if ( F_1 ( V_1 , V_8 -> V_56 , V_57 ) &&
! ! F_2 ( V_1 , V_8 -> V_58 ) != V_4 ) {
F_21 ( V_1 , V_8 -> V_58 ) ;
V_51 = V_50 ;
}
break;
case V_49 :
if ( F_1 ( V_1 , V_8 -> V_59 , V_60 ) )
V_51 = F_17 ( V_8 , V_1 , & V_4 ) ;
break;
case V_61 :
if ( F_1 ( V_1 , V_8 -> V_62 , V_63 ) && V_4 )
V_51 = V_50 ;
break;
case V_64 :
if ( F_1 ( V_1 , V_8 -> V_65 , V_66 ) )
V_51 = V_53 ;
break;
case V_67 :
if ( F_1 ( V_1 , V_8 -> V_68 , V_69 ) &&
! ! F_2 ( V_1 , V_8 -> V_70 ) != V_4 ) {
F_21 ( V_1 , V_8 -> V_70 ) ;
V_51 = V_53 ;
}
break;
case V_71 :
if ( F_1 ( V_1 , V_8 -> V_72 , V_73 ) ) {
if ( ! ! F_2 ( V_1 , V_8 -> V_74 ) != ! ! V_4 )
F_21 ( V_1 , V_8 -> V_74 ) ;
V_51 = V_53 ;
}
break;
case V_33 :
if ( V_1 <= V_75 && V_4 >= 0 && V_8 -> V_29 [ V_1 ] != V_4 ) {
V_8 -> V_29 [ V_1 ] = V_4 ;
V_51 = V_53 ;
}
break;
case V_76 :
if ( V_4 >= 0 )
V_51 = V_53 ;
break;
case V_77 :
V_51 = V_53 ;
break;
}
if ( V_51 != V_42 && type != V_27 )
V_8 -> V_26 = false ;
if ( ( V_51 & V_78 ) && V_8 -> V_14 )
V_8 -> V_14 ( V_8 , type , V_1 , V_4 ) ;
if ( V_51 & V_50 )
F_4 ( V_8 , type , V_1 , V_4 ) ;
}
void F_22 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
unsigned long V_19 ;
if ( F_1 ( type , V_8 -> V_34 , V_79 ) ) {
F_10 ( & V_8 -> V_20 , V_19 ) ;
F_23 ( type , V_1 , V_4 ) ;
F_20 ( V_8 , type , V_1 , V_4 ) ;
F_13 ( & V_8 -> V_20 , V_19 ) ;
}
}
void F_24 ( struct V_11 * V_12 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
struct V_11 * V_13 ;
unsigned long V_19 ;
if ( F_1 ( type , V_8 -> V_34 , V_79 ) ) {
F_10 ( & V_8 -> V_20 , V_19 ) ;
F_5 () ;
V_13 = F_6 ( V_8 -> V_13 ) ;
if ( ! V_13 || V_13 == V_12 )
F_20 ( V_8 , type , V_1 , V_4 ) ;
F_8 () ;
F_13 ( & V_8 -> V_20 , V_19 ) ;
}
}
void F_25 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_26 ( V_80 , sizeof( struct V_81 ) ,
V_82 ) ;
F_27 ( ! V_8 -> V_45 , L_1 , V_83 ) ;
}
void F_28 ( struct V_7 * V_8 , unsigned int V_84 ,
int V_85 , int V_3 , int V_6 , int V_86 )
{
struct V_81 * V_45 ;
F_25 ( V_8 ) ;
if ( ! V_8 -> V_45 )
return;
V_45 = & V_8 -> V_45 [ V_84 ] ;
V_45 -> V_87 = V_85 ;
V_45 -> V_88 = V_3 ;
V_45 -> V_6 = V_6 ;
V_45 -> V_86 = V_86 ;
V_8 -> V_59 [ F_29 ( V_84 ) ] |= F_30 ( V_84 ) ;
}
int F_31 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
int V_89 ;
V_89 = F_32 ( & V_8 -> V_90 ) ;
if ( V_89 )
return V_89 ;
if ( V_8 -> V_13 ) {
V_89 = - V_91 ;
goto V_92;
}
F_33 ( V_8 -> V_13 , V_12 ) ;
V_92:
F_34 ( & V_8 -> V_90 ) ;
return V_89 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
if ( V_8 -> V_13 == V_12 ) {
F_33 ( V_8 -> V_13 , NULL ) ;
F_36 () ;
F_37 (handle, &dev->h_list, d_node)
if ( V_12 -> V_16 && V_12 -> V_10 -> V_93 )
V_12 -> V_10 -> V_93 ( V_12 ) ;
}
}
void F_38 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
F_39 ( & V_8 -> V_90 ) ;
F_35 ( V_12 ) ;
F_34 ( & V_8 -> V_90 ) ;
}
int F_40 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
int V_89 ;
V_89 = F_32 ( & V_8 -> V_90 ) ;
if ( V_89 )
return V_89 ;
if ( V_8 -> V_94 ) {
V_89 = - V_95 ;
goto V_92;
}
V_12 -> V_16 ++ ;
if ( ! V_8 -> V_96 ++ && V_8 -> V_16 )
V_89 = V_8 -> V_16 ( V_8 ) ;
if ( V_89 ) {
V_8 -> V_96 -- ;
if ( ! -- V_12 -> V_16 ) {
F_36 () ;
}
}
V_92:
F_34 ( & V_8 -> V_90 ) ;
return V_89 ;
}
int F_41 ( struct V_11 * V_12 , struct V_97 * V_97 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
int V_89 ;
V_89 = F_32 ( & V_8 -> V_90 ) ;
if ( V_89 )
return V_89 ;
if ( V_8 -> V_98 )
V_89 = V_8 -> V_98 ( V_8 , V_97 ) ;
F_34 ( & V_8 -> V_90 ) ;
return V_89 ;
}
void F_42 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
F_39 ( & V_8 -> V_90 ) ;
F_35 ( V_12 ) ;
if ( ! -- V_8 -> V_96 && V_8 -> V_99 )
V_8 -> V_99 ( V_8 ) ;
if ( ! -- V_12 -> V_16 ) {
F_36 () ;
}
F_34 ( & V_8 -> V_90 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
int V_1 ;
if ( F_1 ( V_25 , V_8 -> V_34 , V_79 ) ) {
for ( V_1 = 0 ; V_1 <= V_24 ; V_1 ++ ) {
if ( F_1 ( V_1 , V_8 -> V_23 , V_24 ) &&
F_44 ( V_1 , V_8 -> V_22 ) ) {
F_4 ( V_8 , V_25 , V_1 , 0 ) ;
}
}
F_4 ( V_8 , V_27 , V_28 , 1 ) ;
}
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
F_39 ( & V_8 -> V_90 ) ;
V_8 -> V_94 = true ;
F_34 ( & V_8 -> V_90 ) ;
F_46 ( & V_8 -> V_20 ) ;
F_43 ( V_8 ) ;
F_37 (handle, &dev->h_list, d_node)
V_12 -> V_16 = 0 ;
F_47 ( & V_8 -> V_20 ) ;
}
int F_48 ( const struct V_100 * V_101 ,
unsigned int * V_102 )
{
switch ( V_101 -> V_103 ) {
case 1 :
* V_102 = * ( ( V_104 * ) V_101 -> V_102 ) ;
break;
case 2 :
* V_102 = * ( ( V_105 * ) V_101 -> V_102 ) ;
break;
case 4 :
* V_102 = * ( ( V_106 * ) V_101 -> V_102 ) ;
break;
default:
return - V_107 ;
}
return 0 ;
}
static unsigned int F_49 ( struct V_7 * V_8 ,
unsigned int V_108 )
{
switch ( V_8 -> V_109 ) {
case 1 :
return ( ( V_104 * ) V_8 -> V_110 ) [ V_108 ] ;
case 2 :
return ( ( V_105 * ) V_8 -> V_110 ) [ V_108 ] ;
default:
return ( ( V_106 * ) V_8 -> V_110 ) [ V_108 ] ;
}
}
static int F_50 ( struct V_7 * V_8 ,
struct V_100 * V_101 )
{
unsigned int V_108 ;
int error ;
if ( ! V_8 -> V_109 )
return - V_107 ;
if ( V_101 -> V_19 & V_111 )
V_108 = V_101 -> V_108 ;
else {
error = F_48 ( V_101 , & V_108 ) ;
if ( error )
return error ;
}
if ( V_108 >= V_8 -> V_112 )
return - V_107 ;
V_101 -> V_110 = F_49 ( V_8 , V_108 ) ;
V_101 -> V_108 = V_108 ;
V_101 -> V_103 = sizeof( V_108 ) ;
memcpy ( V_101 -> V_102 , & V_108 , sizeof( V_108 ) ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 ,
const struct V_100 * V_101 ,
unsigned int * V_113 )
{
unsigned int V_108 ;
int error ;
int V_114 ;
if ( ! V_8 -> V_109 )
return - V_107 ;
if ( V_101 -> V_19 & V_111 ) {
V_108 = V_101 -> V_108 ;
} else {
error = F_48 ( V_101 , & V_108 ) ;
if ( error )
return error ;
}
if ( V_108 >= V_8 -> V_112 )
return - V_107 ;
if ( V_8 -> V_109 < sizeof( V_101 -> V_110 ) &&
( V_101 -> V_110 >> ( V_8 -> V_109 * 8 ) ) )
return - V_107 ;
switch ( V_8 -> V_109 ) {
case 1 : {
V_104 * V_115 = ( V_104 * ) V_8 -> V_110 ;
* V_113 = V_115 [ V_108 ] ;
V_115 [ V_108 ] = V_101 -> V_110 ;
break;
}
case 2 : {
V_105 * V_115 = ( V_105 * ) V_8 -> V_110 ;
* V_113 = V_115 [ V_108 ] ;
V_115 [ V_108 ] = V_101 -> V_110 ;
break;
}
default: {
V_106 * V_115 = ( V_106 * ) V_8 -> V_110 ;
* V_113 = V_115 [ V_108 ] ;
V_115 [ V_108 ] = V_101 -> V_110 ;
break;
}
}
F_52 ( * V_113 , V_8 -> V_23 ) ;
F_53 ( V_101 -> V_110 , V_8 -> V_23 ) ;
for ( V_114 = 0 ; V_114 < V_8 -> V_112 ; V_114 ++ ) {
if ( F_49 ( V_8 , V_114 ) == * V_113 ) {
F_53 ( * V_113 , V_8 -> V_23 ) ;
break;
}
}
return 0 ;
}
int F_54 ( struct V_7 * V_8 , struct V_100 * V_101 )
{
unsigned long V_19 ;
int V_89 ;
F_10 ( & V_8 -> V_20 , V_19 ) ;
V_89 = V_8 -> V_116 ( V_8 , V_101 ) ;
F_13 ( & V_8 -> V_20 , V_19 ) ;
return V_89 ;
}
int F_55 ( struct V_7 * V_8 ,
const struct V_100 * V_101 )
{
unsigned long V_19 ;
unsigned int V_113 ;
int V_89 ;
if ( V_101 -> V_110 > V_24 )
return - V_107 ;
F_10 ( & V_8 -> V_20 , V_19 ) ;
V_89 = V_8 -> V_117 ( V_8 , V_101 , & V_113 ) ;
if ( V_89 )
goto V_92;
F_52 ( V_118 , V_8 -> V_23 ) ;
if ( F_2 ( V_25 , V_8 -> V_34 ) &&
! F_1 ( V_113 , V_8 -> V_23 , V_24 ) &&
F_44 ( V_113 , V_8 -> V_22 ) ) {
F_4 ( V_8 , V_25 , V_113 , 0 ) ;
if ( V_8 -> V_26 )
F_4 ( V_8 , V_27 , V_28 , 1 ) ;
}
V_92:
F_13 ( & V_8 -> V_20 , V_19 ) ;
return V_89 ;
}
static const struct V_119 * F_56 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
const struct V_119 * V_120 ;
int V_114 ;
for ( V_120 = V_10 -> V_121 ; V_120 -> V_19 || V_120 -> V_122 ; V_120 ++ ) {
if ( V_120 -> V_19 & V_123 )
if ( V_120 -> V_124 != V_8 -> V_120 . V_124 )
continue;
if ( V_120 -> V_19 & V_125 )
if ( V_120 -> V_126 != V_8 -> V_120 . V_126 )
continue;
if ( V_120 -> V_19 & V_127 )
if ( V_120 -> V_128 != V_8 -> V_120 . V_128 )
continue;
if ( V_120 -> V_19 & V_129 )
if ( V_120 -> V_130 != V_8 -> V_120 . V_130 )
continue;
F_57 ( V_34 , V_79 ) ;
F_57 ( V_23 , V_24 ) ;
F_57 ( V_62 , V_63 ) ;
F_57 ( V_59 , V_60 ) ;
F_57 ( V_65 , V_66 ) ;
F_57 ( V_68 , V_69 ) ;
F_57 ( V_72 , V_73 ) ;
F_57 ( V_131 , V_132 ) ;
F_57 ( V_56 , V_57 ) ;
if ( ! V_10 -> V_133 || V_10 -> V_133 ( V_10 , V_8 ) )
return V_120 ;
}
return NULL ;
}
static int F_58 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
const struct V_119 * V_120 ;
int error ;
V_120 = F_56 ( V_10 , V_8 ) ;
if ( ! V_120 )
return - V_95 ;
error = V_10 -> V_134 ( V_10 , V_8 , V_120 ) ;
if ( error && error != - V_95 )
F_59 ( L_2 ,
V_10 -> V_135 , F_60 ( & V_8 -> V_8 . V_136 ) , error ) ;
return error ;
}
static int F_61 ( char * V_137 , int V_138 ,
unsigned long V_139 , bool V_140 )
{
int V_103 = 0 ;
if ( V_141 ) {
V_106 V_142 = V_139 >> 32 ;
if ( V_142 || ! V_140 )
V_103 += snprintf ( V_137 , V_138 , L_3 , V_142 ) ;
V_142 = V_139 & 0xffffffffUL ;
if ( V_142 || ! V_140 || V_103 )
V_103 += snprintf ( V_137 + V_103 , V_3 ( V_138 - V_103 , 0 ) ,
L_4 , V_142 ) ;
} else {
if ( V_139 || ! V_140 )
V_103 += snprintf ( V_137 , V_138 , L_5 , V_139 ) ;
}
return V_103 ;
}
static int F_61 ( char * V_137 , int V_138 ,
unsigned long V_139 , bool V_140 )
{
return V_139 || ! V_140 ?
snprintf ( V_137 , V_138 , L_5 , V_139 ) : 0 ;
}
static inline void F_62 ( void )
{
V_143 ++ ;
F_63 ( & V_144 ) ;
}
static unsigned int F_64 ( struct V_97 * V_97 , T_1 * V_145 )
{
F_65 ( V_97 , & V_144 , V_145 ) ;
if ( V_97 -> V_146 != V_143 ) {
V_97 -> V_146 = V_143 ;
return V_147 | V_148 ;
}
return 0 ;
}
static void * F_66 ( struct V_149 * V_150 , T_2 * V_151 )
{
union V_152 * V_153 = (union V_152 * ) & V_150 -> V_154 ;
int error ;
F_67 ( sizeof( union V_152 ) != sizeof( V_150 -> V_154 ) ) ;
error = F_32 ( & V_155 ) ;
if ( error ) {
V_153 -> V_156 = false ;
return F_68 ( error ) ;
}
V_153 -> V_156 = true ;
return F_69 ( & V_157 , * V_151 ) ;
}
static void * F_70 ( struct V_149 * V_150 , void * V_158 , T_2 * V_151 )
{
return F_71 ( V_158 , & V_157 , V_151 ) ;
}
static void F_72 ( struct V_149 * V_150 , void * V_158 )
{
union V_152 * V_153 = (union V_152 * ) & V_150 -> V_154 ;
if ( V_153 -> V_156 )
F_34 ( & V_155 ) ;
}
static void F_73 ( struct V_149 * V_150 , const char * V_135 ,
unsigned long * V_159 , int V_3 )
{
int V_114 ;
bool V_140 = true ;
char V_137 [ 18 ] ;
F_74 ( V_150 , L_6 , V_135 ) ;
for ( V_114 = F_75 ( V_3 ) - 1 ; V_114 >= 0 ; V_114 -- ) {
if ( F_61 ( V_137 , sizeof( V_137 ) ,
V_159 [ V_114 ] , V_140 ) ) {
V_140 = false ;
F_74 ( V_150 , L_7 , V_137 , V_114 > 0 ? L_8 : L_9 ) ;
}
}
if ( V_140 )
F_76 ( V_150 , L_10 ) ;
F_77 ( V_150 , '\n' ) ;
}
static int F_78 ( struct V_149 * V_150 , void * V_158 )
{
struct V_7 * V_8 = F_79 ( V_158 , struct V_7 , V_160 ) ;
const char * V_161 = F_80 ( & V_8 -> V_8 . V_136 , V_82 ) ;
struct V_11 * V_12 ;
F_74 ( V_150 , L_11 ,
V_8 -> V_120 . V_124 , V_8 -> V_120 . V_126 , V_8 -> V_120 . V_128 , V_8 -> V_120 . V_130 ) ;
F_74 ( V_150 , L_12 , V_8 -> V_135 ? V_8 -> V_135 : L_9 ) ;
F_74 ( V_150 , L_13 , V_8 -> V_162 ? V_8 -> V_162 : L_9 ) ;
F_74 ( V_150 , L_14 , V_161 ? V_161 : L_9 ) ;
F_74 ( V_150 , L_15 , V_8 -> V_163 ? V_8 -> V_163 : L_9 ) ;
F_74 ( V_150 , L_16 ) ;
F_37 (handle, &dev->h_list, d_node)
F_74 ( V_150 , L_17 , V_12 -> V_135 ) ;
F_77 ( V_150 , '\n' ) ;
F_73 ( V_150 , L_18 , V_8 -> V_164 , V_165 ) ;
F_73 ( V_150 , L_19 , V_8 -> V_34 , V_79 ) ;
if ( F_2 ( V_25 , V_8 -> V_34 ) )
F_73 ( V_150 , L_20 , V_8 -> V_23 , V_24 ) ;
if ( F_2 ( V_61 , V_8 -> V_34 ) )
F_73 ( V_150 , L_21 , V_8 -> V_62 , V_63 ) ;
if ( F_2 ( V_49 , V_8 -> V_34 ) )
F_73 ( V_150 , L_22 , V_8 -> V_59 , V_60 ) ;
if ( F_2 ( V_64 , V_8 -> V_34 ) )
F_73 ( V_150 , L_23 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_67 , V_8 -> V_34 ) )
F_73 ( V_150 , L_24 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_71 , V_8 -> V_34 ) )
F_73 ( V_150 , L_25 , V_8 -> V_72 , V_73 ) ;
if ( F_2 ( V_76 , V_8 -> V_34 ) )
F_73 ( V_150 , L_26 , V_8 -> V_131 , V_132 ) ;
if ( F_2 ( V_55 , V_8 -> V_34 ) )
F_73 ( V_150 , L_27 , V_8 -> V_56 , V_57 ) ;
F_77 ( V_150 , '\n' ) ;
F_81 ( V_161 ) ;
return 0 ;
}
static int F_82 ( struct V_166 * V_166 , struct V_97 * V_97 )
{
return F_83 ( V_97 , & V_167 ) ;
}
static void * F_84 ( struct V_149 * V_150 , T_2 * V_151 )
{
union V_152 * V_153 = (union V_152 * ) & V_150 -> V_154 ;
int error ;
F_67 ( sizeof( union V_152 ) != sizeof( V_150 -> V_154 ) ) ;
error = F_32 ( & V_155 ) ;
if ( error ) {
V_153 -> V_156 = false ;
return F_68 ( error ) ;
}
V_153 -> V_156 = true ;
V_153 -> V_151 = * V_151 ;
return F_69 ( & V_168 , * V_151 ) ;
}
static void * F_85 ( struct V_149 * V_150 , void * V_158 , T_2 * V_151 )
{
union V_152 * V_153 = (union V_152 * ) & V_150 -> V_154 ;
V_153 -> V_151 = * V_151 + 1 ;
return F_71 ( V_158 , & V_168 , V_151 ) ;
}
static int F_86 ( struct V_149 * V_150 , void * V_158 )
{
struct V_9 * V_10 = F_79 ( V_158 , struct V_9 , V_160 ) ;
union V_152 * V_153 = (union V_152 * ) & V_150 -> V_154 ;
F_74 ( V_150 , L_28 , V_153 -> V_151 , V_10 -> V_135 ) ;
if ( V_10 -> V_17 )
F_76 ( V_150 , L_29 ) ;
if ( V_10 -> V_169 )
F_74 ( V_150 , L_30 , V_10 -> V_170 ) ;
F_77 ( V_150 , '\n' ) ;
return 0 ;
}
static int F_87 ( struct V_166 * V_166 , struct V_97 * V_97 )
{
return F_83 ( V_97 , & V_171 ) ;
}
static int T_3 F_88 ( void )
{
struct V_172 * V_173 ;
V_174 = F_89 ( L_31 , NULL ) ;
if ( ! V_174 )
return - V_175 ;
V_173 = F_90 ( L_32 , 0 , V_174 ,
& V_176 ) ;
if ( ! V_173 )
goto V_177;
V_173 = F_90 ( L_33 , 0 , V_174 ,
& V_178 ) ;
if ( ! V_173 )
goto V_179;
return 0 ;
V_179: F_91 ( L_32 , V_174 ) ;
V_177: F_91 ( L_31 , NULL ) ;
return - V_175 ;
}
static void F_92 ( void )
{
F_91 ( L_32 , V_174 ) ;
F_91 ( L_33 , V_174 ) ;
F_91 ( L_31 , NULL ) ;
}
static inline void F_62 ( void ) { }
static inline int F_88 ( void ) { return 0 ; }
static inline void F_92 ( void ) { }
static int F_93 ( char * V_137 , int V_180 ,
char V_135 , unsigned long * V_2 ,
unsigned int V_181 , unsigned int V_182 )
{
int V_103 = 0 , V_114 ;
V_103 += snprintf ( V_137 , V_3 ( V_180 , 0 ) , L_34 , V_135 ) ;
for ( V_114 = V_181 ; V_114 < V_182 ; V_114 ++ )
if ( V_2 [ F_29 ( V_114 ) ] & F_30 ( V_114 ) )
V_103 += snprintf ( V_137 + V_103 , V_3 ( V_180 - V_103 , 0 ) , L_35 , V_114 ) ;
return V_103 ;
}
static int F_94 ( char * V_137 , int V_180 , struct V_7 * V_120 ,
int V_183 )
{
int V_103 ;
V_103 = snprintf ( V_137 , V_3 ( V_180 , 0 ) ,
L_36 ,
V_120 -> V_120 . V_124 , V_120 -> V_120 . V_126 ,
V_120 -> V_120 . V_128 , V_120 -> V_120 . V_130 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'e' , V_120 -> V_34 , 0 , V_79 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'k' , V_120 -> V_23 , V_184 , V_24 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'r' , V_120 -> V_62 , 0 , V_63 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'a' , V_120 -> V_59 , 0 , V_60 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'm' , V_120 -> V_65 , 0 , V_66 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'l' , V_120 -> V_68 , 0 , V_69 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
's' , V_120 -> V_72 , 0 , V_73 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'f' , V_120 -> V_131 , 0 , V_132 ) ;
V_103 += F_93 ( V_137 + V_103 , V_180 - V_103 ,
'w' , V_120 -> V_56 , 0 , V_57 ) ;
if ( V_183 )
V_103 += snprintf ( V_137 + V_103 , V_3 ( V_180 - V_103 , 0 ) , L_37 ) ;
return V_103 ;
}
static T_4 F_95 ( struct V_185 * V_8 ,
struct V_186 * V_187 ,
char * V_137 )
{
struct V_7 * V_120 = F_96 ( V_8 ) ;
T_4 V_103 ;
V_103 = F_94 ( V_137 , V_188 , V_120 , 1 ) ;
return F_97 ( int , V_103 , V_188 ) ;
}
static T_4 F_98 ( struct V_185 * V_8 ,
struct V_186 * V_187 ,
char * V_137 )
{
struct V_7 * V_7 = F_96 ( V_8 ) ;
int V_103 = F_99 ( V_137 , V_188 , V_7 -> V_164 ,
V_165 , true ) ;
return F_97 ( int , V_103 , V_188 ) ;
}
static int F_99 ( char * V_137 , int V_138 , unsigned long * V_159 ,
int V_3 , int V_183 )
{
int V_114 ;
int V_103 = 0 ;
bool V_140 = true ;
for ( V_114 = F_75 ( V_3 ) - 1 ; V_114 >= 0 ; V_114 -- ) {
V_103 += F_61 ( V_137 + V_103 , V_3 ( V_138 - V_103 , 0 ) ,
V_159 [ V_114 ] , V_140 ) ;
if ( V_103 ) {
V_140 = false ;
if ( V_114 > 0 )
V_103 += snprintf ( V_137 + V_103 , V_3 ( V_138 - V_103 , 0 ) , L_8 ) ;
}
}
if ( V_103 == 0 )
V_103 = snprintf ( V_137 , V_138 , L_38 , 0 ) ;
if ( V_183 )
V_103 += snprintf ( V_137 + V_103 , V_3 ( V_138 - V_103 , 0 ) , L_37 ) ;
return V_103 ;
}
static void F_100 ( struct V_185 * V_185 )
{
struct V_7 * V_8 = F_96 ( V_185 ) ;
F_101 ( V_8 ) ;
F_102 ( V_8 ) ;
F_81 ( V_8 -> V_45 ) ;
F_81 ( V_8 ) ;
F_103 ( V_189 ) ;
}
static int F_104 ( struct V_190 * V_191 ,
const char * V_135 , unsigned long * V_159 , int V_3 )
{
int V_103 ;
if ( F_105 ( V_191 , L_39 , V_135 ) )
return - V_175 ;
V_103 = F_99 ( & V_191 -> V_137 [ V_191 -> V_192 - 1 ] ,
sizeof( V_191 -> V_137 ) - V_191 -> V_192 ,
V_159 , V_3 , false ) ;
if ( V_103 >= ( sizeof( V_191 -> V_137 ) - V_191 -> V_192 ) )
return - V_175 ;
V_191 -> V_192 += V_103 ;
return 0 ;
}
static int F_106 ( struct V_190 * V_191 ,
struct V_7 * V_8 )
{
int V_103 ;
if ( F_105 ( V_191 , L_40 ) )
return - V_175 ;
V_103 = F_94 ( & V_191 -> V_137 [ V_191 -> V_192 - 1 ] ,
sizeof( V_191 -> V_137 ) - V_191 -> V_192 ,
V_8 , 0 ) ;
if ( V_103 >= ( sizeof( V_191 -> V_137 ) - V_191 -> V_192 ) )
return - V_175 ;
V_191 -> V_192 += V_103 ;
return 0 ;
}
static int F_107 ( struct V_185 * V_185 , struct V_190 * V_191 )
{
struct V_7 * V_8 = F_96 ( V_185 ) ;
F_108 ( L_41 ,
V_8 -> V_120 . V_124 , V_8 -> V_120 . V_126 ,
V_8 -> V_120 . V_128 , V_8 -> V_120 . V_130 ) ;
if ( V_8 -> V_135 )
F_108 ( L_42 , V_8 -> V_135 ) ;
if ( V_8 -> V_162 )
F_108 ( L_43 , V_8 -> V_162 ) ;
if ( V_8 -> V_163 )
F_108 ( L_44 , V_8 -> V_163 ) ;
F_109 ( L_45 , V_8 -> V_164 , V_165 ) ;
F_109 ( L_46 , V_8 -> V_34 , V_79 ) ;
if ( F_2 ( V_25 , V_8 -> V_34 ) )
F_109 ( L_47 , V_8 -> V_23 , V_24 ) ;
if ( F_2 ( V_61 , V_8 -> V_34 ) )
F_109 ( L_48 , V_8 -> V_62 , V_63 ) ;
if ( F_2 ( V_49 , V_8 -> V_34 ) )
F_109 ( L_49 , V_8 -> V_59 , V_60 ) ;
if ( F_2 ( V_64 , V_8 -> V_34 ) )
F_109 ( L_50 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_67 , V_8 -> V_34 ) )
F_109 ( L_51 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_71 , V_8 -> V_34 ) )
F_109 ( L_52 , V_8 -> V_72 , V_73 ) ;
if ( F_2 ( V_76 , V_8 -> V_34 ) )
F_109 ( L_53 , V_8 -> V_131 , V_132 ) ;
if ( F_2 ( V_55 , V_8 -> V_34 ) )
F_109 ( L_54 , V_8 -> V_56 , V_57 ) ;
F_110 ( V_8 ) ;
return 0 ;
}
static void F_111 ( struct V_7 * V_8 , bool V_193 )
{
if ( ! V_8 -> V_14 )
return;
F_112 ( V_8 , V_194 , V_70 , V_193 ) ;
F_112 ( V_8 , V_195 , V_74 , V_193 ) ;
if ( V_193 && F_2 ( V_33 , V_8 -> V_34 ) ) {
V_8 -> V_14 ( V_8 , V_33 , V_30 , V_8 -> V_29 [ V_30 ] ) ;
V_8 -> V_14 ( V_8 , V_33 , V_35 , V_8 -> V_29 [ V_35 ] ) ;
}
}
void F_113 ( struct V_7 * V_8 )
{
F_39 ( & V_8 -> V_90 ) ;
if ( V_8 -> V_96 ) {
F_111 ( V_8 , true ) ;
F_46 ( & V_8 -> V_20 ) ;
F_43 ( V_8 ) ;
F_47 ( & V_8 -> V_20 ) ;
}
F_34 ( & V_8 -> V_90 ) ;
}
static int F_114 ( struct V_185 * V_8 )
{
struct V_7 * V_7 = F_96 ( V_8 ) ;
F_39 ( & V_7 -> V_90 ) ;
if ( V_7 -> V_96 )
F_111 ( V_7 , false ) ;
F_34 ( & V_7 -> V_90 ) ;
return 0 ;
}
static int F_115 ( struct V_185 * V_8 )
{
struct V_7 * V_7 = F_96 ( V_8 ) ;
F_113 ( V_7 ) ;
return 0 ;
}
static char * F_116 ( struct V_185 * V_8 , T_5 * V_196 )
{
return F_117 ( V_82 , L_55 , F_118 ( V_8 ) ) ;
}
struct V_7 * F_119 ( void )
{
struct V_7 * V_8 ;
V_8 = F_120 ( sizeof( struct V_7 ) , V_82 ) ;
if ( V_8 ) {
V_8 -> V_8 . type = & V_197 ;
V_8 -> V_8 . V_198 = & V_199 ;
F_121 ( & V_8 -> V_8 ) ;
F_122 ( & V_8 -> V_90 ) ;
F_123 ( & V_8 -> V_20 ) ;
F_124 ( & V_8 -> V_200 ) ;
F_124 ( & V_8 -> V_160 ) ;
F_125 ( V_189 ) ;
}
return V_8 ;
}
void F_126 ( struct V_7 * V_8 )
{
if ( V_8 )
F_127 ( V_8 ) ;
}
void F_128 ( struct V_7 * V_8 , unsigned int type , unsigned int V_1 )
{
switch ( type ) {
case V_25 :
F_53 ( V_1 , V_8 -> V_23 ) ;
break;
case V_61 :
F_53 ( V_1 , V_8 -> V_62 ) ;
break;
case V_49 :
F_53 ( V_1 , V_8 -> V_59 ) ;
break;
case V_64 :
F_53 ( V_1 , V_8 -> V_65 ) ;
break;
case V_55 :
F_53 ( V_1 , V_8 -> V_56 ) ;
break;
case V_67 :
F_53 ( V_1 , V_8 -> V_68 ) ;
break;
case V_71 :
F_53 ( V_1 , V_8 -> V_72 ) ;
break;
case V_76 :
F_53 ( V_1 , V_8 -> V_131 ) ;
break;
case V_77 :
break;
default:
F_59 ( L_56 ,
type , V_1 ) ;
F_129 () ;
return;
}
F_53 ( type , V_8 -> V_34 ) ;
}
static unsigned int F_130 ( struct V_7 * V_8 )
{
int V_201 ;
int V_114 ;
unsigned int V_202 ;
if ( V_8 -> V_40 ) {
V_201 = V_8 -> V_40 ;
} else if ( F_2 ( V_203 , V_8 -> V_59 ) ) {
V_201 = V_8 -> V_45 [ V_203 ] . V_88 -
V_8 -> V_45 [ V_203 ] . V_87 + 1 ,
V_201 = F_131 ( V_201 , 2 , 32 ) ;
} else if ( F_2 ( V_204 , V_8 -> V_59 ) ) {
V_201 = 2 ;
} else {
V_201 = 0 ;
}
V_202 = V_201 + 1 ;
for ( V_114 = 0 ; V_114 < V_80 ; V_114 ++ ) {
if ( F_2 ( V_114 , V_8 -> V_59 ) ) {
if ( F_132 ( V_114 ) )
V_202 += V_201 ;
else
V_202 ++ ;
}
}
for ( V_114 = 0 ; V_114 < V_205 ; V_114 ++ )
if ( F_2 ( V_114 , V_8 -> V_62 ) )
V_202 ++ ;
return V_202 ;
}
static void F_133 ( struct V_7 * V_8 )
{
F_134 ( V_8 , V_206 , V_22 ) ;
F_134 ( V_8 , V_207 , V_208 ) ;
F_134 ( V_8 , ABS , abs ) ;
F_134 ( V_8 , V_209 , V_210 ) ;
F_134 ( V_8 , V_194 , V_70 ) ;
F_134 ( V_8 , V_195 , V_74 ) ;
F_134 ( V_8 , V_211 , V_212 ) ;
F_134 ( V_8 , V_213 , V_58 ) ;
}
int F_135 ( struct V_7 * V_8 )
{
static T_6 V_214 = F_136 ( 0 ) ;
struct V_9 * V_10 ;
const char * V_161 ;
int error ;
F_53 ( V_27 , V_8 -> V_34 ) ;
F_52 ( V_118 , V_8 -> V_23 ) ;
F_133 ( V_8 ) ;
if ( ! V_8 -> V_215 )
V_8 -> V_215 =
F_130 ( V_8 ) ;
F_137 ( & V_8 -> V_31 ) ;
if ( ! V_8 -> V_29 [ V_35 ] && ! V_8 -> V_29 [ V_30 ] ) {
V_8 -> V_31 . V_18 = ( long ) V_8 ;
V_8 -> V_31 . V_216 = F_9 ;
V_8 -> V_29 [ V_35 ] = 250 ;
V_8 -> V_29 [ V_30 ] = 33 ;
}
if ( ! V_8 -> V_116 )
V_8 -> V_116 = F_50 ;
if ( ! V_8 -> V_117 )
V_8 -> V_117 = F_51 ;
F_138 ( & V_8 -> V_8 , L_57 ,
( unsigned long ) F_139 ( & V_214 ) - 1 ) ;
error = F_140 ( & V_8 -> V_8 ) ;
if ( error )
return error ;
V_161 = F_80 ( & V_8 -> V_8 . V_136 , V_82 ) ;
F_141 ( L_58 ,
V_8 -> V_135 ? V_8 -> V_135 : L_59 ,
V_161 ? V_161 : L_60 ) ;
F_81 ( V_161 ) ;
error = F_32 ( & V_155 ) ;
if ( error ) {
F_142 ( & V_8 -> V_8 ) ;
return error ;
}
F_143 ( & V_8 -> V_160 , & V_157 ) ;
F_37 (handler, &input_handler_list, node)
F_58 ( V_8 , V_10 ) ;
F_62 () ;
F_34 ( & V_155 ) ;
return 0 ;
}
void F_144 ( struct V_7 * V_8 )
{
struct V_11 * V_12 , * V_217 ;
F_45 ( V_8 ) ;
F_39 ( & V_155 ) ;
F_145 (handle, next, &dev->h_list, d_node)
V_12 -> V_10 -> V_218 ( V_12 ) ;
F_146 ( ! F_147 ( & V_8 -> V_200 ) ) ;
F_148 ( & V_8 -> V_31 ) ;
F_149 ( & V_8 -> V_160 ) ;
F_62 () ;
F_34 ( & V_155 ) ;
F_150 ( & V_8 -> V_8 ) ;
}
int F_151 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
int V_89 ;
V_89 = F_32 ( & V_155 ) ;
if ( V_89 )
return V_89 ;
F_124 ( & V_10 -> V_200 ) ;
if ( V_10 -> V_169 != NULL ) {
if ( V_219 [ V_10 -> V_170 >> 5 ] ) {
V_89 = - V_91 ;
goto V_92;
}
V_219 [ V_10 -> V_170 >> 5 ] = V_10 ;
}
F_143 ( & V_10 -> V_160 , & V_168 ) ;
F_37 (dev, &input_dev_list, node)
F_58 ( V_8 , V_10 ) ;
F_62 () ;
V_92:
F_34 ( & V_155 ) ;
return V_89 ;
}
void F_152 ( struct V_9 * V_10 )
{
struct V_11 * V_12 , * V_217 ;
F_39 ( & V_155 ) ;
F_145 (handle, next, &handler->h_list, h_node)
V_10 -> V_218 ( V_12 ) ;
F_146 ( ! F_147 ( & V_10 -> V_200 ) ) ;
F_149 ( & V_10 -> V_160 ) ;
if ( V_10 -> V_169 != NULL )
V_219 [ V_10 -> V_170 >> 5 ] = NULL ;
F_62 () ;
F_34 ( & V_155 ) ;
}
int F_153 ( struct V_9 * V_10 , void * V_18 ,
int (* F_154)( struct V_11 * , void * ) )
{
struct V_11 * V_12 ;
int V_89 = 0 ;
F_5 () ;
F_7 (handle, &handler->h_list, h_node) {
V_89 = F_154 ( V_12 , V_18 ) ;
if ( V_89 )
break;
}
F_8 () ;
return V_89 ;
}
int F_155 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_7 * V_8 = V_12 -> V_8 ;
int error ;
error = F_32 ( & V_8 -> V_90 ) ;
if ( error )
return error ;
if ( V_10 -> V_17 )
F_156 ( & V_12 -> V_220 , & V_8 -> V_200 ) ;
else
F_157 ( & V_12 -> V_220 , & V_8 -> V_200 ) ;
F_34 ( & V_8 -> V_90 ) ;
F_157 ( & V_12 -> V_221 , & V_10 -> V_200 ) ;
if ( V_10 -> V_93 )
V_10 -> V_93 ( V_12 ) ;
return 0 ;
}
void F_158 ( struct V_11 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_8 ;
F_159 ( & V_12 -> V_221 ) ;
F_39 ( & V_8 -> V_90 ) ;
F_159 ( & V_12 -> V_220 ) ;
F_34 ( & V_8 -> V_90 ) ;
F_36 () ;
}
static int F_160 ( struct V_166 * V_166 , struct V_97 * V_97 )
{
struct V_9 * V_10 ;
const struct V_222 * V_223 , * V_224 = NULL ;
int V_225 ;
V_225 = F_32 ( & V_155 ) ;
if ( V_225 )
return V_225 ;
V_10 = V_219 [ F_161 ( V_166 ) >> 5 ] ;
if ( V_10 )
V_224 = F_162 ( V_10 -> V_169 ) ;
F_34 ( & V_155 ) ;
if ( ! V_224 || ! V_224 -> V_16 ) {
F_163 ( V_224 ) ;
V_225 = - V_95 ;
goto V_92;
}
V_223 = V_97 -> V_226 ;
V_97 -> V_226 = V_224 ;
V_225 = V_224 -> V_16 ( V_166 , V_97 ) ;
if ( V_225 ) {
F_163 ( V_97 -> V_226 ) ;
V_97 -> V_226 = F_162 ( V_223 ) ;
}
F_163 ( V_223 ) ;
V_92:
return V_225 ;
}
static int T_3 F_164 ( void )
{
int V_225 ;
V_225 = F_165 ( & V_199 ) ;
if ( V_225 ) {
F_59 ( L_61 ) ;
return V_225 ;
}
V_225 = F_88 () ;
if ( V_225 )
goto V_177;
V_225 = F_166 ( V_227 , L_62 , & V_228 ) ;
if ( V_225 ) {
F_59 ( L_63 , V_227 ) ;
goto V_179;
}
return 0 ;
V_179: F_92 () ;
V_177: F_167 ( & V_199 ) ;
return V_225 ;
}
static void T_7 F_168 ( void )
{
F_92 () ;
F_169 ( V_227 , L_62 ) ;
F_167 ( & V_199 ) ;
}
