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
static int F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
int V_3 = ( int ) ( unsigned long ) V_13 -> V_17 ;
T_1 V_26 = 0 ;
int V_27 = 0 ;
F_10 ( V_2 , V_3 , V_28 , 0xFFFF ) ;
if ( ( V_13 -> V_18 == V_29 || V_13 -> V_18 == V_19 ) &&
V_13 -> V_30 . V_31 &&
V_13 -> V_30 . V_31 [ 10 ] != 0 ) {
T_2 V_32 = F_12 ( V_13 -> V_30 . V_31 [ 75 ] ) ;
T_2 V_33 = F_12 ( V_13 -> V_30 . V_31 [ 76 ] ) ;
if ( V_33 & 0x100 )
V_26 = ( V_32 & 0x1F ) + 1 ;
F_4 ( V_2 , V_3 , V_34 ,
( 1ULL << V_26 ) - 1 ) ;
F_6 ( V_2 , V_3 , V_35 , V_26 ) ;
}
if ( V_13 -> V_18 == V_29 || V_13 -> V_18 == V_36 ||
V_13 -> V_18 == V_19 ) {
struct V_37 * V_38 = (struct V_37 * )
V_13 -> V_39 ;
F_6 ( V_2 , V_3 , V_40 , V_38 -> V_41 ) ;
}
F_10 ( V_2 , V_3 , V_42 , 0xFFFF ) ;
if ( V_26 > 0 )
V_27 = F_9 ( V_13 ) ;
return V_27 ;
}
static int F_13 ( struct V_12 * V_13 )
{
int V_3 , V_4 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
T_3 V_43 = 0 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_13 -> V_17 = ( void * ) ( unsigned long ) V_3 ;
F_6 ( V_2 , V_3 , 0 , V_44 ) ;
F_6 ( V_2 , V_3 , 1 , 0 ) ;
F_10 ( V_2 , V_3 , V_45 , 0xFFFF ) ;
for ( V_4 = 0 ; V_4 < V_46 ; V_4 ++ )
F_6 ( V_2 , V_3 , V_47 + V_4 ,
V_13 -> V_48 [ V_4 ] ) ;
F_10 ( V_2 , V_3 , V_49 , 0xFFFF ) ;
F_8 ( V_13 ) ;
F_6 ( V_2 , V_3 , V_50 , V_13 -> V_14 -> V_51 ) ;
if ( V_13 -> V_14 -> V_52 != V_53 ) {
V_43 |= V_54 ;
if ( ( V_13 -> V_18 == V_29 ) ||
( V_13 -> V_21 & V_55 ) ) {
struct V_56 * V_57 = & V_13 -> V_30 . V_57 ;
if ( V_57 -> V_58 == V_59 &&
V_57 -> V_60 == V_61 &&
V_57 -> V_62 == V_63 ) {
if ( V_57 -> V_64 . V_65 )
V_43 |= V_66 ;
if ( V_57 -> V_64 . V_67 )
V_43 |= V_68 ;
}
} else {
V_43 |= V_69 ;
if ( ! V_13 -> V_70 &&
( V_13 -> V_18 == V_71 ||
V_13 -> V_18 == V_72 ) )
F_6 ( V_2 , V_3 , V_73 ,
4 ) ;
else
F_6 ( V_2 , V_3 , V_73 ,
V_13 -> V_74 ) ;
F_6 ( V_2 , V_3 , V_75 , 1 ) ;
}
}
if ( V_13 -> V_18 == V_36 )
V_43 |= V_76 ;
F_6 ( V_2 , V_3 , V_77 , V_43 ) ;
V_43 = 0 ;
if ( V_13 -> V_21 & V_55 )
V_43 |= V_78 ;
F_6 ( V_2 , V_3 , V_79 , V_43 ) ;
F_10 ( V_2 , V_3 , V_80 , 0xFFFF ) ;
F_10 ( V_2 , V_3 , V_81 , 0xFFFF ) ;
F_10 ( V_2 , V_3 , V_25 , 0xFFFF ) ;
if ( V_13 -> V_18 == V_29 || ( V_13 -> V_21 & V_55 ) ) {
V_4 = F_11 ( V_13 ) ;
if ( V_4 < 0 ) {
F_5 ( V_2 , V_3 ) ;
return V_4 ;
}
}
if ( V_13 -> V_18 == V_82 ) {
struct V_83 * V_84 = F_14 ( V_13 -> V_85 ) ;
if ( V_84 -> V_86 > 0 )
F_10 ( V_2 , V_3 , V_87 ,
F_15 ( V_84 -> V_86 ,
( T_2 ) V_88 ) ) ;
else
F_10 ( V_2 , V_3 , V_87 ,
( T_2 ) V_88 ) ;
}
return 0 ;
}
static int F_16 ( struct V_12 * V_13 )
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
static int F_17 ( struct V_12 * V_13 )
{
int V_3 , V_4 , V_89 , V_90 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
T_3 V_43 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_8 ( V_13 ) ;
V_43 = ( V_13 -> V_30 . V_91 << 4 ) | V_92 ;
F_6 ( V_2 , V_3 , V_93 , V_43 ) ;
F_10 ( V_2 , V_3 , V_25 , 0xFFFF ) ;
F_10 ( V_2 , V_3 , V_28 , 0xFFFF ) ;
F_11 ( V_13 ) ;
V_89 = ( int ) ( unsigned long ) V_13 -> V_70 -> V_17 ;
F_10 ( V_2 , V_3 , V_94 , V_89 ) ;
V_90 = F_18 ( V_2 , V_89 , V_25 ) ;
F_10 ( V_2 , V_90 , V_13 -> V_30 . V_91 , V_3 ) ;
if ( F_19 ( V_2 , V_3 , V_35 ) > 0 ) {
V_4 = F_9 ( V_13 ) ;
if ( V_4 < 0 ) {
F_5 ( V_2 , V_3 ) ;
return V_4 ;
}
}
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
return - V_95 ;
}
static int F_21 ( struct V_12 * V_13 )
{
int V_27 = 0 ;
V_27 = F_13 ( V_13 ) ;
if ( V_27 )
goto V_8;
V_27 = F_16 ( V_13 ) ;
if ( V_27 )
F_5 ( V_13 -> V_14 -> V_15 -> V_16 ,
( int ) ( unsigned long ) V_13 -> V_17 ) ;
V_8:
return V_27 ;
}
int F_22 ( struct V_12 * V_13 )
{
unsigned long V_43 ;
int V_27 = 0 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
F_23 ( & V_2 -> V_5 . V_96 , V_43 ) ;
switch ( V_13 -> V_18 ) {
case V_36 :
V_27 = F_21 ( V_13 ) ;
break;
case V_19 :
V_27 = F_17 ( V_13 ) ;
break;
default:
if ( V_13 -> V_21 )
V_27 = F_13 ( V_13 ) ;
else
V_27 = F_20 ( V_13 ) ;
}
F_24 ( & V_2 -> V_5 . V_96 , V_43 ) ;
return V_27 ;
}
void F_25 ( struct V_12 * V_13 )
{
int V_3 , V_97 ;
unsigned long V_43 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 -> V_16 ;
F_23 ( & V_2 -> V_5 . V_96 , V_43 ) ;
V_3 = ( int ) ( unsigned long ) V_13 -> V_17 ;
V_97 = F_18 ( V_2 , V_3 , V_25 ) ;
if ( V_97 != 0xFFFF )
F_5 ( V_2 , V_97 ) ;
F_5 ( V_2 , V_3 ) ;
V_13 -> V_17 = NULL ;
F_24 ( & V_2 -> V_5 . V_96 , V_43 ) ;
}
