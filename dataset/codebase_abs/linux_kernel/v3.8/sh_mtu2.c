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
F_11 ( & V_2 -> V_6 -> V_7 ) ;
F_12 ( & V_2 -> V_6 -> V_7 , true ) ;
V_22 = F_13 ( V_2 -> V_23 ) ;
if ( V_22 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_22 ;
}
F_7 ( V_2 , 0 ) ;
V_2 -> V_24 = F_15 ( V_2 -> V_23 ) / 64 ;
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
static void F_16 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 ) ;
F_17 ( V_2 -> V_23 ) ;
F_12 ( & V_2 -> V_6 -> V_7 , false ) ;
F_18 ( & V_2 -> V_6 -> V_7 ) ;
}
static T_2 F_19 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
F_1 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_33 , 0xfe ) ;
V_2 -> V_34 . V_35 ( & V_2 -> V_34 ) ;
return V_36 ;
}
static struct V_1 * F_20 ( struct V_37 * V_34 )
{
return F_21 ( V_34 , struct V_1 , V_34 ) ;
}
static void F_22 ( enum V_38 V_39 ,
struct V_37 * V_34 )
{
struct V_1 * V_2 = F_20 ( V_34 ) ;
int V_40 = 0 ;
switch ( V_34 -> V_39 ) {
case V_41 :
F_16 ( V_2 ) ;
V_40 = 1 ;
break;
default:
break;
}
switch ( V_39 ) {
case V_41 :
F_23 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
F_10 ( V_2 ) ;
break;
case V_42 :
if ( ! V_40 )
F_16 ( V_2 ) ;
break;
case V_43 :
default:
break;
}
}
static void F_24 ( struct V_37 * V_34 )
{
F_25 ( & F_20 ( V_34 ) -> V_6 -> V_7 ) ;
}
static void F_26 ( struct V_37 * V_34 )
{
F_27 ( & F_20 ( V_34 ) -> V_6 -> V_7 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
char * V_44 , unsigned long V_45 )
{
struct V_37 * V_34 = & V_2 -> V_34 ;
int V_22 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_44 = V_44 ;
V_34 -> V_46 = V_47 ;
V_34 -> V_45 = V_45 ;
V_34 -> V_48 = F_29 ( 0 ) ;
V_34 -> V_49 = F_22 ;
V_34 -> V_50 = F_24 ;
V_34 -> V_51 = F_26 ;
F_23 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
F_30 ( V_34 ) ;
V_22 = F_31 ( V_2 -> V_52 . V_31 , & V_2 -> V_52 ) ;
if ( V_22 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_4 ,
V_2 -> V_52 . V_31 ) ;
return;
}
}
static int F_32 ( struct V_1 * V_2 , char * V_44 ,
unsigned long V_53 )
{
if ( V_53 )
F_28 ( V_2 , V_44 , V_53 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_54 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_55 * V_56 ;
int V_31 , V_22 ;
V_22 = - V_57 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
goto V_58;
}
F_34 ( V_6 , V_2 ) ;
V_56 = F_35 ( V_2 -> V_6 , V_59 , 0 ) ;
if ( ! V_56 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
goto V_58;
}
V_31 = F_36 ( V_2 -> V_6 , 0 ) ;
if ( V_31 < 0 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
goto V_58;
}
V_2 -> V_10 = F_37 ( V_56 -> V_18 , F_38 ( V_56 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
goto V_58;
}
V_2 -> V_52 . V_44 = F_39 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_52 . V_60 = F_19 ;
V_2 -> V_52 . V_32 = V_2 ;
V_2 -> V_52 . V_31 = V_31 ;
V_2 -> V_52 . V_19 = V_61 | V_62 | \
V_63 | V_64 ;
V_2 -> V_23 = F_40 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
if ( F_41 ( V_2 -> V_23 ) ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
V_22 = F_42 ( V_2 -> V_23 ) ;
goto V_65;
}
return F_32 ( V_2 , ( char * ) F_39 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_53 ) ;
V_65:
F_43 ( V_2 -> V_10 ) ;
V_58:
return V_22 ;
}
static int F_44 ( struct V_54 * V_6 )
{
struct V_1 * V_2 = F_45 ( V_6 ) ;
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
int V_22 ;
if ( ! F_46 ( V_6 ) ) {
F_47 ( & V_6 -> V_7 ) ;
F_48 ( & V_6 -> V_7 ) ;
}
if ( V_2 ) {
F_23 ( & V_6 -> V_7 , L_11 ) ;
goto V_66;
}
V_2 = F_49 ( sizeof( * V_2 ) , V_67 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_6 -> V_7 , L_12 ) ;
return - V_68 ;
}
V_22 = F_33 ( V_2 , V_6 ) ;
if ( V_22 ) {
F_50 ( V_2 ) ;
F_34 ( V_6 , NULL ) ;
F_51 ( & V_6 -> V_7 ) ;
return V_22 ;
}
if ( F_46 ( V_6 ) )
return 0 ;
V_66:
if ( V_5 -> V_53 )
F_52 ( & V_6 -> V_7 ) ;
else
F_51 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_53 ( struct V_54 * V_6 )
{
return - V_69 ;
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_70 ) ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_70 ) ;
}
