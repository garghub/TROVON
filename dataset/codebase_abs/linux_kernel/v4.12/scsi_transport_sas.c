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
F_9 ( V_16 ) -> V_19 = F_10 ( V_16 ) ;
if ( V_16 -> V_20 )
F_9 ( V_16 -> V_20 ) -> V_19 =
F_10 ( V_16 -> V_20 ) ;
F_6 = F_11 ( V_14 -> V_21 ) -> V_22 -> V_23 ;
V_17 = F_6 ( V_14 , V_5 , V_16 ) ;
F_9 ( V_16 ) -> V_24 = V_17 ;
F_12 ( V_16 , 0 ) ;
F_13 ( V_12 -> V_18 ) ;
}
}
static void F_14 ( struct V_11 * V_12 )
{
F_5 ( V_12 , (struct V_13 * ) V_12 -> V_25 , NULL ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_25 ;
F_5 ( V_12 , F_16 ( V_5 ) , V_5 ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
struct V_11 * V_12 = V_29 -> V_12 ;
if ( V_12 )
F_20 ( V_12 ) ;
}
static int F_21 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_11 * V_12 ;
int error ;
struct V_26 * V_27 ;
char V_30 [ 20 ] ;
const char * V_31 ;
void (* F_22)( struct V_26 * );
if ( ! F_11 ( V_14 -> V_21 ) -> V_22 -> V_23 ) {
F_23 ( L_1 , V_14 -> V_32 -> V_31 ) ;
return 0 ;
}
V_12 = F_24 ( V_33 ) ;
if ( ! V_12 )
return - V_34 ;
V_12 -> V_35 = sizeof( struct V_36 ) ;
if ( V_5 ) {
V_12 -> V_37 = F_15 ;
V_27 = & V_5 -> V_27 ;
V_31 = F_25 ( V_27 ) ;
F_22 = NULL ;
} else {
V_12 -> V_37 = F_14 ;
V_27 = & V_14 -> V_38 ;
snprintf ( V_30 , sizeof( V_30 ) ,
L_2 , V_14 -> V_39 ) ;
V_31 = V_30 ;
F_22 = F_17 ;
}
error = F_26 ( V_12 ) ;
if ( error )
goto V_40;
error = F_27 ( V_12 , V_27 , V_31 , F_22 ) ;
if ( error )
goto V_40;
if ( V_5 )
V_5 -> V_12 = V_12 ;
else
F_19 ( V_14 ) -> V_12 = V_12 ;
if ( V_5 )
V_12 -> V_25 = V_5 ;
else
V_12 -> V_25 = V_14 ;
F_28 ( V_41 , V_12 ) ;
return 0 ;
V_40:
F_20 ( V_12 ) ;
return error ;
}
static void F_29 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_11 * V_12 ;
if ( V_5 )
V_12 = V_5 -> V_12 ;
else
V_12 = F_19 ( V_14 ) -> V_12 ;
if ( ! V_12 )
return;
F_30 ( V_12 ) ;
}
static int F_31 ( struct V_42 * V_43 , struct V_26 * V_27 ,
struct V_26 * V_44 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_32 ( & V_29 -> V_45 ) ;
F_33 ( & V_29 -> V_46 ) ;
V_29 -> V_47 = 0 ;
V_29 -> V_48 = 0 ;
V_29 -> V_49 = 0 ;
if ( F_21 ( V_14 , NULL ) )
F_34 ( V_50 , V_27 , L_3 ,
V_14 -> V_39 ) ;
return 0 ;
}
static int F_35 ( struct V_42 * V_43 , struct V_26 * V_27 ,
struct V_26 * V_44 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
F_29 ( V_14 , NULL ) ;
return 0 ;
}
static int F_36 ( struct V_51 * V_52 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 ;
if ( ! F_37 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_55 . V_56 . V_57 !=
& V_58 . V_57 )
return 0 ;
V_54 = F_11 ( V_14 -> V_21 ) ;
return & V_54 -> V_59 . V_55 . V_56 == V_52 ;
}
static int F_38 ( struct V_26 * V_27 , void * V_60 )
{
int V_61 = ( int ) ( unsigned long ) V_60 ;
if ( V_61 == 0 && F_39 ( V_27 ) )
F_40 ( F_41 ( V_27 ) ) ;
else if ( V_61 == 1 && F_42 ( V_27 ) )
F_43 ( F_44 ( V_27 ) ) ;
return 0 ;
}
void F_45 ( struct V_26 * V_27 )
{
F_46 ( V_27 , ( void * ) 0 , F_38 ) ;
F_46 ( V_27 , ( void * ) 1 , F_38 ) ;
}
void F_47 ( struct V_13 * V_14 )
{
F_45 ( & V_14 -> V_38 ) ;
F_48 ( V_14 ) ;
}
T_1 F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_5 . V_8 . V_62 ;
}
unsigned int
F_50 ( struct V_2 * V_3 )
{
const int V_63 = 32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
char * V_64 = F_51 ( V_63 , V_33 ) ;
int V_17 = 0 ;
if ( F_52 ( V_3 , 0x90 , V_64 , V_63 ) )
goto V_65;
V_17 = V_64 [ 12 ] & 0x01 ;
V_65:
F_53 ( V_64 ) ;
V_7 -> V_66 = V_17 ;
return V_17 ;
}
void
F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_67 = 0 ;
}
void F_55 ( struct V_2 * V_3 )
{
unsigned int V_66 = 0 ;
V_66 = F_50 ( V_3 ) ;
if ( V_66 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_67 = 1 ;
}
return;
}
unsigned int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_67 ;
}
static T_2
F_57 ( struct V_26 * V_27 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_71 * V_72 = F_58 ( V_27 ) ;
if ( ! V_72 -> V_8 . V_9 )
return snprintf ( V_70 , 20 , L_4 ) ;
return F_59 ( V_72 -> V_8 . V_9 , V_70 ) ;
}
static T_2 F_60 ( struct V_26 * V_27 ,
T_3 V_73 , int V_74 )
{
struct V_71 * V_72 = F_58 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_72 -> V_27 . V_75 ) ;
struct V_53 * V_54 = F_11 ( V_14 -> V_21 ) ;
int error ;
error = V_54 -> V_22 -> V_76 ( V_72 , V_74 ) ;
if ( error )
return error ;
V_72 -> V_77 = V_74 ;
return V_73 ;
}
static T_2
F_61 ( struct V_26 * V_27 , struct V_68 * V_69 ,
const char * V_70 , T_3 V_73 )
{
if ( V_73 < 1 )
return - V_78 ;
switch ( V_70 [ 0 ] ) {
case '0' :
F_60 ( V_27 , V_73 , 0 ) ;
break;
case '1' :
F_60 ( V_27 , V_73 , 1 ) ;
break;
default:
return - V_78 ;
}
return V_73 ;
}
static T_2
F_62 ( struct V_26 * V_27 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_71 * V_72 = F_58 ( V_27 ) ;
return snprintf ( V_70 , 20 , L_5 , V_72 -> V_77 ) ;
}
static T_2
F_63 ( struct V_26 * V_27 , T_3 V_73 , int V_79 )
{
struct V_71 * V_72 = F_58 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_72 -> V_27 . V_75 ) ;
struct V_53 * V_54 = F_11 ( V_14 -> V_21 ) ;
int error ;
error = V_54 -> V_22 -> V_80 ( V_72 , V_79 ) ;
if ( error )
return error ;
V_72 -> V_77 = 1 ;
return V_73 ;
}
static T_2
F_64 ( struct V_26 * V_27 , struct V_68 * V_69 ,
const char * V_70 , T_3 V_73 )
{
return F_63 ( V_27 , V_73 , 0 ) ;
}
static T_2
F_65 ( struct V_26 * V_27 , struct V_68 * V_69 ,
const char * V_70 , T_3 V_73 )
{
return F_63 ( V_27 , V_73 , 1 ) ;
}
static int F_66 ( struct V_42 * V_43 , struct V_26 * V_27 ,
struct V_26 * V_44 )
{
struct V_71 * V_72 = F_44 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_72 -> V_27 . V_75 ) ;
struct V_53 * V_54 = F_11 ( V_14 -> V_21 ) ;
if ( V_54 -> V_22 -> V_81 )
V_54 -> V_22 -> V_81 ( V_72 ) ;
return 0 ;
}
static int F_67 ( struct V_51 * V_52 , struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 ;
if ( ! F_42 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_75 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_55 . V_56 . V_57 !=
& V_58 . V_57 )
return 0 ;
V_54 = F_11 ( V_14 -> V_21 ) ;
return & V_54 -> V_82 . V_56 == V_52 ;
}
static void F_68 ( struct V_26 * V_27 )
{
struct V_71 * V_72 = F_44 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_72 -> V_27 . V_75 ) ;
struct V_53 * V_54 = F_11 ( V_14 -> V_21 ) ;
if ( V_54 -> V_22 -> V_83 )
V_54 -> V_22 -> V_83 ( V_72 ) ;
F_69 ( V_27 -> V_75 ) ;
F_53 ( V_72 ) ;
}
struct V_71 * F_70 ( struct V_26 * V_75 , int V_84 )
{
struct V_13 * V_14 = F_18 ( V_75 ) ;
struct V_71 * V_72 ;
V_72 = F_51 ( sizeof( * V_72 ) , V_33 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> V_84 = V_84 ;
V_72 -> V_77 = 1 ;
F_71 ( & V_72 -> V_27 ) ;
V_72 -> V_27 . V_75 = F_72 ( V_75 ) ;
V_72 -> V_27 . F_22 = F_68 ;
F_32 ( & V_72 -> V_85 ) ;
if ( F_73 ( V_75 ) ) {
struct V_4 * V_5 = F_74 ( V_75 ) ;
F_75 ( & V_72 -> V_27 , L_6 , V_14 -> V_39 ,
V_5 -> V_86 , V_84 ) ;
} else
F_75 ( & V_72 -> V_27 , L_7 , V_14 -> V_39 , V_84 ) ;
F_76 ( & V_72 -> V_27 ) ;
return V_72 ;
}
int F_77 ( struct V_71 * V_72 )
{
int error ;
error = F_78 ( & V_72 -> V_27 ) ;
if ( ! error ) {
F_79 ( & V_72 -> V_27 ) ;
F_80 ( & V_72 -> V_27 ) ;
}
return error ;
}
void F_81 ( struct V_71 * V_72 )
{
F_82 ( & V_72 -> V_27 ) ;
F_69 ( & V_72 -> V_27 ) ;
}
void
F_43 ( struct V_71 * V_72 )
{
struct V_26 * V_27 = & V_72 -> V_27 ;
F_3 ( ! F_83 ( & V_72 -> V_85 ) ) ;
F_84 ( V_27 ) ;
F_85 ( V_27 ) ;
F_82 ( V_27 ) ;
F_69 ( V_27 ) ;
}
int F_42 ( const struct V_26 * V_27 )
{
return V_27 -> F_22 == F_68 ;
}
static int F_86 ( struct V_51 * V_52 , struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 ;
if ( ! F_39 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_75 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_55 . V_56 . V_57 !=
& V_58 . V_57 )
return 0 ;
V_54 = F_11 ( V_14 -> V_21 ) ;
return & V_54 -> V_87 . V_56 == V_52 ;
}
static void F_87 ( struct V_26 * V_27 )
{
struct V_88 * V_89 = F_41 ( V_27 ) ;
F_3 ( ! F_83 ( & V_89 -> V_90 ) ) ;
F_69 ( V_27 -> V_75 ) ;
F_53 ( V_89 ) ;
}
static void F_88 ( struct V_88 * V_89 ,
struct V_71 * V_72 )
{
int V_91 ;
V_91 = F_89 ( & V_89 -> V_27 . V_92 , & V_72 -> V_27 . V_92 ,
F_25 ( & V_72 -> V_27 ) ) ;
if ( V_91 )
goto V_93;
V_91 = F_89 ( & V_72 -> V_27 . V_92 , & V_89 -> V_27 . V_92 , L_8 ) ;
if ( V_91 )
goto V_93;
return;
V_93:
F_23 ( V_50 L_9 ,
V_94 , V_91 ) ;
}
static void F_90 ( struct V_88 * V_89 ,
struct V_71 * V_72 )
{
F_91 ( & V_89 -> V_27 . V_92 , F_25 ( & V_72 -> V_27 ) ) ;
F_91 ( & V_72 -> V_27 . V_92 , L_8 ) ;
}
struct V_88 * F_92 ( struct V_26 * V_75 , int V_95 )
{
struct V_13 * V_14 = F_18 ( V_75 ) ;
struct V_88 * V_89 ;
V_89 = F_51 ( sizeof( * V_89 ) , V_33 ) ;
if ( ! V_89 )
return NULL ;
V_89 -> V_96 = V_95 ;
F_71 ( & V_89 -> V_27 ) ;
V_89 -> V_27 . V_75 = F_72 ( V_75 ) ;
V_89 -> V_27 . F_22 = F_87 ;
F_33 ( & V_89 -> V_97 ) ;
F_32 ( & V_89 -> V_90 ) ;
if ( F_73 ( V_75 ) ) {
struct V_4 * V_5 = F_74 ( V_75 ) ;
F_75 ( & V_89 -> V_27 , L_10 , V_14 -> V_39 ,
V_5 -> V_86 , V_89 -> V_96 ) ;
} else
F_75 ( & V_89 -> V_27 , L_11 , V_14 -> V_39 ,
V_89 -> V_96 ) ;
F_76 ( & V_89 -> V_27 ) ;
return V_89 ;
}
struct V_88 * F_93 ( struct V_26 * V_75 )
{
int V_98 ;
struct V_13 * V_14 = F_18 ( V_75 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_94 ( & V_29 -> V_46 ) ;
if ( F_73 ( V_75 ) ) {
struct V_4 * V_5 = F_74 ( V_75 ) ;
struct V_99 * exp = F_95 ( V_5 ) ;
V_98 = exp -> V_49 ++ ;
} else
V_98 = V_29 -> V_49 ++ ;
F_96 ( & V_29 -> V_46 ) ;
return F_92 ( V_75 , V_98 ) ;
}
int F_97 ( struct V_88 * V_89 )
{
int error ;
F_3 ( ! F_83 ( & V_89 -> V_90 ) ) ;
error = F_78 ( & V_89 -> V_27 ) ;
if ( error )
return error ;
F_79 ( & V_89 -> V_27 ) ;
F_80 ( & V_89 -> V_27 ) ;
return 0 ;
}
void F_98 ( struct V_88 * V_89 )
{
F_82 ( & V_89 -> V_27 ) ;
F_69 ( & V_89 -> V_27 ) ;
}
void F_40 ( struct V_88 * V_89 )
{
struct V_26 * V_27 = & V_89 -> V_27 ;
struct V_71 * V_72 , * V_100 ;
if ( V_89 -> V_5 ) {
F_99 ( V_89 -> V_5 ) ;
V_89 -> V_5 = NULL ;
}
F_94 ( & V_89 -> V_97 ) ;
F_100 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_90 ( V_89 , V_72 ) ;
F_101 ( & V_72 -> V_85 ) ;
}
F_96 ( & V_89 -> V_97 ) ;
if ( V_89 -> V_101 ) {
struct V_26 * V_75 = V_89 -> V_27 . V_75 ;
F_91 ( & V_89 -> V_27 . V_92 , F_25 ( V_75 ) ) ;
V_89 -> V_101 = 0 ;
}
F_84 ( V_27 ) ;
F_85 ( V_27 ) ;
F_82 ( V_27 ) ;
F_69 ( V_27 ) ;
}
int F_39 ( const struct V_26 * V_27 )
{
return V_27 -> F_22 == F_87 ;
}
struct V_71 * F_102 ( struct V_88 * V_89 )
{
struct V_71 * V_72 ;
F_94 ( & V_89 -> V_97 ) ;
if ( F_83 ( & V_89 -> V_90 ) )
V_72 = NULL ;
else {
struct V_102 * V_103 = V_89 -> V_90 . V_104 ;
V_72 = F_103 ( V_103 , F_104 ( * V_72 ) , V_85 ) ;
F_72 ( & V_72 -> V_27 ) ;
}
F_96 ( & V_89 -> V_97 ) ;
return V_72 ;
}
void F_105 ( struct V_88 * V_89 , struct V_71 * V_72 )
{
F_94 ( & V_89 -> V_97 ) ;
if ( F_106 ( ! F_83 ( & V_72 -> V_85 ) ) ) {
struct V_71 * V_105 ;
F_107 (tmp, &port->phy_list, port_siblings)
if ( V_105 == V_72 )
break;
if ( F_106 ( V_105 != V_72 ) ) {
F_34 ( V_50 , & V_89 -> V_27 , L_12 ,
F_25 ( & V_72 -> V_27 ) ) ;
F_108 () ;
}
} else {
F_88 ( V_89 , V_72 ) ;
F_109 ( & V_72 -> V_85 , & V_89 -> V_90 ) ;
V_89 -> V_106 ++ ;
}
F_96 ( & V_89 -> V_97 ) ;
}
void F_110 ( struct V_88 * V_89 , struct V_71 * V_72 )
{
F_94 ( & V_89 -> V_97 ) ;
F_90 ( V_89 , V_72 ) ;
F_101 ( & V_72 -> V_85 ) ;
V_89 -> V_106 -- ;
F_96 ( & V_89 -> V_97 ) ;
}
void F_111 ( struct V_88 * V_89 )
{
int V_91 ;
struct V_26 * V_75 = V_89 -> V_27 . V_75 -> V_75 -> V_75 ;
if ( V_89 -> V_101 )
return;
V_89 -> V_101 = 1 ;
V_91 = F_89 ( & V_89 -> V_27 . V_92 , & V_75 -> V_92 ,
F_25 ( V_75 ) ) ;
if ( V_91 )
goto V_93;
return;
V_93:
F_23 ( V_50 L_13 ,
V_94 , V_91 ) ;
}
static T_2
F_112 ( struct V_26 * V_27 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_4 * V_5 = F_113 ( V_27 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_70 , 20 , L_4 ) ;
return F_59 (
V_5 -> V_8 . V_9 , V_70 ) ;
}
static T_2
F_114 ( struct V_26 * V_27 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_4 * V_5 = F_113 ( V_27 ) ;
struct V_71 * V_72 = F_44 ( V_5 -> V_27 . V_75 ) ;
struct V_13 * V_14 = F_18 ( V_72 -> V_27 . V_75 ) ;
struct V_53 * V_54 = F_11 ( V_14 -> V_21 ) ;
T_1 V_107 ;
int error ;
error = V_54 -> V_22 -> V_108 ( V_5 , & V_107 ) ;
if ( error )
return error ;
return sprintf ( V_70 , L_14 , ( unsigned long long ) V_107 ) ;
}
static T_2
F_115 ( struct V_26 * V_27 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_4 * V_5 = F_113 ( V_27 ) ;
struct V_71 * V_72 = F_44 ( V_5 -> V_27 . V_75 ) ;
struct V_13 * V_14 = F_18 ( V_72 -> V_27 . V_75 ) ;
struct V_53 * V_54 = F_11 ( V_14 -> V_21 ) ;
int V_109 ;
V_109 = V_54 -> V_22 -> V_110 ( V_5 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_70 , L_15 , V_109 ) ;
}
int F_116 ( struct V_2 * V_3 )
{
char * V_64 = F_51 ( V_111 , V_33 ) , * V_112 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_113 V_114 ;
int V_91 , error ;
if ( ! V_64 )
return - V_34 ;
V_91 = F_117 ( V_3 , 1 , 0x19 , V_64 , V_111 , 30 * V_115 , 3 ,
& V_114 , NULL ) ;
error = - V_78 ;
if ( ! F_118 ( V_91 ) )
goto V_65;
V_112 = V_64 + V_114 . V_116 +
V_114 . V_117 ;
if ( V_112 - V_64 > V_111 - 8 )
goto V_65;
error = 0 ;
V_7 -> V_118 = V_112 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_119 = ( V_112 [ 4 ] << 8 ) + V_112 [ 5 ] ;
V_7 -> V_120 = ( V_112 [ 6 ] << 8 ) + V_112 [ 7 ] ;
V_65:
F_53 ( V_64 ) ;
return error ;
}
static int F_119 ( struct V_51 * V_52 , struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 ;
if ( ! F_120 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_75 -> V_75 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_55 . V_56 . V_57 !=
& V_58 . V_57 )
return 0 ;
V_54 = F_11 ( V_14 -> V_21 ) ;
return & V_54 -> V_121 . V_56 == V_52 ;
}
static int F_121 ( struct V_51 * V_52 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 ;
struct V_4 * V_5 ;
if ( ! F_120 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_75 -> V_75 ) ;
V_5 = F_74 ( V_27 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_55 . V_56 . V_57 !=
& V_58 . V_57 )
return 0 ;
V_54 = F_11 ( V_14 -> V_21 ) ;
return & V_54 -> V_122 . V_56 == V_52 &&
V_5 -> V_8 . V_9 == V_10 ;
}
static int F_122 ( struct V_51 * V_52 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 ;
struct V_4 * V_5 ;
if ( ! F_120 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_75 -> V_75 ) ;
V_5 = F_74 ( V_27 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_55 . V_56 . V_57 !=
& V_58 . V_57 )
return 0 ;
V_54 = F_11 ( V_14 -> V_21 ) ;
return & V_54 -> V_123 . V_56 == V_52 &&
( V_5 -> V_8 . V_9 == V_124 ||
V_5 -> V_8 . V_9 == V_125 ) ;
}
static void F_123 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_74 ( V_27 ) ;
struct V_99 * V_126 = F_95 ( V_5 ) ;
if ( V_5 -> V_12 )
F_20 ( V_5 -> V_12 ) ;
F_69 ( V_27 -> V_75 ) ;
F_53 ( V_126 ) ;
}
static void F_124 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_74 ( V_27 ) ;
struct V_1 * V_126 = F_4 ( V_5 ) ;
if ( V_5 -> V_12 )
F_20 ( V_5 -> V_12 ) ;
F_69 ( V_27 -> V_75 ) ;
F_53 ( V_126 ) ;
}
static void F_125 ( struct V_4 * V_5 )
{
F_32 ( & V_5 -> V_127 ) ;
}
struct V_4 * F_126 ( struct V_88 * V_75 )
{
struct V_13 * V_14 = F_18 ( & V_75 -> V_27 ) ;
struct V_1 * V_7 ;
V_7 = F_51 ( sizeof( * V_7 ) , V_33 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_71 ( & V_7 -> V_5 . V_27 ) ;
V_7 -> V_5 . V_27 . V_75 = F_72 ( & V_75 -> V_27 ) ;
V_7 -> V_5 . V_27 . F_22 = F_124 ;
if ( F_73 ( V_75 -> V_27 . V_75 ) ) {
struct V_4 * V_5 = F_74 ( V_75 -> V_27 . V_75 ) ;
F_75 ( & V_7 -> V_5 . V_27 , L_16 ,
V_14 -> V_39 , V_5 -> V_86 ,
V_75 -> V_96 ) ;
} else
F_75 ( & V_7 -> V_5 . V_27 , L_17 ,
V_14 -> V_39 , V_75 -> V_96 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_125 ( & V_7 -> V_5 ) ;
F_76 ( & V_7 -> V_5 . V_27 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_127 ( struct V_88 * V_75 ,
enum V_128 type )
{
struct V_13 * V_14 = F_18 ( & V_75 -> V_27 ) ;
struct V_99 * V_7 ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_3 ( type != V_124 &&
type != V_125 ) ;
V_7 = F_51 ( sizeof( * V_7 ) , V_33 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_71 ( & V_7 -> V_5 . V_27 ) ;
V_7 -> V_5 . V_27 . V_75 = F_72 ( & V_75 -> V_27 ) ;
V_7 -> V_5 . V_27 . F_22 = F_123 ;
F_94 ( & V_29 -> V_46 ) ;
V_7 -> V_5 . V_86 = V_29 -> V_48 ++ ;
F_96 ( & V_29 -> V_46 ) ;
F_75 ( & V_7 -> V_5 . V_27 , L_18 ,
V_14 -> V_39 , V_7 -> V_5 . V_86 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_125 ( & V_7 -> V_5 ) ;
F_76 ( & V_7 -> V_5 . V_27 ) ;
return & V_7 -> V_5 ;
}
int F_128 ( struct V_4 * V_5 )
{
struct V_88 * V_75 = F_41 ( V_5 -> V_27 . V_75 ) ;
struct V_13 * V_14 = F_18 ( V_75 -> V_27 . V_75 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
struct V_129 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_75 -> V_5 )
return - V_130 ;
V_75 -> V_5 = V_5 ;
error = F_78 ( & V_5 -> V_27 ) ;
if ( error )
return error ;
F_79 ( & V_5 -> V_27 ) ;
F_80 ( & V_5 -> V_27 ) ;
if ( F_21 ( V_14 , V_5 ) )
F_23 ( L_19 , F_25 ( & V_5 -> V_27 ) ) ;
F_94 ( & V_29 -> V_46 ) ;
F_109 ( & V_5 -> V_127 , & V_29 -> V_45 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_131 &
( V_132 | V_133 | V_134 ) ) )
V_5 -> V_86 = V_29 -> V_47 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_86 = - 1 ;
F_96 ( & V_29 -> V_46 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_86 != - 1 ) {
int V_135 ;
if ( V_8 -> V_131 & V_132 )
V_135 = V_136 ;
else
V_135 = 0 ;
F_129 ( & V_5 -> V_27 , 0 , V_5 -> V_86 , V_135 ,
V_137 ) ;
}
return 0 ;
}
void F_130 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
struct V_13 * V_14 = F_18 ( V_5 -> V_27 . V_75 -> V_75 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_94 ( & V_29 -> V_46 ) ;
F_131 ( & V_5 -> V_127 ) ;
F_96 ( & V_29 -> V_46 ) ;
F_82 ( V_27 ) ;
F_69 ( V_27 ) ;
}
void
F_99 ( struct V_4 * V_5 )
{
F_132 ( V_5 ) ;
F_130 ( V_5 ) ;
}
void F_133 ( struct V_4 * V_5 )
{
struct V_88 * V_75 = F_41 ( V_5 -> V_27 . V_75 ) ;
V_75 -> V_5 = NULL ;
}
void
F_132 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_134 ( V_27 ) ;
break;
case V_124 :
case V_125 :
F_45 ( V_27 ) ;
break;
default:
break;
}
F_133 ( V_5 ) ;
F_29 ( NULL , V_5 ) ;
F_84 ( V_27 ) ;
F_85 ( V_27 ) ;
}
int F_120 ( const struct V_26 * V_27 )
{
return V_27 -> F_22 == F_124 ||
V_27 -> F_22 == F_123 ;
}
static int F_135 ( struct V_13 * V_14 , T_4 V_138 ,
T_4 V_139 , T_1 V_135 )
{
struct V_28 * V_29 = F_19 ( V_14 ) ;
struct V_4 * V_5 ;
F_94 ( & V_29 -> V_46 ) ;
F_107 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_86 == - 1 )
continue;
if ( ( V_138 == V_136 || V_138 == 0 ) &&
( V_139 == V_136 || V_139 == V_5 -> V_86 ) ) {
F_129 ( & V_5 -> V_27 , 0 , V_5 -> V_86 ,
V_135 , V_140 ) ;
}
}
F_96 ( & V_29 -> V_46 ) ;
return 0 ;
}
struct V_141 *
F_136 ( struct V_142 * V_143 )
{
struct V_53 * V_54 ;
int V_73 ;
V_54 = F_51 ( sizeof( struct V_53 ) , V_33 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_59 . V_144 = F_135 ;
V_54 -> V_59 . V_55 . V_56 . V_145 = & V_54 -> V_55 [ 0 ] ;
V_54 -> V_59 . V_55 . V_56 . V_57 = & V_58 . V_57 ;
V_54 -> V_59 . V_55 . V_56 . V_146 = F_36 ;
F_137 ( & V_54 -> V_59 . V_55 ) ;
V_54 -> V_59 . V_147 = sizeof( struct V_28 ) ;
V_54 -> V_82 . V_56 . V_57 = & V_148 . V_57 ;
V_54 -> V_82 . V_56 . V_145 = & V_54 -> V_149 [ 0 ] ;
V_54 -> V_82 . V_56 . V_146 = F_67 ;
F_137 ( & V_54 -> V_82 ) ;
V_54 -> V_87 . V_56 . V_57 = & V_150 . V_57 ;
V_54 -> V_87 . V_56 . V_145 = & V_54 -> V_151 [ 0 ] ;
V_54 -> V_87 . V_56 . V_146 = F_86 ;
F_137 ( & V_54 -> V_87 ) ;
V_54 -> V_121 . V_56 . V_57 = & V_152 . V_57 ;
V_54 -> V_121 . V_56 . V_145 = & V_54 -> V_153 [ 0 ] ;
V_54 -> V_121 . V_56 . V_146 = F_119 ;
F_137 ( & V_54 -> V_121 ) ;
V_54 -> V_122 . V_56 . V_57 = & V_154 . V_57 ;
V_54 -> V_122 . V_56 . V_145 = & V_54 -> V_155 [ 0 ] ;
V_54 -> V_122 . V_56 . V_146 = F_121 ;
F_137 ( & V_54 -> V_122 ) ;
V_54 -> V_123 . V_56 . V_57 = & V_156 . V_57 ;
V_54 -> V_123 . V_56 . V_145 = & V_54 -> V_157 [ 0 ] ;
V_54 -> V_123 . V_56 . V_146 = F_122 ;
F_137 ( & V_54 -> V_123 ) ;
V_54 -> V_22 = V_143 ;
V_73 = 0 ;
F_138 ( V_158 ) ;
F_138 ( V_131 ) ;
F_138 ( V_9 ) ;
F_138 ( V_62 ) ;
F_138 ( V_159 ) ;
F_138 ( V_160 ) ;
F_138 ( V_161 ) ;
F_139 ( V_162 ) ;
F_138 ( V_163 ) ;
F_139 ( V_164 ) ;
F_138 ( V_165 ) ;
F_138 ( V_166 ) ;
F_138 ( V_167 ) ;
F_138 ( V_168 ) ;
F_140 ( V_169 , V_80 ) ;
F_140 ( V_79 , V_80 ) ;
F_141 ( V_74 , V_76 ) ;
V_54 -> V_149 [ V_73 ] = NULL ;
V_73 = 0 ;
F_142 ( V_106 ) ;
V_54 -> V_151 [ V_73 ] = NULL ;
V_73 = 0 ;
F_143 ( V_170 ) ;
F_143 ( V_171 ) ;
F_143 ( V_172 ) ;
F_143 ( V_173 ) ;
F_143 ( V_174 ) ;
F_143 ( V_175 ) ;
F_144 ( V_176 ,
V_108 ) ;
F_144 ( V_177 ,
V_110 ) ;
V_54 -> V_153 [ V_73 ] = NULL ;
V_73 = 0 ;
F_145 ( V_178 ) ;
F_145 ( V_179 ) ;
F_145 ( V_180 ) ;
F_145 ( V_181 ) ;
F_145 ( V_182 ) ;
V_54 -> V_155 [ V_73 ] = NULL ;
V_73 = 0 ;
F_146 ( V_183 ) ;
F_146 ( V_184 ) ;
F_146 ( V_185 ) ;
F_146 ( V_186 ) ;
F_146 ( V_187 ) ;
F_146 ( V_188 ) ;
F_146 ( V_189 ) ;
V_54 -> V_157 [ V_73 ] = NULL ;
return & V_54 -> V_59 ;
}
void F_147 ( struct V_141 * V_59 )
{
struct V_53 * V_54 = F_11 ( V_59 ) ;
F_148 ( & V_54 -> V_59 . V_55 ) ;
F_148 ( & V_54 -> V_82 ) ;
F_148 ( & V_54 -> V_87 ) ;
F_148 ( & V_54 -> V_121 ) ;
F_148 ( & V_54 -> V_122 ) ;
F_148 ( & V_54 -> V_123 ) ;
F_53 ( V_54 ) ;
}
static T_5 int F_149 ( void )
{
int error ;
error = F_150 ( & V_58 ) ;
if ( error )
goto V_65;
error = F_150 ( & V_148 ) ;
if ( error )
goto V_190;
error = F_150 ( & V_150 ) ;
if ( error )
goto V_191;
error = F_150 ( & V_152 ) ;
if ( error )
goto V_192;
error = F_150 ( & V_154 ) ;
if ( error )
goto V_193;
error = F_150 ( & V_156 ) ;
if ( error )
goto V_194;
return 0 ;
V_194:
F_151 ( & V_154 ) ;
V_193:
F_151 ( & V_152 ) ;
V_192:
F_151 ( & V_150 ) ;
V_191:
F_151 ( & V_148 ) ;
V_190:
F_151 ( & V_58 ) ;
V_65:
return error ;
}
static void T_6 F_152 ( void )
{
F_151 ( & V_58 ) ;
F_151 ( & V_148 ) ;
F_151 ( & V_150 ) ;
F_151 ( & V_152 ) ;
F_151 ( & V_154 ) ;
F_151 ( & V_156 ) ;
}
