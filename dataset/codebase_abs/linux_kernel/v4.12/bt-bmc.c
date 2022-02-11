static T_1 F_1 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_3 = 0 ;
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 , V_1 -> V_6 + V_2 , & V_3 ) ;
F_3 ( V_4 != 0 , L_1 , V_4 ) ;
return V_4 == 0 ? ( T_1 ) V_3 : 0 ;
}
static void F_4 ( struct V_1 * V_1 , T_1 V_7 , int V_2 )
{
int V_4 ;
V_4 = F_5 ( V_1 -> V_5 , V_1 -> V_6 + V_2 , V_7 ) ;
F_3 ( V_4 != 0 , L_2 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_4 ( V_1 , V_8 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
F_4 ( V_1 , V_10 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_4 ( V_1 , V_11 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
if ( ! ( F_1 ( V_1 , V_9 ) & V_12 ) )
F_4 ( V_1 , V_12 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 , V_9 ) & V_12 )
F_4 ( V_1 , V_12 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_4 ( V_1 , V_13 , V_9 ) ;
}
static T_1 F_12 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_14 ) ;
}
static T_3 F_13 ( struct V_1 * V_1 , T_1 * V_15 , T_4 V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
V_15 [ V_17 ] = F_12 ( V_1 ) ;
return V_16 ;
}
static void F_14 ( struct V_1 * V_1 , T_1 V_18 )
{
F_4 ( V_1 , V_18 , V_14 ) ;
}
static T_3 F_15 ( struct V_1 * V_1 , T_1 * V_15 , T_4 V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_14 ( V_1 , V_15 [ V_17 ] ) ;
return V_16 ;
}
static void F_16 ( struct V_1 * V_1 )
{
F_4 ( V_1 , V_19 , V_9 ) ;
}
static struct V_1 * F_17 ( struct V_20 * V_20 )
{
return F_18 ( V_20 -> V_21 , struct V_1 , V_22 ) ;
}
static int F_19 ( struct V_23 * V_23 , struct V_20 * V_20 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
if ( F_20 ( & V_24 ) == 1 ) {
F_10 ( V_1 ) ;
return 0 ;
}
F_21 ( & V_24 ) ;
return - V_25 ;
}
static T_3 F_22 ( struct V_20 * V_20 , char T_5 * V_15 ,
T_4 V_26 , T_6 * V_27 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
T_1 V_28 ;
int V_29 = 1 ;
T_1 V_30 [ V_31 ] ;
T_3 V_32 = 0 ;
T_3 V_33 ;
if ( ! F_23 ( V_34 , V_15 , V_26 ) )
return - V_35 ;
F_24 ( * V_27 ) ;
if ( F_25 ( V_1 -> V_36 ,
F_1 ( V_1 , V_9 ) & V_11 ) )
return - V_37 ;
F_26 ( & V_1 -> V_38 ) ;
if ( F_27 ( ! ( F_1 ( V_1 , V_9 ) & V_11 ) ) ) {
V_32 = - V_39 ;
goto V_40;
}
F_9 ( V_1 ) ;
F_8 ( V_1 ) ;
F_6 ( V_1 ) ;
V_30 [ 0 ] = F_12 ( V_1 ) ;
V_28 = V_30 [ 0 ] ;
if ( V_28 + 1 > V_26 )
V_28 = V_26 - 1 ;
while ( V_28 ) {
V_33 = F_28 ( T_3 , V_28 , sizeof( V_30 ) - V_29 ) ;
F_13 ( V_1 , V_30 + V_29 , V_33 ) ;
if ( F_29 ( V_15 , V_30 , V_33 + V_29 ) ) {
V_32 = - V_35 ;
break;
}
V_28 -= V_33 ;
V_15 += V_33 + V_29 ;
V_32 += V_33 + V_29 ;
V_29 = 0 ;
}
F_10 ( V_1 ) ;
V_40:
F_30 ( & V_1 -> V_38 ) ;
return V_32 ;
}
static T_3 F_31 ( struct V_20 * V_20 , const char T_5 * V_15 ,
T_4 V_26 , T_6 * V_27 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
T_1 V_30 [ V_31 ] ;
T_3 V_32 = 0 ;
T_3 V_41 ;
if ( V_26 < 5 )
return - V_42 ;
if ( ! F_23 ( V_43 , V_15 , V_26 ) )
return - V_35 ;
F_24 ( * V_27 ) ;
if ( F_25 ( V_1 -> V_36 ,
! ( F_1 ( V_1 , V_9 ) &
( V_44 | V_13 ) ) ) )
return - V_37 ;
F_26 ( & V_1 -> V_38 ) ;
if ( F_27 ( F_1 ( V_1 , V_9 ) &
( V_44 | V_13 ) ) ) {
V_32 = - V_39 ;
goto V_40;
}
F_7 ( V_1 ) ;
while ( V_26 ) {
V_41 = F_28 ( T_3 , V_26 , sizeof( V_30 ) ) ;
if ( F_32 ( & V_30 , V_15 , V_41 ) ) {
V_32 = - V_35 ;
break;
}
F_15 ( V_1 , V_30 , V_41 ) ;
V_26 -= V_41 ;
V_15 += V_41 ;
V_32 += V_41 ;
}
F_11 ( V_1 ) ;
V_40:
F_30 ( & V_1 -> V_38 ) ;
return V_32 ;
}
static long F_33 ( struct V_20 * V_20 , unsigned int V_45 ,
unsigned long V_46 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
switch ( V_45 ) {
case V_47 :
F_16 ( V_1 ) ;
return 0 ;
}
return - V_42 ;
}
static int F_34 ( struct V_23 * V_23 , struct V_20 * V_20 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
F_21 ( & V_24 ) ;
F_9 ( V_1 ) ;
return 0 ;
}
static unsigned int F_35 ( struct V_20 * V_20 , T_7 * V_48 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
unsigned int V_49 = 0 ;
T_1 V_50 ;
F_36 ( V_20 , & V_1 -> V_36 , V_48 ) ;
V_50 = F_1 ( V_1 , V_9 ) ;
if ( V_50 & V_11 )
V_49 |= V_51 ;
if ( ! ( V_50 & ( V_44 | V_13 ) ) )
V_49 |= V_52 ;
return V_49 ;
}
static void F_37 ( unsigned long V_7 )
{
struct V_1 * V_1 = ( void * ) V_7 ;
V_1 -> F_37 . V_53 += F_38 ( 500 ) ;
F_39 ( & V_1 -> V_36 ) ;
F_40 ( & V_1 -> F_37 ) ;
}
static T_8 F_41 ( int V_54 , void * V_55 )
{
struct V_1 * V_1 = V_55 ;
T_9 V_2 ;
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 , V_1 -> V_6 + V_56 , & V_2 ) ;
if ( V_4 )
return V_57 ;
V_2 &= V_58 | V_59 ;
if ( ! V_2 )
return V_57 ;
F_5 ( V_1 -> V_5 , V_1 -> V_6 + V_56 , V_2 ) ;
F_39 ( & V_1 -> V_36 ) ;
return V_60 ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = & V_62 -> V_64 ;
int V_4 ;
V_1 -> V_54 = F_43 ( V_62 , 0 ) ;
if ( ! V_1 -> V_54 )
return - V_65 ;
V_4 = F_44 ( V_64 , V_1 -> V_54 , F_41 , V_66 ,
V_67 , V_1 ) ;
if ( V_4 < 0 ) {
F_45 ( V_64 , L_3 , V_1 -> V_54 ) ;
V_1 -> V_54 = 0 ;
return V_4 ;
}
V_4 = F_46 ( V_1 -> V_5 , V_1 -> V_6 + V_68 ,
( V_69 | V_70 ) ,
( V_69 | V_70 ) ) ;
return V_4 ;
}
static int F_47 ( struct V_61 * V_62 )
{
struct V_1 * V_1 ;
struct V_63 * V_64 ;
int V_4 ;
if ( ! V_62 || ! V_62 -> V_64 . V_71 )
return - V_65 ;
V_64 = & V_62 -> V_64 ;
F_48 ( V_64 , L_4 ) ;
V_1 = F_49 ( V_64 , sizeof( * V_1 ) , V_72 ) ;
if ( ! V_1 )
return - V_73 ;
F_50 ( & V_62 -> V_64 , V_1 ) ;
V_1 -> V_5 = F_51 ( V_62 -> V_64 . V_74 -> V_71 ) ;
if ( F_52 ( V_1 -> V_5 ) ) {
struct V_75 * V_76 ;
void T_10 * V_77 ;
V_76 = F_53 ( V_62 , V_78 , 0 ) ;
V_77 = F_54 ( & V_62 -> V_64 , V_76 ) ;
if ( F_52 ( V_77 ) )
return F_55 ( V_77 ) ;
V_1 -> V_5 = F_56 ( V_64 , V_77 , & V_79 ) ;
V_1 -> V_6 = 0 ;
} else {
V_4 = F_57 ( V_64 -> V_71 , L_5 , & V_1 -> V_6 ) ;
if ( V_4 )
return V_4 ;
}
F_58 ( & V_1 -> V_38 ) ;
F_59 ( & V_1 -> V_36 ) ;
V_1 -> V_22 . V_80 = V_81 ,
V_1 -> V_22 . V_82 = V_67 ,
V_1 -> V_22 . V_83 = & V_84 ,
V_1 -> V_22 . V_74 = V_64 ;
V_4 = F_60 ( & V_1 -> V_22 ) ;
if ( V_4 ) {
F_61 ( V_64 , L_6 ) ;
return V_4 ;
}
F_42 ( V_1 , V_62 ) ;
if ( V_1 -> V_54 ) {
F_48 ( V_64 , L_7 , V_1 -> V_54 ) ;
} else {
F_48 ( V_64 , L_8 ) ;
F_62 ( & V_1 -> F_37 , F_37 ,
( unsigned long ) V_1 ) ;
V_1 -> F_37 . V_53 = V_85 + F_38 ( 10 ) ;
F_40 ( & V_1 -> F_37 ) ;
}
F_5 ( V_1 -> V_5 , V_1 -> V_6 + V_86 ,
( V_87 << V_88 ) |
( V_89 << V_90 ) |
V_91 |
V_92 |
V_93 ) ;
F_10 ( V_1 ) ;
return 0 ;
}
static int F_63 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_64 ( & V_62 -> V_64 ) ;
F_65 ( & V_1 -> V_22 ) ;
if ( ! V_1 -> V_54 )
F_66 ( & V_1 -> F_37 ) ;
return 0 ;
}
