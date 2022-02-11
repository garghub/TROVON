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
static T_4 F_26 ( struct V_37 * V_38 , struct V_39 * V_40 , char * V_41 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
return sprintf ( V_41 , L_5 , V_13 -> V_54 & V_55 ? 'Y' : 'N' ) ;
}
static T_4 F_27 ( struct V_37 * V_38 , struct V_39 * V_40 , const char * V_41 , T_5 V_47 )
{
struct V_10 * V_11 = F_4 ( F_14 ( V_38 ) ) ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
bool V_56 ;
if ( F_28 ( V_41 , & V_56 ) )
return - V_48 ;
if ( V_56 == ( V_13 -> V_54 & V_55 ) )
return V_47 ;
if ( V_56 && ! V_13 -> V_57 ) {
V_13 -> V_57 = F_29 ( V_13 -> V_33 , V_58 ) ;
if ( ! V_13 -> V_57 )
return - V_59 ;
}
F_30 ( V_11 -> V_60 ) ;
F_31 ( NULL , V_11 -> V_60 ) ;
F_24 ( & V_13 -> V_52 ) ;
if ( V_56 )
V_13 -> V_54 |= V_55 ;
else
V_13 -> V_54 &= ~ V_55 ;
F_25 ( & V_13 -> V_52 ) ;
F_32 ( V_11 -> V_60 ) ;
return V_47 ;
}
static void F_21 ( struct V_10 * V_11 , V_18 V_22 , V_18 V_31 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_3 V_61 = V_13 -> V_62 -> V_63 -> V_64 . V_65 ;
V_18 V_23 ;
V_23 = F_6 ( V_11 , V_22 ) ;
if ( V_23 != V_13 -> V_43 ) {
T_6 V_29 = F_33 ( V_23 ) ;
F_34 ( & V_11 -> V_30 -> V_11 , L_6 , V_23 ) ;
if ( F_35 ( V_11 , V_66 ,
V_67 | V_68
| V_69 ,
0 , V_61 , & V_29 , 4 ) < 0 )
F_11 ( & V_11 -> V_30 -> V_11 , L_7 ) ;
else
V_13 -> V_43 = V_23 ;
}
if ( V_11 -> V_70 != V_13 -> V_43 ) {
V_11 -> V_70 = V_13 -> V_43 ;
if ( F_36 ( V_11 -> V_60 ) )
F_37 ( V_11 ) ;
}
V_23 = F_12 ( V_11 , V_31 ) ;
if ( V_23 != V_13 -> V_44 )
F_34 ( & V_11 -> V_30 -> V_11 , L_8 , V_23 ) ;
if ( V_23 != F_8 ( V_13 -> V_28 . V_36 ) &&
V_23 % F_38 ( V_11 -> V_71 , V_11 -> V_72 , 1 ) == 0 )
V_23 ++ ;
if ( F_36 ( V_11 -> V_60 ) && V_23 > V_13 -> V_44 ) {
F_30 ( V_11 -> V_60 ) ;
F_31 ( NULL , V_11 -> V_60 ) ;
if ( V_13 -> V_73 ) {
F_39 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
V_13 -> V_44 = V_23 ;
F_32 ( V_11 -> V_60 ) ;
} else {
V_13 -> V_44 = V_23 ;
}
V_11 -> V_74 = V_13 -> V_44 ;
F_40 ( V_11 ) ;
V_13 -> V_42 = F_10 ( V_75 , V_13 -> V_44 - 3 * F_38 ( V_11 -> V_71 , V_11 -> V_72 , 1 ) ,
V_76 , V_13 -> V_44 ) ;
}
static T_3 F_41 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( F_42 ( V_11 -> V_30 -> V_63 ) && V_13 -> V_77 )
return V_13 -> V_77 -> V_78 ;
if ( V_13 -> V_79 )
return V_13 -> V_79 -> V_78 ;
return 0 ;
}
static int F_43 ( struct V_10 * V_11 )
{
if ( F_42 ( V_11 -> V_30 -> V_63 ) )
return 0 ;
return V_80 ;
}
static V_18 F_44 ( struct V_10 * V_11 )
{
if ( F_42 ( V_11 -> V_30 -> V_63 ) )
return V_81 ;
return V_82 ;
}
static V_18 F_45 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( F_42 ( V_11 -> V_30 -> V_63 ) && V_13 -> V_77 )
return F_46 ( V_13 -> V_77 -> V_83 ) ;
if ( V_13 -> V_84 )
return F_46 ( V_13 -> V_84 -> V_83 ) ;
return V_85 ;
}
static int F_47 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_3 V_61 = V_13 -> V_62 -> V_63 -> V_64 . V_65 ;
int V_86 ;
V_86 = F_48 ( V_11 , V_87 ,
V_67 | V_88
| V_69 ,
0 , V_61 , & V_13 -> V_28 ,
sizeof( V_13 -> V_28 ) ) ;
if ( V_86 < 0 ) {
F_49 ( & V_11 -> V_30 -> V_11 , L_9 ) ;
return V_86 ;
}
if ( F_41 ( V_11 ) & V_89 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_10 ) ;
V_86 = F_35 ( V_11 , V_90 ,
V_67 | V_68
| V_69 ,
V_91 ,
V_61 , NULL , 0 ) ;
if ( V_86 < 0 )
F_49 ( & V_11 -> V_30 -> V_11 , L_11 ) ;
}
if ( F_46 ( V_13 -> V_28 . V_92 ) &
V_93 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_12 ) ;
V_86 = F_35 ( V_11 , V_94 ,
V_67 | V_68
| V_69 ,
V_95 ,
V_61 , NULL , 0 ) ;
if ( V_86 < 0 )
F_49 ( & V_11 -> V_30 -> V_11 , L_13 ) ;
}
V_13 -> V_43 = F_8 ( V_13 -> V_28 . V_29 ) ;
V_13 -> V_44 = F_8 ( V_13 -> V_28 . V_36 ) ;
V_13 -> V_96 = F_46 ( V_13 -> V_28 . V_97 ) ;
V_13 -> V_98 = F_46 ( V_13 -> V_28 . V_99 ) ;
V_13 -> V_100 = F_46 ( V_13 -> V_28 . V_101 ) ;
V_13 -> V_102 = F_46 ( V_13 -> V_28 . V_103 ) ;
F_11 ( & V_11 -> V_30 -> V_11 ,
L_14 ,
V_13 -> V_43 , V_13 -> V_44 , V_13 -> V_96 , V_13 -> V_98 ,
V_13 -> V_100 , V_13 -> V_102 , F_41 ( V_11 ) ) ;
if ( ( V_13 -> V_102 == 0 ) ||
( V_13 -> V_102 > V_104 ) )
V_13 -> V_102 = V_104 ;
V_13 -> V_33 = sizeof( struct V_105 ) + ( V_13 -> V_102 + 1 ) * sizeof( struct V_106 ) ;
V_13 -> V_45 = V_107 * V_46 ;
return 0 ;
}
static void F_50 ( struct V_10 * V_11 , int V_108 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
T_3 V_61 = V_13 -> V_62 -> V_63 -> V_64 . V_65 ;
T_7 V_32 ;
V_75 V_109 ;
int V_86 ;
V_13 -> V_32 = F_10 ( V_18 , V_108 ,
F_44 ( V_11 ) ,
V_85 ) ;
if ( ! ( F_41 ( V_11 ) & V_110 ) )
goto V_72;
V_86 = F_48 ( V_11 , V_111 ,
V_67 | V_88 | V_69 ,
0 , V_61 , & V_32 , 2 ) ;
if ( V_86 < 0 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_15 ) ;
goto V_72;
}
if ( F_46 ( V_32 ) == V_13 -> V_32 )
goto V_72;
V_32 = F_51 ( V_13 -> V_32 ) ;
V_86 = F_35 ( V_11 , V_112 ,
V_67 | V_68 | V_69 ,
0 , V_61 , & V_32 , 2 ) ;
if ( V_86 < 0 )
F_11 ( & V_11 -> V_30 -> V_11 , L_16 ) ;
V_72:
V_11 -> V_60 -> V_113 = F_7 ( int , V_11 -> V_60 -> V_113 , V_13 -> V_32 - F_43 ( V_11 ) ) ;
if ( V_13 -> V_114 ) {
V_109 = F_46 ( V_13 -> V_114 -> V_115 ) ;
if ( V_109 != 0 && V_109 < V_11 -> V_60 -> V_113 )
V_11 -> V_60 -> V_113 = V_109 ;
}
}
static void F_52 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
V_18 V_23 ;
V_23 = V_13 -> V_100 ;
if ( ( V_23 < V_116 ) ||
( V_23 != ( ( - V_23 ) & V_23 ) ) || ( V_23 >= V_13 -> V_44 ) ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_17 ) ;
V_13 -> V_100 = V_116 ;
}
V_23 = V_13 -> V_98 ;
if ( ( V_23 < V_116 ) ||
( V_23 != ( ( - V_23 ) & V_23 ) ) || ( V_23 >= V_13 -> V_44 ) ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_18 ) ;
V_13 -> V_98 = V_116 ;
}
if ( V_13 -> V_96 >= V_13 -> V_98 ) {
F_11 ( & V_11 -> V_30 -> V_11 , L_19 ) ;
V_13 -> V_96 = 0 ;
}
V_13 -> V_96 = ( ( V_13 -> V_96 - F_43 ( V_11 ) ) &
( V_13 -> V_98 - 1 ) ) ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
V_18 V_117 , V_118 ;
V_117 = F_7 ( V_18 , V_119 ,
F_8 ( V_13 -> V_28 . V_29 ) ) ;
V_118 = F_7 ( V_18 , V_120 ,
F_8 ( V_13 -> V_28 . V_36 ) ) ;
F_21 ( V_11 , V_117 , V_118 ) ;
F_52 ( V_11 ) ;
F_50 ( V_11 , F_45 ( V_11 ) ) ;
return 0 ;
}
static void
F_54 ( struct V_10 * V_11 , struct V_121 * V_30 )
{
struct V_122 * V_123 , * V_124 = NULL , * V_72 = NULL ;
T_3 V_125 ;
for ( V_125 = 0 ; V_125 < V_30 -> V_63 -> V_64 . V_126 ; V_125 ++ ) {
V_123 = V_30 -> V_63 -> V_127 + V_125 ;
switch ( V_123 -> V_64 . V_128 & V_129 ) {
case V_130 :
if ( F_55 ( & V_123 -> V_64 ) ) {
if ( ! V_11 -> V_131 )
V_11 -> V_131 = V_123 ;
}
break;
case V_132 :
if ( F_55 ( & V_123 -> V_64 ) ) {
if ( ! V_124 )
V_124 = V_123 ;
} else {
if ( ! V_72 )
V_72 = V_123 ;
}
break;
default:
break;
}
}
if ( V_124 && ! V_11 -> V_124 )
V_11 -> V_124 = F_56 ( V_11 -> V_71 ,
V_124 -> V_64 . V_133 &
V_134 ) ;
if ( V_72 && ! V_11 -> V_72 )
V_11 -> V_72 = F_57 ( V_11 -> V_71 ,
V_72 -> V_64 . V_133 &
V_134 ) ;
}
static void F_58 ( struct V_12 * V_13 )
{
if ( V_13 == NULL )
return;
if ( V_13 -> V_135 != NULL ) {
F_39 ( V_13 -> V_135 ) ;
V_13 -> V_135 = NULL ;
}
if ( V_13 -> V_73 != NULL ) {
F_39 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
F_59 ( V_13 -> V_57 ) ;
F_59 ( V_13 ) ;
}
int F_60 ( struct V_1 * V_60 , int V_136 )
{
struct V_10 * V_11 = F_4 ( V_60 ) ;
V_60 -> V_113 = V_136 ;
F_50 ( V_11 , V_136 + F_43 ( V_11 ) ) ;
return 0 ;
}
int F_61 ( struct V_10 * V_11 , struct V_121 * V_30 , T_3 V_137 , int V_54 )
{
struct V_12 * V_13 ;
struct V_138 * V_139 ;
T_3 * V_41 ;
int V_47 ;
int V_140 ;
int V_86 ;
T_3 V_61 ;
struct V_141 V_142 ;
V_75 V_143 ;
V_13 = F_29 ( sizeof( * V_13 ) , V_58 ) ;
if ( ! V_13 )
return - V_59 ;
F_62 ( & V_13 -> V_144 , V_145 , V_146 ) ;
V_13 -> V_144 . V_147 = & V_148 ;
V_13 -> V_149 . V_9 = ( unsigned long ) V_11 ;
V_13 -> V_149 . V_150 = V_151 ;
F_63 ( & V_13 -> V_152 , 0 ) ;
F_64 ( & V_13 -> V_52 ) ;
V_11 -> V_9 [ 0 ] = ( unsigned long ) V_13 ;
V_13 -> V_62 = V_30 ;
V_139 = F_65 ( V_30 ) ;
V_41 = V_30 -> V_63 -> V_153 ;
V_47 = V_30 -> V_63 -> V_154 ;
F_66 ( & V_142 , V_30 , V_41 , V_47 ) ;
if ( V_142 . V_155 )
V_13 -> V_9 = F_67 ( V_11 -> V_71 ,
V_142 . V_155 -> V_156 ) ;
V_13 -> V_84 = V_142 . V_157 ;
V_13 -> V_79 = V_142 . V_158 ;
V_13 -> V_77 = V_142 . V_159 ;
V_13 -> V_114 = V_142 . V_160 ;
if ( ! V_142 . V_155 && V_30 -> V_161 && V_30 -> V_161 -> V_162 == 2 ) {
V_13 -> V_9 = F_67 ( V_11 -> V_71 , V_30 -> V_63 -> V_64 . V_65 + 1 ) ;
F_11 ( & V_30 -> V_11 , L_20 ) ;
}
if ( ! V_13 -> V_9 ) {
F_11 ( & V_30 -> V_11 , L_21 ) ;
goto error;
}
if ( F_42 ( V_30 -> V_63 ) ) {
if ( ! V_13 -> V_77 ) {
F_11 ( & V_30 -> V_11 , L_22 ) ;
goto error;
}
} else {
if ( ! V_13 -> V_84 || ! V_13 -> V_79 ) {
F_11 ( & V_30 -> V_11 , L_23 ) ;
goto error;
}
}
if ( V_13 -> V_9 != V_13 -> V_62 ) {
V_140 = F_68 ( V_139 , V_13 -> V_9 , V_11 ) ;
if ( V_140 ) {
F_11 ( & V_30 -> V_11 , L_24 ) ;
goto error;
}
}
V_61 = V_13 -> V_9 -> V_63 -> V_64 . V_65 ;
V_13 -> V_54 = V_54 ;
if ( ! ( V_13 -> V_54 & V_163 ) )
F_69 ( V_11 -> V_71 , V_61 , V_137 ) ;
V_140 = F_69 ( V_11 -> V_71 , V_61 , 0 ) ;
if ( V_140 ) {
F_11 ( & V_30 -> V_11 , L_25 ) ;
goto V_164;
}
if ( F_47 ( V_11 ) )
goto V_164;
F_70 ( 10000 , 20000 ) ;
V_140 = F_69 ( V_11 -> V_71 , V_61 , V_137 ) ;
if ( V_140 ) {
F_11 ( & V_30 -> V_11 , L_25 ) ;
goto V_164;
}
if ( V_13 -> V_54 & V_165 ) {
V_86 = F_48 ( V_11 , V_166 ,
V_67 | V_88 | V_69 ,
0 , V_61 , & V_143 , 2 ) ;
if ( V_86 < 0 ) {
goto V_164;
}
if ( V_143 == V_167 ) {
F_34 ( & V_30 -> V_11 , L_26 ) ;
V_86 = F_35 ( V_11 , V_94 ,
V_67 | V_68
| V_69 ,
V_95 ,
V_61 , NULL , 0 ) ;
if ( V_86 < 0 )
goto V_164;
}
}
F_54 ( V_11 , V_13 -> V_9 ) ;
F_54 ( V_11 , V_13 -> V_62 ) ;
if ( ! V_11 -> V_124 || ! V_11 -> V_72 || ! V_11 -> V_131 ) {
F_11 ( & V_30 -> V_11 , L_27 ) ;
goto V_164;
}
F_71 ( V_13 -> V_9 , V_11 ) ;
F_71 ( V_13 -> V_62 , V_11 ) ;
if ( V_13 -> V_84 ) {
V_140 = F_72 ( V_11 , V_13 -> V_84 -> V_168 ) ;
if ( V_140 ) {
F_11 ( & V_30 -> V_11 , L_28 ) ;
goto V_164;
}
F_34 ( & V_30 -> V_11 , L_29 , V_11 -> V_60 -> V_169 ) ;
}
F_53 ( V_11 ) ;
if ( V_13 -> V_54 & V_55 ) {
V_13 -> V_57 = F_29 ( V_13 -> V_33 , V_58 ) ;
if ( ! V_13 -> V_57 )
goto V_164;
F_34 ( & V_30 -> V_11 , L_30 ) ;
}
V_11 -> V_60 -> V_170 = & V_171 ;
V_11 -> V_60 -> V_172 [ 0 ] = & V_173 ;
V_11 -> V_60 -> V_174 = & V_175 ;
V_11 -> V_60 -> V_176 = F_45 ( V_11 ) - F_43 ( V_11 ) ;
return 0 ;
V_164:
F_71 ( V_13 -> V_62 , NULL ) ;
F_71 ( V_13 -> V_9 , NULL ) ;
if ( V_13 -> V_9 != V_13 -> V_62 )
F_73 ( V_139 , V_13 -> V_9 ) ;
error:
F_58 ( (struct V_12 * ) V_11 -> V_9 [ 0 ] ) ;
V_11 -> V_9 [ 0 ] = 0 ;
F_34 ( & V_30 -> V_11 , L_31 ) ;
return - V_177 ;
}
void F_74 ( struct V_10 * V_11 , struct V_121 * V_30 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
struct V_138 * V_139 = F_65 ( V_30 ) ;
if ( V_13 == NULL )
return;
F_63 ( & V_13 -> V_152 , 1 ) ;
if ( F_75 ( & V_13 -> V_144 ) )
F_76 ( & V_13 -> V_144 ) ;
F_77 ( & V_13 -> V_149 ) ;
if ( V_13 -> V_62 == V_13 -> V_9 )
V_13 -> V_9 = NULL ;
if ( V_30 == V_13 -> V_62 && V_13 -> V_9 ) {
F_71 ( V_13 -> V_9 , NULL ) ;
F_73 ( V_139 , V_13 -> V_9 ) ;
V_13 -> V_9 = NULL ;
} else if ( V_30 == V_13 -> V_9 && V_13 -> V_62 ) {
F_71 ( V_13 -> V_62 , NULL ) ;
F_73 ( V_139 , V_13 -> V_62 ) ;
V_13 -> V_62 = NULL ;
}
F_71 ( V_30 , NULL ) ;
F_58 ( V_13 ) ;
}
T_3 F_78 ( struct V_121 * V_30 )
{
struct V_178 * V_179 ;
if ( V_30 -> V_180 < 2 )
return V_30 -> V_63 -> V_64 . V_181 ;
if ( V_182 ) {
V_179 = F_79 ( V_30 , V_183 ) ;
if ( V_179 && F_42 ( V_179 ) )
return V_183 ;
}
return V_184 ;
}
static int F_80 ( struct V_10 * V_11 , struct V_121 * V_30 )
{
if ( F_78 ( V_30 ) != V_184 )
return - V_177 ;
return F_61 ( V_11 , V_30 , V_185 , 0 ) ;
}
static void F_81 ( struct V_186 * V_187 , T_5 V_188 , T_5 V_189 , T_5 V_24 )
{
T_5 V_190 = F_82 ( V_187 -> V_47 , V_188 ) - V_187 -> V_47 + V_189 ;
if ( V_187 -> V_47 + V_190 > V_24 )
V_190 = V_24 - V_187 -> V_47 ;
if ( V_190 && F_83 ( V_187 ) >= V_190 )
F_84 ( V_187 , V_190 ) ;
}
static struct V_105 * F_85 ( struct V_12 * V_13 , struct V_186 * V_187 , T_6 V_191 , T_5 V_192 )
{
struct V_105 * V_193 = NULL ;
struct V_34 * V_194 = ( void * ) V_187 -> V_9 ;
T_5 V_195 = F_46 ( V_194 -> V_196 ) ;
if ( V_13 -> V_54 & V_55 ) {
if ( V_13 -> V_57 -> V_197 == V_191 )
return V_13 -> V_57 ;
else if ( V_13 -> V_57 -> V_197 )
return NULL ;
}
while ( V_195 ) {
V_193 = (struct V_105 * ) ( V_187 -> V_9 + V_195 ) ;
if ( V_193 -> V_197 == V_191 )
return V_193 ;
V_195 = F_46 ( V_193 -> V_198 ) ;
}
if ( ! ( V_13 -> V_54 & V_55 ) )
F_81 ( V_187 , V_13 -> V_100 , 0 , V_13 -> V_199 ) ;
if ( ( V_13 -> V_199 - V_187 -> V_47 - V_192 ) < V_13 -> V_33 )
return NULL ;
if ( V_193 )
V_193 -> V_198 = F_51 ( V_187 -> V_47 ) ;
else
V_194 -> V_196 = F_51 ( V_187 -> V_47 ) ;
if ( ! ( V_13 -> V_54 & V_55 ) )
V_193 = F_84 ( V_187 , V_13 -> V_33 ) ;
else
V_193 = V_13 -> V_57 ;
V_193 -> V_197 = V_191 ;
V_193 -> V_200 = F_51 ( sizeof( struct V_105 ) + sizeof( struct V_106 ) ) ;
return V_193 ;
}
struct V_186 *
F_86 ( struct V_10 * V_11 , struct V_186 * V_187 , T_6 V_191 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
struct V_34 * V_194 ;
struct V_105 * V_193 ;
struct V_186 * V_201 ;
V_75 V_202 = 0 , V_203 , V_204 ;
T_3 V_205 = 0 ;
V_18 V_206 ;
T_5 V_207 ;
if ( V_13 -> V_54 & V_55 )
V_206 = V_13 -> V_33 ;
else
V_206 = 0 ;
if ( V_187 != NULL ) {
F_87 ( V_187 , V_13 -> V_135 ) ;
F_87 ( V_191 , V_13 -> V_208 ) ;
} else {
V_205 = 1 ;
}
V_201 = V_13 -> V_73 ;
if ( ! V_201 ) {
if ( V_13 -> V_209 == 0 ) {
V_13 -> V_199 = V_13 -> V_44 ;
V_201 = F_88 ( V_13 -> V_199 , V_210 ) ;
if ( V_201 == NULL ) {
V_13 -> V_211 = V_25 ( V_13 -> V_211 + 1 ,
( unsigned ) V_212 ) ;
V_13 -> V_209 = V_13 -> V_211 ;
}
}
if ( V_201 == NULL ) {
if ( V_187 )
V_13 -> V_199 = V_24 ( V_187 -> V_47 ,
( V_18 ) V_213 ) ;
else
V_13 -> V_199 = V_213 ;
V_201 = F_88 ( V_13 -> V_199 , V_210 ) ;
if ( V_201 == NULL ) {
if ( V_187 != NULL ) {
F_39 ( V_187 ) ;
V_11 -> V_60 -> V_8 . V_214 ++ ;
}
goto V_215;
}
V_13 -> V_209 -- ;
}
V_194 = F_84 ( V_201 , sizeof( struct V_34 ) ) ;
V_194 -> V_197 = F_33 ( V_216 ) ;
V_194 -> V_217 = F_51 ( sizeof( struct V_34 ) ) ;
V_194 -> V_218 = F_51 ( V_13 -> V_219 ++ ) ;
V_13 -> V_220 = 0 ;
V_13 -> V_221 = 0 ;
}
for ( V_202 = V_13 -> V_220 ; V_202 < V_13 -> V_102 ; V_202 ++ ) {
if ( V_187 == NULL ) {
V_187 = V_13 -> V_135 ;
V_191 = V_13 -> V_208 ;
V_13 -> V_135 = NULL ;
if ( V_187 == NULL )
break;
}
V_193 = F_85 ( V_13 , V_201 , V_191 , V_187 -> V_47 + V_13 -> V_98 + V_13 -> V_96 ) ;
F_81 ( V_201 , V_13 -> V_98 , V_13 -> V_96 , V_13 -> V_199 ) ;
if ( ! V_193 || V_201 -> V_47 + V_187 -> V_47 + V_206 > V_13 -> V_199 ) {
if ( V_202 == 0 ) {
F_39 ( V_187 ) ;
V_187 = NULL ;
V_11 -> V_60 -> V_8 . V_214 ++ ;
} else {
if ( V_13 -> V_135 != NULL ) {
F_39 ( V_13 -> V_135 ) ;
V_11 -> V_60 -> V_8 . V_214 ++ ;
}
V_13 -> V_135 = V_187 ;
V_13 -> V_208 = V_191 ;
V_187 = NULL ;
V_205 = 1 ;
V_13 -> V_222 ++ ;
}
break;
}
V_204 = F_46 ( V_193 -> V_200 ) ;
V_203 = ( V_204 - sizeof( struct V_105 ) ) / sizeof( struct V_106 ) - 1 ;
V_193 -> V_223 [ V_203 ] . V_224 = F_51 ( V_187 -> V_47 ) ;
V_193 -> V_223 [ V_203 ] . V_225 = F_51 ( V_201 -> V_47 ) ;
V_193 -> V_200 = F_51 ( V_204 + sizeof( struct V_106 ) ) ;
F_89 ( V_201 , V_187 -> V_9 , V_187 -> V_47 ) ;
V_13 -> V_221 += V_187 -> V_47 ;
F_39 ( V_187 ) ;
V_187 = NULL ;
if ( V_203 >= V_104 ) {
V_205 = 1 ;
V_13 -> V_226 ++ ;
break;
}
}
if ( V_187 != NULL ) {
F_39 ( V_187 ) ;
V_187 = NULL ;
V_11 -> V_60 -> V_8 . V_214 ++ ;
}
V_13 -> V_220 = V_202 ;
if ( V_202 == 0 ) {
V_13 -> V_73 = V_201 ;
goto V_215;
} else if ( ( V_202 < V_13 -> V_102 ) && ( V_205 == 0 ) && ( V_13 -> V_45 > 0 ) ) {
V_13 -> V_73 = V_201 ;
if ( V_202 < V_227 )
V_13 -> V_53 = V_228 ;
goto V_215;
} else {
if ( V_202 == V_13 -> V_102 )
V_13 -> V_229 ++ ;
}
if ( V_13 -> V_54 & V_55 ) {
V_194 = (struct V_34 * ) V_201 -> V_9 ;
F_81 ( V_201 , V_13 -> V_100 , 0 , V_13 -> V_199 ) ;
V_194 -> V_196 = F_51 ( V_201 -> V_47 ) ;
F_89 ( V_201 , V_13 -> V_57 , V_13 -> V_33 ) ;
V_193 = memset ( V_13 -> V_57 , 0 , V_13 -> V_33 ) ;
}
if ( ! ( V_11 -> V_230 -> V_231 & V_232 ) &&
V_201 -> V_47 > V_13 -> V_42 ) {
V_207 = V_13 -> V_199 - V_201 -> V_47 ;
F_84 ( V_201 , V_207 ) ;
} else if ( V_201 -> V_47 < V_13 -> V_199 &&
( V_201 -> V_47 % V_11 -> V_233 ) == 0 ) {
F_90 ( V_201 , 0 ) ;
}
V_194 = (struct V_34 * ) V_201 -> V_9 ;
V_194 -> V_234 = F_51 ( V_201 -> V_47 ) ;
V_13 -> V_73 = NULL ;
V_13 -> V_235 += V_201 -> V_47 - V_13 -> V_221 ;
V_13 -> V_236 ++ ;
F_91 ( V_201 , V_202 ,
( long ) V_13 -> V_221 - V_201 -> V_47 ) ;
return V_201 ;
V_215:
if ( V_13 -> V_73 != NULL && V_202 > 0 )
F_92 ( V_13 ) ;
return NULL ;
}
static void F_92 ( struct V_12 * V_13 )
{
if ( ! ( F_75 ( & V_13 -> V_144 ) || F_93 ( & V_13 -> V_152 ) ) )
F_94 ( & V_13 -> V_144 ,
V_13 -> V_45 ,
V_146 ) ;
}
static enum V_237 V_148 ( struct V_238 * V_239 )
{
struct V_12 * V_13 =
F_95 ( V_239 , struct V_12 , V_144 ) ;
if ( ! F_93 ( & V_13 -> V_152 ) )
F_96 ( & V_13 -> V_149 ) ;
return V_240 ;
}
static void V_151 ( unsigned long V_241 )
{
struct V_10 * V_11 = (struct V_10 * ) V_241 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
F_24 ( & V_13 -> V_52 ) ;
if ( V_13 -> V_53 != 0 ) {
V_13 -> V_53 -- ;
F_92 ( V_13 ) ;
F_25 ( & V_13 -> V_52 ) ;
} else if ( V_11 -> V_60 != NULL ) {
V_13 -> V_242 ++ ;
F_25 ( & V_13 -> V_52 ) ;
F_30 ( V_11 -> V_60 ) ;
F_31 ( NULL , V_11 -> V_60 ) ;
F_32 ( V_11 -> V_60 ) ;
} else {
F_25 ( & V_13 -> V_52 ) ;
}
}
struct V_186 *
F_97 ( struct V_10 * V_11 , struct V_186 * V_187 , T_8 V_231 )
{
struct V_186 * V_201 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( V_13 == NULL )
goto error;
F_24 ( & V_13 -> V_52 ) ;
V_201 = F_86 ( V_11 , V_187 , F_33 ( V_243 ) ) ;
F_25 ( & V_13 -> V_52 ) ;
return V_201 ;
error:
if ( V_187 != NULL )
F_39 ( V_187 ) ;
return NULL ;
}
int F_98 ( struct V_12 * V_13 , struct V_186 * V_244 )
{
struct V_10 * V_11 = F_4 ( V_244 -> V_11 ) ;
struct V_34 * V_194 ;
int V_47 ;
int V_49 = - V_48 ;
if ( V_13 == NULL )
goto error;
if ( V_244 -> V_47 < ( sizeof( struct V_34 ) +
sizeof( struct V_105 ) ) ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 , L_32 ) ;
goto error;
}
V_194 = (struct V_34 * ) V_244 -> V_9 ;
if ( V_194 -> V_197 != F_33 ( V_216 ) ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 ,
L_33 ,
F_8 ( V_194 -> V_197 ) ) ;
goto error;
}
V_47 = F_46 ( V_194 -> V_234 ) ;
if ( V_47 > V_13 -> V_43 ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 ,
L_34 , V_47 ,
V_13 -> V_43 ) ;
goto error;
}
if ( ( V_13 -> V_246 + 1 ) != F_46 ( V_194 -> V_218 ) &&
( V_13 -> V_246 || F_46 ( V_194 -> V_218 ) ) &&
! ( ( V_13 -> V_246 == 0xffff ) && ! F_46 ( V_194 -> V_218 ) ) ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 ,
L_35 ,
V_13 -> V_246 , F_46 ( V_194 -> V_218 ) ) ;
}
V_13 -> V_246 = F_46 ( V_194 -> V_218 ) ;
V_49 = F_46 ( V_194 -> V_196 ) ;
error:
return V_49 ;
}
int F_100 ( struct V_186 * V_244 , int V_195 )
{
struct V_10 * V_11 = F_4 ( V_244 -> V_11 ) ;
struct V_105 * V_193 ;
int V_49 = - V_48 ;
if ( ( V_195 + sizeof( struct V_105 ) ) > V_244 -> V_47 ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 , L_36 ,
V_195 ) ;
goto error;
}
V_193 = (struct V_105 * ) ( V_244 -> V_9 + V_195 ) ;
if ( F_46 ( V_193 -> V_200 ) < V_247 ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 , L_37 ,
F_46 ( V_193 -> V_200 ) ) ;
goto error;
}
V_49 = ( ( F_46 ( V_193 -> V_200 ) -
sizeof( struct V_105 ) ) /
sizeof( struct V_106 ) ) ;
V_49 -- ;
if ( ( sizeof( struct V_105 ) +
V_49 * ( sizeof( struct V_106 ) ) ) > V_244 -> V_47 ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 , L_38 , V_49 ) ;
V_49 = - V_48 ;
}
error:
return V_49 ;
}
int F_101 ( struct V_10 * V_11 , struct V_186 * V_244 )
{
struct V_186 * V_187 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
int V_47 ;
int V_248 ;
int V_249 ;
int V_250 ;
struct V_105 * V_193 ;
struct V_106 * V_223 ;
int V_195 ;
int V_251 = 50 ;
V_18 V_252 = 0 ;
V_195 = F_98 ( V_13 , V_244 ) ;
if ( V_195 < 0 )
goto error;
V_253:
V_248 = F_100 ( V_244 , V_195 ) ;
if ( V_248 < 0 )
goto error;
V_193 = (struct V_105 * ) ( V_244 -> V_9 + V_195 ) ;
if ( V_193 -> V_197 != F_33 ( V_243 ) ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 ,
L_39 ,
F_8 ( V_193 -> V_197 ) ) ;
goto V_254;
}
V_223 = V_193 -> V_223 ;
for ( V_249 = 0 ; V_249 < V_248 ; V_249 ++ , V_223 ++ ) {
V_250 = F_46 ( V_223 -> V_225 ) ;
V_47 = F_46 ( V_223 -> V_224 ) ;
if ( ( V_250 == 0 ) || ( V_47 == 0 ) ) {
if ( ! V_249 )
goto V_254;
break;
}
if ( ( ( V_250 + V_47 ) > V_244 -> V_47 ) ||
( V_47 > V_13 -> V_43 ) || ( V_47 < V_80 ) ) {
F_99 ( V_11 , V_245 , V_11 -> V_60 ,
L_40 ,
V_249 , V_250 , V_47 , V_244 ) ;
if ( ! V_249 )
goto V_254;
break;
} else {
V_187 = F_102 ( V_11 -> V_60 , V_47 ) ;
if ( ! V_187 )
goto error;
F_89 ( V_187 , V_244 -> V_9 + V_250 , V_47 ) ;
F_103 ( V_11 , V_187 ) ;
V_252 += V_47 ;
}
}
V_254:
V_195 = F_46 ( V_193 -> V_198 ) ;
if ( V_195 && V_251 -- )
goto V_253;
V_13 -> V_255 += V_244 -> V_47 - V_252 ;
V_13 -> V_256 ++ ;
return 1 ;
error:
return 0 ;
}
static void
F_104 ( struct V_10 * V_11 ,
struct V_257 * V_9 )
{
T_9 V_258 = F_8 ( V_9 -> V_259 ) ;
T_9 V_260 = F_8 ( V_9 -> V_261 ) ;
if ( ( V_260 > 1000000 ) && ( V_258 > 1000000 ) ) {
F_105 ( V_11 , V_262 , V_11 -> V_60 ,
L_41 ,
( unsigned int ) ( V_258 / 1000000U ) ,
( unsigned int ) ( V_260 / 1000000U ) ) ;
} else {
F_105 ( V_11 , V_262 , V_11 -> V_60 ,
L_42 ,
( unsigned int ) ( V_258 / 1000U ) ,
( unsigned int ) ( V_260 / 1000U ) ) ;
}
}
static void F_106 ( struct V_10 * V_11 , struct V_263 * V_263 )
{
struct V_12 * V_13 ;
struct V_264 * V_265 ;
V_13 = (struct V_12 * ) V_11 -> V_9 [ 0 ] ;
if ( V_263 -> V_266 < sizeof( * V_265 ) )
return;
if ( F_107 ( V_267 , & V_11 -> V_231 ) ) {
F_104 ( V_11 ,
(struct V_257 * ) V_263 -> V_268 ) ;
return;
}
V_265 = V_263 -> V_268 ;
switch ( V_265 -> V_269 ) {
case V_270 :
F_105 ( V_11 , V_262 , V_11 -> V_60 ,
L_43 ,
! ! V_265 -> V_271 ? L_44 : L_45 ) ;
F_108 ( V_11 , ! ! V_265 -> V_271 , 0 ) ;
break;
case V_272 :
if ( V_263 -> V_266 < ( sizeof( * V_265 ) +
sizeof( struct V_257 ) ) )
F_109 ( V_267 , & V_11 -> V_231 ) ;
else
F_104 ( V_11 ,
(struct V_257 * ) & V_265 [ 1 ] ) ;
break;
default:
F_11 ( & V_11 -> V_71 -> V_11 ,
L_46 ,
V_265 -> V_269 ) ;
break;
}
}
