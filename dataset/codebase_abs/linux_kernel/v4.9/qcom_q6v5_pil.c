static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 [ V_5 ] . V_4 = L_1 ;
V_2 -> V_4 [ V_6 ] . V_4 = L_2 ;
V_2 -> V_4 [ V_7 ] . V_4 = L_3 ;
V_2 -> V_4 [ V_8 ] . V_4 = L_4 ;
V_3 = F_2 ( V_2 -> V_9 ,
F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_9 , L_5 ) ;
return V_3 ;
}
F_5 ( V_2 -> V_4 [ V_5 ] . V_10 , 100000 ) ;
F_5 ( V_2 -> V_4 [ V_7 ] . V_10 , 100000 ) ;
F_5 ( V_2 -> V_4 [ V_8 ] . V_10 , 10000 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 [ V_7 ] . V_10 ;
struct V_11 * V_13 = V_2 -> V_4 [ V_6 ] . V_10 ;
int V_3 ;
V_3 = F_7 ( V_13 , 1050000 , V_14 ) ;
if ( V_3 )
return V_3 ;
F_7 ( V_12 , 1000000 , 1150000 ) ;
return F_8 ( F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 [ V_7 ] . V_10 ;
struct V_11 * V_13 = V_2 -> V_4 [ V_6 ] . V_10 ;
F_10 ( F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
F_7 ( V_13 , 0 , V_14 ) ;
F_7 ( V_12 , 0 , 1150000 ) ;
}
static int F_11 ( struct V_15 * V_15 , const struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
memcpy ( V_2 -> V_19 , V_17 -> V_20 , V_17 -> V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_22 )
{
unsigned long V_23 ;
T_1 V_24 ;
V_23 = V_25 + F_13 ( V_22 ) ;
for (; ; ) {
V_24 = F_14 ( V_2 -> V_26 + V_27 ) ;
if ( V_24 )
break;
if ( F_15 ( V_25 , V_23 ) )
return - V_28 ;
F_16 ( 1 ) ;
}
return V_24 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_29 , int V_22 )
{
unsigned long V_23 ;
T_1 V_24 ;
V_23 = V_25 + F_13 ( V_22 ) ;
for (; ; ) {
V_24 = F_14 ( V_2 -> V_26 + V_30 ) ;
if ( V_24 < 0 )
break;
if ( ! V_29 && V_24 )
break;
else if ( V_29 && V_24 == V_29 )
break;
if ( F_15 ( V_25 , V_23 ) )
return - V_28 ;
F_16 ( 1 ) ;
}
return V_24 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 V_24 ;
int V_3 ;
V_24 = F_14 ( V_2 -> V_31 + V_32 ) ;
V_24 |= ( V_33 | V_34 | V_35 ) ;
F_19 ( V_24 , V_2 -> V_31 + V_32 ) ;
V_24 = F_14 ( V_2 -> V_31 + V_36 ) ;
V_24 |= V_37 | V_38 ;
F_19 ( V_24 , V_2 -> V_31 + V_36 ) ;
F_20 ( 1 ) ;
V_24 = F_14 ( V_2 -> V_31 + V_36 ) ;
V_24 |= V_39 | V_40 |
V_41 | V_42 ;
F_19 ( V_24 , V_2 -> V_31 + V_36 ) ;
V_24 |= V_43 ;
F_19 ( V_24 , V_2 -> V_31 + V_36 ) ;
V_24 |= V_44 ;
F_19 ( V_24 , V_2 -> V_31 + V_36 ) ;
V_24 |= V_45 ;
F_19 ( V_24 , V_2 -> V_31 + V_36 ) ;
V_24 &= ~ V_46 ;
F_19 ( V_24 , V_2 -> V_31 + V_36 ) ;
V_24 = F_14 ( V_2 -> V_31 + V_32 ) ;
V_24 &= ~ V_33 ;
F_19 ( V_24 , V_2 -> V_31 + V_32 ) ;
V_24 = F_14 ( V_2 -> V_31 + V_47 ) ;
V_24 |= V_48 ;
F_19 ( V_24 , V_2 -> V_31 + V_47 ) ;
V_24 = F_14 ( V_2 -> V_31 + V_32 ) ;
V_24 &= ~ V_35 ;
F_19 ( V_24 , V_2 -> V_31 + V_32 ) ;
V_3 = F_12 ( V_2 , 1000 ) ;
if ( V_3 == - V_28 ) {
F_4 ( V_2 -> V_9 , L_6 ) ;
} else if ( V_3 != V_49 ) {
F_4 ( V_2 -> V_9 , L_7 , V_3 ) ;
V_3 = - V_50 ;
} else {
V_3 = 0 ;
}
return V_3 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
T_2 V_53 )
{
unsigned long V_23 ;
unsigned int V_24 ;
int V_3 ;
V_3 = F_22 ( V_52 , V_53 + V_54 , & V_24 ) ;
if ( ! V_3 && V_24 )
return;
F_23 ( V_52 , V_53 + V_55 , 1 ) ;
V_23 = V_25 + F_13 ( V_56 ) ;
for (; ; ) {
V_3 = F_22 ( V_52 , V_53 + V_57 , & V_24 ) ;
if ( V_3 || V_24 || F_15 ( V_25 , V_23 ) )
break;
F_16 ( 1 ) ;
}
V_3 = F_22 ( V_52 , V_53 + V_54 , & V_24 ) ;
if ( V_3 || ! V_24 )
F_4 ( V_2 -> V_9 , L_8 ) ;
F_23 ( V_52 , V_53 + V_55 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , const struct V_16 * V_17 )
{
unsigned long V_58 = V_59 ;
T_3 V_60 ;
void * V_61 ;
int V_3 ;
V_61 = F_25 ( V_2 -> V_9 , V_17 -> V_21 , & V_60 , V_62 , V_58 ) ;
if ( ! V_61 ) {
F_4 ( V_2 -> V_9 , L_9 ) ;
return - V_63 ;
}
memcpy ( V_61 , V_17 -> V_20 , V_17 -> V_21 ) ;
F_19 ( V_60 , V_2 -> V_26 + V_64 ) ;
F_19 ( V_65 , V_2 -> V_26 + V_66 ) ;
V_3 = F_17 ( V_2 , V_67 , 1000 ) ;
if ( V_3 == - V_28 )
F_4 ( V_2 -> V_9 , L_10 ) ;
else if ( V_3 < 0 )
F_4 ( V_2 -> V_9 , L_11 , V_3 ) ;
F_26 ( V_2 -> V_9 , V_17 -> V_21 , V_61 , V_60 , V_58 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_27 ( struct V_1 * V_2 , const struct V_16 * V_17 )
{
const struct V_68 * V_69 ;
const struct V_68 * V_70 ;
struct V_71 * V_72 ;
T_4 V_73 ;
T_4 V_74 ;
bool V_75 ;
T_5 V_21 ;
int V_3 ;
int V_76 ;
V_3 = F_28 ( V_17 , & V_74 , NULL , & V_75 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_12 ) ;
return V_3 ;
}
if ( V_75 )
V_73 = V_2 -> V_77 ;
else
V_73 = V_74 ;
V_72 = (struct V_71 * ) V_17 -> V_20 ;
V_69 = (struct V_68 * ) ( V_72 + 1 ) ;
for ( V_76 = 0 ; V_76 < V_72 -> V_78 ; V_76 ++ , V_70 ++ ) {
V_70 = & V_69 [ V_76 ] ;
if ( V_70 -> V_79 != V_80 )
continue;
if ( ( V_70 -> V_81 & V_82 ) == V_83 )
continue;
if ( ! V_70 -> V_84 )
continue;
V_21 = F_14 ( V_2 -> V_26 + V_85 ) ;
if ( ! V_21 ) {
F_19 ( V_73 , V_2 -> V_26 + V_86 ) ;
F_19 ( V_87 , V_2 -> V_26 + V_66 ) ;
}
V_21 += V_70 -> V_84 ;
F_19 ( V_21 , V_2 -> V_26 + V_85 ) ;
}
V_3 = F_17 ( V_2 , V_88 , 10000 ) ;
if ( V_3 == - V_28 )
F_4 ( V_2 -> V_9 , L_13 ) ;
else if ( V_3 < 0 )
F_4 ( V_2 -> V_9 , L_14 , V_3 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 ;
T_4 V_74 ;
bool V_75 ;
int V_3 ;
V_3 = F_30 ( & V_17 , V_89 , V_2 -> V_9 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_9 , L_15 V_89 L_16 ) ;
return V_3 ;
}
V_3 = F_28 ( V_17 , & V_74 , NULL , & V_75 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_12 ) ;
goto V_90;
}
if ( V_75 )
V_2 -> V_91 = V_74 ;
F_19 ( 0 , V_2 -> V_26 + V_85 ) ;
V_3 = F_24 ( V_2 , V_17 ) ;
if ( V_3 )
goto V_90;
V_3 = F_31 ( V_2 -> V_15 , V_17 , V_89 ) ;
if ( V_3 )
goto V_90;
V_3 = F_27 ( V_2 , V_17 ) ;
V_90:
V_90 ( V_17 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_32 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_18 ;
int V_3 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_17 ) ;
return V_3 ;
}
V_3 = F_33 ( V_2 -> V_92 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_18 ) ;
goto V_93;
}
V_3 = F_34 ( V_2 -> V_94 ) ;
if ( V_3 )
goto V_95;
V_3 = F_34 ( V_2 -> V_96 ) ;
if ( V_3 )
goto V_97;
V_3 = F_34 ( V_2 -> V_98 ) ;
if ( V_3 )
goto V_99;
F_19 ( V_2 -> V_100 , V_2 -> V_26 + V_101 ) ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 )
goto V_102;
V_3 = F_17 ( V_2 , 0 , 5000 ) ;
if ( V_3 == - V_28 ) {
F_4 ( V_2 -> V_9 , L_19 ) ;
goto V_102;
} else if ( V_3 != V_103 &&
V_3 != V_104 ) {
F_4 ( V_2 -> V_9 , L_20 , V_3 ) ;
V_3 = - V_50 ;
goto V_102;
}
F_35 ( V_2 -> V_9 , L_21 ) ;
V_3 = F_29 ( V_2 ) ;
if ( V_3 )
goto V_102;
V_3 = F_36 ( & V_2 -> V_105 ,
F_13 ( 5000 ) ) ;
if ( V_3 == 0 ) {
F_4 ( V_2 -> V_9 , L_22 ) ;
V_3 = - V_28 ;
goto V_102;
}
V_2 -> V_106 = true ;
return 0 ;
V_102:
F_21 ( V_2 , V_2 -> V_52 , V_2 -> V_107 ) ;
F_21 ( V_2 , V_2 -> V_52 , V_2 -> V_108 ) ;
F_21 ( V_2 , V_2 -> V_52 , V_2 -> V_109 ) ;
F_37 ( V_2 -> V_98 ) ;
V_99:
F_37 ( V_2 -> V_96 ) ;
V_97:
F_37 ( V_2 -> V_94 ) ;
V_95:
F_38 ( V_2 -> V_92 ) ;
V_93:
F_9 ( V_2 ) ;
return V_3 ;
}
static int F_39 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_18 ;
int V_3 ;
V_2 -> V_106 = false ;
F_40 ( V_2 -> V_110 ,
F_41 ( V_2 -> V_111 ) , F_41 ( V_2 -> V_111 ) ) ;
V_3 = F_36 ( & V_2 -> V_112 ,
F_13 ( 5000 ) ) ;
if ( V_3 == 0 )
F_4 ( V_2 -> V_9 , L_23 ) ;
F_40 ( V_2 -> V_110 , F_41 ( V_2 -> V_111 ) , 0 ) ;
F_21 ( V_2 , V_2 -> V_52 , V_2 -> V_107 ) ;
F_21 ( V_2 , V_2 -> V_52 , V_2 -> V_108 ) ;
F_21 ( V_2 , V_2 -> V_52 , V_2 -> V_109 ) ;
F_38 ( V_2 -> V_92 ) ;
F_37 ( V_2 -> V_98 ) ;
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_94 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void * F_42 ( struct V_15 * V_15 , T_6 V_113 , int V_114 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
int V_53 ;
V_53 = V_113 - V_2 -> V_91 ;
if ( V_53 < 0 || V_53 + V_114 > V_2 -> V_115 )
return NULL ;
return V_2 -> V_116 + V_53 ;
}
static T_7 F_43 ( int V_117 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
T_5 V_114 ;
char * V_118 ;
if ( ! V_2 -> V_106 ) {
F_44 ( & V_2 -> V_112 ) ;
return V_119 ;
}
V_118 = F_45 ( V_120 , V_121 , & V_114 ) ;
if ( ! F_46 ( V_118 ) && V_114 > 0 && V_118 [ 0 ] )
F_4 ( V_2 -> V_9 , L_24 , V_118 ) ;
else
F_4 ( V_2 -> V_9 , L_25 ) ;
F_47 ( V_2 -> V_15 , V_122 ) ;
if ( ! F_46 ( V_118 ) )
V_118 [ 0 ] = '\0' ;
return V_119 ;
}
static T_7 F_48 ( int V_117 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
T_5 V_114 ;
char * V_118 ;
V_118 = F_45 ( V_120 , V_121 , & V_114 ) ;
if ( ! F_46 ( V_118 ) && V_114 > 0 && V_118 [ 0 ] )
F_4 ( V_2 -> V_9 , L_26 , V_118 ) ;
else
F_4 ( V_2 -> V_9 , L_27 ) ;
F_47 ( V_2 -> V_15 , V_123 ) ;
if ( ! F_46 ( V_118 ) )
V_118 [ 0 ] = '\0' ;
return V_119 ;
}
static T_7 F_49 ( int V_117 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
F_44 ( & V_2 -> V_105 ) ;
return V_119 ;
}
static T_7 F_50 ( int V_117 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
F_44 ( & V_2 -> V_112 ) ;
return V_119 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
struct V_126 args ;
struct V_127 * V_128 ;
int V_3 ;
V_128 = F_52 ( V_125 , V_129 , L_28 ) ;
V_2 -> V_31 = F_53 ( & V_125 -> V_9 , V_128 ) ;
if ( F_46 ( V_2 -> V_31 ) )
return F_54 ( V_2 -> V_31 ) ;
V_128 = F_52 ( V_125 , V_129 , L_29 ) ;
V_2 -> V_26 = F_53 ( & V_125 -> V_9 , V_128 ) ;
if ( F_46 ( V_2 -> V_26 ) )
return F_54 ( V_2 -> V_26 ) ;
V_3 = F_55 ( V_125 -> V_9 . V_130 ,
L_30 , 3 , 0 , & args ) ;
if ( V_3 < 0 ) {
F_4 ( & V_125 -> V_9 , L_31 ) ;
return - V_50 ;
}
V_2 -> V_52 = F_56 ( args . V_131 ) ;
F_57 ( args . V_131 ) ;
if ( F_46 ( V_2 -> V_52 ) )
return F_54 ( V_2 -> V_52 ) ;
V_2 -> V_107 = args . args [ 0 ] ;
V_2 -> V_108 = args . args [ 1 ] ;
V_2 -> V_109 = args . args [ 2 ] ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
V_2 -> V_94 = F_59 ( V_2 -> V_9 , L_32 ) ;
if ( F_46 ( V_2 -> V_94 ) ) {
F_4 ( V_2 -> V_9 , L_33 ) ;
return F_54 ( V_2 -> V_94 ) ;
}
V_2 -> V_96 = F_59 ( V_2 -> V_9 , L_34 ) ;
if ( F_46 ( V_2 -> V_96 ) ) {
F_4 ( V_2 -> V_9 , L_35 ) ;
return F_54 ( V_2 -> V_96 ) ;
}
V_2 -> V_98 = F_59 ( V_2 -> V_9 , L_36 ) ;
if ( F_46 ( V_2 -> V_98 ) ) {
F_4 ( V_2 -> V_9 , L_37 ) ;
return F_54 ( V_2 -> V_98 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
V_2 -> V_92 = F_61 ( V_2 -> V_9 , NULL ) ;
if ( F_46 ( V_2 -> V_92 ) ) {
F_4 ( V_2 -> V_9 , L_38 ) ;
return F_54 ( V_2 -> V_92 ) ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
const char * V_132 ,
T_8 V_133 )
{
int V_3 ;
V_3 = F_63 ( V_125 , V_132 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_125 -> V_9 , L_39 , V_132 ) ;
return V_3 ;
}
V_3 = F_64 ( & V_125 -> V_9 , V_3 ,
NULL , V_133 ,
V_134 | V_135 ,
L_40 , V_2 ) ;
if ( V_3 )
F_4 ( & V_125 -> V_9 , L_41 , V_132 ) ;
return V_3 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_136 * V_137 ;
struct V_136 * V_138 ;
struct V_127 V_139 ;
int V_3 ;
V_137 = F_66 ( V_2 -> V_9 -> V_130 , L_42 ) ;
V_138 = F_67 ( V_137 , L_43 , 0 ) ;
V_3 = F_68 ( V_138 , 0 , & V_139 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_44 ) ;
return V_3 ;
}
V_2 -> V_100 = V_139 . V_140 ;
V_2 -> V_141 = F_69 ( & V_139 ) ;
V_2 -> V_19 = F_70 ( V_2 -> V_9 , V_2 -> V_100 , V_2 -> V_141 ) ;
if ( ! V_2 -> V_19 ) {
F_4 ( V_2 -> V_9 , L_45 ,
& V_139 . V_140 , V_2 -> V_141 ) ;
return - V_142 ;
}
V_137 = F_66 ( V_2 -> V_9 -> V_130 , L_46 ) ;
V_138 = F_67 ( V_137 , L_43 , 0 ) ;
V_3 = F_68 ( V_138 , 0 , & V_139 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_47 ) ;
return V_3 ;
}
V_2 -> V_77 = V_2 -> V_91 = V_139 . V_140 ;
V_2 -> V_115 = F_69 ( & V_139 ) ;
V_2 -> V_116 = F_70 ( V_2 -> V_9 , V_2 -> V_77 , V_2 -> V_115 ) ;
if ( ! V_2 -> V_116 ) {
F_4 ( V_2 -> V_9 , L_45 ,
& V_139 . V_140 , V_2 -> V_115 ) ;
return - V_142 ;
}
return 0 ;
}
static int F_71 ( struct V_124 * V_125 )
{
struct V_1 * V_2 ;
struct V_15 * V_15 ;
int V_3 ;
V_15 = F_72 ( & V_125 -> V_9 , V_125 -> V_132 , & V_143 ,
V_144 , sizeof( * V_2 ) ) ;
if ( ! V_15 ) {
F_4 ( & V_125 -> V_9 , L_48 ) ;
return - V_63 ;
}
V_15 -> V_145 = & V_146 ;
V_2 = (struct V_1 * ) V_15 -> V_18 ;
V_2 -> V_9 = & V_125 -> V_9 ;
V_2 -> V_15 = V_15 ;
F_73 ( V_125 , V_2 ) ;
F_74 ( & V_2 -> V_105 ) ;
F_74 ( & V_2 -> V_112 ) ;
V_3 = F_51 ( V_2 , V_125 ) ;
if ( V_3 )
goto V_147;
V_3 = F_65 ( V_2 ) ;
if ( V_3 )
goto V_147;
V_3 = F_58 ( V_2 ) ;
if ( V_3 )
goto V_147;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_147;
V_3 = F_60 ( V_2 ) ;
if ( V_3 )
goto V_147;
V_3 = F_62 ( V_2 , V_125 , L_49 , F_43 ) ;
if ( V_3 < 0 )
goto V_147;
V_3 = F_62 ( V_2 , V_125 , L_50 , F_48 ) ;
if ( V_3 < 0 )
goto V_147;
V_3 = F_62 ( V_2 , V_125 , L_51 , F_49 ) ;
if ( V_3 < 0 )
goto V_147;
V_3 = F_62 ( V_2 , V_125 , L_52 , F_50 ) ;
if ( V_3 < 0 )
goto V_147;
V_2 -> V_110 = F_75 ( & V_125 -> V_9 , L_53 , & V_2 -> V_111 ) ;
if ( F_46 ( V_2 -> V_110 ) ) {
V_3 = F_54 ( V_2 -> V_110 ) ;
goto V_147;
}
V_3 = F_76 ( V_15 ) ;
if ( V_3 )
goto V_147;
return 0 ;
V_147:
F_77 ( V_15 ) ;
return V_3 ;
}
static int F_78 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_79 ( V_125 ) ;
F_80 ( V_2 -> V_15 ) ;
F_77 ( V_2 -> V_15 ) ;
return 0 ;
}
