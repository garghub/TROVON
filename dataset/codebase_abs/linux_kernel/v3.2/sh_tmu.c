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
static void F_16 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_5 ( V_2 , V_14 , 0x0000 ) ;
F_17 ( V_2 -> V_21 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned long V_25 ,
int V_26 )
{
F_9 ( V_2 , 0 ) ;
F_1 ( V_2 , V_14 ) ;
F_5 ( V_2 , V_14 , 0x0020 ) ;
if ( V_26 )
F_5 ( V_2 , V_22 , V_25 ) ;
else
F_5 ( V_2 , V_22 , 0xffffffff ) ;
F_5 ( V_2 , V_23 , V_25 ) ;
F_9 ( V_2 , 1 ) ;
}
static T_2 F_19 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
if ( V_2 -> V_29 . V_30 == V_31 )
F_5 ( V_2 , V_14 , 0x0000 ) ;
else
F_5 ( V_2 , V_14 , 0x0020 ) ;
V_2 -> V_29 . V_32 ( & V_2 -> V_29 ) ;
return V_33 ;
}
static struct V_1 * F_20 ( struct V_34 * V_35 )
{
return F_21 ( V_35 , struct V_1 , V_35 ) ;
}
static T_3 F_22 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_20 ( V_35 ) ;
return F_1 ( V_2 , V_23 ) ^ 0xffffffff ;
}
static int F_23 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_20 ( V_35 ) ;
int V_20 ;
V_20 = F_12 ( V_2 ) ;
if ( ! V_20 )
F_24 ( V_35 , V_2 -> V_24 ) ;
return V_20 ;
}
static void F_25 ( struct V_34 * V_35 )
{
F_16 ( F_20 ( V_35 ) ) ;
}
static int F_26 ( struct V_1 * V_2 ,
char * V_36 , unsigned long V_37 )
{
struct V_34 * V_35 = & V_2 -> V_35 ;
V_35 -> V_36 = V_36 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_38 = F_22 ;
V_35 -> V_39 = F_23 ;
V_35 -> V_40 = F_25 ;
V_35 -> V_41 = F_27 ( 32 ) ;
V_35 -> V_17 = V_42 ;
F_28 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
F_29 ( V_35 , 1 ) ;
return 0 ;
}
static struct V_1 * F_30 ( struct V_43 * V_29 )
{
return F_21 ( V_29 , struct V_1 , V_29 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_26 )
{
struct V_43 * V_29 = & V_2 -> V_29 ;
F_12 ( V_2 ) ;
V_29 -> V_44 = 32 ;
V_29 -> V_45 = F_32 ( V_2 -> V_24 , V_46 , V_29 -> V_44 ) ;
V_29 -> V_47 = F_33 ( 0xffffffff , V_29 ) ;
V_29 -> V_48 = 5000 ;
if ( V_26 ) {
V_2 -> V_26 = ( V_2 -> V_24 + V_49 / 2 ) / V_49 ;
F_18 ( V_2 , V_2 -> V_26 , 1 ) ;
}
}
static void F_34 ( enum V_50 V_30 ,
struct V_43 * V_29 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
int V_51 = 0 ;
switch ( V_29 -> V_30 ) {
case V_52 :
case V_31 :
F_16 ( V_2 ) ;
V_51 = 1 ;
break;
default:
break;
}
switch ( V_30 ) {
case V_52 :
F_28 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
F_31 ( V_2 , 1 ) ;
break;
case V_31 :
F_28 ( & V_2 -> V_6 -> V_7 , L_4 ) ;
F_31 ( V_2 , 0 ) ;
break;
case V_53 :
if ( ! V_51 )
F_16 ( V_2 ) ;
break;
case V_54 :
default:
break;
}
}
static int F_35 ( unsigned long V_25 ,
struct V_43 * V_29 )
{
struct V_1 * V_2 = F_30 ( V_29 ) ;
F_36 ( V_29 -> V_30 != V_31 ) ;
F_18 ( V_2 , V_25 , 0 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 ,
char * V_36 , unsigned long V_37 )
{
struct V_43 * V_29 = & V_2 -> V_29 ;
int V_20 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_36 = V_36 ;
V_29 -> V_55 = V_56 ;
V_29 -> V_55 |= V_57 ;
V_29 -> V_37 = V_37 ;
V_29 -> V_58 = F_38 ( 0 ) ;
V_29 -> V_59 = F_35 ;
V_29 -> V_60 = F_34 ;
F_28 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
F_39 ( V_29 ) ;
V_20 = F_40 ( V_2 -> V_61 . V_27 , & V_2 -> V_61 ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_6 ,
V_2 -> V_61 . V_27 ) ;
return;
}
}
static int F_41 ( struct V_1 * V_2 , char * V_36 ,
unsigned long V_62 ,
unsigned long V_63 )
{
if ( V_62 )
F_37 ( V_2 , V_36 , V_62 ) ;
else if ( V_63 )
F_26 ( V_2 , V_36 , V_63 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_64 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_65 * V_66 ;
int V_27 , V_20 ;
V_20 = - V_67 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
goto V_68;
}
F_43 ( V_6 , V_2 ) ;
V_66 = F_44 ( V_2 -> V_6 , V_69 , 0 ) ;
if ( ! V_66 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
goto V_68;
}
V_27 = F_45 ( V_2 -> V_6 , 0 ) ;
if ( V_27 < 0 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
goto V_68;
}
V_2 -> V_10 = F_46 ( V_66 -> V_16 , F_47 ( V_66 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
goto V_68;
}
V_2 -> V_61 . V_36 = F_48 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_61 . V_70 = F_19 ;
V_2 -> V_61 . V_28 = V_2 ;
V_2 -> V_61 . V_27 = V_27 ;
V_2 -> V_61 . V_17 = V_71 | V_72 | \
V_73 | V_74 ;
V_2 -> V_21 = F_49 ( & V_2 -> V_6 -> V_7 , L_11 ) ;
if ( F_50 ( V_2 -> V_21 ) ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_12 ) ;
V_20 = F_51 ( V_2 -> V_21 ) ;
goto V_75;
}
return F_41 ( V_2 , ( char * ) F_48 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_62 ,
V_5 -> V_63 ) ;
V_75:
F_52 ( V_2 -> V_10 ) ;
V_68:
return V_20 ;
}
static int T_4 F_53 ( struct V_64 * V_6 )
{
struct V_1 * V_2 = F_54 ( V_6 ) ;
int V_20 ;
if ( V_2 ) {
F_28 ( & V_6 -> V_7 , L_13 ) ;
return 0 ;
}
V_2 = F_55 ( sizeof( * V_2 ) , V_76 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_6 -> V_7 , L_14 ) ;
return - V_77 ;
}
V_20 = F_42 ( V_2 , V_6 ) ;
if ( V_20 ) {
F_56 ( V_2 ) ;
F_43 ( V_6 , NULL ) ;
}
return V_20 ;
}
static int T_5 F_57 ( struct V_64 * V_6 )
{
return - V_78 ;
}
static int T_6 F_58 ( void )
{
return F_59 ( & V_79 ) ;
}
static void T_7 F_60 ( void )
{
F_61 ( & V_79 ) ;
}
