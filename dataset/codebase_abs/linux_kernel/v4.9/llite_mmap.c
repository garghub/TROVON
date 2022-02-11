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
F_3 ( ! F_4 ( & V_14 -> V_16 ) ) ;
for ( V_3 = F_5 ( V_14 , V_4 ) ;
V_3 && V_3 -> V_8 < ( V_4 + V_5 ) ; V_3 = V_3 -> V_17 ) {
if ( V_3 -> V_18 && V_3 -> V_18 == & V_19 &&
V_3 -> V_20 & V_21 ) {
V_15 = V_3 ;
break;
}
}
return V_15 ;
}
static struct V_22 *
F_6 ( struct V_2 * V_3 , struct V_23 * * V_24 ,
struct V_25 * V_26 , T_3 V_27 ,
unsigned long * V_28 )
{
struct V_29 * V_29 = V_3 -> V_30 ;
struct V_31 * V_31 = F_7 ( V_29 ) ;
struct V_22 * V_32 ;
struct V_33 * V_34 ;
struct V_23 * V_35 ;
int V_36 ;
* V_24 = NULL ;
if ( F_8 ( V_29 ) )
return F_9 ( - V_37 ) ;
V_35 = F_10 ( V_26 ) ;
if ( F_11 ( V_35 ) )
return F_9 ( - V_38 ) ;
* V_24 = V_35 ;
V_39:
V_32 = F_12 ( V_35 ) ;
V_32 -> V_40 = F_13 ( V_31 ) -> V_41 ;
F_3 ( V_32 -> V_40 ) ;
V_34 = & V_32 -> V_42 . V_43 ;
V_34 -> V_44 = V_27 ;
V_34 -> V_45 = V_3 -> V_20 & V_46 ;
if ( V_28 )
* V_28 = V_3 -> V_20 & ( V_47 | V_48 ) ;
V_3 -> V_20 &= ~ V_48 ;
V_3 -> V_20 |= V_47 ;
F_14 ( V_49 , L_1 , V_3 -> V_20 ,
V_34 -> V_44 , V_34 -> V_45 ) ;
V_36 = F_15 ( V_35 , V_32 , V_50 , V_32 -> V_40 ) ;
if ( V_36 == 0 ) {
struct V_51 * V_52 = F_16 ( V_35 ) ;
struct V_53 * V_54 = F_17 ( V_29 ) ;
F_3 ( V_52 -> V_55 . V_56 == V_32 ) ;
V_32 -> V_57 = V_58 ;
V_52 -> V_59 = V_54 ;
} else {
F_3 ( V_36 < 0 ) ;
F_18 ( V_35 , V_32 ) ;
if ( V_32 -> V_60 )
goto V_39;
F_19 ( V_26 , V_35 ) ;
V_32 = F_9 ( V_36 ) ;
}
return V_32 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_61 * V_62 ,
bool * V_63 )
{
struct V_23 * V_35 ;
struct V_22 * V_32 ;
struct V_51 * V_52 ;
struct V_25 V_26 ;
int V_64 ;
T_4 V_65 ;
struct V_31 * V_31 ;
struct V_66 * V_67 ;
V_32 = F_6 ( V_3 , & V_35 , & V_26 , V_62 -> V_27 , NULL ) ;
if ( F_11 ( V_32 ) ) {
V_64 = F_21 ( V_32 ) ;
goto V_68;
}
V_64 = V_32 -> V_69 ;
if ( V_64 < 0 )
goto V_70;
V_32 -> V_42 . V_43 . V_71 = 1 ;
V_32 -> V_42 . V_43 . V_72 = 1 ;
V_52 = F_16 ( V_35 ) ;
V_52 -> V_42 . V_73 . V_74 = V_3 ;
V_52 -> V_42 . V_73 . V_75 = V_62 ;
V_65 = F_22 ( F_23 ( V_76 ) | F_23 ( V_77 ) ) ;
V_31 = F_24 ( V_32 -> V_40 ) ;
V_67 = F_13 ( V_31 ) ;
V_64 = F_25 ( V_35 , V_32 ) ;
F_26 ( V_65 ) ;
if ( V_64 == 0 ) {
struct V_31 * V_31 = F_7 ( V_3 -> V_30 ) ;
struct V_66 * V_67 = F_13 ( V_31 ) ;
F_27 ( V_62 ) ;
if ( ! V_62 -> V_78 ) {
F_28 ( V_62 ) ;
if ( V_64 == 0 )
V_64 = - V_79 ;
} else if ( ! F_29 ( V_62 ) ) {
F_28 ( V_62 ) ;
F_14 ( V_49 , L_2 ,
V_62 , V_62 -> V_27 ) ;
* V_63 = true ;
V_64 = - V_80 ;
}
if ( V_64 == 0 ) {
F_30 ( & V_67 -> V_81 ) ;
V_67 -> V_82 |= V_83 ;
F_31 ( & V_67 -> V_81 ) ;
}
}
V_70:
F_18 ( V_35 , V_32 ) ;
F_19 ( & V_26 , V_35 ) ;
V_68:
F_14 ( V_49 , L_3 , V_84 -> V_85 , V_64 ) ;
F_3 ( F_32 ( V_64 == 0 , F_33 ( V_62 ) ) ) ;
return V_64 ;
}
static inline int F_34 ( int V_64 )
{
switch ( V_64 ) {
case 0 :
V_64 = V_86 ;
break;
case - V_87 :
V_64 = V_88 ;
break;
case - V_89 :
V_64 = V_90 ;
break;
default:
V_64 = V_91 ;
break;
}
return V_64 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_92 * V_93 )
{
struct V_23 * V_35 ;
struct V_22 * V_32 ;
struct V_51 * V_52 = NULL ;
struct V_61 * V_62 ;
unsigned long V_28 ;
struct V_25 V_26 ;
int V_64 ;
int V_94 = 0 ;
V_32 = F_6 ( V_3 , & V_35 , & V_26 , V_93 -> V_95 , & V_28 ) ;
if ( F_11 ( V_32 ) )
return F_34 ( F_21 ( V_32 ) ) ;
V_64 = V_32 -> V_69 ;
if ( V_64 == 0 ) {
V_52 = F_16 ( V_35 ) ;
V_52 -> V_42 . V_73 . V_74 = V_3 ;
V_52 -> V_42 . V_73 . V_75 = NULL ;
V_52 -> V_42 . V_73 . V_96 = V_93 ;
V_52 -> V_42 . V_73 . V_97 = 0 ;
V_52 -> V_42 . V_73 . V_98 = false ;
F_36 ( V_3 -> V_30 , V_35 , V_32 ) ;
V_64 = F_25 ( V_35 , V_32 ) ;
F_37 ( V_3 -> V_30 , V_35 ) ;
if ( V_52 -> V_42 . V_73 . V_98 )
V_94 = V_52 -> V_42 . V_73 . V_97 ;
V_62 = V_52 -> V_42 . V_73 . V_75 ;
if ( V_64 != 0 && V_62 ) {
F_38 ( V_62 ) ;
V_93 -> V_61 = NULL ;
}
}
F_18 ( V_35 , V_32 ) ;
F_19 ( & V_26 , V_35 ) ;
V_3 -> V_20 |= V_28 ;
if ( V_64 != 0 && ! ( V_94 & V_99 ) )
V_94 |= F_34 ( V_64 ) ;
F_14 ( V_49 , L_4 ,
V_84 -> V_85 , V_94 , V_64 ) ;
return V_94 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_92 * V_93 )
{
int V_5 = 0 ;
bool V_100 = false ;
int V_64 ;
T_4 V_65 ;
V_65 = F_22 ( F_23 ( V_76 ) | F_23 ( V_77 ) ) ;
V_39:
V_64 = F_35 ( V_3 , V_93 ) ;
F_3 ( ! ( V_64 & V_86 ) ) ;
if ( V_64 == 0 ) {
struct V_61 * V_62 = V_93 -> V_61 ;
F_27 ( V_62 ) ;
if ( F_40 ( ! V_62 -> V_78 ) ) {
F_28 ( V_62 ) ;
F_38 ( V_62 ) ;
V_93 -> V_61 = NULL ;
if ( ! V_100 && ++ V_5 > 16 ) {
F_41 ( L_5 ,
V_84 -> V_85 ) ;
V_100 = true ;
}
goto V_39;
}
V_64 = V_86 ;
}
F_26 ( V_65 ) ;
return V_64 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_92 * V_93 )
{
int V_5 = 0 ;
bool V_100 = false ;
bool V_63 ;
int V_64 ;
do {
V_63 = false ;
V_64 = F_20 ( V_3 , V_93 -> V_61 , & V_63 ) ;
if ( ! V_100 && ++ V_5 > 16 ) {
const struct V_101 * V_102 = V_3 -> V_30 -> V_103 . V_101 ;
F_41 ( L_6 V_104 L_7 ,
V_84 -> V_85 , V_93 -> V_95 ,
F_43 ( F_44 ( V_102 -> V_105 ) ) ) ;
V_100 = true ;
}
} while ( V_63 );
switch ( V_64 ) {
case 0 :
F_3 ( F_33 ( V_93 -> V_61 ) ) ;
V_64 = V_86 ;
break;
case - V_79 :
case - V_87 :
V_64 = V_88 ;
break;
case - V_89 :
V_64 = V_90 ;
break;
case - V_80 :
V_64 = V_99 ;
break;
default:
V_64 = V_91 ;
break;
}
return V_64 ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_31 * V_31 = F_7 ( V_3 -> V_30 ) ;
struct V_106 * V_107 = F_46 ( V_31 ) ;
F_3 ( F_47 ( & V_107 -> V_108 ) >= 0 ) ;
F_48 ( & V_107 -> V_108 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_31 * V_31 = F_7 ( V_3 -> V_30 ) ;
struct V_106 * V_107 = F_46 ( V_31 ) ;
F_50 ( & V_107 -> V_108 ) ;
F_3 ( F_47 ( & V_107 -> V_108 ) >= 0 ) ;
}
int F_51 ( struct V_109 * V_78 , T_5 V_110 , T_5 V_111 )
{
int V_36 = - V_112 ;
F_52 ( V_111 > V_110 , L_8 , V_111 , V_110 ) ;
if ( F_53 ( V_78 ) ) {
V_36 = 0 ;
F_54 ( V_78 , V_110 + V_113 - 1 ,
V_111 - V_110 + 1 , 0 ) ;
}
return V_36 ;
}
int F_55 ( struct V_29 * V_29 , struct V_2 * V_3 )
{
struct V_31 * V_31 = F_7 ( V_29 ) ;
int V_36 ;
if ( F_8 ( V_29 ) )
return - V_37 ;
F_56 ( F_57 ( V_31 ) , V_114 , 1 ) ;
V_36 = F_58 ( V_29 , V_3 ) ;
if ( V_36 == 0 ) {
V_3 -> V_18 = & V_19 ;
V_3 -> V_18 -> V_115 ( V_3 ) ;
V_36 = F_59 ( V_31 ) ;
}
return V_36 ;
}
