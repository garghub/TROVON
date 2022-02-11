static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 V_9 [ 2 ] ;
T_1 V_10 = V_3 & 0xff ;
int error ;
if ( V_3 <= V_11 && V_3 + V_4 > V_11 )
F_2 () ;
V_9 [ 0 ] . V_12 = V_7 -> V_12 ;
V_9 [ 0 ] . V_13 = V_14 | V_15 ;
V_9 [ 0 ] . V_4 = 1 ;
V_9 [ 0 ] . V_10 = & V_10 ;
V_9 [ 1 ] . V_12 = V_7 -> V_12 ;
V_9 [ 1 ] . V_13 = V_16 ;
V_9 [ 1 ] . V_4 = V_4 ;
V_9 [ 1 ] . V_10 = V_5 ;
error = F_3 ( V_7 -> V_17 , V_9 , 2 ) ;
if ( error != 2 ) {
F_4 ( & V_7 -> V_18 ,
L_1 , V_19 , error ) ;
return error < 0 ? error : - V_20 ;
}
F_5 ( V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_5 ;
int error ;
if ( V_3 == V_11 )
return V_2 -> V_22 ;
error = F_1 ( V_2 , V_3 , 1 , & V_5 ) ;
return error < 0 ? error : V_5 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_10 [ 2 ] ;
int error ;
V_10 [ 0 ] = V_3 & 0xff ;
V_10 [ 1 ] = V_5 & 0xff ;
error = F_8 ( V_7 , V_10 , 2 ) ;
if ( error != 2 ) {
F_4 ( & V_7 -> V_18 ,
L_2 , V_19 , error ) ;
return error < 0 ? error : - V_20 ;
}
F_5 ( V_21 ) ;
if ( V_3 == V_11 )
V_2 -> V_22 = V_5 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
const struct V_25 * V_26 = V_2 -> V_26 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_27 * V_27 = V_2 -> V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
unsigned int V_30 ;
if ( V_24 -> V_28 > V_31 ) {
F_4 ( & V_7 -> V_18 , L_3 , V_24 -> V_28 ) ;
return;
}
if ( V_24 -> type != V_32 ) {
F_4 ( & V_7 -> V_18 , L_4 , V_24 -> type ) ;
return;
}
V_28 = V_24 -> V_28 - 1 ;
V_29 = V_24 -> V_33 | V_24 -> V_34 << 8 ;
V_30 = V_24 -> V_35 | V_24 -> V_36 << 8 ;
if ( V_29 > V_26 -> V_37 || V_30 > V_26 -> V_38 ) {
F_10 ( & V_7 -> V_18 ,
L_5 , V_29 , V_30 ) ;
return;
}
if ( V_26 -> V_39 )
V_29 = V_26 -> V_37 - V_29 ;
if ( V_26 -> V_40 )
V_30 = V_26 -> V_38 - V_30 ;
F_10 ( & V_7 -> V_18 ,
L_6 ,
V_28 , V_24 -> type , V_24 -> V_41 ,
V_29 , V_30 , V_24 -> V_42 , V_24 -> V_43 ) ;
F_11 ( V_27 , V_28 ) ;
F_12 ( V_27 , V_44 , V_24 -> V_41 ) ;
if ( V_24 -> V_41 ) {
F_13 ( V_27 , V_45 , V_24 -> V_42 ) ;
F_13 ( V_27 , V_46 , V_29 ) ;
F_13 ( V_27 , V_47 , V_30 ) ;
F_13 ( V_27 , V_48 , V_24 -> V_43 ) ;
}
}
static T_2 F_14 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
struct V_27 * V_27 = V_2 -> V_27 ;
struct V_23 V_24 [ V_31 ] ;
int V_51 ;
int V_52 ;
int V_53 ;
int error ;
F_15 ( & V_27 -> V_54 ) ;
if ( ! V_27 -> V_55 ) {
F_16 ( & V_27 -> V_54 ) ;
goto V_56;
}
F_16 ( & V_27 -> V_54 ) ;
V_51 = F_6 ( V_2 , V_57 ) ;
if ( V_51 <= 0 )
goto V_56;
V_52 = V_51 / V_58 ;
error = F_1 ( V_2 , V_59 , V_51 ,
( T_1 * ) V_24 ) ;
if ( error < 0 )
goto V_56;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
F_9 ( V_2 , V_24 + V_53 ) ;
F_17 ( V_2 -> V_27 , true ) ;
F_18 ( V_2 -> V_27 ) ;
V_56:
return V_60 ;
}
static int F_19 ( struct V_1 * V_2 , bool V_61 )
{
int V_5 ;
V_5 = F_6 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 &= ~ V_62 ;
if ( V_61 )
V_5 |= V_63 ;
return F_7 ( V_2 , V_11 , V_5 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_64 * V_18 = & V_2 -> V_7 -> V_18 ;
T_1 V_10 [ 6 ] ;
int error ;
error = F_1 ( V_2 , V_65 , 6 , V_10 ) ;
if ( error < 0 )
return error ;
F_21 ( V_18 , L_7 ,
V_10 [ 0 ] , V_10 [ 1 ] , V_10 [ 3 ] ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_26 ;
int V_5 ;
int error ;
error = F_20 ( V_2 ) ;
if ( error < 0 )
return error ;
error = F_19 ( V_2 , true ) ;
if ( error < 0 )
return error ;
V_5 = ( V_26 -> V_37 >> 8 ) & 0xf ;
V_5 |= ( ( V_26 -> V_38 >> 8 ) & 0xf ) << 4 ;
error = F_7 ( V_2 , V_66 , V_5 ) ;
if ( error < 0 )
return error ;
V_5 = V_26 -> V_37 & 0xff ;
error = F_7 ( V_2 , V_67 , V_5 ) ;
if ( error < 0 )
return error ;
V_5 = V_26 -> V_38 & 0xff ;
error = F_7 ( V_2 , V_68 , V_5 ) ;
if ( error < 0 )
return error ;
if ( V_26 -> V_69 ) {
error = F_7 ( V_2 , V_70 ,
V_26 -> V_69 ) ;
if ( error < 0 )
return error ;
}
if ( V_26 -> V_71 ) {
error = F_7 ( V_2 , V_72 ,
V_26 -> V_71 ) ;
if ( error < 0 )
return error ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int error ;
if ( V_2 -> V_73 )
F_24 ( V_2 -> V_73 ) ;
if ( V_2 -> V_74 )
F_24 ( V_2 -> V_74 ) ;
F_25 ( V_75 ) ;
error = F_22 ( V_2 ) ;
if ( error < 0 )
return error ;
if ( V_2 -> V_26 -> V_76 )
V_2 -> V_26 -> V_76 ( true ) ;
F_26 ( V_7 -> V_49 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_28 ( V_7 -> V_49 ) ;
if ( V_2 -> V_26 -> V_76 )
V_2 -> V_26 -> V_76 ( false ) ;
if ( V_2 -> V_74 )
F_29 ( V_2 -> V_74 ) ;
if ( V_2 -> V_73 )
F_29 ( V_2 -> V_73 ) ;
}
static int F_30 ( struct V_27 * V_18 )
{
struct V_1 * V_2 = F_31 ( V_18 ) ;
return F_23 ( V_2 ) ;
}
static void F_32 ( struct V_27 * V_18 )
{
struct V_1 * V_2 = F_31 ( V_18 ) ;
F_27 ( V_2 ) ;
}
static int T_3 F_33 ( struct V_6 * V_7 ,
const struct V_77 * V_28 )
{
struct V_1 * V_2 ;
struct V_27 * V_27 ;
int error ;
if ( ! V_7 -> V_18 . V_78 ) {
F_4 ( & V_7 -> V_18 , L_8 ) ;
return - V_79 ;
}
if ( ! F_34 ( V_7 -> V_17 ,
V_80 ) ) {
F_4 ( & V_7 -> V_18 ,
L_9 ) ;
return - V_81 ;
}
V_2 = F_35 ( sizeof( struct V_1 ) , V_82 ) ;
V_27 = F_36 () ;
if ( ! V_2 || ! V_27 ) {
F_4 ( & V_7 -> V_18 , L_10 ) ;
error = - V_83 ;
goto V_84;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_26 = V_7 -> V_18 . V_78 ;
V_27 -> V_85 = L_11 ;
V_27 -> V_28 . V_86 = V_87 ;
V_27 -> V_18 . V_88 = & V_7 -> V_18 ;
V_27 -> V_89 = F_30 ;
V_27 -> V_90 = F_32 ;
F_37 ( V_91 , V_27 -> V_92 ) ;
F_37 ( V_93 , V_27 -> V_92 ) ;
F_37 ( V_94 , V_27 -> V_95 ) ;
F_38 ( V_27 , V_96 , 0 , V_2 -> V_26 -> V_37 , 0 , 0 ) ;
F_38 ( V_27 , V_97 , 0 , V_2 -> V_26 -> V_38 , 0 , 0 ) ;
F_39 ( V_27 , V_31 , 0 ) ;
F_38 ( V_27 , V_45 ,
0 , V_98 , 0 , 0 ) ;
F_38 ( V_27 , V_46 ,
0 , V_2 -> V_26 -> V_37 , 0 , 0 ) ;
F_38 ( V_27 , V_47 ,
0 , V_2 -> V_26 -> V_38 , 0 , 0 ) ;
F_38 ( V_27 , V_48 , 0 , 255 , 0 , 0 ) ;
F_40 ( V_27 , V_2 ) ;
F_41 ( V_7 , V_2 ) ;
V_2 -> V_73 = F_42 ( & V_7 -> V_18 , L_12 ) ;
if ( F_43 ( V_2 -> V_73 ) ) {
error = F_44 ( V_2 -> V_73 ) ;
F_4 ( & V_7 -> V_18 ,
L_13 , error ) ;
goto V_84;
}
V_2 -> V_74 = F_42 ( & V_7 -> V_18 , L_14 ) ;
if ( F_43 ( V_2 -> V_74 ) ) {
error = F_44 ( V_2 -> V_74 ) ;
F_4 ( & V_7 -> V_18 ,
L_15 , error ) ;
goto V_99;
}
error = F_45 ( V_7 -> V_49 , NULL , F_14 ,
V_100 | V_101 , L_16 , V_2 ) ;
if ( error ) {
F_4 ( & V_7 -> V_18 , L_17 ) ;
goto V_102;
}
F_28 ( V_7 -> V_49 ) ;
error = F_46 ( V_2 -> V_27 ) ;
if ( error )
goto V_103;
return 0 ;
V_103:
F_47 ( V_7 -> V_49 , V_2 ) ;
V_102:
F_48 ( V_2 -> V_74 ) ;
V_99:
F_48 ( V_2 -> V_73 ) ;
V_84:
F_49 ( V_27 ) ;
F_50 ( V_2 ) ;
return error ;
}
static int T_4 F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_52 ( V_7 ) ;
F_47 ( V_7 -> V_49 , V_2 ) ;
F_48 ( V_2 -> V_74 ) ;
F_48 ( V_2 -> V_73 ) ;
F_53 ( V_2 -> V_27 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_64 * V_18 )
{
struct V_6 * V_7 = F_55 ( V_18 ) ;
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_27 * V_27 = V_2 -> V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_31 ; V_28 ++ ) {
F_11 ( V_27 , V_28 ) ;
F_12 ( V_27 , V_44 , false ) ;
}
F_17 ( V_27 , true ) ;
F_18 ( V_27 ) ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_55 )
F_27 ( V_2 ) ;
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
}
static int F_56 ( struct V_64 * V_18 )
{
struct V_6 * V_7 = F_55 ( V_18 ) ;
struct V_1 * V_2 = F_52 ( V_7 ) ;
struct V_27 * V_27 = V_2 -> V_27 ;
int error ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_55 ) {
error = F_23 ( V_2 ) ;
if ( error < 0 ) {
F_16 ( & V_27 -> V_54 ) ;
return error ;
}
}
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
}
