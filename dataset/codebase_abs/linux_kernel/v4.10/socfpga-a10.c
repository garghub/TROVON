static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return true ;
}
return false ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return true ;
}
return false ;
}
static void F_3 ( struct V_10 * V_11 ,
int V_12 )
{
V_12 <<= V_13 ;
F_4 ( V_11 -> V_14 , V_8 ,
V_15 , V_12 ) ;
}
static void F_5 ( struct V_10 * V_11 ,
T_1 V_16 )
{
T_1 V_17 ;
F_6 ( V_11 -> V_14 , V_5 ,
V_18 ) ;
F_6 ( V_11 -> V_14 , V_4 , V_16 ) ;
F_7 ( V_11 -> V_14 , V_5 , V_17 ,
V_17 , 1 , 100 ) ;
F_6 ( V_11 -> V_14 , V_5 ,
V_18 ) ;
}
static int F_8 ( T_1 * V_19 , T_2 V_20 )
{
if ( V_20 < V_21 + 1 )
return - V_22 ;
return ( ( V_19 [ V_21 ] >> 2 ) & 3 ) != 0 ;
}
static int F_9 ( T_1 * V_19 , T_2 V_20 )
{
if ( V_20 < V_23 + 1 )
return - V_22 ;
return ! ( ( V_19 [ V_23 ] >> 1 ) & 1 ) ;
}
static unsigned int F_10 ( unsigned int V_24 ,
bool V_25 , bool V_26 )
{
unsigned int V_27 ;
if ( ! V_26 && ! V_25 )
return V_28 ;
if ( V_26 )
V_27 = V_29 ;
else
V_27 = V_30 ;
if ( V_24 == V_31 )
V_27 += 1 ;
return V_27 ;
}
static int F_11 ( struct V_32 * V_33 ,
unsigned int V_24 ,
const char * V_34 , T_2 V_16 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
unsigned int V_27 ;
int V_25 , V_26 ;
V_25 = F_8 ( ( T_1 * ) V_34 , V_16 / 4 ) ;
if ( V_25 < 0 )
return - V_22 ;
V_26 = F_9 ( ( T_1 * ) V_34 , V_16 / 4 ) ;
if ( V_26 < 0 )
return - V_22 ;
V_27 = F_10 ( V_24 , V_25 , V_26 ) ;
F_4 ( V_11 -> V_14 , V_8 ,
V_35 ,
V_27 << V_36 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_10 * V_11 )
{
T_1 V_17 ;
F_13 ( V_11 -> V_14 , V_9 , & V_17 ) ;
return V_17 ;
}
static int F_14 ( struct V_10 * V_11 )
{
T_1 V_3 , V_37 ;
for ( V_37 = 0 ; V_37 < 10 ; V_37 ++ ) {
V_3 = F_12 ( V_11 ) ;
if ( V_3 & V_38 )
return - V_22 ;
if ( V_3 & V_39 )
return 0 ;
}
return - V_40 ;
}
static int F_15 ( struct V_10 * V_11 )
{
T_1 V_3 , V_37 ;
for ( V_37 = 0 ; V_37 < 10 ; V_37 ++ ) {
V_3 = F_12 ( V_11 ) ;
if ( V_3 & V_38 )
return - V_22 ;
if ( V_3 & V_41 )
return 0 ;
}
return - V_40 ;
}
static int F_16 ( struct V_32 * V_33 ,
struct V_42 * V_43 ,
const char * V_34 , T_2 V_16 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
unsigned int V_24 ;
T_1 V_44 , V_45 , V_46 ;
int V_47 ;
if ( V_43 -> V_48 & V_49 )
V_24 = V_50 ;
else
return - V_22 ;
V_44 = F_12 ( V_11 ) ;
V_44 &= V_51 ;
V_44 >>= V_52 ;
if ( ( V_44 != 0 ) && ( V_44 != 1 ) ) {
F_17 ( & V_33 -> V_2 , L_1 , V_44 ) ;
return - V_22 ;
}
V_45 = F_12 ( V_11 ) ;
V_46 = V_53 |
V_54 ;
if ( ( V_45 & V_46 ) != V_46 )
return - V_22 ;
F_3 ( V_11 , V_24 ) ;
V_47 = F_11 ( V_33 , V_24 , V_34 , V_16 ) ;
if ( V_47 )
return V_47 ;
F_6 ( V_11 -> V_14 , V_7 ,
V_55 ) ;
F_4 ( V_11 -> V_14 , V_8 ,
V_56 ,
V_56 ) ;
F_6 ( V_11 -> V_14 , V_6 ,
V_57 |
V_58 |
V_59 |
V_60 ) ;
F_4 ( V_11 -> V_14 , V_7 ,
V_55 , 0 ) ;
F_5 ( V_11 , 256 ) ;
F_4 ( V_11 -> V_14 , V_7 ,
V_61 ,
V_61 ) ;
F_5 ( V_11 , 0x7ff ) ;
return F_14 ( V_11 ) ;
}
static int F_18 ( struct V_32 * V_33 , const char * V_34 ,
T_2 V_16 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
T_1 * V_62 = ( T_1 * ) V_34 ;
T_2 V_37 = 0 ;
if ( V_16 <= 0 )
return - V_22 ;
while ( V_16 >= sizeof( T_1 ) ) {
F_19 ( V_62 [ V_37 ++ ] , V_11 -> V_63 ) ;
V_16 -= sizeof( T_1 ) ;
}
switch ( V_16 ) {
case 3 :
F_19 ( V_62 [ V_37 ++ ] & 0x00ffffff , V_11 -> V_63 ) ;
break;
case 2 :
F_19 ( V_62 [ V_37 ++ ] & 0x0000ffff , V_11 -> V_63 ) ;
break;
case 1 :
F_19 ( V_62 [ V_37 ++ ] & 0x000000ff , V_11 -> V_63 ) ;
break;
case 0 :
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_20 ( struct V_32 * V_33 ,
struct V_42 * V_43 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
T_1 V_3 ;
int V_47 ;
V_47 = F_15 ( V_11 ) ;
F_4 ( V_11 -> V_14 , V_7 ,
V_61 , 0 ) ;
F_5 ( V_11 , 256 ) ;
F_4 ( V_11 -> V_14 , V_8 ,
V_56 , 0 ) ;
F_4 ( V_11 -> V_14 , V_7 ,
V_65 ,
V_65 ) ;
F_4 ( V_11 -> V_14 , V_7 ,
V_55 ,
V_55 ) ;
if ( V_47 )
return V_47 ;
V_3 = F_12 ( V_11 ) ;
if ( ( ( V_3 & V_66 ) == 0 ) ||
( ( V_3 & V_67 ) == 0 ) ||
( ( V_3 & V_54 ) == 0 ) ) {
F_17 ( & V_33 -> V_2 ,
L_2 , V_3 ) ;
return - V_40 ;
}
return 0 ;
}
static enum V_68 F_21 ( struct V_32 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
T_1 V_3 = F_12 ( V_11 ) ;
if ( V_3 & V_66 )
return V_69 ;
if ( V_3 & V_39 )
return V_70 ;
if ( V_3 & V_71 )
return V_72 ;
if ( ( V_3 & V_54 ) == 0 )
return V_73 ;
return V_74 ;
}
static int F_22 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = & V_76 -> V_2 ;
struct V_10 * V_11 ;
void T_3 * V_77 ;
struct V_78 * V_79 ;
int V_47 ;
V_11 = F_23 ( V_2 , sizeof( * V_11 ) , V_80 ) ;
if ( ! V_11 )
return - V_81 ;
V_79 = F_24 ( V_76 , V_82 , 0 ) ;
V_77 = F_25 ( V_2 , V_79 ) ;
if ( F_26 ( V_77 ) )
return F_27 ( V_77 ) ;
V_79 = F_24 ( V_76 , V_82 , 1 ) ;
V_11 -> V_63 = F_25 ( V_2 , V_79 ) ;
if ( F_26 ( V_11 -> V_63 ) )
return F_27 ( V_11 -> V_63 ) ;
V_11 -> V_14 = F_28 ( V_2 , V_77 ,
& V_83 ) ;
if ( F_26 ( V_11 -> V_14 ) )
return - V_84 ;
V_11 -> V_85 = F_29 ( V_2 , NULL ) ;
if ( F_26 ( V_11 -> V_85 ) ) {
F_30 ( V_2 , L_3 ) ;
return F_27 ( V_11 -> V_85 ) ;
}
V_47 = F_31 ( V_11 -> V_85 ) ;
if ( V_47 ) {
F_30 ( V_2 , L_4 ) ;
return - V_86 ;
}
return F_32 ( V_2 , L_5 ,
& V_87 , V_11 ) ;
}
static int F_33 ( struct V_75 * V_76 )
{
struct V_32 * V_33 = F_34 ( V_76 ) ;
struct V_10 * V_11 = V_33 -> V_11 ;
F_35 ( & V_76 -> V_2 ) ;
F_36 ( V_11 -> V_85 ) ;
return 0 ;
}
