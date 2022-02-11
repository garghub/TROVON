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
bool F_7 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
if ( V_3 -> V_12 [ 0 ] -> V_13 & V_15 )
return true ;
return false ;
}
static void F_8 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_17 ; V_16 ++ ) {
struct V_8 * V_18 = V_3 -> V_12 [ V_16 ] ;
if ( V_18 )
F_9 ( & V_18 -> V_19 ) ;
}
F_10 ( V_9 ) ;
F_11 ( V_3 -> V_12 ) ;
F_11 ( V_3 ) ;
}
static int F_12 ( struct V_2 * V_9 ,
struct V_20 * V_21 , unsigned int * V_22 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
return F_13 ( V_21 , & V_3 -> V_12 [ 0 ] -> V_19 , V_22 ) ;
}
static struct V_1 * F_14 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_8 * * V_12 ,
unsigned int V_17 )
{
struct V_1 * V_3 ;
unsigned int V_16 ;
int V_27 ;
V_3 = F_15 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
return F_16 ( - V_29 ) ;
V_3 -> V_12 = F_15 ( V_17 * sizeof( * V_12 ) , V_28 ) ;
if ( ! V_3 -> V_12 ) {
F_11 ( V_3 ) ;
return F_16 ( - V_29 ) ;
}
V_3 -> V_17 = V_17 ;
F_17 ( & V_3 -> V_4 , V_26 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_17 ; V_16 ++ )
V_3 -> V_12 [ V_16 ] = V_12 [ V_16 ] ;
V_27 = F_18 ( V_24 , & V_3 -> V_4 , & V_30 ) ;
if ( V_27 < 0 ) {
F_19 ( V_24 -> V_31 , L_1 ,
V_27 ) ;
F_11 ( V_3 -> V_12 ) ;
F_11 ( V_3 ) ;
return F_16 ( V_27 ) ;
}
return V_3 ;
}
static struct V_2 * F_20 ( struct V_23 * V_24 ,
struct V_20 * V_21 ,
struct V_25 * V_32 )
{
unsigned int V_33 , V_34 , V_16 ;
struct V_8 * V_12 [ 4 ] ;
struct V_35 * V_19 ;
struct V_1 * V_3 ;
int V_27 ;
V_33 = F_21 ( V_32 -> V_11 ) ;
V_34 = F_22 ( V_32 -> V_11 ) ;
for ( V_16 = 0 ; V_16 < F_5 ( V_32 -> V_11 ) ; V_16 ++ ) {
unsigned int V_36 = V_32 -> V_36 / ( V_16 ? V_33 : 1 ) ;
unsigned int V_37 = V_32 -> V_37 / ( V_16 ? V_34 : 1 ) ;
unsigned int V_38 , V_39 ;
V_19 = F_23 ( V_24 , V_21 , V_32 -> V_40 [ V_16 ] ) ;
if ( ! V_19 ) {
V_27 = - V_41 ;
goto V_42;
}
V_39 = F_24 ( V_32 -> V_11 , V_16 ) ;
V_38 = ( V_37 - 1 ) * V_32 -> V_43 [ V_16 ] +
V_36 * V_39 + V_32 -> V_44 [ V_16 ] ;
if ( V_19 -> V_38 < V_38 ) {
V_27 = - V_45 ;
goto V_42;
}
V_12 [ V_16 ] = F_25 ( V_19 ) ;
}
V_3 = F_14 ( V_24 , V_32 , V_12 , V_16 ) ;
if ( F_26 ( V_3 ) ) {
V_27 = F_27 ( V_3 ) ;
goto V_42;
}
return & V_3 -> V_4 ;
V_42:
while ( V_16 -- )
F_9 ( & V_12 [ V_16 ] -> V_19 ) ;
return F_16 ( V_27 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
struct V_5 * V_48 = F_3 ( V_7 ) ;
struct V_23 * V_24 = V_7 -> V_31 ;
struct V_25 V_32 = { 0 } ;
unsigned int V_49 ;
struct V_2 * V_3 ;
unsigned long V_50 ;
struct V_51 * V_52 ;
struct V_8 * V_18 ;
T_1 V_38 ;
int V_27 ;
V_49 = F_29 ( V_47 -> V_53 , 8 ) ;
V_32 . V_36 = V_47 -> V_54 ;
V_32 . V_37 = V_47 -> V_55 ;
V_32 . V_43 [ 0 ] = V_47 -> V_54 * V_49 ;
V_32 . V_11 = F_30 ( V_47 -> V_53 ,
V_47 -> V_56 ) ;
V_38 = V_32 . V_43 [ 0 ] * V_32 . V_37 ;
V_18 = F_31 ( V_24 , V_38 , 0 ) ;
if ( F_26 ( V_18 ) )
return F_27 ( V_18 ) ;
V_52 = F_32 ( 0 , V_24 -> V_31 ) ;
if ( ! V_52 ) {
F_19 ( V_24 -> V_31 , L_2 ) ;
F_33 ( & V_18 -> V_19 ) ;
return - V_29 ;
}
V_48 -> V_3 = F_14 ( V_24 , & V_32 , & V_18 , 1 ) ;
if ( F_26 ( V_48 -> V_3 ) ) {
F_19 ( V_24 -> V_31 , L_3 ) ;
V_27 = F_27 ( V_48 -> V_3 ) ;
goto V_57;
}
V_3 = & V_48 -> V_3 -> V_4 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_48 = V_52 ;
V_52 -> V_58 = V_7 ;
V_52 -> V_13 = V_59 ;
V_52 -> V_60 = & V_61 ;
V_27 = F_34 ( & V_52 -> V_62 , 256 , 0 ) ;
if ( V_27 < 0 ) {
F_19 ( V_24 -> V_31 , L_4 , V_27 ) ;
goto V_63;
}
F_35 ( V_52 , V_3 -> V_43 [ 0 ] , V_3 -> V_64 ) ;
F_36 ( V_52 , V_7 , V_3 -> V_36 , V_3 -> V_37 ) ;
V_50 = V_52 -> V_65 . V_66 * V_49 +
V_52 -> V_65 . V_67 * V_3 -> V_43 [ 0 ] ;
V_24 -> V_68 . V_69 = ( V_70 ) V_18 -> V_71 ;
V_52 -> V_72 = ( void V_73 * ) V_18 -> V_74 + V_50 ;
V_52 -> V_75 = V_38 ;
V_52 -> V_76 . V_77 = ( unsigned long ) ( V_18 -> V_71 + V_50 ) ;
V_52 -> V_76 . V_78 = V_38 ;
return 0 ;
V_63:
F_37 ( V_3 ) ;
F_8 ( V_3 ) ;
V_57:
F_38 ( V_52 ) ;
return V_27 ;
}
static struct V_5 * F_39 ( struct V_23 * V_24 ,
unsigned int V_79 ,
unsigned int V_80 ,
unsigned int V_81 )
{
struct V_6 * V_7 ;
struct V_5 * V_48 ;
int V_27 ;
V_48 = F_15 ( sizeof( * V_48 ) , V_28 ) ;
if ( ! V_48 ) {
F_19 ( V_24 -> V_31 , L_5 ) ;
return F_16 ( - V_29 ) ;
}
V_48 -> V_4 . V_82 = & V_83 ;
V_7 = & V_48 -> V_4 ;
V_27 = F_40 ( V_24 , & V_48 -> V_4 , V_80 , V_81 ) ;
if ( V_27 < 0 ) {
F_19 ( V_24 -> V_31 , L_6 ) ;
goto free;
}
V_27 = F_41 ( & V_48 -> V_4 ) ;
if ( V_27 < 0 ) {
F_19 ( V_24 -> V_31 , L_7 ) ;
goto V_84;
}
F_42 ( V_24 ) ;
V_27 = F_43 ( & V_48 -> V_4 , V_79 ) ;
if ( V_27 < 0 ) {
F_19 ( V_24 -> V_31 , L_8 ) ;
goto V_84;
}
return V_48 ;
V_84:
F_44 ( & V_48 -> V_4 ) ;
free:
F_11 ( V_48 ) ;
return F_16 ( V_27 ) ;
}
static void F_45 ( struct V_5 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_4 . V_48 ;
if ( V_52 ) {
int V_27 ;
V_27 = F_46 ( V_52 ) ;
if ( V_27 < 0 )
F_47 ( L_9 ) ;
if ( V_52 -> V_62 . V_85 )
F_48 ( & V_52 -> V_62 ) ;
F_38 ( V_52 ) ;
}
if ( V_48 -> V_3 ) {
F_37 ( & V_48 -> V_3 -> V_4 ) ;
F_8 ( & V_48 -> V_3 -> V_4 ) ;
}
F_44 ( & V_48 -> V_4 ) ;
F_11 ( V_48 ) ;
}
void F_49 ( struct V_5 * V_48 )
{
if ( V_48 )
F_50 ( & V_48 -> V_4 ) ;
}
static void F_51 ( struct V_23 * V_24 )
{
struct V_86 * V_87 = V_24 -> V_88 ;
if ( V_87 -> V_48 )
F_52 ( & V_87 -> V_48 -> V_4 ) ;
}
int F_53 ( struct V_23 * V_24 )
{
#ifdef F_54
struct V_86 * V_87 = V_24 -> V_88 ;
#endif
V_24 -> V_68 . V_89 = 0 ;
V_24 -> V_68 . V_90 = 0 ;
V_24 -> V_68 . V_91 = 4096 ;
V_24 -> V_68 . V_92 = 4096 ;
V_24 -> V_68 . V_82 = & V_93 ;
#ifdef F_54
V_87 -> V_48 = F_39 ( V_24 , 32 , V_24 -> V_68 . V_80 ,
V_24 -> V_68 . V_94 ) ;
if ( F_26 ( V_87 -> V_48 ) )
return F_27 ( V_87 -> V_48 ) ;
#endif
return 0 ;
}
void F_55 ( struct V_23 * V_24 )
{
#ifdef F_54
struct V_86 * V_87 = V_24 -> V_88 ;
F_45 ( V_87 -> V_48 ) ;
#endif
}
