static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return V_2 -> V_3 . V_4 [ F_2 () ] ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
T_1 type , T_1 V_9 , int V_10 , T_2 V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) ( V_6 -> V_14 + V_10 ) ;
struct V_2 * V_2 = F_4 ( V_6 -> V_15 ) ;
if ( type == V_16 )
F_5 ( V_6 , V_2 , V_11 , 0 , 0 , F_6 ( V_2 , NULL ) ) ;
else if ( type == V_17 )
F_7 ( V_6 , V_2 , V_6 -> V_15 -> V_18 , 0 ,
F_6 ( V_2 , NULL ) ) ;
if ( ! ( type & V_19 ) )
if ( V_13 -> V_20 == V_21 )
F_8 ( V_6 , V_10 , F_9 ( V_11 ) ) ;
}
T_3 void F_10 ( struct V_1 * V_22 )
{
F_11 ( & V_22 -> V_23 . V_24 ) ;
}
static bool F_12 ( const struct V_5 * V_6 )
{
int V_25 = ( T_1 * ) ( F_13 ( V_6 ) + 1 ) - V_6 -> V_14 ;
int V_26 = V_6 -> V_26 - V_25 ;
T_4 V_27 = F_13 ( V_6 ) -> V_27 ;
T_5 V_28 ;
if ( V_26 < 0 )
return true ;
V_25 = F_14 ( V_6 , V_25 , & V_27 , & V_28 ) ;
if ( V_25 < 0 )
return false ;
if ( V_27 == V_29 ) {
T_1 V_30 , * V_31 ;
V_31 = F_15 ( V_6 ,
V_25 + F_16 ( struct V_12 , V_20 ) ,
sizeof( V_30 ) , & V_30 ) ;
if ( ! V_31 || ! ( * V_31 & V_19 ) )
return true ;
}
return false ;
}
static bool F_17 ( int type )
{
if ( type & V_19 )
return true ;
if ( type == V_16 )
return true ;
return false ;
}
static bool F_18 ( int type )
{
if ( F_17 ( type ) )
return true ;
if ( F_19 () )
return true ;
return false ;
}
static bool F_20 ( struct V_1 * V_22 , T_1 type ,
struct V_32 * V_33 )
{
struct V_2 * V_2 = F_21 ( V_22 ) ;
struct V_34 * V_35 ;
bool V_36 = false ;
if ( F_17 ( type ) )
return true ;
V_35 = F_22 ( V_2 , V_22 , V_33 ) ;
if ( V_35 -> error ) {
F_23 ( V_2 , F_24 ( V_35 ) ,
V_37 ) ;
} else if ( V_35 -> V_15 && ( V_35 -> V_15 -> V_38 & V_39 ) ) {
V_36 = true ;
} else {
struct V_40 * V_41 = (struct V_40 * ) V_35 ;
int V_42 = V_2 -> V_3 . V_43 . V_44 ;
struct V_45 * V_46 ;
if ( V_41 -> V_47 . V_48 < 128 )
V_42 >>= ( ( 128 - V_41 -> V_47 . V_48 ) >> 5 ) ;
V_46 = F_25 ( V_2 -> V_3 . V_49 , & V_33 -> V_50 , 1 ) ;
V_36 = F_26 ( V_46 , V_42 ) ;
if ( V_46 )
F_27 ( V_46 ) ;
}
F_28 ( V_35 ) ;
return V_36 ;
}
static bool F_29 ( struct V_5 * V_6 , T_6 V_10 )
{
T_1 V_51 , * V_52 ;
V_10 += F_30 ( V_6 ) ;
V_52 = F_15 ( V_6 , V_10 , sizeof( V_51 ) , & V_51 ) ;
if ( ! V_52 )
return true ;
return ( * V_52 & 0xC0 ) == 0x80 ;
}
int F_31 ( struct V_1 * V_22 , struct V_32 * V_33 ,
struct V_12 * V_53 , int V_26 )
{
struct V_5 * V_6 ;
struct V_12 * V_54 ;
int V_55 = 0 ;
V_6 = F_32 ( & V_22 -> V_56 ) ;
if ( ! V_6 )
goto V_57;
V_54 = F_33 ( V_6 ) ;
memcpy ( V_54 , V_53 , sizeof( struct V_12 ) ) ;
V_54 -> V_58 = 0 ;
if ( F_34 ( & V_22 -> V_56 ) == 1 ) {
V_6 -> V_59 = F_35 ( V_54 ,
sizeof( struct V_12 ) , V_6 -> V_59 ) ;
V_54 -> V_58 = F_36 ( & V_33 -> V_60 ,
& V_33 -> V_50 ,
V_26 , V_33 -> V_61 ,
V_6 -> V_59 ) ;
} else {
T_7 V_62 = 0 ;
F_37 (&sk->sk_write_queue, skb) {
V_62 = F_38 ( V_62 , V_6 -> V_59 ) ;
}
V_62 = F_35 ( V_54 ,
sizeof( struct V_12 ) , V_62 ) ;
V_54 -> V_58 = F_36 ( & V_33 -> V_60 ,
& V_33 -> V_50 ,
V_26 , V_33 -> V_61 ,
V_62 ) ;
}
F_39 ( V_22 ) ;
V_57:
return V_55 ;
}
static int F_40 ( void * V_63 , char * V_64 , int V_10 , int V_26 , int V_65 , struct V_5 * V_6 )
{
struct V_66 * V_67 = (struct V_66 * ) V_63 ;
struct V_5 * V_68 = V_67 -> V_6 ;
T_7 V_59 = 0 ;
V_59 = F_41 ( V_68 , V_67 -> V_10 + V_10 ,
V_64 , V_26 , V_59 ) ;
V_6 -> V_59 = F_42 ( V_6 -> V_59 , V_59 , V_65 ) ;
if ( ! ( V_67 -> type & V_19 ) )
F_43 ( V_6 , V_68 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_7 * V_8 = F_45 ( V_6 ) ;
struct V_71 * V_72 ;
struct V_73 V_74 ;
int V_75 ;
if ( V_8 -> V_76 ) {
V_75 = F_46 ( V_6 , V_8 -> V_76 , V_77 ) ;
if ( F_47 ( V_75 >= 0 ) ) {
V_72 = (struct V_71 * )
( F_48 ( V_6 ) + V_75 ) ;
V_74 = V_70 -> V_60 ;
V_70 -> V_60 = V_72 -> V_78 ;
V_72 -> V_78 = V_74 ;
}
}
}
static inline void F_44 ( struct V_5 * V_6 ) {}
static struct V_34 * F_49 ( struct V_2 * V_2 ,
struct V_5 * V_6 ,
struct V_1 * V_22 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 , * V_79 ;
struct V_32 V_80 ;
int V_55 ;
V_55 = F_50 ( V_2 , V_22 , & V_35 , V_33 ) ;
if ( V_55 )
return F_51 ( V_55 ) ;
if ( F_52 ( V_35 , & V_33 -> V_50 ) ) {
F_53 ( L_1 ) ;
F_28 ( V_35 ) ;
return F_51 ( - V_81 ) ;
}
V_79 = V_35 ;
V_35 = F_54 ( V_2 , V_35 , F_55 ( V_33 ) , V_22 , 0 ) ;
if ( ! F_56 ( V_35 ) ) {
if ( V_35 != V_79 )
return V_35 ;
} else {
if ( F_57 ( V_35 ) == - V_82 )
V_35 = NULL ;
else
return V_35 ;
}
V_55 = F_58 ( V_6 , F_55 ( & V_80 ) , V_83 ) ;
if ( V_55 )
goto V_84;
V_55 = F_50 ( V_2 , V_22 , & V_79 , & V_80 ) ;
if ( V_55 )
goto V_84;
V_79 = F_54 ( V_2 , V_79 , F_55 ( & V_80 ) , V_22 , V_85 ) ;
if ( ! F_56 ( V_79 ) ) {
F_28 ( V_35 ) ;
V_35 = V_79 ;
} else {
V_55 = F_57 ( V_79 ) ;
if ( V_55 == - V_82 ) {
F_28 ( V_35 ) ;
return V_79 ;
} else
goto V_84;
}
V_84:
if ( V_35 )
return V_35 ;
return F_51 ( V_55 ) ;
}
static void F_59 ( struct V_5 * V_6 , T_1 type , T_1 V_9 , T_6 V_11 ,
const struct V_73 * V_86 )
{
struct V_2 * V_2 = F_4 ( V_6 -> V_15 ) ;
struct V_87 * V_88 = NULL ;
struct V_69 * V_89 = F_13 ( V_6 ) ;
struct V_1 * V_22 ;
struct V_90 * V_91 ;
const struct V_73 * V_60 = NULL ;
struct V_34 * V_35 ;
struct V_12 V_92 ;
struct V_32 V_33 ;
struct V_66 V_67 ;
struct V_93 V_94 = { 0 } ;
struct V_95 V_96 ;
int V_97 = 0 ;
int V_98 = 0 ;
int V_26 ;
int V_55 = 0 ;
T_8 V_99 = F_60 ( V_2 , V_6 -> V_99 ) ;
if ( ( T_1 * ) V_89 < V_6 -> V_100 ||
( F_48 ( V_6 ) + sizeof( * V_89 ) ) > F_61 ( V_6 ) )
return;
V_98 = F_62 ( & V_89 -> V_50 ) ;
if ( F_63 ( V_2 , & V_89 -> V_50 , V_6 -> V_15 , 0 ) ||
F_64 ( V_2 , V_6 -> V_15 , & V_89 -> V_50 ) )
V_60 = & V_89 -> V_50 ;
if ( V_98 & V_101 || V_6 -> V_102 != V_103 ) {
if ( type != V_16 &&
! ( type == V_104 &&
V_9 == V_105 &&
( F_29 ( V_6 , V_11 ) ) ) )
return;
V_60 = NULL ;
}
V_98 = F_62 ( & V_89 -> V_60 ) ;
if ( F_65 ( V_98 ) )
V_97 = V_6 -> V_15 -> V_18 ;
else {
V_35 = F_66 ( V_6 ) ;
V_97 = F_67 ( V_35 ? V_35 -> V_15 : V_6 -> V_15 ) ;
}
if ( ( V_98 == V_106 ) || ( V_98 & V_101 ) ) {
F_53 ( L_2 ,
& V_89 -> V_60 , & V_89 -> V_50 ) ;
return;
}
if ( F_12 ( V_6 ) ) {
F_53 ( L_3 ,
& V_89 -> V_60 , & V_89 -> V_50 ) ;
return;
}
F_68 () ;
if ( ! ( V_6 -> V_15 -> V_38 & V_39 ) && ! F_18 ( type ) )
goto V_107;
F_44 ( V_6 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_61 = V_29 ;
V_33 . V_50 = V_89 -> V_60 ;
if ( V_86 )
V_60 = V_86 ;
if ( V_60 )
V_33 . V_60 = * V_60 ;
V_33 . V_108 = V_99 ;
V_33 . V_109 = V_97 ;
V_33 . V_110 = type ;
V_33 . V_111 = V_9 ;
V_33 . V_112 = F_6 ( V_2 , NULL ) ;
F_69 ( V_6 , F_55 ( & V_33 ) ) ;
V_22 = F_70 ( V_2 ) ;
if ( ! V_22 )
goto V_107;
V_22 -> V_113 = V_99 ;
V_91 = F_71 ( V_22 ) ;
if ( ! F_20 ( V_22 , type , & V_33 ) )
goto V_57;
V_92 . V_20 = type ;
V_92 . V_114 = V_9 ;
V_92 . V_58 = 0 ;
V_92 . V_115 = F_72 ( V_11 ) ;
if ( ! V_33 . V_109 && F_73 ( & V_33 . V_50 ) )
V_33 . V_109 = V_91 -> V_116 ;
else if ( ! V_33 . V_109 )
V_33 . V_109 = V_91 -> V_117 ;
V_96 . V_118 = V_91 -> V_118 ;
V_33 . V_119 = F_74 ( V_96 . V_118 , V_33 . V_119 ) ;
V_35 = F_49 ( V_2 , V_6 , V_22 , & V_33 ) ;
if ( F_56 ( V_35 ) )
goto V_57;
V_96 . V_120 = F_75 ( V_91 , & V_33 , V_35 ) ;
V_96 . V_121 = V_91 -> V_121 ;
V_96 . V_8 = NULL ;
V_67 . V_6 = V_6 ;
V_67 . V_10 = F_30 ( V_6 ) ;
V_67 . type = type ;
V_26 = V_6 -> V_26 - V_67 . V_10 ;
V_26 = F_76 (unsigned int, len, IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(struct icmp6hdr)) ;
if ( V_26 < 0 ) {
F_53 ( L_4 ,
& V_89 -> V_60 , & V_89 -> V_50 ) ;
goto V_122;
}
F_77 () ;
V_88 = F_78 ( V_6 -> V_15 ) ;
V_55 = F_79 ( V_22 , F_40 , & V_67 ,
V_26 + sizeof( struct V_12 ) ,
sizeof( struct V_12 ) ,
& V_96 , & V_33 , (struct V_40 * ) V_35 ,
V_123 , & V_94 ) ;
if ( V_55 ) {
F_80 ( V_2 , V_88 , V_124 ) ;
F_81 ( V_22 ) ;
} else {
V_55 = F_31 ( V_22 , & V_33 , & V_92 ,
V_26 + sizeof( struct V_12 ) ) ;
}
F_82 () ;
V_122:
F_28 ( V_35 ) ;
V_57:
F_10 ( V_22 ) ;
V_107:
F_83 () ;
}
void F_84 ( struct V_5 * V_6 , T_1 V_9 , int V_125 )
{
F_59 ( V_6 , V_104 , V_9 , V_125 , NULL ) ;
F_85 ( V_6 ) ;
}
int F_86 ( struct V_5 * V_6 , int V_126 , int type ,
unsigned int V_127 )
{
struct V_73 V_128 ;
struct V_40 * V_41 ;
struct V_5 * V_129 ;
T_8 V_11 = 0 ;
if ( ! F_87 ( V_6 , V_126 + sizeof( struct V_69 ) + 8 ) )
return 1 ;
if ( V_127 < 128 || ( V_127 & 7 ) || V_6 -> V_26 < V_127 )
V_127 = 0 ;
V_129 = V_127 ? F_88 ( V_6 , V_130 ) : F_89 ( V_6 , V_130 ) ;
if ( ! V_129 )
return 1 ;
F_90 ( V_129 ) ;
F_91 ( V_129 , V_126 ) ;
F_92 ( V_129 ) ;
V_41 = F_93 ( F_4 ( V_6 -> V_15 ) , & F_13 ( V_129 ) -> V_60 , NULL , 0 , 0 ) ;
if ( V_41 && V_41 -> V_35 . V_15 )
V_129 -> V_15 = V_41 -> V_35 . V_15 ;
F_94 ( F_95 ( V_6 ) -> V_60 , & V_128 ) ;
if ( V_127 ) {
F_96 ( V_129 , V_126 ) ;
F_92 ( V_129 ) ;
memmove ( V_129 -> V_14 , V_129 -> V_14 + V_126 , V_127 - V_126 ) ;
memset ( V_129 -> V_14 + V_127 - V_126 , 0 , V_126 ) ;
V_11 = ( V_127 / 8 ) << 24 ;
}
if ( type == V_131 )
F_59 ( V_129 , V_132 , V_133 ,
V_11 , & V_128 ) ;
else
F_59 ( V_129 , V_134 , V_135 ,
V_11 , & V_128 ) ;
if ( V_41 )
F_97 ( V_41 ) ;
F_85 ( V_129 ) ;
return 0 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_2 * V_2 = F_4 ( V_6 -> V_15 ) ;
struct V_1 * V_22 ;
struct V_87 * V_88 ;
struct V_90 * V_91 ;
const struct V_73 * V_60 = NULL ;
struct V_12 * V_136 = F_33 ( V_6 ) ;
struct V_12 V_92 ;
struct V_32 V_33 ;
struct V_66 V_67 ;
struct V_34 * V_35 ;
struct V_95 V_96 ;
int V_55 = 0 ;
T_8 V_99 = F_60 ( V_2 , V_6 -> V_99 ) ;
struct V_93 V_94 = { 0 } ;
V_60 = & F_13 ( V_6 ) -> V_50 ;
if ( ! F_99 ( V_6 ) &&
! ( V_2 -> V_3 . V_43 . V_137 &&
F_52 ( F_66 ( V_6 ) , V_60 ) ) )
V_60 = NULL ;
memcpy ( & V_92 , V_136 , sizeof( V_92 ) ) ;
V_92 . V_20 = V_138 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_61 = V_29 ;
V_33 . V_50 = F_13 ( V_6 ) -> V_60 ;
if ( V_60 )
V_33 . V_60 = * V_60 ;
V_33 . V_109 = V_6 -> V_15 -> V_18 ;
V_33 . V_110 = V_138 ;
V_33 . V_108 = V_99 ;
V_33 . V_112 = F_6 ( V_2 , NULL ) ;
F_69 ( V_6 , F_55 ( & V_33 ) ) ;
F_68 () ;
V_22 = F_70 ( V_2 ) ;
if ( ! V_22 )
goto V_107;
V_22 -> V_113 = V_99 ;
V_91 = F_71 ( V_22 ) ;
if ( ! V_33 . V_109 && F_73 ( & V_33 . V_50 ) )
V_33 . V_109 = V_91 -> V_116 ;
else if ( ! V_33 . V_109 )
V_33 . V_109 = V_91 -> V_117 ;
V_55 = F_50 ( V_2 , V_22 , & V_35 , & V_33 ) ;
if ( V_55 )
goto V_57;
V_35 = F_54 ( V_2 , V_35 , F_55 ( & V_33 ) , V_22 , 0 ) ;
if ( F_56 ( V_35 ) )
goto V_57;
V_88 = F_78 ( V_6 -> V_15 ) ;
V_67 . V_6 = V_6 ;
V_67 . V_10 = 0 ;
V_67 . type = V_138 ;
V_96 . V_120 = F_75 ( V_91 , & V_33 , V_35 ) ;
V_96 . V_118 = F_100 ( F_13 ( V_6 ) ) ;
V_96 . V_121 = V_91 -> V_121 ;
V_96 . V_8 = NULL ;
V_55 = F_79 ( V_22 , F_40 , & V_67 , V_6 -> V_26 + sizeof( struct V_12 ) ,
sizeof( struct V_12 ) , & V_96 , & V_33 ,
(struct V_40 * ) V_35 , V_123 ,
& V_94 ) ;
if ( V_55 ) {
F_101 ( V_2 , V_88 , V_124 ) ;
F_81 ( V_22 ) ;
} else {
V_55 = F_31 ( V_22 , & V_33 , & V_92 ,
V_6 -> V_26 + sizeof( struct V_12 ) ) ;
}
F_28 ( V_35 ) ;
V_57:
F_10 ( V_22 ) ;
V_107:
F_83 () ;
}
void F_102 ( struct V_5 * V_6 , T_1 type , T_1 V_9 , T_2 V_11 )
{
const struct V_139 * V_140 ;
int V_141 ;
T_5 V_28 ;
T_1 V_27 ;
struct V_2 * V_2 = F_4 ( V_6 -> V_15 ) ;
if ( ! F_87 ( V_6 , sizeof( struct V_69 ) ) )
goto V_57;
V_27 = ( (struct V_69 * ) V_6 -> V_14 ) -> V_27 ;
if ( F_103 ( V_27 ) ) {
V_141 = F_14 ( V_6 , sizeof( struct V_69 ) ,
& V_27 , & V_28 ) ;
if ( V_141 < 0 )
goto V_57;
} else {
V_141 = sizeof( struct V_69 ) ;
}
if ( ! F_87 ( V_6 , V_141 + 8 ) )
goto V_57;
V_140 = F_104 ( V_142 [ V_27 ] ) ;
if ( V_140 && V_140 -> V_143 )
V_140 -> V_143 ( V_6 , NULL , type , V_9 , V_141 , V_11 ) ;
F_105 ( V_6 , V_27 , type , V_9 , V_141 , V_11 ) ;
return;
V_57:
F_101 ( V_2 , F_78 ( V_6 -> V_15 ) , V_144 ) ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_145 * V_15 = V_6 -> V_15 ;
struct V_87 * V_88 = F_78 ( V_15 ) ;
const struct V_73 * V_60 , * V_50 ;
struct V_12 * V_89 ;
T_1 type ;
bool V_146 = false ;
if ( ! F_107 ( NULL , V_147 , V_6 ) ) {
struct V_148 * V_149 = F_108 ( V_6 ) ;
int V_150 ;
if ( ! ( V_149 && V_149 -> V_151 [ V_149 -> V_26 - 1 ] -> V_152 . V_38 &
V_153 ) )
goto V_154;
if ( ! F_87 ( V_6 , sizeof( * V_89 ) + sizeof( struct V_69 ) ) )
goto V_154;
V_150 = F_30 ( V_6 ) ;
F_109 ( V_6 , sizeof( * V_89 ) ) ;
if ( ! F_110 ( NULL , V_147 , V_6 ) )
goto V_154;
F_109 ( V_6 , V_150 ) ;
}
F_101 ( F_4 ( V_15 ) , V_88 , V_155 ) ;
V_60 = & F_13 ( V_6 ) -> V_60 ;
V_50 = & F_13 ( V_6 ) -> V_50 ;
if ( F_111 ( V_6 , V_29 , V_156 ) ) {
F_53 ( L_5 ,
V_60 , V_50 ) ;
goto V_157;
}
if ( ! F_112 ( V_6 , sizeof( * V_89 ) ) )
goto V_158;
V_89 = F_33 ( V_6 ) ;
type = V_89 -> V_20 ;
F_113 ( F_4 ( V_15 ) , V_88 , type ) ;
switch ( type ) {
case V_21 :
F_98 ( V_6 ) ;
break;
case V_138 :
V_146 = F_114 ( V_6 ) ;
break;
case V_16 :
if ( ! F_87 ( V_6 , sizeof( struct V_69 ) ) )
goto V_158;
V_89 = F_33 ( V_6 ) ;
case V_134 :
case V_132 :
case V_104 :
F_102 ( V_6 , type , V_89 -> V_114 , V_89 -> V_159 ) ;
break;
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_17 :
F_115 ( V_6 ) ;
break;
case V_164 :
F_116 ( V_6 ) ;
break;
case V_165 :
F_117 ( V_6 ) ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
break;
default:
if ( type & V_19 )
break;
F_53 ( L_6 ,
V_60 , V_50 ) ;
F_102 ( V_6 , type , V_89 -> V_114 , V_89 -> V_159 ) ;
}
if ( V_146 )
F_118 ( V_6 ) ;
else
F_85 ( V_6 ) ;
return 0 ;
V_157:
F_101 ( F_4 ( V_15 ) , V_88 , V_174 ) ;
V_158:
F_101 ( F_4 ( V_15 ) , V_88 , V_144 ) ;
V_154:
F_85 ( V_6 ) ;
return 0 ;
}
void F_119 ( struct V_1 * V_22 , struct V_32 * V_33 ,
T_1 type ,
const struct V_73 * V_60 ,
const struct V_73 * V_50 ,
int V_175 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_60 = * V_60 ;
V_33 -> V_50 = * V_50 ;
V_33 -> V_61 = V_29 ;
V_33 -> V_110 = type ;
V_33 -> V_111 = 0 ;
V_33 -> V_109 = V_175 ;
F_120 ( V_22 , F_55 ( V_33 ) ) ;
}
static int T_9 F_121 ( struct V_2 * V_2 )
{
struct V_1 * V_22 ;
int V_55 , V_176 , V_177 ;
V_2 -> V_3 . V_4 =
F_122 ( V_178 * sizeof( struct V_1 * ) , V_179 ) ;
if ( ! V_2 -> V_3 . V_4 )
return - V_180 ;
F_123 (i) {
V_55 = F_124 ( & V_22 , V_181 ,
V_182 , V_29 , V_2 ) ;
if ( V_55 < 0 ) {
F_125 ( L_7 ,
V_55 ) ;
goto V_183;
}
V_2 -> V_3 . V_4 [ V_176 ] = V_22 ;
V_22 -> V_184 = 2 * F_126 ( 64 * 1024 ) ;
}
return 0 ;
V_183:
for ( V_177 = 0 ; V_177 < V_176 ; V_177 ++ )
F_127 ( V_2 -> V_3 . V_4 [ V_177 ] ) ;
F_128 ( V_2 -> V_3 . V_4 ) ;
return V_55 ;
}
static void T_10 F_129 ( struct V_2 * V_2 )
{
int V_176 ;
F_123 (i) {
F_127 ( V_2 -> V_3 . V_4 [ V_176 ] ) ;
}
F_128 ( V_2 -> V_3 . V_4 ) ;
}
int T_11 F_130 ( void )
{
int V_55 ;
V_55 = F_131 ( & V_185 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = - V_186 ;
if ( F_132 ( & V_187 , V_29 ) < 0 )
goto V_183;
V_55 = F_133 ( F_59 ) ;
if ( V_55 )
goto V_188;
return 0 ;
V_188:
F_134 ( & V_187 , V_29 ) ;
V_183:
F_125 ( L_8 ) ;
F_135 ( & V_185 ) ;
return V_55 ;
}
void F_136 ( void )
{
F_137 ( F_59 ) ;
F_135 ( & V_185 ) ;
F_134 ( & V_187 , V_29 ) ;
}
int F_138 ( T_1 type , T_1 V_9 , int * V_55 )
{
int V_189 = 0 ;
* V_55 = V_190 ;
switch ( type ) {
case V_134 :
V_189 = 1 ;
if ( V_9 < F_139 ( V_191 ) ) {
* V_55 = V_191 [ V_9 ] . V_55 ;
V_189 = V_191 [ V_9 ] . V_189 ;
}
break;
case V_16 :
* V_55 = V_192 ;
break;
case V_104 :
* V_55 = V_190 ;
V_189 = 1 ;
break;
case V_132 :
* V_55 = V_193 ;
break;
}
return V_189 ;
}
struct V_194 * T_9 F_140 ( struct V_2 * V_2 )
{
struct V_194 * V_195 ;
V_195 = F_141 ( V_196 ,
sizeof( V_196 ) ,
V_179 ) ;
if ( V_195 )
V_195 [ 0 ] . V_14 = & V_2 -> V_3 . V_43 . V_44 ;
return V_195 ;
}
