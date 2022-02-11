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
V_32 = F_12 ( V_35 ) ;
V_32 -> V_39 = F_13 ( V_31 ) -> V_40 ;
F_3 ( V_32 -> V_39 != NULL ) ;
V_34 = & V_32 -> V_41 . V_42 ;
V_34 -> V_43 = V_27 ;
V_34 -> V_44 = V_3 -> V_20 & V_45 ;
if ( V_28 != NULL )
* V_28 = V_3 -> V_20 & ( V_46 | V_47 ) ;
V_3 -> V_20 &= ~ V_47 ;
V_3 -> V_20 |= V_46 ;
F_14 ( V_48 , L_1 , V_3 -> V_20 ,
V_34 -> V_43 , V_34 -> V_44 ) ;
V_36 = F_15 ( V_35 , V_32 , V_49 , V_32 -> V_39 ) ;
if ( V_36 == 0 ) {
struct V_50 * V_51 = F_16 ( V_35 ) ;
struct V_52 * V_53 = F_17 ( V_29 ) ;
F_3 ( V_51 -> V_54 . V_55 == V_32 ) ;
V_32 -> V_56 = V_57 ;
V_51 -> V_58 = V_53 ;
} else {
F_3 ( V_36 < 0 ) ;
F_18 ( V_35 , V_32 ) ;
F_19 ( V_26 , V_35 ) ;
V_32 = F_9 ( V_36 ) ;
}
return V_32 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_59 * V_60 ,
bool * V_61 )
{
struct V_23 * V_35 ;
struct V_22 * V_32 ;
struct V_62 * V_63 ;
struct V_25 V_26 ;
int V_64 ;
T_4 V_65 ;
struct V_31 * V_31 ;
struct V_66 * V_67 ;
F_3 ( V_60 != NULL ) ;
V_32 = F_6 ( V_3 , & V_35 , & V_26 , V_60 -> V_27 , NULL ) ;
if ( F_11 ( V_32 ) ) {
V_64 = F_21 ( V_32 ) ;
goto V_68;
}
V_64 = V_32 -> V_69 ;
if ( V_64 < 0 )
goto V_70;
V_32 -> V_41 . V_42 . V_71 = 1 ;
V_32 -> V_41 . V_42 . V_72 = 1 ;
V_63 = F_22 ( V_35 ) ;
V_63 -> V_41 . V_73 . V_74 = V_3 ;
V_63 -> V_41 . V_73 . V_75 = V_60 ;
V_65 = F_23 ( F_24 ( V_76 ) | F_24 ( V_77 ) ) ;
V_31 = F_25 ( V_32 -> V_39 ) ;
V_67 = F_13 ( V_31 ) ;
F_26 ( & V_67 -> V_78 ) ;
V_64 = F_27 ( V_35 , V_32 ) ;
F_28 ( & V_67 -> V_78 ) ;
F_29 ( V_65 ) ;
if ( V_64 == 0 ) {
struct V_31 * V_31 = F_7 ( V_3 -> V_30 ) ;
struct V_66 * V_67 = F_13 ( V_31 ) ;
F_30 ( V_60 ) ;
if ( V_60 -> V_79 == NULL ) {
F_31 ( V_60 ) ;
if ( V_64 == 0 )
V_64 = - V_80 ;
} else if ( ! F_32 ( V_60 ) ) {
F_31 ( V_60 ) ;
F_14 ( V_48 , L_2 ,
V_60 , V_60 -> V_27 ) ;
* V_61 = true ;
V_64 = - V_81 ;
}
if ( V_64 == 0 ) {
F_33 ( & V_67 -> V_82 ) ;
V_67 -> V_83 |= V_84 ;
F_34 ( & V_67 -> V_82 ) ;
}
}
V_70:
F_18 ( V_35 , V_32 ) ;
F_19 ( & V_26 , V_35 ) ;
V_68:
F_14 ( V_48 , L_3 , V_85 -> V_86 , V_64 ) ;
F_3 ( F_35 ( V_64 == 0 , F_36 ( V_60 ) ) ) ;
return V_64 ;
}
static inline int F_37 ( int V_64 )
{
switch ( V_64 ) {
case 0 :
V_64 = V_87 ;
break;
case - V_88 :
V_64 = V_89 ;
break;
case - V_90 :
V_64 = V_91 ;
break;
default:
V_64 = V_92 ;
break;
}
return V_64 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_93 * V_94 )
{
struct V_23 * V_35 ;
struct V_22 * V_32 ;
struct V_62 * V_63 = NULL ;
struct V_59 * V_60 ;
unsigned long V_28 ;
struct V_25 V_26 ;
int V_64 ;
int V_95 = 0 ;
V_32 = F_6 ( V_3 , & V_35 , & V_26 , V_94 -> V_96 , & V_28 ) ;
if ( F_11 ( V_32 ) )
return F_37 ( F_21 ( V_32 ) ) ;
V_64 = V_32 -> V_69 ;
if ( V_64 == 0 ) {
V_63 = F_22 ( V_35 ) ;
V_63 -> V_41 . V_73 . V_74 = V_3 ;
V_63 -> V_41 . V_73 . V_75 = NULL ;
V_63 -> V_41 . V_73 . V_73 . V_97 = V_94 ;
V_63 -> V_41 . V_73 . V_73 . V_98 = 0 ;
V_63 -> V_41 . V_73 . V_73 . V_99 = false ;
V_64 = F_27 ( V_35 , V_32 ) ;
if ( V_63 -> V_41 . V_73 . V_73 . V_99 )
V_95 = V_63 -> V_41 . V_73 . V_73 . V_98 ;
V_60 = V_63 -> V_41 . V_73 . V_75 ;
if ( V_64 != 0 && V_60 != NULL ) {
F_39 ( V_60 ) ;
V_94 -> V_59 = NULL ;
}
}
F_18 ( V_35 , V_32 ) ;
F_19 ( & V_26 , V_35 ) ;
V_3 -> V_20 |= V_28 ;
if ( V_64 != 0 && ! ( V_95 & V_100 ) )
V_95 |= F_37 ( V_64 ) ;
F_14 ( V_48 , L_4 ,
V_85 -> V_86 , V_95 , V_64 ) ;
return V_95 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_93 * V_94 )
{
int V_5 = 0 ;
bool V_101 = false ;
int V_64 ;
T_4 V_65 ;
V_65 = F_23 ( F_24 ( V_76 ) | F_24 ( V_77 ) ) ;
V_102:
V_64 = F_38 ( V_3 , V_94 ) ;
F_3 ( ! ( V_64 & V_87 ) ) ;
if ( V_64 == 0 ) {
struct V_59 * V_60 = V_94 -> V_59 ;
F_30 ( V_60 ) ;
if ( F_41 ( V_60 -> V_79 == NULL ) ) {
F_31 ( V_60 ) ;
F_39 ( V_60 ) ;
V_94 -> V_59 = NULL ;
if ( ! V_101 && ++ V_5 > 16 ) {
F_42 ( L_5 ,
V_85 -> V_86 ) ;
V_101 = true ;
}
goto V_102;
}
V_64 = V_87 ;
}
F_29 ( V_65 ) ;
return V_64 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_93 * V_94 )
{
int V_5 = 0 ;
bool V_101 = false ;
bool V_61 ;
int V_64 ;
do {
V_61 = false ;
V_64 = F_20 ( V_3 , V_94 -> V_59 , & V_61 ) ;
if ( ! V_101 && ++ V_5 > 16 ) {
F_42 ( L_6 ,
V_85 -> V_86 , V_94 -> V_96 ,
F_7 ( V_3 -> V_30 ) -> V_103 ) ;
V_101 = true ;
}
} while ( V_61 );
switch ( V_64 ) {
case 0 :
F_3 ( F_36 ( V_94 -> V_59 ) ) ;
V_64 = V_87 ;
break;
case - V_80 :
case - V_88 :
V_64 = V_89 ;
break;
case - V_90 :
V_64 = V_91 ;
break;
case - V_81 :
V_64 = V_100 ;
break;
default:
V_64 = V_92 ;
break;
}
return V_64 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_31 * V_31 = F_7 ( V_3 -> V_30 ) ;
struct V_104 * V_105 = F_45 ( V_31 ) ;
F_3 ( V_3 -> V_30 ) ;
F_3 ( F_46 ( & V_105 -> V_106 ) >= 0 ) ;
F_47 ( & V_105 -> V_106 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_31 * V_31 = F_7 ( V_3 -> V_30 ) ;
struct V_104 * V_105 = F_45 ( V_31 ) ;
F_3 ( V_3 -> V_30 ) ;
F_49 ( & V_105 -> V_106 ) ;
F_3 ( F_46 ( & V_105 -> V_106 ) >= 0 ) ;
}
int F_50 ( struct V_107 * V_79 , T_5 V_108 , T_5 V_109 )
{
int V_36 = - V_110 ;
F_51 ( V_109 > V_108 , L_7 , V_109 , V_108 ) ;
if ( F_52 ( V_79 ) ) {
V_36 = 0 ;
F_53 ( V_79 , V_108 + V_111 - 1 ,
V_109 - V_108 + 1 , 0 ) ;
}
return V_36 ;
}
int F_54 ( struct V_29 * V_29 , struct V_2 * V_3 )
{
struct V_31 * V_31 = F_7 ( V_29 ) ;
int V_36 ;
if ( F_8 ( V_29 ) )
return - V_37 ;
F_55 ( F_56 ( V_31 ) , V_112 , 1 ) ;
V_36 = F_57 ( V_29 , V_3 ) ;
if ( V_36 == 0 ) {
V_3 -> V_18 = & V_19 ;
V_3 -> V_18 -> V_113 ( V_3 ) ;
V_36 = F_58 ( V_31 ) ;
}
return V_36 ;
}
