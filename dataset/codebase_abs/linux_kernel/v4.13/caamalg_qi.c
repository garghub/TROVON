static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ,
F_4 ( * V_4 ) , V_2 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
unsigned int V_7 = F_6 ( V_2 ) ;
T_1 V_8 = 0 ;
T_1 * V_9 = NULL ;
unsigned int V_10 [ 2 ] ;
T_1 V_11 ;
const bool V_12 = ( ( V_6 -> V_13 . V_14 & V_15 ) ==
V_16 ) ;
const bool V_17 = V_4 -> V_18 . V_19 ;
if ( ! V_6 -> V_13 . V_20 || ! V_6 -> V_21 )
return 0 ;
if ( V_12 )
V_8 = 16 ;
if ( V_17 ) {
V_8 = 16 + V_22 ;
V_9 = ( T_1 * ) ( ( void * ) V_6 -> V_23 + V_6 -> V_24 . V_25 +
V_6 -> V_13 . V_20 - V_22 ) ;
}
V_10 [ 0 ] = V_6 -> V_24 . V_25 ;
V_10 [ 1 ] = V_6 -> V_13 . V_20 ;
if ( V_4 -> V_18 . V_26 )
goto V_27;
if ( F_7 ( V_28 +
( V_17 ? V_29 : 0 ) ,
V_30 , V_10 , & V_11 ,
F_8 ( V_10 ) ) < 0 )
return - V_31 ;
if ( V_11 & 1 )
V_6 -> V_24 . V_32 = V_6 -> V_23 ;
else
V_6 -> V_24 . V_33 = V_6 -> V_33 ;
if ( V_11 & 2 )
V_6 -> V_13 . V_32 = V_6 -> V_23 + V_6 -> V_24 . V_25 ;
else
V_6 -> V_13 . V_33 = V_6 -> V_33 + V_6 -> V_24 . V_25 ;
V_6 -> V_24 . V_34 = ! ! ( V_11 & 1 ) ;
V_6 -> V_13 . V_34 = ! ! ( V_11 & 2 ) ;
F_9 ( V_6 -> V_35 , & V_6 -> V_13 , & V_6 -> V_24 ,
V_7 , V_6 -> V_21 , V_17 , V_9 ,
V_8 , true ) ;
V_27:
if ( F_7 ( V_36 +
( V_17 ? V_29 : 0 ) ,
V_30 , V_10 , & V_11 ,
F_8 ( V_10 ) ) < 0 )
return - V_31 ;
if ( V_11 & 1 )
V_6 -> V_24 . V_32 = V_6 -> V_23 ;
else
V_6 -> V_24 . V_33 = V_6 -> V_33 ;
if ( V_11 & 2 )
V_6 -> V_13 . V_32 = V_6 -> V_23 + V_6 -> V_24 . V_25 ;
else
V_6 -> V_13 . V_33 = V_6 -> V_33 + V_6 -> V_24 . V_25 ;
V_6 -> V_24 . V_34 = ! ! ( V_11 & 1 ) ;
V_6 -> V_13 . V_34 = ! ! ( V_11 & 2 ) ;
F_10 ( V_6 -> V_37 , & V_6 -> V_13 , & V_6 -> V_24 ,
V_7 , V_6 -> V_21 , V_4 -> V_18 . V_26 ,
V_17 , V_9 , V_8 , true ) ;
if ( ! V_4 -> V_18 . V_26 )
goto V_38;
if ( F_7 ( V_39 +
( V_17 ? V_29 : 0 ) ,
V_30 , V_10 , & V_11 ,
F_8 ( V_10 ) ) < 0 )
return - V_31 ;
if ( V_11 & 1 )
V_6 -> V_24 . V_32 = V_6 -> V_23 ;
else
V_6 -> V_24 . V_33 = V_6 -> V_33 ;
if ( V_11 & 2 )
V_6 -> V_13 . V_32 = V_6 -> V_23 + V_6 -> V_24 . V_25 ;
else
V_6 -> V_13 . V_33 = V_6 -> V_33 + V_6 -> V_24 . V_25 ;
V_6 -> V_24 . V_34 = ! ! ( V_11 & 1 ) ;
V_6 -> V_13 . V_34 = ! ! ( V_11 & 2 ) ;
F_11 ( V_6 -> V_35 , & V_6 -> V_13 , & V_6 -> V_24 ,
V_7 , V_6 -> V_21 , V_17 , V_9 ,
V_8 , true ) ;
V_38:
return 0 ;
}
static int F_12 ( struct V_1 * V_40 , unsigned int V_21 )
{
struct V_5 * V_6 = F_5 ( V_40 ) ;
V_6 -> V_21 = V_21 ;
F_1 ( V_40 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const T_2 * V_23 ,
unsigned int V_20 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_41 * V_42 = V_6 -> V_42 ;
struct V_43 V_44 ;
int V_45 = 0 ;
if ( F_14 ( & V_44 , V_23 , V_20 ) != 0 )
goto V_46;
#ifdef F_15
F_16 ( V_42 , L_1 ,
V_44 . V_47 + V_44 . V_48 , V_44 . V_48 ,
V_44 . V_47 ) ;
F_17 ( V_49 , L_2 F_18 ( __LINE__ ) L_3 ,
V_50 , 16 , 4 , V_23 , V_20 , 1 ) ;
#endif
V_45 = F_19 ( V_42 , V_6 -> V_23 , & V_6 -> V_24 , V_44 . V_51 ,
V_44 . V_47 , V_52 -
V_44 . V_48 ) ;
if ( V_45 )
goto V_46;
memcpy ( V_6 -> V_23 + V_6 -> V_24 . V_25 , V_44 . V_53 , V_44 . V_48 ) ;
F_20 ( V_42 , V_6 -> V_33 , V_6 -> V_24 . V_25 +
V_44 . V_48 , V_54 ) ;
#ifdef F_15
F_17 ( V_49 , L_4 F_18 ( __LINE__ ) L_3 ,
V_50 , 16 , 4 , V_6 -> V_23 ,
V_6 -> V_24 . V_25 + V_44 . V_48 , 1 ) ;
#endif
V_6 -> V_13 . V_20 = V_44 . V_48 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 )
goto V_46;
if ( V_6 -> V_55 [ V_56 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_56 ] ,
V_6 -> V_35 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_5 ) ;
goto V_46;
}
}
if ( V_6 -> V_55 [ V_57 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_57 ] ,
V_6 -> V_37 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_6 ) ;
goto V_46;
}
}
return V_45 ;
V_46:
F_22 ( V_2 , V_58 ) ;
return - V_31 ;
}
static int F_23 ( struct V_59 * V_60 ,
const T_2 * V_23 , unsigned int V_20 )
{
struct V_5 * V_6 = F_24 ( V_60 ) ;
struct V_61 * V_62 = F_25 ( V_60 ) ;
const char * V_63 = F_26 ( V_62 ) ;
struct V_41 * V_42 = V_6 -> V_42 ;
unsigned int V_7 = F_27 ( V_60 ) ;
T_1 V_8 = 0 ;
const bool V_12 = ( ( V_6 -> V_13 . V_14 & V_15 ) ==
V_16 ) ;
const bool V_17 = ( V_12 && strstr ( V_63 , L_7 ) ) ;
int V_45 = 0 ;
memcpy ( V_6 -> V_23 , V_23 , V_20 ) ;
#ifdef F_15
F_17 ( V_49 , L_2 F_18 ( __LINE__ ) L_3 ,
V_50 , 16 , 4 , V_23 , V_20 , 1 ) ;
#endif
if ( V_12 )
V_8 = 16 ;
if ( V_17 ) {
V_8 = 16 + V_22 ;
V_20 -= V_22 ;
}
F_20 ( V_42 , V_6 -> V_33 , V_20 , V_54 ) ;
V_6 -> V_13 . V_20 = V_20 ;
V_6 -> V_13 . V_32 = V_6 -> V_23 ;
V_6 -> V_13 . V_34 = true ;
F_28 ( V_6 -> V_35 , & V_6 -> V_13 , V_7 ,
V_17 , V_8 ) ;
F_29 ( V_6 -> V_37 , & V_6 -> V_13 , V_7 ,
V_17 , V_8 ) ;
F_30 ( V_6 -> V_64 , & V_6 -> V_13 ,
V_7 , V_17 , V_8 ) ;
if ( V_6 -> V_55 [ V_56 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_56 ] ,
V_6 -> V_35 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_5 ) ;
goto V_46;
}
}
if ( V_6 -> V_55 [ V_57 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_57 ] ,
V_6 -> V_37 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_6 ) ;
goto V_46;
}
}
if ( V_6 -> V_55 [ V_65 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_65 ] ,
V_6 -> V_64 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_8 ) ;
goto V_46;
}
}
return V_45 ;
V_46:
F_31 ( V_60 , V_58 ) ;
return - V_31 ;
}
static int F_32 ( struct V_59 * V_60 ,
const T_2 * V_23 , unsigned int V_20 )
{
struct V_5 * V_6 = F_24 ( V_60 ) ;
struct V_41 * V_42 = V_6 -> V_42 ;
int V_45 = 0 ;
if ( V_20 != 2 * V_66 && V_20 != 2 * V_67 ) {
F_31 ( V_60 ,
V_58 ) ;
F_16 ( V_42 , L_9 ) ;
return - V_31 ;
}
memcpy ( V_6 -> V_23 , V_23 , V_20 ) ;
F_20 ( V_42 , V_6 -> V_33 , V_20 , V_54 ) ;
V_6 -> V_13 . V_20 = V_20 ;
V_6 -> V_13 . V_32 = V_6 -> V_23 ;
V_6 -> V_13 . V_34 = true ;
F_33 ( V_6 -> V_35 , & V_6 -> V_13 ) ;
F_34 ( V_6 -> V_37 , & V_6 -> V_13 ) ;
if ( V_6 -> V_55 [ V_56 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_56 ] ,
V_6 -> V_35 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_5 ) ;
goto V_46;
}
}
if ( V_6 -> V_55 [ V_57 ] ) {
V_45 = F_21 ( V_6 -> V_55 [ V_57 ] ,
V_6 -> V_37 ) ;
if ( V_45 ) {
F_16 ( V_42 , L_6 ) ;
goto V_46;
}
}
return V_45 ;
V_46:
F_31 ( V_60 , V_58 ) ;
return 0 ;
}
static struct V_68 * F_35 ( struct V_5 * V_6 ,
enum V_69 type )
{
struct V_68 * V_55 = V_6 -> V_55 [ type ] ;
T_1 * V_70 ;
if ( F_36 ( ! V_55 ) ) {
F_37 ( & V_6 -> V_71 ) ;
V_55 = V_6 -> V_55 [ type ] ;
if ( ! V_55 ) {
int V_72 ;
if ( type == V_56 )
V_70 = V_6 -> V_35 ;
else if ( type == V_57 )
V_70 = V_6 -> V_37 ;
else
V_70 = V_6 -> V_64 ;
V_72 = F_38 () ;
V_55 = F_39 ( V_6 -> V_73 , & V_72 , V_70 ) ;
if ( F_40 ( ! F_41 ( V_55 ) ) )
V_55 -> V_74 = type ;
V_6 -> V_55 [ type ] = V_55 ;
}
F_42 ( & V_6 -> V_71 ) ;
}
return V_55 ;
}
static void F_43 ( struct V_41 * V_75 , struct V_76 * V_77 ,
struct V_76 * V_78 , int V_79 ,
int V_80 , T_3 V_81 , int V_7 ,
enum V_69 V_74 , T_3 V_82 ,
int V_83 )
{
if ( V_78 != V_77 ) {
if ( V_79 )
F_44 ( V_75 , V_77 , V_79 , V_54 ) ;
F_44 ( V_75 , V_78 , V_80 , V_84 ) ;
} else {
F_44 ( V_75 , V_77 , V_79 , V_85 ) ;
}
if ( V_81 )
F_45 ( V_75 , V_81 , V_7 ,
V_74 == V_65 ? V_84 :
V_54 ) ;
if ( V_83 )
F_45 ( V_75 , V_82 , V_83 , V_54 ) ;
}
static void F_46 ( struct V_41 * V_75 ,
struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = F_47 ( V_89 ) ;
int V_7 = F_6 ( V_2 ) ;
F_43 ( V_75 , V_89 -> V_77 , V_89 -> V_78 , V_87 -> V_79 , V_87 -> V_80 ,
V_87 -> V_81 , V_7 , V_87 -> V_90 . V_55 -> V_74 ,
V_87 -> V_82 , V_87 -> V_83 ) ;
F_45 ( V_75 , V_87 -> V_91 , 4 , V_54 ) ;
}
static void F_48 ( struct V_41 * V_75 ,
struct V_92 * V_87 ,
struct V_93 * V_89 )
{
struct V_59 * V_60 = F_49 ( V_89 ) ;
int V_7 = F_27 ( V_60 ) ;
F_43 ( V_75 , V_89 -> V_77 , V_89 -> V_78 , V_87 -> V_79 , V_87 -> V_80 ,
V_87 -> V_81 , V_7 , V_87 -> V_90 . V_55 -> V_74 ,
V_87 -> V_82 , V_87 -> V_83 ) ;
}
static void F_50 ( struct V_94 * V_90 , T_1 V_95 )
{
struct V_41 * V_73 ;
struct V_86 * V_87 ;
struct V_88 * V_96 = V_90 -> V_97 ;
struct V_1 * V_2 = F_47 ( V_96 ) ;
struct V_5 * V_5 = F_5 ( V_2 ) ;
int V_98 = 0 ;
V_73 = V_5 -> V_73 ;
if ( F_36 ( V_95 ) ) {
F_51 ( V_73 , V_95 ) ;
V_98 = - V_99 ;
}
V_87 = F_2 ( V_90 , F_4 ( * V_87 ) , V_90 ) ;
F_46 ( V_73 , V_87 , V_96 ) ;
F_52 ( V_96 , V_98 ) ;
F_53 ( V_87 ) ;
}
static struct V_86 * F_54 ( struct V_88 * V_89 ,
bool V_100 )
{
struct V_1 * V_2 = F_47 ( V_89 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ,
F_4 ( * V_4 ) , V_2 ) ;
struct V_41 * V_73 = V_6 -> V_73 ;
T_4 V_101 = ( V_89 -> V_102 . V_101 & V_103 ) ?
V_104 : V_105 ;
int V_79 , V_106 , V_80 = 0 , V_107 = 0 ;
struct V_86 * V_87 ;
T_3 V_82 , V_81 = 0 ;
int V_7 = 0 ;
unsigned int V_21 = V_6 -> V_21 ;
int V_108 = 0 , V_109 = 0 , V_83 ;
int V_110 , V_111 ;
struct V_112 * V_113 , * V_114 ;
struct V_68 * V_55 ;
enum V_69 V_74 = V_100 ? V_56 : V_57 ;
V_55 = F_35 ( V_6 , V_74 ) ;
if ( F_36 ( F_41 ( V_55 ) ) )
return (struct V_86 * ) V_55 ;
V_87 = F_55 ( V_115 | V_101 ) ;
if ( F_36 ( ! V_87 ) ) {
F_16 ( V_73 , L_10 ) ;
return F_56 ( - V_116 ) ;
}
if ( F_40 ( V_89 -> V_77 == V_89 -> V_78 ) ) {
V_79 = F_57 ( V_89 -> V_77 , V_89 -> V_117 +
V_89 -> V_118 +
( V_100 ? V_21 : 0 ) ) ;
if ( F_36 ( V_79 < 0 ) ) {
F_16 ( V_73 , L_11 ,
V_89 -> V_117 + V_89 -> V_118 +
( V_100 ? V_21 : 0 ) ) ;
F_53 ( V_87 ) ;
return F_56 ( V_79 ) ;
}
V_106 = F_58 ( V_73 , V_89 -> V_77 , V_79 ,
V_85 ) ;
if ( F_36 ( ! V_106 ) ) {
F_16 ( V_73 , L_12 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
} else {
V_79 = F_57 ( V_89 -> V_77 , V_89 -> V_117 +
V_89 -> V_118 ) ;
if ( F_36 ( V_79 < 0 ) ) {
F_16 ( V_73 , L_11 ,
V_89 -> V_117 + V_89 -> V_118 ) ;
F_53 ( V_87 ) ;
return F_56 ( V_79 ) ;
}
V_80 = F_57 ( V_89 -> V_78 , V_89 -> V_117 +
V_89 -> V_118 +
( V_100 ? V_21 :
( - V_21 ) ) ) ;
if ( F_36 ( V_80 < 0 ) ) {
F_16 ( V_73 , L_13 ,
V_89 -> V_117 + V_89 -> V_118 +
( V_100 ? V_21 : ( - V_21 ) ) ) ;
F_53 ( V_87 ) ;
return F_56 ( V_80 ) ;
}
if ( V_79 ) {
V_106 = F_58 ( V_73 , V_89 -> V_77 ,
V_79 , V_54 ) ;
if ( F_36 ( ! V_106 ) ) {
F_16 ( V_73 , L_12 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
} else {
V_106 = 0 ;
}
V_107 = F_58 ( V_73 , V_89 -> V_78 , V_80 ,
V_84 ) ;
if ( F_36 ( ! V_107 ) ) {
F_16 ( V_73 , L_14 ) ;
F_44 ( V_73 , V_89 -> V_77 , V_79 , V_54 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
}
if ( ( V_4 -> V_18 . V_19 && V_100 ) || ! V_4 -> V_18 . V_26 ) {
V_7 = F_6 ( V_2 ) ;
V_81 = F_59 ( V_73 , V_89 -> V_119 , V_7 , V_54 ) ;
if ( F_60 ( V_73 , V_81 ) ) {
F_16 ( V_73 , L_15 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 ,
V_80 , 0 , 0 , V_74 , 0 , 0 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
}
V_109 = 1 + ! ! V_7 + V_106 +
( V_107 > 1 ? V_107 : 0 ) ;
V_113 = & V_87 -> V_120 [ 0 ] ;
V_83 = V_109 * sizeof( * V_113 ) ;
V_87 -> V_79 = V_79 ;
V_87 -> V_80 = V_80 ;
V_87 -> V_81 = V_81 ;
V_87 -> V_90 . V_97 = V_89 ;
V_87 -> V_90 . V_121 = F_50 ;
V_87 -> V_90 . V_55 = V_55 ;
V_87 -> V_91 = F_59 ( V_73 , & V_89 -> V_117 , 4 ,
V_54 ) ;
if ( F_60 ( V_73 , V_87 -> V_91 ) ) {
F_16 ( V_73 , L_16 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 ,
V_81 , V_7 , V_74 , 0 , 0 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
F_61 ( V_113 , V_87 -> V_91 , 4 , 0 ) ;
V_108 ++ ;
if ( V_7 ) {
F_61 ( V_113 + V_108 , V_81 , V_7 , 0 ) ;
V_108 ++ ;
}
F_62 ( V_89 -> V_77 , V_106 , V_113 + V_108 , 0 ) ;
V_108 += V_106 ;
if ( V_107 > 1 )
F_62 ( V_89 -> V_78 , V_107 , V_113 +
V_108 , 0 ) ;
V_82 = F_59 ( V_73 , V_113 , V_83 , V_54 ) ;
if ( F_60 ( V_73 , V_82 ) ) {
F_16 ( V_73 , L_17 ) ;
F_45 ( V_73 , V_87 -> V_91 , 4 , V_54 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 ,
V_81 , V_7 , V_74 , 0 , 0 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
V_87 -> V_82 = V_82 ;
V_87 -> V_83 = V_83 ;
V_111 = V_89 -> V_117 + V_89 -> V_118 +
( V_100 ? V_6 -> V_21 : ( - V_6 -> V_21 ) ) ;
V_110 = 4 + V_7 + V_89 -> V_117 + V_89 -> V_118 ;
V_114 = & V_87 -> V_90 . V_114 [ 0 ] ;
F_63 ( & V_114 [ 1 ] , V_82 , V_110 , 0 ) ;
if ( V_89 -> V_78 == V_89 -> V_77 ) {
if ( V_106 == 1 )
F_61 ( & V_114 [ 0 ] , F_64 ( V_89 -> V_77 ) ,
V_111 , 0 ) ;
else
F_65 ( & V_114 [ 0 ] , V_82 +
( 1 + ! ! V_7 ) * sizeof( * V_113 ) ,
V_111 , 0 ) ;
} else if ( V_107 == 1 ) {
F_61 ( & V_114 [ 0 ] , F_64 ( V_89 -> V_78 ) , V_111 ,
0 ) ;
} else {
F_65 ( & V_114 [ 0 ] , V_82 + sizeof( * V_113 ) *
V_108 , V_111 , 0 ) ;
}
return V_87 ;
}
static inline int F_66 ( struct V_88 * V_89 , bool V_100 )
{
struct V_86 * V_87 ;
struct V_1 * V_2 = F_47 ( V_89 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_45 ;
if ( F_36 ( V_122 ) )
return - V_123 ;
V_87 = F_54 ( V_89 , V_100 ) ;
if ( F_41 ( V_87 ) )
return F_67 ( V_87 ) ;
V_45 = F_68 ( V_6 -> V_73 , & V_87 -> V_90 ) ;
if ( ! V_45 ) {
V_45 = - V_124 ;
} else {
F_46 ( V_6 -> V_73 , V_87 , V_89 ) ;
F_53 ( V_87 ) ;
}
return V_45 ;
}
static int F_69 ( struct V_88 * V_89 )
{
return F_66 ( V_89 , true ) ;
}
static int F_70 ( struct V_88 * V_89 )
{
return F_66 ( V_89 , false ) ;
}
static void F_71 ( struct V_94 * V_90 , T_1 V_95 )
{
struct V_92 * V_87 ;
struct V_93 * V_89 = V_90 -> V_97 ;
struct V_59 * V_60 = F_49 ( V_89 ) ;
struct V_5 * V_5 = F_24 ( V_60 ) ;
struct V_41 * V_73 = V_5 -> V_73 ;
#ifdef F_15
int V_7 = F_27 ( V_60 ) ;
F_16 ( V_73 , L_18 , V_125 , __LINE__ , V_95 ) ;
#endif
V_87 = F_2 ( V_90 , F_4 ( * V_87 ) , V_90 ) ;
if ( V_95 )
F_51 ( V_73 , V_95 ) ;
#ifdef F_15
F_17 ( V_49 , L_19 F_18 ( __LINE__ ) L_3 ,
V_50 , 16 , 4 , V_89 -> V_126 ,
V_87 -> V_79 > 1 ? 100 : V_7 , 1 ) ;
F_72 ( V_49 , L_20 F_18 ( __LINE__ ) L_3 ,
V_50 , 16 , 4 , V_89 -> V_78 ,
V_87 -> V_80 > 1 ? 100 : V_89 -> V_127 , 1 ) ;
#endif
F_48 ( V_73 , V_87 , V_89 ) ;
F_53 ( V_87 ) ;
F_73 ( V_89 , V_95 ) ;
}
static struct V_92 * F_74 ( struct V_93
* V_89 , bool V_100 )
{
struct V_59 * V_60 = F_49 ( V_89 ) ;
struct V_5 * V_6 = F_24 ( V_60 ) ;
struct V_41 * V_73 = V_6 -> V_73 ;
T_4 V_101 = ( V_89 -> V_102 . V_101 & V_103 ) ?
V_104 : V_105 ;
int V_79 , V_106 , V_80 = 0 , V_107 = 0 ;
struct V_92 * V_87 ;
T_3 V_81 ;
bool V_128 ;
int V_7 = F_27 ( V_60 ) ;
int V_129 , V_109 ;
struct V_112 * V_113 , * V_114 ;
struct V_68 * V_55 ;
enum V_69 V_74 = V_100 ? V_56 : V_57 ;
V_55 = F_35 ( V_6 , V_74 ) ;
if ( F_36 ( F_41 ( V_55 ) ) )
return (struct V_92 * ) V_55 ;
V_79 = F_57 ( V_89 -> V_77 , V_89 -> V_127 ) ;
if ( F_36 ( V_79 < 0 ) ) {
F_16 ( V_73 , L_11 ,
V_89 -> V_127 ) ;
return F_56 ( V_79 ) ;
}
if ( F_36 ( V_89 -> V_77 != V_89 -> V_78 ) ) {
V_80 = F_57 ( V_89 -> V_78 , V_89 -> V_127 ) ;
if ( F_36 ( V_80 < 0 ) ) {
F_16 ( V_73 , L_13 ,
V_89 -> V_127 ) ;
return F_56 ( V_80 ) ;
}
V_106 = F_58 ( V_73 , V_89 -> V_77 , V_79 ,
V_54 ) ;
if ( F_36 ( ! V_106 ) ) {
F_16 ( V_73 , L_12 ) ;
return F_56 ( - V_116 ) ;
}
V_107 = F_58 ( V_73 , V_89 -> V_78 , V_80 ,
V_84 ) ;
if ( F_36 ( ! V_107 ) ) {
F_16 ( V_73 , L_14 ) ;
F_44 ( V_73 , V_89 -> V_77 , V_79 , V_54 ) ;
return F_56 ( - V_116 ) ;
}
} else {
V_106 = F_58 ( V_73 , V_89 -> V_77 , V_79 ,
V_85 ) ;
if ( F_36 ( ! V_106 ) ) {
F_16 ( V_73 , L_12 ) ;
return F_56 ( - V_116 ) ;
}
}
V_81 = F_59 ( V_73 , V_89 -> V_126 , V_7 , V_54 ) ;
if ( F_60 ( V_73 , V_81 ) ) {
F_16 ( V_73 , L_15 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 , 0 ,
0 , 0 , 0 , 0 ) ;
return F_56 ( - V_116 ) ;
}
if ( V_106 == 1 &&
V_81 + V_7 == F_64 ( V_89 -> V_77 ) ) {
V_128 = true ;
V_109 = 0 ;
} else {
V_128 = false ;
V_109 = 1 + V_106 ;
}
V_129 = V_109 ;
V_87 = F_55 ( V_115 | V_101 ) ;
if ( F_36 ( ! V_87 ) ) {
F_16 ( V_73 , L_10 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 ,
V_81 , V_7 , V_74 , 0 , 0 ) ;
return F_56 ( - V_116 ) ;
}
V_87 -> V_79 = V_79 ;
V_87 -> V_80 = V_80 ;
V_87 -> V_81 = V_81 ;
V_109 += V_107 > 1 ? V_107 : 0 ;
V_113 = & V_87 -> V_120 [ 0 ] ;
V_87 -> V_83 = V_109 * sizeof( * V_113 ) ;
V_87 -> V_90 . V_97 = V_89 ;
V_87 -> V_90 . V_121 = F_71 ;
V_87 -> V_90 . V_55 = V_55 ;
if ( ! V_128 ) {
F_61 ( V_113 , V_81 , V_7 , 0 ) ;
F_62 ( V_89 -> V_77 , V_106 , V_113 + 1 , 0 ) ;
}
if ( V_107 > 1 )
F_62 ( V_89 -> V_78 , V_107 , V_113 +
V_129 , 0 ) ;
V_87 -> V_82 = F_59 ( V_73 , V_113 , V_87 -> V_83 ,
V_54 ) ;
if ( F_60 ( V_73 , V_87 -> V_82 ) ) {
F_16 ( V_73 , L_17 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 ,
V_81 , V_7 , V_74 , 0 , 0 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
V_114 = & V_87 -> V_90 . V_114 [ 0 ] ;
if ( ! V_128 )
F_63 ( & V_114 [ 1 ] , V_87 -> V_82 ,
V_7 + V_89 -> V_127 , 0 ) ;
else
F_75 ( & V_114 [ 1 ] , V_81 , V_7 + V_89 -> V_127 ,
0 ) ;
if ( V_89 -> V_77 == V_89 -> V_78 ) {
if ( ! V_128 )
F_65 ( & V_114 [ 0 ] , V_87 -> V_82 +
sizeof( * V_113 ) , V_89 -> V_127 , 0 ) ;
else
F_61 ( & V_114 [ 0 ] , F_64 ( V_89 -> V_77 ) ,
V_89 -> V_127 , 0 ) ;
} else if ( V_107 > 1 ) {
F_65 ( & V_114 [ 0 ] , V_87 -> V_82 + V_129 *
sizeof( * V_113 ) , V_89 -> V_127 , 0 ) ;
} else {
F_61 ( & V_114 [ 0 ] , F_64 ( V_89 -> V_78 ) ,
V_89 -> V_127 , 0 ) ;
}
return V_87 ;
}
static struct V_92 * F_76 (
struct V_130 * V_131 )
{
struct V_93 * V_89 = & V_131 -> V_131 ;
struct V_59 * V_60 = F_49 ( V_89 ) ;
struct V_5 * V_6 = F_24 ( V_60 ) ;
struct V_41 * V_73 = V_6 -> V_73 ;
T_4 V_101 = ( V_89 -> V_102 . V_101 & V_103 ) ?
V_104 : V_105 ;
int V_79 , V_106 , V_80 , V_107 ;
struct V_92 * V_87 ;
T_3 V_81 ;
bool V_132 ;
int V_7 = F_27 ( V_60 ) ;
struct V_112 * V_113 , * V_114 ;
int V_129 , V_109 ;
struct V_68 * V_55 ;
V_55 = F_35 ( V_6 , V_65 ) ;
if ( F_36 ( F_41 ( V_55 ) ) )
return (struct V_92 * ) V_55 ;
V_79 = F_57 ( V_89 -> V_77 , V_89 -> V_127 ) ;
if ( F_36 ( V_79 < 0 ) ) {
F_16 ( V_73 , L_11 ,
V_89 -> V_127 ) ;
return F_56 ( V_79 ) ;
}
if ( F_36 ( V_89 -> V_77 != V_89 -> V_78 ) ) {
V_80 = F_57 ( V_89 -> V_78 , V_89 -> V_127 ) ;
if ( F_36 ( V_80 < 0 ) ) {
F_16 ( V_73 , L_13 ,
V_89 -> V_127 ) ;
return F_56 ( V_80 ) ;
}
V_106 = F_58 ( V_73 , V_89 -> V_77 , V_79 ,
V_54 ) ;
if ( F_36 ( ! V_106 ) ) {
F_16 ( V_73 , L_12 ) ;
return F_56 ( - V_116 ) ;
}
V_107 = F_58 ( V_73 , V_89 -> V_78 , V_80 ,
V_84 ) ;
if ( F_36 ( ! V_107 ) ) {
F_16 ( V_73 , L_14 ) ;
F_44 ( V_73 , V_89 -> V_77 , V_79 , V_54 ) ;
return F_56 ( - V_116 ) ;
}
} else {
V_106 = F_58 ( V_73 , V_89 -> V_77 , V_79 ,
V_85 ) ;
if ( F_36 ( ! V_106 ) ) {
F_16 ( V_73 , L_12 ) ;
return F_56 ( - V_116 ) ;
}
V_80 = V_79 ;
V_107 = V_79 ;
}
V_81 = F_59 ( V_73 , V_131 -> V_133 , V_7 , V_84 ) ;
if ( F_60 ( V_73 , V_81 ) ) {
F_16 ( V_73 , L_15 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 , 0 ,
0 , 0 , 0 , 0 ) ;
return F_56 ( - V_116 ) ;
}
V_109 = V_106 > 1 ? V_106 : 0 ;
V_129 = V_109 ;
if ( V_107 == 1 &&
V_81 + V_7 == F_64 ( V_89 -> V_78 ) ) {
V_132 = true ;
} else {
V_132 = false ;
V_109 += 1 + V_107 ;
}
V_87 = F_55 ( V_115 | V_101 ) ;
if ( ! V_87 ) {
F_16 ( V_73 , L_10 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 ,
V_81 , V_7 , V_65 , 0 , 0 ) ;
return F_56 ( - V_116 ) ;
}
V_87 -> V_79 = V_79 ;
V_87 -> V_80 = V_80 ;
V_87 -> V_81 = V_81 ;
V_113 = & V_87 -> V_120 [ 0 ] ;
V_87 -> V_83 = V_109 * sizeof( * V_113 ) ;
V_87 -> V_90 . V_97 = V_89 ;
V_87 -> V_90 . V_121 = F_71 ;
V_87 -> V_90 . V_55 = V_55 ;
if ( V_106 > 1 )
F_62 ( V_89 -> V_77 , V_106 , V_113 , 0 ) ;
if ( ! V_132 ) {
F_61 ( V_113 + V_129 , V_81 , V_7 , 0 ) ;
F_62 ( V_89 -> V_78 , V_107 , V_113 +
V_129 + 1 , 0 ) ;
}
V_87 -> V_82 = F_59 ( V_73 , V_113 , V_87 -> V_83 ,
V_54 ) ;
if ( F_60 ( V_73 , V_87 -> V_82 ) ) {
F_16 ( V_73 , L_17 ) ;
F_43 ( V_73 , V_89 -> V_77 , V_89 -> V_78 , V_79 , V_80 ,
V_81 , V_7 , V_65 , 0 , 0 ) ;
F_53 ( V_87 ) ;
return F_56 ( - V_116 ) ;
}
V_114 = & V_87 -> V_90 . V_114 [ 0 ] ;
if ( V_106 > 1 )
F_65 ( & V_114 [ 1 ] , V_87 -> V_82 , V_89 -> V_127 ,
0 ) ;
else
F_61 ( & V_114 [ 1 ] , F_64 ( V_89 -> V_77 ) ,
V_89 -> V_127 , 0 ) ;
if ( ! V_132 )
F_65 ( & V_114 [ 0 ] , V_87 -> V_82 + V_129 *
sizeof( * V_113 ) , V_7 + V_89 -> V_127 ,
0 ) ;
else
F_61 ( & V_114 [ 0 ] , F_64 ( V_89 -> V_78 ) ,
V_7 + V_89 -> V_127 , 0 ) ;
return V_87 ;
}
static inline int F_77 ( struct V_93 * V_89 , bool V_100 )
{
struct V_92 * V_87 ;
struct V_59 * V_60 = F_49 ( V_89 ) ;
struct V_5 * V_6 = F_24 ( V_60 ) ;
int V_45 ;
if ( F_36 ( V_122 ) )
return - V_123 ;
V_87 = F_74 ( V_89 , V_100 ) ;
if ( F_78 ( V_87 ) )
return F_67 ( V_87 ) ;
V_45 = F_68 ( V_6 -> V_73 , & V_87 -> V_90 ) ;
if ( ! V_45 ) {
V_45 = - V_124 ;
} else {
F_48 ( V_6 -> V_73 , V_87 , V_89 ) ;
F_53 ( V_87 ) ;
}
return V_45 ;
}
static int F_79 ( struct V_93 * V_89 )
{
return F_77 ( V_89 , true ) ;
}
static int F_80 ( struct V_93 * V_89 )
{
return F_77 ( V_89 , false ) ;
}
static int F_81 ( struct V_130 * V_131 )
{
struct V_93 * V_89 = & V_131 -> V_131 ;
struct V_92 * V_87 ;
struct V_59 * V_60 = F_49 ( V_89 ) ;
struct V_5 * V_6 = F_24 ( V_60 ) ;
int V_45 ;
if ( F_36 ( V_122 ) )
return - V_123 ;
V_87 = F_76 ( V_131 ) ;
if ( F_78 ( V_87 ) )
return F_67 ( V_87 ) ;
V_45 = F_68 ( V_6 -> V_73 , & V_87 -> V_90 ) ;
if ( ! V_45 ) {
V_45 = - V_124 ;
} else {
F_48 ( V_6 -> V_73 , V_87 , V_89 ) ;
F_53 ( V_87 ) ;
}
return V_45 ;
}
static int F_82 ( struct V_5 * V_6 , struct V_134 * V_18 )
{
struct V_135 * V_136 ;
V_6 -> V_42 = F_83 () ;
if ( F_78 ( V_6 -> V_42 ) ) {
F_84 ( L_21 ) ;
return F_67 ( V_6 -> V_42 ) ;
}
V_6 -> V_33 = F_59 ( V_6 -> V_42 , V_6 -> V_23 , sizeof( V_6 -> V_23 ) ,
V_54 ) ;
if ( F_60 ( V_6 -> V_42 , V_6 -> V_33 ) ) {
F_16 ( V_6 -> V_42 , L_22 ) ;
F_85 ( V_6 -> V_42 ) ;
return - V_116 ;
}
V_6 -> V_13 . V_14 = V_137 | V_18 -> V_138 ;
V_6 -> V_24 . V_14 = V_139 | V_18 -> V_140 ;
V_136 = F_86 ( V_6 -> V_42 -> V_141 ) ;
V_6 -> V_73 = V_136 -> V_73 ;
F_87 ( & V_6 -> V_71 ) ;
V_6 -> V_55 [ V_56 ] = NULL ;
V_6 -> V_55 [ V_57 ] = NULL ;
V_6 -> V_55 [ V_65 ] = NULL ;
return 0 ;
}
static int F_88 ( struct V_61 * V_62 )
{
struct V_142 * V_4 = V_62 -> V_143 ;
struct V_144 * V_145 = F_2 ( V_4 , F_4 ( * V_145 ) ,
V_142 ) ;
struct V_5 * V_6 = F_89 ( V_62 ) ;
return F_82 ( V_6 , & V_145 -> V_18 ) ;
}
static int F_90 ( struct V_1 * V_62 )
{
struct V_146 * V_4 = F_3 ( V_62 ) ;
struct V_3 * V_145 = F_2 ( V_4 , F_4 ( * V_145 ) ,
V_2 ) ;
struct V_5 * V_6 = F_5 ( V_62 ) ;
return F_82 ( V_6 , & V_145 -> V_18 ) ;
}
static void F_91 ( struct V_5 * V_6 )
{
F_92 ( V_6 -> V_55 [ V_56 ] ) ;
F_92 ( V_6 -> V_55 [ V_57 ] ) ;
F_92 ( V_6 -> V_55 [ V_65 ] ) ;
F_45 ( V_6 -> V_42 , V_6 -> V_33 , sizeof( V_6 -> V_23 ) ,
V_54 ) ;
F_85 ( V_6 -> V_42 ) ;
}
static void F_93 ( struct V_61 * V_62 )
{
F_91 ( F_89 ( V_62 ) ) ;
}
static void F_94 ( struct V_1 * V_62 )
{
F_91 ( F_5 ( V_62 ) ) ;
}
static void T_5 F_95 ( void )
{
struct V_144 * V_147 , * V_148 ;
int V_149 ;
for ( V_149 = 0 ; V_149 < F_8 ( V_150 ) ; V_149 ++ ) {
struct V_3 * V_147 = V_150 + V_149 ;
if ( V_147 -> V_151 )
F_96 ( & V_147 -> V_2 ) ;
}
if ( ! V_152 . V_153 )
return;
F_97 (t_alg, n, &alg_list, entry) {
F_98 ( & V_147 -> V_142 ) ;
F_99 ( & V_147 -> V_154 ) ;
F_100 ( V_147 ) ;
}
}
static struct V_144 * F_101 ( struct V_155
* V_156 )
{
struct V_144 * V_147 ;
struct V_142 * V_4 ;
V_147 = F_102 ( sizeof( * V_147 ) , V_104 ) ;
if ( ! V_147 )
return F_56 ( - V_116 ) ;
V_4 = & V_147 -> V_142 ;
snprintf ( V_4 -> V_157 , V_158 , L_23 , V_156 -> V_159 ) ;
snprintf ( V_4 -> V_160 , V_158 , L_23 ,
V_156 -> V_161 ) ;
V_4 -> V_162 = V_163 ;
V_4 -> V_164 = F_88 ;
V_4 -> V_165 = F_93 ;
V_4 -> V_166 = V_167 ;
V_4 -> V_168 = V_156 -> V_169 ;
V_4 -> V_170 = 0 ;
V_4 -> V_171 = sizeof( struct V_5 ) ;
V_4 -> V_172 = V_173 | V_174 |
V_156 -> type ;
switch ( V_156 -> type ) {
case V_175 :
V_4 -> V_176 = & V_177 ;
V_4 -> V_178 = V_156 -> V_179 ;
break;
case V_180 :
V_4 -> V_176 = & V_181 ;
V_4 -> V_178 = V_156 -> V_179 ;
break;
}
V_147 -> V_18 . V_138 = V_156 -> V_138 ;
V_147 -> V_18 . V_140 = V_156 -> V_140 ;
return V_147 ;
}
static void F_103 ( struct V_3 * V_147 )
{
struct V_146 * V_4 = & V_147 -> V_2 ;
V_4 -> V_102 . V_162 = V_163 ;
V_4 -> V_102 . V_166 = V_167 ;
V_4 -> V_102 . V_171 = sizeof( struct V_5 ) ;
V_4 -> V_102 . V_172 = V_173 | V_174 ;
V_4 -> V_182 = F_90 ;
V_4 -> exit = F_94 ;
}
static int T_6 F_104 ( void )
{
struct V_183 * V_184 ;
struct V_185 * V_186 ;
struct V_41 * V_187 ;
struct V_135 * V_136 ;
int V_149 = 0 , V_188 = 0 ;
T_1 V_189 , V_190 , V_191 , V_192 , V_193 ;
unsigned int V_194 = V_195 ;
bool V_151 = false ;
V_184 = F_105 ( NULL , NULL , L_24 ) ;
if ( ! V_184 ) {
V_184 = F_105 ( NULL , NULL , L_25 ) ;
if ( ! V_184 )
return - V_196 ;
}
V_186 = F_106 ( V_184 ) ;
F_107 ( V_184 ) ;
if ( ! V_186 )
return - V_196 ;
V_187 = & V_186 -> V_75 ;
V_136 = F_86 ( V_187 ) ;
if ( ! V_136 || ! V_136 -> V_197 )
return - V_196 ;
F_108 ( & V_152 ) ;
V_189 = F_109 ( & V_136 -> V_198 -> V_199 . V_200 ) ;
V_190 = F_109 ( & V_136 -> V_198 -> V_199 . V_201 ) ;
V_191 = ( V_190 & V_202 ) >> V_203 ;
V_192 = ( V_190 & V_204 ) >> V_205 ;
V_193 = ( V_190 & V_206 ) >> V_207 ;
if ( V_193 && ( ( V_189 & V_206 ) == V_208 ) )
V_194 = V_209 ;
for ( V_149 = 0 ; V_149 < F_8 ( V_210 ) ; V_149 ++ ) {
struct V_144 * V_147 ;
struct V_155 * V_4 = V_210 + V_149 ;
T_1 V_211 = V_4 -> V_138 & V_212 ;
if ( ! V_191 &&
( ( V_211 == V_213 ) ||
( V_211 == V_214 ) ) )
continue;
if ( ! V_192 && ( V_211 == V_215 ) )
continue;
V_147 = F_101 ( V_4 ) ;
if ( F_78 ( V_147 ) ) {
V_188 = F_67 ( V_147 ) ;
F_110 ( V_136 -> V_73 , L_26 ,
V_4 -> V_161 ) ;
continue;
}
V_188 = F_111 ( & V_147 -> V_142 ) ;
if ( V_188 ) {
F_110 ( V_136 -> V_73 , L_27 ,
V_147 -> V_142 . V_160 ) ;
F_100 ( V_147 ) ;
continue;
}
F_112 ( & V_147 -> V_154 , & V_152 ) ;
V_151 = true ;
}
for ( V_149 = 0 ; V_149 < F_8 ( V_150 ) ; V_149 ++ ) {
struct V_3 * V_147 = V_150 + V_149 ;
T_1 V_216 = V_147 -> V_18 . V_138 &
V_212 ;
T_1 V_217 = V_147 -> V_18 . V_140 &
V_212 ;
T_1 V_218 = V_147 -> V_18 . V_138 & V_15 ;
if ( ! V_191 &&
( ( V_216 == V_213 ) ||
( V_216 == V_214 ) ) )
continue;
if ( ! V_192 && ( V_216 == V_215 ) )
continue;
if ( ( ( V_189 & V_204 ) == V_219 ) &&
( V_218 == V_220 ) )
continue;
if ( V_217 &&
( ! V_193 || ( V_147 -> V_2 . V_221 > V_194 ) ) )
continue;
F_103 ( V_147 ) ;
V_188 = F_113 ( & V_147 -> V_2 ) ;
if ( V_188 ) {
F_114 ( L_27 ,
V_147 -> V_2 . V_102 . V_160 ) ;
continue;
}
V_147 -> V_151 = true ;
V_151 = true ;
}
if ( V_151 )
F_115 ( V_136 -> V_73 , L_28 ) ;
return V_188 ;
}
