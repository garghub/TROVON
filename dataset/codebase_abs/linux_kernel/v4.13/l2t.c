static inline unsigned int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 >> V_4 ;
}
static inline void F_2 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
if ( F_3 ( 1 , & V_2 -> V_7 ) == 1 )
F_4 ( & V_6 -> V_8 ) ;
}
static inline unsigned int F_5 ( struct V_5 * V_6 , const T_1 * V_9 ,
int V_10 )
{
unsigned int V_11 = V_6 -> V_12 / 2 ;
return F_6 ( * V_9 , V_10 , 0 ) % V_11 ;
}
static inline unsigned int F_7 ( struct V_5 * V_6 , const T_1 * V_9 ,
int V_10 )
{
unsigned int V_11 = V_6 -> V_12 / 2 ;
T_1 V_13 = V_9 [ 0 ] ^ V_9 [ 1 ] ^ V_9 [ 2 ] ^ V_9 [ 3 ] ;
return ( V_11 +
( F_6 ( V_13 , V_10 , 0 ) % V_11 ) ) ;
}
static unsigned int F_8 ( struct V_5 * V_6 , const T_1 * V_14 ,
int V_15 , int V_10 )
{
return V_15 == 4 ? F_5 ( V_6 , V_14 , V_10 ) :
F_7 ( V_6 , V_14 , V_10 ) ;
}
static int F_9 ( const struct V_1 * V_2 , const T_1 * V_14 )
{
if ( V_2 -> V_16 )
return ( V_2 -> V_14 [ 0 ] ^ V_14 [ 0 ] ) | ( V_2 -> V_14 [ 1 ] ^ V_14 [ 1 ] ) |
( V_2 -> V_14 [ 2 ] ^ V_14 [ 2 ] ) | ( V_2 -> V_14 [ 3 ] ^ V_14 [ 3 ] ) ;
return V_2 -> V_14 [ 0 ] ^ V_14 [ 0 ] ;
}
static void F_10 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
F_11 ( V_18 ) ;
if ( V_2 -> V_19 )
F_12 ( V_2 -> V_19 ) ;
V_2 -> V_19 = V_18 ;
}
static int F_13 ( struct V_20 * V_21 , struct V_1 * V_2 , int V_22 )
{
struct V_5 * V_6 = V_21 -> V_23 ;
unsigned int V_24 = V_2 -> V_25 + V_6 -> V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_28 = F_14 ( sizeof( * V_30 ) , V_31 ) ;
if ( ! V_28 )
return - V_32 ;
V_30 = F_15 ( V_28 , sizeof( * V_30 ) ) ;
F_16 ( V_30 , 0 ) ;
F_17 ( V_30 ) = F_18 ( F_19 ( V_33 ,
V_24 | ( V_22 ? V_34 : 0 ) |
F_20 ( V_21 -> V_35 . V_36 . V_37 ) ) ) ;
V_30 -> V_38 = F_21 ( F_22 ( V_2 -> V_39 ) | F_23 ( ! V_22 ) ) ;
V_30 -> V_24 = F_21 ( V_24 ) ;
V_30 -> V_3 = F_21 ( V_2 -> V_3 ) ;
if ( V_2 -> V_19 && ! ( V_2 -> V_19 -> V_40 -> V_41 & V_42 ) )
memcpy ( V_2 -> V_43 , V_2 -> V_19 -> V_44 , sizeof( V_2 -> V_43 ) ) ;
memcpy ( V_30 -> V_45 , V_2 -> V_43 , sizeof( V_30 -> V_45 ) ) ;
F_24 ( V_21 , V_28 ) ;
if ( V_22 && V_2 -> V_46 != V_47 )
V_2 -> V_46 = V_48 ;
return 0 ;
}
static void F_25 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_27 * V_28 ;
while ( ( V_28 = F_26 ( & V_2 -> V_49 ) ) != NULL )
F_27 ( V_21 , V_28 ) ;
}
void F_28 ( struct V_20 * V_21 , const struct V_50 * V_51 )
{
struct V_5 * V_6 = V_21 -> V_23 ;
unsigned int V_52 = F_29 ( V_51 ) ;
unsigned int V_24 = V_52 % V_53 ;
if ( F_30 ( V_51 -> V_54 != V_55 ) ) {
F_31 ( V_21 -> V_56 ,
L_1 ,
V_51 -> V_54 , V_24 ) ;
return;
}
if ( V_52 & V_34 ) {
struct V_1 * V_2 = & V_6 -> V_57 [ V_24 - V_6 -> V_26 ] ;
F_32 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_46 != V_47 ) {
F_25 ( V_21 , V_2 ) ;
V_2 -> V_46 = ( V_2 -> V_19 -> V_59 & V_60 ) ?
V_61 : V_62 ;
}
F_33 ( & V_2 -> V_58 ) ;
}
}
static inline void F_34 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_35 ( & V_2 -> V_49 , V_28 ) ;
}
int F_36 ( struct V_63 * V_40 , struct V_27 * V_28 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 = F_37 ( V_40 ) ;
V_64:
switch ( V_2 -> V_46 ) {
case V_61 :
F_38 ( V_2 -> V_19 , NULL ) ;
F_39 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_46 == V_61 )
V_2 -> V_46 = V_62 ;
F_40 ( & V_2 -> V_58 ) ;
case V_62 :
return F_27 ( V_21 , V_28 ) ;
case V_65 :
case V_48 :
F_39 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_46 != V_48 &&
V_2 -> V_46 != V_65 ) {
F_40 ( & V_2 -> V_58 ) ;
goto V_64;
}
F_34 ( V_2 , V_28 ) ;
F_40 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_46 == V_65 &&
! F_38 ( V_2 -> V_19 , NULL ) ) {
F_39 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_46 == V_65 &&
! F_41 ( & V_2 -> V_49 ) )
F_13 ( V_21 , V_2 , 1 ) ;
F_40 ( & V_2 -> V_58 ) ;
}
}
return 0 ;
}
static struct V_1 * F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_66 , * V_2 , * * V_67 ;
if ( ! F_43 ( & V_6 -> V_8 ) )
return NULL ;
for ( V_2 = V_6 -> V_68 , V_66 = & V_6 -> V_57 [ V_6 -> V_12 ] ; V_2 != V_66 ; ++ V_2 )
if ( F_43 ( & V_2 -> V_7 ) == 0 )
goto V_69;
for ( V_2 = V_6 -> V_57 ; F_43 ( & V_2 -> V_7 ) ; ++ V_2 )
;
V_69:
V_6 -> V_68 = V_2 + 1 ;
F_4 ( & V_6 -> V_8 ) ;
if ( V_2 -> V_46 < V_47 )
for ( V_67 = & V_6 -> V_57 [ V_2 -> V_70 ] . V_71 ; * V_67 ; V_67 = & ( * V_67 ) -> V_72 )
if ( * V_67 == V_2 ) {
* V_67 = V_2 -> V_72 ;
V_2 -> V_72 = NULL ;
break;
}
V_2 -> V_46 = V_73 ;
return V_2 ;
}
static struct V_1 * F_44 ( struct V_5 * V_6 , T_2 V_3 ,
T_3 V_74 , T_3 * V_43 )
{
struct V_1 * V_66 , * V_2 , * * V_67 ;
struct V_1 * V_75 = NULL ;
for ( V_2 = & V_6 -> V_57 [ 0 ] , V_66 = & V_6 -> V_57 [ V_6 -> V_12 ] ; V_2 != V_66 ; ++ V_2 ) {
if ( F_43 ( & V_2 -> V_7 ) == 0 ) {
if ( ! V_75 )
V_75 = V_2 ;
} else {
if ( V_2 -> V_46 == V_47 ) {
if ( F_45 ( V_2 -> V_43 , V_43 ) &&
( V_2 -> V_3 == V_3 ) && ( V_2 -> V_39 == V_74 ) )
goto V_76;
}
}
}
if ( V_75 ) {
V_2 = V_75 ;
goto V_69;
}
return NULL ;
V_69:
if ( V_2 -> V_46 < V_47 )
for ( V_67 = & V_6 -> V_57 [ V_2 -> V_70 ] . V_71 ; * V_67 ; V_67 = & ( * V_67 ) -> V_72 )
if ( * V_67 == V_2 ) {
* V_67 = V_2 -> V_72 ;
V_2 -> V_72 = NULL ;
break;
}
V_2 -> V_46 = V_73 ;
V_76:
return V_2 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
if ( F_43 ( & V_2 -> V_7 ) == 0 ) {
if ( V_2 -> V_19 ) {
F_12 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
}
while ( ( V_28 = F_26 ( & V_2 -> V_49 ) ) != NULL )
F_47 ( V_28 ) ;
}
V_6 = F_48 ( V_2 , struct V_5 , V_57 [ V_2 -> V_25 ] ) ;
F_49 ( & V_6 -> V_8 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
F_39 ( & V_2 -> V_58 ) ;
if ( F_43 ( & V_2 -> V_7 ) == 0 ) {
if ( V_2 -> V_19 ) {
F_12 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
}
while ( ( V_28 = F_26 ( & V_2 -> V_49 ) ) != NULL )
F_47 ( V_28 ) ;
}
F_40 ( & V_2 -> V_58 ) ;
V_6 = F_48 ( V_2 , struct V_5 , V_57 [ V_2 -> V_25 ] ) ;
F_49 ( & V_6 -> V_8 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
if ( F_52 ( & V_2 -> V_7 ) )
F_50 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_17 * V_19 )
{
unsigned int V_59 ;
F_32 ( & V_2 -> V_58 ) ;
if ( V_19 != V_2 -> V_19 )
F_10 ( V_2 , V_19 ) ;
V_59 = V_19 -> V_59 ;
if ( memcmp ( V_2 -> V_43 , V_19 -> V_44 , sizeof( V_2 -> V_43 ) ) ||
! ( V_59 & V_77 ) )
V_2 -> V_46 = V_65 ;
else if ( V_59 & V_78 )
V_2 -> V_46 = V_62 ;
else
V_2 -> V_46 = V_61 ;
F_33 ( & V_2 -> V_58 ) ;
}
struct V_1 * F_54 ( struct V_5 * V_6 , struct V_17 * V_19 ,
const struct V_63 * V_79 ,
unsigned int V_80 )
{
T_3 V_39 ;
T_2 V_3 ;
struct V_1 * V_2 ;
int V_15 = V_19 -> V_81 -> V_82 ;
T_1 * V_14 = ( T_1 * ) V_19 -> V_83 ;
int V_84 = V_19 -> V_40 -> V_10 ;
int V_70 = F_8 ( V_6 , V_14 , V_15 , V_84 ) ;
if ( V_19 -> V_40 -> V_41 & V_42 )
V_39 = F_55 ( V_79 ) -> V_85 + 4 ;
else
V_39 = F_55 ( V_79 ) -> V_39 ;
if ( F_56 ( V_19 -> V_40 ) )
V_3 = F_57 ( V_19 -> V_40 ) ;
else
V_3 = V_86 ;
F_58 ( & V_6 -> V_58 ) ;
for ( V_2 = V_6 -> V_57 [ V_70 ] . V_71 ; V_2 ; V_2 = V_2 -> V_72 )
if ( ! F_9 ( V_2 , V_14 ) && V_2 -> V_10 == V_84 &&
V_2 -> V_3 == V_3 && V_2 -> V_39 == V_39 ) {
F_2 ( V_6 , V_2 ) ;
if ( F_43 ( & V_2 -> V_7 ) == 1 )
F_53 ( V_2 , V_19 ) ;
goto V_87;
}
V_2 = F_42 ( V_6 ) ;
if ( V_2 ) {
F_32 ( & V_2 -> V_58 ) ;
V_2 -> V_46 = V_65 ;
if ( V_19 -> V_40 -> V_41 & V_42 )
memcpy ( V_2 -> V_43 , V_79 -> V_88 , sizeof( V_2 -> V_43 ) ) ;
memcpy ( V_2 -> V_14 , V_14 , V_15 ) ;
V_2 -> V_10 = V_84 ;
V_2 -> V_70 = V_70 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_16 = V_15 == 16 ;
F_59 ( & V_2 -> V_7 , 1 ) ;
F_10 ( V_2 , V_19 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_72 = V_6 -> V_57 [ V_70 ] . V_71 ;
V_6 -> V_57 [ V_70 ] . V_71 = V_2 ;
F_33 ( & V_2 -> V_58 ) ;
}
V_87:
F_60 ( & V_6 -> V_58 ) ;
return V_2 ;
}
T_4 F_61 ( struct V_63 * V_40 ,
const struct V_1 * V_23 )
{
struct V_20 * V_21 = F_37 ( V_40 ) ;
struct V_89 * V_90 = & V_21 -> V_38 . V_90 ;
T_4 V_91 = 0 ;
if ( V_90 -> V_92 >= 0 && V_23 -> V_3 != V_86 )
V_91 |= ( T_4 ) ( V_93 | V_23 -> V_3 ) << V_90 -> V_92 ;
if ( V_90 -> V_94 >= 0 )
V_91 |= ( T_4 ) V_23 -> V_39 << V_90 -> V_94 ;
if ( V_90 -> V_95 >= 0 )
V_91 |= ( T_4 ) V_96 << V_90 -> V_95 ;
if ( V_90 -> V_97 >= 0 ) {
T_1 V_98 = F_62 ( V_40 ) ;
T_1 V_99 = F_63 ( V_98 ) ;
T_1 V_100 = F_64 ( V_98 ) ;
T_1 V_101 = F_65 ( V_98 ) ;
V_91 |= ( T_4 ) ( F_66 ( V_99 ) |
F_67 ( V_100 ) |
F_68 ( V_101 ) ) << V_90 -> V_97 ;
}
return V_91 ;
}
static void F_69 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_27 * V_28 ;
while ( ( V_28 = F_26 ( & V_2 -> V_49 ) ) != NULL ) {
const struct V_102 * V_103 = F_70 ( V_28 ) ;
F_33 ( & V_2 -> V_58 ) ;
if ( V_103 -> V_104 )
V_103 -> V_104 ( V_103 -> V_105 , V_28 ) ;
else
F_27 ( V_21 , V_28 ) ;
F_32 ( & V_2 -> V_58 ) ;
}
}
void F_71 ( struct V_20 * V_21 , struct V_17 * V_19 )
{
struct V_1 * V_2 ;
struct V_106 * V_49 = NULL ;
struct V_5 * V_6 = V_21 -> V_23 ;
int V_15 = V_19 -> V_81 -> V_82 ;
T_1 * V_14 = ( T_1 * ) V_19 -> V_83 ;
int V_84 = V_19 -> V_40 -> V_10 ;
int V_70 = F_8 ( V_6 , V_14 , V_15 , V_84 ) ;
F_72 ( & V_6 -> V_58 ) ;
for ( V_2 = V_6 -> V_57 [ V_70 ] . V_71 ; V_2 ; V_2 = V_2 -> V_72 )
if ( ! F_9 ( V_2 , V_14 ) && V_2 -> V_10 == V_84 ) {
F_32 ( & V_2 -> V_58 ) ;
if ( F_43 ( & V_2 -> V_7 ) )
goto V_69;
F_33 ( & V_2 -> V_58 ) ;
break;
}
F_73 ( & V_6 -> V_58 ) ;
return;
V_69:
F_74 ( & V_6 -> V_58 ) ;
if ( V_19 != V_2 -> V_19 )
F_10 ( V_2 , V_19 ) ;
if ( V_2 -> V_46 == V_65 ) {
if ( V_19 -> V_59 & V_107 ) {
V_49 = & V_2 -> V_49 ;
} else if ( ( V_19 -> V_59 & ( V_78 | V_60 ) ) &&
! F_41 ( & V_2 -> V_49 ) ) {
F_13 ( V_21 , V_2 , 1 ) ;
}
} else {
V_2 -> V_46 = V_19 -> V_59 & V_78 ?
V_62 : V_61 ;
if ( memcmp ( V_2 -> V_43 , V_19 -> V_44 , sizeof( V_2 -> V_43 ) ) )
F_13 ( V_21 , V_2 , 0 ) ;
}
if ( V_49 )
F_69 ( V_21 , V_2 ) ;
F_40 ( & V_2 -> V_58 ) ;
}
struct V_1 * F_75 ( struct V_20 * V_21 , T_2 V_3 ,
T_3 V_74 , T_3 * V_108 )
{
struct V_5 * V_6 = V_21 -> V_23 ;
struct V_1 * V_2 ;
int V_109 ;
F_58 ( & V_6 -> V_58 ) ;
V_2 = F_44 ( V_6 , V_3 , V_74 , V_108 ) ;
if ( V_2 ) {
F_32 ( & V_2 -> V_58 ) ;
if ( ! F_43 ( & V_2 -> V_7 ) ) {
V_2 -> V_46 = V_47 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_39 = V_74 ;
F_76 ( V_2 -> V_43 , V_108 ) ;
F_59 ( & V_2 -> V_7 , 1 ) ;
V_109 = F_13 ( V_21 , V_2 , 0 ) ;
if ( V_109 < 0 ) {
F_46 ( V_2 ) ;
F_33 ( & V_2 -> V_58 ) ;
F_60 ( & V_6 -> V_58 ) ;
return NULL ;
}
} else {
F_49 ( & V_2 -> V_7 ) ;
}
F_33 ( & V_2 -> V_58 ) ;
}
F_60 ( & V_6 -> V_58 ) ;
return V_2 ;
}
struct V_1 * F_77 ( struct V_63 * V_40 , T_2 V_3 ,
T_3 V_74 , T_3 * V_43 )
{
struct V_20 * V_21 = F_37 ( V_40 ) ;
return F_75 ( V_21 , V_3 , V_74 , V_43 ) ;
}
struct V_5 * F_78 ( unsigned int V_26 , unsigned int V_110 )
{
unsigned int V_12 ;
int V_111 ;
struct V_5 * V_6 ;
if ( V_26 >= V_110 || V_110 >= V_53 )
return NULL ;
V_12 = V_110 - V_26 + 1 ;
if ( V_12 < V_112 )
return NULL ;
V_6 = F_79 ( sizeof( * V_6 ) + V_12 * sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_26 = V_26 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_68 = V_6 -> V_57 ;
F_59 ( & V_6 -> V_8 , V_12 ) ;
F_80 ( & V_6 -> V_58 ) ;
for ( V_111 = 0 ; V_111 < V_6 -> V_12 ; ++ V_111 ) {
V_6 -> V_57 [ V_111 ] . V_25 = V_111 ;
V_6 -> V_57 [ V_111 ] . V_46 = V_73 ;
F_81 ( & V_6 -> V_57 [ V_111 ] . V_58 ) ;
F_59 ( & V_6 -> V_57 [ V_111 ] . V_7 , 0 ) ;
F_82 ( & V_6 -> V_57 [ V_111 ] . V_49 ) ;
}
return V_6 ;
}
static inline void * F_83 ( struct V_114 * V_115 , T_5 V_116 )
{
struct V_5 * V_6 = V_115 -> V_117 ;
return V_116 >= V_6 -> V_12 ? NULL : & V_6 -> V_57 [ V_116 ] ;
}
static void * F_84 ( struct V_114 * V_115 , T_5 * V_116 )
{
return * V_116 ? F_83 ( V_115 , * V_116 - 1 ) : V_118 ;
}
static void * F_85 ( struct V_114 * V_115 , void * V_119 , T_5 * V_116 )
{
V_119 = F_83 ( V_115 , * V_116 ) ;
if ( V_119 )
++ * V_116 ;
return V_119 ;
}
static void F_86 ( struct V_114 * V_115 , void * V_119 )
{
}
static char F_87 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_46 ) {
case V_62 : return 'V' ;
case V_61 : return 'S' ;
case V_48 : return 'W' ;
case V_65 :
return F_41 ( & V_2 -> V_49 ) ? 'R' : 'A' ;
case V_47 : return 'X' ;
default:
return 'U' ;
}
}
static int F_88 ( struct V_114 * V_115 , void * V_119 )
{
if ( V_119 == V_118 )
F_89 ( V_115 , L_2
L_3 ) ;
else {
char V_120 [ 60 ] ;
struct V_5 * V_6 = V_115 -> V_117 ;
struct V_1 * V_2 = V_119 ;
F_39 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_46 == V_47 )
V_120 [ 0 ] = '\0' ;
else
sprintf ( V_120 , V_2 -> V_16 ? L_4 : L_5 , V_2 -> V_14 ) ;
F_90 ( V_115 , L_6 ,
V_2 -> V_25 + V_6 -> V_26 , V_120 , V_2 -> V_43 ,
V_2 -> V_3 & V_121 , F_1 ( V_2 ) , V_2 -> V_39 ,
F_87 ( V_2 ) , F_43 ( & V_2 -> V_7 ) ,
V_2 -> V_19 ? V_2 -> V_19 -> V_40 -> V_122 : L_7 ) ;
F_40 ( & V_2 -> V_58 ) ;
}
return 0 ;
}
static int F_91 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
int V_125 = F_92 ( V_124 , & V_126 ) ;
if ( ! V_125 ) {
struct V_20 * V_21 = V_123 -> V_127 ;
struct V_114 * V_115 = V_124 -> V_128 ;
V_115 -> V_117 = V_21 -> V_23 ;
}
return V_125 ;
}
