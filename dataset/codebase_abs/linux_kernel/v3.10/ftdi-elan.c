static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_4 -> V_5 , L_1 , V_3 ) ;
F_4 ( V_3 -> V_4 ) ;
V_3 -> V_6 += 1 ;
F_5 ( & V_7 ) ;
F_6 ( & V_3 -> V_8 ) ;
V_9 -= 1 ;
F_7 ( & V_7 ) ;
F_8 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_12 ( & V_3 -> V_1 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_14 ( & V_3 -> V_1 ) ;
}
static void F_15 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( ! F_16 ( V_12 , & V_3 -> V_13 , V_11 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( F_16 ( V_12 , & V_3 -> V_13 , V_11 ) )
F_12 ( & V_3 -> V_1 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_13 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_20 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( ! F_16 ( V_14 , & V_3 -> V_15 , V_11 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_21 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( F_16 ( V_14 , & V_3 -> V_15 , V_11 ) )
F_12 ( & V_3 -> V_1 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_15 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
unsigned int V_11 )
{
if ( ! F_16 ( V_16 , & V_3 -> V_17 , V_11 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_24 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( F_16 ( V_16 , & V_3 -> V_17 , V_11 ) )
F_12 ( & V_3 -> V_1 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_17 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
void F_26 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
V_3 -> V_20 += 1 ;
F_9 ( V_3 ) ;
}
static void F_28 ( struct V_21 * V_5 )
{
V_5 -> V_22 = NULL ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_23 ;
if ( V_3 -> V_24 . V_5 . V_22 )
return - V_25 ;
F_11 ( V_3 ) ;
V_3 -> V_26 . V_27 = 100 ;
V_3 -> V_26 . V_28 = NULL ;
V_3 -> V_24 . V_29 = V_3 -> V_30 ;
V_3 -> V_24 . V_31 = V_3 -> V_32 ;
V_3 -> V_24 . V_33 = F_30 ( V_3 -> V_32 ) ;
V_3 -> V_24 . V_5 . V_26 = & V_3 -> V_26 ;
V_3 -> V_24 . V_5 . V_22 = NULL ;
V_3 -> V_24 . V_5 . V_34 = F_28 ;
V_3 -> V_24 . V_5 . V_35 = NULL ;
snprintf ( V_3 -> V_36 , sizeof( V_3 -> V_36 ) , L_2 ) ;
V_3 -> V_24 . V_37 = V_3 -> V_36 ;
F_31 ( & V_3 -> V_4 -> V_5 , L_3 , L_2 ) ;
F_32 ( L_2 ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_4 ,
V_3 -> V_24 . V_37 ) ;
V_23 = F_33 ( & V_3 -> V_24 ) ;
return V_23 ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_5 ( & V_3 -> V_38 ) ;
while ( V_3 -> V_39 > V_3 -> V_40 ) {
struct V_41 * V_42 = & V_3 -> V_42 [ V_43 &
V_3 -> V_40 ++ ] ;
* V_42 -> V_23 = - V_44 ;
* V_42 -> V_45 = 0 ;
F_35 ( & V_42 -> V_46 ) ;
} F_7 ( & V_3 -> V_38 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
int V_47 = 4 ;
F_5 ( & V_3 -> V_38 ) ;
while ( V_47 -- > 0 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_47 ] ;
if ( V_49 -> V_50 == 1 ) {
V_49 -> V_51 = V_52 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , NULL , 0 ) ;
F_5 ( & V_3 -> V_38 ) ;
}
}
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
int V_47 = 4 ;
F_5 ( & V_3 -> V_38 ) ;
while ( V_47 -- > 0 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_47 ] ;
V_49 -> V_56 = 1 ;
V_57: if ( V_49 -> V_50 == 1 ) {
int V_58 = V_3 -> V_59 -
V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x80 | ( V_47 << 5 ) | 0x4 ;
V_63 -> V_66 = 0x00 ;
V_63 -> V_67 = 0x00 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_38 ) ;
goto V_57;
}
}
V_71: if ( V_49 -> V_50 == 1 ) {
int V_58 = V_3 -> V_59 -
V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x90 | ( V_47 << 5 ) ;
V_63 -> V_66 = 0x00 ;
V_63 -> V_67 = 0x00 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_38 ) ;
goto V_71;
}
}
}
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
int V_47 = 4 ;
F_5 ( & V_3 -> V_38 ) ;
while ( V_47 -- > 0 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_47 ] ;
V_49 -> V_56 = 1 ;
V_72: if ( V_49 -> V_50 == 1 ) {
int V_58 = V_3 -> V_59 -
V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x80 | ( V_47 << 5 ) | 0x4 ;
V_63 -> V_66 = 0x00 ;
V_63 -> V_67 = 0x00 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_38 ) ;
goto V_72;
}
}
}
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_21 ( V_3 , 0 ) ;
}
static void F_42 ( struct V_73 * V_74 )
{
struct V_2 * V_3 =
F_43 ( V_74 , struct V_2 , V_15 . V_74 ) ;
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else {
int V_75 = F_44 ( V_3 ) ;
if ( V_75 == - V_44 ) {
V_3 -> V_6 += 1 ;
} else if ( V_75 == - V_76 ) {
V_3 -> V_6 += 1 ;
} else if ( V_75 )
F_45 ( & V_3 -> V_4 -> V_5 , L_5 , V_75 ) ;
F_20 ( V_3 , F_46 ( 10 ) ) ;
return;
}
}
static void F_47 ( struct V_2 * V_3 )
{
F_24 ( V_3 , 0 ) ;
}
static void F_48 ( struct V_73 * V_74 )
{
struct V_2 * V_3 =
F_43 ( V_74 , struct V_2 , V_17 . V_74 ) ;
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else {
int V_75 = F_49 ( V_3 ) ;
if ( V_75 == 0 ) {
} else if ( V_75 == - V_44 ) {
V_3 -> V_6 += 1 ;
} else if ( V_75 == - V_76 ) {
V_3 -> V_6 += 1 ;
} else if ( V_75 == - V_77 ) {
V_3 -> V_6 += 1 ;
} else {
V_3 -> V_6 += 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_6 , V_75 ) ;
}
if ( V_3 -> V_6 > 0 ) {
F_34 ( V_3 ) ;
F_36 ( V_3 ) ;
}
F_23 ( V_3 , F_46 ( 10 ) ) ;
return;
}
}
static void F_50 ( struct V_73 * V_74 )
{
struct V_2 * V_3 =
F_43 ( V_74 , struct V_2 , V_13 . V_74 ) ;
int V_78 = 0 ;
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else if ( V_3 -> V_79 == 0 ) {
F_51 ( & V_3 -> V_80 ) ;
if ( F_52 ( V_3 ) == 0 ) {
V_3 -> V_79 = 1 ;
F_21 ( V_3 , 1 ) ;
F_24 ( V_3 , 1 ) ;
F_53 ( & V_3 -> V_80 ) ;
V_78 = 100 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_7 ) ;
F_53 ( & V_3 -> V_80 ) ;
V_78 = 10 * 1000 ;
}
} else if ( V_3 -> V_81 > 0 ) {
if ( F_54 ( V_3 ) == 0 ) {
V_3 -> V_81 = 0 ;
V_3 -> V_79 = 0 ;
} else if ( ( V_3 -> V_81 ++ % 60 ) == 1 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_8
L_9 ) ;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_8
L_10 , V_3 -> V_81 ) ;
V_78 = 100 ;
} else if ( V_3 -> V_82 == 0 ) {
if ( F_55 ( V_3 ) == 0 ) {
V_3 -> V_82 = 1 ;
V_78 = 250 ;
} else
V_78 = 1000 ;
} else if ( V_3 -> V_83 == 0 ) {
if ( F_56 ( V_3 ) == 0 ) {
V_3 -> V_83 = 1 ;
V_78 = 500 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_11
L_12 ) ;
V_78 = 1 * 1000 ;
}
} else if ( V_3 -> V_84 == 0 ) {
V_78 = 10 ;
if ( F_29 ( V_3 ) == 0 ) {
V_3 -> V_84 = 1 ;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_13 ) ;
V_78 = 250 ;
} else {
if ( F_57 ( V_3 ) == 0 ) {
V_78 = 250 ;
} else if ( V_3 -> V_85 & 0x00400000 ) {
if ( V_3 -> V_20 > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_14
L_15
L_16 ,
V_3 -> V_24 . V_5 . V_22 ,
& V_3 -> V_24 . V_5 ) ;
F_58 ( & V_3 -> V_24 ) ;
V_3 -> V_24 . V_5 . V_22 = NULL ;
V_3 -> V_84 = 0 ;
V_3 -> V_82 = 0 ;
V_3 -> V_86 = 0 ;
V_3 -> V_83 = 0 ;
V_3 -> V_20 = 0 ;
} else
F_38 ( V_3 ) ;
V_78 = 250 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_17
) ;
F_41 ( V_3 ) ;
V_78 = 500 ;
V_3 -> V_82 = 0 ;
V_3 -> V_83 = 0 ;
}
}
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else {
F_15 ( V_3 ,
F_46 ( V_78 ) ) ;
return;
}
}
static int F_59 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
int V_89 ;
struct V_90 * V_91 ;
V_89 = F_60 ( V_87 ) ;
V_91 = F_61 ( & V_92 , V_89 ) ;
if ( ! V_91 ) {
F_62 ( V_93 L_18 , V_89 ) ;
return - V_76 ;
} else {
struct V_2 * V_3 = F_63 ( V_91 ) ;
if ( ! V_3 ) {
return - V_76 ;
} else {
if ( F_64 ( & V_3 -> V_80 ) ) {
return - V_94 ;
} else {
F_11 ( V_3 ) ;
V_88 -> V_95 = V_3 ;
return 0 ;
}
}
}
}
static int F_65 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_95 ;
if ( V_3 == NULL )
return - V_76 ;
F_53 ( & V_3 -> V_80 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static T_1 F_66 ( struct V_88 * V_88 , char T_2 * V_70 ,
T_3 V_96 , T_4 * V_97 )
{
char V_98 [ 30 * 3 + 4 ] ;
char * V_99 = V_98 ;
int V_100 = ( sizeof( V_98 ) - 1 ) / 3 ;
int V_101 = 0 ;
int V_102 = 10 ;
int V_103 = 5 ;
struct V_2 * V_3 = V_88 -> V_95 ;
if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
}
V_98 [ 0 ] = 0 ;
V_104: if ( V_3 -> V_105 > 0 ) {
if ( V_96 -- > 0 ) {
char * V_106 = ++ V_3 -> V_107 + V_3 -> V_10 ;
V_3 -> V_105 -= 1 ;
if ( V_101 < V_100 ) {
V_99 += sprintf ( V_99 , L_19 , 0x000000FF & * V_106 ) ;
} else if ( V_101 > V_100 ) {
} else
V_99 += sprintf ( V_99 , L_20 ) ;
if ( F_67 ( V_70 ++ , V_106 , 1 ) ) {
return - V_108 ;
} else {
V_101 += 1 ;
goto V_104;
}
} else
return V_101 ;
}
V_109: if ( V_96 > 0 ) {
int V_110 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_111 ) ,
V_3 -> V_10 , V_3 -> V_112 ,
& V_110 , 50 ) ;
if ( V_110 > 2 ) {
V_3 -> V_105 = V_110 - 2 ;
V_3 -> V_107 = 1 ;
goto V_104;
} else if ( V_75 == - V_113 ) {
if ( V_103 -- > 0 ) {
goto V_109;
} else if ( V_101 > 0 ) {
return V_101 ;
} else
return V_75 ;
} else if ( V_75 == 0 ) {
if ( V_102 -- > 0 ) {
goto V_109;
} else
return V_101 ;
} else
return V_75 ;
} else
return V_101 ;
}
static void F_70 ( struct V_114 * V_114 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
int V_116 = V_114 -> V_116 ;
if ( V_116 && ! ( V_116 == - V_117 || V_116 == - V_118 ||
V_116 == - V_44 ) ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_21
L_22 , V_114 , V_116 ) ;
}
F_71 ( V_114 -> V_5 , V_114 -> V_119 ,
V_114 -> V_120 , V_114 -> V_121 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
char * V_122 , int V_58 , int V_123 )
{
int V_124 = 0 ;
int V_125 = 0 ;
int V_126 = V_58 ;
int V_127 = V_3 -> V_60 ;
while ( V_126 -- > 0 ) {
struct V_62 * V_63 = & V_3 -> V_63 [ V_64 &
V_127 ++ ] ;
int V_128 = V_63 -> V_69 ;
T_5 * V_129 = V_63 -> V_70 ;
if ( V_63 -> V_65 & 0x80 ) {
V_124 |= 1 << ( 0x3 & ( V_63 -> V_65 >> 5 ) ) ;
}
V_122 [ V_125 ++ ] = V_63 -> V_65 ;
V_122 [ V_125 ++ ] = ( V_63 -> V_66 >> 0 ) & 0x00FF ;
V_122 [ V_125 ++ ] = ( V_63 -> V_66 >> 8 ) & 0x00FF ;
V_122 [ V_125 ++ ] = V_63 -> V_67 ;
V_122 [ V_125 ++ ] = V_63 -> V_68 ;
while ( V_128 -- > 0 ) {
V_122 [ V_125 ++ ] = * V_129 ++ ;
}
}
return V_124 ;
}
static int F_73 ( struct V_2 * V_3 , int V_58 )
{
int V_123 = 0 ;
int V_126 = V_58 ;
int V_127 = V_3 -> V_60 ;
while ( V_126 -- > 0 ) {
struct V_62 * V_63 = & V_3 -> V_63 [ V_64 &
V_127 ++ ] ;
V_123 += 5 + V_63 -> V_69 ;
} return V_123 ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_75 ;
char * V_122 ;
int V_124 ;
int V_123 ;
struct V_114 * V_114 ;
int V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 == 0 )
return 0 ;
V_123 = F_73 ( V_3 , V_58 ) ;
V_114 = F_74 ( 0 , V_130 ) ;
if ( ! V_114 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_23
L_24 , V_58 ,
V_123 ) ;
return - V_131 ;
}
V_122 = F_75 ( V_3 -> V_4 , V_123 , V_130 ,
& V_114 -> V_121 ) ;
if ( ! V_122 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_25
L_26 , V_58 ,
V_123 ) ;
F_76 ( V_114 ) ;
return - V_131 ;
}
V_124 = F_72 ( V_3 , V_122 ,
V_58 , V_123 ) ;
F_77 ( V_114 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_132 ) , V_122 , V_123 ,
F_70 , V_3 ) ;
V_114 -> V_133 |= V_134 ;
if ( V_124 ) {
char V_135 [ 40 * 3 + 4 ] ;
char * V_99 = V_135 ;
int V_100 = V_123 ;
T_5 * V_136 = V_122 ;
int V_137 = ( sizeof( V_135 ) - 1 ) / 3 ;
V_135 [ 0 ] = 0 ;
while ( V_137 -- > 0 && V_100 -- > 0 ) {
if ( V_137 > 0 || V_100 == 0 ) {
V_99 += sprintf ( V_99 , L_19 , * V_136 ++ ) ;
} else
V_99 += sprintf ( V_99 , L_20 ) ;
}
}
V_75 = F_79 ( V_114 , V_130 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_27
L_28 , V_75 ,
V_114 , V_58 , V_123 ) ;
F_71 ( V_3 -> V_4 , V_123 , V_122 , V_114 -> V_121 ) ;
F_76 ( V_114 ) ;
return V_75 ;
}
F_76 ( V_114 ) ;
V_3 -> V_60 += V_58 ;
F_47 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_48 * V_49 , T_5 * V_70 , int V_66 )
{
struct V_114 * V_114 = V_49 -> V_114 ;
int V_138 = V_49 -> V_138 ;
int V_139 = V_49 -> V_139 ;
int V_140 = V_49 -> V_140 ;
int V_141 = V_49 -> V_141 ;
int V_142 = V_49 -> V_142 ;
int V_143 = V_49 -> V_143 ;
int V_51 = V_49 -> V_51 ;
int V_144 = V_49 -> V_144 ;
void (* F_80) ( void * , struct V_114 * , T_5 * , int , int , int , int , int ,
int , int , int , int ) = V_49 -> F_80 ;
V_49 -> V_50 -= 1 ;
V_49 -> F_80 = NULL ;
(* F_80) ( V_49 -> V_145 , V_114 , V_70 , V_66 , V_142 ,
V_143 , V_51 , V_144 , V_138 , V_139 ,
V_140 , V_141 ) ;
}
static char * F_81 ( struct V_2 * V_3 ,
struct V_48 * V_49 , T_6 V_146 , int V_47 , int V_147 ,
char * V_125 )
{
int V_148 = ( V_146 >> 0 ) & 0x07FF ;
F_5 ( & V_3 -> V_38 ) ;
V_49 -> V_140 = 0 ;
V_49 -> V_141 = ( V_146 >> 15 ) & 0x0001 ;
V_49 -> V_144 = ( V_146 >> 11 ) & 0x000F ;
if ( V_147 == 0x02 ) {
if ( V_148 == 0 || V_49 -> V_56 > 0 ) {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_149 ,
V_148 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_149 ;
} else {
V_3 -> V_54 = 4 + V_148 ;
V_3 -> V_55 = 1 ;
F_7 ( & V_3 -> V_38 ) ;
return V_125 ;
}
} else if ( V_147 == 0x03 ) {
if ( V_148 == 0 || V_49 -> V_56 > 0 ) {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_149 ,
V_148 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_149 ;
} else {
V_3 -> V_54 = 4 + V_148 ;
V_3 -> V_55 = 1 ;
F_7 ( & V_3 -> V_38 ) ;
return V_125 ;
}
} else if ( V_147 == 0x01 ) {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_149 ,
V_148 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_149 ;
} else {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_149 ,
V_148 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_149 ;
}
}
static char * F_82 ( struct V_2 * V_3 ,
struct V_48 * V_49 , T_6 V_146 , int V_47 , int V_147 ,
char * V_125 )
{
F_5 ( & V_3 -> V_38 ) ;
V_49 -> V_51 = V_52 ;
V_49 -> V_140 = ( V_146 >> 0 ) & 0x01FF ;
V_49 -> V_141 = ( V_146 >> 15 ) & 0x0001 ;
V_49 -> V_144 = ( V_146 >> 11 ) & 0x000F ;
F_7 ( & V_3 -> V_38 ) ;
if ( V_49 -> V_50 )
F_37 ( V_3 , V_49 , NULL , 0 ) ;
V_49 -> V_56 = 0 ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_149 ;
}
static int F_49 ( struct V_2 * V_3 )
{
T_5 * V_125 = V_3 -> V_149 + V_3 -> V_53 ;
int V_101 = 0 ;
int V_102 = 1 ;
int V_103 = 3 ;
int V_150 = 0 ;
V_151: {
int V_110 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_111 ) ,
V_3 -> V_10 , V_3 -> V_112 ,
& V_110 , 500 ) ;
char V_135 [ 30 * 3 + 4 ] ;
char * V_99 = V_135 ;
int V_100 = V_110 ;
T_5 * V_136 = V_3 -> V_10 ;
int V_137 = ( sizeof( V_135 ) - 1 ) / 3 ;
V_135 [ 0 ] = 0 ;
while ( V_137 -- > 0 && V_100 -- > 0 ) {
if ( V_137 > 0 || V_100 == 0 ) {
V_99 += sprintf ( V_99 , L_19 , * V_136 ++ ) ;
} else
V_99 += sprintf ( V_99 , L_20 ) ;
}
if ( V_110 > 2 ) {
V_3 -> V_105 = V_110 - 2 ;
V_3 -> V_107 = 1 ;
goto V_104;
} else if ( V_75 == - V_113 ) {
if ( V_103 -- > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_29
L_30 ,
V_110 , V_101 , V_135 ) ;
goto V_109;
} else if ( V_101 > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_31 ,
V_101 , V_135 ) ;
return - V_131 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_29
L_30 ,
V_110 , V_101 , V_135 ) ;
return - V_131 ;
}
} else if ( V_75 == - V_77 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_32
L_33 , V_75 ,
V_110 , V_101 , V_135 ) ;
return V_75 ;
} else if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_32
L_33 , V_75 ,
V_110 , V_101 , V_135 ) ;
return V_75 ;
} else if ( V_110 == 2 ) {
unsigned char V_152 = V_3 -> V_10 [ 0 ] ;
unsigned char V_153 = V_3 -> V_10 [ 1 ] ;
V_150 += 1 ;
if ( V_152 == 0x31 && V_153 == 0x60 ) {
if ( V_102 -- > 0 ) {
goto V_109;
} else
return 0 ;
} else if ( V_152 == 0x31 && V_153 == 0x00 ) {
if ( V_102 -- > 0 ) {
goto V_109;
} else
return 0 ;
} else {
if ( V_102 -- > 0 ) {
goto V_109;
} else
return 0 ;
}
} else if ( V_110 == 1 ) {
if ( V_102 -- > 0 ) {
goto V_109;
} else
return 0 ;
} else {
if ( V_102 -- > 0 ) {
goto V_109;
} else
return 0 ;
}
}
V_109: {
goto V_151;
}
V_104: if ( V_3 -> V_105 > 0 ) {
T_5 V_136 = V_3 -> V_10 [ ++ V_3 -> V_107 ] ;
V_101 += 1 ;
V_3 -> V_105 -= 1 ;
if ( V_3 -> V_53 == 0 && V_136 == 0xFF ) {
goto V_104;
} else
* V_125 ++ = V_136 ;
if ( ++ V_3 -> V_53 < V_3 -> V_54 ) {
goto V_104;
} else if ( V_3 -> V_55 ) {
int V_47 = ( V_3 -> V_149 [ 0 ] >> 5 ) & 0x03 ;
T_6 V_146 = ( V_3 -> V_149 [ 2 ] << 8 ) |
V_3 -> V_149 [ 1 ] ;
struct V_48 * V_49 = & V_3 -> V_49 [ V_47 ] ;
int V_148 = ( V_146 >> 0 ) & 0x07FF ;
char V_135 [ 30 * 3 + 4 ] ;
char * V_99 = V_135 ;
int V_100 = V_148 ;
T_5 * V_136 = 4 + V_3 -> V_149 ;
int V_137 = ( sizeof( V_135 ) - 1 ) / 3 ;
V_135 [ 0 ] = 0 ;
while ( V_137 -- > 0 && V_100 -- > 0 ) {
if ( V_137 > 0 || V_100 == 0 ) {
V_99 += sprintf ( V_99 , L_19 , * V_136 ++ ) ;
} else
V_99 += sprintf ( V_99 , L_20 ) ;
}
F_37 ( V_3 , V_49 , 4 + V_3 -> V_149 ,
V_148 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
V_125 = V_3 -> V_149 ;
goto V_104;
} else if ( V_3 -> V_54 == 8 ) {
T_5 V_154 ;
int V_40 = V_3 -> V_40 ++ ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_40 ] ;
T_7 V_98 = V_3 -> V_149 [ 7 ] ;
V_98 <<= 8 ;
V_98 |= V_3 -> V_149 [ 6 ] ;
V_98 <<= 8 ;
V_98 |= V_3 -> V_149 [ 5 ] ;
V_98 <<= 8 ;
V_98 |= V_3 -> V_149 [ 4 ] ;
* V_42 -> V_45 = V_98 ;
* V_42 -> V_23 = 0 ;
F_35 ( & V_42 -> V_46 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
V_125 = V_3 -> V_149 ;
V_154 = ( V_3 -> V_149 [ 0 ] >> 0 ) & 0x0F ;
if ( V_154 == 0x00 ) {
} else if ( V_154 == 0x02 ) {
} else if ( V_154 == 0x06 ) {
} else if ( V_154 == 0x0A ) {
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_34
L_35 , V_154 , V_98 ) ;
goto V_104;
} else {
if ( ( V_3 -> V_149 [ 0 ] & 0x80 ) == 0x00 ) {
V_3 -> V_54 = 8 ;
goto V_104;
} else {
int V_47 = ( V_3 -> V_149 [ 0 ] >> 5 ) & 0x03 ;
int V_147 = ( V_3 -> V_149 [ 0 ] >> 0 ) & 0x03 ;
T_6 V_146 = ( V_3 -> V_149 [ 2 ] << 8 ) |
V_3 -> V_149 [ 1 ] ;
struct V_48 * V_49 = & V_3 -> V_49 [
V_47 ] ;
V_49 -> V_138 = ( V_3 -> V_149 [ 0 ] >> 3 ) &
0x01 ;
V_49 -> V_139 = ( V_3 -> V_149 [ 0 ] >> 2 ) &
0x01 ;
V_49 -> V_142 = ( V_3 -> V_149 [ 3 ] >> 6 )
& 0x03 ;
V_49 -> V_143 = ( V_3 -> V_149 [ 3 ] >> 4 )
& 0x03 ;
V_49 -> V_51 = ( V_3 -> V_149 [
3 ] >> 0 ) & 0x0F ;
if ( ( V_3 -> V_149 [ 0 ] & 0x10 ) == 0x00 ) {
V_125 = F_81 ( V_3 , V_49 ,
V_146 , V_47 , V_147 ,
V_125 ) ;
goto V_104;
} else {
V_125 = F_82 ( V_3 , V_49 ,
V_146 , V_47 , V_147 ,
V_125 ) ;
goto V_104;
}
}
}
} else
goto V_109;
}
static T_1 F_83 ( struct V_88 * V_88 ,
const char T_2 * V_155 , T_3 V_96 ,
T_4 * V_97 )
{
int V_75 = 0 ;
struct V_114 * V_114 ;
char * V_122 ;
struct V_2 * V_3 = V_88 -> V_95 ;
if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
}
if ( V_96 == 0 ) {
goto exit;
}
V_114 = F_74 ( 0 , V_130 ) ;
if ( ! V_114 ) {
V_75 = - V_131 ;
goto V_156;
}
V_122 = F_75 ( V_3 -> V_4 , V_96 , V_130 ,
& V_114 -> V_121 ) ;
if ( ! V_122 ) {
V_75 = - V_131 ;
goto V_157;
}
if ( F_84 ( V_122 , V_155 , V_96 ) ) {
V_75 = - V_108 ;
goto V_158;
}
F_77 ( V_114 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_132 ) , V_122 , V_96 ,
F_70 , V_3 ) ;
V_114 -> V_133 |= V_134 ;
V_75 = F_79 ( V_114 , V_130 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_36
L_22 , V_75 ) ;
goto V_158;
}
F_76 ( V_114 ) ;
exit:
return V_96 ;
V_158:
F_71 ( V_3 -> V_4 , V_96 , V_122 , V_114 -> V_121 ) ;
V_157:
F_76 ( V_114 ) ;
V_156:
return V_75 ;
}
static int F_85 ( struct V_2 * V_3 , T_7 V_98 )
{
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x00 | V_159 ;
V_63 -> V_66 = 0x04 ;
V_63 -> V_67 = 0x00 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 4 ;
V_63 -> V_45 = V_98 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
static int F_86 ( struct V_2 * V_3 , int V_160 ,
T_5 V_68 , T_7 V_98 )
{
T_5 V_161 = V_160 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x00 | ( V_162 & 0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_63 -> V_67 = V_161 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 4 ;
V_63 -> V_45 = V_98 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
static int F_87 ( struct V_2 * V_3 , int V_163 ,
T_5 V_68 , T_7 V_98 )
{
T_5 V_161 = V_163 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x00 | ( V_164 & 0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_63 -> V_67 = V_161 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 4 ;
V_63 -> V_45 = V_98 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_88 ( struct V_18 * V_19 , int V_163 ,
T_5 V_68 , T_7 V_98 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_87 ( V_3 , V_163 , V_68 , V_98 ) ;
}
static int F_89 ( struct V_2 * V_3 , T_7 * V_98 )
{
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
int V_165 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
V_165 = V_3 -> V_39 - V_3 -> V_40 ;
if ( V_58 < V_61 && V_165 < V_166 )
{
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_3 -> V_39 ] ;
int V_23 = - V_76 ;
V_42 -> V_23 = & V_23 ;
V_42 -> V_65 = V_63 -> V_65 = 0x00 | V_167 ;
V_63 -> V_66 = 0x04 ;
V_42 -> V_67 = V_63 -> V_67 = V_168 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_42 -> V_45 = V_98 ;
F_90 ( & V_42 -> V_46 ) ;
V_3 -> V_59 += 1 ;
V_3 -> V_39 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
F_91 ( & V_42 -> V_46 ) ;
return V_23 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
static int F_92 ( struct V_2 * V_3 , int V_160 ,
T_5 V_68 , T_7 * V_98 )
{
T_5 V_161 = V_160 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
int V_165 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
V_165 = V_3 -> V_39 - V_3 -> V_40 ;
if ( V_58 < V_61 && V_165 < V_166 )
{
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_3 -> V_39 ] ;
int V_23 = - V_76 ;
V_42 -> V_23 = & V_23 ;
V_42 -> V_65 = V_63 -> V_65 = 0x00 | ( V_169 &
0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_42 -> V_67 = V_63 -> V_67 = V_161 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_42 -> V_45 = V_98 ;
F_90 ( & V_42 -> V_46 ) ;
V_3 -> V_59 += 1 ;
V_3 -> V_39 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
F_91 ( & V_42 -> V_46 ) ;
return V_23 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
static int F_93 ( struct V_2 * V_3 , int V_163 ,
T_5 V_68 , T_7 * V_98 )
{
T_5 V_161 = V_163 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
int V_165 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
V_165 = V_3 -> V_39 - V_3 -> V_40 ;
if ( V_58 < V_61 && V_165 < V_166 )
{
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_3 -> V_39 ] ;
int V_23 = - V_76 ;
V_42 -> V_23 = & V_23 ;
V_42 -> V_65 = V_63 -> V_65 = 0x00 | ( V_170 &
0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_42 -> V_67 = V_63 -> V_67 = V_161 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_42 -> V_45 = V_98 ;
F_90 ( & V_42 -> V_46 ) ;
V_3 -> V_59 += 1 ;
V_3 -> V_39 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
F_91 ( & V_42 -> V_46 ) ;
return V_23 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_94 ( struct V_18 * V_19 , int V_163 ,
T_5 V_68 , T_7 * V_98 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else
return F_93 ( V_3 , V_163 , V_68 , V_98 ) ;
}
static int F_95 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
T_5 V_173 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_173 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x80 | ( V_173 << 5 ) ;
V_63 -> V_66 = 0x8007 ;
V_63 -> V_67 = ( V_142 << 6 ) | ( V_171 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_114 -> V_5 , V_114 -> V_174 ,
F_97 ( V_114 -> V_174 ) ) ;
V_63 -> V_69 = 8 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = V_114 -> V_175 ;
V_49 -> F_80 = F_80 ;
V_49 -> V_145 = V_145 ;
V_49 -> V_114 = V_114 ;
V_49 -> V_50 = 1 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_98 ( struct V_18 * V_19 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_95 ( V_3 , V_47 , V_145 , V_114 , V_67 ,
V_171 , V_142 , F_80 ) ;
}
static int F_99 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
T_5 V_173 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_173 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
T_7 V_176 = V_114 -> V_119 -
V_114 -> V_177 ;
V_63 -> V_65 = 0x82 | ( V_173 << 5 ) ;
if ( V_176 == 0 ) {
V_63 -> V_66 = 0x0000 ;
} else if ( V_176 > 1024 ) {
V_63 -> V_66 = 0x8000 | 1023 ;
} else
V_63 -> V_66 = 0x8000 | ( V_176 -
1 ) ;
V_63 -> V_67 = ( V_142 << 6 ) | ( V_171 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_114 -> V_5 , V_114 -> V_174 ,
F_97 ( V_114 -> V_174 ) ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_49 -> F_80 = F_80 ;
V_49 -> V_145 = V_145 ;
V_49 -> V_114 = V_114 ;
V_49 -> V_50 = 1 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_100 ( struct V_18 * V_19 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_99 ( V_3 , V_47 , V_145 , V_114 , V_67 ,
V_171 , V_142 , F_80 ) ;
}
static int F_101 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
T_5 V_173 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_173 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x81 | ( V_173 << 5 ) ;
V_63 -> V_66 = 0x0000 ;
V_63 -> V_67 = ( V_142 << 6 ) | ( V_171 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_114 -> V_5 , V_114 -> V_174 ,
F_97 ( V_114 -> V_174 ) ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_49 -> F_80 = F_80 ;
V_49 -> V_145 = V_145 ;
V_49 -> V_114 = V_114 ;
V_49 -> V_50 = 1 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_102 ( struct V_18 * V_19 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_101 ( V_3 , V_47 , V_145 , V_114 , V_67 ,
V_171 , V_142 , F_80 ) ;
}
static int F_103 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
T_5 V_173 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
T_5 * V_125 ;
T_6 V_178 ;
int V_127 = 0 ;
char V_98 [ 30 * 3 + 4 ] ;
char * V_99 = V_98 ;
int V_100 = ( sizeof( V_98 ) - 1 ) / 3 ;
int V_179 = 0 ;
struct V_48 * V_49 = & V_3 -> V_49 [ V_173 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x81 | ( V_173 << 5 ) ;
V_63 -> V_67 = ( V_142 << 6 ) | ( V_171 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_114 -> V_5 , V_114 -> V_174 ,
F_97 ( V_114 -> V_174 ) ) ;
V_63 -> V_69 = F_104 ( T_7 , 1024 ,
V_114 -> V_119 -
V_114 -> V_177 ) ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = V_114 -> V_120 +
V_114 -> V_177 ;
V_63 -> V_66 = 0x8000 | ( V_63 -> V_69 - 1 ) ;
V_125 = V_63 -> V_70 ;
V_178 = V_63 -> V_69 ;
V_98 [ 0 ] = 0 ;
while ( V_178 -- > 0 ) {
if ( V_127 > V_100 ) {
} else if ( V_127 ++ < V_100 ) {
int V_180 = sprintf ( V_99 , L_19 , * V_125 ++ ) ;
V_99 += V_180 ;
V_179 += V_180 ;
} else
V_99 += sprintf ( V_99 , L_20 ) ;
}
V_49 -> F_80 = F_80 ;
V_49 -> V_145 = V_145 ;
V_49 -> V_114 = V_114 ;
V_49 -> V_50 = 1 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_105 ( struct V_18 * V_19 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_103 ( V_3 , V_47 , V_145 , V_114 , V_67 ,
V_171 , V_142 , F_80 ) ;
}
static int F_106 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
T_5 V_173 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
T_7 V_176 = V_114 -> V_119 -
V_114 -> V_177 ;
struct V_48 * V_49 = & V_3 -> V_49 [ V_173 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x83 | ( V_173 << 5 ) ;
if ( V_176 == 0 ) {
V_63 -> V_66 = 0x0000 ;
} else if ( V_176 > 1024 ) {
V_63 -> V_66 = 0x8000 | 1023 ;
} else
V_63 -> V_66 = 0x8000 | ( V_176 -
1 ) ;
V_63 -> V_67 = ( V_142 << 6 ) | ( V_171 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_114 -> V_5 , V_114 -> V_174 ,
F_97 ( V_114 -> V_174 ) ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_49 -> F_80 = F_80 ;
V_49 -> V_145 = V_145 ;
V_49 -> V_114 = V_114 ;
V_49 -> V_50 = 1 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
goto V_72;
}
}
}
int F_107 ( struct V_18 * V_19 , T_5 V_47 ,
void * V_145 , struct V_114 * V_114 , T_5 V_67 , T_5 V_171 , T_5 V_142 ,
void (* F_80) ( void * V_145 , struct V_114 * V_114 , T_5 * V_122 , int V_172 ,
int V_142 , int V_143 , int V_51 , int V_144 ,
int V_138 , int V_139 , int V_140 , int V_141 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_106 ( V_3 , V_47 , V_145 , V_114 , V_67 ,
V_171 , V_142 , F_80 ) ;
}
static int F_108 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_145 )
{
T_5 V_173 = V_47 - 1 ;
if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
struct V_48 * V_49 = & V_3 -> V_49 [ V_173 ] ;
F_5 ( & V_3 -> V_38 ) ;
if ( V_49 -> V_56 > 0 ) {
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
} else {
V_49 -> V_56 = 1 ;
V_57: if ( V_49 -> V_50 == 1 ) {
int V_58 = V_3 -> V_59 -
V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 =
& V_3 -> V_63 [ V_64 &
V_3 -> V_59 ] ;
V_63 -> V_65 = 0x80 | ( V_173 << 5 ) |
0x4 ;
V_63 -> V_66 = 0x00 ;
V_63 -> V_67 = 0x00 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = & V_63 -> V_45 ;
V_3 -> V_59 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_38 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_38 ) ;
goto V_57;
}
}
F_7 ( & V_3 -> V_38 ) ;
return 0 ;
}
}
}
int F_109 ( struct V_18 * V_19 , T_5 V_47 ,
void * V_145 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_108 ( V_3 , V_47 , V_145 ) ;
}
static int F_110 ( struct V_2 * V_3 )
{
int V_102 = 10 ;
int V_103 = 5 ;
int V_181 = 20 ;
V_109: {
int V_110 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_111 ) ,
V_3 -> V_10 , V_3 -> V_112 ,
& V_110 , 100 ) ;
if ( V_110 > 2 ) {
char V_135 [ 30 * 3 + 4 ] ;
char * V_99 = V_135 ;
int V_100 = ( sizeof( V_135 ) - 1 ) / 3 ;
char * V_125 = V_3 -> V_10 ;
int V_101 = 0 ;
V_135 [ 0 ] = 0 ;
while ( V_110 -- > 0 ) {
char V_136 = * V_125 ++ ;
if ( V_101 < V_100 ) {
V_99 += sprintf ( V_99 , L_19 ,
0x000000FF & V_136 ) ;
} else if ( V_101 > V_100 ) {
} else
V_99 += sprintf ( V_99 , L_20 ) ;
V_101 += 1 ;
continue;
}
goto V_109;
} else if ( V_110 > 1 ) {
char V_153 = V_3 -> V_10 [ 0 ] ;
char V_182 = V_3 -> V_10 [ 1 ] ;
if ( V_153 == 0x31 && V_182 == 0x60 ) {
return 0 ;
} else if ( V_181 -- > 0 ) {
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37
L_38 ) ;
return - V_108 ;
}
} else if ( V_110 > 0 ) {
char V_183 = V_3 -> V_10 [ 0 ] ;
F_45 ( & V_3 -> V_4 -> V_5 , L_39
L_40 , V_183 ) ;
if ( V_181 -- > 0 ) {
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37
L_38 ) ;
return - V_108 ;
}
} else if ( V_75 == - V_113 ) {
if ( V_103 -- > 0 ) {
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_41
L_42 ) ;
return - V_131 ;
}
} else if ( V_75 == 0 ) {
if ( V_102 -- > 0 ) {
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_43
L_38 ) ;
return - V_131 ;
}
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_44 , V_75 ) ;
return V_75 ;
}
}
return - 1 ;
}
static int F_111 ( struct V_2 * V_3 )
{
int V_75 ;
struct V_114 * V_114 ;
char * V_122 ;
int V_126 = 257 ;
int V_127 = 0 ;
V_114 = F_74 ( 0 , V_130 ) ;
if ( ! V_114 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_45
L_46 ) ;
return - V_131 ;
}
V_122 = F_75 ( V_3 -> V_4 , V_126 , V_130 , & V_114 -> V_121 ) ;
if ( ! V_122 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_47
L_48 ) ;
F_76 ( V_114 ) ;
return - V_131 ;
}
while ( V_126 -- > 0 )
V_122 [ V_127 ++ ] = 0x55 ;
F_77 ( V_114 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_132 ) , V_122 , V_127 ,
F_70 , V_3 ) ;
V_114 -> V_133 |= V_134 ;
V_75 = F_79 ( V_114 , V_130 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_49
L_50 ) ;
F_71 ( V_3 -> V_4 , V_127 , V_122 , V_114 -> V_121 ) ;
F_76 ( V_114 ) ;
return - V_131 ;
}
F_76 ( V_114 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
int V_75 ;
struct V_114 * V_114 ;
char * V_122 ;
int V_126 = 4 ;
int V_127 = 0 ;
V_114 = F_74 ( 0 , V_130 ) ;
if ( ! V_114 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_51
L_52 ) ;
return - V_131 ;
}
V_122 = F_75 ( V_3 -> V_4 , V_126 , V_130 , & V_114 -> V_121 ) ;
if ( ! V_122 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_53
L_54 ) ;
F_76 ( V_114 ) ;
return - V_131 ;
}
V_122 [ V_127 ++ ] = 0x55 ;
V_122 [ V_127 ++ ] = 0xAA ;
V_122 [ V_127 ++ ] = 0x5A ;
V_122 [ V_127 ++ ] = 0xA5 ;
F_77 ( V_114 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_132 ) , V_122 , V_127 ,
F_70 , V_3 ) ;
V_114 -> V_133 |= V_134 ;
V_75 = F_79 ( V_114 , V_130 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_49
L_55 ) ;
F_71 ( V_3 -> V_4 , V_127 , V_122 , V_114 -> V_121 ) ;
F_76 ( V_114 ) ;
return - V_131 ;
}
F_76 ( V_114 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_75 ;
int V_184 = 10 ;
int V_103 = 5 ;
int V_102 = 10 ;
int V_185 = 0 ;
V_75 = F_110 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_3 -> V_105 = 0 ;
V_3 -> V_107 = - 1 ;
while ( V_184 -- > 0 ) {
int V_186 ;
int V_187 ;
V_75 = F_111 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_110 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_28: V_75 = F_112 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_186 = 100 ;
V_187 = 10 ;
V_151: {
int V_110 = 0 ;
V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 ,
V_3 -> V_111 ) ,
V_3 -> V_10 , V_3 -> V_112 ,
& V_110 , 500 ) ;
if ( V_110 > 2 ) {
char V_135 [ 30 * 3 + 4 ] ;
char * V_99 = V_135 ;
int V_100 = ( sizeof( V_135 ) - 1 ) / 3 ;
char * V_125 = V_3 -> V_10 ;
int V_101 = 0 ;
unsigned char V_136 = 0 ;
V_135 [ 0 ] = 0 ;
while ( V_110 -- > 0 ) {
V_136 = * V_125 ++ ;
if ( V_101 < V_100 ) {
V_99 += sprintf ( V_99 , L_19 , V_136 ) ;
} else if ( V_101 > V_100 ) {
} else
V_99 += sprintf ( V_99 , L_20 ) ;
V_101 += 1 ;
continue;
}
if ( V_136 == 0x7E ) {
return 0 ;
} else {
if ( V_136 == 0x55 ) {
goto V_151;
} else if ( V_186 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_56
L_57 ) ;
continue;
}
}
} else if ( V_110 > 1 ) {
unsigned char V_153 = V_3 -> V_10 [ 0 ] ;
unsigned char V_182 = V_3 -> V_10 [ 1 ] ;
if ( V_153 == 0x31 && V_182 == 0x00 ) {
if ( V_187 -- > 0 ) {
goto V_151;
} else
goto V_28;
} else if ( V_153 == 0x31 && V_182 == 0x60 ) {
if ( V_186 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_56
L_57 ) ;
continue;
}
} else {
if ( V_186 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_56
L_57 ) ;
continue;
}
}
} else if ( V_110 > 0 ) {
if ( V_186 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_58
L_59 ) ;
continue;
}
} else if ( V_75 == - V_113 ) {
if ( V_103 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_60
L_61 ) ;
continue;
}
} else if ( V_75 == 0 ) {
if ( V_102 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_62
L_63 ) ;
continue;
}
} else {
V_185 += 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_44 ,
V_75 ) ;
if ( V_186 -- > 0 ) {
goto V_151;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_58
L_59 ) ;
continue;
}
}
}
}
F_45 ( & V_3 -> V_4 -> V_5 , L_64 ) ;
return - V_108 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_102 = 10 ;
int V_103 = 5 ;
int V_181 = 50 ;
V_109: {
int V_110 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_111 ) ,
V_3 -> V_10 , V_3 -> V_112 ,
& V_110 , 1000 ) ;
if ( V_110 > 2 ) {
char V_135 [ 30 * 3 + 4 ] ;
char * V_99 = V_135 ;
int V_100 = ( sizeof( V_135 ) - 1 ) / 3 ;
char * V_125 = V_3 -> V_10 ;
int V_101 = 0 ;
V_135 [ 0 ] = 0 ;
while ( V_110 -- > 0 ) {
char V_136 = * V_125 ++ ;
if ( V_101 < V_100 ) {
V_99 += sprintf ( V_99 , L_19 ,
0x000000FF & V_136 ) ;
} else if ( V_101 > V_100 ) {
} else
V_99 += sprintf ( V_99 , L_20 ) ;
V_101 += 1 ;
continue;
}
goto V_109;
} else if ( V_110 > 1 ) {
char V_153 = V_3 -> V_10 [ 0 ] ;
char V_182 = V_3 -> V_10 [ 1 ] ;
if ( V_153 == 0x31 && V_182 == 0x60 ) {
return 0 ;
} else if ( V_181 -- > 0 ) {
F_40 ( 5 ) ;
goto V_109;
} else
return - V_108 ;
} else if ( V_110 > 0 ) {
char V_183 = V_3 -> V_10 [ 0 ] ;
F_45 ( & V_3 -> V_4 -> V_5 , L_39
L_40 , V_183 ) ;
if ( V_181 -- > 0 ) {
F_40 ( 5 ) ;
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37
L_38 ) ;
return - V_108 ;
}
} else if ( V_75 == - V_113 ) {
if ( V_103 -- > 0 ) {
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_41
L_42 ) ;
return - V_131 ;
}
} else if ( V_75 == 0 ) {
if ( V_102 -- > 0 ) {
goto V_109;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_43
L_38 ) ;
return - V_131 ;
}
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_44 , V_75 ) ;
return - V_131 ;
}
}
return - 1 ;
}
static int F_57 ( struct V_2 * V_3 )
{
int V_188 = F_89 ( V_3 , & V_3 -> V_85 ) ;
if ( V_188 )
return V_188 ;
if ( V_3 -> V_85 & 0x00400000 ) {
if ( V_3 -> V_86 ) {
} else {
V_3 -> V_86 = 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_65
L_66 , V_3 -> V_85 ) ;
}
return - V_76 ;
} else {
T_5 V_189 = V_3 -> V_190 - 1 ;
int V_191 = V_189 << 8 ;
T_7 V_192 ;
T_7 V_193 ;
T_7 V_194 ;
int V_195 = 0 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_193 = V_192 & 0xFFFF ;
V_194 = ( V_192 >> 16 ) & 0xFFFF ;
if ( V_193 == V_3 -> V_26 . V_196 && V_194 ==
V_3 -> V_26 . V_21 ) {
return 0 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_67
L_68 ,
V_3 -> V_26 . V_196 , V_193 ,
V_3 -> V_26 . V_21 , V_194 ) ;
return - V_76 ;
}
}
}
static int F_113 ( struct V_2 * V_3 , int V_197 )
{
int V_198 = 0 ;
int V_75 ;
T_7 V_199 ;
int V_200 ;
T_7 V_201 ;
T_7 V_202 = - 1 ;
T_7 V_116 ;
T_7 V_203 ;
T_7 V_204 ;
T_7 V_205 ;
T_7 V_206 ;
T_7 V_207 ;
int V_208 = V_209 ;
int V_210 = 0 ;
int V_211 = 30 ;
int V_212 ;
V_75 = F_114 ( V_3 , V_213 , V_214 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_215 . V_216 , & V_202 ) ;
if ( V_75 )
return V_75 ;
V_200 = V_202 & V_217 ;
V_75 = F_115 ( V_3 , V_203 , & V_204 ) ;
if ( V_75 )
return V_75 ;
V_204 &= 0x3fff ;
if ( V_204 != V_218 ) {
}
V_204 |= F_116 ( V_204 ) << 16 ;
V_75 = F_115 ( V_3 , V_201 , & V_199 ) ;
if ( V_75 )
return V_75 ;
switch ( V_199 & V_219 ) {
case V_220 :
V_210 = 0 ;
break;
case V_221 :
case V_222 :
V_199 &= V_223 ;
V_199 |= V_222 ;
V_210 = 10 ;
break;
default:
V_199 &= V_223 ;
V_199 |= V_224 ;
V_210 = 50 ;
break;
}
V_75 = F_114 ( V_3 , V_201 , V_199 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_75 )
return V_75 ;
F_40 ( V_210 ) ;
V_75 = F_115 ( V_3 , V_215 . V_216 , & V_207 ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_207 & V_225 ) ) {
for ( V_212 = 0 ; V_212 < V_200 ; V_212 ++ ) {
V_75 = F_114 ( V_3 ,
V_215 . V_226 [ V_212 ] , V_227 ) ;
if ( V_75 )
return V_75 ;
}
}
V_75 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_75 )
return V_75 ;
V_228: V_75 = F_115 ( V_3 , V_206 , & V_116 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_206 , V_229 ) ;
if ( V_75 )
return V_75 ;
V_230: {
V_75 = F_115 ( V_3 , V_206 , & V_116 ) ;
if ( V_75 )
return V_75 ;
if ( 0 != ( V_116 & V_229 ) ) {
if ( -- V_211 == 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_69
L_70 ) ;
return - V_76 ;
} else {
F_40 ( 5 ) ;
goto V_230;
}
}
}
if ( V_197 & V_231 ) {
V_75 = F_114 ( V_3 , V_201 , V_199 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_75 )
return V_75 ;
}
V_75 = F_114 ( V_3 , V_232 , 0x00000000 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_233 , 0x11000000 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_234 , 0x00000000 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_203 , & V_203 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_203 ,
( ( V_203 & V_235 ) ^ V_235 ) | V_204 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_205 ,
( ( 9 * V_204 ) / 10 ) & 0x3fff ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_203 , & V_203 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_205 , & V_205 ) ;
if ( V_75 )
return V_75 ;
if ( 0 == ( V_203 & 0x3fff0000 ) || 0 == V_205 ) {
if ( ! ( V_197 & V_231 ) ) {
V_197 |= V_231 ;
goto V_228;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_71 ,
V_203 , V_205 ) ;
}
V_199 &= V_223 ;
V_199 |= V_236 | V_237 | V_220 ;
V_75 = F_114 ( V_3 , V_201 , V_199 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_206 , V_238 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_206 , & V_206 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_215 . V_116 , V_239 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_240 , V_208 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_213 ,
V_214 | V_241 | V_242 | V_243 |
V_244 | V_245 | V_246 | V_247 |
V_248 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_215 . V_216 , & V_207 ) ;
if ( V_75 )
return V_75 ;
V_207 &= ~ ( V_249 | V_250 ) ;
if ( V_197 & V_251 ) {
V_207 |= V_252 ;
V_207 &= ~ ( V_253 | V_225 ) ;
V_75 = F_114 ( V_3 , V_215 . V_216 , V_207 ) ;
if ( V_75 )
return V_75 ;
} else if ( ( V_197 & V_254 ) || V_255 ) {
V_207 |= V_225 ;
V_75 = F_114 ( V_3 , V_215 . V_216 , V_207 ) ;
if ( V_75 )
return V_75 ;
}
V_75 = F_114 ( V_3 , V_215 . V_116 , V_256 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_215 . V_125 ,
( V_207 & V_225 ) ? 0 : V_257 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_75 )
return V_75 ;
F_117 ( ( V_207 >> 23 ) & 0x1fe ) ;
for ( V_212 = 0 ; V_212 < V_200 ; V_212 ++ ) {
T_7 V_226 ;
V_75 = F_115 ( V_3 , V_215 . V_226 [ V_212 ] ,
& V_226 ) ;
if ( V_75 )
return V_75 ;
if ( 1 & V_226 )
V_198 += 1 ;
}
return V_198 ;
}
static int F_118 ( struct V_2 * V_3 , int V_189 )
{
T_7 V_258 ;
int V_188 ;
T_7 V_192 ;
int V_195 = 0 ;
int V_191 = V_189 << 8 ;
V_188 = F_85 ( V_3 , 0x0000025FL | 0x2800 ) ;
if ( V_188 )
return V_188 ;
V_195 = 16 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0 ,
0xFFFFFFFF ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0 ,
0xF0000000 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_195 = 12 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_258 ) ;
if ( V_188 )
return V_188 ;
V_258 &= 0xFFFF00FF ;
V_258 |= 0x00001600 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0x00 ,
V_258 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_195 = 4 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0x00 ,
0x06 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
for ( V_195 = 0 ; V_195 <= 0x54 ; V_195 += 4 ) {
V_188 = F_93 ( V_3 , V_195 , 0 , & V_192 ) ;
if ( V_188 )
return V_188 ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 , int V_189 )
{
T_7 V_258 ;
int V_188 ;
T_7 V_192 ;
int V_195 = 0 ;
int V_191 = V_189 << 8 ;
V_188 = F_85 ( V_3 , 0x0000025FL | 0x2800 ) ;
if ( V_188 )
return V_188 ;
V_195 = 16 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0 ,
0xFFFFFFFF ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0 ,
0x00000000 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_195 = 12 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_258 ) ;
if ( V_188 )
return V_188 ;
V_258 &= 0xFFFF00FF ;
V_258 |= 0x00001600 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0x00 ,
V_258 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_195 = 4 ;
V_188 = F_86 ( V_3 , V_191 | V_195 , 0x00 ,
0x00 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
return 0 ;
}
static int F_120 ( struct V_2 * V_3 , int V_189 , int V_197 )
{
int V_23 ;
int V_188 ;
V_188 = F_118 ( V_3 , V_189 ) ;
if ( V_188 )
return V_188 ;
V_23 = F_113 ( V_3 , V_197 ) ;
V_188 = F_119 ( V_3 , V_189 ) ;
if ( V_188 )
return V_188 ;
return V_23 ;
}
static int F_55 ( struct V_2 * V_3 )
{
T_7 V_85 ;
T_5 V_259 ;
int V_188 ;
V_188 = F_89 ( V_3 , & V_85 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_85 ( V_3 , 0x00000000L ) ;
if ( V_188 )
return V_188 ;
F_40 ( 750 ) ;
V_188 = F_85 ( V_3 , 0x00000200L | 0x100 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_85 ( V_3 , 0x00000200L | 0x500 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_89 ( V_3 , & V_85 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_85 ( V_3 , 0x0000020CL | 0x000 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_85 ( V_3 , 0x0000020DL | 0x000 ) ;
if ( V_188 )
return V_188 ;
F_40 ( 250 ) ;
V_188 = F_85 ( V_3 , 0x0000020FL | 0x000 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_89 ( V_3 , & V_85 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_85 ( V_3 , 0x0000025FL | 0x800 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_89 ( V_3 , & V_85 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_89 ( V_3 , & V_85 ) ;
if ( V_188 )
return V_188 ;
F_40 ( 1000 ) ;
V_259 = ( V_85 >> 16 ) & 0x000F ;
if ( 0x0D == V_259 )
return 0 ;
else
return - V_260 ;
}
static int F_56 ( struct V_2 * V_3 )
{
int V_188 ;
T_7 V_192 ;
int V_195 = 0 ;
T_5 V_189 ;
int V_191 = 0 ;
int V_261 = 0 ;
int V_262 = 0 ;
int V_263 = 0 ;
V_3 -> V_190 = 0 ;
for ( V_189 = 0 ; ( V_189 < 4 ) ; V_189 ++ ) {
T_7 V_193 = 0 ;
T_7 V_194 = 0 ;
int V_198 = 0 ;
V_191 = V_189 << 8 ;
V_188 = F_92 ( V_3 , V_191 | V_195 , 0 ,
& V_192 ) ;
if ( V_188 )
return V_188 ;
V_193 = V_192 & 0xFFFF ;
V_194 = ( V_192 >> 16 ) & 0xFFFF ;
if ( ( V_193 == V_264 ) && ( V_194 == 0xc861 ) ) {
V_198 = F_120 ( V_3 , V_189 , 0 ) ;
V_262 += 1 ;
} else if ( ( V_193 == V_265 ) && ( V_194 == 0x0035 ) )
{
V_198 = F_120 ( V_3 , V_189 , 0 ) ;
V_262 += 1 ;
} else if ( ( V_193 == V_266 ) && ( V_194 == 0x5237 ) ) {
V_198 = F_120 ( V_3 , V_189 , 0 ) ;
V_262 += 1 ;
} else if ( ( V_193 == V_267 ) && ( V_194 == 0x5802 ) )
{
V_198 = F_120 ( V_3 , V_189 , 0 ) ;
V_262 += 1 ;
} else if ( V_193 == V_268 && V_194 == 0x740c ) {
V_198 = F_120 ( V_3 , V_189 ,
V_254 ) ;
V_262 += 1 ;
} else if ( V_193 == V_269 && V_194 == 0xa0f8 ) {
V_198 = F_120 ( V_3 , V_189 ,
V_270 ) ;
V_262 += 1 ;
} else if ( 0 == V_192 ) {
} else
V_263 += 1 ;
if ( V_198 > V_261 ) {
V_261 = V_198 ;
V_3 -> V_190 = V_189 + 1 ;
V_3 -> V_26 . V_196 = V_193 ;
V_3 -> V_26 . V_21 = V_194 ;
}
}
if ( V_3 -> V_190 > 0 ) {
V_188 = F_118 ( V_3 ,
V_3 -> V_190 - 1 ) ;
if ( V_188 )
return V_188 ;
return 0 ;
} else if ( V_262 > 0 ) {
return - V_260 ;
} else if ( V_263 > 0 ) {
return - V_260 ;
} else {
V_3 -> V_82 = 0 ;
return - V_260 ;
}
}
static int F_121 ( struct V_90 * V_91 ,
const struct V_271 * V_29 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
T_3 V_276 ;
int V_127 ;
int V_75 = - V_131 ;
struct V_2 * V_3 ;
V_3 = F_122 ( sizeof( struct V_2 ) , V_130 ) ;
if ( ! V_3 ) {
F_62 ( V_93 L_72 ) ;
return - V_131 ;
}
F_5 ( & V_7 ) ;
F_123 ( & V_3 -> V_8 , & V_277 ) ;
V_3 -> V_30 = ++ V_9 ;
F_7 ( & V_7 ) ;
F_13 ( V_3 ) ;
F_124 ( & V_3 -> V_80 , 1 ) ;
V_3 -> V_4 = F_125 ( F_126 ( V_91 ) ) ;
V_3 -> V_91 = V_91 ;
F_127 ( & V_3 -> V_38 ) ;
V_3 -> V_54 = 4 ;
V_273 = V_91 -> V_278 ;
for ( V_127 = 0 ; V_127 < V_273 -> V_279 . V_280 ; ++ V_127 ) {
V_275 = & V_273 -> V_275 [ V_127 ] . V_279 ;
if ( ! V_3 -> V_111 &&
F_128 ( V_275 ) ) {
V_276 = F_129 ( V_275 ) ;
V_3 -> V_112 = V_276 ;
V_3 -> V_111 = V_275 -> V_281 ;
V_3 -> V_10 = F_130 ( V_276 , V_130 ) ;
if ( ! V_3 -> V_10 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_73
L_74 ) ;
V_75 = - V_131 ;
goto error;
}
}
if ( ! V_3 -> V_132 &&
F_131 ( V_275 ) ) {
V_3 -> V_132 =
V_275 -> V_281 ;
}
}
if ( ! ( V_3 -> V_111 && V_3 -> V_132 ) ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_75
L_76 ) ;
V_75 = - V_76 ;
goto error;
}
F_31 ( & V_3 -> V_4 -> V_5 , L_77 ,
V_273 -> V_279 . V_282 , V_3 -> V_111 ,
V_3 -> V_132 ) ;
F_132 ( V_91 , V_3 ) ;
if ( V_273 -> V_279 . V_282 == 0 &&
V_3 -> V_111 == 0x81 &&
V_3 -> V_132 == 0x02 ) {
V_75 = F_133 ( V_91 , & V_283 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_78
L_79 ) ;
F_132 ( V_91 , NULL ) ;
V_75 = - V_131 ;
goto error;
} else {
V_3 -> V_284 = & V_283 ;
F_31 ( & V_3 -> V_4 -> V_5 , L_80
L_81 , V_3 ,
V_273 -> V_279 . V_282 ,
V_91 -> V_285 ) ;
return 0 ;
}
} else if ( V_273 -> V_279 . V_282 == 1 &&
V_3 -> V_111 == 0x83 &&
V_3 -> V_132 == 0x04 ) {
V_3 -> V_284 = NULL ;
F_31 ( & V_3 -> V_4 -> V_5 , L_82
L_83 , V_3 , V_273 -> V_279 . V_282 ) ;
F_134 ( & V_3 -> V_13 , F_50 ) ;
F_134 ( & V_3 -> V_15 , F_42 ) ;
F_134 ( & V_3 -> V_17 , F_48 ) ;
F_17 ( V_3 , F_46 ( 3 * 1000 ) ) ;
return 0 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_84 ) ;
V_75 = - V_76 ;
goto error;
}
error: if ( V_3 ) {
F_9 ( V_3 ) ;
}
return V_75 ;
}
static void F_135 ( struct V_90 * V_91 )
{
struct V_2 * V_3 = F_63 ( V_91 ) ;
V_3 -> V_6 += 1 ;
if ( V_3 -> V_284 ) {
int V_285 = V_91 -> V_285 ;
struct V_286 * V_284 = V_3 -> V_284 ;
F_132 ( V_91 , NULL ) ;
F_136 ( V_91 , V_284 ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_85
L_86 , V_285 ) ;
} else {
F_18 ( V_3 ) ;
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
F_34 ( V_3 ) ;
F_36 ( V_3 ) ;
if ( V_3 -> V_84 ) {
F_58 ( & V_3 -> V_24 ) ;
V_3 -> V_79 = 0 ;
V_3 -> V_82 = 0 ;
V_3 -> V_83 = 0 ;
V_3 -> V_84 = 0 ;
}
F_137 ( V_12 ) ;
F_137 ( V_14 ) ;
F_137 ( V_16 ) ;
V_3 -> V_6 += 1 ;
F_132 ( V_91 , NULL ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_87
L_88 ) ;
}
F_9 ( V_3 ) ;
}
static int T_8 F_138 ( void )
{
int V_23 ;
F_62 ( V_287 L_89 , V_92 . V_37 ) ;
F_127 ( & V_7 ) ;
F_139 ( & V_277 ) ;
V_12 = F_140 ( L_90 ) ;
if ( ! V_12 )
goto V_288;
V_14 = F_140 ( L_91 ) ;
if ( ! V_14 )
goto V_289;
V_16 = F_140 ( L_92 ) ;
if ( ! V_16 )
goto V_290;
V_23 = F_141 ( & V_92 ) ;
if ( V_23 ) {
F_142 ( V_12 ) ;
F_142 ( V_14 ) ;
F_142 ( V_16 ) ;
F_62 ( V_93 L_93 ,
V_23 ) ;
}
return V_23 ;
V_290:
F_142 ( V_14 ) ;
V_289:
F_142 ( V_12 ) ;
V_288:
F_62 ( V_93 L_94 , V_92 . V_37 ) ;
return - V_131 ;
}
static void T_9 F_143 ( void )
{
struct V_2 * V_3 ;
struct V_2 * V_212 ;
F_144 ( & V_92 ) ;
F_62 ( V_287 L_95 ) ;
F_145 (ftdi, temp, &ftdi_static_list, ftdi_list) {
F_18 ( V_3 ) ;
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
} F_137 ( V_12 ) ;
F_142 ( V_12 ) ;
V_12 = NULL ;
F_137 ( V_14 ) ;
F_142 ( V_14 ) ;
V_14 = NULL ;
F_137 ( V_16 ) ;
F_142 ( V_16 ) ;
V_16 = NULL ;
}
