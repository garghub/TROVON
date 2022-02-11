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
F_13 ( & V_8 -> V_7 , V_18 ) ;
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
struct V_5 * V_8 ;
struct V_19 * V_26 [ 4 ] ;
struct V_27 * V_10 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_23 ;
int V_9 ;
V_28 = F_17 ( V_18 -> V_30 ) ;
V_29 = F_18 ( V_18 -> V_30 ) ;
for ( V_9 = 0 ; V_9 < F_19 ( V_18 -> V_30 ) ; V_9 ++ ) {
unsigned int V_31 = V_18 -> V_31 / ( V_9 ? V_28 : 1 ) ;
unsigned int V_32 = V_18 -> V_32 / ( V_9 ? V_29 : 1 ) ;
unsigned int V_33 ;
V_10 = F_20 ( V_13 , V_18 -> V_34 [ V_9 ] ) ;
if ( ! V_10 ) {
F_15 ( V_16 -> V_16 , L_2 ) ;
V_23 = - V_35 ;
goto V_36;
}
V_33 = ( V_32 - 1 ) * V_18 -> V_37 [ V_9 ]
+ V_31 * F_21 ( V_18 -> V_30 , V_9 )
+ V_18 -> V_38 [ V_9 ] ;
if ( V_10 -> V_39 < V_33 ) {
F_5 ( V_10 ) ;
V_23 = - V_40 ;
goto V_36;
}
V_26 [ V_9 ] = F_22 ( V_10 ) ;
}
V_8 = F_10 ( V_16 , V_18 , V_26 , V_9 , V_22 ) ;
if ( F_23 ( V_8 ) ) {
V_23 = F_24 ( V_8 ) ;
goto V_36;
}
return & V_8 -> V_7 ;
V_36:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_5 ( & V_26 [ V_9 ] -> V_11 ) ;
return F_12 ( V_23 ) ;
}
struct V_6 * F_25 ( struct V_15 * V_16 ,
struct V_12 * V_13 , const struct V_17 * V_18 )
{
return F_16 ( V_16 , V_13 , V_18 ,
& V_41 ) ;
}
struct V_19 * F_26 ( struct V_6 * V_7 ,
unsigned int V_42 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
if ( V_42 >= 4 )
return NULL ;
return V_8 -> V_10 [ V_42 ] ;
}
static void F_27 ( struct V_6 * V_7 , struct V_43 * V_44 )
{
struct V_5 * V_8 = F_3 ( V_7 ) ;
int V_9 , V_45 = F_19 ( V_7 -> V_30 ) ;
F_28 ( V_44 , L_3 , V_7 -> V_31 , V_7 -> V_32 ,
( char * ) & V_7 -> V_30 ) ;
for ( V_9 = 0 ; V_9 < V_45 ; V_9 ++ ) {
F_28 ( V_44 , L_4 ,
V_9 , V_7 -> V_38 [ V_9 ] , V_7 -> V_37 [ V_9 ] ) ;
F_29 ( V_8 -> V_10 [ V_9 ] , V_44 ) ;
}
}
int F_30 ( struct V_43 * V_44 , void * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
struct V_15 * V_16 = V_48 -> V_50 -> V_16 ;
struct V_6 * V_7 ;
F_31 ( & V_16 -> V_51 . V_52 ) ;
F_32 (fb, dev)
F_27 ( V_7 , V_44 ) ;
F_33 ( & V_16 -> V_51 . V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
F_35 ( V_54 , V_56 ) ;
V_56 -> V_57 = F_36 ( V_56 -> V_57 ) ;
return 0 ;
}
static int F_37 ( struct V_53 * V_58 ,
struct V_19 * V_59 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
V_61 = F_11 ( sizeof( * V_61 ) , V_24 ) ;
V_63 = F_11 ( sizeof( * V_63 ) , V_24 ) ;
if ( ! V_61 || ! V_63 ) {
F_7 ( V_61 ) ;
return - V_25 ;
}
V_58 -> V_64 = V_59 -> V_65 ;
V_58 -> V_66 . V_67 = F_38 ( F_39 ( V_58 -> V_64 ) ) ;
* V_63 = * V_58 -> V_63 ;
V_58 -> V_63 = V_63 ;
V_61 -> V_68 = F_40 ( V_69 ) ;
V_61 -> V_70 = V_71 ;
V_58 -> V_61 = V_61 ;
F_41 ( V_58 ) ;
V_58 -> V_63 -> V_72 = F_34 ;
return 0 ;
}
static void F_42 ( struct V_53 * V_58 )
{
if ( ! V_58 -> V_61 )
return;
F_43 ( V_58 ) ;
F_7 ( V_58 -> V_61 ) ;
F_7 ( V_58 -> V_63 ) ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_73 * V_74 ,
const struct V_21 * V_22 )
{
struct V_1 * V_75 = F_1 ( V_3 ) ;
struct V_17 V_18 = { 0 } ;
struct V_15 * V_16 = V_3 -> V_16 ;
struct V_19 * V_10 ;
struct V_6 * V_7 ;
unsigned int V_76 ;
unsigned long V_77 ;
struct V_53 * V_58 ;
T_1 V_39 ;
int V_23 ;
F_45 ( L_5 ,
V_74 -> V_78 , V_74 -> V_79 ,
V_74 -> V_80 ) ;
V_76 = F_46 ( V_74 -> V_80 , 8 ) ;
V_18 . V_31 = V_74 -> V_78 ;
V_18 . V_32 = V_74 -> V_79 ;
V_18 . V_37 [ 0 ] = V_74 -> V_78 * V_76 ;
V_18 . V_30 = F_47 ( V_74 -> V_80 ,
V_74 -> V_81 ) ;
V_39 = V_18 . V_37 [ 0 ] * V_18 . V_32 ;
V_10 = F_48 ( V_16 , V_39 ) ;
if ( F_23 ( V_10 ) )
return - V_25 ;
V_58 = F_49 ( V_3 ) ;
if ( F_23 ( V_58 ) ) {
V_23 = F_24 ( V_58 ) ;
goto V_82;
}
V_75 -> V_7 = F_10 ( V_16 , & V_18 , & V_10 , 1 , V_22 ) ;
if ( F_23 ( V_75 -> V_7 ) ) {
F_15 ( V_16 -> V_16 , L_6 ) ;
V_23 = F_24 ( V_75 -> V_7 ) ;
goto V_83;
}
V_7 = & V_75 -> V_7 -> V_7 ;
V_3 -> V_7 = V_7 ;
V_58 -> V_84 = V_3 ;
V_58 -> V_85 = V_86 ;
V_58 -> V_63 = & V_87 ;
F_50 ( V_58 , V_7 -> V_37 [ 0 ] , V_7 -> V_88 ) ;
F_51 ( V_58 , V_3 , V_74 -> V_89 , V_74 -> V_90 ) ;
V_77 = V_58 -> V_91 . V_92 * V_76 ;
V_77 += V_58 -> V_91 . V_93 * V_7 -> V_37 [ 0 ] ;
V_16 -> V_51 . V_94 = ( V_95 ) V_10 -> V_96 ;
V_58 -> V_97 = V_10 -> V_65 + V_77 ;
V_58 -> V_66 . V_67 = ( unsigned long ) ( V_10 -> V_96 + V_77 ) ;
V_58 -> V_98 = V_39 ;
V_58 -> V_66 . V_99 = V_39 ;
if ( V_22 -> V_100 ) {
V_23 = F_37 ( V_58 , V_10 ) ;
if ( V_23 )
goto V_101;
}
return 0 ;
V_101:
F_52 ( & V_75 -> V_7 -> V_7 ) ;
F_4 ( & V_75 -> V_7 -> V_7 ) ;
V_83:
F_53 ( V_3 ) ;
V_82:
F_5 ( & V_10 -> V_11 ) ;
return V_23 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
return F_44 ( V_3 , V_74 , & V_41 ) ;
}
struct V_1 * F_55 ( struct V_15 * V_16 ,
unsigned int V_102 , unsigned int V_103 ,
unsigned int V_104 , const struct V_105 * V_22 )
{
struct V_1 * V_75 ;
struct V_2 * V_3 ;
int V_23 ;
V_75 = F_11 ( sizeof( * V_75 ) , V_24 ) ;
if ( ! V_75 ) {
F_15 ( V_16 -> V_16 , L_7 ) ;
return F_12 ( - V_25 ) ;
}
V_3 = & V_75 -> V_4 ;
F_56 ( V_16 , V_3 , V_22 ) ;
V_23 = F_57 ( V_16 , V_3 , V_103 , V_104 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_8 ) ;
goto V_106;
}
V_23 = F_58 ( V_3 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_9 ) ;
goto V_107;
}
V_23 = F_59 ( V_3 , V_102 ) ;
if ( V_23 < 0 ) {
F_15 ( V_16 -> V_16 , L_10 ) ;
goto V_107;
}
return V_75 ;
V_107:
F_60 ( V_3 ) ;
V_106:
F_7 ( V_75 ) ;
return F_12 ( V_23 ) ;
}
struct V_1 * F_61 ( struct V_15 * V_16 ,
unsigned int V_102 , unsigned int V_103 ,
unsigned int V_104 )
{
return F_55 ( V_16 , V_102 , V_103 ,
V_104 , & V_108 ) ;
}
void F_62 ( struct V_1 * V_75 )
{
F_63 ( & V_75 -> V_4 ) ;
F_42 ( V_75 -> V_4 . V_109 ) ;
F_53 ( & V_75 -> V_4 ) ;
if ( V_75 -> V_7 ) {
F_52 ( & V_75 -> V_7 -> V_7 ) ;
F_4 ( & V_75 -> V_7 -> V_7 ) ;
}
F_60 ( & V_75 -> V_4 ) ;
F_7 ( V_75 ) ;
}
void F_64 ( struct V_1 * V_75 )
{
if ( V_75 )
F_65 ( & V_75 -> V_4 ) ;
}
void F_66 ( struct V_1 * V_75 )
{
if ( V_75 )
F_67 ( & V_75 -> V_4 ) ;
}
