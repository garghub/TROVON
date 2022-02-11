static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_2 V_6 ;
F_2 ( ! F_3 ( & V_4 -> V_7 ) ) ;
V_6 = F_4 ( V_2 ) ;
V_5 = F_5 ( V_2 , V_6 ) ;
if ( V_5 ) {
F_6 ( V_4 -> V_4 , L_1 ) ;
return 0 ;
}
return F_7 ( & V_2 -> V_8 ) ;
}
static bool F_8 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 & V_12 )
return true ;
if ( ( V_10 -> V_11 & V_13 ) && V_10 -> V_14 -> V_15 == 1 )
return true ;
return false ;
}
static void F_9 ( struct V_1 * V_2 ,
enum V_16 V_17 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
int V_23 = V_21 -> V_24 [ V_17 ] . V_25 ;
T_2 V_6 = V_26 * V_23 ;
T_3 V_27 = F_1 ( V_2 ) +
( V_19 -> V_28 << V_29 ) ;
const int V_30 = 1 + ( ( V_10 -> V_31 << V_17 ) / V_26 ) ;
if ( V_30 > 1 ) {
int V_32 ;
for ( V_32 = V_23 ; V_32 > 0 ; V_32 -- ) {
F_11 ( V_2 -> V_4 -> V_33 -> V_34 ,
V_27 , V_26 , 1 ) ;
V_27 += V_26 * V_30 ;
}
} else {
F_11 ( V_2 -> V_4 -> V_33 -> V_34 ,
V_27 , V_6 , 1 ) ;
}
V_19 -> V_2 = NULL ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
if ( V_10 -> V_11 & V_35 ) {
enum V_16 V_17 = F_13 ( V_10 -> V_11 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
struct V_18 * V_19 =
& V_21 -> V_24 [ V_17 ] . V_19 [ V_32 ] ;
if ( V_19 -> V_2 == V_2 )
F_9 ( V_2 , V_17 , V_19 ) ;
}
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_37 * * V_38 ;
int V_39 = V_2 -> V_6 >> V_29 ;
int V_32 , V_5 ;
T_4 * V_40 ;
F_2 ( V_10 -> V_38 ) ;
V_38 = F_15 ( V_2 ) ;
if ( F_16 ( V_38 ) ) {
F_6 ( V_2 -> V_4 -> V_4 , L_2 , F_17 ( V_38 ) ) ;
return F_17 ( V_38 ) ;
}
if ( V_10 -> V_11 & ( V_41 | V_42 ) ) {
V_40 = F_18 ( V_39 * sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 ) {
V_5 = - V_44 ;
goto V_45;
}
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
V_40 [ V_32 ] = F_19 ( V_4 -> V_4 , V_38 [ V_32 ] ,
0 , V_26 , V_46 ) ;
if ( F_20 ( V_4 -> V_4 , V_40 [ V_32 ] ) ) {
F_21 ( V_4 -> V_4 ,
L_3 , V_47 ) ;
for ( V_32 = V_32 - 1 ; V_32 >= 0 ; -- V_32 ) {
F_22 ( V_4 -> V_4 , V_40 [ V_32 ] ,
V_26 , V_46 ) ;
}
V_5 = - V_44 ;
goto V_48;
}
}
} else {
V_40 = F_23 ( V_39 * sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 ) {
V_5 = - V_44 ;
goto V_45;
}
}
V_10 -> V_40 = V_40 ;
V_10 -> V_38 = V_38 ;
return 0 ;
V_48:
F_24 ( V_40 ) ;
V_45:
F_25 ( V_2 , V_38 , true , false ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_37 * * * V_38 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
if ( ( V_10 -> V_11 & V_49 ) && ! V_10 -> V_38 ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_4 ) ;
return V_5 ;
}
}
* V_38 = V_10 -> V_38 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( V_10 -> V_11 & ( V_41 | V_42 ) ) {
int V_32 , V_39 = V_2 -> V_6 >> V_29 ;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
F_22 ( V_2 -> V_4 -> V_4 , V_10 -> V_40 [ V_32 ] ,
V_26 , V_46 ) ;
}
}
F_24 ( V_10 -> V_40 ) ;
V_10 -> V_40 = NULL ;
F_25 ( V_2 , V_10 -> V_38 , true , false ) ;
V_10 -> V_38 = NULL ;
}
T_5 F_28 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) -> V_11 ;
}
T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_50 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
V_50 = F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_50 ;
}
T_2 F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_2 V_6 = V_2 -> V_6 ;
if ( V_10 -> V_11 & V_35 ) {
V_6 = F_32 ( F_13 ( V_10 -> V_11 ) ,
V_10 -> V_31 , V_10 -> V_25 ) ;
}
return V_6 ;
}
int F_33 ( struct V_1 * V_2 , T_6 * V_51 , T_6 * V_52 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( V_10 -> V_11 & V_35 ) {
* V_51 = V_10 -> V_31 ;
* V_52 = V_10 -> V_25 ;
return 0 ;
}
return - V_53 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_56 * V_57 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_58 ;
T_7 V_59 ;
V_59 = ( ( unsigned long ) V_57 -> V_60 -
V_55 -> V_61 ) >> V_29 ;
if ( V_10 -> V_38 ) {
F_35 ( V_2 , V_59 ) ;
V_58 = F_36 ( V_10 -> V_38 [ V_59 ] ) ;
} else {
F_37 ( ! F_8 ( V_10 ) ) ;
V_58 = ( V_10 -> V_62 >> V_29 ) + V_59 ;
}
F_38 ( L_5 , V_57 -> V_60 ,
V_58 , V_58 << V_29 ) ;
return F_39 ( V_55 , ( unsigned long ) V_57 -> V_60 ,
F_40 ( V_58 , V_63 ) ) ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_56 * V_57 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
struct V_18 * V_19 ;
enum V_16 V_17 = F_13 ( V_10 -> V_11 ) ;
struct V_37 * V_38 [ 64 ] ;
unsigned long V_58 ;
T_7 V_59 , V_64 ;
void T_8 * V_65 ;
int V_32 , V_5 , V_66 ;
const int V_23 = V_21 -> V_24 [ V_17 ] . V_25 ;
const int V_67 = V_21 -> V_24 [ V_17 ] . V_68 ;
const int V_30 = 1 + ( ( V_10 -> V_31 << V_17 ) / V_26 ) ;
V_59 = ( ( unsigned long ) V_57 -> V_60 -
V_55 -> V_61 ) >> V_29 ;
V_64 = F_42 ( V_59 , V_30 << V_67 ) ;
V_66 = V_10 -> V_31 >> V_21 -> V_24 [ V_17 ] . V_69 ;
V_65 = V_57 -> V_60 - ( ( V_59 - V_64 ) << V_29 ) ;
V_19 = & V_21 -> V_24 [ V_17 ] . V_19 [ V_21 -> V_24 [ V_17 ] . V_70 ] ;
if ( V_19 -> V_2 )
F_9 ( V_19 -> V_2 , V_17 , V_19 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_28 = V_64 ;
V_64 = ( V_64 >> V_67 ) * V_66 ;
if ( V_30 > 1 ) {
int V_27 = V_59 % V_30 ;
V_19 -> V_28 += V_27 ;
V_64 /= V_30 ;
V_66 = F_43 ( V_66 - ( V_27 << V_67 ) , V_23 ) ;
V_64 += V_27 << V_67 ;
V_65 += V_27 << V_29 ;
}
memcpy ( V_38 , & V_10 -> V_38 [ V_64 ] ,
sizeof( struct V_37 * ) * V_66 ) ;
memset ( V_38 + V_66 , 0 ,
sizeof( struct V_37 * ) * ( V_23 - V_66 ) ) ;
V_5 = F_44 ( V_19 -> V_71 , V_38 , F_45 ( V_38 ) , 0 , true ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_6 , V_5 ) ;
return V_5 ;
}
V_58 = V_19 -> V_62 >> V_29 ;
F_38 ( L_5 , V_57 -> V_60 ,
V_58 , V_58 << V_29 ) ;
for ( V_32 = V_23 ; V_32 > 0 ; V_32 -- ) {
F_39 ( V_55 , ( unsigned long ) V_65 ,
F_40 ( V_58 , V_63 ) ) ;
V_58 += V_21 -> V_24 [ V_17 ] . V_72 ;
V_65 += V_26 * V_30 ;
}
V_21 -> V_24 [ V_17 ] . V_70 = ( V_21 -> V_24 [ V_17 ] . V_70 + 1 )
% V_36 ;
return 0 ;
}
int F_46 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
struct V_1 * V_2 = V_55 -> V_73 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * * V_38 ;
int V_5 ;
F_30 ( & V_4 -> V_7 ) ;
V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_74;
if ( V_10 -> V_11 & V_35 )
V_5 = F_41 ( V_2 , V_55 , V_57 ) ;
else
V_5 = F_34 ( V_2 , V_55 , V_57 ) ;
V_74:
F_31 ( & V_4 -> V_7 ) ;
switch ( V_5 ) {
case 0 :
case - V_75 :
case - V_76 :
case - V_77 :
return V_78 ;
case - V_44 :
return V_79 ;
default:
return V_80 ;
}
}
int F_47 ( struct V_81 * V_82 , struct V_54 * V_55 )
{
int V_5 ;
V_5 = F_48 ( V_82 , V_55 ) ;
if ( V_5 ) {
F_49 ( L_7 , V_5 ) ;
return V_5 ;
}
return F_50 ( V_55 -> V_73 , V_55 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
V_55 -> V_83 &= ~ V_84 ;
V_55 -> V_83 |= V_85 ;
if ( V_10 -> V_11 & V_41 ) {
V_55 -> V_86 = F_51 ( F_52 ( V_55 -> V_83 ) ) ;
} else if ( V_10 -> V_11 & V_42 ) {
V_55 -> V_86 = F_53 ( F_52 ( V_55 -> V_83 ) ) ;
} else {
if ( F_2 ( ! V_2 -> V_82 ) )
return - V_53 ;
F_54 ( V_55 -> V_87 ) ;
V_55 -> V_88 = 0 ;
V_55 -> V_87 = F_55 ( V_2 -> V_82 ) ;
V_55 -> V_86 = F_52 ( V_55 -> V_83 ) ;
}
return 0 ;
}
int F_56 ( struct V_89 * V_81 , struct V_3 * V_4 ,
struct V_90 * args )
{
union V_91 V_92 ;
args -> V_93 = F_57 ( 0 , args -> V_31 , args -> V_94 ) ;
args -> V_6 = F_58 ( args -> V_93 * args -> V_25 ) ;
V_92 = (union V_91 ) {
. V_95 = args -> V_6 ,
} ;
return F_59 ( V_4 , V_81 , V_92 ,
V_96 | V_41 , & args -> V_97 ) ;
}
int F_60 ( struct V_89 * V_81 , struct V_3 * V_4 ,
T_5 V_97 , T_1 * V_50 )
{
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = F_61 ( V_4 , V_81 , V_97 ) ;
if ( V_2 == NULL ) {
V_5 = - V_98 ;
goto V_74;
}
* V_50 = F_29 ( V_2 ) ;
F_62 ( V_2 ) ;
V_74:
return V_5 ;
}
int F_63 ( struct V_1 * V_2 , T_5 V_99 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
int V_5 = 0 ;
if ( V_99 > V_39 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_8 , V_99 ) ;
return - V_53 ;
}
V_10 -> V_99 = V_99 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_10 -> V_71 ) {
struct V_37 * * V_38 ;
V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_74;
V_5 = F_44 ( V_10 -> V_71 , V_38 , V_39 , V_99 , true ) ;
if ( V_5 )
F_6 ( V_2 -> V_4 -> V_4 , L_9 , V_5 ) ;
}
V_74:
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
static inline bool F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
return ( V_10 -> V_11 & V_49 ) &&
( ( V_10 -> V_11 & V_100 ) == V_101 ) ;
}
void F_35 ( struct V_1 * V_2 , int V_59 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( F_64 ( V_2 ) && V_10 -> V_40 [ V_59 ] ) {
F_22 ( V_4 -> V_4 , V_10 -> V_40 [ V_59 ] ,
V_26 , V_46 ) ;
V_10 -> V_40 [ V_59 ] = 0 ;
}
}
void F_65 ( struct V_1 * V_2 ,
enum V_102 V_103 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( F_64 ( V_2 ) ) {
int V_32 , V_39 = V_2 -> V_6 >> V_29 ;
struct V_37 * * V_38 = V_10 -> V_38 ;
bool V_104 = false ;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
if ( ! V_10 -> V_40 [ V_32 ] ) {
T_4 V_105 ;
V_105 = F_19 ( V_4 -> V_4 , V_38 [ V_32 ] , 0 ,
V_26 , V_46 ) ;
if ( F_20 ( V_4 -> V_4 , V_105 ) ) {
F_21 ( V_4 -> V_4 ,
L_3 ,
V_47 ) ;
break;
}
V_104 = true ;
V_10 -> V_40 [ V_32 ] = V_105 ;
}
}
if ( V_104 ) {
F_11 ( V_2 -> V_82 -> V_106 , 0 ,
F_4 ( V_2 ) , 1 ) ;
}
}
}
int F_66 ( struct V_1 * V_2 ,
T_4 * V_62 , bool V_107 )
{
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( ! F_8 ( V_10 ) && V_107 && V_21 -> V_108 ) {
if ( V_10 -> V_109 == 0 ) {
struct V_37 * * V_38 ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
enum V_16 V_17 = F_13 ( V_10 -> V_11 ) ;
struct V_110 * V_71 ;
F_37 ( V_10 -> V_71 ) ;
V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_74;
if ( V_10 -> V_11 & V_35 ) {
V_71 = F_67 ( V_17 ,
V_10 -> V_31 ,
V_10 -> V_25 , 0 ) ;
} else {
V_71 = F_68 ( V_2 -> V_6 ) ;
}
if ( F_16 ( V_71 ) ) {
V_5 = F_17 ( V_71 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_10 , V_5 , V_17 ) ;
goto V_74;
}
V_5 = F_44 ( V_71 , V_38 , V_39 ,
V_10 -> V_99 , true ) ;
if ( V_5 ) {
F_69 ( V_71 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_11 , V_5 ) ;
goto V_74;
}
V_10 -> V_62 = F_70 ( V_71 ) ;
V_10 -> V_71 = V_71 ;
F_49 ( L_12 , & V_10 -> V_62 ) ;
}
V_10 -> V_109 ++ ;
* V_62 = V_10 -> V_62 ;
} else if ( F_8 ( V_10 ) ) {
* V_62 = V_10 -> V_62 ;
} else {
V_5 = - V_53 ;
goto V_74;
}
V_74:
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_10 -> V_109 > 0 ) {
V_10 -> V_109 -- ;
if ( V_10 -> V_109 == 0 ) {
V_5 = F_72 ( V_10 -> V_71 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_13 , V_5 ) ;
}
V_5 = F_69 ( V_10 -> V_71 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_14 , V_5 ) ;
}
V_10 -> V_62 = 0 ;
V_10 -> V_71 = NULL ;
}
}
F_31 ( & V_2 -> V_4 -> V_7 ) ;
}
int F_73 ( struct V_1 * V_2 , T_5 V_111 ,
int V_112 , int V_113 , T_4 * V_62 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = - V_53 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( ( V_10 -> V_109 > 0 ) && V_10 -> V_71 &&
( V_10 -> V_11 & V_35 ) ) {
* V_62 = F_74 ( V_10 -> V_71 , V_111 , V_112 , V_113 ) ;
V_5 = 0 ;
}
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
int F_75 ( struct V_1 * V_2 , T_5 V_111 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = - V_53 ;
if ( V_10 -> V_11 & V_35 )
V_5 = F_76 ( F_13 ( V_10 -> V_11 ) , V_111 ) ;
return V_5 ;
}
int F_77 ( struct V_1 * V_2 , struct V_37 * * * V_38 ,
bool V_107 )
{
int V_5 ;
if ( ! V_107 ) {
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( ! V_10 -> V_38 )
return - V_44 ;
* V_38 = V_10 -> V_38 ;
return 0 ;
}
F_30 ( & V_2 -> V_4 -> V_7 ) ;
V_5 = F_26 ( V_2 , V_38 ) ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
int F_78 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_79 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_2 ( ! F_3 ( & V_2 -> V_4 -> V_7 ) ) ;
if ( ! V_10 -> V_65 ) {
struct V_37 * * V_38 ;
int V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
return F_80 ( V_5 ) ;
V_10 -> V_65 = F_81 ( V_38 , V_2 -> V_6 >> V_29 ,
V_114 , F_51 ( V_115 ) ) ;
}
return V_10 -> V_65 ;
}
int F_82 ( struct V_116 * V_4 )
{
struct V_3 * V_117 = F_83 ( V_4 ) ;
struct V_20 * V_21 = V_117 -> V_22 ;
struct V_9 * V_10 ;
int V_5 = 0 ;
F_84 (omap_obj, &priv->obj_list, mm_list) {
if ( V_10 -> V_71 ) {
struct V_1 * V_2 = & V_10 -> V_118 ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
F_2 ( ! V_10 -> V_38 ) ;
V_5 = F_44 ( V_10 -> V_71 ,
V_10 -> V_38 , V_39 ,
V_10 -> V_99 , true ) ;
if ( V_5 ) {
F_6 ( V_4 , L_9 , V_5 ) ;
return V_5 ;
}
}
}
return 0 ;
}
void F_85 ( struct V_1 * V_2 , struct V_119 * V_30 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_1 V_27 ;
V_27 = F_86 ( & V_2 -> V_8 ) ;
F_87 ( V_30 , L_15 ,
V_10 -> V_11 , V_2 -> V_120 , V_2 -> V_121 . V_121 . V_122 ,
V_27 , & V_10 -> V_62 , V_10 -> V_109 ,
V_10 -> V_65 , V_10 -> V_99 ) ;
if ( V_10 -> V_11 & V_35 ) {
F_87 ( V_30 , L_16 , V_10 -> V_31 , V_10 -> V_25 ) ;
if ( V_10 -> V_71 ) {
struct V_123 * V_124 = & V_10 -> V_71 -> V_124 ;
F_87 ( V_30 , L_17 ,
V_124 -> V_125 . V_112 , V_124 -> V_125 . V_113 ,
V_124 -> V_126 . V_112 , V_124 -> V_126 . V_113 ) ;
}
} else {
F_87 ( V_30 , L_18 , V_2 -> V_6 ) ;
}
F_87 ( V_30 , L_19 ) ;
}
void F_88 ( struct V_127 * V_128 , struct V_119 * V_30 )
{
struct V_9 * V_10 ;
int V_129 = 0 ;
T_2 V_6 = 0 ;
F_84 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_118 ;
F_87 ( V_30 , L_20 ) ;
F_85 ( V_2 , V_30 ) ;
V_129 ++ ;
V_6 += V_2 -> V_6 ;
}
F_87 ( V_30 , L_21 , V_129 , V_6 ) ;
}
static inline bool F_89 ( struct V_130 * V_131 )
{
struct V_9 * V_10 = V_131 -> V_10 ;
if ( ( V_131 -> V_132 & V_133 ) &&
( V_10 -> V_134 -> V_135 < V_131 -> V_136 ) )
return true ;
if ( ( V_131 -> V_132 & V_137 ) &&
( V_10 -> V_134 -> V_138 < V_131 -> V_139 ) )
return true ;
return false ;
}
static void F_90 ( void )
{
struct V_130 * V_131 , * V_23 ;
F_91 (waiter, n, &waiters, list) {
if ( ! F_89 ( V_131 ) ) {
F_92 ( & V_131 -> V_128 ) ;
F_93 ( L_22 , V_131 ) ;
V_131 -> V_140 ( V_131 -> V_141 ) ;
F_24 ( V_131 ) ;
}
}
}
static inline int F_94 ( struct V_1 * V_2 ,
enum V_142 V_132 , bool V_143 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_95 ( & V_144 ) ;
if ( ! V_10 -> V_134 ) {
V_10 -> V_134 = F_23 ( sizeof( * V_10 -> V_134 ) , V_145 ) ;
if ( ! V_10 -> V_134 ) {
V_5 = - V_44 ;
goto V_146;
}
}
if ( V_143 ) {
if ( V_132 & V_133 )
V_10 -> V_134 -> V_147 ++ ;
if ( V_132 & V_137 )
V_10 -> V_134 -> V_148 ++ ;
} else {
if ( V_132 & V_133 )
V_10 -> V_134 -> V_138 ++ ;
if ( V_132 & V_137 )
V_10 -> V_134 -> V_135 ++ ;
F_90 () ;
}
V_146:
F_96 ( & V_144 ) ;
return V_5 ;
}
int F_97 ( struct V_1 * V_2 , enum V_142 V_132 )
{
return F_94 ( V_2 , V_132 , true ) ;
}
int F_98 ( struct V_1 * V_2 , enum V_142 V_132 )
{
return F_94 ( V_2 , V_132 , false ) ;
}
static void F_99 ( void * V_141 )
{
struct V_149 * * V_150 = V_141 ;
* V_150 = NULL ;
F_100 ( & V_151 ) ;
}
int F_101 ( struct V_1 * V_2 , enum V_142 V_132 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
if ( V_10 -> V_134 ) {
struct V_149 * V_150 = V_152 ;
struct V_130 * V_131 =
F_23 ( sizeof( * V_131 ) , V_43 ) ;
if ( ! V_131 )
return - V_44 ;
V_131 -> V_10 = V_10 ;
V_131 -> V_132 = V_132 ;
V_131 -> V_139 = V_10 -> V_134 -> V_147 ;
V_131 -> V_136 = V_10 -> V_134 -> V_148 ;
V_131 -> V_140 = F_99 ;
V_131 -> V_141 = & V_150 ;
F_95 ( & V_144 ) ;
if ( F_89 ( V_131 ) ) {
F_93 ( L_23 , V_131 ) ;
F_102 ( & V_131 -> V_128 , & V_153 ) ;
F_96 ( & V_144 ) ;
V_5 = F_103 ( V_151 ,
( V_150 == NULL ) ) ;
F_95 ( & V_144 ) ;
if ( V_150 ) {
F_93 ( L_24 , V_131 ) ;
F_92 ( & V_131 -> V_128 ) ;
V_150 = NULL ;
} else {
V_131 = NULL ;
}
}
F_96 ( & V_144 ) ;
F_24 ( V_131 ) ;
}
return V_5 ;
}
int F_104 ( struct V_1 * V_2 , enum V_142 V_132 ,
void (* F_105)( void * V_141 ) , void * V_141 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( V_10 -> V_134 ) {
struct V_130 * V_131 =
F_23 ( sizeof( * V_131 ) , V_145 ) ;
if ( ! V_131 )
return - V_44 ;
V_131 -> V_10 = V_10 ;
V_131 -> V_132 = V_132 ;
V_131 -> V_139 = V_10 -> V_134 -> V_147 ;
V_131 -> V_136 = V_10 -> V_134 -> V_148 ;
V_131 -> V_140 = F_105 ;
V_131 -> V_141 = V_141 ;
F_95 ( & V_144 ) ;
if ( F_89 ( V_131 ) ) {
F_93 ( L_23 , V_131 ) ;
F_102 ( & V_131 -> V_128 , & V_153 ) ;
F_96 ( & V_144 ) ;
return 0 ;
}
F_96 ( & V_144 ) ;
F_24 ( V_131 ) ;
}
F_105 ( V_141 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_12 ( V_2 ) ;
F_2 ( ! F_3 ( & V_4 -> V_7 ) ) ;
F_95 ( & V_21 -> V_154 ) ;
F_92 ( & V_10 -> V_155 ) ;
F_96 ( & V_21 -> V_154 ) ;
F_2 ( V_10 -> V_109 > 0 ) ;
if ( V_10 -> V_38 ) {
if ( V_10 -> V_11 & V_13 )
F_24 ( V_10 -> V_38 ) ;
else
F_27 ( V_2 ) ;
}
if ( V_10 -> V_11 & V_12 ) {
F_107 ( V_4 -> V_4 , V_2 -> V_6 , V_10 -> V_65 ,
V_10 -> V_62 ) ;
} else if ( V_10 -> V_65 ) {
F_108 ( V_10 -> V_65 ) ;
} else if ( V_2 -> V_156 ) {
F_109 ( V_2 , V_10 -> V_14 ) ;
}
F_24 ( V_10 -> V_134 ) ;
F_110 ( V_2 ) ;
F_24 ( V_10 ) ;
}
struct V_1 * F_111 ( struct V_3 * V_4 ,
union V_91 V_92 , T_5 V_11 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_157 * V_158 ;
T_2 V_6 ;
int V_5 ;
if ( V_11 & V_35 ) {
if ( ! V_21 -> V_24 ) {
F_6 ( V_4 -> V_4 , L_25 ) ;
return NULL ;
}
V_11 &= ~ V_96 ;
V_11 |= V_49 ;
V_11 &= ~ ( V_101 | V_41 | V_42 ) ;
V_11 |= F_112 () ;
} else if ( ( V_11 & V_96 ) && ! V_21 -> V_108 ) {
V_11 |= V_12 ;
} else if ( ! ( V_11 & V_13 ) ) {
V_11 |= V_49 ;
}
V_10 = F_23 ( sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_118 ;
V_10 -> V_11 = V_11 ;
if ( V_11 & V_35 ) {
F_113 ( F_13 ( V_11 ) , & V_92 . V_159 . V_31 ,
& V_92 . V_159 . V_25 ) ;
V_6 = F_114 ( F_13 ( V_11 ) , V_92 . V_159 . V_31 ,
V_92 . V_159 . V_25 ) ;
V_10 -> V_31 = V_92 . V_159 . V_31 ;
V_10 -> V_25 = V_92 . V_159 . V_25 ;
} else {
V_6 = F_58 ( V_92 . V_95 ) ;
}
if ( ! ( V_11 & V_49 ) ) {
F_115 ( V_4 , V_2 , V_6 ) ;
} else {
V_5 = F_116 ( V_4 , V_2 , V_6 ) ;
if ( V_5 )
goto V_160;
V_158 = F_117 ( V_2 -> V_82 ) -> V_34 ;
F_118 ( V_158 , V_161 | V_162 ) ;
}
if ( V_11 & V_12 ) {
V_10 -> V_65 = F_119 ( V_4 -> V_4 , V_6 ,
& V_10 -> V_62 ,
V_43 ) ;
if ( ! V_10 -> V_65 )
goto V_163;
}
F_95 ( & V_21 -> V_154 ) ;
F_120 ( & V_10 -> V_155 , & V_21 -> V_164 ) ;
F_96 ( & V_21 -> V_154 ) ;
return V_2 ;
V_163:
F_110 ( V_2 ) ;
V_160:
F_24 ( V_10 ) ;
return NULL ;
}
struct V_1 * F_121 ( struct V_3 * V_4 , T_2 V_6 ,
struct V_165 * V_14 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
union V_91 V_92 ;
if ( V_14 -> V_166 != 1 && ! V_21 -> V_108 )
return F_80 ( - V_53 ) ;
F_30 ( & V_4 -> V_7 ) ;
V_92 . V_95 = F_58 ( V_6 ) ;
V_2 = F_111 ( V_4 , V_92 , V_13 | V_41 ) ;
if ( ! V_2 ) {
V_2 = F_80 ( - V_44 ) ;
goto V_167;
}
V_10 = F_10 ( V_2 ) ;
V_10 -> V_14 = V_14 ;
if ( V_14 -> V_166 == 1 ) {
V_10 -> V_62 = F_122 ( V_14 -> V_168 ) ;
} else {
struct V_169 V_170 ;
struct V_37 * * V_38 ;
unsigned int V_39 ;
unsigned int V_32 = 0 ;
V_39 = F_123 ( V_6 , V_26 ) ;
V_38 = F_124 ( V_39 , sizeof( * V_38 ) , V_43 ) ;
if ( ! V_38 ) {
F_106 ( V_2 ) ;
V_2 = F_80 ( - V_44 ) ;
goto V_167;
}
V_10 -> V_38 = V_38 ;
F_125 (sgt->sgl, &iter, sgt->orig_nents, 0 ) {
V_38 [ V_32 ++ ] = F_126 ( & V_170 ) ;
if ( V_32 > V_39 )
break;
}
if ( F_2 ( V_32 != V_39 ) ) {
F_106 ( V_2 ) ;
V_2 = F_80 ( - V_44 ) ;
goto V_167;
}
}
V_167:
F_31 ( & V_4 -> V_7 ) ;
return V_2 ;
}
int F_59 ( struct V_3 * V_4 , struct V_89 * V_81 ,
union V_91 V_92 , T_5 V_11 , T_5 * V_97 )
{
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_111 ( V_4 , V_92 , V_11 ) ;
if ( ! V_2 )
return - V_44 ;
V_5 = F_127 ( V_81 , V_2 , V_97 ) ;
if ( V_5 ) {
F_106 ( V_2 ) ;
return V_5 ;
}
F_62 ( V_2 ) ;
return 0 ;
}
void F_128 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_171 * V_24 ;
const enum V_16 V_172 [] = {
V_173 , V_174 , V_175
} ;
int V_32 , V_176 ;
if ( ! F_129 () ) {
F_21 ( V_4 -> V_4 , L_26 ) ;
return;
}
V_24 = F_124 ( 3 , sizeof( * V_24 ) , V_43 ) ;
if ( ! V_24 )
return;
for ( V_32 = 0 ; V_32 < F_45 ( V_172 ) ; V_32 ++ ) {
T_6 V_52 = 1 , V_51 = V_26 >> V_32 ;
F_113 ( V_172 [ V_32 ] , & V_51 , & V_52 ) ;
V_24 [ V_32 ] . V_25 = V_52 ;
V_24 [ V_32 ] . V_68 = F_130 ( V_52 ) ;
V_24 [ V_32 ] . V_72 = F_76 ( V_172 [ V_32 ] , 0 ) >> V_29 ;
V_24 [ V_32 ] . V_69 = F_130 ( ( V_26 / V_52 ) >> V_32 ) ;
for ( V_176 = 0 ; V_176 < V_36 ; V_176 ++ ) {
struct V_18 * V_19 ;
struct V_110 * V_71 ;
V_19 = & V_24 [ V_32 ] . V_19 [ V_176 ] ;
V_71 = F_67 ( V_172 [ V_32 ] , V_51 , V_52 , V_26 ) ;
if ( F_16 ( V_71 ) ) {
F_6 ( V_4 -> V_4 ,
L_27 ,
V_32 , V_176 , F_17 ( V_71 ) ) ;
return;
}
V_19 -> V_62 = F_70 ( V_71 ) ;
V_19 -> V_71 = V_71 ;
F_49 ( L_28 , V_32 , V_176 , V_51 , V_52 ,
& V_19 -> V_62 ,
V_24 [ V_32 ] . V_72 << V_29 ) ;
}
}
V_21 -> V_24 = V_24 ;
V_21 -> V_108 = true ;
}
void F_131 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
F_24 ( V_21 -> V_24 ) ;
}
