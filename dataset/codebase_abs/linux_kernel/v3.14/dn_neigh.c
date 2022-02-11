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
struct V_6 * V_7 = V_43 -> V_44 ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_45 [ V_46 ] ;
unsigned int V_47 ;
int V_48 ;
F_9 ( V_45 , V_43 -> V_49 ) ;
do {
V_47 = F_17 ( & V_7 -> V_50 ) ;
V_48 = F_18 ( V_38 , V_3 , F_19 ( V_38 -> V_51 ) ,
V_7 -> V_29 , V_45 , V_38 -> V_52 ) ;
} while ( F_20 ( & V_7 -> V_50 , V_47 ) );
if ( V_48 >= 0 )
V_48 = F_21 ( V_38 ) ;
else {
F_13 ( V_38 ) ;
V_48 = - V_15 ;
}
return V_48 ;
}
static int F_22 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_53 = V_3 -> V_54 + sizeof( struct V_55 ) + 3 ;
unsigned char * V_56 ;
struct V_55 * V_57 ;
struct V_58 * V_59 = F_23 ( V_38 ) ;
if ( F_24 ( V_38 ) < V_53 ) {
struct V_37 * V_60 = F_25 ( V_38 , V_53 ) ;
if ( V_60 == NULL ) {
F_26 ( L_4 ) ;
F_13 ( V_38 ) ;
return - V_61 ;
}
F_27 ( V_38 ) ;
V_38 = V_60 ;
F_28 ( L_5 ) ;
}
V_56 = F_29 ( V_38 , sizeof( struct V_55 ) + 3 ) ;
V_57 = (struct V_55 * ) ( V_56 + 3 ) ;
* ( ( V_62 * ) V_56 ) = F_30 ( V_38 -> V_52 - 2 ) ;
* ( V_56 + 2 ) = 1 | V_63 ;
V_57 -> V_64 = V_65 | ( V_59 -> V_66 & ( V_67 | V_68 | V_69 ) ) ;
V_57 -> V_70 = V_57 -> V_71 = 0 ;
F_9 ( V_57 -> V_72 , V_59 -> V_41 ) ;
V_57 -> V_73 = V_57 -> V_74 = 0 ;
F_9 ( V_57 -> V_75 , V_59 -> V_76 ) ;
V_57 -> V_77 = 0 ;
V_57 -> V_78 = V_59 -> V_79 & 0x3f ;
V_57 -> V_80 = 0 ;
V_57 -> V_81 = 0 ;
F_31 ( V_38 ) ;
return F_32 ( V_82 , V_83 , V_38 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_33 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_53 = V_3 -> V_54 + sizeof( struct V_84 ) + 2 ;
struct V_84 * V_85 ;
unsigned char * V_56 ;
struct V_58 * V_59 = F_23 ( V_38 ) ;
if ( F_24 ( V_38 ) < V_53 ) {
struct V_37 * V_60 = F_25 ( V_38 , V_53 ) ;
if ( V_60 == NULL ) {
F_26 ( L_6 ) ;
F_13 ( V_38 ) ;
return - V_61 ;
}
F_27 ( V_38 ) ;
V_38 = V_60 ;
F_28 ( L_7 ) ;
}
V_56 = F_29 ( V_38 , sizeof( struct V_84 ) + 2 ) ;
* ( ( V_62 * ) V_56 ) = F_30 ( V_38 -> V_52 - 2 ) ;
V_85 = (struct V_84 * ) ( V_56 + 2 ) ;
V_85 -> V_64 = V_86 | ( V_59 -> V_66 & ( V_68 | V_69 ) ) ;
V_85 -> V_87 = V_59 -> V_41 ;
V_85 -> V_88 = V_59 -> V_76 ;
V_85 -> V_89 = V_59 -> V_79 & 0x3f ;
F_31 ( V_38 ) ;
return F_32 ( V_82 , V_83 , V_38 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_34 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_53 = V_3 -> V_54 + sizeof( struct V_84 ) + 2 ;
struct V_84 * V_85 ;
unsigned char * V_56 ;
struct V_58 * V_59 = F_23 ( V_38 ) ;
if ( F_24 ( V_38 ) < V_53 ) {
struct V_37 * V_60 = F_25 ( V_38 , V_53 ) ;
if ( V_60 == NULL ) {
F_26 ( L_8 ) ;
F_13 ( V_38 ) ;
return - V_61 ;
}
F_27 ( V_38 ) ;
V_38 = V_60 ;
F_28 ( L_9 ) ;
}
V_56 = F_29 ( V_38 , sizeof( struct V_84 ) + 2 ) ;
* ( ( V_62 * ) V_56 ) = F_30 ( V_38 -> V_52 - 2 ) ;
V_85 = (struct V_84 * ) ( V_56 + 2 ) ;
V_85 -> V_64 = V_86 | ( V_59 -> V_66 & ( V_68 | V_69 ) ) ;
V_85 -> V_87 = V_59 -> V_41 & F_30 ( 0x03ff ) ;
V_85 -> V_88 = V_59 -> V_76 & F_30 ( 0x03ff ) ;
V_85 -> V_89 = V_59 -> V_79 & 0x3f ;
F_31 ( V_38 ) ;
return F_32 ( V_82 , V_83 , V_38 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
void F_35 ( struct V_37 * V_38 )
{
F_13 ( V_38 ) ;
}
int F_36 ( struct V_37 * V_38 )
{
struct V_90 * V_91 = (struct V_90 * ) V_38 -> V_56 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_62 V_76 ;
V_76 = F_37 ( V_91 -> V_92 ) ;
V_7 = F_38 ( & V_93 , & V_76 , V_38 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_39 ( & V_7 -> V_94 ) ;
V_7 -> V_95 = V_96 ;
V_11 = F_5 ( V_7 -> V_3 -> V_14 ) ;
if ( ! ( V_7 -> V_23 & V_97 ) ) {
V_7 -> V_98 = V_96 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_40 ( V_38 ) -> V_99 , V_46 ) ;
V_9 -> V_35 = F_41 ( V_91 -> V_35 ) ;
V_9 -> V_100 = V_91 -> V_100 ;
V_9 -> V_20 &= ~ V_21 ;
switch ( V_91 -> V_101 & V_102 ) {
case V_103 :
V_9 -> V_20 &= ~ V_104 ;
V_9 -> V_20 |= V_105 ;
break;
case V_106 :
V_9 -> V_20 |= V_104 ;
}
}
if ( ( F_41 ( V_76 ) >> 10 ) == ( F_41 ( ( V_107 ) ) >> 10 ) ) {
if ( ! V_11 -> V_108 ) {
V_11 -> V_108 = F_42 ( V_7 ) ;
} else {
if ( V_91 -> V_100 > ( (struct V_8 * ) V_11 -> V_108 ) -> V_100 )
F_43 ( F_44 ( & V_11 -> V_108 , F_42 ( V_7 ) ) ) ;
}
}
F_45 ( & V_7 -> V_94 ) ;
F_43 ( V_7 ) ;
}
F_13 ( V_38 ) ;
return 0 ;
}
int F_46 ( struct V_37 * V_38 )
{
struct V_109 * V_91 = (struct V_109 * ) V_38 -> V_56 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_62 V_76 ;
V_76 = F_37 ( V_91 -> V_92 ) ;
V_7 = F_38 ( & V_93 , & V_76 , V_38 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_39 ( & V_7 -> V_94 ) ;
V_7 -> V_95 = V_96 ;
if ( ! ( V_7 -> V_23 & V_97 ) ) {
V_7 -> V_98 = V_96 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_40 ( V_38 ) -> V_99 , V_46 ) ;
V_9 -> V_20 &= ~ ( V_105 | V_104 ) ;
V_9 -> V_35 = F_41 ( V_91 -> V_35 ) ;
V_9 -> V_100 = 0 ;
}
F_45 ( & V_7 -> V_94 ) ;
F_43 ( V_7 ) ;
}
F_13 ( V_38 ) ;
return 0 ;
}
static char * F_47 ( char * V_110 , int V_111 , int V_100 )
{
int V_112 ;
unsigned char * V_113 = NULL ;
V_110 += 6 ;
for( V_112 = 0 ; V_112 < V_111 ; V_112 ++ ) {
if ( ! V_113 || ( * V_110 < * V_113 ) )
V_113 = V_110 ;
V_110 += 7 ;
}
if ( ! V_113 )
return NULL ;
return ( * V_113 < V_100 ) ? ( V_113 - 6 ) : NULL ;
}
static void F_48 ( struct V_6 * V_7 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_116 -> V_3 )
return;
V_9 = (struct V_8 * ) V_7 ;
if ( ! ( V_9 -> V_20 & ( V_105 | V_104 ) ) )
return;
if ( V_116 -> V_117 == V_116 -> V_44 )
V_116 -> V_118 = F_47 ( V_116 -> V_119 , V_116 -> V_44 , V_9 -> V_100 ) ;
else
V_116 -> V_117 ++ ;
if ( V_116 -> V_118 == NULL )
return;
F_9 ( V_116 -> V_118 , V_9 -> V_34 ) ;
V_116 -> V_118 += 6 ;
* ( V_116 -> V_118 ) = V_7 -> V_23 & V_120 ? 0x80 : 0x0 ;
* ( V_116 -> V_118 ) |= V_9 -> V_100 ;
V_116 -> V_118 ++ ;
}
int F_49 ( struct V_2 * V_3 , unsigned char * V_119 , int V_44 )
{
struct V_115 V_121 ;
V_121 . V_3 = V_3 ;
V_121 . V_117 = 0 ;
V_121 . V_44 = V_44 ;
V_121 . V_119 = V_119 ;
V_121 . V_118 = V_119 ;
F_50 ( & V_93 , F_48 , & V_121 ) ;
return V_121 . V_117 ;
}
static inline void F_51 ( struct V_122 * V_47 ,
struct V_6 * V_44 )
{
struct V_8 * V_9 = (struct V_8 * ) V_44 ;
char V_123 [ V_124 ] ;
F_52 ( & V_44 -> V_94 ) ;
F_53 ( V_47 , L_10 ,
F_54 ( F_41 ( V_9 -> V_34 ) , V_123 ) ,
( V_9 -> V_20 & V_105 ) ? L_11 : L_12 ,
( V_9 -> V_20 & V_104 ) ? L_13 : L_12 ,
( V_9 -> V_20 & V_21 ) ? L_14 : L_12 ,
V_9 -> V_44 . V_23 ,
F_55 ( & V_9 -> V_44 . V_125 ) ,
V_9 -> V_35 ,
( V_9 -> V_44 . V_3 ) ? V_9 -> V_44 . V_3 -> V_126 : L_15 ) ;
F_56 ( & V_44 -> V_94 ) ;
}
static int F_57 ( struct V_122 * V_47 , void * V_127 )
{
if ( V_127 == V_128 ) {
F_58 ( V_47 , L_16 ) ;
} else {
F_51 ( V_47 , V_127 ) ;
}
return 0 ;
}
static void * F_59 ( struct V_122 * V_47 , T_3 * V_129 )
{
return F_60 ( V_47 , V_129 , & V_93 ,
V_130 ) ;
}
static int F_61 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
return F_62 ( V_131 , V_132 , & V_133 ,
sizeof( struct V_134 ) ) ;
}
void T_4 F_63 ( void )
{
F_64 ( & V_93 ) ;
F_65 ( L_17 , V_135 , V_136 . V_137 ,
& V_138 ) ;
}
void T_5 F_66 ( void )
{
F_67 ( L_17 , V_136 . V_137 ) ;
F_68 ( & V_93 ) ;
}
