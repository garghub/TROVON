static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = 0 ;
int V_5 , V_6 ;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
return V_4 ;
if ( V_6 & V_9 )
F_4 ( V_2 ,
L_1
L_2 ) ;
V_6 &= ~ ( V_9 | V_10 | V_11 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_6 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_5 &= ~ ( V_13 | V_14 ) ;
V_5 |= V_15 ;
return F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * time )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
T_1 V_17 [ 7 ] ;
unsigned int V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 = 0 ;
V_4 = F_7 ( V_3 -> V_7 , V_29 , V_17 , 7 ) ;
if ( V_4 )
return V_4 ;
V_23 = V_17 [ 0 ] ;
V_22 = V_17 [ 1 ] ;
V_21 = V_17 [ 2 ] ;
V_24 = V_17 [ 3 ] ;
V_20 = V_17 [ 4 ] ;
V_19 = V_17 [ 5 ] ;
V_18 = V_17 [ 6 ] ;
V_25 = V_21 & 0x40 ;
V_26 = V_21 & 0x20 ;
V_27 = V_19 & 0x80 ;
time -> V_30 = F_8 ( V_23 ) ;
time -> V_31 = F_8 ( V_22 ) ;
if ( V_25 ) {
if ( V_26 )
time -> V_32 = F_8 ( V_21 & 0x1F ) + 12 ;
else
time -> V_32 = F_8 ( V_21 & 0x1F ) ;
} else {
time -> V_32 = F_8 ( V_21 ) ;
}
time -> V_33 = F_8 ( V_24 ) - 1 ;
time -> V_34 = F_8 ( V_20 ) ;
time -> V_35 = F_8 ( V_19 & 0x7F ) - 1 ;
if ( V_27 )
V_28 = 100 ;
time -> V_36 = F_8 ( V_18 ) + V_28 ;
return F_9 ( time ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_16 * time )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_17 [ 7 ] ;
V_17 [ 0 ] = F_11 ( time -> V_30 ) ;
V_17 [ 1 ] = F_11 ( time -> V_31 ) ;
V_17 [ 2 ] = F_11 ( time -> V_32 ) ;
V_17 [ 3 ] = F_11 ( time -> V_33 + 1 ) ;
V_17 [ 4 ] = F_11 ( time -> V_34 ) ;
V_17 [ 5 ] = F_11 ( time -> V_35 + 1 ) ;
if ( time -> V_36 >= 100 ) {
V_17 [ 5 ] |= 0x80 ;
V_17 [ 6 ] = F_11 ( time -> V_36 - 100 ) ;
} else {
V_17 [ 6 ] = F_11 ( time -> V_36 ) ;
}
return F_12 ( V_3 -> V_7 , V_29 , V_17 , 7 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
int V_4 ;
T_1 V_17 [ 4 ] ;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
goto V_39;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
goto V_39;
V_4 = F_7 ( V_3 -> V_7 , V_40 , V_17 , 4 ) ;
if ( V_4 )
goto V_39;
V_38 -> time . V_30 = F_8 ( V_17 [ 0 ] & 0x7F ) ;
V_38 -> time . V_31 = F_8 ( V_17 [ 1 ] & 0x7F ) ;
V_38 -> time . V_32 = F_8 ( V_17 [ 2 ] & 0x7F ) ;
V_38 -> time . V_34 = F_8 ( V_17 [ 3 ] & 0x7F ) ;
V_38 -> V_41 = ! ! ( V_5 & V_13 ) ;
V_38 -> V_42 = ! ! ( V_6 & V_10 ) ;
V_4 = 0 ;
V_39:
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
int V_4 ;
T_1 V_17 [ 4 ] ;
if ( V_3 -> V_43 <= 0 )
return - V_44 ;
V_17 [ 0 ] = F_11 ( V_38 -> time . V_30 ) ;
V_17 [ 1 ] = F_11 ( V_38 -> time . V_31 ) ;
V_17 [ 2 ] = F_11 ( V_38 -> time . V_32 ) ;
V_17 [ 3 ] = F_11 ( V_38 -> time . V_34 ) ;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
goto V_39;
V_5 &= ~ ( V_13 | V_14 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
if ( V_4 )
goto V_39;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
goto V_39;
V_6 &= ~ ( V_10 | V_11 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_6 ) ;
if ( V_4 )
goto V_39;
V_4 = F_12 ( V_3 -> V_7 , V_40 , V_17 , 4 ) ;
if ( V_4 )
goto V_39;
if ( V_38 -> V_41 ) {
V_5 |= V_13 ;
V_4 = F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
}
V_39:
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_5 ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
return V_4 ;
if ( V_41 )
V_5 |= V_13 ;
else
V_5 &= ~ ( V_13 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 , long int * V_45 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_46 [ 2 ] ;
T_2 V_47 ;
int V_4 ;
V_4 = F_7 ( V_3 -> V_7 , V_48 , V_46 ,
sizeof( V_46 ) ) ;
if ( V_4 < 0 )
return V_4 ;
V_47 = ( V_46 [ 0 ] << 8 ) | V_46 [ 1 ] ;
V_47 >>= 6 ;
* V_45 = V_47 * 250 ;
return 0 ;
}
static T_3 F_17 ( const void * V_49 ,
enum V_50 type ,
T_4 V_51 , int V_52 )
{
if ( type != V_53 )
return 0 ;
switch ( V_51 ) {
case V_54 :
return 0444 ;
default:
return 0 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
enum V_50 type ,
T_4 V_51 , int V_52 , long * V_47 )
{
int V_55 ;
switch ( V_51 ) {
case V_54 :
V_55 = F_16 ( V_2 , V_47 ) ;
break;
default:
V_55 = - V_56 ;
break;
}
return V_55 ;
}
static void F_19 ( struct V_1 * V_2 , const char * V_57 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_58 ;
if ( ! F_20 ( V_59 ) )
return;
V_58 = F_21 ( V_2 , V_57 , V_3 ,
& V_60 ,
NULL ) ;
if ( F_22 ( V_58 ) ) {
F_23 ( V_2 , L_3 ,
F_24 ( V_58 ) ) ;
}
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_43 <= 0 )
return - V_44 ;
return F_15 ( V_2 , V_41 ) ;
}
static T_5 F_26 ( int V_43 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_62 * V_63 = & V_3 -> V_64 -> V_65 ;
int V_4 ;
int V_6 , V_5 ;
F_27 ( V_63 ) ;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
goto V_66;
if ( V_6 & V_10 ) {
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_2 ,
L_4 , V_4 ) ;
} else {
V_5 &= ~ ( V_13 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_12 ,
V_5 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_2 ,
L_5 ,
V_4 ) ;
goto V_66;
}
V_6 &= ~ V_10 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_6 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_2 ,
L_6 ,
V_4 ) ;
goto V_66;
}
F_28 ( V_3 -> V_64 , 1 , V_67 | V_68 ) ;
}
}
V_66:
F_29 ( V_63 ) ;
return V_69 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_7 * V_7 , int V_43 ,
const char * V_57 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_31 ( V_2 , sizeof( * V_3 ) , V_70 ) ;
if ( ! V_3 )
return - V_71 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_43 = V_43 ;
V_3 -> V_2 = V_2 ;
F_32 ( V_2 , V_3 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 -> V_43 > 0 )
F_33 ( V_2 , 1 ) ;
F_19 ( V_2 , V_57 ) ;
V_3 -> V_64 = F_34 ( V_2 , V_57 , & V_72 ,
V_73 ) ;
if ( F_22 ( V_3 -> V_64 ) )
return F_24 ( V_3 -> V_64 ) ;
if ( V_3 -> V_43 > 0 ) {
V_4 = F_35 ( V_2 , V_3 -> V_43 , NULL ,
F_26 ,
V_74 | V_75 ,
V_57 , V_2 ) ;
if ( V_4 ) {
F_36 ( V_2 , 0 ) ;
V_3 -> V_43 = 0 ;
F_23 ( V_2 , L_7 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( F_38 ( V_2 ) ) {
if ( F_39 ( V_3 -> V_43 ) )
F_40 ( V_2 , L_8 ) ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( F_38 ( V_2 ) )
F_42 ( V_3 -> V_43 ) ;
return 0 ;
}
static int F_43 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_7 * V_7 ;
static const struct V_80 V_81 = {
. V_82 = 8 ,
. V_83 = 8 ,
. V_84 = 0x13 ,
} ;
V_7 = F_44 ( V_77 , & V_81 ) ;
if ( F_22 ( V_7 ) ) {
F_23 ( & V_77 -> V_2 , L_9 ,
V_85 , F_24 ( V_7 ) ) ;
return F_24 ( V_7 ) ;
}
return F_30 ( & V_77 -> V_2 , V_7 , V_77 -> V_43 , V_77 -> V_57 ) ;
}
static int F_45 ( void )
{
return F_46 ( & V_86 ) ;
}
static void F_47 ( void )
{
F_48 ( & V_86 ) ;
}
static int F_45 ( void )
{
return 0 ;
}
static void F_47 ( void )
{
}
static int F_49 ( struct V_87 * V_88 )
{
int V_89 ;
unsigned int V_90 ;
static const struct V_80 V_81 = {
. V_82 = 8 ,
. V_83 = 8 ,
. V_84 = 0x13 ,
. V_91 = 0x80 ,
} ;
struct V_7 * V_7 ;
V_7 = F_50 ( V_88 , & V_81 ) ;
if ( F_22 ( V_7 ) ) {
F_23 ( & V_88 -> V_2 , L_9 ,
V_85 , F_24 ( V_7 ) ) ;
return F_24 ( V_7 ) ;
}
V_88 -> V_92 = V_93 ;
V_88 -> V_94 = 8 ;
F_51 ( V_88 ) ;
V_89 = F_3 ( V_7 , V_29 , & V_90 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_3 ( V_7 , V_12 , & V_90 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_5 ( V_7 , V_12 , V_90 & 0x1c ) ;
if ( V_89 )
return V_89 ;
V_89 = F_3 ( V_7 , V_8 , & V_90 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_5 ( V_7 , V_8 , V_90 & 0x88 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_3 ( V_7 , V_12 , & V_90 ) ;
if ( V_89 )
return V_89 ;
F_52 ( & V_88 -> V_2 , L_10 , V_90 ) ;
V_89 = F_3 ( V_7 , V_8 , & V_90 ) ;
if ( V_89 )
return V_89 ;
F_52 ( & V_88 -> V_2 , L_11 , V_90 ) ;
return F_30 ( & V_88 -> V_2 , V_7 , V_88 -> V_43 , L_12 ) ;
}
static int F_53 ( void )
{
return F_54 ( & V_95 ) ;
}
static void F_55 ( void )
{
F_56 ( & V_95 ) ;
}
static int F_53 ( void )
{
return 0 ;
}
static void F_55 ( void )
{
}
static int T_6 F_57 ( void )
{
int V_4 ;
V_4 = F_45 () ;
if ( V_4 ) {
F_58 ( L_13 , V_4 ) ;
return V_4 ;
}
V_4 = F_53 () ;
if ( V_4 ) {
F_58 ( L_14 , V_4 ) ;
F_47 () ;
}
return V_4 ;
}
static void T_7 F_59 ( void )
{
F_55 () ;
F_47 () ;
}
