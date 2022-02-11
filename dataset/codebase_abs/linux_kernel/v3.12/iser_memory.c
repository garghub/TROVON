static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
char * V_8 = NULL ;
struct V_9 * V_10 = & V_2 -> V_10 [ V_4 ] ;
unsigned long V_11 = V_10 -> V_12 ;
if ( V_11 > V_13 )
V_8 = ( void * ) F_2 ( V_14 ,
F_3 ( F_4 ( V_11 ) ) - V_15 ) ;
else
V_8 = F_5 ( V_11 , V_14 ) ;
if ( V_8 == NULL ) {
F_6 ( L_1 ,
V_10 -> V_16 , ( int ) V_11 ) ;
return - V_17 ;
}
if ( V_4 == V_18 ) {
struct V_19 * V_20 = (struct V_19 * ) V_10 -> V_21 ;
struct V_19 * V_22 ;
int V_23 ;
char * V_24 , * V_25 ;
V_24 = V_8 ;
F_7 (sgl, sg, data->size, i) {
V_25 = F_8 ( F_9 ( V_22 ) ) ;
memcpy ( V_24 ,
V_25 + V_22 -> V_26 ,
V_22 -> V_27 ) ;
F_10 ( V_25 ) ;
V_24 += V_22 -> V_27 ;
}
}
F_11 ( & V_2 -> V_28 [ V_4 ] . V_29 , V_8 , V_11 ) ;
V_2 -> V_28 [ V_4 ] . V_21 =
& V_2 -> V_28 [ V_4 ] . V_29 ;
V_2 -> V_28 [ V_4 ] . V_16 = 1 ;
V_2 -> V_28 [ V_4 ] . V_30 = V_8 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
V_5 = F_12 ( V_7 ,
& V_2 -> V_28 [ V_4 ] . V_29 ,
1 ,
( V_4 == V_18 ) ?
V_34 : V_35 ) ;
F_13 ( V_5 == 0 ) ;
V_2 -> V_28 [ V_4 ] . V_5 = V_5 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_6 * V_7 ;
struct V_9 * V_36 ;
unsigned long V_11 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
V_36 = & V_2 -> V_28 [ V_4 ] ;
F_15 ( V_7 , & V_36 -> V_29 , 1 ,
( V_4 == V_18 ) ?
V_34 : V_35 ) ;
if ( V_4 == V_37 ) {
char * V_8 ;
struct V_19 * V_20 , * V_22 ;
unsigned char * V_24 , * V_38 ;
unsigned int V_39 ;
int V_23 ;
V_8 = V_36 -> V_30 ;
V_20 = (struct V_19 * ) V_2 -> V_10 [ V_37 ] . V_21 ;
V_39 = V_2 -> V_10 [ V_37 ] . V_16 ;
V_24 = V_8 ;
F_7 (sgl, sg, sg_size, i) {
V_38 = F_8 ( F_9 ( V_22 ) ) ;
memcpy ( V_38 + V_22 -> V_26 ,
V_24 ,
V_22 -> V_27 ) ;
F_10 ( V_38 ) ;
V_24 += V_22 -> V_27 ;
}
}
V_11 = V_2 -> V_10 [ V_4 ] . V_12 ;
if ( V_11 > V_13 )
F_16 ( ( unsigned long ) V_36 -> V_30 ,
F_3 ( F_4 ( V_11 ) ) - V_15 ) ;
else
F_17 ( V_36 -> V_30 ) ;
V_36 -> V_30 = NULL ;
}
static int F_18 ( struct V_9 * V_10 ,
struct V_6 * V_40 , T_1 * V_41 ,
int * V_26 , int * V_42 )
{
struct V_19 * V_22 , * V_20 = (struct V_19 * ) V_10 -> V_21 ;
T_1 V_43 , V_44 , V_45 , V_46 = 0 ;
unsigned long V_47 = 0 ;
unsigned int V_48 ;
int V_23 , V_49 , V_50 , V_51 = V_10 -> V_5 - 1 ;
* V_26 = ( T_1 ) V_20 [ 0 ] . V_26 & ~ V_52 ;
V_49 = 1 ;
V_50 = 0 ;
F_7 (sgl, sg, data->dma_nents, i) {
V_43 = F_19 ( V_40 , V_22 ) ;
if ( V_49 )
V_46 = V_43 ;
V_48 = F_20 ( V_40 , V_22 ) ;
V_44 = V_43 + V_48 ;
V_47 += V_48 ;
if ( ! F_21 ( V_44 ) && V_23 < V_51 ) {
V_49 = 0 ;
continue;
}
V_49 = 1 ;
V_45 = V_46 & V_52 ;
do {
V_41 [ V_50 ++ ] = V_45 ;
V_45 += V_53 ;
} while ( V_45 < V_44 );
}
* V_42 = V_47 ;
F_22 ( L_2 ,
* V_42 , V_50 ) ;
return V_50 ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_6 * V_40 )
{
struct V_19 * V_20 , * V_22 , * V_54 = NULL ;
T_1 V_43 , V_44 ;
int V_23 , V_55 , V_56 = 0 ;
if ( V_10 -> V_5 == 1 )
return 1 ;
V_20 = (struct V_19 * ) V_10 -> V_21 ;
V_43 = F_19 ( V_40 , V_20 ) ;
F_7 (sgl, sg, data->dma_nents, i) {
if ( V_56 && ! F_21 ( V_43 ) )
break;
V_54 = F_24 ( V_22 ) ;
if ( ! V_54 )
break;
V_44 = V_43 + F_20 ( V_40 , V_22 ) ;
V_43 = F_19 ( V_40 , V_54 ) ;
if ( V_44 == V_43 ) {
V_56 = 0 ;
continue;
} else
V_56 = 1 ;
if ( ! F_21 ( V_44 ) )
break;
}
V_55 = ( V_54 ) ? V_23 : V_23 + 1 ;
F_22 ( L_3 ,
V_55 , V_10 -> V_5 , V_10 ) ;
return V_55 ;
}
static void F_25 ( struct V_9 * V_10 ,
struct V_6 * V_40 )
{
struct V_19 * V_20 = (struct V_19 * ) V_10 -> V_21 ;
struct V_19 * V_22 ;
int V_23 ;
F_7 (sgl, sg, data->dma_nents, i)
F_22 ( L_4
L_5 ,
V_23 , ( unsigned long ) F_19 ( V_40 , V_22 ) ,
F_9 ( V_22 ) , V_22 -> V_26 ,
V_22 -> V_27 , F_20 ( V_40 , V_22 ) ) ;
}
static void F_26 ( struct V_57 * V_58 )
{
int V_23 ;
F_6 ( L_6 ,
V_58 -> V_27 , V_58 -> V_42 ) ;
for ( V_23 = 0 ; V_23 < V_58 -> V_27 ; V_23 ++ )
F_6 ( L_7 , V_23 , ( unsigned long ) V_58 -> V_41 [ V_23 ] ) ;
}
static void F_27 ( struct V_9 * V_10 ,
struct V_57 * V_58 ,
struct V_6 * V_40 )
{
int V_59 = 0 ;
V_58 -> V_27 = 0 ;
V_58 -> V_26 = 0 ;
F_22 ( L_8 , V_10 -> V_5 ) ;
V_59 = F_18 ( V_10 , V_40 , V_58 -> V_41 ,
& V_58 -> V_26 ,
& V_58 -> V_42 ) ;
F_22 ( L_9 , V_10 -> V_5 , V_59 ) ;
V_58 -> V_27 = V_59 ;
if ( V_59 * V_53 < V_58 -> V_42 ) {
F_6 ( L_10 ) ;
F_25 ( V_10 , V_40 ) ;
F_26 ( V_58 ) ;
F_28 () ;
}
}
int F_29 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
enum V_3 V_60 ,
enum V_61 V_62 )
{
struct V_6 * V_7 ;
V_2 -> V_63 [ V_60 ] = 1 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
V_10 -> V_5 = F_12 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_62 ) ;
if ( V_10 -> V_5 == 0 ) {
F_6 ( L_11 ) ;
return - V_64 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
if ( V_2 -> V_63 [ V_37 ] ) {
V_10 = & V_2 -> V_10 [ V_37 ] ;
F_15 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_35 ) ;
}
if ( V_2 -> V_63 [ V_18 ] ) {
V_10 = & V_2 -> V_10 [ V_18 ] ;
F_15 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_34 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_6 * V_40 ,
enum V_3 V_4 ,
int V_65 )
{
struct V_66 * V_66 = V_2 -> V_31 -> V_66 ;
struct V_9 * V_8 = & V_2 -> V_10 [ V_4 ] ;
V_66 -> V_67 ++ ;
F_32 ( L_12 ,
V_65 , V_8 -> V_16 ) ;
if ( V_68 > 0 )
F_25 ( V_8 , V_40 ) ;
F_30 ( V_2 ) ;
if ( F_1 ( V_2 , V_4 ) != 0 )
return - V_17 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_31 * V_32 = V_2 -> V_31 -> V_32 ;
struct V_69 * V_33 = V_32 -> V_33 ;
struct V_6 * V_40 = V_33 -> V_6 ;
struct V_9 * V_8 = & V_2 -> V_10 [ V_4 ] ;
struct V_70 * V_71 ;
int V_65 ;
int V_72 ;
int V_23 ;
struct V_19 * V_22 ;
V_71 = & V_2 -> V_73 [ V_4 ] ;
V_65 = F_23 ( V_8 , V_40 ) ;
if ( V_65 != V_8 -> V_5 ) {
V_72 = F_31 ( V_2 , V_40 ,
V_4 , V_65 ) ;
if ( V_72 ) {
F_6 ( L_13 ) ;
return V_72 ;
}
V_8 = & V_2 -> V_28 [ V_4 ] ;
}
if ( V_8 -> V_5 == 1 ) {
V_22 = (struct V_19 * ) V_8 -> V_21 ;
V_71 -> V_74 . V_75 = V_33 -> V_76 -> V_75 ;
V_71 -> V_74 . V_77 = V_33 -> V_76 -> V_77 ;
V_71 -> V_74 . V_78 = F_20 ( V_40 , & V_22 [ 0 ] ) ;
V_71 -> V_74 . V_79 = F_19 ( V_40 , & V_22 [ 0 ] ) ;
V_71 -> V_74 . V_80 = 0 ;
F_22 ( L_14
L_15 ,
( unsigned int ) V_71 -> V_74 . V_75 ,
( unsigned int ) V_71 -> V_74 . V_77 ,
( unsigned long ) V_71 -> V_74 . V_79 ,
( unsigned long ) V_71 -> V_74 . V_78 ) ;
} else {
F_27 ( V_8 , V_32 -> V_81 . V_82 . V_58 , V_40 ) ;
V_72 = F_34 ( V_32 , V_32 -> V_81 . V_82 . V_58 ,
& V_71 -> V_74 ) ;
if ( V_72 && V_72 != - V_83 ) {
F_25 ( V_8 , V_40 ) ;
F_6 ( L_16 ,
V_8 -> V_5 ,
F_35 ( V_2 -> V_84 . V_85 . V_86 ) ) ;
F_6 ( L_17 ,
V_32 -> V_81 . V_82 . V_58 -> V_42 ,
V_32 -> V_81 . V_82 . V_58 -> V_27 ,
V_32 -> V_81 . V_82 . V_58 -> V_26 ) ;
for ( V_23 = 0 ; V_23 < V_32 -> V_81 . V_82 . V_58 -> V_27 ; V_23 ++ )
F_6 ( L_18 , V_23 ,
( unsigned long long ) V_32 -> V_81 . V_82 . V_58 -> V_41 [ V_23 ] ) ;
}
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_36 ( struct V_87 * V_84 ,
struct V_31 * V_32 ,
struct V_70 * V_71 ,
T_2 V_26 , unsigned int V_42 ,
unsigned int V_88 )
{
struct V_89 V_90 , V_91 ;
struct V_89 * V_92 , * V_93 = NULL ;
T_3 V_94 ;
int V_95 ;
if ( ! V_84 -> V_96 ) {
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_97 = V_98 ;
V_91 . V_99 = V_100 ;
V_91 . V_101 . V_102 = V_84 -> V_103 -> V_77 ;
V_93 = & V_91 ;
V_94 = ( T_3 ) ( V_84 -> V_103 -> V_77 & 0x000000FF ) ;
F_37 ( V_84 -> V_103 , ++ V_94 ) ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_97 = V_104 ;
V_90 . V_99 = V_100 ;
V_90 . V_93 . V_105 . V_106 = V_84 -> V_107 -> V_108 [ 0 ] + V_26 ;
V_90 . V_93 . V_105 . V_108 = V_84 -> V_107 ;
V_90 . V_93 . V_105 . V_88 = V_88 ;
V_90 . V_93 . V_105 . V_109 = V_110 ;
V_90 . V_93 . V_105 . V_27 = V_42 ;
V_90 . V_93 . V_105 . V_77 = V_84 -> V_103 -> V_77 ;
V_90 . V_93 . V_105 . V_111 = ( V_112 |
V_113 |
V_114 ) ;
if ( ! V_93 ) {
V_93 = & V_90 ;
F_38 ( & V_32 -> V_115 ) ;
} else {
V_93 -> V_116 = & V_90 ;
F_39 ( 2 , & V_32 -> V_115 ) ;
}
V_95 = F_40 ( V_32 -> V_117 , V_93 , & V_92 ) ;
if ( V_95 ) {
if ( V_92 -> V_116 )
F_41 ( 2 , & V_32 -> V_115 ) ;
else
F_42 ( & V_32 -> V_115 ) ;
F_6 ( L_19 , V_95 ) ;
return V_95 ;
}
V_84 -> V_96 = false ;
V_71 -> V_74 . V_118 = V_84 ;
V_71 -> V_74 . V_75 = V_84 -> V_103 -> V_75 ;
V_71 -> V_74 . V_77 = V_84 -> V_103 -> V_77 ;
V_71 -> V_74 . V_79 = V_84 -> V_107 -> V_108 [ 0 ] + V_26 ;
V_71 -> V_74 . V_78 = V_42 ;
V_71 -> V_74 . V_80 = 1 ;
return V_95 ;
}
int F_43 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_31 * V_32 = V_2 -> V_31 -> V_32 ;
struct V_69 * V_33 = V_32 -> V_33 ;
struct V_6 * V_40 = V_33 -> V_6 ;
struct V_9 * V_8 = & V_2 -> V_10 [ V_4 ] ;
struct V_70 * V_71 = & V_2 -> V_73 [ V_4 ] ;
struct V_87 * V_84 ;
unsigned int V_42 , V_88 ;
int V_72 , V_65 ;
unsigned long V_119 ;
T_2 V_26 ;
V_65 = F_23 ( V_8 , V_40 ) ;
if ( V_65 != V_8 -> V_5 ) {
V_72 = F_31 ( V_2 , V_40 ,
V_4 , V_65 ) ;
if ( V_72 ) {
F_6 ( L_13 ) ;
return V_72 ;
}
V_8 = & V_2 -> V_28 [ V_4 ] ;
}
if ( V_8 -> V_5 == 1 ) {
struct V_19 * V_22 = (struct V_19 * ) V_8 -> V_21 ;
V_71 -> V_74 . V_75 = V_33 -> V_76 -> V_75 ;
V_71 -> V_74 . V_77 = V_33 -> V_76 -> V_77 ;
V_71 -> V_74 . V_78 = F_20 ( V_40 , & V_22 [ 0 ] ) ;
V_71 -> V_74 . V_79 = F_19 ( V_40 , & V_22 [ 0 ] ) ;
V_71 -> V_74 . V_80 = 0 ;
} else {
F_44 ( & V_32 -> V_120 , V_119 ) ;
V_84 = F_45 ( & V_32 -> V_81 . V_121 . V_122 ,
struct V_87 , V_123 ) ;
F_46 ( & V_84 -> V_123 ) ;
F_47 ( & V_32 -> V_120 , V_119 ) ;
V_88 = F_18 ( V_8 , V_33 -> V_6 ,
V_84 -> V_107 -> V_108 ,
& V_26 , & V_42 ) ;
if ( V_88 * V_53 < V_42 ) {
F_6 ( L_20 ) ;
V_72 = - V_64 ;
goto V_124;
}
V_72 = F_36 ( V_84 , V_32 , V_71 ,
V_26 , V_42 , V_88 ) ;
if ( V_72 )
goto V_124;
}
return 0 ;
V_124:
F_44 ( & V_32 -> V_120 , V_119 ) ;
F_48 ( & V_84 -> V_123 , & V_32 -> V_81 . V_121 . V_122 ) ;
F_47 ( & V_32 -> V_120 , V_119 ) ;
return V_72 ;
}
