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
if ( ! F_16 ( & V_3 -> V_12 , V_11 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( F_16 ( & V_3 -> V_12 , V_11 ) )
F_12 ( & V_3 -> V_1 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_12 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_20 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( ! F_16 ( & V_3 -> V_13 , V_11 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_21 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( F_16 ( & V_3 -> V_13 , V_11 ) )
F_12 ( & V_3 -> V_1 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_13 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
unsigned int V_11 )
{
if ( ! F_16 ( & V_3 -> V_14 , V_11 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_24 ( struct V_2 * V_3 , unsigned int V_11 )
{
if ( F_16 ( & V_3 -> V_14 , V_11 ) )
F_12 ( & V_3 -> V_1 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_14 ) )
F_10 ( & V_3 -> V_1 , F_1 ) ;
}
void F_26 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
V_3 -> V_17 += 1 ;
F_9 ( V_3 ) ;
}
static void F_28 ( struct V_18 * V_5 )
{
V_5 -> V_19 = NULL ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_20 ;
if ( V_3 -> V_21 . V_5 . V_19 )
return - V_22 ;
F_11 ( V_3 ) ;
V_3 -> V_23 . V_24 = 100 ;
V_3 -> V_23 . V_25 = NULL ;
V_3 -> V_21 . V_26 = V_3 -> V_27 ;
V_3 -> V_21 . V_28 = V_3 -> V_29 ;
V_3 -> V_21 . V_30 = F_30 ( V_3 -> V_29 ) ;
V_3 -> V_21 . V_5 . V_23 = & V_3 -> V_23 ;
V_3 -> V_21 . V_5 . V_19 = NULL ;
V_3 -> V_21 . V_5 . V_31 = F_28 ;
V_3 -> V_21 . V_5 . V_32 = NULL ;
snprintf ( V_3 -> V_33 , sizeof( V_3 -> V_33 ) , L_2 ) ;
V_3 -> V_21 . V_34 = V_3 -> V_33 ;
F_31 ( & V_3 -> V_4 -> V_5 , L_3 , L_2 ) ;
F_32 ( L_2 ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_4 ,
V_3 -> V_21 . V_34 ) ;
V_20 = F_33 ( & V_3 -> V_21 ) ;
return V_20 ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_5 ( & V_3 -> V_35 ) ;
while ( V_3 -> V_36 > V_3 -> V_37 ) {
struct V_38 * V_39 = & V_3 -> V_39 [ V_40 &
V_3 -> V_37 ++ ] ;
* V_39 -> V_20 = - V_41 ;
* V_39 -> V_42 = 0 ;
F_35 ( & V_39 -> V_43 ) ;
} F_7 ( & V_3 -> V_35 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
int V_44 = 4 ;
F_5 ( & V_3 -> V_35 ) ;
while ( V_44 -- > 0 ) {
struct V_45 * V_46 = & V_3 -> V_46 [ V_44 ] ;
if ( V_46 -> V_47 == 1 ) {
V_46 -> V_48 = V_49 ;
F_7 ( & V_3 -> V_35 ) ;
F_37 ( V_3 , V_46 , NULL , 0 ) ;
F_5 ( & V_3 -> V_35 ) ;
}
}
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
int V_44 = 4 ;
F_5 ( & V_3 -> V_35 ) ;
while ( V_44 -- > 0 ) {
struct V_45 * V_46 = & V_3 -> V_46 [ V_44 ] ;
V_46 -> V_53 = 1 ;
V_54: if ( V_46 -> V_47 == 1 ) {
int V_55 = V_3 -> V_56 -
V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x80 | ( V_44 << 5 ) | 0x4 ;
V_60 -> V_63 = 0x00 ;
V_60 -> V_64 = 0x00 ;
V_60 -> V_65 = 0x00 ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_35 ) ;
goto V_54;
}
}
V_68: if ( V_46 -> V_47 == 1 ) {
int V_55 = V_3 -> V_56 -
V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x90 | ( V_44 << 5 ) ;
V_60 -> V_63 = 0x00 ;
V_60 -> V_64 = 0x00 ;
V_60 -> V_65 = 0x00 ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_35 ) ;
goto V_68;
}
}
}
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
int V_44 = 4 ;
F_5 ( & V_3 -> V_35 ) ;
while ( V_44 -- > 0 ) {
struct V_45 * V_46 = & V_3 -> V_46 [ V_44 ] ;
V_46 -> V_53 = 1 ;
V_69: if ( V_46 -> V_47 == 1 ) {
int V_55 = V_3 -> V_56 -
V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x80 | ( V_44 << 5 ) | 0x4 ;
V_60 -> V_63 = 0x00 ;
V_60 -> V_64 = 0x00 ;
V_60 -> V_65 = 0x00 ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_35 ) ;
goto V_69;
}
}
}
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_21 ( V_3 , 0 ) ;
}
static void F_42 ( struct V_70 * V_71 )
{
struct V_2 * V_3 =
F_43 ( V_71 , struct V_2 , V_13 . V_71 ) ;
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else {
int V_72 = F_44 ( V_3 ) ;
if ( V_72 == - V_41 ) {
V_3 -> V_6 += 1 ;
} else if ( V_72 == - V_73 ) {
V_3 -> V_6 += 1 ;
} else if ( V_72 )
F_45 ( & V_3 -> V_4 -> V_5 , L_5 , V_72 ) ;
F_20 ( V_3 , F_46 ( 10 ) ) ;
return;
}
}
static void F_47 ( struct V_2 * V_3 )
{
F_24 ( V_3 , 0 ) ;
}
static void F_48 ( struct V_70 * V_71 )
{
struct V_2 * V_3 =
F_43 ( V_71 , struct V_2 , V_14 . V_71 ) ;
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else {
int V_72 = F_49 ( V_3 ) ;
if ( V_72 == 0 ) {
} else if ( V_72 == - V_41 ) {
V_3 -> V_6 += 1 ;
} else if ( V_72 == - V_73 ) {
V_3 -> V_6 += 1 ;
} else if ( V_72 == - V_74 ) {
V_3 -> V_6 += 1 ;
} else {
V_3 -> V_6 += 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_6 , V_72 ) ;
}
if ( V_3 -> V_6 > 0 ) {
F_34 ( V_3 ) ;
F_36 ( V_3 ) ;
}
F_23 ( V_3 , F_46 ( 10 ) ) ;
return;
}
}
static void F_50 ( struct V_70 * V_71 )
{
struct V_2 * V_3 =
F_43 ( V_71 , struct V_2 , V_12 . V_71 ) ;
int V_75 = 0 ;
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else if ( V_3 -> V_76 == 0 ) {
F_51 ( & V_3 -> V_77 ) ;
if ( F_52 ( V_3 ) == 0 ) {
V_3 -> V_76 = 1 ;
F_21 ( V_3 , 1 ) ;
F_24 ( V_3 , 1 ) ;
F_53 ( & V_3 -> V_77 ) ;
V_75 = 100 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_7 ) ;
F_53 ( & V_3 -> V_77 ) ;
V_75 = 10 * 1000 ;
}
} else if ( V_3 -> V_78 > 0 ) {
if ( F_54 ( V_3 ) == 0 ) {
V_3 -> V_78 = 0 ;
V_3 -> V_76 = 0 ;
} else if ( ( V_3 -> V_78 ++ % 60 ) == 1 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_8 ) ;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_9 ,
V_3 -> V_78 ) ;
V_75 = 100 ;
} else if ( V_3 -> V_79 == 0 ) {
if ( F_55 ( V_3 ) == 0 ) {
V_3 -> V_79 = 1 ;
V_75 = 250 ;
} else
V_75 = 1000 ;
} else if ( V_3 -> V_80 == 0 ) {
if ( F_56 ( V_3 ) == 0 ) {
V_3 -> V_80 = 1 ;
V_75 = 500 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_10 ) ;
V_75 = 1 * 1000 ;
}
} else if ( V_3 -> V_81 == 0 ) {
V_75 = 10 ;
if ( F_29 ( V_3 ) == 0 ) {
V_3 -> V_81 = 1 ;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_11 ) ;
V_75 = 250 ;
} else {
if ( F_57 ( V_3 ) == 0 ) {
V_75 = 250 ;
} else if ( V_3 -> V_82 & 0x00400000 ) {
if ( V_3 -> V_17 > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_12 ,
V_3 -> V_21 . V_5 . V_19 ,
& V_3 -> V_21 . V_5 ) ;
F_58 ( & V_3 -> V_21 ) ;
V_3 -> V_21 . V_5 . V_19 = NULL ;
V_3 -> V_81 = 0 ;
V_3 -> V_79 = 0 ;
V_3 -> V_83 = 0 ;
V_3 -> V_80 = 0 ;
V_3 -> V_17 = 0 ;
} else
F_38 ( V_3 ) ;
V_75 = 250 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_13 ) ;
F_41 ( V_3 ) ;
V_75 = 500 ;
V_3 -> V_79 = 0 ;
V_3 -> V_80 = 0 ;
}
}
if ( V_3 -> V_6 > 0 ) {
F_9 ( V_3 ) ;
return;
} else {
F_15 ( V_3 ,
F_46 ( V_75 ) ) ;
return;
}
}
static int F_59 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
int V_86 ;
struct V_87 * V_88 ;
V_86 = F_60 ( V_84 ) ;
V_88 = F_61 ( & V_89 , V_86 ) ;
if ( ! V_88 ) {
F_62 ( L_14 , V_86 ) ;
return - V_73 ;
} else {
struct V_2 * V_3 = F_63 ( V_88 ) ;
if ( ! V_3 ) {
return - V_73 ;
} else {
if ( F_64 ( & V_3 -> V_77 ) ) {
return - V_90 ;
} else {
F_11 ( V_3 ) ;
V_85 -> V_91 = V_3 ;
return 0 ;
}
}
}
}
static int F_65 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_85 -> V_91 ;
if ( V_3 == NULL )
return - V_73 ;
F_53 ( & V_3 -> V_77 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static T_1 F_66 ( struct V_85 * V_85 , char T_2 * V_67 ,
T_3 V_92 , T_4 * V_93 )
{
char V_94 [ 30 * 3 + 4 ] ;
char * V_95 = V_94 ;
int V_96 = ( sizeof( V_94 ) - 1 ) / 3 - 1 ;
int V_97 = 0 ;
int V_98 = 10 ;
int V_99 = 5 ;
struct V_2 * V_3 = V_85 -> V_91 ;
if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
}
V_94 [ 0 ] = 0 ;
V_100: if ( V_3 -> V_101 > 0 ) {
if ( V_92 -- > 0 ) {
char * V_102 = ++ V_3 -> V_103 + V_3 -> V_10 ;
V_3 -> V_101 -= 1 ;
if ( V_97 < V_96 ) {
V_95 += sprintf ( V_95 , L_15 , 0x000000FF & * V_102 ) ;
} else if ( V_97 > V_96 ) {
} else
V_95 += sprintf ( V_95 , L_16 ) ;
if ( F_67 ( V_67 ++ , V_102 , 1 ) ) {
return - V_104 ;
} else {
V_97 += 1 ;
goto V_100;
}
} else
return V_97 ;
}
V_105: if ( V_92 > 0 ) {
int V_106 = 0 ;
int V_72 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_107 ) ,
V_3 -> V_10 , V_3 -> V_108 ,
& V_106 , 50 ) ;
if ( V_106 > 2 ) {
V_3 -> V_101 = V_106 - 2 ;
V_3 -> V_103 = 1 ;
goto V_100;
} else if ( V_72 == - V_109 ) {
if ( V_99 -- > 0 ) {
goto V_105;
} else if ( V_97 > 0 ) {
return V_97 ;
} else
return V_72 ;
} else if ( V_72 == 0 ) {
if ( V_98 -- > 0 ) {
goto V_105;
} else
return V_97 ;
} else
return V_72 ;
} else
return V_97 ;
}
static void F_70 ( struct V_110 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_111 ;
int V_112 = V_110 -> V_112 ;
if ( V_112 && ! ( V_112 == - V_113 || V_112 == - V_114 ||
V_112 == - V_41 ) ) {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_17 , V_110 , V_112 ) ;
}
F_71 ( V_110 -> V_5 , V_110 -> V_115 ,
V_110 -> V_116 , V_110 -> V_117 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
char * V_118 , int V_55 , int V_119 )
{
int V_120 = 0 ;
int V_121 = 0 ;
int V_122 = V_55 ;
int V_123 = V_3 -> V_57 ;
while ( V_122 -- > 0 ) {
struct V_59 * V_60 = & V_3 -> V_60 [ V_61 &
V_123 ++ ] ;
int V_124 = V_60 -> V_66 ;
T_5 * V_125 = V_60 -> V_67 ;
if ( V_60 -> V_62 & 0x80 ) {
V_120 |= 1 << ( 0x3 & ( V_60 -> V_62 >> 5 ) ) ;
}
V_118 [ V_121 ++ ] = V_60 -> V_62 ;
V_118 [ V_121 ++ ] = ( V_60 -> V_63 >> 0 ) & 0x00FF ;
V_118 [ V_121 ++ ] = ( V_60 -> V_63 >> 8 ) & 0x00FF ;
V_118 [ V_121 ++ ] = V_60 -> V_64 ;
V_118 [ V_121 ++ ] = V_60 -> V_65 ;
while ( V_124 -- > 0 ) {
V_118 [ V_121 ++ ] = * V_125 ++ ;
}
}
return V_120 ;
}
static int F_73 ( struct V_2 * V_3 , int V_55 )
{
int V_119 = 0 ;
int V_122 = V_55 ;
int V_123 = V_3 -> V_57 ;
while ( V_122 -- > 0 ) {
struct V_59 * V_60 = & V_3 -> V_60 [ V_61 &
V_123 ++ ] ;
V_119 += 5 + V_60 -> V_66 ;
} return V_119 ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_72 ;
char * V_118 ;
int V_120 ;
int V_119 ;
struct V_110 * V_110 ;
int V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 == 0 )
return 0 ;
V_119 = F_73 ( V_3 , V_55 ) ;
V_110 = F_74 ( 0 , V_126 ) ;
if ( ! V_110 )
return - V_127 ;
V_118 = F_75 ( V_3 -> V_4 , V_119 , V_126 ,
& V_110 -> V_117 ) ;
if ( ! V_118 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_18 ,
V_55 , V_119 ) ;
F_76 ( V_110 ) ;
return - V_127 ;
}
V_120 = F_72 ( V_3 , V_118 ,
V_55 , V_119 ) ;
F_77 ( V_110 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_128 ) , V_118 , V_119 ,
F_70 , V_3 ) ;
V_110 -> V_129 |= V_130 ;
if ( V_120 ) {
char V_131 [ 40 * 3 + 4 ] ;
char * V_95 = V_131 ;
int V_96 = V_119 ;
T_5 * V_132 = V_118 ;
int V_133 = ( sizeof( V_131 ) - 1 ) / 3 ;
V_131 [ 0 ] = 0 ;
while ( V_133 -- > 0 && V_96 -- > 0 ) {
if ( V_133 > 0 || V_96 == 0 ) {
V_95 += sprintf ( V_95 , L_15 , * V_132 ++ ) ;
} else
V_95 += sprintf ( V_95 , L_16 ) ;
}
}
V_72 = F_79 ( V_110 , V_126 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_19 ,
V_72 , V_110 , V_55 , V_119 ) ;
F_71 ( V_3 -> V_4 , V_119 , V_118 , V_110 -> V_117 ) ;
F_76 ( V_110 ) ;
return V_72 ;
}
F_76 ( V_110 ) ;
V_3 -> V_57 += V_55 ;
F_47 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_45 * V_46 , T_5 * V_67 , int V_63 )
{
struct V_110 * V_110 = V_46 -> V_110 ;
int V_134 = V_46 -> V_134 ;
int V_135 = V_46 -> V_135 ;
int V_136 = V_46 -> V_136 ;
int V_137 = V_46 -> V_137 ;
int V_138 = V_46 -> V_138 ;
int V_139 = V_46 -> V_139 ;
int V_48 = V_46 -> V_48 ;
int V_140 = V_46 -> V_140 ;
void (* F_80) ( void * , struct V_110 * , T_5 * , int , int , int , int , int ,
int , int , int , int ) = V_46 -> F_80 ;
V_46 -> V_47 -= 1 ;
V_46 -> F_80 = NULL ;
(* F_80) ( V_46 -> V_141 , V_110 , V_67 , V_63 , V_138 ,
V_139 , V_48 , V_140 , V_134 , V_135 ,
V_136 , V_137 ) ;
}
static char * F_81 ( struct V_2 * V_3 ,
struct V_45 * V_46 , T_6 V_142 , int V_44 , int V_143 ,
char * V_121 )
{
int V_144 = ( V_142 >> 0 ) & 0x07FF ;
F_5 ( & V_3 -> V_35 ) ;
V_46 -> V_136 = 0 ;
V_46 -> V_137 = ( V_142 >> 15 ) & 0x0001 ;
V_46 -> V_140 = ( V_142 >> 11 ) & 0x000F ;
if ( V_143 == 0x02 ) {
if ( V_144 == 0 || V_46 -> V_53 > 0 ) {
V_46 -> V_53 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
F_37 ( V_3 , V_46 , 4 + V_3 -> V_145 ,
V_144 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
return V_3 -> V_145 ;
} else {
V_3 -> V_51 = 4 + V_144 ;
V_3 -> V_52 = 1 ;
F_7 ( & V_3 -> V_35 ) ;
return V_121 ;
}
} else if ( V_143 == 0x03 ) {
if ( V_144 == 0 || V_46 -> V_53 > 0 ) {
V_46 -> V_53 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
F_37 ( V_3 , V_46 , 4 + V_3 -> V_145 ,
V_144 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
return V_3 -> V_145 ;
} else {
V_3 -> V_51 = 4 + V_144 ;
V_3 -> V_52 = 1 ;
F_7 ( & V_3 -> V_35 ) ;
return V_121 ;
}
} else if ( V_143 == 0x01 ) {
V_46 -> V_53 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
F_37 ( V_3 , V_46 , 4 + V_3 -> V_145 ,
V_144 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
return V_3 -> V_145 ;
} else {
V_46 -> V_53 = 0 ;
F_7 ( & V_3 -> V_35 ) ;
F_37 ( V_3 , V_46 , 4 + V_3 -> V_145 ,
V_144 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
return V_3 -> V_145 ;
}
}
static char * F_82 ( struct V_2 * V_3 ,
struct V_45 * V_46 , T_6 V_142 , int V_44 , int V_143 ,
char * V_121 )
{
F_5 ( & V_3 -> V_35 ) ;
V_46 -> V_48 = V_49 ;
V_46 -> V_136 = ( V_142 >> 0 ) & 0x01FF ;
V_46 -> V_137 = ( V_142 >> 15 ) & 0x0001 ;
V_46 -> V_140 = ( V_142 >> 11 ) & 0x000F ;
F_7 ( & V_3 -> V_35 ) ;
if ( V_46 -> V_47 )
F_37 ( V_3 , V_46 , NULL , 0 ) ;
V_46 -> V_53 = 0 ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
return V_3 -> V_145 ;
}
static int F_49 ( struct V_2 * V_3 )
{
T_5 * V_121 = V_3 -> V_145 + V_3 -> V_50 ;
int V_97 = 0 ;
int V_98 = 1 ;
int V_99 = 3 ;
int V_146 = 0 ;
V_147: {
int V_106 = 0 ;
int V_72 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_107 ) ,
V_3 -> V_10 , V_3 -> V_108 ,
& V_106 , 500 ) ;
char V_131 [ 30 * 3 + 4 ] ;
char * V_95 = V_131 ;
int V_96 = V_106 ;
T_5 * V_132 = V_3 -> V_10 ;
int V_133 = ( sizeof( V_131 ) - 1 ) / 3 ;
V_131 [ 0 ] = 0 ;
while ( V_133 -- > 0 && V_96 -- > 0 ) {
if ( V_133 > 0 || V_96 == 0 ) {
V_95 += sprintf ( V_95 , L_15 , * V_132 ++ ) ;
} else
V_95 += sprintf ( V_95 , L_16 ) ;
}
if ( V_106 > 2 ) {
V_3 -> V_101 = V_106 - 2 ;
V_3 -> V_103 = 1 ;
goto V_100;
} else if ( V_72 == - V_109 ) {
if ( V_99 -- > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_20 ,
V_106 , V_97 , V_131 ) ;
goto V_105;
} else if ( V_97 > 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_21 ,
V_97 , V_131 ) ;
return - V_127 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_20 ,
V_106 , V_97 , V_131 ) ;
return - V_127 ;
}
} else if ( V_72 == - V_74 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_22 ,
V_72 , V_106 , V_97 , V_131 ) ;
return V_72 ;
} else if ( V_72 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_22 ,
V_72 , V_106 , V_97 , V_131 ) ;
return V_72 ;
} else if ( V_106 == 2 ) {
unsigned char V_148 = V_3 -> V_10 [ 0 ] ;
unsigned char V_149 = V_3 -> V_10 [ 1 ] ;
V_146 += 1 ;
if ( V_148 == 0x31 && V_149 == 0x60 ) {
if ( V_98 -- > 0 ) {
goto V_105;
} else
return 0 ;
} else if ( V_148 == 0x31 && V_149 == 0x00 ) {
if ( V_98 -- > 0 ) {
goto V_105;
} else
return 0 ;
} else {
if ( V_98 -- > 0 ) {
goto V_105;
} else
return 0 ;
}
} else if ( V_106 == 1 ) {
if ( V_98 -- > 0 ) {
goto V_105;
} else
return 0 ;
} else {
if ( V_98 -- > 0 ) {
goto V_105;
} else
return 0 ;
}
}
V_105: {
goto V_147;
}
V_100: if ( V_3 -> V_101 > 0 ) {
T_5 V_132 = V_3 -> V_10 [ ++ V_3 -> V_103 ] ;
V_97 += 1 ;
V_3 -> V_101 -= 1 ;
if ( V_3 -> V_50 == 0 && V_132 == 0xFF ) {
goto V_100;
} else
* V_121 ++ = V_132 ;
if ( ++ V_3 -> V_50 < V_3 -> V_51 ) {
goto V_100;
} else if ( V_3 -> V_52 ) {
int V_44 = ( V_3 -> V_145 [ 0 ] >> 5 ) & 0x03 ;
T_6 V_142 = ( V_3 -> V_145 [ 2 ] << 8 ) |
V_3 -> V_145 [ 1 ] ;
struct V_45 * V_46 = & V_3 -> V_46 [ V_44 ] ;
int V_144 = ( V_142 >> 0 ) & 0x07FF ;
char V_131 [ 30 * 3 + 4 ] ;
char * V_95 = V_131 ;
int V_96 = V_144 ;
T_5 * V_132 = 4 + V_3 -> V_145 ;
int V_133 = ( sizeof( V_131 ) - 1 ) / 3 ;
V_131 [ 0 ] = 0 ;
while ( V_133 -- > 0 && V_96 -- > 0 ) {
if ( V_133 > 0 || V_96 == 0 ) {
V_95 += sprintf ( V_95 , L_15 , * V_132 ++ ) ;
} else
V_95 += sprintf ( V_95 , L_16 ) ;
}
F_37 ( V_3 , V_46 , 4 + V_3 -> V_145 ,
V_144 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
V_121 = V_3 -> V_145 ;
goto V_100;
} else if ( V_3 -> V_51 == 8 ) {
T_5 V_150 ;
int V_37 = V_3 -> V_37 ++ ;
struct V_38 * V_39 = & V_3 -> V_39 [
V_40 & V_37 ] ;
T_7 V_94 = V_3 -> V_145 [ 7 ] ;
V_94 <<= 8 ;
V_94 |= V_3 -> V_145 [ 6 ] ;
V_94 <<= 8 ;
V_94 |= V_3 -> V_145 [ 5 ] ;
V_94 <<= 8 ;
V_94 |= V_3 -> V_145 [ 4 ] ;
* V_39 -> V_42 = V_94 ;
* V_39 -> V_20 = 0 ;
F_35 ( & V_39 -> V_43 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 4 ;
V_3 -> V_52 = 0 ;
V_121 = V_3 -> V_145 ;
V_150 = ( V_3 -> V_145 [ 0 ] >> 0 ) & 0x0F ;
if ( V_150 == 0x00 ) {
} else if ( V_150 == 0x02 ) {
} else if ( V_150 == 0x06 ) {
} else if ( V_150 == 0x0A ) {
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_23 ,
V_150 , V_94 ) ;
goto V_100;
} else {
if ( ( V_3 -> V_145 [ 0 ] & 0x80 ) == 0x00 ) {
V_3 -> V_51 = 8 ;
goto V_100;
} else {
int V_44 = ( V_3 -> V_145 [ 0 ] >> 5 ) & 0x03 ;
int V_143 = ( V_3 -> V_145 [ 0 ] >> 0 ) & 0x03 ;
T_6 V_142 = ( V_3 -> V_145 [ 2 ] << 8 ) |
V_3 -> V_145 [ 1 ] ;
struct V_45 * V_46 = & V_3 -> V_46 [
V_44 ] ;
V_46 -> V_134 = ( V_3 -> V_145 [ 0 ] >> 3 ) &
0x01 ;
V_46 -> V_135 = ( V_3 -> V_145 [ 0 ] >> 2 ) &
0x01 ;
V_46 -> V_138 = ( V_3 -> V_145 [ 3 ] >> 6 )
& 0x03 ;
V_46 -> V_139 = ( V_3 -> V_145 [ 3 ] >> 4 )
& 0x03 ;
V_46 -> V_48 = ( V_3 -> V_145 [
3 ] >> 0 ) & 0x0F ;
if ( ( V_3 -> V_145 [ 0 ] & 0x10 ) == 0x00 ) {
V_121 = F_81 ( V_3 , V_46 ,
V_142 , V_44 , V_143 ,
V_121 ) ;
goto V_100;
} else {
V_121 = F_82 ( V_3 , V_46 ,
V_142 , V_44 , V_143 ,
V_121 ) ;
goto V_100;
}
}
}
} else
goto V_105;
}
static T_1 F_83 ( struct V_85 * V_85 ,
const char T_2 * V_151 , T_3 V_92 ,
T_4 * V_93 )
{
int V_72 = 0 ;
struct V_110 * V_110 ;
char * V_118 ;
struct V_2 * V_3 = V_85 -> V_91 ;
if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
}
if ( V_92 == 0 ) {
goto exit;
}
V_110 = F_74 ( 0 , V_126 ) ;
if ( ! V_110 ) {
V_72 = - V_127 ;
goto V_152;
}
V_118 = F_75 ( V_3 -> V_4 , V_92 , V_126 ,
& V_110 -> V_117 ) ;
if ( ! V_118 ) {
V_72 = - V_127 ;
goto V_153;
}
if ( F_84 ( V_118 , V_151 , V_92 ) ) {
V_72 = - V_104 ;
goto V_154;
}
F_77 ( V_110 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_128 ) , V_118 , V_92 ,
F_70 , V_3 ) ;
V_110 -> V_129 |= V_130 ;
V_72 = F_79 ( V_110 , V_126 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_24 , V_72 ) ;
goto V_154;
}
F_76 ( V_110 ) ;
exit:
return V_92 ;
V_154:
F_71 ( V_3 -> V_4 , V_92 , V_118 , V_110 -> V_117 ) ;
V_153:
F_76 ( V_110 ) ;
V_152:
return V_72 ;
}
static int F_85 ( struct V_2 * V_3 , T_7 V_94 )
{
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x00 | V_155 ;
V_60 -> V_63 = 0x04 ;
V_60 -> V_64 = 0x00 ;
V_60 -> V_65 = 0x00 ;
V_60 -> V_66 = 4 ;
V_60 -> V_42 = V_94 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
static int F_86 ( struct V_2 * V_3 , int V_156 ,
T_5 V_65 , T_7 V_94 )
{
T_5 V_157 = V_156 / 4 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x00 | ( V_158 & 0x0F ) ;
V_60 -> V_63 = 0x04 ;
V_60 -> V_64 = V_157 ;
V_60 -> V_65 = 0x00 | ( V_65 & 0x0F ) ;
V_60 -> V_66 = 4 ;
V_60 -> V_42 = V_94 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
static int F_87 ( struct V_2 * V_3 , int V_159 ,
T_5 V_65 , T_7 V_94 )
{
T_5 V_157 = V_159 / 4 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x00 | ( V_160 & 0x0F ) ;
V_60 -> V_63 = 0x04 ;
V_60 -> V_64 = V_157 ;
V_60 -> V_65 = 0x00 | ( V_65 & 0x0F ) ;
V_60 -> V_66 = 4 ;
V_60 -> V_42 = V_94 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_88 ( struct V_15 * V_16 , int V_159 ,
T_5 V_65 , T_7 V_94 )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_87 ( V_3 , V_159 , V_65 , V_94 ) ;
}
static int F_89 ( struct V_2 * V_3 , T_7 * V_94 )
{
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else {
int V_55 ;
int V_161 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
V_161 = V_3 -> V_36 - V_3 -> V_37 ;
if ( V_55 < V_58 && V_161 < V_162 )
{
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
struct V_38 * V_39 = & V_3 -> V_39 [
V_40 & V_3 -> V_36 ] ;
int V_20 = - V_73 ;
V_39 -> V_20 = & V_20 ;
V_39 -> V_62 = V_60 -> V_62 = 0x00 | V_163 ;
V_60 -> V_63 = 0x04 ;
V_39 -> V_64 = V_60 -> V_64 = V_164 ;
V_60 -> V_65 = 0x00 ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = NULL ;
V_39 -> V_42 = V_94 ;
F_90 ( & V_39 -> V_43 ) ;
V_3 -> V_56 += 1 ;
V_3 -> V_36 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
F_91 ( & V_39 -> V_43 ) ;
return V_20 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
static int F_92 ( struct V_2 * V_3 , int V_156 ,
T_5 V_65 , T_7 * V_94 )
{
T_5 V_157 = V_156 / 4 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else {
int V_55 ;
int V_161 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
V_161 = V_3 -> V_36 - V_3 -> V_37 ;
if ( V_55 < V_58 && V_161 < V_162 )
{
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
struct V_38 * V_39 = & V_3 -> V_39 [
V_40 & V_3 -> V_36 ] ;
int V_20 = - V_73 ;
V_39 -> V_20 = & V_20 ;
V_39 -> V_62 = V_60 -> V_62 = 0x00 | ( V_165 &
0x0F ) ;
V_60 -> V_63 = 0x04 ;
V_39 -> V_64 = V_60 -> V_64 = V_157 ;
V_60 -> V_65 = 0x00 | ( V_65 & 0x0F ) ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = NULL ;
V_39 -> V_42 = V_94 ;
F_90 ( & V_39 -> V_43 ) ;
V_3 -> V_56 += 1 ;
V_3 -> V_36 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
F_91 ( & V_39 -> V_43 ) ;
return V_20 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
static int F_93 ( struct V_2 * V_3 , int V_159 ,
T_5 V_65 , T_7 * V_94 )
{
T_5 V_157 = V_159 / 4 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else {
int V_55 ;
int V_161 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
V_161 = V_3 -> V_36 - V_3 -> V_37 ;
if ( V_55 < V_58 && V_161 < V_162 )
{
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
struct V_38 * V_39 = & V_3 -> V_39 [
V_40 & V_3 -> V_36 ] ;
int V_20 = - V_73 ;
V_39 -> V_20 = & V_20 ;
V_39 -> V_62 = V_60 -> V_62 = 0x00 | ( V_166 &
0x0F ) ;
V_60 -> V_63 = 0x04 ;
V_39 -> V_64 = V_60 -> V_64 = V_157 ;
V_60 -> V_65 = 0x00 | ( V_65 & 0x0F ) ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = NULL ;
V_39 -> V_42 = V_94 ;
F_90 ( & V_39 -> V_43 ) ;
V_3 -> V_56 += 1 ;
V_3 -> V_36 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
F_91 ( & V_39 -> V_43 ) ;
return V_20 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_94 ( struct V_15 * V_16 , int V_159 ,
T_5 V_65 , T_7 * V_94 )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else
return F_93 ( V_3 , V_159 , V_65 , V_94 ) ;
}
static int F_95 ( struct V_2 * V_3 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
T_5 V_169 = V_44 - 1 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_45 * V_46 = & V_3 -> V_46 [ V_169 ] ;
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x80 | ( V_169 << 5 ) ;
V_60 -> V_63 = 0x8007 ;
V_60 -> V_64 = ( V_138 << 6 ) | ( V_167 << 2 )
| ( V_64 << 0 ) ;
V_60 -> V_65 = F_96 ( V_110 -> V_5 , V_110 -> V_170 ,
F_97 ( V_110 -> V_170 ) ) ;
V_60 -> V_66 = 8 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = V_110 -> V_171 ;
V_46 -> F_80 = F_80 ;
V_46 -> V_141 = V_141 ;
V_46 -> V_110 = V_110 ;
V_46 -> V_47 = 1 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_98 ( struct V_15 * V_16 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_95 ( V_3 , V_44 , V_141 , V_110 , V_64 ,
V_167 , V_138 , F_80 ) ;
}
static int F_99 ( struct V_2 * V_3 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
T_5 V_169 = V_44 - 1 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_45 * V_46 = & V_3 -> V_46 [ V_169 ] ;
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
T_7 V_172 = V_110 -> V_115 -
V_110 -> V_173 ;
V_60 -> V_62 = 0x82 | ( V_169 << 5 ) ;
if ( V_172 == 0 ) {
V_60 -> V_63 = 0x0000 ;
} else if ( V_172 > 1024 ) {
V_60 -> V_63 = 0x8000 | 1023 ;
} else
V_60 -> V_63 = 0x8000 | ( V_172 -
1 ) ;
V_60 -> V_64 = ( V_138 << 6 ) | ( V_167 << 2 )
| ( V_64 << 0 ) ;
V_60 -> V_65 = F_96 ( V_110 -> V_5 , V_110 -> V_170 ,
F_97 ( V_110 -> V_170 ) ) ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = NULL ;
V_46 -> F_80 = F_80 ;
V_46 -> V_141 = V_141 ;
V_46 -> V_110 = V_110 ;
V_46 -> V_47 = 1 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_100 ( struct V_15 * V_16 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_99 ( V_3 , V_44 , V_141 , V_110 , V_64 ,
V_167 , V_138 , F_80 ) ;
}
static int F_101 ( struct V_2 * V_3 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
T_5 V_169 = V_44 - 1 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_45 * V_46 = & V_3 -> V_46 [ V_169 ] ;
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x81 | ( V_169 << 5 ) ;
V_60 -> V_63 = 0x0000 ;
V_60 -> V_64 = ( V_138 << 6 ) | ( V_167 << 2 )
| ( V_64 << 0 ) ;
V_60 -> V_65 = F_96 ( V_110 -> V_5 , V_110 -> V_170 ,
F_97 ( V_110 -> V_170 ) ) ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = NULL ;
V_46 -> F_80 = F_80 ;
V_46 -> V_141 = V_141 ;
V_46 -> V_110 = V_110 ;
V_46 -> V_47 = 1 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_102 ( struct V_15 * V_16 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_101 ( V_3 , V_44 , V_141 , V_110 , V_64 ,
V_167 , V_138 , F_80 ) ;
}
static int F_103 ( struct V_2 * V_3 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
T_5 V_169 = V_44 - 1 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
T_5 * V_121 ;
T_6 V_174 ;
int V_123 = 0 ;
char V_94 [ 30 * 3 + 4 ] ;
char * V_95 = V_94 ;
int V_96 = ( sizeof( V_94 ) - 1 ) / 3 - 1 ;
int V_175 = 0 ;
struct V_45 * V_46 = & V_3 -> V_46 [ V_169 ] ;
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x81 | ( V_169 << 5 ) ;
V_60 -> V_64 = ( V_138 << 6 ) | ( V_167 << 2 )
| ( V_64 << 0 ) ;
V_60 -> V_65 = F_96 ( V_110 -> V_5 , V_110 -> V_170 ,
F_97 ( V_110 -> V_170 ) ) ;
V_60 -> V_66 = F_104 ( T_7 , 1024 ,
V_110 -> V_115 -
V_110 -> V_173 ) ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = V_110 -> V_116 +
V_110 -> V_173 ;
V_60 -> V_63 = 0x8000 | ( V_60 -> V_66 - 1 ) ;
V_121 = V_60 -> V_67 ;
V_174 = V_60 -> V_66 ;
V_94 [ 0 ] = 0 ;
while ( V_174 -- > 0 ) {
if ( V_123 > V_96 ) {
} else if ( V_123 ++ < V_96 ) {
int V_176 = sprintf ( V_95 , L_15 , * V_121 ++ ) ;
V_95 += V_176 ;
V_175 += V_176 ;
} else
V_95 += sprintf ( V_95 , L_16 ) ;
}
V_46 -> F_80 = F_80 ;
V_46 -> V_141 = V_141 ;
V_46 -> V_110 = V_110 ;
V_46 -> V_47 = 1 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_105 ( struct V_15 * V_16 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_103 ( V_3 , V_44 , V_141 , V_110 , V_64 ,
V_167 , V_138 , F_80 ) ;
}
static int F_106 ( struct V_2 * V_3 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
T_5 V_169 = V_44 - 1 ;
V_69: if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else {
int V_55 ;
F_5 ( & V_3 -> V_35 ) ;
V_55 = V_3 -> V_56 - V_3 -> V_57 ;
if ( V_55 < V_58 ) {
T_7 V_172 = V_110 -> V_115 -
V_110 -> V_173 ;
struct V_45 * V_46 = & V_3 -> V_46 [ V_169 ] ;
struct V_59 * V_60 = & V_3 -> V_60 [
V_61 & V_3 -> V_56 ] ;
V_60 -> V_62 = 0x83 | ( V_169 << 5 ) ;
if ( V_172 == 0 ) {
V_60 -> V_63 = 0x0000 ;
} else if ( V_172 > 1024 ) {
V_60 -> V_63 = 0x8000 | 1023 ;
} else
V_60 -> V_63 = 0x8000 | ( V_172 -
1 ) ;
V_60 -> V_64 = ( V_138 << 6 ) | ( V_167 << 2 )
| ( V_64 << 0 ) ;
V_60 -> V_65 = F_96 ( V_110 -> V_5 , V_110 -> V_170 ,
F_97 ( V_110 -> V_170 ) ) ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = NULL ;
V_46 -> F_80 = F_80 ;
V_46 -> V_141 = V_141 ;
V_46 -> V_110 = V_110 ;
V_46 -> V_47 = 1 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
goto V_69;
}
}
}
int F_107 ( struct V_15 * V_16 , T_5 V_44 ,
void * V_141 , struct V_110 * V_110 , T_5 V_64 , T_5 V_167 , T_5 V_138 ,
void (* F_80) ( void * V_141 , struct V_110 * V_110 , T_5 * V_118 , int V_168 ,
int V_138 , int V_139 , int V_48 , int V_140 ,
int V_134 , int V_135 , int V_136 , int V_137 ) )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_106 ( V_3 , V_44 , V_141 , V_110 , V_64 ,
V_167 , V_138 , F_80 ) ;
}
static int F_108 ( struct V_2 * V_3 , T_5 V_44 ,
void * V_141 )
{
T_5 V_169 = V_44 - 1 ;
if ( V_3 -> V_6 > 0 ) {
return - V_73 ;
} else if ( V_3 -> V_80 == 0 ) {
return - V_73 ;
} else {
struct V_45 * V_46 = & V_3 -> V_46 [ V_169 ] ;
F_5 ( & V_3 -> V_35 ) ;
if ( V_46 -> V_53 > 0 ) {
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
} else {
V_46 -> V_53 = 1 ;
V_54: if ( V_46 -> V_47 == 1 ) {
int V_55 = V_3 -> V_56 -
V_3 -> V_57 ;
if ( V_55 < V_58 ) {
struct V_59 * V_60 =
& V_3 -> V_60 [ V_61 &
V_3 -> V_56 ] ;
V_60 -> V_62 = 0x80 | ( V_169 << 5 ) |
0x4 ;
V_60 -> V_63 = 0x00 ;
V_60 -> V_64 = 0x00 ;
V_60 -> V_65 = 0x00 ;
V_60 -> V_66 = 0 ;
V_60 -> V_42 = 0 ;
V_60 -> V_67 = & V_60 -> V_42 ;
V_3 -> V_56 += 1 ;
F_39 ( V_3 ) ;
} else {
F_7 ( & V_3 -> V_35 ) ;
F_40 ( 100 ) ;
F_5 ( & V_3 -> V_35 ) ;
goto V_54;
}
}
F_7 ( & V_3 -> V_35 ) ;
return 0 ;
}
}
}
int F_109 ( struct V_15 * V_16 , T_5 V_44 ,
void * V_141 )
{
struct V_2 * V_3 = F_27 ( V_16 ) ;
return F_108 ( V_3 , V_44 , V_141 ) ;
}
static int F_110 ( struct V_2 * V_3 )
{
int V_98 = 10 ;
int V_99 = 5 ;
int V_177 = 20 ;
V_105: {
int V_106 = 0 ;
int V_72 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_107 ) ,
V_3 -> V_10 , V_3 -> V_108 ,
& V_106 , 100 ) ;
if ( V_106 > 2 ) {
char V_131 [ 30 * 3 + 4 ] ;
char * V_95 = V_131 ;
int V_96 = ( sizeof( V_131 ) - 1 ) / 3 - 1 ;
char * V_121 = V_3 -> V_10 ;
int V_97 = 0 ;
V_131 [ 0 ] = 0 ;
while ( V_106 -- > 0 ) {
char V_132 = * V_121 ++ ;
if ( V_97 < V_96 ) {
V_95 += sprintf ( V_95 , L_15 ,
0x000000FF & V_132 ) ;
} else if ( V_97 > V_96 ) {
} else
V_95 += sprintf ( V_95 , L_16 ) ;
V_97 += 1 ;
continue;
}
goto V_105;
} else if ( V_106 > 1 ) {
char V_149 = V_3 -> V_10 [ 0 ] ;
char V_178 = V_3 -> V_10 [ 1 ] ;
if ( V_149 == 0x31 && V_178 == 0x60 ) {
return 0 ;
} else if ( V_177 -- > 0 ) {
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_25 ) ;
return - V_104 ;
}
} else if ( V_106 > 0 ) {
char V_179 = V_3 -> V_10 [ 0 ] ;
F_45 ( & V_3 -> V_4 -> V_5 , L_26 ,
V_179 ) ;
if ( V_177 -- > 0 ) {
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_25 ) ;
return - V_104 ;
}
} else if ( V_72 == - V_109 ) {
if ( V_99 -- > 0 ) {
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_27 ) ;
return - V_127 ;
}
} else if ( V_72 == 0 ) {
if ( V_98 -- > 0 ) {
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_28 ) ;
return - V_127 ;
}
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_29 , V_72 ) ;
return V_72 ;
}
}
return - 1 ;
}
static int F_111 ( struct V_2 * V_3 )
{
int V_72 ;
struct V_110 * V_110 ;
char * V_118 ;
int V_122 = 257 ;
int V_123 = 0 ;
V_110 = F_74 ( 0 , V_126 ) ;
if ( ! V_110 )
return - V_127 ;
V_118 = F_75 ( V_3 -> V_4 , V_122 , V_126 , & V_110 -> V_117 ) ;
if ( ! V_118 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_30 ) ;
F_76 ( V_110 ) ;
return - V_127 ;
}
while ( V_122 -- > 0 )
V_118 [ V_123 ++ ] = 0x55 ;
F_77 ( V_110 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_128 ) , V_118 , V_123 ,
F_70 , V_3 ) ;
V_110 -> V_129 |= V_130 ;
V_72 = F_79 ( V_110 , V_126 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_31 ) ;
F_71 ( V_3 -> V_4 , V_123 , V_118 , V_110 -> V_117 ) ;
F_76 ( V_110 ) ;
return - V_127 ;
}
F_76 ( V_110 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
int V_72 ;
struct V_110 * V_110 ;
char * V_118 ;
int V_122 = 4 ;
int V_123 = 0 ;
V_110 = F_74 ( 0 , V_126 ) ;
if ( ! V_110 )
return - V_127 ;
V_118 = F_75 ( V_3 -> V_4 , V_122 , V_126 , & V_110 -> V_117 ) ;
if ( ! V_118 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_32 ) ;
F_76 ( V_110 ) ;
return - V_127 ;
}
V_118 [ V_123 ++ ] = 0x55 ;
V_118 [ V_123 ++ ] = 0xAA ;
V_118 [ V_123 ++ ] = 0x5A ;
V_118 [ V_123 ++ ] = 0xA5 ;
F_77 ( V_110 , V_3 -> V_4 , F_78 ( V_3 -> V_4 ,
V_3 -> V_128 ) , V_118 , V_123 ,
F_70 , V_3 ) ;
V_110 -> V_129 |= V_130 ;
V_72 = F_79 ( V_110 , V_126 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_33 ) ;
F_71 ( V_3 -> V_4 , V_123 , V_118 , V_110 -> V_117 ) ;
F_76 ( V_110 ) ;
return - V_127 ;
}
F_76 ( V_110 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_72 ;
int V_180 = 10 ;
int V_99 = 5 ;
int V_98 = 10 ;
int V_181 = 0 ;
V_72 = F_110 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_3 -> V_101 = 0 ;
V_3 -> V_103 = - 1 ;
while ( V_180 -- > 0 ) {
int V_182 ;
int V_183 ;
V_72 = F_111 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_110 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_25: V_72 = F_112 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_182 = 100 ;
V_183 = 10 ;
V_147: {
int V_106 = 0 ;
V_72 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 ,
V_3 -> V_107 ) ,
V_3 -> V_10 , V_3 -> V_108 ,
& V_106 , 500 ) ;
if ( V_106 > 2 ) {
char V_131 [ 30 * 3 + 4 ] ;
char * V_95 = V_131 ;
int V_96 = ( sizeof( V_131 ) - 1 ) / 3 - 1 ;
char * V_121 = V_3 -> V_10 ;
int V_97 = 0 ;
unsigned char V_132 = 0 ;
V_131 [ 0 ] = 0 ;
while ( V_106 -- > 0 ) {
V_132 = * V_121 ++ ;
if ( V_97 < V_96 ) {
V_95 += sprintf ( V_95 , L_15 , V_132 ) ;
} else if ( V_97 > V_96 ) {
} else
V_95 += sprintf ( V_95 , L_16 ) ;
V_97 += 1 ;
continue;
}
if ( V_132 == 0x7E ) {
return 0 ;
} else {
if ( V_132 == 0x55 ) {
goto V_147;
} else if ( V_182 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_34 ) ;
continue;
}
}
} else if ( V_106 > 1 ) {
unsigned char V_149 = V_3 -> V_10 [ 0 ] ;
unsigned char V_178 = V_3 -> V_10 [ 1 ] ;
if ( V_149 == 0x31 && V_178 == 0x00 ) {
if ( V_183 -- > 0 ) {
goto V_147;
} else
goto V_25;
} else if ( V_149 == 0x31 && V_178 == 0x60 ) {
if ( V_182 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_34 ) ;
continue;
}
} else {
if ( V_182 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_34 ) ;
continue;
}
}
} else if ( V_106 > 0 ) {
if ( V_182 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_34 ) ;
continue;
}
} else if ( V_72 == - V_109 ) {
if ( V_99 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_27 ) ;
continue;
}
} else if ( V_72 == 0 ) {
if ( V_98 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_28 ) ;
continue;
}
} else {
V_181 += 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_29 ,
V_72 ) ;
if ( V_182 -- > 0 ) {
goto V_147;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_34 ) ;
continue;
}
}
}
}
F_45 ( & V_3 -> V_4 -> V_5 , L_35 ) ;
return - V_104 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_98 = 10 ;
int V_99 = 5 ;
int V_177 = 50 ;
V_105: {
int V_106 = 0 ;
int V_72 = F_68 ( V_3 -> V_4 ,
F_69 ( V_3 -> V_4 , V_3 -> V_107 ) ,
V_3 -> V_10 , V_3 -> V_108 ,
& V_106 , 1000 ) ;
if ( V_106 > 2 ) {
char V_131 [ 30 * 3 + 4 ] ;
char * V_95 = V_131 ;
int V_96 = ( sizeof( V_131 ) - 1 ) / 3 - 1 ;
char * V_121 = V_3 -> V_10 ;
int V_97 = 0 ;
V_131 [ 0 ] = 0 ;
while ( V_106 -- > 0 ) {
char V_132 = * V_121 ++ ;
if ( V_97 < V_96 ) {
V_95 += sprintf ( V_95 , L_15 ,
0x000000FF & V_132 ) ;
} else if ( V_97 > V_96 ) {
} else
V_95 += sprintf ( V_95 , L_16 ) ;
V_97 += 1 ;
continue;
}
goto V_105;
} else if ( V_106 > 1 ) {
char V_149 = V_3 -> V_10 [ 0 ] ;
char V_178 = V_3 -> V_10 [ 1 ] ;
if ( V_149 == 0x31 && V_178 == 0x60 ) {
return 0 ;
} else if ( V_177 -- > 0 ) {
F_40 ( 5 ) ;
goto V_105;
} else
return - V_104 ;
} else if ( V_106 > 0 ) {
char V_179 = V_3 -> V_10 [ 0 ] ;
F_45 ( & V_3 -> V_4 -> V_5 , L_26 , V_179 ) ;
if ( V_177 -- > 0 ) {
F_40 ( 5 ) ;
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_25 ) ;
return - V_104 ;
}
} else if ( V_72 == - V_109 ) {
if ( V_99 -- > 0 ) {
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_27 ) ;
return - V_127 ;
}
} else if ( V_72 == 0 ) {
if ( V_98 -- > 0 ) {
goto V_105;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_28 ) ;
return - V_127 ;
}
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_29 , V_72 ) ;
return - V_127 ;
}
}
return - 1 ;
}
static int F_57 ( struct V_2 * V_3 )
{
int V_184 = F_89 ( V_3 , & V_3 -> V_82 ) ;
if ( V_184 )
return V_184 ;
if ( V_3 -> V_82 & 0x00400000 ) {
if ( V_3 -> V_83 ) {
} else {
V_3 -> V_83 = 1 ;
F_45 ( & V_3 -> V_4 -> V_5 , L_36 ,
V_3 -> V_82 ) ;
}
return - V_73 ;
} else {
T_5 V_185 = V_3 -> V_186 - 1 ;
int V_187 = V_185 << 8 ;
T_7 V_188 ;
T_7 V_189 ;
T_7 V_190 ;
int V_191 = 0 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_189 = V_188 & 0xFFFF ;
V_190 = ( V_188 >> 16 ) & 0xFFFF ;
if ( V_189 == V_3 -> V_23 . V_192 && V_190 ==
V_3 -> V_23 . V_18 ) {
return 0 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 , L_37 ,
V_3 -> V_23 . V_192 , V_189 ,
V_3 -> V_23 . V_18 , V_190 ) ;
return - V_73 ;
}
}
}
static int F_113 ( struct V_2 * V_3 , int V_193 )
{
int V_194 = 0 ;
int V_72 ;
T_7 V_195 ;
int V_196 ;
T_7 V_197 ;
T_7 V_198 = - 1 ;
T_7 V_112 ;
T_7 V_199 ;
T_7 V_200 ;
T_7 V_201 ;
T_7 V_202 ;
T_7 V_203 ;
int V_204 = V_205 ;
int V_206 = 0 ;
int V_207 = 30 ;
int V_208 ;
V_72 = F_114 ( V_3 , V_209 , V_210 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_197 , & V_197 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_211 . V_212 , & V_198 ) ;
if ( V_72 )
return V_72 ;
V_196 = V_198 & V_213 ;
V_72 = F_115 ( V_3 , V_199 , & V_200 ) ;
if ( V_72 )
return V_72 ;
V_200 &= 0x3fff ;
if ( V_200 != V_214 ) {
}
V_200 |= F_116 ( V_200 ) << 16 ;
V_72 = F_115 ( V_3 , V_197 , & V_195 ) ;
if ( V_72 )
return V_72 ;
switch ( V_195 & V_215 ) {
case V_216 :
V_206 = 0 ;
break;
case V_217 :
case V_218 :
V_195 &= V_219 ;
V_195 |= V_218 ;
V_206 = 10 ;
break;
default:
V_195 &= V_219 ;
V_195 |= V_220 ;
V_206 = 50 ;
break;
}
V_72 = F_114 ( V_3 , V_197 , V_195 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_197 , & V_197 ) ;
if ( V_72 )
return V_72 ;
F_40 ( V_206 ) ;
V_72 = F_115 ( V_3 , V_211 . V_212 , & V_203 ) ;
if ( V_72 )
return V_72 ;
if ( ! ( V_203 & V_221 ) ) {
for ( V_208 = 0 ; V_208 < V_196 ; V_208 ++ ) {
V_72 = F_114 ( V_3 ,
V_211 . V_222 [ V_208 ] , V_223 ) ;
if ( V_72 )
return V_72 ;
}
}
V_72 = F_115 ( V_3 , V_197 , & V_197 ) ;
if ( V_72 )
return V_72 ;
V_224: V_72 = F_115 ( V_3 , V_202 , & V_112 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_202 , V_225 ) ;
if ( V_72 )
return V_72 ;
V_226: {
V_72 = F_115 ( V_3 , V_202 , & V_112 ) ;
if ( V_72 )
return V_72 ;
if ( 0 != ( V_112 & V_225 ) ) {
if ( -- V_207 == 0 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_38 ) ;
return - V_73 ;
} else {
F_40 ( 5 ) ;
goto V_226;
}
}
}
if ( V_193 & V_227 ) {
V_72 = F_114 ( V_3 , V_197 , V_195 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_197 , & V_197 ) ;
if ( V_72 )
return V_72 ;
}
V_72 = F_114 ( V_3 , V_228 , 0x00000000 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_229 , 0x11000000 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_230 , 0x00000000 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_199 , & V_199 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_199 ,
( ( V_199 & V_231 ) ^ V_231 ) | V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_201 ,
( ( 9 * V_200 ) / 10 ) & 0x3fff ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_199 , & V_199 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_201 , & V_201 ) ;
if ( V_72 )
return V_72 ;
if ( 0 == ( V_199 & 0x3fff0000 ) || 0 == V_201 ) {
if ( ! ( V_193 & V_227 ) ) {
V_193 |= V_227 ;
goto V_224;
} else
F_45 ( & V_3 -> V_4 -> V_5 , L_39 ,
V_199 , V_201 ) ;
}
V_195 &= V_219 ;
V_195 |= V_232 | V_233 | V_216 ;
V_72 = F_114 ( V_3 , V_197 , V_195 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_202 , V_234 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_202 , & V_202 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_197 , & V_197 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_211 . V_112 , V_235 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_236 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_209 ,
V_210 | V_237 | V_238 | V_239 |
V_240 | V_241 | V_242 | V_243 |
V_244 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_211 . V_212 , & V_203 ) ;
if ( V_72 )
return V_72 ;
V_203 &= ~ ( V_245 | V_246 ) ;
if ( V_193 & V_247 ) {
V_203 |= V_248 ;
V_203 &= ~ ( V_249 | V_221 ) ;
V_72 = F_114 ( V_3 , V_211 . V_212 , V_203 ) ;
if ( V_72 )
return V_72 ;
} else if ( ( V_193 & V_250 ) || V_251 ) {
V_203 |= V_221 ;
V_72 = F_114 ( V_3 , V_211 . V_212 , V_203 ) ;
if ( V_72 )
return V_72 ;
}
V_72 = F_114 ( V_3 , V_211 . V_112 , V_252 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_114 ( V_3 , V_211 . V_121 ,
( V_203 & V_221 ) ? 0 : V_253 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_115 ( V_3 , V_197 , & V_197 ) ;
if ( V_72 )
return V_72 ;
F_117 ( ( V_203 >> 23 ) & 0x1fe ) ;
for ( V_208 = 0 ; V_208 < V_196 ; V_208 ++ ) {
T_7 V_222 ;
V_72 = F_115 ( V_3 , V_211 . V_222 [ V_208 ] ,
& V_222 ) ;
if ( V_72 )
return V_72 ;
if ( 1 & V_222 )
V_194 += 1 ;
}
return V_194 ;
}
static int F_118 ( struct V_2 * V_3 , int V_185 )
{
T_7 V_254 ;
int V_184 ;
T_7 V_188 ;
int V_191 = 0 ;
int V_187 = V_185 << 8 ;
V_184 = F_85 ( V_3 , 0x0000025FL | 0x2800 ) ;
if ( V_184 )
return V_184 ;
V_191 = 16 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0 ,
0xFFFFFFFF ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0 ,
0xF0000000 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_191 = 12 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_254 ) ;
if ( V_184 )
return V_184 ;
V_254 &= 0xFFFF00FF ;
V_254 |= 0x00001600 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0x00 ,
V_254 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_191 = 4 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0x00 ,
0x06 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
for ( V_191 = 0 ; V_191 <= 0x54 ; V_191 += 4 ) {
V_184 = F_93 ( V_3 , V_191 , 0 , & V_188 ) ;
if ( V_184 )
return V_184 ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 , int V_185 )
{
T_7 V_254 ;
int V_184 ;
T_7 V_188 ;
int V_191 = 0 ;
int V_187 = V_185 << 8 ;
V_184 = F_85 ( V_3 , 0x0000025FL | 0x2800 ) ;
if ( V_184 )
return V_184 ;
V_191 = 16 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0 ,
0xFFFFFFFF ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0 ,
0x00000000 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_191 = 12 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_254 ) ;
if ( V_184 )
return V_184 ;
V_254 &= 0xFFFF00FF ;
V_254 |= 0x00001600 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0x00 ,
V_254 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_191 = 4 ;
V_184 = F_86 ( V_3 , V_187 | V_191 , 0x00 ,
0x00 ) ;
if ( V_184 )
return V_184 ;
return F_92 ( V_3 , V_187 | V_191 , 0 , & V_188 ) ;
}
static int F_120 ( struct V_2 * V_3 , int V_185 , int V_193 )
{
int V_20 ;
int V_184 ;
V_184 = F_118 ( V_3 , V_185 ) ;
if ( V_184 )
return V_184 ;
V_20 = F_113 ( V_3 , V_193 ) ;
V_184 = F_119 ( V_3 , V_185 ) ;
if ( V_184 )
return V_184 ;
return V_20 ;
}
static int F_55 ( struct V_2 * V_3 )
{
T_7 V_82 ;
T_5 V_255 ;
int V_184 ;
V_184 = F_89 ( V_3 , & V_82 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_85 ( V_3 , 0x00000000L ) ;
if ( V_184 )
return V_184 ;
F_40 ( 750 ) ;
V_184 = F_85 ( V_3 , 0x00000200L | 0x100 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_85 ( V_3 , 0x00000200L | 0x500 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_89 ( V_3 , & V_82 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_85 ( V_3 , 0x0000020CL | 0x000 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_85 ( V_3 , 0x0000020DL | 0x000 ) ;
if ( V_184 )
return V_184 ;
F_40 ( 250 ) ;
V_184 = F_85 ( V_3 , 0x0000020FL | 0x000 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_89 ( V_3 , & V_82 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_85 ( V_3 , 0x0000025FL | 0x800 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_89 ( V_3 , & V_82 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_89 ( V_3 , & V_82 ) ;
if ( V_184 )
return V_184 ;
F_40 ( 1000 ) ;
V_255 = ( V_82 >> 16 ) & 0x000F ;
if ( 0x0D == V_255 )
return 0 ;
else
return - V_256 ;
}
static int F_56 ( struct V_2 * V_3 )
{
int V_184 ;
T_7 V_188 ;
int V_191 = 0 ;
T_5 V_185 ;
int V_187 = 0 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_259 = 0 ;
V_3 -> V_186 = 0 ;
for ( V_185 = 0 ; ( V_185 < 4 ) ; V_185 ++ ) {
T_7 V_189 = 0 ;
T_7 V_190 = 0 ;
int V_194 = 0 ;
V_187 = V_185 << 8 ;
V_184 = F_92 ( V_3 , V_187 | V_191 , 0 ,
& V_188 ) ;
if ( V_184 )
return V_184 ;
V_189 = V_188 & 0xFFFF ;
V_190 = ( V_188 >> 16 ) & 0xFFFF ;
if ( ( V_189 == V_260 ) && ( V_190 == 0xc861 ) ) {
V_194 = F_120 ( V_3 , V_185 , 0 ) ;
V_258 += 1 ;
} else if ( ( V_189 == V_261 ) && ( V_190 == 0x0035 ) )
{
V_194 = F_120 ( V_3 , V_185 , 0 ) ;
V_258 += 1 ;
} else if ( ( V_189 == V_262 ) && ( V_190 == 0x5237 ) ) {
V_194 = F_120 ( V_3 , V_185 , 0 ) ;
V_258 += 1 ;
} else if ( ( V_189 == V_263 ) && ( V_190 == 0x5802 ) )
{
V_194 = F_120 ( V_3 , V_185 , 0 ) ;
V_258 += 1 ;
} else if ( V_189 == V_264 && V_190 == 0x740c ) {
V_194 = F_120 ( V_3 , V_185 ,
V_250 ) ;
V_258 += 1 ;
} else if ( V_189 == V_265 && V_190 == 0xa0f8 ) {
V_194 = F_120 ( V_3 , V_185 ,
V_266 ) ;
V_258 += 1 ;
} else if ( 0 == V_188 ) {
} else
V_259 += 1 ;
if ( V_194 > V_257 ) {
V_257 = V_194 ;
V_3 -> V_186 = V_185 + 1 ;
V_3 -> V_23 . V_192 = V_189 ;
V_3 -> V_23 . V_18 = V_190 ;
}
}
if ( V_3 -> V_186 > 0 ) {
return F_118 ( V_3 , V_3 -> V_186 - 1 ) ;
} else if ( V_258 > 0 ) {
return - V_256 ;
} else if ( V_259 > 0 ) {
return - V_256 ;
} else {
V_3 -> V_79 = 0 ;
return - V_256 ;
}
}
static int F_121 ( struct V_87 * V_88 ,
const struct V_267 * V_26 )
{
struct V_268 * V_269 ;
struct V_270 * V_271 ;
T_3 V_272 ;
int V_123 ;
int V_72 = - V_127 ;
struct V_2 * V_3 ;
V_3 = F_122 ( sizeof( struct V_2 ) , V_126 ) ;
if ( ! V_3 )
return - V_127 ;
F_5 ( & V_7 ) ;
F_123 ( & V_3 -> V_8 , & V_273 ) ;
V_3 -> V_27 = ++ V_9 ;
F_7 ( & V_7 ) ;
F_13 ( V_3 ) ;
F_124 ( & V_3 -> V_77 , 1 ) ;
V_3 -> V_4 = F_125 ( F_126 ( V_88 ) ) ;
V_3 -> V_88 = V_88 ;
F_127 ( & V_3 -> V_35 ) ;
V_3 -> V_51 = 4 ;
V_269 = V_88 -> V_274 ;
for ( V_123 = 0 ; V_123 < V_269 -> V_275 . V_276 ; ++ V_123 ) {
V_271 = & V_269 -> V_271 [ V_123 ] . V_275 ;
if ( ! V_3 -> V_107 &&
F_128 ( V_271 ) ) {
V_272 = F_129 ( V_271 ) ;
V_3 -> V_108 = V_272 ;
V_3 -> V_107 = V_271 -> V_277 ;
V_3 -> V_10 = F_130 ( V_272 , V_126 ) ;
if ( ! V_3 -> V_10 ) {
V_72 = - V_127 ;
goto error;
}
}
if ( ! V_3 -> V_128 &&
F_131 ( V_271 ) ) {
V_3 -> V_128 =
V_271 -> V_277 ;
}
}
if ( ! ( V_3 -> V_107 && V_3 -> V_128 ) ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_40 ) ;
V_72 = - V_73 ;
goto error;
}
F_31 ( & V_3 -> V_4 -> V_5 , L_41 ,
V_269 -> V_275 . V_278 , V_3 -> V_107 ,
V_3 -> V_128 ) ;
F_132 ( V_88 , V_3 ) ;
if ( V_269 -> V_275 . V_278 == 0 &&
V_3 -> V_107 == 0x81 &&
V_3 -> V_128 == 0x02 ) {
V_72 = F_133 ( V_88 , & V_279 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_4 -> V_5 , L_42 ) ;
F_132 ( V_88 , NULL ) ;
V_72 = - V_127 ;
goto error;
} else {
V_3 -> V_280 = & V_279 ;
F_31 ( & V_3 -> V_4 -> V_5 , L_43 ,
V_3 , V_269 -> V_275 . V_278 ,
V_88 -> V_281 ) ;
return 0 ;
}
} else if ( V_269 -> V_275 . V_278 == 1 &&
V_3 -> V_107 == 0x83 &&
V_3 -> V_128 == 0x04 ) {
V_3 -> V_280 = NULL ;
F_31 ( & V_3 -> V_4 -> V_5 , L_44 ,
V_3 , V_269 -> V_275 . V_278 ) ;
F_134 ( & V_3 -> V_12 , F_50 ) ;
F_134 ( & V_3 -> V_13 , F_42 ) ;
F_134 ( & V_3 -> V_14 , F_48 ) ;
F_17 ( V_3 , F_46 ( 3 * 1000 ) ) ;
return 0 ;
} else {
F_45 ( & V_3 -> V_4 -> V_5 ,
L_45 ) ;
V_72 = - V_73 ;
goto error;
}
error: if ( V_3 ) {
F_9 ( V_3 ) ;
}
return V_72 ;
}
static void F_135 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = F_63 ( V_88 ) ;
V_3 -> V_6 += 1 ;
if ( V_3 -> V_280 ) {
int V_281 = V_88 -> V_281 ;
struct V_282 * V_280 = V_3 -> V_280 ;
F_132 ( V_88 , NULL ) ;
F_136 ( V_88 , V_280 ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_46 ,
V_281 ) ;
} else {
F_18 ( V_3 ) ;
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
F_34 ( V_3 ) ;
F_36 ( V_3 ) ;
if ( V_3 -> V_81 ) {
F_58 ( & V_3 -> V_21 ) ;
V_3 -> V_76 = 0 ;
V_3 -> V_79 = 0 ;
V_3 -> V_80 = 0 ;
V_3 -> V_81 = 0 ;
}
V_3 -> V_6 += 1 ;
F_132 ( V_88 , NULL ) ;
F_31 ( & V_3 -> V_4 -> V_5 , L_47 ) ;
}
F_9 ( V_3 ) ;
}
static int T_8 F_137 ( void )
{
int V_20 ;
F_138 ( L_48 , V_89 . V_34 ) ;
F_127 ( & V_7 ) ;
F_139 ( & V_273 ) ;
V_20 = F_140 ( & V_89 ) ;
if ( V_20 ) {
F_62 ( L_49 , V_20 ) ;
}
return V_20 ;
}
static void T_9 F_141 ( void )
{
struct V_2 * V_3 ;
struct V_2 * V_208 ;
F_142 ( & V_89 ) ;
F_138 ( L_50 ) ;
F_143 (ftdi, temp, &ftdi_static_list, ftdi_list) {
F_18 ( V_3 ) ;
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
}
}
