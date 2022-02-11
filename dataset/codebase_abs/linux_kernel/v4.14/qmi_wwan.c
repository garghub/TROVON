static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! ( V_4 -> V_5 -> V_6 & V_7 ) )
return - V_8 ;
if ( F_3 ( V_5 ) )
F_4 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_11 = V_10 -> V_11 ;
struct V_12 * V_13 ;
V_13 = F_8 ( V_10 , sizeof( struct V_12 ) ) ;
V_13 -> V_14 = 0 ;
V_13 -> V_15 = V_4 -> V_15 ;
V_13 -> V_16 = F_9 ( V_11 ) ;
V_10 -> V_2 = V_4 -> V_5 ;
return F_10 ( V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_17 = NULL ;
V_2 -> type = V_18 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_6 = V_21 | V_22 | V_23 ;
V_2 -> V_24 = & V_25 ;
V_2 -> V_26 = true ;
}
static struct V_1 * F_12 ( struct V_27 * V_2 , T_2 V_15 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
F_13 () ;
F_14 (dev->net, ldev, iter) {
V_4 = F_2 ( V_30 ) ;
if ( V_4 -> V_15 == V_15 ) {
F_15 () ;
return V_30 ;
}
}
F_15 () ;
return NULL ;
}
static bool F_16 ( struct V_27 * V_2 )
{
return ! F_17 ( & V_2 -> V_31 -> V_32 . V_33 ) ;
}
static int F_18 ( struct V_27 * V_2 , struct V_9 * V_10 )
{
unsigned int V_11 , V_34 = sizeof( struct V_12 ) ;
struct V_12 * V_13 ;
struct V_1 * V_31 ;
struct V_9 * V_35 ;
while ( V_34 < V_10 -> V_11 ) {
V_13 = (struct V_12 * ) V_10 -> V_36 ;
V_11 = F_19 ( V_13 -> V_16 ) ;
if ( V_34 + V_11 > V_10 -> V_11 )
return 0 ;
if ( V_13 -> V_14 & 0x80 )
goto V_37;
V_31 = F_12 ( V_2 , V_13 -> V_15 ) ;
if ( ! V_31 )
goto V_37;
V_35 = F_20 ( V_31 , V_11 ) ;
if ( ! V_35 )
return 0 ;
V_35 -> V_2 = V_31 ;
switch ( V_10 -> V_36 [ V_34 ] & 0xf0 ) {
case 0x40 :
V_35 -> V_38 = F_21 ( V_39 ) ;
break;
case 0x60 :
V_35 -> V_38 = F_21 ( V_40 ) ;
break;
default:
goto V_37;
}
F_22 ( V_35 , V_10 -> V_36 + V_34 , V_11 ) ;
if ( F_23 ( V_35 ) != V_41 )
return 0 ;
V_37:
V_34 += V_11 + sizeof( struct V_12 ) ;
}
return 1 ;
}
static int F_24 ( struct V_1 * V_5 , T_2 V_15 )
{
struct V_1 * V_42 ;
struct V_3 * V_4 ;
int V_43 ;
V_42 = F_25 ( sizeof( struct V_3 ) ,
L_1 , V_44 , F_11 ) ;
if ( ! V_42 )
return - V_45 ;
F_26 ( V_42 , F_27 ( V_5 ) ) ;
V_4 = F_2 ( V_42 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_5 = V_5 ;
V_43 = F_28 ( V_42 ) ;
if ( V_43 < 0 )
goto V_46;
F_29 ( V_5 ) ;
V_43 = F_30 ( V_5 , V_42 ) ;
if ( V_43 )
goto V_47;
F_31 ( V_5 , V_42 ) ;
return 0 ;
V_47:
F_32 ( V_42 ) ;
F_33 ( V_5 ) ;
V_46:
F_34 ( V_42 ) ;
return V_43 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_36 ( V_5 , V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_5 ) ;
}
static void F_37 ( struct V_1 * V_31 )
{
struct V_27 * V_2 = F_2 ( V_31 ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
if ( V_49 -> V_6 & V_50 ) {
V_31 -> V_17 = NULL ;
V_31 -> type = V_18 ;
V_31 -> V_19 = 0 ;
V_31 -> V_20 = 0 ;
V_31 -> V_6 = V_21 | V_22 | V_23 ;
F_38 ( V_31 , L_2 ) ;
} else if ( ! V_31 -> V_17 ) {
F_39 ( V_31 ) ;
F_38 ( V_31 , L_3 ) ;
}
F_40 ( V_31 , V_31 -> V_51 ) ;
}
static T_3 F_41 ( struct V_52 * V_53 , struct V_54 * V_55 , char * V_56 )
{
struct V_27 * V_2 = F_2 ( F_42 ( V_53 ) ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
return sprintf ( V_56 , L_4 , V_49 -> V_6 & V_50 ? 'Y' : 'N' ) ;
}
static T_3 F_43 ( struct V_52 * V_53 , struct V_54 * V_55 , const char * V_56 , T_4 V_11 )
{
struct V_27 * V_2 = F_2 ( F_42 ( V_53 ) ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
bool V_57 ;
int V_58 ;
if ( F_44 ( V_56 , & V_57 ) )
return - V_59 ;
if ( V_57 == ( V_49 -> V_6 & V_50 ) )
return V_11 ;
if ( ! F_45 () )
return F_46 () ;
if ( F_47 ( V_2 -> V_31 ) ) {
F_48 ( V_2 -> V_31 , L_5 ) ;
V_58 = - V_60 ;
goto V_43;
}
V_58 = F_49 ( V_61 , V_2 -> V_31 ) ;
V_58 = F_50 ( V_58 ) ;
if ( V_58 ) {
F_48 ( V_2 -> V_31 , L_6 ) ;
goto V_43;
}
if ( V_57 )
V_49 -> V_6 |= V_50 ;
else
V_49 -> V_6 &= ~ V_50 ;
F_37 ( V_2 -> V_31 ) ;
F_49 ( V_62 , V_2 -> V_31 ) ;
V_58 = V_11 ;
V_43:
F_51 () ;
return V_58 ;
}
static T_3 F_52 ( struct V_52 * V_53 , struct V_54 * V_55 , char * V_56 )
{
struct V_1 * V_2 = F_42 ( V_53 ) ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
T_3 V_63 = 0 ;
F_13 () ;
F_14 (dev, ldev, iter) {
V_4 = F_2 ( V_30 ) ;
V_63 += F_53 ( & V_56 [ V_63 ] , V_64 - V_63 ,
L_7 , V_4 -> V_15 ) ;
}
F_15 () ;
return V_63 ;
}
static T_3 F_54 ( struct V_52 * V_53 , struct V_54 * V_55 , const char * V_56 , T_4 V_11 )
{
struct V_27 * V_2 = F_2 ( F_42 ( V_53 ) ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
T_2 V_15 ;
int V_58 ;
if ( F_55 ( V_56 , 0 , & V_15 ) )
return - V_59 ;
if ( V_15 < 1 || V_15 > 0x7f )
return - V_59 ;
if ( ! F_45 () )
return F_46 () ;
if ( F_12 ( V_2 , V_15 ) ) {
F_48 ( V_2 -> V_31 , L_8 ) ;
V_58 = - V_59 ;
goto V_43;
}
if ( F_47 ( V_2 -> V_31 ) ) {
F_48 ( V_2 -> V_31 , L_5 ) ;
V_58 = - V_60 ;
goto V_43;
}
V_58 = F_24 ( V_2 -> V_31 , V_15 ) ;
if ( ! V_58 ) {
V_49 -> V_6 |= V_65 ;
V_58 = V_11 ;
}
V_43:
F_51 () ;
return V_58 ;
}
static T_3 F_56 ( struct V_52 * V_53 , struct V_54 * V_55 , char * V_56 )
{
return F_52 ( V_53 , V_55 , V_56 ) ;
}
static T_3 F_57 ( struct V_52 * V_53 , struct V_54 * V_55 , const char * V_56 , T_4 V_11 )
{
struct V_27 * V_2 = F_2 ( F_42 ( V_53 ) ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
struct V_1 * V_66 ;
T_2 V_15 ;
int V_58 = 0 ;
if ( F_55 ( V_56 , 0 , & V_15 ) )
return - V_59 ;
if ( ! F_45 () )
return F_46 () ;
if ( F_47 ( V_2 -> V_31 ) ) {
F_48 ( V_2 -> V_31 , L_5 ) ;
V_58 = - V_60 ;
goto V_43;
}
V_66 = F_12 ( V_2 , V_15 ) ;
if ( ! V_66 ) {
F_48 ( V_2 -> V_31 , L_9 ) ;
V_58 = - V_59 ;
goto V_43;
}
F_35 ( V_66 ) ;
if ( ! F_16 ( V_2 ) )
V_49 -> V_6 &= ~ V_65 ;
V_58 = V_11 ;
V_43:
F_51 () ;
return V_58 ;
}
static int F_58 ( struct V_27 * V_2 , struct V_9 * V_10 )
{
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
bool V_67 = V_49 -> V_6 & V_50 ;
T_5 V_68 ;
if ( V_10 -> V_11 < V_2 -> V_31 -> V_19 )
return 0 ;
if ( V_49 -> V_6 & V_65 )
return F_18 ( V_2 , V_10 ) ;
switch ( V_10 -> V_36 [ 0 ] & 0xf0 ) {
case 0x40 :
V_68 = F_21 ( V_39 ) ;
break;
case 0x60 :
V_68 = F_21 ( V_40 ) ;
break;
case 0x00 :
if ( V_67 )
return 0 ;
if ( F_59 ( V_10 -> V_36 ) )
return 1 ;
F_60 ( V_10 ) ;
goto V_69;
default:
if ( V_67 )
return 0 ;
return 1 ;
}
if ( V_67 ) {
F_60 ( V_10 ) ;
V_10 -> V_2 = V_2 -> V_31 ;
V_10 -> V_38 = V_68 ;
return 1 ;
}
if ( F_61 ( V_10 ) < V_70 )
return 0 ;
F_8 ( V_10 , V_70 ) ;
F_60 ( V_10 ) ;
F_62 ( V_10 ) -> V_71 = V_68 ;
F_63 ( F_62 ( V_10 ) -> V_72 ) ;
V_69:
memcpy ( F_62 ( V_10 ) -> V_73 , V_2 -> V_31 -> V_74 , V_75 ) ;
return 1 ;
}
static bool F_64 ( const char * V_36 )
{
return ( V_36 [ 0 ] & 0xd0 ) == 0x40 ;
}
static int F_65 ( struct V_1 * V_2 , void * V_76 )
{
int V_58 ;
struct V_77 * V_78 = V_76 ;
V_58 = F_66 ( V_2 , V_76 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( F_64 ( V_78 -> V_79 ) )
return - V_80 ;
F_67 ( V_2 , V_76 ) ;
return 0 ;
}
static int F_68 ( struct V_27 * V_2 , int V_81 )
{
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
int V_82 ;
F_69 ( & V_2 -> V_83 -> V_2 , L_10 , V_84 ,
F_70 ( & V_49 -> V_85 ) , V_81 ) ;
if ( ( V_81 && F_71 ( 1 , & V_49 -> V_85 ) == 1 ) ||
( ! V_81 && F_72 ( & V_49 -> V_85 ) ) ) {
V_82 = F_73 ( V_2 -> V_83 ) ;
V_2 -> V_83 -> V_86 = V_81 ;
if ( ! V_82 )
F_74 ( V_2 -> V_83 ) ;
}
return 0 ;
}
static int F_75 ( struct V_87 * V_83 , int V_81 )
{
struct V_27 * V_2 = F_76 ( V_83 ) ;
if ( ! V_2 )
return 0 ;
return F_68 ( V_2 , V_81 ) ;
}
static int F_77 ( struct V_27 * V_2 )
{
int V_82 ;
struct V_88 * V_89 = NULL ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
V_82 = F_78 ( V_2 , V_49 -> V_36 ) ;
if ( V_82 < 0 )
goto V_43;
if ( V_49 -> V_90 != V_49 -> V_36 )
V_2 -> V_91 = & V_49 -> V_90 -> V_92 -> V_93 [ 0 ] ;
if ( ! V_2 -> V_91 ) {
V_82 = - V_59 ;
goto V_43;
}
F_79 ( & V_49 -> V_85 , 0 ) ;
V_89 = F_80 ( V_49 -> V_90 , & V_2 -> V_91 -> V_94 ,
4096 , & F_75 ) ;
if ( F_81 ( V_89 ) ) {
F_82 ( & V_49 -> V_90 -> V_2 , L_11 ) ;
V_82 = F_83 ( V_89 ) ;
goto V_43;
}
V_2 -> V_91 = NULL ;
V_49 -> V_89 = V_89 ;
V_43:
return V_82 ;
}
static int F_84 ( struct V_27 * V_2 , bool V_81 )
{
T_2 V_83 = V_2 -> V_83 -> V_92 -> V_94 . V_95 ;
return F_85 ( V_2 , V_96 ,
V_97 | V_98 | V_99 ,
V_81 ? 0x01 : 0x00 , V_83 , NULL , 0 ) ;
}
static int F_86 ( struct V_27 * V_2 , struct V_87 * V_83 )
{
int V_91 = - 1 ;
T_2 * V_56 = V_83 -> V_92 -> V_100 ;
int V_11 = V_83 -> V_92 -> V_101 ;
struct V_102 * V_94 = & V_83 -> V_92 -> V_94 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_88 * V_107 = F_87 ( V_83 ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
struct V_108 V_13 ;
F_88 ( ( sizeof( ( (struct V_27 * ) 0 ) -> V_36 ) <
sizeof( struct V_48 ) ) ) ;
V_49 -> V_90 = V_83 ;
V_49 -> V_36 = V_83 ;
F_89 ( & V_13 , V_83 , V_56 , V_11 ) ;
V_104 = V_13 . V_103 ;
V_106 = V_13 . V_105 ;
if ( V_104 ) {
V_49 -> V_36 = F_90 ( V_2 -> V_109 ,
V_104 -> V_110 ) ;
if ( V_94 -> V_95 != V_104 -> V_111 ||
! V_49 -> V_36 ) {
F_82 ( & V_83 -> V_2 ,
L_12 ,
V_104 -> V_111 ,
V_104 -> V_110 ) ;
V_104 = NULL ;
V_49 -> V_36 = V_83 ;
}
}
if ( V_106 && V_106 -> V_112 ) {
V_2 -> V_113 = F_91 ( V_106 -> V_112 ) ;
F_92 ( V_2 , V_106 -> V_114 ) ;
}
if ( V_49 -> V_90 != V_49 -> V_36 ) {
V_91 = F_93 ( V_107 , V_49 -> V_36 , V_2 ) ;
if ( V_91 < 0 )
goto V_43;
}
V_91 = F_77 ( V_2 ) ;
if ( V_91 < 0 && V_49 -> V_90 != V_49 -> V_36 ) {
F_94 ( V_49 -> V_36 , NULL ) ;
F_95 ( V_107 , V_49 -> V_36 ) ;
}
if ( V_2 -> V_115 -> V_36 & V_116 ||
F_91 ( V_2 -> V_109 -> V_117 . V_118 ) >= 0x0201 ) {
F_68 ( V_2 , 1 ) ;
F_84 ( V_2 , true ) ;
}
if ( F_96 ( V_2 -> V_31 -> V_74 , V_119 ) ||
F_96 ( V_2 -> V_31 -> V_74 , V_120 ) )
F_97 ( V_2 -> V_31 ) ;
if ( F_64 ( V_2 -> V_31 -> V_74 ) ) {
V_2 -> V_31 -> V_74 [ 0 ] |= 0x02 ;
V_2 -> V_31 -> V_74 [ 0 ] &= 0xbf ;
}
V_2 -> V_31 -> V_24 = & V_121 ;
V_2 -> V_31 -> V_122 [ 0 ] = & V_123 ;
V_43:
return V_91 ;
}
static void F_98 ( struct V_27 * V_2 , struct V_87 * V_83 )
{
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
struct V_88 * V_107 = F_87 ( V_83 ) ;
struct V_87 * V_124 ;
if ( V_49 -> V_89 && V_49 -> V_89 -> V_125 )
V_49 -> V_89 -> V_125 ( V_49 -> V_90 ) ;
if ( F_91 ( V_2 -> V_109 -> V_117 . V_118 ) >= 0x0201 ) {
F_84 ( V_2 , false ) ;
F_68 ( V_2 , 0 ) ;
}
if ( V_83 == V_49 -> V_90 )
V_124 = V_49 -> V_36 ;
else
V_124 = V_49 -> V_90 ;
if ( V_124 && V_83 != V_124 ) {
F_94 ( V_124 , NULL ) ;
F_95 ( V_107 , V_124 ) ;
}
V_49 -> V_89 = NULL ;
V_49 -> V_36 = NULL ;
V_49 -> V_90 = NULL ;
}
static int F_99 ( struct V_87 * V_83 , T_6 V_126 )
{
struct V_27 * V_2 = F_76 ( V_83 ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
int V_58 ;
V_58 = F_100 ( V_83 , V_126 ) ;
if ( V_58 < 0 )
goto V_43;
if ( V_83 == V_49 -> V_90 && V_49 -> V_89 &&
V_49 -> V_89 -> V_127 )
V_58 = V_49 -> V_89 -> V_127 ( V_83 , V_126 ) ;
if ( V_58 < 0 )
F_101 ( V_83 ) ;
V_43:
return V_58 ;
}
static int F_102 ( struct V_87 * V_83 )
{
struct V_27 * V_2 = F_76 ( V_83 ) ;
struct V_48 * V_49 = ( void * ) & V_2 -> V_36 ;
int V_58 = 0 ;
bool V_128 = ( V_83 == V_49 -> V_90 && V_49 -> V_89 &&
V_49 -> V_89 -> V_129 ) ;
if ( V_128 )
V_58 = V_49 -> V_89 -> V_129 ( V_83 ) ;
if ( V_58 < 0 )
goto V_43;
V_58 = F_101 ( V_83 ) ;
if ( V_58 < 0 && V_128 )
V_49 -> V_89 -> V_127 ( V_83 , V_130 ) ;
V_43:
return V_58 ;
}
static bool F_103 ( struct V_87 * V_83 )
{
struct V_131 * V_2 = F_104 ( V_83 ) ;
if ( V_2 -> V_132 &&
F_91 ( V_2 -> V_117 . V_133 ) == 0x05c6 &&
F_91 ( V_2 -> V_117 . V_134 ) == 0x9215 &&
V_2 -> V_132 -> V_94 . V_135 == 5 )
return true ;
return false ;
}
static int F_105 ( struct V_87 * V_83 ,
const struct V_136 * V_137 )
{
struct V_136 * V_138 = (struct V_136 * ) V_137 ;
struct V_102 * V_94 = & V_83 -> V_92 -> V_94 ;
if ( ! V_138 -> V_115 ) {
F_69 ( & V_83 -> V_2 , L_13 ) ;
V_138 -> V_115 = ( unsigned long ) & V_139 ;
}
if ( F_103 ( V_83 ) && V_94 -> V_95 == 0 ) {
F_69 ( & V_83 -> V_2 , L_14 ) ;
return - V_140 ;
}
return F_106 ( V_83 , V_138 ) ;
}
static void F_107 ( struct V_87 * V_83 )
{
struct V_27 * V_2 = F_76 ( V_83 ) ;
struct V_48 * V_49 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
if ( ! V_2 )
return;
V_49 = ( void * ) & V_2 -> V_36 ;
if ( V_49 -> V_6 & V_65 ) {
if ( ! F_45 () ) {
F_46 () ;
return;
}
F_13 () ;
F_14 (dev->net, ldev, iter)
F_35 ( V_30 ) ;
F_15 () ;
F_51 () ;
V_49 -> V_6 &= ~ V_65 ;
}
F_108 ( V_83 ) ;
}
