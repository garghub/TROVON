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
if ( V_10 -> V_40 [ V_32 ] )
F_22 ( V_2 -> V_4 -> V_4 ,
V_10 -> V_40 [ V_32 ] ,
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
static int F_33 ( struct V_1 * V_2 ,
struct V_51 * V_52 , struct V_53 * V_54 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_55 ;
T_6 V_56 ;
V_56 = ( V_54 -> V_57 - V_52 -> V_58 ) >> V_29 ;
if ( V_10 -> V_38 ) {
F_34 ( V_2 , V_56 ) ;
V_55 = F_35 ( V_10 -> V_38 [ V_56 ] ) ;
} else {
F_36 ( ! F_8 ( V_10 ) ) ;
V_55 = ( V_10 -> V_59 >> V_29 ) + V_56 ;
}
F_37 ( L_5 , ( void * ) V_54 -> V_57 ,
V_55 , V_55 << V_29 ) ;
return F_38 ( V_52 , V_54 -> V_57 , F_39 ( V_55 , V_60 ) ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_51 * V_52 , struct V_53 * V_54 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
struct V_18 * V_19 ;
enum V_16 V_17 = F_13 ( V_10 -> V_11 ) ;
struct V_37 * V_38 [ 64 ] ;
unsigned long V_55 ;
T_6 V_56 , V_61 ;
unsigned long V_62 ;
int V_32 , V_5 , V_63 ;
const int V_23 = V_21 -> V_24 [ V_17 ] . V_25 ;
const int V_64 = V_21 -> V_24 [ V_17 ] . V_65 ;
const int V_30 = 1 + ( ( V_10 -> V_31 << V_17 ) / V_26 ) ;
V_56 = ( V_54 -> V_57 - V_52 -> V_58 ) >> V_29 ;
V_61 = F_41 ( V_56 , V_30 << V_64 ) ;
V_63 = V_10 -> V_31 >> V_21 -> V_24 [ V_17 ] . V_66 ;
V_62 = V_54 -> V_57 - ( ( V_56 - V_61 ) << V_29 ) ;
V_19 = & V_21 -> V_24 [ V_17 ] . V_19 [ V_21 -> V_24 [ V_17 ] . V_67 ] ;
if ( V_19 -> V_2 )
F_9 ( V_19 -> V_2 , V_17 , V_19 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_28 = V_61 ;
V_61 = ( V_61 >> V_64 ) * V_63 ;
if ( V_30 > 1 ) {
int V_27 = V_56 % V_30 ;
V_19 -> V_28 += V_27 ;
V_61 /= V_30 ;
V_63 = F_42 ( V_63 - ( V_27 << V_64 ) , V_23 ) ;
V_61 += V_27 << V_64 ;
V_62 += V_27 << V_29 ;
}
memcpy ( V_38 , & V_10 -> V_38 [ V_61 ] ,
sizeof( struct V_37 * ) * V_63 ) ;
memset ( V_38 + V_63 , 0 ,
sizeof( struct V_37 * ) * ( V_23 - V_63 ) ) ;
V_5 = F_43 ( V_19 -> V_68 , V_38 , F_44 ( V_38 ) , 0 , true ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_6 , V_5 ) ;
return V_5 ;
}
V_55 = V_19 -> V_59 >> V_29 ;
F_37 ( L_5 , ( void * ) V_54 -> V_57 ,
V_55 , V_55 << V_29 ) ;
for ( V_32 = V_23 ; V_32 > 0 ; V_32 -- ) {
F_38 ( V_52 , V_62 , F_39 ( V_55 , V_60 ) ) ;
V_55 += V_21 -> V_24 [ V_17 ] . V_69 ;
V_62 += V_26 * V_30 ;
}
V_21 -> V_24 [ V_17 ] . V_67 = ( V_21 -> V_24 [ V_17 ] . V_67 + 1 )
% V_36 ;
return 0 ;
}
int F_45 ( struct V_53 * V_54 )
{
struct V_51 * V_52 = V_54 -> V_52 ;
struct V_1 * V_2 = V_52 -> V_70 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * * V_38 ;
int V_5 ;
F_30 ( & V_4 -> V_7 ) ;
V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_71;
if ( V_10 -> V_11 & V_35 )
V_5 = F_40 ( V_2 , V_52 , V_54 ) ;
else
V_5 = F_33 ( V_2 , V_52 , V_54 ) ;
V_71:
F_31 ( & V_4 -> V_7 ) ;
switch ( V_5 ) {
case 0 :
case - V_72 :
case - V_73 :
case - V_74 :
return V_75 ;
case - V_44 :
return V_76 ;
default:
return V_77 ;
}
}
int F_46 ( struct V_78 * V_79 , struct V_51 * V_52 )
{
int V_5 ;
V_5 = F_47 ( V_79 , V_52 ) ;
if ( V_5 ) {
F_48 ( L_7 , V_5 ) ;
return V_5 ;
}
return F_49 ( V_52 -> V_70 , V_52 ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
V_52 -> V_80 &= ~ V_81 ;
V_52 -> V_80 |= V_82 ;
if ( V_10 -> V_11 & V_41 ) {
V_52 -> V_83 = F_50 ( F_51 ( V_52 -> V_80 ) ) ;
} else if ( V_10 -> V_11 & V_42 ) {
V_52 -> V_83 = F_52 ( F_51 ( V_52 -> V_80 ) ) ;
} else {
if ( F_2 ( ! V_2 -> V_79 ) )
return - V_84 ;
F_53 ( V_52 -> V_85 ) ;
V_52 -> V_86 = 0 ;
V_52 -> V_85 = F_54 ( V_2 -> V_79 ) ;
V_52 -> V_83 = F_51 ( V_52 -> V_80 ) ;
}
return 0 ;
}
int F_55 ( struct V_87 * V_78 , struct V_3 * V_4 ,
struct V_88 * args )
{
union V_89 V_90 ;
args -> V_91 = F_56 ( args -> V_31 * args -> V_92 , 8 ) ;
args -> V_6 = F_57 ( args -> V_91 * args -> V_25 ) ;
V_90 = (union V_89 ) {
. V_93 = args -> V_6 ,
} ;
return F_58 ( V_4 , V_78 , V_90 ,
V_94 | V_41 , & args -> V_95 ) ;
}
int F_59 ( struct V_87 * V_78 , struct V_3 * V_4 ,
T_5 V_95 , T_1 * V_50 )
{
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = F_60 ( V_78 , V_95 ) ;
if ( V_2 == NULL ) {
V_5 = - V_96 ;
goto V_71;
}
* V_50 = F_29 ( V_2 ) ;
F_61 ( V_2 ) ;
V_71:
return V_5 ;
}
int F_62 ( struct V_1 * V_2 , T_5 V_97 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
int V_5 = 0 ;
if ( V_97 > V_39 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_8 , V_97 ) ;
return - V_84 ;
}
V_10 -> V_97 = V_97 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_10 -> V_68 ) {
struct V_37 * * V_38 ;
V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_71;
V_5 = F_43 ( V_10 -> V_68 , V_38 , V_39 , V_97 , true ) ;
if ( V_5 )
F_6 ( V_2 -> V_4 -> V_4 , L_9 , V_5 ) ;
}
V_71:
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
static inline bool F_63 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
return ( V_10 -> V_11 & V_49 ) &&
( ( V_10 -> V_11 & V_98 ) == V_99 ) ;
}
void F_34 ( struct V_1 * V_2 , int V_56 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( F_63 ( V_2 ) && V_10 -> V_40 [ V_56 ] ) {
F_22 ( V_4 -> V_4 , V_10 -> V_40 [ V_56 ] ,
V_26 , V_46 ) ;
V_10 -> V_40 [ V_56 ] = 0 ;
}
}
void F_64 ( struct V_1 * V_2 ,
enum V_100 V_101 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( F_63 ( V_2 ) ) {
int V_32 , V_39 = V_2 -> V_6 >> V_29 ;
struct V_37 * * V_38 = V_10 -> V_38 ;
bool V_102 = false ;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
if ( ! V_10 -> V_40 [ V_32 ] ) {
T_4 V_103 ;
V_103 = F_19 ( V_4 -> V_4 , V_38 [ V_32 ] , 0 ,
V_26 , V_46 ) ;
if ( F_20 ( V_4 -> V_4 , V_103 ) ) {
F_21 ( V_4 -> V_4 ,
L_3 ,
V_47 ) ;
break;
}
V_102 = true ;
V_10 -> V_40 [ V_32 ] = V_103 ;
}
}
if ( V_102 ) {
F_11 ( V_2 -> V_79 -> V_104 , 0 ,
F_4 ( V_2 ) , 1 ) ;
}
}
}
int F_65 ( struct V_1 * V_2 ,
T_4 * V_59 , bool V_105 )
{
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( ! F_8 ( V_10 ) && V_105 && V_21 -> V_106 ) {
if ( V_10 -> V_107 == 0 ) {
struct V_37 * * V_38 ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
enum V_16 V_17 = F_13 ( V_10 -> V_11 ) ;
struct V_108 * V_68 ;
F_36 ( V_10 -> V_68 ) ;
V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_71;
if ( V_10 -> V_11 & V_35 ) {
V_68 = F_66 ( V_17 ,
V_10 -> V_31 ,
V_10 -> V_25 , 0 ) ;
} else {
V_68 = F_67 ( V_2 -> V_6 ) ;
}
if ( F_16 ( V_68 ) ) {
V_5 = F_17 ( V_68 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_10 , V_5 , V_17 ) ;
goto V_71;
}
V_5 = F_43 ( V_68 , V_38 , V_39 ,
V_10 -> V_97 , true ) ;
if ( V_5 ) {
F_68 ( V_68 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_11 , V_5 ) ;
goto V_71;
}
V_10 -> V_59 = F_69 ( V_68 ) ;
V_10 -> V_68 = V_68 ;
F_48 ( L_12 , & V_10 -> V_59 ) ;
}
V_10 -> V_107 ++ ;
* V_59 = V_10 -> V_59 ;
} else if ( F_8 ( V_10 ) ) {
* V_59 = V_10 -> V_59 ;
} else {
V_5 = - V_84 ;
goto V_71;
}
V_71:
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_10 -> V_107 > 0 ) {
V_10 -> V_107 -- ;
if ( V_10 -> V_107 == 0 ) {
V_5 = F_71 ( V_10 -> V_68 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_13 , V_5 ) ;
}
V_5 = F_68 ( V_10 -> V_68 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_14 , V_5 ) ;
}
V_10 -> V_59 = 0 ;
V_10 -> V_68 = NULL ;
}
}
F_31 ( & V_2 -> V_4 -> V_7 ) ;
}
int F_72 ( struct V_1 * V_2 , T_5 V_109 ,
int V_110 , int V_111 , T_4 * V_59 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = - V_84 ;
F_30 ( & V_2 -> V_4 -> V_7 ) ;
if ( ( V_10 -> V_107 > 0 ) && V_10 -> V_68 &&
( V_10 -> V_11 & V_35 ) ) {
* V_59 = F_73 ( V_10 -> V_68 , V_109 , V_110 , V_111 ) ;
V_5 = 0 ;
}
F_31 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
int F_74 ( struct V_1 * V_2 , T_5 V_109 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = - V_84 ;
if ( V_10 -> V_11 & V_35 )
V_5 = F_75 ( F_13 ( V_10 -> V_11 ) , V_109 ) ;
return V_5 ;
}
int F_76 ( struct V_1 * V_2 , struct V_37 * * * V_38 ,
bool V_105 )
{
int V_5 ;
if ( ! V_105 ) {
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
int F_77 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_78 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_2 ( ! F_3 ( & V_2 -> V_4 -> V_7 ) ) ;
if ( ! V_10 -> V_62 ) {
struct V_37 * * V_38 ;
int V_5 = F_26 ( V_2 , & V_38 ) ;
if ( V_5 )
return F_79 ( V_5 ) ;
V_10 -> V_62 = F_80 ( V_38 , V_2 -> V_6 >> V_29 ,
V_112 , F_50 ( V_113 ) ) ;
}
return V_10 -> V_62 ;
}
int F_81 ( struct V_114 * V_4 )
{
struct V_3 * V_115 = F_82 ( V_4 ) ;
struct V_20 * V_21 = V_115 -> V_22 ;
struct V_9 * V_10 ;
int V_5 = 0 ;
F_83 (omap_obj, &priv->obj_list, mm_list) {
if ( V_10 -> V_68 ) {
struct V_1 * V_2 = & V_10 -> V_116 ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
F_2 ( ! V_10 -> V_38 ) ;
V_5 = F_43 ( V_10 -> V_68 ,
V_10 -> V_38 , V_39 ,
V_10 -> V_97 , true ) ;
if ( V_5 ) {
F_6 ( V_4 , L_9 , V_5 ) ;
return V_5 ;
}
}
}
return 0 ;
}
void F_84 ( struct V_1 * V_2 , struct V_117 * V_30 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_1 V_27 ;
V_27 = F_85 ( & V_2 -> V_8 ) ;
F_86 ( V_30 , L_15 ,
V_10 -> V_11 , V_2 -> V_118 , F_87 ( & V_2 -> V_119 ) ,
V_27 , & V_10 -> V_59 , V_10 -> V_107 ,
V_10 -> V_62 , V_10 -> V_97 ) ;
if ( V_10 -> V_11 & V_35 ) {
F_86 ( V_30 , L_16 , V_10 -> V_31 , V_10 -> V_25 ) ;
if ( V_10 -> V_68 ) {
struct V_120 * V_121 = & V_10 -> V_68 -> V_121 ;
F_86 ( V_30 , L_17 ,
V_121 -> V_122 . V_110 , V_121 -> V_122 . V_111 ,
V_121 -> V_123 . V_110 , V_121 -> V_123 . V_111 ) ;
}
} else {
F_86 ( V_30 , L_18 , V_2 -> V_6 ) ;
}
F_86 ( V_30 , L_19 ) ;
}
void F_88 ( struct V_124 * V_125 , struct V_117 * V_30 )
{
struct V_9 * V_10 ;
int V_126 = 0 ;
T_2 V_6 = 0 ;
F_83 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_116 ;
F_86 ( V_30 , L_20 ) ;
F_84 ( V_2 , V_30 ) ;
V_126 ++ ;
V_6 += V_2 -> V_6 ;
}
F_86 ( V_30 , L_21 , V_126 , V_6 ) ;
}
static inline bool F_89 ( struct V_127 * V_128 )
{
struct V_9 * V_10 = V_128 -> V_10 ;
if ( ( V_128 -> V_129 & V_130 ) &&
( V_10 -> V_131 -> V_132 < V_128 -> V_133 ) )
return true ;
if ( ( V_128 -> V_129 & V_134 ) &&
( V_10 -> V_131 -> V_135 < V_128 -> V_136 ) )
return true ;
return false ;
}
static void F_90 ( void )
{
struct V_127 * V_128 , * V_23 ;
F_91 (waiter, n, &waiters, list) {
if ( ! F_89 ( V_128 ) ) {
F_92 ( & V_128 -> V_125 ) ;
F_93 ( L_22 , V_128 ) ;
V_128 -> V_137 ( V_128 -> V_138 ) ;
F_24 ( V_128 ) ;
}
}
}
static inline int F_94 ( struct V_1 * V_2 ,
enum V_139 V_129 , bool V_140 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_95 ( & V_141 ) ;
if ( ! V_10 -> V_131 ) {
V_10 -> V_131 = F_23 ( sizeof( * V_10 -> V_131 ) , V_142 ) ;
if ( ! V_10 -> V_131 ) {
V_5 = - V_44 ;
goto V_143;
}
}
if ( V_140 ) {
if ( V_129 & V_130 )
V_10 -> V_131 -> V_144 ++ ;
if ( V_129 & V_134 )
V_10 -> V_131 -> V_145 ++ ;
} else {
if ( V_129 & V_130 )
V_10 -> V_131 -> V_135 ++ ;
if ( V_129 & V_134 )
V_10 -> V_131 -> V_132 ++ ;
F_90 () ;
}
V_143:
F_96 ( & V_141 ) ;
return V_5 ;
}
int F_97 ( struct V_1 * V_2 , enum V_139 V_129 )
{
return F_94 ( V_2 , V_129 , true ) ;
}
int F_98 ( struct V_1 * V_2 , enum V_139 V_129 )
{
return F_94 ( V_2 , V_129 , false ) ;
}
static void F_99 ( void * V_138 )
{
struct V_146 * * V_147 = V_138 ;
* V_147 = NULL ;
F_100 ( & V_148 ) ;
}
int F_101 ( struct V_1 * V_2 , enum V_139 V_129 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
if ( V_10 -> V_131 ) {
struct V_146 * V_147 = V_149 ;
struct V_127 * V_128 =
F_23 ( sizeof( * V_128 ) , V_43 ) ;
if ( ! V_128 )
return - V_44 ;
V_128 -> V_10 = V_10 ;
V_128 -> V_129 = V_129 ;
V_128 -> V_136 = V_10 -> V_131 -> V_144 ;
V_128 -> V_133 = V_10 -> V_131 -> V_145 ;
V_128 -> V_137 = F_99 ;
V_128 -> V_138 = & V_147 ;
F_95 ( & V_141 ) ;
if ( F_89 ( V_128 ) ) {
F_93 ( L_23 , V_128 ) ;
F_102 ( & V_128 -> V_125 , & V_150 ) ;
F_96 ( & V_141 ) ;
V_5 = F_103 ( V_148 ,
( V_147 == NULL ) ) ;
F_95 ( & V_141 ) ;
if ( V_147 ) {
F_93 ( L_24 , V_128 ) ;
F_92 ( & V_128 -> V_125 ) ;
V_147 = NULL ;
} else {
V_128 = NULL ;
}
}
F_96 ( & V_141 ) ;
F_24 ( V_128 ) ;
}
return V_5 ;
}
int F_104 ( struct V_1 * V_2 , enum V_139 V_129 ,
void (* F_105)( void * V_138 ) , void * V_138 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( V_10 -> V_131 ) {
struct V_127 * V_128 =
F_23 ( sizeof( * V_128 ) , V_142 ) ;
if ( ! V_128 )
return - V_44 ;
V_128 -> V_10 = V_10 ;
V_128 -> V_129 = V_129 ;
V_128 -> V_136 = V_10 -> V_131 -> V_144 ;
V_128 -> V_133 = V_10 -> V_131 -> V_145 ;
V_128 -> V_137 = F_105 ;
V_128 -> V_138 = V_138 ;
F_95 ( & V_141 ) ;
if ( F_89 ( V_128 ) ) {
F_93 ( L_23 , V_128 ) ;
F_102 ( & V_128 -> V_125 , & V_150 ) ;
F_96 ( & V_141 ) ;
return 0 ;
}
F_96 ( & V_141 ) ;
F_24 ( V_128 ) ;
}
F_105 ( V_138 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_12 ( V_2 ) ;
F_2 ( ! F_3 ( & V_4 -> V_7 ) ) ;
F_95 ( & V_21 -> V_151 ) ;
F_92 ( & V_10 -> V_152 ) ;
F_96 ( & V_21 -> V_151 ) ;
F_2 ( V_10 -> V_107 > 0 ) ;
if ( V_10 -> V_38 ) {
if ( V_10 -> V_11 & V_13 )
F_24 ( V_10 -> V_38 ) ;
else
F_27 ( V_2 ) ;
}
if ( V_10 -> V_11 & V_12 ) {
F_107 ( V_4 -> V_4 , V_2 -> V_6 , V_10 -> V_62 ,
V_10 -> V_59 ) ;
} else if ( V_10 -> V_62 ) {
F_108 ( V_10 -> V_62 ) ;
} else if ( V_2 -> V_153 ) {
F_109 ( V_2 , V_10 -> V_14 ) ;
}
F_24 ( V_10 -> V_131 ) ;
F_110 ( V_2 ) ;
F_24 ( V_10 ) ;
}
struct V_1 * F_111 ( struct V_3 * V_4 ,
union V_89 V_90 , T_5 V_11 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_154 * V_155 ;
T_2 V_6 ;
int V_5 ;
if ( V_11 & V_35 ) {
if ( ! V_21 -> V_24 ) {
F_6 ( V_4 -> V_4 , L_25 ) ;
return NULL ;
}
V_11 &= ~ V_94 ;
V_11 |= V_49 ;
V_11 &= ~ ( V_99 | V_41 | V_42 ) ;
V_11 |= F_112 () ;
} else if ( ( V_11 & V_94 ) && ! V_21 -> V_106 ) {
V_11 |= V_12 ;
} else if ( ! ( V_11 & V_13 ) ) {
V_11 |= V_49 ;
}
V_10 = F_23 ( sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_116 ;
V_10 -> V_11 = V_11 ;
if ( V_11 & V_35 ) {
F_113 ( F_13 ( V_11 ) , & V_90 . V_156 . V_31 ,
& V_90 . V_156 . V_25 ) ;
V_6 = F_114 ( F_13 ( V_11 ) , V_90 . V_156 . V_31 ,
V_90 . V_156 . V_25 ) ;
V_10 -> V_31 = V_90 . V_156 . V_31 ;
V_10 -> V_25 = V_90 . V_156 . V_25 ;
} else {
V_6 = F_57 ( V_90 . V_93 ) ;
}
if ( ! ( V_11 & V_49 ) ) {
F_115 ( V_4 , V_2 , V_6 ) ;
} else {
V_5 = F_116 ( V_4 , V_2 , V_6 ) ;
if ( V_5 )
goto V_157;
V_155 = V_2 -> V_79 -> V_104 ;
F_117 ( V_155 , V_158 | V_159 ) ;
}
if ( V_11 & V_12 ) {
V_10 -> V_62 = F_118 ( V_4 -> V_4 , V_6 ,
& V_10 -> V_59 ,
V_43 ) ;
if ( ! V_10 -> V_62 )
goto V_160;
}
F_95 ( & V_21 -> V_151 ) ;
F_119 ( & V_10 -> V_152 , & V_21 -> V_161 ) ;
F_96 ( & V_21 -> V_151 ) ;
return V_2 ;
V_160:
F_110 ( V_2 ) ;
V_157:
F_24 ( V_10 ) ;
return NULL ;
}
struct V_1 * F_120 ( struct V_3 * V_4 , T_2 V_6 ,
struct V_162 * V_14 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
union V_89 V_90 ;
if ( V_14 -> V_163 != 1 && ! V_21 -> V_106 )
return F_79 ( - V_84 ) ;
F_30 ( & V_4 -> V_7 ) ;
V_90 . V_93 = F_57 ( V_6 ) ;
V_2 = F_111 ( V_4 , V_90 , V_13 | V_41 ) ;
if ( ! V_2 ) {
V_2 = F_79 ( - V_44 ) ;
goto V_164;
}
V_10 = F_10 ( V_2 ) ;
V_10 -> V_14 = V_14 ;
if ( V_14 -> V_163 == 1 ) {
V_10 -> V_59 = F_121 ( V_14 -> V_165 ) ;
} else {
struct V_166 V_167 ;
struct V_37 * * V_38 ;
unsigned int V_39 ;
unsigned int V_32 = 0 ;
V_39 = F_56 ( V_6 , V_26 ) ;
V_38 = F_122 ( V_39 , sizeof( * V_38 ) , V_43 ) ;
if ( ! V_38 ) {
F_106 ( V_2 ) ;
V_2 = F_79 ( - V_44 ) ;
goto V_164;
}
V_10 -> V_38 = V_38 ;
F_123 (sgt->sgl, &iter, sgt->orig_nents, 0 ) {
V_38 [ V_32 ++ ] = F_124 ( & V_167 ) ;
if ( V_32 > V_39 )
break;
}
if ( F_2 ( V_32 != V_39 ) ) {
F_106 ( V_2 ) ;
V_2 = F_79 ( - V_44 ) ;
goto V_164;
}
}
V_164:
F_31 ( & V_4 -> V_7 ) ;
return V_2 ;
}
int F_58 ( struct V_3 * V_4 , struct V_87 * V_78 ,
union V_89 V_90 , T_5 V_11 , T_5 * V_95 )
{
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_111 ( V_4 , V_90 , V_11 ) ;
if ( ! V_2 )
return - V_44 ;
V_5 = F_125 ( V_78 , V_2 , V_95 ) ;
if ( V_5 ) {
F_106 ( V_2 ) ;
return V_5 ;
}
F_61 ( V_2 ) ;
return 0 ;
}
void F_126 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_168 * V_24 ;
const enum V_16 V_169 [] = {
V_170 , V_171 , V_172
} ;
int V_32 , V_173 ;
if ( ! F_127 () ) {
F_21 ( V_4 -> V_4 , L_26 ) ;
return;
}
V_24 = F_122 ( 3 , sizeof( * V_24 ) , V_43 ) ;
if ( ! V_24 )
return;
for ( V_32 = 0 ; V_32 < F_44 ( V_169 ) ; V_32 ++ ) {
T_7 V_174 = 1 , V_175 = V_26 >> V_32 ;
F_113 ( V_169 [ V_32 ] , & V_175 , & V_174 ) ;
V_24 [ V_32 ] . V_25 = V_174 ;
V_24 [ V_32 ] . V_65 = F_128 ( V_174 ) ;
V_24 [ V_32 ] . V_69 = F_75 ( V_169 [ V_32 ] , 0 ) >> V_29 ;
V_24 [ V_32 ] . V_66 = F_128 ( ( V_26 / V_174 ) >> V_32 ) ;
for ( V_173 = 0 ; V_173 < V_36 ; V_173 ++ ) {
struct V_18 * V_19 ;
struct V_108 * V_68 ;
V_19 = & V_24 [ V_32 ] . V_19 [ V_173 ] ;
V_68 = F_66 ( V_169 [ V_32 ] , V_175 , V_174 , V_26 ) ;
if ( F_16 ( V_68 ) ) {
F_6 ( V_4 -> V_4 ,
L_27 ,
V_32 , V_173 , F_17 ( V_68 ) ) ;
return;
}
V_19 -> V_59 = F_69 ( V_68 ) ;
V_19 -> V_68 = V_68 ;
F_48 ( L_28 , V_32 , V_173 , V_175 , V_174 ,
& V_19 -> V_59 ,
V_24 [ V_32 ] . V_69 << V_29 ) ;
}
}
V_21 -> V_24 = V_24 ;
V_21 -> V_106 = true ;
}
void F_129 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
F_24 ( V_21 -> V_24 ) ;
}
