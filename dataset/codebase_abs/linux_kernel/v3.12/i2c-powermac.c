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
if ( V_40 != 1 ) {
F_4 ( & V_2 -> V_35 ,
L_5 ) ;
return - V_41 ;
}
if ( V_39 -> V_4 & V_42 )
return - V_34 ;
V_13 = ( V_39 -> V_4 & V_43 ) != 0 ;
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
F_7 ( & V_2 -> V_35 , L_6 ,
V_15 & 1 ? L_7 : L_8 ,
V_15 >> 1 , V_12 ) ;
else
F_4 ( & V_2 -> V_35 , L_6 ,
V_15 & 1 ? L_7 : L_8 ,
V_15 >> 1 , V_12 ) ;
}
V_36:
F_8 ( V_11 ) ;
return V_12 < 0 ? V_12 : 1 ;
}
static T_4 F_10 ( struct V_1 * V_44 )
{
return V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 ;
}
static int F_11 ( struct V_51 * V_35 )
{
struct V_1 * V_44 = F_12 ( V_35 ) ;
F_13 ( V_44 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
return 0 ;
}
static T_4 F_14 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 )
{
const T_5 * V_54 ;
int V_18 ;
V_54 = F_15 ( V_53 , L_9 , & V_18 ) ;
if ( V_54 && ( V_18 >= sizeof( int ) ) )
return ( F_16 ( V_54 ) & 0xff ) >> 1 ;
V_54 = F_15 ( V_53 , L_10 , & V_18 ) ;
if ( V_54 && ( V_18 >= sizeof( int ) ) )
return ( F_16 ( V_54 ) & 0xff ) >> 1 ;
if ( ! strcmp ( V_53 -> V_55 , L_11 ) )
return 0x60 ;
else if ( ! strcmp ( V_53 -> V_55 , L_12 ) )
return 0x34 ;
F_17 ( & V_2 -> V_35 , L_13 , V_53 -> V_56 ) ;
return 0xffffffff ;
}
static void F_18 ( struct V_1 * V_2 ,
const char * type ,
T_4 V_3 )
{
struct V_57 V_58 = {} ;
struct V_59 * V_60 ;
strncpy ( V_58 . type , type , sizeof( V_58 . type ) ) ;
V_58 . V_3 = V_3 ;
V_60 = F_19 ( V_2 , & V_58 ) ;
if ( ! V_60 )
F_4 ( & V_2 -> V_35 ,
L_14 ,
type ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
bool V_61 )
{
struct V_52 * V_62 = F_21 ( V_11 ) ;
int V_12 ;
#define F_22 67
if ( F_23 ( V_62 , L_15 ) && ! V_61 ) {
union V_8 V_9 ;
V_12 = F_24 ( V_2 , 0x46 , 0 , V_14 ,
F_22 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_18 ( V_2 , L_16 , 0x46 ) ;
V_12 = F_24 ( V_2 , 0x47 , 0 , V_14 ,
F_22 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_18 ( V_2 , L_16 , 0x47 ) ;
}
}
static bool F_25 ( struct V_1 * V_2 ,
struct V_52 * V_53 ,
T_4 V_3 , char * type , int V_63 )
{
char V_64 [ 16 ] ;
if ( F_26 ( V_53 , V_64 , sizeof( V_64 ) ) >= 0 ) {
snprintf ( type , V_63 , L_17 , V_64 ) ;
return true ;
}
if ( ! strcmp ( V_53 -> V_55 , L_12 ) ) {
if ( V_3 == 0x34 ) {
snprintf ( type , V_63 , L_18 ) ;
return true ;
} else if ( V_3 == 0x35 ) {
snprintf ( type , V_63 , L_19 ) ;
return true ;
}
}
F_4 ( & V_2 -> V_35 , L_20
L_21 , V_53 -> V_56 ) ;
return false ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_59 * V_60 ;
struct V_52 * V_53 ;
bool V_61 = 0 ;
if ( ! strcmp ( V_2 -> V_35 . V_65 -> V_55 , L_22 ) )
return;
F_28 (adap->dev.of_node, node) {
struct V_57 V_58 = {} ;
T_4 V_3 ;
V_3 = F_14 ( V_2 , V_11 , V_53 ) ;
if ( V_3 == 0xffffffff )
continue;
if ( ! F_29 ( V_53 , V_2 ) )
continue;
F_7 ( & V_2 -> V_35 , L_23 ,
V_53 -> V_56 ) ;
if ( F_23 ( V_53 , L_24 ) )
V_61 = true ;
if ( ! F_25 ( V_2 , V_53 , V_3 ,
V_58 . type , sizeof( V_58 . type ) ) ) {
continue;
}
V_58 . V_3 = V_3 ;
V_58 . V_66 = F_30 ( V_53 , 0 ) ;
V_58 . V_65 = F_31 ( V_53 ) ;
V_60 = F_19 ( V_2 , & V_58 ) ;
if ( ! V_60 ) {
F_4 ( & V_2 -> V_35 , L_25
L_26 , V_53 -> V_56 ) ;
F_32 ( V_53 ) ;
continue;
}
}
F_20 ( V_2 , V_11 , V_61 ) ;
}
static int F_33 ( struct V_51 * V_35 )
{
struct V_10 * V_11 = F_34 ( & V_35 -> V_35 ) ;
struct V_52 * V_67 = NULL ;
struct V_1 * V_44 ;
const char * V_68 ;
int V_12 ;
if ( V_11 == NULL )
return - V_34 ;
V_44 = F_35 ( V_11 ) ;
switch( F_36 ( V_11 ) ) {
case V_69 :
V_67 = F_37 ( F_38 ( V_11 ) ) ;
if ( V_67 == NULL )
return - V_34 ;
V_68 = V_67 -> V_55 ;
break;
case V_70 :
V_68 = L_27 ;
break;
case V_71 :
V_68 = L_28 ;
break;
default:
return - V_34 ;
}
snprintf ( V_44 -> V_55 , sizeof( V_44 -> V_55 ) , L_29 , V_68 ,
F_39 ( V_11 ) ) ;
F_32 ( V_67 ) ;
F_40 ( V_35 , V_44 ) ;
V_44 -> V_72 = & V_73 ;
F_41 ( V_44 , V_11 ) ;
V_44 -> V_35 . V_67 = & V_35 -> V_35 ;
V_44 -> V_35 . V_65 = NULL ;
V_12 = F_42 ( V_44 ) ;
if ( V_12 ) {
F_43 ( V_74 L_30
L_31 , V_44 -> V_55 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
return V_12 ;
}
F_43 ( V_75 L_32 , V_44 -> V_55 ) ;
V_44 -> V_35 . V_65 = V_35 -> V_35 . V_65 ;
F_27 ( V_44 , V_11 ) ;
return 0 ;
}
