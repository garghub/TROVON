static void F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 = V_3 ;
int V_6 ;
unsigned long V_7 ;
F_2 ( & ( V_5 -> V_8 ) , V_7 ) ;
V_6 = F_3 ( & ( V_5 -> V_9 ) ) ;
F_4 ( & ( V_2 -> V_10 ) , & ( V_5 -> V_9 ) ) ;
if ( V_6 ) {
F_5 ( & V_5 -> V_11 ) ;
F_6 ( & V_5 -> V_12 , V_13 , V_14 ) ;
}
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
}
static unsigned int F_8 ( struct V_15 * V_15 , T_1 * V_11 )
{
struct V_4 * V_5 = V_15 -> V_16 ;
unsigned int V_17 = 0 ;
unsigned long V_7 ;
F_9 ( V_15 , & V_5 -> V_11 , V_11 ) ;
F_2 ( & V_5 -> V_8 , V_7 ) ;
if ( ! F_3 ( & ( V_5 -> V_9 ) ) )
V_17 |= ( V_18 | V_19 ) ;
F_7 ( & V_5 -> V_8 , V_7 ) ;
return V_17 ;
}
static int F_10 ( int V_20 , struct V_15 * V_15 , int V_21 )
{
struct V_4 * V_5 = V_15 -> V_16 ;
int V_22 ;
F_11 ( & V_23 ) ;
V_22 = F_12 ( V_20 , V_15 , V_21 , & V_5 -> V_12 ) ;
F_13 ( & V_23 ) ;
return ( V_22 ) ;
}
static int F_14 ( struct V_24 * V_24 , struct V_15 * V_15 )
{
int V_25 = F_15 ( V_24 ) ;
int V_26 ;
struct V_4 * V_5 ;
V_5 = F_16 ( sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
F_11 ( & V_23 ) ;
V_5 -> V_15 = V_15 ;
V_26 = F_17 ( V_25 ,
& V_29 ,
V_5 ,
& ( V_5 -> V_30 ) ) ;
if ( V_26 ) {
F_18 ( V_5 ) ;
goto V_31;
}
V_15 -> V_16 = V_5 ;
F_19 ( & ( V_5 -> V_8 ) ) ;
F_20 ( & ( V_5 -> V_9 ) ) ;
F_21 ( & V_5 -> V_11 ) ;
V_5 -> V_12 = NULL ;
F_22 ( & V_5 -> V_32 ) ;
V_5 -> V_33 = - 1 ;
V_5 -> V_34 = 0 ;
V_31:
F_13 ( & V_23 ) ;
return V_26 ;
}
static int F_23 ( struct V_24 * V_24 , struct V_15 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_16 ;
int V_26 ;
struct V_1 * V_2 , * V_35 ;
V_26 = F_24 ( V_5 -> V_30 ) ;
if ( V_26 )
return V_26 ;
F_25 (msg, next, &priv->recv_msgs, link)
F_26 ( V_2 ) ;
F_18 ( V_5 ) ;
return 0 ;
}
static int F_27 ( T_2 V_30 ,
struct V_36 * V_37 ,
int V_38 ,
unsigned int V_39 )
{
int V_26 ;
struct V_40 V_41 ;
struct V_42 V_2 ;
if ( V_37 -> V_43 > sizeof( struct V_40 ) )
return - V_44 ;
if ( F_28 ( & V_41 , V_37 -> V_41 , V_37 -> V_43 ) )
return - V_45 ;
V_2 . V_46 = V_37 -> V_2 . V_46 ;
V_2 . V_47 = V_37 -> V_2 . V_47 ;
V_2 . V_48 = V_37 -> V_2 . V_48 ;
V_2 . V_49 = F_16 ( V_50 , V_27 ) ;
if ( ! V_2 . V_49 )
return - V_28 ;
V_26 = F_29 ( & V_41 , V_37 -> V_43 ) ;
if ( V_26 )
goto V_31;
if ( V_37 -> V_2 . V_49 != NULL ) {
if ( V_37 -> V_2 . V_48 > V_50 ) {
V_26 = - V_51 ;
goto V_31;
}
if ( F_28 ( V_2 . V_49 ,
V_37 -> V_2 . V_49 ,
V_37 -> V_2 . V_48 ) )
{
V_26 = - V_45 ;
goto V_31;
}
} else {
V_2 . V_48 = 0 ;
}
V_26 = F_30 ( V_30 ,
& V_41 ,
V_37 -> V_52 ,
& V_2 ,
NULL ,
0 ,
V_38 ,
V_39 ) ;
V_31:
F_18 ( V_2 . V_49 ) ;
return V_26 ;
}
static int F_31 ( struct V_4 * V_5 ,
bool V_53 , struct V_54 * V_55 ,
int (* F_32)( struct V_54 * , void T_3 * ) ,
void T_3 * V_56 )
{
int V_43 ;
struct V_57 * V_58 ;
struct V_1 * V_2 ;
unsigned long V_7 ;
int V_26 = 0 ;
F_11 ( & V_5 -> V_32 ) ;
F_2 ( & ( V_5 -> V_8 ) , V_7 ) ;
if ( F_3 ( & ( V_5 -> V_9 ) ) ) {
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
V_26 = - V_59 ;
goto V_60;
}
V_58 = V_5 -> V_9 . V_35 ;
V_2 = F_33 ( V_58 , struct V_1 , V_10 ) ;
F_34 ( V_58 ) ;
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
V_43 = F_35 ( V_2 -> V_41 . V_61 ) ;
if ( V_55 -> V_43 < V_43 )
{
V_26 = - V_44 ;
goto V_62;
}
if ( F_36 ( V_55 -> V_41 , & ( V_2 -> V_41 ) , V_43 ) ) {
V_26 = - V_45 ;
goto V_62;
}
V_55 -> V_43 = V_43 ;
V_55 -> V_63 = V_2 -> V_63 ;
V_55 -> V_52 = V_2 -> V_52 ;
V_55 -> V_2 . V_46 = V_2 -> V_2 . V_46 ;
V_55 -> V_2 . V_47 = V_2 -> V_2 . V_47 ;
if ( V_2 -> V_2 . V_48 > 0 ) {
if ( V_55 -> V_2 . V_48 < V_2 -> V_2 . V_48 ) {
V_26 = - V_51 ;
if ( V_53 )
V_2 -> V_2 . V_48 = V_55 -> V_2 . V_48 ;
else
goto V_62;
}
if ( F_36 ( V_55 -> V_2 . V_49 ,
V_2 -> V_2 . V_49 ,
V_2 -> V_2 . V_48 ) )
{
V_26 = - V_45 ;
goto V_62;
}
V_55 -> V_2 . V_48 = V_2 -> V_2 . V_48 ;
} else {
V_55 -> V_2 . V_48 = 0 ;
}
V_26 = F_32 ( V_55 , V_56 ) ;
if ( V_26 )
goto V_62;
F_13 ( & V_5 -> V_32 ) ;
F_26 ( V_2 ) ;
return 0 ;
V_62:
F_2 ( & ( V_5 -> V_8 ) , V_7 ) ;
F_37 ( V_58 , & ( V_5 -> V_9 ) ) ;
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
V_60:
F_13 ( & V_5 -> V_32 ) ;
return V_26 ;
}
static int F_38 ( struct V_54 * V_55 , void T_3 * V_56 )
{
return F_36 ( V_56 , V_55 , sizeof( struct V_54 ) ) ? - V_45 : 0 ;
}
static int F_39 ( struct V_15 * V_15 ,
unsigned int V_47 ,
unsigned long V_49 )
{
int V_26 = - V_44 ;
struct V_4 * V_5 = V_15 -> V_16 ;
void T_3 * V_64 = ( void T_3 * ) V_49 ;
switch ( V_47 )
{
case V_65 :
{
struct V_36 V_37 ;
if ( F_28 ( & V_37 , V_64 , sizeof( V_37 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_27 ( V_5 -> V_30 ,
& V_37 ,
V_5 -> V_33 ,
V_5 -> V_34 ) ;
break;
}
case V_66 :
{
struct V_67 V_37 ;
if ( F_28 ( & V_37 , V_64 , sizeof( V_37 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_27 ( V_5 -> V_30 ,
& V_37 . V_37 ,
V_37 . V_38 ,
V_37 . V_39 ) ;
break;
}
case V_68 :
case V_69 :
{
struct V_54 V_55 ;
if ( F_28 ( & V_55 , V_64 , sizeof( V_55 ) ) )
V_26 = - V_45 ;
else
V_26 = F_31 ( V_5 , V_47 == V_69 ,
& V_55 , F_38 , V_64 ) ;
break;
}
case V_70 :
{
struct V_71 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_40 ( V_5 -> V_30 , V_72 . V_46 , V_72 . V_47 ,
V_73 ) ;
break;
}
case V_74 :
{
struct V_71 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_41 ( V_5 -> V_30 , V_72 . V_46 , V_72 . V_47 ,
V_73 ) ;
break;
}
case V_75 :
{
struct V_76 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_40 ( V_5 -> V_30 , V_72 . V_46 , V_72 . V_47 ,
V_72 . V_77 ) ;
break;
}
case V_78 :
{
struct V_76 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_41 ( V_5 -> V_30 , V_72 . V_46 , V_72 . V_47 ,
V_72 . V_77 ) ;
break;
}
case V_79 :
{
int V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_42 ( V_5 -> V_30 , V_72 ) ;
break;
}
case V_80 :
{
unsigned int V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_43 ( V_5 -> V_30 , 0 , V_72 ) ;
break;
}
case V_81 :
{
unsigned int V_72 ;
unsigned char V_82 ;
V_26 = F_44 ( V_5 -> V_30 , 0 , & V_82 ) ;
if ( V_26 )
break;
V_72 = V_82 ;
if ( F_36 ( V_64 , & V_72 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
break;
}
case V_83 :
{
unsigned int V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_45 ( V_5 -> V_30 , 0 , V_72 ) ;
break;
}
case V_84 :
{
unsigned int V_72 ;
unsigned char V_82 ;
V_26 = F_46 ( V_5 -> V_30 , 0 , & V_82 ) ;
if ( V_26 )
break;
V_72 = V_82 ;
if ( F_36 ( V_64 , & V_72 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
break;
}
case V_85 :
{
struct V_86 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
return F_43 ( V_5 -> V_30 , V_72 . V_87 , V_72 . V_88 ) ;
break;
}
case V_89 :
{
struct V_86 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_44 ( V_5 -> V_30 , V_72 . V_87 , & V_72 . V_88 ) ;
if ( V_26 )
break;
if ( F_36 ( V_64 , & V_72 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
break;
}
case V_90 :
{
struct V_86 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_45 ( V_5 -> V_30 , V_72 . V_87 , V_72 . V_88 ) ;
break;
}
case V_91 :
{
struct V_86 V_72 ;
if ( F_28 ( & V_72 , V_64 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_46 ( V_5 -> V_30 , V_72 . V_87 , & V_72 . V_88 ) ;
if ( V_26 )
break;
if ( F_36 ( V_64 , & V_72 , sizeof( V_72 ) ) ) {
V_26 = - V_45 ;
break;
}
break;
}
case V_92 :
{
struct V_93 V_94 ;
if ( F_28 ( & V_94 , V_64 , sizeof( V_94 ) ) ) {
V_26 = - V_45 ;
break;
}
V_5 -> V_33 = V_94 . V_38 ;
V_5 -> V_34 = V_94 . V_39 ;
V_26 = 0 ;
break;
}
case V_95 :
{
struct V_93 V_94 ;
V_94 . V_38 = V_5 -> V_33 ;
V_94 . V_39 = V_5 -> V_34 ;
if ( F_36 ( V_64 , & V_94 , sizeof( V_94 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = 0 ;
break;
}
case V_96 :
{
int V_97 ;
V_97 = F_47 ( V_5 -> V_30 ) ;
if ( F_36 ( V_64 , & V_97 , sizeof( V_97 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = 0 ;
break;
}
case V_98 :
{
int V_97 ;
if ( F_28 ( & V_97 , V_64 , sizeof( V_97 ) ) ) {
V_26 = - V_45 ;
break;
}
V_26 = F_48 ( V_5 -> V_30 , V_97 ) ;
break;
}
}
return V_26 ;
}
static long F_49 ( struct V_15 * V_15 ,
unsigned int V_47 ,
unsigned long V_49 )
{
int V_99 ;
F_11 ( & V_23 ) ;
V_99 = F_39 ( V_15 , V_47 , V_49 ) ;
F_13 ( & V_23 ) ;
return V_99 ;
}
static void F_50 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
V_101 -> V_46 = V_103 -> V_46 ;
V_101 -> V_47 = V_103 -> V_47 ;
V_101 -> V_48 = V_103 -> V_48 ;
V_101 -> V_49 = F_51 ( V_103 -> V_49 ) ;
}
static void F_52 ( struct V_36 * V_101 ,
struct V_104 * V_103 )
{
V_101 -> V_41 = F_51 ( V_103 -> V_41 ) ;
V_101 -> V_43 = V_103 -> V_43 ;
V_101 -> V_52 = V_103 -> V_52 ;
F_50 ( & V_101 -> V_2 , & V_103 -> V_2 ) ;
}
static void F_53 ( struct V_67 * V_101 ,
struct V_105 * V_103 )
{
F_52 ( & V_101 -> V_37 , & V_103 -> V_37 ) ;
V_101 -> V_38 = V_103 -> V_38 ;
V_101 -> V_39 = V_103 -> V_39 ;
}
static void F_54 ( struct V_54 * V_101 ,
struct V_106 * V_103 )
{
memset ( V_101 , 0 , sizeof( struct V_54 ) ) ;
V_101 -> V_63 = V_103 -> V_63 ;
V_101 -> V_41 = F_51 ( V_103 -> V_41 ) ;
V_101 -> V_43 = V_103 -> V_43 ;
V_101 -> V_52 = V_103 -> V_52 ;
F_50 ( & V_101 -> V_2 , & V_103 -> V_2 ) ;
}
static int F_55 ( struct V_54 * V_101 , void T_3 * V_56 )
{
struct V_106 V_107 ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
V_107 . V_63 = V_101 -> V_63 ;
V_107 . V_41 = F_56 ( V_101 -> V_41 ) ;
V_107 . V_43 = V_101 -> V_43 ;
V_107 . V_52 = V_101 -> V_52 ;
V_107 . V_2 . V_46 = V_101 -> V_2 . V_46 ;
V_107 . V_2 . V_47 = V_101 -> V_2 . V_47 ;
V_107 . V_2 . V_48 = V_101 -> V_2 . V_48 ;
V_107 . V_2 . V_49 = F_56 ( V_101 -> V_2 . V_49 ) ;
return F_36 ( V_56 , & V_107 , sizeof( V_107 ) ) ? - V_45 : 0 ;
}
static long F_57 ( struct V_15 * V_108 , unsigned int V_47 ,
unsigned long V_64 )
{
struct V_4 * V_5 = V_108 -> V_16 ;
switch( V_47 ) {
case V_109 :
{
struct V_36 V_110 ;
struct V_104 V_111 ;
if ( F_28 ( & V_111 , F_51 ( V_64 ) , sizeof( V_111 ) ) )
return - V_45 ;
F_52 ( & V_110 , & V_111 ) ;
return F_27 ( V_5 -> V_30 , & V_110 ,
V_5 -> V_33 ,
V_5 -> V_34 ) ;
}
case V_112 :
{
struct V_67 V_113 ;
struct V_105 V_114 ;
if ( F_28 ( & V_114 , F_51 ( V_64 ) , sizeof( V_114 ) ) )
return - V_45 ;
F_53 ( & V_113 , & V_114 ) ;
return F_27 ( V_5 -> V_30 , & V_113 . V_37 ,
V_113 . V_38 , V_113 . V_39 ) ;
}
case V_115 :
case V_116 :
{
struct V_54 V_117 ;
struct V_106 V_118 ;
if ( F_28 ( & V_118 , F_51 ( V_64 ) , sizeof( V_118 ) ) )
return - V_45 ;
F_54 ( & V_117 , & V_118 ) ;
return F_31 ( V_5 ,
V_47 == V_116 ,
& V_117 , F_55 , F_51 ( V_64 ) ) ;
}
default:
return F_39 ( V_108 , V_47 , V_64 ) ;
}
}
static long F_58 ( struct V_15 * V_108 , unsigned int V_47 ,
unsigned long V_64 )
{
int V_99 ;
F_11 ( & V_23 ) ;
V_99 = F_57 ( V_108 , V_47 , V_64 ) ;
F_13 ( & V_23 ) ;
return V_99 ;
}
static void F_59 ( int V_25 , struct V_119 * V_119 )
{
T_4 V_120 = F_60 ( V_121 , V_25 ) ;
struct V_122 * V_58 ;
V_58 = F_16 ( sizeof( * V_58 ) , V_27 ) ;
if ( ! V_58 ) {
F_61 ( V_123 L_1
L_2 ) ;
return;
}
V_58 -> V_120 = V_120 ;
F_11 ( & V_124 ) ;
F_62 ( V_125 , V_119 , V_120 , NULL , L_3 , V_25 ) ;
F_37 ( & V_58 -> V_10 , & V_126 ) ;
F_13 ( & V_124 ) ;
}
static void F_63 ( int V_25 )
{
T_4 V_120 = F_60 ( V_121 , V_25 ) ;
struct V_122 * V_58 ;
F_11 ( & V_124 ) ;
F_64 (entry, &reg_list, link) {
if ( V_58 -> V_120 == V_120 ) {
F_34 ( & V_58 -> V_10 ) ;
F_18 ( V_58 ) ;
break;
}
}
F_65 ( V_125 , V_120 ) ;
F_13 ( & V_124 ) ;
}
static int T_5 F_66 ( void )
{
int V_26 ;
if ( V_121 < 0 )
return - V_44 ;
F_61 ( V_127 L_4 ) ;
V_125 = F_67 ( V_128 , L_5 ) ;
if ( F_68 ( V_125 ) ) {
F_61 ( V_123 L_6 ) ;
return F_69 ( V_125 ) ;
}
V_26 = F_70 ( V_121 , V_129 , & V_130 ) ;
if ( V_26 < 0 ) {
F_71 ( V_125 ) ;
F_61 ( V_123 L_7 , V_121 ) ;
return V_26 ;
}
if ( V_121 == 0 ) {
V_121 = V_26 ;
}
V_26 = F_72 ( & V_131 ) ;
if ( V_26 ) {
F_73 ( V_121 , V_129 ) ;
F_71 ( V_125 ) ;
F_61 ( V_132 L_8 ) ;
return V_26 ;
}
return 0 ;
}
static void T_6 F_74 ( void )
{
struct V_122 * V_58 , * V_133 ;
F_11 ( & V_124 ) ;
F_25 (entry, entry2, &reg_list, link) {
F_34 ( & V_58 -> V_10 ) ;
F_65 ( V_125 , V_58 -> V_120 ) ;
F_18 ( V_58 ) ;
}
F_13 ( & V_124 ) ;
F_71 ( V_125 ) ;
F_75 ( & V_131 ) ;
F_73 ( V_121 , V_129 ) ;
}
