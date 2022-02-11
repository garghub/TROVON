int F_1 ( void )
{
return V_1 -> V_2 () ;
}
static void F_2 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_3 ( V_4 ) ; V_3 ++ )
F_4 ( & V_4 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < F_3 ( V_5 ) ; V_3 ++ )
F_4 ( & V_5 [ V_3 ] ) ;
}
static void F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_6 ( & V_9 -> V_10 ) ;
F_7 ( & V_9 -> V_11 , V_7 ) ;
}
static void F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_6 ( & V_9 -> V_10 ) ;
F_7 ( & V_9 -> V_12 , V_7 ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
F_10 ( & V_9 -> V_11 ) ;
F_11 ( & V_9 -> V_10 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
F_10 ( & V_9 -> V_12 ) ;
F_11 ( & V_9 -> V_10 ) ;
}
static struct V_13 * F_13 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
F_14 (vsk, vsock_bound_sockets(addr), bound_table)
if ( V_15 -> V_16 == V_9 -> V_17 . V_16 )
return F_15 ( V_9 ) ;
return NULL ;
}
static struct V_13 * F_16 ( struct V_14 * V_18 ,
struct V_14 * V_19 )
{
struct V_8 * V_9 ;
F_14 (vsk, vsock_connected_sockets(src, dst),
connected_table) {
if ( F_17 ( V_18 , & V_9 -> V_20 ) &&
V_19 -> V_16 == V_9 -> V_17 . V_16 ) {
return F_15 ( V_9 ) ;
}
}
return NULL ;
}
static bool F_18 ( struct V_8 * V_9 )
{
return ! F_19 ( & V_9 -> V_11 ) ;
}
static bool F_20 ( struct V_8 * V_9 )
{
return ! F_19 ( & V_9 -> V_12 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
F_22 ( & V_21 ) ;
F_5 ( V_22 , V_9 ) ;
F_23 ( & V_21 ) ;
}
void F_24 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_25 (
& V_9 -> V_20 , & V_9 -> V_17 ) ;
F_22 ( & V_21 ) ;
F_8 ( V_7 , V_9 ) ;
F_23 ( & V_21 ) ;
}
void F_26 ( struct V_8 * V_9 )
{
F_22 ( & V_21 ) ;
F_9 ( V_9 ) ;
F_23 ( & V_21 ) ;
}
void F_27 ( struct V_8 * V_9 )
{
F_22 ( & V_21 ) ;
F_12 ( V_9 ) ;
F_23 ( & V_21 ) ;
}
struct V_13 * F_28 ( struct V_14 * V_15 )
{
struct V_13 * V_10 ;
F_22 ( & V_21 ) ;
V_10 = F_13 ( V_15 ) ;
if ( V_10 )
F_6 ( V_10 ) ;
F_23 ( & V_21 ) ;
return V_10 ;
}
struct V_13 * F_29 ( struct V_14 * V_18 ,
struct V_14 * V_19 )
{
struct V_13 * V_10 ;
F_22 ( & V_21 ) ;
V_10 = F_16 ( V_18 , V_19 ) ;
if ( V_10 )
F_6 ( V_10 ) ;
F_23 ( & V_21 ) ;
return V_10 ;
}
static bool F_30 ( struct V_8 * V_9 )
{
bool V_23 ;
F_22 ( & V_21 ) ;
V_23 = F_18 ( V_9 ) ;
F_23 ( & V_21 ) ;
return V_23 ;
}
static bool F_31 ( struct V_8 * V_9 )
{
bool V_23 ;
F_22 ( & V_21 ) ;
V_23 = F_20 ( V_9 ) ;
F_23 ( & V_21 ) ;
return V_23 ;
}
void F_32 ( void (* F_33)( struct V_13 * V_10 ) )
{
int V_3 ;
F_22 ( & V_21 ) ;
for ( V_3 = 0 ; V_3 < F_3 ( V_5 ) ; V_3 ++ ) {
struct V_8 * V_9 ;
F_14 ( V_9 , & V_5 [ V_3 ] ,
V_12 ) ;
F_33 ( F_15 ( V_9 ) ) ;
}
F_23 ( & V_21 ) ;
}
void F_34 ( struct V_13 * V_24 , struct V_13 * V_25 )
{
struct V_8 * V_26 ;
struct V_8 * V_27 ;
V_26 = F_35 ( V_24 ) ;
V_27 = F_35 ( V_25 ) ;
F_6 ( V_25 ) ;
F_6 ( V_24 ) ;
F_36 ( & V_27 -> V_28 , & V_26 -> V_28 ) ;
}
void F_37 ( struct V_13 * V_24 , struct V_13 * V_25 )
{
struct V_8 * V_27 = F_35 ( V_25 ) ;
F_10 ( & V_27 -> V_28 ) ;
F_11 ( V_24 ) ;
F_11 ( V_25 ) ;
}
void F_38 ( struct V_13 * V_24 , struct V_13 * V_29 )
{
struct V_8 * V_26 ;
struct V_8 * V_30 ;
V_26 = F_35 ( V_24 ) ;
V_30 = F_35 ( V_29 ) ;
F_6 ( V_29 ) ;
F_6 ( V_24 ) ;
F_36 ( & V_30 -> V_31 , & V_26 -> V_31 ) ;
}
static struct V_13 * F_39 ( struct V_13 * V_24 )
{
struct V_8 * V_26 ;
struct V_8 * V_30 ;
V_26 = F_35 ( V_24 ) ;
if ( F_19 ( & V_26 -> V_31 ) )
return NULL ;
V_30 = F_40 ( V_26 -> V_31 . V_32 ,
struct V_8 , V_31 ) ;
F_10 ( & V_30 -> V_31 ) ;
F_11 ( V_24 ) ;
return F_15 ( V_30 ) ;
}
static bool F_41 ( struct V_13 * V_10 )
{
struct V_8 * V_9 = F_35 ( V_10 ) ;
return F_19 ( & V_9 -> V_31 ) ;
}
static bool F_42 ( struct V_13 * V_10 )
{
struct V_8 * V_9 = F_35 ( V_10 ) ;
return ! F_19 ( & V_9 -> V_28 ) ;
}
static int F_43 ( struct V_13 * V_10 , int V_33 )
{
return V_1 -> V_34 ( F_35 ( V_10 ) , V_33 ) ;
}
void F_44 ( struct V_35 * V_36 )
{
struct V_13 * V_10 ;
struct V_13 * V_24 ;
struct V_8 * V_9 ;
bool V_37 ;
V_9 = F_45 ( V_36 , struct V_8 , V_38 . V_36 ) ;
V_10 = F_15 ( V_9 ) ;
V_24 = V_9 -> V_24 ;
V_37 = true ;
F_46 ( V_24 ) ;
F_46 ( V_10 ) ;
if ( F_42 ( V_10 ) ) {
F_37 ( V_24 , V_10 ) ;
} else if ( ! V_9 -> V_39 ) {
V_37 = false ;
goto V_40;
}
V_24 -> V_41 -- ;
if ( F_31 ( V_9 ) )
F_27 ( V_9 ) ;
V_10 -> V_42 = V_43 ;
V_40:
F_47 ( V_10 ) ;
F_47 ( V_24 ) ;
if ( V_37 )
F_11 ( V_10 ) ;
F_11 ( V_10 ) ;
F_11 ( V_24 ) ;
}
static int F_48 ( struct V_8 * V_9 ,
struct V_14 * V_15 )
{
static T_1 V_44 = V_45 + 1 ;
struct V_14 V_46 ;
F_49 ( & V_46 , V_15 -> V_47 , V_15 -> V_16 ) ;
if ( V_15 -> V_16 == V_48 ) {
bool V_49 = false ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_50 ; V_3 ++ ) {
if ( V_44 <= V_45 )
V_44 = V_45 + 1 ;
V_46 . V_16 = V_44 ++ ;
if ( ! F_13 ( & V_46 ) ) {
V_49 = true ;
break;
}
}
if ( ! V_49 )
return - V_51 ;
} else {
if ( V_15 -> V_16 <= V_45 &&
! F_50 ( V_52 ) ) {
return - V_53 ;
}
if ( F_13 ( & V_46 ) )
return - V_54 ;
}
F_49 ( & V_9 -> V_17 , V_46 . V_47 , V_46 . V_16 ) ;
F_9 ( V_9 ) ;
F_5 ( F_51 ( & V_9 -> V_17 ) , V_9 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 ,
struct V_14 * V_15 )
{
return V_1 -> V_55 ( V_9 , V_15 ) ;
}
static int F_53 ( struct V_13 * V_10 , struct V_14 * V_15 )
{
struct V_8 * V_9 = F_35 ( V_10 ) ;
T_1 V_56 ;
int V_57 ;
if ( F_54 ( & V_9 -> V_17 ) )
return - V_58 ;
V_56 = V_1 -> V_2 () ;
if ( V_15 -> V_47 != V_56 && V_15 -> V_47 != V_59 )
return - V_51 ;
switch ( V_10 -> V_60 -> type ) {
case V_61 :
F_22 ( & V_21 ) ;
V_57 = F_48 ( V_9 , V_15 ) ;
F_23 ( & V_21 ) ;
break;
case V_62 :
V_57 = F_52 ( V_9 , V_15 ) ;
break;
default:
V_57 = - V_58 ;
break;
}
return V_57 ;
}
struct V_13 * F_55 ( struct V_63 * V_63 ,
struct V_64 * V_13 ,
struct V_13 * V_65 ,
T_2 V_66 ,
unsigned short type )
{
struct V_13 * V_10 ;
struct V_8 * V_67 ;
struct V_8 * V_9 ;
V_10 = F_56 ( V_63 , V_68 , V_66 , & V_69 ) ;
if ( ! V_10 )
return NULL ;
F_57 ( V_13 , V_10 ) ;
if ( ! V_13 )
V_10 -> V_70 = type ;
V_9 = F_35 ( V_10 ) ;
F_49 ( & V_9 -> V_17 , V_59 , V_48 ) ;
F_49 ( & V_9 -> V_20 , V_59 , V_48 ) ;
V_10 -> V_71 = V_72 ;
V_10 -> V_73 = V_74 ;
V_10 -> V_42 = 0 ;
F_58 ( V_10 , V_75 ) ;
F_4 ( & V_9 -> V_11 ) ;
F_4 ( & V_9 -> V_12 ) ;
V_9 -> V_24 = NULL ;
F_4 ( & V_9 -> V_28 ) ;
F_4 ( & V_9 -> V_31 ) ;
V_9 -> V_39 = false ;
V_9 -> V_76 = false ;
V_9 -> V_77 = false ;
V_9 -> V_78 = 0 ;
V_67 = V_65 ? F_35 ( V_65 ) : NULL ;
if ( V_65 ) {
V_9 -> V_79 = V_67 -> V_79 ;
V_9 -> V_80 = F_59 ( V_67 -> V_80 ) ;
V_9 -> V_81 = V_67 -> V_81 ;
} else {
V_9 -> V_79 = F_50 ( V_82 ) ;
V_9 -> V_80 = F_60 () ;
V_9 -> V_81 = V_83 ;
}
if ( V_1 -> V_84 ( V_9 , V_67 ) < 0 ) {
F_61 ( V_10 ) ;
return NULL ;
}
if ( V_13 )
F_21 ( V_9 ) ;
return V_10 ;
}
static void F_62 ( struct V_13 * V_10 )
{
if ( V_10 ) {
struct V_85 * V_86 ;
struct V_13 * V_25 ;
struct V_8 * V_9 ;
V_9 = F_35 ( V_10 ) ;
V_25 = NULL ;
if ( F_30 ( V_9 ) )
F_26 ( V_9 ) ;
if ( F_31 ( V_9 ) )
F_27 ( V_9 ) ;
V_1 -> V_87 ( V_9 ) ;
F_46 ( V_10 ) ;
F_63 ( V_10 ) ;
V_10 -> V_88 = V_89 ;
while ( ( V_86 = F_64 ( & V_10 -> V_90 ) ) )
F_65 ( V_86 ) ;
while ( ( V_25 = F_39 ( V_10 ) ) != NULL ) {
F_62 ( V_25 ) ;
F_11 ( V_25 ) ;
}
F_47 ( V_10 ) ;
F_11 ( V_10 ) ;
}
}
static void V_72 ( struct V_13 * V_10 )
{
struct V_8 * V_9 = F_35 ( V_10 ) ;
V_1 -> V_91 ( V_9 ) ;
F_49 ( & V_9 -> V_17 , V_59 , V_48 ) ;
F_49 ( & V_9 -> V_20 , V_59 , V_48 ) ;
F_66 ( V_9 -> V_80 ) ;
}
static int V_74 ( struct V_13 * V_10 , struct V_85 * V_86 )
{
int V_92 ;
V_92 = F_67 ( V_10 , V_86 ) ;
if ( V_92 )
F_65 ( V_86 ) ;
return V_92 ;
}
T_3 F_68 ( struct V_8 * V_9 )
{
return V_1 -> V_93 ( V_9 ) ;
}
T_3 F_69 ( struct V_8 * V_9 )
{
return V_1 -> V_94 ( V_9 ) ;
}
static int F_70 ( struct V_64 * V_13 )
{
F_62 ( V_13 -> V_10 ) ;
V_13 -> V_10 = NULL ;
V_13 -> V_95 = V_43 ;
return 0 ;
}
static int
F_71 ( struct V_64 * V_13 , struct V_96 * V_15 , int V_97 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_14 * V_98 ;
V_10 = V_13 -> V_10 ;
if ( F_72 ( V_15 , V_97 , & V_98 ) != 0 )
return - V_58 ;
F_46 ( V_10 ) ;
V_92 = F_53 ( V_10 , V_98 ) ;
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_73 ( struct V_64 * V_13 ,
struct V_96 * V_15 , int * V_97 , int V_99 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
struct V_14 * V_98 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
V_92 = 0 ;
F_46 ( V_10 ) ;
if ( V_99 ) {
if ( V_13 -> V_95 != V_100 ) {
V_92 = - V_101 ;
goto V_40;
}
V_98 = & V_9 -> V_20 ;
} else {
V_98 = & V_9 -> V_17 ;
}
if ( ! V_98 ) {
V_92 = - V_58 ;
goto V_40;
}
F_74 ( sizeof( * V_98 ) > 128 ) ;
memcpy ( V_15 , V_98 , sizeof( * V_98 ) ) ;
* V_97 = sizeof( * V_98 ) ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_75 ( struct V_64 * V_13 , int V_33 )
{
int V_92 ;
struct V_13 * V_10 ;
V_33 ++ ;
if ( ( V_33 & ~ V_89 ) || ! V_33 )
return - V_58 ;
V_10 = V_13 -> V_10 ;
if ( V_13 -> V_95 == V_102 ) {
V_92 = - V_101 ;
if ( V_10 -> V_70 == V_61 )
return V_92 ;
} else {
V_13 -> V_95 = V_103 ;
V_92 = 0 ;
}
V_33 = V_33 & ( V_104 | V_105 ) ;
if ( V_33 ) {
F_46 ( V_10 ) ;
V_10 -> V_88 |= V_33 ;
V_10 -> V_106 ( V_10 ) ;
F_47 ( V_10 ) ;
if ( V_10 -> V_70 == V_61 ) {
F_58 ( V_10 , V_75 ) ;
F_43 ( V_10 , V_33 ) ;
}
}
return V_92 ;
}
static unsigned int F_76 ( struct V_107 * V_107 , struct V_64 * V_13 ,
T_4 * V_108 )
{
struct V_13 * V_10 ;
unsigned int V_109 ;
struct V_8 * V_9 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
F_77 ( V_107 , F_78 ( V_10 ) , V_108 ) ;
V_109 = 0 ;
if ( V_10 -> V_110 )
V_109 |= V_111 ;
if ( ( V_10 -> V_88 == V_89 ) ||
( ( V_10 -> V_88 & V_105 ) &&
( V_9 -> V_78 & V_105 ) ) ) {
V_109 |= V_112 ;
}
if ( V_10 -> V_88 & V_104 ||
V_9 -> V_78 & V_105 ) {
V_109 |= V_113 ;
}
if ( V_13 -> type == V_62 ) {
if ( ! F_79 ( & V_10 -> V_90 ) ||
( V_10 -> V_88 & V_104 ) ) {
V_109 |= V_114 | V_115 ;
}
if ( ! ( V_10 -> V_88 & V_105 ) )
V_109 |= V_116 | V_117 | V_118 ;
} else if ( V_13 -> type == V_61 ) {
F_46 ( V_10 ) ;
if ( V_10 -> V_42 == V_119
&& ! F_41 ( V_10 ) )
V_109 |= V_114 | V_115 ;
if ( V_1 -> V_120 ( V_9 ) &&
! ( V_10 -> V_88 & V_104 ) ) {
bool V_121 = false ;
int V_23 = V_1 -> V_122 (
V_9 , 1 , & V_121 ) ;
if ( V_23 < 0 ) {
V_109 |= V_111 ;
} else {
if ( V_121 )
V_109 |= V_114 | V_115 ;
}
}
if ( V_10 -> V_88 & V_104 ||
V_9 -> V_78 & V_105 ) {
V_109 |= V_114 | V_115 ;
}
if ( V_10 -> V_42 == V_100 ) {
if ( ! ( V_10 -> V_88 & V_105 ) ) {
bool V_123 = false ;
int V_23 = V_1 -> V_124 (
V_9 , 1 , & V_123 ) ;
if ( V_23 < 0 ) {
V_109 |= V_111 ;
} else {
if ( V_123 )
V_109 |= V_116 | V_117 ;
}
}
}
if ( V_10 -> V_42 == V_102 ) {
if ( ! ( V_10 -> V_88 & V_105 ) )
V_109 |= V_116 | V_117 ;
}
F_47 ( V_10 ) ;
}
return V_109 ;
}
static int F_80 ( struct V_125 * V_125 , struct V_64 * V_13 ,
struct V_126 * V_127 , T_5 V_128 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
struct V_14 * V_20 ;
if ( V_127 -> V_129 & V_130 )
return - V_131 ;
V_92 = 0 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
F_46 ( V_10 ) ;
if ( ! F_54 ( & V_9 -> V_17 ) ) {
struct V_14 V_17 ;
F_49 ( & V_17 , V_59 , V_48 ) ;
V_92 = F_53 ( V_10 , & V_17 ) ;
if ( V_92 != 0 )
goto V_40;
}
if ( V_127 -> V_132 &&
F_72 ( V_127 -> V_132 , V_127 -> V_133 ,
& V_20 ) == 0 ) {
if ( V_20 -> V_47 == V_59 )
V_20 -> V_47 = V_1 -> V_2 () ;
if ( ! F_54 ( V_20 ) ) {
V_92 = - V_58 ;
goto V_40;
}
} else if ( V_13 -> V_95 == V_100 ) {
V_20 = & V_9 -> V_20 ;
if ( V_20 -> V_47 == V_59 )
V_20 -> V_47 = V_1 -> V_2 () ;
if ( ! F_54 ( & V_9 -> V_20 ) ) {
V_92 = - V_58 ;
goto V_40;
}
} else {
V_92 = - V_58 ;
goto V_40;
}
if ( ! V_1 -> V_134 ( V_20 -> V_47 ,
V_20 -> V_16 ) ) {
V_92 = - V_58 ;
goto V_40;
}
V_92 = V_1 -> V_135 ( V_9 , V_20 , V_127 -> V_136 , V_128 ) ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_81 ( struct V_64 * V_13 ,
struct V_96 * V_15 , int V_97 , int V_137 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
struct V_14 * V_20 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
V_92 = F_72 ( V_15 , V_97 , & V_20 ) ;
if ( V_92 == - V_138 && V_20 -> V_139 == V_140 ) {
F_46 ( V_10 ) ;
F_49 ( & V_9 -> V_20 , V_59 ,
V_48 ) ;
V_13 -> V_95 = V_102 ;
F_47 ( V_10 ) ;
return 0 ;
} else if ( V_92 != 0 )
return - V_58 ;
F_46 ( V_10 ) ;
if ( ! F_54 ( & V_9 -> V_17 ) ) {
struct V_14 V_17 ;
F_49 ( & V_17 , V_59 , V_48 ) ;
V_92 = F_53 ( V_10 , & V_17 ) ;
if ( V_92 != 0 )
goto V_40;
}
if ( ! V_1 -> V_134 ( V_20 -> V_47 ,
V_20 -> V_16 ) ) {
V_92 = - V_58 ;
goto V_40;
}
memcpy ( & V_9 -> V_20 , V_20 , sizeof( V_9 -> V_20 ) ) ;
V_13 -> V_95 = V_100 ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_82 ( struct V_125 * V_125 , struct V_64 * V_13 ,
struct V_126 * V_127 , T_5 V_128 , int V_137 )
{
return V_1 -> V_141 ( V_125 , F_35 ( V_13 -> V_10 ) , V_127 , V_128 ,
V_137 ) ;
}
static void F_83 ( struct V_35 * V_36 )
{
struct V_13 * V_10 ;
struct V_8 * V_9 ;
V_9 = F_45 ( V_36 , struct V_8 , V_38 . V_36 ) ;
V_10 = F_15 ( V_9 ) ;
F_46 ( V_10 ) ;
if ( V_10 -> V_42 == V_142 &&
( V_10 -> V_88 != V_89 ) ) {
V_10 -> V_42 = V_102 ;
V_10 -> V_110 = V_143 ;
V_10 -> V_144 ( V_10 ) ;
}
F_47 ( V_10 ) ;
F_11 ( V_10 ) ;
}
static int F_84 ( struct V_64 * V_13 , struct V_96 * V_15 ,
int V_97 , int V_137 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
struct V_14 * V_20 ;
long V_145 ;
F_85 ( V_108 ) ;
V_92 = 0 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
F_46 ( V_10 ) ;
switch ( V_13 -> V_95 ) {
case V_100 :
V_92 = - V_146 ;
goto V_40;
case V_103 :
V_92 = - V_58 ;
goto V_40;
case V_142 :
V_92 = - V_147 ;
break;
default:
if ( ( V_10 -> V_42 == V_119 ) ||
F_72 ( V_15 , V_97 , & V_20 ) != 0 ) {
V_92 = - V_58 ;
goto V_40;
}
if ( ! V_1 -> V_148 ( V_20 -> V_47 ,
V_20 -> V_16 ) ) {
V_92 = - V_149 ;
goto V_40;
}
memcpy ( & V_9 -> V_20 , V_20 ,
sizeof( V_9 -> V_20 ) ) ;
if ( ! F_54 ( & V_9 -> V_17 ) ) {
struct V_14 V_17 ;
F_49 ( & V_17 , V_59 ,
V_48 ) ;
V_92 = F_53 ( V_10 , & V_17 ) ;
if ( V_92 != 0 )
goto V_40;
}
V_10 -> V_42 = V_142 ;
V_92 = V_1 -> V_150 ( V_9 ) ;
if ( V_92 < 0 )
goto V_40;
V_13 -> V_95 = V_142 ;
V_92 = - V_151 ;
}
V_145 = V_9 -> V_81 ;
F_86 ( F_78 ( V_10 ) , & V_108 , V_152 ) ;
while ( V_10 -> V_42 != V_100 && V_10 -> V_110 == 0 ) {
if ( V_137 & V_153 ) {
F_6 ( V_10 ) ;
F_87 ( & V_9 -> V_38 ,
F_83 ) ;
F_88 ( & V_9 -> V_38 , V_145 ) ;
goto V_154;
}
F_47 ( V_10 ) ;
V_145 = F_89 ( V_145 ) ;
F_46 ( V_10 ) ;
if ( F_90 ( V_155 ) ) {
V_92 = F_91 ( V_145 ) ;
goto V_156;
} else if ( V_145 == 0 ) {
V_92 = - V_143 ;
goto V_156;
}
F_86 ( F_78 ( V_10 ) , & V_108 , V_152 ) ;
}
if ( V_10 -> V_110 ) {
V_92 = - V_10 -> V_110 ;
goto V_156;
} else
V_92 = 0 ;
V_154:
F_92 ( F_78 ( V_10 ) , & V_108 ) ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
V_156:
V_10 -> V_42 = V_102 ;
V_13 -> V_95 = V_102 ;
goto V_154;
}
static int F_93 ( struct V_64 * V_13 , struct V_64 * V_157 , int V_137 )
{
struct V_13 * V_24 ;
int V_92 ;
struct V_13 * V_29 ;
struct V_8 * V_30 ;
long V_145 ;
F_85 ( V_108 ) ;
V_92 = 0 ;
V_24 = V_13 -> V_10 ;
F_46 ( V_24 ) ;
if ( V_13 -> type != V_61 ) {
V_92 = - V_131 ;
goto V_40;
}
if ( V_24 -> V_42 != V_119 ) {
V_92 = - V_58 ;
goto V_40;
}
V_145 = F_94 ( V_24 , V_137 & V_153 ) ;
F_86 ( F_78 ( V_24 ) , & V_108 , V_152 ) ;
while ( ( V_29 = F_39 ( V_24 ) ) == NULL &&
V_24 -> V_110 == 0 ) {
F_47 ( V_24 ) ;
V_145 = F_89 ( V_145 ) ;
F_46 ( V_24 ) ;
if ( F_90 ( V_155 ) ) {
V_92 = F_91 ( V_145 ) ;
goto V_154;
} else if ( V_145 == 0 ) {
V_92 = - V_158 ;
goto V_154;
}
F_86 ( F_78 ( V_24 ) , & V_108 , V_152 ) ;
}
if ( V_24 -> V_110 )
V_92 = - V_24 -> V_110 ;
if ( V_29 ) {
V_24 -> V_41 -- ;
F_46 ( V_29 ) ;
V_30 = F_35 ( V_29 ) ;
if ( V_92 ) {
V_30 -> V_39 = true ;
F_47 ( V_29 ) ;
F_11 ( V_29 ) ;
goto V_154;
}
V_157 -> V_95 = V_100 ;
F_95 ( V_29 , V_157 ) ;
F_47 ( V_29 ) ;
F_11 ( V_29 ) ;
}
V_154:
F_92 ( F_78 ( V_24 ) , & V_108 ) ;
V_40:
F_47 ( V_24 ) ;
return V_92 ;
}
static int F_96 ( struct V_64 * V_13 , int V_159 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
V_10 = V_13 -> V_10 ;
F_46 ( V_10 ) ;
if ( V_13 -> type != V_61 ) {
V_92 = - V_131 ;
goto V_40;
}
if ( V_13 -> V_95 != V_102 ) {
V_92 = - V_58 ;
goto V_40;
}
V_9 = F_35 ( V_10 ) ;
if ( ! F_54 ( & V_9 -> V_17 ) ) {
V_92 = - V_58 ;
goto V_40;
}
V_10 -> V_160 = V_159 ;
V_10 -> V_42 = V_119 ;
V_92 = 0 ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_97 ( struct V_64 * V_13 ,
int V_161 ,
int V_162 ,
char T_6 * V_163 ,
unsigned int V_164 )
{
int V_92 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
T_7 V_165 ;
if ( V_161 != V_68 )
return - V_166 ;
#define F_98 ( T_8 ) \
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
V_92 = 0 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
F_46 ( V_10 ) ;
switch ( V_162 ) {
case V_167 :
F_98 ( V_165 ) ;
V_1 -> V_168 ( V_9 , V_165 ) ;
break;
case V_169 :
F_98 ( V_165 ) ;
V_1 -> V_170 ( V_9 , V_165 ) ;
break;
case V_171 :
F_98 ( V_165 ) ;
V_1 -> V_172 ( V_9 , V_165 ) ;
break;
case V_173 : {
struct V_174 V_175 ;
F_98 ( V_175 ) ;
if ( V_175 . V_176 >= 0 && V_175 . V_177 < V_178 &&
V_175 . V_176 < ( V_179 / V_180 - 1 ) ) {
V_9 -> V_81 = V_175 . V_176 * V_180 +
F_99 ( V_175 . V_177 , ( 1000000 / V_180 ) ) ;
if ( V_9 -> V_81 == 0 )
V_9 -> V_81 =
V_83 ;
} else {
V_92 = - V_181 ;
}
break;
}
default:
V_92 = - V_166 ;
break;
}
#undef F_98
exit:
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_100 ( struct V_64 * V_13 ,
int V_161 , int V_162 ,
char T_6 * V_163 ,
int T_6 * V_164 )
{
int V_92 ;
int V_128 ;
struct V_13 * V_10 ;
struct V_8 * V_9 ;
T_7 V_165 ;
if ( V_161 != V_68 )
return - V_166 ;
V_92 = F_101 ( V_128 , V_164 ) ;
if ( V_92 != 0 )
return V_92 ;
#define F_102 ( T_8 ) \
do { \
if (len < sizeof(_v)) \
return -EINVAL; \
\
len = sizeof(_v); \
if (copy_to_user(optval, &_v, len) != 0) \
return -EFAULT; \
\
} while (0)
V_92 = 0 ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
switch ( V_162 ) {
case V_167 :
V_165 = V_1 -> V_182 ( V_9 ) ;
F_102 ( V_165 ) ;
break;
case V_169 :
V_165 = V_1 -> V_183 ( V_9 ) ;
F_102 ( V_165 ) ;
break;
case V_171 :
V_165 = V_1 -> V_184 ( V_9 ) ;
F_102 ( V_165 ) ;
break;
case V_173 : {
struct V_174 V_175 ;
V_175 . V_176 = V_9 -> V_81 / V_180 ;
V_175 . V_177 =
( V_9 -> V_81 -
V_175 . V_176 * V_180 ) * ( 1000000 / V_180 ) ;
F_102 ( V_175 ) ;
break;
}
default:
return - V_166 ;
}
V_92 = F_103 ( V_128 , V_164 ) ;
if ( V_92 != 0 )
return - V_185 ;
#undef F_102
return 0 ;
}
static int F_104 ( struct V_125 * V_125 , struct V_64 * V_13 ,
struct V_126 * V_127 , T_5 V_128 )
{
struct V_13 * V_10 ;
struct V_8 * V_9 ;
T_9 V_186 ;
long V_145 ;
int V_92 ;
struct V_187 V_188 ;
F_85 ( V_108 ) ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
V_186 = 0 ;
V_92 = 0 ;
if ( V_127 -> V_129 & V_130 )
return - V_131 ;
F_46 ( V_10 ) ;
if ( V_127 -> V_133 ) {
V_92 = V_10 -> V_42 == V_100 ? - V_146 : - V_131 ;
goto V_40;
}
if ( V_10 -> V_88 & V_105 ||
V_9 -> V_78 & V_104 ) {
V_92 = - V_189 ;
goto V_40;
}
if ( V_10 -> V_42 != V_100 ||
! F_54 ( & V_9 -> V_17 ) ) {
V_92 = - V_101 ;
goto V_40;
}
if ( ! F_54 ( & V_9 -> V_20 ) ) {
V_92 = - V_190 ;
goto V_40;
}
V_145 = F_94 ( V_10 , V_127 -> V_129 & V_191 ) ;
V_92 = V_1 -> V_192 ( V_9 , & V_188 ) ;
if ( V_92 < 0 )
goto V_40;
F_86 ( F_78 ( V_10 ) , & V_108 , V_152 ) ;
while ( V_186 < V_128 ) {
T_9 V_193 ;
while ( F_69 ( V_9 ) == 0 &&
V_10 -> V_110 == 0 &&
! ( V_10 -> V_88 & V_105 ) &&
! ( V_9 -> V_78 & V_104 ) ) {
if ( V_145 == 0 ) {
V_92 = - V_158 ;
goto V_154;
}
V_92 = V_1 -> V_194 ( V_9 , & V_188 ) ;
if ( V_92 < 0 )
goto V_154;
F_47 ( V_10 ) ;
V_145 = F_89 ( V_145 ) ;
F_46 ( V_10 ) ;
if ( F_90 ( V_155 ) ) {
V_92 = F_91 ( V_145 ) ;
goto V_154;
} else if ( V_145 == 0 ) {
V_92 = - V_158 ;
goto V_154;
}
F_86 ( F_78 ( V_10 ) , & V_108 ,
V_152 ) ;
}
if ( V_10 -> V_110 ) {
V_92 = - V_10 -> V_110 ;
goto V_154;
} else if ( ( V_10 -> V_88 & V_105 ) ||
( V_9 -> V_78 & V_104 ) ) {
V_92 = - V_189 ;
goto V_154;
}
V_92 = V_1 -> V_195 ( V_9 , & V_188 ) ;
if ( V_92 < 0 )
goto V_154;
V_193 = V_1 -> V_196 (
V_9 , V_127 -> V_136 ,
V_128 - V_186 ) ;
if ( V_193 < 0 ) {
V_92 = - V_197 ;
goto V_154;
}
V_186 += V_193 ;
V_92 = V_1 -> V_198 (
V_9 , V_193 , & V_188 ) ;
if ( V_92 < 0 )
goto V_154;
}
V_154:
if ( V_186 > 0 )
V_92 = V_186 ;
F_92 ( F_78 ( V_10 ) , & V_108 ) ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
}
static int
F_105 ( struct V_125 * V_125 ,
struct V_64 * V_13 ,
struct V_126 * V_127 , T_5 V_128 , int V_137 )
{
struct V_13 * V_10 ;
struct V_8 * V_9 ;
int V_92 ;
T_5 V_199 ;
T_9 V_200 ;
long V_145 ;
struct V_201 V_202 ;
F_85 ( V_108 ) ;
V_10 = V_13 -> V_10 ;
V_9 = F_35 ( V_10 ) ;
V_92 = 0 ;
V_127 -> V_133 = 0 ;
F_46 ( V_10 ) ;
if ( V_10 -> V_42 != V_100 ) {
if ( F_106 ( V_10 , V_75 ) )
V_92 = 0 ;
else
V_92 = - V_101 ;
goto V_40;
}
if ( V_137 & V_130 ) {
V_92 = - V_131 ;
goto V_40;
}
if ( V_10 -> V_88 & V_104 ) {
V_92 = 0 ;
goto V_40;
}
if ( ! V_128 ) {
V_92 = 0 ;
goto V_40;
}
V_199 = F_107 ( V_10 , V_137 & V_203 , V_128 ) ;
if ( V_199 >= V_1 -> V_204 ( V_9 ) ) {
V_92 = - V_197 ;
goto V_40;
}
V_145 = F_108 ( V_10 , V_137 & V_191 ) ;
V_200 = 0 ;
V_92 = V_1 -> V_205 ( V_9 , V_199 , & V_202 ) ;
if ( V_92 < 0 )
goto V_40;
F_86 ( F_78 ( V_10 ) , & V_108 , V_152 ) ;
while ( 1 ) {
T_3 V_206 = F_68 ( V_9 ) ;
if ( V_206 < 0 ) {
V_92 = - V_197 ;
goto V_154;
} else if ( V_206 > 0 ) {
T_9 V_207 ;
V_92 = V_1 -> V_208 (
V_9 , V_199 , & V_202 ) ;
if ( V_92 < 0 )
break;
V_207 = V_1 -> V_209 (
V_9 , V_127 -> V_136 ,
V_128 - V_200 , V_137 ) ;
if ( V_207 < 0 ) {
V_92 = - V_197 ;
break;
}
V_200 += V_207 ;
V_92 = V_1 -> V_210 (
V_9 , V_199 , V_207 ,
! ( V_137 & V_211 ) , & V_202 ) ;
if ( V_92 < 0 )
goto V_154;
if ( V_207 >= V_199 || V_137 & V_211 )
break;
V_199 -= V_207 ;
} else {
if ( V_10 -> V_110 != 0 || ( V_10 -> V_88 & V_104 )
|| ( V_9 -> V_78 & V_105 ) ) {
break;
}
if ( V_145 == 0 ) {
V_92 = - V_158 ;
break;
}
V_92 = V_1 -> V_212 (
V_9 , V_199 , & V_202 ) ;
if ( V_92 < 0 )
break;
F_47 ( V_10 ) ;
V_145 = F_89 ( V_145 ) ;
F_46 ( V_10 ) ;
if ( F_90 ( V_155 ) ) {
V_92 = F_91 ( V_145 ) ;
break;
} else if ( V_145 == 0 ) {
V_92 = - V_158 ;
break;
}
F_86 ( F_78 ( V_10 ) , & V_108 ,
V_152 ) ;
}
}
if ( V_10 -> V_110 )
V_92 = - V_10 -> V_110 ;
else if ( V_10 -> V_88 & V_104 )
V_92 = 0 ;
if ( V_200 > 0 ) {
if ( ! ( V_137 & V_211 ) ) {
if ( V_9 -> V_78 & V_105 ) {
if ( F_68 ( V_9 ) <= 0 ) {
V_10 -> V_42 = V_102 ;
F_109 ( V_10 , V_75 ) ;
V_10 -> V_106 ( V_10 ) ;
}
}
}
V_92 = V_200 ;
}
V_154:
F_92 ( F_78 ( V_10 ) , & V_108 ) ;
V_40:
F_47 ( V_10 ) ;
return V_92 ;
}
static int F_110 ( struct V_63 * V_63 , struct V_64 * V_13 ,
int V_213 , int V_214 )
{
if ( ! V_13 )
return - V_58 ;
if ( V_213 && V_213 != V_215 )
return - V_216 ;
switch ( V_13 -> type ) {
case V_62 :
V_13 -> V_217 = & V_218 ;
break;
case V_61 :
V_13 -> V_217 = & V_219 ;
break;
default:
return - V_220 ;
}
V_13 -> V_95 = V_102 ;
return F_55 ( V_63 , V_13 , NULL , V_221 , 0 ) ? 0 : - V_197 ;
}
static long F_111 ( struct V_107 * V_222 ,
unsigned int V_223 , void T_6 * V_224 )
{
T_1 T_6 * V_225 = V_224 ;
int V_57 = 0 ;
switch ( V_223 ) {
case V_226 :
if ( F_103 ( V_1 -> V_2 () , V_225 ) != 0 )
V_57 = - V_185 ;
break;
default:
F_112 ( L_1 , V_223 ) ;
V_57 = - V_58 ;
}
return V_57 ;
}
static long F_113 ( struct V_107 * V_222 ,
unsigned int V_223 , unsigned long V_227 )
{
return F_111 ( V_222 , V_223 , ( void T_6 * ) V_227 ) ;
}
static long F_114 ( struct V_107 * V_222 ,
unsigned int V_223 , unsigned long V_227 )
{
return F_111 ( V_222 , V_223 , F_115 ( V_227 ) ) ;
}
static int F_116 ( void )
{
int V_92 ;
F_2 () ;
V_228 . V_229 = V_230 ;
V_92 = F_117 ( & V_228 ) ;
if ( V_92 ) {
F_112 ( L_2 ) ;
return - V_231 ;
}
V_92 = F_118 ( & V_69 , 1 ) ;
if ( V_92 ) {
F_112 ( L_3 ) ;
goto V_232;
}
V_92 = F_119 ( & V_233 ) ;
if ( V_92 ) {
F_112 ( L_4 ,
V_68 , V_92 ) ;
goto V_234;
}
return 0 ;
V_234:
F_120 ( & V_69 ) ;
V_232:
F_121 ( & V_228 ) ;
return V_92 ;
}
int F_122 ( const struct V_235 * V_236 )
{
int V_57 = F_123 ( & V_237 ) ;
if ( V_57 )
return V_57 ;
if ( V_1 ) {
V_57 = - V_238 ;
goto V_40;
}
V_1 = V_236 ;
V_57 = F_116 () ;
if ( V_57 )
V_1 = NULL ;
V_40:
F_124 ( & V_237 ) ;
return V_57 ;
}
void F_125 ( void )
{
F_126 ( & V_237 ) ;
F_121 ( & V_228 ) ;
F_127 ( V_68 ) ;
F_120 ( & V_69 ) ;
F_128 () ;
V_1 = NULL ;
F_124 ( & V_237 ) ;
}
