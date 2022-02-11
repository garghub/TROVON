static inline char * F_1 ( struct V_1 * V_2 , char * V_3 )
{
char * V_4 = V_3 ;
* V_4 ++ = V_2 -> V_5 ? 'r' : 'w' ;
if ( V_2 -> V_6 )
* V_4 ++ = 'i' ;
if ( V_2 -> V_7 )
* V_4 ++ = 's' ;
if ( V_2 -> V_8 )
* V_4 ++ = 'h' ;
if ( V_2 -> V_9 )
* V_4 ++ = 'u' ;
if ( V_2 -> V_10 )
* V_4 ++ = 'm' ;
if ( V_2 -> V_11 )
* V_4 ++ = 't' ;
if ( V_2 -> V_12 )
* V_4 ++ = 'Y' ;
* V_4 = 0 ;
return V_3 ;
}
static inline char F_2 ( struct V_13 * V_14 )
{
return F_3 ( V_14 ) ? '-' : '+' ;
}
static inline struct V_1 * F_4 ( struct V_15 * V_16 )
{
if ( ! V_16 )
return NULL ;
return F_5 ( V_16 , struct V_1 , V_17 ) ;
}
static inline struct V_1 * F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
F_7 ( V_2 -> V_6 ) ;
return F_4 ( F_8 ( & V_2 -> V_17 ) ) ;
}
static inline struct V_1 * F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
F_7 ( V_2 -> V_6 ) ;
return F_4 ( F_10 ( & V_2 -> V_17 ) ) ;
}
static inline struct V_1 * F_11 ( struct V_18 * V_19 )
{
return F_4 ( F_12 ( & V_19 -> V_20 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const char * V_21 , const int line )
{
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_23 * V_24 ;
int V_25 ;
int V_26 = 0 ;
if ( ! F_14 ( V_19 ) ) {
V_26 = 9 ;
goto V_27;
}
if ( V_2 -> V_28 >= V_29 ) {
V_26 = 10 ;
goto V_27;
}
if ( F_15 ( & V_2 -> V_30 ) <= 0 ) {
V_26 = 20 ;
goto V_27;
}
if ( F_15 ( & V_2 -> V_30 ) < F_15 ( & V_2 -> V_31 ) ) {
V_26 = 30 ;
goto V_27;
}
switch ( V_2 -> V_28 ) {
case V_32 :
if ( V_2 -> V_33 > 0 || ! F_3 ( & V_2 -> V_34 ) )
V_26 = 35 ;
else
V_26 = 0 ;
goto V_27;
case V_35 :
if ( F_15 ( & V_2 -> V_31 ) == 0 ) {
V_26 = 40 ;
goto V_27;
}
if ( V_2 -> V_8 ) {
V_26 = 50 ;
goto V_27;
}
if ( V_2 -> V_12 && ! V_2 -> V_9 ) {
V_26 = 55 ;
goto V_27;
}
break;
case V_36 :
if ( V_2 -> V_37 == 0 ) {
V_26 = 60 ;
goto V_27;
}
if ( V_2 -> V_12 && ! V_2 -> V_9 && ! V_2 -> V_8 ) {
V_26 = 65 ;
goto V_27;
}
default:
if ( F_15 ( & V_2 -> V_31 ) > 0 ) {
V_26 = 70 ;
goto V_27;
}
}
if ( V_2 -> V_38 < V_2 -> V_39 || V_2 -> V_39 < V_2 -> V_40 ) {
V_26 = 80 ;
goto V_27;
}
if ( ! V_2 -> V_41 && V_2 -> V_37 > 0 ) {
V_26 = 90 ;
goto V_27;
}
if ( V_2 -> V_41 ) {
struct V_42 * V_43 ;
V_43 = & V_2 -> V_41 -> V_44 ;
if ( ! ( V_43 -> V_45 <= V_2 -> V_40 &&
V_43 -> V_46 >= V_2 -> V_38 ) ) {
V_26 = 100 ;
goto V_27;
}
}
if ( V_2 -> V_33 > V_2 -> V_47 ) {
V_26 = 105 ;
goto V_27;
}
if ( V_2 -> V_28 > V_36 ) {
V_26 = 0 ;
goto V_27;
}
if ( ! V_48 ) {
V_26 = 0 ;
goto V_27;
}
V_25 = 0 ;
F_16 (oap, &ext->oe_pages, oap_pending_item) {
T_1 V_49 = F_17 ( V_24 ) -> V_50 ;
++ V_25 ;
if ( V_49 > V_2 -> V_39 || V_49 < V_2 -> V_40 ) {
V_26 = 110 ;
goto V_27;
}
}
if ( V_25 != V_2 -> V_33 ) {
V_26 = 120 ;
goto V_27;
}
V_27:
if ( V_26 != 0 )
F_18 ( V_51 , V_2 ,
L_1 ,
V_21 , line , V_2 , V_26 ) ;
return V_26 ;
}
static int F_19 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_1 * V_52 ;
F_7 ( F_14 ( V_19 ) ) ;
if ( ! V_48 )
return 0 ;
for ( V_52 = F_11 ( V_19 ) ; V_52 ; V_52 = F_6 ( V_52 ) ) {
if ( V_52 == V_2 )
continue;
if ( V_52 -> V_39 >= V_2 -> V_40 &&
V_52 -> V_40 <= V_2 -> V_39 )
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , int V_53 )
{
F_7 ( F_14 ( V_2 -> V_22 ) ) ;
F_7 ( V_53 >= V_32 && V_53 < V_29 ) ;
V_2 -> V_28 = V_53 ;
F_21 ( & V_2 -> V_54 ) ;
}
static struct V_1 * F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_55 , V_56 ) ;
if ( ! V_2 )
return NULL ;
F_24 ( & V_2 -> V_17 ) ;
V_2 -> V_22 = V_19 ;
F_25 ( & V_2 -> V_30 , 1 ) ;
F_25 ( & V_2 -> V_31 , 0 ) ;
F_26 ( & V_2 -> V_57 ) ;
V_2 -> V_28 = V_32 ;
F_26 ( & V_2 -> V_34 ) ;
F_27 ( & V_2 -> V_54 ) ;
V_2 -> V_41 = NULL ;
return V_2 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_55 , V_2 ) ;
}
static struct V_1 * F_30 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_30 ) >= 0 ) ;
F_31 ( & V_2 -> V_30 ) ;
return V_2 ;
}
static void F_32 ( const struct V_58 * V_59 , struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_30 ) > 0 ) ;
if ( F_33 ( & V_2 -> V_30 ) ) {
F_7 ( F_3 ( & V_2 -> V_57 ) ) ;
F_7 ( F_15 ( & V_2 -> V_31 ) == 0 ) ;
F_7 ( V_2 -> V_28 == V_32 ) ;
F_7 ( ! V_2 -> V_6 ) ;
if ( V_2 -> V_41 ) {
F_34 ( V_59 , V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
F_28 ( V_2 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_30 ) > 1 ) ;
F_7 ( F_14 ( V_2 -> V_22 ) ) ;
F_36 ( & V_2 -> V_30 ) ;
}
static struct V_1 * F_37 ( struct V_18 * V_19 ,
T_1 V_49 )
{
struct V_15 * V_16 = V_19 -> V_20 . V_15 ;
struct V_1 * V_52 , * V_60 = NULL ;
F_7 ( F_14 ( V_19 ) ) ;
while ( V_16 ) {
V_52 = F_4 ( V_16 ) ;
if ( V_49 < V_52 -> V_40 ) {
V_16 = V_16 -> V_61 ;
} else if ( V_49 > V_52 -> V_39 ) {
V_60 = F_4 ( V_16 ) ;
V_16 = V_16 -> V_62 ;
} else {
return V_52 ;
}
}
return V_60 ;
}
static struct V_1 * F_38 ( struct V_18 * V_19 ,
T_1 V_49 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( V_19 , V_49 ) ;
if ( V_2 && V_2 -> V_40 <= V_49 && V_49 <= V_2 -> V_39 )
return F_30 ( V_2 ) ;
return NULL ;
}
static void F_39 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_15 * * V_16 = & V_19 -> V_20 . V_15 ;
struct V_15 * V_63 = NULL ;
struct V_1 * V_52 ;
F_7 ( V_2 -> V_6 == 0 ) ;
F_7 ( V_2 -> V_22 == V_19 ) ;
F_7 ( F_14 ( V_19 ) ) ;
while ( * V_16 ) {
V_52 = F_4 ( * V_16 ) ;
V_63 = * V_16 ;
if ( V_2 -> V_39 < V_52 -> V_40 )
V_16 = & ( * V_16 ) -> V_61 ;
else if ( V_2 -> V_40 > V_52 -> V_39 )
V_16 = & ( * V_16 ) -> V_62 ;
else
F_40 ( 0 , V_52 , V_64 L_2 , F_41 ( V_2 ) ) ;
}
F_42 ( & V_2 -> V_17 , V_63 , V_16 ) ;
F_43 ( & V_2 -> V_17 , & V_19 -> V_20 ) ;
F_30 ( V_2 ) ;
V_2 -> V_6 = 1 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
F_7 ( F_14 ( V_19 ) ) ;
if ( V_2 -> V_6 ) {
F_45 ( & V_2 -> V_17 , & V_19 -> V_20 ) ;
V_2 -> V_6 = 0 ;
F_35 ( V_2 ) ;
}
}
static struct V_1 * F_46 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
F_7 ( F_14 ( V_19 ) ) ;
F_7 ( V_2 -> V_28 == V_35 || V_2 -> V_28 == V_36 ) ;
if ( V_2 -> V_28 == V_36 ) {
F_20 ( V_2 , V_35 ) ;
F_47 ( V_19 , V_65 , - V_2 -> V_33 ) ;
}
F_31 ( & V_2 -> V_31 ) ;
F_48 ( & V_2 -> V_57 ) ;
return F_30 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_7 ( F_14 ( V_2 -> V_22 ) ) ;
F_7 ( F_3 ( & V_2 -> V_34 ) ) ;
F_44 ( V_2 ) ;
F_48 ( & V_2 -> V_57 ) ;
F_20 ( V_2 , V_32 ) ;
F_18 ( V_66 , V_2 , L_3 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
F_51 ( V_19 ) ;
F_49 ( V_2 ) ;
F_52 ( V_19 ) ;
}
static int F_53 ( const struct V_58 * V_59 , struct V_1 * V_67 ,
struct V_1 * V_68 )
{
struct V_18 * V_19 = V_67 -> V_22 ;
T_1 V_69 ;
T_1 V_70 ;
int V_71 ;
F_7 ( V_67 -> V_28 == V_36 ) ;
F_7 ( F_14 ( V_19 ) ) ;
if ( ! V_68 )
return - V_72 ;
if ( V_68 -> V_28 != V_36 || V_68 -> V_12 )
return - V_73 ;
if ( V_67 -> V_38 != V_68 -> V_38 )
return - V_74 ;
F_7 ( V_67 -> V_41 == V_68 -> V_41 ) ;
V_71 = F_54 ( V_19 ) -> V_75 - V_76 ;
V_69 = V_67 -> V_40 >> V_71 ;
V_70 = V_67 -> V_39 >> V_71 ;
if ( V_69 != ( V_68 -> V_39 >> V_71 ) + 1 &&
V_70 + 1 != V_68 -> V_40 >> V_71 )
return - V_74 ;
F_18 ( V_66 , V_68 , L_4 , V_67 ) ;
V_67 -> V_40 = F_55 ( V_67 -> V_40 , V_68 -> V_40 ) ;
V_67 -> V_39 = F_56 ( V_67 -> V_39 , V_68 -> V_39 ) ;
V_67 -> V_37 += V_68 -> V_37 ;
V_67 -> V_33 += V_68 -> V_33 ;
V_67 -> V_9 |= V_68 -> V_9 ;
V_67 -> V_10 |= V_68 -> V_10 ;
F_57 ( & V_68 -> V_34 , & V_67 -> V_34 ) ;
F_48 ( & V_68 -> V_57 ) ;
V_68 -> V_33 = 0 ;
F_30 ( V_68 ) ;
F_49 ( V_68 ) ;
F_32 ( V_59 , V_68 ) ;
F_18 ( V_66 , V_67 , L_5 , V_68 ) ;
return 0 ;
}
void F_58 ( const struct V_58 * V_59 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
F_7 ( F_15 ( & V_2 -> V_31 ) > 0 ) ;
F_7 ( F_59 ( V_2 ) == 0 ) ;
F_7 ( V_2 -> V_37 > 0 ) ;
if ( F_60 ( & V_2 -> V_31 , & V_19 -> V_77 ) ) {
F_7 ( V_2 -> V_28 == V_35 ) ;
if ( V_2 -> V_11 ) {
F_20 ( V_2 , V_78 ) ;
V_2 -> V_11 = 0 ;
} else {
F_20 ( V_2 , V_36 ) ;
F_47 ( V_19 , V_65 ,
V_2 -> V_33 ) ;
F_53 ( V_59 , V_2 , F_9 ( V_2 ) ) ;
F_53 ( V_59 , V_2 , F_6 ( V_2 ) ) ;
if ( V_2 -> V_9 )
F_61 ( & V_2 -> V_57 ,
& V_19 -> V_79 ) ;
}
F_52 ( V_19 ) ;
F_62 ( V_59 , F_54 ( V_19 ) , V_19 ) ;
}
F_32 ( V_59 , V_2 ) ;
}
static inline int F_63 ( struct V_1 * V_80 , struct V_1 * V_81 )
{
return ! ( V_80 -> V_39 < V_81 -> V_40 || V_81 -> V_39 < V_80 -> V_40 ) ;
}
static struct V_1 * F_64 ( const struct V_58 * V_59 ,
struct V_18 * V_19 , T_1 V_49 ,
int * V_82 )
{
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_85 * V_86 ;
struct V_1 * V_67 ;
struct V_1 * V_2 ;
struct V_1 * V_87 = NULL ;
struct V_1 * V_88 = NULL ;
T_1 V_89 ;
T_1 V_90 ;
int V_91 ;
int V_92 ;
int V_71 ;
int V_93 ;
int V_26 ;
V_67 = F_22 ( V_19 ) ;
if ( ! V_67 )
return F_65 ( - V_94 ) ;
V_86 = F_66 ( V_59 , F_67 ( V_19 ) , V_49 , NULL , 1 , 0 ) ;
F_7 ( V_86 -> V_44 . V_95 >= V_96 ) ;
F_7 ( V_84 -> V_75 >= V_76 ) ;
V_71 = V_84 -> V_75 - V_76 ;
V_93 = ~ ( ( 1 << V_71 ) - 1 ) ;
V_92 = 1 << V_84 -> V_75 ;
V_89 = V_49 >> V_71 ;
V_91 = V_84 -> V_97 ;
F_7 ( ( V_91 & ~ V_93 ) == 0 ) ;
V_90 = V_49 - ( V_49 % V_91 ) + V_91 - 1 ;
V_90 = F_68 ( T_1 , V_90 , V_86 -> V_44 . V_46 ) ;
V_67 -> V_38 = V_90 ;
V_67 -> V_40 = V_49 & V_93 ;
V_67 -> V_39 = ( ( V_49 + ~ V_93 + 1 ) & V_93 ) - 1 ;
if ( V_67 -> V_40 < V_86 -> V_44 . V_45 )
V_67 -> V_40 = V_86 -> V_44 . V_45 ;
if ( V_67 -> V_39 > V_90 )
V_67 -> V_39 = V_90 ;
V_67 -> V_41 = V_86 ;
V_67 -> V_37 = 0 ;
V_67 -> V_47 = V_91 ;
F_69 ( * V_82 >= V_92 + V_84 -> V_98 ,
L_6 , * V_82 , V_92 , V_84 -> V_98 ) ;
F_69 ( ( V_90 - V_67 -> V_40 ) < V_91 , V_64 L_2 ,
F_41 ( V_67 ) ) ;
V_99:
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_67 -> V_40 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_19 ) ;
while ( V_2 ) {
T_2 V_100 = V_2 -> V_40 >> V_71 ;
T_2 V_101 = V_2 -> V_39 >> V_71 ;
F_7 ( F_70 ( V_2 ) == 0 ) ;
if ( V_89 > V_101 + 1 )
break;
if ( V_86 != V_2 -> V_41 ) {
F_40 ( ! F_63 ( V_2 , V_67 ) , V_2 ,
V_64 L_2 , F_41 ( V_67 ) ) ;
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_89 + 1 < V_100 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( F_63 ( V_2 , V_67 ) ) {
F_40 ( ( V_2 -> V_40 <= V_67 -> V_40 &&
V_2 -> V_39 >= V_67 -> V_39 ) ,
V_2 , V_64 L_2 , F_41 ( V_67 ) ) ;
if ( V_2 -> V_28 > V_36 || V_2 -> V_12 ) {
V_87 = F_30 ( V_2 ) ;
break;
}
V_88 = F_46 ( V_2 ) ;
break;
}
if ( V_2 -> V_28 != V_36 || V_2 -> V_12 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_2 -> V_38 != V_90 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_89 + 1 == V_100 ) {
F_71 ( ( V_2 -> V_40 & ~ V_93 ) == 0 , V_2 ) ;
V_2 -> V_40 = V_67 -> V_40 ;
V_2 -> V_37 += V_92 ;
* V_82 -= V_92 ;
V_88 = F_46 ( V_2 ) ;
} else if ( V_89 == V_101 + 1 ) {
V_2 -> V_39 = V_67 -> V_39 ;
V_2 -> V_37 += V_92 ;
* V_82 -= V_92 ;
if ( F_53 ( V_59 , V_2 , F_6 ( V_2 ) ) == 0 )
* V_82 += V_84 -> V_98 ;
V_88 = F_46 ( V_2 ) ;
}
if ( V_88 )
break;
V_2 = F_6 ( V_2 ) ;
}
F_72 ( V_66 , V_19 ) ;
if ( V_88 ) {
F_7 ( ! V_87 ) ;
if ( ! F_73 ( V_88 ) ) {
F_7 ( V_88 -> V_41 == V_67 -> V_41 ) ;
F_18 ( V_66 , V_88 ,
L_7 , V_49 ) ;
}
} else if ( ! V_87 ) {
F_71 ( F_19 ( V_19 , V_67 ) == 0 , V_67 ) ;
V_67 -> V_37 = V_92 + V_84 -> V_98 ;
* V_82 -= V_67 -> V_37 ;
F_7 ( * V_82 >= 0 ) ;
V_67 -> V_28 = V_36 ;
V_88 = F_46 ( V_67 ) ;
F_39 ( V_19 , V_67 ) ;
F_18 ( V_66 , V_67 , L_8 ,
V_49 , V_86 -> V_44 . V_46 ) ;
}
F_52 ( V_19 ) ;
if ( V_87 ) {
F_7 ( ! V_88 ) ;
V_26 = F_74 ( V_59 , V_87 , V_32 ) ;
F_32 ( V_59 , V_87 ) ;
V_87 = NULL ;
if ( V_26 < 0 ) {
V_88 = F_65 ( V_26 ) ;
goto V_27;
}
goto V_99;
}
V_27:
F_32 ( V_59 , V_67 ) ;
F_7 ( * V_82 >= 0 ) ;
return V_88 ;
}
int F_75 ( const struct V_58 * V_59 , struct V_1 * V_2 ,
int V_102 , int V_26 )
{
struct V_83 * V_84 = F_54 ( V_2 -> V_22 ) ;
struct V_23 * V_24 ;
struct V_23 * V_52 ;
int V_103 = V_2 -> V_33 ;
int V_104 = 0 ;
int V_105 = V_84 -> V_106 -> V_107 -> V_108 . V_109 ? : 4096 ;
T_3 V_110 = 0 ;
int V_111 = - 1 ;
F_18 ( V_66 , V_2 , L_9 ) ;
V_2 -> V_112 = V_26 ? : V_2 -> V_33 ;
F_71 ( F_76 ( V_26 == 0 , V_2 -> V_28 == V_113 ) , V_2 ) ;
F_77 (oap, tmp, &ext->oe_pages, oap_pending_item) {
F_48 ( & V_24 -> V_114 ) ;
F_48 ( & V_24 -> V_115 ) ;
if ( V_110 <= V_24 -> V_116 ) {
V_110 = V_24 -> V_116 ;
V_111 = V_24 -> V_117 ;
}
-- V_2 -> V_33 ;
F_78 ( V_59 , V_84 , V_24 , V_102 , V_26 ) ;
}
F_71 ( V_2 -> V_33 == 0 , V_2 ) ;
if ( ! V_102 ) {
V_104 = V_2 -> V_37 ;
} else if ( V_105 < V_118 &&
V_111 != V_118 ) {
int V_119 = V_24 -> V_120 & ~ V_121 ;
int V_122 = V_24 -> V_117 + ( V_119 & ( V_105 - 1 ) ) ;
int V_123 = ( V_119 + V_24 -> V_117 ) & ( V_105 - 1 ) ;
if ( V_123 )
V_122 += V_105 - V_123 ;
V_104 = V_118 - V_122 ;
}
if ( V_2 -> V_37 > 0 )
F_79 ( V_84 , V_103 , V_104 ) ;
F_50 ( V_2 ) ;
F_32 ( V_59 , V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , int V_53 )
{
int V_124 ;
F_51 ( V_2 -> V_22 ) ;
V_124 = V_2 -> V_28 == V_53 ;
F_52 ( V_2 -> V_22 ) ;
return V_124 ;
}
static int F_74 ( const struct V_58 * V_59 , struct V_1 * V_2 ,
int V_53 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_125 V_126 = F_81 ( F_82 ( 600 ) , NULL ,
V_127 , NULL ) ;
int V_26 = 0 ;
F_51 ( V_19 ) ;
F_7 ( F_70 ( V_2 ) == 0 ) ;
if ( V_53 == V_32 && ! V_2 -> V_9 && ! V_2 -> V_8 &&
! V_2 -> V_11 ) {
if ( V_2 -> V_28 == V_35 ) {
V_2 -> V_9 = 1 ;
} else if ( V_2 -> V_28 == V_36 ) {
V_2 -> V_9 = 1 ;
F_46 ( V_2 ) ;
V_26 = 1 ;
}
}
F_52 ( V_19 ) ;
if ( V_26 == 1 )
F_58 ( V_59 , V_2 ) ;
V_26 = F_83 ( V_2 -> V_54 , F_80 ( V_2 , V_53 ) , & V_126 ) ;
if ( V_26 == - V_128 ) {
F_18 ( V_51 , V_2 ,
L_10 ,
F_84 ( V_19 ) -> V_129 -> V_130 , V_53 ) ;
V_126 = F_85 ( V_127 , NULL ) ;
V_26 = F_83 ( V_2 -> V_54 , F_80 ( V_2 , V_53 ) ,
& V_126 ) ;
}
if ( V_26 == 0 && V_2 -> V_112 < 0 )
V_26 = V_2 -> V_112 ;
return V_26 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_131 ,
bool V_132 )
{
struct V_133 V_134 ;
struct V_58 * V_59 ;
struct V_135 * V_136 ;
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_23 * V_24 ;
struct V_23 * V_52 ;
int V_137 = 0 ;
int V_71 = V_84 -> V_75 - V_76 ;
T_3 V_138 = V_131 >> V_71 ;
int V_82 = 0 ;
int V_103 = 0 ;
int V_26 = 0 ;
F_7 ( F_59 ( V_2 ) == 0 ) ;
F_71 ( V_2 -> V_28 == V_78 , V_2 ) ;
F_71 ( ! V_2 -> V_9 , V_2 ) ;
V_59 = F_87 ( & V_134 ) ;
V_136 = & F_88 ( V_59 ) -> V_139 ;
V_136 -> V_140 = F_89 ( F_67 ( V_19 ) ) ;
V_26 = F_90 ( V_59 , V_136 , V_141 , V_136 -> V_140 ) ;
if ( V_26 < 0 )
goto V_27;
F_77 (oap, tmp, &ext->oe_pages, oap_pending_item) {
struct V_142 * V_143 = F_17 ( V_24 ) ;
struct V_142 * V_144 = F_91 ( V_143 ) ;
F_7 ( F_3 ( & V_24 -> V_114 ) ) ;
if ( V_143 -> V_50 < V_131 ||
( V_143 -> V_50 == V_131 && V_132 ) ) {
if ( V_143 -> V_50 >> V_71 == V_138 )
++ V_137 ;
continue;
}
F_48 ( & V_24 -> V_115 ) ;
F_92 ( V_144 ) ;
F_93 ( & V_144 -> V_145 , L_11 , V_146 ) ;
if ( F_94 ( V_59 , V_136 , V_144 ) == 0 ) {
F_95 ( V_59 , V_136 , V_144 ) ;
F_96 ( V_59 , V_136 , V_144 ) ;
F_97 ( V_59 , V_136 , V_144 ) ;
} else {
F_7 ( V_144 -> V_147 == V_148 ) ;
F_7 ( 0 ) ;
}
F_98 ( & V_144 -> V_145 , L_11 , V_146 ) ;
F_99 ( V_59 , V_144 ) ;
-- V_2 -> V_33 ;
++ V_103 ;
}
F_40 ( F_76 ( V_2 -> V_40 >= V_131 + ! ! V_132 ,
V_2 -> V_33 == 0 ) ,
V_2 , L_12 , V_131 , V_132 ) ;
F_51 ( V_19 ) ;
if ( V_2 -> V_33 == 0 ) {
F_7 ( V_137 == 0 ) ;
V_82 = V_2 -> V_37 ;
V_2 -> V_37 = 0 ;
} else {
int V_149 = ( V_2 -> V_39 >> V_71 ) - V_138 ;
T_1 V_150 ;
if ( V_137 == 0 ) {
F_7 ( V_138 > 0 ) ;
-- V_138 ;
++ V_149 ;
}
V_82 = V_149 << V_84 -> V_75 ;
V_2 -> V_37 -= V_82 ;
V_150 = ( ( V_138 + 1 ) << V_71 ) - 1 ;
V_2 -> V_39 = F_55 ( V_150 , V_2 -> V_38 ) ;
F_7 ( V_2 -> V_39 >= V_2 -> V_40 ) ;
F_7 ( V_2 -> V_37 > 0 ) ;
}
F_52 ( V_19 ) ;
if ( V_82 > 0 || V_103 > 0 )
F_79 ( V_84 , V_103 , V_82 ) ;
V_27:
F_100 ( V_59 , V_136 ) ;
F_101 ( & V_134 , V_59 ) ;
return V_26 ;
}
static int F_102 ( const struct V_58 * V_59 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_23 * V_151 = NULL ;
struct V_18 * V_19 = V_2 -> V_22 ;
int V_25 = 0 ;
int V_26 ;
F_7 ( F_59 ( V_2 ) == 0 ) ;
F_71 ( V_2 -> V_28 == V_152 , V_2 ) ;
F_71 ( V_2 -> V_153 , V_2 ) ;
F_18 ( V_66 , V_2 , L_13 ) ;
F_16 (oap, &ext->oe_pages, oap_pending_item) {
++ V_25 ;
if ( ! V_151 || V_151 -> V_116 < V_24 -> V_116 )
V_151 = V_24 ;
if ( ( V_24 -> V_154 & V_155 ) != 0 )
continue;
V_26 = F_103 ( V_59 , V_24 , V_65 ) ;
switch ( V_26 ) {
case 0 :
F_104 ( & V_24 -> V_156 ) ;
V_24 -> V_154 |= V_155 ;
F_105 ( & V_24 -> V_156 ) ;
break;
case - V_157 :
F_7 ( ( V_24 -> V_154 & V_155 ) != 0 ) ;
break;
default:
F_69 ( 0 , L_14 , V_26 ) ;
}
}
F_7 ( V_25 == V_2 -> V_33 ) ;
F_7 ( V_151 ) ;
if ( ! ( V_151 -> V_154 & V_158 ) ) {
V_151 -> V_117 = F_106 ( V_59 , V_151 , V_65 ) ;
F_7 ( V_151 -> V_117 > 0 ) ;
F_7 ( V_151 -> V_120 + V_151 -> V_117 <= V_118 ) ;
V_151 -> V_154 |= V_158 ;
}
F_16 (oap, &ext->oe_pages, oap_pending_item) {
if ( ! ( V_24 -> V_154 & V_158 ) ) {
V_24 -> V_117 = V_118 - V_24 -> V_120 ;
V_24 -> V_154 |= V_158 ;
}
}
F_51 ( V_19 ) ;
F_20 ( V_2 , V_113 ) ;
F_52 ( V_19 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_49 , int * V_82 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_1 * V_159 ;
int V_71 = V_84 -> V_75 - V_76 ;
T_1 V_89 = V_49 >> V_71 ;
T_1 V_160 ;
T_1 V_161 ;
int V_92 = 1 << V_84 -> V_75 ;
int V_26 = 0 ;
F_7 ( V_2 -> V_38 >= V_49 && V_2 -> V_40 <= V_49 ) ;
F_51 ( V_19 ) ;
F_7 ( F_70 ( V_2 ) == 0 ) ;
V_160 = V_2 -> V_39 >> V_71 ;
if ( V_89 > V_160 + 1 ) {
V_26 = - V_74 ;
goto V_27;
}
if ( V_160 >= V_89 ) {
V_26 = 0 ;
goto V_27;
}
F_7 ( V_160 + 1 == V_89 ) ;
V_161 = F_55 ( V_2 -> V_38 , ( ( V_89 + 1 ) << V_71 ) - 1 ) ;
V_159 = F_6 ( V_2 ) ;
if ( V_159 && V_159 -> V_40 <= V_161 ) {
V_26 = - V_162 ;
goto V_27;
}
V_2 -> V_39 = V_161 ;
V_2 -> V_37 += V_92 ;
* V_82 -= V_92 ;
F_7 ( * V_82 >= 0 ) ;
F_40 ( F_19 ( V_19 , V_2 ) == 0 , V_2 ,
L_15 , V_49 ) ;
V_27:
F_52 ( V_19 ) ;
return V_26 ;
}
static void F_108 ( int V_163 , struct V_18 * V_19 ,
const char * V_21 , int line )
{
struct V_1 * V_2 ;
int V_164 ;
F_109 ( V_163 , L_16 ,
V_19 , V_21 , line , F_54 ( V_19 ) -> V_97 ) ;
V_164 = 1 ;
for ( V_2 = F_11 ( V_19 ) ; V_2 ; V_2 = F_6 ( V_2 ) )
F_18 ( V_163 , V_2 , L_17 , V_164 ++ ) ;
V_164 = 1 ;
F_16 (ext, &obj->oo_hp_exts, oe_link)
F_18 ( V_163 , V_2 , L_18 , V_164 ++ ) ;
V_164 = 1 ;
F_16 (ext, &obj->oo_urgent_exts, oe_link)
F_18 ( V_163 , V_2 , L_19 , V_164 ++ ) ;
V_164 = 1 ;
F_16 (ext, &obj->oo_reading_exts, oe_link)
F_18 ( V_163 , V_2 , L_20 , V_164 ++ ) ;
}
static inline int F_110 ( struct V_18 * V_165 )
{
return ! F_3 ( & V_165 -> V_166 ) ||
! F_3 ( & V_165 -> V_167 ) ;
}
static int F_103 ( const struct V_58 * V_59 , struct V_23 * V_24 ,
int V_168 )
{
struct V_169 * V_170 = F_111 ( V_24 ) ;
struct V_142 * V_144 = F_91 ( F_17 ( V_24 ) ) ;
int V_171 ;
F_7 ( V_168 == V_65 ) ;
V_171 = F_112 ( V_59 , V_144 , V_172 ) ;
if ( V_171 == 0 )
V_170 -> V_173 = F_113 () ;
return V_171 ;
}
static int F_106 ( const struct V_58 * V_59 ,
struct V_23 * V_24 , int V_168 )
{
struct V_169 * V_170 = F_111 ( V_24 ) ;
struct V_142 * V_144 = F_17 ( V_24 ) ;
struct V_174 * V_19 ;
struct V_175 * V_176 = & F_88 ( V_59 ) -> V_177 ;
int V_171 ;
T_2 V_178 ;
F_7 ( ! ( V_168 & V_179 ) ) ;
V_19 = V_170 -> V_180 . V_181 ;
F_114 ( V_19 ) ;
V_171 = F_115 ( V_59 , V_19 , V_176 ) ;
F_116 ( V_19 ) ;
if ( V_171 < 0 )
return V_171 ;
V_178 = V_176 -> V_182 ;
if ( F_117 ( V_19 , V_144 -> V_50 ) >= V_178 )
return 0 ;
else if ( F_117 ( V_19 , V_144 -> V_50 + 1 ) > V_178 )
return V_178 % V_118 ;
else
return V_118 ;
}
static int F_118 ( const struct V_58 * V_59 , struct V_23 * V_24 ,
int V_168 , int V_26 )
{
struct V_169 * V_170 = F_111 ( V_24 ) ;
struct V_142 * V_144 = F_91 ( F_17 ( V_24 ) ) ;
struct V_18 * V_19 = F_119 ( V_170 -> V_180 . V_181 ) ;
enum V_183 V_184 ;
int V_185 ;
V_168 &= ~ V_186 ;
F_7 ( F_120 ( V_144 -> V_147 == V_187 , V_168 == V_179 ) ) ;
F_7 ( F_120 ( V_144 -> V_147 == V_188 , V_168 == V_65 ) ) ;
F_7 ( V_170 -> V_189 ) ;
if ( V_144 -> V_190 )
F_121 ( V_59 , V_144 ) ;
F_7 ( ! V_144 -> V_190 ) ;
V_184 = V_168 == V_179 ? V_191 : V_172 ;
V_170 -> V_189 = 0 ;
F_104 ( & V_19 -> V_192 ) ;
F_7 ( V_170 -> V_193 ) ;
F_7 ( ! F_3 ( & V_170 -> V_194 ) ) ;
F_48 ( & V_170 -> V_194 ) ;
V_170 -> V_193 = NULL ;
F_105 ( & V_19 -> V_192 ) ;
V_170 -> V_173 = 0 ;
V_185 = V_24 -> V_195 & V_196 ;
if ( V_26 == 0 && V_185 ) {
struct V_197 * V_198 = V_170 -> V_180 . V_181 -> V_199 . V_200 ;
struct V_201 * V_202 = & F_122 ( V_198 ) -> V_203 ;
int V_204 = V_24 -> V_117 ;
if ( V_184 == V_191 )
V_202 -> V_205 += V_204 ;
else
V_202 -> V_206 += V_204 ;
}
F_98 ( & V_144 -> V_145 , L_21 , V_144 ) ;
F_123 ( V_59 , V_144 , V_184 , V_26 ) ;
return 0 ;
}
static void F_124 ( struct V_83 * V_84 ,
struct V_207 * V_208 )
{
F_125 ( & V_84 -> V_209 . V_86 ) ;
F_7 ( ! ( V_208 -> V_210 & V_211 ) ) ;
F_31 ( & V_212 ) ;
V_84 -> V_213 += V_118 ;
V_208 -> V_210 |= V_211 ;
F_109 ( V_66 , L_22 ,
V_118 , V_208 , V_208 -> V_214 ) ;
F_126 ( V_84 ) ;
}
static void F_127 ( struct V_83 * V_84 ,
struct V_207 * V_208 )
{
F_125 ( & V_84 -> V_209 . V_86 ) ;
if ( ! ( V_208 -> V_210 & V_211 ) ) {
return;
}
V_208 -> V_210 &= ~ V_211 ;
F_36 ( & V_212 ) ;
V_84 -> V_213 -= V_118 ;
if ( V_208 -> V_210 & V_215 ) {
V_208 -> V_210 &= ~ V_215 ;
F_36 ( & V_216 ) ;
V_84 -> V_217 -= V_118 ;
}
}
static int F_128 ( struct V_83 * V_84 , unsigned int V_204 )
{
int V_26 = - V_218 ;
if ( V_84 -> V_219 >= V_204 ) {
V_84 -> V_219 -= V_204 ;
V_84 -> V_220 += V_204 ;
V_26 = 0 ;
}
return V_26 ;
}
static void F_129 ( struct V_83 * V_84 ,
unsigned int V_221 , unsigned int V_222 )
{
V_84 -> V_220 -= V_221 ;
if ( V_222 > V_221 ) {
V_84 -> V_219 += V_221 ;
V_84 -> V_223 += V_222 - V_221 ;
} else {
V_84 -> V_219 += V_222 ;
}
}
static void F_130 ( struct V_83 * V_84 ,
unsigned int V_221 , unsigned int V_222 )
{
F_131 ( & V_84 -> V_209 ) ;
F_129 ( V_84 , V_221 , V_222 ) ;
if ( V_222 > 0 )
F_132 ( V_84 ) ;
F_133 ( & V_84 -> V_209 ) ;
}
static void F_79 ( struct V_83 * V_84 , unsigned int V_103 ,
unsigned int V_104 )
{
int V_224 = ( 1 << V_84 -> V_75 ) + V_84 -> V_98 ;
F_131 ( & V_84 -> V_209 ) ;
F_134 ( V_103 , & V_212 ) ;
V_84 -> V_213 -= V_103 << V_76 ;
V_84 -> V_223 += V_104 ;
if ( V_84 -> V_219 < V_224 && V_84 -> V_223 >= V_224 ) {
V_84 -> V_223 -= V_224 ;
V_84 -> V_219 += V_224 ;
}
F_132 ( V_84 ) ;
F_133 ( & V_84 -> V_209 ) ;
F_109 ( V_66 , L_23 ,
V_104 , V_84 -> V_223 ,
V_84 -> V_219 , V_84 -> V_213 ) ;
}
static void F_135 ( struct V_83 * V_84 , struct V_23 * V_24 )
{
F_131 ( & V_84 -> V_209 ) ;
F_127 ( V_84 , & V_24 -> V_225 ) ;
F_133 ( & V_84 -> V_209 ) ;
}
static int F_136 ( struct V_83 * V_84 ,
struct V_23 * V_24 ,
int V_204 , int V_226 )
{
int V_26 ;
F_137 ( V_84 , L_24 , V_204 ) ;
V_26 = F_128 ( V_84 , V_204 ) ;
if ( V_26 < 0 )
return 0 ;
if ( V_84 -> V_213 + V_118 <= V_84 -> V_227 &&
F_15 ( & V_212 ) + 1 <= V_228 ) {
F_124 ( V_84 , & V_24 -> V_225 ) ;
if ( V_226 ) {
V_84 -> V_217 += V_118 ;
F_31 ( & V_216 ) ;
V_24 -> V_195 |= V_215 ;
}
V_26 = 1 ;
} else {
F_129 ( V_84 , V_204 , V_204 ) ;
V_26 = 0 ;
}
return V_26 ;
}
static int F_138 ( struct V_83 * V_84 , struct V_229 * V_230 )
{
int V_26 ;
F_131 ( & V_84 -> V_209 ) ;
V_26 = F_3 ( & V_230 -> V_231 ) ;
F_133 ( & V_84 -> V_209 ) ;
return V_26 ;
}
static int F_139 ( const struct V_58 * V_59 , struct V_83 * V_84 ,
struct V_23 * V_24 , int V_204 )
{
struct V_18 * V_165 = V_24 -> V_232 ;
struct V_233 * V_234 = V_165 -> V_235 ;
struct V_229 V_230 ;
struct V_125 V_126 = F_85 ( V_127 , NULL ) ;
int V_26 = - V_218 ;
F_137 ( V_84 , L_24 , V_204 ) ;
F_131 ( & V_84 -> V_209 ) ;
if ( F_140 ( V_236 ) ||
V_84 -> V_227 < V_118 ||
V_84 -> V_237 . V_238 || V_234 -> V_239 . V_238 ) {
V_26 = - V_218 ;
goto V_27;
}
if ( F_136 ( V_84 , V_24 , V_204 , 0 ) ) {
V_26 = 0 ;
goto V_27;
}
F_27 ( & V_230 . V_240 ) ;
V_230 . V_241 = V_24 ;
V_230 . V_242 = V_204 ;
while ( V_84 -> V_213 > 0 || V_84 -> V_243 > 0 ) {
F_141 ( & V_230 . V_231 , & V_84 -> V_244 ) ;
V_230 . V_245 = 0 ;
F_133 ( & V_84 -> V_209 ) ;
F_62 ( V_59 , V_84 , NULL ) ;
F_109 ( V_66 , L_25 ,
V_84 -> V_106 -> V_107 -> V_130 , & V_230 , V_24 ) ;
V_26 = F_83 ( V_230 . V_240 , F_138 ( V_84 , & V_230 ) , & V_126 ) ;
F_131 ( & V_84 -> V_209 ) ;
if ( V_26 < 0 ) {
F_48 ( & V_230 . V_231 ) ;
goto V_27;
}
F_7 ( F_3 ( & V_230 . V_231 ) ) ;
V_26 = V_230 . V_245 ;
if ( V_26 != - V_218 )
goto V_27;
if ( F_136 ( V_84 , V_24 , V_204 , 0 ) ) {
V_26 = 0 ;
goto V_27;
}
}
V_27:
F_133 ( & V_84 -> V_209 ) ;
F_137 ( V_84 , L_26 , V_26 ) ;
return V_26 ;
}
void F_132 ( struct V_83 * V_84 )
{
struct V_13 * V_246 , * V_52 ;
struct V_229 * V_230 ;
F_142 (l, tmp, &cli->cl_cache_waiters) {
V_230 = F_143 ( V_246 , struct V_229 , V_231 ) ;
F_48 ( & V_230 -> V_231 ) ;
V_230 -> V_245 = - V_218 ;
if ( ( V_84 -> V_213 + V_118 > V_84 -> V_227 ) ||
( F_15 ( & V_212 ) + 1 >
V_228 ) ) {
F_109 ( V_66 , L_27 ,
V_84 -> V_213 ,
V_84 -> V_227 , V_228 ) ;
goto V_247;
}
V_230 -> V_245 = 0 ;
if ( ! F_136 ( V_84 , V_230 -> V_241 , V_230 -> V_242 , 0 ) )
V_230 -> V_245 = - V_218 ;
V_247:
F_109 ( V_66 , L_28 ,
V_230 , V_230 -> V_241 , V_84 -> V_219 , V_230 -> V_245 ) ;
F_144 ( & V_230 -> V_240 ) ;
}
}
static int F_145 ( struct V_83 * V_84 , struct V_18 * V_165 )
{
int V_248 = ! ! F_3 ( & V_165 -> V_249 ) ;
return F_146 ( V_84 ) >= V_84 -> V_250 + V_248 ;
}
static int F_147 ( struct V_83 * V_84 , struct V_18 * V_165 ,
int V_168 )
{
int V_251 = 0 ;
if ( ! V_84 -> V_106 || V_84 -> V_106 -> V_252 )
V_251 = 1 ;
if ( V_168 & V_65 ) {
if ( F_15 ( & V_165 -> V_253 ) == 0 )
return 0 ;
if ( V_251 ) {
F_109 ( V_66 , L_29 ) ;
return 1 ;
}
if ( ! F_3 ( & V_165 -> V_249 ) ) {
F_109 ( V_66 , L_30 ) ;
return 1 ;
}
if ( ! F_3 ( & V_165 -> V_79 ) ) {
F_109 ( V_66 , L_31 ) ;
return 1 ;
}
if ( ! F_3 ( & V_84 -> V_244 ) ) {
F_109 ( V_66 , L_32 ) ;
return 1 ;
}
if ( F_15 ( & V_165 -> V_253 ) >=
V_84 -> V_97 )
return 1 ;
} else {
if ( F_15 ( & V_165 -> V_254 ) == 0 )
return 0 ;
if ( V_251 ) {
F_109 ( V_66 , L_29 ) ;
return 1 ;
}
if ( ! F_3 ( & V_165 -> V_255 ) )
return 1 ;
}
return 0 ;
}
static void F_47 ( struct V_18 * V_19 , int V_168 , int V_256 )
{
struct V_83 * V_84 = F_54 ( V_19 ) ;
if ( V_168 & V_65 ) {
F_148 ( V_256 , & V_19 -> V_253 ) ;
F_148 ( V_256 , & V_84 -> V_257 ) ;
F_7 ( F_15 ( & V_19 -> V_253 ) >= 0 ) ;
} else {
F_148 ( V_256 , & V_19 -> V_254 ) ;
F_148 ( V_256 , & V_84 -> V_258 ) ;
F_7 ( F_15 ( & V_19 -> V_254 ) >= 0 ) ;
}
F_149 ( V_19 , L_33 , V_168 , V_256 ) ;
}
static int F_150 ( struct V_18 * V_19 )
{
return ! F_3 ( & V_19 -> V_249 ) ;
}
static void F_151 ( struct V_13 * V_259 , struct V_13 * V_14 , int V_260 )
{
if ( F_3 ( V_259 ) && V_260 )
F_141 ( V_259 , V_14 ) ;
else if ( ! F_3 ( V_259 ) && ! V_260 )
F_48 ( V_259 ) ;
}
static int F_152 ( struct V_83 * V_84 , struct V_18 * V_165 )
{
if ( F_150 ( V_165 ) ) {
F_151 ( & V_165 -> V_166 , & V_84 -> V_261 , 0 ) ;
F_151 ( & V_165 -> V_167 , & V_84 -> V_262 , 1 ) ;
} else {
F_151 ( & V_165 -> V_167 , & V_84 -> V_262 , 0 ) ;
F_151 ( & V_165 -> V_166 , & V_84 -> V_261 ,
F_147 ( V_84 , V_165 , V_65 ) ||
F_147 ( V_84 , V_165 , V_179 ) ) ;
}
F_151 ( & V_165 -> V_263 , & V_84 -> V_264 ,
F_15 ( & V_165 -> V_253 ) > 0 ) ;
F_151 ( & V_165 -> V_265 , & V_84 -> V_266 ,
F_15 ( & V_165 -> V_254 ) > 0 ) ;
return F_110 ( V_165 ) ;
}
static int F_153 ( struct V_83 * V_84 , struct V_18 * V_165 )
{
int V_267 ;
F_131 ( & V_84 -> V_209 ) ;
V_267 = F_152 ( V_84 , V_165 ) ;
F_133 ( & V_84 -> V_209 ) ;
return V_267 ;
}
static void F_154 ( struct V_268 * V_269 , T_3 V_270 ,
int V_26 )
{
if ( V_26 ) {
if ( ! V_269 -> V_271 )
V_269 -> V_271 = V_26 ;
V_269 -> V_238 = 1 ;
V_269 -> V_272 = F_155 () ;
return;
}
if ( V_269 -> V_238 && ( V_270 >= V_269 -> V_272 ) )
V_269 -> V_238 = 0 ;
}
static void F_78 ( const struct V_58 * V_59 , struct V_83 * V_84 ,
struct V_23 * V_24 , int V_102 , int V_26 )
{
struct V_18 * V_165 = V_24 -> V_232 ;
struct V_233 * V_234 = V_165 -> V_235 ;
T_3 V_270 = 0 ;
if ( V_24 -> V_273 ) {
V_270 = F_156 ( V_24 -> V_273 ) ;
F_157 ( V_24 -> V_273 ) ;
V_24 -> V_273 = NULL ;
}
F_104 ( & V_24 -> V_156 ) ;
V_24 -> V_154 = 0 ;
F_105 ( & V_24 -> V_156 ) ;
V_24 -> V_274 = 0 ;
if ( V_24 -> V_275 & V_65 && V_270 > 0 ) {
F_131 ( & V_84 -> V_209 ) ;
F_154 ( & V_84 -> V_237 , V_270 , V_26 ) ;
F_154 ( & V_234 -> V_239 , V_270 , V_26 ) ;
F_133 ( & V_84 -> V_209 ) ;
}
V_26 = F_118 ( V_59 , V_24 , V_24 -> V_275 , V_26 ) ;
if ( V_26 )
F_158 ( L_34 ,
V_24 , V_165 , V_26 ) ;
}
static int F_159 ( struct V_83 * V_84 ,
struct V_1 * V_2 , struct V_13 * V_276 ,
int * V_277 , unsigned int * V_91 )
{
struct V_1 * V_52 ;
struct V_23 * V_24 = F_160 ( & V_2 -> V_34 ,
struct V_23 ,
V_115 ) ;
F_71 ( ( V_2 -> V_28 == V_36 || V_2 -> V_28 == V_278 ) ,
V_2 ) ;
* V_91 = F_56 ( V_2 -> V_47 , * V_91 ) ;
if ( * V_277 + V_2 -> V_33 > * V_91 )
return 0 ;
F_16 (tmp, rpclist, oe_link) {
struct V_23 * V_279 ;
V_279 = F_160 ( & V_52 -> V_34 , struct V_23 ,
V_115 ) ;
F_71 ( V_52 -> V_153 == V_146 , V_52 ) ;
if ( F_17 ( V_24 ) -> V_280 != F_17 ( V_279 ) -> V_280 ) {
F_109 ( V_66 , L_35
L_36 ) ;
return 0 ;
}
if ( V_52 -> V_7 != V_2 -> V_7 ||
! V_52 -> V_37 != ! V_2 -> V_37 )
return 0 ;
break;
}
* V_277 += V_2 -> V_33 ;
F_61 ( & V_2 -> V_57 , V_276 ) ;
V_2 -> V_153 = V_146 ;
return 1 ;
}
static int F_161 ( struct V_18 * V_19 , struct V_13 * V_276 )
{
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_1 * V_281 ;
int V_25 = 0 ;
unsigned int V_91 = V_84 -> V_97 ;
F_7 ( F_14 ( V_19 ) ) ;
F_77 (ext, temp, &obj->oo_hp_exts, oe_link) {
F_7 ( V_2 -> V_28 == V_36 ) ;
if ( ! F_159 ( V_84 , V_2 , V_276 , & V_25 ,
& V_91 ) )
return V_25 ;
F_71 ( V_2 -> V_33 <= V_91 , V_2 ) ;
}
if ( V_25 == V_91 )
return V_25 ;
while ( ! F_3 ( & V_19 -> V_79 ) ) {
V_2 = F_143 ( V_19 -> V_79 . V_159 ,
struct V_1 , V_57 ) ;
if ( ! F_159 ( V_84 , V_2 , V_276 , & V_25 ,
& V_91 ) )
return V_25 ;
if ( ! V_2 -> V_6 )
continue;
while ( ( V_2 = F_6 ( V_2 ) ) != NULL ) {
if ( ( V_2 -> V_28 != V_36 ) ||
( ! F_3 ( & V_2 -> V_57 ) &&
V_2 -> V_153 ) )
continue;
if ( ! F_159 ( V_84 , V_2 , V_276 ,
& V_25 , & V_91 ) )
return V_25 ;
}
}
if ( V_25 == V_91 )
return V_25 ;
V_2 = F_11 ( V_19 ) ;
while ( V_2 ) {
if ( ( V_2 -> V_28 != V_36 ) ||
( ! F_3 ( & V_2 -> V_57 ) && V_2 -> V_153 ) ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( ! F_159 ( V_84 , V_2 , V_276 , & V_25 ,
& V_91 ) )
return V_25 ;
V_2 = F_6 ( V_2 ) ;
}
return V_25 ;
}
static int
F_162 ( const struct V_58 * V_59 , struct V_83 * V_84 ,
struct V_18 * V_165 )
__must_hold( V_165 )
{
F_163 ( V_276 ) ;
struct V_1 * V_2 ;
struct V_1 * V_52 ;
struct V_1 * V_282 = NULL ;
T_4 V_25 = 0 ;
int V_185 = 0 ;
int V_26 = 0 ;
F_7 ( F_14 ( V_165 ) ) ;
V_25 = F_161 ( V_165 , & V_276 ) ;
F_7 ( F_120 ( V_25 == 0 , F_3 ( & V_276 ) ) ) ;
if ( F_3 ( & V_276 ) )
return 0 ;
F_47 ( V_165 , V_65 , - V_25 ) ;
F_16 (ext, &rpclist, oe_link) {
F_7 ( V_2 -> V_28 == V_36 ||
V_2 -> V_28 == V_278 ) ;
if ( V_2 -> V_28 == V_36 )
F_20 ( V_2 , V_152 ) ;
else
F_20 ( V_2 , V_113 ) ;
}
F_52 ( V_165 ) ;
F_77 (ext, tmp, &rpclist, oe_link) {
if ( V_2 -> V_28 == V_152 ) {
V_26 = F_102 ( V_59 , V_2 ) ;
if ( F_164 ( V_26 < 0 ) ) {
F_48 ( & V_2 -> V_57 ) ;
F_75 ( V_59 , V_2 , 0 , V_26 ) ;
continue;
}
}
if ( ! V_282 ) {
V_282 = V_2 ;
V_185 = V_2 -> V_7 ;
} else {
F_7 ( V_185 == V_2 -> V_7 ) ;
}
}
if ( ! F_3 ( & V_276 ) ) {
F_7 ( V_25 > 0 ) ;
V_26 = F_165 ( V_59 , V_84 , & V_276 , V_65 ) ;
F_7 ( F_3 ( & V_276 ) ) ;
}
F_51 ( V_165 ) ;
return V_26 ;
}
static int
F_166 ( const struct V_58 * V_59 , struct V_83 * V_84 ,
struct V_18 * V_165 )
__must_hold( V_165 )
{
struct V_1 * V_2 ;
struct V_1 * V_159 ;
F_163 ( V_276 ) ;
int V_25 = 0 ;
unsigned int V_91 = V_84 -> V_97 ;
int V_26 = 0 ;
F_7 ( F_14 ( V_165 ) ) ;
F_77 (ext, next, &osc->oo_reading_exts, oe_link) {
F_71 ( V_2 -> V_28 == V_278 , V_2 ) ;
if ( ! F_159 ( V_84 , V_2 , & V_276 , & V_25 ,
& V_91 ) )
break;
F_20 ( V_2 , V_113 ) ;
F_71 ( V_2 -> V_33 <= V_91 , V_2 ) ;
}
F_7 ( V_25 <= V_91 ) ;
F_47 ( V_165 , V_179 , - V_25 ) ;
if ( ! F_3 ( & V_276 ) ) {
F_52 ( V_165 ) ;
F_7 ( V_25 > 0 ) ;
V_26 = F_165 ( V_59 , V_84 , & V_276 , V_179 ) ;
F_7 ( F_3 ( & V_276 ) ) ;
F_51 ( V_165 ) ;
}
return V_26 ;
}
static struct V_18 * F_167 ( struct V_83 * V_84 )
{
if ( ! F_3 ( & V_84 -> V_262 ) )
return F_168 ( & V_84 -> V_262 , V_283 ) ;
if ( ! F_3 ( & V_84 -> V_261 ) )
return F_168 ( & V_84 -> V_261 , V_284 ) ;
if ( ! F_3 ( & V_84 -> V_244 ) &&
! F_3 ( & V_84 -> V_264 ) )
return F_168 ( & V_84 -> V_264 , V_285 ) ;
if ( ! V_84 -> V_106 || V_84 -> V_106 -> V_252 ) {
if ( ! F_3 ( & V_84 -> V_264 ) )
return F_168 ( & V_84 -> V_264 , V_285 ) ;
if ( ! F_3 ( & V_84 -> V_266 ) )
return F_168 ( & V_84 -> V_266 , V_286 ) ;
}
return NULL ;
}
static void F_169 ( const struct V_58 * V_59 , struct V_83 * V_84 )
__must_hold( &cli->cl_loi_list_lock
static int F_170 ( const struct V_58 * V_59 , struct V_83 * V_84 ,
struct V_18 * V_165 , int V_287 )
{
int V_26 = 0 ;
if ( V_165 && F_153 ( V_84 , V_165 ) == 0 )
return 0 ;
if ( ! V_287 ) {
F_31 ( & V_84 -> V_288 ) ;
F_131 ( & V_84 -> V_209 ) ;
F_169 ( V_59 , V_84 ) ;
F_133 ( & V_84 -> V_209 ) ;
F_36 ( & V_84 -> V_288 ) ;
} else {
F_109 ( V_66 , L_37 , V_84 ) ;
F_7 ( V_84 -> V_289 ) ;
V_26 = F_171 ( V_84 -> V_289 ) ;
}
return V_26 ;
}
static int F_62 ( const struct V_58 * V_59 ,
struct V_83 * V_84 , struct V_18 * V_165 )
{
return F_170 ( V_59 , V_84 , V_165 , 1 ) ;
}
void F_172 ( const struct V_58 * V_59 , struct V_83 * V_84 ,
struct V_18 * V_165 )
{
( void ) F_170 ( V_59 , V_84 , V_165 , 0 ) ;
}
int F_173 ( struct V_18 * V_165 , struct V_169 * V_290 ,
struct V_144 * V_144 , T_2 V_119 )
{
struct V_291 * exp = F_84 ( V_165 ) ;
struct V_23 * V_24 = & V_290 -> V_292 ;
if ( ! V_144 )
return F_174 ( sizeof( * V_24 ) ) ;
V_24 -> V_293 = V_294 ;
V_24 -> V_295 = & exp -> V_129 -> V_296 . V_84 ;
V_24 -> V_232 = V_165 ;
V_24 -> V_297 = V_144 ;
V_24 -> V_116 = V_119 ;
F_7 ( ! ( V_119 & ~ V_121 ) ) ;
if ( ! F_175 ( exp ) && F_176 ( V_298 ) )
V_24 -> V_195 = V_186 ;
F_26 ( & V_24 -> V_115 ) ;
F_26 ( & V_24 -> V_114 ) ;
F_177 ( & V_24 -> V_156 ) ;
F_109 ( V_299 , L_38 ,
V_24 , V_144 , V_24 -> V_116 ) ;
return 0 ;
}
int F_178 ( const struct V_58 * V_59 , struct V_135 * V_136 ,
struct V_169 * V_290 )
{
struct V_300 * V_301 = F_179 ( V_59 ) ;
struct V_1 * V_2 = NULL ;
struct V_23 * V_24 = & V_290 -> V_292 ;
struct V_83 * V_84 = V_24 -> V_295 ;
struct V_18 * V_165 = V_24 -> V_232 ;
T_1 V_49 ;
int V_82 = 0 ;
int V_302 = V_303 ;
int V_168 = V_65 ;
int V_304 = 0 ;
int V_26 = 0 ;
if ( V_24 -> V_293 != V_294 )
return - V_72 ;
if ( ! V_84 -> V_106 || V_84 -> V_106 -> V_252 )
return - V_305 ;
if ( ! F_3 ( & V_24 -> V_115 ) ||
! F_3 ( & V_24 -> V_114 ) )
return - V_73 ;
V_302 |= V_290 -> V_306 ? V_196 : 0 ;
if ( ! F_175 ( F_84 ( V_165 ) ) &&
F_176 ( V_298 ) ) {
V_302 |= V_186 ;
V_168 |= V_186 ;
}
if ( ! ( V_168 & V_186 ) ) {
struct V_174 * V_19 ;
struct V_175 * V_176 ;
unsigned int V_307 [ V_308 ] ;
V_19 = F_89 ( & V_165 -> V_309 ) ;
V_176 = & F_88 ( V_59 ) -> V_177 ;
F_114 ( V_19 ) ;
V_26 = F_115 ( V_59 , V_19 , V_176 ) ;
F_116 ( V_19 ) ;
V_307 [ V_310 ] = V_176 -> V_311 ;
V_307 [ V_312 ] = V_176 -> V_313 ;
if ( V_26 == 0 && F_180 ( V_84 , V_307 ) == V_314 )
V_26 = - V_218 ;
if ( V_26 )
return V_26 ;
}
V_24 -> V_275 = V_168 ;
V_24 -> V_120 = V_290 -> V_315 ;
V_24 -> V_117 = V_290 -> V_316 - V_290 -> V_315 ;
V_24 -> V_154 = 0 ;
V_24 -> V_195 = V_302 ;
F_149 ( V_165 , L_39 ,
V_24 , V_24 -> V_297 , V_24 -> V_275 & V_317 ) ;
V_49 = F_17 ( V_24 ) -> V_50 ;
V_2 = V_301 -> V_318 ;
if ( V_2 && V_2 -> V_40 <= V_49 && V_2 -> V_38 >= V_49 ) {
V_82 = ( 1 << V_84 -> V_75 ) + V_84 -> V_98 ;
if ( V_2 -> V_39 >= V_49 )
V_82 = 0 ;
F_131 ( & V_84 -> V_209 ) ;
V_26 = F_136 ( V_84 , V_24 , V_82 , 0 ) ;
F_133 ( & V_84 -> V_209 ) ;
if ( V_26 == 0 ) {
V_82 = 0 ;
V_304 = 1 ;
} else if ( V_2 -> V_39 < V_49 ) {
int V_52 = V_82 ;
V_26 = F_107 ( V_2 , V_49 , & V_52 ) ;
if ( V_26 < 0 ) {
V_304 = 1 ;
} else {
F_18 ( V_66 , V_2 ,
L_40 , V_49 ) ;
F_130 ( V_84 , V_82 , V_52 ) ;
V_82 = 0 ;
}
}
V_26 = 0 ;
} else if ( V_2 ) {
V_304 = 1 ;
}
if ( V_304 ) {
F_58 ( V_59 , V_2 ) ;
V_301 -> V_318 = NULL ;
V_2 = NULL ;
}
if ( ! V_2 ) {
int V_52 = ( 1 << V_84 -> V_75 ) + V_84 -> V_98 ;
F_7 ( ! V_301 -> V_318 ) ;
F_7 ( F_76 ( V_82 > 0 , V_82 >= V_52 ) ) ;
V_26 = 0 ;
if ( V_82 == 0 ) {
V_26 = F_139 ( V_59 , V_84 , V_24 , V_52 ) ;
if ( V_26 == 0 )
V_82 = V_52 ;
}
V_52 = V_82 ;
if ( V_26 == 0 ) {
V_2 = F_64 ( V_59 , V_165 , V_49 , & V_52 ) ;
if ( F_73 ( V_2 ) ) {
F_7 ( V_52 == V_82 ) ;
F_135 ( V_84 , V_24 ) ;
V_26 = F_181 ( V_2 ) ;
V_2 = NULL ;
} else {
V_301 -> V_318 = V_2 ;
}
}
if ( V_82 > 0 )
F_130 ( V_84 , V_82 , V_52 ) ;
}
F_7 ( F_76 ( V_26 == 0 , V_2 ) ) ;
if ( V_2 ) {
F_40 ( V_2 -> V_39 >= V_49 && V_2 -> V_40 <= V_49 ,
V_2 , L_41 , V_49 ) ;
F_7 ( ( V_24 -> V_195 & V_211 ) != 0 ) ;
F_51 ( V_165 ) ;
if ( V_2 -> V_33 == 0 )
V_2 -> V_7 = V_290 -> V_306 ;
else
F_7 ( V_2 -> V_7 == V_290 -> V_306 ) ;
++ V_2 -> V_33 ;
F_141 ( & V_24 -> V_115 , & V_2 -> V_34 ) ;
F_52 ( V_165 ) ;
}
return V_26 ;
}
int F_182 ( const struct V_58 * V_59 ,
struct V_18 * V_19 , struct V_169 * V_290 )
{
struct V_23 * V_24 = & V_290 -> V_292 ;
struct V_1 * V_2 = NULL ;
int V_26 = 0 ;
F_7 ( V_24 -> V_293 == V_294 ) ;
F_109 ( V_299 , L_42 ,
V_24 , V_290 , F_17 ( V_24 ) -> V_50 ) ;
F_51 ( V_19 ) ;
if ( ! F_3 ( & V_24 -> V_114 ) ) {
F_109 ( V_66 , L_43 , V_24 ) ;
V_26 = - V_73 ;
} else if ( ! F_3 ( & V_24 -> V_115 ) ) {
V_2 = F_38 ( V_19 , F_17 ( V_24 ) -> V_50 ) ;
if ( V_2 && V_2 -> V_28 != V_78 ) {
F_18 ( V_51 , V_2 , L_44 ,
F_17 ( V_24 ) -> V_50 ) ;
V_26 = - V_73 ;
}
}
F_52 ( V_19 ) ;
if ( V_2 )
F_32 ( V_59 , V_2 ) ;
return V_26 ;
}
int F_183 ( const struct V_58 * V_59 , struct V_135 * V_136 ,
struct V_169 * V_290 )
{
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 = F_119 ( V_290 -> V_180 . V_181 ) ;
struct V_142 * V_319 = V_290 -> V_180 . V_320 ;
T_1 V_49 = V_319 -> V_50 ;
struct V_23 * V_24 = & V_290 -> V_292 ;
bool V_321 = false ;
int V_26 = 0 ;
F_51 ( V_19 ) ;
V_2 = F_38 ( V_19 , V_49 ) ;
if ( ! V_2 ) {
F_72 ( V_51 , V_19 ) ;
F_69 ( 0 , L_45 , V_49 ) ;
}
switch ( V_2 -> V_28 ) {
case V_113 :
case V_278 :
F_184 ( V_51 , V_59 , F_91 ( V_319 ) ,
L_46 ) ;
F_7 ( 0 ) ;
break;
case V_152 :
case V_78 :
case V_35 :
V_26 = - V_162 ;
goto V_27;
default:
break;
}
V_26 = F_185 ( V_59 , V_136 , F_91 ( V_319 ) , V_172 ) ;
if ( V_26 )
goto V_27;
F_104 ( & V_24 -> V_156 ) ;
V_24 -> V_154 |= V_155 | V_322 ;
F_105 ( & V_24 -> V_156 ) ;
if ( F_186 () )
V_2 -> V_10 = 1 ;
V_2 -> V_9 = 1 ;
if ( V_2 -> V_28 == V_36 ) {
F_18 ( V_66 , V_2 ,
L_47 , V_24 ) ;
if ( F_3 ( & V_2 -> V_57 ) )
F_141 ( & V_2 -> V_57 , & V_19 -> V_79 ) ;
V_321 = true ;
}
V_26 = 0 ;
V_27:
F_52 ( V_19 ) ;
F_32 ( V_59 , V_2 ) ;
if ( V_321 )
F_62 ( V_59 , F_54 ( V_19 ) , V_19 ) ;
return V_26 ;
}
int F_187 ( const struct V_58 * V_59 , struct V_169 * V_290 )
{
struct V_23 * V_24 = & V_290 -> V_292 ;
struct V_18 * V_19 = V_24 -> V_232 ;
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_1 * V_88 = NULL ;
struct V_13 * V_323 ;
T_1 V_49 = F_17 ( V_24 ) -> V_50 ;
int V_26 = - V_73 ;
int V_168 ;
F_7 ( ! V_24 -> V_274 ) ;
V_24 -> V_274 = 1 ;
F_51 ( V_19 ) ;
if ( V_24 -> V_275 & V_65 ) {
V_323 = & V_19 -> V_79 ;
V_168 = V_65 ;
} else {
V_323 = & V_19 -> V_255 ;
V_168 = V_179 ;
}
F_16 (ext, plist, oe_link) {
if ( V_2 -> V_40 <= V_49 && V_2 -> V_39 >= V_49 ) {
F_7 ( V_2 -> V_28 == V_278 ) ;
V_88 = F_30 ( V_2 ) ;
break;
}
}
if ( V_88 ) {
F_48 ( & V_88 -> V_57 ) ;
F_47 ( V_19 , V_168 , - V_88 -> V_33 ) ;
F_52 ( V_19 ) ;
F_75 ( V_59 , V_88 , 0 , - V_324 ) ;
F_32 ( V_59 , V_88 ) ;
V_26 = 0 ;
} else {
F_52 ( V_19 ) ;
if ( V_24 -> V_273 ) {
F_188 ( V_24 -> V_273 ) ;
F_189 ( V_24 -> V_273 ) ;
F_157 ( V_24 -> V_273 ) ;
V_24 -> V_273 = NULL ;
}
}
F_153 ( V_84 , V_19 ) ;
return V_26 ;
}
int F_190 ( const struct V_58 * V_59 , struct V_18 * V_19 ,
struct V_13 * V_14 , int V_168 , int V_302 )
{
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_23 * V_24 , * V_52 ;
int V_25 = 0 ;
int V_325 = V_84 -> V_97 ;
T_1 V_326 = V_327 ;
T_1 V_123 = 0 ;
F_16 (oap, list, oap_pending_item) {
struct V_142 * V_319 = F_17 ( V_24 ) ;
if ( V_319 -> V_50 > V_123 )
V_123 = V_319 -> V_50 ;
if ( V_319 -> V_50 < V_326 )
V_326 = V_319 -> V_50 ;
++ V_25 ;
V_325 <<= ( V_25 > V_325 ) ;
}
V_2 = F_22 ( V_19 ) ;
if ( ! V_2 ) {
F_77 (oap, tmp, list, oap_pending_item) {
F_48 ( & V_24 -> V_115 ) ;
F_78 ( V_59 , V_84 , V_24 , 0 , - V_94 ) ;
}
return - V_94 ;
}
V_2 -> V_5 = ! ! ( V_168 & V_179 ) ;
V_2 -> V_9 = 1 ;
V_2 -> V_40 = V_326 ;
V_2 -> V_39 = V_2 -> V_38 = V_123 ;
V_2 -> V_22 = V_19 ;
V_2 -> V_7 = ! ! ( V_302 & V_196 ) ;
V_2 -> V_33 = V_25 ;
V_2 -> V_47 = V_325 ;
F_57 ( V_14 , & V_2 -> V_34 ) ;
F_51 ( V_19 ) ;
F_20 ( V_2 , V_278 ) ;
if ( V_168 & V_65 ) {
F_141 ( & V_2 -> V_57 , & V_19 -> V_79 ) ;
F_47 ( V_19 , V_65 , V_25 ) ;
} else {
F_141 ( & V_2 -> V_57 , & V_19 -> V_255 ) ;
F_47 ( V_19 , V_179 , V_25 ) ;
}
F_52 ( V_19 ) ;
F_62 ( V_59 , V_84 , V_19 ) ;
return 0 ;
}
int F_191 ( const struct V_58 * V_59 , struct V_300 * V_301 ,
struct V_18 * V_19 , T_3 V_328 )
{
struct V_83 * V_84 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_1 * V_281 ;
struct V_1 * V_329 = NULL ;
T_1 V_49 ;
F_163 ( V_14 ) ;
int V_171 = 0 ;
bool V_132 ;
V_49 = F_192 ( F_67 ( V_19 ) , V_328 ) ;
V_132 = V_328 > F_117 ( F_67 ( V_19 ) , V_49 ) ;
V_330:
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_49 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_19 ) ;
else if ( V_2 -> V_39 < V_49 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
F_71 ( V_2 -> V_28 != V_78 , V_2 ) ;
if ( V_2 -> V_28 > V_36 || V_2 -> V_9 ) {
F_7 ( ! V_2 -> V_8 ) ;
F_18 ( V_66 , V_2 ,
L_48 ) ;
V_329 = F_30 ( V_2 ) ;
break;
}
F_18 ( V_66 , V_2 , L_49 , V_328 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_28 == V_35 ) {
F_7 ( ! V_2 -> V_11 ) ;
V_2 -> V_11 = 1 ;
} else {
F_71 ( V_2 -> V_28 == V_36 , V_2 ) ;
F_20 ( V_2 , V_78 ) ;
F_47 ( V_19 , V_65 ,
- V_2 -> V_33 ) ;
}
F_71 ( F_3 ( & V_2 -> V_57 ) , V_2 ) ;
F_141 ( & V_2 -> V_57 , & V_14 ) ;
V_2 = F_6 ( V_2 ) ;
}
F_52 ( V_19 ) ;
F_153 ( V_84 , V_19 ) ;
F_77 (ext, temp, &list, oe_link) {
int V_26 ;
F_48 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_28 != V_78 )
F_74 ( V_59 , V_2 , V_78 ) ;
V_26 = F_86 ( V_2 , V_49 , V_132 ) ;
if ( V_26 < 0 ) {
if ( V_171 == 0 )
V_171 = V_26 ;
F_18 ( V_51 , V_2 ,
L_50 , V_26 ) ;
} else if ( V_2 -> V_33 == 0 ) {
F_50 ( V_2 ) ;
} else {
F_40 ( V_2 -> V_40 <= V_49 , V_2 ,
L_51 , V_49 , V_132 ) ;
V_49 = V_2 -> V_39 + 1 ;
V_132 = false ;
F_7 ( ! V_301 -> V_331 ) ;
V_301 -> V_331 = F_30 ( V_2 ) ;
F_18 ( V_66 , V_2 ,
L_52 , V_328 ) ;
}
F_32 ( V_59 , V_2 ) ;
}
if ( V_329 ) {
int V_26 ;
V_26 = F_74 ( V_59 , V_329 , V_32 ) ;
if ( V_26 < 0 )
F_18 ( V_66 , V_329 , L_53 , V_26 ) ;
F_32 ( V_59 , V_329 ) ;
V_329 = NULL ;
goto V_330;
}
return V_171 ;
}
void F_193 ( const struct V_58 * V_59 , struct V_300 * V_301 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_301 -> V_331 ;
V_301 -> V_331 = NULL ;
if ( V_2 ) {
bool V_321 = false ;
F_71 ( V_2 -> V_33 > 0 , V_2 ) ;
F_71 ( V_2 -> V_28 == V_78 , V_2 ) ;
F_71 ( ! V_2 -> V_9 , V_2 ) ;
F_18 ( V_66 , V_2 , L_54 ) ;
F_51 ( V_19 ) ;
F_20 ( V_2 , V_36 ) ;
if ( V_2 -> V_12 && ! V_2 -> V_9 ) {
V_2 -> V_9 = 1 ;
F_61 ( & V_2 -> V_57 , & V_19 -> V_79 ) ;
V_321 = true ;
}
F_47 ( V_19 , V_65 , V_2 -> V_33 ) ;
F_52 ( V_19 ) ;
F_32 ( V_59 , V_2 ) ;
if ( V_321 )
F_62 ( V_59 , F_54 ( V_19 ) , V_19 ) ;
}
}
int F_194 ( const struct V_58 * V_59 , struct V_18 * V_19 ,
T_1 V_326 , T_1 V_123 )
{
struct V_1 * V_2 ;
T_1 V_49 = V_326 ;
int V_171 = 0 ;
V_330:
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_49 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_19 ) ;
else if ( V_2 -> V_39 < V_49 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
int V_26 ;
if ( V_2 -> V_40 > V_123 )
break;
if ( ! V_2 -> V_12 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
F_71 ( F_76 ( V_2 -> V_28 == V_36 ,
V_2 -> V_8 || V_2 -> V_9 ) , V_2 ) ;
F_71 ( F_76 ( V_2 -> V_28 == V_35 ,
! V_2 -> V_8 && V_2 -> V_9 ) , V_2 ) ;
V_49 = V_2 -> V_39 + 1 ;
F_30 ( V_2 ) ;
F_52 ( V_19 ) ;
V_26 = F_74 ( V_59 , V_2 , V_32 ) ;
if ( V_171 == 0 )
V_171 = V_26 ;
F_32 ( V_59 , V_2 ) ;
goto V_330;
}
F_52 ( V_19 ) ;
F_149 ( V_19 , L_55 ) ;
return V_171 ;
}
int F_195 ( const struct V_58 * V_59 , struct V_18 * V_19 ,
T_1 V_326 , T_1 V_123 , int V_332 , int V_333 )
{
struct V_1 * V_2 ;
F_163 ( V_334 ) ;
bool V_321 = false ;
int V_171 = 0 ;
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_326 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_19 ) ;
else if ( V_2 -> V_39 < V_326 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
if ( V_2 -> V_40 > V_123 )
break;
V_2 -> V_12 = 1 ;
switch ( V_2 -> V_28 ) {
case V_36 :
V_171 += V_2 -> V_33 ;
if ( ! V_333 ) {
struct V_13 * V_14 = NULL ;
if ( V_332 ) {
F_71 ( ! V_2 -> V_8 , V_2 ) ;
V_2 -> V_8 = 1 ;
V_14 = & V_19 -> V_249 ;
} else if ( ! V_2 -> V_9 ) {
V_2 -> V_9 = 1 ;
V_14 = & V_19 -> V_79 ;
}
if ( V_14 )
F_61 ( & V_2 -> V_57 , V_14 ) ;
V_321 = true ;
} else {
F_71 ( V_2 -> V_40 >= V_326 &&
V_2 -> V_38 <= V_123 , V_2 ) ;
F_20 ( V_2 , V_152 ) ;
V_2 -> V_153 = V_146 ;
F_61 ( & V_2 -> V_57 , & V_334 ) ;
F_47 ( V_19 , V_65 ,
- V_2 -> V_33 ) ;
}
break;
case V_35 :
F_7 ( V_332 == 0 && V_333 == 0 ) ;
V_2 -> V_9 = 1 ;
break;
case V_78 :
default:
break;
}
V_2 = F_6 ( V_2 ) ;
}
F_52 ( V_19 ) ;
F_7 ( F_76 ( ! V_333 , F_3 ( & V_334 ) ) ) ;
if ( ! F_3 ( & V_334 ) ) {
struct V_1 * V_52 ;
int V_26 ;
F_153 ( F_54 ( V_19 ) , V_19 ) ;
F_77 (ext, tmp, &discard_list, oe_link) {
F_48 ( & V_2 -> V_57 ) ;
F_71 ( V_2 -> V_28 == V_152 , V_2 ) ;
V_26 = F_102 ( V_59 , V_2 ) ;
if ( F_164 ( V_26 < 0 ) ) {
F_18 ( V_51 , V_2 ,
L_56 , V_26 ) ;
if ( V_171 >= 0 )
V_171 = V_26 ;
}
F_75 ( V_59 , V_2 , 0 , 0 ) ;
}
}
if ( V_321 )
F_172 ( V_59 , F_54 ( V_19 ) , V_19 ) ;
if ( V_332 || V_333 ) {
int V_26 ;
V_26 = F_194 ( V_59 , V_19 , V_326 , V_123 ) ;
if ( V_171 >= 0 && V_26 < 0 )
V_171 = V_26 ;
}
F_149 ( V_19 , L_57 ) ;
return V_171 ;
}
