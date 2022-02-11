static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
switch ( V_7 -> V_9 ) {
case V_10 :
return sprintf ( V_5 , L_1 ) ;
case V_11 :
return sprintf ( V_5 , L_2 ) ;
case V_12 :
return sprintf ( V_5 , L_3 ) ;
case V_13 :
if ( V_7 -> V_14 )
return sprintf ( V_5 , L_4 ) ;
else
return sprintf ( V_5 , L_5 ) ;
case V_15 :
return sprintf ( V_5 , L_6 ) ;
default:
return sprintf ( V_5 , L_7 ) ;
}
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_8 , V_7 -> V_16 . V_17 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_9 , F_5 ( V_7 ) ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_9 , F_7 ( V_7 ) ) ;
}
static inline const char * F_8 ( struct V_6 * V_7 )
{
if ( V_7 -> V_18 . V_19 == 16384 )
return L_10 ;
else if ( V_7 -> V_18 . V_19 == 24576 )
return L_11 ;
else if ( V_7 -> V_18 . V_19 == 32768 )
return L_12 ;
else if ( V_7 -> V_18 . V_19 == 40960 )
return L_13 ;
else
return L_14 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_9 , F_8 ( V_7 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_16 . V_20 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
unsigned int V_20 , V_23 ;
int V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
V_20 = F_13 ( V_5 , & V_22 , 16 ) ;
if ( V_20 > V_28 ) {
V_24 = - V_8 ;
goto V_27;
}
V_23 = ( V_7 -> V_29 . V_30 ? V_7 -> V_29 . V_30 - 1 : V_7 -> V_29 . V_30 ) ;
if ( V_20 > V_23 ) {
V_24 = - V_8 ;
goto V_27;
}
V_7 -> V_16 . V_20 = V_20 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_16 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_17 ( & V_7 -> V_31 -> V_2 ,
L_17 ) ;
return V_21 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
switch ( V_7 -> V_18 . V_32 ) {
case V_33 :
return sprintf ( V_5 , L_9 , L_18 ) ;
case V_34 :
return sprintf ( V_5 , L_9 , L_19 ) ;
case V_35 :
return sprintf ( V_5 , L_9 , L_20 ) ;
case V_36 :
return sprintf ( V_5 , L_9 , L_21 ) ;
default:
return sprintf ( V_5 , L_22 ,
V_7 -> V_18 . V_37 ) ;
}
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
if ( V_7 -> V_18 . V_38 == 1 ) {
V_7 -> V_18 . V_32 = V_39 ;
V_24 = - V_26 ;
goto V_27;
}
if ( F_20 ( V_5 , L_23 ) ) {
V_7 -> V_18 . V_32 = V_33 ;
V_7 -> V_18 . V_37 = V_40 ;
} else if ( F_20 ( V_5 , L_24 ) ) {
V_7 -> V_18 . V_32 = V_35 ;
V_7 -> V_18 . V_37 = V_40 ;
} else if ( F_20 ( V_5 , L_25 ) ) {
V_7 -> V_18 . V_32 = V_34 ;
V_7 -> V_18 . V_37 = V_40 ;
} else if ( F_20 ( V_5 , L_26 ) ) {
if ( ! V_7 -> V_41 . V_42 ) {
V_24 = - V_43 ;
goto V_27;
}
V_7 -> V_18 . V_32 = V_36 ;
V_7 -> V_18 . V_37 = V_40 ;
} else if ( F_20 ( V_5 , L_27 ) ) {
V_7 -> V_18 . V_32 = V_44 ;
V_7 -> V_18 . V_37 = 0 ;
} else if ( F_20 ( V_5 , L_28 ) ) {
V_7 -> V_18 . V_32 = V_44 ;
V_7 -> V_18 . V_37 = 1 ;
} else if ( F_20 ( V_5 , L_29 ) ) {
V_7 -> V_18 . V_32 = V_44 ;
V_7 -> V_18 . V_37 = 2 ;
} else if ( F_20 ( V_5 , L_30 ) ) {
V_7 -> V_18 . V_32 = V_44 ;
V_7 -> V_18 . V_37 = 3 ;
} else if ( F_20 ( V_5 , L_31 ) ) {
V_7 -> V_18 . V_32 = V_44 ;
V_7 -> V_18 . V_37 = V_40 ;
} else
V_24 = - V_8 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_18 . V_45 . V_46 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_47 , V_48 ;
int V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
V_48 = V_7 -> V_18 . V_45 . V_46 ;
V_47 = F_13 ( V_5 , & V_22 , 10 ) ;
V_47 = ( V_47 < V_49 ) ? V_49 :
( ( V_47 > V_50 ) ? V_50 : V_47 ) ;
if ( V_48 != V_47 ) {
V_24 = F_23 ( V_7 , V_47 ) ;
}
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_51 ;
if ( ! V_7 )
return - V_8 ;
if ( V_7 -> V_9 != V_13 )
return - V_26 ;
V_51 = F_13 ( V_5 , & V_22 , 16 ) ;
if ( V_51 == 1 )
F_25 ( V_7 ) ;
return V_21 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_41 . V_52 ? 1 : 0 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_51 , V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
V_51 = F_13 ( V_5 , & V_22 , 16 ) ;
if ( ( V_51 == 0 ) || ( V_51 == 1 ) ) {
if ( V_51 == V_7 -> V_41 . V_52 )
goto V_27;
V_7 -> V_41 . V_52 = V_51 ;
if ( V_51 == 0 )
memset ( & V_7 -> V_53 , 0 ,
sizeof( struct V_54 ) ) ;
V_7 -> V_53 . V_55 = V_7 -> V_56 . V_57 ;
V_7 -> V_53 . V_58 = V_7 -> V_56 . V_59 ;
} else
V_24 = - V_8 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_41 . V_42 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_51 , V_24 = 0 ;
enum V_60 V_61 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_62 ) ;
if ( V_7 -> V_9 != V_10 ) {
V_24 = - V_26 ;
goto V_27;
}
V_51 = F_13 ( V_5 , & V_22 , 16 ) ;
switch ( V_51 ) {
case 0 :
V_61 = V_63 ;
break;
case 1 :
V_61 = V_64 ;
break;
default:
V_24 = - V_8 ;
goto V_27;
}
if ( V_7 -> V_41 . V_42 == V_61 )
goto V_27;
else {
V_7 -> V_16 . V_65 = 0 ;
if ( V_7 -> V_66 ) {
V_7 -> V_66 -> remove ( V_7 -> V_31 ) ;
F_30 ( V_7 ) ;
}
}
V_24 = F_31 ( V_7 , V_61 ) ;
if ( V_24 )
goto V_27;
V_24 = V_7 -> V_66 -> V_67 ( V_7 -> V_31 ) ;
V_27:
F_14 ( & V_7 -> V_62 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
switch ( V_7 -> V_41 . V_68 ) {
case V_69 :
return snprintf ( V_5 , 6 , L_9 , V_70 ) ;
case V_71 :
return snprintf ( V_5 , 9 , L_9 , V_72 ) ;
case V_73 :
return snprintf ( V_5 , 6 , L_9 , V_74 ) ;
default:
return snprintf ( V_5 , 5 , L_9 , L_32 ) ;
}
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_75 V_68 ;
int V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_16 . type != V_76 &&
V_7 -> V_16 . type != V_77 &&
V_7 -> V_16 . type != V_78 ) {
V_24 = - V_79 ;
F_34 ( & V_7 -> V_31 -> V_2 , L_33
L_34 ) ;
goto V_27;
}
if ( F_20 ( V_5 , V_70 ) ) {
V_68 = V_69 ;
} else if ( F_20 ( V_5 , V_72 ) ) {
V_68 = V_71 ;
} else if ( F_20 ( V_5 , V_74 ) ) {
V_68 = V_73 ;
} else {
V_24 = - V_8 ;
goto V_27;
}
V_24 = V_21 ;
V_7 -> V_41 . V_80 = V_7 -> V_41 . V_68 ;
V_7 -> V_41 . V_68 = V_68 ;
if ( F_35 ( V_7 ) ) {
int V_81 = F_36 ( V_7 , 1 ) ;
if ( V_81 != 0 )
V_24 = V_81 ;
}
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_82 V_83 ;
int V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
if ( ! F_35 ( V_7 ) )
return sprintf ( V_5 , L_35 ) ;
V_24 = F_38 ( V_7 , & V_83 ) ;
if ( V_24 )
return V_24 ;
if ( ! V_83 . V_84 )
V_24 = sprintf ( V_5 , L_36 ) ;
if ( V_83 . V_84 & V_85 )
V_24 = sprintf ( V_5 , ( V_83 . V_86 & V_85 ?
L_37 : L_38 ) ) ;
if ( V_83 . V_84 & V_87 )
V_24 += sprintf ( V_5 + V_24 ,
( V_83 . V_86 & V_87 ?
L_39 : L_40 ) ) ;
V_24 += sprintf ( V_5 + V_24 , L_41 ) ;
return V_24 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
if ( V_7 -> V_16 . V_88 )
return snprintf ( V_5 , 5 , L_42 ) ;
else
return snprintf ( V_5 , 8 , L_43 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_24 = 0 ;
int V_9 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( F_35 ( V_7 ) )
V_9 = 1 ;
if ( F_20 ( V_5 , L_44 ) && ! V_7 -> V_16 . V_88 ) {
if ( V_9 ) {
if ( F_41 ( V_7 ,
V_89 ) ) {
V_24 = F_42 ( V_7 , V_90 ) ;
if ( ! V_24 )
V_7 -> V_16 . V_88 = 1 ;
} else
V_24 = - V_8 ;
} else
V_7 -> V_16 . V_88 = 1 ;
} else if ( F_20 ( V_5 , L_45 ) && V_7 -> V_16 . V_88 ) {
if ( V_9 ) {
V_24 = F_42 ( V_7 , V_91 ) ;
if ( ! V_24 )
V_7 -> V_16 . V_88 = 0 ;
} else
V_7 -> V_16 . V_88 = 0 ;
} else if ( F_20 ( V_5 , L_46 ) && V_9 && V_7 -> V_16 . V_88 )
V_24 = F_42 ( V_7 , V_92 ) ;
else
V_24 = - V_8 ;
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_43 ( char * V_5 , struct V_6 * V_7 , int V_93 )
{
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_93 ) ;
}
static T_1 F_44 ( struct V_6 * V_7 ,
const char * V_5 , T_2 V_21 , int * V_93 , int V_94 )
{
char * V_22 ;
int V_51 , V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
V_51 = F_13 ( V_5 , & V_22 , 10 ) ;
if ( V_51 <= V_94 )
* V_93 = V_51 ;
else
V_24 = - V_8 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_43 ( V_5 , V_7 , V_7 -> V_16 . V_95 . V_96 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_44 ( V_7 , V_5 , V_21 ,
& V_7 -> V_16 . V_95 . V_96 , 5000 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_43 ( V_5 , V_7 , V_7 -> V_16 . V_95 . V_97 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_44 ( V_7 , V_5 , V_21 ,
& V_7 -> V_16 . V_95 . V_97 , 1000 ) ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_43 ( V_5 , V_7 ,
V_7 -> V_16 . V_95 . V_98 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_44 ( V_7 , V_5 , V_21 ,
& V_7 -> V_16 . V_95 . V_98 , 1000 ) ;
}
