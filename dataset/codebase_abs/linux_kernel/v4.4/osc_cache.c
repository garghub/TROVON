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
if ( V_16 == NULL )
return NULL ;
return F_5 ( V_16 , struct V_1 , V_17 ) ;
}
static inline struct V_1 * F_6 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
F_7 ( V_2 -> V_6 ) ;
return F_4 ( F_8 ( & V_2 -> V_17 ) ) ;
}
static inline struct V_1 * F_9 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
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
if ( V_2 -> V_41 == NULL && V_2 -> V_37 > 0 ) {
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
for ( V_52 = F_11 ( V_19 ) ; V_52 != NULL ; V_52 = F_6 ( V_52 ) ) {
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
V_2 = F_23 ( V_55 , V_56 | V_57 ) ;
if ( V_2 == NULL )
return NULL ;
F_24 ( & V_2 -> V_17 ) ;
V_2 -> V_22 = V_19 ;
F_25 ( & V_2 -> V_30 , 1 ) ;
F_25 ( & V_2 -> V_31 , 0 ) ;
F_26 ( & V_2 -> V_58 ) ;
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
static void F_32 ( const struct V_59 * V_60 , struct V_1 * V_2 )
{
F_7 ( F_15 ( & V_2 -> V_30 ) > 0 ) ;
if ( F_33 ( & V_2 -> V_30 ) ) {
F_7 ( F_3 ( & V_2 -> V_58 ) ) ;
F_7 ( F_15 ( & V_2 -> V_31 ) == 0 ) ;
F_7 ( V_2 -> V_28 == V_32 ) ;
F_7 ( ! V_2 -> V_6 ) ;
if ( V_2 -> V_41 ) {
F_34 ( V_60 , V_2 -> V_41 ) ;
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
struct V_1 * V_52 , * V_61 = NULL ;
F_7 ( F_14 ( V_19 ) ) ;
while ( V_16 != NULL ) {
V_52 = F_4 ( V_16 ) ;
if ( V_49 < V_52 -> V_40 ) {
V_16 = V_16 -> V_62 ;
} else if ( V_49 > V_52 -> V_39 ) {
V_61 = F_4 ( V_16 ) ;
V_16 = V_16 -> V_63 ;
} else {
return V_52 ;
}
}
return V_61 ;
}
static struct V_1 * F_38 ( struct V_18 * V_19 ,
T_1 V_49 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( V_19 , V_49 ) ;
if ( V_2 != NULL && V_2 -> V_40 <= V_49 && V_49 <= V_2 -> V_39 )
return F_30 ( V_2 ) ;
return NULL ;
}
static void F_39 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_15 * * V_16 = & V_19 -> V_20 . V_15 ;
struct V_15 * V_64 = NULL ;
struct V_1 * V_52 ;
F_7 ( V_2 -> V_6 == 0 ) ;
F_7 ( V_2 -> V_22 == V_19 ) ;
F_7 ( F_14 ( V_19 ) ) ;
while ( * V_16 != NULL ) {
V_52 = F_4 ( * V_16 ) ;
V_64 = * V_16 ;
if ( V_2 -> V_39 < V_52 -> V_40 )
V_16 = & ( * V_16 ) -> V_62 ;
else if ( V_2 -> V_40 > V_52 -> V_39 )
V_16 = & ( * V_16 ) -> V_63 ;
else
F_40 ( 0 , V_52 , V_65 , F_41 ( V_2 ) ) ;
}
F_42 ( & V_2 -> V_17 , V_64 , V_16 ) ;
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
F_47 ( V_19 , V_66 , - V_2 -> V_33 ) ;
}
F_31 ( & V_2 -> V_31 ) ;
F_48 ( & V_2 -> V_58 ) ;
return F_30 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_7 ( F_14 ( V_2 -> V_22 ) ) ;
F_7 ( F_3 ( & V_2 -> V_34 ) ) ;
F_44 ( V_2 ) ;
F_48 ( & V_2 -> V_58 ) ;
F_20 ( V_2 , V_32 ) ;
F_18 ( V_67 , V_2 , L_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
F_51 ( V_19 ) ;
F_49 ( V_2 ) ;
F_52 ( V_19 ) ;
}
static int F_53 ( const struct V_59 * V_60 , struct V_1 * V_68 ,
struct V_1 * V_69 )
{
struct V_18 * V_19 = V_68 -> V_22 ;
T_1 V_70 ;
T_1 V_71 ;
int V_72 ;
F_7 ( V_68 -> V_28 == V_36 ) ;
F_7 ( F_14 ( V_19 ) ) ;
if ( V_69 == NULL )
return - V_73 ;
if ( V_69 -> V_28 != V_36 || V_69 -> V_12 )
return - V_74 ;
if ( V_68 -> V_38 != V_69 -> V_38 )
return - V_75 ;
F_7 ( V_68 -> V_41 == V_69 -> V_41 ) ;
V_72 = F_54 ( V_19 ) -> V_76 - V_77 ;
V_70 = V_68 -> V_40 >> V_72 ;
V_71 = V_68 -> V_39 >> V_72 ;
if ( V_70 != ( V_69 -> V_39 >> V_72 ) + 1 &&
V_71 + 1 != V_69 -> V_40 >> V_72 )
return - V_75 ;
F_18 ( V_67 , V_69 , L_3 , V_68 ) ;
V_68 -> V_40 = F_55 ( V_68 -> V_40 , V_69 -> V_40 ) ;
V_68 -> V_39 = F_56 ( V_68 -> V_39 , V_69 -> V_39 ) ;
V_68 -> V_37 += V_69 -> V_37 ;
V_68 -> V_33 += V_69 -> V_33 ;
V_68 -> V_9 |= V_69 -> V_9 ;
V_68 -> V_10 |= V_69 -> V_10 ;
F_57 ( & V_69 -> V_34 , & V_68 -> V_34 ) ;
F_48 ( & V_69 -> V_58 ) ;
V_69 -> V_33 = 0 ;
F_30 ( V_69 ) ;
F_49 ( V_69 ) ;
F_32 ( V_60 , V_69 ) ;
F_18 ( V_67 , V_68 , L_4 , V_69 ) ;
return 0 ;
}
void F_58 ( const struct V_59 * V_60 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
F_7 ( F_15 ( & V_2 -> V_31 ) > 0 ) ;
F_7 ( F_59 ( V_2 ) == 0 ) ;
F_7 ( V_2 -> V_37 > 0 ) ;
if ( F_60 ( & V_2 -> V_31 , & V_19 -> V_78 ) ) {
F_7 ( V_2 -> V_28 == V_35 ) ;
if ( V_2 -> V_11 ) {
F_20 ( V_2 , V_79 ) ;
V_2 -> V_11 = 0 ;
} else {
F_20 ( V_2 , V_36 ) ;
F_47 ( V_19 , V_66 ,
V_2 -> V_33 ) ;
F_53 ( V_60 , V_2 , F_9 ( V_2 ) ) ;
F_53 ( V_60 , V_2 , F_6 ( V_2 ) ) ;
if ( V_2 -> V_9 )
F_61 ( & V_2 -> V_58 ,
& V_19 -> V_80 ) ;
}
F_52 ( V_19 ) ;
F_62 ( V_60 , F_54 ( V_19 ) , V_19 ) ;
}
F_32 ( V_60 , V_2 ) ;
}
static inline int F_63 ( struct V_1 * V_81 , struct V_1 * V_82 )
{
return ! ( V_81 -> V_39 < V_82 -> V_40 || V_82 -> V_39 < V_81 -> V_40 ) ;
}
struct V_1 * F_64 ( const struct V_59 * V_60 ,
struct V_18 * V_19 , T_1 V_49 ,
int * V_83 )
{
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_86 * V_87 ;
struct V_1 * V_68 ;
struct V_1 * V_2 ;
struct V_1 * V_88 = NULL ;
struct V_1 * V_89 = NULL ;
T_1 V_90 ;
T_1 V_91 ;
int V_92 ;
int V_93 ;
int V_72 ;
int V_94 ;
int V_26 ;
V_68 = F_22 ( V_19 ) ;
if ( V_68 == NULL )
return F_65 ( - V_95 ) ;
V_87 = F_66 ( V_60 , F_67 ( V_19 ) , V_49 , NULL , 1 , 0 ) ;
F_7 ( V_87 != NULL ) ;
F_7 ( V_87 -> V_44 . V_96 >= V_97 ) ;
F_7 ( V_85 -> V_76 >= V_77 ) ;
V_72 = V_85 -> V_76 - V_77 ;
V_94 = ~ ( ( 1 << V_72 ) - 1 ) ;
V_93 = 1 << V_85 -> V_76 ;
V_90 = V_49 >> V_72 ;
V_92 = V_85 -> V_98 ;
F_7 ( ( V_92 & ~ V_94 ) == 0 ) ;
V_91 = V_49 - ( V_49 % V_92 ) + V_92 - 1 ;
V_91 = F_68 ( T_1 , V_91 , V_87 -> V_44 . V_46 ) ;
V_68 -> V_38 = V_91 ;
V_68 -> V_40 = V_49 & V_94 ;
V_68 -> V_39 = ( ( V_49 + ~ V_94 + 1 ) & V_94 ) - 1 ;
if ( V_68 -> V_40 < V_87 -> V_44 . V_45 )
V_68 -> V_40 = V_87 -> V_44 . V_45 ;
if ( V_68 -> V_39 > V_91 )
V_68 -> V_39 = V_91 ;
V_68 -> V_41 = V_87 ;
V_68 -> V_37 = 0 ;
V_68 -> V_47 = V_92 ;
F_69 ( * V_83 >= V_93 + V_85 -> V_99 ,
L_5 , * V_83 , V_93 , V_85 -> V_99 ) ;
F_69 ( ( V_91 - V_68 -> V_40 ) < V_92 , V_65 , F_41 ( V_68 ) ) ;
V_100:
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_68 -> V_40 ) ;
if ( V_2 == NULL )
V_2 = F_11 ( V_19 ) ;
while ( V_2 != NULL ) {
T_2 V_101 = V_2 -> V_40 >> V_72 ;
T_2 V_102 = V_2 -> V_39 >> V_72 ;
F_7 ( F_70 ( V_2 ) == 0 ) ;
if ( V_90 > V_102 + 1 )
break;
if ( V_87 != V_2 -> V_41 ) {
F_40 ( ! F_63 ( V_2 , V_68 ) , V_2 ,
V_65 , F_41 ( V_68 ) ) ;
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_90 + 1 < V_101 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( F_63 ( V_2 , V_68 ) ) {
F_40 ( ( V_2 -> V_40 <= V_68 -> V_40 &&
V_2 -> V_39 >= V_68 -> V_39 ) ,
V_2 , V_65 , F_41 ( V_68 ) ) ;
if ( V_2 -> V_28 > V_36 || V_2 -> V_12 ) {
V_88 = F_30 ( V_2 ) ;
break;
}
V_89 = F_46 ( V_2 ) ;
break;
}
if ( V_2 -> V_28 != V_36 || V_2 -> V_12 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_2 -> V_38 != V_91 ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( V_90 + 1 == V_101 ) {
F_71 ( ( V_2 -> V_40 & ~ V_94 ) == 0 , V_2 ) ;
V_2 -> V_40 = V_68 -> V_40 ;
V_2 -> V_37 += V_93 ;
* V_83 -= V_93 ;
V_89 = F_46 ( V_2 ) ;
} else if ( V_90 == V_102 + 1 ) {
V_2 -> V_39 = V_68 -> V_39 ;
V_2 -> V_37 += V_93 ;
* V_83 -= V_93 ;
if ( F_53 ( V_60 , V_2 , F_6 ( V_2 ) ) == 0 )
* V_83 += V_85 -> V_99 ;
V_89 = F_46 ( V_2 ) ;
}
if ( V_89 != NULL )
break;
V_2 = F_6 ( V_2 ) ;
}
F_72 ( V_67 , V_19 ) ;
if ( V_89 != NULL ) {
F_7 ( V_88 == NULL ) ;
if ( ! F_73 ( V_89 ) ) {
F_7 ( V_89 -> V_41 == V_68 -> V_41 ) ;
F_18 ( V_67 , V_89 ,
L_6 , V_49 ) ;
}
} else if ( V_88 == NULL ) {
F_71 ( F_19 ( V_19 , V_68 ) == 0 , V_68 ) ;
V_68 -> V_37 = V_93 + V_85 -> V_99 ;
* V_83 -= V_68 -> V_37 ;
F_7 ( * V_83 >= 0 ) ;
V_68 -> V_28 = V_36 ;
V_89 = F_46 ( V_68 ) ;
F_39 ( V_19 , V_68 ) ;
F_18 ( V_67 , V_68 , L_7 ,
V_49 , V_87 -> V_44 . V_46 ) ;
}
F_52 ( V_19 ) ;
if ( V_88 != NULL ) {
F_7 ( V_89 == NULL ) ;
V_26 = F_74 ( V_60 , V_88 , V_32 ) ;
F_32 ( V_60 , V_88 ) ;
V_88 = NULL ;
if ( V_26 < 0 ) {
V_89 = F_65 ( V_26 ) ;
goto V_27;
}
goto V_100;
}
V_27:
F_32 ( V_60 , V_68 ) ;
F_7 ( * V_83 >= 0 ) ;
return V_89 ;
}
int F_75 ( const struct V_59 * V_60 , struct V_1 * V_2 ,
int V_103 , int V_26 )
{
struct V_84 * V_85 = F_54 ( V_2 -> V_22 ) ;
struct V_23 * V_24 ;
struct V_23 * V_52 ;
int V_104 = V_2 -> V_33 ;
int V_105 = 0 ;
int V_106 = V_85 -> V_107 -> V_108 -> V_109 . V_110 ? : 4096 ;
T_3 V_111 = 0 ;
int V_112 = - 1 ;
F_18 ( V_67 , V_2 , L_8 ) ;
V_2 -> V_113 = V_26 ? : V_2 -> V_33 ;
F_71 ( F_76 ( V_26 == 0 , V_2 -> V_28 == V_114 ) , V_2 ) ;
F_77 (oap, tmp, &ext->oe_pages,
oap_pending_item) {
F_48 ( & V_24 -> V_115 ) ;
F_48 ( & V_24 -> V_116 ) ;
if ( V_111 <= V_24 -> V_117 ) {
V_111 = V_24 -> V_117 ;
V_112 = V_24 -> V_118 ;
}
-- V_2 -> V_33 ;
F_78 ( V_60 , V_85 , V_24 , V_103 , V_26 ) ;
}
F_71 ( V_2 -> V_33 == 0 , V_2 ) ;
if ( ! V_103 ) {
V_105 = V_2 -> V_37 ;
} else if ( V_106 < V_119 &&
V_112 != V_119 ) {
int V_120 = V_24 -> V_121 & ~ V_122 ;
int V_123 = V_24 -> V_118 + ( V_120 & ( V_106 - 1 ) ) ;
int V_124 = ( V_120 + V_24 -> V_118 ) & ( V_106 - 1 ) ;
if ( V_124 )
V_123 += V_106 - V_124 ;
V_105 = V_119 - V_123 ;
}
if ( V_2 -> V_37 > 0 )
F_79 ( V_85 , V_104 , V_105 ) ;
F_50 ( V_2 ) ;
F_32 ( V_60 , V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , int V_53 )
{
int V_125 ;
F_51 ( V_2 -> V_22 ) ;
V_125 = V_2 -> V_28 == V_53 ;
F_52 ( V_2 -> V_22 ) ;
return V_125 ;
}
static int F_74 ( const struct V_59 * V_60 , struct V_1 * V_2 ,
int V_53 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_126 V_127 = F_81 ( F_82 ( 600 ) , NULL ,
V_128 , NULL ) ;
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
F_58 ( V_60 , V_2 ) ;
V_26 = F_83 ( V_2 -> V_54 , F_80 ( V_2 , V_53 ) , & V_127 ) ;
if ( V_26 == - V_129 ) {
F_18 ( V_51 , V_2 ,
L_9 ,
F_84 ( V_19 ) -> V_130 -> V_131 , V_53 ) ;
V_127 = F_85 ( V_128 , NULL ) ;
V_26 = F_83 ( V_2 -> V_54 , F_80 ( V_2 , V_53 ) ,
& V_127 ) ;
}
if ( V_26 == 0 && V_2 -> V_113 < 0 )
V_26 = V_2 -> V_113 ;
return V_26 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_132 ,
bool V_133 )
{
struct V_134 V_135 ;
struct V_59 * V_60 ;
struct V_136 * V_137 ;
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_23 * V_24 ;
struct V_23 * V_52 ;
int V_138 = 0 ;
int V_72 = V_85 -> V_76 - V_77 ;
T_3 V_139 = V_132 >> V_72 ;
int V_83 = 0 ;
int V_104 = 0 ;
int V_26 = 0 ;
F_7 ( F_59 ( V_2 ) == 0 ) ;
F_71 ( V_2 -> V_28 == V_79 , V_2 ) ;
F_71 ( ! V_2 -> V_9 , V_2 ) ;
V_60 = F_87 ( & V_135 ) ;
V_137 = & F_88 ( V_60 ) -> V_140 ;
V_137 -> V_141 = F_89 ( F_67 ( V_19 ) ) ;
V_26 = F_90 ( V_60 , V_137 , V_142 , V_137 -> V_141 ) ;
if ( V_26 < 0 )
goto V_27;
F_77 (oap, tmp, &ext->oe_pages,
oap_pending_item) {
struct V_143 * V_144 = F_17 ( V_24 ) ;
struct V_143 * V_145 = F_91 ( V_144 ) ;
F_7 ( F_3 ( & V_24 -> V_115 ) ) ;
if ( V_144 -> V_50 < V_132 ||
( V_144 -> V_50 == V_132 && V_133 ) ) {
if ( V_144 -> V_50 >> V_72 == V_139 )
++ V_138 ;
continue;
}
F_48 ( & V_24 -> V_116 ) ;
F_92 ( V_145 ) ;
F_93 ( & V_145 -> V_146 , L_10 , V_147 ) ;
if ( F_94 ( V_60 , V_137 , V_145 ) == 0 ) {
F_95 ( V_60 , V_137 , V_145 ) ;
F_96 ( V_60 , V_137 , V_145 ) ;
F_97 ( V_60 , V_137 , V_145 ) ;
} else {
F_7 ( V_145 -> V_148 == V_149 ) ;
F_7 ( 0 ) ;
}
F_98 ( & V_145 -> V_146 , L_10 , V_147 ) ;
F_99 ( V_60 , V_145 ) ;
-- V_2 -> V_33 ;
++ V_104 ;
}
F_40 ( F_76 ( V_2 -> V_40 >= V_132 + ! ! V_133 ,
V_2 -> V_33 == 0 ) ,
V_2 , L_11 , V_132 , V_133 ) ;
F_51 ( V_19 ) ;
if ( V_2 -> V_33 == 0 ) {
F_7 ( V_138 == 0 ) ;
V_83 = V_2 -> V_37 ;
V_2 -> V_37 = 0 ;
} else {
int V_150 = ( V_2 -> V_39 >> V_72 ) - V_139 ;
T_1 V_151 ;
if ( V_138 == 0 ) {
F_7 ( V_139 > 0 ) ;
-- V_139 ;
++ V_150 ;
}
V_83 = V_150 << V_85 -> V_76 ;
V_2 -> V_37 -= V_83 ;
V_151 = ( ( V_139 + 1 ) << V_72 ) - 1 ;
V_2 -> V_39 = F_55 ( V_151 , V_2 -> V_38 ) ;
F_7 ( V_2 -> V_39 >= V_2 -> V_40 ) ;
F_7 ( V_2 -> V_37 > 0 ) ;
}
F_52 ( V_19 ) ;
if ( V_83 > 0 || V_104 > 0 )
F_79 ( V_85 , V_104 , V_83 ) ;
V_27:
F_100 ( V_60 , V_137 ) ;
F_101 ( & V_135 , V_60 ) ;
return V_26 ;
}
static int F_102 ( const struct V_59 * V_60 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_23 * V_152 = NULL ;
struct V_18 * V_19 = V_2 -> V_22 ;
int V_25 = 0 ;
int V_26 ;
F_7 ( F_59 ( V_2 ) == 0 ) ;
F_71 ( V_2 -> V_28 == V_153 , V_2 ) ;
F_71 ( V_2 -> V_154 != NULL , V_2 ) ;
F_18 ( V_67 , V_2 , L_12 ) ;
F_16 (oap, &ext->oe_pages, oap_pending_item) {
++ V_25 ;
if ( V_152 == NULL || V_152 -> V_117 < V_24 -> V_117 )
V_152 = V_24 ;
if ( ( V_24 -> V_155 & V_156 ) != 0 )
continue;
V_26 = F_103 ( V_60 , V_24 , V_66 ) ;
switch ( V_26 ) {
case 0 :
F_104 ( & V_24 -> V_157 ) ;
V_24 -> V_155 |= V_156 ;
F_105 ( & V_24 -> V_157 ) ;
break;
case - V_158 :
F_7 ( ( V_24 -> V_155 & V_156 ) != 0 ) ;
break;
default:
F_69 ( 0 , L_13 , V_26 ) ;
}
}
F_7 ( V_25 == V_2 -> V_33 ) ;
F_7 ( V_152 != NULL ) ;
if ( ! ( V_152 -> V_155 & V_159 ) ) {
V_152 -> V_118 = F_106 ( V_60 , V_152 , V_66 ) ;
F_7 ( V_152 -> V_118 > 0 ) ;
F_7 ( V_152 -> V_121 + V_152 -> V_118 <= V_119 ) ;
V_152 -> V_155 |= V_159 ;
}
F_16 (oap, &ext->oe_pages, oap_pending_item) {
if ( ! ( V_24 -> V_155 & V_159 ) ) {
V_24 -> V_118 = V_119 - V_24 -> V_121 ;
V_24 -> V_155 |= V_159 ;
}
}
F_51 ( V_19 ) ;
F_20 ( V_2 , V_114 ) ;
F_52 ( V_19 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_49 , int * V_83 )
{
struct V_18 * V_19 = V_2 -> V_22 ;
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_1 * V_160 ;
int V_72 = V_85 -> V_76 - V_77 ;
T_1 V_90 = V_49 >> V_72 ;
T_1 V_161 ;
T_1 V_162 ;
int V_93 = 1 << V_85 -> V_76 ;
int V_26 = 0 ;
F_7 ( V_2 -> V_38 >= V_49 && V_2 -> V_40 <= V_49 ) ;
F_51 ( V_19 ) ;
F_7 ( F_70 ( V_2 ) == 0 ) ;
V_161 = V_2 -> V_39 >> V_72 ;
if ( V_90 > V_161 + 1 ) {
V_26 = - V_75 ;
goto V_27;
}
if ( V_161 >= V_90 ) {
V_26 = 0 ;
goto V_27;
}
F_7 ( V_161 + 1 == V_90 ) ;
V_162 = F_55 ( V_2 -> V_38 , ( ( V_90 + 1 ) << V_72 ) - 1 ) ;
V_160 = F_6 ( V_2 ) ;
if ( V_160 != NULL && V_160 -> V_40 <= V_162 ) {
V_26 = - V_163 ;
goto V_27;
}
V_2 -> V_39 = V_162 ;
V_2 -> V_37 += V_93 ;
* V_83 -= V_93 ;
F_7 ( * V_83 >= 0 ) ;
F_40 ( F_19 ( V_19 , V_2 ) == 0 , V_2 ,
L_14 , V_49 ) ;
V_27:
F_52 ( V_19 ) ;
return V_26 ;
}
static void F_108 ( int V_164 , struct V_18 * V_19 ,
const char * V_21 , int line )
{
struct V_1 * V_2 ;
int V_165 ;
F_109 ( V_164 , L_15 ,
V_19 , V_21 , line , F_54 ( V_19 ) -> V_98 ) ;
V_165 = 1 ;
for ( V_2 = F_11 ( V_19 ) ; V_2 != NULL ; V_2 = F_6 ( V_2 ) )
F_18 ( V_164 , V_2 , L_16 , V_165 ++ ) ;
V_165 = 1 ;
F_16 (ext, &obj->oo_hp_exts, oe_link)
F_18 ( V_164 , V_2 , L_17 , V_165 ++ ) ;
V_165 = 1 ;
F_16 (ext, &obj->oo_urgent_exts, oe_link)
F_18 ( V_164 , V_2 , L_18 , V_165 ++ ) ;
V_165 = 1 ;
F_16 (ext, &obj->oo_reading_exts, oe_link)
F_18 ( V_164 , V_2 , L_19 , V_165 ++ ) ;
}
static inline int F_110 ( struct V_18 * V_166 )
{
return ! F_3 ( & V_166 -> V_167 ) ||
! F_3 ( & V_166 -> V_168 ) ;
}
static int F_103 ( const struct V_59 * V_60 , struct V_23 * V_24 ,
int V_169 )
{
struct V_170 * V_171 = F_111 ( V_24 ) ;
struct V_143 * V_145 = F_91 ( F_17 ( V_24 ) ) ;
int V_172 ;
F_7 ( V_169 == V_66 ) ;
V_172 = F_112 ( V_60 , V_145 , V_173 ) ;
if ( V_172 == 0 )
V_171 -> V_174 = F_113 () ;
return V_172 ;
}
static int F_106 ( const struct V_59 * V_60 ,
struct V_23 * V_24 , int V_169 )
{
struct V_170 * V_171 = F_111 ( V_24 ) ;
struct V_143 * V_145 = F_17 ( V_24 ) ;
struct V_175 * V_19 ;
struct V_176 * V_177 = & F_88 ( V_60 ) -> V_178 ;
int V_172 ;
T_2 V_179 ;
F_7 ( ! ( V_169 & V_180 ) ) ;
F_7 ( V_171 != NULL ) ;
V_19 = V_171 -> V_181 . V_182 ;
F_114 ( V_19 ) ;
V_172 = F_115 ( V_60 , V_19 , V_177 ) ;
F_116 ( V_19 ) ;
if ( V_172 < 0 )
return V_172 ;
V_179 = V_177 -> V_183 ;
if ( F_117 ( V_19 , V_145 -> V_50 ) >= V_179 )
return 0 ;
else if ( F_117 ( V_19 , V_145 -> V_50 + 1 ) > V_179 )
return V_179 % V_119 ;
else
return V_119 ;
}
static int F_118 ( const struct V_59 * V_60 , struct V_23 * V_24 ,
int V_169 , int V_26 )
{
struct V_170 * V_171 = F_111 ( V_24 ) ;
struct V_143 * V_145 = F_91 ( F_17 ( V_24 ) ) ;
struct V_18 * V_19 = F_119 ( V_171 -> V_181 . V_182 ) ;
enum V_184 V_185 ;
int V_186 ;
V_169 &= ~ V_187 ;
F_7 ( F_120 ( V_145 -> V_148 == V_188 , V_169 == V_180 ) ) ;
F_7 ( F_120 ( V_145 -> V_148 == V_189 , V_169 == V_66 ) ) ;
F_7 ( V_171 -> V_190 ) ;
if ( V_145 -> V_191 != NULL )
F_121 ( V_60 , V_145 ) ;
F_7 ( V_145 -> V_191 == NULL ) ;
V_185 = V_169 == V_180 ? V_192 : V_173 ;
V_171 -> V_190 = 0 ;
F_104 ( & V_19 -> V_193 ) ;
F_7 ( V_171 -> V_194 != NULL ) ;
F_7 ( ! F_3 ( & V_171 -> V_195 ) ) ;
F_48 ( & V_171 -> V_195 ) ;
V_171 -> V_194 = NULL ;
F_105 ( & V_19 -> V_193 ) ;
V_171 -> V_174 = 0 ;
V_186 = V_24 -> V_196 & V_197 ;
if ( V_26 == 0 && V_186 ) {
struct V_198 * V_199 = V_171 -> V_181 . V_182 -> V_200 . V_201 ;
struct V_202 * V_203 = & F_122 ( V_199 ) -> V_204 ;
int V_205 = V_24 -> V_118 ;
if ( V_185 == V_192 )
V_203 -> V_206 += V_205 ;
else
V_203 -> V_207 += V_205 ;
}
F_98 ( & V_145 -> V_146 , L_20 , V_145 ) ;
F_123 ( V_60 , V_145 , V_185 , V_26 ) ;
return 0 ;
}
static void F_124 ( struct V_84 * V_85 ,
struct V_208 * V_209 )
{
F_125 ( & V_85 -> V_210 . V_87 ) ;
F_7 ( ! ( V_209 -> V_211 & V_212 ) ) ;
F_31 ( & V_213 ) ;
V_85 -> V_214 += V_119 ;
V_209 -> V_211 |= V_212 ;
F_109 ( V_67 , L_21 ,
V_119 , V_209 , V_209 -> V_215 ) ;
F_126 ( V_85 ) ;
}
static void F_127 ( struct V_84 * V_85 ,
struct V_208 * V_209 )
{
F_125 ( & V_85 -> V_210 . V_87 ) ;
if ( ! ( V_209 -> V_211 & V_212 ) ) {
return;
}
V_209 -> V_211 &= ~ V_212 ;
F_36 ( & V_213 ) ;
V_85 -> V_214 -= V_119 ;
if ( V_209 -> V_211 & V_216 ) {
V_209 -> V_211 &= ~ V_216 ;
F_36 ( & V_217 ) ;
V_85 -> V_218 -= V_119 ;
}
}
static int F_128 ( struct V_84 * V_85 , unsigned int V_205 )
{
int V_26 = - V_219 ;
if ( V_85 -> V_220 >= V_205 ) {
V_85 -> V_220 -= V_205 ;
V_85 -> V_221 += V_205 ;
V_26 = 0 ;
}
return V_26 ;
}
static void F_129 ( struct V_84 * V_85 ,
unsigned int V_222 , unsigned int V_223 )
{
V_85 -> V_221 -= V_222 ;
if ( V_223 > V_222 ) {
V_85 -> V_220 += V_222 ;
V_85 -> V_224 += V_223 - V_222 ;
} else {
V_85 -> V_220 += V_223 ;
}
}
void F_130 ( struct V_84 * V_85 ,
unsigned int V_222 , unsigned int V_223 )
{
F_131 ( & V_85 -> V_210 ) ;
F_129 ( V_85 , V_222 , V_223 ) ;
if ( V_223 > 0 )
F_132 ( V_85 ) ;
F_133 ( & V_85 -> V_210 ) ;
}
static void F_79 ( struct V_84 * V_85 , unsigned int V_104 ,
unsigned int V_105 )
{
int V_225 = ( 1 << V_85 -> V_76 ) + V_85 -> V_99 ;
F_131 ( & V_85 -> V_210 ) ;
F_134 ( V_104 , & V_213 ) ;
V_85 -> V_214 -= V_104 << V_77 ;
V_85 -> V_224 += V_105 ;
if ( V_85 -> V_220 < V_225 && V_85 -> V_224 >= V_225 ) {
V_85 -> V_224 -= V_225 ;
V_85 -> V_220 += V_225 ;
}
F_132 ( V_85 ) ;
F_133 ( & V_85 -> V_210 ) ;
F_109 ( V_67 , L_22 ,
V_105 , V_85 -> V_224 ,
V_85 -> V_220 , V_85 -> V_214 ) ;
}
static void F_135 ( struct V_84 * V_85 , struct V_23 * V_24 )
{
F_131 ( & V_85 -> V_210 ) ;
F_127 ( V_85 , & V_24 -> V_226 ) ;
F_133 ( & V_85 -> V_210 ) ;
}
static int F_136 ( struct V_84 * V_85 ,
struct V_23 * V_24 ,
int V_205 , int V_227 )
{
int V_26 ;
F_137 ( V_85 , L_23 , V_205 ) ;
V_26 = F_128 ( V_85 , V_205 ) ;
if ( V_26 < 0 )
return 0 ;
if ( V_85 -> V_214 + V_119 <= V_85 -> V_228 &&
F_15 ( & V_213 ) + 1 <= V_229 ) {
F_124 ( V_85 , & V_24 -> V_226 ) ;
if ( V_227 ) {
V_85 -> V_218 += V_119 ;
F_31 ( & V_217 ) ;
V_24 -> V_196 |= V_216 ;
}
V_26 = 1 ;
} else {
F_129 ( V_85 , V_205 , V_205 ) ;
V_26 = 0 ;
}
return V_26 ;
}
static int F_138 ( struct V_84 * V_85 , struct V_230 * V_231 )
{
int V_26 ;
F_131 ( & V_85 -> V_210 ) ;
V_26 = F_3 ( & V_231 -> V_232 ) ;
F_133 ( & V_85 -> V_210 ) ;
return V_26 ;
}
static int F_139 ( const struct V_59 * V_60 , struct V_84 * V_85 ,
struct V_23 * V_24 , int V_205 )
{
struct V_18 * V_166 = V_24 -> V_233 ;
struct V_234 * V_235 = V_166 -> V_236 ;
struct V_230 V_231 ;
struct V_126 V_127 = F_85 ( V_128 , NULL ) ;
int V_26 = - V_219 ;
F_137 ( V_85 , L_23 , V_205 ) ;
F_131 ( & V_85 -> V_210 ) ;
if ( F_140 ( V_237 ) ||
V_85 -> V_228 < V_119 ||
V_85 -> V_238 . V_239 || V_235 -> V_240 . V_239 ) {
V_26 = - V_219 ;
goto V_27;
}
if ( F_136 ( V_85 , V_24 , V_205 , 0 ) ) {
V_26 = 0 ;
goto V_27;
}
F_27 ( & V_231 . V_241 ) ;
V_231 . V_242 = V_24 ;
V_231 . V_243 = V_205 ;
while ( V_85 -> V_214 > 0 || V_85 -> V_244 > 0 ) {
F_141 ( & V_231 . V_232 , & V_85 -> V_245 ) ;
V_231 . V_246 = 0 ;
F_133 ( & V_85 -> V_210 ) ;
F_62 ( V_60 , V_85 , NULL ) ;
F_109 ( V_67 , L_24 ,
V_85 -> V_107 -> V_108 -> V_131 , & V_231 , V_24 ) ;
V_26 = F_83 ( V_231 . V_241 , F_138 ( V_85 , & V_231 ) , & V_127 ) ;
F_131 ( & V_85 -> V_210 ) ;
if ( V_26 < 0 ) {
F_48 ( & V_231 . V_232 ) ;
goto V_27;
}
F_7 ( F_3 ( & V_231 . V_232 ) ) ;
V_26 = V_231 . V_246 ;
if ( V_26 != - V_219 )
goto V_27;
if ( F_136 ( V_85 , V_24 , V_205 , 0 ) ) {
V_26 = 0 ;
goto V_27;
}
}
V_27:
F_133 ( & V_85 -> V_210 ) ;
F_137 ( V_85 , L_25 , V_26 ) ;
return V_26 ;
}
void F_132 ( struct V_84 * V_85 )
{
struct V_13 * V_247 , * V_52 ;
struct V_230 * V_231 ;
F_142 (l, tmp, &cli->cl_cache_waiters) {
V_231 = F_143 ( V_247 , struct V_230 , V_232 ) ;
F_48 ( & V_231 -> V_232 ) ;
V_231 -> V_246 = - V_219 ;
if ( ( V_85 -> V_214 + V_119 > V_85 -> V_228 ) ||
( F_15 ( & V_213 ) + 1 >
V_229 ) ) {
F_109 ( V_67 , L_26 ,
V_85 -> V_214 ,
V_85 -> V_228 , V_229 ) ;
goto V_248;
}
V_231 -> V_246 = 0 ;
if ( ! F_136 ( V_85 , V_231 -> V_242 , V_231 -> V_243 , 0 ) )
V_231 -> V_246 = - V_219 ;
V_248:
F_109 ( V_67 , L_27 ,
V_231 , V_231 -> V_242 , V_85 -> V_220 , V_231 -> V_246 ) ;
F_144 ( & V_231 -> V_241 ) ;
}
}
static int F_145 ( struct V_84 * V_85 , struct V_18 * V_166 )
{
int V_249 = ! ! F_3 ( & V_166 -> V_250 ) ;
return F_146 ( V_85 ) >= V_85 -> V_251 + V_249 ;
}
static int F_147 ( struct V_84 * V_85 , struct V_18 * V_166 ,
int V_169 )
{
int V_252 = 0 ;
if ( ( V_85 -> V_107 == NULL || V_85 -> V_107 -> V_253 ) )
V_252 = 1 ;
if ( V_169 & V_66 ) {
if ( F_15 ( & V_166 -> V_254 ) == 0 )
return 0 ;
if ( V_252 ) {
F_109 ( V_67 , L_28 ) ;
return 1 ;
}
if ( ! F_3 ( & V_166 -> V_250 ) ) {
F_109 ( V_67 , L_29 ) ;
return 1 ;
}
if ( ! F_3 ( & V_166 -> V_80 ) ) {
F_109 ( V_67 , L_30 ) ;
return 1 ;
}
if ( ! F_3 ( & V_85 -> V_245 ) ) {
F_109 ( V_67 , L_31 ) ;
return 1 ;
}
if ( F_15 ( & V_166 -> V_254 ) >=
V_85 -> V_98 )
return 1 ;
} else {
if ( F_15 ( & V_166 -> V_255 ) == 0 )
return 0 ;
if ( V_252 ) {
F_109 ( V_67 , L_28 ) ;
return 1 ;
}
if ( ! F_3 ( & V_166 -> V_256 ) )
return 1 ;
}
return 0 ;
}
static void F_47 ( struct V_18 * V_19 , int V_169 , int V_257 )
{
struct V_84 * V_85 = F_54 ( V_19 ) ;
if ( V_169 & V_66 ) {
F_148 ( V_257 , & V_19 -> V_254 ) ;
F_148 ( V_257 , & V_85 -> V_258 ) ;
F_7 ( F_15 ( & V_19 -> V_254 ) >= 0 ) ;
} else {
F_148 ( V_257 , & V_19 -> V_255 ) ;
F_148 ( V_257 , & V_85 -> V_259 ) ;
F_7 ( F_15 ( & V_19 -> V_255 ) >= 0 ) ;
}
F_149 ( V_19 , L_32 , V_169 , V_257 ) ;
}
static int F_150 ( struct V_18 * V_19 )
{
return ! F_3 ( & V_19 -> V_250 ) ;
}
static void F_151 ( struct V_13 * V_260 , struct V_13 * V_14 , int V_261 )
{
if ( F_3 ( V_260 ) && V_261 )
F_141 ( V_260 , V_14 ) ;
else if ( ! F_3 ( V_260 ) && ! V_261 )
F_48 ( V_260 ) ;
}
static int F_152 ( struct V_84 * V_85 , struct V_18 * V_166 )
{
if ( F_150 ( V_166 ) ) {
F_151 ( & V_166 -> V_167 , & V_85 -> V_262 , 0 ) ;
F_151 ( & V_166 -> V_168 , & V_85 -> V_263 , 1 ) ;
} else {
F_151 ( & V_166 -> V_168 , & V_85 -> V_263 , 0 ) ;
F_151 ( & V_166 -> V_167 , & V_85 -> V_262 ,
F_147 ( V_85 , V_166 , V_66 ) ||
F_147 ( V_85 , V_166 , V_180 ) ) ;
}
F_151 ( & V_166 -> V_264 , & V_85 -> V_265 ,
F_15 ( & V_166 -> V_254 ) > 0 ) ;
F_151 ( & V_166 -> V_266 , & V_85 -> V_267 ,
F_15 ( & V_166 -> V_255 ) > 0 ) ;
return F_110 ( V_166 ) ;
}
static int F_153 ( struct V_84 * V_85 , struct V_18 * V_166 )
{
int V_268 ;
F_131 ( & V_85 -> V_210 ) ;
V_268 = F_152 ( V_85 , V_166 ) ;
F_133 ( & V_85 -> V_210 ) ;
return V_268 ;
}
static void F_154 ( struct V_269 * V_270 , T_3 V_271 ,
int V_26 )
{
if ( V_26 ) {
if ( ! V_270 -> V_272 )
V_270 -> V_272 = V_26 ;
V_270 -> V_239 = 1 ;
V_270 -> V_273 = F_155 () ;
return;
}
if ( V_270 -> V_239 && ( V_271 >= V_270 -> V_273 ) )
V_270 -> V_239 = 0 ;
}
static void F_78 ( const struct V_59 * V_60 , struct V_84 * V_85 ,
struct V_23 * V_24 , int V_103 , int V_26 )
{
struct V_18 * V_166 = V_24 -> V_233 ;
struct V_234 * V_235 = V_166 -> V_236 ;
T_3 V_271 = 0 ;
if ( V_24 -> V_274 != NULL ) {
V_271 = F_156 ( V_24 -> V_274 ) ;
F_157 ( V_24 -> V_274 ) ;
V_24 -> V_274 = NULL ;
}
F_104 ( & V_24 -> V_157 ) ;
V_24 -> V_155 = 0 ;
F_105 ( & V_24 -> V_157 ) ;
V_24 -> V_275 = 0 ;
if ( V_24 -> V_276 & V_66 && V_271 > 0 ) {
F_131 ( & V_85 -> V_210 ) ;
F_154 ( & V_85 -> V_238 , V_271 , V_26 ) ;
F_154 ( & V_235 -> V_240 , V_271 , V_26 ) ;
F_133 ( & V_85 -> V_210 ) ;
}
V_26 = F_118 ( V_60 , V_24 , V_24 -> V_276 , V_26 ) ;
if ( V_26 )
F_158 ( L_33 ,
V_24 , V_166 , V_26 ) ;
}
static int F_159 ( struct V_84 * V_85 ,
struct V_1 * V_2 , struct V_13 * V_277 ,
int * V_278 , unsigned int * V_92 )
{
struct V_1 * V_52 ;
struct V_23 * V_24 = F_160 ( & V_2 -> V_34 ,
struct V_23 ,
V_116 ) ;
F_71 ( ( V_2 -> V_28 == V_36 || V_2 -> V_28 == V_279 ) ,
V_2 ) ;
* V_92 = F_56 ( V_2 -> V_47 , * V_92 ) ;
if ( * V_278 + V_2 -> V_33 > * V_92 )
return 0 ;
F_16 (tmp, rpclist, oe_link) {
struct V_23 * V_280 ;
V_280 = F_160 ( & V_52 -> V_34 , struct V_23 ,
V_116 ) ;
F_71 ( V_52 -> V_154 == V_147 , V_52 ) ;
if ( F_17 ( V_24 ) -> V_281 != F_17 ( V_280 ) -> V_281 ) {
F_109 ( V_67 , L_34
L_35 ) ;
return 0 ;
}
if ( V_52 -> V_7 != V_2 -> V_7 ||
! V_52 -> V_37 != ! V_2 -> V_37 )
return 0 ;
break;
}
* V_278 += V_2 -> V_33 ;
F_61 ( & V_2 -> V_58 , V_277 ) ;
V_2 -> V_154 = V_147 ;
return 1 ;
}
static int F_161 ( struct V_18 * V_19 , struct V_13 * V_277 )
{
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
int V_25 = 0 ;
unsigned int V_92 = V_85 -> V_98 ;
F_7 ( F_14 ( V_19 ) ) ;
while ( ! F_3 ( & V_19 -> V_250 ) ) {
V_2 = F_143 ( V_19 -> V_250 . V_160 , struct V_1 ,
V_58 ) ;
F_7 ( V_2 -> V_28 == V_36 ) ;
if ( ! F_159 ( V_85 , V_2 , V_277 , & V_25 ,
& V_92 ) )
return V_25 ;
F_71 ( V_2 -> V_33 <= V_92 , V_2 ) ;
}
if ( V_25 == V_92 )
return V_25 ;
while ( ! F_3 ( & V_19 -> V_80 ) ) {
V_2 = F_143 ( V_19 -> V_80 . V_160 ,
struct V_1 , V_58 ) ;
if ( ! F_159 ( V_85 , V_2 , V_277 , & V_25 ,
& V_92 ) )
return V_25 ;
if ( ! V_2 -> V_6 )
continue;
while ( ( V_2 = F_6 ( V_2 ) ) != NULL ) {
if ( ( V_2 -> V_28 != V_36 ) ||
( ! F_3 ( & V_2 -> V_58 ) &&
V_2 -> V_154 != NULL ) )
continue;
if ( ! F_159 ( V_85 , V_2 , V_277 ,
& V_25 , & V_92 ) )
return V_25 ;
}
}
if ( V_25 == V_92 )
return V_25 ;
V_2 = F_11 ( V_19 ) ;
while ( V_2 != NULL ) {
if ( ( V_2 -> V_28 != V_36 ) ||
( ! F_3 ( & V_2 -> V_58 ) && V_2 -> V_154 != NULL ) ) {
V_2 = F_6 ( V_2 ) ;
continue;
}
if ( ! F_159 ( V_85 , V_2 , V_277 , & V_25 ,
& V_92 ) )
return V_25 ;
V_2 = F_6 ( V_2 ) ;
}
return V_25 ;
}
static int
F_162 ( const struct V_59 * V_60 , struct V_84 * V_85 ,
struct V_18 * V_166 )
{
F_163 ( V_277 ) ;
struct V_1 * V_2 ;
struct V_1 * V_52 ;
struct V_1 * V_282 = NULL ;
T_4 V_25 = 0 ;
int V_186 = 0 ;
int V_26 = 0 ;
F_7 ( F_14 ( V_166 ) ) ;
V_25 = F_161 ( V_166 , & V_277 ) ;
F_7 ( F_120 ( V_25 == 0 , F_3 ( & V_277 ) ) ) ;
if ( F_3 ( & V_277 ) )
return 0 ;
F_47 ( V_166 , V_66 , - V_25 ) ;
F_16 (ext, &rpclist, oe_link) {
F_7 ( V_2 -> V_28 == V_36 ||
V_2 -> V_28 == V_279 ) ;
if ( V_2 -> V_28 == V_36 )
F_20 ( V_2 , V_153 ) ;
else
F_20 ( V_2 , V_114 ) ;
}
F_52 ( V_166 ) ;
F_77 (ext, tmp, &rpclist, oe_link) {
if ( V_2 -> V_28 == V_153 ) {
V_26 = F_102 ( V_60 , V_2 ) ;
if ( F_164 ( V_26 < 0 ) ) {
F_48 ( & V_2 -> V_58 ) ;
F_75 ( V_60 , V_2 , 0 , V_26 ) ;
continue;
}
}
if ( V_282 == NULL ) {
V_282 = V_2 ;
V_186 = V_2 -> V_7 ;
} else {
F_7 ( V_186 == V_2 -> V_7 ) ;
}
}
if ( ! F_3 ( & V_277 ) ) {
F_7 ( V_25 > 0 ) ;
V_26 = F_165 ( V_60 , V_85 , & V_277 , V_66 ) ;
F_7 ( F_3 ( & V_277 ) ) ;
}
F_51 ( V_166 ) ;
return V_26 ;
}
static int
F_166 ( const struct V_59 * V_60 , struct V_84 * V_85 ,
struct V_18 * V_166 )
{
struct V_1 * V_2 ;
struct V_1 * V_160 ;
F_163 ( V_277 ) ;
int V_25 = 0 ;
unsigned int V_92 = V_85 -> V_98 ;
int V_26 = 0 ;
F_7 ( F_14 ( V_166 ) ) ;
F_77 (ext, next,
&osc->oo_reading_exts, oe_link) {
F_71 ( V_2 -> V_28 == V_279 , V_2 ) ;
if ( ! F_159 ( V_85 , V_2 , & V_277 , & V_25 ,
& V_92 ) )
break;
F_20 ( V_2 , V_114 ) ;
F_71 ( V_2 -> V_33 <= V_92 , V_2 ) ;
}
F_7 ( V_25 <= V_92 ) ;
F_47 ( V_166 , V_180 , - V_25 ) ;
if ( ! F_3 ( & V_277 ) ) {
F_52 ( V_166 ) ;
F_7 ( V_25 > 0 ) ;
V_26 = F_165 ( V_60 , V_85 , & V_277 , V_180 ) ;
F_7 ( F_3 ( & V_277 ) ) ;
F_51 ( V_166 ) ;
}
return V_26 ;
}
static struct V_18 * F_167 ( struct V_84 * V_85 )
{
if ( ! F_3 ( & V_85 -> V_263 ) )
return F_168 ( & V_85 -> V_263 , V_283 ) ;
if ( ! F_3 ( & V_85 -> V_262 ) )
return F_168 ( & V_85 -> V_262 , V_284 ) ;
if ( ! F_3 ( & V_85 -> V_245 ) &&
! F_3 ( & V_85 -> V_265 ) )
return F_168 ( & V_85 -> V_265 , V_285 ) ;
if ( V_85 -> V_107 == NULL || V_85 -> V_107 -> V_253 ) {
if ( ! F_3 ( & V_85 -> V_265 ) )
return F_168 ( & V_85 -> V_265 , V_285 ) ;
if ( ! F_3 ( & V_85 -> V_267 ) )
return F_168 ( & V_85 -> V_267 , V_286 ) ;
}
return NULL ;
}
static void F_169 ( const struct V_59 * V_60 , struct V_84 * V_85 )
{
struct V_18 * V_166 ;
int V_26 = 0 ;
while ( ( V_166 = F_167 ( V_85 ) ) != NULL ) {
struct V_175 * V_19 = F_67 ( V_166 ) ;
struct V_287 V_288 ;
F_149 ( V_166 , L_36 , F_146 ( V_85 ) ) ;
if ( F_145 ( V_85 , V_166 ) ) {
F_152 ( V_85 , V_166 ) ;
break;
}
F_170 ( V_19 ) ;
F_133 ( & V_85 -> V_210 ) ;
F_171 ( & V_19 -> V_200 , & V_288 , L_37 ,
V_147 ) ;
F_51 ( V_166 ) ;
if ( F_147 ( V_85 , V_166 , V_66 ) ) {
V_26 = F_162 ( V_60 , V_85 , V_166 ) ;
if ( V_26 < 0 ) {
F_158 ( L_38 , V_26 ) ;
}
}
if ( F_147 ( V_85 , V_166 , V_180 ) ) {
V_26 = F_166 ( V_60 , V_85 , V_166 ) ;
if ( V_26 < 0 )
F_158 ( L_39 , V_26 ) ;
}
F_52 ( V_166 ) ;
F_153 ( V_85 , V_166 ) ;
F_172 ( & V_19 -> V_200 , & V_288 , L_37 ,
V_147 ) ;
F_173 ( V_60 , V_19 ) ;
F_131 ( & V_85 -> V_210 ) ;
}
}
static int F_174 ( const struct V_59 * V_60 , struct V_84 * V_85 ,
struct V_18 * V_166 , int V_289 )
{
int V_26 = 0 ;
if ( V_166 != NULL && F_153 ( V_85 , V_166 ) == 0 )
return 0 ;
if ( ! V_289 ) {
F_31 ( & V_85 -> V_290 ) ;
F_131 ( & V_85 -> V_210 ) ;
F_169 ( V_60 , V_85 ) ;
F_133 ( & V_85 -> V_210 ) ;
F_36 ( & V_85 -> V_290 ) ;
} else {
F_109 ( V_67 , L_40 , V_85 ) ;
F_7 ( V_85 -> V_291 != NULL ) ;
V_26 = F_175 ( V_85 -> V_291 ) ;
}
return V_26 ;
}
static int F_62 ( const struct V_59 * V_60 ,
struct V_84 * V_85 , struct V_18 * V_166 )
{
return F_174 ( V_60 , V_85 , V_166 , 1 ) ;
}
void F_176 ( const struct V_59 * V_60 , struct V_84 * V_85 ,
struct V_18 * V_166 )
{
( void ) F_174 ( V_60 , V_85 , V_166 , 0 ) ;
}
int F_177 ( struct V_18 * V_166 , struct V_170 * V_292 ,
struct V_145 * V_145 , T_2 V_120 )
{
struct V_293 * exp = F_84 ( V_166 ) ;
struct V_23 * V_24 = & V_292 -> V_294 ;
if ( ! V_145 )
return F_178 ( sizeof( * V_24 ) ) ;
V_24 -> V_295 = V_296 ;
V_24 -> V_297 = & exp -> V_130 -> V_298 . V_85 ;
V_24 -> V_233 = V_166 ;
V_24 -> V_299 = V_145 ;
V_24 -> V_117 = V_120 ;
F_7 ( ! ( V_120 & ~ V_122 ) ) ;
if ( ! F_179 ( exp ) && F_180 ( V_300 ) )
V_24 -> V_196 = V_187 ;
F_26 ( & V_24 -> V_116 ) ;
F_26 ( & V_24 -> V_115 ) ;
F_181 ( & V_24 -> V_157 ) ;
F_109 ( V_301 , L_41 ,
V_24 , V_145 , V_24 -> V_117 ) ;
return 0 ;
}
int F_182 ( const struct V_59 * V_60 , struct V_136 * V_137 ,
struct V_170 * V_292 )
{
struct V_302 * V_303 = F_183 ( V_60 ) ;
struct V_1 * V_2 = NULL ;
struct V_23 * V_24 = & V_292 -> V_294 ;
struct V_84 * V_85 = V_24 -> V_297 ;
struct V_18 * V_166 = V_24 -> V_233 ;
T_1 V_49 ;
int V_83 = 0 ;
int V_304 = V_305 ;
int V_169 = V_66 ;
int V_306 = 0 ;
int V_26 = 0 ;
if ( V_24 -> V_295 != V_296 )
return - V_73 ;
if ( V_85 -> V_107 == NULL || V_85 -> V_107 -> V_253 )
return - V_307 ;
if ( ! F_3 ( & V_24 -> V_116 ) ||
! F_3 ( & V_24 -> V_115 ) )
return - V_74 ;
V_304 |= V_292 -> V_308 ? V_197 : 0 ;
if ( ! F_179 ( F_84 ( V_166 ) ) &&
F_180 ( V_300 ) ) {
V_304 |= V_187 ;
V_169 |= V_187 ;
}
if ( ! ( V_169 & V_187 ) ) {
struct V_175 * V_19 ;
struct V_176 * V_177 ;
unsigned int V_309 [ V_310 ] ;
V_19 = F_89 ( & V_166 -> V_311 ) ;
V_177 = & F_88 ( V_60 ) -> V_178 ;
F_114 ( V_19 ) ;
V_26 = F_115 ( V_60 , V_19 , V_177 ) ;
F_116 ( V_19 ) ;
V_309 [ V_312 ] = V_177 -> V_313 ;
V_309 [ V_314 ] = V_177 -> V_315 ;
if ( V_26 == 0 && F_184 ( V_85 , V_309 ) == V_316 )
V_26 = - V_219 ;
if ( V_26 )
return V_26 ;
}
V_24 -> V_276 = V_169 ;
V_24 -> V_121 = V_292 -> V_317 ;
V_24 -> V_118 = V_292 -> V_318 - V_292 -> V_317 ;
V_24 -> V_155 = 0 ;
V_24 -> V_196 = V_304 ;
F_149 ( V_166 , L_42 ,
V_24 , V_24 -> V_299 , V_24 -> V_276 & V_319 ) ;
V_49 = F_17 ( V_24 ) -> V_50 ;
V_2 = V_303 -> V_320 ;
if ( V_2 != NULL && V_2 -> V_40 <= V_49 && V_2 -> V_38 >= V_49 ) {
V_83 = ( 1 << V_85 -> V_76 ) + V_85 -> V_99 ;
if ( V_2 -> V_39 >= V_49 )
V_83 = 0 ;
F_131 ( & V_85 -> V_210 ) ;
V_26 = F_136 ( V_85 , V_24 , V_83 , 0 ) ;
F_133 ( & V_85 -> V_210 ) ;
if ( V_26 == 0 ) {
V_83 = 0 ;
V_306 = 1 ;
} else if ( V_2 -> V_39 < V_49 ) {
int V_52 = V_83 ;
V_26 = F_107 ( V_2 , V_49 , & V_52 ) ;
if ( V_26 < 0 ) {
V_306 = 1 ;
} else {
F_18 ( V_67 , V_2 ,
L_43 , V_49 ) ;
F_130 ( V_85 , V_83 , V_52 ) ;
V_83 = 0 ;
}
}
V_26 = 0 ;
} else if ( V_2 != NULL ) {
V_306 = 1 ;
}
if ( V_306 ) {
F_58 ( V_60 , V_2 ) ;
V_303 -> V_320 = NULL ;
V_2 = NULL ;
}
if ( V_2 == NULL ) {
int V_52 = ( 1 << V_85 -> V_76 ) + V_85 -> V_99 ;
F_7 ( V_303 -> V_320 == NULL ) ;
F_7 ( F_76 ( V_83 > 0 , V_83 >= V_52 ) ) ;
V_26 = 0 ;
if ( V_83 == 0 ) {
V_26 = F_139 ( V_60 , V_85 , V_24 , V_52 ) ;
if ( V_26 == 0 )
V_83 = V_52 ;
}
V_52 = V_83 ;
if ( V_26 == 0 ) {
V_2 = F_64 ( V_60 , V_166 , V_49 , & V_52 ) ;
if ( F_73 ( V_2 ) ) {
F_7 ( V_52 == V_83 ) ;
F_135 ( V_85 , V_24 ) ;
V_26 = F_185 ( V_2 ) ;
V_2 = NULL ;
} else {
V_303 -> V_320 = V_2 ;
}
}
if ( V_83 > 0 )
F_130 ( V_85 , V_83 , V_52 ) ;
}
F_7 ( F_76 ( V_26 == 0 , V_2 != NULL ) ) ;
if ( V_2 != NULL ) {
F_40 ( V_2 -> V_39 >= V_49 && V_2 -> V_40 <= V_49 ,
V_2 , L_44 , V_49 ) ;
F_7 ( ( V_24 -> V_196 & V_212 ) != 0 ) ;
F_51 ( V_166 ) ;
if ( V_2 -> V_33 == 0 )
V_2 -> V_7 = V_292 -> V_308 ;
else
F_7 ( V_2 -> V_7 == V_292 -> V_308 ) ;
++ V_2 -> V_33 ;
F_141 ( & V_24 -> V_116 , & V_2 -> V_34 ) ;
F_52 ( V_166 ) ;
}
return V_26 ;
}
int F_186 ( const struct V_59 * V_60 ,
struct V_18 * V_19 , struct V_170 * V_292 )
{
struct V_23 * V_24 = & V_292 -> V_294 ;
struct V_1 * V_2 = NULL ;
int V_26 = 0 ;
F_7 ( V_24 -> V_295 == V_296 ) ;
F_109 ( V_301 , L_45 ,
V_24 , V_292 , F_17 ( V_24 ) -> V_50 ) ;
F_51 ( V_19 ) ;
if ( ! F_3 ( & V_24 -> V_115 ) ) {
F_109 ( V_67 , L_46 , V_24 ) ;
V_26 = - V_74 ;
} else if ( ! F_3 ( & V_24 -> V_116 ) ) {
V_2 = F_38 ( V_19 , F_17 ( V_24 ) -> V_50 ) ;
if ( V_2 != NULL && V_2 -> V_28 != V_79 ) {
F_18 ( V_51 , V_2 , L_47 ,
F_17 ( V_24 ) -> V_50 ) ;
V_26 = - V_74 ;
}
}
F_52 ( V_19 ) ;
if ( V_2 != NULL )
F_32 ( V_60 , V_2 ) ;
return V_26 ;
}
int F_187 ( const struct V_59 * V_60 , struct V_136 * V_137 ,
struct V_170 * V_292 )
{
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 = F_119 ( V_292 -> V_181 . V_182 ) ;
struct V_143 * V_321 = V_292 -> V_181 . V_322 ;
T_1 V_49 = V_321 -> V_50 ;
struct V_23 * V_24 = & V_292 -> V_294 ;
bool V_323 = false ;
int V_26 = 0 ;
F_51 ( V_19 ) ;
V_2 = F_38 ( V_19 , V_49 ) ;
if ( V_2 == NULL ) {
F_72 ( V_51 , V_19 ) ;
F_69 ( 0 , L_48 , V_49 ) ;
}
switch ( V_2 -> V_28 ) {
case V_114 :
case V_279 :
F_188 ( V_51 , V_60 , F_91 ( V_321 ) ,
L_49 ) ;
F_7 ( 0 ) ;
break;
case V_153 :
case V_79 :
case V_35 :
V_26 = - V_163 ;
goto V_27;
default:
break;
}
V_26 = F_189 ( V_60 , V_137 , F_91 ( V_321 ) , V_173 ) ;
if ( V_26 )
goto V_27;
F_104 ( & V_24 -> V_157 ) ;
V_24 -> V_155 |= V_156 | V_324 ;
F_105 ( & V_24 -> V_157 ) ;
if ( F_190 () )
V_2 -> V_10 = 1 ;
V_2 -> V_9 = 1 ;
if ( V_2 -> V_28 == V_36 ) {
F_18 ( V_67 , V_2 ,
L_50 , V_24 ) ;
if ( F_3 ( & V_2 -> V_58 ) )
F_141 ( & V_2 -> V_58 , & V_19 -> V_80 ) ;
V_323 = true ;
}
V_26 = 0 ;
V_27:
F_52 ( V_19 ) ;
F_32 ( V_60 , V_2 ) ;
if ( V_323 )
F_62 ( V_60 , F_54 ( V_19 ) , V_19 ) ;
return V_26 ;
}
int F_191 ( const struct V_59 * V_60 , struct V_170 * V_292 )
{
struct V_23 * V_24 = & V_292 -> V_294 ;
struct V_18 * V_19 = V_24 -> V_233 ;
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_1 * V_89 = NULL ;
struct V_13 * V_325 ;
T_1 V_49 = F_17 ( V_24 ) -> V_50 ;
int V_26 = - V_74 ;
int V_169 ;
F_7 ( ! V_24 -> V_275 ) ;
V_24 -> V_275 = 1 ;
F_51 ( V_19 ) ;
if ( V_24 -> V_276 & V_66 ) {
V_325 = & V_19 -> V_80 ;
V_169 = V_66 ;
} else {
V_325 = & V_19 -> V_256 ;
V_169 = V_180 ;
}
F_16 (ext, plist, oe_link) {
if ( V_2 -> V_40 <= V_49 && V_2 -> V_39 >= V_49 ) {
F_7 ( V_2 -> V_28 == V_279 ) ;
V_89 = F_30 ( V_2 ) ;
break;
}
}
if ( V_89 != NULL ) {
F_48 ( & V_89 -> V_58 ) ;
F_47 ( V_19 , V_169 , - V_89 -> V_33 ) ;
F_52 ( V_19 ) ;
F_75 ( V_60 , V_89 , 0 , - V_326 ) ;
F_32 ( V_60 , V_89 ) ;
V_26 = 0 ;
} else {
F_52 ( V_19 ) ;
if ( V_24 -> V_274 != NULL ) {
F_192 ( V_24 -> V_274 ) ;
F_193 ( V_24 -> V_274 ) ;
F_157 ( V_24 -> V_274 ) ;
V_24 -> V_274 = NULL ;
}
}
F_153 ( V_85 , V_19 ) ;
return V_26 ;
}
int F_194 ( const struct V_59 * V_60 , struct V_18 * V_19 ,
struct V_13 * V_14 , int V_169 , int V_304 )
{
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_23 * V_24 , * V_52 ;
int V_25 = 0 ;
int V_327 = V_85 -> V_98 ;
T_1 V_328 = V_329 ;
T_1 V_124 = 0 ;
F_16 (oap, list, oap_pending_item) {
struct V_143 * V_321 = F_17 ( V_24 ) ;
if ( V_321 -> V_50 > V_124 )
V_124 = V_321 -> V_50 ;
if ( V_321 -> V_50 < V_328 )
V_328 = V_321 -> V_50 ;
++ V_25 ;
V_327 <<= ( V_25 > V_327 ) ;
}
V_2 = F_22 ( V_19 ) ;
if ( V_2 == NULL ) {
F_77 (oap, tmp, list, oap_pending_item) {
F_48 ( & V_24 -> V_116 ) ;
F_78 ( V_60 , V_85 , V_24 , 0 , - V_95 ) ;
}
return - V_95 ;
}
V_2 -> V_5 = ! ! ( V_169 & V_180 ) ;
V_2 -> V_9 = 1 ;
V_2 -> V_40 = V_328 ;
V_2 -> V_39 = V_2 -> V_38 = V_124 ;
V_2 -> V_22 = V_19 ;
V_2 -> V_7 = ! ! ( V_304 & V_197 ) ;
V_2 -> V_33 = V_25 ;
V_2 -> V_47 = V_327 ;
F_57 ( V_14 , & V_2 -> V_34 ) ;
F_51 ( V_19 ) ;
F_20 ( V_2 , V_279 ) ;
if ( V_169 & V_66 ) {
F_141 ( & V_2 -> V_58 , & V_19 -> V_80 ) ;
F_47 ( V_19 , V_66 , V_25 ) ;
} else {
F_141 ( & V_2 -> V_58 , & V_19 -> V_256 ) ;
F_47 ( V_19 , V_180 , V_25 ) ;
}
F_52 ( V_19 ) ;
F_62 ( V_60 , V_85 , V_19 ) ;
return 0 ;
}
int F_195 ( const struct V_59 * V_60 , struct V_302 * V_303 ,
struct V_18 * V_19 , T_3 V_330 )
{
struct V_84 * V_85 = F_54 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_1 * V_331 = NULL ;
T_1 V_49 ;
F_163 ( V_14 ) ;
int V_172 = 0 ;
bool V_133 ;
V_49 = F_196 ( F_67 ( V_19 ) , V_330 ) ;
V_133 = V_330 > F_117 ( F_67 ( V_19 ) , V_49 ) ;
V_332:
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_49 ) ;
if ( V_2 == NULL )
V_2 = F_11 ( V_19 ) ;
else if ( V_2 -> V_39 < V_49 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 != NULL ) {
F_71 ( V_2 -> V_28 != V_79 , V_2 ) ;
if ( V_2 -> V_28 > V_36 || V_2 -> V_9 ) {
F_7 ( ! V_2 -> V_8 ) ;
F_18 ( V_67 , V_2 ,
L_51 ) ;
V_331 = F_30 ( V_2 ) ;
break;
}
F_18 ( V_67 , V_2 , L_52 , V_330 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_28 == V_35 ) {
F_7 ( ! V_2 -> V_11 ) ;
V_2 -> V_11 = 1 ;
} else {
F_71 ( V_2 -> V_28 == V_36 , V_2 ) ;
F_20 ( V_2 , V_79 ) ;
F_47 ( V_19 , V_66 ,
- V_2 -> V_33 ) ;
}
F_71 ( F_3 ( & V_2 -> V_58 ) , V_2 ) ;
F_141 ( & V_2 -> V_58 , & V_14 ) ;
V_2 = F_6 ( V_2 ) ;
}
F_52 ( V_19 ) ;
F_153 ( V_85 , V_19 ) ;
while ( ! F_3 ( & V_14 ) ) {
int V_26 ;
V_2 = F_143 ( V_14 . V_160 , struct V_1 , V_58 ) ;
F_48 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_28 != V_79 )
F_74 ( V_60 , V_2 , V_79 ) ;
V_26 = F_86 ( V_2 , V_49 , V_133 ) ;
if ( V_26 < 0 ) {
if ( V_172 == 0 )
V_172 = V_26 ;
F_18 ( V_51 , V_2 ,
L_53 , V_26 ) ;
} else if ( V_2 -> V_33 == 0 ) {
F_50 ( V_2 ) ;
} else {
F_40 ( V_2 -> V_40 <= V_49 , V_2 ,
L_54 , V_49 , V_133 ) ;
V_49 = V_2 -> V_39 + 1 ;
V_133 = false ;
F_7 ( V_303 -> V_333 == NULL ) ;
V_303 -> V_333 = F_30 ( V_2 ) ;
F_18 ( V_67 , V_2 ,
L_55 , V_330 ) ;
}
F_32 ( V_60 , V_2 ) ;
}
if ( V_331 != NULL ) {
int V_26 ;
V_26 = F_74 ( V_60 , V_331 , V_32 ) ;
if ( V_26 < 0 )
F_18 ( V_67 , V_331 , L_56 , V_26 ) ;
F_32 ( V_60 , V_331 ) ;
V_331 = NULL ;
goto V_332;
}
return V_172 ;
}
void F_197 ( const struct V_59 * V_60 , struct V_302 * V_303 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_303 -> V_333 ;
V_303 -> V_333 = NULL ;
if ( V_2 != NULL ) {
bool V_323 = false ;
F_71 ( V_2 -> V_33 > 0 , V_2 ) ;
F_71 ( V_2 -> V_28 == V_79 , V_2 ) ;
F_71 ( ! V_2 -> V_9 , V_2 ) ;
F_18 ( V_67 , V_2 , L_57 ) ;
F_51 ( V_19 ) ;
F_20 ( V_2 , V_36 ) ;
if ( V_2 -> V_12 && ! V_2 -> V_9 ) {
V_2 -> V_9 = 1 ;
F_61 ( & V_2 -> V_58 , & V_19 -> V_80 ) ;
V_323 = true ;
}
F_47 ( V_19 , V_66 , V_2 -> V_33 ) ;
F_52 ( V_19 ) ;
F_32 ( V_60 , V_2 ) ;
if ( V_323 )
F_62 ( V_60 , F_54 ( V_19 ) , V_19 ) ;
}
}
int F_198 ( const struct V_59 * V_60 , struct V_18 * V_19 ,
T_1 V_328 , T_1 V_124 )
{
struct V_1 * V_2 ;
T_1 V_49 = V_328 ;
int V_172 = 0 ;
V_332:
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_49 ) ;
if ( V_2 == NULL )
V_2 = F_11 ( V_19 ) ;
else if ( V_2 -> V_39 < V_49 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 != NULL ) {
int V_26 ;
if ( V_2 -> V_40 > V_124 )
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
V_26 = F_74 ( V_60 , V_2 , V_32 ) ;
if ( V_172 == 0 )
V_172 = V_26 ;
F_32 ( V_60 , V_2 ) ;
goto V_332;
}
F_52 ( V_19 ) ;
F_149 ( V_19 , L_58 ) ;
return V_172 ;
}
int F_199 ( const struct V_59 * V_60 , struct V_18 * V_19 ,
T_1 V_328 , T_1 V_124 , int V_334 , int V_335 )
{
struct V_1 * V_2 ;
F_163 ( V_336 ) ;
bool V_323 = false ;
int V_172 = 0 ;
F_51 ( V_19 ) ;
V_2 = F_37 ( V_19 , V_328 ) ;
if ( V_2 == NULL )
V_2 = F_11 ( V_19 ) ;
else if ( V_2 -> V_39 < V_328 )
V_2 = F_6 ( V_2 ) ;
while ( V_2 != NULL ) {
if ( V_2 -> V_40 > V_124 )
break;
V_2 -> V_12 = 1 ;
switch ( V_2 -> V_28 ) {
case V_36 :
V_172 += V_2 -> V_33 ;
if ( ! V_335 ) {
struct V_13 * V_14 = NULL ;
if ( V_334 ) {
F_71 ( ! V_2 -> V_8 , V_2 ) ;
V_2 -> V_8 = 1 ;
V_14 = & V_19 -> V_250 ;
} else if ( ! V_2 -> V_9 ) {
V_2 -> V_9 = 1 ;
V_14 = & V_19 -> V_80 ;
}
if ( V_14 != NULL )
F_61 ( & V_2 -> V_58 , V_14 ) ;
V_323 = true ;
} else {
F_71 ( V_2 -> V_40 >= V_328 &&
V_2 -> V_38 <= V_124 , V_2 ) ;
F_20 ( V_2 , V_153 ) ;
V_2 -> V_154 = V_147 ;
F_61 ( & V_2 -> V_58 ,
& V_336 ) ;
F_47 ( V_19 , V_66 ,
- V_2 -> V_33 ) ;
}
break;
case V_35 :
F_7 ( V_334 == 0 && V_335 == 0 ) ;
V_2 -> V_9 = 1 ;
break;
case V_79 :
default:
break;
}
V_2 = F_6 ( V_2 ) ;
}
F_52 ( V_19 ) ;
F_7 ( F_76 ( ! V_335 , F_3 ( & V_336 ) ) ) ;
if ( ! F_3 ( & V_336 ) ) {
struct V_1 * V_52 ;
int V_26 ;
F_153 ( F_54 ( V_19 ) , V_19 ) ;
F_77 (ext, tmp, &discard_list, oe_link) {
F_48 ( & V_2 -> V_58 ) ;
F_71 ( V_2 -> V_28 == V_153 , V_2 ) ;
V_26 = F_102 ( V_60 , V_2 ) ;
if ( F_164 ( V_26 < 0 ) ) {
F_18 ( V_51 , V_2 ,
L_59 , V_26 ) ;
if ( V_172 >= 0 )
V_172 = V_26 ;
}
F_75 ( V_60 , V_2 , 0 , 0 ) ;
}
}
if ( V_323 )
F_176 ( V_60 , F_54 ( V_19 ) , V_19 ) ;
if ( V_334 || V_335 ) {
int V_26 ;
V_26 = F_198 ( V_60 , V_19 , V_328 , V_124 ) ;
if ( V_172 >= 0 && V_26 < 0 )
V_172 = V_26 ;
}
F_149 ( V_19 , L_60 ) ;
return V_172 ;
}
