static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_4 = V_2 -> V_5 -> V_6 ;
if ( V_2 -> V_7 + V_2 -> V_8 <
V_4
&& V_2 -> V_7 < V_4 - 1 ) {
V_3 = 0 ;
} else {
F_2 ( V_2 -> V_9 ,
L_1
L_2 , V_10 , V_4 ,
V_2 -> V_7 , V_2 -> V_8 ) ;
V_3 = - V_11 ;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_3 ;
T_1 V_14 ;
V_3 = 0 ;
if ( V_13 -> V_15 == V_16 || V_13 -> V_17 ) {
V_14 = 100 - V_13 -> V_18 ;
} else {
V_14 = 900 - V_13 -> V_18 ;
}
if ( V_2 -> V_19 > V_14 ) {
F_4 ( V_2 -> V_9 ,
L_3 ,
V_10 , V_2 -> V_19 , V_13 -> V_18 ) ;
V_3 = - V_11 ;
}
return V_3 ;
}
static int F_5 ( unsigned long * V_20 , int V_21 ,
int V_22 , int V_23 ,
int V_24 , int V_25 , bool V_26 )
{
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
if ( V_23 > V_21 )
return - V_11 ;
V_24 = F_6 ( V_24 , V_22 ) ;
V_27 = V_21 * V_24 ;
V_28 = V_22 / V_24 ;
if ( V_25 >= V_27 )
return - V_11 ;
if ( V_26 )
V_29 = ( V_25 / V_21 + 1 ) * V_21 ;
else
V_29 = V_27 ;
while ( V_25 + V_23 <= V_29 ) {
int V_31 ;
V_31 = ( V_25 / V_21 + 1 ) * V_21 ;
V_25 = F_7 ( V_20 , V_31 , V_25 , V_23 ,
0 ) ;
if ( V_25 >= V_31 ) {
V_25 = V_31 ;
continue;
}
for ( V_30 = 1 ; V_30 < V_28 ; V_30 ++ ) {
int V_32 = V_25 + V_27 * V_30 ;
int V_33 = V_31 + V_27 * V_30 ;
int V_34 ;
V_34 = F_7 (
V_20 , V_32 + V_23 , V_32 , V_23 ,
0 ) ;
if ( V_34 == V_32 )
continue;
V_32 = F_7 (
V_20 , V_33 , V_32 , V_23 , 0 ) ;
if ( V_32 >= V_33 )
V_25 = V_31 ;
else
V_25 = V_32 - V_27 * V_30 ;
break;
}
if ( V_30 == V_28 )
break;
}
if ( V_25 + V_23 > V_29 )
return - V_11 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
int V_32 = V_25 + V_27 * V_30 ;
F_8 ( V_20 , V_32 , V_23 ) ;
}
return V_25 ;
}
static void F_9 ( unsigned long * V_20 , int V_21 ,
int V_22 , int V_23 ,
int V_24 , int V_25 )
{
int V_27 ;
int V_35 ;
int V_30 ;
V_24 = F_6 ( V_24 , V_22 ) ;
V_27 = V_21 * V_24 ;
V_35 = V_22 / V_24 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
int V_32 = V_25 + V_27 * V_30 ;
F_10 ( V_20 , V_32 , V_23 ) ;
}
}
void F_11 ( unsigned long * V_20 , int V_21 ,
int V_22 , const char * V_36 ,
const char * V_37 ,
void (* F_12)( const char * V_38 , void * V_39 ) ,
void * V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_22 ; V_41 ++ ) {
char V_42 [ 64 ] ;
char * V_43 = V_42 ;
T_2 V_44 = sizeof( V_42 ) ;
int V_45 = V_41 * V_21 ;
int V_46 = V_45 + V_21 ;
int V_25 = 0 ;
int V_47 = 0 ;
bool V_48 = false ;
int V_30 ;
for ( V_30 = V_45 ; V_30 < V_46 + 1 ; V_30 ++ ) {
if ( V_30 < V_46 &&
F_7 ( V_20 , V_30 + 1 ,
V_30 , 1 , 0 ) != V_30 ) {
if ( V_47 == 0 )
V_25 = V_30 - V_45 ;
V_47 ++ ;
continue;
}
if ( V_47 == 0 )
continue;
if ( ! V_48 )
F_13 ( & V_43 , & V_44 , L_4 ,
V_36 , V_41 ) ;
else
F_13 ( & V_43 , & V_44 , L_5 ) ;
V_48 = true ;
F_13 ( & V_43 , & V_44 , L_6 , V_25 ,
V_37 , V_25 + V_47 - 1 , V_37 ) ;
V_47 = 0 ;
}
if ( V_48 )
F_12 ( V_42 , V_40 ) ;
}
}
static unsigned long * F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long * V_20 ;
if ( F_15 ( ! V_13 -> V_49 ) )
return NULL ;
V_20 = V_13 -> V_49 -> V_50 ;
if ( V_13 -> V_49 -> V_51 -> V_52 )
V_20 += V_53 * V_13 -> V_54 ;
return V_20 ;
}
static void F_16 ( const char * V_38 , void * V_39 )
{
struct V_55 * V_40 = V_39 ;
F_17 ( V_40 -> V_2 , L_7 , V_40 -> V_13 , V_38 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_55 V_40 = { V_2 , V_13 } ;
int V_30 ;
#ifndef F_19
return;
#endif
if ( V_13 -> V_56 ) {
unsigned long * V_20 = F_14 ( V_2 , V_13 ) ;
F_17 ( V_2 , L_8 ,
V_13 , V_13 -> V_57 ,
F_20 ( V_13 -> V_57 ) ,
V_58 * V_13 -> V_59 ) ;
if ( V_20 ) {
F_17 ( V_2 ,
L_9 ,
V_13 , V_20 ) ;
F_11 ( V_20 , V_60 ,
V_61 , L_10 , L_11 ,
F_16 , & V_40 ) ;
}
}
for ( V_30 = 0 ; V_30 < V_13 -> V_62 ; V_30 ++ ) {
struct V_63 * V_64 = V_13 -> V_65 + V_30 ;
int V_66 = V_64 -> V_67 /
V_68 ;
int V_69 = V_64 -> V_67 %
V_68 ;
F_17 ( V_2 ,
L_12 ,
V_13 , V_30 , V_64 -> V_70 , V_66 , V_69 ) ;
}
if ( V_13 -> V_62 ) {
F_17 ( V_2 , L_13 , V_13 ) ;
F_11 ( V_2 -> V_71 ,
V_68 ,
V_72 , L_14 , L_15 ,
F_16 , & V_40 ) ;
}
}
static int F_21 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_73 )
{
int V_74 = F_22 ( V_13 -> V_57 , V_58 ) ;
unsigned long * V_20 = F_14 ( V_2 , V_13 ) ;
int V_75 ;
if ( V_20 == NULL )
return - V_76 ;
V_75 = F_5 ( V_20 , V_60 ,
V_61 , V_74 ,
V_13 -> V_77 , V_73 , false ) ;
if ( V_75 < 0 )
return V_75 ;
V_13 -> V_59 = V_75 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_74 = F_22 ( V_13 -> V_57 , V_58 ) ;
unsigned long * V_20 = F_14 ( V_2 , V_13 ) ;
if ( V_20 == NULL )
return;
F_9 ( V_20 , V_60 ,
V_61 , V_74 , V_13 -> V_77 ,
V_13 -> V_59 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool V_26 , int V_78 )
{
struct V_63 * V_64 = V_13 -> V_65 + V_78 ;
int V_79 ;
V_79 = F_5 ( V_2 -> V_71 ,
V_68 ,
V_72 , V_64 -> V_70 ,
V_13 -> V_80 , V_64 -> V_67 ,
V_26 ) ;
if ( V_79 < 0 )
return V_79 ;
V_64 -> V_67 = V_79 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_12 * V_13 , int V_78 )
{
struct V_63 * V_64 = V_13 -> V_65 + V_78 ;
F_9 ( V_2 -> V_71 ,
V_68 ,
V_72 , V_64 -> V_70 ,
V_13 -> V_80 , V_64 -> V_67 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_81 = F_27 ( V_13 -> V_82 ) * F_28 ( V_13 -> V_82 ) ;
int V_83 ;
int V_84 = 0 ;
int V_85 ;
V_85 = F_6 ( V_13 -> V_80 ,
V_72 ) ;
V_83 = 0 ;
while ( V_83 < V_86 ) {
int V_87 ;
int V_88 ;
int V_89 ;
int V_90 ;
int V_91 ;
int V_92 ;
int V_93 ;
int V_94 ;
int V_95 ;
int V_30 ;
if ( V_13 -> V_56 ) {
V_84 = F_21 ( V_2 , V_13 , V_83 ) ;
if ( V_84 )
return V_84 ;
} else {
F_29 ( 1 ) ;
}
V_87 = V_13 -> V_59 /
V_96 ;
V_90 = ( V_87 % 8 ) ;
if ( V_90 == 7 ) {
if ( V_13 -> V_56 )
F_23 ( V_2 , V_13 ) ;
V_83 =
( V_13 -> V_59 /
V_60 + 1 ) *
V_60 ;
continue;
}
V_88 = ( V_87 +
V_85 - 1 ) %
V_85 ;
if ( V_13 -> V_97 == V_98 && ! V_13 -> V_99 )
V_89 = V_87 ;
else
V_89 = V_87 + 1 ;
V_94 = 188 -
F_22 ( 188 * ( V_13 -> V_59 %
V_96 ) ,
V_96 ) ;
if ( V_94 > V_81 )
V_94 = V_81 ;
V_95 = V_81 - V_94 ;
if ( ! V_13 -> V_99 &&
( V_94 != F_30 ( int , 188 , V_81 ) ) ) {
F_17 ( V_2 ,
L_16 ,
V_13 , V_94 , V_81 ) ;
if ( V_13 -> V_56 )
F_23 ( V_2 , V_13 ) ;
V_83 = ( V_87 + 1 ) *
V_96 ;
continue;
}
V_13 -> V_62 = 1 + F_22 ( V_95 , 188 ) ;
if ( V_13 -> V_97 == V_100 ) {
if ( V_90 == 6 )
V_13 -> V_62 += 2 ;
else
V_13 -> V_62 += 3 ;
if ( V_13 -> V_99 ) {
V_91 = 4 ;
V_92 = V_81 ;
V_93 = V_81 ;
} else {
V_91 = V_94 ;
V_92 = F_31 ( int , 4 , V_95 ) ;
V_93 = 4 ;
}
} else {
if ( V_13 -> V_99 ) {
int V_101 ;
V_13 -> V_62 ++ ;
V_101 = V_90 + V_13 -> V_62 + 1 ;
if ( V_101 <= 6 )
V_13 -> V_62 += 2 ;
else
V_13 -> V_62 += 1 ;
if ( V_101 >= 6 && V_90 == 0 )
V_13 -> V_62 -- ;
V_91 = 4 ;
V_92 = F_30 ( int , 188 , V_81 ) ;
V_93 = V_92 ;
} else {
V_91 = V_94 ;
V_92 = F_30 ( int , 188 ,
V_95 ) ;
V_93 = V_95 % 188 ;
}
}
V_13 -> V_65 [ 0 ] . V_70 = F_32 ( V_91 ) ;
for ( V_30 = 1 ; V_30 < V_13 -> V_62 - 1 ; V_30 ++ )
V_13 -> V_65 [ V_30 ] . V_70 =
F_32 ( V_92 ) ;
if ( V_13 -> V_62 > 1 )
V_13 -> V_65 [ V_13 -> V_62 - 1 ] . V_70 =
F_32 ( V_93 ) ;
V_13 -> V_65 [ 0 ] . V_67 =
V_88 * V_68 ;
for ( V_30 = 1 ; V_30 < V_13 -> V_62 ; V_30 ++ )
V_13 -> V_65 [ V_30 ] . V_67 =
( ( V_89 + V_30 - 1 ) %
V_72 ) *
V_68 ;
for ( V_30 = 0 ; V_30 < V_13 -> V_62 ; V_30 ++ ) {
V_84 = F_24 ( V_2 , V_13 , true , V_30 ) ;
if ( V_84 )
break;
}
if ( V_30 == V_13 -> V_62 )
break;
for (; V_30 >= 0 ; V_30 -- )
F_25 ( V_2 , V_13 , V_30 ) ;
if ( V_13 -> V_56 )
F_23 ( V_2 , V_13 ) ;
V_83 = ( V_87 + 1 ) * V_96 ;
}
if ( V_83 >= V_86 )
return - V_11 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_15 ( V_13 -> V_18 != V_13 -> V_57 ) ;
F_15 ( V_13 -> V_80 != V_13 -> V_77 ) ;
F_15 ( V_13 -> V_62 != 1 ) ;
V_13 -> V_65 [ 0 ] . V_67 = 0 ;
V_13 -> V_65 [ 0 ] . V_70 = V_13 -> V_18 ;
return F_24 ( V_2 , V_13 , false , 0 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_15 ( V_13 -> V_18 != V_13 -> V_57 ) ;
F_15 ( V_13 -> V_80 != V_13 -> V_77 ) ;
F_15 ( ! V_13 -> V_56 ) ;
return F_21 ( V_2 , V_13 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_34 ;
if ( V_13 -> V_15 == V_16 )
V_34 = F_33 ( V_2 , V_13 ) ;
else if ( ! V_13 -> V_17 )
V_34 = F_34 ( V_2 , V_13 ) ;
else
V_34 = F_26 ( V_2 , V_13 ) ;
if ( V_34 )
F_17 ( V_2 , L_17 , V_13 , V_34 ) ;
else
F_18 ( V_2 , V_13 ) ;
return V_34 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_13 -> V_62 ; V_30 ++ )
F_25 ( V_2 , V_13 , V_30 ) ;
if ( V_13 -> V_56 )
F_23 ( V_2 , V_13 ) ;
F_17 ( V_2 , L_18 , V_13 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
T_3 V_102 ;
T_3 V_103 ;
T_3 V_104 ;
T_3 V_105 ;
T_3 V_24 ;
V_102 = F_38 ( V_2 ) ;
V_103 = F_39 ( V_102 , 1 ) ;
V_104 = V_103 ;
if ( V_2 -> V_5 -> V_106 <= 0 ) {
if ( V_13 -> V_17 )
V_104 |= 0x7 ;
goto exit;
}
if ( V_13 -> V_15 == V_16 || V_13 -> V_17 ) {
F_15 ( V_13 -> V_62 < 1 ) ;
V_105 = V_13 -> V_65 [ 0 ] . V_67 /
V_68 ;
V_24 = F_6 ( V_13 -> V_80 , V_72 ) ;
} else {
V_105 = V_13 -> V_59 /
V_60 ;
V_24 = F_6 ( V_13 -> V_80 , V_61 ) ;
}
F_15 ( V_105 >= V_24 ) ;
V_104 = ( V_104 / V_24 ) * V_24 ;
V_104 = F_39 ( V_104 ,
V_105 ) ;
V_104 = F_40 ( V_104 , 1 ) ;
while ( F_41 ( V_103 , V_104 ) )
V_104 = F_39 ( V_104 ,
V_24 ) ;
exit:
V_13 -> V_104 = V_104 ;
V_13 -> V_107 = V_104 ;
F_42 ( V_2 , L_19 ,
V_13 , V_102 , V_13 -> V_104 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_3 ;
if ( V_2 -> V_5 -> V_106 > 0 ) {
V_3 = F_35 ( V_2 , V_13 ) ;
} else {
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_44 ( V_2 -> V_9 ,
L_20 ,
V_10 ) ;
return V_3 ;
}
V_3 = F_3 ( V_2 , V_13 ) ;
}
if ( V_3 ) {
F_2 ( V_2 -> V_9 ,
L_21 ,
V_10 ) ;
return V_3 ;
}
if ( V_2 -> V_5 -> V_106 <= 0 )
V_2 -> V_7 ++ ;
V_2 -> V_19 += V_13 -> V_18 ;
F_37 ( V_2 , V_13 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_46 ( & V_2 -> V_108 ) ;
F_15 ( ! V_13 -> V_109 ) ;
V_13 -> V_109 = false ;
if ( F_15 ( ! F_47 ( & V_13 -> V_110 ) ) )
F_48 ( & V_13 -> V_110 ) ;
V_2 -> V_19 -= V_13 -> V_18 ;
if ( V_2 -> V_5 -> V_106 > 0 ) {
F_36 ( V_2 , V_13 ) ;
} else {
V_2 -> V_7 -- ;
}
}
static void F_49 ( unsigned long V_39 )
{
struct V_12 * V_13 = (struct V_12 * ) V_39 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_111 ;
while ( ! F_50 ( & V_2 -> V_108 , V_111 ) ) {
if ( F_51 ( & V_13 -> V_112 ) )
return;
}
if ( V_13 -> V_109 )
F_45 ( V_2 , V_13 ) ;
F_52 ( & V_2 -> V_108 , V_111 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
T_4 V_113 ;
T_4 V_114 ;
int V_3 = 0 ;
V_113 = F_28 ( V_13 -> V_82 ) * F_27 ( V_13 -> V_82 ) ;
V_114 = V_2 -> V_5 -> V_115 ;
if ( V_113 > V_114 ) {
F_4 ( V_2 -> V_9 ,
L_22 ,
V_10 , V_113 , V_114 ) ;
V_3 = - V_11 ;
}
return V_3 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_3 ;
V_3 = F_53 ( V_2 , V_13 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_9 ,
L_23 ,
V_10 ) ;
return V_3 ;
}
if ( F_55 ( & V_13 -> V_112 ) )
F_15 ( ! V_13 -> V_109 ) ;
if ( ! V_13 -> V_109 ) {
V_3 = F_43 ( V_2 , V_13 ) ;
if ( V_3 )
return V_3 ;
} else {
if ( F_56 ( V_13 -> V_104 ,
V_2 -> V_102 ) )
F_37 ( V_2 , V_13 ) ;
}
V_13 -> V_109 = 0 ;
if ( V_2 -> V_5 -> V_116 > 0 )
F_57 ( & V_13 -> V_110 , & V_2 -> V_117 ) ;
else
F_57 ( & V_13 -> V_110 ,
& V_2 -> V_118 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
bool V_119 ;
F_46 ( & V_2 -> V_108 ) ;
V_119 = F_59 ( & V_13 -> V_112 ,
V_120 + V_121 + 1 ) ;
F_15 ( V_119 ) ;
V_13 -> V_109 = 1 ;
F_48 ( & V_13 -> V_110 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_122 * V_123 , T_5 V_124 )
{
int V_15 = F_61 ( V_2 , V_123 -> V_125 ) ;
T_6 V_97 = F_62 ( & V_123 -> V_126 ) ;
bool V_99 = ! ! F_63 ( & V_123 -> V_126 ) ;
bool V_127 = ( V_97 == V_98 ) ;
bool V_128 = ( V_97 == V_100 ) ;
T_4 V_129 = F_64 ( V_2 -> V_130 + V_131 ) ;
T_4 V_132 = ( V_129 & V_133 ) >> V_134 ;
bool V_17 = ( V_132 == V_135 &&
V_15 != V_16 ) ;
int V_82 = F_65 ( & V_123 -> V_126 ) ;
int V_81 = F_27 ( V_82 ) * F_28 ( V_82 ) ;
char * V_136 , * type ;
V_13 -> V_2 = V_2 ;
F_66 ( & V_13 -> V_112 , F_49 ,
( unsigned long ) V_13 ) ;
V_13 -> V_97 = V_97 ;
V_13 -> V_99 = V_99 ;
V_13 -> V_137 = V_138 ;
V_13 -> V_82 = V_82 ;
F_67 ( & V_13 -> V_139 ) ;
F_67 ( & V_13 -> V_110 ) ;
V_13 -> V_17 = V_17 ;
V_13 -> V_15 = V_15 ;
if ( V_128 || V_127 ) {
int V_140 = V_17 ? V_16 : V_15 ;
struct V_141 * V_49 = F_68 ( V_2 , V_123 -> V_125 ,
V_124 ,
& V_13 -> V_54 ) ;
int V_142 ;
V_13 -> V_49 = V_49 ;
V_13 -> V_18 = F_69 ( F_70 ( V_140 , V_99 ,
V_127 , V_81 ) ) ;
V_142 = F_70 ( V_15 , V_99 ,
V_127 , V_81 ) ;
if ( V_17 && V_49 )
V_142 += V_49 -> V_51 -> V_143 ;
V_13 -> V_57 = F_69 ( V_142 ) ;
V_13 -> V_77 = V_123 -> V_24 ;
V_13 -> V_80 = V_123 -> V_24 * ( V_17 ? 8 : 1 ) ;
V_13 -> V_56 = V_132 != V_135 ||
V_49 ;
if ( V_17 ) {
V_13 -> V_62 = - 1 ;
} else if ( V_15 == V_16 ) {
V_13 -> V_62 = 1 ;
} else {
V_13 -> V_62 = 0 ;
}
}
switch ( V_15 ) {
case V_144 :
V_136 = L_24 ;
break;
case V_145 :
V_136 = L_25 ;
break;
case V_16 :
V_136 = L_26 ;
break;
default:
V_136 = L_27 ;
break;
}
switch ( V_13 -> V_97 ) {
case V_98 :
type = L_28 ;
break;
case V_100 :
type = L_29 ;
break;
case V_146 :
type = L_30 ;
break;
case V_147 :
type = L_31 ;
break;
default:
type = L_27 ;
break;
}
F_17 ( V_2 , L_32 , V_13 , type ,
V_136 , V_81 ) ;
F_17 ( V_2 , L_33 , V_13 ,
F_71 ( & V_123 -> V_126 ) ,
F_72 ( & V_123 -> V_126 ) ,
V_99 ? L_34 : L_35 ) ;
if ( V_128 || V_127 ) {
F_17 ( V_2 ,
L_36 ,
V_13 , V_13 -> V_18 , V_13 -> V_57 ) ;
F_17 ( V_2 , L_37 ,
V_13 , V_13 -> V_80 , V_13 -> V_77 ) ;
if ( V_13 -> V_56 )
F_17 ( V_2 , L_38 ,
V_13 , F_14 ( V_2 , V_13 ) ) ;
}
}
struct V_12 * F_73 ( struct V_1 * V_2 ,
struct V_122 * V_123 ,
T_5 V_124 )
{
struct V_12 * V_13 ;
if ( ! V_123 -> V_125 )
return NULL ;
V_13 = F_74 ( sizeof( * V_13 ) , V_124 ) ;
if ( ! V_13 )
return NULL ;
F_60 ( V_2 , V_13 , V_123 , V_124 ) ;
if ( V_2 -> V_5 -> V_116 > 0 &&
F_75 ( V_2 , V_13 , V_124 ) < 0 ) {
F_76 ( V_2 , V_13 ) ;
return NULL ;
}
return V_13 ;
}
void F_76 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( F_77 ( & V_13 -> V_112 ) ) {
unsigned long V_111 ;
F_78 ( & V_2 -> V_108 , V_111 ) ;
F_45 ( V_2 , V_13 ) ;
F_52 ( & V_2 -> V_108 , V_111 ) ;
}
F_79 ( V_2 , V_13 -> V_49 ) ;
if ( V_13 -> V_148 )
F_80 ( V_2 , V_13 ) ;
F_81 ( V_13 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_3 ;
T_4 V_149 ;
if ( F_83 ( V_13 ) )
F_84 ( V_2 -> V_9 , L_39 , V_10 ) ;
if ( ! F_47 ( & V_13 -> V_110 ) )
return 0 ;
if ( F_85 ( V_13 ) ) {
V_13 -> V_107 = V_2 -> V_102 ;
V_13 -> V_104 = V_13 -> V_107 ;
F_57 ( & V_13 -> V_110 ,
& V_2 -> V_150 ) ;
return 0 ;
}
V_3 = F_54 ( V_2 , V_13 ) ;
if ( V_3 )
return V_3 ;
if ( ! V_2 -> V_151 ) {
V_149 = F_64 ( V_2 -> V_130 + V_152 ) ;
V_149 |= V_153 ;
F_86 ( V_149 , V_2 -> V_130 + V_152 ) ;
}
V_2 -> V_151 ++ ;
return 0 ;
}
void F_87 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
T_4 V_149 ;
F_84 ( V_2 -> V_9 , L_39 , V_10 ) ;
if ( F_47 ( & V_13 -> V_110 ) )
return;
if ( F_85 ( V_13 ) ) {
if ( V_2 -> V_154 == & V_13 -> V_110 )
V_2 -> V_154 =
V_2 -> V_154 -> V_155 ;
F_48 ( & V_13 -> V_110 ) ;
return;
}
F_58 ( V_2 , V_13 ) ;
V_2 -> V_151 -- ;
if ( ! V_2 -> V_151 &&
V_2 -> V_5 -> V_116 <= 0 ) {
V_149 = F_64 ( V_2 -> V_130 + V_152 ) ;
V_149 &= ~ V_153 ;
F_86 ( V_149 , V_2 -> V_130 + V_152 ) ;
}
}
static int F_88 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_3 V_102 )
{
T_3 V_156 = V_13 -> V_104 ;
T_3 V_157 = F_40 ( V_102 , 1 ) ;
int V_158 = 0 ;
T_3 V_159 ;
if ( V_156 == V_13 -> V_107 &&
! ( V_13 -> V_97 == V_98 && ! V_13 -> V_99 ) )
V_159 = 2 ;
else
V_159 = 1 ;
V_13 -> V_104 = F_39 ( V_156 , V_159 ) ;
if ( F_41 ( V_157 , V_13 -> V_104 ) ) {
V_158 = F_40 ( V_157 ,
V_13 -> V_104 ) ;
V_13 -> V_104 = V_102 ;
}
return V_158 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_3 V_102 )
{
int V_158 = 0 ;
T_3 V_24 = V_13 -> V_80 ;
T_3 V_157 = F_40 ( V_102 , 1 ) ;
V_13 -> V_107 = F_39 ( V_13 -> V_107 ,
V_24 ) ;
if ( V_24 >= 0x1000 )
goto exit;
if ( V_13 -> V_107 == V_13 -> V_104 ||
F_41 ( V_157 , V_13 -> V_107 ) ) {
T_3 V_160 = V_13 -> V_107 ;
int V_22 ;
if ( V_13 -> V_17 || V_13 -> V_15 == V_16 )
V_22 = V_72 ;
else
V_22 = V_61 ;
V_24 = F_6 ( V_24 , V_22 ) ;
do {
V_13 -> V_107 = F_39 (
V_13 -> V_107 , V_24 ) ;
} while ( F_41 ( V_157 ,
V_13 -> V_107 ) );
V_158 = F_40 ( V_13 -> V_107 ,
V_160 ) ;
}
exit:
V_13 -> V_104 = V_13 -> V_107 ;
return V_158 ;
}
void F_90 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_161 )
{
T_3 V_156 = V_13 -> V_104 ;
T_3 V_102 ;
int V_158 ;
if ( F_83 ( V_13 ) )
F_84 ( V_2 -> V_9 , L_39 , V_10 ) ;
if ( F_85 ( V_13 ) ) {
F_87 ( V_2 , V_13 ) ;
if ( ! F_47 ( & V_13 -> V_139 ) )
F_82 ( V_2 , V_13 ) ;
return;
}
V_102 = F_38 ( V_2 ) ;
if ( V_161 )
V_158 = F_88 ( V_2 , V_13 , V_102 ) ;
else
V_158 = F_89 ( V_2 , V_13 , V_102 ) ;
F_42 ( V_2 ,
L_40 ,
V_13 , V_161 , V_102 , V_156 ,
V_13 -> V_104 ,
F_40 ( V_13 -> V_104 , V_156 ) ,
V_158 , V_158 ? L_41 : L_42 ) ;
if ( F_47 ( & V_13 -> V_139 ) ) {
F_87 ( V_2 , V_13 ) ;
return;
}
if ( F_56 ( V_13 -> V_104 , V_2 -> V_102 ) )
F_91 ( & V_13 -> V_110 ,
& V_2 -> V_117 ) ;
else
F_91 ( & V_13 -> V_110 ,
& V_2 -> V_118 ) ;
}
void F_92 ( struct V_162 * V_163 , struct V_122 * V_123 )
{
V_163 -> V_123 = V_123 ;
if ( F_62 ( & V_123 -> V_126 ) ==
V_146 ) {
V_163 -> V_137 = V_164 ;
V_163 -> V_165 = V_166 ;
}
V_163 -> V_167 = 0 ;
V_163 -> V_168 = V_169 ;
V_163 -> V_170 = 0 ;
V_163 -> V_171 = 0 ;
V_123 -> V_163 = V_163 ;
}
int F_93 ( struct V_1 * V_2 , struct V_162 * V_163 ,
struct V_12 * V_13 )
{
int V_172 ;
if ( F_94 ( ! V_13 ) ) {
F_4 ( V_2 -> V_9 , L_43 , V_10 ) ;
V_172 = - V_76 ;
goto V_173;
}
V_172 = F_82 ( V_2 , V_13 ) ;
if ( V_172 )
goto V_173;
V_163 -> V_13 = V_13 ;
F_57 ( & V_163 -> V_174 , & V_13 -> V_139 ) ;
return 0 ;
V_173:
return V_172 ;
}
