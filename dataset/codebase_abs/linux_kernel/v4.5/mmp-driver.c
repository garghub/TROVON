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
F_16 ( V_4 ) ;
F_20 ( V_3 , V_18 , 0x60000002 ) ;
V_17 = V_4 -> V_9 -> V_19 . V_20 ;
F_21 ( V_17 -> V_21 , 1 ) ;
F_18 ( 5 ) ;
F_22 ( V_3 , V_22 , 0x10000000 ) ;
F_21 ( V_17 -> V_23 , 0 ) ;
F_18 ( 5 ) ;
F_21 ( V_17 -> V_23 , 1 ) ;
F_18 ( 5 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
F_17 ( 0 , V_4 -> V_13 + V_14 ) ;
F_17 ( 0 , V_4 -> V_13 + V_15 ) ;
V_17 = V_4 -> V_9 -> V_19 . V_20 ;
F_21 ( V_17 -> V_21 , 0 ) ;
F_21 ( V_17 -> V_23 , 0 ) ;
F_14 ( V_3 ) ;
}
void F_24 ( struct V_2 * V_3 )
{
unsigned long V_24 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_3 -> V_25 ) {
V_24 = F_25 ( V_4 -> V_13 + V_26 ) ;
F_17 ( V_24 & ~ 0x2 , V_4 -> V_13 + V_26 ) ;
F_17 ( V_24 | 0x2 , V_4 -> V_13 + V_26 ) ;
} else {
V_24 = F_25 ( V_4 -> V_13 + V_15 ) ;
F_17 ( V_24 & ~ 0x2 , V_4 -> V_13 + V_15 ) ;
F_17 ( V_24 | 0x2 , V_4 -> V_13 + V_15 ) ;
}
}
void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_4 -> V_9 -> V_19 . V_20 ;
struct V_27 * V_19 = & V_4 -> V_9 -> V_19 ;
unsigned long V_28 ;
switch ( V_17 -> V_29 ) {
case V_30 :
V_17 -> V_31 [ 0 ] =
( ( ( 1 + ( V_17 -> V_32 * 80 ) / 1000 ) & 0xff ) << 8 )
| ( 1 + V_17 -> V_32 * 35 / 1000 ) ;
break;
case V_33 :
V_17 -> V_31 [ 0 ] =
( ( ( 2 + ( V_17 -> V_32 * 110 ) / 1000 ) & 0xff ) << 8 )
| ( 1 + V_17 -> V_32 * 35 / 1000 ) ;
break;
default:
F_27 ( V_19 , L_1 ) ;
}
if ( F_12 ( V_4 -> V_34 ) )
return;
F_13 ( V_4 -> V_34 ) ;
V_28 = ( F_28 ( V_4 -> V_34 ) / 1000000 ) / 12 ;
F_15 ( V_4 -> V_34 ) ;
V_17 -> V_31 [ 2 ] =
( ( ( ( 534 * V_28 ) / 2000 - 1 ) & 0xff ) << 8 )
| ( ( ( 38 * V_28 ) / 1000 - 1 ) & 0xff ) ;
F_27 ( V_19 , L_2 ,
V_17 -> V_31 [ 0 ] , V_17 -> V_31 [ 1 ] , V_17 -> V_31 [ 2 ] ) ;
}
static T_1 F_29 ( int V_35 , void * V_36 )
{
struct V_2 * V_3 = V_36 ;
unsigned int V_37 , V_38 ;
F_30 ( & V_3 -> V_39 ) ;
V_37 = F_31 ( V_3 , V_40 ) ;
V_38 = F_32 ( V_3 , V_37 ) ;
F_33 ( & V_3 -> V_39 ) ;
return F_34 ( V_38 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_41 [ V_10 ] != NULL ) {
V_3 -> V_12 [ V_10 ] = F_36 ( V_3 -> V_19 , V_41 [ V_10 ] ) ;
if ( F_12 ( V_3 -> V_12 [ V_10 ] ) )
F_37 ( V_3 -> V_19 , L_3 ,
V_41 [ V_10 ] ) ;
}
}
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
struct V_16 * V_17 ;
int V_44 ;
V_17 = V_9 -> V_19 . V_20 ;
if ( ! V_17 )
return - V_45 ;
V_4 = F_39 ( & V_9 -> V_19 , sizeof( * V_4 ) , V_46 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_9 = V_9 ;
F_40 ( & V_4 -> V_6 ) ;
V_3 = & V_4 -> V_3 ;
V_3 -> V_48 = F_19 ;
V_3 -> V_49 = F_23 ;
V_3 -> V_50 = F_24 ;
V_3 -> V_51 = F_26 ;
V_3 -> V_19 = & V_9 -> V_19 ;
V_3 -> V_52 = 0 ;
V_3 -> V_25 = V_9 -> V_53 ;
V_3 -> V_54 = V_17 -> V_54 ;
V_3 -> V_55 = V_17 -> V_55 ;
V_3 -> V_56 = V_17 -> V_56 ;
V_3 -> V_57 = V_17 -> V_57 ;
V_3 -> V_31 = V_17 -> V_31 ;
if ( V_3 -> V_57 == V_58 ) {
V_4 -> V_34 = F_36 ( V_3 -> V_19 , L_4 ) ;
if ( ( F_12 ( V_4 -> V_34 ) && V_3 -> V_31 [ 2 ] == 0 ) )
return F_41 ( V_4 -> V_34 ) ;
}
V_3 -> V_59 = false ;
V_3 -> V_60 = V_17 -> V_60 ;
V_3 -> V_61 = V_62 ;
V_3 -> V_63 = V_64 ;
F_42 ( V_3 -> V_65 , L_5 , sizeof( V_3 -> V_65 ) ) ;
F_43 ( & V_3 -> V_39 ) ;
V_43 = F_44 ( V_9 , V_66 , 0 ) ;
V_3 -> V_67 = F_45 ( & V_9 -> V_19 , V_43 ) ;
if ( F_12 ( V_3 -> V_67 ) )
return F_41 ( V_3 -> V_67 ) ;
V_3 -> V_68 = F_46 ( V_43 ) ;
V_43 = F_44 ( V_9 , V_66 , 1 ) ;
V_4 -> V_13 = F_45 ( & V_9 -> V_19 , V_43 ) ;
if ( F_12 ( V_4 -> V_13 ) )
return F_41 ( V_4 -> V_13 ) ;
V_3 -> V_69 = F_47 ( V_17 -> V_70 ) ;
if ( V_3 -> V_69 == NULL ) {
F_48 ( & V_9 -> V_19 , L_6 ) ;
return - V_45 ;
}
V_44 = F_49 ( & V_9 -> V_19 , V_17 -> V_21 ,
L_7 ) ;
if ( V_44 ) {
F_48 ( & V_9 -> V_19 , L_8 ,
V_17 -> V_21 ) ;
return V_44 ;
}
F_50 ( V_17 -> V_21 , 0 ) ;
V_44 = F_49 ( & V_9 -> V_19 , V_17 -> V_23 ,
L_9 ) ;
if ( V_44 ) {
F_48 ( & V_9 -> V_19 , L_10 ,
V_17 -> V_23 ) ;
return V_44 ;
}
F_50 ( V_17 -> V_23 , 0 ) ;
F_35 ( V_3 ) ;
V_44 = F_19 ( V_3 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_51 ( V_3 ) ;
if ( V_44 )
goto V_71;
V_43 = F_44 ( V_9 , V_72 , 0 ) ;
if ( V_43 == NULL ) {
V_44 = - V_45 ;
goto V_73;
}
V_4 -> V_35 = V_43 -> V_74 ;
V_44 = F_52 ( & V_9 -> V_19 , V_4 -> V_35 , F_29 , V_75 ,
L_11 , V_3 ) ;
if ( V_44 == 0 ) {
F_3 ( V_4 ) ;
return 0 ;
}
V_73:
F_53 ( V_3 ) ;
V_71:
F_23 ( V_3 ) ;
return V_44 ;
}
static int F_54 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
F_7 ( V_4 ) ;
F_53 ( V_3 ) ;
F_23 ( V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_9 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
if ( V_4 == NULL )
return - V_45 ;
return F_54 ( V_4 ) ;
}
static int F_56 ( struct V_8 * V_9 , T_2 V_76 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
if ( V_76 . V_77 != V_78 )
return 0 ;
F_57 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_1 * V_4 = F_9 ( V_9 ) ;
F_16 ( V_4 ) ;
return F_59 ( & V_4 -> V_3 ) ;
}
static int T_3 F_60 ( void )
{
F_61 ( & V_5 ) ;
return F_62 ( & V_79 ) ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_79 ) ;
if ( ! F_65 ( & V_7 ) )
F_66 ( V_80 L_12 ) ;
}
