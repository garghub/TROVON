static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
struct V_6 V_7 = {
. V_8 = V_9 ,
. V_10 = V_11 ,
} ;
if ( ! F_2 ( V_12 , & V_2 -> V_13 ) ||
! F_2 ( V_14 , & V_2 -> V_13 ) ||
! F_2 ( V_15 , & V_2 -> V_13 ) ||
F_2 ( V_16 , & V_2 -> V_13 ) ||
F_2 ( V_17 , & V_2 -> V_13 ) )
return - V_18 ;
V_3 = F_3 ( V_2 , & V_7 ) ;
if ( V_3 )
return V_3 ;
V_5 = (struct V_4 * ) V_7 . V_19 ;
if ( V_5 -> V_20 . V_13 != V_21 ) {
F_4 ( V_2 , L_1 , V_5 -> V_20 . V_13 ) ;
V_3 = - V_18 ;
}
F_5 ( V_2 , V_7 . V_19 ) ;
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 , bool V_22 )
{
if ( V_2 -> V_23 ) {
F_4 ( V_2 , L_2 ) ;
F_7 ( V_2 -> V_24 , V_22 ) ;
}
V_2 -> V_25 = false ;
V_2 -> V_26 = NULL ;
V_2 -> V_23 = NULL ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_27 ) ;
if ( ! F_2 ( V_28 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_3 ) ;
return;
}
F_4 ( V_2 , L_4 ) ;
F_10 ( V_28 , & V_2 -> V_13 ) ;
F_10 ( V_15 , & V_2 -> V_13 ) ;
F_10 ( V_29 , & V_2 -> V_13 ) ;
F_6 ( V_2 , true ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_3 ;
F_9 ( & V_2 -> V_27 ) ;
if ( ! F_2 ( V_28 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_5 ) ;
return;
}
if ( F_12 ( V_29 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_6 ) ;
return;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_2 , L_7 , V_3 ) ;
F_8 ( V_2 ) ;
} else
F_4 ( V_2 , L_8 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_9 ) ;
F_14 ( V_2 -> V_30 , & V_2 -> V_31 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned long V_32 )
{
unsigned long V_33 = V_34 + F_16 ( V_32 ) ;
F_9 ( & V_2 -> V_27 ) ;
F_4 ( V_2 , L_10 ) ;
F_11 ( V_2 ) ;
while ( F_17 ( V_34 , V_33 ) ) {
if ( ! F_2 ( V_15 , & V_2 -> V_13 ) )
break;
F_18 ( 20 ) ;
}
return F_2 ( V_15 , & V_2 -> V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
#ifdef F_20
struct V_4 * V_5 = F_21 ( V_36 ) ;
struct V_37 * V_38 =
(struct V_37 * ) V_5 -> V_20 . V_39 ;
F_4 ( V_2 , L_11 , V_38 -> V_13 ) ;
#endif
}
static void F_22 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = F_21 ( V_36 ) ;
struct V_40 * V_38 =
(struct V_40 * ) V_5 -> V_20 . V_39 ;
V_2 -> V_41 = F_23 ( V_38 -> V_42 ) ;
F_4 ( V_2 , L_12
L_13
L_14 ,
V_38 -> V_43 ,
V_38 -> V_44 ? L_15 : L_16 ,
F_23 ( V_38 -> V_45 ) ,
F_23 ( V_38 -> V_42 ) ,
V_38 -> V_13 , V_38 -> V_46 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
#ifdef F_20
struct V_4 * V_5 = F_21 ( V_36 ) ;
struct V_47 * V_38 =
(struct V_47 * ) V_5 -> V_20 . V_39 ;
F_4 ( V_2 , L_17
L_13
L_18
L_19 ,
V_38 -> V_43 ,
V_38 -> V_44 ? L_15 : L_16 ,
F_23 ( V_38 -> V_45 ) ,
F_23 ( V_38 -> V_42 ) ,
F_23 ( V_38 -> V_48 [ 0 ] ) ,
F_23 ( V_38 -> V_42 ) - V_2 -> V_41 ) ;
#endif
}
static void F_25 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
#ifdef F_20
struct V_4 * V_5 = F_21 ( V_36 ) ;
struct V_49 * V_50 = ( void * ) V_5 -> V_20 . V_39 ;
#endif
F_4 ( V_2 ,
L_20 ,
V_50 -> V_51 ,
V_50 -> V_42 ,
V_50 -> V_45 , V_50 -> V_13 ) ;
F_10 ( V_15 , & V_2 -> V_13 ) ;
F_4 ( V_2 , L_21 ,
( V_2 -> V_52 == V_53 ) ? L_22 : L_23 ,
F_26 ( V_34 - V_2 -> V_54 ) ) ;
F_14 ( V_2 -> V_30 , & V_2 -> V_55 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_56 [ V_57 ] = F_19 ;
V_2 -> V_56 [ V_58 ] =
F_22 ;
V_2 -> V_56 [ V_59 ] =
F_24 ;
V_2 -> V_56 [ V_60 ] =
F_25 ;
}
inline T_1 F_28 ( struct V_1 * V_2 ,
enum V_61 V_44 ,
T_2 V_62 )
{
if ( V_44 == V_63 )
return V_64 +
V_65 * ( V_62 + 1 ) ;
else
return V_66 +
V_67 * ( V_62 + 1 ) ;
}
T_1 F_29 ( struct V_1 * V_2 ,
enum V_61 V_44 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 ;
T_1 V_72 = ( V_44 == V_53 ) ?
V_73 + V_74 :
V_73 + V_75 ;
if ( F_30 ( V_2 ) ) {
F_31 (priv, ctx) {
T_1 V_76 ;
if ( ! F_32 ( V_71 ) )
continue;
V_76 = V_71 -> V_69 ? V_71 -> V_69 -> V_77 . V_78 : 0 ;
if ( ( V_76 > V_73 ) || ! V_76 )
V_76 = V_73 ;
V_76 = ( V_76 * 98 ) / 100 - V_79 * 2 ;
V_72 = F_33 ( V_76 , V_72 ) ;
}
}
return V_72 ;
}
void F_34 ( struct V_1 * V_2 )
{
T_2 V_80 = F_35 ( V_2 -> V_81 . V_82 ) - 1 ;
if ( ! V_2 -> V_83 [ V_63 ] )
V_2 -> V_83 [ V_63 ] = V_80 ;
if ( ! V_2 -> V_83 [ V_53 ] )
V_2 -> V_83 [ V_53 ] = V_80 ;
}
static int T_3 F_36 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
bool V_84 ,
enum V_61 V_44 )
{
int V_3 ;
F_9 ( & V_2 -> V_27 ) ;
if ( F_37 ( ! V_2 -> V_85 -> V_86 -> V_87 -> V_88 ) )
return - V_89 ;
F_38 ( & V_2 -> V_90 ) ;
if ( ! F_39 ( V_2 ) ) {
F_40 ( V_2 , L_24 ) ;
return - V_18 ;
}
if ( F_2 ( V_15 , & V_2 -> V_13 ) ) {
F_4 ( V_2 ,
L_25 ) ;
return - V_91 ;
}
if ( F_2 ( V_29 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_26 ) ;
return - V_91 ;
}
F_4 ( V_2 , L_27 ,
V_84 ? L_28 : L_29 ) ;
F_41 ( V_28 , & V_2 -> V_13 ) ;
V_2 -> V_25 = V_84 ;
V_2 -> V_54 = V_34 ;
V_2 -> V_52 = V_44 ;
V_3 = V_2 -> V_85 -> V_86 -> V_87 -> V_88 ( V_2 , V_69 ) ;
if ( V_3 ) {
F_10 ( V_28 , & V_2 -> V_13 ) ;
V_2 -> V_25 = false ;
return V_3 ;
}
F_42 ( V_2 -> V_30 , & V_2 -> V_90 ,
V_92 ) ;
return 0 ;
}
int F_43 ( struct V_93 * V_24 ,
struct V_68 * V_69 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_3 ;
F_44 ( V_2 , L_30 ) ;
if ( V_95 -> V_96 == 0 )
return - V_97 ;
F_45 ( & V_2 -> V_27 ) ;
if ( F_2 ( V_28 , & V_2 -> V_13 ) &&
! V_2 -> V_25 ) {
F_4 ( V_2 , L_31 ) ;
V_3 = - V_98 ;
goto V_99;
}
V_2 -> V_23 = V_95 ;
V_2 -> V_26 = V_69 ;
if ( V_2 -> V_25 ) {
F_4 ( V_2 , L_32 ) ;
V_3 = 0 ;
} else
V_3 = F_36 ( V_2 , V_69 , false ,
V_95 -> V_100 [ 0 ] -> V_44 ) ;
F_44 ( V_2 , L_33 ) ;
V_99:
F_46 ( & V_2 -> V_27 ) ;
return V_3 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_30 , & V_2 -> V_101 ) ;
}
static void F_48 ( struct V_102 * V_103 )
{
struct V_1 * V_2 =
F_49 ( V_103 , struct V_1 , V_101 ) ;
F_4 ( V_2 , L_34 ) ;
F_45 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_25 == true ) {
F_4 ( V_2 , L_35 ) ;
goto V_104;
}
if ( F_2 ( V_28 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_31 ) ;
goto V_104;
}
if ( F_36 ( V_2 , NULL , true , V_2 -> V_44 ) )
F_4 ( V_2 , L_36 ) ;
V_104:
F_46 ( & V_2 -> V_27 ) ;
}
static void F_50 ( struct V_102 * V_105 )
{
struct V_1 * V_2 =
F_49 ( V_105 , struct V_1 , V_90 . V_103 ) ;
F_4 ( V_2 , L_37 ) ;
F_45 ( & V_2 -> V_27 ) ;
F_8 ( V_2 ) ;
F_46 ( & V_2 -> V_27 ) ;
}
T_1
F_51 ( struct V_1 * V_2 , struct V_106 * V_107 ,
const T_2 * V_108 , const T_2 * V_109 , int V_110 , int V_111 )
{
int V_112 = 0 ;
T_2 * V_113 = NULL ;
V_111 -= 24 ;
if ( V_111 < 0 )
return 0 ;
V_107 -> V_114 = F_52 ( V_115 ) ;
memcpy ( V_107 -> V_116 , V_117 , V_118 ) ;
memcpy ( V_107 -> V_119 , V_108 , V_118 ) ;
memcpy ( V_107 -> V_120 , V_117 , V_118 ) ;
V_107 -> V_121 = 0 ;
V_112 += 24 ;
V_113 = & V_107 -> V_20 . V_122 . V_123 [ 0 ] ;
V_111 -= 2 ;
if ( V_111 < 0 )
return 0 ;
* V_113 ++ = V_124 ;
* V_113 ++ = 0 ;
V_112 += 2 ;
if ( F_37 ( V_111 < V_110 ) )
return V_112 ;
if ( V_109 && V_110 ) {
memcpy ( V_113 , V_109 , V_110 ) ;
V_112 += V_110 ;
}
return ( T_1 ) V_112 ;
}
static void F_53 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_49 ( V_103 , struct V_1 , V_31 ) ;
F_4 ( V_2 , L_38 ) ;
F_45 ( & V_2 -> V_27 ) ;
F_15 ( V_2 , 200 ) ;
F_46 ( & V_2 -> V_27 ) ;
}
static void F_54 ( struct V_102 * V_103 )
{
struct V_1 * V_2 =
F_49 ( V_103 , struct V_1 , V_55 ) ;
bool V_22 ;
F_4 ( V_2 , L_39 ,
V_2 -> V_25 ? L_28 : L_29 ) ;
F_38 ( & V_2 -> V_90 ) ;
F_45 ( & V_2 -> V_27 ) ;
V_22 = F_55 ( V_29 , & V_2 -> V_13 ) ;
if ( V_22 )
F_4 ( V_2 , L_40 ) ;
if ( ! F_55 ( V_28 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_41 ) ;
goto V_125;
}
if ( V_2 -> V_25 && ! V_22 ) {
int V_126 ;
if ( V_2 -> V_23 == NULL )
goto V_127;
V_126 = F_36 ( V_2 , V_2 -> V_26 , false ,
V_2 -> V_23 -> V_100 [ 0 ] -> V_44 ) ;
if ( V_126 ) {
F_4 ( V_2 ,
L_42 , V_126 ) ;
V_22 = true ;
goto V_127;
}
goto V_128;
}
V_127:
F_6 ( V_2 , V_22 ) ;
V_125:
if ( ! F_39 ( V_2 ) )
goto V_128;
F_56 ( V_2 , & V_2 -> V_129 . V_130 ,
false ) ;
F_57 ( V_2 , V_2 -> V_131 , false ) ;
V_2 -> V_85 -> V_86 -> V_87 -> V_132 ( V_2 ) ;
V_128:
F_46 ( & V_2 -> V_27 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_55 , F_54 ) ;
F_59 ( & V_2 -> V_31 , F_53 ) ;
F_59 ( & V_2 -> V_101 ,
F_48 ) ;
F_60 ( & V_2 -> V_90 , F_50 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_62 ( & V_2 -> V_101 ) ;
F_62 ( & V_2 -> V_31 ) ;
F_62 ( & V_2 -> V_55 ) ;
if ( F_63 ( & V_2 -> V_90 ) ) {
F_45 ( & V_2 -> V_27 ) ;
F_8 ( V_2 ) ;
F_46 ( & V_2 -> V_27 ) ;
}
}
