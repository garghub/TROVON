static int F_1 ( struct V_1 T_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
return F_2 ( V_5 ) ;
default:
return - V_6 ;
}
}
static void F_3 ( struct V_1 * V_2 ,
struct V_7 T_1 * V_8 ,
T_2 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
int V_14 ;
char * V_15 = NULL ;
for ( V_14 = 0 ; V_14 < F_2 ( V_5 ) ; V_14 ++ ) {
V_15 = ( char * ) V_13 + V_5 [ V_14 ] . V_16 ;
V_9 [ V_14 ] = ( V_5 [ V_14 ] . V_17 == sizeof( T_2 ) ) ? * ( T_2 * ) V_15 : * ( V_18 * ) V_15 ;
}
}
static void F_5 ( struct V_1 T_1 * V_2 , V_18 V_19 , T_3 * V_9 )
{
T_3 * V_15 = V_9 ;
int V_14 ;
switch ( V_19 ) {
case V_4 :
for ( V_14 = 0 ; V_14 < F_2 ( V_5 ) ; V_14 ++ ) {
memcpy ( V_15 , V_5 [ V_14 ] . V_20 , V_21 ) ;
V_15 += V_21 ;
}
}
}
static V_18 F_6 ( struct V_10 * V_11 , V_18 V_22 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
V_18 V_23 , V_24 , V_25 ;
V_25 = V_26 ;
V_24 = F_7 ( V_18 , V_27 , F_8 ( V_13 -> V_28 . V_29 ) ) ;
if ( V_24 < V_25 ) {
F_9 ( & V_11 -> V_30 -> V_11 , L_1 ,
F_8 ( V_13 -> V_28 . V_29 ) , V_25 ) ;
V_24 = V_25 ;
}
V_23 = F_10 ( V_18 , V_22 , V_25 , V_24 ) ;
if ( V_23 != V_22 )
F_11 ( & V_11 -> V_30 -> V_11 , L_2 , V_25 , V_24 ) ;
return V_23 ;
}
static V_18 F_12 ( struct V_10 * V_11 , V_18 V_31 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
V_18 V_23 , V_24 , V_25 ;
V_25 = V_13 -> V_32 + V_13 -> V_33 + sizeof( struct V_34 ) ;
V_24 = F_7 ( V_18 , V_35 , F_8 ( V_13 -> V_28 . V_36 ) ) ;
V_25 = V_25 ( V_25 , V_24 ) ;
V_23 = F_10 ( V_18 , V_31 , V_25 , V_24 ) ;
if ( V_23 != V_31 )
F_11 ( & V_11 -> V_30 -> V_11 , L_3 , V_25 , V_24 ) ;
return V_23 ;
}
static T_4 F_13 ( struct V_37 * V_38 , struct V_39 * V_40 , char * V_41 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
return sprintf ( V_41 , L_4 , V_13 -> V_42 ) ;
}
static T_4 F_15 ( struct V_37 * V_38 , struct V_39 * V_40 , char * V_41 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
return sprintf ( V_41 , L_4 , V_13 -> V_43 ) ;
}
static T_4 F_16 ( struct V_37 * V_38 , struct V_39 * V_40 , char * V_41 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
return sprintf ( V_41 , L_4 , V_13 -> V_44 ) ;
}
static T_4 F_17 ( struct V_37 * V_38 , struct V_39 * V_40 , char * V_41 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
return sprintf ( V_41 , L_4 , V_13 -> V_45 / ( V_18 ) V_46 ) ;
}
static T_4 F_18 ( struct V_37 * V_38 , struct V_39 * V_40 , const char * V_41 , T_5 V_47 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
unsigned long V_23 ;
if ( F_19 ( V_41 , 0 , & V_23 ) )
return - V_48 ;
V_13 -> V_42 = V_23 ;
return V_47 ;
}
static T_4 F_20 ( struct V_37 * V_38 , struct V_39 * V_40 , const char * V_41 , T_5 V_47 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
unsigned long V_23 ;
if ( F_19 ( V_41 , 0 , & V_23 ) || F_6 ( V_11 , V_23 ) != V_23 )
return - V_48 ;
F_21 ( V_11 , V_23 , V_13 -> V_44 ) ;
return V_47 ;
}
static T_4 F_22 ( struct V_37 * V_38 , struct V_39 * V_40 , const char * V_41 , T_5 V_47 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
unsigned long V_23 ;
if ( F_19 ( V_41 , 0 , & V_23 ) || F_12 ( V_11 , V_23 ) != V_23 )
return - V_48 ;
F_21 ( V_11 , V_13 -> V_43 , V_23 ) ;
return V_47 ;
}
static T_4 F_23 ( struct V_37 * V_38 , struct V_39 * V_40 , const char * V_41 , T_5 V_47 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_4 V_49 ;
unsigned long V_23 ;
V_49 = F_19 ( V_41 , 0 , & V_23 ) ;
if ( V_49 )
return V_49 ;
if ( V_23 && ( V_23 < V_50 || V_23 > V_51 ) )
return - V_48 ;
F_24 ( & V_13 -> V_52 ) ;
V_13 -> V_45 = V_23 * V_46 ;
if ( ! V_13 -> V_45 )
V_13 -> V_53 = 0 ;
F_25 ( & V_13 -> V_52 ) ;
return V_47 ;
}
static void F_21 ( struct V_10 * V_11 , V_18 V_22 , V_18 V_31 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_3 V_54 = V_13 -> V_55 -> V_56 -> V_57 . V_58 ;
V_18 V_23 ;
V_23 = F_6 ( V_11 , V_22 ) ;
if ( V_23 != V_13 -> V_43 ) {
T_6 V_29 = F_26 ( V_23 ) ;
F_27 ( & V_11 -> V_30 -> V_11 , L_5 , V_23 ) ;
if ( F_28 ( V_11 , V_59 ,
V_60 | V_61
| V_62 ,
0 , V_54 , & V_29 , 4 ) < 0 )
F_11 ( & V_11 -> V_30 -> V_11 , L_6 ) ;
else
V_13 -> V_43 = V_23 ;
}
if ( V_11 -> V_63 != V_13 -> V_43 ) {
V_11 -> V_63 = V_13 -> V_43 ;
if ( F_29 ( V_11 -> V_64 ) )
F_30 ( V_11 ) ;
}
V_23 = F_12 ( V_11 , V_31 ) ;
if ( V_23 != V_13 -> V_44 )
F_27 ( & V_11 -> V_30 -> V_11 , L_7 , V_23 ) ;
if ( V_23 != F_8 ( V_13 -> V_28 . V_36 ) &&
V_23 % F_31 ( V_11 -> V_65 , V_11 -> V_66 , 1 ) == 0 )
V_23 ++ ;
if ( F_29 ( V_11 -> V_64 ) && V_23 > V_13 -> V_44 ) {
F_32 ( V_11 -> V_64 ) ;
F_33 ( NULL , V_11 -> V_64 ) ;
if ( V_13 -> V_67 ) {
F_34 ( V_13 -> V_67 ) ;
V_13 -> V_67 = NULL ;
}
V_13 -> V_44 = V_23 ;
F_35 ( V_11 -> V_64 ) ;
} else {
V_13 -> V_44 = V_23 ;
}
V_11 -> V_68 = V_13 -> V_44 ;
F_36 ( V_11 ) ;
V_13 -> V_42 = F_10 ( V_69 , V_13 -> V_44 - 3 * F_31 ( V_11 -> V_65 , V_11 -> V_66 , 1 ) ,
V_70 , V_13 -> V_44 ) ;
}
static T_3 F_37 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( F_38 ( V_11 -> V_30 -> V_56 ) && V_13 -> V_71 )
return V_13 -> V_71 -> V_72 ;
if ( V_13 -> V_73 )
return V_13 -> V_73 -> V_72 ;
return 0 ;
}
static int F_39 ( struct V_10 * V_11 )
{
if ( F_38 ( V_11 -> V_30 -> V_56 ) )
return 0 ;
return V_74 ;
}
static V_18 F_40 ( struct V_10 * V_11 )
{
if ( F_38 ( V_11 -> V_30 -> V_56 ) )
return V_75 ;
return V_76 ;
}
static V_18 F_41 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( F_38 ( V_11 -> V_30 -> V_56 ) && V_13 -> V_71 )
return F_42 ( V_13 -> V_71 -> V_77 ) ;
if ( V_13 -> V_78 )
return F_42 ( V_13 -> V_78 -> V_77 ) ;
return V_79 ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_3 V_54 = V_13 -> V_55 -> V_56 -> V_57 . V_58 ;
int V_80 ;
V_80 = F_44 ( V_11 , V_81 ,
V_60 | V_82
| V_62 ,
0 , V_54 , & V_13 -> V_28 ,
sizeof( V_13 -> V_28 ) ) ;
if ( V_80 < 0 ) {
F_45 ( & V_11 -> V_30 -> V_11 , L_8 ) ;
return V_80 ;
}
if ( F_37 ( V_11 ) & V_83 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_9 ) ;
V_80 = F_28 ( V_11 , V_84 ,
V_60 | V_61
| V_62 ,
V_85 ,
V_54 , NULL , 0 ) ;
if ( V_80 < 0 )
F_45 ( & V_11 -> V_30 -> V_11 , L_10 ) ;
}
if ( F_42 ( V_13 -> V_28 . V_86 ) &
V_87 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_11 ) ;
V_80 = F_28 ( V_11 , V_88 ,
V_60 | V_61
| V_62 ,
V_89 ,
V_54 , NULL , 0 ) ;
if ( V_80 < 0 )
F_45 ( & V_11 -> V_30 -> V_11 , L_12 ) ;
}
V_13 -> V_43 = F_8 ( V_13 -> V_28 . V_29 ) ;
V_13 -> V_44 = F_8 ( V_13 -> V_28 . V_36 ) ;
V_13 -> V_90 = F_42 ( V_13 -> V_28 . V_91 ) ;
V_13 -> V_92 = F_42 ( V_13 -> V_28 . V_93 ) ;
V_13 -> V_94 = F_42 ( V_13 -> V_28 . V_95 ) ;
V_13 -> V_96 = F_42 ( V_13 -> V_28 . V_97 ) ;
F_11 ( & V_11 -> V_30 -> V_11 ,
L_13 ,
V_13 -> V_43 , V_13 -> V_44 , V_13 -> V_90 , V_13 -> V_92 ,
V_13 -> V_94 , V_13 -> V_96 , F_37 ( V_11 ) ) ;
if ( ( V_13 -> V_96 == 0 ) ||
( V_13 -> V_96 > V_98 ) )
V_13 -> V_96 = V_98 ;
V_13 -> V_33 = sizeof( struct V_99 ) + ( V_13 -> V_96 + 1 ) * sizeof( struct V_100 ) ;
V_13 -> V_45 = V_101 * V_46 ;
return 0 ;
}
static void F_46 ( struct V_10 * V_11 , int V_102 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_3 V_54 = V_13 -> V_55 -> V_56 -> V_57 . V_58 ;
T_7 V_32 ;
V_69 V_103 ;
int V_80 ;
V_13 -> V_32 = F_10 ( V_18 , V_102 ,
F_40 ( V_11 ) ,
V_79 ) ;
if ( ! ( F_37 ( V_11 ) & V_104 ) )
goto V_66;
V_80 = F_44 ( V_11 , V_105 ,
V_60 | V_82 | V_62 ,
0 , V_54 , & V_32 , 2 ) ;
if ( V_80 < 0 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_14 ) ;
goto V_66;
}
if ( F_42 ( V_32 ) == V_13 -> V_32 )
goto V_66;
V_32 = F_47 ( V_13 -> V_32 ) ;
V_80 = F_28 ( V_11 , V_106 ,
V_60 | V_61 | V_62 ,
0 , V_54 , & V_32 , 2 ) ;
if ( V_80 < 0 )
F_11 ( & V_11 -> V_30 -> V_11 , L_15 ) ;
V_66:
V_11 -> V_64 -> V_107 = F_7 ( int , V_11 -> V_64 -> V_107 , V_13 -> V_32 - F_39 ( V_11 ) ) ;
if ( V_13 -> V_108 ) {
V_103 = F_42 ( V_13 -> V_108 -> V_109 ) ;
if ( V_103 != 0 && V_103 < V_11 -> V_64 -> V_107 )
V_11 -> V_64 -> V_107 = V_103 ;
}
}
static void F_48 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
V_18 V_23 ;
V_23 = V_13 -> V_94 ;
if ( ( V_23 < V_110 ) ||
( V_23 != ( ( - V_23 ) & V_23 ) ) || ( V_23 >= V_13 -> V_44 ) ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_16 ) ;
V_13 -> V_94 = V_110 ;
}
V_23 = V_13 -> V_92 ;
if ( ( V_23 < V_110 ) ||
( V_23 != ( ( - V_23 ) & V_23 ) ) || ( V_23 >= V_13 -> V_44 ) ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_17 ) ;
V_13 -> V_92 = V_110 ;
}
if ( V_13 -> V_90 >= V_13 -> V_92 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_18 ) ;
V_13 -> V_90 = 0 ;
}
V_13 -> V_90 = ( ( V_13 -> V_90 - F_39 ( V_11 ) ) &
( V_13 -> V_92 - 1 ) ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
V_18 V_111 , V_112 ;
V_111 = F_7 ( V_18 , V_113 ,
F_8 ( V_13 -> V_28 . V_29 ) ) ;
V_112 = F_7 ( V_18 , V_114 ,
F_8 ( V_13 -> V_28 . V_36 ) ) ;
F_21 ( V_11 , V_111 , V_112 ) ;
F_48 ( V_11 ) ;
F_46 ( V_11 , F_41 ( V_11 ) ) ;
return 0 ;
}
static void
F_50 ( struct V_10 * V_11 , struct V_115 * V_30 )
{
struct V_116 * V_117 , * V_118 = NULL , * V_66 = NULL ;
T_3 V_119 ;
for ( V_119 = 0 ; V_119 < V_30 -> V_56 -> V_57 . V_120 ; V_119 ++ ) {
V_117 = V_30 -> V_56 -> V_121 + V_119 ;
switch ( V_117 -> V_57 . V_122 & V_123 ) {
case V_124 :
if ( F_51 ( & V_117 -> V_57 ) ) {
if ( ! V_11 -> V_125 )
V_11 -> V_125 = V_117 ;
}
break;
case V_126 :
if ( F_51 ( & V_117 -> V_57 ) ) {
if ( ! V_118 )
V_118 = V_117 ;
} else {
if ( ! V_66 )
V_66 = V_117 ;
}
break;
default:
break;
}
}
if ( V_118 && ! V_11 -> V_118 )
V_11 -> V_118 = F_52 ( V_11 -> V_65 ,
V_118 -> V_57 . V_127 &
V_128 ) ;
if ( V_66 && ! V_11 -> V_66 )
V_11 -> V_66 = F_53 ( V_11 -> V_65 ,
V_66 -> V_57 . V_127 &
V_128 ) ;
}
static void F_54 ( struct V_12 * V_13 )
{
if ( V_13 == NULL )
return;
if ( V_13 -> V_129 != NULL ) {
F_34 ( V_13 -> V_129 ) ;
V_13 -> V_129 = NULL ;
}
if ( V_13 -> V_67 != NULL ) {
F_34 ( V_13 -> V_67 ) ;
V_13 -> V_67 = NULL ;
}
F_55 ( V_13 ) ;
}
int F_56 ( struct V_10 * V_11 , struct V_115 * V_30 , T_3 V_130 )
{
const struct V_131 * V_132 = NULL ;
struct V_12 * V_13 ;
struct V_133 * V_134 ;
T_3 * V_41 ;
int V_47 ;
int V_135 ;
T_3 V_54 ;
V_13 = F_57 ( sizeof( * V_13 ) , V_136 ) ;
if ( ! V_13 )
return - V_137 ;
F_58 ( & V_13 -> V_138 , V_139 , V_140 ) ;
V_13 -> V_138 . V_141 = & V_142 ;
V_13 -> V_143 . V_9 = ( unsigned long ) V_11 ;
V_13 -> V_143 . V_144 = V_145 ;
F_59 ( & V_13 -> V_146 , 0 ) ;
F_60 ( & V_13 -> V_52 ) ;
V_11 -> V_9 [ 0 ] = ( unsigned long ) V_13 ;
V_13 -> V_55 = V_30 ;
V_134 = F_61 ( V_30 ) ;
V_41 = V_30 -> V_56 -> V_147 ;
V_47 = V_30 -> V_56 -> V_148 ;
while ( ( V_47 > 0 ) && ( V_41 [ 0 ] > 2 ) && ( V_41 [ 0 ] <= V_47 ) ) {
if ( V_41 [ 1 ] != V_149 )
goto V_150;
switch ( V_41 [ 2 ] ) {
case V_151 :
if ( V_41 [ 0 ] < sizeof( * V_132 ) )
break;
V_132 = ( const struct V_131 * ) V_41 ;
if ( V_30 -> V_56 -> V_57 . V_58 !=
V_132 -> V_152 ) {
F_11 ( & V_30 -> V_11 , L_19 ) ;
goto error;
}
V_13 -> V_9 = F_62 ( V_11 -> V_65 ,
V_132 -> V_153 ) ;
break;
case V_154 :
if ( V_41 [ 0 ] < sizeof( * ( V_13 -> V_78 ) ) )
break;
V_13 -> V_78 =
( const struct V_155 * ) V_41 ;
break;
case V_156 :
if ( V_41 [ 0 ] < sizeof( * ( V_13 -> V_73 ) ) )
break;
V_13 -> V_73 = ( const struct V_157 * ) V_41 ;
break;
case V_158 :
if ( V_41 [ 0 ] < sizeof( * ( V_13 -> V_71 ) ) )
break;
V_13 -> V_71 = ( const struct V_159 * ) V_41 ;
break;
case V_160 :
if ( V_41 [ 0 ] < sizeof( * ( V_13 -> V_108 ) ) )
break;
V_13 -> V_108 =
( const struct V_161 * ) V_41 ;
break;
default:
break;
}
V_150:
V_135 = V_41 [ 0 ] ;
V_41 += V_135 ;
V_47 -= V_135 ;
}
if ( ! V_132 && V_30 -> V_162 && V_30 -> V_162 -> V_163 == 2 ) {
V_13 -> V_9 = F_62 ( V_11 -> V_65 , V_30 -> V_56 -> V_57 . V_58 + 1 ) ;
F_11 ( & V_30 -> V_11 , L_20 ) ;
}
if ( ! V_13 -> V_9 ) {
F_11 ( & V_30 -> V_11 , L_21 ) ;
goto error;
}
if ( F_38 ( V_30 -> V_56 ) ) {
if ( ! V_13 -> V_71 ) {
F_11 ( & V_30 -> V_11 , L_22 ) ;
goto error;
}
} else {
if ( ! V_13 -> V_78 || ! V_13 -> V_73 ) {
F_11 ( & V_30 -> V_11 , L_23 ) ;
goto error;
}
}
if ( V_13 -> V_9 != V_13 -> V_55 ) {
V_135 = F_63 ( V_134 , V_13 -> V_9 , V_11 ) ;
if ( V_135 ) {
F_11 ( & V_30 -> V_11 , L_24 ) ;
goto error;
}
}
V_54 = V_13 -> V_9 -> V_56 -> V_57 . V_58 ;
V_135 = F_64 ( V_11 -> V_65 , V_54 , 0 ) ;
if ( V_135 ) {
F_11 ( & V_30 -> V_11 , L_25 ) ;
goto V_164;
}
if ( F_43 ( V_11 ) )
goto V_164;
V_135 = F_64 ( V_11 -> V_65 , V_54 , V_130 ) ;
if ( V_135 ) {
F_11 ( & V_30 -> V_11 , L_25 ) ;
goto V_164;
}
F_50 ( V_11 , V_13 -> V_9 ) ;
F_50 ( V_11 , V_13 -> V_55 ) ;
if ( ! V_11 -> V_118 || ! V_11 -> V_66 || ! V_11 -> V_125 ) {
F_11 ( & V_30 -> V_11 , L_26 ) ;
goto V_164;
}
F_65 ( V_13 -> V_9 , V_11 ) ;
F_65 ( V_13 -> V_55 , V_11 ) ;
if ( V_13 -> V_78 ) {
V_135 = F_66 ( V_11 , V_13 -> V_78 -> V_165 ) ;
if ( V_135 ) {
F_11 ( & V_30 -> V_11 , L_27 ) ;
goto V_164;
}
F_27 ( & V_30 -> V_11 , L_28 , V_11 -> V_64 -> V_166 ) ;
}
F_49 ( V_11 ) ;
V_11 -> V_64 -> V_167 = & V_168 ;
V_11 -> V_64 -> V_169 [ 0 ] = & V_170 ;
return 0 ;
V_164:
F_65 ( V_13 -> V_55 , NULL ) ;
F_65 ( V_13 -> V_9 , NULL ) ;
if ( V_13 -> V_9 != V_13 -> V_55 )
F_67 ( V_134 , V_13 -> V_9 ) ;
error:
F_54 ( (struct V_12 * ) V_11 -> V_9 [ 0 ] ) ;
V_11 -> V_9 [ 0 ] = 0 ;
F_27 ( & V_30 -> V_11 , L_29 ) ;
return - V_171 ;
}
void F_68 ( struct V_10 * V_11 , struct V_115 * V_30 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
struct V_133 * V_134 = F_61 ( V_30 ) ;
if ( V_13 == NULL )
return;
F_59 ( & V_13 -> V_146 , 1 ) ;
if ( F_69 ( & V_13 -> V_138 ) )
F_70 ( & V_13 -> V_138 ) ;
F_71 ( & V_13 -> V_143 ) ;
if ( V_13 -> V_55 == V_13 -> V_9 )
V_13 -> V_9 = NULL ;
if ( V_30 == V_13 -> V_55 && V_13 -> V_9 ) {
F_65 ( V_13 -> V_9 , NULL ) ;
F_67 ( V_134 , V_13 -> V_9 ) ;
V_13 -> V_9 = NULL ;
} else if ( V_30 == V_13 -> V_9 && V_13 -> V_55 ) {
F_65 ( V_13 -> V_55 , NULL ) ;
F_67 ( V_134 , V_13 -> V_55 ) ;
V_13 -> V_55 = NULL ;
}
F_65 ( V_30 , NULL ) ;
F_54 ( V_13 ) ;
}
T_3 F_72 ( struct V_115 * V_30 )
{
struct V_172 * V_173 ;
if ( V_30 -> V_174 < 2 )
return V_30 -> V_56 -> V_57 . V_175 ;
if ( V_176 ) {
V_173 = F_73 ( V_30 , V_177 ) ;
if ( V_173 && F_38 ( V_173 ) )
return V_177 ;
}
return V_178 ;
}
static int F_74 ( struct V_10 * V_11 , struct V_115 * V_30 )
{
int V_49 ;
if ( F_72 ( V_30 ) != V_178 )
return - V_171 ;
V_49 = F_56 ( V_11 , V_30 , V_179 ) ;
F_75 ( V_11 , 0 , 0 ) ;
return V_49 ;
}
static void F_76 ( struct V_180 * V_181 , T_5 V_182 , T_5 V_183 , T_5 V_24 )
{
T_5 V_184 = F_77 ( V_181 -> V_47 , V_182 ) - V_181 -> V_47 + V_183 ;
if ( V_181 -> V_47 + V_184 > V_24 )
V_184 = V_24 - V_181 -> V_47 ;
if ( V_184 && F_78 ( V_181 ) >= V_184 )
memset ( F_79 ( V_181 , V_184 ) , 0 , V_184 ) ;
}
static struct V_99 * F_80 ( struct V_12 * V_13 , struct V_180 * V_181 , T_6 V_185 , T_5 V_186 )
{
struct V_99 * V_187 = NULL ;
struct V_34 * V_188 = ( void * ) V_181 -> V_9 ;
T_5 V_189 = F_42 ( V_188 -> V_190 ) ;
while ( V_189 ) {
V_187 = (struct V_99 * ) ( V_181 -> V_9 + V_189 ) ;
if ( V_187 -> V_191 == V_185 )
return V_187 ;
V_189 = F_42 ( V_187 -> V_192 ) ;
}
F_76 ( V_181 , V_13 -> V_94 , 0 , V_13 -> V_44 ) ;
if ( ( V_13 -> V_44 - V_181 -> V_47 - V_186 ) < V_13 -> V_33 )
return NULL ;
if ( V_187 )
V_187 -> V_192 = F_47 ( V_181 -> V_47 ) ;
else
V_188 -> V_190 = F_47 ( V_181 -> V_47 ) ;
V_187 = (struct V_99 * ) memset ( F_79 ( V_181 , V_13 -> V_33 ) , 0 , V_13 -> V_33 ) ;
V_187 -> V_191 = V_185 ;
V_187 -> V_193 = F_47 ( sizeof( struct V_99 ) + sizeof( struct V_100 ) ) ;
return V_187 ;
}
struct V_180 *
F_81 ( struct V_10 * V_11 , struct V_180 * V_181 , T_6 V_185 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
struct V_34 * V_188 ;
struct V_99 * V_187 ;
struct V_180 * V_194 ;
V_69 V_195 = 0 , V_196 , V_197 ;
T_3 V_198 = 0 ;
if ( V_181 != NULL ) {
F_82 ( V_181 , V_13 -> V_129 ) ;
F_82 ( V_185 , V_13 -> V_199 ) ;
} else {
V_198 = 1 ;
}
V_194 = V_13 -> V_67 ;
if ( ! V_194 ) {
V_194 = F_83 ( V_13 -> V_44 , V_200 ) ;
if ( V_194 == NULL ) {
if ( V_181 != NULL ) {
F_34 ( V_181 ) ;
V_11 -> V_64 -> V_8 . V_201 ++ ;
}
goto V_202;
}
V_188 = (struct V_34 * ) memset ( F_79 ( V_194 , sizeof( struct V_34 ) ) , 0 , sizeof( struct V_34 ) ) ;
V_188 -> V_191 = F_26 ( V_203 ) ;
V_188 -> V_204 = F_47 ( sizeof( struct V_34 ) ) ;
V_188 -> V_205 = F_47 ( V_13 -> V_206 ++ ) ;
V_13 -> V_207 = 0 ;
V_13 -> V_208 = 0 ;
}
for ( V_195 = V_13 -> V_207 ; V_195 < V_13 -> V_96 ; V_195 ++ ) {
if ( V_181 == NULL ) {
V_181 = V_13 -> V_129 ;
V_185 = V_13 -> V_199 ;
V_13 -> V_129 = NULL ;
if ( V_181 == NULL )
break;
}
V_187 = F_80 ( V_13 , V_194 , V_185 , V_181 -> V_47 + V_13 -> V_92 + V_13 -> V_90 ) ;
F_76 ( V_194 , V_13 -> V_92 , V_13 -> V_90 , V_13 -> V_44 ) ;
if ( ! V_187 || V_194 -> V_47 + V_181 -> V_47 > V_13 -> V_44 ) {
if ( V_195 == 0 ) {
F_34 ( V_181 ) ;
V_181 = NULL ;
V_11 -> V_64 -> V_8 . V_201 ++ ;
} else {
if ( V_13 -> V_129 != NULL ) {
F_34 ( V_13 -> V_129 ) ;
V_11 -> V_64 -> V_8 . V_201 ++ ;
}
V_13 -> V_129 = V_181 ;
V_13 -> V_199 = V_185 ;
V_181 = NULL ;
V_198 = 1 ;
V_13 -> V_209 ++ ;
}
break;
}
V_197 = F_42 ( V_187 -> V_193 ) ;
V_196 = ( V_197 - sizeof( struct V_99 ) ) / sizeof( struct V_100 ) - 1 ;
V_187 -> V_210 [ V_196 ] . V_211 = F_47 ( V_181 -> V_47 ) ;
V_187 -> V_210 [ V_196 ] . V_212 = F_47 ( V_194 -> V_47 ) ;
V_187 -> V_193 = F_47 ( V_197 + sizeof( struct V_100 ) ) ;
memcpy ( F_79 ( V_194 , V_181 -> V_47 ) , V_181 -> V_9 , V_181 -> V_47 ) ;
V_13 -> V_208 += V_181 -> V_47 ;
F_34 ( V_181 ) ;
V_181 = NULL ;
if ( V_196 >= V_98 ) {
V_198 = 1 ;
V_13 -> V_213 ++ ;
break;
}
}
if ( V_181 != NULL ) {
F_34 ( V_181 ) ;
V_181 = NULL ;
V_11 -> V_64 -> V_8 . V_201 ++ ;
}
V_13 -> V_207 = V_195 ;
if ( V_195 == 0 ) {
V_13 -> V_67 = V_194 ;
goto V_202;
} else if ( ( V_195 < V_13 -> V_96 ) && ( V_198 == 0 ) && ( V_13 -> V_45 > 0 ) ) {
V_13 -> V_67 = V_194 ;
if ( V_195 < V_214 )
V_13 -> V_53 = V_215 ;
goto V_202;
} else {
if ( V_195 == V_13 -> V_96 )
V_13 -> V_216 ++ ;
}
if ( ! ( V_11 -> V_217 -> V_218 & V_219 ) &&
V_194 -> V_47 > V_13 -> V_42 )
memset ( F_79 ( V_194 , V_13 -> V_44 - V_194 -> V_47 ) , 0 ,
V_13 -> V_44 - V_194 -> V_47 ) ;
else if ( V_194 -> V_47 < V_13 -> V_44 && ( V_194 -> V_47 % V_11 -> V_220 ) == 0 )
* F_79 ( V_194 , 1 ) = 0 ;
V_188 = (struct V_34 * ) V_194 -> V_9 ;
V_188 -> V_221 = F_47 ( V_194 -> V_47 ) ;
V_13 -> V_67 = NULL ;
V_13 -> V_222 += V_194 -> V_47 - V_13 -> V_208 ;
V_13 -> V_223 ++ ;
F_84 ( V_194 , V_195 ,
V_13 -> V_208 - V_194 -> V_47 ) ;
return V_194 ;
V_202:
if ( V_13 -> V_67 != NULL && V_195 > 0 )
F_85 ( V_13 ) ;
return NULL ;
}
static void F_85 ( struct V_12 * V_13 )
{
if ( ! ( F_69 ( & V_13 -> V_138 ) || F_86 ( & V_13 -> V_146 ) ) )
F_87 ( & V_13 -> V_138 ,
F_88 ( 0 , V_13 -> V_45 ) ,
V_140 ) ;
}
static enum V_224 V_142 ( struct V_225 * V_226 )
{
struct V_12 * V_13 =
F_89 ( V_226 , struct V_12 , V_138 ) ;
if ( ! F_86 ( & V_13 -> V_146 ) )
F_90 ( & V_13 -> V_143 ) ;
return V_227 ;
}
static void V_145 ( unsigned long V_228 )
{
struct V_10 * V_11 = (struct V_10 * ) V_228 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
F_24 ( & V_13 -> V_52 ) ;
if ( V_13 -> V_53 != 0 ) {
V_13 -> V_53 -- ;
F_85 ( V_13 ) ;
F_25 ( & V_13 -> V_52 ) ;
} else if ( V_11 -> V_64 != NULL ) {
V_13 -> V_229 ++ ;
F_25 ( & V_13 -> V_52 ) ;
F_32 ( V_11 -> V_64 ) ;
F_33 ( NULL , V_11 -> V_64 ) ;
F_35 ( V_11 -> V_64 ) ;
} else {
F_25 ( & V_13 -> V_52 ) ;
}
}
struct V_180 *
F_91 ( struct V_10 * V_11 , struct V_180 * V_181 , T_8 V_218 )
{
struct V_180 * V_194 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( V_13 == NULL )
goto error;
F_24 ( & V_13 -> V_52 ) ;
V_194 = F_81 ( V_11 , V_181 , F_26 ( V_230 ) ) ;
F_25 ( & V_13 -> V_52 ) ;
return V_194 ;
error:
if ( V_181 != NULL )
F_34 ( V_181 ) ;
return NULL ;
}
int F_92 ( struct V_12 * V_13 , struct V_180 * V_231 )
{
struct V_10 * V_11 = F_4 ( V_231 -> V_11 ) ;
struct V_34 * V_188 ;
int V_47 ;
int V_49 = - V_48 ;
if ( V_13 == NULL )
goto error;
if ( V_231 -> V_47 < ( sizeof( struct V_34 ) +
sizeof( struct V_99 ) ) ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 , L_30 ) ;
goto error;
}
V_188 = (struct V_34 * ) V_231 -> V_9 ;
if ( V_188 -> V_191 != F_26 ( V_203 ) ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 ,
L_31 ,
F_8 ( V_188 -> V_191 ) ) ;
goto error;
}
V_47 = F_42 ( V_188 -> V_221 ) ;
if ( V_47 > V_13 -> V_43 ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 ,
L_32 , V_47 ,
V_13 -> V_43 ) ;
goto error;
}
if ( ( V_13 -> V_233 + 1 ) != F_42 ( V_188 -> V_205 ) &&
( V_13 -> V_233 || F_42 ( V_188 -> V_205 ) ) &&
! ( ( V_13 -> V_233 == 0xffff ) && ! F_42 ( V_188 -> V_205 ) ) ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 ,
L_33 ,
V_13 -> V_233 , F_42 ( V_188 -> V_205 ) ) ;
}
V_13 -> V_233 = F_42 ( V_188 -> V_205 ) ;
V_49 = F_42 ( V_188 -> V_190 ) ;
error:
return V_49 ;
}
int F_94 ( struct V_180 * V_231 , int V_189 )
{
struct V_10 * V_11 = F_4 ( V_231 -> V_11 ) ;
struct V_99 * V_187 ;
int V_49 = - V_48 ;
if ( ( V_189 + sizeof( struct V_99 ) ) > V_231 -> V_47 ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 , L_34 ,
V_189 ) ;
goto error;
}
V_187 = (struct V_99 * ) ( V_231 -> V_9 + V_189 ) ;
if ( F_42 ( V_187 -> V_193 ) < V_234 ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 , L_35 ,
F_42 ( V_187 -> V_193 ) ) ;
goto error;
}
V_49 = ( ( F_42 ( V_187 -> V_193 ) -
sizeof( struct V_99 ) ) /
sizeof( struct V_100 ) ) ;
V_49 -- ;
if ( ( sizeof( struct V_99 ) +
V_49 * ( sizeof( struct V_100 ) ) ) > V_231 -> V_47 ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 , L_36 , V_49 ) ;
V_49 = - V_48 ;
}
error:
return V_49 ;
}
int F_95 ( struct V_10 * V_11 , struct V_180 * V_231 )
{
struct V_180 * V_181 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
int V_47 ;
int V_235 ;
int V_236 ;
int V_237 ;
struct V_99 * V_187 ;
struct V_100 * V_210 ;
int V_189 ;
int V_238 = 50 ;
V_18 V_239 = 0 ;
V_189 = F_92 ( V_13 , V_231 ) ;
if ( V_189 < 0 )
goto error;
V_240:
V_235 = F_94 ( V_231 , V_189 ) ;
if ( V_235 < 0 )
goto error;
V_187 = (struct V_99 * ) ( V_231 -> V_9 + V_189 ) ;
if ( V_187 -> V_191 != F_26 ( V_230 ) ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 ,
L_37 ,
F_8 ( V_187 -> V_191 ) ) ;
goto V_241;
}
V_210 = V_187 -> V_210 ;
for ( V_236 = 0 ; V_236 < V_235 ; V_236 ++ , V_210 ++ ) {
V_237 = F_42 ( V_210 -> V_212 ) ;
V_47 = F_42 ( V_210 -> V_211 ) ;
if ( ( V_237 == 0 ) || ( V_47 == 0 ) ) {
if ( ! V_236 )
goto V_241;
break;
}
if ( ( ( V_237 + V_47 ) > V_231 -> V_47 ) ||
( V_47 > V_13 -> V_43 ) || ( V_47 < V_74 ) ) {
F_93 ( V_11 , V_232 , V_11 -> V_64 ,
L_38 ,
V_236 , V_237 , V_47 , V_231 ) ;
if ( ! V_236 )
goto V_241;
break;
} else {
V_181 = F_96 ( V_11 -> V_64 , V_47 ) ;
if ( ! V_181 )
goto error;
memcpy ( F_79 ( V_181 , V_47 ) , V_231 -> V_9 + V_237 , V_47 ) ;
F_97 ( V_11 , V_181 ) ;
V_239 += V_47 ;
}
}
V_241:
V_189 = F_42 ( V_187 -> V_192 ) ;
if ( V_189 && V_238 -- )
goto V_240;
V_13 -> V_242 += V_231 -> V_47 - V_239 ;
V_13 -> V_243 ++ ;
return 1 ;
error:
return 0 ;
}
static void
F_98 ( struct V_10 * V_11 ,
struct V_244 * V_9 )
{
T_9 V_245 = F_8 ( V_9 -> V_246 ) ;
T_9 V_247 = F_8 ( V_9 -> V_248 ) ;
if ( ( V_247 > 1000000 ) && ( V_245 > 1000000 ) ) {
F_99 ( V_11 , V_249 , V_11 -> V_64 ,
L_39 ,
( unsigned int ) ( V_245 / 1000000U ) ,
( unsigned int ) ( V_247 / 1000000U ) ) ;
} else {
F_99 ( V_11 , V_249 , V_11 -> V_64 ,
L_40 ,
( unsigned int ) ( V_245 / 1000U ) ,
( unsigned int ) ( V_247 / 1000U ) ) ;
}
}
static void F_100 ( struct V_10 * V_11 , struct V_250 * V_250 )
{
struct V_12 * V_13 ;
struct V_251 * V_252 ;
V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( V_250 -> V_253 < sizeof( * V_252 ) )
return;
if ( F_101 ( V_254 , & V_11 -> V_218 ) ) {
F_98 ( V_11 ,
(struct V_244 * ) V_250 -> V_255 ) ;
return;
}
V_252 = V_250 -> V_255 ;
switch ( V_252 -> V_256 ) {
case V_257 :
F_99 ( V_11 , V_249 , V_11 -> V_64 ,
L_41 ,
! ! V_252 -> V_258 ? L_42 : L_43 ) ;
F_75 ( V_11 , ! ! V_252 -> V_258 , 0 ) ;
break;
case V_259 :
if ( V_250 -> V_253 < ( sizeof( * V_252 ) +
sizeof( struct V_244 ) ) )
F_102 ( V_254 , & V_11 -> V_218 ) ;
else
F_98 ( V_11 ,
(struct V_244 * ) & V_252 [ 1 ] ) ;
break;
default:
F_11 ( & V_11 -> V_65 -> V_11 ,
L_44 ,
V_252 -> V_256 ) ;
break;
}
}
