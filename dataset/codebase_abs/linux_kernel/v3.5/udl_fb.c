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
if ( ! V_37 -> V_46 )
return 0 ;
if ( ! V_37 -> V_47 -> V_48 ) {
V_43 = F_10 ( V_37 -> V_47 ) ;
if ( V_43 == - V_49 ) {
F_11 ( L_1 ) ;
return 0 ;
}
if ( ! V_37 -> V_47 -> V_48 ) {
F_11 ( L_2 ) ;
return 0 ;
}
}
V_21 = F_2 () ;
V_44 = F_12 ( V_38 , sizeof( unsigned long ) ) ;
V_40 = F_13 ( V_40 + ( V_38 - V_44 ) , sizeof( unsigned long ) ) ;
V_38 = V_44 ;
if ( ( V_40 <= 0 ) ||
( V_38 + V_40 > V_37 -> V_15 . V_40 ) ||
( V_39 + V_41 > V_37 -> V_15 . V_41 ) )
return - V_50 ;
V_19 = F_3 ( V_13 ) ;
if ( ! V_19 )
return 0 ;
V_20 = V_19 -> V_27 ;
for ( V_42 = V_39 ; V_42 < V_39 + V_41 ; V_42 ++ ) {
const int V_51 = V_37 -> V_15 . V_52 [ 0 ] * V_42 ;
const int V_53 = V_51 + ( V_38 * V_45 ) ;
if ( F_5 ( V_13 , V_45 , & V_19 ,
( char * ) V_37 -> V_47 -> V_48 ,
& V_20 , V_53 , V_40 * V_45 ,
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
static int F_14 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
unsigned long V_56 = V_55 -> V_57 ;
unsigned long V_58 = V_55 -> V_59 - V_55 -> V_57 ;
unsigned long V_60 = V_55 -> V_61 << V_32 ;
unsigned long V_5 , V_62 ;
if ( V_60 + V_58 > V_2 -> V_29 . V_63 )
return - V_50 ;
V_62 = ( unsigned long ) V_2 -> V_29 . V_30 + V_60 ;
F_15 ( L_3 ,
V_62 , V_58 ) ;
while ( V_58 > 0 ) {
V_5 = F_16 ( ( void * ) V_62 ) ;
if ( F_17 ( V_55 , V_56 , V_5 , V_33 , V_64 ) )
return - V_65 ;
V_56 += V_33 ;
V_62 += V_33 ;
if ( V_58 > V_33 )
V_58 -= V_33 ;
else
V_58 = 0 ;
}
V_55 -> V_66 |= V_67 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , const struct V_68 * V_69 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_19 ( V_2 , V_69 ) ;
F_9 ( & V_10 -> V_14 , V_69 -> V_70 , V_69 -> V_71 , V_69 -> V_40 ,
V_69 -> V_41 ) ;
}
static void F_20 ( struct V_1 * V_2 , const struct V_72 * V_73 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_21 ( V_2 , V_73 ) ;
F_9 ( & V_10 -> V_14 , V_73 -> V_70 , V_73 -> V_71 , V_73 -> V_40 ,
V_73 -> V_41 ) ;
}
static void F_22 ( struct V_1 * V_2 , const struct V_74 * V_75 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_23 ( V_2 , V_75 ) ;
F_9 ( & V_10 -> V_14 , V_75 -> V_70 , V_75 -> V_71 , V_75 -> V_40 ,
V_75 -> V_41 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_76 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 . V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
if ( F_25 ( V_17 -> V_77 ) )
return - V_78 ;
V_10 -> V_79 ++ ;
if ( V_26 && ( V_2 -> V_8 == NULL ) ) {
struct V_7 * V_8 ;
V_8 = F_26 ( sizeof( struct V_7 ) , V_80 ) ;
if ( V_8 ) {
V_8 -> V_81 = V_82 ;
V_8 -> V_83 = F_1 ;
}
V_2 -> V_8 = V_8 ;
F_27 ( V_2 ) ;
}
F_15 ( L_4 ,
V_2 -> V_84 , V_76 , V_2 , V_10 -> V_79 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_76 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_79 -- ;
if ( ( V_10 -> V_79 == 0 ) && ( V_2 -> V_8 ) ) {
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_85 -> V_86 = F_14 ;
}
F_31 ( L_5 ,
V_2 -> V_84 , V_76 , V_10 -> V_79 ) ;
return 0 ;
}
void F_32 ( struct V_87 * V_88 , T_2 V_89 , T_2 V_90 ,
T_2 V_91 , int V_92 )
{
}
void F_33 ( struct V_87 * V_88 , T_2 * V_89 , T_2 * V_90 ,
T_2 * V_91 , int V_92 )
{
* V_89 = 0 ;
* V_90 = 0 ;
* V_91 = 0 ;
}
static int F_34 ( struct V_93 * V_37 ,
struct V_94 * V_95 ,
unsigned V_96 , unsigned V_97 ,
struct V_98 * V_99 ,
unsigned V_100 )
{
struct V_36 * V_14 = F_35 ( V_37 ) ;
int V_42 ;
if ( ! V_14 -> V_46 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_100 ; V_42 ++ ) {
F_9 ( V_14 , V_99 [ V_42 ] . V_101 , V_99 [ V_42 ] . y1 ,
V_99 [ V_42 ] . V_102 - V_99 [ V_42 ] . V_101 ,
V_99 [ V_42 ] . V_103 - V_99 [ V_42 ] . y1 ) ;
}
return 0 ;
}
static void F_36 ( struct V_93 * V_37 )
{
struct V_36 * V_14 = F_35 ( V_37 ) ;
if ( V_14 -> V_47 )
F_37 ( & V_14 -> V_47 -> V_15 ) ;
F_38 ( V_37 ) ;
F_30 ( V_14 ) ;
}
static int
F_39 ( struct V_12 * V_13 ,
struct V_36 * V_14 ,
struct V_104 * V_105 ,
struct V_106 * V_47 )
{
int V_43 ;
V_14 -> V_47 = V_47 ;
V_43 = F_40 ( V_13 , & V_14 -> V_15 , & V_107 ) ;
F_41 ( & V_14 -> V_15 , V_105 ) ;
return V_43 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_108 * V_109 )
{
struct V_12 * V_13 = V_10 -> V_110 . V_13 ;
struct V_1 * V_2 ;
struct V_111 * V_111 = & V_13 -> V_112 -> V_13 ;
struct V_93 * V_37 ;
struct V_104 V_105 ;
struct V_106 * V_47 ;
T_3 V_58 ;
int V_43 = 0 ;
if ( V_109 -> V_113 == 24 )
V_109 -> V_113 = 32 ;
V_105 . V_40 = V_109 -> V_114 ;
V_105 . V_41 = V_109 -> V_115 ;
V_105 . V_52 [ 0 ] = V_105 . V_40 * ( ( V_109 -> V_113 + 7 ) / 8 ) ;
V_105 . V_116 = F_43 ( V_109 -> V_113 ,
V_109 -> V_117 ) ;
V_58 = V_105 . V_52 [ 0 ] * V_105 . V_41 ;
V_58 = F_44 ( V_58 , V_33 ) ;
V_47 = F_45 ( V_13 , V_58 ) ;
if ( ! V_47 )
goto V_118;
V_43 = F_10 ( V_47 ) ;
if ( V_43 ) {
F_11 ( L_1 ) ;
goto V_119;
}
V_2 = F_46 ( 0 , V_111 ) ;
if ( ! V_2 ) {
V_43 = - V_49 ;
goto V_119;
}
V_2 -> V_11 = V_10 ;
V_43 = F_39 ( V_13 , & V_10 -> V_14 , & V_105 , V_47 ) ;
if ( V_43 )
goto V_119;
V_37 = & V_10 -> V_14 . V_15 ;
V_10 -> V_110 . V_37 = V_37 ;
V_10 -> V_110 . V_120 = V_2 ;
strcpy ( V_2 -> V_29 . V_121 , L_6 ) ;
V_2 -> V_122 = V_10 -> V_14 . V_47 -> V_48 ;
V_2 -> V_29 . V_63 = V_58 ;
V_2 -> V_29 . V_30 = ( unsigned long ) V_10 -> V_14 . V_47 -> V_48 ;
V_2 -> V_96 = V_123 | V_124 ;
V_2 -> V_85 = & V_125 ;
F_47 ( V_2 , V_37 -> V_52 [ 0 ] , V_37 -> V_126 ) ;
F_48 ( V_2 , & V_10 -> V_110 , V_109 -> V_127 , V_109 -> V_128 ) ;
V_43 = F_49 ( & V_2 -> V_129 , 256 , 0 ) ;
if ( V_43 ) {
V_43 = - V_49 ;
goto V_119;
}
F_50 ( L_7 ,
V_37 -> V_40 , V_37 -> V_41 ,
V_10 -> V_14 . V_47 -> V_48 ) ;
return V_43 ;
V_119:
F_51 ( & V_10 -> V_14 . V_47 -> V_15 ) ;
V_118:
return V_43 ;
}
static int F_52 ( struct V_130 * V_110 ,
struct V_108 * V_109 )
{
struct V_9 * V_10 = (struct V_9 * ) V_110 ;
int V_131 = 0 ;
int V_43 ;
if ( ! V_110 -> V_37 ) {
V_43 = F_42 ( V_10 , V_109 ) ;
if ( V_43 )
return V_43 ;
V_131 = 1 ;
}
return V_131 ;
}
static void F_53 ( struct V_12 * V_13 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
if ( V_10 -> V_110 . V_120 ) {
V_2 = V_10 -> V_110 . V_120 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_129 . V_34 )
F_55 ( & V_2 -> V_129 ) ;
F_56 ( V_2 ) ;
}
F_57 ( & V_10 -> V_110 ) ;
F_38 ( & V_10 -> V_14 . V_15 ) ;
F_37 ( & V_10 -> V_14 . V_47 -> V_15 ) ;
}
int F_58 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_132 = V_133 ;
struct V_9 * V_10 ;
int V_43 ;
V_10 = F_59 ( sizeof( struct V_9 ) , V_80 ) ;
if ( ! V_10 )
return - V_49 ;
V_17 -> V_120 = V_10 ;
V_10 -> V_110 . V_134 = & V_135 ;
V_43 = F_60 ( V_13 , & V_10 -> V_110 ,
1 , 1 ) ;
if ( V_43 ) {
F_30 ( V_10 ) ;
return V_43 ;
}
F_61 ( & V_10 -> V_110 ) ;
F_62 ( & V_10 -> V_110 , V_132 ) ;
return 0 ;
}
void F_63 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( ! V_17 -> V_120 )
return;
F_53 ( V_13 , V_17 -> V_120 ) ;
F_30 ( V_17 -> V_120 ) ;
V_17 -> V_120 = NULL ;
}
void F_64 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_9 * V_10 ;
if ( ! V_17 -> V_120 )
return;
V_10 = V_17 -> V_120 ;
if ( V_10 -> V_110 . V_120 ) {
struct V_1 * V_2 ;
V_2 = V_10 -> V_110 . V_120 ;
F_65 ( V_2 ) ;
}
}
struct V_93 *
F_66 ( struct V_12 * V_13 ,
struct V_94 * V_95 ,
struct V_104 * V_105 )
{
struct V_136 * V_47 ;
struct V_36 * V_14 ;
int V_43 ;
T_3 V_58 ;
V_47 = F_67 ( V_13 , V_95 , V_105 -> V_137 [ 0 ] ) ;
if ( V_47 == NULL )
return F_68 ( - V_138 ) ;
V_58 = V_105 -> V_52 [ 0 ] * V_105 -> V_41 ;
V_58 = F_44 ( V_58 , V_33 ) ;
if ( V_58 > V_47 -> V_58 ) {
F_11 ( L_8 , V_58 , V_47 -> V_58 , V_105 -> V_52 [ 0 ] , V_105 -> V_41 ) ;
return F_68 ( - V_49 ) ;
}
V_14 = F_59 ( sizeof( * V_14 ) , V_80 ) ;
if ( V_14 == NULL )
return F_68 ( - V_49 ) ;
V_43 = F_39 ( V_13 , V_14 , V_105 , F_69 ( V_47 ) ) ;
if ( V_43 ) {
F_30 ( V_14 ) ;
return F_68 ( - V_50 ) ;
}
return & V_14 -> V_15 ;
}
