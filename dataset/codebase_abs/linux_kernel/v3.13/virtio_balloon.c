static T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
F_3 ( V_3 < V_4 ) ;
return V_2 * V_5 ;
}
static struct V_1 * F_4 ( T_1 V_2 )
{
F_5 ( V_2 % V_5 ) ;
return F_6 ( V_2 / V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_8 ( & V_9 -> V_12 ) ;
}
static void F_9 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_13 V_14 ;
unsigned int V_15 ;
F_10 ( & V_14 , V_9 -> V_16 , sizeof( V_9 -> V_16 [ 0 ] ) * V_9 -> V_17 ) ;
if ( F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) < 0 )
F_12 () ;
F_13 ( V_7 ) ;
F_14 ( V_9 -> V_12 , F_15 ( V_7 , & V_15 ) ) ;
}
static void F_16 ( T_1 V_16 [] , struct V_1 * V_1 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_16 [ V_19 ] = F_1 ( V_1 ) + V_19 ;
}
static void F_17 ( struct V_8 * V_9 , T_2 V_20 )
{
struct V_21 * V_22 = V_9 -> V_22 ;
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
F_20 ( & V_9 -> V_23 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
struct V_1 * V_1 = F_21 ( V_22 ) ;
if ( ! V_1 ) {
F_22 ( & V_9 -> V_10 -> V_24 ,
L_1 ,
V_5 ) ;
F_23 ( 200 ) ;
break;
}
F_16 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_25 += V_5 ;
F_24 ( V_1 , - 1 ) ;
}
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_26 ) ;
F_25 ( & V_9 -> V_23 ) ;
}
static void F_26 ( const T_1 V_16 [] , unsigned int V_20 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 += V_5 ) {
struct V_1 * V_1 = F_4 ( V_16 [ V_19 ] ) ;
F_27 ( V_1 ) ;
F_24 ( V_1 , 1 ) ;
}
}
static void F_28 ( struct V_8 * V_9 , T_2 V_20 )
{
struct V_1 * V_1 ;
struct V_21 * V_22 = V_9 -> V_22 ;
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
F_20 ( & V_9 -> V_23 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
V_1 = F_29 ( V_22 ) ;
if ( ! V_1 )
break;
F_16 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_25 -= V_5 ;
}
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_27 ) ;
F_25 ( & V_9 -> V_23 ) ;
F_26 ( V_9 -> V_16 , V_9 -> V_17 ) ;
}
static inline void F_30 ( struct V_8 * V_9 , int V_28 ,
T_3 V_29 , T_4 V_30 )
{
F_5 ( V_28 >= V_31 ) ;
V_9 -> V_32 [ V_28 ] . V_29 = V_29 ;
V_9 -> V_32 [ V_28 ] . V_30 = V_30 ;
}
static void F_31 ( struct V_8 * V_9 )
{
unsigned long V_33 [ V_34 ] ;
struct V_35 V_19 ;
int V_28 = 0 ;
F_32 ( V_33 ) ;
F_33 ( & V_19 ) ;
F_30 ( V_9 , V_28 ++ , V_36 ,
F_34 ( V_33 [ V_37 ] ) ) ;
F_30 ( V_9 , V_28 ++ , V_38 ,
F_34 ( V_33 [ V_39 ] ) ) ;
F_30 ( V_9 , V_28 ++ , V_40 , V_33 [ V_41 ] ) ;
F_30 ( V_9 , V_28 ++ , V_42 , V_33 [ V_43 ] ) ;
F_30 ( V_9 , V_28 ++ , V_44 ,
F_34 ( V_19 . V_45 ) ) ;
F_30 ( V_9 , V_28 ++ , V_46 ,
F_34 ( V_19 . V_47 ) ) ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
V_9 -> V_48 = 1 ;
F_8 ( & V_9 -> V_49 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 ;
V_9 -> V_48 = 0 ;
F_31 ( V_9 ) ;
V_7 = V_9 -> V_50 ;
if ( ! F_15 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_32 , sizeof( V_9 -> V_32 ) ) ;
if ( F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) < 0 )
F_12 () ;
F_13 ( V_7 ) ;
}
static void F_37 ( struct V_51 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_8 ( & V_9 -> V_49 ) ;
}
static inline T_5 F_38 ( struct V_8 * V_9 )
{
T_6 V_52 ;
T_5 V_53 ;
F_39 ( V_9 -> V_10 , struct V_54 , V_25 , & V_52 ) ;
V_53 = F_40 ( V_52 ) ;
return V_53 - V_9 -> V_25 ;
}
static void F_41 ( struct V_8 * V_9 )
{
T_6 V_55 = F_42 ( V_9 -> V_25 ) ;
F_43 ( V_9 -> V_10 , struct V_54 , V_55 ,
& V_55 ) ;
}
static int F_44 ( void * V_56 )
{
struct V_8 * V_9 = V_56 ;
F_45 () ;
while ( ! F_46 () ) {
T_5 V_57 ;
F_47 () ;
F_48 ( V_9 -> V_49 ,
( V_57 = F_38 ( V_9 ) ) != 0
|| V_9 -> V_48
|| F_46 ()
|| F_49 ( V_58 ) ) ;
if ( V_9 -> V_48 )
F_36 ( V_9 ) ;
if ( V_57 > 0 )
F_17 ( V_9 , V_57 ) ;
else if ( V_57 < 0 )
F_28 ( V_9 , - V_57 ) ;
F_41 ( V_9 ) ;
}
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_6 * V_59 [ 3 ] ;
T_7 * V_60 [] = { F_7 , F_7 , F_35 } ;
const char * V_61 [] = { L_2 , L_3 , L_4 } ;
int V_62 , V_63 ;
V_63 = F_51 ( V_9 -> V_10 , V_64 ) ? 3 : 2 ;
V_62 = V_9 -> V_10 -> V_65 -> V_66 ( V_9 -> V_10 , V_63 , V_59 , V_60 , V_61 ) ;
if ( V_62 )
return V_62 ;
V_9 -> V_26 = V_59 [ 0 ] ;
V_9 -> V_27 = V_59 [ 1 ] ;
if ( F_51 ( V_9 -> V_10 , V_64 ) ) {
struct V_13 V_14 ;
V_9 -> V_50 = V_59 [ 2 ] ;
F_10 ( & V_14 , V_9 -> V_32 , sizeof V_9 -> V_32 ) ;
if ( F_11 ( V_9 -> V_50 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_12 () ;
F_13 ( V_9 -> V_50 ) ;
}
return 0 ;
}
int F_52 ( struct V_67 * V_68 ,
struct V_1 * V_69 , struct V_1 * V_1 , enum V_70 V_71 )
{
struct V_21 * V_22 = F_53 ( V_1 ) ;
struct V_8 * V_9 ;
unsigned long V_72 ;
F_5 ( ! V_22 ) ;
V_9 = V_22 -> V_73 ;
if ( ! F_54 ( & V_9 -> V_23 ) )
return - V_74 ;
F_55 ( & V_22 -> V_75 , V_72 ) ;
F_56 ( V_69 , V_68 , & V_22 -> V_76 ) ;
V_22 -> V_77 -- ;
F_57 ( & V_22 -> V_75 , V_72 ) ;
V_9 -> V_17 = V_5 ;
F_16 ( V_9 -> V_16 , V_69 ) ;
F_9 ( V_9 , V_9 -> V_26 ) ;
F_58 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_16 ( V_9 -> V_16 , V_1 ) ;
F_9 ( V_9 , V_9 -> V_27 ) ;
F_25 ( & V_9 -> V_23 ) ;
return V_78 ;
}
static int F_59 ( struct V_51 * V_10 )
{
struct V_8 * V_9 ;
struct V_67 * V_79 ;
struct V_21 * V_80 ;
int V_62 ;
V_10 -> V_11 = V_9 = F_60 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_62 = - V_81 ;
goto V_82;
}
V_9 -> V_25 = 0 ;
F_61 ( & V_9 -> V_23 ) ;
F_62 ( & V_9 -> V_49 ) ;
F_62 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_48 = 0 ;
V_80 = F_63 ( V_9 ) ;
if ( F_64 ( V_80 ) ) {
V_62 = F_65 ( V_80 ) ;
goto V_83;
}
V_79 = F_66 ( V_80 ,
( F_67 () ) ?
& V_84 : NULL ) ;
if ( F_64 ( V_79 ) ) {
V_62 = F_65 ( V_79 ) ;
if ( V_62 != - V_85 )
goto V_86;
}
V_9 -> V_22 = V_80 ;
V_62 = F_50 ( V_9 ) ;
if ( V_62 )
goto V_87;
V_9 -> V_88 = F_68 ( F_44 , V_9 , L_5 ) ;
if ( F_64 ( V_9 -> V_88 ) ) {
V_62 = F_65 ( V_9 -> V_88 ) ;
goto V_89;
}
return 0 ;
V_89:
V_10 -> V_65 -> V_90 ( V_10 ) ;
V_87:
F_69 ( V_79 ) ;
V_86:
F_70 ( V_80 ) ;
V_83:
F_71 ( V_9 ) ;
V_82:
return V_62 ;
}
static void F_72 ( struct V_8 * V_9 )
{
while ( V_9 -> V_25 )
F_28 ( V_9 , V_9 -> V_25 ) ;
F_41 ( V_9 ) ;
V_9 -> V_10 -> V_65 -> V_91 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_65 -> V_90 ( V_9 -> V_10 ) ;
}
static void F_73 ( struct V_51 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_74 ( V_9 -> V_88 ) ;
F_72 ( V_9 ) ;
F_69 ( V_9 -> V_22 -> V_68 ) ;
F_70 ( V_9 -> V_22 ) ;
F_71 ( V_9 ) ;
}
static int F_75 ( struct V_51 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_72 ( V_9 ) ;
return 0 ;
}
static int F_76 ( struct V_51 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_92 ;
V_92 = F_50 ( V_10 -> V_11 ) ;
if ( V_92 )
return V_92 ;
F_17 ( V_9 , F_38 ( V_9 ) ) ;
F_41 ( V_9 ) ;
return 0 ;
}
