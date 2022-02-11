static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 ;
if ( V_3 == V_12 )
return F_2 ( V_9 - V_5 -> V_13 ) ;
V_11 = V_3 << 2 ;
if ( V_3 == V_14 )
return F_3 ( V_9 + V_11 ) ;
else
return F_4 ( V_9 + V_11 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 ;
if ( V_3 == V_12 ) {
F_6 ( V_15 , V_9 - V_5 -> V_13 ) ;
return;
}
V_11 = V_3 << 2 ;
if ( V_3 == V_14 )
F_7 ( V_15 , V_9 + V_11 ) ;
else
F_8 ( V_15 , V_9 + V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
unsigned long V_17 , V_15 ;
F_10 ( & V_18 , V_17 ) ;
V_15 = F_1 ( V_2 , V_12 ) ;
if ( V_16 )
V_15 |= 1 << V_5 -> V_19 ;
else
V_15 &= ~ ( 1 << V_5 -> V_19 ) ;
F_5 ( V_2 , V_12 , V_15 ) ;
F_11 ( & V_18 , V_17 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_13 ( V_2 -> V_21 ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_20 ;
}
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_22 , 0xffffffff ) ;
F_5 ( V_2 , V_23 , 0xffffffff ) ;
V_2 -> V_24 = F_15 ( V_2 -> V_21 ) / 4 ;
F_5 ( V_2 , V_14 , 0x0000 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 ++ > 0 )
return 0 ;
F_17 ( & V_2 -> V_6 -> V_7 ) ;
F_18 ( & V_2 -> V_6 -> V_7 , true ) ;
return F_12 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_14 , 0x0000 ) ;
F_20 ( V_2 -> V_21 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 -> V_25 == 0 ) )
return;
if ( -- V_2 -> V_25 > 0 )
return;
F_19 ( V_2 ) ;
F_18 ( & V_2 -> V_6 -> V_7 , false ) ;
F_23 ( & V_2 -> V_6 -> V_7 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned long V_26 ,
int V_27 )
{
F_9 ( V_2 , 0 ) ;
F_1 ( V_2 , V_14 ) ;
F_5 ( V_2 , V_14 , 0x0020 ) ;
if ( V_27 )
F_5 ( V_2 , V_22 , V_26 ) ;
else
F_5 ( V_2 , V_22 , 0xffffffff ) ;
F_5 ( V_2 , V_23 , V_26 ) ;
F_9 ( V_2 , 1 ) ;
}
static T_2 F_25 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
if ( V_2 -> V_30 . V_31 == V_32 )
F_5 ( V_2 , V_14 , 0x0000 ) ;
else
F_5 ( V_2 , V_14 , 0x0020 ) ;
V_2 -> V_30 . V_33 ( & V_2 -> V_30 ) ;
return V_34 ;
}
static struct V_1 * F_26 ( struct V_35 * V_36 )
{
return F_27 ( V_36 , struct V_1 , V_36 ) ;
}
static T_3 F_28 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( V_36 ) ;
return F_1 ( V_2 , V_23 ) ^ 0xffffffff ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( V_36 ) ;
int V_20 ;
if ( F_22 ( V_2 -> V_37 ) )
return 0 ;
V_20 = F_16 ( V_2 ) ;
if ( ! V_20 ) {
F_30 ( V_36 , V_2 -> V_24 ) ;
V_2 -> V_37 = true ;
}
return V_20 ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( V_36 ) ;
if ( F_22 ( ! V_2 -> V_37 ) )
return;
F_21 ( V_2 ) ;
V_2 -> V_37 = false ;
}
static void F_32 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( V_36 ) ;
if ( ! V_2 -> V_37 )
return;
if ( -- V_2 -> V_25 == 0 ) {
F_19 ( V_2 ) ;
F_33 ( & V_2 -> V_6 -> V_7 ) ;
}
}
static void F_34 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( V_36 ) ;
if ( ! V_2 -> V_37 )
return;
if ( V_2 -> V_25 ++ == 0 ) {
F_35 ( & V_2 -> V_6 -> V_7 ) ;
F_12 ( V_2 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
char * V_38 , unsigned long V_39 )
{
struct V_35 * V_36 = & V_2 -> V_36 ;
V_36 -> V_38 = V_38 ;
V_36 -> V_39 = V_39 ;
V_36 -> V_40 = F_28 ;
V_36 -> V_41 = F_29 ;
V_36 -> V_42 = F_31 ;
V_36 -> V_43 = F_32 ;
V_36 -> V_44 = F_34 ;
V_36 -> V_45 = F_37 ( 32 ) ;
V_36 -> V_17 = V_46 ;
F_38 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
F_39 ( V_36 , 1 ) ;
return 0 ;
}
static struct V_1 * F_40 ( struct V_47 * V_30 )
{
return F_27 ( V_30 , struct V_1 , V_30 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_27 )
{
struct V_47 * V_30 = & V_2 -> V_30 ;
F_16 ( V_2 ) ;
F_42 ( V_30 , V_2 -> V_24 ) ;
if ( V_27 ) {
V_2 -> V_27 = ( V_2 -> V_24 + V_48 / 2 ) / V_48 ;
F_24 ( V_2 , V_2 -> V_27 , 1 ) ;
}
}
static void F_43 ( enum V_49 V_31 ,
struct V_47 * V_30 )
{
struct V_1 * V_2 = F_40 ( V_30 ) ;
int V_50 = 0 ;
switch ( V_30 -> V_31 ) {
case V_51 :
case V_32 :
F_21 ( V_2 ) ;
V_50 = 1 ;
break;
default:
break;
}
switch ( V_31 ) {
case V_51 :
F_38 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
F_41 ( V_2 , 1 ) ;
break;
case V_32 :
F_38 ( & V_2 -> V_6 -> V_7 , L_4 ) ;
F_41 ( V_2 , 0 ) ;
break;
case V_52 :
if ( ! V_50 )
F_21 ( V_2 ) ;
break;
case V_53 :
default:
break;
}
}
static int F_44 ( unsigned long V_26 ,
struct V_47 * V_30 )
{
struct V_1 * V_2 = F_40 ( V_30 ) ;
F_45 ( V_30 -> V_31 != V_32 ) ;
F_24 ( V_2 , V_26 , 0 ) ;
return 0 ;
}
static void F_46 ( struct V_47 * V_30 )
{
F_33 ( & F_40 ( V_30 ) -> V_6 -> V_7 ) ;
}
static void F_47 ( struct V_47 * V_30 )
{
F_35 ( & F_40 ( V_30 ) -> V_6 -> V_7 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
char * V_38 , unsigned long V_39 )
{
struct V_47 * V_30 = & V_2 -> V_30 ;
int V_20 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_38 = V_38 ;
V_30 -> V_54 = V_55 ;
V_30 -> V_54 |= V_56 ;
V_30 -> V_39 = V_39 ;
V_30 -> V_57 = F_49 ( 0 ) ;
V_30 -> V_58 = F_44 ;
V_30 -> V_59 = F_43 ;
V_30 -> V_43 = F_46 ;
V_30 -> V_44 = F_47 ;
F_38 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
F_50 ( V_30 , 1 , 0x300 , 0xffffffff ) ;
V_20 = F_51 ( V_2 -> V_60 . V_28 , & V_2 -> V_60 ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_6 ,
V_2 -> V_60 . V_28 ) ;
return;
}
}
static int F_52 ( struct V_1 * V_2 , char * V_38 ,
unsigned long V_61 ,
unsigned long V_62 )
{
if ( V_61 )
F_48 ( V_2 , V_38 , V_61 ) ;
else if ( V_62 )
F_36 ( V_2 , V_38 , V_62 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_63 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_64 * V_65 ;
int V_28 , V_20 ;
V_20 = - V_66 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
goto V_67;
}
F_54 ( V_6 , V_2 ) ;
V_65 = F_55 ( V_2 -> V_6 , V_68 , 0 ) ;
if ( ! V_65 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
goto V_67;
}
V_28 = F_56 ( V_2 -> V_6 , 0 ) ;
if ( V_28 < 0 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
goto V_67;
}
V_2 -> V_10 = F_57 ( V_65 -> V_16 , F_58 ( V_65 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
goto V_67;
}
V_2 -> V_60 . V_38 = F_59 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_60 . V_69 = F_25 ;
V_2 -> V_60 . V_29 = V_2 ;
V_2 -> V_60 . V_28 = V_28 ;
V_2 -> V_60 . V_17 = V_70 | V_71 | \
V_72 | V_73 ;
V_2 -> V_21 = F_60 ( & V_2 -> V_6 -> V_7 , L_11 ) ;
if ( F_61 ( V_2 -> V_21 ) ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_12 ) ;
V_20 = F_62 ( V_2 -> V_21 ) ;
goto V_74;
}
V_2 -> V_37 = false ;
V_2 -> V_25 = 0 ;
return F_52 ( V_2 , ( char * ) F_59 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_61 ,
V_5 -> V_62 ) ;
V_74:
F_63 ( V_2 -> V_10 ) ;
V_67:
return V_20 ;
}
static int F_64 ( struct V_63 * V_6 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
int V_20 ;
if ( ! F_66 ( V_6 ) ) {
F_67 ( & V_6 -> V_7 ) ;
F_68 ( & V_6 -> V_7 ) ;
}
if ( V_2 ) {
F_38 ( & V_6 -> V_7 , L_13 ) ;
goto V_75;
}
V_2 = F_69 ( sizeof( * V_2 ) , V_76 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_6 -> V_7 , L_14 ) ;
return - V_77 ;
}
V_20 = F_53 ( V_2 , V_6 ) ;
if ( V_20 ) {
F_70 ( V_2 ) ;
F_54 ( V_6 , NULL ) ;
F_71 ( & V_6 -> V_7 ) ;
return V_20 ;
}
if ( F_66 ( V_6 ) )
return 0 ;
V_75:
if ( V_5 -> V_61 || V_5 -> V_62 )
F_72 ( & V_6 -> V_7 ) ;
else
F_71 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_73 ( struct V_63 * V_6 )
{
return - V_78 ;
}
static int T_4 F_74 ( void )
{
return F_75 ( & V_79 ) ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_79 ) ;
}
