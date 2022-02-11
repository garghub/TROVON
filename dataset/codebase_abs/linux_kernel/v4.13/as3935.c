static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_5 = ( V_7 | F_2 ( V_3 ) ) >> 8 ;
V_6 = F_3 ( V_2 -> V_8 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_4 = V_6 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
T_1 * V_9 = V_2 -> V_9 ;
V_9 [ 0 ] = F_2 ( V_3 ) >> 8 ;
V_9 [ 1 ] = V_4 ;
return F_5 ( V_2 -> V_8 , V_9 , 2 ) ;
}
static T_2 F_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_9 )
{
struct V_1 * V_2 = F_7 ( F_8 ( V_11 ) ) ;
int V_4 , V_6 ;
V_6 = F_1 ( V_2 , V_14 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_4 = ( V_4 & V_15 ) >> 1 ;
return sprintf ( V_9 , L_1 , V_4 ) ;
}
static T_2 F_9 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char * V_9 , T_3 V_16 )
{
struct V_1 * V_2 = F_7 ( F_8 ( V_11 ) ) ;
unsigned long V_4 ;
int V_6 ;
V_6 = F_10 ( ( const char * ) V_9 , 10 , & V_4 ) ;
if ( V_6 )
return - V_17 ;
if ( V_4 > V_18 )
return - V_17 ;
F_4 ( V_2 , V_14 , V_4 << 1 ) ;
return V_16 ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_21 const * V_22 ,
int * V_4 ,
int * V_23 ,
long V_24 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
int V_6 ;
switch ( V_24 ) {
case V_25 :
case V_26 :
* V_23 = 0 ;
V_6 = F_1 ( V_2 , V_27 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( * V_4 == V_28 )
return - V_17 ;
if ( V_24 == V_26 )
return V_29 ;
if ( V_24 == V_25 )
* V_4 *= 1000 ;
break;
case V_30 :
* V_4 = 1000 ;
break;
default:
return - V_17 ;
}
return V_29 ;
}
static T_4 F_12 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_19 * V_20 = V_34 -> V_20 ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
int V_4 , V_6 ;
V_6 = F_1 ( V_2 , V_27 , & V_4 ) ;
if ( V_6 )
goto V_35;
V_2 -> V_36 [ 0 ] = V_4 & V_28 ;
F_13 ( V_20 , & V_2 -> V_36 ,
F_14 ( V_20 ) ) ;
V_35:
F_15 ( V_20 -> V_37 ) ;
return V_38 ;
}
static void F_16 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int V_4 ;
int V_6 ;
V_2 = F_17 ( V_40 , struct V_1 , V_40 . V_40 ) ;
V_6 = F_1 ( V_2 , V_41 , & V_4 ) ;
if ( V_6 ) {
F_18 ( & V_2 -> V_8 -> V_11 , L_2 ) ;
return;
}
V_4 &= V_42 ;
switch ( V_4 ) {
case V_43 :
F_19 ( V_2 -> V_37 ) ;
break;
case V_44 :
F_18 ( & V_2 -> V_8 -> V_11 , L_3 ) ;
break;
}
}
static T_4 F_20 ( int V_31 , void * V_32 )
{
struct V_19 * V_20 = V_32 ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
F_21 ( & V_2 -> V_40 , F_22 ( 3 ) ) ;
return V_38 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_41 , F_24 ( 5 ) ) ;
F_4 ( V_2 , V_45 , 0x96 ) ;
F_4 ( V_2 , V_46 ,
F_24 ( 5 ) | ( V_2 -> V_47 / V_48 ) ) ;
F_25 ( 2 ) ;
F_4 ( V_2 , V_46 , ( V_2 -> V_47 / V_48 ) ) ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = F_27 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
int V_4 , V_6 ;
F_28 ( & V_2 -> V_49 ) ;
V_6 = F_1 ( V_2 , V_14 , & V_4 ) ;
if ( V_6 )
goto V_50;
V_4 |= V_51 ;
V_6 = F_4 ( V_2 , V_14 , V_4 ) ;
V_50:
F_29 ( & V_2 -> V_49 ) ;
return V_6 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = F_27 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
int V_4 , V_6 ;
F_28 ( & V_2 -> V_49 ) ;
V_6 = F_1 ( V_2 , V_14 , & V_4 ) ;
if ( V_6 )
goto V_52;
V_4 &= ~ V_51 ;
V_6 = F_4 ( V_2 , V_14 , V_4 ) ;
F_23 ( V_2 ) ;
V_52:
F_29 ( & V_2 -> V_49 ) ;
return V_6 ;
}
static int F_31 ( struct V_53 * V_8 )
{
struct V_19 * V_20 ;
struct V_54 * V_37 ;
struct V_1 * V_2 ;
struct V_55 * V_56 = V_8 -> V_11 . V_57 ;
int V_6 ;
if ( ! V_8 -> V_31 ) {
F_32 ( & V_8 -> V_11 , L_4 ) ;
return - V_17 ;
}
V_20 = F_33 ( & V_8 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_20 )
return - V_58 ;
V_2 = F_7 ( V_20 ) ;
V_2 -> V_8 = V_8 ;
F_34 ( V_8 , V_20 ) ;
F_35 ( & V_2 -> V_49 ) ;
F_36 ( & V_2 -> V_40 , F_16 ) ;
V_6 = F_37 ( V_56 ,
L_5 , & V_2 -> V_47 ) ;
if ( V_6 ) {
V_2 -> V_47 = 0 ;
F_18 ( & V_8 -> V_11 ,
L_6 ,
V_2 -> V_47 ) ;
}
if ( V_2 -> V_47 > V_59 ) {
F_32 ( & V_8 -> V_11 ,
L_7 ,
V_2 -> V_47 ) ;
return - V_17 ;
}
V_20 -> V_11 . V_60 = & V_8 -> V_11 ;
V_20 -> V_61 = F_38 ( V_8 ) -> V_61 ;
V_20 -> V_62 = V_63 ;
V_20 -> V_64 = F_39 ( V_63 ) ;
V_20 -> V_65 = V_66 ;
V_20 -> V_67 = & V_68 ;
V_37 = F_40 ( & V_8 -> V_11 , L_8 ,
V_20 -> V_61 , V_20 -> V_69 ) ;
if ( ! V_37 )
return - V_58 ;
V_2 -> V_37 = V_37 ;
V_37 -> V_11 . V_60 = V_20 -> V_11 . V_60 ;
F_41 ( V_37 , V_20 ) ;
V_37 -> V_70 = & V_71 ;
V_6 = F_42 ( V_37 ) ;
if ( V_6 ) {
F_32 ( & V_8 -> V_11 , L_9 ) ;
return V_6 ;
}
V_6 = F_43 ( V_20 , V_72 ,
& F_12 , NULL ) ;
if ( V_6 ) {
F_32 ( & V_8 -> V_11 , L_10 ) ;
goto V_73;
}
F_23 ( V_2 ) ;
V_6 = F_44 ( & V_8 -> V_11 , V_8 -> V_31 ,
& F_20 ,
V_74 ,
F_45 ( & V_8 -> V_11 ) ,
V_20 ) ;
if ( V_6 ) {
F_32 ( & V_8 -> V_11 , L_11 ) ;
goto V_75;
}
V_6 = F_46 ( V_20 ) ;
if ( V_6 < 0 ) {
F_32 ( & V_8 -> V_11 , L_12 ) ;
goto V_75;
}
return 0 ;
V_75:
F_47 ( V_20 ) ;
V_73:
F_48 ( V_2 -> V_37 ) ;
return V_6 ;
}
static int F_49 ( struct V_53 * V_8 )
{
struct V_19 * V_20 = F_50 ( V_8 ) ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
F_51 ( V_20 ) ;
F_47 ( V_20 ) ;
F_48 ( V_2 -> V_37 ) ;
return 0 ;
}
