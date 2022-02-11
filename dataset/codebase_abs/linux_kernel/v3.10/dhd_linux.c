char * F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 || V_3 >= V_4 ) {
F_2 ( L_1 , V_3 ) ;
return L_2 ;
}
if ( V_2 -> V_5 [ V_3 ] == NULL ) {
F_2 ( L_3 , V_3 ) ;
return L_4 ;
}
if ( V_2 -> V_5 [ V_3 ] -> V_6 )
return V_2 -> V_5 [ V_3 ] -> V_6 -> V_7 ;
return L_5 ;
}
static void F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_6 ;
struct V_13 * V_14 ;
T_1 V_15 , V_16 ;
T_2 V_17 ;
char * V_18 , * V_19 ;
T_1 V_20 ;
T_3 V_21 ;
V_11 = F_4 ( V_9 , struct V_10 , V_22 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
V_6 = V_11 -> V_6 ;
V_15 = ( V_6 -> V_25 & V_26 ) ? true : false ;
V_16 = F_6 ( V_6 ) ;
V_20 = sizeof( V_16 ) + ( V_16 * V_27 ) ;
V_18 = F_7 ( V_20 , V_28 ) ;
if ( ! V_18 )
return;
V_19 = V_18 ;
V_17 = F_8 ( V_16 ) ;
memcpy ( V_19 , & V_17 , sizeof( V_17 ) ) ;
V_19 += sizeof( V_17 ) ;
F_9 (ha, ndev) {
if ( ! V_16 )
break;
memcpy ( V_19 , V_14 -> V_29 , V_27 ) ;
V_19 += V_27 ;
V_16 -- ;
}
V_21 = F_10 ( V_11 , L_7 , V_18 , V_20 ) ;
if ( V_21 < 0 ) {
F_2 ( L_8 , V_21 ) ;
V_15 = V_16 ? true : V_15 ;
}
F_11 ( V_18 ) ;
V_21 = F_12 ( V_11 , L_9 , V_15 ) ;
if ( V_21 < 0 )
F_2 ( L_10 , V_21 ) ;
V_15 = ( V_6 -> V_25 & V_30 ) ? true : false ;
V_21 = F_13 ( V_11 , V_31 , V_15 ) ;
if ( V_21 < 0 )
F_2 ( L_11 ,
V_21 ) ;
}
static void
F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
T_3 V_21 ;
V_11 = F_4 ( V_9 , struct V_10 , V_32 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
V_21 = F_10 ( V_11 , L_12 , V_11 -> V_33 ,
V_27 ) ;
if ( V_21 < 0 ) {
F_2 ( L_13 , V_21 ) ;
} else {
F_5 ( V_23 , L_14 ,
V_11 -> V_33 ) ;
memcpy ( V_11 -> V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
}
}
static int F_15 ( struct V_12 * V_6 , void * V_29 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_35 * V_36 = (struct V_35 * ) V_29 ;
memcpy ( & V_11 -> V_33 , V_36 -> V_37 , V_27 ) ;
F_17 ( & V_11 -> V_32 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_17 ( & V_11 -> V_22 ) ;
}
static T_4 F_19 ( struct V_38 * V_39 ,
struct V_12 * V_6 )
{
int V_40 ;
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_41 * V_42 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( V_2 -> V_43 -> V_44 != V_45 ) {
F_2 ( L_15 , V_2 -> V_43 -> V_44 ) ;
F_20 ( V_6 ) ;
F_21 ( V_39 ) ;
V_40 = - V_46 ;
goto V_47;
}
if ( ! V_2 -> V_5 [ V_11 -> V_24 ] ) {
F_2 ( L_16 , V_11 -> V_24 ) ;
F_20 ( V_6 ) ;
F_21 ( V_39 ) ;
V_40 = - V_46 ;
goto V_47;
}
if ( F_22 ( V_39 ) < V_2 -> V_48 ) {
struct V_38 * V_49 ;
F_5 ( V_50 , L_17 ,
F_1 ( V_2 , V_11 -> V_24 ) ) ;
V_2 -> V_43 -> V_51 ++ ;
V_49 = F_23 ( V_39 , V_2 -> V_48 ) ;
F_21 ( V_39 ) ;
V_39 = V_49 ;
if ( V_39 == NULL ) {
F_2 ( L_18 ,
F_1 ( V_2 , V_11 -> V_24 ) ) ;
V_40 = - V_52 ;
goto V_47;
}
}
if ( V_39 -> V_53 < sizeof( * V_42 ) ) {
V_40 = - V_54 ;
F_21 ( V_39 ) ;
goto V_47;
}
V_40 = F_24 ( V_11 , V_39 ) ;
V_47:
if ( V_40 ) {
V_11 -> V_55 . V_56 ++ ;
} else {
V_11 -> V_55 . V_57 ++ ;
V_11 -> V_55 . V_58 += V_39 -> V_53 ;
}
return V_59 ;
}
void F_25 ( struct V_10 * V_11 ,
enum V_60 V_61 , bool V_44 )
{
if ( ! V_11 )
return;
F_5 ( V_23 , L_19 ,
V_11 -> V_24 , V_11 -> V_62 , V_61 , V_44 ) ;
if ( V_44 ) {
if ( ! V_11 -> V_62 )
F_20 ( V_11 -> V_6 ) ;
V_11 -> V_62 |= V_61 ;
} else {
V_11 -> V_62 &= ~ V_61 ;
if ( ! V_11 -> V_62 )
F_26 ( V_11 -> V_6 ) ;
}
}
void F_27 ( struct V_63 * V_64 , bool V_44 )
{
struct V_65 * V_43 = F_28 ( V_64 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
int V_66 ;
F_5 ( V_23 , L_20 ) ;
for ( V_66 = 0 ; V_66 < V_4 ; V_66 ++ )
F_25 ( V_2 -> V_5 [ V_66 ] ,
V_67 , V_44 ) ;
}
void F_29 ( struct V_63 * V_64 , struct V_68 * V_69 )
{
unsigned char * V_70 ;
T_5 V_53 ;
struct V_38 * V_39 , * V_71 ;
struct V_10 * V_11 ;
struct V_65 * V_43 = F_28 ( V_64 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
T_6 V_3 ;
int V_40 ;
F_5 ( V_23 , L_20 ) ;
F_30 (skb_list, skb, pnext) {
F_31 ( V_39 , V_69 ) ;
V_40 = F_32 ( V_2 , V_2 -> V_72 , & V_3 , V_39 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( V_40 || ! V_11 || ! V_11 -> V_6 ) {
if ( ( V_40 != - V_73 ) && V_11 )
V_11 -> V_55 . V_74 ++ ;
F_33 ( V_39 ) ;
continue;
}
V_70 = V_39 -> V_75 ;
V_53 = V_39 -> V_53 ;
V_39 -> V_64 = V_11 -> V_6 ;
V_39 -> V_76 = F_34 ( V_39 , V_39 -> V_64 ) ;
if ( V_39 -> V_77 == V_78 )
V_11 -> V_55 . V_79 ++ ;
V_39 -> V_75 = V_70 ;
V_39 -> V_53 = V_53 ;
F_35 ( V_39 , V_80 ) ;
F_36 ( V_2 , V_39 ) ;
if ( ! ( V_11 -> V_6 -> V_25 & V_81 ) ) {
F_33 ( V_39 ) ;
continue;
}
V_11 -> V_55 . V_82 += V_39 -> V_53 ;
V_11 -> V_55 . V_83 ++ ;
if ( F_37 () )
F_38 ( V_39 ) ;
else
F_39 ( V_39 ) ;
}
}
void F_40 ( struct V_1 * V_2 , struct V_38 * V_84 ,
bool V_85 )
{
struct V_10 * V_11 ;
struct V_41 * V_42 ;
T_6 V_3 ;
T_7 type ;
int V_86 ;
V_86 = F_32 ( V_2 , false , & V_3 , V_84 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( ! V_11 )
goto V_47;
if ( V_86 == 0 ) {
V_42 = (struct V_41 * ) ( V_84 -> V_75 ) ;
type = F_41 ( V_42 -> V_87 ) ;
if ( type == V_88 ) {
F_42 ( & V_11 -> V_89 ) ;
if ( F_43 ( & V_11 -> V_90 ) )
F_44 ( & V_11 -> V_90 ) ;
}
}
if ( ! V_85 )
V_11 -> V_55 . V_91 ++ ;
V_47:
F_33 ( V_84 ) ;
}
void F_45 ( struct V_63 * V_64 , struct V_38 * V_84 , bool V_85 )
{
struct V_65 * V_43 = F_28 ( V_64 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
if ( F_46 ( V_2 -> V_92 ) ) {
if ( ! V_85 )
F_47 ( V_2 -> V_92 , V_84 ) ;
} else {
F_40 ( V_2 , V_84 , V_85 ) ;
}
}
static struct V_93 * F_48 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
return & V_11 -> V_55 ;
}
static int F_49 ( struct V_10 * V_11 , T_1 V_94 )
{
T_3 V_21 ;
V_21 = F_12 ( V_11 , L_21 , V_94 ) ;
if ( V_21 < 0 ) {
F_2 ( L_22 , V_21 ) ;
return V_21 ;
}
V_21 = F_12 ( V_11 , L_23 , ( V_94 != 0 ) ) ;
if ( V_21 < 0 )
F_2 ( L_24 , V_21 ) ;
return V_21 ;
}
static void F_50 ( struct V_12 * V_6 ,
struct V_95 * V_96 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_51 ( V_96 -> V_97 , V_98 , sizeof( V_96 -> V_97 ) ) ;
snprintf ( V_96 -> V_99 , sizeof( V_96 -> V_99 ) , L_25 ,
V_2 -> V_100 ) ;
F_51 ( V_96 -> V_101 , F_52 ( V_2 -> V_43 -> V_64 ) ,
sizeof( V_96 -> V_101 ) ) ;
}
static int F_53 ( struct V_10 * V_11 , void T_8 * V_102 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_95 V_96 ;
char V_103 [ sizeof( V_96 . V_97 ) ] ;
T_1 V_104 ;
struct V_105 V_106 ;
T_1 V_107 , V_108 ;
int V_40 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( F_54 ( & V_104 , V_102 , sizeof( T_1 ) ) )
return - V_109 ;
switch ( V_104 ) {
case V_110 :
if ( F_54 ( & V_96 , V_102 , sizeof( V_96 ) ) )
return - V_109 ;
strncpy ( V_103 , V_96 . V_97 , sizeof( V_96 . V_97 ) ) ;
V_103 [ sizeof( V_96 . V_97 ) - 1 ] = '\0' ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_104 = V_104 ;
if ( strcmp ( V_103 , L_26 ) == 0 ) {
sprintf ( V_96 . V_97 , L_27 ) ;
strcpy ( V_96 . V_99 , V_111 ) ;
}
else
sprintf ( V_96 . V_97 , L_28 ) ;
sprintf ( V_96 . V_99 , L_25 , V_2 -> V_100 ) ;
if ( F_55 ( V_102 , & V_96 , sizeof( V_96 ) ) )
return - V_109 ;
F_5 ( V_23 , L_29 ,
( int ) sizeof( V_103 ) , V_103 , V_96 . V_97 ) ;
break;
case V_112 :
case V_113 :
V_40 = F_56 ( V_11 , L_21 , & V_107 ) ;
if ( V_40 < 0 )
return V_40 ;
V_108 =
( V_104 == V_113 ) ? V_114 : V_115 ;
V_106 . V_104 = V_104 ;
V_106 . V_75 = ( V_107 & V_108 ) ? 1 : 0 ;
if ( F_55 ( V_102 , & V_106 , sizeof( V_106 ) ) )
return - V_109 ;
break;
case V_116 :
case V_117 :
if ( F_54 ( & V_106 , V_102 , sizeof( V_106 ) ) )
return - V_109 ;
V_40 = F_56 ( V_11 , L_21 , & V_107 ) ;
if ( V_40 < 0 )
return V_40 ;
V_108 =
( V_104 == V_117 ) ? V_114 : V_115 ;
if ( V_106 . V_75 != 0 )
V_107 |= V_108 ;
else
V_107 &= ~ V_108 ;
V_40 = F_49 ( V_11 , V_107 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_104 == V_117 ) {
if ( V_106 . V_75 )
V_11 -> V_6 -> V_118 |= V_119 ;
else
V_11 -> V_6 -> V_118 &= ~ V_119 ;
}
break;
default:
return - V_120 ;
}
return 0 ;
}
static int F_57 ( struct V_12 * V_6 , struct V_121 * V_122 ,
int V_104 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_5 ( V_23 , L_30 , V_11 -> V_24 , V_104 ) ;
if ( ! V_2 -> V_5 [ V_11 -> V_24 ] )
return - 1 ;
if ( V_104 == V_123 )
return F_53 ( V_11 , V_122 -> V_124 ) ;
return - V_120 ;
}
static int F_58 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
F_59 ( V_6 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_65 * V_43 = V_2 -> V_43 ;
T_1 V_94 ;
T_3 V_40 = 0 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( V_43 -> V_44 != V_45 ) {
F_2 ( L_31 ) ;
return - V_125 ;
}
F_61 ( & V_11 -> V_89 , 0 ) ;
if ( F_56 ( V_11 , L_21 , & V_94 ) >= 0
&& ( V_94 & V_114 ) != 0 )
V_6 -> V_118 |= V_119 ;
else
V_6 -> V_118 &= ~ V_119 ;
F_62 ( V_6 ) ;
if ( F_63 ( V_6 ) ) {
F_2 ( L_32 ) ;
return - 1 ;
}
return V_40 ;
}
int F_64 ( struct V_10 * V_11 , bool V_126 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_6 ;
T_3 V_21 ;
F_5 ( V_23 , L_33 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_127 = & V_128 ;
V_6 -> V_129 = V_80 + V_2 -> V_48 ;
V_6 -> V_130 = & V_131 ;
V_2 -> V_132 = V_6 -> V_133 + V_6 -> V_129 +
V_2 -> V_48 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
F_65 ( & V_11 -> V_32 , F_14 ) ;
F_65 ( & V_11 -> V_22 , F_3 ) ;
if ( V_126 )
V_21 = F_66 ( V_6 ) ;
else
V_21 = F_67 ( V_6 ) ;
if ( V_21 != 0 ) {
F_2 ( L_34 ) ;
goto V_134;
}
F_5 ( V_50 , L_35 , V_6 -> V_7 ) ;
V_6 -> V_135 = V_136 ;
return 0 ;
V_134:
V_2 -> V_5 [ V_11 -> V_24 ] = NULL ;
V_6 -> V_127 = NULL ;
V_136 ( V_6 ) ;
return - V_137 ;
}
static int F_68 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_20 ) ;
return F_63 ( V_6 ) ;
}
static int F_69 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_20 ) ;
return F_59 ( V_6 ) ;
}
static int F_70 ( struct V_12 * V_6 ,
struct V_121 * V_122 , int V_104 )
{
F_5 ( V_23 , L_20 ) ;
return 0 ;
}
static T_4 F_71 ( struct V_38 * V_39 ,
struct V_12 * V_6 )
{
if ( V_39 )
F_72 ( V_39 ) ;
return V_59 ;
}
static int F_73 ( struct V_10 * V_11 )
{
struct V_12 * V_6 ;
F_5 ( V_23 , L_33 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_127 = & V_138 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
if ( F_67 ( V_6 ) != 0 ) {
F_2 ( L_36 ) ;
goto V_134;
}
F_5 ( V_50 , L_35 , V_6 -> V_7 ) ;
return 0 ;
V_134:
V_11 -> V_2 -> V_5 [ V_11 -> V_24 ] = NULL ;
V_6 -> V_127 = NULL ;
V_136 ( V_6 ) ;
return - V_137 ;
}
struct V_10 * F_74 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_3 ,
char * V_7 , T_6 * V_33 )
{
struct V_10 * V_11 ;
struct V_12 * V_6 ;
F_5 ( V_23 , L_37 , V_24 , V_3 ) ;
V_11 = V_2 -> V_5 [ V_24 ] ;
if ( V_11 ) {
F_2 ( L_38 ,
V_11 -> V_6 -> V_7 ) ;
if ( V_3 ) {
F_20 ( V_11 -> V_6 ) ;
F_75 ( V_11 -> V_6 ) ;
V_136 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_24 ] = NULL ;
} else {
F_2 ( L_39 ) ;
return F_76 ( - V_54 ) ;
}
}
if ( ! V_139 && V_24 == 1 ) {
F_5 ( V_50 , L_40 ) ;
V_11 = F_77 ( sizeof( * V_11 ) , V_140 ) ;
if ( ! V_11 )
return F_76 ( - V_52 ) ;
} else {
F_5 ( V_50 , L_41 ) ;
V_6 = F_78 ( sizeof( * V_11 ) , V_7 , V_141 ) ;
if ( ! V_6 )
return F_76 ( - V_52 ) ;
V_11 = F_16 ( V_6 ) ;
V_11 -> V_6 = V_6 ;
}
V_11 -> V_2 = V_2 ;
V_2 -> V_5 [ V_24 ] = V_11 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_24 = V_24 ;
F_79 ( & V_11 -> V_90 ) ;
if ( V_33 != NULL )
memcpy ( V_11 -> V_33 , V_33 , V_27 ) ;
F_5 ( V_23 , L_42 ,
V_142 -> V_143 , V_7 , V_11 -> V_33 ) ;
return V_11 ;
}
void F_80 ( struct V_1 * V_2 , T_3 V_24 )
{
struct V_10 * V_11 ;
V_11 = V_2 -> V_5 [ V_24 ] ;
V_2 -> V_5 [ V_24 ] = NULL ;
if ( ! V_11 ) {
F_2 ( L_43 , V_24 ) ;
return;
}
F_5 ( V_23 , L_37 , V_24 , V_11 -> V_3 ) ;
if ( V_11 -> V_6 ) {
if ( V_24 == 0 ) {
if ( V_11 -> V_6 -> V_127 == & V_128 ) {
F_81 () ;
F_58 ( V_11 -> V_6 ) ;
F_82 () ;
}
} else {
F_20 ( V_11 -> V_6 ) ;
}
if ( V_11 -> V_6 -> V_127 == & V_128 ) {
F_83 ( & V_11 -> V_32 ) ;
F_83 ( & V_11 -> V_22 ) ;
}
F_75 ( V_11 -> V_6 ) ;
if ( V_24 == 0 )
F_84 ( V_2 -> V_144 ) ;
} else {
F_11 ( V_11 ) ;
}
}
int F_85 ( T_5 V_145 , struct V_63 * V_64 )
{
struct V_1 * V_2 = NULL ;
int V_40 = 0 ;
F_5 ( V_23 , L_20 ) ;
V_2 = F_77 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 )
return - V_52 ;
F_86 ( & V_2 -> V_146 ) ;
V_2 -> V_48 = V_145 ;
V_2 -> V_43 = F_28 ( V_64 ) ;
V_2 -> V_43 -> V_2 = V_2 ;
F_87 ( V_2 ) ;
V_40 = F_88 ( V_2 ) ;
if ( V_40 != 0 ) {
F_2 ( L_44 ) ;
goto V_134;
}
F_89 ( V_2 ) ;
F_90 ( & V_2 -> V_43 -> V_147 ) ;
return V_40 ;
V_134:
F_91 ( V_64 ) ;
return V_40 ;
}
int F_92 ( struct V_63 * V_64 )
{
int V_40 = - 1 ;
struct V_65 * V_43 = F_28 ( V_64 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_10 * V_11 ;
struct V_10 * V_148 ;
F_5 ( V_23 , L_45 ) ;
V_40 = F_93 ( V_43 ) ;
if ( V_40 != 0 ) {
F_2 ( L_46 , V_40 ) ;
return V_40 ;
}
V_11 = F_74 ( V_2 , 0 , 0 , L_47 , NULL ) ;
if ( F_94 ( V_11 ) )
return F_95 ( V_11 ) ;
if ( V_139 )
V_148 = F_74 ( V_2 , 1 , 0 , L_48 , NULL ) ;
else
V_148 = NULL ;
if ( F_94 ( V_148 ) )
V_148 = NULL ;
V_43 -> V_44 = V_45 ;
V_40 = F_96 ( V_11 ) ;
if ( V_40 < 0 )
goto V_134;
V_2 -> V_72 = true ;
V_40 = F_97 ( V_2 ) ;
if ( V_40 < 0 )
goto V_134;
F_98 ( V_11 ) ;
V_2 -> V_144 = F_99 ( V_2 , V_43 -> V_64 ) ;
if ( V_2 -> V_144 == NULL ) {
V_40 = - V_52 ;
goto V_134;
}
V_40 = F_100 ( V_11 ) ;
if ( V_40 < 0 )
goto V_134;
V_40 = F_64 ( V_11 , false ) ;
V_134:
if ( V_40 < 0 ) {
F_2 ( L_49 , V_40 ) ;
if ( V_2 -> V_144 )
F_84 ( V_2 -> V_144 ) ;
if ( V_2 -> V_92 ) {
F_101 ( V_11 ) ;
F_102 ( V_2 ) ;
}
if ( V_2 -> V_5 [ 0 ] ) {
V_136 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ 0 ] = NULL ;
}
if ( V_148 ) {
V_136 ( V_148 -> V_6 ) ;
V_2 -> V_5 [ 1 ] = NULL ;
}
return V_40 ;
}
if ( ( V_139 ) && ( V_148 ) )
if ( F_73 ( V_148 ) < 0 )
V_139 = 0 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_5 ( V_23 , L_20 ) ;
if ( V_2 ) {
F_104 ( V_2 ) ;
F_105 ( V_2 -> V_43 ) ;
}
}
void F_106 ( struct V_63 * V_64 )
{
struct V_65 * V_43 = F_28 ( V_64 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_5 [ 0 ] )
F_13 ( V_2 -> V_5 [ 0 ] , V_149 , 1 ) ;
}
void F_91 ( struct V_63 * V_64 )
{
T_3 V_66 ;
struct V_65 * V_43 = F_28 ( V_64 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
F_5 ( V_23 , L_20 ) ;
if ( V_2 == NULL )
return;
F_107 ( V_2 ) ;
for ( V_66 = V_4 - 1 ; V_66 > - 1 ; V_66 -- )
if ( V_2 -> V_5 [ V_66 ] ) {
F_101 ( V_2 -> V_5 [ V_66 ] ) ;
F_80 ( V_2 , V_66 ) ;
}
F_103 ( V_2 ) ;
if ( V_2 -> V_150 )
F_108 ( V_2 ) ;
F_102 ( V_2 ) ;
F_109 ( V_2 ) ;
V_43 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
static int F_110 ( struct V_10 * V_11 )
{
return F_111 ( & V_11 -> V_89 ) ;
}
int F_112 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
int V_21 ;
V_21 = F_113 ( V_11 -> V_90 ,
! F_110 ( V_11 ) ,
F_114 ( V_151 ) ) ;
F_115 ( ! V_21 ) ;
return ! V_21 ;
}
T_1 F_116 ( struct V_10 * V_11 )
{
struct V_65 * V_152 = V_11 -> V_2 -> V_43 ;
return V_152 -> V_153 << 4 | V_152 -> V_154 ;
}
static void F_117 ( struct V_8 * V_9 )
{
F_118 () ;
#ifdef F_119
F_120 () ;
#endif
#ifdef F_121
F_122 () ;
#endif
}
static int T_9 F_123 ( void )
{
if ( ! F_17 ( & V_155 ) )
return - V_156 ;
return 0 ;
}
static void T_10 F_124 ( void )
{
F_83 ( & V_155 ) ;
#ifdef F_119
F_125 () ;
#endif
#ifdef F_121
F_126 () ;
#endif
F_127 () ;
}
