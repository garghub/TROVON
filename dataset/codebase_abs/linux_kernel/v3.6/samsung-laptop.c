static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 ,
struct V_4 * V_6 )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
int V_9 = 0 ;
T_1 V_10 = F_2 ( V_2 -> V_11 + V_8 -> V_12 . V_10 ) ;
T_2 V_13 , V_14 ;
F_3 ( & V_2 -> V_15 ) ;
if ( V_16 ) {
if ( V_5 )
F_4 ( L_1
L_2 ,
V_3 , V_5 -> V_17 , V_5 -> V_18 , V_5 -> V_19 , V_5 -> V_20 ) ;
else
F_4 ( L_3 , V_3 ) ;
}
F_5 ( F_6 ( V_2 -> V_11 + V_8 -> V_12 . V_21 ) , V_10 ) ;
F_7 ( V_8 -> V_22 , V_2 -> V_23 + V_24 ) ;
F_7 ( V_3 , V_2 -> V_23 + V_25 ) ;
F_8 ( 0 , V_2 -> V_23 + V_26 ) ;
if ( V_5 ) {
F_9 ( V_5 -> V_17 , V_2 -> V_23 + V_27 ) ;
F_9 ( V_5 -> V_18 , V_2 -> V_23 + V_27 + 4 ) ;
F_7 ( V_5 -> V_19 , V_2 -> V_23 + V_27 + 8 ) ;
F_8 ( V_5 -> V_20 , V_2 -> V_23 + V_27 + 10 ) ;
}
F_5 ( F_6 ( V_2 -> V_11 + V_8 -> V_12 . V_28 ) , V_10 ) ;
F_5 ( F_6 ( V_2 -> V_11 + V_8 -> V_12 . V_29 ) , V_10 ) ;
V_13 = F_6 ( V_2 -> V_23 + V_26 ) ;
V_14 = F_6 ( V_2 -> V_23 + V_27 ) ;
if ( V_13 != 0xaa || ( V_14 == 0xff && V_16 ) )
F_10 ( L_4
L_5 ,
V_3 , V_13 , V_14 ) ;
if ( V_13 != 0xaa || V_14 == 0xff ) {
V_9 = - V_30 ;
goto exit;
}
if ( V_6 ) {
V_6 -> V_17 = F_11 ( V_2 -> V_23 + V_27 ) ;
V_6 -> V_18 = F_11 ( V_2 -> V_23 + V_27 + 4 ) ;
V_6 -> V_19 = F_2 ( V_2 -> V_23 + V_27 + 2 ) ;
V_6 -> V_20 = F_6 ( V_2 -> V_23 + V_27 + 1 ) ;
}
if ( V_16 && V_6 ) {
F_4 ( L_6 ,
V_6 -> V_17 , V_6 -> V_18 , V_6 -> V_19 , V_6 -> V_20 ) ;
}
exit:
F_12 ( & V_2 -> V_15 ) ;
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_31 )
{
struct V_4 V_5 = { { { . V_17 = 0 , . V_18 = 0 , . V_19 = 0 , . V_20 = 0 } } } ;
V_5 . V_31 [ 0 ] = V_31 ;
return F_1 ( V_2 , V_3 , & V_5 , NULL ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_34 ;
int V_35 = 0 ;
int V_36 ;
V_36 = F_1 ( V_2 , V_33 -> V_37 ,
NULL , & V_34 ) ;
if ( V_36 )
return V_36 ;
V_35 = V_34 . V_31 [ 0 ] ;
if ( V_35 > V_8 -> V_38 )
V_35 -= V_8 -> V_38 ;
else
V_35 = 0 ;
return V_35 ;
}
static void F_15 ( struct V_1 * V_2 , T_2 V_35 )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
T_2 V_39 = V_35 + V_8 -> V_38 ;
if ( V_2 -> V_40 && V_39 != 0 ) {
if ( V_35 == F_14 ( V_2 ) )
return;
F_13 ( V_2 , V_33 -> F_15 , 0 ) ;
}
F_13 ( V_2 , V_33 -> F_15 , V_39 ) ;
}
static int V_37 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
return F_14 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_43 ;
int V_44 ;
int V_45 = F_14 ( V_2 ) ;
if ( V_45 == 0 )
F_15 ( V_2 , 1 ) ;
V_43 = F_14 ( V_2 ) ;
if ( V_43 <= 2 )
V_44 = V_43 + 2 ;
else
V_44 = V_43 - 2 ;
V_2 -> V_40 = false ;
F_15 ( V_2 , V_44 ) ;
if ( F_14 ( V_2 ) != V_44 ) {
V_2 -> V_40 = true ;
F_4 ( L_7 ) ;
}
F_15 ( V_2 , V_45 ) ;
}
static int F_18 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
F_15 ( V_2 , V_42 -> V_46 . V_47 ) ;
if ( V_42 -> V_46 . V_48 == V_49 )
F_13 ( V_2 , V_33 -> V_50 , 1 ) ;
else
F_13 ( V_2 , V_33 -> V_50 , 0 ) ;
return 0 ;
}
static int F_19 ( void * V_31 , bool V_51 )
{
struct V_52 * V_53 = V_31 ;
struct V_1 * V_2 = V_53 -> V_2 ;
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
return F_13 ( V_2 , V_33 -> V_54 ,
! V_51 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_4 * V_31 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
return F_1 ( V_2 , V_33 -> V_55 ,
NULL , V_31 ) ;
}
static int F_21 ( void * V_56 , bool V_51 )
{
struct V_52 * V_53 = V_56 ;
struct V_1 * V_2 = V_53 -> V_2 ;
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
int V_9 , V_57 ;
V_9 = F_20 ( V_2 , & V_31 ) ;
if ( V_9 )
return V_9 ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ )
if ( V_31 . V_31 [ V_57 ] == 0x02 )
V_31 . V_31 [ 1 ] = 0 ;
if ( V_53 -> type == V_58 )
V_31 . V_31 [ V_59 ] = ! V_51 ;
else if ( V_53 -> type == V_60 )
V_31 . V_31 [ V_61 ] = ! V_51 ;
return F_1 ( V_2 , V_33 -> V_62 ,
& V_31 , & V_31 ) ;
}
static void F_22 ( struct V_63 * V_63 , void * V_56 )
{
struct V_52 * V_53 = V_56 ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_4 V_31 ;
int V_9 ;
V_9 = F_20 ( V_2 , & V_31 ) ;
if ( V_9 )
return ;
if ( V_53 -> type == V_58 )
V_9 = V_31 . V_31 [ V_59 ] ;
else if ( V_53 -> type == V_60 )
V_9 = V_31 . V_31 [ V_61 ] ;
else
return ;
F_23 ( V_63 , ! V_9 ) ;
}
static T_3 F_24 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
const struct V_7 * V_8 = V_2 -> V_8 ;
const struct V_32 * V_33 = & V_8 -> V_33 ;
struct V_4 V_34 ;
int V_36 ;
int V_57 ;
V_36 = F_1 ( V_2 , V_33 -> F_24 ,
NULL , & V_34 ) ;
if ( V_36 )
return V_36 ;
for ( V_57 = 0 ; V_8 -> V_69 [ V_57 ] . V_70 ; ++ V_57 ) {
if ( V_34 . V_31 [ 0 ] == V_8 -> V_69 [ V_57 ] . V_71 )
return sprintf ( V_68 , L_8 , V_8 -> V_69 [ V_57 ] . V_70 ) ;
}
return sprintf ( V_68 , L_8 , L_9 ) ;
}
static T_3 F_26 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 ,
T_4 V_72 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
const struct V_7 * V_8 = V_2 -> V_8 ;
const struct V_32 * V_33 = & V_8 -> V_33 ;
int V_57 ;
if ( V_72 < 1 )
return V_72 ;
for ( V_57 = 0 ; V_8 -> V_69 [ V_57 ] . V_70 ; ++ V_57 ) {
const struct V_73 * V_74 =
& V_8 -> V_69 [ V_57 ] ;
if ( ! strncasecmp ( V_74 -> V_70 , V_68 , strlen ( V_74 -> V_70 ) ) ) {
F_13 ( V_2 ,
V_33 -> F_26 ,
V_74 -> V_71 ) ;
break;
}
}
if ( ! V_8 -> V_69 [ V_57 ] . V_70 )
return - V_30 ;
return V_72 ;
}
static int F_27 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
int V_36 ;
if ( V_33 -> V_75 == 0xFFFF )
return - V_76 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_31 [ 0 ] = 0x80 ;
V_36 = F_1 ( V_2 , V_33 -> V_75 ,
& V_31 , & V_31 ) ;
if ( V_36 )
return V_36 ;
if ( V_31 . V_31 [ 0 ] != 0 && V_31 . V_31 [ 0 ] != 1 )
return - V_76 ;
return V_31 . V_31 [ 0 ] ;
}
static int F_28 ( struct V_1 * V_2 ,
int V_77 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_31 [ 0 ] = 0x80 | V_77 ;
return F_1 ( V_2 , V_33 -> V_78 ,
& V_31 , NULL ) ;
}
static T_3 V_75 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
char * V_68 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_9 ;
V_9 = F_27 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return sprintf ( V_68 , L_10 , V_9 ) ;
}
static T_3 V_78 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
const char * V_68 , T_4 V_72 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_9 , V_71 ;
if ( ! V_72 || sscanf ( V_68 , L_11 , & V_71 ) != 1 )
return - V_30 ;
V_9 = F_28 ( V_2 , ! ! V_71 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_72 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
int V_36 ;
if ( V_33 -> V_79 == 0xFFFF )
return - V_76 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_31 [ 0 ] = 0x80 ;
V_36 = F_1 ( V_2 , V_33 -> V_79 ,
& V_31 , & V_31 ) ;
if ( V_36 )
return V_36 ;
if ( V_31 . V_31 [ 0 ] != 0 && V_31 . V_31 [ 0 ] != 1 )
return - V_76 ;
return V_31 . V_31 [ 0 ] ;
}
static int F_30 ( struct V_1 * V_2 ,
int V_77 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_31 [ 0 ] = 0x80 | V_77 ;
return F_1 ( V_2 , V_33 -> V_80 ,
& V_31 , NULL ) ;
}
static T_3 V_79 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
char * V_68 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_9 ;
V_9 = F_29 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return sprintf ( V_68 , L_10 , V_9 ) ;
}
static T_3 V_80 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
const char * V_68 , T_4 V_72 )
{
struct V_1 * V_2 = F_25 ( V_65 ) ;
int V_9 , V_71 ;
if ( ! V_72 || sscanf ( V_68 , L_11 , & V_71 ) != 1 )
return - V_30 ;
V_9 = F_30 ( V_2 , ! ! V_71 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_72 ;
}
static int F_31 ( void T_5 * V_81 , const char * V_82 )
{
int V_57 = 0 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < 0xffff ; V_83 ++ ) {
char V_84 = F_6 ( V_81 + V_83 ) ;
if ( V_84 == V_82 [ V_57 ] ) {
if ( V_57 == strlen ( V_82 ) - 1 )
break;
++ V_57 ;
} else {
V_57 = 0 ;
}
}
return V_83 ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 . V_63 ) {
F_33 ( V_2 -> V_85 . V_63 ) ;
F_34 ( V_2 -> V_85 . V_63 ) ;
V_2 -> V_85 . V_63 = NULL ;
}
if ( V_2 -> V_86 . V_63 ) {
F_33 ( V_2 -> V_86 . V_63 ) ;
F_34 ( V_2 -> V_86 . V_63 ) ;
V_2 -> V_86 . V_63 = NULL ;
}
}
static int F_35 ( struct V_1 * V_2 ,
struct V_52 * V_87 ,
const char * V_70 , enum V_88 type ,
const struct V_89 * V_90 ,
int V_51 )
{
struct V_63 * * V_63 = & V_87 -> V_63 ;
int V_9 ;
V_87 -> type = type ;
V_87 -> V_2 = V_2 ;
* V_63 = F_36 ( V_70 , & V_2 -> V_91 -> V_65 ,
type , V_90 , V_87 ) ;
if ( ! * V_63 )
return - V_30 ;
if ( V_51 != - 1 )
F_37 ( * V_63 , V_51 ) ;
V_9 = F_38 ( * V_63 ) ;
if ( V_9 ) {
F_34 ( * V_63 ) ;
* V_63 = NULL ;
return V_9 ;
}
return 0 ;
}
static int T_6 F_39 ( struct V_1 * V_2 )
{
return F_35 ( V_2 , & V_2 -> V_85 , L_12 ,
V_58 , & V_92 , - 1 ) ;
}
static int T_6 F_40 ( struct V_1 * V_2 )
{
struct V_4 V_31 ;
int V_9 ;
V_9 = F_20 ( V_2 , & V_31 ) ;
if ( V_9 ) {
if ( V_9 == - V_30 )
V_9 = F_39 ( V_2 ) ;
return V_9 ;
}
if ( V_31 . V_31 [ V_59 ] != 0x02 )
V_9 = F_35 ( V_2 , & V_2 -> V_85 ,
L_12 ,
V_58 ,
& V_93 ,
! V_31 . V_31 [ V_59 ] ) ;
if ( V_9 )
goto exit;
if ( V_31 . V_31 [ V_61 ] != 0x02 )
V_9 = F_35 ( V_2 , & V_2 -> V_86 ,
L_13 ,
V_60 ,
& V_93 ,
! V_31 . V_31 [ V_61 ] ) ;
if ( V_9 )
goto exit;
exit:
if ( V_9 )
F_32 ( V_2 ) ;
return V_9 ;
}
static int T_6 F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 -> V_94 == 2 )
return F_39 ( V_2 ) ;
if ( V_2 -> V_8 -> V_94 == 3 )
return F_40 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
int V_36 ;
if ( V_33 -> V_95 == 0xFFFF )
return - V_76 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_17 = 0xaabb ;
V_36 = F_1 ( V_2 , V_33 -> V_95 ,
& V_31 , & V_31 ) ;
if ( V_36 )
return V_36 ;
if ( V_31 . V_17 != 0xccdd )
return - V_76 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
int V_36 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_31 [ 0 ] = 0x81 ;
V_36 = F_1 ( V_2 , V_33 -> V_95 ,
& V_31 , & V_31 ) ;
if ( V_36 )
return V_36 ;
return V_31 . V_31 [ 0 ] ;
}
static int F_44 ( struct V_1 * V_2 , int V_47 )
{
const struct V_32 * V_33 = & V_2 -> V_8 -> V_33 ;
struct V_4 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_17 = 0x82 | ( ( V_47 & 0xFF ) << 8 ) ;
return F_1 ( V_2 , V_33 -> V_95 ,
& V_31 , NULL ) ;
}
static void F_45 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
V_2 = F_46 ( V_97 , struct V_1 , V_98 ) ;
F_44 ( V_2 , V_2 -> V_99 ) ;
}
static void F_47 ( struct V_100 * V_101 ,
enum V_102 V_71 )
{
struct V_1 * V_2 ;
V_2 = F_46 ( V_101 , struct V_1 , V_103 ) ;
if ( V_71 > V_2 -> V_103 . V_104 )
V_71 = V_2 -> V_103 . V_104 ;
else if ( V_71 < 0 )
V_71 = 0 ;
V_2 -> V_99 = V_71 ;
F_48 ( V_2 -> V_105 , & V_2 -> V_98 ) ;
}
static enum V_102 F_49 ( struct V_100 * V_101 )
{
struct V_1 * V_2 ;
V_2 = F_46 ( V_101 , struct V_1 , V_103 ) ;
return F_43 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( ! F_51 ( V_2 -> V_103 . V_65 ) )
F_52 ( & V_2 -> V_103 ) ;
if ( V_2 -> V_105 )
F_53 ( V_2 -> V_105 ) ;
}
static int T_6 F_54 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
V_2 -> V_105 = F_55 ( L_14 ) ;
if ( ! V_2 -> V_105 )
return - V_106 ;
if ( F_42 ( V_2 ) >= 0 ) {
F_56 ( & V_2 -> V_98 , F_45 ) ;
V_2 -> V_103 . V_70 = L_15 ;
V_2 -> V_103 . V_107 = F_47 ;
V_2 -> V_103 . V_108 = F_49 ;
V_2 -> V_103 . V_104 = 8 ;
V_9 = F_57 ( & V_2 -> V_91 -> V_65 ,
& V_2 -> V_103 ) ;
}
if ( V_9 )
F_50 ( V_2 ) ;
return V_9 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 ) {
F_59 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
}
static int T_6 F_60 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_109 V_46 ;
if ( ! V_2 -> V_110 )
return 0 ;
memset ( & V_46 , 0 , sizeof( struct V_109 ) ) ;
V_46 . type = V_111 ;
V_46 . V_104 = V_2 -> V_8 -> V_104 -
V_2 -> V_8 -> V_38 ;
V_42 = F_61 ( L_16 ,
& V_2 -> V_91 -> V_65 ,
V_2 , & V_112 ,
& V_46 ) ;
if ( F_62 ( V_42 ) )
return F_63 ( V_42 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_41 -> V_46 . V_47 = F_14 ( V_2 ) ;
V_2 -> V_41 -> V_46 . V_48 = V_49 ;
F_64 ( V_2 -> V_41 ) ;
return 0 ;
}
static T_7 F_65 ( struct V_113 * V_114 ,
struct V_115 * V_67 , int V_116 )
{
struct V_64 * V_65 = F_46 ( V_114 , struct V_64 , V_114 ) ;
struct V_91 * V_117 = F_66 ( V_65 ) ;
struct V_1 * V_2 = F_67 ( V_117 ) ;
bool V_118 = true ;
if ( V_67 == & V_119 . V_67 )
V_118 = ! ! V_2 -> V_8 -> V_69 [ 0 ] . V_70 ;
if ( V_67 == & V_120 . V_67 )
V_118 = ! ! ( F_27 ( V_2 ) >= 0 ) ;
if ( V_67 == & V_121 . V_67 )
V_118 = ! ! ( F_29 ( V_2 ) >= 0 ) ;
return V_118 ? V_67 -> V_122 : 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_91 * V_64 = V_2 -> V_91 ;
F_69 ( & V_64 -> V_65 . V_114 , & V_123 ) ;
}
static int T_6 F_70 ( struct V_1 * V_2 )
{
struct V_91 * V_64 = V_2 -> V_91 ;
return F_71 ( & V_64 -> V_65 . V_114 , & V_123 ) ;
}
static int F_72 ( struct V_124 * V_125 , void * V_31 )
{
struct V_1 * V_2 = V_125 -> V_126 ;
struct V_4 * V_127 = & V_2 -> V_16 . V_31 ;
int V_9 ;
F_73 ( V_125 , L_17 ,
V_2 -> V_16 . V_3 ,
V_127 -> V_17 , V_127 -> V_18 , V_127 -> V_19 , V_127 -> V_20 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_16 . V_3 , V_127 , V_127 ) ;
if ( V_9 ) {
F_73 ( V_125 , L_18 ,
V_2 -> V_16 . V_3 ) ;
return V_9 ;
}
F_73 ( V_125 , L_19 ,
V_127 -> V_17 , V_127 -> V_18 , V_127 -> V_19 , V_127 -> V_20 ) ;
return 0 ;
}
static int F_74 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_75 ( V_129 , F_72 , V_128 -> V_130 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 -> V_16 . V_131 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_132 * V_133 ;
V_2 -> V_16 . V_131 = F_79 ( L_20 , NULL ) ;
if ( ! V_2 -> V_16 . V_131 ) {
F_80 ( L_21 ) ;
goto V_134;
}
V_2 -> V_16 . V_135 . V_31 = V_2 -> V_136 ;
V_2 -> V_16 . V_135 . V_137 = 0xffff ;
V_2 -> V_16 . V_138 . V_31 = & V_2 -> V_16 . V_31 ;
V_2 -> V_16 . V_138 . V_137 = sizeof( V_2 -> V_16 . V_31 ) ;
V_2 -> V_16 . V_139 . V_31 = V_2 -> V_140 ;
V_2 -> V_16 . V_139 . V_137 = strlen ( V_2 -> V_140 ) ;
V_133 = F_81 ( L_22 , V_141 | V_142 ,
V_2 -> V_16 . V_131 , & V_2 -> V_16 . V_3 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_82 ( L_23 , V_141 | V_142 , V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_31 . V_17 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_82 ( L_24 , V_141 | V_142 , V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_31 . V_18 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_81 ( L_25 , V_141 | V_142 , V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_31 . V_19 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_83 ( L_26 , V_141 | V_142 , V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_31 . V_20 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_84 ( L_27 , V_141 | V_142 ,
V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_138 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_84 ( L_28 , V_143 | V_142 ,
V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_135 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_85 ( L_29 , V_144 | V_141 ,
V_2 -> V_16 . V_131 , V_2 ,
& V_145 ) ;
if ( ! V_133 )
goto V_134;
V_133 = F_84 ( L_30 , V_141 | V_142 ,
V_2 -> V_16 . V_131 ,
& V_2 -> V_16 . V_139 ) ;
if ( ! V_133 )
goto V_134;
return 0 ;
V_134:
F_76 ( V_2 ) ;
return - V_106 ;
}
static void F_86 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
if ( V_8 && V_8 -> V_33 . V_146 != 0xff )
F_13 ( V_2 , V_8 -> V_33 . V_146 , 0x80 ) ;
if ( V_2 -> V_23 ) {
F_87 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
if ( V_2 -> V_136 ) {
F_87 ( V_2 -> V_136 ) ;
V_2 -> V_136 = NULL ;
}
V_2 -> V_8 = NULL ;
}
static T_6 void F_88 ( struct V_1 * V_2 , int V_83 ,
unsigned int V_147 )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
F_89 ( V_148 L_31 ,
V_83 + 0xf0000 - 6 ) ;
F_89 ( V_148 L_32 ) ;
F_89 ( V_148 L_33 ,
F_2 ( V_2 -> V_11 + V_8 -> V_12 . V_10 ) ) ;
F_89 ( V_148 L_34 ,
F_6 ( V_2 -> V_11 + V_8 -> V_12 . V_28 ) ) ;
F_89 ( V_148 L_35 ,
F_6 ( V_2 -> V_11 + V_8 -> V_12 . V_21 ) ) ;
F_89 ( V_148 L_36 ,
F_6 ( V_2 -> V_11 + V_8 -> V_12 . V_29 ) ) ;
F_89 ( V_148 L_37 ,
F_2 ( V_2 -> V_11 + V_8 -> V_12 . V_149 ) ) ;
F_89 ( V_148 L_38 ,
F_2 ( V_2 -> V_11 + V_8 -> V_12 . V_150 ) ) ;
F_89 ( V_148 L_39 , V_147 ) ;
}
static void T_6 F_90 ( struct V_1 * V_2 )
{
int V_83 = F_31 ( V_2 -> V_136 , L_40 ) ;
int V_57 ;
if ( V_83 == 0xffff )
return ;
V_83 += 1 ;
for ( V_57 = 0 ; V_83 < 0xffff && V_57 < sizeof( V_2 -> V_140 ) - 1 ; V_83 ++ ) {
char V_84 = F_6 ( V_2 -> V_136 + V_83 ) ;
if ( isalnum ( V_84 ) || V_84 == '/' || V_84 == '-' )
V_2 -> V_140 [ V_57 ++ ] = V_84 ;
else
break ;
}
if ( V_16 && V_2 -> V_140 [ 0 ] )
F_4 ( L_41 , V_2 -> V_140 ) ;
}
static int T_6 F_91 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = NULL ;
const struct V_32 * V_33 ;
unsigned int V_147 ;
int V_9 = 0 ;
int V_57 ;
int V_83 ;
V_2 -> V_136 = F_92 ( 0xf0000 , 0xffff ) ;
if ( ! V_2 -> V_136 ) {
if ( V_16 || V_151 )
F_80 ( L_42 ) ;
V_9 = - V_30 ;
goto exit;
}
F_90 ( V_2 ) ;
for ( V_57 = 0 ; V_152 [ V_57 ] . V_153 != 0 ; ++ V_57 ) {
V_2 -> V_8 = & V_152 [ V_57 ] ;
V_83 = F_31 ( V_2 -> V_136 ,
V_2 -> V_8 -> V_153 ) ;
if ( V_83 != 0xffff )
break;
}
if ( V_83 == 0xffff ) {
if ( V_16 || V_151 )
F_80 ( L_43 ) ;
V_9 = - V_76 ;
goto exit;
}
V_8 = V_2 -> V_8 ;
V_33 = & V_8 -> V_33 ;
V_83 += 1 ;
V_2 -> V_11 = ( V_2 -> V_136 + V_83 ) ;
V_147 = ( F_2 ( V_2 -> V_11 + V_8 -> V_12 . V_150 ) & 0x0ffff ) << 4 ;
V_147 += F_2 ( V_2 -> V_11 + V_8 -> V_12 . V_149 ) & 0x0ffff ;
if ( V_16 )
F_88 ( V_2 , V_83 , V_147 ) ;
V_2 -> V_23 = F_92 ( V_147 , 16 ) ;
if ( ! V_2 -> V_23 ) {
F_80 ( L_44 , V_147 ) ;
V_9 = - V_30 ;
goto exit;
}
if ( V_33 -> V_146 != 0xff ) {
int V_36 = F_13 ( V_2 ,
V_33 -> V_146 , 0x81 ) ;
if ( V_36 ) {
F_10 ( L_45 ) ;
V_9 = - V_76 ;
goto exit;
}
}
if ( V_2 -> V_110 )
F_17 ( V_2 ) ;
F_4 ( L_46 ,
V_2 -> V_8 -> V_153 ) ;
exit:
if ( V_9 )
F_86 ( V_2 ) ;
return V_9 ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 ) {
F_94 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
}
}
static int T_6 F_95 ( struct V_1 * V_2 )
{
struct V_91 * V_117 ;
V_117 = F_96 ( L_16 , - 1 , NULL , 0 ) ;
if ( F_62 ( V_117 ) )
return F_63 ( V_117 ) ;
V_2 -> V_91 = V_117 ;
F_97 ( V_2 -> V_91 , V_2 ) ;
return 0 ;
}
static int T_6 F_98 ( const struct V_154 * V_155 )
{
V_156 = V_155 -> V_157 ;
return 0 ;
}
static int T_6 F_99 ( void )
{
struct V_1 * V_2 ;
int V_9 ;
V_156 = & V_158 ;
if ( ! V_151 && ! F_100 ( V_159 ) )
return - V_76 ;
V_2 = F_101 ( sizeof( * V_2 ) , V_160 ) ;
if ( ! V_2 )
return - V_106 ;
F_102 ( & V_2 -> V_15 ) ;
V_2 -> V_110 = true ;
V_2 -> V_156 = V_156 ;
#ifdef F_103
if ( V_2 -> V_156 -> V_161 )
F_104 () ;
if ( F_105 () ) {
V_2 -> V_110 = false ;
} else if ( V_2 -> V_156 -> V_161 ) {
F_4 ( L_47 ) ;
F_106 () ;
}
#endif
V_9 = F_95 ( V_2 ) ;
if ( V_9 )
goto V_162;
V_9 = F_91 ( V_2 ) ;
if ( V_9 )
goto V_163;
#ifdef F_103
if ( F_105 () )
F_4 ( L_48 ) ;
#endif
V_9 = F_70 ( V_2 ) ;
if ( V_9 )
goto V_164;
V_9 = F_60 ( V_2 ) ;
if ( V_9 )
goto V_165;
V_9 = F_41 ( V_2 ) ;
if ( V_9 )
goto V_166;
V_9 = F_54 ( V_2 ) ;
if ( V_9 )
goto V_167;
V_9 = F_78 ( V_2 ) ;
if ( V_9 )
goto V_134;
V_168 = V_2 -> V_91 ;
return V_9 ;
V_134:
F_50 ( V_2 ) ;
V_167:
F_32 ( V_2 ) ;
V_166:
F_58 ( V_2 ) ;
V_165:
F_68 ( V_2 ) ;
V_164:
F_86 ( V_2 ) ;
V_163:
F_93 ( V_2 ) ;
V_162:
F_107 ( V_2 ) ;
return V_9 ;
}
static void T_8 F_108 ( void )
{
struct V_1 * V_2 ;
V_2 = F_67 ( V_168 ) ;
F_76 ( V_2 ) ;
F_50 ( V_2 ) ;
F_32 ( V_2 ) ;
F_58 ( V_2 ) ;
F_68 ( V_2 ) ;
F_86 ( V_2 ) ;
F_93 ( V_2 ) ;
F_107 ( V_2 ) ;
V_168 = NULL ;
}
