static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 >= V_2 -> V_5 . V_6 ) {
V_3 = - V_7 ;
goto V_8;
}
F_3 ( V_3 , V_2 ) ;
for ( V_4 = 0 ; V_4 < sizeof( struct V_9 ) ; V_4 += 4 )
F_4 ( V_2 , V_3 , V_4 , 0 ) ;
V_8:
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_3 || V_3 >= 0xFFFF )
return;
F_6 ( V_2 , V_3 , V_10 , V_11 ) ;
F_7 ( V_3 , V_2 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
int V_3 = ( int ) ( unsigned long ) V_13 -> V_17 ;
if ( V_13 -> V_18 == V_19 )
F_6 ( V_2 , V_3 , V_10 , V_20 ) ;
else if ( V_13 -> V_21 )
F_6 ( V_2 , V_3 , V_10 , V_22 ) ;
else
F_6 ( V_2 , V_3 , V_10 , V_23 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
int V_3 , V_4 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_4 = 0 ; V_4 < sizeof( struct V_24 ) ; V_4 += 2 )
F_10 ( V_2 , V_3 , V_4 , 0xFFFF ) ;
F_10 ( V_2 , ( int ) ( unsigned long ) V_13 -> V_17 ,
V_25 , V_3 ) ;
return 0 ;
}
void F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
struct V_26 * V_27 = F_12 ( V_13 ) ;
int V_3 = ( int ) ( unsigned long ) V_13 -> V_17 ;
T_1 V_28 = 0 ;
if ( V_13 -> V_18 == V_29 || V_13 -> V_18 == V_19 ) {
if ( F_13 ( V_27 -> V_30 ) )
V_28 = F_14 ( V_27 -> V_30 ) ;
F_4 ( V_2 , V_3 , V_31 ,
( 1ULL << V_28 ) - 1 ) ;
F_6 ( V_2 , V_3 , V_32 , V_28 ) ;
}
if ( V_28 > 0 )
if ( F_9 ( V_13 ) != 0 ) {
unsigned long V_33 ;
F_15 ( V_13 -> V_34 . V_35 -> V_36 , V_33 ) ;
V_27 -> V_33 |= V_37 ;
F_16 ( V_13 -> V_34 . V_35 -> V_36 , V_33 ) ;
}
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
int V_3 = ( int ) ( unsigned long ) V_13 -> V_17 ;
F_10 ( V_2 , V_3 , V_38 , 0xFFFF ) ;
if ( V_13 -> V_18 == V_29 || V_13 -> V_18 == V_39 ||
V_13 -> V_18 == V_19 ) {
struct V_40 * V_41 = (struct V_40 * )
V_13 -> V_42 ;
F_6 ( V_2 , V_3 , V_43 , V_41 -> V_44 ) ;
}
F_10 ( V_2 , V_3 , V_45 , 0xFFFF ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 )
{
int V_3 , V_4 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
T_2 V_33 = 0 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_13 -> V_17 = ( void * ) ( unsigned long ) V_3 ;
F_6 ( V_2 , V_3 , 0 , V_46 ) ;
F_6 ( V_2 , V_3 , 1 , 0 ) ;
F_10 ( V_2 , V_3 , V_47 , 0xFFFF ) ;
for ( V_4 = 0 ; V_4 < V_48 ; V_4 ++ )
F_6 ( V_2 , V_3 , V_49 + V_4 ,
V_13 -> V_50 [ V_4 ] ) ;
F_10 ( V_2 , V_3 , V_51 , 0xFFFF ) ;
F_8 ( V_13 ) ;
F_6 ( V_2 , V_3 , V_52 , V_13 -> V_14 -> V_53 ) ;
if ( V_13 -> V_14 -> V_54 != V_55 ) {
V_33 |= V_56 ;
if ( ( V_13 -> V_18 == V_29 ) ||
( V_13 -> V_21 & V_57 ) ) {
struct V_58 * V_59 = & V_13 -> V_34 . V_59 ;
if ( V_59 -> V_60 == V_61 &&
V_59 -> V_62 == V_63 &&
V_59 -> V_64 == V_65 ) {
if ( V_59 -> V_66 . V_67 )
V_33 |= V_68 ;
if ( V_59 -> V_66 . V_69 )
V_33 |= V_70 ;
}
} else {
V_33 |= V_71 ;
if ( ! V_13 -> V_72 &&
( V_13 -> V_18 == V_73 ||
V_13 -> V_18 == V_74 ) )
F_6 ( V_2 , V_3 , V_75 ,
4 ) ;
else
F_6 ( V_2 , V_3 , V_75 ,
V_13 -> V_76 ) ;
F_6 ( V_2 , V_3 , V_77 , 1 ) ;
}
}
if ( V_13 -> V_18 == V_39 )
V_33 |= V_78 ;
F_6 ( V_2 , V_3 , V_79 , V_33 ) ;
V_33 = 0 ;
if ( V_13 -> V_21 & V_57 )
V_33 |= V_80 ;
F_6 ( V_2 , V_3 , V_81 , V_33 ) ;
F_10 ( V_2 , V_3 , V_82 , 0xFFFF ) ;
F_10 ( V_2 , V_3 , V_83 , 0xFFFF ) ;
F_10 ( V_2 , V_3 , V_25 , 0xFFFF ) ;
if ( V_13 -> V_18 == V_29 || ( V_13 -> V_21 & V_57 ) ) {
V_4 = F_17 ( V_13 ) ;
if ( V_4 < 0 ) {
F_5 ( V_2 , V_3 ) ;
return V_4 ;
}
}
if ( V_13 -> V_18 == V_84 ) {
struct V_85 * V_86 = F_19 ( V_13 -> V_87 ) ;
if ( V_86 -> V_88 > 0 )
F_10 ( V_2 , V_3 , V_89 ,
F_20 ( V_86 -> V_88 ,
( V_90 ) V_91 ) ) ;
else
F_10 ( V_2 , V_3 , V_89 ,
( V_90 ) V_91 ) ;
}
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
int V_3 , V_4 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_4 = 0 ; V_4 < 32 ; V_4 += 2 )
F_10 ( V_2 , V_3 , V_4 , 0xFFFF ) ;
F_10 ( V_2 , ( int ) ( unsigned long ) V_13 -> V_17 ,
V_25 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 )
{
int V_3 , V_4 , V_92 , V_93 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
T_2 V_33 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_8 ( V_13 ) ;
V_33 = ( V_13 -> V_34 . V_94 << 4 ) | V_95 ;
F_6 ( V_2 , V_3 , V_96 , V_33 ) ;
F_10 ( V_2 , V_3 , V_25 , 0xFFFF ) ;
F_10 ( V_2 , V_3 , V_38 , 0xFFFF ) ;
F_17 ( V_13 ) ;
V_92 = ( int ) ( unsigned long ) V_13 -> V_72 -> V_17 ;
F_10 ( V_2 , V_3 , V_97 , V_92 ) ;
V_93 = F_23 ( V_2 , V_92 , V_25 ) ;
F_10 ( V_2 , V_93 , V_13 -> V_34 . V_94 , V_3 ) ;
if ( F_24 ( V_2 , V_3 , V_32 ) > 0 ) {
V_4 = F_9 ( V_13 ) ;
if ( V_4 < 0 ) {
F_5 ( V_2 , V_3 ) ;
return V_4 ;
}
}
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
return - V_98 ;
}
static int F_26 ( struct V_12 * V_13 )
{
int V_99 = 0 ;
V_99 = F_18 ( V_13 ) ;
if ( V_99 )
goto V_8;
V_99 = F_21 ( V_13 ) ;
if ( V_99 )
F_5 ( V_13 -> V_14 -> V_15 -> V_16 ,
( int ) ( unsigned long ) V_13 -> V_17 ) ;
V_8:
return V_99 ;
}
int F_27 ( struct V_12 * V_13 )
{
unsigned long V_33 ;
int V_99 = 0 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
F_15 ( & V_2 -> V_5 . V_100 , V_33 ) ;
switch ( V_13 -> V_18 ) {
case V_39 :
V_99 = F_26 ( V_13 ) ;
break;
case V_19 :
V_99 = F_22 ( V_13 ) ;
break;
default:
if ( V_13 -> V_21 )
V_99 = F_18 ( V_13 ) ;
else
V_99 = F_25 ( V_13 ) ;
}
F_16 ( & V_2 -> V_5 . V_100 , V_33 ) ;
return V_99 ;
}
void F_28 ( struct V_12 * V_13 )
{
int V_3 , V_101 ;
unsigned long V_33 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
F_15 ( & V_2 -> V_5 . V_100 , V_33 ) ;
V_3 = ( int ) ( unsigned long ) V_13 -> V_17 ;
V_101 = F_23 ( V_2 , V_3 , V_25 ) ;
if ( V_101 != 0xFFFF )
F_5 ( V_2 , V_101 ) ;
F_5 ( V_2 , V_3 ) ;
V_13 -> V_17 = NULL ;
F_16 ( & V_2 -> V_5 . V_100 , V_33 ) ;
}
