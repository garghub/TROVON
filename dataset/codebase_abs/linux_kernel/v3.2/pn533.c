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
return 0 ;
}
static bool F_45 ( struct V_77 * V_78 ,
int V_56 )
{
if ( V_56 < sizeof( struct V_77 ) )
return false ;
if ( V_78 -> V_79 != V_80 )
return false ;
return true ;
}
static int F_46 ( struct V_63 * V_64 , T_1 * V_65 ,
int V_66 )
{
struct V_77 * V_81 ;
V_81 = (struct V_77 * ) V_65 ;
if ( ! F_45 ( V_81 , V_66 ) )
return - V_68 ;
if ( V_81 -> V_82 [ 0 ] == V_83 &&
V_81 -> V_82 [ 1 ] ==
V_84 )
V_64 -> V_70 = V_75 ;
else
V_64 -> V_70 = V_85 ;
return 0 ;
}
static bool F_47 ( struct V_86 * V_87 ,
int V_56 )
{
T_1 V_57 ;
T_1 V_58 ;
if ( V_56 < sizeof( struct V_86 ) )
return false ;
V_57 = F_39 ( V_87 -> V_59 ) ;
V_58 = F_40 ( V_87 -> V_59 ) ;
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
struct V_86 * V_88 ;
V_88 = (struct V_86 * ) V_65 ;
if ( ! F_47 ( V_88 , V_66 ) )
return - V_68 ;
V_64 -> V_70 = V_89 ;
V_64 -> V_59 = F_44 ( V_88 -> V_59 ) ;
return 0 ;
}
static bool F_49 ( struct V_90 * V_91 ,
int V_56 )
{
if ( V_56 < sizeof( struct V_90 ) )
return false ;
if ( V_91 -> V_92 . V_79 != V_93 )
return false ;
if ( F_50 ( V_91 -> V_92 . V_94 . V_95 ) &
V_96 )
return false ;
return true ;
}
static int F_51 ( struct V_63 * V_64 , T_1 * V_65 ,
int V_66 )
{
struct V_90 * V_97 ;
V_97 = (struct V_90 * ) V_65 ;
if ( ! F_49 ( V_97 , V_66 ) )
return - V_68 ;
V_64 -> V_70 = V_73 ;
return 0 ;
}
static int F_52 ( struct V_16 * V_17 ,
struct V_98 * V_99 , int V_100 )
{
int V_56 ;
struct V_63 V_64 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_15 , V_41 ,
V_17 -> V_101 ) ;
if ( V_99 -> V_102 != 1 )
return - V_68 ;
V_56 = V_100 - sizeof( struct V_98 ) ;
switch ( V_17 -> V_101 ) {
case V_103 :
V_20 = F_42 ( & V_64 , V_99 -> V_104 ,
V_56 ) ;
break;
case V_105 :
case V_106 :
V_20 = F_46 ( & V_64 , V_99 -> V_104 ,
V_56 ) ;
break;
case V_107 :
V_20 = F_48 ( & V_64 , V_99 -> V_104 ,
V_56 ) ;
break;
case V_108 :
V_20 = F_51 ( & V_64 , V_99 -> V_104 ,
V_56 ) ;
break;
default:
F_21 ( & V_17 -> V_32 -> V_17 , L_16
L_17 ) ;
return - V_68 ;
}
if ( V_20 )
return V_20 ;
if ( ! ( V_64 . V_70 & V_17 -> V_109 ) ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_18
L_19 ) ;
return - V_110 ;
}
F_20 ( & V_17 -> V_32 -> V_17 , L_20
L_21 , V_64 . V_70 ) ;
V_17 -> V_111 = V_64 . V_70 ;
F_53 ( V_17 -> V_112 , & V_64 , 1 ) ;
return 0 ;
}
static void F_54 ( struct V_16 * V_17 )
{
V_17 -> V_113 = 0 ;
}
static void F_55 ( struct V_16 * V_17 , T_1 V_114 )
{
V_17 -> V_115 [ V_17 -> V_113 ] =
(struct V_116 * ) & V_117 [ V_114 ] ;
V_17 -> V_113 ++ ;
}
static void F_56 ( struct V_16 * V_17 , T_4 V_118 )
{
F_54 ( V_17 ) ;
if ( V_118 & V_71
|| V_118 & V_73
|| V_118 & V_75 )
F_55 ( V_17 , V_103 ) ;
if ( V_118 & V_85
|| V_118 & V_75 ) {
F_55 ( V_17 , V_105 ) ;
F_55 ( V_17 , V_106 ) ;
}
if ( V_118 & V_89 )
F_55 ( V_17 , V_107 ) ;
if ( V_118 & V_73 )
F_55 ( V_17 , V_108 ) ;
}
static void F_57 ( struct V_6 * V_7 ,
struct V_116 * V_119 )
{
F_5 ( V_7 , V_120 ) ;
memcpy ( F_16 ( V_7 ) , & V_119 -> V_2 , V_119 -> V_121 ) ;
V_7 -> V_3 += V_119 -> V_121 ;
F_8 ( V_7 ) ;
}
static int F_58 ( struct V_16 * V_17 , void * V_15 ,
T_1 * V_49 , int V_50 )
{
struct V_98 * V_99 ;
struct V_116 * V_122 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( V_50 == - V_30 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_22
L_23 ) ;
goto V_123;
}
if ( V_50 < 0 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_24 ,
V_50 ) ;
goto V_123;
}
V_99 = (struct V_98 * ) V_49 ;
if ( V_99 -> V_124 ) {
V_20 = F_52 ( V_17 , V_99 , V_50 ) ;
if ( V_20 == 0 )
goto V_123;
if ( V_20 != - V_110 )
F_21 ( & V_17 -> V_32 -> V_17 , L_25
L_26 ) ;
}
V_17 -> V_101 = ( V_17 -> V_101 + 1 ) % V_17 -> V_113 ;
V_122 = V_17 -> V_115 [ V_17 -> V_101 ] ;
F_20 ( & V_17 -> V_32 -> V_17 , L_27 ,
V_17 -> V_101 ) ;
F_57 ( V_17 -> V_42 , V_122 ) ;
V_20 = F_28 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 , F_58 ,
NULL , V_40 ) ;
if ( V_20 == - V_126 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_28
L_29 ) ;
goto V_123;
}
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_30
L_31 , V_20 ) ;
goto V_123;
}
return - V_24 ;
V_123:
F_54 ( V_17 ) ;
V_17 -> V_109 = 0 ;
return 0 ;
}
static int F_59 ( struct V_112 * V_112 , T_4 V_118 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
struct V_116 * V_127 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_32 , V_41 ,
V_118 ) ;
if ( V_17 -> V_113 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_33
L_34 ) ;
return - V_47 ;
}
if ( V_17 -> V_128 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_35
L_36 ) ;
return - V_47 ;
}
F_56 ( V_17 , V_118 ) ;
if ( ! V_17 -> V_113 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_37
L_38 ) ;
V_20 = - V_129 ;
goto error;
}
F_20 ( & V_17 -> V_32 -> V_17 , L_39 ,
V_17 -> V_113 ) ;
V_17 -> V_101 = 0 ;
V_127 = V_17 -> V_115 [ V_17 -> V_101 ] ;
F_57 ( V_17 -> V_42 , V_127 ) ;
V_20 = F_31 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 , F_58 ,
NULL , V_53 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_40
L_41 , V_20 ) ;
goto error;
}
V_17 -> V_109 = V_118 ;
return 0 ;
error:
F_54 ( V_17 ) ;
return V_20 ;
}
static void F_61 ( struct V_112 * V_112 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_113 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_42
L_43 ) ;
return;
}
F_27 ( V_17 , V_53 ) ;
F_62 ( V_17 -> V_34 ) ;
}
static int F_63 ( struct V_16 * V_17 )
{
struct V_130 V_131 ;
struct V_132 * V_99 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_5 ( V_17 -> V_42 , V_133 ) ;
V_131 . V_102 = 1 ;
V_131 . V_134 = 0 ;
memcpy ( F_16 ( V_17 -> V_42 ) , & V_131 ,
sizeof( struct V_130 ) ) ;
V_17 -> V_42 -> V_3 += sizeof( struct V_130 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 ) ;
if ( V_20 )
return V_20 ;
V_99 = (struct V_132 * )
F_16 ( V_17 -> V_18 ) ;
V_20 = V_99 -> V_28 & V_135 ;
if ( V_20 != V_136 )
return - V_36 ;
return 0 ;
}
static int F_64 ( struct V_112 * V_112 , T_4 V_137 ,
T_4 V_138 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_44 , V_41 ,
V_138 ) ;
if ( V_17 -> V_113 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_45
L_46 ) ;
return - V_47 ;
}
if ( V_17 -> V_128 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_47
L_48 ) ;
return - V_47 ;
}
if ( ! V_17 -> V_111 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_49
L_50 ) ;
return - V_129 ;
}
if ( ! ( V_17 -> V_111 & ( 1 << V_138 ) ) ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_51
L_52 , V_138 ) ;
return - V_129 ;
}
if ( V_138 == V_139 ) {
V_20 = F_63 ( V_17 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_53
L_54
L_55 , V_20 ) ;
return V_20 ;
}
}
V_17 -> V_128 = V_138 ;
V_17 -> V_111 = 0 ;
return 0 ;
}
static void F_65 ( struct V_112 * V_112 , T_4 V_137 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
T_1 V_102 ;
T_1 V_28 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_128 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_56 ) ;
return;
}
V_17 -> V_128 = 0 ;
F_5 ( V_17 -> V_42 , V_140 ) ;
V_102 = 1 ;
memcpy ( F_16 ( V_17 -> V_42 ) , & V_102 , sizeof( T_1 ) ) ;
V_17 -> V_42 -> V_3 += sizeof( T_1 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_57
L_58 ) ;
return;
}
V_28 = F_16 ( V_17 -> V_18 ) [ 0 ] ;
V_20 = V_28 & V_135 ;
if ( V_20 != V_136 )
F_21 ( & V_17 -> V_32 -> V_17 , L_59
L_60 , V_20 ) ;
return;
}
static int F_66 ( struct V_16 * V_17 , struct V_141 * V_142 )
{
int V_143 = V_142 -> V_121 ;
struct V_6 * V_42 ;
T_1 V_102 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_61 , V_41 ,
V_143 ) ;
if ( V_143 > V_144 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_62
L_63 ,
V_144 ) ;
return - V_145 ;
}
F_67 ( V_142 , V_146 ) ;
V_42 = (struct V_6 * ) V_142 -> V_2 ;
F_5 ( V_42 , V_147 ) ;
V_102 = 1 ;
memcpy ( F_16 ( V_42 ) , & V_102 , sizeof( T_1 ) ) ;
V_42 -> V_3 += sizeof( T_1 ) ;
V_42 -> V_3 += V_143 ;
F_8 ( V_42 ) ;
F_68 ( V_142 , V_148 ) ;
return 0 ;
}
static int F_69 ( struct V_16 * V_17 , void * V_48 ,
T_1 * V_49 , int V_50 )
{
struct V_149 * V_15 = V_48 ;
struct V_141 * V_150 = V_15 -> V_150 ;
struct V_6 * V_18 = (struct V_6 * ) V_150 -> V_2 ;
int V_151 = 0 ;
T_1 V_28 ;
T_1 V_152 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_70 ( V_15 -> V_153 ) ;
if ( V_50 < 0 ) {
V_151 = V_50 ;
goto error;
}
F_68 ( V_150 , F_29 ( V_18 ) ) ;
V_28 = V_49 [ 0 ] ;
V_152 = V_28 & V_135 ;
if ( V_152 != V_136 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_64
L_65 , V_152 ) ;
V_151 = - V_36 ;
goto error;
}
if ( V_28 & V_154 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_66
L_67 ) ;
F_27 ( V_17 , V_40 ) ;
V_151 = - V_145 ;
goto error;
}
F_71 ( V_150 , V_146 ) ;
F_72 ( V_150 , V_150 -> V_121 - V_148 ) ;
V_15 -> V_155 ( V_15 -> V_156 , V_150 , 0 ) ;
F_73 ( V_15 ) ;
return 0 ;
error:
F_70 ( V_150 ) ;
V_15 -> V_155 ( V_15 -> V_156 , NULL , V_151 ) ;
F_73 ( V_15 ) ;
return 0 ;
}
int F_74 ( struct V_112 * V_112 , T_4 V_137 ,
struct V_141 * V_142 ,
T_5 V_155 ,
void * V_156 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
struct V_6 * V_42 , * V_18 ;
struct V_149 * V_15 ;
struct V_141 * V_150 ;
int V_157 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_128 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_68
L_69 ) ;
V_20 = - V_129 ;
goto error;
}
V_20 = F_66 ( V_17 , V_142 ) ;
if ( V_20 )
goto error;
V_157 = V_146 +
V_144 +
V_148 ;
V_150 = F_75 ( V_157 , V_53 ) ;
if ( ! V_150 ) {
V_20 = - V_158 ;
goto error;
}
V_18 = (struct V_6 * ) V_150 -> V_2 ;
V_42 = (struct V_6 * ) V_142 -> V_2 ;
V_15 = F_76 ( sizeof( struct V_149 ) , V_53 ) ;
if ( ! V_15 ) {
V_20 = - V_158 ;
goto V_159;
}
V_15 -> V_150 = V_150 ;
V_15 -> V_153 = V_142 ;
V_15 -> V_155 = V_155 ;
V_15 -> V_156 = V_156 ;
V_20 = F_31 ( V_17 , V_42 , V_18 , V_157 ,
F_69 , V_15 ,
V_53 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_40
L_70 , V_20 ) ;
goto V_160;
}
return 0 ;
V_160:
F_73 ( V_15 ) ;
V_159:
F_77 ( V_150 ) ;
error:
F_77 ( V_142 ) ;
return V_20 ;
}
static int F_78 ( struct V_16 * V_17 , T_1 V_161 , T_1 * V_162 ,
T_1 V_163 )
{
int V_20 ;
T_1 * V_49 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_5 ( V_17 -> V_42 , V_164 ) ;
V_49 = F_16 ( V_17 -> V_42 ) ;
V_49 [ 0 ] = V_161 ;
memcpy ( & V_49 [ 1 ] , V_162 , V_163 ) ;
V_17 -> V_42 -> V_3 += ( 1 + V_163 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 ) ;
return V_20 ;
}
static int F_79 ( struct V_165 * V_32 ,
const struct V_166 * V_167 )
{
struct V_168 * V_169 ;
struct V_16 * V_17 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_174 V_175 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_20 = - V_158 ;
int V_5 ;
T_4 V_118 ;
V_17 = F_80 ( sizeof( * V_17 ) , V_53 ) ;
if ( ! V_17 )
return - V_158 ;
V_17 -> V_178 = F_81 ( F_82 ( V_32 ) ) ;
V_17 -> V_32 = V_32 ;
F_83 ( & V_17 -> V_25 , 1 ) ;
V_171 = V_32 -> V_179 ;
for ( V_5 = 0 ; V_5 < V_171 -> V_180 . V_181 ; ++ V_5 ) {
V_173 = & V_171 -> V_173 [ V_5 ] . V_180 ;
if ( ! V_176 && F_84 ( V_173 ) ) {
V_17 -> V_125 = F_85 ( V_173 -> V_182 ) ;
V_176 = V_173 -> V_183 ;
}
if ( ! V_177 && F_86 ( V_173 ) ) {
V_17 -> V_184 =
F_85 ( V_173 -> V_182 ) ;
V_177 = V_173 -> V_183 ;
}
}
if ( ! V_176 || ! V_177 ) {
F_21 ( & V_32 -> V_17 , L_71
L_72 ) ;
V_20 = - V_185 ;
goto error;
}
V_17 -> V_18 = F_76 ( V_17 -> V_125 , V_53 ) ;
V_17 -> V_34 = F_87 ( 0 , V_53 ) ;
V_17 -> V_42 = F_76 ( V_17 -> V_184 , V_53 ) ;
V_17 -> V_43 = F_87 ( 0 , V_53 ) ;
if ( ! V_17 -> V_18 || ! V_17 -> V_42 ||
! V_17 -> V_34 || ! V_17 -> V_43 )
goto error;
F_88 ( V_17 -> V_34 , V_17 -> V_178 ,
F_89 ( V_17 -> V_178 , V_176 ) ,
NULL , 0 , NULL , V_17 ) ;
F_88 ( V_17 -> V_43 , V_17 -> V_178 ,
F_90 ( V_17 -> V_178 , V_177 ) ,
NULL , 0 ,
F_37 , V_17 ) ;
F_91 ( & V_17 -> V_37 , F_15 , ( V_186 ) V_17 ) ;
F_92 ( V_32 , V_17 ) ;
F_5 ( V_17 -> V_42 , V_187 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 ) ;
if ( V_20 )
goto V_188;
V_169 = (struct V_168 * )
F_16 ( V_17 -> V_18 ) ;
F_93 ( & V_17 -> V_32 -> V_17 , L_73
L_74 , V_169 -> V_189 , V_169 -> V_190 ) ;
V_118 = V_89
| V_71 | V_85
| V_73
| V_75 ;
V_17 -> V_112 = F_94 ( & V_191 , V_118 ,
V_146 ,
V_148 ) ;
if ( ! V_17 -> V_112 )
goto V_188;
F_95 ( V_17 -> V_112 , & V_32 -> V_17 ) ;
F_96 ( V_17 -> V_112 , V_17 ) ;
V_20 = F_97 ( V_17 -> V_112 ) ;
if ( V_20 )
goto V_192;
V_175 . V_193 = V_194 ;
V_175 . V_195 = 2 ;
V_175 . V_196 = V_197 ;
V_20 = F_78 ( V_17 , V_198 ,
( T_1 * ) & V_175 , sizeof( V_175 ) ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_75
L_76 ) ;
goto V_192;
}
return 0 ;
V_192:
F_98 ( V_17 -> V_112 ) ;
V_188:
F_99 ( & V_17 -> V_37 ) ;
error:
F_73 ( V_17 -> V_18 ) ;
F_100 ( V_17 -> V_34 ) ;
F_73 ( V_17 -> V_42 ) ;
F_100 ( V_17 -> V_43 ) ;
F_73 ( V_17 ) ;
return V_20 ;
}
static void F_101 ( struct V_165 * V_32 )
{
struct V_16 * V_17 ;
V_17 = F_102 ( V_32 ) ;
F_92 ( V_32 , NULL ) ;
F_103 ( V_17 -> V_112 ) ;
F_98 ( V_17 -> V_112 ) ;
F_62 ( V_17 -> V_34 ) ;
F_62 ( V_17 -> V_43 ) ;
F_99 ( & V_17 -> V_37 ) ;
F_73 ( V_17 -> V_18 ) ;
F_100 ( V_17 -> V_34 ) ;
F_73 ( V_17 -> V_42 ) ;
F_100 ( V_17 -> V_43 ) ;
F_73 ( V_17 ) ;
F_93 ( & V_32 -> V_17 , L_77 ) ;
}
static int T_6 F_104 ( void )
{
int V_20 ;
V_20 = F_105 ( & V_199 ) ;
if ( V_20 )
V_151 ( L_78 , V_20 ) ;
return V_20 ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_199 ) ;
}
