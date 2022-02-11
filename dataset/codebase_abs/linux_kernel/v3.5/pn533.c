static inline T_1 F_1 ( T_1 V_1 )
{
return ~ V_1 + 1 ;
}
static T_1 F_2 ( T_1 * V_2 , int V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
V_4 += V_2 [ V_5 ] ;
return F_1 ( V_4 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_8 = 0 ;
V_7 -> V_9 = F_4 ( V_10 ) ;
V_7 -> V_3 = 0 ;
V_7 -> V_11 = 0xFF ;
V_7 -> V_2 [ 0 ] = 0 ;
}
static void F_5 ( struct V_6 * V_7 , T_1 V_12 )
{
V_7 -> V_8 = 0 ;
V_7 -> V_9 = F_4 ( V_10 ) ;
F_6 ( V_7 ) = V_13 ;
F_7 ( V_7 ) = V_12 ;
V_7 -> V_3 = 2 ;
}
static void F_8 ( struct V_6 * V_7 )
{
V_7 -> V_11 = F_1 ( V_7 -> V_3 ) ;
F_9 ( V_7 ) =
F_2 ( V_7 -> V_2 , V_7 -> V_3 ) ;
F_10 ( V_7 ) = 0 ;
}
static bool F_11 ( struct V_6 * V_7 )
{
T_1 V_14 ;
if ( V_7 -> V_9 != F_4 ( V_10 ) )
return false ;
V_14 = F_1 ( V_7 -> V_3 ) ;
if ( V_14 != V_7 -> V_11 )
return false ;
V_14 = F_2 ( V_7 -> V_2 , V_7 -> V_3 ) ;
if ( V_14 != F_9 ( V_7 ) )
return false ;
return true ;
}
static bool F_12 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 != F_4 ( V_10 ) )
return false ;
if ( V_7 -> V_3 != 0 || V_7 -> V_11 != 0xFF )
return false ;
return true ;
}
static bool F_13 ( struct V_6 * V_7 , T_1 V_12 )
{
return ( F_7 ( V_7 ) == F_14 ( V_12 ) ) ;
}
static void F_15 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_19 ) ;
struct V_6 * V_20 ;
int V_21 ;
V_20 = V_18 -> V_22 ;
if ( V_18 -> V_23 )
V_21 = V_18 -> V_24 ( V_18 , V_18 -> V_25 , NULL ,
V_18 -> V_23 ) ;
else
V_21 = V_18 -> V_24 ( V_18 , V_18 -> V_25 ,
F_17 ( V_20 ) ,
F_18 ( V_20 ) ) ;
if ( V_21 != - V_26 )
F_19 ( & V_18 -> V_27 ) ;
}
static void F_20 ( struct V_28 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_29 ;
struct V_6 * V_20 ;
V_18 -> V_22 = NULL ;
switch ( V_28 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_21 ( & V_18 -> V_34 -> V_18 , L_1
L_2 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_3
L_4 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
}
V_20 = V_18 -> V_36 -> V_37 ;
if ( ! F_11 ( V_20 ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_5 ) ;
V_18 -> V_23 = - V_38 ;
goto V_35;
}
if ( ! F_13 ( V_20 , V_18 -> V_12 ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_6
L_7 ) ;
V_18 -> V_23 = - V_38 ;
goto V_35;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_8 ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_22 = V_20 ;
V_35:
F_23 ( V_18 -> V_39 , & V_18 -> V_19 ) ;
}
static int F_24 ( struct V_17 * V_18 , T_2 V_40 )
{
V_18 -> V_36 -> V_41 = F_20 ;
return F_25 ( V_18 -> V_36 , V_40 ) ;
}
static void F_26 ( struct V_28 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_29 ;
struct V_6 * V_20 ;
int V_21 ;
switch ( V_28 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_21 ( & V_18 -> V_34 -> V_18 , L_1
L_2 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_3
L_4 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
}
V_20 = V_18 -> V_36 -> V_37 ;
if ( ! F_12 ( V_20 ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_9 ) ;
V_18 -> V_23 = - V_38 ;
goto V_35;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_10 ) ;
V_21 = F_24 ( V_18 , V_42 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_11
L_12 , V_21 ) ;
V_18 -> V_23 = V_21 ;
goto V_35;
}
return;
V_35:
V_18 -> V_22 = NULL ;
F_23 ( V_18 -> V_39 , & V_18 -> V_19 ) ;
}
static int F_27 ( struct V_17 * V_18 , T_2 V_40 )
{
V_18 -> V_36 -> V_41 = F_26 ;
return F_25 ( V_18 -> V_36 , V_40 ) ;
}
static int F_28 ( struct V_17 * V_18 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_3 ( V_18 -> V_44 ) ;
V_18 -> V_45 -> V_37 = V_18 -> V_44 ;
V_18 -> V_45 -> V_46 = V_47 ;
V_21 = F_25 ( V_18 -> V_45 , V_40 ) ;
return V_21 ;
}
static int F_29 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 ,
T_3 V_24 ,
void * V_49 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_14 ,
F_7 ( V_44 ) ) ;
V_18 -> V_12 = F_7 ( V_44 ) ;
V_18 -> V_24 = V_24 ;
V_18 -> V_25 = V_49 ;
V_18 -> V_45 -> V_37 = V_44 ;
V_18 -> V_45 -> V_46 =
F_30 ( V_44 ) ;
V_18 -> V_36 -> V_37 = V_20 ;
V_18 -> V_36 -> V_46 = V_48 ;
V_21 = F_25 ( V_18 -> V_45 , V_40 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_27 ( V_18 , V_40 ) ;
if ( V_21 )
goto error;
return 0 ;
error:
F_31 ( V_18 -> V_45 ) ;
return V_21 ;
}
static int F_32 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 ,
T_3 V_24 ,
void * V_49 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( F_33 ( & V_18 -> V_27 ) )
return - V_50 ;
V_21 = F_29 ( V_18 , V_44 , V_20 ,
V_48 , V_24 , V_49 , V_40 ) ;
if ( V_21 )
goto error;
return 0 ;
error:
F_19 ( & V_18 -> V_27 ) ;
return V_21 ;
}
static int F_34 ( struct V_17 * V_18 , void * V_51 ,
T_1 * V_52 , int V_53 )
{
struct V_54 * V_49 = V_51 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_49 -> V_21 = 0 ;
if ( V_53 < 0 )
V_49 -> V_21 = V_53 ;
V_41 ( & V_49 -> V_55 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 )
{
int V_21 ;
struct V_54 V_49 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_36 ( & V_49 . V_55 ) ;
V_21 = F_32 ( V_18 , V_44 , V_20 , V_48 ,
F_34 , & V_49 , V_56 ) ;
if ( V_21 )
return V_21 ;
F_37 ( & V_49 . V_55 ) ;
return V_49 . V_21 ;
}
static void F_38 ( struct V_28 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_29 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
switch ( V_28 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_21 ( & V_18 -> V_34 -> V_18 , L_1
L_2 , V_28 -> V_30 ) ;
break;
default:
F_21 ( & V_18 -> V_34 -> V_18 , L_3
L_4 , V_28 -> V_30 ) ;
}
}
static bool F_39 ( struct V_57 * V_58 ,
int V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
if ( V_59 < sizeof( struct V_57 ) )
return false ;
V_60 = F_40 ( V_58 -> V_62 ) ;
V_61 = F_41 ( V_58 -> V_62 ) ;
if ( ( V_60 == V_63 &&
V_61 != V_64 ) ||
( V_60 != V_63 &&
V_61 == V_64 ) )
return false ;
if ( F_42 ( V_58 -> V_65 ) != 0 )
return false ;
return true ;
}
static int F_43 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_57 * V_70 ;
V_70 = (struct V_57 * ) V_68 ;
if ( ! F_39 ( V_70 , V_69 ) )
return - V_71 ;
switch ( F_44 ( V_70 -> V_65 ) ) {
case V_72 :
V_67 -> V_73 = V_74 ;
break;
case V_75 :
V_67 -> V_73 = V_76 ;
break;
case V_77 :
V_67 -> V_73 = V_78 ;
break;
case V_79 :
V_67 -> V_73 = V_76 |
V_78 ;
break;
}
V_67 -> V_62 = F_45 ( V_70 -> V_62 ) ;
V_67 -> V_65 = V_70 -> V_65 ;
V_67 -> V_80 = V_70 -> V_81 ;
memcpy ( V_67 -> V_82 , V_70 -> V_83 , V_67 -> V_80 ) ;
return 0 ;
}
static bool F_46 ( struct V_84 * V_85 ,
int V_59 )
{
if ( V_59 < sizeof( struct V_84 ) )
return false ;
if ( V_85 -> V_86 != V_87 )
return false ;
return true ;
}
static int F_47 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_84 * V_88 ;
V_88 = (struct V_84 * ) V_68 ;
if ( ! F_46 ( V_88 , V_69 ) )
return - V_71 ;
if ( V_88 -> V_89 [ 0 ] == V_90 &&
V_88 -> V_89 [ 1 ] ==
V_91 )
V_67 -> V_73 = V_78 ;
else
V_67 -> V_73 = V_92 ;
memcpy ( V_67 -> V_93 , & V_88 -> V_86 , 9 ) ;
V_67 -> V_94 = 9 ;
return 0 ;
}
static bool F_48 ( struct V_95 * V_96 ,
int V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
if ( V_59 < sizeof( struct V_95 ) )
return false ;
V_60 = F_40 ( V_96 -> V_62 ) ;
V_61 = F_41 ( V_96 -> V_62 ) ;
if ( ( V_60 == V_63 &&
V_61 != V_64 ) ||
( V_60 != V_63 &&
V_61 == V_64 ) )
return false ;
return true ;
}
static int F_49 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_95 * V_97 ;
V_97 = (struct V_95 * ) V_68 ;
if ( ! F_48 ( V_97 , V_69 ) )
return - V_71 ;
V_67 -> V_73 = V_98 ;
V_67 -> V_62 = F_45 ( V_97 -> V_62 ) ;
V_67 -> V_80 = 4 ;
memcpy ( V_67 -> V_82 , V_97 -> V_99 , V_67 -> V_80 ) ;
return 0 ;
}
static bool F_50 ( struct V_100 * V_101 ,
int V_59 )
{
if ( V_59 < sizeof( struct V_100 ) )
return false ;
if ( V_101 -> V_102 . V_86 != V_103 )
return false ;
if ( F_51 ( V_101 -> V_102 . V_104 . V_105 ) &
V_106 )
return false ;
return true ;
}
static int F_52 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_100 * V_107 ;
V_107 = (struct V_100 * ) V_68 ;
if ( ! F_50 ( V_107 , V_69 ) )
return - V_71 ;
V_67 -> V_73 = V_76 ;
return 0 ;
}
static int F_53 ( struct V_17 * V_18 ,
struct V_108 * V_109 , int V_110 )
{
int V_59 ;
struct V_66 V_67 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_15 , V_43 ,
V_18 -> V_111 ) ;
if ( V_109 -> V_112 != 1 )
return - V_71 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_59 = V_110 - sizeof( struct V_108 ) ;
switch ( V_18 -> V_111 ) {
case V_113 :
V_21 = F_43 ( & V_67 , V_109 -> V_114 ,
V_59 ) ;
break;
case V_115 :
case V_116 :
V_21 = F_47 ( & V_67 , V_109 -> V_114 ,
V_59 ) ;
break;
case V_117 :
V_21 = F_49 ( & V_67 , V_109 -> V_114 ,
V_59 ) ;
break;
case V_118 :
V_21 = F_52 ( & V_67 , V_109 -> V_114 ,
V_59 ) ;
break;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_16
L_17 ) ;
return - V_71 ;
}
if ( V_21 )
return V_21 ;
if ( ! ( V_67 . V_73 & V_18 -> V_119 ) ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_18
L_19 ) ;
return - V_120 ;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_20
L_21 , V_67 . V_73 ) ;
V_18 -> V_121 = V_67 . V_73 ;
F_54 ( V_18 -> V_122 , & V_67 , 1 ) ;
return 0 ;
}
static void F_55 ( struct V_17 * V_18 )
{
V_18 -> V_123 = 0 ;
}
static void F_56 ( struct V_17 * V_18 , T_1 V_124 )
{
V_18 -> V_125 [ V_18 -> V_123 ] =
(struct V_126 * ) & V_127 [ V_124 ] ;
V_18 -> V_123 ++ ;
}
static void F_57 ( struct V_17 * V_18 , T_4 V_128 )
{
F_55 ( V_18 ) ;
if ( V_128 & V_74
|| V_128 & V_76
|| V_128 & V_78 )
F_56 ( V_18 , V_113 ) ;
if ( V_128 & V_92
|| V_128 & V_78 ) {
F_56 ( V_18 , V_115 ) ;
F_56 ( V_18 , V_116 ) ;
}
if ( V_128 & V_98 )
F_56 ( V_18 , V_117 ) ;
if ( V_128 & V_76 )
F_56 ( V_18 , V_118 ) ;
}
static void F_58 ( struct V_6 * V_7 ,
struct V_126 * V_129 )
{
F_5 ( V_7 , V_130 ) ;
memcpy ( F_17 ( V_7 ) , & V_129 -> V_2 , V_129 -> V_131 ) ;
V_7 -> V_3 += V_129 -> V_131 ;
F_8 ( V_7 ) ;
}
static int F_59 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_108 * V_109 ;
struct V_126 * V_132 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_53 == - V_32 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_22
L_23 ) ;
goto V_133;
}
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_24 ,
V_53 ) ;
goto V_133;
}
V_109 = (struct V_108 * ) V_52 ;
if ( V_109 -> V_134 ) {
V_21 = F_53 ( V_18 , V_109 , V_53 ) ;
if ( V_21 == 0 )
goto V_133;
if ( V_21 != - V_120 )
F_22 ( & V_18 -> V_34 -> V_18 , L_25
L_26 ) ;
}
V_18 -> V_111 = ( V_18 -> V_111 + 1 ) % V_18 -> V_123 ;
V_132 = V_18 -> V_125 [ V_18 -> V_111 ] ;
F_21 ( & V_18 -> V_34 -> V_18 , L_27 ,
V_18 -> V_111 ) ;
F_58 ( V_18 -> V_44 , V_132 ) ;
V_21 = F_29 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 , F_59 ,
NULL , V_42 ) ;
if ( V_21 == - V_136 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_28
L_29 ) ;
goto V_133;
}
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_30
L_31 , V_21 ) ;
goto V_133;
}
return - V_26 ;
V_133:
F_55 ( V_18 ) ;
V_18 -> V_119 = 0 ;
return 0 ;
}
static int F_60 ( struct V_122 * V_122 , T_4 V_128 )
{
struct V_17 * V_18 = F_61 ( V_122 ) ;
struct V_126 * V_137 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_32 , V_43 ,
V_128 ) ;
if ( V_18 -> V_123 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_33
L_34 ) ;
return - V_50 ;
}
if ( V_18 -> V_138 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_35
L_36 ) ;
return - V_50 ;
}
F_57 ( V_18 , V_128 ) ;
if ( ! V_18 -> V_123 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_37
L_38 ) ;
V_21 = - V_139 ;
goto error;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_39 ,
V_18 -> V_123 ) ;
V_18 -> V_111 = 0 ;
V_137 = V_18 -> V_125 [ V_18 -> V_111 ] ;
F_58 ( V_18 -> V_44 , V_137 ) ;
V_21 = F_32 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 , F_59 ,
NULL , V_56 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_40
L_41 , V_21 ) ;
goto error;
}
V_18 -> V_119 = V_128 ;
return 0 ;
error:
F_55 ( V_18 ) ;
return V_21 ;
}
static void F_62 ( struct V_122 * V_122 )
{
struct V_17 * V_18 = F_61 ( V_122 ) ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_123 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_42
L_43 ) ;
return;
}
F_28 ( V_18 , V_56 ) ;
F_63 ( V_18 -> V_36 ) ;
}
static int F_64 ( struct V_17 * V_18 )
{
struct V_140 V_141 ;
struct V_142 * V_109 ;
T_5 V_143 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , V_144 ) ;
V_141 . V_112 = 1 ;
V_141 . V_145 = 0 ;
memcpy ( F_17 ( V_18 -> V_44 ) , & V_141 ,
sizeof( struct V_140 ) ) ;
V_18 -> V_44 -> V_3 += sizeof( struct V_140 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 ) ;
if ( V_21 )
return V_21 ;
V_109 = (struct V_142 * )
F_17 ( V_18 -> V_20 ) ;
V_21 = V_109 -> V_30 & V_146 ;
if ( V_21 != V_147 )
return - V_38 ;
V_143 = F_18 ( V_18 -> V_20 ) - 16 ;
V_21 = F_65 ( V_18 -> V_122 , V_109 -> V_148 , V_143 ) ;
return V_21 ;
}
static int F_66 ( struct V_122 * V_122 ,
struct V_66 * V_149 , T_4 V_150 )
{
struct V_17 * V_18 = F_61 ( V_122 ) ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_44 , V_43 ,
V_150 ) ;
if ( V_18 -> V_123 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_45
L_46 ) ;
return - V_50 ;
}
if ( V_18 -> V_138 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_47
L_48 ) ;
return - V_50 ;
}
if ( ! V_18 -> V_121 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_49
L_50 ) ;
return - V_139 ;
}
if ( ! ( V_18 -> V_121 & ( 1 << V_150 ) ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_51
L_52 , V_150 ) ;
return - V_139 ;
}
if ( V_150 == V_151 ) {
V_21 = F_64 ( V_18 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_53
L_54
L_55 , V_21 ) ;
return V_21 ;
}
}
V_18 -> V_138 = V_150 ;
V_18 -> V_121 = 0 ;
return 0 ;
}
static void F_67 ( struct V_122 * V_122 ,
struct V_66 * V_149 )
{
struct V_17 * V_18 = F_61 ( V_122 ) ;
T_1 V_112 ;
T_1 V_30 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_138 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_56 ) ;
return;
}
V_18 -> V_138 = 0 ;
F_68 ( & V_18 -> V_152 ) ;
F_5 ( V_18 -> V_44 , V_153 ) ;
V_112 = 1 ;
memcpy ( F_17 ( V_18 -> V_44 ) , & V_112 , sizeof( T_1 ) ) ;
V_18 -> V_44 -> V_3 += sizeof( T_1 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_57
L_58 ) ;
return;
}
V_30 = F_17 ( V_18 -> V_20 ) [ 0 ] ;
V_21 = V_30 & V_146 ;
if ( V_21 != V_147 )
F_22 ( & V_18 -> V_34 -> V_18 , L_59
L_60 , V_21 ) ;
return;
}
static int F_69 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_154 * V_12 ;
struct V_155 * V_109 ;
struct V_66 V_66 ;
T_1 V_156 ;
int V_21 ;
if ( V_53 == - V_32 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_61 ) ;
return 0 ;
}
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_62 ,
V_53 ) ;
return 0 ;
}
if ( V_18 -> V_121 &&
! ( V_18 -> V_121 & ( 1 << V_151 ) ) ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_63 ) ;
return - V_139 ;
}
V_109 = (struct V_155 * ) V_52 ;
V_12 = (struct V_154 * ) V_49 ;
V_21 = V_109 -> V_30 & V_146 ;
if ( V_21 != V_147 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_64 , V_21 ) ;
return 0 ;
}
if ( ! V_18 -> V_121 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_65 ) ;
V_66 . V_73 = V_78 ;
V_66 . V_80 = 10 ;
memcpy ( V_66 . V_82 , V_109 -> V_157 , V_66 . V_80 ) ;
V_21 = F_54 ( V_18 -> V_122 , & V_66 , 1 ) ;
if ( V_21 )
return 0 ;
V_18 -> V_121 = 0 ;
}
V_18 -> V_138 = V_151 ;
V_156 = F_18 ( V_18 -> V_20 ) - 17 ;
V_21 = F_65 ( V_18 -> V_122 ,
V_109 -> V_148 , V_156 ) ;
if ( V_21 == 0 )
V_21 = F_70 ( V_18 -> V_122 ,
V_18 -> V_122 -> V_158 [ 0 ] . V_159 ,
! V_12 -> V_160 , V_161 ) ;
return 0 ;
}
static int F_71 ( struct V_122 * V_122 , struct V_66 * V_149 ,
T_1 V_162 , T_1 * V_163 , T_6 V_164 )
{
struct V_17 * V_18 = F_61 ( V_122 ) ;
struct V_154 * V_12 ;
T_1 V_165 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_18 -> V_123 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_66 ) ;
return - V_50 ;
}
if ( V_18 -> V_138 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_67 ) ;
return - V_50 ;
}
V_165 = sizeof( struct V_154 ) + V_164 ;
V_12 = F_72 ( V_165 , V_56 ) ;
if ( V_12 == NULL )
return - V_166 ;
F_5 ( V_18 -> V_44 , V_167 ) ;
V_12 -> V_160 = ! V_162 ;
V_12 -> V_168 = 0 ;
if ( V_163 != NULL && V_164 > 0 ) {
V_12 -> V_145 = 4 ;
memcpy ( V_12 -> V_148 , V_163 , V_164 ) ;
} else {
V_12 -> V_145 = 0 ;
}
memcpy ( F_17 ( V_18 -> V_44 ) , V_12 , V_165 ) ;
V_18 -> V_44 -> V_3 += V_165 ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_32 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 , F_69 ,
V_12 , V_56 ) ;
if ( V_21 )
goto V_169;
V_169:
F_73 ( V_12 ) ;
return V_21 ;
}
static int F_74 ( struct V_122 * V_122 )
{
F_67 ( V_122 , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_17 * V_18 , struct V_170 * V_171 )
{
int V_172 = V_171 -> V_131 ;
struct V_6 * V_44 ;
T_1 V_112 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_68 , V_43 ,
V_172 ) ;
if ( V_172 > V_173 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_69
L_70 ,
V_173 ) ;
return - V_174 ;
}
F_76 ( V_171 , V_175 ) ;
V_44 = (struct V_6 * ) V_171 -> V_2 ;
F_5 ( V_44 , V_176 ) ;
V_112 = 1 ;
memcpy ( F_17 ( V_44 ) , & V_112 , sizeof( T_1 ) ) ;
V_44 -> V_3 += sizeof( T_1 ) ;
V_44 -> V_3 += V_172 ;
F_8 ( V_44 ) ;
F_77 ( V_171 , V_177 ) ;
return 0 ;
}
static struct V_170 * F_78 ( struct V_17 * V_18 )
{
struct V_170 * V_171 , * V_178 , * V_179 ;
unsigned int V_180 = 0 , V_181 = 0 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_71 , V_43 ) ;
if ( F_79 ( & V_18 -> V_152 ) )
return NULL ;
if ( F_80 ( & V_18 -> V_152 ) == 1 ) {
V_171 = F_81 ( & V_18 -> V_152 ) ;
goto V_169;
}
F_82 (&dev->resp_q, tmp, t)
V_180 += V_178 -> V_131 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_72 ,
V_43 , V_180 ) ;
V_171 = F_83 ( V_180 , V_56 ) ;
if ( V_171 == NULL )
goto V_169;
F_77 ( V_171 , V_180 ) ;
F_82 (&dev->resp_q, tmp, t) {
memcpy ( V_171 -> V_2 + V_181 , V_178 -> V_2 , V_178 -> V_131 ) ;
V_181 += V_178 -> V_131 ;
}
V_169:
F_68 ( & V_18 -> V_152 ) ;
return V_171 ;
}
static int F_84 ( struct V_17 * V_18 , void * V_51 ,
T_1 * V_52 , int V_53 )
{
struct V_182 * V_49 = V_51 ;
struct V_170 * V_171 = NULL , * V_183 = V_49 -> V_183 ;
struct V_6 * V_20 = (struct V_6 * ) V_183 -> V_2 ;
int V_184 = 0 ;
T_1 V_30 ;
T_1 V_185 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_85 ( V_49 -> V_186 ) ;
if ( V_53 < 0 ) {
V_184 = V_53 ;
goto error;
}
V_30 = V_52 [ 0 ] ;
V_185 = V_30 & V_146 ;
if ( V_185 != V_147 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_73
L_74 , V_185 ) ;
V_184 = - V_38 ;
goto error;
}
F_77 ( V_183 , F_30 ( V_20 ) ) ;
F_86 ( V_183 , V_175 ) ;
F_87 ( V_183 , V_183 -> V_131 - V_177 ) ;
F_88 ( & V_18 -> V_152 , V_183 ) ;
if ( V_30 & V_187 ) {
F_23 ( V_18 -> V_39 , & V_18 -> V_188 ) ;
return - V_26 ;
}
V_171 = F_78 ( V_18 ) ;
if ( V_171 == NULL )
goto error;
V_49 -> V_189 ( V_49 -> V_190 , V_171 , 0 ) ;
F_73 ( V_49 ) ;
return 0 ;
error:
F_68 ( & V_18 -> V_152 ) ;
F_85 ( V_183 ) ;
V_49 -> V_189 ( V_49 -> V_190 , NULL , V_184 ) ;
F_73 ( V_49 ) ;
return 0 ;
}
static int F_89 ( struct V_122 * V_122 ,
struct V_66 * V_149 , struct V_170 * V_171 ,
T_7 V_189 , void * V_190 )
{
struct V_17 * V_18 = F_61 ( V_122 ) ;
struct V_6 * V_44 , * V_20 ;
struct V_182 * V_49 ;
struct V_170 * V_183 ;
int V_191 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_138 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_75
L_76 ) ;
V_21 = - V_139 ;
goto error;
}
V_21 = F_75 ( V_18 , V_171 ) ;
if ( V_21 )
goto error;
V_191 = V_175 +
V_173 +
V_177 ;
V_183 = F_90 ( V_191 , V_56 ) ;
if ( ! V_183 ) {
V_21 = - V_166 ;
goto error;
}
V_20 = (struct V_6 * ) V_183 -> V_2 ;
V_44 = (struct V_6 * ) V_171 -> V_2 ;
V_49 = F_91 ( sizeof( struct V_182 ) , V_56 ) ;
if ( ! V_49 ) {
V_21 = - V_166 ;
goto V_192;
}
V_49 -> V_183 = V_183 ;
V_49 -> V_186 = V_171 ;
V_49 -> V_189 = V_189 ;
V_49 -> V_190 = V_190 ;
V_21 = F_32 ( V_18 , V_44 , V_20 , V_191 ,
F_84 , V_49 ,
V_56 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_40
L_77 , V_21 ) ;
goto V_193;
}
return 0 ;
V_193:
F_73 ( V_49 ) ;
V_192:
F_92 ( V_183 ) ;
error:
F_92 ( V_171 ) ;
return V_21 ;
}
static void F_93 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_188 ) ;
struct V_170 * V_194 ;
struct V_182 * V_49 = V_18 -> V_25 ;
struct V_6 * V_44 , * V_20 ;
struct V_170 * V_183 ;
int V_191 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_194 = F_83 ( V_175 + V_177 ,
V_56 ) ;
if ( V_194 == NULL )
goto V_195;
F_94 ( V_194 , V_175 ) ;
V_21 = F_75 ( V_18 , V_194 ) ;
if ( V_21 )
goto V_196;
V_191 = V_175 +
V_173 +
V_177 ;
V_183 = F_83 ( V_191 , V_56 ) ;
if ( ! V_183 ) {
V_21 = - V_166 ;
goto V_196;
}
V_20 = (struct V_6 * ) V_183 -> V_2 ;
V_44 = (struct V_6 * ) V_194 -> V_2 ;
V_49 -> V_183 = V_183 ;
V_49 -> V_186 = V_194 ;
V_21 = F_29 ( V_18 , V_44 , V_20 ,
V_191 ,
F_84 ,
V_18 -> V_25 , V_56 ) ;
if ( ! V_21 )
return;
F_22 ( & V_18 -> V_34 -> V_18 , L_40
L_77 , V_21 ) ;
F_92 ( V_183 ) ;
V_196:
F_92 ( V_194 ) ;
V_195:
F_28 ( V_18 , V_56 ) ;
F_73 ( V_49 ) ;
F_19 ( & V_18 -> V_27 ) ;
}
static int F_95 ( struct V_17 * V_18 , T_1 V_197 , T_1 * V_198 ,
T_1 V_199 )
{
int V_21 ;
T_1 * V_52 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , V_200 ) ;
V_52 = F_17 ( V_18 -> V_44 ) ;
V_52 [ 0 ] = V_197 ;
memcpy ( & V_52 [ 1 ] , V_198 , V_199 ) ;
V_18 -> V_44 -> V_3 += ( 1 + V_199 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 ) ;
return V_21 ;
}
static int F_96 ( struct V_201 * V_34 ,
const struct V_202 * V_203 )
{
struct V_204 * V_205 ;
struct V_17 * V_18 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
struct V_210 V_211 ;
int V_212 = 0 ;
int V_213 = 0 ;
int V_21 = - V_166 ;
int V_5 ;
T_4 V_128 ;
V_18 = F_72 ( sizeof( * V_18 ) , V_56 ) ;
if ( ! V_18 )
return - V_166 ;
V_18 -> V_214 = F_97 ( F_98 ( V_34 ) ) ;
V_18 -> V_34 = V_34 ;
F_99 ( & V_18 -> V_27 , 1 ) ;
V_207 = V_34 -> V_215 ;
for ( V_5 = 0 ; V_5 < V_207 -> V_216 . V_217 ; ++ V_5 ) {
V_209 = & V_207 -> V_209 [ V_5 ] . V_216 ;
if ( ! V_212 && F_100 ( V_209 ) ) {
V_18 -> V_135 = F_101 ( V_209 -> V_218 ) ;
V_212 = V_209 -> V_219 ;
}
if ( ! V_213 && F_102 ( V_209 ) ) {
V_18 -> V_220 =
F_101 ( V_209 -> V_218 ) ;
V_213 = V_209 -> V_219 ;
}
}
if ( ! V_212 || ! V_213 ) {
F_22 ( & V_34 -> V_18 , L_78
L_79 ) ;
V_21 = - V_221 ;
goto error;
}
V_18 -> V_20 = F_91 ( V_18 -> V_135 , V_56 ) ;
V_18 -> V_36 = F_103 ( 0 , V_56 ) ;
V_18 -> V_44 = F_91 ( V_18 -> V_220 , V_56 ) ;
V_18 -> V_45 = F_103 ( 0 , V_56 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_44 ||
! V_18 -> V_36 || ! V_18 -> V_45 )
goto error;
F_104 ( V_18 -> V_36 , V_18 -> V_214 ,
F_105 ( V_18 -> V_214 , V_212 ) ,
NULL , 0 , NULL , V_18 ) ;
F_104 ( V_18 -> V_45 , V_18 -> V_214 ,
F_106 ( V_18 -> V_214 , V_213 ) ,
NULL , 0 ,
F_38 , V_18 ) ;
F_107 ( & V_18 -> V_19 , F_15 ) ;
F_107 ( & V_18 -> V_188 , F_93 ) ;
V_18 -> V_39 = F_108 ( L_80 ,
V_222 | V_223 | V_224 ,
1 ) ;
if ( V_18 -> V_39 == NULL )
goto error;
F_109 ( & V_18 -> V_152 ) ;
F_110 ( V_34 , V_18 ) ;
F_5 ( V_18 -> V_44 , V_225 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_135 ) ;
if ( V_21 )
goto V_226;
V_205 = (struct V_204 * )
F_17 ( V_18 -> V_20 ) ;
F_111 ( & V_18 -> V_34 -> V_18 , L_81
L_82 , V_205 -> V_227 , V_205 -> V_228 ) ;
V_128 = V_98
| V_74 | V_92
| V_76
| V_78 ;
V_18 -> V_122 = F_112 ( & V_229 , V_128 ,
V_175 ,
V_177 ) ;
if ( ! V_18 -> V_122 )
goto V_226;
F_113 ( V_18 -> V_122 , & V_34 -> V_18 ) ;
F_114 ( V_18 -> V_122 , V_18 ) ;
V_21 = F_115 ( V_18 -> V_122 ) ;
if ( V_21 )
goto V_230;
V_211 . V_231 = V_232 ;
V_211 . V_233 = 2 ;
V_211 . V_234 = V_235 ;
V_21 = F_95 ( V_18 , V_236 ,
( T_1 * ) & V_211 , sizeof( V_211 ) ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_83
L_84 ) ;
goto V_230;
}
return 0 ;
V_230:
F_116 ( V_18 -> V_122 ) ;
V_226:
F_117 ( V_18 -> V_39 ) ;
error:
F_73 ( V_18 -> V_20 ) ;
F_118 ( V_18 -> V_36 ) ;
F_73 ( V_18 -> V_44 ) ;
F_118 ( V_18 -> V_45 ) ;
F_73 ( V_18 ) ;
return V_21 ;
}
static void F_119 ( struct V_201 * V_34 )
{
struct V_17 * V_18 ;
V_18 = F_120 ( V_34 ) ;
F_110 ( V_34 , NULL ) ;
F_121 ( V_18 -> V_122 ) ;
F_116 ( V_18 -> V_122 ) ;
F_63 ( V_18 -> V_36 ) ;
F_63 ( V_18 -> V_45 ) ;
F_117 ( V_18 -> V_39 ) ;
F_68 ( & V_18 -> V_152 ) ;
F_73 ( V_18 -> V_20 ) ;
F_118 ( V_18 -> V_36 ) ;
F_73 ( V_18 -> V_44 ) ;
F_118 ( V_18 -> V_45 ) ;
F_73 ( V_18 ) ;
F_111 ( & V_34 -> V_18 , L_85 ) ;
}
