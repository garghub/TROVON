static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_1 ;
struct V_9 * V_10 ;
F_2 ( F_3 ( V_2 ) ) ;
F_2 ( ! F_4 ( V_2 ) ) ;
if ( V_3 == 0 && V_4 == V_11 ) {
V_7 = F_5 () ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_5 = V_2 -> V_12 -> V_13 ;
V_10 = F_7 ( V_5 ) -> V_14 ;
if ( V_10 ) {
V_1 = F_8 ( V_2 , V_10 ) ;
if ( V_1 ) {
F_9 ( V_7 , V_1 ) ;
F_10 ( V_7 , V_1 ) ;
}
} else {
F_2 ( V_2 -> V_15 == 0 ) ;
}
F_11 ( V_7 ) ;
}
}
static int F_12 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_8 * V_1 ;
struct V_17 * V_12 ;
int V_18 = 0 ;
F_2 ( F_3 ( V_2 ) ) ;
if ( F_4 ( V_2 ) || F_13 ( V_2 ) )
return 0 ;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return 1 ;
V_10 = F_7 ( V_12 -> V_13 ) -> V_14 ;
if ( ! V_10 )
return 1 ;
if ( F_14 ( V_2 ) > 3 )
return 0 ;
V_1 = F_8 ( V_2 , V_10 ) ;
if ( ! V_1 )
return 1 ;
V_7 = F_5 () ;
F_2 ( ! F_6 ( V_7 ) ) ;
if ( ! F_15 ( V_1 ) ) {
V_18 = 1 ;
F_9 ( V_7 , V_1 ) ;
}
F_2 ( F_16 ( V_10 ) > 1 ) ;
F_10 ( V_7 , V_1 ) ;
F_11 ( V_7 ) ;
return V_18 ;
}
static void F_17 ( struct V_1 * * V_19 , int V_20 , int V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_21 )
F_18 ( V_19 [ V_22 ] ) ;
F_19 ( V_19 [ V_22 ] ) ;
}
F_20 ( V_19 ) ;
}
T_2 F_21 ( const struct V_6 * V_7 , struct V_23 * V_24 ,
int V_25 , struct V_5 * V_5 ,
struct V_26 * V_27 )
{
struct V_8 * V_28 ;
struct V_29 * V_30 ;
struct V_9 * V_10 = V_24 -> V_31 ;
int V_22 ;
T_2 V_32 = 0 ;
T_3 V_33 = V_27 -> V_34 ;
T_4 V_35 = V_27 -> V_36 ;
int F_14 = V_27 -> V_37 ;
struct V_1 * * V_19 = V_27 -> V_38 ;
T_4 V_39 = F_22 ( V_10 ) ;
bool V_40 ;
int V_41 = 0 ;
V_30 = & V_24 -> V_42 ;
F_23 ( V_30 ) ;
for ( V_22 = 0 ; V_22 < F_14 ; V_22 ++ ) {
if ( V_27 -> V_43 )
V_33 = V_27 -> V_43 [ V_22 ] ;
F_2 ( ! ( V_33 & ( V_39 - 1 ) ) ) ;
V_28 = F_24 ( V_7 , V_10 , F_25 ( V_10 , V_33 ) ,
V_27 -> V_38 [ V_22 ] , V_44 ) ;
if ( F_6 ( V_28 ) ) {
V_32 = F_26 ( V_28 ) ;
break;
}
V_32 = F_27 ( V_7 , V_24 , V_28 ) ;
if ( V_32 ) {
F_2 ( V_28 -> V_45 == V_46 ) ;
F_10 ( V_7 , V_28 ) ;
break;
}
V_40 = true ;
if ( V_28 -> V_47 == V_48 ) {
struct V_1 * V_2 = F_28 ( V_28 ) ;
struct V_1 * V_49 ;
struct V_1 * V_50 ;
void * V_51 ;
void * V_52 ;
V_49 = ( V_25 == V_53 ) ? V_19 [ V_22 ] : V_2 ;
V_50 = ( V_25 == V_53 ) ? V_2 : V_19 [ V_22 ] ;
V_51 = F_29 ( V_49 ) ;
V_52 = F_29 ( V_50 ) ;
memcpy ( V_52 , V_51 , F_30 ( V_39 , V_35 ) ) ;
F_31 ( V_52 ) ;
F_31 ( V_51 ) ;
if ( V_25 == V_53 )
F_32 ( V_2 ) ;
if ( V_25 == V_54 ) {
F_33 ( V_7 , V_24 , V_28 ) ;
V_40 = false ;
}
}
if ( F_34 ( V_40 ) ) {
F_35 ( & V_30 -> V_55 , V_28 ) ;
F_36 ( V_7 , V_28 , 0 , F_30 ( V_35 , V_39 ) ) ;
++ V_41 ;
}
F_10 ( V_7 , V_28 ) ;
V_35 -= V_39 ;
V_33 += V_39 ;
}
if ( V_32 == 0 && V_41 ) {
V_32 = F_37 ( V_7 , V_24 ,
V_25 == V_54 ? V_56 : V_57 ,
V_30 , 0 ) ;
}
if ( V_32 == 0 )
V_32 = V_27 -> V_36 ;
F_38 ( V_7 , V_24 , V_30 ) ;
F_39 ( V_7 , V_24 , V_30 ) ;
F_40 ( V_7 , V_30 ) ;
return V_32 ;
}
static T_2 F_41 ( const struct V_6 * V_7 , struct V_23 * V_24 ,
int V_25 , struct V_5 * V_5 ,
struct V_17 * V_12 ,
T_4 V_35 , T_3 V_33 ,
struct V_1 * * V_19 , int F_14 )
{
struct V_26 V_58 = {
. V_38 = V_19 ,
. V_37 = F_14 ,
. V_36 = V_35 ,
. V_43 = NULL ,
. V_34 = V_33
} ;
return F_21 ( V_7 , V_24 , V_25 , V_5 , & V_58 ) ;
}
static T_2 F_42 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_63 * V_64 ;
const struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_65 * V_65 = V_60 -> V_66 ;
struct V_5 * V_5 = V_65 -> V_67 -> V_13 ;
T_3 V_33 = V_60 -> V_68 ;
T_2 V_69 = F_43 ( V_62 ) ;
T_2 V_70 = 0 , V_18 = 0 ;
long V_35 = V_71 ;
if ( F_44 ( V_62 ) == V_54 && V_33 >= F_45 ( V_5 ) )
return 0 ;
if ( ( V_33 & ~ V_72 ) || ( V_69 & ~ V_72 ) )
return - V_73 ;
F_46 ( V_74 , L_1 V_75 L_2 ,
F_47 ( F_48 ( V_5 ) ) , V_5 , V_69 , V_71 ,
V_33 , V_33 , V_69 >> V_76 ,
V_71 >> V_76 ) ;
if ( F_49 ( V_62 ) & ~ V_72 )
return - V_73 ;
V_64 = F_50 ( V_65 ) ;
if ( ! V_64 )
return - V_77 ;
V_7 = V_64 -> V_78 ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_24 = V_64 -> V_79 ;
F_2 ( V_24 ) ;
while ( F_43 ( V_62 ) ) {
struct V_1 * * V_19 ;
T_4 V_80 ;
V_69 = F_51 ( T_4 , F_43 ( V_62 ) , V_35 ) ;
if ( F_44 ( V_62 ) == V_54 ) {
if ( V_33 >= F_45 ( V_5 ) )
break;
if ( V_33 + V_69 > F_45 ( V_5 ) )
V_69 = F_45 ( V_5 ) - V_33 ;
}
V_18 = F_52 ( V_62 , & V_19 , V_69 , & V_80 ) ;
if ( F_34 ( V_18 > 0 ) ) {
int V_81 = F_53 ( V_18 + V_80 , V_11 ) ;
V_18 = F_41 ( V_7 , V_24 , F_44 ( V_62 ) ,
V_5 , V_65 -> V_67 ,
V_18 , V_33 , V_19 ,
V_81 ) ;
F_17 ( V_19 , V_81 , F_44 ( V_62 ) == V_54 ) ;
}
if ( F_54 ( V_18 <= 0 ) ) {
if ( V_18 == - V_82 &&
V_35 > ( V_11 / sizeof( * V_19 ) ) *
V_11 ) {
V_35 = ( ( ( ( V_35 / 2 ) - 1 ) |
~ V_72 ) + 1 ) &
V_72 ;
F_46 ( V_74 , L_3 ,
V_35 ) ;
continue;
}
goto V_83;
}
F_55 ( V_62 , V_18 ) ;
V_70 += V_18 ;
V_33 += V_18 ;
}
V_83:
if ( V_70 > 0 ) {
struct V_84 * V_85 = F_56 ( V_7 ) ;
V_85 -> V_86 . V_87 . V_88 += V_70 ;
}
return V_70 ? V_70 : V_18 ;
}
static int F_57 ( const struct V_6 * V_7 , struct V_23 * V_24 ,
struct V_8 * V_89 )
{
struct V_90 * V_91 = F_58 ( V_7 ) ;
struct V_9 * V_10 = V_24 -> V_31 ;
struct V_92 * V_93 = F_59 ( V_10 , V_89 ) ;
T_3 V_3 = F_60 ( V_10 , F_61 ( V_93 ) ) ;
int V_18 ;
F_62 ( V_10 ) ;
V_18 = F_63 ( V_7 , V_10 , V_91 ) ;
F_64 ( V_10 ) ;
if ( V_18 == 0 ) {
if ( V_91 -> V_94 <= V_3 ) {
char * V_95 = F_29 ( V_93 -> V_96 ) ;
memset ( V_95 , 0 , F_22 ( V_10 ) ) ;
F_31 ( V_95 ) ;
} else if ( V_93 -> V_97 ) {
V_93 -> V_98 = 1 ;
} else {
V_18 = F_65 ( V_7 , V_24 , V_89 , V_56 ) ;
}
}
return V_18 ;
}
static int F_66 ( struct V_65 * V_65 , struct V_17 * V_12 ,
T_3 V_99 , unsigned int V_100 , unsigned int V_101 ,
struct V_1 * * V_102 , void * * V_103 )
{
struct V_63 * V_64 ;
const struct V_6 * V_7 = NULL ;
struct V_23 * V_24 ;
struct V_8 * V_1 = NULL ;
struct V_9 * V_104 = F_7 ( V_12 -> V_13 ) -> V_14 ;
T_5 V_105 = V_99 >> V_76 ;
struct V_1 * V_2 = NULL ;
unsigned int V_106 = V_99 & ( V_11 - 1 ) ;
unsigned int V_107 = V_106 + V_100 ;
int V_18 = 0 ;
F_46 ( V_74 , L_4 , V_105 , V_106 , V_100 ) ;
V_64 = F_50 ( V_65 ) ;
if ( ! V_64 ) {
V_24 = NULL ;
V_18 = - V_77 ;
goto V_83;
}
V_7 = V_64 -> V_78 ;
V_24 = V_64 -> V_79 ;
V_2 = F_67 ( V_12 , V_105 ) ;
if ( F_54 ( ! V_2 || F_13 ( V_2 ) || F_4 ( V_2 ) ) ) {
struct V_84 * V_85 = F_56 ( V_7 ) ;
struct V_108 * V_109 = & V_85 -> V_86 . V_87 . V_110 ;
if ( V_2 && V_109 -> V_111 > 0 ) {
F_68 ( V_2 ) ;
F_19 ( V_2 ) ;
V_2 = NULL ;
}
V_18 = F_69 ( V_7 , V_24 ) ;
if ( V_18 < 0 )
goto V_83;
if ( ! V_2 ) {
V_2 = F_70 ( V_12 , V_105 ,
V_101 ) ;
if ( ! V_2 ) {
V_18 = - V_82 ;
goto V_83;
}
}
}
V_1 = F_24 ( V_7 , V_104 , V_2 -> V_105 , V_2 , V_48 ) ;
if ( F_6 ( V_1 ) ) {
V_18 = F_26 ( V_1 ) ;
goto V_83;
}
V_64 -> V_112 = V_1 ;
F_71 ( & V_1 -> V_113 , L_5 , V_24 ) ;
F_72 ( V_7 , V_24 , V_1 ) ;
if ( ! F_73 ( V_2 ) ) {
if ( V_106 == 0 && V_107 == V_11 ) {
F_74 ( V_114 , V_7 , V_1 , L_6 ) ;
F_75 ( V_2 , 0x11 ) ;
} else {
V_18 = F_57 ( V_7 , V_24 , V_1 ) ;
if ( V_18 == 0 )
F_76 ( V_2 ) ;
}
}
if ( V_18 < 0 )
F_77 ( V_7 , V_24 , V_1 ) ;
V_83:
if ( V_18 < 0 ) {
if ( V_2 ) {
F_68 ( V_2 ) ;
F_19 ( V_2 ) ;
}
if ( ! F_78 ( V_1 ) ) {
F_79 ( & V_1 -> V_113 , L_5 , V_24 ) ;
F_10 ( V_7 , V_1 ) ;
}
if ( V_24 )
V_24 -> V_115 = V_18 ;
} else {
* V_102 = V_2 ;
* V_103 = V_64 ;
}
return V_18 ;
}
static int F_80 ( struct V_65 * V_65 , struct V_17 * V_12 ,
T_3 V_99 , unsigned int V_100 , unsigned int V_116 ,
struct V_1 * V_2 , void * V_103 )
{
struct V_63 * V_64 = V_103 ;
const struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_84 * V_85 ;
struct V_8 * V_1 ;
unsigned int V_106 = V_99 & ( V_11 - 1 ) ;
bool V_117 = false ;
int V_18 = 0 ;
F_19 ( V_2 ) ;
V_7 = V_64 -> V_78 ;
V_1 = V_64 -> V_112 ;
V_24 = V_64 -> V_79 ;
V_85 = F_56 ( V_7 ) ;
F_2 ( F_81 ( V_1 , V_24 ) ) ;
if ( V_116 > 0 ) {
struct V_108 * V_109 = & V_85 -> V_86 . V_87 . V_110 ;
V_64 -> V_112 = NULL ;
F_35 ( V_109 , V_1 ) ;
if ( V_109 -> V_111 == 1 )
V_85 -> V_86 . V_87 . V_118 = V_106 ;
else
F_2 ( V_106 == 0 ) ;
V_85 -> V_86 . V_87 . V_119 = V_106 + V_116 ;
if ( F_13 ( V_2 ) )
V_117 = true ;
if ( V_109 -> V_111 >= V_120 )
V_117 = true ;
F_82 ( V_74 , V_7 , V_1 ,
L_7 , V_109 -> V_111 ) ;
} else {
F_33 ( V_7 , V_24 , V_1 ) ;
V_64 -> V_112 = NULL ;
F_79 ( & V_1 -> V_113 , L_5 , V_24 ) ;
F_10 ( V_7 , V_1 ) ;
V_117 = true ;
}
if ( V_117 ||
V_65 -> V_121 & V_122 || F_83 ( F_84 ( V_65 ) ) )
V_18 = F_69 ( V_7 , V_24 ) ;
if ( V_18 < 0 )
V_24 -> V_115 = V_18 ;
return V_18 >= 0 ? V_116 : V_18 ;
}
static int F_85 ( struct V_17 * V_12 ,
struct V_1 * V_123 , struct V_1 * V_1 ,
enum V_124 V_125
)
{
return - V_77 ;
}
