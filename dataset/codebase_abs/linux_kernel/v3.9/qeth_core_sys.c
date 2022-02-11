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
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_31 [ 9 ] = { 0 , } ;
if ( ! V_7 )
return - V_8 ;
if ( V_7 -> V_16 . V_32 ) {
memcpy ( V_31 , V_7 -> V_16 . V_31 + 1 , 8 ) ;
F_16 ( V_31 , 8 ) ;
return sprintf ( V_5 , L_9 , V_31 ) ;
} else
return sprintf ( V_5 , L_16 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_33 , V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
V_22 = F_18 ( ( char * * ) & V_5 , L_17 ) ;
if ( ( strlen ( V_22 ) > 8 ) || ( strlen ( V_22 ) == 0 ) ) {
V_24 = - V_8 ;
goto V_27;
}
V_7 -> V_16 . V_31 [ 0 ] = strlen ( V_22 ) ;
for ( V_33 = 1 ; V_33 < 9 ; V_33 ++ )
V_7 -> V_16 . V_31 [ V_33 ] = ' ' ;
strcpy ( V_7 -> V_16 . V_31 + 1 , V_22 ) ;
F_19 ( V_7 -> V_16 . V_31 + 1 , 8 ) ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
switch ( V_7 -> V_18 . V_34 ) {
case V_35 :
return sprintf ( V_5 , L_9 , L_18 ) ;
case V_36 :
return sprintf ( V_5 , L_9 , L_19 ) ;
default:
return sprintf ( V_5 , L_20 ,
V_7 -> V_18 . V_37 ) ;
}
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
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
V_7 -> V_18 . V_34 = V_39 ;
V_24 = - V_26 ;
goto V_27;
}
V_22 = F_18 ( ( char * * ) & V_5 , L_17 ) ;
if ( ! strcmp ( V_22 , L_21 ) )
V_7 -> V_18 . V_34 = V_35 ;
else if ( ! strcmp ( V_22 , L_22 ) )
V_7 -> V_18 . V_34 = V_36 ;
else if ( ! strcmp ( V_22 , L_23 ) ) {
V_7 -> V_18 . V_34 = V_40 ;
V_7 -> V_18 . V_37 = 0 ;
} else if ( ! strcmp ( V_22 , L_24 ) ) {
V_7 -> V_18 . V_34 = V_40 ;
V_7 -> V_18 . V_37 = 1 ;
} else if ( ! strcmp ( V_22 , L_25 ) ) {
V_7 -> V_18 . V_34 = V_40 ;
V_7 -> V_18 . V_37 = 2 ;
} else if ( ! strcmp ( V_22 , L_26 ) ) {
V_7 -> V_18 . V_34 = V_40 ;
V_7 -> V_18 . V_37 = 3 ;
} else if ( ! strcmp ( V_22 , L_27 ) ) {
V_7 -> V_18 . V_34 = V_40 ;
V_7 -> V_18 . V_37 = V_41 ;
} else
V_24 = - V_8 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_18 . V_42 . V_43 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_44 , V_45 ;
int V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
V_45 = V_7 -> V_18 . V_42 . V_43 ;
V_44 = F_13 ( V_5 , & V_22 , 10 ) ;
V_44 = ( V_44 < V_46 ) ? V_46 :
( ( V_44 > V_47 ) ? V_47 : V_44 ) ;
if ( V_45 != V_44 ) {
V_24 = F_24 ( V_7 , V_44 ) ;
}
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_33 ;
if ( ! V_7 )
return - V_8 ;
if ( V_7 -> V_9 != V_13 )
return - V_26 ;
V_33 = F_13 ( V_5 , & V_22 , 16 ) ;
if ( V_33 == 1 )
F_26 ( V_7 ) ;
return V_21 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_48 . V_49 ? 1 : 0 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_33 , V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
V_33 = F_13 ( V_5 , & V_22 , 16 ) ;
if ( ( V_33 == 0 ) || ( V_33 == 1 ) ) {
if ( V_33 == V_7 -> V_48 . V_49 )
goto V_27;
V_7 -> V_48 . V_49 = V_33 ;
if ( V_33 == 0 )
memset ( & V_7 -> V_50 , 0 ,
sizeof( struct V_51 ) ) ;
V_7 -> V_50 . V_52 = V_7 -> V_53 . V_54 ;
V_7 -> V_50 . V_55 = V_7 -> V_53 . V_56 ;
} else
V_24 = - V_8 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_7 -> V_48 . V_57 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_22 ;
int V_33 , V_24 = 0 ;
enum V_58 V_59 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_60 ) ;
if ( V_7 -> V_9 != V_10 ) {
V_24 = - V_26 ;
goto V_27;
}
V_33 = F_13 ( V_5 , & V_22 , 16 ) ;
switch ( V_33 ) {
case 0 :
V_59 = V_61 ;
break;
case 1 :
V_59 = V_62 ;
break;
default:
V_24 = - V_8 ;
goto V_27;
}
if ( V_7 -> V_48 . V_57 == V_59 )
goto V_27;
else {
V_7 -> V_16 . V_63 = 0 ;
if ( V_7 -> V_64 ) {
V_7 -> V_64 -> remove ( V_7 -> V_65 ) ;
F_31 ( V_7 ) ;
}
}
V_24 = F_32 ( V_7 , V_59 ) ;
if ( V_24 )
goto V_27;
V_24 = V_7 -> V_64 -> V_66 ( V_7 -> V_65 ) ;
V_27:
F_14 ( & V_7 -> V_60 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
switch ( V_7 -> V_48 . V_67 ) {
case V_68 :
return snprintf ( V_5 , 6 , L_9 , V_69 ) ;
case V_70 :
return snprintf ( V_5 , 9 , L_9 , V_71 ) ;
case V_72 :
return snprintf ( V_5 , 6 , L_9 , V_73 ) ;
default:
return snprintf ( V_5 , 5 , L_9 , L_28 ) ;
}
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_74 V_67 ;
int V_24 = 0 ;
char * V_22 , * V_75 ;
V_75 = ( char * ) V_5 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_16 . type != V_76 &&
V_7 -> V_16 . type != V_77 &&
V_7 -> V_16 . type != V_78 ) {
V_24 = - V_79 ;
F_35 ( & V_7 -> V_65 -> V_2 , L_29
L_30 ) ;
goto V_27;
}
V_22 = F_18 ( & V_75 , L_17 ) ;
if ( ! strcmp ( V_22 , V_69 ) ) {
V_67 = V_68 ;
} else if ( ! strcmp ( V_22 , V_71 ) ) {
V_67 = V_70 ;
} else if ( ! strcmp ( V_22 , V_73 ) ) {
V_67 = V_72 ;
} else {
V_24 = - V_8 ;
goto V_27;
}
V_24 = V_21 ;
V_7 -> V_48 . V_80 = V_7 -> V_48 . V_67 ;
V_7 -> V_48 . V_67 = V_67 ;
if ( V_7 -> V_9 == V_12 ||
V_7 -> V_9 == V_13 ) {
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
if ( ! V_7 )
return - V_8 ;
if ( V_7 -> V_16 . V_82 )
return snprintf ( V_5 , 5 , L_31 ) ;
else
return snprintf ( V_5 , 8 , L_32 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_24 = 0 ;
char * V_22 , * V_75 ;
int V_9 = 0 ;
V_75 = ( char * ) V_5 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_9 == V_12 || V_7 -> V_9 == V_13 )
V_9 = 1 ;
V_22 = F_18 ( & V_75 , L_17 ) ;
if ( ! strcmp ( V_22 , L_33 ) && ! V_7 -> V_16 . V_82 ) {
if ( V_9 ) {
if ( F_39 ( V_7 ,
V_83 ) ) {
V_24 = F_40 ( V_7 , V_84 ) ;
if ( ! V_24 )
V_7 -> V_16 . V_82 = 1 ;
} else
V_24 = - V_8 ;
} else
V_7 -> V_16 . V_82 = 1 ;
} else if ( ! strcmp ( V_22 , L_34 ) && V_7 -> V_16 . V_82 ) {
if ( V_9 ) {
V_24 = F_40 ( V_7 , V_85 ) ;
if ( ! V_24 )
V_7 -> V_16 . V_82 = 0 ;
} else
V_7 -> V_16 . V_82 = 0 ;
} else if ( ! strcmp ( V_22 , L_35 ) && V_9 && V_7 -> V_16 . V_82 )
V_24 = F_40 ( V_7 , V_86 ) ;
else
V_24 = - V_8 ;
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_41 ( char * V_5 , struct V_6 * V_7 , int V_87 )
{
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_15 , V_87 ) ;
}
static T_1 F_42 ( struct V_6 * V_7 ,
const char * V_5 , T_2 V_21 , int * V_87 , int V_88 )
{
char * V_22 ;
int V_33 , V_24 = 0 ;
if ( ! V_7 )
return - V_8 ;
F_12 ( & V_7 -> V_25 ) ;
if ( ( V_7 -> V_9 != V_10 ) &&
( V_7 -> V_9 != V_15 ) ) {
V_24 = - V_26 ;
goto V_27;
}
V_33 = F_13 ( V_5 , & V_22 , 10 ) ;
if ( V_33 <= V_88 )
* V_87 = V_33 ;
else
V_24 = - V_8 ;
V_27:
F_14 ( & V_7 -> V_25 ) ;
return V_24 ? V_24 : V_21 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_41 ( V_5 , V_7 , V_7 -> V_16 . V_89 . V_90 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_42 ( V_7 , V_5 , V_21 ,
& V_7 -> V_16 . V_89 . V_90 , 5000 ) ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_41 ( V_5 , V_7 , V_7 -> V_16 . V_89 . V_91 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_42 ( V_7 , V_5 , V_21 ,
& V_7 -> V_16 . V_89 . V_91 , 1000 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_41 ( V_5 , V_7 ,
V_7 -> V_16 . V_89 . V_92 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_42 ( V_7 , V_5 , V_21 ,
& V_7 -> V_16 . V_89 . V_92 , 1000 ) ;
}
