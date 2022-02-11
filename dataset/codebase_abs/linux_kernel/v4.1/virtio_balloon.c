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
F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_12 ( V_7 ) ;
F_13 ( V_9 -> V_12 , F_14 ( V_7 , & V_15 ) ) ;
}
static void F_15 ( T_1 V_16 [] , struct V_1 * V_1 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_16 [ V_19 ] = F_1 ( V_1 ) + V_19 ;
}
static void F_16 ( struct V_8 * V_9 , T_2 V_20 )
{
struct V_21 * V_22 = & V_9 -> V_22 ;
V_20 = F_17 ( V_20 , F_18 ( V_9 -> V_16 ) ) ;
F_19 ( & V_9 -> V_23 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
struct V_1 * V_1 = F_20 ( V_22 ) ;
if ( ! V_1 ) {
F_21 ( & V_9 -> V_10 -> V_24 ,
L_1 ,
V_5 ) ;
F_22 ( 200 ) ;
break;
}
F_15 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_25 += V_5 ;
F_23 ( V_1 , - 1 ) ;
}
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_26 ) ;
F_24 ( & V_9 -> V_23 ) ;
}
static void F_25 ( const T_1 V_16 [] , unsigned int V_20 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 += V_5 ) {
struct V_1 * V_1 = F_4 ( V_16 [ V_19 ] ) ;
F_23 ( V_1 , 1 ) ;
F_26 ( V_1 ) ;
}
}
static unsigned F_27 ( struct V_8 * V_9 , T_2 V_20 )
{
unsigned V_27 ;
struct V_1 * V_1 ;
struct V_21 * V_22 = & V_9 -> V_22 ;
V_20 = F_17 ( V_20 , F_18 ( V_9 -> V_16 ) ) ;
F_19 ( & V_9 -> V_23 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
V_1 = F_28 ( V_22 ) ;
if ( ! V_1 )
break;
F_15 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_25 -= V_5 ;
}
V_27 = V_9 -> V_17 ;
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_28 ) ;
F_24 ( & V_9 -> V_23 ) ;
F_25 ( V_9 -> V_16 , V_9 -> V_17 ) ;
return V_27 ;
}
static inline void F_29 ( struct V_8 * V_9 , int V_29 ,
T_3 V_30 , T_4 V_31 )
{
F_5 ( V_29 >= V_32 ) ;
V_9 -> V_33 [ V_29 ] . V_30 = F_30 ( V_9 -> V_10 , V_30 ) ;
V_9 -> V_33 [ V_29 ] . V_31 = F_31 ( V_9 -> V_10 , V_31 ) ;
}
static void F_32 ( struct V_8 * V_9 )
{
unsigned long V_34 [ V_35 ] ;
struct V_36 V_19 ;
int V_29 = 0 ;
F_33 ( V_34 ) ;
F_34 ( & V_19 ) ;
F_29 ( V_9 , V_29 ++ , V_37 ,
F_35 ( V_34 [ V_38 ] ) ) ;
F_29 ( V_9 , V_29 ++ , V_39 ,
F_35 ( V_34 [ V_40 ] ) ) ;
F_29 ( V_9 , V_29 ++ , V_41 , V_34 [ V_42 ] ) ;
F_29 ( V_9 , V_29 ++ , V_43 , V_34 [ V_44 ] ) ;
F_29 ( V_9 , V_29 ++ , V_45 ,
F_35 ( V_19 . V_46 ) ) ;
F_29 ( V_9 , V_29 ++ , V_47 ,
F_35 ( V_19 . V_48 ) ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
V_9 -> V_49 = 1 ;
F_8 ( & V_9 -> V_50 ) ;
}
static void F_37 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 ;
V_9 -> V_49 = 0 ;
F_32 ( V_9 ) ;
V_7 = V_9 -> V_51 ;
if ( ! F_14 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_33 , sizeof( V_9 -> V_33 ) ) ;
F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_12 ( V_7 ) ;
}
static void F_38 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_8 ( & V_9 -> V_50 ) ;
}
static inline T_5 F_39 ( struct V_8 * V_9 )
{
T_5 V_53 ;
T_1 V_25 ;
F_40 ( V_9 -> V_10 , struct V_54 , V_25 ,
& V_25 ) ;
if ( ! F_41 ( V_9 -> V_10 , V_55 ) )
V_25 = F_42 ( ( V_56 V_57 ) V_25 ) ;
V_53 = V_25 ;
return V_53 - V_9 -> V_25 ;
}
static void F_43 ( struct V_8 * V_9 )
{
T_1 V_58 = V_9 -> V_25 ;
if ( ! F_41 ( V_9 -> V_10 , V_55 ) )
V_58 = ( V_56 T_1 ) F_44 ( V_58 ) ;
F_45 ( V_9 -> V_10 , struct V_54 , V_58 ,
& V_58 ) ;
}
static int F_46 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_62 )
{
struct V_8 * V_9 ;
unsigned long * V_63 ;
unsigned V_27 ;
V_9 = F_47 ( V_60 , struct V_8 , V_64 ) ;
if ( ! F_41 ( V_9 -> V_10 , V_65 ) )
return V_66 ;
V_63 = V_62 ;
V_27 = F_27 ( V_9 , V_67 ) ;
F_43 ( V_9 ) ;
* V_63 += V_27 ;
return V_66 ;
}
static int F_48 ( void * V_68 )
{
struct V_8 * V_9 = V_68 ;
F_49 ( V_69 , V_70 ) ;
F_50 () ;
while ( ! F_51 () ) {
T_5 V_71 ;
F_52 () ;
F_53 ( & V_9 -> V_50 , & V_69 ) ;
for (; ; ) {
if ( ( V_71 = F_39 ( V_9 ) ) != 0 ||
V_9 -> V_49 ||
F_51 () ||
F_54 ( V_72 ) )
break;
F_55 ( & V_69 , V_73 , V_74 ) ;
}
F_56 ( & V_9 -> V_50 , & V_69 ) ;
if ( V_9 -> V_49 )
F_37 ( V_9 ) ;
if ( V_71 > 0 )
F_16 ( V_9 , V_71 ) ;
else if ( V_71 < 0 )
F_27 ( V_9 , - V_71 ) ;
F_43 ( V_9 ) ;
F_57 () ;
}
return 0 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_6 * V_75 [ 3 ] ;
T_6 * V_76 [] = { F_7 , F_7 , F_36 } ;
const char * V_77 [] = { L_2 , L_3 , L_4 } ;
int V_78 , V_79 ;
V_79 = F_41 ( V_9 -> V_10 , V_80 ) ? 3 : 2 ;
V_78 = V_9 -> V_10 -> V_81 -> V_82 ( V_9 -> V_10 , V_79 , V_75 , V_76 , V_77 ) ;
if ( V_78 )
return V_78 ;
V_9 -> V_26 = V_75 [ 0 ] ;
V_9 -> V_28 = V_75 [ 1 ] ;
if ( F_41 ( V_9 -> V_10 , V_80 ) ) {
struct V_13 V_14 ;
V_9 -> V_51 = V_75 [ 2 ] ;
F_10 ( & V_14 , V_9 -> V_33 , sizeof V_9 -> V_33 ) ;
if ( F_11 ( V_9 -> V_51 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_59 () ;
F_12 ( V_9 -> V_51 ) ;
}
return 0 ;
}
static int F_60 ( struct V_21 * V_22 ,
struct V_1 * V_83 , struct V_1 * V_1 , enum V_84 V_85 )
{
struct V_8 * V_9 = F_47 ( V_22 ,
struct V_8 , V_22 ) ;
unsigned long V_86 ;
if ( ! F_61 ( & V_9 -> V_23 ) )
return - V_87 ;
F_62 ( V_83 ) ;
F_63 ( & V_22 -> V_88 , V_86 ) ;
F_64 ( V_22 , V_83 ) ;
V_22 -> V_89 -- ;
F_65 ( V_90 ) ;
F_66 ( & V_22 -> V_88 , V_86 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 -> V_16 , V_83 ) ;
F_9 ( V_9 , V_9 -> V_26 ) ;
F_67 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 -> V_16 , V_1 ) ;
F_9 ( V_9 , V_9 -> V_28 ) ;
F_24 ( & V_9 -> V_23 ) ;
F_26 ( V_1 ) ;
return V_91 ;
}
static int F_68 ( struct V_52 * V_10 )
{
struct V_8 * V_9 ;
int V_78 ;
if ( ! V_10 -> V_81 -> V_92 ) {
F_69 ( & V_10 -> V_24 , L_5 ,
V_93 ) ;
return - V_94 ;
}
V_10 -> V_11 = V_9 = F_70 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_78 = - V_95 ;
goto V_96;
}
V_9 -> V_25 = 0 ;
F_71 ( & V_9 -> V_23 ) ;
F_72 ( & V_9 -> V_50 ) ;
F_72 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_49 = 0 ;
F_73 ( & V_9 -> V_22 ) ;
#ifdef F_74
V_9 -> V_22 . V_97 = F_60 ;
#endif
V_78 = F_58 ( V_9 ) ;
if ( V_78 )
goto V_98;
V_9 -> V_64 . V_99 = F_46 ;
V_9 -> V_64 . V_100 = V_101 ;
V_78 = F_75 ( & V_9 -> V_64 ) ;
if ( V_78 < 0 )
goto V_102;
F_76 ( V_10 ) ;
V_9 -> V_103 = F_77 ( F_48 , V_9 , L_6 ) ;
if ( F_78 ( V_9 -> V_103 ) ) {
V_78 = F_79 ( V_9 -> V_103 ) ;
goto V_104;
}
return 0 ;
V_104:
F_80 ( & V_9 -> V_64 ) ;
V_102:
V_10 -> V_81 -> V_105 ( V_10 ) ;
V_98:
F_81 ( V_9 ) ;
V_96:
return V_78 ;
}
static void F_82 ( struct V_8 * V_9 )
{
while ( V_9 -> V_25 )
F_27 ( V_9 , V_9 -> V_25 ) ;
F_43 ( V_9 ) ;
V_9 -> V_10 -> V_81 -> V_106 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_81 -> V_105 ( V_9 -> V_10 ) ;
}
static void F_83 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_80 ( & V_9 -> V_64 ) ;
F_84 ( V_9 -> V_103 ) ;
F_82 ( V_9 ) ;
F_81 ( V_9 ) ;
}
static int F_85 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_82 ( V_9 ) ;
return 0 ;
}
static int F_86 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_107 ;
V_107 = F_58 ( V_10 -> V_11 ) ;
if ( V_107 )
return V_107 ;
F_76 ( V_10 ) ;
F_16 ( V_9 , F_39 ( V_9 ) ) ;
F_43 ( V_9 ) ;
return 0 ;
}
