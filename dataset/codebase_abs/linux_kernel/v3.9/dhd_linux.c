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
V_42 = (struct V_41 * ) ( V_39 -> V_55 ) ;
if ( F_24 ( V_42 -> V_56 ) )
V_2 -> V_57 ++ ;
if ( F_25 ( V_42 -> V_58 ) == V_59 )
F_26 ( & V_11 -> V_60 ) ;
F_27 ( V_2 , V_11 -> V_3 , V_39 ) ;
V_40 = F_28 ( V_2 -> V_43 , V_39 ) ;
V_47:
if ( V_40 ) {
V_11 -> V_61 . V_62 ++ ;
} else {
V_11 -> V_61 . V_63 ++ ;
V_11 -> V_61 . V_64 += V_39 -> V_53 ;
}
return V_65 ;
}
void F_29 ( struct V_66 * V_67 , bool V_44 )
{
struct V_12 * V_6 ;
struct V_68 * V_43 = F_30 ( V_67 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
int V_69 ;
F_5 ( V_23 , L_19 ) ;
for ( V_69 = 0 ; V_69 < V_4 ; V_69 ++ )
if ( V_2 -> V_5 [ V_69 ] ) {
V_6 = V_2 -> V_5 [ V_69 ] -> V_6 ;
if ( V_44 )
F_20 ( V_6 ) ;
else
F_31 ( V_6 ) ;
}
}
void F_32 ( struct V_66 * V_67 , struct V_70 * V_71 )
{
unsigned char * V_72 ;
T_5 V_53 ;
struct V_38 * V_39 , * V_73 ;
struct V_10 * V_11 ;
struct V_68 * V_43 = F_30 ( V_67 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
T_6 V_3 ;
int V_40 ;
F_5 ( V_23 , L_19 ) ;
F_33 (skb_list, skb, pnext) {
F_34 ( V_39 , V_71 ) ;
V_40 = F_35 ( V_2 , & V_3 , V_39 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( V_40 || ! V_11 || ! V_11 -> V_6 ) {
if ( ( V_40 != - V_74 ) && V_11 )
V_11 -> V_61 . V_75 ++ ;
F_36 ( V_39 ) ;
continue;
}
V_72 = V_39 -> V_55 ;
V_53 = V_39 -> V_53 ;
V_39 -> V_67 = V_11 -> V_6 ;
V_39 -> V_76 = F_37 ( V_39 , V_39 -> V_67 ) ;
if ( V_39 -> V_77 == V_78 )
V_11 -> V_61 . V_79 ++ ;
V_39 -> V_55 = V_72 ;
V_39 -> V_53 = V_53 ;
F_38 ( V_39 , V_80 ) ;
F_39 ( V_2 , V_39 , & V_3 ) ;
if ( V_2 -> V_5 [ V_3 ] ) {
V_11 = V_2 -> V_5 [ V_3 ] ;
V_11 -> V_6 -> V_81 = V_82 ;
}
if ( ! ( V_11 -> V_6 -> V_25 & V_83 ) ) {
F_36 ( V_39 ) ;
continue;
}
V_11 -> V_61 . V_84 += V_39 -> V_53 ;
V_11 -> V_61 . V_85 ++ ;
if ( F_40 () )
F_41 ( V_39 ) ;
else
F_42 ( V_39 ) ;
}
}
void F_43 ( struct V_66 * V_67 , struct V_38 * V_86 , bool V_87 )
{
T_6 V_3 ;
struct V_41 * V_42 ;
T_7 type ;
struct V_68 * V_43 = F_30 ( V_67 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_10 * V_11 ;
F_35 ( V_2 , & V_3 , V_86 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( ! V_11 )
return;
V_42 = (struct V_41 * ) ( V_86 -> V_55 ) ;
type = F_25 ( V_42 -> V_58 ) ;
if ( type == V_59 ) {
F_44 ( & V_11 -> V_60 ) ;
if ( F_45 ( & V_11 -> V_88 ) )
F_46 ( & V_11 -> V_88 ) ;
}
if ( ! V_87 )
V_11 -> V_61 . V_89 ++ ;
}
static struct V_90 * F_47 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
return & V_11 -> V_61 ;
}
static int F_48 ( struct V_10 * V_11 , T_1 V_91 )
{
T_3 V_21 ;
V_21 = F_12 ( V_11 , L_20 , V_91 ) ;
if ( V_21 < 0 ) {
F_2 ( L_21 , V_21 ) ;
return V_21 ;
}
V_21 = F_12 ( V_11 , L_22 , ( V_91 != 0 ) ) ;
if ( V_21 < 0 )
F_2 ( L_23 , V_21 ) ;
return V_21 ;
}
static void F_49 ( struct V_12 * V_6 ,
struct V_92 * V_93 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_50 ( V_93 -> V_94 , V_95 , sizeof( V_93 -> V_94 ) ) ;
snprintf ( V_93 -> V_96 , sizeof( V_93 -> V_96 ) , L_24 ,
V_2 -> V_97 ) ;
F_50 ( V_93 -> V_98 , F_51 ( V_2 -> V_43 -> V_67 ) ,
sizeof( V_93 -> V_98 ) ) ;
}
static int F_52 ( struct V_10 * V_11 , void T_8 * V_99 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_92 V_93 ;
char V_100 [ sizeof( V_93 . V_94 ) ] ;
T_1 V_101 ;
struct V_102 V_103 ;
T_1 V_104 , V_105 ;
int V_40 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( F_53 ( & V_101 , V_99 , sizeof( T_1 ) ) )
return - V_106 ;
switch ( V_101 ) {
case V_107 :
if ( F_53 ( & V_93 , V_99 , sizeof( V_93 ) ) )
return - V_106 ;
strncpy ( V_100 , V_93 . V_94 , sizeof( V_93 . V_94 ) ) ;
V_100 [ sizeof( V_93 . V_94 ) - 1 ] = '\0' ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_101 = V_101 ;
if ( strcmp ( V_100 , L_25 ) == 0 ) {
sprintf ( V_93 . V_94 , L_26 ) ;
strcpy ( V_93 . V_96 , V_108 ) ;
}
else
sprintf ( V_93 . V_94 , L_27 ) ;
sprintf ( V_93 . V_96 , L_24 , V_2 -> V_97 ) ;
if ( F_54 ( V_99 , & V_93 , sizeof( V_93 ) ) )
return - V_106 ;
F_5 ( V_23 , L_28 ,
( int ) sizeof( V_100 ) , V_100 , V_93 . V_94 ) ;
break;
case V_109 :
case V_110 :
V_40 = F_55 ( V_11 , L_20 , & V_104 ) ;
if ( V_40 < 0 )
return V_40 ;
V_105 =
( V_101 == V_110 ) ? V_111 : V_112 ;
V_103 . V_101 = V_101 ;
V_103 . V_55 = ( V_104 & V_105 ) ? 1 : 0 ;
if ( F_54 ( V_99 , & V_103 , sizeof( V_103 ) ) )
return - V_106 ;
break;
case V_113 :
case V_114 :
if ( F_53 ( & V_103 , V_99 , sizeof( V_103 ) ) )
return - V_106 ;
V_40 = F_55 ( V_11 , L_20 , & V_104 ) ;
if ( V_40 < 0 )
return V_40 ;
V_105 =
( V_101 == V_114 ) ? V_111 : V_112 ;
if ( V_103 . V_55 != 0 )
V_104 |= V_105 ;
else
V_104 &= ~ V_105 ;
V_40 = F_48 ( V_11 , V_104 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_101 == V_114 ) {
if ( V_103 . V_55 )
V_11 -> V_6 -> V_115 |= V_116 ;
else
V_11 -> V_6 -> V_115 &= ~ V_116 ;
}
break;
default:
return - V_117 ;
}
return 0 ;
}
static int F_56 ( struct V_12 * V_6 , struct V_118 * V_119 ,
int V_101 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_5 ( V_23 , L_29 , V_11 -> V_24 , V_101 ) ;
if ( ! V_2 -> V_5 [ V_11 -> V_24 ] )
return - 1 ;
if ( V_101 == V_120 )
return F_52 ( V_11 , V_119 -> V_121 ) ;
return - V_117 ;
}
static int F_57 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
F_58 ( V_6 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_59 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_68 * V_43 = V_2 -> V_43 ;
T_1 V_91 ;
T_3 V_40 = 0 ;
F_5 ( V_23 , L_6 , V_11 -> V_24 ) ;
if ( V_43 -> V_44 != V_45 ) {
F_2 ( L_30 ) ;
return - V_122 ;
}
F_60 ( & V_11 -> V_60 , 0 ) ;
if ( F_55 ( V_11 , L_20 , & V_91 ) >= 0
&& ( V_91 & V_111 ) != 0 )
V_6 -> V_115 |= V_116 ;
else
V_6 -> V_115 &= ~ V_116 ;
F_61 ( V_6 ) ;
if ( F_62 ( V_6 ) ) {
F_2 ( L_31 ) ;
return - 1 ;
}
return V_40 ;
}
int F_63 ( struct V_10 * V_11 , bool V_123 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_6 ;
T_3 V_21 ;
F_5 ( V_23 , L_32 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_124 = & V_125 ;
V_6 -> V_126 = V_80 + V_2 -> V_48 ;
V_6 -> V_127 = & V_128 ;
V_2 -> V_129 = V_6 -> V_130 + V_6 -> V_126 +
V_2 -> V_48 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
F_64 ( & V_11 -> V_32 , F_14 ) ;
F_64 ( & V_11 -> V_22 , F_3 ) ;
if ( V_123 )
V_21 = F_65 ( V_6 ) ;
else
V_21 = F_66 ( V_6 ) ;
if ( V_21 != 0 ) {
F_2 ( L_33 ) ;
goto V_131;
}
F_5 ( V_50 , L_34 , V_6 -> V_7 ) ;
return 0 ;
V_131:
V_6 -> V_124 = NULL ;
return - V_132 ;
}
static int F_67 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_19 ) ;
return F_62 ( V_6 ) ;
}
static int F_68 ( struct V_12 * V_6 )
{
F_5 ( V_23 , L_19 ) ;
return F_58 ( V_6 ) ;
}
static int F_69 ( struct V_12 * V_6 ,
struct V_118 * V_119 , int V_101 )
{
F_5 ( V_23 , L_19 ) ;
return 0 ;
}
static T_4 F_70 ( struct V_38 * V_39 ,
struct V_12 * V_6 )
{
if ( V_39 )
F_71 ( V_39 ) ;
return V_65 ;
}
static int F_72 ( struct V_10 * V_11 )
{
struct V_12 * V_6 ;
F_5 ( V_23 , L_32 , V_11 -> V_24 ,
V_11 -> V_33 ) ;
V_6 = V_11 -> V_6 ;
V_6 -> V_124 = & V_133 ;
memcpy ( V_6 -> V_34 , V_11 -> V_33 , V_27 ) ;
if ( F_66 ( V_6 ) != 0 ) {
F_2 ( L_35 ) ;
goto V_131;
}
F_5 ( V_50 , L_34 , V_6 -> V_7 ) ;
return 0 ;
V_131:
return - V_132 ;
}
struct V_10 * F_73 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_3 ,
char * V_7 , T_6 * V_33 )
{
struct V_10 * V_11 ;
struct V_12 * V_6 ;
F_5 ( V_23 , L_36 , V_24 , V_3 ) ;
V_11 = V_2 -> V_5 [ V_24 ] ;
if ( V_11 ) {
F_2 ( L_37 ,
V_11 -> V_6 -> V_7 ) ;
if ( V_3 ) {
F_20 ( V_11 -> V_6 ) ;
F_74 ( V_11 -> V_6 ) ;
F_75 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_24 ] = NULL ;
} else {
F_2 ( L_38 ) ;
return F_76 ( - V_54 ) ;
}
}
V_6 = F_77 ( sizeof( struct V_10 ) , V_7 , V_134 ) ;
if ( ! V_6 ) {
F_2 ( L_39 ) ;
return F_76 ( - V_52 ) ;
}
V_11 = F_16 ( V_6 ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
V_2 -> V_5 [ V_24 ] = V_11 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_24 = V_24 ;
F_78 ( & V_11 -> V_88 ) ;
if ( V_33 != NULL )
memcpy ( V_11 -> V_33 , V_33 , V_27 ) ;
F_5 ( V_23 , L_40 ,
V_135 -> V_136 , V_11 -> V_6 -> V_7 , V_11 -> V_33 ) ;
return V_11 ;
}
void F_79 ( struct V_1 * V_2 , T_3 V_24 )
{
struct V_10 * V_11 ;
V_11 = V_2 -> V_5 [ V_24 ] ;
if ( ! V_11 ) {
F_2 ( L_41 , V_24 ) ;
return;
}
F_5 ( V_23 , L_36 , V_24 , V_11 -> V_3 ) ;
if ( V_11 -> V_6 ) {
if ( V_24 == 0 ) {
if ( V_11 -> V_6 -> V_124 == & V_125 ) {
F_80 () ;
F_57 ( V_11 -> V_6 ) ;
F_81 () ;
}
} else {
F_20 ( V_11 -> V_6 ) ;
}
if ( V_11 -> V_6 -> V_124 == & V_125 ) {
F_82 ( & V_11 -> V_32 ) ;
F_82 ( & V_11 -> V_22 ) ;
}
F_74 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_24 ] = NULL ;
if ( V_24 == 0 )
F_83 ( V_2 -> V_137 ) ;
F_75 ( V_11 -> V_6 ) ;
}
}
int F_84 ( T_5 V_138 , struct V_66 * V_67 )
{
struct V_1 * V_2 = NULL ;
int V_40 = 0 ;
F_5 ( V_23 , L_19 ) ;
V_2 = F_85 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 )
return - V_52 ;
F_86 ( & V_2 -> V_139 ) ;
V_2 -> V_48 = V_138 ;
V_2 -> V_43 = F_30 ( V_67 ) ;
V_2 -> V_43 -> V_2 = V_2 ;
F_87 ( V_2 ) ;
V_40 = F_88 ( V_2 ) ;
if ( V_40 != 0 ) {
F_2 ( L_42 ) ;
goto V_131;
}
F_89 ( V_2 ) ;
F_90 ( & V_2 -> V_43 -> V_140 ) ;
return V_40 ;
V_131:
F_91 ( V_67 ) ;
return V_40 ;
}
int F_92 ( struct V_66 * V_67 )
{
int V_40 = - 1 ;
struct V_68 * V_43 = F_30 ( V_67 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_10 * V_11 ;
struct V_10 * V_141 ;
F_5 ( V_23 , L_43 ) ;
V_40 = F_93 ( V_43 ) ;
if ( V_40 != 0 ) {
F_2 ( L_44 , V_40 ) ;
return V_40 ;
}
V_11 = F_73 ( V_2 , 0 , 0 , L_45 , NULL ) ;
if ( F_94 ( V_11 ) )
return F_95 ( V_11 ) ;
if ( V_142 )
V_141 = F_73 ( V_2 , 1 , 0 , L_46 , NULL ) ;
else
V_141 = NULL ;
if ( F_94 ( V_141 ) )
V_141 = NULL ;
V_43 -> V_44 = V_45 ;
V_40 = F_96 ( V_11 ) ;
if ( V_40 < 0 )
goto V_131;
V_2 -> V_137 = F_97 ( V_2 , V_43 -> V_67 ) ;
if ( V_2 -> V_137 == NULL ) {
V_40 = - V_52 ;
goto V_131;
}
V_40 = F_98 ( V_11 ) ;
if ( V_40 < 0 )
goto V_131;
V_40 = F_63 ( V_11 , false ) ;
V_131:
if ( V_40 < 0 ) {
F_2 ( L_47 , V_40 ) ;
if ( V_2 -> V_137 )
F_83 ( V_2 -> V_137 ) ;
F_75 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ 0 ] = NULL ;
if ( V_141 ) {
F_75 ( V_141 -> V_6 ) ;
V_2 -> V_5 [ 1 ] = NULL ;
}
return V_40 ;
}
if ( ( V_142 ) && ( V_141 ) )
F_72 ( V_141 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_5 ( V_23 , L_19 ) ;
if ( V_2 ) {
F_100 ( V_2 ) ;
F_101 ( V_2 -> V_43 ) ;
}
}
void F_102 ( struct V_66 * V_67 )
{
struct V_68 * V_43 = F_30 ( V_67 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_5 [ 0 ] )
F_13 ( V_2 -> V_5 [ 0 ] , V_143 , 1 ) ;
}
void F_91 ( struct V_66 * V_67 )
{
T_3 V_69 ;
struct V_68 * V_43 = F_30 ( V_67 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
F_5 ( V_23 , L_19 ) ;
if ( V_2 == NULL )
return;
F_103 ( V_2 ) ;
for ( V_69 = V_4 - 1 ; V_69 > - 1 ; V_69 -- )
if ( V_2 -> V_5 [ V_69 ] )
F_79 ( V_2 , V_69 ) ;
F_99 ( V_2 ) ;
if ( V_2 -> V_144 )
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
V_43 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
static int F_106 ( struct V_10 * V_11 )
{
return F_107 ( & V_11 -> V_60 ) ;
}
int F_108 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
int V_21 ;
V_21 = F_109 ( V_11 -> V_88 ,
! F_106 ( V_11 ) ,
F_110 ( V_145 ) ) ;
F_111 ( ! V_21 ) ;
return ! V_21 ;
}
T_1 F_112 ( struct V_10 * V_11 )
{
struct V_68 * V_146 = V_11 -> V_2 -> V_43 ;
return V_146 -> V_147 << 4 | V_146 -> V_148 ;
}
static void F_113 ( struct V_8 * V_9 )
{
F_114 () ;
#ifdef F_115
F_116 () ;
#endif
#ifdef F_117
F_118 () ;
#endif
}
static int T_9 F_119 ( void )
{
if ( ! F_17 ( & V_149 ) )
return - V_150 ;
return 0 ;
}
static void T_10 F_120 ( void )
{
F_82 ( & V_149 ) ;
#ifdef F_115
F_121 () ;
#endif
#ifdef F_117
F_122 () ;
#endif
F_123 () ;
}
