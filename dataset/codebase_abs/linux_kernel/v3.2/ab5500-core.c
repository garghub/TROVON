int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 ,
T_1 * V_5 )
{
int V_6 ;
if ( V_3 >= V_7 )
return - V_8 ;
V_6 = F_2 ( & V_2 -> V_9 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_10 [ V_3 ] . V_11 , V_4 , V_5 , 1 ) ;
F_4 ( & V_2 -> V_9 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_12 , T_1 * V_13 , T_1 V_14 )
{
int V_6 ;
if ( V_3 >= V_7 )
return - V_8 ;
V_6 = F_2 ( & V_2 -> V_9 ) ;
if ( V_6 )
return V_6 ;
while ( V_14 ) {
T_1 V_15 = F_6 ( T_1 , V_14 , 4u ) ;
V_6 = F_3 ( V_10 [ V_3 ] . V_11 ,
V_12 , V_13 , V_15 ) ;
if ( V_6 )
goto V_16;
V_14 -= V_15 ;
V_12 += V_15 ;
V_13 += V_15 ;
}
V_16:
F_4 ( & V_2 -> V_9 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_17 , T_1 V_18 )
{
int V_6 = 0 ;
if ( V_3 >= V_7 )
return - V_8 ;
if ( V_17 ) {
T_1 V_19 ;
V_6 = F_2 ( & V_2 -> V_9 ) ;
if ( V_6 )
return V_6 ;
if ( V_17 == 0xFF )
V_19 = V_18 ;
else {
V_6 = F_3 ( V_10 [ V_3 ] . V_11 ,
V_4 , & V_19 , 1 ) ;
if ( V_6 )
return V_6 ;
V_19 = ( ( ~ V_17 & V_19 ) | ( V_17 & V_18 ) ) ;
}
V_6 = F_8 ( V_10 [ V_3 ] . V_11 , V_4 ,
& V_19 , 1 ) ;
F_4 ( & V_2 -> V_9 ) ;
}
return V_6 ;
}
static int
F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
return F_7 ( V_2 , V_3 , V_4 ,
0xff , V_5 ) ;
}
static const struct V_20 * F_10 ( T_1 V_21 , T_1 V_3 )
{
T_1 V_22 ;
if ( V_21 < V_23 ) {
for ( V_22 = 0 ; V_22 < V_24 [ V_21 ] . V_25 ; V_22 ++ ) {
if ( V_24 [ V_21 ] . V_3 [ V_22 ] . V_26 == V_3 )
return & V_24 [ V_21 ] . V_3 [ V_22 ] ;
}
}
return NULL ;
}
static bool F_11 ( T_1 V_21 , T_1 V_3 , T_1 V_12 , T_1 V_27 )
{
T_1 V_22 ;
const struct V_20 * V_28 ;
V_28 = F_10 ( V_21 , V_3 ) ;
if ( V_28 == NULL || V_27 < V_12 )
return false ;
for ( V_22 = 0 ; V_22 < V_28 -> V_29 ; V_22 ++ ) {
if ( V_12 < V_28 -> V_30 [ V_22 ] . V_31 )
break;
if ( ( V_27 <= V_28 -> V_30 [ V_22 ] . V_32 ) &&
( V_28 -> V_30 [ V_22 ] . V_33 & V_34 ) )
return true ;
}
return false ;
}
static bool F_12 ( T_1 V_21 , T_1 V_3 , T_1 V_4 )
{
return F_11 ( V_21 , V_3 , V_4 , V_4 ) ;
}
static bool F_13 ( T_1 V_21 , T_1 V_3 , T_1 V_12 , T_1 V_27 )
{
T_1 V_22 ;
const struct V_20 * V_28 ;
V_28 = F_10 ( V_21 , V_3 ) ;
if ( V_28 == NULL || V_27 < V_12 )
return false ;
for ( V_22 = 0 ; V_22 < V_28 -> V_29 ; V_22 ++ ) {
if ( V_12 < V_28 -> V_30 [ V_22 ] . V_31 )
return false ;
if ( V_12 <= V_28 -> V_30 [ V_22 ] . V_32 )
break;
}
while ( ( V_22 < V_28 -> V_29 ) &&
( V_28 -> V_30 [ V_22 ] . V_33 & V_35 ) ) {
if ( V_27 <= V_28 -> V_30 [ V_22 ] . V_32 )
return true ;
if ( ( ++ V_22 >= V_28 -> V_29 ) ||
( V_28 -> V_30 [ V_22 ] . V_31 !=
( V_28 -> V_30 [ V_22 - 1 ] . V_32 + 1 ) ) ) {
break;
}
}
return false ;
}
static bool F_14 ( T_1 V_21 , T_1 V_3 , T_1 V_4 )
{
return F_13 ( V_21 , V_3 , V_4 , V_4 ) ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_16 ( V_37 -> V_38 ) ;
return ( int ) V_2 -> V_39 ;
}
static int F_17 ( struct V_36 * V_37 ,
T_1 V_3 , T_1 V_4 , T_1 V_17 , T_1 V_18 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 = F_18 ( V_37 ) ;
if ( ( V_7 <= V_3 ) ||
! F_12 ( V_41 -> V_42 , V_3 , V_4 ) )
return - V_8 ;
V_2 = F_16 ( V_37 -> V_38 ) ;
return F_7 ( V_2 , V_3 , V_4 ,
V_17 , V_18 ) ;
}
static int F_19 ( struct V_36 * V_37 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
return F_17 ( V_37 , V_3 , V_4 , 0xFF ,
V_5 ) ;
}
static int F_20 ( struct V_36 * V_37 , T_1 V_3 ,
T_1 V_4 , T_1 * V_5 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 = F_18 ( V_37 ) ;
if ( ( V_7 <= V_3 ) ||
! F_14 ( V_41 -> V_42 , V_3 , V_4 ) )
return - V_8 ;
V_2 = F_16 ( V_37 -> V_38 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_21 ( struct V_36 * V_37 , T_1 V_3 ,
T_1 V_12 , T_1 * V_13 , T_1 V_14 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 = F_18 ( V_37 ) ;
if ( ( V_7 <= V_3 ) ||
! F_13 ( V_41 -> V_42 , V_3 ,
V_12 , ( V_12 + V_14 - 1 ) ) )
return - V_8 ;
V_2 = F_16 ( V_37 -> V_38 ) ;
return F_5 ( V_2 , V_3 , V_12 , V_13 ,
V_14 ) ;
}
static int
F_22 ( struct V_36 * V_37 , T_1 * V_43 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_37 -> V_38 ) ;
if ( ! V_2 -> V_44 )
return - V_45 ;
memcpy ( V_43 , V_2 -> V_46 , V_47 ) ;
return 0 ;
}
static int T_2 F_23 ( struct V_1 * V_2 ,
struct V_48 * V_49 , unsigned int V_50 )
{
int V_6 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_50 ; V_22 ++ ) {
V_6 = F_7 ( V_2 ,
V_49 [ V_22 ] . V_3 ,
V_49 [ V_22 ] . V_4 ,
0xFF , V_49 [ V_22 ] . V_51 ) ;
if ( V_6 )
goto V_52;
if ( ( V_49 [ V_22 ] . V_3 == V_53 ) &&
( V_54 <= V_49 [ V_22 ] . V_4 ) &&
( V_49 [ V_22 ] . V_4 <= V_55 ) ) {
V_2 -> V_56 [ V_49 [ V_22 ] . V_4 - V_54 ] =
V_49 [ V_22 ] . V_51 ;
}
}
V_52:
return V_6 ;
}
static int T_2 F_24 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_57 * V_58 =
V_41 -> V_37 . V_59 ;
int V_6 ;
int V_22 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 ) {
F_26 ( & V_41 -> V_37 ,
L_1 ) ;
return - V_61 ;
}
F_27 ( & V_2 -> V_9 ) ;
F_27 ( & V_2 -> V_62 ) ;
V_2 -> V_37 = & V_41 -> V_37 ;
F_28 ( V_41 , V_2 ) ;
V_6 = F_1 ( V_2 ,
V_63 ,
V_64 , & V_2 -> V_39 ) ;
if ( V_6 ) {
F_26 ( & V_41 -> V_37 , L_2
L_3 ) ;
goto V_65;
}
for ( V_22 = 0 ; V_66 [ V_22 ] . V_42 != 0x0 ; V_22 ++ ) {
if ( V_66 [ V_22 ] . V_42 == V_2 -> V_39 ) {
snprintf ( & V_2 -> V_67 [ 0 ] , sizeof( V_2 -> V_67 ) - 1 ,
L_4 , V_66 [ V_22 ] . V_68 ) ;
break;
}
}
if ( V_66 [ V_22 ] . V_42 == 0x0 ) {
F_26 ( & V_41 -> V_37 , L_5 ,
V_2 -> V_39 ) ;
F_26 ( & V_41 -> V_37 , L_6 ) ;
goto V_65;
}
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ ) {
T_1 V_70 = V_71 + V_22 ;
T_1 V_72 = V_73 + V_22 ;
T_1 V_74 ;
F_1 ( V_2 , V_53 ,
V_70 , & V_74 ) ;
F_9 ( V_2 , V_53 , V_72 , 0xff ) ;
V_2 -> V_56 [ V_22 ] = V_2 -> V_75 [ V_22 ] = 0xff ;
}
V_6 = F_29 ( & V_41 -> V_37 , & V_76 ) ;
if ( V_6 ) {
F_26 ( & V_41 -> V_37 , L_7 ) ;
goto V_65;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_77 [ V_22 ] . V_59 = V_58 -> V_78 [ V_22 ] ;
V_77 [ V_22 ] . V_79 =
sizeof( V_58 -> V_78 [ V_22 ] ) ;
}
V_6 = F_30 ( & V_41 -> V_37 , 0 , V_77 ,
F_31 ( V_77 ) , NULL ,
V_58 -> V_80 . V_81 ) ;
if ( V_6 ) {
F_26 ( & V_41 -> V_37 , L_8 ) ;
goto V_65;
}
V_6 = F_23 ( V_2 , V_58 -> V_82 ,
V_58 -> V_83 ) ;
if ( V_6 ) {
F_26 ( & V_41 -> V_37 , L_9 ) ;
goto V_65;
}
F_32 ( V_2 ) ;
F_33 ( & V_41 -> V_37 , L_10 , & V_2 -> V_67 [ 0 ] ) ;
return 0 ;
V_65:
F_34 ( V_2 ) ;
return V_6 ;
}
static int T_3 F_35 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_36 ( V_41 ) ;
F_37 () ;
F_38 ( & V_41 -> V_37 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_84 , F_24 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_84 ) ;
}
