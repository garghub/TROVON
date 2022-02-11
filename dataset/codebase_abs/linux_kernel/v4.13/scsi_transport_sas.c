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
T_1 V_17 ;
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
V_12 -> V_35 = V_36 ;
V_12 -> V_37 = sizeof( struct V_38 ) ;
if ( V_5 ) {
V_12 -> V_39 = F_15 ;
V_27 = & V_5 -> V_27 ;
V_31 = F_25 ( V_27 ) ;
F_22 = NULL ;
} else {
V_12 -> V_39 = F_14 ;
V_27 = & V_14 -> V_40 ;
snprintf ( V_30 , sizeof( V_30 ) ,
L_2 , V_14 -> V_41 ) ;
V_31 = V_30 ;
F_22 = F_17 ;
}
error = F_26 ( V_12 ) ;
if ( error )
goto V_42;
F_27 ( V_12 , V_43 ) ;
error = F_28 ( V_12 , V_27 , V_31 , F_22 ) ;
if ( error )
goto V_42;
if ( V_5 )
V_5 -> V_12 = V_12 ;
else
F_19 ( V_14 ) -> V_12 = V_12 ;
if ( V_5 )
V_12 -> V_25 = V_5 ;
else
V_12 -> V_25 = V_14 ;
F_29 ( V_44 , V_12 ) ;
F_29 ( V_45 , V_12 ) ;
return 0 ;
V_42:
F_20 ( V_12 ) ;
return error ;
}
static void F_30 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_11 * V_12 ;
if ( V_5 )
V_12 = V_5 -> V_12 ;
else
V_12 = F_19 ( V_14 ) -> V_12 ;
if ( ! V_12 )
return;
F_31 ( V_12 ) ;
}
static int F_32 ( struct V_46 * V_47 , struct V_26 * V_27 ,
struct V_26 * V_48 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_33 ( & V_29 -> V_49 ) ;
F_34 ( & V_29 -> V_50 ) ;
V_29 -> V_51 = 0 ;
V_29 -> V_52 = 0 ;
V_29 -> V_53 = 0 ;
if ( F_21 ( V_14 , NULL ) )
F_35 ( V_54 , V_27 , L_3 ,
V_14 -> V_41 ) ;
return 0 ;
}
static int F_36 ( struct V_46 * V_47 , struct V_26 * V_27 ,
struct V_26 * V_48 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
F_30 ( V_14 , NULL ) ;
return 0 ;
}
static int F_37 ( struct V_55 * V_56 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_57 * V_58 ;
if ( ! F_38 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_59 . V_60 . V_61 !=
& V_62 . V_61 )
return 0 ;
V_58 = F_11 ( V_14 -> V_21 ) ;
return & V_58 -> V_63 . V_59 . V_60 == V_56 ;
}
static int F_39 ( struct V_26 * V_27 , void * V_64 )
{
int V_65 = ( int ) ( unsigned long ) V_64 ;
if ( V_65 == 0 && F_40 ( V_27 ) )
F_41 ( F_42 ( V_27 ) ) ;
else if ( V_65 == 1 && F_43 ( V_27 ) )
F_44 ( F_45 ( V_27 ) ) ;
return 0 ;
}
void F_46 ( struct V_26 * V_27 )
{
F_47 ( V_27 , ( void * ) 0 , F_39 ) ;
F_47 ( V_27 , ( void * ) 1 , F_39 ) ;
}
void F_48 ( struct V_13 * V_14 )
{
F_46 ( & V_14 -> V_40 ) ;
F_49 ( V_14 ) ;
}
T_2 F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_5 . V_8 . V_66 ;
}
unsigned int
F_51 ( struct V_2 * V_3 )
{
const int V_67 = 32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
char * V_68 = F_52 ( V_67 , V_33 ) ;
int V_17 = 0 ;
if ( F_53 ( V_3 , 0x90 , V_68 , V_67 ) )
goto V_69;
V_17 = V_68 [ 12 ] & 0x01 ;
V_69:
F_54 ( V_68 ) ;
V_7 -> V_70 = V_17 ;
return V_17 ;
}
void
F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_71 = 0 ;
}
void F_56 ( struct V_2 * V_3 )
{
unsigned int V_70 = 0 ;
V_70 = F_51 ( V_3 ) ;
if ( V_70 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_71 = 1 ;
}
return;
}
unsigned int F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_71 ;
}
static T_3
F_58 ( struct V_26 * V_27 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_75 * V_76 = F_59 ( V_27 ) ;
if ( ! V_76 -> V_8 . V_9 )
return snprintf ( V_74 , 20 , L_4 ) ;
return F_60 ( V_76 -> V_8 . V_9 , V_74 ) ;
}
static T_3 F_61 ( struct V_26 * V_27 ,
T_4 V_77 , int V_78 )
{
struct V_75 * V_76 = F_59 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_76 -> V_27 . V_79 ) ;
struct V_57 * V_58 = F_11 ( V_14 -> V_21 ) ;
int error ;
error = V_58 -> V_22 -> V_80 ( V_76 , V_78 ) ;
if ( error )
return error ;
V_76 -> V_81 = V_78 ;
return V_77 ;
}
static T_3
F_62 ( struct V_26 * V_27 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
if ( V_77 < 1 )
return - V_82 ;
switch ( V_74 [ 0 ] ) {
case '0' :
F_61 ( V_27 , V_77 , 0 ) ;
break;
case '1' :
F_61 ( V_27 , V_77 , 1 ) ;
break;
default:
return - V_82 ;
}
return V_77 ;
}
static T_3
F_63 ( struct V_26 * V_27 , struct V_72 * V_73 ,
char * V_74 )
{
struct V_75 * V_76 = F_59 ( V_27 ) ;
return snprintf ( V_74 , 20 , L_5 , V_76 -> V_81 ) ;
}
static T_3
F_64 ( struct V_26 * V_27 , T_4 V_77 , int V_83 )
{
struct V_75 * V_76 = F_59 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_76 -> V_27 . V_79 ) ;
struct V_57 * V_58 = F_11 ( V_14 -> V_21 ) ;
int error ;
error = V_58 -> V_22 -> V_84 ( V_76 , V_83 ) ;
if ( error )
return error ;
V_76 -> V_81 = 1 ;
return V_77 ;
}
static T_3
F_65 ( struct V_26 * V_27 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
return F_64 ( V_27 , V_77 , 0 ) ;
}
static T_3
F_66 ( struct V_26 * V_27 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
return F_64 ( V_27 , V_77 , 1 ) ;
}
static int F_67 ( struct V_46 * V_47 , struct V_26 * V_27 ,
struct V_26 * V_48 )
{
struct V_75 * V_76 = F_45 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_76 -> V_27 . V_79 ) ;
struct V_57 * V_58 = F_11 ( V_14 -> V_21 ) ;
if ( V_58 -> V_22 -> V_85 )
V_58 -> V_22 -> V_85 ( V_76 ) ;
return 0 ;
}
static int F_68 ( struct V_55 * V_56 , struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_57 * V_58 ;
if ( ! F_43 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_79 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_59 . V_60 . V_61 !=
& V_62 . V_61 )
return 0 ;
V_58 = F_11 ( V_14 -> V_21 ) ;
return & V_58 -> V_86 . V_60 == V_56 ;
}
static void F_69 ( struct V_26 * V_27 )
{
struct V_75 * V_76 = F_45 ( V_27 ) ;
struct V_13 * V_14 = F_18 ( V_76 -> V_27 . V_79 ) ;
struct V_57 * V_58 = F_11 ( V_14 -> V_21 ) ;
if ( V_58 -> V_22 -> V_87 )
V_58 -> V_22 -> V_87 ( V_76 ) ;
F_70 ( V_27 -> V_79 ) ;
F_54 ( V_76 ) ;
}
struct V_75 * F_71 ( struct V_26 * V_79 , int V_88 )
{
struct V_13 * V_14 = F_18 ( V_79 ) ;
struct V_75 * V_76 ;
V_76 = F_52 ( sizeof( * V_76 ) , V_33 ) ;
if ( ! V_76 )
return NULL ;
V_76 -> V_88 = V_88 ;
V_76 -> V_81 = 1 ;
F_72 ( & V_76 -> V_27 ) ;
V_76 -> V_27 . V_79 = F_73 ( V_79 ) ;
V_76 -> V_27 . F_22 = F_69 ;
F_33 ( & V_76 -> V_89 ) ;
if ( F_74 ( V_79 ) ) {
struct V_4 * V_5 = F_75 ( V_79 ) ;
F_76 ( & V_76 -> V_27 , L_6 , V_14 -> V_41 ,
V_5 -> V_90 , V_88 ) ;
} else
F_76 ( & V_76 -> V_27 , L_7 , V_14 -> V_41 , V_88 ) ;
F_77 ( & V_76 -> V_27 ) ;
return V_76 ;
}
int F_78 ( struct V_75 * V_76 )
{
int error ;
error = F_79 ( & V_76 -> V_27 ) ;
if ( ! error ) {
F_80 ( & V_76 -> V_27 ) ;
F_81 ( & V_76 -> V_27 ) ;
}
return error ;
}
void F_82 ( struct V_75 * V_76 )
{
F_83 ( & V_76 -> V_27 ) ;
F_70 ( & V_76 -> V_27 ) ;
}
void
F_44 ( struct V_75 * V_76 )
{
struct V_26 * V_27 = & V_76 -> V_27 ;
F_3 ( ! F_84 ( & V_76 -> V_89 ) ) ;
F_85 ( V_27 ) ;
F_86 ( V_27 ) ;
F_83 ( V_27 ) ;
F_70 ( V_27 ) ;
}
int F_43 ( const struct V_26 * V_27 )
{
return V_27 -> F_22 == F_69 ;
}
static int F_87 ( struct V_55 * V_56 , struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_57 * V_58 ;
if ( ! F_40 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_79 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_59 . V_60 . V_61 !=
& V_62 . V_61 )
return 0 ;
V_58 = F_11 ( V_14 -> V_21 ) ;
return & V_58 -> V_91 . V_60 == V_56 ;
}
static void F_88 ( struct V_26 * V_27 )
{
struct V_92 * V_93 = F_42 ( V_27 ) ;
F_3 ( ! F_84 ( & V_93 -> V_94 ) ) ;
F_70 ( V_27 -> V_79 ) ;
F_54 ( V_93 ) ;
}
static void F_89 ( struct V_92 * V_93 ,
struct V_75 * V_76 )
{
int V_95 ;
V_95 = F_90 ( & V_93 -> V_27 . V_96 , & V_76 -> V_27 . V_96 ,
F_25 ( & V_76 -> V_27 ) ) ;
if ( V_95 )
goto V_97;
V_95 = F_90 ( & V_76 -> V_27 . V_96 , & V_93 -> V_27 . V_96 , L_8 ) ;
if ( V_95 )
goto V_97;
return;
V_97:
F_23 ( V_54 L_9 ,
V_98 , V_95 ) ;
}
static void F_91 ( struct V_92 * V_93 ,
struct V_75 * V_76 )
{
F_92 ( & V_93 -> V_27 . V_96 , F_25 ( & V_76 -> V_27 ) ) ;
F_92 ( & V_76 -> V_27 . V_96 , L_8 ) ;
}
struct V_92 * F_93 ( struct V_26 * V_79 , int V_99 )
{
struct V_13 * V_14 = F_18 ( V_79 ) ;
struct V_92 * V_93 ;
V_93 = F_52 ( sizeof( * V_93 ) , V_33 ) ;
if ( ! V_93 )
return NULL ;
V_93 -> V_100 = V_99 ;
F_72 ( & V_93 -> V_27 ) ;
V_93 -> V_27 . V_79 = F_73 ( V_79 ) ;
V_93 -> V_27 . F_22 = F_88 ;
F_34 ( & V_93 -> V_101 ) ;
F_33 ( & V_93 -> V_94 ) ;
if ( F_74 ( V_79 ) ) {
struct V_4 * V_5 = F_75 ( V_79 ) ;
F_76 ( & V_93 -> V_27 , L_10 , V_14 -> V_41 ,
V_5 -> V_90 , V_93 -> V_100 ) ;
} else
F_76 ( & V_93 -> V_27 , L_11 , V_14 -> V_41 ,
V_93 -> V_100 ) ;
F_77 ( & V_93 -> V_27 ) ;
return V_93 ;
}
struct V_92 * F_94 ( struct V_26 * V_79 )
{
int V_102 ;
struct V_13 * V_14 = F_18 ( V_79 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_95 ( & V_29 -> V_50 ) ;
if ( F_74 ( V_79 ) ) {
struct V_4 * V_5 = F_75 ( V_79 ) ;
struct V_103 * exp = F_96 ( V_5 ) ;
V_102 = exp -> V_53 ++ ;
} else
V_102 = V_29 -> V_53 ++ ;
F_97 ( & V_29 -> V_50 ) ;
return F_93 ( V_79 , V_102 ) ;
}
int F_98 ( struct V_92 * V_93 )
{
int error ;
F_3 ( ! F_84 ( & V_93 -> V_94 ) ) ;
error = F_79 ( & V_93 -> V_27 ) ;
if ( error )
return error ;
F_80 ( & V_93 -> V_27 ) ;
F_81 ( & V_93 -> V_27 ) ;
return 0 ;
}
void F_99 ( struct V_92 * V_93 )
{
F_83 ( & V_93 -> V_27 ) ;
F_70 ( & V_93 -> V_27 ) ;
}
void F_41 ( struct V_92 * V_93 )
{
struct V_26 * V_27 = & V_93 -> V_27 ;
struct V_75 * V_76 , * V_104 ;
if ( V_93 -> V_5 ) {
F_100 ( V_93 -> V_5 ) ;
V_93 -> V_5 = NULL ;
}
F_95 ( & V_93 -> V_101 ) ;
F_101 (phy, tmp_phy, &port->phy_list,
port_siblings) {
F_91 ( V_93 , V_76 ) ;
F_102 ( & V_76 -> V_89 ) ;
}
F_97 ( & V_93 -> V_101 ) ;
if ( V_93 -> V_105 ) {
struct V_26 * V_79 = V_93 -> V_27 . V_79 ;
F_92 ( & V_93 -> V_27 . V_96 , F_25 ( V_79 ) ) ;
V_93 -> V_105 = 0 ;
}
F_85 ( V_27 ) ;
F_86 ( V_27 ) ;
F_83 ( V_27 ) ;
F_70 ( V_27 ) ;
}
int F_40 ( const struct V_26 * V_27 )
{
return V_27 -> F_22 == F_88 ;
}
struct V_75 * F_103 ( struct V_92 * V_93 )
{
struct V_75 * V_76 ;
F_95 ( & V_93 -> V_101 ) ;
if ( F_84 ( & V_93 -> V_94 ) )
V_76 = NULL ;
else {
struct V_106 * V_107 = V_93 -> V_94 . V_108 ;
V_76 = F_104 ( V_107 , F_105 ( * V_76 ) , V_89 ) ;
F_73 ( & V_76 -> V_27 ) ;
}
F_97 ( & V_93 -> V_101 ) ;
return V_76 ;
}
void F_106 ( struct V_92 * V_93 , struct V_75 * V_76 )
{
F_95 ( & V_93 -> V_101 ) ;
if ( F_107 ( ! F_84 ( & V_76 -> V_89 ) ) ) {
struct V_75 * V_109 ;
F_108 (tmp, &port->phy_list, port_siblings)
if ( V_109 == V_76 )
break;
if ( F_107 ( V_109 != V_76 ) ) {
F_35 ( V_54 , & V_93 -> V_27 , L_12 ,
F_25 ( & V_76 -> V_27 ) ) ;
F_109 () ;
}
} else {
F_89 ( V_93 , V_76 ) ;
F_110 ( & V_76 -> V_89 , & V_93 -> V_94 ) ;
V_93 -> V_110 ++ ;
}
F_97 ( & V_93 -> V_101 ) ;
}
void F_111 ( struct V_92 * V_93 , struct V_75 * V_76 )
{
F_95 ( & V_93 -> V_101 ) ;
F_91 ( V_93 , V_76 ) ;
F_102 ( & V_76 -> V_89 ) ;
V_93 -> V_110 -- ;
F_97 ( & V_93 -> V_101 ) ;
}
void F_112 ( struct V_92 * V_93 )
{
int V_95 ;
struct V_26 * V_79 = V_93 -> V_27 . V_79 -> V_79 -> V_79 ;
if ( V_93 -> V_105 )
return;
V_93 -> V_105 = 1 ;
V_95 = F_90 ( & V_93 -> V_27 . V_96 , & V_79 -> V_96 ,
F_25 ( V_79 ) ) ;
if ( V_95 )
goto V_97;
return;
V_97:
F_23 ( V_54 L_13 ,
V_98 , V_95 ) ;
}
static T_3
F_113 ( struct V_26 * V_27 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_4 * V_5 = F_114 ( V_27 ) ;
if ( ! V_5 -> V_8 . V_9 )
return snprintf ( V_74 , 20 , L_4 ) ;
return F_60 (
V_5 -> V_8 . V_9 , V_74 ) ;
}
static T_3
F_115 ( struct V_26 * V_27 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_4 * V_5 = F_114 ( V_27 ) ;
struct V_75 * V_76 = F_45 ( V_5 -> V_27 . V_79 ) ;
struct V_13 * V_14 = F_18 ( V_76 -> V_27 . V_79 ) ;
struct V_57 * V_58 = F_11 ( V_14 -> V_21 ) ;
T_2 V_111 ;
int error ;
error = V_58 -> V_22 -> V_112 ( V_5 , & V_111 ) ;
if ( error )
return error ;
return sprintf ( V_74 , L_14 , ( unsigned long long ) V_111 ) ;
}
static T_3
F_116 ( struct V_26 * V_27 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_4 * V_5 = F_114 ( V_27 ) ;
struct V_75 * V_76 = F_45 ( V_5 -> V_27 . V_79 ) ;
struct V_13 * V_14 = F_18 ( V_76 -> V_27 . V_79 ) ;
struct V_57 * V_58 = F_11 ( V_14 -> V_21 ) ;
int V_113 ;
V_113 = V_58 -> V_22 -> V_114 ( V_5 ) ;
if ( V_113 < 0 )
return V_113 ;
return sprintf ( V_74 , L_15 , V_113 ) ;
}
int F_117 ( struct V_2 * V_3 )
{
char * V_68 = F_52 ( V_115 , V_33 ) , * V_116 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_117 V_118 ;
int V_95 , error ;
if ( ! V_68 )
return - V_34 ;
V_95 = F_118 ( V_3 , 1 , 0x19 , V_68 , V_115 , 30 * V_119 , 3 ,
& V_118 , NULL ) ;
error = - V_82 ;
if ( ! F_119 ( V_95 ) )
goto V_69;
V_116 = V_68 + V_118 . V_120 +
V_118 . V_121 ;
if ( V_116 - V_68 > V_115 - 8 )
goto V_69;
error = 0 ;
V_7 -> V_122 = V_116 [ 2 ] & 0x10 ? 1 : 0 ;
V_7 -> V_123 = ( V_116 [ 4 ] << 8 ) + V_116 [ 5 ] ;
V_7 -> V_124 = ( V_116 [ 6 ] << 8 ) + V_116 [ 7 ] ;
V_69:
F_54 ( V_68 ) ;
return error ;
}
static int F_120 ( struct V_55 * V_56 , struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_57 * V_58 ;
if ( ! F_121 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_79 -> V_79 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_59 . V_60 . V_61 !=
& V_62 . V_61 )
return 0 ;
V_58 = F_11 ( V_14 -> V_21 ) ;
return & V_58 -> V_125 . V_60 == V_56 ;
}
static int F_122 ( struct V_55 * V_56 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_57 * V_58 ;
struct V_4 * V_5 ;
if ( ! F_121 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_79 -> V_79 ) ;
V_5 = F_75 ( V_27 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_59 . V_60 . V_61 !=
& V_62 . V_61 )
return 0 ;
V_58 = F_11 ( V_14 -> V_21 ) ;
return & V_58 -> V_126 . V_60 == V_56 &&
V_5 -> V_8 . V_9 == V_10 ;
}
static int F_123 ( struct V_55 * V_56 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_57 * V_58 ;
struct V_4 * V_5 ;
if ( ! F_121 ( V_27 ) )
return 0 ;
V_14 = F_18 ( V_27 -> V_79 -> V_79 ) ;
V_5 = F_75 ( V_27 ) ;
if ( ! V_14 -> V_21 )
return 0 ;
if ( V_14 -> V_21 -> V_59 . V_60 . V_61 !=
& V_62 . V_61 )
return 0 ;
V_58 = F_11 ( V_14 -> V_21 ) ;
return & V_58 -> V_127 . V_60 == V_56 &&
( V_5 -> V_8 . V_9 == V_128 ||
V_5 -> V_8 . V_9 == V_129 ) ;
}
static void F_124 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_75 ( V_27 ) ;
struct V_103 * V_130 = F_96 ( V_5 ) ;
if ( V_5 -> V_12 )
F_20 ( V_5 -> V_12 ) ;
F_70 ( V_27 -> V_79 ) ;
F_54 ( V_130 ) ;
}
static void F_125 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_75 ( V_27 ) ;
struct V_1 * V_130 = F_4 ( V_5 ) ;
if ( V_5 -> V_12 )
F_20 ( V_5 -> V_12 ) ;
F_70 ( V_27 -> V_79 ) ;
F_54 ( V_130 ) ;
}
static void F_126 ( struct V_4 * V_5 )
{
F_33 ( & V_5 -> V_131 ) ;
}
struct V_4 * F_127 ( struct V_92 * V_79 )
{
struct V_13 * V_14 = F_18 ( & V_79 -> V_27 ) ;
struct V_1 * V_7 ;
V_7 = F_52 ( sizeof( * V_7 ) , V_33 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_72 ( & V_7 -> V_5 . V_27 ) ;
V_7 -> V_5 . V_27 . V_79 = F_73 ( & V_79 -> V_27 ) ;
V_7 -> V_5 . V_27 . F_22 = F_125 ;
if ( F_74 ( V_79 -> V_27 . V_79 ) ) {
struct V_4 * V_5 = F_75 ( V_79 -> V_27 . V_79 ) ;
F_76 ( & V_7 -> V_5 . V_27 , L_16 ,
V_14 -> V_41 , V_5 -> V_90 ,
V_79 -> V_100 ) ;
} else
F_76 ( & V_7 -> V_5 . V_27 , L_17 ,
V_14 -> V_41 , V_79 -> V_100 ) ;
V_7 -> V_5 . V_8 . V_9 = V_10 ;
F_126 ( & V_7 -> V_5 ) ;
F_77 ( & V_7 -> V_5 . V_27 ) ;
return & V_7 -> V_5 ;
}
struct V_4 * F_128 ( struct V_92 * V_79 ,
enum V_132 type )
{
struct V_13 * V_14 = F_18 ( & V_79 -> V_27 ) ;
struct V_103 * V_7 ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_3 ( type != V_128 &&
type != V_129 ) ;
V_7 = F_52 ( sizeof( * V_7 ) , V_33 ) ;
if ( ! V_7 ) {
return NULL ;
}
F_72 ( & V_7 -> V_5 . V_27 ) ;
V_7 -> V_5 . V_27 . V_79 = F_73 ( & V_79 -> V_27 ) ;
V_7 -> V_5 . V_27 . F_22 = F_124 ;
F_95 ( & V_29 -> V_50 ) ;
V_7 -> V_5 . V_90 = V_29 -> V_52 ++ ;
F_97 ( & V_29 -> V_50 ) ;
F_76 ( & V_7 -> V_5 . V_27 , L_18 ,
V_14 -> V_41 , V_7 -> V_5 . V_90 ) ;
V_7 -> V_5 . V_8 . V_9 = type ;
F_126 ( & V_7 -> V_5 ) ;
F_77 ( & V_7 -> V_5 . V_27 ) ;
return & V_7 -> V_5 ;
}
int F_129 ( struct V_4 * V_5 )
{
struct V_92 * V_79 = F_42 ( V_5 -> V_27 . V_79 ) ;
struct V_13 * V_14 = F_18 ( V_79 -> V_27 . V_79 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
struct V_133 * V_8 = & V_5 -> V_8 ;
int error ;
if ( V_79 -> V_5 )
return - V_134 ;
V_79 -> V_5 = V_5 ;
error = F_79 ( & V_5 -> V_27 ) ;
if ( error )
return error ;
F_80 ( & V_5 -> V_27 ) ;
F_81 ( & V_5 -> V_27 ) ;
if ( F_21 ( V_14 , V_5 ) )
F_23 ( L_19 , F_25 ( & V_5 -> V_27 ) ) ;
F_95 ( & V_29 -> V_50 ) ;
F_110 ( & V_5 -> V_131 , & V_29 -> V_49 ) ;
if ( V_8 -> V_9 == V_10 &&
( V_8 -> V_135 &
( V_136 | V_137 | V_138 ) ) )
V_5 -> V_90 = V_29 -> V_51 ++ ;
else if ( V_8 -> V_9 == V_10 )
V_5 -> V_90 = - 1 ;
F_97 ( & V_29 -> V_50 ) ;
if ( V_8 -> V_9 == V_10 &&
V_5 -> V_90 != - 1 ) {
int V_139 ;
if ( V_8 -> V_135 & V_136 )
V_139 = V_140 ;
else
V_139 = 0 ;
F_130 ( & V_5 -> V_27 , 0 , V_5 -> V_90 , V_139 ,
V_141 ) ;
}
return 0 ;
}
void F_131 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
struct V_13 * V_14 = F_18 ( V_5 -> V_27 . V_79 -> V_79 ) ;
struct V_28 * V_29 = F_19 ( V_14 ) ;
F_95 ( & V_29 -> V_50 ) ;
F_132 ( & V_5 -> V_131 ) ;
F_97 ( & V_29 -> V_50 ) ;
F_83 ( V_27 ) ;
F_70 ( V_27 ) ;
}
void
F_100 ( struct V_4 * V_5 )
{
F_133 ( V_5 ) ;
F_131 ( V_5 ) ;
}
void F_134 ( struct V_4 * V_5 )
{
struct V_92 * V_79 = F_42 ( V_5 -> V_27 . V_79 ) ;
V_79 -> V_5 = NULL ;
}
void
F_133 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
switch ( V_5 -> V_8 . V_9 ) {
case V_10 :
F_135 ( V_27 ) ;
break;
case V_128 :
case V_129 :
F_46 ( V_27 ) ;
break;
default:
break;
}
F_134 ( V_5 ) ;
F_30 ( NULL , V_5 ) ;
F_85 ( V_27 ) ;
F_86 ( V_27 ) ;
}
int F_121 ( const struct V_26 * V_27 )
{
return V_27 -> F_22 == F_125 ||
V_27 -> F_22 == F_124 ;
}
static int F_136 ( struct V_13 * V_14 , T_5 V_142 ,
T_5 V_143 , T_2 V_139 )
{
struct V_28 * V_29 = F_19 ( V_14 ) ;
struct V_4 * V_5 ;
F_95 ( & V_29 -> V_50 ) ;
F_108 (rphy, &sas_host->rphy_list, list) {
if ( V_5 -> V_8 . V_9 != V_10 ||
V_5 -> V_90 == - 1 )
continue;
if ( ( V_142 == V_140 || V_142 == 0 ) &&
( V_143 == V_140 || V_143 == V_5 -> V_90 ) ) {
F_130 ( & V_5 -> V_27 , 0 , V_5 -> V_90 ,
V_139 , V_144 ) ;
}
}
F_97 ( & V_29 -> V_50 ) ;
return 0 ;
}
struct V_145 *
F_137 ( struct V_146 * V_147 )
{
struct V_57 * V_58 ;
int V_77 ;
V_58 = F_52 ( sizeof( struct V_57 ) , V_33 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_63 . V_148 = F_136 ;
V_58 -> V_63 . V_59 . V_60 . V_149 = & V_58 -> V_59 [ 0 ] ;
V_58 -> V_63 . V_59 . V_60 . V_61 = & V_62 . V_61 ;
V_58 -> V_63 . V_59 . V_60 . V_150 = F_37 ;
F_138 ( & V_58 -> V_63 . V_59 ) ;
V_58 -> V_63 . V_151 = sizeof( struct V_28 ) ;
V_58 -> V_86 . V_60 . V_61 = & V_152 . V_61 ;
V_58 -> V_86 . V_60 . V_149 = & V_58 -> V_153 [ 0 ] ;
V_58 -> V_86 . V_60 . V_150 = F_68 ;
F_138 ( & V_58 -> V_86 ) ;
V_58 -> V_91 . V_60 . V_61 = & V_154 . V_61 ;
V_58 -> V_91 . V_60 . V_149 = & V_58 -> V_155 [ 0 ] ;
V_58 -> V_91 . V_60 . V_150 = F_87 ;
F_138 ( & V_58 -> V_91 ) ;
V_58 -> V_125 . V_60 . V_61 = & V_156 . V_61 ;
V_58 -> V_125 . V_60 . V_149 = & V_58 -> V_157 [ 0 ] ;
V_58 -> V_125 . V_60 . V_150 = F_120 ;
F_138 ( & V_58 -> V_125 ) ;
V_58 -> V_126 . V_60 . V_61 = & V_158 . V_61 ;
V_58 -> V_126 . V_60 . V_149 = & V_58 -> V_159 [ 0 ] ;
V_58 -> V_126 . V_60 . V_150 = F_122 ;
F_138 ( & V_58 -> V_126 ) ;
V_58 -> V_127 . V_60 . V_61 = & V_160 . V_61 ;
V_58 -> V_127 . V_60 . V_149 = & V_58 -> V_161 [ 0 ] ;
V_58 -> V_127 . V_60 . V_150 = F_123 ;
F_138 ( & V_58 -> V_127 ) ;
V_58 -> V_22 = V_147 ;
V_77 = 0 ;
F_139 ( V_162 ) ;
F_139 ( V_135 ) ;
F_139 ( V_9 ) ;
F_139 ( V_66 ) ;
F_139 ( V_163 ) ;
F_139 ( V_164 ) ;
F_139 ( V_165 ) ;
F_140 ( V_166 ) ;
F_139 ( V_167 ) ;
F_140 ( V_168 ) ;
F_139 ( V_169 ) ;
F_139 ( V_170 ) ;
F_139 ( V_171 ) ;
F_139 ( V_172 ) ;
F_141 ( V_173 , V_84 ) ;
F_141 ( V_83 , V_84 ) ;
F_142 ( V_78 , V_80 ) ;
V_58 -> V_153 [ V_77 ] = NULL ;
V_77 = 0 ;
F_143 ( V_110 ) ;
V_58 -> V_155 [ V_77 ] = NULL ;
V_77 = 0 ;
F_144 ( V_174 ) ;
F_144 ( V_175 ) ;
F_144 ( V_176 ) ;
F_144 ( V_177 ) ;
F_144 ( V_178 ) ;
F_144 ( V_179 ) ;
F_145 ( V_180 ,
V_112 ) ;
F_145 ( V_181 ,
V_114 ) ;
V_58 -> V_157 [ V_77 ] = NULL ;
V_77 = 0 ;
F_146 ( V_182 ) ;
F_146 ( V_183 ) ;
F_146 ( V_184 ) ;
F_146 ( V_185 ) ;
F_146 ( V_186 ) ;
V_58 -> V_159 [ V_77 ] = NULL ;
V_77 = 0 ;
F_147 ( V_187 ) ;
F_147 ( V_188 ) ;
F_147 ( V_189 ) ;
F_147 ( V_190 ) ;
F_147 ( V_191 ) ;
F_147 ( V_192 ) ;
F_147 ( V_193 ) ;
V_58 -> V_161 [ V_77 ] = NULL ;
return & V_58 -> V_63 ;
}
void F_148 ( struct V_145 * V_63 )
{
struct V_57 * V_58 = F_11 ( V_63 ) ;
F_149 ( & V_58 -> V_63 . V_59 ) ;
F_149 ( & V_58 -> V_86 ) ;
F_149 ( & V_58 -> V_91 ) ;
F_149 ( & V_58 -> V_125 ) ;
F_149 ( & V_58 -> V_126 ) ;
F_149 ( & V_58 -> V_127 ) ;
F_54 ( V_58 ) ;
}
static T_6 int F_150 ( void )
{
int error ;
error = F_151 ( & V_62 ) ;
if ( error )
goto V_69;
error = F_151 ( & V_152 ) ;
if ( error )
goto V_194;
error = F_151 ( & V_154 ) ;
if ( error )
goto V_195;
error = F_151 ( & V_156 ) ;
if ( error )
goto V_196;
error = F_151 ( & V_158 ) ;
if ( error )
goto V_197;
error = F_151 ( & V_160 ) ;
if ( error )
goto V_198;
return 0 ;
V_198:
F_152 ( & V_158 ) ;
V_197:
F_152 ( & V_156 ) ;
V_196:
F_152 ( & V_154 ) ;
V_195:
F_152 ( & V_152 ) ;
V_194:
F_152 ( & V_62 ) ;
V_69:
return error ;
}
static void T_7 F_153 ( void )
{
F_152 ( & V_62 ) ;
F_152 ( & V_152 ) ;
F_152 ( & V_154 ) ;
F_152 ( & V_156 ) ;
F_152 ( & V_158 ) ;
F_152 ( & V_160 ) ;
}
