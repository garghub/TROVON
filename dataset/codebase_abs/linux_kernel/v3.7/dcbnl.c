static struct V_1 * F_1 ( int type , T_1 V_2 , T_2 V_3 , T_2 V_4 ,
T_2 V_5 , struct V_6 * * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
struct V_6 * V_11 ;
V_8 = F_2 ( V_12 , V_13 ) ;
if ( ! V_8 )
return NULL ;
V_11 = F_3 ( V_8 , V_3 , V_4 , type , sizeof( * V_10 ) , V_5 ) ;
F_4 ( ! V_11 ) ;
V_10 = F_5 ( V_11 ) ;
V_10 -> V_14 = V_15 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_16 = 0 ;
if ( V_7 )
* V_7 = V_11 ;
return V_8 ;
}
static int F_6 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
if ( ! V_18 -> V_21 -> V_22 )
return - V_23 ;
return F_7 ( V_8 , V_24 ,
V_18 -> V_21 -> V_22 ( V_18 ) ) ;
}
static int F_8 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_26 + 1 ] , * V_27 ;
T_1 V_28 ;
int V_29 ;
int V_30 ;
int V_31 = 0 ;
if ( ! V_20 [ V_32 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_34 )
return - V_23 ;
V_29 = F_9 ( V_25 , V_26 ,
V_20 [ V_32 ] ,
V_35 ) ;
if ( V_29 )
return V_29 ;
V_27 = F_10 ( V_8 , V_32 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_25 [ V_37 ] )
V_31 = 1 ;
for ( V_30 = V_38 ; V_30 <= V_39 ; V_30 ++ ) {
if ( ! V_31 && ! V_25 [ V_30 ] )
continue;
V_18 -> V_21 -> V_34 ( V_18 , V_30 - V_38 ,
& V_28 ) ;
V_29 = F_7 ( V_8 , V_30 , V_28 ) ;
if ( V_29 ) {
F_11 ( V_8 , V_27 ) ;
return V_29 ;
}
}
F_12 ( V_8 , V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
T_1 V_40 [ V_41 ] ;
if ( ! V_18 -> V_21 -> V_42 )
return - V_23 ;
V_18 -> V_21 -> V_42 ( V_18 , V_40 ) ;
return F_14 ( V_8 , V_43 , sizeof( V_40 ) , V_40 ) ;
}
static int F_15 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_44 + 1 ] , * V_27 ;
T_1 V_28 ;
int V_29 ;
int V_30 ;
int V_31 = 0 ;
if ( ! V_20 [ V_45 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_46 )
return - V_23 ;
V_29 = F_9 ( V_25 , V_44 , V_20 [ V_45 ] ,
V_47 ) ;
if ( V_29 )
return V_29 ;
V_27 = F_10 ( V_8 , V_45 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_25 [ V_48 ] )
V_31 = 1 ;
for ( V_30 = V_48 + 1 ; V_30 <= V_44 ; V_30 ++ ) {
if ( ! V_31 && ! V_25 [ V_30 ] )
continue;
if ( ! V_18 -> V_21 -> V_46 ( V_18 , V_30 , & V_28 ) ) {
V_29 = F_7 ( V_8 , V_30 , V_28 ) ;
if ( V_29 ) {
F_11 ( V_8 , V_27 ) ;
return V_29 ;
}
}
}
F_12 ( V_8 , V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_49 + 1 ] , * V_27 ;
T_1 V_28 ;
int V_29 ;
int V_30 ;
int V_31 = 0 ;
if ( ! V_20 [ V_50 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_51 )
return - V_23 ;
V_29 = F_9 ( V_25 , V_49 , V_20 [ V_50 ] ,
V_52 ) ;
if ( V_29 )
return V_29 ;
V_27 = F_10 ( V_8 , V_50 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_25 [ V_53 ] )
V_31 = 1 ;
for ( V_30 = V_53 + 1 ; V_30 <= V_49 ; V_30 ++ ) {
if ( ! V_31 && ! V_25 [ V_30 ] )
continue;
V_29 = V_18 -> V_21 -> V_51 ( V_18 , V_30 , & V_28 ) ;
if ( ! V_29 ) {
V_29 = F_7 ( V_8 , V_30 , V_28 ) ;
if ( V_29 ) {
F_11 ( V_8 , V_27 ) ;
return V_29 ;
}
} else
return - V_33 ;
}
F_12 ( V_8 , V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_49 + 1 ] ;
int V_29 ;
T_1 V_28 ;
int V_30 ;
if ( ! V_20 [ V_50 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_54 )
return - V_23 ;
V_29 = F_9 ( V_25 , V_49 , V_20 [ V_50 ] ,
V_52 ) ;
if ( V_29 )
return V_29 ;
for ( V_30 = V_53 + 1 ; V_30 <= V_49 ; V_30 ++ ) {
if ( V_25 [ V_30 ] == NULL )
continue;
V_28 = F_18 ( V_25 [ V_30 ] ) ;
V_29 = V_18 -> V_21 -> V_54 ( V_18 , V_30 , V_28 ) ;
if ( V_29 )
break;
}
return F_7 ( V_8 , V_50 , ! ! V_29 ) ;
}
static int F_19 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
if ( ! V_18 -> V_21 -> V_55 )
return - V_23 ;
return F_7 ( V_8 , V_56 ,
V_18 -> V_21 -> V_55 ( V_18 ) ) ;
}
static int F_20 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
T_1 V_28 ;
if ( ! V_20 [ V_56 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_57 )
return - V_23 ;
V_28 = F_18 ( V_20 [ V_56 ] ) ;
V_18 -> V_21 -> V_57 ( V_18 , V_28 ) ;
return F_7 ( V_8 , V_56 , 0 ) ;
}
static int F_21 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_58 ;
struct V_19 * V_59 [ V_60 + 1 ] ;
T_3 V_61 ;
T_1 V_62 , V_63 ;
int V_29 ;
if ( ! V_20 [ V_64 ] )
return - V_33 ;
V_29 = F_9 ( V_59 , V_60 , V_20 [ V_64 ] ,
V_65 ) ;
if ( V_29 )
return V_29 ;
if ( ( ! V_59 [ V_66 ] ) ||
( ! V_59 [ V_67 ] ) )
return - V_33 ;
V_63 = F_18 ( V_59 [ V_66 ] ) ;
if ( ( V_63 != V_68 ) &&
( V_63 != V_69 ) )
return - V_33 ;
V_61 = F_22 ( V_59 [ V_67 ] ) ;
if ( V_18 -> V_21 -> V_70 ) {
V_62 = V_18 -> V_21 -> V_70 ( V_18 , V_63 , V_61 ) ;
} else {
struct V_71 V_72 = {
. V_73 = V_63 ,
. V_74 = V_61 ,
} ;
V_62 = F_23 ( V_18 , & V_72 ) ;
}
V_58 = F_10 ( V_8 , V_64 ) ;
if ( ! V_58 )
return - V_36 ;
V_29 = F_7 ( V_8 , V_66 , V_63 ) ;
if ( V_29 )
goto V_75;
V_29 = F_24 ( V_8 , V_67 , V_61 ) ;
if ( V_29 )
goto V_75;
V_29 = F_7 ( V_8 , V_76 , V_62 ) ;
if ( V_29 )
goto V_75;
F_12 ( V_8 , V_58 ) ;
return 0 ;
V_75:
F_11 ( V_8 , V_58 ) ;
return V_29 ;
}
static int F_25 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
int V_29 ;
T_3 V_61 ;
T_1 V_62 , V_63 ;
struct V_19 * V_59 [ V_60 + 1 ] ;
if ( ! V_20 [ V_64 ] )
return - V_33 ;
V_29 = F_9 ( V_59 , V_60 , V_20 [ V_64 ] ,
V_65 ) ;
if ( V_29 )
return V_29 ;
if ( ( ! V_59 [ V_66 ] ) ||
( ! V_59 [ V_67 ] ) ||
( ! V_59 [ V_76 ] ) )
return - V_33 ;
V_63 = F_18 ( V_59 [ V_66 ] ) ;
if ( ( V_63 != V_68 ) &&
( V_63 != V_69 ) )
return - V_33 ;
V_61 = F_22 ( V_59 [ V_67 ] ) ;
V_62 = F_18 ( V_59 [ V_76 ] ) ;
if ( V_18 -> V_21 -> V_77 ) {
V_29 = V_18 -> V_21 -> V_77 ( V_18 , V_63 , V_61 , V_62 ) ;
} else {
struct V_71 V_72 ;
V_72 . V_73 = V_63 ;
V_72 . V_74 = V_61 ;
V_72 . V_78 = V_62 ;
V_29 = F_26 ( V_18 , & V_72 ) ;
}
V_29 = F_7 ( V_8 , V_64 , V_29 ) ;
F_27 ( V_18 , V_79 , V_80 , V_4 , 0 ) ;
return V_29 ;
}
static int F_28 ( struct V_17 * V_18 , struct V_6 * V_11 ,
struct V_19 * * V_20 , struct V_1 * V_8 , int V_81 )
{
struct V_19 * V_82 , * V_83 , * V_25 ;
struct V_19 * V_84 [ V_85 + 1 ] ;
struct V_19 * V_86 [ V_87 + 1 ] ;
T_1 V_88 , V_89 , V_90 , V_91 ;
int V_29 ;
int V_31 = 0 ;
int V_30 ;
if ( ! V_20 [ V_92 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_93 ||
! V_18 -> V_21 -> V_94 ||
! V_18 -> V_21 -> V_95 ||
! V_18 -> V_21 -> V_96 )
return - V_23 ;
V_29 = F_9 ( V_84 , V_85 ,
V_20 [ V_92 ] , V_97 ) ;
if ( V_29 )
return V_29 ;
V_82 = F_10 ( V_8 , V_92 ) ;
if ( ! V_82 )
return - V_36 ;
if ( V_84 [ V_98 ] )
V_31 = 1 ;
for ( V_30 = V_99 ; V_30 <= V_100 ; V_30 ++ ) {
if ( ! V_31 && ! V_84 [ V_30 ] )
continue;
if ( V_84 [ V_98 ] )
V_25 = V_84 [ V_98 ] ;
else
V_25 = V_84 [ V_30 ] ;
V_29 = F_9 ( V_86 , V_87 ,
V_25 , V_101 ) ;
if ( V_29 )
goto V_102;
V_83 = F_10 ( V_8 , V_30 ) ;
if ( ! V_83 )
goto V_102;
V_89 = V_103 ;
V_88 = V_103 ;
V_90 = V_103 ;
V_91 = V_103 ;
if ( V_81 ) {
V_18 -> V_21 -> V_94 ( V_18 ,
V_30 - V_99 , & V_88 ,
& V_89 , & V_90 , & V_91 ) ;
} else {
V_18 -> V_21 -> V_93 ( V_18 ,
V_30 - V_99 , & V_88 ,
& V_89 , & V_90 , & V_91 ) ;
}
if ( V_86 [ V_104 ] ||
V_86 [ V_105 ] ) {
V_29 = F_7 ( V_8 ,
V_104 , V_89 ) ;
if ( V_29 )
goto V_106;
}
if ( V_86 [ V_107 ] ||
V_86 [ V_105 ] ) {
V_29 = F_7 ( V_8 ,
V_107 , V_91 ) ;
if ( V_29 )
goto V_106;
}
if ( V_86 [ V_108 ] ||
V_86 [ V_105 ] ) {
V_29 = F_7 ( V_8 ,
V_108 , V_88 ) ;
if ( V_29 )
goto V_106;
}
if ( V_86 [ V_109 ] ||
V_86 [ V_105 ] ) {
V_29 = F_7 ( V_8 , V_109 ,
V_90 ) ;
if ( V_29 )
goto V_106;
}
F_12 ( V_8 , V_83 ) ;
}
if ( V_84 [ V_110 ] )
V_31 = 1 ;
else
V_31 = 0 ;
for ( V_30 = V_111 ; V_30 <= V_112 ; V_30 ++ ) {
if ( ! V_31 && ! V_84 [ V_30 ] )
continue;
V_90 = V_103 ;
if ( V_81 ) {
V_18 -> V_21 -> V_96 ( V_18 ,
V_30 - V_111 , & V_90 ) ;
} else {
V_18 -> V_21 -> V_95 ( V_18 ,
V_30 - V_111 , & V_90 ) ;
}
V_29 = F_7 ( V_8 , V_30 , V_90 ) ;
if ( V_29 )
goto V_102;
}
F_12 ( V_8 , V_82 ) ;
return 0 ;
V_106:
F_11 ( V_8 , V_83 ) ;
V_102:
F_11 ( V_8 , V_82 ) ;
return - V_36 ;
}
static int F_29 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
return F_28 ( V_18 , V_11 , V_20 , V_8 , 0 ) ;
}
static int F_30 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
return F_28 ( V_18 , V_11 , V_20 , V_8 , 1 ) ;
}
static int F_31 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
T_1 V_28 ;
if ( ! V_20 [ V_24 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_113 )
return - V_23 ;
V_28 = F_18 ( V_20 [ V_24 ] ) ;
return F_7 ( V_8 , V_24 ,
V_18 -> V_21 -> V_113 ( V_18 , V_28 ) ) ;
}
static int F_32 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_26 + 1 ] ;
int V_30 ;
int V_29 ;
T_1 V_28 ;
if ( ! V_20 [ V_32 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_114 )
return - V_23 ;
V_29 = F_9 ( V_25 , V_26 ,
V_20 [ V_32 ] ,
V_35 ) ;
if ( V_29 )
return V_29 ;
for ( V_30 = V_38 ; V_30 <= V_39 ; V_30 ++ ) {
if ( V_25 [ V_30 ] == NULL )
continue;
V_28 = F_18 ( V_25 [ V_30 ] ) ;
V_18 -> V_21 -> V_114 ( V_18 ,
V_25 [ V_30 ] -> V_115 - V_38 , V_28 ) ;
}
return F_7 ( V_8 , V_32 , 0 ) ;
}
static int F_33 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
int V_29 ;
if ( ! V_20 [ V_116 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_117 )
return - V_23 ;
V_29 = F_7 ( V_8 , V_116 ,
V_18 -> V_21 -> V_117 ( V_18 ) ) ;
F_27 ( V_18 , V_79 , V_118 , V_4 , 0 ) ;
return V_29 ;
}
static int F_34 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 ,
int V_81 )
{
struct V_19 * V_84 [ V_85 + 1 ] ;
struct V_19 * V_86 [ V_87 + 1 ] ;
int V_29 ;
int V_30 ;
T_1 V_89 ;
T_1 V_91 ;
T_1 V_88 ;
T_1 V_90 ;
if ( ! V_20 [ V_92 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_119 ||
! V_18 -> V_21 -> V_120 ||
! V_18 -> V_21 -> V_121 ||
! V_18 -> V_21 -> V_122 )
return - V_23 ;
V_29 = F_9 ( V_84 , V_85 ,
V_20 [ V_92 ] , V_97 ) ;
if ( V_29 )
return V_29 ;
for ( V_30 = V_99 ; V_30 <= V_100 ; V_30 ++ ) {
if ( ! V_84 [ V_30 ] )
continue;
V_29 = F_9 ( V_86 , V_87 ,
V_84 [ V_30 ] , V_101 ) ;
if ( V_29 )
return V_29 ;
V_89 = V_103 ;
V_88 = V_103 ;
V_90 = V_103 ;
V_91 = V_103 ;
if ( V_86 [ V_108 ] )
V_88 =
F_18 ( V_86 [ V_108 ] ) ;
if ( V_86 [ V_104 ] )
V_89 = F_18 ( V_86 [ V_104 ] ) ;
if ( V_86 [ V_109 ] )
V_90 = F_18 ( V_86 [ V_109 ] ) ;
if ( V_86 [ V_107 ] )
V_91 =
F_18 ( V_86 [ V_107 ] ) ;
if ( V_81 ) {
V_18 -> V_21 -> V_120 ( V_18 ,
V_30 - V_99 ,
V_88 , V_89 , V_90 , V_91 ) ;
} else {
V_18 -> V_21 -> V_119 ( V_18 ,
V_30 - V_99 ,
V_88 , V_89 , V_90 , V_91 ) ;
}
}
for ( V_30 = V_111 ; V_30 <= V_112 ; V_30 ++ ) {
if ( ! V_84 [ V_30 ] )
continue;
V_90 = F_18 ( V_84 [ V_30 ] ) ;
if ( V_81 ) {
V_18 -> V_21 -> V_122 ( V_18 ,
V_30 - V_111 , V_90 ) ;
} else {
V_18 -> V_21 -> V_121 ( V_18 ,
V_30 - V_111 , V_90 ) ;
}
}
return F_7 ( V_8 , V_92 , 0 ) ;
}
static int F_35 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
return F_34 ( V_18 , V_11 , V_4 , V_20 , V_8 , 0 ) ;
}
static int F_36 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
return F_34 ( V_18 , V_11 , V_4 , V_20 , V_8 , 1 ) ;
}
static int F_37 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_123 ;
struct V_19 * V_124 [ V_125 + 1 ] ;
T_1 V_126 ;
T_2 V_127 ;
int V_29 ;
bool V_31 = false ;
int V_30 ;
if ( ! V_20 [ V_128 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_129 ||
! V_18 -> V_21 -> V_130 )
return - V_23 ;
V_29 = F_9 ( V_124 , V_125 ,
V_20 [ V_128 ] , V_131 ) ;
if ( V_29 )
return V_29 ;
V_123 = F_10 ( V_8 , V_128 ) ;
if ( ! V_123 )
return - V_36 ;
if ( V_124 [ V_132 ] )
V_31 = true ;
for ( V_30 = V_133 ; V_30 <= V_134 ; V_30 ++ ) {
if ( ! V_31 && ! V_124 [ V_30 ] )
continue;
V_18 -> V_21 -> V_129 ( V_18 , V_30 - V_133 ,
& V_126 ) ;
V_29 = F_7 ( V_8 , V_30 , V_126 ) ;
if ( V_29 )
goto V_135;
}
for ( V_30 = V_136 ; V_30 <= V_137 ; V_30 ++ ) {
if ( ! V_31 && ! V_124 [ V_30 ] )
continue;
V_18 -> V_21 -> V_130 ( V_18 , V_30 ,
& V_127 ) ;
V_29 = F_38 ( V_8 , V_30 , V_127 ) ;
if ( V_29 )
goto V_135;
}
F_12 ( V_8 , V_123 ) ;
return 0 ;
V_135:
F_11 ( V_8 , V_123 ) ;
return V_29 ;
}
static int F_39 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_125 + 1 ] ;
int V_30 ;
int V_29 ;
T_1 V_126 ;
T_2 V_138 ;
if ( ! V_20 [ V_128 ] )
return - V_33 ;
if ( ! V_18 -> V_21 -> V_139 ||
! V_18 -> V_21 -> V_140 )
return - V_23 ;
V_29 = F_9 ( V_25 , V_125 ,
V_20 [ V_128 ] ,
V_35 ) ;
if ( V_29 )
return V_29 ;
for ( V_30 = V_133 ; V_30 <= V_134 ; V_30 ++ ) {
if ( V_25 [ V_30 ] == NULL )
continue;
V_126 = F_18 ( V_25 [ V_30 ] ) ;
V_18 -> V_21 -> V_140 ( V_18 ,
V_25 [ V_30 ] -> V_115 - V_133 , V_126 ) ;
}
for ( V_30 = V_136 ; V_30 <= V_137 ; V_30 ++ ) {
if ( V_25 [ V_30 ] == NULL )
continue;
V_138 = F_40 ( V_25 [ V_30 ] ) ;
V_18 -> V_21 -> V_139 ( V_18 ,
V_30 , V_138 ) ;
}
return F_7 ( V_8 , V_128 , 0 ) ;
}
static int F_41 ( struct V_17 * V_18 , struct V_1 * V_8 ,
int V_141 , int V_142 ,
int V_143 )
{
struct V_144 V_145 ;
struct V_71 * V_146 = NULL ;
const struct V_147 * V_148 = V_18 -> V_21 ;
T_3 V_149 ;
int V_150 ;
V_150 = V_148 -> V_151 ( V_18 , & V_145 , & V_149 ) ;
if ( ! V_150 && V_149 ) {
V_146 = F_42 ( sizeof( struct V_71 ) * V_149 , V_13 ) ;
if ( ! V_146 )
return - V_152 ;
V_150 = V_148 -> V_153 ( V_18 , V_146 ) ;
}
if ( ! V_150 ) {
T_3 V_30 ;
struct V_19 * V_72 ;
V_150 = - V_36 ;
V_72 = F_10 ( V_8 , V_141 ) ;
if ( ! V_72 )
goto V_154;
if ( V_142 &&
F_14 ( V_8 , V_142 , sizeof( V_145 ) , & V_145 ) )
goto V_154;
for ( V_30 = 0 ; V_30 < V_149 ; V_30 ++ ) {
if ( F_14 ( V_8 , V_143 , sizeof( struct V_71 ) ,
& V_146 [ V_30 ] ) )
goto V_154;
}
F_12 ( V_8 , V_72 ) ;
}
V_150 = 0 ;
V_154:
F_43 ( V_146 ) ;
return V_150 ;
}
static int F_44 ( struct V_1 * V_8 , struct V_17 * V_18 )
{
struct V_19 * V_155 , * V_72 ;
struct V_156 * V_157 ;
const struct V_147 * V_148 = V_18 -> V_21 ;
int V_158 ;
int V_150 ;
if ( F_45 ( V_8 , V_159 , V_18 -> V_160 ) )
return - V_36 ;
V_155 = F_10 ( V_8 , V_161 ) ;
if ( ! V_155 )
return - V_36 ;
if ( V_148 -> V_162 ) {
struct V_163 V_164 ;
V_150 = V_148 -> V_162 ( V_18 , & V_164 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_165 , sizeof( V_164 ) , & V_164 ) )
return - V_36 ;
}
if ( V_148 -> V_166 ) {
struct V_167 V_168 ;
V_150 = V_148 -> V_166 ( V_18 , & V_168 ) ;
if ( ! V_150 ) {
V_150 = F_14 ( V_8 , V_169 ,
sizeof( V_168 ) , & V_168 ) ;
if ( V_150 )
return - V_36 ;
}
}
if ( V_148 -> V_170 ) {
struct V_171 V_172 ;
V_150 = V_148 -> V_170 ( V_18 , & V_172 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_173 , sizeof( V_172 ) , & V_172 ) )
return - V_36 ;
}
V_72 = F_10 ( V_8 , V_174 ) ;
if ( ! V_72 )
return - V_36 ;
F_46 ( & V_175 ) ;
F_47 (itr, &dcb_app_list, list) {
if ( V_157 -> V_176 == V_18 -> V_176 ) {
V_150 = F_14 ( V_8 , V_177 , sizeof( V_157 -> V_72 ) ,
& V_157 -> V_72 ) ;
if ( V_150 ) {
F_48 ( & V_175 ) ;
return - V_36 ;
}
}
}
if ( V_18 -> V_21 -> V_178 )
V_158 = V_18 -> V_21 -> V_178 ( V_18 ) ;
else
V_158 = - V_23 ;
F_48 ( & V_175 ) ;
F_12 ( V_8 , V_72 ) ;
if ( V_148 -> V_179 ) {
struct V_163 V_164 ;
V_150 = V_148 -> V_179 ( V_18 , & V_164 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_180 , sizeof( V_164 ) , & V_164 ) )
return - V_36 ;
}
if ( V_148 -> V_181 ) {
struct V_171 V_172 ;
V_150 = V_148 -> V_181 ( V_18 , & V_172 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_182 , sizeof( V_172 ) , & V_172 ) )
return - V_36 ;
}
if ( V_148 -> V_151 && V_148 -> V_153 ) {
V_150 = F_41 ( V_18 , V_8 ,
V_183 ,
V_184 ,
V_177 ) ;
if ( V_150 )
return - V_36 ;
}
F_12 ( V_8 , V_155 ) ;
if ( V_158 >= 0 ) {
V_150 = F_7 ( V_8 , V_185 , V_158 ) ;
if ( V_150 )
return - V_36 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_8 , struct V_17 * V_186 ,
int V_81 )
{
T_1 V_89 , V_91 , V_88 , V_90 ;
const struct V_147 * V_148 = V_186 -> V_21 ;
int V_30 = V_81 ? V_187 : V_188 ;
struct V_19 * V_189 = F_10 ( V_8 , V_30 ) ;
if ( ! V_189 )
return - V_36 ;
for ( V_30 = V_99 ; V_30 <= V_100 ; V_30 ++ ) {
struct V_19 * V_190 = F_10 ( V_8 , V_30 ) ;
if ( ! V_190 )
return - V_36 ;
V_89 = V_103 ;
V_88 = V_103 ;
V_90 = V_103 ;
V_91 = V_103 ;
if ( ! V_81 )
V_148 -> V_94 ( V_186 , V_30 - V_99 ,
& V_88 , & V_89 , & V_90 , & V_91 ) ;
else
V_148 -> V_93 ( V_186 , V_30 - V_99 ,
& V_88 , & V_89 , & V_90 , & V_91 ) ;
if ( F_7 ( V_8 , V_104 , V_89 ) ||
F_7 ( V_8 , V_107 , V_91 ) ||
F_7 ( V_8 , V_108 , V_88 ) ||
F_7 ( V_8 , V_109 , V_90 ) )
return - V_36 ;
F_12 ( V_8 , V_190 ) ;
}
for ( V_30 = V_111 ; V_30 <= V_112 ; V_30 ++ ) {
V_90 = V_103 ;
if ( ! V_81 )
V_148 -> V_96 ( V_186 , V_30 - V_111 ,
& V_90 ) ;
else
V_148 -> V_95 ( V_186 , V_30 - V_111 ,
& V_90 ) ;
if ( F_7 ( V_8 , V_30 , V_90 ) )
return - V_36 ;
}
F_12 ( V_8 , V_189 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_8 , struct V_17 * V_18 )
{
struct V_19 * V_191 , * V_72 ;
struct V_156 * V_157 ;
const struct V_147 * V_148 = V_18 -> V_21 ;
int V_158 , V_30 , V_150 = - V_36 ;
T_1 V_28 ;
if ( F_45 ( V_8 , V_159 , V_18 -> V_160 ) )
goto V_154;
V_191 = F_10 ( V_8 , V_192 ) ;
if ( ! V_191 )
goto V_154;
if ( V_148 -> V_93 && V_148 -> V_95 ) {
V_150 = F_49 ( V_8 , V_18 , 1 ) ;
if ( V_150 )
goto V_154;
}
if ( V_148 -> V_94 && V_148 -> V_96 ) {
V_150 = F_49 ( V_8 , V_18 , 0 ) ;
if ( V_150 )
goto V_154;
}
if ( V_148 -> V_34 ) {
struct V_19 * V_193 = F_10 ( V_8 , V_194 ) ;
if ( ! V_193 )
goto V_154;
for ( V_30 = V_38 ; V_30 <= V_39 ; V_30 ++ ) {
V_148 -> V_34 ( V_18 , V_30 - V_38 , & V_28 ) ;
if ( F_7 ( V_8 , V_30 , V_28 ) )
goto V_154;
}
F_12 ( V_8 , V_193 ) ;
}
F_46 ( & V_175 ) ;
V_72 = F_10 ( V_8 , V_195 ) ;
if ( ! V_72 )
goto V_196;
F_47 (itr, &dcb_app_list, list) {
if ( V_157 -> V_176 == V_18 -> V_176 ) {
struct V_19 * V_58 = F_10 ( V_8 ,
V_64 ) ;
if ( ! V_58 )
goto V_196;
V_150 = F_7 ( V_8 , V_66 ,
V_157 -> V_72 . V_73 ) ;
if ( V_150 )
goto V_196;
V_150 = F_24 ( V_8 , V_67 ,
V_157 -> V_72 . V_74 ) ;
if ( V_150 )
goto V_196;
V_150 = F_7 ( V_8 , V_76 ,
V_157 -> V_72 . V_78 ) ;
if ( V_150 )
goto V_196;
F_12 ( V_8 , V_58 ) ;
}
}
F_12 ( V_8 , V_72 ) ;
if ( V_18 -> V_21 -> V_178 )
V_158 = V_18 -> V_21 -> V_178 ( V_18 ) ;
else
V_158 = - V_23 ;
F_48 ( & V_175 ) ;
if ( V_148 -> V_197 ) {
struct V_19 * V_198 = F_10 ( V_8 , V_199 ) ;
if ( ! V_198 )
goto V_154;
for ( V_30 = V_200 + 1 ; V_30 <= V_201 ;
V_30 ++ )
if ( ! V_148 -> V_197 ( V_18 , V_30 , & V_28 ) &&
F_7 ( V_8 , V_30 , V_28 ) )
goto V_154;
F_12 ( V_8 , V_198 ) ;
}
if ( V_148 -> V_202 ) {
struct V_203 V_189 ;
V_150 = V_148 -> V_202 ( V_18 , & V_189 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_204 , sizeof( V_189 ) , & V_189 ) )
goto V_154;
}
if ( V_148 -> V_205 ) {
struct V_206 V_172 ;
V_150 = V_148 -> V_205 ( V_18 , & V_172 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_207 , sizeof( V_172 ) , & V_172 ) )
goto V_154;
}
if ( V_148 -> V_151 && V_148 -> V_153 ) {
V_150 = F_41 ( V_18 , V_8 ,
V_208 ,
V_209 ,
V_210 ) ;
if ( V_150 )
goto V_154;
}
F_12 ( V_8 , V_191 ) ;
if ( V_158 >= 0 ) {
V_150 = F_7 ( V_8 , V_185 , V_158 ) ;
if ( V_150 )
goto V_154;
}
return 0 ;
V_196:
F_48 ( & V_175 ) ;
V_154:
return V_150 ;
}
static int F_51 ( struct V_17 * V_186 , int V_211 , int V_2 ,
T_2 V_4 , T_2 V_212 , int V_213 )
{
struct V_214 * V_214 = F_52 ( V_186 ) ;
struct V_1 * V_8 ;
struct V_6 * V_11 ;
const struct V_147 * V_148 = V_186 -> V_21 ;
int V_150 ;
if ( ! V_148 )
return - V_23 ;
V_8 = F_1 ( V_211 , V_2 , V_212 , V_4 , 0 , & V_11 ) ;
if ( ! V_8 )
return - V_215 ;
if ( V_213 == V_216 )
V_150 = F_44 ( V_8 , V_186 ) ;
else
V_150 = F_50 ( V_8 , V_186 ) ;
if ( V_150 < 0 ) {
F_53 ( V_8 ) ;
F_54 ( V_214 , V_217 , V_150 ) ;
} else {
F_55 ( V_8 , V_11 ) ;
F_56 ( V_8 , V_214 , 0 , V_217 , NULL , V_13 ) ;
}
return V_150 ;
}
int F_57 ( struct V_17 * V_186 , int V_211 , int V_2 ,
T_2 V_4 , T_2 V_212 )
{
return F_51 ( V_186 , V_211 , V_2 , V_4 , V_212 , V_216 ) ;
}
int F_27 ( struct V_17 * V_186 , int V_211 , int V_2 ,
T_2 V_4 , T_2 V_212 )
{
return F_51 ( V_186 , V_211 , V_2 , V_4 , V_212 , V_218 ) ;
}
static int F_58 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
const struct V_147 * V_148 = V_18 -> V_21 ;
struct V_19 * V_155 [ V_219 + 1 ] ;
int V_150 ;
if ( ! V_148 )
return - V_23 ;
if ( ! V_20 [ V_161 ] )
return - V_33 ;
V_150 = F_9 ( V_155 , V_219 ,
V_20 [ V_161 ] , V_220 ) ;
if ( V_150 )
return V_150 ;
if ( V_155 [ V_165 ] && V_148 -> V_221 ) {
struct V_163 * V_164 = F_59 ( V_155 [ V_165 ] ) ;
V_150 = V_148 -> V_221 ( V_18 , V_164 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_169 ] && V_148 -> V_222 ) {
struct V_167 * V_168 =
F_59 ( V_155 [ V_169 ] ) ;
V_150 = V_148 -> V_222 ( V_18 , V_168 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_173 ] && V_148 -> V_223 ) {
struct V_171 * V_172 = F_59 ( V_155 [ V_173 ] ) ;
V_150 = V_148 -> V_223 ( V_18 , V_172 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_174 ] ) {
struct V_19 * V_224 ;
int V_225 ;
F_60 (attr, ieee[DCB_ATTR_IEEE_APP_TABLE], rem) {
struct V_71 * V_226 ;
if ( V_115 ( V_224 ) != V_177 )
continue;
V_226 = F_59 ( V_224 ) ;
if ( V_148 -> V_227 )
V_150 = V_148 -> V_227 ( V_18 , V_226 ) ;
else
V_150 = F_61 ( V_18 , V_226 ) ;
if ( V_150 )
goto V_150;
}
}
V_150:
V_150 = F_7 ( V_8 , V_161 , V_150 ) ;
F_57 ( V_18 , V_79 , V_228 , V_4 , 0 ) ;
return V_150 ;
}
static int F_62 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
const struct V_147 * V_148 = V_18 -> V_21 ;
if ( ! V_148 )
return - V_23 ;
return F_44 ( V_8 , V_18 ) ;
}
static int F_63 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
const struct V_147 * V_148 = V_18 -> V_21 ;
struct V_19 * V_155 [ V_219 + 1 ] ;
int V_150 ;
if ( ! V_148 )
return - V_23 ;
if ( ! V_20 [ V_161 ] )
return - V_33 ;
V_150 = F_9 ( V_155 , V_219 ,
V_20 [ V_161 ] , V_220 ) ;
if ( V_150 )
return V_150 ;
if ( V_155 [ V_174 ] ) {
struct V_19 * V_224 ;
int V_225 ;
F_60 (attr, ieee[DCB_ATTR_IEEE_APP_TABLE], rem) {
struct V_71 * V_226 ;
if ( V_115 ( V_224 ) != V_177 )
continue;
V_226 = F_59 ( V_224 ) ;
if ( V_148 -> V_229 )
V_150 = V_148 -> V_229 ( V_18 , V_226 ) ;
else
V_150 = F_64 ( V_18 , V_226 ) ;
if ( V_150 )
goto V_150;
}
}
V_150:
V_150 = F_7 ( V_8 , V_161 , V_150 ) ;
F_57 ( V_18 , V_79 , V_230 , V_4 , 0 ) ;
return V_150 ;
}
static int F_65 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
if ( ! V_18 -> V_21 -> V_178 )
return - V_23 ;
return F_7 ( V_8 , V_185 ,
V_18 -> V_21 -> V_178 ( V_18 ) ) ;
}
static int F_66 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
T_1 V_28 ;
if ( ! V_18 -> V_21 -> V_231 )
return - V_23 ;
if ( ! V_20 [ V_185 ] )
return - V_33 ;
V_28 = F_18 ( V_20 [ V_185 ] ) ;
return F_7 ( V_8 , V_185 ,
V_18 -> V_21 -> V_231 ( V_18 , V_28 ) ) ;
}
static int F_67 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_201 + 1 ] , * V_27 ;
T_1 V_28 ;
int V_29 , V_30 ;
int V_31 = 0 ;
if ( ! V_18 -> V_21 -> V_197 )
return - V_23 ;
if ( ! V_20 [ V_232 ] )
return - V_33 ;
V_29 = F_9 ( V_25 , V_201 , V_20 [ V_232 ] ,
V_233 ) ;
if ( V_29 )
return V_29 ;
V_27 = F_10 ( V_8 , V_232 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_25 [ V_200 ] )
V_31 = 1 ;
for ( V_30 = V_200 + 1 ; V_30 <= V_201 ; V_30 ++ ) {
if ( ! V_31 && ! V_25 [ V_30 ] )
continue;
V_29 = V_18 -> V_21 -> V_197 ( V_18 , V_30 , & V_28 ) ;
if ( ! V_29 )
V_29 = F_7 ( V_8 , V_30 , V_28 ) ;
if ( V_29 ) {
F_11 ( V_8 , V_27 ) ;
goto V_154;
}
}
F_12 ( V_8 , V_27 ) ;
V_154:
return V_29 ;
}
static int F_68 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_201 + 1 ] ;
int V_29 , V_30 ;
T_1 V_28 ;
if ( ! V_18 -> V_21 -> V_234 )
return - V_235 ;
if ( ! V_20 [ V_232 ] )
return - V_33 ;
V_29 = F_9 ( V_25 , V_201 , V_20 [ V_232 ] ,
V_233 ) ;
if ( V_29 )
goto V_150;
for ( V_30 = V_200 + 1 ; V_30 <= V_201 ; V_30 ++ ) {
if ( V_25 [ V_30 ] == NULL )
continue;
V_28 = F_18 ( V_25 [ V_30 ] ) ;
V_29 = V_18 -> V_21 -> V_234 ( V_18 , V_30 , V_28 ) ;
if ( V_29 )
goto V_150;
}
V_150:
V_29 = F_7 ( V_8 , V_232 , V_29 ) ;
return V_29 ;
}
static int F_69 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
const struct V_147 * V_148 = V_18 -> V_21 ;
if ( ! V_148 )
return - V_23 ;
return F_50 ( V_8 , V_18 ) ;
}
static int F_70 ( struct V_1 * V_8 , struct V_6 * V_11 , void * V_236 )
{
struct V_214 * V_214 = F_71 ( V_8 -> V_237 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 = F_5 ( V_11 ) ;
struct V_19 * V_20 [ V_238 + 1 ] ;
T_2 V_212 = V_8 ? F_72 ( V_8 ) . V_212 : 0 ;
int V_29 = - V_33 ;
struct V_1 * V_239 ;
struct V_6 * V_240 = NULL ;
const struct V_241 * V_242 ;
if ( ! F_73 ( V_214 , & V_243 ) )
return - V_33 ;
V_29 = F_74 ( V_11 , sizeof( * V_10 ) , V_20 , V_238 ,
V_244 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_10 -> V_2 > V_245 )
return - V_33 ;
V_242 = & V_246 [ V_10 -> V_2 ] ;
if ( ! V_242 -> V_247 )
return - V_23 ;
if ( ! V_20 [ V_159 ] )
return - V_33 ;
V_18 = F_75 ( & V_243 , F_59 ( V_20 [ V_159 ] ) ) ;
if ( ! V_18 )
return - V_248 ;
if ( ! V_18 -> V_21 ) {
V_29 = - V_23 ;
goto V_249;
}
V_239 = F_1 ( V_242 -> type , V_10 -> V_2 , V_212 , V_11 -> V_250 ,
V_11 -> V_251 , & V_240 ) ;
if ( ! V_239 ) {
V_29 = - V_215 ;
goto V_249;
}
V_29 = V_242 -> V_247 ( V_18 , V_11 , V_11 -> V_250 , V_20 , V_239 ) ;
if ( V_29 < 0 ) {
F_53 ( V_239 ) ;
goto V_249;
}
F_55 ( V_239 , V_240 ) ;
V_29 = F_76 ( V_239 , & V_243 , V_212 ) ;
V_249:
F_77 ( V_18 ) ;
return V_29 ;
}
static struct V_156 * F_78 ( const struct V_71 * V_72 ,
int V_176 , int V_88 )
{
struct V_156 * V_157 ;
F_47 (itr, &dcb_app_list, list) {
if ( V_157 -> V_72 . V_73 == V_72 -> V_73 &&
V_157 -> V_72 . V_74 == V_72 -> V_74 &&
V_157 -> V_176 == V_176 &&
( ! V_88 || V_157 -> V_72 . V_78 == V_88 ) )
return V_157 ;
}
return NULL ;
}
static int F_79 ( const struct V_71 * V_72 , int V_176 )
{
struct V_156 * V_252 ;
V_252 = F_42 ( sizeof( * V_252 ) , V_253 ) ;
if ( ! V_252 )
return - V_152 ;
memcpy ( & V_252 -> V_72 , V_72 , sizeof( * V_72 ) ) ;
V_252 -> V_176 = V_176 ;
F_80 ( & V_252 -> V_254 , & V_255 ) ;
return 0 ;
}
T_1 F_23 ( struct V_17 * V_186 , struct V_71 * V_72 )
{
struct V_156 * V_157 ;
T_1 V_88 = 0 ;
F_46 ( & V_175 ) ;
if ( ( V_157 = F_78 ( V_72 , V_186 -> V_176 , 0 ) ) )
V_88 = V_157 -> V_72 . V_78 ;
F_48 ( & V_175 ) ;
return V_88 ;
}
int F_26 ( struct V_17 * V_186 , struct V_71 * V_256 )
{
struct V_156 * V_157 ;
struct V_156 V_211 ;
int V_150 = 0 ;
V_211 . V_176 = V_186 -> V_176 ;
memcpy ( & V_211 . V_72 , V_256 , sizeof( V_211 . V_72 ) ) ;
if ( V_186 -> V_21 -> V_178 )
V_211 . V_158 = V_186 -> V_21 -> V_178 ( V_186 ) ;
F_46 ( & V_175 ) ;
if ( ( V_157 = F_78 ( V_256 , V_186 -> V_176 , 0 ) ) ) {
if ( V_256 -> V_78 )
V_157 -> V_72 . V_78 = V_256 -> V_78 ;
else {
F_81 ( & V_157 -> V_254 ) ;
F_43 ( V_157 ) ;
}
goto V_249;
}
if ( V_256 -> V_78 )
V_150 = F_79 ( V_256 , V_186 -> V_176 ) ;
V_249:
F_48 ( & V_175 ) ;
if ( ! V_150 )
F_82 ( V_257 , & V_211 ) ;
return V_150 ;
}
T_1 F_83 ( struct V_17 * V_186 , struct V_71 * V_72 )
{
struct V_156 * V_157 ;
T_1 V_88 = 0 ;
F_46 ( & V_175 ) ;
if ( ( V_157 = F_78 ( V_72 , V_186 -> V_176 , 0 ) ) )
V_88 |= 1 << V_157 -> V_72 . V_78 ;
F_48 ( & V_175 ) ;
return V_88 ;
}
int F_61 ( struct V_17 * V_186 , struct V_71 * V_256 )
{
struct V_156 V_211 ;
int V_150 = 0 ;
V_211 . V_176 = V_186 -> V_176 ;
memcpy ( & V_211 . V_72 , V_256 , sizeof( V_211 . V_72 ) ) ;
if ( V_186 -> V_21 -> V_178 )
V_211 . V_158 = V_186 -> V_21 -> V_178 ( V_186 ) ;
F_46 ( & V_175 ) ;
if ( F_78 ( V_256 , V_186 -> V_176 , V_256 -> V_78 ) ) {
V_150 = - V_258 ;
goto V_249;
}
V_150 = F_79 ( V_256 , V_186 -> V_176 ) ;
V_249:
F_48 ( & V_175 ) ;
if ( ! V_150 )
F_82 ( V_257 , & V_211 ) ;
return V_150 ;
}
int F_64 ( struct V_17 * V_186 , struct V_71 * V_259 )
{
struct V_156 * V_157 ;
struct V_156 V_211 ;
int V_150 = - V_260 ;
V_211 . V_176 = V_186 -> V_176 ;
memcpy ( & V_211 . V_72 , V_259 , sizeof( V_211 . V_72 ) ) ;
if ( V_186 -> V_21 -> V_178 )
V_211 . V_158 = V_186 -> V_21 -> V_178 ( V_186 ) ;
F_46 ( & V_175 ) ;
if ( ( V_157 = F_78 ( V_259 , V_186 -> V_176 , V_259 -> V_78 ) ) ) {
F_81 ( & V_157 -> V_254 ) ;
F_43 ( V_157 ) ;
V_150 = 0 ;
}
F_48 ( & V_175 ) ;
if ( ! V_150 )
F_82 ( V_257 , & V_211 ) ;
return V_150 ;
}
static void F_84 ( void )
{
struct V_156 * V_72 ;
struct V_156 * V_261 ;
F_46 ( & V_175 ) ;
F_85 (app, tmp, &dcb_app_list, list) {
F_81 ( & V_72 -> V_254 ) ;
F_43 ( V_72 ) ;
}
F_48 ( & V_175 ) ;
}
static int T_4 F_86 ( void )
{
F_87 ( & V_255 ) ;
F_88 ( V_262 , V_263 , F_70 , NULL , NULL ) ;
F_88 ( V_262 , V_79 , F_70 , NULL , NULL ) ;
return 0 ;
}
static void T_5 F_89 ( void )
{
F_90 ( V_262 , V_263 ) ;
F_90 ( V_262 , V_79 ) ;
F_84 () ;
}
