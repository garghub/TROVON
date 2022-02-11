static inline void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 -> V_6 [ 0 ] , V_7 [ V_2 ] [ 0 ] ) ;
F_2 ( V_4 -> V_5 -> V_6 [ 1 ] , V_7 [ V_2 ] [ 1 ] ) ;
V_4 -> V_2 = V_2 ;
}
static int F_3 ( struct V_3 * V_4 , T_1 V_8 )
{
int V_9 ;
F_1 ( V_10 , V_4 ) ;
V_4 -> V_11 [ 0 ] = V_8 ;
V_9 = F_4 ( V_4 -> V_12 , V_4 -> V_11 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_13 = true ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 ,
unsigned char V_14 )
{
struct V_15 V_16 = {
. V_17 = 2 ,
. V_18 = V_4 -> V_19 ,
. V_20 = V_4 -> V_11 ,
} ;
struct V_21 V_22 ;
int V_9 = 0 ;
F_1 ( V_10 , V_4 ) ;
F_6 ( & V_22 ) ;
F_7 ( & V_16 , & V_22 ) ;
V_4 -> V_11 [ 0 ] = V_14 | V_23 ;
V_4 -> V_11 [ 1 ] = V_24 ;
V_9 = F_8 ( V_4 -> V_12 , & V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_13 = true ;
return V_4 -> V_19 [ 1 ] ;
}
static inline
int F_9 ( struct V_3 * V_4 )
{
int V_9 ;
unsigned char V_25 ;
V_25 = ( unsigned char ) ( V_4 -> V_26 * ( 1 << 15 ) / V_4 -> V_27 ) ;
if ( V_25 < V_28 || V_25 > V_29 ) {
F_10 ( L_1 ) ;
return - V_30 ;
}
V_9 = F_3 ( V_4 , V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( V_4 , V_25 ) ;
}
static unsigned char F_11 ( struct V_3 * V_4 )
{
return V_32 [
( F_12 ( V_4 -> V_5 -> V_33 [ 0 ] ) << 1 ) |
F_12 ( V_4 -> V_5 -> V_33 [ 1 ] ) ] ;
}
static inline void F_13 ( struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 -> V_33 [ 0 ] ,
V_34 [ ( V_4 -> V_35 - 10 ) / 2 ] [ 0 ] ) ;
F_2 ( V_4 -> V_5 -> V_33 [ 1 ] ,
V_34 [ ( V_4 -> V_35 - 10 ) / 2 ] [ 1 ] ) ;
}
static inline int F_14 ( struct V_3 * V_4 )
{
int V_9 ;
V_9 = F_3 ( V_4 , V_36 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( V_4 , 0x0 ) ;
}
static T_2 F_15 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 = 0 ;
F_18 ( & V_4 -> V_42 ) ;
if ( V_4 -> V_13 ) {
V_9 = sprintf ( V_41 , L_2 , V_4 -> V_19 [ 0 ] ) ;
V_4 -> V_13 = false ;
}
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static T_2 F_20 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_43 ;
unsigned char V_8 ;
int V_9 ;
V_9 = F_21 ( V_41 , 16 , & V_43 ) ;
if ( V_9 )
return - V_44 ;
V_8 = V_43 & 0xff ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_3 ( V_4 , V_8 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_22 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_14 ( V_4 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_23 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
return sprintf ( V_41 , L_3 , V_4 -> V_27 ) ;
}
static T_2 F_24 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_27 ;
int V_9 ;
V_9 = F_21 ( V_41 , 10 , & V_27 ) ;
if ( V_9 )
return V_9 ;
if ( V_27 < V_45 || V_27 > V_46 ) {
F_10 ( L_4 ) ;
return - V_44 ;
}
F_18 ( & V_4 -> V_42 ) ;
V_4 -> V_27 = V_27 ;
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_14 ( V_4 ) ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_25 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
return sprintf ( V_41 , L_3 , V_4 -> V_26 ) ;
}
static T_2 F_26 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_26 ;
int V_9 ;
V_9 = F_21 ( V_41 , 10 , & V_26 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_26 < V_48 || V_26 > V_49 ) {
F_10 ( L_5 ) ;
return - V_44 ;
}
F_18 ( & V_4 -> V_42 ) ;
V_4 -> V_26 = V_26 ;
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_14 ( V_4 ) ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_27 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_50 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : sprintf ( V_41 , L_2 , V_9 ) ;
}
static T_2 F_28 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_43 ;
unsigned char V_8 ;
int V_9 ;
V_9 = F_21 ( V_41 , 16 , & V_43 ) ;
if ( V_9 )
return - V_44 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_3 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
V_8 = V_43 & V_51 ;
V_9 = F_3 ( V_4 , V_8 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_5 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
if ( V_9 & V_23 ) {
V_9 = - V_52 ;
F_10 ( L_6 ) ;
goto V_47;
}
V_4 -> V_35
= V_32 [ V_8 & V_53 ] ;
if ( V_4 -> V_5 -> V_54 ) {
V_8 = F_11 ( V_4 ) ;
if ( V_8 != V_4 -> V_35 )
F_29 ( L_7 ) ;
} else
F_13 ( V_4 ) ;
V_9 = V_17 ;
V_4 -> V_55 = ! ! ( V_8 & V_56 ) ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static T_2 F_30 ( struct V_37 * V_38 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
return sprintf ( V_41 , L_3 , V_4 -> V_35 ) ;
}
static T_2 F_31 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned char V_8 ;
unsigned long V_43 ;
int V_9 ;
V_9 = F_21 ( V_41 , 10 , & V_43 ) ;
if ( V_9 || V_43 < 10 || V_43 > 16 ) {
F_10 ( L_8 ) ;
return - V_44 ;
}
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
V_8 = V_9 ;
V_8 &= ~ V_53 ;
V_8 |= ( V_43 - 10 ) >> 1 ;
V_9 = F_3 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_3 ( V_4 , V_8 & V_51 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_5 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
V_8 = V_9 ;
if ( V_8 & V_23 ) {
V_9 = - V_52 ;
F_10 ( L_9 ) ;
goto V_47;
}
V_4 -> V_35
= V_32 [ V_8 & V_53 ] ;
if ( V_4 -> V_5 -> V_54 ) {
V_8 = F_11 ( V_4 ) ;
if ( V_8 != V_4 -> V_35 )
F_29 ( L_7 ) ;
} else
F_13 ( V_4 ) ;
V_9 = V_17 ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static T_2 F_32 ( struct V_37 * V_38 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_24 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 ? V_9 : sprintf ( V_41 , L_2 , V_9 ) ;
}
static T_2 F_33 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_34 ( 1 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
V_9 = F_5 ( V_4 , V_24 ) ;
if ( V_9 < 0 )
goto V_47;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_35 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
struct V_58 * V_59 = F_36 ( V_40 ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_59 -> V_14 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : sprintf ( V_41 , L_3 , V_9 ) ;
}
static T_2 F_37 ( struct V_37 * V_38 ,
struct V_39 * V_40 , const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_8 ;
int V_9 ;
struct V_58 * V_59 = F_36 ( V_40 ) ;
V_9 = F_21 ( V_41 , 10 , & V_8 ) ;
if ( V_9 )
return - V_44 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_3 ( V_4 , V_59 -> V_14 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_3 ( V_4 , V_8 & V_51 ) ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_38 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
int V_9 = 0 ;
T_2 V_17 = 0 ;
T_4 V_60 ;
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
F_18 ( & V_4 -> V_42 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_34 ( 1 ) ;
F_1 ( V_61 , V_4 ) ;
V_9 = F_39 ( V_4 -> V_12 , V_4 -> V_19 , 2 ) ;
if ( V_9 )
goto V_47;
V_60 = F_40 ( ( T_4 * ) V_4 -> V_19 ) ;
if ( V_4 -> V_55 )
V_60 >>= 16 - V_4 -> V_35 ;
V_17 = sprintf ( V_41 , L_3 , V_60 ) ;
V_47:
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
F_34 ( 1 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_41 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
unsigned short V_62 ;
int V_9 = 0 ;
T_2 V_17 = 0 ;
T_5 V_63 ;
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
F_18 ( & V_4 -> V_42 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_34 ( 1 ) ;
F_1 ( V_64 , V_4 ) ;
V_9 = F_39 ( V_4 -> V_12 , V_4 -> V_19 , 2 ) ;
if ( V_9 )
goto V_47;
V_62 = V_4 -> V_19 [ 0 ] & 0x80 ;
V_63 = F_40 ( ( T_5 * ) V_4 -> V_19 ) ;
V_63 >>= 16 - V_4 -> V_35 ;
if ( V_63 & 0x8000 ) {
V_62 = ( 0xffff >> V_4 -> V_35 ) << V_4 -> V_35 ;
V_63 |= V_62 ;
}
V_17 = sprintf ( V_41 , L_3 , V_63 ) ;
V_47:
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
F_34 ( 1 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static int T_6 F_42 ( struct V_3 * V_4 )
{
unsigned char V_8 ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
if ( V_4 -> V_5 -> V_54 )
V_4 -> V_35 = F_11 ( V_4 ) ;
else
F_13 ( V_4 ) ;
V_9 = F_3 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
V_8 = V_65 & ~ ( V_53 ) ;
V_8 |= ( V_4 -> V_35 - 10 ) >> 1 ;
V_9 = F_3 ( V_4 , V_8 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_5 ( V_4 , V_50 ) ;
if ( V_9 < 0 )
goto V_47;
if ( V_9 & V_23 ) {
V_9 = - V_52 ;
goto V_47;
}
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_14 ( V_4 ) ;
V_47:
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static int F_43 ( struct V_3 * V_4 )
{
int V_9 ;
unsigned long V_66 = V_4 -> V_5 -> V_54 ? V_67 : V_68 ;
V_9 = F_44 ( V_4 -> V_5 -> V_57 , V_67 , L_10 ) ;
if ( V_9 < 0 )
goto V_47;
V_9 = F_44 ( V_4 -> V_5 -> V_6 [ 0 ] , V_66 , L_11 ) ;
if ( V_9 < 0 )
goto V_69;
V_9 = F_44 ( V_4 -> V_5 -> V_6 [ 1 ] , V_66 , L_12 ) ;
if ( V_9 < 0 )
goto V_70;
V_9 = F_44 ( V_4 -> V_5 -> V_33 [ 1 ] , V_66 , L_13 ) ;
if ( V_9 < 0 )
goto V_71;
V_9 = F_44 ( V_4 -> V_5 -> V_33 [ 1 ] , V_66 , L_14 ) ;
if ( V_9 < 0 )
goto V_72;
return 0 ;
V_72:
F_45 ( V_4 -> V_5 -> V_33 [ 0 ] ) ;
V_71:
F_45 ( V_4 -> V_5 -> V_6 [ 1 ] ) ;
V_70:
F_45 ( V_4 -> V_5 -> V_6 [ 0 ] ) ;
V_69:
F_45 ( V_4 -> V_5 -> V_57 ) ;
V_47:
return V_9 ;
}
static void F_46 ( struct V_3 * V_4 )
{
F_45 ( V_4 -> V_5 -> V_33 [ 1 ] ) ;
F_45 ( V_4 -> V_5 -> V_33 [ 0 ] ) ;
F_45 ( V_4 -> V_5 -> V_6 [ 1 ] ) ;
F_45 ( V_4 -> V_5 -> V_6 [ 0 ] ) ;
F_45 ( V_4 -> V_5 -> V_57 ) ;
}
static int T_6 F_47 ( struct V_73 * V_74 )
{
struct V_75 * V_76 ;
struct V_3 * V_4 ;
int V_9 ;
if ( V_74 -> V_38 . V_77 == NULL )
return - V_44 ;
V_76 = F_48 ( sizeof( * V_4 ) ) ;
if ( V_76 == NULL ) {
V_9 = - V_78 ;
goto V_47;
}
V_4 = F_16 ( V_76 ) ;
V_4 -> V_5 = V_74 -> V_38 . V_77 ;
V_9 = F_43 ( V_4 ) ;
if ( V_9 < 0 )
goto V_79;
F_49 ( V_74 , V_76 ) ;
F_50 ( & V_4 -> V_42 ) ;
V_4 -> V_12 = V_74 ;
V_4 -> V_55 = true ;
V_4 -> V_2 = V_10 ;
V_4 -> V_35 = 12 ;
V_4 -> V_26 = V_80 ;
V_76 -> V_38 . V_81 = & V_74 -> V_38 ;
V_76 -> V_82 = & V_83 ;
V_76 -> V_84 = V_85 ;
V_9 = F_51 ( V_76 ) ;
if ( V_9 )
goto V_86;
V_4 -> V_27 = V_74 -> V_87 ;
V_74 -> V_2 = V_88 ;
F_52 ( V_74 ) ;
F_42 ( V_4 ) ;
return 0 ;
V_86:
F_46 ( V_4 ) ;
V_79:
F_53 ( V_76 ) ;
V_47:
return V_9 ;
}
static int T_7 F_54 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_55 ( V_74 ) ;
struct V_3 * V_4 = F_16 ( V_76 ) ;
F_56 ( V_76 ) ;
F_46 ( V_4 ) ;
return 0 ;
}
static T_8 int F_57 ( void )
{
return F_58 ( & V_89 ) ;
}
static T_9 void F_59 ( void )
{
F_60 ( & V_89 ) ;
}
