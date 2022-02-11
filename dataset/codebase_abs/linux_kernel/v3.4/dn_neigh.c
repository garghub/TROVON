static T_1 F_1 ( const void * V_1 ,
const struct V_2 * V_3 ,
T_2 * V_4 )
{
return F_2 ( * ( V_5 * ) V_1 , 0 , V_4 [ 0 ] ) ;
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
struct V_6 * V_7 = F_17 ( V_41 ) ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_44 [ V_45 ] ;
unsigned int V_46 ;
int V_47 ;
F_9 ( V_44 , V_43 -> V_48 ) ;
do {
V_46 = F_18 ( & V_7 -> V_49 ) ;
V_47 = F_19 ( V_39 , V_3 , F_20 ( V_39 -> V_50 ) ,
V_7 -> V_29 , V_44 , V_39 -> V_51 ) ;
} while ( F_21 ( & V_7 -> V_49 , V_46 ) );
if ( V_47 >= 0 )
V_47 = F_22 ( V_39 ) ;
else {
F_13 ( V_39 ) ;
V_47 = - V_15 ;
}
return V_47 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_54 ) + 3 ;
unsigned char * V_55 ;
struct V_54 * V_56 ;
struct V_57 * V_58 = F_24 ( V_39 ) ;
if ( F_25 ( V_39 ) < V_52 ) {
struct V_38 * V_59 = F_26 ( V_39 , V_52 ) ;
if ( V_59 == NULL ) {
if ( F_10 () )
F_11 ( V_60 L_4 ) ;
F_13 ( V_39 ) ;
return - V_61 ;
}
F_13 ( V_39 ) ;
V_39 = V_59 ;
if ( F_10 () )
F_11 ( V_62 L_5 ) ;
}
V_55 = F_27 ( V_39 , sizeof( struct V_54 ) + 3 ) ;
V_56 = (struct V_54 * ) ( V_55 + 3 ) ;
* ( ( V_63 * ) V_55 ) = F_28 ( V_39 -> V_51 - 2 ) ;
* ( V_55 + 2 ) = 1 | V_64 ;
V_56 -> V_65 = V_66 | ( V_58 -> V_67 & ( V_68 | V_69 | V_70 ) ) ;
V_56 -> V_71 = V_56 -> V_72 = 0 ;
F_9 ( V_56 -> V_73 , V_58 -> V_41 ) ;
V_56 -> V_74 = V_56 -> V_75 = 0 ;
F_9 ( V_56 -> V_76 , V_58 -> V_77 ) ;
V_56 -> V_78 = 0 ;
V_56 -> V_79 = V_58 -> V_80 & 0x3f ;
V_56 -> V_81 = 0 ;
V_56 -> V_82 = 0 ;
F_29 ( V_39 ) ;
return F_30 ( V_83 , V_84 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_31 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_85 ) + 2 ;
struct V_85 * V_86 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_24 ( V_39 ) ;
if ( F_25 ( V_39 ) < V_52 ) {
struct V_38 * V_59 = F_26 ( V_39 , V_52 ) ;
if ( V_59 == NULL ) {
if ( F_10 () )
F_11 ( V_60 L_6 ) ;
F_13 ( V_39 ) ;
return - V_61 ;
}
F_13 ( V_39 ) ;
V_39 = V_59 ;
if ( F_10 () )
F_11 ( V_62 L_7 ) ;
}
V_55 = F_27 ( V_39 , sizeof( struct V_85 ) + 2 ) ;
* ( ( V_63 * ) V_55 ) = F_28 ( V_39 -> V_51 - 2 ) ;
V_86 = (struct V_85 * ) ( V_55 + 2 ) ;
V_86 -> V_65 = V_87 | ( V_58 -> V_67 & ( V_69 | V_70 ) ) ;
V_86 -> V_88 = V_58 -> V_41 ;
V_86 -> V_89 = V_58 -> V_77 ;
V_86 -> V_90 = V_58 -> V_80 & 0x3f ;
F_29 ( V_39 ) ;
return F_30 ( V_83 , V_84 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_32 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_85 ) + 2 ;
struct V_85 * V_86 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_24 ( V_39 ) ;
if ( F_25 ( V_39 ) < V_52 ) {
struct V_38 * V_59 = F_26 ( V_39 , V_52 ) ;
if ( V_59 == NULL ) {
if ( F_10 () )
F_11 ( V_60 L_8 ) ;
F_13 ( V_39 ) ;
return - V_61 ;
}
F_13 ( V_39 ) ;
V_39 = V_59 ;
if ( F_10 () )
F_11 ( V_62 L_9 ) ;
}
V_55 = F_27 ( V_39 , sizeof( struct V_85 ) + 2 ) ;
* ( ( V_63 * ) V_55 ) = F_28 ( V_39 -> V_51 - 2 ) ;
V_86 = (struct V_85 * ) ( V_55 + 2 ) ;
V_86 -> V_65 = V_87 | ( V_58 -> V_67 & ( V_69 | V_70 ) ) ;
V_86 -> V_88 = V_58 -> V_41 & F_28 ( 0x03ff ) ;
V_86 -> V_89 = V_58 -> V_77 & F_28 ( 0x03ff ) ;
V_86 -> V_90 = V_58 -> V_80 & 0x3f ;
F_29 ( V_39 ) ;
return F_30 ( V_83 , V_84 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
void F_33 ( struct V_38 * V_39 )
{
F_13 ( V_39 ) ;
}
int F_34 ( struct V_38 * V_39 )
{
struct V_91 * V_92 = (struct V_91 * ) V_39 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_63 V_77 ;
V_77 = F_35 ( V_92 -> V_93 ) ;
V_7 = F_36 ( & V_94 , & V_77 , V_39 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_37 ( & V_7 -> V_95 ) ;
V_7 -> V_96 = V_97 ;
V_11 = F_5 ( V_7 -> V_3 -> V_14 ) ;
if ( ! ( V_7 -> V_23 & V_98 ) ) {
V_7 -> V_99 = V_97 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_38 ( V_39 ) -> V_100 , V_45 ) ;
V_9 -> V_36 = F_39 ( V_92 -> V_36 ) ;
V_9 -> V_101 = V_92 -> V_101 ;
V_9 -> V_20 &= ~ V_21 ;
switch ( V_92 -> V_102 & V_103 ) {
case V_104 :
V_9 -> V_20 &= ~ V_105 ;
V_9 -> V_20 |= V_106 ;
break;
case V_107 :
V_9 -> V_20 |= V_105 ;
}
}
if ( ( F_39 ( V_77 ) >> 10 ) == ( F_39 ( ( V_108 ) ) >> 10 ) ) {
if ( ! V_11 -> V_109 ) {
V_11 -> V_109 = F_40 ( V_7 ) ;
} else {
if ( V_92 -> V_101 > ( (struct V_8 * ) V_11 -> V_109 ) -> V_101 )
F_41 ( F_42 ( & V_11 -> V_109 , F_40 ( V_7 ) ) ) ;
}
}
F_43 ( & V_7 -> V_95 ) ;
F_41 ( V_7 ) ;
}
F_13 ( V_39 ) ;
return 0 ;
}
int F_44 ( struct V_38 * V_39 )
{
struct V_110 * V_92 = (struct V_110 * ) V_39 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_63 V_77 ;
V_77 = F_35 ( V_92 -> V_93 ) ;
V_7 = F_36 ( & V_94 , & V_77 , V_39 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_37 ( & V_7 -> V_95 ) ;
V_7 -> V_96 = V_97 ;
if ( ! ( V_7 -> V_23 & V_98 ) ) {
V_7 -> V_99 = V_97 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_38 ( V_39 ) -> V_100 , V_45 ) ;
V_9 -> V_20 &= ~ ( V_106 | V_105 ) ;
V_9 -> V_36 = F_39 ( V_92 -> V_36 ) ;
V_9 -> V_101 = 0 ;
}
F_43 ( & V_7 -> V_95 ) ;
F_41 ( V_7 ) ;
}
F_13 ( V_39 ) ;
return 0 ;
}
static char * F_45 ( char * V_111 , int V_112 , int V_101 )
{
int V_113 ;
unsigned char * V_114 = NULL ;
V_111 += 6 ;
for( V_113 = 0 ; V_113 < V_112 ; V_113 ++ ) {
if ( ! V_114 || ( * V_111 < * V_114 ) )
V_114 = V_111 ;
V_111 += 7 ;
}
if ( ! V_114 )
return NULL ;
return ( * V_114 < V_101 ) ? ( V_114 - 6 ) : NULL ;
}
static void F_46 ( struct V_6 * V_7 , void * V_115 )
{
struct V_116 * V_117 = V_115 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_117 -> V_3 )
return;
V_9 = (struct V_8 * ) V_7 ;
if ( ! ( V_9 -> V_20 & ( V_106 | V_105 ) ) )
return;
if ( V_117 -> V_118 == V_117 -> V_119 )
V_117 -> V_120 = F_45 ( V_117 -> V_121 , V_117 -> V_119 , V_9 -> V_101 ) ;
else
V_117 -> V_118 ++ ;
if ( V_117 -> V_120 == NULL )
return;
F_9 ( V_117 -> V_120 , V_9 -> V_34 ) ;
V_117 -> V_120 += 6 ;
* ( V_117 -> V_120 ) = V_7 -> V_23 & V_122 ? 0x80 : 0x0 ;
* ( V_117 -> V_120 ) |= V_9 -> V_101 ;
V_117 -> V_120 ++ ;
}
int F_47 ( struct V_2 * V_3 , unsigned char * V_121 , int V_119 )
{
struct V_116 V_123 ;
V_123 . V_3 = V_3 ;
V_123 . V_118 = 0 ;
V_123 . V_119 = V_119 ;
V_123 . V_121 = V_121 ;
V_123 . V_120 = V_121 ;
F_48 ( & V_94 , F_46 , & V_123 ) ;
return V_123 . V_118 ;
}
static inline void F_49 ( struct V_124 * V_46 ,
struct V_6 * V_119 )
{
struct V_8 * V_9 = (struct V_8 * ) V_119 ;
char V_125 [ V_126 ] ;
F_50 ( & V_119 -> V_95 ) ;
F_51 ( V_46 , L_10 ,
F_52 ( F_39 ( V_9 -> V_34 ) , V_125 ) ,
( V_9 -> V_20 & V_106 ) ? L_11 : L_12 ,
( V_9 -> V_20 & V_105 ) ? L_13 : L_12 ,
( V_9 -> V_20 & V_21 ) ? L_14 : L_12 ,
V_9 -> V_119 . V_23 ,
F_53 ( & V_9 -> V_119 . V_127 ) ,
V_9 -> V_36 ,
( V_9 -> V_119 . V_3 ) ? V_9 -> V_119 . V_3 -> V_128 : L_15 ) ;
F_54 ( & V_119 -> V_95 ) ;
}
static int F_55 ( struct V_124 * V_46 , void * V_129 )
{
if ( V_129 == V_130 ) {
F_56 ( V_46 , L_16 ) ;
} else {
F_49 ( V_46 , V_129 ) ;
}
return 0 ;
}
static void * F_57 ( struct V_124 * V_46 , T_3 * V_131 )
{
return F_58 ( V_46 , V_131 , & V_94 ,
V_132 ) ;
}
static int F_59 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_60 ( V_133 , V_134 , & V_135 ,
sizeof( struct V_136 ) ) ;
}
void T_4 F_61 ( void )
{
F_62 ( & V_94 ) ;
F_63 ( & V_137 , L_17 , V_138 , & V_139 ) ;
}
void T_5 F_64 ( void )
{
F_65 ( & V_137 , L_17 ) ;
F_66 ( & V_94 ) ;
}
