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
static void F_11 ( char * * V_36 , T_2 * V_37 , const char * V_38 , ... )
{
T_3 args ;
int V_30 ;
if ( * V_37 == 0 )
return;
va_start ( args , V_38 ) ;
V_30 = vsnprintf ( * V_36 , * V_37 , V_38 , args ) ;
va_end ( args ) ;
if ( V_30 >= * V_37 ) {
( * V_36 ) [ * V_37 - 1 ] = '\0' ;
* V_36 += * V_37 ;
* V_37 = 0 ;
} else {
* V_36 += V_30 ;
* V_37 -= V_30 ;
}
}
static void F_12 ( unsigned long * V_20 , int V_21 ,
int V_22 , const char * V_39 ,
const char * V_40 ,
void (* F_13)( const char * V_41 , void * V_42 ) ,
void * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_22 ; V_44 ++ ) {
char V_45 [ 64 ] ;
char * V_36 = V_45 ;
T_2 V_46 = sizeof( V_45 ) ;
int V_47 = V_44 * V_21 ;
int V_48 = V_47 + V_21 ;
int V_25 = 0 ;
int V_49 = 0 ;
bool V_50 = false ;
int V_30 ;
for ( V_30 = V_47 ; V_30 < V_48 + 1 ; V_30 ++ ) {
if ( V_30 < V_48 &&
F_7 ( V_20 , V_30 + 1 ,
V_30 , 1 , 0 ) != V_30 ) {
if ( V_49 == 0 )
V_25 = V_30 - V_47 ;
V_49 ++ ;
continue;
}
if ( V_49 == 0 )
continue;
if ( ! V_50 )
F_11 ( & V_36 , & V_46 , L_4 ,
V_39 , V_44 ) ;
else
F_11 ( & V_36 , & V_46 , L_5 ) ;
V_50 = true ;
F_11 ( & V_36 , & V_46 , L_6 , V_25 ,
V_40 , V_25 + V_49 - 1 , V_40 ) ;
V_49 = 0 ;
}
if ( V_50 )
F_13 ( V_45 , V_43 ) ;
}
}
static unsigned long * F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long * V_20 ;
if ( F_15 ( ! V_13 -> V_51 ) )
return NULL ;
V_20 = V_13 -> V_51 -> V_52 ;
if ( V_13 -> V_51 -> V_53 -> V_54 )
V_20 += V_55 * V_13 -> V_56 ;
return V_20 ;
}
static void F_16 ( const char * V_41 , void * V_42 )
{
struct V_57 * V_43 = V_42 ;
F_17 ( V_43 -> V_2 , L_7 , V_43 -> V_13 , V_41 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_57 V_43 = { V_2 , V_13 } ;
int V_30 ;
#ifndef F_19
return;
#endif
if ( V_13 -> V_58 ) {
unsigned long * V_20 = F_14 ( V_2 , V_13 ) ;
F_17 ( V_2 , L_8 ,
V_13 , V_13 -> V_59 ,
F_20 ( V_13 -> V_59 ) ,
V_60 * V_13 -> V_61 ) ;
if ( V_20 ) {
F_17 ( V_2 ,
L_9 ,
V_13 , V_20 ) ;
F_12 ( V_20 , V_62 ,
V_63 , L_10 , L_11 ,
F_16 , & V_43 ) ;
}
}
for ( V_30 = 0 ; V_30 < V_13 -> V_64 ; V_30 ++ ) {
struct V_65 * V_66 = V_13 -> V_67 + V_30 ;
int V_68 = V_66 -> V_69 /
V_70 ;
int V_71 = V_66 -> V_69 %
V_70 ;
F_17 ( V_2 ,
L_12 ,
V_13 , V_30 , V_66 -> V_72 , V_68 , V_71 ) ;
}
if ( V_13 -> V_64 ) {
F_17 ( V_2 , L_13 , V_13 ) ;
F_12 ( V_2 -> V_73 ,
V_70 ,
V_74 , L_14 , L_15 ,
F_16 , & V_43 ) ;
}
}
static int F_21 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_75 )
{
int V_76 = F_22 ( V_13 -> V_59 , V_60 ) ;
unsigned long * V_20 = F_14 ( V_2 , V_13 ) ;
int V_77 ;
if ( V_20 == NULL )
return - V_78 ;
V_77 = F_5 ( V_20 , V_62 ,
V_63 , V_76 ,
V_13 -> V_79 , V_75 , false ) ;
if ( V_77 < 0 )
return V_77 ;
V_13 -> V_61 = V_77 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_76 = F_22 ( V_13 -> V_59 , V_60 ) ;
unsigned long * V_20 = F_14 ( V_2 , V_13 ) ;
if ( V_20 == NULL )
return;
F_9 ( V_20 , V_62 ,
V_63 , V_76 , V_13 -> V_79 ,
V_13 -> V_61 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool V_26 , int V_80 )
{
struct V_65 * V_66 = V_13 -> V_67 + V_80 ;
int V_81 ;
V_81 = F_5 ( V_2 -> V_73 ,
V_70 ,
V_74 , V_66 -> V_72 ,
V_13 -> V_82 , V_66 -> V_69 ,
V_26 ) ;
if ( V_81 < 0 )
return V_81 ;
V_66 -> V_69 = V_81 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_12 * V_13 , int V_80 )
{
struct V_65 * V_66 = V_13 -> V_67 + V_80 ;
F_9 ( V_2 -> V_73 ,
V_70 ,
V_74 , V_66 -> V_72 ,
V_13 -> V_82 , V_66 -> V_69 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_83 = F_27 ( V_13 -> V_84 ) * F_28 ( V_13 -> V_84 ) ;
int V_85 ;
int V_86 = 0 ;
int V_87 ;
V_87 = F_6 ( V_13 -> V_82 ,
V_74 ) ;
V_85 = 0 ;
while ( V_85 < V_88 ) {
int V_89 ;
int V_90 ;
int V_91 ;
int V_92 ;
int V_93 ;
int V_94 ;
int V_95 ;
int V_96 ;
int V_97 ;
int V_30 ;
if ( V_13 -> V_58 ) {
V_86 = F_21 ( V_2 , V_13 , V_85 ) ;
if ( V_86 )
return V_86 ;
} else {
F_29 ( 1 ) ;
}
V_89 = V_13 -> V_61 /
V_98 ;
V_92 = ( V_89 % 8 ) ;
if ( V_92 == 7 ) {
if ( V_13 -> V_58 )
F_23 ( V_2 , V_13 ) ;
V_85 =
( V_13 -> V_61 /
V_62 + 1 ) *
V_62 ;
continue;
}
V_90 = ( V_89 +
V_87 - 1 ) %
V_87 ;
if ( V_13 -> V_99 == V_100 && ! V_13 -> V_101 )
V_91 = V_89 ;
else
V_91 = V_89 + 1 ;
V_96 = 188 -
F_22 ( 188 * ( V_13 -> V_61 %
V_98 ) ,
V_98 ) ;
if ( V_96 > V_83 )
V_96 = V_83 ;
V_97 = V_83 - V_96 ;
if ( ! V_13 -> V_101 &&
( V_96 != F_30 ( int , 188 , V_83 ) ) ) {
F_17 ( V_2 ,
L_16 ,
V_13 , V_96 , V_83 ) ;
if ( V_13 -> V_58 )
F_23 ( V_2 , V_13 ) ;
V_85 = ( V_89 + 1 ) *
V_98 ;
continue;
}
V_13 -> V_64 = 1 + F_22 ( V_97 , 188 ) ;
if ( V_13 -> V_99 == V_102 ) {
if ( V_92 == 6 )
V_13 -> V_64 += 2 ;
else
V_13 -> V_64 += 3 ;
if ( V_13 -> V_101 ) {
V_93 = 4 ;
V_94 = V_83 ;
V_95 = V_83 ;
} else {
V_93 = V_96 ;
V_94 = F_31 ( int , 4 , V_97 ) ;
V_95 = 4 ;
}
} else {
if ( V_13 -> V_101 ) {
int V_103 ;
V_13 -> V_64 ++ ;
V_103 = V_92 + V_13 -> V_64 + 1 ;
if ( V_103 <= 6 )
V_13 -> V_64 += 2 ;
else
V_13 -> V_64 += 1 ;
if ( V_103 >= 6 && V_92 == 0 )
V_13 -> V_64 -- ;
V_93 = 4 ;
V_94 = F_30 ( int , 188 , V_83 ) ;
V_95 = V_94 ;
} else {
V_93 = V_96 ;
V_94 = F_30 ( int , 188 ,
V_97 ) ;
V_95 = V_97 % 188 ;
}
}
V_13 -> V_67 [ 0 ] . V_72 = F_32 ( V_93 ) ;
for ( V_30 = 1 ; V_30 < V_13 -> V_64 - 1 ; V_30 ++ )
V_13 -> V_67 [ V_30 ] . V_72 =
F_32 ( V_94 ) ;
if ( V_13 -> V_64 > 1 )
V_13 -> V_67 [ V_13 -> V_64 - 1 ] . V_72 =
F_32 ( V_95 ) ;
V_13 -> V_67 [ 0 ] . V_69 =
V_90 * V_70 ;
for ( V_30 = 1 ; V_30 < V_13 -> V_64 ; V_30 ++ )
V_13 -> V_67 [ V_30 ] . V_69 =
( ( V_91 + V_30 - 1 ) %
V_74 ) *
V_70 ;
for ( V_30 = 0 ; V_30 < V_13 -> V_64 ; V_30 ++ ) {
V_86 = F_24 ( V_2 , V_13 , true , V_30 ) ;
if ( V_86 )
break;
}
if ( V_30 == V_13 -> V_64 )
break;
for (; V_30 >= 0 ; V_30 -- )
F_25 ( V_2 , V_13 , V_30 ) ;
if ( V_13 -> V_58 )
F_23 ( V_2 , V_13 ) ;
V_85 = ( V_89 + 1 ) * V_98 ;
}
if ( V_85 >= V_88 )
return - V_11 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_15 ( V_13 -> V_18 != V_13 -> V_59 ) ;
F_15 ( V_13 -> V_82 != V_13 -> V_79 ) ;
F_15 ( V_13 -> V_64 != 1 ) ;
V_13 -> V_67 [ 0 ] . V_69 = 0 ;
V_13 -> V_67 [ 0 ] . V_72 = V_13 -> V_18 ;
return F_24 ( V_2 , V_13 , false , 0 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_15 ( V_13 -> V_18 != V_13 -> V_59 ) ;
F_15 ( V_13 -> V_82 != V_13 -> V_79 ) ;
F_15 ( ! V_13 -> V_58 ) ;
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
for ( V_30 = 0 ; V_30 < V_13 -> V_64 ; V_30 ++ )
F_25 ( V_2 , V_13 , V_30 ) ;
if ( V_13 -> V_58 )
F_23 ( V_2 , V_13 ) ;
F_17 ( V_2 , L_18 , V_13 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
T_4 V_104 ;
T_4 V_105 ;
T_4 V_106 ;
T_4 V_107 ;
T_4 V_24 ;
V_104 = F_38 ( V_2 ) ;
V_105 = F_39 ( V_104 , 1 ) ;
V_106 = V_105 ;
if ( V_2 -> V_5 -> V_108 <= 0 ) {
if ( V_13 -> V_17 )
V_106 |= 0x7 ;
goto exit;
}
if ( V_13 -> V_15 == V_16 || V_13 -> V_17 ) {
F_15 ( V_13 -> V_64 < 1 ) ;
V_107 = V_13 -> V_67 [ 0 ] . V_69 /
V_70 ;
V_24 = F_6 ( V_13 -> V_82 , V_74 ) ;
} else {
V_107 = V_13 -> V_61 /
V_62 ;
V_24 = F_6 ( V_13 -> V_82 , V_63 ) ;
}
F_15 ( V_107 >= V_24 ) ;
V_106 = ( V_106 / V_24 ) * V_24 ;
V_106 = F_39 ( V_106 ,
V_107 ) ;
V_106 = F_40 ( V_106 , 1 ) ;
while ( F_41 ( V_105 , V_106 ) )
V_106 = F_39 ( V_106 ,
V_24 ) ;
exit:
V_13 -> V_106 = V_106 ;
V_13 -> V_109 = V_106 ;
F_42 ( V_2 , L_19 ,
V_13 , V_104 , V_13 -> V_106 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_3 ;
if ( V_2 -> V_5 -> V_108 > 0 ) {
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
if ( V_2 -> V_5 -> V_108 <= 0 )
V_2 -> V_7 ++ ;
V_2 -> V_19 += V_13 -> V_18 ;
F_37 ( V_2 , V_13 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_46 ( & V_2 -> V_110 ) ;
F_15 ( ! V_13 -> V_111 ) ;
V_13 -> V_111 = false ;
if ( F_15 ( ! F_47 ( & V_13 -> V_112 ) ) )
F_48 ( & V_13 -> V_112 ) ;
V_2 -> V_19 -= V_13 -> V_18 ;
if ( V_2 -> V_5 -> V_108 > 0 ) {
F_36 ( V_2 , V_13 ) ;
} else {
V_2 -> V_7 -- ;
}
}
static void F_49 ( unsigned long V_42 )
{
struct V_12 * V_13 = (struct V_12 * ) V_42 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_113 ;
while ( ! F_50 ( & V_2 -> V_110 , V_113 ) ) {
if ( F_51 ( & V_13 -> V_114 ) )
return;
}
if ( V_13 -> V_111 )
F_45 ( V_2 , V_13 ) ;
F_52 ( & V_2 -> V_110 , V_113 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
T_5 V_115 ;
T_5 V_116 ;
int V_3 = 0 ;
V_115 = F_28 ( V_13 -> V_84 ) * F_27 ( V_13 -> V_84 ) ;
V_116 = V_2 -> V_5 -> V_117 ;
if ( V_115 > V_116 ) {
F_4 ( V_2 -> V_9 ,
L_22 ,
V_10 , V_115 , V_116 ) ;
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
if ( F_55 ( & V_13 -> V_114 ) )
F_15 ( ! V_13 -> V_111 ) ;
if ( ! V_13 -> V_111 ) {
V_3 = F_43 ( V_2 , V_13 ) ;
if ( V_3 )
return V_3 ;
} else {
if ( F_56 ( V_13 -> V_106 ,
V_2 -> V_104 ) )
F_37 ( V_2 , V_13 ) ;
}
V_13 -> V_111 = 0 ;
if ( V_2 -> V_5 -> V_118 > 0 )
F_57 ( & V_13 -> V_112 , & V_2 -> V_119 ) ;
else
F_57 ( & V_13 -> V_112 ,
& V_2 -> V_120 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
bool V_121 ;
F_46 ( & V_2 -> V_110 ) ;
V_121 = F_59 ( & V_13 -> V_114 ,
V_122 + V_123 + 1 ) ;
F_15 ( V_121 ) ;
V_13 -> V_111 = 1 ;
F_48 ( & V_13 -> V_112 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_124 * V_125 , T_6 V_126 )
{
int V_15 = F_61 ( V_2 , V_125 -> V_127 ) ;
T_7 V_99 = F_62 ( & V_125 -> V_128 ) ;
bool V_101 = ! ! F_63 ( & V_125 -> V_128 ) ;
bool V_129 = ( V_99 == V_100 ) ;
bool V_130 = ( V_99 == V_102 ) ;
T_5 V_131 = F_64 ( V_2 -> V_132 + V_133 ) ;
T_5 V_134 = ( V_131 & V_135 ) >> V_136 ;
bool V_17 = ( V_134 == V_137 &&
V_15 != V_16 ) ;
int V_84 = F_65 ( & V_125 -> V_128 ) ;
int V_83 = F_27 ( V_84 ) * F_28 ( V_84 ) ;
char * V_138 , * type ;
V_13 -> V_2 = V_2 ;
F_66 ( & V_13 -> V_114 , F_49 ,
( unsigned long ) V_13 ) ;
V_13 -> V_99 = V_99 ;
V_13 -> V_101 = V_101 ;
V_13 -> V_139 = V_140 ;
V_13 -> V_84 = V_84 ;
F_67 ( & V_13 -> V_141 ) ;
F_67 ( & V_13 -> V_112 ) ;
V_13 -> V_17 = V_17 ;
V_13 -> V_15 = V_15 ;
if ( V_130 || V_129 ) {
int V_142 = V_17 ? V_16 : V_15 ;
struct V_143 * V_51 = F_68 ( V_2 , V_125 -> V_127 ,
V_126 ,
& V_13 -> V_56 ) ;
int V_144 ;
V_13 -> V_51 = V_51 ;
V_13 -> V_18 = F_69 ( F_70 ( V_142 , V_101 ,
V_129 , V_83 ) ) ;
V_144 = F_70 ( V_15 , V_101 ,
V_129 , V_83 ) ;
if ( V_17 && V_51 )
V_144 += V_51 -> V_53 -> V_145 ;
V_13 -> V_59 = F_69 ( V_144 ) ;
V_13 -> V_79 = V_125 -> V_24 ;
V_13 -> V_82 = V_125 -> V_24 * ( V_17 ? 8 : 1 ) ;
V_13 -> V_58 = V_134 != V_137 ||
V_51 ;
if ( V_17 ) {
V_13 -> V_64 = - 1 ;
} else if ( V_15 == V_16 ) {
V_13 -> V_64 = 1 ;
} else {
V_13 -> V_64 = 0 ;
}
}
switch ( V_15 ) {
case V_146 :
V_138 = L_24 ;
break;
case V_147 :
V_138 = L_25 ;
break;
case V_16 :
V_138 = L_26 ;
break;
default:
V_138 = L_27 ;
break;
}
switch ( V_13 -> V_99 ) {
case V_100 :
type = L_28 ;
break;
case V_102 :
type = L_29 ;
break;
case V_148 :
type = L_30 ;
break;
case V_149 :
type = L_31 ;
break;
default:
type = L_27 ;
break;
}
F_17 ( V_2 , L_32 , V_13 , type ,
V_138 , V_83 ) ;
F_17 ( V_2 , L_33 , V_13 ,
F_71 ( & V_125 -> V_128 ) ,
F_72 ( & V_125 -> V_128 ) ,
V_101 ? L_34 : L_35 ) ;
if ( V_130 || V_129 ) {
F_17 ( V_2 ,
L_36 ,
V_13 , V_13 -> V_18 , V_13 -> V_59 ) ;
F_17 ( V_2 , L_37 ,
V_13 , V_13 -> V_82 , V_13 -> V_79 ) ;
if ( V_13 -> V_58 )
F_17 ( V_2 , L_38 ,
V_13 , F_14 ( V_2 , V_13 ) ) ;
}
}
struct V_12 * F_73 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
T_6 V_126 )
{
struct V_12 * V_13 ;
if ( ! V_125 -> V_127 )
return NULL ;
V_13 = F_74 ( sizeof( * V_13 ) , V_126 ) ;
if ( ! V_13 )
return NULL ;
F_60 ( V_2 , V_13 , V_125 , V_126 ) ;
if ( V_2 -> V_5 -> V_118 > 0 &&
F_75 ( V_2 , V_13 , V_126 ) < 0 ) {
F_76 ( V_2 , V_13 ) ;
return NULL ;
}
return V_13 ;
}
void F_76 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( F_77 ( & V_13 -> V_114 ) ) {
unsigned long V_113 ;
F_78 ( & V_2 -> V_110 , V_113 ) ;
F_45 ( V_2 , V_13 ) ;
F_52 ( & V_2 -> V_110 , V_113 ) ;
}
F_79 ( V_2 , V_13 -> V_51 ) ;
if ( V_13 -> V_150 )
F_80 ( V_2 , V_13 ) ;
F_81 ( V_13 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_3 ;
T_5 V_151 ;
if ( F_83 ( V_13 ) )
F_84 ( V_2 -> V_9 , L_39 , V_10 ) ;
if ( ! F_47 ( & V_13 -> V_112 ) )
return 0 ;
if ( F_85 ( V_13 ) ) {
V_13 -> V_109 = V_2 -> V_104 ;
V_13 -> V_106 = V_13 -> V_109 ;
F_57 ( & V_13 -> V_112 ,
& V_2 -> V_152 ) ;
return 0 ;
}
V_3 = F_54 ( V_2 , V_13 ) ;
if ( V_3 )
return V_3 ;
if ( ! V_2 -> V_153 ) {
V_151 = F_64 ( V_2 -> V_132 + V_154 ) ;
V_151 |= V_155 ;
F_86 ( V_151 , V_2 -> V_132 + V_154 ) ;
}
V_2 -> V_153 ++ ;
return 0 ;
}
void F_87 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
T_5 V_151 ;
F_84 ( V_2 -> V_9 , L_39 , V_10 ) ;
if ( F_47 ( & V_13 -> V_112 ) )
return;
if ( F_85 ( V_13 ) ) {
if ( V_2 -> V_156 == & V_13 -> V_112 )
V_2 -> V_156 =
V_2 -> V_156 -> V_157 ;
F_48 ( & V_13 -> V_112 ) ;
return;
}
F_58 ( V_2 , V_13 ) ;
V_2 -> V_153 -- ;
if ( ! V_2 -> V_153 ) {
V_151 = F_64 ( V_2 -> V_132 + V_154 ) ;
V_151 &= ~ V_155 ;
F_86 ( V_151 , V_2 -> V_132 + V_154 ) ;
}
}
static int F_88 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_4 V_104 )
{
T_4 V_158 = V_13 -> V_106 ;
T_4 V_159 = F_40 ( V_104 , 1 ) ;
int V_160 = 0 ;
T_4 V_161 ;
if ( V_158 == V_13 -> V_109 &&
! ( V_13 -> V_99 == V_100 && ! V_13 -> V_101 ) )
V_161 = 2 ;
else
V_161 = 1 ;
V_13 -> V_106 = F_39 ( V_158 , V_161 ) ;
if ( F_41 ( V_159 , V_13 -> V_106 ) ) {
V_160 = F_40 ( V_159 ,
V_13 -> V_106 ) ;
V_13 -> V_106 = V_104 ;
}
return V_160 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_4 V_104 )
{
int V_160 = 0 ;
T_4 V_24 = V_13 -> V_82 ;
T_4 V_159 = F_40 ( V_104 , 1 ) ;
V_13 -> V_109 = F_39 ( V_13 -> V_109 ,
V_24 ) ;
if ( V_24 >= 0x1000 )
goto exit;
if ( V_13 -> V_109 == V_13 -> V_106 ||
F_41 ( V_159 , V_13 -> V_109 ) ) {
T_4 V_162 = V_13 -> V_109 ;
int V_22 ;
if ( V_13 -> V_17 || V_13 -> V_15 == V_16 )
V_22 = V_74 ;
else
V_22 = V_63 ;
V_24 = F_6 ( V_24 , V_22 ) ;
do {
V_13 -> V_109 = F_39 (
V_13 -> V_109 , V_24 ) ;
} while ( F_41 ( V_159 ,
V_13 -> V_109 ) );
V_160 = F_40 ( V_13 -> V_109 ,
V_162 ) ;
}
exit:
V_13 -> V_106 = V_13 -> V_109 ;
return V_160 ;
}
void F_90 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_163 )
{
T_4 V_158 = V_13 -> V_106 ;
T_4 V_104 ;
int V_160 ;
if ( F_83 ( V_13 ) )
F_84 ( V_2 -> V_9 , L_39 , V_10 ) ;
if ( F_85 ( V_13 ) ) {
F_87 ( V_2 , V_13 ) ;
if ( ! F_47 ( & V_13 -> V_141 ) )
F_82 ( V_2 , V_13 ) ;
return;
}
V_104 = F_38 ( V_2 ) ;
if ( V_163 )
V_160 = F_88 ( V_2 , V_13 , V_104 ) ;
else
V_160 = F_89 ( V_2 , V_13 , V_104 ) ;
F_42 ( V_2 ,
L_40 ,
V_13 , V_163 , V_104 , V_158 ,
V_13 -> V_106 ,
F_40 ( V_13 -> V_106 , V_158 ) ,
V_160 , V_160 ? L_41 : L_42 ) ;
if ( F_47 ( & V_13 -> V_141 ) ) {
F_87 ( V_2 , V_13 ) ;
return;
}
if ( F_56 ( V_13 -> V_106 , V_2 -> V_104 ) )
F_91 ( & V_13 -> V_112 ,
& V_2 -> V_119 ) ;
else
F_91 ( & V_13 -> V_112 ,
& V_2 -> V_120 ) ;
}
void F_92 ( struct V_164 * V_165 , struct V_124 * V_125 )
{
V_165 -> V_125 = V_125 ;
if ( F_62 ( & V_125 -> V_128 ) ==
V_148 ) {
V_165 -> V_139 = V_166 ;
V_165 -> V_167 = V_168 ;
}
V_165 -> V_169 = 0 ;
V_165 -> V_170 = V_171 ;
V_165 -> V_172 = 0 ;
V_165 -> V_173 = 0 ;
V_125 -> V_165 = V_165 ;
}
int F_93 ( struct V_1 * V_2 , struct V_164 * V_165 ,
struct V_12 * V_13 )
{
int V_174 ;
if ( F_94 ( ! V_13 ) ) {
F_4 ( V_2 -> V_9 , L_43 , V_10 ) ;
V_174 = - V_78 ;
goto V_175;
}
V_174 = F_82 ( V_2 , V_13 ) ;
if ( V_174 )
goto V_175;
V_165 -> V_13 = V_13 ;
F_57 ( & V_165 -> V_176 , & V_13 -> V_141 ) ;
return 0 ;
V_175:
return V_174 ;
}
