static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_1 ;
struct V_9 * V_10 ;
int V_11 ;
F_2 ( F_3 ( V_2 ) ) ;
F_2 ( ! F_4 ( V_2 ) ) ;
if ( V_3 == 0 && V_4 == V_12 ) {
V_7 = F_5 ( & V_11 ) ;
if ( ! F_6 ( V_7 ) ) {
V_5 = V_2 -> V_13 -> V_14 ;
V_10 = F_7 ( V_5 ) -> V_15 ;
if ( V_10 ) {
V_1 = F_8 ( V_2 , V_10 ) ;
if ( V_1 ) {
F_9 ( V_7 , V_1 ) ;
F_10 ( V_7 , V_1 ) ;
}
} else {
F_2 ( V_2 -> V_16 == 0 ) ;
}
F_11 ( V_7 , & V_11 ) ;
}
}
}
static int F_12 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_7 ;
void * V_18 ;
struct V_9 * V_10 ;
struct V_8 * V_1 ;
struct V_19 * V_13 ;
int V_20 = 0 ;
F_2 ( F_3 ( V_2 ) ) ;
if ( F_4 ( V_2 ) || F_13 ( V_2 ) )
return 0 ;
V_13 = V_2 -> V_13 ;
if ( ! V_13 )
return 1 ;
V_10 = F_7 ( V_13 -> V_14 ) -> V_15 ;
if ( ! V_10 )
return 1 ;
if ( F_14 ( V_2 ) > 3 )
return 0 ;
V_1 = F_8 ( V_2 , V_10 ) ;
if ( ! V_1 )
return 1 ;
V_18 = F_15 () ;
V_7 = F_16 () ;
F_2 ( ! F_6 ( V_7 ) ) ;
if ( ! F_17 ( V_1 ) ) {
V_20 = 1 ;
F_9 ( V_7 , V_1 ) ;
}
F_2 ( F_18 ( V_10 ) > 1 ) ;
F_10 ( V_7 , V_1 ) ;
F_19 ( V_7 ) ;
F_20 ( V_18 ) ;
return V_20 ;
}
static inline int F_21 ( int V_21 , unsigned long V_22 ,
T_2 V_23 , struct V_1 * * * V_24 ,
int * V_25 )
{
int V_20 = - V_26 ;
if ( V_23 > V_27 ) {
* V_24 = NULL ;
return - V_28 ;
}
* V_25 = ( V_22 + V_23 + V_12 - 1 ) >> V_29 ;
* V_25 -= V_22 >> V_29 ;
* V_24 = F_22 ( * V_25 * sizeof( * * V_24 ) , V_30 ) ;
if ( * V_24 ) {
V_20 = F_23 ( V_22 , * V_25 ,
( V_21 == V_31 ) , * V_24 ) ;
if ( F_24 ( V_20 <= 0 ) )
F_25 ( * V_24 ) ;
}
return V_20 ;
}
static void F_26 ( struct V_1 * * V_24 , int V_32 , int V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
if ( V_33 )
F_27 ( V_24 [ V_34 ] ) ;
F_28 ( V_24 [ V_34 ] ) ;
}
F_25 ( V_24 ) ;
}
T_3 F_29 ( const struct V_6 * V_7 , struct V_35 * V_36 ,
int V_21 , struct V_5 * V_5 ,
struct V_37 * V_38 )
{
struct V_8 * V_39 ;
struct V_40 * V_41 ;
struct V_9 * V_10 = V_36 -> V_42 ;
int V_34 ;
T_3 V_43 = 0 ;
T_4 V_44 = V_38 -> V_45 ;
T_2 V_23 = V_38 -> V_46 ;
int F_14 = V_38 -> V_47 ;
struct V_1 * * V_24 = V_38 -> V_48 ;
T_2 V_49 = F_30 ( V_10 ) ;
bool V_50 ;
int V_51 = 0 ;
V_41 = & V_36 -> V_52 ;
F_31 ( V_41 ) ;
for ( V_34 = 0 ; V_34 < F_14 ; V_34 ++ ) {
if ( V_38 -> V_53 )
V_44 = V_38 -> V_53 [ V_34 ] ;
F_2 ( ! ( V_44 & ( V_49 - 1 ) ) ) ;
V_39 = F_32 ( V_7 , V_10 , F_33 ( V_10 , V_44 ) ,
V_38 -> V_48 [ V_34 ] , V_54 ) ;
if ( F_6 ( V_39 ) ) {
V_43 = F_34 ( V_39 ) ;
break;
}
V_43 = F_35 ( V_7 , V_36 , V_39 ) ;
if ( V_43 ) {
F_2 ( V_39 -> V_55 == V_56 ) ;
F_10 ( V_7 , V_39 ) ;
break;
}
V_50 = true ;
if ( V_39 -> V_57 == V_58 ) {
struct V_1 * V_2 = F_36 ( V_39 ) ;
struct V_1 * V_59 ;
struct V_1 * V_60 ;
void * V_61 ;
void * V_62 ;
V_59 = ( V_21 == V_63 ) ? V_24 [ V_34 ] : V_2 ;
V_60 = ( V_21 == V_63 ) ? V_2 : V_24 [ V_34 ] ;
V_61 = F_37 ( V_59 ) ;
V_62 = F_37 ( V_60 ) ;
memcpy ( V_62 , V_61 , F_38 ( V_49 , V_23 ) ) ;
F_39 ( V_62 ) ;
F_39 ( V_61 ) ;
if ( V_21 == V_63 )
F_40 ( V_2 ) ;
if ( V_21 == V_31 ) {
F_41 ( V_7 , V_36 , V_39 ) ;
V_50 = false ;
}
}
if ( F_42 ( V_50 ) ) {
F_43 ( & V_41 -> V_64 , V_39 ) ;
F_44 ( V_7 , V_39 , 0 , F_38 ( V_23 , V_49 ) ) ;
++ V_51 ;
}
F_10 ( V_7 , V_39 ) ;
V_23 -= V_49 ;
V_44 += V_49 ;
}
if ( V_43 == 0 && V_51 ) {
V_43 = F_45 ( V_7 , V_36 ,
V_21 == V_31 ? V_65 : V_66 ,
V_41 , 0 ) ;
}
if ( V_43 == 0 )
V_43 = V_38 -> V_46 ;
F_46 ( V_7 , V_36 , V_41 ) ;
F_47 ( V_7 , V_36 , V_41 ) ;
F_48 ( V_7 , V_41 ) ;
return V_43 ;
}
static T_3 F_49 ( const struct V_6 * V_7 , struct V_35 * V_36 ,
int V_21 , struct V_5 * V_5 ,
struct V_19 * V_13 ,
T_2 V_23 , T_4 V_44 ,
struct V_1 * * V_24 , int F_14 )
{
struct V_37 V_67 = {
. V_48 = V_24 ,
. V_47 = F_14 ,
. V_46 = V_23 ,
. V_53 = NULL ,
. V_45 = V_44
} ;
return F_29 ( V_7 , V_36 , V_21 , V_5 , & V_67 ) ;
}
static T_3 F_50 ( struct V_68 * V_69 , struct V_70 * V_71 )
{
struct V_6 * V_7 ;
struct V_35 * V_36 ;
struct V_72 * V_72 = V_69 -> V_73 ;
struct V_5 * V_5 = V_72 -> V_74 -> V_14 ;
T_4 V_44 = V_69 -> V_75 ;
T_3 V_76 = F_51 ( V_71 ) ;
T_3 V_77 = 0 , V_20 = 0 ;
struct V_78 * V_79 = F_7 ( V_5 ) ;
long V_23 = V_80 ;
int V_11 ;
if ( ! V_79 -> V_81 )
return - V_82 ;
if ( ( V_44 & ~ V_83 ) || ( V_76 & ~ V_83 ) )
return - V_84 ;
F_52 ( V_85 , L_1 V_86 L_2 ,
F_53 ( F_54 ( V_5 ) ) , V_5 , V_76 , V_80 ,
V_44 , V_44 , V_76 >> V_29 ,
V_80 >> V_29 ) ;
if ( F_55 ( V_71 ) & ~ V_83 )
return - V_84 ;
V_7 = F_5 ( & V_11 ) ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_36 = F_56 ( V_7 ) -> V_87 . V_88 ;
F_2 ( V_36 ) ;
while ( F_51 ( V_71 ) ) {
struct V_1 * * V_24 ;
T_2 V_89 ;
V_76 = F_57 ( T_2 , F_51 ( V_71 ) , V_23 ) ;
if ( F_58 ( V_71 ) == V_31 ) {
if ( V_44 >= F_59 ( V_5 ) )
break;
if ( V_44 + V_76 > F_59 ( V_5 ) )
V_76 = F_59 ( V_5 ) - V_44 ;
}
V_20 = F_60 ( V_71 , & V_24 , V_76 , & V_89 ) ;
if ( F_42 ( V_20 > 0 ) ) {
int V_90 = F_61 ( V_20 + V_89 , V_12 ) ;
V_20 = F_49 ( V_7 , V_36 , F_58 ( V_71 ) ,
V_5 , V_72 -> V_74 ,
V_20 , V_44 , V_24 ,
V_90 ) ;
F_26 ( V_24 , V_90 , F_58 ( V_71 ) == V_31 ) ;
}
if ( F_24 ( V_20 <= 0 ) ) {
if ( V_20 == - V_26 &&
V_23 > ( V_12 / sizeof( * V_24 ) ) *
V_12 ) {
V_23 = ( ( ( ( V_23 / 2 ) - 1 ) |
~ V_83 ) + 1 ) &
V_83 ;
F_52 ( V_85 , L_3 ,
V_23 ) ;
continue;
}
goto V_91;
}
F_62 ( V_71 , V_20 ) ;
V_77 += V_20 ;
V_44 += V_20 ;
}
V_91:
if ( V_77 > 0 ) {
struct V_92 * V_93 = F_56 ( V_7 ) ;
V_93 -> V_94 . V_95 . V_96 += V_77 ;
}
F_11 ( V_7 , & V_11 ) ;
return V_77 ? V_77 : V_20 ;
}
static int F_63 ( const struct V_6 * V_7 , struct V_35 * V_36 ,
struct V_8 * V_97 )
{
struct V_98 * V_99 = F_64 ( V_7 ) ;
struct V_9 * V_10 = V_36 -> V_42 ;
struct V_100 * V_101 = F_65 ( V_10 , V_97 ) ;
T_4 V_3 = F_66 ( V_10 , F_67 ( V_101 ) ) ;
int V_20 ;
F_68 ( V_10 ) ;
V_20 = F_69 ( V_7 , V_10 , V_99 ) ;
F_70 ( V_10 ) ;
if ( V_20 == 0 ) {
if ( V_99 -> V_102 <= V_3 ) {
char * V_103 = F_37 ( V_101 -> V_104 ) ;
memset ( V_103 , 0 , F_30 ( V_10 ) ) ;
F_39 ( V_103 ) ;
} else if ( V_101 -> V_105 ) {
V_101 -> V_106 = 1 ;
} else {
V_20 = F_71 ( V_7 , V_36 , V_97 , V_65 ) ;
}
}
return V_20 ;
}
static int F_72 ( struct V_72 * V_72 , struct V_19 * V_13 ,
T_4 V_107 , unsigned V_108 , unsigned V_109 ,
struct V_1 * * V_110 , void * * V_111 )
{
struct V_112 * V_113 ;
const struct V_6 * V_7 ;
struct V_35 * V_36 ;
struct V_8 * V_1 ;
struct V_9 * V_114 = F_7 ( V_13 -> V_14 ) -> V_15 ;
T_5 V_115 = V_107 >> V_29 ;
struct V_1 * V_2 = NULL ;
unsigned int V_116 = V_107 & ( V_12 - 1 ) ;
unsigned int V_117 = V_116 + V_108 ;
int V_20 = 0 ;
F_52 ( V_85 , L_4 , V_115 , V_116 , V_108 ) ;
V_113 = F_73 ( V_72 ) ;
if ( ! V_113 ) {
V_20 = - V_118 ;
goto V_91;
}
V_7 = V_113 -> V_119 ;
V_36 = V_113 -> V_120 ;
V_2 = F_74 ( V_13 , V_115 ) ;
if ( F_24 ( ! V_2 || F_13 ( V_2 ) || F_4 ( V_2 ) ) ) {
struct V_92 * V_93 = F_56 ( V_7 ) ;
struct V_121 * V_122 = & V_93 -> V_94 . V_95 . V_123 ;
if ( V_2 && V_122 -> V_124 > 0 ) {
F_75 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 = NULL ;
}
V_20 = F_76 ( V_7 , V_36 ) ;
if ( V_20 < 0 )
goto V_91;
if ( ! V_2 ) {
V_2 = F_77 ( V_13 , V_115 ,
V_109 ) ;
if ( ! V_2 ) {
V_20 = - V_26 ;
goto V_91;
}
}
}
V_1 = F_32 ( V_7 , V_114 , V_2 -> V_115 , V_2 , V_58 ) ;
if ( F_6 ( V_1 ) ) {
V_20 = F_34 ( V_1 ) ;
goto V_91;
}
V_113 -> V_125 = V_1 ;
F_78 ( & V_1 -> V_126 , L_5 , V_36 ) ;
F_79 ( V_7 , V_36 , V_1 ) ;
if ( ! F_80 ( V_2 ) ) {
if ( V_116 == 0 && V_117 == V_12 ) {
F_81 ( V_127 , V_7 , V_1 , L_6 ) ;
F_82 ( V_2 , 0x11 ) ;
} else {
V_20 = F_63 ( V_7 , V_36 , V_1 ) ;
if ( V_20 == 0 )
F_83 ( V_2 ) ;
}
}
if ( V_20 < 0 )
F_84 ( V_7 , V_36 , V_1 ) ;
V_91:
if ( V_20 < 0 ) {
if ( V_2 ) {
F_75 ( V_2 ) ;
F_28 ( V_2 ) ;
}
} else {
* V_110 = V_2 ;
* V_111 = V_113 ;
}
return V_20 ;
}
static int F_85 ( struct V_72 * V_72 , struct V_19 * V_13 ,
T_4 V_107 , unsigned V_108 , unsigned V_128 ,
struct V_1 * V_2 , void * V_111 )
{
struct V_112 * V_113 = V_111 ;
const struct V_6 * V_7 ;
struct V_35 * V_36 ;
struct V_92 * V_93 ;
struct V_8 * V_1 ;
unsigned V_116 = V_107 & ( V_12 - 1 ) ;
bool V_129 = false ;
int V_20 = 0 ;
F_28 ( V_2 ) ;
V_7 = V_113 -> V_119 ;
V_1 = V_113 -> V_125 ;
V_36 = V_113 -> V_120 ;
V_93 = F_56 ( V_7 ) ;
F_2 ( F_86 ( V_1 , V_36 ) ) ;
if ( V_128 > 0 ) {
struct V_121 * V_122 = & V_93 -> V_94 . V_95 . V_123 ;
V_113 -> V_125 = NULL ;
F_43 ( V_122 , V_1 ) ;
if ( V_122 -> V_124 == 1 )
V_93 -> V_94 . V_95 . V_130 = V_116 ;
else
F_2 ( V_116 == 0 ) ;
V_93 -> V_94 . V_95 . V_131 = V_116 + V_128 ;
if ( F_13 ( V_2 ) )
V_129 = true ;
if ( V_122 -> V_124 >= V_132 )
V_129 = true ;
F_87 ( V_85 , V_7 , V_1 ,
L_7 , V_122 -> V_124 ) ;
} else {
F_41 ( V_7 , V_36 , V_1 ) ;
V_113 -> V_125 = NULL ;
F_88 ( & V_1 -> V_126 , L_5 , V_36 ) ;
F_10 ( V_7 , V_1 ) ;
V_129 = true ;
}
if ( V_129 ||
V_72 -> V_133 & V_134 || F_89 ( F_90 ( V_72 ) ) )
V_20 = F_76 ( V_7 , V_36 ) ;
return V_20 >= 0 ? V_128 : V_20 ;
}
static int F_91 ( struct V_19 * V_13 ,
struct V_1 * V_135 , struct V_1 * V_1 ,
enum V_136 V_137
)
{
return - V_118 ;
}
