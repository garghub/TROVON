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
F_9 ( V_2 -> V_29 ,
L_1 ,
V_30 , V_2 -> V_12 -> V_14 [ V_9 ] . V_31 ,
V_20 , V_21 ) ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= V_8 -> V_32 ;
if ( V_2 -> V_12 -> V_33 )
V_2 -> V_12 -> V_33 ( V_2 , V_9 ) ;
}
return V_34 ;
}
static T_2 F_10 ( int V_18 , void * V_19 )
{
F_11 ( true ) ;
return V_34 ;
}
static
int F_12 ( struct V_1 * V_2 , int V_35 , int V_36 ,
int * V_37 )
{
struct V_38 * V_39 = V_2 -> V_12 -> V_14 [ V_35 ] . V_39 ;
if ( V_36 < V_39 -> V_40 || V_36 > V_39 -> V_41 )
return - V_42 ;
* V_37 = V_2 -> V_43 [ V_36 - V_39 -> V_40 ] ;
return 0 ;
}
static int F_13 ( long V_22 , struct V_1 * V_2 , int V_9 ,
int * V_44 )
{
struct V_38 * V_39 = V_2 -> V_12 -> V_14 [ V_9 ] . V_39 ;
int V_45 , V_46 , V_47 ;
V_46 = 0 ;
V_45 = V_39 -> V_41 - V_39 -> V_40 ;
V_47 = ( V_45 + V_46 ) / 2 ;
if ( V_22 < V_2 -> V_43 [ V_46 ] || V_22 > V_2 -> V_43 [ V_45 ] )
return - V_48 ;
while ( V_46 < V_45 ) {
if ( V_22 < V_2 -> V_43 [ V_47 ] )
V_45 = V_47 - 1 ;
else
V_46 = V_47 + 1 ;
V_47 = ( V_46 + V_45 ) / 2 ;
}
* V_44 = V_39 -> V_40 + V_46 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_35 ,
T_1 V_20 , T_1 V_21 )
{
struct V_7 * V_8 ;
T_1 V_22 , V_49 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= V_8 -> V_32 ;
V_49 = F_1 ( V_2 , V_8 -> V_26 ) ;
if ( V_22 < V_20 )
V_49 |= V_8 -> V_27 ;
else
V_49 &= ~ V_8 -> V_27 ;
if ( V_21 < V_22 )
V_49 |= V_8 -> V_28 ;
else
V_49 &= ~ V_8 -> V_28 ;
F_3 ( V_2 , V_49 , V_8 -> V_26 ) ;
return 0 ;
}
static
int F_15 ( int V_36 , int V_50 , struct V_1 * V_2 , int V_9 ,
T_1 * V_51 )
{
int V_22 , V_52 ;
V_52 = F_12 ( V_2 , V_9 , V_36 , & V_22 ) ;
if ( V_52 < 0 )
return V_52 ;
V_22 += V_50 ;
return F_13 ( V_22 , V_2 , V_9 , V_51 ) ;
}
static
int F_16 ( struct V_1 * V_2 , int V_35 , int V_20 )
{
struct V_38 * V_39 = V_2 -> V_12 -> V_14 [ V_35 ] . V_39 ;
struct V_7 * V_8 ;
T_1 V_53 , V_49 ;
int V_54 , V_55 = 0 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_53 = F_1 ( V_2 , V_8 -> V_56 ) ;
V_54 = ( V_53 & V_8 -> V_57 ) >>
F_7 ( V_8 -> V_57 ) ;
if ( V_20 <= V_54 ) {
V_55 |= F_15 ( V_20 , - V_39 -> V_50 , V_2 , V_35 , & V_54 ) ;
V_49 = V_53 & ( ~ V_8 -> V_57 ) ;
V_49 |= V_54 << F_7 ( V_8 -> V_57 ) ;
F_3 ( V_2 , V_49 , V_8 -> V_56 ) ;
V_53 = V_49 ;
}
V_49 = V_53 & ~ V_8 -> V_58 ;
V_49 |= ( V_20 << F_7 ( V_8 -> V_58 ) ) ;
F_3 ( V_2 , V_49 , V_8 -> V_56 ) ;
if ( V_55 ) {
F_17 ( V_2 -> V_29 , L_2 ) ;
return - V_59 ;
}
return F_14 ( V_2 , V_35 , V_20 , V_54 ) ;
}
static
int F_18 ( struct V_1 * V_2 , int V_35 ,
int V_20 , int V_21 )
{
struct V_7 * V_8 ;
T_1 V_49 , V_53 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_53 = F_1 ( V_2 , V_8 -> V_56 ) ;
V_49 = V_53 & ~ V_8 -> V_57 ;
V_49 |= ( V_21 << F_7 ( V_8 -> V_57 ) ) ;
F_3 ( V_2 , V_49 , V_8 -> V_56 ) ;
V_53 = F_1 ( V_2 , V_8 -> V_56 ) ;
V_49 = V_53 & ~ V_8 -> V_58 ;
V_49 |= ( V_20 << F_7 ( V_8 -> V_58 ) ) ;
F_3 ( V_2 , V_49 , V_8 -> V_56 ) ;
V_49 = F_1 ( V_2 , V_8 -> V_26 ) ;
V_49 |= V_8 -> V_27 ;
V_49 |= V_8 -> V_28 ;
F_3 ( V_2 , V_49 , V_8 -> V_26 ) ;
return 0 ;
}
static
int F_19 ( struct V_1 * V_2 , int V_35 ,
int V_21 )
{
struct V_38 * V_39 = V_2 -> V_12 -> V_14 [ V_35 ] . V_39 ;
struct V_7 * V_8 ;
T_1 V_53 , V_49 ;
int V_60 , V_55 = 0 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_53 = F_1 ( V_2 , V_8 -> V_56 ) ;
V_60 = ( V_53 & V_8 -> V_58 ) >>
F_7 ( V_8 -> V_58 ) ;
if ( V_21 >= V_60 ) {
V_55 |= F_15 ( V_21 , V_39 -> V_50 , V_2 , V_35 , & V_60 ) ;
V_49 = V_53 & ( ~ V_8 -> V_58 ) ;
V_49 |= V_60 << F_7 ( V_8 -> V_58 ) ;
F_3 ( V_2 , V_49 , V_8 -> V_56 ) ;
V_53 = V_49 ;
}
V_49 = V_53 & ~ V_8 -> V_57 ;
V_49 |= ( V_21 << F_7 ( V_8 -> V_57 ) ) ;
F_3 ( V_2 , V_49 , V_8 -> V_56 ) ;
if ( V_55 ) {
F_17 ( V_2 -> V_29 , L_3 ) ;
return - V_59 ;
}
return F_14 ( V_2 , V_35 , V_60 , V_21 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_35 , int V_61 )
{
struct V_7 * V_8 ;
T_1 V_49 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_49 = F_1 ( V_2 , V_8 -> V_62 ) ;
V_49 &= ~ V_8 -> V_63 ;
V_49 |= V_61 << F_7 ( V_8 -> V_63 ) ;
F_3 ( V_2 , V_49 , V_8 -> V_62 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_35 , int V_64 )
{
struct V_7 * V_8 ;
T_1 V_49 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_49 = F_1 ( V_2 , V_8 -> V_62 ) ;
V_49 &= ~ V_8 -> V_65 ;
V_49 |= V_64 << F_7 ( V_8 -> V_65 ) ;
F_3 ( V_2 , V_49 , V_8 -> V_62 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_35 ,
T_1 V_66 )
{
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_5 = F_1 ( V_2 , V_8 -> V_67 ) ;
V_5 &= ~ V_8 -> V_68 ;
V_5 |= V_66 << F_7 ( V_8 -> V_68 ) ;
F_3 ( V_2 , V_5 , V_8 -> V_67 ) ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , int V_35 )
{
if ( ! F_24 ( V_2 ) ) {
F_25 ( L_4 , V_30 ) ;
return - V_48 ;
}
if ( ! F_26 ( V_2 , V_35 ) ) {
F_17 ( V_2 -> V_29 , L_5 ,
V_30 , V_35 ) ;
return - V_42 ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 , int V_35 ,
int * V_69 )
{
struct V_7 * V_8 ;
T_1 V_22 ;
int V_52 ;
V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
if ( ! F_6 ( V_2 , V_70 ) )
return - V_71 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_56 ) ;
V_22 = ( V_22 & V_8 -> V_58 ) >>
F_7 ( V_8 -> V_58 ) ;
V_52 |= F_12 ( V_2 , V_35 , V_22 , & V_22 ) ;
if ( V_52 ) {
F_17 ( V_2 -> V_29 , L_6 ) ;
return - V_59 ;
}
* V_69 = V_22 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , int V_35 , int V_5 )
{
struct V_38 * V_39 ;
struct V_7 * V_8 ;
T_1 V_20 ;
int V_52 ;
V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
if ( ! F_6 ( V_2 , V_70 ) )
return - V_71 ;
V_39 = V_2 -> V_12 -> V_14 [ V_35 ] . V_39 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
if ( V_5 < V_39 -> V_72 + V_39 -> V_50 )
return - V_48 ;
V_52 = F_13 ( V_5 , V_2 , V_35 , & V_20 ) ;
if ( V_52 < 0 )
return V_52 ;
F_29 ( & V_2 -> V_73 ) ;
F_16 ( V_2 , V_35 , V_20 ) ;
F_30 ( & V_2 -> V_73 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , int V_35 ,
int * V_74 )
{
struct V_7 * V_8 ;
T_1 V_22 ;
int V_52 ;
V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
if ( ! F_6 ( V_2 , V_70 ) )
return - V_71 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_56 ) ;
V_22 = ( V_22 & V_8 -> V_57 )
>> F_7 ( V_8 -> V_57 ) ;
V_52 |= F_12 ( V_2 , V_35 , V_22 , & V_22 ) ;
if ( V_52 )
return - V_59 ;
* V_74 = V_22 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , int V_35 , int V_5 )
{
struct V_38 * V_39 ;
struct V_7 * V_8 ;
T_1 V_21 ;
int V_52 ;
V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
if ( ! F_6 ( V_2 , V_70 ) )
return - V_71 ;
V_39 = V_2 -> V_12 -> V_14 [ V_35 ] . V_39 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
if ( V_5 > V_39 -> V_75 + V_39 -> V_50 )
return - V_48 ;
V_52 = F_13 ( V_5 , V_2 , V_35 , & V_21 ) ;
if ( V_52 < 0 )
return V_52 ;
F_29 ( & V_2 -> V_73 ) ;
F_19 ( V_2 , V_35 , V_21 ) ;
F_30 ( & V_2 -> V_73 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , int V_35 ,
int * V_76 )
{
struct V_7 * V_8 ;
T_1 time ;
int V_52 ;
V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
if ( ! F_6 ( V_2 , V_77 ) )
return - V_71 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
time = F_1 ( V_2 , V_8 -> V_67 ) ;
time = ( time & V_8 -> V_68 ) >> F_7 ( V_8 -> V_68 ) ;
time = time * 1000 / V_2 -> V_78 ;
* V_76 = time ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
int V_35 , T_1 V_76 )
{
int V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
if ( ! F_6 ( V_2 , V_77 ) )
return - V_71 ;
V_76 = V_76 * V_2 -> V_78 / 1000 ;
F_29 ( & V_2 -> V_73 ) ;
F_22 ( V_2 , V_35 , V_76 ) ;
F_30 ( & V_2 -> V_73 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_35 ,
int * V_79 )
{
struct V_7 * V_8 ;
T_1 V_22 ;
int V_52 ;
V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= V_8 -> V_32 ;
V_52 |= F_12 ( V_2 , V_35 , V_22 , & V_22 ) ;
if ( V_52 )
return - V_59 ;
* V_79 = V_22 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , int V_35 ,
void * V_19 )
{
int V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return V_52 ;
V_2 -> V_12 -> V_14 [ V_35 ] . V_19 = V_19 ;
return 0 ;
}
void * F_37 ( struct V_1 * V_2 , int V_35 )
{
int V_52 = F_23 ( V_2 , V_35 ) ;
if ( V_52 )
return F_38 ( V_52 ) ;
return V_2 -> V_12 -> V_14 [ V_35 ] . V_19 ;
}
static int
F_39 ( struct V_1 * V_2 , int V_35 )
{
struct V_7 * V_8 ;
T_1 V_22 = 0 , V_66 = 1000 ;
V_8 = V_2 -> V_12 -> V_14 [ V_35 ] . V_15 ;
if ( F_6 ( V_2 , V_80 ) ) {
V_22 = F_1 ( V_2 , V_8 -> V_81 ) ;
V_22 &= ~ ( 1 << F_7 ( V_8 -> V_82 ) ) ;
F_3 ( V_2 , V_22 , V_8 -> V_81 ) ;
}
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 |= 1 << F_7 ( V_8 -> V_83 ) ;
F_3 ( V_2 , V_22 , V_8 -> V_16 ) ;
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= ( V_8 -> V_32 ) ;
while ( ( V_22 == 0 ) && -- V_66 ) {
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= ( V_8 -> V_32 ) ;
}
V_22 = F_1 ( V_2 , V_8 -> V_16 ) ;
V_22 &= ~ ( 1 << F_7 ( V_8 -> V_83 ) ) ;
F_3 ( V_2 , V_22 , V_8 -> V_16 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_5 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
F_39 ( V_2 , V_9 ) ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
V_5 = F_1 ( V_2 , V_8 -> V_81 ) ;
V_5 |= 1 << F_7 ( V_8 -> V_82 ) ;
F_3 ( V_2 , V_5 , V_8 -> V_81 ) ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
int V_86 = V_2 -> V_87 ;
int V_88 ;
V_88 = F_42 ( V_86 , L_7 ) ;
if ( V_88 < 0 ) {
F_17 ( V_2 -> V_29 ,
L_8 , 86 ) ;
return V_88 ;
}
V_88 = F_43 ( V_86 ) ;
if ( V_88 ) {
F_17 ( V_2 -> V_29 ,
L_9 , V_86 ) ;
return V_88 ;
}
V_88 = F_44 ( F_45 ( V_86 ) ,
F_10 ,
V_89 , L_7 ,
NULL ) ;
if ( V_88 ) {
F_46 ( V_86 ) ;
F_17 ( V_2 -> V_29 , L_10 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
int V_52 ;
V_2 -> V_18 = F_48 ( V_85 , 0 ) ;
if ( V_2 -> V_18 < 0 ) {
F_17 ( & V_85 -> V_29 , L_11 ) ;
return V_2 -> V_18 ;
}
V_52 = F_49 ( V_2 -> V_18 , NULL ,
F_8 ,
V_90 | V_91 ,
L_12 , V_2 ) ;
if ( V_52 ) {
F_17 ( & V_85 -> V_29 , L_13 ) ;
return V_52 ;
}
return 0 ;
}
static struct V_1 * F_50 ( struct V_84 * V_85 )
{
struct V_92 * V_93 = V_85 -> V_29 . V_94 ;
const struct V_95 * V_96 ;
struct V_1 * V_2 ;
struct V_97 * V_98 ;
T_1 V_99 ;
int V_9 ;
if ( ! V_93 ) {
F_17 ( & V_85 -> V_29 , L_14 ) ;
return F_38 ( - V_48 ) ;
}
V_2 = F_51 ( & V_85 -> V_29 , sizeof( struct V_1 ) ,
V_100 ) ;
if ( ! V_2 ) {
F_17 ( & V_85 -> V_29 , L_15 ) ;
return F_38 ( - V_101 ) ;
}
V_96 = F_52 ( V_102 , & V_85 -> V_29 ) ;
if ( V_96 )
V_2 -> V_12 = V_96 -> V_19 ;
V_9 = 0 ;
do {
void T_3 * V_103 ;
V_98 = F_53 ( V_85 , V_104 , V_9 ) ;
if ( ! V_98 )
break;
V_103 = F_54 ( & V_85 -> V_29 , V_98 ) ;
if ( V_9 == 0 )
V_2 -> V_4 = V_103 ;
if ( F_55 ( V_103 ) )
return F_56 ( V_103 ) ;
V_9 ++ ;
} while ( V_98 );
if ( F_6 ( V_2 , V_105 ) ) {
if ( F_57 ( V_93 , L_16 , & V_99 ) < 0 ) {
F_17 ( & V_85 -> V_29 , L_17 ) ;
return F_38 ( - V_48 ) ;
}
V_2 -> V_87 = V_99 ;
if ( ! F_58 ( V_2 -> V_87 ) ) {
F_17 ( & V_85 -> V_29 , L_18 ,
V_2 -> V_87 ) ;
return F_38 ( - V_48 ) ;
}
}
return V_2 ;
}
static
int F_59 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_78 , V_52 = 0 , V_9 ;
V_2 = F_50 ( V_85 ) ;
if ( F_60 ( V_2 ) ) {
F_17 ( & V_85 -> V_29 , L_19 ) ;
return F_61 ( V_2 ) ;
}
V_2 -> V_29 = & V_85 -> V_29 ;
if ( F_6 ( V_2 , V_105 ) ) {
V_52 = F_41 ( V_2 , V_85 ) ;
if ( V_52 ) {
F_17 ( & V_85 -> V_29 ,
L_20 ) ;
return V_52 ;
}
}
V_2 -> V_106 = F_62 ( NULL , V_2 -> V_12 -> V_107 ) ;
V_52 = F_60 ( V_2 -> V_106 ) ;
if ( V_52 ) {
F_17 ( & V_85 -> V_29 , L_21 ) ;
goto V_108;
}
V_2 -> V_109 = F_62 ( NULL , V_2 -> V_12 -> V_110 ) ;
V_52 = F_60 ( V_2 -> V_109 ) ;
if ( V_52 ) {
F_17 ( & V_85 -> V_29 ,
L_22 ) ;
goto V_108;
}
V_2 -> V_43 = V_2 -> V_12 -> V_43 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
V_5 = F_1 ( V_2 , V_8 -> V_111 ) ;
if ( V_52 || ! V_5 )
F_63 ( & V_85 -> V_29 ,
L_23 ) ;
}
V_78 = F_64 ( V_2 -> V_109 ,
V_2 -> V_12 -> V_14 [ 0 ] . V_39 -> V_112 ) ;
if ( V_78 < V_2 -> V_12 -> V_14 [ 0 ] . V_39 -> V_113 ||
V_78 == 0xffffffff ) {
V_52 = - V_114 ;
F_17 ( & V_85 -> V_29 , L_24 , V_78 ) ;
goto V_115;
}
V_52 = F_65 ( V_2 -> V_109 , V_78 ) ;
if ( V_52 )
F_17 ( & V_85 -> V_29 , L_25 ) ;
V_2 -> V_78 = V_78 ;
F_66 ( V_2 -> V_106 ) ;
F_67 ( & V_2 -> V_73 ) ;
V_2 -> V_29 = & V_85 -> V_29 ;
F_68 ( V_85 , V_2 ) ;
F_5 ( V_2 , true ) ;
if ( F_6 ( V_2 , V_77 ) )
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ )
F_22 ( V_2 , V_9 , 1 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_38 * V_39 ;
V_39 = V_2 -> V_12 -> V_14 [ V_9 ] . V_39 ;
if ( F_6 ( V_2 , V_70 ) )
F_18 ( V_2 , V_9 ,
V_39 -> V_20 ,
V_39 -> V_21 ) ;
if ( F_6 ( V_2 , V_116 ) ) {
F_20 ( V_2 , V_9 ,
V_39 -> V_61 ) ;
F_21 ( V_2 , V_9 ,
V_39 -> V_64 ) ;
}
}
if ( F_6 ( V_2 , V_80 ) )
F_40 ( V_2 ) ;
if ( F_6 ( V_2 , V_77 ) )
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ )
F_22 ( V_2 , V_9 ,
V_2 -> V_78 / 4 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
char * V_31 ;
if ( V_2 -> V_12 -> V_14 [ V_9 ] . V_117 )
V_2 -> V_12 -> V_14 [ V_9 ] . V_117 ( V_2 , V_9 ) ;
V_31 = V_2 -> V_12 -> V_14 [ V_9 ] . V_31 ;
if ( V_2 -> V_12 -> V_118 )
V_2 -> V_12 -> V_118 ( V_2 , V_9 , V_31 ) ;
}
if ( F_6 ( V_2 , V_70 ) ) {
V_52 = F_47 ( V_2 , V_85 ) ;
if ( V_52 ) {
F_17 ( & V_85 -> V_29 , L_26 ) ;
V_9 = V_2 -> V_12 -> V_13 ;
goto V_119;
}
}
return 0 ;
V_119:
F_69 ( V_2 -> V_106 ) ;
V_115:
F_70 ( V_2 -> V_106 ) ;
F_70 ( V_2 -> V_109 ) ;
V_108:
if ( F_6 ( V_2 , V_105 ) ) {
F_71 ( F_45 ( V_2 -> V_87 ) , NULL ) ;
F_46 ( V_2 -> V_87 ) ;
}
return V_52 ;
}
static
int F_72 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_73 ( V_85 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
if ( V_2 -> V_12 -> V_14 [ V_9 ] . V_117 )
V_2 -> V_12 -> V_14 [ V_9 ] . F_74 ( V_2 , V_9 ) ;
if ( V_2 -> V_12 -> V_120 )
V_2 -> V_12 -> V_120 ( V_2 , V_9 ) ;
}
F_5 ( V_2 , false ) ;
F_69 ( V_2 -> V_106 ) ;
F_70 ( V_2 -> V_106 ) ;
F_70 ( V_2 -> V_109 ) ;
if ( F_6 ( V_2 , V_70 ) )
F_71 ( V_2 -> V_18 , V_2 ) ;
if ( F_6 ( V_2 , V_105 ) ) {
F_71 ( F_45 ( V_2 -> V_87 ) , NULL ) ;
F_46 ( V_2 -> V_87 ) ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_7 * V_8 ;
struct V_121 * V_122 ;
V_122 = & V_2 -> V_12 -> V_14 [ V_9 ] . V_123 ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
if ( F_6 ( V_2 , V_80 ) )
V_122 -> V_124 = F_1 ( V_2 ,
V_8 -> V_81 ) ;
if ( F_6 ( V_2 , V_77 ) )
V_122 -> V_125 = F_1 ( V_2 ,
V_8 -> V_67 ) ;
if ( F_6 ( V_2 , V_70 ) ) {
V_122 -> V_126 = F_1 ( V_2 ,
V_8 -> V_56 ) ;
V_122 -> V_127 = F_1 ( V_2 ,
V_8 -> V_26 ) ;
}
if ( F_6 ( V_2 , V_116 ) )
V_122 -> V_62 = F_1 ( V_2 ,
V_8 -> V_62 ) ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_7 * V_8 ;
struct V_121 * V_122 ;
T_1 V_5 = 0 ;
V_122 = & V_2 -> V_12 -> V_14 [ V_9 ] . V_123 ;
V_8 = V_2 -> V_12 -> V_14 [ V_9 ] . V_15 ;
if ( F_6 ( V_2 , V_77 ) )
V_5 = F_1 ( V_2 , V_8 -> V_67 ) ;
if ( F_6 ( V_2 , V_116 ) )
F_3 ( V_2 ,
V_122 -> V_62 ,
V_8 -> V_62 ) ;
F_39 ( V_2 , V_9 ) ;
if ( F_6 ( V_2 , V_77 ) )
F_3 ( V_2 , V_122 -> V_125 ,
V_8 -> V_67 ) ;
if ( F_6 ( V_2 , V_80 ) )
F_3 ( V_2 , V_122 -> V_124 ,
V_8 -> V_81 ) ;
if ( F_6 ( V_2 , V_70 ) ) {
F_3 ( V_2 ,
V_122 -> V_126 ,
V_8 -> V_56 ) ;
F_3 ( V_2 , V_122 -> V_127 ,
V_8 -> V_26 ) ;
}
}
return 0 ;
}
static int F_77 ( struct V_128 * V_29 )
{
struct V_1 * V_2 = F_78 ( V_29 ) ;
int V_55 ;
V_55 = F_75 ( V_2 ) ;
F_5 ( V_2 , false ) ;
F_69 ( V_2 -> V_106 ) ;
return V_55 ;
}
static int F_79 ( struct V_128 * V_29 )
{
struct V_1 * V_2 = F_78 ( V_29 ) ;
F_66 ( V_2 -> V_106 ) ;
F_5 ( V_2 , true ) ;
return F_76 ( V_2 ) ;
}
