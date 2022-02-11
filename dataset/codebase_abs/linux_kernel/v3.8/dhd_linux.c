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
F_4 ( V_22 , L_6 ) ;
V_11 = F_5 ( V_9 , struct V_10 , V_23 ) ;
V_6 = V_11 -> V_6 ;
V_15 = ( V_6 -> V_24 & V_25 ) ? true : false ;
V_16 = F_6 ( V_6 ) ;
V_20 = sizeof( V_16 ) + ( V_16 * V_26 ) ;
V_18 = F_7 ( V_20 , V_27 ) ;
if ( ! V_18 )
return;
V_19 = V_18 ;
V_17 = F_8 ( V_16 ) ;
memcpy ( V_19 , & V_17 , sizeof( V_17 ) ) ;
V_19 += sizeof( V_17 ) ;
F_9 (ha, ndev) {
if ( ! V_16 )
break;
memcpy ( V_19 , V_14 -> V_28 , V_26 ) ;
V_19 += V_26 ;
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
V_15 = ( V_6 -> V_24 & V_29 ) ? true : false ;
V_21 = F_13 ( V_11 , V_30 , V_15 ) ;
if ( V_21 < 0 )
F_2 ( L_11 ,
V_21 ) ;
}
static void
F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
T_3 V_21 ;
F_4 ( V_22 , L_6 ) ;
V_11 = F_5 ( V_9 , struct V_10 , V_31 ) ;
V_21 = F_10 ( V_11 , L_12 , V_11 -> V_32 ,
V_26 ) ;
if ( V_21 < 0 ) {
F_2 ( L_13 , V_21 ) ;
} else {
F_4 ( V_22 , L_14 ,
V_11 -> V_32 ) ;
memcpy ( V_11 -> V_6 -> V_33 , V_11 -> V_32 , V_26 ) ;
}
}
static int F_15 ( struct V_12 * V_6 , void * V_28 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_34 * V_35 = (struct V_34 * ) V_28 ;
memcpy ( & V_11 -> V_32 , V_35 -> V_36 , V_26 ) ;
F_17 ( & V_11 -> V_31 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
F_17 ( & V_11 -> V_23 ) ;
}
static int F_19 ( struct V_37 * V_38 , struct V_12 * V_6 )
{
int V_39 ;
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_4 ( V_22 , L_15 ) ;
if ( ! V_2 -> V_40 -> V_41 ||
( V_2 -> V_40 -> V_42 != V_43 ) ) {
F_2 ( L_16 ,
V_2 -> V_40 -> V_41 ,
V_2 -> V_40 -> V_42 ) ;
F_20 ( V_6 ) ;
return - V_44 ;
}
if ( ! V_2 -> V_5 [ V_11 -> V_45 ] ) {
F_2 ( L_17 , V_11 -> V_45 ) ;
F_20 ( V_6 ) ;
return - V_44 ;
}
if ( F_21 ( V_38 ) < V_2 -> V_46 ) {
struct V_37 * V_47 ;
F_4 ( V_48 , L_18 ,
F_1 ( V_2 , V_11 -> V_45 ) ) ;
V_2 -> V_40 -> V_49 ++ ;
V_47 = F_22 ( V_38 , V_2 -> V_46 ) ;
F_23 ( V_38 ) ;
V_38 = V_47 ;
if ( V_38 == NULL ) {
F_2 ( L_19 ,
F_1 ( V_2 , V_11 -> V_45 ) ) ;
V_39 = - V_50 ;
goto V_51;
}
}
if ( V_38 -> V_52 >= V_26 ) {
T_4 * V_53 = ( T_4 * ) ( V_38 -> V_54 ) ;
struct V_55 * V_56 = (struct V_55 * ) V_53 ;
if ( F_24 ( V_56 -> V_57 ) )
V_2 -> V_58 ++ ;
if ( F_25 ( V_56 -> V_59 ) == V_60 )
F_26 ( & V_2 -> V_61 ) ;
}
F_27 ( V_2 , V_11 -> V_45 , V_38 ) ;
V_39 = F_28 ( V_2 -> V_40 , V_38 ) ;
V_51:
if ( V_39 )
V_2 -> V_40 -> V_62 . V_63 ++ ;
else
V_2 -> V_40 -> V_62 . V_64 ++ ;
return 0 ;
}
void F_29 ( struct V_65 * V_66 , bool V_42 )
{
struct V_12 * V_6 ;
struct V_67 * V_40 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
int V_68 ;
F_4 ( V_22 , L_15 ) ;
for ( V_68 = 0 ; V_68 < V_4 ; V_68 ++ )
if ( V_2 -> V_5 [ V_68 ] ) {
V_6 = V_2 -> V_5 [ V_68 ] -> V_6 ;
if ( V_42 )
F_20 ( V_6 ) ;
else
F_31 ( V_6 ) ;
}
}
void F_32 ( struct V_65 * V_66 , T_4 V_3 ,
struct V_69 * V_70 )
{
unsigned char * V_71 ;
T_5 V_52 ;
struct V_37 * V_38 , * V_72 ;
struct V_10 * V_11 ;
struct V_67 * V_40 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
F_4 ( V_22 , L_15 ) ;
F_33 (skb_list, skb, pnext) {
F_34 ( V_38 , V_70 ) ;
V_71 = V_38 -> V_54 ;
V_52 = V_38 -> V_52 ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( V_11 == NULL )
V_11 = V_2 -> V_5 [ 0 ] ;
if ( ! V_11 || ! V_11 -> V_6 ||
V_11 -> V_6 -> V_73 != V_74 ) {
F_35 ( V_38 ) ;
continue;
}
V_38 -> V_66 = V_11 -> V_6 ;
V_38 -> V_75 = F_36 ( V_38 , V_38 -> V_66 ) ;
if ( V_38 -> V_76 == V_77 )
V_40 -> V_62 . V_78 ++ ;
V_38 -> V_54 = V_71 ;
V_38 -> V_52 = V_52 ;
F_37 ( V_38 , V_79 ) ;
F_38 ( V_2 , V_38 , & V_3 ) ;
if ( V_2 -> V_5 [ V_3 ] ) {
V_11 = V_2 -> V_5 [ V_3 ] ;
V_11 -> V_6 -> V_80 = V_81 ;
}
V_40 -> V_62 . V_82 += V_38 -> V_52 ;
V_40 -> V_62 . V_83 ++ ;
if ( F_39 () )
F_40 ( V_38 ) ;
else
F_41 ( V_38 ) ;
}
}
void F_42 ( struct V_65 * V_66 , struct V_37 * V_84 , bool V_85 )
{
T_5 V_3 ;
struct V_55 * V_56 ;
T_6 type ;
struct V_67 * V_40 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
F_43 ( V_66 , & V_3 , V_84 ) ;
V_56 = (struct V_55 * ) ( V_84 -> V_54 ) ;
type = F_25 ( V_56 -> V_59 ) ;
if ( type == V_60 ) {
F_44 ( & V_2 -> V_61 ) ;
if ( F_45 ( & V_2 -> V_86 ) )
F_46 ( & V_2 -> V_86 ) ;
}
}
static struct V_87 * F_47 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_67 * V_40 = V_11 -> V_2 -> V_40 ;
F_4 ( V_22 , L_15 ) ;
V_11 -> V_88 . V_83 = V_40 -> V_62 . V_83 ;
V_11 -> V_88 . V_64 = V_40 -> V_62 . V_64 ;
V_11 -> V_88 . V_82 = V_40 -> V_62 . V_82 ;
V_11 -> V_88 . V_89 = V_40 -> V_62 . V_89 ;
V_11 -> V_88 . V_90 = V_40 -> V_62 . V_90 ;
V_11 -> V_88 . V_91 = V_40 -> V_62 . V_91 ;
V_11 -> V_88 . V_92 = V_40 -> V_62 . V_92 ;
V_11 -> V_88 . V_63 = V_40 -> V_62 . V_63 ;
V_11 -> V_88 . V_78 = V_40 -> V_62 . V_78 ;
return & V_11 -> V_88 ;
}
static int F_48 ( struct V_10 * V_11 , T_1 V_93 )
{
T_3 V_21 ;
V_21 = F_12 ( V_11 , L_20 , V_93 ) ;
if ( V_21 < 0 ) {
F_2 ( L_21 , V_21 ) ;
return V_21 ;
}
V_21 = F_12 ( V_11 , L_22 , ( V_93 != 0 ) ) ;
if ( V_21 < 0 )
F_2 ( L_23 , V_21 ) ;
return V_21 ;
}
static void F_49 ( struct V_12 * V_6 ,
struct V_94 * V_95 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
sprintf ( V_95 -> V_96 , V_97 ) ;
sprintf ( V_95 -> V_98 , L_24 , V_2 -> V_99 ) ;
sprintf ( V_95 -> V_100 , L_25 , F_50 ( V_2 -> V_40 -> V_66 ) ) ;
}
static int F_51 ( struct V_10 * V_11 , void T_7 * V_101 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_94 V_95 ;
char V_102 [ sizeof( V_95 . V_96 ) ] ;
T_1 V_103 ;
struct V_104 V_105 ;
T_1 V_106 , V_107 ;
int V_39 ;
F_4 ( V_22 , L_15 ) ;
if ( F_52 ( & V_103 , V_101 , sizeof( T_1 ) ) )
return - V_108 ;
switch ( V_103 ) {
case V_109 :
if ( F_52 ( & V_95 , V_101 , sizeof( V_95 ) ) )
return - V_108 ;
strncpy ( V_102 , V_95 . V_96 , sizeof( V_95 . V_96 ) ) ;
V_102 [ sizeof( V_95 . V_96 ) - 1 ] = '\0' ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_103 = V_103 ;
if ( strcmp ( V_102 , L_26 ) == 0 ) {
sprintf ( V_95 . V_96 , L_27 ) ;
strcpy ( V_95 . V_98 , V_110 ) ;
}
else if ( ! V_2 -> V_40 -> V_41 ) {
F_2 ( L_28 ) ;
return - V_44 ;
}
else
sprintf ( V_95 . V_96 , L_29 ) ;
sprintf ( V_95 . V_98 , L_24 , V_2 -> V_99 ) ;
if ( F_53 ( V_101 , & V_95 , sizeof( V_95 ) ) )
return - V_108 ;
F_4 ( V_111 , L_30 ,
( int ) sizeof( V_102 ) , V_102 , V_95 . V_96 ) ;
break;
case V_112 :
case V_113 :
V_39 = F_54 ( V_11 , L_20 , & V_106 ) ;
if ( V_39 < 0 )
return V_39 ;
V_107 =
( V_103 == V_113 ) ? V_114 : V_115 ;
V_105 . V_103 = V_103 ;
V_105 . V_54 = ( V_106 & V_107 ) ? 1 : 0 ;
if ( F_53 ( V_101 , & V_105 , sizeof( V_105 ) ) )
return - V_108 ;
break;
case V_116 :
case V_117 :
if ( F_52 ( & V_105 , V_101 , sizeof( V_105 ) ) )
return - V_108 ;
V_39 = F_54 ( V_11 , L_20 , & V_106 ) ;
if ( V_39 < 0 )
return V_39 ;
V_107 =
( V_103 == V_117 ) ? V_114 : V_115 ;
if ( V_105 . V_54 != 0 )
V_106 |= V_107 ;
else
V_106 &= ~ V_107 ;
V_39 = F_48 ( V_11 , V_106 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_103 == V_117 ) {
if ( V_105 . V_54 )
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
static int F_55 ( struct V_12 * V_6 , struct V_121 * V_122 ,
int V_103 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_4 ( V_22 , L_31 , V_11 -> V_45 , V_103 ) ;
if ( ! V_2 -> V_5 [ V_11 -> V_45 ] )
return - 1 ;
if ( V_103 == V_123 )
return F_51 ( V_11 , V_122 -> V_124 ) ;
return - V_120 ;
}
static int F_56 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_4 ( V_22 , L_15 ) ;
if ( V_2 -> V_40 -> V_41 == 0 )
return 0 ;
F_57 ( V_6 ) ;
V_2 -> V_40 -> V_41 = false ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_58 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_67 * V_40 = V_2 -> V_40 ;
T_1 V_93 ;
T_3 V_39 = 0 ;
F_4 ( V_22 , L_32 , V_11 -> V_45 ) ;
if ( V_40 -> V_42 != V_43 ) {
F_2 ( L_33 ) ;
return - V_125 ;
}
F_59 ( & V_2 -> V_61 , 0 ) ;
memcpy ( V_6 -> V_33 , V_2 -> V_126 , V_26 ) ;
if ( F_54 ( V_11 , L_20 , & V_93 ) >= 0
&& ( V_93 & V_114 ) != 0 )
V_2 -> V_5 [ V_11 -> V_45 ] -> V_6 -> V_118 |=
V_119 ;
else
V_2 -> V_5 [ V_11 -> V_45 ] -> V_6 -> V_118 &=
~ V_119 ;
F_13 ( V_11 , V_127 , 0 ) ;
F_60 ( V_6 ) ;
V_2 -> V_40 -> V_41 = true ;
if ( F_61 ( V_6 ) ) {
F_2 ( L_34 ) ;
return - 1 ;
}
return V_39 ;
}
int F_62 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_6 ;
F_4 ( V_22 , L_35 , V_11 -> V_45 , V_11 -> V_32 ) ;
V_6 = V_11 -> V_6 ;
if ( ! V_11 -> V_45 )
V_6 -> V_128 = & V_129 ;
else
V_6 -> V_128 = & V_130 ;
V_6 -> V_131 = V_79 + V_2 -> V_46 ;
V_6 -> V_132 = & V_133 ;
V_2 -> V_134 = V_6 -> V_135 + V_6 -> V_131 +
V_2 -> V_46 ;
memcpy ( V_6 -> V_33 , V_11 -> V_32 , V_26 ) ;
if ( F_63 ( V_6 ) != 0 ) {
F_2 ( L_36 ) ;
goto V_136;
}
F_4 ( V_48 , L_37 , V_6 -> V_7 ) ;
return 0 ;
V_136:
V_6 -> V_128 = NULL ;
return - V_137 ;
}
struct V_10 * F_64 ( struct V_1 * V_2 , int V_3 , T_3 V_138 ,
char * V_7 , T_4 * V_139 )
{
struct V_10 * V_11 ;
struct V_12 * V_6 ;
int V_68 ;
F_4 ( V_22 , L_38 , V_3 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( V_11 ) {
F_2 ( L_39 ,
V_11 -> V_6 -> V_7 ) ;
if ( V_3 ) {
F_20 ( V_11 -> V_6 ) ;
F_65 ( V_11 -> V_6 ) ;
F_66 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_3 ] = NULL ;
} else {
F_2 ( L_40 ) ;
return F_67 ( - V_140 ) ;
}
}
V_6 = F_68 ( sizeof( struct V_10 ) , V_7 , V_141 ) ;
if ( ! V_6 ) {
F_2 ( L_41 ) ;
return F_67 ( - V_50 ) ;
}
V_11 = F_16 ( V_6 ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
V_2 -> V_5 [ V_3 ] = V_11 ;
V_11 -> V_45 = V_3 ;
V_11 -> V_138 = V_138 ;
F_69 ( & V_11 -> V_31 , F_14 ) ;
F_69 ( & V_11 -> V_23 , F_3 ) ;
if ( V_139 != NULL )
for ( V_68 = 0 ; V_68 < V_26 ; V_68 ++ )
V_11 -> V_32 [ V_68 ] = V_2 -> V_126 [ V_68 ] ^ V_139 [ V_68 ] ;
F_4 ( V_22 , L_42 ,
V_142 -> V_143 , V_11 -> V_6 -> V_7 , V_11 -> V_32 ) ;
return V_11 ;
}
void F_70 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_11 ;
F_4 ( V_22 , L_38 , V_3 ) ;
V_11 = V_2 -> V_5 [ V_3 ] ;
if ( ! V_11 ) {
F_2 ( L_43 ) ;
return;
}
if ( V_11 -> V_6 ) {
if ( V_3 == 0 ) {
if ( V_11 -> V_6 -> V_128 == & V_129 ) {
F_71 () ;
F_56 ( V_11 -> V_6 ) ;
F_72 () ;
}
} else {
F_20 ( V_11 -> V_6 ) ;
}
F_73 ( & V_11 -> V_31 ) ;
F_73 ( & V_11 -> V_23 ) ;
F_65 ( V_11 -> V_6 ) ;
V_2 -> V_5 [ V_3 ] = NULL ;
if ( V_3 == 0 )
F_74 ( V_2 -> V_144 ) ;
F_66 ( V_11 -> V_6 ) ;
}
}
int F_75 ( T_5 V_145 , struct V_65 * V_66 )
{
struct V_1 * V_2 = NULL ;
int V_39 = 0 ;
F_4 ( V_22 , L_15 ) ;
V_2 = F_76 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 )
return - V_50 ;
F_77 ( & V_2 -> V_146 ) ;
V_2 -> V_46 = V_145 ;
V_2 -> V_40 = F_30 ( V_66 ) ;
V_2 -> V_40 -> V_2 = V_2 ;
F_78 ( V_2 ) ;
V_39 = F_79 ( V_2 ) ;
if ( V_39 != 0 ) {
F_2 ( L_44 ) ;
goto V_136;
}
F_80 ( V_2 ) ;
F_81 ( & V_2 -> V_40 -> V_147 ) ;
F_82 ( & V_2 -> V_86 ) ;
return V_39 ;
V_136:
F_83 ( V_66 ) ;
return V_39 ;
}
int F_84 ( struct V_65 * V_66 )
{
int V_39 = - 1 ;
struct V_67 * V_40 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_10 * V_11 ;
F_4 ( V_22 , L_45 ) ;
V_39 = F_85 ( V_40 ) ;
if ( V_39 != 0 ) {
F_2 ( L_46 , V_39 ) ;
return V_39 ;
}
V_11 = F_64 ( V_2 , 0 , 0 , L_47 , NULL ) ;
if ( F_86 ( V_11 ) )
return F_87 ( V_11 ) ;
V_40 -> V_42 = V_43 ;
V_39 = F_88 ( V_11 ) ;
if ( V_39 < 0 )
goto V_136;
V_2 -> V_144 = F_89 ( V_2 , V_40 -> V_66 ) ;
if ( V_2 -> V_144 == NULL ) {
V_39 = - V_50 ;
goto V_136;
}
V_39 = F_90 ( V_11 ) ;
if ( V_39 < 0 )
goto V_136;
V_39 = F_62 ( V_11 ) ;
V_136:
if ( V_39 < 0 ) {
F_2 ( L_48 , V_39 ) ;
if ( V_2 -> V_144 )
F_74 ( V_2 -> V_144 ) ;
F_66 ( V_2 -> V_5 [ 0 ] -> V_6 ) ;
V_2 -> V_5 [ 0 ] = NULL ;
return V_39 ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_4 ( V_22 , L_15 ) ;
if ( V_2 ) {
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_40 ) ;
}
}
void F_83 ( struct V_65 * V_66 )
{
int V_68 ;
struct V_67 * V_40 = F_30 ( V_66 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
F_4 ( V_22 , L_15 ) ;
if ( V_2 == NULL )
return;
F_94 ( V_2 ) ;
for ( V_68 = V_4 - 1 ; V_68 > - 1 ; V_68 -- )
if ( V_2 -> V_5 [ V_68 ] )
F_70 ( V_2 , V_68 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_148 ) {
F_95 ( V_2 ) ;
}
F_96 ( V_2 ) ;
V_40 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
return F_98 ( & V_2 -> V_61 ) ;
}
int F_99 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_16 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_21 ;
V_21 = F_100 ( V_2 -> V_86 ,
! F_97 ( V_2 ) ,
F_101 ( V_149 ) ) ;
F_102 ( ! V_21 ) ;
return ! V_21 ;
}
static void F_103 ( struct V_8 * V_9 )
{
F_104 () ;
#ifdef F_105
F_106 () ;
#endif
#ifdef F_107
F_108 () ;
#endif
}
static int T_8 F_109 ( void )
{
if ( ! F_17 ( & V_150 ) )
return - V_151 ;
return 0 ;
}
static void T_9 F_110 ( void )
{
F_73 ( & V_150 ) ;
#ifdef F_105
F_111 () ;
#endif
#ifdef F_107
F_112 () ;
#endif
F_113 () ;
}
