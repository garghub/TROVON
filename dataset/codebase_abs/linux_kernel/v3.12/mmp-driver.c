static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
F_4 ( & V_5 ) ;
F_5 ( & V_4 -> V_6 , & V_7 ) ;
F_6 ( & V_5 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
F_4 ( & V_5 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_6 ( & V_5 ) ;
}
static struct V_1 * F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_4 ;
F_4 ( & V_5 ) ;
F_10 (cam, &mmpcam_devices, devlist) {
if ( V_4 -> V_9 == V_9 ) {
F_6 ( & V_5 ) ;
return V_4 ;
}
}
F_6 ( & V_5 ) ;
return NULL ;
}
static void F_11 ( struct V_2 * V_3 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ! F_12 ( V_3 -> V_12 [ V_10 ] ) )
F_13 ( V_3 -> V_12 [ V_10 ] ) ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
int V_10 ;
for ( V_10 = V_11 - 1 ; V_10 >= 0 ; V_10 -- ) {
if ( ! F_12 ( V_3 -> V_12 [ V_10 ] ) )
F_15 ( V_3 -> V_12 [ V_10 ] ) ;
}
}
static void F_16 ( struct V_1 * V_4 )
{
F_17 ( 0x3f , V_4 -> V_13 + V_14 ) ;
F_17 ( 0x3805b , V_4 -> V_13 + V_15 ) ;
F_18 ( 1 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
if ( V_3 -> V_18 == V_19 ) {
V_4 -> V_20 = F_20 ( V_3 -> V_21 , L_1 ) ;
if ( ( F_12 ( V_4 -> V_20 ) && V_3 -> V_22 [ 2 ] == 0 ) )
return F_21 ( V_4 -> V_20 ) ;
}
F_16 ( V_4 ) ;
F_22 ( V_3 , V_23 , 0x60000002 ) ;
V_17 = V_4 -> V_9 -> V_21 . V_24 ;
F_23 ( V_17 -> V_25 , 1 ) ;
F_18 ( 5 ) ;
F_24 ( V_3 , V_26 , 0x10000000 ) ;
F_23 ( V_17 -> V_27 , 0 ) ;
F_18 ( 5 ) ;
F_23 ( V_17 -> V_27 , 1 ) ;
F_18 ( 5 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
F_17 ( 0 , V_4 -> V_13 + V_14 ) ;
F_17 ( 0 , V_4 -> V_13 + V_15 ) ;
V_17 = V_4 -> V_9 -> V_21 . V_24 ;
F_23 ( V_17 -> V_25 , 0 ) ;
F_23 ( V_17 -> V_27 , 0 ) ;
if ( V_3 -> V_18 == V_19 && ! F_12 ( V_4 -> V_20 ) ) {
if ( V_4 -> V_20 )
F_26 ( V_3 -> V_21 , V_4 -> V_20 ) ;
V_4 -> V_20 = NULL ;
}
F_14 ( V_3 ) ;
}
void F_27 ( struct V_2 * V_3 )
{
unsigned long V_28 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_3 -> V_29 ) {
V_28 = F_28 ( V_4 -> V_13 + V_30 ) ;
F_17 ( V_28 & ~ 0x2 , V_4 -> V_13 + V_30 ) ;
F_17 ( V_28 | 0x2 , V_4 -> V_13 + V_30 ) ;
} else {
V_28 = F_28 ( V_4 -> V_13 + V_15 ) ;
F_17 ( V_28 & ~ 0x2 , V_4 -> V_13 + V_15 ) ;
F_17 ( V_28 | 0x2 , V_4 -> V_13 + V_15 ) ;
}
}
void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_4 -> V_9 -> V_21 . V_24 ;
struct V_31 * V_21 = & V_4 -> V_9 -> V_21 ;
unsigned long V_32 ;
switch ( V_17 -> V_33 ) {
case V_34 :
V_17 -> V_22 [ 0 ] =
( ( ( 1 + ( V_17 -> V_35 * 80 ) / 1000 ) & 0xff ) << 8 )
| ( 1 + V_17 -> V_35 * 35 / 1000 ) ;
break;
case V_36 :
V_17 -> V_22 [ 0 ] =
( ( ( 2 + ( V_17 -> V_35 * 110 ) / 1000 ) & 0xff ) << 8 )
| ( 1 + V_17 -> V_35 * 35 / 1000 ) ;
break;
default:
F_30 ( V_21 , L_2 ) ;
}
if ( F_12 ( V_4 -> V_20 ) )
return;
V_32 = ( F_31 ( V_4 -> V_20 ) / 1000000 ) / 12 ;
V_17 -> V_22 [ 2 ] =
( ( ( ( 534 * V_32 ) / 2000 - 1 ) & 0xff ) << 8 )
| ( ( ( 38 * V_32 ) / 1000 - 1 ) & 0xff ) ;
F_30 ( V_21 , L_3 ,
V_17 -> V_22 [ 0 ] , V_17 -> V_22 [ 1 ] , V_17 -> V_22 [ 2 ] ) ;
}
static T_1 F_32 ( int V_37 , void * V_38 )
{
struct V_2 * V_3 = V_38 ;
unsigned int V_39 , V_40 ;
F_33 ( & V_3 -> V_41 ) ;
V_39 = F_34 ( V_3 , V_42 ) ;
V_40 = F_35 ( V_3 , V_39 ) ;
F_36 ( & V_3 -> V_41 ) ;
return F_37 ( V_40 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ! F_12 ( V_3 -> V_12 [ V_10 ] ) ) {
if ( V_3 -> V_12 [ V_10 ] )
F_26 ( V_3 -> V_21 , V_3 -> V_12 [ V_10 ] ) ;
}
V_3 -> V_12 [ V_10 ] = NULL ;
}
}
static void F_39 ( struct V_2 * V_3 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_43 [ V_10 ] != NULL ) {
V_3 -> V_12 [ V_10 ] = F_20 ( V_3 -> V_21 , V_43 [ V_10 ] ) ;
if ( F_12 ( V_3 -> V_12 [ V_10 ] ) )
F_40 ( V_3 -> V_21 , L_4 ,
V_43 [ V_10 ] ) ;
}
}
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_44 * V_45 ;
struct V_16 * V_17 ;
int V_46 ;
V_17 = V_9 -> V_21 . V_24 ;
if ( ! V_17 )
return - V_47 ;
V_4 = F_42 ( & V_9 -> V_21 , sizeof( * V_4 ) , V_48 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_20 = NULL ;
F_43 ( & V_4 -> V_6 ) ;
V_3 = & V_4 -> V_3 ;
V_3 -> V_50 = F_19 ;
V_3 -> V_51 = F_25 ;
V_3 -> V_52 = F_27 ;
V_3 -> V_53 = F_29 ;
V_3 -> V_21 = & V_9 -> V_21 ;
V_3 -> V_54 = 0 ;
V_3 -> V_29 = V_9 -> V_55 ;
V_3 -> V_56 = V_17 -> V_56 ;
V_3 -> V_57 = V_17 -> V_57 ;
V_3 -> V_58 = V_17 -> V_58 ;
V_3 -> V_18 = V_17 -> V_18 ;
V_3 -> V_22 = V_17 -> V_22 ;
V_3 -> V_59 = false ;
V_3 -> V_60 = V_17 -> V_60 ;
V_3 -> V_61 = V_62 ;
V_3 -> V_63 = V_64 ;
F_44 ( & V_3 -> V_41 ) ;
V_45 = F_45 ( V_9 , V_65 , 0 ) ;
V_3 -> V_66 = F_46 ( & V_9 -> V_21 , V_45 ) ;
if ( F_12 ( V_3 -> V_66 ) )
return F_21 ( V_3 -> V_66 ) ;
V_3 -> V_67 = F_47 ( V_45 ) ;
V_45 = F_45 ( V_9 , V_65 , 1 ) ;
V_4 -> V_13 = F_46 ( & V_9 -> V_21 , V_45 ) ;
if ( F_12 ( V_4 -> V_13 ) )
return F_21 ( V_4 -> V_13 ) ;
V_3 -> V_68 = F_48 ( V_17 -> V_69 ) ;
if ( V_3 -> V_68 == NULL ) {
F_49 ( & V_9 -> V_21 , L_5 ) ;
return - V_47 ;
}
V_46 = F_50 ( & V_9 -> V_21 , V_17 -> V_25 ,
L_6 ) ;
if ( V_46 ) {
F_49 ( & V_9 -> V_21 , L_7 ,
V_17 -> V_25 ) ;
return V_46 ;
}
F_51 ( V_17 -> V_25 , 0 ) ;
V_46 = F_50 ( & V_9 -> V_21 , V_17 -> V_27 ,
L_8 ) ;
if ( V_46 ) {
F_49 ( & V_9 -> V_21 , L_9 ,
V_17 -> V_27 ) ;
return V_46 ;
}
F_51 ( V_17 -> V_27 , 0 ) ;
F_39 ( V_3 ) ;
V_46 = F_19 ( V_3 ) ;
if ( V_46 )
goto V_70;
V_46 = F_52 ( V_3 ) ;
if ( V_46 )
goto V_71;
V_45 = F_45 ( V_9 , V_72 , 0 ) ;
if ( V_45 == NULL ) {
V_46 = - V_47 ;
goto V_73;
}
V_4 -> V_37 = V_45 -> V_74 ;
V_46 = F_53 ( & V_9 -> V_21 , V_4 -> V_37 , F_32 , V_75 ,
L_10 , V_3 ) ;
if ( V_46 == 0 ) {
F_3 ( V_4 ) ;
return 0 ;
}
V_73:
F_54 ( V_3 ) ;
V_71:
F_25 ( V_3 ) ;
V_70:
F_38 ( V_3 ) ;
return V_46 ;
}
static int F_55 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_16 * V_17 ;
F_7 ( V_4 ) ;
F_56 ( V_4 -> V_37 , V_3 ) ;
F_54 ( V_3 ) ;
F_25 ( V_3 ) ;
V_17 = V_4 -> V_9 -> V_21 . V_24 ;
F_57 ( V_17 -> V_27 ) ;
F_57 ( V_17 -> V_25 ) ;
F_38 ( V_3 ) ;
F_58 ( V_4 -> V_13 ) ;
F_58 ( V_3 -> V_66 ) ;
F_59 ( V_4 ) ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
if ( V_4 == NULL )
return - V_47 ;
return F_55 ( V_4 ) ;
}
static int F_61 ( struct V_8 * V_9 , T_2 V_76 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
if ( V_76 . V_77 != V_78 )
return 0 ;
F_62 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
F_16 ( V_4 ) ;
return F_64 ( & V_4 -> V_3 ) ;
}
static int T_3 F_65 ( void )
{
F_66 ( & V_5 ) ;
return F_67 ( & V_79 ) ;
}
static void T_4 F_68 ( void )
{
F_69 ( & V_79 ) ;
if ( ! F_70 ( & V_7 ) )
F_71 ( V_80 L_11 ) ;
}
