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
static int F_19 ( struct V_46 * V_47 , struct V_15 * V_9 )
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
F_20 ( V_9 ) ;
return - V_52 ;
}
if ( ! V_2 -> V_8 [ V_7 -> V_53 ] ) {
F_2 ( ERROR , L_19 , V_7 -> V_53 ) ;
F_20 ( V_9 ) ;
return - V_52 ;
}
if ( F_21 ( V_47 ) < V_2 -> V_54 ) {
struct V_46 * V_55 ;
F_2 ( V_56 , L_20 ,
F_3 ( V_2 , V_7 -> V_53 ) ) ;
V_2 -> V_48 -> V_57 ++ ;
V_55 = F_22 ( V_47 , V_2 -> V_54 ) ;
F_23 ( V_47 ) ;
V_47 = V_55 ;
if ( V_47 == NULL ) {
F_2 ( ERROR , L_21 ,
F_3 ( V_2 , V_7 -> V_53 ) ) ;
V_27 = - V_58 ;
goto V_59;
}
}
if ( V_47 -> V_36 >= V_31 ) {
T_4 * V_60 = ( T_4 * ) ( V_47 -> V_61 ) ;
struct V_62 * V_63 = (struct V_62 * ) V_60 ;
if ( F_24 ( V_63 -> V_64 ) )
V_2 -> V_65 ++ ;
if ( F_25 ( V_63 -> V_66 ) == V_67 )
F_26 ( & V_2 -> V_68 ) ;
}
F_27 ( V_2 , V_7 -> V_53 , V_47 ) ;
V_27 = V_2 -> V_48 -> V_69 ( V_2 -> V_70 , V_47 ) ;
V_59:
if ( V_27 )
V_2 -> V_48 -> V_71 . V_72 ++ ;
else
V_2 -> V_48 -> V_71 . V_73 ++ ;
return 0 ;
}
void F_28 ( struct V_74 * V_70 , bool V_50 )
{
struct V_15 * V_9 ;
struct V_75 * V_48 = F_29 ( V_70 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
int V_4 ;
F_2 ( V_11 , L_17 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
if ( V_2 -> V_8 [ V_4 ] ) {
V_9 = V_2 -> V_8 [ V_4 ] -> V_9 ;
if ( V_50 )
F_20 ( V_9 ) ;
else
F_30 ( V_9 ) ;
}
}
static int F_31 ( struct V_1 * V_2 , int * V_12 ,
void * V_60 , struct V_76 * V_77 ,
void * * V_61 )
{
int V_78 = 0 ;
V_78 = F_32 ( V_2 , V_12 , V_60 , V_77 , V_61 ) ;
if ( V_78 != 0 )
return V_78 ;
if ( V_2 -> V_8 [ * V_12 ] -> V_9 )
F_33 ( V_2 -> V_8 [ * V_12 ] -> V_9 ,
V_77 , * V_61 ) ;
return V_78 ;
}
void F_34 ( struct V_74 * V_70 , int V_12 ,
struct V_79 * V_80 )
{
unsigned char * V_81 ;
T_3 V_36 ;
void * V_61 ;
struct V_46 * V_47 , * V_82 ;
struct V_6 * V_7 ;
struct V_76 V_77 ;
struct V_75 * V_48 = F_29 ( V_70 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
F_35 (skb_list, skb, pnext) {
F_36 ( V_47 , V_80 ) ;
V_81 = V_47 -> V_61 ;
V_36 = V_47 -> V_36 ;
V_7 = V_2 -> V_8 [ V_12 ] ;
if ( V_7 == NULL )
V_7 = V_2 -> V_8 [ 0 ] ;
if ( ! V_7 || ! V_7 -> V_9 ||
V_7 -> V_9 -> V_83 != V_84 ) {
F_37 ( V_47 ) ;
continue;
}
V_47 -> V_70 = V_7 -> V_9 ;
V_47 -> V_85 = F_38 ( V_47 , V_47 -> V_70 ) ;
if ( V_47 -> V_86 == V_87 )
V_48 -> V_71 . V_88 ++ ;
V_47 -> V_61 = V_81 ;
V_47 -> V_36 = V_36 ;
F_39 ( V_47 , V_89 ) ;
if ( F_25 ( V_47 -> V_85 ) == V_90 )
F_31 ( V_2 , & V_12 ,
F_40 ( V_47 ) ,
& V_77 , & V_61 ) ;
if ( V_2 -> V_8 [ V_12 ] ) {
V_7 = V_2 -> V_8 [ V_12 ] ;
V_7 -> V_9 -> V_91 = V_92 ;
}
V_48 -> V_71 . V_93 += V_47 -> V_36 ;
V_48 -> V_71 . V_94 ++ ;
if ( F_41 () )
F_42 ( V_47 ) ;
else
F_43 ( V_47 ) ;
}
}
void F_44 ( struct V_74 * V_70 , struct V_46 * V_95 , bool V_96 )
{
T_3 V_12 ;
struct V_62 * V_63 ;
T_5 type ;
struct V_75 * V_48 = F_29 ( V_70 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_45 ( V_70 , & V_12 , V_95 ) ;
V_63 = (struct V_62 * ) ( V_95 -> V_61 ) ;
type = F_25 ( V_63 -> V_66 ) ;
if ( type == V_67 )
F_46 ( & V_2 -> V_68 ) ;
}
static struct V_97 * F_47 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_75 * V_48 = V_7 -> V_2 -> V_48 ;
F_2 ( V_11 , L_17 ) ;
V_7 -> V_98 . V_94 = V_48 -> V_71 . V_94 ;
V_7 -> V_98 . V_73 = V_48 -> V_71 . V_73 ;
V_7 -> V_98 . V_93 = V_48 -> V_71 . V_93 ;
V_7 -> V_98 . V_99 = V_48 -> V_71 . V_99 ;
V_7 -> V_98 . V_100 = V_48 -> V_71 . V_100 ;
V_7 -> V_98 . V_101 = V_48 -> V_71 . V_101 ;
V_7 -> V_98 . V_102 = V_48 -> V_71 . V_102 ;
V_7 -> V_98 . V_72 = V_48 -> V_71 . V_72 ;
V_7 -> V_98 . V_88 = V_48 -> V_71 . V_88 ;
return & V_7 -> V_98 ;
}
static int F_48 ( struct V_1 * V_2 , int V_12 , T_1 * V_103 )
{
struct V_22 V_23 ;
T_2 V_104 ;
char V_24 [ 32 ] ;
int V_27 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_105 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = ( T_3 ) sizeof( V_24 ) ;
V_23 . V_37 = false ;
strcpy ( V_24 , L_22 ) ;
V_27 = F_10 ( V_2 , V_12 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
if ( V_27 == - V_106 ) {
F_2 ( ERROR , L_23 ,
F_3 ( V_2 , V_12 ) ) ;
return - V_107 ;
}
F_2 ( V_56 , L_24 ,
F_3 ( V_2 , V_12 ) , V_27 ) ;
return V_27 ;
}
memcpy ( & V_104 , V_24 , sizeof( T_1 ) ) ;
* V_103 = F_13 ( V_104 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_12 , T_1 V_103 )
{
struct V_22 V_23 ;
char V_24 [ 32 ] ;
int V_27 ;
T_2 V_104 = F_8 ( V_103 ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_35 ;
V_23 . V_24 = V_24 ;
V_23 . V_36 = ( T_3 ) sizeof( V_24 ) ;
V_23 . V_37 = true ;
strcpy ( V_24 , L_22 ) ;
memcpy ( & V_24 [ sizeof( L_22 ) ] , & V_104 , sizeof( T_1 ) ) ;
V_27 = F_10 ( V_2 , V_12 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_25 ,
F_3 ( V_2 , V_12 ) , V_27 ) ;
return V_27 ;
}
V_104 = F_8 ( V_103 != 0 ) ;
strcpy ( V_24 , L_26 ) ;
memcpy ( & V_24 [ sizeof( L_26 ) ] , & V_104 , sizeof( T_1 ) ) ;
V_27 = F_10 ( V_2 , V_12 , & V_23 , V_23 . V_36 ) ;
if ( V_27 < 0 ) {
F_2 ( ERROR , L_27 ,
F_3 ( V_2 , V_12 ) , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static void F_50 ( struct V_15 * V_9 ,
struct V_108 * V_109 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
sprintf ( V_109 -> V_110 , V_111 ) ;
sprintf ( V_109 -> V_112 , L_28 , V_2 -> V_113 ) ;
sprintf ( V_109 -> V_114 , L_29 , F_51 ( V_2 -> V_70 ) ) ;
}
static int F_52 ( struct V_1 * V_2 , void T_6 * V_115 )
{
struct V_108 V_109 ;
char V_116 [ sizeof( V_109 . V_110 ) ] ;
T_1 V_34 ;
struct V_117 V_118 ;
T_1 V_119 , V_120 ;
int V_27 ;
F_2 ( V_11 , L_17 ) ;
if ( F_53 ( & V_34 , V_115 , sizeof( T_1 ) ) )
return - V_121 ;
switch ( V_34 ) {
case V_122 :
if ( F_53 ( & V_109 , V_115 , sizeof( V_109 ) ) )
return - V_121 ;
strncpy ( V_116 , V_109 . V_110 , sizeof( V_109 . V_110 ) ) ;
V_116 [ sizeof( V_109 . V_110 ) - 1 ] = '\0' ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_34 = V_34 ;
if ( strcmp ( V_116 , L_30 ) == 0 ) {
sprintf ( V_109 . V_110 , L_31 ) ;
strcpy ( V_109 . V_112 , V_123 ) ;
}
else if ( ! V_2 -> V_48 -> V_49 ) {
F_2 ( ERROR , L_32 ) ;
return - V_52 ;
}
else if ( V_2 -> V_124 )
sprintf ( V_109 . V_110 , L_33 ) ;
else
sprintf ( V_109 . V_110 , L_34 ) ;
sprintf ( V_109 . V_112 , L_28 , V_2 -> V_113 ) ;
if ( F_54 ( V_115 , & V_109 , sizeof( V_109 ) ) )
return - V_121 ;
F_2 ( V_125 , L_35 ,
( int ) sizeof( V_116 ) , V_116 , V_109 . V_110 ) ;
break;
case V_126 :
case V_127 :
V_27 = F_48 ( V_2 , 0 , & V_119 ) ;
if ( V_27 < 0 )
return V_27 ;
V_120 =
( V_34 == V_127 ) ? V_128 : V_129 ;
V_118 . V_34 = V_34 ;
V_118 . V_61 = ( V_119 & V_120 ) ? 1 : 0 ;
if ( F_54 ( V_115 , & V_118 , sizeof( V_118 ) ) )
return - V_121 ;
break;
case V_130 :
case V_131 :
if ( F_53 ( & V_118 , V_115 , sizeof( V_118 ) ) )
return - V_121 ;
V_27 = F_48 ( V_2 , 0 , & V_119 ) ;
if ( V_27 < 0 )
return V_27 ;
V_120 =
( V_34 == V_131 ) ? V_128 : V_129 ;
if ( V_118 . V_61 != 0 )
V_119 |= V_120 ;
else
V_119 &= ~ V_120 ;
V_27 = F_49 ( V_2 , 0 , V_119 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_34 == V_131 ) {
if ( V_118 . V_61 )
V_2 -> V_8 [ 0 ] -> V_9 -> V_132 |=
V_133 ;
else
V_2 -> V_8 [ 0 ] -> V_9 -> V_132 &=
~ V_133 ;
}
break;
default:
return - V_107 ;
}
return 0 ;
}
static int F_55 ( struct V_15 * V_9 , struct V_134 * V_135 ,
int V_34 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_2 ( V_11 , L_36 , V_7 -> V_53 , V_34 ) ;
if ( ! V_2 -> V_8 [ V_7 -> V_53 ] )
return - 1 ;
if ( V_34 == V_136 )
return F_52 ( V_2 , V_135 -> V_137 ) ;
return - V_107 ;
}
T_7 F_56 ( struct V_15 * V_9 , T_1 V_34 , void * V_138 , T_1 V_36 )
{
struct V_22 V_23 ;
T_7 V_139 = 0 ;
int V_26 = 0 ;
bool V_140 ;
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_34 = V_34 ;
V_23 . V_24 = V_138 ;
V_23 . V_36 = V_36 ;
if ( V_23 . V_24 != NULL )
V_26 = F_57 ( T_3 , V_23 . V_36 , V_141 ) ;
if ( ( V_2 -> V_48 -> V_50 != V_142 ) ) {
F_2 ( ERROR , L_37 ) ;
V_139 = - V_106 ;
goto V_59;
}
if ( ! V_2 -> V_124 ) {
V_139 = - V_106 ;
goto V_59;
}
V_140 = ( ( V_23 . V_34 == V_143 ) ||
( ( V_23 . V_34 == V_35 ) &&
! ( strncmp ( L_38 , V_23 . V_24 , 9 ) ) ) ||
( ( V_23 . V_34 == V_35 ) &&
! ( strncmp ( L_39 , V_23 . V_24 , 15 ) ) ) ) ;
if ( V_140 )
F_58 ( V_9 ) ;
V_139 = F_10 ( V_2 , V_7 -> V_53 , & V_23 , V_26 ) ;
V_59:
if ( V_139 > 0 )
V_139 = 0 ;
return V_139 ;
}
int F_59 ( struct V_15 * V_9 , struct V_22 * V_23 )
{
F_2 ( V_11 , L_40 ,
V_23 -> V_34 , V_23 -> V_24 , V_23 -> V_36 ) ;
return F_56 ( V_9 , V_23 -> V_34 , V_23 -> V_24 , V_23 -> V_36 ) ;
}
static int F_60 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
F_61 ( V_2 -> V_144 ) ;
if ( V_2 -> V_48 -> V_49 == 0 )
return 0 ;
V_2 -> V_48 -> V_49 = false ;
F_20 ( V_9 ) ;
return 0 ;
}
static int F_62 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_75 * V_48 = V_2 -> V_48 ;
T_1 V_103 ;
T_7 V_27 = 0 ;
T_3 V_145 = 0 ;
F_2 ( V_11 , L_41 , V_7 -> V_53 ) ;
if ( V_7 -> V_53 == 0 ) {
if ( V_48 -> V_50 != V_142 ) {
F_2 ( ERROR , L_42 ) ;
return - V_146 ;
}
F_63 ( & V_2 -> V_68 , 0 ) ;
memcpy ( V_9 -> V_42 , V_2 -> V_147 , V_31 ) ;
if ( F_48 ( V_2 , V_7 -> V_53 , & V_103 ) >= 0
&& ( V_103 & V_128 ) != 0 )
V_2 -> V_8 [ V_7 -> V_53 ] -> V_9 -> V_132 |=
V_133 ;
else
V_2 -> V_8 [ V_7 -> V_53 ] -> V_9 -> V_132 &=
~ V_133 ;
}
F_64 ( V_2 , 0 , V_148 , ( char * ) & V_145 , sizeof( V_145 ) ) ;
F_65 ( V_9 ) ;
V_2 -> V_48 -> V_49 = true ;
if ( F_66 ( V_2 -> V_144 ) ) {
F_2 ( ERROR , L_43 ) ;
return - 1 ;
}
return V_27 ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_15 * V_9 ;
T_4 V_149 [ V_31 ] ;
F_2 ( V_11 , L_41 , V_7 -> V_53 ) ;
V_9 = V_2 -> V_8 [ V_7 -> V_53 ] -> V_9 ;
V_9 -> V_150 = & V_151 ;
if ( F_68 ( V_7 -> V_152 ) )
memcpy ( V_149 , V_7 -> V_152 , V_31 ) ;
else
memcpy ( V_149 , V_2 -> V_147 , V_31 ) ;
if ( V_7 -> V_53 == 1 ) {
F_2 ( V_11 , L_44 ) ;
V_149 [ 0 ] |= 0X02 ;
}
V_9 -> V_153 = V_89 + V_2 -> V_54 ;
V_9 -> V_154 = & V_155 ;
V_2 -> V_156 = V_9 -> V_157 + V_9 -> V_153 +
V_2 -> V_54 ;
memcpy ( V_9 -> V_42 , V_149 , V_31 ) ;
if ( ! V_7 -> V_53 ) {
V_2 -> V_144 = F_69 ( V_9 , V_2 -> V_70 , V_2 ) ;
if ( V_2 -> V_144 == NULL ) {
F_2 ( ERROR , L_45 ) ;
goto V_158;
}
}
if ( F_70 ( V_9 ) != 0 ) {
F_2 ( ERROR , L_46 ) ;
goto V_158;
}
F_2 ( V_56 , L_47 , V_9 -> V_3 ) ;
return 0 ;
V_158:
V_9 -> V_150 = NULL ;
return - V_159 ;
}
int
F_71 ( struct V_74 * V_70 , int V_12 , char * V_3 , T_4 * V_152 )
{
struct V_6 * V_7 ;
struct V_15 * V_9 ;
struct V_75 * V_48 = F_29 ( V_70 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_48 , V_12 ) ;
V_7 = V_2 -> V_8 [ V_12 ] ;
if ( V_7 ) {
F_2 ( ERROR , L_49 ,
V_7 -> V_9 -> V_3 ) ;
F_20 ( V_7 -> V_9 ) ;
F_72 ( V_7 -> V_9 ) ;
F_73 ( V_7 -> V_9 ) ;
V_2 -> V_8 [ V_12 ] = NULL ;
}
V_9 = F_74 ( sizeof( struct V_6 ) , V_3 , V_160 ) ;
if ( ! V_9 ) {
F_2 ( ERROR , L_50 ) ;
return - V_58 ;
}
V_7 = F_16 ( V_9 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
V_2 -> V_8 [ V_12 ] = V_7 ;
V_7 -> V_53 = V_12 ;
if ( V_152 != NULL )
memcpy ( & V_7 -> V_152 , V_152 , V_31 ) ;
if ( F_67 ( V_7 ) ) {
F_2 ( ERROR , L_51 ) ;
F_73 ( V_7 -> V_9 ) ;
V_2 -> V_8 [ V_12 ] = NULL ;
return - V_107 ;
}
F_2 ( V_11 , L_52 ,
V_161 -> V_162 , V_7 -> V_9 -> V_3 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 , int V_12 )
{
struct V_6 * V_7 ;
F_2 ( V_11 , L_48 , V_12 ) ;
V_7 = V_2 -> V_8 [ V_12 ] ;
if ( ! V_7 ) {
F_2 ( ERROR , L_53 ) ;
return;
}
if ( V_7 -> V_9 ) {
if ( V_12 == 0 ) {
if ( V_7 -> V_9 -> V_150 == & V_151 ) {
F_76 () ;
F_60 ( V_7 -> V_9 ) ;
F_77 () ;
}
} else {
F_20 ( V_7 -> V_9 ) ;
}
F_72 ( V_7 -> V_9 ) ;
V_2 -> V_8 [ V_12 ] = NULL ;
if ( V_12 == 0 )
F_78 ( V_2 -> V_144 ) ;
F_73 ( V_7 -> V_9 ) ;
}
}
int F_79 ( T_3 V_163 , struct V_74 * V_70 )
{
struct V_1 * V_2 = NULL ;
int V_27 = 0 ;
F_2 ( V_11 , L_17 ) ;
V_2 = F_80 ( sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_2 )
return - V_58 ;
F_81 ( & V_2 -> V_164 ) ;
V_2 -> V_54 = V_163 ;
V_2 -> V_48 = F_29 ( V_70 ) ;
V_2 -> V_48 -> V_2 = V_2 ;
V_2 -> V_70 = V_70 ;
F_82 ( V_2 ) ;
V_27 = F_83 ( V_2 ) ;
if ( V_27 != 0 ) {
F_2 ( ERROR , L_54 ) ;
goto V_158;
}
F_84 ( & V_2 -> V_40 , F_14 ) ;
F_84 ( & V_2 -> V_28 , F_4 ) ;
F_85 ( & V_2 -> V_48 -> V_165 ) ;
return V_27 ;
V_158:
F_86 ( V_70 ) ;
return V_27 ;
}
int F_87 ( struct V_74 * V_70 )
{
int V_27 = - 1 ;
char V_166 [ V_167 + 12 ] ;
struct V_75 * V_48 = F_29 ( V_70 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_55 ) ;
V_27 = V_48 -> V_168 ( V_70 ) ;
if ( V_27 != 0 ) {
F_2 ( ERROR , L_56 , V_27 ) ;
return V_27 ;
}
F_12 ( L_57 , V_2 -> V_169 , V_167 ,
V_166 , sizeof( V_166 ) ) ;
F_88 ( V_2 , 0 , V_105 , V_166 ,
sizeof( V_166 ) ) ;
memcpy ( V_2 -> V_169 , V_166 , V_167 ) ;
F_89 ( V_2 -> V_169 , V_170 ) ;
F_89 ( V_2 -> V_169 , V_171 ) ;
F_89 ( V_2 -> V_169 , V_172 ) ;
F_89 ( V_2 -> V_169 , V_173 ) ;
F_89 ( V_2 -> V_169 , V_174 ) ;
F_89 ( V_2 -> V_169 , V_175 ) ;
F_89 ( V_2 -> V_169 , V_176 ) ;
F_89 ( V_2 -> V_169 , V_177 ) ;
F_89 ( V_2 -> V_169 , V_178 ) ;
F_89 ( V_2 -> V_169 , V_179 ) ;
F_89 ( V_2 -> V_169 , V_180 ) ;
F_89 ( V_2 -> V_169 , V_181 ) ;
F_89 ( V_2 -> V_169 , V_182 ) ;
F_89 ( V_2 -> V_169 , V_183 ) ;
F_89 ( V_2 -> V_169 , V_184 ) ;
F_89 ( V_2 -> V_169 , V_185 ) ;
F_89 ( V_2 -> V_169 , V_186 ) ;
F_89 ( V_2 -> V_169 , V_187 ) ;
V_2 -> V_188 = 1 ;
V_2 -> V_189 [ 0 ] = L_58 ;
V_27 = F_90 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_71 ( V_70 , 0 , L_59 , V_2 -> V_147 ) ;
if ( V_27 < 0 )
return V_27 ;
V_48 -> V_50 = V_142 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_2 ( V_11 , L_17 ) ;
if ( V_2 ) {
F_92 ( V_2 ) ;
V_2 -> V_48 -> V_190 ( V_2 -> V_70 ) ;
}
}
void F_86 ( struct V_74 * V_70 )
{
int V_4 ;
struct V_75 * V_48 = F_29 ( V_70 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_2 ( V_11 , L_17 ) ;
for ( V_4 = V_5 - 1 ; V_4 > - 1 ; V_4 -- )
if ( V_2 -> V_8 [ V_4 ] )
F_75 ( V_2 , V_4 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_191 ) {
F_93 ( & V_2 -> V_40 ) ;
F_93 ( & V_2 -> V_28 ) ;
F_94 ( V_2 ) ;
}
F_95 ( V_2 ) ;
V_48 -> V_2 = NULL ;
F_11 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
return F_97 ( & V_2 -> V_68 ) ;
}
int F_58 ( struct V_15 * V_9 )
{
struct V_6 * V_7 = F_16 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_192 = 10 * V_193 / 1000 ;
int V_194 = V_195 ;
int V_196 = F_96 ( V_2 ) ;
while ( V_194 && V_196 ) {
if ( V_196 ) {
F_98 ( V_197 ) ;
F_99 ( V_192 ) ;
F_98 ( V_198 ) ;
V_194 -- ;
}
V_196 = F_96 ( V_2 ) ;
}
return V_196 ;
}
int F_100 ( struct V_1 * V_2 , const T_4 * V_24 , int V_199 )
{
int V_27 = 0 ;
struct V_200 * V_201 ;
T_8 V_202 ;
T_9 V_203 = 0 ;
V_202 = F_101 () ;
F_102 ( V_204 ) ;
V_201 = F_103 ( L_60 , V_205 | V_206 , 0640 ) ;
if ( ! V_201 ) {
F_2 ( ERROR , L_61 ) ;
V_27 = - 1 ;
goto exit;
}
V_201 -> V_207 -> V_208 ( V_201 , ( char T_6 * ) V_24 , V_199 , & V_203 ) ;
exit:
F_11 ( V_24 ) ;
if ( V_201 )
F_104 ( V_201 , NULL ) ;
F_102 ( V_202 ) ;
return V_27 ;
}
static void F_105 ( struct V_13 * V_14 )
{
F_106 () ;
#ifdef F_107
F_108 () ;
#endif
#ifdef F_109
F_110 () ;
#endif
}
static int T_10 F_111 ( void )
{
if ( ! F_17 ( & V_209 ) )
return - V_210 ;
return 0 ;
}
static void T_11 F_112 ( void )
{
F_93 ( & V_209 ) ;
#ifdef F_107
F_113 () ;
#endif
#ifdef F_109
F_114 () ;
#endif
F_115 () ;
}
