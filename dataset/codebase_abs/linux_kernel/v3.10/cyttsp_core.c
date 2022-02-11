static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , void * V_5 )
{
int error ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
error = V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! error )
return 0 ;
F_2 ( V_10 ) ;
}
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , void * V_5 )
{
int error ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
error = V_2 -> V_8 -> V_12 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! error )
return 0 ;
F_2 ( V_10 ) ;
}
return - V_11 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 )
{
return F_3 ( V_2 , V_14 , sizeof( V_13 ) , & V_13 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_16 )
return F_4 ( V_2 ,
V_2 -> V_17 . V_18 ^ V_19 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_20 , 0 , sizeof( V_2 -> V_20 ) ) ;
V_2 -> V_20 . V_21 = 0x10 ;
return F_1 ( V_2 , V_14 ,
sizeof( V_2 -> V_20 ) , & V_2 -> V_20 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int error ;
T_1 V_22 [ sizeof( V_23 ) ] ;
memcpy ( V_22 , V_23 , sizeof( V_23 ) ) ;
if ( V_2 -> V_15 -> V_24 )
memcpy ( & V_22 [ sizeof( V_23 ) - V_25 ] ,
V_2 -> V_15 -> V_24 , V_25 ) ;
error = F_3 ( V_2 , V_14 ,
sizeof( V_22 ) , V_22 ) ;
if ( error )
return error ;
F_2 ( V_10 ) ;
error = F_6 ( V_2 ) ;
if ( error )
return error ;
if ( F_8 ( V_2 -> V_20 . V_21 ) )
return - V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_26 ) ;
if ( error )
return error ;
error = F_1 ( V_2 , V_14 ,
sizeof( V_2 -> V_17 ) , & V_2 -> V_17 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
return V_2 -> V_17 . V_27 == V_28 ? - V_11 : 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int error ;
memset ( & V_2 -> V_29 , 0 , sizeof( V_2 -> V_29 ) ) ;
error = F_4 ( V_2 , V_30 ) ;
if ( error )
return error ;
F_2 ( V_10 ) ;
error = F_1 ( V_2 , V_14 , sizeof( V_2 -> V_29 ) ,
& V_2 -> V_29 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
if ( ! V_2 -> V_29 . V_31 && ! V_2 -> V_29 . V_32 )
return - V_11 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
if ( V_2 -> V_15 -> V_34 != V_35 ||
V_2 -> V_15 -> V_36 != V_37 ||
V_2 -> V_15 -> V_38 != V_39 ) {
T_1 V_40 [] = {
V_2 -> V_15 -> V_34 ,
V_2 -> V_15 -> V_36 ,
V_2 -> V_15 -> V_38
} ;
V_33 = F_3 ( V_2 , V_41 ,
sizeof( V_40 ) , V_40 ) ;
F_2 ( V_10 ) ;
}
return V_33 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
int V_33 ;
F_13 ( V_2 -> V_43 ) ;
V_2 -> V_44 = V_45 ;
F_14 ( V_2 -> V_46 ) ;
V_33 = F_4 ( V_2 , V_47 ) ;
if ( V_33 )
goto V_48;
V_42 = F_15 ( & V_2 -> V_43 ,
F_16 ( V_10 * V_49 ) ) ;
V_33 = V_42 ? 0 : - V_11 ;
V_48:
V_2 -> V_44 = V_50 ;
F_17 ( V_2 -> V_46 ) ;
return V_33 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_51 = V_2 -> V_15 -> V_27 ;
return F_3 ( V_2 , V_52 ,
sizeof( V_51 ) , & V_51 ) ;
}
static void F_19 ( struct V_53 * V_17 , int * V_54 )
{
V_54 [ 0 ] = V_17 -> V_55 >> 4 ;
V_54 [ 1 ] = V_17 -> V_55 & 0xF ;
V_54 [ 2 ] = V_17 -> V_56 >> 4 ;
V_54 [ 3 ] = V_17 -> V_56 & 0xF ;
}
static const struct V_57 * F_20 ( struct V_53 * V_17 ,
int V_58 )
{
switch ( V_58 ) {
case 0 :
return & V_17 -> V_59 ;
case 1 :
return & V_17 -> V_60 ;
case 2 :
return & V_17 -> V_61 ;
case 3 :
return & V_17 -> V_62 ;
default:
return NULL ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_53 * V_17 = & V_2 -> V_17 ;
struct V_63 * V_64 = V_2 -> V_64 ;
int V_65 = F_22 ( V_17 -> V_66 ) ;
const struct V_57 * V_67 ;
int V_54 [ V_68 ] ;
int V_69 ;
F_23 ( V_70 , V_68 ) ;
if ( F_24 ( V_17 -> V_66 ) == 1 ) {
V_65 = 0 ;
F_25 ( V_2 -> V_71 , L_1 , V_72 ) ;
} else if ( V_65 > V_73 ) {
V_65 = 0 ;
F_25 ( V_2 -> V_71 , L_2 , V_72 ) ;
} else if ( F_26 ( V_17 -> V_74 ) ) {
V_65 = 0 ;
F_25 ( V_2 -> V_71 , L_3 , V_72 ) ;
}
F_19 ( V_17 , V_54 ) ;
F_27 ( V_70 , V_68 ) ;
for ( V_69 = 0 ; V_69 < V_65 ; V_69 ++ ) {
V_67 = F_20 ( V_17 , V_69 ) ;
F_28 ( V_64 , V_54 [ V_69 ] ) ;
F_29 ( V_64 , V_75 , true ) ;
F_30 ( V_64 , V_76 , F_31 ( V_67 -> V_77 ) ) ;
F_30 ( V_64 , V_78 , F_31 ( V_67 -> V_79 ) ) ;
F_30 ( V_64 , V_80 , V_67 -> V_81 ) ;
F_32 ( V_54 [ V_69 ] , V_70 ) ;
}
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
if ( F_33 ( V_69 , V_70 ) )
continue;
F_28 ( V_64 , V_69 ) ;
F_29 ( V_64 , V_75 , false ) ;
}
F_34 ( V_64 ) ;
}
static T_2 F_35 ( int V_46 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
int error ;
if ( F_36 ( V_2 -> V_44 == V_45 ) ) {
F_37 ( & V_2 -> V_43 ) ;
goto V_48;
}
error = F_1 ( V_2 , V_14 ,
sizeof( struct V_53 ) , & V_2 -> V_17 ) ;
if ( error )
goto V_48;
error = F_5 ( V_2 ) ;
if ( error )
goto V_48;
if ( F_36 ( V_2 -> V_44 == V_50 ) )
goto V_48;
if ( F_8 ( V_2 -> V_17 . V_74 ) ) {
error = F_7 ( V_2 ) ;
if ( error ) {
F_38 ( V_2 -> V_71 ,
L_4 ,
error ) ;
V_2 -> V_44 = V_50 ;
}
} else {
F_21 ( V_2 ) ;
}
V_48:
return V_83 ;
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
if ( F_8 ( V_2 -> V_20 . V_21 ) &&
F_40 ( V_2 -> V_20 . V_21 ) ) {
error = F_7 ( V_2 ) ;
if ( error )
return error ;
}
if ( F_41 ( V_2 -> V_20 . V_84 ) != V_26 ||
F_42 ( V_2 -> V_20 . V_21 ) ) {
return - V_85 ;
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
V_2 -> V_44 = V_86 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int error ;
error = F_1 ( V_2 , V_14 ,
sizeof( V_2 -> V_17 ) , & V_2 -> V_17 ) ;
if ( error )
return error ;
if ( F_41 ( V_2 -> V_17 . V_18 ) )
return - V_11 ;
F_14 ( V_2 -> V_46 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_87 ) ;
if ( error )
return error ;
F_17 ( V_2 -> V_46 ) ;
return 0 ;
}
static int F_45 ( struct V_88 * V_71 )
{
struct V_1 * V_2 = F_46 ( V_71 ) ;
int V_33 = 0 ;
F_47 ( & V_2 -> V_64 -> V_89 ) ;
if ( V_2 -> V_64 -> V_90 ) {
V_33 = F_44 ( V_2 ) ;
if ( V_33 == 0 )
V_2 -> V_91 = true ;
}
F_48 ( & V_2 -> V_64 -> V_89 ) ;
return V_33 ;
}
static int F_49 ( struct V_88 * V_71 )
{
struct V_1 * V_2 = F_46 ( V_71 ) ;
F_47 ( & V_2 -> V_64 -> V_89 ) ;
if ( V_2 -> V_64 -> V_90 )
F_43 ( V_2 ) ;
V_2 -> V_91 = false ;
F_48 ( & V_2 -> V_64 -> V_89 ) ;
return 0 ;
}
static int F_50 ( struct V_63 * V_71 )
{
struct V_1 * V_2 = F_51 ( V_71 ) ;
int V_33 = 0 ;
if ( ! V_2 -> V_91 )
V_33 = F_43 ( V_2 ) ;
return V_33 ;
}
static void F_52 ( struct V_63 * V_71 )
{
struct V_1 * V_2 = F_51 ( V_71 ) ;
if ( ! V_2 -> V_91 )
F_44 ( V_2 ) ;
}
struct V_1 * F_53 ( const struct V_92 * V_8 ,
struct V_88 * V_71 , int V_46 , T_3 V_93 )
{
const struct V_94 * V_15 = V_71 -> V_95 ;
struct V_1 * V_2 ;
struct V_63 * V_63 ;
int error ;
if ( ! V_15 || ! V_15 -> V_96 || V_46 <= 0 ) {
error = - V_97 ;
goto V_98;
}
V_2 = F_54 ( sizeof( * V_2 ) + V_93 , V_99 ) ;
V_63 = F_55 () ;
if ( ! V_2 || ! V_63 ) {
error = - V_100 ;
goto V_101;
}
V_2 -> V_71 = V_71 ;
V_2 -> V_64 = V_63 ;
V_2 -> V_15 = V_71 -> V_95 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_46 = V_46 ;
F_56 ( & V_2 -> V_43 ) ;
snprintf ( V_2 -> V_102 , sizeof( V_2 -> V_102 ) , L_5 , F_57 ( V_71 ) ) ;
if ( V_15 -> V_103 ) {
error = V_15 -> V_103 () ;
if ( error ) {
F_38 ( V_2 -> V_71 , L_6 ,
error ) ;
goto V_101;
}
}
V_63 -> V_96 = V_15 -> V_96 ;
V_63 -> V_102 = V_2 -> V_102 ;
V_63 -> V_104 . V_105 = V_8 -> V_105 ;
V_63 -> V_71 . V_106 = V_2 -> V_71 ;
V_63 -> V_107 = F_50 ;
V_63 -> V_108 = F_52 ;
F_58 ( V_63 , V_2 ) ;
F_32 ( V_109 , V_63 -> V_110 ) ;
F_59 ( V_63 , V_76 ,
0 , V_15 -> V_111 , 0 , 0 ) ;
F_59 ( V_63 , V_78 ,
0 , V_15 -> V_112 , 0 , 0 ) ;
F_59 ( V_63 , V_80 ,
0 , V_113 , 0 , 0 ) ;
F_60 ( V_63 , V_68 , 0 ) ;
error = F_61 ( V_2 -> V_46 , NULL , F_35 ,
V_114 | V_115 ,
V_15 -> V_96 , V_2 ) ;
if ( error ) {
F_38 ( V_2 -> V_71 , L_7 ,
V_2 -> V_46 , error ) ;
goto V_116;
}
F_17 ( V_2 -> V_46 ) ;
error = F_39 ( V_2 ) ;
if ( error )
goto V_117;
error = F_62 ( V_63 ) ;
if ( error ) {
F_38 ( V_2 -> V_71 , L_8 ,
error ) ;
goto V_117;
}
return V_2 ;
V_117:
F_63 ( V_2 -> V_46 , V_2 ) ;
V_116:
if ( V_15 -> exit )
V_15 -> exit () ;
V_101:
F_64 ( V_63 ) ;
F_65 ( V_2 ) ;
V_98:
return F_66 ( error ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_46 , V_2 ) ;
F_68 ( V_2 -> V_64 ) ;
if ( V_2 -> V_15 -> exit )
V_2 -> V_15 -> exit () ;
F_65 ( V_2 ) ;
}
