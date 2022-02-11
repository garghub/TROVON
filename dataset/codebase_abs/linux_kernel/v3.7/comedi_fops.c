static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned V_7 )
{
int V_8 ;
if ( V_7 > V_6 -> V_9 )
return - V_10 ;
if ( V_4 -> V_11 ) {
F_2 ( L_1 ) ;
return - V_12 ;
}
if ( V_6 -> V_13 ) {
F_2 ( L_2 ) ;
return - V_12 ;
}
if ( ! V_6 -> V_14 )
return - V_15 ;
V_7 = ( V_7 + V_16 - 1 ) & V_17 ;
V_8 = F_3 ( V_2 , V_4 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_4 -> V_18 ) {
V_8 = V_4 -> V_18 ( V_2 , V_4 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_2 ( L_3 ,
V_2 -> V_19 , ( int ) ( V_4 - V_2 -> V_20 ) , V_6 -> V_21 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_22 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_6 ( V_27 ) ;
unsigned int V_28 = 0 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_31 ) && V_4 -> V_6 )
V_28 = V_4 -> V_6 -> V_9 / 1024 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return snprintf ( V_25 , V_16 , L_4 , V_28 ) ;
}
static T_1 F_9 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_32 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_6 ( V_27 ) ;
unsigned int V_28 ;
int V_33 ;
V_33 = F_10 ( V_25 , 10 , & V_28 ) ;
if ( V_33 )
return V_33 ;
if ( V_28 > ( V_34 / 1024 ) )
return - V_15 ;
V_28 *= 1024 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_31 ) && V_4 -> V_6 )
V_4 -> V_6 -> V_9 = V_28 ;
else
V_33 = - V_15 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return V_33 ? V_33 : V_32 ;
}
static T_1 F_11 ( struct V_22 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_6 ( V_27 ) ;
unsigned int V_28 = 0 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_31 ) && V_4 -> V_6 )
V_28 = V_4 -> V_6 -> V_21 / 1024 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return snprintf ( V_25 , V_16 , L_4 , V_28 ) ;
}
static T_1 F_12 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_32 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_6 ( V_27 ) ;
unsigned int V_28 ;
int V_33 ;
V_33 = F_10 ( V_25 , 10 , & V_28 ) ;
if ( V_33 )
return V_33 ;
if ( V_28 > ( V_34 / 1024 ) )
return - V_15 ;
V_28 *= 1024 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_31 ) && V_4 -> V_6 )
V_33 = F_1 ( V_27 -> V_22 , V_4 , V_4 -> V_6 , V_28 ) ;
else
V_33 = - V_15 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return V_33 ? V_33 : V_32 ;
}
static T_1 F_13 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_14 ( V_27 ) ;
unsigned int V_28 = 0 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_35 ) && V_4 -> V_6 )
V_28 = V_4 -> V_6 -> V_9 / 1024 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return snprintf ( V_25 , V_16 , L_4 , V_28 ) ;
}
static T_1 F_15 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_32 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_14 ( V_27 ) ;
unsigned int V_28 ;
int V_33 ;
V_33 = F_10 ( V_25 , 10 , & V_28 ) ;
if ( V_33 )
return V_33 ;
if ( V_28 > ( V_34 / 1024 ) )
return - V_15 ;
V_28 *= 1024 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_35 ) && V_4 -> V_6 )
V_4 -> V_6 -> V_9 = V_28 ;
else
V_33 = - V_15 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return V_33 ? V_33 : V_32 ;
}
static T_1 F_16 ( struct V_22 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_14 ( V_27 ) ;
unsigned int V_28 = 0 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_35 ) && V_4 -> V_6 )
V_28 = V_4 -> V_6 -> V_21 / 1024 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return snprintf ( V_25 , V_16 , L_4 , V_28 ) ;
}
static T_1 F_17 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_32 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_14 ( V_27 ) ;
unsigned int V_28 ;
int V_33 ;
V_33 = F_10 ( V_25 , 10 , & V_28 ) ;
if ( V_33 )
return V_33 ;
if ( V_28 > ( V_34 / 1024 ) )
return - V_15 ;
V_28 *= 1024 ;
F_7 ( & V_27 -> V_22 -> V_29 ) ;
if ( V_4 && ( V_4 -> V_30 & V_35 ) && V_4 -> V_6 )
V_33 = F_1 ( V_27 -> V_22 , V_4 , V_4 -> V_6 , V_28 ) ;
else
V_33 = - V_15 ;
F_8 ( & V_27 -> V_22 -> V_29 ) ;
return V_33 ? V_33 : V_32 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_36 T_3 * V_37 )
{
struct V_36 V_38 ;
int V_39 ;
unsigned char * V_40 = NULL ;
int V_41 ;
if ( ! F_19 ( V_42 ) )
return - V_10 ;
if ( V_37 == NULL ) {
if ( F_20 ( V_2 ) )
return - V_12 ;
if ( V_2 -> V_43 ) {
struct V_44 * V_45 = V_2 -> V_46 -> V_44 ;
F_21 ( V_2 ) ;
F_22 ( V_45 ) ;
}
return 0 ;
}
if ( F_23 ( & V_38 , V_37 , sizeof( struct V_36 ) ) )
return - V_47 ;
V_38 . V_48 [ V_49 - 1 ] = 0 ;
if ( F_24 ( V_38 . V_50 , 0 ) &&
V_38 . V_50 [ V_51 ] ) {
int V_52 ;
V_41 = V_38 . V_50 [ V_51 ] ;
if ( V_41 < 0 )
return - V_47 ;
V_40 = F_25 ( V_41 ) ;
if ( ! V_40 )
return - V_53 ;
if ( F_23 ( V_40 ,
( unsigned char T_3 *
) F_24 ( V_38 . V_50 , 0 ) , V_41 ) ) {
F_26 ( V_40 ) ;
return - V_47 ;
}
V_38 . V_50 [ V_54 ] =
( unsigned long ) V_40 ;
if ( sizeof( void * ) > sizeof( int ) ) {
V_52 = sizeof( int ) * 8 ;
V_38 . V_50 [ V_55 ] =
( ( unsigned long ) V_40 ) >> V_52 ;
} else
V_38 . V_50 [ V_55 ] = 0 ;
}
V_39 = F_27 ( V_2 , & V_38 ) ;
if ( V_39 == 0 ) {
if ( ! F_28 ( V_2 -> V_46 -> V_44 ) ) {
F_21 ( V_2 ) ;
V_39 = - V_56 ;
}
}
if ( V_40 )
F_26 ( V_40 ) ;
return V_39 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_57 T_3 * V_37 )
{
struct V_57 V_58 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_8 = 0 ;
if ( F_23 ( & V_58 , V_37 , sizeof( struct V_57 ) ) )
return - V_47 ;
if ( V_58 . V_59 >= V_2 -> V_60 || V_58 . V_59 < 0 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_58 . V_59 ] ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 ) {
F_2 ( L_5 ) ;
V_58 . V_28 = 0 ;
V_58 . V_61 = 0 ;
goto V_62;
}
if ( V_58 . V_61 ) {
if ( ! F_19 ( V_42 ) )
return - V_10 ;
V_6 -> V_9 = V_58 . V_61 ;
}
if ( V_58 . V_28 ) {
V_8 = F_1 ( V_2 , V_4 , V_6 , V_58 . V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_58 . V_28 = V_6 -> V_21 ;
V_58 . V_61 = V_6 -> V_9 ;
V_62:
if ( F_30 ( V_37 , & V_58 , sizeof( struct V_57 ) ) )
return - V_47 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_63 T_3 * V_37 ,
struct V_64 * V_64 )
{
struct V_63 V_65 ;
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_26 * V_68 =
F_33 ( V_19 ) ;
struct V_3 * V_69 =
F_6 ( V_68 ) ;
struct V_3 * V_70 =
F_14 ( V_68 ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_71 = V_72 ;
V_65 . V_73 = V_2 -> V_60 ;
F_34 ( V_65 . V_74 , V_2 -> V_46 -> V_74 , V_49 ) ;
F_34 ( V_65 . V_48 , V_2 -> V_48 , V_49 ) ;
if ( V_69 )
V_65 . V_75 = V_69 - V_2 -> V_20 ;
else
V_65 . V_75 = - 1 ;
if ( V_70 )
V_65 . V_76 = V_70 - V_2 -> V_20 ;
else
V_65 . V_76 = - 1 ;
if ( F_30 ( V_37 , & V_65 , sizeof( struct V_63 ) ) )
return - V_47 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_77 T_3 * V_37 , void * V_64 )
{
int V_39 , V_78 ;
struct V_77 * V_79 , * V_80 ;
struct V_3 * V_4 ;
V_79 =
F_36 ( V_2 -> V_60 , sizeof( struct V_77 ) ,
V_81 ) ;
if ( ! V_79 )
return - V_53 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_60 ; V_78 ++ ) {
V_4 = & V_2 -> V_20 [ V_78 ] ;
V_80 = V_79 + V_78 ;
V_80 -> type = V_4 -> type ;
V_80 -> V_82 = V_4 -> V_82 ;
V_80 -> V_83 = V_4 -> V_30 ;
if ( F_37 ( V_4 ) & V_84 )
V_80 -> V_83 |= V_85 ;
#define F_38 5
V_80 -> V_86 = F_38 ;
V_80 -> V_87 = V_4 -> V_87 ;
V_80 -> V_88 = V_4 -> V_88 ;
if ( V_4 -> V_89 ) {
V_80 -> V_90 =
( V_78 << 24 ) | ( 0 << 16 ) | ( V_4 -> V_89 -> V_91 ) ;
} else {
V_80 -> V_90 = 0 ;
}
V_80 -> V_92 = V_4 -> V_92 ;
if ( V_4 -> V_11 )
V_80 -> V_83 |= V_93 ;
if ( V_4 -> V_11 == V_64 )
V_80 -> V_83 |= V_94 ;
if ( V_4 -> V_95 )
V_80 -> V_83 |= V_96 ;
if ( V_4 -> V_95 == V_64 )
V_80 -> V_83 |= V_97 ;
if ( ! V_4 -> V_88 && V_4 -> V_98 )
V_80 -> V_83 |= V_99 ;
if ( V_4 -> V_100 )
V_80 -> V_83 |= V_101 ;
if ( V_4 -> V_102 )
V_80 -> V_83 |= V_103 ;
if ( V_4 -> V_104 )
V_80 -> V_83 |= V_105 ;
if ( V_4 -> V_106 != & V_107 )
V_80 -> V_108 = V_109 ;
else
V_80 -> V_108 = V_110 ;
V_80 -> V_111 = V_4 -> V_111 ;
}
V_39 = F_30 ( V_37 , V_79 ,
V_2 -> V_60 * sizeof( struct V_77 ) ) ;
F_39 ( V_79 ) ;
return V_39 ? - V_47 : 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_112 T_3 * V_37 )
{
struct V_3 * V_4 ;
struct V_112 V_38 ;
if ( F_23 ( & V_38 , V_37 , sizeof( struct V_112 ) ) )
return - V_47 ;
if ( V_38 . V_113 >= V_2 -> V_60 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_38 . V_113 ] ;
if ( V_38 . V_98 ) {
if ( V_4 -> V_88 || ! V_4 -> V_98 )
return - V_15 ;
if ( F_30 ( V_38 . V_98 , V_4 -> V_98 ,
V_4 -> V_82 * sizeof( unsigned int ) ) )
return - V_47 ;
}
if ( V_38 . V_100 ) {
if ( ! V_4 -> V_100 )
return - V_15 ;
if ( F_30 ( V_38 . V_100 , V_4 -> V_100 ,
V_4 -> V_82 * sizeof( unsigned int ) ) )
return - V_47 ;
}
if ( V_38 . V_114 ) {
int V_78 ;
if ( ! V_4 -> V_102 )
return - V_15 ;
for ( V_78 = 0 ; V_78 < V_4 -> V_82 ; V_78 ++ ) {
int V_115 ;
V_115 = ( V_2 -> V_19 << 28 ) | ( V_38 . V_113 << 24 ) | ( V_78 << 16 ) |
( V_4 -> V_102 [ V_78 ] -> V_91 ) ;
if ( F_41 ( V_115 , V_38 . V_114 + V_78 ) )
return - V_47 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_116 T_3 * V_37 , void * V_64 )
{
struct V_116 V_117 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( F_23 ( & V_117 , V_37 , sizeof( struct V_116 ) ) )
return - V_47 ;
if ( V_117 . V_59 >= V_2 -> V_60 || V_117 . V_59 < 0 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_117 . V_59 ] ;
if ( V_4 -> V_95 && V_4 -> V_95 != V_64 )
return - V_118 ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 ) {
F_2 ( L_5 ) ;
V_117 . V_119 = 0 ;
V_117 . V_120 = 0 ;
V_117 . V_121 = 0 ;
V_117 . V_122 = 0 ;
V_117 . V_123 = 0 ;
V_117 . V_124 = 0 ;
goto V_62;
}
if ( ! V_4 -> V_11 ) {
V_117 . V_123 = 0 ;
V_117 . V_124 = 0 ;
goto V_125;
}
if ( V_4 -> V_11 != V_64 )
return - V_118 ;
if ( V_117 . V_123 && ( V_4 -> V_30 & V_31 ) ) {
V_117 . V_123 = F_43 ( V_6 , V_117 . V_123 ) ;
F_44 ( V_6 , V_117 . V_123 ) ;
if ( ! ( F_37 ( V_4 ) & ( V_126 |
V_84 ) )
&& V_6 -> V_121 == V_6 -> V_122 ) {
F_45 ( V_2 , V_4 ) ;
}
}
if ( V_117 . V_124 && ( V_4 -> V_30 & V_35 ) ) {
V_117 . V_124 =
F_46 ( V_6 , V_117 . V_124 ) ;
F_47 ( V_6 , V_117 . V_124 ) ;
}
V_125:
V_117 . V_121 = V_6 -> V_121 ;
V_117 . V_119 = V_6 -> V_119 ;
V_117 . V_122 = V_6 -> V_122 ;
V_117 . V_120 = V_6 -> V_120 ;
V_62:
if ( F_30 ( V_37 , & V_117 , sizeof( struct V_116 ) ) )
return - V_47 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_127 T_3 * V_37 , void * V_64 )
{
struct V_127 V_128 ;
struct V_129 * V_130 = NULL ;
unsigned int * V_131 = NULL ;
int V_78 = 0 ;
int V_39 = 0 ;
if ( F_23 ( & V_128 , V_37 , sizeof( struct V_127 ) ) )
return - V_47 ;
V_131 = F_49 ( sizeof( unsigned int ) * V_132 , V_81 ) ;
if ( ! V_131 ) {
F_2 ( L_6 ) ;
V_39 = - V_53 ;
goto error;
}
V_130 =
F_36 ( V_128 . V_133 , sizeof( struct V_129 ) , V_81 ) ;
if ( ! V_130 ) {
F_2 ( L_6 ) ;
V_39 = - V_53 ;
goto error;
}
if ( F_23 ( V_130 , V_128 . V_130 ,
sizeof( struct V_129 ) * V_128 . V_133 ) ) {
F_2 ( L_7 ) ;
V_39 = - V_47 ;
goto error;
}
for ( V_78 = 0 ; V_78 < V_128 . V_133 ; V_78 ++ ) {
if ( V_130 [ V_78 ] . V_134 > V_132 ) {
F_2 ( L_8 ) ;
V_39 = - V_15 ;
goto error;
}
if ( V_130 [ V_78 ] . V_135 & V_136 ) {
if ( F_23 ( V_131 , V_130 [ V_78 ] . V_131 ,
V_130 [ V_78 ] . V_134 * sizeof( unsigned int ) ) ) {
F_2 ( L_7 ) ;
V_39 = - V_47 ;
goto error;
}
}
V_39 = F_50 ( V_2 , V_130 + V_78 , V_131 , V_64 ) ;
if ( V_39 < 0 )
goto error;
if ( V_130 [ V_78 ] . V_135 & V_137 ) {
if ( F_30 ( V_130 [ V_78 ] . V_131 , V_131 ,
V_130 [ V_78 ] . V_134 * sizeof( unsigned int ) ) ) {
F_2 ( L_9 ) ;
V_39 = - V_47 ;
goto error;
}
}
if ( F_51 () )
F_52 () ;
}
error:
F_39 ( V_130 ) ;
F_39 ( V_131 ) ;
if ( V_39 < 0 )
return V_39 ;
return V_78 ;
}
static int F_53 ( struct V_129 * V_135 ,
unsigned int * V_131 )
{
if ( V_135 -> V_134 < 1 )
return - V_15 ;
switch ( V_131 [ 0 ] ) {
case V_138 :
case V_139 :
case V_140 :
case V_141 :
if ( V_135 -> V_134 == 1 )
return 0 ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
if ( V_135 -> V_134 == 2 )
return 0 ;
break;
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
if ( V_135 -> V_134 == 3 )
return 0 ;
break;
case V_165 :
case V_166 :
if ( V_135 -> V_134 == 5 )
return 0 ;
break;
default:
F_54 ( L_10 ,
V_131 [ 0 ] ) ;
F_54 ( L_11 ,
V_167 , __FILE__ ) ;
F_54 ( L_12 , V_135 -> V_134 ) ;
return 0 ;
}
return - V_15 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_129 * V_135 ,
unsigned int * V_131 , void * V_64 )
{
struct V_3 * V_4 ;
int V_39 = 0 ;
int V_78 ;
if ( V_135 -> V_135 & V_168 ) {
switch ( V_135 -> V_135 ) {
case V_169 :
{
struct V_170 V_171 ;
if ( V_135 -> V_134 != 2 ) {
V_39 = - V_15 ;
break;
}
F_55 ( & V_171 ) ;
V_131 [ 0 ] = V_171 . V_172 ;
V_131 [ 1 ] = V_171 . V_173 ;
V_39 = 2 ;
break;
}
case V_174 :
if ( V_135 -> V_134 != 1 || V_131 [ 0 ] >= 100000 ) {
V_39 = - V_15 ;
break;
}
F_56 ( V_131 [ 0 ] / 1000 ) ;
V_39 = 1 ;
break;
case V_175 :
if ( V_135 -> V_134 != 1 ) {
V_39 = - V_15 ;
break;
}
if ( V_135 -> V_113 >= V_2 -> V_60 ) {
F_2 ( L_13 ,
V_135 -> V_113 ) ;
V_39 = - V_15 ;
break;
}
V_4 = & V_2 -> V_20 [ V_135 -> V_113 ] ;
if ( ! V_4 -> V_6 ) {
F_2 ( L_14 ) ;
V_39 = - V_15 ;
break;
}
if ( ! V_4 -> V_6 -> V_176 ) {
F_2 ( L_15 ) ;
V_39 = - V_177 ;
break;
}
V_39 = V_4 -> V_6 -> V_176 ( V_2 , V_4 , V_131 [ 0 ] ) ;
if ( V_39 >= 0 )
V_39 = 1 ;
break;
default:
F_2 ( L_16 ) ;
V_39 = - V_15 ;
break;
}
} else {
unsigned int V_88 ;
if ( V_135 -> V_113 >= V_2 -> V_60 ) {
F_2 ( L_17 , V_135 -> V_113 ) ;
V_39 = - V_15 ;
goto V_178;
}
V_4 = & V_2 -> V_20 [ V_135 -> V_113 ] ;
if ( V_4 -> type == V_179 ) {
F_2 ( L_13 , V_135 -> V_113 ) ;
V_39 = - V_180 ;
goto V_178;
}
if ( V_4 -> V_95 && V_4 -> V_95 != V_64 ) {
F_2 ( L_18 ) ;
V_39 = - V_118 ;
goto V_178;
}
V_39 = F_57 ( V_4 , 1 , & V_135 -> V_181 ) ;
if ( V_39 < 0 ) {
V_39 = - V_15 ;
F_2 ( L_19 ) ;
goto V_178;
}
if ( V_4 -> V_11 ) {
V_39 = - V_12 ;
goto V_178;
}
V_4 -> V_11 = & F_50 ;
switch ( V_135 -> V_135 ) {
case V_182 :
V_39 = V_4 -> V_183 ( V_2 , V_4 , V_135 , V_131 ) ;
break;
case V_184 :
V_88 = V_4 -> V_98
? V_4 -> V_98 [ F_58 ( V_135 -> V_181 ) ]
: V_4 -> V_88 ;
for ( V_78 = 0 ; V_78 < V_135 -> V_134 ; ++ V_78 ) {
if ( V_131 [ V_78 ] > V_88 ) {
V_39 = - V_15 ;
F_2 ( L_20 ) ;
break;
}
}
if ( V_39 == 0 )
V_39 = V_4 -> V_185 ( V_2 , V_4 , V_135 , V_131 ) ;
break;
case V_186 :
if ( V_135 -> V_134 != 2 ) {
V_39 = - V_15 ;
} else {
unsigned int V_187 ;
unsigned int V_188 ;
V_188 = V_131 [ 0 ] ;
if ( V_4 -> V_82 <= 32 ) {
V_187 = F_58 ( V_135 -> V_181 ) ;
if ( V_187 > 0 ) {
V_135 -> V_181 = 0 ;
V_131 [ 0 ] <<= V_187 ;
V_131 [ 1 ] <<= V_187 ;
}
} else
V_187 = 0 ;
V_39 = V_4 -> V_106 ( V_2 , V_4 , V_135 , V_131 ) ;
V_131 [ 0 ] = V_188 ;
if ( V_187 > 0 )
V_131 [ 1 ] >>= V_187 ;
}
break;
case V_189 :
V_39 = F_53 ( V_135 , V_131 ) ;
if ( V_39 )
break;
V_39 = V_4 -> V_190 ( V_2 , V_4 , V_135 , V_131 ) ;
break;
default:
V_39 = - V_15 ;
break;
}
V_4 -> V_11 = NULL ;
}
V_178:
return V_39 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_129 T_3 * V_37 , void * V_64 )
{
struct V_129 V_135 ;
unsigned int * V_131 = NULL ;
int V_39 = 0 ;
V_131 = F_49 ( sizeof( unsigned int ) * V_132 , V_81 ) ;
if ( ! V_131 ) {
V_39 = - V_53 ;
goto error;
}
if ( F_23 ( & V_135 , V_37 , sizeof( struct V_129 ) ) ) {
V_39 = - V_47 ;
goto error;
}
if ( V_135 . V_134 > V_132 )
V_135 . V_134 = V_132 ;
if ( V_135 . V_135 & V_136 ) {
if ( F_23 ( V_131 ,
V_135 . V_131 ,
V_135 . V_134 * sizeof( unsigned int ) ) ) {
V_39 = - V_47 ;
goto error;
}
}
V_39 = F_50 ( V_2 , & V_135 , V_131 , V_64 ) ;
if ( V_39 < 0 )
goto error;
if ( V_135 . V_135 & V_137 ) {
if ( F_30 ( V_135 . V_131 ,
V_131 ,
V_135 . V_134 * sizeof( unsigned int ) ) ) {
V_39 = - V_47 ;
goto error;
}
}
V_39 = V_135 . V_134 ;
error:
F_39 ( V_131 ) ;
return V_39 ;
}
static void F_60 ( struct V_3 * V_4 ,
unsigned V_191 , unsigned V_192 )
{
unsigned long V_92 ;
F_61 ( & V_4 -> V_193 , V_92 ) ;
V_4 -> V_194 &= ~ V_191 ;
V_4 -> V_194 |= ( V_192 & V_191 ) ;
F_62 ( & V_4 -> V_193 , V_92 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_195 T_3 * V_37 , void * V_64 )
{
struct V_195 V_196 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_39 = 0 ;
unsigned int T_3 * V_197 ;
if ( F_23 ( & V_196 , V_37 , sizeof( struct V_195 ) ) ) {
F_2 ( L_21 ) ;
return - V_47 ;
}
V_197 = ( unsigned int T_3 * ) V_196 . V_198 ;
if ( V_196 . V_113 >= V_2 -> V_60 ) {
F_2 ( L_22 , V_196 . V_113 ) ;
return - V_199 ;
}
V_4 = & V_2 -> V_20 [ V_196 . V_113 ] ;
V_6 = V_4 -> V_6 ;
if ( V_4 -> type == V_179 ) {
F_2 ( L_23 , V_196 . V_113 ) ;
return - V_180 ;
}
if ( ! V_4 -> V_104 || ! V_4 -> V_200 || ! V_4 -> V_6 ) {
F_2 ( L_24 ,
V_196 . V_113 ) ;
return - V_180 ;
}
if ( V_4 -> V_95 && V_4 -> V_95 != V_64 ) {
F_2 ( L_25 ) ;
return - V_118 ;
}
if ( V_4 -> V_11 ) {
F_2 ( L_26 ) ;
return - V_12 ;
}
V_4 -> V_11 = V_64 ;
if ( V_196 . V_201 > V_4 -> V_87 ) {
F_2 ( L_27 ,
V_196 . V_201 , V_4 -> V_87 ) ;
V_39 = - V_15 ;
goto V_202;
}
if ( V_196 . V_201 < 1 ) {
F_2 ( L_28 ,
V_196 . V_201 ) ;
V_39 = - V_15 ;
goto V_202;
}
V_6 -> V_196 = V_196 ;
V_6 -> V_196 . V_131 = NULL ;
V_6 -> V_196 . V_198 =
F_49 ( V_6 -> V_196 . V_201 * sizeof( int ) , V_81 ) ;
if ( ! V_6 -> V_196 . V_198 ) {
F_2 ( L_29 ) ;
V_39 = - V_53 ;
goto V_202;
}
if ( F_23 ( V_6 -> V_196 . V_198 , V_197 ,
V_6 -> V_196 . V_201 * sizeof( int ) ) ) {
F_2 ( L_30 ) ;
V_39 = - V_47 ;
goto V_202;
}
V_39 = F_57 ( V_4 ,
V_6 -> V_196 . V_201 ,
V_6 -> V_196 . V_198 ) ;
if ( V_39 < 0 ) {
F_2 ( L_31 ) ;
goto V_202;
}
V_39 = V_4 -> V_200 ( V_2 , V_4 , & V_6 -> V_196 ) ;
if ( V_6 -> V_196 . V_92 & V_203 || V_39 ) {
F_2 ( L_32 , V_39 ) ;
V_196 = V_6 -> V_196 ;
V_196 . V_198 = ( unsigned int V_204 * ) V_197 ;
V_196 . V_131 = NULL ;
if ( F_30 ( V_37 , & V_196 , sizeof( struct V_195 ) ) ) {
F_2 ( L_33 ) ;
V_39 = - V_47 ;
goto V_202;
}
V_39 = - V_177 ;
goto V_202;
}
if ( ! V_6 -> V_21 ) {
V_39 = - V_53 ;
F_2 ( L_34 ) ;
goto V_202;
}
F_64 ( V_6 ) ;
V_6 -> V_205 =
V_206 | V_207 | V_208 |
V_209 ;
if ( V_6 -> V_196 . V_92 & V_210 )
V_6 -> V_205 |= V_211 ;
F_60 ( V_4 , ~ 0 , V_212 | V_84 ) ;
V_39 = V_4 -> V_104 ( V_2 , V_4 ) ;
if ( V_39 == 0 )
return 0 ;
V_202:
F_45 ( V_2 , V_4 ) ;
return V_39 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_195 T_3 * V_37 , void * V_64 )
{
struct V_195 V_196 ;
struct V_3 * V_4 ;
int V_39 = 0 ;
unsigned int * V_198 = NULL ;
unsigned int T_3 * V_197 ;
if ( F_23 ( & V_196 , V_37 , sizeof( struct V_195 ) ) ) {
F_2 ( L_21 ) ;
return - V_47 ;
}
V_197 = ( unsigned int T_3 * ) V_196 . V_198 ;
if ( V_196 . V_113 >= V_2 -> V_60 ) {
F_2 ( L_22 , V_196 . V_113 ) ;
return - V_199 ;
}
V_4 = & V_2 -> V_20 [ V_196 . V_113 ] ;
if ( V_4 -> type == V_179 ) {
F_2 ( L_23 , V_196 . V_113 ) ;
return - V_180 ;
}
if ( ! V_4 -> V_104 || ! V_4 -> V_200 ) {
F_2 ( L_24 ,
V_196 . V_113 ) ;
return - V_180 ;
}
if ( V_196 . V_201 > V_4 -> V_87 ) {
F_2 ( L_35 ,
V_196 . V_201 , V_4 -> V_87 ) ;
V_39 = - V_15 ;
goto V_202;
}
if ( V_196 . V_198 ) {
V_198 =
F_49 ( V_196 . V_201 * sizeof( int ) , V_81 ) ;
if ( ! V_198 ) {
F_2 ( L_29 ) ;
V_39 = - V_53 ;
goto V_202;
}
if ( F_23 ( V_198 , V_197 ,
V_196 . V_201 * sizeof( int ) ) ) {
F_2 ( L_30 ) ;
V_39 = - V_47 ;
goto V_202;
}
V_39 = F_57 ( V_4 , V_196 . V_201 , V_198 ) ;
if ( V_39 < 0 ) {
F_2 ( L_31 ) ;
goto V_202;
}
V_196 . V_198 = V_198 ;
}
V_39 = V_4 -> V_200 ( V_2 , V_4 , & V_196 ) ;
V_196 . V_198 = ( unsigned int V_204 * ) V_197 ;
if ( F_30 ( V_37 , & V_196 , sizeof( struct V_195 ) ) ) {
F_2 ( L_21 ) ;
V_39 = - V_47 ;
goto V_202;
}
V_202:
F_39 ( V_198 ) ;
return V_39 ;
}
static int F_66 ( struct V_1 * V_2 , unsigned int V_37 ,
void * V_64 )
{
int V_39 = 0 ;
unsigned long V_92 ;
struct V_3 * V_4 ;
if ( V_37 >= V_2 -> V_60 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_37 ] ;
F_61 ( & V_4 -> V_193 , V_92 ) ;
if ( V_4 -> V_11 || V_4 -> V_95 )
V_39 = - V_12 ;
else
V_4 -> V_95 = V_64 ;
F_62 ( & V_4 -> V_193 , V_92 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_39 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int V_37 ,
void * V_64 )
{
struct V_3 * V_4 ;
if ( V_37 >= V_2 -> V_60 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_37 ] ;
if ( V_4 -> V_11 )
return - V_12 ;
if ( V_4 -> V_95 && V_4 -> V_95 != V_64 )
return - V_118 ;
if ( V_4 -> V_95 == V_64 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_4 -> V_95 = NULL ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , unsigned int V_37 ,
void * V_64 )
{
struct V_3 * V_4 ;
if ( V_37 >= V_2 -> V_60 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_37 ] ;
if ( V_4 -> V_6 == NULL )
return - V_15 ;
if ( V_4 -> V_95 && V_4 -> V_95 != V_64 )
return - V_118 ;
if ( ! V_4 -> V_11 )
return 0 ;
if ( V_4 -> V_11 != V_64 )
return - V_12 ;
return F_69 ( V_2 , V_4 ) ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_37 ,
void * V_64 )
{
struct V_3 * V_4 ;
if ( V_37 >= V_2 -> V_60 )
return - V_15 ;
V_4 = & V_2 -> V_20 [ V_37 ] ;
if ( V_4 -> V_95 && V_4 -> V_95 != V_64 )
return - V_118 ;
if ( ! V_4 -> V_11 )
return 0 ;
if ( V_4 -> V_11 != V_64 )
return - V_12 ;
if ( V_4 -> V_213 )
return V_4 -> V_213 ( V_2 , V_4 ) ;
return - V_15 ;
}
static long F_71 ( struct V_64 * V_64 , unsigned int V_196 ,
unsigned long V_37 )
{
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_26 * V_68 =
F_33 ( V_19 ) ;
struct V_1 * V_2 ;
int V_214 ;
if ( V_68 == NULL || V_68 -> V_22 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
F_7 ( & V_2 -> V_29 ) ;
if ( V_196 == V_215 ) {
V_214 = F_18 ( V_2 ,
(struct V_36 T_3 * ) V_37 ) ;
goto V_216;
}
if ( ! V_2 -> V_43 ) {
F_2 ( L_36 , V_2 -> V_19 ) ;
V_214 = - V_199 ;
goto V_216;
}
switch ( V_196 ) {
case V_217 :
V_214 = F_29 ( V_2 ,
(struct V_57 T_3 * ) V_37 ) ;
break;
case V_218 :
V_214 = F_31 ( V_2 , (struct V_63 T_3 * ) V_37 ,
V_64 ) ;
break;
case V_219 :
V_214 = F_35 ( V_2 ,
(struct V_77 T_3 * ) V_37 ,
V_64 ) ;
break;
case V_220 :
V_214 = F_40 ( V_2 , ( void T_3 * ) V_37 ) ;
break;
case V_221 :
V_214 = F_72 ( V_2 , ( void T_3 * ) V_37 ) ;
break;
case V_222 :
V_214 = F_42 ( V_2 ,
(struct V_116 T_3 * ) V_37 ,
V_64 ) ;
break;
case V_223 :
V_214 = F_66 ( V_2 , V_37 , V_64 ) ;
break;
case V_224 :
V_214 = F_67 ( V_2 , V_37 , V_64 ) ;
break;
case V_225 :
V_214 = F_68 ( V_2 , V_37 , V_64 ) ;
break;
case V_226 :
V_214 = F_63 ( V_2 , (struct V_195 T_3 * ) V_37 , V_64 ) ;
break;
case V_227 :
V_214 = F_65 ( V_2 , (struct V_195 T_3 * ) V_37 ,
V_64 ) ;
break;
case V_228 :
V_214 = F_48 ( V_2 ,
(struct V_127 T_3 * ) V_37 ,
V_64 ) ;
break;
case V_229 :
V_214 = F_59 ( V_2 , (struct V_129 T_3 * ) V_37 ,
V_64 ) ;
break;
case V_230 :
V_214 = F_70 ( V_2 , V_37 , V_64 ) ;
break;
default:
V_214 = - V_231 ;
break;
}
V_216:
F_8 ( & V_2 -> V_29 ) ;
return V_214 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_39 = 0 ;
if ( ( F_37 ( V_4 ) & V_84 ) && V_4 -> V_232 )
V_39 = V_4 -> V_232 ( V_2 , V_4 ) ;
F_45 ( V_2 , V_4 ) ;
return V_39 ;
}
static void F_73 ( struct V_233 * V_234 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = V_234 -> V_235 ;
V_2 = V_6 -> V_59 -> V_22 ;
F_7 ( & V_2 -> V_29 ) ;
V_6 -> V_13 ++ ;
F_8 ( & V_2 -> V_29 ) ;
}
static void F_74 ( struct V_233 * V_234 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = V_234 -> V_235 ;
V_2 = V_6 -> V_59 -> V_22 ;
F_7 ( & V_2 -> V_29 ) ;
V_6 -> V_13 -- ;
F_8 ( & V_2 -> V_29 ) ;
}
static int F_75 ( struct V_64 * V_64 , struct V_233 * V_236 )
{
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_5 * V_6 = NULL ;
unsigned long V_237 = V_236 -> V_238 ;
unsigned long V_28 ;
int V_239 ;
int V_78 ;
int V_8 ;
struct V_3 * V_4 ;
struct V_26 * V_68 ;
struct V_1 * V_2 ;
V_68 = F_33 ( V_19 ) ;
if ( V_68 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
if ( V_2 == NULL )
return - V_199 ;
F_7 ( & V_2 -> V_29 ) ;
if ( ! V_2 -> V_43 ) {
F_2 ( L_37 , V_2 -> V_19 ) ;
V_8 = - V_199 ;
goto V_216;
}
if ( V_236 -> V_240 & V_241 )
V_4 = F_14 ( V_68 ) ;
else
V_4 = F_6 ( V_68 ) ;
if ( V_4 == NULL ) {
V_8 = - V_15 ;
goto V_216;
}
V_6 = V_4 -> V_6 ;
if ( V_6 == NULL ) {
V_8 = - V_15 ;
goto V_216;
}
if ( V_236 -> V_242 != 0 ) {
F_2 ( L_38 ) ;
V_8 = - V_15 ;
goto V_216;
}
V_28 = V_236 -> V_243 - V_236 -> V_238 ;
if ( V_28 > V_6 -> V_21 ) {
V_8 = - V_47 ;
goto V_216;
}
if ( V_28 & ( ~ V_17 ) ) {
V_8 = - V_47 ;
goto V_216;
}
V_239 = V_28 >> V_244 ;
for ( V_78 = 0 ; V_78 < V_239 ; ++ V_78 ) {
if ( F_76 ( V_236 , V_237 ,
F_77 ( F_78
( V_6 -> V_245
[ V_78 ] . V_246 ) ) , V_16 ,
V_247 ) ) {
V_8 = - V_177 ;
goto V_216;
}
V_237 += V_16 ;
}
V_236 -> V_248 = & V_249 ;
V_236 -> V_235 = V_6 ;
V_6 -> V_13 ++ ;
V_8 = 0 ;
V_216:
F_8 ( & V_2 -> V_29 ) ;
return V_8 ;
}
static unsigned int F_79 ( struct V_64 * V_64 , T_4 * V_250 )
{
unsigned int V_191 = 0 ;
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_3 * V_69 ;
struct V_3 * V_70 ;
struct V_26 * V_68 ;
struct V_1 * V_2 ;
V_68 = F_33 ( V_19 ) ;
if ( V_68 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
if ( V_2 == NULL )
return - V_199 ;
F_7 ( & V_2 -> V_29 ) ;
if ( ! V_2 -> V_43 ) {
F_2 ( L_37 , V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_29 ) ;
return 0 ;
}
V_191 = 0 ;
V_69 = F_6 ( V_68 ) ;
if ( V_69 ) {
F_80 ( V_64 , & V_69 -> V_6 -> V_251 , V_250 ) ;
if ( ! V_69 -> V_11
|| F_81 ( V_69 -> V_6 ) > 0
|| ! ( F_37 ( V_69 ) &
V_84 ) ) {
V_191 |= V_252 | V_253 ;
}
}
V_70 = F_14 ( V_68 ) ;
if ( V_70 ) {
F_80 ( V_64 , & V_70 -> V_6 -> V_251 , V_250 ) ;
F_46 ( V_70 -> V_6 ,
V_70 -> V_6 -> V_21 ) ;
if ( ! V_70 -> V_11
|| ! ( F_37 ( V_70 ) &
V_84 )
|| F_82 ( V_70 -> V_6 ) >=
F_83 ( V_70 -> V_6 -> V_59 ) ) {
V_191 |= V_254 | V_255 ;
}
}
F_8 ( & V_2 -> V_29 ) ;
return V_191 ;
}
static T_1 F_84 ( struct V_64 * V_64 , const char T_3 * V_25 ,
T_2 V_256 , T_5 * V_257 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_134 , V_258 , V_32 = 0 , V_8 = 0 ;
F_85 ( V_250 , V_259 ) ;
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_26 * V_68 ;
struct V_1 * V_2 ;
V_68 = F_33 ( V_19 ) ;
if ( V_68 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
if ( V_2 == NULL )
return - V_199 ;
if ( ! V_2 -> V_43 ) {
F_2 ( L_37 , V_2 -> V_19 ) ;
V_8 = - V_199 ;
goto V_216;
}
V_4 = F_14 ( V_68 ) ;
if ( V_4 == NULL ) {
V_8 = - V_180 ;
goto V_216;
}
V_6 = V_4 -> V_6 ;
if ( ! V_256 ) {
V_8 = 0 ;
goto V_216;
}
if ( ! V_4 -> V_11 ) {
V_8 = 0 ;
goto V_216;
}
if ( V_4 -> V_11 != V_64 ) {
V_8 = - V_118 ;
goto V_216;
}
F_86 ( & V_6 -> V_251 , & V_250 ) ;
while ( V_256 > 0 && ! V_8 ) {
F_87 ( V_260 ) ;
if ( ! ( F_37 ( V_4 ) & V_84 ) ) {
if ( V_32 == 0 ) {
if ( F_37 ( V_4 ) &
V_126 ) {
V_8 = - V_261 ;
} else {
V_8 = 0 ;
}
F_45 ( V_2 , V_4 ) ;
}
break;
}
V_134 = V_256 ;
V_258 = V_134 ;
if ( V_6 -> V_119 + V_258 > V_6 -> V_21 )
V_258 = V_6 -> V_21 - V_6 -> V_119 ;
F_46 ( V_6 , V_6 -> V_21 ) ;
if ( V_258 > F_82 ( V_6 ) )
V_258 = F_82 ( V_6 ) ;
if ( V_258 < V_134 )
V_134 = V_258 ;
if ( V_134 == 0 ) {
if ( V_64 -> V_262 & V_263 ) {
V_8 = - V_177 ;
break;
}
F_52 () ;
if ( F_88 ( V_259 ) ) {
V_8 = - V_264 ;
break;
}
if ( ! V_4 -> V_11 )
break;
if ( V_4 -> V_11 != V_64 ) {
V_8 = - V_118 ;
break;
}
continue;
}
V_258 = F_23 ( V_6 -> V_14 + V_6 -> V_119 ,
V_25 , V_134 ) ;
if ( V_258 ) {
V_134 -= V_258 ;
V_8 = - V_47 ;
}
F_47 ( V_6 , V_134 ) ;
V_32 += V_134 ;
V_256 -= V_134 ;
V_25 += V_134 ;
break;
}
F_87 ( V_265 ) ;
F_89 ( & V_6 -> V_251 , & V_250 ) ;
V_216:
return V_32 ? V_32 : V_8 ;
}
static T_1 F_90 ( struct V_64 * V_64 , char T_3 * V_25 , T_2 V_256 ,
T_5 * V_257 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_134 , V_258 , V_32 = 0 , V_8 = 0 ;
F_85 ( V_250 , V_259 ) ;
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_26 * V_68 ;
struct V_1 * V_2 ;
V_68 = F_33 ( V_19 ) ;
if ( V_68 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
if ( V_2 == NULL )
return - V_199 ;
if ( ! V_2 -> V_43 ) {
F_2 ( L_37 , V_2 -> V_19 ) ;
V_8 = - V_199 ;
goto V_216;
}
V_4 = F_6 ( V_68 ) ;
if ( V_4 == NULL ) {
V_8 = - V_180 ;
goto V_216;
}
V_6 = V_4 -> V_6 ;
if ( ! V_256 ) {
V_8 = 0 ;
goto V_216;
}
if ( ! V_4 -> V_11 ) {
V_8 = 0 ;
goto V_216;
}
if ( V_4 -> V_11 != V_64 ) {
V_8 = - V_118 ;
goto V_216;
}
F_86 ( & V_6 -> V_251 , & V_250 ) ;
while ( V_256 > 0 && ! V_8 ) {
F_87 ( V_260 ) ;
V_134 = V_256 ;
V_258 = F_81 ( V_6 ) ;
if ( V_6 -> V_120 + V_258 > V_6 -> V_21 )
V_258 = V_6 -> V_21 - V_6 -> V_120 ;
if ( V_258 < V_134 )
V_134 = V_258 ;
if ( V_134 == 0 ) {
if ( ! ( F_37 ( V_4 ) & V_84 ) ) {
F_45 ( V_2 , V_4 ) ;
if ( F_37 ( V_4 ) &
V_126 ) {
V_8 = - V_261 ;
} else {
V_8 = 0 ;
}
break;
}
if ( V_64 -> V_262 & V_263 ) {
V_8 = - V_177 ;
break;
}
F_52 () ;
if ( F_88 ( V_259 ) ) {
V_8 = - V_264 ;
break;
}
if ( ! V_4 -> V_11 ) {
V_8 = 0 ;
break;
}
if ( V_4 -> V_11 != V_64 ) {
V_8 = - V_118 ;
break;
}
continue;
}
V_258 = F_30 ( V_25 , V_6 -> V_14 +
V_6 -> V_120 , V_134 ) ;
if ( V_258 ) {
V_134 -= V_258 ;
V_8 = - V_47 ;
}
F_43 ( V_6 , V_134 ) ;
F_44 ( V_6 , V_134 ) ;
V_32 += V_134 ;
V_256 -= V_134 ;
V_25 += V_134 ;
break;
}
if ( ! ( F_37 ( V_4 ) & ( V_126 | V_84 ) ) &&
V_6 -> V_122 - V_6 -> V_121 == 0 ) {
F_45 ( V_2 , V_4 ) ;
}
F_87 ( V_265 ) ;
F_89 ( & V_6 -> V_251 , & V_250 ) ;
V_216:
return V_32 ? V_32 : V_8 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
F_60 ( V_4 , V_84 , 0 ) ;
if ( V_6 ) {
F_64 ( V_6 ) ;
V_6 -> V_176 = NULL ;
F_39 ( V_6 -> V_196 . V_198 ) ;
V_6 -> V_196 . V_198 = NULL ;
} else {
F_91 ( V_2 -> V_266 ,
L_39 ) ;
}
V_4 -> V_11 = NULL ;
}
static int F_92 ( struct V_267 * V_267 , struct V_64 * V_64 )
{
const unsigned V_19 = F_32 ( V_267 ) ;
struct V_26 * V_68 =
F_33 ( V_19 ) ;
struct V_1 * V_2 =
V_68 ? V_68 -> V_22 : NULL ;
if ( V_2 == NULL ) {
F_2 ( L_40 ) ;
return - V_199 ;
}
F_7 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_43 )
goto V_268;
if ( ! F_19 ( V_269 ) && V_2 -> V_270 ) {
F_2 ( L_41 ) ;
F_8 ( & V_2 -> V_29 ) ;
return - V_199 ;
}
if ( F_19 ( V_269 ) && V_2 -> V_270 )
goto V_268;
V_2 -> V_270 = 1 ;
#ifdef F_93
F_8 ( & V_2 -> V_29 ) ;
F_94 ( L_42 , V_271 , V_2 -> V_19 ) ;
F_7 ( & V_2 -> V_29 ) ;
#endif
V_2 -> V_270 = 0 ;
if ( ! V_2 -> V_43 && ! F_19 ( V_269 ) ) {
F_2 ( L_43 ) ;
F_8 ( & V_2 -> V_29 ) ;
return - V_199 ;
}
V_268:
F_95 ( V_272 ) ;
if ( V_2 -> V_43 ) {
if ( ! F_28 ( V_2 -> V_46 -> V_44 ) ) {
F_22 ( V_272 ) ;
F_8 ( & V_2 -> V_29 ) ;
return - V_56 ;
}
}
if ( V_2 -> V_43 && V_2 -> V_273 == 0 && V_2 -> V_274 ) {
int V_214 = V_2 -> V_274 ( V_2 ) ;
if ( V_214 < 0 ) {
F_22 ( V_2 -> V_46 -> V_44 ) ;
F_22 ( V_272 ) ;
F_8 ( & V_2 -> V_29 ) ;
return V_214 ;
}
}
V_2 -> V_273 ++ ;
F_8 ( & V_2 -> V_29 ) ;
return 0 ;
}
static int F_96 ( struct V_267 * V_267 , struct V_64 * V_64 )
{
const unsigned V_19 = F_32 ( V_267 ) ;
struct V_3 * V_4 = NULL ;
int V_78 ;
struct V_26 * V_68 ;
struct V_1 * V_2 ;
V_68 = F_33 ( V_19 ) ;
if ( V_68 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
if ( V_2 == NULL )
return - V_199 ;
F_7 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_20 ) {
for ( V_78 = 0 ; V_78 < V_2 -> V_60 ; V_78 ++ ) {
V_4 = & V_2 -> V_20 [ V_78 ] ;
if ( V_4 -> V_11 == V_64 )
F_69 ( V_2 , V_4 ) ;
if ( V_4 -> V_95 == V_64 )
V_4 -> V_95 = NULL ;
}
}
if ( V_2 -> V_43 && V_2 -> V_273 == 1 && V_2 -> V_275 )
V_2 -> V_275 ( V_2 ) ;
F_22 ( V_272 ) ;
if ( V_2 -> V_43 )
F_22 ( V_2 -> V_46 -> V_44 ) ;
V_2 -> V_273 -- ;
F_8 ( & V_2 -> V_29 ) ;
if ( V_64 -> V_262 & V_276 )
F_97 ( - 1 , V_64 , 0 ) ;
return 0 ;
}
static int F_97 ( int V_277 , struct V_64 * V_64 , int V_278 )
{
const unsigned V_19 = F_32 ( V_64 -> V_66 -> V_67 ) ;
struct V_26 * V_68 ;
struct V_1 * V_2 ;
V_68 = F_33 ( V_19 ) ;
if ( V_68 == NULL )
return - V_199 ;
V_2 = V_68 -> V_22 ;
if ( V_2 == NULL )
return - V_199 ;
return F_98 ( V_277 , V_64 , V_278 , & V_2 -> V_279 ) ;
}
static void F_99 ( void )
{
unsigned V_78 ;
for ( V_78 = 0 ; V_78 < V_280 ; V_78 ++ )
F_100 ( V_78 ) ;
}
static int T_6 F_101 ( void )
{
int V_78 ;
int V_8 ;
F_102 ( L_44 V_281 L_45 ) ;
if ( V_280 < 0 ||
V_280 > V_282 ) {
F_103 ( L_46 ,
V_282 ) ;
return - V_15 ;
}
if ( V_283 == 0 && V_280 == 0 )
V_280 = 16 ;
memset ( V_284 , 0 ,
sizeof( struct V_26 * ) * V_285 ) ;
V_8 = F_104 ( F_105 ( V_271 , 0 ) ,
V_285 , L_47 ) ;
if ( V_8 )
return - V_180 ;
F_106 ( & V_286 , & V_287 ) ;
V_286 . V_288 = V_272 ;
F_107 ( & V_286 . V_289 , L_47 ) ;
if ( F_108 ( & V_286 , F_105 ( V_271 , 0 ) , V_285 ) ) {
F_109 ( F_105 ( V_271 , 0 ) ,
V_285 ) ;
return - V_180 ;
}
V_290 = F_110 ( V_272 , L_47 ) ;
if ( F_111 ( V_290 ) ) {
F_103 ( L_48 ) ;
F_112 ( & V_286 ) ;
F_109 ( F_105 ( V_271 , 0 ) ,
V_285 ) ;
return F_113 ( V_290 ) ;
}
V_290 -> V_291 = V_292 ;
F_114 () ;
for ( V_78 = 0 ; V_78 < V_280 ; V_78 ++ ) {
int V_19 ;
V_19 = F_115 ( NULL ) ;
if ( V_19 < 0 ) {
F_99 () ;
F_112 ( & V_286 ) ;
F_109 ( F_105 ( V_271 , 0 ) ,
V_285 ) ;
return V_19 ;
}
}
return 0 ;
}
static void T_7 F_116 ( void )
{
int V_78 ;
F_99 () ;
for ( V_78 = 0 ; V_78 < V_285 ; ++ V_78 )
F_117 ( V_284 [ V_78 ] ) ;
F_118 ( V_290 ) ;
F_112 ( & V_286 ) ;
F_109 ( F_105 ( V_271 , 0 ) , V_285 ) ;
F_119 () ;
}
void F_120 ( const struct V_1 * V_2 , const char * V_4 )
{
F_91 ( V_2 -> V_266 , L_49 , V_2 -> V_46 -> V_74 , V_4 ) ;
}
void F_121 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned V_194 = 0 ;
unsigned V_293 = 0 ;
if ( ( F_37 ( V_4 ) & V_84 ) == 0 )
return;
if ( V_4 ->
V_6 -> V_294 & ( V_206 | V_208 |
V_209 ) ) {
V_293 |= V_84 ;
}
if ( V_4 -> V_6 -> V_294 & ( V_208 | V_209 ) ) {
V_293 |= V_126 ;
V_194 |= V_126 ;
}
if ( V_293 ) {
F_60 ( V_4 , V_293 , V_194 ) ;
}
if ( V_6 -> V_205 & V_4 -> V_6 -> V_294 ) {
if ( F_37 ( V_4 ) & V_212 ) {
F_122 ( & V_6 -> V_251 ) ;
if ( V_4 -> V_30 & V_31 )
F_123 ( & V_2 -> V_279 , V_295 , V_296 ) ;
if ( V_4 -> V_30 & V_35 )
F_123 ( & V_2 -> V_279 , V_295 , V_297 ) ;
} else {
if ( V_6 -> V_298 )
V_6 -> V_298 ( V_4 -> V_6 -> V_294 , V_6 -> V_299 ) ;
}
}
V_4 -> V_6 -> V_294 = 0 ;
}
unsigned F_37 ( struct V_3 * V_4 )
{
unsigned long V_92 ;
unsigned V_194 ;
F_61 ( & V_4 -> V_193 , V_92 ) ;
V_194 = V_4 -> V_194 ;
F_62 ( & V_4 -> V_193 , V_92 ) ;
return V_194 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_78 ;
if ( ! V_2 -> V_43 )
return 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_60 ; V_78 ++ ) {
V_4 = & V_2 -> V_20 [ V_78 ] ;
if ( V_4 -> V_11 )
return 1 ;
if ( V_4 -> V_6 && V_4 -> V_6 -> V_13 )
return 1 ;
}
return 0 ;
}
static void F_124 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_125 ( & V_2 -> V_300 ) ;
F_126 ( & V_2 -> V_29 ) ;
V_2 -> V_19 = - 1 ;
}
static void F_127 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_7 ( & V_2 -> V_29 ) ;
F_21 ( V_2 ) ;
F_8 ( & V_2 -> V_29 ) ;
F_128 ( & V_2 -> V_29 ) ;
}
int F_115 ( struct V_22 * V_301 )
{
struct V_26 * V_27 ;
struct V_22 * V_302 ;
unsigned V_78 ;
V_27 = F_129 ( sizeof( struct V_26 ) , V_81 ) ;
if ( V_27 == NULL )
return - V_53 ;
V_27 -> V_22 = F_129 ( sizeof( struct V_1 ) , V_81 ) ;
if ( V_27 -> V_22 == NULL ) {
F_39 ( V_27 ) ;
return - V_53 ;
}
V_27 -> V_301 = V_301 ;
F_124 ( V_27 -> V_22 ) ;
V_193 ( & V_303 ) ;
for ( V_78 = 0 ; V_78 < V_282 ; ++ V_78 ) {
if ( V_284 [ V_78 ] == NULL ) {
V_284 [ V_78 ] = V_27 ;
break;
}
}
F_130 ( & V_303 ) ;
if ( V_78 == V_282 ) {
F_127 ( V_27 -> V_22 ) ;
F_39 ( V_27 -> V_22 ) ;
F_39 ( V_27 ) ;
F_103 ( L_50 ) ;
return - V_12 ;
}
V_27 -> V_22 -> V_19 = V_78 ;
V_302 = F_131 ( V_290 , V_301 ,
F_105 ( V_271 , V_78 ) , NULL , L_51 , V_78 ) ;
if ( ! F_111 ( V_302 ) )
V_27 -> V_22 -> V_266 = V_302 ;
F_132 ( V_302 , V_27 ) ;
return V_78 ;
}
void F_100 ( unsigned V_19 )
{
struct V_26 * V_27 ;
F_117 ( V_19 >= V_282 ) ;
V_193 ( & V_303 ) ;
V_27 = V_284 [ V_19 ] ;
V_284 [ V_19 ] = NULL ;
F_130 ( & V_303 ) ;
if ( V_27 ) {
struct V_1 * V_2 = V_27 -> V_22 ;
if ( V_2 ) {
if ( V_2 -> V_266 ) {
F_133 ( V_290 ,
F_105 ( V_271 , V_2 -> V_19 ) ) ;
}
F_127 ( V_2 ) ;
F_39 ( V_2 ) ;
}
F_39 ( V_27 ) ;
}
}
int F_134 ( struct V_22 * V_301 )
{
int V_19 ;
struct V_26 * V_27 ;
for ( V_19 = 0 ; V_19 < V_282 ; V_19 ++ ) {
V_193 ( & V_303 ) ;
V_27 = V_284 [ V_19 ] ;
if ( V_27 && V_27 -> V_301 == V_301 ) {
F_130 ( & V_303 ) ;
return V_19 ;
}
F_130 ( & V_303 ) ;
}
return - V_199 ;
}
int F_135 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 ;
struct V_22 * V_302 ;
unsigned V_78 ;
V_27 = F_49 ( sizeof( struct V_26 ) , V_81 ) ;
if ( V_27 == NULL )
return - V_53 ;
V_27 -> V_22 = V_2 ;
V_27 -> V_75 = V_4 ;
V_27 -> V_76 = V_4 ;
V_193 ( & V_303 ) ;
for ( V_78 = V_304 ; V_78 < V_285 ; ++ V_78 ) {
if ( V_284 [ V_78 ] == NULL ) {
V_284 [ V_78 ] = V_27 ;
break;
}
}
F_130 ( & V_303 ) ;
if ( V_78 == V_285 ) {
F_39 ( V_27 ) ;
F_103 ( L_50 ) ;
return - V_12 ;
}
V_4 -> V_19 = V_78 ;
V_302 = F_131 ( V_290 , V_2 -> V_266 ,
F_105 ( V_271 , V_78 ) , NULL , L_52 ,
V_2 -> V_19 , ( int ) ( V_4 - V_2 -> V_20 ) ) ;
if ( ! F_111 ( V_302 ) )
V_4 -> V_266 = V_302 ;
F_132 ( V_302 , V_27 ) ;
return V_78 ;
}
void F_136 ( struct V_3 * V_4 )
{
struct V_26 * V_27 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_19 < 0 )
return;
F_117 ( V_4 -> V_19 >= V_285 ) ;
F_117 ( V_4 -> V_19 < V_304 ) ;
V_193 ( & V_303 ) ;
V_27 = V_284 [ V_4 -> V_19 ] ;
V_284 [ V_4 -> V_19 ] = NULL ;
F_130 ( & V_303 ) ;
if ( V_4 -> V_266 ) {
F_133 ( V_290 , F_105 ( V_271 , V_4 -> V_19 ) ) ;
V_4 -> V_266 = NULL ;
}
F_39 ( V_27 ) ;
}
struct V_26 * F_33 ( unsigned V_19 )
{
struct V_26 * V_27 ;
F_117 ( V_19 >= V_285 ) ;
V_193 ( & V_303 ) ;
V_27 = V_284 [ V_19 ] ;
F_130 ( & V_303 ) ;
return V_27 ;
}
