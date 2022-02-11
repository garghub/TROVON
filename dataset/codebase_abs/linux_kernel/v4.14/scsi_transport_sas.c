static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_1 * V_7 ;
F_3 ( V_5 -> V_8 . V_9 != V_10 ) ;
V_7 = F_4 ( V_5 ) ;
return V_7 ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 -> V_15 ) ;
struct V_4 * V_5 = NULL ;
if ( ! F_7 ( V_12 -> V_15 ) )
V_5 = F_8 ( V_12 -> V_15 ) ;
if ( ! V_12 -> V_16 -> V_17 ) {
F_9 ( V_12 -> V_15 , L_1 ) ;
F_10 ( V_12 , - V_18 , 0 ) ;
return 0 ;
}
F_11 ( V_14 -> V_19 ) -> V_20 -> V_21 ( V_12 , V_14 , V_5 ) ;
return 0 ;
}
static void F_12 ( struct V_22 * V_15 )
{
struct V_13 * V_14 = F_6 ( V_15 ) ;
struct V_23 * V_24 = F_13 ( V_14 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
if ( V_26 )
F_14 ( V_26 ) ;
}
static int F_15 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_25 * V_26 ;
if ( ! F_11 ( V_14 -> V_19 ) -> V_20 -> V_21 ) {
F_16 ( L_2 , V_14 -> V_27 -> V_28 ) ;
return 0 ;
}
if ( V_5 ) {
V_26 = F_17 ( & V_5 -> V_15 , F_18 ( & V_5 -> V_15 ) ,
F_5 , 0 , NULL ) ;
if ( F_19 ( V_26 ) )
return F_20 ( V_26 ) ;
V_5 -> V_26 = V_26 ;
} else {
char V_28 [ 20 ] ;
snprintf ( V_28 , sizeof( V_28 ) , L_3 , V_14 -> V_29 ) ;
V_26 = F_17 ( & V_14 -> V_30 , V_28 ,
F_5 , 0 , F_12 ) ;
if ( F_19 ( V_26 ) )
return F_20 ( V_26 ) ;
F_13 ( V_14 ) -> V_26 = V_26 ;
}
F_21 ( V_26 , V_31 ) ;
F_22 ( V_32 , V_26 ) ;
F_22 ( V_33 , V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_34 * V_35 , struct V_22 * V_15 ,
struct V_22 * V_36 )
{
struct V_13 * V_14 = F_6 ( V_15 ) ;
struct V_23 * V_24 = F_13 ( V_14 ) ;
F_24 ( & V_24 -> V_37 ) ;
F_25 ( & V_24 -> V_38 ) ;
V_24 -> V_39 = 0 ;
V_24 -> V_40 = 0 ;
V_24 -> V_41 = 0 ;
if ( F_15 ( V_14 , NULL ) )
F_26 ( V_42 , V_15 , L_4 ,
V_14 -> V_29 ) ;
return 0 ;
}
static int F_27 ( struct V_34 * V_35 , struct V_22 * V_15 ,
struct V_22 * V_36 )
{
struct V_13 * V_14 = F_6 ( V_15 ) ;
struct V_25 * V_26 = F_13 ( V_14 ) -> V_26 ;
if ( V_26 )
F_28 ( V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_43 * V_44 ,
struct V_22 * V_15 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 ;
if ( ! F_7 ( V_15 ) )
return 0 ;
V_14 = F_6 ( V_15 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_47 . V_48 . V_49 !=
& V_50 . V_49 )
return 0 ;
V_46 = F_11 ( V_14 -> V_19 ) ;
return & V_46 -> V_51 . V_47 . V_48 == V_44 ;
}
static int F_30 ( struct V_22 * V_15 , void * V_52 )
{
int V_53 = ( int ) ( unsigned long ) V_52 ;
if ( V_53 == 0 && F_31 ( V_15 ) )
F_32 ( F_33 ( V_15 ) ) ;
else if ( V_53 == 1 && F_34 ( V_15 ) )
F_35 ( F_36 ( V_15 ) ) ;
return 0 ;
}
void F_37 ( struct V_22 * V_15 )
{
F_38 ( V_15 , ( void * ) 0 , F_30 ) ;
F_38 ( V_15 , ( void * ) 1 , F_30 ) ;
}
void F_39 ( struct V_13 * V_14 )
{
F_37 ( & V_14 -> V_30 ) ;
F_40 ( V_14 ) ;
}
T_1 F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_5 . V_8 . V_54 ;
}
unsigned int
F_42 ( struct V_2 * V_3 )
{
const int V_55 = 32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
char * V_56 = F_43 ( V_55 , V_57 ) ;
int V_58 = 0 ;
if ( ! V_56 )
goto V_59;
if ( F_44 ( V_3 , 0x90 , V_56 , V_55 ) )
goto V_59;
V_58 = V_56 [ 12 ] & 0x01 ;
V_59:
F_45 ( V_56 ) ;
V_7 -> V_60 = V_58 ;
return V_58 ;
}
void
F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_61 = 0 ;
}
void F_47 ( struct V_2 * V_3 )
{
unsigned int V_60 = 0 ;
V_60 = F_42 ( V_3 ) ;
if ( V_60 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_61 = 1 ;
}
return;
}
unsigned int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_61 ;
}
static T_2
F_49 ( struct V_22 * V_15 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_65 * V_66 = F_50 ( V_15 ) ;
if ( ! V_66 -> V_8 . V_9 )
return snprintf ( V_64 , 20 , L_5 ) ;
return F_51 ( V_66 -> V_8 . V_9 , V_64 ) ;
}
static T_2 F_52 ( struct V_22 * V_15 ,
T_3 V_67 , int V_68 )
{
struct V_65 * V_66 = F_50 ( V_15 ) ;
struct V_13 * V_14 = F_6 ( V_66 -> V_15 . V_69 ) ;
struct V_45 * V_46 = F_11 ( V_14 -> V_19 ) ;
int error ;
error = V_46 -> V_20 -> V_70 ( V_66 , V_68 ) ;
if ( error )
return error ;
V_66 -> V_71 = V_68 ;
return V_67 ;
}
static T_2
F_53 ( struct V_22 * V_15 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_67 )
{
if ( V_67 < 1 )
return - V_18 ;
switch ( V_64 [ 0 ] ) {
case '0' :
F_52 ( V_15 , V_67 , 0 ) ;
break;
case '1' :
F_52 ( V_15 , V_67 , 1 ) ;
break;
default:
return - V_18 ;
}
return V_67 ;
}
static T_2
F_54 ( struct V_22 * V_15 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_65 * V_66 = F_50 ( V_15 ) ;
return snprintf ( V_64 , 20 , L_6 , V_66 -> V_71 ) ;
}
static T_2
F_55 ( struct V_22 * V_15 , T_3 V_67 , int V_72 )
{
struct V_65 * V_66 = F_50 ( V_15 ) ;
struct V_13 * V_14 = F_6 ( V_66 -> V_15 . V_69 ) ;
struct V_45 * V_46 = F_11 ( V_14 -> V_19 ) ;
int error ;
error = V_46 -> V_20 -> V_73 ( V_66 , V_72 ) ;
if ( error )
return error ;
V_66 -> V_71 = 1 ;
return V_67 ;
}
static T_2
F_56 ( struct V_22 * V_15 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_67 )
{
return F_55 ( V_15 , V_67 , 0 ) ;
}
static T_2
F_57 ( struct V_22 * V_15 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_67 )
{
return F_55 ( V_15 , V_67 , 1 ) ;
}
static int F_58 ( struct V_34 * V_35 , struct V_22 * V_15 ,
struct V_22 * V_36 )
{
struct V_65 * V_66 = F_36 ( V_15 ) ;
struct V_13 * V_14 = F_6 ( V_66 -> V_15 . V_69 ) ;
struct V_45 * V_46 = F_11 ( V_14 -> V_19 ) ;
if ( V_46 -> V_20 -> V_74 )
V_46 -> V_20 -> V_74 ( V_66 ) ;
return 0 ;
}
static int F_59 ( struct V_43 * V_44 , struct V_22 * V_15 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 ;
if ( ! F_34 ( V_15 ) )
return 0 ;
V_14 = F_6 ( V_15 -> V_69 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_47 . V_48 . V_49 !=
& V_50 . V_49 )
return 0 ;
V_46 = F_11 ( V_14 -> V_19 ) ;
return & V_46 -> V_75 . V_48 == V_44 ;
}
static void F_60 ( struct V_22 * V_15 )
{
struct V_65 * V_66 = F_36 ( V_15 ) ;
struct V_13 * V_14 = F_6 ( V_66 -> V_15 . V_69 ) ;
struct V_45 * V_46 = F_11 ( V_14 -> V_19 ) ;
if ( V_46 -> V_20 -> V_76 )
V_46 -> V_20 -> V_76 ( V_66 ) ;
F_61 ( V_15 -> V_69 ) ;
F_45 ( V_66 ) ;
}
struct V_65 * F_62 ( struct V_22 * V_69 , int V_77 )
{
struct V_13 * V_14 = F_6 ( V_69 ) ;
struct V_65 * V_66 ;
V_66 = F_43 ( sizeof( * V_66 ) , V_57 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_77 = V_77 ;
V_66 -> V_71 = 1 ;
F_63 ( & V_66 -> V_15 ) ;
V_66 -> V_15 . V_69 = F_64 ( V_69 ) ;
V_66 -> V_15 . V_78 = F_60 ;
F_24 ( & V_66 -> V_79 ) ;
if ( F_65 ( V_69 ) ) {
struct V_4 * V_5 = F_8 ( V_69 ) ;
F_66 ( & V_66 -> V_15 , L_7 , V_14 -> V_29 ,
V_5 -> V_80 , V_77 ) ;
} else
F_66 ( & V_66 -> V_15 , L_8 , V_14 -> V_29 , V_77 ) ;
F_67 ( & V_66 -> V_15 ) ;
return V_66 ;
}
int F_68 ( struct V_65 * V_66 )
{
int error ;
error = F_69 ( & V_66 -> V_15 ) ;
if ( ! error ) {
F_70 ( & V_66 -> V_15 ) ;
F_71 ( & V_66 -> V_15 ) ;
}
return error ;
}
void F_72 ( struct V_65 * V_66 )
{
F_73 ( & V_66 -> V_15 ) ;
F_61 ( & V_66 -> V_15 ) ;
}
void
F_35 ( struct V_65 * V_66 )
{
struct V_22 * V_15 = & V_66 -> V_15 ;
F_3 ( ! F_74 ( & V_66 -> V_79 ) ) ;
F_75 ( V_15 ) ;
F_76 ( V_15 ) ;
F_73 ( V_15 ) ;
F_61 ( V_15 ) ;
}
int F_34 ( const struct V_22 * V_15 )
{
return V_15 -> V_78 == F_60 ;
}
static int F_77 ( struct V_43 * V_44 , struct V_22 * V_15 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 ;
if ( ! F_31 ( V_15 ) )
return 0 ;
V_14 = F_6 ( V_15 -> V_69 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_47 . V_48 . V_49 !=
& V_50 . V_49 )
return 0 ;
V_46 = F_11 ( V_14 -> V_19 ) ;
return & V_46 -> V_81 . V_48 == V_44 ;
}
static void F_78 ( struct V_22 * V_15 )
{
struct V_82 * V_83 = F_33 ( V_15 ) ;
F_3 ( ! F_74 ( & V_83 -> V_84 ) ) ;
F_61 ( V_15 -> V_69 ) ;
F_45 ( V_83 ) ;
}
static void F_79 ( struct V_82 * V_83 ,
struct V_65 * V_66 )
{
int V_85 ;
V_85 = F_80 ( & V_83 -> V_15 . V_86 , & V_66 -> V_15 . V_86 ,
F_18 ( & V_66 -> V_15 ) ) ;
if ( V_85 )
goto V_87;
V_85 = F_80 ( & V_66 -> V_15 . V_86 , & V_83 -> V_15 . V_86 , L_9 ) ;
if ( V_85 )
goto V_87;
return;
V_87:
F_16 ( V_42 L_10 ,
V_88 , V_85 ) ;
}
static void F_81 ( struct V_82 * V_83 ,
struct V_65 * V_66 )
{
F_82 ( & V_83 -> V_15 . V_86 , F_18 ( & V_66 -> V_15 ) ) ;
F_82 ( & V_66 -> V_15 . V_86 , L_9 ) ;
}
struct V_82 * F_83 ( struct V_22 * V_69 , int V_89 )
{
struct V_13 * V_14 = F_6 ( V_69 ) ;
struct V_82 * V_83 ;
V_83 = F_43 ( sizeof( * V_83 ) , V_57 ) ;
if ( ! V_83 )
return NULL ;
V_83 -> V_90 = V_89 ;
F_63 ( & V_83 -> V_15 ) ;
V_83 -> V_15 . V_69 = F_64 ( V_69 ) ;
V_83 -> V_15 . V_78 = F_78 ;
F_25 ( & V_83 -> V_91 ) ;
F_24 ( & V_83 -> V_84 ) ;
if ( F_65 ( V_69 ) ) {
struct V_4 * V_5 = F_8 ( V_69 ) ;
F_66 ( & V_83 -> V_15 , L_11 , V_14 -> V_29 ,
V_5 -> V_80 , V_83 -> V_90 ) ;
} else
F_66 ( & V_83 -> V_15 , L_12 , V_14 -> V_29 ,
V_83 -> V_90 ) ;
F_67 ( & V_83 -> V_15 ) ;
return V_83 ;
}
struct V_82 * F_84 ( struct V_22 * V_69 )
{
int V_92 ;
struct V_13 * V_14 = F_6 ( V_69 ) ;
struct V_23 * V_24 = F_13 ( V_14 ) ;
F_85 ( & V_24 -> V_38 ) ;
if ( F_65 ( V_69 ) ) {
struct V_4 * V_5 = F_8 ( V_69 ) ;
struct V_93 * exp = F_86 ( V_5 ) ;
V_92 = exp -> V_41 ++ ;
} else
V_92 = V_24 -> V_41 ++ ;
F_87 ( & V_24 -> V_38 ) ;
return F_83 ( V_69 , V_92 ) ;
}
int F_88 ( struct V_82 * V_83 )
{
int error ;
F_3 ( ! F_74 ( & V_83 -> V_84 ) ) ;
error = F_69 ( & V_83 -> V_15 ) ;
if ( error )
return error ;
F_70 ( & V_83 -> V_15 ) ;
F_71 ( & V_83 -> V_15 ) ;
return 0 ;
}
void F_89 ( struct V_82 * V_83 )
{
F_73 ( & V_83 -> V_15 ) ;
F_61 ( & V_83 -> V_15 ) ;
}
void F_32 ( struct V_82 * V_83 )
{
struct V_22 * V_15 = & V_83 -> V_15 ;
struct V_65 * V_66 , * V_94 ;
if ( V_83 -> V_5 ) {
F_90 ( V_83 -> V_5 ) ;
V_83 -> V_5 = NULL ;
}
F_85 ( & V_83 -> V_91 ) ;
F_91 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_81 ( V_83 , V_66 ) ;
F_92 ( & V_66 -> V_79 ) ;
}
F_87 ( & V_83 -> V_91 ) ;
if ( V_83 -> V_95 ) {
struct V_22 * V_69 = V_83 -> V_15 . V_69 ;
F_82 ( & V_83 -> V_15 . V_86 , F_18 ( V_69 ) ) ;
V_83 -> V_95 = 0 ;
}
F_75 ( V_15 ) ;
F_76 ( V_15 ) ;
F_73 ( V_15 ) ;
F_61 ( V_15 ) ;
}
int F_31 ( const struct V_22 * V_15 )
{
return V_15 -> V_78 == F_78 ;
}
struct V_65 * F_93 ( struct V_82 * V_83 )
{
struct V_65 * V_66 ;
F_85 ( & V_83 -> V_91 ) ;
if ( F_74 ( & V_83 -> V_84 ) )
V_66 = NULL ;
else {
struct V_96 * V_97 = V_83 -> V_84 . V_98 ;
V_66 = F_94 ( V_97 , F_95 ( * V_66 ) , V_79 ) ;
F_64 ( & V_66 -> V_15 ) ;
}
F_87 ( & V_83 -> V_91 ) ;
return V_66 ;
}
void F_96 ( struct V_82 * V_83 , struct V_65 * V_66 )
{
F_85 ( & V_83 -> V_91 ) ;
if ( F_97 ( ! F_74 ( & V_66 -> V_79 ) ) ) {
struct V_65 * V_99 ;
F_98 (tmp, &port->phy_list, port_siblings)
if ( V_99 == V_66 )
break;
if ( F_97 ( V_99 != V_66 ) ) {
F_26 ( V_42 , & V_83 -> V_15 , L_13 ,
F_18 ( & V_66 -> V_15 ) ) ;
F_99 () ;
}
} else {
F_79 ( V_83 , V_66 ) ;
F_100 ( & V_66 -> V_79 , & V_83 -> V_84 ) ;
V_83 -> V_100 ++ ;
}
F_87 ( & V_83 -> V_91 ) ;
}
void F_101 ( struct V_82 * V_83 , struct V_65 * V_66 )
{
F_85 ( & V_83 -> V_91 ) ;
F_81 ( V_83 , V_66 ) ;
F_92 ( & V_66 -> V_79 ) ;
V_83 -> V_100 -- ;
F_87 ( & V_83 -> V_91 ) ;
}
void F_102 ( struct V_82 * V_83 )
{
int V_85 ;
struct V_22 * V_69 = V_83 -> V_15 . V_69 -> V_69 -> V_69 ;
if ( V_83 -> V_95 )
return;
V_83 -> V_95 = 1 ;
V_85 = F_80 ( & V_83 -> V_15 . V_86 , & V_69 -> V_86 ,
F_18 ( V_69 ) ) ;
if ( V_85 )
goto V_87;
return;
V_87:
F_16 ( V_42 L_14 ,
V_88 , V_85 ) ;
}
static T_2
F_103 ( struct V_22 * V_15 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_5 = F_104 ( V_15 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_64 , 20 , L_5 ) ;
return F_51 (
V_5 -> V_8 . V_9 , V_64 ) ;
}
static T_2
F_105 ( struct V_22 * V_15 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_5 = F_104 ( V_15 ) ;
struct V_65 * V_66 = F_36 ( V_5 -> V_15 . V_69 ) ;
struct V_13 * V_14 = F_6 ( V_66 -> V_15 . V_69 ) ;
struct V_45 * V_46 = F_11 ( V_14 -> V_19 ) ;
T_1 V_101 ;
int error ;
error = V_46 -> V_20 -> V_102 ( V_5 , & V_101 ) ;
if ( error )
return error ;
return sprintf ( V_64 , L_15 , ( unsigned long long ) V_101 ) ;
}
static T_2
F_106 ( struct V_22 * V_15 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_5 = F_104 ( V_15 ) ;
struct V_65 * V_66 = F_36 ( V_5 -> V_15 . V_69 ) ;
struct V_13 * V_14 = F_6 ( V_66 -> V_15 . V_69 ) ;
struct V_45 * V_46 = F_11 ( V_14 -> V_19 ) ;
int V_103 ;
V_103 = V_46 -> V_20 -> V_104 ( V_5 ) ;
if ( V_103 < 0 )
return V_103 ;
return sprintf ( V_64 , L_16 , V_103 ) ;
}
int F_107 ( struct V_2 * V_3 )
{
char * V_56 = F_43 ( V_105 , V_57 ) , * V_106 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_107 V_108 ;
int V_85 , error ;
if ( ! V_56 )
return - V_109 ;
V_85 = F_108 ( V_3 , 1 , 0x19 , V_56 , V_105 , 30 * V_110 , 3 ,
& V_108 , NULL ) ;
error = - V_18 ;
if ( ! F_109 ( V_85 ) )
goto V_59;
V_106 = V_56 + V_108 . V_111 +
V_108 . V_112 ;
if ( V_106 - V_56 > V_105 - 8 )
goto V_59;
error = 0 ;
V_7 -> V_113 = V_106 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_114 = ( V_106 [ 4 ] << 8 ) + V_106 [ 5 ] ;
V_7 -> V_115 = ( V_106 [ 6 ] << 8 ) + V_106 [ 7 ] ;
V_59:
F_45 ( V_56 ) ;
return error ;
}
static int F_110 ( struct V_43 * V_44 , struct V_22 * V_15 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 ;
if ( ! F_111 ( V_15 ) )
return 0 ;
V_14 = F_6 ( V_15 -> V_69 -> V_69 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_47 . V_48 . V_49 !=
& V_50 . V_49 )
return 0 ;
V_46 = F_11 ( V_14 -> V_19 ) ;
return & V_46 -> V_116 . V_48 == V_44 ;
}
static int F_112 ( struct V_43 * V_44 ,
struct V_22 * V_15 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 ;
struct V_4 * V_5 ;
if ( ! F_111 ( V_15 ) )
return 0 ;
V_14 = F_6 ( V_15 -> V_69 -> V_69 ) ;
V_5 = F_8 ( V_15 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_47 . V_48 . V_49 !=
& V_50 . V_49 )
return 0 ;
V_46 = F_11 ( V_14 -> V_19 ) ;
return & V_46 -> V_117 . V_48 == V_44 &&
V_5 -> V_8 . V_9 == V_10 ;
}
static int F_113 ( struct V_43 * V_44 ,
struct V_22 * V_15 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 ;
struct V_4 * V_5 ;
if ( ! F_111 ( V_15 ) )
return 0 ;
V_14 = F_6 ( V_15 -> V_69 -> V_69 ) ;
V_5 = F_8 ( V_15 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_47 . V_48 . V_49 !=
& V_50 . V_49 )
return 0 ;
V_46 = F_11 ( V_14 -> V_19 ) ;
return & V_46 -> V_118 . V_48 == V_44 &&
( V_5 -> V_8 . V_9 == V_119 ||
V_5 -> V_8 . V_9 == V_120 ) ;
}
static void F_114 ( struct V_22 * V_15 )
{
struct V_4 * V_5 = F_8 ( V_15 ) ;
struct V_93 * V_121 = F_86 ( V_5 ) ;
if ( V_5 -> V_26 )
F_14 ( V_5 -> V_26 ) ;
F_61 ( V_15 -> V_69 ) ;
F_45 ( V_121 ) ;
}
static void F_115 ( struct V_22 * V_15 )
{
struct V_4 * V_5 = F_8 ( V_15 ) ;
struct V_1 * V_121 = F_4 ( V_5 ) ;
if ( V_5 -> V_26 )
F_14 ( V_5 -> V_26 ) ;
F_61 ( V_15 -> V_69 ) ;
F_45 ( V_121 ) ;
}
static void F_116 ( struct V_4 * V_5 )
{
F_24 ( & V_5 -> V_122 ) ;
}
struct V_4 * F_117 ( struct V_82 * V_69 )
{
struct V_13 * V_14 = F_6 ( & V_69 -> V_15 ) ;
struct V_1 * V_7 ;
V_7 = F_43 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_63 ( & V_7 -> V_5 . V_15 ) ;
V_7 -> V_5 . V_15 . V_69 = F_64 ( & V_69 -> V_15 ) ;
V_7 -> V_5 . V_15 . V_78 = F_115 ;
if ( F_65 ( V_69 -> V_15 . V_69 ) ) {
struct V_4 * V_5 = F_8 ( V_69 -> V_15 . V_69 ) ;
F_66 ( & V_7 -> V_5 . V_15 , L_17 ,
V_14 -> V_29 , V_5 -> V_80 ,
V_69 -> V_90 ) ;
} else
F_66 ( & V_7 -> V_5 . V_15 , L_18 ,
V_14 -> V_29 , V_69 -> V_90 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_116 ( & V_7 -> V_5 ) ;
F_67 ( & V_7 -> V_5 . V_15 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_118 ( struct V_82 * V_69 ,
enum V_123 type )
{
struct V_13 * V_14 = F_6 ( & V_69 -> V_15 ) ;
struct V_93 * V_7 ;
struct V_23 * V_24 = F_13 ( V_14 ) ;
F_3 ( type != V_119 &&
type != V_120 ) ;
V_7 = F_43 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_63 ( & V_7 -> V_5 . V_15 ) ;
V_7 -> V_5 . V_15 . V_69 = F_64 ( & V_69 -> V_15 ) ;
V_7 -> V_5 . V_15 . V_78 = F_114 ;
F_85 ( & V_24 -> V_38 ) ;
V_7 -> V_5 . V_80 = V_24 -> V_40 ++ ;
F_87 ( & V_24 -> V_38 ) ;
F_66 ( & V_7 -> V_5 . V_15 , L_19 ,
V_14 -> V_29 , V_7 -> V_5 . V_80 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_116 ( & V_7 -> V_5 ) ;
F_67 ( & V_7 -> V_5 . V_15 ) ;
return & V_7 -> V_5 ;
}
int F_119 ( struct V_4 * V_5 )
{
struct V_82 * V_69 = F_33 ( V_5 -> V_15 . V_69 ) ;
struct V_13 * V_14 = F_6 ( V_69 -> V_15 . V_69 ) ;
struct V_23 * V_24 = F_13 ( V_14 ) ;
struct V_124 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_69 -> V_5 )
return - V_125 ;
V_69 -> V_5 = V_5 ;
error = F_69 ( & V_5 -> V_15 ) ;
if ( error )
return error ;
F_70 ( & V_5 -> V_15 ) ;
F_71 ( & V_5 -> V_15 ) ;
if ( F_15 ( V_14 , V_5 ) )
F_16 ( L_20 , F_18 ( & V_5 -> V_15 ) ) ;
F_85 ( & V_24 -> V_38 ) ;
F_100 ( & V_5 -> V_122 , & V_24 -> V_37 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_126 &
( V_127 | V_128 | V_129 ) ) )
V_5 -> V_80 = V_24 -> V_39 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_80 = - 1 ;
F_87 ( & V_24 -> V_38 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_80 != - 1 ) {
int V_130 ;
if ( V_8 -> V_126 & V_127 )
V_130 = V_131 ;
else
V_130 = 0 ;
F_120 ( & V_5 -> V_15 , 0 , V_5 -> V_80 , V_130 ,
V_132 ) ;
}
return 0 ;
}
void F_121 ( struct V_4 * V_5 )
{
struct V_22 * V_15 = & V_5 -> V_15 ;
struct V_13 * V_14 = F_6 ( V_5 -> V_15 . V_69 -> V_69 ) ;
struct V_23 * V_24 = F_13 ( V_14 ) ;
F_85 ( & V_24 -> V_38 ) ;
F_122 ( & V_5 -> V_122 ) ;
F_87 ( & V_24 -> V_38 ) ;
F_73 ( V_15 ) ;
F_61 ( V_15 ) ;
}
void
F_90 ( struct V_4 * V_5 )
{
F_123 ( V_5 ) ;
F_121 ( V_5 ) ;
}
void F_124 ( struct V_4 * V_5 )
{
struct V_82 * V_69 = F_33 ( V_5 -> V_15 . V_69 ) ;
V_69 -> V_5 = NULL ;
}
void
F_123 ( struct V_4 * V_5 )
{
struct V_22 * V_15 = & V_5 -> V_15 ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_125 ( V_15 ) ;
break;
case V_119 :
case V_120 :
F_37 ( V_15 ) ;
break;
default:
break;
}
F_124 ( V_5 ) ;
if ( V_5 -> V_26 )
F_28 ( V_5 -> V_26 ) ;
F_75 ( V_15 ) ;
F_76 ( V_15 ) ;
}
int F_111 ( const struct V_22 * V_15 )
{
return V_15 -> V_78 == F_115 ||
V_15 -> V_78 == F_114 ;
}
static int F_126 ( struct V_13 * V_14 , T_4 V_133 ,
T_4 V_134 , T_1 V_130 )
{
struct V_23 * V_24 = F_13 ( V_14 ) ;
struct V_4 * V_5 ;
F_85 ( & V_24 -> V_38 ) ;
F_98 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_80 == - 1 )
continue;
if ( ( V_133 == V_131 || V_133 == 0 ) &&
( V_134 == V_131 || V_134 == V_5 -> V_80 ) ) {
F_120 ( & V_5 -> V_15 , 0 , V_5 -> V_80 ,
V_130 , V_135 ) ;
}
}
F_87 ( & V_24 -> V_38 ) ;
return 0 ;
}
struct V_136 *
F_127 ( struct V_137 * V_138 )
{
struct V_45 * V_46 ;
int V_67 ;
V_46 = F_43 ( sizeof( struct V_45 ) , V_57 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_51 . V_139 = F_126 ;
V_46 -> V_51 . V_47 . V_48 . V_140 = & V_46 -> V_47 [ 0 ] ;
V_46 -> V_51 . V_47 . V_48 . V_49 = & V_50 . V_49 ;
V_46 -> V_51 . V_47 . V_48 . V_141 = F_29 ;
F_128 ( & V_46 -> V_51 . V_47 ) ;
V_46 -> V_51 . V_142 = sizeof( struct V_23 ) ;
V_46 -> V_75 . V_48 . V_49 = & V_143 . V_49 ;
V_46 -> V_75 . V_48 . V_140 = & V_46 -> V_144 [ 0 ] ;
V_46 -> V_75 . V_48 . V_141 = F_59 ;
F_128 ( & V_46 -> V_75 ) ;
V_46 -> V_81 . V_48 . V_49 = & V_145 . V_49 ;
V_46 -> V_81 . V_48 . V_140 = & V_46 -> V_146 [ 0 ] ;
V_46 -> V_81 . V_48 . V_141 = F_77 ;
F_128 ( & V_46 -> V_81 ) ;
V_46 -> V_116 . V_48 . V_49 = & V_147 . V_49 ;
V_46 -> V_116 . V_48 . V_140 = & V_46 -> V_148 [ 0 ] ;
V_46 -> V_116 . V_48 . V_141 = F_110 ;
F_128 ( & V_46 -> V_116 ) ;
V_46 -> V_117 . V_48 . V_49 = & V_149 . V_49 ;
V_46 -> V_117 . V_48 . V_140 = & V_46 -> V_150 [ 0 ] ;
V_46 -> V_117 . V_48 . V_141 = F_112 ;
F_128 ( & V_46 -> V_117 ) ;
V_46 -> V_118 . V_48 . V_49 = & V_151 . V_49 ;
V_46 -> V_118 . V_48 . V_140 = & V_46 -> V_152 [ 0 ] ;
V_46 -> V_118 . V_48 . V_141 = F_113 ;
F_128 ( & V_46 -> V_118 ) ;
V_46 -> V_20 = V_138 ;
V_67 = 0 ;
F_129 ( V_153 ) ;
F_129 ( V_126 ) ;
F_129 ( V_9 ) ;
F_129 ( V_54 ) ;
F_129 ( V_154 ) ;
F_129 ( V_155 ) ;
F_129 ( V_156 ) ;
F_130 ( V_157 ) ;
F_129 ( V_158 ) ;
F_130 ( V_159 ) ;
F_129 ( V_160 ) ;
F_129 ( V_161 ) ;
F_129 ( V_162 ) ;
F_129 ( V_163 ) ;
F_131 ( V_164 , V_73 ) ;
F_131 ( V_72 , V_73 ) ;
F_132 ( V_68 , V_70 ) ;
V_46 -> V_144 [ V_67 ] = NULL ;
V_67 = 0 ;
F_133 ( V_100 ) ;
V_46 -> V_146 [ V_67 ] = NULL ;
V_67 = 0 ;
F_134 ( V_165 ) ;
F_134 ( V_166 ) ;
F_134 ( V_167 ) ;
F_134 ( V_168 ) ;
F_134 ( V_169 ) ;
F_134 ( V_170 ) ;
F_135 ( V_171 ,
V_102 ) ;
F_135 ( V_172 ,
V_104 ) ;
V_46 -> V_148 [ V_67 ] = NULL ;
V_67 = 0 ;
F_136 ( V_173 ) ;
F_136 ( V_174 ) ;
F_136 ( V_175 ) ;
F_136 ( V_176 ) ;
F_136 ( V_177 ) ;
V_46 -> V_150 [ V_67 ] = NULL ;
V_67 = 0 ;
F_137 ( V_178 ) ;
F_137 ( V_179 ) ;
F_137 ( V_180 ) ;
F_137 ( V_181 ) ;
F_137 ( V_182 ) ;
F_137 ( V_183 ) ;
F_137 ( V_184 ) ;
V_46 -> V_152 [ V_67 ] = NULL ;
return & V_46 -> V_51 ;
}
void F_138 ( struct V_136 * V_51 )
{
struct V_45 * V_46 = F_11 ( V_51 ) ;
F_139 ( & V_46 -> V_51 . V_47 ) ;
F_139 ( & V_46 -> V_75 ) ;
F_139 ( & V_46 -> V_81 ) ;
F_139 ( & V_46 -> V_116 ) ;
F_139 ( & V_46 -> V_117 ) ;
F_139 ( & V_46 -> V_118 ) ;
F_45 ( V_46 ) ;
}
static T_5 int F_140 ( void )
{
int error ;
error = F_141 ( & V_50 ) ;
if ( error )
goto V_59;
error = F_141 ( & V_143 ) ;
if ( error )
goto V_185;
error = F_141 ( & V_145 ) ;
if ( error )
goto V_186;
error = F_141 ( & V_147 ) ;
if ( error )
goto V_187;
error = F_141 ( & V_149 ) ;
if ( error )
goto V_188;
error = F_141 ( & V_151 ) ;
if ( error )
goto V_189;
return 0 ;
V_189:
F_142 ( & V_149 ) ;
V_188:
F_142 ( & V_147 ) ;
V_187:
F_142 ( & V_145 ) ;
V_186:
F_142 ( & V_143 ) ;
V_185:
F_142 ( & V_50 ) ;
V_59:
return error ;
}
static void T_6 F_143 ( void )
{
F_142 ( & V_50 ) ;
F_142 ( & V_143 ) ;
F_142 ( & V_145 ) ;
F_142 ( & V_147 ) ;
F_142 ( & V_149 ) ;
F_142 ( & V_151 ) ;
}
