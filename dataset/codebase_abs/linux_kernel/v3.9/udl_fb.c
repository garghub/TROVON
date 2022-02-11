static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 . V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_19 * V_19 ;
char * V_20 ;
T_1 V_21 , V_22 ;
int V_23 = 0 ;
int V_24 = 0 ;
int V_25 = 0 ;
if ( ! V_26 )
return;
V_21 = F_2 () ;
V_19 = F_3 ( V_13 ) ;
if ( ! V_19 )
return;
V_20 = V_19 -> V_27 ;
F_4 (cur, &fbdefio->pagelist, lru) {
if ( F_5 ( V_13 , ( V_10 -> V_14 . V_15 . V_28 / 8 ) ,
& V_19 , ( char * ) V_2 -> V_29 . V_30 ,
& V_20 , V_6 -> V_31 << V_32 ,
V_6 -> V_31 << V_32 ,
V_33 , & V_24 , & V_23 ) )
goto error;
V_25 += V_33 ;
}
if ( V_20 > ( char * ) V_19 -> V_27 ) {
int V_34 = V_20 - ( char * ) V_19 -> V_27 ;
F_6 ( V_13 , V_19 , V_34 ) ;
V_23 += V_34 ;
} else
F_7 ( V_19 ) ;
error:
F_8 ( V_23 , & V_17 -> V_23 ) ;
F_8 ( V_24 , & V_17 -> V_24 ) ;
F_8 ( V_25 , & V_17 -> V_25 ) ;
V_22 = F_2 () ;
F_8 ( ( ( unsigned int ) ( ( V_22 - V_21 )
>> 10 ) ) ,
& V_17 -> V_35 ) ;
}
int F_9 ( struct V_36 * V_37 , int V_38 , int V_39 ,
int V_40 , int V_41 )
{
struct V_12 * V_13 = V_37 -> V_15 . V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
int V_42 , V_43 ;
char * V_20 ;
T_1 V_21 , V_22 ;
int V_23 = 0 ;
int V_24 = 0 ;
struct V_19 * V_19 ;
int V_44 ;
int V_45 = ( V_37 -> V_15 . V_28 / 8 ) ;
int V_46 , V_47 ;
bool V_48 = false ;
unsigned long V_49 ;
if ( ! V_37 -> V_50 )
return 0 ;
if ( ! V_37 -> V_51 -> V_52 ) {
V_43 = F_10 ( V_37 -> V_51 ) ;
if ( V_43 == - V_53 ) {
F_11 ( L_1 ) ;
return 0 ;
}
if ( ! V_37 -> V_51 -> V_52 ) {
F_11 ( L_2 ) ;
return 0 ;
}
}
V_44 = F_12 ( V_38 , sizeof( unsigned long ) ) ;
V_40 = F_13 ( V_40 + ( V_38 - V_44 ) , sizeof( unsigned long ) ) ;
V_38 = V_44 ;
if ( ( V_40 <= 0 ) ||
( V_38 + V_40 > V_37 -> V_15 . V_40 ) ||
( V_39 + V_41 > V_37 -> V_15 . V_41 ) )
return - V_54 ;
if ( F_14 () )
V_48 = true ;
V_46 = V_38 + V_40 - 1 ;
V_47 = V_39 + V_41 - 1 ;
F_15 ( & V_37 -> V_55 , V_49 ) ;
if ( V_37 -> y1 < V_39 )
V_39 = V_37 -> y1 ;
if ( V_37 -> V_47 > V_47 )
V_47 = V_37 -> V_47 ;
if ( V_37 -> V_56 < V_38 )
V_38 = V_37 -> V_56 ;
if ( V_37 -> V_46 > V_46 )
V_46 = V_37 -> V_46 ;
if ( V_48 ) {
V_37 -> V_56 = V_38 ;
V_37 -> V_46 = V_46 ;
V_37 -> y1 = V_39 ;
V_37 -> V_47 = V_47 ;
F_16 ( & V_37 -> V_55 , V_49 ) ;
return 0 ;
}
V_37 -> V_56 = V_37 -> y1 = V_57 ;
V_37 -> V_46 = V_37 -> V_47 = 0 ;
F_16 ( & V_37 -> V_55 , V_49 ) ;
V_21 = F_2 () ;
V_19 = F_3 ( V_13 ) ;
if ( ! V_19 )
return 0 ;
V_20 = V_19 -> V_27 ;
for ( V_42 = V_39 ; V_42 <= V_47 ; V_42 ++ ) {
const int V_58 = V_37 -> V_15 . V_59 [ 0 ] * V_42 ;
const int V_60 = V_58 + ( V_38 * V_45 ) ;
const int V_61 = ( V_37 -> V_15 . V_40 * V_45 * V_42 ) + ( V_38 * V_45 ) ;
if ( F_5 ( V_13 , V_45 , & V_19 ,
( char * ) V_37 -> V_51 -> V_52 ,
& V_20 , V_60 , V_61 ,
( V_46 - V_38 + 1 ) * V_45 ,
& V_24 , & V_23 ) )
goto error;
}
if ( V_20 > ( char * ) V_19 -> V_27 ) {
int V_34 = V_20 - ( char * ) V_19 -> V_27 ;
V_43 = F_6 ( V_13 , V_19 , V_34 ) ;
V_23 += V_34 ;
} else
F_7 ( V_19 ) ;
error:
F_8 ( V_23 , & V_17 -> V_23 ) ;
F_8 ( V_24 , & V_17 -> V_24 ) ;
F_8 ( V_40 * V_41 * V_45 , & V_17 -> V_25 ) ;
V_22 = F_2 () ;
F_8 ( ( ( unsigned int ) ( ( V_22 - V_21 )
>> 10 ) ) ,
& V_17 -> V_35 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
unsigned long V_64 = V_63 -> V_65 ;
unsigned long V_66 = V_63 -> V_67 - V_63 -> V_65 ;
unsigned long V_68 = V_63 -> V_69 << V_32 ;
unsigned long V_5 , V_70 ;
if ( V_68 + V_66 > V_2 -> V_29 . V_71 )
return - V_54 ;
V_70 = ( unsigned long ) V_2 -> V_29 . V_30 + V_68 ;
F_18 ( L_3 ,
V_70 , V_66 ) ;
while ( V_66 > 0 ) {
V_5 = F_19 ( ( void * ) V_70 ) ;
if ( F_20 ( V_63 , V_64 , V_5 , V_33 , V_72 ) )
return - V_73 ;
V_64 += V_33 ;
V_70 += V_33 ;
if ( V_66 > V_33 )
V_66 -= V_33 ;
else
V_66 = 0 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , const struct V_74 * V_75 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_22 ( V_2 , V_75 ) ;
F_9 ( & V_10 -> V_14 , V_75 -> V_76 , V_75 -> V_77 , V_75 -> V_40 ,
V_75 -> V_41 ) ;
}
static void F_23 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_24 ( V_2 , V_79 ) ;
F_9 ( & V_10 -> V_14 , V_79 -> V_76 , V_79 -> V_77 , V_79 -> V_40 ,
V_79 -> V_41 ) ;
}
static void F_25 ( struct V_1 * V_2 , const struct V_80 * V_81 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_26 ( V_2 , V_81 ) ;
F_9 ( & V_10 -> V_14 , V_81 -> V_76 , V_81 -> V_77 , V_81 -> V_40 ,
V_81 -> V_41 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_82 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 . V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
if ( F_28 ( V_17 -> V_83 ) )
return - V_84 ;
V_10 -> V_85 ++ ;
if ( V_26 && ( V_2 -> V_8 == NULL ) ) {
struct V_7 * V_8 ;
V_8 = F_29 ( sizeof( struct V_7 ) , V_86 ) ;
if ( V_8 ) {
V_8 -> V_87 = V_88 ;
V_8 -> V_89 = F_1 ;
}
V_2 -> V_8 = V_8 ;
F_30 ( V_2 ) ;
}
F_18 ( L_4 ,
V_2 -> V_90 , V_82 , V_2 , V_10 -> V_85 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_82 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_85 -- ;
if ( ( V_10 -> V_85 == 0 ) && ( V_2 -> V_8 ) ) {
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_91 -> V_92 = F_17 ;
}
F_34 ( L_5 ,
V_2 -> V_90 , V_82 , V_10 -> V_85 ) ;
return 0 ;
}
static void F_35 ( struct V_93 * V_94 , T_2 V_95 , T_2 V_96 ,
T_2 V_97 , int V_98 )
{
}
static void F_36 ( struct V_93 * V_94 , T_2 * V_95 , T_2 * V_96 ,
T_2 * V_97 , int V_98 )
{
* V_95 = 0 ;
* V_96 = 0 ;
* V_97 = 0 ;
}
static int F_37 ( struct V_99 * V_37 ,
struct V_100 * V_101 ,
unsigned V_49 , unsigned V_102 ,
struct V_103 * V_104 ,
unsigned V_105 )
{
struct V_36 * V_14 = F_38 ( V_37 ) ;
int V_42 ;
int V_43 = 0 ;
if ( ! V_14 -> V_50 )
return 0 ;
if ( V_14 -> V_51 -> V_15 . V_106 ) {
V_43 = F_39 ( V_14 -> V_51 -> V_15 . V_106 -> V_107 ,
0 , V_14 -> V_51 -> V_15 . V_66 ,
V_108 ) ;
if ( V_43 )
return V_43 ;
}
for ( V_42 = 0 ; V_42 < V_105 ; V_42 ++ ) {
V_43 = F_9 ( V_14 , V_104 [ V_42 ] . V_56 , V_104 [ V_42 ] . y1 ,
V_104 [ V_42 ] . V_46 - V_104 [ V_42 ] . V_56 ,
V_104 [ V_42 ] . V_47 - V_104 [ V_42 ] . y1 ) ;
if ( V_43 )
break;
}
if ( V_14 -> V_51 -> V_15 . V_106 ) {
F_40 ( V_14 -> V_51 -> V_15 . V_106 -> V_107 ,
0 , V_14 -> V_51 -> V_15 . V_66 ,
V_108 ) ;
}
return V_43 ;
}
static void F_41 ( struct V_99 * V_37 )
{
struct V_36 * V_14 = F_38 ( V_37 ) ;
if ( V_14 -> V_51 )
F_42 ( & V_14 -> V_51 -> V_15 ) ;
F_43 ( V_37 ) ;
F_33 ( V_14 ) ;
}
static int
F_44 ( struct V_12 * V_13 ,
struct V_36 * V_14 ,
struct V_109 * V_110 ,
struct V_111 * V_51 )
{
int V_43 ;
F_45 ( & V_14 -> V_55 ) ;
V_14 -> V_51 = V_51 ;
F_46 ( & V_14 -> V_15 , V_110 ) ;
V_43 = F_47 ( V_13 , & V_14 -> V_15 , & V_112 ) ;
return V_43 ;
}
static int F_48 ( struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_9 * V_10 = (struct V_9 * ) V_114 ;
struct V_12 * V_13 = V_10 -> V_114 . V_13 ;
struct V_1 * V_2 ;
struct V_117 * V_117 = & V_13 -> V_118 -> V_13 ;
struct V_99 * V_37 ;
struct V_109 V_110 ;
struct V_111 * V_51 ;
T_3 V_66 ;
int V_43 = 0 ;
if ( V_116 -> V_119 == 24 )
V_116 -> V_119 = 32 ;
V_110 . V_40 = V_116 -> V_120 ;
V_110 . V_41 = V_116 -> V_121 ;
V_110 . V_59 [ 0 ] = V_110 . V_40 * ( ( V_116 -> V_119 + 7 ) / 8 ) ;
V_110 . V_122 = F_49 ( V_116 -> V_119 ,
V_116 -> V_123 ) ;
V_66 = V_110 . V_59 [ 0 ] * V_110 . V_41 ;
V_66 = F_50 ( V_66 , V_33 ) ;
V_51 = F_51 ( V_13 , V_66 ) ;
if ( ! V_51 )
goto V_124;
V_43 = F_10 ( V_51 ) ;
if ( V_43 ) {
F_11 ( L_1 ) ;
goto V_125;
}
V_2 = F_52 ( 0 , V_117 ) ;
if ( ! V_2 ) {
V_43 = - V_53 ;
goto V_125;
}
V_2 -> V_11 = V_10 ;
V_43 = F_44 ( V_13 , & V_10 -> V_14 , & V_110 , V_51 ) ;
if ( V_43 )
goto V_125;
V_37 = & V_10 -> V_14 . V_15 ;
V_10 -> V_114 . V_37 = V_37 ;
V_10 -> V_114 . V_126 = V_2 ;
strcpy ( V_2 -> V_29 . V_127 , L_6 ) ;
V_2 -> V_128 = V_10 -> V_14 . V_51 -> V_52 ;
V_2 -> V_29 . V_71 = V_66 ;
V_2 -> V_29 . V_30 = ( unsigned long ) V_10 -> V_14 . V_51 -> V_52 ;
V_2 -> V_49 = V_129 | V_130 ;
V_2 -> V_91 = & V_131 ;
F_53 ( V_2 , V_37 -> V_59 [ 0 ] , V_37 -> V_132 ) ;
F_54 ( V_2 , & V_10 -> V_114 , V_116 -> V_133 , V_116 -> V_134 ) ;
V_43 = F_55 ( & V_2 -> V_135 , 256 , 0 ) ;
if ( V_43 ) {
V_43 = - V_53 ;
goto V_125;
}
F_56 ( L_7 ,
V_37 -> V_40 , V_37 -> V_41 ,
V_10 -> V_14 . V_51 -> V_52 ) ;
return V_43 ;
V_125:
F_57 ( & V_10 -> V_14 . V_51 -> V_15 ) ;
V_124:
return V_43 ;
}
static void F_58 ( struct V_12 * V_13 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
if ( V_10 -> V_114 . V_126 ) {
V_2 = V_10 -> V_114 . V_126 ;
F_59 ( V_2 ) ;
if ( V_2 -> V_135 . V_34 )
F_60 ( & V_2 -> V_135 ) ;
F_61 ( V_2 ) ;
}
F_62 ( & V_10 -> V_114 ) ;
F_63 ( & V_10 -> V_14 . V_15 ) ;
F_43 ( & V_10 -> V_14 . V_15 ) ;
F_42 ( & V_10 -> V_14 . V_51 -> V_15 ) ;
}
int F_64 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_136 = V_137 ;
struct V_9 * V_10 ;
int V_43 ;
V_10 = F_65 ( sizeof( struct V_9 ) , V_86 ) ;
if ( ! V_10 )
return - V_53 ;
V_17 -> V_126 = V_10 ;
V_10 -> V_114 . V_138 = & V_139 ;
V_43 = F_66 ( V_13 , & V_10 -> V_114 ,
1 , 1 ) ;
if ( V_43 ) {
F_33 ( V_10 ) ;
return V_43 ;
}
F_67 ( & V_10 -> V_114 ) ;
F_68 ( V_13 ) ;
F_69 ( & V_10 -> V_114 , V_136 ) ;
return 0 ;
}
void F_70 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( ! V_17 -> V_126 )
return;
F_58 ( V_13 , V_17 -> V_126 ) ;
F_33 ( V_17 -> V_126 ) ;
V_17 -> V_126 = NULL ;
}
void F_71 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_9 * V_10 ;
if ( ! V_17 -> V_126 )
return;
V_10 = V_17 -> V_126 ;
if ( V_10 -> V_114 . V_126 ) {
struct V_1 * V_2 ;
V_2 = V_10 -> V_114 . V_126 ;
F_72 ( V_2 ) ;
}
}
struct V_99 *
F_73 ( struct V_12 * V_13 ,
struct V_100 * V_101 ,
struct V_109 * V_110 )
{
struct V_140 * V_51 ;
struct V_36 * V_14 ;
int V_43 ;
T_3 V_66 ;
V_51 = F_74 ( V_13 , V_101 , V_110 -> V_141 [ 0 ] ) ;
if ( V_51 == NULL )
return F_75 ( - V_142 ) ;
V_66 = V_110 -> V_59 [ 0 ] * V_110 -> V_41 ;
V_66 = F_50 ( V_66 , V_33 ) ;
if ( V_66 > V_51 -> V_66 ) {
F_11 ( L_8 , V_66 , V_51 -> V_66 , V_110 -> V_59 [ 0 ] , V_110 -> V_41 ) ;
return F_75 ( - V_53 ) ;
}
V_14 = F_65 ( sizeof( * V_14 ) , V_86 ) ;
if ( V_14 == NULL )
return F_75 ( - V_53 ) ;
V_43 = F_44 ( V_13 , V_14 , V_110 , F_76 ( V_51 ) ) ;
if ( V_43 ) {
F_33 ( V_14 ) ;
return F_75 ( - V_54 ) ;
}
return & V_14 -> V_15 ;
}
