static inline unsigned int F_1 ( T_1 V_1 , T_2 V_2 , T_3 V_3 ,
T_1 V_4 , T_1 V_5 )
{
if ( V_1 == 0xff )
return 0 ;
return ( V_2 * 30 * V_5 ) / ( ( V_1 ? V_1 : 1 ) * V_3 * V_4 ) ;
}
static inline unsigned char F_2 ( T_2 V_6 , T_2 V_2 , T_3 V_3 ,
T_1 V_4 , T_1 V_5 )
{
if ( ! V_6 )
return 0xff ;
return F_3 ( ( ( V_2 * 30 * V_5 ) / ( V_6 * V_3 * V_4 ) ) ,
0 , 255 ) ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_6 ( V_11 ) ;
int V_13 = 0 ;
F_7 ( & V_12 -> V_14 ) ;
if ( F_8 ( V_15 , V_12 -> V_16 + V_17 ) &&
F_9 ( V_12 -> V_18 ) )
goto V_19;
V_13 = F_10 ( V_11 , V_20 ) ;
if ( V_13 < 0 )
goto V_19;
V_12 -> V_21 = V_13 ;
V_13 = F_10 ( V_11 , V_22 ) ;
if ( V_13 < 0 )
goto V_19;
V_12 -> V_23 = V_13 ;
V_13 = F_10 ( V_11 , V_24 ) ;
if ( V_13 < 0 )
goto V_19;
V_12 -> V_25 = V_13 ;
V_13 = F_10 ( V_11 , V_26 ) ;
if ( V_13 < 0 )
goto V_19;
V_12 -> V_27 = V_13 ;
V_13 = F_10 ( V_11 , V_28 ) ;
if ( V_13 < 0 )
goto V_19;
V_12 -> V_29 = V_13 ;
V_13 = F_10 ( V_11 , V_30 ) ;
if ( V_13 < 0 )
goto V_19;
V_12 -> V_31 = V_13 ;
V_12 -> V_16 = V_15 ;
V_12 -> V_18 = true ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
if ( V_13 < 0 )
V_12 = F_12 ( V_13 ) ;
return V_12 ;
}
static int F_13 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_6 ( V_11 ) ;
if ( V_32 > 0xffffff )
return - V_33 ;
if ( ! V_32 )
V_32 = 32768 ;
V_12 -> V_2 = V_32 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case V_34 :
V_12 -> V_29 |= V_35 ;
break;
case V_36 :
V_12 -> V_29 &= ~ V_35 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_28 ,
V_12 -> V_29 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_18 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case 1 :
V_12 -> V_29 &= ~ V_37 ;
V_12 -> V_29 &= ~ V_38 ;
break;
case 2 :
V_12 -> V_29 |= V_37 ;
V_12 -> V_29 &= ~ V_38 ;
break;
case 4 :
V_12 -> V_29 &= ~ V_37 ;
V_12 -> V_29 |= V_38 ;
break;
case 8 :
V_12 -> V_29 |= V_37 ;
V_12 -> V_29 |= V_38 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_28 ,
V_12 -> V_29 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_19 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case 0 :
V_12 -> V_31 &= ~ V_39 ;
V_12 -> V_31 &= ~ V_40 ;
break;
case 1 :
V_12 -> V_31 |= V_39 ;
V_12 -> V_31 &= ~ V_40 ;
break;
case 2 :
V_12 -> V_31 &= ~ V_39 ;
V_12 -> V_31 |= V_40 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_30 ,
V_12 -> V_31 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_20 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case 2 :
V_12 -> V_29 &= ~ V_41 ;
break;
case 4 :
V_12 -> V_29 |= V_41 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_28 ,
V_12 -> V_29 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_21 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case V_42 :
V_12 -> V_29 |= V_43 ;
break;
case V_44 :
V_12 -> V_29 &= ~ V_43 ;
if ( V_12 -> V_21 == 0xff )
F_17 ( V_11 , V_20 ,
254 ) ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_28 ,
V_12 -> V_29 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_22 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case V_45 :
V_12 -> V_29 &= ~ V_46 ;
break;
case V_47 :
V_12 -> V_29 |= V_46 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_28 ,
V_12 -> V_29 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_23 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_6 ( V_11 ) ;
int V_13 ;
if ( V_32 > 255 )
return - V_33 ;
F_7 ( & V_12 -> V_14 ) ;
V_13 = F_17 ( V_11 , V_26 , V_32 ) ;
V_12 -> V_18 = false ;
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_24 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
V_12 -> V_21 = F_2 ( V_32 , V_12 -> V_2 ,
F_25 ( V_12 -> V_29 ) ,
F_26 ( V_12 -> V_29 ) ,
F_27 ( V_12 -> V_31 ) ) ;
V_13 = F_17 ( V_11 , V_20 ,
V_12 -> V_21 ) ;
V_12 -> V_18 = false ;
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_28 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
switch ( V_32 ) {
case 0 :
V_12 -> V_31 &= ~ V_48 ;
V_12 -> V_31 &= ~ V_49 ;
break;
case 1 :
V_12 -> V_31 |= V_48 ;
V_12 -> V_31 &= ~ V_49 ;
break;
case 2 :
V_12 -> V_31 &= ~ V_48 ;
V_12 -> V_31 |= V_49 ;
break;
case 3 :
V_12 -> V_31 |= V_48 ;
V_12 -> V_31 |= V_49 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_17 ( V_11 , V_30 ,
V_12 -> V_31 ) ;
V_12 -> V_18 = false ;
V_19:
F_11 ( & V_12 -> V_14 ) ;
return V_13 ;
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_7 * V_12 ;
unsigned long V_2 ;
struct V_50 * V_50 ;
int V_13 ;
if ( ! V_11 -> V_9 . V_51 )
return 0 ;
V_50 = F_30 ( V_11 -> V_9 . V_51 , 0 ) ;
if ( F_15 ( V_50 ) ) {
F_31 ( & V_11 -> V_9 , L_1 ) ;
return F_16 ( V_50 ) ;
}
V_13 = F_32 ( V_50 ) ;
if ( V_13 ) {
F_31 ( & V_11 -> V_9 , L_2 ) ;
goto V_52;
}
V_2 = F_33 ( V_50 ) ;
V_13 = F_13 ( & V_11 -> V_9 , V_2 ) ;
if ( V_13 ) {
F_31 ( & V_11 -> V_9 , L_3 , V_2 ) ;
goto V_53;
}
V_12 = F_6 ( V_11 ) ;
V_12 -> V_50 = V_50 ;
return 0 ;
V_53:
F_34 ( V_50 ) ;
V_52:
V_52 ( V_50 ) ;
return V_13 ;
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_7 * V_12 = F_6 ( V_11 ) ;
if ( ! V_12 -> V_50 )
return;
F_34 ( V_12 -> V_50 ) ;
V_52 ( V_12 -> V_50 ) ;
}
static int F_36 ( struct V_10 * V_11 ,
const char * V_54 ,
int (* F_37)( struct V_8 * V_9 ,
unsigned long V_32 ) )
{
const T_4 * V_55 ;
int V_56 , V_13 ;
T_2 V_57 ;
V_55 = F_38 ( V_11 -> V_9 . V_51 , V_54 , & V_56 ) ;
if ( ! V_55 || V_56 != sizeof( T_2 ) )
return 0 ;
V_57 = F_39 ( V_55 [ 0 ] ) ;
F_40 ( & V_11 -> V_9 , L_4 , V_54 , V_57 ) ;
V_13 = (* F_37)( & V_11 -> V_9 , V_57 ) ;
if ( V_13 )
F_31 ( & V_11 -> V_9 , L_5 , V_54 , V_57 ) ;
return V_13 ;
}
static int F_41 ( struct V_10 * V_11 )
{
int V_13 ;
if ( ! V_11 -> V_9 . V_51 )
return 0 ;
V_13 = F_36 ( V_11 , L_6 ,
F_19 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_36 ( V_11 , L_7 ,
F_22 ) ;
if ( V_13 )
return V_13 ;
return F_36 ( V_11 , L_8 ,
F_28 ) ;
}
static int F_41 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_29 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_35 ( struct V_10 * V_11 ) { }
static int F_42 ( struct V_10 * V_11 )
{
struct V_58 * V_59 = F_43 ( & V_11 -> V_9 ) ;
int V_13 ;
if ( ! V_59 )
return 0 ;
V_13 = F_19 ( & V_11 -> V_9 , V_59 -> V_60 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( & V_11 -> V_9 , V_59 -> V_61 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_28 ( & V_11 -> V_9 , V_59 -> V_62 ) ;
if ( V_13 )
return V_13 ;
return F_13 ( & V_11 -> V_9 , V_59 -> V_2 ) ;
}
static T_5 F_44 ( struct V_8 * V_9 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
unsigned int V_6 = 0 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
if ( V_12 -> V_25 & V_66 ) {
V_6 = F_1 ( V_12 -> V_23 , V_12 -> V_2 ,
F_25 ( V_12 -> V_29 ) ,
F_26 ( V_12 -> V_29 ) ,
F_27 ( V_12 -> V_31 ) ) ;
}
F_11 ( & V_12 -> V_14 ) ;
return sprintf ( V_65 , L_9 , V_6 ) ;
}
static T_5 F_45 ( struct V_8 * V_9 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_10 ,
! ! ( V_12 -> V_29 & V_35 ) ) ;
}
static T_5 F_46 ( struct V_8 * V_9 , struct V_63 * V_64 ,
const char * V_65 , T_6 V_67 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_47 ( V_65 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_14 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_67 ;
}
static T_5 F_48 ( struct V_8 * V_9 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_10 , F_26 ( V_12 -> V_29 ) ) ;
}
static T_5 F_49 ( struct V_8 * V_9 ,
struct V_63 * V_64 ,
const char * V_65 , T_6 V_67 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_47 ( V_65 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_18 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_67 ;
}
static T_5 F_50 ( struct V_8 * V_9 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_10 , F_25 ( V_12 -> V_29 ) ) ;
}
static T_5 F_51 ( struct V_8 * V_9 ,
struct V_63 * V_64 ,
const char * V_65 , T_6 V_67 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_47 ( V_65 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_20 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_67 ;
}
static T_5 F_52 ( struct V_8 * V_9 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_10 ,
( ! ! ( V_12 -> V_29 & V_43 ) ) + 1 ) ;
}
static T_5 F_53 ( struct V_8 * V_9 ,
struct V_63 * V_64 ,
const char * V_65 , T_6 V_67 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_47 ( V_65 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_21 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_67 ;
}
static T_5 F_54 ( struct V_8 * V_9 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_10 , V_12 -> V_27 ) ;
}
static T_5 F_55 ( struct V_8 * V_9 , struct V_63 * V_64 ,
const char * V_65 , T_6 V_67 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_47 ( V_65 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_23 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_67 ;
}
static T_5 F_56 ( struct V_8 * V_9 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
unsigned int V_6 ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_7 ( & V_12 -> V_14 ) ;
V_6 = F_1 ( V_12 -> V_21 , V_12 -> V_2 ,
F_25 ( V_12 -> V_29 ) ,
F_26 ( V_12 -> V_29 ) ,
F_27 ( V_12 -> V_31 ) ) ;
F_11 ( & V_12 -> V_14 ) ;
return sprintf ( V_65 , L_9 , V_6 ) ;
}
static T_5 F_57 ( struct V_8 * V_9 , struct V_63 * V_64 ,
const char * V_65 , T_6 V_67 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_47 ( V_65 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_24 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_67 ;
}
static T_5 F_58 ( struct V_8 * V_9 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_9 , ! ! ( V_12 -> V_25 & V_68 ) ) ;
}
static T_5 F_59 ( struct V_8 * V_9 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
return sprintf ( V_65 , L_9 , ! ( V_12 -> V_25 & V_66 ) ) ;
}
static inline int F_60 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_12 = F_4 ( V_9 ) ;
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
V_12 -> V_29 |= V_69 ;
V_12 -> V_29 |= V_70 ;
V_12 -> V_18 = false ;
return F_17 ( V_11 , V_28 ,
V_12 -> V_29 ) ;
}
static int F_61 ( struct V_10 * V_11 , const struct V_71 * V_72 )
{
struct V_7 * V_12 ;
int V_13 ;
if ( ! F_62 ( V_11 -> V_73 ,
V_74 ) )
return - V_75 ;
V_12 = F_63 ( & V_11 -> V_9 , sizeof( struct V_7 ) , V_76 ) ;
if ( ! V_12 )
return - V_77 ;
F_64 ( V_11 , V_12 ) ;
V_12 -> V_11 = V_11 ;
F_65 ( & V_12 -> V_14 ) ;
V_13 = F_60 ( & V_11 -> V_9 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_29 ( V_11 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_41 ( V_11 ) ;
if ( V_13 )
goto V_78;
V_13 = F_42 ( V_11 ) ;
if ( V_13 )
goto V_78;
V_13 = F_66 ( & V_11 -> V_9 . V_79 , & V_80 ) ;
if ( V_13 )
goto V_78;
V_12 -> V_81 = F_67 ( & V_11 -> V_9 ) ;
if ( F_15 ( V_12 -> V_81 ) ) {
V_13 = F_16 ( V_12 -> V_81 ) ;
goto V_82;
}
return 0 ;
V_82:
F_68 ( & V_11 -> V_9 . V_79 , & V_80 ) ;
V_78:
F_35 ( V_11 ) ;
return V_13 ;
}
static int F_69 ( struct V_10 * V_11 )
{
struct V_7 * V_12 = F_6 ( V_11 ) ;
F_70 ( V_12 -> V_81 ) ;
F_68 ( & V_11 -> V_9 . V_79 , & V_80 ) ;
F_35 ( V_11 ) ;
return 0 ;
}
