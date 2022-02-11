static T_1 F_1 ( const void * V_1 ,
const struct V_2 * V_3 ,
T_2 * V_4 )
{
return F_2 ( * ( V_5 * ) V_1 , 0 , V_4 [ 0 ] ) ;
}
static bool F_3 ( const struct V_6 * V_7 , const void * V_1 )
{
return F_4 ( V_7 , V_1 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_8 * V_9 = F_6 ( V_7 , struct V_8 , V_10 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_7 () ;
V_12 = F_8 ( V_3 -> V_15 ) ;
if ( V_12 == NULL ) {
F_9 () ;
return - V_16 ;
}
V_14 = V_12 -> V_13 ;
if ( ! V_14 ) {
F_9 () ;
return - V_16 ;
}
F_10 ( V_7 -> V_14 ) ;
V_7 -> V_14 = F_11 ( V_14 ) ;
F_9 () ;
V_7 -> V_17 = & V_18 ;
V_7 -> V_19 = V_20 ;
V_7 -> V_21 = V_7 -> V_17 -> V_22 ;
if ( ( V_3 -> type == V_23 ) || ( V_3 -> V_24 & V_25 ) )
memcpy ( V_7 -> V_26 , V_3 -> V_27 , V_3 -> V_28 ) ;
else if ( ( V_3 -> type == V_29 ) || ( V_3 -> type == V_30 ) )
F_12 ( V_7 -> V_26 , V_9 -> V_31 ) ;
else {
F_13 ( L_1 ,
V_3 -> type ) ;
return - V_16 ;
}
V_9 -> V_32 = V_3 -> V_33 - 2 ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
F_15 ( V_36 L_2 ) ;
F_16 ( V_35 ) ;
}
static int F_17 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
struct V_37 * V_38 = F_18 ( V_35 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_38 ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_41 [ V_42 ] ;
unsigned int V_43 ;
int V_44 ;
F_12 ( V_41 , V_40 -> V_45 ) ;
do {
V_43 = F_19 ( & V_7 -> V_46 ) ;
V_44 = F_20 ( V_35 , V_3 , F_21 ( V_35 -> V_47 ) ,
V_7 -> V_26 , V_41 , V_35 -> V_48 ) ;
} while ( F_22 ( & V_7 -> V_46 , V_43 ) );
if ( V_44 >= 0 )
V_44 = F_23 ( V_35 ) ;
else {
F_16 ( V_35 ) ;
V_44 = - V_16 ;
}
return V_44 ;
}
static int F_24 ( struct V_49 * V_49 , struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_37 * V_38 = F_18 ( V_35 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_38 ;
struct V_6 * V_7 = V_40 -> V_10 ;
return V_7 -> V_21 ( V_7 , V_35 ) ;
}
static int F_25 ( struct V_6 * V_7 , struct V_50 * V_51 ,
struct V_34 * V_35 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_54 ) + 3 ;
unsigned char * V_55 ;
struct V_54 * V_56 ;
struct V_57 * V_58 = F_26 ( V_35 ) ;
if ( F_27 ( V_35 ) < V_52 ) {
struct V_34 * V_59 = F_28 ( V_35 , V_52 ) ;
if ( V_59 == NULL ) {
F_29 ( L_3 ) ;
F_16 ( V_35 ) ;
return - V_60 ;
}
F_30 ( V_35 ) ;
V_35 = V_59 ;
F_31 ( L_4 ) ;
}
V_55 = F_32 ( V_35 , sizeof( struct V_54 ) + 3 ) ;
V_56 = (struct V_54 * ) ( V_55 + 3 ) ;
* ( ( V_61 * ) V_55 ) = F_33 ( V_35 -> V_48 - 2 ) ;
* ( V_55 + 2 ) = 1 | V_62 ;
V_56 -> V_63 = V_64 | ( V_58 -> V_65 & ( V_66 | V_67 | V_68 ) ) ;
V_56 -> V_69 = V_56 -> V_70 = 0 ;
F_12 ( V_56 -> V_71 , V_58 -> V_38 ) ;
V_56 -> V_72 = V_56 -> V_73 = 0 ;
F_12 ( V_56 -> V_74 , V_58 -> V_75 ) ;
V_56 -> V_76 = 0 ;
V_56 -> V_77 = V_58 -> V_78 & 0x3f ;
V_56 -> V_79 = 0 ;
V_56 -> V_80 = 0 ;
F_34 ( V_35 ) ;
return F_35 ( V_81 , V_82 ,
& V_83 , V_51 , V_35 , NULL , V_7 -> V_3 ,
F_24 ) ;
}
static int F_36 ( struct V_6 * V_7 , struct V_50 * V_51 ,
struct V_34 * V_35 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_84 ) + 2 ;
struct V_84 * V_85 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_26 ( V_35 ) ;
if ( F_27 ( V_35 ) < V_52 ) {
struct V_34 * V_59 = F_28 ( V_35 , V_52 ) ;
if ( V_59 == NULL ) {
F_29 ( L_5 ) ;
F_16 ( V_35 ) ;
return - V_60 ;
}
F_30 ( V_35 ) ;
V_35 = V_59 ;
F_31 ( L_6 ) ;
}
V_55 = F_32 ( V_35 , sizeof( struct V_84 ) + 2 ) ;
* ( ( V_61 * ) V_55 ) = F_33 ( V_35 -> V_48 - 2 ) ;
V_85 = (struct V_84 * ) ( V_55 + 2 ) ;
V_85 -> V_63 = V_86 | ( V_58 -> V_65 & ( V_67 | V_68 ) ) ;
V_85 -> V_87 = V_58 -> V_38 ;
V_85 -> V_88 = V_58 -> V_75 ;
V_85 -> V_89 = V_58 -> V_78 & 0x3f ;
F_34 ( V_35 ) ;
return F_35 ( V_81 , V_82 ,
& V_83 , V_51 , V_35 , NULL , V_7 -> V_3 ,
F_24 ) ;
}
static int F_37 ( struct V_6 * V_7 , struct V_50 * V_51 ,
struct V_34 * V_35 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_84 ) + 2 ;
struct V_84 * V_85 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_26 ( V_35 ) ;
if ( F_27 ( V_35 ) < V_52 ) {
struct V_34 * V_59 = F_28 ( V_35 , V_52 ) ;
if ( V_59 == NULL ) {
F_29 ( L_7 ) ;
F_16 ( V_35 ) ;
return - V_60 ;
}
F_30 ( V_35 ) ;
V_35 = V_59 ;
F_31 ( L_8 ) ;
}
V_55 = F_32 ( V_35 , sizeof( struct V_84 ) + 2 ) ;
* ( ( V_61 * ) V_55 ) = F_33 ( V_35 -> V_48 - 2 ) ;
V_85 = (struct V_84 * ) ( V_55 + 2 ) ;
V_85 -> V_63 = V_86 | ( V_58 -> V_65 & ( V_67 | V_68 ) ) ;
V_85 -> V_87 = V_58 -> V_38 & F_33 ( 0x03ff ) ;
V_85 -> V_88 = V_58 -> V_75 & F_33 ( 0x03ff ) ;
V_85 -> V_89 = V_58 -> V_78 & 0x3f ;
F_34 ( V_35 ) ;
return F_35 ( V_81 , V_82 ,
& V_83 , V_51 , V_35 , NULL , V_7 -> V_3 ,
F_24 ) ;
}
int F_38 ( struct V_49 * V_49 , struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_37 * V_38 = F_18 ( V_35 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_38 ;
struct V_6 * V_7 = V_40 -> V_10 ;
struct V_8 * V_9 = F_6 ( V_7 , struct V_8 , V_10 ) ;
struct V_11 * V_12 ;
bool V_90 ;
F_7 () ;
V_12 = F_8 ( V_7 -> V_3 -> V_15 ) ;
if ( V_12 == NULL ) {
F_9 () ;
return - V_16 ;
}
V_90 = V_12 -> V_90 ;
F_9 () ;
if ( V_9 -> V_24 & V_91 )
return F_37 ( V_7 , V_51 , V_35 ) ;
if ( V_90 )
return F_25 ( V_7 , V_51 , V_35 ) ;
else
return F_36 ( V_7 , V_51 , V_35 ) ;
}
void F_39 ( struct V_34 * V_35 )
{
F_16 ( V_35 ) ;
}
int F_40 ( struct V_49 * V_49 , struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_92 * V_93 = (struct V_92 * ) V_35 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_11 * V_12 ;
V_61 V_75 ;
V_75 = F_41 ( V_93 -> V_94 ) ;
V_7 = F_42 ( & V_95 , & V_75 , V_35 -> V_3 , 1 ) ;
V_9 = F_6 ( V_7 , struct V_8 , V_10 ) ;
if ( V_7 ) {
F_43 ( & V_7 -> V_96 ) ;
V_7 -> V_97 = V_98 ;
V_12 = F_8 ( V_7 -> V_3 -> V_15 ) ;
if ( ! ( V_7 -> V_19 & V_99 ) ) {
V_7 -> V_100 = V_98 ;
if ( V_7 -> V_3 -> type == V_29 )
memcpy ( V_7 -> V_26 , & F_44 ( V_35 ) -> V_101 , V_42 ) ;
V_9 -> V_32 = F_45 ( V_93 -> V_32 ) ;
V_9 -> V_102 = V_93 -> V_102 ;
V_9 -> V_24 &= ~ V_91 ;
switch ( V_93 -> V_103 & V_104 ) {
case V_105 :
V_9 -> V_24 &= ~ V_106 ;
V_9 -> V_24 |= V_107 ;
break;
case V_108 :
V_9 -> V_24 |= V_106 ;
}
}
if ( ( F_45 ( V_75 ) >> 10 ) == ( F_45 ( ( V_109 ) ) >> 10 ) ) {
if ( ! V_12 -> V_110 ) {
V_12 -> V_110 = F_46 ( V_7 ) ;
} else {
if ( V_93 -> V_102 > ( (struct V_8 * ) V_12 -> V_110 ) -> V_102 )
F_47 ( F_48 ( & V_12 -> V_110 , F_46 ( V_7 ) ) ) ;
}
}
F_49 ( & V_7 -> V_96 ) ;
F_47 ( V_7 ) ;
}
F_16 ( V_35 ) ;
return 0 ;
}
int F_50 ( struct V_49 * V_49 , struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_111 * V_93 = (struct V_111 * ) V_35 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_61 V_75 ;
V_75 = F_41 ( V_93 -> V_94 ) ;
V_7 = F_42 ( & V_95 , & V_75 , V_35 -> V_3 , 1 ) ;
V_9 = F_6 ( V_7 , struct V_8 , V_10 ) ;
if ( V_7 ) {
F_43 ( & V_7 -> V_96 ) ;
V_7 -> V_97 = V_98 ;
if ( ! ( V_7 -> V_19 & V_99 ) ) {
V_7 -> V_100 = V_98 ;
if ( V_7 -> V_3 -> type == V_29 )
memcpy ( V_7 -> V_26 , & F_44 ( V_35 ) -> V_101 , V_42 ) ;
V_9 -> V_24 &= ~ ( V_107 | V_106 ) ;
V_9 -> V_32 = F_45 ( V_93 -> V_32 ) ;
V_9 -> V_102 = 0 ;
}
F_49 ( & V_7 -> V_96 ) ;
F_47 ( V_7 ) ;
}
F_16 ( V_35 ) ;
return 0 ;
}
static char * F_51 ( char * V_112 , int V_113 , int V_102 )
{
int V_114 ;
unsigned char * V_115 = NULL ;
V_112 += 6 ;
for( V_114 = 0 ; V_114 < V_113 ; V_114 ++ ) {
if ( ! V_115 || ( * V_112 < * V_115 ) )
V_115 = V_112 ;
V_112 += 7 ;
}
if ( ! V_115 )
return NULL ;
return ( * V_115 < V_102 ) ? ( V_115 - 6 ) : NULL ;
}
static void F_52 ( struct V_6 * V_7 , void * V_116 )
{
struct V_117 * V_118 = V_116 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_118 -> V_3 )
return;
V_9 = F_6 ( V_7 , struct V_8 , V_10 ) ;
if ( ! ( V_9 -> V_24 & ( V_107 | V_106 ) ) )
return;
if ( V_118 -> V_119 == V_118 -> V_10 )
V_118 -> V_120 = F_51 ( V_118 -> V_121 , V_118 -> V_10 , V_9 -> V_102 ) ;
else
V_118 -> V_119 ++ ;
if ( V_118 -> V_120 == NULL )
return;
F_12 ( V_118 -> V_120 , V_9 -> V_31 ) ;
V_118 -> V_120 += 6 ;
* ( V_118 -> V_120 ) = V_7 -> V_19 & V_122 ? 0x80 : 0x0 ;
* ( V_118 -> V_120 ) |= V_9 -> V_102 ;
V_118 -> V_120 ++ ;
}
int F_53 ( struct V_2 * V_3 , unsigned char * V_121 , int V_10 )
{
struct V_117 V_123 ;
V_123 . V_3 = V_3 ;
V_123 . V_119 = 0 ;
V_123 . V_10 = V_10 ;
V_123 . V_121 = V_121 ;
V_123 . V_120 = V_121 ;
F_54 ( & V_95 , F_52 , & V_123 ) ;
return V_123 . V_119 ;
}
static inline void F_55 ( struct V_124 * V_43 ,
struct V_6 * V_10 )
{
struct V_8 * V_9 = F_6 ( V_10 , struct V_8 , V_10 ) ;
char V_125 [ V_126 ] ;
F_56 ( & V_10 -> V_96 ) ;
F_57 ( V_43 , L_9 ,
F_58 ( F_45 ( V_9 -> V_31 ) , V_125 ) ,
( V_9 -> V_24 & V_107 ) ? L_10 : L_11 ,
( V_9 -> V_24 & V_106 ) ? L_12 : L_11 ,
( V_9 -> V_24 & V_91 ) ? L_13 : L_11 ,
V_9 -> V_10 . V_19 ,
F_59 ( & V_9 -> V_10 . V_127 ) ,
V_9 -> V_32 ,
( V_9 -> V_10 . V_3 ) ? V_9 -> V_10 . V_3 -> V_128 : L_14 ) ;
F_60 ( & V_10 -> V_96 ) ;
}
static int F_61 ( struct V_124 * V_43 , void * V_129 )
{
if ( V_129 == V_130 ) {
F_62 ( V_43 , L_15 ) ;
} else {
F_55 ( V_43 , V_129 ) ;
}
return 0 ;
}
static void * F_63 ( struct V_124 * V_43 , T_3 * V_131 )
{
return F_64 ( V_43 , V_131 , & V_95 ,
V_132 ) ;
}
static int F_65 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_66 ( V_133 , V_134 , & V_135 ,
sizeof( struct V_136 ) ) ;
}
void T_4 F_67 ( void )
{
F_68 ( V_137 , & V_95 ) ;
F_69 ( L_16 , V_138 , V_83 . V_139 ,
& V_140 ) ;
}
void T_5 F_70 ( void )
{
F_71 ( L_16 , V_83 . V_139 ) ;
F_72 ( V_137 , & V_95 ) ;
}
