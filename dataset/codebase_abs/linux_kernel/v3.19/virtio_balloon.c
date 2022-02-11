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
if ( ! F_14 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_33 , sizeof( V_9 -> V_33 ) ) ;
F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_12 ( V_7 ) ;
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
F_38 ( V_9 -> V_10 , struct V_55 , V_25 , & V_53 ) ;
V_54 = F_39 ( V_53 ) ;
return V_54 - V_9 -> V_25 ;
}
static void F_40 ( struct V_8 * V_9 )
{
T_6 V_56 = F_41 ( V_9 -> V_25 ) ;
F_42 ( V_9 -> V_10 , struct V_55 , V_56 ,
& V_56 ) ;
}
static int F_43 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_60 )
{
struct V_8 * V_9 ;
unsigned long * V_61 ;
unsigned V_27 ;
V_9 = F_44 ( V_58 , struct V_8 , V_62 ) ;
if ( ! F_45 ( V_9 -> V_10 , V_63 ) )
return V_64 ;
V_61 = V_60 ;
V_27 = F_27 ( V_9 , V_65 ) ;
F_40 ( V_9 ) ;
* V_61 += V_27 ;
return V_64 ;
}
static int F_46 ( void * V_66 )
{
struct V_8 * V_9 = V_66 ;
F_47 () ;
while ( ! F_48 () ) {
T_5 V_67 ;
F_49 () ;
F_50 ( V_9 -> V_50 ,
( V_67 = F_37 ( V_9 ) ) != 0
|| V_9 -> V_49
|| F_48 ()
|| F_51 ( V_68 ) ) ;
if ( V_9 -> V_49 )
F_35 ( V_9 ) ;
if ( V_67 > 0 )
F_16 ( V_9 , V_67 ) ;
else if ( V_67 < 0 )
F_27 ( V_9 , - V_67 ) ;
F_40 ( V_9 ) ;
F_52 () ;
}
return 0 ;
}
static int F_53 ( struct V_8 * V_9 )
{
struct V_6 * V_69 [ 3 ] ;
T_7 * V_70 [] = { F_7 , F_7 , F_34 } ;
const char * V_71 [] = { L_2 , L_3 , L_4 } ;
int V_72 , V_73 ;
V_73 = F_45 ( V_9 -> V_10 , V_74 ) ? 3 : 2 ;
V_72 = V_9 -> V_10 -> V_75 -> V_76 ( V_9 -> V_10 , V_73 , V_69 , V_70 , V_71 ) ;
if ( V_72 )
return V_72 ;
V_9 -> V_26 = V_69 [ 0 ] ;
V_9 -> V_28 = V_69 [ 1 ] ;
if ( F_45 ( V_9 -> V_10 , V_74 ) ) {
struct V_13 V_14 ;
V_9 -> V_51 = V_69 [ 2 ] ;
F_10 ( & V_14 , V_9 -> V_33 , sizeof V_9 -> V_33 ) ;
if ( F_11 ( V_9 -> V_51 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_54 () ;
F_12 ( V_9 -> V_51 ) ;
}
return 0 ;
}
static int F_55 ( struct V_21 * V_22 ,
struct V_1 * V_77 , struct V_1 * V_1 , enum V_78 V_79 )
{
struct V_8 * V_9 = F_44 ( V_22 ,
struct V_8 , V_22 ) ;
unsigned long V_80 ;
if ( ! F_56 ( & V_9 -> V_23 ) )
return - V_81 ;
F_57 ( V_77 ) ;
F_58 ( & V_22 -> V_82 , V_80 ) ;
F_59 ( V_22 , V_77 ) ;
V_22 -> V_83 -- ;
F_60 ( V_84 ) ;
F_61 ( & V_22 -> V_82 , V_80 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 -> V_16 , V_77 ) ;
F_9 ( V_9 , V_9 -> V_26 ) ;
F_62 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 -> V_16 , V_1 ) ;
F_9 ( V_9 , V_9 -> V_28 ) ;
F_24 ( & V_9 -> V_23 ) ;
F_26 ( V_1 ) ;
return V_85 ;
}
static int F_63 ( struct V_52 * V_10 )
{
struct V_8 * V_9 ;
int V_72 ;
V_10 -> V_11 = V_9 = F_64 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_72 = - V_86 ;
goto V_87;
}
V_9 -> V_25 = 0 ;
F_65 ( & V_9 -> V_23 ) ;
F_66 ( & V_9 -> V_50 ) ;
F_66 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_49 = 0 ;
F_67 ( & V_9 -> V_22 ) ;
#ifdef F_68
V_9 -> V_22 . V_88 = F_55 ;
#endif
V_72 = F_53 ( V_9 ) ;
if ( V_72 )
goto V_89;
V_9 -> V_62 . V_90 = F_43 ;
V_9 -> V_62 . V_91 = V_92 ;
V_72 = F_69 ( & V_9 -> V_62 ) ;
if ( V_72 < 0 )
goto V_93;
V_9 -> V_94 = F_70 ( F_46 , V_9 , L_5 ) ;
if ( F_71 ( V_9 -> V_94 ) ) {
V_72 = F_72 ( V_9 -> V_94 ) ;
goto V_95;
}
return 0 ;
V_95:
F_73 ( & V_9 -> V_62 ) ;
V_93:
V_10 -> V_75 -> V_96 ( V_10 ) ;
V_89:
F_74 ( V_9 ) ;
V_87:
return V_72 ;
}
static void F_75 ( struct V_8 * V_9 )
{
while ( V_9 -> V_25 )
F_27 ( V_9 , V_9 -> V_25 ) ;
F_40 ( V_9 ) ;
V_9 -> V_10 -> V_75 -> V_97 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_75 -> V_96 ( V_9 -> V_10 ) ;
}
static void F_76 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_73 ( & V_9 -> V_62 ) ;
F_77 ( V_9 -> V_94 ) ;
F_75 ( V_9 ) ;
F_74 ( V_9 ) ;
}
static int F_78 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_75 ( V_9 ) ;
return 0 ;
}
static int F_79 ( struct V_52 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_98 ;
V_98 = F_53 ( V_10 -> V_11 ) ;
if ( V_98 )
return V_98 ;
F_80 ( V_10 ) ;
F_16 ( V_9 , F_37 ( V_9 ) ) ;
F_40 ( V_9 ) ;
return 0 ;
}
