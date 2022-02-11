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
int V_26 = 0 ;
F_5 ( & V_2 -> V_27 ) ;
if ( F_6 ( V_5 , L_11 ) ) {
V_4 -> type = V_28 ;
} else if ( F_6 ( V_5 , L_12 ) ) {
V_4 -> type = V_12 ;
} else if ( F_6 ( V_5 , L_13 ) ) {
V_4 -> type = V_13 ;
} else if ( F_6 ( V_5 , L_14 ) ) {
V_4 -> type = V_6 ;
} else if ( F_6 ( V_5 , L_15 ) ) {
V_4 -> type = V_7 ;
} else if ( F_6 ( V_5 , L_16 ) ) {
V_4 -> type = V_8 ;
} else {
V_26 = - V_18 ;
goto V_29;
}
if ( F_7 ( V_2 ) &&
( V_25 != V_4 -> type ) ) {
if ( V_22 == V_30 )
V_26 = F_8 ( V_2 ) ;
else if ( V_22 == V_31 )
V_26 = F_9 ( V_2 ) ;
}
V_29:
if ( V_26 )
V_4 -> type = V_25 ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_4 ( V_2 , & V_2 -> V_19 . V_20 ,
V_30 , V_5 , V_23 ) ;
}
static T_1 F_12 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_1 ( V_2 , & V_2 -> V_19 . V_32 , V_5 ) ;
}
static T_1 F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_4 ( V_2 , & V_2 -> V_19 . V_32 ,
V_31 , V_5 , V_23 ) ;
}
static T_1 F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_17 , V_2 -> V_19 . V_33 ? 1 : 0 ) ;
}
static T_1 F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char * V_34 ;
int V_35 , V_26 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_5 ( & V_2 -> V_27 ) ;
if ( ( V_2 -> V_36 != V_37 ) &&
( V_2 -> V_36 != V_38 ) ) {
V_26 = - V_39 ;
goto V_29;
}
V_35 = F_16 ( V_5 , & V_34 , 16 ) ;
if ( ( V_35 == 0 ) || ( V_35 == 1 ) )
V_2 -> V_19 . V_33 = V_35 ;
else
V_26 = - V_18 ;
V_29:
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_17 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_17 , V_2 -> V_19 . V_40 ? 1 : 0 ) ;
}
static T_1 F_18 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
int V_26 = 0 ;
unsigned long V_35 ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_41 )
return - V_39 ;
if ( V_2 -> V_19 . V_42 == V_43 )
return - V_39 ;
F_5 ( & V_2 -> V_27 ) ;
if ( ( V_2 -> V_36 != V_37 ) &&
( V_2 -> V_36 != V_38 ) ) {
V_26 = - V_39 ;
goto V_29;
}
V_26 = F_19 ( V_5 , 16 , & V_35 ) ;
if ( V_26 ) {
V_26 = - V_18 ;
goto V_29;
}
switch ( V_35 ) {
case 0 :
V_2 -> V_19 . V_40 = V_35 ;
break;
case 1 :
F_20 ( F_21 ( V_2 ) , & V_2 -> V_44 ) ;
if ( V_2 -> V_44 . V_45 & V_46 ) {
V_2 -> V_19 . V_40 = V_35 ;
if ( V_2 -> V_47 . V_48 . V_49 !=
V_50 )
F_22 ( V_2 ,
V_50 ) ;
} else
V_26 = - V_39 ;
break;
default:
V_26 = - V_18 ;
}
V_29:
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_23 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
char V_51 [ 9 ] ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_41 )
return - V_39 ;
memcpy ( V_51 , V_2 -> V_19 . V_52 , sizeof( V_51 ) ) ;
F_24 ( V_51 , 8 ) ;
return sprintf ( V_5 , L_1 , V_51 ) ;
}
static T_1 F_25 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_53 * V_54 ;
char * V_34 ;
int V_35 ;
if ( ! V_2 )
return - V_18 ;
if ( V_2 -> V_9 . type != V_41 )
return - V_39 ;
if ( V_2 -> V_36 != V_37 &&
V_2 -> V_36 != V_38 )
return - V_39 ;
if ( V_2 -> V_19 . V_40 )
return - V_39 ;
if ( V_2 -> V_19 . V_42 == V_55 )
return - V_39 ;
V_34 = F_26 ( ( char * * ) & V_5 , L_18 ) ;
if ( strlen ( V_34 ) > 8 )
return - V_18 ;
if ( V_2 -> V_19 . V_52 [ 0 ] ) {
V_54 = F_27 ( V_31 ) ;
if ( ! V_54 )
return - V_56 ;
V_54 -> V_57 . V_58 . V_54 . V_59 [ 0 ] = F_28 ( 0xfe800000 ) ;
V_54 -> V_57 . V_58 . V_54 . V_59 [ 1 ] = 0x00000000 ;
for ( V_35 = 8 ; V_35 < 16 ; V_35 ++ )
V_54 -> V_57 . V_58 . V_54 . V_60 [ V_35 ] =
V_2 -> V_19 . V_52 [ V_35 - 8 ] ;
V_54 -> V_57 . V_58 . V_61 = 0 ;
V_54 -> type = V_62 ;
F_29 ( & V_2 -> V_63 ) ;
F_30 ( V_2 , V_54 ) ;
F_31 ( & V_2 -> V_63 ) ;
F_32 ( V_54 ) ;
}
if ( strlen ( V_34 ) == 0 ) {
V_2 -> V_19 . V_52 [ 0 ] = '\0' ;
if ( V_2 -> V_15 )
memcpy ( V_2 -> V_15 -> V_64 , V_2 -> V_19 . V_52 , 9 ) ;
F_33 ( V_2 , V_65 ) ;
return V_23 ;
}
if ( F_33 ( V_2 , V_43 ) )
return - V_39 ;
snprintf ( V_2 -> V_19 . V_52 , sizeof( V_2 -> V_19 . V_52 ) ,
L_19 , V_34 ) ;
F_34 ( V_2 -> V_19 . V_52 , 8 ) ;
if ( V_2 -> V_15 )
memcpy ( V_2 -> V_15 -> V_64 , V_2 -> V_19 . V_52 , 9 ) ;
V_54 = F_27 ( V_31 ) ;
if ( V_54 != NULL ) {
V_54 -> V_57 . V_58 . V_54 . V_59 [ 0 ] = F_28 ( 0xfe800000 ) ;
V_54 -> V_57 . V_58 . V_54 . V_59 [ 1 ] = 0x00000000 ;
for ( V_35 = 8 ; V_35 < 16 ; V_35 ++ )
V_54 -> V_57 . V_58 . V_54 . V_60 [ V_35 ] = V_2 -> V_19 . V_52 [ V_35 - 8 ] ;
V_54 -> V_57 . V_58 . V_61 = 0 ;
V_54 -> type = V_62 ;
} else
return - V_56 ;
F_29 ( & V_2 -> V_63 ) ;
F_35 ( V_2 , V_54 ) ;
F_31 ( & V_2 -> V_63 ) ;
F_32 ( V_54 ) ;
return V_23 ;
}
static T_1 F_36 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_17 , V_2 -> V_66 . V_67 ? 1 : 0 ) ;
}
static T_1 F_37 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
struct V_53 * V_54 ;
int V_35 , V_26 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_5 ( & V_2 -> V_27 ) ;
if ( ( V_2 -> V_36 != V_37 ) &&
( V_2 -> V_36 != V_38 ) ) {
V_26 = - V_39 ;
goto V_29;
}
if ( F_6 ( V_5 , L_20 ) ) {
V_2 -> V_66 . V_67 = ( V_2 -> V_66 . V_67 ) ? 0 : 1 ;
} else if ( F_6 ( V_5 , L_21 ) ) {
V_2 -> V_66 . V_67 = 1 ;
F_38 (card->ip_htable, i, addr, hnode) {
if ( ( V_54 -> type == V_62 ) &&
F_39 ( V_2 , V_54 ) )
V_54 -> V_68 |=
V_69 ;
}
} else if ( F_6 ( V_5 , L_22 ) ) {
V_2 -> V_66 . V_67 = 0 ;
F_38 (card->ip_htable, i, addr, hnode) {
if ( V_54 -> V_68 &
V_69 )
V_54 -> V_68 &=
~ V_69 ;
}
} else
V_26 = - V_18 ;
V_29:
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_40 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_17 , V_2 -> V_66 . V_70 ? 1 : 0 ) ;
}
static T_1 F_41 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
int V_26 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_5 ( & V_2 -> V_27 ) ;
if ( F_6 ( V_5 , L_20 ) )
V_2 -> V_66 . V_70 = ( V_2 -> V_66 . V_70 ) ? 0 : 1 ;
else if ( F_6 ( V_5 , L_21 ) )
V_2 -> V_66 . V_70 = 1 ;
else if ( F_6 ( V_5 , L_22 ) )
V_2 -> V_66 . V_70 = 0 ;
else
V_26 = - V_18 ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_42 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_71 )
{
struct V_72 * V_73 ;
char V_74 [ 40 ] ;
int V_75 ;
int V_35 = 0 ;
V_75 = ( V_71 == V_30 ) ? 12 : 40 ;
V_75 += ( V_71 == V_30 ) ? 5 : 6 ;
F_29 ( & V_2 -> V_63 ) ;
F_43 (ipatoe, &card->ipato.entries, entry) {
if ( V_73 -> V_71 != V_71 )
continue;
if ( ( V_76 - V_35 ) <= V_75 )
break;
F_44 ( V_71 , V_73 -> V_54 , V_74 ) ;
V_35 += snprintf ( V_5 + V_35 , V_76 - V_35 ,
L_23 , V_74 , V_73 -> V_77 ) ;
}
F_31 ( & V_2 -> V_63 ) ;
V_35 += snprintf ( V_5 + V_35 , V_76 - V_35 , L_18 ) ;
return V_35 ;
}
static T_1 F_45 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_42 ( V_5 , V_2 , V_30 ) ;
}
static int F_46 ( const char * V_5 , enum V_21 V_71 ,
T_3 * V_54 , int * V_77 )
{
const char * V_78 , * V_79 ;
char * V_34 ;
char V_80 [ 40 ] = { 0 , } ;
V_78 = V_5 ;
V_79 = strchr ( V_78 , '/' ) ;
if ( ! V_79 || ( V_79 - V_78 >= 40 ) ) {
return - V_18 ;
}
strncpy ( V_80 , V_78 , V_79 - V_78 ) ;
if ( F_47 ( V_80 , V_71 , V_54 ) ) {
return - V_18 ;
}
V_78 = V_79 + 1 ;
* V_77 = F_16 ( V_78 , & V_34 , 10 ) ;
if ( ! strlen ( V_78 ) ||
( V_34 == V_78 ) ||
( * V_77 > ( ( V_71 == V_30 ) ? 32 : 128 ) ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_48 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_71 )
{
struct V_72 * V_73 ;
T_3 V_54 [ 16 ] ;
int V_77 ;
int V_26 = 0 ;
F_5 ( & V_2 -> V_27 ) ;
V_26 = F_46 ( V_5 , V_71 , V_54 , & V_77 ) ;
if ( V_26 )
goto V_29;
V_73 = F_49 ( sizeof( struct V_72 ) , V_81 ) ;
if ( ! V_73 ) {
V_26 = - V_56 ;
goto V_29;
}
V_73 -> V_71 = V_71 ;
memcpy ( V_73 -> V_54 , V_54 , ( V_71 == V_30 ) ? 4 : 16 ) ;
V_73 -> V_77 = V_77 ;
V_26 = F_50 ( V_2 , V_73 ) ;
if ( V_26 )
F_32 ( V_73 ) ;
V_29:
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_51 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_48 ( V_5 , V_23 , V_2 , V_30 ) ;
}
static T_1 F_52 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_71 )
{
T_3 V_54 [ 16 ] ;
int V_77 ;
int V_26 = 0 ;
F_5 ( & V_2 -> V_27 ) ;
V_26 = F_46 ( V_5 , V_71 , V_54 , & V_77 ) ;
if ( ! V_26 )
F_53 ( V_2 , V_71 , V_54 , V_77 ) ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_54 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_52 ( V_5 , V_23 , V_2 , V_30 ) ;
}
static T_1 F_55 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return sprintf ( V_5 , L_17 , V_2 -> V_66 . V_82 ? 1 : 0 ) ;
}
static T_1 F_56 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
int V_26 = 0 ;
if ( ! V_2 )
return - V_18 ;
F_5 ( & V_2 -> V_27 ) ;
if ( F_6 ( V_5 , L_20 ) )
V_2 -> V_66 . V_82 = ( V_2 -> V_66 . V_82 ) ? 0 : 1 ;
else if ( F_6 ( V_5 , L_21 ) )
V_2 -> V_66 . V_82 = 1 ;
else if ( F_6 ( V_5 , L_22 ) )
V_2 -> V_66 . V_82 = 0 ;
else
V_26 = - V_18 ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_57 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_42 ( V_5 , V_2 , V_31 ) ;
}
static T_1 F_58 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_48 ( V_5 , V_23 , V_2 , V_31 ) ;
}
static T_1 F_59 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_52 ( V_5 , V_23 , V_2 , V_31 ) ;
}
static T_1 F_60 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_71 )
{
struct V_53 * V_83 ;
char V_74 [ 40 ] ;
int V_84 = 0 ;
int V_75 ;
int V_35 ;
V_75 = ( V_71 == V_30 ) ? 12 : 40 ;
V_75 += 2 ;
F_29 ( & V_2 -> V_63 ) ;
F_38 (card->ip_htable, i, ipaddr, hnode) {
if ( V_83 -> V_71 != V_71 )
continue;
if ( V_83 -> type != V_85 )
continue;
if ( ( V_76 - V_84 ) <= V_75 )
break;
F_44 ( V_71 , ( const T_3 * ) & V_83 -> V_57 ,
V_74 ) ;
V_84 += snprintf ( V_5 + V_84 , V_76 - V_84 , L_1 ,
V_74 ) ;
}
F_31 ( & V_2 -> V_63 ) ;
V_84 += snprintf ( V_5 + V_84 , V_76 - V_84 , L_18 ) ;
return V_84 ;
}
static T_1 F_61 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_60 ( V_5 , V_2 , V_30 ) ;
}
static int F_62 ( const char * V_5 , enum V_21 V_71 ,
T_3 * V_54 )
{
if ( F_47 ( V_5 , V_71 , V_54 ) ) {
return - V_18 ;
}
return 0 ;
}
static T_1 F_63 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_71 )
{
T_3 V_54 [ 16 ] = { 0 , } ;
int V_26 ;
F_5 ( & V_2 -> V_27 ) ;
V_26 = F_62 ( V_5 , V_71 , V_54 ) ;
if ( ! V_26 )
V_26 = F_64 ( V_2 , V_71 , V_54 ) ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_65 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_63 ( V_5 , V_23 , V_2 , V_30 ) ;
}
static T_1 F_66 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_71 )
{
T_3 V_54 [ 16 ] ;
int V_26 ;
F_5 ( & V_2 -> V_27 ) ;
V_26 = F_62 ( V_5 , V_71 , V_54 ) ;
if ( ! V_26 )
F_67 ( V_2 , V_71 , V_54 ) ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_68 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_66 ( V_5 , V_23 , V_2 , V_30 ) ;
}
static T_1 F_69 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_60 ( V_5 , V_2 , V_31 ) ;
}
static T_1 F_70 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_63 ( V_5 , V_23 , V_2 , V_31 ) ;
}
static T_1 F_71 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_66 ( V_5 , V_23 , V_2 , V_31 ) ;
}
static T_1 F_72 ( char * V_5 , struct V_1 * V_2 ,
enum V_21 V_71 )
{
struct V_53 * V_83 ;
char V_74 [ 40 ] ;
int V_84 = 0 ;
int V_75 ;
int V_35 ;
V_75 = ( V_71 == V_30 ) ? 12 : 40 ;
V_75 += 2 ;
F_29 ( & V_2 -> V_63 ) ;
F_38 (card->ip_htable, i, ipaddr, hnode) {
if ( V_83 -> V_71 != V_71 )
continue;
if ( V_83 -> type != V_86 )
continue;
if ( ( V_76 - V_84 ) <= V_75 )
break;
F_44 ( V_71 , ( const T_3 * ) & V_83 -> V_57 ,
V_74 ) ;
V_84 += snprintf ( V_5 + V_84 , V_76 - V_84 , L_1 ,
V_74 ) ;
}
F_31 ( & V_2 -> V_63 ) ;
V_84 += snprintf ( V_5 + V_84 , V_76 - V_84 , L_18 ) ;
return V_84 ;
}
static T_1 F_73 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_72 ( V_5 , V_2 , V_30 ) ;
}
static int F_74 ( const char * V_5 , enum V_21 V_71 ,
T_3 * V_54 )
{
T_4 V_87 ;
struct V_88 V_89 ;
if ( F_47 ( V_5 , V_71 , V_54 ) ) {
return - V_18 ;
}
if ( V_71 == V_30 ) {
memcpy ( & V_87 , V_54 , sizeof( V_87 ) ) ;
if ( F_75 ( V_87 ) ) {
F_76 ( 2 , L_24 ) ;
return - V_18 ;
}
} else if ( V_71 == V_31 ) {
memcpy ( & V_89 , V_54 , sizeof( V_89 ) ) ;
if ( F_77 ( & V_89 ) ) {
F_76 ( 2 , L_24 ) ;
return - V_18 ;
}
}
return 0 ;
}
static T_1 F_78 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_71 )
{
T_3 V_54 [ 16 ] = { 0 , } ;
int V_26 ;
F_5 ( & V_2 -> V_27 ) ;
V_26 = F_74 ( V_5 , V_71 , V_54 ) ;
if ( ! V_26 )
V_26 = F_79 ( V_2 , V_71 , V_54 ) ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_80 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_78 ( V_5 , V_23 , V_2 , V_30 ) ;
}
static T_1 F_81 ( const char * V_5 , T_2 V_23 ,
struct V_1 * V_2 , enum V_21 V_71 )
{
T_3 V_54 [ 16 ] ;
int V_26 ;
F_5 ( & V_2 -> V_27 ) ;
V_26 = F_74 ( V_5 , V_71 , V_54 ) ;
if ( ! V_26 )
F_82 ( V_2 , V_71 , V_54 ) ;
F_10 ( & V_2 -> V_27 ) ;
return V_26 ? V_26 : V_23 ;
}
static T_1 F_83 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_81 ( V_5 , V_23 , V_2 , V_30 ) ;
}
static T_1 F_84 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_5 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_72 ( V_5 , V_2 , V_31 ) ;
}
static T_1 F_85 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_78 ( V_5 , V_23 , V_2 , V_31 ) ;
}
static T_1 F_86 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_5 , T_2 V_23 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
if ( ! V_2 )
return - V_18 ;
return F_81 ( V_5 , V_23 , V_2 , V_31 ) ;
}
int F_87 ( struct V_14 * V_15 )
{
int V_90 ;
V_90 = F_88 ( & V_15 -> V_91 , & V_92 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_88 ( & V_15 -> V_91 , & V_93 ) ;
if ( V_90 ) {
F_89 ( & V_15 -> V_91 , & V_92 ) ;
return V_90 ;
}
V_90 = F_88 ( & V_15 -> V_91 , & V_94 ) ;
if ( V_90 ) {
F_89 ( & V_15 -> V_91 , & V_92 ) ;
F_89 ( & V_15 -> V_91 , & V_93 ) ;
return V_90 ;
}
V_90 = F_88 ( & V_15 -> V_91 , & V_95 ) ;
if ( V_90 ) {
F_89 ( & V_15 -> V_91 , & V_92 ) ;
F_89 ( & V_15 -> V_91 , & V_93 ) ;
F_89 ( & V_15 -> V_91 , & V_94 ) ;
return V_90 ;
}
return 0 ;
}
void F_90 ( struct V_14 * V_15 )
{
F_89 ( & V_15 -> V_91 , & V_92 ) ;
F_89 ( & V_15 -> V_91 , & V_93 ) ;
F_89 ( & V_15 -> V_91 , & V_94 ) ;
F_89 ( & V_15 -> V_91 , & V_95 ) ;
}
