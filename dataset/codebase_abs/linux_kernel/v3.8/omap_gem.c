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
F_10 ( ! F_23 ( & V_7 -> V_40 ) ) ;
if ( ! V_2 -> V_41 . V_42 ) {
T_1 V_14 = F_24 ( V_2 ) ;
int V_32 = F_25 ( V_2 , V_14 ) ;
if ( V_32 ) {
F_13 ( V_7 -> V_7 , L_2 ) ;
return 0 ;
}
}
return ( T_5 ) V_2 -> V_41 . V_43 . V_44 << V_18 ;
}
T_5 F_26 ( struct V_1 * V_2 )
{
T_5 V_45 ;
F_27 ( & V_2 -> V_7 -> V_40 ) ;
V_45 = F_3 ( V_2 ) ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
return V_45 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_14 = V_2 -> V_14 ;
if ( V_10 -> V_22 & V_23 ) {
V_14 = F_29 ( F_6 ( V_10 -> V_22 ) ,
V_10 -> V_20 , V_10 -> V_13 ) ;
}
return V_14 ;
}
int F_30 ( struct V_1 * V_2 , T_6 * V_46 , T_6 * V_47 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & V_23 ) {
* V_46 = V_10 -> V_20 ;
* V_47 = V_10 -> V_13 ;
return 0 ;
}
return - V_48 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_49 * V_50 , struct V_51 * V_52 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned long V_53 ;
T_7 V_54 ;
V_54 = ( ( unsigned long ) V_52 -> V_55 -
V_50 -> V_56 ) >> V_18 ;
if ( V_10 -> V_30 ) {
F_32 ( V_2 , V_54 ) ;
V_53 = F_33 ( V_10 -> V_30 [ V_54 ] ) ;
} else {
F_34 ( ! ( V_10 -> V_22 & V_57 ) ) ;
V_53 = ( V_10 -> V_58 >> V_18 ) + V_54 ;
}
F_35 ( L_3 , V_52 -> V_55 ,
V_53 , V_53 << V_18 ) ;
return F_36 ( V_50 , ( unsigned long ) V_52 -> V_55 , V_53 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_49 * V_50 , struct V_51 * V_52 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_29 * V_30 [ 64 ] ;
unsigned long V_53 ;
T_7 V_54 , V_59 ;
void T_8 * V_60 ;
int V_21 , V_32 , V_61 ;
const int V_11 = V_12 [ V_4 ] . V_13 ;
const int V_62 = V_12 [ V_4 ] . V_63 ;
const int V_19 = 1 + ( ( V_10 -> V_20 << V_4 ) / V_15 ) ;
V_54 = ( ( unsigned long ) V_52 -> V_55 -
V_50 -> V_56 ) >> V_18 ;
V_59 = F_38 ( V_54 , V_19 << V_62 ) ;
V_61 = V_10 -> V_20 >> V_12 [ V_4 ] . V_64 ;
V_60 = V_52 -> V_55 - ( ( V_54 - V_59 ) << V_18 ) ;
V_6 = & V_12 [ V_4 ] . V_6 [ V_12 [ V_4 ] . V_65 ] ;
if ( V_6 -> V_2 )
F_1 ( V_6 -> V_2 , V_4 , V_6 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_17 = V_59 ;
V_59 = ( V_59 >> V_62 ) * V_61 ;
if ( V_19 > 1 ) {
int V_16 = V_54 % V_19 ;
V_6 -> V_17 += V_16 ;
V_59 /= V_19 ;
V_61 = F_39 ( V_61 - ( V_16 << V_62 ) , V_11 ) ;
V_59 += V_16 << V_62 ;
V_60 += V_16 << V_18 ;
}
memcpy ( V_30 , & V_10 -> V_30 [ V_59 ] ,
sizeof( struct V_29 * ) * V_61 ) ;
memset ( V_30 + V_61 , 0 ,
sizeof( struct V_29 * ) * ( V_11 - V_61 ) ) ;
V_32 = F_40 ( V_6 -> V_66 , V_30 , F_41 ( V_30 ) , 0 , true ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_4 , V_32 ) ;
return V_32 ;
}
V_53 = V_6 -> V_58 >> V_18 ;
F_35 ( L_3 , V_52 -> V_55 ,
V_53 , V_53 << V_18 ) ;
for ( V_21 = V_11 ; V_21 > 0 ; V_21 -- ) {
F_36 ( V_50 , ( unsigned long ) V_60 , V_53 ) ;
V_53 += V_12 [ V_4 ] . V_67 ;
V_60 += V_15 * V_19 ;
}
V_12 [ V_4 ] . V_65 = ( V_12 [ V_4 ] . V_65 + 1 ) % V_24 ;
return 0 ;
}
int F_42 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_50 -> V_68 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_29 * * V_30 ;
int V_32 ;
F_27 ( & V_7 -> V_40 ) ;
V_32 = F_43 ( V_2 , & V_30 ) ;
if ( V_32 )
goto V_69;
if ( V_10 -> V_22 & V_23 )
V_32 = F_37 ( V_2 , V_50 , V_52 ) ;
else
V_32 = F_31 ( V_2 , V_50 , V_52 ) ;
V_69:
F_28 ( & V_7 -> V_40 ) ;
switch ( V_32 ) {
case 0 :
case - V_70 :
case - V_71 :
return V_72 ;
case - V_37 :
return V_73 ;
default:
return V_74 ;
}
}
int F_44 ( struct V_75 * V_25 , struct V_49 * V_50 )
{
int V_32 ;
V_32 = F_45 ( V_25 , V_50 ) ;
if ( V_32 ) {
F_46 ( L_5 , V_32 ) ;
return V_32 ;
}
return F_47 ( V_50 -> V_68 , V_50 ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_50 -> V_76 &= ~ V_77 ;
V_50 -> V_76 |= V_78 ;
if ( V_10 -> V_22 & V_35 ) {
V_50 -> V_79 = F_48 ( F_49 ( V_50 -> V_76 ) ) ;
} else if ( V_10 -> V_22 & V_36 ) {
V_50 -> V_79 = F_50 ( F_49 ( V_50 -> V_76 ) ) ;
} else {
if ( F_10 ( ! V_2 -> V_25 ) )
return - V_48 ;
F_51 ( V_50 -> V_80 ) ;
V_50 -> V_81 = 0 ;
V_50 -> V_80 = F_52 ( V_2 -> V_25 ) ;
V_50 -> V_79 = F_49 ( V_50 -> V_76 ) ;
}
return 0 ;
}
int F_53 ( struct V_82 * V_75 , struct V_28 * V_7 ,
struct V_83 * args )
{
union V_84 V_85 ;
args -> V_86 = F_54 ( args -> V_86 , args -> V_20 , args -> V_87 ) ;
args -> V_14 = F_55 ( args -> V_86 * args -> V_13 ) ;
V_85 = (union V_84 ) {
. V_88 = args -> V_14 ,
} ;
return F_56 ( V_7 , V_75 , V_85 ,
V_89 | V_35 , & args -> V_90 ) ;
}
int F_57 ( struct V_82 * V_75 , struct V_28 * V_7 ,
T_4 V_90 )
{
return F_58 ( V_75 , V_90 ) ;
}
int F_59 ( struct V_82 * V_75 , struct V_28 * V_7 ,
T_4 V_90 , T_5 * V_45 )
{
struct V_1 * V_2 ;
int V_32 = 0 ;
V_2 = F_60 ( V_7 , V_75 , V_90 ) ;
if ( V_2 == NULL ) {
V_32 = - V_91 ;
goto V_69;
}
* V_45 = F_26 ( V_2 ) ;
F_61 ( V_2 ) ;
V_69:
return V_32 ;
}
int F_62 ( struct V_1 * V_2 , T_4 V_92 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
int V_32 = 0 ;
if ( V_92 > V_31 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_6 , V_92 ) ;
return - V_48 ;
}
V_10 -> V_92 = V_92 ;
F_27 ( & V_2 -> V_7 -> V_40 ) ;
if ( V_10 -> V_66 ) {
struct V_29 * * V_30 ;
V_32 = F_43 ( V_2 , & V_30 ) ;
if ( V_32 )
goto V_69;
V_32 = F_40 ( V_10 -> V_66 , V_30 , V_31 , V_92 , true ) ;
if ( V_32 )
F_13 ( V_2 -> V_7 -> V_7 , L_7 , V_32 ) ;
}
V_69:
F_28 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
void F_32 ( struct V_1 * V_2 , int V_54 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) && V_10 -> V_33 [ V_54 ] ) {
F_20 ( V_7 -> V_7 , V_10 -> V_33 [ V_54 ] ,
V_15 , V_39 ) ;
V_10 -> V_33 [ V_54 ] = 0 ;
}
}
void F_63 ( struct V_1 * V_2 ,
enum V_93 V_94 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
struct V_29 * * V_30 = V_10 -> V_30 ;
bool V_95 = false ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
if ( ! V_10 -> V_33 [ V_21 ] ) {
V_10 -> V_33 [ V_21 ] = F_16 ( V_7 -> V_7 , V_30 [ V_21 ] , 0 ,
V_15 , V_39 ) ;
V_95 = true ;
}
}
if ( V_95 ) {
F_4 ( V_2 -> V_25 -> V_96 , 0 ,
F_24 ( V_2 ) , 1 ) ;
}
}
}
int F_64 ( struct V_1 * V_2 ,
T_3 * V_58 , bool V_97 )
{
struct V_98 * V_99 = V_2 -> V_7 -> V_100 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_27 ( & V_2 -> V_7 -> V_40 ) ;
if ( V_97 && F_7 ( V_2 ) && V_99 -> V_101 ) {
if ( V_10 -> V_102 == 0 ) {
struct V_29 * * V_30 ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_103 * V_66 ;
F_34 ( V_10 -> V_66 ) ;
V_32 = F_43 ( V_2 , & V_30 ) ;
if ( V_32 )
goto V_69;
if ( V_10 -> V_22 & V_23 ) {
V_66 = F_65 ( V_4 ,
V_10 -> V_20 ,
V_10 -> V_13 , 0 ) ;
} else {
V_66 = F_66 ( V_2 -> V_14 ) ;
}
if ( F_12 ( V_66 ) ) {
V_32 = F_14 ( V_66 ) ;
F_13 ( V_2 -> V_7 -> V_7 ,
L_8 , V_32 , V_4 ) ;
goto V_69;
}
V_32 = F_40 ( V_66 , V_30 , V_31 ,
V_10 -> V_92 , true ) ;
if ( V_32 ) {
F_67 ( V_66 ) ;
F_13 ( V_2 -> V_7 -> V_7 ,
L_9 , V_32 ) ;
goto V_69;
}
V_10 -> V_58 = F_68 ( V_66 ) ;
V_10 -> V_66 = V_66 ;
F_46 ( L_10 , V_10 -> V_58 ) ;
}
V_10 -> V_102 ++ ;
* V_58 = V_10 -> V_58 ;
} else if ( V_10 -> V_22 & V_57 ) {
* V_58 = V_10 -> V_58 ;
} else {
V_32 = - V_48 ;
goto V_69;
}
V_69:
F_28 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_27 ( & V_2 -> V_7 -> V_40 ) ;
if ( V_10 -> V_102 > 0 ) {
V_10 -> V_102 -- ;
if ( V_10 -> V_102 == 0 ) {
V_32 = F_70 ( V_10 -> V_66 ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 ,
L_11 , V_32 ) ;
goto V_69;
}
V_32 = F_67 ( V_10 -> V_66 ) ;
if ( V_32 ) {
F_13 ( V_2 -> V_7 -> V_7 ,
L_12 , V_32 ) ;
}
V_10 -> V_66 = NULL ;
}
}
V_69:
F_28 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_71 ( struct V_1 * V_2 , T_4 V_104 ,
int V_105 , int V_106 , T_3 * V_58 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = - V_48 ;
F_27 ( & V_2 -> V_7 -> V_40 ) ;
if ( ( V_10 -> V_102 > 0 ) && V_10 -> V_66 &&
( V_10 -> V_22 & V_23 ) ) {
* V_58 = F_72 ( V_10 -> V_66 , V_104 , V_105 , V_106 ) ;
V_32 = 0 ;
}
F_28 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_73 ( struct V_1 * V_2 , T_4 V_104 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = - V_48 ;
if ( V_10 -> V_22 & V_23 )
V_32 = F_74 ( F_6 ( V_10 -> V_22 ) , V_104 ) ;
return V_32 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_29 * * * V_30 )
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
int F_75 ( struct V_1 * V_2 , struct V_29 * * * V_30 ,
bool V_97 )
{
int V_32 ;
if ( ! V_97 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_30 )
return - V_37 ;
* V_30 = V_10 -> V_30 ;
return 0 ;
}
F_27 ( & V_2 -> V_7 -> V_40 ) ;
V_32 = F_43 ( V_2 , V_30 ) ;
F_28 ( & V_2 -> V_7 -> V_40 ) ;
return V_32 ;
}
int F_76 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_77 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_10 ( ! F_23 ( & V_2 -> V_7 -> V_40 ) ) ;
if ( ! V_10 -> V_60 ) {
struct V_29 * * V_30 ;
int V_32 = F_43 ( V_2 , & V_30 ) ;
if ( V_32 )
return F_78 ( V_32 ) ;
V_10 -> V_60 = F_79 ( V_30 , V_2 -> V_14 >> V_18 ,
V_107 , F_48 ( V_108 ) ) ;
}
return V_10 -> V_60 ;
}
void F_80 ( struct V_1 * V_2 , struct V_109 * V_19 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_5 V_16 = 0 ;
F_10 ( ! F_23 ( & V_7 -> V_40 ) ) ;
if ( V_2 -> V_41 . V_42 )
V_16 = ( T_5 ) V_2 -> V_41 . V_43 . V_44 ;
F_81 ( V_19 , L_14 ,
V_10 -> V_22 , V_2 -> V_110 , V_2 -> V_111 . V_111 . V_112 ,
V_16 , V_10 -> V_58 , V_10 -> V_102 ,
V_10 -> V_60 , V_10 -> V_92 ) ;
if ( V_10 -> V_22 & V_23 ) {
F_81 ( V_19 , L_15 , V_10 -> V_20 , V_10 -> V_13 ) ;
if ( V_10 -> V_66 ) {
struct V_113 * V_114 = & V_10 -> V_66 -> V_114 ;
F_81 ( V_19 , L_16 ,
V_114 -> V_115 . V_105 , V_114 -> V_115 . V_106 ,
V_114 -> V_116 . V_105 , V_114 -> V_116 . V_106 ) ;
}
} else {
F_81 ( V_19 , L_17 , V_2 -> V_14 ) ;
}
F_81 ( V_19 , L_18 ) ;
}
void F_82 ( struct V_117 * V_118 , struct V_109 * V_19 )
{
struct V_9 * V_10 ;
int V_119 = 0 ;
T_1 V_14 = 0 ;
F_83 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_120 ;
F_81 ( V_19 , L_19 ) ;
F_80 ( V_2 , V_19 ) ;
V_119 ++ ;
V_14 += V_2 -> V_14 ;
}
F_81 ( V_19 , L_20 , V_119 , V_14 ) ;
}
static inline bool F_84 ( struct V_121 * V_122 )
{
struct V_9 * V_10 = V_122 -> V_10 ;
if ( ( V_122 -> V_123 & V_124 ) &&
( V_10 -> V_125 -> V_126 < V_122 -> V_127 ) )
return true ;
if ( ( V_122 -> V_123 & V_128 ) &&
( V_10 -> V_125 -> V_129 < V_122 -> V_130 ) )
return true ;
return false ;
}
static void F_85 ( void )
{
struct V_121 * V_122 , * V_11 ;
F_86 (waiter, n, &waiters, list) {
if ( ! F_84 ( V_122 ) ) {
F_87 ( & V_122 -> V_118 ) ;
F_88 ( L_21 , V_122 ) ;
V_122 -> V_131 ( V_122 -> V_132 ) ;
F_21 ( V_122 ) ;
}
}
}
static inline int F_89 ( struct V_1 * V_2 ,
enum V_133 V_123 , bool V_134 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_90 ( & V_135 ) ;
if ( ! V_10 -> V_125 ) {
V_10 -> V_125 = F_17 ( sizeof( * V_10 -> V_125 ) , V_136 ) ;
if ( ! V_10 -> V_125 ) {
V_32 = - V_37 ;
goto V_137;
}
}
if ( V_134 ) {
if ( V_123 & V_124 )
V_10 -> V_125 -> V_138 ++ ;
if ( V_123 & V_128 )
V_10 -> V_125 -> V_139 ++ ;
} else {
if ( V_123 & V_124 )
V_10 -> V_125 -> V_126 ++ ;
if ( V_123 & V_128 )
V_10 -> V_125 -> V_129 ++ ;
F_85 () ;
}
V_137:
F_91 ( & V_135 ) ;
return V_32 ;
}
void F_92 ( void )
{
F_90 ( & V_135 ) ;
F_85 () ;
F_91 ( & V_135 ) ;
}
int F_93 ( struct V_1 * V_2 , enum V_133 V_123 )
{
return F_89 ( V_2 , V_123 , true ) ;
}
int F_94 ( struct V_1 * V_2 , enum V_133 V_123 )
{
return F_89 ( V_2 , V_123 , false ) ;
}
static void F_95 ( void * V_132 )
{
struct V_140 * * V_141 = V_132 ;
* V_141 = NULL ;
F_96 ( & V_142 ) ;
}
int F_97 ( struct V_1 * V_2 , enum V_133 V_123 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
if ( V_10 -> V_125 ) {
struct V_140 * V_141 = V_143 ;
struct V_121 * V_122 =
F_17 ( sizeof( * V_122 ) , V_34 ) ;
if ( ! V_122 )
return - V_37 ;
V_122 -> V_10 = V_10 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_127 = V_10 -> V_125 -> V_138 ;
V_122 -> V_130 = V_10 -> V_125 -> V_139 ;
V_122 -> V_131 = F_95 ;
V_122 -> V_132 = & V_141 ;
F_90 ( & V_135 ) ;
if ( F_84 ( V_122 ) ) {
F_88 ( L_22 , V_122 ) ;
F_98 ( & V_122 -> V_118 , & V_144 ) ;
F_91 ( & V_135 ) ;
V_32 = F_99 ( V_142 ,
( V_141 == NULL ) ) ;
F_90 ( & V_135 ) ;
if ( V_141 ) {
F_88 ( L_23 , V_122 ) ;
F_87 ( & V_122 -> V_118 ) ;
V_141 = NULL ;
} else {
V_122 = NULL ;
}
}
F_91 ( & V_135 ) ;
if ( V_122 )
F_21 ( V_122 ) ;
}
return V_32 ;
}
int F_100 ( struct V_1 * V_2 , enum V_133 V_123 ,
void (* F_101)( void * V_132 ) , void * V_132 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_125 ) {
struct V_121 * V_122 =
F_17 ( sizeof( * V_122 ) , V_136 ) ;
if ( ! V_122 )
return - V_37 ;
V_122 -> V_10 = V_10 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_127 = V_10 -> V_125 -> V_138 ;
V_122 -> V_130 = V_10 -> V_125 -> V_139 ;
V_122 -> V_131 = F_101 ;
V_122 -> V_132 = V_132 ;
F_90 ( & V_135 ) ;
if ( F_84 ( V_122 ) ) {
F_88 ( L_22 , V_122 ) ;
F_98 ( & V_122 -> V_118 , & V_144 ) ;
F_91 ( & V_135 ) ;
return 0 ;
}
F_91 ( & V_135 ) ;
}
F_101 ( V_132 ) ;
return 0 ;
}
int F_102 ( struct V_1 * V_2 , void * V_145 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_32 = 0 ;
F_90 ( & V_135 ) ;
if ( ( V_10 -> V_22 & V_146 ) && ! V_145 ) {
V_145 = F_17 ( sizeof( * V_10 -> V_125 ) , V_136 ) ;
if ( ! V_145 ) {
V_32 = - V_37 ;
goto V_137;
}
memcpy ( V_145 , V_10 -> V_125 , sizeof( * V_10 -> V_125 ) ) ;
V_10 -> V_22 &= ~ V_146 ;
V_10 -> V_125 = V_145 ;
} else if ( V_145 && ! ( V_10 -> V_22 & V_146 ) ) {
if ( V_10 -> V_125 ) {
memcpy ( V_145 , V_10 -> V_125 , sizeof( * V_10 -> V_125 ) ) ;
F_21 ( V_10 -> V_125 ) ;
}
V_10 -> V_22 |= V_146 ;
V_10 -> V_125 = V_145 ;
}
V_137:
F_91 ( & V_135 ) ;
return V_32 ;
}
int F_103 ( struct V_1 * V_2 )
{
return - V_48 ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_10 ( ! F_23 ( & V_7 -> V_40 ) ) ;
F_87 ( & V_10 -> V_147 ) ;
if ( V_2 -> V_41 . V_42 )
F_105 ( V_2 ) ;
F_10 ( V_10 -> V_102 > 0 ) ;
if ( ! ( V_10 -> V_22 & V_148 ) ) {
if ( V_10 -> V_30 )
F_19 ( V_2 ) ;
if ( ! F_7 ( V_2 ) ) {
F_106 ( V_7 -> V_7 , V_2 -> V_14 ,
V_10 -> V_60 , V_10 -> V_58 ) ;
} else if ( V_10 -> V_60 ) {
F_107 ( V_10 -> V_60 ) ;
}
}
if ( ! ( V_10 -> V_22 & V_146 ) )
F_21 ( V_10 -> V_125 ) ;
F_108 ( V_2 ) ;
F_21 ( V_2 ) ;
}
int F_56 ( struct V_28 * V_7 , struct V_82 * V_75 ,
union V_84 V_85 , T_4 V_22 , T_4 * V_90 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_109 ( V_7 , V_85 , V_22 ) ;
if ( ! V_2 )
return - V_37 ;
V_32 = F_110 ( V_75 , V_2 , V_90 ) ;
if ( V_32 ) {
F_108 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_32 ;
}
F_61 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_109 ( struct V_28 * V_7 ,
union V_84 V_85 , T_4 V_22 )
{
struct V_98 * V_99 = V_7 -> V_100 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
T_1 V_14 ;
int V_32 ;
if ( V_22 & V_23 ) {
if ( ! V_12 ) {
F_13 ( V_7 -> V_7 , L_24 ) ;
goto V_69;
}
V_22 &= ~ V_89 ;
V_22 &= ~ ( V_27 | V_36 ) ;
V_22 |= V_35 ;
F_111 ( F_6 ( V_22 ) ,
& V_85 . V_149 . V_20 , & V_85 . V_149 . V_13 ) ;
V_14 = F_112 ( F_6 ( V_22 ) ,
V_85 . V_149 . V_20 , V_85 . V_149 . V_13 ) ;
} else {
V_14 = F_55 ( V_85 . V_88 ) ;
}
V_10 = F_17 ( sizeof( * V_10 ) , V_34 ) ;
if ( ! V_10 ) {
F_13 ( V_7 -> V_7 , L_25 ) ;
goto V_69;
}
F_113 ( & V_10 -> V_147 , & V_99 -> V_150 ) ;
V_2 = & V_10 -> V_120 ;
if ( ( V_22 & V_89 ) && ! V_99 -> V_101 ) {
V_10 -> V_60 = F_114 ( V_7 -> V_7 , V_14 ,
& V_10 -> V_58 , V_34 ) ;
if ( V_10 -> V_60 )
V_22 |= V_57 ;
}
V_10 -> V_22 = V_22 ;
if ( V_22 & V_23 ) {
V_10 -> V_20 = V_85 . V_149 . V_20 ;
V_10 -> V_13 = V_85 . V_149 . V_13 ;
}
if ( V_22 & ( V_57 | V_148 ) )
V_32 = F_115 ( V_7 , V_2 , V_14 ) ;
else
V_32 = F_116 ( V_7 , V_2 , V_14 ) ;
if ( V_32 )
goto V_69;
return V_2 ;
V_69:
if ( V_2 )
F_104 ( V_2 ) ;
return NULL ;
}
void F_117 ( struct V_28 * V_7 )
{
struct V_98 * V_99 = V_7 -> V_100 ;
const enum V_3 V_151 [] = {
V_152 , V_153 , V_154
} ;
int V_21 , V_155 ;
if ( ! F_118 () ) {
F_119 ( V_7 -> V_7 , L_26 ) ;
return;
}
V_12 = F_17 ( 3 * sizeof( * V_12 ) , V_34 ) ;
if ( ! V_12 ) {
F_119 ( V_7 -> V_7 , L_27 ) ;
return;
}
for ( V_21 = 0 ; V_21 < F_41 ( V_151 ) ; V_21 ++ ) {
T_6 V_47 = 1 , V_46 = V_15 >> V_21 ;
F_111 ( V_151 [ V_21 ] , & V_46 , & V_47 ) ;
V_12 [ V_21 ] . V_13 = V_47 ;
V_12 [ V_21 ] . V_63 = F_120 ( V_47 ) ;
V_12 [ V_21 ] . V_67 = F_74 ( V_151 [ V_21 ] , 0 ) >> V_18 ;
V_12 [ V_21 ] . V_64 = F_120 ( ( V_15 / V_47 ) >> V_21 ) ;
for ( V_155 = 0 ; V_155 < V_24 ; V_155 ++ ) {
struct V_5 * V_6 = & V_12 [ V_21 ] . V_6 [ V_155 ] ;
struct V_103 * V_66 =
F_65 ( V_151 [ V_21 ] , V_46 , V_47 ,
V_15 ) ;
if ( F_12 ( V_66 ) ) {
F_13 ( V_7 -> V_7 ,
L_28 ,
V_21 , V_155 , F_14 ( V_66 ) ) ;
return;
}
V_6 -> V_58 = F_68 ( V_66 ) ;
V_6 -> V_66 = V_66 ;
F_46 ( L_29 , V_21 , V_155 , V_46 , V_47 ,
V_6 -> V_58 ,
V_12 [ V_21 ] . V_67 << V_18 ) ;
}
}
V_99 -> V_101 = true ;
}
void F_121 ( struct V_28 * V_7 )
{
F_21 ( V_12 ) ;
}
