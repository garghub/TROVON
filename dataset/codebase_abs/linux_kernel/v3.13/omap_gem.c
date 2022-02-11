static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , struct V_5 * V_6 )
{
if ( V_2 -> V_7 -> V_8 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_11 = V_12 [ V_4 ] . V_13 ;
T_1 V_14 = V_15 * V_11 ;
T_2 V_16 = F_3 ( V_2 ) +
( V_6 -> V_17 << V_18 ) ;
const int V_19 = 1 + ( ( V_10 -> V_20 << V_4 ) / V_15 ) ;
if ( V_19 > 1 ) {
int V_21 ;
for ( V_21 = V_11 ; V_21 > 0 ; V_21 -- ) {
F_4 ( V_2 -> V_7 -> V_8 ,
V_16 , V_15 , 1 ) ;
V_16 += V_15 * V_19 ;
}
} else {
F_4 ( V_2 -> V_7 -> V_8 , V_16 , V_14 , 1 ) ;
}
}
V_6 -> V_2 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & V_23 ) {
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
int V_21 ;
if ( ! V_12 )
return;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
struct V_5 * V_6 = & V_12 [ V_4 ] . V_6 [ V_21 ] ;
if ( V_6 -> V_2 == V_2 )
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_25 != NULL ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_7 ( V_2 ) &&
( ( V_10 -> V_22 & V_26 ) == V_27 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_29 * * V_30 ;
int V_31 = V_2 -> V_14 >> V_18 ;
int V_21 , V_32 ;
T_3 * V_33 ;
F_10 ( V_10 -> V_30 ) ;
V_30 = F_11 ( V_2 , V_34 ) ;
if ( F_12 ( V_30 ) ) {
F_13 ( V_2 -> V_7 -> V_7 , L_1 , F_14 ( V_30 ) ) ;
return F_14 ( V_30 ) ;
}
if ( V_10 -> V_22 & ( V_35 | V_36 ) ) {
V_33 = F_15 ( V_31 * sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 ) {
V_32 = - V_37 ;
goto V_38;
}
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
V_33 [ V_21 ] = F_16 ( V_7 -> V_7 , V_30 [ V_21 ] ,
0 , V_15 , V_39 ) ;
}
} else {
V_33 = F_17 ( V_31 * sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 ) {
V_32 = - V_37 ;
goto V_38;
}
}
V_10 -> V_33 = V_33 ;
V_10 -> V_30 = V_30 ;
return 0 ;
V_38:
F_18 ( V_2 , V_30 , true , false ) ;
return V_32 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & ( V_35 | V_36 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
F_20 ( V_2 -> V_7 -> V_7 , V_10 -> V_33 [ V_21 ] ,
V_15 , V_39 ) ;
}
}
F_21 ( V_10 -> V_33 ) ;
V_10 -> V_33 = NULL ;
F_18 ( V_2 , V_10 -> V_30 , true , false ) ;
V_10 -> V_30 = NULL ;
}
T_4 F_22 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_22 ;
}
static T_5 F_3 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
int V_32 ;
T_1 V_14 ;
F_10 ( ! F_23 ( & V_7 -> V_40 ) ) ;
V_14 = F_24 ( V_2 ) ;
V_32 = F_25 ( V_2 , V_14 ) ;
if ( V_32 ) {
F_13 ( V_7 -> V_7 , L_2 ) ;
return 0 ;
}
return F_26 ( & V_2 -> V_41 ) ;
}
T_5 F_27 ( struct V_1 * V_2 )
{
T_5 V_42 ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
V_42 = F_3 ( V_2 ) ;
F_29 ( & V_2 -> V_7 -> V_40 ) ;
return V_42 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_14 = V_2 -> V_14 ;
if ( V_10 -> V_22 & V_23 ) {
V_14 = F_30 ( F_6 ( V_10 -> V_22 ) ,
V_10 -> V_20 , V_10 -> V_13 ) ;
}
return V_14 ;
}
int F_31 ( struct V_1 * V_2 , T_6 * V_43 , T_6 * V_44 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & V_23 ) {
* V_43 = V_10 -> V_20 ;
* V_44 = V_10 -> V_13 ;
return 0 ;
}
return - V_45 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned long V_50 ;
T_7 V_51 ;
V_51 = ( ( unsigned long ) V_49 -> V_52 -
V_47 -> V_53 ) >> V_18 ;
if ( V_10 -> V_30 ) {
F_33 ( V_2 , V_51 ) ;
V_50 = F_34 ( V_10 -> V_30 [ V_51 ] ) ;
} else {
F_35 ( ! ( V_10 -> V_22 & V_54 ) ) ;
V_50 = ( V_10 -> V_55 >> V_18 ) + V_51 ;
}
F_36 ( L_3 , V_49 -> V_52 ,
V_50 , V_50 << V_18 ) ;
return F_37 ( V_47 , ( unsigned long ) V_49 -> V_52 , V_50 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_29 * V_30 [ 64 ] ;
unsigned long V_50 ;
T_7 V_51 , V_56 ;
void T_8 * V_57 ;
int V_21 , V_32 , V_58 ;
const int V_11 = V_12 [ V_4 ] . V_13 ;
const int V_59 = V_12 [ V_4 ] . V_60 ;
const int V_19 = 1 + ( ( V_10 -> V_20 << V_4 ) / V_15 ) ;
V_51 = ( ( unsigned long ) V_49 -> V_52 -
V_47 -> V_53 ) >> V_18 ;
V_56 = F_39 ( V_51 , V_19 << V_59 ) ;
V_58 = V_10 -> V_20 >> V_12 [ V_4 ] . V_61 ;
V_57 = V_49 -> V_52 - ( ( V_51 - V_56 ) << V_18 ) ;
V_6 = & V_12 [ V_4 ] . V_6 [ V_12 [ V_4 ] . V_62 ] ;
if ( V_6 -> V_2 )
F_1 ( V_6 -> V_2 , V_4 , V_6 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_17 = V_56 ;
V_56 = ( V_56 >> V_59 ) * V_58 ;
if ( V_19 > 1 ) {
int V_16 = V_51 % V_19 ;
V_6 -> V_17 += V_16 ;
V_56 /= V_19 ;
V_58 = F_40 ( V_58 - ( V_16 << V_59 ) , V_11 ) ;
V_56 += V_16 << V_59 ;
V_57 += V_16 << V_18 ;
}
memcpy ( V_30 , & V_10 -> V_30 [ V_56 ] ,
sizeof( struct V_29 * ) * V_58 ) ;
memset ( V_30 + V_58 , 0 ,
sizeof( struct V_29 * ) * ( V_11 - V_58 ) ) ;
V_32 = F_41 ( V_6 -> V_63 , V_30 , F_42 ( V_30 ) , 0 , true ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_4 , V_32 ) ;
return V_32 ;
}
V_50 = V_6 -> V_55 >> V_18 ;
F_36 ( L_3 , V_49 -> V_52 ,
V_50 , V_50 << V_18 ) ;
for ( V_21 = V_11 ; V_21 > 0 ; V_21 -- ) {
F_37 ( V_47 , ( unsigned long ) V_57 , V_50 ) ;
V_50 += V_12 [ V_4 ] . V_64 ;
V_57 += V_15 * V_19 ;
}
V_12 [ V_4 ] . V_62 = ( V_12 [ V_4 ] . V_62 + 1 ) % V_24 ;
return 0 ;
}
int F_43 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_1 * V_2 = V_47 -> V_65 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_29 * * V_30 ;
int V_32 ;
F_28 ( & V_7 -> V_40 ) ;
V_32 = F_44 ( V_2 , & V_30 ) ;
if ( V_32 )
goto V_66;
if ( V_10 -> V_22 & V_23 )
V_32 = F_38 ( V_2 , V_47 , V_49 ) ;
else
V_32 = F_32 ( V_2 , V_47 , V_49 ) ;
V_66:
F_29 ( & V_7 -> V_40 ) ;
switch ( V_32 ) {
case 0 :
case - V_67 :
case - V_68 :
return V_69 ;
case - V_37 :
return V_70 ;
default:
return V_71 ;
}
}
int F_45 ( struct V_72 * V_25 , struct V_46 * V_47 )
{
int V_32 ;
V_32 = F_46 ( V_25 , V_47 ) ;
if ( V_32 ) {
F_47 ( L_5 , V_32 ) ;
return V_32 ;
}
return F_48 ( V_47 -> V_65 , V_47 ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_47 -> V_73 &= ~ V_74 ;
V_47 -> V_73 |= V_75 ;
if ( V_10 -> V_22 & V_35 ) {
V_47 -> V_76 = F_49 ( F_50 ( V_47 -> V_73 ) ) ;
} else if ( V_10 -> V_22 & V_36 ) {
V_47 -> V_76 = F_51 ( F_50 ( V_47 -> V_73 ) ) ;
} else {
if ( F_10 ( ! V_2 -> V_25 ) )
return - V_45 ;
F_52 ( V_47 -> V_77 ) ;
V_47 -> V_78 = 0 ;
V_47 -> V_77 = F_53 ( V_2 -> V_25 ) ;
V_47 -> V_76 = F_50 ( V_47 -> V_73 ) ;
}
return 0 ;
}
int F_54 ( struct V_79 * V_72 , struct V_28 * V_7 ,
struct V_80 * args )
{
union V_81 V_82 ;
args -> V_83 = F_55 ( args -> V_83 , args -> V_20 , args -> V_84 ) ;
args -> V_14 = F_56 ( args -> V_83 * args -> V_13 ) ;
V_82 = (union V_81 ) {
. V_85 = args -> V_14 ,
} ;
return F_57 ( V_7 , V_72 , V_82 ,
V_86 | V_35 , & args -> V_87 ) ;
}
int F_58 ( struct V_79 * V_72 , struct V_28 * V_7 ,
T_4 V_87 , T_5 * V_42 )
{
struct V_1 * V_2 ;
int V_32 = 0 ;
V_2 = F_59 ( V_7 , V_72 , V_87 ) ;
if ( V_2 == NULL ) {
V_32 = - V_88 ;
goto V_66;
}
* V_42 = F_27 ( V_2 ) ;
F_60 ( V_2 ) ;
V_66:
return V_32 ;
}
int F_61 ( struct V_1 * V_2 , T_4 V_89 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
int V_32 = 0 ;
if ( V_89 > V_31 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_6 , V_89 ) ;
return - V_45 ;
}
V_10 -> V_89 = V_89 ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
if ( V_10 -> V_63 ) {
struct V_29 * * V_30 ;
V_32 = F_44 ( V_2 , & V_30 ) ;
if ( V_32 )
goto V_66;
V_32 = F_41 ( V_10 -> V_63 , V_30 , V_31 , V_89 , true ) ;
if ( V_32 )
F_13 ( V_2 -> V_7 -> V_7 , L_7 , V_32 ) ;
}
V_66:
F_29 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
void F_33 ( struct V_1 * V_2 , int V_51 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) && V_10 -> V_33 [ V_51 ] ) {
F_20 ( V_7 -> V_7 , V_10 -> V_33 [ V_51 ] ,
V_15 , V_39 ) ;
V_10 -> V_33 [ V_51 ] = 0 ;
}
}
void F_62 ( struct V_1 * V_2 ,
enum V_90 V_91 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
struct V_29 * * V_30 = V_10 -> V_30 ;
bool V_92 = false ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
if ( ! V_10 -> V_33 [ V_21 ] ) {
V_10 -> V_33 [ V_21 ] = F_16 ( V_7 -> V_7 , V_30 [ V_21 ] , 0 ,
V_15 , V_39 ) ;
V_92 = true ;
}
}
if ( V_92 ) {
F_4 ( V_2 -> V_25 -> V_93 , 0 ,
F_24 ( V_2 ) , 1 ) ;
}
}
}
int F_63 ( struct V_1 * V_2 ,
T_3 * V_55 , bool V_94 )
{
struct V_95 * V_96 = V_2 -> V_7 -> V_97 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
if ( V_94 && F_7 ( V_2 ) && V_96 -> V_98 ) {
if ( V_10 -> V_99 == 0 ) {
struct V_29 * * V_30 ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_100 * V_63 ;
F_35 ( V_10 -> V_63 ) ;
V_32 = F_44 ( V_2 , & V_30 ) ;
if ( V_32 )
goto V_66;
if ( V_10 -> V_22 & V_23 ) {
V_63 = F_64 ( V_4 ,
V_10 -> V_20 ,
V_10 -> V_13 , 0 ) ;
} else {
V_63 = F_65 ( V_2 -> V_14 ) ;
}
if ( F_12 ( V_63 ) ) {
V_32 = F_14 ( V_63 ) ;
F_13 ( V_2 -> V_7 -> V_7 ,
L_8 , V_32 , V_4 ) ;
goto V_66;
}
V_32 = F_41 ( V_63 , V_30 , V_31 ,
V_10 -> V_89 , true ) ;
if ( V_32 ) {
F_66 ( V_63 ) ;
F_13 ( V_2 -> V_7 -> V_7 ,
L_9 , V_32 ) ;
goto V_66;
}
V_10 -> V_55 = F_67 ( V_63 ) ;
V_10 -> V_63 = V_63 ;
F_47 ( L_10 , V_10 -> V_55 ) ;
}
V_10 -> V_99 ++ ;
* V_55 = V_10 -> V_55 ;
} else if ( V_10 -> V_22 & V_54 ) {
* V_55 = V_10 -> V_55 ;
} else {
V_32 = - V_45 ;
goto V_66;
}
V_66:
F_29 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
if ( V_10 -> V_99 > 0 ) {
V_10 -> V_99 -- ;
if ( V_10 -> V_99 == 0 ) {
V_32 = F_69 ( V_10 -> V_63 ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 ,
L_11 , V_32 ) ;
goto V_66;
}
V_32 = F_66 ( V_10 -> V_63 ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 ,
L_12 , V_32 ) ;
}
V_10 -> V_63 = NULL ;
}
}
V_66:
F_29 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_70 ( struct V_1 * V_2 , T_4 V_101 ,
int V_102 , int V_103 , T_3 * V_55 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = - V_45 ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
if ( ( V_10 -> V_99 > 0 ) && V_10 -> V_63 &&
( V_10 -> V_22 & V_23 ) ) {
* V_55 = F_71 ( V_10 -> V_63 , V_101 , V_102 , V_103 ) ;
V_32 = 0 ;
}
F_29 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_72 ( struct V_1 * V_2 , T_4 V_101 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = - V_45 ;
if ( V_10 -> V_22 & V_23 )
V_32 = F_73 ( F_6 ( V_10 -> V_22 ) , V_101 ) ;
return V_32 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_29 * * * V_30 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
if ( F_7 ( V_2 ) && ! V_10 -> V_30 ) {
V_32 = F_9 ( V_2 ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_13 ) ;
return V_32 ;
}
}
* V_30 = V_10 -> V_30 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , struct V_29 * * * V_30 ,
bool V_94 )
{
int V_32 ;
if ( ! V_94 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_30 )
return - V_37 ;
* V_30 = V_10 -> V_30 ;
return 0 ;
}
F_28 ( & V_2 -> V_7 -> V_40 ) ;
V_32 = F_44 ( V_2 , V_30 ) ;
F_29 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_75 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_76 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_10 ( ! F_23 ( & V_2 -> V_7 -> V_40 ) ) ;
if ( ! V_10 -> V_57 ) {
struct V_29 * * V_30 ;
int V_32 = F_44 ( V_2 , & V_30 ) ;
if ( V_32 )
return F_77 ( V_32 ) ;
V_10 -> V_57 = F_78 ( V_30 , V_2 -> V_14 >> V_18 ,
V_104 , F_49 ( V_105 ) ) ;
}
return V_10 -> V_57 ;
}
int F_79 ( struct V_106 * V_7 )
{
struct V_28 * V_107 = F_80 ( V_7 ) ;
struct V_95 * V_96 = V_107 -> V_97 ;
struct V_9 * V_10 ;
int V_32 = 0 ;
F_81 (omap_obj, &priv->obj_list, mm_list) {
if ( V_10 -> V_63 ) {
struct V_1 * V_2 = & V_10 -> V_108 ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
F_10 ( ! V_10 -> V_30 ) ;
V_32 = F_41 ( V_10 -> V_63 ,
V_10 -> V_30 , V_31 ,
V_10 -> V_89 , true ) ;
if ( V_32 ) {
F_13 ( V_7 , L_7 , V_32 ) ;
return V_32 ;
}
}
}
return 0 ;
}
void F_82 ( struct V_1 * V_2 , struct V_109 * V_19 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_5 V_16 ;
F_10 ( ! F_23 ( & V_7 -> V_40 ) ) ;
V_16 = F_83 ( & V_2 -> V_41 ) ;
F_84 ( V_19 , L_14 ,
V_10 -> V_22 , V_2 -> V_110 , V_2 -> V_111 . V_111 . V_112 ,
V_16 , V_10 -> V_55 , V_10 -> V_99 ,
V_10 -> V_57 , V_10 -> V_89 ) ;
if ( V_10 -> V_22 & V_23 ) {
F_84 ( V_19 , L_15 , V_10 -> V_20 , V_10 -> V_13 ) ;
if ( V_10 -> V_63 ) {
struct V_113 * V_114 = & V_10 -> V_63 -> V_114 ;
F_84 ( V_19 , L_16 ,
V_114 -> V_115 . V_102 , V_114 -> V_115 . V_103 ,
V_114 -> V_116 . V_102 , V_114 -> V_116 . V_103 ) ;
}
} else {
F_84 ( V_19 , L_17 , V_2 -> V_14 ) ;
}
F_84 ( V_19 , L_18 ) ;
}
void F_85 ( struct V_117 * V_118 , struct V_109 * V_19 )
{
struct V_9 * V_10 ;
int V_119 = 0 ;
T_1 V_14 = 0 ;
F_81 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_108 ;
F_84 ( V_19 , L_19 ) ;
F_82 ( V_2 , V_19 ) ;
V_119 ++ ;
V_14 += V_2 -> V_14 ;
}
F_84 ( V_19 , L_20 , V_119 , V_14 ) ;
}
static inline bool F_86 ( struct V_120 * V_121 )
{
struct V_9 * V_10 = V_121 -> V_10 ;
if ( ( V_121 -> V_122 & V_123 ) &&
( V_10 -> V_124 -> V_125 < V_121 -> V_126 ) )
return true ;
if ( ( V_121 -> V_122 & V_127 ) &&
( V_10 -> V_124 -> V_128 < V_121 -> V_129 ) )
return true ;
return false ;
}
static void F_87 ( void )
{
struct V_120 * V_121 , * V_11 ;
F_88 (waiter, n, &waiters, list) {
if ( ! F_86 ( V_121 ) ) {
F_89 ( & V_121 -> V_118 ) ;
F_90 ( L_21 , V_121 ) ;
V_121 -> V_130 ( V_121 -> V_131 ) ;
F_21 ( V_121 ) ;
}
}
}
static inline int F_91 ( struct V_1 * V_2 ,
enum V_132 V_122 , bool V_133 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_92 ( & V_134 ) ;
if ( ! V_10 -> V_124 ) {
V_10 -> V_124 = F_17 ( sizeof( * V_10 -> V_124 ) , V_135 ) ;
if ( ! V_10 -> V_124 ) {
V_32 = - V_37 ;
goto V_136;
}
}
if ( V_133 ) {
if ( V_122 & V_123 )
V_10 -> V_124 -> V_137 ++ ;
if ( V_122 & V_127 )
V_10 -> V_124 -> V_138 ++ ;
} else {
if ( V_122 & V_123 )
V_10 -> V_124 -> V_125 ++ ;
if ( V_122 & V_127 )
V_10 -> V_124 -> V_128 ++ ;
F_87 () ;
}
V_136:
F_93 ( & V_134 ) ;
return V_32 ;
}
void F_94 ( void )
{
F_92 ( & V_134 ) ;
F_87 () ;
F_93 ( & V_134 ) ;
}
int F_95 ( struct V_1 * V_2 , enum V_132 V_122 )
{
return F_91 ( V_2 , V_122 , true ) ;
}
int F_96 ( struct V_1 * V_2 , enum V_132 V_122 )
{
return F_91 ( V_2 , V_122 , false ) ;
}
static void F_97 ( void * V_131 )
{
struct V_139 * * V_140 = V_131 ;
* V_140 = NULL ;
F_98 ( & V_141 ) ;
}
int F_99 ( struct V_1 * V_2 , enum V_132 V_122 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
if ( V_10 -> V_124 ) {
struct V_139 * V_140 = V_142 ;
struct V_120 * V_121 =
F_17 ( sizeof( * V_121 ) , V_34 ) ;
if ( ! V_121 )
return - V_37 ;
V_121 -> V_10 = V_10 ;
V_121 -> V_122 = V_122 ;
V_121 -> V_126 = V_10 -> V_124 -> V_137 ;
V_121 -> V_129 = V_10 -> V_124 -> V_138 ;
V_121 -> V_130 = F_97 ;
V_121 -> V_131 = & V_140 ;
F_92 ( & V_134 ) ;
if ( F_86 ( V_121 ) ) {
F_90 ( L_22 , V_121 ) ;
F_100 ( & V_121 -> V_118 , & V_143 ) ;
F_93 ( & V_134 ) ;
V_32 = F_101 ( V_141 ,
( V_140 == NULL ) ) ;
F_92 ( & V_134 ) ;
if ( V_140 ) {
F_90 ( L_23 , V_121 ) ;
F_89 ( & V_121 -> V_118 ) ;
V_140 = NULL ;
} else {
V_121 = NULL ;
}
}
F_93 ( & V_134 ) ;
if ( V_121 )
F_21 ( V_121 ) ;
}
return V_32 ;
}
int F_102 ( struct V_1 * V_2 , enum V_132 V_122 ,
void (* F_103)( void * V_131 ) , void * V_131 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_124 ) {
struct V_120 * V_121 =
F_17 ( sizeof( * V_121 ) , V_135 ) ;
if ( ! V_121 )
return - V_37 ;
V_121 -> V_10 = V_10 ;
V_121 -> V_122 = V_122 ;
V_121 -> V_126 = V_10 -> V_124 -> V_137 ;
V_121 -> V_129 = V_10 -> V_124 -> V_138 ;
V_121 -> V_130 = F_103 ;
V_121 -> V_131 = V_131 ;
F_92 ( & V_134 ) ;
if ( F_86 ( V_121 ) ) {
F_90 ( L_22 , V_121 ) ;
F_100 ( & V_121 -> V_118 , & V_143 ) ;
F_93 ( & V_134 ) ;
return 0 ;
}
F_93 ( & V_134 ) ;
}
F_103 ( V_131 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 , void * V_144 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_92 ( & V_134 ) ;
if ( ( V_10 -> V_22 & V_145 ) && ! V_144 ) {
V_144 = F_105 ( V_10 -> V_124 , sizeof( * V_10 -> V_124 ) ,
V_135 ) ;
if ( ! V_144 ) {
V_32 = - V_37 ;
goto V_136;
}
V_10 -> V_22 &= ~ V_145 ;
V_10 -> V_124 = V_144 ;
} else if ( V_144 && ! ( V_10 -> V_22 & V_145 ) ) {
if ( V_10 -> V_124 ) {
memcpy ( V_144 , V_10 -> V_124 , sizeof( * V_10 -> V_124 ) ) ;
F_21 ( V_10 -> V_124 ) ;
}
V_10 -> V_22 |= V_145 ;
V_10 -> V_124 = V_144 ;
}
V_136:
F_93 ( & V_134 ) ;
return V_32 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_10 ( ! F_23 ( & V_7 -> V_40 ) ) ;
F_89 ( & V_10 -> V_146 ) ;
F_107 ( V_2 ) ;
F_10 ( V_10 -> V_99 > 0 ) ;
if ( ! ( V_10 -> V_22 & V_147 ) ) {
if ( V_10 -> V_30 )
F_19 ( V_2 ) ;
if ( ! F_7 ( V_2 ) ) {
F_108 ( V_7 -> V_7 , V_2 -> V_14 ,
V_10 -> V_57 , V_10 -> V_55 ) ;
} else if ( V_10 -> V_57 ) {
F_109 ( V_10 -> V_57 ) ;
}
}
if ( ! ( V_10 -> V_22 & V_145 ) )
F_21 ( V_10 -> V_124 ) ;
F_110 ( V_2 ) ;
F_21 ( V_2 ) ;
}
int F_57 ( struct V_28 * V_7 , struct V_79 * V_72 ,
union V_81 V_82 , T_4 V_22 , T_4 * V_87 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_111 ( V_7 , V_82 , V_22 ) ;
if ( ! V_2 )
return - V_37 ;
V_32 = F_112 ( V_72 , V_2 , V_87 ) ;
if ( V_32 ) {
F_110 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_32 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_111 ( struct V_28 * V_7 ,
union V_81 V_82 , T_4 V_22 )
{
struct V_95 * V_96 = V_7 -> V_97 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
T_1 V_14 ;
int V_32 ;
if ( V_22 & V_23 ) {
if ( ! V_12 ) {
F_13 ( V_7 -> V_7 , L_24 ) ;
goto V_66;
}
V_22 &= ~ V_86 ;
V_22 &= ~ ( V_27 | V_36 ) ;
V_22 |= V_35 ;
F_113 ( F_6 ( V_22 ) ,
& V_82 . V_148 . V_20 , & V_82 . V_148 . V_13 ) ;
V_14 = F_114 ( F_6 ( V_22 ) ,
V_82 . V_148 . V_20 , V_82 . V_148 . V_13 ) ;
} else {
V_14 = F_56 ( V_82 . V_85 ) ;
}
V_10 = F_17 ( sizeof( * V_10 ) , V_34 ) ;
if ( ! V_10 )
goto V_66;
F_115 ( & V_10 -> V_146 , & V_96 -> V_149 ) ;
V_2 = & V_10 -> V_108 ;
if ( ( V_22 & V_86 ) && ! V_96 -> V_98 ) {
V_10 -> V_57 = F_116 ( V_7 -> V_7 , V_14 ,
& V_10 -> V_55 , V_34 ) ;
if ( V_10 -> V_57 )
V_22 |= V_54 ;
}
V_10 -> V_22 = V_22 ;
if ( V_22 & V_23 ) {
V_10 -> V_20 = V_82 . V_148 . V_20 ;
V_10 -> V_13 = V_82 . V_148 . V_13 ;
}
V_32 = 0 ;
if ( V_22 & ( V_54 | V_147 ) )
F_117 ( V_7 , V_2 , V_14 ) ;
else
V_32 = F_118 ( V_7 , V_2 , V_14 ) ;
if ( V_32 )
goto V_66;
return V_2 ;
V_66:
if ( V_2 )
F_106 ( V_2 ) ;
return NULL ;
}
void F_119 ( struct V_28 * V_7 )
{
struct V_95 * V_96 = V_7 -> V_97 ;
const enum V_3 V_150 [] = {
V_151 , V_152 , V_153
} ;
int V_21 , V_154 ;
if ( ! F_120 () ) {
F_121 ( V_7 -> V_7 , L_25 ) ;
return;
}
V_12 = F_122 ( 3 , sizeof( * V_12 ) , V_34 ) ;
if ( ! V_12 )
return;
for ( V_21 = 0 ; V_21 < F_42 ( V_150 ) ; V_21 ++ ) {
T_6 V_44 = 1 , V_43 = V_15 >> V_21 ;
F_113 ( V_150 [ V_21 ] , & V_43 , & V_44 ) ;
V_12 [ V_21 ] . V_13 = V_44 ;
V_12 [ V_21 ] . V_60 = F_123 ( V_44 ) ;
V_12 [ V_21 ] . V_64 = F_73 ( V_150 [ V_21 ] , 0 ) >> V_18 ;
V_12 [ V_21 ] . V_61 = F_123 ( ( V_15 / V_44 ) >> V_21 ) ;
for ( V_154 = 0 ; V_154 < V_24 ; V_154 ++ ) {
struct V_5 * V_6 = & V_12 [ V_21 ] . V_6 [ V_154 ] ;
struct V_100 * V_63 =
F_64 ( V_150 [ V_21 ] , V_43 , V_44 ,
V_15 ) ;
if ( F_12 ( V_63 ) ) {
F_13 ( V_7 -> V_7 ,
L_26 ,
V_21 , V_154 , F_14 ( V_63 ) ) ;
return;
}
V_6 -> V_55 = F_67 ( V_63 ) ;
V_6 -> V_63 = V_63 ;
F_47 ( L_27 , V_21 , V_154 , V_43 , V_44 ,
V_6 -> V_55 ,
V_12 [ V_21 ] . V_64 << V_18 ) ;
}
}
V_96 -> V_98 = true ;
}
void F_124 ( struct V_28 * V_7 )
{
F_21 ( V_12 ) ;
}
