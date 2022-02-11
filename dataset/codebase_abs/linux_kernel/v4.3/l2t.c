static inline unsigned int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 >> 13 ;
}
static inline void F_2 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( F_3 ( 1 , & V_2 -> V_6 ) == 1 )
F_4 ( & V_5 -> V_7 ) ;
}
static inline unsigned int F_5 ( struct V_4 * V_5 , const T_1 * V_8 ,
int V_9 )
{
unsigned int V_10 = V_5 -> V_11 / 2 ;
return F_6 ( * V_8 , V_9 , 0 ) % V_10 ;
}
static inline unsigned int F_7 ( struct V_4 * V_5 , const T_1 * V_8 ,
int V_9 )
{
unsigned int V_10 = V_5 -> V_11 / 2 ;
T_1 V_12 = V_8 [ 0 ] ^ V_8 [ 1 ] ^ V_8 [ 2 ] ^ V_8 [ 3 ] ;
return ( V_10 +
( F_6 ( V_12 , V_9 , 0 ) % V_10 ) ) ;
}
static unsigned int F_8 ( struct V_4 * V_5 , const T_1 * V_13 ,
int V_14 , int V_9 )
{
return V_14 == 4 ? F_5 ( V_5 , V_13 , V_9 ) :
F_7 ( V_5 , V_13 , V_9 ) ;
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
struct V_4 * V_5 = V_20 -> V_22 ;
unsigned int V_23 = V_2 -> V_24 + V_5 -> V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = F_14 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_27 )
return - V_31 ;
V_29 = (struct V_28 * ) F_15 ( V_27 , sizeof( * V_29 ) ) ;
F_16 ( V_29 , 0 ) ;
F_17 ( V_29 ) = F_18 ( F_19 ( V_32 ,
V_23 | ( V_21 ? V_33 : 0 ) |
F_20 ( V_20 -> V_34 . V_35 . V_36 ) ) ) ;
V_29 -> V_37 = F_21 ( F_22 ( V_2 -> V_38 ) | F_23 ( ! V_21 ) ) ;
V_29 -> V_23 = F_21 ( V_23 ) ;
V_29 -> V_3 = F_21 ( V_2 -> V_3 ) ;
if ( V_2 -> V_18 && ! ( V_2 -> V_18 -> V_39 -> V_40 & V_41 ) )
memcpy ( V_2 -> V_42 , V_2 -> V_18 -> V_43 , sizeof( V_2 -> V_42 ) ) ;
memcpy ( V_29 -> V_44 , V_2 -> V_42 , sizeof( V_29 -> V_44 ) ) ;
F_24 ( V_27 , V_45 , 0 ) ;
F_25 ( V_20 , V_27 ) ;
if ( V_21 && V_2 -> V_46 != V_47 )
V_2 -> V_46 = V_48 ;
return 0 ;
}
static void F_26 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
while ( V_2 -> V_49 ) {
struct V_26 * V_27 = V_2 -> V_49 ;
V_2 -> V_49 = V_27 -> V_50 ;
V_27 -> V_50 = NULL ;
F_25 ( V_20 , V_27 ) ;
}
V_2 -> V_51 = NULL ;
}
void F_27 ( struct V_19 * V_20 , const struct V_52 * V_53 )
{
struct V_4 * V_5 = V_20 -> V_22 ;
unsigned int V_54 = F_28 ( V_53 ) ;
unsigned int V_23 = V_54 % V_55 ;
if ( F_29 ( V_53 -> V_56 != V_57 ) ) {
F_30 ( V_20 -> V_58 ,
L_1 ,
V_53 -> V_56 , V_23 ) ;
return;
}
if ( V_54 & V_33 ) {
struct V_1 * V_2 = & V_5 -> V_59 [ V_23 - V_5 -> V_25 ] ;
F_31 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_46 != V_47 ) {
F_26 ( V_20 , V_2 ) ;
V_2 -> V_46 = ( V_2 -> V_18 -> V_61 & V_62 ) ?
V_63 : V_64 ;
}
F_32 ( & V_2 -> V_60 ) ;
}
}
static inline void F_33 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
V_27 -> V_50 = NULL ;
if ( V_2 -> V_49 )
V_2 -> V_51 -> V_50 = V_27 ;
else
V_2 -> V_49 = V_27 ;
V_2 -> V_51 = V_27 ;
}
int F_34 ( struct V_65 * V_39 , struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_35 ( V_39 ) ;
V_66:
switch ( V_2 -> V_46 ) {
case V_63 :
F_36 ( V_2 -> V_18 , NULL ) ;
F_37 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_46 == V_63 )
V_2 -> V_46 = V_64 ;
F_38 ( & V_2 -> V_60 ) ;
case V_64 :
return F_25 ( V_20 , V_27 ) ;
case V_67 :
case V_48 :
F_37 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_46 != V_48 &&
V_2 -> V_46 != V_67 ) {
F_38 ( & V_2 -> V_60 ) ;
goto V_66;
}
F_33 ( V_2 , V_27 ) ;
F_38 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_46 == V_67 &&
! F_36 ( V_2 -> V_18 , NULL ) ) {
F_37 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_46 == V_67 && V_2 -> V_49 )
F_13 ( V_20 , V_2 , 1 ) ;
F_38 ( & V_2 -> V_60 ) ;
}
}
return 0 ;
}
static struct V_1 * F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_68 , * V_2 , * * V_69 ;
if ( ! F_40 ( & V_5 -> V_7 ) )
return NULL ;
for ( V_2 = V_5 -> V_70 , V_68 = & V_5 -> V_59 [ V_5 -> V_11 ] ; V_2 != V_68 ; ++ V_2 )
if ( F_40 ( & V_2 -> V_6 ) == 0 )
goto V_71;
for ( V_2 = V_5 -> V_59 ; F_40 ( & V_2 -> V_6 ) ; ++ V_2 )
;
V_71:
V_5 -> V_70 = V_2 + 1 ;
F_4 ( & V_5 -> V_7 ) ;
if ( V_2 -> V_46 < V_47 )
for ( V_69 = & V_5 -> V_59 [ V_2 -> V_72 ] . V_73 ; * V_69 ; V_69 = & ( * V_69 ) -> V_50 )
if ( * V_69 == V_2 ) {
* V_69 = V_2 -> V_50 ;
V_2 -> V_50 = NULL ;
break;
}
V_2 -> V_46 = V_74 ;
return V_2 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_37 ( & V_2 -> V_60 ) ;
if ( F_40 ( & V_2 -> V_6 ) == 0 ) {
if ( V_2 -> V_18 ) {
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
while ( V_2 -> V_49 ) {
struct V_26 * V_27 = V_2 -> V_49 ;
V_2 -> V_49 = V_27 -> V_50 ;
F_42 ( V_27 ) ;
}
V_2 -> V_51 = NULL ;
}
F_38 ( & V_2 -> V_60 ) ;
V_5 = F_43 ( V_2 , struct V_4 , V_59 [ V_2 -> V_24 ] ) ;
F_44 ( & V_5 -> V_7 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_46 ( & V_2 -> V_6 ) )
F_41 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
unsigned int V_61 ;
F_31 ( & V_2 -> V_60 ) ;
if ( V_18 != V_2 -> V_18 )
F_10 ( V_2 , V_18 ) ;
V_61 = V_18 -> V_61 ;
if ( memcmp ( V_2 -> V_42 , V_18 -> V_43 , sizeof( V_2 -> V_42 ) ) ||
! ( V_61 & V_75 ) )
V_2 -> V_46 = V_67 ;
else if ( V_61 & V_76 )
V_2 -> V_46 = V_64 ;
else
V_2 -> V_46 = V_63 ;
F_32 ( & V_2 -> V_60 ) ;
}
struct V_1 * F_48 ( struct V_4 * V_5 , struct V_16 * V_18 ,
const struct V_65 * V_77 ,
unsigned int V_78 )
{
T_2 V_38 ;
T_3 V_3 ;
struct V_1 * V_2 ;
int V_14 = V_18 -> V_79 -> V_80 ;
T_1 * V_13 = ( T_1 * ) V_18 -> V_81 ;
int V_82 = V_18 -> V_39 -> V_9 ;
int V_72 = F_8 ( V_5 , V_13 , V_14 , V_82 ) ;
if ( V_18 -> V_39 -> V_40 & V_41 )
V_38 = F_49 ( V_77 ) -> V_83 + 4 ;
else
V_38 = F_49 ( V_77 ) -> V_38 ;
if ( V_18 -> V_39 -> V_84 & V_85 )
V_3 = F_50 ( V_18 -> V_39 ) ;
else
V_3 = V_86 ;
F_51 ( & V_5 -> V_60 ) ;
for ( V_2 = V_5 -> V_59 [ V_72 ] . V_73 ; V_2 ; V_2 = V_2 -> V_50 )
if ( ! F_9 ( V_2 , V_13 ) && V_2 -> V_9 == V_82 &&
V_2 -> V_3 == V_3 && V_2 -> V_38 == V_38 ) {
F_2 ( V_5 , V_2 ) ;
if ( F_40 ( & V_2 -> V_6 ) == 1 )
F_47 ( V_2 , V_18 ) ;
goto V_87;
}
V_2 = F_39 ( V_5 ) ;
if ( V_2 ) {
F_31 ( & V_2 -> V_60 ) ;
V_2 -> V_46 = V_67 ;
if ( V_18 -> V_39 -> V_40 & V_41 )
memcpy ( V_2 -> V_42 , V_77 -> V_88 , sizeof( V_2 -> V_42 ) ) ;
memcpy ( V_2 -> V_13 , V_13 , V_14 ) ;
V_2 -> V_9 = V_82 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_15 = V_14 == 16 ;
F_52 ( & V_2 -> V_6 , 1 ) ;
F_10 ( V_2 , V_18 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_50 = V_5 -> V_59 [ V_72 ] . V_73 ;
V_5 -> V_59 [ V_72 ] . V_73 = V_2 ;
F_32 ( & V_2 -> V_60 ) ;
}
V_87:
F_53 ( & V_5 -> V_60 ) ;
return V_2 ;
}
T_4 F_54 ( struct V_65 * V_39 ,
const struct V_1 * V_22 )
{
struct V_19 * V_20 = F_35 ( V_39 ) ;
struct V_89 * V_90 = & V_20 -> V_37 . V_90 ;
T_4 V_91 = 0 ;
if ( V_90 -> V_92 >= 0 && V_22 -> V_3 != V_86 )
V_91 |= ( T_4 ) ( V_93 | V_22 -> V_3 ) << V_90 -> V_92 ;
if ( V_90 -> V_94 >= 0 )
V_91 |= ( T_4 ) V_22 -> V_38 << V_90 -> V_94 ;
if ( V_90 -> V_95 >= 0 )
V_91 |= ( T_4 ) V_96 << V_90 -> V_95 ;
if ( V_90 -> V_97 >= 0 ) {
T_1 V_98 = F_55 ( V_39 ) ;
T_1 V_99 = F_56 ( V_98 ) ;
T_1 V_100 = F_57 ( V_98 ) ;
T_1 V_101 = F_58 ( V_98 ) ;
V_91 |= ( T_4 ) ( F_59 ( V_99 ) |
F_60 ( V_100 ) |
F_61 ( V_101 ) ) << V_90 -> V_97 ;
}
return V_91 ;
}
static void F_62 ( struct V_19 * V_20 , struct V_26 * V_102 )
{
while ( V_102 ) {
struct V_26 * V_27 = V_102 ;
const struct V_103 * V_104 = F_63 ( V_27 ) ;
V_102 = V_27 -> V_50 ;
V_27 -> V_50 = NULL ;
if ( V_104 -> V_105 )
V_104 -> V_105 ( V_104 -> V_106 , V_27 ) ;
else
F_25 ( V_20 , V_27 ) ;
}
}
void F_64 ( struct V_19 * V_20 , struct V_16 * V_18 )
{
struct V_1 * V_2 ;
struct V_26 * V_102 = NULL ;
struct V_4 * V_5 = V_20 -> V_22 ;
int V_14 = V_18 -> V_79 -> V_80 ;
T_1 * V_13 = ( T_1 * ) V_18 -> V_81 ;
int V_82 = V_18 -> V_39 -> V_9 ;
int V_72 = F_8 ( V_5 , V_13 , V_14 , V_82 ) ;
F_65 ( & V_5 -> V_60 ) ;
for ( V_2 = V_5 -> V_59 [ V_72 ] . V_73 ; V_2 ; V_2 = V_2 -> V_50 )
if ( ! F_9 ( V_2 , V_13 ) && V_2 -> V_9 == V_82 ) {
F_31 ( & V_2 -> V_60 ) ;
if ( F_40 ( & V_2 -> V_6 ) )
goto V_71;
F_32 ( & V_2 -> V_60 ) ;
break;
}
F_66 ( & V_5 -> V_60 ) ;
return;
V_71:
F_67 ( & V_5 -> V_60 ) ;
if ( V_18 != V_2 -> V_18 )
F_10 ( V_2 , V_18 ) ;
if ( V_2 -> V_46 == V_67 ) {
if ( V_18 -> V_61 & V_107 ) {
V_102 = V_2 -> V_49 ;
V_2 -> V_49 = V_2 -> V_51 = NULL ;
} else if ( ( V_18 -> V_61 & ( V_76 | V_62 ) ) &&
V_2 -> V_49 ) {
F_13 ( V_20 , V_2 , 1 ) ;
}
} else {
V_2 -> V_46 = V_18 -> V_61 & V_76 ?
V_64 : V_63 ;
if ( memcmp ( V_2 -> V_42 , V_18 -> V_43 , sizeof( V_2 -> V_42 ) ) )
F_13 ( V_20 , V_2 , 0 ) ;
}
F_38 ( & V_2 -> V_60 ) ;
if ( V_102 )
F_62 ( V_20 , V_102 ) ;
}
struct V_1 * F_68 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_51 ( & V_5 -> V_60 ) ;
V_2 = F_39 ( V_5 ) ;
if ( V_2 ) {
F_31 ( & V_2 -> V_60 ) ;
V_2 -> V_46 = V_47 ;
F_52 ( & V_2 -> V_6 , 1 ) ;
F_32 ( & V_2 -> V_60 ) ;
}
F_53 ( & V_5 -> V_60 ) ;
return V_2 ;
}
int F_69 ( struct V_19 * V_20 , struct V_1 * V_2 , T_3 V_3 ,
T_2 V_108 , T_2 * V_109 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_38 = V_108 ;
memcpy ( V_2 -> V_42 , V_109 , V_110 ) ;
return F_13 ( V_20 , V_2 , 0 ) ;
}
struct V_4 * F_70 ( unsigned int V_25 , unsigned int V_111 )
{
unsigned int V_11 ;
int V_112 ;
struct V_4 * V_5 ;
if ( V_25 >= V_111 || V_111 >= V_55 )
return NULL ;
V_11 = V_111 - V_25 + 1 ;
if ( V_11 < V_113 )
return NULL ;
V_5 = F_71 ( sizeof( * V_5 ) + V_11 * sizeof( struct V_1 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_25 = V_25 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_70 = V_5 -> V_59 ;
F_52 ( & V_5 -> V_7 , V_11 ) ;
F_72 ( & V_5 -> V_60 ) ;
for ( V_112 = 0 ; V_112 < V_5 -> V_11 ; ++ V_112 ) {
V_5 -> V_59 [ V_112 ] . V_24 = V_112 ;
V_5 -> V_59 [ V_112 ] . V_46 = V_74 ;
F_73 ( & V_5 -> V_59 [ V_112 ] . V_60 ) ;
F_52 ( & V_5 -> V_59 [ V_112 ] . V_6 , 0 ) ;
}
return V_5 ;
}
static inline void * F_74 ( struct V_114 * V_115 , T_5 V_116 )
{
struct V_4 * V_5 = V_115 -> V_117 ;
return V_116 >= V_5 -> V_11 ? NULL : & V_5 -> V_59 [ V_116 ] ;
}
static void * F_75 ( struct V_114 * V_115 , T_5 * V_116 )
{
return * V_116 ? F_74 ( V_115 , * V_116 - 1 ) : V_118 ;
}
static void * F_76 ( struct V_114 * V_115 , void * V_119 , T_5 * V_116 )
{
V_119 = F_74 ( V_115 , * V_116 ) ;
if ( V_119 )
++ * V_116 ;
return V_119 ;
}
static void F_77 ( struct V_114 * V_115 , void * V_119 )
{
}
static char F_78 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_46 ) {
case V_64 : return 'V' ;
case V_63 : return 'S' ;
case V_48 : return 'W' ;
case V_67 : return V_2 -> V_49 ? 'A' : 'R' ;
case V_47 : return 'X' ;
default:
return 'U' ;
}
}
static int F_79 ( struct V_114 * V_115 , void * V_119 )
{
if ( V_119 == V_118 )
F_80 ( V_115 , L_2
L_3 ) ;
else {
char V_120 [ 60 ] ;
struct V_4 * V_5 = V_115 -> V_117 ;
struct V_1 * V_2 = V_119 ;
F_37 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_46 == V_47 )
V_120 [ 0 ] = '\0' ;
else
sprintf ( V_120 , V_2 -> V_15 ? L_4 : L_5 , V_2 -> V_13 ) ;
F_81 ( V_115 , L_6 ,
V_2 -> V_24 + V_5 -> V_25 , V_120 , V_2 -> V_42 ,
V_2 -> V_3 & V_121 , F_1 ( V_2 ) , V_2 -> V_38 ,
F_78 ( V_2 ) , F_40 ( & V_2 -> V_6 ) ,
V_2 -> V_18 ? V_2 -> V_18 -> V_39 -> V_122 : L_7 ) ;
F_38 ( & V_2 -> V_60 ) ;
}
return 0 ;
}
static int F_82 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
int V_125 = F_83 ( V_124 , & V_126 ) ;
if ( ! V_125 ) {
struct V_19 * V_20 = V_123 -> V_127 ;
struct V_114 * V_115 = V_124 -> V_128 ;
V_115 -> V_117 = V_20 -> V_22 ;
}
return V_125 ;
}
