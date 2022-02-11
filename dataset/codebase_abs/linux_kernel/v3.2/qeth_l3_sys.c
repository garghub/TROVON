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
if ( V_2 -> V_19 . V_53 == V_54 )
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
F_23 ( F_24 ( V_2 ) , & V_2 -> V_55 ) ;
if ( V_2 -> V_55 . V_56 & V_57 ) {
V_2 -> V_19 . V_51 = V_38 ;
if ( V_2 -> V_58 . V_59 . V_60 !=
V_61 )
F_25 ( V_2 ,
V_61 ) ;
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
static T_1 F_26 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char V_62 [ 9 ] ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_52 )
return - V_41 ;
if ( V_2 -> V_31 == V_39 )
return - V_41 ;
memcpy ( V_62 , V_2 -> V_19 . V_63 , sizeof( V_62 ) ) ;
F_27 ( V_62 , 8 ) ;
return sprintf ( V_5 , L_1 , V_62 ) ;
}
static T_1 F_28 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_64 * V_65 ;
char * V_26 ;
int V_38 ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_52 )
return - V_41 ;
if ( V_2 -> V_31 != V_39 &&
V_2 -> V_31 != V_40 )
return - V_41 ;
if ( V_2 -> V_19 . V_51 )
return - V_41 ;
if ( V_2 -> V_19 . V_53 == V_66 )
return - V_41 ;
V_26 = F_5 ( ( char * * ) & V_5 , L_11 ) ;
if ( strlen ( V_26 ) > 8 )
return - V_18 ;
if ( V_2 -> V_19 . V_63 [ 0 ] ) {
V_65 = F_29 ( V_35 ) ;
if ( V_65 != NULL ) {
V_65 -> V_67 . V_68 . V_65 . V_69 [ 0 ] = 0xfe800000 ;
V_65 -> V_67 . V_68 . V_65 . V_69 [ 1 ] = 0x00000000 ;
for ( V_38 = 8 ; V_38 < 16 ; V_38 ++ )
V_65 -> V_67 . V_68 . V_65 . V_70 [ V_38 ] =
V_2 -> V_19 . V_63 [ V_38 - 8 ] ;
V_65 -> V_67 . V_68 . V_71 = 0 ;
V_65 -> type = V_72 ;
} else
return - V_73 ;
if ( ! F_30 ( V_2 , V_65 ) )
F_31 ( V_65 ) ;
F_32 ( V_2 ) ;
}
if ( strlen ( V_26 ) == 0 ) {
V_2 -> V_19 . V_63 [ 0 ] = '\0' ;
if ( V_2 -> V_15 )
memcpy ( V_2 -> V_15 -> V_74 , V_2 -> V_19 . V_63 , 9 ) ;
F_33 ( V_2 , V_75 ) ;
return V_23 ;
}
if ( F_33 ( V_2 , V_54 ) )
return - V_41 ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ )
V_2 -> V_19 . V_63 [ V_38 ] = ' ' ;
V_2 -> V_19 . V_63 [ 8 ] = '\0' ;
strncpy ( V_2 -> V_19 . V_63 , V_26 , strlen ( V_26 ) ) ;
F_34 ( V_2 -> V_19 . V_63 , 8 ) ;
if ( V_2 -> V_15 )
memcpy ( V_2 -> V_15 -> V_74 , V_2 -> V_19 . V_63 , 9 ) ;
V_65 = F_29 ( V_35 ) ;
if ( V_65 != NULL ) {
V_65 -> V_67 . V_68 . V_65 . V_69 [ 0 ] = 0xfe800000 ;
V_65 -> V_67 . V_68 . V_65 . V_69 [ 1 ] = 0x00000000 ;
for ( V_38 = 8 ; V_38 < 16 ; V_38 ++ )
V_65 -> V_67 . V_68 . V_65 . V_70 [ V_38 ] = V_2 -> V_19 . V_63 [ V_38 - 8 ] ;
V_65 -> V_67 . V_68 . V_71 = 0 ;
V_65 -> type = V_72 ;
} else
return - V_73 ;
if ( ! F_35 ( V_2 , V_65 ) )
F_31 ( V_65 ) ;
F_32 ( V_2 ) ;
return V_23 ;
}
static T_1 F_36 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_76 . V_77 ? 1 : 0 ) ;
}
static T_1 F_37 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_64 * V_78 , * V_79 ;
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
V_2 -> V_76 . V_77 = ( V_2 -> V_76 . V_77 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_24 ) ) {
V_2 -> V_76 . V_77 = 1 ;
F_38 (tmpipa, t, card->ip_tbd_list, entry) {
if ( ( V_78 -> type == V_72 ) &&
F_39 ( V_2 , V_78 ) )
V_78 -> V_80 |=
V_81 ;
}
} else if ( ! strcmp ( V_26 , L_25 ) ) {
V_2 -> V_76 . V_77 = 0 ;
F_38 (tmpipa, t, card->ip_tbd_list, entry) {
if ( V_78 -> V_80 &
V_81 )
V_78 -> V_80 &=
~ V_81 ;
}
} else
V_27 = - V_18 ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_40 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_76 . V_82 ? 1 : 0 ) ;
}
static T_1 F_41 ( struct V_14 * V_15 ,
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
V_2 -> V_76 . V_82 = ( V_2 -> V_76 . V_82 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_24 ) ) {
V_2 -> V_76 . V_82 = 1 ;
} else if ( ! strcmp ( V_26 , L_25 ) ) {
V_2 -> V_76 . V_82 = 0 ;
} else
V_27 = - V_18 ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_42 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_83 )
{
struct V_84 * V_85 ;
unsigned long V_86 ;
char V_87 [ 40 ] ;
int V_88 ;
int V_38 = 0 ;
V_88 = ( V_83 == V_34 ) ? 12 : 40 ;
V_88 += ( V_83 == V_34 ) ? 5 : 6 ;
F_43 ( & V_2 -> V_89 , V_86 ) ;
F_44 (ipatoe, &card->ipato.entries, entry) {
if ( V_85 -> V_83 != V_83 )
continue;
if ( ( V_90 - V_38 ) <= V_88 )
break;
F_45 ( V_83 , V_85 -> V_65 , V_87 ) ;
V_38 += snprintf ( V_5 + V_38 , V_90 - V_38 ,
L_26 , V_87 , V_85 -> V_91 ) ;
}
F_46 ( & V_2 -> V_89 , V_86 ) ;
V_38 += snprintf ( V_5 + V_38 , V_90 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_47 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_42 ( V_5 , V_2 , V_34 ) ;
}
static int F_48 ( const char * V_5 , enum V_21 V_83 ,
T_3 * V_65 , int * V_91 )
{
const char * V_92 , * V_93 ;
char * V_26 ;
char V_94 [ 40 ] = { 0 , } ;
V_92 = V_5 ;
V_93 = strchr ( V_92 , '/' ) ;
if ( ! V_93 || ( V_93 - V_92 >= 40 ) ) {
return - V_18 ;
}
strncpy ( V_94 , V_92 , V_93 - V_92 ) ;
if ( F_49 ( V_94 , V_83 , V_65 ) ) {
return - V_18 ;
}
V_92 = V_93 + 1 ;
* V_91 = F_15 ( V_92 , & V_26 , 10 ) ;
if ( ! strlen ( V_92 ) ||
( V_26 == V_92 ) ||
( * V_91 > ( ( V_83 == V_34 ) ? 32 : 128 ) ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_50 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_83 )
{
struct V_84 * V_85 ;
T_3 V_65 [ 16 ] ;
int V_91 ;
int V_27 = 0 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_48 ( V_5 , V_83 , V_65 , & V_91 ) ;
if ( V_27 )
goto V_30;
V_85 = F_51 ( sizeof( struct V_84 ) , V_95 ) ;
if ( ! V_85 ) {
V_27 = - V_73 ;
goto V_30;
}
V_85 -> V_83 = V_83 ;
memcpy ( V_85 -> V_65 , V_65 , ( V_83 == V_34 ) ? 4 : 16 ) ;
V_85 -> V_91 = V_91 ;
V_27 = F_52 ( V_2 , V_85 ) ;
if ( V_27 )
F_31 ( V_85 ) ;
V_30:
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_53 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_50 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_54 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_83 )
{
T_3 V_65 [ 16 ] ;
int V_91 ;
int V_27 = 0 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_48 ( V_5 , V_83 , V_65 , & V_91 ) ;
if ( ! V_27 )
F_55 ( V_2 , V_83 , V_65 , V_91 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_56 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_54 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_57 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_18 , V_2 -> V_76 . V_96 ? 1 : 0 ) ;
}
static T_1 F_58 ( struct V_14 * V_15 ,
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
V_2 -> V_76 . V_96 = ( V_2 -> V_76 . V_96 ) ? 0 : 1 ;
} else if ( ! strcmp ( V_26 , L_24 ) ) {
V_2 -> V_76 . V_96 = 1 ;
} else if ( ! strcmp ( V_26 , L_25 ) ) {
V_2 -> V_76 . V_96 = 0 ;
} else
V_27 = - V_18 ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_59 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_42 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_60 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_50 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_61 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_54 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_62 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_83 )
{
struct V_64 * V_97 ;
char V_87 [ 40 ] ;
int V_88 ;
unsigned long V_86 ;
int V_38 = 0 ;
V_88 = ( V_83 == V_34 ) ? 12 : 40 ;
V_88 += 2 ;
F_43 ( & V_2 -> V_89 , V_86 ) ;
F_44 (ipaddr, &card->ip_list, entry) {
if ( V_97 -> V_83 != V_83 )
continue;
if ( V_97 -> type != V_98 )
continue;
if ( ( V_90 - V_38 ) <= V_88 )
break;
F_45 ( V_83 , ( const T_3 * ) & V_97 -> V_67 ,
V_87 ) ;
V_38 += snprintf ( V_5 + V_38 , V_90 - V_38 , L_1 , V_87 ) ;
}
F_46 ( & V_2 -> V_89 , V_86 ) ;
V_38 += snprintf ( V_5 + V_38 , V_90 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_63 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_62 ( V_5 , V_2 , V_34 ) ;
}
static int F_64 ( const char * V_5 , enum V_21 V_83 ,
T_3 * V_65 )
{
if ( F_49 ( V_5 , V_83 , V_65 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_65 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_83 )
{
T_3 V_65 [ 16 ] = { 0 , } ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_64 ( V_5 , V_83 , V_65 ) ;
if ( ! V_27 )
V_27 = F_66 ( V_2 , V_83 , V_65 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_67 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_65 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_68 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_83 )
{
T_3 V_65 [ 16 ] ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_64 ( V_5 , V_83 , V_65 ) ;
if ( ! V_27 )
F_69 ( V_2 , V_83 , V_65 ) ;
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
static T_1 F_71 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_62 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_72 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_65 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_73 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_68 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_74 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_83 )
{
struct V_64 * V_97 ;
char V_87 [ 40 ] ;
int V_88 ;
unsigned long V_86 ;
int V_38 = 0 ;
V_88 = ( V_83 == V_34 ) ? 12 : 40 ;
V_88 += 2 ;
F_43 ( & V_2 -> V_89 , V_86 ) ;
F_44 (ipaddr, &card->ip_list, entry) {
if ( V_97 -> V_83 != V_83 )
continue;
if ( V_97 -> type != V_99 )
continue;
if ( ( V_90 - V_38 ) <= V_88 )
break;
F_45 ( V_83 , ( const T_3 * ) & V_97 -> V_67 ,
V_87 ) ;
V_38 += snprintf ( V_5 + V_38 , V_90 - V_38 , L_1 , V_87 ) ;
}
F_46 ( & V_2 -> V_89 , V_86 ) ;
V_38 += snprintf ( V_5 + V_38 , V_90 - V_38 , L_11 ) ;
return V_38 ;
}
static T_1 F_75 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_74 ( V_5 , V_2 , V_34 ) ;
}
static int F_76 ( const char * V_5 , enum V_21 V_83 ,
T_3 * V_65 )
{
if ( F_49 ( V_5 , V_83 , V_65 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_77 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_83 )
{
T_3 V_65 [ 16 ] = { 0 , } ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_76 ( V_5 , V_83 , V_65 ) ;
if ( ! V_27 )
V_27 = F_78 ( V_2 , V_83 , V_65 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_79 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_77 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_80 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_83 )
{
T_3 V_65 [ 16 ] ;
int V_27 ;
F_6 ( & V_2 -> V_28 ) ;
V_27 = F_76 ( V_5 , V_83 , V_65 ) ;
if ( ! V_27 )
F_81 ( V_2 , V_83 , V_65 ) ;
F_9 ( & V_2 -> V_28 ) ;
return V_27 ? V_27 : V_23 ;
}
static T_1 F_82 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_80 ( V_5 , V_23 , V_2 , V_34 ) ;
}
static T_1 F_83 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_74 ( V_5 , V_2 , V_35 ) ;
}
static T_1 F_84 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_77 ( V_5 , V_23 , V_2 , V_35 ) ;
}
static T_1 F_85 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_80 ( V_5 , V_23 , V_2 , V_35 ) ;
}
int F_86 ( struct V_14 * V_15 )
{
int V_100 ;
V_100 = F_87 ( & V_15 -> V_101 , & V_102 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_87 ( & V_15 -> V_101 , & V_103 ) ;
if ( V_100 ) {
F_88 ( & V_15 -> V_101 , & V_102 ) ;
return V_100 ;
}
V_100 = F_87 ( & V_15 -> V_101 , & V_104 ) ;
if ( V_100 ) {
F_88 ( & V_15 -> V_101 , & V_102 ) ;
F_88 ( & V_15 -> V_101 , & V_103 ) ;
return V_100 ;
}
V_100 = F_87 ( & V_15 -> V_101 , & V_105 ) ;
if ( V_100 ) {
F_88 ( & V_15 -> V_101 , & V_102 ) ;
F_88 ( & V_15 -> V_101 , & V_103 ) ;
F_88 ( & V_15 -> V_101 , & V_104 ) ;
return V_100 ;
}
return 0 ;
}
void F_89 ( struct V_14 * V_15 )
{
F_88 ( & V_15 -> V_101 , & V_102 ) ;
F_88 ( & V_15 -> V_101 , & V_103 ) ;
F_88 ( & V_15 -> V_101 , & V_104 ) ;
F_88 ( & V_15 -> V_101 , & V_105 ) ;
}
