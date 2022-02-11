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
static int F_61 ( struct V_44 * V_45 , struct V_24 * V_25 )
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
return & V_47 -> V_74 . V_49 == V_45 ;
}
static void F_62 ( struct V_24 * V_25 )
{
struct V_64 * V_65 = F_41 ( V_25 ) ;
F_63 ( V_25 -> V_68 ) ;
F_48 ( V_65 ) ;
}
struct V_64 * F_64 ( struct V_24 * V_68 , int V_75 )
{
struct V_13 * V_14 = F_16 ( V_68 ) ;
struct V_64 * V_65 ;
V_65 = F_46 ( sizeof( * V_65 ) , V_57 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> V_75 = V_75 ;
V_65 -> V_70 = 1 ;
F_65 ( & V_65 -> V_25 ) ;
V_65 -> V_25 . V_68 = F_66 ( V_68 ) ;
V_65 -> V_25 . F_20 = F_62 ;
F_29 ( & V_65 -> V_76 ) ;
if ( F_67 ( V_68 ) ) {
struct V_4 * V_5 = F_68 ( V_68 ) ;
F_69 ( & V_65 -> V_25 , L_6 , V_14 -> V_32 ,
V_5 -> V_77 , V_75 ) ;
} else
F_69 ( & V_65 -> V_25 , L_7 , V_14 -> V_32 , V_75 ) ;
F_70 ( & V_65 -> V_25 ) ;
return V_65 ;
}
int F_71 ( struct V_64 * V_65 )
{
int error ;
error = F_72 ( & V_65 -> V_25 ) ;
if ( ! error ) {
F_73 ( & V_65 -> V_25 ) ;
F_74 ( & V_65 -> V_25 ) ;
}
return error ;
}
void F_75 ( struct V_64 * V_65 )
{
F_76 ( & V_65 -> V_25 ) ;
F_63 ( & V_65 -> V_25 ) ;
}
void
F_40 ( struct V_64 * V_65 )
{
struct V_24 * V_25 = & V_65 -> V_25 ;
F_3 ( ! F_77 ( & V_65 -> V_76 ) ) ;
F_78 ( V_25 ) ;
F_79 ( V_25 ) ;
F_76 ( V_25 ) ;
F_63 ( V_25 ) ;
}
int F_39 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_62 ;
}
static int F_80 ( struct V_44 * V_45 , struct V_24 * V_25 )
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
return & V_47 -> V_78 . V_49 == V_45 ;
}
static void F_81 ( struct V_24 * V_25 )
{
struct V_79 * V_80 = F_38 ( V_25 ) ;
F_3 ( ! F_77 ( & V_80 -> V_81 ) ) ;
F_63 ( V_25 -> V_68 ) ;
F_48 ( V_80 ) ;
}
static void F_82 ( struct V_79 * V_80 ,
struct V_64 * V_65 )
{
int V_82 ;
V_82 = F_83 ( & V_80 -> V_25 . V_83 , & V_65 -> V_25 . V_83 ,
F_23 ( & V_65 -> V_25 ) ) ;
if ( V_82 )
goto V_84;
V_82 = F_83 ( & V_65 -> V_25 . V_83 , & V_80 -> V_25 . V_83 , L_8 ) ;
if ( V_82 )
goto V_84;
return;
V_84:
F_21 ( V_43 L_9 ,
V_85 , V_82 ) ;
}
static void F_84 ( struct V_79 * V_80 ,
struct V_64 * V_65 )
{
F_85 ( & V_80 -> V_25 . V_83 , F_23 ( & V_65 -> V_25 ) ) ;
F_85 ( & V_65 -> V_25 . V_83 , L_8 ) ;
}
struct V_79 * F_86 ( struct V_24 * V_68 , int V_86 )
{
struct V_13 * V_14 = F_16 ( V_68 ) ;
struct V_79 * V_80 ;
V_80 = F_46 ( sizeof( * V_80 ) , V_57 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_87 = V_86 ;
F_65 ( & V_80 -> V_25 ) ;
V_80 -> V_25 . V_68 = F_66 ( V_68 ) ;
V_80 -> V_25 . F_20 = F_81 ;
F_30 ( & V_80 -> V_88 ) ;
F_29 ( & V_80 -> V_81 ) ;
if ( F_67 ( V_68 ) ) {
struct V_4 * V_5 = F_68 ( V_68 ) ;
F_69 ( & V_80 -> V_25 , L_10 , V_14 -> V_32 ,
V_5 -> V_77 , V_80 -> V_87 ) ;
} else
F_69 ( & V_80 -> V_25 , L_11 , V_14 -> V_32 ,
V_80 -> V_87 ) ;
F_70 ( & V_80 -> V_25 ) ;
return V_80 ;
}
struct V_79 * F_87 ( struct V_24 * V_68 )
{
int V_89 ;
struct V_13 * V_14 = F_16 ( V_68 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_88 ( & V_27 -> V_39 ) ;
if ( F_67 ( V_68 ) ) {
struct V_4 * V_5 = F_68 ( V_68 ) ;
struct V_90 * exp = F_89 ( V_5 ) ;
V_89 = exp -> V_42 ++ ;
} else
V_89 = V_27 -> V_42 ++ ;
F_90 ( & V_27 -> V_39 ) ;
return F_86 ( V_68 , V_89 ) ;
}
int F_91 ( struct V_79 * V_80 )
{
int error ;
F_3 ( ! F_77 ( & V_80 -> V_81 ) ) ;
error = F_72 ( & V_80 -> V_25 ) ;
if ( error )
return error ;
F_73 ( & V_80 -> V_25 ) ;
F_74 ( & V_80 -> V_25 ) ;
return 0 ;
}
void F_92 ( struct V_79 * V_80 )
{
F_76 ( & V_80 -> V_25 ) ;
F_63 ( & V_80 -> V_25 ) ;
}
void F_37 ( struct V_79 * V_80 )
{
struct V_24 * V_25 = & V_80 -> V_25 ;
struct V_64 * V_65 , * V_91 ;
if ( V_80 -> V_5 ) {
F_93 ( V_80 -> V_5 ) ;
V_80 -> V_5 = NULL ;
}
F_88 ( & V_80 -> V_88 ) ;
F_94 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_84 ( V_80 , V_65 ) ;
F_95 ( & V_65 -> V_76 ) ;
}
F_90 ( & V_80 -> V_88 ) ;
if ( V_80 -> V_92 ) {
struct V_24 * V_68 = V_80 -> V_25 . V_68 ;
F_85 ( & V_80 -> V_25 . V_83 , F_23 ( V_68 ) ) ;
V_80 -> V_92 = 0 ;
}
F_78 ( V_25 ) ;
F_79 ( V_25 ) ;
F_76 ( V_25 ) ;
F_63 ( V_25 ) ;
}
int F_36 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_81 ;
}
void F_96 ( struct V_79 * V_80 , struct V_64 * V_65 )
{
F_88 ( & V_80 -> V_88 ) ;
if ( F_97 ( ! F_77 ( & V_65 -> V_76 ) ) ) {
struct V_64 * V_93 ;
F_98 (tmp, &port->phy_list, port_siblings)
if ( V_93 == V_65 )
break;
if ( F_97 ( V_93 != V_65 ) ) {
F_31 ( V_43 , & V_80 -> V_25 , L_12 ,
F_23 ( & V_65 -> V_25 ) ) ;
F_99 () ;
}
} else {
F_82 ( V_80 , V_65 ) ;
F_100 ( & V_65 -> V_76 , & V_80 -> V_81 ) ;
V_80 -> V_94 ++ ;
}
F_90 ( & V_80 -> V_88 ) ;
}
void F_101 ( struct V_79 * V_80 , struct V_64 * V_65 )
{
F_88 ( & V_80 -> V_88 ) ;
F_84 ( V_80 , V_65 ) ;
F_95 ( & V_65 -> V_76 ) ;
V_80 -> V_94 -- ;
F_90 ( & V_80 -> V_88 ) ;
}
void F_102 ( struct V_79 * V_80 )
{
int V_82 ;
struct V_24 * V_68 = V_80 -> V_25 . V_68 -> V_68 -> V_68 ;
if ( V_80 -> V_92 )
return;
V_80 -> V_92 = 1 ;
V_82 = F_83 ( & V_80 -> V_25 . V_83 , & V_68 -> V_83 ,
F_23 ( V_68 ) ) ;
if ( V_82 )
goto V_84;
return;
V_84:
F_21 ( V_43 L_13 ,
V_85 , V_82 ) ;
}
static T_1
F_103 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_4 * V_5 = F_104 ( V_25 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_63 , 20 , L_4 ) ;
return F_54 (
V_5 -> V_8 . V_9 , V_63 ) ;
}
static T_1
F_105 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_4 * V_5 = F_104 ( V_25 ) ;
struct V_64 * V_65 = F_41 ( V_5 -> V_25 . V_68 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
T_3 V_95 ;
int error ;
if ( F_106 ( V_65 ) )
return - V_71 ;
error = V_47 -> V_20 -> V_96 ( V_5 , & V_95 ) ;
if ( error )
return error ;
return sprintf ( V_63 , L_14 , ( unsigned long long ) V_95 ) ;
}
static T_1
F_107 ( struct V_24 * V_25 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_4 * V_5 = F_104 ( V_25 ) ;
struct V_64 * V_65 = F_41 ( V_5 -> V_25 . V_68 ) ;
struct V_13 * V_14 = F_16 ( V_65 -> V_25 . V_68 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int V_97 ;
if ( F_106 ( V_65 ) )
return - V_71 ;
V_97 = V_47 -> V_20 -> V_98 ( V_5 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_63 , L_15 , V_97 ) ;
}
int F_108 ( struct V_2 * V_3 )
{
char * V_56 = F_46 ( V_99 , V_57 ) , * V_100 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_101 V_102 ;
int V_82 , error ;
if ( ! V_56 )
return - V_33 ;
V_82 = F_109 ( V_3 , 1 , 0x19 , V_56 , V_99 , 30 * V_103 , 3 ,
& V_102 , NULL ) ;
error = - V_71 ;
if ( ! F_110 ( V_82 ) )
goto V_58;
V_100 = V_56 + V_102 . V_104 +
V_102 . V_105 ;
if ( V_100 - V_56 > V_99 - 8 )
goto V_58;
error = 0 ;
V_7 -> V_106 = V_100 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_107 = ( V_100 [ 4 ] << 8 ) + V_100 [ 5 ] ;
V_7 -> V_108 = ( V_100 [ 6 ] << 8 ) + V_100 [ 7 ] ;
V_58:
F_48 ( V_56 ) ;
return error ;
}
static int F_111 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_112 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 -> V_68 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_109 . V_49 == V_45 ;
}
static int F_113 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_112 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 -> V_68 ) ;
V_5 = F_68 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_110 . V_49 == V_45 &&
V_5 -> V_8 . V_9 == V_10 ;
}
static int F_114 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_112 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_68 -> V_68 ) ;
V_5 = F_68 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_111 . V_49 == V_45 &&
( V_5 -> V_8 . V_9 == V_112 ||
V_5 -> V_8 . V_9 == V_113 ) ;
}
static void F_115 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_68 ( V_25 ) ;
struct V_90 * V_114 = F_89 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_63 ( V_25 -> V_68 ) ;
F_48 ( V_114 ) ;
}
static void F_116 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_68 ( V_25 ) ;
struct V_1 * V_114 = F_4 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_63 ( V_25 -> V_68 ) ;
F_48 ( V_114 ) ;
}
static void F_117 ( struct V_4 * V_5 )
{
F_29 ( & V_5 -> V_115 ) ;
}
struct V_4 * F_118 ( struct V_79 * V_68 )
{
struct V_13 * V_14 = F_16 ( & V_68 -> V_25 ) ;
struct V_1 * V_7 ;
V_7 = F_46 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_65 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_68 = F_66 ( & V_68 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_116 ;
if ( F_67 ( V_68 -> V_25 . V_68 ) ) {
struct V_4 * V_5 = F_68 ( V_68 -> V_25 . V_68 ) ;
F_69 ( & V_7 -> V_5 . V_25 , L_16 ,
V_14 -> V_32 , V_5 -> V_77 ,
V_68 -> V_87 ) ;
} else
F_69 ( & V_7 -> V_5 . V_25 , L_17 ,
V_14 -> V_32 , V_68 -> V_87 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_117 ( & V_7 -> V_5 ) ;
F_70 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_119 ( struct V_79 * V_68 ,
enum V_116 type )
{
struct V_13 * V_14 = F_16 ( & V_68 -> V_25 ) ;
struct V_90 * V_7 ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_3 ( type != V_112 &&
type != V_113 ) ;
V_7 = F_46 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_65 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_68 = F_66 ( & V_68 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_115 ;
F_88 ( & V_27 -> V_39 ) ;
V_7 -> V_5 . V_77 = V_27 -> V_41 ++ ;
F_90 ( & V_27 -> V_39 ) ;
F_69 ( & V_7 -> V_5 . V_25 , L_18 ,
V_14 -> V_32 , V_7 -> V_5 . V_77 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_117 ( & V_7 -> V_5 ) ;
F_70 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
int F_120 ( struct V_4 * V_5 )
{
struct V_79 * V_68 = F_38 ( V_5 -> V_25 . V_68 ) ;
struct V_13 * V_14 = F_16 ( V_68 -> V_25 . V_68 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_117 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_68 -> V_5 )
return - V_118 ;
V_68 -> V_5 = V_5 ;
error = F_72 ( & V_5 -> V_25 ) ;
if ( error )
return error ;
F_73 ( & V_5 -> V_25 ) ;
F_74 ( & V_5 -> V_25 ) ;
if ( F_19 ( V_14 , V_5 ) )
F_21 ( L_19 , F_23 ( & V_5 -> V_25 ) ) ;
F_88 ( & V_27 -> V_39 ) ;
F_100 ( & V_5 -> V_115 , & V_27 -> V_38 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_119 &
( V_120 | V_121 | V_122 ) ) )
V_5 -> V_77 = V_27 -> V_40 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_77 = - 1 ;
F_90 ( & V_27 -> V_39 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_77 != - 1 ) {
int V_123 ;
if ( V_8 -> V_119 & V_120 )
V_123 = V_124 ;
else
V_123 = 0 ;
F_121 ( & V_5 -> V_25 , 0 , V_5 -> V_77 , V_123 , 0 ) ;
}
return 0 ;
}
void F_122 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
struct V_13 * V_14 = F_16 ( V_5 -> V_25 . V_68 -> V_68 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_88 ( & V_27 -> V_39 ) ;
F_123 ( & V_5 -> V_115 ) ;
F_90 ( & V_27 -> V_39 ) ;
F_26 ( V_14 , V_5 ) ;
F_76 ( V_25 ) ;
F_63 ( V_25 ) ;
}
void
F_93 ( struct V_4 * V_5 )
{
F_124 ( V_5 ) ;
F_122 ( V_5 ) ;
}
void
F_124 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
struct V_79 * V_68 = F_38 ( V_25 -> V_68 ) ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_125 ( V_25 ) ;
break;
case V_112 :
case V_113 :
F_42 ( V_25 ) ;
break;
default:
break;
}
F_78 ( V_25 ) ;
F_79 ( V_25 ) ;
V_68 -> V_5 = NULL ;
}
int F_112 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_116 ||
V_25 -> F_20 == F_115 ;
}
static int F_126 ( struct V_13 * V_14 , T_4 V_125 ,
T_4 V_126 , T_4 V_123 )
{
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_4 * V_5 ;
F_88 ( & V_27 -> V_39 ) ;
F_98 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_77 == - 1 )
continue;
if ( ( V_125 == V_124 || V_125 == 0 ) &&
( V_126 == V_124 || V_126 == V_5 -> V_77 ) ) {
F_121 ( & V_5 -> V_25 , 0 ,
V_5 -> V_77 , V_123 , 1 ) ;
}
}
F_90 ( & V_27 -> V_39 ) ;
return 0 ;
}
struct V_127 *
F_127 ( struct V_128 * V_129 )
{
struct V_46 * V_47 ;
int V_66 ;
V_47 = F_46 ( sizeof( struct V_46 ) , V_57 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_52 . V_130 = F_126 ;
V_47 -> V_52 . V_48 . V_49 . V_131 = & V_47 -> V_48 [ 0 ] ;
V_47 -> V_52 . V_48 . V_49 . V_50 = & V_51 . V_50 ;
V_47 -> V_52 . V_48 . V_49 . V_132 = F_33 ;
F_128 ( & V_47 -> V_52 . V_48 ) ;
V_47 -> V_52 . V_133 = sizeof( struct V_26 ) ;
V_47 -> V_74 . V_49 . V_50 = & V_134 . V_50 ;
V_47 -> V_74 . V_49 . V_131 = & V_47 -> V_135 [ 0 ] ;
V_47 -> V_74 . V_49 . V_132 = F_61 ;
F_128 ( & V_47 -> V_74 ) ;
V_47 -> V_78 . V_49 . V_50 = & V_136 . V_50 ;
V_47 -> V_78 . V_49 . V_131 = & V_47 -> V_137 [ 0 ] ;
V_47 -> V_78 . V_49 . V_132 = F_80 ;
F_128 ( & V_47 -> V_78 ) ;
V_47 -> V_109 . V_49 . V_50 = & V_138 . V_50 ;
V_47 -> V_109 . V_49 . V_131 = & V_47 -> V_139 [ 0 ] ;
V_47 -> V_109 . V_49 . V_132 = F_111 ;
F_128 ( & V_47 -> V_109 ) ;
V_47 -> V_110 . V_49 . V_50 = & V_140 . V_50 ;
V_47 -> V_110 . V_49 . V_131 = & V_47 -> V_141 [ 0 ] ;
V_47 -> V_110 . V_49 . V_132 = F_113 ;
F_128 ( & V_47 -> V_110 ) ;
V_47 -> V_111 . V_49 . V_50 = & V_142 . V_50 ;
V_47 -> V_111 . V_49 . V_131 = & V_47 -> V_143 [ 0 ] ;
V_47 -> V_111 . V_49 . V_132 = F_114 ;
F_128 ( & V_47 -> V_111 ) ;
V_47 -> V_20 = V_129 ;
V_66 = 0 ;
F_129 ( V_144 ) ;
F_129 ( V_119 ) ;
F_129 ( V_9 ) ;
F_129 ( V_145 ) ;
F_129 ( V_146 ) ;
F_129 ( V_147 ) ;
F_129 ( V_148 ) ;
F_130 ( V_149 ) ;
F_129 ( V_150 ) ;
F_130 ( V_151 ) ;
F_129 ( V_152 ) ;
F_129 ( V_153 ) ;
F_129 ( V_154 ) ;
F_129 ( V_155 ) ;
F_131 ( V_156 , V_73 ) ;
F_131 ( V_72 , V_73 ) ;
F_132 ( V_67 , V_69 ) ;
V_47 -> V_135 [ V_66 ] = NULL ;
V_66 = 0 ;
F_133 ( V_94 ) ;
V_47 -> V_137 [ V_66 ] = NULL ;
V_66 = 0 ;
F_134 ( V_157 ) ;
F_134 ( V_158 ) ;
F_134 ( V_159 ) ;
F_134 ( V_160 ) ;
F_134 ( V_161 ) ;
F_135 ( V_162 ,
V_96 ) ;
F_135 ( V_163 ,
V_98 ) ;
V_47 -> V_139 [ V_66 ] = NULL ;
V_66 = 0 ;
F_136 ( V_164 ) ;
F_136 ( V_165 ) ;
F_136 ( V_166 ) ;
F_136 ( V_167 ) ;
F_136 ( V_168 ) ;
V_47 -> V_141 [ V_66 ] = NULL ;
V_66 = 0 ;
F_137 ( V_169 ) ;
F_137 ( V_170 ) ;
F_137 ( V_171 ) ;
F_137 ( V_172 ) ;
F_137 ( V_173 ) ;
F_137 ( V_174 ) ;
F_137 ( V_175 ) ;
V_47 -> V_143 [ V_66 ] = NULL ;
return & V_47 -> V_52 ;
}
void F_138 ( struct V_127 * V_52 )
{
struct V_46 * V_47 = F_9 ( V_52 ) ;
F_139 ( & V_47 -> V_52 . V_48 ) ;
F_139 ( & V_47 -> V_74 ) ;
F_139 ( & V_47 -> V_78 ) ;
F_139 ( & V_47 -> V_109 ) ;
F_139 ( & V_47 -> V_110 ) ;
F_139 ( & V_47 -> V_111 ) ;
F_48 ( V_47 ) ;
}
static T_5 int F_140 ( void )
{
int error ;
error = F_141 ( & V_51 ) ;
if ( error )
goto V_58;
error = F_141 ( & V_134 ) ;
if ( error )
goto V_176;
error = F_141 ( & V_136 ) ;
if ( error )
goto V_177;
error = F_141 ( & V_138 ) ;
if ( error )
goto V_178;
error = F_141 ( & V_140 ) ;
if ( error )
goto V_179;
error = F_141 ( & V_142 ) ;
if ( error )
goto V_180;
return 0 ;
V_180:
F_142 ( & V_140 ) ;
V_179:
F_142 ( & V_138 ) ;
V_178:
F_142 ( & V_136 ) ;
V_177:
F_142 ( & V_134 ) ;
V_176:
F_142 ( & V_51 ) ;
V_58:
return error ;
}
static void T_6 F_143 ( void )
{
F_142 ( & V_51 ) ;
F_142 ( & V_134 ) ;
F_142 ( & V_136 ) ;
F_142 ( & V_138 ) ;
F_142 ( & V_140 ) ;
F_142 ( & V_142 ) ;
}
