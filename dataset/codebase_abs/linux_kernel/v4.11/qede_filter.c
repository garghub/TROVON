void F_1 ( void * V_1 , T_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_1 ;
if ( F_2 ( V_5 -> V_6 -> V_7 ) && ! V_3 )
return;
F_3 ( V_5 -> V_6 -> V_7 , V_2 ) ;
F_3 ( V_5 -> V_8 , V_2 ) ;
}
void F_4 ( struct V_4 * V_5 ,
struct V_9 * V_10 , T_1 * V_11 )
{
bool V_12 = false ;
int V_13 ;
if ( F_5 ( V_5 ) <= 1 ) {
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
* V_11 = 0 ;
return;
}
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( V_5 -> V_15 [ V_13 ] >= F_5 ( V_5 ) ) {
V_12 = true ;
break;
}
}
if ( ! ( V_5 -> V_16 & V_17 ) || V_12 ) {
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
T_2 V_18 , V_19 ;
V_19 = F_5 ( V_5 ) ;
V_18 = F_6 ( V_13 , V_19 ) ;
V_5 -> V_15 [ V_13 ] = V_18 ;
}
V_5 -> V_16 |= V_17 ;
}
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
T_2 V_20 = F_7 ( V_5 , V_5 -> V_15 [ V_13 ] ) ;
V_10 -> V_15 [ V_13 ] = V_5 -> V_21 [ V_20 ] . V_22 -> V_23 ;
}
if ( ! ( V_5 -> V_16 & V_24 ) ) {
F_8 ( V_5 -> V_25 , sizeof( V_5 -> V_25 ) ) ;
V_5 -> V_16 |= V_24 ;
}
memcpy ( V_10 -> V_25 , V_5 -> V_25 , sizeof( V_10 -> V_25 ) ) ;
if ( ! ( V_5 -> V_16 & V_26 ) ) {
V_5 -> V_27 = V_28 | V_29 |
V_30 | V_31 ;
V_5 -> V_16 |= V_26 ;
}
V_10 -> V_27 = V_5 -> V_27 ;
* V_11 = 1 ;
}
static int F_9 ( struct V_4 * V_5 ,
enum V_32 V_33 ,
unsigned char V_2 [ V_34 ] )
{
struct V_35 V_36 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . type = V_37 ;
V_36 . V_38 . V_39 . type = V_33 ;
V_36 . V_38 . V_39 . V_40 = 1 ;
F_3 ( V_36 . V_38 . V_39 . V_2 , V_2 ) ;
return V_5 -> V_41 -> V_42 ( V_5 -> V_43 , & V_36 ) ;
}
static int F_10 ( struct V_4 * V_5 ,
enum V_32 V_33 ,
T_2 V_44 )
{
struct V_35 V_36 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . type = V_37 ;
V_36 . V_38 . V_39 . type = V_33 ;
V_36 . V_38 . V_39 . V_45 = 1 ;
V_36 . V_38 . V_39 . V_46 = V_44 ;
return V_5 -> V_41 -> V_42 ( V_5 -> V_43 , & V_36 ) ;
}
static int F_11 ( struct V_4 * V_5 , bool V_47 )
{
struct V_48 * V_49 ;
int V_50 ;
if ( V_5 -> V_51 == V_47 )
return 0 ;
V_49 = F_12 ( sizeof( * V_49 ) ) ;
if ( ! V_49 )
return - V_52 ;
V_49 -> V_53 = 0 ;
V_49 -> V_51 = V_47 ;
V_49 -> V_54 = 1 ;
V_50 = V_5 -> V_41 -> V_55 ( V_5 -> V_43 , V_49 ) ;
if ( V_50 ) {
F_13 ( V_5 , L_1 ,
V_47 ? L_2 : L_3 ) ;
} else {
F_14 ( V_5 , L_4 ,
V_47 ? L_5 : L_6 ) ;
V_5 -> V_51 = V_47 ;
}
F_15 ( V_49 ) ;
return 0 ;
}
int F_16 ( struct V_56 * V_1 , T_3 V_57 , T_2 V_44 )
{
struct V_4 * V_5 = F_17 ( V_1 ) ;
struct V_58 * V_46 , * V_59 ;
int V_50 = 0 ;
F_18 ( V_5 , V_60 , L_7 , V_44 ) ;
V_46 = F_19 ( sizeof( * V_46 ) , V_61 ) ;
if ( ! V_46 ) {
F_14 ( V_5 , L_8 ) ;
return - V_52 ;
}
F_20 ( & V_46 -> V_62 ) ;
V_46 -> V_44 = V_44 ;
V_46 -> V_63 = false ;
F_21 (tmp, &edev->vlan_list, list) {
if ( V_59 -> V_44 == V_46 -> V_44 ) {
F_18 ( V_5 , ( V_60 | V_64 ) ,
L_9 ) ;
F_22 ( V_46 ) ;
return - V_65 ;
}
}
F_23 ( V_5 ) ;
if ( V_5 -> V_66 != V_67 ) {
F_18 ( V_5 , V_64 ,
L_10 ,
V_44 ) ;
if ( V_44 != 0 )
V_5 -> V_68 ++ ;
F_24 ( & V_46 -> V_62 , & V_5 -> V_69 ) ;
goto V_70;
}
if ( ( V_5 -> V_71 < V_5 -> V_72 . V_73 ) ||
( V_46 -> V_44 == 0 ) ) {
V_50 = F_10 ( V_5 ,
V_74 ,
V_46 -> V_44 ) ;
if ( V_50 ) {
F_13 ( V_5 , L_11 ,
V_46 -> V_44 ) ;
F_22 ( V_46 ) ;
goto V_70;
}
V_46 -> V_63 = true ;
if ( V_46 -> V_44 != 0 )
V_5 -> V_71 ++ ;
} else {
if ( ! V_5 -> V_68 ) {
V_50 = F_11 ( V_5 , true ) ;
if ( V_50 ) {
F_22 ( V_46 ) ;
goto V_70;
}
}
V_5 -> V_68 ++ ;
}
F_24 ( & V_46 -> V_62 , & V_5 -> V_69 ) ;
V_70:
F_25 ( V_5 ) ;
return V_50 ;
}
static void F_26 ( struct V_4 * V_5 ,
struct V_58 * V_46 )
{
if ( V_46 -> V_44 != 0 ) {
if ( V_46 -> V_63 )
V_5 -> V_71 -- ;
else
V_5 -> V_68 -- ;
}
F_27 ( & V_46 -> V_62 ) ;
F_22 ( V_46 ) ;
}
int F_28 ( struct V_4 * V_5 )
{
int V_50 = 0 , V_75 = 0 , V_51 = 0 ;
struct V_76 * V_72 ;
struct V_58 * V_46 = NULL ;
if ( F_29 ( & V_5 -> V_69 ) )
return 0 ;
V_72 = & V_5 -> V_72 ;
F_21 (vlan, &edev->vlan_list, list) {
if ( V_46 -> V_63 )
continue;
if ( ( V_46 -> V_44 != 0 ) &&
( V_5 -> V_71 == V_72 -> V_73 ) ) {
V_51 = 1 ;
continue;
}
F_18 ( V_5 , V_60 , L_12 , V_46 -> V_44 ) ;
V_50 = F_10 ( V_5 , V_74 ,
V_46 -> V_44 ) ;
if ( V_50 ) {
F_13 ( V_5 , L_13 ,
V_46 -> V_44 ) ;
V_75 = V_50 ;
continue;
}
V_46 -> V_63 = true ;
if ( V_46 -> V_44 != 0 ) {
V_5 -> V_68 -- ;
V_5 -> V_71 ++ ;
}
}
if ( V_51 )
V_50 = F_11 ( V_5 , true ) ;
else if ( ! V_5 -> V_68 )
V_50 = F_11 ( V_5 , false ) ;
if ( V_50 && ! V_75 )
V_75 = V_50 ;
return V_75 ;
}
int F_30 ( struct V_56 * V_1 , T_3 V_57 , T_2 V_44 )
{
struct V_4 * V_5 = F_17 ( V_1 ) ;
struct V_58 * V_46 = NULL ;
int V_50 = 0 ;
F_18 ( V_5 , V_64 , L_14 , V_44 ) ;
F_23 ( V_5 ) ;
F_21 (vlan, &edev->vlan_list, list)
if ( V_46 -> V_44 == V_44 )
break;
if ( ! V_46 || ( V_46 -> V_44 != V_44 ) ) {
F_18 ( V_5 , ( V_60 | V_64 ) ,
L_15 ) ;
goto V_70;
}
if ( V_5 -> V_66 != V_67 ) {
F_18 ( V_5 , V_64 ,
L_16 ) ;
F_26 ( V_5 , V_46 ) ;
goto V_70;
}
if ( V_46 -> V_63 ) {
V_50 = F_10 ( V_5 , V_77 ,
V_44 ) ;
if ( V_50 ) {
F_13 ( V_5 , L_17 , V_44 ) ;
goto V_70;
}
}
F_26 ( V_5 , V_46 ) ;
V_50 = F_28 ( V_5 ) ;
V_70:
F_25 ( V_5 ) ;
return V_50 ;
}
void F_31 ( struct V_4 * V_5 )
{
struct V_58 * V_46 = NULL ;
if ( F_29 ( & V_5 -> V_69 ) )
return;
F_21 (vlan, &edev->vlan_list, list) {
if ( ! V_46 -> V_63 )
continue;
V_46 -> V_63 = false ;
if ( V_46 -> V_44 != 0 ) {
V_5 -> V_68 ++ ;
V_5 -> V_71 -- ;
}
F_18 ( V_5 , V_64 ,
L_18 , V_46 -> V_44 ) ;
}
V_5 -> V_51 = false ;
}
static void F_32 ( struct V_4 * V_5 ,
struct V_78 * args )
{
V_5 -> V_6 -> V_79 = args -> V_80 . V_79 ;
}
int F_33 ( struct V_56 * V_1 , T_4 V_79 )
{
struct V_4 * V_5 = F_17 ( V_1 ) ;
T_4 V_81 = V_79 ^ V_1 -> V_79 ;
bool V_82 = false ;
if ( V_81 & V_83 ) {
if ( V_1 -> V_79 & V_83 )
V_82 = ! V_5 -> V_84 ;
else
V_82 = V_5 -> V_84 ;
}
if ( V_82 ) {
struct V_78 args ;
args . V_80 . V_79 = V_79 ;
args . V_85 = & F_32 ;
F_23 ( V_5 ) ;
if ( V_5 -> V_86 )
args . V_85 ( V_5 , & args ) ;
else
F_34 ( V_5 , & args , true ) ;
F_25 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
void F_35 ( struct V_56 * V_1 , struct V_87 * V_88 )
{
struct V_4 * V_5 = F_17 ( V_1 ) ;
T_2 V_89 = F_36 ( V_88 -> V_90 ) ;
switch ( V_88 -> type ) {
case V_91 :
if ( V_5 -> V_92 )
return;
V_5 -> V_92 = V_89 ;
F_18 ( V_5 , V_93 , L_19 ,
V_89 ) ;
F_37 ( V_94 , & V_5 -> V_95 ) ;
break;
case V_96 :
if ( V_5 -> V_97 )
return;
V_5 -> V_97 = V_89 ;
F_18 ( V_5 , V_93 , L_20 ,
V_89 ) ;
F_37 ( V_98 , & V_5 -> V_95 ) ;
break;
default:
return;
}
F_38 ( & V_5 -> V_99 , 0 ) ;
}
void F_39 ( struct V_56 * V_1 , struct V_87 * V_88 )
{
struct V_4 * V_5 = F_17 ( V_1 ) ;
T_2 V_89 = F_36 ( V_88 -> V_90 ) ;
switch ( V_88 -> type ) {
case V_91 :
if ( V_89 != V_5 -> V_92 )
return;
V_5 -> V_92 = 0 ;
F_18 ( V_5 , V_93 , L_21 ,
V_89 ) ;
F_37 ( V_94 , & V_5 -> V_95 ) ;
break;
case V_96 :
if ( V_89 != V_5 -> V_97 )
return;
V_5 -> V_97 = 0 ;
F_18 ( V_5 , V_93 , L_22 ,
V_89 ) ;
F_37 ( V_98 , & V_5 -> V_95 ) ;
break;
default:
return;
}
F_38 ( & V_5 -> V_99 , 0 ) ;
}
static void F_40 ( struct V_4 * V_5 ,
struct V_78 * args )
{
struct V_100 * V_101 ;
V_101 = F_41 ( & V_5 -> V_86 , args -> V_80 . V_102 ) ;
if ( V_101 )
F_42 ( V_101 ) ;
}
static int F_43 ( struct V_4 * V_5 , struct V_100 * V_103 )
{
struct V_78 args ;
if ( V_103 && V_103 -> V_104 ) {
F_13 ( V_5 , L_23 ) ;
return - V_105 ;
}
args . V_85 = & F_40 ;
args . V_80 . V_102 = V_103 ;
F_34 ( V_5 , & args , false ) ;
return 0 ;
}
int F_44 ( struct V_56 * V_1 , struct V_106 * V_107 )
{
struct V_4 * V_5 = F_17 ( V_1 ) ;
switch ( V_107 -> V_108 ) {
case V_109 :
return F_43 ( V_5 , V_107 -> V_103 ) ;
case V_110 :
V_107 -> V_111 = ! ! V_5 -> V_86 ;
return 0 ;
default:
return - V_112 ;
}
}
static int F_45 ( struct V_4 * V_5 ,
enum V_32 V_33 ,
unsigned char * V_2 , int V_113 )
{
struct V_35 V_36 ;
int V_13 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . type = V_114 ;
V_36 . V_38 . V_115 . type = V_33 ;
V_36 . V_38 . V_115 . V_116 = V_113 ;
for ( V_13 = 0 ; V_13 < V_113 ; V_13 ++ , V_2 += V_34 )
F_3 ( V_36 . V_38 . V_115 . V_2 [ V_13 ] , V_2 ) ;
return V_5 -> V_41 -> V_42 ( V_5 -> V_43 , & V_36 ) ;
}
int F_46 ( struct V_56 * V_6 , void * V_117 )
{
struct V_4 * V_5 = F_17 ( V_6 ) ;
struct V_118 * V_119 = V_117 ;
int V_50 ;
F_47 () ;
F_14 ( V_5 , L_24 ) ;
if ( ! F_2 ( V_119 -> V_120 ) ) {
F_48 ( V_5 , L_25 ) ;
return - V_121 ;
}
if ( ! V_5 -> V_41 -> V_122 ( V_5 -> V_43 , V_119 -> V_120 ) ) {
F_48 ( V_5 , L_26 ) ;
return - V_112 ;
}
F_3 ( V_6 -> V_7 , V_119 -> V_120 ) ;
if ( ! F_49 ( V_6 ) ) {
F_48 ( V_5 , L_27 ) ;
return 0 ;
}
V_50 = F_9 ( V_5 , V_77 ,
V_5 -> V_8 ) ;
if ( V_50 )
return V_50 ;
V_5 -> V_41 -> V_123 -> V_124 ( V_5 -> V_43 , V_119 -> V_120 ) ;
F_3 ( V_5 -> V_8 , V_6 -> V_7 ) ;
return F_9 ( V_5 , V_74 ,
V_5 -> V_8 ) ;
}
static int
F_50 ( struct V_56 * V_6 ,
enum V_125 * V_126 )
{
struct V_4 * V_5 = F_17 ( V_6 ) ;
unsigned char * V_127 , * V_128 ;
struct V_129 * V_130 ;
int V_50 = 0 , V_131 ;
T_5 V_132 ;
V_132 = 64 * V_34 ;
V_127 = F_19 ( V_132 , V_61 ) ;
if ( ! V_127 ) {
F_48 ( V_5 ,
L_28 ) ;
V_50 = - V_52 ;
goto exit;
}
V_128 = V_127 ;
V_50 = F_45 ( V_5 , V_77 ,
V_127 , 1 ) ;
if ( V_50 )
goto exit;
F_51 ( V_6 ) ;
V_131 = F_52 ( V_6 ) ;
if ( V_131 < 64 ) {
F_53 (ha, ndev) {
F_3 ( V_128 , V_130 -> V_119 ) ;
V_128 += V_34 ;
}
}
F_54 ( V_6 ) ;
if ( ( V_6 -> V_133 & V_134 ) || ( V_131 > 64 ) ) {
if ( * V_126 == V_135 )
* V_126 = V_136 ;
} else {
V_50 = F_45 ( V_5 , V_74 ,
V_127 , V_131 ) ;
}
exit:
F_22 ( V_127 ) ;
return V_50 ;
}
void F_55 ( struct V_56 * V_6 )
{
struct V_4 * V_5 = F_17 ( V_6 ) ;
F_37 ( V_137 , & V_5 -> V_95 ) ;
F_38 ( & V_5 -> V_99 , 0 ) ;
}
void F_56 ( struct V_56 * V_6 )
{
enum V_125 V_126 ;
struct V_4 * V_5 = F_17 ( V_6 ) ;
struct V_35 V_138 ;
unsigned char * V_139 , * V_128 ;
struct V_129 * V_130 ;
int V_50 , V_140 ;
T_5 V_132 ;
F_51 ( V_6 ) ;
V_140 = F_57 ( V_6 ) ;
V_132 = V_140 * V_34 ;
V_139 = F_19 ( V_132 , V_141 ) ;
if ( ! V_139 ) {
F_48 ( V_5 , L_29 ) ;
F_54 ( V_6 ) ;
return;
}
V_128 = V_139 ;
F_58 (ha, ndev) {
F_3 ( V_128 , V_130 -> V_119 ) ;
V_128 += V_34 ;
}
F_54 ( V_6 ) ;
memset ( & V_138 , 0 , sizeof( struct V_35 ) ) ;
V_138 . type = V_142 ;
V_50 = F_9 ( V_5 , V_143 ,
V_5 -> V_8 ) ;
if ( V_50 )
goto V_70;
if ( V_6 -> V_133 & V_144 )
V_126 = V_145 ;
else
V_126 = V_135 ;
if ( V_140 < V_5 -> V_72 . V_146 ) {
int V_13 ;
V_128 = V_139 ;
for ( V_13 = 0 ; V_13 < V_140 ; V_13 ++ ) {
V_50 = F_9 ( V_5 ,
V_74 ,
V_128 ) ;
if ( V_50 )
goto V_70;
V_128 += V_34 ;
}
} else {
V_126 = V_145 ;
}
V_50 = F_50 ( V_6 , & V_126 ) ;
if ( V_50 )
goto V_70;
if ( V_6 -> V_133 & V_144 ) {
F_11 ( V_5 , true ) ;
} else if ( ! V_5 -> V_68 ) {
F_11 ( V_5 , false ) ;
}
V_138 . V_38 . V_126 = V_126 ;
V_5 -> V_41 -> V_42 ( V_5 -> V_43 , & V_138 ) ;
V_70:
F_22 ( V_139 ) ;
}
