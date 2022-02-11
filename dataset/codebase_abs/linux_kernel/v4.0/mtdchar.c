static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
return F_2 ( V_1 , V_2 , V_3 , V_5 -> V_7 -> V_8 ) ;
}
static int F_3 ( struct V_9 * V_9 , struct V_1 * V_1 )
{
int V_10 = F_4 ( V_9 ) ;
int V_11 = V_10 >> 1 ;
int V_12 = 0 ;
struct V_13 * V_7 ;
struct V_4 * V_5 ;
F_5 ( L_1 ) ;
if ( ( V_1 -> V_14 & V_15 ) && ( V_10 & 1 ) )
return - V_16 ;
F_6 ( & V_17 ) ;
V_7 = F_7 ( NULL , V_11 ) ;
if ( F_8 ( V_7 ) ) {
V_12 = F_9 ( V_7 ) ;
goto V_18;
}
if ( V_7 -> type == V_19 ) {
V_12 = - V_20 ;
goto V_21;
}
if ( ( V_1 -> V_14 & V_15 ) && ! ( V_7 -> V_22 & V_23 ) ) {
V_12 = - V_16 ;
goto V_21;
}
V_5 = F_10 ( sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 ) {
V_12 = - V_25 ;
goto V_21;
}
V_5 -> V_7 = V_7 ;
V_1 -> V_6 = V_5 ;
F_11 ( & V_17 ) ;
return 0 ;
V_21:
F_12 ( V_7 ) ;
V_18:
F_11 ( & V_17 ) ;
return V_12 ;
}
static int F_13 ( struct V_9 * V_9 , struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
F_5 ( L_2 ) ;
if ( ( V_1 -> V_14 & V_15 ) )
F_14 ( V_7 ) ;
F_12 ( V_7 ) ;
V_1 -> V_6 = NULL ;
F_15 ( V_5 ) ;
return 0 ;
}
static T_2 F_16 ( struct V_1 * V_1 , char T_3 * V_26 , T_4 V_27 ,
T_1 * V_28 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
T_4 V_29 ;
T_4 V_30 = 0 ;
int V_12 = 0 ;
int V_31 ;
T_4 V_8 = V_27 ;
char * V_32 ;
F_5 ( L_3 ) ;
if ( * V_28 + V_27 > V_7 -> V_8 )
V_27 = V_7 -> V_8 - * V_28 ;
if ( ! V_27 )
return 0 ;
V_32 = F_17 ( V_7 , & V_8 ) ;
if ( ! V_32 )
return - V_25 ;
while ( V_27 ) {
V_31 = F_18 ( T_4 , V_27 , V_8 ) ;
switch ( V_5 -> V_33 ) {
case V_34 :
V_12 = F_19 ( V_7 , * V_28 , V_31 ,
& V_29 , V_32 ) ;
break;
case V_35 :
V_12 = F_20 ( V_7 , * V_28 , V_31 ,
& V_29 , V_32 ) ;
break;
case V_36 :
{
struct V_37 V_38 ;
V_38 . V_33 = V_39 ;
V_38 . V_40 = V_32 ;
V_38 . V_41 = NULL ;
V_38 . V_31 = V_31 ;
V_12 = F_21 ( V_7 , * V_28 , & V_38 ) ;
V_29 = V_38 . V_29 ;
break;
}
default:
V_12 = F_22 ( V_7 , * V_28 , V_31 , & V_29 , V_32 ) ;
}
if ( ! V_12 || F_23 ( V_12 ) ) {
* V_28 += V_29 ;
if ( F_24 ( V_26 , V_32 , V_29 ) ) {
F_15 ( V_32 ) ;
return - V_42 ;
}
else
V_30 += V_29 ;
V_27 -= V_29 ;
V_26 += V_29 ;
if ( V_29 == 0 )
V_27 = 0 ;
}
else {
F_15 ( V_32 ) ;
return V_12 ;
}
}
F_15 ( V_32 ) ;
return V_30 ;
}
static T_2 F_25 ( struct V_1 * V_1 , const char T_3 * V_26 , T_4 V_27 ,
T_1 * V_28 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
T_4 V_8 = V_27 ;
char * V_32 ;
T_4 V_29 ;
T_4 V_30 = 0 ;
int V_12 = 0 ;
int V_31 ;
F_5 ( L_4 ) ;
if ( * V_28 == V_7 -> V_8 )
return - V_43 ;
if ( * V_28 + V_27 > V_7 -> V_8 )
V_27 = V_7 -> V_8 - * V_28 ;
if ( ! V_27 )
return 0 ;
V_32 = F_17 ( V_7 , & V_8 ) ;
if ( ! V_32 )
return - V_25 ;
while ( V_27 ) {
V_31 = F_18 ( T_4 , V_27 , V_8 ) ;
if ( F_26 ( V_32 , V_26 , V_31 ) ) {
F_15 ( V_32 ) ;
return - V_42 ;
}
switch ( V_5 -> V_33 ) {
case V_34 :
V_12 = - V_44 ;
break;
case V_35 :
V_12 = F_27 ( V_7 , * V_28 , V_31 ,
& V_29 , V_32 ) ;
break;
case V_36 :
{
struct V_37 V_38 ;
V_38 . V_33 = V_39 ;
V_38 . V_40 = V_32 ;
V_38 . V_41 = NULL ;
V_38 . V_45 = 0 ;
V_38 . V_31 = V_31 ;
V_12 = F_28 ( V_7 , * V_28 , & V_38 ) ;
V_29 = V_38 . V_29 ;
break;
}
default:
V_12 = F_29 ( V_7 , * V_28 , V_31 , & V_29 , V_32 ) ;
}
if ( ( V_12 == - V_43 ) && ( V_30 ) )
break;
if ( ! V_12 ) {
* V_28 += V_29 ;
V_30 += V_29 ;
V_27 -= V_29 ;
V_26 += V_29 ;
}
else {
F_15 ( V_32 ) ;
return V_12 ;
}
}
F_15 ( V_32 ) ;
return V_30 ;
}
static void F_30 ( struct V_46 * V_47 )
{
F_31 ( ( V_48 * ) V_47 -> V_49 ) ;
}
static int F_32 ( struct V_4 * V_5 , int V_33 )
{
struct V_13 * V_7 = V_5 -> V_7 ;
T_4 V_29 ;
switch ( V_33 ) {
case V_50 :
if ( F_19 ( V_7 , - 1 , 0 , & V_29 , NULL ) ==
- V_51 )
return - V_51 ;
V_5 -> V_33 = V_34 ;
break;
case V_52 :
if ( F_20 ( V_7 , - 1 , 0 , & V_29 , NULL ) ==
- V_51 )
return - V_51 ;
V_5 -> V_33 = V_35 ;
break;
case V_53 :
V_5 -> V_33 = V_54 ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_13 * V_7 ,
T_5 V_56 , T_6 V_57 , void T_3 * V_58 ,
T_6 T_3 * V_59 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_37 V_38 ;
T_6 V_29 ;
int V_12 = 0 ;
if ( ! ( V_1 -> V_14 & V_15 ) )
return - V_60 ;
if ( V_57 > 4096 )
return - V_55 ;
if ( ! V_7 -> V_61 )
V_12 = - V_51 ;
else
V_12 = F_34 ( V_62 , V_58 , V_57 ) ? 0 : - V_42 ;
if ( V_12 )
return V_12 ;
V_38 . V_63 = V_57 ;
V_38 . V_45 = V_56 & ( V_7 -> V_64 - 1 ) ;
V_38 . V_40 = NULL ;
V_38 . V_33 = ( V_5 -> V_33 == V_36 ) ? V_39 :
V_65 ;
if ( V_38 . V_45 && V_38 . V_63 > ( V_7 -> V_66 - V_38 . V_45 ) )
return - V_55 ;
V_38 . V_41 = F_35 ( V_58 , V_57 ) ;
if ( F_8 ( V_38 . V_41 ) )
return F_9 ( V_38 . V_41 ) ;
V_56 &= ~ ( ( T_5 ) V_7 -> V_64 - 1 ) ;
V_12 = F_28 ( V_7 , V_56 , & V_38 ) ;
if ( V_38 . V_67 > 0xFFFFFFFFU )
V_12 = - V_68 ;
V_29 = V_38 . V_67 ;
if ( F_24 ( V_59 , & V_29 , sizeof( V_57 ) ) )
V_12 = - V_42 ;
F_15 ( V_38 . V_41 ) ;
return V_12 ;
}
static int F_36 ( struct V_1 * V_1 , struct V_13 * V_7 ,
T_5 V_56 , T_6 V_57 , void T_3 * V_58 ,
T_6 T_3 * V_59 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_37 V_38 ;
int V_12 = 0 ;
if ( V_57 > 4096 )
return - V_55 ;
if ( ! F_34 ( V_69 , V_58 , V_57 ) )
return - V_42 ;
V_38 . V_63 = V_57 ;
V_38 . V_45 = V_56 & ( V_7 -> V_64 - 1 ) ;
V_38 . V_40 = NULL ;
V_38 . V_33 = ( V_5 -> V_33 == V_36 ) ? V_39 :
V_65 ;
if ( V_38 . V_45 && V_38 . V_63 > ( V_7 -> V_66 - V_38 . V_45 ) )
return - V_55 ;
V_38 . V_41 = F_37 ( V_57 , V_24 ) ;
if ( ! V_38 . V_41 )
return - V_25 ;
V_56 &= ~ ( ( T_5 ) V_7 -> V_64 - 1 ) ;
V_12 = F_21 ( V_7 , V_56 , & V_38 ) ;
if ( F_38 ( V_38 . V_67 , V_59 ) )
V_12 = - V_42 ;
else if ( V_38 . V_67 && F_24 ( V_58 , V_38 . V_41 ,
V_38 . V_67 ) )
V_12 = - V_42 ;
F_15 ( V_38 . V_41 ) ;
if ( F_23 ( V_12 ) )
return 0 ;
return V_12 ;
}
static int F_39 ( const struct V_70 * V_71 ,
struct V_72 * V_73 )
{
int V_74 ;
if ( ! V_71 || ! V_73 )
return - V_55 ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
V_73 -> V_75 = F_40 ( ( int ) V_71 -> V_75 , V_76 ) ;
for ( V_74 = 0 ; V_74 < V_73 -> V_75 ; V_74 ++ )
V_73 -> V_77 [ V_74 ] = V_71 -> V_77 [ V_74 ] ;
for ( V_74 = 0 ; V_74 < V_78 ; V_74 ++ ) {
if ( V_71 -> V_79 [ V_74 ] . V_57 == 0 &&
V_71 -> V_79 [ V_74 ] . V_2 == 0 )
break;
V_73 -> V_80 += V_71 -> V_79 [ V_74 ] . V_57 ;
V_73 -> V_79 [ V_74 ] = V_71 -> V_79 [ V_74 ] ;
}
return 0 ;
}
static int F_41 ( struct V_13 * V_7 ,
struct V_81 T_3 * V_82 )
{
struct V_81 V_83 ;
struct V_84 V_85 ;
if ( ! F_42 ( V_86 ) )
return - V_60 ;
if ( F_26 ( & V_83 , V_82 , sizeof( struct V_81 ) ) )
return - V_42 ;
if ( F_26 ( & V_85 , V_83 . V_87 , sizeof( struct V_84 ) ) )
return - V_42 ;
switch ( V_83 . V_88 ) {
case V_89 :
if ( F_43 ( V_7 ) )
return - V_55 ;
V_85 . V_90 [ V_91 - 1 ] = '\0' ;
return F_44 ( V_7 , V_85 . V_90 , V_85 . V_56 , V_85 . V_57 ) ;
case V_92 :
if ( V_85 . V_93 < 0 )
return - V_55 ;
return F_45 ( V_7 , V_85 . V_93 ) ;
default:
return - V_55 ;
}
}
static int F_46 ( struct V_13 * V_7 ,
struct V_94 T_3 * V_95 )
{
struct V_94 V_96 ;
struct V_37 V_38 ;
const void T_3 * V_97 , * V_98 ;
int V_12 ;
if ( F_26 ( & V_96 , V_95 , sizeof( V_96 ) ) )
return - V_42 ;
V_97 = ( const void T_3 * ) ( V_99 ) V_96 . V_97 ;
V_98 = ( const void T_3 * ) ( V_99 ) V_96 . V_98 ;
if ( ! F_34 ( V_62 , V_97 , V_96 . V_31 ) ||
! F_34 ( V_62 , V_98 , V_96 . V_63 ) )
return - V_42 ;
if ( ! V_7 -> V_61 )
return - V_51 ;
V_38 . V_33 = V_96 . V_33 ;
V_38 . V_31 = ( T_4 ) V_96 . V_31 ;
V_38 . V_63 = ( T_4 ) V_96 . V_63 ;
V_38 . V_45 = 0 ;
if ( V_97 ) {
V_38 . V_40 = F_35 ( V_97 , V_38 . V_31 ) ;
if ( F_8 ( V_38 . V_40 ) )
return F_9 ( V_38 . V_40 ) ;
} else {
V_38 . V_40 = NULL ;
}
if ( V_98 ) {
V_38 . V_41 = F_35 ( V_98 , V_38 . V_63 ) ;
if ( F_8 ( V_38 . V_41 ) ) {
F_15 ( V_38 . V_40 ) ;
return F_9 ( V_38 . V_41 ) ;
}
} else {
V_38 . V_41 = NULL ;
}
V_12 = F_28 ( V_7 , ( T_1 ) V_96 . V_56 , & V_38 ) ;
F_15 ( V_38 . V_40 ) ;
F_15 ( V_38 . V_41 ) ;
return V_12 ;
}
static int F_47 ( struct V_1 * V_1 , T_7 V_100 , T_8 V_82 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_95 = ( void T_3 * ) V_82 ;
int V_12 = 0 ;
T_8 V_8 ;
struct V_101 V_102 ;
F_5 ( L_5 ) ;
V_8 = ( V_100 & V_103 ) >> V_104 ;
if ( V_100 & V_105 ) {
if ( ! F_34 ( V_62 , V_95 , V_8 ) )
return - V_42 ;
}
if ( V_100 & V_106 ) {
if ( ! F_34 ( V_69 , V_95 , V_8 ) )
return - V_42 ;
}
switch ( V_100 ) {
case V_107 :
if ( F_24 ( V_95 , & ( V_7 -> V_108 ) , sizeof( int ) ) )
return - V_42 ;
break;
case V_109 :
{
T_6 V_110 ;
struct V_111 * V_112 ;
struct V_113 T_3 * V_114 = V_95 ;
if ( F_48 ( V_110 , & ( V_114 -> V_115 ) ) )
return - V_42 ;
if ( V_110 >= V_7 -> V_108 )
return - V_55 ;
V_112 = & ( V_7 -> V_116 [ V_110 ] ) ;
if ( F_38 ( V_112 -> V_2 , & ( V_114 -> V_2 ) )
|| F_38 ( V_112 -> V_117 , & ( V_114 -> V_117 ) )
|| F_38 ( V_112 -> V_118 , & ( V_114 -> V_118 ) ) )
return - V_42 ;
break;
}
case V_119 :
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . type = V_7 -> type ;
V_102 . V_22 = V_7 -> V_22 ;
V_102 . V_8 = V_7 -> V_8 ;
V_102 . V_117 = V_7 -> V_117 ;
V_102 . V_64 = V_7 -> V_64 ;
V_102 . V_66 = V_7 -> V_66 ;
V_102 . V_120 = 0 ;
if ( F_24 ( V_95 , & V_102 , sizeof( struct V_101 ) ) )
return - V_42 ;
break;
case V_121 :
case V_122 :
{
struct V_46 * V_123 ;
if( ! ( V_1 -> V_14 & V_15 ) )
return - V_60 ;
V_123 = F_10 ( sizeof( struct V_46 ) , V_24 ) ;
if ( ! V_123 )
V_12 = - V_25 ;
else {
V_48 V_124 ;
F_49 ( V_125 , V_126 ) ;
F_50 ( & V_124 ) ;
if ( V_100 == V_122 ) {
struct V_127 V_128 ;
if ( F_26 ( & V_128 , V_95 ,
sizeof( struct V_127 ) ) ) {
F_15 ( V_123 ) ;
return - V_42 ;
}
V_123 -> V_129 = V_128 . V_56 ;
V_123 -> V_31 = V_128 . V_57 ;
} else {
struct V_130 V_131 ;
if ( F_26 ( & V_131 , V_95 ,
sizeof( struct V_130 ) ) ) {
F_15 ( V_123 ) ;
return - V_42 ;
}
V_123 -> V_129 = V_131 . V_56 ;
V_123 -> V_31 = V_131 . V_57 ;
}
V_123 -> V_7 = V_7 ;
V_123 -> V_132 = F_30 ;
V_123 -> V_49 = ( unsigned long ) & V_124 ;
V_12 = F_51 ( V_7 , V_123 ) ;
if ( ! V_12 ) {
F_52 ( V_133 ) ;
F_53 ( & V_124 , & V_125 ) ;
if ( V_123 -> V_134 != V_135 &&
V_123 -> V_134 != V_136 )
F_54 () ;
F_55 ( & V_124 , & V_125 ) ;
F_52 ( V_137 ) ;
V_12 = ( V_123 -> V_134 == V_136 ) ? - V_138 : 0 ;
}
F_15 ( V_123 ) ;
}
break;
}
case V_139 :
{
struct V_140 V_26 ;
struct V_140 T_3 * V_141 = V_95 ;
if ( F_26 ( & V_26 , V_95 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
V_26 . V_58 , & V_141 -> V_57 ) ;
break;
}
case V_142 :
{
struct V_140 V_26 ;
struct V_140 T_3 * V_141 = V_95 ;
if ( F_26 ( & V_26 , V_95 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
V_26 . V_58 , & V_141 -> V_56 ) ;
break;
}
case V_143 :
{
struct V_144 V_26 ;
struct V_144 T_3 * V_141 = V_95 ;
if ( F_26 ( & V_26 , V_95 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
( void T_3 * ) ( V_99 ) V_26 . V_145 ,
& V_141 -> V_57 ) ;
break;
}
case V_146 :
{
struct V_144 V_26 ;
struct V_144 T_3 * V_141 = V_95 ;
if ( F_26 ( & V_26 , V_95 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
( void T_3 * ) ( V_99 ) V_26 . V_145 ,
& V_141 -> V_57 ) ;
break;
}
case V_147 :
{
V_12 = F_46 ( V_7 ,
(struct V_94 T_3 * ) V_82 ) ;
break;
}
case V_148 :
{
struct V_130 V_149 ;
if ( F_26 ( & V_149 , V_95 , sizeof( V_149 ) ) )
return - V_42 ;
V_12 = F_56 ( V_7 , V_149 . V_56 , V_149 . V_57 ) ;
break;
}
case V_150 :
{
struct V_130 V_149 ;
if ( F_26 ( & V_149 , V_95 , sizeof( V_149 ) ) )
return - V_42 ;
V_12 = F_57 ( V_7 , V_149 . V_56 , V_149 . V_57 ) ;
break;
}
case V_151 :
{
struct V_130 V_149 ;
if ( F_26 ( & V_149 , V_95 , sizeof( V_149 ) ) )
return - V_42 ;
V_12 = F_58 ( V_7 , V_149 . V_56 , V_149 . V_57 ) ;
break;
}
case V_152 :
{
struct V_153 V_154 ;
if ( ! V_7 -> V_155 )
return - V_51 ;
if ( V_7 -> V_155 -> V_75 > F_59 ( V_154 . V_77 ) )
return - V_55 ;
V_154 . V_156 = V_157 ;
memcpy ( & V_154 . V_77 , V_7 -> V_155 -> V_77 , sizeof( V_154 . V_77 ) ) ;
memcpy ( & V_154 . V_79 , V_7 -> V_155 -> V_79 ,
sizeof( V_154 . V_79 ) ) ;
V_154 . V_75 = V_7 -> V_155 -> V_75 ;
if ( F_24 ( V_95 , & V_154 , sizeof( struct V_153 ) ) )
return - V_42 ;
break;
}
case V_158 :
{
T_1 V_159 ;
if ( F_26 ( & V_159 , V_95 , sizeof( T_1 ) ) )
return - V_42 ;
return F_60 ( V_7 , V_159 ) ;
break;
}
case V_160 :
{
T_1 V_159 ;
if ( F_26 ( & V_159 , V_95 , sizeof( T_1 ) ) )
return - V_42 ;
return F_61 ( V_7 , V_159 ) ;
break;
}
case V_161 :
{
int V_33 ;
if ( F_26 ( & V_33 , V_95 , sizeof( int ) ) )
return - V_42 ;
V_5 -> V_33 = V_54 ;
V_12 = F_32 ( V_5 , V_33 ) ;
V_1 -> V_162 = 0 ;
break;
}
case V_163 :
case V_164 :
{
struct V_165 * V_26 = F_37 ( 4096 , V_24 ) ;
T_4 V_29 ;
if ( ! V_26 )
return - V_25 ;
switch ( V_5 -> V_33 ) {
case V_34 :
V_12 = F_62 ( V_7 , 4096 , & V_29 , V_26 ) ;
break;
case V_35 :
V_12 = F_63 ( V_7 , 4096 , & V_29 , V_26 ) ;
break;
default:
V_12 = - V_55 ;
break;
}
if ( ! V_12 ) {
if ( V_100 == V_163 ) {
int V_166 = V_29 / sizeof( struct V_165 ) ;
V_12 = F_24 ( V_95 , & V_166 , sizeof( int ) ) ;
} else
V_12 = F_24 ( V_95 , V_26 , V_29 ) ;
if ( V_12 )
V_12 = - V_42 ;
}
F_15 ( V_26 ) ;
break;
}
case V_167 :
{
struct V_165 V_168 ;
if ( V_5 -> V_33 != V_35 )
return - V_55 ;
if ( F_26 ( & V_168 , V_95 , sizeof( V_168 ) ) )
return - V_42 ;
V_12 = F_64 ( V_7 , V_168 . V_56 , V_168 . V_57 ) ;
break;
}
case V_169 :
{
struct V_72 * V_170 ;
if ( ! V_7 -> V_155 )
return - V_51 ;
V_170 = F_37 ( sizeof( * V_170 ) , V_24 ) ;
if ( ! V_170 )
return - V_25 ;
F_39 ( V_7 -> V_155 , V_170 ) ;
if ( F_24 ( V_95 , V_170 , sizeof( * V_170 ) ) )
V_12 = - V_42 ;
F_15 ( V_170 ) ;
break;
}
case V_171 :
{
if ( F_24 ( V_95 , & V_7 -> V_172 ,
sizeof( struct V_173 ) ) )
return - V_42 ;
break;
}
case V_174 :
{
V_5 -> V_33 = 0 ;
switch( V_82 ) {
case V_34 :
case V_35 :
V_12 = F_32 ( V_5 , V_82 ) ;
break;
case V_36 :
if ( ! F_65 ( V_7 ) )
return - V_51 ;
V_5 -> V_33 = V_82 ;
case V_54 :
break;
default:
V_12 = - V_55 ;
}
V_1 -> V_162 = 0 ;
break;
}
case V_175 :
{
V_12 = F_41 ( V_7 ,
(struct V_81 T_3 * ) V_82 ) ;
break;
}
case V_176 :
{
V_12 = 0 ;
break;
}
default:
V_12 = - V_177 ;
}
return V_12 ;
}
static long F_66 ( struct V_1 * V_1 , T_7 V_100 , T_8 V_82 )
{
int V_12 ;
F_6 ( & V_17 ) ;
V_12 = F_47 ( V_1 , V_100 , V_82 ) ;
F_11 ( & V_17 ) ;
return V_12 ;
}
static long F_67 ( struct V_1 * V_1 , unsigned int V_100 ,
unsigned long V_82 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_95 = F_68 ( V_82 ) ;
int V_12 = 0 ;
F_6 ( & V_17 ) ;
switch ( V_100 ) {
case V_178 :
{
struct V_179 V_26 ;
struct V_179 T_3 * V_141 = V_95 ;
if ( F_26 ( & V_26 , V_95 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 ,
V_26 . V_57 , F_68 ( V_26 . V_58 ) ,
& V_141 -> V_57 ) ;
break;
}
case V_180 :
{
struct V_179 V_26 ;
struct V_179 T_3 * V_141 = V_95 ;
if ( F_26 ( & V_26 , V_95 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 ,
V_26 . V_57 , F_68 ( V_26 . V_58 ) ,
& V_141 -> V_56 ) ;
break;
}
default:
V_12 = F_47 ( V_1 , V_100 , ( unsigned long ) V_95 ) ;
}
F_11 ( & V_17 ) ;
return V_12 ;
}
static unsigned long F_69 ( struct V_1 * V_1 ,
unsigned long V_129 ,
unsigned long V_31 ,
unsigned long V_181 ,
unsigned long V_22 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
unsigned long V_2 ;
int V_12 ;
if ( V_129 != 0 )
return ( unsigned long ) - V_55 ;
if ( V_31 > V_7 -> V_8 || V_181 >= ( V_7 -> V_8 >> V_182 ) )
return ( unsigned long ) - V_55 ;
V_2 = V_181 << V_182 ;
if ( V_2 > V_7 -> V_8 - V_31 )
return ( unsigned long ) - V_55 ;
V_12 = F_70 ( V_7 , V_31 , V_2 , V_22 ) ;
return V_12 == - V_51 ? - V_20 : V_12 ;
}
static unsigned F_71 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
return F_72 ( V_5 -> V_7 ) ;
}
static int F_73 ( struct V_1 * V_1 , struct V_183 * V_184 )
{
#ifdef F_74
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
struct V_185 * V_186 = V_7 -> V_49 ;
if ( 0 ) {
#ifdef F_75
if ( V_1 -> V_187 & V_188 || V_186 -> V_189 >= F_76 ( V_190 ) )
V_184 -> V_191 = F_75 ( V_184 -> V_191 ) ;
#endif
return F_77 ( V_184 , V_186 -> V_189 , V_186 -> V_8 ) ;
}
return - V_20 ;
#else
return V_184 -> V_192 & V_193 ? 0 : - V_16 ;
#endif
}
int T_9 F_78 ( void )
{
int V_12 ;
V_12 = F_79 ( V_194 , 0 , 1 << V_195 ,
L_6 , & V_196 ) ;
if ( V_12 < 0 ) {
F_80 ( L_7 ,
V_194 ) ;
return V_12 ;
}
return V_12 ;
}
void T_10 F_81 ( void )
{
F_82 ( V_194 , 0 , 1 << V_195 , L_6 ) ;
}
