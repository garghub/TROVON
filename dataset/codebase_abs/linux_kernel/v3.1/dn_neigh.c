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
struct V_6 * V_7 = F_17 ( V_41 ) ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_44 [ V_45 ] ;
F_9 ( V_44 , V_43 -> V_46 ) ;
if ( F_18 ( V_39 , V_3 , F_19 ( V_39 -> V_47 ) , V_7 -> V_29 ,
V_44 , V_39 -> V_48 ) >= 0 )
return F_20 ( V_39 ) ;
if ( F_10 () )
F_11 ( V_35 L_4 ) ;
F_13 ( V_39 ) ;
return - V_15 ;
}
static int F_21 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_49 = V_3 -> V_50 + sizeof( struct V_51 ) + 3 ;
unsigned char * V_52 ;
struct V_51 * V_53 ;
struct V_54 * V_55 = F_22 ( V_39 ) ;
if ( F_23 ( V_39 ) < V_49 ) {
struct V_38 * V_56 = F_24 ( V_39 , V_49 ) ;
if ( V_56 == NULL ) {
if ( F_10 () )
F_11 ( V_57 L_5 ) ;
F_13 ( V_39 ) ;
return - V_58 ;
}
F_13 ( V_39 ) ;
V_39 = V_56 ;
if ( F_10 () )
F_11 ( V_59 L_6 ) ;
}
V_52 = F_25 ( V_39 , sizeof( struct V_51 ) + 3 ) ;
V_53 = (struct V_51 * ) ( V_52 + 3 ) ;
* ( ( V_60 * ) V_52 ) = F_26 ( V_39 -> V_48 - 2 ) ;
* ( V_52 + 2 ) = 1 | V_61 ;
V_53 -> V_62 = V_63 | ( V_55 -> V_64 & ( V_65 | V_66 | V_67 ) ) ;
V_53 -> V_68 = V_53 -> V_69 = 0 ;
F_9 ( V_53 -> V_70 , V_55 -> V_41 ) ;
V_53 -> V_71 = V_53 -> V_72 = 0 ;
F_9 ( V_53 -> V_73 , V_55 -> V_74 ) ;
V_53 -> V_75 = 0 ;
V_53 -> V_76 = V_55 -> V_77 & 0x3f ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = 0 ;
F_27 ( V_39 ) ;
return F_28 ( V_80 , V_81 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_29 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_49 = V_3 -> V_50 + sizeof( struct V_82 ) + 2 ;
struct V_82 * V_83 ;
unsigned char * V_52 ;
struct V_54 * V_55 = F_22 ( V_39 ) ;
if ( F_23 ( V_39 ) < V_49 ) {
struct V_38 * V_56 = F_24 ( V_39 , V_49 ) ;
if ( V_56 == NULL ) {
if ( F_10 () )
F_11 ( V_57 L_7 ) ;
F_13 ( V_39 ) ;
return - V_58 ;
}
F_13 ( V_39 ) ;
V_39 = V_56 ;
if ( F_10 () )
F_11 ( V_59 L_8 ) ;
}
V_52 = F_25 ( V_39 , sizeof( struct V_82 ) + 2 ) ;
* ( ( V_60 * ) V_52 ) = F_26 ( V_39 -> V_48 - 2 ) ;
V_83 = (struct V_82 * ) ( V_52 + 2 ) ;
V_83 -> V_62 = V_84 | ( V_55 -> V_64 & ( V_66 | V_67 ) ) ;
V_83 -> V_85 = V_55 -> V_41 ;
V_83 -> V_86 = V_55 -> V_74 ;
V_83 -> V_87 = V_55 -> V_77 & 0x3f ;
F_27 ( V_39 ) ;
return F_28 ( V_80 , V_81 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
static int F_30 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_49 = V_3 -> V_50 + sizeof( struct V_82 ) + 2 ;
struct V_82 * V_83 ;
unsigned char * V_52 ;
struct V_54 * V_55 = F_22 ( V_39 ) ;
if ( F_23 ( V_39 ) < V_49 ) {
struct V_38 * V_56 = F_24 ( V_39 , V_49 ) ;
if ( V_56 == NULL ) {
if ( F_10 () )
F_11 ( V_57 L_9 ) ;
F_13 ( V_39 ) ;
return - V_58 ;
}
F_13 ( V_39 ) ;
V_39 = V_56 ;
if ( F_10 () )
F_11 ( V_59 L_10 ) ;
}
V_52 = F_25 ( V_39 , sizeof( struct V_82 ) + 2 ) ;
* ( ( V_60 * ) V_52 ) = F_26 ( V_39 -> V_48 - 2 ) ;
V_83 = (struct V_82 * ) ( V_52 + 2 ) ;
V_83 -> V_62 = V_84 | ( V_55 -> V_64 & ( V_66 | V_67 ) ) ;
V_83 -> V_85 = V_55 -> V_41 & F_26 ( 0x03ff ) ;
V_83 -> V_86 = V_55 -> V_74 & F_26 ( 0x03ff ) ;
V_83 -> V_87 = V_55 -> V_77 & 0x3f ;
F_27 ( V_39 ) ;
return F_28 ( V_80 , V_81 , V_39 , NULL ,
V_7 -> V_3 , F_15 ) ;
}
void F_31 ( struct V_38 * V_39 )
{
F_13 ( V_39 ) ;
}
int F_32 ( struct V_38 * V_39 )
{
struct V_88 * V_89 = (struct V_88 * ) V_39 -> V_52 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_60 V_74 ;
V_74 = F_33 ( V_89 -> V_90 ) ;
V_7 = F_34 ( & V_91 , & V_74 , V_39 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_35 ( & V_7 -> V_92 ) ;
V_7 -> V_93 = V_94 ;
V_11 = F_5 ( V_7 -> V_3 -> V_14 ) ;
if ( ! ( V_7 -> V_23 & V_95 ) ) {
V_7 -> V_96 = V_94 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_36 ( V_39 ) -> V_97 , V_45 ) ;
V_9 -> V_36 = F_37 ( V_89 -> V_36 ) ;
V_9 -> V_98 = V_89 -> V_98 ;
V_9 -> V_20 &= ~ V_21 ;
switch ( V_89 -> V_99 & V_100 ) {
case V_101 :
V_9 -> V_20 &= ~ V_102 ;
V_9 -> V_20 |= V_103 ;
break;
case V_104 :
V_9 -> V_20 |= V_102 ;
}
}
if ( ( F_37 ( V_74 ) >> 10 ) == ( F_37 ( ( V_105 ) ) >> 10 ) ) {
if ( ! V_11 -> V_106 ) {
V_11 -> V_106 = F_38 ( V_7 ) ;
} else {
if ( V_89 -> V_98 > ( (struct V_8 * ) V_11 -> V_106 ) -> V_98 )
F_39 ( F_40 ( & V_11 -> V_106 , F_38 ( V_7 ) ) ) ;
}
}
F_41 ( & V_7 -> V_92 ) ;
F_39 ( V_7 ) ;
}
F_13 ( V_39 ) ;
return 0 ;
}
int F_42 ( struct V_38 * V_39 )
{
struct V_107 * V_89 = (struct V_107 * ) V_39 -> V_52 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_60 V_74 ;
V_74 = F_33 ( V_89 -> V_90 ) ;
V_7 = F_34 ( & V_91 , & V_74 , V_39 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_35 ( & V_7 -> V_92 ) ;
V_7 -> V_93 = V_94 ;
if ( ! ( V_7 -> V_23 & V_95 ) ) {
V_7 -> V_96 = V_94 ;
if ( V_7 -> V_3 -> type == V_32 )
memcpy ( V_7 -> V_29 , & F_36 ( V_39 ) -> V_97 , V_45 ) ;
V_9 -> V_20 &= ~ ( V_103 | V_102 ) ;
V_9 -> V_36 = F_37 ( V_89 -> V_36 ) ;
V_9 -> V_98 = 0 ;
}
F_41 ( & V_7 -> V_92 ) ;
F_39 ( V_7 ) ;
}
F_13 ( V_39 ) ;
return 0 ;
}
static char * F_43 ( char * V_108 , int V_109 , int V_98 )
{
int V_110 ;
unsigned char * V_111 = NULL ;
V_108 += 6 ;
for( V_110 = 0 ; V_110 < V_109 ; V_110 ++ ) {
if ( ! V_111 || ( * V_108 < * V_111 ) )
V_111 = V_108 ;
V_108 += 7 ;
}
if ( ! V_111 )
return NULL ;
return ( * V_111 < V_98 ) ? ( V_111 - 6 ) : NULL ;
}
static void F_44 ( struct V_6 * V_7 , void * V_112 )
{
struct V_113 * V_114 = V_112 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_114 -> V_3 )
return;
V_9 = (struct V_8 * ) V_7 ;
if ( ! ( V_9 -> V_20 & ( V_103 | V_102 ) ) )
return;
if ( V_114 -> V_115 == V_114 -> V_116 )
V_114 -> V_117 = F_43 ( V_114 -> V_118 , V_114 -> V_116 , V_9 -> V_98 ) ;
else
V_114 -> V_115 ++ ;
if ( V_114 -> V_117 == NULL )
return;
F_9 ( V_114 -> V_117 , V_9 -> V_34 ) ;
V_114 -> V_117 += 6 ;
* ( V_114 -> V_117 ) = V_7 -> V_23 & V_119 ? 0x80 : 0x0 ;
* ( V_114 -> V_117 ) |= V_9 -> V_98 ;
V_114 -> V_117 ++ ;
}
int F_45 ( struct V_2 * V_3 , unsigned char * V_118 , int V_116 )
{
struct V_113 V_120 ;
V_120 . V_3 = V_3 ;
V_120 . V_115 = 0 ;
V_120 . V_116 = V_116 ;
V_120 . V_118 = V_118 ;
V_120 . V_117 = V_118 ;
F_46 ( & V_91 , F_44 , & V_120 ) ;
return V_120 . V_115 ;
}
static inline void F_47 ( struct V_121 * V_122 ,
struct V_6 * V_116 )
{
struct V_8 * V_9 = (struct V_8 * ) V_116 ;
char V_123 [ V_124 ] ;
F_48 ( & V_116 -> V_92 ) ;
F_49 ( V_122 , L_11 ,
F_50 ( F_37 ( V_9 -> V_34 ) , V_123 ) ,
( V_9 -> V_20 & V_103 ) ? L_12 : L_13 ,
( V_9 -> V_20 & V_102 ) ? L_14 : L_13 ,
( V_9 -> V_20 & V_21 ) ? L_15 : L_13 ,
V_9 -> V_116 . V_23 ,
F_51 ( & V_9 -> V_116 . V_125 ) ,
V_9 -> V_36 ,
( V_9 -> V_116 . V_3 ) ? V_9 -> V_116 . V_3 -> V_126 : L_16 ) ;
F_52 ( & V_116 -> V_92 ) ;
}
static int F_53 ( struct V_121 * V_122 , void * V_127 )
{
if ( V_127 == V_128 ) {
F_54 ( V_122 , L_17 ) ;
} else {
F_47 ( V_122 , V_127 ) ;
}
return 0 ;
}
static void * F_55 ( struct V_121 * V_122 , T_3 * V_129 )
{
return F_56 ( V_122 , V_129 , & V_91 ,
V_130 ) ;
}
static int F_57 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
return F_58 ( V_131 , V_132 , & V_133 ,
sizeof( struct V_134 ) ) ;
}
void T_4 F_59 ( void )
{
F_60 ( & V_91 ) ;
F_61 ( & V_135 , L_18 , V_136 , & V_137 ) ;
}
void T_5 F_62 ( void )
{
F_63 ( & V_135 , L_18 ) ;
F_64 ( & V_91 ) ;
}
