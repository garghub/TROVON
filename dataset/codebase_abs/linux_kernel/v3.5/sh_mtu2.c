static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 ;
if ( V_3 == V_12 )
return F_2 ( V_9 + V_5 -> V_13 ) ;
V_11 = V_14 [ V_3 ] ;
if ( ( V_3 == V_15 ) || ( V_3 == V_16 ) )
return F_3 ( V_9 + V_11 ) ;
else
return F_2 ( V_9 + V_11 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 ;
if ( V_3 == V_12 ) {
F_5 ( V_17 , V_9 + V_5 -> V_13 ) ;
return;
}
V_11 = V_14 [ V_3 ] ;
if ( ( V_3 == V_15 ) || ( V_3 == V_16 ) )
F_6 ( V_17 , V_9 + V_11 ) ;
else
F_5 ( V_17 , V_9 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
unsigned long V_19 , V_17 ;
F_8 ( & V_20 , V_19 ) ;
V_17 = F_1 ( V_2 , V_12 ) ;
if ( V_18 )
V_17 |= 1 << V_5 -> V_21 ;
else
V_17 &= ~ ( 1 << V_5 -> V_21 ) ;
F_4 ( V_2 , V_12 , V_17 ) ;
F_9 ( & V_20 , V_19 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_11 ( V_2 -> V_23 ) ;
if ( V_22 ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_22 ;
}
F_7 ( V_2 , 0 ) ;
V_2 -> V_24 = F_13 ( V_2 -> V_23 ) / 64 ;
V_2 -> V_25 = ( V_2 -> V_24 + V_26 / 2 ) / V_26 ;
F_4 ( V_2 , V_27 , 0x23 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
F_4 ( V_2 , V_16 , V_2 -> V_25 ) ;
F_4 ( V_2 , V_15 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_30 , 0x01 ) ;
F_7 ( V_2 , 1 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 ) ;
F_15 ( V_2 -> V_23 ) ;
}
static T_2 F_16 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
F_1 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_33 , 0xfe ) ;
V_2 -> V_34 . V_35 ( & V_2 -> V_34 ) ;
return V_36 ;
}
static struct V_1 * F_17 ( struct V_37 * V_34 )
{
return F_18 ( V_34 , struct V_1 , V_34 ) ;
}
static void F_19 ( enum V_38 V_39 ,
struct V_37 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_34 ) ;
int V_40 = 0 ;
switch ( V_34 -> V_39 ) {
case V_41 :
F_14 ( V_2 ) ;
V_40 = 1 ;
break;
default:
break;
}
switch ( V_39 ) {
case V_41 :
F_20 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
F_10 ( V_2 ) ;
break;
case V_42 :
if ( ! V_40 )
F_14 ( V_2 ) ;
break;
case V_43 :
default:
break;
}
}
static void F_21 ( struct V_1 * V_2 ,
char * V_44 , unsigned long V_45 )
{
struct V_37 * V_34 = & V_2 -> V_34 ;
int V_22 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_44 = V_44 ;
V_34 -> V_46 = V_47 ;
V_34 -> V_45 = V_45 ;
V_34 -> V_48 = F_22 ( 0 ) ;
V_34 -> V_49 = F_19 ;
F_20 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
F_23 ( V_34 ) ;
V_22 = F_24 ( V_2 -> V_50 . V_31 , & V_2 -> V_50 ) ;
if ( V_22 ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_4 ,
V_2 -> V_50 . V_31 ) ;
return;
}
}
static int F_25 ( struct V_1 * V_2 , char * V_44 ,
unsigned long V_51 )
{
if ( V_51 )
F_21 ( V_2 , V_44 , V_51 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_52 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_53 * V_54 ;
int V_31 , V_22 ;
V_22 = - V_55 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
goto V_56;
}
F_27 ( V_6 , V_2 ) ;
V_54 = F_28 ( V_2 -> V_6 , V_57 , 0 ) ;
if ( ! V_54 ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
goto V_56;
}
V_31 = F_29 ( V_2 -> V_6 , 0 ) ;
if ( V_31 < 0 ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
goto V_56;
}
V_2 -> V_10 = F_30 ( V_54 -> V_18 , F_31 ( V_54 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
goto V_56;
}
V_2 -> V_50 . V_44 = F_32 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_50 . V_58 = F_16 ;
V_2 -> V_50 . V_32 = V_2 ;
V_2 -> V_50 . V_31 = V_31 ;
V_2 -> V_50 . V_19 = V_59 | V_60 | \
V_61 | V_62 ;
V_2 -> V_23 = F_33 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
if ( F_34 ( V_2 -> V_23 ) ) {
F_12 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
V_22 = F_35 ( V_2 -> V_23 ) ;
goto V_63;
}
return F_25 ( V_2 , ( char * ) F_32 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_51 ) ;
V_63:
F_36 ( V_2 -> V_10 ) ;
V_56:
return V_22 ;
}
static int T_3 F_37 ( struct V_52 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 ) ;
int V_22 ;
if ( ! F_39 ( V_6 ) )
F_40 ( & V_6 -> V_7 , true ) ;
if ( V_2 ) {
F_20 ( & V_6 -> V_7 , L_11 ) ;
return 0 ;
}
V_2 = F_41 ( sizeof( * V_2 ) , V_64 ) ;
if ( V_2 == NULL ) {
F_12 ( & V_6 -> V_7 , L_12 ) ;
return - V_65 ;
}
V_22 = F_26 ( V_2 , V_6 ) ;
if ( V_22 ) {
F_42 ( V_2 ) ;
F_27 ( V_6 , NULL ) ;
}
return V_22 ;
}
static int T_4 F_43 ( struct V_52 * V_6 )
{
return - V_66 ;
}
static int T_5 F_44 ( void )
{
return F_45 ( & V_67 ) ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_67 ) ;
}
