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
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
F_6 () ;
V_11 = F_7 ( V_3 -> V_14 ) ;
if ( V_11 == NULL ) {
F_8 () ;
return - V_15 ;
}
V_13 = V_11 -> V_12 ;
if ( ! V_13 ) {
F_8 () ;
return - V_15 ;
}
F_9 ( V_7 -> V_13 ) ;
V_7 -> V_13 = F_10 ( V_13 ) ;
F_8 () ;
V_7 -> V_16 = & V_17 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_20 = V_7 -> V_16 -> V_21 ;
if ( ( V_3 -> type == V_22 ) || ( V_3 -> V_23 & V_24 ) )
memcpy ( V_7 -> V_25 , V_3 -> V_26 , V_3 -> V_27 ) ;
else if ( ( V_3 -> type == V_28 ) || ( V_3 -> type == V_29 ) )
F_11 ( V_7 -> V_25 , V_9 -> V_30 ) ;
else {
F_12 ( L_1 ,
V_3 -> type ) ;
return - V_15 ;
}
V_9 -> V_31 = V_3 -> V_32 - 2 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 , struct V_33 * V_34 )
{
F_14 ( V_35 L_2 ) ;
F_15 ( V_34 ) ;
}
static int F_16 ( struct V_6 * V_7 , struct V_33 * V_34 )
{
struct V_36 * V_37 = F_17 ( V_34 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_37 ;
struct V_2 * V_3 = V_7 -> V_3 ;
char V_40 [ V_41 ] ;
unsigned int V_42 ;
int V_43 ;
F_11 ( V_40 , V_39 -> V_44 ) ;
do {
V_42 = F_18 ( & V_7 -> V_45 ) ;
V_43 = F_19 ( V_34 , V_3 , F_20 ( V_34 -> V_46 ) ,
V_7 -> V_25 , V_40 , V_34 -> V_47 ) ;
} while ( F_21 ( & V_7 -> V_45 , V_42 ) );
if ( V_43 >= 0 )
V_43 = F_22 ( V_34 ) ;
else {
F_15 ( V_34 ) ;
V_43 = - V_15 ;
}
return V_43 ;
}
static int F_23 ( struct V_48 * V_48 , struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_36 * V_37 = F_17 ( V_34 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_37 ;
struct V_6 * V_7 = V_39 -> V_51 ;
return V_7 -> V_20 ( V_7 , V_34 ) ;
}
static int F_24 ( struct V_6 * V_7 , struct V_49 * V_50 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_54 ) + 3 ;
unsigned char * V_55 ;
struct V_54 * V_56 ;
struct V_57 * V_58 = F_25 ( V_34 ) ;
if ( F_26 ( V_34 ) < V_52 ) {
struct V_33 * V_59 = F_27 ( V_34 , V_52 ) ;
if ( V_59 == NULL ) {
F_28 ( L_3 ) ;
F_15 ( V_34 ) ;
return - V_60 ;
}
F_29 ( V_34 ) ;
V_34 = V_59 ;
F_30 ( L_4 ) ;
}
V_55 = F_31 ( V_34 , sizeof( struct V_54 ) + 3 ) ;
V_56 = (struct V_54 * ) ( V_55 + 3 ) ;
* ( ( V_61 * ) V_55 ) = F_32 ( V_34 -> V_47 - 2 ) ;
* ( V_55 + 2 ) = 1 | V_62 ;
V_56 -> V_63 = V_64 | ( V_58 -> V_65 & ( V_66 | V_67 | V_68 ) ) ;
V_56 -> V_69 = V_56 -> V_70 = 0 ;
F_11 ( V_56 -> V_71 , V_58 -> V_37 ) ;
V_56 -> V_72 = V_56 -> V_73 = 0 ;
F_11 ( V_56 -> V_74 , V_58 -> V_75 ) ;
V_56 -> V_76 = 0 ;
V_56 -> V_77 = V_58 -> V_78 & 0x3f ;
V_56 -> V_79 = 0 ;
V_56 -> V_80 = 0 ;
F_33 ( V_34 ) ;
return F_34 ( V_81 , V_82 ,
& V_83 , V_50 , V_34 , NULL , V_7 -> V_3 ,
F_23 ) ;
}
static int F_35 ( struct V_6 * V_7 , struct V_49 * V_50 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_84 ) + 2 ;
struct V_84 * V_85 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_25 ( V_34 ) ;
if ( F_26 ( V_34 ) < V_52 ) {
struct V_33 * V_59 = F_27 ( V_34 , V_52 ) ;
if ( V_59 == NULL ) {
F_28 ( L_5 ) ;
F_15 ( V_34 ) ;
return - V_60 ;
}
F_29 ( V_34 ) ;
V_34 = V_59 ;
F_30 ( L_6 ) ;
}
V_55 = F_31 ( V_34 , sizeof( struct V_84 ) + 2 ) ;
* ( ( V_61 * ) V_55 ) = F_32 ( V_34 -> V_47 - 2 ) ;
V_85 = (struct V_84 * ) ( V_55 + 2 ) ;
V_85 -> V_63 = V_86 | ( V_58 -> V_65 & ( V_67 | V_68 ) ) ;
V_85 -> V_87 = V_58 -> V_37 ;
V_85 -> V_88 = V_58 -> V_75 ;
V_85 -> V_89 = V_58 -> V_78 & 0x3f ;
F_33 ( V_34 ) ;
return F_34 ( V_81 , V_82 ,
& V_83 , V_50 , V_34 , NULL , V_7 -> V_3 ,
F_23 ) ;
}
static int F_36 ( struct V_6 * V_7 , struct V_49 * V_50 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
int V_52 = V_3 -> V_53 + sizeof( struct V_84 ) + 2 ;
struct V_84 * V_85 ;
unsigned char * V_55 ;
struct V_57 * V_58 = F_25 ( V_34 ) ;
if ( F_26 ( V_34 ) < V_52 ) {
struct V_33 * V_59 = F_27 ( V_34 , V_52 ) ;
if ( V_59 == NULL ) {
F_28 ( L_7 ) ;
F_15 ( V_34 ) ;
return - V_60 ;
}
F_29 ( V_34 ) ;
V_34 = V_59 ;
F_30 ( L_8 ) ;
}
V_55 = F_31 ( V_34 , sizeof( struct V_84 ) + 2 ) ;
* ( ( V_61 * ) V_55 ) = F_32 ( V_34 -> V_47 - 2 ) ;
V_85 = (struct V_84 * ) ( V_55 + 2 ) ;
V_85 -> V_63 = V_86 | ( V_58 -> V_65 & ( V_67 | V_68 ) ) ;
V_85 -> V_87 = V_58 -> V_37 & F_32 ( 0x03ff ) ;
V_85 -> V_88 = V_58 -> V_75 & F_32 ( 0x03ff ) ;
V_85 -> V_89 = V_58 -> V_78 & 0x3f ;
F_33 ( V_34 ) ;
return F_34 ( V_81 , V_82 ,
& V_83 , V_50 , V_34 , NULL , V_7 -> V_3 ,
F_23 ) ;
}
int F_37 ( struct V_48 * V_48 , struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_36 * V_37 = F_17 ( V_34 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_37 ;
struct V_6 * V_7 = V_39 -> V_51 ;
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
struct V_10 * V_11 ;
bool V_90 ;
F_6 () ;
V_11 = F_7 ( V_7 -> V_3 -> V_14 ) ;
if ( V_11 == NULL ) {
F_8 () ;
return - V_15 ;
}
V_90 = V_11 -> V_90 ;
F_8 () ;
if ( V_9 -> V_23 & V_91 )
return F_36 ( V_7 , V_50 , V_34 ) ;
if ( V_90 )
return F_24 ( V_7 , V_50 , V_34 ) ;
else
return F_35 ( V_7 , V_50 , V_34 ) ;
}
void F_38 ( struct V_33 * V_34 )
{
F_15 ( V_34 ) ;
}
int F_39 ( struct V_48 * V_48 , struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_92 * V_93 = (struct V_92 * ) V_34 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_61 V_75 ;
V_75 = F_40 ( V_93 -> V_94 ) ;
V_7 = F_41 ( & V_95 , & V_75 , V_34 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_42 ( & V_7 -> V_96 ) ;
V_7 -> V_97 = V_98 ;
V_11 = F_7 ( V_7 -> V_3 -> V_14 ) ;
if ( ! ( V_7 -> V_18 & V_99 ) ) {
V_7 -> V_100 = V_98 ;
if ( V_7 -> V_3 -> type == V_28 )
memcpy ( V_7 -> V_25 , & F_43 ( V_34 ) -> V_101 , V_41 ) ;
V_9 -> V_31 = F_44 ( V_93 -> V_31 ) ;
V_9 -> V_102 = V_93 -> V_102 ;
V_9 -> V_23 &= ~ V_91 ;
switch ( V_93 -> V_103 & V_104 ) {
case V_105 :
V_9 -> V_23 &= ~ V_106 ;
V_9 -> V_23 |= V_107 ;
break;
case V_108 :
V_9 -> V_23 |= V_106 ;
}
}
if ( ( F_44 ( V_75 ) >> 10 ) == ( F_44 ( ( V_109 ) ) >> 10 ) ) {
if ( ! V_11 -> V_110 ) {
V_11 -> V_110 = F_45 ( V_7 ) ;
} else {
if ( V_93 -> V_102 > ( (struct V_8 * ) V_11 -> V_110 ) -> V_102 )
F_46 ( F_47 ( & V_11 -> V_110 , F_45 ( V_7 ) ) ) ;
}
}
F_48 ( & V_7 -> V_96 ) ;
F_46 ( V_7 ) ;
}
F_15 ( V_34 ) ;
return 0 ;
}
int F_49 ( struct V_48 * V_48 , struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_111 * V_93 = (struct V_111 * ) V_34 -> V_55 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_61 V_75 ;
V_75 = F_40 ( V_93 -> V_94 ) ;
V_7 = F_41 ( & V_95 , & V_75 , V_34 -> V_3 , 1 ) ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_7 ) {
F_42 ( & V_7 -> V_96 ) ;
V_7 -> V_97 = V_98 ;
if ( ! ( V_7 -> V_18 & V_99 ) ) {
V_7 -> V_100 = V_98 ;
if ( V_7 -> V_3 -> type == V_28 )
memcpy ( V_7 -> V_25 , & F_43 ( V_34 ) -> V_101 , V_41 ) ;
V_9 -> V_23 &= ~ ( V_107 | V_106 ) ;
V_9 -> V_31 = F_44 ( V_93 -> V_31 ) ;
V_9 -> V_102 = 0 ;
}
F_48 ( & V_7 -> V_96 ) ;
F_46 ( V_7 ) ;
}
F_15 ( V_34 ) ;
return 0 ;
}
static char * F_50 ( char * V_112 , int V_113 , int V_102 )
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
static void F_51 ( struct V_6 * V_7 , void * V_116 )
{
struct V_117 * V_118 = V_116 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 != V_118 -> V_3 )
return;
V_9 = (struct V_8 * ) V_7 ;
if ( ! ( V_9 -> V_23 & ( V_107 | V_106 ) ) )
return;
if ( V_118 -> V_119 == V_118 -> V_51 )
V_118 -> V_120 = F_50 ( V_118 -> V_121 , V_118 -> V_51 , V_9 -> V_102 ) ;
else
V_118 -> V_119 ++ ;
if ( V_118 -> V_120 == NULL )
return;
F_11 ( V_118 -> V_120 , V_9 -> V_30 ) ;
V_118 -> V_120 += 6 ;
* ( V_118 -> V_120 ) = V_7 -> V_18 & V_122 ? 0x80 : 0x0 ;
* ( V_118 -> V_120 ) |= V_9 -> V_102 ;
V_118 -> V_120 ++ ;
}
int F_52 ( struct V_2 * V_3 , unsigned char * V_121 , int V_51 )
{
struct V_117 V_123 ;
V_123 . V_3 = V_3 ;
V_123 . V_119 = 0 ;
V_123 . V_51 = V_51 ;
V_123 . V_121 = V_121 ;
V_123 . V_120 = V_121 ;
F_53 ( & V_95 , F_51 , & V_123 ) ;
return V_123 . V_119 ;
}
static inline void F_54 ( struct V_124 * V_42 ,
struct V_6 * V_51 )
{
struct V_8 * V_9 = (struct V_8 * ) V_51 ;
char V_125 [ V_126 ] ;
F_55 ( & V_51 -> V_96 ) ;
F_56 ( V_42 , L_9 ,
F_57 ( F_44 ( V_9 -> V_30 ) , V_125 ) ,
( V_9 -> V_23 & V_107 ) ? L_10 : L_11 ,
( V_9 -> V_23 & V_106 ) ? L_12 : L_11 ,
( V_9 -> V_23 & V_91 ) ? L_13 : L_11 ,
V_9 -> V_51 . V_18 ,
F_58 ( & V_9 -> V_51 . V_127 ) ,
V_9 -> V_31 ,
( V_9 -> V_51 . V_3 ) ? V_9 -> V_51 . V_3 -> V_128 : L_14 ) ;
F_59 ( & V_51 -> V_96 ) ;
}
static int F_60 ( struct V_124 * V_42 , void * V_129 )
{
if ( V_129 == V_130 ) {
F_61 ( V_42 , L_15 ) ;
} else {
F_54 ( V_42 , V_129 ) ;
}
return 0 ;
}
static void * F_62 ( struct V_124 * V_42 , T_3 * V_131 )
{
return F_63 ( V_42 , V_131 , & V_95 ,
V_132 ) ;
}
static int F_64 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_65 ( V_133 , V_134 , & V_135 ,
sizeof( struct V_136 ) ) ;
}
void T_4 F_66 ( void )
{
F_67 ( V_137 , & V_95 ) ;
F_68 ( L_16 , V_138 , V_83 . V_139 ,
& V_140 ) ;
}
void T_5 F_69 ( void )
{
F_70 ( L_16 , V_83 . V_139 ) ;
F_71 ( V_137 , & V_95 ) ;
}
