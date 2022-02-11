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
int V_9 = 0 ;
F_1 ( V_10 , V_4 ) ;
V_4 -> V_11 [ 0 ] = V_14 | V_21 ;
V_4 -> V_11 [ 1 ] = V_22 ;
V_9 = F_6 ( V_4 -> V_12 , & V_16 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_13 = true ;
return V_4 -> V_19 [ 1 ] ;
}
static inline
int F_7 ( struct V_3 * V_4 )
{
int V_9 ;
unsigned char V_23 ;
V_23 = ( unsigned char ) ( V_4 -> V_24 * ( 1 << 15 ) / V_4 -> V_25 ) ;
if ( V_23 < V_26 || V_23 > V_27 ) {
F_8 ( & V_4 -> V_12 -> V_28 , L_1 ) ;
return - V_29 ;
}
V_9 = F_3 ( V_4 , V_30 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( V_4 , V_23 ) ;
}
static unsigned char F_9 ( struct V_3 * V_4 )
{
return V_31 [
( F_10 ( V_4 -> V_5 -> V_32 [ 0 ] ) << 1 ) |
F_10 ( V_4 -> V_5 -> V_32 [ 1 ] ) ] ;
}
static inline void F_11 ( struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 -> V_32 [ 0 ] ,
V_33 [ ( V_4 -> V_34 - 10 ) / 2 ] [ 0 ] ) ;
F_2 ( V_4 -> V_5 -> V_32 [ 1 ] ,
V_33 [ ( V_4 -> V_34 - 10 ) / 2 ] [ 1 ] ) ;
}
static inline int F_12 ( struct V_3 * V_4 )
{
int V_9 ;
V_9 = F_3 ( V_4 , V_35 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( V_4 , 0x0 ) ;
}
static T_2 F_13 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
return sprintf ( V_39 , L_2 , V_4 -> V_25 ) ;
}
static T_2 F_16 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
const char * V_39 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
unsigned int V_25 ;
int V_9 ;
V_9 = F_17 ( V_39 , 10 , & V_25 ) ;
if ( V_9 )
return V_9 ;
if ( V_25 < V_40 || V_25 > V_41 ) {
F_8 ( V_28 , L_3 ) ;
return - V_42 ;
}
F_18 ( & V_4 -> V_43 ) ;
V_4 -> V_25 = V_25 ;
V_9 = F_7 ( V_4 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_12 ( V_4 ) ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_20 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
return sprintf ( V_39 , L_2 , V_4 -> V_24 ) ;
}
static T_2 F_21 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_17 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
unsigned int V_24 ;
int V_9 ;
V_9 = F_17 ( V_39 , 10 , & V_24 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_24 < V_45 || V_24 > V_46 ) {
F_8 ( V_28 ,
L_4 ) ;
return - V_42 ;
}
F_18 ( & V_4 -> V_43 ) ;
V_4 -> V_24 = V_24 ;
V_9 = F_7 ( V_4 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_12 ( V_4 ) ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_22 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_43 ) ;
V_9 = F_5 ( V_4 , V_47 ) ;
F_19 ( & V_4 -> V_43 ) ;
return V_9 < 0 ? V_9 : sprintf ( V_39 , L_5 , V_9 ) ;
}
static T_2 F_23 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_17 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
unsigned char V_48 ;
unsigned char V_8 ;
int V_9 ;
V_9 = F_24 ( V_39 , 16 , & V_48 ) ;
if ( V_9 )
return - V_42 ;
F_18 ( & V_4 -> V_43 ) ;
V_9 = F_3 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
V_8 = V_48 & V_49 ;
V_9 = F_3 ( V_4 , V_8 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_5 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
if ( V_9 & V_21 ) {
V_9 = - V_50 ;
F_8 ( V_28 ,
L_6 ) ;
goto V_44;
}
V_4 -> V_34
= V_31 [ V_8 & V_51 ] ;
if ( V_4 -> V_5 -> V_52 ) {
V_8 = F_9 ( V_4 ) ;
if ( V_8 != V_4 -> V_34 )
F_25 ( V_28 , L_7 ) ;
} else {
F_11 ( V_4 ) ;
}
V_9 = V_17 ;
V_4 -> V_53 = ! ! ( V_8 & V_54 ) ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 ;
}
static T_2 F_26 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
return sprintf ( V_39 , L_8 , V_4 -> V_34 ) ;
}
static T_2 F_27 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_17 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
unsigned char V_8 ;
unsigned char V_48 ;
int V_9 ;
V_9 = F_24 ( V_39 , 10 , & V_48 ) ;
if ( V_9 || V_48 < 10 || V_48 > 16 ) {
F_8 ( V_28 , L_9 ) ;
return - V_42 ;
}
F_18 ( & V_4 -> V_43 ) ;
V_9 = F_5 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
V_8 = V_9 ;
V_8 &= ~ V_51 ;
V_8 |= ( V_48 - 10 ) >> 1 ;
V_9 = F_3 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_3 ( V_4 , V_8 & V_49 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_5 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
V_8 = V_9 ;
if ( V_8 & V_21 ) {
V_9 = - V_50 ;
F_8 ( V_28 , L_10 ) ;
goto V_44;
}
V_4 -> V_34
= V_31 [ V_8 & V_51 ] ;
if ( V_4 -> V_5 -> V_52 ) {
V_8 = F_9 ( V_4 ) ;
if ( V_8 != V_4 -> V_34 )
F_25 ( V_28 , L_7 ) ;
} else {
F_11 ( V_4 ) ;
}
V_9 = V_17 ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 ;
}
static T_2 F_28 ( struct V_36 * V_28 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_43 ) ;
V_9 = F_5 ( V_4 , V_22 ) ;
F_19 ( & V_4 -> V_43 ) ;
return V_9 ? V_9 : sprintf ( V_39 , L_5 , V_9 ) ;
}
static T_2 F_29 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
const char * V_39 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_43 ) ;
F_2 ( V_4 -> V_5 -> V_55 , 0 ) ;
F_30 ( 1 ) ;
F_2 ( V_4 -> V_5 -> V_55 , 1 ) ;
V_9 = F_5 ( V_4 , V_22 ) ;
if ( V_9 < 0 )
goto V_44;
F_2 ( V_4 -> V_5 -> V_55 , 0 ) ;
F_2 ( V_4 -> V_5 -> V_55 , 1 ) ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_31 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
struct V_56 * V_57 = F_32 ( V_38 ) ;
int V_9 ;
F_18 ( & V_4 -> V_43 ) ;
V_9 = F_5 ( V_4 , V_57 -> V_14 ) ;
F_19 ( & V_4 -> V_43 ) ;
return V_9 < 0 ? V_9 : sprintf ( V_39 , L_8 , V_9 ) ;
}
static T_2 F_33 ( struct V_36 * V_28 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_17 )
{
struct V_3 * V_4 = F_14 ( F_15 ( V_28 ) ) ;
unsigned char V_8 ;
int V_9 ;
struct V_56 * V_57 = F_32 ( V_38 ) ;
V_9 = F_24 ( V_39 , 10 , & V_8 ) ;
if ( V_9 )
return - V_42 ;
F_18 ( & V_4 -> V_43 ) ;
V_9 = F_3 ( V_4 , V_57 -> V_14 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_3 ( V_4 , V_8 & V_49 ) ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static int F_34 ( struct V_58 * V_59 ,
struct V_60 const * V_61 ,
int * V_62 ,
int * V_63 ,
long V_64 )
{
struct V_3 * V_4 = F_14 ( V_59 ) ;
T_4 V_65 ;
int V_9 = 0 ;
T_4 V_66 ;
T_5 V_67 ;
F_18 ( & V_4 -> V_43 ) ;
F_2 ( V_4 -> V_5 -> V_55 , 0 ) ;
F_30 ( 1 ) ;
switch ( V_61 -> type ) {
case V_68 :
F_1 ( V_69 , V_4 ) ;
break;
case V_70 :
F_1 ( V_71 , V_4 ) ;
break;
default:
V_9 = - V_42 ;
break;
}
if ( V_9 < 0 )
goto V_44;
V_9 = F_35 ( V_4 -> V_12 , V_4 -> V_19 , 2 ) ;
if ( V_9 < 0 )
goto V_44;
switch ( V_61 -> type ) {
case V_68 :
V_66 = F_36 ( ( V_72 * ) V_4 -> V_19 ) ;
if ( V_4 -> V_53 )
V_66 >>= 16 - V_4 -> V_34 ;
* V_62 = V_66 ;
V_9 = V_73 ;
break;
case V_70 :
V_65 = V_4 -> V_19 [ 0 ] & 0x80 ;
V_67 = F_36 ( ( V_72 * ) V_4 -> V_19 ) ;
V_67 >>= 16 - V_4 -> V_34 ;
if ( V_67 & 0x8000 ) {
V_65 = ( 0xffff >> V_4 -> V_34 ) << V_4 -> V_34 ;
V_67 |= V_65 ;
}
* V_62 = V_67 ;
V_9 = V_73 ;
break;
default:
F_19 ( & V_4 -> V_43 ) ;
return - V_42 ;
}
V_44:
F_2 ( V_4 -> V_5 -> V_55 , 1 ) ;
F_30 ( 1 ) ;
F_19 ( & V_4 -> V_43 ) ;
return V_9 ;
}
static int F_37 ( struct V_3 * V_4 )
{
unsigned char V_8 ;
int V_9 ;
F_18 ( & V_4 -> V_43 ) ;
if ( V_4 -> V_5 -> V_52 )
V_4 -> V_34 = F_9 ( V_4 ) ;
else
F_11 ( V_4 ) ;
V_9 = F_3 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
V_8 = V_74 & ~ ( V_51 ) ;
V_8 |= ( V_4 -> V_34 - 10 ) >> 1 ;
V_9 = F_3 ( V_4 , V_8 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_5 ( V_4 , V_47 ) ;
if ( V_9 < 0 )
goto V_44;
if ( V_9 & V_21 ) {
V_9 = - V_50 ;
goto V_44;
}
V_9 = F_7 ( V_4 ) ;
if ( V_9 < 0 )
goto V_44;
V_9 = F_12 ( V_4 ) ;
V_44:
F_19 ( & V_4 -> V_43 ) ;
return V_9 ;
}
static int F_38 ( struct V_3 * V_4 )
{
unsigned long V_75 = V_4 -> V_5 -> V_52 ? V_76 : V_77 ;
struct V_78 V_79 [] = {
{ V_4 -> V_5 -> V_55 , V_76 , L_11 } ,
{ V_4 -> V_5 -> V_6 [ 0 ] , V_75 , L_12 } ,
{ V_4 -> V_5 -> V_6 [ 1 ] , V_75 , L_13 } ,
{ V_4 -> V_5 -> V_32 [ 0 ] , V_75 , L_14 } ,
{ V_4 -> V_5 -> V_32 [ 0 ] , V_75 , L_15 } ,
} ;
return F_39 ( V_79 , F_40 ( V_79 ) ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
unsigned long V_75 = V_4 -> V_5 -> V_52 ? V_76 : V_77 ;
struct V_78 V_79 [] = {
{ V_4 -> V_5 -> V_55 , V_76 , L_11 } ,
{ V_4 -> V_5 -> V_6 [ 0 ] , V_75 , L_12 } ,
{ V_4 -> V_5 -> V_6 [ 1 ] , V_75 , L_13 } ,
{ V_4 -> V_5 -> V_32 [ 0 ] , V_75 , L_14 } ,
{ V_4 -> V_5 -> V_32 [ 0 ] , V_75 , L_15 } ,
} ;
F_42 ( V_79 , F_40 ( V_79 ) ) ;
}
static int F_43 ( struct V_80 * V_81 )
{
struct V_58 * V_59 ;
struct V_3 * V_4 ;
int V_9 ;
if ( ! V_81 -> V_28 . V_82 )
return - V_42 ;
V_59 = F_44 ( & V_81 -> V_28 , sizeof( * V_4 ) ) ;
if ( ! V_59 )
return - V_83 ;
V_4 = F_14 ( V_59 ) ;
V_4 -> V_5 = V_81 -> V_28 . V_82 ;
V_9 = F_38 ( V_4 ) ;
if ( V_9 < 0 )
return V_9 ;
F_45 ( V_81 , V_59 ) ;
F_46 ( & V_4 -> V_43 ) ;
V_4 -> V_12 = V_81 ;
V_4 -> V_53 = true ;
V_4 -> V_2 = V_10 ;
V_4 -> V_34 = 12 ;
V_4 -> V_24 = V_84 ;
V_59 -> V_28 . V_85 = & V_81 -> V_28 ;
V_59 -> V_86 = & V_87 ;
V_59 -> V_88 = V_89 ;
V_59 -> V_90 = V_91 ;
V_59 -> V_92 = F_40 ( V_91 ) ;
V_59 -> V_93 = F_47 ( V_81 ) -> V_93 ;
V_9 = F_48 ( V_59 ) ;
if ( V_9 )
goto V_94;
V_4 -> V_25 = V_81 -> V_95 ;
V_81 -> V_2 = V_96 ;
F_49 ( V_81 ) ;
F_37 ( V_4 ) ;
return 0 ;
V_94:
F_41 ( V_4 ) ;
return V_9 ;
}
static int F_50 ( struct V_80 * V_81 )
{
struct V_58 * V_59 = F_51 ( V_81 ) ;
F_52 ( V_59 ) ;
F_41 ( F_14 ( V_59 ) ) ;
return 0 ;
}
