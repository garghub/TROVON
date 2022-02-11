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
V_2 -> V_25 = NULL ;
V_2 -> V_23 = NULL ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_26 ) ;
if ( ! F_2 ( V_27 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_3 ) ;
return;
}
F_4 ( V_2 , L_4 ) ;
F_10 ( V_27 , & V_2 -> V_13 ) ;
F_10 ( V_15 , & V_2 -> V_13 ) ;
F_10 ( V_28 , & V_2 -> V_13 ) ;
F_6 ( V_2 , true ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_3 ;
F_9 ( & V_2 -> V_26 ) ;
if ( ! F_2 ( V_27 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_5 ) ;
return;
}
if ( F_12 ( V_28 , & V_2 -> V_13 ) ) {
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
F_14 ( V_2 -> V_29 , & V_2 -> V_30 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned long V_31 )
{
unsigned long V_32 = V_33 + F_16 ( V_31 ) ;
F_9 ( & V_2 -> V_26 ) ;
F_4 ( V_2 , L_10 ) ;
F_11 ( V_2 ) ;
while ( F_17 ( V_33 , V_32 ) ) {
if ( ! F_2 ( V_15 , & V_2 -> V_13 ) )
break;
F_18 ( 20 ) ;
}
return F_2 ( V_15 , & V_2 -> V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
#ifdef F_20
struct V_4 * V_5 = F_21 ( V_35 ) ;
struct V_36 * V_37 =
(struct V_36 * ) V_5 -> V_20 . V_38 ;
F_4 ( V_2 , L_11 , V_37 -> V_13 ) ;
#endif
}
static void F_22 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_4 * V_5 = F_21 ( V_35 ) ;
struct V_39 * V_37 =
(struct V_39 * ) V_5 -> V_20 . V_38 ;
V_2 -> V_40 = F_23 ( V_37 -> V_41 ) ;
F_4 ( V_2 , L_12
L_13
L_14 ,
V_37 -> V_42 ,
V_37 -> V_43 ? L_15 : L_16 ,
F_23 ( V_37 -> V_44 ) ,
F_23 ( V_37 -> V_41 ) ,
V_37 -> V_13 , V_37 -> V_45 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
#ifdef F_20
struct V_4 * V_5 = F_21 ( V_35 ) ;
struct V_46 * V_37 =
(struct V_46 * ) V_5 -> V_20 . V_38 ;
F_4 ( V_2 , L_17
L_13
L_18
L_19 ,
V_37 -> V_42 ,
V_37 -> V_43 ? L_15 : L_16 ,
F_23 ( V_37 -> V_44 ) ,
F_23 ( V_37 -> V_41 ) ,
F_23 ( V_37 -> V_47 [ 0 ] ) ,
F_23 ( V_37 -> V_41 ) - V_2 -> V_40 ) ;
#endif
}
static void F_25 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
#ifdef F_20
struct V_4 * V_5 = F_21 ( V_35 ) ;
struct V_48 * V_49 = ( void * ) V_5 -> V_20 . V_38 ;
#endif
F_4 ( V_2 ,
L_20 ,
V_49 -> V_50 ,
V_49 -> V_41 ,
V_49 -> V_44 , V_49 -> V_13 ) ;
F_10 ( V_15 , & V_2 -> V_13 ) ;
F_4 ( V_2 , L_21 ,
( V_2 -> V_51 == V_52 ) ? L_22 : L_23 ,
F_26 ( V_33 - V_2 -> V_53 ) ) ;
F_14 ( V_2 -> V_29 , & V_2 -> V_54 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_55 [ V_56 ] = F_19 ;
V_2 -> V_55 [ V_57 ] =
F_22 ;
V_2 -> V_55 [ V_58 ] =
F_24 ;
V_2 -> V_55 [ V_59 ] =
F_25 ;
}
inline T_1 F_28 ( struct V_1 * V_2 ,
enum V_60 V_43 ,
T_2 V_61 )
{
if ( V_43 == V_62 )
return V_63 +
V_64 * ( V_61 + 1 ) ;
else
return V_65 +
V_66 * ( V_61 + 1 ) ;
}
T_1 F_29 ( struct V_1 * V_2 ,
enum V_60 V_43 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
T_1 V_71 = ( V_43 == V_52 ) ?
V_72 + V_73 :
V_72 + V_74 ;
if ( F_30 ( V_2 ) ) {
F_31 (priv, ctx) {
T_1 V_75 ;
if ( ! F_32 ( V_70 ) )
continue;
V_75 = V_70 -> V_68 ? V_70 -> V_68 -> V_76 . V_77 : 0 ;
if ( ( V_75 > V_72 ) || ! V_75 )
V_75 = V_72 ;
V_75 = ( V_75 * 98 ) / 100 - V_78 * 2 ;
V_71 = F_33 ( V_75 , V_71 ) ;
}
}
return V_71 ;
}
void F_34 ( struct V_1 * V_2 )
{
T_2 V_79 = F_35 ( V_2 -> V_80 . V_81 ) - 1 ;
if ( ! V_2 -> V_82 [ V_62 ] )
V_2 -> V_82 [ V_62 ] = V_79 ;
if ( ! V_2 -> V_82 [ V_52 ] )
V_2 -> V_82 [ V_52 ] = V_79 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
int V_3 ;
F_9 ( & V_2 -> V_26 ) ;
if ( F_37 ( ! V_2 -> V_83 -> V_84 -> V_85 -> V_86 ) )
return - V_87 ;
F_38 ( & V_2 -> V_88 ) ;
if ( ! F_39 ( V_2 ) ) {
F_40 ( V_2 , L_24 ) ;
return - V_18 ;
}
if ( F_2 ( V_15 , & V_2 -> V_13 ) ) {
F_4 ( V_2 ,
L_25 ) ;
return - V_89 ;
}
if ( F_2 ( V_28 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_26 ) ;
return - V_89 ;
}
F_4 ( V_2 , L_27 ) ;
F_41 ( V_27 , & V_2 -> V_13 ) ;
V_2 -> V_53 = V_33 ;
V_3 = V_2 -> V_83 -> V_84 -> V_85 -> V_86 ( V_2 , V_68 ) ;
if ( V_3 ) {
F_10 ( V_27 , & V_2 -> V_13 ) ;
return V_3 ;
}
F_42 ( V_2 -> V_29 , & V_2 -> V_88 ,
V_90 ) ;
return 0 ;
}
int F_43 ( struct V_91 * V_24 ,
struct V_67 * V_68 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_3 ;
F_44 ( V_2 , L_28 ) ;
if ( V_93 -> V_94 == 0 )
return - V_95 ;
F_45 ( & V_2 -> V_26 ) ;
if ( F_2 ( V_27 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_29 ) ;
V_3 = - V_96 ;
goto V_97;
}
V_2 -> V_23 = V_93 ;
V_2 -> V_25 = V_68 ;
V_2 -> V_51 = V_93 -> V_98 [ 0 ] -> V_43 ;
V_3 = F_36 ( V_2 , V_68 ) ;
F_44 ( V_2 , L_30 ) ;
V_97:
F_46 ( & V_2 -> V_26 ) ;
return V_3 ;
}
static void F_47 ( struct V_99 * V_100 )
{
struct V_1 * V_2 =
F_48 ( V_100 , struct V_1 , V_88 . V_101 ) ;
F_4 ( V_2 , L_31 ) ;
F_45 ( & V_2 -> V_26 ) ;
F_8 ( V_2 ) ;
F_46 ( & V_2 -> V_26 ) ;
}
T_1
F_49 ( struct V_1 * V_2 , struct V_102 * V_103 ,
const T_2 * V_104 , const T_2 * V_105 , int V_106 , int V_107 )
{
int V_108 = 0 ;
T_2 * V_109 = NULL ;
V_107 -= 24 ;
if ( V_107 < 0 )
return 0 ;
V_103 -> V_110 = F_50 ( V_111 ) ;
memcpy ( V_103 -> V_112 , V_113 , V_114 ) ;
memcpy ( V_103 -> V_115 , V_104 , V_114 ) ;
memcpy ( V_103 -> V_116 , V_113 , V_114 ) ;
V_103 -> V_117 = 0 ;
V_108 += 24 ;
V_109 = & V_103 -> V_20 . V_118 . V_119 [ 0 ] ;
V_107 -= 2 ;
if ( V_107 < 0 )
return 0 ;
* V_109 ++ = V_120 ;
* V_109 ++ = 0 ;
V_108 += 2 ;
if ( F_37 ( V_107 < V_106 ) )
return V_108 ;
if ( V_105 && V_106 ) {
memcpy ( V_109 , V_105 , V_106 ) ;
V_108 += V_106 ;
}
return ( T_1 ) V_108 ;
}
static void F_51 ( struct V_99 * V_101 )
{
struct V_1 * V_2 = F_48 ( V_101 , struct V_1 , V_30 ) ;
F_4 ( V_2 , L_32 ) ;
F_45 ( & V_2 -> V_26 ) ;
F_15 ( V_2 , 200 ) ;
F_46 ( & V_2 -> V_26 ) ;
}
static void F_52 ( struct V_99 * V_101 )
{
struct V_1 * V_2 =
F_48 ( V_101 , struct V_1 , V_54 ) ;
bool V_22 ;
F_4 ( V_2 , L_33 ) ;
F_38 ( & V_2 -> V_88 ) ;
F_45 ( & V_2 -> V_26 ) ;
V_22 = F_53 ( V_28 , & V_2 -> V_13 ) ;
if ( V_22 )
F_4 ( V_2 , L_34 ) ;
if ( ! F_53 ( V_27 , & V_2 -> V_13 ) ) {
F_4 ( V_2 , L_35 ) ;
goto V_121;
}
F_6 ( V_2 , V_22 ) ;
V_121:
if ( ! F_39 ( V_2 ) )
goto V_122;
F_54 ( V_2 , & V_2 -> V_123 . V_124 , false ) ;
F_55 ( V_2 , V_2 -> V_125 , false ) ;
V_2 -> V_83 -> V_84 -> V_85 -> V_126 ( V_2 ) ;
V_122:
F_46 ( & V_2 -> V_26 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_54 , F_52 ) ;
F_57 ( & V_2 -> V_30 , F_51 ) ;
F_58 ( & V_2 -> V_88 , F_47 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_30 ) ;
F_60 ( & V_2 -> V_54 ) ;
if ( F_61 ( & V_2 -> V_88 ) ) {
F_45 ( & V_2 -> V_26 ) ;
F_8 ( V_2 ) ;
F_46 ( & V_2 -> V_26 ) ;
}
}
