int F_1 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 = V_5 ;
struct V_6 * V_7 ;
if ( V_3 == NULL || * V_3 == '\0' )
return 0 ;
while ( -- V_4 > 0 ) {
V_7 = V_2 -> V_8 [ V_4 ] ;
if ( V_7 && ! strncmp ( V_7 -> V_9 -> V_3 , V_3 , V_10 ) )
break;
}
F_2 ( V_11 , L_1 , V_4 , V_3 ) ;
return V_4 ;
}
char * F_3 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 < 0 || V_12 >= V_5 ) {
F_2 ( ERROR , L_2 , V_12 ) ;
return L_3 ;
}
if ( V_2 -> V_8 [ V_12 ] == NULL ) {
F_2 ( ERROR , L_4 , V_12 ) ;
return L_5 ;
}
if ( V_2 -> V_8 [ V_12 ] -> V_9 )
return V_2 -> V_8 [ V_12 ] -> V_9 -> V_3 ;
return L_6 ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_15 * V_9 ;
struct V_16 * V_17 ;
T_1 V_18 , V_19 ;
T_2 V_20 ;
T_2 V_21 ;
struct V_22 V_23 ;
char * V_24 , * V_25 ;
T_3 V_26 ;
int V_27 ;
struct V_1 * V_2 = F_5 ( V_14 , struct V_1 ,
V_28 ) ;
V_9 = V_2 -> V_8 [ 0 ] -> V_9 ;
V_19 = F_6 ( V_9 ) ;
V_18 = ( V_9 -> V_29 & V_30 ) ? true : false ;
V_26 = sizeof( L_7 ) + sizeof( V_19 ) + ( V_19 * V_31 ) ;
V_25 = V_24 = F_7 ( V_26 , V_32 ) ;
if ( ! V_25 )
return;
strcpy ( V_25 , L_7 ) ;
V_25 += strlen ( L_7 ) + 1 ;
V_20 = F_8 ( V_19 ) ;
memcpy ( V_25 , & V_20 , sizeof( V_19 ) ) ;
V_25 += sizeof( V_20 ) ;
F_9 (ha, ndev) {
if ( ! V_19 )
break;
memcpy ( V_25 , V_17 -> V_33 , V_31 ) ;
V_25 += V_31 ;
V_19 -- ;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_35 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = V_26 ;
V_23 . V_37 = true ;
V_27 = F_10 ( V_2 , 0 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_8 ,
F_3 ( V_2 , 0 ) , V_19 ) ;
V_18 = V_19 ? true : V_18 ;
}
F_11 ( V_24 ) ;
V_26 = sizeof( L_9 ) + sizeof( V_18 ) ;
V_24 = F_7 ( V_26 , V_32 ) ;
if ( ! V_24 )
return;
V_21 = F_8 ( V_18 ) ;
if ( ! F_12
( L_9 , ( void * ) & V_21 ,
sizeof( V_21 ) , V_24 , V_26 ) ) {
F_2 ( ERROR , L_10 ,
F_3 ( V_2 , 0 ) ,
( int ) sizeof( V_18 ) , V_26 ) ;
F_11 ( V_24 ) ;
return;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_35 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = V_26 ;
V_23 . V_37 = true ;
V_27 = F_10 ( V_2 , 0 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_11 ,
F_3 ( V_2 , 0 ) ,
F_13 ( V_21 ) ) ;
}
F_11 ( V_24 ) ;
V_18 = ( V_9 -> V_29 & V_38 ) ? true : false ;
V_21 = F_8 ( V_18 ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_39 ;
V_23 . V_24 = & V_21 ;
V_23 . V_36 = sizeof( V_21 ) ;
V_23 . V_37 = true ;
V_27 = F_10 ( V_2 , 0 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_12 ,
F_3 ( V_2 , 0 ) ,
F_13 ( V_21 ) ) ;
}
}
static void
F_14 ( struct V_13 * V_14 )
{
char V_24 [ 32 ] ;
struct V_22 V_23 ;
int V_27 ;
struct V_1 * V_2 = F_5 ( V_14 , struct V_1 ,
V_40 ) ;
F_2 ( V_11 , L_13 ) ;
if ( ! F_12 ( L_14 , ( char * ) V_2 -> V_41 ,
V_31 , V_24 , 32 ) ) {
F_2 ( ERROR , L_15 ,
F_3 ( V_2 , 0 ) ) ;
return;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_35 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = 32 ;
V_23 . V_37 = true ;
V_27 = F_10 ( V_2 , 0 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 )
F_2 ( ERROR , L_16 ,
F_3 ( V_2 , 0 ) ) ;
else
memcpy ( V_2 -> V_8 [ 0 ] -> V_9 -> V_42 ,
V_2 -> V_41 , V_31 ) ;
return;
}
static int F_15 ( struct V_15 * V_9 , void * V_33 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_43 * V_44 = (struct V_43 * ) V_33 ;
memcpy ( & V_2 -> V_41 , V_44 -> V_45 , V_31 ) ;
F_17 ( & V_2 -> V_40 ) ;
return 0 ;
}
static void F_18 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_17 ( & V_2 -> V_28 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_12 , struct V_46 * V_47 )
{
if ( ! V_2 -> V_48 -> V_49 || ( V_2 -> V_48 -> V_50 == V_51 ) )
return - V_52 ;
if ( V_47 -> V_36 >= V_31 ) {
T_4 * V_53 = ( T_4 * ) ( V_47 -> V_54 ) ;
struct V_55 * V_56 = (struct V_55 * ) V_53 ;
if ( F_20 ( V_56 -> V_57 ) )
V_2 -> V_58 ++ ;
if ( F_21 ( V_56 -> V_59 ) == V_60 )
F_22 ( & V_2 -> V_61 ) ;
}
F_23 ( V_2 , V_12 , V_47 ) ;
return V_2 -> V_48 -> V_62 ( V_2 -> V_63 , V_47 ) ;
}
static int F_24 ( struct V_46 * V_64 , struct V_15 * V_9 )
{
int V_27 ;
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
if ( ! V_2 -> V_48 -> V_49 ||
( V_2 -> V_48 -> V_50 == V_51 ) ) {
F_2 ( ERROR , L_18 ,
V_2 -> V_48 -> V_49 ,
V_2 -> V_48 -> V_50 ) ;
F_25 ( V_9 ) ;
return - V_52 ;
}
if ( ! V_2 -> V_8 [ V_7 -> V_65 ] ) {
F_2 ( ERROR , L_19 , V_7 -> V_65 ) ;
F_25 ( V_9 ) ;
return - V_52 ;
}
if ( F_26 ( V_64 ) < V_2 -> V_66 ) {
struct V_46 * V_67 ;
F_2 ( V_68 , L_20 ,
F_3 ( V_2 , V_7 -> V_65 ) ) ;
V_2 -> V_48 -> V_69 ++ ;
V_67 = F_27 ( V_64 , V_2 -> V_66 ) ;
F_28 ( V_64 ) ;
V_64 = V_67 ;
if ( V_64 == NULL ) {
F_2 ( ERROR , L_21 ,
F_3 ( V_2 , V_7 -> V_65 ) ) ;
V_27 = - V_70 ;
goto V_71;
}
}
V_27 = F_19 ( V_2 , V_7 -> V_65 , V_64 ) ;
V_71:
if ( V_27 )
V_2 -> V_48 -> V_72 . V_73 ++ ;
else
V_2 -> V_48 -> V_72 . V_74 ++ ;
return 0 ;
}
void F_29 ( struct V_75 * V_63 , int V_12 , bool V_50 )
{
struct V_15 * V_9 ;
struct V_76 * V_48 = F_30 ( V_63 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
V_9 = V_2 -> V_8 [ V_12 ] -> V_9 ;
if ( V_50 == V_77 )
F_25 ( V_9 ) ;
else
F_31 ( V_9 ) ;
}
static int F_32 ( struct V_1 * V_2 , int * V_12 ,
void * V_53 , struct V_78 * V_79 ,
void * * V_54 )
{
int V_80 = 0 ;
V_80 = F_33 ( V_2 , V_12 , V_53 , V_79 , V_54 ) ;
if ( V_80 != 0 )
return V_80 ;
if ( V_2 -> V_8 [ * V_12 ] -> V_9 )
F_34 ( V_2 -> V_8 [ * V_12 ] -> V_9 ,
V_79 , * V_54 ) ;
return V_80 ;
}
void F_35 ( struct V_75 * V_63 , int V_12 ,
struct V_81 * V_82 )
{
unsigned char * V_83 ;
T_3 V_36 ;
void * V_54 ;
struct V_46 * V_64 , * V_84 ;
struct V_6 * V_7 ;
struct V_78 V_79 ;
struct V_76 * V_48 = F_30 ( V_63 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
F_36 (skb_list, skb, pnext) {
F_37 ( V_64 , V_82 ) ;
V_83 = V_64 -> V_54 ;
V_36 = V_64 -> V_36 ;
V_7 = V_2 -> V_8 [ V_12 ] ;
if ( V_7 == NULL )
V_7 = V_2 -> V_8 [ 0 ] ;
if ( ! V_7 || ! V_7 -> V_9 ||
V_7 -> V_9 -> V_85 != V_86 ) {
F_38 ( V_64 ) ;
continue;
}
V_64 -> V_63 = V_7 -> V_9 ;
V_64 -> V_87 = F_39 ( V_64 , V_64 -> V_63 ) ;
if ( V_64 -> V_88 == V_89 )
V_48 -> V_72 . V_90 ++ ;
V_64 -> V_54 = V_83 ;
V_64 -> V_36 = V_36 ;
F_40 ( V_64 , V_91 ) ;
if ( F_21 ( V_64 -> V_87 ) == V_92 )
F_32 ( V_2 , & V_12 ,
F_41 ( V_64 ) ,
& V_79 , & V_54 ) ;
if ( V_2 -> V_8 [ V_12 ] ) {
V_7 = V_2 -> V_8 [ V_12 ] ;
V_7 -> V_9 -> V_93 = V_94 ;
}
V_48 -> V_72 . V_95 += V_64 -> V_36 ;
V_48 -> V_72 . V_96 ++ ;
if ( F_42 () )
F_43 ( V_64 ) ;
else
F_44 ( V_64 ) ;
}
}
void F_45 ( struct V_75 * V_63 , struct V_46 * V_97 , bool V_98 )
{
T_3 V_12 ;
struct V_55 * V_56 ;
T_5 type ;
struct V_76 * V_48 = F_30 ( V_63 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_46 ( V_63 , & V_12 , V_97 ) ;
V_56 = (struct V_55 * ) ( V_97 -> V_54 ) ;
type = F_21 ( V_56 -> V_59 ) ;
if ( type == V_60 )
F_47 ( & V_2 -> V_61 ) ;
}
static struct V_99 * F_48 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_76 * V_48 = V_7 -> V_2 -> V_48 ;
F_2 ( V_11 , L_17 ) ;
V_7 -> V_100 . V_96 = V_48 -> V_72 . V_96 ;
V_7 -> V_100 . V_74 = V_48 -> V_72 . V_74 ;
V_7 -> V_100 . V_95 = V_48 -> V_72 . V_95 ;
V_7 -> V_100 . V_101 = V_48 -> V_72 . V_101 ;
V_7 -> V_100 . V_102 = V_48 -> V_72 . V_102 ;
V_7 -> V_100 . V_103 = V_48 -> V_72 . V_103 ;
V_7 -> V_100 . V_104 = V_48 -> V_72 . V_104 ;
V_7 -> V_100 . V_73 = V_48 -> V_72 . V_73 ;
V_7 -> V_100 . V_90 = V_48 -> V_72 . V_90 ;
return & V_7 -> V_100 ;
}
static int F_49 ( struct V_1 * V_2 , int V_12 , T_1 * V_105 )
{
struct V_22 V_23 ;
T_2 V_106 ;
char V_24 [ 32 ] ;
int V_27 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_107 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = ( T_3 ) sizeof( V_24 ) ;
V_23 . V_37 = false ;
strcpy ( V_24 , L_22 ) ;
V_27 = F_10 ( V_2 , V_12 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
if ( V_27 == - V_108 ) {
F_2 ( ERROR , L_23 ,
F_3 ( V_2 , V_12 ) ) ;
return - V_109 ;
}
F_2 ( V_68 , L_24 ,
F_3 ( V_2 , V_12 ) , V_27 ) ;
return V_27 ;
}
memcpy ( & V_106 , V_24 , sizeof( T_1 ) ) ;
* V_105 = F_13 ( V_106 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_12 , T_1 V_105 )
{
struct V_22 V_23 ;
char V_24 [ 32 ] ;
int V_27 ;
T_2 V_106 = F_8 ( V_105 ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_35 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = ( T_3 ) sizeof( V_24 ) ;
V_23 . V_37 = true ;
strcpy ( V_24 , L_22 ) ;
memcpy ( & V_24 [ sizeof( L_22 ) ] , & V_106 , sizeof( T_1 ) ) ;
V_27 = F_10 ( V_2 , V_12 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_25 ,
F_3 ( V_2 , V_12 ) , V_27 ) ;
return V_27 ;
}
V_106 = F_8 ( V_105 != 0 ) ;
strcpy ( V_24 , L_26 ) ;
memcpy ( & V_24 [ sizeof( L_26 ) ] , & V_106 , sizeof( T_1 ) ) ;
V_27 = F_10 ( V_2 , V_12 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_27 ,
F_3 ( V_2 , V_12 ) , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static void F_51 ( struct V_15 * V_9 ,
struct V_110 * V_111 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
sprintf ( V_111 -> V_112 , V_113 ) ;
sprintf ( V_111 -> V_114 , L_28 , V_2 -> V_115 ) ;
sprintf ( V_111 -> V_116 , L_29 , F_52 ( V_2 -> V_63 ) ) ;
}
static int F_53 ( struct V_1 * V_2 , void T_6 * V_117 )
{
struct V_110 V_111 ;
char V_118 [ sizeof( V_111 . V_112 ) ] ;
T_1 V_34 ;
struct V_119 V_120 ;
T_1 V_121 , V_122 ;
int V_27 ;
F_2 ( V_11 , L_17 ) ;
if ( F_54 ( & V_34 , V_117 , sizeof( T_1 ) ) )
return - V_123 ;
switch ( V_34 ) {
case V_124 :
if ( F_54 ( & V_111 , V_117 , sizeof( V_111 ) ) )
return - V_123 ;
strncpy ( V_118 , V_111 . V_112 , sizeof( V_111 . V_112 ) ) ;
V_118 [ sizeof( V_111 . V_112 ) - 1 ] = '\0' ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_34 = V_34 ;
if ( strcmp ( V_118 , L_30 ) == 0 ) {
sprintf ( V_111 . V_112 , L_31 ) ;
strcpy ( V_111 . V_114 , V_125 ) ;
}
else if ( ! V_2 -> V_48 -> V_49 ) {
F_2 ( ERROR , L_32 ) ;
return - V_52 ;
}
else if ( V_2 -> V_126 )
sprintf ( V_111 . V_112 , L_33 ) ;
else
sprintf ( V_111 . V_112 , L_34 ) ;
sprintf ( V_111 . V_114 , L_28 , V_2 -> V_115 ) ;
if ( F_55 ( V_117 , & V_111 , sizeof( V_111 ) ) )
return - V_123 ;
F_2 ( V_127 , L_35 ,
( int ) sizeof( V_118 ) , V_118 , V_111 . V_112 ) ;
break;
case V_128 :
case V_129 :
V_27 = F_49 ( V_2 , 0 , & V_121 ) ;
if ( V_27 < 0 )
return V_27 ;
V_122 =
( V_34 == V_129 ) ? V_130 : V_131 ;
V_120 . V_34 = V_34 ;
V_120 . V_54 = ( V_121 & V_122 ) ? 1 : 0 ;
if ( F_55 ( V_117 , & V_120 , sizeof( V_120 ) ) )
return - V_123 ;
break;
case V_132 :
case V_133 :
if ( F_54 ( & V_120 , V_117 , sizeof( V_120 ) ) )
return - V_123 ;
V_27 = F_49 ( V_2 , 0 , & V_121 ) ;
if ( V_27 < 0 )
return V_27 ;
V_122 =
( V_34 == V_133 ) ? V_130 : V_131 ;
if ( V_120 . V_54 != 0 )
V_121 |= V_122 ;
else
V_121 &= ~ V_122 ;
V_27 = F_50 ( V_2 , 0 , V_121 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_34 == V_133 ) {
if ( V_120 . V_54 )
V_2 -> V_8 [ 0 ] -> V_9 -> V_134 |=
V_135 ;
else
V_2 -> V_8 [ 0 ] -> V_9 -> V_134 &=
~ V_135 ;
}
break;
default:
return - V_109 ;
}
return 0 ;
}
static int F_56 ( struct V_15 * V_9 , struct V_136 * V_137 ,
int V_34 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_2 ( V_11 , L_36 , V_7 -> V_65 , V_34 ) ;
if ( ! V_2 -> V_8 [ V_7 -> V_65 ] )
return - 1 ;
if ( V_34 == V_138 )
return F_53 ( V_2 , V_137 -> V_139 ) ;
return - V_109 ;
}
T_7 F_57 ( struct V_15 * V_9 , T_1 V_34 , void * V_140 , T_1 V_36 )
{
struct V_22 V_23 ;
T_7 V_141 = 0 ;
int V_26 = 0 ;
bool V_142 ;
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_34 ;
V_23 . V_24 = V_140 ;
V_23 . V_36 = V_36 ;
if ( V_23 . V_24 != NULL )
V_26 = F_58 ( T_3 , V_23 . V_36 , V_143 ) ;
if ( ( V_2 -> V_48 -> V_50 != V_144 ) ) {
F_2 ( ERROR , L_37 ) ;
V_141 = - V_108 ;
goto V_71;
}
if ( ! V_2 -> V_126 ) {
V_141 = - V_108 ;
goto V_71;
}
V_142 = ( ( V_23 . V_34 == V_145 ) ||
( ( V_23 . V_34 == V_35 ) &&
! ( strncmp ( L_38 , V_23 . V_24 , 9 ) ) ) ||
( ( V_23 . V_34 == V_35 ) &&
! ( strncmp ( L_39 , V_23 . V_24 , 15 ) ) ) ) ;
if ( V_142 )
F_59 ( V_9 ) ;
V_141 = F_10 ( V_2 , V_7 -> V_65 , & V_23 , V_26 ) ;
V_71:
if ( V_141 > 0 )
V_141 = 0 ;
return V_141 ;
}
static int F_60 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
F_61 ( V_2 -> V_146 ) ;
if ( V_2 -> V_48 -> V_49 == 0 )
return 0 ;
V_2 -> V_48 -> V_49 = false ;
F_25 ( V_9 ) ;
return 0 ;
}
static int F_62 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_76 * V_48 = V_2 -> V_48 ;
T_1 V_105 ;
T_7 V_27 = 0 ;
T_3 V_147 = 0 ;
F_2 ( V_11 , L_40 , V_7 -> V_65 ) ;
if ( V_7 -> V_65 == 0 ) {
if ( V_48 -> V_50 != V_144 ) {
F_2 ( ERROR , L_41 ) ;
return - V_148 ;
}
F_63 ( & V_2 -> V_61 , 0 ) ;
memcpy ( V_9 -> V_42 , V_2 -> V_149 , V_31 ) ;
if ( F_49 ( V_2 , V_7 -> V_65 , & V_105 ) >= 0
&& ( V_105 & V_130 ) != 0 )
V_2 -> V_8 [ V_7 -> V_65 ] -> V_9 -> V_134 |=
V_135 ;
else
V_2 -> V_8 [ V_7 -> V_65 ] -> V_9 -> V_134 &=
~ V_135 ;
}
F_64 ( V_2 , 0 , V_150 , ( char * ) & V_147 , sizeof( V_147 ) ) ;
F_65 ( V_9 ) ;
V_2 -> V_48 -> V_49 = true ;
if ( F_66 ( V_2 -> V_146 ) ) {
F_2 ( ERROR , L_42 ) ;
return - 1 ;
}
return V_27 ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_15 * V_9 ;
T_4 V_151 [ V_31 ] ;
F_2 ( V_11 , L_40 , V_7 -> V_65 ) ;
V_9 = V_2 -> V_8 [ V_7 -> V_65 ] -> V_9 ;
V_9 -> V_152 = & V_153 ;
if ( F_68 ( V_7 -> V_154 ) )
memcpy ( V_151 , V_7 -> V_154 , V_31 ) ;
else
memcpy ( V_151 , V_2 -> V_149 , V_31 ) ;
if ( V_7 -> V_65 == 1 ) {
F_2 ( V_11 , L_43 ) ;
V_151 [ 0 ] |= 0X02 ;
}
V_9 -> V_155 = V_91 + V_2 -> V_66 ;
V_9 -> V_156 = & V_157 ;
V_2 -> V_158 = V_9 -> V_159 + V_9 -> V_155 +
V_2 -> V_66 ;
memcpy ( V_9 -> V_42 , V_151 , V_31 ) ;
if ( ! V_7 -> V_65 ) {
V_2 -> V_146 = F_69 ( V_9 , V_2 -> V_63 , V_2 ) ;
if ( V_2 -> V_146 == NULL ) {
F_2 ( ERROR , L_44 ) ;
goto V_160;
}
}
if ( F_70 ( V_9 ) != 0 ) {
F_2 ( ERROR , L_45 ) ;
goto V_160;
}
F_2 ( V_68 , L_46 , V_9 -> V_3 ) ;
return 0 ;
V_160:
V_9 -> V_152 = NULL ;
return - V_161 ;
}
int
F_71 ( struct V_75 * V_63 , int V_12 , char * V_3 , T_4 * V_154 )
{
struct V_6 * V_7 ;
struct V_15 * V_9 ;
struct V_76 * V_48 = F_30 ( V_63 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_47 , V_12 ) ;
V_7 = V_2 -> V_8 [ V_12 ] ;
if ( V_7 ) {
F_2 ( ERROR , L_48 ,
V_7 -> V_9 -> V_3 ) ;
F_25 ( V_7 -> V_9 ) ;
F_72 ( V_7 -> V_9 ) ;
F_73 ( V_7 -> V_9 ) ;
V_2 -> V_8 [ V_12 ] = NULL ;
}
V_9 = F_74 ( sizeof( struct V_6 ) , V_3 , V_162 ) ;
if ( ! V_9 ) {
F_2 ( ERROR , L_49 ) ;
return - V_70 ;
}
V_7 = F_16 ( V_9 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
V_2 -> V_8 [ V_12 ] = V_7 ;
V_7 -> V_65 = V_12 ;
if ( V_154 != NULL )
memcpy ( & V_7 -> V_154 , V_154 , V_31 ) ;
if ( F_67 ( V_7 ) ) {
F_2 ( ERROR , L_50 ) ;
F_73 ( V_7 -> V_9 ) ;
V_2 -> V_8 [ V_12 ] = NULL ;
return - V_109 ;
}
F_2 ( V_11 , L_51 ,
V_163 -> V_164 , V_7 -> V_9 -> V_3 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 , int V_12 )
{
struct V_6 * V_7 ;
F_2 ( V_11 , L_47 , V_12 ) ;
V_7 = V_2 -> V_8 [ V_12 ] ;
if ( ! V_7 ) {
F_2 ( ERROR , L_52 ) ;
return;
}
if ( V_7 -> V_9 ) {
if ( V_12 == 0 ) {
if ( V_7 -> V_9 -> V_152 == & V_153 ) {
F_76 () ;
F_60 ( V_7 -> V_9 ) ;
F_77 () ;
}
} else {
F_25 ( V_7 -> V_9 ) ;
}
F_72 ( V_7 -> V_9 ) ;
V_2 -> V_8 [ V_12 ] = NULL ;
if ( V_12 == 0 )
F_78 ( V_2 -> V_146 ) ;
F_73 ( V_7 -> V_9 ) ;
}
}
int F_79 ( T_3 V_165 , struct V_75 * V_63 )
{
struct V_1 * V_2 = NULL ;
int V_27 = 0 ;
F_2 ( V_11 , L_17 ) ;
V_2 = F_80 ( sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_2 )
return - V_70 ;
F_81 ( & V_2 -> V_166 ) ;
V_2 -> V_66 = V_165 ;
V_2 -> V_48 = F_30 ( V_63 ) ;
V_2 -> V_48 -> V_2 = V_2 ;
V_2 -> V_63 = V_63 ;
V_27 = F_82 ( V_2 ) ;
if ( V_27 != 0 ) {
F_2 ( ERROR , L_53 ) ;
goto V_160;
}
F_83 ( & V_2 -> V_40 , F_14 ) ;
F_83 ( & V_2 -> V_28 , F_4 ) ;
return V_27 ;
V_160:
F_84 ( V_63 ) ;
return V_27 ;
}
int F_85 ( struct V_75 * V_63 )
{
int V_27 = - 1 ;
char V_167 [ V_168 + 12 ] ;
struct V_76 * V_48 = F_30 ( V_63 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_54 ) ;
V_27 = V_48 -> V_169 ( V_63 ) ;
if ( V_27 != 0 ) {
F_2 ( ERROR , L_55 , V_27 ) ;
return V_27 ;
}
F_12 ( L_56 , V_2 -> V_170 , V_168 ,
V_167 , sizeof( V_167 ) ) ;
F_86 ( V_2 , 0 , V_107 , V_167 ,
sizeof( V_167 ) ) ;
memcpy ( V_2 -> V_170 , V_167 , V_168 ) ;
F_87 ( V_2 -> V_170 , V_171 ) ;
F_87 ( V_2 -> V_170 , V_172 ) ;
F_87 ( V_2 -> V_170 , V_173 ) ;
F_87 ( V_2 -> V_170 , V_174 ) ;
F_87 ( V_2 -> V_170 , V_175 ) ;
F_87 ( V_2 -> V_170 , V_176 ) ;
F_87 ( V_2 -> V_170 , V_177 ) ;
F_87 ( V_2 -> V_170 , V_178 ) ;
F_87 ( V_2 -> V_170 , V_179 ) ;
F_87 ( V_2 -> V_170 , V_180 ) ;
F_87 ( V_2 -> V_170 , V_181 ) ;
F_87 ( V_2 -> V_170 , V_182 ) ;
F_87 ( V_2 -> V_170 , V_183 ) ;
F_87 ( V_2 -> V_170 , V_184 ) ;
F_87 ( V_2 -> V_170 , V_185 ) ;
F_87 ( V_2 -> V_170 , V_186 ) ;
F_87 ( V_2 -> V_170 , V_187 ) ;
F_87 ( V_2 -> V_170 , V_188 ) ;
V_2 -> V_189 = 1 ;
V_2 -> V_190 [ 0 ] = L_57 ;
V_27 = F_88 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_71 ( V_63 , 0 , L_58 , V_2 -> V_149 ) ;
if ( V_27 < 0 )
return V_27 ;
V_48 -> V_50 = V_144 ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_2 ( V_11 , L_17 ) ;
if ( V_2 ) {
F_90 ( V_2 ) ;
V_2 -> V_48 -> V_191 ( V_2 -> V_63 ) ;
}
}
void F_84 ( struct V_75 * V_63 )
{
int V_4 ;
struct V_76 * V_48 = F_30 ( V_63 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
for ( V_4 = V_5 - 1 ; V_4 > - 1 ; V_4 -- )
if ( V_2 -> V_8 [ V_4 ] )
F_75 ( V_2 , V_4 ) ;
F_89 ( V_2 ) ;
if ( V_2 -> V_192 ) {
F_91 ( & V_2 -> V_40 ) ;
F_91 ( & V_2 -> V_28 ) ;
F_92 ( V_2 ) ;
}
V_48 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
return F_94 ( & V_2 -> V_61 ) ;
}
int F_59 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_193 = 10 * V_194 / 1000 ;
int V_195 = V_196 ;
int V_197 = F_93 ( V_2 ) ;
while ( V_195 && V_197 ) {
if ( V_197 ) {
F_95 ( V_198 ) ;
F_96 ( V_193 ) ;
F_95 ( V_199 ) ;
V_195 -- ;
}
V_197 = F_93 ( V_2 ) ;
}
return V_197 ;
}
int F_97 ( struct V_1 * V_2 , const T_4 * V_24 , int V_200 )
{
int V_27 = 0 ;
struct V_201 * V_202 ;
T_8 V_203 ;
T_9 V_204 = 0 ;
V_203 = F_98 () ;
F_99 ( V_205 ) ;
V_202 = F_100 ( L_59 , V_206 | V_207 , 0640 ) ;
if ( ! V_202 ) {
F_2 ( ERROR , L_60 ) ;
V_27 = - 1 ;
goto exit;
}
V_202 -> V_208 -> V_209 ( V_202 , ( char T_6 * ) V_24 , V_200 , & V_204 ) ;
exit:
F_11 ( V_24 ) ;
if ( V_202 )
F_101 ( V_202 , V_163 -> V_210 ) ;
F_99 ( V_203 ) ;
return V_27 ;
}
static void F_102 ( struct V_13 * V_14 )
{
#ifdef F_103
F_104 () ;
#endif
#ifdef F_105
F_106 () ;
#endif
}
static int T_10 F_107 ( void )
{
if ( ! F_17 ( & V_211 ) )
return - V_212 ;
return 0 ;
}
static void T_11 F_108 ( void )
{
F_91 ( & V_211 ) ;
#ifdef F_103
F_109 () ;
#endif
#ifdef F_105
F_110 () ;
#endif
}
