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
const int V_30 = F_11 ( V_10 -> V_31 << V_17 , V_26 ) ;
if ( V_30 > 1 ) {
int V_32 ;
for ( V_32 = V_23 ; V_32 > 0 ; V_32 -- ) {
F_12 ( V_2 -> V_4 -> V_33 -> V_34 ,
V_27 , V_26 , 1 ) ;
V_27 += V_26 * V_30 ;
}
} else {
F_12 ( V_2 -> V_4 -> V_33 -> V_34 ,
V_27 , V_6 , 1 ) ;
}
V_19 -> V_2 = NULL ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
if ( V_10 -> V_11 & V_35 ) {
enum V_16 V_17 = F_14 ( V_10 -> V_11 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
struct V_18 * V_19 =
& V_21 -> V_24 [ V_17 ] . V_19 [ V_32 ] ;
if ( V_19 -> V_2 == V_2 )
F_9 ( V_2 , V_17 , V_19 ) ;
}
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_37 * * V_38 ;
int V_39 = V_2 -> V_6 >> V_29 ;
int V_32 , V_5 ;
T_4 * V_40 ;
F_2 ( V_10 -> V_38 ) ;
V_38 = F_16 ( V_2 ) ;
if ( F_17 ( V_38 ) ) {
F_6 ( V_2 -> V_4 -> V_4 , L_2 , F_18 ( V_38 ) ) ;
return F_18 ( V_38 ) ;
}
if ( V_10 -> V_11 & ( V_41 | V_42 ) ) {
V_40 = F_19 ( V_39 * sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 ) {
V_5 = - V_44 ;
goto V_45;
}
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
V_40 [ V_32 ] = F_20 ( V_4 -> V_4 , V_38 [ V_32 ] ,
0 , V_26 , V_46 ) ;
if ( F_21 ( V_4 -> V_4 , V_40 [ V_32 ] ) ) {
F_22 ( V_4 -> V_4 ,
L_3 , V_47 ) ;
for ( V_32 = V_32 - 1 ; V_32 >= 0 ; -- V_32 ) {
F_23 ( V_4 -> V_4 , V_40 [ V_32 ] ,
V_26 , V_46 ) ;
}
V_5 = - V_44 ;
goto V_48;
}
}
} else {
V_40 = F_24 ( V_39 * sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 ) {
V_5 = - V_44 ;
goto V_45;
}
}
V_10 -> V_49 = V_40 ;
V_10 -> V_38 = V_38 ;
return 0 ;
V_48:
F_25 ( V_40 ) ;
V_45:
F_26 ( V_2 , V_38 , true , false ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_37 * * * V_38 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
if ( ( V_10 -> V_11 & V_50 ) && ! V_10 -> V_38 ) {
V_5 = F_15 ( V_2 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_4 ) ;
return V_5 ;
}
}
* V_38 = V_10 -> V_38 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned int V_39 = V_2 -> V_6 >> V_29 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
if ( V_10 -> V_49 [ V_32 ] )
F_23 ( V_2 -> V_4 -> V_4 , V_10 -> V_49 [ V_32 ] ,
V_26 , V_46 ) ;
}
F_25 ( V_10 -> V_49 ) ;
V_10 -> V_49 = NULL ;
F_26 ( V_2 , V_10 -> V_38 , true , false ) ;
V_10 -> V_38 = NULL ;
}
T_5 F_29 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) -> V_11 ;
}
T_1 F_30 ( struct V_1 * V_2 )
{
T_1 V_51 ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
V_51 = F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_4 -> V_7 ) ;
return V_51 ;
}
T_2 F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_2 V_6 = V_2 -> V_6 ;
if ( V_10 -> V_11 & V_35 ) {
V_6 = F_33 ( F_14 ( V_10 -> V_11 ) ,
V_10 -> V_31 , V_10 -> V_25 ) ;
}
return V_6 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_56 ;
T_6 V_57 ;
V_57 = ( V_55 -> V_58 - V_53 -> V_59 ) >> V_29 ;
if ( V_10 -> V_38 ) {
F_35 ( V_2 , V_57 ) ;
V_56 = F_36 ( V_10 -> V_38 [ V_57 ] ) ;
} else {
F_37 ( ! F_8 ( V_10 ) ) ;
V_56 = ( V_10 -> V_60 >> V_29 ) + V_57 ;
}
F_38 ( L_5 , ( void * ) V_55 -> V_58 ,
V_56 , V_56 << V_29 ) ;
return F_39 ( V_53 , V_55 -> V_58 , F_40 ( V_56 , V_61 ) ) ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
struct V_18 * V_19 ;
enum V_16 V_17 = F_14 ( V_10 -> V_11 ) ;
struct V_37 * V_38 [ 64 ] ;
unsigned long V_56 ;
T_6 V_57 , V_62 ;
unsigned long V_63 ;
int V_32 , V_5 , V_64 ;
const int V_23 = V_21 -> V_24 [ V_17 ] . V_25 ;
const int V_65 = V_21 -> V_24 [ V_17 ] . V_66 ;
const int V_30 = F_11 ( V_10 -> V_31 << V_17 , V_26 ) ;
V_57 = ( V_55 -> V_58 - V_53 -> V_59 ) >> V_29 ;
V_62 = F_42 ( V_57 , V_30 << V_65 ) ;
V_64 = V_10 -> V_31 >> V_21 -> V_24 [ V_17 ] . V_67 ;
V_63 = V_55 -> V_58 - ( ( V_57 - V_62 ) << V_29 ) ;
V_19 = & V_21 -> V_24 [ V_17 ] . V_19 [ V_21 -> V_24 [ V_17 ] . V_68 ] ;
if ( V_19 -> V_2 )
F_9 ( V_19 -> V_2 , V_17 , V_19 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_28 = V_62 ;
V_62 = ( V_62 >> V_65 ) * V_64 ;
if ( V_30 > 1 ) {
int V_27 = V_57 % V_30 ;
V_19 -> V_28 += V_27 ;
V_62 /= V_30 ;
V_64 = F_43 ( V_64 - ( V_27 << V_65 ) , V_23 ) ;
V_62 += V_27 << V_65 ;
V_63 += V_27 << V_29 ;
}
memcpy ( V_38 , & V_10 -> V_38 [ V_62 ] ,
sizeof( struct V_37 * ) * V_64 ) ;
memset ( V_38 + V_64 , 0 ,
sizeof( struct V_37 * ) * ( V_23 - V_64 ) ) ;
V_5 = F_44 ( V_19 -> V_69 , V_38 , F_45 ( V_38 ) , 0 , true ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_6 , V_5 ) ;
return V_5 ;
}
V_56 = V_19 -> V_60 >> V_29 ;
F_38 ( L_5 , ( void * ) V_55 -> V_58 ,
V_56 , V_56 << V_29 ) ;
for ( V_32 = V_23 ; V_32 > 0 ; V_32 -- ) {
F_39 ( V_53 , V_63 , F_40 ( V_56 , V_61 ) ) ;
V_56 += V_21 -> V_24 [ V_17 ] . V_70 ;
V_63 += V_26 * V_30 ;
}
V_21 -> V_24 [ V_17 ] . V_68 = ( V_21 -> V_24 [ V_17 ] . V_68 + 1 )
% V_36 ;
return 0 ;
}
int F_46 ( struct V_54 * V_55 )
{
struct V_52 * V_53 = V_55 -> V_53 ;
struct V_1 * V_2 = V_53 -> V_71 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * * V_38 ;
int V_5 ;
F_31 ( & V_4 -> V_7 ) ;
V_5 = F_27 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_72;
if ( V_10 -> V_11 & V_35 )
V_5 = F_41 ( V_2 , V_53 , V_55 ) ;
else
V_5 = F_34 ( V_2 , V_53 , V_55 ) ;
V_72:
F_32 ( & V_4 -> V_7 ) ;
switch ( V_5 ) {
case 0 :
case - V_73 :
case - V_74 :
case - V_75 :
return V_76 ;
case - V_44 :
return V_77 ;
default:
return V_78 ;
}
}
int F_47 ( struct V_79 * V_80 , struct V_52 * V_53 )
{
int V_5 ;
V_5 = F_48 ( V_80 , V_53 ) ;
if ( V_5 ) {
F_49 ( L_7 , V_5 ) ;
return V_5 ;
}
return F_50 ( V_53 -> V_71 , V_53 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
V_53 -> V_81 &= ~ V_82 ;
V_53 -> V_81 |= V_83 ;
if ( V_10 -> V_11 & V_41 ) {
V_53 -> V_84 = F_51 ( F_52 ( V_53 -> V_81 ) ) ;
} else if ( V_10 -> V_11 & V_42 ) {
V_53 -> V_84 = F_53 ( F_52 ( V_53 -> V_81 ) ) ;
} else {
if ( F_2 ( ! V_2 -> V_80 ) )
return - V_85 ;
F_54 ( V_53 -> V_86 ) ;
V_53 -> V_87 = 0 ;
V_53 -> V_86 = F_55 ( V_2 -> V_80 ) ;
V_53 -> V_84 = F_52 ( V_53 -> V_81 ) ;
}
return 0 ;
}
int F_56 ( struct V_88 * V_79 , struct V_3 * V_4 ,
struct V_89 * args )
{
union V_90 V_91 ;
args -> V_92 = F_11 ( args -> V_31 * args -> V_93 , 8 ) ;
args -> V_6 = F_57 ( args -> V_92 * args -> V_25 ) ;
V_91 = (union V_90 ) {
. V_94 = args -> V_6 ,
} ;
return F_58 ( V_4 , V_79 , V_91 ,
V_95 | V_41 , & args -> V_96 ) ;
}
int F_59 ( struct V_88 * V_79 , struct V_3 * V_4 ,
T_5 V_96 , T_1 * V_51 )
{
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = F_60 ( V_79 , V_96 ) ;
if ( V_2 == NULL ) {
V_5 = - V_97 ;
goto V_72;
}
* V_51 = F_30 ( V_2 ) ;
F_61 ( V_2 ) ;
V_72:
return V_5 ;
}
int F_62 ( struct V_1 * V_2 , T_5 V_98 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
int V_5 = 0 ;
if ( V_98 > V_39 ) {
F_6 ( V_2 -> V_4 -> V_4 , L_8 , V_98 ) ;
return - V_85 ;
}
V_10 -> V_98 = V_98 ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_10 -> V_69 ) {
struct V_37 * * V_38 ;
V_5 = F_27 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_72;
V_5 = F_44 ( V_10 -> V_69 , V_38 , V_39 , V_98 , true ) ;
if ( V_5 )
F_6 ( V_2 -> V_4 -> V_4 , L_9 , V_5 ) ;
}
V_72:
F_32 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
static inline bool F_63 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
return ! ( ( V_10 -> V_11 & V_50 ) &&
( ( V_10 -> V_11 & V_99 ) == V_100 ) ) ;
}
void F_35 ( struct V_1 * V_2 , int V_57 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( F_63 ( V_2 ) )
return;
if ( V_10 -> V_49 [ V_57 ] ) {
F_23 ( V_4 -> V_4 , V_10 -> V_49 [ V_57 ] ,
V_26 , V_46 ) ;
V_10 -> V_49 [ V_57 ] = 0 ;
}
}
void F_64 ( struct V_1 * V_2 ,
enum V_101 V_102 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_32 , V_39 = V_2 -> V_6 >> V_29 ;
struct V_37 * * V_38 = V_10 -> V_38 ;
bool V_103 = false ;
if ( F_63 ( V_2 ) )
return;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
if ( ! V_10 -> V_49 [ V_32 ] ) {
T_4 V_104 ;
V_104 = F_20 ( V_4 -> V_4 , V_38 [ V_32 ] , 0 ,
V_26 , V_102 ) ;
if ( F_21 ( V_4 -> V_4 , V_104 ) ) {
F_22 ( V_4 -> V_4 , L_3 ,
V_47 ) ;
break;
}
V_103 = true ;
V_10 -> V_49 [ V_32 ] = V_104 ;
}
}
if ( V_103 ) {
F_12 ( V_2 -> V_80 -> V_105 , 0 ,
F_4 ( V_2 ) , 1 ) ;
}
}
int F_65 ( struct V_1 * V_2 , T_4 * V_60 )
{
struct V_20 * V_21 = V_2 -> V_4 -> V_22 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = 0 ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
if ( ! F_8 ( V_10 ) && V_21 -> V_106 ) {
if ( V_10 -> V_107 == 0 ) {
struct V_37 * * V_38 ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
enum V_16 V_17 = F_14 ( V_10 -> V_11 ) ;
struct V_108 * V_69 ;
F_37 ( V_10 -> V_69 ) ;
V_5 = F_27 ( V_2 , & V_38 ) ;
if ( V_5 )
goto V_72;
if ( V_10 -> V_11 & V_35 ) {
V_69 = F_66 ( V_17 ,
V_10 -> V_31 ,
V_10 -> V_25 , 0 ) ;
} else {
V_69 = F_67 ( V_2 -> V_6 ) ;
}
if ( F_17 ( V_69 ) ) {
V_5 = F_18 ( V_69 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_10 , V_5 , V_17 ) ;
goto V_72;
}
V_5 = F_44 ( V_69 , V_38 , V_39 ,
V_10 -> V_98 , true ) ;
if ( V_5 ) {
F_68 ( V_69 ) ;
F_6 ( V_2 -> V_4 -> V_4 ,
L_11 , V_5 ) ;
goto V_72;
}
V_10 -> V_60 = F_69 ( V_69 ) ;
V_10 -> V_69 = V_69 ;
F_49 ( L_12 , & V_10 -> V_60 ) ;
}
V_10 -> V_107 ++ ;
* V_60 = V_10 -> V_60 ;
} else if ( F_8 ( V_10 ) ) {
* V_60 = V_10 -> V_60 ;
} else {
V_5 = - V_85 ;
goto V_72;
}
V_72:
F_32 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
if ( V_10 -> V_107 > 0 ) {
V_10 -> V_107 -- ;
if ( V_10 -> V_107 == 0 ) {
V_5 = F_71 ( V_10 -> V_69 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_13 , V_5 ) ;
}
V_5 = F_68 ( V_10 -> V_69 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_4 -> V_4 ,
L_14 , V_5 ) ;
}
V_10 -> V_60 = 0 ;
V_10 -> V_69 = NULL ;
}
}
F_32 ( & V_2 -> V_4 -> V_7 ) ;
}
int F_72 ( struct V_1 * V_2 , T_5 V_109 ,
int V_110 , int V_111 , T_4 * V_60 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = - V_85 ;
F_31 ( & V_2 -> V_4 -> V_7 ) ;
if ( ( V_10 -> V_107 > 0 ) && V_10 -> V_69 &&
( V_10 -> V_11 & V_35 ) ) {
* V_60 = F_73 ( V_10 -> V_69 , V_109 , V_110 , V_111 ) ;
V_5 = 0 ;
}
F_32 ( & V_2 -> V_4 -> V_7 ) ;
return V_5 ;
}
int F_74 ( struct V_1 * V_2 , T_5 V_109 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_5 = - V_85 ;
if ( V_10 -> V_11 & V_35 )
V_5 = F_75 ( F_14 ( V_10 -> V_11 ) , V_109 ) ;
return V_5 ;
}
int F_76 ( struct V_1 * V_2 , struct V_37 * * * V_38 ,
bool V_112 )
{
int V_5 ;
if ( ! V_112 ) {
struct V_9 * V_10 = F_10 ( V_2 ) ;
if ( ! V_10 -> V_38 )
return - V_44 ;
* V_38 = V_10 -> V_38 ;
return 0 ;
}
F_31 ( & V_2 -> V_4 -> V_7 ) ;
V_5 = F_27 ( V_2 , V_38 ) ;
F_32 ( & V_2 -> V_4 -> V_7 ) ;
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
if ( ! V_10 -> V_63 ) {
struct V_37 * * V_38 ;
int V_5 = F_27 ( V_2 , & V_38 ) ;
if ( V_5 )
return F_79 ( V_5 ) ;
V_10 -> V_63 = F_80 ( V_38 , V_2 -> V_6 >> V_29 ,
V_113 , F_51 ( V_114 ) ) ;
}
return V_10 -> V_63 ;
}
int F_81 ( struct V_115 * V_4 )
{
struct V_3 * V_116 = F_82 ( V_4 ) ;
struct V_20 * V_21 = V_116 -> V_22 ;
struct V_9 * V_10 ;
int V_5 = 0 ;
F_83 (omap_obj, &priv->obj_list, mm_list) {
if ( V_10 -> V_69 ) {
struct V_1 * V_2 = & V_10 -> V_117 ;
T_5 V_39 = V_2 -> V_6 >> V_29 ;
F_2 ( ! V_10 -> V_38 ) ;
V_5 = F_44 ( V_10 -> V_69 ,
V_10 -> V_38 , V_39 ,
V_10 -> V_98 , true ) ;
if ( V_5 ) {
F_6 ( V_4 , L_9 , V_5 ) ;
return V_5 ;
}
}
}
return 0 ;
}
void F_84 ( struct V_1 * V_2 , struct V_118 * V_30 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
T_1 V_27 ;
V_27 = F_85 ( & V_2 -> V_8 ) ;
F_86 ( V_30 , L_15 ,
V_10 -> V_11 , V_2 -> V_119 , F_87 ( & V_2 -> V_120 ) ,
V_27 , & V_10 -> V_60 , V_10 -> V_107 ,
V_10 -> V_63 , V_10 -> V_98 ) ;
if ( V_10 -> V_11 & V_35 ) {
F_86 ( V_30 , L_16 , V_10 -> V_31 , V_10 -> V_25 ) ;
if ( V_10 -> V_69 ) {
struct V_121 * V_122 = & V_10 -> V_69 -> V_122 ;
F_86 ( V_30 , L_17 ,
V_122 -> V_123 . V_110 , V_122 -> V_123 . V_111 ,
V_122 -> V_124 . V_110 , V_122 -> V_124 . V_111 ) ;
}
} else {
F_86 ( V_30 , L_18 , V_2 -> V_6 ) ;
}
F_86 ( V_30 , L_19 ) ;
}
void F_88 ( struct V_125 * V_126 , struct V_118 * V_30 )
{
struct V_9 * V_10 ;
int V_127 = 0 ;
T_2 V_6 = 0 ;
F_83 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_117 ;
F_86 ( V_30 , L_20 ) ;
F_84 ( V_2 , V_30 ) ;
V_127 ++ ;
V_6 += V_2 -> V_6 ;
}
F_86 ( V_30 , L_21 , V_127 , V_6 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
F_2 ( ! F_3 ( & V_4 -> V_7 ) ) ;
F_90 ( & V_21 -> V_128 ) ;
F_91 ( & V_10 -> V_129 ) ;
F_92 ( & V_21 -> V_128 ) ;
F_2 ( V_10 -> V_107 > 0 ) ;
if ( V_10 -> V_38 ) {
if ( V_10 -> V_11 & V_13 )
F_25 ( V_10 -> V_38 ) ;
else
F_28 ( V_2 ) ;
}
if ( V_10 -> V_11 & V_12 ) {
F_93 ( V_4 -> V_4 , V_2 -> V_6 , V_10 -> V_63 ,
V_10 -> V_60 ) ;
} else if ( V_10 -> V_63 ) {
F_94 ( V_10 -> V_63 ) ;
} else if ( V_2 -> V_130 ) {
F_95 ( V_2 , V_10 -> V_14 ) ;
}
F_96 ( V_2 ) ;
F_25 ( V_10 ) ;
}
struct V_1 * F_97 ( struct V_3 * V_4 ,
union V_90 V_91 , T_5 V_11 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_131 * V_132 ;
T_2 V_6 ;
int V_5 ;
if ( V_11 & V_35 ) {
if ( ! V_21 -> V_24 ) {
F_6 ( V_4 -> V_4 , L_22 ) ;
return NULL ;
}
V_11 &= ~ V_95 ;
V_11 |= V_50 ;
V_11 &= ~ ( V_100 | V_41 | V_42 ) ;
V_11 |= F_98 () ;
} else if ( ( V_11 & V_95 ) && ! V_21 -> V_106 ) {
V_11 |= V_12 ;
} else if ( ! ( V_11 & V_13 ) ) {
V_11 |= V_50 ;
}
V_10 = F_24 ( sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_117 ;
V_10 -> V_11 = V_11 ;
if ( V_11 & V_35 ) {
F_99 ( F_14 ( V_11 ) , & V_91 . V_133 . V_31 ,
& V_91 . V_133 . V_25 ) ;
V_6 = F_100 ( F_14 ( V_11 ) , V_91 . V_133 . V_31 ,
V_91 . V_133 . V_25 ) ;
V_10 -> V_31 = V_91 . V_133 . V_31 ;
V_10 -> V_25 = V_91 . V_133 . V_25 ;
} else {
V_6 = F_57 ( V_91 . V_94 ) ;
}
if ( ! ( V_11 & V_50 ) ) {
F_101 ( V_4 , V_2 , V_6 ) ;
} else {
V_5 = F_102 ( V_4 , V_2 , V_6 ) ;
if ( V_5 )
goto V_134;
V_132 = V_2 -> V_80 -> V_105 ;
F_103 ( V_132 , V_135 | V_136 ) ;
}
if ( V_11 & V_12 ) {
V_10 -> V_63 = F_104 ( V_4 -> V_4 , V_6 ,
& V_10 -> V_60 ,
V_43 ) ;
if ( ! V_10 -> V_63 )
goto V_137;
}
F_90 ( & V_21 -> V_128 ) ;
F_105 ( & V_10 -> V_129 , & V_21 -> V_138 ) ;
F_92 ( & V_21 -> V_128 ) ;
return V_2 ;
V_137:
F_96 ( V_2 ) ;
V_134:
F_25 ( V_10 ) ;
return NULL ;
}
struct V_1 * F_106 ( struct V_3 * V_4 , T_2 V_6 ,
struct V_139 * V_14 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
union V_90 V_91 ;
if ( V_14 -> V_140 != 1 && ! V_21 -> V_106 )
return F_79 ( - V_85 ) ;
F_31 ( & V_4 -> V_7 ) ;
V_91 . V_94 = F_57 ( V_6 ) ;
V_2 = F_97 ( V_4 , V_91 , V_13 | V_41 ) ;
if ( ! V_2 ) {
V_2 = F_79 ( - V_44 ) ;
goto V_141;
}
V_10 = F_10 ( V_2 ) ;
V_10 -> V_14 = V_14 ;
if ( V_14 -> V_140 == 1 ) {
V_10 -> V_60 = F_107 ( V_14 -> V_142 ) ;
} else {
struct V_143 V_144 ;
struct V_37 * * V_38 ;
unsigned int V_39 ;
unsigned int V_32 = 0 ;
V_39 = F_11 ( V_6 , V_26 ) ;
V_38 = F_108 ( V_39 , sizeof( * V_38 ) , V_43 ) ;
if ( ! V_38 ) {
F_89 ( V_2 ) ;
V_2 = F_79 ( - V_44 ) ;
goto V_141;
}
V_10 -> V_38 = V_38 ;
F_109 (sgt->sgl, &iter, sgt->orig_nents, 0 ) {
V_38 [ V_32 ++ ] = F_110 ( & V_144 ) ;
if ( V_32 > V_39 )
break;
}
if ( F_2 ( V_32 != V_39 ) ) {
F_89 ( V_2 ) ;
V_2 = F_79 ( - V_44 ) ;
goto V_141;
}
}
V_141:
F_32 ( & V_4 -> V_7 ) ;
return V_2 ;
}
int F_58 ( struct V_3 * V_4 , struct V_88 * V_79 ,
union V_90 V_91 , T_5 V_11 , T_5 * V_96 )
{
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_97 ( V_4 , V_91 , V_11 ) ;
if ( ! V_2 )
return - V_44 ;
V_5 = F_111 ( V_79 , V_2 , V_96 ) ;
if ( V_5 ) {
F_89 ( V_2 ) ;
return V_5 ;
}
F_61 ( V_2 ) ;
return 0 ;
}
void F_112 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_145 * V_24 ;
const enum V_16 V_146 [] = {
V_147 , V_148 , V_149
} ;
int V_32 , V_150 ;
if ( ! F_113 () ) {
F_22 ( V_4 -> V_4 , L_23 ) ;
return;
}
V_24 = F_108 ( 3 , sizeof( * V_24 ) , V_43 ) ;
if ( ! V_24 )
return;
for ( V_32 = 0 ; V_32 < F_45 ( V_146 ) ; V_32 ++ ) {
T_7 V_151 = 1 , V_152 = V_26 >> V_32 ;
F_99 ( V_146 [ V_32 ] , & V_152 , & V_151 ) ;
V_24 [ V_32 ] . V_25 = V_151 ;
V_24 [ V_32 ] . V_66 = F_114 ( V_151 ) ;
V_24 [ V_32 ] . V_70 = F_75 ( V_146 [ V_32 ] , 0 ) >> V_29 ;
V_24 [ V_32 ] . V_67 = F_114 ( ( V_26 / V_151 ) >> V_32 ) ;
for ( V_150 = 0 ; V_150 < V_36 ; V_150 ++ ) {
struct V_18 * V_19 ;
struct V_108 * V_69 ;
V_19 = & V_24 [ V_32 ] . V_19 [ V_150 ] ;
V_69 = F_66 ( V_146 [ V_32 ] , V_152 , V_151 , V_26 ) ;
if ( F_17 ( V_69 ) ) {
F_6 ( V_4 -> V_4 ,
L_24 ,
V_32 , V_150 , F_18 ( V_69 ) ) ;
return;
}
V_19 -> V_60 = F_69 ( V_69 ) ;
V_19 -> V_69 = V_69 ;
F_49 ( L_25 , V_32 , V_150 , V_152 , V_151 ,
& V_19 -> V_60 ,
V_24 [ V_32 ] . V_70 << V_29 ) ;
}
}
V_21 -> V_24 = V_24 ;
V_21 -> V_106 = true ;
}
void F_115 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
F_25 ( V_21 -> V_24 ) ;
}
