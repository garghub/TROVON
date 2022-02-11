int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 . V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
int V_13 , V_14 ;
char * V_15 ;
T_1 V_16 , V_17 ;
int V_18 = 0 ;
int V_19 = 0 ;
struct V_20 * V_20 ;
int V_21 ;
int V_22 = ( V_2 -> V_9 . V_23 / 8 ) ;
if ( ! V_2 -> V_24 )
return 0 ;
if ( ! V_2 -> V_25 -> V_26 ) {
V_14 = F_2 ( V_2 -> V_25 ) ;
if ( V_14 == - V_27 ) {
F_3 ( L_1 ) ;
return 0 ;
}
if ( ! V_2 -> V_25 -> V_26 ) {
F_3 ( L_2 ) ;
return 0 ;
}
}
V_21 = F_4 ( V_3 , sizeof( unsigned long ) ) ;
V_5 = F_5 ( V_5 + ( V_3 - V_21 ) , sizeof( unsigned long ) ) ;
V_3 = V_21 ;
if ( ( V_5 <= 0 ) ||
( V_3 + V_5 > V_2 -> V_9 . V_5 ) ||
( V_4 + V_6 > V_2 -> V_9 . V_6 ) )
return - V_28 ;
V_16 = F_6 () ;
V_20 = F_7 ( V_8 ) ;
if ( ! V_20 )
return 0 ;
V_15 = V_20 -> V_29 ;
for ( V_13 = V_4 ; V_13 < V_4 + V_6 ; V_13 ++ ) {
const int V_30 = V_2 -> V_9 . V_31 [ 0 ] * V_13 ;
const int V_32 = V_30 + ( V_3 * V_22 ) ;
const int V_33 = ( V_2 -> V_9 . V_5 * V_22 * V_13 ) + ( V_3 * V_22 ) ;
if ( F_8 ( V_8 , V_22 , & V_20 ,
( char * ) V_2 -> V_25 -> V_26 ,
& V_15 , V_32 , V_33 ,
V_5 * V_22 ,
& V_19 , & V_18 ) )
goto error;
}
if ( V_15 > ( char * ) V_20 -> V_29 ) {
int V_34 = V_15 - ( char * ) V_20 -> V_29 ;
V_14 = F_9 ( V_8 , V_20 , V_34 ) ;
V_18 += V_34 ;
} else
F_10 ( V_20 ) ;
error:
F_11 ( V_18 , & V_11 -> V_18 ) ;
F_11 ( V_19 , & V_11 -> V_19 ) ;
F_11 ( V_5 * V_6 * V_22 , & V_11 -> V_35 ) ;
V_17 = F_6 () ;
F_11 ( ( ( unsigned int ) ( ( V_17 - V_16 )
>> 10 ) ) ,
& V_11 -> V_36 ) ;
return 0 ;
}
static int F_12 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
unsigned long V_41 = V_40 -> V_42 ;
unsigned long V_43 = V_40 -> V_44 - V_40 -> V_42 ;
unsigned long V_45 = V_40 -> V_46 << V_47 ;
unsigned long V_48 , V_49 ;
if ( V_45 + V_43 > V_38 -> V_50 . V_51 )
return - V_28 ;
V_49 = ( unsigned long ) V_38 -> V_50 . V_52 + V_45 ;
F_13 ( L_3 ,
V_49 , V_43 ) ;
while ( V_43 > 0 ) {
V_48 = F_14 ( ( void * ) V_49 ) ;
if ( F_15 ( V_40 , V_41 , V_48 , V_53 , V_54 ) )
return - V_55 ;
V_41 += V_53 ;
V_49 += V_53 ;
if ( V_43 > V_53 )
V_43 -= V_53 ;
else
V_43 = 0 ;
}
return 0 ;
}
static int F_16 ( struct V_37 * V_38 , int V_56 )
{
struct V_57 * V_58 = V_38 -> V_59 ;
struct V_7 * V_8 = V_58 -> V_60 . V_9 . V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( F_17 ( V_11 -> V_61 ) )
return - V_62 ;
V_58 -> V_63 ++ ;
#ifdef F_18
if ( V_64 && ( V_38 -> V_65 == NULL ) ) {
struct V_66 * V_65 ;
V_65 = F_19 ( sizeof( struct V_66 ) , V_67 ) ;
if ( V_65 ) {
V_65 -> V_68 = V_69 ;
V_65 -> V_70 = V_71 ;
}
V_38 -> V_65 = V_65 ;
F_20 ( V_38 ) ;
}
#endif
F_13 ( L_4 ,
V_38 -> V_72 , V_56 , V_38 , V_58 -> V_63 ) ;
return 0 ;
}
static int F_21 ( struct V_37 * V_38 , int V_56 )
{
struct V_57 * V_58 = V_38 -> V_59 ;
V_58 -> V_63 -- ;
#ifdef F_18
if ( ( V_58 -> V_63 == 0 ) && ( V_38 -> V_65 ) ) {
F_22 ( V_38 ) ;
F_23 ( V_38 -> V_65 ) ;
V_38 -> V_65 = NULL ;
V_38 -> V_73 -> V_74 = F_12 ;
}
#endif
F_24 ( L_5 ,
V_38 -> V_72 , V_56 , V_58 -> V_63 ) ;
return 0 ;
}
static int F_25 ( struct V_75 * V_2 ,
struct V_76 * V_77 ,
unsigned V_78 , unsigned V_79 ,
struct V_80 * V_81 ,
unsigned V_82 )
{
struct V_1 * V_60 = F_26 ( V_2 ) ;
int V_13 ;
int V_14 = 0 ;
F_27 ( V_2 -> V_8 ) ;
if ( ! V_60 -> V_24 )
goto V_83;
if ( V_60 -> V_25 -> V_9 . V_84 ) {
V_14 = F_28 ( V_60 -> V_25 -> V_9 . V_84 -> V_85 ,
V_86 ) ;
if ( V_14 )
goto V_83;
}
for ( V_13 = 0 ; V_13 < V_82 ; V_13 ++ ) {
V_14 = F_1 ( V_60 , V_81 [ V_13 ] . V_87 , V_81 [ V_13 ] . y1 ,
V_81 [ V_13 ] . V_88 - V_81 [ V_13 ] . V_87 ,
V_81 [ V_13 ] . V_89 - V_81 [ V_13 ] . y1 ) ;
if ( V_14 )
break;
}
if ( V_60 -> V_25 -> V_9 . V_84 ) {
V_14 = F_29 ( V_60 -> V_25 -> V_9 . V_84 -> V_85 ,
V_86 ) ;
}
V_83:
F_30 ( V_2 -> V_8 ) ;
return V_14 ;
}
static void F_31 ( struct V_75 * V_2 )
{
struct V_1 * V_60 = F_26 ( V_2 ) ;
if ( V_60 -> V_25 )
F_32 ( & V_60 -> V_25 -> V_9 ) ;
F_33 ( V_2 ) ;
F_23 ( V_60 ) ;
}
static int
F_34 ( struct V_7 * V_8 ,
struct V_1 * V_60 ,
const struct V_90 * V_91 ,
struct V_92 * V_25 )
{
int V_14 ;
V_60 -> V_25 = V_25 ;
F_35 ( & V_60 -> V_9 , V_91 ) ;
V_14 = F_36 ( V_8 , & V_60 -> V_9 , & V_93 ) ;
return V_14 ;
}
static int F_37 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_57 * V_58 =
F_38 ( V_95 , struct V_57 , V_95 ) ;
struct V_7 * V_8 = V_58 -> V_95 . V_8 ;
struct V_37 * V_38 ;
struct V_75 * V_2 ;
struct V_90 V_91 ;
struct V_92 * V_25 ;
T_2 V_43 ;
int V_14 = 0 ;
if ( V_97 -> V_98 == 24 )
V_97 -> V_98 = 32 ;
V_91 . V_5 = V_97 -> V_99 ;
V_91 . V_6 = V_97 -> V_100 ;
V_91 . V_31 [ 0 ] = V_91 . V_5 * ( ( V_97 -> V_98 + 7 ) / 8 ) ;
V_91 . V_101 = F_39 ( V_97 -> V_98 ,
V_97 -> V_102 ) ;
V_43 = V_91 . V_31 [ 0 ] * V_91 . V_6 ;
V_43 = F_40 ( V_43 , V_53 ) ;
V_25 = F_41 ( V_8 , V_43 ) ;
if ( ! V_25 )
goto V_103;
V_14 = F_2 ( V_25 ) ;
if ( V_14 ) {
F_3 ( L_1 ) ;
goto V_104;
}
V_38 = F_42 ( V_95 ) ;
if ( F_43 ( V_38 ) ) {
V_14 = F_44 ( V_38 ) ;
goto V_104;
}
V_38 -> V_59 = V_58 ;
V_14 = F_34 ( V_8 , & V_58 -> V_60 , & V_91 , V_25 ) ;
if ( V_14 )
goto V_105;
V_2 = & V_58 -> V_60 . V_9 ;
V_58 -> V_95 . V_2 = V_2 ;
strcpy ( V_38 -> V_50 . V_106 , L_6 ) ;
V_38 -> V_107 = V_58 -> V_60 . V_25 -> V_26 ;
V_38 -> V_50 . V_51 = V_43 ;
V_38 -> V_50 . V_52 = ( unsigned long ) V_58 -> V_60 . V_25 -> V_26 ;
V_38 -> V_78 = V_108 | V_109 ;
V_38 -> V_73 = & V_110 ;
F_45 ( V_38 , V_2 -> V_31 [ 0 ] , V_2 -> V_111 ) ;
F_46 ( V_38 , & V_58 -> V_95 , V_97 -> V_112 , V_97 -> V_113 ) ;
F_47 ( L_7 ,
V_2 -> V_5 , V_2 -> V_6 ,
V_58 -> V_60 . V_25 -> V_26 ) ;
return V_14 ;
V_105:
F_48 ( V_95 ) ;
V_104:
F_32 ( & V_58 -> V_60 . V_25 -> V_9 ) ;
V_103:
return V_14 ;
}
static void F_49 ( struct V_7 * V_8 ,
struct V_57 * V_58 )
{
F_50 ( & V_58 -> V_95 ) ;
F_48 ( & V_58 -> V_95 ) ;
F_51 ( & V_58 -> V_95 ) ;
F_52 ( & V_58 -> V_60 . V_9 ) ;
F_33 ( & V_58 -> V_60 . V_9 ) ;
F_32 ( & V_58 -> V_60 . V_25 -> V_9 ) ;
}
int F_53 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
int V_114 = V_115 ;
struct V_57 * V_58 ;
int V_14 ;
V_58 = F_54 ( sizeof( struct V_57 ) , V_67 ) ;
if ( ! V_58 )
return - V_27 ;
V_11 -> V_116 = V_58 ;
F_55 ( V_8 , & V_58 -> V_95 , & V_117 ) ;
V_14 = F_56 ( V_8 , & V_58 -> V_95 ,
1 , 1 ) ;
if ( V_14 )
goto free;
V_14 = F_57 ( & V_58 -> V_95 ) ;
if ( V_14 )
goto V_118;
F_58 ( V_8 ) ;
V_14 = F_59 ( & V_58 -> V_95 , V_114 ) ;
if ( V_14 )
goto V_118;
return 0 ;
V_118:
F_51 ( & V_58 -> V_95 ) ;
free:
F_23 ( V_58 ) ;
return V_14 ;
}
void F_60 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
if ( ! V_11 -> V_116 )
return;
F_49 ( V_8 , V_11 -> V_116 ) ;
F_23 ( V_11 -> V_116 ) ;
V_11 -> V_116 = NULL ;
}
void F_61 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_57 * V_58 ;
if ( ! V_11 -> V_116 )
return;
V_58 = V_11 -> V_116 ;
F_62 ( & V_58 -> V_95 ) ;
}
struct V_75 *
F_63 ( struct V_7 * V_8 ,
struct V_76 * V_77 ,
const struct V_90 * V_91 )
{
struct V_119 * V_25 ;
struct V_1 * V_60 ;
int V_14 ;
T_2 V_43 ;
V_25 = F_64 ( V_77 , V_91 -> V_120 [ 0 ] ) ;
if ( V_25 == NULL )
return F_65 ( - V_121 ) ;
V_43 = V_91 -> V_31 [ 0 ] * V_91 -> V_6 ;
V_43 = F_40 ( V_43 , V_53 ) ;
if ( V_43 > V_25 -> V_43 ) {
F_3 ( L_8 , V_43 , V_25 -> V_43 , V_91 -> V_31 [ 0 ] , V_91 -> V_6 ) ;
return F_65 ( - V_27 ) ;
}
V_60 = F_54 ( sizeof( * V_60 ) , V_67 ) ;
if ( V_60 == NULL )
return F_65 ( - V_27 ) ;
V_14 = F_34 ( V_8 , V_60 , V_91 , F_66 ( V_25 ) ) ;
if ( V_14 ) {
F_23 ( V_60 ) ;
return F_65 ( - V_28 ) ;
}
return & V_60 -> V_9 ;
}
