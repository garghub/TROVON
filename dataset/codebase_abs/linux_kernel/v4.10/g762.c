static inline unsigned int F_1 ( T_1 V_1 , T_2 V_2 , T_3 V_3 ,
T_1 V_4 , T_1 V_5 )
{
if ( V_1 == 0xff )
return 0 ;
return ( V_2 * 30 * V_5 ) / ( ( V_1 ? V_1 : 1 ) * V_3 * V_4 ) ;
}
static inline unsigned char F_2 ( unsigned long V_6 , T_2 V_2 , T_3 V_3 ,
T_1 V_4 , T_1 V_5 )
{
unsigned long V_7 = V_2 * 30 * V_5 ;
unsigned long V_8 = V_3 * V_4 ;
if ( ! V_6 )
return 0xff ;
V_6 = F_3 ( V_6 , V_7 / ( 255 * V_8 ) , V_9 / V_8 ) ;
return F_4 ( V_7 , V_6 * V_8 ) ;
}
static struct V_10 * F_5 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = F_6 ( V_12 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
int V_16 = 0 ;
F_7 ( & V_13 -> V_17 ) ;
if ( F_8 ( V_18 , V_13 -> V_19 + V_20 ) &&
F_9 ( V_13 -> V_21 ) )
goto V_22;
V_16 = F_10 ( V_15 , V_23 ) ;
if ( V_16 < 0 )
goto V_22;
V_13 -> V_24 = V_16 ;
V_16 = F_10 ( V_15 , V_25 ) ;
if ( V_16 < 0 )
goto V_22;
V_13 -> V_26 = V_16 ;
V_16 = F_10 ( V_15 , V_27 ) ;
if ( V_16 < 0 )
goto V_22;
V_13 -> V_28 = V_16 ;
V_16 = F_10 ( V_15 , V_29 ) ;
if ( V_16 < 0 )
goto V_22;
V_13 -> V_30 = V_16 ;
V_16 = F_10 ( V_15 , V_31 ) ;
if ( V_16 < 0 )
goto V_22;
V_13 -> V_32 = V_16 ;
V_16 = F_10 ( V_15 , V_33 ) ;
if ( V_16 < 0 )
goto V_22;
V_13 -> V_34 = V_16 ;
V_13 -> V_19 = V_18 ;
V_13 -> V_21 = true ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
if ( V_16 < 0 )
V_13 = F_12 ( V_16 ) ;
return V_13 ;
}
static int F_13 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_6 ( V_12 ) ;
if ( V_35 > 0xffffff )
return - V_36 ;
if ( ! V_35 )
V_35 = 32768 ;
V_13 -> V_2 = V_35 ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case V_37 :
V_13 -> V_32 |= V_38 ;
break;
case V_39 :
V_13 -> V_32 &= ~ V_38 ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_31 ,
V_13 -> V_32 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_18 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case 1 :
V_13 -> V_32 &= ~ V_40 ;
V_13 -> V_32 &= ~ V_41 ;
break;
case 2 :
V_13 -> V_32 |= V_40 ;
V_13 -> V_32 &= ~ V_41 ;
break;
case 4 :
V_13 -> V_32 &= ~ V_40 ;
V_13 -> V_32 |= V_41 ;
break;
case 8 :
V_13 -> V_32 |= V_40 ;
V_13 -> V_32 |= V_41 ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_31 ,
V_13 -> V_32 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_19 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case 0 :
V_13 -> V_34 &= ~ V_42 ;
V_13 -> V_34 &= ~ V_43 ;
break;
case 1 :
V_13 -> V_34 |= V_42 ;
V_13 -> V_34 &= ~ V_43 ;
break;
case 2 :
V_13 -> V_34 &= ~ V_42 ;
V_13 -> V_34 |= V_43 ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_33 ,
V_13 -> V_34 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_20 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case 2 :
V_13 -> V_32 &= ~ V_44 ;
break;
case 4 :
V_13 -> V_32 |= V_44 ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_31 ,
V_13 -> V_32 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_21 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case V_45 :
V_13 -> V_32 |= V_46 ;
break;
case V_47 :
V_13 -> V_32 &= ~ V_46 ;
if ( V_13 -> V_24 == 0xff )
F_17 ( V_13 -> V_15 ,
V_23 , 254 ) ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_31 ,
V_13 -> V_32 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_22 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case V_48 :
V_13 -> V_32 &= ~ V_49 ;
break;
case V_50 :
V_13 -> V_32 |= V_49 ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_31 ,
V_13 -> V_32 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_23 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_6 ( V_12 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
int V_16 ;
if ( V_35 > 255 )
return - V_36 ;
F_7 ( & V_13 -> V_17 ) ;
V_16 = F_17 ( V_15 , V_29 , V_35 ) ;
V_13 -> V_21 = false ;
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_24 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_13 -> V_24 = F_2 ( V_35 , V_13 -> V_2 ,
F_25 ( V_13 -> V_32 ) ,
F_26 ( V_13 -> V_32 ) ,
F_27 ( V_13 -> V_34 ) ) ;
V_16 = F_17 ( V_13 -> V_15 , V_23 ,
V_13 -> V_24 ) ;
V_13 -> V_21 = false ;
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_28 ( struct V_11 * V_12 , unsigned long V_35 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
int V_16 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
switch ( V_35 ) {
case 0 :
V_13 -> V_34 &= ~ V_51 ;
V_13 -> V_34 &= ~ V_52 ;
break;
case 1 :
V_13 -> V_34 |= V_51 ;
V_13 -> V_34 &= ~ V_52 ;
break;
case 2 :
V_13 -> V_34 &= ~ V_51 ;
V_13 -> V_34 |= V_52 ;
break;
case 3 :
V_13 -> V_34 |= V_51 ;
V_13 -> V_34 |= V_52 ;
break;
default:
V_16 = - V_36 ;
goto V_22;
}
V_16 = F_17 ( V_13 -> V_15 , V_33 ,
V_13 -> V_34 ) ;
V_13 -> V_21 = false ;
V_22:
F_11 ( & V_13 -> V_17 ) ;
return V_16 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_10 * V_13 ;
unsigned long V_2 ;
struct V_53 * V_53 ;
int V_16 ;
if ( ! V_15 -> V_12 . V_54 )
return 0 ;
V_53 = F_30 ( V_15 -> V_12 . V_54 , 0 ) ;
if ( F_15 ( V_53 ) ) {
F_31 ( & V_15 -> V_12 , L_1 ) ;
return F_16 ( V_53 ) ;
}
V_16 = F_32 ( V_53 ) ;
if ( V_16 ) {
F_31 ( & V_15 -> V_12 , L_2 ) ;
goto V_55;
}
V_2 = F_33 ( V_53 ) ;
V_16 = F_13 ( & V_15 -> V_12 , V_2 ) ;
if ( V_16 ) {
F_31 ( & V_15 -> V_12 , L_3 , V_2 ) ;
goto V_56;
}
V_13 = F_34 ( V_15 ) ;
V_13 -> V_53 = V_53 ;
return 0 ;
V_56:
F_35 ( V_53 ) ;
V_55:
V_55 ( V_53 ) ;
return V_16 ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_10 * V_13 = F_34 ( V_15 ) ;
if ( ! V_13 -> V_53 )
return;
F_35 ( V_13 -> V_53 ) ;
V_55 ( V_13 -> V_53 ) ;
}
static int F_37 ( struct V_14 * V_15 ,
const char * V_57 ,
int (* F_38)( struct V_11 * V_12 ,
unsigned long V_35 ) )
{
int V_16 ;
T_2 V_58 ;
if ( F_39 ( V_15 -> V_12 . V_54 , V_57 , & V_58 ) )
return 0 ;
F_40 ( & V_15 -> V_12 , L_4 , V_57 , V_58 ) ;
V_16 = (* F_38)( & V_15 -> V_12 , V_58 ) ;
if ( V_16 )
F_31 ( & V_15 -> V_12 , L_5 , V_57 , V_58 ) ;
return V_16 ;
}
static int F_41 ( struct V_14 * V_15 )
{
int V_16 ;
if ( ! V_15 -> V_12 . V_54 )
return 0 ;
V_16 = F_37 ( V_15 , L_6 ,
F_19 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_37 ( V_15 , L_7 ,
F_22 ) ;
if ( V_16 )
return V_16 ;
return F_37 ( V_15 , L_8 ,
F_28 ) ;
}
static int F_41 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
return 0 ;
}
static void F_36 ( struct V_14 * V_15 ) { }
static int F_42 ( struct V_14 * V_15 )
{
struct V_59 * V_60 = F_43 ( & V_15 -> V_12 ) ;
int V_16 ;
if ( ! V_60 )
return 0 ;
V_16 = F_19 ( & V_15 -> V_12 , V_60 -> V_61 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_22 ( & V_15 -> V_12 , V_60 -> V_62 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_28 ( & V_15 -> V_12 , V_60 -> V_63 ) ;
if ( V_16 )
return V_16 ;
return F_13 ( & V_15 -> V_12 , V_60 -> V_2 ) ;
}
static T_4 F_44 ( struct V_11 * V_12 , struct V_64 * V_65 ,
char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
unsigned int V_6 = 0 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_28 & V_67 ) {
V_6 = F_1 ( V_13 -> V_26 , V_13 -> V_2 ,
F_25 ( V_13 -> V_32 ) ,
F_26 ( V_13 -> V_32 ) ,
F_27 ( V_13 -> V_34 ) ) ;
}
F_11 ( & V_13 -> V_17 ) ;
return sprintf ( V_66 , L_9 , V_6 ) ;
}
static T_4 F_45 ( struct V_11 * V_12 , struct V_64 * V_65 ,
char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_10 ,
! ! ( V_13 -> V_32 & V_38 ) ) ;
}
static T_4 F_46 ( struct V_11 * V_12 , struct V_64 * V_65 ,
const char * V_66 , T_5 V_68 )
{
unsigned long V_35 ;
int V_16 ;
if ( F_47 ( V_66 , 10 , & V_35 ) )
return - V_36 ;
V_16 = F_14 ( V_12 , V_35 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_68 ;
}
static T_4 F_48 ( struct V_11 * V_12 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_10 , F_26 ( V_13 -> V_32 ) ) ;
}
static T_4 F_49 ( struct V_11 * V_12 ,
struct V_64 * V_65 ,
const char * V_66 , T_5 V_68 )
{
unsigned long V_35 ;
int V_16 ;
if ( F_47 ( V_66 , 10 , & V_35 ) )
return - V_36 ;
V_16 = F_18 ( V_12 , V_35 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_68 ;
}
static T_4 F_50 ( struct V_11 * V_12 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_10 , F_25 ( V_13 -> V_32 ) ) ;
}
static T_4 F_51 ( struct V_11 * V_12 ,
struct V_64 * V_65 ,
const char * V_66 , T_5 V_68 )
{
unsigned long V_35 ;
int V_16 ;
if ( F_47 ( V_66 , 10 , & V_35 ) )
return - V_36 ;
V_16 = F_20 ( V_12 , V_35 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_68 ;
}
static T_4 F_52 ( struct V_11 * V_12 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_10 ,
( ! ! ( V_13 -> V_32 & V_46 ) ) + 1 ) ;
}
static T_4 F_53 ( struct V_11 * V_12 ,
struct V_64 * V_65 ,
const char * V_66 , T_5 V_68 )
{
unsigned long V_35 ;
int V_16 ;
if ( F_47 ( V_66 , 10 , & V_35 ) )
return - V_36 ;
V_16 = F_21 ( V_12 , V_35 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_68 ;
}
static T_4 F_54 ( struct V_11 * V_12 , struct V_64 * V_65 ,
char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_10 , V_13 -> V_30 ) ;
}
static T_4 F_55 ( struct V_11 * V_12 , struct V_64 * V_65 ,
const char * V_66 , T_5 V_68 )
{
unsigned long V_35 ;
int V_16 ;
if ( F_47 ( V_66 , 10 , & V_35 ) )
return - V_36 ;
V_16 = F_23 ( V_12 , V_35 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_68 ;
}
static T_4 F_56 ( struct V_11 * V_12 , struct V_64 * V_65 ,
char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
unsigned int V_6 ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_6 = F_1 ( V_13 -> V_24 , V_13 -> V_2 ,
F_25 ( V_13 -> V_32 ) ,
F_26 ( V_13 -> V_32 ) ,
F_27 ( V_13 -> V_34 ) ) ;
F_11 ( & V_13 -> V_17 ) ;
return sprintf ( V_66 , L_9 , V_6 ) ;
}
static T_4 F_57 ( struct V_11 * V_12 , struct V_64 * V_65 ,
const char * V_66 , T_5 V_68 )
{
unsigned long V_35 ;
int V_16 ;
if ( F_47 ( V_66 , 10 , & V_35 ) )
return - V_36 ;
V_16 = F_24 ( V_12 , V_35 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_68 ;
}
static T_4 F_58 ( struct V_11 * V_12 , struct V_64 * V_65 ,
char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_9 , ! ! ( V_13 -> V_28 & V_69 ) ) ;
}
static T_4 F_59 ( struct V_11 * V_12 , struct V_64 * V_65 ,
char * V_66 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
return sprintf ( V_66 , L_9 , ! ( V_13 -> V_28 & V_67 ) ) ;
}
static inline int F_60 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
if ( F_15 ( V_13 ) )
return F_16 ( V_13 ) ;
V_13 -> V_32 |= V_70 ;
V_13 -> V_32 |= V_71 ;
V_13 -> V_21 = false ;
return F_17 ( V_13 -> V_15 , V_31 ,
V_13 -> V_32 ) ;
}
static int F_61 ( struct V_14 * V_15 , const struct V_72 * V_73 )
{
struct V_11 * V_12 = & V_15 -> V_12 ;
struct V_10 * V_13 ;
int V_16 ;
if ( ! F_62 ( V_15 -> V_74 ,
V_75 ) )
return - V_76 ;
V_13 = F_63 ( V_12 , sizeof( struct V_10 ) , V_77 ) ;
if ( ! V_13 )
return - V_78 ;
F_64 ( V_15 , V_13 ) ;
V_13 -> V_15 = V_15 ;
F_65 ( & V_13 -> V_17 ) ;
V_16 = F_60 ( V_12 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_29 ( V_15 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_41 ( V_15 ) ;
if ( V_16 )
goto V_79;
V_16 = F_42 ( V_15 ) ;
if ( V_16 )
goto V_79;
V_13 -> V_80 = F_66 ( V_12 , V_15 -> V_81 ,
V_13 , V_82 ) ;
if ( F_15 ( V_13 -> V_80 ) ) {
V_16 = F_16 ( V_13 -> V_80 ) ;
goto V_79;
}
return 0 ;
V_79:
F_36 ( V_15 ) ;
return V_16 ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_10 * V_13 = F_34 ( V_15 ) ;
F_68 ( V_13 -> V_80 ) ;
F_36 ( V_15 ) ;
return 0 ;
}
