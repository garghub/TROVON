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
V_107 = F_32 ( V_117 ) ;
if ( ! V_107 )
return NULL ;
}
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_28 = V_28 ;
return V_107 ;
}
void F_62 ( struct V_116 * V_107 )
{
int V_123 ;
if ( V_107 -> V_124 != NULL ) {
F_63 (cpu)
F_64 ( V_107 -> V_124 [ V_123 ] ) ;
F_64 ( V_107 -> V_124 ) ;
}
F_64 ( V_107 ) ;
}
struct V_125 * F_65 ( struct V_126 * V_126 , T_1 V_3 ,
const char * V_13 )
{
struct V_125 * V_22 , * V_127 = NULL ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 && F_15 ( V_22 -> V_17 ) )
return V_22 ;
if ( V_126 == & V_128 )
goto V_129;
F_14 (t, &init_net.xt.tables[af], list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) )
continue;
if ( ! F_15 ( V_22 -> V_17 ) )
return NULL ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_22 -> V_130 ( V_126 ) != 0 ) {
F_41 ( V_22 -> V_17 ) ;
return NULL ;
}
V_127 = V_22 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
break;
}
if ( ! V_127 )
goto V_129;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 )
return V_22 ;
F_41 ( V_127 -> V_17 ) ;
V_129:
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
void F_66 ( struct V_125 * V_45 )
{
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
}
void F_67 ( T_1 V_3 )
{
F_2 ( & V_5 [ V_3 ] . V_131 ) ;
}
void F_68 ( T_1 V_3 )
{
F_4 ( & V_5 [ V_3 ] . V_131 ) ;
}
static int F_69 ( struct V_116 * V_9 )
{
unsigned int V_28 ;
int V_123 ;
V_28 = sizeof( void * * ) * V_132 ;
if ( V_28 > V_120 )
V_9 -> V_124 = F_70 ( V_28 ) ;
else
V_9 -> V_124 = F_71 ( V_28 , V_97 ) ;
if ( V_9 -> V_124 == NULL )
return - V_65 ;
if ( V_9 -> V_133 == 0 )
return 0 ;
V_28 = sizeof( void * ) * V_9 -> V_133 * 2u ;
F_63 (cpu) {
if ( V_28 > V_120 )
V_9 -> V_124 [ V_123 ] = F_72 ( V_28 ,
F_73 ( V_123 ) ) ;
else
V_9 -> V_124 [ V_123 ] = F_74 ( V_28 ,
V_97 , F_73 ( V_123 ) ) ;
if ( V_9 -> V_124 [ V_123 ] == NULL )
return - V_65 ;
}
return 0 ;
}
struct V_116 *
F_75 ( struct V_125 * V_45 ,
unsigned int V_112 ,
struct V_116 * V_134 ,
int * error )
{
struct V_116 * V_135 ;
int V_42 ;
V_42 = F_69 ( V_134 ) ;
if ( V_42 < 0 ) {
* error = V_42 ;
return NULL ;
}
F_76 () ;
V_135 = V_45 -> V_135 ;
if ( V_112 != V_135 -> V_63 ) {
F_77 ( L_22 ,
V_112 , V_135 -> V_63 ) ;
F_78 () ;
* error = - V_136 ;
return NULL ;
}
V_134 -> V_137 = V_135 -> V_137 ;
F_79 () ;
V_45 -> V_135 = V_134 ;
F_78 () ;
#ifdef F_80
if ( V_138 ) {
struct V_139 * V_140 ;
V_140 = F_81 ( V_141 -> V_142 , V_97 ,
V_143 ) ;
if ( V_140 ) {
F_82 ( V_140 , L_23 ,
V_45 -> V_13 , V_45 -> V_3 ,
V_135 -> V_63 ) ;
F_83 ( V_140 ) ;
}
}
#endif
return V_135 ;
}
struct V_125 * F_84 ( struct V_126 * V_126 ,
const struct V_125 * V_144 ,
struct V_116 * V_145 ,
struct V_116 * V_134 )
{
int V_42 ;
struct V_116 * V_135 ;
struct V_125 * V_22 , * V_45 ;
V_45 = F_85 ( V_144 , sizeof( struct V_125 ) , V_97 ) ;
if ( ! V_45 ) {
V_42 = - V_65 ;
goto V_129;
}
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_22 -> V_13 , V_45 -> V_13 ) == 0 ) {
V_42 = - V_146 ;
goto V_147;
}
}
V_45 -> V_135 = V_145 ;
if ( ! F_75 ( V_45 , 0 , V_134 , & V_42 ) )
goto V_147;
V_135 = V_45 -> V_135 ;
F_77 ( L_24 , V_135 -> V_63 ) ;
V_135 -> V_137 = V_135 -> V_63 ;
F_3 ( & V_45 -> V_7 , & V_126 -> V_5 . V_148 [ V_45 -> V_3 ] ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
return V_45 ;
V_147:
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_86 ( V_45 ) ;
V_129:
return F_16 ( V_42 ) ;
}
void * F_87 ( struct V_125 * V_45 )
{
struct V_116 * V_135 ;
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
V_135 = V_45 -> V_135 ;
F_6 ( & V_45 -> V_7 ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_86 ( V_45 ) ;
return V_135 ;
}
static void * F_88 ( struct V_149 * V_150 , T_8 * V_54 )
{
struct V_151 * V_152 = V_150 -> V_135 ;
struct V_126 * V_126 = F_89 ( V_150 ) ;
T_1 V_3 = V_152 -> V_3 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
return F_90 ( & V_126 -> V_5 . V_148 [ V_3 ] , * V_54 ) ;
}
static void * F_91 ( struct V_149 * V_150 , void * V_153 , T_8 * V_54 )
{
struct V_151 * V_152 = V_150 -> V_135 ;
struct V_126 * V_126 = F_89 ( V_150 ) ;
T_1 V_3 = V_152 -> V_3 ;
return F_92 ( V_153 , & V_126 -> V_5 . V_148 [ V_3 ] , V_54 ) ;
}
static void F_93 ( struct V_149 * V_150 , void * V_153 )
{
struct V_151 * V_152 = V_150 -> V_135 ;
T_1 V_3 = V_152 -> V_3 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
static int F_94 ( struct V_149 * V_150 , void * V_153 )
{
struct V_125 * V_45 = F_95 ( V_153 , struct V_125 , V_7 ) ;
if ( * V_45 -> V_13 )
F_96 ( V_150 , L_25 , V_45 -> V_13 ) ;
return 0 ;
}
static int F_97 ( struct V_154 * V_154 , struct V_155 * V_155 )
{
int V_42 ;
struct V_151 * V_152 ;
V_42 = F_98 ( V_154 , V_155 , & V_156 ,
sizeof( struct V_151 ) ) ;
if ( ! V_42 ) {
V_152 = ( (struct V_149 * ) V_155 -> V_157 ) -> V_135 ;
V_152 -> V_3 = ( unsigned long ) F_99 ( V_154 ) ;
}
return V_42 ;
}
static void * F_100 ( struct V_149 * V_150 , void * V_153 , T_8 * V_158 ,
bool V_159 )
{
static const T_3 V_160 [] = {
[ V_161 ] = V_162 ,
[ V_162 ] = V_163 ,
} ;
struct V_164 * V_165 = V_150 -> V_135 ;
switch ( V_165 -> V_166 ) {
case V_167 :
V_165 -> V_166 = V_161 ;
F_2 ( & V_5 [ V_19 ] . V_6 ) ;
V_165 -> V_168 = V_165 -> V_169 = V_159 ?
& V_5 [ V_19 ] . V_2 : & V_5 [ V_19 ] . V_12 ;
break;
case V_161 :
V_165 -> V_169 = V_165 -> V_169 -> V_170 ;
if ( V_165 -> V_169 != V_165 -> V_168 )
break;
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
F_2 ( & V_5 [ V_165 -> V_20 ] . V_6 ) ;
V_165 -> V_168 = V_165 -> V_169 = V_159 ?
& V_5 [ V_165 -> V_20 ] . V_2 : & V_5 [ V_165 -> V_20 ] . V_12 ;
V_165 -> V_166 = V_160 [ V_165 -> V_166 ] ;
break;
case V_162 :
V_165 -> V_169 = V_165 -> V_169 -> V_170 ;
if ( V_165 -> V_169 != V_165 -> V_168 )
break;
default:
return NULL ;
}
if ( V_158 != NULL )
++ * V_158 ;
return V_165 ;
}
static void * F_101 ( struct V_149 * V_150 , T_8 * V_54 ,
bool V_159 )
{
struct V_164 * V_165 = V_150 -> V_135 ;
unsigned int V_171 ;
V_165 -> V_166 = V_167 ;
for ( V_171 = 0 ; V_171 < * V_54 ; ++ V_171 )
if ( F_100 ( V_150 , NULL , NULL , V_159 ) == NULL )
return NULL ;
return V_165 ;
}
static void F_102 ( struct V_149 * V_150 , void * V_153 )
{
struct V_164 * V_165 = V_150 -> V_135 ;
switch ( V_165 -> V_166 ) {
case V_161 :
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
break;
case V_162 :
F_4 ( & V_5 [ V_165 -> V_20 ] . V_6 ) ;
break;
}
}
static void * F_103 ( struct V_149 * V_150 , T_8 * V_54 )
{
return F_101 ( V_150 , V_54 , false ) ;
}
static void * F_104 ( struct V_149 * V_150 , void * V_153 , T_8 * V_158 )
{
return F_100 ( V_150 , V_153 , V_158 , false ) ;
}
static int F_105 ( struct V_149 * V_150 , void * V_153 )
{
const struct V_164 * V_165 = V_150 -> V_135 ;
const struct V_11 * V_12 ;
switch ( V_165 -> V_166 ) {
case V_161 :
case V_162 :
if ( V_165 -> V_169 == V_165 -> V_168 )
return 0 ;
V_12 = F_95 ( V_165 -> V_169 , struct V_11 , V_7 ) ;
if ( * V_12 -> V_13 )
F_96 ( V_150 , L_25 , V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_106 ( struct V_154 * V_154 , struct V_155 * V_155 )
{
struct V_164 * V_165 ;
V_165 = F_107 ( V_155 , & V_172 , sizeof( * V_165 ) ) ;
if ( ! V_165 )
return - V_65 ;
V_165 -> V_20 = ( unsigned long ) F_99 ( V_154 ) ;
return 0 ;
}
static void * F_108 ( struct V_149 * V_150 , T_8 * V_54 )
{
return F_101 ( V_150 , V_54 , true ) ;
}
static void * F_109 ( struct V_149 * V_150 , void * V_153 , T_8 * V_158 )
{
return F_100 ( V_150 , V_153 , V_158 , true ) ;
}
static int F_110 ( struct V_149 * V_150 , void * V_153 )
{
const struct V_164 * V_165 = V_150 -> V_135 ;
const struct V_1 * V_2 ;
switch ( V_165 -> V_166 ) {
case V_161 :
case V_162 :
if ( V_165 -> V_169 == V_165 -> V_168 )
return 0 ;
V_2 = F_95 ( V_165 -> V_169 , struct V_1 , V_7 ) ;
if ( * V_2 -> V_13 )
F_96 ( V_150 , L_25 , V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_111 ( struct V_154 * V_154 , struct V_155 * V_155 )
{
struct V_164 * V_165 ;
V_165 = F_107 ( V_155 , & V_173 , sizeof( * V_165 ) ) ;
if ( ! V_165 )
return - V_65 ;
V_165 -> V_20 = ( unsigned long ) F_99 ( V_154 ) ;
return 0 ;
}
struct V_174 *
F_112 ( const struct V_125 * V_45 , T_9 * V_175 )
{
unsigned int V_47 = V_45 -> V_176 ;
T_3 V_9 , V_177 = F_113 ( V_47 ) ;
T_3 V_178 ;
struct V_174 * V_179 ;
if ( ! V_177 )
return F_16 ( - V_44 ) ;
V_179 = F_50 ( V_177 , sizeof( * V_179 ) , V_97 ) ;
if ( V_179 == NULL )
return F_16 ( - V_65 ) ;
for ( V_9 = 0 , V_178 = 0 ; V_9 < V_177 && V_47 != 0 ;
V_47 >>= 1 , ++ V_178 ) {
if ( ! ( V_47 & 1 ) )
continue;
V_179 [ V_9 ] . V_180 = V_175 ;
V_179 [ V_9 ] . V_181 = V_45 -> V_3 ;
V_179 [ V_9 ] . V_178 = V_178 ;
V_179 [ V_9 ] . V_182 = V_45 -> V_182 ;
++ V_9 ;
}
return V_179 ;
}
int F_114 ( struct V_126 * V_126 , T_1 V_3 )
{
#ifdef F_115
char V_27 [ V_183 ] ;
struct V_184 * V_185 ;
T_10 V_186 ;
T_11 V_187 ;
#endif
if ( V_3 >= F_26 ( V_21 ) )
return - V_44 ;
#ifdef F_115
V_186 = F_116 ( V_126 -> V_188 , 0 ) ;
V_187 = F_117 ( V_126 -> V_188 , 0 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_189 , sizeof( V_27 ) ) ;
V_185 = F_119 ( V_27 , 0440 , V_126 -> V_190 , & V_191 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_185 )
goto V_129;
if ( F_120 ( V_186 ) && F_121 ( V_187 ) )
F_122 ( V_185 , V_186 , V_187 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_192 , sizeof( V_27 ) ) ;
V_185 = F_119 ( V_27 , 0440 , V_126 -> V_190 , & V_193 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_185 )
goto V_194;
if ( F_120 ( V_186 ) && F_121 ( V_187 ) )
F_122 ( V_185 , V_186 , V_187 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_195 , sizeof( V_27 ) ) ;
V_185 = F_119 ( V_27 , 0440 , V_126 -> V_190 , & V_196 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_185 )
goto V_197;
if ( F_120 ( V_186 ) && F_121 ( V_187 ) )
F_122 ( V_185 , V_186 , V_187 ) ;
#endif
return 0 ;
#ifdef F_115
V_197:
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_192 , sizeof( V_27 ) ) ;
F_123 ( V_27 , V_126 -> V_190 ) ;
V_194:
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_189 , sizeof( V_27 ) ) ;
F_123 ( V_27 , V_126 -> V_190 ) ;
V_129:
return - 1 ;
#endif
}
void F_124 ( struct V_126 * V_126 , T_1 V_3 )
{
#ifdef F_115
char V_27 [ V_183 ] ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_189 , sizeof( V_27 ) ) ;
F_123 ( V_27 , V_126 -> V_190 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_195 , sizeof( V_27 ) ) ;
F_123 ( V_27 , V_126 -> V_190 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_118 ( V_27 , V_192 , sizeof( V_27 ) ) ;
F_123 ( V_27 , V_126 -> V_190 ) ;
#endif
}
static int T_12 F_125 ( struct V_126 * V_126 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_198 ; V_9 ++ )
F_126 ( & V_126 -> V_5 . V_148 [ V_9 ] ) ;
return 0 ;
}
static int T_13 F_127 ( void )
{
unsigned int V_9 ;
int V_199 ;
F_63 (i) {
F_128 ( & F_129 ( V_200 , V_9 ) ) ;
}
V_5 = F_61 ( sizeof( struct V_60 ) * V_198 , V_97 ) ;
if ( ! V_5 )
return - V_65 ;
for ( V_9 = 0 ; V_9 < V_198 ; V_9 ++ ) {
F_130 ( & V_5 [ V_9 ] . V_6 ) ;
#ifdef F_54
F_130 ( & V_5 [ V_9 ] . V_131 ) ;
V_5 [ V_9 ] . V_62 = NULL ;
#endif
F_126 ( & V_5 [ V_9 ] . V_2 ) ;
F_126 ( & V_5 [ V_9 ] . V_12 ) ;
}
V_199 = F_131 ( & V_201 ) ;
if ( V_199 < 0 )
F_86 ( V_5 ) ;
return V_199 ;
}
static void T_14 F_132 ( void )
{
F_133 ( & V_201 ) ;
F_86 ( V_5 ) ;
}
