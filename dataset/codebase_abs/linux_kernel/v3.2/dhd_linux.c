static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
while ( V_5 < V_6 ) {
if ( V_2 -> V_7 [ V_5 ] && V_2 -> V_7 [ V_5 ] -> V_4 == V_4 )
return V_5 ;
V_5 ++ ;
}
return V_8 ;
}
int F_2 ( struct V_1 * V_2 , char * V_9 )
{
int V_5 = V_6 ;
struct V_10 * V_11 ;
if ( V_9 == NULL || * V_9 == '\0' )
return 0 ;
while ( -- V_5 > 0 ) {
V_11 = V_2 -> V_7 [ V_5 ] ;
if ( V_11 && ! strncmp ( V_11 -> V_4 -> V_9 , V_9 , V_12 ) )
break;
}
F_3 ( V_13 , L_1 , V_5 , V_9 ) ;
return V_5 ;
}
char * F_4 ( struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
if ( V_16 < 0 || V_16 >= V_6 ) {
F_3 ( ERROR , L_2 , V_16 ) ;
return L_3 ;
}
if ( V_2 -> V_7 [ V_16 ] == NULL ) {
F_3 ( ERROR , L_4 , V_16 ) ;
return L_5 ;
}
if ( V_2 -> V_7 [ V_16 ] -> V_4 )
return V_2 -> V_7 [ V_16 ] -> V_4 -> V_9 ;
return L_6 ;
}
static void F_5 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_20 * V_21 ;
T_1 V_22 , V_23 ;
T_2 V_24 ;
T_2 V_25 ;
struct V_26 V_27 ;
char * V_28 , * V_29 ;
T_3 V_30 ;
int V_31 ;
struct V_1 * V_2 = F_6 ( V_19 , struct V_1 ,
V_32 ) ;
V_4 = V_2 -> V_7 [ 0 ] -> V_4 ;
V_23 = F_7 ( V_4 ) ;
V_22 = ( V_4 -> V_33 & V_34 ) ? true : false ;
V_30 = sizeof( L_7 ) + sizeof( V_23 ) + ( V_23 * V_35 ) ;
V_29 = V_28 = F_8 ( V_30 , V_36 ) ;
if ( ! V_29 )
return;
strcpy ( V_29 , L_7 ) ;
V_29 += strlen ( L_7 ) + 1 ;
V_24 = F_9 ( V_23 ) ;
memcpy ( V_29 , & V_24 , sizeof( V_23 ) ) ;
V_29 += sizeof( V_24 ) ;
F_10 (ha, ndev) {
if ( ! V_23 )
break;
memcpy ( V_29 , V_21 -> V_37 , V_35 ) ;
V_29 += V_35 ;
V_23 -- ;
}
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_39 ;
V_27 . V_28 = V_28 ;
V_27 . V_40 = V_30 ;
V_27 . V_41 = true ;
V_31 = F_11 ( & V_2 -> V_42 , 0 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 ) {
F_3 ( ERROR , L_8 ,
F_4 ( & V_2 -> V_42 , 0 ) , V_23 ) ;
V_22 = V_23 ? true : V_22 ;
}
F_12 ( V_28 ) ;
V_30 = sizeof( L_9 ) + sizeof( V_22 ) ;
V_28 = F_8 ( V_30 , V_36 ) ;
if ( ! V_28 )
return;
V_25 = F_9 ( V_22 ) ;
if ( ! F_13
( L_9 , ( void * ) & V_25 ,
sizeof( V_25 ) , V_28 , V_30 ) ) {
F_3 ( ERROR , L_10 ,
F_4 ( & V_2 -> V_42 , 0 ) ,
( int ) sizeof( V_22 ) , V_30 ) ;
F_12 ( V_28 ) ;
return;
}
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_39 ;
V_27 . V_28 = V_28 ;
V_27 . V_40 = V_30 ;
V_27 . V_41 = true ;
V_31 = F_11 ( & V_2 -> V_42 , 0 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 ) {
F_3 ( ERROR , L_11 ,
F_4 ( & V_2 -> V_42 , 0 ) ,
F_14 ( V_25 ) ) ;
}
F_12 ( V_28 ) ;
V_22 = ( V_4 -> V_33 & V_43 ) ? true : false ;
V_25 = F_9 ( V_22 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_44 ;
V_27 . V_28 = & V_25 ;
V_27 . V_40 = sizeof( V_25 ) ;
V_27 . V_41 = true ;
V_31 = F_11 ( & V_2 -> V_42 , 0 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 ) {
F_3 ( ERROR , L_12 ,
F_4 ( & V_2 -> V_42 , 0 ) ,
F_14 ( V_25 ) ) ;
}
}
static void
F_15 ( struct V_18 * V_19 )
{
char V_28 [ 32 ] ;
struct V_26 V_27 ;
int V_31 ;
struct V_1 * V_2 = F_6 ( V_19 , struct V_1 ,
V_45 ) ;
F_3 ( V_13 , L_13 ) ;
if ( ! F_13 ( L_14 , ( char * ) V_2 -> V_46 ,
V_35 , V_28 , 32 ) ) {
F_3 ( ERROR , L_15 ,
F_4 ( & V_2 -> V_42 , 0 ) ) ;
return;
}
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_39 ;
V_27 . V_28 = V_28 ;
V_27 . V_40 = 32 ;
V_27 . V_41 = true ;
V_31 = F_11 ( & V_2 -> V_42 , 0 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 )
F_3 ( ERROR , L_16 ,
F_4 ( & V_2 -> V_42 , 0 ) ) ;
else
memcpy ( V_2 -> V_7 [ 0 ] -> V_4 -> V_47 ,
V_2 -> V_46 , V_35 ) ;
return;
}
static int F_16 ( struct V_3 * V_4 , void * V_37 )
{
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
struct V_48 * V_49 = (struct V_48 * ) V_37 ;
int V_16 ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 == V_8 )
return - 1 ;
memcpy ( & V_2 -> V_46 , V_49 -> V_50 , V_35 ) ;
F_18 ( & V_2 -> V_45 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
int V_16 ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 == V_8 )
return;
F_18 ( & V_2 -> V_32 ) ;
}
int F_20 ( struct V_14 * V_15 , int V_16 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
if ( ! V_15 -> V_53 || ( V_15 -> V_54 == V_55 ) )
return - V_56 ;
if ( V_52 -> V_40 >= V_35 ) {
T_4 * V_57 = ( T_4 * ) ( V_52 -> V_58 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_57 ;
if ( F_21 ( V_60 -> V_61 ) )
V_15 -> V_62 ++ ;
if ( F_22 ( V_60 -> V_63 ) == V_64 )
F_23 ( & V_2 -> V_65 ) ;
}
F_24 ( V_15 , V_16 , V_52 ) ;
return F_25 ( V_15 -> V_66 , V_52 ) ;
}
static int F_26 ( struct V_51 * V_67 , struct V_3 * V_4 )
{
int V_31 ;
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
int V_16 ;
F_3 ( V_13 , L_17 ) ;
if ( ! V_2 -> V_42 . V_53 || ( V_2 -> V_42 . V_54 == V_55 ) ) {
F_3 ( ERROR , L_18 ,
V_2 -> V_42 . V_53 , V_2 -> V_42 . V_54 ) ;
F_27 ( V_4 ) ;
return - V_56 ;
}
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 == V_8 ) {
F_3 ( ERROR , L_19 , V_16 ) ;
F_27 ( V_4 ) ;
return - V_56 ;
}
if ( F_28 ( V_67 ) < V_2 -> V_42 . V_68 ) {
struct V_51 * V_69 ;
F_3 ( V_70 , L_20 ,
F_4 ( & V_2 -> V_42 , V_16 ) ) ;
V_2 -> V_42 . V_71 ++ ;
V_69 = F_29 ( V_67 , V_2 -> V_42 . V_68 ) ;
F_30 ( V_67 ) ;
V_67 = V_69 ;
if ( V_67 == NULL ) {
F_3 ( ERROR , L_21 ,
F_4 ( & V_2 -> V_42 , V_16 ) ) ;
V_31 = - V_72 ;
goto V_73;
}
}
V_31 = F_20 ( & V_2 -> V_42 , V_16 , V_67 ) ;
V_73:
if ( V_31 )
V_2 -> V_42 . V_74 . V_75 ++ ;
else
V_2 -> V_42 . V_76 ++ ;
return 0 ;
}
void F_31 ( struct V_14 * V_15 , int V_16 , bool V_77 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = V_15 -> V_17 ;
F_3 ( V_13 , L_17 ) ;
V_15 -> V_78 = V_77 ;
V_4 = V_2 -> V_7 [ V_16 ] -> V_4 ;
if ( V_77 == V_79 )
F_27 ( V_4 ) ;
else
F_32 ( V_4 ) ;
}
static int F_33 ( struct V_1 * V_2 , int * V_16 ,
void * V_57 , struct V_80 * V_81 ,
void * * V_58 )
{
int V_82 = 0 ;
V_82 = F_34 ( V_2 , V_16 , V_57 , V_81 , V_58 ) ;
if ( V_82 != 0 )
return V_82 ;
if ( V_2 -> V_7 [ * V_16 ] -> V_4 )
F_35 ( V_2 -> V_7 [ * V_16 ] -> V_4 ,
V_81 , * V_58 ) ;
return V_82 ;
}
void F_36 ( struct V_14 * V_15 , int V_16 , struct V_51 * V_67 ,
int V_83 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
unsigned char * V_84 ;
T_3 V_40 ;
void * V_58 ;
struct V_51 * V_85 , * V_86 ;
int V_5 ;
struct V_10 * V_11 ;
struct V_80 V_81 ;
F_3 ( V_13 , L_17 ) ;
V_86 = V_67 ;
for ( V_5 = 0 ; V_67 && V_5 < V_83 ; V_5 ++ , V_67 = V_85 ) {
V_85 = V_67 -> V_87 ;
V_67 -> V_87 = NULL ;
V_84 = V_67 -> V_58 ;
V_40 = V_67 -> V_40 ;
V_11 = V_2 -> V_7 [ V_16 ] ;
if ( V_11 == NULL )
V_11 = V_2 -> V_7 [ 0 ] ;
V_67 -> V_88 = V_11 -> V_4 ;
V_67 -> V_89 = F_37 ( V_67 , V_67 -> V_88 ) ;
if ( V_67 -> V_90 == V_91 )
V_2 -> V_42 . V_92 ++ ;
V_67 -> V_58 = V_84 ;
V_67 -> V_40 = V_40 ;
F_38 ( V_67 , V_93 ) ;
if ( F_22 ( V_67 -> V_89 ) == V_94 )
F_33 ( V_2 , & V_16 ,
F_39 ( V_67 ) ,
& V_81 , & V_58 ) ;
if ( V_2 -> V_7 [ V_16 ] &&
! V_2 -> V_7 [ V_16 ] -> V_77 )
V_11 = V_2 -> V_7 [ V_16 ] ;
if ( V_11 -> V_4 )
V_11 -> V_4 -> V_95 = V_96 ;
V_15 -> V_74 . V_97 += V_67 -> V_40 ;
V_15 -> V_98 ++ ;
if ( F_40 () )
F_41 ( V_67 ) ;
else
F_42 ( V_67 ) ;
}
}
void F_43 ( struct V_14 * V_15 , struct V_51 * V_99 , bool V_100 )
{
T_3 V_16 ;
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_59 * V_60 ;
T_5 type ;
F_44 ( V_15 , & V_16 , V_99 ) ;
V_60 = (struct V_59 * ) ( V_99 -> V_58 ) ;
type = F_22 ( V_60 -> V_63 ) ;
if ( type == V_64 )
F_45 ( & V_2 -> V_65 ) ;
}
static struct V_101 * F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
struct V_10 * V_11 ;
int V_16 ;
F_3 ( V_13 , L_17 ) ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 == V_8 )
return NULL ;
V_11 = V_2 -> V_7 [ V_16 ] ;
if ( V_2 -> V_42 . V_53 )
F_47 ( & V_2 -> V_42 ) ;
V_11 -> V_102 . V_98 = V_2 -> V_42 . V_74 . V_98 ;
V_11 -> V_102 . V_76 = V_2 -> V_42 . V_74 . V_76 ;
V_11 -> V_102 . V_97 = V_2 -> V_42 . V_74 . V_97 ;
V_11 -> V_102 . V_103 = V_2 -> V_42 . V_74 . V_103 ;
V_11 -> V_102 . V_104 = V_2 -> V_42 . V_74 . V_104 ;
V_11 -> V_102 . V_105 = V_2 -> V_42 . V_74 . V_105 ;
V_11 -> V_102 . V_106 = V_2 -> V_42 . V_74 . V_106 ;
V_11 -> V_102 . V_75 = V_2 -> V_42 . V_74 . V_75 ;
V_11 -> V_102 . V_107 = V_2 -> V_42 . V_74 . V_107 ;
return & V_11 -> V_102 ;
}
static int F_48 ( struct V_1 * V_2 , int V_16 , T_1 * V_108 )
{
struct V_26 V_27 ;
T_2 V_109 ;
char V_28 [ 32 ] ;
int V_31 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_110 ;
V_27 . V_28 = V_28 ;
V_27 . V_40 = ( T_3 ) sizeof( V_28 ) ;
V_27 . V_41 = false ;
strcpy ( V_28 , L_22 ) ;
V_31 = F_11 ( & V_2 -> V_42 , V_16 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 ) {
if ( V_31 == - V_111 ) {
F_3 ( ERROR , L_23 ,
F_4 ( & V_2 -> V_42 , V_16 ) ) ;
return - V_112 ;
}
F_3 ( V_70 , L_24 ,
F_4 ( & V_2 -> V_42 , V_16 ) , V_31 ) ;
return V_31 ;
}
memcpy ( & V_109 , V_28 , sizeof( T_1 ) ) ;
* V_108 = F_14 ( V_109 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_16 , T_1 V_108 )
{
struct V_26 V_27 ;
char V_28 [ 32 ] ;
int V_31 ;
T_2 V_109 = F_9 ( V_108 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_39 ;
V_27 . V_28 = V_28 ;
V_27 . V_40 = ( T_3 ) sizeof( V_28 ) ;
V_27 . V_41 = true ;
strcpy ( V_28 , L_22 ) ;
memcpy ( & V_28 [ sizeof( L_22 ) ] , & V_109 , sizeof( T_1 ) ) ;
V_31 = F_11 ( & V_2 -> V_42 , V_16 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 ) {
F_3 ( ERROR , L_25 ,
F_4 ( & V_2 -> V_42 , V_16 ) , V_31 ) ;
return V_31 ;
}
V_109 = F_9 ( V_108 != 0 ) ;
strcpy ( V_28 , L_26 ) ;
memcpy ( & V_28 [ sizeof( L_26 ) ] , & V_109 , sizeof( T_1 ) ) ;
V_31 = F_11 ( & V_2 -> V_42 , V_16 , & V_27 , V_27 . V_40 ) ;
if ( V_31 < 0 ) {
F_3 ( ERROR , L_27 ,
F_4 ( & V_2 -> V_42 , V_16 ) , V_31 ) ;
return V_31 ;
}
return 0 ;
}
static void F_50 ( struct V_3 * V_4 ,
struct V_113 * V_17 )
{
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
sprintf ( V_17 -> V_114 , V_115 ) ;
sprintf ( V_17 -> V_116 , L_28 , V_2 -> V_42 . V_117 ) ;
sprintf ( V_17 -> V_118 , L_29 , V_119 ) ;
sprintf ( V_17 -> V_120 , L_29 ,
F_51 ( F_52 ( V_2 -> V_42 . V_66 ) ) ) ;
}
static int F_53 ( struct V_1 * V_2 , void T_6 * V_121 )
{
struct V_113 V_17 ;
char V_122 [ sizeof( V_17 . V_114 ) ] ;
T_1 V_38 ;
struct V_123 V_124 ;
T_1 V_125 , V_126 ;
int V_31 ;
F_3 ( V_13 , L_17 ) ;
if ( F_54 ( & V_38 , V_121 , sizeof( T_1 ) ) )
return - V_127 ;
switch ( V_38 ) {
case V_128 :
if ( F_54 ( & V_17 , V_121 , sizeof( V_17 ) ) )
return - V_127 ;
strncpy ( V_122 , V_17 . V_114 , sizeof( V_17 . V_114 ) ) ;
V_122 [ sizeof( V_17 . V_114 ) - 1 ] = '\0' ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_38 = V_38 ;
if ( strcmp ( V_122 , L_30 ) == 0 ) {
sprintf ( V_17 . V_114 , L_31 ) ;
strcpy ( V_17 . V_116 , V_129 ) ;
}
else if ( ! V_2 -> V_42 . V_53 ) {
F_3 ( ERROR , L_32 ) ;
return - V_56 ;
}
else if ( V_2 -> V_42 . V_130 )
sprintf ( V_17 . V_114 , L_33 ) ;
else
sprintf ( V_17 . V_114 , L_34 ) ;
sprintf ( V_17 . V_116 , L_28 , V_2 -> V_42 . V_117 ) ;
if ( F_55 ( V_121 , & V_17 , sizeof( V_17 ) ) )
return - V_127 ;
F_3 ( V_131 , L_35 ,
( int ) sizeof( V_122 ) , V_122 , V_17 . V_114 ) ;
break;
case V_132 :
case V_133 :
V_31 = F_48 ( V_2 , 0 , & V_125 ) ;
if ( V_31 < 0 )
return V_31 ;
V_126 =
( V_38 == V_133 ) ? V_134 : V_135 ;
V_124 . V_38 = V_38 ;
V_124 . V_58 = ( V_125 & V_126 ) ? 1 : 0 ;
if ( F_55 ( V_121 , & V_124 , sizeof( V_124 ) ) )
return - V_127 ;
break;
case V_136 :
case V_137 :
if ( F_54 ( & V_124 , V_121 , sizeof( V_124 ) ) )
return - V_127 ;
V_31 = F_48 ( V_2 , 0 , & V_125 ) ;
if ( V_31 < 0 )
return V_31 ;
V_126 =
( V_38 == V_137 ) ? V_134 : V_135 ;
if ( V_124 . V_58 != 0 )
V_125 |= V_126 ;
else
V_125 &= ~ V_126 ;
V_31 = F_49 ( V_2 , 0 , V_125 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_38 == V_137 ) {
if ( V_124 . V_58 )
V_2 -> V_7 [ 0 ] -> V_4 -> V_138 |=
V_139 ;
else
V_2 -> V_7 [ 0 ] -> V_4 -> V_138 &=
~ V_139 ;
}
break;
default:
return - V_112 ;
}
return 0 ;
}
static int F_56 ( struct V_3 * V_4 , struct V_140 * V_141 ,
int V_38 )
{
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
int V_16 ;
V_16 = F_1 ( V_2 , V_4 ) ;
F_3 ( V_13 , L_36 , V_16 , V_38 ) ;
if ( V_16 == V_8 )
return - 1 ;
if ( V_38 == V_142 )
return F_53 ( V_2 , V_141 -> V_143 ) ;
return - V_112 ;
}
T_7 F_57 ( struct V_3 * V_4 , T_1 V_38 , void * V_144 , T_1 V_40 )
{
struct V_26 V_27 ;
T_7 V_145 = 0 ;
int V_30 = 0 ;
bool V_146 ;
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
int V_16 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_38 ;
V_27 . V_28 = V_144 ;
V_27 . V_40 = V_40 ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_27 . V_28 != NULL )
V_30 = F_58 ( T_3 , V_27 . V_40 , V_147 ) ;
if ( ( V_2 -> V_42 . V_54 != V_148 ) ) {
F_3 ( ERROR , L_37 ) ;
V_145 = - V_111 ;
goto V_73;
}
if ( ! V_2 -> V_42 . V_130 ) {
V_145 = - V_111 ;
goto V_73;
}
V_146 = ( ( V_27 . V_38 == V_149 ) ||
( ( V_27 . V_38 == V_39 ) &&
! ( strncmp ( L_38 , V_27 . V_28 , 9 ) ) ) ||
( ( V_27 . V_38 == V_39 ) &&
! ( strncmp ( L_39 , V_27 . V_28 , 15 ) ) ) ) ;
if ( V_146 )
F_59 ( V_4 ) ;
V_145 = F_11 ( & V_2 -> V_42 , V_16 , & V_27 , V_30 ) ;
V_73:
if ( V_145 > 0 )
V_145 = 0 ;
return V_145 ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = * (struct V_14 * * ) F_17 ( V_4 ) ;
F_3 ( V_13 , L_17 ) ;
F_61 ( V_15 -> V_150 ) ;
if ( V_15 -> V_53 == 0 )
return 0 ;
V_15 -> V_53 = 0 ;
F_27 ( V_4 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = * (struct V_1 * * )
F_17 ( V_4 ) ;
T_1 V_108 ;
int V_16 = F_1 ( V_2 , V_4 ) ;
T_7 V_31 = 0 ;
F_3 ( V_13 , L_40 , V_16 ) ;
if ( V_16 == 0 ) {
V_31 = F_63 ( & V_2 -> V_42 ) ;
if ( V_31 != 0 ) {
F_3 ( ERROR , L_41 , V_31 ) ;
return - 1 ;
}
F_64 ( & V_2 -> V_65 , 0 ) ;
memcpy ( V_4 -> V_47 , V_2 -> V_42 . V_151 , V_35 ) ;
if ( F_48 ( V_2 , V_16 , & V_108 ) >= 0
&& ( V_108 & V_134 ) != 0 )
V_2 -> V_7 [ V_16 ] -> V_4 -> V_138 |=
V_139 ;
else
V_2 -> V_7 [ V_16 ] -> V_4 -> V_138 &=
~ V_139 ;
}
F_65 ( V_4 ) ;
V_2 -> V_42 . V_53 = 1 ;
if ( F_66 ( V_2 -> V_42 . V_150 ) ) {
F_3 ( ERROR , L_42 ) ;
return - 1 ;
}
return V_31 ;
}
int
F_67 ( struct V_1 * V_2 , int V_16 , struct V_3 * V_4 ,
char * V_9 , T_4 * V_152 , T_1 V_33 , T_4 V_153 )
{
struct V_10 * V_11 ;
int V_31 = 0 , V_145 = 0 ;
F_3 ( V_13 , L_43 , V_16 , V_4 ) ;
V_11 = V_2 -> V_7 [ V_16 ] ;
if ( ! V_11 ) {
V_11 = F_8 ( sizeof( struct V_10 ) , V_36 ) ;
if ( ! V_11 )
return - V_72 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_17 = V_2 ;
V_2 -> V_7 [ V_16 ] = V_11 ;
if ( V_152 != NULL )
memcpy ( & V_11 -> V_152 , V_152 , V_35 ) ;
if ( V_4 == NULL ) {
V_11 -> V_77 = V_154 ;
V_11 -> V_155 = V_16 ;
if ( V_11 -> V_4 != NULL ) {
F_3 ( ERROR , L_44 ,
V_11 -> V_4 -> V_9 ) ;
F_27 ( V_11 -> V_4 ) ;
F_68 ( V_11 -> V_4 ) ;
F_69 ( V_11 -> V_4 ) ;
}
V_11 -> V_4 = F_70 ( sizeof( V_2 ) , L_45 ,
V_156 ) ;
if ( ! V_11 -> V_4 ) {
F_3 ( ERROR , L_46 ) ;
V_31 = - V_72 ;
}
if ( V_31 == 0 ) {
memcpy ( F_17 ( V_11 -> V_4 ) , & V_2 ,
sizeof( V_2 ) ) ;
V_145 = F_71 ( & V_2 -> V_42 , V_11 -> V_155 ) ;
if ( V_145 != 0 ) {
F_3 ( ERROR , L_47 ,
V_145 ) ;
V_31 = - V_112 ;
} else {
F_3 ( V_13 , L_48 ,
V_157 -> V_158 , V_11 -> V_4 -> V_9 ) ;
V_11 -> V_77 = 0 ;
}
}
if ( V_31 < 0 ) {
if ( V_11 -> V_4 )
F_69 ( V_11 -> V_4 ) ;
V_2 -> V_7 [ V_11 -> V_155 ] = NULL ;
F_12 ( V_11 ) ;
}
} else
V_11 -> V_4 = V_4 ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 , int V_16 )
{
struct V_10 * V_11 ;
F_3 ( V_13 , L_49 , V_16 ) ;
V_11 = V_2 -> V_7 [ V_16 ] ;
if ( ! V_11 ) {
F_3 ( ERROR , L_50 ) ;
return;
}
V_11 -> V_77 = V_159 ;
V_11 -> V_155 = V_16 ;
if ( V_11 -> V_4 != NULL ) {
F_27 ( V_11 -> V_4 ) ;
F_68 ( V_11 -> V_4 ) ;
F_69 ( V_11 -> V_4 ) ;
V_2 -> V_7 [ V_16 ] = NULL ;
F_12 ( V_11 ) ;
}
}
struct V_14 * F_73 ( struct V_160 * V_66 , T_3 V_161 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
F_3 ( V_13 , L_17 ) ;
V_4 = F_70 ( sizeof( V_2 ) , L_45 , V_156 ) ;
if ( ! V_4 ) {
F_3 ( ERROR , L_46 ) ;
goto V_162;
}
V_2 = F_74 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_2 )
goto V_162;
memcpy ( F_17 ( V_4 ) , & V_2 , sizeof( V_2 ) ) ;
if ( F_67 ( V_2 , 0 , V_4 , V_4 -> V_9 , NULL , 0 , 0 ) ==
V_8 )
goto V_162;
V_4 -> V_163 = NULL ;
F_75 ( & V_2 -> V_164 ) ;
V_2 -> V_42 . V_17 = V_2 ;
V_2 -> V_42 . V_66 = V_66 ;
V_2 -> V_42 . V_68 = V_161 ;
if ( F_76 ( & V_2 -> V_42 ) != 0 ) {
F_3 ( ERROR , L_51 ) ;
goto V_162;
}
V_2 -> V_42 . V_150 =
F_77 ( V_4 ,
F_52 ( V_66 ) ,
& V_2 -> V_42 ) ;
if ( V_2 -> V_42 . V_150 == NULL ) {
F_3 ( ERROR , L_52 ) ;
goto V_162;
}
F_78 ( & V_2 -> V_45 , F_15 ) ;
F_78 ( & V_2 -> V_32 , F_5 ) ;
memcpy ( F_17 ( V_4 ) , & V_2 , sizeof( V_2 ) ) ;
return & V_2 -> V_42 ;
V_162:
if ( V_4 )
F_69 ( V_4 ) ;
if ( V_2 )
F_79 ( & V_2 -> V_42 ) ;
return NULL ;
}
int F_63 ( struct V_14 * V_15 )
{
int V_31 = - 1 ;
struct V_1 * V_2 = V_15 -> V_17 ;
char V_165 [ V_166 + 12 ] ;
F_3 ( V_13 , L_53 ) ;
V_31 = F_80 ( & V_2 -> V_42 ) ;
if ( V_31 != 0 ) {
F_3 ( ERROR , L_54 , V_31 ) ;
return V_31 ;
}
if ( V_2 -> V_42 . V_54 != V_148 ) {
F_3 ( ERROR , L_55 ) ;
return - V_56 ;
}
F_13 ( L_56 , V_15 -> V_167 , V_166 ,
V_165 , sizeof( V_165 ) ) ;
F_81 ( V_15 , 0 , V_110 , V_165 ,
sizeof( V_165 ) ) ;
memcpy ( V_15 -> V_167 , V_165 , V_166 ) ;
F_82 ( V_15 -> V_167 , V_168 ) ;
F_82 ( V_15 -> V_167 , V_169 ) ;
F_82 ( V_15 -> V_167 , V_170 ) ;
F_82 ( V_15 -> V_167 , V_171 ) ;
F_82 ( V_15 -> V_167 , V_172 ) ;
F_82 ( V_15 -> V_167 , V_173 ) ;
F_82 ( V_15 -> V_167 , V_174 ) ;
F_82 ( V_15 -> V_167 , V_175 ) ;
F_82 ( V_15 -> V_167 , V_176 ) ;
F_82 ( V_15 -> V_167 , V_177 ) ;
F_82 ( V_15 -> V_167 , V_178 ) ;
F_82 ( V_15 -> V_167 , V_179 ) ;
F_82 ( V_15 -> V_167 , V_180 ) ;
F_82 ( V_15 -> V_167 , V_181 ) ;
F_82 ( V_15 -> V_167 , V_182 ) ;
F_82 ( V_15 -> V_167 , V_183 ) ;
F_82 ( V_15 -> V_167 , V_184 ) ;
F_82 ( V_15 -> V_167 , V_185 ) ;
V_15 -> V_186 = 1 ;
V_15 -> V_187 [ 0 ] = L_57 ;
V_31 = F_83 ( & V_2 -> V_42 ) ;
if ( V_31 < 0 )
return V_31 ;
return 0 ;
}
int F_71 ( struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_3 * V_4 ;
T_4 V_188 [ V_35 ] = {
0x00 , 0x90 , 0x4c , 0x11 , 0x22 , 0x33 } ;
F_3 ( V_13 , L_40 , V_16 ) ;
V_4 = V_2 -> V_7 [ V_16 ] -> V_4 ;
V_4 -> V_163 = & V_189 ;
if ( V_16 != 0 ) {
memcpy ( V_188 , V_2 -> V_42 . V_151 , V_35 ) ;
}
if ( V_16 == 1 ) {
F_3 ( V_13 , L_58 ) ;
V_188 [ 0 ] |= 0X02 ;
}
V_4 -> V_190 = V_93 + V_2 -> V_42 . V_68 ;
V_4 -> V_191 = & V_192 ;
V_2 -> V_42 . V_193 = V_4 -> V_194 + V_4 -> V_190 +
V_2 -> V_42 . V_68 ;
memcpy ( V_4 -> V_47 , V_188 , V_35 ) ;
if ( F_84 ( V_4 ) != 0 ) {
F_3 ( ERROR , L_59 ) ;
goto V_162;
}
F_3 ( V_70 , L_60 , V_4 -> V_9 ) ;
return 0 ;
V_162:
V_4 -> V_163 = NULL ;
return - V_195 ;
}
static void F_85 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
F_3 ( V_13 , L_17 ) ;
if ( V_15 ) {
V_2 = V_15 -> V_17 ;
if ( V_2 ) {
F_86 ( & V_2 -> V_42 ) ;
F_87 ( V_2 -> V_42 . V_66 ) ;
}
}
}
void F_79 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
F_3 ( V_13 , L_17 ) ;
if ( V_15 ) {
V_2 = V_15 -> V_17 ;
if ( V_2 ) {
struct V_10 * V_11 ;
int V_5 ;
for ( V_5 = 1 ; V_5 < V_6 ; V_5 ++ )
if ( V_2 -> V_7 [ V_5 ] )
F_72 ( V_2 , V_5 ) ;
V_11 = V_2 -> V_7 [ 0 ] ;
if ( V_11 -> V_4 -> V_163 == & V_189 ) {
F_88 () ;
F_60 ( V_11 -> V_4 ) ;
F_89 () ;
F_68 ( V_11 -> V_4 ) ;
}
F_90 ( & V_2 -> V_45 ) ;
F_90 ( & V_2 -> V_32 ) ;
F_85 ( V_15 ) ;
if ( V_15 -> V_196 )
F_91 ( V_15 ) ;
F_92 ( V_15 -> V_150 ) ;
F_69 ( V_11 -> V_4 ) ;
F_12 ( V_11 ) ;
F_12 ( V_2 ) ;
}
}
}
static void T_8 F_93 ( void )
{
F_3 ( V_13 , L_17 ) ;
F_94 () ;
}
static int T_9 F_95 ( void )
{
int error ;
F_3 ( V_13 , L_17 ) ;
error = F_96 () ;
if ( error ) {
F_3 ( ERROR , L_61 ) ;
goto V_197;
}
return 0 ;
V_197:
return - V_198 ;
}
int F_97 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
if ( V_2 ) {
F_98 ( & V_2 -> V_164 ) ;
return 1 ;
}
return 0 ;
}
int F_99 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
if ( V_2 ) {
F_100 ( & V_2 -> V_164 ) ;
return 1 ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
return F_102 ( & V_2 -> V_65 ) ;
}
int F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = * (struct V_1 * * ) F_17 ( V_4 ) ;
int V_199 = 10 * V_200 / 1000 ;
int V_201 = V_202 ;
int V_203 = F_101 ( V_2 ) ;
while ( V_201 && V_203 ) {
if ( V_203 ) {
F_103 ( V_204 ) ;
F_104 ( V_199 ) ;
F_103 ( V_205 ) ;
V_201 -- ;
}
V_203 = F_101 ( V_2 ) ;
}
return V_203 ;
}
int F_105 ( struct V_14 * V_15 , const T_4 * V_28 , int V_206 )
{
int V_31 = 0 ;
struct V_207 * V_208 ;
T_10 V_209 ;
T_11 V_210 = 0 ;
V_209 = F_106 () ;
F_107 ( V_211 ) ;
V_208 = F_108 ( L_62 , V_212 | V_213 , 0640 ) ;
if ( ! V_208 ) {
F_3 ( ERROR , L_63 ) ;
V_31 = - 1 ;
goto exit;
}
V_208 -> V_214 -> V_215 ( V_208 , ( char T_6 * ) V_28 , V_206 , & V_210 ) ;
exit:
F_12 ( V_28 ) ;
if ( V_208 )
F_109 ( V_208 , V_157 -> V_216 ) ;
F_107 ( V_209 ) ;
return V_31 ;
}
