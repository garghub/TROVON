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
void F_36 ( void (* F_37)( struct V_5 * V_6 ) )
{
int V_11 ;
F_26 ( & V_23 ) ;
for ( V_11 = 0 ; V_11 < F_8 ( V_13 ) ; V_11 ++ ) {
struct V_3 * V_4 ;
F_19 (vsk, &vsock_connected_table[i],
connected_table)
F_37 ( F_3 ( V_4 ) ) ;
}
F_27 ( & V_23 ) ;
}
void F_38 ( struct V_5 * V_26 , struct V_5 * V_27 )
{
struct V_3 * V_28 ;
struct V_3 * V_29 ;
V_28 = F_39 ( V_26 ) ;
V_29 = F_39 ( V_27 ) ;
F_11 ( V_27 ) ;
F_11 ( V_26 ) ;
F_40 ( & V_29 -> V_30 , & V_28 -> V_30 ) ;
}
void F_41 ( struct V_5 * V_26 , struct V_5 * V_27 )
{
struct V_3 * V_29 = F_39 ( V_27 ) ;
F_15 ( & V_29 -> V_30 ) ;
F_16 ( V_26 ) ;
F_16 ( V_27 ) ;
}
void F_42 ( struct V_5 * V_26 , struct V_5 * V_31 )
{
struct V_3 * V_28 ;
struct V_3 * V_32 ;
V_28 = F_39 ( V_26 ) ;
V_32 = F_39 ( V_31 ) ;
F_11 ( V_31 ) ;
F_11 ( V_26 ) ;
F_40 ( & V_32 -> V_33 , & V_28 -> V_33 ) ;
}
static struct V_5 * F_43 ( struct V_5 * V_26 )
{
struct V_3 * V_28 ;
struct V_3 * V_32 ;
V_28 = F_39 ( V_26 ) ;
if ( F_23 ( & V_28 -> V_33 ) )
return NULL ;
V_32 = F_44 ( V_28 -> V_33 . V_34 ,
struct V_3 , V_33 ) ;
F_15 ( & V_32 -> V_33 ) ;
F_16 ( V_26 ) ;
return F_3 ( V_32 ) ;
}
static bool F_45 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_39 ( V_6 ) ;
return F_23 ( & V_4 -> V_33 ) ;
}
static bool F_46 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_39 ( V_6 ) ;
return ! F_23 ( & V_4 -> V_30 ) ;
}
static int F_47 ( struct V_5 * V_6 , int V_35 )
{
return V_1 -> V_36 ( F_39 ( V_6 ) , V_35 ) ;
}
void F_48 ( struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_5 * V_26 ;
struct V_3 * V_4 ;
bool V_39 ;
V_4 = F_49 ( V_38 , struct V_3 , V_40 . V_38 ) ;
V_6 = F_3 ( V_4 ) ;
V_26 = V_4 -> V_26 ;
V_39 = true ;
F_50 ( V_26 ) ;
F_50 ( V_6 ) ;
if ( F_46 ( V_6 ) ) {
F_41 ( V_26 , V_6 ) ;
} else if ( ! V_4 -> V_41 ) {
V_39 = false ;
goto V_42;
}
V_26 -> V_43 -- ;
if ( F_35 ( V_4 ) )
F_31 ( V_4 ) ;
V_6 -> V_44 = V_45 ;
V_42:
F_51 ( V_6 ) ;
F_51 ( V_26 ) ;
if ( V_39 )
F_16 ( V_6 ) ;
F_16 ( V_6 ) ;
F_16 ( V_26 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_7 * V_18 )
{
static T_1 V_46 = V_47 + 1 ;
struct V_7 V_48 ;
F_5 ( & V_48 , V_18 -> V_49 , V_18 -> V_19 ) ;
if ( V_18 -> V_19 == V_10 ) {
bool V_50 = false ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_51 ; V_11 ++ ) {
if ( V_46 <= V_47 )
V_46 = V_47 + 1 ;
V_48 . V_19 = V_46 ++ ;
if ( ! F_18 ( & V_48 ) ) {
V_50 = true ;
break;
}
}
if ( ! V_50 )
return - V_52 ;
} else {
if ( V_18 -> V_19 <= V_47 &&
! F_53 ( V_53 ) ) {
return - V_54 ;
}
if ( F_18 ( & V_48 ) )
return - V_55 ;
}
F_5 ( & V_4 -> V_8 , V_48 . V_49 , V_48 . V_19 ) ;
F_14 ( V_4 ) ;
F_10 ( F_54 ( & V_4 -> V_8 ) , V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_7 * V_18 )
{
return V_1 -> V_56 ( V_4 , V_18 ) ;
}
static int F_6 ( struct V_5 * V_6 , struct V_7 * V_18 )
{
struct V_3 * V_4 = F_39 ( V_6 ) ;
T_1 V_57 ;
int V_58 ;
if ( F_4 ( & V_4 -> V_8 ) )
return - V_59 ;
V_57 = V_1 -> V_2 () ;
if ( V_18 -> V_49 != V_57 && V_18 -> V_49 != V_9 )
return - V_52 ;
switch ( V_6 -> V_60 -> type ) {
case V_61 :
F_26 ( & V_23 ) ;
V_58 = F_52 ( V_4 , V_18 ) ;
F_27 ( & V_23 ) ;
break;
case V_62 :
V_58 = F_55 ( V_4 , V_18 ) ;
break;
default:
V_58 = - V_59 ;
break;
}
return V_58 ;
}
struct V_5 * F_56 ( struct V_63 * V_63 ,
struct V_64 * V_5 ,
struct V_5 * V_65 ,
T_2 V_66 ,
unsigned short type ,
int V_67 )
{
struct V_5 * V_6 ;
struct V_3 * V_68 ;
struct V_3 * V_4 ;
V_6 = F_57 ( V_63 , V_69 , V_66 , & V_70 , V_67 ) ;
if ( ! V_6 )
return NULL ;
F_58 ( V_5 , V_6 ) ;
if ( ! V_5 )
V_6 -> V_71 = type ;
V_4 = F_39 ( V_6 ) ;
F_5 ( & V_4 -> V_8 , V_9 , V_10 ) ;
F_5 ( & V_4 -> V_22 , V_9 , V_10 ) ;
V_6 -> V_72 = V_73 ;
V_6 -> V_74 = V_75 ;
V_6 -> V_44 = 0 ;
F_59 ( V_6 , V_76 ) ;
F_9 ( & V_4 -> V_16 ) ;
F_9 ( & V_4 -> V_17 ) ;
V_4 -> V_26 = NULL ;
F_9 ( & V_4 -> V_30 ) ;
F_9 ( & V_4 -> V_33 ) ;
V_4 -> V_41 = false ;
V_4 -> V_77 = false ;
V_4 -> V_78 = false ;
V_4 -> V_79 = 0 ;
V_68 = V_65 ? F_39 ( V_65 ) : NULL ;
if ( V_65 ) {
V_4 -> V_80 = V_68 -> V_80 ;
V_4 -> V_81 = F_60 ( V_68 -> V_81 ) ;
V_4 -> V_82 = V_68 -> V_82 ;
} else {
V_4 -> V_80 = F_53 ( V_83 ) ;
V_4 -> V_81 = F_61 () ;
V_4 -> V_82 = V_84 ;
}
if ( V_1 -> V_85 ( V_4 , V_68 ) < 0 ) {
F_62 ( V_6 ) ;
return NULL ;
}
if ( V_5 )
F_25 ( V_4 ) ;
return V_6 ;
}
static void F_63 ( struct V_5 * V_6 )
{
if ( V_6 ) {
struct V_86 * V_87 ;
struct V_5 * V_27 ;
struct V_3 * V_4 ;
V_4 = F_39 ( V_6 ) ;
V_27 = NULL ;
if ( F_34 ( V_4 ) )
F_30 ( V_4 ) ;
if ( F_35 ( V_4 ) )
F_31 ( V_4 ) ;
V_1 -> V_88 ( V_4 ) ;
F_50 ( V_6 ) ;
F_64 ( V_6 ) ;
V_6 -> V_89 = V_90 ;
while ( ( V_87 = F_65 ( & V_6 -> V_91 ) ) )
F_66 ( V_87 ) ;
while ( ( V_27 = F_43 ( V_6 ) ) != NULL ) {
F_63 ( V_27 ) ;
F_16 ( V_27 ) ;
}
F_51 ( V_6 ) ;
F_16 ( V_6 ) ;
}
}
static void V_73 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_39 ( V_6 ) ;
V_1 -> V_92 ( V_4 ) ;
F_5 ( & V_4 -> V_8 , V_9 , V_10 ) ;
F_5 ( & V_4 -> V_22 , V_9 , V_10 ) ;
F_67 ( V_4 -> V_81 ) ;
}
static int V_75 ( struct V_5 * V_6 , struct V_86 * V_87 )
{
int V_93 ;
V_93 = F_68 ( V_6 , V_87 ) ;
if ( V_93 )
F_66 ( V_87 ) ;
return V_93 ;
}
T_3 F_69 ( struct V_3 * V_4 )
{
return V_1 -> V_94 ( V_4 ) ;
}
T_3 F_70 ( struct V_3 * V_4 )
{
return V_1 -> V_95 ( V_4 ) ;
}
static int F_71 ( struct V_64 * V_5 )
{
F_63 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
V_5 -> V_96 = V_45 ;
return 0 ;
}
static int
F_72 ( struct V_64 * V_5 , struct V_97 * V_18 , int V_98 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_7 * V_99 ;
V_6 = V_5 -> V_6 ;
if ( F_73 ( V_18 , V_98 , & V_99 ) != 0 )
return - V_59 ;
F_50 ( V_6 ) ;
V_93 = F_6 ( V_6 , V_99 ) ;
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_74 ( struct V_64 * V_5 ,
struct V_97 * V_18 , int * V_98 , int V_100 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_99 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
V_93 = 0 ;
F_50 ( V_6 ) ;
if ( V_100 ) {
if ( V_5 -> V_96 != V_101 ) {
V_93 = - V_102 ;
goto V_42;
}
V_99 = & V_4 -> V_22 ;
} else {
V_99 = & V_4 -> V_8 ;
}
if ( ! V_99 ) {
V_93 = - V_59 ;
goto V_42;
}
F_75 ( sizeof( * V_99 ) > 128 ) ;
memcpy ( V_18 , V_99 , sizeof( * V_99 ) ) ;
* V_98 = sizeof( * V_99 ) ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_76 ( struct V_64 * V_5 , int V_35 )
{
int V_93 ;
struct V_5 * V_6 ;
V_35 ++ ;
if ( ( V_35 & ~ V_90 ) || ! V_35 )
return - V_59 ;
V_6 = V_5 -> V_6 ;
if ( V_5 -> V_96 == V_103 ) {
V_93 = - V_102 ;
if ( V_6 -> V_71 == V_61 )
return V_93 ;
} else {
V_5 -> V_96 = V_104 ;
V_93 = 0 ;
}
V_35 = V_35 & ( V_105 | V_106 ) ;
if ( V_35 ) {
F_50 ( V_6 ) ;
V_6 -> V_89 |= V_35 ;
V_6 -> V_107 ( V_6 ) ;
F_51 ( V_6 ) ;
if ( V_6 -> V_71 == V_61 ) {
F_59 ( V_6 , V_76 ) ;
F_47 ( V_6 , V_35 ) ;
}
}
return V_93 ;
}
static unsigned int F_77 ( struct V_108 * V_108 , struct V_64 * V_5 ,
T_4 * V_109 )
{
struct V_5 * V_6 ;
unsigned int V_110 ;
struct V_3 * V_4 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
F_78 ( V_108 , F_79 ( V_6 ) , V_109 ) ;
V_110 = 0 ;
if ( V_6 -> V_111 )
V_110 |= V_112 ;
if ( ( V_6 -> V_89 == V_90 ) ||
( ( V_6 -> V_89 & V_106 ) &&
( V_4 -> V_79 & V_106 ) ) ) {
V_110 |= V_113 ;
}
if ( V_6 -> V_89 & V_105 ||
V_4 -> V_79 & V_106 ) {
V_110 |= V_114 ;
}
if ( V_5 -> type == V_62 ) {
if ( ! F_80 ( & V_6 -> V_91 ) ||
( V_6 -> V_89 & V_105 ) ) {
V_110 |= V_115 | V_116 ;
}
if ( ! ( V_6 -> V_89 & V_106 ) )
V_110 |= V_117 | V_118 | V_119 ;
} else if ( V_5 -> type == V_61 ) {
F_50 ( V_6 ) ;
if ( V_6 -> V_44 == V_120
&& ! F_45 ( V_6 ) )
V_110 |= V_115 | V_116 ;
if ( V_1 -> V_121 ( V_4 ) &&
! ( V_6 -> V_89 & V_105 ) ) {
bool V_122 = false ;
int V_25 = V_1 -> V_123 (
V_4 , 1 , & V_122 ) ;
if ( V_25 < 0 ) {
V_110 |= V_112 ;
} else {
if ( V_122 )
V_110 |= V_115 | V_116 ;
}
}
if ( V_6 -> V_89 & V_105 ||
V_4 -> V_79 & V_106 ) {
V_110 |= V_115 | V_116 ;
}
if ( V_6 -> V_44 == V_101 ) {
if ( ! ( V_6 -> V_89 & V_106 ) ) {
bool V_124 = false ;
int V_25 = V_1 -> V_125 (
V_4 , 1 , & V_124 ) ;
if ( V_25 < 0 ) {
V_110 |= V_112 ;
} else {
if ( V_124 )
V_110 |= V_117 | V_118 ;
}
}
}
if ( V_6 -> V_44 == V_103 ) {
if ( ! ( V_6 -> V_89 & V_106 ) )
V_110 |= V_117 | V_118 ;
}
F_51 ( V_6 ) ;
}
return V_110 ;
}
static int F_81 ( struct V_64 * V_5 , struct V_126 * V_127 ,
T_5 V_128 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
if ( V_127 -> V_129 & V_130 )
return - V_131 ;
V_93 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
F_50 ( V_6 ) ;
V_93 = F_2 ( V_4 ) ;
if ( V_93 )
goto V_42;
if ( V_127 -> V_132 &&
F_73 ( V_127 -> V_132 , V_127 -> V_133 ,
& V_22 ) == 0 ) {
if ( V_22 -> V_49 == V_9 )
V_22 -> V_49 = V_1 -> V_2 () ;
if ( ! F_4 ( V_22 ) ) {
V_93 = - V_59 ;
goto V_42;
}
} else if ( V_5 -> V_96 == V_101 ) {
V_22 = & V_4 -> V_22 ;
if ( V_22 -> V_49 == V_9 )
V_22 -> V_49 = V_1 -> V_2 () ;
if ( ! F_4 ( & V_4 -> V_22 ) ) {
V_93 = - V_59 ;
goto V_42;
}
} else {
V_93 = - V_59 ;
goto V_42;
}
if ( ! V_1 -> V_134 ( V_22 -> V_49 ,
V_22 -> V_19 ) ) {
V_93 = - V_59 ;
goto V_42;
}
V_93 = V_1 -> V_135 ( V_4 , V_22 , V_127 , V_128 ) ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_82 ( struct V_64 * V_5 ,
struct V_97 * V_18 , int V_98 , int V_136 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
V_93 = F_73 ( V_18 , V_98 , & V_22 ) ;
if ( V_93 == - V_137 && V_22 -> V_138 == V_139 ) {
F_50 ( V_6 ) ;
F_5 ( & V_4 -> V_22 , V_9 ,
V_10 ) ;
V_5 -> V_96 = V_103 ;
F_51 ( V_6 ) ;
return 0 ;
} else if ( V_93 != 0 )
return - V_59 ;
F_50 ( V_6 ) ;
V_93 = F_2 ( V_4 ) ;
if ( V_93 )
goto V_42;
if ( ! V_1 -> V_134 ( V_22 -> V_49 ,
V_22 -> V_19 ) ) {
V_93 = - V_59 ;
goto V_42;
}
memcpy ( & V_4 -> V_22 , V_22 , sizeof( V_4 -> V_22 ) ) ;
V_5 -> V_96 = V_101 ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_83 ( struct V_64 * V_5 , struct V_126 * V_127 ,
T_5 V_128 , int V_136 )
{
return V_1 -> V_140 ( F_39 ( V_5 -> V_6 ) , V_127 , V_128 , V_136 ) ;
}
static void F_84 ( struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
V_4 = F_49 ( V_38 , struct V_3 , V_40 . V_38 ) ;
V_6 = F_3 ( V_4 ) ;
F_50 ( V_6 ) ;
if ( V_6 -> V_44 == V_141 &&
( V_6 -> V_89 != V_90 ) ) {
V_6 -> V_44 = V_103 ;
V_6 -> V_111 = V_142 ;
V_6 -> V_143 ( V_6 ) ;
}
F_51 ( V_6 ) ;
F_16 ( V_6 ) ;
}
static int F_85 ( struct V_64 * V_5 , struct V_97 * V_18 ,
int V_98 , int V_136 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
long V_144 ;
F_86 ( V_109 ) ;
V_93 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
F_50 ( V_6 ) ;
switch ( V_5 -> V_96 ) {
case V_101 :
V_93 = - V_145 ;
goto V_42;
case V_104 :
V_93 = - V_59 ;
goto V_42;
case V_141 :
V_93 = - V_146 ;
break;
default:
if ( ( V_6 -> V_44 == V_120 ) ||
F_73 ( V_18 , V_98 , & V_22 ) != 0 ) {
V_93 = - V_59 ;
goto V_42;
}
if ( ! V_1 -> V_147 ( V_22 -> V_49 ,
V_22 -> V_19 ) ) {
V_93 = - V_148 ;
goto V_42;
}
memcpy ( & V_4 -> V_22 , V_22 ,
sizeof( V_4 -> V_22 ) ) ;
V_93 = F_2 ( V_4 ) ;
if ( V_93 )
goto V_42;
V_6 -> V_44 = V_141 ;
V_93 = V_1 -> V_149 ( V_4 ) ;
if ( V_93 < 0 )
goto V_42;
V_5 -> V_96 = V_141 ;
V_93 = - V_150 ;
}
V_144 = V_4 -> V_82 ;
F_87 ( F_79 ( V_6 ) , & V_109 , V_151 ) ;
while ( V_6 -> V_44 != V_101 && V_6 -> V_111 == 0 ) {
if ( V_136 & V_152 ) {
F_11 ( V_6 ) ;
F_88 ( & V_4 -> V_40 ,
F_84 ) ;
F_89 ( & V_4 -> V_40 , V_144 ) ;
goto V_153;
}
F_51 ( V_6 ) ;
V_144 = F_90 ( V_144 ) ;
F_50 ( V_6 ) ;
if ( F_91 ( V_154 ) ) {
V_93 = F_92 ( V_144 ) ;
goto V_155;
} else if ( V_144 == 0 ) {
V_93 = - V_142 ;
goto V_155;
}
F_87 ( F_79 ( V_6 ) , & V_109 , V_151 ) ;
}
if ( V_6 -> V_111 ) {
V_93 = - V_6 -> V_111 ;
goto V_155;
} else
V_93 = 0 ;
V_153:
F_93 ( F_79 ( V_6 ) , & V_109 ) ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
V_155:
V_6 -> V_44 = V_103 ;
V_5 -> V_96 = V_103 ;
goto V_153;
}
static int F_94 ( struct V_64 * V_5 , struct V_64 * V_156 , int V_136 )
{
struct V_5 * V_26 ;
int V_93 ;
struct V_5 * V_31 ;
struct V_3 * V_32 ;
long V_144 ;
F_86 ( V_109 ) ;
V_93 = 0 ;
V_26 = V_5 -> V_6 ;
F_50 ( V_26 ) ;
if ( V_5 -> type != V_61 ) {
V_93 = - V_131 ;
goto V_42;
}
if ( V_26 -> V_44 != V_120 ) {
V_93 = - V_59 ;
goto V_42;
}
V_144 = F_95 ( V_26 , V_136 & V_152 ) ;
F_87 ( F_79 ( V_26 ) , & V_109 , V_151 ) ;
while ( ( V_31 = F_43 ( V_26 ) ) == NULL &&
V_26 -> V_111 == 0 ) {
F_51 ( V_26 ) ;
V_144 = F_90 ( V_144 ) ;
F_50 ( V_26 ) ;
if ( F_91 ( V_154 ) ) {
V_93 = F_92 ( V_144 ) ;
goto V_153;
} else if ( V_144 == 0 ) {
V_93 = - V_157 ;
goto V_153;
}
F_87 ( F_79 ( V_26 ) , & V_109 , V_151 ) ;
}
if ( V_26 -> V_111 )
V_93 = - V_26 -> V_111 ;
if ( V_31 ) {
V_26 -> V_43 -- ;
F_50 ( V_31 ) ;
V_32 = F_39 ( V_31 ) ;
if ( V_93 ) {
V_32 -> V_41 = true ;
F_51 ( V_31 ) ;
F_16 ( V_31 ) ;
goto V_153;
}
V_156 -> V_96 = V_101 ;
F_96 ( V_31 , V_156 ) ;
F_51 ( V_31 ) ;
F_16 ( V_31 ) ;
}
V_153:
F_93 ( F_79 ( V_26 ) , & V_109 ) ;
V_42:
F_51 ( V_26 ) ;
return V_93 ;
}
static int F_97 ( struct V_64 * V_5 , int V_158 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
V_6 = V_5 -> V_6 ;
F_50 ( V_6 ) ;
if ( V_5 -> type != V_61 ) {
V_93 = - V_131 ;
goto V_42;
}
if ( V_5 -> V_96 != V_103 ) {
V_93 = - V_59 ;
goto V_42;
}
V_4 = F_39 ( V_6 ) ;
if ( ! F_4 ( & V_4 -> V_8 ) ) {
V_93 = - V_59 ;
goto V_42;
}
V_6 -> V_159 = V_158 ;
V_6 -> V_44 = V_120 ;
V_93 = 0 ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_98 ( struct V_64 * V_5 ,
int V_160 ,
int V_161 ,
char T_6 * V_162 ,
unsigned int V_163 )
{
int V_93 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_7 V_164 ;
if ( V_160 != V_69 )
return - V_165 ;
#define F_99 ( T_8 ) \
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
V_93 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
F_50 ( V_6 ) ;
switch ( V_161 ) {
case V_166 :
F_99 ( V_164 ) ;
V_1 -> V_167 ( V_4 , V_164 ) ;
break;
case V_168 :
F_99 ( V_164 ) ;
V_1 -> V_169 ( V_4 , V_164 ) ;
break;
case V_170 :
F_99 ( V_164 ) ;
V_1 -> V_171 ( V_4 , V_164 ) ;
break;
case V_172 : {
struct V_173 V_174 ;
F_99 ( V_174 ) ;
if ( V_174 . V_175 >= 0 && V_174 . V_176 < V_177 &&
V_174 . V_175 < ( V_178 / V_179 - 1 ) ) {
V_4 -> V_82 = V_174 . V_175 * V_179 +
F_100 ( V_174 . V_176 , ( 1000000 / V_179 ) ) ;
if ( V_4 -> V_82 == 0 )
V_4 -> V_82 =
V_84 ;
} else {
V_93 = - V_180 ;
}
break;
}
default:
V_93 = - V_165 ;
break;
}
#undef F_99
exit:
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_101 ( struct V_64 * V_5 ,
int V_160 , int V_161 ,
char T_6 * V_162 ,
int T_6 * V_163 )
{
int V_93 ;
int V_128 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_7 V_164 ;
if ( V_160 != V_69 )
return - V_165 ;
V_93 = F_102 ( V_128 , V_163 ) ;
if ( V_93 != 0 )
return V_93 ;
#define F_103 ( T_8 ) \
do { \
if (len < sizeof(_v)) \
return -EINVAL; \
\
len = sizeof(_v); \
if (copy_to_user(optval, &_v, len) != 0) \
return -EFAULT; \
\
} while (0)
V_93 = 0 ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
switch ( V_161 ) {
case V_166 :
V_164 = V_1 -> V_181 ( V_4 ) ;
F_103 ( V_164 ) ;
break;
case V_168 :
V_164 = V_1 -> V_182 ( V_4 ) ;
F_103 ( V_164 ) ;
break;
case V_170 :
V_164 = V_1 -> V_183 ( V_4 ) ;
F_103 ( V_164 ) ;
break;
case V_172 : {
struct V_173 V_174 ;
V_174 . V_175 = V_4 -> V_82 / V_179 ;
V_174 . V_176 =
( V_4 -> V_82 -
V_174 . V_175 * V_179 ) * ( 1000000 / V_179 ) ;
F_103 ( V_174 ) ;
break;
}
default:
return - V_165 ;
}
V_93 = F_104 ( V_128 , V_163 ) ;
if ( V_93 != 0 )
return - V_184 ;
#undef F_103
return 0 ;
}
static int F_105 ( struct V_64 * V_5 , struct V_126 * V_127 ,
T_5 V_128 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_9 V_185 ;
long V_144 ;
int V_93 ;
struct V_186 V_187 ;
F_86 ( V_109 ) ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
V_185 = 0 ;
V_93 = 0 ;
if ( V_127 -> V_129 & V_130 )
return - V_131 ;
F_50 ( V_6 ) ;
if ( V_127 -> V_133 ) {
V_93 = V_6 -> V_44 == V_101 ? - V_145 : - V_131 ;
goto V_42;
}
if ( V_6 -> V_89 & V_106 ||
V_4 -> V_79 & V_105 ) {
V_93 = - V_188 ;
goto V_42;
}
if ( V_6 -> V_44 != V_101 ||
! F_4 ( & V_4 -> V_8 ) ) {
V_93 = - V_102 ;
goto V_42;
}
if ( ! F_4 ( & V_4 -> V_22 ) ) {
V_93 = - V_189 ;
goto V_42;
}
V_144 = F_95 ( V_6 , V_127 -> V_129 & V_190 ) ;
V_93 = V_1 -> V_191 ( V_4 , & V_187 ) ;
if ( V_93 < 0 )
goto V_42;
F_87 ( F_79 ( V_6 ) , & V_109 , V_151 ) ;
while ( V_185 < V_128 ) {
T_9 V_192 ;
while ( F_70 ( V_4 ) == 0 &&
V_6 -> V_111 == 0 &&
! ( V_6 -> V_89 & V_106 ) &&
! ( V_4 -> V_79 & V_105 ) ) {
if ( V_144 == 0 ) {
V_93 = - V_157 ;
goto V_153;
}
V_93 = V_1 -> V_193 ( V_4 , & V_187 ) ;
if ( V_93 < 0 )
goto V_153;
F_51 ( V_6 ) ;
V_144 = F_90 ( V_144 ) ;
F_50 ( V_6 ) ;
if ( F_91 ( V_154 ) ) {
V_93 = F_92 ( V_144 ) ;
goto V_153;
} else if ( V_144 == 0 ) {
V_93 = - V_157 ;
goto V_153;
}
F_87 ( F_79 ( V_6 ) , & V_109 ,
V_151 ) ;
}
if ( V_6 -> V_111 ) {
V_93 = - V_6 -> V_111 ;
goto V_153;
} else if ( ( V_6 -> V_89 & V_106 ) ||
( V_4 -> V_79 & V_105 ) ) {
V_93 = - V_188 ;
goto V_153;
}
V_93 = V_1 -> V_194 ( V_4 , & V_187 ) ;
if ( V_93 < 0 )
goto V_153;
V_192 = V_1 -> V_195 (
V_4 , V_127 ,
V_128 - V_185 ) ;
if ( V_192 < 0 ) {
V_93 = - V_196 ;
goto V_153;
}
V_185 += V_192 ;
V_93 = V_1 -> V_197 (
V_4 , V_192 , & V_187 ) ;
if ( V_93 < 0 )
goto V_153;
}
V_153:
if ( V_185 > 0 )
V_93 = V_185 ;
F_93 ( F_79 ( V_6 ) , & V_109 ) ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
}
static int
F_106 ( struct V_64 * V_5 , struct V_126 * V_127 , T_5 V_128 ,
int V_136 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_93 ;
T_5 V_198 ;
T_9 V_199 ;
long V_144 ;
struct V_200 V_201 ;
F_86 ( V_109 ) ;
V_6 = V_5 -> V_6 ;
V_4 = F_39 ( V_6 ) ;
V_93 = 0 ;
F_50 ( V_6 ) ;
if ( V_6 -> V_44 != V_101 ) {
if ( F_107 ( V_6 , V_76 ) )
V_93 = 0 ;
else
V_93 = - V_102 ;
goto V_42;
}
if ( V_136 & V_130 ) {
V_93 = - V_131 ;
goto V_42;
}
if ( V_6 -> V_89 & V_105 ) {
V_93 = 0 ;
goto V_42;
}
if ( ! V_128 ) {
V_93 = 0 ;
goto V_42;
}
V_198 = F_108 ( V_6 , V_136 & V_202 , V_128 ) ;
if ( V_198 >= V_1 -> V_203 ( V_4 ) ) {
V_93 = - V_196 ;
goto V_42;
}
V_144 = F_109 ( V_6 , V_136 & V_190 ) ;
V_199 = 0 ;
V_93 = V_1 -> V_204 ( V_4 , V_198 , & V_201 ) ;
if ( V_93 < 0 )
goto V_42;
F_87 ( F_79 ( V_6 ) , & V_109 , V_151 ) ;
while ( 1 ) {
T_3 V_205 = F_69 ( V_4 ) ;
if ( V_205 < 0 ) {
V_93 = - V_196 ;
goto V_153;
} else if ( V_205 > 0 ) {
T_9 V_206 ;
V_93 = V_1 -> V_207 (
V_4 , V_198 , & V_201 ) ;
if ( V_93 < 0 )
break;
V_206 = V_1 -> V_208 (
V_4 , V_127 ,
V_128 - V_199 , V_136 ) ;
if ( V_206 < 0 ) {
V_93 = - V_196 ;
break;
}
V_199 += V_206 ;
V_93 = V_1 -> V_209 (
V_4 , V_198 , V_206 ,
! ( V_136 & V_210 ) , & V_201 ) ;
if ( V_93 < 0 )
goto V_153;
if ( V_206 >= V_198 || V_136 & V_210 )
break;
V_198 -= V_206 ;
} else {
if ( V_6 -> V_111 != 0 || ( V_6 -> V_89 & V_105 )
|| ( V_4 -> V_79 & V_106 ) ) {
break;
}
if ( V_144 == 0 ) {
V_93 = - V_157 ;
break;
}
V_93 = V_1 -> V_211 (
V_4 , V_198 , & V_201 ) ;
if ( V_93 < 0 )
break;
F_51 ( V_6 ) ;
V_144 = F_90 ( V_144 ) ;
F_50 ( V_6 ) ;
if ( F_91 ( V_154 ) ) {
V_93 = F_92 ( V_144 ) ;
break;
} else if ( V_144 == 0 ) {
V_93 = - V_157 ;
break;
}
F_87 ( F_79 ( V_6 ) , & V_109 ,
V_151 ) ;
}
}
if ( V_6 -> V_111 )
V_93 = - V_6 -> V_111 ;
else if ( V_6 -> V_89 & V_105 )
V_93 = 0 ;
if ( V_199 > 0 ) {
if ( ! ( V_136 & V_210 ) ) {
if ( V_4 -> V_79 & V_106 ) {
if ( F_69 ( V_4 ) <= 0 ) {
V_6 -> V_44 = V_103 ;
F_110 ( V_6 , V_76 ) ;
V_6 -> V_107 ( V_6 ) ;
}
}
}
V_93 = V_199 ;
}
V_153:
F_93 ( F_79 ( V_6 ) , & V_109 ) ;
V_42:
F_51 ( V_6 ) ;
return V_93 ;
}
static int F_111 ( struct V_63 * V_63 , struct V_64 * V_5 ,
int V_212 , int V_67 )
{
if ( ! V_5 )
return - V_59 ;
if ( V_212 && V_212 != V_213 )
return - V_214 ;
switch ( V_5 -> type ) {
case V_62 :
V_5 -> V_215 = & V_216 ;
break;
case V_61 :
V_5 -> V_215 = & V_217 ;
break;
default:
return - V_218 ;
}
V_5 -> V_96 = V_103 ;
return F_56 ( V_63 , V_5 , NULL , V_219 , 0 , V_67 ) ? 0 : - V_196 ;
}
static long F_112 ( struct V_108 * V_220 ,
unsigned int V_221 , void T_6 * V_222 )
{
T_1 T_6 * V_223 = V_222 ;
int V_58 = 0 ;
switch ( V_221 ) {
case V_224 :
if ( F_104 ( V_1 -> V_2 () , V_223 ) != 0 )
V_58 = - V_184 ;
break;
default:
F_113 ( L_1 , V_221 ) ;
V_58 = - V_59 ;
}
return V_58 ;
}
static long F_114 ( struct V_108 * V_220 ,
unsigned int V_221 , unsigned long V_225 )
{
return F_112 ( V_220 , V_221 , ( void T_6 * ) V_225 ) ;
}
static long F_115 ( struct V_108 * V_220 ,
unsigned int V_221 , unsigned long V_225 )
{
return F_112 ( V_220 , V_221 , F_116 ( V_225 ) ) ;
}
int F_117 ( const struct V_226 * V_227 , struct V_228 * V_81 )
{
int V_93 = F_118 ( & V_229 ) ;
if ( V_93 )
return V_93 ;
if ( V_1 ) {
V_93 = - V_230 ;
goto V_231;
}
V_70 . V_81 = V_81 ;
V_1 = V_227 ;
F_7 () ;
V_232 . V_233 = V_234 ;
V_93 = F_119 ( & V_232 ) ;
if ( V_93 ) {
F_113 ( L_2 ) ;
goto V_235;
}
V_93 = F_120 ( & V_70 , 1 ) ;
if ( V_93 ) {
F_113 ( L_3 ) ;
goto V_236;
}
V_93 = F_121 ( & V_237 ) ;
if ( V_93 ) {
F_113 ( L_4 ,
V_69 , V_93 ) ;
goto V_238;
}
F_122 ( & V_229 ) ;
return 0 ;
V_238:
F_123 ( & V_70 ) ;
V_236:
F_124 ( & V_232 ) ;
V_235:
V_1 = NULL ;
V_231:
F_122 ( & V_229 ) ;
return V_93 ;
}
void F_125 ( void )
{
F_126 ( & V_229 ) ;
F_124 ( & V_232 ) ;
F_127 ( V_69 ) ;
F_123 ( & V_70 ) ;
F_128 () ;
V_1 = NULL ;
F_122 ( & V_229 ) ;
}
