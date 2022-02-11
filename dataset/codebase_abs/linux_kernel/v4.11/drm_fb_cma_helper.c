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
V_27 = V_26 ( V_18 -> V_30 ) ;
if ( ! V_27 )
return F_12 ( - V_31 ) ;
for ( V_9 = 0 ; V_9 < V_27 -> V_20 ; V_9 ++ ) {
unsigned int V_32 = V_18 -> V_32 / ( V_9 ? V_27 -> V_33 : 1 ) ;
unsigned int V_34 = V_18 -> V_34 / ( V_9 ? V_27 -> V_35 : 1 ) ;
unsigned int V_36 ;
V_10 = F_17 ( V_13 , V_18 -> V_37 [ V_9 ] ) ;
if ( ! V_10 ) {
F_15 ( V_16 -> V_16 , L_2 ) ;
V_23 = - V_38 ;
goto V_39;
}
V_36 = ( V_34 - 1 ) * V_18 -> V_40 [ V_9 ]
+ V_32 * V_27 -> V_41 [ V_9 ]
+ V_18 -> V_42 [ V_9 ] ;
if ( V_10 -> V_43 < V_36 ) {
F_5 ( V_10 ) ;
V_23 = - V_31 ;
goto V_39;
}
V_28 [ V_9 ] = F_18 ( V_10 ) ;
}
V_8 = F_10 ( V_16 , V_18 , V_28 , V_9 , V_22 ) ;
if ( F_19 ( V_8 ) ) {
V_23 = F_20 ( V_8 ) ;
goto V_39;
}
return & V_8 -> V_7 ;
V_39:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_5 ( & V_28 [ V_9 ] -> V_11 ) ;
return F_12 ( V_23 ) ;
}
struct V_6 * F_21 ( struct V_15 * V_16 ,
struct V_12 * V_13 , const struct V_17 * V_18 )
{
return F_16 ( V_16 , V_13 , V_18 ,
& V_44 ) ;
}
struct V_19 * F_22 ( struct V_6 * V_7 ,
unsigned int V_45 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
if ( V_45 >= 4 )
return NULL ;
return V_8 -> V_10 [ V_45 ] ;
}
int F_23 ( struct V_46 * V_45 ,
struct V_47 * V_48 )
{
struct V_49 * V_49 ;
struct V_50 * V_51 ;
if ( ( V_45 -> V_48 -> V_7 == V_48 -> V_7 ) || ! V_48 -> V_7 )
return 0 ;
V_49 = F_22 ( V_48 -> V_7 , 0 ) -> V_11 . V_49 ;
if ( V_49 ) {
V_51 = F_24 ( V_49 -> V_52 ) ;
F_25 ( V_48 , V_51 ) ;
}
return 0 ;
}
static void F_26 ( struct V_6 * V_7 , struct V_53 * V_54 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
int V_9 ;
F_27 ( V_54 , L_3 , V_7 -> V_32 , V_7 -> V_34 ,
( char * ) & V_7 -> V_55 -> V_55 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_55 -> V_20 ; V_9 ++ ) {
F_27 ( V_54 , L_4 ,
V_9 , V_7 -> V_42 [ V_9 ] , V_7 -> V_40 [ V_9 ] ) ;
F_28 ( V_8 -> V_10 [ V_9 ] , V_54 ) ;
}
}
int F_29 ( struct V_53 * V_54 , void * V_56 )
{
struct V_57 * V_58 = (struct V_57 * ) V_54 -> V_59 ;
struct V_15 * V_16 = V_58 -> V_60 -> V_16 ;
struct V_6 * V_7 ;
F_30 ( & V_16 -> V_61 . V_62 ) ;
F_31 (fb, dev)
F_26 ( V_7 , V_54 ) ;
F_32 ( & V_16 -> V_61 . V_62 ) ;
return 0 ;
}
static int F_33 ( struct V_63 * V_27 , struct V_64 * V_65 )
{
return F_34 ( V_27 -> V_66 , V_65 , V_27 -> V_67 ,
V_27 -> V_68 . V_69 , V_27 -> V_68 . V_70 ) ;
}
static int F_35 ( struct V_63 * V_27 ,
struct V_64 * V_65 )
{
F_36 ( V_27 , V_65 ) ;
V_65 -> V_71 = F_37 ( V_65 -> V_71 ) ;
return 0 ;
}
static int F_38 ( struct V_63 * V_72 ,
struct V_19 * V_73 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 ;
V_75 = F_11 ( sizeof( * V_75 ) , V_24 ) ;
V_77 = F_11 ( sizeof( * V_77 ) , V_24 ) ;
if ( ! V_75 || ! V_77 ) {
F_7 ( V_75 ) ;
F_7 ( V_77 ) ;
return - V_25 ;
}
V_72 -> V_78 = V_73 -> V_79 ;
V_72 -> V_68 . V_69 = F_39 ( F_40 ( V_72 -> V_78 ) ) ;
* V_77 = * V_72 -> V_77 ;
V_72 -> V_77 = V_77 ;
V_75 -> V_80 = F_41 ( V_81 ) ;
V_75 -> V_82 = V_83 ;
V_72 -> V_75 = V_75 ;
F_42 ( V_72 ) ;
V_72 -> V_77 -> V_84 = F_35 ;
return 0 ;
}
static void F_43 ( struct V_63 * V_72 )
{
if ( ! V_72 -> V_75 )
return;
F_44 ( V_72 ) ;
F_7 ( V_72 -> V_75 ) ;
F_7 ( V_72 -> V_77 ) ;
}
static int
F_45 ( struct V_2 * V_3 ,
struct V_85 * V_86 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
struct V_17 V_18 = { 0 } ;
struct V_15 * V_16 = V_3 -> V_16 ;
struct V_19 * V_10 ;
struct V_6 * V_7 ;
unsigned int V_88 ;
unsigned long V_89 ;
struct V_63 * V_72 ;
T_1 V_43 ;
int V_23 ;
F_46 ( L_5 ,
V_86 -> V_90 , V_86 -> V_91 ,
V_86 -> V_92 ) ;
V_88 = F_47 ( V_86 -> V_92 , 8 ) ;
V_18 . V_32 = V_86 -> V_90 ;
V_18 . V_34 = V_86 -> V_91 ;
V_18 . V_40 [ 0 ] = V_86 -> V_90 * V_88 ;
V_18 . V_30 = F_48 ( V_86 -> V_92 ,
V_86 -> V_93 ) ;
V_43 = V_18 . V_40 [ 0 ] * V_18 . V_34 ;
V_10 = F_49 ( V_16 , V_43 ) ;
if ( F_19 ( V_10 ) )
return - V_25 ;
V_72 = F_50 ( V_3 ) ;
if ( F_19 ( V_72 ) ) {
V_23 = F_20 ( V_72 ) ;
goto V_94;
}
V_87 -> V_7 = F_10 ( V_16 , & V_18 , & V_10 , 1 ,
V_87 -> V_95 ) ;
if ( F_19 ( V_87 -> V_7 ) ) {
F_15 ( V_16 -> V_16 , L_6 ) ;
V_23 = F_20 ( V_87 -> V_7 ) ;
goto V_96;
}
V_7 = & V_87 -> V_7 -> V_7 ;
V_3 -> V_7 = V_7 ;
V_72 -> V_97 = V_3 ;
V_72 -> V_98 = V_99 ;
V_72 -> V_77 = & V_100 ;
F_51 ( V_72 , V_7 -> V_40 [ 0 ] , V_7 -> V_55 -> V_101 ) ;
F_52 ( V_72 , V_3 , V_86 -> V_102 , V_86 -> V_103 ) ;
V_89 = V_72 -> V_104 . V_105 * V_88 ;
V_89 += V_72 -> V_104 . V_106 * V_7 -> V_40 [ 0 ] ;
V_16 -> V_61 . V_107 = ( V_108 ) V_10 -> V_109 ;
V_72 -> V_67 = V_10 -> V_79 + V_89 ;
V_72 -> V_68 . V_69 = ( unsigned long ) ( V_10 -> V_109 + V_89 ) ;
V_72 -> V_110 = V_43 ;
V_72 -> V_68 . V_70 = V_43 ;
if ( V_87 -> V_95 -> V_111 ) {
V_23 = F_38 ( V_72 , V_10 ) ;
if ( V_23 )
goto V_112;
}
return 0 ;
V_112:
F_53 ( & V_87 -> V_7 -> V_7 ) ;
V_96:
F_54 ( V_3 ) ;
V_94:
F_5 ( & V_10 -> V_11 ) ;
return V_23 ;
}
struct V_1 * F_55 ( struct V_15 * V_16 ,
unsigned int V_113 , unsigned int V_114 ,
const struct V_21 * V_22 )
{
struct V_1 * V_87 ;
struct V_2 * V_3 ;
int V_23 ;
V_87 = F_11 ( sizeof( * V_87 ) , V_24 ) ;
if ( ! V_87 ) {
F_15 ( V_16 -> V_16 , L_7 ) ;
return F_12 ( - V_25 ) ;
}
V_87 -> V_95 = V_22 ;
V_3 = & V_87 -> V_4 ;
F_56 ( V_16 , V_3 , & V_115 ) ;
V_23 = F_57 ( V_16 , V_3 , V_114 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_8 ) ;
goto V_116;
}
V_23 = F_58 ( V_3 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_9 ) ;
goto V_117;
}
V_23 = F_59 ( V_3 , V_113 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_10 ) ;
goto V_117;
}
return V_87 ;
V_117:
F_60 ( V_3 ) ;
V_116:
F_7 ( V_87 ) ;
return F_12 ( V_23 ) ;
}
struct V_1 * F_61 ( struct V_15 * V_16 ,
unsigned int V_113 , unsigned int V_114 )
{
return F_55 ( V_16 , V_113 ,
V_114 ,
& V_44 ) ;
}
void F_62 ( struct V_1 * V_87 )
{
F_63 ( & V_87 -> V_4 ) ;
if ( V_87 -> V_4 . V_118 )
F_43 ( V_87 -> V_4 . V_118 ) ;
F_54 ( & V_87 -> V_4 ) ;
if ( V_87 -> V_7 )
F_53 ( & V_87 -> V_7 -> V_7 ) ;
F_60 ( & V_87 -> V_4 ) ;
F_7 ( V_87 ) ;
}
void F_64 ( struct V_1 * V_87 )
{
if ( V_87 )
F_65 ( & V_87 -> V_4 ) ;
}
void F_66 ( struct V_1 * V_87 )
{
if ( V_87 )
F_67 ( & V_87 -> V_4 ) ;
}
void F_68 ( struct V_1 * V_87 , int V_48 )
{
if ( V_87 )
F_69 ( & V_87 -> V_4 , V_48 ) ;
}
void F_70 ( struct V_1 * V_87 ,
int V_48 )
{
if ( V_87 )
F_71 ( & V_87 -> V_4 ,
V_48 ) ;
}
