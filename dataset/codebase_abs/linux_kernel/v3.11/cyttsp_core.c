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
if ( V_2 -> V_17 -> V_18 )
return F_4 ( V_2 ,
V_2 -> V_19 . V_20 ^ V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_22 , 0 , sizeof( V_2 -> V_22 ) ) ;
V_2 -> V_22 . V_23 = 0x10 ;
return F_1 ( V_2 , V_16 ,
sizeof( V_2 -> V_22 ) , & V_2 -> V_22 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int error ;
T_1 V_24 [ sizeof( V_25 ) ] ;
memcpy ( V_24 , V_25 , sizeof( V_25 ) ) ;
if ( V_2 -> V_17 -> V_26 )
memcpy ( & V_24 [ sizeof( V_25 ) - V_27 ] ,
V_2 -> V_17 -> V_26 , V_27 ) ;
error = F_3 ( V_2 , V_16 ,
sizeof( V_24 ) , V_24 ) ;
if ( error )
return error ;
F_2 ( V_12 ) ;
error = F_6 ( V_2 ) ;
if ( error )
return error ;
if ( F_8 ( V_2 -> V_22 . V_23 ) )
return - V_13 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_28 ) ;
if ( error )
return error ;
error = F_1 ( V_2 , V_16 ,
sizeof( V_2 -> V_19 ) , & V_2 -> V_19 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
return V_2 -> V_19 . V_29 == V_30 ? - V_13 : 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int error ;
memset ( & V_2 -> V_31 , 0 , sizeof( V_2 -> V_31 ) ) ;
error = F_4 ( V_2 , V_32 ) ;
if ( error )
return error ;
F_2 ( V_12 ) ;
error = F_1 ( V_2 , V_16 , sizeof( V_2 -> V_31 ) ,
& V_2 -> V_31 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
if ( ! V_2 -> V_31 . V_33 && ! V_2 -> V_31 . V_34 )
return - V_13 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
if ( V_2 -> V_17 -> V_36 != V_37 ||
V_2 -> V_17 -> V_38 != V_39 ||
V_2 -> V_17 -> V_40 != V_41 ) {
T_1 V_42 [] = {
V_2 -> V_17 -> V_36 ,
V_2 -> V_17 -> V_38 ,
V_2 -> V_17 -> V_40
} ;
V_35 = F_3 ( V_2 , V_43 ,
sizeof( V_42 ) , V_42 ) ;
F_2 ( V_12 ) ;
}
return V_35 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
int V_35 ;
F_13 ( V_2 -> V_45 ) ;
V_2 -> V_46 = V_47 ;
F_14 ( V_2 -> V_48 ) ;
V_35 = F_4 ( V_2 , V_49 ) ;
if ( V_35 )
goto V_50;
V_44 = F_15 ( & V_2 -> V_45 ,
F_16 ( V_12 * V_51 ) ) ;
V_35 = V_44 ? 0 : - V_13 ;
V_50:
V_2 -> V_46 = V_52 ;
F_17 ( V_2 -> V_48 ) ;
return V_35 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_53 = V_2 -> V_17 -> V_29 ;
return F_3 ( V_2 , V_54 ,
sizeof( V_53 ) , & V_53 ) ;
}
static void F_19 ( struct V_55 * V_19 , int * V_56 )
{
V_56 [ 0 ] = V_19 -> V_57 >> 4 ;
V_56 [ 1 ] = V_19 -> V_57 & 0xF ;
V_56 [ 2 ] = V_19 -> V_58 >> 4 ;
V_56 [ 3 ] = V_19 -> V_58 & 0xF ;
}
static const struct V_59 * F_20 ( struct V_55 * V_19 ,
int V_60 )
{
switch ( V_60 ) {
case 0 :
return & V_19 -> V_61 ;
case 1 :
return & V_19 -> V_62 ;
case 2 :
return & V_19 -> V_63 ;
case 3 :
return & V_19 -> V_64 ;
default:
return NULL ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_55 * V_19 = & V_2 -> V_19 ;
struct V_65 * V_66 = V_2 -> V_66 ;
int V_67 = F_22 ( V_19 -> V_68 ) ;
const struct V_59 * V_69 ;
int V_56 [ V_70 ] ;
int V_71 ;
F_23 ( V_72 , V_70 ) ;
if ( F_24 ( V_19 -> V_68 ) == 1 ) {
V_67 = 0 ;
F_25 ( V_2 -> V_10 , L_1 , V_73 ) ;
} else if ( V_67 > V_74 ) {
V_67 = 0 ;
F_25 ( V_2 -> V_10 , L_2 , V_73 ) ;
} else if ( F_26 ( V_19 -> V_75 ) ) {
V_67 = 0 ;
F_25 ( V_2 -> V_10 , L_3 , V_73 ) ;
}
F_19 ( V_19 , V_56 ) ;
F_27 ( V_72 , V_70 ) ;
for ( V_71 = 0 ; V_71 < V_67 ; V_71 ++ ) {
V_69 = F_20 ( V_19 , V_71 ) ;
F_28 ( V_66 , V_56 [ V_71 ] ) ;
F_29 ( V_66 , V_76 , true ) ;
F_30 ( V_66 , V_77 , F_31 ( V_69 -> V_78 ) ) ;
F_30 ( V_66 , V_79 , F_31 ( V_69 -> V_80 ) ) ;
F_30 ( V_66 , V_81 , V_69 -> V_82 ) ;
F_32 ( V_56 [ V_71 ] , V_72 ) ;
}
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
if ( F_33 ( V_71 , V_72 ) )
continue;
F_28 ( V_66 , V_71 ) ;
F_29 ( V_66 , V_76 , false ) ;
}
F_34 ( V_66 ) ;
}
static T_2 F_35 ( int V_48 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
int error ;
if ( F_36 ( V_2 -> V_46 == V_47 ) ) {
F_37 ( & V_2 -> V_45 ) ;
goto V_50;
}
error = F_1 ( V_2 , V_16 ,
sizeof( struct V_55 ) , & V_2 -> V_19 ) ;
if ( error )
goto V_50;
error = F_5 ( V_2 ) ;
if ( error )
goto V_50;
if ( F_36 ( V_2 -> V_46 == V_52 ) )
goto V_50;
if ( F_8 ( V_2 -> V_19 . V_75 ) ) {
error = F_7 ( V_2 ) ;
if ( error ) {
F_38 ( V_2 -> V_10 ,
L_4 ,
error ) ;
V_2 -> V_46 = V_52 ;
}
} else {
F_21 ( V_2 ) ;
}
V_50:
return V_84 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int error ;
error = F_12 ( V_2 ) ;
if ( error )
return error ;
error = F_6 ( V_2 ) ;
if ( error )
return error ;
if ( F_8 ( V_2 -> V_22 . V_23 ) &&
F_40 ( V_2 -> V_22 . V_23 ) ) {
error = F_7 ( V_2 ) ;
if ( error )
return error ;
}
if ( F_41 ( V_2 -> V_22 . V_85 ) != V_28 ||
F_42 ( V_2 -> V_22 . V_23 ) ) {
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
error = F_18 ( V_2 ) ;
if ( error )
return error ;
V_2 -> V_46 = V_87 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int error ;
error = F_1 ( V_2 , V_16 ,
sizeof( V_2 -> V_19 ) , & V_2 -> V_19 ) ;
if ( error )
return error ;
if ( F_41 ( V_2 -> V_19 . V_20 ) )
return - V_13 ;
F_14 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_88 ) ;
if ( error )
return error ;
F_17 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_45 ( struct V_89 * V_10 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
int V_35 = 0 ;
F_47 ( & V_2 -> V_66 -> V_90 ) ;
if ( V_2 -> V_66 -> V_91 ) {
V_35 = F_44 ( V_2 ) ;
if ( V_35 == 0 )
V_2 -> V_92 = true ;
}
F_48 ( & V_2 -> V_66 -> V_90 ) ;
return V_35 ;
}
static int F_49 ( struct V_89 * V_10 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
F_47 ( & V_2 -> V_66 -> V_90 ) ;
if ( V_2 -> V_66 -> V_91 )
F_43 ( V_2 ) ;
V_2 -> V_92 = false ;
F_48 ( & V_2 -> V_66 -> V_90 ) ;
return 0 ;
}
static int F_50 ( struct V_65 * V_10 )
{
struct V_1 * V_2 = F_51 ( V_10 ) ;
int V_35 = 0 ;
if ( ! V_2 -> V_92 )
V_35 = F_43 ( V_2 ) ;
return V_35 ;
}
static void F_52 ( struct V_65 * V_10 )
{
struct V_1 * V_2 = F_51 ( V_10 ) ;
if ( ! V_2 -> V_92 )
F_44 ( V_2 ) ;
}
struct V_1 * F_53 ( const struct V_93 * V_8 ,
struct V_89 * V_10 , int V_48 , T_3 V_94 )
{
const struct V_95 * V_17 = V_10 -> V_96 ;
struct V_1 * V_2 ;
struct V_65 * V_65 ;
int error ;
if ( ! V_17 || ! V_17 -> V_97 || V_48 <= 0 ) {
error = - V_98 ;
goto V_99;
}
V_2 = F_54 ( sizeof( * V_2 ) + V_94 , V_100 ) ;
V_65 = F_55 () ;
if ( ! V_2 || ! V_65 ) {
error = - V_101 ;
goto V_102;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_17 = V_10 -> V_96 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_48 = V_48 ;
F_56 ( & V_2 -> V_45 ) ;
snprintf ( V_2 -> V_103 , sizeof( V_2 -> V_103 ) , L_5 , F_57 ( V_10 ) ) ;
if ( V_17 -> V_104 ) {
error = V_17 -> V_104 () ;
if ( error ) {
F_38 ( V_2 -> V_10 , L_6 ,
error ) ;
goto V_102;
}
}
V_65 -> V_97 = V_17 -> V_97 ;
V_65 -> V_103 = V_2 -> V_103 ;
V_65 -> V_105 . V_106 = V_8 -> V_106 ;
V_65 -> V_10 . V_107 = V_2 -> V_10 ;
V_65 -> V_108 = F_50 ;
V_65 -> V_109 = F_52 ;
F_58 ( V_65 , V_2 ) ;
F_32 ( V_110 , V_65 -> V_111 ) ;
F_59 ( V_65 , V_77 ,
0 , V_17 -> V_112 , 0 , 0 ) ;
F_59 ( V_65 , V_79 ,
0 , V_17 -> V_113 , 0 , 0 ) ;
F_59 ( V_65 , V_81 ,
0 , V_114 , 0 , 0 ) ;
F_60 ( V_65 , V_70 , 0 ) ;
error = F_61 ( V_2 -> V_48 , NULL , F_35 ,
V_115 | V_116 ,
V_17 -> V_97 , V_2 ) ;
if ( error ) {
F_38 ( V_2 -> V_10 , L_7 ,
V_2 -> V_48 , error ) ;
goto V_117;
}
F_17 ( V_2 -> V_48 ) ;
error = F_39 ( V_2 ) ;
if ( error )
goto V_118;
error = F_62 ( V_65 ) ;
if ( error ) {
F_38 ( V_2 -> V_10 , L_8 ,
error ) ;
goto V_118;
}
return V_2 ;
V_118:
F_63 ( V_2 -> V_48 , V_2 ) ;
V_117:
if ( V_17 -> exit )
V_17 -> exit () ;
V_102:
F_64 ( V_65 ) ;
F_65 ( V_2 ) ;
V_99:
return F_66 ( error ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_48 , V_2 ) ;
F_68 ( V_2 -> V_66 ) ;
if ( V_2 -> V_17 -> exit )
V_2 -> V_17 -> exit () ;
F_65 ( V_2 ) ;
}
