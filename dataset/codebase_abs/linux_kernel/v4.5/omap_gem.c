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
static inline bool F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_9 != NULL ;
}
static void F_9 ( struct V_1 * V_2 ,
enum V_10 V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_4 -> V_18 ;
int V_19 = V_17 -> V_20 [ V_11 ] . V_21 ;
T_2 V_6 = V_22 * V_19 ;
T_3 V_23 = F_1 ( V_2 ) +
( V_13 -> V_24 << V_25 ) ;
const int V_26 = 1 + ( ( V_15 -> V_27 << V_11 ) / V_22 ) ;
if ( V_26 > 1 ) {
int V_28 ;
for ( V_28 = V_19 ; V_28 > 0 ; V_28 -- ) {
F_11 ( V_2 -> V_4 -> V_29 -> V_30 ,
V_23 , V_22 , 1 ) ;
V_23 += V_22 * V_26 ;
}
} else {
F_11 ( V_2 -> V_4 -> V_29 -> V_30 ,
V_23 , V_6 , 1 ) ;
}
V_13 -> V_2 = NULL ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_4 -> V_18 ;
if ( V_15 -> V_31 & V_32 ) {
enum V_10 V_11 = F_13 ( V_15 -> V_31 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_33 ; V_28 ++ ) {
struct V_12 * V_13 =
& V_17 -> V_20 [ V_11 ] . V_13 [ V_28 ] ;
if ( V_13 -> V_2 == V_2 )
F_9 ( V_2 , V_11 , V_13 ) ;
}
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_34 * * V_35 ;
int V_36 = V_2 -> V_6 >> V_25 ;
int V_28 , V_5 ;
T_4 * V_37 ;
F_2 ( V_15 -> V_35 ) ;
V_35 = F_15 ( V_2 ) ;
if ( F_16 ( V_35 ) ) {
F_6 ( V_2 -> V_4 -> V_4 , L_2 , F_17 ( V_35 ) ) ;
return F_17 ( V_35 ) ;
}
if ( V_15 -> V_31 & ( V_38 | V_39 ) ) {
V_37 = F_18 ( V_36 * sizeof( * V_37 ) , V_40 ) ;
if ( ! V_37 ) {
V_5 = - V_41 ;
goto V_42;
}
for ( V_28 = 0 ; V_28 < V_36 ; V_28 ++ ) {
V_37 [ V_28 ] = F_19 ( V_4 -> V_4 , V_35 [ V_28 ] ,
0 , V_22 , V_43 ) ;
}
} else {
V_37 = F_20 ( V_36 * sizeof( * V_37 ) , V_40 ) ;
if ( ! V_37 ) {
V_5 = - V_41 ;
goto V_42;
}
}
V_15 -> V_37 = V_37 ;
V_15 -> V_35 = V_35 ;
return 0 ;
V_42:
F_21 ( V_2 , V_35 , true , false ) ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_34 * * * V_35 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = 0 ;
if ( F_8 ( V_2 ) && ! V_15 -> V_35 ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_3 ) ;
return V_5 ;
}
}
* V_35 = V_15 -> V_35 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
if ( V_15 -> V_31 & ( V_38 | V_39 ) ) {
int V_28 , V_36 = V_2 -> V_6 >> V_25 ;
for ( V_28 = 0 ; V_28 < V_36 ; V_28 ++ ) {
F_24 ( V_2 -> V_4 -> V_4 , V_15 -> V_37 [ V_28 ] ,
V_22 , V_43 ) ;
}
}
F_25 ( V_15 -> V_37 ) ;
V_15 -> V_37 = NULL ;
F_21 ( V_2 , V_15 -> V_35 , true , false ) ;
V_15 -> V_35 = NULL ;
}
T_5 F_26 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) -> V_31 ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_28 ( & V_2 -> V_4 -> V_7 ) ;
V_44 = F_1 ( V_2 ) ;
F_29 ( & V_2 -> V_4 -> V_7 ) ;
return V_44 ;
}
T_2 F_4 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
T_2 V_6 = V_2 -> V_6 ;
if ( V_15 -> V_31 & V_32 ) {
V_6 = F_30 ( F_13 ( V_15 -> V_31 ) ,
V_15 -> V_27 , V_15 -> V_21 ) ;
}
return V_6 ;
}
int F_31 ( struct V_1 * V_2 , T_6 * V_45 , T_6 * V_46 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
if ( V_15 -> V_31 & V_32 ) {
* V_45 = V_15 -> V_27 ;
* V_46 = V_15 -> V_21 ;
return 0 ;
}
return - V_47 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
unsigned long V_52 ;
T_7 V_53 ;
V_53 = ( ( unsigned long ) V_51 -> V_54 -
V_49 -> V_55 ) >> V_25 ;
if ( V_15 -> V_35 ) {
F_33 ( V_2 , V_53 ) ;
V_52 = F_34 ( V_15 -> V_35 [ V_53 ] ) ;
} else {
F_35 ( ! ( V_15 -> V_31 & V_56 ) ) ;
V_52 = ( V_15 -> V_57 >> V_25 ) + V_53 ;
}
F_36 ( L_4 , V_51 -> V_54 ,
V_52 , V_52 << V_25 ) ;
return F_37 ( V_49 , ( unsigned long ) V_51 -> V_54 ,
F_38 ( V_52 , V_58 ) ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_4 -> V_18 ;
struct V_12 * V_13 ;
enum V_10 V_11 = F_13 ( V_15 -> V_31 ) ;
struct V_34 * V_35 [ 64 ] ;
unsigned long V_52 ;
T_7 V_53 , V_59 ;
void T_8 * V_60 ;
int V_28 , V_5 , V_61 ;
const int V_19 = V_17 -> V_20 [ V_11 ] . V_21 ;
const int V_62 = V_17 -> V_20 [ V_11 ] . V_63 ;
const int V_26 = 1 + ( ( V_15 -> V_27 << V_11 ) / V_22 ) ;
V_53 = ( ( unsigned long ) V_51 -> V_54 -
V_49 -> V_55 ) >> V_25 ;
V_59 = F_40 ( V_53 , V_26 << V_62 ) ;
V_61 = V_15 -> V_27 >> V_17 -> V_20 [ V_11 ] . V_64 ;
V_60 = V_51 -> V_54 - ( ( V_53 - V_59 ) << V_25 ) ;
V_13 = & V_17 -> V_20 [ V_11 ] . V_13 [ V_17 -> V_20 [ V_11 ] . V_65 ] ;
if ( V_13 -> V_2 )
F_9 ( V_13 -> V_2 , V_11 , V_13 ) ;
V_13 -> V_2 = V_2 ;
V_13 -> V_24 = V_59 ;
V_59 = ( V_59 >> V_62 ) * V_61 ;
if ( V_26 > 1 ) {
int V_23 = V_53 % V_26 ;
V_13 -> V_24 += V_23 ;
V_59 /= V_26 ;
V_61 = F_41 ( V_61 - ( V_23 << V_62 ) , V_19 ) ;
V_59 += V_23 << V_62 ;
V_60 += V_23 << V_25 ;
}
memcpy ( V_35 , & V_15 -> V_35 [ V_59 ] ,
sizeof( struct V_34 * ) * V_61 ) ;
memset ( V_35 + V_61 , 0 ,
sizeof( struct V_34 * ) * ( V_19 - V_61 ) ) ;
V_5 = F_42 ( V_13 -> V_66 , V_35 , F_43 ( V_35 ) , 0 , true ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_5 , V_5 ) ;
return V_5 ;
}
V_52 = V_13 -> V_57 >> V_25 ;
F_36 ( L_4 , V_51 -> V_54 ,
V_52 , V_52 << V_25 ) ;
for ( V_28 = V_19 ; V_28 > 0 ; V_28 -- ) {
F_37 ( V_49 , ( unsigned long ) V_60 ,
F_38 ( V_52 , V_58 ) ) ;
V_52 += V_17 -> V_20 [ V_11 ] . V_67 ;
V_60 += V_22 * V_26 ;
}
V_17 -> V_20 [ V_11 ] . V_65 = ( V_17 -> V_20 [ V_11 ] . V_65 + 1 )
% V_33 ;
return 0 ;
}
int F_44 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_1 * V_2 = V_49 -> V_68 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_34 * * V_35 ;
int V_5 ;
F_28 ( & V_4 -> V_7 ) ;
V_5 = F_22 ( V_2 , & V_35 ) ;
if ( V_5 )
goto V_69;
if ( V_15 -> V_31 & V_32 )
V_5 = F_39 ( V_2 , V_49 , V_51 ) ;
else
V_5 = F_32 ( V_2 , V_49 , V_51 ) ;
V_69:
F_29 ( & V_4 -> V_7 ) ;
switch ( V_5 ) {
case 0 :
case - V_70 :
case - V_71 :
return V_72 ;
case - V_41 :
return V_73 ;
default:
return V_74 ;
}
}
int F_45 ( struct V_75 * V_9 , struct V_48 * V_49 )
{
int V_5 ;
V_5 = F_46 ( V_9 , V_49 ) ;
if ( V_5 ) {
F_47 ( L_6 , V_5 ) ;
return V_5 ;
}
return F_48 ( V_49 -> V_68 , V_49 ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
V_49 -> V_76 &= ~ V_77 ;
V_49 -> V_76 |= V_78 ;
if ( V_15 -> V_31 & V_38 ) {
V_49 -> V_79 = F_49 ( F_50 ( V_49 -> V_76 ) ) ;
} else if ( V_15 -> V_31 & V_39 ) {
V_49 -> V_79 = F_51 ( F_50 ( V_49 -> V_76 ) ) ;
} else {
if ( F_2 ( ! V_2 -> V_9 ) )
return - V_47 ;
F_52 ( V_49 -> V_80 ) ;
V_49 -> V_81 = 0 ;
V_49 -> V_80 = F_53 ( V_2 -> V_9 ) ;
V_49 -> V_79 = F_50 ( V_49 -> V_76 ) ;
}
return 0 ;
}
int F_54 ( struct V_82 * V_75 , struct V_3 * V_4 ,
struct V_83 * args )
{
union V_84 V_85 ;
args -> V_86 = F_55 ( 0 , args -> V_27 , args -> V_87 ) ;
args -> V_6 = F_56 ( args -> V_86 * args -> V_21 ) ;
V_85 = (union V_84 ) {
. V_88 = args -> V_6 ,
} ;
return F_57 ( V_4 , V_75 , V_85 ,
V_89 | V_38 , & args -> V_90 ) ;
}
int F_58 ( struct V_82 * V_75 , struct V_3 * V_4 ,
T_5 V_90 , T_1 * V_44 )
{
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = F_59 ( V_4 , V_75 , V_90 ) ;
if ( V_2 == NULL ) {
V_5 = - V_91 ;
goto V_69;
}
* V_44 = F_27 ( V_2 ) ;
F_60 ( V_2 ) ;
V_69:
return V_5 ;
}
int F_61 ( struct V_1 * V_2 , T_5 V_92 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
T_5 V_36 = V_2 -> V_6 >> V_25 ;
int V_5 = 0 ;
if ( V_92 > V_36 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_7 , V_92 ) ;
return - V_47 ;
}
V_15 -> V_92 = V_92 ;
F_28 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_15 -> V_66 ) {
struct V_34 * * V_35 ;
V_5 = F_22 ( V_2 , & V_35 ) ;
if ( V_5 )
goto V_69;
V_5 = F_42 ( V_15 -> V_66 , V_35 , V_36 , V_92 , true ) ;
if ( V_5 )
F_6 ( V_2 -> V_4 -> V_4 , L_8 , V_5 ) ;
}
V_69:
F_29 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
static inline bool F_62 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
return F_8 ( V_2 ) &&
( ( V_15 -> V_31 & V_93 ) == V_94 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_53 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
if ( F_62 ( V_2 ) && V_15 -> V_37 [ V_53 ] ) {
F_24 ( V_4 -> V_4 , V_15 -> V_37 [ V_53 ] ,
V_22 , V_43 ) ;
V_15 -> V_37 [ V_53 ] = 0 ;
}
}
void F_63 ( struct V_1 * V_2 ,
enum V_95 V_96 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
if ( F_62 ( V_2 ) ) {
int V_28 , V_36 = V_2 -> V_6 >> V_25 ;
struct V_34 * * V_35 = V_15 -> V_35 ;
bool V_97 = false ;
for ( V_28 = 0 ; V_28 < V_36 ; V_28 ++ ) {
if ( ! V_15 -> V_37 [ V_28 ] ) {
V_15 -> V_37 [ V_28 ] = F_19 ( V_4 -> V_4 , V_35 [ V_28 ] , 0 ,
V_22 , V_43 ) ;
V_97 = true ;
}
}
if ( V_97 ) {
F_11 ( V_2 -> V_9 -> V_98 , 0 ,
F_4 ( V_2 ) , 1 ) ;
}
}
}
int F_64 ( struct V_1 * V_2 ,
T_4 * V_57 , bool V_99 )
{
struct V_16 * V_17 = V_2 -> V_4 -> V_18 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_28 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_99 && F_8 ( V_2 ) && V_17 -> V_100 ) {
if ( V_15 -> V_101 == 0 ) {
struct V_34 * * V_35 ;
T_5 V_36 = V_2 -> V_6 >> V_25 ;
enum V_10 V_11 = F_13 ( V_15 -> V_31 ) ;
struct V_102 * V_66 ;
F_35 ( V_15 -> V_66 ) ;
V_5 = F_22 ( V_2 , & V_35 ) ;
if ( V_5 )
goto V_69;
if ( V_15 -> V_31 & V_32 ) {
V_66 = F_65 ( V_11 ,
V_15 -> V_27 ,
V_15 -> V_21 , 0 ) ;
} else {
V_66 = F_66 ( V_2 -> V_6 ) ;
}
if ( F_16 ( V_66 ) ) {
V_5 = F_17 ( V_66 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_9 , V_5 , V_11 ) ;
goto V_69;
}
V_5 = F_42 ( V_66 , V_35 , V_36 ,
V_15 -> V_92 , true ) ;
if ( V_5 ) {
F_67 ( V_66 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_10 , V_5 ) ;
goto V_69;
}
V_15 -> V_57 = F_68 ( V_66 ) ;
V_15 -> V_66 = V_66 ;
F_47 ( L_11 , & V_15 -> V_57 ) ;
}
V_15 -> V_101 ++ ;
* V_57 = V_15 -> V_57 ;
} else if ( V_15 -> V_31 & V_56 ) {
* V_57 = V_15 -> V_57 ;
} else {
V_5 = - V_47 ;
goto V_69;
}
V_69:
F_29 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 ;
F_28 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_15 -> V_101 > 0 ) {
V_15 -> V_101 -- ;
if ( V_15 -> V_101 == 0 ) {
V_5 = F_70 ( V_15 -> V_66 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_12 , V_5 ) ;
}
V_5 = F_67 ( V_15 -> V_66 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_13 , V_5 ) ;
}
V_15 -> V_57 = 0 ;
V_15 -> V_66 = NULL ;
}
}
F_29 ( & V_2 -> V_4 -> V_7 ) ;
}
int F_71 ( struct V_1 * V_2 , T_5 V_103 ,
int V_104 , int V_105 , T_4 * V_57 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = - V_47 ;
F_28 ( & V_2 -> V_4 -> V_7 ) ;
if ( ( V_15 -> V_101 > 0 ) && V_15 -> V_66 &&
( V_15 -> V_31 & V_32 ) ) {
* V_57 = F_72 ( V_15 -> V_66 , V_103 , V_104 , V_105 ) ;
V_5 = 0 ;
}
F_29 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
int F_73 ( struct V_1 * V_2 , T_5 V_103 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = - V_47 ;
if ( V_15 -> V_31 & V_32 )
V_5 = F_74 ( F_13 ( V_15 -> V_31 ) , V_103 ) ;
return V_5 ;
}
int F_75 ( struct V_1 * V_2 , struct V_34 * * * V_35 ,
bool V_99 )
{
int V_5 ;
if ( ! V_99 ) {
struct V_14 * V_15 = F_10 ( V_2 ) ;
if ( ! V_15 -> V_35 )
return - V_41 ;
* V_35 = V_15 -> V_35 ;
return 0 ;
}
F_28 ( & V_2 -> V_4 -> V_7 ) ;
V_5 = F_22 ( V_2 , V_35 ) ;
F_29 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
int F_76 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_77 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
F_2 ( ! F_3 ( & V_2 -> V_4 -> V_7 ) ) ;
if ( ! V_15 -> V_60 ) {
struct V_34 * * V_35 ;
int V_5 = F_22 ( V_2 , & V_35 ) ;
if ( V_5 )
return F_78 ( V_5 ) ;
V_15 -> V_60 = F_79 ( V_35 , V_2 -> V_6 >> V_25 ,
V_106 , F_49 ( V_107 ) ) ;
}
return V_15 -> V_60 ;
}
int F_80 ( struct V_108 * V_4 )
{
struct V_3 * V_109 = F_81 ( V_4 ) ;
struct V_16 * V_17 = V_109 -> V_18 ;
struct V_14 * V_15 ;
int V_5 = 0 ;
F_82 (omap_obj, &priv->obj_list, mm_list) {
if ( V_15 -> V_66 ) {
struct V_1 * V_2 = & V_15 -> V_110 ;
T_5 V_36 = V_2 -> V_6 >> V_25 ;
F_2 ( ! V_15 -> V_35 ) ;
V_5 = F_42 ( V_15 -> V_66 ,
V_15 -> V_35 , V_36 ,
V_15 -> V_92 , true ) ;
if ( V_5 ) {
F_6 ( V_4 , L_8 , V_5 ) ;
return V_5 ;
}
}
}
return 0 ;
}
void F_83 ( struct V_1 * V_2 , struct V_111 * V_26 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
T_1 V_23 ;
V_23 = F_84 ( & V_2 -> V_8 ) ;
F_85 ( V_26 , L_14 ,
V_15 -> V_31 , V_2 -> V_112 , V_2 -> V_113 . V_113 . V_114 ,
V_23 , & V_15 -> V_57 , V_15 -> V_101 ,
V_15 -> V_60 , V_15 -> V_92 ) ;
if ( V_15 -> V_31 & V_32 ) {
F_85 ( V_26 , L_15 , V_15 -> V_27 , V_15 -> V_21 ) ;
if ( V_15 -> V_66 ) {
struct V_115 * V_116 = & V_15 -> V_66 -> V_116 ;
F_85 ( V_26 , L_16 ,
V_116 -> V_117 . V_104 , V_116 -> V_117 . V_105 ,
V_116 -> V_118 . V_104 , V_116 -> V_118 . V_105 ) ;
}
} else {
F_85 ( V_26 , L_17 , V_2 -> V_6 ) ;
}
F_85 ( V_26 , L_18 ) ;
}
void F_86 ( struct V_119 * V_120 , struct V_111 * V_26 )
{
struct V_14 * V_15 ;
int V_121 = 0 ;
T_2 V_6 = 0 ;
F_82 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_15 -> V_110 ;
F_85 ( V_26 , L_19 ) ;
F_83 ( V_2 , V_26 ) ;
V_121 ++ ;
V_6 += V_2 -> V_6 ;
}
F_85 ( V_26 , L_20 , V_121 , V_6 ) ;
}
static inline bool F_87 ( struct V_122 * V_123 )
{
struct V_14 * V_15 = V_123 -> V_15 ;
if ( ( V_123 -> V_124 & V_125 ) &&
( V_15 -> V_126 -> V_127 < V_123 -> V_128 ) )
return true ;
if ( ( V_123 -> V_124 & V_129 ) &&
( V_15 -> V_126 -> V_130 < V_123 -> V_131 ) )
return true ;
return false ;
}
static void F_88 ( void )
{
struct V_122 * V_123 , * V_19 ;
F_89 (waiter, n, &waiters, list) {
if ( ! F_87 ( V_123 ) ) {
F_90 ( & V_123 -> V_120 ) ;
F_91 ( L_21 , V_123 ) ;
V_123 -> V_132 ( V_123 -> V_133 ) ;
F_25 ( V_123 ) ;
}
}
}
static inline int F_92 ( struct V_1 * V_2 ,
enum V_134 V_124 , bool V_135 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_93 ( & V_136 ) ;
if ( ! V_15 -> V_126 ) {
V_15 -> V_126 = F_20 ( sizeof( * V_15 -> V_126 ) , V_137 ) ;
if ( ! V_15 -> V_126 ) {
V_5 = - V_41 ;
goto V_138;
}
}
if ( V_135 ) {
if ( V_124 & V_125 )
V_15 -> V_126 -> V_139 ++ ;
if ( V_124 & V_129 )
V_15 -> V_126 -> V_140 ++ ;
} else {
if ( V_124 & V_125 )
V_15 -> V_126 -> V_130 ++ ;
if ( V_124 & V_129 )
V_15 -> V_126 -> V_127 ++ ;
F_88 () ;
}
V_138:
F_94 ( & V_136 ) ;
return V_5 ;
}
void F_95 ( void )
{
F_93 ( & V_136 ) ;
F_88 () ;
F_94 ( & V_136 ) ;
}
int F_96 ( struct V_1 * V_2 , enum V_134 V_124 )
{
return F_92 ( V_2 , V_124 , true ) ;
}
int F_97 ( struct V_1 * V_2 , enum V_134 V_124 )
{
return F_92 ( V_2 , V_124 , false ) ;
}
static void F_98 ( void * V_133 )
{
struct V_141 * * V_142 = V_133 ;
* V_142 = NULL ;
F_99 ( & V_143 ) ;
}
int F_100 ( struct V_1 * V_2 , enum V_134 V_124 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = 0 ;
if ( V_15 -> V_126 ) {
struct V_141 * V_142 = V_144 ;
struct V_122 * V_123 =
F_20 ( sizeof( * V_123 ) , V_40 ) ;
if ( ! V_123 )
return - V_41 ;
V_123 -> V_15 = V_15 ;
V_123 -> V_124 = V_124 ;
V_123 -> V_131 = V_15 -> V_126 -> V_139 ;
V_123 -> V_128 = V_15 -> V_126 -> V_140 ;
V_123 -> V_132 = F_98 ;
V_123 -> V_133 = & V_142 ;
F_93 ( & V_136 ) ;
if ( F_87 ( V_123 ) ) {
F_91 ( L_22 , V_123 ) ;
F_101 ( & V_123 -> V_120 , & V_145 ) ;
F_94 ( & V_136 ) ;
V_5 = F_102 ( V_143 ,
( V_142 == NULL ) ) ;
F_93 ( & V_136 ) ;
if ( V_142 ) {
F_91 ( L_23 , V_123 ) ;
F_90 ( & V_123 -> V_120 ) ;
V_142 = NULL ;
} else {
V_123 = NULL ;
}
}
F_94 ( & V_136 ) ;
F_25 ( V_123 ) ;
}
return V_5 ;
}
int F_103 ( struct V_1 * V_2 , enum V_134 V_124 ,
void (* F_104)( void * V_133 ) , void * V_133 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
if ( V_15 -> V_126 ) {
struct V_122 * V_123 =
F_20 ( sizeof( * V_123 ) , V_137 ) ;
if ( ! V_123 )
return - V_41 ;
V_123 -> V_15 = V_15 ;
V_123 -> V_124 = V_124 ;
V_123 -> V_131 = V_15 -> V_126 -> V_139 ;
V_123 -> V_128 = V_15 -> V_126 -> V_140 ;
V_123 -> V_132 = F_104 ;
V_123 -> V_133 = V_133 ;
F_93 ( & V_136 ) ;
if ( F_87 ( V_123 ) ) {
F_91 ( L_22 , V_123 ) ;
F_101 ( & V_123 -> V_120 , & V_145 ) ;
F_94 ( & V_136 ) ;
return 0 ;
}
F_94 ( & V_136 ) ;
F_25 ( V_123 ) ;
}
F_104 ( V_133 ) ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 , void * V_146 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_93 ( & V_136 ) ;
if ( ( V_15 -> V_31 & V_147 ) && ! V_146 ) {
V_146 = F_106 ( V_15 -> V_126 , sizeof( * V_15 -> V_126 ) ,
V_137 ) ;
if ( ! V_146 ) {
V_5 = - V_41 ;
goto V_138;
}
V_15 -> V_31 &= ~ V_147 ;
V_15 -> V_126 = V_146 ;
} else if ( V_146 && ! ( V_15 -> V_31 & V_147 ) ) {
if ( V_15 -> V_126 ) {
memcpy ( V_146 , V_15 -> V_126 , sizeof( * V_15 -> V_126 ) ) ;
F_25 ( V_15 -> V_126 ) ;
}
V_15 -> V_31 |= V_147 ;
V_15 -> V_126 = V_146 ;
}
V_138:
F_94 ( & V_136 ) ;
return V_5 ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = V_4 -> V_18 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
F_12 ( V_2 ) ;
F_2 ( ! F_3 ( & V_4 -> V_7 ) ) ;
F_93 ( & V_17 -> V_148 ) ;
F_90 ( & V_15 -> V_149 ) ;
F_94 ( & V_17 -> V_148 ) ;
F_2 ( V_15 -> V_101 > 0 ) ;
if ( ! ( V_15 -> V_31 & V_150 ) ) {
if ( V_15 -> V_35 )
F_23 ( V_2 ) ;
if ( ! F_8 ( V_2 ) ) {
F_108 ( V_4 -> V_4 , V_2 -> V_6 ,
V_15 -> V_60 , V_15 -> V_57 ) ;
} else if ( V_15 -> V_60 ) {
F_109 ( V_15 -> V_60 ) ;
}
}
if ( ! ( V_15 -> V_31 & V_147 ) )
F_25 ( V_15 -> V_126 ) ;
F_110 ( V_2 ) ;
F_25 ( V_15 ) ;
}
struct V_1 * F_111 ( struct V_3 * V_4 ,
union V_84 V_85 , T_5 V_31 )
{
struct V_16 * V_17 = V_4 -> V_18 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_151 * V_152 ;
T_2 V_6 ;
int V_5 ;
if ( V_31 & V_32 ) {
if ( ! V_17 -> V_20 ) {
F_6 ( V_4 -> V_4 , L_24 ) ;
return NULL ;
}
V_31 &= ~ V_89 ;
V_31 &= ~ ( V_94 | V_38 | V_39 ) ;
V_31 |= F_112 () ;
F_113 ( F_13 ( V_31 ) ,
& V_85 . V_153 . V_27 , & V_85 . V_153 . V_21 ) ;
V_6 = F_114 ( F_13 ( V_31 ) ,
V_85 . V_153 . V_27 , V_85 . V_153 . V_21 ) ;
} else {
V_6 = F_56 ( V_85 . V_88 ) ;
}
V_15 = F_20 ( sizeof( * V_15 ) , V_40 ) ;
if ( ! V_15 )
return NULL ;
V_2 = & V_15 -> V_110 ;
if ( ( V_31 & V_89 ) && ! V_17 -> V_100 ) {
V_15 -> V_60 = F_115 ( V_4 -> V_4 , V_6 ,
& V_15 -> V_57 , V_40 ) ;
if ( ! V_15 -> V_60 ) {
F_25 ( V_15 ) ;
return NULL ;
}
V_31 |= V_56 ;
}
F_93 ( & V_17 -> V_148 ) ;
F_116 ( & V_15 -> V_149 , & V_17 -> V_154 ) ;
F_94 ( & V_17 -> V_148 ) ;
V_15 -> V_31 = V_31 ;
if ( V_31 & V_32 ) {
V_15 -> V_27 = V_85 . V_153 . V_27 ;
V_15 -> V_21 = V_85 . V_153 . V_21 ;
}
if ( V_31 & ( V_56 | V_150 ) ) {
F_117 ( V_4 , V_2 , V_6 ) ;
} else {
V_5 = F_118 ( V_4 , V_2 , V_6 ) ;
if ( V_5 )
goto V_69;
V_152 = F_119 ( V_2 -> V_9 ) -> V_30 ;
F_120 ( V_152 , V_155 | V_156 ) ;
}
return V_2 ;
V_69:
F_107 ( V_2 ) ;
return NULL ;
}
int F_57 ( struct V_3 * V_4 , struct V_82 * V_75 ,
union V_84 V_85 , T_5 V_31 , T_5 * V_90 )
{
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_111 ( V_4 , V_85 , V_31 ) ;
if ( ! V_2 )
return - V_41 ;
V_5 = F_121 ( V_75 , V_2 , V_90 ) ;
if ( V_5 ) {
F_107 ( V_2 ) ;
return V_5 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
void F_122 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_18 ;
struct V_157 * V_20 ;
const enum V_10 V_158 [] = {
V_159 , V_160 , V_161
} ;
int V_28 , V_162 ;
if ( ! F_123 () ) {
F_124 ( V_4 -> V_4 , L_25 ) ;
return;
}
V_20 = F_125 ( 3 , sizeof( * V_20 ) , V_40 ) ;
if ( ! V_20 )
return;
for ( V_28 = 0 ; V_28 < F_43 ( V_158 ) ; V_28 ++ ) {
T_6 V_46 = 1 , V_45 = V_22 >> V_28 ;
F_113 ( V_158 [ V_28 ] , & V_45 , & V_46 ) ;
V_20 [ V_28 ] . V_21 = V_46 ;
V_20 [ V_28 ] . V_63 = F_126 ( V_46 ) ;
V_20 [ V_28 ] . V_67 = F_74 ( V_158 [ V_28 ] , 0 ) >> V_25 ;
V_20 [ V_28 ] . V_64 = F_126 ( ( V_22 / V_46 ) >> V_28 ) ;
for ( V_162 = 0 ; V_162 < V_33 ; V_162 ++ ) {
struct V_12 * V_13 ;
struct V_102 * V_66 ;
V_13 = & V_20 [ V_28 ] . V_13 [ V_162 ] ;
V_66 = F_65 ( V_158 [ V_28 ] , V_45 , V_46 , V_22 ) ;
if ( F_16 ( V_66 ) ) {
F_6 ( V_4 -> V_4 ,
L_26 ,
V_28 , V_162 , F_17 ( V_66 ) ) ;
return;
}
V_13 -> V_57 = F_68 ( V_66 ) ;
V_13 -> V_66 = V_66 ;
F_47 ( L_27 , V_28 , V_162 , V_45 , V_46 ,
& V_13 -> V_57 ,
V_20 [ V_28 ] . V_67 << V_25 ) ;
}
}
V_17 -> V_20 = V_20 ;
V_17 -> V_100 = true ;
}
void F_127 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_18 ;
F_25 ( V_17 -> V_20 ) ;
}
