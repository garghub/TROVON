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
int V_15 ;
if ( V_39 -> V_4 & V_41 )
return - V_34 ;
V_15 = F_10 ( V_39 ) ;
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
static T_4 F_11 ( struct V_1 * V_42 )
{
return V_43 | V_44 |
V_45 | V_46 |
V_47 | V_48 ;
}
static int F_12 ( struct V_49 * V_35 )
{
struct V_1 * V_42 = F_13 ( V_35 ) ;
F_14 ( V_42 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
return 0 ;
}
static T_4 F_15 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_50 * V_51 )
{
const T_5 * V_52 ;
int V_18 ;
V_52 = F_16 ( V_51 , L_8 , & V_18 ) ;
if ( V_52 && ( V_18 >= sizeof( int ) ) )
return ( F_17 ( V_52 ) & 0xff ) >> 1 ;
V_52 = F_16 ( V_51 , L_9 , & V_18 ) ;
if ( V_52 && ( V_18 >= sizeof( int ) ) )
return ( F_17 ( V_52 ) & 0xff ) >> 1 ;
if ( ! strcmp ( V_51 -> V_53 , L_10 ) )
return 0x60 ;
else if ( ! strcmp ( V_51 -> V_53 , L_11 ) )
return 0x34 ;
F_18 ( & V_2 -> V_35 , L_12 , V_51 ) ;
return 0xffffffff ;
}
static void F_19 ( struct V_1 * V_2 ,
const char * type ,
T_4 V_3 )
{
struct V_54 V_55 = {} ;
struct V_56 * V_57 ;
strncpy ( V_55 . type , type , sizeof( V_55 . type ) ) ;
V_55 . V_3 = V_3 ;
V_57 = F_20 ( V_2 , & V_55 ) ;
if ( ! V_57 )
F_4 ( & V_2 -> V_35 ,
L_13 ,
type ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
bool V_58 )
{
struct V_50 * V_59 = F_22 ( V_11 ) ;
int V_12 ;
#define F_23 67
if ( F_24 ( V_59 , L_14 ) && ! V_58 ) {
union V_8 V_9 ;
V_12 = F_25 ( V_2 , 0x46 , 0 , V_14 ,
F_23 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_19 ( V_2 , L_15 , 0x46 ) ;
V_12 = F_25 ( V_2 , 0x47 , 0 , V_14 ,
F_23 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_19 ( V_2 , L_15 , 0x47 ) ;
}
}
static bool F_26 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_4 V_3 , char * type , int V_60 )
{
char V_61 [ 16 ] ;
if ( F_27 ( V_51 , V_61 , sizeof( V_61 ) ) >= 0 ) {
snprintf ( type , V_60 , L_16 , V_61 ) ;
return true ;
}
if ( ! strcmp ( V_51 -> V_53 , L_11 ) ) {
if ( V_3 == 0x34 ) {
snprintf ( type , V_60 , L_17 ) ;
return true ;
} else if ( V_3 == 0x35 ) {
snprintf ( type , V_60 , L_18 ) ;
return true ;
}
}
F_4 ( & V_2 -> V_35 , L_19 , V_51 ) ;
return false ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_56 * V_57 ;
struct V_50 * V_51 ;
bool V_58 = 0 ;
if ( ! strcmp ( V_2 -> V_35 . V_62 -> V_53 , L_20 ) )
return;
F_29 (adap->dev.of_node, node) {
struct V_54 V_55 = {} ;
T_4 V_3 ;
V_3 = F_15 ( V_2 , V_11 , V_51 ) ;
if ( V_3 == 0xffffffff )
continue;
if ( ! F_30 ( V_51 , V_2 ) )
continue;
F_7 ( & V_2 -> V_35 , L_21 , V_51 ) ;
if ( F_24 ( V_51 , L_22 ) )
V_58 = true ;
if ( ! F_26 ( V_2 , V_51 , V_3 ,
V_55 . type , sizeof( V_55 . type ) ) ) {
continue;
}
V_55 . V_3 = V_3 ;
V_55 . V_63 = F_31 ( V_51 , 0 ) ;
V_55 . V_62 = F_32 ( V_51 ) ;
V_57 = F_20 ( V_2 , & V_55 ) ;
if ( ! V_57 ) {
F_4 ( & V_2 -> V_35 , L_23
L_24 , V_51 ) ;
F_33 ( V_51 ) ;
continue;
}
}
F_21 ( V_2 , V_11 , V_58 ) ;
}
static int F_34 ( struct V_49 * V_35 )
{
struct V_10 * V_11 = F_35 ( & V_35 -> V_35 ) ;
struct V_50 * V_64 = NULL ;
struct V_1 * V_42 ;
const char * V_65 ;
int V_12 ;
if ( V_11 == NULL )
return - V_34 ;
V_42 = F_36 ( V_11 ) ;
switch( F_37 ( V_11 ) ) {
case V_66 :
V_64 = F_38 ( F_39 ( V_11 ) ) ;
if ( V_64 == NULL )
return - V_34 ;
V_65 = V_64 -> V_53 ;
break;
case V_67 :
V_65 = L_25 ;
break;
case V_68 :
V_65 = L_26 ;
break;
default:
return - V_34 ;
}
snprintf ( V_42 -> V_53 , sizeof( V_42 -> V_53 ) , L_27 , V_65 ,
F_40 ( V_11 ) ) ;
F_33 ( V_64 ) ;
F_41 ( V_35 , V_42 ) ;
V_42 -> V_69 = & V_70 ;
V_42 -> V_71 = & V_72 ;
F_42 ( V_42 , V_11 ) ;
V_42 -> V_35 . V_64 = & V_35 -> V_35 ;
V_42 -> V_35 . V_62 = NULL ;
V_12 = F_43 ( V_42 ) ;
if ( V_12 ) {
F_44 ( V_73 L_28
L_29 , V_42 -> V_53 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
return V_12 ;
}
F_44 ( V_74 L_30 , V_42 -> V_53 ) ;
V_42 -> V_35 . V_62 = V_35 -> V_35 . V_62 ;
F_28 ( V_42 , V_11 ) ;
return 0 ;
}
