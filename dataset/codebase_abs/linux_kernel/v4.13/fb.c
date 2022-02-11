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
T_1 V_18 = V_3 -> V_4 . V_18 ;
switch ( F_7 ( V_18 ) ) {
case V_19 :
V_17 -> V_20 = V_21 ;
V_17 -> V_22 = 0 ;
break;
case F_8 ( 0 ) :
V_17 -> V_20 = V_23 ;
V_17 -> V_22 = F_9 ( V_18 ) ;
if ( V_17 -> V_22 > 5 )
return - V_24 ;
break;
default:
* V_17 = V_3 -> V_13 [ 0 ] -> V_17 ;
break;
}
return 0 ;
}
static void F_10 ( struct V_2 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_3 -> V_12 ; V_25 ++ ) {
struct V_8 * V_26 = V_3 -> V_13 [ V_25 ] ;
if ( V_26 ) {
if ( V_26 -> V_27 )
F_11 ( V_26 -> V_28 ) ;
F_12 ( & V_26 -> V_29 ) ;
}
}
F_13 ( V_9 ) ;
F_14 ( V_3 -> V_13 ) ;
F_14 ( V_3 ) ;
}
static int F_15 ( struct V_2 * V_9 ,
struct V_30 * V_31 , unsigned int * V_32 )
{
struct V_1 * V_3 = F_1 ( V_9 ) ;
return F_16 ( V_31 , & V_3 -> V_13 [ 0 ] -> V_29 , V_32 ) ;
}
static struct V_1 * F_17 ( struct V_33 * V_34 ,
const struct V_35 * V_36 ,
struct V_8 * * V_13 ,
unsigned int V_12 )
{
struct V_1 * V_3 ;
unsigned int V_25 ;
int V_37 ;
V_3 = F_18 ( sizeof( * V_3 ) , V_38 ) ;
if ( ! V_3 )
return F_19 ( - V_39 ) ;
V_3 -> V_13 = F_18 ( V_12 * sizeof( * V_13 ) , V_38 ) ;
if ( ! V_3 -> V_13 ) {
F_14 ( V_3 ) ;
return F_19 ( - V_39 ) ;
}
V_3 -> V_12 = V_12 ;
F_20 ( V_34 , & V_3 -> V_4 , V_36 ) ;
for ( V_25 = 0 ; V_25 < V_3 -> V_12 ; V_25 ++ )
V_3 -> V_13 [ V_25 ] = V_13 [ V_25 ] ;
V_37 = F_21 ( V_34 , & V_3 -> V_4 , & V_40 ) ;
if ( V_37 < 0 ) {
F_22 ( V_34 -> V_41 , L_1 ,
V_37 ) ;
F_14 ( V_3 -> V_13 ) ;
F_14 ( V_3 ) ;
return F_19 ( V_37 ) ;
}
return V_3 ;
}
struct V_2 * F_23 ( struct V_33 * V_34 ,
struct V_30 * V_31 ,
const struct V_35 * V_42 )
{
unsigned int V_43 , V_44 , V_25 ;
struct V_8 * V_13 [ 4 ] ;
struct V_45 * V_29 ;
struct V_1 * V_3 ;
int V_37 ;
V_43 = F_24 ( V_42 -> V_46 ) ;
V_44 = F_25 ( V_42 -> V_46 ) ;
for ( V_25 = 0 ; V_25 < F_26 ( V_42 -> V_46 ) ; V_25 ++ ) {
unsigned int V_47 = V_42 -> V_47 / ( V_25 ? V_43 : 1 ) ;
unsigned int V_48 = V_42 -> V_48 / ( V_25 ? V_44 : 1 ) ;
unsigned int V_49 , V_50 ;
V_29 = F_27 ( V_31 , V_42 -> V_51 [ V_25 ] ) ;
if ( ! V_29 ) {
V_37 = - V_52 ;
goto V_53;
}
V_50 = F_28 ( V_42 -> V_46 , V_25 ) ;
V_49 = ( V_48 - 1 ) * V_42 -> V_54 [ V_25 ] +
V_47 * V_50 + V_42 -> V_55 [ V_25 ] ;
if ( V_29 -> V_49 < V_49 ) {
V_37 = - V_24 ;
goto V_53;
}
V_13 [ V_25 ] = F_29 ( V_29 ) ;
}
V_3 = F_17 ( V_34 , V_42 , V_13 , V_25 ) ;
if ( F_30 ( V_3 ) ) {
V_37 = F_31 ( V_3 ) ;
goto V_53;
}
return & V_3 -> V_4 ;
V_53:
while ( V_25 -- )
F_12 ( & V_13 [ V_25 ] -> V_29 ) ;
return F_19 ( V_37 ) ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_56 * V_57 )
{
struct V_5 * V_58 = F_3 ( V_7 ) ;
struct V_59 * V_60 = V_7 -> V_41 -> V_61 ;
struct V_33 * V_34 = V_7 -> V_41 ;
struct V_35 V_42 = { 0 } ;
unsigned int V_62 ;
struct V_2 * V_3 ;
unsigned long V_63 ;
struct V_64 * V_65 ;
struct V_8 * V_26 ;
T_2 V_49 ;
int V_37 ;
V_62 = F_33 ( V_57 -> V_66 , 8 ) ;
V_42 . V_47 = V_57 -> V_67 ;
V_42 . V_48 = V_57 -> V_68 ;
V_42 . V_54 [ 0 ] = F_34 ( V_57 -> V_67 * V_62 ,
V_60 -> V_69 ) ;
V_42 . V_46 = F_35 ( V_57 -> V_66 ,
V_57 -> V_70 ) ;
V_49 = V_42 . V_54 [ 0 ] * V_42 . V_48 ;
V_26 = F_36 ( V_34 , V_49 , 0 ) ;
if ( F_30 ( V_26 ) )
return F_31 ( V_26 ) ;
V_65 = F_37 ( V_7 ) ;
if ( F_30 ( V_65 ) ) {
F_22 ( V_34 -> V_41 , L_2 ) ;
F_12 ( & V_26 -> V_29 ) ;
return F_31 ( V_65 ) ;
}
V_58 -> V_3 = F_17 ( V_34 , & V_42 , & V_26 , 1 ) ;
if ( F_30 ( V_58 -> V_3 ) ) {
V_37 = F_31 ( V_58 -> V_3 ) ;
F_22 ( V_34 -> V_41 , L_3 ,
V_37 ) ;
F_12 ( & V_26 -> V_29 ) ;
return F_31 ( V_58 -> V_3 ) ;
}
V_3 = & V_58 -> V_3 -> V_4 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_58 = V_65 ;
V_65 -> V_71 = V_7 ;
V_65 -> V_14 = V_72 ;
V_65 -> V_73 = & V_74 ;
F_38 ( V_65 , V_3 -> V_54 [ 0 ] , V_3 -> V_11 -> V_75 ) ;
F_39 ( V_65 , V_7 , V_3 -> V_47 , V_3 -> V_48 ) ;
V_63 = V_65 -> V_76 . V_77 * V_62 +
V_65 -> V_76 . V_78 * V_3 -> V_54 [ 0 ] ;
if ( V_26 -> V_27 ) {
V_26 -> V_28 = F_40 ( V_26 -> V_27 , V_26 -> V_79 , V_80 ,
F_41 ( V_81 ) ) ;
if ( ! V_26 -> V_28 ) {
F_22 ( V_34 -> V_41 , L_4 ) ;
V_37 = - V_39 ;
goto V_82;
}
}
V_34 -> V_83 . V_84 = ( V_85 ) V_26 -> V_86 ;
V_65 -> V_87 = ( void V_88 * ) V_26 -> V_28 + V_63 ;
V_65 -> V_89 = V_49 ;
V_65 -> V_90 . V_91 = ( unsigned long ) ( V_26 -> V_86 + V_63 ) ;
V_65 -> V_90 . V_92 = V_49 ;
return 0 ;
V_82:
F_42 ( V_3 ) ;
return V_37 ;
}
static struct V_5 * F_43 ( struct V_33 * V_34 )
{
struct V_5 * V_58 ;
V_58 = F_18 ( sizeof( * V_58 ) , V_38 ) ;
if ( ! V_58 ) {
F_22 ( V_34 -> V_41 , L_5 ) ;
return F_19 ( - V_39 ) ;
}
F_44 ( V_34 , & V_58 -> V_4 , & V_93 ) ;
return V_58 ;
}
static void F_45 ( struct V_5 * V_58 )
{
F_14 ( V_58 ) ;
}
static int F_46 ( struct V_5 * V_58 ,
unsigned int V_94 ,
unsigned int V_95 ,
unsigned int V_96 )
{
struct V_33 * V_34 = V_58 -> V_4 . V_41 ;
int V_37 ;
V_37 = F_47 ( V_34 , & V_58 -> V_4 , V_96 ) ;
if ( V_37 < 0 ) {
F_22 ( V_34 -> V_41 , L_6 ,
V_37 ) ;
return V_37 ;
}
V_37 = F_48 ( & V_58 -> V_4 ) ;
if ( V_37 < 0 ) {
F_22 ( V_34 -> V_41 , L_7 , V_37 ) ;
goto V_97;
}
V_37 = F_49 ( & V_58 -> V_4 , V_94 ) ;
if ( V_37 < 0 ) {
F_22 ( V_34 -> V_41 , L_8 ,
V_37 ) ;
goto V_97;
}
return 0 ;
V_97:
F_50 ( & V_58 -> V_4 ) ;
return V_37 ;
}
static void F_51 ( struct V_5 * V_58 )
{
F_52 ( & V_58 -> V_4 ) ;
if ( V_58 -> V_3 )
F_42 ( & V_58 -> V_3 -> V_4 ) ;
F_50 ( & V_58 -> V_4 ) ;
F_45 ( V_58 ) ;
}
void F_53 ( struct V_5 * V_58 )
{
if ( V_58 )
F_54 ( & V_58 -> V_4 ) ;
}
void F_55 ( struct V_33 * V_34 )
{
struct V_59 * V_60 = V_34 -> V_61 ;
if ( V_60 -> V_58 )
F_56 ( & V_60 -> V_58 -> V_4 ) ;
}
int F_57 ( struct V_33 * V_34 )
{
#ifdef F_58
struct V_59 * V_60 = V_34 -> V_61 ;
V_60 -> V_58 = F_43 ( V_34 ) ;
if ( F_30 ( V_60 -> V_58 ) )
return F_31 ( V_60 -> V_58 ) ;
#endif
return 0 ;
}
void F_59 ( struct V_33 * V_34 )
{
#ifdef F_58
struct V_59 * V_60 = V_34 -> V_61 ;
F_45 ( V_60 -> V_58 ) ;
#endif
}
int F_60 ( struct V_33 * V_34 )
{
#ifdef F_58
struct V_59 * V_60 = V_34 -> V_61 ;
int V_37 ;
V_37 = F_46 ( V_60 -> V_58 , 32 , V_34 -> V_83 . V_95 ,
V_34 -> V_83 . V_98 ) ;
if ( V_37 < 0 )
return V_37 ;
#endif
return 0 ;
}
void F_61 ( struct V_33 * V_34 )
{
#ifdef F_58
struct V_59 * V_60 = V_34 -> V_61 ;
F_51 ( V_60 -> V_58 ) ;
#endif
}
void F_62 ( struct V_33 * V_34 )
{
#ifdef F_58
struct V_59 * V_60 = V_34 -> V_61 ;
F_63 () ;
F_64 ( & V_60 -> V_58 -> V_4 , 1 ) ;
F_65 () ;
#endif
}
void F_66 ( struct V_33 * V_34 )
{
#ifdef F_58
struct V_59 * V_60 = V_34 -> V_61 ;
F_63 () ;
F_64 ( & V_60 -> V_58 -> V_4 , 0 ) ;
F_65 () ;
#endif
}
