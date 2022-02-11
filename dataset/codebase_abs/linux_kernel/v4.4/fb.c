static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
struct V_8 * F_4 ( struct V_2 * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
if ( V_10 >= F_5 ( V_9 -> V_11 ) )
return NULL ;
return V_3 -> V_12 [ V_10 ] ;
}
bool F_6 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
if ( V_3 -> V_12 [ 0 ] -> V_13 & V_14 )
return true ;
return false ;
}
int F_7 ( struct V_2 * V_9 ,
struct V_15 * V_16 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
* V_16 = V_3 -> V_12 [ 0 ] -> V_16 ;
return 0 ;
}
static void F_8 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_3 -> V_18 ; V_17 ++ ) {
struct V_8 * V_19 = V_3 -> V_12 [ V_17 ] ;
if ( V_19 ) {
if ( V_19 -> V_20 && V_19 -> V_21 )
F_9 ( V_19 -> V_21 ) ;
F_10 ( & V_19 -> V_22 ) ;
}
}
F_11 ( V_9 ) ;
F_12 ( V_3 -> V_12 ) ;
F_12 ( V_3 ) ;
}
static int F_13 ( struct V_2 * V_9 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
return F_14 ( V_24 , & V_3 -> V_12 [ 0 ] -> V_22 , V_25 ) ;
}
static struct V_1 * F_15 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_8 * * V_12 ,
unsigned int V_18 )
{
struct V_1 * V_3 ;
unsigned int V_17 ;
int V_30 ;
V_3 = F_16 ( sizeof( * V_3 ) , V_31 ) ;
if ( ! V_3 )
return F_17 ( - V_32 ) ;
V_3 -> V_12 = F_16 ( V_18 * sizeof( * V_12 ) , V_31 ) ;
if ( ! V_3 -> V_12 ) {
F_12 ( V_3 ) ;
return F_17 ( - V_32 ) ;
}
V_3 -> V_18 = V_18 ;
F_18 ( & V_3 -> V_4 , V_29 ) ;
for ( V_17 = 0 ; V_17 < V_3 -> V_18 ; V_17 ++ )
V_3 -> V_12 [ V_17 ] = V_12 [ V_17 ] ;
V_30 = F_19 ( V_27 , & V_3 -> V_4 , & V_33 ) ;
if ( V_30 < 0 ) {
F_20 ( V_27 -> V_34 , L_1 ,
V_30 ) ;
F_12 ( V_3 -> V_12 ) ;
F_12 ( V_3 ) ;
return F_17 ( V_30 ) ;
}
return V_3 ;
}
struct V_2 * F_21 ( struct V_26 * V_27 ,
struct V_23 * V_24 ,
struct V_28 * V_35 )
{
unsigned int V_36 , V_37 , V_17 ;
struct V_8 * V_12 [ 4 ] ;
struct V_38 * V_22 ;
struct V_1 * V_3 ;
int V_30 ;
V_36 = F_22 ( V_35 -> V_11 ) ;
V_37 = F_23 ( V_35 -> V_11 ) ;
for ( V_17 = 0 ; V_17 < F_5 ( V_35 -> V_11 ) ; V_17 ++ ) {
unsigned int V_39 = V_35 -> V_39 / ( V_17 ? V_36 : 1 ) ;
unsigned int V_40 = V_35 -> V_40 / ( V_17 ? V_37 : 1 ) ;
unsigned int V_41 , V_42 ;
V_22 = F_24 ( V_27 , V_24 , V_35 -> V_43 [ V_17 ] ) ;
if ( ! V_22 ) {
V_30 = - V_44 ;
goto V_45;
}
V_42 = F_25 ( V_35 -> V_11 , V_17 ) ;
V_41 = ( V_40 - 1 ) * V_35 -> V_46 [ V_17 ] +
V_39 * V_42 + V_35 -> V_47 [ V_17 ] ;
if ( V_22 -> V_41 < V_41 ) {
V_30 = - V_48 ;
goto V_45;
}
V_12 [ V_17 ] = F_26 ( V_22 ) ;
}
V_3 = F_15 ( V_27 , V_35 , V_12 , V_17 ) ;
if ( F_27 ( V_3 ) ) {
V_30 = F_28 ( V_3 ) ;
goto V_45;
}
return & V_3 -> V_4 ;
V_45:
while ( V_17 -- )
F_10 ( & V_12 [ V_17 ] -> V_22 ) ;
return F_17 ( V_30 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_49 * V_50 )
{
struct V_5 * V_51 = F_3 ( V_7 ) ;
struct V_52 * V_53 = V_7 -> V_34 -> V_54 ;
struct V_26 * V_27 = V_7 -> V_34 ;
struct V_28 V_35 = { 0 } ;
unsigned int V_55 ;
struct V_2 * V_3 ;
unsigned long V_56 ;
struct V_57 * V_58 ;
struct V_8 * V_19 ;
T_1 V_41 ;
int V_30 ;
V_55 = F_30 ( V_50 -> V_59 , 8 ) ;
V_35 . V_39 = V_50 -> V_60 ;
V_35 . V_40 = V_50 -> V_61 ;
V_35 . V_46 [ 0 ] = F_31 ( V_50 -> V_60 * V_55 ,
V_53 -> V_62 ) ;
V_35 . V_11 = F_32 ( V_50 -> V_59 ,
V_50 -> V_63 ) ;
V_41 = V_35 . V_46 [ 0 ] * V_35 . V_40 ;
V_19 = F_33 ( V_27 , V_41 , 0 ) ;
if ( F_27 ( V_19 ) )
return F_28 ( V_19 ) ;
V_58 = F_34 ( V_7 ) ;
if ( F_27 ( V_58 ) ) {
F_20 ( V_27 -> V_34 , L_2 ) ;
F_10 ( & V_19 -> V_22 ) ;
return F_28 ( V_58 ) ;
}
V_51 -> V_3 = F_15 ( V_27 , & V_35 , & V_19 , 1 ) ;
if ( F_27 ( V_51 -> V_3 ) ) {
V_30 = F_28 ( V_51 -> V_3 ) ;
F_20 ( V_27 -> V_34 , L_3 ,
V_30 ) ;
F_10 ( & V_19 -> V_22 ) ;
goto V_64;
}
V_3 = & V_51 -> V_3 -> V_4 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_51 = V_58 ;
V_58 -> V_65 = V_7 ;
V_58 -> V_13 = V_66 ;
V_58 -> V_67 = & V_68 ;
F_35 ( V_58 , V_3 -> V_46 [ 0 ] , V_3 -> V_69 ) ;
F_36 ( V_58 , V_7 , V_3 -> V_39 , V_3 -> V_40 ) ;
V_56 = V_58 -> V_70 . V_71 * V_55 +
V_58 -> V_70 . V_72 * V_3 -> V_46 [ 0 ] ;
if ( V_19 -> V_20 ) {
V_19 -> V_21 = F_37 ( V_19 -> V_20 , V_19 -> V_73 , V_74 ,
F_38 ( V_75 ) ) ;
if ( ! V_19 -> V_21 ) {
F_20 ( V_27 -> V_34 , L_4 ) ;
V_30 = - V_32 ;
goto V_76;
}
}
V_27 -> V_77 . V_78 = ( V_79 ) V_19 -> V_80 ;
V_58 -> V_81 = ( void V_82 * ) V_19 -> V_21 + V_56 ;
V_58 -> V_83 = V_41 ;
V_58 -> V_84 . V_85 = ( unsigned long ) ( V_19 -> V_80 + V_56 ) ;
V_58 -> V_84 . V_86 = V_41 ;
return 0 ;
V_76:
F_39 ( V_3 ) ;
F_8 ( V_3 ) ;
V_64:
F_40 ( V_7 ) ;
return V_30 ;
}
static struct V_5 * F_41 ( struct V_26 * V_27 )
{
struct V_5 * V_51 ;
V_51 = F_16 ( sizeof( * V_51 ) , V_31 ) ;
if ( ! V_51 ) {
F_20 ( V_27 -> V_34 , L_5 ) ;
return F_17 ( - V_32 ) ;
}
F_42 ( V_27 , & V_51 -> V_4 , & V_87 ) ;
return V_51 ;
}
static void F_43 ( struct V_5 * V_51 )
{
F_12 ( V_51 ) ;
}
static int F_44 ( struct V_5 * V_51 ,
unsigned int V_88 ,
unsigned int V_89 ,
unsigned int V_90 )
{
struct V_26 * V_27 = V_51 -> V_4 . V_34 ;
int V_30 ;
V_30 = F_45 ( V_27 , & V_51 -> V_4 , V_89 , V_90 ) ;
if ( V_30 < 0 ) {
F_20 ( V_27 -> V_34 , L_6 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_46 ( & V_51 -> V_4 ) ;
if ( V_30 < 0 ) {
F_20 ( V_27 -> V_34 , L_7 , V_30 ) ;
goto V_91;
}
V_30 = F_47 ( & V_51 -> V_4 , V_88 ) ;
if ( V_30 < 0 ) {
F_20 ( V_27 -> V_34 , L_8 ,
V_30 ) ;
goto V_91;
}
return 0 ;
V_91:
F_48 ( & V_51 -> V_4 ) ;
return V_30 ;
}
static void F_49 ( struct V_5 * V_51 )
{
F_50 ( & V_51 -> V_4 ) ;
F_40 ( & V_51 -> V_4 ) ;
if ( V_51 -> V_3 ) {
F_39 ( & V_51 -> V_3 -> V_4 ) ;
F_51 ( & V_51 -> V_3 -> V_4 ) ;
}
F_48 ( & V_51 -> V_4 ) ;
F_43 ( V_51 ) ;
}
void F_52 ( struct V_5 * V_51 )
{
if ( V_51 )
F_53 ( & V_51 -> V_4 ) ;
}
void F_54 ( struct V_26 * V_27 )
{
struct V_52 * V_53 = V_27 -> V_54 ;
if ( V_53 -> V_51 )
F_55 ( & V_53 -> V_51 -> V_4 ) ;
}
int F_56 ( struct V_26 * V_27 )
{
#ifdef F_57
struct V_52 * V_53 = V_27 -> V_54 ;
V_53 -> V_51 = F_41 ( V_27 ) ;
if ( F_27 ( V_53 -> V_51 ) )
return F_28 ( V_53 -> V_51 ) ;
#endif
return 0 ;
}
void F_58 ( struct V_26 * V_27 )
{
#ifdef F_57
struct V_52 * V_53 = V_27 -> V_54 ;
F_43 ( V_53 -> V_51 ) ;
#endif
}
int F_59 ( struct V_26 * V_27 )
{
#ifdef F_57
struct V_52 * V_53 = V_27 -> V_54 ;
int V_30 ;
V_30 = F_44 ( V_53 -> V_51 , 32 , V_27 -> V_77 . V_89 ,
V_27 -> V_77 . V_92 ) ;
if ( V_30 < 0 )
return V_30 ;
#endif
return 0 ;
}
void F_60 ( struct V_26 * V_27 )
{
#ifdef F_57
struct V_52 * V_53 = V_27 -> V_54 ;
F_49 ( V_53 -> V_51 ) ;
#endif
}
