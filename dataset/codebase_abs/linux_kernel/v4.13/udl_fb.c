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
while ( V_44 > 0 ) {
V_49 = F_14 ( ( void * ) V_50 ) ;
if ( F_15 ( V_41 , V_42 , V_49 , V_54 , V_55 ) )
return - V_56 ;
V_42 += V_54 ;
V_50 += V_54 ;
if ( V_44 > V_54 )
V_44 -= V_54 ;
else
V_44 = 0 ;
}
return 0 ;
}
static int F_16 ( struct V_38 * V_39 , int V_57 )
{
struct V_58 * V_59 = V_39 -> V_60 ;
struct V_7 * V_8 = V_59 -> V_61 . V_9 . V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( F_17 ( V_11 -> V_62 ) )
return - V_63 ;
V_59 -> V_64 ++ ;
#ifdef F_18
if ( V_65 && ( V_39 -> V_66 == NULL ) ) {
struct V_67 * V_66 ;
V_66 = F_19 ( sizeof( struct V_67 ) , V_68 ) ;
if ( V_66 ) {
V_66 -> V_69 = V_70 ;
V_66 -> V_71 = V_72 ;
}
V_39 -> V_66 = V_66 ;
F_20 ( V_39 ) ;
}
#endif
F_13 ( L_4 ,
V_39 -> V_73 , V_57 , V_39 , V_59 -> V_64 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 , int V_57 )
{
struct V_58 * V_59 = V_39 -> V_60 ;
V_59 -> V_64 -- ;
#ifdef F_18
if ( ( V_59 -> V_64 == 0 ) && ( V_39 -> V_66 ) ) {
F_22 ( V_39 ) ;
F_23 ( V_39 -> V_66 ) ;
V_39 -> V_66 = NULL ;
V_39 -> V_74 -> V_75 = F_12 ;
}
#endif
F_24 ( L_5 ,
V_39 -> V_73 , V_57 , V_59 -> V_64 ) ;
return 0 ;
}
static int F_25 ( struct V_76 * V_2 ,
struct V_77 * V_78 ,
unsigned V_79 , unsigned V_80 ,
struct V_81 * V_82 ,
unsigned V_83 )
{
struct V_1 * V_61 = F_26 ( V_2 ) ;
int V_13 ;
int V_14 = 0 ;
F_27 ( V_2 -> V_8 ) ;
if ( ! V_61 -> V_25 )
goto V_84;
if ( V_61 -> V_26 -> V_9 . V_85 ) {
V_14 = F_28 ( V_61 -> V_26 -> V_9 . V_85 -> V_86 ,
V_87 ) ;
if ( V_14 )
goto V_84;
}
for ( V_13 = 0 ; V_13 < V_83 ; V_13 ++ ) {
V_14 = F_1 ( V_61 , V_82 [ V_13 ] . V_88 , V_82 [ V_13 ] . y1 ,
V_82 [ V_13 ] . V_89 - V_82 [ V_13 ] . V_88 ,
V_82 [ V_13 ] . V_90 - V_82 [ V_13 ] . y1 ) ;
if ( V_14 )
break;
}
if ( V_61 -> V_26 -> V_9 . V_85 ) {
V_14 = F_29 ( V_61 -> V_26 -> V_9 . V_85 -> V_86 ,
V_87 ) ;
}
V_84:
F_30 ( V_2 -> V_8 ) ;
return V_14 ;
}
static void F_31 ( struct V_76 * V_2 )
{
struct V_1 * V_61 = F_26 ( V_2 ) ;
if ( V_61 -> V_26 )
F_32 ( & V_61 -> V_26 -> V_9 ) ;
F_33 ( V_2 ) ;
F_23 ( V_61 ) ;
}
static int
F_34 ( struct V_7 * V_8 ,
struct V_1 * V_61 ,
const struct V_91 * V_92 ,
struct V_93 * V_26 )
{
int V_14 ;
V_61 -> V_26 = V_26 ;
F_35 ( V_8 , & V_61 -> V_9 , V_92 ) ;
V_14 = F_36 ( V_8 , & V_61 -> V_9 , & V_94 ) ;
return V_14 ;
}
static int F_37 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_58 * V_59 =
F_38 ( V_96 , struct V_58 , V_96 ) ;
struct V_7 * V_8 = V_59 -> V_96 . V_8 ;
struct V_38 * V_39 ;
struct V_76 * V_2 ;
struct V_91 V_92 ;
struct V_93 * V_26 ;
T_2 V_44 ;
int V_14 = 0 ;
if ( V_98 -> V_99 == 24 )
V_98 -> V_99 = 32 ;
V_92 . V_5 = V_98 -> V_100 ;
V_92 . V_6 = V_98 -> V_101 ;
V_92 . V_32 [ 0 ] = V_92 . V_5 * ( ( V_98 -> V_99 + 7 ) / 8 ) ;
V_92 . V_102 = F_39 ( V_98 -> V_99 ,
V_98 -> V_103 ) ;
V_44 = V_92 . V_32 [ 0 ] * V_92 . V_6 ;
V_44 = F_40 ( V_44 , V_54 ) ;
V_26 = F_41 ( V_8 , V_44 ) ;
if ( ! V_26 )
goto V_104;
V_14 = F_2 ( V_26 ) ;
if ( V_14 ) {
F_3 ( L_1 ) ;
goto V_105;
}
V_39 = F_42 ( V_96 ) ;
if ( F_43 ( V_39 ) ) {
V_14 = F_44 ( V_39 ) ;
goto V_105;
}
V_39 -> V_60 = V_59 ;
V_14 = F_34 ( V_8 , & V_59 -> V_61 , & V_92 , V_26 ) ;
if ( V_14 )
goto V_105;
V_2 = & V_59 -> V_61 . V_9 ;
V_59 -> V_96 . V_2 = V_2 ;
strcpy ( V_39 -> V_51 . V_106 , L_6 ) ;
V_39 -> V_107 = V_59 -> V_61 . V_26 -> V_27 ;
V_39 -> V_51 . V_52 = V_44 ;
V_39 -> V_51 . V_53 = ( unsigned long ) V_59 -> V_61 . V_26 -> V_27 ;
V_39 -> V_79 = V_108 | V_109 ;
V_39 -> V_74 = & V_110 ;
F_45 ( V_39 , V_2 -> V_32 [ 0 ] , V_2 -> V_23 -> V_111 ) ;
F_46 ( V_39 , & V_59 -> V_96 , V_98 -> V_112 , V_98 -> V_113 ) ;
F_47 ( L_7 ,
V_2 -> V_5 , V_2 -> V_6 ,
V_59 -> V_61 . V_26 -> V_27 ) ;
return V_14 ;
V_105:
F_32 ( & V_59 -> V_61 . V_26 -> V_9 ) ;
V_104:
return V_14 ;
}
static void F_48 ( struct V_7 * V_8 ,
struct V_58 * V_59 )
{
F_49 ( & V_59 -> V_96 ) ;
F_50 ( & V_59 -> V_96 ) ;
F_51 ( & V_59 -> V_61 . V_9 ) ;
F_33 ( & V_59 -> V_61 . V_9 ) ;
F_32 ( & V_59 -> V_61 . V_26 -> V_9 ) ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
int V_114 = V_115 ;
struct V_58 * V_59 ;
int V_14 ;
V_59 = F_53 ( sizeof( struct V_58 ) , V_68 ) ;
if ( ! V_59 )
return - V_28 ;
V_11 -> V_116 = V_59 ;
F_54 ( V_8 , & V_59 -> V_96 , & V_117 ) ;
V_14 = F_55 ( V_8 , & V_59 -> V_96 , 1 ) ;
if ( V_14 )
goto free;
V_14 = F_56 ( & V_59 -> V_96 ) ;
if ( V_14 )
goto V_118;
F_57 ( V_8 ) ;
V_14 = F_58 ( & V_59 -> V_96 , V_114 ) ;
if ( V_14 )
goto V_118;
return 0 ;
V_118:
F_50 ( & V_59 -> V_96 ) ;
free:
F_23 ( V_59 ) ;
return V_14 ;
}
void F_59 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
if ( ! V_11 -> V_116 )
return;
F_48 ( V_8 , V_11 -> V_116 ) ;
F_23 ( V_11 -> V_116 ) ;
V_11 -> V_116 = NULL ;
}
void F_60 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_58 * V_59 ;
if ( ! V_11 -> V_116 )
return;
V_59 = V_11 -> V_116 ;
F_61 ( & V_59 -> V_96 ) ;
}
struct V_76 *
F_62 ( struct V_7 * V_8 ,
struct V_77 * V_78 ,
const struct V_91 * V_92 )
{
struct V_119 * V_26 ;
struct V_1 * V_61 ;
int V_14 ;
T_2 V_44 ;
V_26 = F_63 ( V_78 , V_92 -> V_120 [ 0 ] ) ;
if ( V_26 == NULL )
return F_64 ( - V_121 ) ;
V_44 = V_92 -> V_32 [ 0 ] * V_92 -> V_6 ;
V_44 = F_40 ( V_44 , V_54 ) ;
if ( V_44 > V_26 -> V_44 ) {
F_3 ( L_8 , V_44 , V_26 -> V_44 , V_92 -> V_32 [ 0 ] , V_92 -> V_6 ) ;
return F_64 ( - V_28 ) ;
}
V_61 = F_53 ( sizeof( * V_61 ) , V_68 ) ;
if ( V_61 == NULL )
return F_64 ( - V_28 ) ;
V_14 = F_34 ( V_8 , V_61 , V_92 , F_65 ( V_26 ) ) ;
if ( V_14 ) {
F_23 ( V_61 ) ;
return F_64 ( - V_29 ) ;
}
return & V_61 -> V_9 ;
}
