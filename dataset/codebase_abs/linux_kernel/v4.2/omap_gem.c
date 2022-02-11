static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = V_10 [ V_4 ] . V_11 ;
T_1 V_12 = V_13 * V_9 ;
T_2 V_14 = F_3 ( V_2 ) +
( V_6 -> V_15 << V_16 ) ;
const int V_17 = 1 + ( ( V_8 -> V_18 << V_4 ) / V_13 ) ;
if ( V_17 > 1 ) {
int V_19 ;
for ( V_19 = V_9 ; V_19 > 0 ; V_19 -- ) {
F_4 ( V_2 -> V_20 -> V_21 -> V_22 ,
V_14 , V_13 , 1 ) ;
V_14 += V_13 * V_17 ;
}
} else {
F_4 ( V_2 -> V_20 -> V_21 -> V_22 ,
V_14 , V_12 , 1 ) ;
}
V_6 -> V_2 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_23 & V_24 ) {
enum V_3 V_4 = F_6 ( V_8 -> V_23 ) ;
int V_19 ;
if ( ! V_10 )
return;
for ( V_19 = 0 ; V_19 < V_25 ; V_19 ++ ) {
struct V_5 * V_6 = & V_10 [ V_4 ] . V_6 [ V_19 ] ;
if ( V_6 -> V_2 == V_2 )
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_26 != NULL ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_7 ( V_2 ) &&
( ( V_8 -> V_23 & V_27 ) == V_28 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_30 * * V_31 ;
int V_32 = V_2 -> V_12 >> V_16 ;
int V_19 , V_33 ;
T_3 * V_34 ;
F_10 ( V_8 -> V_31 ) ;
V_31 = F_11 ( V_2 ) ;
if ( F_12 ( V_31 ) ) {
F_13 ( V_2 -> V_20 -> V_20 , L_1 , F_14 ( V_31 ) ) ;
return F_14 ( V_31 ) ;
}
if ( V_8 -> V_23 & ( V_35 | V_36 ) ) {
V_34 = F_15 ( V_32 * sizeof( * V_34 ) , V_37 ) ;
if ( ! V_34 ) {
V_33 = - V_38 ;
goto V_39;
}
for ( V_19 = 0 ; V_19 < V_32 ; V_19 ++ ) {
V_34 [ V_19 ] = F_16 ( V_20 -> V_20 , V_31 [ V_19 ] ,
0 , V_13 , V_40 ) ;
}
} else {
V_34 = F_17 ( V_32 * sizeof( * V_34 ) , V_37 ) ;
if ( ! V_34 ) {
V_33 = - V_38 ;
goto V_39;
}
}
V_8 -> V_34 = V_34 ;
V_8 -> V_31 = V_31 ;
return 0 ;
V_39:
F_18 ( V_2 , V_31 , true , false ) ;
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_23 & ( V_35 | V_36 ) ) {
int V_19 , V_32 = V_2 -> V_12 >> V_16 ;
for ( V_19 = 0 ; V_19 < V_32 ; V_19 ++ ) {
F_20 ( V_2 -> V_20 -> V_20 , V_8 -> V_34 [ V_19 ] ,
V_13 , V_40 ) ;
}
}
F_21 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
F_18 ( V_2 , V_8 -> V_31 , true , false ) ;
V_8 -> V_31 = NULL ;
}
T_4 F_22 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_23 ;
}
static T_5 F_3 ( struct V_1 * V_2 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
int V_33 ;
T_1 V_12 ;
F_10 ( ! F_23 ( & V_20 -> V_41 ) ) ;
V_12 = F_24 ( V_2 ) ;
V_33 = F_25 ( V_2 , V_12 ) ;
if ( V_33 ) {
F_13 ( V_20 -> V_20 , L_2 ) ;
return 0 ;
}
return F_26 ( & V_2 -> V_42 ) ;
}
T_5 F_27 ( struct V_1 * V_2 )
{
T_5 V_43 ;
F_28 ( & V_2 -> V_20 -> V_41 ) ;
V_43 = F_3 ( V_2 ) ;
F_29 ( & V_2 -> V_20 -> V_41 ) ;
return V_43 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 = V_2 -> V_12 ;
if ( V_8 -> V_23 & V_24 ) {
V_12 = F_30 ( F_6 ( V_8 -> V_23 ) ,
V_8 -> V_18 , V_8 -> V_11 ) ;
}
return V_12 ;
}
int F_31 ( struct V_1 * V_2 , T_6 * V_44 , T_6 * V_45 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_23 & V_24 ) {
* V_44 = V_8 -> V_18 ;
* V_45 = V_8 -> V_11 ;
return 0 ;
}
return - V_46 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_51 ;
T_7 V_52 ;
V_52 = ( ( unsigned long ) V_50 -> V_53 -
V_48 -> V_54 ) >> V_16 ;
if ( V_8 -> V_31 ) {
F_33 ( V_2 , V_52 ) ;
V_51 = F_34 ( V_8 -> V_31 [ V_52 ] ) ;
} else {
F_35 ( ! ( V_8 -> V_23 & V_55 ) ) ;
V_51 = ( V_8 -> V_56 >> V_16 ) + V_52 ;
}
F_36 ( L_3 , V_50 -> V_53 ,
V_51 , V_51 << V_16 ) ;
return F_37 ( V_48 , ( unsigned long ) V_50 -> V_53 , V_51 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_3 V_4 = F_6 ( V_8 -> V_23 ) ;
struct V_30 * V_31 [ 64 ] ;
unsigned long V_51 ;
T_7 V_52 , V_57 ;
void T_8 * V_58 ;
int V_19 , V_33 , V_59 ;
const int V_9 = V_10 [ V_4 ] . V_11 ;
const int V_60 = V_10 [ V_4 ] . V_61 ;
const int V_17 = 1 + ( ( V_8 -> V_18 << V_4 ) / V_13 ) ;
V_52 = ( ( unsigned long ) V_50 -> V_53 -
V_48 -> V_54 ) >> V_16 ;
V_57 = F_39 ( V_52 , V_17 << V_60 ) ;
V_59 = V_8 -> V_18 >> V_10 [ V_4 ] . V_62 ;
V_58 = V_50 -> V_53 - ( ( V_52 - V_57 ) << V_16 ) ;
V_6 = & V_10 [ V_4 ] . V_6 [ V_10 [ V_4 ] . V_63 ] ;
if ( V_6 -> V_2 )
F_1 ( V_6 -> V_2 , V_4 , V_6 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_15 = V_57 ;
V_57 = ( V_57 >> V_60 ) * V_59 ;
if ( V_17 > 1 ) {
int V_14 = V_52 % V_17 ;
V_6 -> V_15 += V_14 ;
V_57 /= V_17 ;
V_59 = F_40 ( V_59 - ( V_14 << V_60 ) , V_9 ) ;
V_57 += V_14 << V_60 ;
V_58 += V_14 << V_16 ;
}
memcpy ( V_31 , & V_8 -> V_31 [ V_57 ] ,
sizeof( struct V_30 * ) * V_59 ) ;
memset ( V_31 + V_59 , 0 ,
sizeof( struct V_30 * ) * ( V_9 - V_59 ) ) ;
V_33 = F_41 ( V_6 -> V_64 , V_31 , F_42 ( V_31 ) , 0 , true ) ;
if ( V_33 ) {
F_13 ( V_2 -> V_20 -> V_20 , L_4 , V_33 ) ;
return V_33 ;
}
V_51 = V_6 -> V_56 >> V_16 ;
F_36 ( L_3 , V_50 -> V_53 ,
V_51 , V_51 << V_16 ) ;
for ( V_19 = V_9 ; V_19 > 0 ; V_19 -- ) {
F_37 ( V_48 , ( unsigned long ) V_58 , V_51 ) ;
V_51 += V_10 [ V_4 ] . V_65 ;
V_58 += V_13 * V_17 ;
}
V_10 [ V_4 ] . V_63 = ( V_10 [ V_4 ] . V_63 + 1 ) % V_25 ;
return 0 ;
}
int F_43 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_66 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_29 * V_20 = V_2 -> V_20 ;
struct V_30 * * V_31 ;
int V_33 ;
F_28 ( & V_20 -> V_41 ) ;
V_33 = F_44 ( V_2 , & V_31 ) ;
if ( V_33 )
goto V_67;
if ( V_8 -> V_23 & V_24 )
V_33 = F_38 ( V_2 , V_48 , V_50 ) ;
else
V_33 = F_32 ( V_2 , V_48 , V_50 ) ;
V_67:
F_29 ( & V_20 -> V_41 ) ;
switch ( V_33 ) {
case 0 :
case - V_68 :
case - V_69 :
return V_70 ;
case - V_38 :
return V_71 ;
default:
return V_72 ;
}
}
int F_45 ( struct V_73 * V_26 , struct V_47 * V_48 )
{
int V_33 ;
V_33 = F_46 ( V_26 , V_48 ) ;
if ( V_33 ) {
F_47 ( L_5 , V_33 ) ;
return V_33 ;
}
return F_48 ( V_48 -> V_66 , V_48 ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_48 -> V_74 &= ~ V_75 ;
V_48 -> V_74 |= V_76 ;
if ( V_8 -> V_23 & V_35 ) {
V_48 -> V_77 = F_49 ( F_50 ( V_48 -> V_74 ) ) ;
} else if ( V_8 -> V_23 & V_36 ) {
V_48 -> V_77 = F_51 ( F_50 ( V_48 -> V_74 ) ) ;
} else {
if ( F_10 ( ! V_2 -> V_26 ) )
return - V_46 ;
F_52 ( V_48 -> V_78 ) ;
V_48 -> V_79 = 0 ;
V_48 -> V_78 = F_53 ( V_2 -> V_26 ) ;
V_48 -> V_77 = F_50 ( V_48 -> V_74 ) ;
}
return 0 ;
}
int F_54 ( struct V_80 * V_73 , struct V_29 * V_20 ,
struct V_81 * args )
{
union V_82 V_83 ;
args -> V_84 = F_55 ( 0 , args -> V_18 , args -> V_85 ) ;
args -> V_12 = F_56 ( args -> V_84 * args -> V_11 ) ;
V_83 = (union V_82 ) {
. V_86 = args -> V_12 ,
} ;
return F_57 ( V_20 , V_73 , V_83 ,
V_87 | V_35 , & args -> V_88 ) ;
}
int F_58 ( struct V_80 * V_73 , struct V_29 * V_20 ,
T_4 V_88 , T_5 * V_43 )
{
struct V_1 * V_2 ;
int V_33 = 0 ;
V_2 = F_59 ( V_20 , V_73 , V_88 ) ;
if ( V_2 == NULL ) {
V_33 = - V_89 ;
goto V_67;
}
* V_43 = F_27 ( V_2 ) ;
F_60 ( V_2 ) ;
V_67:
return V_33 ;
}
int F_61 ( struct V_1 * V_2 , T_4 V_90 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_4 V_32 = V_2 -> V_12 >> V_16 ;
int V_33 = 0 ;
if ( V_90 > V_32 ) {
F_13 ( V_2 -> V_20 -> V_20 , L_6 , V_90 ) ;
return - V_46 ;
}
V_8 -> V_90 = V_90 ;
F_28 ( & V_2 -> V_20 -> V_41 ) ;
if ( V_8 -> V_64 ) {
struct V_30 * * V_31 ;
V_33 = F_44 ( V_2 , & V_31 ) ;
if ( V_33 )
goto V_67;
V_33 = F_41 ( V_8 -> V_64 , V_31 , V_32 , V_90 , true ) ;
if ( V_33 )
F_13 ( V_2 -> V_20 -> V_20 , L_7 , V_33 ) ;
}
V_67:
F_29 ( & V_2 -> V_20 -> V_41 ) ;
return V_33 ;
}
void F_33 ( struct V_1 * V_2 , int V_52 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) && V_8 -> V_34 [ V_52 ] ) {
F_20 ( V_20 -> V_20 , V_8 -> V_34 [ V_52 ] ,
V_13 , V_40 ) ;
V_8 -> V_34 [ V_52 ] = 0 ;
}
}
void F_62 ( struct V_1 * V_2 ,
enum V_91 V_92 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_19 , V_32 = V_2 -> V_12 >> V_16 ;
struct V_30 * * V_31 = V_8 -> V_31 ;
bool V_93 = false ;
for ( V_19 = 0 ; V_19 < V_32 ; V_19 ++ ) {
if ( ! V_8 -> V_34 [ V_19 ] ) {
V_8 -> V_34 [ V_19 ] = F_16 ( V_20 -> V_20 , V_31 [ V_19 ] , 0 ,
V_13 , V_40 ) ;
V_93 = true ;
}
}
if ( V_93 ) {
F_4 ( V_2 -> V_26 -> V_94 , 0 ,
F_24 ( V_2 ) , 1 ) ;
}
}
}
int F_63 ( struct V_1 * V_2 ,
T_3 * V_56 , bool V_95 )
{
struct V_96 * V_97 = V_2 -> V_20 -> V_98 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = 0 ;
F_28 ( & V_2 -> V_20 -> V_41 ) ;
if ( V_95 && F_7 ( V_2 ) && V_97 -> V_99 ) {
if ( V_8 -> V_100 == 0 ) {
struct V_30 * * V_31 ;
T_4 V_32 = V_2 -> V_12 >> V_16 ;
enum V_3 V_4 = F_6 ( V_8 -> V_23 ) ;
struct V_101 * V_64 ;
F_35 ( V_8 -> V_64 ) ;
V_33 = F_44 ( V_2 , & V_31 ) ;
if ( V_33 )
goto V_67;
if ( V_8 -> V_23 & V_24 ) {
V_64 = F_64 ( V_4 ,
V_8 -> V_18 ,
V_8 -> V_11 , 0 ) ;
} else {
V_64 = F_65 ( V_2 -> V_12 ) ;
}
if ( F_12 ( V_64 ) ) {
V_33 = F_14 ( V_64 ) ;
F_13 ( V_2 -> V_20 -> V_20 ,
L_8 , V_33 , V_4 ) ;
goto V_67;
}
V_33 = F_41 ( V_64 , V_31 , V_32 ,
V_8 -> V_90 , true ) ;
if ( V_33 ) {
F_66 ( V_64 ) ;
F_13 ( V_2 -> V_20 -> V_20 ,
L_9 , V_33 ) ;
goto V_67;
}
V_8 -> V_56 = F_67 ( V_64 ) ;
V_8 -> V_64 = V_64 ;
F_47 ( L_10 , & V_8 -> V_56 ) ;
}
V_8 -> V_100 ++ ;
* V_56 = V_8 -> V_56 ;
} else if ( V_8 -> V_23 & V_55 ) {
* V_56 = V_8 -> V_56 ;
} else {
V_33 = - V_46 ;
goto V_67;
}
V_67:
F_29 ( & V_2 -> V_20 -> V_41 ) ;
return V_33 ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 ;
F_28 ( & V_2 -> V_20 -> V_41 ) ;
if ( V_8 -> V_100 > 0 ) {
V_8 -> V_100 -- ;
if ( V_8 -> V_100 == 0 ) {
V_33 = F_69 ( V_8 -> V_64 ) ;
if ( V_33 ) {
F_13 ( V_2 -> V_20 -> V_20 ,
L_11 , V_33 ) ;
}
V_33 = F_66 ( V_8 -> V_64 ) ;
if ( V_33 ) {
F_13 ( V_2 -> V_20 -> V_20 ,
L_12 , V_33 ) ;
}
V_8 -> V_56 = 0 ;
V_8 -> V_64 = NULL ;
}
}
F_29 ( & V_2 -> V_20 -> V_41 ) ;
}
int F_70 ( struct V_1 * V_2 , T_4 V_102 ,
int V_103 , int V_104 , T_3 * V_56 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = - V_46 ;
F_28 ( & V_2 -> V_20 -> V_41 ) ;
if ( ( V_8 -> V_100 > 0 ) && V_8 -> V_64 &&
( V_8 -> V_23 & V_24 ) ) {
* V_56 = F_71 ( V_8 -> V_64 , V_102 , V_103 , V_104 ) ;
V_33 = 0 ;
}
F_29 ( & V_2 -> V_20 -> V_41 ) ;
return V_33 ;
}
int F_72 ( struct V_1 * V_2 , T_4 V_102 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = - V_46 ;
if ( V_8 -> V_23 & V_24 )
V_33 = F_73 ( F_6 ( V_8 -> V_23 ) , V_102 ) ;
return V_33 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_30 * * * V_31 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = 0 ;
if ( F_7 ( V_2 ) && ! V_8 -> V_31 ) {
V_33 = F_9 ( V_2 ) ;
if ( V_33 ) {
F_13 ( V_2 -> V_20 -> V_20 , L_13 ) ;
return V_33 ;
}
}
* V_31 = V_8 -> V_31 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , struct V_30 * * * V_31 ,
bool V_95 )
{
int V_33 ;
if ( ! V_95 ) {
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! V_8 -> V_31 )
return - V_38 ;
* V_31 = V_8 -> V_31 ;
return 0 ;
}
F_28 ( & V_2 -> V_20 -> V_41 ) ;
V_33 = F_44 ( V_2 , V_31 ) ;
F_29 ( & V_2 -> V_20 -> V_41 ) ;
return V_33 ;
}
int F_75 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_10 ( ! F_23 ( & V_2 -> V_20 -> V_41 ) ) ;
if ( ! V_8 -> V_58 ) {
struct V_30 * * V_31 ;
int V_33 = F_44 ( V_2 , & V_31 ) ;
if ( V_33 )
return F_77 ( V_33 ) ;
V_8 -> V_58 = F_78 ( V_31 , V_2 -> V_12 >> V_16 ,
V_105 , F_49 ( V_106 ) ) ;
}
return V_8 -> V_58 ;
}
int F_79 ( struct V_107 * V_20 )
{
struct V_29 * V_108 = F_80 ( V_20 ) ;
struct V_96 * V_97 = V_108 -> V_98 ;
struct V_7 * V_8 ;
int V_33 = 0 ;
F_81 (omap_obj, &priv->obj_list, mm_list) {
if ( V_8 -> V_64 ) {
struct V_1 * V_2 = & V_8 -> V_109 ;
T_4 V_32 = V_2 -> V_12 >> V_16 ;
F_10 ( ! V_8 -> V_31 ) ;
V_33 = F_41 ( V_8 -> V_64 ,
V_8 -> V_31 , V_32 ,
V_8 -> V_90 , true ) ;
if ( V_33 ) {
F_13 ( V_20 , L_7 , V_33 ) ;
return V_33 ;
}
}
}
return 0 ;
}
void F_82 ( struct V_1 * V_2 , struct V_110 * V_17 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_5 V_14 ;
V_14 = F_83 ( & V_2 -> V_42 ) ;
F_84 ( V_17 , L_14 ,
V_8 -> V_23 , V_2 -> V_111 , V_2 -> V_112 . V_112 . V_113 ,
V_14 , & V_8 -> V_56 , V_8 -> V_100 ,
V_8 -> V_58 , V_8 -> V_90 ) ;
if ( V_8 -> V_23 & V_24 ) {
F_84 ( V_17 , L_15 , V_8 -> V_18 , V_8 -> V_11 ) ;
if ( V_8 -> V_64 ) {
struct V_114 * V_115 = & V_8 -> V_64 -> V_115 ;
F_84 ( V_17 , L_16 ,
V_115 -> V_116 . V_103 , V_115 -> V_116 . V_104 ,
V_115 -> V_117 . V_103 , V_115 -> V_117 . V_104 ) ;
}
} else {
F_84 ( V_17 , L_17 , V_2 -> V_12 ) ;
}
F_84 ( V_17 , L_18 ) ;
}
void F_85 ( struct V_118 * V_119 , struct V_110 * V_17 )
{
struct V_7 * V_8 ;
int V_120 = 0 ;
T_1 V_12 = 0 ;
F_81 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_8 -> V_109 ;
F_84 ( V_17 , L_19 ) ;
F_82 ( V_2 , V_17 ) ;
V_120 ++ ;
V_12 += V_2 -> V_12 ;
}
F_84 ( V_17 , L_20 , V_120 , V_12 ) ;
}
static inline bool F_86 ( struct V_121 * V_122 )
{
struct V_7 * V_8 = V_122 -> V_8 ;
if ( ( V_122 -> V_123 & V_124 ) &&
( V_8 -> V_125 -> V_126 < V_122 -> V_127 ) )
return true ;
if ( ( V_122 -> V_123 & V_128 ) &&
( V_8 -> V_125 -> V_129 < V_122 -> V_130 ) )
return true ;
return false ;
}
static void F_87 ( void )
{
struct V_121 * V_122 , * V_9 ;
F_88 (waiter, n, &waiters, list) {
if ( ! F_86 ( V_122 ) ) {
F_89 ( & V_122 -> V_119 ) ;
F_90 ( L_21 , V_122 ) ;
V_122 -> V_131 ( V_122 -> V_132 ) ;
F_21 ( V_122 ) ;
}
}
}
static inline int F_91 ( struct V_1 * V_2 ,
enum V_133 V_123 , bool V_134 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = 0 ;
F_92 ( & V_135 ) ;
if ( ! V_8 -> V_125 ) {
V_8 -> V_125 = F_17 ( sizeof( * V_8 -> V_125 ) , V_136 ) ;
if ( ! V_8 -> V_125 ) {
V_33 = - V_38 ;
goto V_137;
}
}
if ( V_134 ) {
if ( V_123 & V_124 )
V_8 -> V_125 -> V_138 ++ ;
if ( V_123 & V_128 )
V_8 -> V_125 -> V_139 ++ ;
} else {
if ( V_123 & V_124 )
V_8 -> V_125 -> V_129 ++ ;
if ( V_123 & V_128 )
V_8 -> V_125 -> V_126 ++ ;
F_87 () ;
}
V_137:
F_93 ( & V_135 ) ;
return V_33 ;
}
void F_94 ( void )
{
F_92 ( & V_135 ) ;
F_87 () ;
F_93 ( & V_135 ) ;
}
int F_95 ( struct V_1 * V_2 , enum V_133 V_123 )
{
return F_91 ( V_2 , V_123 , true ) ;
}
int F_96 ( struct V_1 * V_2 , enum V_133 V_123 )
{
return F_91 ( V_2 , V_123 , false ) ;
}
static void F_97 ( void * V_132 )
{
struct V_140 * * V_141 = V_132 ;
* V_141 = NULL ;
F_98 ( & V_142 ) ;
}
int F_99 ( struct V_1 * V_2 , enum V_133 V_123 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = 0 ;
if ( V_8 -> V_125 ) {
struct V_140 * V_141 = V_143 ;
struct V_121 * V_122 =
F_17 ( sizeof( * V_122 ) , V_37 ) ;
if ( ! V_122 )
return - V_38 ;
V_122 -> V_8 = V_8 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_130 = V_8 -> V_125 -> V_138 ;
V_122 -> V_127 = V_8 -> V_125 -> V_139 ;
V_122 -> V_131 = F_97 ;
V_122 -> V_132 = & V_141 ;
F_92 ( & V_135 ) ;
if ( F_86 ( V_122 ) ) {
F_90 ( L_22 , V_122 ) ;
F_100 ( & V_122 -> V_119 , & V_144 ) ;
F_93 ( & V_135 ) ;
V_33 = F_101 ( V_142 ,
( V_141 == NULL ) ) ;
F_92 ( & V_135 ) ;
if ( V_141 ) {
F_90 ( L_23 , V_122 ) ;
F_89 ( & V_122 -> V_119 ) ;
V_141 = NULL ;
} else {
V_122 = NULL ;
}
}
F_93 ( & V_135 ) ;
F_21 ( V_122 ) ;
}
return V_33 ;
}
int F_102 ( struct V_1 * V_2 , enum V_133 V_123 ,
void (* F_103)( void * V_132 ) , void * V_132 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_125 ) {
struct V_121 * V_122 =
F_17 ( sizeof( * V_122 ) , V_136 ) ;
if ( ! V_122 )
return - V_38 ;
V_122 -> V_8 = V_8 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_130 = V_8 -> V_125 -> V_138 ;
V_122 -> V_127 = V_8 -> V_125 -> V_139 ;
V_122 -> V_131 = F_103 ;
V_122 -> V_132 = V_132 ;
F_92 ( & V_135 ) ;
if ( F_86 ( V_122 ) ) {
F_90 ( L_22 , V_122 ) ;
F_100 ( & V_122 -> V_119 , & V_144 ) ;
F_93 ( & V_135 ) ;
return 0 ;
}
F_93 ( & V_135 ) ;
F_21 ( V_122 ) ;
}
F_103 ( V_132 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 , void * V_145 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 = 0 ;
F_92 ( & V_135 ) ;
if ( ( V_8 -> V_23 & V_146 ) && ! V_145 ) {
V_145 = F_105 ( V_8 -> V_125 , sizeof( * V_8 -> V_125 ) ,
V_136 ) ;
if ( ! V_145 ) {
V_33 = - V_38 ;
goto V_137;
}
V_8 -> V_23 &= ~ V_146 ;
V_8 -> V_125 = V_145 ;
} else if ( V_145 && ! ( V_8 -> V_23 & V_146 ) ) {
if ( V_8 -> V_125 ) {
memcpy ( V_145 , V_8 -> V_125 , sizeof( * V_8 -> V_125 ) ) ;
F_21 ( V_8 -> V_125 ) ;
}
V_8 -> V_23 |= V_146 ;
V_8 -> V_125 = V_145 ;
}
V_137:
F_93 ( & V_135 ) ;
return V_33 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
struct V_96 * V_97 = V_20 -> V_98 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_10 ( ! F_23 ( & V_20 -> V_41 ) ) ;
F_92 ( & V_97 -> V_147 ) ;
F_89 ( & V_8 -> V_148 ) ;
F_93 ( & V_97 -> V_147 ) ;
F_107 ( V_2 ) ;
F_10 ( V_8 -> V_100 > 0 ) ;
if ( ! ( V_8 -> V_23 & V_149 ) ) {
if ( V_8 -> V_31 )
F_19 ( V_2 ) ;
if ( ! F_7 ( V_2 ) ) {
F_108 ( V_20 -> V_20 , V_2 -> V_12 ,
V_8 -> V_58 , V_8 -> V_56 ) ;
} else if ( V_8 -> V_58 ) {
F_109 ( V_8 -> V_58 ) ;
}
}
if ( ! ( V_8 -> V_23 & V_146 ) )
F_21 ( V_8 -> V_125 ) ;
F_110 ( V_2 ) ;
F_21 ( V_2 ) ;
}
int F_57 ( struct V_29 * V_20 , struct V_80 * V_73 ,
union V_82 V_83 , T_4 V_23 , T_4 * V_88 )
{
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_111 ( V_20 , V_83 , V_23 ) ;
if ( ! V_2 )
return - V_38 ;
V_33 = F_112 ( V_73 , V_2 , V_88 ) ;
if ( V_33 ) {
F_110 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_33 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_111 ( struct V_29 * V_20 ,
union V_82 V_83 , T_4 V_23 )
{
struct V_96 * V_97 = V_20 -> V_98 ;
struct V_7 * V_8 ;
struct V_1 * V_2 = NULL ;
struct V_150 * V_151 ;
T_1 V_12 ;
int V_33 ;
if ( V_23 & V_24 ) {
if ( ! V_10 ) {
F_13 ( V_20 -> V_20 , L_24 ) ;
goto V_67;
}
V_23 &= ~ V_87 ;
V_23 &= ~ ( V_28 | V_35 | V_36 ) ;
V_23 |= F_113 () ;
F_114 ( F_6 ( V_23 ) ,
& V_83 . V_152 . V_18 , & V_83 . V_152 . V_11 ) ;
V_12 = F_115 ( F_6 ( V_23 ) ,
V_83 . V_152 . V_18 , V_83 . V_152 . V_11 ) ;
} else {
V_12 = F_56 ( V_83 . V_86 ) ;
}
V_8 = F_17 ( sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return NULL ;
V_2 = & V_8 -> V_109 ;
if ( ( V_23 & V_87 ) && ! V_97 -> V_99 ) {
V_8 -> V_58 = F_116 ( V_20 -> V_20 , V_12 ,
& V_8 -> V_56 , V_37 ) ;
if ( ! V_8 -> V_58 ) {
F_21 ( V_8 ) ;
return NULL ;
}
V_23 |= V_55 ;
}
F_92 ( & V_97 -> V_147 ) ;
F_117 ( & V_8 -> V_148 , & V_97 -> V_153 ) ;
F_93 ( & V_97 -> V_147 ) ;
V_8 -> V_23 = V_23 ;
if ( V_23 & V_24 ) {
V_8 -> V_18 = V_83 . V_152 . V_18 ;
V_8 -> V_11 = V_83 . V_152 . V_11 ;
}
if ( V_23 & ( V_55 | V_149 ) ) {
F_118 ( V_20 , V_2 , V_12 ) ;
} else {
V_33 = F_119 ( V_20 , V_2 , V_12 ) ;
if ( V_33 )
goto V_67;
V_151 = F_120 ( V_2 -> V_26 ) -> V_22 ;
F_121 ( V_151 , V_154 | V_155 ) ;
}
return V_2 ;
V_67:
if ( V_2 )
F_106 ( V_2 ) ;
return NULL ;
}
void F_122 ( struct V_29 * V_20 )
{
struct V_96 * V_97 = V_20 -> V_98 ;
const enum V_3 V_156 [] = {
V_157 , V_158 , V_159
} ;
int V_19 , V_160 ;
if ( ! F_123 () ) {
F_124 ( V_20 -> V_20 , L_25 ) ;
return;
}
V_10 = F_125 ( 3 , sizeof( * V_10 ) , V_37 ) ;
if ( ! V_10 )
return;
for ( V_19 = 0 ; V_19 < F_42 ( V_156 ) ; V_19 ++ ) {
T_6 V_45 = 1 , V_44 = V_13 >> V_19 ;
F_114 ( V_156 [ V_19 ] , & V_44 , & V_45 ) ;
V_10 [ V_19 ] . V_11 = V_45 ;
V_10 [ V_19 ] . V_61 = F_126 ( V_45 ) ;
V_10 [ V_19 ] . V_65 = F_73 ( V_156 [ V_19 ] , 0 ) >> V_16 ;
V_10 [ V_19 ] . V_62 = F_126 ( ( V_13 / V_45 ) >> V_19 ) ;
for ( V_160 = 0 ; V_160 < V_25 ; V_160 ++ ) {
struct V_5 * V_6 = & V_10 [ V_19 ] . V_6 [ V_160 ] ;
struct V_101 * V_64 =
F_64 ( V_156 [ V_19 ] , V_44 , V_45 ,
V_13 ) ;
if ( F_12 ( V_64 ) ) {
F_13 ( V_20 -> V_20 ,
L_26 ,
V_19 , V_160 , F_14 ( V_64 ) ) ;
return;
}
V_6 -> V_56 = F_67 ( V_64 ) ;
V_6 -> V_64 = V_64 ;
F_47 ( L_27 , V_19 , V_160 , V_44 , V_45 ,
& V_6 -> V_56 ,
V_10 [ V_19 ] . V_65 << V_16 ) ;
}
}
V_97 -> V_99 = true ;
}
void F_127 ( struct V_29 * V_20 )
{
F_21 ( V_10 ) ;
}
