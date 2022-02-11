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
static int F_39 ( struct V_13 * V_7 ,
struct V_70 * V_71 )
{
struct V_72 V_73 ;
int V_74 , V_75 = 0 , V_12 ;
if ( ! V_7 || ! V_71 )
return - V_55 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_71 -> V_76 = 0 ;
for ( V_74 = 0 ; V_74 < V_77 ; ) {
T_7 V_78 ;
V_12 = F_40 ( V_7 , V_75 , & V_73 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_79 )
return V_12 ;
break;
}
V_78 = V_73 . V_2 ;
for (; V_74 < V_77 &&
V_78 < V_73 . V_2 + V_73 . V_57 ; V_74 ++ ) {
V_71 -> V_78 [ V_74 ] = V_78 ++ ;
V_71 -> V_76 ++ ;
}
}
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_12 = F_41 ( V_7 , V_74 , & V_73 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_79 )
return V_12 ;
break;
}
V_71 -> V_81 [ V_74 ] . V_2 = V_73 . V_2 ;
V_71 -> V_81 [ V_74 ] . V_57 = V_73 . V_57 ;
V_71 -> V_82 += V_71 -> V_81 [ V_74 ] . V_57 ;
}
return 0 ;
}
static int F_42 ( struct V_13 * V_7 , struct V_83 * V_71 )
{
struct V_72 V_73 ;
int V_74 , V_75 = 0 , V_12 ;
if ( ! V_7 || ! V_71 )
return - V_55 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_71 -> V_76 = 0 ;
for ( V_74 = 0 ; V_74 < F_43 ( V_71 -> V_78 ) ; ) {
T_7 V_78 ;
V_12 = F_40 ( V_7 , V_75 , & V_73 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_79 )
return V_12 ;
break;
}
if ( V_73 . V_57 + V_74 > F_43 ( V_71 -> V_78 ) )
return - V_55 ;
V_78 = V_73 . V_2 ;
for (; V_78 < V_73 . V_2 + V_73 . V_57 ; V_74 ++ ) {
V_71 -> V_78 [ V_74 ] = V_78 ++ ;
V_71 -> V_76 ++ ;
}
}
for ( V_74 = 0 ; V_74 < 8 ; V_74 ++ ) {
V_12 = F_41 ( V_7 , V_74 , & V_73 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_79 )
return V_12 ;
break;
}
V_71 -> V_81 [ V_74 ] [ 0 ] = V_73 . V_2 ;
V_71 -> V_81 [ V_74 ] [ 1 ] = V_73 . V_57 ;
}
V_71 -> V_84 = V_85 ;
return 0 ;
}
static int F_44 ( struct V_13 * V_7 ,
struct V_86 * V_87 )
{
struct V_88 V_89 ;
if ( ! F_45 ( V_90 ) )
return - V_60 ;
if ( F_26 ( & V_89 , V_87 -> V_91 , sizeof( V_89 ) ) )
return - V_42 ;
switch ( V_87 -> V_92 ) {
case V_93 :
if ( F_46 ( V_7 ) )
return - V_55 ;
V_89 . V_94 [ V_95 - 1 ] = '\0' ;
return F_47 ( V_7 , V_89 . V_94 , V_89 . V_56 , V_89 . V_57 ) ;
case V_96 :
if ( V_89 . V_97 < 0 )
return - V_55 ;
return F_48 ( V_7 , V_89 . V_97 ) ;
default:
return - V_55 ;
}
}
static int F_49 ( struct V_13 * V_7 ,
struct V_98 T_3 * V_99 )
{
struct V_98 V_100 ;
struct V_37 V_38 ;
const void T_3 * V_101 , * V_102 ;
int V_12 ;
if ( F_26 ( & V_100 , V_99 , sizeof( V_100 ) ) )
return - V_42 ;
V_101 = ( const void T_3 * ) ( V_103 ) V_100 . V_101 ;
V_102 = ( const void T_3 * ) ( V_103 ) V_100 . V_102 ;
if ( ! F_34 ( V_62 , V_101 , V_100 . V_31 ) ||
! F_34 ( V_62 , V_102 , V_100 . V_63 ) )
return - V_42 ;
if ( ! V_7 -> V_61 )
return - V_51 ;
V_38 . V_33 = V_100 . V_33 ;
V_38 . V_31 = ( T_4 ) V_100 . V_31 ;
V_38 . V_63 = ( T_4 ) V_100 . V_63 ;
V_38 . V_45 = 0 ;
if ( V_101 ) {
V_38 . V_40 = F_35 ( V_101 , V_38 . V_31 ) ;
if ( F_8 ( V_38 . V_40 ) )
return F_9 ( V_38 . V_40 ) ;
} else {
V_38 . V_40 = NULL ;
}
if ( V_102 ) {
V_38 . V_41 = F_35 ( V_102 , V_38 . V_63 ) ;
if ( F_8 ( V_38 . V_41 ) ) {
F_15 ( V_38 . V_40 ) ;
return F_9 ( V_38 . V_41 ) ;
}
} else {
V_38 . V_41 = NULL ;
}
V_12 = F_28 ( V_7 , ( T_1 ) V_100 . V_56 , & V_38 ) ;
F_15 ( V_38 . V_40 ) ;
F_15 ( V_38 . V_41 ) ;
return V_12 ;
}
static int F_50 ( struct V_1 * V_1 , T_8 V_104 , T_9 V_87 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_99 = ( void T_3 * ) V_87 ;
int V_12 = 0 ;
T_9 V_8 ;
struct V_105 V_106 ;
F_5 ( L_5 ) ;
V_8 = ( V_104 & V_107 ) >> V_108 ;
if ( V_104 & V_109 ) {
if ( ! F_34 ( V_62 , V_99 , V_8 ) )
return - V_42 ;
}
if ( V_104 & V_110 ) {
if ( ! F_34 ( V_69 , V_99 , V_8 ) )
return - V_42 ;
}
switch ( V_104 ) {
case V_111 :
if ( F_24 ( V_99 , & ( V_7 -> V_112 ) , sizeof( int ) ) )
return - V_42 ;
break;
case V_113 :
{
T_6 V_114 ;
struct V_115 * V_116 ;
struct V_117 T_3 * V_118 = V_99 ;
if ( F_51 ( V_114 , & ( V_118 -> V_119 ) ) )
return - V_42 ;
if ( V_114 >= V_7 -> V_112 )
return - V_55 ;
V_116 = & ( V_7 -> V_120 [ V_114 ] ) ;
if ( F_38 ( V_116 -> V_2 , & ( V_118 -> V_2 ) )
|| F_38 ( V_116 -> V_121 , & ( V_118 -> V_121 ) )
|| F_38 ( V_116 -> V_122 , & ( V_118 -> V_122 ) ) )
return - V_42 ;
break;
}
case V_123 :
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . type = V_7 -> type ;
V_106 . V_22 = V_7 -> V_22 ;
V_106 . V_8 = V_7 -> V_8 ;
V_106 . V_121 = V_7 -> V_121 ;
V_106 . V_64 = V_7 -> V_64 ;
V_106 . V_66 = V_7 -> V_66 ;
V_106 . V_124 = 0 ;
if ( F_24 ( V_99 , & V_106 , sizeof( struct V_105 ) ) )
return - V_42 ;
break;
case V_125 :
case V_126 :
{
struct V_46 * V_127 ;
if( ! ( V_1 -> V_14 & V_15 ) )
return - V_60 ;
V_127 = F_10 ( sizeof( struct V_46 ) , V_24 ) ;
if ( ! V_127 )
V_12 = - V_25 ;
else {
V_48 V_128 ;
F_52 ( V_129 , V_130 ) ;
F_53 ( & V_128 ) ;
if ( V_104 == V_126 ) {
struct V_131 V_132 ;
if ( F_26 ( & V_132 , V_99 ,
sizeof( struct V_131 ) ) ) {
F_15 ( V_127 ) ;
return - V_42 ;
}
V_127 -> V_133 = V_132 . V_56 ;
V_127 -> V_31 = V_132 . V_57 ;
} else {
struct V_134 V_135 ;
if ( F_26 ( & V_135 , V_99 ,
sizeof( struct V_134 ) ) ) {
F_15 ( V_127 ) ;
return - V_42 ;
}
V_127 -> V_133 = V_135 . V_56 ;
V_127 -> V_31 = V_135 . V_57 ;
}
V_127 -> V_7 = V_7 ;
V_127 -> V_136 = F_30 ;
V_127 -> V_49 = ( unsigned long ) & V_128 ;
V_12 = F_54 ( V_7 , V_127 ) ;
if ( ! V_12 ) {
F_55 ( V_137 ) ;
F_56 ( & V_128 , & V_129 ) ;
if ( V_127 -> V_138 != V_139 &&
V_127 -> V_138 != V_140 )
F_57 () ;
F_58 ( & V_128 , & V_129 ) ;
F_55 ( V_141 ) ;
V_12 = ( V_127 -> V_138 == V_140 ) ? - V_142 : 0 ;
}
F_15 ( V_127 ) ;
}
break;
}
case V_143 :
{
struct V_144 V_26 ;
struct V_144 T_3 * V_145 = V_99 ;
if ( F_26 ( & V_26 , V_99 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
V_26 . V_58 , & V_145 -> V_57 ) ;
break;
}
case V_146 :
{
struct V_144 V_26 ;
struct V_144 T_3 * V_145 = V_99 ;
if ( F_26 ( & V_26 , V_99 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
V_26 . V_58 , & V_145 -> V_56 ) ;
break;
}
case V_147 :
{
struct V_148 V_26 ;
struct V_148 T_3 * V_145 = V_99 ;
if ( F_26 ( & V_26 , V_99 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
( void T_3 * ) ( V_103 ) V_26 . V_149 ,
& V_145 -> V_57 ) ;
break;
}
case V_150 :
{
struct V_148 V_26 ;
struct V_148 T_3 * V_145 = V_99 ;
if ( F_26 ( & V_26 , V_99 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 , V_26 . V_57 ,
( void T_3 * ) ( V_103 ) V_26 . V_149 ,
& V_145 -> V_57 ) ;
break;
}
case V_151 :
{
V_12 = F_49 ( V_7 ,
(struct V_98 T_3 * ) V_87 ) ;
break;
}
case V_152 :
{
struct V_134 V_153 ;
if ( F_26 ( & V_153 , V_99 , sizeof( V_153 ) ) )
return - V_42 ;
V_12 = F_59 ( V_7 , V_153 . V_56 , V_153 . V_57 ) ;
break;
}
case V_154 :
{
struct V_134 V_153 ;
if ( F_26 ( & V_153 , V_99 , sizeof( V_153 ) ) )
return - V_42 ;
V_12 = F_60 ( V_7 , V_153 . V_56 , V_153 . V_57 ) ;
break;
}
case V_155 :
{
struct V_134 V_153 ;
if ( F_26 ( & V_153 , V_99 , sizeof( V_153 ) ) )
return - V_42 ;
V_12 = F_61 ( V_7 , V_153 . V_56 , V_153 . V_57 ) ;
break;
}
case V_156 :
{
struct V_83 V_157 ;
if ( ! V_7 -> V_158 )
return - V_51 ;
V_12 = F_42 ( V_7 , & V_157 ) ;
if ( V_12 )
return V_12 ;
if ( F_24 ( V_99 , & V_157 , sizeof( struct V_83 ) ) )
return - V_42 ;
break;
}
case V_159 :
{
T_1 V_160 ;
if ( F_26 ( & V_160 , V_99 , sizeof( T_1 ) ) )
return - V_42 ;
return F_62 ( V_7 , V_160 ) ;
break;
}
case V_161 :
{
T_1 V_160 ;
if ( F_26 ( & V_160 , V_99 , sizeof( T_1 ) ) )
return - V_42 ;
return F_63 ( V_7 , V_160 ) ;
break;
}
case V_162 :
{
int V_33 ;
if ( F_26 ( & V_33 , V_99 , sizeof( int ) ) )
return - V_42 ;
V_5 -> V_33 = V_54 ;
V_12 = F_32 ( V_5 , V_33 ) ;
V_1 -> V_163 = 0 ;
break;
}
case V_164 :
case V_165 :
{
struct V_166 * V_26 = F_37 ( 4096 , V_24 ) ;
T_4 V_29 ;
if ( ! V_26 )
return - V_25 ;
switch ( V_5 -> V_33 ) {
case V_34 :
V_12 = F_64 ( V_7 , 4096 , & V_29 , V_26 ) ;
break;
case V_35 :
V_12 = F_65 ( V_7 , 4096 , & V_29 , V_26 ) ;
break;
default:
V_12 = - V_55 ;
break;
}
if ( ! V_12 ) {
if ( V_104 == V_164 ) {
int V_167 = V_29 / sizeof( struct V_166 ) ;
V_12 = F_24 ( V_99 , & V_167 , sizeof( int ) ) ;
} else
V_12 = F_24 ( V_99 , V_26 , V_29 ) ;
if ( V_12 )
V_12 = - V_42 ;
}
F_15 ( V_26 ) ;
break;
}
case V_168 :
{
struct V_166 V_169 ;
if ( V_5 -> V_33 != V_35 )
return - V_55 ;
if ( F_26 ( & V_169 , V_99 , sizeof( V_169 ) ) )
return - V_42 ;
V_12 = F_66 ( V_7 , V_169 . V_56 , V_169 . V_57 ) ;
break;
}
case V_170 :
{
struct V_70 * V_171 ;
if ( ! V_7 -> V_158 )
return - V_51 ;
V_171 = F_37 ( sizeof( * V_171 ) , V_24 ) ;
if ( ! V_171 )
return - V_25 ;
F_39 ( V_7 , V_171 ) ;
if ( F_24 ( V_99 , V_171 , sizeof( * V_171 ) ) )
V_12 = - V_42 ;
F_15 ( V_171 ) ;
break;
}
case V_172 :
{
if ( F_24 ( V_99 , & V_7 -> V_173 ,
sizeof( struct V_174 ) ) )
return - V_42 ;
break;
}
case V_175 :
{
V_5 -> V_33 = 0 ;
switch( V_87 ) {
case V_34 :
case V_35 :
V_12 = F_32 ( V_5 , V_87 ) ;
break;
case V_36 :
if ( ! F_67 ( V_7 ) )
return - V_51 ;
V_5 -> V_33 = V_87 ;
case V_54 :
break;
default:
V_12 = - V_55 ;
}
V_1 -> V_163 = 0 ;
break;
}
case V_176 :
{
struct V_86 T_3 * V_177 = V_99 ;
struct V_86 V_178 ;
if ( F_26 ( & V_178 , V_177 , sizeof( V_178 ) ) )
V_12 = - V_42 ;
else
V_12 = F_44 ( V_7 , & V_178 ) ;
break;
}
case V_179 :
{
V_12 = 0 ;
break;
}
default:
V_12 = - V_180 ;
}
return V_12 ;
}
static long F_68 ( struct V_1 * V_1 , T_8 V_104 , T_9 V_87 )
{
int V_12 ;
F_6 ( & V_17 ) ;
V_12 = F_50 ( V_1 , V_104 , V_87 ) ;
F_11 ( & V_17 ) ;
return V_12 ;
}
static long F_69 ( struct V_1 * V_1 , unsigned int V_104 ,
unsigned long V_87 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
void T_3 * V_99 = F_70 ( V_87 ) ;
int V_12 = 0 ;
F_6 ( & V_17 ) ;
switch ( V_104 ) {
case V_181 :
{
struct V_182 V_26 ;
struct V_182 T_3 * V_145 = V_99 ;
if ( F_26 ( & V_26 , V_99 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_33 ( V_1 , V_7 , V_26 . V_56 ,
V_26 . V_57 , F_70 ( V_26 . V_58 ) ,
& V_145 -> V_57 ) ;
break;
}
case V_183 :
{
struct V_182 V_26 ;
struct V_182 T_3 * V_145 = V_99 ;
if ( F_26 ( & V_26 , V_99 , sizeof( V_26 ) ) )
V_12 = - V_42 ;
else
V_12 = F_36 ( V_1 , V_7 , V_26 . V_56 ,
V_26 . V_57 , F_70 ( V_26 . V_58 ) ,
& V_145 -> V_56 ) ;
break;
}
case V_176 :
{
struct V_184 T_3 * V_185 = V_99 ;
struct V_184 V_186 ;
struct V_86 V_178 ;
if ( F_26 ( & V_186 , V_185 , sizeof( V_186 ) ) ) {
V_12 = - V_42 ;
break;
}
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_92 = V_186 . V_92 ;
V_178 . V_22 = V_186 . V_22 ;
V_178 . V_187 = V_186 . V_187 ;
V_178 . V_91 = F_70 ( V_186 . V_91 ) ;
V_12 = F_44 ( V_7 , & V_178 ) ;
break;
}
default:
V_12 = F_50 ( V_1 , V_104 , ( unsigned long ) V_99 ) ;
}
F_11 ( & V_17 ) ;
return V_12 ;
}
static unsigned long F_71 ( struct V_1 * V_1 ,
unsigned long V_133 ,
unsigned long V_31 ,
unsigned long V_188 ,
unsigned long V_22 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
unsigned long V_2 ;
int V_12 ;
if ( V_133 != 0 )
return ( unsigned long ) - V_55 ;
if ( V_31 > V_7 -> V_8 || V_188 >= ( V_7 -> V_8 >> V_189 ) )
return ( unsigned long ) - V_55 ;
V_2 = V_188 << V_189 ;
if ( V_2 > V_7 -> V_8 - V_31 )
return ( unsigned long ) - V_55 ;
V_12 = F_72 ( V_7 , V_31 , V_2 , V_22 ) ;
return V_12 == - V_51 ? - V_20 : V_12 ;
}
static unsigned F_73 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
return F_74 ( V_5 -> V_7 ) ;
}
static int F_75 ( struct V_1 * V_1 , struct V_190 * V_191 )
{
#ifdef F_76
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_13 * V_7 = V_5 -> V_7 ;
struct V_192 * V_193 = V_7 -> V_49 ;
if ( 0 ) {
#ifdef F_77
if ( V_1 -> V_194 & V_195 || V_193 -> V_196 >= F_78 ( V_197 ) )
V_191 -> V_198 = F_77 ( V_191 -> V_198 ) ;
#endif
return F_79 ( V_191 , V_193 -> V_196 , V_193 -> V_8 ) ;
}
return - V_20 ;
#else
return V_191 -> V_199 & V_200 ? 0 : - V_16 ;
#endif
}
int T_10 F_80 ( void )
{
int V_12 ;
V_12 = F_81 ( V_201 , 0 , 1 << V_202 ,
L_6 , & V_203 ) ;
if ( V_12 < 0 ) {
F_82 ( L_7 ,
V_201 ) ;
return V_12 ;
}
return V_12 ;
}
void T_11 F_83 ( void )
{
F_84 ( V_201 , 0 , 1 << V_202 , L_6 ) ;
}
