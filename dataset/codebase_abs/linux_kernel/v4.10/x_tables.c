int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_3 ( & V_2 -> V_7 , & V_5 [ V_3 ] . V_2 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return 0 ;
}
void
F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_6 ( & V_2 -> V_7 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
int
F_7 ( struct V_1 * V_2 , unsigned int V_8 )
{
unsigned int V_9 ;
int V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = F_1 ( & V_2 [ V_9 ] ) ;
if ( V_10 )
goto V_10;
}
return V_10 ;
V_10:
if ( V_9 > 0 )
F_8 ( V_2 , V_9 ) ;
return V_10 ;
}
void
F_8 ( struct V_1 * V_2 , unsigned int V_8 )
{
while ( V_8 -- > 0 )
F_5 ( & V_2 [ V_8 ] ) ;
}
int F_9 ( struct V_11 * V_12 )
{
T_1 V_3 = V_12 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_3 ( & V_12 -> V_7 , & V_5 [ V_3 ] . V_12 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return 0 ;
}
void
F_10 ( struct V_11 * V_12 )
{
T_1 V_3 = V_12 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_6 ( & V_12 -> V_7 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
int
F_11 ( struct V_11 * V_12 , unsigned int V_8 )
{
unsigned int V_9 ;
int V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = F_9 ( & V_12 [ V_9 ] ) ;
if ( V_10 )
goto V_10;
}
return V_10 ;
V_10:
if ( V_9 > 0 )
F_12 ( V_12 , V_9 ) ;
return V_10 ;
}
void
F_12 ( struct V_11 * V_12 , unsigned int V_8 )
{
while ( V_8 -- > 0 )
F_10 ( & V_12 [ V_8 ] ) ;
}
struct V_11 * F_13 ( T_2 V_3 , const char * V_13 , T_2 V_14 )
{
struct V_11 * V_15 ;
int V_10 = - V_16 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (m, &xt[af].match, list) {
if ( strcmp ( V_15 -> V_13 , V_13 ) == 0 ) {
if ( V_15 -> V_14 == V_14 ) {
if ( F_15 ( V_15 -> V_17 ) ) {
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return V_15 ;
}
} else
V_10 = - V_18 ;
}
}
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_3 != V_19 )
return F_13 ( V_19 , V_13 , V_14 ) ;
return F_16 ( V_10 ) ;
}
struct V_11 *
F_17 ( T_3 V_20 , const char * V_13 , T_3 V_14 )
{
struct V_11 * V_12 ;
V_12 = F_13 ( V_20 , V_13 , V_14 ) ;
if ( F_18 ( V_12 ) ) {
F_19 ( L_1 , V_21 [ V_20 ] , V_13 ) ;
V_12 = F_13 ( V_20 , V_13 , V_14 ) ;
}
return V_12 ;
}
struct V_1 * F_20 ( T_2 V_3 , const char * V_13 , T_2 V_14 )
{
struct V_1 * V_22 ;
int V_10 = - V_16 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &xt[af].target, list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 ) {
if ( V_22 -> V_14 == V_14 ) {
if ( F_15 ( V_22 -> V_17 ) ) {
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return V_22 ;
}
} else
V_10 = - V_18 ;
}
}
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_3 != V_19 )
return F_20 ( V_19 , V_13 , V_14 ) ;
return F_16 ( V_10 ) ;
}
struct V_1 * F_21 ( T_2 V_3 , const char * V_13 , T_2 V_14 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_3 , V_13 , V_14 ) ;
if ( F_18 ( V_2 ) ) {
F_19 ( L_1 , V_21 [ V_3 ] , V_13 ) ;
V_2 = F_20 ( V_3 , V_13 , V_14 ) ;
}
return V_2 ;
}
static int F_22 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int * V_23 )
{
const struct V_11 * V_15 ;
int V_24 = 0 ;
F_14 (m, &xt[af].match, list) {
if ( strcmp ( V_15 -> V_13 , V_13 ) == 0 ) {
if ( V_15 -> V_14 > * V_23 )
* V_23 = V_15 -> V_14 ;
if ( V_15 -> V_14 == V_14 )
V_24 = 1 ;
}
}
if ( V_3 != V_19 && ! V_24 )
return F_22 ( V_19 , V_13 , V_14 , V_23 ) ;
return V_24 ;
}
static int F_23 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int * V_23 )
{
const struct V_1 * V_22 ;
int V_24 = 0 ;
F_14 (t, &xt[af].target, list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 ) {
if ( V_22 -> V_14 > * V_23 )
* V_23 = V_22 -> V_14 ;
if ( V_22 -> V_14 == V_14 )
V_24 = 1 ;
}
}
if ( V_3 != V_19 && ! V_24 )
return F_23 ( V_19 , V_13 , V_14 , V_23 ) ;
return V_24 ;
}
int F_24 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int V_2 ,
int * V_10 )
{
int V_24 , V_25 = - 1 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_2 == 1 )
V_24 = F_23 ( V_3 , V_13 , V_14 , & V_25 ) ;
else
V_24 = F_22 ( V_3 , V_13 , V_14 , & V_25 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_25 == - 1 ) {
* V_10 = - V_16 ;
return 0 ;
}
* V_10 = V_25 ;
if ( ! V_24 )
* V_10 = - V_26 ;
return 1 ;
}
static char *
F_25 ( char * V_27 , T_4 V_28 , unsigned int V_29 , T_3 V_20 )
{
static const char * const V_30 [] = {
L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 ,
} ;
static const char * const V_31 [] = {
L_3 , L_4 , L_5 ,
} ;
const char * const * V_32 ;
unsigned int V_9 , V_33 ;
char * V_34 = V_27 ;
bool V_35 = false ;
int V_36 ;
V_32 = ( V_20 == V_37 ) ? V_31 : V_30 ;
V_33 = ( V_20 == V_37 ) ? F_26 ( V_31 ) :
F_26 ( V_30 ) ;
* V_34 = '\0' ;
for ( V_9 = 0 ; V_9 < V_33 ; ++ V_9 ) {
if ( ! ( V_29 & ( 1 << V_9 ) ) )
continue;
V_36 = snprintf ( V_34 , V_28 , L_8 , V_35 ? L_9 : L_10 , V_32 [ V_9 ] ) ;
if ( V_36 > 0 ) {
V_28 -= V_36 ;
V_34 += V_36 ;
}
V_35 = true ;
}
return V_27 ;
}
int F_27 ( struct V_38 * V_39 ,
unsigned int V_28 , T_1 V_40 , bool V_41 )
{
int V_42 ;
if ( F_28 ( V_39 -> V_12 -> V_43 ) != V_28 &&
V_39 -> V_12 -> V_43 != - 1 ) {
F_29 ( L_11
L_12 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
V_39 -> V_12 -> V_14 ,
F_28 ( V_39 -> V_12 -> V_43 ) , V_28 ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_45 != NULL &&
strcmp ( V_39 -> V_12 -> V_45 , V_39 -> V_45 ) != 0 ) {
F_29 ( L_13 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
V_39 -> V_12 -> V_45 , V_39 -> V_45 ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_46 && ( V_39 -> V_47 & ~ V_39 -> V_12 -> V_46 ) != 0 ) {
char V_48 [ 64 ] , V_49 [ 64 ] ;
F_29 ( L_14
L_15 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
F_25 ( V_48 , sizeof( V_48 ) , V_39 -> V_47 ,
V_39 -> V_4 ) ,
F_25 ( V_49 , sizeof( V_49 ) , V_39 -> V_12 -> V_46 ,
V_39 -> V_4 ) ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_40 && ( V_39 -> V_12 -> V_40 != V_40 || V_41 ) ) {
F_29 ( L_16 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
V_39 -> V_12 -> V_40 ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_50 != NULL ) {
V_42 = V_39 -> V_12 -> V_50 ( V_39 ) ;
if ( V_42 < 0 )
return V_42 ;
else if ( V_42 > 0 )
return - V_51 ;
}
return 0 ;
}
static int F_30 ( const char * V_12 , const char * V_2 ,
const T_4 V_52 )
{
const struct V_53 * V_54 ;
int V_55 = V_2 - V_12 ;
if ( V_55 == 0 )
return 0 ;
V_54 = (struct V_53 * ) V_12 ;
do {
if ( ( unsigned long ) V_54 % V_52 )
return - V_44 ;
if ( V_55 < ( int ) sizeof( struct V_53 ) )
return - V_44 ;
if ( V_54 -> V_56 . V_57 < sizeof( struct V_53 ) )
return - V_44 ;
if ( V_54 -> V_56 . V_57 > V_55 )
return - V_44 ;
V_55 -= V_54 -> V_56 . V_57 ;
V_54 = ( ( void * ) ( ( char * ) ( V_54 ) + ( V_54 ) -> V_56 . V_57 ) ) ;
} while ( V_55 > 0 );
return 0 ;
}
int F_31 ( T_1 V_3 , unsigned int V_58 , int V_59 )
{
struct V_60 * V_61 = & V_5 [ V_3 ] ;
if ( ! V_61 -> V_62 ) {
if ( ! V_61 -> V_63 )
return - V_44 ;
V_61 -> V_62 = F_32 ( sizeof( struct V_64 ) * V_61 -> V_63 ) ;
if ( ! V_61 -> V_62 )
return - V_65 ;
V_61 -> V_66 = 0 ;
}
if ( V_61 -> V_66 >= V_61 -> V_63 )
return - V_44 ;
if ( V_61 -> V_66 )
V_59 += V_61 -> V_62 [ V_61 -> V_66 - 1 ] . V_59 ;
V_61 -> V_62 [ V_61 -> V_66 ] . V_58 = V_58 ;
V_61 -> V_62 [ V_61 -> V_66 ] . V_59 = V_59 ;
V_61 -> V_66 ++ ;
return 0 ;
}
void F_33 ( T_1 V_3 )
{
if ( V_5 [ V_3 ] . V_62 ) {
F_34 ( V_5 [ V_3 ] . V_62 ) ;
V_5 [ V_3 ] . V_62 = NULL ;
V_5 [ V_3 ] . V_63 = 0 ;
V_5 [ V_3 ] . V_66 = 0 ;
}
}
int F_35 ( T_1 V_3 , unsigned int V_58 )
{
struct V_64 * V_67 = V_5 [ V_3 ] . V_62 ;
int V_68 , V_69 = 0 , V_70 = V_5 [ V_3 ] . V_66 - 1 ;
while ( V_69 <= V_70 ) {
V_68 = ( V_69 + V_70 ) >> 1 ;
if ( V_58 > V_67 [ V_68 ] . V_58 )
V_69 = V_68 + 1 ;
else if ( V_58 < V_67 [ V_68 ] . V_58 )
V_70 = V_68 - 1 ;
else
return V_68 ? V_67 [ V_68 - 1 ] . V_59 : 0 ;
}
return V_69 ? V_67 [ V_69 - 1 ] . V_59 : 0 ;
}
void F_36 ( T_1 V_3 , unsigned int V_63 )
{
V_5 [ V_3 ] . V_63 = V_63 ;
V_5 [ V_3 ] . V_66 = 0 ;
}
int F_37 ( const struct V_11 * V_12 )
{
T_5 V_71 = V_12 -> V_72 ? : V_12 -> V_43 ;
return F_28 ( V_12 -> V_43 ) - F_38 ( V_71 ) ;
}
void F_39 ( struct V_53 * V_15 , void * * V_73 ,
unsigned int * V_28 )
{
const struct V_11 * V_12 = V_15 -> V_56 . V_74 . V_12 ;
struct V_75 * V_76 = (struct V_75 * ) V_15 ;
int V_77 , V_78 = F_37 ( V_12 ) ;
T_5 V_79 = V_76 -> V_56 . V_80 . V_57 ;
char V_13 [ sizeof( V_15 -> V_56 . V_80 . V_13 ) ] ;
V_15 = * V_73 ;
memcpy ( V_15 , V_76 , sizeof( * V_76 ) ) ;
if ( V_12 -> V_81 )
V_12 -> V_81 ( V_15 -> V_82 , V_76 -> V_82 ) ;
else
memcpy ( V_15 -> V_82 , V_76 -> V_82 , V_79 - sizeof( * V_76 ) ) ;
V_77 = F_28 ( V_12 -> V_43 ) - V_12 -> V_43 ;
if ( V_77 > 0 )
memset ( V_15 -> V_82 + V_12 -> V_43 , 0 , V_77 ) ;
V_79 += V_78 ;
V_15 -> V_56 . V_80 . V_57 = V_79 ;
F_40 ( V_13 , V_12 -> V_13 , sizeof( V_13 ) ) ;
F_41 ( V_12 -> V_17 ) ;
strncpy ( V_15 -> V_56 . V_80 . V_13 , V_13 , sizeof( V_15 -> V_56 . V_80 . V_13 ) ) ;
* V_28 += V_78 ;
* V_73 += V_79 ;
}
int F_42 ( const struct V_53 * V_15 ,
void T_6 * * V_73 , unsigned int * V_28 )
{
const struct V_11 * V_12 = V_15 -> V_56 . V_74 . V_12 ;
struct V_75 T_6 * V_76 = * V_73 ;
int V_78 = F_37 ( V_12 ) ;
T_5 V_79 = V_15 -> V_56 . V_80 . V_57 - V_78 ;
if ( F_43 ( V_76 , V_15 , sizeof( * V_76 ) ) ||
F_44 ( V_79 , & V_76 -> V_56 . V_80 . V_57 ) ||
F_43 ( V_76 -> V_56 . V_80 . V_13 , V_15 -> V_56 . V_74 . V_12 -> V_13 ,
strlen ( V_15 -> V_56 . V_74 . V_12 -> V_13 ) + 1 ) )
return - V_83 ;
if ( V_12 -> V_84 ) {
if ( V_12 -> V_84 ( ( void T_6 * ) V_76 -> V_82 , V_15 -> V_82 ) )
return - V_83 ;
} else {
if ( F_43 ( V_76 -> V_82 , V_15 -> V_82 , V_79 - sizeof( * V_76 ) ) )
return - V_83 ;
}
* V_28 -= V_78 ;
* V_73 += V_79 ;
return 0 ;
}
int F_45 ( const void * V_85 , const char * V_86 ,
unsigned int V_87 ,
unsigned int V_88 )
{
long V_89 = V_86 - ( const char * ) V_85 ;
const struct V_90 * V_22 ;
const char * V_91 = V_85 ;
if ( V_87 < V_89 )
return - V_44 ;
if ( V_87 + sizeof( * V_22 ) > V_88 )
return - V_44 ;
V_22 = ( void * ) ( V_91 + V_87 ) ;
if ( V_22 -> V_56 . V_92 < sizeof( * V_22 ) )
return - V_44 ;
if ( V_87 + V_22 -> V_56 . V_92 > V_88 )
return - V_44 ;
if ( strcmp ( V_22 -> V_56 . V_80 . V_13 , V_93 ) == 0 &&
F_38 ( V_87 + sizeof( struct V_94 ) ) != V_88 )
return - V_44 ;
F_46 ( sizeof( struct V_75 ) != sizeof( struct V_53 ) ) ;
return F_30 ( V_86 , V_85 + V_87 ,
F_47 ( struct V_75 ) ) ;
}
int F_48 ( const void * V_85 ,
const char * V_86 ,
unsigned int V_87 ,
unsigned int V_88 )
{
long V_89 = V_86 - ( const char * ) V_85 ;
const struct V_95 * V_22 ;
const char * V_91 = V_85 ;
if ( V_87 < V_89 )
return - V_44 ;
if ( V_87 + sizeof( * V_22 ) > V_88 )
return - V_44 ;
V_22 = ( void * ) ( V_91 + V_87 ) ;
if ( V_22 -> V_56 . V_92 < sizeof( * V_22 ) )
return - V_44 ;
if ( V_87 + V_22 -> V_56 . V_92 > V_88 )
return - V_44 ;
if ( strcmp ( V_22 -> V_56 . V_80 . V_13 , V_93 ) == 0 &&
F_28 ( V_87 + sizeof( struct V_96 ) ) != V_88 )
return - V_44 ;
return F_30 ( V_86 , V_85 + V_87 ,
F_47 ( struct V_53 ) ) ;
}
unsigned int * F_49 ( unsigned int V_28 )
{
unsigned int * V_78 ;
V_78 = F_50 ( V_28 , sizeof( unsigned int ) , V_97 | V_98 ) ;
if ( V_78 )
return V_78 ;
if ( V_28 < ( V_99 / sizeof( unsigned int ) ) )
V_78 = F_32 ( V_28 * sizeof( unsigned int ) ) ;
return V_78 ;
}
bool F_51 ( const unsigned int * V_100 ,
unsigned int V_2 , unsigned int V_28 )
{
int V_15 , V_101 = 0 , V_102 = V_28 ;
while ( V_102 > V_101 ) {
V_15 = ( V_101 + V_102 ) / 2u ;
if ( V_100 [ V_15 ] > V_2 )
V_102 = V_15 ;
else if ( V_100 [ V_15 ] < V_2 )
V_101 = V_15 + 1 ;
else
return true ;
}
return false ;
}
int F_52 ( struct V_103 * V_39 ,
unsigned int V_28 , T_1 V_40 , bool V_41 )
{
int V_42 ;
if ( F_28 ( V_39 -> V_2 -> V_104 ) != V_28 ) {
F_29 ( L_17
L_12 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_14 ,
F_28 ( V_39 -> V_2 -> V_104 ) , V_28 ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_45 != NULL &&
strcmp ( V_39 -> V_2 -> V_45 , V_39 -> V_45 ) != 0 ) {
F_29 ( L_18 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_45 , V_39 -> V_45 ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_46 && ( V_39 -> V_47 & ~ V_39 -> V_2 -> V_46 ) != 0 ) {
char V_48 [ 64 ] , V_49 [ 64 ] ;
F_29 ( L_19
L_20 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
F_25 ( V_48 , sizeof( V_48 ) , V_39 -> V_47 ,
V_39 -> V_4 ) ,
F_25 ( V_49 , sizeof( V_49 ) , V_39 -> V_2 -> V_46 ,
V_39 -> V_4 ) ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_40 && ( V_39 -> V_2 -> V_40 != V_40 || V_41 ) ) {
F_29 ( L_21 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_40 ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_50 != NULL ) {
V_42 = V_39 -> V_2 -> V_50 ( V_39 ) ;
if ( V_42 < 0 )
return V_42 ;
else if ( V_42 > 0 )
return - V_51 ;
}
return 0 ;
}
void * F_53 ( const void T_6 * V_80 , unsigned int V_105 ,
struct V_106 * V_107 , bool V_108 )
{
void * V_109 ;
T_7 V_28 ;
#ifdef F_54
if ( V_108 ) {
struct V_110 V_111 ;
if ( V_105 <= sizeof( V_111 ) )
return F_16 ( - V_44 ) ;
V_105 -= sizeof( V_111 ) ;
if ( F_55 ( & V_111 , V_80 , sizeof( V_111 ) ) != 0 )
return F_16 ( - V_83 ) ;
F_40 ( V_107 -> V_13 , V_111 . V_13 , sizeof( V_107 -> V_13 ) ) ;
V_107 -> V_112 = V_111 . V_112 ;
V_80 += sizeof( V_111 ) ;
} else
#endif
{
if ( V_105 <= sizeof( * V_107 ) )
return F_16 ( - V_44 ) ;
V_105 -= sizeof( * V_107 ) ;
if ( F_55 ( V_107 , V_80 , sizeof( * V_107 ) ) != 0 )
return F_16 ( - V_83 ) ;
V_107 -> V_13 [ sizeof( V_107 -> V_13 ) - 1 ] = '\0' ;
V_80 += sizeof( * V_107 ) ;
}
V_28 = sizeof( struct V_113 ) ;
V_28 *= V_107 -> V_112 ;
if ( V_28 != ( T_7 ) V_105 )
return F_16 ( - V_44 ) ;
V_109 = F_32 ( V_105 ) ;
if ( ! V_109 )
return F_16 ( - V_65 ) ;
if ( F_55 ( V_109 , V_80 , V_105 ) == 0 )
return V_109 ;
F_34 ( V_109 ) ;
return F_16 ( - V_83 ) ;
}
int F_56 ( const struct V_1 * V_2 )
{
T_5 V_71 = V_2 -> V_72 ? : V_2 -> V_104 ;
return F_28 ( V_2 -> V_104 ) - F_38 ( V_71 ) ;
}
void F_57 ( struct V_95 * V_22 , void * * V_73 ,
unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_56 . V_74 . V_2 ;
struct V_90 * V_114 = (struct V_90 * ) V_22 ;
int V_77 , V_78 = F_56 ( V_2 ) ;
T_5 V_115 = V_114 -> V_56 . V_80 . V_92 ;
char V_13 [ sizeof( V_22 -> V_56 . V_80 . V_13 ) ] ;
V_22 = * V_73 ;
memcpy ( V_22 , V_114 , sizeof( * V_114 ) ) ;
if ( V_2 -> V_81 )
V_2 -> V_81 ( V_22 -> V_82 , V_114 -> V_82 ) ;
else
memcpy ( V_22 -> V_82 , V_114 -> V_82 , V_115 - sizeof( * V_114 ) ) ;
V_77 = F_28 ( V_2 -> V_104 ) - V_2 -> V_104 ;
if ( V_77 > 0 )
memset ( V_22 -> V_82 + V_2 -> V_104 , 0 , V_77 ) ;
V_115 += V_78 ;
V_22 -> V_56 . V_80 . V_92 = V_115 ;
F_40 ( V_13 , V_2 -> V_13 , sizeof( V_13 ) ) ;
F_41 ( V_2 -> V_17 ) ;
strncpy ( V_22 -> V_56 . V_80 . V_13 , V_13 , sizeof( V_22 -> V_56 . V_80 . V_13 ) ) ;
* V_28 += V_78 ;
* V_73 += V_115 ;
}
int F_58 ( const struct V_95 * V_22 ,
void T_6 * * V_73 , unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_56 . V_74 . V_2 ;
struct V_90 T_6 * V_114 = * V_73 ;
int V_78 = F_56 ( V_2 ) ;
T_5 V_115 = V_22 -> V_56 . V_80 . V_92 - V_78 ;
if ( F_43 ( V_114 , V_22 , sizeof( * V_114 ) ) ||
F_44 ( V_115 , & V_114 -> V_56 . V_80 . V_92 ) ||
F_43 ( V_114 -> V_56 . V_80 . V_13 , V_22 -> V_56 . V_74 . V_2 -> V_13 ,
strlen ( V_22 -> V_56 . V_74 . V_2 -> V_13 ) + 1 ) )
return - V_83 ;
if ( V_2 -> V_84 ) {
if ( V_2 -> V_84 ( ( void T_6 * ) V_114 -> V_82 , V_22 -> V_82 ) )
return - V_83 ;
} else {
if ( F_43 ( V_114 -> V_82 , V_22 -> V_82 , V_115 - sizeof( * V_114 ) ) )
return - V_83 ;
}
* V_28 -= V_78 ;
* V_73 += V_115 ;
return 0 ;
}
struct V_116 * F_59 ( unsigned int V_28 )
{
struct V_116 * V_107 = NULL ;
T_4 V_117 = sizeof( * V_107 ) + V_28 ;
if ( V_117 < sizeof( * V_107 ) )
return NULL ;
if ( ( F_60 ( V_28 ) >> V_118 ) + 2 > V_119 )
return NULL ;
if ( V_117 <= ( V_120 << V_121 ) )
V_107 = F_61 ( V_117 , V_97 | V_98 | V_122 ) ;
if ( ! V_107 ) {
V_107 = F_62 ( V_117 , V_97 | V_98 |
V_122 | V_123 ,
V_124 ) ;
if ( ! V_107 )
return NULL ;
}
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_28 = V_28 ;
return V_107 ;
}
void F_63 ( struct V_116 * V_107 )
{
int V_125 ;
if ( V_107 -> V_126 != NULL ) {
F_64 (cpu)
F_65 ( V_107 -> V_126 [ V_125 ] ) ;
F_65 ( V_107 -> V_126 ) ;
}
F_65 ( V_107 ) ;
}
struct V_127 * F_66 ( struct V_128 * V_128 , T_1 V_3 ,
const char * V_13 )
{
struct V_127 * V_22 , * V_129 = NULL ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 && F_15 ( V_22 -> V_17 ) )
return V_22 ;
if ( V_128 == & V_130 )
goto V_131;
F_14 (t, &init_net.xt.tables[af], list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) )
continue;
if ( ! F_15 ( V_22 -> V_17 ) )
return NULL ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_22 -> V_132 ( V_128 ) != 0 ) {
F_41 ( V_22 -> V_17 ) ;
return NULL ;
}
V_129 = V_22 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
break;
}
if ( ! V_129 )
goto V_131;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 )
return V_22 ;
F_41 ( V_129 -> V_17 ) ;
V_131:
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
void F_67 ( struct V_127 * V_45 )
{
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
}
void F_68 ( T_1 V_3 )
{
F_2 ( & V_5 [ V_3 ] . V_133 ) ;
}
void F_69 ( T_1 V_3 )
{
F_4 ( & V_5 [ V_3 ] . V_133 ) ;
}
static int F_70 ( struct V_116 * V_9 )
{
unsigned int V_28 ;
int V_125 ;
V_28 = sizeof( void * * ) * V_134 ;
if ( V_28 > V_120 )
V_9 -> V_126 = F_71 ( V_28 ) ;
else
V_9 -> V_126 = F_72 ( V_28 , V_97 ) ;
if ( V_9 -> V_126 == NULL )
return - V_65 ;
if ( V_9 -> V_135 == 0 )
return 0 ;
V_28 = sizeof( void * ) * V_9 -> V_135 * 2u ;
F_64 (cpu) {
if ( V_28 > V_120 )
V_9 -> V_126 [ V_125 ] = F_73 ( V_28 ,
F_74 ( V_125 ) ) ;
else
V_9 -> V_126 [ V_125 ] = F_75 ( V_28 ,
V_97 , F_74 ( V_125 ) ) ;
if ( V_9 -> V_126 [ V_125 ] == NULL )
return - V_65 ;
}
return 0 ;
}
struct V_116 *
F_76 ( struct V_127 * V_45 ,
unsigned int V_112 ,
struct V_116 * V_136 ,
int * error )
{
struct V_116 * V_137 ;
int V_42 ;
V_42 = F_70 ( V_136 ) ;
if ( V_42 < 0 ) {
* error = V_42 ;
return NULL ;
}
F_77 () ;
V_137 = V_45 -> V_137 ;
if ( V_112 != V_137 -> V_63 ) {
F_78 ( L_22 ,
V_112 , V_137 -> V_63 ) ;
F_79 () ;
* error = - V_138 ;
return NULL ;
}
V_136 -> V_139 = V_137 -> V_139 ;
F_80 () ;
V_45 -> V_137 = V_136 ;
F_79 () ;
#ifdef F_81
if ( V_140 ) {
struct V_141 * V_142 ;
V_142 = F_82 ( V_143 -> V_144 , V_97 ,
V_145 ) ;
if ( V_142 ) {
F_83 ( V_142 , L_23 ,
V_45 -> V_13 , V_45 -> V_3 ,
V_137 -> V_63 ) ;
F_84 ( V_142 ) ;
}
}
#endif
return V_137 ;
}
struct V_127 * F_85 ( struct V_128 * V_128 ,
const struct V_127 * V_146 ,
struct V_116 * V_147 ,
struct V_116 * V_136 )
{
int V_42 ;
struct V_116 * V_137 ;
struct V_127 * V_22 , * V_45 ;
V_45 = F_86 ( V_146 , sizeof( struct V_127 ) , V_97 ) ;
if ( ! V_45 ) {
V_42 = - V_65 ;
goto V_131;
}
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_22 -> V_13 , V_45 -> V_13 ) == 0 ) {
V_42 = - V_148 ;
goto V_149;
}
}
V_45 -> V_137 = V_147 ;
if ( ! F_76 ( V_45 , 0 , V_136 , & V_42 ) )
goto V_149;
V_137 = V_45 -> V_137 ;
F_78 ( L_24 , V_137 -> V_63 ) ;
V_137 -> V_139 = V_137 -> V_63 ;
F_3 ( & V_45 -> V_7 , & V_128 -> V_5 . V_150 [ V_45 -> V_3 ] ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
return V_45 ;
V_149:
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_87 ( V_45 ) ;
V_131:
return F_16 ( V_42 ) ;
}
void * F_88 ( struct V_127 * V_45 )
{
struct V_116 * V_137 ;
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
V_137 = V_45 -> V_137 ;
F_6 ( & V_45 -> V_7 ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_87 ( V_45 ) ;
return V_137 ;
}
static void * F_89 ( struct V_151 * V_152 , T_8 * V_54 )
{
struct V_153 * V_154 = V_152 -> V_137 ;
struct V_128 * V_128 = F_90 ( V_152 ) ;
T_1 V_3 = V_154 -> V_3 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
return F_91 ( & V_128 -> V_5 . V_150 [ V_3 ] , * V_54 ) ;
}
static void * F_92 ( struct V_151 * V_152 , void * V_155 , T_8 * V_54 )
{
struct V_153 * V_154 = V_152 -> V_137 ;
struct V_128 * V_128 = F_90 ( V_152 ) ;
T_1 V_3 = V_154 -> V_3 ;
return F_93 ( V_155 , & V_128 -> V_5 . V_150 [ V_3 ] , V_54 ) ;
}
static void F_94 ( struct V_151 * V_152 , void * V_155 )
{
struct V_153 * V_154 = V_152 -> V_137 ;
T_1 V_3 = V_154 -> V_3 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
static int F_95 ( struct V_151 * V_152 , void * V_155 )
{
struct V_127 * V_45 = F_96 ( V_155 , struct V_127 , V_7 ) ;
if ( * V_45 -> V_13 )
F_97 ( V_152 , L_25 , V_45 -> V_13 ) ;
return 0 ;
}
static int F_98 ( struct V_156 * V_156 , struct V_157 * V_157 )
{
int V_42 ;
struct V_153 * V_154 ;
V_42 = F_99 ( V_156 , V_157 , & V_158 ,
sizeof( struct V_153 ) ) ;
if ( ! V_42 ) {
V_154 = ( (struct V_151 * ) V_157 -> V_159 ) -> V_137 ;
V_154 -> V_3 = ( unsigned long ) F_100 ( V_156 ) ;
}
return V_42 ;
}
static void * F_101 ( struct V_151 * V_152 , void * V_155 , T_8 * V_160 ,
bool V_161 )
{
static const T_3 V_162 [] = {
[ V_163 ] = V_164 ,
[ V_164 ] = V_165 ,
} ;
struct V_166 * V_167 = V_152 -> V_137 ;
switch ( V_167 -> V_168 ) {
case V_169 :
V_167 -> V_168 = V_163 ;
F_2 ( & V_5 [ V_19 ] . V_6 ) ;
V_167 -> V_170 = V_167 -> V_171 = V_161 ?
& V_5 [ V_19 ] . V_2 : & V_5 [ V_19 ] . V_12 ;
break;
case V_163 :
V_167 -> V_171 = V_167 -> V_171 -> V_172 ;
if ( V_167 -> V_171 != V_167 -> V_170 )
break;
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
F_2 ( & V_5 [ V_167 -> V_20 ] . V_6 ) ;
V_167 -> V_170 = V_167 -> V_171 = V_161 ?
& V_5 [ V_167 -> V_20 ] . V_2 : & V_5 [ V_167 -> V_20 ] . V_12 ;
V_167 -> V_168 = V_162 [ V_167 -> V_168 ] ;
break;
case V_164 :
V_167 -> V_171 = V_167 -> V_171 -> V_172 ;
if ( V_167 -> V_171 != V_167 -> V_170 )
break;
default:
return NULL ;
}
if ( V_160 != NULL )
++ * V_160 ;
return V_167 ;
}
static void * F_102 ( struct V_151 * V_152 , T_8 * V_54 ,
bool V_161 )
{
struct V_166 * V_167 = V_152 -> V_137 ;
unsigned int V_173 ;
V_167 -> V_168 = V_169 ;
for ( V_173 = 0 ; V_173 < * V_54 ; ++ V_173 )
if ( F_101 ( V_152 , NULL , NULL , V_161 ) == NULL )
return NULL ;
return V_167 ;
}
static void F_103 ( struct V_151 * V_152 , void * V_155 )
{
struct V_166 * V_167 = V_152 -> V_137 ;
switch ( V_167 -> V_168 ) {
case V_163 :
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
break;
case V_164 :
F_4 ( & V_5 [ V_167 -> V_20 ] . V_6 ) ;
break;
}
}
static void * F_104 ( struct V_151 * V_152 , T_8 * V_54 )
{
return F_102 ( V_152 , V_54 , false ) ;
}
static void * F_105 ( struct V_151 * V_152 , void * V_155 , T_8 * V_160 )
{
return F_101 ( V_152 , V_155 , V_160 , false ) ;
}
static int F_106 ( struct V_151 * V_152 , void * V_155 )
{
const struct V_166 * V_167 = V_152 -> V_137 ;
const struct V_11 * V_12 ;
switch ( V_167 -> V_168 ) {
case V_163 :
case V_164 :
if ( V_167 -> V_171 == V_167 -> V_170 )
return 0 ;
V_12 = F_96 ( V_167 -> V_171 , struct V_11 , V_7 ) ;
if ( * V_12 -> V_13 )
F_97 ( V_152 , L_25 , V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_107 ( struct V_156 * V_156 , struct V_157 * V_157 )
{
struct V_166 * V_167 ;
V_167 = F_108 ( V_157 , & V_174 , sizeof( * V_167 ) ) ;
if ( ! V_167 )
return - V_65 ;
V_167 -> V_20 = ( unsigned long ) F_100 ( V_156 ) ;
return 0 ;
}
static void * F_109 ( struct V_151 * V_152 , T_8 * V_54 )
{
return F_102 ( V_152 , V_54 , true ) ;
}
static void * F_110 ( struct V_151 * V_152 , void * V_155 , T_8 * V_160 )
{
return F_101 ( V_152 , V_155 , V_160 , true ) ;
}
static int F_111 ( struct V_151 * V_152 , void * V_155 )
{
const struct V_166 * V_167 = V_152 -> V_137 ;
const struct V_1 * V_2 ;
switch ( V_167 -> V_168 ) {
case V_163 :
case V_164 :
if ( V_167 -> V_171 == V_167 -> V_170 )
return 0 ;
V_2 = F_96 ( V_167 -> V_171 , struct V_1 , V_7 ) ;
if ( * V_2 -> V_13 )
F_97 ( V_152 , L_25 , V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_112 ( struct V_156 * V_156 , struct V_157 * V_157 )
{
struct V_166 * V_167 ;
V_167 = F_108 ( V_157 , & V_175 , sizeof( * V_167 ) ) ;
if ( ! V_167 )
return - V_65 ;
V_167 -> V_20 = ( unsigned long ) F_100 ( V_156 ) ;
return 0 ;
}
struct V_176 *
F_113 ( const struct V_127 * V_45 , T_9 * V_177 )
{
unsigned int V_47 = V_45 -> V_178 ;
T_3 V_9 , V_179 = F_114 ( V_47 ) ;
T_3 V_180 ;
struct V_176 * V_181 ;
if ( ! V_179 )
return F_16 ( - V_44 ) ;
V_181 = F_50 ( V_179 , sizeof( * V_181 ) , V_97 ) ;
if ( V_181 == NULL )
return F_16 ( - V_65 ) ;
for ( V_9 = 0 , V_180 = 0 ; V_9 < V_179 && V_47 != 0 ;
V_47 >>= 1 , ++ V_180 ) {
if ( ! ( V_47 & 1 ) )
continue;
V_181 [ V_9 ] . V_182 = V_177 ;
V_181 [ V_9 ] . V_183 = V_45 -> V_3 ;
V_181 [ V_9 ] . V_180 = V_180 ;
V_181 [ V_9 ] . V_184 = V_45 -> V_184 ;
++ V_9 ;
}
return V_181 ;
}
int F_115 ( struct V_128 * V_128 , T_1 V_3 )
{
#ifdef F_116
char V_27 [ V_185 ] ;
struct V_186 * V_187 ;
T_10 V_188 ;
T_11 V_189 ;
#endif
if ( V_3 >= F_26 ( V_21 ) )
return - V_44 ;
#ifdef F_116
V_188 = F_117 ( V_128 -> V_190 , 0 ) ;
V_189 = F_118 ( V_128 -> V_190 , 0 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_191 , sizeof( V_27 ) ) ;
V_187 = F_120 ( V_27 , 0440 , V_128 -> V_192 , & V_193 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_187 )
goto V_131;
if ( F_121 ( V_188 ) && F_122 ( V_189 ) )
F_123 ( V_187 , V_188 , V_189 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_194 , sizeof( V_27 ) ) ;
V_187 = F_120 ( V_27 , 0440 , V_128 -> V_192 , & V_195 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_187 )
goto V_196;
if ( F_121 ( V_188 ) && F_122 ( V_189 ) )
F_123 ( V_187 , V_188 , V_189 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_197 , sizeof( V_27 ) ) ;
V_187 = F_120 ( V_27 , 0440 , V_128 -> V_192 , & V_198 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_187 )
goto V_199;
if ( F_121 ( V_188 ) && F_122 ( V_189 ) )
F_123 ( V_187 , V_188 , V_189 ) ;
#endif
return 0 ;
#ifdef F_116
V_199:
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_194 , sizeof( V_27 ) ) ;
F_124 ( V_27 , V_128 -> V_192 ) ;
V_196:
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_191 , sizeof( V_27 ) ) ;
F_124 ( V_27 , V_128 -> V_192 ) ;
V_131:
return - 1 ;
#endif
}
void F_125 ( struct V_128 * V_128 , T_1 V_3 )
{
#ifdef F_116
char V_27 [ V_185 ] ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_191 , sizeof( V_27 ) ) ;
F_124 ( V_27 , V_128 -> V_192 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_197 , sizeof( V_27 ) ) ;
F_124 ( V_27 , V_128 -> V_192 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_119 ( V_27 , V_194 , sizeof( V_27 ) ) ;
F_124 ( V_27 , V_128 -> V_192 ) ;
#endif
}
bool F_126 ( struct V_200 * V_201 ,
struct V_113 * V_202 )
{
F_46 ( V_203 < ( sizeof( * V_202 ) * 2 ) ) ;
if ( V_134 <= 1 )
return true ;
if ( ! V_201 -> V_109 ) {
V_201 -> V_109 = F_127 ( V_203 ,
V_203 ) ;
if ( ! V_201 -> V_109 )
return false ;
}
V_202 -> V_204 = ( V_205 unsigned long ) ( V_201 -> V_109 + V_201 -> V_78 ) ;
V_201 -> V_78 += sizeof( * V_202 ) ;
if ( V_201 -> V_78 > ( V_203 - sizeof( * V_202 ) ) ) {
V_201 -> V_109 = NULL ;
V_201 -> V_78 = 0 ;
}
return true ;
}
void F_128 ( struct V_113 * V_206 )
{
unsigned long V_204 = V_206 -> V_204 ;
if ( V_134 > 1 && ( V_204 & ( V_203 - 1 ) ) == 0 )
F_129 ( ( void V_207 * ) V_204 ) ;
}
static int T_12 F_130 ( struct V_128 * V_128 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_208 ; V_9 ++ )
F_131 ( & V_128 -> V_5 . V_150 [ V_9 ] ) ;
return 0 ;
}
static int T_13 F_132 ( void )
{
unsigned int V_9 ;
int V_209 ;
F_64 (i) {
F_133 ( & F_134 ( V_210 , V_9 ) ) ;
}
V_5 = F_61 ( sizeof( struct V_60 ) * V_208 , V_97 ) ;
if ( ! V_5 )
return - V_65 ;
for ( V_9 = 0 ; V_9 < V_208 ; V_9 ++ ) {
F_135 ( & V_5 [ V_9 ] . V_6 ) ;
#ifdef F_54
F_135 ( & V_5 [ V_9 ] . V_133 ) ;
V_5 [ V_9 ] . V_62 = NULL ;
#endif
F_131 ( & V_5 [ V_9 ] . V_2 ) ;
F_131 ( & V_5 [ V_9 ] . V_12 ) ;
}
V_209 = F_136 ( & V_211 ) ;
if ( V_209 < 0 )
F_87 ( V_5 ) ;
return V_209 ;
}
static void T_14 F_137 ( void )
{
F_138 ( & V_211 ) ;
F_87 ( V_5 ) ;
}
