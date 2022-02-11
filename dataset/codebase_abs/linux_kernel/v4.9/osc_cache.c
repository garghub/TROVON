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
if ( ! V_17 )
return NULL ;
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
if ( V_2 -> V_42 ) {
struct V_43 * V_44 ;
V_44 = & V_2 -> V_42 -> V_45 . V_46 ;
if ( ! ( V_44 -> V_47 <= F_16 ( F_17 ( V_20 ) , V_2 -> V_41 ) &&
V_44 -> V_48 >= F_16 ( F_17 ( V_20 ) , V_2 -> V_39 ) ) ) {
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
F_18 (oap, &ext->oe_pages, oap_pending_item) {
T_2 V_54 = F_19 ( F_20 ( V_25 ) ) ;
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
F_21 ( V_55 , V_2 ,
L_1 ,
V_22 , line , V_2 , V_27 ) ;
return V_27 ;
}
static int F_22 ( struct V_19 * V_20 ,
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
static void F_23 ( struct V_1 * V_2 , int V_57 )
{
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_7 ( V_57 >= V_33 && V_57 < V_30 ) ;
V_2 -> V_29 = V_57 ;
F_24 ( & V_2 -> V_58 ) ;
}
static struct V_1 * F_25 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_59 , V_60 ) ;
if ( ! V_2 )
return NULL ;
F_27 ( & V_2 -> V_18 ) ;
V_2 -> V_23 = V_20 ;
F_28 ( & V_2 -> V_31 , 1 ) ;
F_28 ( & V_2 -> V_32 , 0 ) ;
F_29 ( & V_2 -> V_61 ) ;
V_2 -> V_29 = V_33 ;
F_29 ( & V_2 -> V_35 ) ;
F_30 ( & V_2 -> V_58 ) ;
V_2 -> V_42 = NULL ;
return V_2 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_59 , V_2 ) ;
}
static struct V_1 * F_33 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) >= 0 ) ;
F_34 ( & V_2 -> V_31 ) ;
return V_2 ;
}
static void F_35 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) > 0 ) ;
if ( F_36 ( & V_2 -> V_31 ) ) {
F_7 ( F_3 ( & V_2 -> V_61 ) ) ;
F_7 ( F_15 ( & V_2 -> V_32 ) == 0 ) ;
F_7 ( V_2 -> V_29 == V_33 ) ;
F_7 ( ! V_2 -> V_6 ) ;
if ( V_2 -> V_42 ) {
F_37 ( & V_2 -> V_42 -> V_64 ,
L_2 , V_2 ) ;
F_38 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
}
F_31 ( V_2 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) > 1 ) ;
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_40 ( & V_2 -> V_31 ) ;
}
static struct V_1 * F_41 ( struct V_19 * V_20 ,
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
static struct V_1 * F_42 ( struct V_19 * V_20 ,
T_2 V_54 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( V_20 , V_54 ) ;
if ( V_2 && V_2 -> V_41 <= V_54 && V_54 <= V_2 -> V_40 )
return F_33 ( V_2 ) ;
return NULL ;
}
static void F_43 ( struct V_19 * V_20 , struct V_1 * V_2 )
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
F_44 ( 0 , V_56 , V_69 L_3 , F_45 ( V_2 ) ) ;
}
F_46 ( & V_2 -> V_18 , V_68 , V_17 ) ;
F_47 ( & V_2 -> V_18 , & V_20 -> V_21 ) ;
F_33 ( V_2 ) ;
V_2 -> V_6 = 1 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_14 ( V_20 ) ) ;
if ( V_2 -> V_6 ) {
F_49 ( & V_2 -> V_18 , & V_20 -> V_21 ) ;
V_2 -> V_6 = 0 ;
F_39 ( V_2 ) ;
}
}
static struct V_1 * F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_14 ( V_20 ) ) ;
F_7 ( V_2 -> V_29 == V_36 || V_2 -> V_29 == V_37 ) ;
if ( V_2 -> V_29 == V_37 ) {
F_23 ( V_2 , V_36 ) ;
F_51 ( V_20 , V_70 , - V_2 -> V_34 ) ;
}
F_34 ( & V_2 -> V_32 ) ;
F_52 ( & V_2 -> V_61 ) ;
return F_33 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_7 ( F_3 ( & V_2 -> V_35 ) ) ;
F_48 ( V_2 ) ;
F_52 ( & V_2 -> V_61 ) ;
F_23 ( V_2 , V_33 ) ;
F_21 ( V_71 , V_2 , L_4 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_55 ( V_20 ) ;
F_53 ( V_2 ) ;
F_56 ( V_20 ) ;
}
static int F_57 ( const struct V_62 * V_63 , struct V_1 * V_72 ,
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
V_76 = F_58 ( V_20 ) -> V_80 - V_81 ;
V_74 = V_72 -> V_41 >> V_76 ;
V_75 = V_72 -> V_40 >> V_76 ;
if ( V_74 != ( V_73 -> V_40 >> V_76 ) + 1 &&
V_75 + 1 != V_73 -> V_41 >> V_76 )
return - V_79 ;
F_21 ( V_71 , V_73 , L_5 , V_72 ) ;
V_72 -> V_41 = F_59 ( V_72 -> V_41 , V_73 -> V_41 ) ;
V_72 -> V_40 = F_60 ( V_72 -> V_40 , V_73 -> V_40 ) ;
V_72 -> V_38 += V_73 -> V_38 ;
V_72 -> V_34 += V_73 -> V_34 ;
V_72 -> V_10 |= V_73 -> V_10 ;
V_72 -> V_11 |= V_73 -> V_11 ;
F_61 ( & V_73 -> V_35 , & V_72 -> V_35 ) ;
F_52 ( & V_73 -> V_61 ) ;
V_73 -> V_34 = 0 ;
F_33 ( V_73 ) ;
F_53 ( V_73 ) ;
F_35 ( V_63 , V_73 ) ;
F_21 ( V_71 , V_72 , L_6 , V_73 ) ;
return 0 ;
}
void F_62 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_15 ( & V_2 -> V_32 ) > 0 ) ;
F_7 ( F_63 ( V_2 ) == 0 ) ;
F_7 ( V_2 -> V_38 > 0 ) ;
if ( F_64 ( & V_2 -> V_32 , & V_20 -> V_82 ) ) {
F_7 ( V_2 -> V_29 == V_36 ) ;
if ( V_2 -> V_12 ) {
F_23 ( V_2 , V_83 ) ;
V_2 -> V_12 = 0 ;
} else {
F_23 ( V_2 , V_37 ) ;
F_51 ( V_20 , V_70 ,
V_2 -> V_34 ) ;
F_57 ( V_63 , V_2 , F_9 ( V_2 ) ) ;
F_57 ( V_63 , V_2 , F_6 ( V_2 ) ) ;
if ( V_2 -> V_10 )
F_65 ( & V_2 -> V_61 ,
& V_20 -> V_84 ) ;
}
F_56 ( V_20 ) ;
F_66 ( V_63 , F_58 ( V_20 ) , V_20 ) ;
}
F_35 ( V_63 , V_2 ) ;
}
static inline int F_67 ( struct V_1 * V_85 , struct V_1 * V_86 )
{
return ! ( V_85 -> V_40 < V_86 -> V_41 || V_86 -> V_40 < V_85 -> V_41 ) ;
}
static struct V_1 * F_68 ( const struct V_62 * V_63 ,
struct V_19 * V_20 , T_2 V_54 ,
unsigned int * V_87 )
{
struct V_88 * V_89 = F_58 ( V_20 ) ;
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
V_72 = F_25 ( V_20 ) ;
if ( ! V_72 )
return F_69 ( - V_101 ) ;
V_91 = F_70 ( V_63 ) -> V_102 ;
F_71 ( V_91 , L_7 , V_54 ) ;
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
V_97 = F_72 ( T_2 , V_97 , V_93 -> V_111 ) ;
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
V_72 -> V_42 = F_73 ( V_91 -> V_113 ) ;
F_37 ( & V_91 -> V_113 -> V_64 , L_2 , V_72 ) ;
}
F_71 ( * V_87 >= V_99 + V_89 -> V_115 ,
L_8 , * V_87 , V_99 , V_89 -> V_115 ) ;
F_71 ( ( V_97 - V_72 -> V_41 ) < V_98 , V_69 L_3 ,
F_45 ( V_72 ) ) ;
V_116:
F_55 ( V_20 ) ;
V_2 = F_41 ( V_20 , V_72 -> V_41 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
while ( V_2 ) {
T_2 V_117 = V_2 -> V_41 >> V_76 ;
T_2 V_118 = V_2 -> V_40 >> V_76 ;
F_7 ( F_74 ( V_2 ) == 0 ) ;
if ( V_96 > V_118 + 1 )
break;
if ( V_91 -> V_113 != V_2 -> V_42 ) {
F_44 ( ! F_67 ( V_2 , V_72 ) , V_2 ,
V_69 L_3 , F_45 ( V_72 ) ) ;
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_96 + 1 < V_117 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( F_67 ( V_2 , V_72 ) ) {
F_44 ( ( V_2 -> V_41 <= V_72 -> V_41 &&
V_2 -> V_40 >= V_72 -> V_40 ) ,
V_2 , V_69 L_3 , F_45 ( V_72 ) ) ;
if ( V_2 -> V_29 > V_37 || V_2 -> V_13 ) {
V_94 = F_33 ( V_2 ) ;
break;
}
V_95 = F_50 ( V_2 ) ;
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
F_75 ( ( V_2 -> V_41 & ~ V_100 ) == 0 , V_2 ) ;
V_2 -> V_41 = V_72 -> V_41 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
V_95 = F_50 ( V_2 ) ;
} else if ( V_96 == V_118 + 1 ) {
V_2 -> V_40 = V_72 -> V_40 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
if ( F_57 ( V_63 , V_2 , F_6 ( V_2 ) ) == 0 )
* V_87 += V_89 -> V_115 ;
V_95 = F_50 ( V_2 ) ;
}
if ( V_95 )
break;
V_2 = F_6 ( V_2 ) ;
}
F_76 ( V_71 , V_20 ) ;
if ( V_95 ) {
F_7 ( ! V_94 ) ;
if ( ! F_77 ( V_95 ) ) {
F_7 ( V_95 -> V_42 == V_72 -> V_42 ) ;
F_21 ( V_71 , V_95 ,
L_9 , V_54 ) ;
}
} else if ( ! V_94 ) {
F_75 ( F_22 ( V_20 , V_72 ) == 0 , V_72 ) ;
V_72 -> V_38 = V_99 + V_89 -> V_115 ;
* V_87 -= V_72 -> V_38 ;
F_7 ( * V_87 >= 0 ) ;
V_72 -> V_29 = V_37 ;
V_95 = F_50 ( V_72 ) ;
F_43 ( V_20 , V_72 ) ;
F_21 ( V_71 , V_72 , L_10 ,
V_54 , V_93 -> V_111 ) ;
}
F_56 ( V_20 ) ;
if ( V_94 ) {
F_7 ( ! V_95 ) ;
V_27 = F_78 ( V_63 , V_94 , V_33 ) ;
F_35 ( V_63 , V_94 ) ;
V_94 = NULL ;
if ( V_27 < 0 ) {
V_95 = F_69 ( V_27 ) ;
goto V_28;
}
goto V_116;
}
V_28:
F_35 ( V_63 , V_72 ) ;
F_7 ( * V_87 >= 0 ) ;
return V_95 ;
}
int F_79 ( const struct V_62 * V_63 , struct V_1 * V_2 ,
int V_119 , int V_27 )
{
struct V_88 * V_89 = F_58 ( V_2 -> V_23 ) ;
struct V_24 * V_25 ;
struct V_24 * V_56 ;
int V_120 = V_2 -> V_34 ;
int V_121 = 0 ;
int V_122 = V_89 -> V_123 -> V_124 -> V_125 . V_126 ? : 4096 ;
T_3 V_127 = 0 ;
int V_128 = - 1 ;
F_21 ( V_71 , V_2 , L_11 ) ;
V_2 -> V_129 = V_27 ? : V_2 -> V_34 ;
F_75 ( F_80 ( V_27 == 0 , V_2 -> V_29 == V_130 ) , V_2 ) ;
F_81 ( V_89 , & V_2 -> V_35 ) ;
F_82 (oap, tmp, &ext->oe_pages, oap_pending_item) {
F_52 ( & V_25 -> V_131 ) ;
F_52 ( & V_25 -> V_132 ) ;
if ( V_127 <= V_25 -> V_133 ) {
V_127 = V_25 -> V_133 ;
V_128 = V_25 -> V_134 ;
}
-- V_2 -> V_34 ;
F_83 ( V_63 , V_89 , V_25 , V_119 , V_27 ) ;
}
F_75 ( V_2 -> V_34 == 0 , V_2 ) ;
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
F_84 ( V_89 , V_120 , V_121 ) ;
F_54 ( V_2 ) ;
F_35 ( V_63 , V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , enum V_139 V_57 )
{
int V_140 ;
F_55 ( V_2 -> V_23 ) ;
V_140 = V_2 -> V_29 == V_57 ;
F_56 ( V_2 -> V_23 ) ;
return V_140 ;
}
static int F_78 ( const struct V_62 * V_63 , struct V_1 * V_2 ,
enum V_139 V_57 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_141 V_142 = F_86 ( F_87 ( 600 ) , NULL ,
V_143 , NULL ) ;
int V_27 = 0 ;
F_55 ( V_20 ) ;
F_7 ( F_74 ( V_2 ) == 0 ) ;
if ( V_57 == V_33 && ! V_2 -> V_10 && ! V_2 -> V_9 &&
! V_2 -> V_12 ) {
if ( V_2 -> V_29 == V_36 ) {
V_2 -> V_10 = 1 ;
} else if ( V_2 -> V_29 == V_37 ) {
V_2 -> V_10 = 1 ;
F_50 ( V_2 ) ;
V_27 = 1 ;
}
}
F_56 ( V_20 ) ;
if ( V_27 == 1 )
F_62 ( V_63 , V_2 ) ;
V_27 = F_88 ( V_2 -> V_58 , F_85 ( V_2 , V_57 ) , & V_142 ) ;
if ( V_27 == - V_144 ) {
F_21 ( V_55 , V_2 ,
L_12 ,
F_89 ( V_20 ) -> V_145 -> V_146 , V_57 ) ;
V_142 = F_90 ( NULL , NULL ) ;
V_27 = F_88 ( V_2 -> V_58 , F_85 ( V_2 , V_57 ) ,
& V_142 ) ;
}
if ( V_27 == 0 && V_2 -> V_129 < 0 )
V_27 = V_2 -> V_129 ;
return V_27 ;
}
static int F_91 ( struct V_1 * V_2 , T_2 V_147 ,
bool V_148 )
{
struct V_149 V_150 ;
struct V_62 * V_63 ;
struct V_151 * V_152 ;
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_88 * V_89 = F_58 ( V_20 ) ;
struct V_24 * V_25 ;
struct V_24 * V_56 ;
int V_153 = 0 ;
int V_76 = V_89 -> V_80 - V_81 ;
T_3 V_154 = V_147 >> V_76 ;
int V_87 = 0 ;
int V_120 = 0 ;
int V_27 = 0 ;
F_7 ( F_63 ( V_2 ) == 0 ) ;
F_75 ( V_2 -> V_29 == V_83 , V_2 ) ;
F_75 ( ! V_2 -> V_10 , V_2 ) ;
V_63 = F_92 ( & V_150 ) ;
V_152 = & F_93 ( V_63 ) -> V_155 ;
V_152 -> V_156 = F_94 ( F_17 ( V_20 ) ) ;
V_27 = F_95 ( V_63 , V_152 , V_157 , V_152 -> V_156 ) ;
if ( V_27 < 0 )
goto V_28;
F_82 (oap, tmp, &ext->oe_pages, oap_pending_item) {
T_2 V_54 = F_19 ( F_20 ( V_25 ) ) ;
struct V_158 * V_159 = F_96 ( V_25 ) ;
F_7 ( F_3 ( & V_25 -> V_131 ) ) ;
if ( V_54 < V_147 ||
( V_54 == V_147 && V_148 ) ) {
if ( V_54 >> V_76 == V_154 )
++ V_153 ;
continue;
}
F_52 ( & V_25 -> V_132 ) ;
F_97 ( V_159 ) ;
F_37 ( & V_159 -> V_160 , L_13 , V_161 ) ;
if ( F_98 ( V_63 , V_152 , V_159 ) == 0 ) {
F_99 ( V_63 , V_152 , V_159 ) ;
F_100 ( V_63 , V_152 , V_159 ) ;
} else {
F_7 ( V_159 -> V_162 == V_163 ) ;
F_7 ( 0 ) ;
}
F_101 ( & V_159 -> V_160 , L_13 , V_161 ) ;
F_102 ( V_63 , V_159 ) ;
-- V_2 -> V_34 ;
++ V_120 ;
}
F_44 ( F_80 ( V_2 -> V_41 >= V_147 + ! ! V_148 ,
V_2 -> V_34 == 0 ) ,
V_2 , L_14 , V_147 , V_148 ) ;
F_55 ( V_20 ) ;
if ( V_2 -> V_34 == 0 ) {
F_7 ( V_153 == 0 ) ;
V_87 = V_2 -> V_38 ;
V_2 -> V_38 = 0 ;
} else {
int V_164 = ( V_2 -> V_40 >> V_76 ) - V_154 ;
T_2 V_165 ;
if ( V_153 == 0 ) {
F_7 ( V_154 > 0 ) ;
-- V_154 ;
++ V_164 ;
}
V_87 = V_164 << V_89 -> V_80 ;
V_2 -> V_38 -= V_87 ;
V_165 = ( ( V_154 + 1 ) << V_76 ) - 1 ;
V_2 -> V_40 = F_59 ( V_165 , V_2 -> V_39 ) ;
F_7 ( V_2 -> V_40 >= V_2 -> V_41 ) ;
F_7 ( V_2 -> V_38 > 0 ) ;
}
F_56 ( V_20 ) ;
if ( V_87 > 0 || V_120 > 0 )
F_84 ( V_89 , V_120 , V_87 ) ;
V_28:
F_103 ( V_63 , V_152 ) ;
F_104 ( & V_150 , V_63 ) ;
return V_27 ;
}
static int F_105 ( const struct V_62 * V_63 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_24 * V_166 = NULL ;
struct V_19 * V_20 = V_2 -> V_23 ;
unsigned int V_26 = 0 ;
int V_27 ;
F_7 ( F_63 ( V_2 ) == 0 ) ;
F_75 ( V_2 -> V_29 == V_167 , V_2 ) ;
F_75 ( V_2 -> V_168 , V_2 ) ;
F_21 ( V_71 , V_2 , L_15 ) ;
F_18 (oap, &ext->oe_pages, oap_pending_item) {
++ V_26 ;
if ( ! V_166 || V_166 -> V_133 < V_25 -> V_133 )
V_166 = V_25 ;
if ( ( V_25 -> V_169 & V_170 ) != 0 )
continue;
V_27 = F_106 ( V_63 , V_25 , V_70 ) ;
switch ( V_27 ) {
case 0 :
F_107 ( & V_25 -> V_171 ) ;
V_25 -> V_169 |= V_170 ;
F_108 ( & V_25 -> V_171 ) ;
break;
case - V_172 :
F_7 ( ( V_25 -> V_169 & V_170 ) != 0 ) ;
break;
default:
F_71 ( 0 , L_16 , V_27 ) ;
}
}
F_7 ( V_26 == V_2 -> V_34 ) ;
F_7 ( V_166 ) ;
if ( ! ( V_166 -> V_169 & V_173 ) ) {
int V_174 = F_109 ( V_63 , V_166 , V_70 ) ;
F_7 ( V_174 > 0 ) ;
F_7 ( V_166 -> V_175 + V_174 <= V_135 ) ;
V_166 -> V_134 = V_174 ;
F_107 ( & V_166 -> V_171 ) ;
V_166 -> V_169 |= V_173 ;
F_108 ( & V_166 -> V_171 ) ;
}
F_18 (oap, &ext->oe_pages, oap_pending_item) {
if ( ! ( V_25 -> V_169 & V_173 ) ) {
V_25 -> V_134 = V_135 - V_25 -> V_175 ;
F_107 ( & V_166 -> V_171 ) ;
V_25 -> V_169 |= V_173 ;
F_108 ( & V_166 -> V_171 ) ;
}
}
F_55 ( V_20 ) ;
F_23 ( V_2 , V_130 ) ;
F_56 ( V_20 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , T_2 V_54 ,
unsigned int * V_87 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_88 * V_89 = F_58 ( V_20 ) ;
struct V_1 * V_176 ;
int V_76 = V_89 -> V_80 - V_81 ;
T_2 V_96 = V_54 >> V_76 ;
T_2 V_177 ;
T_2 V_178 ;
unsigned int V_99 = 1 << V_89 -> V_80 ;
int V_27 = 0 ;
F_7 ( V_2 -> V_39 >= V_54 && V_2 -> V_41 <= V_54 ) ;
F_55 ( V_20 ) ;
F_7 ( F_74 ( V_2 ) == 0 ) ;
V_177 = V_2 -> V_40 >> V_76 ;
if ( V_96 > V_177 + 1 ) {
V_27 = - V_79 ;
goto V_28;
}
if ( V_177 >= V_96 ) {
V_27 = 0 ;
goto V_28;
}
F_7 ( V_177 + 1 == V_96 ) ;
V_178 = F_59 ( V_2 -> V_39 , ( ( V_96 + 1 ) << V_76 ) - 1 ) ;
V_176 = F_6 ( V_2 ) ;
if ( V_176 && V_176 -> V_41 <= V_178 ) {
V_27 = - V_179 ;
goto V_28;
}
V_2 -> V_40 = V_178 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
F_7 ( * V_87 >= 0 ) ;
F_44 ( F_22 ( V_20 , V_2 ) == 0 , V_2 ,
L_17 , V_54 ) ;
V_28:
F_56 ( V_20 ) ;
return V_27 ;
}
static void F_111 ( int V_180 , struct V_19 * V_20 ,
const char * V_22 , int line )
{
struct V_1 * V_2 ;
int V_181 ;
F_112 ( V_180 , L_18 ,
V_20 , V_22 , line , F_58 ( V_20 ) -> V_110 ) ;
V_181 = 1 ;
for ( V_2 = F_11 ( V_20 ) ; V_2 ; V_2 = F_6 ( V_2 ) )
F_21 ( V_180 , V_2 , L_19 , V_181 ++ ) ;
V_181 = 1 ;
F_18 (ext, &obj->oo_hp_exts, oe_link)
F_21 ( V_180 , V_2 , L_20 , V_181 ++ ) ;
V_181 = 1 ;
F_18 (ext, &obj->oo_urgent_exts, oe_link)
F_21 ( V_180 , V_2 , L_21 , V_181 ++ ) ;
V_181 = 1 ;
F_18 (ext, &obj->oo_reading_exts, oe_link)
F_21 ( V_180 , V_2 , L_22 , V_181 ++ ) ;
}
static inline int F_113 ( struct V_19 * V_182 )
{
return ! F_3 ( & V_182 -> V_183 ) ||
! F_3 ( & V_182 -> V_184 ) ;
}
static int F_106 ( const struct V_62 * V_63 , struct V_24 * V_25 ,
int V_185 )
{
struct V_186 * V_187 = F_114 ( V_25 ) ;
struct V_158 * V_159 = F_96 ( V_25 ) ;
int V_188 ;
F_7 ( V_185 == V_70 ) ;
V_188 = F_115 ( V_63 , V_159 , V_189 ) ;
if ( V_188 == 0 )
V_187 -> V_190 = F_116 () ;
return V_188 ;
}
static int F_109 ( const struct V_62 * V_63 ,
struct V_24 * V_25 , int V_185 )
{
struct V_186 * V_187 = F_114 ( V_25 ) ;
T_2 V_54 = F_19 ( F_20 ( V_25 ) ) ;
struct V_191 * V_20 ;
struct V_192 * V_193 = & F_93 ( V_63 ) -> V_194 ;
int V_188 ;
T_4 V_195 ;
F_7 ( ! ( V_185 & V_196 ) ) ;
V_20 = V_187 -> V_197 . V_198 ;
F_117 ( V_20 ) ;
V_188 = F_118 ( V_63 , V_20 , V_193 ) ;
F_119 ( V_20 ) ;
if ( V_188 < 0 )
return V_188 ;
V_195 = V_193 -> V_199 ;
if ( F_16 ( V_20 , V_54 ) >= V_195 )
return 0 ;
else if ( F_16 ( V_20 , V_54 + 1 ) > V_195 )
return V_195 % V_135 ;
else
return V_135 ;
}
static int F_120 ( const struct V_62 * V_63 , struct V_24 * V_25 ,
int V_185 , int V_27 )
{
struct V_186 * V_187 = F_114 ( V_25 ) ;
struct V_158 * V_159 = F_96 ( V_25 ) ;
struct V_19 * V_20 = F_121 ( V_187 -> V_197 . V_198 ) ;
enum V_200 V_201 ;
int V_202 ;
V_185 &= ~ V_203 ;
F_71 ( F_122 ( V_159 -> V_162 == V_204 , V_185 == V_196 ) ,
L_23 , V_159 -> V_162 , V_185 ) ;
F_71 ( F_122 ( V_159 -> V_162 == V_205 , V_185 == V_70 ) ,
L_23 , V_159 -> V_162 , V_185 ) ;
F_7 ( V_187 -> V_206 ) ;
if ( V_159 -> V_207 )
F_123 ( V_63 , V_159 ) ;
F_7 ( ! V_159 -> V_207 ) ;
V_201 = V_185 == V_196 ? V_208 : V_189 ;
V_187 -> V_206 = 0 ;
F_107 ( & V_20 -> V_209 ) ;
F_7 ( V_187 -> V_210 ) ;
F_7 ( ! F_3 ( & V_187 -> V_211 ) ) ;
F_52 ( & V_187 -> V_211 ) ;
V_187 -> V_210 = NULL ;
F_108 ( & V_20 -> V_209 ) ;
V_187 -> V_190 = 0 ;
V_202 = V_25 -> V_212 & V_213 ;
if ( V_27 == 0 && V_202 ) {
struct V_214 * V_215 = V_187 -> V_197 . V_198 -> V_216 . V_217 ;
struct V_218 * V_219 = & F_124 ( V_215 ) -> V_220 ;
T_1 V_221 = V_25 -> V_134 ;
if ( V_201 == V_208 )
V_219 -> V_222 += V_221 ;
else
V_219 -> V_223 += V_221 ;
}
F_101 ( & V_159 -> V_160 , L_24 , V_159 ) ;
F_125 ( V_63 , V_159 , V_201 , V_27 ) ;
return 0 ;
}
static void F_126 ( struct V_88 * V_89 ,
struct V_224 * V_225 )
{
F_127 ( & V_89 -> V_226 ) ;
F_7 ( ! ( V_225 -> V_227 & V_228 ) ) ;
F_128 ( & V_229 ) ;
V_89 -> V_230 ++ ;
V_225 -> V_227 |= V_228 ;
F_112 ( V_71 , L_25 ,
V_135 , V_225 , V_225 -> V_231 ) ;
F_129 ( V_89 ) ;
}
static void F_130 ( struct V_88 * V_89 ,
struct V_224 * V_225 )
{
F_127 ( & V_89 -> V_226 ) ;
if ( ! ( V_225 -> V_227 & V_228 ) ) {
return;
}
V_225 -> V_227 &= ~ V_228 ;
F_131 ( & V_229 ) ;
V_89 -> V_230 -- ;
if ( V_225 -> V_227 & V_232 ) {
V_225 -> V_227 &= ~ V_232 ;
F_131 ( & V_233 ) ;
V_89 -> V_234 -- ;
}
}
static int F_132 ( struct V_88 * V_89 , unsigned int V_221 )
{
int V_27 = - V_235 ;
if ( V_89 -> V_236 >= V_221 ) {
V_89 -> V_236 -= V_221 ;
V_89 -> V_237 += V_221 ;
V_27 = 0 ;
}
return V_27 ;
}
static void F_133 ( struct V_88 * V_89 ,
unsigned int V_238 , unsigned int V_239 )
{
V_89 -> V_237 -= V_238 ;
if ( V_239 > V_238 ) {
V_89 -> V_236 += V_238 ;
V_89 -> V_240 += V_239 - V_238 ;
} else {
V_89 -> V_236 += V_239 ;
}
}
static void F_134 ( struct V_88 * V_89 ,
unsigned int V_238 , unsigned int V_239 )
{
F_107 ( & V_89 -> V_226 ) ;
F_133 ( V_89 , V_238 , V_239 ) ;
if ( V_239 > 0 )
F_135 ( V_89 ) ;
F_108 ( & V_89 -> V_226 ) ;
}
static void F_84 ( struct V_88 * V_89 , unsigned int V_120 ,
unsigned int V_121 )
{
unsigned long V_241 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
F_107 ( & V_89 -> V_226 ) ;
F_136 ( V_120 , & V_229 ) ;
V_89 -> V_230 -= V_120 ;
V_89 -> V_240 += V_121 ;
if ( V_89 -> V_236 < V_241 && V_89 -> V_240 >= V_241 ) {
V_89 -> V_240 -= V_241 ;
V_89 -> V_236 += V_241 ;
}
F_135 ( V_89 ) ;
F_108 ( & V_89 -> V_226 ) ;
F_112 ( V_71 , L_26 ,
V_121 , V_89 -> V_240 ,
V_89 -> V_236 , V_89 -> V_230 << V_81 ) ;
}
static void F_137 ( struct V_88 * V_89 , struct V_24 * V_25 )
{
F_107 ( & V_89 -> V_226 ) ;
F_130 ( V_89 , & V_25 -> V_242 ) ;
F_108 ( & V_89 -> V_226 ) ;
}
static int F_138 ( struct V_88 * V_89 ,
struct V_24 * V_25 ,
int V_221 , int V_243 )
{
int V_27 ;
F_139 ( V_71 , V_89 , L_27 , V_221 ) ;
V_27 = F_132 ( V_89 , V_221 ) ;
if ( V_27 < 0 )
return 0 ;
if ( V_89 -> V_230 <= V_89 -> V_244 &&
F_140 ( & V_229 ) + 1 <= V_245 ) {
F_126 ( V_89 , & V_25 -> V_242 ) ;
if ( V_243 ) {
V_89 -> V_234 ++ ;
F_128 ( & V_233 ) ;
V_25 -> V_212 |= V_232 ;
}
V_27 = 1 ;
} else {
F_133 ( V_89 , V_221 , V_221 ) ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_141 ( struct V_88 * V_89 , struct V_246 * V_247 )
{
int V_27 ;
F_107 ( & V_89 -> V_226 ) ;
V_27 = F_3 ( & V_247 -> V_248 ) ;
F_108 ( & V_89 -> V_226 ) ;
return V_27 ;
}
static int F_142 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_24 * V_25 , int V_221 )
{
struct V_19 * V_182 = V_25 -> V_249 ;
struct V_250 * V_251 = V_182 -> V_252 ;
struct V_246 V_247 ;
struct V_141 V_142 ;
int V_27 = - V_235 ;
V_142 = F_86 ( F_87 ( V_253 ? V_254 : V_255 ) ,
NULL , V_143 , NULL ) ;
F_139 ( V_71 , V_89 , L_27 , V_221 ) ;
F_107 ( & V_89 -> V_226 ) ;
if ( F_143 ( V_256 ) ||
! V_89 -> V_244 || V_89 -> V_257 . V_258 ||
V_251 -> V_259 . V_258 ) {
F_139 ( V_71 , V_89 , L_28 ) ;
V_27 = - V_235 ;
goto V_28;
}
if ( F_138 ( V_89 , V_25 , V_221 , 0 ) ) {
F_139 ( V_71 , V_89 , L_29 ) ;
V_27 = 0 ;
goto V_28;
}
F_30 ( & V_247 . V_260 ) ;
V_247 . V_261 = V_25 ;
V_247 . V_262 = V_221 ;
while ( V_89 -> V_230 > 0 || V_89 -> V_263 > 0 ) {
F_144 ( & V_247 . V_248 , & V_89 -> V_264 ) ;
V_247 . V_265 = 0 ;
F_108 ( & V_89 -> V_226 ) ;
F_66 ( V_63 , V_89 , NULL ) ;
F_112 ( V_71 , L_30 ,
V_89 -> V_123 -> V_124 -> V_146 , & V_247 , V_25 ) ;
V_27 = F_88 ( V_247 . V_260 , F_141 ( V_89 , & V_247 ) , & V_142 ) ;
F_107 ( & V_89 -> V_226 ) ;
if ( V_27 < 0 ) {
F_52 ( & V_247 . V_248 ) ;
break;
}
F_7 ( F_3 ( & V_247 . V_248 ) ) ;
V_27 = V_247 . V_265 ;
if ( V_27 != - V_235 )
break;
if ( F_138 ( V_89 , V_25 , V_221 , 0 ) ) {
V_27 = 0 ;
break;
}
}
switch ( V_27 ) {
case 0 :
F_139 ( V_71 , V_89 , L_31 ) ;
break;
case - V_144 :
F_139 ( V_71 , V_89 ,
L_32 ) ;
F_76 ( V_71 , V_182 ) ;
V_27 = - V_235 ;
break;
case - V_266 :
F_139 ( V_71 , V_89 , L_33 ) ;
V_27 = - V_267 ;
break;
case - V_235 :
F_139 ( V_71 , V_89 ,
L_34 ) ;
break;
default:
F_112 ( V_71 , L_35 ,
V_89 -> V_123 -> V_124 -> V_146 , & V_247 , V_27 ) ;
break;
}
V_28:
F_108 ( & V_89 -> V_226 ) ;
return V_27 ;
}
void F_135 ( struct V_88 * V_89 )
{
struct V_14 * V_268 , * V_56 ;
struct V_246 * V_247 ;
F_145 (l, tmp, &cli->cl_cache_waiters) {
V_247 = F_146 ( V_268 , struct V_246 , V_248 ) ;
F_52 ( & V_247 -> V_248 ) ;
V_247 -> V_265 = - V_235 ;
if ( ( V_89 -> V_230 > V_89 -> V_244 ) ||
( F_140 ( & V_229 ) + 1 >
V_245 ) ) {
F_112 ( V_71 , L_36 ,
V_89 -> V_230 , V_89 -> V_244 ,
V_245 ) ;
goto V_269;
}
if ( F_138 ( V_89 , V_247 -> V_261 , V_247 -> V_262 , 0 ) )
V_247 -> V_265 = 0 ;
V_269:
F_112 ( V_71 , L_37 ,
V_247 , V_247 -> V_261 , V_89 -> V_236 , V_247 -> V_265 ) ;
F_147 ( & V_247 -> V_260 ) ;
}
}
static int F_148 ( struct V_88 * V_89 , struct V_19 * V_182 )
{
int V_270 = ! ! F_3 ( & V_182 -> V_271 ) ;
return F_149 ( V_89 ) >= V_89 -> V_272 + V_270 ;
}
static int F_150 ( struct V_88 * V_89 , struct V_19 * V_182 ,
int V_185 )
{
int V_273 = 0 ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_274 )
V_273 = 1 ;
if ( V_185 & V_70 ) {
if ( F_15 ( & V_182 -> V_275 ) == 0 )
return 0 ;
if ( V_273 ) {
F_112 ( V_71 , L_38 ) ;
return 1 ;
}
if ( ! F_3 ( & V_182 -> V_271 ) ) {
F_112 ( V_71 , L_39 ) ;
return 1 ;
}
if ( ! F_3 ( & V_182 -> V_84 ) ) {
F_112 ( V_71 , L_40 ) ;
return 1 ;
}
if ( ! F_3 ( & V_89 -> V_264 ) ) {
F_112 ( V_71 , L_41 ) ;
return 1 ;
}
if ( F_15 ( & V_182 -> V_275 ) >=
V_89 -> V_110 )
return 1 ;
} else {
if ( F_15 ( & V_182 -> V_276 ) == 0 )
return 0 ;
if ( V_273 ) {
F_112 ( V_71 , L_38 ) ;
return 1 ;
}
if ( ! F_3 ( & V_182 -> V_277 ) )
return 1 ;
}
return 0 ;
}
static void F_51 ( struct V_19 * V_20 , int V_185 , int V_278 )
{
struct V_88 * V_89 = F_58 ( V_20 ) ;
if ( V_185 & V_70 ) {
F_151 ( V_278 , & V_20 -> V_275 ) ;
F_151 ( V_278 , & V_89 -> V_279 ) ;
F_7 ( F_15 ( & V_20 -> V_275 ) >= 0 ) ;
} else {
F_151 ( V_278 , & V_20 -> V_276 ) ;
F_151 ( V_278 , & V_89 -> V_280 ) ;
F_7 ( F_15 ( & V_20 -> V_276 ) >= 0 ) ;
}
F_152 ( V_20 , L_42 , V_185 , V_278 ) ;
}
static int F_153 ( struct V_19 * V_20 )
{
return ! F_3 ( & V_20 -> V_271 ) ;
}
static void F_154 ( struct V_14 * V_281 , struct V_14 * V_15 , int V_282 )
{
if ( F_3 ( V_281 ) && V_282 )
F_144 ( V_281 , V_15 ) ;
else if ( ! F_3 ( V_281 ) && ! V_282 )
F_52 ( V_281 ) ;
}
static int F_155 ( struct V_88 * V_89 , struct V_19 * V_182 )
{
if ( F_153 ( V_182 ) ) {
F_154 ( & V_182 -> V_183 , & V_89 -> V_283 , 0 ) ;
F_154 ( & V_182 -> V_184 , & V_89 -> V_284 , 1 ) ;
} else {
F_154 ( & V_182 -> V_184 , & V_89 -> V_284 , 0 ) ;
F_154 ( & V_182 -> V_183 , & V_89 -> V_283 ,
F_150 ( V_89 , V_182 , V_70 ) ||
F_150 ( V_89 , V_182 , V_196 ) ) ;
}
F_154 ( & V_182 -> V_285 , & V_89 -> V_286 ,
F_15 ( & V_182 -> V_275 ) > 0 ) ;
F_154 ( & V_182 -> V_287 , & V_89 -> V_288 ,
F_15 ( & V_182 -> V_276 ) > 0 ) ;
return F_113 ( V_182 ) ;
}
static int F_156 ( struct V_88 * V_89 , struct V_19 * V_182 )
{
int V_289 ;
F_107 ( & V_89 -> V_226 ) ;
V_289 = F_155 ( V_89 , V_182 ) ;
F_108 ( & V_89 -> V_226 ) ;
return V_289 ;
}
static void F_157 ( struct V_290 * V_291 , T_3 V_292 ,
int V_27 )
{
if ( V_27 ) {
if ( ! V_291 -> V_293 )
V_291 -> V_293 = V_27 ;
V_291 -> V_258 = 1 ;
V_291 -> V_294 = F_158 () ;
return;
}
if ( V_291 -> V_258 && ( V_292 >= V_291 -> V_294 ) )
V_291 -> V_258 = 0 ;
}
static void F_83 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_24 * V_25 , int V_119 , int V_27 )
{
struct V_19 * V_182 = V_25 -> V_249 ;
struct V_250 * V_251 = V_182 -> V_252 ;
T_3 V_292 = 0 ;
if ( V_25 -> V_295 ) {
V_292 = F_159 ( V_25 -> V_295 ) ;
F_160 ( V_25 -> V_295 ) ;
V_25 -> V_295 = NULL ;
}
F_107 ( & V_25 -> V_171 ) ;
V_25 -> V_169 = 0 ;
F_108 ( & V_25 -> V_171 ) ;
V_25 -> V_296 = 0 ;
if ( V_25 -> V_297 & V_70 && V_292 > 0 ) {
F_107 ( & V_89 -> V_226 ) ;
F_157 ( & V_89 -> V_257 , V_292 , V_27 ) ;
F_157 ( & V_251 -> V_259 , V_292 , V_27 ) ;
F_108 ( & V_89 -> V_226 ) ;
}
V_27 = F_120 ( V_63 , V_25 , V_25 -> V_297 , V_27 ) ;
if ( V_27 )
F_161 ( L_43 ,
V_25 , V_182 , V_27 ) ;
}
static int F_162 ( struct V_88 * V_89 ,
struct V_1 * V_2 , struct V_14 * V_298 ,
unsigned int * V_299 , unsigned int * V_98 )
{
struct V_1 * V_56 ;
struct V_24 * V_25 = F_163 ( & V_2 -> V_35 ,
struct V_24 ,
V_132 ) ;
F_75 ( ( V_2 -> V_29 == V_37 || V_2 -> V_29 == V_300 ) ,
V_2 ) ;
* V_98 = F_60 ( V_2 -> V_52 , * V_98 ) ;
if ( * V_299 + V_2 -> V_34 > * V_98 )
return 0 ;
F_18 (tmp, rpclist, oe_link) {
struct V_24 * V_301 ;
V_301 = F_163 ( & V_56 -> V_35 , struct V_24 ,
V_132 ) ;
F_75 ( V_56 -> V_168 == V_161 , V_56 ) ;
if ( F_96 ( V_25 ) -> V_302 != F_96 ( V_301 ) -> V_302 ) {
F_112 ( V_71 , L_44
L_45 ) ;
return 0 ;
}
if ( V_56 -> V_8 != V_2 -> V_8 ||
! V_56 -> V_38 != ! V_2 -> V_38 )
return 0 ;
break;
}
* V_299 += V_2 -> V_34 ;
F_65 ( & V_2 -> V_61 , V_298 ) ;
V_2 -> V_168 = V_161 ;
return 1 ;
}
static unsigned int F_164 ( struct V_19 * V_20 ,
struct V_14 * V_298 )
{
struct V_88 * V_89 = F_58 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_303 ;
unsigned int V_26 = 0 ;
unsigned int V_98 = V_89 -> V_110 ;
F_7 ( F_14 ( V_20 ) ) ;
F_82 (ext, temp, &obj->oo_hp_exts, oe_link) {
F_7 ( V_2 -> V_29 == V_37 ) ;
if ( ! F_162 ( V_89 , V_2 , V_298 , & V_26 ,
& V_98 ) )
return V_26 ;
F_75 ( V_2 -> V_34 <= V_98 , V_2 ) ;
}
if ( V_26 == V_98 )
return V_26 ;
while ( ! F_3 ( & V_20 -> V_84 ) ) {
V_2 = F_146 ( V_20 -> V_84 . V_176 ,
struct V_1 , V_61 ) ;
if ( ! F_162 ( V_89 , V_2 , V_298 , & V_26 ,
& V_98 ) )
return V_26 ;
if ( ! V_2 -> V_6 )
continue;
while ( ( V_2 = F_6 ( V_2 ) ) != NULL ) {
if ( ( V_2 -> V_29 != V_37 ) ||
( ! F_3 ( & V_2 -> V_61 ) &&
V_2 -> V_168 ) )
continue;
if ( ! F_162 ( V_89 , V_2 , V_298 ,
& V_26 , & V_98 ) )
return V_26 ;
}
}
if ( V_26 == V_98 )
return V_26 ;
V_2 = F_11 ( V_20 ) ;
while ( V_2 ) {
if ( ( V_2 -> V_29 != V_37 ) ||
( ! F_3 ( & V_2 -> V_61 ) && V_2 -> V_168 ) ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( ! F_162 ( V_89 , V_2 , V_298 , & V_26 ,
& V_98 ) )
return V_26 ;
V_2 = F_6 ( V_2 ) ;
}
return V_26 ;
}
static int
F_165 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_182 )
__must_hold( V_182 )
{
F_166 ( V_298 ) ;
struct V_1 * V_2 ;
struct V_1 * V_56 ;
struct V_1 * V_304 = NULL ;
T_5 V_26 = 0 ;
int V_202 = 0 ;
int V_27 = 0 ;
F_7 ( F_14 ( V_182 ) ) ;
V_26 = F_164 ( V_182 , & V_298 ) ;
F_7 ( F_122 ( V_26 == 0 , F_3 ( & V_298 ) ) ) ;
if ( F_3 ( & V_298 ) )
return 0 ;
F_51 ( V_182 , V_70 , - V_26 ) ;
F_18 (ext, &rpclist, oe_link) {
F_7 ( V_2 -> V_29 == V_37 ||
V_2 -> V_29 == V_300 ) ;
if ( V_2 -> V_29 == V_37 )
F_23 ( V_2 , V_167 ) ;
else
F_23 ( V_2 , V_130 ) ;
}
F_56 ( V_182 ) ;
F_82 (ext, tmp, &rpclist, oe_link) {
if ( V_2 -> V_29 == V_167 ) {
V_27 = F_105 ( V_63 , V_2 ) ;
if ( F_167 ( V_27 < 0 ) ) {
F_52 ( & V_2 -> V_61 ) ;
F_79 ( V_63 , V_2 , 0 , V_27 ) ;
continue;
}
}
if ( ! V_304 ) {
V_304 = V_2 ;
V_202 = V_2 -> V_8 ;
} else {
F_7 ( V_202 == V_2 -> V_8 ) ;
}
}
if ( ! F_3 ( & V_298 ) ) {
F_7 ( V_26 > 0 ) ;
V_27 = F_168 ( V_63 , V_89 , & V_298 , V_70 ) ;
F_7 ( F_3 ( & V_298 ) ) ;
}
F_55 ( V_182 ) ;
return V_27 ;
}
static int
F_169 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_182 )
__must_hold( V_182 )
{
struct V_1 * V_2 ;
struct V_1 * V_176 ;
F_166 ( V_298 ) ;
unsigned int V_26 = 0 ;
unsigned int V_98 = V_89 -> V_110 ;
int V_27 = 0 ;
F_7 ( F_14 ( V_182 ) ) ;
F_82 (ext, next, &osc->oo_reading_exts, oe_link) {
F_75 ( V_2 -> V_29 == V_300 , V_2 ) ;
if ( ! F_162 ( V_89 , V_2 , & V_298 , & V_26 ,
& V_98 ) )
break;
F_23 ( V_2 , V_130 ) ;
F_75 ( V_2 -> V_34 <= V_98 , V_2 ) ;
}
F_7 ( V_26 <= V_98 ) ;
F_51 ( V_182 , V_196 , - V_26 ) ;
if ( ! F_3 ( & V_298 ) ) {
F_56 ( V_182 ) ;
F_7 ( V_26 > 0 ) ;
V_27 = F_168 ( V_63 , V_89 , & V_298 , V_196 ) ;
F_7 ( F_3 ( & V_298 ) ) ;
F_55 ( V_182 ) ;
}
return V_27 ;
}
static struct V_19 * F_170 ( struct V_88 * V_89 )
{
if ( ! F_3 ( & V_89 -> V_284 ) )
return F_171 ( & V_89 -> V_284 , V_305 ) ;
if ( ! F_3 ( & V_89 -> V_283 ) )
return F_171 ( & V_89 -> V_283 , V_306 ) ;
if ( ! F_3 ( & V_89 -> V_264 ) &&
! F_3 ( & V_89 -> V_286 ) )
return F_171 ( & V_89 -> V_286 , V_307 ) ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_274 ) {
if ( ! F_3 ( & V_89 -> V_286 ) )
return F_171 ( & V_89 -> V_286 , V_307 ) ;
if ( ! F_3 ( & V_89 -> V_288 ) )
return F_171 ( & V_89 -> V_288 , V_308 ) ;
}
return NULL ;
}
static void F_172 ( const struct V_62 * V_63 , struct V_88 * V_89 )
__must_hold( &cli->cl_loi_list_lock
static int F_173 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_182 , int V_309 )
{
int V_27 = 0 ;
if ( V_182 && F_156 ( V_89 , V_182 ) == 0 )
return 0 ;
if ( ! V_309 ) {
F_34 ( & V_89 -> V_310 ) ;
F_107 ( & V_89 -> V_226 ) ;
F_172 ( V_63 , V_89 ) ;
F_108 ( & V_89 -> V_226 ) ;
F_40 ( & V_89 -> V_310 ) ;
} else {
F_112 ( V_71 , L_46 , V_89 ) ;
F_7 ( V_89 -> V_311 ) ;
V_27 = F_174 ( V_89 -> V_311 ) ;
}
return V_27 ;
}
static int F_66 ( const struct V_62 * V_63 ,
struct V_88 * V_89 , struct V_19 * V_182 )
{
return F_173 ( V_63 , V_89 , V_182 , 1 ) ;
}
void F_175 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_182 )
{
( void ) F_173 ( V_63 , V_89 , V_182 , 0 ) ;
}
int F_176 ( struct V_19 * V_182 , struct V_186 * V_312 ,
struct V_159 * V_159 , T_4 V_136 )
{
struct V_313 * exp = F_89 ( V_182 ) ;
struct V_24 * V_25 = & V_312 -> V_314 ;
if ( ! V_159 )
return F_177 ( sizeof( * V_25 ) ) ;
V_25 -> V_315 = V_316 ;
V_25 -> V_317 = & exp -> V_145 -> V_318 . V_89 ;
V_25 -> V_249 = V_182 ;
V_25 -> V_319 = V_159 ;
V_25 -> V_133 = V_136 ;
F_7 ( ! ( V_136 & ~ V_137 ) ) ;
if ( F_178 ( V_320 ) )
V_25 -> V_212 = V_203 ;
F_29 ( & V_25 -> V_132 ) ;
F_29 ( & V_25 -> V_131 ) ;
F_179 ( & V_25 -> V_171 ) ;
F_112 ( V_321 , L_47 ,
V_25 , V_159 , V_25 -> V_133 ) ;
return 0 ;
}
int F_180 ( const struct V_62 * V_63 , struct V_151 * V_152 ,
struct V_186 * V_312 )
{
struct V_322 * V_323 = F_70 ( V_63 ) ;
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 = & V_312 -> V_314 ;
struct V_88 * V_89 = V_25 -> V_317 ;
struct V_19 * V_182 = V_25 -> V_249 ;
T_2 V_54 ;
unsigned int V_87 = 0 , V_56 ;
int V_324 = V_325 ;
int V_185 = V_70 ;
int V_326 = 0 ;
int V_27 = 0 ;
if ( V_25 -> V_315 != V_316 )
return - V_77 ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_274 )
return - V_327 ;
if ( ! F_3 ( & V_25 -> V_132 ) ||
! F_3 ( & V_25 -> V_131 ) )
return - V_78 ;
V_324 |= V_312 -> V_328 ? V_213 : 0 ;
if ( F_178 ( V_320 ) ) {
V_324 |= V_203 ;
V_185 |= V_203 ;
}
if ( ! ( V_185 & V_203 ) ) {
struct V_191 * V_20 ;
struct V_192 * V_193 ;
unsigned int V_329 [ V_330 ] ;
V_20 = F_94 ( & V_182 -> V_331 ) ;
V_193 = & F_93 ( V_63 ) -> V_194 ;
F_117 ( V_20 ) ;
V_27 = F_118 ( V_63 , V_20 , V_193 ) ;
F_119 ( V_20 ) ;
V_329 [ V_332 ] = V_193 -> V_333 ;
V_329 [ V_334 ] = V_193 -> V_335 ;
if ( V_27 == 0 && F_181 ( V_89 , V_329 ) == V_336 )
V_27 = - V_235 ;
if ( V_27 )
return V_27 ;
}
V_25 -> V_297 = V_185 ;
V_25 -> V_175 = V_312 -> V_337 ;
V_25 -> V_134 = V_312 -> V_338 - V_312 -> V_337 ;
V_25 -> V_169 = 0 ;
V_25 -> V_212 = V_324 ;
F_152 ( V_182 , L_48 ,
V_25 , V_25 -> V_319 , V_25 -> V_297 & V_339 ) ;
V_54 = F_19 ( F_20 ( V_25 ) ) ;
V_2 = V_323 -> V_340 ;
if ( V_2 && V_2 -> V_41 <= V_54 && V_2 -> V_39 >= V_54 ) {
V_87 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
if ( V_2 -> V_40 >= V_54 )
V_87 = 0 ;
F_107 ( & V_89 -> V_226 ) ;
V_27 = F_138 ( V_89 , V_25 , V_87 , 0 ) ;
F_108 ( & V_89 -> V_226 ) ;
if ( V_27 == 0 ) {
V_87 = 0 ;
V_326 = 1 ;
} else if ( V_2 -> V_40 < V_54 ) {
V_56 = V_87 ;
V_27 = F_110 ( V_2 , V_54 , & V_56 ) ;
if ( V_27 < 0 ) {
V_326 = 1 ;
} else {
F_21 ( V_71 , V_2 ,
L_49 , V_54 ) ;
F_134 ( V_89 , V_87 , V_56 ) ;
V_87 = 0 ;
}
}
V_27 = 0 ;
} else if ( V_2 ) {
V_326 = 1 ;
}
if ( V_326 ) {
F_62 ( V_63 , V_2 ) ;
V_323 -> V_340 = NULL ;
V_2 = NULL ;
}
if ( ! V_2 ) {
V_56 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
F_7 ( ! V_323 -> V_340 ) ;
F_7 ( F_80 ( V_87 > 0 , V_87 >= V_56 ) ) ;
V_27 = 0 ;
if ( V_87 == 0 ) {
V_27 = F_142 ( V_63 , V_89 , V_25 , V_56 ) ;
if ( V_27 == 0 )
V_87 = V_56 ;
}
V_56 = V_87 ;
if ( V_27 == 0 ) {
V_2 = F_68 ( V_63 , V_182 , V_54 , & V_56 ) ;
if ( F_77 ( V_2 ) ) {
F_7 ( V_56 == V_87 ) ;
F_137 ( V_89 , V_25 ) ;
V_27 = F_182 ( V_2 ) ;
V_2 = NULL ;
} else {
V_323 -> V_340 = V_2 ;
}
}
if ( V_87 > 0 )
F_134 ( V_89 , V_87 , V_56 ) ;
}
F_7 ( F_80 ( V_27 == 0 , V_2 ) ) ;
if ( V_2 ) {
F_44 ( V_2 -> V_40 >= V_54 && V_2 -> V_41 <= V_54 ,
V_2 , L_50 , V_54 ) ;
F_7 ( ( V_25 -> V_212 & V_228 ) != 0 ) ;
F_55 ( V_182 ) ;
if ( V_2 -> V_34 == 0 )
V_2 -> V_8 = V_312 -> V_328 ;
else
F_7 ( V_2 -> V_8 == V_312 -> V_328 ) ;
++ V_2 -> V_34 ;
F_144 ( & V_25 -> V_132 , & V_2 -> V_35 ) ;
F_56 ( V_182 ) ;
}
return V_27 ;
}
int F_183 ( const struct V_62 * V_63 ,
struct V_19 * V_20 , struct V_186 * V_312 )
{
struct V_24 * V_25 = & V_312 -> V_314 ;
struct V_1 * V_2 = NULL ;
int V_27 = 0 ;
F_7 ( V_25 -> V_315 == V_316 ) ;
F_112 ( V_321 , L_51 ,
V_25 , V_312 , F_19 ( F_20 ( V_25 ) ) ) ;
F_55 ( V_20 ) ;
if ( ! F_3 ( & V_25 -> V_131 ) ) {
F_112 ( V_71 , L_52 , V_25 ) ;
V_27 = - V_78 ;
} else if ( ! F_3 ( & V_25 -> V_132 ) ) {
V_2 = F_42 ( V_20 , F_19 ( F_20 ( V_25 ) ) ) ;
if ( V_2 && V_2 -> V_29 != V_83 ) {
F_21 ( V_55 , V_2 , L_53 ,
F_19 ( F_20 ( V_25 ) ) ) ;
V_27 = - V_78 ;
}
}
F_56 ( V_20 ) ;
if ( V_2 )
F_35 ( V_63 , V_2 ) ;
return V_27 ;
}
int F_184 ( const struct V_62 * V_63 , struct V_151 * V_152 ,
struct V_186 * V_312 )
{
struct V_1 * V_2 = NULL ;
struct V_19 * V_20 = F_121 ( V_312 -> V_197 . V_198 ) ;
struct V_158 * V_341 = V_312 -> V_197 . V_342 ;
T_2 V_54 = F_19 ( V_312 ) ;
struct V_24 * V_25 = & V_312 -> V_314 ;
bool V_343 = false ;
int V_27 = 0 ;
F_55 ( V_20 ) ;
V_2 = F_42 ( V_20 , V_54 ) ;
if ( ! V_2 ) {
F_76 ( V_55 , V_20 ) ;
F_71 ( 0 , L_54 , V_54 ) ;
}
switch ( V_2 -> V_29 ) {
case V_130 :
case V_300 :
F_185 ( V_55 , V_63 , V_341 , L_55 ) ;
F_7 ( 0 ) ;
break;
case V_167 :
case V_83 :
case V_36 :
V_27 = - V_179 ;
goto V_28;
default:
break;
}
V_27 = F_186 ( V_63 , V_152 , V_341 , V_189 ) ;
if ( V_27 )
goto V_28;
F_107 ( & V_25 -> V_171 ) ;
V_25 -> V_169 |= V_170 | V_344 ;
F_108 ( & V_25 -> V_171 ) ;
if ( F_187 () )
V_2 -> V_11 = 1 ;
V_2 -> V_10 = 1 ;
if ( V_2 -> V_29 == V_37 ) {
F_21 ( V_71 , V_2 ,
L_56 , V_25 ) ;
if ( F_3 ( & V_2 -> V_61 ) )
F_144 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
V_343 = true ;
}
V_27 = 0 ;
V_28:
F_56 ( V_20 ) ;
F_35 ( V_63 , V_2 ) ;
if ( V_343 )
F_66 ( V_63 , F_58 ( V_20 ) , V_20 ) ;
return V_27 ;
}
int F_188 ( const struct V_62 * V_63 , struct V_186 * V_312 )
{
struct V_24 * V_25 = & V_312 -> V_314 ;
struct V_19 * V_20 = V_25 -> V_249 ;
struct V_88 * V_89 = F_58 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_95 = NULL ;
struct V_14 * V_345 ;
T_2 V_54 = F_19 ( V_312 ) ;
int V_27 = - V_78 ;
int V_185 ;
F_7 ( ! V_25 -> V_296 ) ;
V_25 -> V_296 = 1 ;
F_55 ( V_20 ) ;
if ( V_25 -> V_297 & V_70 ) {
V_345 = & V_20 -> V_84 ;
V_185 = V_70 ;
} else {
V_345 = & V_20 -> V_277 ;
V_185 = V_196 ;
}
F_18 (ext, plist, oe_link) {
if ( V_2 -> V_41 <= V_54 && V_2 -> V_40 >= V_54 ) {
F_7 ( V_2 -> V_29 == V_300 ) ;
V_95 = F_33 ( V_2 ) ;
break;
}
}
if ( V_95 ) {
F_52 ( & V_95 -> V_61 ) ;
F_51 ( V_20 , V_185 , - V_95 -> V_34 ) ;
F_56 ( V_20 ) ;
F_79 ( V_63 , V_95 , 0 , - V_266 ) ;
F_35 ( V_63 , V_95 ) ;
V_27 = 0 ;
} else {
F_56 ( V_20 ) ;
if ( V_25 -> V_295 ) {
F_189 ( V_25 -> V_295 ) ;
F_190 ( V_25 -> V_295 ) ;
F_160 ( V_25 -> V_295 ) ;
V_25 -> V_295 = NULL ;
}
}
F_156 ( V_89 , V_20 ) ;
return V_27 ;
}
int F_191 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
struct V_14 * V_15 , int V_185 , int V_324 )
{
struct V_88 * V_89 = F_58 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_24 * V_25 , * V_56 ;
int V_26 = 0 ;
int V_346 = V_89 -> V_110 ;
T_2 V_47 = V_347 ;
T_2 V_48 = 0 ;
F_18 (oap, list, oap_pending_item) {
T_2 V_54 = F_19 ( F_20 ( V_25 ) ) ;
if ( V_54 > V_48 )
V_48 = V_54 ;
if ( V_54 < V_47 )
V_47 = V_54 ;
++ V_26 ;
V_346 <<= ( V_26 > V_346 ) ;
}
V_2 = F_25 ( V_20 ) ;
if ( ! V_2 ) {
F_82 (oap, tmp, list, oap_pending_item) {
F_52 ( & V_25 -> V_132 ) ;
F_83 ( V_63 , V_89 , V_25 , 0 , - V_101 ) ;
}
return - V_101 ;
}
V_2 -> V_5 = ! ! ( V_185 & V_196 ) ;
V_2 -> V_7 = 1 ;
V_2 -> V_10 = 1 ;
V_2 -> V_41 = V_47 ;
V_2 -> V_40 = V_48 ;
V_2 -> V_39 = V_48 ;
V_2 -> V_23 = V_20 ;
V_2 -> V_8 = ! ! ( V_324 & V_213 ) ;
V_2 -> V_34 = V_26 ;
V_2 -> V_52 = V_346 ;
F_61 ( V_15 , & V_2 -> V_35 ) ;
F_55 ( V_20 ) ;
F_23 ( V_2 , V_300 ) ;
if ( V_185 & V_70 ) {
F_144 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
F_51 ( V_20 , V_70 , V_26 ) ;
} else {
F_144 ( & V_2 -> V_61 , & V_20 -> V_277 ) ;
F_51 ( V_20 , V_196 , V_26 ) ;
}
F_56 ( V_20 ) ;
F_66 ( V_63 , V_89 , V_20 ) ;
return 0 ;
}
int F_192 ( const struct V_62 * V_63 , struct V_322 * V_323 ,
struct V_19 * V_20 , T_3 V_348 )
{
struct V_88 * V_89 = F_58 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_303 ;
struct V_1 * V_349 = NULL ;
T_2 V_54 ;
F_166 ( V_15 ) ;
int V_188 = 0 ;
bool V_148 ;
V_54 = F_193 ( F_17 ( V_20 ) , V_348 ) ;
V_148 = V_348 > F_16 ( F_17 ( V_20 ) , V_54 ) ;
V_350:
F_55 ( V_20 ) ;
V_2 = F_41 ( V_20 , V_54 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
else if ( V_2 -> V_40 < V_54 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
F_75 ( V_2 -> V_29 != V_83 , V_2 ) ;
if ( V_2 -> V_29 > V_37 || V_2 -> V_10 ) {
F_7 ( ! V_2 -> V_9 ) ;
F_21 ( V_71 , V_2 ,
L_57 ) ;
V_349 = F_33 ( V_2 ) ;
break;
}
F_21 ( V_71 , V_2 , L_58 , V_348 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_29 == V_36 ) {
F_7 ( ! V_2 -> V_12 ) ;
V_2 -> V_12 = 1 ;
} else {
F_75 ( V_2 -> V_29 == V_37 , V_2 ) ;
F_23 ( V_2 , V_83 ) ;
F_51 ( V_20 , V_70 ,
- V_2 -> V_34 ) ;
}
F_75 ( F_3 ( & V_2 -> V_61 ) , V_2 ) ;
F_144 ( & V_2 -> V_61 , & V_15 ) ;
V_2 = F_6 ( V_2 ) ;
}
F_56 ( V_20 ) ;
F_156 ( V_89 , V_20 ) ;
F_82 (ext, temp, &list, oe_link) {
int V_27 ;
F_52 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_29 != V_83 )
F_78 ( V_63 , V_2 , V_83 ) ;
V_27 = F_91 ( V_2 , V_54 , V_148 ) ;
if ( V_27 < 0 ) {
if ( V_188 == 0 )
V_188 = V_27 ;
F_21 ( V_55 , V_2 ,
L_59 , V_27 ) ;
} else if ( V_2 -> V_34 == 0 ) {
F_54 ( V_2 ) ;
} else {
F_44 ( V_2 -> V_41 <= V_54 , V_2 ,
L_60 , V_54 , V_148 ) ;
V_54 = V_2 -> V_40 + 1 ;
V_148 = false ;
F_7 ( ! V_323 -> V_351 ) ;
V_323 -> V_351 = F_33 ( V_2 ) ;
F_21 ( V_71 , V_2 ,
L_61 , V_348 ) ;
}
F_35 ( V_63 , V_2 ) ;
}
if ( V_349 ) {
int V_27 ;
V_27 = F_78 ( V_63 , V_349 , V_33 ) ;
if ( V_27 < 0 )
F_21 ( V_71 , V_349 , L_62 , V_27 ) ;
F_35 ( V_63 , V_349 ) ;
V_349 = NULL ;
goto V_350;
}
return V_188 ;
}
void F_194 ( const struct V_62 * V_63 , struct V_322 * V_323 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_323 -> V_351 ;
V_323 -> V_351 = NULL ;
if ( V_2 ) {
bool V_343 = false ;
F_75 ( V_2 -> V_34 > 0 , V_2 ) ;
F_75 ( V_2 -> V_29 == V_83 , V_2 ) ;
F_75 ( ! V_2 -> V_10 , V_2 ) ;
F_21 ( V_71 , V_2 , L_63 ) ;
F_55 ( V_20 ) ;
F_23 ( V_2 , V_37 ) ;
if ( V_2 -> V_13 && ! V_2 -> V_10 ) {
V_2 -> V_10 = 1 ;
F_65 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
V_343 = true ;
}
F_51 ( V_20 , V_70 , V_2 -> V_34 ) ;
F_56 ( V_20 ) ;
F_35 ( V_63 , V_2 ) ;
if ( V_343 )
F_66 ( V_63 , F_58 ( V_20 ) , V_20 ) ;
}
}
int F_195 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_2 V_47 , T_2 V_48 )
{
struct V_1 * V_2 ;
T_2 V_54 = V_47 ;
int V_188 = 0 ;
V_350:
F_55 ( V_20 ) ;
V_2 = F_41 ( V_20 , V_54 ) ;
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
F_75 ( F_80 ( V_2 -> V_29 == V_37 ,
V_2 -> V_9 || V_2 -> V_10 ) , V_2 ) ;
F_75 ( F_80 ( V_2 -> V_29 == V_36 ,
! V_2 -> V_9 && V_2 -> V_10 ) , V_2 ) ;
V_54 = V_2 -> V_40 + 1 ;
F_33 ( V_2 ) ;
F_56 ( V_20 ) ;
V_27 = F_78 ( V_63 , V_2 , V_33 ) ;
if ( V_188 == 0 )
V_188 = V_27 ;
F_35 ( V_63 , V_2 ) ;
goto V_350;
}
F_56 ( V_20 ) ;
F_152 ( V_20 , L_64 ) ;
return V_188 ;
}
int F_196 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_2 V_47 , T_2 V_48 , int V_352 , int V_353 )
{
struct V_1 * V_2 ;
F_166 ( V_354 ) ;
bool V_343 = false ;
int V_188 = 0 ;
F_55 ( V_20 ) ;
V_2 = F_41 ( V_20 , V_47 ) ;
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
V_188 += V_2 -> V_34 ;
if ( ! V_353 ) {
struct V_14 * V_15 = NULL ;
if ( V_352 ) {
F_75 ( ! V_2 -> V_9 , V_2 ) ;
V_2 -> V_9 = 1 ;
V_15 = & V_20 -> V_271 ;
} else if ( ! V_2 -> V_10 ) {
V_2 -> V_10 = 1 ;
V_15 = & V_20 -> V_84 ;
}
if ( V_15 )
F_65 ( & V_2 -> V_61 , V_15 ) ;
V_343 = true ;
} else {
F_75 ( V_2 -> V_41 >= V_47 &&
V_2 -> V_39 <= V_48 , V_2 ) ;
F_23 ( V_2 , V_167 ) ;
V_2 -> V_168 = V_161 ;
F_65 ( & V_2 -> V_61 , & V_354 ) ;
F_51 ( V_20 , V_70 ,
- V_2 -> V_34 ) ;
}
break;
case V_36 :
F_7 ( V_352 == 0 && V_353 == 0 ) ;
V_2 -> V_10 = 1 ;
break;
case V_83 :
default:
break;
}
V_2 = F_6 ( V_2 ) ;
}
F_56 ( V_20 ) ;
F_7 ( F_80 ( ! V_353 , F_3 ( & V_354 ) ) ) ;
if ( ! F_3 ( & V_354 ) ) {
struct V_1 * V_56 ;
int V_27 ;
F_156 ( F_58 ( V_20 ) , V_20 ) ;
F_82 (ext, tmp, &discard_list, oe_link) {
F_52 ( & V_2 -> V_61 ) ;
F_75 ( V_2 -> V_29 == V_167 , V_2 ) ;
V_27 = F_105 ( V_63 , V_2 ) ;
if ( F_167 ( V_27 < 0 ) ) {
F_21 ( V_55 , V_2 ,
L_65 , V_27 ) ;
if ( V_188 >= 0 )
V_188 = V_27 ;
}
F_79 ( V_63 , V_2 , 0 , 0 ) ;
}
}
if ( V_343 )
F_175 ( V_63 , F_58 ( V_20 ) , V_20 ) ;
if ( V_352 || V_353 ) {
int V_27 ;
V_27 = F_195 ( V_63 , V_20 , V_47 , V_48 ) ;
if ( V_188 >= 0 && V_27 < 0 )
V_188 = V_27 ;
}
F_152 ( V_20 , L_66 , V_47 , V_48 , V_188 ) ;
return V_188 ;
}
int F_197 ( const struct V_62 * V_63 , struct V_151 * V_152 ,
struct V_19 * V_182 , T_2 V_47 , T_2 V_48 ,
T_6 V_355 , void * V_356 )
{
struct V_186 * V_312 ;
void * * V_357 ;
T_2 V_358 ;
unsigned int V_359 ;
unsigned int V_360 ;
unsigned int V_361 ;
int V_362 = V_363 ;
bool V_364 = true ;
V_358 = V_47 ;
V_357 = F_93 ( V_63 ) -> V_365 ;
F_107 ( & V_182 -> V_366 ) ;
while ( ( V_359 = F_198 ( & V_182 -> V_367 , V_357 ,
V_358 , V_368 ) ) > 0 ) {
struct V_158 * V_159 ;
bool V_369 = false ;
for ( V_360 = 0 , V_361 = 0 ; V_360 < V_359 ; ++ V_360 ) {
V_312 = V_357 [ V_360 ] ;
V_357 [ V_360 ] = NULL ;
V_358 = F_19 ( V_312 ) ;
if ( V_358 > V_48 ) {
V_369 = true ;
break;
}
V_159 = V_312 -> V_197 . V_342 ;
F_7 ( V_159 -> V_302 == V_370 ) ;
if ( V_159 -> V_162 == V_163 )
continue;
F_97 ( V_159 ) ;
F_199 ( & V_159 -> V_160 ,
L_67 , V_161 ) ;
V_357 [ V_361 ++ ] = V_312 ;
}
++ V_358 ;
F_108 ( & V_182 -> V_366 ) ;
V_364 = false ;
for ( V_360 = 0 ; V_360 < V_361 ; ++ V_360 ) {
V_312 = V_357 [ V_360 ] ;
if ( V_362 == V_363 )
V_362 = (* V_355)( V_63 , V_152 , V_312 , V_356 ) ;
V_159 = V_312 -> V_197 . V_342 ;
F_101 ( & V_159 -> V_160 , L_67 , V_161 ) ;
F_102 ( V_63 , V_159 ) ;
}
if ( V_359 < V_368 || V_369 )
break;
if ( V_362 == V_363 && F_200 () )
V_362 = V_371 ;
if ( V_362 != V_363 )
break;
F_107 ( & V_182 -> V_366 ) ;
V_364 = true ;
}
if ( V_364 )
F_108 ( & V_182 -> V_366 ) ;
return V_362 ;
}
static int F_201 ( const struct V_62 * V_63 , struct V_151 * V_152 ,
struct V_186 * V_312 , void * V_356 )
{
struct V_372 * V_373 = F_93 ( V_63 ) ;
struct V_19 * V_182 = V_356 ;
T_2 V_54 ;
V_54 = F_19 ( V_312 ) ;
if ( V_54 >= V_373 -> V_374 ) {
struct V_375 * V_56 ;
struct V_158 * V_159 = V_312 -> V_197 . V_342 ;
V_56 = F_202 ( V_63 , V_182 , V_54 , 0 , 0 ) ;
if ( V_56 ) {
T_3 V_48 = V_56 -> V_45 . V_46 . V_48 ;
V_373 -> V_374 = F_193 ( F_17 ( V_182 ) , V_48 + 1 ) ;
if ( V_48 == V_376 )
V_373 -> V_374 = V_347 ;
F_38 ( V_56 ) ;
} else if ( F_98 ( V_63 , V_152 , V_159 ) == 0 ) {
F_99 ( V_63 , V_152 , V_159 ) ;
F_100 ( V_63 , V_152 , V_159 ) ;
} else {
F_7 ( V_159 -> V_162 == V_163 ) ;
}
}
V_373 -> V_377 = V_54 + 1 ;
return V_363 ;
}
static int F_203 ( const struct V_62 * V_63 , struct V_151 * V_152 ,
struct V_186 * V_312 , void * V_356 )
{
struct V_372 * V_373 = F_93 ( V_63 ) ;
struct V_158 * V_159 = V_312 -> V_197 . V_342 ;
V_373 -> V_377 = F_19 ( V_312 ) + 1 ;
if ( F_98 ( V_63 , V_152 , V_159 ) == 0 ) {
F_204 ( F_80 ( V_159 -> V_302 == V_370 ,
! F_205 ( F_206 ( V_159 ) ) ) ) ;
F_99 ( V_63 , V_152 , V_159 ) ;
F_100 ( V_63 , V_152 , V_159 ) ;
} else {
F_7 ( V_159 -> V_162 == V_163 ) ;
}
return V_363 ;
}
int F_207 ( const struct V_62 * V_63 , struct V_19 * V_182 ,
T_2 V_47 , T_2 V_48 , enum V_378 V_379 )
{
struct V_372 * V_373 = F_93 ( V_63 ) ;
struct V_151 * V_152 = & V_373 -> V_155 ;
T_6 V_355 ;
int V_362 ;
int V_188 ;
V_152 -> V_156 = F_94 ( F_17 ( V_182 ) ) ;
V_152 -> V_380 = 1 ;
V_188 = F_95 ( V_63 , V_152 , V_157 , V_152 -> V_156 ) ;
if ( V_188 != 0 )
goto V_28;
V_355 = V_379 == V_381 ? F_201 : F_203 ;
V_373 -> V_374 = V_47 ;
V_373 -> V_377 = V_47 ;
do {
V_362 = F_197 ( V_63 , V_152 , V_182 ,
V_373 -> V_377 , V_48 , V_355 , V_182 ) ;
if ( V_373 -> V_377 > V_48 )
break;
if ( V_362 == V_371 )
F_208 () ;
} while ( V_362 != V_363 );
V_28:
F_103 ( V_63 , V_152 ) ;
return V_188 ;
}
