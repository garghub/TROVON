int F_1 ( void )
{
return V_1 -> V_2 () ;
}
static int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 V_8 ;
if ( F_4 ( & V_4 -> V_8 ) )
return 0 ;
F_5 ( & V_8 , V_9 , V_10 ) ;
return F_6 ( V_6 , & V_8 ) ;
}
static void F_7 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_8 ( V_12 ) ; V_11 ++ )
F_9 ( & V_12 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < F_8 ( V_13 ) ; V_11 ++ )
F_9 ( & V_13 [ V_11 ] ) ;
}
static void F_10 ( struct V_14 * V_15 ,
struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_6 ) ;
F_12 ( & V_4 -> V_16 , V_15 ) ;
}
static void F_13 ( struct V_14 * V_15 ,
struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_6 ) ;
F_12 ( & V_4 -> V_17 , V_15 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_15 ( & V_4 -> V_16 ) ;
F_16 ( & V_4 -> V_6 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
F_15 ( & V_4 -> V_17 ) ;
F_16 ( & V_4 -> V_6 ) ;
}
static struct V_5 * F_18 ( struct V_7 * V_18 )
{
struct V_3 * V_4 ;
F_19 (vsk, vsock_bound_sockets(addr), bound_table)
if ( V_18 -> V_19 == V_4 -> V_8 . V_19 )
return F_3 ( V_4 ) ;
return NULL ;
}
static struct V_5 * F_20 ( struct V_7 * V_20 ,
struct V_7 * V_21 )
{
struct V_3 * V_4 ;
F_19 (vsk, vsock_connected_sockets(src, dst),
connected_table) {
if ( F_21 ( V_20 , & V_4 -> V_22 ) &&
V_21 -> V_19 == V_4 -> V_8 . V_19 ) {
return F_3 ( V_4 ) ;
}
}
return NULL ;
}
static bool F_22 ( struct V_3 * V_4 )
{
return ! F_23 ( & V_4 -> V_16 ) ;
}
static bool F_24 ( struct V_3 * V_4 )
{
return ! F_23 ( & V_4 -> V_17 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
F_26 ( & V_23 ) ;
F_10 ( V_24 , V_4 ) ;
F_27 ( & V_23 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_29 (
& V_4 -> V_22 , & V_4 -> V_8 ) ;
F_26 ( & V_23 ) ;
F_13 ( V_15 , V_4 ) ;
F_27 ( & V_23 ) ;
}
void F_30 ( struct V_3 * V_4 )
{
F_26 ( & V_23 ) ;
F_14 ( V_4 ) ;
F_27 ( & V_23 ) ;
}
void F_31 ( struct V_3 * V_4 )
{
F_26 ( & V_23 ) ;
F_17 ( V_4 ) ;
F_27 ( & V_23 ) ;
}
struct V_5 * F_32 ( struct V_7 * V_18 )
{
struct V_5 * V_6 ;
F_26 ( & V_23 ) ;
V_6 = F_18 ( V_18 ) ;
if ( V_6 )
F_11 ( V_6 ) ;
F_27 ( & V_23 ) ;
return V_6 ;
}
struct V_5 * F_33 ( struct V_7 * V_20 ,
struct V_7 * V_21 )
{
struct V_5 * V_6 ;
F_26 ( & V_23 ) ;
V_6 = F_20 ( V_20 , V_21 ) ;
if ( V_6 )
F_11 ( V_6 ) ;
F_27 ( & V_23 ) ;
return V_6 ;
}
static bool F_34 ( struct V_3 * V_4 )
{
bool V_25 ;
F_26 ( & V_23 ) ;
V_25 = F_22 ( V_4 ) ;
F_27 ( & V_23 ) ;
return V_25 ;
}
static bool F_35 ( struct V_3 * V_4 )
{
bool V_25 ;
F_26 ( & V_23 ) ;
V_25 = F_24 ( V_4 ) ;
F_27 ( & V_23 ) ;
return V_25 ;
}
void F_36 ( struct V_3 * V_4 )
{
if ( F_34 ( V_4 ) )
F_30 ( V_4 ) ;
if ( F_35 ( V_4 ) )
F_31 ( V_4 ) ;
}
void F_37 ( void (* F_38)( struct V_5 * V_6 ) )
{
int V_11 ;
F_26 ( & V_23 ) ;
for ( V_11 = 0 ; V_11 < F_8 ( V_13 ) ; V_11 ++ ) {
struct V_3 * V_4 ;
F_19 (vsk, &vsock_connected_table[i],
connected_table)
F_38 ( F_3 ( V_4 ) ) ;
}
F_27 ( & V_23 ) ;
}
void F_39 ( struct V_5 * V_26 , struct V_5 * V_27 )
{
struct V_3 * V_28 ;
struct V_3 * V_29 ;
V_28 = F_40 ( V_26 ) ;
V_29 = F_40 ( V_27 ) ;
F_11 ( V_27 ) ;
F_11 ( V_26 ) ;
F_41 ( & V_29 -> V_30 , & V_28 -> V_30 ) ;
}
void F_42 ( struct V_5 * V_26 , struct V_5 * V_27 )
{
struct V_3 * V_29 = F_40 ( V_27 ) ;
F_15 ( & V_29 -> V_30 ) ;
F_16 ( V_26 ) ;
F_16 ( V_27 ) ;
}
void F_43 ( struct V_5 * V_26 , struct V_5 * V_31 )
{
struct V_3 * V_28 ;
struct V_3 * V_32 ;
V_28 = F_40 ( V_26 ) ;
V_32 = F_40 ( V_31 ) ;
F_11 ( V_31 ) ;
F_11 ( V_26 ) ;
F_41 ( & V_32 -> V_33 , & V_28 -> V_33 ) ;
}
static struct V_5 * F_44 ( struct V_5 * V_26 )
{
struct V_3 * V_28 ;
struct V_3 * V_32 ;
V_28 = F_40 ( V_26 ) ;
if ( F_23 ( & V_28 -> V_33 ) )
return NULL ;
V_32 = F_45 ( V_28 -> V_33 . V_34 ,
struct V_3 , V_33 ) ;
F_15 ( & V_32 -> V_33 ) ;
F_16 ( V_26 ) ;
return F_3 ( V_32 ) ;
}
static bool F_46 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_40 ( V_6 ) ;
return F_23 ( & V_4 -> V_33 ) ;
}
static bool F_47 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_40 ( V_6 ) ;
return ! F_23 ( & V_4 -> V_30 ) ;
}
static int F_48 ( struct V_5 * V_6 , int V_35 )
{
return V_1 -> V_36 ( F_40 ( V_6 ) , V_35 ) ;
}
void F_49 ( struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_5 * V_26 ;
struct V_3 * V_4 ;
bool V_39 ;
V_4 = F_50 ( V_38 , struct V_3 , V_40 . V_38 ) ;
V_6 = F_3 ( V_4 ) ;
V_26 = V_4 -> V_26 ;
V_39 = true ;
F_51 ( V_26 ) ;
F_52 ( V_6 , V_41 ) ;
if ( F_47 ( V_6 ) ) {
F_42 ( V_26 , V_6 ) ;
V_26 -> V_42 -- ;
} else if ( ! V_4 -> V_43 ) {
V_39 = false ;
goto V_44;
}
if ( F_35 ( V_4 ) )
F_31 ( V_4 ) ;
V_6 -> V_45 = V_46 ;
V_44:
F_53 ( V_6 ) ;
F_53 ( V_26 ) ;
if ( V_39 )
F_16 ( V_6 ) ;
F_16 ( V_6 ) ;
F_16 ( V_26 ) ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_7 * V_18 )
{
static T_1 V_47 = V_48 + 1 ;
struct V_7 V_49 ;
F_5 ( & V_49 , V_18 -> V_50 , V_18 -> V_19 ) ;
if ( V_18 -> V_19 == V_10 ) {
bool V_51 = false ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_52 ; V_11 ++ ) {
if ( V_47 <= V_48 )
V_47 = V_48 + 1 ;
V_49 . V_19 = V_47 ++ ;
if ( ! F_18 ( & V_49 ) ) {
V_51 = true ;
break;
}
}
if ( ! V_51 )
return - V_53 ;
} else {
if ( V_18 -> V_19 <= V_48 &&
! F_55 ( V_54 ) ) {
return - V_55 ;
}
if ( F_18 ( & V_49 ) )
return - V_56 ;
}
F_5 ( & V_4 -> V_8 , V_49 . V_50 , V_49 . V_19 ) ;
F_14 ( V_4 ) ;
F_10 ( F_56 ( & V_4 -> V_8 ) , V_4 ) ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_7 * V_18 )
{
return V_1 -> V_57 ( V_4 , V_18 ) ;
}
static int F_6 ( struct V_5 * V_6 , struct V_7 * V_18 )
{
struct V_3 * V_4 = F_40 ( V_6 ) ;
T_1 V_58 ;
int V_59 ;
if ( F_4 ( & V_4 -> V_8 ) )
return - V_60 ;
V_58 = V_1 -> V_2 () ;
if ( V_18 -> V_50 != V_58 && V_18 -> V_50 != V_9 )
return - V_53 ;
switch ( V_6 -> V_61 -> type ) {
case V_62 :
F_26 ( & V_23 ) ;
V_59 = F_54 ( V_4 , V_18 ) ;
F_27 ( & V_23 ) ;
break;
case V_63 :
V_59 = F_57 ( V_4 , V_18 ) ;
break;
default:
V_59 = - V_60 ;
break;
}
return V_59 ;
}
struct V_5 * F_58 ( struct V_64 * V_64 ,
struct V_65 * V_5 ,
struct V_5 * V_66 ,
T_2 V_67 ,
unsigned short type ,
int V_68 )
{
struct V_5 * V_6 ;
struct V_3 * V_69 ;
struct V_3 * V_4 ;
V_6 = F_59 ( V_64 , V_70 , V_67 , & V_71 , V_68 ) ;
if ( ! V_6 )
return NULL ;
F_60 ( V_5 , V_6 ) ;
if ( ! V_5 )
V_6 -> V_72 = type ;
V_4 = F_40 ( V_6 ) ;
F_5 ( & V_4 -> V_8 , V_9 , V_10 ) ;
F_5 ( & V_4 -> V_22 , V_9 , V_10 ) ;
V_6 -> V_73 = V_74 ;
V_6 -> V_75 = V_76 ;
V_6 -> V_45 = 0 ;
F_61 ( V_6 , V_77 ) ;
F_9 ( & V_4 -> V_16 ) ;
F_9 ( & V_4 -> V_17 ) ;
V_4 -> V_26 = NULL ;
F_9 ( & V_4 -> V_30 ) ;
F_9 ( & V_4 -> V_33 ) ;
V_4 -> V_43 = false ;
V_4 -> V_78 = false ;
V_4 -> V_79 = false ;
V_4 -> V_80 = 0 ;
V_69 = V_66 ? F_40 ( V_66 ) : NULL ;
if ( V_66 ) {
V_4 -> V_81 = V_69 -> V_81 ;
V_4 -> V_82 = F_62 ( V_69 -> V_82 ) ;
V_4 -> V_83 = V_69 -> V_83 ;
} else {
V_4 -> V_81 = F_55 ( V_84 ) ;
V_4 -> V_82 = F_63 () ;
V_4 -> V_83 = V_85 ;
}
if ( V_1 -> V_86 ( V_4 , V_69 ) < 0 ) {
F_64 ( V_6 ) ;
return NULL ;
}
if ( V_5 )
F_25 ( V_4 ) ;
return V_6 ;
}
static void F_65 ( struct V_5 * V_6 )
{
if ( V_6 ) {
struct V_87 * V_88 ;
struct V_5 * V_27 ;
struct V_3 * V_4 ;
V_4 = F_40 ( V_6 ) ;
V_27 = NULL ;
V_1 -> V_89 ( V_4 ) ;
F_51 ( V_6 ) ;
F_66 ( V_6 ) ;
V_6 -> V_90 = V_91 ;
while ( ( V_88 = F_67 ( & V_6 -> V_92 ) ) )
F_68 ( V_88 ) ;
while ( ( V_27 = F_44 ( V_6 ) ) != NULL ) {
F_65 ( V_27 ) ;
F_16 ( V_27 ) ;
}
F_53 ( V_6 ) ;
F_16 ( V_6 ) ;
}
}
static void V_74 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_40 ( V_6 ) ;
V_1 -> V_93 ( V_4 ) ;
F_5 ( & V_4 -> V_8 , V_9 , V_10 ) ;
F_5 ( & V_4 -> V_22 , V_9 , V_10 ) ;
F_69 ( V_4 -> V_82 ) ;
}
static int V_76 ( struct V_5 * V_6 , struct V_87 * V_88 )
{
int V_94 ;
V_94 = F_70 ( V_6 , V_88 ) ;
if ( V_94 )
F_68 ( V_88 ) ;
return V_94 ;
}
T_3 F_71 ( struct V_3 * V_4 )
{
return V_1 -> V_95 ( V_4 ) ;
}
T_3 F_72 ( struct V_3 * V_4 )
{
return V_1 -> V_96 ( V_4 ) ;
}
static int F_73 ( struct V_65 * V_5 )
{
F_65 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
V_5 -> V_97 = V_46 ;
return 0 ;
}
static int
F_74 ( struct V_65 * V_5 , struct V_98 * V_18 , int V_99 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_7 * V_100 ;
V_6 = V_5 -> V_6 ;
if ( F_75 ( V_18 , V_99 , & V_100 ) != 0 )
return - V_60 ;
F_51 ( V_6 ) ;
V_94 = F_6 ( V_6 , V_100 ) ;
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_76 ( struct V_65 * V_5 ,
struct V_98 * V_18 , int * V_99 , int V_101 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_100 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
V_94 = 0 ;
F_51 ( V_6 ) ;
if ( V_101 ) {
if ( V_5 -> V_97 != V_102 ) {
V_94 = - V_103 ;
goto V_44;
}
V_100 = & V_4 -> V_22 ;
} else {
V_100 = & V_4 -> V_8 ;
}
if ( ! V_100 ) {
V_94 = - V_60 ;
goto V_44;
}
F_77 ( sizeof( * V_100 ) > 128 ) ;
memcpy ( V_18 , V_100 , sizeof( * V_100 ) ) ;
* V_99 = sizeof( * V_100 ) ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_78 ( struct V_65 * V_5 , int V_35 )
{
int V_94 ;
struct V_5 * V_6 ;
V_35 ++ ;
if ( ( V_35 & ~ V_91 ) || ! V_35 )
return - V_60 ;
V_6 = V_5 -> V_6 ;
if ( V_5 -> V_97 == V_104 ) {
V_94 = - V_103 ;
if ( V_6 -> V_72 == V_62 )
return V_94 ;
} else {
V_5 -> V_97 = V_105 ;
V_94 = 0 ;
}
V_35 = V_35 & ( V_106 | V_107 ) ;
if ( V_35 ) {
F_51 ( V_6 ) ;
V_6 -> V_90 |= V_35 ;
V_6 -> V_108 ( V_6 ) ;
F_53 ( V_6 ) ;
if ( V_6 -> V_72 == V_62 ) {
F_61 ( V_6 , V_77 ) ;
F_48 ( V_6 , V_35 ) ;
}
}
return V_94 ;
}
static unsigned int F_79 ( struct V_109 * V_109 , struct V_65 * V_5 ,
T_4 * V_110 )
{
struct V_5 * V_6 ;
unsigned int V_111 ;
struct V_3 * V_4 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
F_80 ( V_109 , F_81 ( V_6 ) , V_110 ) ;
V_111 = 0 ;
if ( V_6 -> V_112 )
V_111 |= V_113 ;
if ( ( V_6 -> V_90 == V_91 ) ||
( ( V_6 -> V_90 & V_107 ) &&
( V_4 -> V_80 & V_107 ) ) ) {
V_111 |= V_114 ;
}
if ( V_6 -> V_90 & V_106 ||
V_4 -> V_80 & V_107 ) {
V_111 |= V_115 ;
}
if ( V_5 -> type == V_63 ) {
if ( ! F_82 ( & V_6 -> V_92 ) ||
( V_6 -> V_90 & V_106 ) ) {
V_111 |= V_116 | V_117 ;
}
if ( ! ( V_6 -> V_90 & V_107 ) )
V_111 |= V_118 | V_119 | V_120 ;
} else if ( V_5 -> type == V_62 ) {
F_51 ( V_6 ) ;
if ( V_6 -> V_45 == V_121
&& ! F_46 ( V_6 ) )
V_111 |= V_116 | V_117 ;
if ( V_1 -> V_122 ( V_4 ) &&
! ( V_6 -> V_90 & V_106 ) ) {
bool V_123 = false ;
int V_25 = V_1 -> V_124 (
V_4 , 1 , & V_123 ) ;
if ( V_25 < 0 ) {
V_111 |= V_113 ;
} else {
if ( V_123 )
V_111 |= V_116 | V_117 ;
}
}
if ( V_6 -> V_90 & V_106 ||
V_4 -> V_80 & V_107 ) {
V_111 |= V_116 | V_117 ;
}
if ( V_6 -> V_45 == V_102 ) {
if ( ! ( V_6 -> V_90 & V_107 ) ) {
bool V_125 = false ;
int V_25 = V_1 -> V_126 (
V_4 , 1 , & V_125 ) ;
if ( V_25 < 0 ) {
V_111 |= V_113 ;
} else {
if ( V_125 )
V_111 |= V_118 | V_119 ;
}
}
}
if ( V_6 -> V_45 == V_104 ) {
if ( ! ( V_6 -> V_90 & V_107 ) )
V_111 |= V_118 | V_119 ;
}
F_53 ( V_6 ) ;
}
return V_111 ;
}
static int F_83 ( struct V_65 * V_5 , struct V_127 * V_128 ,
T_5 V_129 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
if ( V_128 -> V_130 & V_131 )
return - V_132 ;
V_94 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
F_51 ( V_6 ) ;
V_94 = F_2 ( V_4 ) ;
if ( V_94 )
goto V_44;
if ( V_128 -> V_133 &&
F_75 ( V_128 -> V_133 , V_128 -> V_134 ,
& V_22 ) == 0 ) {
if ( V_22 -> V_50 == V_9 )
V_22 -> V_50 = V_1 -> V_2 () ;
if ( ! F_4 ( V_22 ) ) {
V_94 = - V_60 ;
goto V_44;
}
} else if ( V_5 -> V_97 == V_102 ) {
V_22 = & V_4 -> V_22 ;
if ( V_22 -> V_50 == V_9 )
V_22 -> V_50 = V_1 -> V_2 () ;
if ( ! F_4 ( & V_4 -> V_22 ) ) {
V_94 = - V_60 ;
goto V_44;
}
} else {
V_94 = - V_60 ;
goto V_44;
}
if ( ! V_1 -> V_135 ( V_22 -> V_50 ,
V_22 -> V_19 ) ) {
V_94 = - V_60 ;
goto V_44;
}
V_94 = V_1 -> V_136 ( V_4 , V_22 , V_128 , V_129 ) ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_84 ( struct V_65 * V_5 ,
struct V_98 * V_18 , int V_99 , int V_137 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
V_94 = F_75 ( V_18 , V_99 , & V_22 ) ;
if ( V_94 == - V_138 && V_22 -> V_139 == V_140 ) {
F_51 ( V_6 ) ;
F_5 ( & V_4 -> V_22 , V_9 ,
V_10 ) ;
V_5 -> V_97 = V_104 ;
F_53 ( V_6 ) ;
return 0 ;
} else if ( V_94 != 0 )
return - V_60 ;
F_51 ( V_6 ) ;
V_94 = F_2 ( V_4 ) ;
if ( V_94 )
goto V_44;
if ( ! V_1 -> V_135 ( V_22 -> V_50 ,
V_22 -> V_19 ) ) {
V_94 = - V_60 ;
goto V_44;
}
memcpy ( & V_4 -> V_22 , V_22 , sizeof( V_4 -> V_22 ) ) ;
V_5 -> V_97 = V_102 ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_85 ( struct V_65 * V_5 , struct V_127 * V_128 ,
T_5 V_129 , int V_137 )
{
return V_1 -> V_141 ( F_40 ( V_5 -> V_6 ) , V_128 , V_129 , V_137 ) ;
}
static int F_86 ( struct V_3 * V_4 )
{
if ( ! V_1 -> V_142 )
return - V_132 ;
return V_1 -> V_142 ( V_4 ) ;
}
static void F_87 ( struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_143 = 0 ;
V_4 = F_50 ( V_38 , struct V_3 , V_40 . V_38 ) ;
V_6 = F_3 ( V_4 ) ;
F_51 ( V_6 ) ;
if ( V_6 -> V_45 == V_144 &&
( V_6 -> V_90 != V_91 ) ) {
V_6 -> V_45 = V_104 ;
V_6 -> V_112 = V_145 ;
V_6 -> V_146 ( V_6 ) ;
V_143 = 1 ;
}
F_53 ( V_6 ) ;
if ( V_143 )
F_86 ( V_4 ) ;
F_16 ( V_6 ) ;
}
static int F_88 ( struct V_65 * V_5 , struct V_98 * V_18 ,
int V_99 , int V_137 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
long V_147 ;
F_89 ( V_110 ) ;
V_94 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
F_51 ( V_6 ) ;
switch ( V_5 -> V_97 ) {
case V_102 :
V_94 = - V_148 ;
goto V_44;
case V_105 :
V_94 = - V_60 ;
goto V_44;
case V_144 :
V_94 = - V_149 ;
break;
default:
if ( ( V_6 -> V_45 == V_121 ) ||
F_75 ( V_18 , V_99 , & V_22 ) != 0 ) {
V_94 = - V_60 ;
goto V_44;
}
if ( ! V_1 -> V_150 ( V_22 -> V_50 ,
V_22 -> V_19 ) ) {
V_94 = - V_151 ;
goto V_44;
}
memcpy ( & V_4 -> V_22 , V_22 ,
sizeof( V_4 -> V_22 ) ) ;
V_94 = F_2 ( V_4 ) ;
if ( V_94 )
goto V_44;
V_6 -> V_45 = V_144 ;
V_94 = V_1 -> V_152 ( V_4 ) ;
if ( V_94 < 0 )
goto V_44;
V_5 -> V_97 = V_144 ;
V_94 = - V_153 ;
}
V_147 = V_4 -> V_83 ;
F_90 ( F_81 ( V_6 ) , & V_110 , V_154 ) ;
while ( V_6 -> V_45 != V_102 && V_6 -> V_112 == 0 ) {
if ( V_137 & V_155 ) {
F_11 ( V_6 ) ;
F_91 ( & V_4 -> V_40 ,
F_87 ) ;
F_92 ( & V_4 -> V_40 , V_147 ) ;
goto V_156;
}
F_53 ( V_6 ) ;
V_147 = F_93 ( V_147 ) ;
F_51 ( V_6 ) ;
if ( F_94 ( V_157 ) ) {
V_94 = F_95 ( V_147 ) ;
V_6 -> V_45 = V_104 ;
V_5 -> V_97 = V_104 ;
F_86 ( V_4 ) ;
goto V_156;
} else if ( V_147 == 0 ) {
V_94 = - V_145 ;
V_6 -> V_45 = V_104 ;
V_5 -> V_97 = V_104 ;
F_86 ( V_4 ) ;
goto V_156;
}
F_90 ( F_81 ( V_6 ) , & V_110 , V_154 ) ;
}
if ( V_6 -> V_112 ) {
V_94 = - V_6 -> V_112 ;
V_6 -> V_45 = V_104 ;
V_5 -> V_97 = V_104 ;
} else {
V_94 = 0 ;
}
V_156:
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_97 ( struct V_65 * V_5 , struct V_65 * V_158 , int V_137 ,
bool V_68 )
{
struct V_5 * V_26 ;
int V_94 ;
struct V_5 * V_31 ;
struct V_3 * V_32 ;
long V_147 ;
F_89 ( V_110 ) ;
V_94 = 0 ;
V_26 = V_5 -> V_6 ;
F_51 ( V_26 ) ;
if ( V_5 -> type != V_62 ) {
V_94 = - V_132 ;
goto V_44;
}
if ( V_26 -> V_45 != V_121 ) {
V_94 = - V_60 ;
goto V_44;
}
V_147 = F_98 ( V_26 , V_137 & V_155 ) ;
F_90 ( F_81 ( V_26 ) , & V_110 , V_154 ) ;
while ( ( V_31 = F_44 ( V_26 ) ) == NULL &&
V_26 -> V_112 == 0 ) {
F_53 ( V_26 ) ;
V_147 = F_93 ( V_147 ) ;
F_96 ( F_81 ( V_26 ) , & V_110 ) ;
F_51 ( V_26 ) ;
if ( F_94 ( V_157 ) ) {
V_94 = F_95 ( V_147 ) ;
goto V_44;
} else if ( V_147 == 0 ) {
V_94 = - V_159 ;
goto V_44;
}
F_90 ( F_81 ( V_26 ) , & V_110 , V_154 ) ;
}
F_96 ( F_81 ( V_26 ) , & V_110 ) ;
if ( V_26 -> V_112 )
V_94 = - V_26 -> V_112 ;
if ( V_31 ) {
V_26 -> V_42 -- ;
F_52 ( V_31 , V_41 ) ;
V_32 = F_40 ( V_31 ) ;
if ( V_94 ) {
V_32 -> V_43 = true ;
} else {
V_158 -> V_97 = V_102 ;
F_99 ( V_31 , V_158 ) ;
}
F_53 ( V_31 ) ;
F_16 ( V_31 ) ;
}
V_44:
F_53 ( V_26 ) ;
return V_94 ;
}
static int F_100 ( struct V_65 * V_5 , int V_160 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
V_6 = V_5 -> V_6 ;
F_51 ( V_6 ) ;
if ( V_5 -> type != V_62 ) {
V_94 = - V_132 ;
goto V_44;
}
if ( V_5 -> V_97 != V_104 ) {
V_94 = - V_60 ;
goto V_44;
}
V_4 = F_40 ( V_6 ) ;
if ( ! F_4 ( & V_4 -> V_8 ) ) {
V_94 = - V_60 ;
goto V_44;
}
V_6 -> V_161 = V_160 ;
V_6 -> V_45 = V_121 ;
V_94 = 0 ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_101 ( struct V_65 * V_5 ,
int V_162 ,
int V_163 ,
char T_6 * V_164 ,
unsigned int V_165 )
{
int V_94 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_7 V_166 ;
if ( V_162 != V_70 )
return - V_167 ;
#define F_102 ( T_8 ) \
do { \
if (optlen < sizeof(_v)) { \
err = -EINVAL; \
goto exit; \
} \
if (copy_from_user(&_v, optval, sizeof(_v)) != 0) { \
err = -EFAULT; \
goto exit; \
} \
} while (0)
V_94 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
F_51 ( V_6 ) ;
switch ( V_163 ) {
case V_168 :
F_102 ( V_166 ) ;
V_1 -> V_169 ( V_4 , V_166 ) ;
break;
case V_170 :
F_102 ( V_166 ) ;
V_1 -> V_171 ( V_4 , V_166 ) ;
break;
case V_172 :
F_102 ( V_166 ) ;
V_1 -> V_173 ( V_4 , V_166 ) ;
break;
case V_174 : {
struct V_175 V_176 ;
F_102 ( V_176 ) ;
if ( V_176 . V_177 >= 0 && V_176 . V_178 < V_179 &&
V_176 . V_177 < ( V_180 / V_181 - 1 ) ) {
V_4 -> V_83 = V_176 . V_177 * V_181 +
F_103 ( V_176 . V_178 , ( 1000000 / V_181 ) ) ;
if ( V_4 -> V_83 == 0 )
V_4 -> V_83 =
V_85 ;
} else {
V_94 = - V_182 ;
}
break;
}
default:
V_94 = - V_167 ;
break;
}
#undef F_102
exit:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_104 ( struct V_65 * V_5 ,
int V_162 , int V_163 ,
char T_6 * V_164 ,
int T_6 * V_165 )
{
int V_94 ;
int V_129 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_7 V_166 ;
if ( V_162 != V_70 )
return - V_167 ;
V_94 = F_105 ( V_129 , V_165 ) ;
if ( V_94 != 0 )
return V_94 ;
#define F_106 ( T_8 ) \
do { \
if (len < sizeof(_v)) \
return -EINVAL; \
\
len = sizeof(_v); \
if (copy_to_user(optval, &_v, len) != 0) \
return -EFAULT; \
\
} while (0)
V_94 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
switch ( V_163 ) {
case V_168 :
V_166 = V_1 -> V_183 ( V_4 ) ;
F_106 ( V_166 ) ;
break;
case V_170 :
V_166 = V_1 -> V_184 ( V_4 ) ;
F_106 ( V_166 ) ;
break;
case V_172 :
V_166 = V_1 -> V_185 ( V_4 ) ;
F_106 ( V_166 ) ;
break;
case V_174 : {
struct V_175 V_176 ;
V_176 . V_177 = V_4 -> V_83 / V_181 ;
V_176 . V_178 =
( V_4 -> V_83 -
V_176 . V_177 * V_181 ) * ( 1000000 / V_181 ) ;
F_106 ( V_176 ) ;
break;
}
default:
return - V_167 ;
}
V_94 = F_107 ( V_129 , V_165 ) ;
if ( V_94 != 0 )
return - V_186 ;
#undef F_106
return 0 ;
}
static int F_108 ( struct V_65 * V_5 , struct V_127 * V_128 ,
T_5 V_129 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_9 V_187 ;
long V_147 ;
int V_94 ;
struct V_188 V_189 ;
F_89 ( V_110 ) ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
V_187 = 0 ;
V_94 = 0 ;
if ( V_128 -> V_130 & V_131 )
return - V_132 ;
F_51 ( V_6 ) ;
if ( V_128 -> V_134 ) {
V_94 = V_6 -> V_45 == V_102 ? - V_148 : - V_132 ;
goto V_44;
}
if ( V_6 -> V_90 & V_107 ||
V_4 -> V_80 & V_106 ) {
V_94 = - V_190 ;
goto V_44;
}
if ( V_6 -> V_45 != V_102 ||
! F_4 ( & V_4 -> V_8 ) ) {
V_94 = - V_103 ;
goto V_44;
}
if ( ! F_4 ( & V_4 -> V_22 ) ) {
V_94 = - V_191 ;
goto V_44;
}
V_147 = F_98 ( V_6 , V_128 -> V_130 & V_192 ) ;
V_94 = V_1 -> V_193 ( V_4 , & V_189 ) ;
if ( V_94 < 0 )
goto V_44;
while ( V_187 < V_129 ) {
T_9 V_194 ;
F_90 ( F_81 ( V_6 ) , & V_110 , V_154 ) ;
while ( F_72 ( V_4 ) == 0 &&
V_6 -> V_112 == 0 &&
! ( V_6 -> V_90 & V_107 ) &&
! ( V_4 -> V_80 & V_106 ) ) {
if ( V_147 == 0 ) {
V_94 = - V_159 ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
goto V_195;
}
V_94 = V_1 -> V_196 ( V_4 , & V_189 ) ;
if ( V_94 < 0 ) {
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
goto V_195;
}
F_53 ( V_6 ) ;
V_147 = F_93 ( V_147 ) ;
F_51 ( V_6 ) ;
if ( F_94 ( V_157 ) ) {
V_94 = F_95 ( V_147 ) ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
goto V_195;
} else if ( V_147 == 0 ) {
V_94 = - V_159 ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
goto V_195;
}
F_90 ( F_81 ( V_6 ) , & V_110 ,
V_154 ) ;
}
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
if ( V_6 -> V_112 ) {
V_94 = - V_6 -> V_112 ;
goto V_195;
} else if ( ( V_6 -> V_90 & V_107 ) ||
( V_4 -> V_80 & V_106 ) ) {
V_94 = - V_190 ;
goto V_195;
}
V_94 = V_1 -> V_197 ( V_4 , & V_189 ) ;
if ( V_94 < 0 )
goto V_195;
V_194 = V_1 -> V_198 (
V_4 , V_128 ,
V_129 - V_187 ) ;
if ( V_194 < 0 ) {
V_94 = - V_199 ;
goto V_195;
}
V_187 += V_194 ;
V_94 = V_1 -> V_200 (
V_4 , V_194 , & V_189 ) ;
if ( V_94 < 0 )
goto V_195;
}
V_195:
if ( V_187 > 0 )
V_94 = V_187 ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int
F_109 ( struct V_65 * V_5 , struct V_127 * V_128 , T_5 V_129 ,
int V_137 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_94 ;
T_5 V_201 ;
T_9 V_202 ;
long V_147 ;
struct V_203 V_204 ;
F_89 ( V_110 ) ;
V_6 = V_5 -> V_6 ;
V_4 = F_40 ( V_6 ) ;
V_94 = 0 ;
F_51 ( V_6 ) ;
if ( V_6 -> V_45 != V_102 ) {
if ( F_110 ( V_6 , V_77 ) )
V_94 = 0 ;
else
V_94 = - V_103 ;
goto V_44;
}
if ( V_137 & V_131 ) {
V_94 = - V_132 ;
goto V_44;
}
if ( V_6 -> V_90 & V_106 ) {
V_94 = 0 ;
goto V_44;
}
if ( ! V_129 ) {
V_94 = 0 ;
goto V_44;
}
V_201 = F_111 ( V_6 , V_137 & V_205 , V_129 ) ;
if ( V_201 >= V_1 -> V_206 ( V_4 ) ) {
V_94 = - V_199 ;
goto V_44;
}
V_147 = F_112 ( V_6 , V_137 & V_192 ) ;
V_202 = 0 ;
V_94 = V_1 -> V_207 ( V_4 , V_201 , & V_204 ) ;
if ( V_94 < 0 )
goto V_44;
while ( 1 ) {
T_3 V_208 ;
F_90 ( F_81 ( V_6 ) , & V_110 , V_154 ) ;
V_208 = F_71 ( V_4 ) ;
if ( V_208 == 0 ) {
if ( V_6 -> V_112 != 0 ||
( V_6 -> V_90 & V_106 ) ||
( V_4 -> V_80 & V_107 ) ) {
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
break;
}
if ( V_147 == 0 ) {
V_94 = - V_159 ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
break;
}
V_94 = V_1 -> V_209 (
V_4 , V_201 , & V_204 ) ;
if ( V_94 < 0 ) {
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
break;
}
F_53 ( V_6 ) ;
V_147 = F_93 ( V_147 ) ;
F_51 ( V_6 ) ;
if ( F_94 ( V_157 ) ) {
V_94 = F_95 ( V_147 ) ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
break;
} else if ( V_147 == 0 ) {
V_94 = - V_159 ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
break;
}
} else {
T_9 V_210 ;
F_96 ( F_81 ( V_6 ) , & V_110 ) ;
if ( V_208 < 0 ) {
V_94 = - V_199 ;
goto V_44;
}
V_94 = V_1 -> V_211 (
V_4 , V_201 , & V_204 ) ;
if ( V_94 < 0 )
break;
V_210 = V_1 -> V_212 (
V_4 , V_128 ,
V_129 - V_202 , V_137 ) ;
if ( V_210 < 0 ) {
V_94 = - V_199 ;
break;
}
V_202 += V_210 ;
V_94 = V_1 -> V_213 (
V_4 , V_201 , V_210 ,
! ( V_137 & V_214 ) , & V_204 ) ;
if ( V_94 < 0 )
goto V_44;
if ( V_210 >= V_201 || V_137 & V_214 )
break;
V_201 -= V_210 ;
}
}
if ( V_6 -> V_112 )
V_94 = - V_6 -> V_112 ;
else if ( V_6 -> V_90 & V_106 )
V_94 = 0 ;
if ( V_202 > 0 )
V_94 = V_202 ;
V_44:
F_53 ( V_6 ) ;
return V_94 ;
}
static int F_113 ( struct V_64 * V_64 , struct V_65 * V_5 ,
int V_215 , int V_68 )
{
if ( ! V_5 )
return - V_60 ;
if ( V_215 && V_215 != V_216 )
return - V_217 ;
switch ( V_5 -> type ) {
case V_63 :
V_5 -> V_218 = & V_219 ;
break;
case V_62 :
V_5 -> V_218 = & V_220 ;
break;
default:
return - V_221 ;
}
V_5 -> V_97 = V_104 ;
return F_58 ( V_64 , V_5 , NULL , V_222 , 0 , V_68 ) ? 0 : - V_199 ;
}
static long F_114 ( struct V_109 * V_223 ,
unsigned int V_224 , void T_6 * V_225 )
{
T_1 T_6 * V_226 = V_225 ;
int V_59 = 0 ;
switch ( V_224 ) {
case V_227 :
if ( F_107 ( V_1 -> V_2 () , V_226 ) != 0 )
V_59 = - V_186 ;
break;
default:
F_115 ( L_1 , V_224 ) ;
V_59 = - V_60 ;
}
return V_59 ;
}
static long F_116 ( struct V_109 * V_223 ,
unsigned int V_224 , unsigned long V_228 )
{
return F_114 ( V_223 , V_224 , ( void T_6 * ) V_228 ) ;
}
static long F_117 ( struct V_109 * V_223 ,
unsigned int V_224 , unsigned long V_228 )
{
return F_114 ( V_223 , V_224 , F_118 ( V_228 ) ) ;
}
int F_119 ( const struct V_229 * V_230 , struct V_231 * V_82 )
{
int V_94 = F_120 ( & V_232 ) ;
if ( V_94 )
return V_94 ;
if ( V_1 ) {
V_94 = - V_233 ;
goto V_234;
}
V_71 . V_82 = V_82 ;
V_1 = V_230 ;
F_7 () ;
V_235 . V_236 = V_237 ;
V_94 = F_121 ( & V_235 ) ;
if ( V_94 ) {
F_115 ( L_2 ) ;
goto V_238;
}
V_94 = F_122 ( & V_71 , 1 ) ;
if ( V_94 ) {
F_115 ( L_3 ) ;
goto V_239;
}
V_94 = F_123 ( & V_240 ) ;
if ( V_94 ) {
F_115 ( L_4 ,
V_70 , V_94 ) ;
goto V_241;
}
F_124 ( & V_232 ) ;
return 0 ;
V_241:
F_125 ( & V_71 ) ;
V_239:
F_126 ( & V_235 ) ;
V_238:
V_1 = NULL ;
V_234:
F_124 ( & V_232 ) ;
return V_94 ;
}
void F_127 ( void )
{
F_128 ( & V_232 ) ;
F_126 ( & V_235 ) ;
F_129 ( V_70 ) ;
F_125 ( & V_71 ) ;
F_130 () ;
V_1 = NULL ;
F_124 ( & V_232 ) ;
}
const struct V_229 * F_131 ( void )
{
return V_1 ;
}
