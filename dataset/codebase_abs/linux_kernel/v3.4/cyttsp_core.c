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
memset ( & V_2 -> V_15 , 0 , sizeof( V_2 -> V_15 ) ) ;
V_2 -> V_15 . V_16 = 0x10 ;
return F_1 ( V_2 , V_14 ,
sizeof( V_2 -> V_15 ) , & V_2 -> V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int error ;
T_1 V_17 [ sizeof( V_18 ) ] ;
memcpy ( V_17 , V_18 , sizeof( V_18 ) ) ;
if ( V_2 -> V_19 -> V_20 )
memcpy ( & V_17 [ sizeof( V_18 ) - V_21 ] ,
V_2 -> V_19 -> V_20 , sizeof( V_18 ) ) ;
error = F_3 ( V_2 , V_14 ,
sizeof( V_17 ) , V_17 ) ;
if ( error )
return error ;
F_2 ( V_10 ) ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
if ( F_7 ( V_2 -> V_15 . V_16 ) )
return - V_11 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_22 ) ;
if ( error )
return error ;
error = F_1 ( V_2 , V_14 ,
sizeof( V_2 -> V_23 ) , & V_2 -> V_23 ) ;
if ( error )
return error ;
return V_2 -> V_23 . V_24 == V_25 ? - V_11 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int error ;
memset ( & V_2 -> V_26 , 0 , sizeof( V_2 -> V_26 ) ) ;
error = F_4 ( V_2 , V_27 ) ;
if ( error )
return error ;
F_2 ( V_10 ) ;
error = F_1 ( V_2 , V_14 , sizeof( V_2 -> V_26 ) ,
& V_2 -> V_26 ) ;
if ( error )
return error ;
if ( ! V_2 -> V_26 . V_28 && ! V_2 -> V_26 . V_29 )
return - V_11 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 -> V_19 -> V_31 != V_32 ||
V_2 -> V_19 -> V_33 != V_34 ||
V_2 -> V_19 -> V_35 != V_36 ) {
T_1 V_37 [] = {
V_2 -> V_19 -> V_31 ,
V_2 -> V_19 -> V_33 ,
V_2 -> V_19 -> V_35
} ;
V_30 = F_3 ( V_2 , V_38 ,
sizeof( V_37 ) , V_37 ) ;
F_2 ( V_10 ) ;
}
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
int V_30 ;
F_12 ( V_2 -> V_40 ) ;
V_2 -> V_41 = V_42 ;
F_13 ( V_2 -> V_43 ) ;
V_30 = F_4 ( V_2 , V_44 ) ;
if ( V_30 )
goto V_45;
V_39 = F_14 ( & V_2 -> V_40 ,
F_15 ( V_10 * V_46 ) ) ;
V_30 = V_39 ? 0 : - V_11 ;
V_45:
V_2 -> V_41 = V_47 ;
F_16 ( V_2 -> V_43 ) ;
return V_30 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_48 = V_2 -> V_19 -> V_24 ;
return F_3 ( V_2 , V_49 ,
sizeof( V_48 ) , & V_48 ) ;
}
static void F_18 ( struct V_50 * V_23 , int * V_51 )
{
V_51 [ 0 ] = V_23 -> V_52 >> 4 ;
V_51 [ 1 ] = V_23 -> V_52 & 0xF ;
V_51 [ 2 ] = V_23 -> V_53 >> 4 ;
V_51 [ 3 ] = V_23 -> V_53 & 0xF ;
}
static const struct V_54 * F_19 ( struct V_50 * V_23 ,
int V_55 )
{
switch ( V_55 ) {
case 0 :
return & V_23 -> V_56 ;
case 1 :
return & V_23 -> V_57 ;
case 2 :
return & V_23 -> V_58 ;
case 3 :
return & V_23 -> V_59 ;
default:
return NULL ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_50 * V_23 = & V_2 -> V_23 ;
struct V_60 * V_61 = V_2 -> V_61 ;
int V_62 = F_21 ( V_23 -> V_63 ) ;
const struct V_54 * V_64 ;
int V_51 [ V_65 ] ;
int V_66 ;
F_22 ( V_67 , V_65 ) ;
if ( F_23 ( V_23 -> V_63 ) == 1 ) {
V_62 = 0 ;
F_24 ( V_2 -> V_68 , L_1 , V_69 ) ;
} else if ( V_62 > V_70 ) {
V_62 = 0 ;
F_24 ( V_2 -> V_68 , L_2 , V_69 ) ;
} else if ( F_25 ( V_23 -> V_71 ) ) {
V_62 = 0 ;
F_24 ( V_2 -> V_68 , L_3 , V_69 ) ;
}
F_18 ( V_23 , V_51 ) ;
F_26 ( V_67 , V_65 ) ;
for ( V_66 = 0 ; V_66 < V_62 ; V_66 ++ ) {
V_64 = F_19 ( V_23 , V_66 ) ;
F_27 ( V_61 , V_51 [ V_66 ] ) ;
F_28 ( V_61 , V_72 , true ) ;
F_29 ( V_61 , V_73 , F_30 ( V_64 -> V_74 ) ) ;
F_29 ( V_61 , V_75 , F_30 ( V_64 -> V_76 ) ) ;
F_29 ( V_61 , V_77 , V_64 -> V_78 ) ;
F_31 ( V_51 [ V_66 ] , V_67 ) ;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
if ( F_32 ( V_66 , V_67 ) )
continue;
F_27 ( V_61 , V_66 ) ;
F_28 ( V_61 , V_72 , false ) ;
}
F_33 ( V_61 ) ;
}
static T_2 F_34 ( int V_43 , void * V_79 )
{
struct V_1 * V_2 = V_79 ;
int error ;
if ( F_35 ( V_2 -> V_41 == V_42 ) ) {
F_36 ( & V_2 -> V_40 ) ;
goto V_45;
}
error = F_1 ( V_2 , V_14 ,
sizeof( struct V_50 ) , & V_2 -> V_23 ) ;
if ( error )
goto V_45;
if ( V_2 -> V_19 -> V_80 ) {
error = F_4 ( V_2 ,
V_2 -> V_23 . V_81 ^ V_82 ) ;
if ( error )
goto V_45;
}
if ( F_35 ( V_2 -> V_41 == V_47 ) )
goto V_45;
if ( F_7 ( V_2 -> V_23 . V_71 ) ) {
error = F_6 ( V_2 ) ;
if ( error ) {
F_37 ( V_2 -> V_68 ,
L_4 ,
error ) ;
V_2 -> V_41 = V_47 ;
}
} else {
F_20 ( V_2 ) ;
}
V_45:
return V_83 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int error ;
error = F_11 ( V_2 ) ;
if ( error )
return error ;
error = F_5 ( V_2 ) ;
if ( error )
return error ;
if ( F_7 ( V_2 -> V_15 . V_16 ) &&
F_39 ( V_2 -> V_15 . V_16 ) ) {
error = F_6 ( V_2 ) ;
if ( error )
return error ;
}
if ( F_40 ( V_2 -> V_15 . V_84 ) != V_22 ||
F_41 ( V_2 -> V_15 . V_16 ) ) {
return - V_85 ;
}
error = F_9 ( V_2 ) ;
if ( error )
return error ;
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_8 ( V_2 ) ;
if ( error )
return error ;
error = F_17 ( V_2 ) ;
if ( error )
return error ;
V_2 -> V_41 = V_86 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int error ;
error = F_1 ( V_2 , V_14 ,
sizeof( V_2 -> V_23 ) , & V_2 -> V_23 ) ;
if ( error )
return error ;
if ( F_40 ( V_2 -> V_23 . V_81 ) )
return - V_11 ;
F_13 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_87 ) ;
if ( error )
return error ;
F_16 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_44 ( struct V_88 * V_68 )
{
struct V_1 * V_2 = F_45 ( V_68 ) ;
int V_30 = 0 ;
F_46 ( & V_2 -> V_61 -> V_89 ) ;
if ( V_2 -> V_61 -> V_90 ) {
V_30 = F_43 ( V_2 ) ;
if ( V_30 == 0 )
V_2 -> V_91 = true ;
}
F_47 ( & V_2 -> V_61 -> V_89 ) ;
return V_30 ;
}
static int F_48 ( struct V_88 * V_68 )
{
struct V_1 * V_2 = F_45 ( V_68 ) ;
F_46 ( & V_2 -> V_61 -> V_89 ) ;
if ( V_2 -> V_61 -> V_90 )
F_42 ( V_2 ) ;
V_2 -> V_91 = false ;
F_47 ( & V_2 -> V_61 -> V_89 ) ;
return 0 ;
}
static int F_49 ( struct V_60 * V_68 )
{
struct V_1 * V_2 = F_50 ( V_68 ) ;
int V_30 = 0 ;
if ( ! V_2 -> V_91 )
V_30 = F_42 ( V_2 ) ;
return V_30 ;
}
static void F_51 ( struct V_60 * V_68 )
{
struct V_1 * V_2 = F_50 ( V_68 ) ;
if ( ! V_2 -> V_91 )
F_43 ( V_2 ) ;
}
struct V_1 * F_52 ( const struct V_92 * V_8 ,
struct V_88 * V_68 , int V_43 , T_3 V_93 )
{
const struct V_94 * V_19 = V_68 -> V_95 ;
struct V_1 * V_2 ;
struct V_60 * V_60 ;
int error ;
if ( ! V_19 || ! V_19 -> V_96 || V_43 <= 0 ) {
error = - V_97 ;
goto V_98;
}
V_2 = F_53 ( sizeof( * V_2 ) + V_93 , V_99 ) ;
V_60 = F_54 () ;
if ( ! V_2 || ! V_60 ) {
error = - V_100 ;
goto V_101;
}
V_2 -> V_68 = V_68 ;
V_2 -> V_61 = V_60 ;
V_2 -> V_19 = V_68 -> V_95 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_43 = V_43 ;
F_55 ( & V_2 -> V_40 ) ;
snprintf ( V_2 -> V_102 , sizeof( V_2 -> V_102 ) , L_5 , F_56 ( V_68 ) ) ;
if ( V_19 -> V_103 ) {
error = V_19 -> V_103 () ;
if ( error ) {
F_37 ( V_2 -> V_68 , L_6 ,
error ) ;
goto V_101;
}
}
V_60 -> V_96 = V_19 -> V_96 ;
V_60 -> V_102 = V_2 -> V_102 ;
V_60 -> V_104 . V_105 = V_8 -> V_105 ;
V_60 -> V_68 . V_106 = V_2 -> V_68 ;
V_60 -> V_107 = F_49 ;
V_60 -> V_108 = F_51 ;
F_57 ( V_60 , V_2 ) ;
F_31 ( V_109 , V_60 -> V_110 ) ;
F_58 ( V_60 , V_73 ,
0 , V_19 -> V_111 , 0 , 0 ) ;
F_58 ( V_60 , V_75 ,
0 , V_19 -> V_112 , 0 , 0 ) ;
F_58 ( V_60 , V_77 ,
0 , V_113 , 0 , 0 ) ;
F_59 ( V_60 , V_65 ) ;
error = F_60 ( V_2 -> V_43 , NULL , F_34 ,
V_114 | V_115 ,
V_19 -> V_96 , V_2 ) ;
if ( error ) {
F_37 ( V_2 -> V_68 , L_7 ,
V_2 -> V_43 , error ) ;
goto V_116;
}
F_16 ( V_2 -> V_43 ) ;
error = F_38 ( V_2 ) ;
if ( error )
goto V_117;
error = F_61 ( V_60 ) ;
if ( error ) {
F_37 ( V_2 -> V_68 , L_8 ,
error ) ;
goto V_117;
}
return V_2 ;
V_117:
F_62 ( V_2 -> V_43 , V_2 ) ;
V_116:
if ( V_19 -> exit )
V_19 -> exit () ;
V_101:
F_63 ( V_60 ) ;
F_64 ( V_2 ) ;
V_98:
return F_65 ( error ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_43 , V_2 ) ;
F_67 ( V_2 -> V_61 ) ;
if ( V_2 -> V_19 -> exit )
V_2 -> V_19 -> exit () ;
F_64 ( V_2 ) ;
}
