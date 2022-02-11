void F_1 ( T_1 * V_1 ,
struct V_2 * V_3 , unsigned long V_4 ,
T_2 V_5 )
{
V_1 -> V_6 . V_7 = ( ( V_4 - V_3 -> V_8 ) & V_9 ) +
( V_3 -> V_10 << V_11 ) ;
V_1 -> V_6 . V_12 = ( V_1 -> V_6 . V_7 + V_5 - 1 ) |
~ V_9 ;
}
struct V_2 * F_2 ( struct V_13 * V_14 , unsigned long V_4 ,
T_2 V_5 )
{
struct V_2 * V_3 , * V_15 = NULL ;
V_16 ;
F_3 ( ! F_4 ( & V_14 -> V_17 ) ) ;
for( V_3 = F_5 ( V_14 , V_4 ) ;
V_3 != NULL && V_3 -> V_8 < ( V_4 + V_5 ) ; V_3 = V_3 -> V_18 ) {
if ( V_3 -> V_19 && V_3 -> V_19 == & V_20 &&
V_3 -> V_21 & V_22 ) {
V_15 = V_3 ;
break;
}
}
RETURN ( V_15 ) ;
}
struct V_23 * F_6 ( struct V_2 * V_3 ,
struct V_24 * * V_25 ,
struct V_26 * V_27 ,
T_3 V_28 , unsigned long * V_29 )
{
struct V_30 * V_30 = V_3 -> V_31 ;
struct V_32 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_23 * V_35 ;
struct V_36 * V_37 ;
struct V_24 * V_38 ;
V_16 ;
* V_25 = NULL ;
if ( F_7 ( V_30 ) )
RETURN ( F_8 ( - V_39 ) ) ;
V_38 = F_9 ( V_27 ) ;
if ( F_10 ( V_38 ) )
RETURN ( F_8 ( - V_40 ) ) ;
* V_25 = V_38 ;
V_35 = F_11 ( V_38 ) ;
V_35 -> V_41 = F_12 ( V_32 ) -> V_42 ;
F_3 ( V_35 -> V_41 != NULL ) ;
V_37 = & V_35 -> V_43 . V_44 ;
V_37 -> V_45 = V_28 ;
V_37 -> V_46 = V_3 -> V_21 & V_47 ;
if ( V_29 != NULL )
* V_29 = V_3 -> V_21 & ( V_48 | V_49 ) ;
V_3 -> V_21 &= ~ V_49 ;
V_3 -> V_21 |= V_48 ;
F_13 ( V_50 , L_1 , V_3 -> V_21 ,
V_37 -> V_45 , V_37 -> V_46 ) ;
if ( F_14 ( V_38 , V_35 , V_51 , V_35 -> V_41 ) == 0 ) {
struct V_52 * V_53 = F_15 ( V_38 ) ;
struct V_54 * V_55 = F_16 ( V_30 ) ;
F_3 ( V_53 -> V_56 . V_57 == V_35 ) ;
V_35 -> V_58 = V_59 ;
V_53 -> V_60 = V_55 ;
}
return V_35 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_61 * V_62 ,
bool * V_63 )
{
struct V_24 * V_38 ;
struct V_23 * V_35 ;
struct V_64 * V_65 ;
struct V_26 V_27 ;
int V_66 ;
T_4 V_67 ;
struct V_32 * V_32 ;
struct V_68 * V_69 ;
V_16 ;
F_3 ( V_62 != NULL ) ;
V_35 = F_6 ( V_3 , & V_38 , & V_27 , V_62 -> V_28 , NULL ) ;
if ( F_10 ( V_35 ) )
GOTO ( V_70 , V_66 = F_18 ( V_35 ) ) ;
V_66 = V_35 -> V_71 ;
if ( V_66 < 0 )
GOTO ( V_70 , V_66 ) ;
V_35 -> V_43 . V_44 . V_72 = 1 ;
V_35 -> V_43 . V_44 . V_73 = 1 ;
V_65 = F_19 ( V_38 ) ;
V_65 -> V_43 . V_74 . V_75 = V_3 ;
V_65 -> V_43 . V_74 . V_76 = V_62 ;
V_67 = F_20 ( F_21 ( V_77 ) | F_21 ( V_78 ) ) ;
V_32 = F_22 ( V_35 -> V_41 ) ;
V_69 = F_12 ( V_32 ) ;
F_23 ( & V_69 -> V_79 ) ;
V_66 = F_24 ( V_38 , V_35 ) ;
F_25 ( & V_69 -> V_79 ) ;
F_26 ( V_67 ) ;
if ( V_66 == 0 ) {
struct V_32 * V_32 = V_3 -> V_31 -> V_33 -> V_34 ;
struct V_68 * V_69 = F_12 ( V_32 ) ;
F_27 ( V_62 ) ;
if ( V_62 -> V_80 == NULL ) {
F_28 ( V_62 ) ;
if ( V_66 == 0 )
V_66 = - V_81 ;
} else if ( ! F_29 ( V_62 ) ) {
F_28 ( V_62 ) ;
F_13 ( V_50 , L_2
L_3 ,
V_62 , V_62 -> V_28 ) ;
* V_63 = true ;
V_66 = - V_82 ;
}
if ( V_66 == 0 ) {
F_30 ( & V_69 -> V_83 ) ;
V_69 -> V_84 |= V_85 ;
F_31 ( & V_69 -> V_83 ) ;
}
}
EXIT ;
V_70:
F_32 ( V_38 , V_35 ) ;
F_33 ( & V_27 , V_38 ) ;
F_13 ( V_50 , L_4 , V_86 -> V_87 , V_66 ) ;
F_3 ( F_34 ( V_66 == 0 , F_35 ( V_62 ) ) ) ;
return ( V_66 ) ;
}
static inline int F_36 ( int V_66 )
{
switch( V_66 ) {
case 0 :
V_66 = V_88 ;
break;
case - V_89 :
V_66 = V_90 ;
break;
case - V_91 :
V_66 = V_92 ;
break;
default:
V_66 = V_93 ;
break;
}
return V_66 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_94 * V_95 )
{
struct V_24 * V_38 ;
struct V_23 * V_35 ;
struct V_64 * V_65 = NULL ;
struct V_61 * V_62 ;
unsigned long V_29 ;
struct V_26 V_27 ;
int V_66 ;
int V_96 = 0 ;
V_16 ;
V_35 = F_6 ( V_3 , & V_38 , & V_27 , V_95 -> V_97 , & V_29 ) ;
if ( F_10 ( V_35 ) )
RETURN ( F_36 ( F_18 ( V_35 ) ) ) ;
V_66 = V_35 -> V_71 ;
if ( V_66 == 0 ) {
V_65 = F_19 ( V_38 ) ;
V_65 -> V_43 . V_74 . V_75 = V_3 ;
V_65 -> V_43 . V_74 . V_76 = NULL ;
V_65 -> V_43 . V_74 . V_74 . V_98 = V_95 ;
V_66 = F_24 ( V_38 , V_35 ) ;
V_96 = V_65 -> V_43 . V_74 . V_74 . V_99 ;
V_62 = V_65 -> V_43 . V_74 . V_76 ;
if ( V_66 != 0 && V_62 != NULL ) {
F_38 ( V_62 ) ;
V_95 -> V_61 = NULL ;
}
}
F_32 ( V_38 , V_35 ) ;
F_33 ( & V_27 , V_38 ) ;
V_3 -> V_21 |= V_29 ;
if ( V_66 != 0 && ! ( V_96 & V_100 ) )
V_96 |= F_36 ( V_66 ) ;
F_13 ( V_50 , L_5 ,
V_86 -> V_87 , V_96 , V_66 ) ;
RETURN ( V_96 ) ;
}
static int F_39 ( struct V_2 * V_3 , struct V_94 * V_95 )
{
int V_5 = 0 ;
bool V_101 = false ;
int V_66 ;
T_4 V_67 ;
V_67 = F_20 ( F_21 ( V_77 ) | F_21 ( V_78 ) ) ;
V_102:
V_66 = F_37 ( V_3 , V_95 ) ;
F_3 ( ! ( V_66 & V_88 ) ) ;
if ( V_66 == 0 ) {
struct V_61 * V_62 = V_95 -> V_61 ;
F_27 ( V_62 ) ;
if ( F_40 ( V_62 -> V_80 == NULL ) ) {
F_28 ( V_62 ) ;
F_38 ( V_62 ) ;
V_95 -> V_61 = NULL ;
if ( ! V_101 && ++ V_5 > 16 ) {
F_41 ( L_6
L_7 ,
V_86 -> V_87 ) ;
V_101 = true ;
}
goto V_102;
}
V_66 |= V_88 ;
}
F_26 ( V_67 ) ;
return V_66 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_94 * V_95 )
{
int V_5 = 0 ;
bool V_101 = false ;
bool V_63 ;
int V_66 ;
do {
V_63 = false ;
V_66 = F_17 ( V_3 , V_95 -> V_61 , & V_63 ) ;
if ( ! V_101 && ++ V_5 > 16 ) {
F_41 ( L_8
L_9 ,
V_86 -> V_87 , V_95 -> V_97 ,
V_3 -> V_31 -> V_33 -> V_34 -> V_103 ) ;
V_101 = true ;
}
} while ( V_63 );
switch( V_66 ) {
case 0 :
F_3 ( F_35 ( V_95 -> V_61 ) ) ;
V_66 = V_88 ;
break;
case - V_81 :
case - V_89 :
V_66 = V_90 ;
break;
case - V_91 :
V_66 = V_92 ;
break;
case - V_82 :
V_66 = V_100 ;
break;
default:
V_66 = V_93 ;
break;
}
return V_66 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_32 * V_32 = V_3 -> V_31 -> V_33 -> V_34 ;
struct V_104 * V_105 = F_44 ( V_32 ) ;
V_16 ;
F_3 ( V_3 -> V_31 ) ;
F_3 ( F_45 ( & V_105 -> V_106 ) >= 0 ) ;
F_46 ( & V_105 -> V_106 ) ;
EXIT ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_32 * V_32 = V_3 -> V_31 -> V_33 -> V_34 ;
struct V_104 * V_105 = F_44 ( V_32 ) ;
V_16 ;
F_3 ( V_3 -> V_31 ) ;
F_48 ( & V_105 -> V_106 ) ;
F_3 ( F_45 ( & V_105 -> V_106 ) >= 0 ) ;
EXIT ;
}
static inline unsigned long F_49 ( struct V_2 * V_3 , T_5 V_107 )
{
return V_3 -> V_8 + ( V_107 - ( ( T_5 ) V_3 -> V_10 << V_11 ) ) ;
}
int F_50 ( struct V_108 * V_80 , T_5 V_109 , T_5 V_110 )
{
int V_111 = - V_112 ;
V_16 ;
F_51 ( V_110 > V_109 , L_10 V_113 L_11 V_113 L_12 , V_110 , V_109 ) ;
if ( F_52 ( V_80 ) ) {
V_111 = 0 ;
F_53 ( V_80 , V_109 + V_114 - 1 ,
V_110 - V_109 + 1 , 0 ) ;
}
RETURN ( V_111 ) ;
}
int F_54 ( struct V_30 * V_30 , struct V_2 * V_3 )
{
struct V_32 * V_32 = V_30 -> V_33 -> V_34 ;
int V_111 ;
V_16 ;
if ( F_7 ( V_30 ) )
RETURN ( - V_39 ) ;
F_55 ( F_56 ( V_32 ) , V_115 , 1 ) ;
V_111 = F_57 ( V_30 , V_3 ) ;
if ( V_111 == 0 ) {
V_3 -> V_19 = & V_20 ;
V_3 -> V_19 -> V_116 ( V_3 ) ;
V_111 = F_58 ( V_32 ) ;
}
RETURN ( V_111 ) ;
}
