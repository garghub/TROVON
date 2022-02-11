static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_2 ( V_2 -> V_5 == V_6 ,
L_1 ) )
return - V_7 ;
F_3 ( V_8 , L_2 , V_4 -> V_9 ) ;
F_4 ( & V_2 -> V_10 ) ;
V_2 -> V_11 [ V_2 -> V_5 ++ ] = V_4 ;
F_5 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
int V_12 , V_13 = 0 ;
F_4 ( & V_2 -> V_10 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 ; V_12 ++ ) {
if ( V_2 -> V_11 [ V_12 ] -> V_9 == V_9 )
break;
}
if ( F_2 ( V_12 == V_2 -> V_5 , L_3 ) ) {
V_13 = - V_14 ;
goto V_15;
}
F_3 ( V_8 , L_2 , V_9 ) ;
V_2 -> V_5 -- ;
if ( ! V_2 -> V_5 || V_12 == V_2 -> V_5 )
goto V_15;
while ( V_12 <= V_2 -> V_5 - 1 ) {
V_2 -> V_11 [ V_12 ] = V_2 -> V_11 [ V_12 + 1 ] ;
V_12 ++ ;
}
V_15:
F_5 ( & V_2 -> V_10 ) ;
return V_13 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
V_19 -> V_20 = 0 ;
V_19 -> V_21 = 0 ;
return F_8 ( V_17 , L_4 , V_19 , sizeof( * V_19 ) ) ;
}
static int F_9 ( struct V_16 * V_17 , T_2 V_22 ,
T_2 V_23 , T_2 V_24 )
{
struct V_25 V_26 ;
T_3 V_21 ;
T_2 V_27 ;
T_4 V_13 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_28 = F_10 ( V_29 ) ;
V_21 = F_11 ( V_30 ) |
F_11 ( V_31 ) ;
V_26 . V_32 = V_33 ;
V_26 . exp = V_34 ;
V_26 . V_22 = F_10 ( V_22 ) ;
if ( V_23 ) {
V_27 = V_24 ;
V_13 = F_12 ( V_17 , L_5 , V_27 ) ;
if ( V_13 < 0 ) {
F_13 ( L_6 ) ;
goto exit;
}
V_13 = F_14 ( V_17 , L_5 , & V_27 ) ;
if ( V_13 < 0 ) {
F_13 ( L_7 ) ;
goto exit;
}
V_23 = F_15 ( T_2 , V_23 , V_27 ) ;
V_26 . V_23 = V_23 ;
V_26 . V_24 = V_24 ;
V_21 |= F_11 ( V_35 ) ;
F_3 ( V_36 , L_8 , V_23 , V_24 ) ;
}
V_26 . V_21 = F_16 ( V_21 ) ;
V_13 = F_8 ( V_17 , L_9 , & V_26 ,
sizeof( V_26 ) ) ;
if ( V_13 )
F_13 ( L_10 , V_13 ) ;
exit:
return V_13 ;
}
static int F_17 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_37 V_38 ;
T_5 * V_39 = NULL ;
T_5 * V_40 = NULL ;
int V_13 , V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 ; V_12 ++ )
if ( V_2 -> V_11 [ V_12 ] -> V_21 & V_41 ) {
V_39 = V_2 -> V_11 [ V_12 ] -> V_39 ;
V_40 = V_2 -> V_11 [ V_12 ] -> V_42 ;
break;
}
if ( ! V_39 )
return 0 ;
V_38 . V_28 = V_43 ;
V_38 . V_21 = V_44 | V_45 ;
memcpy ( V_38 . V_46 , V_39 , V_47 ) ;
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ ) {
V_38 . V_46 [ V_12 ] &= V_40 [ V_12 ] ;
V_38 . V_46 [ V_12 ] |= F_18 () & ~ ( V_40 [ V_12 ] ) ;
}
V_38 . V_46 [ 0 ] &= 0xFE ;
V_38 . V_46 [ 0 ] |= 0x02 ;
F_3 ( V_8 , L_11 ,
V_2 -> V_11 [ V_12 ] -> V_9 , V_38 . V_46 ) ;
V_13 = F_8 ( V_17 , L_12 , & V_38 ,
sizeof( V_38 ) ) ;
if ( V_13 )
F_13 ( L_13 , V_13 ) ;
return V_13 ;
}
static int F_19 ( struct V_16 * V_17 , struct V_48 * V_49 ,
bool V_50 )
{
struct V_51 V_52 ;
int V_13 ;
V_52 . V_53 = F_10 ( V_54 ) ;
V_52 . V_55 = F_10 ( V_56 ) ;
V_52 . V_57 = F_10 ( 0 ) ;
V_52 . V_58 = F_10 ( 1 ) ;
V_52 . V_21 = 0 ;
if ( V_50 )
V_52 . V_21 = F_10 ( 1 << V_59 ) ;
V_52 . V_49 . V_60 = F_10 ( V_49 -> V_61 ) ;
memcpy ( V_52 . V_49 . V_62 , V_49 -> V_49 , V_49 -> V_61 ) ;
F_3 ( V_8 , L_14 , V_49 -> V_49 , V_50 ) ;
V_13 = F_8 ( V_17 , L_15 , & V_52 , sizeof( V_52 ) ) ;
if ( V_13 < 0 )
F_13 ( L_16 , V_13 ) ;
return V_13 ;
}
static int F_20 ( struct V_16 * V_17 , const T_5 * V_63 )
{
struct V_64 V_65 ;
int V_13 ;
memcpy ( V_65 . V_63 , V_63 , V_47 ) ;
V_65 . V_21 = 0 ;
F_3 ( V_8 , L_17 , V_63 ) ;
V_13 = F_8 ( V_17 , L_18 , & V_65 ,
sizeof( V_65 ) ) ;
if ( V_13 < 0 )
F_13 ( L_16 , V_13 ) ;
return V_13 ;
}
static bool F_21 ( struct V_48 * V_49 ,
struct V_3 * V_4 )
{
int V_12 ;
if ( ! V_49 || ! V_4 -> V_66 || ! V_4 -> V_67 )
return false ;
for ( V_12 = 0 ; V_12 < V_4 -> V_67 ; V_12 ++ ) {
if ( V_49 -> V_61 == V_4 -> V_66 [ V_12 ] . V_61 ) {
if ( ! strncmp ( V_49 -> V_49 , V_4 -> V_66 [ V_12 ] . V_49 ,
V_49 -> V_61 ) )
return true ;
}
}
return false ;
}
static int F_22 ( struct V_16 * V_17 )
{
int V_68 ;
V_68 = F_12 ( V_17 , L_19 , 0 ) ;
if ( V_68 == 0 ) {
V_68 = F_8 ( V_17 , L_20 , NULL , 0 ) ;
}
if ( V_68 < 0 )
F_13 ( L_21 , V_68 ) ;
return V_68 ;
}
static int F_23 ( struct V_3 * V_69 ,
struct V_18 * V_70 )
{
T_2 V_71 = F_24 ( V_70 -> V_72 ) ;
T_3 V_73 ;
int V_12 , V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_69 -> V_74 ; V_12 ++ ) {
if ( V_71 >= V_75 ) {
V_13 = - V_7 ;
goto V_15;
}
V_73 = V_69 -> V_76 [ V_12 ] -> V_77 ;
F_3 ( V_8 , L_22 , V_71 , V_73 ) ;
V_70 -> V_78 [ V_71 ++ ] = F_16 ( V_73 ) ;
}
V_13 = V_71 ;
V_15:
V_70 -> V_72 = F_10 ( V_71 ) ;
return V_13 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_18 * V_70 ,
struct V_79 * * V_80 ,
T_2 * V_22 )
{
struct V_3 * V_81 ;
struct V_79 * V_82 ;
int V_12 , V_13 , V_83 ;
F_3 ( V_8 , L_23 , V_2 -> V_5 ) ;
if ( F_26 ( ! V_2 -> V_5 ) )
return - V_84 ;
* V_22 = V_2 -> V_11 [ 0 ] -> V_85 [ 0 ] . V_86 ;
for ( V_12 = 1 ; V_12 < V_2 -> V_5 ; V_12 ++ ) {
V_81 = V_2 -> V_11 [ V_12 ] ;
* V_22 = F_27 ( V_81 -> V_85 [ 0 ] . V_86 , * V_22 ) ;
}
if ( * V_22 < V_87 ) {
F_3 ( V_8 , L_24 ) ;
* V_22 = V_87 ;
}
* V_80 = NULL ;
V_82 = F_28 ( V_2 -> V_5 , sizeof( * V_82 ) , V_88 ) ;
if ( ! V_82 )
return - V_89 ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 ; V_12 ++ ) {
V_81 = V_2 -> V_11 [ V_12 ] ;
V_83 = F_23 ( V_81 , V_70 ) ;
if ( V_83 < 0 ) {
V_13 = V_83 ;
goto V_90;
}
V_82 [ V_12 ] . V_91 = V_83 - 1 ;
V_82 [ V_12 ] . V_92 =
V_81 -> V_85 [ 0 ] . V_86 / * V_22 ;
if ( ! V_82 [ V_12 ] . V_92 )
V_82 [ V_12 ] . V_92 = 1 ;
V_82 [ V_12 ] . V_93 = V_94 ;
}
if ( F_29 () ) {
F_13 ( L_25 , * V_22 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 ; V_12 ++ ) {
F_13 ( L_26 ,
V_12 , V_82 [ V_12 ] . V_92 ,
F_30 ( V_82 [ V_12 ] . V_95 ) ,
V_82 [ V_12 ] . V_32 , V_82 [ V_12 ] . V_93 ,
V_82 [ V_12 ] . V_91 ) ;
}
}
* V_80 = V_82 ;
return V_2 -> V_5 ;
V_90:
F_31 ( V_82 ) ;
return V_13 ;
}
static int F_32 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_3 * V_69 ;
struct V_96 * V_97 ;
bool V_50 ;
int V_12 , V_98 , V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 ; V_12 ++ ) {
V_69 = V_2 -> V_11 [ V_12 ] ;
for ( V_98 = 0 ; V_98 < V_69 -> V_99 ; V_98 ++ ) {
V_97 = & V_69 -> V_100 [ V_98 ] ;
if ( V_97 -> V_49 . V_61 ) {
V_50 = F_21 ( & V_97 -> V_49 , V_69 ) ;
V_13 = F_19 ( V_17 , & V_97 -> V_49 ,
V_50 ) ;
}
if ( ! V_13 && F_33 ( V_97 -> V_63 ) )
V_13 = F_20 ( V_17 , V_97 -> V_63 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
return 0 ;
}
static int F_34 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_101 * V_102 ;
struct V_79 * V_80 ;
struct V_18 V_70 ;
T_6 V_103 ;
T_2 V_22 ;
int V_13 , V_104 ;
V_2 = F_35 ( V_17 ) ;
V_104 = F_25 ( V_2 , & V_70 , & V_80 ,
& V_22 ) ;
if ( V_104 < 0 )
return V_104 ;
V_103 = sizeof( * V_102 ) + ( V_104 - 1 ) * sizeof( * V_80 ) ;
V_102 = F_36 ( V_103 , V_88 ) ;
if ( ! V_102 ) {
V_13 = - V_89 ;
goto V_105;
}
V_13 = F_22 ( V_17 ) ;
if ( V_13 < 0 ) {
F_13 ( L_27 , V_13 ) ;
goto V_106;
}
V_13 = F_9 ( V_17 , V_22 , 0 , 0 ) ;
if ( V_13 < 0 )
goto V_106;
V_13 = F_7 ( V_17 , & V_70 ) ;
if ( V_13 < 0 )
goto V_107;
V_102 -> V_28 = F_16 ( V_108 ) ;
V_102 -> V_109 = V_110 ;
V_102 -> V_111 = V_112 ;
V_102 -> V_21 = V_113 ;
V_102 -> V_114 = V_104 ;
memcpy ( & V_102 -> V_115 [ 0 ] , V_80 ,
V_104 * sizeof( * V_80 ) ) ;
V_13 = F_8 ( V_17 , L_28 , V_102 , V_103 ) ;
if ( V_13 < 0 )
goto V_107;
V_13 = F_17 ( V_17 , V_2 ) ;
if ( V_13 < 0 )
goto V_107;
V_13 = F_32 ( V_17 , V_2 ) ;
if ( V_13 < 0 )
goto V_107;
V_13 = F_12 ( V_17 , L_19 , 1 ) ;
V_107:
if ( V_13 < 0 )
F_22 ( V_17 ) ;
V_106:
F_31 ( V_102 ) ;
V_105:
F_31 ( V_80 ) ;
return V_13 ;
}
int F_37 ( struct V_16 * V_17 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_68 ;
F_3 ( V_116 , L_2 , V_4 -> V_9 ) ;
V_2 = F_35 ( V_17 ) ;
V_68 = F_1 ( V_2 , V_4 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_34 ( V_17 ) ;
if ( V_68 < 0 ) {
F_6 ( V_2 , V_4 -> V_9 ) ;
if ( V_2 -> V_5 )
( void ) F_34 ( V_17 ) ;
return V_68 ;
}
return 0 ;
}
int F_38 ( struct V_16 * V_17 , T_1 V_9 )
{
struct V_1 * V_2 ;
int V_13 ;
F_3 ( V_116 , L_2 , V_9 ) ;
V_2 = F_35 ( V_17 ) ;
V_13 = F_6 ( V_2 , V_9 ) ;
if ( V_13 )
return V_13 ;
F_22 ( V_17 ) ;
if ( V_2 -> V_5 )
( void ) F_34 ( V_17 ) ;
return 0 ;
}
int F_39 ( struct V_117 * V_19 )
{
struct V_1 * V_2 ;
F_3 ( V_116 , L_29 ) ;
V_2 = F_36 ( sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_19 -> V_118 = V_2 ;
F_40 ( & V_2 -> V_10 ) ;
return 0 ;
}
void F_41 ( struct V_117 * V_19 )
{
struct V_1 * V_2 ;
F_3 ( V_116 , L_29 ) ;
V_2 = V_19 -> V_118 ;
V_19 -> V_118 = NULL ;
F_26 ( V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_10 ) ;
F_31 ( V_2 ) ;
}
void F_43 ( struct V_119 * V_119 , bool V_120 )
{
V_119 -> V_121 = V_120 ? V_6 : 1 ;
V_119 -> V_122 = V_123 ;
V_119 -> V_124 = V_123 ;
V_119 -> V_125 = V_126 ;
V_119 -> V_127 = V_128 ;
}
T_1 F_44 ( struct V_1 * V_2 , T_2 V_115 )
{
T_1 V_9 = 0 ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_115 < V_2 -> V_5 )
V_9 = V_2 -> V_11 [ V_115 ] -> V_9 ;
F_5 ( & V_2 -> V_10 ) ;
return V_9 ;
}
T_2 F_45 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 ;
struct V_96 * V_97 ;
T_2 V_131 = 0 ;
int V_12 , V_98 ;
F_4 ( & V_2 -> V_10 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 ; V_12 ++ ) {
V_4 = V_2 -> V_11 [ V_12 ] ;
if ( ! V_4 -> V_99 )
continue;
for ( V_98 = 0 ; V_98 < V_4 -> V_99 ; V_98 ++ ) {
V_97 = & V_4 -> V_100 [ V_98 ] ;
if ( V_97 -> V_49 . V_61 == V_130 -> V_60 &&
! memcmp ( V_97 -> V_49 . V_49 , V_130 -> V_62 , V_130 -> V_60 ) ) {
V_131 |= F_11 ( V_12 ) ;
break;
}
if ( F_33 ( V_97 -> V_63 ) &&
! memcmp ( V_97 -> V_63 , V_130 -> V_63 , V_47 ) ) {
V_131 |= F_11 ( V_12 ) ;
break;
}
}
}
F_5 ( & V_2 -> V_10 ) ;
return V_131 ;
}
