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
static inline int F_17 ( int V_19 , unsigned long V_20 ,
T_2 V_21 , struct V_1 * * * V_22 ,
int * V_23 )
{
int V_18 = - V_24 ;
if ( V_21 > V_25 ) {
* V_22 = NULL ;
return - V_26 ;
}
* V_23 = ( V_20 + V_21 + V_11 - 1 ) >> V_27 ;
* V_23 -= V_20 >> V_27 ;
* V_22 = F_18 ( * V_23 * sizeof( * * V_22 ) , V_28 ) ;
if ( * V_22 ) {
V_18 = F_19 ( V_20 , * V_23 ,
( V_19 == V_29 ) , * V_22 ) ;
if ( F_20 ( V_18 <= 0 ) )
F_21 ( * V_22 ) ;
}
return V_18 ;
}
static void F_22 ( struct V_1 * * V_22 , int V_30 , int V_31 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ ) {
if ( V_31 )
F_23 ( V_22 [ V_32 ] ) ;
F_24 ( V_22 [ V_32 ] ) ;
}
F_21 ( V_22 ) ;
}
T_3 F_25 ( const struct V_6 * V_7 , struct V_33 * V_34 ,
int V_19 , struct V_5 * V_5 ,
struct V_35 * V_36 )
{
struct V_8 * V_37 ;
struct V_38 * V_39 ;
struct V_9 * V_10 = V_34 -> V_40 ;
int V_32 ;
T_3 V_41 = 0 ;
T_4 V_42 = V_36 -> V_43 ;
T_2 V_21 = V_36 -> V_44 ;
int F_14 = V_36 -> V_45 ;
struct V_1 * * V_22 = V_36 -> V_46 ;
T_2 V_47 = F_26 ( V_10 ) ;
bool V_48 ;
int V_49 = 0 ;
V_39 = & V_34 -> V_50 ;
F_27 ( V_39 ) ;
for ( V_32 = 0 ; V_32 < F_14 ; V_32 ++ ) {
if ( V_36 -> V_51 )
V_42 = V_36 -> V_51 [ V_32 ] ;
F_2 ( ! ( V_42 & ( V_47 - 1 ) ) ) ;
V_37 = F_28 ( V_7 , V_10 , F_29 ( V_10 , V_42 ) ,
V_36 -> V_46 [ V_32 ] , V_52 ) ;
if ( F_6 ( V_37 ) ) {
V_41 = F_30 ( V_37 ) ;
break;
}
V_41 = F_31 ( V_7 , V_34 , V_37 ) ;
if ( V_41 ) {
F_2 ( V_37 -> V_53 == V_54 ) ;
F_10 ( V_7 , V_37 ) ;
break;
}
V_48 = true ;
if ( V_37 -> V_55 == V_56 ) {
struct V_1 * V_2 = F_32 ( V_37 ) ;
struct V_1 * V_57 ;
struct V_1 * V_58 ;
void * V_59 ;
void * V_60 ;
V_57 = ( V_19 == V_61 ) ? V_22 [ V_32 ] : V_2 ;
V_58 = ( V_19 == V_61 ) ? V_2 : V_22 [ V_32 ] ;
V_59 = F_33 ( V_57 ) ;
V_60 = F_33 ( V_58 ) ;
memcpy ( V_60 , V_59 , F_34 ( V_47 , V_21 ) ) ;
F_35 ( V_60 ) ;
F_35 ( V_59 ) ;
if ( V_19 == V_61 )
F_36 ( V_2 ) ;
if ( V_19 == V_29 ) {
F_37 ( V_7 , V_34 , V_37 ) ;
V_48 = false ;
}
}
if ( F_38 ( V_48 ) ) {
F_39 ( & V_39 -> V_62 , V_37 ) ;
F_40 ( V_7 , V_37 , 0 , F_34 ( V_21 , V_47 ) ) ;
++ V_49 ;
}
F_10 ( V_7 , V_37 ) ;
V_21 -= V_47 ;
V_42 += V_47 ;
}
if ( V_41 == 0 && V_49 ) {
V_41 = F_41 ( V_7 , V_34 ,
V_19 == V_29 ? V_63 : V_64 ,
V_39 , 0 ) ;
}
if ( V_41 == 0 )
V_41 = V_36 -> V_44 ;
F_42 ( V_7 , V_34 , V_39 ) ;
F_43 ( V_7 , V_34 , V_39 ) ;
F_44 ( V_7 , V_39 ) ;
return V_41 ;
}
static T_3 F_45 ( const struct V_6 * V_7 , struct V_33 * V_34 ,
int V_19 , struct V_5 * V_5 ,
struct V_17 * V_12 ,
T_2 V_21 , T_4 V_42 ,
struct V_1 * * V_22 , int F_14 )
{
struct V_35 V_65 = {
. V_46 = V_22 ,
. V_45 = F_14 ,
. V_44 = V_21 ,
. V_51 = NULL ,
. V_43 = V_42
} ;
return F_25 ( V_7 , V_34 , V_19 , V_5 , & V_65 ) ;
}
static T_3 F_46 ( struct V_66 * V_67 , struct V_68 * V_69 )
{
struct V_70 * V_71 ;
const struct V_6 * V_7 ;
struct V_33 * V_34 ;
struct V_72 * V_72 = V_67 -> V_73 ;
struct V_5 * V_5 = V_72 -> V_74 -> V_13 ;
T_4 V_42 = V_67 -> V_75 ;
T_3 V_76 = F_47 ( V_69 ) ;
T_3 V_77 = 0 , V_18 = 0 ;
long V_21 = V_78 ;
if ( ( V_42 & ~ V_79 ) || ( V_76 & ~ V_79 ) )
return - V_80 ;
F_48 ( V_81 , L_1 V_82 L_2 ,
F_49 ( F_50 ( V_5 ) ) , V_5 , V_76 , V_78 ,
V_42 , V_42 , V_76 >> V_27 ,
V_78 >> V_27 ) ;
if ( F_51 ( V_69 ) & ~ V_79 )
return - V_80 ;
V_71 = F_52 ( V_72 ) ;
if ( ! V_71 )
return - V_83 ;
V_7 = V_71 -> V_84 ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_34 = V_71 -> V_85 ;
F_2 ( V_34 ) ;
while ( F_47 ( V_69 ) ) {
struct V_1 * * V_22 ;
T_2 V_86 ;
V_76 = F_53 ( T_2 , F_47 ( V_69 ) , V_21 ) ;
if ( F_54 ( V_69 ) == V_29 ) {
if ( V_42 >= F_55 ( V_5 ) )
break;
if ( V_42 + V_76 > F_55 ( V_5 ) )
V_76 = F_55 ( V_5 ) - V_42 ;
}
V_18 = F_56 ( V_69 , & V_22 , V_76 , & V_86 ) ;
if ( F_38 ( V_18 > 0 ) ) {
int V_87 = F_57 ( V_18 + V_86 , V_11 ) ;
V_18 = F_45 ( V_7 , V_34 , F_54 ( V_69 ) ,
V_5 , V_72 -> V_74 ,
V_18 , V_42 , V_22 ,
V_87 ) ;
F_22 ( V_22 , V_87 , F_54 ( V_69 ) == V_29 ) ;
}
if ( F_20 ( V_18 <= 0 ) ) {
if ( V_18 == - V_24 &&
V_21 > ( V_11 / sizeof( * V_22 ) ) *
V_11 ) {
V_21 = ( ( ( ( V_21 / 2 ) - 1 ) |
~ V_79 ) + 1 ) &
V_79 ;
F_48 ( V_81 , L_3 ,
V_21 ) ;
continue;
}
goto V_88;
}
F_58 ( V_69 , V_18 ) ;
V_77 += V_18 ;
V_42 += V_18 ;
}
V_88:
if ( V_77 > 0 ) {
struct V_89 * V_90 = F_59 ( V_7 ) ;
V_90 -> V_91 . V_92 . V_93 += V_77 ;
}
return V_77 ? V_77 : V_18 ;
}
static int F_60 ( const struct V_6 * V_7 , struct V_33 * V_34 ,
struct V_8 * V_94 )
{
struct V_95 * V_96 = F_61 ( V_7 ) ;
struct V_9 * V_10 = V_34 -> V_40 ;
struct V_97 * V_98 = F_62 ( V_10 , V_94 ) ;
T_4 V_3 = F_63 ( V_10 , F_64 ( V_98 ) ) ;
int V_18 ;
F_65 ( V_10 ) ;
V_18 = F_66 ( V_7 , V_10 , V_96 ) ;
F_67 ( V_10 ) ;
if ( V_18 == 0 ) {
if ( V_96 -> V_99 <= V_3 ) {
char * V_100 = F_33 ( V_98 -> V_101 ) ;
memset ( V_100 , 0 , F_26 ( V_10 ) ) ;
F_35 ( V_100 ) ;
} else if ( V_98 -> V_102 ) {
V_98 -> V_103 = 1 ;
} else {
V_18 = F_68 ( V_7 , V_34 , V_94 , V_63 ) ;
}
}
return V_18 ;
}
static int F_69 ( struct V_72 * V_72 , struct V_17 * V_12 ,
T_4 V_104 , unsigned int V_105 , unsigned int V_106 ,
struct V_1 * * V_107 , void * * V_108 )
{
struct V_70 * V_71 ;
const struct V_6 * V_7 = NULL ;
struct V_33 * V_34 ;
struct V_8 * V_1 = NULL ;
struct V_9 * V_109 = F_7 ( V_12 -> V_13 ) -> V_14 ;
T_5 V_110 = V_104 >> V_27 ;
struct V_1 * V_2 = NULL ;
unsigned int V_111 = V_104 & ( V_11 - 1 ) ;
unsigned int V_112 = V_111 + V_105 ;
int V_18 = 0 ;
F_48 ( V_81 , L_4 , V_110 , V_111 , V_105 ) ;
V_71 = F_52 ( V_72 ) ;
if ( ! V_71 ) {
V_34 = NULL ;
V_18 = - V_83 ;
goto V_88;
}
V_7 = V_71 -> V_84 ;
V_34 = V_71 -> V_85 ;
V_2 = F_70 ( V_12 , V_110 ) ;
if ( F_20 ( ! V_2 || F_13 ( V_2 ) || F_4 ( V_2 ) ) ) {
struct V_89 * V_90 = F_59 ( V_7 ) ;
struct V_113 * V_114 = & V_90 -> V_91 . V_92 . V_115 ;
if ( V_2 && V_114 -> V_116 > 0 ) {
F_71 ( V_2 ) ;
F_24 ( V_2 ) ;
V_2 = NULL ;
}
V_18 = F_72 ( V_7 , V_34 ) ;
if ( V_18 < 0 )
goto V_88;
if ( ! V_2 ) {
V_2 = F_73 ( V_12 , V_110 ,
V_106 ) ;
if ( ! V_2 ) {
V_18 = - V_24 ;
goto V_88;
}
}
}
V_1 = F_28 ( V_7 , V_109 , V_2 -> V_110 , V_2 , V_56 ) ;
if ( F_6 ( V_1 ) ) {
V_18 = F_30 ( V_1 ) ;
goto V_88;
}
V_71 -> V_117 = V_1 ;
F_74 ( & V_1 -> V_118 , L_5 , V_34 ) ;
F_75 ( V_7 , V_34 , V_1 ) ;
if ( ! F_76 ( V_2 ) ) {
if ( V_111 == 0 && V_112 == V_11 ) {
F_77 ( V_119 , V_7 , V_1 , L_6 ) ;
F_78 ( V_2 , 0x11 ) ;
} else {
V_18 = F_60 ( V_7 , V_34 , V_1 ) ;
if ( V_18 == 0 )
F_79 ( V_2 ) ;
}
}
if ( V_18 < 0 )
F_80 ( V_7 , V_34 , V_1 ) ;
V_88:
if ( V_18 < 0 ) {
if ( V_2 ) {
F_71 ( V_2 ) ;
F_24 ( V_2 ) ;
}
if ( ! F_81 ( V_1 ) ) {
F_82 ( & V_1 -> V_118 , L_5 , V_34 ) ;
F_10 ( V_7 , V_1 ) ;
}
if ( V_34 )
V_34 -> V_120 = V_18 ;
} else {
* V_107 = V_2 ;
* V_108 = V_71 ;
}
return V_18 ;
}
static int F_83 ( struct V_72 * V_72 , struct V_17 * V_12 ,
T_4 V_104 , unsigned V_105 , unsigned V_121 ,
struct V_1 * V_2 , void * V_108 )
{
struct V_70 * V_71 = V_108 ;
const struct V_6 * V_7 ;
struct V_33 * V_34 ;
struct V_89 * V_90 ;
struct V_8 * V_1 ;
unsigned int V_111 = V_104 & ( V_11 - 1 ) ;
bool V_122 = false ;
int V_18 = 0 ;
F_24 ( V_2 ) ;
V_7 = V_71 -> V_84 ;
V_1 = V_71 -> V_117 ;
V_34 = V_71 -> V_85 ;
V_90 = F_59 ( V_7 ) ;
F_2 ( F_84 ( V_1 , V_34 ) ) ;
if ( V_121 > 0 ) {
struct V_113 * V_114 = & V_90 -> V_91 . V_92 . V_115 ;
V_71 -> V_117 = NULL ;
F_39 ( V_114 , V_1 ) ;
if ( V_114 -> V_116 == 1 )
V_90 -> V_91 . V_92 . V_123 = V_111 ;
else
F_2 ( V_111 == 0 ) ;
V_90 -> V_91 . V_92 . V_124 = V_111 + V_121 ;
if ( F_13 ( V_2 ) )
V_122 = true ;
if ( V_114 -> V_116 >= V_125 )
V_122 = true ;
F_85 ( V_81 , V_7 , V_1 ,
L_7 , V_114 -> V_116 ) ;
} else {
F_37 ( V_7 , V_34 , V_1 ) ;
V_71 -> V_117 = NULL ;
F_82 ( & V_1 -> V_118 , L_5 , V_34 ) ;
F_10 ( V_7 , V_1 ) ;
V_122 = true ;
}
if ( V_122 ||
V_72 -> V_126 & V_127 || F_86 ( F_87 ( V_72 ) ) )
V_18 = F_72 ( V_7 , V_34 ) ;
if ( V_18 < 0 )
V_34 -> V_120 = V_18 ;
return V_18 >= 0 ? V_121 : V_18 ;
}
static int F_88 ( struct V_17 * V_12 ,
struct V_1 * V_128 , struct V_1 * V_1 ,
enum V_129 V_130
)
{
return - V_83 ;
}
