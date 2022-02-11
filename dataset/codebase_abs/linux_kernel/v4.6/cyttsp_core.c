static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , void * V_5 )
{
int error ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
error = V_2 -> V_8 -> V_9 ( V_2 -> V_10 , V_2 -> V_11 , V_3 ,
V_4 , V_5 ) ;
if ( ! error )
return 0 ;
F_2 ( V_12 ) ;
}
return - V_13 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , void * V_5 )
{
int error ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
error = V_2 -> V_8 -> V_14 ( V_2 -> V_10 , V_2 -> V_11 , V_3 ,
V_4 , V_5 ) ;
if ( ! error )
return 0 ;
F_2 ( V_12 ) ;
}
return - V_13 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_15 )
{
return F_3 ( V_2 , V_16 , sizeof( V_15 ) , & V_15 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
return F_4 ( V_2 ,
V_2 -> V_18 . V_19 ^ V_20 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_21 , 0 , sizeof( V_2 -> V_21 ) ) ;
V_2 -> V_21 . V_22 = 0x10 ;
return F_1 ( V_2 , V_16 ,
sizeof( V_2 -> V_21 ) , & V_2 -> V_21 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int error ;
T_1 V_23 [ sizeof( V_24 ) ] ;
memcpy ( V_23 , V_24 , sizeof( V_24 ) ) ;
if ( V_2 -> V_25 )
memcpy ( & V_23 [ sizeof( V_24 ) - V_26 ] ,
V_2 -> V_25 , V_26 ) ;
error = F_3 ( V_2 , V_16 ,
sizeof( V_23 ) , V_23 ) ;
if ( error )
return error ;
F_2 ( V_12 ) ;
error = F_6 ( V_2 ) ;
if ( error )
return error ;
if ( F_8 ( V_2 -> V_21 . V_22 ) )
return - V_13 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_27 ) ;
if ( error )
return error ;
error = F_1 ( V_2 , V_16 ,
sizeof( V_2 -> V_18 ) , & V_2 -> V_18 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
return V_2 -> V_18 . V_28 == V_29 ? - V_13 : 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int error ;
memset ( & V_2 -> V_30 , 0 , sizeof( V_2 -> V_30 ) ) ;
error = F_4 ( V_2 , V_31 ) ;
if ( error )
return error ;
F_2 ( V_12 ) ;
error = F_1 ( V_2 , V_16 , sizeof( V_2 -> V_30 ) ,
& V_2 -> V_30 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
if ( ! V_2 -> V_30 . V_32 && ! V_2 -> V_30 . V_33 )
return - V_13 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
if ( V_2 -> V_35 != V_36 ||
V_2 -> V_37 != V_38 ||
V_2 -> V_39 != V_40 ) {
T_1 V_41 [] = {
V_2 -> V_35 ,
V_2 -> V_37 ,
V_2 -> V_39
} ;
V_34 = F_3 ( V_2 , V_42 ,
sizeof( V_41 ) , V_41 ) ;
F_2 ( V_12 ) ;
}
return V_34 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 ) {
F_13 ( V_2 -> V_43 , 1 ) ;
F_2 ( V_12 ) ;
F_13 ( V_2 -> V_43 , 0 ) ;
F_2 ( V_12 ) ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
int V_34 ;
F_15 ( & V_2 -> V_45 ) ;
V_2 -> V_46 = V_47 ;
F_16 ( V_2 -> V_48 ) ;
V_34 = F_4 ( V_2 , V_49 ) ;
if ( V_34 )
goto V_50;
V_44 = F_17 ( & V_2 -> V_45 ,
F_18 ( V_12 * V_51 ) ) ;
V_34 = V_44 ? 0 : - V_13 ;
V_50:
V_2 -> V_46 = V_52 ;
F_19 ( V_2 -> V_48 ) ;
return V_34 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_53 = V_2 -> V_28 ;
return F_3 ( V_2 , V_54 ,
sizeof( V_53 ) , & V_53 ) ;
}
static void F_21 ( struct V_55 * V_18 , int * V_56 )
{
V_56 [ 0 ] = V_18 -> V_57 >> 4 ;
V_56 [ 1 ] = V_18 -> V_57 & 0xF ;
V_56 [ 2 ] = V_18 -> V_58 >> 4 ;
V_56 [ 3 ] = V_18 -> V_58 & 0xF ;
}
static const struct V_59 * F_22 ( struct V_55 * V_18 ,
int V_60 )
{
switch ( V_60 ) {
case 0 :
return & V_18 -> V_61 ;
case 1 :
return & V_18 -> V_62 ;
case 2 :
return & V_18 -> V_63 ;
case 3 :
return & V_18 -> V_64 ;
default:
return NULL ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_55 * V_18 = & V_2 -> V_18 ;
struct V_65 * V_66 = V_2 -> V_66 ;
int V_67 = F_24 ( V_18 -> V_68 ) ;
const struct V_59 * V_69 ;
int V_56 [ V_70 ] ;
int V_71 ;
F_25 ( V_72 , V_70 ) ;
if ( F_26 ( V_18 -> V_68 ) == 1 ) {
V_67 = 0 ;
F_27 ( V_2 -> V_10 , L_1 , V_73 ) ;
} else if ( V_67 > V_74 ) {
V_67 = 0 ;
F_27 ( V_2 -> V_10 , L_2 , V_73 ) ;
} else if ( F_28 ( V_18 -> V_75 ) ) {
V_67 = 0 ;
F_27 ( V_2 -> V_10 , L_3 , V_73 ) ;
}
F_21 ( V_18 , V_56 ) ;
F_29 ( V_72 , V_70 ) ;
for ( V_71 = 0 ; V_71 < V_67 ; V_71 ++ ) {
V_69 = F_22 ( V_18 , V_71 ) ;
F_30 ( V_66 , V_56 [ V_71 ] ) ;
F_31 ( V_66 , V_76 , true ) ;
F_32 ( V_66 , V_77 , F_33 ( V_69 -> V_78 ) ) ;
F_32 ( V_66 , V_79 , F_33 ( V_69 -> V_80 ) ) ;
F_32 ( V_66 , V_81 , V_69 -> V_82 ) ;
F_34 ( V_56 [ V_71 ] , V_72 ) ;
}
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
if ( F_35 ( V_71 , V_72 ) )
continue;
F_30 ( V_66 , V_71 ) ;
F_31 ( V_66 , V_76 , false ) ;
}
F_36 ( V_66 ) ;
}
static T_2 F_37 ( int V_48 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
int error ;
if ( F_38 ( V_2 -> V_46 == V_47 ) ) {
F_39 ( & V_2 -> V_45 ) ;
goto V_50;
}
error = F_1 ( V_2 , V_16 ,
sizeof( struct V_55 ) , & V_2 -> V_18 ) ;
if ( error )
goto V_50;
error = F_5 ( V_2 ) ;
if ( error )
goto V_50;
if ( F_38 ( V_2 -> V_46 == V_52 ) )
goto V_50;
if ( F_8 ( V_2 -> V_18 . V_75 ) ) {
error = F_7 ( V_2 ) ;
if ( error ) {
F_40 ( V_2 -> V_10 ,
L_4 ,
error ) ;
V_2 -> V_46 = V_52 ;
}
} else {
F_23 ( V_2 ) ;
}
V_50:
return V_84 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int error ;
error = F_14 ( V_2 ) ;
if ( error )
return error ;
error = F_6 ( V_2 ) ;
if ( error )
return error ;
if ( F_8 ( V_2 -> V_21 . V_22 ) &&
F_42 ( V_2 -> V_21 . V_22 ) ) {
error = F_7 ( V_2 ) ;
if ( error )
return error ;
}
if ( F_43 ( V_2 -> V_21 . V_85 ) != V_27 ||
F_44 ( V_2 -> V_21 . V_22 ) ) {
return - V_86 ;
}
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_11 ( V_2 ) ;
if ( error )
return error ;
error = F_9 ( V_2 ) ;
if ( error )
return error ;
error = F_20 ( V_2 ) ;
if ( error )
return error ;
V_2 -> V_46 = V_87 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int error ;
error = F_1 ( V_2 , V_16 ,
sizeof( V_2 -> V_18 ) , & V_2 -> V_18 ) ;
if ( error )
return error ;
if ( F_43 ( V_2 -> V_18 . V_19 ) )
return - V_13 ;
F_16 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_88 ) ;
if ( error )
return error ;
F_19 ( V_2 -> V_48 ) ;
return 0 ;
}
static int T_3 F_47 ( struct V_89 * V_10 )
{
struct V_1 * V_2 = F_48 ( V_10 ) ;
int V_34 = 0 ;
F_49 ( & V_2 -> V_66 -> V_90 ) ;
if ( V_2 -> V_66 -> V_91 ) {
V_34 = F_46 ( V_2 ) ;
if ( V_34 == 0 )
V_2 -> V_92 = true ;
}
F_50 ( & V_2 -> V_66 -> V_90 ) ;
return V_34 ;
}
static int T_3 F_51 ( struct V_89 * V_10 )
{
struct V_1 * V_2 = F_48 ( V_10 ) ;
F_49 ( & V_2 -> V_66 -> V_90 ) ;
if ( V_2 -> V_66 -> V_91 )
F_45 ( V_2 ) ;
V_2 -> V_92 = false ;
F_50 ( & V_2 -> V_66 -> V_90 ) ;
return 0 ;
}
static int F_52 ( struct V_65 * V_10 )
{
struct V_1 * V_2 = F_53 ( V_10 ) ;
int V_34 = 0 ;
if ( ! V_2 -> V_92 )
V_34 = F_45 ( V_2 ) ;
return V_34 ;
}
static void F_54 ( struct V_65 * V_10 )
{
struct V_1 * V_2 = F_53 ( V_10 ) ;
if ( ! V_2 -> V_92 )
F_46 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_89 * V_10 = V_2 -> V_10 ;
T_4 V_93 ;
int V_94 ;
V_2 -> V_25 = F_56 ( V_10 , V_26 , V_95 ) ;
if ( ! V_2 -> V_25 )
return - V_96 ;
V_2 -> V_17 = false ;
V_2 -> V_28 = V_29 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = V_40 ;
V_94 = F_57 ( V_10 , L_5 ,
V_2 -> V_25 , V_26 ) ;
if ( V_94 ) {
F_40 ( V_10 ,
L_6 ) ;
return V_94 ;
}
V_2 -> V_17 = F_58 ( V_10 , L_7 ) ;
if ( ! F_59 ( V_10 , L_8 , & V_93 ) ) {
if ( V_93 > 15 ) {
F_40 ( V_10 , L_9 ,
V_93 ) ;
return - V_97 ;
}
V_2 -> V_28 &= ~ V_98 ;
V_2 -> V_28 |= V_93 ;
}
if ( ! F_59 ( V_10 , L_10 , & V_93 ) ) {
if ( V_93 > 255 ) {
F_40 ( V_10 , L_11 ,
V_93 ) ;
return - V_97 ;
}
V_2 -> V_35 = V_93 ;
}
if ( ! F_59 ( V_10 , L_12 , & V_93 ) ) {
if ( V_93 > 2550 ) {
F_40 ( V_10 , L_13 ,
V_93 ) ;
return - V_97 ;
}
V_2 -> V_39 = V_93 / 10 ;
}
if ( ! F_59 ( V_10 , L_14 , & V_93 ) ) {
if ( V_93 > 2550 ) {
F_40 ( V_10 , L_15 ,
V_93 ) ;
return - V_97 ;
}
V_2 -> V_37 = V_93 / 10 ;
}
return 0 ;
}
struct V_1 * F_60 ( const struct V_99 * V_8 ,
struct V_89 * V_10 , int V_48 , T_5 V_100 )
{
struct V_1 * V_2 ;
struct V_65 * V_65 ;
int error ;
V_2 = F_56 ( V_10 , sizeof( * V_2 ) + V_100 , V_95 ) ;
if ( ! V_2 )
return F_61 ( - V_96 ) ;
V_65 = F_62 ( V_10 ) ;
if ( ! V_65 )
return F_61 ( - V_96 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_43 = F_63 ( V_10 , L_16 , V_101 ) ;
if ( F_64 ( V_2 -> V_43 ) ) {
error = F_65 ( V_2 -> V_43 ) ;
F_40 ( V_10 , L_17 , error ) ;
return F_61 ( error ) ;
}
error = F_55 ( V_2 ) ;
if ( error )
return F_61 ( error ) ;
F_66 ( & V_2 -> V_45 ) ;
snprintf ( V_2 -> V_102 , sizeof( V_2 -> V_102 ) , L_18 , F_67 ( V_10 ) ) ;
V_65 -> V_103 = L_19 ;
V_65 -> V_102 = V_2 -> V_102 ;
V_65 -> V_104 . V_105 = V_8 -> V_105 ;
V_65 -> V_10 . V_106 = V_2 -> V_10 ;
V_65 -> V_107 = F_52 ;
V_65 -> V_108 = F_54 ;
F_68 ( V_65 , V_2 ) ;
F_69 ( V_65 , V_109 , V_77 ) ;
F_69 ( V_65 , V_109 , V_79 ) ;
F_70 ( V_65 , true ) ;
error = F_71 ( V_65 , V_70 , 0 ) ;
if ( error ) {
F_40 ( V_10 , L_20 ) ;
return F_61 ( error ) ;
}
error = F_72 ( V_10 , V_2 -> V_48 , NULL , F_37 ,
V_110 | V_111 ,
L_21 , V_2 ) ;
if ( error ) {
F_40 ( V_2 -> V_10 , L_22 ,
V_2 -> V_48 , error ) ;
return F_61 ( error ) ;
}
F_19 ( V_2 -> V_48 ) ;
F_12 ( V_2 ) ;
error = F_41 ( V_2 ) ;
if ( error )
return F_61 ( error ) ;
error = F_73 ( V_65 ) ;
if ( error ) {
F_40 ( V_2 -> V_10 , L_23 ,
error ) ;
return F_61 ( error ) ;
}
return V_2 ;
}
