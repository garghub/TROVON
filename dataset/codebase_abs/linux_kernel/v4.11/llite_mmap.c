void F_1 ( union V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_5 ,
T_1 V_6 )
{
V_2 -> V_7 . V_8 = ( ( V_5 - V_4 -> V_9 ) & V_10 ) +
( V_4 -> V_11 << V_12 ) ;
V_2 -> V_7 . V_13 = ( V_2 -> V_7 . V_8 + V_6 - 1 ) |
~ V_10 ;
}
struct V_3 * F_2 ( struct V_14 * V_15 , unsigned long V_5 ,
T_1 V_6 )
{
struct V_3 * V_4 , * V_16 = NULL ;
F_3 ( ! F_4 ( & V_15 -> V_17 ) ) ;
for ( V_4 = F_5 ( V_15 , V_5 ) ;
V_4 && V_4 -> V_9 < ( V_5 + V_6 ) ; V_4 = V_4 -> V_18 ) {
if ( V_4 -> V_19 && V_4 -> V_19 == & V_20 &&
V_4 -> V_21 & V_22 ) {
V_16 = V_4 ;
break;
}
}
return V_16 ;
}
static struct V_23 *
F_6 ( struct V_24 * V_25 , struct V_3 * V_4 ,
T_2 V_26 , unsigned long * V_27 )
{
struct V_28 * V_28 = V_4 -> V_29 ;
struct V_30 * V_30 = F_7 ( V_28 ) ;
struct V_23 * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
if ( F_8 ( V_28 ) )
return F_9 ( - V_35 ) ;
V_36:
V_31 = F_10 ( V_25 ) ;
V_31 -> V_37 = F_11 ( V_30 ) -> V_38 ;
F_3 ( V_31 -> V_37 ) ;
V_33 = & V_31 -> V_39 . V_40 ;
V_33 -> V_41 = V_26 ;
V_33 -> V_42 = V_4 -> V_21 & V_43 ;
if ( V_27 )
* V_27 = V_4 -> V_21 & ( V_44 | V_45 ) ;
V_4 -> V_21 &= ~ V_45 ;
V_4 -> V_21 |= V_44 ;
F_12 ( V_46 , L_1 , V_4 -> V_21 ,
V_33 -> V_41 , V_33 -> V_42 ) ;
V_34 = F_13 ( V_25 , V_31 , V_47 , V_31 -> V_37 ) ;
if ( V_34 == 0 ) {
struct V_48 * V_49 = F_14 ( V_25 ) ;
struct V_50 * V_51 = F_15 ( V_28 ) ;
F_3 ( V_49 -> V_52 . V_53 == V_31 ) ;
V_31 -> V_54 = V_55 ;
V_49 -> V_56 = V_51 ;
} else {
F_3 ( V_34 < 0 ) ;
F_16 ( V_25 , V_31 ) ;
if ( V_31 -> V_57 )
goto V_36;
V_31 = F_9 ( V_34 ) ;
}
return V_31 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_58 * V_59 ,
bool * V_60 )
{
struct V_24 * V_25 ;
struct V_23 * V_31 ;
struct V_48 * V_49 ;
int V_61 ;
int V_62 ;
T_3 V_63 ;
struct V_30 * V_30 ;
struct V_64 * V_65 ;
V_25 = F_18 ( & V_62 ) ;
if ( F_19 ( V_25 ) )
return F_20 ( V_25 ) ;
V_31 = F_6 ( V_25 , V_4 , V_59 -> V_26 , NULL ) ;
if ( F_19 ( V_31 ) ) {
V_61 = F_20 ( V_31 ) ;
goto V_66;
}
V_61 = V_31 -> V_67 ;
if ( V_61 < 0 )
goto V_68;
V_31 -> V_39 . V_40 . V_69 = 1 ;
V_31 -> V_39 . V_40 . V_70 = 1 ;
V_49 = F_14 ( V_25 ) ;
V_49 -> V_39 . V_71 . V_72 = V_4 ;
V_49 -> V_39 . V_71 . V_73 = V_59 ;
V_63 = F_21 ( F_22 ( V_74 ) | F_22 ( V_75 ) ) ;
V_30 = F_23 ( V_31 -> V_37 ) ;
V_65 = F_11 ( V_30 ) ;
V_61 = F_24 ( V_25 , V_31 ) ;
F_25 ( V_63 ) ;
if ( V_61 == 0 ) {
struct V_30 * V_30 = F_7 ( V_4 -> V_29 ) ;
struct V_64 * V_65 = F_11 ( V_30 ) ;
F_26 ( V_59 ) ;
if ( ! V_59 -> V_76 ) {
F_27 ( V_59 ) ;
if ( V_61 == 0 )
V_61 = - V_77 ;
} else if ( ! F_28 ( V_59 ) ) {
F_27 ( V_59 ) ;
F_12 ( V_46 , L_2 ,
V_59 , V_59 -> V_26 ) ;
* V_60 = true ;
V_61 = - V_78 ;
}
if ( ! V_61 )
F_29 ( V_79 , & V_65 -> V_80 ) ;
}
V_68:
F_16 ( V_25 , V_31 ) ;
V_66:
F_30 ( V_25 , & V_62 ) ;
F_12 ( V_46 , L_3 , V_81 -> V_82 , V_61 ) ;
F_3 ( F_31 ( V_61 == 0 , F_32 ( V_59 ) ) ) ;
return V_61 ;
}
static inline int F_33 ( int V_61 )
{
switch ( V_61 ) {
case 0 :
V_61 = V_83 ;
break;
case - V_84 :
V_61 = V_85 ;
break;
case - V_86 :
V_61 = V_87 ;
break;
default:
V_61 = V_88 ;
break;
}
return V_61 ;
}
static int F_34 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
struct V_24 * V_25 ;
struct V_23 * V_31 ;
struct V_48 * V_49 = NULL ;
struct V_58 * V_59 ;
unsigned long V_27 ;
int V_61 = 0 ;
int V_91 = 0 ;
int V_62 ;
V_25 = F_18 ( & V_62 ) ;
if ( F_19 ( V_25 ) )
return F_20 ( V_25 ) ;
V_31 = F_6 ( V_25 , V_4 , V_90 -> V_92 , & V_27 ) ;
if ( F_19 ( V_31 ) ) {
V_61 = F_33 ( F_20 ( V_31 ) ) ;
goto V_66;
}
V_61 = V_31 -> V_67 ;
if ( V_61 == 0 ) {
V_49 = F_14 ( V_25 ) ;
V_49 -> V_39 . V_71 . V_72 = V_4 ;
V_49 -> V_39 . V_71 . V_73 = NULL ;
V_49 -> V_39 . V_71 . V_93 = V_90 ;
V_49 -> V_39 . V_71 . V_94 = 0 ;
V_49 -> V_39 . V_71 . V_95 = false ;
F_35 ( V_4 -> V_29 , V_25 , V_31 ) ;
V_61 = F_24 ( V_25 , V_31 ) ;
F_36 ( V_4 -> V_29 , V_25 ) ;
if ( V_49 -> V_39 . V_71 . V_95 )
V_91 = V_49 -> V_39 . V_71 . V_94 ;
V_59 = V_49 -> V_39 . V_71 . V_73 ;
if ( V_61 != 0 && V_59 ) {
F_37 ( V_59 ) ;
V_90 -> V_58 = NULL ;
}
}
F_16 ( V_25 , V_31 ) ;
V_4 -> V_21 |= V_27 ;
V_66:
F_30 ( V_25 , & V_62 ) ;
if ( V_61 != 0 && ! ( V_91 & V_96 ) )
V_91 |= F_33 ( V_61 ) ;
F_12 ( V_46 , L_4 , V_81 -> V_82 , V_91 , V_61 ) ;
return V_91 ;
}
static int F_38 ( struct V_89 * V_90 )
{
int V_6 = 0 ;
bool V_97 = false ;
int V_61 ;
T_3 V_63 ;
V_63 = F_21 ( F_22 ( V_74 ) | F_22 ( V_75 ) ) ;
V_36:
V_61 = F_34 ( V_90 -> V_4 , V_90 ) ;
F_3 ( ! ( V_61 & V_83 ) ) ;
if ( V_61 == 0 ) {
struct V_58 * V_59 = V_90 -> V_58 ;
F_26 ( V_59 ) ;
if ( F_39 ( ! V_59 -> V_76 ) ) {
F_27 ( V_59 ) ;
F_37 ( V_59 ) ;
V_90 -> V_58 = NULL ;
if ( ! V_97 && ++ V_6 > 16 ) {
F_40 ( L_5 ,
V_81 -> V_82 ) ;
V_97 = true ;
}
goto V_36;
}
V_61 = V_83 ;
}
F_25 ( V_63 ) ;
return V_61 ;
}
static int F_41 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_4 ;
int V_6 = 0 ;
bool V_97 = false ;
bool V_60 ;
int V_61 ;
F_42 ( V_4 -> V_29 ) ;
do {
V_60 = false ;
V_61 = F_17 ( V_4 , V_90 -> V_58 , & V_60 ) ;
if ( ! V_97 && ++ V_6 > 16 ) {
const struct V_98 * V_99 = V_4 -> V_29 -> V_100 . V_98 ;
F_40 ( L_6 V_101 L_7 ,
V_81 -> V_82 , V_90 -> V_92 ,
F_43 ( F_44 ( V_99 -> V_102 ) ) ) ;
V_97 = true ;
}
} while ( V_60 );
switch ( V_61 ) {
case 0 :
F_3 ( F_32 ( V_90 -> V_58 ) ) ;
V_61 = V_83 ;
break;
case - V_77 :
case - V_78 :
case - V_84 :
V_61 = V_85 ;
break;
case - V_86 :
V_61 = V_87 ;
break;
default:
V_61 = V_88 ;
break;
}
return V_61 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_30 * V_30 = F_7 ( V_4 -> V_29 ) ;
struct V_103 * V_104 = F_46 ( V_30 ) ;
F_3 ( F_47 ( & V_104 -> V_105 ) >= 0 ) ;
F_48 ( & V_104 -> V_105 ) ;
}
static void F_49 ( struct V_3 * V_4 )
{
struct V_30 * V_30 = F_7 ( V_4 -> V_29 ) ;
struct V_103 * V_104 = F_46 ( V_30 ) ;
F_50 ( & V_104 -> V_105 ) ;
F_3 ( F_47 ( & V_104 -> V_105 ) >= 0 ) ;
}
int F_51 ( struct V_106 * V_76 , T_4 V_107 , T_4 V_108 )
{
int V_34 = - V_109 ;
F_52 ( V_108 > V_107 , L_8 , V_108 , V_107 ) ;
if ( F_53 ( V_76 ) ) {
V_34 = 0 ;
F_54 ( V_76 , V_107 + V_110 - 1 ,
V_108 - V_107 + 1 , 0 ) ;
}
return V_34 ;
}
int F_55 ( struct V_28 * V_28 , struct V_3 * V_4 )
{
struct V_30 * V_30 = F_7 ( V_28 ) ;
int V_34 ;
if ( F_8 ( V_28 ) )
return - V_35 ;
F_56 ( F_57 ( V_30 ) , V_111 , 1 ) ;
V_34 = F_58 ( V_28 , V_4 ) ;
if ( V_34 == 0 ) {
V_4 -> V_19 = & V_20 ;
V_4 -> V_19 -> V_112 ( V_4 ) ;
V_34 = F_59 ( V_30 ) ;
}
return V_34 ;
}
