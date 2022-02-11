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
static T_2 F_11 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_9 )
{
struct V_1 * V_2 = F_7 ( F_8 ( V_11 ) ) ;
int V_6 ;
F_12 ( & V_2 -> V_19 ) ;
V_6 = sprintf ( V_9 , L_1 , ! F_13 ( V_20 , V_2 -> V_21 + V_22 ) ) ;
F_14 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static int F_15 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_4 ,
int * V_27 ,
long V_28 )
{
struct V_1 * V_2 = F_7 ( V_24 ) ;
int V_6 ;
switch ( V_28 ) {
case V_29 :
case V_30 :
* V_27 = 0 ;
V_6 = F_1 ( V_2 , V_31 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( * V_4 == V_32 )
return - V_17 ;
if ( V_28 == V_30 )
return V_33 ;
if ( V_28 == V_29 )
* V_4 *= 1000 ;
break;
case V_34 :
* V_4 = 1000 ;
break;
default:
return - V_17 ;
}
return V_33 ;
}
static T_4 F_16 ( int V_35 , void * V_36 )
{
struct V_37 * V_38 = V_36 ;
struct V_23 * V_24 = V_38 -> V_24 ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
int V_4 , V_6 ;
V_6 = F_1 ( V_2 , V_31 , & V_4 ) ;
if ( V_6 )
goto V_39;
V_2 -> V_40 [ 0 ] = V_4 & V_32 ;
F_17 ( V_24 , & V_2 -> V_40 ,
F_18 ( V_24 ) ) ;
V_39:
F_19 ( V_24 -> V_41 ) ;
return V_42 ;
}
static void F_20 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
int V_4 ;
int V_6 ;
V_2 = F_21 ( V_44 , struct V_1 , V_44 . V_44 ) ;
V_6 = F_1 ( V_2 , V_45 , & V_4 ) ;
if ( V_6 ) {
F_22 ( & V_2 -> V_8 -> V_11 , L_2 ) ;
return;
}
V_4 &= V_46 ;
switch ( V_4 ) {
case V_47 :
F_23 ( V_2 -> V_41 ) ;
break;
case V_48 :
case V_49 :
F_12 ( & V_2 -> V_19 ) ;
V_2 -> V_21 = V_20 ;
F_14 ( & V_2 -> V_19 ) ;
F_22 ( & V_2 -> V_8 -> V_11 , L_3 ) ;
break;
}
}
static T_4 F_24 ( int V_35 , void * V_36 )
{
struct V_23 * V_24 = V_36 ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
F_25 ( & V_2 -> V_44 , F_26 ( 3 ) ) ;
return V_42 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_50 , 0x96 ) ;
F_4 ( V_2 , V_51 , 0x96 ) ;
F_4 ( V_2 , V_52 ,
F_28 ( 5 ) | ( V_2 -> V_53 / V_54 ) ) ;
F_29 ( 2 ) ;
F_4 ( V_2 , V_52 , ( V_2 -> V_53 / V_54 ) ) ;
F_4 ( V_2 , V_55 , V_2 -> V_56 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = F_31 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
int V_4 , V_6 ;
F_12 ( & V_2 -> V_19 ) ;
V_6 = F_1 ( V_2 , V_14 , & V_4 ) ;
if ( V_6 )
goto V_57;
V_4 |= V_58 ;
V_6 = F_4 ( V_2 , V_14 , V_4 ) ;
V_57:
F_14 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = F_31 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
int V_4 , V_6 ;
F_12 ( & V_2 -> V_19 ) ;
V_6 = F_1 ( V_2 , V_14 , & V_4 ) ;
if ( V_6 )
goto V_59;
V_4 &= ~ V_58 ;
V_6 = F_4 ( V_2 , V_14 , V_4 ) ;
F_27 ( V_2 ) ;
V_59:
F_14 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static int F_33 ( struct V_60 * V_8 )
{
struct V_23 * V_24 ;
struct V_61 * V_41 ;
struct V_1 * V_2 ;
struct V_62 * V_63 = V_8 -> V_11 . V_64 ;
int V_6 ;
if ( ! V_8 -> V_35 ) {
F_34 ( & V_8 -> V_11 , L_4 ) ;
return - V_17 ;
}
V_24 = F_35 ( & V_8 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_65 ;
V_2 = F_7 ( V_24 ) ;
V_2 -> V_8 = V_8 ;
F_36 ( V_8 , V_24 ) ;
F_37 ( & V_2 -> V_19 ) ;
F_38 ( & V_2 -> V_44 , F_20 ) ;
V_6 = F_39 ( V_63 ,
L_5 , & V_2 -> V_53 ) ;
if ( V_6 ) {
V_2 -> V_53 = 0 ;
F_22 ( & V_8 -> V_11 ,
L_6 ,
V_2 -> V_53 ) ;
}
if ( V_2 -> V_53 > V_66 ) {
F_34 ( & V_8 -> V_11 ,
L_7 ,
V_2 -> V_53 ) ;
return - V_17 ;
}
V_6 = F_39 ( V_63 ,
L_8 , & V_2 -> V_56 ) ;
if ( ! V_6 && V_2 -> V_56 > V_67 ) {
F_34 ( & V_8 -> V_11 ,
L_9 ,
V_2 -> V_56 ) ;
return - V_17 ;
}
V_24 -> V_11 . V_68 = & V_8 -> V_11 ;
V_24 -> V_69 = F_40 ( V_8 ) -> V_69 ;
V_24 -> V_70 = V_71 ;
V_24 -> V_72 = F_41 ( V_71 ) ;
V_24 -> V_73 = V_74 ;
V_24 -> V_75 = & V_76 ;
V_41 = F_42 ( & V_8 -> V_11 , L_10 ,
V_24 -> V_69 , V_24 -> V_77 ) ;
if ( ! V_41 )
return - V_65 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_21 = V_20 - V_22 ;
V_41 -> V_11 . V_68 = V_24 -> V_11 . V_68 ;
F_43 ( V_41 , V_24 ) ;
V_41 -> V_78 = & V_79 ;
V_6 = F_44 ( V_41 ) ;
if ( V_6 ) {
F_34 ( & V_8 -> V_11 , L_11 ) ;
return V_6 ;
}
V_6 = F_45 ( V_24 , V_80 ,
& F_16 , NULL ) ;
if ( V_6 ) {
F_34 ( & V_8 -> V_11 , L_12 ) ;
goto V_81;
}
F_27 ( V_2 ) ;
V_6 = F_46 ( & V_8 -> V_11 , V_8 -> V_35 ,
& F_24 ,
V_82 ,
F_47 ( & V_8 -> V_11 ) ,
V_24 ) ;
if ( V_6 ) {
F_34 ( & V_8 -> V_11 , L_13 ) ;
goto V_83;
}
V_6 = F_48 ( V_24 ) ;
if ( V_6 < 0 ) {
F_34 ( & V_8 -> V_11 , L_14 ) ;
goto V_83;
}
return 0 ;
V_83:
F_49 ( V_24 ) ;
V_81:
F_50 ( V_2 -> V_41 ) ;
return V_6 ;
}
static int F_51 ( struct V_60 * V_8 )
{
struct V_23 * V_24 = F_52 ( V_8 ) ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
F_53 ( V_24 ) ;
F_49 ( V_24 ) ;
F_50 ( V_2 -> V_41 ) ;
return 0 ;
}
