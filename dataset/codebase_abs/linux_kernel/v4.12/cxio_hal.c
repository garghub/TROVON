static struct V_1 * F_1 ( char * V_2 )
{
struct V_1 * V_3 ;
F_2 (rdev, &rdev_list, entry)
if ( ! strcmp ( V_3 -> V_2 , V_2 ) )
return V_3 ;
return NULL ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_3 ;
F_2 (rdev, &rdev_list, entry)
if ( V_3 -> V_6 == V_5 )
return V_3 ;
return NULL ;
}
int F_4 ( struct V_1 * V_7 , struct V_8 * V_9 ,
enum V_10 V_11 , T_1 V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
T_1 V_16 ;
struct V_17 V_18 ;
V_18 . V_19 = V_9 -> V_20 ;
V_18 . V_21 = ( V_11 == V_22 ) ? V_12 : 0 ;
V_18 . V_11 = V_11 ;
V_13 = V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_24 , & V_18 ) ;
if ( ( V_13 < 0 ) || ( V_11 == V_22 ) )
return V_13 ;
if ( F_5 ( ( V_9 -> V_16 ) , V_9 -> V_25 ) != V_13 ) {
int V_26 = 0 ;
V_16 = V_9 -> V_16 ;
while ( F_5 ( ( V_16 + 1 ) , V_9 -> V_25 ) != V_13 )
V_16 ++ ;
V_15 = V_9 -> V_27 + F_5 ( V_16 , V_9 -> V_25 ) ;
while ( ! F_6 ( V_16 , V_9 -> V_25 , V_15 ) ) {
F_7 ( 1 ) ;
if ( V_26 ++ > 1000000 ) {
F_8 ( L_1 , V_7 -> V_2 ) ;
return - V_28 ;
}
}
return 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_7 , T_1 V_20 )
{
struct V_29 V_18 ;
V_18 . V_19 = V_20 ;
V_18 . V_30 = 0 ;
V_18 . V_31 = 0 ;
V_18 . V_21 = 0 ;
V_18 . V_32 = 0 ;
V_18 . V_33 = 0 ;
return ( V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_34 , & V_18 ) ) ;
}
static int F_10 ( struct V_1 * V_7 , T_1 V_35 )
{
T_2 V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 = F_11 ( sizeof( * V_38 ) , V_41 ) ;
if ( ! V_40 ) {
F_12 ( L_2 , V_42 ) ;
return - V_43 ;
}
V_38 = (struct V_37 * ) F_13 ( V_40 , sizeof( * V_38 ) ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
F_14 ( (struct V_44 * ) V_38 , V_45 ,
V_46 | V_47 , 0 , V_35 , 7 ,
V_48 ) ;
V_38 -> V_49 = F_15 ( V_50 ) ;
V_36 = V_35 << 8 | 3 ;
V_38 -> V_36 = F_16 ( V_36 ) ;
V_40 -> V_51 = V_52 ;
return F_17 ( V_7 -> V_6 , V_40 ) ;
}
int F_18 ( struct V_1 * V_7 , struct V_8 * V_9 , int V_53 )
{
struct V_29 V_18 ;
int V_31 = ( 1UL << ( V_9 -> V_25 ) ) * sizeof( struct V_14 ) ;
V_31 += 1 ;
V_9 -> V_20 = F_19 ( V_7 -> V_54 ) ;
if ( ! V_9 -> V_20 )
return - V_43 ;
if ( V_53 ) {
V_9 -> V_55 = F_20 ( V_31 , V_41 ) ;
if ( ! V_9 -> V_55 )
return - V_43 ;
}
V_9 -> V_27 = F_21 ( & ( V_7 -> V_56 . V_57 -> V_58 ) , V_31 ,
& ( V_9 -> V_59 ) , V_41 ) ;
if ( ! V_9 -> V_27 ) {
F_22 ( V_9 -> V_55 ) ;
return - V_43 ;
}
F_23 ( V_9 , V_60 , V_9 -> V_59 ) ;
memset ( V_9 -> V_27 , 0 , V_31 ) ;
V_18 . V_19 = V_9 -> V_20 ;
V_18 . V_30 = ( T_2 ) ( V_9 -> V_59 ) ;
V_18 . V_31 = 1UL << V_9 -> V_25 ;
V_18 . V_21 = 65535 ;
V_18 . V_32 = 1 ;
if ( V_7 -> V_6 -> type != V_61 )
V_18 . V_33 = 0 ;
else
V_18 . V_33 = 1 ;
return ( V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_34 , & V_18 ) ) ;
}
int F_24 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
struct V_29 V_18 ;
V_18 . V_19 = V_9 -> V_20 ;
V_18 . V_30 = ( T_2 ) ( V_9 -> V_59 ) ;
V_18 . V_31 = 1UL << V_9 -> V_25 ;
V_18 . V_21 = V_18 . V_31 ;
V_18 . V_32 = V_18 . V_31 ;
V_18 . V_33 = 1 ;
return ( V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_34 , & V_18 ) ) ;
}
static T_1 F_25 ( struct V_1 * V_7 , struct V_62 * V_63 )
{
struct V_64 * V_65 ;
T_1 V_35 ;
int V_26 ;
F_26 ( & V_63 -> V_66 ) ;
if ( ! F_27 ( & V_63 -> V_67 ) ) {
V_65 = F_28 ( V_63 -> V_67 . V_68 , struct V_64 ,
V_65 ) ;
F_29 ( & V_65 -> V_65 ) ;
V_35 = V_65 -> V_35 ;
F_22 ( V_65 ) ;
} else {
V_35 = F_30 ( V_7 -> V_54 ) ;
if ( ! V_35 )
goto V_69;
for ( V_26 = V_35 + 1 ; V_26 & V_7 -> V_70 ; V_26 ++ ) {
V_65 = F_31 ( sizeof *V_65 , V_41 ) ;
if ( ! V_65 )
break;
V_65 -> V_35 = V_26 ;
F_32 ( & V_65 -> V_65 , & V_63 -> V_67 ) ;
}
}
V_69:
F_33 ( & V_63 -> V_66 ) ;
F_12 ( L_3 , V_42 , V_35 ) ;
return V_35 ;
}
static void F_34 ( struct V_1 * V_7 , T_1 V_35 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 ;
V_65 = F_31 ( sizeof *V_65 , V_41 ) ;
if ( ! V_65 )
return;
F_12 ( L_3 , V_42 , V_35 ) ;
V_65 -> V_35 = V_35 ;
F_26 ( & V_63 -> V_66 ) ;
F_32 ( & V_65 -> V_65 , & V_63 -> V_67 ) ;
F_33 ( & V_63 -> V_66 ) ;
}
void F_35 ( struct V_1 * V_7 , struct V_62 * V_63 )
{
struct V_71 * V_72 , * V_73 ;
struct V_64 * V_65 ;
F_26 ( & V_63 -> V_66 ) ;
F_36 (pos, nxt, &uctx->qpids) {
V_65 = F_28 ( V_72 , struct V_64 , V_65 ) ;
F_37 ( & V_65 -> V_65 ) ;
if ( ! ( V_65 -> V_35 & V_7 -> V_70 ) )
F_38 ( V_7 -> V_54 , V_65 -> V_35 ) ;
F_22 ( V_65 ) ;
}
F_33 ( & V_63 -> V_66 ) ;
}
void F_39 ( struct V_1 * V_7 , struct V_62 * V_63 )
{
F_40 ( & V_63 -> V_67 ) ;
F_41 ( & V_63 -> V_66 ) ;
}
int F_42 ( struct V_1 * V_7 , T_1 V_74 ,
struct V_75 * V_76 , struct V_62 * V_63 )
{
int V_77 = 1UL << V_76 -> V_25 ;
int V_78 = 1UL << V_76 -> V_79 ;
V_76 -> V_35 = F_25 ( V_7 , V_63 ) ;
if ( ! V_76 -> V_35 )
return - V_43 ;
V_76 -> V_80 = F_20 ( V_77 * sizeof( struct V_81 ) , V_41 ) ;
if ( ! V_76 -> V_80 )
goto V_82;
V_76 -> V_83 = F_43 ( V_7 , V_78 ) ;
if ( ! V_76 -> V_83 )
goto V_84;
V_76 -> V_85 = F_20 ( V_77 * sizeof( struct V_86 ) , V_41 ) ;
if ( ! V_76 -> V_85 )
goto V_87;
V_76 -> V_27 = F_21 ( & ( V_7 -> V_56 . V_57 -> V_58 ) ,
V_77 * sizeof( union V_88 ) ,
& ( V_76 -> V_59 ) , V_41 ) ;
if ( ! V_76 -> V_27 )
goto V_89;
memset ( V_76 -> V_27 , 0 , V_77 * sizeof( union V_88 ) ) ;
F_23 ( V_76 , V_60 , V_76 -> V_59 ) ;
V_76 -> V_90 = ( void V_91 * ) V_7 -> V_56 . V_92 ;
if ( ! V_74 )
V_76 -> V_93 = ( T_2 ) V_7 -> V_56 . V_94 +
( V_76 -> V_35 << V_7 -> V_95 ) ;
V_76 -> V_3 = V_7 ;
F_12 ( L_4 ,
V_42 , V_76 -> V_35 , V_76 -> V_90 , ( unsigned long long ) V_76 -> V_93 ) ;
return 0 ;
V_89:
F_22 ( V_76 -> V_85 ) ;
V_87:
F_44 ( V_7 , V_76 -> V_83 , V_78 ) ;
V_84:
F_22 ( V_76 -> V_80 ) ;
V_82:
F_34 ( V_7 , V_76 -> V_35 , V_63 ) ;
return - V_43 ;
}
int F_45 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
int V_96 ;
V_96 = F_9 ( V_7 , V_9 -> V_20 ) ;
F_22 ( V_9 -> V_55 ) ;
F_46 ( & ( V_7 -> V_56 . V_57 -> V_58 ) ,
( 1UL << ( V_9 -> V_25 ) )
* sizeof( struct V_14 ) + 1 , V_9 -> V_27 ,
F_47 ( V_9 , V_60 ) ) ;
F_48 ( V_7 -> V_54 , V_9 -> V_20 ) ;
return V_96 ;
}
int F_49 ( struct V_1 * V_7 , struct V_75 * V_76 ,
struct V_62 * V_63 )
{
F_46 ( & ( V_7 -> V_56 . V_57 -> V_58 ) ,
( 1UL << ( V_76 -> V_25 ) )
* sizeof( union V_88 ) , V_76 -> V_27 ,
F_47 ( V_76 , V_60 ) ) ;
F_22 ( V_76 -> V_85 ) ;
F_44 ( V_7 , V_76 -> V_83 , ( 1UL << V_76 -> V_79 ) ) ;
F_22 ( V_76 -> V_80 ) ;
F_34 ( V_7 , V_76 -> V_35 , V_63 ) ;
return 0 ;
}
static void F_50 ( struct V_75 * V_76 , struct V_8 * V_9 )
{
struct V_14 V_15 ;
F_12 ( L_5 , V_42 ,
V_76 , V_9 , V_9 -> V_97 , V_9 -> V_98 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_99 = F_15 ( F_51 ( V_100 ) |
F_52 ( V_101 ) |
F_53 ( 0 ) |
F_54 ( 1 ) |
F_55 ( V_76 -> V_35 ) |
F_56 ( F_57 ( V_9 -> V_98 ,
V_9 -> V_25 ) ) ) ;
* ( V_9 -> V_55 + F_5 ( V_9 -> V_98 , V_9 -> V_25 ) ) = V_15 ;
V_9 -> V_98 ++ ;
}
int F_58 ( struct V_75 * V_76 , struct V_8 * V_9 , int V_102 )
{
T_1 V_103 ;
int V_104 = 0 ;
F_12 ( L_6 , V_42 , V_76 , V_9 ) ;
F_12 ( L_7 , V_42 ,
V_76 -> V_105 , V_76 -> V_106 , V_102 ) ;
V_103 = V_76 -> V_105 + V_102 ;
while ( V_103 ++ != V_76 -> V_106 ) {
F_50 ( V_76 , V_9 ) ;
V_104 ++ ;
}
return V_104 ;
}
static void F_59 ( struct V_75 * V_76 , struct V_8 * V_9 ,
struct V_86 * V_107 )
{
struct V_14 V_15 ;
F_12 ( L_5 , V_42 ,
V_76 , V_9 , V_9 -> V_97 , V_9 -> V_98 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_99 = F_15 ( F_51 ( V_100 ) |
F_52 ( V_107 -> V_108 ) |
F_53 ( 1 ) |
F_54 ( 1 ) |
F_55 ( V_76 -> V_35 ) |
F_56 ( F_57 ( V_9 -> V_98 ,
V_9 -> V_25 ) ) ) ;
V_15 . V_109 . V_110 . V_111 = V_107 -> V_112 ;
* ( V_9 -> V_55 + F_5 ( V_9 -> V_98 , V_9 -> V_25 ) ) = V_15 ;
V_9 -> V_98 ++ ;
}
int F_60 ( struct V_75 * V_76 , struct V_8 * V_9 , int V_102 )
{
T_3 V_103 ;
int V_104 = 0 ;
struct V_86 * V_107 = V_76 -> V_85 + F_5 ( V_76 -> V_113 , V_76 -> V_114 ) ;
V_103 = V_76 -> V_113 + V_102 ;
V_107 = V_76 -> V_85 + F_5 ( V_103 , V_76 -> V_114 ) ;
while ( V_103 != V_76 -> V_112 ) {
V_107 -> V_115 = 0 ;
F_59 ( V_76 , V_9 , V_107 ) ;
V_103 ++ ;
V_107 = V_76 -> V_85 + F_5 ( V_103 , V_76 -> V_114 ) ;
V_104 ++ ;
}
return V_104 ;
}
void F_61 ( struct V_8 * V_9 )
{
struct V_14 * V_15 , * V_116 ;
F_12 ( L_8 , V_42 , V_9 , V_9 -> V_20 ) ;
V_15 = F_62 ( V_9 ) ;
while ( V_15 ) {
F_12 ( L_9 ,
V_42 , V_9 -> V_16 , V_9 -> V_98 ) ;
V_116 = V_9 -> V_55 + F_5 ( V_9 -> V_98 , V_9 -> V_25 ) ;
* V_116 = * V_15 ;
V_116 -> V_99 |= F_15 ( F_54 ( 1 ) ) ;
V_9 -> V_98 ++ ;
V_9 -> V_16 ++ ;
V_15 = F_62 ( V_9 ) ;
}
}
static int F_63 ( struct V_14 * V_15 , struct V_75 * V_76 )
{
if ( F_64 ( * V_15 ) == V_117 )
return 0 ;
if ( ( F_64 ( * V_15 ) == V_118 ) && F_65 ( * V_15 ) )
return 0 ;
if ( ( F_64 ( * V_15 ) == V_119 ) && F_66 ( * V_15 ) )
return 0 ;
if ( F_67 ( * V_15 ) && F_65 ( * V_15 ) &&
F_68 ( V_76 -> V_105 , V_76 -> V_106 ) )
return 0 ;
return 1 ;
}
void F_69 ( struct V_8 * V_9 , struct V_75 * V_76 , int * V_102 )
{
struct V_14 * V_15 ;
T_1 V_103 ;
* V_102 = 0 ;
V_103 = V_9 -> V_97 ;
while ( ! F_68 ( V_103 , V_9 -> V_98 ) ) {
V_15 = V_9 -> V_55 + ( F_5 ( V_103 , V_9 -> V_25 ) ) ;
if ( ( F_66 ( * V_15 ) ||
( ( F_64 ( * V_15 ) == V_119 ) && V_76 -> V_120 ) ) &&
( F_70 ( * V_15 ) == V_76 -> V_35 ) )
( * V_102 ) ++ ;
V_103 ++ ;
}
F_12 ( L_10 , V_42 , V_9 , * V_102 ) ;
}
void F_71 ( struct V_8 * V_9 , struct V_75 * V_76 , int * V_102 )
{
struct V_14 * V_15 ;
T_1 V_103 ;
* V_102 = 0 ;
F_12 ( L_11 , V_42 , * V_102 ) ;
V_103 = V_9 -> V_97 ;
while ( ! F_68 ( V_103 , V_9 -> V_98 ) ) {
V_15 = V_9 -> V_55 + ( F_5 ( V_103 , V_9 -> V_25 ) ) ;
if ( F_65 ( * V_15 ) && ( F_64 ( * V_15 ) != V_119 ) &&
( F_70 ( * V_15 ) == V_76 -> V_35 ) && F_63 ( V_15 , V_76 ) )
( * V_102 ) ++ ;
V_103 ++ ;
}
F_12 ( L_10 , V_42 , V_9 , * V_102 ) ;
}
static int F_72 ( struct V_1 * V_7 )
{
struct V_29 V_18 ;
V_18 . V_19 = 0 ;
V_18 . V_30 = 0 ;
V_18 . V_31 = 1 ;
V_18 . V_21 = 0 ;
V_18 . V_32 = 0 ;
V_18 . V_33 = 1 ;
return ( V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_34 , & V_18 ) ) ;
}
static int F_73 ( struct V_1 * V_7 )
{
int V_96 ;
T_2 V_36 , V_121 , V_122 ;
T_2 V_30 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_40 = F_11 ( sizeof( * V_38 ) , V_41 ) ;
if ( ! V_40 ) {
F_12 ( L_2 , V_42 ) ;
return - V_43 ;
}
V_96 = F_72 ( V_7 ) ;
if ( V_96 ) {
F_12 ( L_12 , V_42 , V_96 ) ;
goto V_96;
}
V_7 -> V_123 . V_124 = F_21 (
& ( V_7 -> V_56 . V_57 -> V_58 ) ,
( 1 << V_125 ) *
sizeof( union V_88 ) ,
& ( V_7 -> V_123 . V_59 ) ,
V_41 ) ;
if ( ! V_7 -> V_123 . V_124 ) {
F_12 ( L_13 , V_42 ) ;
V_96 = - V_43 ;
goto V_96;
}
F_23 ( & V_7 -> V_123 , V_60 ,
V_7 -> V_123 . V_59 ) ;
V_7 -> V_123 . V_90 = ( void V_91 * ) V_7 -> V_56 . V_92 ;
memset ( V_7 -> V_123 . V_124 , 0 ,
( 1 << V_125 ) * sizeof( union V_88 ) ) ;
F_41 ( & V_7 -> V_123 . V_66 ) ;
F_74 ( & V_7 -> V_123 . V_126 ) ;
V_30 = V_7 -> V_123 . V_59 ;
V_30 >>= 12 ;
V_121 = ( F_75 ( ( 1 << V_125 ) ) |
F_76 ( ( T_1 ) V_30 & 0xffff ) ) ;
V_121 <<= 32 ;
V_121 |= F_77 ( V_127 ) ;
V_30 >>= 16 ;
V_122 = ( T_1 ) V_30 ;
V_30 >>= 32 ;
V_122 |= ( ( T_2 ) ( F_78 ( ( T_1 ) V_30 & 0xf ) | F_79 ( 0 ) |
F_80 ( 0 ) | F_81 ( 1 ) |
F_82 ( V_128 ) | V_129 ) ) << 32 ;
V_38 = (struct V_37 * ) F_13 ( V_40 , sizeof( * V_38 ) ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
F_14 ( (struct V_44 * ) V_38 , V_45 , 0 , 0 ,
V_128 , 7 , V_48 ) ;
V_38 -> V_49 = F_15 ( V_50 ) ;
V_36 = ( 3ULL << 56 ) | V_130 << 8 | 3 ;
V_38 -> V_36 = F_16 ( V_36 ) ;
V_38 -> V_122 = F_16 ( V_122 ) ;
V_38 -> V_121 = F_16 ( V_121 ) ;
F_12 ( L_14 ,
( unsigned long long ) V_7 -> V_123 . V_59 ,
V_7 -> V_123 . V_124 , 1 << V_125 ) ;
V_40 -> V_51 = V_52 ;
return F_17 ( V_7 -> V_6 , V_40 ) ;
V_96:
F_83 ( V_40 ) ;
return V_96 ;
}
static int F_84 ( struct V_1 * V_7 )
{
F_46 ( & ( V_7 -> V_56 . V_57 -> V_58 ) ,
( 1UL << V_125 )
* sizeof( union V_88 ) , V_7 -> V_123 . V_124 ,
F_47 ( & V_7 -> V_123 , V_60 ) ) ;
return F_10 ( V_7 , V_131 ) ;
}
static int F_85 ( struct V_1 * V_7 , T_1 V_132 ,
T_1 V_133 , void * V_134 )
{
T_1 V_26 , V_135 , V_136 ;
T_4 * V_137 ;
T_4 V_138 , V_139 ;
enum V_140 V_141 ;
T_5 * V_38 ;
T_2 V_142 ;
V_132 &= 0x7FFFFFF ;
V_135 = V_133 % 96 ? V_133 / 96 + 1 : V_133 / 96 ;
F_12 ( L_15 ,
V_42 , V_7 -> V_123 . V_143 , V_7 -> V_123 . V_16 , V_133 ,
V_135 , V_134 , V_132 ) ;
V_139 = 3 ;
for ( V_26 = 0 ; V_26 < V_135 ; V_26 ++ ) {
if ( F_86 ( V_7 -> V_123 . V_16 , V_7 -> V_123 . V_143 ,
V_125 ) ) {
F_12 ( L_16 ,
V_42 ,
V_7 -> V_123 . V_143 , V_7 -> V_123 . V_16 , V_26 ) ;
if ( F_87 ( V_7 -> V_123 . V_126 ,
! F_86 ( V_7 -> V_123 . V_16 ,
V_7 -> V_123 . V_143 ,
V_125 ) ) ) {
F_12 ( L_17 ,
V_42 ) ;
return - V_144 ;
}
F_12 ( L_18 ,
V_42 , V_26 ) ;
}
V_38 = ( T_5 * ) ( V_7 -> V_123 . V_124 + ( V_7 -> V_123 . V_143 %
( 1 << V_125 ) ) ) ;
V_141 = 0 ;
if ( V_26 == ( V_135 - 1 ) ) {
V_141 = V_46 ;
if ( V_133 % 32 )
V_139 = V_133 / 32 + 1 ;
else
V_139 = V_133 / 32 ;
}
if ( ( V_26 != 0 ) &&
( V_26 % ( ( ( 1 << V_125 ) ) >> 1 ) == 0 ) ) {
V_141 = V_46 ;
F_12 ( L_19 , V_42 , V_26 ) ;
}
V_38 += ( sizeof( struct V_145 ) >> 3 ) ;
V_142 = ( V_146 << 28 ) | ( V_132 + V_26 * 3 ) ;
V_142 <<= 32 ;
V_142 |= ( V_139 << 28 ) | ( ( V_139 << 2 ) + 1 ) ;
* V_38 = F_16 ( V_142 ) ;
V_38 ++ ;
V_137 = ( T_4 * ) V_134 + V_26 * 96 ;
V_136 = V_133 > 96 ? 96 : V_133 ;
if ( V_134 )
memcpy ( V_38 , V_137 , V_136 ) ;
else
memset ( V_38 , 0 , V_136 ) ;
if ( V_136 % 32 )
memset ( ( ( T_4 * ) V_38 ) + V_136 , 0 ,
32 - ( V_136 % 32 ) ) ;
V_138 = ( ( sizeof( struct V_145 ) ) >> 3 ) + 1 +
( V_139 << 2 ) ;
V_38 = ( T_5 * ) ( V_7 -> V_123 . V_124 + ( V_7 -> V_123 . V_143 %
( 1 << V_125 ) ) ) ;
( (union V_147 * ) ( V_38 + 1 ) ) -> V_148 . V_149 = V_7 -> V_123 . V_143 ;
F_14 ( (struct V_44 * ) V_38 , V_150 , V_141 ,
F_57 ( V_7 -> V_123 . V_143 ,
V_125 ) , V_131 ,
V_138 , V_48 ) ;
if ( V_141 == V_46 )
F_88 ( V_7 -> V_123 . V_90 , V_131 ) ;
V_133 -= 96 ;
V_7 -> V_123 . V_143 ++ ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_7 , T_1 V_151 ,
T_1 * V_152 , T_4 V_153 , T_1 V_154 ,
enum V_155 type , enum V_156 V_157 ,
T_1 V_158 , T_2 V_159 , T_1 V_133 , T_4 V_160 ,
T_1 V_161 , T_1 V_162 )
{
int V_96 ;
struct V_163 V_164 ;
T_1 V_165 ;
T_1 V_143 ;
if ( F_90 ( V_7 ) )
return - V_28 ;
V_153 = V_153 > 0 ;
V_165 = ( * V_152 ) >> 8 ;
if ( ( ! V_151 ) && ! ( * V_152 != V_166 ) ) {
V_165 = F_91 ( V_7 -> V_54 ) ;
if ( ! V_165 )
return - V_43 ;
* V_152 = ( V_165 << 8 ) | ( ( * V_152 ) & 0xFF ) ;
}
F_12 ( L_20 ,
V_42 , V_153 , type , V_154 , V_165 ) ;
F_26 ( & V_7 -> V_123 . V_66 ) ;
if ( V_151 )
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
else {
V_164 . V_167 = F_15 ( V_168 |
F_92 ( ( * V_152 ) & V_169 ) |
F_93 ( V_153 ) |
F_94 ( type ) | F_95 ( V_154 ) ) ;
F_96 ( V_160 >= 28 ) ;
V_164 . V_170 = F_15 ( F_97 ( V_157 ) |
( ( V_157 & V_171 ) ? V_172 : 0 ) |
F_98 ( ( V_158 ? V_173 : V_174 ) ) |
F_99 ( V_160 ) ) ;
V_164 . V_175 = F_15 ( F_100 ( F_101 ( V_7 , V_162 ) >> 3 ) ) ;
V_164 . V_133 = F_15 ( V_133 ) ;
V_164 . V_176 = F_15 ( ( T_1 ) ( V_159 >> 32 ) ) ;
V_164 . V_177 = F_15 ( ( T_1 ) ( V_159 & 0xFFFFFFFFULL ) ) ;
V_164 . V_178 = 0 ;
V_164 . V_179 = F_15 ( F_102 ( V_161 >> 2 ) ) ;
}
V_96 = F_85 ( V_7 ,
V_165 +
( V_7 -> V_56 . V_180 >> 5 ) ,
sizeof( V_164 ) , & V_164 ) ;
if ( V_151 )
F_103 ( V_7 -> V_54 , V_165 ) ;
V_143 = V_7 -> V_123 . V_143 ;
F_33 ( & V_7 -> V_123 . V_66 ) ;
if ( ! V_96 )
if ( F_87 ( V_7 -> V_123 . V_126 ,
F_104 ( V_7 -> V_123 . V_16 ,
V_143 ) ) )
return - V_144 ;
return V_96 ;
}
int F_105 ( struct V_1 * V_7 , T_5 * V_181 ,
T_1 V_162 , T_1 V_161 )
{
T_1 V_143 ;
int V_96 ;
F_12 ( L_21 ,
V_42 , V_162 , V_7 -> V_56 . V_182 ,
V_161 ) ;
F_26 ( & V_7 -> V_123 . V_66 ) ;
V_96 = F_85 ( V_7 , V_162 >> 5 , V_161 << 3 ,
V_181 ) ;
V_143 = V_7 -> V_123 . V_143 ;
F_33 ( & V_7 -> V_123 . V_66 ) ;
if ( V_96 )
return V_96 ;
if ( F_87 ( V_7 -> V_123 . V_126 ,
F_104 ( V_7 -> V_123 . V_16 ,
V_143 ) ) )
return - V_144 ;
return 0 ;
}
int F_106 ( struct V_1 * V_7 , T_1 * V_152 , T_1 V_154 ,
enum V_156 V_157 , T_1 V_158 , T_2 V_159 , T_1 V_133 ,
T_4 V_160 , T_1 V_161 , T_1 V_162 )
{
* V_152 = V_166 ;
return F_89 ( V_7 , 0 , V_152 , 1 , V_154 , V_183 , V_157 ,
V_158 , V_159 , V_133 , V_160 , V_161 , V_162 ) ;
}
int F_107 ( struct V_1 * V_7 , T_1 * V_152 , T_1 V_154 ,
enum V_156 V_157 , T_1 V_158 , T_2 V_159 , T_1 V_133 ,
T_4 V_160 , T_1 V_161 , T_1 V_162 )
{
return F_89 ( V_7 , 0 , V_152 , 1 , V_154 , V_183 , V_157 ,
V_158 , V_159 , V_133 , V_160 , V_161 , V_162 ) ;
}
int F_108 ( struct V_1 * V_7 , T_1 V_152 , T_1 V_161 ,
T_1 V_162 )
{
return F_89 ( V_7 , 1 , & V_152 , 0 , 0 , 0 , 0 , 0 , 0ULL , 0 , 0 ,
V_161 , V_162 ) ;
}
int F_109 ( struct V_1 * V_7 , T_1 * V_152 , T_1 V_154 )
{
* V_152 = V_166 ;
return F_89 ( V_7 , 0 , V_152 , 0 , V_154 , V_184 , 0 , 0 , 0ULL , 0 , 0 ,
0 , 0 ) ;
}
int F_110 ( struct V_1 * V_7 , T_1 V_152 )
{
return F_89 ( V_7 , 1 , & V_152 , 0 , 0 , 0 , 0 , 0 , 0ULL , 0 , 0 ,
0 , 0 ) ;
}
int F_111 ( struct V_1 * V_7 , T_1 * V_152 , T_1 V_154 , T_1 V_161 , T_1 V_162 )
{
* V_152 = V_166 ;
return F_89 ( V_7 , 0 , V_152 , 0 , V_154 , V_183 ,
0 , 0 , 0ULL , 0 , 0 , V_161 , V_162 ) ;
}
int F_112 ( struct V_1 * V_7 , struct V_185 * V_186 )
{
struct V_187 * V_38 ;
struct V_39 * V_40 = F_11 ( sizeof( * V_38 ) , V_188 ) ;
if ( ! V_40 )
return - V_43 ;
F_12 ( L_22 , V_42 , V_7 ) ;
V_38 = (struct V_187 * ) F_113 ( V_40 , sizeof( * V_38 ) ) ;
V_38 -> V_189 . V_190 = F_15 ( F_114 ( V_191 ) ) ;
V_38 -> V_189 . V_192 = F_15 ( F_115 ( V_186 -> V_193 ) |
F_116 ( sizeof( * V_38 ) >> 3 ) ) ;
V_38 -> V_194 . V_195 = 0 ;
V_38 -> V_35 = F_15 ( V_186 -> V_35 ) ;
V_38 -> V_154 = F_15 ( V_186 -> V_154 ) ;
V_38 -> V_196 = F_15 ( V_186 -> V_196 ) ;
V_38 -> V_197 = F_15 ( V_186 -> V_197 ) ;
V_38 -> V_83 = F_15 ( V_186 -> V_83 - V_7 -> V_56 . V_198 ) ;
V_38 -> V_199 = F_15 ( V_186 -> V_199 ) ;
V_38 -> V_200 = V_186 -> V_200 ;
V_38 -> V_201 = V_186 -> V_201 ;
V_38 -> V_202 = F_117 ( V_186 -> V_203 ) ;
V_38 -> V_204 = F_117 ( V_186 -> V_204 ) ;
V_38 -> V_205 = F_117 ( V_186 -> V_49 |
F_118 ( V_186 -> V_206 ) |
F_119 ( V_186 -> V_207 ) ) ;
V_38 -> V_208 = F_15 ( V_186 -> V_208 ) ;
V_38 -> V_209 = F_15 ( V_186 -> V_209 ) ;
V_38 -> V_210 = F_16 ( V_186 -> V_210 ) ;
V_38 -> V_211 = F_15 ( V_186 -> V_211 ) ;
V_38 -> V_212 = F_15 ( V_186 -> V_212 ) ;
V_40 -> V_51 = 0 ;
return F_17 ( V_7 -> V_6 , V_40 ) ;
}
void F_120 ( T_6 V_213 )
{
V_214 = V_213 ;
}
void F_121 ( T_6 V_213 )
{
V_214 = NULL ;
}
static int F_122 ( struct V_4 * V_6 , struct V_39 * V_40 )
{
static int V_215 ;
struct V_1 * V_7 = NULL ;
struct V_216 * V_217 = (struct V_216 * ) V_40 -> V_134 ;
F_12 ( L_23 ,
V_215 , V_42 , F_123 ( V_217 ) , F_124 ( V_217 ) ,
F_125 ( V_217 ) , F_126 ( V_217 ) , F_127 ( V_217 ) ,
F_128 ( V_217 ) , F_129 ( V_217 ) , F_130 ( V_217 ) ,
F_131 ( V_217 ) ) ;
F_12 ( L_24 ,
F_70 ( V_217 -> V_15 ) , F_132 ( V_217 -> V_15 ) ,
F_133 ( V_217 -> V_15 ) , F_134 ( V_217 -> V_15 ) ,
F_64 ( V_217 -> V_15 ) , F_135 ( V_217 -> V_15 ) ,
F_136 ( V_217 -> V_15 ) , F_137 ( V_217 -> V_15 ) ) ;
V_7 = (struct V_1 * ) V_6 -> V_218 ;
if ( ! V_7 ) {
F_12 ( L_25 , V_42 ,
V_6 ) ;
return 0 ;
}
if ( F_70 ( V_217 -> V_15 ) == V_131 ) {
V_7 -> V_123 . V_16 = F_137 ( V_217 -> V_15 ) + 1 ;
F_138 ( & V_7 -> V_123 . V_126 ) ;
F_139 ( V_40 ) ;
} else if ( F_70 ( V_217 -> V_15 ) == 0xfff8 )
F_139 ( V_40 ) ;
else if ( V_214 )
(* V_214) ( V_7 , V_40 ) ;
else
F_139 ( V_40 ) ;
V_215 ++ ;
return 0 ;
}
int F_140 ( struct V_1 * V_7 )
{
struct V_219 * V_220 = NULL ;
int V_96 = 0 ;
if ( strlen ( V_7 -> V_2 ) ) {
if ( F_1 ( V_7 -> V_2 ) ) {
return - V_221 ;
}
V_220 = F_141 ( & V_222 , V_7 -> V_2 ) ;
if ( ! V_220 ) {
return - V_223 ;
}
F_142 ( V_220 ) ;
} else if ( V_7 -> V_6 ) {
if ( F_3 ( V_7 -> V_6 ) ) {
return - V_221 ;
}
V_220 = V_7 -> V_6 -> V_224 ;
strncpy ( V_7 -> V_2 , V_7 -> V_6 -> V_225 ,
V_226 ) ;
} else {
F_12 ( L_26 , V_42 ) ;
return - V_223 ;
}
F_32 ( & V_7 -> V_65 , & V_227 ) ;
F_12 ( L_27 , V_42 , V_7 -> V_2 ) ;
memset ( & V_7 -> V_123 , 0 , sizeof( V_7 -> V_123 ) ) ;
if ( ! V_7 -> V_6 )
V_7 -> V_6 = F_143 ( V_220 ) ;
V_7 -> V_6 -> V_218 = ( void * ) V_7 ;
V_96 = V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_228 ,
& ( V_7 -> V_229 ) ) ;
if ( V_96 ) {
F_8 ( L_28 ,
V_42 , V_7 -> V_6 , V_96 ) ;
goto V_82;
}
if ( F_144 ( V_7 -> V_229 . V_230 ) != V_231 ) {
F_8 ( L_29 ,
V_231 ,
F_144 ( V_7 -> V_229 . V_230 ) ) ;
V_96 = - V_223 ;
goto V_82;
}
V_96 = V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_232 ,
& ( V_7 -> V_56 ) ) ;
if ( V_96 ) {
F_8 ( L_28 ,
V_42 , V_7 -> V_6 , V_96 ) ;
goto V_82;
}
V_96 = V_7 -> V_6 -> V_23 ( V_7 -> V_6 , V_233 ,
& ( V_7 -> V_234 ) ) ;
if ( V_96 ) {
F_8 ( L_28 ,
V_42 , V_7 -> V_6 , V_96 ) ;
goto V_82;
}
F_39 ( V_7 , & V_7 -> V_63 ) ;
V_7 -> V_95 = V_235 -
F_145 ( 65536 >>
F_145 ( V_7 -> V_56 . V_236 >>
V_235 ) ) ;
V_7 -> V_237 = V_7 -> V_56 . V_236 >> V_235 ;
V_7 -> V_70 = ( 65536 >> F_145 ( V_7 -> V_237 ) ) - 1 ;
F_12 ( L_30 ,
V_42 , V_7 -> V_2 , V_7 -> V_56 . V_180 ,
V_7 -> V_56 . V_238 , F_146 ( V_7 ) ,
V_7 -> V_56 . V_182 ,
V_7 -> V_56 . V_239 , V_7 -> V_56 . V_198 ,
V_7 -> V_56 . V_240 ) ;
F_12 ( L_31 ,
V_7 -> V_56 . V_236 ,
V_7 -> V_56 . V_94 , V_7 -> V_56 . V_92 ,
V_7 -> V_95 , V_7 -> V_237 , V_7 -> V_70 ) ;
V_96 = F_73 ( V_7 ) ;
if ( V_96 ) {
F_8 ( L_32 , V_42 , V_96 ) ;
goto V_82;
}
V_96 = F_147 ( V_7 , F_146 ( V_7 ) , 0 ,
0 , V_241 , V_242 ,
V_243 ) ;
if ( V_96 ) {
F_8 ( L_33 ,
V_42 , V_96 ) ;
goto V_84;
}
V_96 = F_148 ( V_7 ) ;
if ( V_96 ) {
F_8 ( L_34 ,
V_42 , V_96 ) ;
goto V_87;
}
V_96 = F_149 ( V_7 ) ;
if ( V_96 ) {
F_8 ( L_35 ,
V_42 , V_96 ) ;
goto V_89;
}
return 0 ;
V_89:
F_150 ( V_7 ) ;
V_87:
F_151 ( V_7 -> V_54 ) ;
V_84:
F_84 ( V_7 ) ;
V_82:
V_7 -> V_6 -> V_218 = NULL ;
F_29 ( & V_7 -> V_65 ) ;
return V_96 ;
}
void F_152 ( struct V_1 * V_7 )
{
if ( V_7 ) {
F_150 ( V_7 ) ;
F_153 ( V_7 ) ;
F_29 ( & V_7 -> V_65 ) ;
F_84 ( V_7 ) ;
F_151 ( V_7 -> V_54 ) ;
V_7 -> V_6 -> V_218 = NULL ;
}
}
int T_7 F_154 ( void )
{
if ( F_155 ( V_244 ) )
return - V_43 ;
F_156 ( V_245 , F_122 ) ;
return 0 ;
}
void T_8 F_157 ( void )
{
struct V_1 * V_3 , * V_246 ;
F_156 ( V_245 , NULL ) ;
F_158 (rdev, tmp, &rdev_list, entry)
F_152 ( V_3 ) ;
F_159 () ;
}
static void F_160 ( struct V_75 * V_76 , struct V_8 * V_9 )
{
struct V_86 * V_107 ;
T_3 V_103 = V_76 -> V_113 ;
int V_102 = F_161 ( V_76 -> V_113 , V_76 -> V_112 ) ;
V_107 = V_76 -> V_85 + F_5 ( V_103 , V_76 -> V_114 ) ;
while ( V_102 -- )
if ( ! V_107 -> V_115 ) {
V_103 ++ ;
V_107 = V_76 -> V_85 + F_5 ( V_103 , V_76 -> V_114 ) ;
} else if ( V_107 -> V_247 ) {
F_12 ( L_36 ,
V_42 , F_5 ( V_103 , V_76 -> V_114 ) ,
F_5 ( V_9 -> V_98 , V_9 -> V_25 ) ) ;
V_107 -> V_15 . V_99 |= F_162 ( F_54 ( 1 ) ) ;
* ( V_9 -> V_55 + F_5 ( V_9 -> V_98 , V_9 -> V_25 ) )
= V_107 -> V_15 ;
V_9 -> V_98 ++ ;
V_107 -> V_115 = 0 ;
break;
} else
break;
}
static void F_163 ( struct V_75 * V_76 , struct V_14 * V_248 ,
struct V_14 * V_249 )
{
V_249 -> V_109 . V_110 . V_111 = V_76 -> V_120 -> V_112 ;
V_249 -> V_133 = V_76 -> V_120 -> V_250 ;
V_249 -> V_99 = F_162 ( F_55 ( F_70 ( * V_248 ) ) |
F_54 ( F_164 ( * V_248 ) ) |
F_52 ( V_251 ) |
F_53 ( 1 ) ) ;
}
static void F_165 ( struct V_75 * V_76 )
{
T_1 V_16 = V_76 -> V_120 - V_76 -> V_85 + 1 ;
T_1 V_143 = F_5 ( V_76 -> V_112 , V_76 -> V_114 ) ;
while ( F_5 ( V_16 , V_76 -> V_114 ) != V_143 ) {
V_76 -> V_120 = V_76 -> V_85 + F_5 ( V_16 , V_76 -> V_114 ) ;
if ( V_76 -> V_120 -> V_108 == V_251 )
return;
V_16 ++ ;
}
V_76 -> V_120 = NULL ;
}
int F_166 ( struct V_75 * V_76 , struct V_8 * V_9 , struct V_14 * V_15 ,
T_4 * V_252 , T_2 * V_253 , T_1 * V_12 )
{
int V_13 = 0 ;
struct V_14 * V_248 , V_249 ;
* V_252 = 0 ;
* V_12 = 0 ;
V_248 = F_167 ( V_9 ) ;
F_12 ( L_37 ,
V_42 , F_168 ( * V_248 ) , F_70 ( * V_248 ) ,
F_132 ( * V_248 ) , F_133 ( * V_248 ) , F_134 ( * V_248 ) ,
F_64 ( * V_248 ) , F_135 ( * V_248 ) , F_136 ( * V_248 ) ,
F_137 ( * V_248 ) ) ;
if ( V_76 == NULL ) {
V_13 = - 1 ;
goto V_254;
}
if ( F_65 ( * V_248 ) && ( F_64 ( * V_248 ) == V_119 ) ) {
if ( ! V_76 -> V_120 ) {
if ( F_134 ( * V_248 ) )
V_76 -> error = 1 ;
V_13 = - 1 ;
goto V_254;
}
F_163 ( V_76 , V_248 , & V_249 ) ;
V_248 = & V_249 ;
F_165 ( V_76 ) ;
}
if ( F_64 ( * V_248 ) == V_117 ) {
V_13 = - 1 ;
V_76 -> error = 1 ;
goto V_254;
}
if ( F_134 ( * V_248 ) || V_76 -> error ) {
* V_252 = V_76 -> error ;
V_76 -> error = 1 ;
if ( ( F_64 ( * V_248 ) == V_118 )
&& F_65 ( * V_248 ) ) {
V_13 = - 1 ;
goto V_254;
}
if ( ( F_64 ( * V_248 ) == V_119 ) && F_66 ( * V_248 ) ) {
V_13 = - 1 ;
goto V_254;
}
if ( F_67 ( * V_248 ) && F_65 ( * V_248 ) &&
F_68 ( V_76 -> V_105 , V_76 -> V_106 ) ) {
V_13 = - 1 ;
goto V_254;
}
F_96 ( ( * V_252 == 0 ) && ! F_164 ( * V_248 ) ) ;
goto V_255;
}
if ( F_65 ( * V_248 ) ) {
if ( F_68 ( V_76 -> V_105 , V_76 -> V_106 ) ) {
V_76 -> error = 1 ;
V_13 = - 1 ;
goto V_254;
}
if ( F_169 ( ( F_170 ( * V_248 ) != ( V_76 -> V_105 + 1 ) ) ) ) {
V_76 -> error = 1 ;
V_248 -> V_99 |= F_162 ( F_51 ( V_256 ) ) ;
goto V_255;
}
goto V_255;
}
if ( ! F_164 ( * V_248 ) && ( F_171 ( * V_248 ) != V_76 -> V_113 ) ) {
struct V_86 * V_107 ;
F_12 ( L_38 ,
V_42 ,
F_5 ( F_171 ( * V_248 ) ,
V_76 -> V_114 ) ) ;
V_107 = V_76 -> V_85 +
F_5 ( F_171 ( * V_248 ) , V_76 -> V_114 ) ;
V_107 -> V_15 = * V_248 ;
V_107 -> V_247 = 1 ;
V_13 = - 1 ;
goto V_257;
}
V_255:
* V_15 = * V_248 ;
if ( F_66 ( * V_248 ) ) {
V_76 -> V_113 = F_171 ( * V_248 ) ;
F_12 ( L_39 , V_42 ,
F_5 ( V_76 -> V_113 , V_76 -> V_114 ) ) ;
* V_253 = V_76 -> V_85 [ F_5 ( V_76 -> V_113 , V_76 -> V_114 ) ] . V_258 ;
V_76 -> V_113 ++ ;
} else {
F_12 ( L_40 , V_42 ,
F_5 ( V_76 -> V_105 , V_76 -> V_79 ) ) ;
* V_253 = V_76 -> V_80 [ F_5 ( V_76 -> V_105 , V_76 -> V_79 ) ] . V_258 ;
if ( V_76 -> V_80 [ F_5 ( V_76 -> V_105 , V_76 -> V_79 ) ] . V_162 )
F_172 ( V_76 -> V_3 ,
V_76 -> V_80 [ F_5 ( V_76 -> V_105 ,
V_76 -> V_79 ) ] . V_162 , V_259 ) ;
F_96 ( F_68 ( V_76 -> V_105 , V_76 -> V_106 ) ) ;
V_76 -> V_105 ++ ;
}
V_257:
F_160 ( V_76 , V_9 ) ;
V_254:
if ( F_164 ( * V_248 ) ) {
F_12 ( L_41 ,
V_42 , V_9 , V_9 -> V_20 , V_9 -> V_97 ) ;
++ V_9 -> V_97 ;
} else {
F_12 ( L_42 ,
V_42 , V_9 , V_9 -> V_20 , V_9 -> V_16 ) ;
++ V_9 -> V_16 ;
if ( ( ( V_9 -> V_16 - V_9 -> V_143 ) > ( 1 << ( V_9 -> V_25 - 1 ) ) )
|| ( ( V_9 -> V_16 - V_9 -> V_143 ) >= 128 ) ) {
* V_12 = V_9 -> V_16 - V_9 -> V_143 ;
V_9 -> V_143 = V_9 -> V_16 ;
}
}
return V_13 ;
}
