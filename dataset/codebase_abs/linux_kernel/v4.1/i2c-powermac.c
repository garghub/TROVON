static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
unsigned short V_4 ,
char V_5 ,
T_3 V_6 ,
int V_7 ,
union V_8 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_13 = ( V_5 == V_14 ) ;
int V_15 = ( V_3 << 1 ) | V_13 ;
int V_16 , V_17 , V_18 ;
T_4 V_19 ;
T_3 * V_20 ;
T_3 V_21 [ 2 ] ;
if ( V_7 == V_22 || V_7 == V_23 ) {
V_16 = V_24 ;
V_17 = 0 ;
V_19 = 0 ;
} else {
V_16 = V_13 ? V_25 : V_26 ;
V_17 = 1 ;
V_19 = V_6 ;
}
switch ( V_7 ) {
case V_22 :
V_20 = NULL ;
V_18 = 0 ;
break;
case V_23 :
case V_27 :
V_20 = & V_9 -> V_28 ;
V_18 = 1 ;
break;
case V_29 :
if ( ! V_13 ) {
V_21 [ 0 ] = V_9 -> V_30 & 0xff ;
V_21 [ 1 ] = ( V_9 -> V_30 >> 8 ) & 0xff ;
}
V_20 = V_21 ;
V_18 = 2 ;
break;
case V_31 :
V_20 = V_9 -> V_32 ;
V_18 = V_9 -> V_32 [ 0 ] + 1 ;
break;
case V_33 :
V_20 = & V_9 -> V_32 [ 1 ] ;
V_18 = V_9 -> V_32 [ 0 ] ;
break;
default:
return - V_34 ;
}
V_12 = F_3 ( V_11 , 0 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_5 ( V_11 , V_16 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_2 ,
V_16 , V_12 ) ;
goto V_36;
}
V_12 = F_6 ( V_11 , V_15 , V_17 , V_19 , V_20 , V_18 ) ;
if ( V_12 ) {
if ( V_12 == - V_37 )
F_7 ( & V_2 -> V_35 ,
L_3
L_4 , V_15 >> 1 , V_7 , V_12 ) ;
else
F_4 ( & V_2 -> V_35 ,
L_3
L_4 , V_15 >> 1 , V_7 , V_12 ) ;
goto V_36;
}
if ( V_7 == V_29 && V_13 ) {
V_9 -> V_30 = ( ( T_2 ) V_21 [ 1 ] ) << 8 ;
V_9 -> V_30 |= V_21 [ 0 ] ;
}
V_36:
F_8 ( V_11 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_40 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_13 ;
int V_15 ;
if ( V_39 -> V_4 & V_41 )
return - V_34 ;
V_13 = ( V_39 -> V_4 & V_42 ) != 0 ;
V_15 = ( V_39 -> V_3 << 1 ) | V_13 ;
V_12 = F_3 ( V_11 , 0 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_5 ( V_11 , V_24 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_2 ,
V_24 , V_12 ) ;
goto V_36;
}
V_12 = F_6 ( V_11 , V_15 , 0 , 0 , V_39 -> V_20 , V_39 -> V_18 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_37 )
F_7 ( & V_2 -> V_35 , L_5 ,
V_15 & 1 ? L_6 : L_7 ,
V_15 >> 1 , V_12 ) ;
else
F_4 ( & V_2 -> V_35 , L_5 ,
V_15 & 1 ? L_6 : L_7 ,
V_15 >> 1 , V_12 ) ;
}
V_36:
F_8 ( V_11 ) ;
return V_12 < 0 ? V_12 : 1 ;
}
static T_4 F_10 ( struct V_1 * V_43 )
{
return V_44 | V_45 |
V_46 | V_47 |
V_48 | V_49 ;
}
static int F_11 ( struct V_50 * V_35 )
{
struct V_1 * V_43 = F_12 ( V_35 ) ;
F_13 ( V_43 ) ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
return 0 ;
}
static T_4 F_14 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_51 * V_52 )
{
const T_5 * V_53 ;
int V_18 ;
V_53 = F_15 ( V_52 , L_8 , & V_18 ) ;
if ( V_53 && ( V_18 >= sizeof( int ) ) )
return ( F_16 ( V_53 ) & 0xff ) >> 1 ;
V_53 = F_15 ( V_52 , L_9 , & V_18 ) ;
if ( V_53 && ( V_18 >= sizeof( int ) ) )
return ( F_16 ( V_53 ) & 0xff ) >> 1 ;
if ( ! strcmp ( V_52 -> V_54 , L_10 ) )
return 0x60 ;
else if ( ! strcmp ( V_52 -> V_54 , L_11 ) )
return 0x34 ;
F_17 ( & V_2 -> V_35 , L_12 , V_52 -> V_55 ) ;
return 0xffffffff ;
}
static void F_18 ( struct V_1 * V_2 ,
const char * type ,
T_4 V_3 )
{
struct V_56 V_57 = {} ;
struct V_58 * V_59 ;
strncpy ( V_57 . type , type , sizeof( V_57 . type ) ) ;
V_57 . V_3 = V_3 ;
V_59 = F_19 ( V_2 , & V_57 ) ;
if ( ! V_59 )
F_4 ( & V_2 -> V_35 ,
L_13 ,
type ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
bool V_60 )
{
struct V_51 * V_61 = F_21 ( V_11 ) ;
int V_12 ;
#define F_22 67
if ( F_23 ( V_61 , L_14 ) && ! V_60 ) {
union V_8 V_9 ;
V_12 = F_24 ( V_2 , 0x46 , 0 , V_14 ,
F_22 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_18 ( V_2 , L_15 , 0x46 ) ;
V_12 = F_24 ( V_2 , 0x47 , 0 , V_14 ,
F_22 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_18 ( V_2 , L_15 , 0x47 ) ;
}
}
static bool F_25 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
T_4 V_3 , char * type , int V_62 )
{
char V_63 [ 16 ] ;
if ( F_26 ( V_52 , V_63 , sizeof( V_63 ) ) >= 0 ) {
snprintf ( type , V_62 , L_16 , V_63 ) ;
return true ;
}
if ( ! strcmp ( V_52 -> V_54 , L_11 ) ) {
if ( V_3 == 0x34 ) {
snprintf ( type , V_62 , L_17 ) ;
return true ;
} else if ( V_3 == 0x35 ) {
snprintf ( type , V_62 , L_18 ) ;
return true ;
}
}
F_4 ( & V_2 -> V_35 , L_19
L_20 , V_52 -> V_55 ) ;
return false ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_58 * V_59 ;
struct V_51 * V_52 ;
bool V_60 = 0 ;
if ( ! strcmp ( V_2 -> V_35 . V_64 -> V_54 , L_21 ) )
return;
F_28 (adap->dev.of_node, node) {
struct V_56 V_57 = {} ;
T_4 V_3 ;
V_3 = F_14 ( V_2 , V_11 , V_52 ) ;
if ( V_3 == 0xffffffff )
continue;
if ( ! F_29 ( V_52 , V_2 ) )
continue;
F_7 ( & V_2 -> V_35 , L_22 ,
V_52 -> V_55 ) ;
if ( F_23 ( V_52 , L_23 ) )
V_60 = true ;
if ( ! F_25 ( V_2 , V_52 , V_3 ,
V_57 . type , sizeof( V_57 . type ) ) ) {
continue;
}
V_57 . V_3 = V_3 ;
V_57 . V_65 = F_30 ( V_52 , 0 ) ;
V_57 . V_64 = F_31 ( V_52 ) ;
V_59 = F_19 ( V_2 , & V_57 ) ;
if ( ! V_59 ) {
F_4 ( & V_2 -> V_35 , L_24
L_25 , V_52 -> V_55 ) ;
F_32 ( V_52 ) ;
continue;
}
}
F_20 ( V_2 , V_11 , V_60 ) ;
}
static int F_33 ( struct V_50 * V_35 )
{
struct V_10 * V_11 = F_34 ( & V_35 -> V_35 ) ;
struct V_51 * V_66 = NULL ;
struct V_1 * V_43 ;
const char * V_67 ;
int V_12 ;
if ( V_11 == NULL )
return - V_34 ;
V_43 = F_35 ( V_11 ) ;
switch( F_36 ( V_11 ) ) {
case V_68 :
V_66 = F_37 ( F_38 ( V_11 ) ) ;
if ( V_66 == NULL )
return - V_34 ;
V_67 = V_66 -> V_54 ;
break;
case V_69 :
V_67 = L_26 ;
break;
case V_70 :
V_67 = L_27 ;
break;
default:
return - V_34 ;
}
snprintf ( V_43 -> V_54 , sizeof( V_43 -> V_54 ) , L_28 , V_67 ,
F_39 ( V_11 ) ) ;
F_32 ( V_66 ) ;
F_40 ( V_35 , V_43 ) ;
V_43 -> V_71 = & V_72 ;
V_43 -> V_73 = & V_74 ;
F_41 ( V_43 , V_11 ) ;
V_43 -> V_35 . V_66 = & V_35 -> V_35 ;
V_43 -> V_35 . V_64 = NULL ;
V_12 = F_42 ( V_43 ) ;
if ( V_12 ) {
F_43 ( V_75 L_29
L_30 , V_43 -> V_54 ) ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
return V_12 ;
}
F_43 ( V_76 L_31 , V_43 -> V_54 ) ;
V_43 -> V_35 . V_64 = V_35 -> V_35 . V_64 ;
F_27 ( V_43 , V_11 ) ;
return 0 ;
}
