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
T_5 V_133 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_5 ( V_17 -> V_42 , V_134 ) ;
V_131 . V_102 = 1 ;
V_131 . V_135 = 0 ;
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
V_20 = V_99 -> V_28 & V_136 ;
if ( V_20 != V_137 )
return - V_36 ;
V_133 = F_17 ( V_17 -> V_18 ) - 16 ;
V_20 = F_64 ( V_17 -> V_112 , V_99 -> V_138 , V_133 ) ;
return V_20 ;
}
static int F_65 ( struct V_112 * V_112 , T_4 V_139 ,
T_4 V_140 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_44 , V_41 ,
V_140 ) ;
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
if ( ! ( V_17 -> V_111 & ( 1 << V_140 ) ) ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_51
L_52 , V_140 ) ;
return - V_129 ;
}
if ( V_140 == V_141 ) {
V_20 = F_63 ( V_17 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_53
L_54
L_55 , V_20 ) ;
return V_20 ;
}
}
V_17 -> V_128 = V_140 ;
V_17 -> V_111 = 0 ;
return 0 ;
}
static void F_66 ( struct V_112 * V_112 , T_4 V_139 )
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
F_5 ( V_17 -> V_42 , V_142 ) ;
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
V_20 = V_28 & V_136 ;
if ( V_20 != V_137 )
F_21 ( & V_17 -> V_32 -> V_17 , L_59
L_60 , V_20 ) ;
return;
}
static int F_67 ( struct V_16 * V_17 , void * V_15 ,
T_1 * V_49 , int V_50 )
{
struct V_143 * V_12 ;
struct V_144 * V_99 ;
struct V_63 V_63 ;
T_1 V_145 ;
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
if ( V_17 -> V_111 &&
! ( V_17 -> V_111 & ( 1 << V_141 ) ) ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_63 ) ;
return - V_129 ;
}
V_99 = (struct V_144 * ) V_49 ;
V_12 = (struct V_143 * ) V_15 ;
V_20 = V_99 -> V_28 & V_136 ;
if ( V_20 != V_137 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_64 , V_20 ) ;
return 0 ;
}
if ( ! V_17 -> V_111 ) {
F_20 ( & V_17 -> V_32 -> V_17 , L_65 ) ;
V_63 . V_70 = V_75 ;
V_20 = F_53 ( V_17 -> V_112 , & V_63 , 1 ) ;
if ( V_20 )
return 0 ;
V_17 -> V_111 = 0 ;
}
V_17 -> V_128 = V_141 ;
V_145 = F_17 ( V_17 -> V_18 ) - 17 ;
V_20 = F_64 ( V_17 -> V_112 ,
V_99 -> V_138 , V_145 ) ;
if ( V_20 == 0 )
V_20 = F_68 ( V_17 -> V_112 ,
V_17 -> V_112 -> V_146 [ 0 ] . V_147 ,
! V_12 -> V_148 , V_149 ) ;
return 0 ;
}
static int F_69 ( struct V_112 * V_112 , int V_139 ,
T_1 V_150 , T_1 V_151 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
struct V_143 * V_12 ;
T_1 V_152 , V_153 , * V_154 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( V_151 == V_155 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_66 ) ;
return - V_156 ;
}
if ( V_17 -> V_113 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_67 ) ;
return - V_47 ;
}
if ( V_17 -> V_128 ) {
F_21 ( & V_17 -> V_32 -> V_17 ,
L_68 ) ;
return - V_47 ;
}
V_154 = F_70 ( V_17 -> V_112 , & V_153 ) ;
if ( V_153 > V_157 )
return - V_129 ;
V_152 = sizeof( struct V_143 ) + V_153 ;
V_12 = F_71 ( V_152 , V_53 ) ;
if ( V_12 == NULL )
return - V_158 ;
F_5 ( V_17 -> V_42 , V_159 ) ;
V_12 -> V_148 = ! V_150 ;
V_12 -> V_160 = 0 ;
if ( V_154 != NULL ) {
V_12 -> V_135 = 4 ;
memcpy ( V_12 -> V_138 , V_154 , V_153 ) ;
} else {
V_12 -> V_135 = 0 ;
}
memcpy ( F_16 ( V_17 -> V_42 ) , V_12 , V_152 ) ;
V_17 -> V_42 -> V_3 += V_152 ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_31 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 , F_67 ,
V_12 , V_53 ) ;
if ( V_20 )
goto V_161;
V_161:
F_72 ( V_12 ) ;
return V_20 ;
}
static int F_73 ( struct V_112 * V_112 )
{
F_66 ( V_112 , 0 ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_17 , struct V_162 * V_163 )
{
int V_164 = V_163 -> V_121 ;
struct V_6 * V_42 ;
T_1 V_102 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_69 , V_41 ,
V_164 ) ;
if ( V_164 > V_165 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_70
L_71 ,
V_165 ) ;
return - V_166 ;
}
F_75 ( V_163 , V_167 ) ;
V_42 = (struct V_6 * ) V_163 -> V_2 ;
F_5 ( V_42 , V_168 ) ;
V_102 = 1 ;
memcpy ( F_16 ( V_42 ) , & V_102 , sizeof( T_1 ) ) ;
V_42 -> V_3 += sizeof( T_1 ) ;
V_42 -> V_3 += V_164 ;
F_8 ( V_42 ) ;
F_76 ( V_163 , V_169 ) ;
return 0 ;
}
static int F_77 ( struct V_16 * V_17 , void * V_48 ,
T_1 * V_49 , int V_50 )
{
struct V_170 * V_15 = V_48 ;
struct V_162 * V_171 = V_15 -> V_171 ;
struct V_6 * V_18 = (struct V_6 * ) V_171 -> V_2 ;
int V_172 = 0 ;
T_1 V_28 ;
T_1 V_173 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_78 ( V_15 -> V_174 ) ;
if ( V_50 < 0 ) {
V_172 = V_50 ;
goto error;
}
F_76 ( V_171 , F_29 ( V_18 ) ) ;
V_28 = V_49 [ 0 ] ;
V_173 = V_28 & V_136 ;
if ( V_173 != V_137 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_72
L_73 , V_173 ) ;
V_172 = - V_36 ;
goto error;
}
if ( V_28 & V_175 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_74
L_75 ) ;
F_27 ( V_17 , V_40 ) ;
V_172 = - V_166 ;
goto error;
}
F_79 ( V_171 , V_167 ) ;
F_80 ( V_171 , V_171 -> V_121 - V_169 ) ;
V_15 -> V_176 ( V_15 -> V_177 , V_171 , 0 ) ;
F_72 ( V_15 ) ;
return 0 ;
error:
F_78 ( V_171 ) ;
V_15 -> V_176 ( V_15 -> V_177 , NULL , V_172 ) ;
F_72 ( V_15 ) ;
return 0 ;
}
static int F_81 ( struct V_112 * V_112 , T_4 V_139 ,
struct V_162 * V_163 ,
T_6 V_176 ,
void * V_177 )
{
struct V_16 * V_17 = F_60 ( V_112 ) ;
struct V_6 * V_42 , * V_18 ;
struct V_170 * V_15 ;
struct V_162 * V_171 ;
int V_178 ;
int V_20 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
if ( ! V_17 -> V_128 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_76
L_77 ) ;
V_20 = - V_129 ;
goto error;
}
V_20 = F_74 ( V_17 , V_163 ) ;
if ( V_20 )
goto error;
V_178 = V_167 +
V_165 +
V_169 ;
V_171 = F_82 ( V_178 , V_53 ) ;
if ( ! V_171 ) {
V_20 = - V_158 ;
goto error;
}
V_18 = (struct V_6 * ) V_171 -> V_2 ;
V_42 = (struct V_6 * ) V_163 -> V_2 ;
V_15 = F_83 ( sizeof( struct V_170 ) , V_53 ) ;
if ( ! V_15 ) {
V_20 = - V_158 ;
goto V_179;
}
V_15 -> V_171 = V_171 ;
V_15 -> V_174 = V_163 ;
V_15 -> V_176 = V_176 ;
V_15 -> V_177 = V_177 ;
V_20 = F_31 ( V_17 , V_42 , V_18 , V_178 ,
F_77 , V_15 ,
V_53 ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_40
L_78 , V_20 ) ;
goto V_180;
}
return 0 ;
V_180:
F_72 ( V_15 ) ;
V_179:
F_84 ( V_171 ) ;
error:
F_84 ( V_163 ) ;
return V_20 ;
}
static int F_85 ( struct V_16 * V_17 , T_1 V_181 , T_1 * V_182 ,
T_1 V_183 )
{
int V_20 ;
T_1 * V_49 ;
F_20 ( & V_17 -> V_32 -> V_17 , L_13 , V_41 ) ;
F_5 ( V_17 -> V_42 , V_184 ) ;
V_49 = F_16 ( V_17 -> V_42 ) ;
V_49 [ 0 ] = V_181 ;
memcpy ( & V_49 [ 1 ] , V_182 , V_183 ) ;
V_17 -> V_42 -> V_3 += ( 1 + V_183 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 ) ;
return V_20 ;
}
static int F_86 ( struct V_185 * V_32 ,
const struct V_186 * V_187 )
{
struct V_188 * V_189 ;
struct V_16 * V_17 ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
struct V_194 V_195 ;
int V_196 = 0 ;
int V_197 = 0 ;
int V_20 = - V_158 ;
int V_5 ;
T_4 V_118 ;
V_17 = F_71 ( sizeof( * V_17 ) , V_53 ) ;
if ( ! V_17 )
return - V_158 ;
V_17 -> V_198 = F_87 ( F_88 ( V_32 ) ) ;
V_17 -> V_32 = V_32 ;
F_89 ( & V_17 -> V_25 , 1 ) ;
V_191 = V_32 -> V_199 ;
for ( V_5 = 0 ; V_5 < V_191 -> V_200 . V_201 ; ++ V_5 ) {
V_193 = & V_191 -> V_193 [ V_5 ] . V_200 ;
if ( ! V_196 && F_90 ( V_193 ) ) {
V_17 -> V_125 = F_91 ( V_193 -> V_202 ) ;
V_196 = V_193 -> V_203 ;
}
if ( ! V_197 && F_92 ( V_193 ) ) {
V_17 -> V_204 =
F_91 ( V_193 -> V_202 ) ;
V_197 = V_193 -> V_203 ;
}
}
if ( ! V_196 || ! V_197 ) {
F_21 ( & V_32 -> V_17 , L_79
L_80 ) ;
V_20 = - V_205 ;
goto error;
}
V_17 -> V_18 = F_83 ( V_17 -> V_125 , V_53 ) ;
V_17 -> V_34 = F_93 ( 0 , V_53 ) ;
V_17 -> V_42 = F_83 ( V_17 -> V_204 , V_53 ) ;
V_17 -> V_43 = F_93 ( 0 , V_53 ) ;
if ( ! V_17 -> V_18 || ! V_17 -> V_42 ||
! V_17 -> V_34 || ! V_17 -> V_43 )
goto error;
F_94 ( V_17 -> V_34 , V_17 -> V_198 ,
F_95 ( V_17 -> V_198 , V_196 ) ,
NULL , 0 , NULL , V_17 ) ;
F_94 ( V_17 -> V_43 , V_17 -> V_198 ,
F_96 ( V_17 -> V_198 , V_197 ) ,
NULL , 0 ,
F_37 , V_17 ) ;
F_97 ( & V_17 -> V_37 , F_15 , ( V_206 ) V_17 ) ;
F_98 ( V_32 , V_17 ) ;
F_5 ( V_17 -> V_42 , V_207 ) ;
F_8 ( V_17 -> V_42 ) ;
V_20 = F_34 ( V_17 , V_17 -> V_42 , V_17 -> V_18 ,
V_17 -> V_125 ) ;
if ( V_20 )
goto V_208;
V_189 = (struct V_188 * )
F_16 ( V_17 -> V_18 ) ;
F_99 ( & V_17 -> V_32 -> V_17 , L_81
L_82 , V_189 -> V_209 , V_189 -> V_210 ) ;
V_118 = V_89
| V_71 | V_85
| V_73
| V_75 ;
V_17 -> V_112 = F_100 ( & V_211 , V_118 ,
V_167 ,
V_169 ) ;
if ( ! V_17 -> V_112 )
goto V_208;
F_101 ( V_17 -> V_112 , & V_32 -> V_17 ) ;
F_102 ( V_17 -> V_112 , V_17 ) ;
V_20 = F_103 ( V_17 -> V_112 ) ;
if ( V_20 )
goto V_212;
V_195 . V_213 = V_214 ;
V_195 . V_215 = 2 ;
V_195 . V_216 = V_217 ;
V_20 = F_85 ( V_17 , V_218 ,
( T_1 * ) & V_195 , sizeof( V_195 ) ) ;
if ( V_20 ) {
F_21 ( & V_17 -> V_32 -> V_17 , L_83
L_84 ) ;
goto V_212;
}
return 0 ;
V_212:
F_104 ( V_17 -> V_112 ) ;
V_208:
F_105 ( & V_17 -> V_37 ) ;
error:
F_72 ( V_17 -> V_18 ) ;
F_106 ( V_17 -> V_34 ) ;
F_72 ( V_17 -> V_42 ) ;
F_106 ( V_17 -> V_43 ) ;
F_72 ( V_17 ) ;
return V_20 ;
}
static void F_107 ( struct V_185 * V_32 )
{
struct V_16 * V_17 ;
V_17 = F_108 ( V_32 ) ;
F_98 ( V_32 , NULL ) ;
F_109 ( V_17 -> V_112 ) ;
F_104 ( V_17 -> V_112 ) ;
F_62 ( V_17 -> V_34 ) ;
F_62 ( V_17 -> V_43 ) ;
F_105 ( & V_17 -> V_37 ) ;
F_72 ( V_17 -> V_18 ) ;
F_106 ( V_17 -> V_34 ) ;
F_72 ( V_17 -> V_42 ) ;
F_106 ( V_17 -> V_43 ) ;
F_72 ( V_17 ) ;
F_99 ( & V_32 -> V_17 , L_85 ) ;
}
