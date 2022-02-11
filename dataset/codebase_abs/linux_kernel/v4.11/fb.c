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
if ( V_10 >= V_9 -> V_11 -> V_12 )
return NULL ;
return V_3 -> V_13 [ V_10 ] ;
}
bool F_5 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
if ( V_3 -> V_13 [ 0 ] -> V_14 & V_15 )
return true ;
return false ;
}
int F_6 ( struct V_2 * V_9 ,
struct V_16 * V_17 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
* V_17 = V_3 -> V_13 [ 0 ] -> V_17 ;
return 0 ;
}
static void F_7 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_12 ; V_18 ++ ) {
struct V_8 * V_19 = V_3 -> V_13 [ V_18 ] ;
if ( V_19 ) {
if ( V_19 -> V_20 )
F_8 ( V_19 -> V_21 ) ;
F_9 ( & V_19 -> V_22 ) ;
}
}
F_10 ( V_9 ) ;
F_11 ( V_3 -> V_13 ) ;
F_11 ( V_3 ) ;
}
static int F_12 ( struct V_2 * V_9 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
return F_13 ( V_24 , & V_3 -> V_13 [ 0 ] -> V_22 , V_25 ) ;
}
static struct V_1 * F_14 ( struct V_26 * V_27 ,
const struct V_28 * V_29 ,
struct V_8 * * V_13 ,
unsigned int V_12 )
{
struct V_1 * V_3 ;
unsigned int V_18 ;
int V_30 ;
V_3 = F_15 ( sizeof( * V_3 ) , V_31 ) ;
if ( ! V_3 )
return F_16 ( - V_32 ) ;
V_3 -> V_13 = F_15 ( V_12 * sizeof( * V_13 ) , V_31 ) ;
if ( ! V_3 -> V_13 ) {
F_11 ( V_3 ) ;
return F_16 ( - V_32 ) ;
}
V_3 -> V_12 = V_12 ;
F_17 ( V_27 , & V_3 -> V_4 , V_29 ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_12 ; V_18 ++ )
V_3 -> V_13 [ V_18 ] = V_13 [ V_18 ] ;
V_30 = F_18 ( V_27 , & V_3 -> V_4 , & V_33 ) ;
if ( V_30 < 0 ) {
F_19 ( V_27 -> V_34 , L_1 ,
V_30 ) ;
F_11 ( V_3 -> V_13 ) ;
F_11 ( V_3 ) ;
return F_16 ( V_30 ) ;
}
return V_3 ;
}
struct V_2 * F_20 ( struct V_26 * V_27 ,
struct V_23 * V_24 ,
const struct V_28 * V_35 )
{
unsigned int V_36 , V_37 , V_18 ;
struct V_8 * V_13 [ 4 ] ;
struct V_38 * V_22 ;
struct V_1 * V_3 ;
int V_30 ;
V_36 = F_21 ( V_35 -> V_39 ) ;
V_37 = F_22 ( V_35 -> V_39 ) ;
for ( V_18 = 0 ; V_18 < F_23 ( V_35 -> V_39 ) ; V_18 ++ ) {
unsigned int V_40 = V_35 -> V_40 / ( V_18 ? V_36 : 1 ) ;
unsigned int V_41 = V_35 -> V_41 / ( V_18 ? V_37 : 1 ) ;
unsigned int V_42 , V_43 ;
V_22 = F_24 ( V_24 , V_35 -> V_44 [ V_18 ] ) ;
if ( ! V_22 ) {
V_30 = - V_45 ;
goto V_46;
}
V_43 = F_25 ( V_35 -> V_39 , V_18 ) ;
V_42 = ( V_41 - 1 ) * V_35 -> V_47 [ V_18 ] +
V_40 * V_43 + V_35 -> V_48 [ V_18 ] ;
if ( V_22 -> V_42 < V_42 ) {
V_30 = - V_49 ;
goto V_46;
}
V_13 [ V_18 ] = F_26 ( V_22 ) ;
}
V_3 = F_14 ( V_27 , V_35 , V_13 , V_18 ) ;
if ( F_27 ( V_3 ) ) {
V_30 = F_28 ( V_3 ) ;
goto V_46;
}
return & V_3 -> V_4 ;
V_46:
while ( V_18 -- )
F_9 ( & V_13 [ V_18 ] -> V_22 ) ;
return F_16 ( V_30 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_50 * V_51 )
{
struct V_5 * V_52 = F_3 ( V_7 ) ;
struct V_53 * V_54 = V_7 -> V_34 -> V_55 ;
struct V_26 * V_27 = V_7 -> V_34 ;
struct V_28 V_35 = { 0 } ;
unsigned int V_56 ;
struct V_2 * V_3 ;
unsigned long V_57 ;
struct V_58 * V_59 ;
struct V_8 * V_19 ;
T_1 V_42 ;
int V_30 ;
V_56 = F_30 ( V_51 -> V_60 , 8 ) ;
V_35 . V_40 = V_51 -> V_61 ;
V_35 . V_41 = V_51 -> V_62 ;
V_35 . V_47 [ 0 ] = F_31 ( V_51 -> V_61 * V_56 ,
V_54 -> V_63 ) ;
V_35 . V_39 = F_32 ( V_51 -> V_60 ,
V_51 -> V_64 ) ;
V_42 = V_35 . V_47 [ 0 ] * V_35 . V_41 ;
V_19 = F_33 ( V_27 , V_42 , 0 ) ;
if ( F_27 ( V_19 ) )
return F_28 ( V_19 ) ;
V_59 = F_34 ( V_7 ) ;
if ( F_27 ( V_59 ) ) {
F_19 ( V_27 -> V_34 , L_2 ) ;
F_9 ( & V_19 -> V_22 ) ;
return F_28 ( V_59 ) ;
}
V_52 -> V_3 = F_14 ( V_27 , & V_35 , & V_19 , 1 ) ;
if ( F_27 ( V_52 -> V_3 ) ) {
V_30 = F_28 ( V_52 -> V_3 ) ;
F_19 ( V_27 -> V_34 , L_3 ,
V_30 ) ;
F_9 ( & V_19 -> V_22 ) ;
goto V_65;
}
V_3 = & V_52 -> V_3 -> V_4 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_52 = V_59 ;
V_59 -> V_66 = V_7 ;
V_59 -> V_14 = V_67 ;
V_59 -> V_68 = & V_69 ;
F_35 ( V_59 , V_3 -> V_47 [ 0 ] , V_3 -> V_11 -> V_70 ) ;
F_36 ( V_59 , V_7 , V_3 -> V_40 , V_3 -> V_41 ) ;
V_57 = V_59 -> V_71 . V_72 * V_56 +
V_59 -> V_71 . V_73 * V_3 -> V_47 [ 0 ] ;
if ( V_19 -> V_20 ) {
V_19 -> V_21 = F_37 ( V_19 -> V_20 , V_19 -> V_74 , V_75 ,
F_38 ( V_76 ) ) ;
if ( ! V_19 -> V_21 ) {
F_19 ( V_27 -> V_34 , L_4 ) ;
V_30 = - V_32 ;
goto V_77;
}
}
V_27 -> V_78 . V_79 = ( V_80 ) V_19 -> V_81 ;
V_59 -> V_82 = ( void V_83 * ) V_19 -> V_21 + V_57 ;
V_59 -> V_84 = V_42 ;
V_59 -> V_85 . V_86 = ( unsigned long ) ( V_19 -> V_81 + V_57 ) ;
V_59 -> V_85 . V_87 = V_42 ;
return 0 ;
V_77:
F_39 ( V_3 ) ;
V_65:
F_40 ( V_7 ) ;
return V_30 ;
}
static struct V_5 * F_41 ( struct V_26 * V_27 )
{
struct V_5 * V_52 ;
V_52 = F_15 ( sizeof( * V_52 ) , V_31 ) ;
if ( ! V_52 ) {
F_19 ( V_27 -> V_34 , L_5 ) ;
return F_16 ( - V_32 ) ;
}
F_42 ( V_27 , & V_52 -> V_4 , & V_88 ) ;
return V_52 ;
}
static void F_43 ( struct V_5 * V_52 )
{
F_11 ( V_52 ) ;
}
static int F_44 ( struct V_5 * V_52 ,
unsigned int V_89 ,
unsigned int V_90 ,
unsigned int V_91 )
{
struct V_26 * V_27 = V_52 -> V_4 . V_34 ;
int V_30 ;
V_30 = F_45 ( V_27 , & V_52 -> V_4 , V_91 ) ;
if ( V_30 < 0 ) {
F_19 ( V_27 -> V_34 , L_6 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_46 ( & V_52 -> V_4 ) ;
if ( V_30 < 0 ) {
F_19 ( V_27 -> V_34 , L_7 , V_30 ) ;
goto V_92;
}
V_30 = F_47 ( & V_52 -> V_4 , V_89 ) ;
if ( V_30 < 0 ) {
F_19 ( V_27 -> V_34 , L_8 ,
V_30 ) ;
goto V_92;
}
return 0 ;
V_92:
F_48 ( & V_52 -> V_4 ) ;
return V_30 ;
}
static void F_49 ( struct V_5 * V_52 )
{
F_50 ( & V_52 -> V_4 ) ;
F_40 ( & V_52 -> V_4 ) ;
if ( V_52 -> V_3 )
F_39 ( & V_52 -> V_3 -> V_4 ) ;
F_48 ( & V_52 -> V_4 ) ;
F_43 ( V_52 ) ;
}
void F_51 ( struct V_5 * V_52 )
{
if ( V_52 )
F_52 ( & V_52 -> V_4 ) ;
}
void F_53 ( struct V_26 * V_27 )
{
struct V_53 * V_54 = V_27 -> V_55 ;
if ( V_54 -> V_52 )
F_54 ( & V_54 -> V_52 -> V_4 ) ;
}
int F_55 ( struct V_26 * V_27 )
{
#ifdef F_56
struct V_53 * V_54 = V_27 -> V_55 ;
V_54 -> V_52 = F_41 ( V_27 ) ;
if ( F_27 ( V_54 -> V_52 ) )
return F_28 ( V_54 -> V_52 ) ;
#endif
return 0 ;
}
void F_57 ( struct V_26 * V_27 )
{
#ifdef F_56
struct V_53 * V_54 = V_27 -> V_55 ;
F_43 ( V_54 -> V_52 ) ;
#endif
}
int F_58 ( struct V_26 * V_27 )
{
#ifdef F_56
struct V_53 * V_54 = V_27 -> V_55 ;
int V_30 ;
V_30 = F_44 ( V_54 -> V_52 , 32 , V_27 -> V_78 . V_90 ,
V_27 -> V_78 . V_93 ) ;
if ( V_30 < 0 )
return V_30 ;
#endif
return 0 ;
}
void F_59 ( struct V_26 * V_27 )
{
#ifdef F_56
struct V_53 * V_54 = V_27 -> V_55 ;
F_49 ( V_54 -> V_52 ) ;
#endif
}
void F_60 ( struct V_26 * V_27 )
{
#ifdef F_56
struct V_53 * V_54 = V_27 -> V_55 ;
F_61 () ;
F_62 ( & V_54 -> V_52 -> V_4 , 1 ) ;
F_63 () ;
#endif
}
void F_64 ( struct V_26 * V_27 )
{
#ifdef F_56
struct V_53 * V_54 = V_27 -> V_55 ;
F_61 () ;
F_62 ( & V_54 -> V_52 -> V_4 , 0 ) ;
F_63 () ;
#endif
}
