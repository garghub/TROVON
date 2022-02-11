static int F_1 ( void )
{
T_1 V_1 , V_2 ;
T_1 V_3 ;
int V_4 ;
V_4 = F_2 ( V_5 , & V_1 , & V_2 ) ;
if ( V_4 )
return V_4 ;
V_3 = ( V_1 >> 16 ) & 0xff ;
if ( V_3 )
return V_3 ;
return - V_6 ;
}
static int F_3 ( int * V_7 )
{
int V_8 ;
T_1 V_1 , V_2 ;
int V_4 ;
unsigned long V_9 = 0 ;
* V_7 = 0 ;
F_4 (cpu) {
V_4 = F_5 ( V_8 , V_10 , & V_1 ,
& V_2 ) ;
if ( V_4 )
goto V_11;
else {
if ( V_1 & 0x80000000 ) {
V_9 = ( V_1 >> 16 ) & 0x7f ;
if ( ! * V_7 || V_9 < * V_7 )
* V_7 = V_9 ;
} else {
V_4 = - V_6 ;
goto V_11;
}
}
}
return 0 ;
V_11:
return V_4 ;
}
static int F_6 ( struct V_12 * V_13 ,
int * V_7 )
{
int V_14 ;
V_14 = F_3 ( V_7 ) ;
if ( ! V_14 )
* V_7 = ( V_15 - * V_7 ) * 1000 ;
return V_14 ;
}
static int F_7 ( struct V_16 * V_17 )
{
int V_18 ;
T_2 V_19 ;
struct V_20 V_21 = { V_22 , NULL } ;
union V_23 * V_24 , * V_25 ;
union V_23 * V_26 ;
int V_14 = 0 ;
V_19 = F_8 ( V_17 -> V_27 -> V_28 , L_1 ,
NULL , & V_21 ) ;
if ( F_9 ( V_19 ) )
return - V_29 ;
V_26 = V_21 . V_30 ;
if ( ! V_26 || ( V_26 -> type != V_31 ) ) {
F_10 ( V_17 -> V_32 , L_2 ) ;
V_14 = - V_33 ;
goto V_34;
}
if ( ! V_26 -> V_35 . V_36 ) {
F_10 ( V_17 -> V_32 , L_3 ) ;
V_14 = - V_33 ;
goto V_34;
}
for ( V_18 = 0 ; V_18 < F_11 ( ( int ) V_26 -> V_35 . V_36 - 1 , 2 ) ; ++ V_18 ) {
V_24 = & ( V_26 -> V_35 . V_24 [ V_18 + 1 ] ) ;
if ( V_24 -> type != V_31 ||
V_24 -> V_35 . V_36 != 6 ) {
V_14 = - V_33 ;
goto V_34;
}
V_25 = V_24 -> V_35 . V_24 ;
V_17 -> V_37 [ V_18 ] . V_38 = V_25 [ 0 ] . integer . V_39 ;
V_17 -> V_37 [ V_18 ] . V_40 = V_25 [ 1 ] . integer . V_39 ;
V_17 -> V_37 [ V_18 ] . V_41 = V_25 [ 2 ] . integer . V_39 ;
V_17 -> V_37 [ V_18 ] . V_42 = V_25 [ 3 ] . integer . V_39 ;
V_17 -> V_37 [ V_18 ] . V_43 = V_25 [ 4 ] . integer . V_39 ;
V_17 -> V_37 [ V_18 ] . V_44 = V_25 [ 5 ] . integer . V_39 ;
}
V_34:
F_12 ( V_21 . V_30 ) ;
return V_14 ;
}
static void F_13 ( T_3 V_28 , T_1 V_45 , void * V_46 )
{
struct V_16 * V_17 = V_46 ;
if ( ! V_17 )
return;
switch ( V_45 ) {
case V_47 :
F_7 ( V_17 ) ;
F_14 ( V_17 -> V_48 ,
V_49 ) ;
break;
default:
F_10 ( V_17 -> V_32 , L_4 , V_45 ) ;
break;
}
}
static int F_15 ( struct V_50 * V_32 ,
struct V_16 * * V_51 )
{
struct V_16 * V_17 ;
struct V_52 * V_27 ;
T_2 V_19 ;
unsigned long long V_53 ;
struct V_54 * V_55 = NULL ;
int V_14 ;
V_27 = F_16 ( V_32 ) ;
if ( ! V_27 )
return - V_29 ;
V_17 = F_17 ( V_32 , sizeof( * V_17 ) , V_56 ) ;
if ( ! V_17 )
return - V_57 ;
V_17 -> V_32 = V_32 ;
V_17 -> V_27 = V_27 ;
* V_51 = V_17 ;
V_14 = F_7 ( V_17 ) ;
if ( ! V_14 ) {
V_14 = F_18 ( & V_32 -> V_58 ,
& V_59 ) ;
}
if ( V_14 )
return V_14 ;
V_19 = F_19 ( V_27 -> V_28 , L_5 , NULL , & V_53 ) ;
if ( F_9 ( V_19 ) ) {
V_15 = F_1 () ;
if ( V_15 > 0 )
V_55 = & V_60 ;
}
V_17 -> V_48 = F_20 ( V_27 , V_55 ) ;
if ( F_21 ( V_17 -> V_48 ) ) {
V_14 = F_22 ( V_17 -> V_48 ) ;
goto V_61;
} else
V_14 = 0 ;
V_14 = F_23 ( V_27 -> V_28 , V_62 ,
F_13 ,
( void * ) V_17 ) ;
if ( V_14 )
goto V_63;
return 0 ;
V_63:
F_24 ( V_17 -> V_48 ) ;
V_61:
F_25 ( & V_17 -> V_32 -> V_58 ,
& V_59 ) ;
return V_14 ;
}
static void F_26 ( struct V_16 * V_17 )
{
F_27 ( V_17 -> V_27 -> V_28 ,
V_62 , F_13 ) ;
F_24 ( V_17 -> V_48 ) ;
F_25 ( & V_17 -> V_32 -> V_58 ,
& V_59 ) ;
}
static int F_28 ( struct V_64 * V_65 )
{
struct V_16 * V_17 ;
int V_14 ;
if ( V_66 == V_67 ) {
F_10 ( & V_65 -> V_32 , L_6 ) ;
return - V_29 ;
}
V_14 = F_15 ( & V_65 -> V_32 , & V_17 ) ;
if ( V_14 )
return V_14 ;
F_29 ( V_65 , V_17 ) ;
V_66 = V_68 ;
return 0 ;
}
static int F_30 ( struct V_64 * V_65 )
{
F_26 ( F_31 ( V_65 ) ) ;
return 0 ;
}
static T_4 F_32 ( int V_69 , void * V_70 )
{
struct V_16 * V_17 ;
struct V_71 * V_65 = V_70 ;
V_17 = F_33 ( V_65 ) ;
F_34 ( V_17 -> V_72 ) ;
return V_73 ;
}
static int F_35 ( struct V_71 * V_65 ,
const struct V_74 * V_75 )
{
struct V_16 * V_17 ;
int V_14 ;
if ( V_66 == V_68 ) {
F_10 ( & V_65 -> V_32 , L_7 ) ;
return - V_29 ;
}
V_14 = F_36 ( V_65 ) ;
if ( V_14 < 0 ) {
F_10 ( & V_65 -> V_32 , L_8 ) ;
return V_14 ;
}
V_14 = F_15 ( & V_65 -> V_32 , & V_17 ) ;
if ( V_14 ) {
F_37 ( V_65 ) ;
return V_14 ;
}
F_38 ( V_65 , V_17 ) ;
V_66 = V_67 ;
if ( V_65 -> V_50 == V_76 ) {
V_17 -> V_72 = F_39 (
V_77 , 2 , 0 ) ;
if ( V_17 -> V_72 && V_65 -> V_69 ) {
V_14 = F_40 ( V_65 ) ;
if ( ! V_14 ) {
V_14 = F_41 ( V_65 -> V_69 , NULL ,
F_32 ,
V_78 , L_9 ,
V_65 ) ;
if ( V_14 ) {
F_42 (
V_17 -> V_72 ) ;
F_43 ( V_65 ) ;
V_17 -> V_72 = NULL ;
}
}
} else
F_10 ( & V_65 -> V_32 , L_10 ) ;
}
return 0 ;
}
static void F_44 ( struct V_71 * V_65 )
{
struct V_16 * V_17 = F_33 ( V_65 ) ;
if ( V_17 -> V_72 ) {
F_42 ( V_17 -> V_72 ) ;
if ( V_65 -> V_69 ) {
F_45 ( V_65 -> V_69 , V_65 ) ;
F_43 ( V_65 ) ;
}
}
F_26 ( V_17 ) ;
F_37 ( V_65 ) ;
}
static int T_5 F_46 ( void )
{
int V_14 ;
V_14 = F_47 ( & V_79 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_48 ( & V_80 ) ;
return V_14 ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_79 ) ;
F_51 ( & V_80 ) ;
}
