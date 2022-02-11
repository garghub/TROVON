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
V_26 -- ;
}
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_27 ) ;
F_24 ( & V_9 -> V_23 ) ;
}
static void F_25 ( const T_1 V_16 [] , unsigned int V_20 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 += V_5 ) {
F_26 ( F_4 ( V_16 [ V_19 ] ) ) ;
V_26 ++ ;
}
}
static void F_27 ( struct V_8 * V_9 , T_2 V_20 )
{
struct V_1 * V_1 ;
struct V_21 * V_22 = V_9 -> V_22 ;
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
F_20 ( & V_9 -> V_23 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
V_1 = F_28 ( V_22 ) ;
if ( ! V_1 )
break;
F_16 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_25 -= V_5 ;
}
F_9 ( V_9 , V_9 -> V_28 ) ;
F_24 ( & V_9 -> V_23 ) ;
F_25 ( V_9 -> V_16 , V_9 -> V_17 ) ;
}
static inline void F_29 ( struct V_8 * V_9 , int V_29 ,
T_3 V_30 , T_4 V_31 )
{
F_5 ( V_29 >= V_32 ) ;
V_9 -> V_33 [ V_29 ] . V_30 = V_30 ;
V_9 -> V_33 [ V_29 ] . V_31 = V_31 ;
}
static void F_30 ( struct V_8 * V_9 )
{
unsigned long V_34 [ V_35 ] ;
struct V_36 V_19 ;
int V_29 = 0 ;
F_31 ( V_34 ) ;
F_32 ( & V_19 ) ;
F_29 ( V_9 , V_29 ++ , V_37 ,
F_33 ( V_34 [ V_38 ] ) ) ;
F_29 ( V_9 , V_29 ++ , V_39 ,
F_33 ( V_34 [ V_40 ] ) ) ;
F_29 ( V_9 , V_29 ++ , V_41 , V_34 [ V_42 ] ) ;
F_29 ( V_9 , V_29 ++ , V_43 , V_34 [ V_44 ] ) ;
F_29 ( V_9 , V_29 ++ , V_45 ,
F_33 ( V_19 . V_46 ) ) ;
F_29 ( V_9 , V_29 ++ , V_47 ,
F_33 ( V_19 . V_48 ) ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
V_9 -> V_49 = 1 ;
F_8 ( & V_9 -> V_50 ) ;
}
static void F_35 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 ;
V_9 -> V_49 = 0 ;
F_30 ( V_9 ) ;
V_7 = V_9 -> V_51 ;
if ( ! F_15 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_33 , sizeof( V_9 -> V_33 ) ) ;
if ( F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) < 0 )
F_12 () ;
F_13 ( V_7 ) ;
}
static void F_36 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_8 ( & V_9 -> V_50 ) ;
}
static inline T_5 F_37 ( struct V_8 * V_9 )
{
T_6 V_53 ;
T_5 V_54 ;
V_9 -> V_10 -> V_55 -> V_56 ( V_9 -> V_10 ,
F_38 ( struct V_57 , V_25 ) ,
& V_53 , sizeof( V_53 ) ) ;
V_54 = F_39 ( V_53 ) ;
return V_54 - V_9 -> V_25 ;
}
static void F_40 ( struct V_8 * V_9 )
{
T_6 V_58 = F_41 ( V_9 -> V_25 ) ;
V_9 -> V_10 -> V_55 -> V_59 ( V_9 -> V_10 ,
F_38 ( struct V_57 , V_58 ) ,
& V_58 , sizeof( V_58 ) ) ;
}
static int F_42 ( void * V_60 )
{
struct V_8 * V_9 = V_60 ;
F_43 () ;
while ( ! F_44 () ) {
T_5 V_61 ;
F_45 () ;
F_46 ( V_9 -> V_50 ,
( V_61 = F_37 ( V_9 ) ) != 0
|| V_9 -> V_49
|| F_44 ()
|| F_47 ( V_62 ) ) ;
if ( V_9 -> V_49 )
F_35 ( V_9 ) ;
if ( V_61 > 0 )
F_17 ( V_9 , V_61 ) ;
else if ( V_61 < 0 )
F_27 ( V_9 , - V_61 ) ;
F_40 ( V_9 ) ;
}
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_6 * V_63 [ 3 ] ;
T_7 * V_64 [] = { F_7 , F_7 , F_34 } ;
const char * V_65 [] = { L_2 , L_3 , L_4 } ;
int V_66 , V_67 ;
V_67 = F_49 ( V_9 -> V_10 , V_68 ) ? 3 : 2 ;
V_66 = V_9 -> V_10 -> V_55 -> V_69 ( V_9 -> V_10 , V_67 , V_63 , V_64 , V_65 ) ;
if ( V_66 )
return V_66 ;
V_9 -> V_27 = V_63 [ 0 ] ;
V_9 -> V_28 = V_63 [ 1 ] ;
if ( F_49 ( V_9 -> V_10 , V_68 ) ) {
struct V_13 V_14 ;
V_9 -> V_51 = V_63 [ 2 ] ;
F_10 ( & V_14 , V_9 -> V_33 , sizeof V_9 -> V_33 ) ;
if ( F_11 ( V_9 -> V_51 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_12 () ;
F_13 ( V_9 -> V_51 ) ;
}
return 0 ;
}
int F_50 ( struct V_70 * V_71 ,
struct V_1 * V_72 , struct V_1 * V_1 , enum V_73 V_74 )
{
struct V_21 * V_22 = F_51 ( V_1 ) ;
struct V_8 * V_9 ;
unsigned long V_75 ;
F_5 ( ! V_22 ) ;
V_9 = V_22 -> V_76 ;
if ( ! F_52 ( & V_9 -> V_23 ) )
return - V_77 ;
F_53 ( & V_22 -> V_78 , V_75 ) ;
F_54 ( V_72 , V_71 , & V_22 -> V_79 ) ;
V_22 -> V_80 -- ;
F_55 ( & V_22 -> V_78 , V_75 ) ;
V_9 -> V_17 = V_5 ;
F_16 ( V_9 -> V_16 , V_72 ) ;
F_9 ( V_9 , V_9 -> V_27 ) ;
F_56 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_16 ( V_9 -> V_16 , V_1 ) ;
F_9 ( V_9 , V_9 -> V_28 ) ;
F_24 ( & V_9 -> V_23 ) ;
return V_81 ;
}
static int F_57 ( struct V_52 * V_10 )
{
struct V_8 * V_9 ;
struct V_70 * V_82 ;
struct V_21 * V_83 ;
int V_66 ;
V_10 -> V_11 = V_9 = F_58 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_66 = - V_84 ;
goto V_85;
}
V_9 -> V_25 = 0 ;
F_59 ( & V_9 -> V_23 ) ;
F_60 ( & V_9 -> V_50 ) ;
F_60 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_49 = 0 ;
V_83 = F_61 ( V_9 ) ;
if ( F_62 ( V_83 ) ) {
V_66 = F_63 ( V_83 ) ;
goto V_86;
}
V_82 = F_64 ( V_83 ,
( F_65 () ) ?
& V_87 : NULL ) ;
if ( F_62 ( V_82 ) ) {
V_66 = F_63 ( V_82 ) ;
if ( V_66 != - V_88 )
goto V_89;
}
V_9 -> V_22 = V_83 ;
V_66 = F_48 ( V_9 ) ;
if ( V_66 )
goto V_90;
V_9 -> V_91 = F_66 ( F_42 , V_9 , L_5 ) ;
if ( F_62 ( V_9 -> V_91 ) ) {
V_66 = F_63 ( V_9 -> V_91 ) ;
goto V_92;
}
return 0 ;
V_92:
V_10 -> V_55 -> V_93 ( V_10 ) ;
V_90:
F_67 ( V_82 ) ;
V_89:
F_68 ( V_83 ) ;
V_86:
F_69 ( V_9 ) ;
V_85:
return V_66 ;
}
static void F_70 ( struct V_8 * V_9 )
{
while ( V_9 -> V_25 )
F_27 ( V_9 , V_9 -> V_25 ) ;
F_40 ( V_9 ) ;
V_9 -> V_10 -> V_55 -> V_94 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_55 -> V_93 ( V_9 -> V_10 ) ;
}
static void F_71 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_72 ( V_9 -> V_91 ) ;
F_70 ( V_9 ) ;
F_67 ( V_9 -> V_22 -> V_71 ) ;
F_68 ( V_9 -> V_22 ) ;
F_69 ( V_9 ) ;
}
static int F_73 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_70 ( V_9 ) ;
return 0 ;
}
static int F_74 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_95 ;
V_95 = F_48 ( V_10 -> V_11 ) ;
if ( V_95 )
return V_95 ;
F_17 ( V_9 , F_37 ( V_9 ) ) ;
F_40 ( V_9 ) ;
return 0 ;
}
