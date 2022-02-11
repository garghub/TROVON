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
if ( V_32 -> V_40 >= V_21 -> V_42 ) {
V_34 = 1 ;
V_32 -> V_40 = 0 ;
}
if ( V_34 ) {
V_32 -> V_38 . V_43 = F_14 ( F_15 () ) ;
F_16 ( & V_32 -> V_38 . V_39 ) ;
V_32 -> V_38 . V_44 = V_45 ;
F_17 ( & V_32 -> V_38 . V_46 ) ;
}
F_18 ( & V_21 -> V_47 , F_19 ( 2000 ) + V_48 ) ;
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
V_10 -> V_49 ( V_10 -> V_50 , V_7 -> V_7 ,
V_7 -> V_27 ) ;
return;
}
F_9 (buf, &mdl->buf_list, list) {
if ( V_7 -> V_27 == 0 )
break;
V_10 -> V_49 ( V_10 -> V_50 , V_7 -> V_7 , V_7 -> V_27 ) ;
}
}
static void F_22 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
T_1 V_53 , V_54 , V_55 ;
struct V_11 * V_12 ;
struct V_56 * V_57 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_3 ;
V_12 = & V_52 -> V_12 ;
V_53 = V_12 -> args [ 0 ] ;
V_21 = F_23 ( V_10 , V_53 ) ;
if ( V_21 == NULL ) {
F_24 ( L_4
L_5 , V_53 ,
( V_52 -> V_58 & V_59 ) ?
L_6 : L_7 , V_12 -> V_18 ) ;
return;
}
V_54 = V_12 -> args [ 2 ] ;
V_57 = V_52 -> V_57 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ , V_57 ++ ) {
V_55 = V_57 -> V_55 ;
if ( ( V_52 -> V_58 & V_59 ) &&
! ( V_55 >= V_21 -> V_60 &&
V_55 < ( V_21 -> V_60 + V_21 -> V_61 ) ) ) {
F_24 ( L_8
L_9
L_10 , V_12 -> V_18 ) ;
break;
}
V_23 = F_25 ( V_21 , V_55 , V_57 -> V_62 ) ;
F_26 ( L_11 , V_21 -> V_13 , V_55 ) ;
if ( V_23 == NULL ) {
F_24 ( L_12 ,
V_55 , V_21 -> V_13 ) ;
continue;
}
F_26 ( L_13 ,
V_21 -> V_13 , V_23 -> V_27 ) ;
if ( V_21 -> type == V_63 ) {
F_5 ( V_21 , V_23 ) ;
F_27 ( V_21 , V_23 , & V_21 -> V_64 ) ;
} else if ( V_21 -> type == V_65 ) {
if ( V_10 -> V_49 != NULL ) {
F_21 ( V_10 , V_21 , V_23 ) ;
F_27 ( V_21 , V_23 , & V_21 -> V_64 ) ;
} else {
F_27 ( V_21 , V_23 , & V_21 -> V_66 ) ;
}
} else if ( V_21 -> type == V_67 ) {
F_10 ( V_21 , V_23 ) ;
F_27 ( V_21 , V_23 , & V_21 -> V_64 ) ;
} else {
F_27 ( V_21 , V_23 , & V_21 -> V_66 ) ;
if ( V_21 -> type == V_68 )
F_28 ( V_10 ) ;
}
}
F_29 ( V_21 ) ;
F_17 ( & V_10 -> V_69 ) ;
if ( V_21 -> V_55 != - 1 )
F_17 ( & V_21 -> V_70 ) ;
}
static void F_30 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
char * V_8 ;
char * V_71 = V_52 -> V_71 ;
F_31 ( L_14 , V_52 -> V_12 . args [ 0 ] , V_71 ) ;
V_8 = strchr ( V_71 , '.' ) ;
if ( ! F_32 ( V_72 , & V_10 -> V_73 ) && V_8 && V_8 > V_71 )
F_33 ( L_15 , V_8 - 1 ) ;
}
static void F_34 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
switch ( V_52 -> V_74 ) {
case V_75 :
{
switch ( V_52 -> V_12 . V_2 ) {
case V_76 :
F_22 ( V_10 , V_52 ) ;
break;
case V_77 :
F_30 ( V_10 , V_52 ) ;
break;
default:
F_24 ( L_16 ,
V_52 -> V_12 . V_2 ) ;
break;
}
break;
}
case V_78 :
F_24 ( L_17 ,
V_52 -> V_12 . V_2 ) ;
break;
default:
break;
}
}
static
void F_35 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
F_36 ( & V_52 -> V_79 , 0 ) ;
}
void F_37 ( struct V_80 * V_81 )
{
struct V_51 * V_52 =
F_38 ( V_81 , struct V_51 , V_81 ) ;
struct V_9 * V_10 = V_52 -> V_10 ;
F_34 ( V_10 , V_52 ) ;
F_35 ( V_10 , V_52 ) ;
}
static void F_39 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
struct V_11 T_3 * V_82 ;
T_1 V_83 , V_84 ;
switch ( V_52 -> V_74 ) {
case V_78 :
V_83 = V_85 ;
V_82 = & V_10 -> V_86 -> V_87 ;
break;
case V_75 :
V_83 = V_88 ;
V_82 = & V_10 -> V_86 -> V_89 ;
break;
default:
F_24 ( L_18 ,
V_52 -> V_74 , V_52 -> V_12 . V_2 ) ;
return;
}
V_84 = V_52 -> V_12 . V_18 ;
if ( V_84 != F_40 ( V_10 , & V_82 -> V_18 ) ||
V_84 == F_40 ( V_10 , & V_82 -> V_19 ) ) {
F_41 ( L_19
L_20
L_21 ,
V_90 [ V_52 -> V_74 ] , V_90 [ V_52 -> V_74 ] , V_84 ) ;
V_52 -> V_58 |= V_91 ;
return;
}
F_42 ( V_10 , V_84 , & V_82 -> V_19 ) ;
F_43 ( V_10 , V_83 , V_92 , V_83 , V_83 ) ;
return;
}
static int F_44 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
T_1 V_53 , V_93 , V_54 ;
struct V_11 * V_12 ;
V_12 = & V_52 -> V_12 ;
V_53 = V_12 -> args [ 0 ] ;
V_93 = V_12 -> args [ 1 ] ;
V_54 = V_12 -> args [ 2 ] ;
if ( V_53 == V_94 ||
V_54 == 0 || V_54 > V_95 ) {
if ( ( V_52 -> V_58 & V_96 ) == 0 )
F_39 ( V_10 , V_52 ) ;
return - 1 ;
}
F_45 ( V_10 , V_52 -> V_57 , V_10 -> V_97 + V_93 ,
sizeof( struct V_56 ) * V_54 ) ;
if ( ( V_52 -> V_58 & V_96 ) == 0 )
F_39 ( V_10 , V_52 ) ;
return 1 ;
}
static
int F_46 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
T_1 V_98 ;
char * V_71 = V_52 -> V_71 ;
V_71 [ 0 ] = '\0' ;
V_98 = V_52 -> V_12 . args [ 1 ] ;
if ( V_98 ) {
F_47 ( V_10 , V_98 ) ;
F_45 ( V_10 , V_71 , V_10 -> V_97 + V_98 , 252 ) ;
V_71 [ 252 ] = '\0' ;
F_47 ( V_10 , V_99 ) ;
}
if ( ( V_52 -> V_58 & V_96 ) == 0 )
F_39 ( V_10 , V_52 ) ;
return V_98 ? 1 : 0 ;
}
static inline
int F_48 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
int V_100 = - 1 ;
switch ( V_52 -> V_74 ) {
case V_75 :
{
switch ( V_52 -> V_12 . V_2 ) {
case V_76 :
V_100 = F_44 ( V_10 , V_52 ) ;
break;
case V_77 :
V_100 = F_46 ( V_10 , V_52 ) ;
break;
default:
F_24 ( L_16 ,
V_52 -> V_12 . V_2 ) ;
break;
}
break;
}
case V_78 :
F_24 ( L_17 ,
V_52 -> V_12 . V_2 ) ;
break;
default:
break;
}
return V_100 ;
}
static inline
struct V_51 * F_49 ( struct V_9 * V_10 )
{
int V_3 ;
struct V_51 * V_52 = NULL ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
if ( F_50 ( & V_10 -> V_102 [ V_3 ] . V_79 ) == 0 ) {
V_52 = & V_10 -> V_102 [ V_3 ] ;
F_36 ( & V_52 -> V_79 , 1 ) ;
break;
}
}
return V_52 ;
}
void F_51 ( struct V_9 * V_10 , int V_74 )
{
struct V_11 T_3 * V_12 ;
struct V_11 * V_103 ;
struct V_51 * V_52 ;
int V_104 ;
switch ( V_74 ) {
case V_75 :
V_12 = & V_10 -> V_86 -> V_89 ;
break;
case V_78 :
V_12 = & V_10 -> V_86 -> V_87 ;
break;
default:
return;
}
V_52 = F_49 ( V_10 ) ;
if ( V_52 == NULL ) {
F_24 ( L_22
L_23 ) ;
return;
}
V_52 -> V_58 = 0 ;
V_52 -> V_74 = V_74 ;
V_103 = & V_52 -> V_12 ;
F_45 ( V_10 , & V_103 -> V_2 , & V_12 -> V_2 , 4 * sizeof( T_1 ) ) ;
F_45 ( V_10 , & V_103 -> V_18 , & V_12 -> V_18 ,
2 * sizeof( T_1 ) ) ;
if ( V_103 -> V_18 == V_103 -> V_19 ) {
F_41 ( L_19
L_24
L_3 ,
V_90 [ V_74 ] , V_90 [ V_74 ] , V_103 -> V_18 ) ;
if ( V_16 & V_105 )
F_3 ( V_10 , V_103 , L_25 ) ;
V_52 -> V_58 = V_59 ;
}
V_104 = F_48 ( V_10 , V_52 ) ;
if ( V_104 > 0 ) {
F_52 ( V_10 -> V_106 , & V_52 -> V_81 ) ;
}
}
static int F_53 ( struct V_9 * V_10 , T_1 V_2 , int args , T_1 V_5 [] )
{
const struct V_1 * V_107 = F_1 ( V_2 ) ;
T_1 V_44 , V_108 , V_84 , V_19 , V_109 ;
struct V_11 T_3 * V_12 ;
T_1 T_3 * V_110 ;
T_4 * V_70 ;
struct V_111 * V_112 ;
unsigned long int V_113 , V_114 , V_100 ;
int V_3 ;
char V_14 [ V_15 * 11 + 1 ] ;
F_54 ( V_115 ) ;
if ( V_107 == NULL ) {
F_24 ( L_26 , V_2 ) ;
return - V_116 ;
}
if ( V_16 & V_17 ) {
if ( V_2 == V_117 ) {
if ( V_16 & V_118 )
F_55 ( L_27 ,
V_107 -> V_13 , V_2 ,
F_2 ( V_5 , args , V_14 ) ) ;
} else
F_4 ( L_27 ,
V_107 -> V_13 , V_2 ,
F_2 ( V_5 , args , V_14 ) ) ;
}
switch ( V_107 -> V_74 ) {
case V_78 :
V_70 = & V_10 -> V_119 ;
V_112 = & V_10 -> V_120 ;
V_108 = V_121 ;
V_12 = & V_10 -> V_86 -> V_122 ;
V_110 = & V_10 -> V_86 -> V_123 ;
break;
case V_75 :
V_70 = & V_10 -> V_124 ;
V_112 = & V_10 -> V_125 ;
V_108 = V_126 ;
V_12 = & V_10 -> V_86 -> V_127 ;
V_110 = & V_10 -> V_86 -> V_128 ;
break;
default:
F_24 ( L_28 , V_107 -> V_74 ) ;
return - V_116 ;
}
F_56 ( V_112 ) ;
V_44 = F_40 ( V_10 , V_110 ) ;
V_84 = F_40 ( V_10 , & V_12 -> V_18 ) ;
V_114 = F_19 ( 10 ) ;
V_100 = F_57 ( * V_70 ,
( V_19 = F_40 ( V_10 , & V_12 -> V_19 ) ) == V_84 ,
V_114 ) ;
if ( V_84 != V_19 ) {
F_42 ( V_10 , V_84 , & V_12 -> V_19 ) ;
F_58 ( L_29
L_30 , V_107 -> V_13 ) ;
} else if ( V_100 != V_114 )
F_4 ( L_31 ,
F_59 ( V_114 - V_100 ) ) ;
V_84 = ( ( V_84 & 0xfffffffe ) == 0xfffffffe ) ? 1 : V_84 + 1 ;
F_42 ( V_10 , V_2 , & V_12 -> V_2 ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
F_42 ( V_10 , V_5 [ V_3 ] , & V_12 -> args [ V_3 ] ) ;
F_42 ( V_10 , 0 , & V_12 -> error ) ;
F_42 ( V_10 , V_84 , & V_12 -> V_18 ) ;
F_42 ( V_10 , V_84 - 1 , & V_12 -> V_19 ) ;
V_114 = F_19 ( ( V_107 -> V_58 & V_129 ) ? 10 : 20 ) ;
F_60 ( L_32 ,
V_108 , V_107 -> V_13 ) ;
F_61 ( V_70 , & V_115 , V_130 ) ;
F_43 ( V_10 , V_108 , V_131 , V_108 , V_108 ) ;
V_113 = V_48 ;
V_19 = F_40 ( V_10 , & V_12 -> V_19 ) ;
if ( V_19 != V_84 ) {
F_62 ( V_114 ) ;
V_100 = V_48 - V_113 ;
V_19 = F_40 ( V_10 , & V_12 -> V_19 ) ;
} else {
V_100 = V_48 - V_113 ;
}
F_63 ( V_70 , & V_115 ) ;
if ( V_84 != V_19 ) {
F_64 ( V_112 ) ;
if ( V_100 >= V_114 ) {
F_41 ( L_33
L_34 ,
V_107 -> V_13 , F_59 ( V_100 ) ) ;
} else {
F_41 ( L_35
L_36
L_37
L_38 ,
V_107 -> V_13 ,
F_59 ( V_100 ) ,
V_84 , V_19 ) ;
}
return - V_116 ;
}
if ( V_100 >= V_114 )
F_41 ( L_39
L_40 ,
V_107 -> V_13 , F_59 ( V_100 ) ) ;
else
F_55 ( L_41 ,
F_59 ( V_100 ) , V_107 -> V_13 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ )
V_5 [ V_3 ] = F_40 ( V_10 , & V_12 -> args [ V_3 ] ) ;
V_109 = F_40 ( V_10 , & V_12 -> error ) ;
F_64 ( V_112 ) ;
if ( V_107 -> V_58 & V_132 )
F_65 ( 300 , 0 ) ;
if ( V_109 )
F_4 ( L_42 , V_109 ,
V_107 -> V_13 ) ;
return V_109 ? - V_133 : 0 ;
}
int F_66 ( struct V_9 * V_10 , T_1 V_2 , int args , T_1 V_5 [] )
{
return F_53 ( V_10 , V_2 , args , V_5 ) ;
}
static int F_67 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
T_1 V_134 ;
int V_100 ;
V_134 = ( V_10 -> V_135 & 1 ) ? 2 : ( V_10 -> V_136 ? 1 : 0 ) ;
V_100 = F_68 ( V_10 , V_137 , 4 ,
V_21 -> V_53 , 1 , V_134 , V_10 -> V_136 ) ;
V_134 = ( V_10 -> V_135 & 2 ) ? 2 : ( V_10 -> V_138 ? 1 : 0 ) ;
V_100 = V_100 ? V_100 : F_68 ( V_10 , V_137 , 4 ,
V_21 -> V_53 , 0 , V_134 , V_10 -> V_138 ) ;
V_100 = V_100 ? V_100 : F_68 ( V_10 , V_137 , 4 ,
V_21 -> V_53 , 2 , V_10 -> V_135 >> 2 , 0 ) ;
return V_100 ;
}
int F_69 ( void * V_139 , T_1 V_2 , int V_140 , int V_37 ,
T_1 V_5 [ V_141 ] )
{
struct V_20 * V_21 = V_139 ;
struct V_9 * V_10 = V_21 -> V_10 ;
switch ( V_2 ) {
case V_142 :
return 0 ;
case V_143 :
return F_68 ( V_10 , V_144 , 6 ,
V_21 -> V_53 , 0 , 0 , 0 , 0 , V_5 [ 0 ] ) ;
case V_145 :
return F_68 ( V_10 , V_146 , 3 ,
V_21 -> V_53 , V_5 [ 1 ] , V_5 [ 0 ] ) ;
case V_147 :
return F_68 ( V_10 , V_148 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_149 :
return F_68 ( V_10 , V_150 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_151 :
return F_68 ( V_10 , V_152 , 3 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
case V_153 :
return 0 ;
case V_154 :
return F_68 ( V_10 , V_155 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_156 :
return F_68 ( V_10 , V_157 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_158 :
return F_68 ( V_10 , V_159 , 5 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
case V_160 :
return F_68 ( V_10 , V_161 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_162 :
return F_68 ( V_10 , V_163 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_164 :
return F_68 ( V_10 , V_165 , 4 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
case V_166 :
V_10 -> V_135 = ( V_5 [ 0 ] & 3 ) | ( V_5 [ 1 ] << 2 ) ;
return F_67 ( V_21 ) ;
case V_167 :
V_10 -> V_136 = V_5 [ 0 ] ;
V_10 -> V_138 = V_5 [ 1 ] ;
return F_67 ( V_21 ) ;
case V_168 :
return F_68 ( V_10 , V_169 , 3 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
case V_170 :
return F_68 ( V_10 , V_171 , 5 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
}
F_24 ( L_43 , V_2 ) ;
return 0 ;
}
int F_70 ( struct V_9 * V_10 , T_1 V_5 [ V_15 ] ,
T_1 V_2 , int args , ... )
{
T_5 V_172 ;
int V_3 ;
va_start ( V_172 , args ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
V_5 [ V_3 ] = va_arg ( V_172 , T_1 ) ;
va_end ( V_172 ) ;
return F_66 ( V_10 , V_2 , args , V_5 ) ;
}
int F_68 ( struct V_9 * V_10 , T_1 V_2 , int args , ... )
{
T_1 V_5 [ V_15 ] ;
T_5 V_172 ;
int V_3 ;
if ( V_10 == NULL ) {
F_58 ( L_44 , V_2 ) ;
return 0 ;
}
if ( args > V_15 ) {
F_58 ( L_45 , V_2 ) ;
args = V_15 ;
}
va_start ( V_172 , args ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
V_5 [ V_3 ] = va_arg ( V_172 , T_1 ) ;
va_end ( V_172 ) ;
return F_66 ( V_10 , V_2 , args , V_5 ) ;
}
