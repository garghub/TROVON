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
if ( V_19 )
F_9 ( & V_19 -> V_20 ) ;
}
F_10 ( V_9 ) ;
F_11 ( V_3 -> V_12 ) ;
F_11 ( V_3 ) ;
}
static int F_12 ( struct V_2 * V_9 ,
struct V_21 * V_22 , unsigned int * V_23 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
return F_13 ( V_22 , & V_3 -> V_12 [ 0 ] -> V_20 , V_23 ) ;
}
static struct V_1 * F_14 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
struct V_8 * * V_12 ,
unsigned int V_18 )
{
struct V_1 * V_3 ;
unsigned int V_17 ;
int V_28 ;
V_3 = F_15 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
return F_16 ( - V_30 ) ;
V_3 -> V_12 = F_15 ( V_18 * sizeof( * V_12 ) , V_29 ) ;
if ( ! V_3 -> V_12 ) {
F_11 ( V_3 ) ;
return F_16 ( - V_30 ) ;
}
V_3 -> V_18 = V_18 ;
F_17 ( & V_3 -> V_4 , V_27 ) ;
for ( V_17 = 0 ; V_17 < V_3 -> V_18 ; V_17 ++ )
V_3 -> V_12 [ V_17 ] = V_12 [ V_17 ] ;
V_28 = F_18 ( V_25 , & V_3 -> V_4 , & V_31 ) ;
if ( V_28 < 0 ) {
F_19 ( V_25 -> V_32 , L_1 ,
V_28 ) ;
F_11 ( V_3 -> V_12 ) ;
F_11 ( V_3 ) ;
return F_16 ( V_28 ) ;
}
return V_3 ;
}
static struct V_2 * F_20 ( struct V_24 * V_25 ,
struct V_21 * V_22 ,
struct V_26 * V_33 )
{
unsigned int V_34 , V_35 , V_17 ;
struct V_8 * V_12 [ 4 ] ;
struct V_36 * V_20 ;
struct V_1 * V_3 ;
int V_28 ;
V_34 = F_21 ( V_33 -> V_11 ) ;
V_35 = F_22 ( V_33 -> V_11 ) ;
for ( V_17 = 0 ; V_17 < F_5 ( V_33 -> V_11 ) ; V_17 ++ ) {
unsigned int V_37 = V_33 -> V_37 / ( V_17 ? V_34 : 1 ) ;
unsigned int V_38 = V_33 -> V_38 / ( V_17 ? V_35 : 1 ) ;
unsigned int V_39 , V_40 ;
V_20 = F_23 ( V_25 , V_22 , V_33 -> V_41 [ V_17 ] ) ;
if ( ! V_20 ) {
V_28 = - V_42 ;
goto V_43;
}
V_40 = F_24 ( V_33 -> V_11 , V_17 ) ;
V_39 = ( V_38 - 1 ) * V_33 -> V_44 [ V_17 ] +
V_37 * V_40 + V_33 -> V_45 [ V_17 ] ;
if ( V_20 -> V_39 < V_39 ) {
V_28 = - V_46 ;
goto V_43;
}
V_12 [ V_17 ] = F_25 ( V_20 ) ;
}
V_3 = F_14 ( V_25 , V_33 , V_12 , V_17 ) ;
if ( F_26 ( V_3 ) ) {
V_28 = F_27 ( V_3 ) ;
goto V_43;
}
return & V_3 -> V_4 ;
V_43:
while ( V_17 -- )
F_9 ( & V_12 [ V_17 ] -> V_20 ) ;
return F_16 ( V_28 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_47 * V_48 )
{
struct V_5 * V_49 = F_3 ( V_7 ) ;
struct V_50 * V_51 = V_7 -> V_32 -> V_52 ;
struct V_24 * V_25 = V_7 -> V_32 ;
struct V_26 V_33 = { 0 } ;
unsigned int V_53 ;
struct V_2 * V_3 ;
unsigned long V_54 ;
struct V_55 * V_56 ;
struct V_8 * V_19 ;
T_1 V_39 ;
int V_28 ;
V_53 = F_29 ( V_48 -> V_57 , 8 ) ;
V_33 . V_37 = V_48 -> V_58 ;
V_33 . V_38 = V_48 -> V_59 ;
V_33 . V_44 [ 0 ] = F_30 ( V_48 -> V_58 * V_53 ,
V_51 -> V_60 ) ;
V_33 . V_11 = F_31 ( V_48 -> V_57 ,
V_48 -> V_61 ) ;
V_39 = V_33 . V_44 [ 0 ] * V_33 . V_38 ;
V_19 = F_32 ( V_25 , V_39 , 0 ) ;
if ( F_26 ( V_19 ) )
return F_27 ( V_19 ) ;
V_56 = F_33 ( 0 , V_25 -> V_32 ) ;
if ( ! V_56 ) {
F_19 ( V_25 -> V_32 , L_2 ) ;
F_34 ( & V_19 -> V_20 ) ;
return - V_30 ;
}
V_49 -> V_3 = F_14 ( V_25 , & V_33 , & V_19 , 1 ) ;
if ( F_26 ( V_49 -> V_3 ) ) {
F_19 ( V_25 -> V_32 , L_3 ) ;
V_28 = F_27 ( V_49 -> V_3 ) ;
goto V_62;
}
V_3 = & V_49 -> V_3 -> V_4 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_49 = V_56 ;
V_56 -> V_63 = V_7 ;
V_56 -> V_13 = V_64 ;
V_56 -> V_65 = & V_66 ;
V_28 = F_35 ( & V_56 -> V_67 , 256 , 0 ) ;
if ( V_28 < 0 ) {
F_19 ( V_25 -> V_32 , L_4 , V_28 ) ;
goto V_68;
}
F_36 ( V_56 , V_3 -> V_44 [ 0 ] , V_3 -> V_69 ) ;
F_37 ( V_56 , V_7 , V_3 -> V_37 , V_3 -> V_38 ) ;
V_54 = V_56 -> V_70 . V_71 * V_53 +
V_56 -> V_70 . V_72 * V_3 -> V_44 [ 0 ] ;
V_25 -> V_73 . V_74 = ( V_75 ) V_19 -> V_76 ;
V_56 -> V_77 = ( void V_78 * ) V_19 -> V_79 + V_54 ;
V_56 -> V_80 = V_39 ;
V_56 -> V_81 . V_82 = ( unsigned long ) ( V_19 -> V_76 + V_54 ) ;
V_56 -> V_81 . V_83 = V_39 ;
return 0 ;
V_68:
F_38 ( V_3 ) ;
F_8 ( V_3 ) ;
V_62:
F_39 ( V_56 ) ;
return V_28 ;
}
static struct V_5 * F_40 ( struct V_24 * V_25 )
{
struct V_5 * V_49 ;
V_49 = F_15 ( sizeof( * V_49 ) , V_29 ) ;
if ( ! V_49 ) {
F_19 ( V_25 -> V_32 , L_5 ) ;
return F_16 ( - V_30 ) ;
}
F_41 ( V_25 , & V_49 -> V_4 , & V_84 ) ;
return V_49 ;
}
static int F_42 ( struct V_5 * V_49 ,
unsigned int V_85 ,
unsigned int V_86 ,
unsigned int V_87 )
{
struct V_24 * V_25 = V_49 -> V_4 . V_32 ;
int V_28 ;
V_28 = F_43 ( V_25 , & V_49 -> V_4 , V_86 , V_87 ) ;
if ( V_28 < 0 ) {
F_19 ( V_25 -> V_32 , L_6 ) ;
return V_28 ;
}
V_28 = F_44 ( & V_49 -> V_4 ) ;
if ( V_28 < 0 ) {
F_19 ( V_25 -> V_32 , L_7 ) ;
goto V_88;
}
V_28 = F_45 ( & V_49 -> V_4 , V_85 ) ;
if ( V_28 < 0 ) {
F_19 ( V_25 -> V_32 , L_8 ) ;
goto V_88;
}
return 0 ;
V_88:
F_46 ( & V_49 -> V_4 ) ;
return V_28 ;
}
static void F_47 ( struct V_5 * V_49 )
{
struct V_55 * V_56 = V_49 -> V_4 . V_49 ;
if ( V_56 ) {
int V_28 ;
V_28 = F_48 ( V_56 ) ;
if ( V_28 < 0 )
F_49 ( L_9 ) ;
if ( V_56 -> V_67 . V_89 )
F_50 ( & V_56 -> V_67 ) ;
F_39 ( V_56 ) ;
}
if ( V_49 -> V_3 ) {
F_38 ( & V_49 -> V_3 -> V_4 ) ;
F_8 ( & V_49 -> V_3 -> V_4 ) ;
}
F_46 ( & V_49 -> V_4 ) ;
F_11 ( V_49 ) ;
}
void F_51 ( struct V_5 * V_49 )
{
if ( V_49 )
F_52 ( & V_49 -> V_4 ) ;
}
static void F_53 ( struct V_24 * V_25 )
{
struct V_50 * V_51 = V_25 -> V_52 ;
if ( V_51 -> V_49 )
F_54 ( & V_51 -> V_49 -> V_4 ) ;
}
int F_55 ( struct V_24 * V_25 )
{
#ifdef F_56
struct V_50 * V_51 = V_25 -> V_52 ;
#endif
V_25 -> V_73 . V_90 = 0 ;
V_25 -> V_73 . V_91 = 0 ;
V_25 -> V_73 . V_92 = 4096 ;
V_25 -> V_73 . V_93 = 4096 ;
V_25 -> V_73 . V_94 = & V_95 ;
#ifdef F_56
V_51 -> V_49 = F_40 ( V_25 ) ;
if ( F_26 ( V_51 -> V_49 ) )
return F_27 ( V_51 -> V_49 ) ;
#endif
return 0 ;
}
int F_57 ( struct V_24 * V_25 )
{
#ifdef F_56
struct V_50 * V_51 = V_25 -> V_52 ;
int V_28 ;
V_28 = F_42 ( V_51 -> V_49 , 32 , V_25 -> V_73 . V_86 ,
V_25 -> V_73 . V_96 ) ;
if ( V_28 < 0 )
return V_28 ;
#endif
return 0 ;
}
void F_58 ( struct V_24 * V_25 )
{
#ifdef F_56
struct V_50 * V_51 = V_25 -> V_52 ;
F_47 ( V_51 -> V_49 ) ;
#endif
}
