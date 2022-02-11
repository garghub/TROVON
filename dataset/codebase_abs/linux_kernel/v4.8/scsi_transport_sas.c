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
T_1 F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_5 . V_8 . V_55 ;
}
unsigned int
F_46 ( struct V_2 * V_3 )
{
const int V_56 = 32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
char * V_57 = F_47 ( V_56 , V_58 ) ;
int V_17 = 0 ;
if ( F_48 ( V_3 , 0x90 , V_57 , V_56 ) )
goto V_59;
V_17 = V_57 [ 12 ] & 0x01 ;
V_59:
F_49 ( V_57 ) ;
V_7 -> V_60 = V_17 ;
return V_17 ;
}
void
F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_61 = 0 ;
}
void F_51 ( struct V_2 * V_3 )
{
unsigned int V_60 = 0 ;
V_60 = F_46 ( V_3 ) ;
if ( V_60 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_61 = 1 ;
}
return;
}
unsigned int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_61 ;
}
static T_2
F_53 ( struct V_24 * V_25 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_65 * V_66 = F_54 ( V_25 ) ;
if ( ! V_66 -> V_8 . V_9 )
return snprintf ( V_64 , 20 , L_4 ) ;
return F_55 ( V_66 -> V_8 . V_9 , V_64 ) ;
}
static T_2 F_56 ( struct V_24 * V_25 ,
T_3 V_67 , int V_68 )
{
struct V_65 * V_66 = F_54 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_66 -> V_25 . V_69 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int error ;
error = V_47 -> V_20 -> V_70 ( V_66 , V_68 ) ;
if ( error )
return error ;
V_66 -> V_71 = V_68 ;
return V_67 ;
}
static T_2
F_57 ( struct V_24 * V_25 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_67 )
{
if ( V_67 < 1 )
return - V_72 ;
switch ( V_64 [ 0 ] ) {
case '0' :
F_56 ( V_25 , V_67 , 0 ) ;
break;
case '1' :
F_56 ( V_25 , V_67 , 1 ) ;
break;
default:
return - V_72 ;
}
return V_67 ;
}
static T_2
F_58 ( struct V_24 * V_25 , struct V_62 * V_63 ,
char * V_64 )
{
struct V_65 * V_66 = F_54 ( V_25 ) ;
return snprintf ( V_64 , 20 , L_5 , V_66 -> V_71 ) ;
}
static T_2
F_59 ( struct V_24 * V_25 , T_3 V_67 , int V_73 )
{
struct V_65 * V_66 = F_54 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_66 -> V_25 . V_69 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int error ;
error = V_47 -> V_20 -> V_74 ( V_66 , V_73 ) ;
if ( error )
return error ;
V_66 -> V_71 = 1 ;
return V_67 ;
}
static T_2
F_60 ( struct V_24 * V_25 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_67 )
{
return F_59 ( V_25 , V_67 , 0 ) ;
}
static T_2
F_61 ( struct V_24 * V_25 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_67 )
{
return F_59 ( V_25 , V_67 , 1 ) ;
}
static int F_62 ( struct V_35 * V_36 , struct V_24 * V_25 ,
struct V_24 * V_37 )
{
struct V_65 * V_66 = F_41 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_66 -> V_25 . V_69 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
if ( V_47 -> V_20 -> V_75 )
V_47 -> V_20 -> V_75 ( V_66 ) ;
return 0 ;
}
static int F_63 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_39 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_69 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_76 . V_49 == V_45 ;
}
static void F_64 ( struct V_24 * V_25 )
{
struct V_65 * V_66 = F_41 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_66 -> V_25 . V_69 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
if ( V_47 -> V_20 -> V_77 )
V_47 -> V_20 -> V_77 ( V_66 ) ;
F_65 ( V_25 -> V_69 ) ;
F_49 ( V_66 ) ;
}
struct V_65 * F_66 ( struct V_24 * V_69 , int V_78 )
{
struct V_13 * V_14 = F_16 ( V_69 ) ;
struct V_65 * V_66 ;
V_66 = F_47 ( sizeof( * V_66 ) , V_58 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_78 = V_78 ;
V_66 -> V_71 = 1 ;
F_67 ( & V_66 -> V_25 ) ;
V_66 -> V_25 . V_69 = F_68 ( V_69 ) ;
V_66 -> V_25 . F_20 = F_64 ;
F_29 ( & V_66 -> V_79 ) ;
if ( F_69 ( V_69 ) ) {
struct V_4 * V_5 = F_70 ( V_69 ) ;
F_71 ( & V_66 -> V_25 , L_6 , V_14 -> V_32 ,
V_5 -> V_80 , V_78 ) ;
} else
F_71 ( & V_66 -> V_25 , L_7 , V_14 -> V_32 , V_78 ) ;
F_72 ( & V_66 -> V_25 ) ;
return V_66 ;
}
int F_73 ( struct V_65 * V_66 )
{
int error ;
error = F_74 ( & V_66 -> V_25 ) ;
if ( ! error ) {
F_75 ( & V_66 -> V_25 ) ;
F_76 ( & V_66 -> V_25 ) ;
}
return error ;
}
void F_77 ( struct V_65 * V_66 )
{
F_78 ( & V_66 -> V_25 ) ;
F_65 ( & V_66 -> V_25 ) ;
}
void
F_40 ( struct V_65 * V_66 )
{
struct V_24 * V_25 = & V_66 -> V_25 ;
F_3 ( ! F_79 ( & V_66 -> V_79 ) ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_78 ( V_25 ) ;
F_65 ( V_25 ) ;
}
int F_39 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_64 ;
}
static int F_82 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_36 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_69 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_81 . V_49 == V_45 ;
}
static void F_83 ( struct V_24 * V_25 )
{
struct V_82 * V_83 = F_38 ( V_25 ) ;
F_3 ( ! F_79 ( & V_83 -> V_84 ) ) ;
F_65 ( V_25 -> V_69 ) ;
F_49 ( V_83 ) ;
}
static void F_84 ( struct V_82 * V_83 ,
struct V_65 * V_66 )
{
int V_85 ;
V_85 = F_85 ( & V_83 -> V_25 . V_86 , & V_66 -> V_25 . V_86 ,
F_23 ( & V_66 -> V_25 ) ) ;
if ( V_85 )
goto V_87;
V_85 = F_85 ( & V_66 -> V_25 . V_86 , & V_83 -> V_25 . V_86 , L_8 ) ;
if ( V_85 )
goto V_87;
return;
V_87:
F_21 ( V_43 L_9 ,
V_88 , V_85 ) ;
}
static void F_86 ( struct V_82 * V_83 ,
struct V_65 * V_66 )
{
F_87 ( & V_83 -> V_25 . V_86 , F_23 ( & V_66 -> V_25 ) ) ;
F_87 ( & V_66 -> V_25 . V_86 , L_8 ) ;
}
struct V_82 * F_88 ( struct V_24 * V_69 , int V_89 )
{
struct V_13 * V_14 = F_16 ( V_69 ) ;
struct V_82 * V_83 ;
V_83 = F_47 ( sizeof( * V_83 ) , V_58 ) ;
if ( ! V_83 )
return NULL ;
V_83 -> V_90 = V_89 ;
F_67 ( & V_83 -> V_25 ) ;
V_83 -> V_25 . V_69 = F_68 ( V_69 ) ;
V_83 -> V_25 . F_20 = F_83 ;
F_30 ( & V_83 -> V_91 ) ;
F_29 ( & V_83 -> V_84 ) ;
if ( F_69 ( V_69 ) ) {
struct V_4 * V_5 = F_70 ( V_69 ) ;
F_71 ( & V_83 -> V_25 , L_10 , V_14 -> V_32 ,
V_5 -> V_80 , V_83 -> V_90 ) ;
} else
F_71 ( & V_83 -> V_25 , L_11 , V_14 -> V_32 ,
V_83 -> V_90 ) ;
F_72 ( & V_83 -> V_25 ) ;
return V_83 ;
}
struct V_82 * F_89 ( struct V_24 * V_69 )
{
int V_92 ;
struct V_13 * V_14 = F_16 ( V_69 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_90 ( & V_27 -> V_39 ) ;
if ( F_69 ( V_69 ) ) {
struct V_4 * V_5 = F_70 ( V_69 ) ;
struct V_93 * exp = F_91 ( V_5 ) ;
V_92 = exp -> V_42 ++ ;
} else
V_92 = V_27 -> V_42 ++ ;
F_92 ( & V_27 -> V_39 ) ;
return F_88 ( V_69 , V_92 ) ;
}
int F_93 ( struct V_82 * V_83 )
{
int error ;
F_3 ( ! F_79 ( & V_83 -> V_84 ) ) ;
error = F_74 ( & V_83 -> V_25 ) ;
if ( error )
return error ;
F_75 ( & V_83 -> V_25 ) ;
F_76 ( & V_83 -> V_25 ) ;
return 0 ;
}
void F_94 ( struct V_82 * V_83 )
{
F_78 ( & V_83 -> V_25 ) ;
F_65 ( & V_83 -> V_25 ) ;
}
void F_37 ( struct V_82 * V_83 )
{
struct V_24 * V_25 = & V_83 -> V_25 ;
struct V_65 * V_66 , * V_94 ;
if ( V_83 -> V_5 ) {
F_95 ( V_83 -> V_5 ) ;
V_83 -> V_5 = NULL ;
}
F_90 ( & V_83 -> V_91 ) ;
F_96 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_86 ( V_83 , V_66 ) ;
F_97 ( & V_66 -> V_79 ) ;
}
F_92 ( & V_83 -> V_91 ) ;
if ( V_83 -> V_95 ) {
struct V_24 * V_69 = V_83 -> V_25 . V_69 ;
F_87 ( & V_83 -> V_25 . V_86 , F_23 ( V_69 ) ) ;
V_83 -> V_95 = 0 ;
}
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_78 ( V_25 ) ;
F_65 ( V_25 ) ;
}
int F_36 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_83 ;
}
struct V_65 * F_98 ( struct V_82 * V_83 )
{
struct V_65 * V_66 ;
F_90 ( & V_83 -> V_91 ) ;
if ( F_79 ( & V_83 -> V_84 ) )
V_66 = NULL ;
else {
struct V_96 * V_97 = V_83 -> V_84 . V_98 ;
V_66 = F_99 ( V_97 , F_100 ( * V_66 ) , V_79 ) ;
F_68 ( & V_66 -> V_25 ) ;
}
F_92 ( & V_83 -> V_91 ) ;
return V_66 ;
}
void F_101 ( struct V_82 * V_83 , struct V_65 * V_66 )
{
F_90 ( & V_83 -> V_91 ) ;
if ( F_102 ( ! F_79 ( & V_66 -> V_79 ) ) ) {
struct V_65 * V_99 ;
F_103 (tmp, &port->phy_list, port_siblings)
if ( V_99 == V_66 )
break;
if ( F_102 ( V_99 != V_66 ) ) {
F_31 ( V_43 , & V_83 -> V_25 , L_12 ,
F_23 ( & V_66 -> V_25 ) ) ;
F_104 () ;
}
} else {
F_84 ( V_83 , V_66 ) ;
F_105 ( & V_66 -> V_79 , & V_83 -> V_84 ) ;
V_83 -> V_100 ++ ;
}
F_92 ( & V_83 -> V_91 ) ;
}
void F_106 ( struct V_82 * V_83 , struct V_65 * V_66 )
{
F_90 ( & V_83 -> V_91 ) ;
F_86 ( V_83 , V_66 ) ;
F_97 ( & V_66 -> V_79 ) ;
V_83 -> V_100 -- ;
F_92 ( & V_83 -> V_91 ) ;
}
void F_107 ( struct V_82 * V_83 )
{
int V_85 ;
struct V_24 * V_69 = V_83 -> V_25 . V_69 -> V_69 -> V_69 ;
if ( V_83 -> V_95 )
return;
V_83 -> V_95 = 1 ;
V_85 = F_85 ( & V_83 -> V_25 . V_86 , & V_69 -> V_86 ,
F_23 ( V_69 ) ) ;
if ( V_85 )
goto V_87;
return;
V_87:
F_21 ( V_43 L_13 ,
V_88 , V_85 ) ;
}
static T_2
F_108 ( struct V_24 * V_25 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_5 = F_109 ( V_25 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_64 , 20 , L_4 ) ;
return F_55 (
V_5 -> V_8 . V_9 , V_64 ) ;
}
static T_2
F_110 ( struct V_24 * V_25 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_5 = F_109 ( V_25 ) ;
struct V_65 * V_66 = F_41 ( V_5 -> V_25 . V_69 ) ;
struct V_13 * V_14 = F_16 ( V_66 -> V_25 . V_69 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
T_1 V_101 ;
int error ;
error = V_47 -> V_20 -> V_102 ( V_5 , & V_101 ) ;
if ( error )
return error ;
return sprintf ( V_64 , L_14 , ( unsigned long long ) V_101 ) ;
}
static T_2
F_111 ( struct V_24 * V_25 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_4 * V_5 = F_109 ( V_25 ) ;
struct V_65 * V_66 = F_41 ( V_5 -> V_25 . V_69 ) ;
struct V_13 * V_14 = F_16 ( V_66 -> V_25 . V_69 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int V_103 ;
V_103 = V_47 -> V_20 -> V_104 ( V_5 ) ;
if ( V_103 < 0 )
return V_103 ;
return sprintf ( V_64 , L_15 , V_103 ) ;
}
int F_112 ( struct V_2 * V_3 )
{
char * V_57 = F_47 ( V_105 , V_58 ) , * V_106 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_107 V_108 ;
int V_85 , error ;
if ( ! V_57 )
return - V_33 ;
V_85 = F_113 ( V_3 , 1 , 0x19 , V_57 , V_105 , 30 * V_109 , 3 ,
& V_108 , NULL ) ;
error = - V_72 ;
if ( ! F_114 ( V_85 ) )
goto V_59;
V_106 = V_57 + V_108 . V_110 +
V_108 . V_111 ;
if ( V_106 - V_57 > V_105 - 8 )
goto V_59;
error = 0 ;
V_7 -> V_112 = V_106 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_113 = ( V_106 [ 4 ] << 8 ) + V_106 [ 5 ] ;
V_7 -> V_114 = ( V_106 [ 6 ] << 8 ) + V_106 [ 7 ] ;
V_59:
F_49 ( V_57 ) ;
return error ;
}
static int F_115 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_116 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_69 -> V_69 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_115 . V_49 == V_45 ;
}
static int F_117 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_116 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_69 -> V_69 ) ;
V_5 = F_70 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_116 . V_49 == V_45 &&
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
V_14 = F_16 ( V_25 -> V_69 -> V_69 ) ;
V_5 = F_70 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_117 . V_49 == V_45 &&
( V_5 -> V_8 . V_9 == V_118 ||
V_5 -> V_8 . V_9 == V_119 ) ;
}
static void F_119 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_70 ( V_25 ) ;
struct V_93 * V_120 = F_91 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_65 ( V_25 -> V_69 ) ;
F_49 ( V_120 ) ;
}
static void F_120 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_70 ( V_25 ) ;
struct V_1 * V_120 = F_4 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_65 ( V_25 -> V_69 ) ;
F_49 ( V_120 ) ;
}
static void F_121 ( struct V_4 * V_5 )
{
F_29 ( & V_5 -> V_121 ) ;
}
struct V_4 * F_122 ( struct V_82 * V_69 )
{
struct V_13 * V_14 = F_16 ( & V_69 -> V_25 ) ;
struct V_1 * V_7 ;
V_7 = F_47 ( sizeof( * V_7 ) , V_58 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_67 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_69 = F_68 ( & V_69 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_120 ;
if ( F_69 ( V_69 -> V_25 . V_69 ) ) {
struct V_4 * V_5 = F_70 ( V_69 -> V_25 . V_69 ) ;
F_71 ( & V_7 -> V_5 . V_25 , L_16 ,
V_14 -> V_32 , V_5 -> V_80 ,
V_69 -> V_90 ) ;
} else
F_71 ( & V_7 -> V_5 . V_25 , L_17 ,
V_14 -> V_32 , V_69 -> V_90 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_121 ( & V_7 -> V_5 ) ;
F_72 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_123 ( struct V_82 * V_69 ,
enum V_122 type )
{
struct V_13 * V_14 = F_16 ( & V_69 -> V_25 ) ;
struct V_93 * V_7 ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_3 ( type != V_118 &&
type != V_119 ) ;
V_7 = F_47 ( sizeof( * V_7 ) , V_58 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_67 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_69 = F_68 ( & V_69 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_119 ;
F_90 ( & V_27 -> V_39 ) ;
V_7 -> V_5 . V_80 = V_27 -> V_41 ++ ;
F_92 ( & V_27 -> V_39 ) ;
F_71 ( & V_7 -> V_5 . V_25 , L_18 ,
V_14 -> V_32 , V_7 -> V_5 . V_80 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_121 ( & V_7 -> V_5 ) ;
F_72 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
int F_124 ( struct V_4 * V_5 )
{
struct V_82 * V_69 = F_38 ( V_5 -> V_25 . V_69 ) ;
struct V_13 * V_14 = F_16 ( V_69 -> V_25 . V_69 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_123 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_69 -> V_5 )
return - V_124 ;
V_69 -> V_5 = V_5 ;
error = F_74 ( & V_5 -> V_25 ) ;
if ( error )
return error ;
F_75 ( & V_5 -> V_25 ) ;
F_76 ( & V_5 -> V_25 ) ;
if ( F_19 ( V_14 , V_5 ) )
F_21 ( L_19 , F_23 ( & V_5 -> V_25 ) ) ;
F_90 ( & V_27 -> V_39 ) ;
F_105 ( & V_5 -> V_121 , & V_27 -> V_38 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_125 &
( V_126 | V_127 | V_128 ) ) )
V_5 -> V_80 = V_27 -> V_40 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_80 = - 1 ;
F_92 ( & V_27 -> V_39 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_80 != - 1 ) {
int V_129 ;
if ( V_8 -> V_125 & V_126 )
V_129 = V_130 ;
else
V_129 = 0 ;
F_125 ( & V_5 -> V_25 , 0 , V_5 -> V_80 , V_129 ,
V_131 ) ;
}
return 0 ;
}
void F_126 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
struct V_13 * V_14 = F_16 ( V_5 -> V_25 . V_69 -> V_69 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_90 ( & V_27 -> V_39 ) ;
F_127 ( & V_5 -> V_121 ) ;
F_92 ( & V_27 -> V_39 ) ;
F_78 ( V_25 ) ;
F_65 ( V_25 ) ;
}
void
F_95 ( struct V_4 * V_5 )
{
F_128 ( V_5 ) ;
F_126 ( V_5 ) ;
}
void F_129 ( struct V_4 * V_5 )
{
struct V_82 * V_69 = F_38 ( V_5 -> V_25 . V_69 ) ;
V_69 -> V_5 = NULL ;
}
void
F_128 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_130 ( V_25 ) ;
break;
case V_118 :
case V_119 :
F_42 ( V_25 ) ;
break;
default:
break;
}
F_129 ( V_5 ) ;
F_26 ( NULL , V_5 ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
}
int F_116 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_120 ||
V_25 -> F_20 == F_119 ;
}
static int F_131 ( struct V_13 * V_14 , T_4 V_132 ,
T_4 V_133 , T_1 V_129 )
{
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_4 * V_5 ;
F_90 ( & V_27 -> V_39 ) ;
F_103 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_80 == - 1 )
continue;
if ( ( V_132 == V_130 || V_132 == 0 ) &&
( V_133 == V_130 || V_133 == V_5 -> V_80 ) ) {
F_125 ( & V_5 -> V_25 , 0 , V_5 -> V_80 ,
V_129 , V_134 ) ;
}
}
F_92 ( & V_27 -> V_39 ) ;
return 0 ;
}
struct V_135 *
F_132 ( struct V_136 * V_137 )
{
struct V_46 * V_47 ;
int V_67 ;
V_47 = F_47 ( sizeof( struct V_46 ) , V_58 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_52 . V_138 = F_131 ;
V_47 -> V_52 . V_48 . V_49 . V_139 = & V_47 -> V_48 [ 0 ] ;
V_47 -> V_52 . V_48 . V_49 . V_50 = & V_51 . V_50 ;
V_47 -> V_52 . V_48 . V_49 . V_140 = F_33 ;
F_133 ( & V_47 -> V_52 . V_48 ) ;
V_47 -> V_52 . V_141 = sizeof( struct V_26 ) ;
V_47 -> V_76 . V_49 . V_50 = & V_142 . V_50 ;
V_47 -> V_76 . V_49 . V_139 = & V_47 -> V_143 [ 0 ] ;
V_47 -> V_76 . V_49 . V_140 = F_63 ;
F_133 ( & V_47 -> V_76 ) ;
V_47 -> V_81 . V_49 . V_50 = & V_144 . V_50 ;
V_47 -> V_81 . V_49 . V_139 = & V_47 -> V_145 [ 0 ] ;
V_47 -> V_81 . V_49 . V_140 = F_82 ;
F_133 ( & V_47 -> V_81 ) ;
V_47 -> V_115 . V_49 . V_50 = & V_146 . V_50 ;
V_47 -> V_115 . V_49 . V_139 = & V_47 -> V_147 [ 0 ] ;
V_47 -> V_115 . V_49 . V_140 = F_115 ;
F_133 ( & V_47 -> V_115 ) ;
V_47 -> V_116 . V_49 . V_50 = & V_148 . V_50 ;
V_47 -> V_116 . V_49 . V_139 = & V_47 -> V_149 [ 0 ] ;
V_47 -> V_116 . V_49 . V_140 = F_117 ;
F_133 ( & V_47 -> V_116 ) ;
V_47 -> V_117 . V_49 . V_50 = & V_150 . V_50 ;
V_47 -> V_117 . V_49 . V_139 = & V_47 -> V_151 [ 0 ] ;
V_47 -> V_117 . V_49 . V_140 = F_118 ;
F_133 ( & V_47 -> V_117 ) ;
V_47 -> V_20 = V_137 ;
V_67 = 0 ;
F_134 ( V_152 ) ;
F_134 ( V_125 ) ;
F_134 ( V_9 ) ;
F_134 ( V_55 ) ;
F_134 ( V_153 ) ;
F_134 ( V_154 ) ;
F_134 ( V_155 ) ;
F_135 ( V_156 ) ;
F_134 ( V_157 ) ;
F_135 ( V_158 ) ;
F_134 ( V_159 ) ;
F_134 ( V_160 ) ;
F_134 ( V_161 ) ;
F_134 ( V_162 ) ;
F_136 ( V_163 , V_74 ) ;
F_136 ( V_73 , V_74 ) ;
F_137 ( V_68 , V_70 ) ;
V_47 -> V_143 [ V_67 ] = NULL ;
V_67 = 0 ;
F_138 ( V_100 ) ;
V_47 -> V_145 [ V_67 ] = NULL ;
V_67 = 0 ;
F_139 ( V_164 ) ;
F_139 ( V_165 ) ;
F_139 ( V_166 ) ;
F_139 ( V_167 ) ;
F_139 ( V_168 ) ;
F_139 ( V_169 ) ;
F_140 ( V_170 ,
V_102 ) ;
F_140 ( V_171 ,
V_104 ) ;
V_47 -> V_147 [ V_67 ] = NULL ;
V_67 = 0 ;
F_141 ( V_172 ) ;
F_141 ( V_173 ) ;
F_141 ( V_174 ) ;
F_141 ( V_175 ) ;
F_141 ( V_176 ) ;
V_47 -> V_149 [ V_67 ] = NULL ;
V_67 = 0 ;
F_142 ( V_177 ) ;
F_142 ( V_178 ) ;
F_142 ( V_179 ) ;
F_142 ( V_180 ) ;
F_142 ( V_181 ) ;
F_142 ( V_182 ) ;
F_142 ( V_183 ) ;
V_47 -> V_151 [ V_67 ] = NULL ;
return & V_47 -> V_52 ;
}
void F_143 ( struct V_135 * V_52 )
{
struct V_46 * V_47 = F_9 ( V_52 ) ;
F_144 ( & V_47 -> V_52 . V_48 ) ;
F_144 ( & V_47 -> V_76 ) ;
F_144 ( & V_47 -> V_81 ) ;
F_144 ( & V_47 -> V_115 ) ;
F_144 ( & V_47 -> V_116 ) ;
F_144 ( & V_47 -> V_117 ) ;
F_49 ( V_47 ) ;
}
static T_5 int F_145 ( void )
{
int error ;
error = F_146 ( & V_51 ) ;
if ( error )
goto V_59;
error = F_146 ( & V_142 ) ;
if ( error )
goto V_184;
error = F_146 ( & V_144 ) ;
if ( error )
goto V_185;
error = F_146 ( & V_146 ) ;
if ( error )
goto V_186;
error = F_146 ( & V_148 ) ;
if ( error )
goto V_187;
error = F_146 ( & V_150 ) ;
if ( error )
goto V_188;
return 0 ;
V_188:
F_147 ( & V_148 ) ;
V_187:
F_147 ( & V_146 ) ;
V_186:
F_147 ( & V_144 ) ;
V_185:
F_147 ( & V_142 ) ;
V_184:
F_147 ( & V_51 ) ;
V_59:
return error ;
}
static void T_6 F_148 ( void )
{
F_147 ( & V_51 ) ;
F_147 ( & V_142 ) ;
F_147 ( & V_144 ) ;
F_147 ( & V_146 ) ;
F_147 ( & V_148 ) ;
F_147 ( & V_150 ) ;
}
