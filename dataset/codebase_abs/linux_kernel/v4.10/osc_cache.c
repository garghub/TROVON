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
F_28 ( F_17 ( V_20 ) ) ;
F_29 ( & V_2 -> V_31 , 1 ) ;
F_29 ( & V_2 -> V_32 , 0 ) ;
F_30 ( & V_2 -> V_61 ) ;
V_2 -> V_29 = V_33 ;
F_30 ( & V_2 -> V_35 ) ;
F_31 ( & V_2 -> V_58 ) ;
V_2 -> V_42 = NULL ;
return V_2 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_59 , V_2 ) ;
}
static struct V_1 * F_34 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) >= 0 ) ;
F_35 ( & V_2 -> V_31 ) ;
return V_2 ;
}
static void F_36 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) > 0 ) ;
if ( F_37 ( & V_2 -> V_31 ) ) {
F_7 ( F_3 ( & V_2 -> V_61 ) ) ;
F_7 ( F_15 ( & V_2 -> V_32 ) == 0 ) ;
F_7 ( V_2 -> V_29 == V_33 ) ;
F_7 ( ! V_2 -> V_6 ) ;
if ( V_2 -> V_42 ) {
F_38 ( & V_2 -> V_42 -> V_64 ,
L_2 , V_2 ) ;
F_39 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
}
F_40 ( V_63 , F_17 ( V_2 -> V_23 ) ) ;
F_32 ( V_2 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_31 ) > 1 ) ;
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_42 ( & V_2 -> V_31 ) ;
}
static struct V_1 * F_43 ( struct V_19 * V_20 ,
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
static struct V_1 * F_44 ( struct V_19 * V_20 ,
T_2 V_54 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_20 , V_54 ) ;
if ( V_2 && V_2 -> V_41 <= V_54 && V_54 <= V_2 -> V_40 )
return F_34 ( V_2 ) ;
return NULL ;
}
static void F_45 ( struct V_19 * V_20 , struct V_1 * V_2 )
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
F_46 ( 0 , V_56 , V_69 L_3 , F_47 ( V_2 ) ) ;
}
F_48 ( & V_2 -> V_18 , V_68 , V_17 ) ;
F_49 ( & V_2 -> V_18 , & V_20 -> V_21 ) ;
F_34 ( V_2 ) ;
V_2 -> V_6 = 1 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_14 ( V_20 ) ) ;
if ( V_2 -> V_6 ) {
F_51 ( & V_2 -> V_18 , & V_20 -> V_21 ) ;
V_2 -> V_6 = 0 ;
F_41 ( V_2 ) ;
}
}
static struct V_1 * F_52 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_14 ( V_20 ) ) ;
F_7 ( V_2 -> V_29 == V_36 || V_2 -> V_29 == V_37 ) ;
if ( V_2 -> V_29 == V_37 ) {
F_23 ( V_2 , V_36 ) ;
F_53 ( V_20 , V_70 , - V_2 -> V_34 ) ;
}
F_35 ( & V_2 -> V_32 ) ;
F_54 ( & V_2 -> V_61 ) ;
return F_34 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_7 ( F_14 ( V_2 -> V_23 ) ) ;
F_7 ( F_3 ( & V_2 -> V_35 ) ) ;
F_50 ( V_2 ) ;
F_54 ( & V_2 -> V_61 ) ;
F_23 ( V_2 , V_33 ) ;
F_21 ( V_71 , V_2 , L_4 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_57 ( V_20 ) ;
F_55 ( V_2 ) ;
F_58 ( V_20 ) ;
}
static int F_59 ( const struct V_62 * V_63 , struct V_1 * V_72 ,
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
V_76 = F_60 ( V_20 ) -> V_80 - V_81 ;
V_74 = V_72 -> V_41 >> V_76 ;
V_75 = V_72 -> V_40 >> V_76 ;
if ( V_74 != ( V_73 -> V_40 >> V_76 ) + 1 &&
V_75 + 1 != V_73 -> V_41 >> V_76 )
return - V_79 ;
F_21 ( V_71 , V_73 , L_5 , V_72 ) ;
V_72 -> V_41 = F_61 ( V_72 -> V_41 , V_73 -> V_41 ) ;
V_72 -> V_40 = F_62 ( V_72 -> V_40 , V_73 -> V_40 ) ;
V_72 -> V_38 += V_73 -> V_38 ;
V_72 -> V_34 += V_73 -> V_34 ;
V_72 -> V_10 |= V_73 -> V_10 ;
V_72 -> V_11 |= V_73 -> V_11 ;
F_63 ( & V_73 -> V_35 , & V_72 -> V_35 ) ;
F_54 ( & V_73 -> V_61 ) ;
V_73 -> V_34 = 0 ;
F_34 ( V_73 ) ;
F_55 ( V_73 ) ;
F_36 ( V_63 , V_73 ) ;
F_21 ( V_71 , V_72 , L_6 , V_73 ) ;
return 0 ;
}
void F_64 ( const struct V_62 * V_63 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
F_7 ( F_15 ( & V_2 -> V_32 ) > 0 ) ;
F_7 ( F_65 ( V_2 ) == 0 ) ;
F_7 ( V_2 -> V_38 > 0 ) ;
if ( F_66 ( & V_2 -> V_32 , & V_20 -> V_82 ) ) {
F_7 ( V_2 -> V_29 == V_36 ) ;
if ( V_2 -> V_12 ) {
F_23 ( V_2 , V_83 ) ;
V_2 -> V_12 = 0 ;
} else {
F_23 ( V_2 , V_37 ) ;
F_53 ( V_20 , V_70 ,
V_2 -> V_34 ) ;
F_59 ( V_63 , V_2 , F_9 ( V_2 ) ) ;
F_59 ( V_63 , V_2 , F_6 ( V_2 ) ) ;
if ( V_2 -> V_10 )
F_67 ( & V_2 -> V_61 ,
& V_20 -> V_84 ) ;
}
F_58 ( V_20 ) ;
F_68 ( V_63 , F_60 ( V_20 ) , V_20 ) ;
}
F_36 ( V_63 , V_2 ) ;
}
static inline int F_69 ( struct V_1 * V_85 , struct V_1 * V_86 )
{
return ! ( V_85 -> V_40 < V_86 -> V_41 || V_86 -> V_40 < V_85 -> V_41 ) ;
}
static struct V_1 * F_70 ( const struct V_62 * V_63 ,
struct V_19 * V_20 , T_2 V_54 ,
unsigned int * V_87 )
{
struct V_88 * V_89 = F_60 ( V_20 ) ;
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
return F_71 ( - V_101 ) ;
V_91 = F_72 ( V_63 ) -> V_102 ;
F_73 ( V_91 , L_7 , V_54 ) ;
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
V_97 = F_74 ( T_2 , V_97 , V_93 -> V_111 ) ;
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
V_72 -> V_42 = F_75 ( V_91 -> V_113 ) ;
F_38 ( & V_91 -> V_113 -> V_64 , L_2 , V_72 ) ;
}
F_73 ( * V_87 >= V_99 + V_89 -> V_115 ,
L_8 , * V_87 , V_99 , V_89 -> V_115 ) ;
F_73 ( ( V_97 - V_72 -> V_41 ) < V_98 , V_69 L_3 ,
F_47 ( V_72 ) ) ;
V_116:
F_57 ( V_20 ) ;
V_2 = F_43 ( V_20 , V_72 -> V_41 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
while ( V_2 ) {
T_2 V_117 = V_2 -> V_41 >> V_76 ;
T_2 V_118 = V_2 -> V_40 >> V_76 ;
F_7 ( F_76 ( V_2 ) == 0 ) ;
if ( V_96 > V_118 + 1 )
break;
if ( V_91 -> V_113 != V_2 -> V_42 ) {
F_46 ( ! F_69 ( V_2 , V_72 ) , V_2 ,
V_69 L_3 , F_47 ( V_72 ) ) ;
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_96 + 1 < V_117 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( F_69 ( V_2 , V_72 ) ) {
F_46 ( ( V_2 -> V_41 <= V_72 -> V_41 &&
V_2 -> V_40 >= V_72 -> V_40 ) ,
V_2 , V_69 L_3 , F_47 ( V_72 ) ) ;
if ( V_2 -> V_29 > V_37 || V_2 -> V_13 ) {
V_94 = F_34 ( V_2 ) ;
break;
}
V_95 = F_52 ( V_2 ) ;
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
F_77 ( ( V_2 -> V_41 & ~ V_100 ) == 0 , V_2 ) ;
V_2 -> V_41 = V_72 -> V_41 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
V_95 = F_52 ( V_2 ) ;
} else if ( V_96 == V_118 + 1 ) {
V_2 -> V_40 = V_72 -> V_40 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
if ( F_59 ( V_63 , V_2 , F_6 ( V_2 ) ) == 0 )
* V_87 += V_89 -> V_115 ;
V_95 = F_52 ( V_2 ) ;
}
if ( V_95 )
break;
V_2 = F_6 ( V_2 ) ;
}
F_78 ( V_71 , V_20 ) ;
if ( V_95 ) {
F_7 ( ! V_94 ) ;
if ( ! F_79 ( V_95 ) ) {
F_7 ( V_95 -> V_42 == V_72 -> V_42 ) ;
F_21 ( V_71 , V_95 ,
L_9 , V_54 ) ;
}
} else if ( ! V_94 ) {
F_77 ( F_22 ( V_20 , V_72 ) == 0 , V_72 ) ;
V_72 -> V_38 = V_99 + V_89 -> V_115 ;
* V_87 -= V_72 -> V_38 ;
F_7 ( * V_87 >= 0 ) ;
V_72 -> V_29 = V_37 ;
V_95 = F_52 ( V_72 ) ;
F_45 ( V_20 , V_72 ) ;
F_21 ( V_71 , V_72 , L_10 ,
V_54 , V_93 -> V_111 ) ;
}
F_58 ( V_20 ) ;
if ( V_94 ) {
F_7 ( ! V_95 ) ;
V_27 = F_80 ( V_63 , V_94 , V_33 ) ;
F_36 ( V_63 , V_94 ) ;
V_94 = NULL ;
if ( V_27 < 0 ) {
V_95 = F_71 ( V_27 ) ;
goto V_28;
}
goto V_116;
}
V_28:
F_36 ( V_63 , V_72 ) ;
F_7 ( * V_87 >= 0 ) ;
return V_95 ;
}
int F_81 ( const struct V_62 * V_63 , struct V_1 * V_2 ,
int V_119 , int V_27 )
{
struct V_88 * V_89 = F_60 ( V_2 -> V_23 ) ;
struct V_24 * V_25 ;
struct V_24 * V_56 ;
int V_120 = V_2 -> V_34 ;
int V_121 = 0 ;
int V_122 = V_89 -> V_123 -> V_124 -> V_125 . V_126 ? : 4096 ;
T_3 V_127 = 0 ;
int V_128 = - 1 ;
F_21 ( V_71 , V_2 , L_11 ) ;
V_2 -> V_129 = V_27 ? : V_2 -> V_34 ;
F_77 ( F_82 ( V_27 == 0 , V_2 -> V_29 == V_130 ) , V_2 ) ;
F_83 ( V_89 , & V_2 -> V_35 ) ;
F_84 (oap, tmp, &ext->oe_pages, oap_pending_item) {
F_54 ( & V_25 -> V_131 ) ;
F_54 ( & V_25 -> V_132 ) ;
if ( V_127 <= V_25 -> V_133 ) {
V_127 = V_25 -> V_133 ;
V_128 = V_25 -> V_134 ;
}
-- V_2 -> V_34 ;
F_85 ( V_63 , V_89 , V_25 , V_119 , V_27 ) ;
}
F_77 ( V_2 -> V_34 == 0 , V_2 ) ;
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
F_86 ( V_89 , V_120 , V_121 ) ;
F_56 ( V_2 ) ;
F_36 ( V_63 , V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , enum V_139 V_57 )
{
int V_140 ;
F_57 ( V_2 -> V_23 ) ;
V_140 = V_2 -> V_29 == V_57 ;
F_58 ( V_2 -> V_23 ) ;
return V_140 ;
}
static int F_80 ( const struct V_62 * V_63 , struct V_1 * V_2 ,
enum V_139 V_57 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_141 V_142 = F_88 ( F_89 ( 600 ) , NULL ,
V_143 , NULL ) ;
int V_27 = 0 ;
F_57 ( V_20 ) ;
F_7 ( F_76 ( V_2 ) == 0 ) ;
if ( V_57 == V_33 && ! V_2 -> V_10 && ! V_2 -> V_9 &&
! V_2 -> V_12 ) {
if ( V_2 -> V_29 == V_36 ) {
V_2 -> V_10 = 1 ;
} else if ( V_2 -> V_29 == V_37 ) {
V_2 -> V_10 = 1 ;
F_52 ( V_2 ) ;
V_27 = 1 ;
}
}
F_58 ( V_20 ) ;
if ( V_27 == 1 )
F_64 ( V_63 , V_2 ) ;
V_27 = F_90 ( V_2 -> V_58 , F_87 ( V_2 , V_57 ) , & V_142 ) ;
if ( V_27 == - V_144 ) {
F_21 ( V_55 , V_2 ,
L_12 ,
F_91 ( F_60 ( V_20 ) ) , V_57 ) ;
V_142 = F_92 ( NULL , NULL ) ;
V_27 = F_90 ( V_2 -> V_58 , F_87 ( V_2 , V_57 ) ,
& V_142 ) ;
}
if ( V_27 == 0 && V_2 -> V_129 < 0 )
V_27 = V_2 -> V_129 ;
return V_27 ;
}
static int F_93 ( struct V_1 * V_2 , T_2 V_145 ,
bool V_146 )
{
struct V_62 * V_63 ;
struct V_147 * V_148 ;
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_88 * V_89 = F_60 ( V_20 ) ;
struct V_24 * V_25 ;
struct V_24 * V_56 ;
int V_149 = 0 ;
int V_76 = V_89 -> V_80 - V_81 ;
T_3 V_150 = V_145 >> V_76 ;
int V_87 = 0 ;
int V_120 = 0 ;
int V_27 = 0 ;
int V_151 ;
F_7 ( F_65 ( V_2 ) == 0 ) ;
F_77 ( V_2 -> V_29 == V_83 , V_2 ) ;
F_77 ( ! V_2 -> V_10 , V_2 ) ;
V_63 = F_94 ( & V_151 ) ;
V_148 = & F_95 ( V_63 ) -> V_152 ;
V_148 -> V_153 = F_96 ( F_17 ( V_20 ) ) ;
V_27 = F_97 ( V_63 , V_148 , V_154 , V_148 -> V_153 ) ;
if ( V_27 < 0 )
goto V_28;
F_84 (oap, tmp, &ext->oe_pages, oap_pending_item) {
T_2 V_54 = F_19 ( F_20 ( V_25 ) ) ;
struct V_155 * V_156 = F_98 ( V_25 ) ;
F_7 ( F_3 ( & V_25 -> V_131 ) ) ;
if ( V_54 < V_145 ||
( V_54 == V_145 && V_146 ) ) {
if ( V_54 >> V_76 == V_150 )
++ V_149 ;
continue;
}
F_54 ( & V_25 -> V_132 ) ;
F_99 ( V_156 ) ;
F_38 ( & V_156 -> V_157 , L_13 , V_158 ) ;
if ( F_100 ( V_63 , V_148 , V_156 ) == 0 ) {
F_101 ( V_63 , V_148 , V_156 ) ;
F_102 ( V_63 , V_148 , V_156 ) ;
} else {
F_7 ( V_156 -> V_159 == V_160 ) ;
F_7 ( 0 ) ;
}
F_103 ( & V_156 -> V_157 , L_13 , V_158 ) ;
F_104 ( V_63 , V_156 ) ;
-- V_2 -> V_34 ;
++ V_120 ;
}
F_46 ( F_82 ( V_2 -> V_41 >= V_145 + ! ! V_146 ,
V_2 -> V_34 == 0 ) ,
V_2 , L_14 , V_145 , V_146 ) ;
F_57 ( V_20 ) ;
if ( V_2 -> V_34 == 0 ) {
F_7 ( V_149 == 0 ) ;
V_87 = V_2 -> V_38 ;
V_2 -> V_38 = 0 ;
} else {
int V_161 = ( V_2 -> V_40 >> V_76 ) - V_150 ;
T_2 V_162 ;
if ( V_149 == 0 ) {
F_7 ( V_150 > 0 ) ;
-- V_150 ;
++ V_161 ;
}
V_87 = V_161 << V_89 -> V_80 ;
V_2 -> V_38 -= V_87 ;
V_162 = ( ( V_150 + 1 ) << V_76 ) - 1 ;
V_2 -> V_40 = F_61 ( V_162 , V_2 -> V_39 ) ;
F_7 ( V_2 -> V_40 >= V_2 -> V_41 ) ;
F_7 ( V_2 -> V_38 > 0 ) ;
}
F_58 ( V_20 ) ;
if ( V_87 > 0 || V_120 > 0 )
F_86 ( V_89 , V_120 , V_87 ) ;
V_28:
F_105 ( V_63 , V_148 ) ;
F_106 ( V_63 , & V_151 ) ;
return V_27 ;
}
static int F_107 ( const struct V_62 * V_63 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_24 * V_163 = NULL ;
struct V_19 * V_20 = V_2 -> V_23 ;
unsigned int V_26 = 0 ;
int V_27 ;
F_7 ( F_65 ( V_2 ) == 0 ) ;
F_77 ( V_2 -> V_29 == V_164 , V_2 ) ;
F_77 ( V_2 -> V_165 , V_2 ) ;
F_21 ( V_71 , V_2 , L_15 ) ;
F_18 (oap, &ext->oe_pages, oap_pending_item) {
++ V_26 ;
if ( ! V_163 || V_163 -> V_133 < V_25 -> V_133 )
V_163 = V_25 ;
if ( ( V_25 -> V_166 & V_167 ) != 0 )
continue;
V_27 = F_108 ( V_63 , V_25 , V_70 ) ;
switch ( V_27 ) {
case 0 :
F_109 ( & V_25 -> V_168 ) ;
V_25 -> V_166 |= V_167 ;
F_110 ( & V_25 -> V_168 ) ;
break;
case - V_169 :
F_7 ( ( V_25 -> V_166 & V_167 ) != 0 ) ;
break;
default:
F_73 ( 0 , L_16 , V_27 ) ;
}
}
F_7 ( V_26 == V_2 -> V_34 ) ;
F_7 ( V_163 ) ;
if ( ! ( V_163 -> V_166 & V_170 ) ) {
int V_171 = F_111 ( V_63 , V_163 , V_70 ) ;
F_7 ( V_171 > 0 ) ;
F_7 ( V_163 -> V_172 + V_171 <= V_135 ) ;
V_163 -> V_134 = V_171 ;
F_109 ( & V_163 -> V_168 ) ;
V_163 -> V_166 |= V_170 ;
F_110 ( & V_163 -> V_168 ) ;
}
F_18 (oap, &ext->oe_pages, oap_pending_item) {
if ( ! ( V_25 -> V_166 & V_170 ) ) {
V_25 -> V_134 = V_135 - V_25 -> V_172 ;
F_109 ( & V_163 -> V_168 ) ;
V_25 -> V_166 |= V_170 ;
F_110 ( & V_163 -> V_168 ) ;
}
}
F_57 ( V_20 ) ;
F_23 ( V_2 , V_130 ) ;
F_58 ( V_20 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , T_2 V_54 ,
unsigned int * V_87 )
{
struct V_19 * V_20 = V_2 -> V_23 ;
struct V_88 * V_89 = F_60 ( V_20 ) ;
struct V_1 * V_173 ;
int V_76 = V_89 -> V_80 - V_81 ;
T_2 V_96 = V_54 >> V_76 ;
T_2 V_174 ;
T_2 V_175 ;
unsigned int V_99 = 1 << V_89 -> V_80 ;
int V_27 = 0 ;
F_7 ( V_2 -> V_39 >= V_54 && V_2 -> V_41 <= V_54 ) ;
F_57 ( V_20 ) ;
F_7 ( F_76 ( V_2 ) == 0 ) ;
V_174 = V_2 -> V_40 >> V_76 ;
if ( V_96 > V_174 + 1 ) {
V_27 = - V_79 ;
goto V_28;
}
if ( V_174 >= V_96 ) {
V_27 = 0 ;
goto V_28;
}
F_7 ( V_174 + 1 == V_96 ) ;
V_175 = F_61 ( V_2 -> V_39 , ( ( V_96 + 1 ) << V_76 ) - 1 ) ;
V_173 = F_6 ( V_2 ) ;
if ( V_173 && V_173 -> V_41 <= V_175 ) {
V_27 = - V_176 ;
goto V_28;
}
V_2 -> V_40 = V_175 ;
V_2 -> V_38 += V_99 ;
* V_87 -= V_99 ;
F_7 ( * V_87 >= 0 ) ;
F_46 ( F_22 ( V_20 , V_2 ) == 0 , V_2 ,
L_17 , V_54 ) ;
V_28:
F_58 ( V_20 ) ;
return V_27 ;
}
static void F_113 ( int V_177 , struct V_19 * V_20 ,
const char * V_22 , int line )
{
struct V_1 * V_2 ;
int V_178 ;
F_114 ( V_177 , L_18 ,
V_20 , V_22 , line , F_60 ( V_20 ) -> V_110 ) ;
V_178 = 1 ;
for ( V_2 = F_11 ( V_20 ) ; V_2 ; V_2 = F_6 ( V_2 ) )
F_21 ( V_177 , V_2 , L_19 , V_178 ++ ) ;
V_178 = 1 ;
F_18 (ext, &obj->oo_hp_exts, oe_link)
F_21 ( V_177 , V_2 , L_20 , V_178 ++ ) ;
V_178 = 1 ;
F_18 (ext, &obj->oo_urgent_exts, oe_link)
F_21 ( V_177 , V_2 , L_21 , V_178 ++ ) ;
V_178 = 1 ;
F_18 (ext, &obj->oo_reading_exts, oe_link)
F_21 ( V_177 , V_2 , L_22 , V_178 ++ ) ;
}
static inline int F_115 ( struct V_19 * V_179 )
{
return ! F_3 ( & V_179 -> V_180 ) ||
! F_3 ( & V_179 -> V_181 ) ;
}
static int F_108 ( const struct V_62 * V_63 , struct V_24 * V_25 ,
int V_182 )
{
struct V_183 * V_184 = F_116 ( V_25 ) ;
struct V_155 * V_156 = F_98 ( V_25 ) ;
int V_185 ;
F_7 ( V_182 == V_70 ) ;
V_185 = F_117 ( V_63 , V_156 , V_186 ) ;
if ( V_185 == 0 )
V_184 -> V_187 = F_118 () ;
return V_185 ;
}
static int F_111 ( const struct V_62 * V_63 ,
struct V_24 * V_25 , int V_182 )
{
struct V_183 * V_184 = F_116 ( V_25 ) ;
T_2 V_54 = F_19 ( F_20 ( V_25 ) ) ;
struct V_188 * V_20 ;
struct V_189 * V_190 = & F_95 ( V_63 ) -> V_191 ;
int V_185 ;
T_4 V_192 ;
F_7 ( ! ( V_182 & V_193 ) ) ;
V_20 = V_184 -> V_194 . V_195 ;
F_119 ( V_20 ) ;
V_185 = F_120 ( V_63 , V_20 , V_190 ) ;
F_121 ( V_20 ) ;
if ( V_185 < 0 )
return V_185 ;
V_192 = V_190 -> V_196 ;
if ( F_16 ( V_20 , V_54 ) >= V_192 )
return 0 ;
else if ( F_16 ( V_20 , V_54 + 1 ) > V_192 )
return V_192 % V_135 ;
else
return V_135 ;
}
static int F_122 ( const struct V_62 * V_63 , struct V_24 * V_25 ,
int V_182 , int V_27 )
{
struct V_183 * V_184 = F_116 ( V_25 ) ;
struct V_155 * V_156 = F_98 ( V_25 ) ;
enum V_197 V_198 ;
int V_199 ;
V_182 &= ~ V_200 ;
F_73 ( F_123 ( V_156 -> V_159 == V_201 , V_182 == V_193 ) ,
L_23 , V_156 -> V_159 , V_182 ) ;
F_73 ( F_123 ( V_156 -> V_159 == V_202 , V_182 == V_70 ) ,
L_23 , V_156 -> V_159 , V_182 ) ;
F_7 ( V_184 -> V_203 ) ;
V_198 = V_182 == V_193 ? V_204 : V_186 ;
V_184 -> V_203 = 0 ;
V_184 -> V_187 = 0 ;
V_199 = V_25 -> V_205 & V_206 ;
if ( V_27 == 0 && V_199 ) {
struct V_207 * V_208 = V_184 -> V_194 . V_195 -> V_209 . V_210 ;
struct V_211 * V_212 = & F_124 ( V_208 ) -> V_213 ;
T_1 V_214 = V_25 -> V_134 ;
if ( V_198 == V_204 )
V_212 -> V_215 += V_214 ;
else
V_212 -> V_216 += V_214 ;
}
F_103 ( & V_156 -> V_157 , L_24 , V_156 ) ;
F_125 ( V_63 , V_156 , V_198 , V_27 ) ;
F_104 ( V_63 , V_156 ) ;
return 0 ;
}
static void F_126 ( struct V_88 * V_89 ,
struct V_217 * V_218 )
{
F_127 ( & V_89 -> V_219 ) ;
F_7 ( ! ( V_218 -> V_220 & V_221 ) ) ;
F_128 ( & V_222 ) ;
V_89 -> V_223 ++ ;
V_218 -> V_220 |= V_221 ;
F_114 ( V_71 , L_25 ,
V_135 , V_218 , V_218 -> V_224 ) ;
F_129 ( V_89 ) ;
}
static void F_130 ( struct V_88 * V_89 ,
struct V_217 * V_218 )
{
F_127 ( & V_89 -> V_219 ) ;
if ( ! ( V_218 -> V_220 & V_221 ) ) {
return;
}
V_218 -> V_220 &= ~ V_221 ;
F_131 ( & V_222 ) ;
V_89 -> V_223 -- ;
if ( V_218 -> V_220 & V_225 ) {
V_218 -> V_220 &= ~ V_225 ;
F_131 ( & V_226 ) ;
V_89 -> V_227 -- ;
}
}
static int F_132 ( struct V_88 * V_89 , unsigned int V_214 )
{
int V_27 = - V_228 ;
if ( V_89 -> V_229 >= V_214 ) {
V_89 -> V_229 -= V_214 ;
V_89 -> V_230 += V_214 ;
V_27 = 0 ;
}
return V_27 ;
}
static void F_133 ( struct V_88 * V_89 ,
unsigned int V_231 , unsigned int V_232 )
{
V_89 -> V_230 -= V_231 ;
if ( V_232 > V_231 ) {
V_89 -> V_229 += V_231 ;
V_89 -> V_233 += V_232 - V_231 ;
} else {
V_89 -> V_229 += V_232 ;
}
}
static void F_134 ( struct V_88 * V_89 ,
unsigned int V_231 , unsigned int V_232 )
{
F_109 ( & V_89 -> V_219 ) ;
F_133 ( V_89 , V_231 , V_232 ) ;
if ( V_232 > 0 )
F_135 ( V_89 ) ;
F_110 ( & V_89 -> V_219 ) ;
}
static void F_86 ( struct V_88 * V_89 , unsigned int V_120 ,
unsigned int V_121 )
{
unsigned long V_234 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
F_109 ( & V_89 -> V_219 ) ;
F_136 ( V_120 , & V_222 ) ;
V_89 -> V_223 -= V_120 ;
V_89 -> V_233 += V_121 ;
if ( V_89 -> V_229 < V_234 && V_89 -> V_233 >= V_234 ) {
V_89 -> V_233 -= V_234 ;
V_89 -> V_229 += V_234 ;
}
F_135 ( V_89 ) ;
F_110 ( & V_89 -> V_219 ) ;
F_114 ( V_71 , L_26 ,
V_121 , V_89 -> V_233 ,
V_89 -> V_229 , V_89 -> V_223 << V_81 ) ;
}
static void F_137 ( struct V_88 * V_89 , struct V_24 * V_25 )
{
F_109 ( & V_89 -> V_219 ) ;
F_130 ( V_89 , & V_25 -> V_235 ) ;
F_110 ( & V_89 -> V_219 ) ;
}
static int F_138 ( struct V_88 * V_89 ,
struct V_24 * V_25 ,
int V_214 , int V_236 )
{
int V_27 ;
F_139 ( V_71 , V_89 , L_27 , V_214 ) ;
V_27 = F_132 ( V_89 , V_214 ) ;
if ( V_27 < 0 )
return 0 ;
if ( V_89 -> V_223 <= V_89 -> V_237 &&
F_140 ( & V_222 ) + 1 <= V_238 ) {
F_126 ( V_89 , & V_25 -> V_235 ) ;
if ( V_236 ) {
V_89 -> V_227 ++ ;
F_128 ( & V_226 ) ;
V_25 -> V_205 |= V_225 ;
}
V_27 = 1 ;
} else {
F_133 ( V_89 , V_214 , V_214 ) ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_141 ( struct V_88 * V_89 , struct V_239 * V_240 )
{
int V_27 ;
F_109 ( & V_89 -> V_219 ) ;
V_27 = F_3 ( & V_240 -> V_241 ) ;
F_110 ( & V_89 -> V_219 ) ;
return V_27 ;
}
static int F_142 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_24 * V_25 , int V_214 )
{
struct V_19 * V_179 = V_25 -> V_242 ;
struct V_243 * V_244 = V_179 -> V_245 ;
struct V_239 V_240 ;
struct V_141 V_142 ;
int V_27 = - V_228 ;
V_142 = F_88 ( F_89 ( V_246 ? V_247 : V_248 ) ,
NULL , V_143 , NULL ) ;
F_139 ( V_71 , V_89 , L_27 , V_214 ) ;
F_109 ( & V_89 -> V_219 ) ;
if ( F_143 ( V_249 ) ||
! V_89 -> V_237 || V_89 -> V_250 . V_251 ||
V_244 -> V_252 . V_251 ) {
F_139 ( V_71 , V_89 , L_28 ) ;
V_27 = - V_228 ;
goto V_28;
}
if ( F_138 ( V_89 , V_25 , V_214 , 0 ) ) {
F_139 ( V_71 , V_89 , L_29 ) ;
V_27 = 0 ;
goto V_28;
}
F_31 ( & V_240 . V_253 ) ;
V_240 . V_254 = V_25 ;
V_240 . V_255 = V_214 ;
while ( V_89 -> V_223 > 0 || V_89 -> V_256 > 0 ) {
F_144 ( & V_240 . V_241 , & V_89 -> V_257 ) ;
V_240 . V_258 = 0 ;
F_110 ( & V_89 -> V_219 ) ;
F_68 ( V_63 , V_89 , NULL ) ;
F_114 ( V_71 , L_30 ,
F_91 ( V_89 ) , & V_240 , V_25 ) ;
V_27 = F_90 ( V_240 . V_253 , F_141 ( V_89 , & V_240 ) , & V_142 ) ;
F_109 ( & V_89 -> V_219 ) ;
if ( V_27 < 0 ) {
F_54 ( & V_240 . V_241 ) ;
break;
}
F_7 ( F_3 ( & V_240 . V_241 ) ) ;
V_27 = V_240 . V_258 ;
if ( V_27 != - V_228 )
break;
if ( F_138 ( V_89 , V_25 , V_214 , 0 ) ) {
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
F_78 ( V_71 , V_179 ) ;
V_27 = - V_228 ;
break;
case - V_259 :
F_139 ( V_71 , V_89 , L_33 ) ;
V_27 = - V_260 ;
break;
case - V_228 :
F_139 ( V_71 , V_89 ,
L_34 ) ;
break;
default:
F_114 ( V_71 , L_35 ,
F_91 ( V_89 ) , & V_240 , V_27 ) ;
break;
}
V_28:
F_110 ( & V_89 -> V_219 ) ;
return V_27 ;
}
void F_135 ( struct V_88 * V_89 )
{
struct V_14 * V_261 , * V_56 ;
struct V_239 * V_240 ;
F_145 (l, tmp, &cli->cl_cache_waiters) {
V_240 = F_146 ( V_261 , struct V_239 , V_241 ) ;
F_54 ( & V_240 -> V_241 ) ;
V_240 -> V_258 = - V_228 ;
if ( ( V_89 -> V_223 > V_89 -> V_237 ) ||
( F_140 ( & V_222 ) + 1 >
V_238 ) ) {
F_114 ( V_71 , L_36 ,
V_89 -> V_223 , V_89 -> V_237 ,
V_238 ) ;
goto V_262;
}
if ( F_138 ( V_89 , V_240 -> V_254 , V_240 -> V_255 , 0 ) )
V_240 -> V_258 = 0 ;
V_262:
F_114 ( V_71 , L_37 ,
V_240 , V_240 -> V_254 , V_89 -> V_229 , V_240 -> V_258 ) ;
F_147 ( & V_240 -> V_253 ) ;
}
}
static int F_148 ( struct V_88 * V_89 , struct V_19 * V_179 )
{
int V_263 = ! ! F_3 ( & V_179 -> V_264 ) ;
return F_149 ( V_89 ) >= V_89 -> V_265 + V_263 ;
}
static int F_150 ( struct V_88 * V_89 , struct V_19 * V_179 ,
int V_182 )
{
int V_266 = 0 ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_267 )
V_266 = 1 ;
if ( V_182 & V_70 ) {
if ( F_15 ( & V_179 -> V_268 ) == 0 )
return 0 ;
if ( V_266 ) {
F_114 ( V_71 , L_38 ) ;
return 1 ;
}
if ( ! F_3 ( & V_179 -> V_264 ) ) {
F_114 ( V_71 , L_39 ) ;
return 1 ;
}
if ( ! F_3 ( & V_179 -> V_84 ) ) {
F_114 ( V_71 , L_40 ) ;
return 1 ;
}
if ( ! F_3 ( & V_89 -> V_257 ) ) {
F_114 ( V_71 , L_41 ) ;
return 1 ;
}
if ( F_15 ( & V_179 -> V_268 ) >=
V_89 -> V_110 )
return 1 ;
} else {
if ( F_15 ( & V_179 -> V_269 ) == 0 )
return 0 ;
if ( V_266 ) {
F_114 ( V_71 , L_38 ) ;
return 1 ;
}
if ( ! F_3 ( & V_179 -> V_270 ) )
return 1 ;
}
return 0 ;
}
static void F_53 ( struct V_19 * V_20 , int V_182 , int V_271 )
{
struct V_88 * V_89 = F_60 ( V_20 ) ;
if ( V_182 & V_70 ) {
F_151 ( V_271 , & V_20 -> V_268 ) ;
F_151 ( V_271 , & V_89 -> V_272 ) ;
F_7 ( F_15 ( & V_20 -> V_268 ) >= 0 ) ;
} else {
F_151 ( V_271 , & V_20 -> V_269 ) ;
F_151 ( V_271 , & V_89 -> V_273 ) ;
F_7 ( F_15 ( & V_20 -> V_269 ) >= 0 ) ;
}
F_152 ( V_20 , L_42 , V_182 , V_271 ) ;
}
static int F_153 ( struct V_19 * V_20 )
{
return ! F_3 ( & V_20 -> V_264 ) ;
}
static void F_154 ( struct V_14 * V_274 , struct V_14 * V_15 , int V_275 )
{
if ( F_3 ( V_274 ) && V_275 )
F_144 ( V_274 , V_15 ) ;
else if ( ! F_3 ( V_274 ) && ! V_275 )
F_54 ( V_274 ) ;
}
static int F_155 ( struct V_88 * V_89 , struct V_19 * V_179 )
{
if ( F_153 ( V_179 ) ) {
F_154 ( & V_179 -> V_180 , & V_89 -> V_276 , 0 ) ;
F_154 ( & V_179 -> V_181 , & V_89 -> V_277 , 1 ) ;
} else {
F_154 ( & V_179 -> V_181 , & V_89 -> V_277 , 0 ) ;
F_154 ( & V_179 -> V_180 , & V_89 -> V_276 ,
F_150 ( V_89 , V_179 , V_70 ) ||
F_150 ( V_89 , V_179 , V_193 ) ) ;
}
F_154 ( & V_179 -> V_278 , & V_89 -> V_279 ,
F_15 ( & V_179 -> V_268 ) > 0 ) ;
F_154 ( & V_179 -> V_280 , & V_89 -> V_281 ,
F_15 ( & V_179 -> V_269 ) > 0 ) ;
return F_115 ( V_179 ) ;
}
static int F_156 ( struct V_88 * V_89 , struct V_19 * V_179 )
{
int V_282 ;
F_109 ( & V_89 -> V_219 ) ;
V_282 = F_155 ( V_89 , V_179 ) ;
F_110 ( & V_89 -> V_219 ) ;
return V_282 ;
}
static void F_157 ( struct V_283 * V_284 , T_3 V_285 ,
int V_27 )
{
if ( V_27 ) {
if ( ! V_284 -> V_286 )
V_284 -> V_286 = V_27 ;
V_284 -> V_251 = 1 ;
V_284 -> V_287 = F_158 () ;
return;
}
if ( V_284 -> V_251 && ( V_285 >= V_284 -> V_287 ) )
V_284 -> V_251 = 0 ;
}
static void F_85 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_24 * V_25 , int V_119 , int V_27 )
{
struct V_19 * V_179 = V_25 -> V_242 ;
struct V_243 * V_244 = V_179 -> V_245 ;
T_3 V_285 = 0 ;
if ( V_25 -> V_288 ) {
V_285 = F_159 ( V_25 -> V_288 ) ;
F_160 ( V_25 -> V_288 ) ;
V_25 -> V_288 = NULL ;
}
F_109 ( & V_25 -> V_168 ) ;
V_25 -> V_166 = 0 ;
F_110 ( & V_25 -> V_168 ) ;
V_25 -> V_289 = 0 ;
if ( V_25 -> V_290 & V_70 && V_285 > 0 ) {
F_109 ( & V_89 -> V_219 ) ;
F_157 ( & V_89 -> V_250 , V_285 , V_27 ) ;
F_157 ( & V_244 -> V_252 , V_285 , V_27 ) ;
F_110 ( & V_89 -> V_219 ) ;
}
V_27 = F_122 ( V_63 , V_25 , V_25 -> V_290 , V_27 ) ;
if ( V_27 )
F_161 ( L_43 ,
V_25 , V_179 , V_27 ) ;
}
static int F_162 ( struct V_88 * V_89 ,
struct V_1 * V_2 , struct V_14 * V_291 ,
unsigned int * V_292 , unsigned int * V_98 )
{
struct V_1 * V_56 ;
struct V_24 * V_25 = F_163 ( & V_2 -> V_35 ,
struct V_24 ,
V_132 ) ;
F_77 ( ( V_2 -> V_29 == V_37 || V_2 -> V_29 == V_293 ) ,
V_2 ) ;
* V_98 = F_62 ( V_2 -> V_52 , * V_98 ) ;
if ( * V_292 + V_2 -> V_34 > * V_98 )
return 0 ;
F_18 (tmp, rpclist, oe_link) {
struct V_24 * V_294 ;
V_294 = F_163 ( & V_56 -> V_35 , struct V_24 ,
V_132 ) ;
F_77 ( V_56 -> V_165 == V_158 , V_56 ) ;
if ( F_98 ( V_25 ) -> V_295 != F_98 ( V_294 ) -> V_295 ) {
F_114 ( V_71 , L_44
L_45 ) ;
return 0 ;
}
if ( V_56 -> V_8 != V_2 -> V_8 ||
! V_56 -> V_38 != ! V_2 -> V_38 ||
V_56 -> V_296 || V_2 -> V_296 )
return 0 ;
break;
}
* V_292 += V_2 -> V_34 ;
F_67 ( & V_2 -> V_61 , V_291 ) ;
V_2 -> V_165 = V_158 ;
return 1 ;
}
static unsigned int F_164 ( struct V_19 * V_20 ,
struct V_14 * V_291 )
{
struct V_88 * V_89 = F_60 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_297 ;
unsigned int V_26 = 0 ;
unsigned int V_98 = V_89 -> V_110 ;
F_7 ( F_14 ( V_20 ) ) ;
F_84 (ext, temp, &obj->oo_hp_exts, oe_link) {
F_7 ( V_2 -> V_29 == V_37 ) ;
if ( ! F_162 ( V_89 , V_2 , V_291 , & V_26 ,
& V_98 ) )
return V_26 ;
F_77 ( V_2 -> V_34 <= V_98 , V_2 ) ;
}
if ( V_26 == V_98 )
return V_26 ;
while ( ! F_3 ( & V_20 -> V_84 ) ) {
V_2 = F_146 ( V_20 -> V_84 . V_173 ,
struct V_1 , V_61 ) ;
if ( ! F_162 ( V_89 , V_2 , V_291 , & V_26 ,
& V_98 ) )
return V_26 ;
if ( ! V_2 -> V_6 )
continue;
while ( ( V_2 = F_6 ( V_2 ) ) != NULL ) {
if ( ( V_2 -> V_29 != V_37 ) ||
( ! F_3 ( & V_2 -> V_61 ) &&
V_2 -> V_165 ) )
continue;
if ( ! F_162 ( V_89 , V_2 , V_291 ,
& V_26 , & V_98 ) )
return V_26 ;
}
}
if ( V_26 == V_98 )
return V_26 ;
V_2 = F_11 ( V_20 ) ;
while ( V_2 ) {
if ( ( V_2 -> V_29 != V_37 ) ||
( ! F_3 ( & V_2 -> V_61 ) && V_2 -> V_165 ) ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( ! F_162 ( V_89 , V_2 , V_291 , & V_26 ,
& V_98 ) )
return V_26 ;
V_2 = F_6 ( V_2 ) ;
}
return V_26 ;
}
static int
F_165 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_179 )
__must_hold( V_179 )
{
F_166 ( V_291 ) ;
struct V_1 * V_2 ;
struct V_1 * V_56 ;
struct V_1 * V_298 = NULL ;
T_5 V_26 = 0 ;
int V_199 = 0 ;
int V_27 = 0 ;
F_7 ( F_14 ( V_179 ) ) ;
V_26 = F_164 ( V_179 , & V_291 ) ;
F_7 ( F_123 ( V_26 == 0 , F_3 ( & V_291 ) ) ) ;
if ( F_3 ( & V_291 ) )
return 0 ;
F_53 ( V_179 , V_70 , - V_26 ) ;
F_18 (ext, &rpclist, oe_link) {
F_7 ( V_2 -> V_29 == V_37 ||
V_2 -> V_29 == V_293 ) ;
if ( V_2 -> V_29 == V_37 )
F_23 ( V_2 , V_164 ) ;
else
F_23 ( V_2 , V_130 ) ;
}
F_58 ( V_179 ) ;
F_84 (ext, tmp, &rpclist, oe_link) {
if ( V_2 -> V_29 == V_164 ) {
V_27 = F_107 ( V_63 , V_2 ) ;
if ( F_167 ( V_27 < 0 ) ) {
F_54 ( & V_2 -> V_61 ) ;
F_81 ( V_63 , V_2 , 0 , V_27 ) ;
continue;
}
}
if ( ! V_298 ) {
V_298 = V_2 ;
V_199 = V_2 -> V_8 ;
} else {
F_7 ( V_199 == V_2 -> V_8 ) ;
}
}
if ( ! F_3 ( & V_291 ) ) {
F_7 ( V_26 > 0 ) ;
V_27 = F_168 ( V_63 , V_89 , & V_291 , V_70 ) ;
F_7 ( F_3 ( & V_291 ) ) ;
}
F_57 ( V_179 ) ;
return V_27 ;
}
static int
F_169 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_179 )
__must_hold( V_179 )
{
struct V_1 * V_2 ;
struct V_1 * V_173 ;
F_166 ( V_291 ) ;
unsigned int V_26 = 0 ;
unsigned int V_98 = V_89 -> V_110 ;
int V_27 = 0 ;
F_7 ( F_14 ( V_179 ) ) ;
F_84 (ext, next, &osc->oo_reading_exts, oe_link) {
F_77 ( V_2 -> V_29 == V_293 , V_2 ) ;
if ( ! F_162 ( V_89 , V_2 , & V_291 , & V_26 ,
& V_98 ) )
break;
F_23 ( V_2 , V_130 ) ;
F_77 ( V_2 -> V_34 <= V_98 , V_2 ) ;
}
F_7 ( V_26 <= V_98 ) ;
F_53 ( V_179 , V_193 , - V_26 ) ;
if ( ! F_3 ( & V_291 ) ) {
F_58 ( V_179 ) ;
F_7 ( V_26 > 0 ) ;
V_27 = F_168 ( V_63 , V_89 , & V_291 , V_193 ) ;
F_7 ( F_3 ( & V_291 ) ) ;
F_57 ( V_179 ) ;
}
return V_27 ;
}
static struct V_19 * F_170 ( struct V_88 * V_89 )
{
if ( ! F_3 ( & V_89 -> V_277 ) )
return F_171 ( & V_89 -> V_277 , V_299 ) ;
if ( ! F_3 ( & V_89 -> V_276 ) )
return F_171 ( & V_89 -> V_276 , V_300 ) ;
if ( ! F_3 ( & V_89 -> V_257 ) &&
! F_3 ( & V_89 -> V_279 ) )
return F_171 ( & V_89 -> V_279 , V_301 ) ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_267 ) {
if ( ! F_3 ( & V_89 -> V_279 ) )
return F_171 ( & V_89 -> V_279 , V_301 ) ;
if ( ! F_3 ( & V_89 -> V_281 ) )
return F_171 ( & V_89 -> V_281 , V_302 ) ;
}
return NULL ;
}
static void F_172 ( const struct V_62 * V_63 , struct V_88 * V_89 )
__must_hold( &cli->cl_loi_list_lock
static int F_173 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_179 , int V_303 )
{
int V_27 = 0 ;
if ( V_179 && F_156 ( V_89 , V_179 ) == 0 )
return 0 ;
if ( ! V_303 ) {
F_109 ( & V_89 -> V_219 ) ;
F_172 ( V_63 , V_89 ) ;
F_110 ( & V_89 -> V_219 ) ;
} else {
F_114 ( V_71 , L_46 , V_89 ) ;
F_7 ( V_89 -> V_304 ) ;
V_27 = F_174 ( V_89 -> V_304 ) ;
}
return V_27 ;
}
static int F_68 ( const struct V_62 * V_63 ,
struct V_88 * V_89 , struct V_19 * V_179 )
{
return F_173 ( V_63 , V_89 , V_179 , 1 ) ;
}
void F_175 ( const struct V_62 * V_63 , struct V_88 * V_89 ,
struct V_19 * V_179 )
{
( void ) F_173 ( V_63 , V_89 , V_179 , 0 ) ;
}
int F_176 ( struct V_19 * V_179 , struct V_183 * V_305 ,
struct V_156 * V_156 , T_4 V_136 )
{
struct V_306 * exp = F_177 ( V_179 ) ;
struct V_24 * V_25 = & V_305 -> V_307 ;
if ( ! V_156 )
return F_178 ( sizeof( * V_25 ) ) ;
V_25 -> V_308 = V_309 ;
V_25 -> V_310 = & exp -> V_311 -> V_312 . V_89 ;
V_25 -> V_242 = V_179 ;
V_25 -> V_313 = V_156 ;
V_25 -> V_133 = V_136 ;
F_7 ( ! ( V_136 & ~ V_137 ) ) ;
if ( F_179 ( V_314 ) )
V_25 -> V_205 = V_200 ;
F_30 ( & V_25 -> V_132 ) ;
F_30 ( & V_25 -> V_131 ) ;
F_180 ( & V_25 -> V_168 ) ;
F_114 ( V_315 , L_47 ,
V_25 , V_156 , V_25 -> V_133 ) ;
return 0 ;
}
int F_181 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_183 * V_305 )
{
struct V_316 * V_317 = F_72 ( V_63 ) ;
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 = & V_305 -> V_307 ;
struct V_88 * V_89 = V_25 -> V_310 ;
struct V_19 * V_179 = V_25 -> V_242 ;
T_2 V_54 ;
unsigned int V_87 = 0 , V_56 ;
int V_318 = V_319 ;
int V_182 = V_70 ;
int V_320 = 0 ;
int V_27 = 0 ;
if ( V_25 -> V_308 != V_309 )
return - V_77 ;
if ( ! V_89 -> V_123 || V_89 -> V_123 -> V_267 )
return - V_321 ;
if ( ! F_3 ( & V_25 -> V_132 ) ||
! F_3 ( & V_25 -> V_131 ) )
return - V_78 ;
V_318 |= V_305 -> V_322 ? V_206 : 0 ;
if ( F_179 ( V_314 ) ) {
V_318 |= V_200 ;
V_182 |= V_200 ;
}
if ( ! ( V_182 & V_200 ) ) {
struct V_188 * V_20 ;
struct V_189 * V_190 ;
unsigned int V_323 [ V_324 ] ;
V_20 = F_96 ( & V_179 -> V_325 ) ;
V_190 = & F_95 ( V_63 ) -> V_191 ;
F_119 ( V_20 ) ;
V_27 = F_120 ( V_63 , V_20 , V_190 ) ;
F_121 ( V_20 ) ;
V_323 [ V_326 ] = V_190 -> V_327 ;
V_323 [ V_328 ] = V_190 -> V_329 ;
if ( V_27 == 0 && F_182 ( V_89 , V_323 ) == V_330 )
V_27 = - V_228 ;
if ( V_27 )
return V_27 ;
}
V_25 -> V_290 = V_182 ;
V_25 -> V_172 = V_305 -> V_331 ;
V_25 -> V_134 = V_305 -> V_332 - V_305 -> V_331 ;
V_25 -> V_166 = 0 ;
V_25 -> V_205 = V_318 ;
F_152 ( V_179 , L_48 ,
V_25 , V_25 -> V_313 , V_25 -> V_290 & V_333 ) ;
V_54 = F_19 ( F_20 ( V_25 ) ) ;
V_2 = V_317 -> V_334 ;
if ( V_2 && V_2 -> V_41 <= V_54 && V_2 -> V_39 >= V_54 ) {
V_87 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
if ( V_2 -> V_40 >= V_54 )
V_87 = 0 ;
F_109 ( & V_89 -> V_219 ) ;
V_27 = F_138 ( V_89 , V_25 , V_87 , 0 ) ;
F_110 ( & V_89 -> V_219 ) ;
if ( V_27 == 0 ) {
V_87 = 0 ;
V_320 = 1 ;
} else if ( V_2 -> V_40 < V_54 ) {
V_56 = V_87 ;
V_27 = F_112 ( V_2 , V_54 , & V_56 ) ;
if ( V_27 < 0 ) {
V_320 = 1 ;
} else {
F_21 ( V_71 , V_2 ,
L_49 , V_54 ) ;
F_134 ( V_89 , V_87 , V_56 ) ;
V_87 = 0 ;
}
}
V_27 = 0 ;
} else if ( V_2 ) {
V_320 = 1 ;
}
if ( V_320 ) {
F_64 ( V_63 , V_2 ) ;
V_317 -> V_334 = NULL ;
V_2 = NULL ;
}
if ( ! V_2 ) {
V_56 = ( 1 << V_89 -> V_80 ) + V_89 -> V_115 ;
F_7 ( ! V_317 -> V_334 ) ;
F_7 ( F_82 ( V_87 > 0 , V_87 >= V_56 ) ) ;
V_27 = 0 ;
if ( V_87 == 0 ) {
V_27 = F_142 ( V_63 , V_89 , V_25 , V_56 ) ;
if ( V_27 == 0 )
V_87 = V_56 ;
}
V_56 = V_87 ;
if ( V_27 == 0 ) {
V_2 = F_70 ( V_63 , V_179 , V_54 , & V_56 ) ;
if ( F_79 ( V_2 ) ) {
F_7 ( V_56 == V_87 ) ;
F_137 ( V_89 , V_25 ) ;
V_27 = F_183 ( V_2 ) ;
V_2 = NULL ;
} else {
V_317 -> V_334 = V_2 ;
}
}
if ( V_87 > 0 )
F_134 ( V_89 , V_87 , V_56 ) ;
}
F_7 ( F_82 ( V_27 == 0 , V_2 ) ) ;
if ( V_2 ) {
F_46 ( V_2 -> V_40 >= V_54 && V_2 -> V_41 <= V_54 ,
V_2 , L_50 , V_54 ) ;
F_7 ( ( V_25 -> V_205 & V_221 ) != 0 ) ;
F_57 ( V_179 ) ;
if ( V_2 -> V_34 == 0 )
V_2 -> V_8 = V_305 -> V_322 ;
else
F_7 ( V_2 -> V_8 == V_305 -> V_322 ) ;
++ V_2 -> V_34 ;
F_144 ( & V_25 -> V_132 , & V_2 -> V_35 ) ;
F_58 ( V_179 ) ;
}
return V_27 ;
}
int F_184 ( const struct V_62 * V_63 ,
struct V_19 * V_20 , struct V_183 * V_305 )
{
struct V_24 * V_25 = & V_305 -> V_307 ;
int V_27 = 0 ;
F_7 ( V_25 -> V_308 == V_309 ) ;
F_114 ( V_315 , L_51 ,
V_25 , V_305 , F_19 ( F_20 ( V_25 ) ) ) ;
if ( ! F_3 ( & V_25 -> V_131 ) ) {
F_114 ( V_71 , L_52 , V_25 ) ;
V_27 = - V_78 ;
} else if ( ! F_3 ( & V_25 -> V_132 ) ) {
struct V_1 * V_2 = NULL ;
F_57 ( V_20 ) ;
V_2 = F_44 ( V_20 , F_19 ( F_20 ( V_25 ) ) ) ;
F_58 ( V_20 ) ;
if ( V_2 && V_2 -> V_29 != V_83 ) {
F_21 ( V_55 , V_2 , L_53 ,
F_19 ( F_20 ( V_25 ) ) ) ;
V_27 = - V_78 ;
}
if ( V_2 )
F_36 ( V_63 , V_2 ) ;
}
return V_27 ;
}
int F_185 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_183 * V_305 )
{
struct V_1 * V_2 = NULL ;
struct V_19 * V_20 = F_186 ( V_305 -> V_194 . V_195 ) ;
struct V_155 * V_335 = V_305 -> V_194 . V_336 ;
T_2 V_54 = F_19 ( V_305 ) ;
struct V_24 * V_25 = & V_305 -> V_307 ;
bool V_337 = false ;
int V_27 = 0 ;
F_57 ( V_20 ) ;
V_2 = F_44 ( V_20 , V_54 ) ;
if ( ! V_2 ) {
F_78 ( V_55 , V_20 ) ;
F_73 ( 0 , L_54 , V_54 ) ;
}
switch ( V_2 -> V_29 ) {
case V_130 :
case V_293 :
F_187 ( V_55 , V_63 , V_335 , L_55 ) ;
F_7 ( 0 ) ;
break;
case V_164 :
case V_83 :
case V_36 :
V_27 = - V_176 ;
goto V_28;
default:
break;
}
V_27 = F_188 ( V_63 , V_148 , V_335 , V_186 ) ;
if ( V_27 )
goto V_28;
F_109 ( & V_25 -> V_168 ) ;
V_25 -> V_166 |= V_167 | V_338 ;
F_110 ( & V_25 -> V_168 ) ;
if ( F_189 () )
V_2 -> V_11 = 1 ;
V_2 -> V_10 = 1 ;
if ( V_2 -> V_29 == V_37 ) {
F_21 ( V_71 , V_2 ,
L_56 , V_25 ) ;
if ( F_3 ( & V_2 -> V_61 ) )
F_144 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
V_337 = true ;
}
V_27 = 0 ;
V_28:
F_58 ( V_20 ) ;
F_36 ( V_63 , V_2 ) ;
if ( V_337 )
F_68 ( V_63 , F_60 ( V_20 ) , V_20 ) ;
return V_27 ;
}
int F_190 ( const struct V_62 * V_63 , struct V_183 * V_305 )
{
struct V_24 * V_25 = & V_305 -> V_307 ;
struct V_19 * V_20 = V_25 -> V_242 ;
struct V_88 * V_89 = F_60 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_95 = NULL ;
struct V_14 * V_339 ;
T_2 V_54 = F_19 ( V_305 ) ;
int V_27 = - V_78 ;
int V_182 ;
F_7 ( ! V_25 -> V_289 ) ;
V_25 -> V_289 = 1 ;
F_57 ( V_20 ) ;
if ( V_25 -> V_290 & V_70 ) {
V_339 = & V_20 -> V_84 ;
V_182 = V_70 ;
} else {
V_339 = & V_20 -> V_270 ;
V_182 = V_193 ;
}
F_18 (ext, plist, oe_link) {
if ( V_2 -> V_41 <= V_54 && V_2 -> V_40 >= V_54 ) {
F_7 ( V_2 -> V_29 == V_293 ) ;
V_95 = F_34 ( V_2 ) ;
break;
}
}
if ( V_95 ) {
F_54 ( & V_95 -> V_61 ) ;
F_53 ( V_20 , V_182 , - V_95 -> V_34 ) ;
F_58 ( V_20 ) ;
F_81 ( V_63 , V_95 , 0 , - V_259 ) ;
F_36 ( V_63 , V_95 ) ;
V_27 = 0 ;
} else {
F_58 ( V_20 ) ;
if ( V_25 -> V_288 ) {
F_191 ( V_25 -> V_288 ) ;
F_192 ( V_25 -> V_288 ) ;
F_160 ( V_25 -> V_288 ) ;
V_25 -> V_288 = NULL ;
}
}
F_156 ( V_89 , V_20 ) ;
return V_27 ;
}
int F_193 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
struct V_14 * V_15 , int V_182 , int V_318 )
{
struct V_88 * V_89 = F_60 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_24 * V_25 , * V_56 ;
int V_26 = 0 ;
int V_340 = V_89 -> V_110 ;
bool V_341 = true ;
T_2 V_47 = V_342 ;
T_2 V_48 = 0 ;
F_18 (oap, list, oap_pending_item) {
struct V_183 * V_184 = F_116 ( V_25 ) ;
T_2 V_54 = F_19 ( V_184 ) ;
if ( V_54 > V_48 )
V_48 = V_54 ;
if ( V_54 < V_47 )
V_47 = V_54 ;
++ V_26 ;
V_340 <<= ( V_26 > V_340 ) ;
if ( F_167 ( V_184 -> V_331 > 0 || V_184 -> V_332 < V_135 ) )
V_341 = false ;
}
V_2 = F_25 ( V_20 ) ;
if ( ! V_2 ) {
F_84 (oap, tmp, list, oap_pending_item) {
F_54 ( & V_25 -> V_132 ) ;
F_85 ( V_63 , V_89 , V_25 , 0 , - V_101 ) ;
}
return - V_101 ;
}
V_2 -> V_5 = ! ! ( V_182 & V_193 ) ;
V_2 -> V_7 = 1 ;
V_2 -> V_296 = ! V_341 ;
V_2 -> V_10 = 1 ;
V_2 -> V_41 = V_47 ;
V_2 -> V_40 = V_48 ;
V_2 -> V_39 = V_48 ;
V_2 -> V_23 = V_20 ;
V_2 -> V_8 = ! ! ( V_318 & V_206 ) ;
V_2 -> V_34 = V_26 ;
V_2 -> V_52 = V_340 ;
F_63 ( V_15 , & V_2 -> V_35 ) ;
F_57 ( V_20 ) ;
F_23 ( V_2 , V_293 ) ;
if ( V_182 & V_70 ) {
F_144 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
F_53 ( V_20 , V_70 , V_26 ) ;
} else {
F_144 ( & V_2 -> V_61 , & V_20 -> V_270 ) ;
F_53 ( V_20 , V_193 , V_26 ) ;
}
F_58 ( V_20 ) ;
F_68 ( V_63 , V_89 , V_20 ) ;
return 0 ;
}
int F_194 ( const struct V_62 * V_63 , struct V_316 * V_317 ,
struct V_19 * V_20 , T_3 V_343 )
{
struct V_88 * V_89 = F_60 ( V_20 ) ;
struct V_1 * V_2 ;
struct V_1 * V_297 ;
struct V_1 * V_344 = NULL ;
T_2 V_54 ;
F_166 ( V_15 ) ;
int V_185 = 0 ;
bool V_146 ;
V_54 = F_195 ( F_17 ( V_20 ) , V_343 ) ;
V_146 = V_343 > F_16 ( F_17 ( V_20 ) , V_54 ) ;
V_345:
F_57 ( V_20 ) ;
V_2 = F_43 ( V_20 , V_54 ) ;
if ( ! V_2 )
V_2 = F_11 ( V_20 ) ;
else if ( V_2 -> V_40 < V_54 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 ) {
F_77 ( V_2 -> V_29 != V_83 , V_2 ) ;
if ( V_2 -> V_29 > V_37 || V_2 -> V_10 ) {
F_7 ( ! V_2 -> V_9 ) ;
F_21 ( V_71 , V_2 ,
L_57 ) ;
V_344 = F_34 ( V_2 ) ;
break;
}
F_21 ( V_71 , V_2 , L_58 , V_343 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_29 == V_36 ) {
F_7 ( ! V_2 -> V_12 ) ;
V_2 -> V_12 = 1 ;
} else {
F_77 ( V_2 -> V_29 == V_37 , V_2 ) ;
F_23 ( V_2 , V_83 ) ;
F_53 ( V_20 , V_70 ,
- V_2 -> V_34 ) ;
}
F_77 ( F_3 ( & V_2 -> V_61 ) , V_2 ) ;
F_144 ( & V_2 -> V_61 , & V_15 ) ;
V_2 = F_6 ( V_2 ) ;
}
F_58 ( V_20 ) ;
F_156 ( V_89 , V_20 ) ;
F_84 (ext, temp, &list, oe_link) {
int V_27 ;
F_54 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_29 != V_83 )
F_80 ( V_63 , V_2 , V_83 ) ;
V_27 = F_93 ( V_2 , V_54 , V_146 ) ;
if ( V_27 < 0 ) {
if ( V_185 == 0 )
V_185 = V_27 ;
F_21 ( V_55 , V_2 ,
L_59 , V_27 ) ;
} else if ( V_2 -> V_34 == 0 ) {
F_56 ( V_2 ) ;
} else {
F_46 ( V_2 -> V_41 <= V_54 , V_2 ,
L_60 , V_54 , V_146 ) ;
V_54 = V_2 -> V_40 + 1 ;
V_146 = false ;
F_7 ( ! V_317 -> V_346 ) ;
V_317 -> V_346 = F_34 ( V_2 ) ;
F_21 ( V_71 , V_2 ,
L_61 , V_343 ) ;
}
F_36 ( V_63 , V_2 ) ;
}
if ( V_344 ) {
int V_27 ;
V_27 = F_80 ( V_63 , V_344 , V_33 ) ;
if ( V_27 < 0 )
F_21 ( V_71 , V_344 , L_62 , V_27 ) ;
F_36 ( V_63 , V_344 ) ;
V_344 = NULL ;
goto V_345;
}
return V_185 ;
}
void F_196 ( const struct V_62 * V_63 , struct V_316 * V_317 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_317 -> V_346 ;
V_317 -> V_346 = NULL ;
if ( V_2 ) {
bool V_337 = false ;
F_77 ( V_2 -> V_34 > 0 , V_2 ) ;
F_77 ( V_2 -> V_29 == V_83 , V_2 ) ;
F_77 ( ! V_2 -> V_10 , V_2 ) ;
F_21 ( V_71 , V_2 , L_63 ) ;
F_57 ( V_20 ) ;
F_23 ( V_2 , V_37 ) ;
if ( V_2 -> V_13 && ! V_2 -> V_10 ) {
V_2 -> V_10 = 1 ;
F_67 ( & V_2 -> V_61 , & V_20 -> V_84 ) ;
V_337 = true ;
}
F_53 ( V_20 , V_70 , V_2 -> V_34 ) ;
F_58 ( V_20 ) ;
F_36 ( V_63 , V_2 ) ;
if ( V_337 )
F_68 ( V_63 , F_60 ( V_20 ) , V_20 ) ;
}
}
int F_197 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_2 V_47 , T_2 V_48 )
{
struct V_1 * V_2 ;
T_2 V_54 = V_47 ;
int V_185 = 0 ;
V_345:
F_57 ( V_20 ) ;
V_2 = F_43 ( V_20 , V_54 ) ;
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
F_77 ( F_82 ( V_2 -> V_29 == V_37 ,
V_2 -> V_9 || V_2 -> V_10 ) , V_2 ) ;
F_77 ( F_82 ( V_2 -> V_29 == V_36 ,
! V_2 -> V_9 && V_2 -> V_10 ) , V_2 ) ;
V_54 = V_2 -> V_40 + 1 ;
F_34 ( V_2 ) ;
F_58 ( V_20 ) ;
V_27 = F_80 ( V_63 , V_2 , V_33 ) ;
if ( V_185 == 0 )
V_185 = V_27 ;
F_36 ( V_63 , V_2 ) ;
goto V_345;
}
F_58 ( V_20 ) ;
F_152 ( V_20 , L_64 ) ;
return V_185 ;
}
int F_198 ( const struct V_62 * V_63 , struct V_19 * V_20 ,
T_2 V_47 , T_2 V_48 , int V_347 , int V_348 )
{
struct V_1 * V_2 ;
F_166 ( V_349 ) ;
bool V_337 = false ;
int V_185 = 0 ;
F_57 ( V_20 ) ;
V_2 = F_43 ( V_20 , V_47 ) ;
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
V_185 += V_2 -> V_34 ;
if ( ! V_348 ) {
struct V_14 * V_15 = NULL ;
if ( V_347 ) {
F_77 ( ! V_2 -> V_9 , V_2 ) ;
V_2 -> V_9 = 1 ;
V_15 = & V_20 -> V_264 ;
} else if ( ! V_2 -> V_10 ) {
V_2 -> V_10 = 1 ;
V_15 = & V_20 -> V_84 ;
}
if ( V_15 )
F_67 ( & V_2 -> V_61 , V_15 ) ;
V_337 = true ;
} else {
F_77 ( V_2 -> V_41 >= V_47 &&
V_2 -> V_39 <= V_48 , V_2 ) ;
F_23 ( V_2 , V_164 ) ;
V_2 -> V_165 = V_158 ;
F_67 ( & V_2 -> V_61 , & V_349 ) ;
F_53 ( V_20 , V_70 ,
- V_2 -> V_34 ) ;
}
break;
case V_36 :
F_7 ( V_347 == 0 && V_348 == 0 ) ;
V_2 -> V_10 = 1 ;
break;
case V_83 :
default:
break;
}
V_2 = F_6 ( V_2 ) ;
}
F_58 ( V_20 ) ;
F_7 ( F_82 ( ! V_348 , F_3 ( & V_349 ) ) ) ;
if ( ! F_3 ( & V_349 ) ) {
struct V_1 * V_56 ;
int V_27 ;
F_156 ( F_60 ( V_20 ) , V_20 ) ;
F_84 (ext, tmp, &discard_list, oe_link) {
F_54 ( & V_2 -> V_61 ) ;
F_77 ( V_2 -> V_29 == V_164 , V_2 ) ;
V_27 = F_107 ( V_63 , V_2 ) ;
if ( F_167 ( V_27 < 0 ) ) {
F_21 ( V_55 , V_2 ,
L_65 , V_27 ) ;
if ( V_185 >= 0 )
V_185 = V_27 ;
}
F_81 ( V_63 , V_2 , 0 , 0 ) ;
}
}
if ( V_337 )
F_175 ( V_63 , F_60 ( V_20 ) , V_20 ) ;
if ( V_347 || V_348 ) {
int V_27 ;
V_27 = F_197 ( V_63 , V_20 , V_47 , V_48 ) ;
if ( V_185 >= 0 && V_27 < 0 )
V_185 = V_27 ;
}
F_152 ( V_20 , L_66 , V_47 , V_48 , V_185 ) ;
return V_185 ;
}
int F_199 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_19 * V_179 , T_2 V_47 , T_2 V_48 ,
T_6 V_350 , void * V_351 )
{
struct V_183 * V_305 ;
void * * V_352 ;
T_2 V_353 ;
unsigned int V_354 ;
unsigned int V_355 ;
unsigned int V_356 ;
int V_357 = V_358 ;
bool V_359 = true ;
V_353 = V_47 ;
V_352 = F_95 ( V_63 ) -> V_360 ;
F_109 ( & V_179 -> V_361 ) ;
while ( ( V_354 = F_200 ( & V_179 -> V_362 , V_352 ,
V_353 , V_363 ) ) > 0 ) {
struct V_155 * V_156 ;
bool V_364 = false ;
for ( V_355 = 0 , V_356 = 0 ; V_355 < V_354 ; ++ V_355 ) {
V_305 = V_352 [ V_355 ] ;
V_352 [ V_355 ] = NULL ;
V_353 = F_19 ( V_305 ) ;
if ( V_353 > V_48 ) {
V_364 = true ;
break;
}
V_156 = V_305 -> V_194 . V_336 ;
F_7 ( V_156 -> V_295 == V_365 ) ;
if ( V_156 -> V_159 == V_160 )
continue;
F_99 ( V_156 ) ;
F_201 ( & V_156 -> V_157 ,
L_67 , V_158 ) ;
V_352 [ V_356 ++ ] = V_305 ;
}
++ V_353 ;
F_110 ( & V_179 -> V_361 ) ;
V_359 = false ;
for ( V_355 = 0 ; V_355 < V_356 ; ++ V_355 ) {
V_305 = V_352 [ V_355 ] ;
if ( V_357 == V_358 )
V_357 = (* V_350)( V_63 , V_148 , V_305 , V_351 ) ;
V_156 = V_305 -> V_194 . V_336 ;
F_103 ( & V_156 -> V_157 , L_67 , V_158 ) ;
F_104 ( V_63 , V_156 ) ;
}
if ( V_354 < V_363 || V_364 )
break;
if ( V_357 == V_358 && F_202 () )
V_357 = V_366 ;
if ( V_357 != V_358 )
break;
F_109 ( & V_179 -> V_361 ) ;
V_359 = true ;
}
if ( V_359 )
F_110 ( & V_179 -> V_361 ) ;
return V_357 ;
}
static int F_203 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_183 * V_305 , void * V_351 )
{
struct V_367 * V_368 = F_95 ( V_63 ) ;
struct V_19 * V_179 = V_351 ;
T_2 V_54 ;
V_54 = F_19 ( V_305 ) ;
if ( V_54 >= V_368 -> V_369 ) {
struct V_370 * V_56 ;
struct V_155 * V_156 = V_305 -> V_194 . V_336 ;
V_56 = F_204 ( V_63 , V_179 , V_54 ,
V_371 ) ;
if ( V_56 ) {
T_3 V_48 = V_56 -> V_45 . V_46 . V_48 ;
V_368 -> V_369 = F_195 ( F_17 ( V_179 ) , V_48 + 1 ) ;
if ( V_48 == V_372 )
V_368 -> V_369 = V_342 ;
F_39 ( V_56 ) ;
} else if ( F_100 ( V_63 , V_148 , V_156 ) == 0 ) {
F_101 ( V_63 , V_148 , V_156 ) ;
F_102 ( V_63 , V_148 , V_156 ) ;
} else {
F_7 ( V_156 -> V_159 == V_160 ) ;
}
}
V_368 -> V_373 = V_54 + 1 ;
return V_358 ;
}
static int F_205 ( const struct V_62 * V_63 , struct V_147 * V_148 ,
struct V_183 * V_305 , void * V_351 )
{
struct V_367 * V_368 = F_95 ( V_63 ) ;
struct V_155 * V_156 = V_305 -> V_194 . V_336 ;
V_368 -> V_373 = F_19 ( V_305 ) + 1 ;
if ( F_100 ( V_63 , V_148 , V_156 ) == 0 ) {
F_206 ( F_82 ( V_156 -> V_295 == V_365 ,
! F_207 ( F_208 ( V_156 ) ) ) ) ;
F_101 ( V_63 , V_148 , V_156 ) ;
F_102 ( V_63 , V_148 , V_156 ) ;
} else {
F_7 ( V_156 -> V_159 == V_160 ) ;
}
return V_358 ;
}
int F_209 ( const struct V_62 * V_63 , struct V_19 * V_179 ,
T_2 V_47 , T_2 V_48 , enum V_374 V_375 )
{
struct V_367 * V_368 = F_95 ( V_63 ) ;
struct V_147 * V_148 = & V_368 -> V_152 ;
T_6 V_350 ;
int V_357 ;
int V_185 ;
V_148 -> V_153 = F_96 ( F_17 ( V_179 ) ) ;
V_148 -> V_376 = 1 ;
V_185 = F_97 ( V_63 , V_148 , V_154 , V_148 -> V_153 ) ;
if ( V_185 != 0 )
goto V_28;
V_350 = V_375 == V_377 ? F_203 : F_205 ;
V_368 -> V_369 = V_47 ;
V_368 -> V_373 = V_47 ;
do {
V_357 = F_199 ( V_63 , V_148 , V_179 ,
V_368 -> V_373 , V_48 , V_350 , V_179 ) ;
if ( V_368 -> V_373 > V_48 )
break;
if ( V_357 == V_366 )
F_210 () ;
} while ( V_357 != V_358 );
V_28:
F_105 ( V_63 , V_148 ) ;
return V_185 ;
}
