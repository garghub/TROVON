static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
if ( V_8 -> V_10 [ V_9 ] )
F_5 ( & V_8 -> V_10 [ V_9 ] -> V_11 ) ;
}
F_6 ( V_7 ) ;
F_7 ( V_8 ) ;
}
int F_8 ( struct V_6 * V_7 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
return F_9 ( V_13 ,
& V_8 -> V_10 [ 0 ] -> V_11 , V_14 ) ;
}
static struct V_5 * F_10 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
struct V_19 * * V_10 ,
unsigned int V_20 , const struct V_21 * V_22 )
{
struct V_5 * V_8 ;
int V_23 ;
int V_9 ;
V_8 = F_11 ( sizeof( * V_8 ) , V_24 ) ;
if ( ! V_8 )
return F_12 ( - V_25 ) ;
F_13 ( V_16 , & V_8 -> V_7 , V_18 ) ;
for ( V_9 = 0 ; V_9 < V_20 ; V_9 ++ )
V_8 -> V_10 [ V_9 ] = V_10 [ V_9 ] ;
V_23 = F_14 ( V_16 , & V_8 -> V_7 , V_22 ) ;
if ( V_23 ) {
F_15 ( V_16 -> V_16 , L_1 , V_23 ) ;
F_7 ( V_8 ) ;
return F_12 ( V_23 ) ;
}
return V_8 ;
}
struct V_6 * F_16 ( struct V_15 * V_16 ,
struct V_12 * V_13 , const struct V_17 * V_18 ,
const struct V_21 * V_22 )
{
const struct V_26 * V_27 ;
struct V_5 * V_8 ;
struct V_19 * V_28 [ 4 ] ;
struct V_29 * V_10 ;
int V_23 ;
int V_9 ;
V_27 = F_17 ( V_16 , V_18 ) ;
if ( ! V_27 )
return F_12 ( - V_30 ) ;
for ( V_9 = 0 ; V_9 < V_27 -> V_20 ; V_9 ++ ) {
unsigned int V_31 = V_18 -> V_31 / ( V_9 ? V_27 -> V_32 : 1 ) ;
unsigned int V_33 = V_18 -> V_33 / ( V_9 ? V_27 -> V_34 : 1 ) ;
unsigned int V_35 ;
V_10 = F_18 ( V_13 , V_18 -> V_36 [ V_9 ] ) ;
if ( ! V_10 ) {
F_15 ( V_16 -> V_16 , L_2 ) ;
V_23 = - V_37 ;
goto V_38;
}
V_35 = ( V_33 - 1 ) * V_18 -> V_39 [ V_9 ]
+ V_31 * V_27 -> V_40 [ V_9 ]
+ V_18 -> V_41 [ V_9 ] ;
if ( V_10 -> V_42 < V_35 ) {
F_5 ( V_10 ) ;
V_23 = - V_30 ;
goto V_38;
}
V_28 [ V_9 ] = F_19 ( V_10 ) ;
}
V_8 = F_10 ( V_16 , V_18 , V_28 , V_9 , V_22 ) ;
if ( F_20 ( V_8 ) ) {
V_23 = F_21 ( V_8 ) ;
goto V_38;
}
return & V_8 -> V_7 ;
V_38:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_5 ( & V_28 [ V_9 ] -> V_11 ) ;
return F_12 ( V_23 ) ;
}
struct V_6 * F_22 ( struct V_15 * V_16 ,
struct V_12 * V_13 , const struct V_17 * V_18 )
{
return F_16 ( V_16 , V_13 , V_18 ,
& V_43 ) ;
}
struct V_19 * F_23 ( struct V_6 * V_7 ,
unsigned int V_44 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
if ( V_44 >= 4 )
return NULL ;
return V_8 -> V_10 [ V_44 ] ;
}
T_1 F_24 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
unsigned int V_44 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
T_1 V_47 ;
if ( V_44 >= 4 )
return 0 ;
V_47 = V_8 -> V_10 [ V_44 ] -> V_47 + V_7 -> V_41 [ V_44 ] ;
V_47 += V_7 -> V_48 -> V_40 [ V_44 ] * ( V_46 -> V_49 >> 16 ) ;
V_47 += V_7 -> V_39 [ V_44 ] * ( V_46 -> V_50 >> 16 ) ;
return V_47 ;
}
int F_25 ( struct V_51 * V_44 ,
struct V_45 * V_46 )
{
struct V_52 * V_52 ;
struct V_53 * V_54 ;
if ( ( V_44 -> V_46 -> V_7 == V_46 -> V_7 ) || ! V_46 -> V_7 )
return 0 ;
V_52 = F_23 ( V_46 -> V_7 , 0 ) -> V_11 . V_52 ;
if ( V_52 ) {
V_54 = F_26 ( V_52 -> V_55 ) ;
F_27 ( V_46 , V_54 ) ;
}
return 0 ;
}
static void F_28 ( struct V_6 * V_7 , struct V_56 * V_57 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
int V_9 ;
F_29 ( V_57 , L_3 , V_7 -> V_31 , V_7 -> V_33 ,
( char * ) & V_7 -> V_48 -> V_48 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_48 -> V_20 ; V_9 ++ ) {
F_29 ( V_57 , L_4 ,
V_9 , V_7 -> V_41 [ V_9 ] , V_7 -> V_39 [ V_9 ] ) ;
F_30 ( V_8 -> V_10 [ V_9 ] , V_57 ) ;
}
}
int F_31 ( struct V_56 * V_57 , void * V_58 )
{
struct V_59 * V_60 = (struct V_59 * ) V_57 -> V_61 ;
struct V_15 * V_16 = V_60 -> V_62 -> V_16 ;
struct V_6 * V_7 ;
F_32 ( & V_16 -> V_63 . V_64 ) ;
F_33 (fb, dev)
F_28 ( V_7 , V_57 ) ;
F_34 ( & V_16 -> V_63 . V_64 ) ;
return 0 ;
}
static int F_35 ( struct V_65 * V_27 , struct V_66 * V_67 )
{
return F_36 ( V_27 -> V_68 , V_67 , V_27 -> V_69 ,
V_27 -> V_70 . V_71 , V_27 -> V_70 . V_72 ) ;
}
static int F_37 ( struct V_65 * V_27 ,
struct V_66 * V_67 )
{
F_38 ( V_27 , V_67 ) ;
V_67 -> V_73 = F_39 ( V_67 -> V_73 ) ;
return 0 ;
}
static int F_40 ( struct V_65 * V_74 ,
struct V_19 * V_75 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
V_77 = F_11 ( sizeof( * V_77 ) , V_24 ) ;
V_79 = F_11 ( sizeof( * V_79 ) , V_24 ) ;
if ( ! V_77 || ! V_79 ) {
F_7 ( V_77 ) ;
F_7 ( V_79 ) ;
return - V_25 ;
}
V_74 -> V_80 = V_75 -> V_81 ;
V_74 -> V_70 . V_71 = F_41 ( F_42 ( V_74 -> V_80 ) ) ;
* V_79 = * V_74 -> V_79 ;
V_74 -> V_79 = V_79 ;
V_77 -> V_82 = F_43 ( V_83 ) ;
V_77 -> V_84 = V_85 ;
V_74 -> V_77 = V_77 ;
F_44 ( V_74 ) ;
V_74 -> V_79 -> V_86 = F_37 ;
return 0 ;
}
static void F_45 ( struct V_65 * V_74 )
{
if ( ! V_74 -> V_77 )
return;
F_46 ( V_74 ) ;
F_7 ( V_74 -> V_77 ) ;
F_7 ( V_74 -> V_79 ) ;
}
static int
F_47 ( struct V_2 * V_3 ,
struct V_87 * V_88 )
{
struct V_1 * V_89 = F_1 ( V_3 ) ;
struct V_17 V_18 = { 0 } ;
struct V_15 * V_16 = V_3 -> V_16 ;
struct V_19 * V_10 ;
struct V_6 * V_7 ;
unsigned int V_90 ;
unsigned long V_91 ;
struct V_65 * V_74 ;
T_2 V_42 ;
int V_23 ;
F_48 ( L_5 ,
V_88 -> V_92 , V_88 -> V_93 ,
V_88 -> V_94 ) ;
V_90 = F_49 ( V_88 -> V_94 , 8 ) ;
V_18 . V_31 = V_88 -> V_92 ;
V_18 . V_33 = V_88 -> V_93 ;
V_18 . V_39 [ 0 ] = V_88 -> V_92 * V_90 ;
V_18 . V_95 = F_50 ( V_88 -> V_94 ,
V_88 -> V_96 ) ;
V_42 = V_18 . V_39 [ 0 ] * V_18 . V_33 ;
V_10 = F_51 ( V_16 , V_42 ) ;
if ( F_20 ( V_10 ) )
return - V_25 ;
V_74 = F_52 ( V_3 ) ;
if ( F_20 ( V_74 ) ) {
V_23 = F_21 ( V_74 ) ;
goto V_97;
}
V_89 -> V_7 = F_10 ( V_16 , & V_18 , & V_10 , 1 ,
V_89 -> V_98 ) ;
if ( F_20 ( V_89 -> V_7 ) ) {
F_15 ( V_16 -> V_16 , L_6 ) ;
V_23 = F_21 ( V_89 -> V_7 ) ;
goto V_99;
}
V_7 = & V_89 -> V_7 -> V_7 ;
V_3 -> V_7 = V_7 ;
V_74 -> V_100 = V_3 ;
V_74 -> V_101 = V_102 ;
V_74 -> V_79 = & V_103 ;
F_53 ( V_74 , V_7 -> V_39 [ 0 ] , V_7 -> V_48 -> V_104 ) ;
F_54 ( V_74 , V_3 , V_88 -> V_105 , V_88 -> V_106 ) ;
V_91 = V_74 -> V_107 . V_108 * V_90 ;
V_91 += V_74 -> V_107 . V_109 * V_7 -> V_39 [ 0 ] ;
V_16 -> V_63 . V_110 = ( V_111 ) V_10 -> V_47 ;
V_74 -> V_69 = V_10 -> V_81 + V_91 ;
V_74 -> V_70 . V_71 = ( unsigned long ) ( V_10 -> V_47 + V_91 ) ;
V_74 -> V_112 = V_42 ;
V_74 -> V_70 . V_72 = V_42 ;
if ( V_89 -> V_98 -> V_113 ) {
V_23 = F_40 ( V_74 , V_10 ) ;
if ( V_23 )
goto V_114;
}
return 0 ;
V_114:
F_55 ( & V_89 -> V_7 -> V_7 ) ;
V_99:
F_56 ( V_3 ) ;
V_97:
F_5 ( & V_10 -> V_11 ) ;
return V_23 ;
}
struct V_1 * F_57 ( struct V_15 * V_16 ,
unsigned int V_115 , unsigned int V_116 ,
const struct V_21 * V_22 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_23 ;
V_89 = F_11 ( sizeof( * V_89 ) , V_24 ) ;
if ( ! V_89 ) {
F_15 ( V_16 -> V_16 , L_7 ) ;
return F_12 ( - V_25 ) ;
}
V_89 -> V_98 = V_22 ;
V_3 = & V_89 -> V_4 ;
F_58 ( V_16 , V_3 , & V_117 ) ;
V_23 = F_59 ( V_16 , V_3 , V_116 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_8 ) ;
goto V_118;
}
V_23 = F_60 ( V_3 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_9 ) ;
goto V_119;
}
V_23 = F_61 ( V_3 , V_115 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_10 ) ;
goto V_119;
}
return V_89 ;
V_119:
F_56 ( V_3 ) ;
V_118:
F_7 ( V_89 ) ;
return F_12 ( V_23 ) ;
}
struct V_1 * F_62 ( struct V_15 * V_16 ,
unsigned int V_115 , unsigned int V_116 )
{
return F_57 ( V_16 , V_115 ,
V_116 ,
& V_43 ) ;
}
void F_63 ( struct V_1 * V_89 )
{
F_64 ( & V_89 -> V_4 ) ;
if ( V_89 -> V_4 . V_120 )
F_45 ( V_89 -> V_4 . V_120 ) ;
if ( V_89 -> V_7 )
F_55 ( & V_89 -> V_7 -> V_7 ) ;
F_56 ( & V_89 -> V_4 ) ;
F_7 ( V_89 ) ;
}
void F_65 ( struct V_1 * V_89 )
{
if ( V_89 )
F_66 ( & V_89 -> V_4 ) ;
}
void F_67 ( struct V_1 * V_89 )
{
if ( V_89 )
F_68 ( & V_89 -> V_4 ) ;
}
void F_69 ( struct V_1 * V_89 , int V_46 )
{
if ( V_89 )
F_70 ( & V_89 -> V_4 , V_46 ) ;
}
void F_71 ( struct V_1 * V_89 ,
int V_46 )
{
if ( V_89 )
F_72 ( & V_89 -> V_4 ,
V_46 ) ;
}
