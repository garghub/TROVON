static T_1 F_1 ( const void * V_1 ,
const struct V_2 * V_3 ,
T_2 V_4 )
{
return F_2 ( * ( V_5 * ) V_1 , 0 , V_4 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
F_4 () ;
V_11 = F_5 ( V_3 -> V_14 ) ;
if ( V_11 == NULL ) {
F_6 () ;
return - V_15 ;
}
V_13 = V_11 -> V_12 ;
if ( ! V_13 ) {
F_6 () ;
return - V_15 ;
}
F_7 ( V_7 -> V_13 ) ;
V_7 -> V_13 = F_8 ( V_13 ) ;
if ( V_11 -> V_16 )
V_7 -> V_17 = & V_18 ;
else
V_7 -> V_17 = & V_19 ;
F_6 () ;
if ( V_9 -> V_20 & V_21 )
V_7 -> V_17 = & V_22 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_25 = V_7 -> V_17 -> V_26 ;
if ( ( V_3 -> type == V_27 ) || ( V_3 -> V_20 & V_28 ) )
memcpy ( V_7 -> V_29 , V_3 -> V_30 , V_3 -> V_31 ) ;
else if ( ( V_3 -> type == V_32 ) || ( V_3 -> type == V_33 ) )
F_9 ( V_7 -> V_29 , V_9 -> V_34 ) ;
else {
if ( F_10 () )
F_11 ( V_35 L_1 , V_3 -> type ) ;
return - V_15 ;
}
V_9 -> V_36 = V_3 -> V_37 - 2 ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
F_11 ( V_35 L_2 ) ;
F_13 ( V_39 ) ;
}
static void F_14 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
F_11 ( V_35 L_3 ) ;
F_13 ( V_39 ) ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_16 ( V_39 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_41 ;
struct V_6 * V_7 = V_41 -> V_6 ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_44 [ V_45 ] ;
F_9 ( V_44 , V_43 -> V_46 ) ;
if ( F_17 ( V_39 , V_3 , F_18 ( V_39 -> V_47 ) , V_7 -> V_29 ,
V_44 , V_39 -> V_48 ) >= 0 )
return V_7 -> V_17 -> V_49 ( V_39 ) ;
if ( F_10 () )
F_11 ( V_35 L_4 ) ;
F_13 ( V_39 ) ;
return - V_15 ;
}
static int F_19 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_16 ( V_39 ) ;
struct V_6 * V_7 = V_41 -> V_6 ;
struct V_2 * V_3 = V_7 -> V_3 ;
int V_50 = V_3 -> V_51 + sizeof( struct V_52 ) + 3 ;
unsigned char * V_53 ;
struct V_52 * V_54 ;
struct V_55 * V_56 = F_20 ( V_39 ) ;
if ( F_21 ( V_39 ) < V_50 ) {
struct V_38 * V_57 = F_22 ( V_39 , V_50 ) ;
if ( V_57 == NULL ) {
if ( F_10 () )
F_11 ( V_58 L_5 ) ;
F_13 ( V_39 ) ;
return - V_59 ;
}
F_13 ( V_39 ) ;
V_39 = V_57 ;
if ( F_10 () )
F_11 ( V_60 L_6 ) ;
}
V_53 = F_23 ( V_39 , sizeof( struct V_52 ) + 3 ) ;
V_54 = (struct V_52 * ) ( V_53 + 3 ) ;
* ( ( V_61 * ) V_53 ) = F_24 ( V_39 -> V_48 - 2 ) ;
* ( V_53 + 2 ) = 1 | V_62 ;
V_54 -> V_63 = V_64 | ( V_56 -> V_65 & ( V_66 | V_67 | V_68 ) ) ;
V_54 -> V_69 = V_54 -> V_70 = 0 ;
F_9 ( V_54 -> V_71 , V_56 -> V_41 ) ;
V_54 -> V_72 = V_54 -> V_73 = 0 ;
F_9 ( V_54 -> V_74 , V_56 -> V_75 ) ;
V_54 -> V_76 = 0 ;
V_54 -> V_77 = V_56 -> V_78 & 0x3f ;
V_54 -> V_79 = 0 ;
V_54 -> V_80 = 0 ;
F_25 ( V_39 ) ;
return F_26 ( V_81 , V_82 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_16 ( V_39 ) ;
struct V_6 * V_7 = V_41 -> V_6 ;
struct V_2 * V_3 = V_7 -> V_3 ;
int V_50 = V_3 -> V_51 + sizeof( struct V_83 ) + 2 ;
struct V_83 * V_84 ;
unsigned char * V_53 ;
struct V_55 * V_56 = F_20 ( V_39 ) ;
if ( F_21 ( V_39 ) < V_50 ) {
struct V_38 * V_57 = F_22 ( V_39 , V_50 ) ;
if ( V_57 == NULL ) {
if ( F_10 () )
F_11 ( V_58 L_7 ) ;
F_13 ( V_39 ) ;
return - V_59 ;
}
F_13 ( V_39 ) ;
V_39 = V_57 ;
if ( F_10 () )
F_11 ( V_60 L_8 ) ;
}
V_53 = F_23 ( V_39 , sizeof( struct V_83 ) + 2 ) ;
* ( ( V_61 * ) V_53 ) = F_24 ( V_39 -> V_48 - 2 ) ;
V_84 = (struct V_83 * ) ( V_53 + 2 ) ;
V_84 -> V_63 = V_85 | ( V_56 -> V_65 & ( V_67 | V_68 ) ) ;
V_84 -> V_86 = V_56 -> V_41 ;
V_84 -> V_87 = V_56 -> V_75 ;
V_84 -> V_88 = V_56 -> V_78 & 0x3f ;
F_25 ( V_39 ) ;
return F_26 ( V_81 , V_82 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_16 ( V_39 ) ;
struct V_6 * V_7 = V_41 -> V_6 ;
struct V_2 * V_3 = V_7 -> V_3 ;
int V_50 = V_3 -> V_51 + sizeof( struct V_83 ) + 2 ;
struct V_83 * V_84 ;
unsigned char * V_53 ;
struct V_55 * V_56 = F_20 ( V_39 ) ;
if ( F_21 ( V_39 ) < V_50 ) {
struct V_38 * V_57 = F_22 ( V_39 , V_50 ) ;
if ( V_57 == NULL ) {
if ( F_10 () )
F_11 ( V_58 L_9 ) ;
F_13 ( V_39 ) ;
return - V_59 ;
}
F_13 ( V_39 ) ;
V_39 = V_57 ;
if ( F_10 () )
F_11 ( V_60 L_10 ) ;
}
V_53 = F_23 ( V_39 , sizeof( struct V_83 ) + 2 ) ;
* ( ( V_61 * ) V_53 ) = F_24 ( V_39 -> V_48 - 2 ) ;
V_84 = (struct V_83 * ) ( V_53 + 2 ) ;
V_84 -> V_63 = V_85 | ( V_56 -> V_65 & ( V_67 | V_68 ) ) ;
V_84 -> V_86 = V_56 -> V_41 & F_24 ( 0x03ff ) ;
V_84 -> V_87 = V_56 -> V_75 & F_24 ( 0x03ff ) ;
V_84 -> V_88 = V_56 -> V_78 & 0x3f ;
F_25 ( V_39 ) ;
return F_26 ( V_81 , V_82 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
void F_29 ( struct V_38 * V_39 )
{
F_13 ( V_39 ) ;
}
int F_30 ( struct V_38 * V_39 )
{
struct V_89 * V_90 = (struct V_89 * ) V_39 -> V_53 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_61 V_75 ;
V_75 = F_31 ( V_90 -> V_91 ) ;
V_7 = F_32 ( & V_92 , & V_75 , V_39 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_33 ( & V_7 -> V_93 ) ;
V_7 -> V_94 = V_95 ;
V_11 = F_5 ( V_7 -> V_3 -> V_14 ) ;
if ( ! ( V_7 -> V_23 & V_96 ) ) {
V_7 -> V_97 = V_95 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_34 ( V_39 ) -> V_98 , V_45 ) ;
V_9 -> V_36 = F_35 ( V_90 -> V_36 ) ;
V_9 -> V_99 = V_90 -> V_99 ;
V_9 -> V_20 &= ~ V_21 ;
switch( V_90 -> V_100 & V_101 ) {
case V_102 :
V_9 -> V_20 &= ~ V_103 ;
V_9 -> V_20 |= V_104 ;
break;
case V_105 :
V_9 -> V_20 |= V_103 ;
}
}
if ( ( F_35 ( V_75 ) >> 10 ) == ( F_35 ( ( V_106 ) ) >> 10 ) ) {
if ( ! V_11 -> V_107 ) {
V_11 -> V_107 = F_36 ( V_7 ) ;
} else {
if ( V_90 -> V_99 > ( (struct V_8 * ) V_11 -> V_107 ) -> V_99 )
F_37 ( F_38 ( & V_11 -> V_107 , F_36 ( V_7 ) ) ) ;
}
}
F_39 ( & V_7 -> V_93 ) ;
F_37 ( V_7 ) ;
}
F_13 ( V_39 ) ;
return 0 ;
}
int F_40 ( struct V_38 * V_39 )
{
struct V_108 * V_90 = (struct V_108 * ) V_39 -> V_53 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_61 V_75 ;
V_75 = F_31 ( V_90 -> V_91 ) ;
V_7 = F_32 ( & V_92 , & V_75 , V_39 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_33 ( & V_7 -> V_93 ) ;
V_7 -> V_94 = V_95 ;
if ( ! ( V_7 -> V_23 & V_96 ) ) {
V_7 -> V_97 = V_95 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_34 ( V_39 ) -> V_98 , V_45 ) ;
V_9 -> V_20 &= ~ ( V_104 | V_103 ) ;
V_9 -> V_36 = F_35 ( V_90 -> V_36 ) ;
V_9 -> V_99 = 0 ;
}
F_39 ( & V_7 -> V_93 ) ;
F_37 ( V_7 ) ;
}
F_13 ( V_39 ) ;
return 0 ;
}
static char * F_41 ( char * V_109 , int V_110 , int V_99 )
{
int V_111 ;
unsigned char * V_112 = NULL ;
V_109 += 6 ;
for( V_111 = 0 ; V_111 < V_110 ; V_111 ++ ) {
if ( ! V_112 || ( * V_109 < * V_112 ) )
V_112 = V_109 ;
V_109 += 7 ;
}
if ( ! V_112 )
return NULL ;
return ( * V_112 < V_99 ) ? ( V_112 - 6 ) : NULL ;
}
static void F_42 ( struct V_6 * V_7 , void * V_113 )
{
struct V_114 * V_115 = V_113 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_115 -> V_3 )
return;
V_9 = (struct V_8 * ) V_7 ;
if ( ! ( V_9 -> V_20 & ( V_104 | V_103 ) ) )
return;
if ( V_115 -> V_116 == V_115 -> V_117 )
V_115 -> V_118 = F_41 ( V_115 -> V_119 , V_115 -> V_117 , V_9 -> V_99 ) ;
else
V_115 -> V_116 ++ ;
if ( V_115 -> V_118 == NULL )
return;
F_9 ( V_115 -> V_118 , V_9 -> V_34 ) ;
V_115 -> V_118 += 6 ;
* ( V_115 -> V_118 ) = V_7 -> V_23 & V_120 ? 0x80 : 0x0 ;
* ( V_115 -> V_118 ) |= V_9 -> V_99 ;
V_115 -> V_118 ++ ;
}
int F_43 ( struct V_2 * V_3 , unsigned char * V_119 , int V_117 )
{
struct V_114 V_121 ;
V_121 . V_3 = V_3 ;
V_121 . V_116 = 0 ;
V_121 . V_117 = V_117 ;
V_121 . V_119 = V_119 ;
V_121 . V_118 = V_119 ;
F_44 ( & V_92 , F_42 , & V_121 ) ;
return V_121 . V_116 ;
}
static inline void F_45 ( struct V_122 * V_123 ,
struct V_6 * V_117 )
{
struct V_8 * V_9 = (struct V_8 * ) V_117 ;
char V_124 [ V_125 ] ;
F_46 ( & V_117 -> V_93 ) ;
F_47 ( V_123 , L_11 ,
F_48 ( F_35 ( V_9 -> V_34 ) , V_124 ) ,
( V_9 -> V_20 & V_104 ) ? L_12 : L_13 ,
( V_9 -> V_20 & V_103 ) ? L_14 : L_13 ,
( V_9 -> V_20 & V_21 ) ? L_15 : L_13 ,
V_9 -> V_117 . V_23 ,
F_49 ( & V_9 -> V_117 . V_126 ) ,
V_9 -> V_36 ,
( V_9 -> V_117 . V_3 ) ? V_9 -> V_117 . V_3 -> V_127 : L_16 ) ;
F_50 ( & V_117 -> V_93 ) ;
}
static int F_51 ( struct V_122 * V_123 , void * V_128 )
{
if ( V_128 == V_129 ) {
F_52 ( V_123 , L_17 ) ;
} else {
F_45 ( V_123 , V_128 ) ;
}
return 0 ;
}
static void * F_53 ( struct V_122 * V_123 , T_3 * V_130 )
{
return F_54 ( V_123 , V_130 , & V_92 ,
V_131 ) ;
}
static int F_55 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
return F_56 ( V_132 , V_133 , & V_134 ,
sizeof( struct V_135 ) ) ;
}
void T_4 F_57 ( void )
{
F_58 ( & V_92 ) ;
F_59 ( & V_136 , L_18 , V_137 , & V_138 ) ;
}
void T_5 F_60 ( void )
{
F_61 ( & V_136 , L_18 ) ;
F_62 ( & V_92 ) ;
}
