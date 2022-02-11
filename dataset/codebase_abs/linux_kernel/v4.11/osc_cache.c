static inline char * F_1 ( struct V_1 * V_2 , char * V_3 )
{
char * V_4 = V_3 ;
* V_4 ++ = V_2 -> V_5 ? 'r' : 'w' ;
if ( V_2 -> V_6 )
* V_4 ++ = 'i' ;
if ( V_2 -> V_7 )
* V_4 ++ = 'S' ;
if ( V_2 -> V_8 )
* V_4 ++ = 's' ;
if ( V_2 -> V_9 )
* V_4 ++ = 'h' ;
if ( V_2 -> V_10 )
* V_4 ++ = 'u' ;
if ( V_2 -> V_11 )
* V_4 ++ = 'm' ;
if ( V_2 -> V_12 )
* V_4 ++ = 't' ;
if ( V_2 -> V_13 )
* V_4 ++ = 'Y' ;
* V_4 = 0 ;
return V_3 ;
}
static inline char F_2 ( struct V_14 * V_15 )
{
return F_3 ( V_15 ) ? '-' : '+' ;
}
static inline struct V_1 * F_4 ( struct V_16 * V_17 )
{
return F_5 ( V_17 , struct V_1 , V_18 ) ;
}
static inline struct V_1 * F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
F_7 ( V_2 -> V_6 ) ;
return F_4 ( F_8 ( & V_2 -> V_18 ) ) ;
}
static inline struct V_1 * F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
F_7 ( V_2 -> V_6 ) ;
return F_4 ( F_10 ( & V_2 -> V_18 ) ) ;
}
static inline struct V_1 * F_11 ( struct V_19 * V_20 )
{
return F_4 ( F_12 ( & V_20 -> V_21 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const char * V_22 , const int line )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_24 * V_25 ;
T_1 V_26 ;
int V_27 = 0 ;
if ( ! F_14 ( V_20 ) ) {
V_27 = 9 ;
goto V_28;
}
if ( V_2 -> V_29 >= V_30 ) {
V_27 = 10 ;
goto V_28;
}
if ( F_15 ( & V_2 -> V_31 ) <= 0 ) {
V_27 = 20 ;
goto V_28;
}
if ( F_15 ( & V_2 -> V_31 ) < F_15 ( & V_2 -> V_32 ) ) {
V_27 = 30 ;
goto V_28;
}
switch ( V_2 -> V_29 ) {
case V_33 :
if ( V_2 -> V_34 > 0 || ! F_3 ( & V_2 -> V_35 ) )
V_27 = 35 ;
else
V_27 = 0 ;
goto V_28;
case V_36 :
if ( F_15 ( & V_2 -> V_32 ) == 0 ) {
V_27 = 40 ;
goto V_28;
}
if ( V_2 -> V_9 ) {
V_27 = 50 ;
goto V_28;
}
if ( V_2 -> V_13 && ! V_2 -> V_10 ) {
V_27 = 55 ;
goto V_28;
}
break;
case V_37 :
if ( V_2 -> V_38 == 0 ) {
V_27 = 60 ;
goto V_28;
}
if ( V_2 -> V_13 && ! V_2 -> V_10 && ! V_2 -> V_9 ) {
V_27 = 65 ;
goto V_28;
}
default:
if ( F_15 ( & V_2 -> V_32 ) > 0 ) {
V_27 = 70 ;
goto V_28;
}
}
if ( V_2 -> V_39 < V_2 -> V_40 || V_2 -> V_40 < V_2 -> V_41 ) {
V_27 = 80 ;
goto V_28;
}
if ( V_2 -> V_7 && V_2 -> V_38 > 0 ) {
V_27 = 90 ;
goto V_28;
}
if ( V_2 -> V_42 && ! F_16 ( V_2 -> V_42 ) ) {
struct V_43 * V_44 ;
V_44 = & V_2 -> V_42 -> V_45 . V_46 ;
if ( ! ( V_44 -> V_47 <= F_17 ( F_18 ( V_20 ) , V_2 -> V_41 ) &&
V_44 -> V_48 >= F_17 ( F_18 ( V_20 ) , V_2 -> V_39 ) ) ) {
V_27 = 100 ;
goto V_28;
}
if ( ! ( V_2 -> V_42 -> V_49 & ( V_50 | V_51 ) ) ) {
V_27 = 102 ;
goto V_28;
}
}
if ( V_2 -> V_34 > V_2 -> V_52 ) {
V_27 = 105 ;
goto V_28;
}
if ( V_2 -> V_29 > V_37 ) {
V_27 = 0 ;
goto V_28;
}
if ( ! V_53 ) {
V_27 = 0 ;
goto V_28;
}
V_26 = 0 ;
F_19 (oap, &ext->oe_pages, oap_pending_item) {
T_2 V_54 = F_20 ( F_21 ( V_25 ) ) ;
++ V_26 ;
if ( V_54 > V_2 -> V_40 || V_54 < V_2 -> V_41 ) {
V_27 = 110 ;
goto V_28;
}
}
if ( V_26 != V_2 -> V_34 ) {
V_27 = 120 ;
goto V_28;
}
V_28:
if ( V_27 != 0 )
F_22 ( V_55 , V_2 ,
L_1 ,
V_22 , line , V_2 , V_27 ) ;
return V_27 ;
}
static int F_23 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_1 * V_56 ;
F_7 ( F_14 ( V_20 ) ) ;
if ( ! V_53 )
return 0 ;
for ( V_56 = F_11 ( V_20 ) ; V_56 ; V_56 = F_6 ( V_56 ) ) {
if ( V_56 == V_2 )
continue;
if ( V_56 -> V_40 >= V_2 -> V_41 &&
V_56 -> V_41 <= V_2 -> V_40 )
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , int V_57 )
{
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_7 ( V_57 >= V_33 && V_57 < V_30 ) ;
V_2 -> V_29 = V_57 ;
F_25 ( & V_2 -> V_58 ) ;
}
static struct V_1 * F_26 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_59 , V_60 ) ;
if ( ! V_2 )
return NULL ;
F_28 ( & V_2 -> V_18 ) ;
V_2 -> V_23 = V_20 ;
F_29 ( F_18 ( V_20 ) ) ;
F_30 ( & V_2 -> V_31 , 1 ) ;
F_30 ( & V_2 -> V_32 , 0 ) ;
F_31 ( & V_2 -> V_61 ) ;
V_2 -> V_29 = V_33 ;
F_31 ( & V_2 -> V_35 ) ;
F_32 ( & V_2 -> V_58 ) ;
V_2 -> V_42 = NULL ;
return V_2 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_59 , V_2 ) ;
}
static struct V_1 * F_35 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) >= 0 ) ;
F_36 ( & V_2 -> V_31 ) ;
return V_2 ;
}
static void F_37 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) > 0 ) ;
if ( F_38 ( & V_2 -> V_31 ) ) {
F_7 ( F_3 ( & V_2 -> V_61 ) ) ;
F_7 ( F_15 ( & V_2 -> V_32 ) == 0 ) ;
F_7 ( V_2 -> V_29 == V_33 ) ;
F_7 ( ! V_2 -> V_6 ) ;
if ( V_2 -> V_42 ) {
F_39 ( & V_2 -> V_42 -> V_64 ,
L_2 , V_2 ) ;
F_40 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
}
F_41 ( V_63 , F_18 ( V_2 -> V_23 ) ) ;
F_33 ( V_2 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) > 1 ) ;
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_43 ( & V_2 -> V_31 ) ;
}
static struct V_1 * F_44 ( struct V_19 * V_20 ,
T_2 V_54 )
{
struct V_16 * V_17 = V_20 -> V_21 . V_16 ;
struct V_1 * V_56 , * V_65 = NULL ;
F_7 ( F_14 ( V_20 ) ) ;
while ( V_17 ) {
V_56 = F_4 ( V_17 ) ;
if ( V_54 < V_56 -> V_41 ) {
V_17 = V_17 -> V_66 ;
} else if ( V_54 > V_56 -> V_40 ) {
V_65 = F_4 ( V_17 ) ;
V_17 = V_17 -> V_67 ;
} else {
return V_56 ;
}
}
return V_65 ;
}
static struct V_1 * F_45 ( struct V_19 * V_20 ,
T_2 V_54 )
{
struct V_1 * V_2 ;
V_2 = F_44 ( V_20 , V_54 ) ;
if ( V_2 && V_2 -> V_41 <= V_54 && V_54 <= V_2 -> V_40 )
return F_35 ( V_2 ) ;
return NULL ;
}
static void F_46 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_16 * * V_17 = & V_20 -> V_21 . V_16 ;
struct V_16 * V_68 = NULL ;
struct V_1 * V_56 ;
F_7 ( V_2 -> V_6 == 0 ) ;
F_7 ( V_2 -> V_23 == V_20 ) ;
F_7 ( F_14 ( V_20 ) ) ;
while ( * V_17 ) {
V_56 = F_4 ( * V_17 ) ;
V_68 = * V_17 ;
if ( V_2 -> V_40 < V_56 -> V_41 )
V_17 = & ( * V_17 ) -> V_66 ;
else if ( V_2 -> V_41 > V_56 -> V_40 )
V_17 = & ( * V_17 ) -> V_67 ;
else
F_47 ( 0 , V_56 , V_69 L_3 , F_48 ( V_2 ) ) ;
}
F_49 ( & V_2 -> V_18 , V_68 , V_17 ) ;
F_50 ( & V_2 -> V_18 , & V_20 -> V_21 ) ;
F_35 ( V_2 ) ;
V_2 -> V_6 = 1 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_14 ( V_20 ) ) ;
if ( V_2 -> V_6 ) {
F_52 ( & V_2 -> V_18 , & V_20 -> V_21 ) ;
V_2 -> V_6 = 0 ;
F_42 ( V_2 ) ;
}
}
static struct V_1 * F_53 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_14 ( V_20 ) ) ;
F_7 ( V_2 -> V_29 == V_36 || V_2 -> V_29 == V_37 ) ;
if ( V_2 -> V_29 == V_37 ) {
F_24 ( V_2 , V_36 ) ;
F_54 ( V_20 , V_70 , - V_2 -> V_34 ) ;
}
F_36 ( & V_2 -> V_32 ) ;
F_55 ( & V_2 -> V_61 ) ;
return F_35 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_7 ( F_3 ( & V_2 -> V_35 ) ) ;
F_51 ( V_2 ) ;
F_55 ( & V_2 -> V_61 ) ;
F_24 ( V_2 , V_33 ) ;
F_22 ( V_71 , V_2 , L_4 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_58 ( V_20 ) ;
F_56 ( V_2 ) ;
F_59 ( V_20 ) ;
}
static int F_60 ( const struct V_62 * V_63 , struct V_1 * V_72 ,
struct V_1 * V_73 )
{
struct V_19 * V_20 = V_72 -> V_23 ;
T_2 V_74 ;
T_2 V_75 ;
int V_76 ;
F_7 ( V_72 -> V_29 == V_37 ) ;
F_7 ( F_14 ( V_20 ) ) ;
if ( ! V_73 )
return - V_77 ;
if ( V_73 -> V_29 != V_37 || V_73 -> V_13 )
return - V_78 ;
if ( V_72 -> V_39 != V_73 -> V_39 )
return - V_79 ;
F_7 ( V_72 -> V_42 == V_73 -> V_42 ) ;
V_76 = F_61 ( V_20 ) -> V_80 - V_81 ;
V_74 = V_72 -> V_41 >> V_76 ;
V_75 = V_72 -> V_40 >> V_76 ;
if ( V_74 != ( V_73 -> V_40 >> V_76 ) + 1 &&
V_75 + 1 != V_73 -> V_41 >> V_76 )
return - V_79 ;
F_22 ( V_71 , V_73 , L_5 , V_72 ) ;
V_72 -> V_41 = F_62 ( V_72 -> V_41 , V_73 -> V_41 ) ;
V_72 -> V_40 = F_63 ( V_72 -> V_40 , V_73 -> V_40 ) ;
V_72 -> V_38 += V_73 -> V_38 ;
V_72 -> V_34 += V_73 -> V_34 ;
V_72 -> V_10 |= V_73 -> V_10 ;
V_72 -> V_11 |= V_73 -> V_11 ;
F_64 ( & V_73 -> V_35 , & V_72 -> V_35 ) ;
F_55 ( & V_73 -> V_61 ) ;
V_73 -> V_34 = 0 ;
F_35 ( V_73 ) ;
F_56 ( V_73 ) ;
F_37 ( V_63 , V_73 ) ;
F_22 ( V_71 , V_72 , L_6 , V_73 ) ;
return 0 ;
}
void F_65 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_15 ( & V_2 -> V_32 ) > 0 ) ;
F_7 ( F_66 ( V_2 ) == 0 ) ;
F_7 ( V_2 -> V_38 > 0 ) ;
if ( F_67 ( & V_2 -> V_32 , & V_20 -> V_82 ) ) {
F_7 ( V_2 -> V_29 == V_36 ) ;
if ( V_2 -> V_12 ) {
F_24 ( V_2 , V_83 ) ;
V_2 -> V_12 = 0 ;
} else {
F_24 ( V_2 , V_37 ) ;
F_54 ( V_20 , V_70 ,
V_2 -> V_34 ) ;
F_60 ( V_63 , V_2 , F_9 ( V_2 ) ) ;
F_60 ( V_63 , V_2 , F_6 ( V_2 ) ) ;
if ( V_2 -> V_10 )
F_68 ( & V_2 -> V_61 ,
& V_20 -> V_84 ) ;
}
F_59 ( V_20 ) ;
F_69 ( V_63 , F_61 ( V_20 ) , V_20 ) ;
}
F_37 ( V_63 , V_2 ) ;
}
static inline int F_70 ( struct V_1 * V_85 , struct V_1 * V_86 )
{
return ! ( V_85 -> V_40 < V_86 -> V_41 || V_86 -> V_40 < V_85 -> V_41 ) ;
}
static struct V_1 * F_71 ( const struct V_62 * V_63 ,
struct V_19 * V_20 , T_2 V_54 ,
unsigned int * V_87 )
{
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_1 * V_72 ;
struct V_1 * V_2 ;
struct V_1 * V_94 = NULL ;
struct V_1 * V_95 = NULL ;
T_2 V_96 ;
T_2 V_97 ;
unsigned int V_98 ;
unsigned int V_99 ;
int V_76 ;
T_2 V_100 ;
int V_27 ;
V_72 = F_26 ( V_20 ) ;
if ( ! V_72 )
return F_72 ( - V_101 ) ;
V_91 = F_73 ( V_63 ) -> V_102 ;
F_74 ( V_91 , L_7 , V_54 ) ;
F_7 ( V_91 -> V_103 == V_104 ) ;
V_93 = & V_91 -> V_105 . V_106 -> V_107 ;
F_7 ( V_93 -> V_108 >= V_109 ) ;
F_7 ( V_89 -> V_80 >= V_81 ) ;
V_76 = V_89 -> V_80 - V_81 ;
V_100 = ~ ( ( 1 << V_76 ) - 1 ) ;
V_99 = 1 << V_89 -> V_80 ;
V_96 = V_54 >> V_76 ;
V_98 = V_89 -> V_110 ;
F_7 ( ( V_98 & ~ V_100 ) == 0 ) ;
V_97 = V_54 - ( V_54 % V_98 ) + V_98 - 1 ;
V_97 = F_75 ( T_2 , V_97 , V_93 -> V_111 ) ;
V_72 -> V_39 = V_97 ;
V_72 -> V_41 = V_54 & V_100 ;
V_72 -> V_40 = ( ( V_54 + ~ V_100 + 1 ) & V_100 ) - 1 ;
if ( V_72 -> V_41 < V_93 -> V_112 )
V_72 -> V_41 = V_93 -> V_112 ;
if ( V_72 -> V_40 > V_97 )
V_72 -> V_40 = V_97 ;
V_72 -> V_38 = 0 ;
V_72 -> V_52 = V_98 ;
if ( V_91 -> V_113 ) {
F_7 ( V_91 -> V_114 ) ;
V_72 -> V_42 = F_76 ( V_91 -> V_113 ) ;
F_39 ( & V_91 -> V_113 -> V_64 , L_2 , V_72 ) ;
}
F_74 ( * V_87 >= V_99 + V_89 -> V_115 ,
L_8 , * V_87 , V_99 , V_89 -> V_115 ) ;
F_74 ( ( V_97 - V_72 -> V_41 ) < V_98 , V_69 L_3 ,
F_48 ( V_72 ) ) ;
V_116:
F_58 ( V_20 ) ;
V_2 = F_44 ( V_20 , V_72 -> V_41 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
while ( V_2 ) {
T_2 V_117 = V_2 -> V_41 >> V_76 ;
T_2 V_118 = V_2 -> V_40 >> V_76 ;
F_7 ( F_77 ( V_2 ) == 0 ) ;
if ( V_96 > V_118 + 1 )
break;
if ( V_91 -> V_113 != V_2 -> V_42 ) {
F_47 ( ! F_70 ( V_2 , V_72 ) , V_2 ,
V_69 L_3 , F_48 ( V_72 ) ) ;
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_96 + 1 < V_117 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( F_70 ( V_2 , V_72 ) ) {
F_47 ( ( V_2 -> V_41 <= V_72 -> V_41 &&
V_2 -> V_40 >= V_72 -> V_40 ) ,
V_2 , V_69 L_3 , F_48 ( V_72 ) ) ;
if ( V_2 -> V_29 > V_37 || V_2 -> V_13 ) {
V_94 = F_35 ( V_2 ) ;
break;
}
V_95 = F_53 ( V_2 ) ;
break;
}
if ( V_2 -> V_29 != V_37 || V_2 -> V_13 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_2 -> V_39 != V_97 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_96 + 1 == V_117 ) {
F_78 ( ( V_2 -> V_41 & ~ V_100 ) == 0 , V_2 ) ;
V_2 -> V_41 = V_72 -> V_41 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
V_95 = F_53 ( V_2 ) ;
} else if ( V_96 == V_118 + 1 ) {
V_2 -> V_40 = V_72 -> V_40 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
if ( F_60 ( V_63 , V_2 , F_6 ( V_2 ) ) == 0 )
* V_87 += V_89 -> V_115 ;
V_95 = F_53 ( V_2 ) ;
}
if ( V_95 )
break;
V_2 = F_6 ( V_2 ) ;
}
F_79 ( V_71 , V_20 ) ;
if ( V_95 ) {
F_7 ( ! V_94 ) ;
if ( ! F_80 ( V_95 ) ) {
F_7 ( V_95 -> V_42 == V_72 -> V_42 ) ;
F_22 ( V_71 , V_95 ,
L_9 , V_54 ) ;
}
} else if ( ! V_94 ) {
F_78 ( F_23 ( V_20 , V_72 ) == 0 , V_72 ) ;
V_72 -> V_38 = V_99 + V_89 -> V_115 ;
* V_87 -= V_72 -> V_38 ;
F_7 ( * V_87 >= 0 ) ;
V_72 -> V_29 = V_37 ;
V_95 = F_53 ( V_72 ) ;
F_46 ( V_20 , V_72 ) ;
F_22 ( V_71 , V_72 , L_10 ,
V_54 , V_93 -> V_111 ) ;
}
F_59 ( V_20 ) ;
if ( V_94 ) {
F_7 ( ! V_95 ) ;
V_27 = F_81 ( V_63 , V_94 , V_33 ) ;
F_37 ( V_63 , V_94 ) ;
V_94 = NULL ;
if ( V_27 < 0 ) {
V_95 = F_72 ( V_27 ) ;
goto V_28;
}
goto V_116;
}
V_28:
F_37 ( V_63 , V_72 ) ;
F_7 ( * V_87 >= 0 ) ;
return V_95 ;
}
int F_82 ( const struct V_62 * V_63 , struct V_1 * V_2 ,
int V_119 , int V_27 )
{
struct V_88 * V_89 = F_61 ( V_2 -> V_23 ) ;
struct V_24 * V_25 ;
struct V_24 * V_56 ;
int V_120 = V_2 -> V_34 ;
int V_121 = 0 ;
int V_122 = V_89 -> V_123 -> V_124 -> V_125 . V_126 ? : 4096 ;
T_3 V_127 = 0 ;
int V_128 = - 1 ;
F_22 ( V_71 , V_2 , L_11 ) ;
V_2 -> V_129 = V_27 ? : V_2 -> V_34 ;
F_78 ( F_83 ( V_27 == 0 , V_2 -> V_29 == V_130 ) , V_2 ) ;
F_84 ( V_89 , & V_2 -> V_35 ) ;
F_85 (oap, tmp, &ext->oe_pages, oap_pending_item) {
F_55 ( & V_25 -> V_131 ) ;
F_55 ( & V_25 -> V_132 ) ;
if ( V_127 <= V_25 -> V_133 ) {
V_127 = V_25 -> V_133 ;
V_128 = V_25 -> V_134 ;
}
-- V_2 -> V_34 ;
F_86 ( V_63 , V_89 , V_25 , V_119 , V_27 ) ;
}
F_78 ( V_2 -> V_34 == 0 , V_2 ) ;
if ( ! V_119 ) {
V_121 = V_2 -> V_38 ;
} else if ( V_122 < V_135 &&
V_128 != V_135 ) {
int V_136 = V_127 & ~ V_137 ;
int V_138 = V_128 + ( V_136 & ( V_122 - 1 ) ) ;
int V_48 = ( V_136 + V_128 ) & ( V_122 - 1 ) ;
if ( V_48 )
V_138 += V_122 - V_48 ;
V_121 = V_135 - V_138 ;
}
if ( V_2 -> V_38 > 0 )
F_87 ( V_89 , V_120 , V_121 ) ;
F_57 ( V_2 ) ;
F_37 ( V_63 , V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , enum V_139 V_57 )
{
int V_140 ;
F_58 ( V_2 -> V_23 ) ;
V_140 = V_2 -> V_29 == V_57 ;
F_59 ( V_2 -> V_23 ) ;
return V_140 ;
}
static int F_81 ( const struct V_62 * V_63 , struct V_1 * V_2 ,
enum V_139 V_57 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_141 V_142 = F_89 ( F_90 ( 600 ) , NULL ,
V_143 , NULL ) ;
int V_27 = 0 ;
F_58 ( V_20 ) ;
F_7 ( F_77 ( V_2 ) == 0 ) ;
if ( V_57 == V_33 && ! V_2 -> V_10 && ! V_2 -> V_9 &&
! V_2 -> V_12 ) {
if ( V_2 -> V_29 == V_36 ) {
V_2 -> V_10 = 1 ;
} else if ( V_2 -> V_29 == V_37 ) {
V_2 -> V_10 = 1 ;
F_53 ( V_2 ) ;
V_27 = 1 ;
}
}
F_59 ( V_20 ) ;
if ( V_27 == 1 )
F_65 ( V_63 , V_2 ) ;
V_27 = F_91 ( V_2 -> V_58 , F_88 ( V_2 , V_57 ) , & V_142 ) ;
if ( V_27 == - V_144 ) {
F_22 ( V_55 , V_2 ,
L_12 ,
F_92 ( F_61 ( V_20 ) ) , V_57 ) ;
V_142 = F_93 ( NULL , NULL ) ;
V_27 = F_91 ( V_2 -> V_58 , F_88 ( V_2 , V_57 ) ,
& V_142 ) ;
}
if ( V_27 == 0 && V_2 -> V_129 < 0 )
V_27 = V_2 -> V_129 ;
return V_27 ;
}
static int F_94 ( struct V_1 * V_2 , T_2 V_145 ,
bool V_146 )
{
struct V_62 * V_63 ;
struct V_147 * V_148 ;
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_24 * V_25 ;
struct V_24 * V_56 ;
int V_149 = 0 ;
int V_76 = V_89 -> V_80 - V_81 ;
T_3 V_150 = V_145 >> V_76 ;
int V_87 = 0 ;
int V_120 = 0 ;
int V_27 = 0 ;
int V_151 ;
F_7 ( F_66 ( V_2 ) == 0 ) ;
F_78 ( V_2 -> V_29 == V_83 , V_2 ) ;
F_78 ( ! V_2 -> V_10 , V_2 ) ;
V_63 = F_95 ( & V_151 ) ;
V_148 = & F_96 ( V_63 ) -> V_152 ;
V_148 -> V_153 = F_97 ( F_18 ( V_20 ) ) ;
V_148 -> V_154 = 1 ;
V_27 = F_98 ( V_63 , V_148 , V_155 , V_148 -> V_153 ) ;
if ( V_27 < 0 )
goto V_28;
F_85 (oap, tmp, &ext->oe_pages, oap_pending_item) {
T_2 V_54 = F_20 ( F_21 ( V_25 ) ) ;
struct V_156 * V_157 = F_99 ( V_25 ) ;
F_7 ( F_3 ( & V_25 -> V_131 ) ) ;
if ( V_54 < V_145 ||
( V_54 == V_145 && V_146 ) ) {
if ( V_54 >> V_76 == V_150 )
++ V_149 ;
continue;
}
F_55 ( & V_25 -> V_132 ) ;
F_100 ( V_157 ) ;
F_39 ( & V_157 -> V_158 , L_13 , V_159 ) ;
if ( F_101 ( V_63 , V_148 , V_157 ) == 0 ) {
F_102 ( V_63 , V_148 , V_157 ) ;
F_103 ( V_63 , V_148 , V_157 ) ;
} else {
F_7 ( V_157 -> V_160 == V_161 ) ;
F_7 ( 0 ) ;
}
F_104 ( & V_157 -> V_158 , L_13 , V_159 ) ;
F_105 ( V_63 , V_157 ) ;
-- V_2 -> V_34 ;
++ V_120 ;
}
F_47 ( F_83 ( V_2 -> V_41 >= V_145 + ! ! V_146 ,
V_2 -> V_34 == 0 ) ,
V_2 , L_14 , V_145 , V_146 ) ;
F_58 ( V_20 ) ;
if ( V_2 -> V_34 == 0 ) {
F_7 ( V_149 == 0 ) ;
V_87 = V_2 -> V_38 ;
V_2 -> V_38 = 0 ;
} else {
int V_162 = ( V_2 -> V_40 >> V_76 ) - V_150 ;
T_2 V_163 ;
if ( V_149 == 0 ) {
F_7 ( V_150 > 0 ) ;
-- V_150 ;
++ V_162 ;
}
V_87 = V_162 << V_89 -> V_80 ;
V_2 -> V_38 -= V_87 ;
V_163 = ( ( V_150 + 1 ) << V_76 ) - 1 ;
V_2 -> V_40 = F_62 ( V_163 , V_2 -> V_39 ) ;
F_7 ( V_2 -> V_40 >= V_2 -> V_41 ) ;
F_7 ( V_2 -> V_38 > 0 ) ;
}
F_59 ( V_20 ) ;
if ( V_87 > 0 || V_120 > 0 )
F_87 ( V_89 , V_120 , V_87 ) ;
V_28:
F_106 ( V_63 , V_148 ) ;
F_107 ( V_63 , & V_151 ) ;
return V_27 ;
}
static int F_108 ( const struct V_62 * V_63 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_24 * V_164 = NULL ;
struct V_19 * V_20 = V_2 -> V_23 ;
unsigned int V_26 = 0 ;
int V_27 ;
F_7 ( F_66 ( V_2 ) == 0 ) ;
F_78 ( V_2 -> V_29 == V_165 , V_2 ) ;
F_78 ( V_2 -> V_166 , V_2 ) ;
F_22 ( V_71 , V_2 , L_15 ) ;
F_19 (oap, &ext->oe_pages, oap_pending_item) {
++ V_26 ;
if ( ! V_164 || V_164 -> V_133 < V_25 -> V_133 )
V_164 = V_25 ;
if ( ( V_25 -> V_167 & V_168 ) != 0 )
continue;
V_27 = F_109 ( V_63 , V_25 , V_70 ) ;
switch ( V_27 ) {
case 0 :
F_110 ( & V_25 -> V_169 ) ;
V_25 -> V_167 |= V_168 ;
F_111 ( & V_25 -> V_169 ) ;
break;
case - V_170 :
F_7 ( ( V_25 -> V_167 & V_168 ) != 0 ) ;
break;
default:
F_74 ( 0 , L_16 , V_27 ) ;
}
}
F_7 ( V_26 == V_2 -> V_34 ) ;
F_7 ( V_164 ) ;
if ( ! ( V_164 -> V_167 & V_171 ) ) {
int V_172 = F_112 ( V_63 , V_164 , V_70 ) ;
F_7 ( V_172 > 0 ) ;
F_7 ( V_164 -> V_173 + V_172 <= V_135 ) ;
V_164 -> V_134 = V_172 ;
F_110 ( & V_164 -> V_169 ) ;
V_164 -> V_167 |= V_171 ;
F_111 ( & V_164 -> V_169 ) ;
}
F_19 (oap, &ext->oe_pages, oap_pending_item) {
if ( ! ( V_25 -> V_167 & V_171 ) ) {
V_25 -> V_134 = V_135 - V_25 -> V_173 ;
F_110 ( & V_164 -> V_169 ) ;
V_25 -> V_167 |= V_171 ;
F_111 ( & V_164 -> V_169 ) ;
}
}
F_58 ( V_20 ) ;
F_24 ( V_2 , V_130 ) ;
F_59 ( V_20 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , T_2 V_54 ,
unsigned int * V_87 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_1 * V_174 ;
int V_76 = V_89 -> V_80 - V_81 ;
T_2 V_96 = V_54 >> V_76 ;
T_2 V_175 ;
T_2 V_176 ;
unsigned int V_99 = 1 << V_89 -> V_80 ;
int V_27 = 0 ;
F_7 ( V_2 -> V_39 >= V_54 && V_2 -> V_41 <= V_54 ) ;
F_58 ( V_20 ) ;
F_7 ( F_77 ( V_2 ) == 0 ) ;
V_175 = V_2 -> V_40 >> V_76 ;
if ( V_96 > V_175 + 1 ) {
V_27 = - V_79 ;
goto V_28;
}
if ( V_175 >= V_96 ) {
V_27 = 0 ;
goto V_28;
}
F_7 ( V_175 + 1 == V_96 ) ;
V_176 = F_62 ( V_2 -> V_39 , ( ( V_96 + 1 ) << V_76 ) - 1 ) ;
V_174 = F_6 ( V_2 ) ;
if ( V_174 && V_174 -> V_41 <= V_176 ) {
V_27 = - V_177 ;
goto V_28;
}
V_2 -> V_40 = V_176 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
F_7 ( * V_87 >= 0 ) ;
F_47 ( F_23 ( V_20 , V_2 ) == 0 , V_2 ,
L_17 , V_54 ) ;
V_28:
F_59 ( V_20 ) ;
return V_27 ;
}
static void F_114 ( int V_178 , struct V_19 * V_20 ,
const char * V_22 , int line )
{
struct V_1 * V_2 ;
int V_179 ;
F_115 ( V_178 , L_18 ,
V_20 , V_22 , line , F_61 ( V_20 ) -> V_110 ) ;
V_179 = 1 ;
for ( V_2 = F_11 ( V_20 ) ; V_2 ; V_2 = F_6 ( V_2 ) )
F_22 ( V_178 , V_2 , L_19 , V_179 ++ ) ;
V_179 = 1 ;
F_19 (ext, &obj->oo_hp_exts, oe_link)
F_22 ( V_178 , V_2 , L_20 , V_179 ++ ) ;
V_179 = 1 ;
F_19 (ext, &obj->oo_urgent_exts, oe_link)
F_22 ( V_178 , V_2 , L_21 , V_179 ++ ) ;
V_179 = 1 ;
F_19 (ext, &obj->oo_reading_exts, oe_link)
F_22 ( V_178 , V_2 , L_22 , V_179 ++ ) ;
}
static inline int F_116 ( struct V_19 * V_180 )
{
return ! F_3 ( & V_180 -> V_181 ) ||
! F_3 ( & V_180 -> V_182 ) ;
}
static int F_109 ( const struct V_62 * V_63 , struct V_24 * V_25 ,
int V_183 )
{
struct V_184 * V_185 = F_117 ( V_25 ) ;
struct V_156 * V_157 = F_99 ( V_25 ) ;
int V_186 ;
F_7 ( V_183 == V_70 ) ;
V_186 = F_118 ( V_63 , V_157 , V_187 ) ;
if ( V_186 == 0 )
V_185 -> V_188 = F_119 () ;
return V_186 ;
}
static int F_112 ( const struct V_62 * V_63 ,
struct V_24 * V_25 , int V_183 )
{
struct V_184 * V_185 = F_117 ( V_25 ) ;
T_2 V_54 = F_20 ( F_21 ( V_25 ) ) ;
struct V_189 * V_20 ;
struct V_190 * V_191 = & F_96 ( V_63 ) -> V_192 ;
int V_186 ;
T_4 V_193 ;
F_7 ( ! ( V_183 & V_194 ) ) ;
V_20 = V_185 -> V_195 . V_196 ;
F_120 ( V_20 ) ;
V_186 = F_121 ( V_63 , V_20 , V_191 ) ;
F_122 ( V_20 ) ;
if ( V_186 < 0 )
return V_186 ;
V_193 = V_191 -> V_197 ;
if ( F_17 ( V_20 , V_54 ) >= V_193 )
return 0 ;
else if ( F_17 ( V_20 , V_54 + 1 ) > V_193 )
return V_193 % V_135 ;
else
return V_135 ;
}
static int F_123 ( const struct V_62 * V_63 , struct V_24 * V_25 ,
int V_183 , int V_27 )
{
struct V_184 * V_185 = F_117 ( V_25 ) ;
struct V_156 * V_157 = F_99 ( V_25 ) ;
enum V_198 V_199 ;
int V_200 ;
V_183 &= ~ V_201 ;
F_74 ( F_124 ( V_157 -> V_160 == V_202 , V_183 == V_194 ) ,
L_23 , V_157 -> V_160 , V_183 ) ;
F_74 ( F_124 ( V_157 -> V_160 == V_203 , V_183 == V_70 ) ,
L_23 , V_157 -> V_160 , V_183 ) ;
F_7 ( V_185 -> V_204 ) ;
V_199 = V_183 == V_194 ? V_205 : V_187 ;
V_185 -> V_204 = 0 ;
V_185 -> V_188 = 0 ;
V_200 = V_25 -> V_206 & V_207 ;
if ( V_27 == 0 && V_200 ) {
struct V_208 * V_209 = V_185 -> V_195 . V_196 -> V_210 . V_211 ;
struct V_212 * V_213 = & F_125 ( V_209 ) -> V_214 ;
T_1 V_215 = V_25 -> V_134 ;
if ( V_199 == V_205 )
V_213 -> V_216 += V_215 ;
else
V_213 -> V_217 += V_215 ;
}
F_104 ( & V_157 -> V_158 , L_24 , V_157 ) ;
F_126 ( V_63 , V_157 , V_199 , V_27 ) ;
F_105 ( V_63 , V_157 ) ;
return 0 ;
}
static void F_127 ( struct V_88 * V_89 ,
struct V_218 * V_219 )
{
F_128 ( & V_89 -> V_220 ) ;
F_7 ( ! ( V_219 -> V_221 & V_222 ) ) ;
F_129 ( & V_223 ) ;
V_89 -> V_224 ++ ;
V_219 -> V_221 |= V_222 ;
F_115 ( V_71 , L_25 ,
V_135 , V_219 , V_219 -> V_225 ) ;
F_130 ( V_89 ) ;
}
static void F_131 ( struct V_88 * V_89 ,
struct V_218 * V_219 )
{
F_128 ( & V_89 -> V_220 ) ;
if ( ! ( V_219 -> V_221 & V_222 ) ) {
return;
}
V_219 -> V_221 &= ~ V_222 ;
F_132 ( & V_223 ) ;
V_89 -> V_224 -- ;
if ( V_219 -> V_221 & V_226 ) {
V_219 -> V_221 &= ~ V_226 ;
F_132 ( & V_227 ) ;
V_89 -> V_228 -- ;
}
}
static int F_133 ( struct V_88 * V_89 , unsigned int V_215 )
{
int V_27 = - V_229 ;
if ( V_89 -> V_230 >= V_215 ) {
V_89 -> V_230 -= V_215 ;
V_89 -> V_231 += V_215 ;
V_27 = 0 ;
}
return V_27 ;
}
static void F_134 ( struct V_88 * V_89 ,
unsigned int V_232 , unsigned int V_233 )
{
V_89 -> V_231 -= V_232 ;
if ( V_233 > V_232 ) {
V_89 -> V_230 += V_232 ;
V_89 -> V_234 += V_233 - V_232 ;
} else {
V_89 -> V_230 += V_233 ;
}
}
static void F_135 ( struct V_88 * V_89 ,
unsigned int V_232 , unsigned int V_233 )
{
F_110 ( & V_89 -> V_220 ) ;
F_134 ( V_89 , V_232 , V_233 ) ;
if ( V_233 > 0 )
F_136 ( V_89 ) ;
F_111 ( & V_89 -> V_220 ) ;
}
static void F_87 ( struct V_88 * V_89 , unsigned int V_120 ,
unsigned int V_121 )
{
unsigned long V_235 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
F_110 ( & V_89 -> V_220 ) ;
F_137 ( V_120 , & V_223 ) ;
V_89 -> V_224 -= V_120 ;
V_89 -> V_234 += V_121 ;
if ( V_89 -> V_230 < V_235 && V_89 -> V_234 >= V_235 ) {
V_89 -> V_234 -= V_235 ;
V_89 -> V_230 += V_235 ;
}
F_136 ( V_89 ) ;
F_111 ( & V_89 -> V_220 ) ;
F_115 ( V_71 , L_26 ,
V_121 , V_89 -> V_234 ,
V_89 -> V_230 , V_89 -> V_224 << V_81 ) ;
}
static void F_138 ( struct V_88 * V_89 , struct V_24 * V_25 )
{
F_110 ( & V_89 -> V_220 ) ;
F_131 ( V_89 , & V_25 -> V_236 ) ;
F_111 ( & V_89 -> V_220 ) ;
}
static int F_139 ( struct V_88 * V_89 ,
struct V_24 * V_25 ,
int V_215 , int V_237 )
{
int V_27 ;
F_140 ( V_71 , V_89 , L_27 , V_215 ) ;
V_27 = F_133 ( V_89 , V_215 ) ;
if ( V_27 < 0 )
return 0 ;
if ( V_89 -> V_224 <= V_89 -> V_238 &&
F_141 ( & V_223 ) + 1 <= V_239 ) {
F_127 ( V_89 , & V_25 -> V_236 ) ;
if ( V_237 ) {
V_89 -> V_228 ++ ;
F_129 ( & V_227 ) ;
V_25 -> V_206 |= V_226 ;
}
V_27 = 1 ;
} else {
F_134 ( V_89 , V_215 , V_215 ) ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_142 ( struct V_88 * V_89 , struct V_240 * V_241 )
{
int V_27 ;
F_110 ( & V_89 -> V_220 ) ;
V_27 = F_3 ( & V_241 -> V_242 ) ;
F_111 ( & V_89 -> V_220 ) ;
return V_27 ;
}
static int F_143 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_24 * V_25 , int V_215 )
{
struct V_19 * V_180 = V_25 -> V_243 ;
struct V_244 * V_245 = V_180 -> V_246 ;
struct V_240 V_241 ;
struct V_141 V_142 ;
int V_27 = - V_229 ;
V_142 = F_89 ( F_90 ( V_247 ? V_248 : V_249 ) ,
NULL , V_143 , NULL ) ;
F_140 ( V_71 , V_89 , L_27 , V_215 ) ;
F_110 ( & V_89 -> V_220 ) ;
if ( F_144 ( V_250 ) ||
! V_89 -> V_238 || V_89 -> V_251 . V_252 ||
V_245 -> V_253 . V_252 ) {
F_140 ( V_71 , V_89 , L_28 ) ;
V_27 = - V_229 ;
goto V_28;
}
if ( F_139 ( V_89 , V_25 , V_215 , 0 ) ) {
F_140 ( V_71 , V_89 , L_29 ) ;
V_27 = 0 ;
goto V_28;
}
F_32 ( & V_241 . V_254 ) ;
V_241 . V_255 = V_25 ;
V_241 . V_256 = V_215 ;
while ( V_89 -> V_224 > 0 || V_89 -> V_257 > 0 ) {
F_145 ( & V_241 . V_242 , & V_89 -> V_258 ) ;
V_241 . V_259 = 0 ;
F_111 ( & V_89 -> V_220 ) ;
F_69 ( V_63 , V_89 , NULL ) ;
F_115 ( V_71 , L_30 ,
F_92 ( V_89 ) , & V_241 , V_25 ) ;
V_27 = F_91 ( V_241 . V_254 , F_142 ( V_89 , & V_241 ) , & V_142 ) ;
F_110 ( & V_89 -> V_220 ) ;
if ( V_27 < 0 ) {
F_55 ( & V_241 . V_242 ) ;
break;
}
F_7 ( F_3 ( & V_241 . V_242 ) ) ;
V_27 = V_241 . V_259 ;
if ( V_27 != - V_229 )
break;
if ( F_139 ( V_89 , V_25 , V_215 , 0 ) ) {
V_27 = 0 ;
break;
}
}
switch ( V_27 ) {
case 0 :
F_140 ( V_71 , V_89 , L_31 ) ;
break;
case - V_144 :
F_140 ( V_71 , V_89 ,
L_32 ) ;
F_79 ( V_71 , V_180 ) ;
V_27 = - V_229 ;
break;
case - V_260 :
F_140 ( V_71 , V_89 , L_33 ) ;
V_27 = - V_261 ;
break;
case - V_229 :
F_140 ( V_71 , V_89 ,
L_34 ) ;
break;
default:
F_115 ( V_71 , L_35 ,
F_92 ( V_89 ) , & V_241 , V_27 ) ;
break;
}
V_28:
F_111 ( & V_89 -> V_220 ) ;
return V_27 ;
}
void F_136 ( struct V_88 * V_89 )
{
struct V_14 * V_262 , * V_56 ;
struct V_240 * V_241 ;
F_146 (l, tmp, &cli->cl_cache_waiters) {
V_241 = F_147 ( V_262 , struct V_240 , V_242 ) ;
F_55 ( & V_241 -> V_242 ) ;
V_241 -> V_259 = - V_229 ;
if ( ( V_89 -> V_224 > V_89 -> V_238 ) ||
( F_141 ( & V_223 ) + 1 >
V_239 ) ) {
F_115 ( V_71 , L_36 ,
V_89 -> V_224 , V_89 -> V_238 ,
V_239 ) ;
goto V_263;
}
if ( F_139 ( V_89 , V_241 -> V_255 , V_241 -> V_256 , 0 ) )
V_241 -> V_259 = 0 ;
V_263:
F_115 ( V_71 , L_37 ,
V_241 , V_241 -> V_255 , V_89 -> V_230 , V_241 -> V_259 ) ;
F_148 ( & V_241 -> V_254 ) ;
}
}
static int F_149 ( struct V_88 * V_89 , struct V_19 * V_180 )
{
int V_264 = ! ! F_3 ( & V_180 -> V_265 ) ;
return F_150 ( V_89 ) >= V_89 -> V_266 + V_264 ;
}
static int F_151 ( struct V_88 * V_89 , struct V_19 * V_180 ,
int V_183 )
{
int V_267 = 0 ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_268 )
V_267 = 1 ;
if ( V_183 & V_70 ) {
if ( F_15 ( & V_180 -> V_269 ) == 0 )
return 0 ;
if ( V_267 ) {
F_115 ( V_71 , L_38 ) ;
return 1 ;
}
if ( ! F_3 ( & V_180 -> V_265 ) ) {
F_115 ( V_71 , L_39 ) ;
return 1 ;
}
if ( ! F_3 ( & V_180 -> V_84 ) ) {
F_115 ( V_71 , L_40 ) ;
return 1 ;
}
if ( ! F_3 ( & V_89 -> V_258 ) ) {
F_115 ( V_71 , L_41 ) ;
return 1 ;
}
if ( F_15 ( & V_180 -> V_269 ) >=
V_89 -> V_110 )
return 1 ;
} else {
if ( F_15 ( & V_180 -> V_270 ) == 0 )
return 0 ;
if ( V_267 ) {
F_115 ( V_71 , L_38 ) ;
return 1 ;
}
if ( ! F_3 ( & V_180 -> V_271 ) )
return 1 ;
}
return 0 ;
}
static void F_54 ( struct V_19 * V_20 , int V_183 , int V_272 )
{
struct V_88 * V_89 = F_61 ( V_20 ) ;
if ( V_183 & V_70 ) {
F_152 ( V_272 , & V_20 -> V_269 ) ;
F_152 ( V_272 , & V_89 -> V_273 ) ;
F_7 ( F_15 ( & V_20 -> V_269 ) >= 0 ) ;
} else {
F_152 ( V_272 , & V_20 -> V_270 ) ;
F_152 ( V_272 , & V_89 -> V_274 ) ;
F_7 ( F_15 ( & V_20 -> V_270 ) >= 0 ) ;
}
F_153 ( V_20 , L_42 , V_183 , V_272 ) ;
}
static int F_154 ( struct V_19 * V_20 )
{
return ! F_3 ( & V_20 -> V_265 ) ;
}
static void F_155 ( struct V_14 * V_275 , struct V_14 * V_15 , int V_276 )
{
if ( F_3 ( V_275 ) && V_276 )
F_145 ( V_275 , V_15 ) ;
else if ( ! F_3 ( V_275 ) && ! V_276 )
F_55 ( V_275 ) ;
}
static int F_156 ( struct V_88 * V_89 , struct V_19 * V_180 )
{
if ( F_154 ( V_180 ) ) {
F_155 ( & V_180 -> V_181 , & V_89 -> V_277 , 0 ) ;
F_155 ( & V_180 -> V_182 , & V_89 -> V_278 , 1 ) ;
} else {
F_155 ( & V_180 -> V_182 , & V_89 -> V_278 , 0 ) ;
F_155 ( & V_180 -> V_181 , & V_89 -> V_277 ,
F_151 ( V_89 , V_180 , V_70 ) ||
F_151 ( V_89 , V_180 , V_194 ) ) ;
}
F_155 ( & V_180 -> V_279 , & V_89 -> V_280 ,
F_15 ( & V_180 -> V_269 ) > 0 ) ;
F_155 ( & V_180 -> V_281 , & V_89 -> V_282 ,
F_15 ( & V_180 -> V_270 ) > 0 ) ;
return F_116 ( V_180 ) ;
}
static int F_157 ( struct V_88 * V_89 , struct V_19 * V_180 )
{
int V_283 ;
F_110 ( & V_89 -> V_220 ) ;
V_283 = F_156 ( V_89 , V_180 ) ;
F_111 ( & V_89 -> V_220 ) ;
return V_283 ;
}
static void F_158 ( struct V_284 * V_285 , T_3 V_286 ,
int V_27 )
{
if ( V_27 ) {
if ( ! V_285 -> V_287 )
V_285 -> V_287 = V_27 ;
V_285 -> V_252 = 1 ;
V_285 -> V_288 = F_159 () ;
return;
}
if ( V_285 -> V_252 && ( V_286 >= V_285 -> V_288 ) )
V_285 -> V_252 = 0 ;
}
static void F_86 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_24 * V_25 , int V_119 , int V_27 )
{
struct V_19 * V_180 = V_25 -> V_243 ;
struct V_244 * V_245 = V_180 -> V_246 ;
T_3 V_286 = 0 ;
if ( V_25 -> V_289 ) {
V_286 = F_160 ( V_25 -> V_289 ) ;
F_161 ( V_25 -> V_289 ) ;
V_25 -> V_289 = NULL ;
}
F_110 ( & V_25 -> V_169 ) ;
V_25 -> V_167 = 0 ;
F_111 ( & V_25 -> V_169 ) ;
V_25 -> V_290 = 0 ;
if ( V_25 -> V_291 & V_70 && V_286 > 0 ) {
F_110 ( & V_89 -> V_220 ) ;
F_158 ( & V_89 -> V_251 , V_286 , V_27 ) ;
F_158 ( & V_245 -> V_253 , V_286 , V_27 ) ;
F_111 ( & V_89 -> V_220 ) ;
}
V_27 = F_123 ( V_63 , V_25 , V_25 -> V_291 , V_27 ) ;
if ( V_27 )
F_162 ( L_43 ,
V_25 , V_180 , V_27 ) ;
}
static inline unsigned F_163 ( const struct V_1 * V_2 )
{
struct V_88 * V_89 = F_61 ( V_2 -> V_23 ) ;
unsigned V_76 = V_89 -> V_80 - V_81 ;
return ( V_2 -> V_40 >> V_76 ) - ( V_2 -> V_41 >> V_76 ) + 1 ;
}
static int F_164 ( struct V_88 * V_89 ,
struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_1 * V_56 ;
unsigned int V_294 ;
struct V_24 * V_25 = F_165 ( & V_2 -> V_35 ,
struct V_24 ,
V_132 ) ;
F_78 ( ( V_2 -> V_29 == V_37 || V_2 -> V_29 == V_295 ) ,
V_2 ) ;
V_294 = F_163 ( V_2 ) ;
if ( V_294 > V_293 -> V_296 )
return 0 ;
V_293 -> V_297 = F_63 ( V_2 -> V_52 , V_293 -> V_297 ) ;
if ( V_293 -> V_298 + V_2 -> V_34 > V_293 -> V_297 )
return 0 ;
F_19 (tmp, data->erd_rpc_list, oe_link) {
struct V_24 * V_299 ;
V_299 = F_165 ( & V_56 -> V_35 , struct V_24 ,
V_132 ) ;
F_78 ( V_56 -> V_166 == V_159 , V_56 ) ;
if ( F_99 ( V_25 ) -> V_300 != F_99 ( V_299 ) -> V_300 ) {
F_115 ( V_71 , L_44 ) ;
return 0 ;
}
if ( V_56 -> V_8 != V_2 -> V_8 ||
! V_56 -> V_38 != ! V_2 -> V_38 ||
V_56 -> V_301 || V_2 -> V_301 )
return 0 ;
break;
}
V_293 -> V_296 -= V_294 ;
V_293 -> V_298 += V_2 -> V_34 ;
F_68 ( & V_2 -> V_61 , V_293 -> V_302 ) ;
V_2 -> V_166 = V_159 ;
return 1 ;
}
static inline unsigned F_166 ( const struct V_88 * V_89 )
{
return F_62 ( V_303 >> V_89 -> V_80 , 256 ) ;
}
static unsigned int F_167 ( struct V_19 * V_20 ,
struct V_14 * V_304 )
{
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_305 ;
struct V_292 V_293 = {
. V_302 = V_304 ,
. V_298 = 0 ,
. V_297 = V_89 -> V_110 ,
. V_296 = F_166 ( V_89 ) ,
} ;
F_7 ( F_14 ( V_20 ) ) ;
F_85 (ext, temp, &obj->oo_hp_exts, oe_link) {
F_7 ( V_2 -> V_29 == V_37 ) ;
if ( ! F_164 ( V_89 , V_2 , & V_293 ) )
return V_293 . V_298 ;
F_78 ( V_2 -> V_34 <= V_293 . V_297 , V_2 ) ;
}
if ( V_293 . V_298 == V_293 . V_297 )
return V_293 . V_298 ;
while ( ! F_3 ( & V_20 -> V_84 ) ) {
V_2 = F_147 ( V_20 -> V_84 . V_174 ,
struct V_1 , V_61 ) ;
if ( ! F_164 ( V_89 , V_2 , & V_293 ) )
return V_293 . V_298 ;
if ( ! V_2 -> V_6 )
continue;
while ( ( V_2 = F_6 ( V_2 ) ) != NULL ) {
if ( ( V_2 -> V_29 != V_37 ) ||
( ! F_3 ( & V_2 -> V_61 ) &&
V_2 -> V_166 ) )
continue;
if ( ! F_164 ( V_89 , V_2 , & V_293 ) )
return V_293 . V_298 ;
}
}
if ( V_293 . V_298 == V_293 . V_297 )
return V_293 . V_298 ;
V_2 = F_11 ( V_20 ) ;
while ( V_2 ) {
if ( ( V_2 -> V_29 != V_37 ) ||
( ! F_3 ( & V_2 -> V_61 ) && V_2 -> V_166 ) ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( ! F_164 ( V_89 , V_2 , & V_293 ) )
return V_293 . V_298 ;
V_2 = F_6 ( V_2 ) ;
}
return V_293 . V_298 ;
}
static int
F_168 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_180 )
__must_hold( V_180 )
{
F_169 ( V_304 ) ;
struct V_1 * V_2 ;
struct V_1 * V_56 ;
struct V_1 * V_306 = NULL ;
T_5 V_26 = 0 ;
int V_200 = 0 ;
int V_27 = 0 ;
F_7 ( F_14 ( V_180 ) ) ;
V_26 = F_167 ( V_180 , & V_304 ) ;
F_7 ( F_124 ( V_26 == 0 , F_3 ( & V_304 ) ) ) ;
if ( F_3 ( & V_304 ) )
return 0 ;
F_54 ( V_180 , V_70 , - V_26 ) ;
F_19 (ext, &rpclist, oe_link) {
F_7 ( V_2 -> V_29 == V_37 ||
V_2 -> V_29 == V_295 ) ;
if ( V_2 -> V_29 == V_37 )
F_24 ( V_2 , V_165 ) ;
else
F_24 ( V_2 , V_130 ) ;
}
F_59 ( V_180 ) ;
F_85 (ext, tmp, &rpclist, oe_link) {
if ( V_2 -> V_29 == V_165 ) {
V_27 = F_108 ( V_63 , V_2 ) ;
if ( F_170 ( V_27 < 0 ) ) {
F_55 ( & V_2 -> V_61 ) ;
F_82 ( V_63 , V_2 , 0 , V_27 ) ;
continue;
}
}
if ( ! V_306 ) {
V_306 = V_2 ;
V_200 = V_2 -> V_8 ;
} else {
F_7 ( V_200 == V_2 -> V_8 ) ;
}
}
if ( ! F_3 ( & V_304 ) ) {
F_7 ( V_26 > 0 ) ;
V_27 = F_171 ( V_63 , V_89 , & V_304 , V_70 ) ;
F_7 ( F_3 ( & V_304 ) ) ;
}
F_58 ( V_180 ) ;
return V_27 ;
}
static int
F_172 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_180 )
__must_hold( V_180 )
{
struct V_1 * V_2 ;
struct V_1 * V_174 ;
F_169 ( V_304 ) ;
struct V_292 V_293 = {
. V_302 = & V_304 ,
. V_298 = 0 ,
. V_297 = V_89 -> V_110 ,
. V_296 = V_307 ,
} ;
int V_27 = 0 ;
F_7 ( F_14 ( V_180 ) ) ;
F_85 (ext, next, &osc->oo_reading_exts, oe_link) {
F_78 ( V_2 -> V_29 == V_295 , V_2 ) ;
if ( ! F_164 ( V_89 , V_2 , & V_293 ) )
break;
F_24 ( V_2 , V_130 ) ;
F_78 ( V_2 -> V_34 <= V_293 . V_297 , V_2 ) ;
}
F_7 ( V_293 . V_298 <= V_293 . V_297 ) ;
F_54 ( V_180 , V_194 , - V_293 . V_298 ) ;
if ( ! F_3 ( & V_304 ) ) {
F_59 ( V_180 ) ;
V_27 = F_171 ( V_63 , V_89 , & V_304 , V_194 ) ;
F_7 ( F_3 ( & V_304 ) ) ;
F_58 ( V_180 ) ;
}
return V_27 ;
}
static struct V_19 * F_173 ( struct V_88 * V_89 )
{
if ( ! F_3 ( & V_89 -> V_278 ) )
return F_174 ( & V_89 -> V_278 , V_308 ) ;
if ( ! F_3 ( & V_89 -> V_277 ) )
return F_174 ( & V_89 -> V_277 , V_309 ) ;
if ( ! F_3 ( & V_89 -> V_258 ) &&
! F_3 ( & V_89 -> V_280 ) )
return F_174 ( & V_89 -> V_280 , V_310 ) ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_268 ) {
if ( ! F_3 ( & V_89 -> V_280 ) )
return F_174 ( & V_89 -> V_280 , V_310 ) ;
if ( ! F_3 ( & V_89 -> V_282 ) )
return F_174 ( & V_89 -> V_282 , V_311 ) ;
}
return NULL ;
}
static void F_175 ( const struct V_62 * V_63 , struct V_88 * V_89 )
__must_hold( &cli->cl_loi_list_lock
static int F_176 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_180 , int V_312 )
{
int V_27 = 0 ;
if ( V_180 && F_157 ( V_89 , V_180 ) == 0 )
return 0 ;
if ( ! V_312 ) {
F_110 ( & V_89 -> V_220 ) ;
F_175 ( V_63 , V_89 ) ;
F_111 ( & V_89 -> V_220 ) ;
} else {
F_115 ( V_71 , L_45 , V_89 ) ;
F_7 ( V_89 -> V_313 ) ;
V_27 = F_177 ( V_89 -> V_313 ) ;
}
return V_27 ;
}
static int F_69 ( const struct V_62 * V_63 ,
struct V_88 * V_89 , struct V_19 * V_180 )
{
return F_176 ( V_63 , V_89 , V_180 , 1 ) ;
}
void F_178 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_180 )
{
( void ) F_176 ( V_63 , V_89 , V_180 , 0 ) ;
}
int F_179 ( struct V_19 * V_180 , struct V_184 * V_314 ,
struct V_157 * V_157 , T_4 V_136 )
{
struct V_315 * exp = F_180 ( V_180 ) ;
struct V_24 * V_25 = & V_314 -> V_316 ;
if ( ! V_157 )
return F_181 ( sizeof( * V_25 ) ) ;
V_25 -> V_317 = V_318 ;
V_25 -> V_319 = & exp -> V_320 -> V_321 . V_89 ;
V_25 -> V_243 = V_180 ;
V_25 -> V_322 = V_157 ;
V_25 -> V_133 = V_136 ;
F_7 ( ! ( V_136 & ~ V_137 ) ) ;
if ( F_182 ( V_323 ) )
V_25 -> V_206 = V_201 ;
F_31 ( & V_25 -> V_132 ) ;
F_31 ( & V_25 -> V_131 ) ;
F_183 ( & V_25 -> V_169 ) ;
F_115 ( V_324 , L_46 ,
V_25 , V_157 , V_25 -> V_133 ) ;
return 0 ;
}
int F_184 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_184 * V_314 )
{
struct V_325 * V_326 = F_73 ( V_63 ) ;
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 = & V_314 -> V_316 ;
struct V_88 * V_89 = V_25 -> V_319 ;
struct V_19 * V_180 = V_25 -> V_243 ;
T_2 V_54 ;
unsigned int V_87 = 0 , V_56 ;
int V_327 = V_328 ;
int V_183 = V_70 ;
int V_329 = 0 ;
int V_27 = 0 ;
if ( V_25 -> V_317 != V_318 )
return - V_77 ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_268 )
return - V_330 ;
if ( ! F_3 ( & V_25 -> V_132 ) ||
! F_3 ( & V_25 -> V_131 ) )
return - V_78 ;
V_327 |= V_314 -> V_331 ? V_207 : 0 ;
if ( F_182 ( V_323 ) ) {
V_327 |= V_201 ;
V_183 |= V_201 ;
}
if ( ! ( V_183 & V_201 ) ) {
struct V_189 * V_20 ;
struct V_190 * V_191 ;
unsigned int V_332 [ V_333 ] ;
V_20 = F_97 ( & V_180 -> V_334 ) ;
V_191 = & F_96 ( V_63 ) -> V_192 ;
F_120 ( V_20 ) ;
V_27 = F_121 ( V_63 , V_20 , V_191 ) ;
F_122 ( V_20 ) ;
V_332 [ V_335 ] = V_191 -> V_336 ;
V_332 [ V_337 ] = V_191 -> V_338 ;
if ( V_27 == 0 && F_185 ( V_89 , V_332 ) == V_339 )
V_27 = - V_229 ;
if ( V_27 )
return V_27 ;
}
V_25 -> V_291 = V_183 ;
V_25 -> V_173 = V_314 -> V_340 ;
V_25 -> V_134 = V_314 -> V_341 - V_314 -> V_340 ;
V_25 -> V_167 = 0 ;
V_25 -> V_206 = V_327 ;
F_153 ( V_180 , L_47 ,
V_25 , V_25 -> V_322 , V_25 -> V_291 & V_342 ) ;
V_54 = F_20 ( F_21 ( V_25 ) ) ;
V_2 = V_326 -> V_343 ;
if ( V_2 && V_2 -> V_41 <= V_54 && V_2 -> V_39 >= V_54 ) {
V_87 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
if ( V_2 -> V_40 >= V_54 )
V_87 = 0 ;
F_110 ( & V_89 -> V_220 ) ;
V_27 = F_139 ( V_89 , V_25 , V_87 , 0 ) ;
F_111 ( & V_89 -> V_220 ) ;
if ( V_27 == 0 ) {
V_87 = 0 ;
V_329 = 1 ;
} else if ( V_2 -> V_40 < V_54 ) {
V_56 = V_87 ;
V_27 = F_113 ( V_2 , V_54 , & V_56 ) ;
if ( V_27 < 0 ) {
V_329 = 1 ;
} else {
F_22 ( V_71 , V_2 ,
L_48 , V_54 ) ;
F_135 ( V_89 , V_87 , V_56 ) ;
V_87 = 0 ;
}
}
V_27 = 0 ;
} else if ( V_2 ) {
V_329 = 1 ;
}
if ( V_329 ) {
F_65 ( V_63 , V_2 ) ;
V_326 -> V_343 = NULL ;
V_2 = NULL ;
}
if ( ! V_2 ) {
V_56 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
F_7 ( ! V_326 -> V_343 ) ;
F_7 ( F_83 ( V_87 > 0 , V_87 >= V_56 ) ) ;
V_27 = 0 ;
if ( V_87 == 0 ) {
V_27 = F_143 ( V_63 , V_89 , V_25 , V_56 ) ;
if ( V_27 == 0 )
V_87 = V_56 ;
}
V_56 = V_87 ;
if ( V_27 == 0 ) {
V_2 = F_71 ( V_63 , V_180 , V_54 , & V_56 ) ;
if ( F_80 ( V_2 ) ) {
F_7 ( V_56 == V_87 ) ;
F_138 ( V_89 , V_25 ) ;
V_27 = F_186 ( V_2 ) ;
V_2 = NULL ;
} else {
V_326 -> V_343 = V_2 ;
}
}
if ( V_87 > 0 )
F_135 ( V_89 , V_87 , V_56 ) ;
}
F_7 ( F_83 ( V_27 == 0 , V_2 ) ) ;
if ( V_2 ) {
F_47 ( V_2 -> V_40 >= V_54 && V_2 -> V_41 <= V_54 ,
V_2 , L_49 , V_54 ) ;
F_7 ( ( V_25 -> V_206 & V_222 ) != 0 ) ;
F_58 ( V_180 ) ;
if ( V_2 -> V_34 == 0 )
V_2 -> V_8 = V_314 -> V_331 ;
else
F_7 ( V_2 -> V_8 == V_314 -> V_331 ) ;
++ V_2 -> V_34 ;
F_145 ( & V_25 -> V_132 , & V_2 -> V_35 ) ;
F_59 ( V_180 ) ;
}
return V_27 ;
}
int F_187 ( const struct V_62 * V_63 ,
struct V_19 * V_20 , struct V_184 * V_314 )
{
struct V_24 * V_25 = & V_314 -> V_316 ;
int V_27 = 0 ;
F_7 ( V_25 -> V_317 == V_318 ) ;
F_115 ( V_324 , L_50 ,
V_25 , V_314 , F_20 ( F_21 ( V_25 ) ) ) ;
if ( ! F_3 ( & V_25 -> V_131 ) ) {
F_115 ( V_71 , L_51 , V_25 ) ;
V_27 = - V_78 ;
} else if ( ! F_3 ( & V_25 -> V_132 ) ) {
struct V_1 * V_2 = NULL ;
F_58 ( V_20 ) ;
V_2 = F_45 ( V_20 , F_20 ( F_21 ( V_25 ) ) ) ;
F_59 ( V_20 ) ;
if ( V_2 && V_2 -> V_29 != V_83 ) {
F_22 ( V_55 , V_2 , L_52 ,
F_20 ( F_21 ( V_25 ) ) ) ;
V_27 = - V_78 ;
}
if ( V_2 )
F_37 ( V_63 , V_2 ) ;
}
return V_27 ;
}
int F_188 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_184 * V_314 )
{
struct V_1 * V_2 = NULL ;
struct V_19 * V_20 = F_189 ( V_314 -> V_195 . V_196 ) ;
struct V_156 * V_344 = V_314 -> V_195 . V_345 ;
T_2 V_54 = F_20 ( V_314 ) ;
struct V_24 * V_25 = & V_314 -> V_316 ;
bool V_346 = false ;
int V_27 = 0 ;
F_58 ( V_20 ) ;
V_2 = F_45 ( V_20 , V_54 ) ;
if ( ! V_2 ) {
F_79 ( V_55 , V_20 ) ;
F_74 ( 0 , L_53 , V_54 ) ;
}
switch ( V_2 -> V_29 ) {
case V_130 :
case V_295 :
F_190 ( V_55 , V_63 , V_344 , L_54 ) ;
F_7 ( 0 ) ;
break;
case V_165 :
case V_83 :
case V_36 :
V_27 = - V_177 ;
goto V_28;
default:
break;
}
V_27 = F_191 ( V_63 , V_148 , V_344 , V_187 ) ;
if ( V_27 )
goto V_28;
F_110 ( & V_25 -> V_169 ) ;
V_25 -> V_167 |= V_168 | V_347 ;
F_111 ( & V_25 -> V_169 ) ;
if ( F_192 () )
V_2 -> V_11 = 1 ;
V_2 -> V_10 = 1 ;
if ( V_2 -> V_29 == V_37 ) {
F_22 ( V_71 , V_2 ,
L_55 , V_25 ) ;
if ( F_3 ( & V_2 -> V_61 ) )
F_145 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
V_346 = true ;
}
V_27 = 0 ;
V_28:
F_59 ( V_20 ) ;
F_37 ( V_63 , V_2 ) ;
if ( V_346 )
F_69 ( V_63 , F_61 ( V_20 ) , V_20 ) ;
return V_27 ;
}
int F_193 ( const struct V_62 * V_63 , struct V_184 * V_314 )
{
struct V_24 * V_25 = & V_314 -> V_316 ;
struct V_19 * V_20 = V_25 -> V_243 ;
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_95 = NULL ;
struct V_14 * V_348 ;
T_2 V_54 = F_20 ( V_314 ) ;
int V_27 = - V_78 ;
int V_183 ;
F_7 ( ! V_25 -> V_290 ) ;
V_25 -> V_290 = 1 ;
F_58 ( V_20 ) ;
if ( V_25 -> V_291 & V_70 ) {
V_348 = & V_20 -> V_84 ;
V_183 = V_70 ;
} else {
V_348 = & V_20 -> V_271 ;
V_183 = V_194 ;
}
F_19 (ext, plist, oe_link) {
if ( V_2 -> V_41 <= V_54 && V_2 -> V_40 >= V_54 ) {
F_7 ( V_2 -> V_29 == V_295 ) ;
V_95 = F_35 ( V_2 ) ;
break;
}
}
if ( V_95 ) {
F_55 ( & V_95 -> V_61 ) ;
F_54 ( V_20 , V_183 , - V_95 -> V_34 ) ;
F_59 ( V_20 ) ;
F_82 ( V_63 , V_95 , 0 , - V_260 ) ;
F_37 ( V_63 , V_95 ) ;
V_27 = 0 ;
} else {
F_59 ( V_20 ) ;
if ( V_25 -> V_289 ) {
F_194 ( V_25 -> V_289 ) ;
F_195 ( V_25 -> V_289 ) ;
F_161 ( V_25 -> V_289 ) ;
V_25 -> V_289 = NULL ;
}
}
F_157 ( V_89 , V_20 ) ;
return V_27 ;
}
int F_196 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
struct V_14 * V_15 , int V_183 , int V_327 )
{
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_24 * V_25 , * V_56 ;
int V_26 = 0 ;
int V_349 = V_89 -> V_110 ;
bool V_350 = true ;
T_2 V_47 = V_351 ;
T_2 V_48 = 0 ;
F_19 (oap, list, oap_pending_item) {
struct V_184 * V_185 = F_117 ( V_25 ) ;
T_2 V_54 = F_20 ( V_185 ) ;
if ( V_54 > V_48 )
V_48 = V_54 ;
if ( V_54 < V_47 )
V_47 = V_54 ;
++ V_26 ;
V_349 <<= ( V_26 > V_349 ) ;
if ( F_170 ( V_185 -> V_340 > 0 || V_185 -> V_341 < V_135 ) )
V_350 = false ;
}
V_2 = F_26 ( V_20 ) ;
if ( ! V_2 ) {
F_85 (oap, tmp, list, oap_pending_item) {
F_55 ( & V_25 -> V_132 ) ;
F_86 ( V_63 , V_89 , V_25 , 0 , - V_101 ) ;
}
return - V_101 ;
}
V_2 -> V_5 = ! ! ( V_183 & V_194 ) ;
V_2 -> V_7 = 1 ;
V_2 -> V_301 = ! V_350 ;
V_2 -> V_10 = 1 ;
V_2 -> V_41 = V_47 ;
V_2 -> V_40 = V_48 ;
V_2 -> V_39 = V_48 ;
V_2 -> V_23 = V_20 ;
V_2 -> V_8 = ! ! ( V_327 & V_207 ) ;
V_2 -> V_34 = V_26 ;
V_2 -> V_52 = V_349 ;
F_64 ( V_15 , & V_2 -> V_35 ) ;
F_58 ( V_20 ) ;
F_24 ( V_2 , V_295 ) ;
if ( V_183 & V_70 ) {
F_145 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
F_54 ( V_20 , V_70 , V_26 ) ;
} else {
F_145 ( & V_2 -> V_61 , & V_20 -> V_271 ) ;
F_54 ( V_20 , V_194 , V_26 ) ;
}
F_59 ( V_20 ) ;
F_69 ( V_63 , V_89 , V_20 ) ;
return 0 ;
}
int F_197 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_6 V_352 , struct V_1 * * V_353 )
{
struct V_88 * V_89 = F_61 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_305 ;
struct V_1 * V_354 = NULL ;
T_2 V_54 ;
F_169 ( V_15 ) ;
int V_186 = 0 ;
bool V_146 ;
V_54 = F_198 ( F_18 ( V_20 ) , V_352 ) ;
V_146 = V_352 > F_17 ( F_18 ( V_20 ) , V_54 ) ;
V_355:
F_58 ( V_20 ) ;
V_2 = F_44 ( V_20 , V_54 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
else if ( V_2 -> V_40 < V_54 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
F_78 ( V_2 -> V_29 != V_83 , V_2 ) ;
if ( V_2 -> V_29 > V_37 || V_2 -> V_10 ) {
F_7 ( ! V_2 -> V_9 ) ;
F_22 ( V_71 , V_2 ,
L_56 ) ;
V_354 = F_35 ( V_2 ) ;
break;
}
F_22 ( V_71 , V_2 , L_57 , V_352 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_29 == V_36 ) {
F_7 ( ! V_2 -> V_12 ) ;
V_2 -> V_12 = 1 ;
} else {
F_78 ( V_2 -> V_29 == V_37 , V_2 ) ;
F_24 ( V_2 , V_83 ) ;
F_54 ( V_20 , V_70 ,
- V_2 -> V_34 ) ;
}
F_78 ( F_3 ( & V_2 -> V_61 ) , V_2 ) ;
F_145 ( & V_2 -> V_61 , & V_15 ) ;
V_2 = F_6 ( V_2 ) ;
}
F_59 ( V_20 ) ;
F_157 ( V_89 , V_20 ) ;
F_85 (ext, temp, &list, oe_link) {
int V_27 ;
F_55 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_29 != V_83 )
F_81 ( V_63 , V_2 , V_83 ) ;
V_27 = F_94 ( V_2 , V_54 , V_146 ) ;
if ( V_27 < 0 ) {
if ( V_186 == 0 )
V_186 = V_27 ;
F_22 ( V_55 , V_2 ,
L_58 , V_27 ) ;
} else if ( V_2 -> V_34 == 0 ) {
F_57 ( V_2 ) ;
} else {
F_47 ( V_2 -> V_41 <= V_54 , V_2 ,
L_59 , V_54 , V_146 ) ;
V_54 = V_2 -> V_40 + 1 ;
V_146 = false ;
F_7 ( ! * V_353 ) ;
* V_353 = F_35 ( V_2 ) ;
F_22 ( V_71 , V_2 ,
L_60 , V_352 ) ;
}
F_37 ( V_63 , V_2 ) ;
}
if ( V_354 ) {
int V_27 ;
V_27 = F_81 ( V_63 , V_354 , V_33 ) ;
if ( V_27 < 0 )
F_22 ( V_71 , V_354 , L_61 , V_27 ) ;
F_37 ( V_63 , V_354 ) ;
V_354 = NULL ;
goto V_355;
}
return V_186 ;
}
void F_199 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_19 * V_20 = V_2 -> V_23 ;
bool V_346 = false ;
F_78 ( V_2 -> V_34 > 0 , V_2 ) ;
F_78 ( V_2 -> V_29 == V_83 , V_2 ) ;
F_78 ( ! V_2 -> V_10 , V_2 ) ;
F_22 ( V_71 , V_2 , L_62 ) ;
F_58 ( V_20 ) ;
F_24 ( V_2 , V_37 ) ;
if ( V_2 -> V_13 && ! V_2 -> V_10 ) {
V_2 -> V_10 = 1 ;
F_68 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
V_346 = true ;
}
F_54 ( V_20 , V_70 , V_2 -> V_34 ) ;
F_59 ( V_20 ) ;
F_37 ( V_63 , V_2 ) ;
if ( V_346 )
F_69 ( V_63 , F_61 ( V_20 ) , V_20 ) ;
}
}
int F_200 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_2 V_47 , T_2 V_48 )
{
struct V_1 * V_2 ;
T_2 V_54 = V_47 ;
int V_186 = 0 ;
V_355:
F_58 ( V_20 ) ;
V_2 = F_44 ( V_20 , V_54 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
else if ( V_2 -> V_40 < V_54 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
int V_27 ;
if ( V_2 -> V_41 > V_48 )
break;
if ( ! V_2 -> V_13 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
F_78 ( F_83 ( V_2 -> V_29 == V_37 ,
V_2 -> V_9 || V_2 -> V_10 ) , V_2 ) ;
F_78 ( F_83 ( V_2 -> V_29 == V_36 ,
! V_2 -> V_9 && V_2 -> V_10 ) , V_2 ) ;
V_54 = V_2 -> V_40 + 1 ;
F_35 ( V_2 ) ;
F_59 ( V_20 ) ;
V_27 = F_81 ( V_63 , V_2 , V_33 ) ;
if ( V_186 == 0 )
V_186 = V_27 ;
F_37 ( V_63 , V_2 ) ;
goto V_355;
}
F_59 ( V_20 ) ;
F_153 ( V_20 , L_63 ) ;
return V_186 ;
}
int F_201 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_2 V_47 , T_2 V_48 , int V_356 , int V_357 )
{
struct V_1 * V_2 ;
F_169 ( V_358 ) ;
bool V_346 = false ;
int V_186 = 0 ;
F_58 ( V_20 ) ;
V_2 = F_44 ( V_20 , V_47 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
else if ( V_2 -> V_40 < V_47 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
if ( V_2 -> V_41 > V_48 )
break;
V_2 -> V_13 = 1 ;
switch ( V_2 -> V_29 ) {
case V_37 :
V_186 += V_2 -> V_34 ;
if ( ! V_357 ) {
struct V_14 * V_15 = NULL ;
if ( V_356 ) {
F_78 ( ! V_2 -> V_9 , V_2 ) ;
V_2 -> V_9 = 1 ;
V_15 = & V_20 -> V_265 ;
} else if ( ! V_2 -> V_10 ) {
V_2 -> V_10 = 1 ;
V_15 = & V_20 -> V_84 ;
}
if ( V_15 )
F_68 ( & V_2 -> V_61 , V_15 ) ;
V_346 = true ;
} else {
F_78 ( V_2 -> V_41 >= V_47 &&
V_2 -> V_39 <= V_48 , V_2 ) ;
F_24 ( V_2 , V_165 ) ;
V_2 -> V_166 = V_159 ;
F_68 ( & V_2 -> V_61 , & V_358 ) ;
F_54 ( V_20 , V_70 ,
- V_2 -> V_34 ) ;
}
break;
case V_36 :
F_7 ( V_356 == 0 && V_357 == 0 ) ;
V_2 -> V_10 = 1 ;
break;
case V_83 :
default:
break;
}
V_2 = F_6 ( V_2 ) ;
}
F_59 ( V_20 ) ;
F_7 ( F_83 ( ! V_357 , F_3 ( & V_358 ) ) ) ;
if ( ! F_3 ( & V_358 ) ) {
struct V_1 * V_56 ;
int V_27 ;
F_157 ( F_61 ( V_20 ) , V_20 ) ;
F_85 (ext, tmp, &discard_list, oe_link) {
F_55 ( & V_2 -> V_61 ) ;
F_78 ( V_2 -> V_29 == V_165 , V_2 ) ;
V_27 = F_108 ( V_63 , V_2 ) ;
if ( F_170 ( V_27 < 0 ) ) {
F_22 ( V_55 , V_2 ,
L_64 , V_27 ) ;
if ( V_186 >= 0 )
V_186 = V_27 ;
}
F_82 ( V_63 , V_2 , 0 , 0 ) ;
}
}
if ( V_346 )
F_178 ( V_63 , F_61 ( V_20 ) , V_20 ) ;
if ( V_356 || V_357 ) {
int V_27 ;
V_27 = F_200 ( V_63 , V_20 , V_47 , V_48 ) ;
if ( V_186 >= 0 && V_27 < 0 )
V_186 = V_27 ;
}
F_153 ( V_20 , L_65 , V_47 , V_48 , V_186 ) ;
return V_186 ;
}
int F_202 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_19 * V_180 , T_2 V_47 , T_2 V_48 ,
T_7 V_359 , void * V_360 )
{
struct V_184 * V_314 ;
void * * V_361 ;
T_2 V_362 ;
unsigned int V_363 ;
unsigned int V_364 ;
unsigned int V_365 ;
int V_366 = V_367 ;
bool V_368 = true ;
V_362 = V_47 ;
V_361 = F_96 ( V_63 ) -> V_369 ;
F_110 ( & V_180 -> V_370 ) ;
while ( ( V_363 = F_203 ( & V_180 -> V_371 , V_361 ,
V_362 , V_372 ) ) > 0 ) {
struct V_156 * V_157 ;
bool V_373 = false ;
for ( V_364 = 0 , V_365 = 0 ; V_364 < V_363 ; ++ V_364 ) {
V_314 = V_361 [ V_364 ] ;
V_361 [ V_364 ] = NULL ;
V_362 = F_20 ( V_314 ) ;
if ( V_362 > V_48 ) {
V_373 = true ;
break;
}
V_157 = V_314 -> V_195 . V_345 ;
F_7 ( V_157 -> V_300 == V_374 ) ;
if ( V_157 -> V_160 == V_161 )
continue;
F_100 ( V_157 ) ;
F_204 ( & V_157 -> V_158 ,
L_66 , V_159 ) ;
V_361 [ V_365 ++ ] = V_314 ;
}
++ V_362 ;
F_111 ( & V_180 -> V_370 ) ;
V_368 = false ;
for ( V_364 = 0 ; V_364 < V_365 ; ++ V_364 ) {
V_314 = V_361 [ V_364 ] ;
if ( V_366 == V_367 )
V_366 = (* V_359)( V_63 , V_148 , V_314 , V_360 ) ;
V_157 = V_314 -> V_195 . V_345 ;
F_104 ( & V_157 -> V_158 , L_66 , V_159 ) ;
F_105 ( V_63 , V_157 ) ;
}
if ( V_363 < V_372 || V_373 )
break;
if ( V_366 == V_367 && F_205 () )
V_366 = V_375 ;
if ( V_366 != V_367 )
break;
F_110 ( & V_180 -> V_370 ) ;
V_368 = true ;
}
if ( V_368 )
F_111 ( & V_180 -> V_370 ) ;
return V_366 ;
}
static int F_206 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_184 * V_314 , void * V_360 )
{
struct V_376 * V_377 = F_96 ( V_63 ) ;
struct V_19 * V_180 = V_360 ;
T_2 V_54 ;
V_54 = F_20 ( V_314 ) ;
if ( V_54 >= V_377 -> V_378 ) {
struct V_379 * V_56 ;
struct V_156 * V_157 = V_314 -> V_195 . V_345 ;
V_56 = F_207 ( V_63 , V_180 , V_54 ,
V_380 ) ;
if ( V_56 ) {
T_3 V_48 = V_56 -> V_45 . V_46 . V_48 ;
V_377 -> V_378 = F_198 ( F_18 ( V_180 ) , V_48 + 1 ) ;
if ( V_48 == V_381 )
V_377 -> V_378 = V_351 ;
F_40 ( V_56 ) ;
} else if ( F_101 ( V_63 , V_148 , V_157 ) == 0 ) {
F_102 ( V_63 , V_148 , V_157 ) ;
F_103 ( V_63 , V_148 , V_157 ) ;
} else {
F_7 ( V_157 -> V_160 == V_161 ) ;
}
}
V_377 -> V_382 = V_54 + 1 ;
return V_367 ;
}
static int F_208 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_184 * V_314 , void * V_360 )
{
struct V_376 * V_377 = F_96 ( V_63 ) ;
struct V_156 * V_157 = V_314 -> V_195 . V_345 ;
V_377 -> V_382 = F_20 ( V_314 ) + 1 ;
if ( F_101 ( V_63 , V_148 , V_157 ) == 0 ) {
if ( V_157 -> V_300 == V_374 &&
F_209 ( F_210 ( V_157 ) ) )
F_190 ( V_55 , V_63 , V_157 ,
L_67 ) ;
F_102 ( V_63 , V_148 , V_157 ) ;
F_103 ( V_63 , V_148 , V_157 ) ;
} else {
F_7 ( V_157 -> V_160 == V_161 ) ;
}
return V_367 ;
}
int F_211 ( const struct V_62 * V_63 , struct V_19 * V_180 ,
T_2 V_47 , T_2 V_48 , enum V_383 V_384 )
{
struct V_376 * V_377 = F_96 ( V_63 ) ;
struct V_147 * V_148 = & V_377 -> V_152 ;
T_7 V_359 ;
int V_366 ;
int V_186 ;
V_148 -> V_153 = F_97 ( F_18 ( V_180 ) ) ;
V_148 -> V_154 = 1 ;
V_186 = F_98 ( V_63 , V_148 , V_155 , V_148 -> V_153 ) ;
if ( V_186 != 0 )
goto V_28;
V_359 = V_384 == V_385 ? F_206 : F_208 ;
V_377 -> V_378 = V_47 ;
V_377 -> V_382 = V_47 ;
do {
V_366 = F_202 ( V_63 , V_148 , V_180 ,
V_377 -> V_382 , V_48 , V_359 , V_180 ) ;
if ( V_377 -> V_382 > V_48 )
break;
if ( V_366 == V_375 )
F_212 () ;
} while ( V_366 != V_367 );
V_28:
F_106 ( V_63 , V_148 ) ;
return V_186 ;
}
