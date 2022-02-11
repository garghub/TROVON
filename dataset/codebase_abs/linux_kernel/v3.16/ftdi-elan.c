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
F_45 ( & V_3 -> V_4 -> V_5 , L_8 ) ;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_9 ,
V_3 -> V_81 ) ;
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
F_45 ( & V_3 -> V_4 -> V_5 , L_10 ) ;
V_78 = 1 * 1000 ;
}
} else if ( V_3 -> V_84 == 0 ) {
V_78 = 10 ;
if ( F_29 ( V_3 ) == 0 ) {
V_3 -> V_84 = 1 ;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_11 ) ;
V_78 = 250 ;
} else {
if ( F_57 ( V_3 ) == 0 ) {
V_78 = 250 ;
} else if ( V_3 -> V_85 & 0x00400000 ) {
if ( V_3 -> V_20 > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_12 ,
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
F_45 ( & V_3 -> V_4 -> V_5 , L_13 ) ;
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
F_62 ( L_14 , V_89 ) ;
return - V_76 ;
} else {
struct V_2 * V_3 = F_63 ( V_91 ) ;
if ( ! V_3 ) {
return - V_76 ;
} else {
if ( F_64 ( & V_3 -> V_80 ) ) {
return - V_93 ;
} else {
F_11 ( V_3 ) ;
V_88 -> V_94 = V_3 ;
return 0 ;
}
}
}
}
static int F_65 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_94 ;
if ( V_3 == NULL )
return - V_76 ;
F_53 ( & V_3 -> V_80 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static T_1 F_66 ( struct V_88 * V_88 , char T_2 * V_70 ,
T_3 V_95 , T_4 * V_96 )
{
char V_97 [ 30 * 3 + 4 ] ;
char * V_98 = V_97 ;
int V_99 = ( sizeof( V_97 ) - 1 ) / 3 ;
int V_100 = 0 ;
int V_101 = 10 ;
int V_102 = 5 ;
struct V_2 * V_3 = V_88 -> V_94 ;
if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
}
V_97 [ 0 ] = 0 ;
V_103: if ( V_3 -> V_104 > 0 ) {
if ( V_95 -- > 0 ) {
char * V_105 = ++ V_3 -> V_106 + V_3 -> V_10 ;
V_3 -> V_104 -= 1 ;
if ( V_100 < V_99 ) {
V_98 += sprintf ( V_98 , L_15 , 0x000000FF & * V_105 ) ;
} else if ( V_100 > V_99 ) {
} else
V_98 += sprintf ( V_98 , L_16 ) ;
if ( F_67 ( V_70 ++ , V_105 , 1 ) ) {
return - V_107 ;
} else {
V_100 += 1 ;
goto V_103;
}
} else
return V_100 ;
}
V_108: if ( V_95 > 0 ) {
int V_109 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_110 ) ,
V_3 -> V_10 , V_3 -> V_111 ,
& V_109 , 50 ) ;
if ( V_109 > 2 ) {
V_3 -> V_104 = V_109 - 2 ;
V_3 -> V_106 = 1 ;
goto V_103;
} else if ( V_75 == - V_112 ) {
if ( V_102 -- > 0 ) {
goto V_108;
} else if ( V_100 > 0 ) {
return V_100 ;
} else
return V_75 ;
} else if ( V_75 == 0 ) {
if ( V_101 -- > 0 ) {
goto V_108;
} else
return V_100 ;
} else
return V_75 ;
} else
return V_100 ;
}
static void F_70 ( struct V_113 * V_113 )
{
struct V_2 * V_3 = V_113 -> V_114 ;
int V_115 = V_113 -> V_115 ;
if ( V_115 && ! ( V_115 == - V_116 || V_115 == - V_117 ||
V_115 == - V_44 ) ) {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_17 , V_113 , V_115 ) ;
}
F_71 ( V_113 -> V_5 , V_113 -> V_118 ,
V_113 -> V_119 , V_113 -> V_120 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
char * V_121 , int V_58 , int V_122 )
{
int V_123 = 0 ;
int V_124 = 0 ;
int V_125 = V_58 ;
int V_126 = V_3 -> V_60 ;
while ( V_125 -- > 0 ) {
struct V_62 * V_63 = & V_3 -> V_63 [ V_64 &
V_126 ++ ] ;
int V_127 = V_63 -> V_69 ;
T_5 * V_128 = V_63 -> V_70 ;
if ( V_63 -> V_65 & 0x80 ) {
V_123 |= 1 << ( 0x3 & ( V_63 -> V_65 >> 5 ) ) ;
}
V_121 [ V_124 ++ ] = V_63 -> V_65 ;
V_121 [ V_124 ++ ] = ( V_63 -> V_66 >> 0 ) & 0x00FF ;
V_121 [ V_124 ++ ] = ( V_63 -> V_66 >> 8 ) & 0x00FF ;
V_121 [ V_124 ++ ] = V_63 -> V_67 ;
V_121 [ V_124 ++ ] = V_63 -> V_68 ;
while ( V_127 -- > 0 ) {
V_121 [ V_124 ++ ] = * V_128 ++ ;
}
}
return V_123 ;
}
static int F_73 ( struct V_2 * V_3 , int V_58 )
{
int V_122 = 0 ;
int V_125 = V_58 ;
int V_126 = V_3 -> V_60 ;
while ( V_125 -- > 0 ) {
struct V_62 * V_63 = & V_3 -> V_63 [ V_64 &
V_126 ++ ] ;
V_122 += 5 + V_63 -> V_69 ;
} return V_122 ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_75 ;
char * V_121 ;
int V_123 ;
int V_122 ;
struct V_113 * V_113 ;
int V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 == 0 )
return 0 ;
V_122 = F_73 ( V_3 , V_58 ) ;
V_113 = F_74 ( 0 , V_129 ) ;
if ( ! V_113 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_18 ,
V_58 , V_122 ) ;
return - V_130 ;
}
V_121 = F_75 ( V_3 -> V_4 , V_122 , V_129 ,
& V_113 -> V_120 ) ;
if ( ! V_121 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_19 ,
V_58 , V_122 ) ;
F_76 ( V_113 ) ;
return - V_130 ;
}
V_123 = F_72 ( V_3 , V_121 ,
V_58 , V_122 ) ;
F_77 ( V_113 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_131 ) , V_121 , V_122 ,
F_70 , V_3 ) ;
V_113 -> V_132 |= V_133 ;
if ( V_123 ) {
char V_134 [ 40 * 3 + 4 ] ;
char * V_98 = V_134 ;
int V_99 = V_122 ;
T_5 * V_135 = V_121 ;
int V_136 = ( sizeof( V_134 ) - 1 ) / 3 ;
V_134 [ 0 ] = 0 ;
while ( V_136 -- > 0 && V_99 -- > 0 ) {
if ( V_136 > 0 || V_99 == 0 ) {
V_98 += sprintf ( V_98 , L_15 , * V_135 ++ ) ;
} else
V_98 += sprintf ( V_98 , L_16 ) ;
}
}
V_75 = F_79 ( V_113 , V_129 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_20 ,
V_75 , V_113 , V_58 , V_122 ) ;
F_71 ( V_3 -> V_4 , V_122 , V_121 , V_113 -> V_120 ) ;
F_76 ( V_113 ) ;
return V_75 ;
}
F_76 ( V_113 ) ;
V_3 -> V_60 += V_58 ;
F_47 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_48 * V_49 , T_5 * V_70 , int V_66 )
{
struct V_113 * V_113 = V_49 -> V_113 ;
int V_137 = V_49 -> V_137 ;
int V_138 = V_49 -> V_138 ;
int V_139 = V_49 -> V_139 ;
int V_140 = V_49 -> V_140 ;
int V_141 = V_49 -> V_141 ;
int V_142 = V_49 -> V_142 ;
int V_51 = V_49 -> V_51 ;
int V_143 = V_49 -> V_143 ;
void (* F_80) ( void * , struct V_113 * , T_5 * , int , int , int , int , int ,
int , int , int , int ) = V_49 -> F_80 ;
V_49 -> V_50 -= 1 ;
V_49 -> F_80 = NULL ;
(* F_80) ( V_49 -> V_144 , V_113 , V_70 , V_66 , V_141 ,
V_142 , V_51 , V_143 , V_137 , V_138 ,
V_139 , V_140 ) ;
}
static char * F_81 ( struct V_2 * V_3 ,
struct V_48 * V_49 , T_6 V_145 , int V_47 , int V_146 ,
char * V_124 )
{
int V_147 = ( V_145 >> 0 ) & 0x07FF ;
F_5 ( & V_3 -> V_38 ) ;
V_49 -> V_139 = 0 ;
V_49 -> V_140 = ( V_145 >> 15 ) & 0x0001 ;
V_49 -> V_143 = ( V_145 >> 11 ) & 0x000F ;
if ( V_146 == 0x02 ) {
if ( V_147 == 0 || V_49 -> V_56 > 0 ) {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_148 ,
V_147 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_148 ;
} else {
V_3 -> V_54 = 4 + V_147 ;
V_3 -> V_55 = 1 ;
F_7 ( & V_3 -> V_38 ) ;
return V_124 ;
}
} else if ( V_146 == 0x03 ) {
if ( V_147 == 0 || V_49 -> V_56 > 0 ) {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_148 ,
V_147 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_148 ;
} else {
V_3 -> V_54 = 4 + V_147 ;
V_3 -> V_55 = 1 ;
F_7 ( & V_3 -> V_38 ) ;
return V_124 ;
}
} else if ( V_146 == 0x01 ) {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_148 ,
V_147 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_148 ;
} else {
V_49 -> V_56 = 0 ;
F_7 ( & V_3 -> V_38 ) ;
F_37 ( V_3 , V_49 , 4 + V_3 -> V_148 ,
V_147 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_148 ;
}
}
static char * F_82 ( struct V_2 * V_3 ,
struct V_48 * V_49 , T_6 V_145 , int V_47 , int V_146 ,
char * V_124 )
{
F_5 ( & V_3 -> V_38 ) ;
V_49 -> V_51 = V_52 ;
V_49 -> V_139 = ( V_145 >> 0 ) & 0x01FF ;
V_49 -> V_140 = ( V_145 >> 15 ) & 0x0001 ;
V_49 -> V_143 = ( V_145 >> 11 ) & 0x000F ;
F_7 ( & V_3 -> V_38 ) ;
if ( V_49 -> V_50 )
F_37 ( V_3 , V_49 , NULL , 0 ) ;
V_49 -> V_56 = 0 ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
return V_3 -> V_148 ;
}
static int F_49 ( struct V_2 * V_3 )
{
T_5 * V_124 = V_3 -> V_148 + V_3 -> V_53 ;
int V_100 = 0 ;
int V_101 = 1 ;
int V_102 = 3 ;
int V_149 = 0 ;
V_150: {
int V_109 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_110 ) ,
V_3 -> V_10 , V_3 -> V_111 ,
& V_109 , 500 ) ;
char V_134 [ 30 * 3 + 4 ] ;
char * V_98 = V_134 ;
int V_99 = V_109 ;
T_5 * V_135 = V_3 -> V_10 ;
int V_136 = ( sizeof( V_134 ) - 1 ) / 3 ;
V_134 [ 0 ] = 0 ;
while ( V_136 -- > 0 && V_99 -- > 0 ) {
if ( V_136 > 0 || V_99 == 0 ) {
V_98 += sprintf ( V_98 , L_15 , * V_135 ++ ) ;
} else
V_98 += sprintf ( V_98 , L_16 ) ;
}
if ( V_109 > 2 ) {
V_3 -> V_104 = V_109 - 2 ;
V_3 -> V_106 = 1 ;
goto V_103;
} else if ( V_75 == - V_112 ) {
if ( V_102 -- > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_21 ,
V_109 , V_100 , V_134 ) ;
goto V_108;
} else if ( V_100 > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_22 ,
V_100 , V_134 ) ;
return - V_130 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_21 ,
V_109 , V_100 , V_134 ) ;
return - V_130 ;
}
} else if ( V_75 == - V_77 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_23 ,
V_75 , V_109 , V_100 , V_134 ) ;
return V_75 ;
} else if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_23 ,
V_75 , V_109 , V_100 , V_134 ) ;
return V_75 ;
} else if ( V_109 == 2 ) {
unsigned char V_151 = V_3 -> V_10 [ 0 ] ;
unsigned char V_152 = V_3 -> V_10 [ 1 ] ;
V_149 += 1 ;
if ( V_151 == 0x31 && V_152 == 0x60 ) {
if ( V_101 -- > 0 ) {
goto V_108;
} else
return 0 ;
} else if ( V_151 == 0x31 && V_152 == 0x00 ) {
if ( V_101 -- > 0 ) {
goto V_108;
} else
return 0 ;
} else {
if ( V_101 -- > 0 ) {
goto V_108;
} else
return 0 ;
}
} else if ( V_109 == 1 ) {
if ( V_101 -- > 0 ) {
goto V_108;
} else
return 0 ;
} else {
if ( V_101 -- > 0 ) {
goto V_108;
} else
return 0 ;
}
}
V_108: {
goto V_150;
}
V_103: if ( V_3 -> V_104 > 0 ) {
T_5 V_135 = V_3 -> V_10 [ ++ V_3 -> V_106 ] ;
V_100 += 1 ;
V_3 -> V_104 -= 1 ;
if ( V_3 -> V_53 == 0 && V_135 == 0xFF ) {
goto V_103;
} else
* V_124 ++ = V_135 ;
if ( ++ V_3 -> V_53 < V_3 -> V_54 ) {
goto V_103;
} else if ( V_3 -> V_55 ) {
int V_47 = ( V_3 -> V_148 [ 0 ] >> 5 ) & 0x03 ;
T_6 V_145 = ( V_3 -> V_148 [ 2 ] << 8 ) |
V_3 -> V_148 [ 1 ] ;
struct V_48 * V_49 = & V_3 -> V_49 [ V_47 ] ;
int V_147 = ( V_145 >> 0 ) & 0x07FF ;
char V_134 [ 30 * 3 + 4 ] ;
char * V_98 = V_134 ;
int V_99 = V_147 ;
T_5 * V_135 = 4 + V_3 -> V_148 ;
int V_136 = ( sizeof( V_134 ) - 1 ) / 3 ;
V_134 [ 0 ] = 0 ;
while ( V_136 -- > 0 && V_99 -- > 0 ) {
if ( V_136 > 0 || V_99 == 0 ) {
V_98 += sprintf ( V_98 , L_15 , * V_135 ++ ) ;
} else
V_98 += sprintf ( V_98 , L_16 ) ;
}
F_37 ( V_3 , V_49 , 4 + V_3 -> V_148 ,
V_147 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
V_124 = V_3 -> V_148 ;
goto V_103;
} else if ( V_3 -> V_54 == 8 ) {
T_5 V_153 ;
int V_40 = V_3 -> V_40 ++ ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_40 ] ;
T_7 V_97 = V_3 -> V_148 [ 7 ] ;
V_97 <<= 8 ;
V_97 |= V_3 -> V_148 [ 6 ] ;
V_97 <<= 8 ;
V_97 |= V_3 -> V_148 [ 5 ] ;
V_97 <<= 8 ;
V_97 |= V_3 -> V_148 [ 4 ] ;
* V_42 -> V_45 = V_97 ;
* V_42 -> V_23 = 0 ;
F_35 ( & V_42 -> V_46 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 4 ;
V_3 -> V_55 = 0 ;
V_124 = V_3 -> V_148 ;
V_153 = ( V_3 -> V_148 [ 0 ] >> 0 ) & 0x0F ;
if ( V_153 == 0x00 ) {
} else if ( V_153 == 0x02 ) {
} else if ( V_153 == 0x06 ) {
} else if ( V_153 == 0x0A ) {
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_24 ,
V_153 , V_97 ) ;
goto V_103;
} else {
if ( ( V_3 -> V_148 [ 0 ] & 0x80 ) == 0x00 ) {
V_3 -> V_54 = 8 ;
goto V_103;
} else {
int V_47 = ( V_3 -> V_148 [ 0 ] >> 5 ) & 0x03 ;
int V_146 = ( V_3 -> V_148 [ 0 ] >> 0 ) & 0x03 ;
T_6 V_145 = ( V_3 -> V_148 [ 2 ] << 8 ) |
V_3 -> V_148 [ 1 ] ;
struct V_48 * V_49 = & V_3 -> V_49 [
V_47 ] ;
V_49 -> V_137 = ( V_3 -> V_148 [ 0 ] >> 3 ) &
0x01 ;
V_49 -> V_138 = ( V_3 -> V_148 [ 0 ] >> 2 ) &
0x01 ;
V_49 -> V_141 = ( V_3 -> V_148 [ 3 ] >> 6 )
& 0x03 ;
V_49 -> V_142 = ( V_3 -> V_148 [ 3 ] >> 4 )
& 0x03 ;
V_49 -> V_51 = ( V_3 -> V_148 [
3 ] >> 0 ) & 0x0F ;
if ( ( V_3 -> V_148 [ 0 ] & 0x10 ) == 0x00 ) {
V_124 = F_81 ( V_3 , V_49 ,
V_145 , V_47 , V_146 ,
V_124 ) ;
goto V_103;
} else {
V_124 = F_82 ( V_3 , V_49 ,
V_145 , V_47 , V_146 ,
V_124 ) ;
goto V_103;
}
}
}
} else
goto V_108;
}
static T_1 F_83 ( struct V_88 * V_88 ,
const char T_2 * V_154 , T_3 V_95 ,
T_4 * V_96 )
{
int V_75 = 0 ;
struct V_113 * V_113 ;
char * V_121 ;
struct V_2 * V_3 = V_88 -> V_94 ;
if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
}
if ( V_95 == 0 ) {
goto exit;
}
V_113 = F_74 ( 0 , V_129 ) ;
if ( ! V_113 ) {
V_75 = - V_130 ;
goto V_155;
}
V_121 = F_75 ( V_3 -> V_4 , V_95 , V_129 ,
& V_113 -> V_120 ) ;
if ( ! V_121 ) {
V_75 = - V_130 ;
goto V_156;
}
if ( F_84 ( V_121 , V_154 , V_95 ) ) {
V_75 = - V_107 ;
goto V_157;
}
F_77 ( V_113 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_131 ) , V_121 , V_95 ,
F_70 , V_3 ) ;
V_113 -> V_132 |= V_133 ;
V_75 = F_79 ( V_113 , V_129 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_25 , V_75 ) ;
goto V_157;
}
F_76 ( V_113 ) ;
exit:
return V_95 ;
V_157:
F_71 ( V_3 -> V_4 , V_95 , V_121 , V_113 -> V_120 ) ;
V_156:
F_76 ( V_113 ) ;
V_155:
return V_75 ;
}
static int F_85 ( struct V_2 * V_3 , T_7 V_97 )
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
V_63 -> V_65 = 0x00 | V_158 ;
V_63 -> V_66 = 0x04 ;
V_63 -> V_67 = 0x00 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 4 ;
V_63 -> V_45 = V_97 ;
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
static int F_86 ( struct V_2 * V_3 , int V_159 ,
T_5 V_68 , T_7 V_97 )
{
T_5 V_160 = V_159 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x00 | ( V_161 & 0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_63 -> V_67 = V_160 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 4 ;
V_63 -> V_45 = V_97 ;
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
static int F_87 ( struct V_2 * V_3 , int V_162 ,
T_5 V_68 , T_7 V_97 )
{
T_5 V_160 = V_162 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x00 | ( V_163 & 0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_63 -> V_67 = V_160 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 4 ;
V_63 -> V_45 = V_97 ;
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
int F_88 ( struct V_18 * V_19 , int V_162 ,
T_5 V_68 , T_7 V_97 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_87 ( V_3 , V_162 , V_68 , V_97 ) ;
}
static int F_89 ( struct V_2 * V_3 , T_7 * V_97 )
{
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
int V_164 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
V_164 = V_3 -> V_39 - V_3 -> V_40 ;
if ( V_58 < V_61 && V_164 < V_165 )
{
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_3 -> V_39 ] ;
int V_23 = - V_76 ;
V_42 -> V_23 = & V_23 ;
V_42 -> V_65 = V_63 -> V_65 = 0x00 | V_166 ;
V_63 -> V_66 = 0x04 ;
V_42 -> V_67 = V_63 -> V_67 = V_167 ;
V_63 -> V_68 = 0x00 ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_42 -> V_45 = V_97 ;
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
static int F_92 ( struct V_2 * V_3 , int V_159 ,
T_5 V_68 , T_7 * V_97 )
{
T_5 V_160 = V_159 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
int V_164 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
V_164 = V_3 -> V_39 - V_3 -> V_40 ;
if ( V_58 < V_61 && V_164 < V_165 )
{
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
struct V_41 * V_42 = & V_3 -> V_42 [
V_43 & V_3 -> V_39 ] ;
int V_23 = - V_76 ;
V_42 -> V_23 = & V_23 ;
V_42 -> V_65 = V_63 -> V_65 = 0x00 | ( V_168 &
0x0F ) ;
V_63 -> V_66 = 0x04 ;
V_42 -> V_67 = V_63 -> V_67 = V_160 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_42 -> V_45 = V_97 ;
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
static int F_93 ( struct V_2 * V_3 , int V_162 ,
T_5 V_68 , T_7 * V_97 )
{
T_5 V_160 = V_162 / 4 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else {
int V_58 ;
int V_164 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
V_164 = V_3 -> V_39 - V_3 -> V_40 ;
if ( V_58 < V_61 && V_164 < V_165 )
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
V_42 -> V_67 = V_63 -> V_67 = V_160 ;
V_63 -> V_68 = 0x00 | ( V_68 & 0x0F ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_42 -> V_45 = V_97 ;
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
int F_94 ( struct V_18 * V_19 , int V_162 ,
T_5 V_68 , T_7 * V_97 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else
return F_93 ( V_3 , V_162 , V_68 , V_97 ) ;
}
static int F_95 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
T_5 V_172 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_172 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x80 | ( V_172 << 5 ) ;
V_63 -> V_66 = 0x8007 ;
V_63 -> V_67 = ( V_141 << 6 ) | ( V_170 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_113 -> V_5 , V_113 -> V_173 ,
F_97 ( V_113 -> V_173 ) ) ;
V_63 -> V_69 = 8 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = V_113 -> V_174 ;
V_49 -> F_80 = F_80 ;
V_49 -> V_144 = V_144 ;
V_49 -> V_113 = V_113 ;
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
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_95 ( V_3 , V_47 , V_144 , V_113 , V_67 ,
V_170 , V_141 , F_80 ) ;
}
static int F_99 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
T_5 V_172 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_172 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
T_7 V_175 = V_113 -> V_118 -
V_113 -> V_176 ;
V_63 -> V_65 = 0x82 | ( V_172 << 5 ) ;
if ( V_175 == 0 ) {
V_63 -> V_66 = 0x0000 ;
} else if ( V_175 > 1024 ) {
V_63 -> V_66 = 0x8000 | 1023 ;
} else
V_63 -> V_66 = 0x8000 | ( V_175 -
1 ) ;
V_63 -> V_67 = ( V_141 << 6 ) | ( V_170 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_113 -> V_5 , V_113 -> V_173 ,
F_97 ( V_113 -> V_173 ) ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_49 -> F_80 = F_80 ;
V_49 -> V_144 = V_144 ;
V_49 -> V_113 = V_113 ;
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
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_99 ( V_3 , V_47 , V_144 , V_113 , V_67 ,
V_170 , V_141 , F_80 ) ;
}
static int F_101 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
T_5 V_172 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
struct V_48 * V_49 = & V_3 -> V_49 [ V_172 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x81 | ( V_172 << 5 ) ;
V_63 -> V_66 = 0x0000 ;
V_63 -> V_67 = ( V_141 << 6 ) | ( V_170 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_113 -> V_5 , V_113 -> V_173 ,
F_97 ( V_113 -> V_173 ) ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_49 -> F_80 = F_80 ;
V_49 -> V_144 = V_144 ;
V_49 -> V_113 = V_113 ;
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
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_101 ( V_3 , V_47 , V_144 , V_113 , V_67 ,
V_170 , V_141 , F_80 ) ;
}
static int F_103 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
T_5 V_172 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
T_5 * V_124 ;
T_6 V_177 ;
int V_126 = 0 ;
char V_97 [ 30 * 3 + 4 ] ;
char * V_98 = V_97 ;
int V_99 = ( sizeof( V_97 ) - 1 ) / 3 ;
int V_178 = 0 ;
struct V_48 * V_49 = & V_3 -> V_49 [ V_172 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x81 | ( V_172 << 5 ) ;
V_63 -> V_67 = ( V_141 << 6 ) | ( V_170 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_113 -> V_5 , V_113 -> V_173 ,
F_97 ( V_113 -> V_173 ) ) ;
V_63 -> V_69 = F_104 ( T_7 , 1024 ,
V_113 -> V_118 -
V_113 -> V_176 ) ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = V_113 -> V_119 +
V_113 -> V_176 ;
V_63 -> V_66 = 0x8000 | ( V_63 -> V_69 - 1 ) ;
V_124 = V_63 -> V_70 ;
V_177 = V_63 -> V_69 ;
V_97 [ 0 ] = 0 ;
while ( V_177 -- > 0 ) {
if ( V_126 > V_99 ) {
} else if ( V_126 ++ < V_99 ) {
int V_179 = sprintf ( V_98 , L_15 , * V_124 ++ ) ;
V_98 += V_179 ;
V_178 += V_179 ;
} else
V_98 += sprintf ( V_98 , L_16 ) ;
}
V_49 -> F_80 = F_80 ;
V_49 -> V_144 = V_144 ;
V_49 -> V_113 = V_113 ;
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
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_103 ( V_3 , V_47 , V_144 , V_113 , V_67 ,
V_170 , V_141 , F_80 ) ;
}
static int F_106 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
T_5 V_172 = V_47 - 1 ;
V_72: if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
int V_58 ;
F_5 ( & V_3 -> V_38 ) ;
V_58 = V_3 -> V_59 - V_3 -> V_60 ;
if ( V_58 < V_61 ) {
T_7 V_175 = V_113 -> V_118 -
V_113 -> V_176 ;
struct V_48 * V_49 = & V_3 -> V_49 [ V_172 ] ;
struct V_62 * V_63 = & V_3 -> V_63 [
V_64 & V_3 -> V_59 ] ;
V_63 -> V_65 = 0x83 | ( V_172 << 5 ) ;
if ( V_175 == 0 ) {
V_63 -> V_66 = 0x0000 ;
} else if ( V_175 > 1024 ) {
V_63 -> V_66 = 0x8000 | 1023 ;
} else
V_63 -> V_66 = 0x8000 | ( V_175 -
1 ) ;
V_63 -> V_67 = ( V_141 << 6 ) | ( V_170 << 2 )
| ( V_67 << 0 ) ;
V_63 -> V_68 = F_96 ( V_113 -> V_5 , V_113 -> V_173 ,
F_97 ( V_113 -> V_173 ) ) ;
V_63 -> V_69 = 0 ;
V_63 -> V_45 = 0 ;
V_63 -> V_70 = NULL ;
V_49 -> F_80 = F_80 ;
V_49 -> V_144 = V_144 ;
V_49 -> V_113 = V_113 ;
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
void * V_144 , struct V_113 * V_113 , T_5 V_67 , T_5 V_170 , T_5 V_141 ,
void (* F_80) ( void * V_144 , struct V_113 * V_113 , T_5 * V_121 , int V_171 ,
int V_141 , int V_142 , int V_51 , int V_143 ,
int V_137 , int V_138 , int V_139 , int V_140 ) )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_106 ( V_3 , V_47 , V_144 , V_113 , V_67 ,
V_170 , V_141 , F_80 ) ;
}
static int F_108 ( struct V_2 * V_3 , T_5 V_47 ,
void * V_144 )
{
T_5 V_172 = V_47 - 1 ;
if ( V_3 -> V_6 > 0 ) {
return - V_76 ;
} else if ( V_3 -> V_83 == 0 ) {
return - V_76 ;
} else {
struct V_48 * V_49 = & V_3 -> V_49 [ V_172 ] ;
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
V_63 -> V_65 = 0x80 | ( V_172 << 5 ) |
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
void * V_144 )
{
struct V_2 * V_3 = F_27 ( V_19 ) ;
return F_108 ( V_3 , V_47 , V_144 ) ;
}
static int F_110 ( struct V_2 * V_3 )
{
int V_101 = 10 ;
int V_102 = 5 ;
int V_180 = 20 ;
V_108: {
int V_109 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_110 ) ,
V_3 -> V_10 , V_3 -> V_111 ,
& V_109 , 100 ) ;
if ( V_109 > 2 ) {
char V_134 [ 30 * 3 + 4 ] ;
char * V_98 = V_134 ;
int V_99 = ( sizeof( V_134 ) - 1 ) / 3 ;
char * V_124 = V_3 -> V_10 ;
int V_100 = 0 ;
V_134 [ 0 ] = 0 ;
while ( V_109 -- > 0 ) {
char V_135 = * V_124 ++ ;
if ( V_100 < V_99 ) {
V_98 += sprintf ( V_98 , L_15 ,
0x000000FF & V_135 ) ;
} else if ( V_100 > V_99 ) {
} else
V_98 += sprintf ( V_98 , L_16 ) ;
V_100 += 1 ;
continue;
}
goto V_108;
} else if ( V_109 > 1 ) {
char V_152 = V_3 -> V_10 [ 0 ] ;
char V_181 = V_3 -> V_10 [ 1 ] ;
if ( V_152 == 0x31 && V_181 == 0x60 ) {
return 0 ;
} else if ( V_180 -- > 0 ) {
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_26 ) ;
return - V_107 ;
}
} else if ( V_109 > 0 ) {
char V_182 = V_3 -> V_10 [ 0 ] ;
F_45 ( & V_3 -> V_4 -> V_5 , L_27 ,
V_182 ) ;
if ( V_180 -- > 0 ) {
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_26 ) ;
return - V_107 ;
}
} else if ( V_75 == - V_112 ) {
if ( V_102 -- > 0 ) {
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_28 ) ;
return - V_130 ;
}
} else if ( V_75 == 0 ) {
if ( V_101 -- > 0 ) {
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_29 ) ;
return - V_130 ;
}
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_30 , V_75 ) ;
return V_75 ;
}
}
return - 1 ;
}
static int F_111 ( struct V_2 * V_3 )
{
int V_75 ;
struct V_113 * V_113 ;
char * V_121 ;
int V_125 = 257 ;
int V_126 = 0 ;
V_113 = F_74 ( 0 , V_129 ) ;
if ( ! V_113 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_31 ) ;
return - V_130 ;
}
V_121 = F_75 ( V_3 -> V_4 , V_125 , V_129 , & V_113 -> V_120 ) ;
if ( ! V_121 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_32 ) ;
F_76 ( V_113 ) ;
return - V_130 ;
}
while ( V_125 -- > 0 )
V_121 [ V_126 ++ ] = 0x55 ;
F_77 ( V_113 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_131 ) , V_121 , V_126 ,
F_70 , V_3 ) ;
V_113 -> V_132 |= V_133 ;
V_75 = F_79 ( V_113 , V_129 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_33 ) ;
F_71 ( V_3 -> V_4 , V_126 , V_121 , V_113 -> V_120 ) ;
F_76 ( V_113 ) ;
return - V_130 ;
}
F_76 ( V_113 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
int V_75 ;
struct V_113 * V_113 ;
char * V_121 ;
int V_125 = 4 ;
int V_126 = 0 ;
V_113 = F_74 ( 0 , V_129 ) ;
if ( ! V_113 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_34 ) ;
return - V_130 ;
}
V_121 = F_75 ( V_3 -> V_4 , V_125 , V_129 , & V_113 -> V_120 ) ;
if ( ! V_121 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_35 ) ;
F_76 ( V_113 ) ;
return - V_130 ;
}
V_121 [ V_126 ++ ] = 0x55 ;
V_121 [ V_126 ++ ] = 0xAA ;
V_121 [ V_126 ++ ] = 0x5A ;
V_121 [ V_126 ++ ] = 0xA5 ;
F_77 ( V_113 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_131 ) , V_121 , V_126 ,
F_70 , V_3 ) ;
V_113 -> V_132 |= V_133 ;
V_75 = F_79 ( V_113 , V_129 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_36 ) ;
F_71 ( V_3 -> V_4 , V_126 , V_121 , V_113 -> V_120 ) ;
F_76 ( V_113 ) ;
return - V_130 ;
}
F_76 ( V_113 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_75 ;
int V_183 = 10 ;
int V_102 = 5 ;
int V_101 = 10 ;
int V_184 = 0 ;
V_75 = F_110 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_3 -> V_104 = 0 ;
V_3 -> V_106 = - 1 ;
while ( V_183 -- > 0 ) {
int V_185 ;
int V_186 ;
V_75 = F_111 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_110 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_28: V_75 = F_112 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_185 = 100 ;
V_186 = 10 ;
V_150: {
int V_109 = 0 ;
V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 ,
V_3 -> V_110 ) ,
V_3 -> V_10 , V_3 -> V_111 ,
& V_109 , 500 ) ;
if ( V_109 > 2 ) {
char V_134 [ 30 * 3 + 4 ] ;
char * V_98 = V_134 ;
int V_99 = ( sizeof( V_134 ) - 1 ) / 3 ;
char * V_124 = V_3 -> V_10 ;
int V_100 = 0 ;
unsigned char V_135 = 0 ;
V_134 [ 0 ] = 0 ;
while ( V_109 -- > 0 ) {
V_135 = * V_124 ++ ;
if ( V_100 < V_99 ) {
V_98 += sprintf ( V_98 , L_15 , V_135 ) ;
} else if ( V_100 > V_99 ) {
} else
V_98 += sprintf ( V_98 , L_16 ) ;
V_100 += 1 ;
continue;
}
if ( V_135 == 0x7E ) {
return 0 ;
} else {
if ( V_135 == 0x55 ) {
goto V_150;
} else if ( V_185 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37 ) ;
continue;
}
}
} else if ( V_109 > 1 ) {
unsigned char V_152 = V_3 -> V_10 [ 0 ] ;
unsigned char V_181 = V_3 -> V_10 [ 1 ] ;
if ( V_152 == 0x31 && V_181 == 0x00 ) {
if ( V_186 -- > 0 ) {
goto V_150;
} else
goto V_28;
} else if ( V_152 == 0x31 && V_181 == 0x60 ) {
if ( V_185 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37 ) ;
continue;
}
} else {
if ( V_185 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37 ) ;
continue;
}
}
} else if ( V_109 > 0 ) {
if ( V_185 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37 ) ;
continue;
}
} else if ( V_75 == - V_112 ) {
if ( V_102 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_28 ) ;
continue;
}
} else if ( V_75 == 0 ) {
if ( V_101 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_29 ) ;
continue;
}
} else {
V_184 += 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_30 ,
V_75 ) ;
if ( V_185 -- > 0 ) {
goto V_150;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37 ) ;
continue;
}
}
}
}
F_45 ( & V_3 -> V_4 -> V_5 , L_38 ) ;
return - V_107 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_101 = 10 ;
int V_102 = 5 ;
int V_180 = 50 ;
V_108: {
int V_109 = 0 ;
int V_75 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_110 ) ,
V_3 -> V_10 , V_3 -> V_111 ,
& V_109 , 1000 ) ;
if ( V_109 > 2 ) {
char V_134 [ 30 * 3 + 4 ] ;
char * V_98 = V_134 ;
int V_99 = ( sizeof( V_134 ) - 1 ) / 3 ;
char * V_124 = V_3 -> V_10 ;
int V_100 = 0 ;
V_134 [ 0 ] = 0 ;
while ( V_109 -- > 0 ) {
char V_135 = * V_124 ++ ;
if ( V_100 < V_99 ) {
V_98 += sprintf ( V_98 , L_15 ,
0x000000FF & V_135 ) ;
} else if ( V_100 > V_99 ) {
} else
V_98 += sprintf ( V_98 , L_16 ) ;
V_100 += 1 ;
continue;
}
goto V_108;
} else if ( V_109 > 1 ) {
char V_152 = V_3 -> V_10 [ 0 ] ;
char V_181 = V_3 -> V_10 [ 1 ] ;
if ( V_152 == 0x31 && V_181 == 0x60 ) {
return 0 ;
} else if ( V_180 -- > 0 ) {
F_40 ( 5 ) ;
goto V_108;
} else
return - V_107 ;
} else if ( V_109 > 0 ) {
char V_182 = V_3 -> V_10 [ 0 ] ;
F_45 ( & V_3 -> V_4 -> V_5 , L_27 , V_182 ) ;
if ( V_180 -- > 0 ) {
F_40 ( 5 ) ;
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_26 ) ;
return - V_107 ;
}
} else if ( V_75 == - V_112 ) {
if ( V_102 -- > 0 ) {
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_28 ) ;
return - V_130 ;
}
} else if ( V_75 == 0 ) {
if ( V_101 -- > 0 ) {
goto V_108;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_29 ) ;
return - V_130 ;
}
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_30 , V_75 ) ;
return - V_130 ;
}
}
return - 1 ;
}
static int F_57 ( struct V_2 * V_3 )
{
int V_187 = F_89 ( V_3 , & V_3 -> V_85 ) ;
if ( V_187 )
return V_187 ;
if ( V_3 -> V_85 & 0x00400000 ) {
if ( V_3 -> V_86 ) {
} else {
V_3 -> V_86 = 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_39 ,
V_3 -> V_85 ) ;
}
return - V_76 ;
} else {
T_5 V_188 = V_3 -> V_189 - 1 ;
int V_190 = V_188 << 8 ;
T_7 V_191 ;
T_7 V_192 ;
T_7 V_193 ;
int V_194 = 0 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_192 = V_191 & 0xFFFF ;
V_193 = ( V_191 >> 16 ) & 0xFFFF ;
if ( V_192 == V_3 -> V_26 . V_195 && V_193 ==
V_3 -> V_26 . V_21 ) {
return 0 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_40 ,
V_3 -> V_26 . V_195 , V_192 ,
V_3 -> V_26 . V_21 , V_193 ) ;
return - V_76 ;
}
}
}
static int F_113 ( struct V_2 * V_3 , int V_196 )
{
int V_197 = 0 ;
int V_75 ;
T_7 V_198 ;
int V_199 ;
T_7 V_200 ;
T_7 V_201 = - 1 ;
T_7 V_115 ;
T_7 V_202 ;
T_7 V_203 ;
T_7 V_204 ;
T_7 V_205 ;
T_7 V_206 ;
int V_207 = V_208 ;
int V_209 = 0 ;
int V_210 = 30 ;
int V_211 ;
V_75 = F_114 ( V_3 , V_212 , V_213 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_200 , & V_200 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_214 . V_215 , & V_201 ) ;
if ( V_75 )
return V_75 ;
V_199 = V_201 & V_216 ;
V_75 = F_115 ( V_3 , V_202 , & V_203 ) ;
if ( V_75 )
return V_75 ;
V_203 &= 0x3fff ;
if ( V_203 != V_217 ) {
}
V_203 |= F_116 ( V_203 ) << 16 ;
V_75 = F_115 ( V_3 , V_200 , & V_198 ) ;
if ( V_75 )
return V_75 ;
switch ( V_198 & V_218 ) {
case V_219 :
V_209 = 0 ;
break;
case V_220 :
case V_221 :
V_198 &= V_222 ;
V_198 |= V_221 ;
V_209 = 10 ;
break;
default:
V_198 &= V_222 ;
V_198 |= V_223 ;
V_209 = 50 ;
break;
}
V_75 = F_114 ( V_3 , V_200 , V_198 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_200 , & V_200 ) ;
if ( V_75 )
return V_75 ;
F_40 ( V_209 ) ;
V_75 = F_115 ( V_3 , V_214 . V_215 , & V_206 ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_206 & V_224 ) ) {
for ( V_211 = 0 ; V_211 < V_199 ; V_211 ++ ) {
V_75 = F_114 ( V_3 ,
V_214 . V_225 [ V_211 ] , V_226 ) ;
if ( V_75 )
return V_75 ;
}
}
V_75 = F_115 ( V_3 , V_200 , & V_200 ) ;
if ( V_75 )
return V_75 ;
V_227: V_75 = F_115 ( V_3 , V_205 , & V_115 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_205 , V_228 ) ;
if ( V_75 )
return V_75 ;
V_229: {
V_75 = F_115 ( V_3 , V_205 , & V_115 ) ;
if ( V_75 )
return V_75 ;
if ( 0 != ( V_115 & V_228 ) ) {
if ( -- V_210 == 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_41 ) ;
return - V_76 ;
} else {
F_40 ( 5 ) ;
goto V_229;
}
}
}
if ( V_196 & V_230 ) {
V_75 = F_114 ( V_3 , V_200 , V_198 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_200 , & V_200 ) ;
if ( V_75 )
return V_75 ;
}
V_75 = F_114 ( V_3 , V_231 , 0x00000000 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_232 , 0x11000000 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_233 , 0x00000000 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_202 , & V_202 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_202 ,
( ( V_202 & V_234 ) ^ V_234 ) | V_203 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_204 ,
( ( 9 * V_203 ) / 10 ) & 0x3fff ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_202 , & V_202 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_204 , & V_204 ) ;
if ( V_75 )
return V_75 ;
if ( 0 == ( V_202 & 0x3fff0000 ) || 0 == V_204 ) {
if ( ! ( V_196 & V_230 ) ) {
V_196 |= V_230 ;
goto V_227;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_42 ,
V_202 , V_204 ) ;
}
V_198 &= V_222 ;
V_198 |= V_235 | V_236 | V_219 ;
V_75 = F_114 ( V_3 , V_200 , V_198 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_205 , V_237 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_205 , & V_205 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_200 , & V_200 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_214 . V_115 , V_238 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_239 , V_207 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_212 ,
V_213 | V_240 | V_241 | V_242 |
V_243 | V_244 | V_245 | V_246 |
V_247 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_214 . V_215 , & V_206 ) ;
if ( V_75 )
return V_75 ;
V_206 &= ~ ( V_248 | V_249 ) ;
if ( V_196 & V_250 ) {
V_206 |= V_251 ;
V_206 &= ~ ( V_252 | V_224 ) ;
V_75 = F_114 ( V_3 , V_214 . V_215 , V_206 ) ;
if ( V_75 )
return V_75 ;
} else if ( ( V_196 & V_253 ) || V_254 ) {
V_206 |= V_224 ;
V_75 = F_114 ( V_3 , V_214 . V_215 , V_206 ) ;
if ( V_75 )
return V_75 ;
}
V_75 = F_114 ( V_3 , V_214 . V_115 , V_255 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_3 , V_214 . V_124 ,
( V_206 & V_224 ) ? 0 : V_256 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_115 ( V_3 , V_200 , & V_200 ) ;
if ( V_75 )
return V_75 ;
F_117 ( ( V_206 >> 23 ) & 0x1fe ) ;
for ( V_211 = 0 ; V_211 < V_199 ; V_211 ++ ) {
T_7 V_225 ;
V_75 = F_115 ( V_3 , V_214 . V_225 [ V_211 ] ,
& V_225 ) ;
if ( V_75 )
return V_75 ;
if ( 1 & V_225 )
V_197 += 1 ;
}
return V_197 ;
}
static int F_118 ( struct V_2 * V_3 , int V_188 )
{
T_7 V_257 ;
int V_187 ;
T_7 V_191 ;
int V_194 = 0 ;
int V_190 = V_188 << 8 ;
V_187 = F_85 ( V_3 , 0x0000025FL | 0x2800 ) ;
if ( V_187 )
return V_187 ;
V_194 = 16 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0 ,
0xFFFFFFFF ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0 ,
0xF0000000 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_194 = 12 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_257 ) ;
if ( V_187 )
return V_187 ;
V_257 &= 0xFFFF00FF ;
V_257 |= 0x00001600 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0x00 ,
V_257 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_194 = 4 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0x00 ,
0x06 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
for ( V_194 = 0 ; V_194 <= 0x54 ; V_194 += 4 ) {
V_187 = F_93 ( V_3 , V_194 , 0 , & V_191 ) ;
if ( V_187 )
return V_187 ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 , int V_188 )
{
T_7 V_257 ;
int V_187 ;
T_7 V_191 ;
int V_194 = 0 ;
int V_190 = V_188 << 8 ;
V_187 = F_85 ( V_3 , 0x0000025FL | 0x2800 ) ;
if ( V_187 )
return V_187 ;
V_194 = 16 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0 ,
0xFFFFFFFF ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0 ,
0x00000000 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_194 = 12 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_257 ) ;
if ( V_187 )
return V_187 ;
V_257 &= 0xFFFF00FF ;
V_257 |= 0x00001600 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0x00 ,
V_257 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_194 = 4 ;
V_187 = F_86 ( V_3 , V_190 | V_194 , 0x00 ,
0x00 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
return 0 ;
}
static int F_120 ( struct V_2 * V_3 , int V_188 , int V_196 )
{
int V_23 ;
int V_187 ;
V_187 = F_118 ( V_3 , V_188 ) ;
if ( V_187 )
return V_187 ;
V_23 = F_113 ( V_3 , V_196 ) ;
V_187 = F_119 ( V_3 , V_188 ) ;
if ( V_187 )
return V_187 ;
return V_23 ;
}
static int F_55 ( struct V_2 * V_3 )
{
T_7 V_85 ;
T_5 V_258 ;
int V_187 ;
V_187 = F_89 ( V_3 , & V_85 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_85 ( V_3 , 0x00000000L ) ;
if ( V_187 )
return V_187 ;
F_40 ( 750 ) ;
V_187 = F_85 ( V_3 , 0x00000200L | 0x100 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_85 ( V_3 , 0x00000200L | 0x500 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_89 ( V_3 , & V_85 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_85 ( V_3 , 0x0000020CL | 0x000 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_85 ( V_3 , 0x0000020DL | 0x000 ) ;
if ( V_187 )
return V_187 ;
F_40 ( 250 ) ;
V_187 = F_85 ( V_3 , 0x0000020FL | 0x000 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_89 ( V_3 , & V_85 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_85 ( V_3 , 0x0000025FL | 0x800 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_89 ( V_3 , & V_85 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_89 ( V_3 , & V_85 ) ;
if ( V_187 )
return V_187 ;
F_40 ( 1000 ) ;
V_258 = ( V_85 >> 16 ) & 0x000F ;
if ( 0x0D == V_258 )
return 0 ;
else
return - V_259 ;
}
static int F_56 ( struct V_2 * V_3 )
{
int V_187 ;
T_7 V_191 ;
int V_194 = 0 ;
T_5 V_188 ;
int V_190 = 0 ;
int V_260 = 0 ;
int V_261 = 0 ;
int V_262 = 0 ;
V_3 -> V_189 = 0 ;
for ( V_188 = 0 ; ( V_188 < 4 ) ; V_188 ++ ) {
T_7 V_192 = 0 ;
T_7 V_193 = 0 ;
int V_197 = 0 ;
V_190 = V_188 << 8 ;
V_187 = F_92 ( V_3 , V_190 | V_194 , 0 ,
& V_191 ) ;
if ( V_187 )
return V_187 ;
V_192 = V_191 & 0xFFFF ;
V_193 = ( V_191 >> 16 ) & 0xFFFF ;
if ( ( V_192 == V_263 ) && ( V_193 == 0xc861 ) ) {
V_197 = F_120 ( V_3 , V_188 , 0 ) ;
V_261 += 1 ;
} else if ( ( V_192 == V_264 ) && ( V_193 == 0x0035 ) )
{
V_197 = F_120 ( V_3 , V_188 , 0 ) ;
V_261 += 1 ;
} else if ( ( V_192 == V_265 ) && ( V_193 == 0x5237 ) ) {
V_197 = F_120 ( V_3 , V_188 , 0 ) ;
V_261 += 1 ;
} else if ( ( V_192 == V_266 ) && ( V_193 == 0x5802 ) )
{
V_197 = F_120 ( V_3 , V_188 , 0 ) ;
V_261 += 1 ;
} else if ( V_192 == V_267 && V_193 == 0x740c ) {
V_197 = F_120 ( V_3 , V_188 ,
V_253 ) ;
V_261 += 1 ;
} else if ( V_192 == V_268 && V_193 == 0xa0f8 ) {
V_197 = F_120 ( V_3 , V_188 ,
V_269 ) ;
V_261 += 1 ;
} else if ( 0 == V_191 ) {
} else
V_262 += 1 ;
if ( V_197 > V_260 ) {
V_260 = V_197 ;
V_3 -> V_189 = V_188 + 1 ;
V_3 -> V_26 . V_195 = V_192 ;
V_3 -> V_26 . V_21 = V_193 ;
}
}
if ( V_3 -> V_189 > 0 ) {
V_187 = F_118 ( V_3 ,
V_3 -> V_189 - 1 ) ;
if ( V_187 )
return V_187 ;
return 0 ;
} else if ( V_261 > 0 ) {
return - V_259 ;
} else if ( V_262 > 0 ) {
return - V_259 ;
} else {
V_3 -> V_82 = 0 ;
return - V_259 ;
}
}
static int F_121 ( struct V_90 * V_91 ,
const struct V_270 * V_29 )
{
struct V_271 * V_272 ;
struct V_273 * V_274 ;
T_3 V_275 ;
int V_126 ;
int V_75 = - V_130 ;
struct V_2 * V_3 ;
V_3 = F_122 ( sizeof( struct V_2 ) , V_129 ) ;
if ( ! V_3 )
return - V_130 ;
F_5 ( & V_7 ) ;
F_123 ( & V_3 -> V_8 , & V_276 ) ;
V_3 -> V_30 = ++ V_9 ;
F_7 ( & V_7 ) ;
F_13 ( V_3 ) ;
F_124 ( & V_3 -> V_80 , 1 ) ;
V_3 -> V_4 = F_125 ( F_126 ( V_91 ) ) ;
V_3 -> V_91 = V_91 ;
F_127 ( & V_3 -> V_38 ) ;
V_3 -> V_54 = 4 ;
V_272 = V_91 -> V_277 ;
for ( V_126 = 0 ; V_126 < V_272 -> V_278 . V_279 ; ++ V_126 ) {
V_274 = & V_272 -> V_274 [ V_126 ] . V_278 ;
if ( ! V_3 -> V_110 &&
F_128 ( V_274 ) ) {
V_275 = F_129 ( V_274 ) ;
V_3 -> V_111 = V_275 ;
V_3 -> V_110 = V_274 -> V_280 ;
V_3 -> V_10 = F_130 ( V_275 , V_129 ) ;
if ( ! V_3 -> V_10 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_43 ) ;
V_75 = - V_130 ;
goto error;
}
}
if ( ! V_3 -> V_131 &&
F_131 ( V_274 ) ) {
V_3 -> V_131 =
V_274 -> V_280 ;
}
}
if ( ! ( V_3 -> V_110 && V_3 -> V_131 ) ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_44 ) ;
V_75 = - V_76 ;
goto error;
}
F_31 ( & V_3 -> V_4 -> V_5 , L_45 ,
V_272 -> V_278 . V_281 , V_3 -> V_110 ,
V_3 -> V_131 ) ;
F_132 ( V_91 , V_3 ) ;
if ( V_272 -> V_278 . V_281 == 0 &&
V_3 -> V_110 == 0x81 &&
V_3 -> V_131 == 0x02 ) {
V_75 = F_133 ( V_91 , & V_282 ) ;
if ( V_75 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_46 ) ;
F_132 ( V_91 , NULL ) ;
V_75 = - V_130 ;
goto error;
} else {
V_3 -> V_283 = & V_282 ;
F_31 ( & V_3 -> V_4 -> V_5 , L_47 ,
V_3 , V_272 -> V_278 . V_281 ,
V_91 -> V_284 ) ;
return 0 ;
}
} else if ( V_272 -> V_278 . V_281 == 1 &&
V_3 -> V_110 == 0x83 &&
V_3 -> V_131 == 0x04 ) {
V_3 -> V_283 = NULL ;
F_31 ( & V_3 -> V_4 -> V_5 , L_48 ,
V_3 , V_272 -> V_278 . V_281 ) ;
F_134 ( & V_3 -> V_13 , F_50 ) ;
F_134 ( & V_3 -> V_15 , F_42 ) ;
F_134 ( & V_3 -> V_17 , F_48 ) ;
F_17 ( V_3 , F_46 ( 3 * 1000 ) ) ;
return 0 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_49 ) ;
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
if ( V_3 -> V_283 ) {
int V_284 = V_91 -> V_284 ;
struct V_285 * V_283 = V_3 -> V_283 ;
F_132 ( V_91 , NULL ) ;
F_136 ( V_91 , V_283 ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_50 ,
V_284 ) ;
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
F_31 ( & V_3 -> V_4 -> V_5 , L_51 ) ;
}
F_9 ( V_3 ) ;
}
static int T_8 F_138 ( void )
{
int V_23 ;
F_139 ( L_52 , V_92 . V_37 ) ;
F_127 ( & V_7 ) ;
F_140 ( & V_276 ) ;
V_12 = F_141 ( L_53 ) ;
if ( ! V_12 )
goto V_286;
V_14 = F_141 ( L_54 ) ;
if ( ! V_14 )
goto V_287;
V_16 = F_141 ( L_55 ) ;
if ( ! V_16 )
goto V_288;
V_23 = F_142 ( & V_92 ) ;
if ( V_23 ) {
F_143 ( V_12 ) ;
F_143 ( V_14 ) ;
F_143 ( V_16 ) ;
F_62 ( L_56 , V_23 ) ;
}
return V_23 ;
V_288:
F_143 ( V_14 ) ;
V_287:
F_143 ( V_12 ) ;
V_286:
F_62 ( L_57 , V_92 . V_37 ) ;
return - V_130 ;
}
static void T_9 F_144 ( void )
{
struct V_2 * V_3 ;
struct V_2 * V_211 ;
F_145 ( & V_92 ) ;
F_139 ( L_58 ) ;
F_146 (ftdi, temp, &ftdi_static_list, ftdi_list) {
F_18 ( V_3 ) ;
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
} F_137 ( V_12 ) ;
F_143 ( V_12 ) ;
V_12 = NULL ;
F_137 ( V_14 ) ;
F_143 ( V_14 ) ;
V_14 = NULL ;
F_137 ( V_16 ) ;
F_143 ( V_16 ) ;
V_16 = NULL ;
}
