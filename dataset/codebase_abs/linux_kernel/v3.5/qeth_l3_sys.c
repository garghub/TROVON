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
return sprintf ( V_5 , L_18 , V_2 -> V_19 . V_42 ? 1 : 0 ) ;
}
static T_1 F_17 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
int V_27 = 0 ;
unsigned long V_38 ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_43 )
return - V_41 ;
if ( V_2 -> V_19 . V_44 == V_45 )
return - V_41 ;
F_6 ( & V_2 -> V_28 ) ;
if ( ( V_2 -> V_31 != V_39 ) &&
( V_2 -> V_31 != V_40 ) ) {
V_27 = - V_41 ;
goto V_30;
}
V_27 = F_18 ( V_5 , 16 , & V_38 ) ;
if ( V_27 ) {
V_27 = - V_18 ;
goto V_30;
}
switch ( V_38 ) {
case 0 :
V_2 -> V_19 . V_42 = V_38 ;
break;
case 1 :
F_19 ( F_20 ( V_2 ) , & V_2 -> V_46 ) ;
if ( V_2 -> V_46 . V_47 & V_48 ) {
V_2 -> V_19 . V_42 = V_38 ;
if ( V_2 -> V_49 . V_50 . V_51 !=
V_52 )
F_21 ( V_2 ,
V_52 ) ;
} else
V_27 = - V_41 ;
break;
default:
V_27 = - V_18 ;
}
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_22 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char V_53 [ 9 ] ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_43 )
return - V_41 ;
if ( V_2 -> V_31 == V_39 )
return - V_41 ;
memcpy ( V_53 , V_2 -> V_19 . V_54 , sizeof( V_53 ) ) ;
F_23 ( V_53 , 8 ) ;
return sprintf ( V_5 , L_1 , V_53 ) ;
}
static T_1 F_24 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_55 * V_56 ;
char * V_26 ;
int V_38 ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_43 )
return - V_41 ;
if ( V_2 -> V_31 != V_39 &&
V_2 -> V_31 != V_40 )
return - V_41 ;
if ( V_2 -> V_19 . V_42 )
return - V_41 ;
if ( V_2 -> V_19 . V_44 == V_57 )
return - V_41 ;
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( strlen ( V_26 ) > 8 )
return - V_18 ;
if ( V_2 -> V_19 . V_54 [ 0 ] ) {
V_56 = F_25 ( V_35 ) ;
if ( V_56 != NULL ) {
V_56 -> V_58 . V_59 . V_56 . V_60 [ 0 ] = 0xfe800000 ;
V_56 -> V_58 . V_59 . V_56 . V_60 [ 1 ] = 0x00000000 ;
for ( V_38 = 8 ; V_38 < 16 ; V_38 ++ )
V_56 -> V_58 . V_59 . V_56 . V_61 [ V_38 ] =
V_2 -> V_19 . V_54 [ V_38 - 8 ] ;
V_56 -> V_58 . V_59 . V_62 = 0 ;
V_56 -> type = V_63 ;
} else
return - V_64 ;
if ( ! F_26 ( V_2 , V_56 ) )
F_27 ( V_56 ) ;
F_28 ( V_2 ) ;
}
if ( strlen ( V_26 ) == 0 ) {
V_2 -> V_19 . V_54 [ 0 ] = '\0' ;
if ( V_2 -> V_15 )
memcpy ( V_2 -> V_15 -> V_65 , V_2 -> V_19 . V_54 , 9 ) ;
F_29 ( V_2 , V_66 ) ;
return V_23 ;
}
if ( F_29 ( V_2 , V_45 ) )
return - V_41 ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ )
V_2 -> V_19 . V_54 [ V_38 ] = ' ' ;
V_2 -> V_19 . V_54 [ 8 ] = '\0' ;
strncpy ( V_2 -> V_19 . V_54 , V_26 , strlen ( V_26 ) ) ;
F_30 ( V_2 -> V_19 . V_54 , 8 ) ;
if ( V_2 -> V_15 )
memcpy ( V_2 -> V_15 -> V_65 , V_2 -> V_19 . V_54 , 9 ) ;
V_56 = F_25 ( V_35 ) ;
if ( V_56 != NULL ) {
V_56 -> V_58 . V_59 . V_56 . V_60 [ 0 ] = 0xfe800000 ;
V_56 -> V_58 . V_59 . V_56 . V_60 [ 1 ] = 0x00000000 ;
for ( V_38 = 8 ; V_38 < 16 ; V_38 ++ )
V_56 -> V_58 . V_59 . V_56 . V_61 [ V_38 ] = V_2 -> V_19 . V_54 [ V_38 - 8 ] ;
V_56 -> V_58 . V_59 . V_62 = 0 ;
V_56 -> type = V_63 ;
} else
return - V_64 ;
if ( ! F_31 ( V_2 , V_56 ) )
F_27 ( V_56 ) ;
F_28 ( V_2 ) ;
return V_23 ;
}
static T_1 F_32 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_67 . V_68 ? 1 : 0 ) ;
}
static T_1 F_33 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_55 * V_69 , * V_70 ;
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
if ( ! strcmp ( V_26 , L_19 ) ) {
V_2 -> V_67 . V_68 = ( V_2 -> V_67 . V_68 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_20 ) ) {
V_2 -> V_67 . V_68 = 1 ;
F_34 (tmpipa, t, card->ip_tbd_list, entry) {
if ( ( V_69 -> type == V_63 ) &&
F_35 ( V_2 , V_69 ) )
V_69 -> V_71 |=
V_72 ;
}
} else if ( ! strcmp ( V_26 , L_21 ) ) {
V_2 -> V_67 . V_68 = 0 ;
F_34 (tmpipa, t, card->ip_tbd_list, entry) {
if ( V_69 -> V_71 &
V_72 )
V_69 -> V_71 &=
~ V_72 ;
}
} else
V_27 = - V_18 ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_36 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_67 . V_73 ? 1 : 0 ) ;
}
static T_1 F_37 ( struct V_14 * V_15 ,
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
if ( ! strcmp ( V_26 , L_19 ) ) {
V_2 -> V_67 . V_73 = ( V_2 -> V_67 . V_73 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_20 ) ) {
V_2 -> V_67 . V_73 = 1 ;
} else if ( ! strcmp ( V_26 , L_21 ) ) {
V_2 -> V_67 . V_73 = 0 ;
} else
V_27 = - V_18 ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_38 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_74 )
{
struct V_75 * V_76 ;
unsigned long V_77 ;
char V_78 [ 40 ] ;
int V_79 ;
int V_38 = 0 ;
V_79 = ( V_74 == V_34 ) ? 12 : 40 ;
V_79 += ( V_74 == V_34 ) ? 5 : 6 ;
F_39 ( & V_2 -> V_80 , V_77 ) ;
F_40 (ipatoe, &card->ipato.entries, entry) {
if ( V_76 -> V_74 != V_74 )
continue;
if ( ( V_81 - V_38 ) <= V_79 )
break;
F_41 ( V_74 , V_76 -> V_56 , V_78 ) ;
V_38 += snprintf ( V_5 + V_38 , V_81 - V_38 ,
L_22 , V_78 , V_76 -> V_82 ) ;
}
F_42 ( & V_2 -> V_80 , V_77 ) ;
V_38 += snprintf ( V_5 + V_38 , V_81 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_43 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_38 ( V_5 , V_2 , V_34 ) ;
}
static int F_44 ( const char * V_5 , enum V_21 V_74 ,
T_3 * V_56 , int * V_82 )
{
const char * V_83 , * V_84 ;
char * V_26 ;
char V_85 [ 40 ] = { 0 , } ;
V_83 = V_5 ;
V_84 = strchr ( V_83 , '/' ) ;
if ( ! V_84 || ( V_84 - V_83 >= 40 ) ) {
return - V_18 ;
}
strncpy ( V_85 , V_83 , V_84 - V_83 ) ;
if ( F_45 ( V_85 , V_74 , V_56 ) ) {
return - V_18 ;
}
V_83 = V_84 + 1 ;
* V_82 = F_15 ( V_83 , & V_26 , 10 ) ;
if ( ! strlen ( V_83 ) ||
( V_26 == V_83 ) ||
( * V_82 > ( ( V_74 == V_34 ) ? 32 : 128 ) ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_46 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_74 )
{
struct V_75 * V_76 ;
T_3 V_56 [ 16 ] ;
int V_82 ;
int V_27 = 0 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_44 ( V_5 , V_74 , V_56 , & V_82 ) ;
if ( V_27 )
goto V_30;
V_76 = F_47 ( sizeof( struct V_75 ) , V_86 ) ;
if ( ! V_76 ) {
V_27 = - V_64 ;
goto V_30;
}
V_76 -> V_74 = V_74 ;
memcpy ( V_76 -> V_56 , V_56 , ( V_74 == V_34 ) ? 4 : 16 ) ;
V_76 -> V_82 = V_82 ;
V_27 = F_48 ( V_2 , V_76 ) ;
if ( V_27 )
F_27 ( V_76 ) ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_49 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_46 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_50 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_74 )
{
T_3 V_56 [ 16 ] ;
int V_82 ;
int V_27 = 0 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_44 ( V_5 , V_74 , V_56 , & V_82 ) ;
if ( ! V_27 )
F_51 ( V_2 , V_74 , V_56 , V_82 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_52 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_50 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_53 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_67 . V_87 ? 1 : 0 ) ;
}
static T_1 F_54 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_26 ;
int V_27 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_6 ( & V_2 -> V_28 ) ;
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( ! strcmp ( V_26 , L_19 ) ) {
V_2 -> V_67 . V_87 = ( V_2 -> V_67 . V_87 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_20 ) ) {
V_2 -> V_67 . V_87 = 1 ;
} else if ( ! strcmp ( V_26 , L_21 ) ) {
V_2 -> V_67 . V_87 = 0 ;
} else
V_27 = - V_18 ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_55 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_38 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_56 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_46 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_57 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_50 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_58 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_74 )
{
struct V_55 * V_88 ;
char V_78 [ 40 ] ;
int V_79 ;
unsigned long V_77 ;
int V_38 = 0 ;
V_79 = ( V_74 == V_34 ) ? 12 : 40 ;
V_79 += 2 ;
F_39 ( & V_2 -> V_80 , V_77 ) ;
F_40 (ipaddr, &card->ip_list, entry) {
if ( V_88 -> V_74 != V_74 )
continue;
if ( V_88 -> type != V_89 )
continue;
if ( ( V_81 - V_38 ) <= V_79 )
break;
F_41 ( V_74 , ( const T_3 * ) & V_88 -> V_58 ,
V_78 ) ;
V_38 += snprintf ( V_5 + V_38 , V_81 - V_38 , L_1 , V_78 ) ;
}
F_42 ( & V_2 -> V_80 , V_77 ) ;
V_38 += snprintf ( V_5 + V_38 , V_81 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_59 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_58 ( V_5 , V_2 , V_34 ) ;
}
static int F_60 ( const char * V_5 , enum V_21 V_74 ,
T_3 * V_56 )
{
if ( F_45 ( V_5 , V_74 , V_56 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_61 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_74 )
{
T_3 V_56 [ 16 ] = { 0 , } ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_60 ( V_5 , V_74 , V_56 ) ;
if ( ! V_27 )
V_27 = F_62 ( V_2 , V_74 , V_56 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_63 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_61 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_64 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_74 )
{
T_3 V_56 [ 16 ] ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_60 ( V_5 , V_74 , V_56 ) ;
if ( ! V_27 )
F_65 ( V_2 , V_74 , V_56 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_66 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_64 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_67 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_58 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_68 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_61 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_69 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_64 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_70 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_74 )
{
struct V_55 * V_88 ;
char V_78 [ 40 ] ;
int V_79 ;
unsigned long V_77 ;
int V_38 = 0 ;
V_79 = ( V_74 == V_34 ) ? 12 : 40 ;
V_79 += 2 ;
F_39 ( & V_2 -> V_80 , V_77 ) ;
F_40 (ipaddr, &card->ip_list, entry) {
if ( V_88 -> V_74 != V_74 )
continue;
if ( V_88 -> type != V_90 )
continue;
if ( ( V_81 - V_38 ) <= V_79 )
break;
F_41 ( V_74 , ( const T_3 * ) & V_88 -> V_58 ,
V_78 ) ;
V_38 += snprintf ( V_5 + V_38 , V_81 - V_38 , L_1 , V_78 ) ;
}
F_42 ( & V_2 -> V_80 , V_77 ) ;
V_38 += snprintf ( V_5 + V_38 , V_81 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_71 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_70 ( V_5 , V_2 , V_34 ) ;
}
static int F_72 ( const char * V_5 , enum V_21 V_74 ,
T_3 * V_56 )
{
if ( F_45 ( V_5 , V_74 , V_56 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_73 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_74 )
{
T_3 V_56 [ 16 ] = { 0 , } ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_72 ( V_5 , V_74 , V_56 ) ;
if ( ! V_27 )
V_27 = F_74 ( V_2 , V_74 , V_56 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_75 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_73 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_76 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_74 )
{
T_3 V_56 [ 16 ] ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_72 ( V_5 , V_74 , V_56 ) ;
if ( ! V_27 )
F_77 ( V_2 , V_74 , V_56 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_78 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_76 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_79 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_70 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_80 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_73 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_81 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_76 ( V_5 , V_23 , V_2 , V_35 ) ;
}
int F_82 ( struct V_14 * V_15 )
{
int V_91 ;
V_91 = F_83 ( & V_15 -> V_92 , & V_93 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_83 ( & V_15 -> V_92 , & V_94 ) ;
if ( V_91 ) {
F_84 ( & V_15 -> V_92 , & V_93 ) ;
return V_91 ;
}
V_91 = F_83 ( & V_15 -> V_92 , & V_95 ) ;
if ( V_91 ) {
F_84 ( & V_15 -> V_92 , & V_93 ) ;
F_84 ( & V_15 -> V_92 , & V_94 ) ;
return V_91 ;
}
V_91 = F_83 ( & V_15 -> V_92 , & V_96 ) ;
if ( V_91 ) {
F_84 ( & V_15 -> V_92 , & V_93 ) ;
F_84 ( & V_15 -> V_92 , & V_94 ) ;
F_84 ( & V_15 -> V_92 , & V_95 ) ;
return V_91 ;
}
return 0 ;
}
void F_85 ( struct V_14 * V_15 )
{
F_84 ( & V_15 -> V_92 , & V_93 ) ;
F_84 ( & V_15 -> V_92 , & V_94 ) ;
F_84 ( & V_15 -> V_92 , & V_95 ) ;
F_84 ( & V_15 -> V_92 , & V_96 ) ;
}
