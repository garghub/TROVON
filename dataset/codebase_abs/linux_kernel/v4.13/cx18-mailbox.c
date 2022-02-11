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
F_4 ( L_2 ,
V_13 , V_12 -> V_18 , V_12 -> V_19 , V_12 -> V_2 , V_12 -> error ,
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
F_14 ( & V_32 -> V_38 . V_43 ) ;
F_15 ( & V_32 -> V_38 . V_39 ) ;
V_32 -> V_38 . V_44 = V_45 ;
F_16 ( & V_32 -> V_38 . V_46 ) ;
}
F_17 ( & V_21 -> V_47 , F_18 ( 2000 ) + V_48 ) ;
V_37:
F_19 ( & V_21 -> V_35 ) ;
}
static void F_20 ( struct V_9 * V_10 , struct V_20 * V_21 ,
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
static void F_21 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
T_1 V_53 , V_54 , V_55 ;
struct V_11 * V_12 ;
struct V_56 * V_57 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_3 ;
V_12 = & V_52 -> V_12 ;
V_53 = V_12 -> args [ 0 ] ;
V_21 = F_22 ( V_10 , V_53 ) ;
if ( V_21 == NULL ) {
F_23 ( L_3 ,
V_53 ,
( V_52 -> V_58 & V_59 ) ?
L_4 : L_5 , V_12 -> V_18 ) ;
return;
}
V_54 = V_12 -> args [ 2 ] ;
V_57 = V_52 -> V_57 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ , V_57 ++ ) {
V_55 = V_57 -> V_55 ;
if ( ( V_52 -> V_58 & V_59 ) &&
! ( V_55 >= V_21 -> V_60 &&
V_55 < ( V_21 -> V_60 + V_21 -> V_61 ) ) ) {
F_23 ( L_6 ,
V_12 -> V_18 ) ;
break;
}
V_23 = F_24 ( V_21 , V_55 , V_57 -> V_62 ) ;
F_25 ( L_7 , V_21 -> V_13 , V_55 ) ;
if ( V_23 == NULL ) {
F_23 ( L_8 ,
V_55 , V_21 -> V_13 ) ;
continue;
}
F_25 ( L_9 ,
V_21 -> V_13 , V_23 -> V_27 ) ;
if ( V_21 -> type == V_63 ) {
F_5 ( V_21 , V_23 ) ;
F_26 ( V_21 , V_23 , & V_21 -> V_64 ) ;
} else if ( V_21 -> type == V_65 ) {
if ( V_10 -> V_49 != NULL ) {
F_20 ( V_10 , V_21 , V_23 ) ;
F_26 ( V_21 , V_23 , & V_21 -> V_64 ) ;
} else {
F_26 ( V_21 , V_23 , & V_21 -> V_66 ) ;
}
} else if ( V_21 -> type == V_67 ) {
F_10 ( V_21 , V_23 ) ;
F_26 ( V_21 , V_23 , & V_21 -> V_64 ) ;
} else {
F_26 ( V_21 , V_23 , & V_21 -> V_66 ) ;
if ( V_21 -> type == V_68 )
F_27 ( V_10 ) ;
}
}
F_28 ( V_21 ) ;
F_16 ( & V_10 -> V_69 ) ;
if ( V_21 -> V_55 != - 1 )
F_16 ( & V_21 -> V_70 ) ;
}
static void F_29 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
char * V_8 ;
char * V_71 = V_52 -> V_71 ;
F_30 ( L_10 , V_52 -> V_12 . args [ 0 ] , V_71 ) ;
V_8 = strchr ( V_71 , '.' ) ;
if ( ! F_31 ( V_72 , & V_10 -> V_73 ) && V_8 && V_8 > V_71 )
F_32 ( L_11 , V_8 - 1 ) ;
}
static void F_33 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
switch ( V_52 -> V_74 ) {
case V_75 :
{
switch ( V_52 -> V_12 . V_2 ) {
case V_76 :
F_21 ( V_10 , V_52 ) ;
break;
case V_77 :
F_29 ( V_10 , V_52 ) ;
break;
default:
F_23 ( L_12 ,
V_52 -> V_12 . V_2 ) ;
break;
}
break;
}
case V_78 :
F_23 ( L_13 ,
V_52 -> V_12 . V_2 ) ;
break;
default:
break;
}
}
static
void F_34 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
F_35 ( & V_52 -> V_79 , 0 ) ;
}
void F_36 ( struct V_80 * V_81 )
{
struct V_51 * V_52 =
F_37 ( V_81 , struct V_51 , V_81 ) ;
struct V_9 * V_10 = V_52 -> V_10 ;
F_33 ( V_10 , V_52 ) ;
F_34 ( V_10 , V_52 ) ;
}
static void F_38 ( struct V_9 * V_10 , struct V_51 * V_52 )
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
F_23 ( L_14 ,
V_52 -> V_74 , V_52 -> V_12 . V_2 ) ;
return;
}
V_84 = V_52 -> V_12 . V_18 ;
if ( V_84 != F_39 ( V_10 , & V_82 -> V_18 ) ||
V_84 == F_39 ( V_10 , & V_82 -> V_19 ) ) {
F_40 ( L_15 ,
V_90 [ V_52 -> V_74 ] , V_90 [ V_52 -> V_74 ] , V_84 ) ;
V_52 -> V_58 |= V_91 ;
return;
}
F_41 ( V_10 , V_84 , & V_82 -> V_19 ) ;
F_42 ( V_10 , V_83 , V_92 , V_83 , V_83 ) ;
return;
}
static int F_43 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
T_1 V_53 , V_93 , V_54 ;
struct V_11 * V_12 ;
int V_3 ;
V_12 = & V_52 -> V_12 ;
V_53 = V_12 -> args [ 0 ] ;
V_93 = V_12 -> args [ 1 ] ;
V_54 = V_12 -> args [ 2 ] ;
if ( V_53 == V_94 ||
V_54 == 0 || V_54 > V_95 ) {
if ( ( V_52 -> V_58 & V_96 ) == 0 )
F_38 ( V_10 , V_52 ) ;
return - 1 ;
}
for ( V_3 = 0 ; V_3 < sizeof( struct V_56 ) * V_54 ; V_3 += sizeof( T_1 ) )
( ( T_1 * ) V_52 -> V_57 ) [ V_3 / sizeof( T_1 ) ] =
F_39 ( V_10 , V_10 -> V_97 + V_93 + V_3 ) ;
if ( ( V_52 -> V_58 & V_96 ) == 0 )
F_38 ( V_10 , V_52 ) ;
return 1 ;
}
static
int F_44 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
T_1 V_98 ;
char * V_71 = V_52 -> V_71 ;
V_71 [ 0 ] = '\0' ;
V_98 = V_52 -> V_12 . args [ 1 ] ;
if ( V_98 ) {
F_45 ( V_10 , V_98 ) ;
F_46 ( V_10 , V_71 , V_10 -> V_97 + V_98 , 252 ) ;
V_71 [ 252 ] = '\0' ;
F_45 ( V_10 , V_99 ) ;
}
if ( ( V_52 -> V_58 & V_96 ) == 0 )
F_38 ( V_10 , V_52 ) ;
return V_98 ? 1 : 0 ;
}
static inline
int F_47 ( struct V_9 * V_10 , struct V_51 * V_52 )
{
int V_100 = - 1 ;
switch ( V_52 -> V_74 ) {
case V_75 :
{
switch ( V_52 -> V_12 . V_2 ) {
case V_76 :
V_100 = F_43 ( V_10 , V_52 ) ;
break;
case V_77 :
V_100 = F_44 ( V_10 , V_52 ) ;
break;
default:
F_23 ( L_12 ,
V_52 -> V_12 . V_2 ) ;
break;
}
break;
}
case V_78 :
F_23 ( L_13 ,
V_52 -> V_12 . V_2 ) ;
break;
default:
break;
}
return V_100 ;
}
static inline
struct V_51 * F_48 ( struct V_9 * V_10 )
{
int V_3 ;
struct V_51 * V_52 = NULL ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
if ( F_49 ( & V_10 -> V_102 [ V_3 ] . V_79 ) == 0 ) {
V_52 = & V_10 -> V_102 [ V_3 ] ;
F_35 ( & V_52 -> V_79 , 1 ) ;
break;
}
}
return V_52 ;
}
void F_50 ( struct V_9 * V_10 , int V_74 )
{
struct V_11 T_3 * V_12 ;
struct V_11 * V_103 ;
struct V_51 * V_52 ;
int V_104 ;
int V_3 ;
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
V_52 = F_48 ( V_10 ) ;
if ( V_52 == NULL ) {
F_23 ( L_16 ) ;
return;
}
V_52 -> V_58 = 0 ;
V_52 -> V_74 = V_74 ;
V_103 = & V_52 -> V_12 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
( & V_103 -> V_2 ) [ V_3 ] = F_39 ( V_10 , & V_12 -> V_2 + V_3 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
( & V_103 -> V_18 ) [ V_3 ] = F_39 ( V_10 , & V_12 -> V_18 + V_3 ) ;
if ( V_103 -> V_18 == V_103 -> V_19 ) {
F_40 ( L_17 ,
V_90 [ V_74 ] , V_90 [ V_74 ] , V_103 -> V_18 ) ;
if ( V_16 & V_105 )
F_3 ( V_10 , V_103 , L_18 ) ;
V_52 -> V_58 = V_59 ;
}
V_104 = F_47 ( V_10 , V_52 ) ;
if ( V_104 > 0 ) {
F_51 ( V_10 -> V_106 , & V_52 -> V_81 ) ;
}
}
static int F_52 ( struct V_9 * V_10 , T_1 V_2 , int args , T_1 V_5 [] )
{
const struct V_1 * V_107 = F_1 ( V_2 ) ;
T_1 V_108 , V_84 , V_19 , V_109 ;
struct V_11 T_3 * V_12 ;
T_4 * V_70 ;
struct V_110 * V_111 ;
unsigned long int V_112 , V_113 , V_100 ;
int V_3 ;
char V_14 [ V_15 * 11 + 1 ] ;
F_53 ( V_114 ) ;
if ( V_107 == NULL ) {
F_23 ( L_19 , V_2 ) ;
return - V_115 ;
}
if ( V_16 & V_17 ) {
if ( V_2 == V_116 ) {
if ( V_16 & V_117 )
F_54 ( L_20 ,
V_107 -> V_13 , V_2 ,
F_2 ( V_5 , args , V_14 ) ) ;
} else
F_4 ( L_20 ,
V_107 -> V_13 , V_2 ,
F_2 ( V_5 , args , V_14 ) ) ;
}
switch ( V_107 -> V_74 ) {
case V_78 :
V_70 = & V_10 -> V_118 ;
V_111 = & V_10 -> V_119 ;
V_108 = V_120 ;
V_12 = & V_10 -> V_86 -> V_121 ;
break;
case V_75 :
V_70 = & V_10 -> V_122 ;
V_111 = & V_10 -> V_123 ;
V_108 = V_124 ;
V_12 = & V_10 -> V_86 -> V_125 ;
break;
default:
F_23 ( L_21 , V_107 -> V_74 ) ;
return - V_115 ;
}
F_55 ( V_111 ) ;
V_84 = F_39 ( V_10 , & V_12 -> V_18 ) ;
V_113 = F_18 ( 10 ) ;
V_100 = F_56 ( * V_70 ,
( V_19 = F_39 ( V_10 , & V_12 -> V_19 ) ) == V_84 ,
V_113 ) ;
if ( V_84 != V_19 ) {
F_41 ( V_10 , V_84 , & V_12 -> V_19 ) ;
F_57 ( L_22 ,
V_107 -> V_13 ) ;
} else if ( V_100 != V_113 )
F_4 ( L_23 ,
F_58 ( V_113 - V_100 ) ) ;
V_84 = ( ( V_84 & 0xfffffffe ) == 0xfffffffe ) ? 1 : V_84 + 1 ;
F_41 ( V_10 , V_2 , & V_12 -> V_2 ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
F_41 ( V_10 , V_5 [ V_3 ] , & V_12 -> args [ V_3 ] ) ;
F_41 ( V_10 , 0 , & V_12 -> error ) ;
F_41 ( V_10 , V_84 , & V_12 -> V_18 ) ;
F_41 ( V_10 , V_84 - 1 , & V_12 -> V_19 ) ;
V_113 = F_18 ( ( V_107 -> V_58 & V_126 ) ? 10 : 20 ) ;
F_59 ( L_24 ,
V_108 , V_107 -> V_13 ) ;
F_60 ( V_70 , & V_114 , V_127 ) ;
F_42 ( V_10 , V_108 , V_128 , V_108 , V_108 ) ;
V_112 = V_48 ;
V_19 = F_39 ( V_10 , & V_12 -> V_19 ) ;
if ( V_19 != V_84 ) {
F_61 ( V_113 ) ;
V_100 = V_48 - V_112 ;
V_19 = F_39 ( V_10 , & V_12 -> V_19 ) ;
} else {
V_100 = V_48 - V_112 ;
}
F_62 ( V_70 , & V_114 ) ;
if ( V_84 != V_19 ) {
F_63 ( V_111 ) ;
if ( V_100 >= V_113 ) {
F_40 ( L_25 ,
V_107 -> V_13 , F_58 ( V_100 ) ) ;
} else {
F_40 ( L_26 ,
V_107 -> V_13 ,
F_58 ( V_100 ) ,
V_84 , V_19 ) ;
}
return - V_115 ;
}
if ( V_100 >= V_113 )
F_40 ( L_27 ,
V_107 -> V_13 , F_58 ( V_100 ) ) ;
else
F_54 ( L_28 ,
F_58 ( V_100 ) , V_107 -> V_13 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ )
V_5 [ V_3 ] = F_39 ( V_10 , & V_12 -> args [ V_3 ] ) ;
V_109 = F_39 ( V_10 , & V_12 -> error ) ;
F_63 ( V_111 ) ;
if ( V_107 -> V_58 & V_129 )
F_64 ( 300 , 0 ) ;
if ( V_109 )
F_4 ( L_29 , V_109 ,
V_107 -> V_13 ) ;
return V_109 ? - V_130 : 0 ;
}
int F_65 ( struct V_9 * V_10 , T_1 V_2 , int args , T_1 V_5 [] )
{
return F_52 ( V_10 , V_2 , args , V_5 ) ;
}
static int F_66 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
T_1 V_131 ;
int V_100 ;
V_131 = ( V_10 -> V_132 & 1 ) ? 2 : ( V_10 -> V_133 ? 1 : 0 ) ;
V_100 = F_67 ( V_10 , V_134 , 4 ,
V_21 -> V_53 , 1 , V_131 , V_10 -> V_133 ) ;
V_131 = ( V_10 -> V_132 & 2 ) ? 2 : ( V_10 -> V_135 ? 1 : 0 ) ;
V_100 = V_100 ? V_100 : F_67 ( V_10 , V_134 , 4 ,
V_21 -> V_53 , 0 , V_131 , V_10 -> V_135 ) ;
V_100 = V_100 ? V_100 : F_67 ( V_10 , V_134 , 4 ,
V_21 -> V_53 , 2 , V_10 -> V_132 >> 2 , 0 ) ;
return V_100 ;
}
int F_68 ( void * V_136 , T_1 V_2 , int V_137 , int V_37 ,
T_1 V_5 [ V_138 ] )
{
struct V_20 * V_21 = V_136 ;
struct V_9 * V_10 = V_21 -> V_10 ;
switch ( V_2 ) {
case V_139 :
return 0 ;
case V_140 :
return F_67 ( V_10 , V_141 , 6 ,
V_21 -> V_53 , 0 , 0 , 0 , 0 , V_5 [ 0 ] ) ;
case V_142 :
return F_67 ( V_10 , V_143 , 3 ,
V_21 -> V_53 , V_5 [ 1 ] , V_5 [ 0 ] ) ;
case V_144 :
return F_67 ( V_10 , V_145 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_146 :
return F_67 ( V_10 , V_147 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_148 :
return F_67 ( V_10 , V_149 , 3 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
case V_150 :
return 0 ;
case V_151 :
return F_67 ( V_10 , V_152 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_153 :
return F_67 ( V_10 , V_154 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_155 :
return F_67 ( V_10 , V_156 , 5 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
case V_157 :
return F_67 ( V_10 , V_158 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_159 :
return F_67 ( V_10 , V_160 , 2 ,
V_21 -> V_53 , V_5 [ 0 ] ) ;
case V_161 :
return F_67 ( V_10 , V_162 , 4 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
case V_163 :
V_10 -> V_132 = ( V_5 [ 0 ] & 3 ) | ( V_5 [ 1 ] << 2 ) ;
return F_66 ( V_21 ) ;
case V_164 :
V_10 -> V_133 = V_5 [ 0 ] ;
V_10 -> V_135 = V_5 [ 1 ] ;
return F_66 ( V_21 ) ;
case V_165 :
return F_67 ( V_10 , V_166 , 3 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
case V_167 :
return F_67 ( V_10 , V_168 , 5 ,
V_21 -> V_53 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
}
F_23 ( L_30 , V_2 ) ;
return 0 ;
}
int F_69 ( struct V_9 * V_10 , T_1 V_5 [ V_15 ] ,
T_1 V_2 , int args , ... )
{
T_5 V_169 ;
int V_3 ;
va_start ( V_169 , args ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
V_5 [ V_3 ] = va_arg ( V_169 , T_1 ) ;
va_end ( V_169 ) ;
return F_65 ( V_10 , V_2 , args , V_5 ) ;
}
int F_67 ( struct V_9 * V_10 , T_1 V_2 , int args , ... )
{
T_1 V_5 [ V_15 ] ;
T_5 V_169 ;
int V_3 ;
if ( V_10 == NULL ) {
F_57 ( L_31 , V_2 ) ;
return 0 ;
}
if ( args > V_15 ) {
F_57 ( L_32 , V_2 ) ;
args = V_15 ;
}
va_start ( V_169 , args ) ;
for ( V_3 = 0 ; V_3 < args ; V_3 ++ )
V_5 [ V_3 ] = va_arg ( V_169 , T_1 ) ;
va_end ( V_169 ) ;
return F_65 ( V_10 , V_2 , args , V_5 ) ;
}
