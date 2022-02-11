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
long V_23 = V_38 -> V_46 ;
int F_14 = V_38 -> V_47 ;
struct V_1 * * V_24 = V_38 -> V_48 ;
long V_49 = F_30 ( V_10 ) ;
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
struct V_75 * V_10 = F_51 ( V_5 ) ;
T_4 V_44 = V_69 -> V_76 ;
T_3 V_77 = F_52 ( V_71 ) ;
T_3 V_78 = 0 , V_20 = 0 ;
struct V_79 * V_80 = F_7 ( V_5 ) ;
long V_23 = V_81 ;
int V_11 ;
if ( ! V_80 -> V_82 )
return - V_83 ;
if ( ( V_44 & ~ V_84 ) || ( V_77 & ~ V_84 ) )
return - V_85 ;
F_53 ( V_86 , L_1 V_87 L_2 ,
F_54 ( F_55 ( V_5 ) ) , V_5 , V_77 , V_81 ,
V_44 , V_44 , V_77 >> V_29 ,
V_81 >> V_29 ) ;
if ( F_56 ( V_71 ) & ~ V_84 )
return - V_85 ;
V_7 = F_5 ( & V_11 ) ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_36 = F_57 ( V_7 ) -> V_88 . V_89 ;
F_2 ( V_36 ) ;
if ( F_58 ( V_71 ) == V_31 )
F_59 ( V_5 ) ;
F_2 ( V_10 -> V_90 == 0 ) ;
while ( F_52 ( V_71 ) ) {
struct V_1 * * V_24 ;
T_2 V_91 ;
V_77 = F_60 ( T_2 , F_52 ( V_71 ) , V_23 ) ;
if ( F_58 ( V_71 ) == V_31 ) {
if ( V_44 >= F_61 ( V_5 ) )
break;
if ( V_44 + V_77 > F_61 ( V_5 ) )
V_77 = F_61 ( V_5 ) - V_44 ;
}
V_20 = F_62 ( V_71 , & V_24 , V_77 , & V_91 ) ;
if ( F_42 ( V_20 > 0 ) ) {
int V_92 = F_63 ( V_20 + V_91 , V_12 ) ;
V_20 = F_49 ( V_7 , V_36 , F_58 ( V_71 ) ,
V_5 , V_72 -> V_74 ,
V_20 , V_44 , V_24 ,
V_92 ) ;
F_26 ( V_24 , V_92 , F_58 ( V_71 ) == V_31 ) ;
}
if ( F_24 ( V_20 <= 0 ) ) {
if ( V_20 == - V_26 &&
V_23 > ( V_12 / sizeof( * V_24 ) ) *
V_12 ) {
V_23 = ( ( ( ( V_23 / 2 ) - 1 ) |
~ V_84 ) + 1 ) &
V_84 ;
F_53 ( V_86 , L_3 ,
V_23 ) ;
continue;
}
goto V_93;
}
F_64 ( V_71 , V_20 ) ;
V_78 += V_20 ;
V_44 += V_20 ;
}
V_93:
F_2 ( V_10 -> V_90 == 0 ) ;
if ( F_58 ( V_71 ) == V_31 )
F_65 ( V_5 ) ;
if ( V_78 > 0 ) {
struct V_94 * V_95 = F_57 ( V_7 ) ;
V_95 -> V_96 . V_97 . V_98 += V_78 ;
}
F_11 ( V_7 , & V_11 ) ;
return V_78 ? V_78 : V_20 ;
}
static int F_66 ( const struct V_6 * V_7 , struct V_35 * V_36 ,
struct V_8 * V_99 )
{
struct V_100 * V_101 = F_67 ( V_7 ) ;
struct V_9 * V_10 = V_36 -> V_42 ;
struct V_102 * V_103 = F_68 ( V_10 , V_99 ) ;
T_4 V_3 = F_69 ( V_10 , F_70 ( V_103 ) ) ;
int V_20 ;
F_71 ( V_10 ) ;
V_20 = F_72 ( V_7 , V_10 , V_101 ) ;
F_73 ( V_10 ) ;
if ( V_20 == 0 ) {
if ( V_101 -> V_104 <= V_3 ) {
char * V_105 = F_37 ( V_103 -> V_106 ) ;
memset ( V_105 , 0 , F_30 ( V_10 ) ) ;
F_39 ( V_105 ) ;
} else if ( V_103 -> V_107 ) {
V_103 -> V_108 = 1 ;
} else {
V_20 = F_74 ( V_7 , V_36 , V_99 , V_65 ) ;
}
}
return V_20 ;
}
static int F_75 ( struct V_72 * V_72 , struct V_19 * V_13 ,
T_4 V_109 , unsigned V_110 , unsigned V_111 ,
struct V_1 * * V_112 , void * * V_113 )
{
struct V_114 * V_115 ;
struct V_6 * V_7 ;
struct V_35 * V_36 ;
struct V_8 * V_1 ;
struct V_9 * V_116 = F_7 ( V_13 -> V_14 ) -> V_15 ;
T_5 V_117 = V_109 >> V_29 ;
struct V_1 * V_2 = NULL ;
unsigned int V_118 = V_109 & ( V_12 - 1 ) ;
unsigned int V_119 = V_118 + V_110 ;
int V_20 = 0 ;
F_53 ( V_86 , L_4 , V_117 , V_118 , V_110 ) ;
V_115 = F_76 ( V_72 , NULL ) ;
if ( F_6 ( V_115 ) ) {
V_20 = F_34 ( V_115 ) ;
goto V_93;
}
V_7 = V_115 -> V_120 ;
V_36 = V_115 -> V_121 ;
V_2 = F_77 ( V_13 , V_117 ) ;
if ( F_24 ( ! V_2 || F_13 ( V_2 ) || F_4 ( V_2 ) ) ) {
struct V_94 * V_95 = F_57 ( V_7 ) ;
struct V_122 * V_123 = & V_95 -> V_96 . V_97 . V_124 ;
if ( V_2 && V_123 -> V_125 > 0 ) {
F_78 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 = NULL ;
}
V_20 = F_79 ( V_7 , V_36 ) ;
if ( V_20 < 0 )
goto V_93;
if ( ! V_2 ) {
V_2 = F_80 ( V_13 , V_117 ,
V_111 ) ;
if ( ! V_2 ) {
V_20 = - V_26 ;
goto V_93;
}
}
}
V_1 = F_32 ( V_7 , V_116 , V_2 -> V_117 , V_2 , V_58 ) ;
if ( F_6 ( V_1 ) ) {
V_20 = F_34 ( V_1 ) ;
goto V_93;
}
V_115 -> V_126 = V_1 ;
F_81 ( & V_1 -> V_127 , L_5 , V_36 ) ;
F_82 ( V_7 , V_36 , V_1 ) ;
if ( ! F_83 ( V_2 ) ) {
if ( V_118 == 0 && V_119 == V_12 ) {
F_84 ( V_128 , V_7 , V_1 , L_6 ) ;
F_85 ( V_2 , 0x11 ) ;
} else {
V_20 = F_66 ( V_7 , V_36 , V_1 ) ;
if ( V_20 == 0 )
F_86 ( V_2 ) ;
}
}
if ( V_20 < 0 )
F_87 ( V_7 , V_36 , V_1 ) ;
V_93:
if ( V_20 < 0 ) {
if ( V_2 ) {
F_78 ( V_2 ) ;
F_28 ( V_2 ) ;
}
if ( ! F_6 ( V_115 ) )
F_88 ( V_115 ) ;
} else {
* V_112 = V_2 ;
* V_113 = V_115 ;
}
return V_20 ;
}
static int F_89 ( struct V_72 * V_72 , struct V_19 * V_13 ,
T_4 V_109 , unsigned V_110 , unsigned V_129 ,
struct V_1 * V_2 , void * V_113 )
{
struct V_114 * V_115 = V_113 ;
struct V_6 * V_7 ;
struct V_35 * V_36 ;
struct V_94 * V_95 ;
struct V_8 * V_1 ;
unsigned V_118 = V_109 & ( V_12 - 1 ) ;
bool V_130 = false ;
int V_20 = 0 ;
F_28 ( V_2 ) ;
V_7 = V_115 -> V_120 ;
V_1 = V_115 -> V_126 ;
V_36 = V_115 -> V_121 ;
V_95 = F_57 ( V_7 ) ;
F_2 ( F_90 ( V_1 , V_36 ) ) ;
if ( V_129 > 0 ) {
struct V_122 * V_123 = & V_95 -> V_96 . V_97 . V_124 ;
V_115 -> V_126 = NULL ;
F_43 ( V_123 , V_1 ) ;
if ( V_123 -> V_125 == 1 )
V_95 -> V_96 . V_97 . V_131 = V_118 ;
else
F_2 ( V_118 == 0 ) ;
V_95 -> V_96 . V_97 . V_132 = V_118 + V_129 ;
if ( V_123 -> V_125 >= V_133 )
V_130 = true ;
F_91 ( V_86 , V_7 , V_1 ,
L_7 , V_123 -> V_125 ) ;
} else {
F_41 ( V_7 , V_36 , V_1 ) ;
V_130 = true ;
}
if ( V_130 ||
V_72 -> V_134 & V_135 || F_92 ( F_93 ( V_72 ) ) )
V_20 = F_79 ( V_7 , V_36 ) ;
F_88 ( V_115 ) ;
return V_20 >= 0 ? V_129 : V_20 ;
}
static int F_94 ( struct V_19 * V_13 ,
struct V_1 * V_136 , struct V_1 * V_1 ,
enum V_137 V_138
)
{
return - V_139 ;
}
