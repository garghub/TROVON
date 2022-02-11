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
static int F_35 ( struct V_93 * V_37 ,
struct V_94 * V_95 ,
unsigned V_49 , unsigned V_96 ,
struct V_97 * V_98 ,
unsigned V_99 )
{
struct V_36 * V_14 = F_36 ( V_37 ) ;
int V_42 ;
int V_43 = 0 ;
F_37 ( V_37 -> V_13 ) ;
if ( ! V_14 -> V_50 )
goto V_100;
if ( V_14 -> V_51 -> V_15 . V_101 ) {
V_43 = F_38 ( V_14 -> V_51 -> V_15 . V_101 -> V_102 ,
0 , V_14 -> V_51 -> V_15 . V_66 ,
V_103 ) ;
if ( V_43 )
goto V_100;
}
for ( V_42 = 0 ; V_42 < V_99 ; V_42 ++ ) {
V_43 = F_9 ( V_14 , V_98 [ V_42 ] . V_56 , V_98 [ V_42 ] . y1 ,
V_98 [ V_42 ] . V_46 - V_98 [ V_42 ] . V_56 ,
V_98 [ V_42 ] . V_47 - V_98 [ V_42 ] . y1 ) ;
if ( V_43 )
break;
}
if ( V_14 -> V_51 -> V_15 . V_101 ) {
F_39 ( V_14 -> V_51 -> V_15 . V_101 -> V_102 ,
0 , V_14 -> V_51 -> V_15 . V_66 ,
V_103 ) ;
}
V_100:
F_40 ( V_37 -> V_13 ) ;
return V_43 ;
}
static void F_41 ( struct V_93 * V_37 )
{
struct V_36 * V_14 = F_36 ( V_37 ) ;
if ( V_14 -> V_51 )
F_42 ( & V_14 -> V_51 -> V_15 ) ;
F_43 ( V_37 ) ;
F_33 ( V_14 ) ;
}
static int
F_44 ( struct V_12 * V_13 ,
struct V_36 * V_14 ,
struct V_104 * V_105 ,
struct V_106 * V_51 )
{
int V_43 ;
F_45 ( & V_14 -> V_55 ) ;
V_14 -> V_51 = V_51 ;
F_46 ( & V_14 -> V_15 , V_105 ) ;
V_43 = F_47 ( V_13 , & V_14 -> V_15 , & V_107 ) ;
return V_43 ;
}
static int F_48 ( struct V_108 * V_109 ,
struct V_110 * V_111 )
{
struct V_9 * V_10 =
F_49 ( V_109 , struct V_9 , V_109 ) ;
struct V_12 * V_13 = V_10 -> V_109 . V_13 ;
struct V_1 * V_2 ;
struct V_93 * V_37 ;
struct V_104 V_105 ;
struct V_106 * V_51 ;
T_2 V_66 ;
int V_43 = 0 ;
if ( V_111 -> V_112 == 24 )
V_111 -> V_112 = 32 ;
V_105 . V_40 = V_111 -> V_113 ;
V_105 . V_41 = V_111 -> V_114 ;
V_105 . V_59 [ 0 ] = V_105 . V_40 * ( ( V_111 -> V_112 + 7 ) / 8 ) ;
V_105 . V_115 = F_50 ( V_111 -> V_112 ,
V_111 -> V_116 ) ;
V_66 = V_105 . V_59 [ 0 ] * V_105 . V_41 ;
V_66 = F_51 ( V_66 , V_33 ) ;
V_51 = F_52 ( V_13 , V_66 ) ;
if ( ! V_51 )
goto V_117;
V_43 = F_10 ( V_51 ) ;
if ( V_43 ) {
F_11 ( L_1 ) ;
goto V_118;
}
V_2 = F_53 ( V_109 ) ;
if ( F_54 ( V_2 ) ) {
V_43 = F_55 ( V_2 ) ;
goto V_118;
}
V_2 -> V_11 = V_10 ;
V_43 = F_44 ( V_13 , & V_10 -> V_14 , & V_105 , V_51 ) ;
if ( V_43 )
goto V_119;
V_37 = & V_10 -> V_14 . V_15 ;
V_10 -> V_109 . V_37 = V_37 ;
strcpy ( V_2 -> V_29 . V_120 , L_6 ) ;
V_2 -> V_121 = V_10 -> V_14 . V_51 -> V_52 ;
V_2 -> V_29 . V_71 = V_66 ;
V_2 -> V_29 . V_30 = ( unsigned long ) V_10 -> V_14 . V_51 -> V_52 ;
V_2 -> V_49 = V_122 | V_123 ;
V_2 -> V_91 = & V_124 ;
F_56 ( V_2 , V_37 -> V_59 [ 0 ] , V_37 -> V_125 ) ;
F_57 ( V_2 , & V_10 -> V_109 , V_111 -> V_126 , V_111 -> V_127 ) ;
F_58 ( L_7 ,
V_37 -> V_40 , V_37 -> V_41 ,
V_10 -> V_14 . V_51 -> V_52 ) ;
return V_43 ;
V_119:
F_59 ( V_109 ) ;
V_118:
F_60 ( & V_10 -> V_14 . V_51 -> V_15 ) ;
V_117:
return V_43 ;
}
static void F_61 ( struct V_12 * V_13 ,
struct V_9 * V_10 )
{
F_62 ( & V_10 -> V_109 ) ;
F_59 ( & V_10 -> V_109 ) ;
F_63 ( & V_10 -> V_109 ) ;
F_64 ( & V_10 -> V_14 . V_15 ) ;
F_43 ( & V_10 -> V_14 . V_15 ) ;
F_42 ( & V_10 -> V_14 . V_51 -> V_15 ) ;
}
int F_65 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_128 = V_129 ;
struct V_9 * V_10 ;
int V_43 ;
V_10 = F_66 ( sizeof( struct V_9 ) , V_86 ) ;
if ( ! V_10 )
return - V_53 ;
V_17 -> V_130 = V_10 ;
F_67 ( V_13 , & V_10 -> V_109 , & V_131 ) ;
V_43 = F_68 ( V_13 , & V_10 -> V_109 ,
1 , 1 ) ;
if ( V_43 )
goto free;
V_43 = F_69 ( & V_10 -> V_109 ) ;
if ( V_43 )
goto V_132;
F_70 ( V_13 ) ;
V_43 = F_71 ( & V_10 -> V_109 , V_128 ) ;
if ( V_43 )
goto V_132;
return 0 ;
V_132:
F_63 ( & V_10 -> V_109 ) ;
free:
F_33 ( V_10 ) ;
return V_43 ;
}
void F_72 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( ! V_17 -> V_130 )
return;
F_61 ( V_13 , V_17 -> V_130 ) ;
F_33 ( V_17 -> V_130 ) ;
V_17 -> V_130 = NULL ;
}
void F_73 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_9 * V_10 ;
if ( ! V_17 -> V_130 )
return;
V_10 = V_17 -> V_130 ;
F_74 ( & V_10 -> V_109 ) ;
}
struct V_93 *
F_75 ( struct V_12 * V_13 ,
struct V_94 * V_95 ,
struct V_104 * V_105 )
{
struct V_133 * V_51 ;
struct V_36 * V_14 ;
int V_43 ;
T_2 V_66 ;
V_51 = F_76 ( V_13 , V_95 , V_105 -> V_134 [ 0 ] ) ;
if ( V_51 == NULL )
return F_77 ( - V_135 ) ;
V_66 = V_105 -> V_59 [ 0 ] * V_105 -> V_41 ;
V_66 = F_51 ( V_66 , V_33 ) ;
if ( V_66 > V_51 -> V_66 ) {
F_11 ( L_8 , V_66 , V_51 -> V_66 , V_105 -> V_59 [ 0 ] , V_105 -> V_41 ) ;
return F_77 ( - V_53 ) ;
}
V_14 = F_66 ( sizeof( * V_14 ) , V_86 ) ;
if ( V_14 == NULL )
return F_77 ( - V_53 ) ;
V_43 = F_44 ( V_13 , V_14 , V_105 , F_78 ( V_51 ) ) ;
if ( V_43 ) {
F_33 ( V_14 ) ;
return F_77 ( - V_54 ) ;
}
return & V_14 -> V_15 ;
}
