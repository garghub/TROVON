static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) F_5 ( V_4 -> V_8 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
F_3 ( V_10 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) V_10 -> V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_12 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
T_2 * V_13 = ( T_2 * ) V_12 ;
return * V_13 == V_10 -> V_11 ;
}
struct V_9 *
F_10 ( int V_14 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_11 ;
int V_15 ;
for ( V_11 = 1 ; V_11 < V_16 ; V_11 ++ ) {
V_2 = F_11 ( & V_17 , NULL , & V_11 ,
F_9 ) ;
if ( ! V_2 )
break;
}
if ( V_11 == V_16 ) {
F_12 ( V_18 L_2 ,
V_16 - 1 ) ;
return NULL ;
}
V_10 = F_13 ( sizeof( * V_10 ) + V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 . V_20 = & V_17 ;
F_14 ( & V_10 -> V_2 , L_3 , ( unsigned long long ) V_11 ) ;
V_15 = F_15 ( & V_10 -> V_2 ) ;
if ( V_15 )
goto V_21;
V_15 = F_16 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
if ( V_15 )
goto V_24;
if ( V_14 )
V_10 -> V_25 = & V_10 [ 1 ] ;
return V_10 ;
V_24:
F_17 ( & V_10 -> V_2 ) ;
return NULL ;
V_21:
F_3 ( V_10 ) ;
return NULL ;
}
void F_18 ( struct V_9 * V_10 )
{
F_19 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
F_17 ( & V_10 -> V_2 ) ;
}
struct V_9 * F_20 ( T_3 V_26 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_11 ( & V_17 , NULL , & V_26 ,
F_9 ) ;
if ( ! V_2 )
return NULL ;
V_10 = F_7 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_10 ;
}
static int F_22 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_1 * V_29 )
{
struct V_30 * V_31 = F_23 ( V_2 ) ;
struct V_32 * V_33 = V_31 -> V_34 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
F_24 ( & V_33 -> V_35 , 0 ) ;
F_25 ( & V_33 -> V_36 ) ;
return 0 ;
}
static T_4 F_26 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_27 ( V_38 -> V_2 . V_41 ) ;
return V_40 -> V_42 ;
}
static struct V_39 * F_28 ( T_4 V_42 )
{
unsigned long V_43 ;
struct V_39 * V_40 ;
F_29 ( & V_44 , V_43 ) ;
F_30 (sess, &sesslist, sess_list) {
if ( V_40 -> V_42 == V_42 ) {
F_31 ( & V_44 , V_43 ) ;
return V_40 ;
}
}
F_31 ( & V_44 , V_43 ) ;
return NULL ;
}
static struct V_37 * F_32 ( T_4 V_42 , T_4 V_45 )
{
unsigned long V_43 ;
struct V_37 * V_38 ;
F_29 ( & V_46 , V_43 ) ;
F_30 (conn, &connlist, conn_list) {
if ( ( V_38 -> V_45 == V_45 ) && ( F_26 ( V_38 ) == V_42 ) ) {
F_31 ( & V_46 , V_43 ) ;
return V_38 ;
}
}
F_31 ( & V_46 , V_43 ) ;
return NULL ;
}
static const char * F_33 ( int V_47 )
{
int V_48 ;
char * V_49 = NULL ;
for ( V_48 = 0 ; V_48 < F_34 ( V_50 ) ; V_48 ++ ) {
if ( V_50 [ V_48 ] . V_51 == V_47 ) {
V_49 = V_50 [ V_48 ] . V_49 ;
break;
}
}
return V_49 ;
}
int F_35 ( struct V_39 * V_52 )
{
unsigned long V_43 ;
int V_15 ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
switch ( V_52 -> V_47 ) {
case V_54 :
V_15 = 0 ;
break;
case V_55 :
V_15 = V_56 << 16 ;
break;
case V_57 :
V_15 = V_58 << 16 ;
break;
default:
V_15 = V_59 << 16 ;
break;
}
F_31 ( & V_52 -> V_53 , V_43 ) ;
return V_15 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_39 * V_52 = F_27 ( V_2 ) ;
struct V_30 * V_31 ;
V_31 = F_37 ( V_52 ) ;
F_38 ( V_31 ) ;
F_39 ( V_52 , L_4 ) ;
F_3 ( V_52 ) ;
}
static int F_40 ( const struct V_1 * V_2 )
{
return V_2 -> V_60 == F_36 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_12 )
{
void (* F_42) ( struct V_39 * ) = V_12 ;
if ( ! F_40 ( V_2 ) )
return 0 ;
F_42 ( F_27 ( V_2 ) ) ;
return 0 ;
}
void F_43 ( struct V_30 * V_31 ,
void (* F_42)( struct V_39 * ) )
{
F_44 ( & V_31 -> V_61 , F_42 ,
F_41 ) ;
}
int F_45 ( struct V_30 * V_31 , unsigned long time )
{
struct V_32 * V_33 = V_31 -> V_34 ;
return ! F_46 ( & V_33 -> V_35 ) ;
}
static int F_47 ( struct V_1 * V_2 , void * V_12 )
{
struct V_62 * V_63 = V_12 ;
struct V_39 * V_52 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
unsigned long V_43 ;
unsigned int V_11 ;
if ( ! F_40 ( V_2 ) )
return 0 ;
V_52 = F_27 ( V_2 ) ;
F_39 ( V_52 , L_5 ) ;
V_31 = F_37 ( V_52 ) ;
V_33 = V_31 -> V_34 ;
F_48 ( & V_33 -> V_36 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
if ( V_52 -> V_47 != V_54 ) {
F_31 ( & V_52 -> V_53 , V_43 ) ;
goto V_64;
}
V_11 = V_52 -> V_65 ;
F_31 ( & V_52 -> V_53 , V_43 ) ;
if ( V_11 != V_66 ) {
if ( ( V_63 -> V_67 == V_68 ||
V_63 -> V_67 == 0 ) &&
( V_63 -> V_11 == V_68 ||
V_63 -> V_11 == V_11 ) )
F_49 ( & V_52 -> V_2 , 0 , V_11 ,
V_63 -> V_69 , 1 ) ;
}
V_64:
F_50 ( & V_33 -> V_36 ) ;
F_39 ( V_52 , L_6 ) ;
return 0 ;
}
static int F_51 ( struct V_30 * V_31 , T_5 V_67 ,
T_5 V_11 , T_5 V_69 )
{
struct V_62 V_63 ;
V_63 . V_67 = V_67 ;
V_63 . V_11 = V_11 ;
V_63 . V_69 = V_69 ;
return F_44 ( & V_31 -> V_61 , & V_63 ,
F_47 ) ;
}
static void F_52 ( struct V_70 * V_71 )
{
struct V_39 * V_52 =
F_53 ( V_71 , struct V_39 , V_72 ) ;
struct V_30 * V_31 = F_37 ( V_52 ) ;
struct V_32 * V_33 = V_31 -> V_34 ;
struct V_62 V_63 ;
V_63 . V_67 = 0 ;
V_63 . V_11 = V_68 ;
V_63 . V_69 = V_68 ;
F_47 ( & V_52 -> V_2 , & V_63 ) ;
F_54 ( & V_33 -> V_35 ) ;
}
int F_55 ( struct V_73 * V_74 )
{
struct V_39 * V_52 =
F_56 ( F_57 ( V_74 -> V_1 ) ) ;
unsigned long V_43 ;
int V_75 = 0 ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
while ( V_52 -> V_47 != V_54 ) {
if ( V_52 -> V_47 == V_57 ) {
V_75 = V_76 ;
break;
}
F_31 ( & V_52 -> V_53 , V_43 ) ;
F_58 ( 1000 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
}
F_31 ( & V_52 -> V_53 , V_43 ) ;
return V_75 ;
}
static void F_59 ( struct V_70 * V_71 )
{
struct V_39 * V_52 =
F_53 ( V_71 , struct V_39 ,
V_77 . V_71 ) ;
unsigned long V_43 ;
F_60 ( V_78 , V_52 ,
L_7 ,
V_52 -> V_79 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
switch ( V_52 -> V_47 ) {
case V_55 :
V_52 -> V_47 = V_57 ;
break;
case V_54 :
case V_57 :
F_31 ( & V_52 -> V_53 , V_43 ) ;
return;
}
F_31 ( & V_52 -> V_53 , V_43 ) ;
if ( V_52 -> V_80 -> F_59 )
V_52 -> V_80 -> F_59 ( V_52 ) ;
F_39 ( V_52 , L_8 ) ;
F_61 ( & V_52 -> V_2 ) ;
F_39 ( V_52 , L_9 ) ;
}
static void F_62 ( struct V_70 * V_71 )
{
struct V_39 * V_52 =
F_53 ( V_71 , struct V_39 ,
V_81 ) ;
struct V_30 * V_31 = F_37 ( V_52 ) ;
struct V_32 * V_33 = V_31 -> V_34 ;
unsigned long V_43 ;
F_39 ( V_52 , L_10 ) ;
F_63 ( & V_52 -> V_77 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
V_52 -> V_47 = V_54 ;
F_31 ( & V_52 -> V_53 , V_43 ) ;
F_61 ( & V_52 -> V_2 ) ;
if ( V_31 -> V_82 -> V_83 ) {
if ( F_64 ( V_31 , & V_52 -> V_72 ) )
F_65 ( & V_33 -> V_35 ) ;
}
F_39 ( V_52 , L_11 ) ;
}
void F_66 ( struct V_39 * V_52 )
{
F_67 ( V_84 , & V_52 -> V_81 ) ;
F_68 ( V_84 ) ;
}
static void F_69 ( struct V_70 * V_71 )
{
struct V_39 * V_52 =
F_53 ( V_71 , struct V_39 ,
V_85 ) ;
unsigned long V_43 ;
F_39 ( V_52 , L_12 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
V_52 -> V_47 = V_55 ;
F_31 ( & V_52 -> V_53 , V_43 ) ;
F_70 ( & V_52 -> V_2 ) ;
F_39 ( V_52 , L_13 ) ;
if ( V_52 -> V_79 >= 0 )
F_71 ( V_84 ,
& V_52 -> V_77 ,
V_52 -> V_79 * V_86 ) ;
}
void F_72 ( struct V_39 * V_52 )
{
F_67 ( V_84 , & V_52 -> V_85 ) ;
}
static void F_73 ( struct V_70 * V_71 )
{
struct V_39 * V_52 =
F_53 ( V_71 , struct V_39 ,
V_87 ) ;
struct V_30 * V_31 = F_37 ( V_52 ) ;
struct V_32 * V_33 = V_31 -> V_34 ;
unsigned long V_43 ;
F_39 ( V_52 , L_14 ) ;
F_48 ( & V_33 -> V_36 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
if ( V_52 -> V_65 == V_66 ) {
F_31 ( & V_52 -> V_53 , V_43 ) ;
F_50 ( & V_33 -> V_36 ) ;
return;
}
V_52 -> V_65 = V_66 ;
F_31 ( & V_52 -> V_53 , V_43 ) ;
F_50 ( & V_33 -> V_36 ) ;
F_74 ( & V_52 -> V_2 ) ;
F_75 ( V_52 , V_88 ) ;
F_39 ( V_52 , L_15 ) ;
}
struct V_39 *
F_76 ( struct V_30 * V_31 , struct V_8 * V_80 ,
int V_14 )
{
struct V_39 * V_52 ;
V_52 = F_13 ( sizeof( * V_52 ) + V_14 ,
V_19 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_80 = V_80 ;
V_52 -> V_79 = 120 ;
V_52 -> V_47 = V_57 ;
F_77 ( & V_52 -> V_77 , F_59 ) ;
F_78 ( & V_52 -> V_89 ) ;
F_79 ( & V_52 -> V_81 , F_62 ) ;
F_79 ( & V_52 -> V_85 , F_69 ) ;
F_79 ( & V_52 -> V_87 , F_73 ) ;
F_79 ( & V_52 -> V_72 , F_52 ) ;
F_80 ( & V_52 -> V_53 ) ;
F_81 ( V_31 ) ;
V_52 -> V_2 . V_41 = & V_31 -> V_61 ;
V_52 -> V_2 . V_60 = F_36 ;
F_82 ( & V_52 -> V_2 ) ;
if ( V_14 )
V_52 -> V_25 = & V_52 [ 1 ] ;
F_39 ( V_52 , L_16 ) ;
return V_52 ;
}
static int F_83 ( struct V_1 * V_2 , void * V_12 )
{
struct V_39 * V_52 ;
unsigned long V_43 ;
int V_15 = 0 ;
if ( ! F_40 ( V_2 ) )
return 0 ;
V_52 = F_27 ( V_2 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
if ( * ( ( unsigned int * ) V_12 ) == V_52 -> V_65 )
V_15 = - V_90 ;
F_31 ( & V_52 -> V_53 , V_43 ) ;
return V_15 ;
}
int F_84 ( struct V_39 * V_52 , unsigned int V_65 )
{
struct V_30 * V_31 = F_37 ( V_52 ) ;
struct V_32 * V_33 ;
unsigned long V_43 ;
unsigned int V_11 = V_65 ;
int V_15 ;
V_33 = V_31 -> V_34 ;
V_52 -> V_42 = F_85 ( 1 , & V_91 ) ;
if ( V_11 == V_66 ) {
for ( V_11 = 0 ; V_11 < V_66 ; V_11 ++ ) {
V_15 = F_44 ( & V_31 -> V_61 , & V_11 ,
F_83 ) ;
if ( ! V_15 )
break;
}
if ( V_11 == V_66 ) {
F_60 ( V_18 , V_52 ,
L_17
L_18 ,
V_66 - 1 ) ;
V_15 = - V_92 ;
goto V_93;
}
}
V_52 -> V_65 = V_11 ;
F_14 ( & V_52 -> V_2 , L_19 , V_52 -> V_42 ) ;
V_15 = F_86 ( & V_52 -> V_2 ) ;
if ( V_15 ) {
F_60 ( V_18 , V_52 ,
L_20 ) ;
goto V_93;
}
F_87 ( & V_52 -> V_2 ) ;
F_29 ( & V_44 , V_43 ) ;
F_88 ( & V_52 -> V_89 , & V_94 ) ;
F_31 ( & V_44 , V_43 ) ;
F_75 ( V_52 , V_95 ) ;
F_39 ( V_52 , L_21 ) ;
return 0 ;
V_93:
F_38 ( V_31 ) ;
return V_15 ;
}
struct V_39 *
F_89 ( struct V_30 * V_31 , struct V_8 * V_80 ,
int V_14 , unsigned int V_65 )
{
struct V_39 * V_52 ;
V_52 = F_76 ( V_31 , V_80 , V_14 ) ;
if ( ! V_52 )
return NULL ;
if ( F_84 ( V_52 , V_65 ) ) {
F_90 ( V_52 ) ;
return NULL ;
}
return V_52 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_92 ( V_2 ) ;
struct V_1 * V_41 = V_38 -> V_2 . V_41 ;
F_93 ( V_38 , L_22 ) ;
F_3 ( V_38 ) ;
F_21 ( V_41 ) ;
}
static int F_94 ( const struct V_1 * V_2 )
{
return V_2 -> V_60 == F_91 ;
}
static int F_95 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_94 ( V_2 ) )
return 0 ;
return F_96 ( F_92 ( V_2 ) ) ;
}
void F_97 ( struct V_39 * V_52 )
{
struct V_30 * V_31 = F_37 ( V_52 ) ;
unsigned long V_43 ;
int V_15 ;
F_39 ( V_52 , L_23 ) ;
F_29 ( & V_44 , V_43 ) ;
F_98 ( & V_52 -> V_89 ) ;
F_31 ( & V_44 , V_43 ) ;
F_68 ( V_84 ) ;
if ( ! F_63 ( & V_52 -> V_77 ) )
F_68 ( V_84 ) ;
F_29 ( & V_52 -> V_53 , V_43 ) ;
V_52 -> V_47 = V_57 ;
F_31 ( & V_52 -> V_53 , V_43 ) ;
F_61 ( & V_52 -> V_2 ) ;
F_99 ( V_31 ) ;
F_73 ( & V_52 -> V_87 ) ;
V_15 = F_44 ( & V_52 -> V_2 , NULL ,
F_95 ) ;
if ( V_15 )
F_60 ( V_18 , V_52 ,
L_24
L_25 , V_15 ) ;
F_100 ( & V_52 -> V_2 ) ;
F_39 ( V_52 , L_26 ) ;
F_101 ( & V_52 -> V_2 ) ;
}
void F_90 ( struct V_39 * V_52 )
{
F_39 ( V_52 , L_27 ) ;
F_75 ( V_52 , V_96 ) ;
F_21 ( & V_52 -> V_2 ) ;
}
int F_102 ( struct V_39 * V_52 )
{
F_97 ( V_52 ) ;
F_39 ( V_52 , L_28 ) ;
F_90 ( V_52 ) ;
return 0 ;
}
struct V_37 *
F_103 ( struct V_39 * V_52 , int V_14 , T_4 V_45 )
{
struct V_8 * V_80 = V_52 -> V_80 ;
struct V_37 * V_38 ;
unsigned long V_43 ;
int V_15 ;
V_38 = F_13 ( sizeof( * V_38 ) + V_14 , V_19 ) ;
if ( ! V_38 )
return NULL ;
if ( V_14 )
V_38 -> V_25 = & V_38 [ 1 ] ;
F_25 ( & V_38 -> V_97 ) ;
F_78 ( & V_38 -> V_98 ) ;
V_38 -> V_80 = V_80 ;
V_38 -> V_45 = V_45 ;
if ( ! F_104 ( & V_52 -> V_2 ) )
goto V_99;
F_14 ( & V_38 -> V_2 , L_29 , V_52 -> V_42 , V_45 ) ;
V_38 -> V_2 . V_41 = & V_52 -> V_2 ;
V_38 -> V_2 . V_60 = F_91 ;
V_15 = F_15 ( & V_38 -> V_2 ) ;
if ( V_15 ) {
F_60 ( V_18 , V_52 , L_30
L_31 ) ;
goto V_100;
}
F_87 ( & V_38 -> V_2 ) ;
F_29 ( & V_46 , V_43 ) ;
F_88 ( & V_38 -> V_98 , & V_101 ) ;
F_31 ( & V_46 , V_43 ) ;
F_93 ( V_38 , L_32 ) ;
return V_38 ;
V_100:
F_21 ( & V_52 -> V_2 ) ;
V_99:
F_3 ( V_38 ) ;
return NULL ;
}
int F_96 ( struct V_37 * V_38 )
{
unsigned long V_43 ;
F_29 ( & V_46 , V_43 ) ;
F_98 ( & V_38 -> V_98 ) ;
F_31 ( & V_46 , V_43 ) ;
F_100 ( & V_38 -> V_2 ) ;
F_93 ( V_38 , L_33 ) ;
F_17 ( & V_38 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_105 ( struct V_8 * V_102 )
{
struct V_3 * V_4 ;
unsigned long V_43 ;
F_29 ( & V_103 , V_43 ) ;
F_30 (priv, &iscsi_transports, list) {
if ( V_102 == V_4 -> V_8 ) {
F_31 ( & V_103 , V_43 ) ;
return V_4 ;
}
}
F_31 ( & V_103 , V_43 ) ;
return NULL ;
}
static int
F_106 ( struct V_104 * V_105 , T_4 V_106 , T_6 V_107 )
{
return F_107 ( V_108 , V_105 , 0 , V_106 , V_107 ) ;
}
int F_108 ( struct V_37 * V_38 , struct V_109 * V_110 ,
char * V_12 , T_4 V_111 )
{
struct V_112 * V_113 ;
struct V_104 * V_105 ;
struct V_114 * V_115 ;
char * V_116 ;
struct V_3 * V_4 ;
int V_117 = F_109 ( sizeof( * V_115 ) + sizeof( struct V_109 ) +
V_111 ) ;
V_4 = F_105 ( V_38 -> V_80 ) ;
if ( ! V_4 )
return - V_118 ;
V_105 = F_110 ( V_117 , V_119 ) ;
if ( ! V_105 ) {
F_111 ( V_38 , V_120 ) ;
F_112 ( V_18 , V_38 , L_34
L_35 ) ;
return - V_121 ;
}
V_113 = F_113 ( V_105 , 0 , 0 , 0 , ( V_117 - sizeof( * V_113 ) ) , 0 ) ;
V_115 = F_114 ( V_113 ) ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_122 = F_5 ( V_38 -> V_80 ) ;
V_115 -> type = V_123 ;
V_115 -> V_124 . V_125 . V_45 = V_38 -> V_45 ;
V_115 -> V_124 . V_125 . V_42 = F_26 ( V_38 ) ;
V_116 = ( char * ) V_115 + sizeof( * V_115 ) ;
memcpy ( V_116 , V_110 , sizeof( struct V_109 ) ) ;
memcpy ( V_116 + sizeof( struct V_109 ) , V_12 , V_111 ) ;
return F_106 ( V_105 , V_126 , V_119 ) ;
}
int F_115 ( struct V_30 * V_31 ,
struct V_8 * V_80 , T_4 type ,
char * V_12 , T_7 V_111 )
{
struct V_112 * V_113 ;
struct V_104 * V_105 ;
struct V_114 * V_115 ;
int V_117 = F_109 ( sizeof( * V_115 ) + V_111 ) ;
V_105 = F_110 ( V_117 , V_119 ) ;
if ( ! V_105 ) {
F_12 ( V_18 L_36 ) ;
return - V_121 ;
}
V_113 = F_113 ( V_105 , 0 , 0 , 0 , ( V_117 - sizeof( * V_113 ) ) , 0 ) ;
V_115 = F_114 ( V_113 ) ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> type = type ;
V_115 -> V_122 = F_5 ( V_80 ) ;
switch ( type ) {
case V_127 :
V_115 -> V_124 . V_128 . V_129 = V_31 -> V_129 ;
break;
case V_130 :
V_115 -> V_124 . V_131 . V_129 = V_31 -> V_129 ;
break;
}
memcpy ( ( char * ) V_115 + sizeof( * V_115 ) , V_12 , V_111 ) ;
return F_106 ( V_105 , V_132 , V_119 ) ;
}
void F_111 ( struct V_37 * V_38 , enum V_133 error )
{
struct V_112 * V_113 ;
struct V_104 * V_105 ;
struct V_114 * V_115 ;
struct V_3 * V_4 ;
int V_117 = F_109 ( sizeof( * V_115 ) ) ;
V_4 = F_105 ( V_38 -> V_80 ) ;
if ( ! V_4 )
return;
V_105 = F_110 ( V_117 , V_119 ) ;
if ( ! V_105 ) {
F_112 ( V_18 , V_38 , L_37
L_38 , error ) ;
return;
}
V_113 = F_113 ( V_105 , 0 , 0 , 0 , ( V_117 - sizeof( * V_113 ) ) , 0 ) ;
V_115 = F_114 ( V_113 ) ;
V_115 -> V_122 = F_5 ( V_38 -> V_80 ) ;
V_115 -> type = V_134 ;
V_115 -> V_124 . V_135 . error = error ;
V_115 -> V_124 . V_135 . V_45 = V_38 -> V_45 ;
V_115 -> V_124 . V_135 . V_42 = F_26 ( V_38 ) ;
F_106 ( V_105 , V_126 , V_119 ) ;
F_112 ( V_78 , V_38 , L_39 ,
error ) ;
}
static int
F_116 ( T_4 V_106 , int V_136 , int type , int V_137 , int V_138 ,
void * V_139 , int V_140 )
{
struct V_104 * V_105 ;
struct V_112 * V_113 ;
int V_117 = F_109 ( V_140 ) ;
int V_43 = V_138 ? V_141 : 0 ;
int V_142 = V_137 ? V_143 : type ;
V_105 = F_110 ( V_117 , V_119 ) ;
if ( ! V_105 ) {
F_12 ( V_18 L_40 ) ;
return - V_121 ;
}
V_113 = F_113 ( V_105 , 0 , 0 , V_142 , ( V_117 - sizeof( * V_113 ) ) , 0 ) ;
V_113 -> V_144 = V_43 ;
memcpy ( F_114 ( V_113 ) , V_139 , V_140 ) ;
return F_106 ( V_105 , V_106 , V_119 ) ;
}
static int
F_117 ( struct V_8 * V_80 , struct V_112 * V_113 )
{
struct V_114 * V_115 = F_114 ( V_113 ) ;
struct V_145 * V_146 ;
struct V_104 * V_147 ;
struct V_37 * V_38 ;
struct V_112 * V_148 ;
struct V_114 * V_149 ;
struct V_3 * V_4 ;
int V_117 = F_109 ( sizeof( * V_115 ) +
sizeof( struct V_145 ) +
sizeof( struct V_150 ) *
V_151 ) ;
int V_15 = 0 ;
V_4 = F_105 ( V_80 ) ;
if ( ! V_4 )
return - V_118 ;
V_38 = F_32 ( V_115 -> V_152 . V_153 . V_42 , V_115 -> V_152 . V_153 . V_45 ) ;
if ( ! V_38 )
return - V_90 ;
do {
int V_154 ;
V_147 = F_110 ( V_117 , V_119 ) ;
if ( ! V_147 ) {
F_112 ( V_18 , V_38 , L_41
L_42 ) ;
return - V_121 ;
}
V_148 = F_113 ( V_147 , 0 , 0 , 0 ,
( V_117 - sizeof( * V_148 ) ) , 0 ) ;
V_149 = F_114 ( V_148 ) ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_122 = F_5 ( V_38 -> V_80 ) ;
V_149 -> type = V_113 -> V_155 ;
V_149 -> V_152 . V_153 . V_45 =
V_115 -> V_152 . V_153 . V_45 ;
V_149 -> V_152 . V_153 . V_42 =
V_115 -> V_152 . V_153 . V_42 ;
V_146 = (struct V_145 * )
( ( char * ) V_149 + sizeof( * V_149 ) ) ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_80 -> V_153 ( V_38 , V_146 ) ;
V_154 = F_109 ( sizeof( struct V_114 ) +
sizeof( struct V_145 ) +
sizeof( struct V_150 ) *
V_146 -> V_156 ) ;
V_154 -= sizeof( * V_148 ) ;
V_154 = F_118 ( V_154 ) ;
F_119 ( V_147 , F_120 ( V_154 ) ) ;
V_148 -> V_157 = V_154 ;
V_15 = F_106 ( V_147 , V_126 ,
V_119 ) ;
} while ( V_15 < 0 && V_15 != - V_158 );
return V_15 ;
}
int F_75 ( struct V_39 * V_52 ,
enum V_159 V_160 )
{
struct V_3 * V_4 ;
struct V_30 * V_31 ;
struct V_114 * V_115 ;
struct V_104 * V_105 ;
struct V_112 * V_113 ;
int V_161 , V_117 = F_109 ( sizeof( * V_115 ) ) ;
V_4 = F_105 ( V_52 -> V_80 ) ;
if ( ! V_4 )
return - V_118 ;
V_31 = F_37 ( V_52 ) ;
V_105 = F_110 ( V_117 , V_19 ) ;
if ( ! V_105 ) {
F_60 ( V_18 , V_52 ,
L_43
L_44 , V_160 ) ;
return - V_121 ;
}
V_113 = F_113 ( V_105 , 0 , 0 , 0 , ( V_117 - sizeof( * V_113 ) ) , 0 ) ;
V_115 = F_114 ( V_113 ) ;
V_115 -> V_122 = F_5 ( V_52 -> V_80 ) ;
V_115 -> type = V_160 ;
switch ( V_160 ) {
case V_96 :
V_115 -> V_124 . V_162 . V_129 = V_31 -> V_129 ;
V_115 -> V_124 . V_162 . V_42 = V_52 -> V_42 ;
break;
case V_95 :
V_115 -> V_124 . V_163 . V_129 = V_31 -> V_129 ;
V_115 -> V_124 . V_163 . V_42 = V_52 -> V_42 ;
break;
case V_88 :
V_115 -> V_124 . V_164 . V_129 = V_31 -> V_129 ;
V_115 -> V_124 . V_164 . V_42 = V_52 -> V_42 ;
break;
default:
F_60 ( V_18 , V_52 , L_45
L_46 , V_160 ) ;
F_121 ( V_105 ) ;
return - V_118 ;
}
V_161 = F_106 ( V_105 , V_126 , V_19 ) ;
if ( V_161 == - V_165 )
F_60 ( V_18 , V_52 ,
L_43
L_47 ,
V_160 ) ;
F_39 ( V_52 , L_48 ,
V_160 , V_161 ) ;
return V_161 ;
}
static int
F_122 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_114 * V_115 , T_4 V_166 ,
T_7 V_167 , T_7 V_168 )
{
struct V_8 * V_80 = V_4 -> V_8 ;
struct V_39 * V_52 ;
struct V_30 * V_31 ;
V_52 = V_80 -> V_169 ( V_10 , V_167 , V_168 ,
V_166 ) ;
if ( ! V_52 )
return - V_121 ;
V_31 = F_37 ( V_52 ) ;
V_115 -> V_124 . V_163 . V_129 = V_31 -> V_129 ;
V_115 -> V_124 . V_163 . V_42 = V_52 -> V_42 ;
F_39 ( V_52 ,
L_49 ) ;
return 0 ;
}
static int
F_123 ( struct V_8 * V_80 , struct V_114 * V_115 )
{
struct V_37 * V_38 ;
struct V_39 * V_52 ;
V_52 = F_28 ( V_115 -> V_152 . V_170 . V_42 ) ;
if ( ! V_52 ) {
F_12 ( V_18 L_50 ,
V_115 -> V_152 . V_170 . V_42 ) ;
return - V_118 ;
}
V_38 = V_80 -> V_171 ( V_52 , V_115 -> V_152 . V_170 . V_45 ) ;
if ( ! V_38 ) {
F_60 ( V_18 , V_52 ,
L_51 ) ;
return - V_121 ;
}
V_115 -> V_124 . V_172 . V_42 = V_52 -> V_42 ;
V_115 -> V_124 . V_172 . V_45 = V_38 -> V_45 ;
F_93 ( V_38 , L_52 ) ;
return 0 ;
}
static int
F_124 ( struct V_8 * V_80 , struct V_114 * V_115 )
{
struct V_37 * V_38 ;
V_38 = F_32 ( V_115 -> V_152 . V_173 . V_42 , V_115 -> V_152 . V_173 . V_45 ) ;
if ( ! V_38 )
return - V_118 ;
F_93 ( V_38 , L_53 ) ;
if ( V_80 -> V_174 )
V_80 -> V_174 ( V_38 ) ;
return 0 ;
}
static int
F_125 ( struct V_8 * V_80 , struct V_114 * V_115 )
{
char * V_12 = ( char * ) V_115 + sizeof( * V_115 ) ;
struct V_37 * V_38 ;
struct V_39 * V_52 ;
int V_15 = 0 , V_51 = 0 ;
V_52 = F_28 ( V_115 -> V_152 . V_175 . V_42 ) ;
V_38 = F_32 ( V_115 -> V_152 . V_175 . V_42 , V_115 -> V_152 . V_175 . V_45 ) ;
if ( ! V_38 || ! V_52 )
return - V_118 ;
switch ( V_115 -> V_152 . V_175 . V_176 ) {
case V_177 :
sscanf ( V_12 , L_54 , & V_51 ) ;
V_52 -> V_79 = V_51 ;
break;
default:
V_15 = V_80 -> V_175 ( V_38 , V_115 -> V_152 . V_175 . V_176 ,
V_12 , V_115 -> V_152 . V_175 . V_117 ) ;
}
return V_15 ;
}
static int F_126 ( struct V_8 * V_80 ,
struct V_114 * V_115 , int V_178 )
{
struct V_9 * V_10 ;
struct V_179 * V_180 ;
struct V_30 * V_31 = NULL ;
int V_181 , V_15 = 0 ;
if ( ! V_80 -> V_182 )
return - V_118 ;
if ( V_178 == V_183 ) {
V_31 = F_127 ( V_115 -> V_152 . V_184 . V_129 ) ;
if ( ! V_31 ) {
F_12 ( V_18 L_55
L_56 ,
V_115 -> V_152 . V_184 . V_129 ) ;
return - V_185 ;
}
V_181 = V_115 -> V_152 . V_184 . V_181 ;
} else
V_181 = V_115 -> V_152 . V_182 . V_181 ;
V_180 = (struct V_179 * ) ( ( char * ) V_115 + sizeof( * V_115 ) ) ;
V_10 = V_80 -> V_182 ( V_31 , V_180 , V_181 ) ;
if ( F_128 ( V_10 ) ) {
V_15 = F_129 ( V_10 ) ;
goto V_93;
}
V_115 -> V_124 . V_186 . V_26 = V_10 -> V_11 ;
V_93:
if ( V_31 )
F_38 ( V_31 ) ;
return V_15 ;
}
static int F_130 ( struct V_8 * V_80 ,
T_3 V_187 )
{
struct V_37 * V_38 ;
struct V_9 * V_10 ;
if ( ! V_80 -> V_188 )
return - V_118 ;
V_10 = F_20 ( V_187 ) ;
if ( ! V_10 )
return - V_118 ;
V_38 = V_10 -> V_38 ;
if ( V_38 ) {
F_48 ( & V_38 -> V_97 ) ;
V_38 -> V_10 = NULL ;
F_50 ( & V_38 -> V_97 ) ;
}
V_80 -> V_188 ( V_10 ) ;
return 0 ;
}
static int
F_131 ( struct V_8 * V_80 ,
struct V_114 * V_115 , int V_178 )
{
struct V_9 * V_10 ;
int V_161 = 0 ;
switch ( V_178 ) {
case V_183 :
case V_189 :
V_161 = F_126 ( V_80 , V_115 , V_178 ) ;
break;
case V_190 :
if ( ! V_80 -> V_191 )
return - V_118 ;
V_10 = F_20 ( V_115 -> V_152 . V_191 . V_187 ) ;
if ( ! V_10 )
return - V_118 ;
V_115 -> V_124 . V_192 = V_80 -> V_191 ( V_10 ,
V_115 -> V_152 . V_191 . V_193 ) ;
break;
case V_194 :
V_161 = F_130 ( V_80 ,
V_115 -> V_152 . V_188 . V_187 ) ;
break;
}
return V_161 ;
}
static int
F_132 ( struct V_8 * V_80 ,
struct V_114 * V_115 )
{
struct V_30 * V_31 ;
struct V_179 * V_180 ;
int V_15 ;
if ( ! V_80 -> V_195 )
return - V_118 ;
V_31 = F_127 ( V_115 -> V_152 . V_195 . V_129 ) ;
if ( ! V_31 ) {
F_12 ( V_18 L_57 ,
V_115 -> V_152 . V_195 . V_129 ) ;
return - V_185 ;
}
V_180 = (struct V_179 * ) ( ( char * ) V_115 + sizeof( * V_115 ) ) ;
V_15 = V_80 -> V_195 ( V_31 , V_115 -> V_152 . V_195 . type ,
V_115 -> V_152 . V_195 . V_196 , V_180 ) ;
F_38 ( V_31 ) ;
return V_15 ;
}
static int
F_133 ( struct V_8 * V_80 ,
struct V_114 * V_115 )
{
char * V_12 = ( char * ) V_115 + sizeof( * V_115 ) ;
struct V_30 * V_31 ;
int V_15 ;
if ( ! V_80 -> V_197 )
return - V_198 ;
V_31 = F_127 ( V_115 -> V_152 . V_197 . V_129 ) ;
if ( ! V_31 ) {
F_12 ( V_18 L_58 ,
V_115 -> V_152 . V_197 . V_129 ) ;
return - V_185 ;
}
V_15 = V_80 -> V_197 ( V_31 , V_115 -> V_152 . V_197 . V_176 ,
V_12 , V_115 -> V_152 . V_197 . V_117 ) ;
F_38 ( V_31 ) ;
return V_15 ;
}
static int
F_134 ( struct V_8 * V_80 , struct V_114 * V_115 )
{
struct V_30 * V_31 ;
struct V_199 * V_200 ;
int V_15 ;
if ( ! V_80 -> V_201 )
return - V_198 ;
V_31 = F_127 ( V_115 -> V_152 . V_201 . V_129 ) ;
if ( ! V_31 ) {
F_12 ( V_18 L_59 ,
V_115 -> V_152 . V_201 . V_129 ) ;
return - V_185 ;
}
V_200 = (struct V_199 * ) ( ( char * ) V_115 + sizeof( * V_115 ) ) ;
V_15 = V_80 -> V_201 ( V_31 , V_200 ) ;
F_38 ( V_31 ) ;
return V_15 ;
}
static int
F_135 ( struct V_104 * V_105 , struct V_112 * V_113 , T_4 * V_106 )
{
int V_15 = 0 ;
struct V_114 * V_115 = F_114 ( V_113 ) ;
struct V_8 * V_80 = NULL ;
struct V_3 * V_4 ;
struct V_39 * V_52 ;
struct V_37 * V_38 ;
struct V_9 * V_10 = NULL ;
if ( V_113 -> V_155 == V_202 )
* V_106 = V_132 ;
else
* V_106 = V_126 ;
V_4 = F_105 ( F_136 ( V_115 -> V_122 ) ) ;
if ( ! V_4 )
return - V_118 ;
V_80 = V_4 -> V_8 ;
if ( ! F_137 ( V_80 -> V_203 ) )
return - V_118 ;
switch ( V_113 -> V_155 ) {
case V_204 :
V_15 = F_122 ( V_4 , V_10 , V_115 ,
V_115 -> V_152 . V_205 . V_166 ,
V_115 -> V_152 . V_205 . V_167 ,
V_115 -> V_152 . V_205 . V_168 ) ;
break;
case V_206 :
V_10 = F_20 ( V_115 -> V_152 . V_207 . V_187 ) ;
if ( ! V_10 ) {
V_15 = - V_118 ;
break;
}
V_15 = F_122 ( V_4 , V_10 , V_115 ,
V_115 -> V_152 . V_207 . V_166 ,
V_115 -> V_152 . V_207 . V_167 ,
V_115 -> V_152 . V_207 . V_168 ) ;
break;
case V_208 :
V_52 = F_28 ( V_115 -> V_152 . V_162 . V_42 ) ;
if ( V_52 )
V_80 -> V_209 ( V_52 ) ;
else
V_15 = - V_118 ;
break;
case V_210 :
V_52 = F_28 ( V_115 -> V_152 . V_162 . V_42 ) ;
if ( V_52 )
F_64 ( F_37 ( V_52 ) ,
& V_52 -> V_87 ) ;
else
V_15 = - V_118 ;
break;
case V_211 :
V_15 = F_123 ( V_80 , V_115 ) ;
break;
case V_212 :
V_15 = F_124 ( V_80 , V_115 ) ;
break;
case V_213 :
V_52 = F_28 ( V_115 -> V_152 . V_214 . V_42 ) ;
V_38 = F_32 ( V_115 -> V_152 . V_214 . V_42 , V_115 -> V_152 . V_214 . V_45 ) ;
if ( V_38 && V_38 -> V_10 )
F_130 ( V_80 , V_38 -> V_10 -> V_11 ) ;
if ( ! V_52 || ! V_38 ) {
V_15 = - V_118 ;
break;
}
V_115 -> V_124 . V_192 = V_80 -> V_215 ( V_52 , V_38 ,
V_115 -> V_152 . V_214 . V_216 ,
V_115 -> V_152 . V_214 . V_217 ) ;
if ( V_115 -> V_124 . V_192 || ! V_80 -> V_182 )
break;
V_10 = F_20 ( V_115 -> V_152 . V_214 . V_216 ) ;
if ( V_10 ) {
V_10 -> V_38 = V_38 ;
F_48 ( & V_38 -> V_97 ) ;
V_38 -> V_10 = V_10 ;
F_50 ( & V_38 -> V_97 ) ;
} else
F_112 ( V_18 , V_38 ,
L_60
L_61 ) ;
break;
case V_218 :
V_15 = F_125 ( V_80 , V_115 ) ;
break;
case V_219 :
V_38 = F_32 ( V_115 -> V_152 . V_220 . V_42 , V_115 -> V_152 . V_220 . V_45 ) ;
if ( V_38 )
V_115 -> V_124 . V_192 = V_80 -> V_220 ( V_38 ) ;
else
V_15 = - V_118 ;
break;
case V_221 :
V_38 = F_32 ( V_115 -> V_152 . V_222 . V_42 , V_115 -> V_152 . V_222 . V_45 ) ;
if ( V_38 )
V_80 -> V_222 ( V_38 , V_115 -> V_152 . V_222 . V_223 ) ;
else
V_15 = - V_118 ;
break;
case V_224 :
V_38 = F_32 ( V_115 -> V_152 . V_225 . V_42 , V_115 -> V_152 . V_225 . V_45 ) ;
if ( V_38 )
V_115 -> V_124 . V_192 = V_80 -> V_225 ( V_38 ,
(struct V_109 * ) ( ( char * ) V_115 + sizeof( * V_115 ) ) ,
( char * ) V_115 + sizeof( * V_115 ) + V_115 -> V_152 . V_225 . V_226 ,
V_115 -> V_152 . V_225 . V_111 ) ;
else
V_15 = - V_118 ;
break;
case V_227 :
V_15 = F_117 ( V_80 , V_113 ) ;
break;
case V_189 :
case V_190 :
case V_194 :
case V_183 :
V_15 = F_131 ( V_80 , V_115 , V_113 -> V_155 ) ;
break;
case V_228 :
V_15 = F_132 ( V_80 , V_115 ) ;
break;
case V_229 :
V_15 = F_133 ( V_80 , V_115 ) ;
break;
case V_202 :
V_15 = F_134 ( V_80 , V_115 ) ;
break;
default:
V_15 = - V_198 ;
break;
}
F_138 ( V_80 -> V_203 ) ;
return V_15 ;
}
static void
F_139 ( struct V_104 * V_105 )
{
F_48 ( & V_230 ) ;
while ( V_105 -> V_117 >= F_109 ( 0 ) ) {
int V_15 ;
T_4 V_231 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
T_4 V_106 ;
V_113 = F_140 ( V_105 ) ;
if ( V_113 -> V_157 < sizeof( * V_113 ) ||
V_105 -> V_117 < V_113 -> V_157 ) {
break;
}
V_115 = F_114 ( V_113 ) ;
V_231 = F_120 ( V_113 -> V_157 ) ;
if ( V_231 > V_105 -> V_117 )
V_231 = V_105 -> V_117 ;
V_15 = F_135 ( V_105 , V_113 , & V_106 ) ;
if ( V_15 ) {
V_115 -> type = V_232 ;
V_115 -> V_233 = V_15 ;
}
do {
if ( V_115 -> type == V_227 && ! V_15 )
break;
V_15 = F_116 ( V_106 , V_113 -> V_234 ,
V_113 -> V_155 , 0 , 0 , V_115 , sizeof( * V_115 ) ) ;
} while ( V_15 < 0 && V_15 != - V_158 );
F_141 ( V_105 , V_231 ) ;
}
F_50 ( & V_230 ) ;
}
static T_1
F_142 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_39 * V_52 = F_27 ( V_2 -> V_41 ) ;
return sprintf ( V_7 , L_62 , F_33 ( V_52 -> V_47 ) ) ;
}
static int F_143 ( struct V_235 * V_236 ,
struct V_1 * V_2 )
{
struct V_39 * V_52 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
if ( ! F_40 ( V_2 ) )
return 0 ;
V_52 = F_27 ( V_2 ) ;
V_31 = F_37 ( V_52 ) ;
if ( ! V_31 -> V_237 )
return 0 ;
V_4 = F_144 ( V_31 -> V_237 ) ;
if ( V_4 -> V_238 . V_239 . V_20 != & V_240 . V_20 )
return 0 ;
return & V_4 -> V_238 . V_239 == V_236 ;
}
static int F_145 ( struct V_235 * V_236 ,
struct V_1 * V_2 )
{
struct V_39 * V_52 ;
struct V_37 * V_38 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
if ( ! F_94 ( V_2 ) )
return 0 ;
V_38 = F_92 ( V_2 ) ;
V_52 = F_27 ( V_38 -> V_2 . V_41 ) ;
V_31 = F_37 ( V_52 ) ;
if ( ! V_31 -> V_237 )
return 0 ;
V_4 = F_144 ( V_31 -> V_237 ) ;
if ( V_4 -> V_241 . V_239 . V_20 != & V_242 . V_20 )
return 0 ;
return & V_4 -> V_241 . V_239 == V_236 ;
}
static int F_146 ( struct V_235 * V_236 ,
struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_3 * V_4 ;
if ( ! F_147 ( V_2 ) )
return 0 ;
V_31 = F_23 ( V_2 ) ;
if ( ! V_31 -> V_237 ||
V_31 -> V_237 -> V_243 . V_239 . V_20 != & V_244 . V_20 )
return 0 ;
V_4 = F_144 ( V_31 -> V_237 ) ;
return & V_4 -> V_142 . V_243 . V_239 == V_236 ;
}
struct V_245 *
F_148 ( struct V_8 * V_102 )
{
struct V_3 * V_4 ;
unsigned long V_43 ;
int V_246 = 0 , V_15 ;
F_149 ( ! V_102 ) ;
V_4 = F_105 ( V_102 ) ;
if ( V_4 )
return NULL ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_78 ( & V_4 -> V_247 ) ;
V_4 -> V_8 = V_102 ;
V_4 -> V_142 . V_248 = F_51 ;
V_4 -> V_142 . V_249 = 1 ;
V_4 -> V_2 . V_20 = & V_250 ;
F_14 ( & V_4 -> V_2 , L_63 , V_102 -> V_49 ) ;
V_15 = F_15 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_251;
V_15 = F_16 ( & V_4 -> V_2 . V_22 , & V_252 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_142 . V_243 . V_239 . V_253 = & V_4 -> V_243 [ 0 ] ;
V_4 -> V_142 . V_243 . V_239 . V_20 = & V_244 . V_20 ;
V_4 -> V_142 . V_243 . V_239 . V_254 = F_146 ;
V_4 -> V_142 . V_255 = sizeof( struct V_32 ) ;
F_150 ( & V_4 -> V_142 . V_243 ) ;
F_151 ( V_256 , V_257 ) ;
F_151 ( V_258 , V_259 ) ;
F_151 ( V_260 , V_261 ) ;
F_151 ( V_262 , V_263 ) ;
F_149 ( V_246 > V_264 ) ;
V_4 -> V_243 [ V_246 ] = NULL ;
V_246 = 0 ;
V_4 -> V_241 . V_239 . V_253 = & V_4 -> V_265 [ 0 ] ;
V_4 -> V_241 . V_239 . V_20 = & V_242 . V_20 ;
V_4 -> V_241 . V_239 . V_254 = F_145 ;
F_150 ( & V_4 -> V_241 ) ;
F_152 ( V_266 , V_267 ) ;
F_152 ( V_268 , V_269 ) ;
F_152 ( V_270 , V_271 ) ;
F_152 ( V_272 , V_273 ) ;
F_152 ( V_274 , V_275 ) ;
F_152 ( V_276 , V_277 ) ;
F_152 ( V_278 , V_279 ) ;
F_152 ( V_280 , V_281 ) ;
F_152 ( V_282 , V_283 ) ;
F_152 ( V_284 , V_285 ) ;
F_152 ( V_286 , V_287 ) ;
F_152 ( V_288 , V_289 ) ;
F_152 ( V_290 , V_291 ) ;
F_149 ( V_246 > V_292 ) ;
V_4 -> V_265 [ V_246 ] = NULL ;
V_246 = 0 ;
V_4 -> V_238 . V_239 . V_253 = & V_4 -> V_293 [ 0 ] ;
V_4 -> V_238 . V_239 . V_20 = & V_240 . V_20 ;
V_4 -> V_238 . V_239 . V_254 = F_143 ;
F_150 ( & V_4 -> V_238 ) ;
F_153 ( V_294 , V_295 ) ;
F_153 ( V_296 , V_297 ) ;
F_153 ( V_298 , V_299 ) ;
F_153 ( V_300 , V_301 ) ;
F_153 ( V_302 , V_303 ) ;
F_153 ( V_304 , V_305 ) ;
F_153 ( V_306 , V_307 ) ;
F_153 ( V_308 , V_309 ) ;
F_153 ( V_310 , V_311 ) ;
F_153 ( V_312 , V_313 ) ;
F_153 ( V_314 , V_315 ) ;
F_153 ( V_316 , V_317 ) ;
F_153 ( V_318 , V_319 ) ;
F_153 ( V_320 , V_321 ) ;
F_153 ( V_322 , V_323 ) ;
F_153 ( V_324 , V_325 ) ;
F_153 ( V_326 , V_327 ) ;
F_153 ( V_328 , V_329 ) ;
F_153 ( V_330 , V_331 ) ;
F_153 ( V_262 , V_332 ) ;
F_153 ( V_333 , V_334 ) ;
F_154 ( V_79 ) ;
F_155 ( V_47 ) ;
F_149 ( V_246 > V_335 ) ;
V_4 -> V_293 [ V_246 ] = NULL ;
F_29 ( & V_103 , V_43 ) ;
F_88 ( & V_4 -> V_247 , & V_336 ) ;
F_31 ( & V_103 , V_43 ) ;
F_12 ( V_337 L_64 , V_102 -> V_49 ) ;
return & V_4 -> V_142 ;
V_24:
F_17 ( & V_4 -> V_2 ) ;
return NULL ;
V_251:
F_3 ( V_4 ) ;
return NULL ;
}
int F_156 ( struct V_8 * V_102 )
{
struct V_3 * V_4 ;
unsigned long V_43 ;
F_149 ( ! V_102 ) ;
F_48 ( & V_230 ) ;
V_4 = F_105 ( V_102 ) ;
F_149 ( ! V_4 ) ;
F_29 ( & V_103 , V_43 ) ;
F_98 ( & V_4 -> V_247 ) ;
F_31 ( & V_103 , V_43 ) ;
F_157 ( & V_4 -> V_241 ) ;
F_157 ( & V_4 -> V_238 ) ;
F_157 ( & V_4 -> V_142 . V_243 ) ;
F_19 ( & V_4 -> V_2 . V_22 , & V_252 ) ;
F_17 ( & V_4 -> V_2 ) ;
F_50 ( & V_230 ) ;
return 0 ;
}
static T_8 int F_158 ( void )
{
int V_15 ;
F_12 ( V_78 L_65 ,
V_338 ) ;
F_24 ( & V_91 , 0 ) ;
V_15 = F_159 ( & V_250 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_159 ( & V_17 ) ;
if ( V_15 )
goto V_339;
V_15 = F_160 ( & V_244 ) ;
if ( V_15 )
goto V_340;
V_15 = F_160 ( & V_242 ) ;
if ( V_15 )
goto V_341;
V_15 = F_160 ( & V_240 ) ;
if ( V_15 )
goto V_342;
V_108 = F_161 ( & V_343 , V_344 , 1 , F_139 ,
NULL , V_345 ) ;
if ( ! V_108 ) {
V_15 = - V_346 ;
goto V_347;
}
V_84 = F_162 ( L_66 ) ;
if ( ! V_84 )
goto V_348;
return 0 ;
V_348:
F_163 ( V_108 ) ;
V_347:
F_164 ( & V_240 ) ;
V_342:
F_164 ( & V_242 ) ;
V_341:
F_164 ( & V_244 ) ;
V_340:
F_165 ( & V_17 ) ;
V_339:
F_165 ( & V_250 ) ;
return V_15 ;
}
static void T_9 F_166 ( void )
{
F_167 ( V_84 ) ;
F_163 ( V_108 ) ;
F_164 ( & V_242 ) ;
F_164 ( & V_240 ) ;
F_164 ( & V_244 ) ;
F_165 ( & V_17 ) ;
F_165 ( & V_250 ) ;
}
