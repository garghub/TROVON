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
int F_42 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_55 ;
return V_14 -> V_19 -> V_48 . V_49 . V_50 ==
& V_51 . V_50 ;
}
void F_43 ( struct V_24 * V_25 )
{
F_44 ( V_25 , ( void * ) 0 , F_35 ) ;
F_44 ( V_25 , ( void * ) 1 , F_35 ) ;
}
void F_45 ( struct V_13 * V_14 )
{
F_43 ( & V_14 -> V_31 ) ;
}
T_1 F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_5 . V_8 . V_56 ;
}
unsigned int
F_47 ( struct V_2 * V_3 )
{
const int V_57 = 32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
char * V_58 = F_48 ( V_57 , V_59 ) ;
int V_17 = 0 ;
if ( F_49 ( V_3 , 0x90 , V_58 , V_57 ) )
goto V_60;
V_17 = V_58 [ 12 ] & 0x01 ;
V_60:
F_50 ( V_58 ) ;
V_7 -> V_61 = V_17 ;
return V_17 ;
}
void
F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_62 = 0 ;
}
void F_52 ( struct V_2 * V_3 )
{
unsigned int V_61 = 0 ;
V_61 = F_47 ( V_3 ) ;
if ( V_61 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_62 = 1 ;
}
return;
}
unsigned int F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_62 ;
}
static T_2
F_54 ( struct V_24 * V_25 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_66 * V_67 = F_55 ( V_25 ) ;
if ( ! V_67 -> V_8 . V_9 )
return snprintf ( V_65 , 20 , L_4 ) ;
return F_56 ( V_67 -> V_8 . V_9 , V_65 ) ;
}
static T_2 F_57 ( struct V_24 * V_25 ,
T_3 V_68 , int V_69 )
{
struct V_66 * V_67 = F_55 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_67 -> V_25 . V_70 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int error ;
error = V_47 -> V_20 -> V_71 ( V_67 , V_69 ) ;
if ( error )
return error ;
V_67 -> V_72 = V_69 ;
return V_68 ;
}
static T_2
F_58 ( struct V_24 * V_25 , struct V_63 * V_64 ,
const char * V_65 , T_3 V_68 )
{
if ( V_68 < 1 )
return - V_73 ;
switch ( V_65 [ 0 ] ) {
case '0' :
F_57 ( V_25 , V_68 , 0 ) ;
break;
case '1' :
F_57 ( V_25 , V_68 , 1 ) ;
break;
default:
return - V_73 ;
}
return V_68 ;
}
static T_2
F_59 ( struct V_24 * V_25 , struct V_63 * V_64 ,
char * V_65 )
{
struct V_66 * V_67 = F_55 ( V_25 ) ;
return snprintf ( V_65 , 20 , L_5 , V_67 -> V_72 ) ;
}
static T_2
F_60 ( struct V_24 * V_25 , T_3 V_68 , int V_74 )
{
struct V_66 * V_67 = F_55 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_67 -> V_25 . V_70 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int error ;
error = V_47 -> V_20 -> V_75 ( V_67 , V_74 ) ;
if ( error )
return error ;
V_67 -> V_72 = 1 ;
return V_68 ;
}
static T_2
F_61 ( struct V_24 * V_25 , struct V_63 * V_64 ,
const char * V_65 , T_3 V_68 )
{
return F_60 ( V_25 , V_68 , 0 ) ;
}
static T_2
F_62 ( struct V_24 * V_25 , struct V_63 * V_64 ,
const char * V_65 , T_3 V_68 )
{
return F_60 ( V_25 , V_68 , 1 ) ;
}
static int F_63 ( struct V_35 * V_36 , struct V_24 * V_25 ,
struct V_24 * V_37 )
{
struct V_66 * V_67 = F_41 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_67 -> V_25 . V_70 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
if ( V_47 -> V_20 -> V_76 )
V_47 -> V_20 -> V_76 ( V_67 ) ;
return 0 ;
}
static int F_64 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_39 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_70 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_77 . V_49 == V_45 ;
}
static void F_65 ( struct V_24 * V_25 )
{
struct V_66 * V_67 = F_41 ( V_25 ) ;
struct V_13 * V_14 = F_16 ( V_67 -> V_25 . V_70 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
if ( V_47 -> V_20 -> V_78 )
V_47 -> V_20 -> V_78 ( V_67 ) ;
F_66 ( V_25 -> V_70 ) ;
F_50 ( V_67 ) ;
}
struct V_66 * F_67 ( struct V_24 * V_70 , int V_79 )
{
struct V_13 * V_14 = F_16 ( V_70 ) ;
struct V_66 * V_67 ;
V_67 = F_48 ( sizeof( * V_67 ) , V_59 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_79 = V_79 ;
V_67 -> V_72 = 1 ;
F_68 ( & V_67 -> V_25 ) ;
V_67 -> V_25 . V_70 = F_69 ( V_70 ) ;
V_67 -> V_25 . F_20 = F_65 ;
F_29 ( & V_67 -> V_80 ) ;
if ( F_70 ( V_70 ) ) {
struct V_4 * V_5 = F_71 ( V_70 ) ;
F_72 ( & V_67 -> V_25 , L_6 , V_14 -> V_32 ,
V_5 -> V_81 , V_79 ) ;
} else
F_72 ( & V_67 -> V_25 , L_7 , V_14 -> V_32 , V_79 ) ;
F_73 ( & V_67 -> V_25 ) ;
return V_67 ;
}
int F_74 ( struct V_66 * V_67 )
{
int error ;
error = F_75 ( & V_67 -> V_25 ) ;
if ( ! error ) {
F_76 ( & V_67 -> V_25 ) ;
F_77 ( & V_67 -> V_25 ) ;
}
return error ;
}
void F_78 ( struct V_66 * V_67 )
{
F_79 ( & V_67 -> V_25 ) ;
F_66 ( & V_67 -> V_25 ) ;
}
void
F_40 ( struct V_66 * V_67 )
{
struct V_24 * V_25 = & V_67 -> V_25 ;
F_3 ( ! F_80 ( & V_67 -> V_80 ) ) ;
F_81 ( V_25 ) ;
F_82 ( V_25 ) ;
F_79 ( V_25 ) ;
F_66 ( V_25 ) ;
}
int F_39 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_65 ;
}
static int F_83 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_36 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_70 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_82 . V_49 == V_45 ;
}
static void F_84 ( struct V_24 * V_25 )
{
struct V_83 * V_84 = F_38 ( V_25 ) ;
F_3 ( ! F_80 ( & V_84 -> V_85 ) ) ;
F_66 ( V_25 -> V_70 ) ;
F_50 ( V_84 ) ;
}
static void F_85 ( struct V_83 * V_84 ,
struct V_66 * V_67 )
{
int V_86 ;
V_86 = F_86 ( & V_84 -> V_25 . V_87 , & V_67 -> V_25 . V_87 ,
F_23 ( & V_67 -> V_25 ) ) ;
if ( V_86 )
goto V_88;
V_86 = F_86 ( & V_67 -> V_25 . V_87 , & V_84 -> V_25 . V_87 , L_8 ) ;
if ( V_86 )
goto V_88;
return;
V_88:
F_21 ( V_43 L_9 ,
V_89 , V_86 ) ;
}
static void F_87 ( struct V_83 * V_84 ,
struct V_66 * V_67 )
{
F_88 ( & V_84 -> V_25 . V_87 , F_23 ( & V_67 -> V_25 ) ) ;
F_88 ( & V_67 -> V_25 . V_87 , L_8 ) ;
}
struct V_83 * F_89 ( struct V_24 * V_70 , int V_90 )
{
struct V_13 * V_14 = F_16 ( V_70 ) ;
struct V_83 * V_84 ;
V_84 = F_48 ( sizeof( * V_84 ) , V_59 ) ;
if ( ! V_84 )
return NULL ;
V_84 -> V_91 = V_90 ;
F_68 ( & V_84 -> V_25 ) ;
V_84 -> V_25 . V_70 = F_69 ( V_70 ) ;
V_84 -> V_25 . F_20 = F_84 ;
F_30 ( & V_84 -> V_92 ) ;
F_29 ( & V_84 -> V_85 ) ;
if ( F_70 ( V_70 ) ) {
struct V_4 * V_5 = F_71 ( V_70 ) ;
F_72 ( & V_84 -> V_25 , L_10 , V_14 -> V_32 ,
V_5 -> V_81 , V_84 -> V_91 ) ;
} else
F_72 ( & V_84 -> V_25 , L_11 , V_14 -> V_32 ,
V_84 -> V_91 ) ;
F_73 ( & V_84 -> V_25 ) ;
return V_84 ;
}
struct V_83 * F_90 ( struct V_24 * V_70 )
{
int V_93 ;
struct V_13 * V_14 = F_16 ( V_70 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_91 ( & V_27 -> V_39 ) ;
if ( F_70 ( V_70 ) ) {
struct V_4 * V_5 = F_71 ( V_70 ) ;
struct V_94 * exp = F_92 ( V_5 ) ;
V_93 = exp -> V_42 ++ ;
} else
V_93 = V_27 -> V_42 ++ ;
F_93 ( & V_27 -> V_39 ) ;
return F_89 ( V_70 , V_93 ) ;
}
int F_94 ( struct V_83 * V_84 )
{
int error ;
F_3 ( ! F_80 ( & V_84 -> V_85 ) ) ;
error = F_75 ( & V_84 -> V_25 ) ;
if ( error )
return error ;
F_76 ( & V_84 -> V_25 ) ;
F_77 ( & V_84 -> V_25 ) ;
return 0 ;
}
void F_95 ( struct V_83 * V_84 )
{
F_79 ( & V_84 -> V_25 ) ;
F_66 ( & V_84 -> V_25 ) ;
}
void F_37 ( struct V_83 * V_84 )
{
struct V_24 * V_25 = & V_84 -> V_25 ;
struct V_66 * V_67 , * V_95 ;
if ( V_84 -> V_5 ) {
F_96 ( V_84 -> V_5 ) ;
V_84 -> V_5 = NULL ;
}
F_91 ( & V_84 -> V_92 ) ;
F_97 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_87 ( V_84 , V_67 ) ;
F_98 ( & V_67 -> V_80 ) ;
}
F_93 ( & V_84 -> V_92 ) ;
if ( V_84 -> V_96 ) {
struct V_24 * V_70 = V_84 -> V_25 . V_70 ;
F_88 ( & V_84 -> V_25 . V_87 , F_23 ( V_70 ) ) ;
V_84 -> V_96 = 0 ;
}
F_81 ( V_25 ) ;
F_82 ( V_25 ) ;
F_79 ( V_25 ) ;
F_66 ( V_25 ) ;
}
int F_36 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_84 ;
}
struct V_66 * F_99 ( struct V_83 * V_84 )
{
struct V_66 * V_67 ;
F_91 ( & V_84 -> V_92 ) ;
if ( F_80 ( & V_84 -> V_85 ) )
V_67 = NULL ;
else {
struct V_97 * V_98 = V_84 -> V_85 . V_99 ;
V_67 = F_100 ( V_98 , F_101 ( * V_67 ) , V_80 ) ;
F_69 ( & V_67 -> V_25 ) ;
}
F_93 ( & V_84 -> V_92 ) ;
return V_67 ;
}
void F_102 ( struct V_83 * V_84 , struct V_66 * V_67 )
{
F_91 ( & V_84 -> V_92 ) ;
if ( F_103 ( ! F_80 ( & V_67 -> V_80 ) ) ) {
struct V_66 * V_100 ;
F_104 (tmp, &port->phy_list, port_siblings)
if ( V_100 == V_67 )
break;
if ( F_103 ( V_100 != V_67 ) ) {
F_31 ( V_43 , & V_84 -> V_25 , L_12 ,
F_23 ( & V_67 -> V_25 ) ) ;
F_105 () ;
}
} else {
F_85 ( V_84 , V_67 ) ;
F_106 ( & V_67 -> V_80 , & V_84 -> V_85 ) ;
V_84 -> V_101 ++ ;
}
F_93 ( & V_84 -> V_92 ) ;
}
void F_107 ( struct V_83 * V_84 , struct V_66 * V_67 )
{
F_91 ( & V_84 -> V_92 ) ;
F_87 ( V_84 , V_67 ) ;
F_98 ( & V_67 -> V_80 ) ;
V_84 -> V_101 -- ;
F_93 ( & V_84 -> V_92 ) ;
}
void F_108 ( struct V_83 * V_84 )
{
int V_86 ;
struct V_24 * V_70 = V_84 -> V_25 . V_70 -> V_70 -> V_70 ;
if ( V_84 -> V_96 )
return;
V_84 -> V_96 = 1 ;
V_86 = F_86 ( & V_84 -> V_25 . V_87 , & V_70 -> V_87 ,
F_23 ( V_70 ) ) ;
if ( V_86 )
goto V_88;
return;
V_88:
F_21 ( V_43 L_13 ,
V_89 , V_86 ) ;
}
static T_2
F_109 ( struct V_24 * V_25 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_4 * V_5 = F_110 ( V_25 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_65 , 20 , L_4 ) ;
return F_56 (
V_5 -> V_8 . V_9 , V_65 ) ;
}
static T_2
F_111 ( struct V_24 * V_25 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_4 * V_5 = F_110 ( V_25 ) ;
struct V_66 * V_67 = F_41 ( V_5 -> V_25 . V_70 ) ;
struct V_13 * V_14 = F_16 ( V_67 -> V_25 . V_70 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
T_1 V_102 ;
int error ;
error = V_47 -> V_20 -> V_103 ( V_5 , & V_102 ) ;
if ( error )
return error ;
return sprintf ( V_65 , L_14 , ( unsigned long long ) V_102 ) ;
}
static T_2
F_112 ( struct V_24 * V_25 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_4 * V_5 = F_110 ( V_25 ) ;
struct V_66 * V_67 = F_41 ( V_5 -> V_25 . V_70 ) ;
struct V_13 * V_14 = F_16 ( V_67 -> V_25 . V_70 ) ;
struct V_46 * V_47 = F_9 ( V_14 -> V_19 ) ;
int V_104 ;
V_104 = V_47 -> V_20 -> V_105 ( V_5 ) ;
if ( V_104 < 0 )
return V_104 ;
return sprintf ( V_65 , L_15 , V_104 ) ;
}
int F_113 ( struct V_2 * V_3 )
{
char * V_58 = F_48 ( V_106 , V_59 ) , * V_107 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_108 V_109 ;
int V_86 , error ;
if ( ! V_58 )
return - V_33 ;
V_86 = F_114 ( V_3 , 1 , 0x19 , V_58 , V_106 , 30 * V_110 , 3 ,
& V_109 , NULL ) ;
error = - V_73 ;
if ( ! F_115 ( V_86 ) )
goto V_60;
V_107 = V_58 + V_109 . V_111 +
V_109 . V_112 ;
if ( V_107 - V_58 > V_106 - 8 )
goto V_60;
error = 0 ;
V_7 -> V_113 = V_107 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_114 = ( V_107 [ 4 ] << 8 ) + V_107 [ 5 ] ;
V_7 -> V_115 = ( V_107 [ 6 ] << 8 ) + V_107 [ 7 ] ;
V_60:
F_50 ( V_58 ) ;
return error ;
}
static int F_116 ( struct V_44 * V_45 , struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
if ( ! F_117 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_70 -> V_70 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_116 . V_49 == V_45 ;
}
static int F_118 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_117 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_70 -> V_70 ) ;
V_5 = F_71 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_117 . V_49 == V_45 &&
V_5 -> V_8 . V_9 == V_10 ;
}
static int F_119 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_13 * V_14 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
if ( ! F_117 ( V_25 ) )
return 0 ;
V_14 = F_16 ( V_25 -> V_70 -> V_70 ) ;
V_5 = F_71 ( V_25 ) ;
if ( ! V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_19 -> V_48 . V_49 . V_50 !=
& V_51 . V_50 )
return 0 ;
V_47 = F_9 ( V_14 -> V_19 ) ;
return & V_47 -> V_118 . V_49 == V_45 &&
( V_5 -> V_8 . V_9 == V_119 ||
V_5 -> V_8 . V_9 == V_120 ) ;
}
static void F_120 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_71 ( V_25 ) ;
struct V_94 * V_121 = F_92 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_66 ( V_25 -> V_70 ) ;
F_50 ( V_121 ) ;
}
static void F_121 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_71 ( V_25 ) ;
struct V_1 * V_121 = F_4 ( V_5 ) ;
if ( V_5 -> V_12 )
F_18 ( V_5 -> V_12 ) ;
F_66 ( V_25 -> V_70 ) ;
F_50 ( V_121 ) ;
}
static void F_122 ( struct V_4 * V_5 )
{
F_29 ( & V_5 -> V_122 ) ;
}
struct V_4 * F_123 ( struct V_83 * V_70 )
{
struct V_13 * V_14 = F_16 ( & V_70 -> V_25 ) ;
struct V_1 * V_7 ;
V_7 = F_48 ( sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_68 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_70 = F_69 ( & V_70 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_121 ;
if ( F_70 ( V_70 -> V_25 . V_70 ) ) {
struct V_4 * V_5 = F_71 ( V_70 -> V_25 . V_70 ) ;
F_72 ( & V_7 -> V_5 . V_25 , L_16 ,
V_14 -> V_32 , V_5 -> V_81 ,
V_70 -> V_91 ) ;
} else
F_72 ( & V_7 -> V_5 . V_25 , L_17 ,
V_14 -> V_32 , V_70 -> V_91 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_122 ( & V_7 -> V_5 ) ;
F_73 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_124 ( struct V_83 * V_70 ,
enum V_123 type )
{
struct V_13 * V_14 = F_16 ( & V_70 -> V_25 ) ;
struct V_94 * V_7 ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_3 ( type != V_119 &&
type != V_120 ) ;
V_7 = F_48 ( sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_68 ( & V_7 -> V_5 . V_25 ) ;
V_7 -> V_5 . V_25 . V_70 = F_69 ( & V_70 -> V_25 ) ;
V_7 -> V_5 . V_25 . F_20 = F_120 ;
F_91 ( & V_27 -> V_39 ) ;
V_7 -> V_5 . V_81 = V_27 -> V_41 ++ ;
F_93 ( & V_27 -> V_39 ) ;
F_72 ( & V_7 -> V_5 . V_25 , L_18 ,
V_14 -> V_32 , V_7 -> V_5 . V_81 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_122 ( & V_7 -> V_5 ) ;
F_73 ( & V_7 -> V_5 . V_25 ) ;
return & V_7 -> V_5 ;
}
int F_125 ( struct V_4 * V_5 )
{
struct V_83 * V_70 = F_38 ( V_5 -> V_25 . V_70 ) ;
struct V_13 * V_14 = F_16 ( V_70 -> V_25 . V_70 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_124 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_70 -> V_5 )
return - V_125 ;
V_70 -> V_5 = V_5 ;
error = F_75 ( & V_5 -> V_25 ) ;
if ( error )
return error ;
F_76 ( & V_5 -> V_25 ) ;
F_77 ( & V_5 -> V_25 ) ;
if ( F_19 ( V_14 , V_5 ) )
F_21 ( L_19 , F_23 ( & V_5 -> V_25 ) ) ;
F_91 ( & V_27 -> V_39 ) ;
F_106 ( & V_5 -> V_122 , & V_27 -> V_38 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_126 &
( V_127 | V_128 | V_129 ) ) )
V_5 -> V_81 = V_27 -> V_40 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_81 = - 1 ;
F_93 ( & V_27 -> V_39 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_81 != - 1 ) {
int V_130 ;
if ( V_8 -> V_126 & V_127 )
V_130 = V_131 ;
else
V_130 = 0 ;
F_126 ( & V_5 -> V_25 , 0 , V_5 -> V_81 , V_130 ,
V_132 ) ;
}
return 0 ;
}
void F_127 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
struct V_13 * V_14 = F_16 ( V_5 -> V_25 . V_70 -> V_70 ) ;
struct V_26 * V_27 = F_17 ( V_14 ) ;
F_91 ( & V_27 -> V_39 ) ;
F_128 ( & V_5 -> V_122 ) ;
F_93 ( & V_27 -> V_39 ) ;
F_79 ( V_25 ) ;
F_66 ( V_25 ) ;
}
void
F_96 ( struct V_4 * V_5 )
{
F_129 ( V_5 ) ;
F_127 ( V_5 ) ;
}
void F_130 ( struct V_4 * V_5 )
{
struct V_83 * V_70 = F_38 ( V_5 -> V_25 . V_70 ) ;
V_70 -> V_5 = NULL ;
}
void
F_129 ( struct V_4 * V_5 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_131 ( V_25 ) ;
break;
case V_119 :
case V_120 :
F_43 ( V_25 ) ;
break;
default:
break;
}
F_130 ( V_5 ) ;
F_26 ( NULL , V_5 ) ;
F_81 ( V_25 ) ;
F_82 ( V_25 ) ;
}
int F_117 ( const struct V_24 * V_25 )
{
return V_25 -> F_20 == F_121 ||
V_25 -> F_20 == F_120 ;
}
static int F_132 ( struct V_13 * V_14 , T_4 V_133 ,
T_4 V_134 , T_1 V_130 )
{
struct V_26 * V_27 = F_17 ( V_14 ) ;
struct V_4 * V_5 ;
F_91 ( & V_27 -> V_39 ) ;
F_104 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_81 == - 1 )
continue;
if ( ( V_133 == V_131 || V_133 == 0 ) &&
( V_134 == V_131 || V_134 == V_5 -> V_81 ) ) {
F_126 ( & V_5 -> V_25 , 0 , V_5 -> V_81 ,
V_130 , V_135 ) ;
}
}
F_93 ( & V_27 -> V_39 ) ;
return 0 ;
}
struct V_136 *
F_133 ( struct V_137 * V_138 )
{
struct V_46 * V_47 ;
int V_68 ;
V_47 = F_48 ( sizeof( struct V_46 ) , V_59 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_52 . V_139 = F_132 ;
V_47 -> V_52 . V_48 . V_49 . V_140 = & V_47 -> V_48 [ 0 ] ;
V_47 -> V_52 . V_48 . V_49 . V_50 = & V_51 . V_50 ;
V_47 -> V_52 . V_48 . V_49 . V_141 = F_33 ;
F_134 ( & V_47 -> V_52 . V_48 ) ;
V_47 -> V_52 . V_142 = sizeof( struct V_26 ) ;
V_47 -> V_77 . V_49 . V_50 = & V_143 . V_50 ;
V_47 -> V_77 . V_49 . V_140 = & V_47 -> V_144 [ 0 ] ;
V_47 -> V_77 . V_49 . V_141 = F_64 ;
F_134 ( & V_47 -> V_77 ) ;
V_47 -> V_82 . V_49 . V_50 = & V_145 . V_50 ;
V_47 -> V_82 . V_49 . V_140 = & V_47 -> V_146 [ 0 ] ;
V_47 -> V_82 . V_49 . V_141 = F_83 ;
F_134 ( & V_47 -> V_82 ) ;
V_47 -> V_116 . V_49 . V_50 = & V_147 . V_50 ;
V_47 -> V_116 . V_49 . V_140 = & V_47 -> V_148 [ 0 ] ;
V_47 -> V_116 . V_49 . V_141 = F_116 ;
F_134 ( & V_47 -> V_116 ) ;
V_47 -> V_117 . V_49 . V_50 = & V_149 . V_50 ;
V_47 -> V_117 . V_49 . V_140 = & V_47 -> V_150 [ 0 ] ;
V_47 -> V_117 . V_49 . V_141 = F_118 ;
F_134 ( & V_47 -> V_117 ) ;
V_47 -> V_118 . V_49 . V_50 = & V_151 . V_50 ;
V_47 -> V_118 . V_49 . V_140 = & V_47 -> V_152 [ 0 ] ;
V_47 -> V_118 . V_49 . V_141 = F_119 ;
F_134 ( & V_47 -> V_118 ) ;
V_47 -> V_20 = V_138 ;
V_68 = 0 ;
F_135 ( V_153 ) ;
F_135 ( V_126 ) ;
F_135 ( V_9 ) ;
F_135 ( V_56 ) ;
F_135 ( V_154 ) ;
F_135 ( V_155 ) ;
F_135 ( V_156 ) ;
F_136 ( V_157 ) ;
F_135 ( V_158 ) ;
F_136 ( V_159 ) ;
F_135 ( V_160 ) ;
F_135 ( V_161 ) ;
F_135 ( V_162 ) ;
F_135 ( V_163 ) ;
F_137 ( V_164 , V_75 ) ;
F_137 ( V_74 , V_75 ) ;
F_138 ( V_69 , V_71 ) ;
V_47 -> V_144 [ V_68 ] = NULL ;
V_68 = 0 ;
F_139 ( V_101 ) ;
V_47 -> V_146 [ V_68 ] = NULL ;
V_68 = 0 ;
F_140 ( V_165 ) ;
F_140 ( V_166 ) ;
F_140 ( V_167 ) ;
F_140 ( V_168 ) ;
F_140 ( V_169 ) ;
F_140 ( V_170 ) ;
F_141 ( V_171 ,
V_103 ) ;
F_141 ( V_172 ,
V_105 ) ;
V_47 -> V_148 [ V_68 ] = NULL ;
V_68 = 0 ;
F_142 ( V_173 ) ;
F_142 ( V_174 ) ;
F_142 ( V_175 ) ;
F_142 ( V_176 ) ;
F_142 ( V_177 ) ;
V_47 -> V_150 [ V_68 ] = NULL ;
V_68 = 0 ;
F_143 ( V_178 ) ;
F_143 ( V_179 ) ;
F_143 ( V_180 ) ;
F_143 ( V_181 ) ;
F_143 ( V_182 ) ;
F_143 ( V_183 ) ;
F_143 ( V_184 ) ;
V_47 -> V_152 [ V_68 ] = NULL ;
return & V_47 -> V_52 ;
}
void F_144 ( struct V_136 * V_52 )
{
struct V_46 * V_47 = F_9 ( V_52 ) ;
F_145 ( & V_47 -> V_52 . V_48 ) ;
F_145 ( & V_47 -> V_77 ) ;
F_145 ( & V_47 -> V_82 ) ;
F_145 ( & V_47 -> V_116 ) ;
F_145 ( & V_47 -> V_117 ) ;
F_145 ( & V_47 -> V_118 ) ;
F_50 ( V_47 ) ;
}
static T_5 int F_146 ( void )
{
int error ;
error = F_147 ( & V_51 ) ;
if ( error )
goto V_60;
error = F_147 ( & V_143 ) ;
if ( error )
goto V_185;
error = F_147 ( & V_145 ) ;
if ( error )
goto V_186;
error = F_147 ( & V_147 ) ;
if ( error )
goto V_187;
error = F_147 ( & V_149 ) ;
if ( error )
goto V_188;
error = F_147 ( & V_151 ) ;
if ( error )
goto V_189;
return 0 ;
V_189:
F_148 ( & V_149 ) ;
V_188:
F_148 ( & V_147 ) ;
V_187:
F_148 ( & V_145 ) ;
V_186:
F_148 ( & V_143 ) ;
V_185:
F_148 ( & V_51 ) ;
V_60:
return error ;
}
static void T_6 F_149 ( void )
{
F_148 ( & V_51 ) ;
F_148 ( & V_143 ) ;
F_148 ( & V_145 ) ;
F_148 ( & V_147 ) ;
F_148 ( & V_149 ) ;
F_148 ( & V_151 ) ;
}
