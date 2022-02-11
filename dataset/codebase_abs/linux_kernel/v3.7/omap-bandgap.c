static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
if ( ! F_6 ( V_2 , V_11 ) )
return 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
V_10 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_10 &= ~ V_8 -> V_17 ;
V_10 |= ! V_6 << F_7 ( V_8 -> V_17 ) ;
F_3 ( V_2 , V_10 , V_8 -> V_16 ) ;
}
return 0 ;
}
static T_2 F_8 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_7 * V_8 ;
T_1 V_20 = 0 , V_21 = 0 , V_22 , V_10 ;
int V_9 ;
V_2 = V_19 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
V_20 = F_1 ( V_2 , V_8 -> V_23 ) ;
V_20 &= V_8 -> V_24 ;
V_21 = F_1 ( V_2 , V_8 -> V_23 ) ;
V_21 &= V_8 -> V_25 ;
if ( ! V_21 && ! V_20 )
continue;
V_10 = F_1 ( V_2 , V_8 -> V_26 ) ;
if ( V_20 ) {
V_10 &= ~ V_8 -> V_27 ;
V_10 |= V_8 -> V_28 ;
} else if ( V_21 ) {
V_10 &= ~ V_8 -> V_28 ;
V_10 |= V_8 -> V_27 ;
}
F_3 ( V_2 , V_10 , V_8 -> V_26 ) ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= V_8 -> V_29 ;
if ( V_2 -> V_12 -> V_30 )
V_2 -> V_12 -> V_30 ( V_2 , V_9 ) ;
}
return V_31 ;
}
static T_2 F_9 ( int V_18 , void * V_19 )
{
F_10 ( true ) ;
return V_31 ;
}
static
int F_11 ( struct V_1 * V_2 , int V_32 , int V_33 ,
int * V_34 )
{
struct V_35 * V_36 = V_2 -> V_12 -> V_14 [ V_32 ] . V_36 ;
if ( V_33 < V_36 -> V_37 || V_33 > V_36 -> V_38 )
return - V_39 ;
* V_34 = V_2 -> V_40 [ V_33 - V_36 -> V_37 ] ;
return 0 ;
}
static int F_12 ( long V_22 , struct V_1 * V_2 , int V_9 ,
int * V_41 )
{
struct V_35 * V_36 = V_2 -> V_12 -> V_14 [ V_9 ] . V_36 ;
int V_42 , V_43 , V_44 ;
V_43 = 0 ;
V_42 = V_36 -> V_38 - V_36 -> V_37 ;
V_44 = ( V_42 + V_43 ) / 2 ;
if ( V_22 < V_2 -> V_40 [ V_43 ] || V_22 > V_2 -> V_40 [ V_42 ] )
return - V_45 ;
while ( V_43 < V_42 ) {
if ( V_22 < V_2 -> V_40 [ V_44 ] )
V_42 = V_44 - 1 ;
else
V_43 = V_44 + 1 ;
V_44 = ( V_43 + V_42 ) / 2 ;
}
* V_41 = V_36 -> V_37 + V_43 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_32 ,
T_1 V_20 , T_1 V_21 )
{
struct V_7 * V_8 ;
T_1 V_22 , V_46 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= V_8 -> V_29 ;
V_46 = F_1 ( V_2 , V_8 -> V_26 ) ;
if ( V_22 < V_20 )
V_46 |= V_8 -> V_27 ;
else
V_46 &= ~ V_8 -> V_27 ;
if ( V_21 < V_22 )
V_46 |= V_8 -> V_28 ;
else
V_46 &= ~ V_8 -> V_28 ;
F_3 ( V_2 , V_46 , V_8 -> V_26 ) ;
return 0 ;
}
static
int F_14 ( int V_33 , int V_47 , struct V_1 * V_2 , int V_9 ,
T_1 * V_48 )
{
int V_22 , V_49 ;
V_49 = F_11 ( V_2 , V_9 , V_33 , & V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
V_22 += V_47 ;
return F_12 ( V_22 , V_2 , V_9 , V_48 ) ;
}
static
int F_15 ( struct V_1 * V_2 , int V_32 , int V_20 )
{
struct V_35 * V_36 = V_2 -> V_12 -> V_14 [ V_32 ] . V_36 ;
struct V_7 * V_8 ;
T_1 V_50 , V_46 ;
int V_51 , V_52 = 0 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_50 = F_1 ( V_2 , V_8 -> V_53 ) ;
V_51 = ( V_50 & V_8 -> V_54 ) >>
F_7 ( V_8 -> V_54 ) ;
if ( V_20 <= V_51 ) {
V_52 |= F_14 ( V_20 , - V_36 -> V_47 , V_2 , V_32 , & V_51 ) ;
V_46 = V_50 & ( ~ V_8 -> V_54 ) ;
V_46 |= V_51 << F_7 ( V_8 -> V_54 ) ;
F_3 ( V_2 , V_46 , V_8 -> V_53 ) ;
V_50 = V_46 ;
}
V_46 = V_50 & ~ V_8 -> V_55 ;
V_46 |= ( V_20 << F_7 ( V_8 -> V_55 ) ) ;
F_3 ( V_2 , V_46 , V_8 -> V_53 ) ;
if ( V_52 ) {
F_16 ( V_2 -> V_56 , L_1 ) ;
return - V_57 ;
}
return F_13 ( V_2 , V_32 , V_20 , V_51 ) ;
}
static
int F_17 ( struct V_1 * V_2 , int V_32 ,
int V_20 , int V_21 )
{
struct V_7 * V_8 ;
T_1 V_46 , V_50 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_50 = F_1 ( V_2 , V_8 -> V_53 ) ;
V_46 = V_50 & ~ V_8 -> V_54 ;
V_46 |= ( V_21 << F_7 ( V_8 -> V_54 ) ) ;
F_3 ( V_2 , V_46 , V_8 -> V_53 ) ;
V_50 = F_1 ( V_2 , V_8 -> V_53 ) ;
V_46 = V_50 & ~ V_8 -> V_55 ;
V_46 |= ( V_20 << F_7 ( V_8 -> V_55 ) ) ;
F_3 ( V_2 , V_46 , V_8 -> V_53 ) ;
V_46 = F_1 ( V_2 , V_8 -> V_26 ) ;
V_46 |= V_8 -> V_27 ;
V_46 |= V_8 -> V_28 ;
F_3 ( V_2 , V_46 , V_8 -> V_26 ) ;
return 0 ;
}
static
int F_18 ( struct V_1 * V_2 , int V_32 ,
int V_21 )
{
struct V_35 * V_36 = V_2 -> V_12 -> V_14 [ V_32 ] . V_36 ;
struct V_7 * V_8 ;
T_1 V_50 , V_46 ;
int V_58 , V_52 = 0 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_50 = F_1 ( V_2 , V_8 -> V_53 ) ;
V_58 = ( V_50 & V_8 -> V_55 ) >>
F_7 ( V_8 -> V_55 ) ;
if ( V_21 >= V_58 ) {
V_52 |= F_14 ( V_21 , V_36 -> V_47 , V_2 , V_32 , & V_58 ) ;
V_46 = V_50 & ( ~ V_8 -> V_55 ) ;
V_46 |= V_58 << F_7 ( V_8 -> V_55 ) ;
F_3 ( V_2 , V_46 , V_8 -> V_53 ) ;
V_50 = V_46 ;
}
V_46 = V_50 & ~ V_8 -> V_54 ;
V_46 |= ( V_21 << F_7 ( V_8 -> V_54 ) ) ;
F_3 ( V_2 , V_46 , V_8 -> V_53 ) ;
if ( V_52 ) {
F_16 ( V_2 -> V_56 , L_2 ) ;
return - V_57 ;
}
return F_13 ( V_2 , V_32 , V_58 , V_21 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_32 , int V_59 )
{
struct V_7 * V_8 ;
T_1 V_46 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_46 = F_1 ( V_2 , V_8 -> V_60 ) ;
V_46 &= ~ V_8 -> V_61 ;
V_46 |= V_59 << F_7 ( V_8 -> V_61 ) ;
F_3 ( V_2 , V_46 , V_8 -> V_60 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_32 , int V_62 )
{
struct V_7 * V_8 ;
T_1 V_46 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_46 = F_1 ( V_2 , V_8 -> V_60 ) ;
V_46 &= ~ V_8 -> V_63 ;
V_46 |= V_62 << F_7 ( V_8 -> V_63 ) ;
F_3 ( V_2 , V_46 , V_8 -> V_60 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_32 ,
T_1 V_64 )
{
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_5 = F_1 ( V_2 , V_8 -> V_65 ) ;
V_5 &= ~ V_8 -> V_66 ;
V_5 |= V_64 << F_7 ( V_8 -> V_66 ) ;
F_3 ( V_2 , V_5 , V_8 -> V_65 ) ;
return 0 ;
}
static inline int F_22 ( struct V_1 * V_2 , int V_32 )
{
if ( ! F_23 ( V_2 ) ) {
F_24 ( L_3 , V_67 ) ;
return - V_45 ;
}
if ( ! F_25 ( V_2 , V_32 ) ) {
F_16 ( V_2 -> V_56 , L_4 ,
V_67 , V_32 ) ;
return - V_39 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 , int V_32 ,
int * V_68 )
{
struct V_7 * V_8 ;
T_1 V_22 ;
int V_49 ;
V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( ! F_6 ( V_2 , V_69 ) )
return - V_70 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_53 ) ;
V_22 = ( V_22 & V_8 -> V_55 ) >>
F_7 ( V_8 -> V_55 ) ;
V_49 |= F_11 ( V_2 , V_32 , V_22 , & V_22 ) ;
if ( V_49 ) {
F_16 ( V_2 -> V_56 , L_5 ) ;
return - V_57 ;
}
* V_68 = V_22 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , int V_32 , int V_5 )
{
struct V_35 * V_36 ;
struct V_7 * V_8 ;
T_1 V_20 ;
int V_49 ;
V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( ! F_6 ( V_2 , V_69 ) )
return - V_70 ;
V_36 = V_2 -> V_12 -> V_14 [ V_32 ] . V_36 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
if ( V_5 < V_36 -> V_71 + V_36 -> V_47 )
return - V_45 ;
V_49 = F_12 ( V_5 , V_2 , V_32 , & V_20 ) ;
if ( V_49 < 0 )
return V_49 ;
F_28 ( & V_2 -> V_72 ) ;
F_15 ( V_2 , V_32 , V_20 ) ;
F_29 ( & V_2 -> V_72 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , int V_32 ,
int * V_73 )
{
struct V_7 * V_8 ;
T_1 V_22 ;
int V_49 ;
V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( ! F_6 ( V_2 , V_69 ) )
return - V_70 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_53 ) ;
V_22 = ( V_22 & V_8 -> V_54 )
>> F_7 ( V_8 -> V_54 ) ;
V_49 |= F_11 ( V_2 , V_32 , V_22 , & V_22 ) ;
if ( V_49 )
return - V_57 ;
* V_73 = V_22 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , int V_32 , int V_5 )
{
struct V_35 * V_36 ;
struct V_7 * V_8 ;
T_1 V_21 ;
int V_49 ;
V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( ! F_6 ( V_2 , V_69 ) )
return - V_70 ;
V_36 = V_2 -> V_12 -> V_14 [ V_32 ] . V_36 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
if ( V_5 > V_36 -> V_74 + V_36 -> V_47 )
return - V_45 ;
V_49 = F_12 ( V_5 , V_2 , V_32 , & V_21 ) ;
if ( V_49 < 0 )
return V_49 ;
F_28 ( & V_2 -> V_72 ) ;
F_18 ( V_2 , V_32 , V_21 ) ;
F_29 ( & V_2 -> V_72 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , int V_32 ,
int * V_75 )
{
struct V_7 * V_8 ;
T_1 time ;
int V_49 ;
V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( ! F_6 ( V_2 , V_76 ) )
return - V_70 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
time = F_1 ( V_2 , V_8 -> V_65 ) ;
if ( V_49 )
return V_49 ;
time = ( time & V_8 -> V_66 ) >> F_7 ( V_8 -> V_66 ) ;
time = time * 1000 / V_2 -> V_77 ;
* V_75 = time ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
int V_32 , T_1 V_75 )
{
int V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( ! F_6 ( V_2 , V_76 ) )
return - V_70 ;
V_75 = V_75 * V_2 -> V_77 / 1000 ;
F_28 ( & V_2 -> V_72 ) ;
F_21 ( V_2 , V_32 , V_75 ) ;
F_29 ( & V_2 -> V_72 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , int V_32 ,
int * V_78 )
{
struct V_7 * V_8 ;
T_1 V_22 ;
int V_49 ;
V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= V_8 -> V_29 ;
V_49 |= F_11 ( V_2 , V_32 , V_22 , & V_22 ) ;
if ( V_49 )
return - V_57 ;
* V_78 = V_22 ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_32 ,
void * V_19 )
{
int V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_12 -> V_14 [ V_32 ] . V_19 = V_19 ;
return 0 ;
}
void * F_36 ( struct V_1 * V_2 , int V_32 )
{
int V_49 = F_22 ( V_2 , V_32 ) ;
if ( V_49 )
return F_37 ( V_49 ) ;
return V_2 -> V_12 -> V_14 [ V_32 ] . V_19 ;
}
static int
F_38 ( struct V_1 * V_2 , int V_32 )
{
struct V_7 * V_8 ;
T_1 V_22 = 0 , V_64 = 1000 ;
V_8 = V_2 -> V_12 -> V_14 [ V_32 ] . V_15 ;
if ( F_6 ( V_2 , V_79 ) ) {
V_22 = F_1 ( V_2 , V_8 -> V_80 ) ;
V_22 &= ~ ( 1 << F_7 ( V_8 -> V_81 ) ) ;
F_3 ( V_2 , V_22 , V_8 -> V_80 ) ;
}
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 |= 1 << F_7 ( V_8 -> V_82 ) ;
F_3 ( V_2 , V_22 , V_8 -> V_16 ) ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= ( V_8 -> V_29 ) ;
while ( ( V_22 == 0 ) && -- V_64 ) {
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= ( V_8 -> V_29 ) ;
}
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= ~ ( 1 << F_7 ( V_8 -> V_82 ) ) ;
F_3 ( V_2 , V_22 , V_8 -> V_16 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_5 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
F_38 ( V_2 , V_9 ) ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
V_5 = F_1 ( V_2 , V_8 -> V_80 ) ;
V_5 |= 1 << F_7 ( V_8 -> V_81 ) ;
F_3 ( V_2 , V_5 , V_8 -> V_80 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
int V_85 = V_2 -> V_86 ;
int V_87 ;
V_87 = F_41 ( V_85 , L_6 ) ;
if ( V_87 < 0 ) {
F_16 ( V_2 -> V_56 ,
L_7 , 86 ) ;
return V_87 ;
}
V_87 = F_42 ( V_85 ) ;
if ( V_87 ) {
F_16 ( V_2 -> V_56 ,
L_8 , V_85 ) ;
return V_87 ;
}
V_87 = F_43 ( F_44 ( V_85 ) ,
F_9 ,
V_88 , L_6 ,
NULL ) ;
if ( V_87 ) {
F_45 ( V_85 ) ;
F_16 ( V_2 -> V_56 , L_9 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
int V_49 ;
V_2 -> V_18 = F_47 ( V_84 , 0 ) ;
if ( V_2 -> V_18 < 0 ) {
F_16 ( & V_84 -> V_56 , L_10 ) ;
return V_2 -> V_18 ;
}
V_49 = F_48 ( V_2 -> V_18 , NULL ,
F_8 ,
V_89 | V_90 ,
L_11 , V_2 ) ;
if ( V_49 ) {
F_16 ( & V_84 -> V_56 , L_12 ) ;
return V_49 ;
}
return 0 ;
}
static struct V_1 * F_49 ( struct V_83 * V_84 )
{
struct V_91 * V_92 = V_84 -> V_56 . V_93 ;
const struct V_94 * V_95 ;
struct V_1 * V_2 ;
struct V_96 * V_97 ;
T_1 V_98 ;
int V_9 ;
if ( ! V_92 ) {
F_16 ( & V_84 -> V_56 , L_13 ) ;
return F_37 ( - V_45 ) ;
}
V_2 = F_50 ( & V_84 -> V_56 , sizeof( struct V_1 ) ,
V_99 ) ;
if ( ! V_2 ) {
F_16 ( & V_84 -> V_56 , L_14 ) ;
return F_37 ( - V_100 ) ;
}
V_95 = F_51 ( V_101 , & V_84 -> V_56 ) ;
if ( V_95 )
V_2 -> V_12 = V_95 -> V_19 ;
V_9 = 0 ;
do {
void T_3 * V_102 ;
V_97 = F_52 ( V_84 , V_103 , V_9 ) ;
if ( ! V_97 )
break;
V_102 = F_53 ( & V_84 -> V_56 , V_97 ) ;
if ( V_9 == 0 )
V_2 -> V_4 = V_102 ;
if ( ! V_102 ) {
F_16 ( & V_84 -> V_56 ,
L_15 ,
V_9 , V_97 ) ;
return F_37 ( - V_104 ) ;
}
V_9 ++ ;
} while ( V_97 );
if ( F_6 ( V_2 , V_105 ) ) {
if ( F_54 ( V_92 , L_16 , & V_98 ) < 0 ) {
F_16 ( & V_84 -> V_56 , L_17 ) ;
return F_37 ( - V_45 ) ;
}
V_2 -> V_86 = V_98 ;
if ( ! F_55 ( V_2 -> V_86 ) ) {
F_16 ( & V_84 -> V_56 , L_18 ,
V_2 -> V_86 ) ;
return F_37 ( - V_45 ) ;
}
}
return V_2 ;
}
static
int T_4 F_56 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
int V_77 , V_49 = 0 , V_9 ;
V_2 = F_49 ( V_84 ) ;
if ( F_57 ( V_2 ) ) {
F_16 ( & V_84 -> V_56 , L_19 ) ;
return F_58 ( V_2 ) ;
}
V_2 -> V_56 = & V_84 -> V_56 ;
if ( F_6 ( V_2 , V_105 ) ) {
V_49 = F_40 ( V_2 , V_84 ) ;
if ( V_49 ) {
F_16 ( & V_84 -> V_56 ,
L_20 ) ;
return V_49 ;
}
}
V_2 -> V_106 = F_59 ( NULL , V_2 -> V_12 -> V_107 ) ;
V_49 = F_57 ( V_2 -> V_106 ) ;
if ( V_49 ) {
F_16 ( & V_84 -> V_56 , L_21 ) ;
goto V_108;
}
V_2 -> V_109 = F_59 ( NULL , V_2 -> V_12 -> V_110 ) ;
V_49 = F_57 ( V_2 -> V_109 ) ;
if ( V_49 ) {
F_16 ( & V_84 -> V_56 ,
L_22 ) ;
goto V_108;
}
V_2 -> V_40 = V_2 -> V_12 -> V_40 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
V_5 = F_1 ( V_2 , V_8 -> V_111 ) ;
if ( V_49 || ! V_5 )
F_60 ( & V_84 -> V_56 ,
L_23 ) ;
}
V_77 = F_61 ( V_2 -> V_109 ,
V_2 -> V_12 -> V_14 [ 0 ] . V_36 -> V_112 ) ;
if ( V_77 < V_2 -> V_12 -> V_14 [ 0 ] . V_36 -> V_113 ||
V_77 == 0xffffffff ) {
V_49 = - V_114 ;
F_16 ( & V_84 -> V_56 , L_24 , V_77 ) ;
goto V_115;
}
V_49 = F_62 ( V_2 -> V_109 , V_77 ) ;
if ( V_49 )
F_16 ( & V_84 -> V_56 , L_25 ) ;
V_2 -> V_77 = V_77 ;
F_63 ( V_2 -> V_106 ) ;
F_64 ( & V_2 -> V_72 ) ;
V_2 -> V_56 = & V_84 -> V_56 ;
F_65 ( V_84 , V_2 ) ;
F_5 ( V_2 , true ) ;
if ( F_6 ( V_2 , V_76 ) )
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ )
F_21 ( V_2 , V_9 , 1 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_35 * V_36 ;
V_36 = V_2 -> V_12 -> V_14 [ V_9 ] . V_36 ;
if ( F_6 ( V_2 , V_69 ) )
F_17 ( V_2 , V_9 ,
V_36 -> V_20 ,
V_36 -> V_21 ) ;
if ( F_6 ( V_2 , V_116 ) ) {
F_19 ( V_2 , V_9 ,
V_36 -> V_59 ) ;
F_20 ( V_2 , V_9 ,
V_36 -> V_62 ) ;
}
}
if ( F_6 ( V_2 , V_79 ) )
F_39 ( V_2 ) ;
if ( F_6 ( V_2 , V_76 ) )
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ )
F_21 ( V_2 , V_9 ,
V_2 -> V_77 / 4 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
char * V_117 ;
if ( V_2 -> V_12 -> V_14 [ V_9 ] . V_118 )
V_2 -> V_12 -> V_14 [ V_9 ] . V_118 ( V_2 , V_9 ) ;
V_117 = V_2 -> V_12 -> V_14 [ V_9 ] . V_117 ;
if ( V_2 -> V_12 -> V_119 )
V_2 -> V_12 -> V_119 ( V_2 , V_9 , V_117 ) ;
}
if ( F_6 ( V_2 , V_69 ) ) {
V_49 = F_46 ( V_2 , V_84 ) ;
if ( V_49 ) {
F_16 ( & V_84 -> V_56 , L_26 ) ;
V_9 = V_2 -> V_12 -> V_13 ;
goto V_120;
}
}
return 0 ;
V_120:
F_66 ( V_2 -> V_106 ) ;
V_115:
F_67 ( V_2 -> V_106 ) ;
F_67 ( V_2 -> V_109 ) ;
V_108:
if ( F_6 ( V_2 , V_105 ) ) {
F_68 ( F_44 ( V_2 -> V_86 ) , NULL ) ;
F_45 ( V_2 -> V_86 ) ;
}
return V_49 ;
}
static
int T_5 F_69 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_70 ( V_84 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
if ( V_2 -> V_12 -> V_14 [ V_9 ] . V_118 )
V_2 -> V_12 -> V_14 [ V_9 ] . F_71 ( V_2 , V_9 ) ;
if ( V_2 -> V_12 -> V_121 )
V_2 -> V_12 -> V_121 ( V_2 , V_9 ) ;
}
F_5 ( V_2 , false ) ;
F_66 ( V_2 -> V_106 ) ;
F_67 ( V_2 -> V_106 ) ;
F_67 ( V_2 -> V_109 ) ;
if ( F_6 ( V_2 , V_69 ) )
F_68 ( V_2 -> V_18 , V_2 ) ;
if ( F_6 ( V_2 , V_105 ) ) {
F_68 ( F_44 ( V_2 -> V_86 ) , NULL ) ;
F_45 ( V_2 -> V_86 ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_7 * V_8 ;
struct V_122 * V_123 ;
V_123 = & V_2 -> V_12 -> V_14 [ V_9 ] . V_124 ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
if ( F_6 ( V_2 , V_79 ) )
V_123 -> V_125 = F_1 ( V_2 ,
V_8 -> V_80 ) ;
if ( F_6 ( V_2 , V_76 ) )
V_123 -> V_126 = F_1 ( V_2 ,
V_8 -> V_65 ) ;
if ( F_6 ( V_2 , V_69 ) ) {
V_123 -> V_127 = F_1 ( V_2 ,
V_8 -> V_53 ) ;
V_123 -> V_128 = F_1 ( V_2 ,
V_8 -> V_26 ) ;
}
if ( F_6 ( V_2 , V_116 ) )
V_123 -> V_60 = F_1 ( V_2 ,
V_8 -> V_60 ) ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_9 ;
T_1 V_22 = 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_7 * V_8 ;
struct V_122 * V_123 ;
T_1 V_5 = 0 ;
V_123 = & V_2 -> V_12 -> V_14 [ V_9 ] . V_124 ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
if ( F_6 ( V_2 , V_76 ) )
V_5 = F_1 ( V_2 , V_8 -> V_65 ) ;
if ( V_5 == 0 ) {
if ( F_6 ( V_2 , V_116 ) )
F_3 ( V_2 ,
V_123 -> V_60 ,
V_8 -> V_60 ) ;
F_38 ( V_2 , V_9 ) ;
if ( F_6 ( V_2 , V_76 ) )
F_3 ( V_2 , V_123 -> V_126 ,
V_8 -> V_65 ) ;
if ( F_6 ( V_2 , V_79 ) )
F_3 ( V_2 , V_123 -> V_125 ,
V_8 -> V_80 ) ;
if ( F_6 ( V_2 , V_69 ) ) {
F_3 ( V_2 ,
V_123 -> V_127 ,
V_8 -> V_53 ) ;
F_3 ( V_2 , V_123 -> V_128 ,
V_8 -> V_26 ) ;
}
} else {
V_22 = F_1 ( V_2 ,
V_8 -> V_16 ) ;
V_22 &= ( V_8 -> V_29 ) ;
F_38 ( V_2 , V_9 ) ;
if ( V_22 == 0 && F_6 ( V_2 , V_69 ) ) {
V_22 = F_1 ( V_2 ,
V_8 -> V_26 ) ;
V_22 |= 1 << F_7 ( V_8 -> V_81 ) ;
F_3 ( V_2 , V_22 ,
V_8 -> V_26 ) ;
}
}
}
return 0 ;
}
static int F_74 ( struct V_129 * V_56 )
{
struct V_1 * V_2 = F_75 ( V_56 ) ;
int V_52 ;
V_52 = F_72 ( V_2 ) ;
F_5 ( V_2 , false ) ;
F_66 ( V_2 -> V_106 ) ;
return V_52 ;
}
static int F_76 ( struct V_129 * V_56 )
{
struct V_1 * V_2 = F_75 ( V_56 ) ;
F_63 ( V_2 -> V_106 ) ;
F_5 ( V_2 , true ) ;
return F_73 ( V_2 ) ;
}
