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
int V_22 = V_2 -> V_9 . V_23 -> V_24 [ 0 ] ;
if ( ! V_2 -> V_25 )
return 0 ;
if ( ! V_2 -> V_26 -> V_27 ) {
V_14 = F_2 ( V_2 -> V_26 ) ;
if ( V_14 == - V_28 ) {
F_3 ( L_1 ) ;
return 0 ;
}
if ( ! V_2 -> V_26 -> V_27 ) {
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
return - V_29 ;
V_16 = F_6 () ;
V_20 = F_7 ( V_8 ) ;
if ( ! V_20 )
return 0 ;
V_15 = V_20 -> V_30 ;
for ( V_13 = V_4 ; V_13 < V_4 + V_6 ; V_13 ++ ) {
const int V_31 = V_2 -> V_9 . V_32 [ 0 ] * V_13 ;
const int V_33 = V_31 + ( V_3 * V_22 ) ;
const int V_34 = ( V_2 -> V_9 . V_5 * V_22 * V_13 ) + ( V_3 * V_22 ) ;
if ( F_8 ( V_8 , V_22 , & V_20 ,
( char * ) V_2 -> V_26 -> V_27 ,
& V_15 , V_33 , V_34 ,
V_5 * V_22 ,
& V_19 , & V_18 ) )
goto error;
}
if ( V_15 > ( char * ) V_20 -> V_30 ) {
int V_35 = V_15 - ( char * ) V_20 -> V_30 ;
V_14 = F_9 ( V_8 , V_20 , V_35 ) ;
V_18 += V_35 ;
} else
F_10 ( V_20 ) ;
error:
F_11 ( V_18 , & V_11 -> V_18 ) ;
F_11 ( V_19 , & V_11 -> V_19 ) ;
F_11 ( V_5 * V_6 * V_22 , & V_11 -> V_36 ) ;
V_17 = F_6 () ;
F_11 ( ( ( unsigned int ) ( ( V_17 - V_16 )
>> 10 ) ) ,
& V_11 -> V_37 ) ;
return 0 ;
}
static int F_12 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
unsigned long V_42 = V_41 -> V_43 ;
unsigned long V_44 = V_41 -> V_45 - V_41 -> V_43 ;
unsigned long V_46 = V_41 -> V_47 << V_48 ;
unsigned long V_49 , V_50 ;
if ( V_46 + V_44 > V_39 -> V_51 . V_52 )
return - V_29 ;
V_50 = ( unsigned long ) V_39 -> V_51 . V_53 + V_46 ;
F_13 ( L_3 ,
V_50 , V_44 ) ;
V_41 -> V_54 = F_14 ( V_41 -> V_54 ) ;
while ( V_44 > 0 ) {
V_49 = F_15 ( ( void * ) V_50 ) ;
if ( F_16 ( V_41 , V_42 , V_49 , V_55 , V_56 ) )
return - V_57 ;
V_42 += V_55 ;
V_50 += V_55 ;
if ( V_44 > V_55 )
V_44 -= V_55 ;
else
V_44 = 0 ;
}
return 0 ;
}
static int F_17 ( struct V_38 * V_39 , int V_58 )
{
struct V_59 * V_60 = V_39 -> V_61 ;
struct V_7 * V_8 = V_60 -> V_62 . V_9 . V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( F_18 ( V_11 -> V_63 ) )
return - V_64 ;
V_60 -> V_65 ++ ;
#ifdef F_19
if ( V_66 && ( V_39 -> V_67 == NULL ) ) {
struct V_68 * V_67 ;
V_67 = F_20 ( sizeof( struct V_68 ) , V_69 ) ;
if ( V_67 ) {
V_67 -> V_70 = V_71 ;
V_67 -> V_72 = V_73 ;
}
V_39 -> V_67 = V_67 ;
F_21 ( V_39 ) ;
}
#endif
F_13 ( L_4 ,
V_39 -> V_74 , V_58 , V_39 , V_60 -> V_65 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 , int V_58 )
{
struct V_59 * V_60 = V_39 -> V_61 ;
V_60 -> V_65 -- ;
#ifdef F_19
if ( ( V_60 -> V_65 == 0 ) && ( V_39 -> V_67 ) ) {
F_23 ( V_39 ) ;
F_24 ( V_39 -> V_67 ) ;
V_39 -> V_67 = NULL ;
V_39 -> V_75 -> V_76 = F_12 ;
}
#endif
F_25 ( L_5 ,
V_39 -> V_74 , V_58 , V_60 -> V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_77 * V_2 ,
struct V_78 * V_79 ,
unsigned V_80 , unsigned V_81 ,
struct V_82 * V_83 ,
unsigned V_84 )
{
struct V_1 * V_62 = F_27 ( V_2 ) ;
int V_13 ;
int V_14 = 0 ;
F_28 ( V_2 -> V_8 ) ;
if ( ! V_62 -> V_25 )
goto V_85;
if ( V_62 -> V_26 -> V_9 . V_86 ) {
V_14 = F_29 ( V_62 -> V_26 -> V_9 . V_86 -> V_87 ,
V_88 ) ;
if ( V_14 )
goto V_85;
}
for ( V_13 = 0 ; V_13 < V_84 ; V_13 ++ ) {
V_14 = F_1 ( V_62 , V_83 [ V_13 ] . V_89 , V_83 [ V_13 ] . y1 ,
V_83 [ V_13 ] . V_90 - V_83 [ V_13 ] . V_89 ,
V_83 [ V_13 ] . V_91 - V_83 [ V_13 ] . y1 ) ;
if ( V_14 )
break;
}
if ( V_62 -> V_26 -> V_9 . V_86 ) {
V_14 = F_30 ( V_62 -> V_26 -> V_9 . V_86 -> V_87 ,
V_88 ) ;
}
V_85:
F_31 ( V_2 -> V_8 ) ;
return V_14 ;
}
static void F_32 ( struct V_77 * V_2 )
{
struct V_1 * V_62 = F_27 ( V_2 ) ;
if ( V_62 -> V_26 )
F_33 ( & V_62 -> V_26 -> V_9 ) ;
F_34 ( V_2 ) ;
F_24 ( V_62 ) ;
}
static int
F_35 ( struct V_7 * V_8 ,
struct V_1 * V_62 ,
const struct V_92 * V_93 ,
struct V_94 * V_26 )
{
int V_14 ;
V_62 -> V_26 = V_26 ;
F_36 ( V_8 , & V_62 -> V_9 , V_93 ) ;
V_14 = F_37 ( V_8 , & V_62 -> V_9 , & V_95 ) ;
return V_14 ;
}
static int F_38 ( struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_59 * V_60 =
F_39 ( V_97 , struct V_59 , V_97 ) ;
struct V_7 * V_8 = V_60 -> V_97 . V_8 ;
struct V_38 * V_39 ;
struct V_77 * V_2 ;
struct V_92 V_93 ;
struct V_94 * V_26 ;
T_2 V_44 ;
int V_14 = 0 ;
if ( V_99 -> V_100 == 24 )
V_99 -> V_100 = 32 ;
V_93 . V_5 = V_99 -> V_101 ;
V_93 . V_6 = V_99 -> V_102 ;
V_93 . V_32 [ 0 ] = V_93 . V_5 * ( ( V_99 -> V_100 + 7 ) / 8 ) ;
V_93 . V_103 = F_40 ( V_99 -> V_100 ,
V_99 -> V_104 ) ;
V_44 = V_93 . V_32 [ 0 ] * V_93 . V_6 ;
V_44 = F_41 ( V_44 , V_55 ) ;
V_26 = F_42 ( V_8 , V_44 ) ;
if ( ! V_26 )
goto V_105;
V_14 = F_2 ( V_26 ) ;
if ( V_14 ) {
F_3 ( L_1 ) ;
goto V_106;
}
V_39 = F_43 ( V_97 ) ;
if ( F_44 ( V_39 ) ) {
V_14 = F_45 ( V_39 ) ;
goto V_106;
}
V_39 -> V_61 = V_60 ;
V_14 = F_35 ( V_8 , & V_60 -> V_62 , & V_93 , V_26 ) ;
if ( V_14 )
goto V_106;
V_2 = & V_60 -> V_62 . V_9 ;
V_60 -> V_97 . V_2 = V_2 ;
strcpy ( V_39 -> V_51 . V_107 , L_6 ) ;
V_39 -> V_108 = V_60 -> V_62 . V_26 -> V_27 ;
V_39 -> V_51 . V_52 = V_44 ;
V_39 -> V_51 . V_53 = ( unsigned long ) V_60 -> V_62 . V_26 -> V_27 ;
V_39 -> V_75 = & V_109 ;
F_46 ( V_39 , V_2 -> V_32 [ 0 ] , V_2 -> V_23 -> V_110 ) ;
F_47 ( V_39 , & V_60 -> V_97 , V_99 -> V_111 , V_99 -> V_112 ) ;
F_48 ( L_7 ,
V_2 -> V_5 , V_2 -> V_6 ,
V_60 -> V_62 . V_26 -> V_27 ) ;
return V_14 ;
V_106:
F_33 ( & V_60 -> V_62 . V_26 -> V_9 ) ;
V_105:
return V_14 ;
}
static void F_49 ( struct V_7 * V_8 ,
struct V_59 * V_60 )
{
F_50 ( & V_60 -> V_97 ) ;
F_51 ( & V_60 -> V_97 ) ;
F_52 ( & V_60 -> V_62 . V_9 ) ;
F_34 ( & V_60 -> V_62 . V_9 ) ;
F_33 ( & V_60 -> V_62 . V_26 -> V_9 ) ;
}
int F_53 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
int V_113 = V_114 ;
struct V_59 * V_60 ;
int V_14 ;
V_60 = F_54 ( sizeof( struct V_59 ) , V_69 ) ;
if ( ! V_60 )
return - V_28 ;
V_11 -> V_115 = V_60 ;
F_55 ( V_8 , & V_60 -> V_97 , & V_116 ) ;
V_14 = F_56 ( V_8 , & V_60 -> V_97 , 1 ) ;
if ( V_14 )
goto free;
V_14 = F_57 ( & V_60 -> V_97 ) ;
if ( V_14 )
goto V_117;
F_58 ( V_8 ) ;
V_14 = F_59 ( & V_60 -> V_97 , V_113 ) ;
if ( V_14 )
goto V_117;
return 0 ;
V_117:
F_51 ( & V_60 -> V_97 ) ;
free:
F_24 ( V_60 ) ;
return V_14 ;
}
void F_60 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
if ( ! V_11 -> V_115 )
return;
F_49 ( V_8 , V_11 -> V_115 ) ;
F_24 ( V_11 -> V_115 ) ;
V_11 -> V_115 = NULL ;
}
void F_61 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_59 * V_60 ;
if ( ! V_11 -> V_115 )
return;
V_60 = V_11 -> V_115 ;
F_62 ( & V_60 -> V_97 ) ;
}
struct V_77 *
F_63 ( struct V_7 * V_8 ,
struct V_78 * V_79 ,
const struct V_92 * V_93 )
{
struct V_118 * V_26 ;
struct V_1 * V_62 ;
int V_14 ;
T_2 V_44 ;
V_26 = F_64 ( V_79 , V_93 -> V_119 [ 0 ] ) ;
if ( V_26 == NULL )
return F_65 ( - V_120 ) ;
V_44 = V_93 -> V_32 [ 0 ] * V_93 -> V_6 ;
V_44 = F_41 ( V_44 , V_55 ) ;
if ( V_44 > V_26 -> V_44 ) {
F_3 ( L_8 , V_44 , V_26 -> V_44 , V_93 -> V_32 [ 0 ] , V_93 -> V_6 ) ;
return F_65 ( - V_28 ) ;
}
V_62 = F_54 ( sizeof( * V_62 ) , V_69 ) ;
if ( V_62 == NULL )
return F_65 ( - V_28 ) ;
V_14 = F_35 ( V_8 , V_62 , V_93 , F_66 ( V_26 ) ) ;
if ( V_14 ) {
F_24 ( V_62 ) ;
return F_65 ( - V_29 ) ;
}
return & V_62 -> V_9 ;
}
