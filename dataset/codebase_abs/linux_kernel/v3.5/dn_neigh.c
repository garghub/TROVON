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
F_10 ( L_1 ,
V_3 -> type ) ;
return - V_15 ;
}
V_9 -> V_35 = V_3 -> V_36 - 2 ;
return 0 ;
}
static void F_11 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
F_12 ( V_39 L_2 ) ;
F_13 ( V_38 ) ;
}
static void F_14 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
F_12 ( V_39 L_3 ) ;
F_13 ( V_38 ) ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_40 * V_41 = F_16 ( V_38 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_41 ;
struct V_6 * V_7 = F_17 ( V_41 ) ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_44 [ V_45 ] ;
unsigned int V_46 ;
int V_47 ;
F_9 ( V_44 , V_43 -> V_48 ) ;
do {
V_46 = F_18 ( & V_7 -> V_49 ) ;
V_47 = F_19 ( V_38 , V_3 , F_20 ( V_38 -> V_50 ) ,
V_7 -> V_29 , V_44 , V_38 -> V_51 ) ;
} while ( F_21 ( & V_7 -> V_49 , V_46 ) );
if ( V_47 >= 0 )
V_47 = F_22 ( V_38 ) ;
else {
F_13 ( V_38 ) ;
V_47 = - V_15 ;
}
return V_47 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_54 ) + 3 ;
unsigned char * V_55 ;
struct V_54 * V_56 ;
struct V_57 * V_58 = F_24 ( V_38 ) ;
if ( F_25 ( V_38 ) < V_52 ) {
struct V_37 * V_59 = F_26 ( V_38 , V_52 ) ;
if ( V_59 == NULL ) {
F_27 ( L_4 ) ;
F_13 ( V_38 ) ;
return - V_60 ;
}
F_13 ( V_38 ) ;
V_38 = V_59 ;
F_28 ( L_5 ) ;
}
V_55 = F_29 ( V_38 , sizeof( struct V_54 ) + 3 ) ;
V_56 = (struct V_54 * ) ( V_55 + 3 ) ;
* ( ( V_61 * ) V_55 ) = F_30 ( V_38 -> V_51 - 2 ) ;
* ( V_55 + 2 ) = 1 | V_62 ;
V_56 -> V_63 = V_64 | ( V_58 -> V_65 & ( V_66 | V_67 | V_68 ) ) ;
V_56 -> V_69 = V_56 -> V_70 = 0 ;
F_9 ( V_56 -> V_71 , V_58 -> V_41 ) ;
V_56 -> V_72 = V_56 -> V_73 = 0 ;
F_9 ( V_56 -> V_74 , V_58 -> V_75 ) ;
V_56 -> V_76 = 0 ;
V_56 -> V_77 = V_58 -> V_78 & 0x3f ;
V_56 -> V_79 = 0 ;
V_56 -> V_80 = 0 ;
F_31 ( V_38 ) ;
return F_32 ( V_81 , V_82 , V_38 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_33 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_83 ) + 2 ;
struct V_83 * V_84 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_24 ( V_38 ) ;
if ( F_25 ( V_38 ) < V_52 ) {
struct V_37 * V_59 = F_26 ( V_38 , V_52 ) ;
if ( V_59 == NULL ) {
F_27 ( L_6 ) ;
F_13 ( V_38 ) ;
return - V_60 ;
}
F_13 ( V_38 ) ;
V_38 = V_59 ;
F_28 ( L_7 ) ;
}
V_55 = F_29 ( V_38 , sizeof( struct V_83 ) + 2 ) ;
* ( ( V_61 * ) V_55 ) = F_30 ( V_38 -> V_51 - 2 ) ;
V_84 = (struct V_83 * ) ( V_55 + 2 ) ;
V_84 -> V_63 = V_85 | ( V_58 -> V_65 & ( V_67 | V_68 ) ) ;
V_84 -> V_86 = V_58 -> V_41 ;
V_84 -> V_87 = V_58 -> V_75 ;
V_84 -> V_88 = V_58 -> V_78 & 0x3f ;
F_31 ( V_38 ) ;
return F_32 ( V_81 , V_82 , V_38 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_34 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_83 ) + 2 ;
struct V_83 * V_84 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_24 ( V_38 ) ;
if ( F_25 ( V_38 ) < V_52 ) {
struct V_37 * V_59 = F_26 ( V_38 , V_52 ) ;
if ( V_59 == NULL ) {
F_27 ( L_8 ) ;
F_13 ( V_38 ) ;
return - V_60 ;
}
F_13 ( V_38 ) ;
V_38 = V_59 ;
F_28 ( L_9 ) ;
}
V_55 = F_29 ( V_38 , sizeof( struct V_83 ) + 2 ) ;
* ( ( V_61 * ) V_55 ) = F_30 ( V_38 -> V_51 - 2 ) ;
V_84 = (struct V_83 * ) ( V_55 + 2 ) ;
V_84 -> V_63 = V_85 | ( V_58 -> V_65 & ( V_67 | V_68 ) ) ;
V_84 -> V_86 = V_58 -> V_41 & F_30 ( 0x03ff ) ;
V_84 -> V_87 = V_58 -> V_75 & F_30 ( 0x03ff ) ;
V_84 -> V_88 = V_58 -> V_78 & 0x3f ;
F_31 ( V_38 ) ;
return F_32 ( V_81 , V_82 , V_38 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
void F_35 ( struct V_37 * V_38 )
{
F_13 ( V_38 ) ;
}
int F_36 ( struct V_37 * V_38 )
{
struct V_89 * V_90 = (struct V_89 * ) V_38 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_61 V_75 ;
V_75 = F_37 ( V_90 -> V_91 ) ;
V_7 = F_38 ( & V_92 , & V_75 , V_38 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_39 ( & V_7 -> V_93 ) ;
V_7 -> V_94 = V_95 ;
V_11 = F_5 ( V_7 -> V_3 -> V_14 ) ;
if ( ! ( V_7 -> V_23 & V_96 ) ) {
V_7 -> V_97 = V_95 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_40 ( V_38 ) -> V_98 , V_45 ) ;
V_9 -> V_35 = F_41 ( V_90 -> V_35 ) ;
V_9 -> V_99 = V_90 -> V_99 ;
V_9 -> V_20 &= ~ V_21 ;
switch ( V_90 -> V_100 & V_101 ) {
case V_102 :
V_9 -> V_20 &= ~ V_103 ;
V_9 -> V_20 |= V_104 ;
break;
case V_105 :
V_9 -> V_20 |= V_103 ;
}
}
if ( ( F_41 ( V_75 ) >> 10 ) == ( F_41 ( ( V_106 ) ) >> 10 ) ) {
if ( ! V_11 -> V_107 ) {
V_11 -> V_107 = F_42 ( V_7 ) ;
} else {
if ( V_90 -> V_99 > ( (struct V_8 * ) V_11 -> V_107 ) -> V_99 )
F_43 ( F_44 ( & V_11 -> V_107 , F_42 ( V_7 ) ) ) ;
}
}
F_45 ( & V_7 -> V_93 ) ;
F_43 ( V_7 ) ;
}
F_13 ( V_38 ) ;
return 0 ;
}
int F_46 ( struct V_37 * V_38 )
{
struct V_108 * V_90 = (struct V_108 * ) V_38 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_61 V_75 ;
V_75 = F_37 ( V_90 -> V_91 ) ;
V_7 = F_38 ( & V_92 , & V_75 , V_38 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_39 ( & V_7 -> V_93 ) ;
V_7 -> V_94 = V_95 ;
if ( ! ( V_7 -> V_23 & V_96 ) ) {
V_7 -> V_97 = V_95 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_40 ( V_38 ) -> V_98 , V_45 ) ;
V_9 -> V_20 &= ~ ( V_104 | V_103 ) ;
V_9 -> V_35 = F_41 ( V_90 -> V_35 ) ;
V_9 -> V_99 = 0 ;
}
F_45 ( & V_7 -> V_93 ) ;
F_43 ( V_7 ) ;
}
F_13 ( V_38 ) ;
return 0 ;
}
static char * F_47 ( char * V_109 , int V_110 , int V_99 )
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
static void F_48 ( struct V_6 * V_7 , void * V_113 )
{
struct V_114 * V_115 = V_113 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_115 -> V_3 )
return;
V_9 = (struct V_8 * ) V_7 ;
if ( ! ( V_9 -> V_20 & ( V_104 | V_103 ) ) )
return;
if ( V_115 -> V_116 == V_115 -> V_117 )
V_115 -> V_118 = F_47 ( V_115 -> V_119 , V_115 -> V_117 , V_9 -> V_99 ) ;
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
int F_49 ( struct V_2 * V_3 , unsigned char * V_119 , int V_117 )
{
struct V_114 V_121 ;
V_121 . V_3 = V_3 ;
V_121 . V_116 = 0 ;
V_121 . V_117 = V_117 ;
V_121 . V_119 = V_119 ;
V_121 . V_118 = V_119 ;
F_50 ( & V_92 , F_48 , & V_121 ) ;
return V_121 . V_116 ;
}
static inline void F_51 ( struct V_122 * V_46 ,
struct V_6 * V_117 )
{
struct V_8 * V_9 = (struct V_8 * ) V_117 ;
char V_123 [ V_124 ] ;
F_52 ( & V_117 -> V_93 ) ;
F_53 ( V_46 , L_10 ,
F_54 ( F_41 ( V_9 -> V_34 ) , V_123 ) ,
( V_9 -> V_20 & V_104 ) ? L_11 : L_12 ,
( V_9 -> V_20 & V_103 ) ? L_13 : L_12 ,
( V_9 -> V_20 & V_21 ) ? L_14 : L_12 ,
V_9 -> V_117 . V_23 ,
F_55 ( & V_9 -> V_117 . V_125 ) ,
V_9 -> V_35 ,
( V_9 -> V_117 . V_3 ) ? V_9 -> V_117 . V_3 -> V_126 : L_15 ) ;
F_56 ( & V_117 -> V_93 ) ;
}
static int F_57 ( struct V_122 * V_46 , void * V_127 )
{
if ( V_127 == V_128 ) {
F_58 ( V_46 , L_16 ) ;
} else {
F_51 ( V_46 , V_127 ) ;
}
return 0 ;
}
static void * F_59 ( struct V_122 * V_46 , T_3 * V_129 )
{
return F_60 ( V_46 , V_129 , & V_92 ,
V_130 ) ;
}
static int F_61 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
return F_62 ( V_131 , V_132 , & V_133 ,
sizeof( struct V_134 ) ) ;
}
void T_4 F_63 ( void )
{
F_64 ( & V_92 ) ;
F_65 ( & V_135 , L_17 , V_136 , & V_137 ) ;
}
void T_5 F_66 ( void )
{
F_67 ( & V_135 , L_17 ) ;
F_68 ( & V_92 ) ;
}
