static void T_1 F_1 (
const struct V_1 * V_2 , const char * V_3 , int line )
{
F_2 ( L_1 , V_3 , line , V_2 -> V_4 ) ;
F_2 ( L_2 , V_3 , line , V_2 -> V_5 ) ;
F_2 ( L_3 , V_3 , line , V_2 -> V_6 ) ;
F_2 ( L_4 , V_3 , line , V_2 -> V_7 ) ;
F_2 ( L_5 , V_3 , line , V_2 -> V_8 ) ;
}
static int F_3 ( struct V_9 * V_10 ,
const struct V_1 * V_11 , const void * V_12 )
{
int V_13 ;
F_4 ( V_11 -> V_4 != 1 ) ;
F_4 ( V_11 -> V_5 != 16 ) ;
F_4 ( V_11 -> V_6 != 8 && V_11 -> V_6 != 16 ) ;
F_4 ( V_11 -> V_7 > 8 ) ;
V_13 = F_5 ( V_10 , V_11 ,
sizeof( struct V_1 ) ) ;
if ( ! V_13 )
V_13 = F_5 ( V_10 , V_12 , V_11 -> V_6 ) ;
return V_13 ;
}
static int F_6 ( struct V_9 * V_10 ,
enum V_14 V_15 )
{
struct V_1 V_11 ;
struct {
T_2 V_4 ;
T_2 V_16 [ 3 ] ;
T_3 V_17 ;
} V_12 ;
F_7 ( sizeof( V_12 ) != 8 ) ;
F_8 ( & V_10 -> V_18 , L_6 , V_19 , __LINE__ , V_15 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_4 = 1 ;
V_11 . V_5 = 16 ;
V_11 . V_6 = 16 ;
V_11 . V_7 = V_20 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_4 = 1 ;
V_12 . V_17 = V_15 ;
return F_3 ( V_10 , & V_11 , & V_12 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
enum V_21 V_22 ,
enum V_23 V_24 )
{
struct V_1 V_11 ;
struct {
T_2 V_4 ;
T_2 type ;
T_2 V_25 ;
T_2 V_16 ;
T_3 V_24 ;
T_2 V_26 [ 8 ] ;
} V_12 ;
F_7 ( sizeof( V_12 ) != 16 ) ;
F_8 ( & V_10 -> V_18 , L_7 , V_19 , __LINE__ , V_22 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_4 = 1 ;
V_11 . V_5 = 16 ;
V_11 . V_6 = 16 ;
V_11 . V_7 = V_27 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_4 = 3 ;
V_12 . type = V_22 ;
V_12 . V_25 = 3 ;
V_12 . V_24 = V_24 ;
return F_3 ( V_10 , & V_11 , & V_12 ) ;
}
static int F_10 (
struct V_9 * V_10 )
{
struct V_1 V_11 ;
struct {
T_2 V_4 ;
T_2 type ;
T_2 V_25 ;
T_2 V_16 [ 13 ] ;
} V_12 ;
F_7 ( sizeof( V_12 ) != 16 ) ;
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_4 = 1 ;
V_11 . V_5 = 16 ;
V_11 . V_6 = 16 ;
V_11 . V_7 = V_28 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_4 = 1 ;
V_12 . type = 1 ;
V_12 . V_25 = 0 ;
return F_3 ( V_10 , & V_11 , & V_12 ) ;
}
static int F_11 ( struct V_9 * V_10 ,
T_4 V_29 )
{
struct V_1 V_11 ;
struct {
T_2 V_4 ;
T_2 V_16 [ 3 ] ;
T_2 V_29 ;
T_2 V_26 [ 11 ] ;
} V_12 ;
F_7 ( sizeof( V_12 ) != 16 ) ;
F_8 ( & V_10 -> V_18 , L_9 , V_19 , __LINE__ ,
( V_29 ? L_10 : L_11 ) ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_4 = 1 ;
V_11 . V_5 = 16 ;
V_11 . V_6 = 16 ;
V_11 . V_7 = V_30 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_4 = 1 ;
V_12 . V_29 = V_29 ;
return F_3 ( V_10 , & V_11 , & V_12 ) ;
}
static int F_12 ( struct V_9 * V_10 )
{
int V_13 ;
struct {
T_2 V_4 ;
T_2 type ;
T_2 V_16 [ 2 ] ;
T_3 V_31 ;
T_2 V_26 [ 8 ] ;
} V_32 ;
F_7 ( sizeof( V_32 ) != 16 ) ;
V_13 = F_13 ( V_10 , & V_32 , sizeof( V_32 ) ) ;
F_4 ( V_13 && L_12 ) ;
if ( V_32 . V_4 != 1 ) {
F_8 ( & V_10 -> V_18 , L_13 ,
V_19 , __LINE__ , V_32 . V_4 ) ;
return - V_33 ;
}
switch ( V_32 . type ) {
case V_34 :
F_8 ( & V_10 -> V_18 , L_14 ,
V_19 , __LINE__ ,
( V_32 . V_31 == V_35 ? L_15
: L_16 ) ) ;
V_36 = 1 ;
F_14 () ;
F_15 ( V_37 , 1 ) ;
break;
case V_38 :
F_8 ( & V_10 -> V_18 , L_17 ,
V_19 , __LINE__ , V_32 . V_31 ) ;
break;
case V_39 :
F_8 ( & V_10 -> V_18 , L_18 ,
V_19 , __LINE__ ,
( V_32 . V_31 == V_35 ? L_15
: L_16 ) ) ;
V_36 = 0 ;
F_14 () ;
F_15 ( V_37 , 1 ) ;
break;
case V_40 :
F_8 ( & V_10 -> V_18 , L_19 ,
V_19 , __LINE__ , V_32 . V_31 ) ;
break;
case V_41 :
F_8 ( & V_10 -> V_18 , L_20 ,
V_19 , __LINE__ , V_32 . V_31 ) ;
F_16 ( L_21 , V_32 . V_31 ) ;
break;
case V_42 :
F_8 ( & V_10 -> V_18 , L_22 ,
V_19 , __LINE__ , V_32 . V_31 ) ;
break;
default:
F_8 ( & V_10 -> V_18 , L_23 ,
V_19 , __LINE__ , V_32 . type ) ;
return - V_33 ;
}
return 0 ;
}
static int F_17 ( struct V_9 * V_10 )
{
int V_13 ;
struct {
T_2 V_4 ;
T_2 type ;
T_2 V_16 [ 14 ] ;
} V_43 ;
F_7 ( sizeof( V_43 ) != 16 ) ;
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
V_13 = F_13 ( V_10 , & V_43 , sizeof( V_43 ) ) ;
F_4 ( V_13 && L_12 ) ;
if ( V_13 )
return V_13 ;
if ( V_43 . V_4 != 1 ) {
F_8 ( & V_10 -> V_18 , L_24 ,
V_19 , __LINE__ , V_43 . V_4 ) ;
return - V_33 ;
}
if ( V_43 . type != V_44 ) {
F_8 ( & V_10 -> V_18 , L_25 ,
V_19 , __LINE__ , V_43 . type ) ;
return - V_33 ;
}
F_11 ( V_10 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
int V_13 ;
struct V_1 V_11 ;
V_13 = F_13 ( V_10 , & V_11 ,
sizeof( struct V_1 ) ) ;
if ( V_13 )
return V_13 ;
if ( V_11 . V_4 != 1 ) {
F_8 ( & V_10 -> V_18 , L_26 ,
V_19 , __LINE__ , V_11 . V_4 ) ;
F_19 ( & V_11 ) ;
goto V_45;
}
F_7 ( sizeof( V_11 ) != 16 ) ;
if ( V_11 . V_5 != 16 || ( V_11 . V_6 != 8
&& V_11 . V_6 != 16 ) ) {
F_19 ( & V_11 ) ;
F_20 () ;
}
switch ( V_11 . V_7 ) {
case V_46 :
F_8 ( & V_10 -> V_18 , L_27 , V_19 , __LINE__ ) ;
return F_12 ( V_10 ) ;
case V_47 :
F_8 ( & V_10 -> V_18 , L_28 , V_19 , __LINE__ ) ;
return F_17 ( V_10 ) ;
case V_48 :
F_8 ( & V_10 -> V_18 , L_29 , V_19 ,
__LINE__ ) ;
F_19 ( & V_11 ) ;
break;
default:
F_8 ( & V_10 -> V_18 , L_30 ,
V_19 , __LINE__ , V_11 . V_7 ) ;
break;
}
goto V_49;
V_45:
F_21 ( V_10 , 0 ) ;
return - V_33 ;
V_49:
F_21 ( V_10 , V_11 . V_6 ) ;
return - V_33 ;
}
static void F_22 ( struct V_9 * V_10 )
{
F_10 ( V_10 ) ;
F_23 ( L_31 ) ;
while ( F_18 ( V_10 ) ) {
F_24 ( 0 ) ;
}
while ( 1 ) {
F_24 ( 1 ) ;
}
}
static void F_25 ( struct V_9 * V_10 )
{
F_4 ( ! V_10 ) ;
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
F_26 ( V_10 ) ;
F_9 ( V_10 , V_50 ,
V_51 ) ;
F_22 ( V_10 ) ;
}
static void F_27 ( struct V_9 * V_10 )
{
F_4 ( ! V_10 ) ;
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
if ( V_36 ) {
F_8 ( & V_10 -> V_18 , L_32 ,
V_19 , __LINE__ ) ;
F_25 ( V_10 ) ;
}
F_26 ( V_10 ) ;
F_6 ( V_10 , 0 ) ;
F_9 ( V_10 , V_52 ,
V_51 ) ;
F_22 ( V_10 ) ;
}
int F_28 ( void )
{
F_2 ( L_8 , V_19 , __LINE__ ) ;
return ( V_51 & V_53 ) != 0 ;
}
void F_29 ( int V_54 )
{
static F_30 ( V_55 ) ;
F_31 ( & V_55 ) ;
F_2 ( L_33 , V_19 , __LINE__ , V_54 ) ;
if ( V_54 )
V_51 |= V_53 ;
else
V_51 &= ~ V_53 ;
F_32 ( & V_55 ) ;
}
static void F_33 ( struct V_9 * V_10 )
{
F_18 ( V_10 ) ;
F_34 ( V_10 , V_56 ) ;
}
static int T_5 F_35 ( struct V_9 * V_10 )
{
int V_13 ;
struct V_57 V_58 ;
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
V_58 . V_59 = F_25 ;
V_58 . V_60 = F_27 ;
V_58 . V_10 = V_10 ;
F_36 ( & V_58 ) ;
V_13 = F_6 ( V_10 , V_61 ) ;
F_4 ( V_13 ) ;
V_13 = F_34 ( V_10 , V_56 ) ;
F_4 ( V_13 ) ;
return V_13 ;
}
static int F_37 ( struct V_9 * V_10 )
{
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
return 0 ;
}
static void F_38 ( struct V_9 * V_10 )
{
F_8 ( & V_10 -> V_18 , L_8 , V_19 , __LINE__ ) ;
}
static int T_6 F_39 ( void )
{
if ( ! F_40 ( V_62 ) )
return - V_63 ;
return F_41 ( & V_64 ) ;
}
