static inline unsigned int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 >> 13 ;
}
static inline void F_2 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_3 ( 1 , & V_2 -> V_6 ) == 1 )
F_4 ( & V_5 -> V_7 ) ;
}
static inline unsigned int F_5 ( const T_1 * V_8 , int V_9 )
{
return F_6 ( * V_8 , V_9 , 0 ) & V_10 ;
}
static inline unsigned int F_7 ( const T_1 * V_8 , int V_9 )
{
T_1 V_11 = V_8 [ 0 ] ^ V_8 [ 1 ] ^ V_8 [ 2 ] ^ V_8 [ 3 ] ;
return V_12 + ( F_6 ( V_11 , V_9 , 0 ) & V_10 ) ;
}
static unsigned int F_8 ( const T_1 * V_13 , int V_14 , int V_9 )
{
return V_14 == 4 ? F_5 ( V_13 , V_9 ) :
F_7 ( V_13 , V_9 ) ;
}
static int F_9 ( const struct V_1 * V_2 , const T_1 * V_13 )
{
if ( V_2 -> V_15 )
return ( V_2 -> V_13 [ 0 ] ^ V_13 [ 0 ] ) | ( V_2 -> V_13 [ 1 ] ^ V_13 [ 1 ] ) |
( V_2 -> V_13 [ 2 ] ^ V_13 [ 2 ] ) | ( V_2 -> V_13 [ 3 ] ^ V_13 [ 3 ] ) ;
return V_2 -> V_13 [ 0 ] ^ V_13 [ 0 ] ;
}
static void F_10 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
F_11 ( V_17 ) ;
if ( V_2 -> V_18 )
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_18 = V_17 ;
}
static int F_13 ( struct V_19 * V_20 , struct V_1 * V_2 , int V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_14 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_23 )
return - V_27 ;
V_25 = (struct V_24 * ) F_15 ( V_23 , sizeof( * V_25 ) ) ;
F_16 ( V_25 , 0 ) ;
F_17 ( V_25 ) = F_18 ( F_19 ( V_28 ,
V_2 -> V_29 | ( V_21 ? V_30 : 0 ) |
F_20 ( V_20 -> V_31 . V_32 . V_33 ) ) ) ;
V_25 -> V_34 = F_21 ( F_22 ( V_2 -> V_35 ) | F_23 ( ! V_21 ) ) ;
V_25 -> V_36 = F_21 ( V_2 -> V_29 ) ;
V_25 -> V_3 = F_21 ( V_2 -> V_3 ) ;
if ( V_2 -> V_18 && ! ( V_2 -> V_18 -> V_37 -> V_38 & V_39 ) )
memcpy ( V_2 -> V_40 , V_2 -> V_18 -> V_41 , sizeof( V_2 -> V_40 ) ) ;
memcpy ( V_25 -> V_42 , V_2 -> V_40 , sizeof( V_25 -> V_42 ) ) ;
F_24 ( V_23 , V_43 , 0 ) ;
F_25 ( V_20 , V_23 ) ;
if ( V_21 && V_2 -> V_44 != V_45 )
V_2 -> V_44 = V_46 ;
return 0 ;
}
static void F_26 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
while ( V_2 -> V_47 ) {
struct V_22 * V_23 = V_2 -> V_47 ;
V_2 -> V_47 = V_23 -> V_48 ;
V_23 -> V_48 = NULL ;
F_25 ( V_20 , V_23 ) ;
}
V_2 -> V_49 = NULL ;
}
void F_27 ( struct V_19 * V_20 , const struct V_50 * V_51 )
{
unsigned int V_52 = F_28 ( V_51 ) ;
unsigned int V_29 = V_52 & ( V_53 - 1 ) ;
if ( F_29 ( V_51 -> V_54 != V_55 ) ) {
F_30 ( V_20 -> V_56 ,
L_1 ,
V_51 -> V_54 , V_29 ) ;
return;
}
if ( V_52 & V_30 ) {
struct V_1 * V_2 = & V_20 -> V_57 -> V_58 [ V_29 ] ;
F_31 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_44 != V_45 ) {
F_26 ( V_20 , V_2 ) ;
V_2 -> V_44 = ( V_2 -> V_18 -> V_60 & V_61 ) ?
V_62 : V_63 ;
}
F_32 ( & V_2 -> V_59 ) ;
}
}
static inline void F_33 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
V_23 -> V_48 = NULL ;
if ( V_2 -> V_47 )
V_2 -> V_49 -> V_48 = V_23 ;
else
V_2 -> V_47 = V_23 ;
V_2 -> V_49 = V_23 ;
}
int F_34 ( struct V_64 * V_37 , struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_35 ( V_37 ) ;
V_65:
switch ( V_2 -> V_44 ) {
case V_62 :
F_36 ( V_2 -> V_18 , NULL ) ;
F_37 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_44 == V_62 )
V_2 -> V_44 = V_63 ;
F_38 ( & V_2 -> V_59 ) ;
case V_63 :
return F_25 ( V_20 , V_23 ) ;
case V_66 :
case V_46 :
F_37 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_44 != V_46 &&
V_2 -> V_44 != V_66 ) {
F_38 ( & V_2 -> V_59 ) ;
goto V_65;
}
F_33 ( V_2 , V_23 ) ;
F_38 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_44 == V_66 &&
! F_36 ( V_2 -> V_18 , NULL ) ) {
F_37 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_44 == V_66 && V_2 -> V_47 )
F_13 ( V_20 , V_2 , 1 ) ;
F_38 ( & V_2 -> V_59 ) ;
}
}
return 0 ;
}
static struct V_1 * F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_67 , * V_2 , * * V_68 ;
if ( ! F_40 ( & V_5 -> V_7 ) )
return NULL ;
for ( V_2 = V_5 -> V_69 , V_67 = & V_5 -> V_58 [ V_53 ] ; V_2 != V_67 ; ++ V_2 )
if ( F_40 ( & V_2 -> V_6 ) == 0 )
goto V_70;
for ( V_2 = V_5 -> V_58 ; F_40 ( & V_2 -> V_6 ) ; ++ V_2 )
;
V_70:
V_5 -> V_69 = V_2 + 1 ;
F_4 ( & V_5 -> V_7 ) ;
if ( V_2 -> V_44 < V_45 )
for ( V_68 = & V_5 -> V_58 [ V_2 -> V_71 ] . V_72 ; * V_68 ; V_68 = & ( * V_68 ) -> V_48 )
if ( * V_68 == V_2 ) {
* V_68 = V_2 -> V_48 ;
V_2 -> V_48 = NULL ;
break;
}
V_2 -> V_44 = V_73 ;
return V_2 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_37 ( & V_2 -> V_59 ) ;
if ( F_40 ( & V_2 -> V_6 ) == 0 ) {
if ( V_2 -> V_18 ) {
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
while ( V_2 -> V_47 ) {
struct V_22 * V_23 = V_2 -> V_47 ;
V_2 -> V_47 = V_23 -> V_48 ;
F_42 ( V_23 ) ;
}
V_2 -> V_49 = NULL ;
}
F_38 ( & V_2 -> V_59 ) ;
V_5 = F_43 ( V_2 , struct V_4 , V_58 [ V_2 -> V_29 ] ) ;
F_44 ( & V_5 -> V_7 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_46 ( & V_2 -> V_6 ) )
F_41 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
unsigned int V_60 ;
F_31 ( & V_2 -> V_59 ) ;
if ( V_18 != V_2 -> V_18 )
F_10 ( V_2 , V_18 ) ;
V_60 = V_18 -> V_60 ;
if ( memcmp ( V_2 -> V_40 , V_18 -> V_41 , sizeof( V_2 -> V_40 ) ) ||
! ( V_60 & V_74 ) )
V_2 -> V_44 = V_66 ;
else if ( V_60 & V_75 )
V_2 -> V_44 = V_63 ;
else
V_2 -> V_44 = V_62 ;
F_32 ( & V_2 -> V_59 ) ;
}
struct V_1 * F_48 ( struct V_4 * V_5 , struct V_16 * V_18 ,
const struct V_64 * V_76 ,
unsigned int V_77 )
{
T_2 V_35 ;
T_3 V_3 ;
struct V_1 * V_2 ;
int V_14 = V_18 -> V_78 -> V_79 ;
T_1 * V_13 = ( T_1 * ) V_18 -> V_80 ;
int V_81 = V_18 -> V_37 -> V_9 ;
int V_71 = F_8 ( V_13 , V_14 , V_81 ) ;
if ( V_18 -> V_37 -> V_38 & V_39 )
V_35 = F_49 ( V_76 ) -> V_82 + 4 ;
else
V_35 = F_49 ( V_76 ) -> V_35 ;
if ( V_18 -> V_37 -> V_83 & V_84 )
V_3 = F_50 ( V_18 -> V_37 ) ;
else
V_3 = V_85 ;
F_51 ( & V_5 -> V_59 ) ;
for ( V_2 = V_5 -> V_58 [ V_71 ] . V_72 ; V_2 ; V_2 = V_2 -> V_48 )
if ( ! F_9 ( V_2 , V_13 ) && V_2 -> V_9 == V_81 &&
V_2 -> V_3 == V_3 && V_2 -> V_35 == V_35 ) {
F_2 ( V_5 , V_2 ) ;
if ( F_40 ( & V_2 -> V_6 ) == 1 )
F_47 ( V_2 , V_18 ) ;
goto V_86;
}
V_2 = F_39 ( V_5 ) ;
if ( V_2 ) {
F_31 ( & V_2 -> V_59 ) ;
V_2 -> V_44 = V_66 ;
if ( V_18 -> V_37 -> V_38 & V_39 )
memcpy ( V_2 -> V_40 , V_76 -> V_87 , sizeof( V_2 -> V_40 ) ) ;
memcpy ( V_2 -> V_13 , V_13 , V_14 ) ;
V_2 -> V_9 = V_81 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_15 = V_14 == 16 ;
F_52 ( & V_2 -> V_6 , 1 ) ;
F_10 ( V_2 , V_18 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_48 = V_5 -> V_58 [ V_71 ] . V_72 ;
V_5 -> V_58 [ V_71 ] . V_72 = V_2 ;
F_32 ( & V_2 -> V_59 ) ;
}
V_86:
F_53 ( & V_5 -> V_59 ) ;
return V_2 ;
}
T_4 F_54 ( struct V_64 * V_37 ,
const struct V_1 * V_57 )
{
struct V_19 * V_20 = F_35 ( V_37 ) ;
struct V_88 * V_89 = & V_20 -> V_34 . V_89 ;
T_4 V_90 = 0 ;
if ( V_89 -> V_91 >= 0 && V_57 -> V_3 != V_85 )
V_90 |= ( T_4 ) ( V_92 | V_57 -> V_3 ) << V_89 -> V_91 ;
if ( V_89 -> V_93 >= 0 )
V_90 |= ( T_4 ) V_57 -> V_35 << V_89 -> V_93 ;
if ( V_89 -> V_94 >= 0 )
V_90 |= ( T_4 ) V_95 << V_89 -> V_94 ;
if ( V_89 -> V_96 >= 0 ) {
T_1 V_97 = F_55 ( V_37 ) ;
T_1 V_98 = F_56 ( V_97 ) ;
T_1 V_99 = F_57 ( V_97 ) ;
T_1 V_100 = F_58 ( V_97 ) ;
V_90 |= ( T_4 ) ( F_59 ( V_98 ) |
F_60 ( V_99 ) |
F_61 ( V_100 ) ) << V_89 -> V_96 ;
}
return V_90 ;
}
static void F_62 ( struct V_19 * V_20 , struct V_22 * V_101 )
{
while ( V_101 ) {
struct V_22 * V_23 = V_101 ;
const struct V_102 * V_103 = F_63 ( V_23 ) ;
V_101 = V_23 -> V_48 ;
V_23 -> V_48 = NULL ;
if ( V_103 -> V_104 )
V_103 -> V_104 ( V_103 -> V_105 , V_23 ) ;
else
F_25 ( V_20 , V_23 ) ;
}
}
void F_64 ( struct V_19 * V_20 , struct V_16 * V_18 )
{
struct V_1 * V_2 ;
struct V_22 * V_101 = NULL ;
struct V_4 * V_5 = V_20 -> V_57 ;
int V_14 = V_18 -> V_78 -> V_79 ;
T_1 * V_13 = ( T_1 * ) V_18 -> V_80 ;
int V_81 = V_18 -> V_37 -> V_9 ;
int V_71 = F_8 ( V_13 , V_14 , V_81 ) ;
F_65 ( & V_5 -> V_59 ) ;
for ( V_2 = V_5 -> V_58 [ V_71 ] . V_72 ; V_2 ; V_2 = V_2 -> V_48 )
if ( ! F_9 ( V_2 , V_13 ) && V_2 -> V_9 == V_81 ) {
F_31 ( & V_2 -> V_59 ) ;
if ( F_40 ( & V_2 -> V_6 ) )
goto V_70;
F_32 ( & V_2 -> V_59 ) ;
break;
}
F_66 ( & V_5 -> V_59 ) ;
return;
V_70:
F_67 ( & V_5 -> V_59 ) ;
if ( V_18 != V_2 -> V_18 )
F_10 ( V_2 , V_18 ) ;
if ( V_2 -> V_44 == V_66 ) {
if ( V_18 -> V_60 & V_106 ) {
V_101 = V_2 -> V_47 ;
V_2 -> V_47 = V_2 -> V_49 = NULL ;
} else if ( ( V_18 -> V_60 & ( V_75 | V_61 ) ) &&
V_2 -> V_47 ) {
F_13 ( V_20 , V_2 , 1 ) ;
}
} else {
V_2 -> V_44 = V_18 -> V_60 & V_75 ?
V_63 : V_62 ;
if ( memcmp ( V_2 -> V_40 , V_18 -> V_41 , sizeof( V_2 -> V_40 ) ) )
F_13 ( V_20 , V_2 , 0 ) ;
}
F_38 ( & V_2 -> V_59 ) ;
if ( V_101 )
F_62 ( V_20 , V_101 ) ;
}
struct V_1 * F_68 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_51 ( & V_5 -> V_59 ) ;
V_2 = F_39 ( V_5 ) ;
if ( V_2 ) {
F_31 ( & V_2 -> V_59 ) ;
V_2 -> V_44 = V_45 ;
F_52 ( & V_2 -> V_6 , 1 ) ;
F_32 ( & V_2 -> V_59 ) ;
}
F_53 ( & V_5 -> V_59 ) ;
return V_2 ;
}
int F_69 ( struct V_19 * V_20 , struct V_1 * V_2 , T_3 V_3 ,
T_2 V_107 , T_2 * V_108 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_35 = V_107 ;
memcpy ( V_2 -> V_40 , V_108 , V_109 ) ;
return F_13 ( V_20 , V_2 , 0 ) ;
}
struct V_4 * F_70 ( void )
{
int V_110 ;
struct V_4 * V_5 ;
V_5 = F_71 ( sizeof( * V_5 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_69 = V_5 -> V_58 ;
F_52 ( & V_5 -> V_7 , V_53 ) ;
F_72 ( & V_5 -> V_59 ) ;
for ( V_110 = 0 ; V_110 < V_53 ; ++ V_110 ) {
V_5 -> V_58 [ V_110 ] . V_29 = V_110 ;
V_5 -> V_58 [ V_110 ] . V_44 = V_73 ;
F_73 ( & V_5 -> V_58 [ V_110 ] . V_59 ) ;
F_52 ( & V_5 -> V_58 [ V_110 ] . V_6 , 0 ) ;
}
return V_5 ;
}
static inline void * F_74 ( struct V_111 * V_112 , T_5 V_113 )
{
struct V_1 * V_58 = V_112 -> V_114 ;
return V_113 >= V_53 ? NULL : & V_58 [ V_113 ] ;
}
static void * F_75 ( struct V_111 * V_112 , T_5 * V_113 )
{
return * V_113 ? F_74 ( V_112 , * V_113 - 1 ) : V_115 ;
}
static void * F_76 ( struct V_111 * V_112 , void * V_116 , T_5 * V_113 )
{
V_116 = F_74 ( V_112 , * V_113 ) ;
if ( V_116 )
++ * V_113 ;
return V_116 ;
}
static void F_77 ( struct V_111 * V_112 , void * V_116 )
{
}
static char F_78 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_44 ) {
case V_63 : return 'V' ;
case V_62 : return 'S' ;
case V_46 : return 'W' ;
case V_66 : return V_2 -> V_47 ? 'A' : 'R' ;
case V_45 : return 'X' ;
default:
return 'U' ;
}
}
static int F_79 ( struct V_111 * V_112 , void * V_116 )
{
if ( V_116 == V_115 )
F_80 ( V_112 , L_2
L_3 ) ;
else {
char V_117 [ 60 ] ;
struct V_1 * V_2 = V_116 ;
F_37 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_44 == V_45 )
V_117 [ 0 ] = '\0' ;
else
sprintf ( V_117 , V_2 -> V_15 ? L_4 : L_5 , V_2 -> V_13 ) ;
F_81 ( V_112 , L_6 ,
V_2 -> V_29 , V_117 , V_2 -> V_40 ,
V_2 -> V_3 & V_118 , F_1 ( V_2 ) , V_2 -> V_35 ,
F_78 ( V_2 ) , F_40 ( & V_2 -> V_6 ) ,
V_2 -> V_18 ? V_2 -> V_18 -> V_37 -> V_119 : L_7 ) ;
F_38 ( & V_2 -> V_59 ) ;
}
return 0 ;
}
static int F_82 ( struct V_120 * V_120 , struct V_121 * V_121 )
{
int V_122 = F_83 ( V_121 , & V_123 ) ;
if ( ! V_122 ) {
struct V_19 * V_20 = V_120 -> V_124 ;
struct V_111 * V_112 = V_121 -> V_125 ;
V_112 -> V_114 = V_20 -> V_57 -> V_58 ;
}
return V_122 ;
}
