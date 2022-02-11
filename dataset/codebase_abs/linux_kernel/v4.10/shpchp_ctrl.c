static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_2 = V_2 ;
F_3 ( & V_5 -> V_8 , V_9 ) ;
F_4 ( V_2 -> V_10 , & V_5 -> V_8 ) ;
return 0 ;
}
T_2 F_5 ( T_2 V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
T_1 V_3 ;
F_6 ( V_13 , L_1 ) ;
V_2 = F_7 ( V_13 , V_11 + V_13 -> V_14 ) ;
V_2 -> V_15 -> V_16 ( V_2 , & ( V_2 -> V_17 ) ) ;
F_8 ( V_13 , L_2 , F_9 ( V_2 ) ) ;
V_3 = V_18 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
T_2 F_10 ( T_2 V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
T_2 V_19 ;
T_1 V_3 ;
F_6 ( V_13 , L_3 ) ;
V_2 = F_7 ( V_13 , V_11 + V_13 -> V_14 ) ;
V_2 -> V_15 -> V_16 ( V_2 , & ( V_2 -> V_17 ) ) ;
V_2 -> V_15 -> V_20 ( V_2 , & V_19 ) ;
F_6 ( V_13 , L_4 ,
V_2 -> V_17 , V_2 -> V_21 ) ;
if ( V_19 ) {
F_8 ( V_13 , L_5 , F_9 ( V_2 ) ) ;
V_3 = V_22 ;
if ( V_2 -> V_21 && V_2 -> V_17 ) {
V_3 = V_23 ;
F_11 ( V_13 , L_6 ) ;
}
} else {
F_8 ( V_13 , L_7 , F_9 ( V_2 ) ) ;
V_3 = V_24 ;
}
F_1 ( V_2 , V_3 ) ;
return 1 ;
}
T_2 F_12 ( T_2 V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
T_1 V_3 ;
F_6 ( V_13 , L_8 ) ;
V_2 = F_7 ( V_13 , V_11 + V_13 -> V_14 ) ;
V_2 -> V_15 -> V_16 ( V_2 , & ( V_2 -> V_17 ) ) ;
if ( V_2 -> V_17 ) {
F_8 ( V_13 , L_9 ,
F_9 ( V_2 ) ) ;
V_3 = V_25 ;
} else {
F_8 ( V_13 , L_10 ,
F_9 ( V_2 ) ) ;
V_3 = V_26 ;
}
F_1 ( V_2 , V_3 ) ;
return 1 ;
}
T_2 F_13 ( T_2 V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
T_1 V_3 ;
F_6 ( V_13 , L_11 ) ;
V_2 = F_7 ( V_13 , V_11 + V_13 -> V_14 ) ;
if ( ! ( V_2 -> V_15 -> V_27 ( V_2 ) ) ) {
F_8 ( V_13 , L_12 ,
F_9 ( V_2 ) ) ;
V_2 -> V_28 = 0x00 ;
V_3 = V_29 ;
} else {
F_8 ( V_13 , L_13 , F_9 ( V_2 ) ) ;
V_3 = V_23 ;
V_2 -> V_28 = 0xFF ;
F_8 ( V_13 , L_14 , V_11 ) ;
}
F_1 ( V_2 , V_3 ) ;
return 1 ;
}
static int F_14 ( struct V_12 * V_13 , struct V_1 * V_2 ,
enum V_30 V_31 )
{
int V_32 = 0 ;
F_6 ( V_13 , L_15 , V_31 ) ;
V_32 = V_2 -> V_15 -> V_33 ( V_2 , V_31 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_16 ,
V_34 ) ;
return V_35 ;
}
return V_32 ;
}
static int F_15 ( struct V_12 * V_13 , struct V_1 * V_36 ,
T_2 V_37 , enum V_30 V_38 , enum V_30 V_39 ,
enum V_30 V_40 )
{
int V_32 = 0 ;
if ( V_37 ) {
if ( V_38 < V_39 ) {
F_11 ( V_13 , L_17 ,
V_39 , V_38 ) ;
V_32 = V_35 ;
}
return V_32 ;
}
if ( V_38 < V_40 ) {
if ( V_39 != V_38 )
V_32 = F_14 ( V_13 , V_36 , V_38 ) ;
} else {
if ( V_39 != V_40 )
V_32 = F_14 ( V_13 , V_36 , V_40 ) ;
}
return V_32 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_11 ;
T_2 V_41 = 0 ;
int V_32 = 0 ;
enum V_30 V_38 , V_39 , V_40 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_42 * V_43 = V_13 -> V_44 -> V_45 ;
V_11 = V_2 -> V_46 - V_13 -> V_14 ;
F_6 ( V_13 , L_18 ,
V_34 , V_2 -> V_46 , V_13 -> V_14 , V_11 ) ;
V_32 = V_2 -> V_15 -> V_47 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_19 ) ;
return - 1 ;
}
if ( ( V_13 -> V_44 -> V_48 == 0x8086 ) && ( V_13 -> V_44 -> V_46 == 0x0332 ) ) {
V_32 = V_2 -> V_15 -> V_33 ( V_2 , V_49 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_16 ,
V_34 ) ;
return V_35 ;
}
V_32 = V_2 -> V_15 -> V_50 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_20 ) ;
return V_32 ;
}
}
V_32 = V_2 -> V_15 -> V_51 ( V_2 , & V_38 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_21 ) ;
return V_35 ;
}
V_39 = V_13 -> V_44 -> V_45 -> V_52 ;
V_40 = V_13 -> V_44 -> V_45 -> V_53 ;
if ( ! F_17 ( & V_13 -> V_44 -> V_45 -> V_54 ) )
V_41 = 1 ;
F_6 ( V_13 , L_22 ,
V_34 , V_41 , V_38 ,
V_39 , V_40 ) ;
V_32 = F_15 ( V_13 , V_2 , V_41 , V_38 , V_39 , V_40 ) ;
if ( V_32 )
return V_32 ;
V_32 = V_2 -> V_15 -> V_50 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_20 ) ;
return V_32 ;
}
F_18 ( 1000 ) ;
F_6 ( V_13 , L_23 , V_34 , V_2 -> V_28 ) ;
if ( V_2 -> V_28 == 0xFF ) {
F_6 ( V_13 , L_24 , V_34 ) ;
V_32 = V_55 ;
V_2 -> V_28 = 0 ;
goto V_56;
}
if ( F_19 ( V_2 ) ) {
F_11 ( V_13 , L_25 ,
F_20 ( V_43 ) , V_2 -> V_57 , V_2 -> V_46 ) ;
goto V_56;
}
V_2 -> V_28 = 0 ;
V_2 -> V_58 = 0x01 ;
V_2 -> V_21 = 1 ;
V_2 -> V_15 -> V_59 ( V_2 ) ;
return 0 ;
V_56:
V_32 = V_2 -> V_15 -> V_60 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_26 ,
V_34 ) ;
return V_32 ;
}
return ( V_32 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_2 V_11 ;
int V_32 ;
if ( F_22 ( V_2 ) )
return ( 1 ) ;
V_11 = V_2 -> V_46 - V_13 -> V_14 ;
V_2 = F_7 ( V_13 , V_11 + V_13 -> V_14 ) ;
F_6 ( V_13 , L_27 , V_34 , V_11 ) ;
if ( V_2 -> V_58 )
V_2 -> V_28 = 0x01 ;
V_32 = V_2 -> V_15 -> V_60 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_26 ,
V_34 ) ;
return V_32 ;
}
V_32 = V_2 -> V_15 -> V_61 ( V_2 , 0 ) ;
if ( V_32 ) {
F_11 ( V_13 , L_28 ) ;
return V_32 ;
}
V_2 -> V_21 = 0 ;
V_2 -> V_58 = 0 ;
return 0 ;
}
static void F_23 ( struct V_62 * V_8 )
{
struct V_63 * V_5 =
F_24 ( V_8 , struct V_63 , V_8 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_25 ( & V_2 -> V_64 ) ;
switch ( V_2 -> V_65 ) {
case V_66 :
F_26 ( & V_2 -> V_64 ) ;
F_27 ( V_2 ) ;
F_25 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = V_67 ;
break;
case V_68 :
F_26 ( & V_2 -> V_64 ) ;
if ( F_28 ( V_2 ) )
V_2 -> V_15 -> V_69 ( V_2 ) ;
F_25 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = V_67 ;
break;
default:
break;
}
F_26 ( & V_2 -> V_64 ) ;
F_29 ( V_5 ) ;
}
void F_30 ( struct V_62 * V_8 )
{
struct V_1 * V_2 = F_24 ( V_8 , struct V_1 , V_8 . V_8 ) ;
struct V_63 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_70 ) ;
if ( ! V_5 ) {
F_11 ( V_2 -> V_13 , L_29 ,
V_34 ) ;
return;
}
V_5 -> V_2 = V_2 ;
F_3 ( & V_5 -> V_8 , F_23 ) ;
F_25 ( & V_2 -> V_64 ) ;
switch ( V_2 -> V_65 ) {
case V_71 :
V_2 -> V_65 = V_66 ;
break;
case V_72 :
V_2 -> V_65 = V_68 ;
break;
default:
F_29 ( V_5 ) ;
goto V_73;
}
F_4 ( V_2 -> V_10 , & V_5 -> V_8 ) ;
V_73:
F_26 ( & V_2 -> V_64 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_74 * V_5 ;
int V_75 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_70 ) ;
if ( ! V_5 )
return - V_7 ;
V_1 -> V_15 -> V_76 ( V_1 , & ( V_5 -> V_77 ) ) ;
V_1 -> V_15 -> V_78 ( V_1 , & ( V_5 -> V_79 ) ) ;
V_1 -> V_15 -> V_20 ( V_1 , & ( V_5 -> V_80 ) ) ;
V_1 -> V_15 -> V_16 ( V_1 , & ( V_5 -> V_81 ) ) ;
V_75 = F_32 ( V_1 -> V_82 , V_5 ) ;
F_29 ( V_5 ) ;
return V_75 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_2 V_19 ;
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_2 -> V_65 ) {
case V_67 :
V_2 -> V_15 -> V_76 ( V_2 , & V_19 ) ;
if ( V_19 ) {
V_2 -> V_65 = V_71 ;
F_8 ( V_13 , L_30 ,
F_9 ( V_2 ) ) ;
} else {
V_2 -> V_65 = V_72 ;
F_8 ( V_13 , L_31 ,
F_9 ( V_2 ) ) ;
}
V_2 -> V_15 -> V_83 ( V_2 ) ;
V_2 -> V_15 -> V_61 ( V_2 , 0 ) ;
F_34 ( V_2 -> V_10 , & V_2 -> V_8 , 5 * V_84 ) ;
break;
case V_71 :
case V_72 :
F_8 ( V_13 , L_32 ,
F_9 ( V_2 ) ) ;
F_35 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_65 == V_71 )
V_2 -> V_15 -> V_59 ( V_2 ) ;
else
V_2 -> V_15 -> V_69 ( V_2 ) ;
V_2 -> V_15 -> V_61 ( V_2 , 0 ) ;
F_8 ( V_13 , L_33 ,
F_9 ( V_2 ) ) ;
V_2 -> V_65 = V_67 ;
break;
case V_66 :
case V_68 :
F_8 ( V_13 , L_34 ,
F_9 ( V_2 ) ) ;
F_31 ( V_2 ) ;
break;
default:
F_36 ( V_13 , L_35 ) ;
break;
}
}
static void V_9 ( struct V_62 * V_8 )
{
struct V_4 * V_5 = F_24 ( V_8 , struct V_4 , V_8 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_25 ( & V_2 -> V_64 ) ;
switch ( V_5 -> V_3 ) {
case V_18 :
F_33 ( V_2 ) ;
break;
case V_23 :
F_6 ( V_2 -> V_13 , L_24 , V_34 ) ;
V_2 -> V_15 -> V_61 ( V_2 , 1 ) ;
V_2 -> V_15 -> V_69 ( V_2 ) ;
break;
default:
F_31 ( V_2 ) ;
break;
}
F_26 ( & V_2 -> V_64 ) ;
F_29 ( V_5 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
int V_32 , V_85 = - V_86 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_25 ( & V_2 -> V_13 -> V_87 ) ;
V_32 = V_2 -> V_15 -> V_16 ( V_2 , & V_19 ) ;
if ( V_32 || ! V_19 ) {
F_8 ( V_13 , L_36 , F_9 ( V_2 ) ) ;
goto V_73;
}
V_32 = V_2 -> V_15 -> V_20 ( V_2 , & V_19 ) ;
if ( V_32 || V_19 ) {
F_8 ( V_13 , L_37 , F_9 ( V_2 ) ) ;
goto V_73;
}
V_32 = V_2 -> V_15 -> V_76 ( V_2 , & V_19 ) ;
if ( V_32 || V_19 ) {
F_8 ( V_13 , L_38 ,
F_9 ( V_2 ) ) ;
goto V_73;
}
V_2 -> V_58 = 1 ;
V_2 -> V_15 -> V_16 ( V_2 , & ( V_2 -> V_17 ) ) ;
V_2 -> V_15 -> V_76 ( V_2 , & ( V_2 -> V_21 ) ) ;
F_6 ( V_13 , L_39 , V_34 , V_2 -> V_21 ) ;
V_2 -> V_15 -> V_20 ( V_2 , & V_19 ) ;
if ( ( ( V_2 -> V_13 -> V_44 -> V_48 == V_88 ) ||
( V_2 -> V_13 -> V_44 -> V_46 == V_89 ) )
&& V_2 -> V_13 -> V_90 == 1 ) {
F_37 ( V_2 ) ;
V_85 = F_16 ( V_2 ) ;
F_38 ( V_2 ) ;
} else
V_85 = F_16 ( V_2 ) ;
if ( V_85 ) {
V_2 -> V_15 -> V_16 ( V_2 ,
& ( V_2 -> V_17 ) ) ;
V_2 -> V_15 -> V_20 ( V_2 , & V_19 ) ;
}
F_31 ( V_2 ) ;
V_73:
F_26 ( & V_2 -> V_13 -> V_87 ) ;
return V_85 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
int V_32 , V_85 = - V_86 ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( ! V_2 -> V_13 )
return - V_86 ;
F_25 ( & V_2 -> V_13 -> V_87 ) ;
V_32 = V_2 -> V_15 -> V_16 ( V_2 , & V_19 ) ;
if ( V_32 || ! V_19 ) {
F_8 ( V_13 , L_36 , F_9 ( V_2 ) ) ;
goto V_73;
}
V_32 = V_2 -> V_15 -> V_20 ( V_2 , & V_19 ) ;
if ( V_32 || V_19 ) {
F_8 ( V_13 , L_37 , F_9 ( V_2 ) ) ;
goto V_73;
}
V_32 = V_2 -> V_15 -> V_76 ( V_2 , & V_19 ) ;
if ( V_32 || ! V_19 ) {
F_8 ( V_13 , L_40 ,
F_9 ( V_2 ) ) ;
goto V_73;
}
V_85 = F_21 ( V_2 ) ;
F_31 ( V_2 ) ;
V_73:
F_26 ( & V_2 -> V_13 -> V_87 ) ;
return V_85 ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_85 = - V_86 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_25 ( & V_2 -> V_64 ) ;
switch ( V_2 -> V_65 ) {
case V_72 :
F_35 ( & V_2 -> V_8 ) ;
case V_67 :
V_2 -> V_65 = V_68 ;
F_26 ( & V_2 -> V_64 ) ;
V_85 = F_28 ( V_2 ) ;
F_25 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = V_67 ;
break;
case V_68 :
F_8 ( V_13 , L_41 ,
F_9 ( V_2 ) ) ;
break;
case V_71 :
case V_66 :
F_8 ( V_13 , L_42 ,
F_9 ( V_2 ) ) ;
break;
default:
F_11 ( V_13 , L_43 ,
F_9 ( V_2 ) ) ;
break;
}
F_26 ( & V_2 -> V_64 ) ;
return V_85 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_85 = - V_86 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_25 ( & V_2 -> V_64 ) ;
switch ( V_2 -> V_65 ) {
case V_71 :
F_35 ( & V_2 -> V_8 ) ;
case V_67 :
V_2 -> V_65 = V_66 ;
F_26 ( & V_2 -> V_64 ) ;
V_85 = F_27 ( V_2 ) ;
F_25 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = V_67 ;
break;
case V_66 :
F_8 ( V_13 , L_44 ,
F_9 ( V_2 ) ) ;
break;
case V_72 :
case V_68 :
F_8 ( V_13 , L_45 ,
F_9 ( V_2 ) ) ;
break;
default:
F_11 ( V_13 , L_43 ,
F_9 ( V_2 ) ) ;
break;
}
F_26 ( & V_2 -> V_64 ) ;
return V_85 ;
}
