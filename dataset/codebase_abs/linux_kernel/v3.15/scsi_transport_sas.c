static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_1 * V_7 ;
F_3 ( V_5 -> V_8 . V_9 != V_10 ) ;
V_7 = F_4 ( V_5 ) ;
return V_7 ;
}
static void F_5 ( struct V_11 * V_12 , struct V_13 * V_14 ,
struct V_4 * V_5 )
{
struct V_15 * V_16 ;
int V_17 ;
int (* F_6)( struct V_13 * , struct V_4 * , struct V_15 * );
while ( ( V_16 = F_7 ( V_12 ) ) != NULL ) {
F_8 ( V_12 -> V_18 ) ;
F_6 = F_9 ( V_14 -> V_19 ) -> V_20 -> V_21 ;
V_17 = F_6 ( V_14 , V_5 , V_16 ) ;
V_16 -> V_22 = V_17 ;
F_10 ( V_16 , V_17 ) ;
F_11 ( V_12 -> V_18 ) ;
}
}
static void F_12 ( struct V_11 * V_12 )
{
F_5 ( V_12 , (struct V_13 * ) V_12 -> V_23 , NULL ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_23 ;
F_5 ( V_12 , F_14 ( V_5 ) , V_5 ) ;
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_16 ( V_25 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_11 * V_12 = V_27 -> V_12 ;
if ( V_12 )
F_18 ( V_12 ) ;
}
static int F_19 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_11 * V_12 ;
int error ;
struct V_24 * V_25 ;
char V_28 [ 20 ] ;
const char * V_29 ;
void (* F_20)( struct V_24 * );
if ( ! F_9 ( V_14 -> V_19 ) -> V_20 -> V_21 ) {
F_21 ( L_1 , V_14 -> V_30 -> V_29 ) ;
return 0 ;
}
if ( V_5 ) {
V_12 = F_22 ( F_13 , NULL ) ;
V_25 = & V_5 -> V_25 ;
V_29 = F_23 ( V_25 ) ;
F_20 = NULL ;
} else {
V_12 = F_22 ( F_12 , NULL ) ;
V_25 = & V_14 -> V_31 ;
snprintf ( V_28 , sizeof( V_28 ) ,
L_2 , V_14 -> V_32 ) ;
V_29 = V_28 ;
F_20 = F_15 ;
}
if ( ! V_12 )
return - V_33 ;
error = F_24 ( V_12 , V_25 , V_29 , F_20 ) ;
if ( error ) {
F_18 ( V_12 ) ;
return - V_33 ;
}
if ( V_5 )
V_5 -> V_12 = V_12 ;
else
F_17 ( V_14 ) -> V_12 = V_12 ;
if ( V_5 )
V_12 -> V_23 = V_5 ;
else
V_12 -> V_23 = V_14 ;
F_25 ( V_34 , V_12 ) ;
return 0 ;
}
static void F_26 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_11 * V_12 ;
if ( V_5 )
V_12 = V_5 -> V_12 ;
else
V_12 = F_17 ( V_14 ) -> V_12 ;
if ( ! V_12 )
return;
F_27 ( V_12 ) ;
}
static int F_28 ( struct V_35 * V_36 , struct V_24 * V_25 ,
struct V_24 * V_37 )
{
struct V_13 * V_14 = F_16 ( V_25 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_29 ( & V_27 -> V_38 ) ;
F_30 ( & V_27 -> V_39 ) ;
V_27 -> V_40 = 0 ;
V_27 -> V_41 = 0 ;
V_27 -> V_42 = 0 ;
if ( F_19 ( V_14 , NULL ) )
F_31 ( V_43 , V_25 , L_3 ,
V_14 -> V_32 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_36 , struct V_24 * V_25 ,
struct V_24 * V_37 )
{
struct V_13 * V_14 = F_16 ( V_25 ) ;
F_26 ( V_14 , NULL ) ;
return 0 ;
}
static int F_33 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_34 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_52 . V_48 . V_49 == V_45 ;
}
static int F_35 ( struct V_24 * V_25 , void * V_53 )
{
int V_54 = ( int ) ( unsigned long ) V_53 ;
if ( V_54 == 0 && F_36 ( V_25 ) )
F_37 ( F_38 ( V_25 ) ) ;
else if ( V_54 == 1 && F_39 ( V_25 ) )
F_40 ( F_41 ( V_25 ) ) ;
return 0 ;
}
void F_42 ( struct V_24 * V_25 )
{
F_43 ( V_25 , ( void * ) 0 , F_35 ) ;
F_43 ( V_25 , ( void * ) 1 , F_35 ) ;
}
void F_44 ( struct V_13 * V_14 )
{
F_42 ( & V_14 -> V_31 ) ;
}
unsigned int
F_45 ( struct V_2 * V_3 )
{
const int V_55 = 32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
char * V_56 = F_46 ( V_55 , V_57 ) ;
int V_17 = 0 ;
if ( F_47 ( V_3 , 0x90 , V_56 , V_55 ) )
goto V_58;
V_17 = V_56 [ 12 ] & 0x01 ;
V_58:
F_48 ( V_56 ) ;
V_7 -> V_59 = V_17 ;
return V_17 ;
}
void
F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_60 = 0 ;
}
void F_50 ( struct V_2 * V_3 )
{
unsigned int V_59 = 0 ;
V_59 = F_45 ( V_3 ) ;
if ( V_59 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_60 = 1 ;
}
return;
}
unsigned int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_60 ;
}
static T_1
F_52 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_64 * V_65 = F_53 ( V_25 ) ;
if ( ! V_65 -> V_8 . V_9 )
return snprintf ( V_63 , 20 , L_4 ) ;
return F_54 ( V_65 -> V_8 . V_9 , V_63 ) ;
}
static T_1 F_55 ( struct V_24 * V_25 ,
T_2 V_66 , int V_67 )
{
struct V_64 * V_65 = F_53 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int error ;
error = V_47 -> V_20 -> V_69 ( V_65 , V_67 ) ;
if ( error )
return error ;
V_65 -> V_70 = V_67 ;
return V_66 ;
}
static T_1
F_56 ( struct V_24 * V_25 , struct V_61 * V_62 ,
const char * V_63 , T_2 V_66 )
{
if ( V_66 < 1 )
return - V_71 ;
switch ( V_63 [ 0 ] ) {
case '0' :
F_55 ( V_25 , V_66 , 0 ) ;
break;
case '1' :
F_55 ( V_25 , V_66 , 1 ) ;
break;
default:
return - V_71 ;
}
return V_66 ;
}
static T_1
F_57 ( struct V_24 * V_25 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_64 * V_65 = F_53 ( V_25 ) ;
return snprintf ( V_63 , 20 , L_5 , V_65 -> V_70 ) ;
}
static T_1
F_58 ( struct V_24 * V_25 , T_2 V_66 , int V_72 )
{
struct V_64 * V_65 = F_53 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int error ;
error = V_47 -> V_20 -> V_73 ( V_65 , V_72 ) ;
if ( error )
return error ;
V_65 -> V_70 = 1 ;
return V_66 ;
}
static T_1
F_59 ( struct V_24 * V_25 , struct V_61 * V_62 ,
const char * V_63 , T_2 V_66 )
{
return F_58 ( V_25 , V_66 , 0 ) ;
}
static T_1
F_60 ( struct V_24 * V_25 , struct V_61 * V_62 ,
const char * V_63 , T_2 V_66 )
{
return F_58 ( V_25 , V_66 , 1 ) ;
}
static int F_61 ( struct V_35 * V_36 , struct V_24 * V_25 ,
struct V_24 * V_37 )
{
struct V_64 * V_65 = F_41 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
if ( V_47 -> V_20 -> V_74 )
V_47 -> V_20 -> V_74 ( V_65 ) ;
return 0 ;
}
static int F_62 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_39 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_75 . V_49 == V_45 ;
}
static void F_63 ( struct V_24 * V_25 )
{
struct V_64 * V_65 = F_41 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
if ( V_47 -> V_20 -> V_76 )
V_47 -> V_20 -> V_76 ( V_65 ) ;
F_64 ( V_25 -> V_68 ) ;
F_48 ( V_65 ) ;
}
struct V_64 * F_65 ( struct V_24 * V_68 , int V_77 )
{
struct V_13 * V_14 = F_16 ( V_68 ) ;
struct V_64 * V_65 ;
V_65 = F_46 ( sizeof( * V_65 ) , V_57 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> V_77 = V_77 ;
V_65 -> V_70 = 1 ;
F_66 ( & V_65 -> V_25 ) ;
V_65 -> V_25 . V_68 = F_67 ( V_68 ) ;
V_65 -> V_25 . F_20 = F_63 ;
F_29 ( & V_65 -> V_78 ) ;
if ( F_68 ( V_68 ) ) {
struct V_4 * V_5 = F_69 ( V_68 ) ;
F_70 ( & V_65 -> V_25 , L_6 , V_14 -> V_32 ,
V_5 -> V_79 , V_77 ) ;
} else
F_70 ( & V_65 -> V_25 , L_7 , V_14 -> V_32 , V_77 ) ;
F_71 ( & V_65 -> V_25 ) ;
return V_65 ;
}
int F_72 ( struct V_64 * V_65 )
{
int error ;
error = F_73 ( & V_65 -> V_25 ) ;
if ( ! error ) {
F_74 ( & V_65 -> V_25 ) ;
F_75 ( & V_65 -> V_25 ) ;
}
return error ;
}
void F_76 ( struct V_64 * V_65 )
{
F_77 ( & V_65 -> V_25 ) ;
F_64 ( & V_65 -> V_25 ) ;
}
void
F_40 ( struct V_64 * V_65 )
{
struct V_24 * V_25 = & V_65 -> V_25 ;
F_3 ( ! F_78 ( & V_65 -> V_78 ) ) ;
F_79 ( V_25 ) ;
F_80 ( V_25 ) ;
F_77 ( V_25 ) ;
F_64 ( V_25 ) ;
}
int F_39 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_63 ;
}
static int F_81 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_36 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_80 . V_49 == V_45 ;
}
static void F_82 ( struct V_24 * V_25 )
{
struct V_81 * V_82 = F_38 ( V_25 ) ;
F_3 ( ! F_78 ( & V_82 -> V_83 ) ) ;
F_64 ( V_25 -> V_68 ) ;
F_48 ( V_82 ) ;
}
static void F_83 ( struct V_81 * V_82 ,
struct V_64 * V_65 )
{
int V_84 ;
V_84 = F_84 ( & V_82 -> V_25 . V_85 , & V_65 -> V_25 . V_85 ,
F_23 ( & V_65 -> V_25 ) ) ;
if ( V_84 )
goto V_86;
V_84 = F_84 ( & V_65 -> V_25 . V_85 , & V_82 -> V_25 . V_85 , L_8 ) ;
if ( V_84 )
goto V_86;
return;
V_86:
F_21 ( V_43 L_9 ,
V_87 , V_84 ) ;
}
static void F_85 ( struct V_81 * V_82 ,
struct V_64 * V_65 )
{
F_86 ( & V_82 -> V_25 . V_85 , F_23 ( & V_65 -> V_25 ) ) ;
F_86 ( & V_65 -> V_25 . V_85 , L_8 ) ;
}
struct V_81 * F_87 ( struct V_24 * V_68 , int V_88 )
{
struct V_13 * V_14 = F_16 ( V_68 ) ;
struct V_81 * V_82 ;
V_82 = F_46 ( sizeof( * V_82 ) , V_57 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_89 = V_88 ;
F_66 ( & V_82 -> V_25 ) ;
V_82 -> V_25 . V_68 = F_67 ( V_68 ) ;
V_82 -> V_25 . F_20 = F_82 ;
F_30 ( & V_82 -> V_90 ) ;
F_29 ( & V_82 -> V_83 ) ;
if ( F_68 ( V_68 ) ) {
struct V_4 * V_5 = F_69 ( V_68 ) ;
F_70 ( & V_82 -> V_25 , L_10 , V_14 -> V_32 ,
V_5 -> V_79 , V_82 -> V_89 ) ;
} else
F_70 ( & V_82 -> V_25 , L_11 , V_14 -> V_32 ,
V_82 -> V_89 ) ;
F_71 ( & V_82 -> V_25 ) ;
return V_82 ;
}
struct V_81 * F_88 ( struct V_24 * V_68 )
{
int V_91 ;
struct V_13 * V_14 = F_16 ( V_68 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_89 ( & V_27 -> V_39 ) ;
if ( F_68 ( V_68 ) ) {
struct V_4 * V_5 = F_69 ( V_68 ) ;
struct V_92 * exp = F_90 ( V_5 ) ;
V_91 = exp -> V_42 ++ ;
} else
V_91 = V_27 -> V_42 ++ ;
F_91 ( & V_27 -> V_39 ) ;
return F_87 ( V_68 , V_91 ) ;
}
int F_92 ( struct V_81 * V_82 )
{
int error ;
F_3 ( ! F_78 ( & V_82 -> V_83 ) ) ;
error = F_73 ( & V_82 -> V_25 ) ;
if ( error )
return error ;
F_74 ( & V_82 -> V_25 ) ;
F_75 ( & V_82 -> V_25 ) ;
return 0 ;
}
void F_93 ( struct V_81 * V_82 )
{
F_77 ( & V_82 -> V_25 ) ;
F_64 ( & V_82 -> V_25 ) ;
}
void F_37 ( struct V_81 * V_82 )
{
struct V_24 * V_25 = & V_82 -> V_25 ;
struct V_64 * V_65 , * V_93 ;
if ( V_82 -> V_5 ) {
F_94 ( V_82 -> V_5 ) ;
V_82 -> V_5 = NULL ;
}
F_89 ( & V_82 -> V_90 ) ;
F_95 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_85 ( V_82 , V_65 ) ;
F_96 ( & V_65 -> V_78 ) ;
}
F_91 ( & V_82 -> V_90 ) ;
if ( V_82 -> V_94 ) {
struct V_24 * V_68 = V_82 -> V_25 . V_68 ;
F_86 ( & V_82 -> V_25 . V_85 , F_23 ( V_68 ) ) ;
V_82 -> V_94 = 0 ;
}
F_79 ( V_25 ) ;
F_80 ( V_25 ) ;
F_77 ( V_25 ) ;
F_64 ( V_25 ) ;
}
int F_36 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_82 ;
}
struct V_64 * F_97 ( struct V_81 * V_82 )
{
struct V_64 * V_65 ;
F_89 ( & V_82 -> V_90 ) ;
if ( F_78 ( & V_82 -> V_83 ) )
V_65 = NULL ;
else {
struct V_95 * V_96 = V_82 -> V_83 . V_97 ;
V_65 = F_98 ( V_96 , F_99 ( * V_65 ) , V_78 ) ;
F_67 ( & V_65 -> V_25 ) ;
}
F_91 ( & V_82 -> V_90 ) ;
return V_65 ;
}
void F_100 ( struct V_81 * V_82 , struct V_64 * V_65 )
{
F_89 ( & V_82 -> V_90 ) ;
if ( F_101 ( ! F_78 ( & V_65 -> V_78 ) ) ) {
struct V_64 * V_98 ;
F_102 (tmp, &port->phy_list, port_siblings)
if ( V_98 == V_65 )
break;
if ( F_101 ( V_98 != V_65 ) ) {
F_31 ( V_43 , & V_82 -> V_25 , L_12 ,
F_23 ( & V_65 -> V_25 ) ) ;
F_103 () ;
}
} else {
F_83 ( V_82 , V_65 ) ;
F_104 ( & V_65 -> V_78 , & V_82 -> V_83 ) ;
V_82 -> V_99 ++ ;
}
F_91 ( & V_82 -> V_90 ) ;
}
void F_105 ( struct V_81 * V_82 , struct V_64 * V_65 )
{
F_89 ( & V_82 -> V_90 ) ;
F_85 ( V_82 , V_65 ) ;
F_96 ( & V_65 -> V_78 ) ;
V_82 -> V_99 -- ;
F_91 ( & V_82 -> V_90 ) ;
}
void F_106 ( struct V_81 * V_82 )
{
int V_84 ;
struct V_24 * V_68 = V_82 -> V_25 . V_68 -> V_68 -> V_68 ;
if ( V_82 -> V_94 )
return;
V_82 -> V_94 = 1 ;
V_84 = F_84 ( & V_82 -> V_25 . V_85 , & V_68 -> V_85 ,
F_23 ( V_68 ) ) ;
if ( V_84 )
goto V_86;
return;
V_86:
F_21 ( V_43 L_13 ,
V_87 , V_84 ) ;
}
static T_1
F_107 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_4 * V_5 = F_108 ( V_25 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_63 , 20 , L_4 ) ;
return F_54 (
V_5 -> V_8 . V_9 , V_63 ) ;
}
static T_1
F_109 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_4 * V_5 = F_108 ( V_25 ) ;
struct V_64 * V_65 = F_41 ( V_5 -> V_25 . V_68 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
T_3 V_100 ;
int error ;
if ( F_110 ( V_65 ) )
return - V_71 ;
error = V_47 -> V_20 -> V_101 ( V_5 , & V_100 ) ;
if ( error )
return error ;
return sprintf ( V_63 , L_14 , ( unsigned long long ) V_100 ) ;
}
static T_1
F_111 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_4 * V_5 = F_108 ( V_25 ) ;
struct V_64 * V_65 = F_41 ( V_5 -> V_25 . V_68 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int V_102 ;
if ( F_110 ( V_65 ) )
return - V_71 ;
V_102 = V_47 -> V_20 -> V_103 ( V_5 ) ;
if ( V_102 < 0 )
return V_102 ;
return sprintf ( V_63 , L_15 , V_102 ) ;
}
int F_112 ( struct V_2 * V_3 )
{
char * V_56 = F_46 ( V_104 , V_57 ) , * V_105 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_106 V_107 ;
int V_84 , error ;
if ( ! V_56 )
return - V_33 ;
V_84 = F_113 ( V_3 , 1 , 0x19 , V_56 , V_104 , 30 * V_108 , 3 ,
& V_107 , NULL ) ;
error = - V_71 ;
if ( ! F_114 ( V_84 ) )
goto V_58;
V_105 = V_56 + V_107 . V_109 +
V_107 . V_110 ;
if ( V_105 - V_56 > V_104 - 8 )
goto V_58;
error = 0 ;
V_7 -> V_111 = V_105 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_112 = ( V_105 [ 4 ] << 8 ) + V_105 [ 5 ] ;
V_7 -> V_113 = ( V_105 [ 6 ] << 8 ) + V_105 [ 7 ] ;
V_58:
F_48 ( V_56 ) ;
return error ;
}
static int F_115 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_116 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 -> V_68 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_114 . V_49 == V_45 ;
}
static int F_117 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_116 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 -> V_68 ) ;
V_5 = F_69 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_115 . V_49 == V_45 &&
V_5 -> V_8 . V_9 == V_10 ;
}
static int F_118 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_116 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 -> V_68 ) ;
V_5 = F_69 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_116 . V_49 == V_45 &&
( V_5 -> V_8 . V_9 == V_117 ||
V_5 -> V_8 . V_9 == V_118 ) ;
}
static void F_119 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_69 ( V_25 ) ;
struct V_92 * V_119 = F_90 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_64 ( V_25 -> V_68 ) ;
F_48 ( V_119 ) ;
}
static void F_120 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_69 ( V_25 ) ;
struct V_1 * V_119 = F_4 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_64 ( V_25 -> V_68 ) ;
F_48 ( V_119 ) ;
}
static void F_121 ( struct V_4 * V_5 )
{
F_29 ( & V_5 -> V_120 ) ;
}
struct V_4 * F_122 ( struct V_81 * V_68 )
{
struct V_13 * V_14 = F_16 ( & V_68 -> V_25 ) ;
struct V_1 * V_7 ;
V_7 = F_46 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_66 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_68 = F_67 ( & V_68 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_120 ;
if ( F_68 ( V_68 -> V_25 . V_68 ) ) {
struct V_4 * V_5 = F_69 ( V_68 -> V_25 . V_68 ) ;
F_70 ( & V_7 -> V_5 . V_25 , L_16 ,
V_14 -> V_32 , V_5 -> V_79 ,
V_68 -> V_89 ) ;
} else
F_70 ( & V_7 -> V_5 . V_25 , L_17 ,
V_14 -> V_32 , V_68 -> V_89 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_121 ( & V_7 -> V_5 ) ;
F_71 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_123 ( struct V_81 * V_68 ,
enum V_121 type )
{
struct V_13 * V_14 = F_16 ( & V_68 -> V_25 ) ;
struct V_92 * V_7 ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_3 ( type != V_117 &&
type != V_118 ) ;
V_7 = F_46 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_66 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_68 = F_67 ( & V_68 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_119 ;
F_89 ( & V_27 -> V_39 ) ;
V_7 -> V_5 . V_79 = V_27 -> V_41 ++ ;
F_91 ( & V_27 -> V_39 ) ;
F_70 ( & V_7 -> V_5 . V_25 , L_18 ,
V_14 -> V_32 , V_7 -> V_5 . V_79 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_121 ( & V_7 -> V_5 ) ;
F_71 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
int F_124 ( struct V_4 * V_5 )
{
struct V_81 * V_68 = F_38 ( V_5 -> V_25 . V_68 ) ;
struct V_13 * V_14 = F_16 ( V_68 -> V_25 . V_68 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_122 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_68 -> V_5 )
return - V_123 ;
V_68 -> V_5 = V_5 ;
error = F_73 ( & V_5 -> V_25 ) ;
if ( error )
return error ;
F_74 ( & V_5 -> V_25 ) ;
F_75 ( & V_5 -> V_25 ) ;
if ( F_19 ( V_14 , V_5 ) )
F_21 ( L_19 , F_23 ( & V_5 -> V_25 ) ) ;
F_89 ( & V_27 -> V_39 ) ;
F_104 ( & V_5 -> V_120 , & V_27 -> V_38 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_124 &
( V_125 | V_126 | V_127 ) ) )
V_5 -> V_79 = V_27 -> V_40 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_79 = - 1 ;
F_91 ( & V_27 -> V_39 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_79 != - 1 ) {
int V_128 ;
if ( V_8 -> V_124 & V_125 )
V_128 = V_129 ;
else
V_128 = 0 ;
F_125 ( & V_5 -> V_25 , 0 , V_5 -> V_79 , V_128 , 0 ) ;
}
return 0 ;
}
void F_126 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
struct V_13 * V_14 = F_16 ( V_5 -> V_25 . V_68 -> V_68 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_89 ( & V_27 -> V_39 ) ;
F_127 ( & V_5 -> V_120 ) ;
F_91 ( & V_27 -> V_39 ) ;
F_77 ( V_25 ) ;
F_64 ( V_25 ) ;
}
void
F_94 ( struct V_4 * V_5 )
{
F_128 ( V_5 ) ;
F_126 ( V_5 ) ;
}
void F_129 ( struct V_4 * V_5 )
{
struct V_81 * V_68 = F_38 ( V_5 -> V_25 . V_68 ) ;
V_68 -> V_5 = NULL ;
}
void
F_128 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_130 ( V_25 ) ;
break;
case V_117 :
case V_118 :
F_42 ( V_25 ) ;
break;
default:
break;
}
F_129 ( V_5 ) ;
F_26 ( NULL , V_5 ) ;
F_79 ( V_25 ) ;
F_80 ( V_25 ) ;
}
int F_116 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_120 ||
V_25 -> F_20 == F_119 ;
}
static int F_131 ( struct V_13 * V_14 , T_4 V_130 ,
T_4 V_131 , T_4 V_128 )
{
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_4 * V_5 ;
F_89 ( & V_27 -> V_39 ) ;
F_102 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_79 == - 1 )
continue;
if ( ( V_130 == V_129 || V_130 == 0 ) &&
( V_131 == V_129 || V_131 == V_5 -> V_79 ) ) {
F_125 ( & V_5 -> V_25 , 0 ,
V_5 -> V_79 , V_128 , 1 ) ;
}
}
F_91 ( & V_27 -> V_39 ) ;
return 0 ;
}
struct V_132 *
F_132 ( struct V_133 * V_134 )
{
struct V_46 * V_47 ;
int V_66 ;
V_47 = F_46 ( sizeof( struct V_46 ) , V_57 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_52 . V_135 = F_131 ;
V_47 -> V_52 . V_48 . V_49 . V_136 = & V_47 -> V_48 [ 0 ] ;
V_47 -> V_52 . V_48 . V_49 . V_50 = & V_51 . V_50 ;
V_47 -> V_52 . V_48 . V_49 . V_137 = F_33 ;
F_133 ( & V_47 -> V_52 . V_48 ) ;
V_47 -> V_52 . V_138 = sizeof( struct V_26 ) ;
V_47 -> V_75 . V_49 . V_50 = & V_139 . V_50 ;
V_47 -> V_75 . V_49 . V_136 = & V_47 -> V_140 [ 0 ] ;
V_47 -> V_75 . V_49 . V_137 = F_62 ;
F_133 ( & V_47 -> V_75 ) ;
V_47 -> V_80 . V_49 . V_50 = & V_141 . V_50 ;
V_47 -> V_80 . V_49 . V_136 = & V_47 -> V_142 [ 0 ] ;
V_47 -> V_80 . V_49 . V_137 = F_81 ;
F_133 ( & V_47 -> V_80 ) ;
V_47 -> V_114 . V_49 . V_50 = & V_143 . V_50 ;
V_47 -> V_114 . V_49 . V_136 = & V_47 -> V_144 [ 0 ] ;
V_47 -> V_114 . V_49 . V_137 = F_115 ;
F_133 ( & V_47 -> V_114 ) ;
V_47 -> V_115 . V_49 . V_50 = & V_145 . V_50 ;
V_47 -> V_115 . V_49 . V_136 = & V_47 -> V_146 [ 0 ] ;
V_47 -> V_115 . V_49 . V_137 = F_117 ;
F_133 ( & V_47 -> V_115 ) ;
V_47 -> V_116 . V_49 . V_50 = & V_147 . V_50 ;
V_47 -> V_116 . V_49 . V_136 = & V_47 -> V_148 [ 0 ] ;
V_47 -> V_116 . V_49 . V_137 = F_118 ;
F_133 ( & V_47 -> V_116 ) ;
V_47 -> V_20 = V_134 ;
V_66 = 0 ;
F_134 ( V_149 ) ;
F_134 ( V_124 ) ;
F_134 ( V_9 ) ;
F_134 ( V_150 ) ;
F_134 ( V_151 ) ;
F_134 ( V_152 ) ;
F_134 ( V_153 ) ;
F_135 ( V_154 ) ;
F_134 ( V_155 ) ;
F_135 ( V_156 ) ;
F_134 ( V_157 ) ;
F_134 ( V_158 ) ;
F_134 ( V_159 ) ;
F_134 ( V_160 ) ;
F_136 ( V_161 , V_73 ) ;
F_136 ( V_72 , V_73 ) ;
F_137 ( V_67 , V_69 ) ;
V_47 -> V_140 [ V_66 ] = NULL ;
V_66 = 0 ;
F_138 ( V_99 ) ;
V_47 -> V_142 [ V_66 ] = NULL ;
V_66 = 0 ;
F_139 ( V_162 ) ;
F_139 ( V_163 ) ;
F_139 ( V_164 ) ;
F_139 ( V_165 ) ;
F_139 ( V_166 ) ;
F_140 ( V_167 ,
V_101 ) ;
F_140 ( V_168 ,
V_103 ) ;
V_47 -> V_144 [ V_66 ] = NULL ;
V_66 = 0 ;
F_141 ( V_169 ) ;
F_141 ( V_170 ) ;
F_141 ( V_171 ) ;
F_141 ( V_172 ) ;
F_141 ( V_173 ) ;
V_47 -> V_146 [ V_66 ] = NULL ;
V_66 = 0 ;
F_142 ( V_174 ) ;
F_142 ( V_175 ) ;
F_142 ( V_176 ) ;
F_142 ( V_177 ) ;
F_142 ( V_178 ) ;
F_142 ( V_179 ) ;
F_142 ( V_180 ) ;
V_47 -> V_148 [ V_66 ] = NULL ;
return & V_47 -> V_52 ;
}
void F_143 ( struct V_132 * V_52 )
{
struct V_46 * V_47 = F_9 ( V_52 ) ;
F_144 ( & V_47 -> V_52 . V_48 ) ;
F_144 ( & V_47 -> V_75 ) ;
F_144 ( & V_47 -> V_80 ) ;
F_144 ( & V_47 -> V_114 ) ;
F_144 ( & V_47 -> V_115 ) ;
F_144 ( & V_47 -> V_116 ) ;
F_48 ( V_47 ) ;
}
static T_5 int F_145 ( void )
{
int error ;
error = F_146 ( & V_51 ) ;
if ( error )
goto V_58;
error = F_146 ( & V_139 ) ;
if ( error )
goto V_181;
error = F_146 ( & V_141 ) ;
if ( error )
goto V_182;
error = F_146 ( & V_143 ) ;
if ( error )
goto V_183;
error = F_146 ( & V_145 ) ;
if ( error )
goto V_184;
error = F_146 ( & V_147 ) ;
if ( error )
goto V_185;
return 0 ;
V_185:
F_147 ( & V_145 ) ;
V_184:
F_147 ( & V_143 ) ;
V_183:
F_147 ( & V_141 ) ;
V_182:
F_147 ( & V_139 ) ;
V_181:
F_147 ( & V_51 ) ;
V_58:
return error ;
}
static void T_6 F_148 ( void )
{
F_147 ( & V_51 ) ;
F_147 ( & V_139 ) ;
F_147 ( & V_141 ) ;
F_147 ( & V_143 ) ;
F_147 ( & V_145 ) ;
F_147 ( & V_147 ) ;
}
