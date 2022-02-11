static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 , V_4 , V_1 -> V_5 [ 1 ] & 0x04 ) ;
F_2 ( V_2 , V_6 , V_1 -> V_5 [ 1 ] & 0x01 ) ;
F_2 ( V_2 , V_7 , V_1 -> V_5 [ 1 ] & 0x02 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_8 , V_9 ;
unsigned int V_10 ;
V_10 = V_1 -> V_5 [ 6 ] ;
V_8 = ( V_11 ) ( F_4 ( ( V_12 * ) & V_1 -> V_5 [ 2 ] ) << 3 ) >> 7 ;
V_9 = ( V_11 ) ( F_4 ( ( V_12 * ) & V_1 -> V_5 [ 4 ] ) << 3 ) >> 7 ;
if ( V_10 > 0 ) {
F_5 ( V_2 , V_13 , V_8 ) ;
F_5 ( V_2 , V_14 , - V_9 ) ;
}
F_6 ( V_2 , V_15 , V_10 ) ;
F_1 ( V_1 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
unsigned int V_16 , V_17 ;
unsigned int V_8 , V_9 ;
unsigned int V_10 , V_18 ;
V_10 = V_1 -> V_5 [ 6 ] ;
V_8 = F_4 ( ( V_12 * ) & V_1 -> V_5 [ 2 ] ) ;
V_9 = F_4 ( ( V_12 * ) & V_1 -> V_5 [ 4 ] ) ;
V_18 = V_1 -> V_5 [ 0 ] & 0x0f ;
if ( V_10 > 0 ) {
V_16 = 1 ;
V_17 = 5 ;
switch ( V_18 ) {
case 0 ... 1 :
V_16 = 2 + V_18 ;
break;
case 2 :
break;
case 4 ... 15 :
V_17 = V_18 ;
break;
}
} else {
V_16 = 0 ;
V_17 = 0 ;
}
if ( V_10 > 30 )
F_2 ( V_2 , V_19 , 1 ) ;
if ( V_10 < 25 )
F_2 ( V_2 , V_19 , 0 ) ;
if ( V_16 > 0 ) {
F_6 ( V_2 , V_20 , V_8 ) ;
F_6 ( V_2 , V_21 ,
V_22 + V_23 - V_9 ) ;
}
F_6 ( V_2 , V_15 , V_10 ) ;
F_6 ( V_2 , V_24 , V_17 ) ;
F_2 ( V_2 , V_25 , V_16 == 1 ) ;
F_2 ( V_2 , V_26 , V_16 == 2 ) ;
F_2 ( V_2 , V_27 , V_16 == 3 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_28 & V_29 )
F_2 ( V_2 , V_7 , V_1 -> V_5 [ 1 ] & 0x08 ) ;
F_7 ( V_2 ) ;
}
static void F_9 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = V_30 -> V_31 ;
int error ;
switch ( V_30 -> V_32 ) {
case 0 :
F_10 ( V_1 -> V_33 ) ;
break;
case - V_34 :
case - V_35 :
case - V_36 :
return;
default:
goto V_37;
break;
}
if ( V_1 -> V_28 & V_38 )
F_3 ( V_1 ) ;
else
F_8 ( V_1 ) ;
V_37:
error = F_11 ( V_30 , V_39 ) ;
if ( error && error != - V_40 )
F_12 ( & V_1 -> V_41 -> V_42 ,
L_1 ,
V_43 , error ) ;
}
static struct V_44 *
F_13 ( struct V_45 * V_46 )
{
struct V_44 * V_47 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_46 -> V_49 . V_50 ; ++ V_48 ) {
V_47 = & V_46 -> V_47 [ V_48 ] . V_49 ;
if ( F_14 ( V_47 ) ) {
return V_47 ;
}
}
return NULL ;
}
static int F_15 ( struct V_2 * V_42 )
{
struct V_1 * V_1 = F_16 ( V_42 ) ;
int V_51 ;
V_51 = F_17 ( V_1 -> V_41 ) ;
if ( V_51 ) {
F_12 ( & V_1 -> V_41 -> V_42 ,
L_2 ,
V_43 , V_51 ) ;
return V_51 ;
}
V_51 = F_11 ( V_1 -> V_30 , V_52 ) ;
if ( V_51 ) {
F_12 ( & V_1 -> V_41 -> V_42 ,
L_3 ,
V_43 , V_51 ) ;
V_51 = - V_53 ;
goto V_54;
}
V_1 -> V_41 -> V_55 = 1 ;
V_54:
F_18 ( V_1 -> V_41 ) ;
return V_51 ;
}
static void F_19 ( struct V_2 * V_42 )
{
struct V_1 * V_1 = F_16 ( V_42 ) ;
int V_56 ;
V_56 = F_17 ( V_1 -> V_41 ) ;
F_20 ( V_1 -> V_30 ) ;
V_1 -> V_41 -> V_55 = 0 ;
if ( ! V_56 )
F_18 ( V_1 -> V_41 ) ;
}
static int F_21 ( struct V_57 * V_41 ,
const struct V_58 * V_59 )
{
struct V_60 * V_33 = F_22 ( V_41 ) ;
struct V_44 * V_61 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
unsigned int V_62 = V_41 -> V_63 -> V_49 . V_64 ;
unsigned int V_65 = F_23 ( V_41 -> V_66 , 1U ) ;
int error ;
error = F_24 ( V_33 , V_62 , V_65 ) ;
if ( error ) {
F_12 ( & V_33 -> V_42 ,
L_4 ,
V_65 , error ) ;
return error ;
}
V_61 = F_13 ( V_41 -> V_63 ) ;
if ( ! V_61 )
return - V_67 ;
V_1 = F_25 ( sizeof( * V_1 ) , V_52 ) ;
V_2 = F_26 () ;
if ( ! V_1 || ! V_2 ) {
error = - V_68 ;
goto V_69;
}
V_1 -> V_33 = V_33 ;
V_1 -> V_41 = V_41 ;
V_1 -> V_3 = V_2 ;
V_1 -> V_28 = V_59 -> V_70 ;
if ( V_1 -> V_28 & V_71 ) {
V_1 -> V_28 |= V_62 == 1 ?
V_38 : V_72 ;
}
V_1 -> V_30 = F_27 ( 0 , V_52 ) ;
if ( ! V_1 -> V_30 ) {
error = - V_68 ;
goto V_69;
}
V_1 -> V_5 = F_28 ( V_33 , V_73 , V_52 ,
& V_1 -> V_30 -> V_74 ) ;
if ( ! V_1 -> V_5 ) {
error = - V_68 ;
goto V_75;
}
F_29 ( V_1 -> V_30 , V_33 ,
F_30 ( V_33 , V_61 -> V_76 ) ,
V_1 -> V_5 , V_73 ,
F_9 , V_1 ,
V_61 -> V_77 ) ;
V_1 -> V_30 -> V_78 |= V_79 ;
if ( V_33 -> V_80 )
F_31 ( V_1 -> V_81 , V_33 -> V_80 ,
sizeof( V_1 -> V_81 ) ) ;
if ( V_33 -> V_82 ) {
if ( V_33 -> V_80 )
F_32 ( V_1 -> V_81 , L_5 , sizeof( V_1 -> V_81 ) ) ;
F_32 ( V_1 -> V_81 , V_33 -> V_82 , sizeof( V_1 -> V_81 ) ) ;
}
if ( ! strlen ( V_1 -> V_81 ) )
snprintf ( V_1 -> V_81 , sizeof( V_1 -> V_81 ) ,
L_6 ,
F_33 ( V_33 -> V_83 . V_84 ) ,
F_33 ( V_33 -> V_83 . V_85 ) ) ;
if ( V_1 -> V_28 & V_38 )
F_32 ( V_1 -> V_81 , L_7 , sizeof( V_1 -> V_81 ) ) ;
F_34 ( V_33 , V_1 -> V_86 , sizeof( V_1 -> V_86 ) ) ;
F_32 ( V_1 -> V_86 , L_8 , sizeof( V_1 -> V_86 ) ) ;
V_2 -> V_81 = V_1 -> V_81 ;
V_2 -> V_86 = V_1 -> V_86 ;
F_35 ( V_33 , & V_2 -> V_59 ) ;
V_2 -> V_42 . V_87 = & V_1 -> V_41 -> V_42 ;
if ( ! ( V_1 -> V_28 & V_88 ) ) {
V_2 -> V_89 = F_15 ;
V_2 -> V_90 = F_19 ;
}
F_36 ( V_2 , V_1 ) ;
F_37 ( V_91 , V_2 -> V_92 ) ;
F_37 ( V_93 , V_2 -> V_92 ) ;
if ( V_1 -> V_28 & V_38 ) {
F_37 ( V_94 , V_2 -> V_92 ) ;
F_37 ( V_13 , V_2 -> V_95 ) ;
F_37 ( V_14 , V_2 -> V_95 ) ;
F_37 ( V_96 , V_2 -> V_97 ) ;
F_38 ( V_2 , V_15 , 0 , 127 , 0 , 0 ) ;
} else {
F_38 ( V_2 , V_20 ,
V_98 , V_99 , 0 , 0 ) ;
F_38 ( V_2 , V_21 ,
V_23 , V_22 , 0 , 0 ) ;
F_38 ( V_2 , V_15 , 0 , 255 , 0 , 0 ) ;
F_38 ( V_2 , V_24 , 0 , 15 , 0 , 0 ) ;
F_37 ( V_19 , V_2 -> V_100 ) ;
F_37 ( V_25 , V_2 -> V_100 ) ;
F_37 ( V_26 , V_2 -> V_100 ) ;
F_37 ( V_27 , V_2 -> V_100 ) ;
}
if ( V_1 -> V_28 & V_101 )
F_37 ( V_102 , V_2 -> V_97 ) ;
else
F_37 ( V_103 , V_2 -> V_97 ) ;
F_37 ( V_4 , V_2 -> V_100 ) ;
F_37 ( V_6 , V_2 -> V_100 ) ;
F_37 ( V_7 , V_2 -> V_100 ) ;
F_39 ( V_41 , V_1 ) ;
if ( V_1 -> V_28 & V_88 ) {
error = F_15 ( V_2 ) ;
if ( error )
goto V_104;
}
error = F_40 ( V_2 ) ;
if ( error ) {
F_12 ( & V_33 -> V_42 ,
L_9 ,
error ) ;
goto V_105;
}
return 0 ;
V_105:
if ( V_1 -> V_28 & V_88 )
F_19 ( V_1 -> V_3 ) ;
V_104:
F_41 ( V_33 , V_73 , V_1 -> V_5 ,
V_1 -> V_30 -> V_74 ) ;
V_75:
F_42 ( V_1 -> V_30 ) ;
V_69:
F_43 ( V_2 ) ;
F_44 ( V_1 ) ;
F_39 ( V_41 , NULL ) ;
return error ;
}
static void F_45 ( struct V_57 * V_41 )
{
struct V_1 * V_1 = F_46 ( V_41 ) ;
struct V_60 * V_33 = F_22 ( V_41 ) ;
if ( V_1 -> V_28 & V_88 )
F_19 ( V_1 -> V_3 ) ;
F_47 ( V_1 -> V_3 ) ;
F_41 ( V_33 , V_73 , V_1 -> V_5 ,
V_1 -> V_30 -> V_74 ) ;
F_42 ( V_1 -> V_30 ) ;
F_44 ( V_1 ) ;
F_39 ( V_41 , NULL ) ;
}
static int F_48 ( struct V_57 * V_41 , T_1 V_106 )
{
struct V_1 * V_1 = F_46 ( V_41 ) ;
struct V_2 * V_2 = V_1 -> V_3 ;
F_49 ( & V_2 -> V_107 ) ;
F_20 ( V_1 -> V_30 ) ;
F_50 ( & V_2 -> V_107 ) ;
return 0 ;
}
static int F_51 ( struct V_57 * V_41 )
{
struct V_1 * V_1 = F_46 ( V_41 ) ;
struct V_2 * V_2 = V_1 -> V_3 ;
int V_51 = 0 ;
F_49 ( & V_2 -> V_107 ) ;
if ( ( V_2 -> V_108 || ( V_1 -> V_28 & V_88 ) ) &&
F_11 ( V_1 -> V_30 , V_109 ) < 0 ) {
V_51 = - V_53 ;
}
F_50 ( & V_2 -> V_107 ) ;
return V_51 ;
}
static int F_52 ( struct V_57 * V_41 )
{
struct V_1 * V_1 = F_46 ( V_41 ) ;
struct V_2 * V_2 = V_1 -> V_3 ;
F_49 ( & V_2 -> V_107 ) ;
F_20 ( V_1 -> V_30 ) ;
return 0 ;
}
static int F_53 ( struct V_57 * V_41 )
{
struct V_1 * V_1 = F_46 ( V_41 ) ;
struct V_2 * V_2 = V_1 -> V_3 ;
int V_51 = 0 ;
if ( ( V_2 -> V_108 || ( V_1 -> V_28 & V_88 ) ) &&
F_11 ( V_1 -> V_30 , V_109 ) < 0 ) {
V_51 = - V_53 ;
}
F_50 ( & V_2 -> V_107 ) ;
return V_51 ;
}
static int F_54 ( struct V_57 * V_41 )
{
return F_51 ( V_41 ) ;
}
