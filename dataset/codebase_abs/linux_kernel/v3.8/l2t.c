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
if ( V_2 -> V_18 )
memcpy ( V_2 -> V_37 , V_2 -> V_18 -> V_38 , sizeof( V_2 -> V_37 ) ) ;
memcpy ( V_25 -> V_39 , V_2 -> V_37 , sizeof( V_25 -> V_39 ) ) ;
F_24 ( V_23 , V_40 , 0 ) ;
F_25 ( V_20 , V_23 ) ;
if ( V_21 && V_2 -> V_41 != V_42 )
V_2 -> V_41 = V_43 ;
return 0 ;
}
static void F_26 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
while ( V_2 -> V_44 ) {
struct V_22 * V_23 = V_2 -> V_44 ;
V_2 -> V_44 = V_23 -> V_45 ;
V_23 -> V_45 = NULL ;
F_25 ( V_20 , V_23 ) ;
}
V_2 -> V_46 = NULL ;
}
void F_27 ( struct V_19 * V_20 , const struct V_47 * V_48 )
{
unsigned int V_49 = F_28 ( V_48 ) ;
unsigned int V_29 = V_49 & ( V_50 - 1 ) ;
if ( F_29 ( V_48 -> V_51 != V_52 ) ) {
F_30 ( V_20 -> V_53 ,
L_1 ,
V_48 -> V_51 , V_29 ) ;
return;
}
if ( V_49 & V_30 ) {
struct V_1 * V_2 = & V_20 -> V_54 -> V_55 [ V_29 ] ;
F_31 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_41 != V_42 ) {
F_26 ( V_20 , V_2 ) ;
V_2 -> V_41 = ( V_2 -> V_18 -> V_57 & V_58 ) ?
V_59 : V_60 ;
}
F_32 ( & V_2 -> V_56 ) ;
}
}
static inline void F_33 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
V_23 -> V_45 = NULL ;
if ( V_2 -> V_44 )
V_2 -> V_46 -> V_45 = V_23 ;
else
V_2 -> V_44 = V_23 ;
V_2 -> V_46 = V_23 ;
}
int F_34 ( struct V_61 * V_62 , struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_35 ( V_62 ) ;
V_63:
switch ( V_2 -> V_41 ) {
case V_59 :
F_36 ( V_2 -> V_18 , NULL ) ;
F_37 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_41 == V_59 )
V_2 -> V_41 = V_60 ;
F_38 ( & V_2 -> V_56 ) ;
case V_60 :
return F_25 ( V_20 , V_23 ) ;
case V_64 :
case V_43 :
F_37 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_41 != V_43 &&
V_2 -> V_41 != V_64 ) {
F_38 ( & V_2 -> V_56 ) ;
goto V_63;
}
F_33 ( V_2 , V_23 ) ;
F_38 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_41 == V_64 &&
! F_36 ( V_2 -> V_18 , NULL ) ) {
F_37 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_41 == V_64 && V_2 -> V_44 )
F_13 ( V_20 , V_2 , 1 ) ;
F_38 ( & V_2 -> V_56 ) ;
}
}
return 0 ;
}
static struct V_1 * F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_65 , * V_2 , * * V_66 ;
if ( ! F_40 ( & V_5 -> V_7 ) )
return NULL ;
for ( V_2 = V_5 -> V_67 , V_65 = & V_5 -> V_55 [ V_50 ] ; V_2 != V_65 ; ++ V_2 )
if ( F_40 ( & V_2 -> V_6 ) == 0 )
goto V_68;
for ( V_2 = V_5 -> V_55 ; F_40 ( & V_2 -> V_6 ) ; ++ V_2 )
;
V_68:
V_5 -> V_67 = V_2 + 1 ;
F_4 ( & V_5 -> V_7 ) ;
if ( V_2 -> V_41 < V_42 )
for ( V_66 = & V_5 -> V_55 [ V_2 -> V_69 ] . V_70 ; * V_66 ; V_66 = & ( * V_66 ) -> V_45 )
if ( * V_66 == V_2 ) {
* V_66 = V_2 -> V_45 ;
V_2 -> V_45 = NULL ;
break;
}
V_2 -> V_41 = V_71 ;
return V_2 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_37 ( & V_2 -> V_56 ) ;
if ( F_40 ( & V_2 -> V_6 ) == 0 ) {
if ( V_2 -> V_18 ) {
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
while ( V_2 -> V_44 ) {
struct V_22 * V_23 = V_2 -> V_44 ;
V_2 -> V_44 = V_23 -> V_45 ;
F_42 ( V_23 ) ;
}
V_2 -> V_46 = NULL ;
}
F_38 ( & V_2 -> V_56 ) ;
V_5 = F_43 ( V_2 , struct V_4 , V_55 [ V_2 -> V_29 ] ) ;
F_44 ( & V_5 -> V_7 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_46 ( & V_2 -> V_6 ) )
F_41 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
unsigned int V_57 ;
F_31 ( & V_2 -> V_56 ) ;
if ( V_18 != V_2 -> V_18 )
F_10 ( V_2 , V_18 ) ;
V_57 = V_18 -> V_57 ;
if ( memcmp ( V_2 -> V_37 , V_18 -> V_38 , sizeof( V_2 -> V_37 ) ) ||
! ( V_57 & V_72 ) )
V_2 -> V_41 = V_64 ;
else if ( V_57 & V_73 )
V_2 -> V_41 = V_60 ;
else
V_2 -> V_41 = V_59 ;
F_32 ( & V_2 -> V_56 ) ;
}
struct V_1 * F_48 ( struct V_4 * V_5 , struct V_16 * V_18 ,
const struct V_61 * V_74 ,
unsigned int V_75 )
{
T_2 V_35 ;
T_3 V_3 ;
struct V_1 * V_2 ;
int V_14 = V_18 -> V_76 -> V_77 ;
T_1 * V_13 = ( T_1 * ) V_18 -> V_78 ;
int V_79 = V_18 -> V_62 -> V_9 ;
int V_69 = F_8 ( V_13 , V_14 , V_79 ) ;
if ( V_18 -> V_62 -> V_80 & V_81 )
V_35 = F_49 ( V_74 ) -> V_82 + 4 ;
else
V_35 = F_49 ( V_74 ) -> V_35 ;
if ( V_18 -> V_62 -> V_83 & V_84 )
V_3 = F_50 ( V_18 -> V_62 ) ;
else
V_3 = V_85 ;
F_51 ( & V_5 -> V_56 ) ;
for ( V_2 = V_5 -> V_55 [ V_69 ] . V_70 ; V_2 ; V_2 = V_2 -> V_45 )
if ( ! F_9 ( V_2 , V_13 ) && V_2 -> V_9 == V_79 &&
V_2 -> V_3 == V_3 && V_2 -> V_35 == V_35 ) {
F_2 ( V_5 , V_2 ) ;
if ( F_40 ( & V_2 -> V_6 ) == 1 )
F_47 ( V_2 , V_18 ) ;
goto V_86;
}
V_2 = F_39 ( V_5 ) ;
if ( V_2 ) {
F_31 ( & V_2 -> V_56 ) ;
V_2 -> V_41 = V_64 ;
memcpy ( V_2 -> V_13 , V_13 , V_14 ) ;
V_2 -> V_9 = V_79 ;
V_2 -> V_69 = V_69 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_15 = V_14 == 16 ;
F_52 ( & V_2 -> V_6 , 1 ) ;
F_10 ( V_2 , V_18 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_45 = V_5 -> V_55 [ V_69 ] . V_70 ;
V_5 -> V_55 [ V_69 ] . V_70 = V_2 ;
F_32 ( & V_2 -> V_56 ) ;
}
V_86:
F_53 ( & V_5 -> V_56 ) ;
return V_2 ;
}
static void F_54 ( struct V_19 * V_20 , struct V_22 * V_87 )
{
while ( V_87 ) {
struct V_22 * V_23 = V_87 ;
const struct V_88 * V_89 = F_55 ( V_23 ) ;
V_87 = V_23 -> V_45 ;
V_23 -> V_45 = NULL ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_91 , V_23 ) ;
else
F_25 ( V_20 , V_23 ) ;
}
}
void F_56 ( struct V_19 * V_20 , struct V_16 * V_18 )
{
struct V_1 * V_2 ;
struct V_22 * V_87 = NULL ;
struct V_4 * V_5 = V_20 -> V_54 ;
int V_14 = V_18 -> V_76 -> V_77 ;
T_1 * V_13 = ( T_1 * ) V_18 -> V_78 ;
int V_79 = V_18 -> V_62 -> V_9 ;
int V_69 = F_8 ( V_13 , V_14 , V_79 ) ;
F_57 ( & V_5 -> V_56 ) ;
for ( V_2 = V_5 -> V_55 [ V_69 ] . V_70 ; V_2 ; V_2 = V_2 -> V_45 )
if ( ! F_9 ( V_2 , V_13 ) && V_2 -> V_9 == V_79 ) {
F_31 ( & V_2 -> V_56 ) ;
if ( F_40 ( & V_2 -> V_6 ) )
goto V_68;
F_32 ( & V_2 -> V_56 ) ;
break;
}
F_58 ( & V_5 -> V_56 ) ;
return;
V_68:
F_59 ( & V_5 -> V_56 ) ;
if ( V_18 != V_2 -> V_18 )
F_10 ( V_2 , V_18 ) ;
if ( V_2 -> V_41 == V_64 ) {
if ( V_18 -> V_57 & V_92 ) {
V_87 = V_2 -> V_44 ;
V_2 -> V_44 = V_2 -> V_46 = NULL ;
} else if ( ( V_18 -> V_57 & ( V_73 | V_58 ) ) &&
V_2 -> V_44 ) {
F_13 ( V_20 , V_2 , 1 ) ;
}
} else {
V_2 -> V_41 = V_18 -> V_57 & V_73 ?
V_60 : V_59 ;
if ( memcmp ( V_2 -> V_37 , V_18 -> V_38 , sizeof( V_2 -> V_37 ) ) )
F_13 ( V_20 , V_2 , 0 ) ;
}
F_38 ( & V_2 -> V_56 ) ;
if ( V_87 )
F_54 ( V_20 , V_87 ) ;
}
struct V_1 * F_60 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_51 ( & V_5 -> V_56 ) ;
V_2 = F_39 ( V_5 ) ;
if ( V_2 ) {
F_31 ( & V_2 -> V_56 ) ;
V_2 -> V_41 = V_42 ;
F_52 ( & V_2 -> V_6 , 1 ) ;
F_32 ( & V_2 -> V_56 ) ;
}
F_53 ( & V_5 -> V_56 ) ;
return V_2 ;
}
int F_61 ( struct V_19 * V_20 , struct V_1 * V_2 , T_3 V_3 ,
T_2 V_93 , T_2 * V_94 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_35 = V_93 ;
memcpy ( V_2 -> V_37 , V_94 , V_95 ) ;
return F_13 ( V_20 , V_2 , 0 ) ;
}
struct V_4 * F_62 ( void )
{
int V_96 ;
struct V_4 * V_5 ;
V_5 = F_63 ( sizeof( * V_5 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_67 = V_5 -> V_55 ;
F_52 ( & V_5 -> V_7 , V_50 ) ;
F_64 ( & V_5 -> V_56 ) ;
for ( V_96 = 0 ; V_96 < V_50 ; ++ V_96 ) {
V_5 -> V_55 [ V_96 ] . V_29 = V_96 ;
V_5 -> V_55 [ V_96 ] . V_41 = V_71 ;
F_65 ( & V_5 -> V_55 [ V_96 ] . V_56 ) ;
F_52 ( & V_5 -> V_55 [ V_96 ] . V_6 , 0 ) ;
}
return V_5 ;
}
static inline void * F_66 ( struct V_97 * V_98 , T_4 V_99 )
{
struct V_1 * V_55 = V_98 -> V_100 ;
return V_99 >= V_50 ? NULL : & V_55 [ V_99 ] ;
}
static void * F_67 ( struct V_97 * V_98 , T_4 * V_99 )
{
return * V_99 ? F_66 ( V_98 , * V_99 - 1 ) : V_101 ;
}
static void * F_68 ( struct V_97 * V_98 , void * V_102 , T_4 * V_99 )
{
V_102 = F_66 ( V_98 , * V_99 ) ;
if ( V_102 )
++ * V_99 ;
return V_102 ;
}
static void F_69 ( struct V_97 * V_98 , void * V_102 )
{
}
static char F_70 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_41 ) {
case V_60 : return 'V' ;
case V_59 : return 'S' ;
case V_43 : return 'W' ;
case V_64 : return V_2 -> V_44 ? 'A' : 'R' ;
case V_42 : return 'X' ;
default:
return 'U' ;
}
}
static int F_71 ( struct V_97 * V_98 , void * V_102 )
{
if ( V_102 == V_101 )
F_72 ( V_98 , L_2
L_3 ) ;
else {
char V_103 [ 60 ] ;
struct V_1 * V_2 = V_102 ;
F_37 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_41 == V_42 )
V_103 [ 0 ] = '\0' ;
else
sprintf ( V_103 , V_2 -> V_15 ? L_4 : L_5 , V_2 -> V_13 ) ;
F_73 ( V_98 , L_6 ,
V_2 -> V_29 , V_103 , V_2 -> V_37 ,
V_2 -> V_3 & V_104 , F_1 ( V_2 ) , V_2 -> V_35 ,
F_70 ( V_2 ) , F_40 ( & V_2 -> V_6 ) ,
V_2 -> V_18 ? V_2 -> V_18 -> V_62 -> V_105 : L_7 ) ;
F_38 ( & V_2 -> V_56 ) ;
}
return 0 ;
}
static int F_74 ( struct V_106 * V_106 , struct V_107 * V_107 )
{
int V_108 = F_75 ( V_107 , & V_109 ) ;
if ( ! V_108 ) {
struct V_19 * V_20 = V_106 -> V_110 ;
struct V_97 * V_98 = V_107 -> V_111 ;
V_98 -> V_100 = V_20 -> V_54 -> V_55 ;
}
return V_108 ;
}
