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
if ( ! V_37 -> V_47 -> V_48 )
F_10 ( V_37 -> V_47 ) ;
V_21 = F_2 () ;
V_44 = F_11 ( V_38 , sizeof( unsigned long ) ) ;
V_40 = F_12 ( V_40 + ( V_38 - V_44 ) , sizeof( unsigned long ) ) ;
V_38 = V_44 ;
if ( ( V_40 <= 0 ) ||
( V_38 + V_40 > V_37 -> V_15 . V_40 ) ||
( V_39 + V_41 > V_37 -> V_15 . V_41 ) )
return - V_49 ;
V_19 = F_3 ( V_13 ) ;
if ( ! V_19 )
return 0 ;
V_20 = V_19 -> V_27 ;
for ( V_42 = V_39 ; V_42 < V_39 + V_41 ; V_42 ++ ) {
const int V_50 = V_37 -> V_15 . V_51 [ 0 ] * V_42 ;
const int V_52 = V_50 + ( V_38 * V_45 ) ;
if ( F_5 ( V_13 , V_45 , & V_19 ,
( char * ) V_37 -> V_47 -> V_48 ,
& V_20 , V_52 , V_40 * V_45 ,
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
static int F_13 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
unsigned long V_55 = V_54 -> V_56 ;
unsigned long V_57 = V_54 -> V_58 - V_54 -> V_56 ;
unsigned long V_59 = V_54 -> V_60 << V_32 ;
unsigned long V_5 , V_61 ;
if ( V_59 + V_57 > V_2 -> V_29 . V_62 )
return - V_49 ;
V_61 = ( unsigned long ) V_2 -> V_29 . V_30 + V_59 ;
F_14 ( L_1 ,
V_61 , V_57 ) ;
while ( V_57 > 0 ) {
V_5 = F_15 ( ( void * ) V_61 ) ;
if ( F_16 ( V_54 , V_55 , V_5 , V_33 , V_63 ) )
return - V_64 ;
V_55 += V_33 ;
V_61 += V_33 ;
if ( V_57 > V_33 )
V_57 -= V_33 ;
else
V_57 = 0 ;
}
V_54 -> V_65 |= V_66 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , const struct V_67 * V_68 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_18 ( V_2 , V_68 ) ;
F_9 ( & V_10 -> V_14 , V_68 -> V_69 , V_68 -> V_70 , V_68 -> V_40 ,
V_68 -> V_41 ) ;
}
static void F_19 ( struct V_1 * V_2 , const struct V_71 * V_72 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_20 ( V_2 , V_72 ) ;
F_9 ( & V_10 -> V_14 , V_72 -> V_69 , V_72 -> V_70 , V_72 -> V_40 ,
V_72 -> V_41 ) ;
}
static void F_21 ( struct V_1 * V_2 , const struct V_73 * V_74 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_22 ( V_2 , V_74 ) ;
F_9 ( & V_10 -> V_14 , V_74 -> V_69 , V_74 -> V_70 , V_74 -> V_40 ,
V_74 -> V_41 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_75 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 . V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
if ( F_24 ( V_17 -> V_76 ) )
return - V_77 ;
V_10 -> V_78 ++ ;
if ( V_26 && ( V_2 -> V_8 == NULL ) ) {
struct V_7 * V_8 ;
V_8 = F_25 ( sizeof( struct V_7 ) , V_79 ) ;
if ( V_8 ) {
V_8 -> V_80 = V_81 ;
V_8 -> V_82 = F_1 ;
}
V_2 -> V_8 = V_8 ;
F_26 ( V_2 ) ;
}
F_14 ( L_2 ,
V_2 -> V_83 , V_75 , V_2 , V_10 -> V_78 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_75 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_78 -- ;
if ( ( V_10 -> V_78 == 0 ) && ( V_2 -> V_8 ) ) {
F_28 ( V_2 ) ;
F_29 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_84 -> V_85 = F_13 ;
}
F_30 ( L_3 ,
V_2 -> V_83 , V_75 , V_10 -> V_78 ) ;
return 0 ;
}
void F_31 ( struct V_86 * V_87 , T_2 V_88 , T_2 V_89 ,
T_2 V_90 , int V_91 )
{
}
void F_32 ( struct V_86 * V_87 , T_2 * V_88 , T_2 * V_89 ,
T_2 * V_90 , int V_91 )
{
* V_88 = 0 ;
* V_89 = 0 ;
* V_90 = 0 ;
}
static int F_33 ( struct V_92 * V_37 ,
struct V_93 * V_94 ,
unsigned V_95 , unsigned V_96 ,
struct V_97 * V_98 ,
unsigned V_99 )
{
struct V_36 * V_14 = F_34 ( V_37 ) ;
int V_42 ;
if ( ! V_14 -> V_46 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_99 ; V_42 ++ ) {
F_9 ( V_14 , V_98 [ V_42 ] . V_100 , V_98 [ V_42 ] . y1 ,
V_98 [ V_42 ] . V_101 - V_98 [ V_42 ] . V_100 ,
V_98 [ V_42 ] . V_102 - V_98 [ V_42 ] . y1 ) ;
}
return 0 ;
}
static void F_35 ( struct V_92 * V_37 )
{
struct V_36 * V_14 = F_34 ( V_37 ) ;
if ( V_14 -> V_47 )
F_36 ( & V_14 -> V_47 -> V_15 ) ;
F_37 ( V_37 ) ;
F_29 ( V_14 ) ;
}
static int
F_38 ( struct V_12 * V_13 ,
struct V_36 * V_14 ,
struct V_103 * V_104 ,
struct V_105 * V_47 )
{
int V_43 ;
V_14 -> V_47 = V_47 ;
V_43 = F_39 ( V_13 , & V_14 -> V_15 , & V_106 ) ;
F_40 ( & V_14 -> V_15 , V_104 ) ;
return V_43 ;
}
static int F_41 ( struct V_9 * V_10 ,
struct V_107 * V_108 )
{
struct V_12 * V_13 = V_10 -> V_109 . V_13 ;
struct V_1 * V_2 ;
struct V_110 * V_110 = & V_13 -> V_111 -> V_13 ;
struct V_92 * V_37 ;
struct V_103 V_104 ;
struct V_105 * V_47 ;
T_3 V_57 ;
int V_43 = 0 ;
if ( V_108 -> V_112 == 24 )
V_108 -> V_112 = 32 ;
V_104 . V_40 = V_108 -> V_113 ;
V_104 . V_41 = V_108 -> V_114 ;
V_104 . V_51 [ 0 ] = V_104 . V_40 * ( ( V_108 -> V_112 + 7 ) / 8 ) ;
V_104 . V_115 = F_42 ( V_108 -> V_112 ,
V_108 -> V_116 ) ;
V_57 = V_104 . V_51 [ 0 ] * V_104 . V_41 ;
V_57 = F_43 ( V_57 , V_33 ) ;
V_47 = F_44 ( V_13 , V_57 ) ;
if ( ! V_47 )
goto V_117;
V_43 = F_10 ( V_47 ) ;
if ( V_43 ) {
F_45 ( L_4 ) ;
goto V_118;
}
V_2 = F_46 ( 0 , V_110 ) ;
if ( ! V_2 ) {
V_43 = - V_119 ;
goto V_118;
}
V_2 -> V_11 = V_10 ;
V_43 = F_38 ( V_13 , & V_10 -> V_14 , & V_104 , V_47 ) ;
if ( V_43 )
goto V_118;
V_37 = & V_10 -> V_14 . V_15 ;
V_10 -> V_109 . V_37 = V_37 ;
V_10 -> V_109 . V_120 = V_2 ;
strcpy ( V_2 -> V_29 . V_121 , L_5 ) ;
V_2 -> V_122 = V_10 -> V_14 . V_47 -> V_48 ;
V_2 -> V_29 . V_62 = V_57 ;
V_2 -> V_29 . V_30 = ( unsigned long ) V_10 -> V_14 . V_47 -> V_48 ;
V_2 -> V_95 = V_123 | V_124 ;
V_2 -> V_84 = & V_125 ;
F_47 ( V_2 , V_37 -> V_51 [ 0 ] , V_37 -> V_126 ) ;
F_48 ( V_2 , & V_10 -> V_109 , V_108 -> V_127 , V_108 -> V_128 ) ;
V_43 = F_49 ( & V_2 -> V_129 , 256 , 0 ) ;
if ( V_43 ) {
V_43 = - V_119 ;
goto V_118;
}
F_50 ( L_6 ,
V_37 -> V_40 , V_37 -> V_41 ,
V_10 -> V_14 . V_47 -> V_48 ) ;
return V_43 ;
V_118:
F_51 ( & V_10 -> V_14 . V_47 -> V_15 ) ;
V_117:
return V_43 ;
}
static int F_52 ( struct V_130 * V_109 ,
struct V_107 * V_108 )
{
struct V_9 * V_10 = (struct V_9 * ) V_109 ;
int V_131 = 0 ;
int V_43 ;
if ( ! V_109 -> V_37 ) {
V_43 = F_41 ( V_10 , V_108 ) ;
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
if ( V_10 -> V_109 . V_120 ) {
V_2 = V_10 -> V_109 . V_120 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_129 . V_34 )
F_55 ( & V_2 -> V_129 ) ;
F_56 ( V_2 ) ;
}
F_57 ( & V_10 -> V_109 ) ;
F_37 ( & V_10 -> V_14 . V_15 ) ;
F_36 ( & V_10 -> V_14 . V_47 -> V_15 ) ;
}
int F_58 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_132 = V_133 ;
struct V_9 * V_10 ;
int V_43 ;
V_10 = F_59 ( sizeof( struct V_9 ) , V_79 ) ;
if ( ! V_10 )
return - V_119 ;
V_17 -> V_120 = V_10 ;
V_10 -> V_109 . V_134 = & V_135 ;
V_43 = F_60 ( V_13 , & V_10 -> V_109 ,
1 , 1 ) ;
if ( V_43 ) {
F_29 ( V_10 ) ;
return V_43 ;
}
F_61 ( & V_10 -> V_109 ) ;
F_62 ( & V_10 -> V_109 , V_132 ) ;
return 0 ;
}
void F_63 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( ! V_17 -> V_120 )
return;
F_53 ( V_13 , V_17 -> V_120 ) ;
F_29 ( V_17 -> V_120 ) ;
V_17 -> V_120 = NULL ;
}
void F_64 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_9 * V_10 ;
if ( ! V_17 -> V_120 )
return;
V_10 = V_17 -> V_120 ;
if ( V_10 -> V_109 . V_120 ) {
struct V_1 * V_2 ;
V_2 = V_10 -> V_109 . V_120 ;
F_65 ( V_2 ) ;
}
}
struct V_92 *
F_66 ( struct V_12 * V_13 ,
struct V_93 * V_94 ,
struct V_103 * V_104 )
{
struct V_136 * V_47 ;
struct V_36 * V_14 ;
int V_43 ;
V_47 = F_67 ( V_13 , V_94 , V_104 -> V_137 [ 0 ] ) ;
if ( V_47 == NULL )
return F_68 ( - V_138 ) ;
V_14 = F_59 ( sizeof( * V_14 ) , V_79 ) ;
if ( V_14 == NULL )
return F_68 ( - V_119 ) ;
V_43 = F_38 ( V_13 , V_14 , V_104 , F_69 ( V_47 ) ) ;
if ( V_43 ) {
F_29 ( V_14 ) ;
return F_68 ( - V_49 ) ;
}
return & V_14 -> V_15 ;
}
