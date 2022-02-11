void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ,
V_4 , V_5 , 1 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 ) ;
}
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_5 ( V_2 -> V_3 + V_8 ) ;
V_7 |= V_9 ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
V_7 |= F_7 ( V_10 ) ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
if ( F_2 ( V_2 -> V_3 ,
V_8 , V_10 , 0 ) ) {
F_3 ( V_2 -> V_6 ,
L_2 ) ;
}
F_1 ( V_2 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_6 ( V_11 , V_2 -> V_3 + V_12 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_6 ( 0x0 , V_2 -> V_3 + V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
switch ( V_2 -> V_14 ) {
case V_15 :
case V_16 :
V_13 = F_11 ( V_2 ) ;
break;
case V_17 :
V_13 = F_12 ( V_2 ) ;
break;
default:
V_13 = - V_18 ;
}
if ( ! V_13 )
F_13 ( V_2 -> V_6 , L_3 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
switch ( V_2 -> V_14 ) {
case V_15 :
case V_16 :
V_13 = F_15 ( V_2 ) ;
break;
case V_17 :
V_13 = F_16 ( V_2 ) ;
break;
default:
V_13 = - V_18 ;
}
if ( ! V_13 )
F_13 ( V_2 -> V_6 , L_4 ) ;
return V_13 ;
}
static int F_17 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
int V_13 ;
struct V_1 * V_2 = F_18 ( V_20 -> V_21 ,
struct V_1 , V_22 ) ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( V_19 , V_20 ) ;
F_20 ( V_2 -> V_6 , L_5 , V_23 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_20 * V_20 , char T_3 * V_24 , T_4 V_25 ,
T_5 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_20 -> V_21 ,
struct V_1 , V_22 ) ;
char * V_27 = V_2 -> V_28 + * V_26 ;
if ( * V_26 + V_25 > V_2 -> V_25 )
V_25 = V_2 -> V_25 - * V_26 ;
if ( V_2 -> V_14 == V_17 ) {
if ( V_27 == ( char * ) ( V_2 -> V_29 + V_2 -> V_30 ) )
V_27 = V_2 -> V_29 ;
else if ( V_27 > ( char * ) ( V_2 -> V_29 + V_2 -> V_30 ) )
V_27 -= V_2 -> V_30 ;
if ( ( V_27 + V_25 ) > ( char * ) ( V_2 -> V_29 + V_2 -> V_30 ) )
V_25 = ( char * ) ( V_2 -> V_29 + V_2 -> V_30 ) - V_27 ;
}
if ( F_22 ( V_24 , V_27 , V_25 ) ) {
F_20 ( V_2 -> V_6 , L_6 , V_23 ) ;
return - V_31 ;
}
* V_26 += V_25 ;
F_20 ( V_2 -> V_6 , L_7 ,
V_23 , V_25 , ( int ) ( V_2 -> V_25 - * V_26 ) ) ;
return V_25 ;
}
static int F_23 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
int V_13 ;
struct V_1 * V_2 = F_18 ( V_20 -> V_21 ,
struct V_1 , V_22 ) ;
V_13 = F_14 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_20 ( V_2 -> V_6 , L_8 , V_23 ) ;
return 0 ;
}
static enum V_32 F_24 ( T_1 V_33 )
{
enum V_32 V_34 ;
switch ( F_25 ( V_33 , 8 , 10 ) ) {
case 0x2 :
V_34 = V_35 ;
break;
case 0x3 :
V_34 = V_36 ;
break;
case 0x4 :
V_34 = V_37 ;
break;
case 0x5 :
V_34 = V_38 ;
break;
default:
V_34 = 0 ;
}
return V_34 ;
}
static T_2 F_26 ( struct V_39 * V_6 ,
struct V_40 * V_41 , char * V_28 )
{
struct V_1 * V_2 = F_27 ( V_6 -> V_42 ) ;
unsigned long V_43 = V_2 -> V_44 ;
return sprintf ( V_28 , L_9 , V_43 ) ;
}
static T_2 F_28 ( struct V_39 * V_6 ,
struct V_40 * V_41 ,
const char * V_28 , T_4 V_30 )
{
int V_13 ;
unsigned long V_43 ;
struct V_1 * V_2 = F_27 ( V_6 -> V_42 ) ;
V_13 = F_29 ( V_28 , 16 , & V_43 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_44 = V_43 ;
return V_30 ;
}
static int F_30 ( struct V_45 * V_46 , const struct V_47 * V_48 )
{
int V_13 = 0 ;
T_1 V_33 ;
void T_6 * V_3 ;
struct V_39 * V_6 = & V_46 -> V_6 ;
struct V_49 * V_50 = NULL ;
struct V_1 * V_2 ;
struct V_51 * V_52 = & V_46 -> V_52 ;
struct V_53 V_54 = { 0 } ;
struct V_55 * V_56 = V_46 -> V_6 . V_57 ;
if ( V_56 ) {
V_50 = F_31 ( V_6 , V_56 ) ;
if ( F_32 ( V_50 ) ) {
V_13 = F_33 ( V_50 ) ;
goto V_58;
}
V_46 -> V_6 . V_59 = V_50 ;
}
V_13 = - V_60 ;
V_2 = F_34 ( V_6 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
goto V_58;
V_2 -> V_6 = & V_46 -> V_6 ;
F_35 ( V_6 , V_2 ) ;
V_3 = F_36 ( V_6 , V_52 ) ;
if ( F_32 ( V_3 ) ) {
V_13 = F_33 ( V_3 ) ;
goto V_58;
}
V_2 -> V_3 = V_3 ;
F_37 ( & V_2 -> V_62 ) ;
V_33 = F_5 ( V_2 -> V_3 + V_63 ) ;
V_2 -> V_14 = F_25 ( V_33 , 6 , 7 ) ;
V_2 -> V_34 = F_24 ( V_33 ) ;
if ( V_2 -> V_14 == V_17 ) {
if ( V_56 )
V_13 = F_38 ( V_56 ,
L_10 ,
& V_2 -> V_30 ) ;
if ( V_13 )
V_2 -> V_30 = V_64 ;
} else {
V_2 -> V_30 = F_5 ( V_2 -> V_3 + V_65 ) * 4 ;
}
F_39 ( & V_46 -> V_6 ) ;
V_54 . V_50 = V_50 ;
V_54 . V_6 = V_6 ;
V_54 . V_66 = V_67 ;
if ( V_2 -> V_14 == V_15 ) {
V_54 . type = V_68 ;
V_54 . V_69 . V_70 = V_71 ;
V_54 . V_72 = & V_73 ;
} else if ( V_2 -> V_14 == V_17 ) {
V_54 . type = V_68 ;
V_54 . V_69 . V_70 = V_71 ;
V_54 . V_72 = & V_74 ;
V_13 = F_40 ( V_6 , F_41 ( 40 ) ) ;
if ( V_13 )
goto V_58;
} else {
V_54 . type = V_75 ;
V_54 . V_69 . V_76 = V_77 ;
V_54 . V_72 = & V_78 ;
}
V_2 -> V_79 = F_42 ( & V_54 ) ;
if ( F_32 ( V_2 -> V_79 ) ) {
V_13 = F_33 ( V_2 -> V_79 ) ;
goto V_58;
}
V_2 -> V_22 . V_80 = V_50 -> V_80 ;
V_2 -> V_22 . V_81 = V_82 ;
V_2 -> V_22 . V_83 = & V_84 ;
V_13 = F_43 ( & V_2 -> V_22 ) ;
if ( V_13 )
F_44 ( V_2 -> V_79 ) ;
V_58:
return V_13 ;
}
