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
for( V_3 = F_5 ( V_14 , V_4 ) ;
V_3 != NULL && V_3 -> V_8 < ( V_4 + V_5 ) ; V_3 = V_3 -> V_17 ) {
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
struct V_31 * V_31 = V_29 -> V_32 -> V_33 ;
struct V_22 * V_34 ;
struct V_35 * V_36 ;
struct V_23 * V_37 ;
int V_38 ;
* V_24 = NULL ;
if ( F_7 ( V_29 ) )
return F_8 ( - V_39 ) ;
V_37 = F_9 ( V_26 ) ;
if ( F_10 ( V_37 ) )
return F_8 ( - V_40 ) ;
* V_24 = V_37 ;
V_34 = F_11 ( V_37 ) ;
V_34 -> V_41 = F_12 ( V_31 ) -> V_42 ;
F_3 ( V_34 -> V_41 != NULL ) ;
V_36 = & V_34 -> V_43 . V_44 ;
V_36 -> V_45 = V_27 ;
V_36 -> V_46 = V_3 -> V_20 & V_47 ;
if ( V_28 != NULL )
* V_28 = V_3 -> V_20 & ( V_48 | V_49 ) ;
V_3 -> V_20 &= ~ V_49 ;
V_3 -> V_20 |= V_48 ;
F_13 ( V_50 , L_1 , V_3 -> V_20 ,
V_36 -> V_45 , V_36 -> V_46 ) ;
V_38 = F_14 ( V_37 , V_34 , V_51 , V_34 -> V_41 ) ;
if ( V_38 == 0 ) {
struct V_52 * V_53 = F_15 ( V_37 ) ;
struct V_54 * V_55 = F_16 ( V_29 ) ;
F_3 ( V_53 -> V_56 . V_57 == V_34 ) ;
V_34 -> V_58 = V_59 ;
V_53 -> V_60 = V_55 ;
} else {
F_3 ( V_38 < 0 ) ;
F_17 ( V_37 , V_34 ) ;
F_18 ( V_26 , V_37 ) ;
V_34 = F_8 ( V_38 ) ;
}
return V_34 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_61 * V_62 ,
bool * V_63 )
{
struct V_23 * V_37 ;
struct V_22 * V_34 ;
struct V_64 * V_65 ;
struct V_25 V_26 ;
int V_66 ;
T_4 V_67 ;
struct V_31 * V_31 ;
struct V_68 * V_69 ;
F_3 ( V_62 != NULL ) ;
V_34 = F_6 ( V_3 , & V_37 , & V_26 , V_62 -> V_27 , NULL ) ;
if ( F_10 ( V_34 ) )
GOTO ( V_70 , V_66 = F_20 ( V_34 ) ) ;
V_66 = V_34 -> V_71 ;
if ( V_66 < 0 )
GOTO ( V_72 , V_66 ) ;
V_34 -> V_43 . V_44 . V_73 = 1 ;
V_34 -> V_43 . V_44 . V_74 = 1 ;
V_65 = F_21 ( V_37 ) ;
V_65 -> V_43 . V_75 . V_76 = V_3 ;
V_65 -> V_43 . V_75 . V_77 = V_62 ;
V_67 = F_22 ( F_23 ( V_78 ) | F_23 ( V_79 ) ) ;
V_31 = F_24 ( V_34 -> V_41 ) ;
V_69 = F_12 ( V_31 ) ;
F_25 ( & V_69 -> V_80 ) ;
V_66 = F_26 ( V_37 , V_34 ) ;
F_27 ( & V_69 -> V_80 ) ;
F_28 ( V_67 ) ;
if ( V_66 == 0 ) {
struct V_31 * V_31 = V_3 -> V_30 -> V_32 -> V_33 ;
struct V_68 * V_69 = F_12 ( V_31 ) ;
F_29 ( V_62 ) ;
if ( V_62 -> V_81 == NULL ) {
F_30 ( V_62 ) ;
if ( V_66 == 0 )
V_66 = - V_82 ;
} else if ( ! F_31 ( V_62 ) ) {
F_30 ( V_62 ) ;
F_13 ( V_50 , L_2
L_3 ,
V_62 , V_62 -> V_27 ) ;
* V_63 = true ;
V_66 = - V_83 ;
}
if ( V_66 == 0 ) {
F_32 ( & V_69 -> V_84 ) ;
V_69 -> V_85 |= V_86 ;
F_33 ( & V_69 -> V_84 ) ;
}
}
V_72:
F_17 ( V_37 , V_34 ) ;
F_18 ( & V_26 , V_37 ) ;
V_70:
F_13 ( V_50 , L_4 , V_87 -> V_88 , V_66 ) ;
F_3 ( F_34 ( V_66 == 0 , F_35 ( V_62 ) ) ) ;
return V_66 ;
}
static inline int F_36 ( int V_66 )
{
switch( V_66 ) {
case 0 :
V_66 = V_89 ;
break;
case - V_90 :
V_66 = V_91 ;
break;
case - V_92 :
V_66 = V_93 ;
break;
default:
V_66 = V_94 ;
break;
}
return V_66 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_95 * V_96 )
{
struct V_23 * V_37 ;
struct V_22 * V_34 ;
struct V_64 * V_65 = NULL ;
struct V_61 * V_62 ;
unsigned long V_28 ;
struct V_25 V_26 ;
int V_66 ;
int V_97 = 0 ;
V_34 = F_6 ( V_3 , & V_37 , & V_26 , V_96 -> V_98 , & V_28 ) ;
if ( F_10 ( V_34 ) )
return F_36 ( F_20 ( V_34 ) ) ;
V_66 = V_34 -> V_71 ;
if ( V_66 == 0 ) {
V_65 = F_21 ( V_37 ) ;
V_65 -> V_43 . V_75 . V_76 = V_3 ;
V_65 -> V_43 . V_75 . V_77 = NULL ;
V_65 -> V_43 . V_75 . V_75 . V_99 = V_96 ;
V_66 = F_26 ( V_37 , V_34 ) ;
V_97 = V_65 -> V_43 . V_75 . V_75 . V_100 ;
V_62 = V_65 -> V_43 . V_75 . V_77 ;
if ( V_66 != 0 && V_62 != NULL ) {
F_38 ( V_62 ) ;
V_96 -> V_61 = NULL ;
}
}
F_17 ( V_37 , V_34 ) ;
F_18 ( & V_26 , V_37 ) ;
V_3 -> V_20 |= V_28 ;
if ( V_66 != 0 && ! ( V_97 & V_101 ) )
V_97 |= F_36 ( V_66 ) ;
F_13 ( V_50 , L_5 ,
V_87 -> V_88 , V_97 , V_66 ) ;
return V_97 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_95 * V_96 )
{
int V_5 = 0 ;
bool V_102 = false ;
int V_66 ;
T_4 V_67 ;
V_67 = F_22 ( F_23 ( V_78 ) | F_23 ( V_79 ) ) ;
V_103:
V_66 = F_37 ( V_3 , V_96 ) ;
F_3 ( ! ( V_66 & V_89 ) ) ;
if ( V_66 == 0 ) {
struct V_61 * V_62 = V_96 -> V_61 ;
F_29 ( V_62 ) ;
if ( F_40 ( V_62 -> V_81 == NULL ) ) {
F_30 ( V_62 ) ;
F_38 ( V_62 ) ;
V_96 -> V_61 = NULL ;
if ( ! V_102 && ++ V_5 > 16 ) {
F_41 ( L_6
L_7 ,
V_87 -> V_88 ) ;
V_102 = true ;
}
goto V_103;
}
V_66 = V_89 ;
}
F_28 ( V_67 ) ;
return V_66 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_95 * V_96 )
{
int V_5 = 0 ;
bool V_102 = false ;
bool V_63 ;
int V_66 ;
do {
V_63 = false ;
V_66 = F_19 ( V_3 , V_96 -> V_61 , & V_63 ) ;
if ( ! V_102 && ++ V_5 > 16 ) {
F_41 ( L_8
L_9 ,
V_87 -> V_88 , V_96 -> V_98 ,
V_3 -> V_30 -> V_32 -> V_33 -> V_104 ) ;
V_102 = true ;
}
} while ( V_63 );
switch( V_66 ) {
case 0 :
F_3 ( F_35 ( V_96 -> V_61 ) ) ;
V_66 = V_89 ;
break;
case - V_82 :
case - V_90 :
V_66 = V_91 ;
break;
case - V_92 :
V_66 = V_93 ;
break;
case - V_83 :
V_66 = V_101 ;
break;
default:
V_66 = V_94 ;
break;
}
return V_66 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_31 * V_31 = V_3 -> V_30 -> V_32 -> V_33 ;
struct V_105 * V_106 = F_44 ( V_31 ) ;
F_3 ( V_3 -> V_30 ) ;
F_3 ( F_45 ( & V_106 -> V_107 ) >= 0 ) ;
F_46 ( & V_106 -> V_107 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_31 * V_31 = V_3 -> V_30 -> V_32 -> V_33 ;
struct V_105 * V_106 = F_44 ( V_31 ) ;
F_3 ( V_3 -> V_30 ) ;
F_48 ( & V_106 -> V_107 ) ;
F_3 ( F_45 ( & V_106 -> V_107 ) >= 0 ) ;
}
int F_49 ( struct V_108 * V_81 , T_5 V_109 , T_5 V_110 )
{
int V_38 = - V_111 ;
F_50 ( V_110 > V_109 , L_10 V_112 L_11 V_112 L_12 , V_110 , V_109 ) ;
if ( F_51 ( V_81 ) ) {
V_38 = 0 ;
F_52 ( V_81 , V_109 + V_113 - 1 ,
V_110 - V_109 + 1 , 0 ) ;
}
return V_38 ;
}
int F_53 ( struct V_29 * V_29 , struct V_2 * V_3 )
{
struct V_31 * V_31 = V_29 -> V_32 -> V_33 ;
int V_38 ;
if ( F_7 ( V_29 ) )
return - V_39 ;
F_54 ( F_55 ( V_31 ) , V_114 , 1 ) ;
V_38 = F_56 ( V_29 , V_3 ) ;
if ( V_38 == 0 ) {
V_3 -> V_18 = & V_19 ;
V_3 -> V_18 -> V_115 ( V_3 ) ;
V_38 = F_57 ( V_31 ) ;
}
return V_38 ;
}
