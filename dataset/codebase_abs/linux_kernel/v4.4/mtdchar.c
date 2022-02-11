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
struct V_81 * V_82 )
{
struct V_83 V_84 ;
if ( ! F_42 ( V_85 ) )
return - V_60 ;
if ( F_26 ( & V_84 , V_82 -> V_86 , sizeof( V_84 ) ) )
return - V_42 ;
switch ( V_82 -> V_87 ) {
case V_88 :
if ( F_43 ( V_7 ) )
return - V_55 ;
V_84 . V_89 [ V_90 - 1 ] = '\0' ;
return F_44 ( V_7 , V_84 . V_89 , V_84 . V_56 , V_84 . V_57 ) ;
case V_91 :
if ( V_84 . V_92 < 0 )
return - V_55 ;
return F_45 ( V_7 , V_84 . V_92 ) ;
default:
return - V_55 ;
}
}
static int F_46 ( struct V_13 * V_7 ,
struct V_93 T_3 * V_94 )
{
struct V_93 V_95 ;
struct V_37 V_38 ;
const void T_3 * V_96 , * V_97 ;
int V_12 ;
if ( F_26 ( & V_95 , V_94 , sizeof( V_95 ) ) )
return - V_42 ;
V_96 = ( const void T_3 * ) ( V_98 ) V_95 . V_96 ;
V_97 = ( const void T_3 * ) ( V_98 ) V_95 . V_97 ;
if ( ! F_34 ( V_62 , V_96 , V_95 . V_31 ) ||
! F_34 ( V_62 , V_97 , V_95 . V_63 ) )
return - V_42 ;
if ( ! V_7 -> V_61 )
return - V_51 ;
V_38 . V_33 = V_95 . V_33 ;
V_38 . V_31 = ( T_4 ) V_95 . V_31 ;
V_38 . V_63 = ( T_4 ) V_95 . V_63 ;
V_38 . V_45 = 0 ;
if ( V_96 ) {
V_38 . V_40 = F_35 ( V_96 , V_38 . V_31 ) ;
if ( F_8 ( V_38 . V_40 ) )
return F_9 ( V_38 . V_40 ) ;
} else {
V_38 . V_40 = NULL ;
}
if ( V_97 ) {
V_38 . V_41 = F_35 ( V_97 , V_38 . V_63 ) ;
if ( F_8 ( V_38 . V_41 ) ) {
F_15 ( V_38 . V_40 ) ;
return F_9 ( V_38 . V_41 ) ;
}
} else {
V_38 . V_41 = NULL ;
}
V_12 = F_28 ( V_7 , ( T_1 ) V_95 . V_56 , & V_38 ) ;
F_15 ( V_38 . V_40 ) ;
F_15 ( V_38 . V_41 ) ;
return V_12 ;
}
static int F_47 ( struct V_1 * V_1 , T_7 V_99 , T_8 V_82 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_94 = ( void T_3 * ) V_82 ;
int V_12 = 0 ;
T_8 V_8 ;
struct V_100 V_101 ;
F_5 ( L_5 ) ;
V_8 = ( V_99 & V_102 ) >> V_103 ;
if ( V_99 & V_104 ) {
if ( ! F_34 ( V_62 , V_94 , V_8 ) )
return - V_42 ;
}
if ( V_99 & V_105 ) {
if ( ! F_34 ( V_69 , V_94 , V_8 ) )
return - V_42 ;
}
switch ( V_99 ) {
case V_106 :
if ( F_24 ( V_94 , & ( V_7 -> V_107 ) , sizeof( int ) ) )
return - V_42 ;
break;
case V_108 :
{
T_6 V_109 ;
struct V_110 * V_111 ;
struct V_112 T_3 * V_113 = V_94 ;
if ( F_48 ( V_109 , & ( V_113 -> V_114 ) ) )
return - V_42 ;
if ( V_109 >= V_7 -> V_107 )
return - V_55 ;
V_111 = & ( V_7 -> V_115 [ V_109 ] ) ;
if ( F_38 ( V_111 -> V_2 , & ( V_113 -> V_2 ) )
|| F_38 ( V_111 -> V_116 , & ( V_113 -> V_116 ) )
|| F_38 ( V_111 -> V_117 , & ( V_113 -> V_117 ) ) )
return - V_42 ;
break;
}
case V_118 :
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . type = V_7 -> type ;
V_101 . V_22 = V_7 -> V_22 ;
V_101 . V_8 = V_7 -> V_8 ;
V_101 . V_116 = V_7 -> V_116 ;
V_101 . V_64 = V_7 -> V_64 ;
V_101 . V_66 = V_7 -> V_66 ;
V_101 . V_119 = 0 ;
if ( F_24 ( V_94 , & V_101 , sizeof( struct V_100 ) ) )
return - V_42 ;
break;
case V_120 :
case V_121 :
{
struct V_46 * V_122 ;
if( ! ( V_1 -> V_14 & V_15 ) )
return - V_60 ;
V_122 = F_10 ( sizeof( struct V_46 ) , V_24 ) ;
if ( ! V_122 )
V_12 = - V_25 ;
else {
V_48 V_123 ;
F_49 ( V_124 , V_125 ) ;
F_50 ( & V_123 ) ;
if ( V_99 == V_121 ) {
struct V_126 V_127 ;
if ( F_26 ( & V_127 , V_94 ,
sizeof( struct V_126 ) ) ) {
F_15 ( V_122 ) ;
return - V_42 ;
}
V_122 -> V_128 = V_127 . V_56 ;
V_122 -> V_31 = V_127 . V_57 ;
} else {
struct V_129 V_130 ;
if ( F_26 ( & V_130 , V_94 ,
sizeof( struct V_129 ) ) ) {
F_15 ( V_122 ) ;
return - V_42 ;
}
V_122 -> V_128 = V_130 . V_56 ;
V_122 -> V_31 = V_130 . V_57 ;
}
V_122 -> V_7 = V_7 ;
V_122 -> V_131 = F_30 ;
V_122 -> V_49 = ( unsigned long ) & V_123 ;
V_12 = F_51 ( V_7 , V_122 ) ;
if ( ! V_12 ) {
F_52 ( V_132 ) ;
F_53 ( & V_123 , & V_124 ) ;
if ( V_122 -> V_133 != V_134 &&
V_122 -> V_133 != V_135 )
F_54 () ;
F_55 ( & V_123 , & V_124 ) ;
F_52 ( V_136 ) ;
V_12 = ( V_122 -> V_133 == V_135 ) ? - V_137 : 0 ;
}
F_15 ( V_122 ) ;
}
break;
}
case V_138 :
{
struct V_139 V_26 ;
struct V_139 T_3 * V_140 = V_94 ;
if ( F_26 ( & V_26 , V_94 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
V_26 . V_58 , & V_140 -> V_57 ) ;
break;
}
case V_141 :
{
struct V_139 V_26 ;
struct V_139 T_3 * V_140 = V_94 ;
if ( F_26 ( & V_26 , V_94 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
V_26 . V_58 , & V_140 -> V_56 ) ;
break;
}
case V_142 :
{
struct V_143 V_26 ;
struct V_143 T_3 * V_140 = V_94 ;
if ( F_26 ( & V_26 , V_94 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
( void T_3 * ) ( V_98 ) V_26 . V_144 ,
& V_140 -> V_57 ) ;
break;
}
case V_145 :
{
struct V_143 V_26 ;
struct V_143 T_3 * V_140 = V_94 ;
if ( F_26 ( & V_26 , V_94 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
( void T_3 * ) ( V_98 ) V_26 . V_144 ,
& V_140 -> V_57 ) ;
break;
}
case V_146 :
{
V_12 = F_46 ( V_7 ,
(struct V_93 T_3 * ) V_82 ) ;
break;
}
case V_147 :
{
struct V_129 V_148 ;
if ( F_26 ( & V_148 , V_94 , sizeof( V_148 ) ) )
return - V_42 ;
V_12 = F_56 ( V_7 , V_148 . V_56 , V_148 . V_57 ) ;
break;
}
case V_149 :
{
struct V_129 V_148 ;
if ( F_26 ( & V_148 , V_94 , sizeof( V_148 ) ) )
return - V_42 ;
V_12 = F_57 ( V_7 , V_148 . V_56 , V_148 . V_57 ) ;
break;
}
case V_150 :
{
struct V_129 V_148 ;
if ( F_26 ( & V_148 , V_94 , sizeof( V_148 ) ) )
return - V_42 ;
V_12 = F_58 ( V_7 , V_148 . V_56 , V_148 . V_57 ) ;
break;
}
case V_151 :
{
struct V_152 V_153 ;
if ( ! V_7 -> V_154 )
return - V_51 ;
if ( V_7 -> V_154 -> V_75 > F_59 ( V_153 . V_77 ) )
return - V_55 ;
V_153 . V_155 = V_156 ;
memcpy ( & V_153 . V_77 , V_7 -> V_154 -> V_77 , sizeof( V_153 . V_77 ) ) ;
memcpy ( & V_153 . V_79 , V_7 -> V_154 -> V_79 ,
sizeof( V_153 . V_79 ) ) ;
V_153 . V_75 = V_7 -> V_154 -> V_75 ;
if ( F_24 ( V_94 , & V_153 , sizeof( struct V_152 ) ) )
return - V_42 ;
break;
}
case V_157 :
{
T_1 V_158 ;
if ( F_26 ( & V_158 , V_94 , sizeof( T_1 ) ) )
return - V_42 ;
return F_60 ( V_7 , V_158 ) ;
break;
}
case V_159 :
{
T_1 V_158 ;
if ( F_26 ( & V_158 , V_94 , sizeof( T_1 ) ) )
return - V_42 ;
return F_61 ( V_7 , V_158 ) ;
break;
}
case V_160 :
{
int V_33 ;
if ( F_26 ( & V_33 , V_94 , sizeof( int ) ) )
return - V_42 ;
V_5 -> V_33 = V_54 ;
V_12 = F_32 ( V_5 , V_33 ) ;
V_1 -> V_161 = 0 ;
break;
}
case V_162 :
case V_163 :
{
struct V_164 * V_26 = F_37 ( 4096 , V_24 ) ;
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
if ( V_99 == V_162 ) {
int V_165 = V_29 / sizeof( struct V_164 ) ;
V_12 = F_24 ( V_94 , & V_165 , sizeof( int ) ) ;
} else
V_12 = F_24 ( V_94 , V_26 , V_29 ) ;
if ( V_12 )
V_12 = - V_42 ;
}
F_15 ( V_26 ) ;
break;
}
case V_166 :
{
struct V_164 V_167 ;
if ( V_5 -> V_33 != V_35 )
return - V_55 ;
if ( F_26 ( & V_167 , V_94 , sizeof( V_167 ) ) )
return - V_42 ;
V_12 = F_64 ( V_7 , V_167 . V_56 , V_167 . V_57 ) ;
break;
}
case V_168 :
{
struct V_72 * V_169 ;
if ( ! V_7 -> V_154 )
return - V_51 ;
V_169 = F_37 ( sizeof( * V_169 ) , V_24 ) ;
if ( ! V_169 )
return - V_25 ;
F_39 ( V_7 -> V_154 , V_169 ) ;
if ( F_24 ( V_94 , V_169 , sizeof( * V_169 ) ) )
V_12 = - V_42 ;
F_15 ( V_169 ) ;
break;
}
case V_170 :
{
if ( F_24 ( V_94 , & V_7 -> V_171 ,
sizeof( struct V_172 ) ) )
return - V_42 ;
break;
}
case V_173 :
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
V_1 -> V_161 = 0 ;
break;
}
case V_174 :
{
struct V_81 T_3 * V_175 = V_94 ;
struct V_81 V_176 ;
if ( F_26 ( & V_176 , V_175 , sizeof( V_176 ) ) )
V_12 = - V_42 ;
else
V_12 = F_41 ( V_7 , & V_176 ) ;
break;
}
case V_177 :
{
V_12 = 0 ;
break;
}
default:
V_12 = - V_178 ;
}
return V_12 ;
}
static long F_66 ( struct V_1 * V_1 , T_7 V_99 , T_8 V_82 )
{
int V_12 ;
F_6 ( & V_17 ) ;
V_12 = F_47 ( V_1 , V_99 , V_82 ) ;
F_11 ( & V_17 ) ;
return V_12 ;
}
static long F_67 ( struct V_1 * V_1 , unsigned int V_99 ,
unsigned long V_82 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_94 = F_68 ( V_82 ) ;
int V_12 = 0 ;
F_6 ( & V_17 ) ;
switch ( V_99 ) {
case V_179 :
{
struct V_180 V_26 ;
struct V_180 T_3 * V_140 = V_94 ;
if ( F_26 ( & V_26 , V_94 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 ,
V_26 . V_57 , F_68 ( V_26 . V_58 ) ,
& V_140 -> V_57 ) ;
break;
}
case V_181 :
{
struct V_180 V_26 ;
struct V_180 T_3 * V_140 = V_94 ;
if ( F_26 ( & V_26 , V_94 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 ,
V_26 . V_57 , F_68 ( V_26 . V_58 ) ,
& V_140 -> V_56 ) ;
break;
}
case V_174 :
{
struct V_182 T_3 * V_183 = V_94 ;
struct V_182 V_184 ;
struct V_81 V_176 ;
if ( F_26 ( & V_184 , V_183 , sizeof( V_184 ) ) ) {
V_12 = - V_42 ;
break;
}
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_87 = V_184 . V_87 ;
V_176 . V_22 = V_184 . V_22 ;
V_176 . V_185 = V_184 . V_185 ;
V_176 . V_86 = F_68 ( V_184 . V_86 ) ;
V_12 = F_41 ( V_7 , & V_176 ) ;
break;
}
default:
V_12 = F_47 ( V_1 , V_99 , ( unsigned long ) V_94 ) ;
}
F_11 ( & V_17 ) ;
return V_12 ;
}
static unsigned long F_69 ( struct V_1 * V_1 ,
unsigned long V_128 ,
unsigned long V_31 ,
unsigned long V_186 ,
unsigned long V_22 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
unsigned long V_2 ;
int V_12 ;
if ( V_128 != 0 )
return ( unsigned long ) - V_55 ;
if ( V_31 > V_7 -> V_8 || V_186 >= ( V_7 -> V_8 >> V_187 ) )
return ( unsigned long ) - V_55 ;
V_2 = V_186 << V_187 ;
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
static int F_73 ( struct V_1 * V_1 , struct V_188 * V_189 )
{
#ifdef F_74
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
struct V_190 * V_191 = V_7 -> V_49 ;
if ( 0 ) {
#ifdef F_75
if ( V_1 -> V_192 & V_193 || V_191 -> V_194 >= F_76 ( V_195 ) )
V_189 -> V_196 = F_75 ( V_189 -> V_196 ) ;
#endif
return F_77 ( V_189 , V_191 -> V_194 , V_191 -> V_8 ) ;
}
return - V_20 ;
#else
return V_189 -> V_197 & V_198 ? 0 : - V_16 ;
#endif
}
int T_9 F_78 ( void )
{
int V_12 ;
V_12 = F_79 ( V_199 , 0 , 1 << V_200 ,
L_6 , & V_201 ) ;
if ( V_12 < 0 ) {
F_80 ( L_7 ,
V_199 ) ;
return V_12 ;
}
return V_12 ;
}
void T_10 F_81 ( void )
{
F_82 ( V_199 , 0 , 1 << V_200 , L_6 ) ;
}
