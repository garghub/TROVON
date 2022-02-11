static const struct V_1 * F_1 ( T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] . V_2 ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
return NULL ;
}
static char * F_2 ( T_1 V_5 [] , int V_6 , char * V_7 )
{
char * V_8 ;
int V_3 ;
for ( V_3 = 0 , V_8 = V_7 ; V_3 < V_6 ; V_3 ++ , V_8 += 11 ) {
snprintf ( V_8 , 12 , L_1 , V_5 [ V_3 ] ) ;
}
* V_8 = '\0' ;
return V_7 ;
}
static void F_3 ( struct V_9 * V_10 , struct V_11 * V_12 , char * V_13 )
{
char V_14 [ V_15 * 11 + 1 ] ;
if ( ! ( V_16 & V_17 ) )
return;
F_4 ( L_2
L_3 , V_13 , V_12 -> V_18 , V_12 -> V_19 , V_12 -> V_2 , V_12 -> error ,
F_2 ( V_12 -> args , V_15 , V_14 ) ) ;
}
static void F_5 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_24 * V_7 ;
if ( V_21 -> V_25 == NULL || ! V_21 -> V_25 -> V_26 || V_23 -> V_27 == 0 )
return;
if ( F_6 ( & V_23 -> V_28 ) ) {
V_7 = F_7 ( & V_23 -> V_28 , struct V_24 ,
V_29 ) ;
if ( V_7 -> V_27 )
F_8 ( & V_21 -> V_25 -> V_30 ,
V_7 -> V_7 , V_7 -> V_27 ) ;
return;
}
F_9 (buf, &mdl->buf_list, list) {
if ( V_7 -> V_27 == 0 )
break;
F_8 ( & V_21 -> V_25 -> V_30 , V_7 -> V_7 , V_7 -> V_27 ) ;
}
}
static void F_10 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_31 * V_32 ;
struct V_24 * V_7 ;
T_2 * V_8 ;
T_1 V_33 = 0 ;
int V_34 = 0 ;
if ( V_23 -> V_27 == 0 )
return;
F_11 ( & V_21 -> V_35 ) ;
if ( F_12 ( & V_21 -> V_36 ) )
goto V_37;
V_32 = F_7 ( & V_21 -> V_36 , struct V_31 ,
V_38 . V_39 ) ;
V_8 = F_13 ( & V_32 -> V_38 ) ;
if ( ! V_8 )
goto V_37;
V_33 = V_32 -> V_40 ;
F_9 (buf, &mdl->buf_list, list) {
if ( V_7 -> V_27 == 0 )
break;
if ( ( V_33 + V_7 -> V_27 ) <= V_32 -> V_38 . V_41 ) {
memcpy ( V_8 + V_33 , V_7 -> V_7 , V_7 -> V_27 ) ;
V_33 += V_7 -> V_27 ;
V_32 -> V_40 += V_7 -> V_27 ;
}
}
if ( V_32 -> V_40 >= ( V_32 -> V_38 . V_42 * V_32 -> V_38 . V_43 * 2 ) ) {
V_34 = 1 ;
V_32 -> V_40 = 0 ;
}
if ( V_34 ) {
V_32 -> V_38 . V_44 = F_14 ( F_15 () ) ;
F_16 ( & V_32 -> V_38 . V_39 ) ;
V_32 -> V_38 . V_45 = V_46 ;
F_17 ( & V_32 -> V_38 . V_47 ) ;
}
F_18 ( & V_21 -> V_48 , F_19 ( 2000 ) + V_49 ) ;
V_37:
F_20 ( & V_21 -> V_35 ) ;
}
static void F_21 ( struct V_9 * V_10 , struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_7 ;
if ( V_23 -> V_27 == 0 )
return;
if ( F_6 ( & V_23 -> V_28 ) ) {
V_7 = F_7 ( & V_23 -> V_28 , struct V_24 ,
V_29 ) ;
if ( V_7 -> V_27 )
V_10 -> V_50 ( V_10 -> V_51 , V_7 -> V_7 ,
V_7 -> V_27 ) ;
return;
}
F_9 (buf, &mdl->buf_list, list) {
if ( V_7 -> V_27 == 0 )
break;
V_10 -> V_50 ( V_10 -> V_51 , V_7 -> V_7 , V_7 -> V_27 ) ;
}
}
static void F_22 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
T_1 V_54 , V_55 , V_56 ;
struct V_11 * V_12 ;
struct V_57 * V_58 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_3 ;
V_12 = & V_53 -> V_12 ;
V_54 = V_12 -> args [ 0 ] ;
V_21 = F_23 ( V_10 , V_54 ) ;
if ( V_21 == NULL ) {
F_24 ( L_4
L_5 , V_54 ,
( V_53 -> V_59 & V_60 ) ?
L_6 : L_7 , V_12 -> V_18 ) ;
return;
}
V_55 = V_12 -> args [ 2 ] ;
V_58 = V_53 -> V_58 ;
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ , V_58 ++ ) {
V_56 = V_58 -> V_56 ;
if ( ( V_53 -> V_59 & V_60 ) &&
! ( V_56 >= V_21 -> V_61 &&
V_56 < ( V_21 -> V_61 + V_21 -> V_62 ) ) ) {
F_24 ( L_8
L_9
L_10 , V_12 -> V_18 ) ;
break;
}
V_23 = F_25 ( V_21 , V_56 , V_58 -> V_63 ) ;
F_26 ( L_11 , V_21 -> V_13 , V_56 ) ;
if ( V_23 == NULL ) {
F_24 ( L_12 ,
V_56 , V_21 -> V_13 ) ;
continue;
}
F_26 ( L_13 ,
V_21 -> V_13 , V_23 -> V_27 ) ;
if ( V_21 -> type == V_64 ) {
F_5 ( V_21 , V_23 ) ;
F_27 ( V_21 , V_23 , & V_21 -> V_65 ) ;
} else if ( V_21 -> type == V_66 ) {
if ( V_10 -> V_50 != NULL ) {
F_21 ( V_10 , V_21 , V_23 ) ;
F_27 ( V_21 , V_23 , & V_21 -> V_65 ) ;
} else {
F_27 ( V_21 , V_23 , & V_21 -> V_67 ) ;
}
} else if ( V_21 -> type == V_68 ) {
F_10 ( V_21 , V_23 ) ;
F_27 ( V_21 , V_23 , & V_21 -> V_65 ) ;
} else {
F_27 ( V_21 , V_23 , & V_21 -> V_67 ) ;
if ( V_21 -> type == V_69 )
F_28 ( V_10 ) ;
}
}
F_29 ( V_21 ) ;
F_17 ( & V_10 -> V_70 ) ;
if ( V_21 -> V_56 != - 1 )
F_17 ( & V_21 -> V_71 ) ;
}
static void F_30 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
char * V_8 ;
char * V_72 = V_53 -> V_72 ;
F_31 ( L_14 , V_53 -> V_12 . args [ 0 ] , V_72 ) ;
V_8 = strchr ( V_72 , '.' ) ;
if ( ! F_32 ( V_73 , & V_10 -> V_74 ) && V_8 && V_8 > V_72 )
F_33 ( L_15 , V_8 - 1 ) ;
}
static void F_34 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
switch ( V_53 -> V_75 ) {
case V_76 :
{
switch ( V_53 -> V_12 . V_2 ) {
case V_77 :
F_22 ( V_10 , V_53 ) ;
break;
case V_78 :
F_30 ( V_10 , V_53 ) ;
break;
default:
F_24 ( L_16 ,
V_53 -> V_12 . V_2 ) ;
break;
}
break;
}
case V_79 :
F_24 ( L_17 ,
V_53 -> V_12 . V_2 ) ;
break;
default:
break;
}
}
static
void F_35 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
F_36 ( & V_53 -> V_80 , 0 ) ;
}
void F_37 ( struct V_81 * V_82 )
{
struct V_52 * V_53 =
F_38 ( V_82 , struct V_52 , V_82 ) ;
struct V_9 * V_10 = V_53 -> V_10 ;
F_34 ( V_10 , V_53 ) ;
F_35 ( V_10 , V_53 ) ;
}
static void F_39 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
struct V_11 T_3 * V_83 ;
T_1 V_84 , V_85 ;
switch ( V_53 -> V_75 ) {
case V_79 :
V_84 = V_86 ;
V_83 = & V_10 -> V_87 -> V_88 ;
break;
case V_76 :
V_84 = V_89 ;
V_83 = & V_10 -> V_87 -> V_90 ;
break;
default:
F_24 ( L_18 ,
V_53 -> V_75 , V_53 -> V_12 . V_2 ) ;
return;
}
V_85 = V_53 -> V_12 . V_18 ;
if ( V_85 != F_40 ( V_10 , & V_83 -> V_18 ) ||
V_85 == F_40 ( V_10 , & V_83 -> V_19 ) ) {
F_41 ( L_19
L_20
L_21 ,
V_91 [ V_53 -> V_75 ] , V_91 [ V_53 -> V_75 ] , V_85 ) ;
V_53 -> V_59 |= V_92 ;
return;
}
F_42 ( V_10 , V_85 , & V_83 -> V_19 ) ;
F_43 ( V_10 , V_84 , V_93 , V_84 , V_84 ) ;
return;
}
static int F_44 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
T_1 V_54 , V_94 , V_55 ;
struct V_11 * V_12 ;
V_12 = & V_53 -> V_12 ;
V_54 = V_12 -> args [ 0 ] ;
V_94 = V_12 -> args [ 1 ] ;
V_55 = V_12 -> args [ 2 ] ;
if ( V_54 == V_95 ||
V_55 == 0 || V_55 > V_96 ) {
if ( ( V_53 -> V_59 & V_97 ) == 0 )
F_39 ( V_10 , V_53 ) ;
return - 1 ;
}
F_45 ( V_10 , V_53 -> V_58 , V_10 -> V_98 + V_94 ,
sizeof( struct V_57 ) * V_55 ) ;
if ( ( V_53 -> V_59 & V_97 ) == 0 )
F_39 ( V_10 , V_53 ) ;
return 1 ;
}
static
int F_46 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
T_1 V_99 ;
char * V_72 = V_53 -> V_72 ;
V_72 [ 0 ] = '\0' ;
V_99 = V_53 -> V_12 . args [ 1 ] ;
if ( V_99 ) {
F_47 ( V_10 , V_99 ) ;
F_45 ( V_10 , V_72 , V_10 -> V_98 + V_99 , 252 ) ;
V_72 [ 252 ] = '\0' ;
F_47 ( V_10 , V_100 ) ;
}
if ( ( V_53 -> V_59 & V_97 ) == 0 )
F_39 ( V_10 , V_53 ) ;
return V_99 ? 1 : 0 ;
}
static inline
int F_48 ( struct V_9 * V_10 , struct V_52 * V_53 )
{
int V_101 = - 1 ;
switch ( V_53 -> V_75 ) {
case V_76 :
{
switch ( V_53 -> V_12 . V_2 ) {
case V_77 :
V_101 = F_44 ( V_10 , V_53 ) ;
break;
case V_78 :
V_101 = F_46 ( V_10 , V_53 ) ;
break;
default:
F_24 ( L_16 ,
V_53 -> V_12 . V_2 ) ;
break;
}
break;
}
case V_79 :
F_24 ( L_17 ,
V_53 -> V_12 . V_2 ) ;
break;
default:
break;
}
return V_101 ;
}
static inline
struct V_52 * F_49 ( struct V_9 * V_10 )
{
int V_3 ;
struct V_52 * V_53 = NULL ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
if ( F_50 ( & V_10 -> V_103 [ V_3 ] . V_80 ) == 0 ) {
V_53 = & V_10 -> V_103 [ V_3 ] ;
F_36 ( & V_53 -> V_80 , 1 ) ;
break;
}
}
return V_53 ;
}
void F_51 ( struct V_9 * V_10 , int V_75 )
{
struct V_11 T_3 * V_12 ;
struct V_11 * V_104 ;
struct V_52 * V_53 ;
int V_105 ;
switch ( V_75 ) {
case V_76 :
V_12 = & V_10 -> V_87 -> V_90 ;
break;
case V_79 :
V_12 = & V_10 -> V_87 -> V_88 ;
break;
default:
return;
}
V_53 = F_49 ( V_10 ) ;
if ( V_53 == NULL ) {
F_24 ( L_22
L_23 ) ;
return;
}
V_53 -> V_59 = 0 ;
V_53 -> V_75 = V_75 ;
V_104 = & V_53 -> V_12 ;
F_45 ( V_10 , & V_104 -> V_2 , & V_12 -> V_2 , 4 * sizeof( T_1 ) ) ;
F_45 ( V_10 , & V_104 -> V_18 , & V_12 -> V_18 ,
2 * sizeof( T_1 ) ) ;
if ( V_104 -> V_18 == V_104 -> V_19 ) {
F_41 ( L_19
L_24
L_3 ,
V_91 [ V_75 ] , V_91 [ V_75 ] , V_104 -> V_18 ) ;
if ( V_16 & V_106 )
F_3 ( V_10 , V_104 , L_25 ) ;
V_53 -> V_59 = V_60 ;
}
V_105 = F_48 ( V_10 , V_53 ) ;
if ( V_105 > 0 ) {
F_52 ( V_10 -> V_107 , & V_53 -> V_82 ) ;
}
}
static int F_53 ( struct V_9 * V_10 , T_1 V_2 , int args , T_1 V_5 [] )
{
const struct V_1 * V_108 = F_1 ( V_2 ) ;
T_1 V_45 , V_109 , V_85 , V_19 , V_110 ;
struct V_11 T_3 * V_12 ;
T_1 T_3 * V_111 ;
T_4 * V_71 ;
struct V_112 * V_113 ;
unsigned long int V_114 , V_115 , V_101 ;
int V_3 ;
char V_14 [ V_15 * 11 + 1 ] ;
F_54 ( V_116 ) ;
if ( V_108 == NULL ) {
F_24 ( L_26 , V_2 ) ;
return - V_117 ;
}
if ( V_16 & V_17 ) {
if ( V_2 == V_118 ) {
if ( V_16 & V_119 )
F_55 ( L_27 ,
V_108 -> V_13 , V_2 ,
F_2 ( V_5 , args , V_14 ) ) ;
} else
F_4 ( L_27 ,
V_108 -> V_13 , V_2 ,
F_2 ( V_5 , args , V_14 ) ) ;
}
switch ( V_108 -> V_75 ) {
case V_79 :
V_71 = & V_10 -> V_120 ;
V_113 = & V_10 -> V_121 ;
V_109 = V_122 ;
V_12 = & V_10 -> V_87 -> V_123 ;
V_111 = & V_10 -> V_87 -> V_124 ;
break;
case V_76 :
V_71 = & V_10 -> V_125 ;
V_113 = & V_10 -> V_126 ;
V_109 = V_127 ;
V_12 = & V_10 -> V_87 -> V_128 ;
V_111 = & V_10 -> V_87 -> V_129 ;
break;
default:
F_24 ( L_28 , V_108 -> V_75 ) ;
return - V_117 ;
}
F_56 ( V_113 ) ;
V_45 = F_40 ( V_10 , V_111 ) ;
V_85 = F_40 ( V_10 , & V_12 -> V_18 ) ;
V_115 = F_19 ( 10 ) ;
V_101 = F_57 ( * V_71 ,
( V_19 = F_40 ( V_10 , & V_12 -> V_19 ) ) == V_85 ,
V_115 ) ;
if ( V_85 != V_19 ) {
F_42 ( V_10 , V_85 , & V_12 -> V_19 ) ;
F_58 ( L_29
L_30 , V_108 -> V_13 ) ;
} else if ( V_101 != V_115 )
F_4 ( L_31 ,
F_59 ( V_115 - V_101 ) ) ;
V_85 = ( ( V_85 & 0xfffffffe ) == 0xfffffffe ) ? 1 : V_85 + 1 ;
F_42 ( V_10 , V_2 , & V_12 -> V_2 ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
F_42 ( V_10 , V_5 [ V_3 ] , & V_12 -> args [ V_3 ] ) ;
F_42 ( V_10 , 0 , & V_12 -> error ) ;
F_42 ( V_10 , V_85 , & V_12 -> V_18 ) ;
F_42 ( V_10 , V_85 - 1 , & V_12 -> V_19 ) ;
V_115 = F_19 ( ( V_108 -> V_59 & V_130 ) ? 10 : 20 ) ;
F_60 ( L_32 ,
V_109 , V_108 -> V_13 ) ;
F_61 ( V_71 , & V_116 , V_131 ) ;
F_43 ( V_10 , V_109 , V_132 , V_109 , V_109 ) ;
V_114 = V_49 ;
V_19 = F_40 ( V_10 , & V_12 -> V_19 ) ;
if ( V_19 != V_85 ) {
F_62 ( V_115 ) ;
V_101 = V_49 - V_114 ;
V_19 = F_40 ( V_10 , & V_12 -> V_19 ) ;
} else {
V_101 = V_49 - V_114 ;
}
F_63 ( V_71 , & V_116 ) ;
if ( V_85 != V_19 ) {
F_64 ( V_113 ) ;
if ( V_101 >= V_115 ) {
F_41 ( L_33
L_34 ,
V_108 -> V_13 , F_59 ( V_101 ) ) ;
} else {
F_41 ( L_35
L_36
L_37
L_38 ,
V_108 -> V_13 ,
F_59 ( V_101 ) ,
V_85 , V_19 ) ;
}
return - V_117 ;
}
if ( V_101 >= V_115 )
F_41 ( L_39
L_40 ,
V_108 -> V_13 , F_59 ( V_101 ) ) ;
else
F_55 ( L_41 ,
F_59 ( V_101 ) , V_108 -> V_13 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ )
V_5 [ V_3 ] = F_40 ( V_10 , & V_12 -> args [ V_3 ] ) ;
V_110 = F_40 ( V_10 , & V_12 -> error ) ;
F_64 ( V_113 ) ;
if ( V_108 -> V_59 & V_133 )
F_65 ( 300 , 0 ) ;
if ( V_110 )
F_4 ( L_42 , V_110 ,
V_108 -> V_13 ) ;
return V_110 ? - V_134 : 0 ;
}
int F_66 ( struct V_9 * V_10 , T_1 V_2 , int args , T_1 V_5 [] )
{
return F_53 ( V_10 , V_2 , args , V_5 ) ;
}
static int F_67 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
T_1 V_135 ;
int V_101 ;
V_135 = ( V_10 -> V_136 & 1 ) ? 2 : ( V_10 -> V_137 ? 1 : 0 ) ;
V_101 = F_68 ( V_10 , V_138 , 4 ,
V_21 -> V_54 , 1 , V_135 , V_10 -> V_137 ) ;
V_135 = ( V_10 -> V_136 & 2 ) ? 2 : ( V_10 -> V_139 ? 1 : 0 ) ;
V_101 = V_101 ? V_101 : F_68 ( V_10 , V_138 , 4 ,
V_21 -> V_54 , 0 , V_135 , V_10 -> V_139 ) ;
V_101 = V_101 ? V_101 : F_68 ( V_10 , V_138 , 4 ,
V_21 -> V_54 , 2 , V_10 -> V_136 >> 2 , 0 ) ;
return V_101 ;
}
int F_69 ( void * V_140 , T_1 V_2 , int V_141 , int V_37 ,
T_1 V_5 [ V_142 ] )
{
struct V_20 * V_21 = V_140 ;
struct V_9 * V_10 = V_21 -> V_10 ;
switch ( V_2 ) {
case V_143 :
return 0 ;
case V_144 :
return F_68 ( V_10 , V_145 , 6 ,
V_21 -> V_54 , 0 , 0 , 0 , 0 , V_5 [ 0 ] ) ;
case V_146 :
return F_68 ( V_10 , V_147 , 3 ,
V_21 -> V_54 , V_5 [ 1 ] , V_5 [ 0 ] ) ;
case V_148 :
return F_68 ( V_10 , V_149 , 2 ,
V_21 -> V_54 , V_5 [ 0 ] ) ;
case V_150 :
return F_68 ( V_10 , V_151 , 2 ,
V_21 -> V_54 , V_5 [ 0 ] ) ;
case V_152 :
return F_68 ( V_10 , V_153 , 3 ,
V_21 -> V_54 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
case V_154 :
return 0 ;
case V_155 :
return F_68 ( V_10 , V_156 , 2 ,
V_21 -> V_54 , V_5 [ 0 ] ) ;
case V_157 :
return F_68 ( V_10 , V_158 , 2 ,
V_21 -> V_54 , V_5 [ 0 ] ) ;
case V_159 :
return F_68 ( V_10 , V_160 , 5 ,
V_21 -> V_54 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
case V_161 :
return F_68 ( V_10 , V_162 , 2 ,
V_21 -> V_54 , V_5 [ 0 ] ) ;
case V_163 :
return F_68 ( V_10 , V_164 , 2 ,
V_21 -> V_54 , V_5 [ 0 ] ) ;
case V_165 :
return F_68 ( V_10 , V_166 , 4 ,
V_21 -> V_54 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
case V_167 :
V_10 -> V_136 = ( V_5 [ 0 ] & 3 ) | ( V_5 [ 1 ] << 2 ) ;
return F_67 ( V_21 ) ;
case V_168 :
V_10 -> V_137 = V_5 [ 0 ] ;
V_10 -> V_139 = V_5 [ 1 ] ;
return F_67 ( V_21 ) ;
case V_169 :
return F_68 ( V_10 , V_170 , 3 ,
V_21 -> V_54 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
case V_171 :
return F_68 ( V_10 , V_172 , 5 ,
V_21 -> V_54 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
}
F_24 ( L_43 , V_2 ) ;
return 0 ;
}
int F_70 ( struct V_9 * V_10 , T_1 V_5 [ V_15 ] ,
T_1 V_2 , int args , ... )
{
T_5 V_173 ;
int V_3 ;
va_start ( V_173 , args ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
V_5 [ V_3 ] = va_arg ( V_173 , T_1 ) ;
va_end ( V_173 ) ;
return F_66 ( V_10 , V_2 , args , V_5 ) ;
}
int F_68 ( struct V_9 * V_10 , T_1 V_2 , int args , ... )
{
T_1 V_5 [ V_15 ] ;
T_5 V_173 ;
int V_3 ;
if ( V_10 == NULL ) {
F_58 ( L_44 , V_2 ) ;
return 0 ;
}
if ( args > V_15 ) {
F_58 ( L_45 , V_2 ) ;
args = V_15 ;
}
va_start ( V_173 , args ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
V_5 [ V_3 ] = va_arg ( V_173 , T_1 ) ;
va_end ( V_173 ) ;
return F_66 ( V_10 , V_2 , args , V_5 ) ;
}
