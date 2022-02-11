static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_6 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
T_1 V_9 ;
V_9 = F_1 ( V_2 , V_7 ) ;
V_9 |= V_8 ;
F_3 ( V_2 , V_7 , V_9 ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
T_1 V_9 ;
V_9 = F_1 ( V_2 , V_7 ) ;
V_9 &= ~ V_8 ;
F_3 ( V_2 , V_7 , V_9 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_10 ) &
V_11 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_1 V_12 = F_12 ( V_2 ) ;
if ( ( V_12 & V_13 ) == 0 )
return V_14 ;
return F_1 ( V_2 , V_15 ) &
V_16 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_17 ,
V_18 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_19 )
{
int V_20 = 2 ;
T_1 V_21 ;
if ( F_1 ( V_2 , V_17 ) )
F_14 ( V_2 ) ;
F_3 ( V_2 , V_22 , V_19 ) ;
do {
V_21 = F_1 ( V_2 , V_17 ) ;
if ( V_21 == V_18 ) {
F_14 ( V_2 ) ;
return 0 ;
}
F_16 ( 1 ) ;
} while ( V_20 -- );
return - V_23 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 V_24 )
{
int V_20 = 2 ;
do {
if ( ( F_13 ( V_2 ) & V_24 ) != 0 )
return 0 ;
F_18 ( 20 ) ;
} while ( V_20 -- );
return - V_23 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_25 )
{
F_3 ( V_2 , V_26 , 0 ) ;
F_3 ( V_2 , V_27 , V_25 ) ;
F_3 ( V_2 , V_28 , V_25 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_30 , V_25 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_30 , 0 ) ;
}
static T_2 F_21 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_1 V_25 , V_33 ;
bool V_34 , V_35 ;
V_25 = F_5 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_28 , V_25 ) ;
V_33 = F_5 ( V_2 , V_10 ) ;
V_34 = ( V_33 & V_37 ) != 0 ;
V_35 = ( V_33 & V_38 ) != 0 ;
if ( V_34 && V_35 ) {
F_7 ( V_2 ,
V_30 , 0 ) ;
F_22 ( & V_2 -> V_39 ) ;
}
return V_40 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_20 , V_41 = 0 ;
F_20 ( V_2 ) ;
F_24 ( & V_2 -> V_39 ) ;
F_19 ( V_2 , V_37 ) ;
V_20 = F_25 (
& V_2 -> V_39 ,
F_26 ( 10 ) ) ;
if ( V_20 == 0 )
V_41 = - V_23 ;
F_20 ( V_2 ) ;
return V_41 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_42 ;
V_42 = F_1 ( V_2 , V_15 ) ;
V_42 &= V_43 ;
V_42 >>= V_44 ;
if ( ( V_42 >= F_28 ( V_45 ) ) || ! V_45 [ V_42 ] . V_46 )
return - V_47 ;
return V_42 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_48 ;
int V_49 ;
V_49 = F_27 ( V_2 ) ;
if ( V_49 < 0 )
return V_49 ;
V_48 = F_1 ( V_2 , V_50 ) ;
V_48 &= ~ V_51 ;
V_48 &= ~ V_52 ;
V_48 |= V_45 [ V_49 ] . V_53 ;
V_48 &= ~ V_54 ;
F_3 ( V_2 , V_50 , V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
T_1 V_48 , V_12 ;
int V_41 ;
V_41 = F_29 ( V_2 ) ;
if ( V_41 )
return V_41 ;
F_10 ( V_2 , V_50 ,
V_57 ) ;
V_48 = F_1 ( V_2 , V_50 ) ;
V_48 |= V_58 ;
F_3 ( V_2 , V_50 , V_48 ) ;
V_12 = F_17 ( V_2 , V_59 ) ;
V_48 &= ~ V_58 ;
F_3 ( V_2 , V_50 , V_48 ) ;
if ( V_12 )
return - V_23 ;
return 0 ;
}
static int F_31 ( struct V_55 * V_56 , T_1 V_60 ,
const char * V_61 , T_3 V_19 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
int V_41 ;
if ( V_60 & V_62 ) {
F_32 ( & V_56 -> V_63 , L_1 ) ;
return - V_47 ;
}
V_41 = F_30 ( V_56 ) ;
if ( V_41 )
return V_41 ;
if ( F_17 ( V_2 , V_64 ) )
return - V_23 ;
F_3 ( V_2 , V_28 ,
V_38 ) ;
F_10 ( V_2 , V_50 ,
V_65 ) ;
return 0 ;
}
static int F_33 ( struct V_55 * V_56 ,
const char * V_61 , T_3 V_19 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
T_1 * V_66 = ( T_1 * ) V_61 ;
T_3 V_67 = 0 ;
if ( V_19 <= 0 )
return - V_47 ;
while ( V_19 >= sizeof( T_1 ) ) {
F_9 ( V_2 , V_66 [ V_67 ++ ] ) ;
V_19 -= sizeof( T_1 ) ;
}
switch ( V_19 ) {
case 3 :
F_9 ( V_2 , V_66 [ V_67 ++ ] & 0x00ffffff ) ;
break;
case 2 :
F_9 ( V_2 , V_66 [ V_67 ++ ] & 0x0000ffff ) ;
break;
case 1 :
F_9 ( V_2 , V_66 [ V_67 ++ ] & 0x000000ff ) ;
break;
case 0 :
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_34 ( struct V_55 * V_56 ,
T_1 V_60 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
T_1 V_12 ;
V_12 = F_23 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_11 ( V_2 , V_50 ,
V_65 ) ;
if ( F_15 ( V_2 , 4 ) )
return - V_23 ;
if ( F_17 ( V_2 , V_69 ) )
return - V_23 ;
F_11 ( V_2 , V_50 ,
V_57 ) ;
return 0 ;
}
static enum V_70 F_35 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
enum V_70 V_41 ;
T_1 V_24 ;
V_24 = F_13 ( V_2 ) ;
if ( V_24 < F_28 ( V_71 ) )
V_41 = V_71 [ V_24 ] ;
else
V_41 = V_72 ;
return V_41 ;
}
static int F_36 ( struct V_73 * V_74 )
{
struct V_75 * V_63 = & V_74 -> V_63 ;
struct V_1 * V_2 ;
struct V_76 * V_77 ;
int V_41 ;
V_2 = F_37 ( V_63 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_77 = F_38 ( V_74 , V_80 , 0 ) ;
V_2 -> V_4 = F_39 ( V_63 , V_77 ) ;
if ( F_40 ( V_2 -> V_4 ) )
return F_41 ( V_2 -> V_4 ) ;
V_77 = F_38 ( V_74 , V_80 , 1 ) ;
V_2 -> V_6 = F_39 ( V_63 , V_77 ) ;
if ( F_40 ( V_2 -> V_6 ) )
return F_41 ( V_2 -> V_6 ) ;
V_2 -> V_31 = F_42 ( V_74 , 0 ) ;
if ( V_2 -> V_31 < 0 )
return V_2 -> V_31 ;
V_41 = F_43 ( V_63 , V_2 -> V_31 , F_21 , 0 ,
F_44 ( V_63 ) , V_2 ) ;
if ( V_41 )
return V_41 ;
return F_45 ( V_63 , L_2 ,
& V_81 , V_2 ) ;
}
static int F_46 ( struct V_73 * V_74 )
{
F_47 ( & V_74 -> V_63 ) ;
return 0 ;
}
