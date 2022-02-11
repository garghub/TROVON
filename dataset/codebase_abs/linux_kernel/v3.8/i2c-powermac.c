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
int V_12 ;
V_12 = F_13 ( V_44 ) ;
if ( V_12 )
F_14 ( V_52
L_9 ,
V_44 -> V_53 ) ;
F_15 ( V_35 , NULL ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
return 0 ;
}
static T_4 F_16 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_54 * V_55 )
{
const T_5 * V_56 ;
int V_18 ;
V_56 = F_17 ( V_55 , L_10 , & V_18 ) ;
if ( V_56 && ( V_18 >= sizeof( int ) ) )
return ( F_18 ( V_56 ) & 0xff ) >> 1 ;
V_56 = F_17 ( V_55 , L_11 , & V_18 ) ;
if ( V_56 && ( V_18 >= sizeof( int ) ) )
return ( F_18 ( V_56 ) & 0xff ) >> 1 ;
if ( ! strcmp ( V_55 -> V_53 , L_12 ) )
return 0x60 ;
else if ( ! strcmp ( V_55 -> V_53 , L_13 ) )
return 0x34 ;
F_19 ( & V_2 -> V_35 , L_14 , V_55 -> V_57 ) ;
return 0xffffffff ;
}
static void F_20 ( struct V_1 * V_2 ,
const char * type ,
T_4 V_3 )
{
struct V_58 V_59 = {} ;
struct V_60 * V_61 ;
strncpy ( V_59 . type , type , sizeof( V_59 . type ) ) ;
V_59 . V_3 = V_3 ;
V_61 = F_21 ( V_2 , & V_59 ) ;
if ( ! V_61 )
F_4 ( & V_2 -> V_35 ,
L_15 ,
type ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
bool V_62 )
{
struct V_54 * V_63 = F_23 ( V_11 ) ;
int V_12 ;
#define F_24 67
if ( F_25 ( V_63 , L_16 ) && ! V_62 ) {
union V_8 V_9 ;
V_12 = F_26 ( V_2 , 0x46 , 0 , V_14 ,
F_24 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_20 ( V_2 , L_17 , 0x46 ) ;
V_12 = F_26 ( V_2 , 0x47 , 0 , V_14 ,
F_24 , V_27 ,
& V_9 ) ;
if ( V_12 >= 0 )
F_20 ( V_2 , L_17 , 0x47 ) ;
}
}
static bool F_27 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
T_4 V_3 , char * type , int V_64 )
{
char V_65 [ 16 ] ;
if ( F_28 ( V_55 , V_65 , sizeof( V_65 ) ) >= 0 ) {
snprintf ( type , V_64 , L_18 , V_65 ) ;
return true ;
}
if ( ! strcmp ( V_55 -> V_53 , L_13 ) ) {
if ( V_3 == 0x34 ) {
snprintf ( type , V_64 , L_19 ) ;
return true ;
} else if ( V_3 == 0x35 ) {
snprintf ( type , V_64 , L_20 ) ;
return true ;
}
}
F_4 ( & V_2 -> V_35 , L_21
L_22 , V_55 -> V_57 ) ;
return false ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_60 * V_61 ;
struct V_54 * V_55 ;
bool V_62 = 0 ;
if ( ! strcmp ( V_2 -> V_35 . V_66 -> V_53 , L_23 ) )
return;
F_30 (adap->dev.of_node, node) {
struct V_58 V_59 = {} ;
T_4 V_3 ;
V_3 = F_16 ( V_2 , V_11 , V_55 ) ;
if ( V_3 == 0xffffffff )
continue;
if ( ! F_31 ( V_55 , V_2 ) )
continue;
F_7 ( & V_2 -> V_35 , L_24 ,
V_55 -> V_57 ) ;
if ( F_25 ( V_55 , L_25 ) )
V_62 = true ;
if ( ! F_27 ( V_2 , V_55 , V_3 ,
V_59 . type , sizeof( V_59 . type ) ) ) {
continue;
}
V_59 . V_3 = V_3 ;
V_59 . V_67 = F_32 ( V_55 , 0 ) ;
V_59 . V_66 = F_33 ( V_55 ) ;
V_61 = F_21 ( V_2 , & V_59 ) ;
if ( ! V_61 ) {
F_4 ( & V_2 -> V_35 , L_26
L_27 , V_55 -> V_57 ) ;
F_34 ( V_55 ) ;
continue;
}
}
F_22 ( V_2 , V_11 , V_62 ) ;
}
static int F_35 ( struct V_51 * V_35 )
{
struct V_10 * V_11 = V_35 -> V_35 . V_68 ;
struct V_54 * V_69 = NULL ;
struct V_1 * V_44 ;
const char * V_70 ;
int V_12 ;
if ( V_11 == NULL )
return - V_34 ;
V_44 = F_36 ( V_11 ) ;
switch( F_37 ( V_11 ) ) {
case V_71 :
V_69 = F_38 ( F_39 ( V_11 ) ) ;
if ( V_69 == NULL )
return - V_34 ;
V_70 = V_69 -> V_53 ;
break;
case V_72 :
V_70 = L_28 ;
break;
case V_73 :
V_70 = L_29 ;
break;
default:
return - V_34 ;
}
snprintf ( V_44 -> V_53 , sizeof( V_44 -> V_53 ) , L_30 , V_70 ,
F_40 ( V_11 ) ) ;
F_34 ( V_69 ) ;
F_15 ( V_35 , V_44 ) ;
V_44 -> V_74 = & V_75 ;
F_41 ( V_44 , V_11 ) ;
V_44 -> V_35 . V_69 = & V_35 -> V_35 ;
V_44 -> V_35 . V_66 = V_35 -> V_35 . V_66 ;
V_12 = F_42 ( V_44 ) ;
if ( V_12 ) {
F_14 ( V_76 L_31
L_32 , V_44 -> V_53 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
}
F_14 ( V_77 L_33 , V_44 -> V_53 ) ;
F_29 ( V_44 , V_11 ) ;
return V_12 ;
}
