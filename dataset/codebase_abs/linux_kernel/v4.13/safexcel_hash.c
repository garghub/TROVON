static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 . V_6 ;
V_6 [ 0 ] . V_8 = V_9 ;
V_6 [ 0 ] . V_10 = V_3 ;
V_6 [ 0 ] . V_11 = V_12 ;
V_6 [ 0 ] . V_13 = V_14 ;
V_6 [ 1 ] . V_8 = V_15 ;
V_6 [ 1 ] . V_10 = V_4 ;
V_6 [ 1 ] . V_11 = V_12 |
V_16 ;
V_6 [ 1 ] . V_13 = V_17 |
V_18 ;
}
static void F_2 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_1 * V_2 ,
unsigned int V_23 ,
unsigned int V_24 )
{
int V_25 ;
V_2 -> V_7 . V_26 |= V_27 ;
V_2 -> V_7 . V_26 |= V_20 -> V_28 ;
V_2 -> V_7 . V_26 |= V_20 -> V_29 ;
if ( V_20 -> V_29 == V_30 ) {
if ( V_22 -> V_31 ) {
if ( V_20 -> V_28 == V_32 )
V_2 -> V_7 . V_26 |= F_3 ( 6 ) ;
else if ( V_20 -> V_28 == V_33 ||
V_20 -> V_28 == V_34 )
V_2 -> V_7 . V_26 |= F_3 ( 9 ) ;
V_2 -> V_7 . V_35 |= V_36 ;
} else {
V_2 -> V_7 . V_26 |= V_37 ;
}
if ( ! V_22 -> V_38 )
V_2 -> V_7 . V_26 |= V_39 ;
if ( V_22 -> V_31 ) {
for ( V_25 = 0 ; V_25 < V_23 / sizeof( T_1 ) ; V_25 ++ )
V_20 -> V_40 . V_41 -> V_42 [ V_25 ] = F_4 ( V_22 -> V_43 [ V_25 ] ) ;
if ( V_22 -> V_38 )
V_20 -> V_40 . V_41 -> V_42 [ V_25 ] = F_4 ( V_22 -> V_31 / V_24 ) ;
}
} else if ( V_20 -> V_29 == V_44 ) {
V_2 -> V_7 . V_26 |= F_3 ( 10 ) ;
memcpy ( V_20 -> V_40 . V_41 -> V_42 , V_20 -> V_45 , V_23 ) ;
memcpy ( V_20 -> V_40 . V_41 -> V_42 + V_23 / sizeof( T_1 ) ,
V_20 -> V_46 , V_23 ) ;
}
}
static int F_5 ( struct V_47 * V_48 , int V_49 ,
struct V_50 * V_51 ,
bool * V_52 , int * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 = F_6 ( V_51 ) ;
struct V_58 * V_59 = F_7 ( V_57 ) ;
struct V_21 * V_60 = F_8 ( V_57 ) ;
int V_61 , V_62 = V_60 -> V_63 ;
* V_53 = 0 ;
F_9 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
V_55 = F_10 ( V_48 , & V_48 -> V_49 [ V_49 ] . V_65 ) ;
if ( F_11 ( V_55 ) ) {
F_12 ( V_48 -> V_66 ,
L_1 ) ;
* V_53 = F_13 ( V_55 ) ;
} else if ( V_55 -> V_67 . V_68 ) {
F_12 ( V_48 -> V_66 ,
L_2 ,
V_55 -> V_67 . V_68 ) ;
* V_53 = - V_69 ;
}
F_14 ( V_48 , V_49 ) ;
F_15 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
if ( V_60 -> V_38 )
V_62 = F_16 ( V_59 ) ;
memcpy ( V_60 -> V_43 , V_57 -> V_70 , V_62 ) ;
F_17 ( V_48 -> V_66 , V_57 -> V_71 ,
F_18 ( V_57 -> V_71 , V_57 -> V_72 ) , V_73 ) ;
F_19 ( V_48 , V_51 , V_60 -> V_63 ) ;
V_61 = V_60 -> V_74 - V_60 -> V_31 ;
if ( V_61 )
memcpy ( V_60 -> V_75 , V_60 -> V_76 , V_61 ) ;
* V_52 = true ;
return 1 ;
}
static int F_20 ( struct V_50 * V_51 , int V_49 ,
struct V_77 * V_78 , int * V_79 ,
int * V_80 )
{
struct V_56 * V_57 = F_6 ( V_51 ) ;
struct V_58 * V_59 = F_7 ( V_57 ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_47 * V_48 = V_20 -> V_48 ;
struct V_1 * V_2 , * V_81 = NULL ;
struct V_54 * V_55 ;
struct V_82 * V_83 ;
int V_25 , V_84 , V_85 , V_74 , V_61 , V_86 , V_87 = 0 , V_53 = 0 ;
V_85 = V_74 = V_22 -> V_74 - V_22 -> V_31 ;
if ( V_85 < F_22 ( V_59 ) )
V_61 = V_85 ;
else
V_61 = V_85 - V_57 -> V_72 ;
V_86 = V_85 & ( F_22 ( V_59 ) - 1 ) ;
if ( ! V_22 -> V_88 && V_86 ) {
F_23 ( V_57 -> V_71 , F_24 ( V_57 -> V_71 ) ,
V_22 -> V_76 , V_86 , V_57 -> V_72 - V_86 ) ;
V_85 -= V_86 ;
V_74 -= V_86 ;
}
F_9 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
if ( V_61 ) {
V_20 -> V_40 . V_75 = F_25 ( V_61 , F_26 ( * V_51 ) ) ;
if ( ! V_20 -> V_40 . V_75 ) {
V_53 = - V_89 ;
goto V_90;
}
memcpy ( V_20 -> V_40 . V_75 , V_22 -> V_75 , V_61 ) ;
V_20 -> V_40 . V_91 = F_27 ( V_48 -> V_66 , V_20 -> V_40 . V_75 ,
V_61 , V_73 ) ;
if ( F_28 ( V_48 -> V_66 , V_20 -> V_40 . V_91 ) ) {
V_53 = - V_69 ;
goto V_92;
}
V_20 -> V_40 . V_93 = V_61 ;
V_81 = F_29 ( V_48 , V_49 , 1 ,
( V_61 == V_74 ) ,
V_20 -> V_40 . V_91 ,
V_61 , V_74 ,
V_20 -> V_40 . V_94 ) ;
if ( F_11 ( V_81 ) ) {
V_53 = F_13 ( V_81 ) ;
goto V_95;
}
V_87 ++ ;
V_85 -= V_61 ;
if ( ! V_85 )
goto V_96;
}
V_84 = F_30 ( V_48 -> V_66 , V_57 -> V_71 ,
F_18 ( V_57 -> V_71 , V_57 -> V_72 ) ,
V_73 ) ;
if ( ! V_84 ) {
V_53 = - V_89 ;
goto V_97;
}
F_31 (areq->src, sg, nents, i) {
int V_98 = F_32 ( V_83 ) ;
if ( V_85 - V_98 < 0 )
V_98 = V_85 ;
V_2 = F_29 ( V_48 , V_49 , ! V_87 ,
! ( V_85 - V_98 ) , F_33 ( V_83 ) ,
V_98 , V_74 , V_20 -> V_40 . V_94 ) ;
if ( F_11 ( V_2 ) ) {
V_53 = F_13 ( V_2 ) ;
goto V_97;
}
V_87 ++ ;
if ( V_87 == 1 )
V_81 = V_2 ;
V_85 -= V_98 ;
if ( ! V_85 )
break;
}
V_96:
F_2 ( V_20 , V_22 , V_81 , V_22 -> V_63 ,
F_22 ( V_59 ) ) ;
F_1 ( V_81 , V_74 , V_22 -> V_63 ) ;
V_20 -> V_40 . V_99 = F_27 ( V_48 -> V_66 , V_57 -> V_70 ,
V_22 -> V_63 , V_100 ) ;
if ( F_28 ( V_48 -> V_66 , V_20 -> V_40 . V_99 ) ) {
V_53 = - V_69 ;
goto V_97;
}
V_55 = F_34 ( V_48 , V_49 , 1 , 1 , V_20 -> V_40 . V_99 ,
V_22 -> V_63 ) ;
if ( F_11 ( V_55 ) ) {
V_53 = F_13 ( V_55 ) ;
goto V_97;
}
F_15 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
V_22 -> V_31 += V_74 ;
V_78 -> V_22 = & V_57 -> V_40 ;
V_20 -> V_40 . V_101 = F_5 ;
* V_79 = V_87 ;
* V_80 = 1 ;
return 0 ;
V_97:
for ( V_25 = 0 ; V_25 < V_87 ; V_25 ++ )
F_35 ( V_48 , & V_48 -> V_49 [ V_49 ] . V_102 ) ;
V_95:
if ( V_20 -> V_40 . V_91 ) {
F_36 ( V_48 -> V_66 , V_20 -> V_40 . V_91 ,
V_20 -> V_40 . V_93 , V_73 ) ;
V_20 -> V_40 . V_93 = 0 ;
}
V_92:
if ( V_20 -> V_40 . V_75 ) {
F_37 ( V_20 -> V_40 . V_75 ) ;
V_20 -> V_40 . V_75 = NULL ;
}
V_90:
F_15 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
return V_53 ;
}
static inline bool F_38 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_58 * V_59 = F_7 ( V_57 ) ;
unsigned int V_103 = V_22 -> V_63 / sizeof( T_1 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_103 ; V_25 ++ )
if ( V_20 -> V_40 . V_41 -> V_42 [ V_25 ] != F_4 ( V_22 -> V_43 [ V_25 ] ) )
return true ;
if ( V_20 -> V_40 . V_41 -> V_42 [ V_103 ] !=
F_4 ( V_22 -> V_31 / F_22 ( V_59 ) ) )
return true ;
return false ;
}
static int F_39 ( struct V_47 * V_48 ,
int V_49 ,
struct V_50 * V_51 ,
bool * V_52 , int * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 = F_6 ( V_51 ) ;
struct V_58 * V_59 = F_7 ( V_57 ) ;
struct V_19 * V_20 = F_21 ( V_59 ) ;
int V_104 ;
* V_53 = 0 ;
F_9 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
V_55 = F_10 ( V_48 , & V_48 -> V_49 [ V_49 ] . V_65 ) ;
if ( F_11 ( V_55 ) ) {
F_12 ( V_48 -> V_66 ,
L_3 ) ;
* V_53 = F_13 ( V_55 ) ;
} else if ( V_55 -> V_67 . V_68 ) {
F_12 ( V_48 -> V_66 ,
L_4 ,
V_55 -> V_67 . V_68 ) ;
* V_53 = - V_69 ;
}
F_14 ( V_48 , V_49 ) ;
F_15 ( & V_48 -> V_49 [ V_49 ] . V_64 ) ;
if ( V_20 -> V_40 . V_105 ) {
F_40 ( V_48 -> V_106 , V_20 -> V_40 . V_41 ,
V_20 -> V_40 . V_94 ) ;
* V_52 = true ;
return 1 ;
}
V_49 = F_41 ( V_48 ) ;
V_20 -> V_40 . V_49 = V_49 ;
V_20 -> V_40 . V_107 = false ;
V_20 -> V_40 . V_108 = F_20 ;
F_9 ( & V_48 -> V_49 [ V_49 ] . V_109 ) ;
V_104 = F_42 ( & V_48 -> V_49 [ V_49 ] . V_110 , V_51 ) ;
F_15 ( & V_48 -> V_49 [ V_49 ] . V_109 ) ;
if ( V_104 != - V_111 )
* V_53 = V_104 ;
if ( ! V_48 -> V_49 [ V_49 ] . V_112 )
F_43 ( V_48 , V_49 ) ;
* V_52 = false ;
return 1 ;
}
static int F_44 ( struct V_50 * V_51 ,
int V_49 , struct V_77 * V_78 ,
int * V_79 , int * V_80 )
{
struct V_56 * V_57 = F_6 ( V_51 ) ;
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
int V_53 ;
V_20 -> V_40 . V_101 = F_39 ;
V_53 = F_45 ( V_51 , & V_20 -> V_40 , V_20 -> V_48 ,
V_20 -> V_40 . V_94 , V_49 , V_78 ) ;
if ( F_46 ( V_53 ) )
return V_53 ;
* V_79 = 1 ;
* V_80 = 1 ;
return 0 ;
}
static int F_47 ( struct V_113 * V_114 )
{
struct V_19 * V_20 = F_48 ( V_114 ) ;
struct V_47 * V_48 = V_20 -> V_48 ;
struct V_56 V_22 ;
struct V_115 V_70 = { 0 } ;
int V_49 = V_20 -> V_40 . V_49 ;
memset ( & V_22 , 0 , sizeof( struct V_56 ) ) ;
F_49 ( & V_70 . V_116 ) ;
F_50 ( & V_22 , V_117 ,
V_118 , & V_70 ) ;
F_51 ( & V_22 , F_52 ( V_114 ) ) ;
V_20 = F_48 ( V_22 . V_40 . V_114 ) ;
V_20 -> V_40 . V_105 = true ;
V_20 -> V_40 . V_108 = F_44 ;
F_9 ( & V_48 -> V_49 [ V_49 ] . V_109 ) ;
F_42 ( & V_48 -> V_49 [ V_49 ] . V_110 , & V_22 . V_40 ) ;
F_15 ( & V_48 -> V_49 [ V_49 ] . V_109 ) ;
if ( ! V_48 -> V_49 [ V_49 ] . V_112 )
F_43 ( V_48 , V_49 ) ;
F_53 ( & V_70 . V_116 ) ;
if ( V_70 . error ) {
F_54 ( V_48 -> V_66 , L_5 ,
V_70 . error ) ;
return V_70 . error ;
}
return 0 ;
}
static int F_55 ( struct V_56 * V_57 )
{
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_58 * V_59 = F_7 ( V_57 ) ;
int V_85 , V_61 ;
V_61 = V_22 -> V_74 - V_57 -> V_72 - V_22 -> V_31 ;
V_85 = V_22 -> V_74 - V_22 -> V_31 ;
if ( V_61 + V_57 -> V_72 <= F_22 ( V_59 ) ) {
F_23 ( V_57 -> V_71 , F_24 ( V_57 -> V_71 ) ,
V_22 -> V_75 + V_61 ,
V_57 -> V_72 , 0 ) ;
return V_57 -> V_72 ;
}
return - V_119 ;
}
static int F_56 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_47 * V_48 = V_20 -> V_48 ;
int V_53 , V_49 ;
V_20 -> V_40 . V_108 = F_20 ;
if ( V_22 -> V_31 && V_20 -> V_29 == V_30 )
V_20 -> V_40 . V_107 = F_38 ( V_57 ) ;
if ( V_20 -> V_40 . V_41 ) {
if ( V_20 -> V_40 . V_107 )
V_20 -> V_40 . V_108 = F_44 ;
} else {
V_20 -> V_40 . V_49 = F_41 ( V_48 ) ;
V_20 -> V_40 . V_41 = F_57 ( V_48 -> V_106 ,
F_26 ( V_57 -> V_40 ) ,
& V_20 -> V_40 . V_94 ) ;
if ( ! V_20 -> V_40 . V_41 )
return - V_89 ;
}
V_49 = V_20 -> V_40 . V_49 ;
F_9 ( & V_48 -> V_49 [ V_49 ] . V_109 ) ;
V_53 = F_42 ( & V_48 -> V_49 [ V_49 ] . V_110 , & V_57 -> V_40 ) ;
F_15 ( & V_48 -> V_49 [ V_49 ] . V_109 ) ;
if ( ! V_48 -> V_49 [ V_49 ] . V_112 )
F_43 ( V_48 , V_49 ) ;
return V_53 ;
}
static int F_58 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_58 * V_59 = F_7 ( V_57 ) ;
if ( ! V_57 -> V_72 )
return 0 ;
V_22 -> V_74 += V_57 -> V_72 ;
F_55 ( V_57 ) ;
if ( V_20 -> V_29 == V_44 )
return 0 ;
if ( V_22 -> V_120 )
return F_56 ( V_57 ) ;
if ( ! V_22 -> V_88 &&
V_22 -> V_74 - V_22 -> V_31 > F_22 ( V_59 ) )
return F_56 ( V_57 ) ;
return 0 ;
}
static int F_59 ( struct V_56 * V_57 )
{
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
V_22 -> V_88 = true ;
V_22 -> V_38 = true ;
if ( ! ( V_22 -> V_74 + V_57 -> V_72 ) ) {
if ( V_20 -> V_28 == V_32 )
memcpy ( V_57 -> V_70 , V_121 ,
V_122 ) ;
else if ( V_20 -> V_28 == V_33 )
memcpy ( V_57 -> V_70 , V_123 ,
V_124 ) ;
else if ( V_20 -> V_28 == V_34 )
memcpy ( V_57 -> V_70 , V_125 ,
V_126 ) ;
return 0 ;
}
return F_56 ( V_57 ) ;
}
static int F_60 ( struct V_56 * V_57 )
{
struct V_21 * V_22 = F_8 ( V_57 ) ;
V_22 -> V_88 = true ;
V_22 -> V_38 = true ;
F_58 ( V_57 ) ;
return F_59 ( V_57 ) ;
}
static int F_61 ( struct V_56 * V_57 , void * V_127 )
{
struct V_58 * V_59 = F_7 ( V_57 ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
struct V_128 * V_129 = V_127 ;
V_129 -> V_74 = V_22 -> V_74 ;
V_129 -> V_31 = V_22 -> V_31 ;
memcpy ( V_129 -> V_43 , V_22 -> V_43 , V_22 -> V_63 ) ;
memset ( V_129 -> V_75 , 0 , F_22 ( V_59 ) ) ;
memcpy ( V_129 -> V_75 , V_22 -> V_75 , F_22 ( V_59 ) ) ;
return 0 ;
}
static int F_62 ( struct V_56 * V_57 , const void * V_130 )
{
struct V_58 * V_59 = F_7 ( V_57 ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
const struct V_128 * V_129 = V_130 ;
int V_53 ;
V_53 = F_63 ( V_57 ) ;
if ( V_53 )
return V_53 ;
V_22 -> V_74 = V_129 -> V_74 ;
V_22 -> V_31 = V_129 -> V_31 ;
memcpy ( V_22 -> V_75 , V_129 -> V_75 , F_22 ( V_59 ) ) ;
memcpy ( V_22 -> V_43 , V_129 -> V_43 , V_22 -> V_63 ) ;
return 0 ;
}
static int F_64 ( struct V_113 * V_114 )
{
struct V_19 * V_20 = F_48 ( V_114 ) ;
struct V_131 * V_132 =
F_65 ( F_66 ( V_114 -> V_133 ) ,
struct V_131 , V_28 . V_59 ) ;
V_20 -> V_48 = V_132 -> V_48 ;
F_67 ( F_52 ( V_114 ) ,
sizeof( struct V_21 ) ) ;
return 0 ;
}
static int F_68 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_43 [ 0 ] = V_134 ;
V_22 -> V_43 [ 1 ] = V_135 ;
V_22 -> V_43 [ 2 ] = V_136 ;
V_22 -> V_43 [ 3 ] = V_137 ;
V_22 -> V_43 [ 4 ] = V_138 ;
V_20 -> V_28 = V_32 ;
V_20 -> V_29 = V_30 ;
V_22 -> V_63 = V_122 ;
return 0 ;
}
static int F_69 ( struct V_56 * V_57 )
{
int V_53 = F_68 ( V_57 ) ;
if ( V_53 )
return V_53 ;
return F_60 ( V_57 ) ;
}
static void F_70 ( struct V_113 * V_114 )
{
struct V_19 * V_20 = F_48 ( V_114 ) ;
struct V_47 * V_48 = V_20 -> V_48 ;
int V_53 ;
if ( ! V_20 -> V_40 . V_41 )
return;
V_53 = F_47 ( V_114 ) ;
if ( V_53 )
F_54 ( V_48 -> V_66 , L_6 , V_53 ) ;
}
static int F_71 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
F_68 ( V_57 ) ;
V_20 -> V_29 = V_44 ;
return 0 ;
}
static int F_72 ( struct V_56 * V_57 )
{
int V_53 = F_71 ( V_57 ) ;
if ( V_53 )
return V_53 ;
return F_60 ( V_57 ) ;
}
static void F_73 ( struct V_50 * V_22 , int error )
{
struct V_139 * V_70 = V_22 -> V_42 ;
if ( error == - V_111 )
return;
V_70 -> error = error ;
F_74 ( & V_70 -> V_116 ) ;
}
static int F_75 ( struct V_56 * V_57 ,
unsigned int V_24 , const T_2 * V_140 ,
unsigned int V_141 , T_2 * V_45 , T_2 * V_46 )
{
struct V_139 V_70 ;
struct V_82 V_83 ;
int V_53 , V_25 ;
T_2 * V_142 ;
if ( V_141 <= V_24 ) {
memcpy ( V_45 , V_140 , V_141 ) ;
} else {
V_142 = F_76 ( V_140 , V_141 , V_143 ) ;
if ( ! V_142 )
return - V_89 ;
F_50 ( V_57 , V_117 ,
F_73 , & V_70 ) ;
F_77 ( & V_83 , V_142 , V_141 ) ;
F_78 ( V_57 , & V_83 , V_45 , V_141 ) ;
F_49 ( & V_70 . V_116 ) ;
V_53 = F_79 ( V_57 ) ;
if ( V_53 == - V_111 ) {
F_53 ( & V_70 . V_116 ) ;
V_53 = V_70 . error ;
}
F_80 ( V_142 , V_141 ) ;
F_37 ( V_142 ) ;
if ( V_53 )
return V_53 ;
V_141 = F_16 ( F_7 ( V_57 ) ) ;
}
memset ( V_45 + V_141 , 0 , V_24 - V_141 ) ;
memcpy ( V_46 , V_45 , V_24 ) ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
V_45 [ V_25 ] ^= V_144 ;
V_46 [ V_25 ] ^= V_145 ;
}
return 0 ;
}
static int F_81 ( struct V_56 * V_57 ,
unsigned int V_24 , T_2 * V_146 , void * V_43 )
{
struct V_139 V_70 ;
struct V_21 * V_22 ;
struct V_82 V_83 ;
int V_53 ;
F_50 ( V_57 , V_117 ,
F_73 , & V_70 ) ;
F_77 ( & V_83 , V_146 , V_24 ) ;
F_78 ( V_57 , & V_83 , V_146 , V_24 ) ;
F_49 ( & V_70 . V_116 ) ;
V_53 = F_63 ( V_57 ) ;
if ( V_53 )
return V_53 ;
V_22 = F_8 ( V_57 ) ;
V_22 -> V_120 = true ;
V_22 -> V_88 = true ;
V_53 = F_82 ( V_57 ) ;
if ( V_53 && V_53 != - V_111 )
return V_53 ;
F_53 ( & V_70 . V_116 ) ;
if ( V_70 . error )
return V_70 . error ;
return F_83 ( V_57 , V_43 ) ;
}
static int F_84 ( const char * V_28 , const T_2 * V_140 ,
unsigned int V_141 , void * V_147 , void * V_148 )
{
struct V_56 * V_57 ;
struct V_58 * V_114 ;
unsigned int V_24 ;
T_2 * V_45 , * V_46 ;
int V_53 ;
V_114 = F_85 ( V_28 , V_149 ,
V_150 ) ;
if ( F_11 ( V_114 ) )
return F_13 ( V_114 ) ;
V_57 = F_86 ( V_114 , V_143 ) ;
if ( ! V_57 ) {
V_53 = - V_89 ;
goto V_151;
}
F_87 ( V_114 , ~ 0 ) ;
V_24 = F_88 ( F_89 ( V_114 ) ) ;
V_45 = F_25 ( 2 * V_24 , V_143 ) ;
if ( ! V_45 ) {
V_53 = - V_89 ;
goto V_152;
}
V_46 = V_45 + V_24 ;
V_53 = F_75 ( V_57 , V_24 , V_140 , V_141 , V_45 , V_46 ) ;
if ( V_53 )
goto V_153;
V_53 = F_81 ( V_57 , V_24 , V_45 , V_147 ) ;
if ( V_53 )
goto V_153;
V_53 = F_81 ( V_57 , V_24 , V_46 , V_148 ) ;
V_153:
F_37 ( V_45 ) ;
V_152:
F_90 ( V_57 ) ;
V_151:
F_91 ( V_114 ) ;
return V_53 ;
}
static int F_92 ( struct V_58 * V_114 , const T_2 * V_140 ,
unsigned int V_141 )
{
struct V_19 * V_20 = F_48 ( F_89 ( V_114 ) ) ;
struct V_128 V_147 , V_148 ;
int V_53 , V_25 ;
V_53 = F_84 ( L_7 , V_140 , V_141 , & V_147 , & V_148 ) ;
if ( V_53 )
return V_53 ;
for ( V_25 = 0 ; V_25 < V_122 / sizeof( T_1 ) ; V_25 ++ ) {
if ( V_20 -> V_45 [ V_25 ] != F_93 ( V_147 . V_43 [ V_25 ] ) ||
V_20 -> V_46 [ V_25 ] != F_93 ( V_148 . V_43 [ V_25 ] ) ) {
V_20 -> V_40 . V_107 = true ;
break;
}
}
memcpy ( V_20 -> V_45 , & V_147 . V_43 , V_122 ) ;
memcpy ( V_20 -> V_46 , & V_148 . V_43 , V_122 ) ;
return 0 ;
}
static int F_94 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_43 [ 0 ] = V_154 ;
V_22 -> V_43 [ 1 ] = V_155 ;
V_22 -> V_43 [ 2 ] = V_156 ;
V_22 -> V_43 [ 3 ] = V_157 ;
V_22 -> V_43 [ 4 ] = V_158 ;
V_22 -> V_43 [ 5 ] = V_159 ;
V_22 -> V_43 [ 6 ] = V_160 ;
V_22 -> V_43 [ 7 ] = V_161 ;
V_20 -> V_28 = V_34 ;
V_20 -> V_29 = V_30 ;
V_22 -> V_63 = V_126 ;
return 0 ;
}
static int F_95 ( struct V_56 * V_57 )
{
int V_53 = F_94 ( V_57 ) ;
if ( V_53 )
return V_53 ;
return F_60 ( V_57 ) ;
}
static int F_96 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_21 ( F_7 ( V_57 ) ) ;
struct V_21 * V_22 = F_8 ( V_57 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_43 [ 0 ] = V_162 ;
V_22 -> V_43 [ 1 ] = V_163 ;
V_22 -> V_43 [ 2 ] = V_164 ;
V_22 -> V_43 [ 3 ] = V_165 ;
V_22 -> V_43 [ 4 ] = V_166 ;
V_22 -> V_43 [ 5 ] = V_167 ;
V_22 -> V_43 [ 6 ] = V_168 ;
V_22 -> V_43 [ 7 ] = V_169 ;
V_20 -> V_28 = V_33 ;
V_20 -> V_29 = V_30 ;
V_22 -> V_63 = V_126 ;
return 0 ;
}
static int F_97 ( struct V_56 * V_57 )
{
int V_53 = F_96 ( V_57 ) ;
if ( V_53 )
return V_53 ;
return F_60 ( V_57 ) ;
}
