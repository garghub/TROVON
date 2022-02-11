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
static T_2 F_20 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
return sprintf ( V_41 , L_2 , V_4 -> V_27 ) ;
}
static T_2 F_21 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_27 ;
int V_9 ;
V_9 = F_22 ( V_41 , 10 , & V_27 ) ;
if ( V_9 )
return V_9 ;
if ( V_27 < V_43 || V_27 > V_44 ) {
F_10 ( L_3 ) ;
return - V_45 ;
}
F_18 ( & V_4 -> V_42 ) ;
V_4 -> V_27 = V_27 ;
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_14 ( V_4 ) ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_23 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
return sprintf ( V_41 , L_2 , V_4 -> V_26 ) ;
}
static T_2 F_24 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_26 ;
int V_9 ;
V_9 = F_22 ( V_41 , 10 , & V_26 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_26 < V_47 || V_26 > V_48 ) {
F_10 ( L_4 ) ;
return - V_45 ;
}
F_18 ( & V_4 -> V_42 ) ;
V_4 -> V_26 = V_26 ;
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_14 ( V_4 ) ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_25 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_49 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : sprintf ( V_41 , L_5 , V_9 ) ;
}
static T_2 F_26 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_50 ;
unsigned char V_8 ;
int V_9 ;
V_9 = F_22 ( V_41 , 16 , & V_50 ) ;
if ( V_9 )
return - V_45 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_3 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
V_8 = V_50 & V_51 ;
V_9 = F_3 ( V_4 , V_8 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_5 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
if ( V_9 & V_23 ) {
V_9 = - V_52 ;
F_10 ( L_6 ) ;
goto V_46;
}
V_4 -> V_35
= V_32 [ V_8 & V_53 ] ;
if ( V_4 -> V_5 -> V_54 ) {
V_8 = F_11 ( V_4 ) ;
if ( V_8 != V_4 -> V_35 )
F_27 ( L_7 ) ;
} else
F_13 ( V_4 ) ;
V_9 = V_17 ;
V_4 -> V_55 = ! ! ( V_8 & V_56 ) ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static T_2 F_28 ( struct V_37 * V_38 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
return sprintf ( V_41 , L_2 , V_4 -> V_35 ) ;
}
static T_2 F_29 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned char V_8 ;
unsigned long V_50 ;
int V_9 ;
V_9 = F_22 ( V_41 , 10 , & V_50 ) ;
if ( V_9 || V_50 < 10 || V_50 > 16 ) {
F_10 ( L_8 ) ;
return - V_45 ;
}
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
V_8 = V_9 ;
V_8 &= ~ V_53 ;
V_8 |= ( V_50 - 10 ) >> 1 ;
V_9 = F_3 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_3 ( V_4 , V_8 & V_51 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_5 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
V_8 = V_9 ;
if ( V_8 & V_23 ) {
V_9 = - V_52 ;
F_10 ( L_9 ) ;
goto V_46;
}
V_4 -> V_35
= V_32 [ V_8 & V_53 ] ;
if ( V_4 -> V_5 -> V_54 ) {
V_8 = F_11 ( V_4 ) ;
if ( V_8 != V_4 -> V_35 )
F_27 ( L_7 ) ;
} else
F_13 ( V_4 ) ;
V_9 = V_17 ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static T_2 F_30 ( struct V_37 * V_38 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_24 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 ? V_9 : sprintf ( V_41 , L_5 , V_9 ) ;
}
static T_2 F_31 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_32 ( 1 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
V_9 = F_5 ( V_4 , V_24 ) ;
if ( V_9 < 0 )
goto V_46;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static T_2 F_33 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
struct V_58 * V_59 = F_34 ( V_40 ) ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_5 ( V_4 , V_59 -> V_14 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : sprintf ( V_41 , L_2 , V_9 ) ;
}
static T_2 F_35 ( struct V_37 * V_38 ,
struct V_39 * V_40 , const char * V_41 , T_3 V_17 )
{
struct V_3 * V_4 = F_16 ( F_17 ( V_38 ) ) ;
unsigned long V_8 ;
int V_9 ;
struct V_58 * V_59 = F_34 ( V_40 ) ;
V_9 = F_22 ( V_41 , 10 , & V_8 ) ;
if ( V_9 )
return - V_45 ;
F_18 ( & V_4 -> V_42 ) ;
V_9 = F_3 ( V_4 , V_59 -> V_14 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_3 ( V_4 , V_8 & V_51 ) ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 < 0 ? V_9 : V_17 ;
}
static int F_36 ( struct V_60 * V_61 ,
struct V_62 const * V_63 ,
int * V_64 ,
int * V_65 ,
long V_66 )
{
struct V_3 * V_4 = F_16 ( V_61 ) ;
bool V_67 ;
int V_9 = 0 ;
T_4 V_68 ;
T_5 V_69 ;
F_18 ( & V_4 -> V_42 ) ;
F_2 ( V_4 -> V_5 -> V_57 , 0 ) ;
F_32 ( 1 ) ;
switch ( V_63 -> type ) {
case V_70 :
F_1 ( V_71 , V_4 ) ;
break;
case V_72 :
F_1 ( V_73 , V_4 ) ;
break;
default:
V_9 = - V_45 ;
break;
}
if ( V_9 < 0 )
goto V_46;
V_9 = F_37 ( V_4 -> V_12 , V_4 -> V_19 , 2 ) ;
if ( V_9 < 0 )
goto V_46;
switch ( V_63 -> type ) {
case V_70 :
V_68 = F_38 ( ( T_4 * ) V_4 -> V_19 ) ;
if ( V_4 -> V_55 )
V_68 >>= 16 - V_4 -> V_35 ;
* V_64 = V_68 ;
V_9 = V_74 ;
break;
case V_72 :
V_67 = V_4 -> V_19 [ 0 ] & 0x80 ;
V_69 = F_38 ( ( T_5 * ) V_4 -> V_19 ) ;
V_69 >>= 16 - V_4 -> V_35 ;
if ( V_69 & 0x8000 ) {
V_67 = ( 0xffff >> V_4 -> V_35 ) << V_4 -> V_35 ;
V_69 |= V_67 ;
}
* V_64 = V_69 ;
V_9 = V_74 ;
break;
default:
F_19 ( & V_4 -> V_42 ) ;
return - V_45 ;
}
V_46:
F_2 ( V_4 -> V_5 -> V_57 , 1 ) ;
F_32 ( 1 ) ;
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static int T_6 F_39 ( struct V_3 * V_4 )
{
unsigned char V_8 ;
int V_9 ;
F_18 ( & V_4 -> V_42 ) ;
if ( V_4 -> V_5 -> V_54 )
V_4 -> V_35 = F_11 ( V_4 ) ;
else
F_13 ( V_4 ) ;
V_9 = F_3 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
V_8 = V_75 & ~ ( V_53 ) ;
V_8 |= ( V_4 -> V_35 - 10 ) >> 1 ;
V_9 = F_3 ( V_4 , V_8 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_5 ( V_4 , V_49 ) ;
if ( V_9 < 0 )
goto V_46;
if ( V_9 & V_23 ) {
V_9 = - V_52 ;
goto V_46;
}
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 )
goto V_46;
V_9 = F_14 ( V_4 ) ;
V_46:
F_19 ( & V_4 -> V_42 ) ;
return V_9 ;
}
static int F_40 ( struct V_3 * V_4 )
{
unsigned long V_76 = V_4 -> V_5 -> V_54 ? V_77 : V_78 ;
struct V_79 V_80 [] = {
{ V_4 -> V_5 -> V_57 , V_77 , L_10 } ,
{ V_4 -> V_5 -> V_6 [ 0 ] , V_76 , L_11 } ,
{ V_4 -> V_5 -> V_6 [ 1 ] , V_76 , L_12 } ,
{ V_4 -> V_5 -> V_33 [ 0 ] , V_76 , L_13 } ,
{ V_4 -> V_5 -> V_33 [ 0 ] , V_76 , L_14 } ,
} ;
return F_41 ( V_80 , F_42 ( V_80 ) ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
unsigned long V_76 = V_4 -> V_5 -> V_54 ? V_77 : V_78 ;
struct V_79 V_80 [] = {
{ V_4 -> V_5 -> V_57 , V_77 , L_10 } ,
{ V_4 -> V_5 -> V_6 [ 0 ] , V_76 , L_11 } ,
{ V_4 -> V_5 -> V_6 [ 1 ] , V_76 , L_12 } ,
{ V_4 -> V_5 -> V_33 [ 0 ] , V_76 , L_13 } ,
{ V_4 -> V_5 -> V_33 [ 0 ] , V_76 , L_14 } ,
} ;
F_44 ( V_80 , F_42 ( V_80 ) ) ;
}
static int T_6 F_45 ( struct V_81 * V_82 )
{
struct V_60 * V_61 ;
struct V_3 * V_4 ;
int V_9 ;
if ( V_82 -> V_38 . V_83 == NULL )
return - V_45 ;
V_61 = F_46 ( sizeof( * V_4 ) ) ;
if ( V_61 == NULL ) {
V_9 = - V_84 ;
goto V_46;
}
V_4 = F_16 ( V_61 ) ;
V_4 -> V_5 = V_82 -> V_38 . V_83 ;
V_9 = F_40 ( V_4 ) ;
if ( V_9 < 0 )
goto V_85;
F_47 ( V_82 , V_61 ) ;
F_48 ( & V_4 -> V_42 ) ;
V_4 -> V_12 = V_82 ;
V_4 -> V_55 = true ;
V_4 -> V_2 = V_10 ;
V_4 -> V_35 = 12 ;
V_4 -> V_26 = V_86 ;
V_61 -> V_38 . V_87 = & V_82 -> V_38 ;
V_61 -> V_88 = & V_89 ;
V_61 -> V_90 = V_91 ;
V_61 -> V_92 = V_93 ;
V_61 -> V_94 = F_42 ( V_93 ) ;
V_61 -> V_95 = F_49 ( V_82 ) -> V_95 ;
V_9 = F_50 ( V_61 ) ;
if ( V_9 )
goto V_96;
V_4 -> V_27 = V_82 -> V_97 ;
V_82 -> V_2 = V_98 ;
F_51 ( V_82 ) ;
F_39 ( V_4 ) ;
return 0 ;
V_96:
F_43 ( V_4 ) ;
V_85:
F_52 ( V_61 ) ;
V_46:
return V_9 ;
}
static int T_7 F_53 ( struct V_81 * V_82 )
{
struct V_60 * V_61 = F_54 ( V_82 ) ;
F_55 ( V_61 ) ;
F_43 ( F_16 ( V_61 ) ) ;
F_52 ( V_61 ) ;
return 0 ;
}
static T_8 int F_56 ( void )
{
return F_57 ( & V_99 ) ;
}
static T_9 void F_58 ( void )
{
F_59 ( & V_99 ) ;
}
