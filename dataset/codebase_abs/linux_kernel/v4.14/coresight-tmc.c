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
static int F_30 ( struct V_1 * V_2 ,
T_1 V_33 , void * V_45 )
{
T_1 V_46 = 0 ;
F_31 ( V_2 , ( T_1 ) ( unsigned long ) V_45 ) ;
if ( ! ( V_33 & V_47 ) )
F_32 ( V_2 , V_48 ) ;
if ( V_33 & V_49 )
V_46 = ( ( V_33 >> V_50 ) &
V_51 ) ;
switch ( V_46 ) {
case 32 :
case 40 :
case 44 :
case 48 :
case 52 :
F_13 ( V_2 -> V_6 , L_10 , V_46 ) ;
break;
default:
V_46 = 40 ;
}
return F_33 ( V_2 -> V_6 , F_34 ( V_46 ) ) ;
}
static int F_35 ( struct V_52 * V_53 , const struct V_54 * V_55 )
{
int V_13 = 0 ;
T_1 V_33 ;
void T_6 * V_3 ;
struct V_39 * V_6 = & V_53 -> V_6 ;
struct V_56 * V_57 = NULL ;
struct V_1 * V_2 ;
struct V_58 * V_59 = & V_53 -> V_59 ;
struct V_60 V_61 = { 0 } ;
struct V_62 * V_63 = V_53 -> V_6 . V_64 ;
if ( V_63 ) {
V_57 = F_36 ( V_6 , V_63 ) ;
if ( F_37 ( V_57 ) ) {
V_13 = F_38 ( V_57 ) ;
goto V_65;
}
V_53 -> V_6 . V_66 = V_57 ;
}
V_13 = - V_67 ;
V_2 = F_39 ( V_6 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
goto V_65;
V_2 -> V_6 = & V_53 -> V_6 ;
F_40 ( V_6 , V_2 ) ;
V_3 = F_41 ( V_6 , V_59 ) ;
if ( F_37 ( V_3 ) ) {
V_13 = F_38 ( V_3 ) ;
goto V_65;
}
V_2 -> V_3 = V_3 ;
F_42 ( & V_2 -> V_69 ) ;
V_33 = F_5 ( V_2 -> V_3 + V_70 ) ;
V_2 -> V_14 = F_25 ( V_33 , 6 , 7 ) ;
V_2 -> V_34 = F_24 ( V_33 ) ;
if ( V_2 -> V_14 == V_17 ) {
if ( V_63 )
V_13 = F_43 ( V_63 ,
L_11 ,
& V_2 -> V_30 ) ;
if ( V_13 )
V_2 -> V_30 = V_71 ;
} else {
V_2 -> V_30 = F_5 ( V_2 -> V_3 + V_72 ) * 4 ;
}
F_44 ( & V_53 -> V_6 ) ;
V_61 . V_57 = V_57 ;
V_61 . V_6 = V_6 ;
V_61 . V_73 = V_74 ;
switch ( V_2 -> V_14 ) {
case V_15 :
V_61 . type = V_75 ;
V_61 . V_76 . V_77 = V_78 ;
V_61 . V_79 = & V_80 ;
break;
case V_17 :
V_61 . type = V_75 ;
V_61 . V_76 . V_77 = V_78 ;
V_61 . V_79 = & V_81 ;
V_13 = F_30 ( V_2 , V_33 , V_55 -> V_24 ) ;
if ( V_13 )
goto V_65;
break;
case V_16 :
V_61 . type = V_82 ;
V_61 . V_76 . V_83 = V_84 ;
V_61 . V_79 = & V_85 ;
break;
default:
F_45 ( L_12 , V_57 -> V_86 ) ;
V_13 = - V_18 ;
goto V_65;
}
V_2 -> V_87 = F_46 ( & V_61 ) ;
if ( F_37 ( V_2 -> V_87 ) ) {
V_13 = F_38 ( V_2 -> V_87 ) ;
goto V_65;
}
V_2 -> V_22 . V_86 = V_57 -> V_86 ;
V_2 -> V_22 . V_88 = V_89 ;
V_2 -> V_22 . V_90 = & V_91 ;
V_13 = F_47 ( & V_2 -> V_22 ) ;
if ( V_13 )
F_48 ( V_2 -> V_87 ) ;
V_65:
return V_13 ;
}
