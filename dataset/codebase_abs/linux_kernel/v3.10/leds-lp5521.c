static inline void F_1 ( void )
{
F_2 ( 200 , 300 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 500 , 600 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 ;
F_5 ( V_2 -> V_4 , V_5 + V_2 -> V_6 ,
V_3 ) ;
}
static void F_6 ( struct V_7 * V_4 )
{
enum V_8 V_9 = V_4 -> V_10 ;
T_1 V_11 [] = {
[ V_12 ] = V_13 ,
[ V_14 ] = V_15 ,
[ V_16 ] = V_17 ,
} ;
T_1 V_18 [] = {
[ V_12 ] = V_19 ,
[ V_14 ] = V_20 ,
[ V_16 ] = V_21 ,
} ;
F_7 ( V_4 , V_22 , V_11 [ V_9 ] , V_18 [ V_9 ] ) ;
F_1 () ;
}
static void F_8 ( struct V_7 * V_4 )
{
F_5 ( V_4 , V_22 , 0 ) ;
F_1 () ;
}
static void F_9 ( struct V_7 * V_4 , bool V_23 )
{
int V_24 ;
T_1 V_25 ;
T_1 V_26 ;
if ( ! V_23 ) {
F_8 ( V_4 ) ;
F_5 ( V_4 , V_22 , V_27 ) ;
F_1 () ;
return;
}
V_24 = F_10 ( V_4 , V_22 , & V_25 ) ;
if ( V_24 )
return;
V_24 = F_10 ( V_4 , V_28 , & V_26 ) ;
if ( V_24 )
return;
if ( F_11 ( V_25 ) ) {
V_25 = ( V_25 & ~ V_13 ) | V_29 ;
V_26 = ( V_26 & ~ V_30 ) | V_29 ;
}
if ( F_12 ( V_25 ) ) {
V_25 = ( V_25 & ~ V_15 ) | V_31 ;
V_26 = ( V_26 & ~ V_32 ) | V_31 ;
}
if ( F_13 ( V_25 ) ) {
V_25 = ( V_25 & ~ V_17 ) | V_33 ;
V_26 = ( V_26 & ~ V_34 ) | V_33 ;
}
F_5 ( V_4 , V_22 , V_25 ) ;
F_1 () ;
F_7 ( V_4 , V_28 , V_35 , V_26 ) ;
F_3 () ;
}
static int F_14 ( struct V_7 * V_4 ,
const T_1 * V_36 , T_2 V_37 )
{
enum V_8 V_9 = V_4 -> V_10 ;
T_1 V_38 [ V_39 ] = { 0 } ;
T_1 V_40 [] = {
[ V_12 ] = V_41 ,
[ V_14 ] = V_42 ,
[ V_16 ] = V_43 ,
} ;
unsigned V_44 ;
char V_45 [ 3 ] ;
int V_46 ;
int V_47 ;
int V_48 = 0 ;
int V_24 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_39 ; V_49 ++ )
F_5 ( V_4 , V_40 [ V_9 ] + V_49 , 0 ) ;
V_49 = 0 ;
while ( ( V_48 < V_37 - 1 ) && ( V_49 < V_39 ) ) {
V_24 = sscanf ( V_36 + V_48 , L_1 , V_45 , & V_47 ) ;
if ( V_24 != 1 )
goto V_50;
V_24 = sscanf ( V_45 , L_2 , & V_44 ) ;
if ( V_24 != 1 )
goto V_50;
V_38 [ V_49 ] = ( T_1 ) V_44 ;
V_48 += V_47 ;
V_49 ++ ;
}
if ( V_49 % 2 )
goto V_50;
V_46 = V_49 ;
for ( V_49 = 0 ; V_49 < V_46 ; V_49 ++ )
F_5 ( V_4 , V_40 [ V_9 ] + V_49 , V_38 [ V_49 ] ) ;
return 0 ;
V_50:
F_15 ( & V_4 -> V_51 -> V_52 , L_3 ) ;
return - V_53 ;
}
static void F_16 ( struct V_7 * V_4 )
{
const struct V_54 * V_55 = V_4 -> V_55 ;
if ( V_55 -> V_37 > V_39 ) {
F_15 ( & V_4 -> V_51 -> V_52 , L_4 ,
V_55 -> V_37 ) ;
return;
}
F_6 ( V_4 ) ;
F_14 ( V_4 , V_55 -> V_36 , V_55 -> V_37 ) ;
}
static int F_17 ( struct V_7 * V_4 )
{
int V_24 ;
T_1 V_18 ;
V_24 = F_10 ( V_4 , V_56 , & V_18 ) ;
if ( V_24 ) {
F_15 ( & V_4 -> V_51 -> V_52 , L_5 ) ;
return V_24 ;
}
if ( V_18 != V_57 ) {
F_15 ( & V_4 -> V_51 -> V_52 ,
L_6 ,
V_57 , V_18 ) ;
V_24 = - V_53 ;
return V_24 ;
}
F_2 ( 10000 , 20000 ) ;
V_24 = F_5 ( V_4 , V_22 , V_27 ) ;
V_18 = V_58 ;
if ( ! F_18 ( V_4 ) )
V_18 |= V_59 ;
V_24 = F_5 ( V_4 , V_60 , V_18 ) ;
if ( V_24 )
return V_24 ;
F_5 ( V_4 , V_61 , 0 ) ;
F_5 ( V_4 , V_62 , 0 ) ;
F_5 ( V_4 , V_63 , 0 ) ;
V_24 = F_5 ( V_4 , V_28 , V_64 ) ;
if ( V_24 )
return V_24 ;
F_3 () ;
return 0 ;
}
static int F_19 ( struct V_7 * V_4 , char * V_65 )
{
struct V_66 * V_67 = V_4 -> V_67 ;
int V_24 ;
T_1 V_68 ;
V_24 = F_10 ( V_4 , V_69 , & V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_67 -> V_70 != V_71 )
return 0 ;
if ( ( V_68 & V_72 ) == 0 )
return - V_73 ;
return 0 ;
}
static void F_20 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_21 ( V_75 , struct V_1 ,
V_76 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_22 ( & V_4 -> V_77 ) ;
F_5 ( V_4 , V_78 + V_2 -> V_6 ,
V_2 -> V_79 ) ;
F_23 ( & V_4 -> V_77 ) ;
}
static T_3 F_24 ( struct V_80 * V_52 ,
struct V_81 * V_82 ,
char * V_65 )
{
struct V_1 * V_2 = F_25 ( F_26 ( V_52 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_24 ;
F_22 ( & V_4 -> V_77 ) ;
V_24 = F_19 ( V_4 , V_65 ) ;
F_23 ( & V_4 -> V_77 ) ;
return F_27 ( V_65 , V_83 , L_7 , V_24 ? L_8 : L_9 ) ;
}
static int F_28 ( struct V_84 * V_85 ,
const struct V_86 * V_87 )
{
int V_24 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
struct V_66 * V_67 = V_85 -> V_52 . V_88 ;
if ( ! V_67 ) {
F_15 ( & V_85 -> V_52 , L_10 ) ;
return - V_53 ;
}
V_4 = F_29 ( & V_85 -> V_52 , sizeof( * V_4 ) , V_89 ) ;
if ( ! V_4 )
return - V_90 ;
V_2 = F_29 ( & V_85 -> V_52 ,
sizeof( * V_2 ) * V_67 -> V_91 , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
V_4 -> V_51 = V_85 ;
V_4 -> V_67 = V_67 ;
V_4 -> V_92 = & V_93 ;
F_30 ( & V_4 -> V_77 ) ;
F_31 ( V_85 , V_2 ) ;
V_24 = F_32 ( V_4 ) ;
if ( V_24 )
goto V_94;
F_33 ( & V_85 -> V_52 , L_11 , V_87 -> V_95 ) ;
V_24 = F_34 ( V_2 , V_4 ) ;
if ( V_24 )
goto V_96;
V_24 = F_35 ( V_4 ) ;
if ( V_24 ) {
F_15 ( & V_85 -> V_52 , L_12 ) ;
goto V_97;
}
return 0 ;
V_97:
F_36 ( V_2 , V_4 ) ;
V_96:
F_37 ( V_4 ) ;
V_94:
return V_24 ;
}
static int F_38 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_25 ( V_85 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_8 ( V_4 ) ;
F_39 ( V_4 ) ;
F_36 ( V_2 , V_4 ) ;
F_37 ( V_4 ) ;
return 0 ;
}
