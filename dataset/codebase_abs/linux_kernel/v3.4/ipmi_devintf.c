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
V_26 = F_24 ( V_5 -> V_30 ) ;
if ( V_26 )
return V_26 ;
F_18 ( V_5 ) ;
return 0 ;
}
static int F_25 ( T_2 V_30 ,
struct V_35 * V_36 ,
int V_37 ,
unsigned int V_38 )
{
int V_26 ;
struct V_39 V_40 ;
struct V_41 V_2 ;
if ( V_36 -> V_42 > sizeof( struct V_39 ) )
return - V_43 ;
if ( F_26 ( & V_40 , V_36 -> V_40 , V_36 -> V_42 ) )
return - V_44 ;
V_2 . V_45 = V_36 -> V_2 . V_45 ;
V_2 . V_46 = V_36 -> V_2 . V_46 ;
V_2 . V_47 = V_36 -> V_2 . V_47 ;
V_2 . V_48 = F_16 ( V_49 , V_27 ) ;
if ( ! V_2 . V_48 )
return - V_28 ;
V_26 = F_27 ( & V_40 , V_36 -> V_42 ) ;
if ( V_26 )
goto V_31;
if ( V_36 -> V_2 . V_48 != NULL ) {
if ( V_36 -> V_2 . V_47 > V_49 ) {
V_26 = - V_50 ;
goto V_31;
}
if ( F_26 ( V_2 . V_48 ,
V_36 -> V_2 . V_48 ,
V_36 -> V_2 . V_47 ) )
{
V_26 = - V_44 ;
goto V_31;
}
} else {
V_2 . V_47 = 0 ;
}
V_26 = F_28 ( V_30 ,
& V_40 ,
V_36 -> V_51 ,
& V_2 ,
NULL ,
0 ,
V_37 ,
V_38 ) ;
V_31:
F_18 ( V_2 . V_48 ) ;
return V_26 ;
}
static int F_29 ( struct V_15 * V_15 ,
unsigned int V_46 ,
unsigned long V_48 )
{
int V_26 = - V_43 ;
struct V_4 * V_5 = V_15 -> V_16 ;
void T_3 * V_52 = ( void T_3 * ) V_48 ;
switch ( V_46 )
{
case V_53 :
{
struct V_35 V_36 ;
if ( F_26 ( & V_36 , V_52 , sizeof( V_36 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_25 ( V_5 -> V_30 ,
& V_36 ,
V_5 -> V_33 ,
V_5 -> V_34 ) ;
break;
}
case V_54 :
{
struct V_55 V_36 ;
if ( F_26 ( & V_36 , V_52 , sizeof( V_36 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_25 ( V_5 -> V_30 ,
& V_36 . V_36 ,
V_36 . V_37 ,
V_36 . V_38 ) ;
break;
}
case V_56 :
case V_57 :
{
struct V_58 V_59 ;
int V_42 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
unsigned long V_7 ;
V_26 = 0 ;
if ( F_26 ( & V_59 , V_52 , sizeof( V_59 ) ) ) {
V_26 = - V_44 ;
break;
}
F_11 ( & V_5 -> V_32 ) ;
F_2 ( & ( V_5 -> V_8 ) , V_7 ) ;
if ( F_3 ( & ( V_5 -> V_9 ) ) ) {
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
V_26 = - V_62 ;
goto V_63;
}
V_61 = V_5 -> V_9 . V_64 ;
V_2 = F_30 ( V_61 , struct V_1 , V_10 ) ;
F_31 ( V_61 ) ;
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
V_42 = F_32 ( V_2 -> V_40 . V_65 ) ;
if ( V_59 . V_42 < V_42 )
{
V_26 = - V_43 ;
goto V_66;
}
if ( F_33 ( V_59 . V_40 , & ( V_2 -> V_40 ) , V_42 ) ) {
V_26 = - V_44 ;
goto V_66;
}
V_59 . V_42 = V_42 ;
V_59 . V_67 = V_2 -> V_67 ;
V_59 . V_51 = V_2 -> V_51 ;
V_59 . V_2 . V_45 = V_2 -> V_2 . V_45 ;
V_59 . V_2 . V_46 = V_2 -> V_2 . V_46 ;
if ( V_2 -> V_2 . V_47 > 0 ) {
if ( V_59 . V_2 . V_47 < V_2 -> V_2 . V_47 ) {
V_26 = - V_50 ;
if ( V_46 == V_57 ) {
V_2 -> V_2 . V_47 = V_59 . V_2 . V_47 ;
} else {
goto V_66;
}
}
if ( F_33 ( V_59 . V_2 . V_48 ,
V_2 -> V_2 . V_48 ,
V_2 -> V_2 . V_47 ) )
{
V_26 = - V_44 ;
goto V_66;
}
V_59 . V_2 . V_47 = V_2 -> V_2 . V_47 ;
} else {
V_59 . V_2 . V_47 = 0 ;
}
if ( F_33 ( V_52 , & V_59 , sizeof( V_59 ) ) ) {
V_26 = - V_44 ;
goto V_66;
}
F_13 ( & V_5 -> V_32 ) ;
F_34 ( V_2 ) ;
break;
V_66:
F_2 ( & ( V_5 -> V_8 ) , V_7 ) ;
F_35 ( V_61 , & ( V_5 -> V_9 ) ) ;
F_7 ( & ( V_5 -> V_8 ) , V_7 ) ;
F_13 ( & V_5 -> V_32 ) ;
break;
V_63:
F_13 ( & V_5 -> V_32 ) ;
break;
}
case V_68 :
{
struct V_69 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_36 ( V_5 -> V_30 , V_70 . V_45 , V_70 . V_46 ,
V_71 ) ;
break;
}
case V_72 :
{
struct V_69 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_37 ( V_5 -> V_30 , V_70 . V_45 , V_70 . V_46 ,
V_71 ) ;
break;
}
case V_73 :
{
struct V_74 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_36 ( V_5 -> V_30 , V_70 . V_45 , V_70 . V_46 ,
V_70 . V_75 ) ;
break;
}
case V_76 :
{
struct V_74 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_37 ( V_5 -> V_30 , V_70 . V_45 , V_70 . V_46 ,
V_70 . V_75 ) ;
break;
}
case V_77 :
{
int V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_38 ( V_5 -> V_30 , V_70 ) ;
break;
}
case V_78 :
{
unsigned int V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_39 ( V_5 -> V_30 , 0 , V_70 ) ;
break;
}
case V_79 :
{
unsigned int V_70 ;
unsigned char V_80 ;
V_26 = F_40 ( V_5 -> V_30 , 0 , & V_80 ) ;
if ( V_26 )
break;
V_70 = V_80 ;
if ( F_33 ( V_52 , & V_70 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
break;
}
case V_81 :
{
unsigned int V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_41 ( V_5 -> V_30 , 0 , V_70 ) ;
break;
}
case V_82 :
{
unsigned int V_70 ;
unsigned char V_80 ;
V_26 = F_42 ( V_5 -> V_30 , 0 , & V_80 ) ;
if ( V_26 )
break;
V_70 = V_80 ;
if ( F_33 ( V_52 , & V_70 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
break;
}
case V_83 :
{
struct V_84 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
return F_39 ( V_5 -> V_30 , V_70 . V_85 , V_70 . V_86 ) ;
break;
}
case V_87 :
{
struct V_84 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_40 ( V_5 -> V_30 , V_70 . V_85 , & V_70 . V_86 ) ;
if ( V_26 )
break;
if ( F_33 ( V_52 , & V_70 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
break;
}
case V_88 :
{
struct V_84 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_41 ( V_5 -> V_30 , V_70 . V_85 , V_70 . V_86 ) ;
break;
}
case V_89 :
{
struct V_84 V_70 ;
if ( F_26 ( & V_70 , V_52 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_42 ( V_5 -> V_30 , V_70 . V_85 , & V_70 . V_86 ) ;
if ( V_26 )
break;
if ( F_33 ( V_52 , & V_70 , sizeof( V_70 ) ) ) {
V_26 = - V_44 ;
break;
}
break;
}
case V_90 :
{
struct V_91 V_92 ;
if ( F_26 ( & V_92 , V_52 , sizeof( V_92 ) ) ) {
V_26 = - V_44 ;
break;
}
V_5 -> V_33 = V_92 . V_37 ;
V_5 -> V_34 = V_92 . V_38 ;
V_26 = 0 ;
break;
}
case V_93 :
{
struct V_91 V_92 ;
V_92 . V_37 = V_5 -> V_33 ;
V_92 . V_38 = V_5 -> V_34 ;
if ( F_33 ( V_52 , & V_92 , sizeof( V_92 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = 0 ;
break;
}
case V_94 :
{
int V_95 ;
V_95 = F_43 ( V_5 -> V_30 ) ;
if ( F_33 ( V_52 , & V_95 , sizeof( V_95 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = 0 ;
break;
}
case V_96 :
{
int V_95 ;
if ( F_26 ( & V_95 , V_52 , sizeof( V_95 ) ) ) {
V_26 = - V_44 ;
break;
}
V_26 = F_44 ( V_5 -> V_30 , V_95 ) ;
break;
}
}
return V_26 ;
}
static long F_45 ( struct V_15 * V_15 ,
unsigned int V_46 ,
unsigned long V_48 )
{
int V_97 ;
F_11 ( & V_23 ) ;
V_97 = F_29 ( V_15 , V_46 , V_48 ) ;
F_13 ( & V_23 ) ;
return V_97 ;
}
static long F_46 ( struct V_98 * V_99 ,
struct V_100 T_3 * V_101 )
{
T_4 V_102 ;
if ( ! F_47 ( V_103 , V_101 , sizeof( * V_101 ) ) ||
F_48 ( V_99 -> V_45 , & V_101 -> V_45 ) ||
F_48 ( V_99 -> V_46 , & V_101 -> V_46 ) ||
F_48 ( V_99 -> V_47 , & V_101 -> V_47 ) ||
F_48 ( V_102 , & V_101 -> V_48 ) )
return - V_44 ;
V_99 -> V_48 = F_49 ( V_102 ) ;
return 0 ;
}
static long F_50 ( struct V_98 * V_99 ,
struct V_100 T_3 * V_101 )
{
if ( ! F_47 ( V_104 , V_101 , sizeof( * V_101 ) ) ||
F_51 ( V_99 -> V_45 , & V_101 -> V_45 ) ||
F_51 ( V_99 -> V_46 , & V_101 -> V_46 ) ||
F_51 ( V_99 -> V_47 , & V_101 -> V_47 ) )
return - V_44 ;
return 0 ;
}
static long F_52 ( struct V_35 * V_99 ,
struct V_105 T_3 * V_101 )
{
T_4 V_102 ;
if ( ! F_47 ( V_103 , V_101 , sizeof( * V_101 ) ) ||
F_48 ( V_102 , & V_101 -> V_40 ) ||
F_48 ( V_99 -> V_42 , & V_101 -> V_42 ) ||
F_48 ( V_99 -> V_51 , & V_101 -> V_51 ) ||
F_46 ( & V_99 -> V_2 , & V_101 -> V_2 ) )
return - V_44 ;
V_99 -> V_40 = F_49 ( V_102 ) ;
return 0 ;
}
static long F_53 ( struct V_55 * V_99 ,
struct V_106 T_3 * V_101 )
{
if ( ! F_47 ( V_103 , V_101 , sizeof( * V_101 ) ) ||
F_52 ( & V_99 -> V_36 , & V_101 -> V_36 ) ||
F_48 ( V_99 -> V_37 , & V_101 -> V_37 ) ||
F_48 ( V_99 -> V_38 , & V_101 -> V_38 ) )
return - V_44 ;
return 0 ;
}
static long F_54 ( struct V_58 * V_99 ,
struct V_107 T_3 * V_101 )
{
T_4 V_102 ;
if ( ! F_47 ( V_103 , V_101 , sizeof( * V_101 ) ) ||
F_48 ( V_99 -> V_67 , & V_101 -> V_67 ) ||
F_48 ( V_102 , & V_101 -> V_40 ) ||
F_48 ( V_99 -> V_42 , & V_101 -> V_42 ) ||
F_48 ( V_99 -> V_51 , & V_101 -> V_51 ) ||
F_46 ( & V_99 -> V_2 , & V_101 -> V_2 ) )
return - V_44 ;
V_99 -> V_40 = F_49 ( V_102 ) ;
return 0 ;
}
static long F_55 ( struct V_58 * V_99 ,
struct V_107 T_3 * V_101 )
{
if ( ! F_47 ( V_104 , V_101 , sizeof( * V_101 ) ) ||
F_51 ( V_99 -> V_67 , & V_101 -> V_67 ) ||
F_51 ( V_99 -> V_42 , & V_101 -> V_42 ) ||
F_51 ( V_99 -> V_51 , & V_101 -> V_51 ) ||
F_50 ( & V_99 -> V_2 , & V_101 -> V_2 ) )
return - V_44 ;
return 0 ;
}
static long F_56 ( struct V_15 * V_108 , unsigned int V_46 ,
unsigned long V_52 )
{
int V_109 ;
struct V_4 * V_5 = V_108 -> V_16 ;
switch( V_46 ) {
case V_110 :
{
struct V_35 V_111 ;
if ( F_52 ( & V_111 , F_49 ( V_52 ) ) )
return - V_44 ;
return F_25 ( V_5 -> V_30 , & V_111 ,
V_5 -> V_33 ,
V_5 -> V_34 ) ;
}
case V_112 :
{
struct V_55 V_113 ;
if ( F_53 ( & V_113 , F_49 ( V_52 ) ) )
return - V_44 ;
return F_25 ( V_5 -> V_30 , & V_113 . V_36 ,
V_113 . V_37 , V_113 . V_38 ) ;
}
case V_114 :
case V_115 :
{
struct V_58 T_3 * V_116 ;
struct V_58 V_117 ;
if ( F_54 ( & V_117 , F_49 ( V_52 ) ) )
return - V_44 ;
V_116 = F_57 ( sizeof( V_117 ) ) ;
if ( F_33 ( V_116 , & V_117 , sizeof( V_117 ) ) )
return - V_44 ;
V_109 = F_29 ( V_108 ,
( ( V_46 == V_114 )
? V_56
: V_57 ) ,
( unsigned long ) V_116 ) ;
if ( V_109 != 0 )
return V_109 ;
if ( F_26 ( & V_117 , V_116 , sizeof( V_117 ) ) )
return - V_44 ;
if ( F_55 ( & V_117 , F_49 ( V_52 ) ) )
return - V_44 ;
return V_109 ;
}
default:
return F_29 ( V_108 , V_46 , V_52 ) ;
}
}
static void F_58 ( int V_25 , struct V_118 * V_118 )
{
T_5 V_119 = F_59 ( V_120 , V_25 ) ;
struct V_121 * V_61 ;
V_61 = F_16 ( sizeof( * V_61 ) , V_27 ) ;
if ( ! V_61 ) {
F_60 ( V_122 L_1
L_2 ) ;
return;
}
V_61 -> V_119 = V_119 ;
F_11 ( & V_123 ) ;
F_61 ( V_124 , V_118 , V_119 , NULL , L_3 , V_25 ) ;
F_35 ( & V_61 -> V_10 , & V_125 ) ;
F_13 ( & V_123 ) ;
}
static void F_62 ( int V_25 )
{
T_5 V_119 = F_59 ( V_120 , V_25 ) ;
struct V_121 * V_61 ;
F_11 ( & V_123 ) ;
F_63 (entry, &reg_list, link) {
if ( V_61 -> V_119 == V_119 ) {
F_31 ( & V_61 -> V_10 ) ;
F_18 ( V_61 ) ;
break;
}
}
F_64 ( V_124 , V_119 ) ;
F_13 ( & V_123 ) ;
}
static int T_6 F_65 ( void )
{
int V_26 ;
if ( V_120 < 0 )
return - V_43 ;
F_60 ( V_126 L_4 ) ;
V_124 = F_66 ( V_127 , L_5 ) ;
if ( F_67 ( V_124 ) ) {
F_60 ( V_122 L_6 ) ;
return F_68 ( V_124 ) ;
}
V_26 = F_69 ( V_120 , V_128 , & V_129 ) ;
if ( V_26 < 0 ) {
F_70 ( V_124 ) ;
F_60 ( V_122 L_7 , V_120 ) ;
return V_26 ;
}
if ( V_120 == 0 ) {
V_120 = V_26 ;
}
V_26 = F_71 ( & V_130 ) ;
if ( V_26 ) {
F_72 ( V_120 , V_128 ) ;
F_70 ( V_124 ) ;
F_60 ( V_131 L_8 ) ;
return V_26 ;
}
return 0 ;
}
static void T_7 F_73 ( void )
{
struct V_121 * V_61 , * V_132 ;
F_11 ( & V_123 ) ;
F_74 (entry, entry2, &reg_list, link) {
F_31 ( & V_61 -> V_10 ) ;
F_64 ( V_124 , V_61 -> V_119 ) ;
F_18 ( V_61 ) ;
}
F_13 ( & V_123 ) ;
F_70 ( V_124 ) ;
F_75 ( & V_130 ) ;
F_72 ( V_120 , V_128 ) ;
}
