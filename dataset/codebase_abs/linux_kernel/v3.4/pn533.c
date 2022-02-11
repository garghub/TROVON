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
static void F_15 ( unsigned long V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
struct V_6 * V_18 = V_17 -> V_19 ;
int V_20 ;
if ( V_17 -> V_21 )
V_20 = V_17 -> V_22 ( V_17 , V_17 -> V_23 , NULL ,
V_17 -> V_21 ) ;
else
V_20 = V_17 -> V_22 ( V_17 , V_17 -> V_23 ,
F_16 ( V_18 ) ,
F_17 ( V_18 ) ) ;
if ( V_20 != - V_24 )
F_18 ( & V_17 -> V_25 ) ;
}
static void F_19 ( struct V_26 * V_26 )
{
struct V_16 * V_17 = V_26 -> V_27 ;
struct V_6 * V_18 ;
V_17 -> V_19 = NULL ;
switch ( V_26 -> V_28 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
F_20 ( & V_17 -> V_32 -> V_17 , L_1
L_2 , V_26 -> V_28 ) ;
V_17 -> V_21 = V_26 -> V_28 ;
goto V_33;
default:
F_21 ( & V_17 -> V_32 -> V_17 , L_3
L_4 , V_26 -> V_28 ) ;
V_17 -> V_21 = V_26 -> V_28 ;
goto V_33;
}
V_18 = V_17 -> V_34 -> V_35 ;
if ( ! F_11 ( V_18 ) ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_5 ) ;
V_17 -> V_21 = - V_36 ;
goto V_33;
}
if ( ! F_13 ( V_18 , V_17 -> V_12 ) ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_6
L_7 ) ;
V_17 -> V_21 = - V_36 ;
goto V_33;
}
F_20 ( & V_17 -> V_32 -> V_17 , L_8 ) ;
V_17 -> V_21 = 0 ;
V_17 -> V_19 = V_18 ;
V_33:
F_22 ( & V_17 -> V_37 ) ;
}
static int F_23 ( struct V_16 * V_17 , T_2 V_38 )
{
V_17 -> V_34 -> V_39 = F_19 ;
return F_24 ( V_17 -> V_34 , V_38 ) ;
}
static void F_25 ( struct V_26 * V_26 )
{
struct V_16 * V_17 = V_26 -> V_27 ;
struct V_6 * V_18 ;
int V_20 ;
switch ( V_26 -> V_28 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
F_20 ( & V_17 -> V_32 -> V_17 , L_1
L_2 , V_26 -> V_28 ) ;
V_17 -> V_21 = V_26 -> V_28 ;
goto V_33;
default:
F_21 ( & V_17 -> V_32 -> V_17 , L_3
L_4 , V_26 -> V_28 ) ;
V_17 -> V_21 = V_26 -> V_28 ;
goto V_33;
}
V_18 = V_17 -> V_34 -> V_35 ;
if ( ! F_12 ( V_18 ) ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_9 ) ;
V_17 -> V_21 = - V_36 ;
goto V_33;
}
F_20 ( & V_17 -> V_32 -> V_17 , L_10 ) ;
V_20 = F_23 ( V_17 , V_40 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_11
L_12 , V_20 ) ;
V_17 -> V_21 = V_20 ;
goto V_33;
}
return;
V_33:
V_17 -> V_19 = NULL ;
F_22 ( & V_17 -> V_37 ) ;
}
static int F_26 ( struct V_16 * V_17 , T_2 V_38 )
{
V_17 -> V_34 -> V_39 = F_25 ;
return F_24 ( V_17 -> V_34 , V_38 ) ;
}
static int F_27 ( struct V_16 * V_17 , T_2 V_38 )
{
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_3 ( V_17 -> V_42 ) ;
V_17 -> V_43 -> V_35 = V_17 -> V_42 ;
V_17 -> V_43 -> V_44 = V_45 ;
V_20 = F_24 ( V_17 -> V_43 , V_38 ) ;
return V_20 ;
}
static int F_28 ( struct V_16 * V_17 ,
struct V_6 * V_42 ,
struct V_6 * V_18 ,
int V_46 ,
T_3 V_22 ,
void * V_15 , T_2 V_38 )
{
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_14 ,
F_7 ( V_42 ) ) ;
V_17 -> V_12 = F_7 ( V_42 ) ;
V_17 -> V_22 = V_22 ;
V_17 -> V_23 = V_15 ;
V_17 -> V_43 -> V_35 = V_42 ;
V_17 -> V_43 -> V_44 =
F_29 ( V_42 ) ;
V_17 -> V_34 -> V_35 = V_18 ;
V_17 -> V_34 -> V_44 = V_46 ;
V_20 = F_24 ( V_17 -> V_43 , V_38 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_26 ( V_17 , V_38 ) ;
if ( V_20 )
goto error;
return 0 ;
error:
F_30 ( V_17 -> V_43 ) ;
return V_20 ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_6 * V_42 ,
struct V_6 * V_18 ,
int V_46 ,
T_3 V_22 ,
void * V_15 , T_2 V_38 )
{
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( F_32 ( & V_17 -> V_25 ) )
return - V_47 ;
V_20 = F_28 ( V_17 , V_42 , V_18 ,
V_46 , V_22 , V_15 , V_38 ) ;
if ( V_20 )
goto error;
return 0 ;
error:
F_18 ( & V_17 -> V_25 ) ;
return V_20 ;
}
static int F_33 ( struct V_16 * V_17 , void * V_48 ,
T_1 * V_49 , int V_50 )
{
struct V_51 * V_15 = V_48 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
V_15 -> V_20 = 0 ;
if ( V_50 < 0 )
V_15 -> V_20 = V_50 ;
V_39 ( & V_15 -> V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_16 * V_17 ,
struct V_6 * V_42 ,
struct V_6 * V_18 ,
int V_46 )
{
int V_20 ;
struct V_51 V_15 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_35 ( & V_15 . V_52 ) ;
V_20 = F_31 ( V_17 , V_42 , V_18 , V_46 ,
F_33 , & V_15 , V_53 ) ;
if ( V_20 )
return V_20 ;
F_36 ( & V_15 . V_52 ) ;
return V_15 . V_20 ;
}
static void F_37 ( struct V_26 * V_26 )
{
struct V_16 * V_17 = V_26 -> V_27 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
switch ( V_26 -> V_28 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
F_20 ( & V_17 -> V_32 -> V_17 , L_1
L_2 , V_26 -> V_28 ) ;
break;
default:
F_20 ( & V_17 -> V_32 -> V_17 , L_3
L_4 , V_26 -> V_28 ) ;
}
}
static bool F_38 ( struct V_54 * V_55 ,
int V_56 )
{
T_1 V_57 ;
T_1 V_58 ;
if ( V_56 < sizeof( struct V_54 ) )
return false ;
V_57 = F_39 ( V_55 -> V_59 ) ;
V_58 = F_40 ( V_55 -> V_59 ) ;
if ( ( V_57 == V_60 &&
V_58 != V_61 ) ||
( V_57 != V_60 &&
V_58 == V_61 ) )
return false ;
if ( F_41 ( V_55 -> V_62 ) != 0 )
return false ;
return true ;
}
static int F_42 ( struct V_63 * V_64 , T_1 * V_65 ,
int V_66 )
{
struct V_54 * V_67 ;
V_67 = (struct V_54 * ) V_65 ;
if ( ! F_38 ( V_67 , V_66 ) )
return - V_68 ;
switch ( F_43 ( V_67 -> V_62 ) ) {
case V_69 :
V_64 -> V_70 = V_71 ;
break;
case V_72 :
V_64 -> V_70 = V_73 ;
break;
case V_74 :
V_64 -> V_70 = V_75 ;
break;
case V_76 :
V_64 -> V_70 = V_73 |
V_75 ;
break;
}
V_64 -> V_59 = F_44 ( V_67 -> V_59 ) ;
V_64 -> V_62 = V_67 -> V_62 ;
V_64 -> V_77 = V_67 -> V_78 ;
memcpy ( V_64 -> V_79 , V_67 -> V_80 , V_64 -> V_77 ) ;
return 0 ;
}
static bool F_45 ( struct V_81 * V_82 ,
int V_56 )
{
if ( V_56 < sizeof( struct V_81 ) )
return false ;
if ( V_82 -> V_83 != V_84 )
return false ;
return true ;
}
static int F_46 ( struct V_63 * V_64 , T_1 * V_65 ,
int V_66 )
{
struct V_81 * V_85 ;
V_85 = (struct V_81 * ) V_65 ;
if ( ! F_45 ( V_85 , V_66 ) )
return - V_68 ;
if ( V_85 -> V_86 [ 0 ] == V_87 &&
V_85 -> V_86 [ 1 ] ==
V_88 )
V_64 -> V_70 = V_75 ;
else
V_64 -> V_70 = V_89 ;
memcpy ( V_64 -> V_90 , & V_85 -> V_83 , 9 ) ;
V_64 -> V_91 = 9 ;
return 0 ;
}
static bool F_47 ( struct V_92 * V_93 ,
int V_56 )
{
T_1 V_57 ;
T_1 V_58 ;
if ( V_56 < sizeof( struct V_92 ) )
return false ;
V_57 = F_39 ( V_93 -> V_59 ) ;
V_58 = F_40 ( V_93 -> V_59 ) ;
if ( ( V_57 == V_60 &&
V_58 != V_61 ) ||
( V_57 != V_60 &&
V_58 == V_61 ) )
return false ;
return true ;
}
static int F_48 ( struct V_63 * V_64 , T_1 * V_65 ,
int V_66 )
{
struct V_92 * V_94 ;
V_94 = (struct V_92 * ) V_65 ;
if ( ! F_47 ( V_94 , V_66 ) )
return - V_68 ;
V_64 -> V_70 = V_95 ;
V_64 -> V_59 = F_44 ( V_94 -> V_59 ) ;
V_64 -> V_77 = 4 ;
memcpy ( V_64 -> V_79 , V_94 -> V_96 , V_64 -> V_77 ) ;
return 0 ;
}
static bool F_49 ( struct V_97 * V_98 ,
int V_56 )
{
if ( V_56 < sizeof( struct V_97 ) )
return false ;
if ( V_98 -> V_99 . V_83 != V_100 )
return false ;
if ( F_50 ( V_98 -> V_99 . V_101 . V_102 ) &
V_103 )
return false ;
return true ;
}
static int F_51 ( struct V_63 * V_64 , T_1 * V_65 ,
int V_66 )
{
struct V_97 * V_104 ;
V_104 = (struct V_97 * ) V_65 ;
if ( ! F_49 ( V_104 , V_66 ) )
return - V_68 ;
V_64 -> V_70 = V_73 ;
return 0 ;
}
static int F_52 ( struct V_16 * V_17 ,
struct V_105 * V_106 , int V_107 )
{
int V_56 ;
struct V_63 V_64 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_15 , V_41 ,
V_17 -> V_108 ) ;
if ( V_106 -> V_109 != 1 )
return - V_68 ;
memset ( & V_64 , 0 , sizeof( struct V_63 ) ) ;
V_56 = V_107 - sizeof( struct V_105 ) ;
switch ( V_17 -> V_108 ) {
case V_110 :
V_20 = F_42 ( & V_64 , V_106 -> V_111 ,
V_56 ) ;
break;
case V_112 :
case V_113 :
V_20 = F_46 ( & V_64 , V_106 -> V_111 ,
V_56 ) ;
break;
case V_114 :
V_20 = F_48 ( & V_64 , V_106 -> V_111 ,
V_56 ) ;
break;
case V_115 :
V_20 = F_51 ( & V_64 , V_106 -> V_111 ,
V_56 ) ;
break;
default:
F_21 ( & V_17 -> V_32 -> V_17 , L_16
L_17 ) ;
return - V_68 ;
}
if ( V_20 )
return V_20 ;
if ( ! ( V_64 . V_70 & V_17 -> V_116 ) ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_18
L_19 ) ;
return - V_117 ;
}
F_20 ( & V_17 -> V_32 -> V_17 , L_20
L_21 , V_64 . V_70 ) ;
V_17 -> V_118 = V_64 . V_70 ;
F_53 ( V_17 -> V_119 , & V_64 , 1 ) ;
return 0 ;
}
static void F_54 ( struct V_16 * V_17 )
{
V_17 -> V_120 = 0 ;
}
static void F_55 ( struct V_16 * V_17 , T_1 V_121 )
{
V_17 -> V_122 [ V_17 -> V_120 ] =
(struct V_123 * ) & V_124 [ V_121 ] ;
V_17 -> V_120 ++ ;
}
static void F_56 ( struct V_16 * V_17 , T_4 V_125 )
{
F_54 ( V_17 ) ;
if ( V_125 & V_71
|| V_125 & V_73
|| V_125 & V_75 )
F_55 ( V_17 , V_110 ) ;
if ( V_125 & V_89
|| V_125 & V_75 ) {
F_55 ( V_17 , V_112 ) ;
F_55 ( V_17 , V_113 ) ;
}
if ( V_125 & V_95 )
F_55 ( V_17 , V_114 ) ;
if ( V_125 & V_73 )
F_55 ( V_17 , V_115 ) ;
}
static void F_57 ( struct V_6 * V_7 ,
struct V_123 * V_126 )
{
F_5 ( V_7 , V_127 ) ;
memcpy ( F_16 ( V_7 ) , & V_126 -> V_2 , V_126 -> V_128 ) ;
V_7 -> V_3 += V_126 -> V_128 ;
F_8 ( V_7 ) ;
}
static int F_58 ( struct V_16 * V_17 , void * V_15 ,
T_1 * V_49 , int V_50 )
{
struct V_105 * V_106 ;
struct V_123 * V_129 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( V_50 == - V_30 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_22
L_23 ) ;
goto V_130;
}
if ( V_50 < 0 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_24 ,
V_50 ) ;
goto V_130;
}
V_106 = (struct V_105 * ) V_49 ;
if ( V_106 -> V_131 ) {
V_20 = F_52 ( V_17 , V_106 , V_50 ) ;
if ( V_20 == 0 )
goto V_130;
if ( V_20 != - V_117 )
F_21 ( & V_17 -> V_32 -> V_17 , L_25
L_26 ) ;
}
V_17 -> V_108 = ( V_17 -> V_108 + 1 ) % V_17 -> V_120 ;
V_129 = V_17 -> V_122 [ V_17 -> V_108 ] ;
F_20 ( & V_17 -> V_32 -> V_17 , L_27 ,
V_17 -> V_108 ) ;
F_57 ( V_17 -> V_42 , V_129 ) ;
V_20 = F_28 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 , F_58 ,
NULL , V_40 ) ;
if ( V_20 == - V_133 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_28
L_29 ) ;
goto V_130;
}
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_30
L_31 , V_20 ) ;
goto V_130;
}
return - V_24 ;
V_130:
F_54 ( V_17 ) ;
V_17 -> V_116 = 0 ;
return 0 ;
}
static int F_59 ( struct V_119 * V_119 , T_4 V_125 )
{
struct V_16 * V_17 = F_60 ( V_119 ) ;
struct V_123 * V_134 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_32 , V_41 ,
V_125 ) ;
if ( V_17 -> V_120 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_33
L_34 ) ;
return - V_47 ;
}
if ( V_17 -> V_135 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_35
L_36 ) ;
return - V_47 ;
}
F_56 ( V_17 , V_125 ) ;
if ( ! V_17 -> V_120 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_37
L_38 ) ;
V_20 = - V_136 ;
goto error;
}
F_20 ( & V_17 -> V_32 -> V_17 , L_39 ,
V_17 -> V_120 ) ;
V_17 -> V_108 = 0 ;
V_134 = V_17 -> V_122 [ V_17 -> V_108 ] ;
F_57 ( V_17 -> V_42 , V_134 ) ;
V_20 = F_31 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 , F_58 ,
NULL , V_53 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_40
L_41 , V_20 ) ;
goto error;
}
V_17 -> V_116 = V_125 ;
return 0 ;
error:
F_54 ( V_17 ) ;
return V_20 ;
}
static void F_61 ( struct V_119 * V_119 )
{
struct V_16 * V_17 = F_60 ( V_119 ) ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_120 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_42
L_43 ) ;
return;
}
F_27 ( V_17 , V_53 ) ;
F_62 ( V_17 -> V_34 ) ;
}
static int F_63 ( struct V_16 * V_17 )
{
struct V_137 V_138 ;
struct V_139 * V_106 ;
T_5 V_140 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_5 ( V_17 -> V_42 , V_141 ) ;
V_138 . V_109 = 1 ;
V_138 . V_142 = 0 ;
memcpy ( F_16 ( V_17 -> V_42 ) , & V_138 ,
sizeof( struct V_137 ) ) ;
V_17 -> V_42 -> V_3 += sizeof( struct V_137 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 ) ;
if ( V_20 )
return V_20 ;
V_106 = (struct V_139 * )
F_16 ( V_17 -> V_18 ) ;
V_20 = V_106 -> V_28 & V_143 ;
if ( V_20 != V_144 )
return - V_36 ;
V_140 = F_17 ( V_17 -> V_18 ) - 16 ;
V_20 = F_64 ( V_17 -> V_119 , V_106 -> V_145 , V_140 ) ;
return V_20 ;
}
static int F_65 ( struct V_119 * V_119 , T_4 V_146 ,
T_4 V_147 )
{
struct V_16 * V_17 = F_60 ( V_119 ) ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_44 , V_41 ,
V_147 ) ;
if ( V_17 -> V_120 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_45
L_46 ) ;
return - V_47 ;
}
if ( V_17 -> V_135 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_47
L_48 ) ;
return - V_47 ;
}
if ( ! V_17 -> V_118 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_49
L_50 ) ;
return - V_136 ;
}
if ( ! ( V_17 -> V_118 & ( 1 << V_147 ) ) ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_51
L_52 , V_147 ) ;
return - V_136 ;
}
if ( V_147 == V_148 ) {
V_20 = F_63 ( V_17 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_53
L_54
L_55 , V_20 ) ;
return V_20 ;
}
}
V_17 -> V_135 = V_147 ;
V_17 -> V_118 = 0 ;
return 0 ;
}
static void F_66 ( struct V_119 * V_119 , T_4 V_146 )
{
struct V_16 * V_17 = F_60 ( V_119 ) ;
T_1 V_109 ;
T_1 V_28 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_135 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_56 ) ;
return;
}
V_17 -> V_135 = 0 ;
F_5 ( V_17 -> V_42 , V_149 ) ;
V_109 = 1 ;
memcpy ( F_16 ( V_17 -> V_42 ) , & V_109 , sizeof( T_1 ) ) ;
V_17 -> V_42 -> V_3 += sizeof( T_1 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_57
L_58 ) ;
return;
}
V_28 = F_16 ( V_17 -> V_18 ) [ 0 ] ;
V_20 = V_28 & V_143 ;
if ( V_20 != V_144 )
F_21 ( & V_17 -> V_32 -> V_17 , L_59
L_60 , V_20 ) ;
return;
}
static int F_67 ( struct V_16 * V_17 , void * V_15 ,
T_1 * V_49 , int V_50 )
{
struct V_150 * V_12 ;
struct V_151 * V_106 ;
struct V_63 V_63 ;
T_1 V_152 ;
int V_20 ;
if ( V_50 == - V_30 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_61 ) ;
return 0 ;
}
if ( V_50 < 0 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_62 ,
V_50 ) ;
return 0 ;
}
if ( V_17 -> V_118 &&
! ( V_17 -> V_118 & ( 1 << V_148 ) ) ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_63 ) ;
return - V_136 ;
}
V_106 = (struct V_151 * ) V_49 ;
V_12 = (struct V_150 * ) V_15 ;
V_20 = V_106 -> V_28 & V_143 ;
if ( V_20 != V_144 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_64 , V_20 ) ;
return 0 ;
}
if ( ! V_17 -> V_118 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_65 ) ;
V_63 . V_70 = V_75 ;
V_63 . V_77 = 10 ;
memcpy ( V_63 . V_79 , V_106 -> V_153 , V_63 . V_77 ) ;
V_20 = F_53 ( V_17 -> V_119 , & V_63 , 1 ) ;
if ( V_20 )
return 0 ;
V_17 -> V_118 = 0 ;
}
V_17 -> V_135 = V_148 ;
V_152 = F_17 ( V_17 -> V_18 ) - 17 ;
V_20 = F_64 ( V_17 -> V_119 ,
V_106 -> V_145 , V_152 ) ;
if ( V_20 == 0 )
V_20 = F_68 ( V_17 -> V_119 ,
V_17 -> V_119 -> V_154 [ 0 ] . V_155 ,
! V_12 -> V_156 , V_157 ) ;
return 0 ;
}
static int F_69 ( struct V_119 * V_119 , int V_146 ,
T_1 V_158 , T_1 * V_159 , T_6 V_160 )
{
struct V_16 * V_17 = F_60 ( V_119 ) ;
struct V_150 * V_12 ;
T_1 V_161 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( V_17 -> V_120 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_66 ) ;
return - V_47 ;
}
if ( V_17 -> V_135 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_67 ) ;
return - V_47 ;
}
V_161 = sizeof( struct V_150 ) + V_160 ;
V_12 = F_70 ( V_161 , V_53 ) ;
if ( V_12 == NULL )
return - V_162 ;
F_5 ( V_17 -> V_42 , V_163 ) ;
V_12 -> V_156 = ! V_158 ;
V_12 -> V_164 = 0 ;
if ( V_159 != NULL && V_160 > 0 ) {
V_12 -> V_142 = 4 ;
memcpy ( V_12 -> V_145 , V_159 , V_160 ) ;
} else {
V_12 -> V_142 = 0 ;
}
memcpy ( F_16 ( V_17 -> V_42 ) , V_12 , V_161 ) ;
V_17 -> V_42 -> V_3 += V_161 ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_31 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 , F_67 ,
V_12 , V_53 ) ;
if ( V_20 )
goto V_165;
V_165:
F_71 ( V_12 ) ;
return V_20 ;
}
static int F_72 ( struct V_119 * V_119 )
{
F_66 ( V_119 , 0 ) ;
return 0 ;
}
static int F_73 ( struct V_16 * V_17 , struct V_166 * V_167 )
{
int V_168 = V_167 -> V_128 ;
struct V_6 * V_42 ;
T_1 V_109 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_68 , V_41 ,
V_168 ) ;
if ( V_168 > V_169 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_69
L_70 ,
V_169 ) ;
return - V_170 ;
}
F_74 ( V_167 , V_171 ) ;
V_42 = (struct V_6 * ) V_167 -> V_2 ;
F_5 ( V_42 , V_172 ) ;
V_109 = 1 ;
memcpy ( F_16 ( V_42 ) , & V_109 , sizeof( T_1 ) ) ;
V_42 -> V_3 += sizeof( T_1 ) ;
V_42 -> V_3 += V_168 ;
F_8 ( V_42 ) ;
F_75 ( V_167 , V_173 ) ;
return 0 ;
}
static int F_76 ( struct V_16 * V_17 , void * V_48 ,
T_1 * V_49 , int V_50 )
{
struct V_174 * V_15 = V_48 ;
struct V_166 * V_175 = V_15 -> V_175 ;
struct V_6 * V_18 = (struct V_6 * ) V_175 -> V_2 ;
int V_176 = 0 ;
T_1 V_28 ;
T_1 V_177 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_77 ( V_15 -> V_178 ) ;
if ( V_50 < 0 ) {
V_176 = V_50 ;
goto error;
}
F_75 ( V_175 , F_29 ( V_18 ) ) ;
V_28 = V_49 [ 0 ] ;
V_177 = V_28 & V_143 ;
if ( V_177 != V_144 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_71
L_72 , V_177 ) ;
V_176 = - V_36 ;
goto error;
}
if ( V_28 & V_179 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_73
L_74 ) ;
F_27 ( V_17 , V_40 ) ;
V_176 = - V_170 ;
goto error;
}
F_78 ( V_175 , V_171 ) ;
F_79 ( V_175 , V_175 -> V_128 - V_173 ) ;
V_15 -> V_180 ( V_15 -> V_181 , V_175 , 0 ) ;
F_71 ( V_15 ) ;
return 0 ;
error:
F_77 ( V_175 ) ;
V_15 -> V_180 ( V_15 -> V_181 , NULL , V_176 ) ;
F_71 ( V_15 ) ;
return 0 ;
}
static int F_80 ( struct V_119 * V_119 , T_4 V_146 ,
struct V_166 * V_167 ,
T_7 V_180 ,
void * V_181 )
{
struct V_16 * V_17 = F_60 ( V_119 ) ;
struct V_6 * V_42 , * V_18 ;
struct V_174 * V_15 ;
struct V_166 * V_175 ;
int V_182 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_135 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_75
L_76 ) ;
V_20 = - V_136 ;
goto error;
}
V_20 = F_73 ( V_17 , V_167 ) ;
if ( V_20 )
goto error;
V_182 = V_171 +
V_169 +
V_173 ;
V_175 = F_81 ( V_182 , V_53 ) ;
if ( ! V_175 ) {
V_20 = - V_162 ;
goto error;
}
V_18 = (struct V_6 * ) V_175 -> V_2 ;
V_42 = (struct V_6 * ) V_167 -> V_2 ;
V_15 = F_82 ( sizeof( struct V_174 ) , V_53 ) ;
if ( ! V_15 ) {
V_20 = - V_162 ;
goto V_183;
}
V_15 -> V_175 = V_175 ;
V_15 -> V_178 = V_167 ;
V_15 -> V_180 = V_180 ;
V_15 -> V_181 = V_181 ;
V_20 = F_31 ( V_17 , V_42 , V_18 , V_182 ,
F_76 , V_15 ,
V_53 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_40
L_77 , V_20 ) ;
goto V_184;
}
return 0 ;
V_184:
F_71 ( V_15 ) ;
V_183:
F_83 ( V_175 ) ;
error:
F_83 ( V_167 ) ;
return V_20 ;
}
static int F_84 ( struct V_16 * V_17 , T_1 V_185 , T_1 * V_186 ,
T_1 V_187 )
{
int V_20 ;
T_1 * V_49 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_5 ( V_17 -> V_42 , V_188 ) ;
V_49 = F_16 ( V_17 -> V_42 ) ;
V_49 [ 0 ] = V_185 ;
memcpy ( & V_49 [ 1 ] , V_186 , V_187 ) ;
V_17 -> V_42 -> V_3 += ( 1 + V_187 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 ) ;
return V_20 ;
}
static int F_85 ( struct V_189 * V_32 ,
const struct V_190 * V_191 )
{
struct V_192 * V_193 ;
struct V_16 * V_17 ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
struct V_198 V_199 ;
int V_200 = 0 ;
int V_201 = 0 ;
int V_20 = - V_162 ;
int V_5 ;
T_4 V_125 ;
V_17 = F_70 ( sizeof( * V_17 ) , V_53 ) ;
if ( ! V_17 )
return - V_162 ;
V_17 -> V_202 = F_86 ( F_87 ( V_32 ) ) ;
V_17 -> V_32 = V_32 ;
F_88 ( & V_17 -> V_25 , 1 ) ;
V_195 = V_32 -> V_203 ;
for ( V_5 = 0 ; V_5 < V_195 -> V_204 . V_205 ; ++ V_5 ) {
V_197 = & V_195 -> V_197 [ V_5 ] . V_204 ;
if ( ! V_200 && F_89 ( V_197 ) ) {
V_17 -> V_132 = F_90 ( V_197 -> V_206 ) ;
V_200 = V_197 -> V_207 ;
}
if ( ! V_201 && F_91 ( V_197 ) ) {
V_17 -> V_208 =
F_90 ( V_197 -> V_206 ) ;
V_201 = V_197 -> V_207 ;
}
}
if ( ! V_200 || ! V_201 ) {
F_21 ( & V_32 -> V_17 , L_78
L_79 ) ;
V_20 = - V_209 ;
goto error;
}
V_17 -> V_18 = F_82 ( V_17 -> V_132 , V_53 ) ;
V_17 -> V_34 = F_92 ( 0 , V_53 ) ;
V_17 -> V_42 = F_82 ( V_17 -> V_208 , V_53 ) ;
V_17 -> V_43 = F_92 ( 0 , V_53 ) ;
if ( ! V_17 -> V_18 || ! V_17 -> V_42 ||
! V_17 -> V_34 || ! V_17 -> V_43 )
goto error;
F_93 ( V_17 -> V_34 , V_17 -> V_202 ,
F_94 ( V_17 -> V_202 , V_200 ) ,
NULL , 0 , NULL , V_17 ) ;
F_93 ( V_17 -> V_43 , V_17 -> V_202 ,
F_95 ( V_17 -> V_202 , V_201 ) ,
NULL , 0 ,
F_37 , V_17 ) ;
F_96 ( & V_17 -> V_37 , F_15 , ( V_210 ) V_17 ) ;
F_97 ( V_32 , V_17 ) ;
F_5 ( V_17 -> V_42 , V_211 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_132 ) ;
if ( V_20 )
goto V_212;
V_193 = (struct V_192 * )
F_16 ( V_17 -> V_18 ) ;
F_98 ( & V_17 -> V_32 -> V_17 , L_80
L_81 , V_193 -> V_213 , V_193 -> V_214 ) ;
V_125 = V_95
| V_71 | V_89
| V_73
| V_75 ;
V_17 -> V_119 = F_99 ( & V_215 , V_125 ,
V_171 ,
V_173 ) ;
if ( ! V_17 -> V_119 )
goto V_212;
F_100 ( V_17 -> V_119 , & V_32 -> V_17 ) ;
F_101 ( V_17 -> V_119 , V_17 ) ;
V_20 = F_102 ( V_17 -> V_119 ) ;
if ( V_20 )
goto V_216;
V_199 . V_217 = V_218 ;
V_199 . V_219 = 2 ;
V_199 . V_220 = V_221 ;
V_20 = F_84 ( V_17 , V_222 ,
( T_1 * ) & V_199 , sizeof( V_199 ) ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_82
L_83 ) ;
goto V_216;
}
return 0 ;
V_216:
F_103 ( V_17 -> V_119 ) ;
V_212:
F_104 ( & V_17 -> V_37 ) ;
error:
F_71 ( V_17 -> V_18 ) ;
F_105 ( V_17 -> V_34 ) ;
F_71 ( V_17 -> V_42 ) ;
F_105 ( V_17 -> V_43 ) ;
F_71 ( V_17 ) ;
return V_20 ;
}
static void F_106 ( struct V_189 * V_32 )
{
struct V_16 * V_17 ;
V_17 = F_107 ( V_32 ) ;
F_97 ( V_32 , NULL ) ;
F_108 ( V_17 -> V_119 ) ;
F_103 ( V_17 -> V_119 ) ;
F_62 ( V_17 -> V_34 ) ;
F_62 ( V_17 -> V_43 ) ;
F_104 ( & V_17 -> V_37 ) ;
F_71 ( V_17 -> V_18 ) ;
F_105 ( V_17 -> V_34 ) ;
F_71 ( V_17 -> V_42 ) ;
F_105 ( V_17 -> V_43 ) ;
F_71 ( V_17 ) ;
F_98 ( & V_32 -> V_17 , L_84 ) ;
}
