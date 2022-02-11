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
V_9 [ 0 ] = ( V_10 | F_2 ( V_3 ) ) >> 8 ;
V_9 [ 1 ] = V_4 ;
return F_5 ( V_2 -> V_8 , V_9 , 2 ) ;
}
static T_2 F_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_9 )
{
struct V_1 * V_2 = F_7 ( F_8 ( V_12 ) ) ;
int V_4 , V_6 ;
V_6 = F_1 ( V_2 , V_15 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_4 = ( V_4 & V_16 ) >> 1 ;
return sprintf ( V_9 , L_1 , V_4 ) ;
}
static T_2 F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_9 , T_3 V_17 )
{
struct V_1 * V_2 = F_7 ( F_8 ( V_12 ) ) ;
unsigned long V_4 ;
int V_6 ;
V_6 = F_10 ( ( const char * ) V_9 , 10 , & V_4 ) ;
if ( V_6 )
return - V_18 ;
if ( V_4 > V_19 )
return - V_18 ;
F_4 ( V_2 , V_15 , V_4 << 1 ) ;
return V_17 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_4 ,
int * V_24 ,
long V_25 )
{
struct V_1 * V_2 = F_7 ( V_21 ) ;
int V_6 ;
switch ( V_25 ) {
case V_26 :
case V_27 :
* V_24 = 0 ;
V_6 = F_1 ( V_2 , V_28 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_25 == V_27 )
return V_29 ;
if ( * V_4 == V_30 )
return - V_18 ;
if ( V_25 == V_26 )
* V_4 *= 1000 ;
break;
case V_31 :
* V_4 = 1000 ;
break;
default:
return - V_18 ;
}
return V_29 ;
}
static T_4 F_12 ( int V_32 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_20 * V_21 = V_35 -> V_21 ;
struct V_1 * V_2 = F_7 ( V_21 ) ;
int V_4 , V_6 ;
V_6 = F_1 ( V_2 , V_28 , & V_4 ) ;
if ( V_6 )
goto V_36;
V_2 -> V_37 [ 0 ] = V_4 & V_30 ;
F_13 ( V_21 , & V_2 -> V_37 ,
V_35 -> V_38 ) ;
V_36:
F_14 ( V_21 -> V_39 ) ;
return V_40 ;
}
static void F_15 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_16 ( V_42 , struct V_1 , V_42 . V_42 ) ;
F_1 ( V_2 , V_43 , & V_4 ) ;
V_4 &= V_44 ;
switch ( V_4 ) {
case V_45 :
F_17 ( V_2 -> V_39 ) ;
break;
case V_46 :
F_18 ( & V_2 -> V_8 -> V_12 , L_2 ) ;
break;
}
}
static T_4 F_19 ( int V_32 , void * V_33 )
{
struct V_20 * V_21 = V_33 ;
struct V_1 * V_2 = F_7 ( V_21 ) ;
F_20 ( & V_2 -> V_42 , F_21 ( 3 ) ) ;
return V_40 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_47 ) ;
F_4 ( V_2 , V_43 , F_24 ( 5 ) ) ;
F_4 ( V_2 , V_48 , 0x96 ) ;
F_4 ( V_2 , V_49 ,
F_24 ( 5 ) | ( V_2 -> V_50 / V_51 ) ) ;
F_25 ( 2 ) ;
F_4 ( V_2 , V_49 , ( V_2 -> V_50 / V_51 ) ) ;
F_26 ( & V_2 -> V_47 ) ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = F_28 ( V_12 ) ;
struct V_1 * V_2 = F_7 ( V_21 ) ;
int V_4 , V_6 ;
F_23 ( & V_2 -> V_47 ) ;
V_6 = F_1 ( V_2 , V_15 , & V_4 ) ;
if ( V_6 )
goto V_52;
V_4 |= V_53 ;
V_6 = F_4 ( V_2 , V_15 , V_4 ) ;
V_52:
F_26 ( & V_2 -> V_47 ) ;
return V_6 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = F_28 ( V_12 ) ;
struct V_1 * V_2 = F_7 ( V_21 ) ;
int V_4 , V_6 ;
F_23 ( & V_2 -> V_47 ) ;
V_6 = F_1 ( V_2 , V_15 , & V_4 ) ;
if ( V_6 )
goto V_54;
V_4 &= ~ V_53 ;
V_6 = F_4 ( V_2 , V_15 , V_4 ) ;
V_54:
F_26 ( & V_2 -> V_47 ) ;
return V_6 ;
}
static int F_30 ( struct V_55 * V_8 )
{
struct V_20 * V_21 ;
struct V_56 * V_39 ;
struct V_1 * V_2 ;
struct V_57 * V_58 = V_8 -> V_12 . V_59 ;
int V_6 ;
if ( ! V_8 -> V_32 ) {
F_31 ( & V_8 -> V_12 , L_3 ) ;
return - V_18 ;
}
V_21 = F_32 ( & V_8 -> V_12 , sizeof( * V_2 ) ) ;
if ( ! V_21 )
return - V_60 ;
V_2 = F_7 ( V_21 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_50 = 0 ;
F_33 ( V_8 , V_21 ) ;
F_34 ( & V_2 -> V_47 ) ;
F_35 ( & V_2 -> V_42 , F_15 ) ;
V_6 = F_36 ( V_58 ,
L_4 , & V_2 -> V_50 ) ;
if ( V_6 ) {
V_2 -> V_50 = 0 ;
F_18 ( & V_8 -> V_12 ,
L_5 ,
V_2 -> V_50 ) ;
}
if ( V_2 -> V_50 > V_61 ) {
F_31 ( & V_8 -> V_12 ,
L_6 ,
V_2 -> V_50 ) ;
return - V_18 ;
}
V_21 -> V_12 . V_62 = & V_8 -> V_12 ;
V_21 -> V_63 = F_37 ( V_8 ) -> V_63 ;
V_21 -> V_64 = V_65 ;
V_21 -> V_66 = F_38 ( V_65 ) ;
V_21 -> V_67 = V_68 ;
V_21 -> V_69 = & V_70 ;
V_39 = F_39 ( & V_8 -> V_12 , L_7 ,
V_21 -> V_63 , V_21 -> V_71 ) ;
if ( ! V_39 )
return - V_60 ;
V_2 -> V_39 = V_39 ;
V_39 -> V_12 . V_62 = V_21 -> V_12 . V_62 ;
F_40 ( V_39 , V_21 ) ;
V_39 -> V_72 = & V_73 ;
V_6 = F_41 ( V_39 ) ;
if ( V_6 ) {
F_31 ( & V_8 -> V_12 , L_8 ) ;
return V_6 ;
}
V_6 = F_42 ( V_21 , NULL ,
& F_12 , NULL ) ;
if ( V_6 ) {
F_31 ( & V_8 -> V_12 , L_9 ) ;
goto V_74;
}
F_22 ( V_2 ) ;
V_6 = F_43 ( & V_8 -> V_12 , V_8 -> V_32 ,
& F_19 ,
V_75 ,
F_44 ( & V_8 -> V_12 ) ,
V_21 ) ;
if ( V_6 ) {
F_31 ( & V_8 -> V_12 , L_10 ) ;
goto V_76;
}
V_6 = F_45 ( V_21 ) ;
if ( V_6 < 0 ) {
F_31 ( & V_8 -> V_12 , L_11 ) ;
goto V_76;
}
return 0 ;
V_76:
F_46 ( V_21 ) ;
V_74:
F_47 ( V_2 -> V_39 ) ;
return V_6 ;
}
static int F_48 ( struct V_55 * V_8 )
{
struct V_20 * V_21 = F_49 ( V_8 ) ;
struct V_1 * V_2 = F_7 ( V_21 ) ;
F_50 ( V_21 ) ;
F_46 ( V_21 ) ;
F_47 ( V_2 -> V_39 ) ;
return 0 ;
}
