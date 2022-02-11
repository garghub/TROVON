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
struct V_7 * V_10 = F_5 ( V_9 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_13 = 0 ;
F_6 ( & V_10 -> V_14 ) ;
if ( F_7 ( V_15 , V_10 -> V_16 + V_17 ) &&
F_8 ( V_10 -> V_18 ) )
goto V_19;
V_13 = F_9 ( V_12 , V_20 ) ;
if ( V_13 < 0 )
goto V_19;
V_10 -> V_21 = V_13 ;
V_13 = F_9 ( V_12 , V_22 ) ;
if ( V_13 < 0 )
goto V_19;
V_10 -> V_23 = V_13 ;
V_13 = F_9 ( V_12 , V_24 ) ;
if ( V_13 < 0 )
goto V_19;
V_10 -> V_25 = V_13 ;
V_13 = F_9 ( V_12 , V_26 ) ;
if ( V_13 < 0 )
goto V_19;
V_10 -> V_27 = V_13 ;
V_13 = F_9 ( V_12 , V_28 ) ;
if ( V_13 < 0 )
goto V_19;
V_10 -> V_29 = V_13 ;
V_13 = F_9 ( V_12 , V_30 ) ;
if ( V_13 < 0 )
goto V_19;
V_10 -> V_31 = V_13 ;
V_10 -> V_16 = V_15 ;
V_10 -> V_18 = true ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
if ( V_13 < 0 )
V_10 = F_11 ( V_13 ) ;
return V_10 ;
}
static int F_12 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_5 ( V_9 ) ;
if ( V_32 > 0xffffff )
return - V_33 ;
if ( ! V_32 )
V_32 = 32768 ;
V_10 -> V_2 = V_32 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case V_34 :
V_10 -> V_29 |= V_35 ;
break;
case V_36 :
V_10 -> V_29 &= ~ V_35 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_17 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case 1 :
V_10 -> V_29 &= ~ V_37 ;
V_10 -> V_29 &= ~ V_38 ;
break;
case 2 :
V_10 -> V_29 |= V_37 ;
V_10 -> V_29 &= ~ V_38 ;
break;
case 4 :
V_10 -> V_29 &= ~ V_37 ;
V_10 -> V_29 |= V_38 ;
break;
case 8 :
V_10 -> V_29 |= V_37 ;
V_10 -> V_29 |= V_38 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_18 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case 0 :
V_10 -> V_31 &= ~ V_39 ;
V_10 -> V_31 &= ~ V_40 ;
break;
case 1 :
V_10 -> V_31 |= V_39 ;
V_10 -> V_31 &= ~ V_40 ;
break;
case 2 :
V_10 -> V_31 &= ~ V_39 ;
V_10 -> V_31 |= V_40 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_30 ,
V_10 -> V_31 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_19 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case 2 :
V_10 -> V_29 &= ~ V_41 ;
break;
case 4 :
V_10 -> V_29 |= V_41 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_20 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case V_42 :
V_10 -> V_29 |= V_43 ;
break;
case V_44 :
V_10 -> V_29 &= ~ V_43 ;
if ( V_10 -> V_21 == 0xff )
F_16 ( V_10 -> V_12 ,
V_20 , 254 ) ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_21 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case V_45 :
V_10 -> V_29 &= ~ V_46 ;
break;
case V_47 :
V_10 -> V_29 |= V_46 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_22 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_5 ( V_9 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_13 ;
if ( V_32 > 255 )
return - V_33 ;
F_6 ( & V_10 -> V_14 ) ;
V_13 = F_16 ( V_12 , V_26 , V_32 ) ;
V_10 -> V_18 = false ;
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_23 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
V_10 -> V_21 = F_2 ( V_32 , V_10 -> V_2 ,
F_24 ( V_10 -> V_29 ) ,
F_25 ( V_10 -> V_29 ) ,
F_26 ( V_10 -> V_31 ) ) ;
V_13 = F_16 ( V_10 -> V_12 , V_20 ,
V_10 -> V_21 ) ;
V_10 -> V_18 = false ;
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_27 ( struct V_8 * V_9 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_13 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
switch ( V_32 ) {
case 0 :
V_10 -> V_31 &= ~ V_48 ;
V_10 -> V_31 &= ~ V_49 ;
break;
case 1 :
V_10 -> V_31 |= V_48 ;
V_10 -> V_31 &= ~ V_49 ;
break;
case 2 :
V_10 -> V_31 &= ~ V_48 ;
V_10 -> V_31 |= V_49 ;
break;
case 3 :
V_10 -> V_31 |= V_48 ;
V_10 -> V_31 |= V_49 ;
break;
default:
V_13 = - V_33 ;
goto V_19;
}
V_13 = F_16 ( V_10 -> V_12 , V_30 ,
V_10 -> V_31 ) ;
V_10 -> V_18 = false ;
V_19:
F_10 ( & V_10 -> V_14 ) ;
return V_13 ;
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_7 * V_10 ;
unsigned long V_2 ;
struct V_50 * V_50 ;
int V_13 ;
if ( ! V_12 -> V_9 . V_51 )
return 0 ;
V_50 = F_29 ( V_12 -> V_9 . V_51 , 0 ) ;
if ( F_14 ( V_50 ) ) {
F_30 ( & V_12 -> V_9 , L_1 ) ;
return F_15 ( V_50 ) ;
}
V_13 = F_31 ( V_50 ) ;
if ( V_13 ) {
F_30 ( & V_12 -> V_9 , L_2 ) ;
goto V_52;
}
V_2 = F_32 ( V_50 ) ;
V_13 = F_12 ( & V_12 -> V_9 , V_2 ) ;
if ( V_13 ) {
F_30 ( & V_12 -> V_9 , L_3 , V_2 ) ;
goto V_53;
}
V_10 = F_33 ( V_12 ) ;
V_10 -> V_50 = V_50 ;
return 0 ;
V_53:
F_34 ( V_50 ) ;
V_52:
V_52 ( V_50 ) ;
return V_13 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_7 * V_10 = F_33 ( V_12 ) ;
if ( ! V_10 -> V_50 )
return;
F_34 ( V_10 -> V_50 ) ;
V_52 ( V_10 -> V_50 ) ;
}
static int F_36 ( struct V_11 * V_12 ,
const char * V_54 ,
int (* F_37)( struct V_8 * V_9 ,
unsigned long V_32 ) )
{
int V_13 ;
T_2 V_55 ;
if ( F_38 ( V_12 -> V_9 . V_51 , V_54 , & V_55 ) )
return 0 ;
F_39 ( & V_12 -> V_9 , L_4 , V_54 , V_55 ) ;
V_13 = (* F_37)( & V_12 -> V_9 , V_55 ) ;
if ( V_13 )
F_30 ( & V_12 -> V_9 , L_5 , V_54 , V_55 ) ;
return V_13 ;
}
static int F_40 ( struct V_11 * V_12 )
{
int V_13 ;
if ( ! V_12 -> V_9 . V_51 )
return 0 ;
V_13 = F_36 ( V_12 , L_6 ,
F_18 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_36 ( V_12 , L_7 ,
F_21 ) ;
if ( V_13 )
return V_13 ;
return F_36 ( V_12 , L_8 ,
F_27 ) ;
}
static int F_40 ( struct V_11 * V_12 )
{
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
return 0 ;
}
static void F_35 ( struct V_11 * V_12 ) { }
static int F_41 ( struct V_11 * V_12 )
{
struct V_56 * V_57 = F_42 ( & V_12 -> V_9 ) ;
int V_13 ;
if ( ! V_57 )
return 0 ;
V_13 = F_18 ( & V_12 -> V_9 , V_57 -> V_58 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_21 ( & V_12 -> V_9 , V_57 -> V_59 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_27 ( & V_12 -> V_9 , V_57 -> V_60 ) ;
if ( V_13 )
return V_13 ;
return F_12 ( & V_12 -> V_9 , V_57 -> V_2 ) ;
}
static T_4 F_43 ( struct V_8 * V_9 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
unsigned int V_6 = 0 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_25 & V_64 ) {
V_6 = F_1 ( V_10 -> V_23 , V_10 -> V_2 ,
F_24 ( V_10 -> V_29 ) ,
F_25 ( V_10 -> V_29 ) ,
F_26 ( V_10 -> V_31 ) ) ;
}
F_10 ( & V_10 -> V_14 ) ;
return sprintf ( V_63 , L_9 , V_6 ) ;
}
static T_4 F_44 ( struct V_8 * V_9 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_10 ,
! ! ( V_10 -> V_29 & V_35 ) ) ;
}
static T_4 F_45 ( struct V_8 * V_9 , struct V_61 * V_62 ,
const char * V_63 , T_5 V_65 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_46 ( V_63 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_13 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_65 ;
}
static T_4 F_47 ( struct V_8 * V_9 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_10 , F_25 ( V_10 -> V_29 ) ) ;
}
static T_4 F_48 ( struct V_8 * V_9 ,
struct V_61 * V_62 ,
const char * V_63 , T_5 V_65 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_46 ( V_63 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_17 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_65 ;
}
static T_4 F_49 ( struct V_8 * V_9 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_10 , F_24 ( V_10 -> V_29 ) ) ;
}
static T_4 F_50 ( struct V_8 * V_9 ,
struct V_61 * V_62 ,
const char * V_63 , T_5 V_65 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_46 ( V_63 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_19 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_65 ;
}
static T_4 F_51 ( struct V_8 * V_9 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_10 ,
( ! ! ( V_10 -> V_29 & V_43 ) ) + 1 ) ;
}
static T_4 F_52 ( struct V_8 * V_9 ,
struct V_61 * V_62 ,
const char * V_63 , T_5 V_65 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_46 ( V_63 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_20 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_65 ;
}
static T_4 F_53 ( struct V_8 * V_9 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_10 , V_10 -> V_27 ) ;
}
static T_4 F_54 ( struct V_8 * V_9 , struct V_61 * V_62 ,
const char * V_63 , T_5 V_65 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_46 ( V_63 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_22 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_65 ;
}
static T_4 F_55 ( struct V_8 * V_9 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
unsigned int V_6 ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
F_6 ( & V_10 -> V_14 ) ;
V_6 = F_1 ( V_10 -> V_21 , V_10 -> V_2 ,
F_24 ( V_10 -> V_29 ) ,
F_25 ( V_10 -> V_29 ) ,
F_26 ( V_10 -> V_31 ) ) ;
F_10 ( & V_10 -> V_14 ) ;
return sprintf ( V_63 , L_9 , V_6 ) ;
}
static T_4 F_56 ( struct V_8 * V_9 , struct V_61 * V_62 ,
const char * V_63 , T_5 V_65 )
{
unsigned long V_32 ;
int V_13 ;
if ( F_46 ( V_63 , 10 , & V_32 ) )
return - V_33 ;
V_13 = F_23 ( V_9 , V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_65 ;
}
static T_4 F_57 ( struct V_8 * V_9 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_9 , ! ! ( V_10 -> V_25 & V_66 ) ) ;
}
static T_4 F_58 ( struct V_8 * V_9 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
return sprintf ( V_63 , L_9 , ! ( V_10 -> V_25 & V_64 ) ) ;
}
static inline int F_59 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
V_10 -> V_29 |= V_67 ;
V_10 -> V_29 |= V_68 ;
V_10 -> V_18 = false ;
return F_16 ( V_10 -> V_12 , V_28 ,
V_10 -> V_29 ) ;
}
static int F_60 ( struct V_11 * V_12 , const struct V_69 * V_70 )
{
struct V_8 * V_9 = & V_12 -> V_9 ;
struct V_7 * V_10 ;
int V_13 ;
if ( ! F_61 ( V_12 -> V_71 ,
V_72 ) )
return - V_73 ;
V_10 = F_62 ( V_9 , sizeof( struct V_7 ) , V_74 ) ;
if ( ! V_10 )
return - V_75 ;
F_63 ( V_12 , V_10 ) ;
V_10 -> V_12 = V_12 ;
F_64 ( & V_10 -> V_14 ) ;
V_13 = F_59 ( V_9 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_28 ( V_12 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_40 ( V_12 ) ;
if ( V_13 )
goto V_76;
V_13 = F_41 ( V_12 ) ;
if ( V_13 )
goto V_76;
V_10 -> V_77 = F_65 ( V_9 , V_12 -> V_78 ,
V_10 , V_79 ) ;
if ( F_14 ( V_10 -> V_77 ) ) {
V_13 = F_15 ( V_10 -> V_77 ) ;
goto V_76;
}
return 0 ;
V_76:
F_35 ( V_12 ) ;
return V_13 ;
}
static int F_66 ( struct V_11 * V_12 )
{
struct V_7 * V_10 = F_33 ( V_12 ) ;
F_67 ( V_10 -> V_77 ) ;
F_35 ( V_12 ) ;
return 0 ;
}
