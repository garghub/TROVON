static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
switch ( V_4 -> type ) {
case V_6 :
return sprintf ( V_5 , L_1 , L_2 ) ;
case V_7 :
return sprintf ( V_5 , L_1 , L_3 ) ;
case V_8 :
if ( V_2 -> V_9 . V_10 == V_11 )
return sprintf ( V_5 , L_1 , L_4 ) ;
else
return sprintf ( V_5 , L_1 , L_5 ) ;
case V_12 :
if ( V_2 -> V_9 . V_10 == V_11 )
return sprintf ( V_5 , L_1 , L_6 ) ;
else
return sprintf ( V_5 , L_1 , L_7 ) ;
case V_13 :
if ( V_2 -> V_9 . V_10 == V_11 )
return sprintf ( V_5 , L_1 , L_8 ) ;
else
return sprintf ( V_5 , L_1 , L_9 ) ;
default:
return sprintf ( V_5 , L_1 , L_10 ) ;
}
}
static T_1 F_2 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_1 ( V_2 , & V_2 -> V_19 . V_20 , V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_21 V_22 ,
const char * V_5 , T_2 V_23 )
{
enum V_24 V_25 = V_4 -> type ;
char * V_26 ;
int V_27 = 0 ;
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
F_6 ( & V_2 -> V_28 ) ;
if ( ! strcmp ( V_26 , L_12 ) ) {
V_4 -> type = V_29 ;
} else if ( ! strcmp ( V_26 , L_13 ) ) {
V_4 -> type = V_12 ;
} else if ( ! strcmp ( V_26 , L_14 ) ) {
V_4 -> type = V_13 ;
} else if ( ! strcmp ( V_26 , L_15 ) ) {
V_4 -> type = V_6 ;
} else if ( ! strcmp ( V_26 , L_16 ) ) {
V_4 -> type = V_7 ;
} else if ( ! strcmp ( V_26 , L_17 ) ) {
V_4 -> type = V_8 ;
} else {
V_27 = - V_18 ;
goto V_30;
}
if ( ( ( V_2 -> V_31 == V_32 ) ||
( V_2 -> V_31 == V_33 ) ) &&
( V_25 != V_4 -> type ) ) {
if ( V_22 == V_34 )
V_27 = F_7 ( V_2 ) ;
else if ( V_22 == V_35 )
V_27 = F_8 ( V_2 ) ;
}
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_10 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_4 ( V_2 , & V_2 -> V_19 . V_20 ,
V_34 , V_5 , V_23 ) ;
}
static T_1 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_1 ( V_2 , & V_2 -> V_19 . V_36 , V_5 ) ;
}
static T_1 F_12 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_4 ( V_2 , & V_2 -> V_19 . V_36 ,
V_35 , V_5 , V_23 ) ;
}
static T_1 F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_19 . V_37 ? 1 : 0 ) ;
}
static T_1 F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_26 ;
int V_38 , V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
if ( ( V_2 -> V_31 != V_39 ) &&
( V_2 -> V_31 != V_40 ) ) {
V_27 = - V_41 ;
goto V_30;
}
V_38 = F_15 ( V_5 , & V_26 , 16 ) ;
if ( ( V_38 == 0 ) || ( V_38 == 1 ) )
V_2 -> V_19 . V_37 = V_38 ;
else
V_27 = - V_18 ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_16 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
if ( ! ( ( V_2 -> V_9 . V_42 == V_43 ) ||
( V_2 -> V_9 . V_42 == V_44 ) ) )
return sprintf ( V_5 , L_19 ) ;
return sprintf ( V_5 , L_1 , ( V_2 -> V_19 . V_45 ==
V_46 ) ?
L_20 : L_21 ) ;
}
static T_1 F_17 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_26 ;
int V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
if ( ( V_2 -> V_31 != V_39 ) &&
( V_2 -> V_31 != V_40 ) ) {
V_27 = - V_41 ;
goto V_30;
}
if ( ! ( ( V_2 -> V_9 . V_42 == V_43 ) ||
( V_2 -> V_9 . V_42 == V_44 ) ) ) {
V_27 = - V_18 ;
goto V_30;
}
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( ! strcmp ( V_26 , L_21 ) )
V_2 -> V_19 . V_45 = V_47 ;
else if ( ! strcmp ( V_26 , L_22 ) )
V_2 -> V_19 . V_45 = V_46 ;
else
V_27 = - V_18 ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_18 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
if ( ! ( ( V_2 -> V_9 . V_42 == V_43 ) ||
( V_2 -> V_9 . V_42 == V_44 ) ) )
return sprintf ( V_5 , L_19 ) ;
return sprintf ( V_5 , L_18 , ( V_2 -> V_19 . V_48 ==
V_49 ) ? 1 : 0 ) ;
}
static T_1 F_19 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_26 ;
int V_38 , V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
if ( ( V_2 -> V_31 != V_39 ) &&
( V_2 -> V_31 != V_40 ) ) {
V_27 = - V_41 ;
goto V_30;
}
if ( ! ( ( V_2 -> V_9 . V_42 == V_43 ) ||
( V_2 -> V_9 . V_42 == V_44 ) ) ) {
V_27 = - V_18 ;
goto V_30;
}
V_38 = F_15 ( V_5 , & V_26 , 16 ) ;
if ( ( V_38 == 0 ) || ( V_38 == 1 ) )
V_2 -> V_19 . V_48 = V_38 ?
V_49 :
V_50 ;
else
V_27 = - V_18 ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_20 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_19 . V_51 ? 1 : 0 ) ;
}
static T_1 F_21 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
int V_27 = 0 ;
unsigned long V_38 ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_52 )
return - V_41 ;
F_6 ( & V_2 -> V_28 ) ;
if ( ( V_2 -> V_31 != V_39 ) &&
( V_2 -> V_31 != V_40 ) ) {
V_27 = - V_41 ;
goto V_30;
}
V_27 = F_22 ( V_5 , 16 , & V_38 ) ;
if ( V_27 ) {
V_27 = - V_18 ;
goto V_30;
}
switch ( V_38 ) {
case 0 :
V_2 -> V_19 . V_51 = V_38 ;
break;
case 1 :
F_23 ( F_24 ( V_2 ) , & V_2 -> V_53 ) ;
if ( V_2 -> V_53 . V_54 & V_55 ) {
V_2 -> V_19 . V_51 = V_38 ;
if ( V_2 -> V_56 . V_57 . V_58 !=
V_59 )
F_25 ( V_2 ,
V_59 ) ;
break;
} else
V_27 = - V_41 ;
default:
V_27 = - V_18 ;
}
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_26 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_60 . V_61 ? 1 : 0 ) ;
}
static T_1 F_27 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_62 * V_63 , * V_64 ;
char * V_26 ;
int V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
if ( ( V_2 -> V_31 != V_39 ) &&
( V_2 -> V_31 != V_40 ) ) {
V_27 = - V_41 ;
goto V_30;
}
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( ! strcmp ( V_26 , L_23 ) ) {
V_2 -> V_60 . V_61 = ( V_2 -> V_60 . V_61 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_24 ) ) {
V_2 -> V_60 . V_61 = 1 ;
F_28 (tmpipa, t, card->ip_tbd_list, entry) {
if ( ( V_63 -> type == V_65 ) &&
F_29 ( V_2 , V_63 ) )
V_63 -> V_66 |=
V_67 ;
}
} else if ( ! strcmp ( V_26 , L_25 ) ) {
V_2 -> V_60 . V_61 = 0 ;
F_28 (tmpipa, t, card->ip_tbd_list, entry) {
if ( V_63 -> V_66 &
V_67 )
V_63 -> V_66 &=
~ V_67 ;
}
} else
V_27 = - V_18 ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_30 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_60 . V_68 ? 1 : 0 ) ;
}
static T_1 F_31 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_26 ;
int V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( ! strcmp ( V_26 , L_23 ) ) {
V_2 -> V_60 . V_68 = ( V_2 -> V_60 . V_68 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_24 ) ) {
V_2 -> V_60 . V_68 = 1 ;
} else if ( ! strcmp ( V_26 , L_25 ) ) {
V_2 -> V_60 . V_68 = 0 ;
} else
V_27 = - V_18 ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_32 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_69 )
{
struct V_70 * V_71 ;
unsigned long V_72 ;
char V_73 [ 40 ] ;
int V_74 ;
int V_38 = 0 ;
V_74 = ( V_69 == V_34 ) ? 12 : 40 ;
V_74 += ( V_69 == V_34 ) ? 5 : 6 ;
F_33 ( & V_2 -> V_75 , V_72 ) ;
F_34 (ipatoe, &card->ipato.entries, entry) {
if ( V_71 -> V_69 != V_69 )
continue;
if ( ( V_76 - V_38 ) <= V_74 )
break;
F_35 ( V_69 , V_71 -> V_77 , V_73 ) ;
V_38 += snprintf ( V_5 + V_38 , V_76 - V_38 ,
L_26 , V_73 , V_71 -> V_78 ) ;
}
F_36 ( & V_2 -> V_75 , V_72 ) ;
V_38 += snprintf ( V_5 + V_38 , V_76 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_37 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_32 ( V_5 , V_2 , V_34 ) ;
}
static int F_38 ( const char * V_5 , enum V_21 V_69 ,
T_3 * V_77 , int * V_78 )
{
const char * V_79 , * V_80 ;
char * V_26 ;
char V_81 [ 40 ] = { 0 , } ;
V_79 = V_5 ;
V_80 = strchr ( V_79 , '/' ) ;
if ( ! V_80 || ( V_80 - V_79 >= 40 ) ) {
return - V_18 ;
}
strncpy ( V_81 , V_79 , V_80 - V_79 ) ;
if ( F_39 ( V_81 , V_69 , V_77 ) ) {
return - V_18 ;
}
V_79 = V_80 + 1 ;
* V_78 = F_15 ( V_79 , & V_26 , 10 ) ;
if ( ! strlen ( V_79 ) ||
( V_26 == V_79 ) ||
( * V_78 > ( ( V_69 == V_34 ) ? 32 : 128 ) ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_40 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_69 )
{
struct V_70 * V_71 ;
T_3 V_77 [ 16 ] ;
int V_78 ;
int V_27 = 0 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_38 ( V_5 , V_69 , V_77 , & V_78 ) ;
if ( V_27 )
goto V_30;
V_71 = F_41 ( sizeof( struct V_70 ) , V_82 ) ;
if ( ! V_71 ) {
V_27 = - V_83 ;
goto V_30;
}
V_71 -> V_69 = V_69 ;
memcpy ( V_71 -> V_77 , V_77 , ( V_69 == V_34 ) ? 4 : 16 ) ;
V_71 -> V_78 = V_78 ;
V_27 = F_42 ( V_2 , V_71 ) ;
if ( V_27 )
F_43 ( V_71 ) ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_44 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_40 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_45 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_69 )
{
T_3 V_77 [ 16 ] ;
int V_78 ;
int V_27 = 0 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_38 ( V_5 , V_69 , V_77 , & V_78 ) ;
if ( ! V_27 )
F_46 ( V_2 , V_69 , V_77 , V_78 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_47 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_45 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_48 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_60 . V_84 ? 1 : 0 ) ;
}
static T_1 F_49 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_26 ;
int V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( ! strcmp ( V_26 , L_23 ) ) {
V_2 -> V_60 . V_84 = ( V_2 -> V_60 . V_84 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_24 ) ) {
V_2 -> V_60 . V_84 = 1 ;
} else if ( ! strcmp ( V_26 , L_25 ) ) {
V_2 -> V_60 . V_84 = 0 ;
} else
V_27 = - V_18 ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_50 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_32 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_51 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_40 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_52 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_45 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_53 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_69 )
{
struct V_62 * V_85 ;
char V_73 [ 40 ] ;
int V_74 ;
unsigned long V_72 ;
int V_38 = 0 ;
V_74 = ( V_69 == V_34 ) ? 12 : 40 ;
V_74 += 2 ;
F_33 ( & V_2 -> V_75 , V_72 ) ;
F_34 (ipaddr, &card->ip_list, entry) {
if ( V_85 -> V_69 != V_69 )
continue;
if ( V_85 -> type != V_86 )
continue;
if ( ( V_76 - V_38 ) <= V_74 )
break;
F_35 ( V_69 , ( const T_3 * ) & V_85 -> V_87 ,
V_73 ) ;
V_38 += snprintf ( V_5 + V_38 , V_76 - V_38 , L_1 , V_73 ) ;
}
F_36 ( & V_2 -> V_75 , V_72 ) ;
V_38 += snprintf ( V_5 + V_38 , V_76 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_54 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_53 ( V_5 , V_2 , V_34 ) ;
}
static int F_55 ( const char * V_5 , enum V_21 V_69 ,
T_3 * V_77 )
{
if ( F_39 ( V_5 , V_69 , V_77 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_56 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_69 )
{
T_3 V_77 [ 16 ] = { 0 , } ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_55 ( V_5 , V_69 , V_77 ) ;
if ( ! V_27 )
V_27 = F_57 ( V_2 , V_69 , V_77 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_58 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_56 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_59 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_69 )
{
T_3 V_77 [ 16 ] ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_55 ( V_5 , V_69 , V_77 ) ;
if ( ! V_27 )
F_60 ( V_2 , V_69 , V_77 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_61 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_59 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_62 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_53 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_63 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_56 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_64 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_59 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_65 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_69 )
{
struct V_62 * V_85 ;
char V_73 [ 40 ] ;
int V_74 ;
unsigned long V_72 ;
int V_38 = 0 ;
V_74 = ( V_69 == V_34 ) ? 12 : 40 ;
V_74 += 2 ;
F_33 ( & V_2 -> V_75 , V_72 ) ;
F_34 (ipaddr, &card->ip_list, entry) {
if ( V_85 -> V_69 != V_69 )
continue;
if ( V_85 -> type != V_88 )
continue;
if ( ( V_76 - V_38 ) <= V_74 )
break;
F_35 ( V_69 , ( const T_3 * ) & V_85 -> V_87 ,
V_73 ) ;
V_38 += snprintf ( V_5 + V_38 , V_76 - V_38 , L_1 , V_73 ) ;
}
F_36 ( & V_2 -> V_75 , V_72 ) ;
V_38 += snprintf ( V_5 + V_38 , V_76 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_66 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_65 ( V_5 , V_2 , V_34 ) ;
}
static int F_67 ( const char * V_5 , enum V_21 V_69 ,
T_3 * V_77 )
{
if ( F_39 ( V_5 , V_69 , V_77 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_68 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_69 )
{
T_3 V_77 [ 16 ] = { 0 , } ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_67 ( V_5 , V_69 , V_77 ) ;
if ( ! V_27 )
V_27 = F_69 ( V_2 , V_69 , V_77 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_70 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_68 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_71 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_69 )
{
T_3 V_77 [ 16 ] ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_67 ( V_5 , V_69 , V_77 ) ;
if ( ! V_27 )
F_72 ( V_2 , V_69 , V_77 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_73 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_71 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_74 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_65 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_75 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_68 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_76 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_71 ( V_5 , V_23 , V_2 , V_35 ) ;
}
int F_77 ( struct V_14 * V_15 )
{
int V_89 ;
V_89 = F_78 ( & V_15 -> V_90 , & V_91 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_78 ( & V_15 -> V_90 , & V_92 ) ;
if ( V_89 ) {
F_79 ( & V_15 -> V_90 , & V_91 ) ;
return V_89 ;
}
V_89 = F_78 ( & V_15 -> V_90 , & V_93 ) ;
if ( V_89 ) {
F_79 ( & V_15 -> V_90 , & V_91 ) ;
F_79 ( & V_15 -> V_90 , & V_92 ) ;
return V_89 ;
}
V_89 = F_78 ( & V_15 -> V_90 , & V_94 ) ;
if ( V_89 ) {
F_79 ( & V_15 -> V_90 , & V_91 ) ;
F_79 ( & V_15 -> V_90 , & V_92 ) ;
F_79 ( & V_15 -> V_90 , & V_93 ) ;
return V_89 ;
}
return 0 ;
}
void F_80 ( struct V_14 * V_15 )
{
F_79 ( & V_15 -> V_90 , & V_91 ) ;
F_79 ( & V_15 -> V_90 , & V_92 ) ;
F_79 ( & V_15 -> V_90 , & V_93 ) ;
F_79 ( & V_15 -> V_90 , & V_94 ) ;
}
