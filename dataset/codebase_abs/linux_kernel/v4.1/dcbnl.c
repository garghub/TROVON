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
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
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
V_29 = V_18 -> V_21 -> V_70 ( V_18 , V_63 , V_61 ) ;
if ( V_29 < 0 )
return V_29 ;
else
V_62 = V_29 ;
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
if ( V_29 < 0 )
return V_29 ;
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
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_150 = V_148 -> V_162 ( V_18 , & V_164 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_165 , sizeof( V_164 ) , & V_164 ) )
return - V_36 ;
}
if ( V_148 -> V_166 ) {
struct V_167 V_168 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
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
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_150 = V_148 -> V_170 ( V_18 , & V_172 ) ;
if ( ! V_150 ) {
V_150 = F_14 ( V_8 , V_173 ,
sizeof( V_172 ) , & V_172 ) ;
if ( V_150 )
return - V_36 ;
}
}
if ( V_148 -> V_174 ) {
struct V_175 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_150 = V_148 -> V_174 ( V_18 , & V_176 ) ;
if ( ! V_150 ) {
V_150 = F_14 ( V_8 , V_177 ,
sizeof( V_176 ) , & V_176 ) ;
if ( V_150 )
return - V_36 ;
}
}
if ( V_148 -> V_178 ) {
struct V_179 V_180 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_150 = V_148 -> V_178 ( V_18 , & V_180 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_181 , sizeof( V_180 ) , & V_180 ) )
return - V_36 ;
}
V_72 = F_10 ( V_8 , V_182 ) ;
if ( ! V_72 )
return - V_36 ;
F_46 ( & V_183 ) ;
F_47 (itr, &dcb_app_list, list) {
if ( V_157 -> V_184 == V_18 -> V_184 ) {
V_150 = F_14 ( V_8 , V_185 , sizeof( V_157 -> V_72 ) ,
& V_157 -> V_72 ) ;
if ( V_150 ) {
F_48 ( & V_183 ) ;
return - V_36 ;
}
}
}
if ( V_18 -> V_21 -> V_186 )
V_158 = V_18 -> V_21 -> V_186 ( V_18 ) ;
else
V_158 = - V_23 ;
F_48 ( & V_183 ) ;
F_12 ( V_8 , V_72 ) ;
if ( V_148 -> V_187 ) {
struct V_163 V_164 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_150 = V_148 -> V_187 ( V_18 , & V_164 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_188 , sizeof( V_164 ) , & V_164 ) )
return - V_36 ;
}
if ( V_148 -> V_189 ) {
struct V_179 V_180 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_150 = V_148 -> V_189 ( V_18 , & V_180 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_190 , sizeof( V_180 ) , & V_180 ) )
return - V_36 ;
}
if ( V_148 -> V_151 && V_148 -> V_153 ) {
V_150 = F_41 ( V_18 , V_8 ,
V_191 ,
V_192 ,
V_185 ) ;
if ( V_150 )
return - V_36 ;
}
F_12 ( V_8 , V_155 ) ;
if ( V_158 >= 0 ) {
V_150 = F_7 ( V_8 , V_193 , V_158 ) ;
if ( V_150 )
return - V_36 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_8 , struct V_17 * V_194 ,
int V_81 )
{
T_1 V_89 , V_91 , V_88 , V_90 ;
const struct V_147 * V_148 = V_194 -> V_21 ;
int V_30 = V_81 ? V_195 : V_196 ;
struct V_19 * V_197 = F_10 ( V_8 , V_30 ) ;
if ( ! V_197 )
return - V_36 ;
for ( V_30 = V_99 ; V_30 <= V_100 ; V_30 ++ ) {
struct V_19 * V_198 = F_10 ( V_8 , V_30 ) ;
if ( ! V_198 )
return - V_36 ;
V_89 = V_103 ;
V_88 = V_103 ;
V_90 = V_103 ;
V_91 = V_103 ;
if ( ! V_81 )
V_148 -> V_94 ( V_194 , V_30 - V_99 ,
& V_88 , & V_89 , & V_90 , & V_91 ) ;
else
V_148 -> V_93 ( V_194 , V_30 - V_99 ,
& V_88 , & V_89 , & V_90 , & V_91 ) ;
if ( F_7 ( V_8 , V_104 , V_89 ) ||
F_7 ( V_8 , V_107 , V_91 ) ||
F_7 ( V_8 , V_108 , V_88 ) ||
F_7 ( V_8 , V_109 , V_90 ) )
return - V_36 ;
F_12 ( V_8 , V_198 ) ;
}
for ( V_30 = V_111 ; V_30 <= V_112 ; V_30 ++ ) {
V_90 = V_103 ;
if ( ! V_81 )
V_148 -> V_96 ( V_194 , V_30 - V_111 ,
& V_90 ) ;
else
V_148 -> V_95 ( V_194 , V_30 - V_111 ,
& V_90 ) ;
if ( F_7 ( V_8 , V_30 , V_90 ) )
return - V_36 ;
}
F_12 ( V_8 , V_197 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_8 , struct V_17 * V_18 )
{
struct V_19 * V_199 , * V_72 ;
struct V_156 * V_157 ;
const struct V_147 * V_148 = V_18 -> V_21 ;
int V_158 , V_30 , V_150 = - V_36 ;
T_1 V_28 ;
if ( F_45 ( V_8 , V_159 , V_18 -> V_160 ) )
goto V_154;
V_199 = F_10 ( V_8 , V_200 ) ;
if ( ! V_199 )
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
struct V_19 * V_201 = F_10 ( V_8 , V_202 ) ;
if ( ! V_201 )
goto V_154;
for ( V_30 = V_38 ; V_30 <= V_39 ; V_30 ++ ) {
V_148 -> V_34 ( V_18 , V_30 - V_38 , & V_28 ) ;
if ( F_7 ( V_8 , V_30 , V_28 ) )
goto V_154;
}
F_12 ( V_8 , V_201 ) ;
}
F_46 ( & V_183 ) ;
V_72 = F_10 ( V_8 , V_203 ) ;
if ( ! V_72 )
goto V_204;
F_47 (itr, &dcb_app_list, list) {
if ( V_157 -> V_184 == V_18 -> V_184 ) {
struct V_19 * V_58 = F_10 ( V_8 ,
V_64 ) ;
if ( ! V_58 )
goto V_204;
V_150 = F_7 ( V_8 , V_66 ,
V_157 -> V_72 . V_73 ) ;
if ( V_150 )
goto V_204;
V_150 = F_24 ( V_8 , V_67 ,
V_157 -> V_72 . V_74 ) ;
if ( V_150 )
goto V_204;
V_150 = F_7 ( V_8 , V_76 ,
V_157 -> V_72 . V_78 ) ;
if ( V_150 )
goto V_204;
F_12 ( V_8 , V_58 ) ;
}
}
F_12 ( V_8 , V_72 ) ;
if ( V_18 -> V_21 -> V_186 )
V_158 = V_18 -> V_21 -> V_186 ( V_18 ) ;
else
V_158 = - V_23 ;
F_48 ( & V_183 ) ;
if ( V_148 -> V_205 ) {
struct V_19 * V_206 = F_10 ( V_8 , V_207 ) ;
if ( ! V_206 )
goto V_154;
for ( V_30 = V_208 + 1 ; V_30 <= V_209 ;
V_30 ++ )
if ( ! V_148 -> V_205 ( V_18 , V_30 , & V_28 ) &&
F_7 ( V_8 , V_30 , V_28 ) )
goto V_154;
F_12 ( V_8 , V_206 ) ;
}
if ( V_148 -> V_210 ) {
struct V_211 V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_150 = V_148 -> V_210 ( V_18 , & V_197 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_212 , sizeof( V_197 ) , & V_197 ) )
goto V_154;
}
if ( V_148 -> V_213 ) {
struct V_214 V_180 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_150 = V_148 -> V_213 ( V_18 , & V_180 ) ;
if ( ! V_150 &&
F_14 ( V_8 , V_215 , sizeof( V_180 ) , & V_180 ) )
goto V_154;
}
if ( V_148 -> V_151 && V_148 -> V_153 ) {
V_150 = F_41 ( V_18 , V_8 ,
V_216 ,
V_217 ,
V_218 ) ;
if ( V_150 )
goto V_154;
}
F_12 ( V_8 , V_199 ) ;
if ( V_158 >= 0 ) {
V_150 = F_7 ( V_8 , V_193 , V_158 ) ;
if ( V_150 )
goto V_154;
}
return 0 ;
V_204:
F_48 ( & V_183 ) ;
V_154:
return V_150 ;
}
static int F_51 ( struct V_17 * V_194 , int V_219 , int V_2 ,
T_2 V_4 , T_2 V_220 , int V_221 )
{
struct V_222 * V_222 = F_52 ( V_194 ) ;
struct V_1 * V_8 ;
struct V_6 * V_11 ;
const struct V_147 * V_148 = V_194 -> V_21 ;
int V_150 ;
if ( ! V_148 )
return - V_23 ;
V_8 = F_1 ( V_219 , V_2 , V_220 , V_4 , 0 , & V_11 ) ;
if ( ! V_8 )
return - V_223 ;
if ( V_221 == V_224 )
V_150 = F_44 ( V_8 , V_194 ) ;
else
V_150 = F_50 ( V_8 , V_194 ) ;
if ( V_150 < 0 ) {
F_53 ( V_8 ) ;
F_54 ( V_222 , V_225 , V_150 ) ;
} else {
F_55 ( V_8 , V_11 ) ;
F_56 ( V_8 , V_222 , 0 , V_225 , NULL , V_13 ) ;
}
return V_150 ;
}
int F_57 ( struct V_17 * V_194 , int V_219 , int V_2 ,
T_2 V_4 , T_2 V_220 )
{
return F_51 ( V_194 , V_219 , V_2 , V_4 , V_220 , V_224 ) ;
}
int F_27 ( struct V_17 * V_194 , int V_219 , int V_2 ,
T_2 V_4 , T_2 V_220 )
{
return F_51 ( V_194 , V_219 , V_2 , V_4 , V_220 , V_226 ) ;
}
static int F_58 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
const struct V_147 * V_148 = V_18 -> V_21 ;
struct V_19 * V_155 [ V_227 + 1 ] ;
int V_150 ;
if ( ! V_148 )
return - V_23 ;
if ( ! V_20 [ V_161 ] )
return - V_33 ;
V_150 = F_9 ( V_155 , V_227 ,
V_20 [ V_161 ] , V_228 ) ;
if ( V_150 )
return V_150 ;
if ( V_155 [ V_165 ] && V_148 -> V_229 ) {
struct V_163 * V_164 = F_59 ( V_155 [ V_165 ] ) ;
V_150 = V_148 -> V_229 ( V_18 , V_164 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_169 ] && V_148 -> V_230 ) {
struct V_167 * V_168 =
F_59 ( V_155 [ V_169 ] ) ;
V_150 = V_148 -> V_230 ( V_18 , V_168 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_173 ] && V_148 -> V_231 ) {
struct V_171 * V_172 =
F_59 ( V_155 [ V_173 ] ) ;
V_150 = V_148 -> V_231 ( V_18 , V_172 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_181 ] && V_148 -> V_232 ) {
struct V_179 * V_180 = F_59 ( V_155 [ V_181 ] ) ;
V_150 = V_148 -> V_232 ( V_18 , V_180 ) ;
if ( V_150 )
goto V_150;
}
if ( V_155 [ V_182 ] ) {
struct V_19 * V_233 ;
int V_234 ;
F_60 (attr, ieee[DCB_ATTR_IEEE_APP_TABLE], rem) {
struct V_71 * V_235 ;
if ( V_115 ( V_233 ) != V_185 )
continue;
V_235 = F_59 ( V_233 ) ;
if ( V_148 -> V_236 )
V_150 = V_148 -> V_236 ( V_18 , V_235 ) ;
else
V_150 = F_61 ( V_18 , V_235 ) ;
if ( V_150 )
goto V_150;
}
}
V_150:
V_150 = F_7 ( V_8 , V_161 , V_150 ) ;
F_57 ( V_18 , V_79 , V_237 , V_4 , 0 ) ;
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
struct V_19 * V_155 [ V_227 + 1 ] ;
int V_150 ;
if ( ! V_148 )
return - V_23 ;
if ( ! V_20 [ V_161 ] )
return - V_33 ;
V_150 = F_9 ( V_155 , V_227 ,
V_20 [ V_161 ] , V_228 ) ;
if ( V_150 )
return V_150 ;
if ( V_155 [ V_182 ] ) {
struct V_19 * V_233 ;
int V_234 ;
F_60 (attr, ieee[DCB_ATTR_IEEE_APP_TABLE], rem) {
struct V_71 * V_235 ;
if ( V_115 ( V_233 ) != V_185 )
continue;
V_235 = F_59 ( V_233 ) ;
if ( V_148 -> V_238 )
V_150 = V_148 -> V_238 ( V_18 , V_235 ) ;
else
V_150 = F_64 ( V_18 , V_235 ) ;
if ( V_150 )
goto V_150;
}
}
V_150:
V_150 = F_7 ( V_8 , V_161 , V_150 ) ;
F_57 ( V_18 , V_79 , V_239 , V_4 , 0 ) ;
return V_150 ;
}
static int F_65 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
if ( ! V_18 -> V_21 -> V_186 )
return - V_23 ;
return F_7 ( V_8 , V_193 ,
V_18 -> V_21 -> V_186 ( V_18 ) ) ;
}
static int F_66 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
T_1 V_28 ;
if ( ! V_18 -> V_21 -> V_240 )
return - V_23 ;
if ( ! V_20 [ V_193 ] )
return - V_33 ;
V_28 = F_18 ( V_20 [ V_193 ] ) ;
return F_7 ( V_8 , V_193 ,
V_18 -> V_21 -> V_240 ( V_18 , V_28 ) ) ;
}
static int F_67 ( struct V_17 * V_18 , struct V_6 * V_11 ,
T_2 V_4 , struct V_19 * * V_20 , struct V_1 * V_8 )
{
struct V_19 * V_25 [ V_209 + 1 ] , * V_27 ;
T_1 V_28 ;
int V_29 , V_30 ;
int V_31 = 0 ;
if ( ! V_18 -> V_21 -> V_205 )
return - V_23 ;
if ( ! V_20 [ V_241 ] )
return - V_33 ;
V_29 = F_9 ( V_25 , V_209 , V_20 [ V_241 ] ,
V_242 ) ;
if ( V_29 )
return V_29 ;
V_27 = F_10 ( V_8 , V_241 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_25 [ V_208 ] )
V_31 = 1 ;
for ( V_30 = V_208 + 1 ; V_30 <= V_209 ; V_30 ++ ) {
if ( ! V_31 && ! V_25 [ V_30 ] )
continue;
V_29 = V_18 -> V_21 -> V_205 ( V_18 , V_30 , & V_28 ) ;
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
struct V_19 * V_25 [ V_209 + 1 ] ;
int V_29 , V_30 ;
T_1 V_28 ;
if ( ! V_18 -> V_21 -> V_243 )
return - V_244 ;
if ( ! V_20 [ V_241 ] )
return - V_33 ;
V_29 = F_9 ( V_25 , V_209 , V_20 [ V_241 ] ,
V_242 ) ;
if ( V_29 )
goto V_150;
for ( V_30 = V_208 + 1 ; V_30 <= V_209 ; V_30 ++ ) {
if ( V_25 [ V_30 ] == NULL )
continue;
V_28 = F_18 ( V_25 [ V_30 ] ) ;
V_29 = V_18 -> V_21 -> V_243 ( V_18 , V_30 , V_28 ) ;
if ( V_29 )
goto V_150;
}
V_150:
V_29 = F_7 ( V_8 , V_241 , V_29 ) ;
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
static int F_70 ( struct V_1 * V_8 , struct V_6 * V_11 )
{
struct V_222 * V_222 = F_71 ( V_8 -> V_245 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 = F_5 ( V_11 ) ;
struct V_19 * V_20 [ V_246 + 1 ] ;
T_2 V_220 = V_8 ? F_72 ( V_8 ) . V_220 : 0 ;
int V_29 = - V_33 ;
struct V_1 * V_247 ;
struct V_6 * V_248 = NULL ;
const struct V_249 * V_250 ;
if ( ( V_11 -> V_251 == V_79 ) && ! F_73 ( V_8 , V_252 ) )
return - V_253 ;
V_29 = F_74 ( V_11 , sizeof( * V_10 ) , V_20 , V_246 ,
V_254 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_10 -> V_2 > V_255 )
return - V_33 ;
V_250 = & V_256 [ V_10 -> V_2 ] ;
if ( ! V_250 -> V_257 )
return - V_23 ;
if ( ! V_20 [ V_159 ] )
return - V_33 ;
V_18 = F_75 ( V_222 , F_59 ( V_20 [ V_159 ] ) ) ;
if ( ! V_18 )
return - V_258 ;
if ( ! V_18 -> V_21 )
return - V_23 ;
V_247 = F_1 ( V_250 -> type , V_10 -> V_2 , V_220 , V_11 -> V_259 ,
V_11 -> V_260 , & V_248 ) ;
if ( ! V_247 )
return - V_223 ;
V_29 = V_250 -> V_257 ( V_18 , V_11 , V_11 -> V_259 , V_20 , V_247 ) ;
if ( V_29 < 0 ) {
F_53 ( V_247 ) ;
goto V_261;
}
F_55 ( V_247 , V_248 ) ;
V_29 = F_76 ( V_247 , V_222 , V_220 ) ;
V_261:
return V_29 ;
}
static struct V_156 * F_77 ( const struct V_71 * V_72 ,
int V_184 , int V_88 )
{
struct V_156 * V_157 ;
F_47 (itr, &dcb_app_list, list) {
if ( V_157 -> V_72 . V_73 == V_72 -> V_73 &&
V_157 -> V_72 . V_74 == V_72 -> V_74 &&
V_157 -> V_184 == V_184 &&
( ! V_88 || V_157 -> V_72 . V_78 == V_88 ) )
return V_157 ;
}
return NULL ;
}
static int F_78 ( const struct V_71 * V_72 , int V_184 )
{
struct V_156 * V_262 ;
V_262 = F_42 ( sizeof( * V_262 ) , V_263 ) ;
if ( ! V_262 )
return - V_152 ;
memcpy ( & V_262 -> V_72 , V_72 , sizeof( * V_72 ) ) ;
V_262 -> V_184 = V_184 ;
F_79 ( & V_262 -> V_264 , & V_265 ) ;
return 0 ;
}
T_1 F_23 ( struct V_17 * V_194 , struct V_71 * V_72 )
{
struct V_156 * V_157 ;
T_1 V_88 = 0 ;
F_46 ( & V_183 ) ;
if ( ( V_157 = F_77 ( V_72 , V_194 -> V_184 , 0 ) ) )
V_88 = V_157 -> V_72 . V_78 ;
F_48 ( & V_183 ) ;
return V_88 ;
}
int F_26 ( struct V_17 * V_194 , struct V_71 * V_266 )
{
struct V_156 * V_157 ;
struct V_156 V_219 ;
int V_150 = 0 ;
V_219 . V_184 = V_194 -> V_184 ;
memcpy ( & V_219 . V_72 , V_266 , sizeof( V_219 . V_72 ) ) ;
if ( V_194 -> V_21 -> V_186 )
V_219 . V_158 = V_194 -> V_21 -> V_186 ( V_194 ) ;
F_46 ( & V_183 ) ;
if ( ( V_157 = F_77 ( V_266 , V_194 -> V_184 , 0 ) ) ) {
if ( V_266 -> V_78 )
V_157 -> V_72 . V_78 = V_266 -> V_78 ;
else {
F_80 ( & V_157 -> V_264 ) ;
F_43 ( V_157 ) ;
}
goto V_261;
}
if ( V_266 -> V_78 )
V_150 = F_78 ( V_266 , V_194 -> V_184 ) ;
V_261:
F_48 ( & V_183 ) ;
if ( ! V_150 )
F_81 ( V_267 , & V_219 ) ;
return V_150 ;
}
T_1 F_82 ( struct V_17 * V_194 , struct V_71 * V_72 )
{
struct V_156 * V_157 ;
T_1 V_88 = 0 ;
F_46 ( & V_183 ) ;
if ( ( V_157 = F_77 ( V_72 , V_194 -> V_184 , 0 ) ) )
V_88 |= 1 << V_157 -> V_72 . V_78 ;
F_48 ( & V_183 ) ;
return V_88 ;
}
int F_61 ( struct V_17 * V_194 , struct V_71 * V_266 )
{
struct V_156 V_219 ;
int V_150 = 0 ;
V_219 . V_184 = V_194 -> V_184 ;
memcpy ( & V_219 . V_72 , V_266 , sizeof( V_219 . V_72 ) ) ;
if ( V_194 -> V_21 -> V_186 )
V_219 . V_158 = V_194 -> V_21 -> V_186 ( V_194 ) ;
F_46 ( & V_183 ) ;
if ( F_77 ( V_266 , V_194 -> V_184 , V_266 -> V_78 ) ) {
V_150 = - V_268 ;
goto V_261;
}
V_150 = F_78 ( V_266 , V_194 -> V_184 ) ;
V_261:
F_48 ( & V_183 ) ;
if ( ! V_150 )
F_81 ( V_267 , & V_219 ) ;
return V_150 ;
}
int F_64 ( struct V_17 * V_194 , struct V_71 * V_269 )
{
struct V_156 * V_157 ;
struct V_156 V_219 ;
int V_150 = - V_270 ;
V_219 . V_184 = V_194 -> V_184 ;
memcpy ( & V_219 . V_72 , V_269 , sizeof( V_219 . V_72 ) ) ;
if ( V_194 -> V_21 -> V_186 )
V_219 . V_158 = V_194 -> V_21 -> V_186 ( V_194 ) ;
F_46 ( & V_183 ) ;
if ( ( V_157 = F_77 ( V_269 , V_194 -> V_184 , V_269 -> V_78 ) ) ) {
F_80 ( & V_157 -> V_264 ) ;
F_43 ( V_157 ) ;
V_150 = 0 ;
}
F_48 ( & V_183 ) ;
if ( ! V_150 )
F_81 ( V_267 , & V_219 ) ;
return V_150 ;
}
static void F_83 ( void )
{
struct V_156 * V_72 ;
struct V_156 * V_271 ;
F_46 ( & V_183 ) ;
F_84 (app, tmp, &dcb_app_list, list) {
F_80 ( & V_72 -> V_264 ) ;
F_43 ( V_72 ) ;
}
F_48 ( & V_183 ) ;
}
static int T_4 F_85 ( void )
{
F_86 ( & V_265 ) ;
F_87 ( V_272 , V_273 , F_70 , NULL , NULL ) ;
F_87 ( V_272 , V_79 , F_70 , NULL , NULL ) ;
return 0 ;
}
static void T_5 F_88 ( void )
{
F_89 ( V_272 , V_273 ) ;
F_89 ( V_272 , V_79 ) ;
F_83 () ;
}
