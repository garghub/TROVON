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
static int F_22 ( T_4 T_5 * V_23 , T_4 V_24 ,
void T_5 * V_25 , const char * V_13 ,
T_2 T_5 * V_26 , T_2 V_27 )
{
if ( F_23 ( V_24 , V_23 ) )
return - V_28 ;
if ( F_24 ( V_25 , V_13 , strlen ( V_13 ) + 1 ) )
return - V_28 ;
if ( F_23 ( V_27 , V_26 ) )
return - V_28 ;
return 0 ;
}
int F_25 ( void T_5 * V_29 , const void * V_30 ,
int V_31 , int V_24 , int V_32 )
{
V_31 = V_31 ? : V_24 ;
if ( F_24 ( V_29 , V_30 , V_31 ) )
return - V_28 ;
if ( V_31 != V_32 &&
F_26 ( V_29 + V_31 , V_32 - V_31 ) )
return - V_28 ;
return 0 ;
}
int F_27 ( const struct V_33 * V_15 ,
struct V_33 T_5 * V_34 )
{
return F_28 ( V_34 , V_15 , V_12 , 0 ) ||
F_29 ( V_34 , V_15 , V_12 ) ;
}
int F_30 ( const struct V_35 * V_22 ,
struct V_35 T_5 * V_34 )
{
return F_28 ( V_34 , V_22 , V_2 , 0 ) ||
F_29 ( V_34 , V_22 , V_2 ) ;
}
static int F_31 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int * V_36 )
{
const struct V_11 * V_15 ;
int V_37 = 0 ;
F_14 (m, &xt[af].match, list) {
if ( strcmp ( V_15 -> V_13 , V_13 ) == 0 ) {
if ( V_15 -> V_14 > * V_36 )
* V_36 = V_15 -> V_14 ;
if ( V_15 -> V_14 == V_14 )
V_37 = 1 ;
}
}
if ( V_3 != V_19 && ! V_37 )
return F_31 ( V_19 , V_13 , V_14 , V_36 ) ;
return V_37 ;
}
static int F_32 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int * V_36 )
{
const struct V_1 * V_22 ;
int V_37 = 0 ;
F_14 (t, &xt[af].target, list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 ) {
if ( V_22 -> V_14 > * V_36 )
* V_36 = V_22 -> V_14 ;
if ( V_22 -> V_14 == V_14 )
V_37 = 1 ;
}
}
if ( V_3 != V_19 && ! V_37 )
return F_32 ( V_19 , V_13 , V_14 , V_36 ) ;
return V_37 ;
}
int F_33 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int V_2 ,
int * V_10 )
{
int V_37 , V_38 = - 1 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_2 == 1 )
V_37 = F_32 ( V_3 , V_13 , V_14 , & V_38 ) ;
else
V_37 = F_31 ( V_3 , V_13 , V_14 , & V_38 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_38 == - 1 ) {
* V_10 = - V_16 ;
return 0 ;
}
* V_10 = V_38 ;
if ( ! V_37 )
* V_10 = - V_39 ;
return 1 ;
}
static char *
F_34 ( char * V_40 , T_6 V_24 , unsigned int V_41 , T_3 V_20 )
{
static const char * const V_42 [] = {
L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 ,
} ;
static const char * const V_43 [] = {
L_3 , L_4 , L_5 ,
} ;
const char * const * V_44 ;
unsigned int V_9 , V_45 ;
char * V_46 = V_40 ;
bool V_47 = false ;
int V_48 ;
V_44 = ( V_20 == V_49 ) ? V_43 : V_42 ;
V_45 = ( V_20 == V_49 ) ? F_35 ( V_43 ) :
F_35 ( V_42 ) ;
* V_46 = '\0' ;
for ( V_9 = 0 ; V_9 < V_45 ; ++ V_9 ) {
if ( ! ( V_41 & ( 1 << V_9 ) ) )
continue;
V_48 = snprintf ( V_46 , V_24 , L_8 , V_47 ? L_9 : L_10 , V_44 [ V_9 ] ) ;
if ( V_48 > 0 ) {
V_24 -= V_48 ;
V_46 += V_48 ;
}
V_47 = true ;
}
return V_40 ;
}
int F_36 ( struct V_50 * V_51 ,
unsigned int V_24 , T_1 V_52 , bool V_53 )
{
int V_54 ;
if ( F_37 ( V_51 -> V_12 -> V_55 ) != V_24 &&
V_51 -> V_12 -> V_55 != - 1 ) {
F_38 ( L_11
L_12 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_12 -> V_13 ,
V_51 -> V_12 -> V_14 ,
F_37 ( V_51 -> V_12 -> V_55 ) , V_24 ) ;
return - V_56 ;
}
if ( V_51 -> V_12 -> V_57 != NULL &&
strcmp ( V_51 -> V_12 -> V_57 , V_51 -> V_57 ) != 0 ) {
F_38 ( L_13 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_12 -> V_13 ,
V_51 -> V_12 -> V_57 , V_51 -> V_57 ) ;
return - V_56 ;
}
if ( V_51 -> V_12 -> V_58 && ( V_51 -> V_59 & ~ V_51 -> V_12 -> V_58 ) != 0 ) {
char V_60 [ 64 ] , V_61 [ 64 ] ;
F_38 ( L_14
L_15 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_12 -> V_13 ,
F_34 ( V_60 , sizeof( V_60 ) , V_51 -> V_59 ,
V_51 -> V_4 ) ,
F_34 ( V_61 , sizeof( V_61 ) , V_51 -> V_12 -> V_58 ,
V_51 -> V_4 ) ) ;
return - V_56 ;
}
if ( V_51 -> V_12 -> V_52 && ( V_51 -> V_12 -> V_52 != V_52 || V_53 ) ) {
F_38 ( L_16 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_12 -> V_13 ,
V_51 -> V_12 -> V_52 ) ;
return - V_56 ;
}
if ( V_51 -> V_12 -> V_62 != NULL ) {
V_54 = V_51 -> V_12 -> V_62 ( V_51 ) ;
if ( V_54 < 0 )
return V_54 ;
else if ( V_54 > 0 )
return - V_63 ;
}
return 0 ;
}
static int F_39 ( const char * V_12 , const char * V_2 ,
const T_6 V_64 )
{
const struct V_33 * V_65 ;
int V_66 = V_2 - V_12 ;
if ( V_66 == 0 )
return 0 ;
V_65 = (struct V_33 * ) V_12 ;
do {
if ( ( unsigned long ) V_65 % V_64 )
return - V_56 ;
if ( V_66 < ( int ) sizeof( struct V_33 ) )
return - V_56 ;
if ( V_65 -> V_34 . V_67 < sizeof( struct V_33 ) )
return - V_56 ;
if ( V_65 -> V_34 . V_67 > V_66 )
return - V_56 ;
V_66 -= V_65 -> V_34 . V_67 ;
V_65 = ( ( void * ) ( ( char * ) ( V_65 ) + ( V_65 ) -> V_34 . V_67 ) ) ;
} while ( V_66 > 0 );
return 0 ;
}
int F_40 ( T_1 V_3 , unsigned int V_68 , int V_69 )
{
struct V_70 * V_71 = & V_5 [ V_3 ] ;
if ( ! V_71 -> V_72 ) {
if ( ! V_71 -> V_73 )
return - V_56 ;
V_71 -> V_72 = F_41 ( sizeof( struct V_74 ) * V_71 -> V_73 ) ;
if ( ! V_71 -> V_72 )
return - V_75 ;
V_71 -> V_76 = 0 ;
}
if ( V_71 -> V_76 >= V_71 -> V_73 )
return - V_56 ;
if ( V_71 -> V_76 )
V_69 += V_71 -> V_72 [ V_71 -> V_76 - 1 ] . V_69 ;
V_71 -> V_72 [ V_71 -> V_76 ] . V_68 = V_68 ;
V_71 -> V_72 [ V_71 -> V_76 ] . V_69 = V_69 ;
V_71 -> V_76 ++ ;
return 0 ;
}
void F_42 ( T_1 V_3 )
{
if ( V_5 [ V_3 ] . V_72 ) {
F_43 ( V_5 [ V_3 ] . V_72 ) ;
V_5 [ V_3 ] . V_72 = NULL ;
V_5 [ V_3 ] . V_73 = 0 ;
V_5 [ V_3 ] . V_76 = 0 ;
}
}
int F_44 ( T_1 V_3 , unsigned int V_68 )
{
struct V_74 * V_77 = V_5 [ V_3 ] . V_72 ;
int V_78 , V_79 = 0 , V_80 = V_5 [ V_3 ] . V_76 - 1 ;
while ( V_79 <= V_80 ) {
V_78 = ( V_79 + V_80 ) >> 1 ;
if ( V_68 > V_77 [ V_78 ] . V_68 )
V_79 = V_78 + 1 ;
else if ( V_68 < V_77 [ V_78 ] . V_68 )
V_80 = V_78 - 1 ;
else
return V_78 ? V_77 [ V_78 - 1 ] . V_69 : 0 ;
}
return V_79 ? V_77 [ V_79 - 1 ] . V_69 : 0 ;
}
void F_45 ( T_1 V_3 , unsigned int V_73 )
{
V_5 [ V_3 ] . V_73 = V_73 ;
V_5 [ V_3 ] . V_76 = 0 ;
}
int F_46 ( const struct V_11 * V_12 )
{
T_7 V_81 = V_12 -> V_82 ? : V_12 -> V_55 ;
return F_37 ( V_12 -> V_55 ) - F_47 ( V_81 ) ;
}
void F_48 ( struct V_33 * V_15 , void * * V_83 ,
unsigned int * V_24 )
{
const struct V_11 * V_12 = V_15 -> V_34 . V_84 . V_12 ;
struct V_85 * V_86 = (struct V_85 * ) V_15 ;
int V_87 , V_88 = F_46 ( V_12 ) ;
T_7 V_89 = V_86 -> V_34 . V_90 . V_67 ;
char V_13 [ sizeof( V_15 -> V_34 . V_90 . V_13 ) ] ;
V_15 = * V_83 ;
memcpy ( V_15 , V_86 , sizeof( * V_86 ) ) ;
if ( V_12 -> V_91 )
V_12 -> V_91 ( V_15 -> V_92 , V_86 -> V_92 ) ;
else
memcpy ( V_15 -> V_92 , V_86 -> V_92 , V_89 - sizeof( * V_86 ) ) ;
V_87 = F_37 ( V_12 -> V_55 ) - V_12 -> V_55 ;
if ( V_87 > 0 )
memset ( V_15 -> V_92 + V_12 -> V_55 , 0 , V_87 ) ;
V_89 += V_88 ;
V_15 -> V_34 . V_90 . V_67 = V_89 ;
F_49 ( V_13 , V_12 -> V_13 , sizeof( V_13 ) ) ;
F_50 ( V_12 -> V_17 ) ;
strncpy ( V_15 -> V_34 . V_90 . V_13 , V_13 , sizeof( V_15 -> V_34 . V_90 . V_13 ) ) ;
* V_24 += V_88 ;
* V_83 += V_89 ;
}
int F_51 ( const struct V_33 * V_15 ,
void T_5 * * V_83 , unsigned int * V_24 )
{
const struct V_11 * V_12 = V_15 -> V_34 . V_84 . V_12 ;
struct V_85 T_5 * V_86 = * V_83 ;
int V_88 = F_46 ( V_12 ) ;
T_7 V_89 = V_15 -> V_34 . V_90 . V_67 - V_88 ;
if ( F_28 ( V_86 , V_15 , V_12 , V_89 ) )
return - V_28 ;
if ( V_12 -> V_93 ) {
if ( V_12 -> V_93 ( ( void T_5 * ) V_86 -> V_92 , V_15 -> V_92 ) )
return - V_28 ;
} else {
if ( F_52 ( V_86 , V_15 , V_12 , V_89 - sizeof( * V_86 ) ) )
return - V_28 ;
}
* V_24 -= V_88 ;
* V_83 += V_89 ;
return 0 ;
}
int F_53 ( const void * V_94 , const char * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
long V_98 = V_95 - ( const char * ) V_94 ;
const struct V_99 * V_22 ;
const char * V_100 = V_94 ;
if ( V_96 < V_98 )
return - V_56 ;
if ( V_96 + sizeof( * V_22 ) > V_97 )
return - V_56 ;
V_22 = ( void * ) ( V_100 + V_96 ) ;
if ( V_22 -> V_34 . V_101 < sizeof( * V_22 ) )
return - V_56 ;
if ( V_96 + V_22 -> V_34 . V_101 > V_97 )
return - V_56 ;
if ( strcmp ( V_22 -> V_34 . V_90 . V_13 , V_102 ) == 0 &&
F_47 ( V_96 + sizeof( struct V_103 ) ) != V_97 )
return - V_56 ;
F_54 ( sizeof( struct V_85 ) != sizeof( struct V_33 ) ) ;
return F_39 ( V_95 , V_94 + V_96 ,
F_55 ( struct V_85 ) ) ;
}
int F_56 ( const void * V_94 ,
const char * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
long V_98 = V_95 - ( const char * ) V_94 ;
const struct V_35 * V_22 ;
const char * V_100 = V_94 ;
if ( V_96 < V_98 )
return - V_56 ;
if ( V_96 + sizeof( * V_22 ) > V_97 )
return - V_56 ;
V_22 = ( void * ) ( V_100 + V_96 ) ;
if ( V_22 -> V_34 . V_101 < sizeof( * V_22 ) )
return - V_56 ;
if ( V_96 + V_22 -> V_34 . V_101 > V_97 )
return - V_56 ;
if ( strcmp ( V_22 -> V_34 . V_90 . V_13 , V_102 ) == 0 &&
F_37 ( V_96 + sizeof( struct V_104 ) ) != V_97 )
return - V_56 ;
return F_39 ( V_95 , V_94 + V_96 ,
F_55 ( struct V_33 ) ) ;
}
unsigned int * F_57 ( unsigned int V_24 )
{
return F_58 ( V_24 , sizeof( unsigned int ) , V_105 | V_106 ) ;
}
bool F_59 ( const unsigned int * V_107 ,
unsigned int V_2 , unsigned int V_24 )
{
int V_15 , V_108 = 0 , V_109 = V_24 ;
while ( V_109 > V_108 ) {
V_15 = ( V_108 + V_109 ) / 2u ;
if ( V_107 [ V_15 ] > V_2 )
V_109 = V_15 ;
else if ( V_107 [ V_15 ] < V_2 )
V_108 = V_15 + 1 ;
else
return true ;
}
return false ;
}
int F_60 ( struct V_110 * V_51 ,
unsigned int V_24 , T_1 V_52 , bool V_53 )
{
int V_54 ;
if ( F_37 ( V_51 -> V_2 -> V_111 ) != V_24 ) {
F_38 ( L_17
L_12 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_2 -> V_13 ,
V_51 -> V_2 -> V_14 ,
F_37 ( V_51 -> V_2 -> V_111 ) , V_24 ) ;
return - V_56 ;
}
if ( V_51 -> V_2 -> V_57 != NULL &&
strcmp ( V_51 -> V_2 -> V_57 , V_51 -> V_57 ) != 0 ) {
F_38 ( L_18 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_2 -> V_13 ,
V_51 -> V_2 -> V_57 , V_51 -> V_57 ) ;
return - V_56 ;
}
if ( V_51 -> V_2 -> V_58 && ( V_51 -> V_59 & ~ V_51 -> V_2 -> V_58 ) != 0 ) {
char V_60 [ 64 ] , V_61 [ 64 ] ;
F_38 ( L_19
L_20 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_2 -> V_13 ,
F_34 ( V_60 , sizeof( V_60 ) , V_51 -> V_59 ,
V_51 -> V_4 ) ,
F_34 ( V_61 , sizeof( V_61 ) , V_51 -> V_2 -> V_58 ,
V_51 -> V_4 ) ) ;
return - V_56 ;
}
if ( V_51 -> V_2 -> V_52 && ( V_51 -> V_2 -> V_52 != V_52 || V_53 ) ) {
F_38 ( L_21 ,
V_21 [ V_51 -> V_4 ] , V_51 -> V_2 -> V_13 ,
V_51 -> V_2 -> V_52 ) ;
return - V_56 ;
}
if ( V_51 -> V_2 -> V_62 != NULL ) {
V_54 = V_51 -> V_2 -> V_62 ( V_51 ) ;
if ( V_54 < 0 )
return V_54 ;
else if ( V_54 > 0 )
return - V_63 ;
}
return 0 ;
}
void * F_61 ( const void T_5 * V_90 , unsigned int V_112 ,
struct V_113 * V_114 , bool V_115 )
{
void * V_116 ;
T_8 V_24 ;
#ifdef F_62
if ( V_115 ) {
struct V_117 V_118 ;
if ( V_112 <= sizeof( V_118 ) )
return F_16 ( - V_56 ) ;
V_112 -= sizeof( V_118 ) ;
if ( F_63 ( & V_118 , V_90 , sizeof( V_118 ) ) != 0 )
return F_16 ( - V_28 ) ;
F_49 ( V_114 -> V_13 , V_118 . V_13 , sizeof( V_114 -> V_13 ) ) ;
V_114 -> V_119 = V_118 . V_119 ;
V_90 += sizeof( V_118 ) ;
} else
#endif
{
if ( V_112 <= sizeof( * V_114 ) )
return F_16 ( - V_56 ) ;
V_112 -= sizeof( * V_114 ) ;
if ( F_63 ( V_114 , V_90 , sizeof( * V_114 ) ) != 0 )
return F_16 ( - V_28 ) ;
V_114 -> V_13 [ sizeof( V_114 -> V_13 ) - 1 ] = '\0' ;
V_90 += sizeof( * V_114 ) ;
}
V_24 = sizeof( struct V_120 ) ;
V_24 *= V_114 -> V_119 ;
if ( V_24 != ( T_8 ) V_112 )
return F_16 ( - V_56 ) ;
V_116 = F_41 ( V_112 ) ;
if ( ! V_116 )
return F_16 ( - V_75 ) ;
if ( F_63 ( V_116 , V_90 , V_112 ) == 0 )
return V_116 ;
F_43 ( V_116 ) ;
return F_16 ( - V_28 ) ;
}
int F_64 ( const struct V_1 * V_2 )
{
T_7 V_81 = V_2 -> V_82 ? : V_2 -> V_111 ;
return F_37 ( V_2 -> V_111 ) - F_47 ( V_81 ) ;
}
void F_65 ( struct V_35 * V_22 , void * * V_83 ,
unsigned int * V_24 )
{
const struct V_1 * V_2 = V_22 -> V_34 . V_84 . V_2 ;
struct V_99 * V_121 = (struct V_99 * ) V_22 ;
int V_87 , V_88 = F_64 ( V_2 ) ;
T_7 V_122 = V_121 -> V_34 . V_90 . V_101 ;
char V_13 [ sizeof( V_22 -> V_34 . V_90 . V_13 ) ] ;
V_22 = * V_83 ;
memcpy ( V_22 , V_121 , sizeof( * V_121 ) ) ;
if ( V_2 -> V_91 )
V_2 -> V_91 ( V_22 -> V_92 , V_121 -> V_92 ) ;
else
memcpy ( V_22 -> V_92 , V_121 -> V_92 , V_122 - sizeof( * V_121 ) ) ;
V_87 = F_37 ( V_2 -> V_111 ) - V_2 -> V_111 ;
if ( V_87 > 0 )
memset ( V_22 -> V_92 + V_2 -> V_111 , 0 , V_87 ) ;
V_122 += V_88 ;
V_22 -> V_34 . V_90 . V_101 = V_122 ;
F_49 ( V_13 , V_2 -> V_13 , sizeof( V_13 ) ) ;
F_50 ( V_2 -> V_17 ) ;
strncpy ( V_22 -> V_34 . V_90 . V_13 , V_13 , sizeof( V_22 -> V_34 . V_90 . V_13 ) ) ;
* V_24 += V_88 ;
* V_83 += V_122 ;
}
int F_66 ( const struct V_35 * V_22 ,
void T_5 * * V_83 , unsigned int * V_24 )
{
const struct V_1 * V_2 = V_22 -> V_34 . V_84 . V_2 ;
struct V_99 T_5 * V_121 = * V_83 ;
int V_88 = F_64 ( V_2 ) ;
T_7 V_122 = V_22 -> V_34 . V_90 . V_101 - V_88 ;
if ( F_28 ( V_121 , V_22 , V_2 , V_122 ) )
return - V_28 ;
if ( V_2 -> V_93 ) {
if ( V_2 -> V_93 ( ( void T_5 * ) V_121 -> V_92 , V_22 -> V_92 ) )
return - V_28 ;
} else {
if ( F_52 ( V_121 , V_22 , V_2 , V_122 - sizeof( * V_121 ) ) )
return - V_28 ;
}
* V_24 -= V_88 ;
* V_83 += V_122 ;
return 0 ;
}
struct V_123 * F_67 ( unsigned int V_24 )
{
struct V_123 * V_114 = NULL ;
T_6 V_124 = sizeof( * V_114 ) + V_24 ;
if ( V_124 < sizeof( * V_114 ) )
return NULL ;
if ( ( F_68 ( V_24 ) >> V_125 ) + 2 > V_126 )
return NULL ;
if ( V_124 <= ( V_127 << V_128 ) )
V_114 = F_69 ( V_124 , V_105 | V_129 | V_130 ) ;
if ( ! V_114 ) {
V_114 = F_70 ( V_124 , V_105 | V_129 | V_130 ,
V_131 ) ;
if ( ! V_114 )
return NULL ;
}
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
V_114 -> V_24 = V_24 ;
return V_114 ;
}
void F_71 ( struct V_123 * V_114 )
{
int V_132 ;
if ( V_114 -> V_133 != NULL ) {
F_72 (cpu)
F_73 ( V_114 -> V_133 [ V_132 ] ) ;
F_73 ( V_114 -> V_133 ) ;
}
F_73 ( V_114 ) ;
}
struct V_134 * F_74 ( struct V_135 * V_135 , T_1 V_3 ,
const char * V_13 )
{
struct V_134 * V_22 , * V_136 = NULL ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 && F_15 ( V_22 -> V_17 ) )
return V_22 ;
if ( V_135 == & V_137 )
goto V_138;
F_14 (t, &init_net.xt.tables[af], list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) )
continue;
if ( ! F_15 ( V_22 -> V_17 ) ) {
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_22 -> V_139 ( V_135 ) != 0 ) {
F_50 ( V_22 -> V_17 ) ;
return NULL ;
}
V_136 = V_22 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
break;
}
if ( ! V_136 )
goto V_138;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 )
return V_22 ;
F_50 ( V_136 -> V_17 ) ;
V_138:
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
void F_75 ( struct V_134 * V_57 )
{
F_4 ( & V_5 [ V_57 -> V_3 ] . V_6 ) ;
}
void F_76 ( T_1 V_3 )
{
F_2 ( & V_5 [ V_3 ] . V_140 ) ;
}
void F_77 ( T_1 V_3 )
{
F_4 ( & V_5 [ V_3 ] . V_140 ) ;
}
static int F_78 ( struct V_123 * V_9 )
{
unsigned int V_24 ;
int V_132 ;
V_24 = sizeof( void * * ) * V_141 ;
if ( V_24 > V_127 )
V_9 -> V_133 = F_79 ( V_24 , V_105 ) ;
else
V_9 -> V_133 = F_80 ( V_24 , V_105 ) ;
if ( V_9 -> V_133 == NULL )
return - V_75 ;
if ( V_9 -> V_142 == 0 )
return 0 ;
V_24 = sizeof( void * ) * V_9 -> V_142 * 2u ;
F_72 (cpu) {
V_9 -> V_133 [ V_132 ] = F_81 ( V_24 , V_105 ,
F_82 ( V_132 ) ) ;
if ( V_9 -> V_133 [ V_132 ] == NULL )
return - V_75 ;
}
return 0 ;
}
struct V_123 *
F_83 ( struct V_134 * V_57 ,
unsigned int V_119 ,
struct V_123 * V_143 ,
int * error )
{
struct V_123 * V_144 ;
int V_54 ;
V_54 = F_78 ( V_143 ) ;
if ( V_54 < 0 ) {
* error = V_54 ;
return NULL ;
}
F_84 () ;
V_144 = V_57 -> V_144 ;
if ( V_119 != V_144 -> V_73 ) {
F_85 ( L_22 ,
V_119 , V_144 -> V_73 ) ;
F_86 () ;
* error = - V_145 ;
return NULL ;
}
V_143 -> V_146 = V_144 -> V_146 ;
F_87 () ;
V_57 -> V_144 = V_143 ;
F_86 () ;
#ifdef F_88
if ( V_147 ) {
struct V_148 * V_149 ;
V_149 = F_89 ( V_150 -> V_151 , V_105 ,
V_152 ) ;
if ( V_149 ) {
F_90 ( V_149 , L_23 ,
V_57 -> V_13 , V_57 -> V_3 ,
V_144 -> V_73 ) ;
F_91 ( V_149 ) ;
}
}
#endif
return V_144 ;
}
struct V_134 * F_92 ( struct V_135 * V_135 ,
const struct V_134 * V_153 ,
struct V_123 * V_154 ,
struct V_123 * V_143 )
{
int V_54 ;
struct V_123 * V_144 ;
struct V_134 * V_22 , * V_57 ;
V_57 = F_93 ( V_153 , sizeof( struct V_134 ) , V_105 ) ;
if ( ! V_57 ) {
V_54 = - V_75 ;
goto V_138;
}
F_2 ( & V_5 [ V_57 -> V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_22 -> V_13 , V_57 -> V_13 ) == 0 ) {
V_54 = - V_155 ;
goto V_156;
}
}
V_57 -> V_144 = V_154 ;
if ( ! F_83 ( V_57 , 0 , V_143 , & V_54 ) )
goto V_156;
V_144 = V_57 -> V_144 ;
F_85 ( L_24 , V_144 -> V_73 ) ;
V_144 -> V_146 = V_144 -> V_73 ;
F_3 ( & V_57 -> V_7 , & V_135 -> V_5 . V_157 [ V_57 -> V_3 ] ) ;
F_4 ( & V_5 [ V_57 -> V_3 ] . V_6 ) ;
return V_57 ;
V_156:
F_4 ( & V_5 [ V_57 -> V_3 ] . V_6 ) ;
F_94 ( V_57 ) ;
V_138:
return F_16 ( V_54 ) ;
}
void * F_95 ( struct V_134 * V_57 )
{
struct V_123 * V_144 ;
F_2 ( & V_5 [ V_57 -> V_3 ] . V_6 ) ;
V_144 = V_57 -> V_144 ;
F_6 ( & V_57 -> V_7 ) ;
F_4 ( & V_5 [ V_57 -> V_3 ] . V_6 ) ;
F_94 ( V_57 ) ;
return V_144 ;
}
static void * F_96 ( struct V_158 * V_159 , T_9 * V_65 )
{
struct V_160 * V_161 = V_159 -> V_144 ;
struct V_135 * V_135 = F_97 ( V_159 ) ;
T_1 V_3 = V_161 -> V_3 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
return F_98 ( & V_135 -> V_5 . V_157 [ V_3 ] , * V_65 ) ;
}
static void * F_99 ( struct V_158 * V_159 , void * V_162 , T_9 * V_65 )
{
struct V_160 * V_161 = V_159 -> V_144 ;
struct V_135 * V_135 = F_97 ( V_159 ) ;
T_1 V_3 = V_161 -> V_3 ;
return F_100 ( V_162 , & V_135 -> V_5 . V_157 [ V_3 ] , V_65 ) ;
}
static void F_101 ( struct V_158 * V_159 , void * V_162 )
{
struct V_160 * V_161 = V_159 -> V_144 ;
T_1 V_3 = V_161 -> V_3 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
static int F_102 ( struct V_158 * V_159 , void * V_162 )
{
struct V_134 * V_57 = F_103 ( V_162 , struct V_134 , V_7 ) ;
if ( * V_57 -> V_13 )
F_104 ( V_159 , L_25 , V_57 -> V_13 ) ;
return 0 ;
}
static int F_105 ( struct V_163 * V_163 , struct V_164 * V_164 )
{
int V_54 ;
struct V_160 * V_161 ;
V_54 = F_106 ( V_163 , V_164 , & V_165 ,
sizeof( struct V_160 ) ) ;
if ( ! V_54 ) {
V_161 = ( (struct V_158 * ) V_164 -> V_166 ) -> V_144 ;
V_161 -> V_3 = ( unsigned long ) F_107 ( V_163 ) ;
}
return V_54 ;
}
static void * F_108 ( struct V_158 * V_159 , void * V_162 , T_9 * V_167 ,
bool V_168 )
{
static const T_3 V_169 [] = {
[ V_170 ] = V_171 ,
[ V_171 ] = V_172 ,
} ;
struct V_173 * V_174 = V_159 -> V_144 ;
switch ( V_174 -> V_175 ) {
case V_176 :
V_174 -> V_175 = V_170 ;
F_2 ( & V_5 [ V_19 ] . V_6 ) ;
V_174 -> V_177 = V_174 -> V_178 = V_168 ?
& V_5 [ V_19 ] . V_2 : & V_5 [ V_19 ] . V_12 ;
break;
case V_170 :
V_174 -> V_178 = V_174 -> V_178 -> V_179 ;
if ( V_174 -> V_178 != V_174 -> V_177 )
break;
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
F_2 ( & V_5 [ V_174 -> V_20 ] . V_6 ) ;
V_174 -> V_177 = V_174 -> V_178 = V_168 ?
& V_5 [ V_174 -> V_20 ] . V_2 : & V_5 [ V_174 -> V_20 ] . V_12 ;
V_174 -> V_175 = V_169 [ V_174 -> V_175 ] ;
break;
case V_171 :
V_174 -> V_178 = V_174 -> V_178 -> V_179 ;
if ( V_174 -> V_178 != V_174 -> V_177 )
break;
default:
return NULL ;
}
if ( V_167 != NULL )
++ * V_167 ;
return V_174 ;
}
static void * F_109 ( struct V_158 * V_159 , T_9 * V_65 ,
bool V_168 )
{
struct V_173 * V_174 = V_159 -> V_144 ;
unsigned int V_180 ;
V_174 -> V_175 = V_176 ;
for ( V_180 = 0 ; V_180 < * V_65 ; ++ V_180 )
if ( F_108 ( V_159 , NULL , NULL , V_168 ) == NULL )
return NULL ;
return V_174 ;
}
static void F_110 ( struct V_158 * V_159 , void * V_162 )
{
struct V_173 * V_174 = V_159 -> V_144 ;
switch ( V_174 -> V_175 ) {
case V_170 :
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
break;
case V_171 :
F_4 ( & V_5 [ V_174 -> V_20 ] . V_6 ) ;
break;
}
}
static void * F_111 ( struct V_158 * V_159 , T_9 * V_65 )
{
return F_109 ( V_159 , V_65 , false ) ;
}
static void * F_112 ( struct V_158 * V_159 , void * V_162 , T_9 * V_167 )
{
return F_108 ( V_159 , V_162 , V_167 , false ) ;
}
static int F_113 ( struct V_158 * V_159 , void * V_162 )
{
const struct V_173 * V_174 = V_159 -> V_144 ;
const struct V_11 * V_12 ;
switch ( V_174 -> V_175 ) {
case V_170 :
case V_171 :
if ( V_174 -> V_178 == V_174 -> V_177 )
return 0 ;
V_12 = F_103 ( V_174 -> V_178 , struct V_11 , V_7 ) ;
if ( * V_12 -> V_13 )
F_104 ( V_159 , L_25 , V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_114 ( struct V_163 * V_163 , struct V_164 * V_164 )
{
struct V_173 * V_174 ;
V_174 = F_115 ( V_164 , & V_181 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_75 ;
V_174 -> V_20 = ( unsigned long ) F_107 ( V_163 ) ;
return 0 ;
}
static void * F_116 ( struct V_158 * V_159 , T_9 * V_65 )
{
return F_109 ( V_159 , V_65 , true ) ;
}
static void * F_117 ( struct V_158 * V_159 , void * V_162 , T_9 * V_167 )
{
return F_108 ( V_159 , V_162 , V_167 , true ) ;
}
static int F_118 ( struct V_158 * V_159 , void * V_162 )
{
const struct V_173 * V_174 = V_159 -> V_144 ;
const struct V_1 * V_2 ;
switch ( V_174 -> V_175 ) {
case V_170 :
case V_171 :
if ( V_174 -> V_178 == V_174 -> V_177 )
return 0 ;
V_2 = F_103 ( V_174 -> V_178 , struct V_1 , V_7 ) ;
if ( * V_2 -> V_13 )
F_104 ( V_159 , L_25 , V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_119 ( struct V_163 * V_163 , struct V_164 * V_164 )
{
struct V_173 * V_174 ;
V_174 = F_115 ( V_164 , & V_182 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_75 ;
V_174 -> V_20 = ( unsigned long ) F_107 ( V_163 ) ;
return 0 ;
}
struct V_183 *
F_120 ( const struct V_134 * V_57 , T_10 * V_184 )
{
unsigned int V_59 = V_57 -> V_185 ;
T_3 V_9 , V_186 = F_121 ( V_59 ) ;
T_3 V_187 ;
struct V_183 * V_188 ;
if ( ! V_186 )
return F_16 ( - V_56 ) ;
V_188 = F_122 ( V_186 , sizeof( * V_188 ) , V_105 ) ;
if ( V_188 == NULL )
return F_16 ( - V_75 ) ;
for ( V_9 = 0 , V_187 = 0 ; V_9 < V_186 && V_59 != 0 ;
V_59 >>= 1 , ++ V_187 ) {
if ( ! ( V_59 & 1 ) )
continue;
V_188 [ V_9 ] . V_189 = V_184 ;
V_188 [ V_9 ] . V_190 = V_57 -> V_3 ;
V_188 [ V_9 ] . V_187 = V_187 ;
V_188 [ V_9 ] . V_191 = V_57 -> V_191 ;
++ V_9 ;
}
return V_188 ;
}
int F_123 ( struct V_135 * V_135 , T_1 V_3 )
{
#ifdef F_124
char V_40 [ V_192 ] ;
struct V_193 * V_194 ;
T_11 V_195 ;
T_12 V_196 ;
#endif
if ( V_3 >= F_35 ( V_21 ) )
return - V_56 ;
#ifdef F_124
V_195 = F_125 ( V_135 -> V_197 , 0 ) ;
V_196 = F_126 ( V_135 -> V_197 , 0 ) ;
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_198 , sizeof( V_40 ) ) ;
V_194 = F_128 ( V_40 , 0440 , V_135 -> V_199 , & V_200 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_194 )
goto V_138;
if ( F_129 ( V_195 ) && F_130 ( V_196 ) )
F_131 ( V_194 , V_195 , V_196 ) ;
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_201 , sizeof( V_40 ) ) ;
V_194 = F_128 ( V_40 , 0440 , V_135 -> V_199 , & V_202 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_194 )
goto V_203;
if ( F_129 ( V_195 ) && F_130 ( V_196 ) )
F_131 ( V_194 , V_195 , V_196 ) ;
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_204 , sizeof( V_40 ) ) ;
V_194 = F_128 ( V_40 , 0440 , V_135 -> V_199 , & V_205 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_194 )
goto V_206;
if ( F_129 ( V_195 ) && F_130 ( V_196 ) )
F_131 ( V_194 , V_195 , V_196 ) ;
#endif
return 0 ;
#ifdef F_124
V_206:
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_201 , sizeof( V_40 ) ) ;
F_132 ( V_40 , V_135 -> V_199 ) ;
V_203:
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_198 , sizeof( V_40 ) ) ;
F_132 ( V_40 , V_135 -> V_199 ) ;
V_138:
return - 1 ;
#endif
}
void F_133 ( struct V_135 * V_135 , T_1 V_3 )
{
#ifdef F_124
char V_40 [ V_192 ] ;
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_198 , sizeof( V_40 ) ) ;
F_132 ( V_40 , V_135 -> V_199 ) ;
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_204 , sizeof( V_40 ) ) ;
F_132 ( V_40 , V_135 -> V_199 ) ;
F_49 ( V_40 , V_21 [ V_3 ] , sizeof( V_40 ) ) ;
F_127 ( V_40 , V_201 , sizeof( V_40 ) ) ;
F_132 ( V_40 , V_135 -> V_199 ) ;
#endif
}
bool F_134 ( struct V_207 * V_208 ,
struct V_120 * V_209 )
{
F_54 ( V_210 < ( sizeof( * V_209 ) * 2 ) ) ;
if ( V_141 <= 1 )
return true ;
if ( ! V_208 -> V_116 ) {
V_208 -> V_116 = F_135 ( V_210 ,
V_210 ) ;
if ( ! V_208 -> V_116 )
return false ;
}
V_209 -> V_211 = ( V_212 unsigned long ) ( V_208 -> V_116 + V_208 -> V_88 ) ;
V_208 -> V_88 += sizeof( * V_209 ) ;
if ( V_208 -> V_88 > ( V_210 - sizeof( * V_209 ) ) ) {
V_208 -> V_116 = NULL ;
V_208 -> V_88 = 0 ;
}
return true ;
}
void F_136 ( struct V_120 * V_213 )
{
unsigned long V_211 = V_213 -> V_211 ;
if ( V_141 > 1 && ( V_211 & ( V_210 - 1 ) ) == 0 )
F_137 ( ( void V_214 * ) V_211 ) ;
}
static int T_13 F_138 ( struct V_135 * V_135 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_215 ; V_9 ++ )
F_139 ( & V_135 -> V_5 . V_157 [ V_9 ] ) ;
return 0 ;
}
static int T_14 F_140 ( void )
{
unsigned int V_9 ;
int V_216 ;
F_72 (i) {
F_141 ( & F_142 ( V_217 , V_9 ) ) ;
}
V_5 = F_69 ( sizeof( struct V_70 ) * V_215 , V_105 ) ;
if ( ! V_5 )
return - V_75 ;
for ( V_9 = 0 ; V_9 < V_215 ; V_9 ++ ) {
F_143 ( & V_5 [ V_9 ] . V_6 ) ;
#ifdef F_62
F_143 ( & V_5 [ V_9 ] . V_140 ) ;
V_5 [ V_9 ] . V_72 = NULL ;
#endif
F_139 ( & V_5 [ V_9 ] . V_2 ) ;
F_139 ( & V_5 [ V_9 ] . V_12 ) ;
}
V_216 = F_144 ( & V_218 ) ;
if ( V_216 < 0 )
F_94 ( V_5 ) ;
return V_216 ;
}
static void T_15 F_145 ( void )
{
F_146 ( & V_218 ) ;
F_94 ( V_5 ) ;
}
