static T_1 F_1 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_1 -> V_3 + V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_4 , int V_2 )
{
F_4 ( V_4 , V_1 -> V_3 + V_2 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_5 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_7 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_8 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
if ( ! ( F_1 ( V_1 , V_6 ) & V_9 ) )
F_3 ( V_1 , V_9 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 , V_6 ) & V_9 )
F_3 ( V_1 , V_9 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_10 , V_6 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_11 ) ;
}
static T_2 F_12 ( struct V_1 * V_1 , T_1 * V_12 , T_3 V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_12 [ V_14 ] = F_11 ( V_1 ) ;
return V_13 ;
}
static void F_13 ( struct V_1 * V_1 , T_1 V_15 )
{
F_3 ( V_1 , V_15 , V_11 ) ;
}
static T_2 F_14 ( struct V_1 * V_1 , T_1 * V_12 , T_3 V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_13 ( V_1 , V_12 [ V_14 ] ) ;
return V_13 ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_3 ( V_1 , V_16 , V_6 ) ;
}
static struct V_1 * F_16 ( struct V_17 * V_17 )
{
return F_17 ( V_17 -> V_18 , struct V_1 , V_19 ) ;
}
static int F_18 ( struct V_20 * V_20 , struct V_17 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
if ( F_19 ( & V_21 ) == 1 ) {
F_9 ( V_1 ) ;
return 0 ;
}
F_20 ( & V_21 ) ;
return - V_22 ;
}
static T_2 F_21 ( struct V_17 * V_17 , char T_4 * V_12 ,
T_3 V_23 , T_5 * V_24 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
T_1 V_25 ;
int V_26 = 1 ;
T_1 V_27 [ V_28 ] ;
T_2 V_29 = 0 ;
T_2 V_30 ;
if ( ! F_22 ( V_31 , V_12 , V_23 ) )
return - V_32 ;
F_23 ( * V_24 ) ;
if ( F_24 ( V_1 -> V_33 ,
F_1 ( V_1 , V_6 ) & V_8 ) )
return - V_34 ;
F_25 ( & V_1 -> V_35 ) ;
if ( F_26 ( ! ( F_1 ( V_1 , V_6 ) & V_8 ) ) ) {
V_29 = - V_36 ;
goto V_37;
}
F_8 ( V_1 ) ;
F_7 ( V_1 ) ;
F_5 ( V_1 ) ;
V_27 [ 0 ] = F_11 ( V_1 ) ;
V_25 = V_27 [ 0 ] ;
if ( V_25 + 1 > V_23 )
V_25 = V_23 - 1 ;
while ( V_25 ) {
V_30 = F_27 ( T_2 , V_25 , sizeof( V_27 ) - V_26 ) ;
F_12 ( V_1 , V_27 + V_26 , V_30 ) ;
if ( F_28 ( V_12 , V_27 , V_30 + V_26 ) ) {
V_29 = - V_32 ;
break;
}
V_25 -= V_30 ;
V_12 += V_30 + V_26 ;
V_29 += V_30 + V_26 ;
V_26 = 0 ;
}
F_9 ( V_1 ) ;
V_37:
F_29 ( & V_1 -> V_35 ) ;
return V_29 ;
}
static T_2 F_30 ( struct V_17 * V_17 , const char T_4 * V_12 ,
T_3 V_23 , T_5 * V_24 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
T_1 V_27 [ V_28 ] ;
T_2 V_29 = 0 ;
T_2 V_38 ;
if ( V_23 < 5 )
return - V_39 ;
if ( ! F_22 ( V_40 , V_12 , V_23 ) )
return - V_32 ;
F_23 ( * V_24 ) ;
if ( F_24 ( V_1 -> V_33 ,
! ( F_1 ( V_1 , V_6 ) &
( V_41 | V_10 ) ) ) )
return - V_34 ;
F_25 ( & V_1 -> V_35 ) ;
if ( F_26 ( F_1 ( V_1 , V_6 ) &
( V_41 | V_10 ) ) ) {
V_29 = - V_36 ;
goto V_37;
}
F_6 ( V_1 ) ;
while ( V_23 ) {
V_38 = F_27 ( T_2 , V_23 , sizeof( V_27 ) ) ;
if ( F_31 ( & V_27 , V_12 , V_38 ) ) {
V_29 = - V_32 ;
break;
}
F_14 ( V_1 , V_27 , V_38 ) ;
V_23 -= V_38 ;
V_12 += V_38 ;
V_29 += V_38 ;
}
F_10 ( V_1 ) ;
V_37:
F_29 ( & V_1 -> V_35 ) ;
return V_29 ;
}
static long F_32 ( struct V_17 * V_17 , unsigned int V_42 ,
unsigned long V_43 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
switch ( V_42 ) {
case V_44 :
F_15 ( V_1 ) ;
return 0 ;
}
return - V_39 ;
}
static int F_33 ( struct V_20 * V_20 , struct V_17 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
F_20 ( & V_21 ) ;
F_8 ( V_1 ) ;
return 0 ;
}
static unsigned int F_34 ( struct V_17 * V_17 , T_6 * V_45 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
unsigned int V_46 = 0 ;
T_1 V_47 ;
F_35 ( V_17 , & V_1 -> V_33 , V_45 ) ;
V_47 = F_1 ( V_1 , V_6 ) ;
if ( V_47 & V_8 )
V_46 |= V_48 ;
if ( ! ( V_47 & ( V_41 | V_10 ) ) )
V_46 |= V_49 ;
return V_46 ;
}
static void F_36 ( unsigned long V_4 )
{
struct V_1 * V_1 = ( void * ) V_4 ;
V_1 -> F_36 . V_50 += F_37 ( 500 ) ;
F_38 ( & V_1 -> V_33 ) ;
F_39 ( & V_1 -> F_36 ) ;
}
static T_7 F_40 ( int V_51 , void * V_52 )
{
struct V_1 * V_1 = V_52 ;
T_8 V_2 ;
V_2 = F_41 ( V_1 -> V_3 + V_53 ) ;
V_2 &= V_54 | V_55 ;
if ( ! V_2 )
return V_56 ;
F_42 ( V_2 , V_1 -> V_3 + V_53 ) ;
F_38 ( & V_1 -> V_33 ) ;
return V_57 ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_59 -> V_61 ;
T_8 V_2 ;
int V_62 ;
V_1 -> V_51 = F_44 ( V_59 , 0 ) ;
if ( ! V_1 -> V_51 )
return - V_63 ;
V_62 = F_45 ( V_61 , V_1 -> V_51 , F_40 , V_64 ,
V_65 , V_1 ) ;
if ( V_62 < 0 ) {
F_46 ( V_61 , L_1 , V_1 -> V_51 ) ;
V_1 -> V_51 = 0 ;
return V_62 ;
}
V_2 = F_41 ( V_1 -> V_3 + V_66 ) ;
V_2 |= V_67 | V_68 ;
F_42 ( V_2 , V_1 -> V_3 + V_66 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_59 )
{
struct V_1 * V_1 ;
struct V_60 * V_61 ;
struct V_69 * V_70 ;
int V_62 ;
if ( ! V_59 || ! V_59 -> V_61 . V_71 )
return - V_63 ;
V_61 = & V_59 -> V_61 ;
F_48 ( V_61 , L_2 ) ;
V_1 = F_49 ( V_61 , sizeof( * V_1 ) , V_72 ) ;
if ( ! V_1 )
return - V_73 ;
F_50 ( & V_59 -> V_61 , V_1 ) ;
V_70 = F_51 ( V_59 , V_74 , 0 ) ;
V_1 -> V_3 = F_52 ( & V_59 -> V_61 , V_70 ) ;
if ( F_53 ( V_1 -> V_3 ) )
return F_54 ( V_1 -> V_3 ) ;
F_55 ( & V_1 -> V_35 ) ;
F_56 ( & V_1 -> V_33 ) ;
V_1 -> V_19 . V_75 = V_76 ,
V_1 -> V_19 . V_77 = V_65 ,
V_1 -> V_19 . V_78 = & V_79 ,
V_1 -> V_19 . V_80 = V_61 ;
V_62 = F_57 ( & V_1 -> V_19 ) ;
if ( V_62 ) {
F_58 ( V_61 , L_3 ) ;
return V_62 ;
}
F_43 ( V_1 , V_59 ) ;
if ( V_1 -> V_51 ) {
F_48 ( V_61 , L_4 , V_1 -> V_51 ) ;
} else {
F_48 ( V_61 , L_5 ) ;
F_59 ( & V_1 -> F_36 , F_36 ,
( unsigned long ) V_1 ) ;
V_1 -> F_36 . V_50 = V_81 + F_37 ( 10 ) ;
F_39 ( & V_1 -> F_36 ) ;
}
F_42 ( ( V_82 << V_83 ) |
( V_84 << V_85 ) |
V_86 |
V_87 |
V_88 ,
V_1 -> V_3 + V_89 ) ;
F_9 ( V_1 ) ;
return 0 ;
}
static int F_60 ( struct V_58 * V_59 )
{
struct V_1 * V_1 = F_61 ( & V_59 -> V_61 ) ;
F_62 ( & V_1 -> V_19 ) ;
if ( ! V_1 -> V_51 )
F_63 ( & V_1 -> F_36 ) ;
return 0 ;
}
