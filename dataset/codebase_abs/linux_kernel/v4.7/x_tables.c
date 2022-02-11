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
int F_49 ( struct V_97 * V_39 ,
unsigned int V_28 , T_1 V_40 , bool V_41 )
{
int V_42 ;
if ( F_28 ( V_39 -> V_2 -> V_98 ) != V_28 ) {
F_29 ( L_17
L_12 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_14 ,
F_28 ( V_39 -> V_2 -> V_98 ) , V_28 ) ;
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
void * F_50 ( const void T_6 * V_80 , unsigned int V_99 ,
struct V_100 * V_101 , bool V_102 )
{
void * V_103 ;
T_7 V_28 ;
#ifdef F_51
if ( V_102 ) {
struct V_104 V_105 ;
if ( V_99 <= sizeof( V_105 ) )
return F_16 ( - V_44 ) ;
V_99 -= sizeof( V_105 ) ;
if ( F_52 ( & V_105 , V_80 , sizeof( V_105 ) ) != 0 )
return F_16 ( - V_83 ) ;
F_40 ( V_101 -> V_13 , V_105 . V_13 , sizeof( V_101 -> V_13 ) ) ;
V_101 -> V_106 = V_105 . V_106 ;
V_80 += sizeof( V_105 ) ;
} else
#endif
{
if ( V_99 <= sizeof( * V_101 ) )
return F_16 ( - V_44 ) ;
V_99 -= sizeof( * V_101 ) ;
if ( F_52 ( V_101 , V_80 , sizeof( * V_101 ) ) != 0 )
return F_16 ( - V_83 ) ;
V_101 -> V_13 [ sizeof( V_101 -> V_13 ) - 1 ] = '\0' ;
V_80 += sizeof( * V_101 ) ;
}
V_28 = sizeof( struct V_107 ) ;
V_28 *= V_101 -> V_106 ;
if ( V_28 != ( T_7 ) V_99 )
return F_16 ( - V_44 ) ;
V_103 = F_32 ( V_99 ) ;
if ( ! V_103 )
return F_16 ( - V_65 ) ;
if ( F_52 ( V_103 , V_80 , V_99 ) == 0 )
return V_103 ;
F_34 ( V_103 ) ;
return F_16 ( - V_83 ) ;
}
int F_53 ( const struct V_1 * V_2 )
{
T_5 V_71 = V_2 -> V_72 ? : V_2 -> V_98 ;
return F_28 ( V_2 -> V_98 ) - F_38 ( V_71 ) ;
}
void F_54 ( struct V_95 * V_22 , void * * V_73 ,
unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_56 . V_74 . V_2 ;
struct V_90 * V_108 = (struct V_90 * ) V_22 ;
int V_77 , V_78 = F_53 ( V_2 ) ;
T_5 V_109 = V_108 -> V_56 . V_80 . V_92 ;
char V_13 [ sizeof( V_22 -> V_56 . V_80 . V_13 ) ] ;
V_22 = * V_73 ;
memcpy ( V_22 , V_108 , sizeof( * V_108 ) ) ;
if ( V_2 -> V_81 )
V_2 -> V_81 ( V_22 -> V_82 , V_108 -> V_82 ) ;
else
memcpy ( V_22 -> V_82 , V_108 -> V_82 , V_109 - sizeof( * V_108 ) ) ;
V_77 = F_28 ( V_2 -> V_98 ) - V_2 -> V_98 ;
if ( V_77 > 0 )
memset ( V_22 -> V_82 + V_2 -> V_98 , 0 , V_77 ) ;
V_109 += V_78 ;
V_22 -> V_56 . V_80 . V_92 = V_109 ;
F_40 ( V_13 , V_2 -> V_13 , sizeof( V_13 ) ) ;
F_41 ( V_2 -> V_17 ) ;
strncpy ( V_22 -> V_56 . V_80 . V_13 , V_13 , sizeof( V_22 -> V_56 . V_80 . V_13 ) ) ;
* V_28 += V_78 ;
* V_73 += V_109 ;
}
int F_55 ( const struct V_95 * V_22 ,
void T_6 * * V_73 , unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_56 . V_74 . V_2 ;
struct V_90 T_6 * V_108 = * V_73 ;
int V_78 = F_53 ( V_2 ) ;
T_5 V_109 = V_22 -> V_56 . V_80 . V_92 - V_78 ;
if ( F_43 ( V_108 , V_22 , sizeof( * V_108 ) ) ||
F_44 ( V_109 , & V_108 -> V_56 . V_80 . V_92 ) ||
F_43 ( V_108 -> V_56 . V_80 . V_13 , V_22 -> V_56 . V_74 . V_2 -> V_13 ,
strlen ( V_22 -> V_56 . V_74 . V_2 -> V_13 ) + 1 ) )
return - V_83 ;
if ( V_2 -> V_84 ) {
if ( V_2 -> V_84 ( ( void T_6 * ) V_108 -> V_82 , V_22 -> V_82 ) )
return - V_83 ;
} else {
if ( F_43 ( V_108 -> V_82 , V_22 -> V_82 , V_109 - sizeof( * V_108 ) ) )
return - V_83 ;
}
* V_28 -= V_78 ;
* V_73 += V_109 ;
return 0 ;
}
struct V_110 * F_56 ( unsigned int V_28 )
{
struct V_110 * V_101 = NULL ;
T_4 V_111 = sizeof( * V_101 ) + V_28 ;
if ( V_111 < sizeof( * V_101 ) )
return NULL ;
if ( ( F_57 ( V_28 ) >> V_112 ) + 2 > V_113 )
return NULL ;
if ( V_111 <= ( V_114 << V_115 ) )
V_101 = F_58 ( V_111 , V_116 | V_117 | V_118 ) ;
if ( ! V_101 ) {
V_101 = F_32 ( V_111 ) ;
if ( ! V_101 )
return NULL ;
}
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_28 = V_28 ;
return V_101 ;
}
void F_59 ( struct V_110 * V_101 )
{
int V_119 ;
if ( V_101 -> V_120 != NULL ) {
F_60 (cpu)
F_61 ( V_101 -> V_120 [ V_119 ] ) ;
F_61 ( V_101 -> V_120 ) ;
}
F_61 ( V_101 ) ;
}
struct V_121 * F_62 ( struct V_122 * V_122 , T_1 V_3 ,
const char * V_13 )
{
struct V_121 * V_22 , * V_123 = NULL ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 && F_15 ( V_22 -> V_17 ) )
return V_22 ;
if ( V_122 == & V_124 )
goto V_125;
F_14 (t, &init_net.xt.tables[af], list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) )
continue;
if ( ! F_15 ( V_22 -> V_17 ) )
return NULL ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_22 -> V_126 ( V_122 ) != 0 ) {
F_41 ( V_22 -> V_17 ) ;
return NULL ;
}
V_123 = V_22 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
break;
}
if ( ! V_123 )
goto V_125;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 )
return V_22 ;
F_41 ( V_123 -> V_17 ) ;
V_125:
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
void F_63 ( struct V_121 * V_45 )
{
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
}
void F_64 ( T_1 V_3 )
{
F_2 ( & V_5 [ V_3 ] . V_127 ) ;
}
void F_65 ( T_1 V_3 )
{
F_4 ( & V_5 [ V_3 ] . V_127 ) ;
}
static int F_66 ( struct V_110 * V_9 )
{
unsigned int V_28 ;
int V_119 ;
V_28 = sizeof( void * * ) * V_128 ;
if ( V_28 > V_114 )
V_9 -> V_120 = F_67 ( V_28 ) ;
else
V_9 -> V_120 = F_68 ( V_28 , V_116 ) ;
if ( V_9 -> V_120 == NULL )
return - V_65 ;
if ( V_9 -> V_129 == 0 )
return 0 ;
V_28 = sizeof( void * ) * V_9 -> V_129 * 2u ;
F_60 (cpu) {
if ( V_28 > V_114 )
V_9 -> V_120 [ V_119 ] = F_69 ( V_28 ,
F_70 ( V_119 ) ) ;
else
V_9 -> V_120 [ V_119 ] = F_71 ( V_28 ,
V_116 , F_70 ( V_119 ) ) ;
if ( V_9 -> V_120 [ V_119 ] == NULL )
return - V_65 ;
}
return 0 ;
}
struct V_110 *
F_72 ( struct V_121 * V_45 ,
unsigned int V_106 ,
struct V_110 * V_130 ,
int * error )
{
struct V_110 * V_131 ;
int V_42 ;
V_42 = F_66 ( V_130 ) ;
if ( V_42 < 0 ) {
* error = V_42 ;
return NULL ;
}
F_73 () ;
V_131 = V_45 -> V_131 ;
if ( V_106 != V_131 -> V_63 ) {
F_74 ( L_22 ,
V_106 , V_131 -> V_63 ) ;
F_75 () ;
* error = - V_132 ;
return NULL ;
}
V_130 -> V_133 = V_131 -> V_133 ;
F_76 () ;
V_45 -> V_131 = V_130 ;
F_75 () ;
#ifdef F_77
if ( V_134 ) {
struct V_135 * V_136 ;
V_136 = F_78 ( V_137 -> V_138 , V_116 ,
V_139 ) ;
if ( V_136 ) {
F_79 ( V_136 , L_23 ,
V_45 -> V_13 , V_45 -> V_3 ,
V_131 -> V_63 ) ;
F_80 ( V_136 ) ;
}
}
#endif
return V_131 ;
}
struct V_121 * F_81 ( struct V_122 * V_122 ,
const struct V_121 * V_140 ,
struct V_110 * V_141 ,
struct V_110 * V_130 )
{
int V_42 ;
struct V_110 * V_131 ;
struct V_121 * V_22 , * V_45 ;
V_45 = F_82 ( V_140 , sizeof( struct V_121 ) , V_116 ) ;
if ( ! V_45 ) {
V_42 = - V_65 ;
goto V_125;
}
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_22 -> V_13 , V_45 -> V_13 ) == 0 ) {
V_42 = - V_142 ;
goto V_143;
}
}
V_45 -> V_131 = V_141 ;
if ( ! F_72 ( V_45 , 0 , V_130 , & V_42 ) )
goto V_143;
V_131 = V_45 -> V_131 ;
F_74 ( L_24 , V_131 -> V_63 ) ;
V_131 -> V_133 = V_131 -> V_63 ;
F_3 ( & V_45 -> V_7 , & V_122 -> V_5 . V_144 [ V_45 -> V_3 ] ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
return V_45 ;
V_143:
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_83 ( V_45 ) ;
V_125:
return F_16 ( V_42 ) ;
}
void * F_84 ( struct V_121 * V_45 )
{
struct V_110 * V_131 ;
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
V_131 = V_45 -> V_131 ;
F_6 ( & V_45 -> V_7 ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_83 ( V_45 ) ;
return V_131 ;
}
static void * F_85 ( struct V_145 * V_146 , T_8 * V_54 )
{
struct V_147 * V_148 = V_146 -> V_131 ;
struct V_122 * V_122 = F_86 ( V_146 ) ;
T_1 V_3 = V_148 -> V_3 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
return F_87 ( & V_122 -> V_5 . V_144 [ V_3 ] , * V_54 ) ;
}
static void * F_88 ( struct V_145 * V_146 , void * V_149 , T_8 * V_54 )
{
struct V_147 * V_148 = V_146 -> V_131 ;
struct V_122 * V_122 = F_86 ( V_146 ) ;
T_1 V_3 = V_148 -> V_3 ;
return F_89 ( V_149 , & V_122 -> V_5 . V_144 [ V_3 ] , V_54 ) ;
}
static void F_90 ( struct V_145 * V_146 , void * V_149 )
{
struct V_147 * V_148 = V_146 -> V_131 ;
T_1 V_3 = V_148 -> V_3 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
static int F_91 ( struct V_145 * V_146 , void * V_149 )
{
struct V_121 * V_45 = F_92 ( V_149 , struct V_121 , V_7 ) ;
if ( * V_45 -> V_13 )
F_93 ( V_146 , L_25 , V_45 -> V_13 ) ;
return 0 ;
}
static int F_94 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
int V_42 ;
struct V_147 * V_148 ;
V_42 = F_95 ( V_150 , V_151 , & V_152 ,
sizeof( struct V_147 ) ) ;
if ( ! V_42 ) {
V_148 = ( (struct V_145 * ) V_151 -> V_153 ) -> V_131 ;
V_148 -> V_3 = ( unsigned long ) F_96 ( V_150 ) ;
}
return V_42 ;
}
static void * F_97 ( struct V_145 * V_146 , void * V_149 , T_8 * V_154 ,
bool V_155 )
{
static const T_3 V_156 [] = {
[ V_157 ] = V_158 ,
[ V_158 ] = V_159 ,
} ;
struct V_160 * V_161 = V_146 -> V_131 ;
switch ( V_161 -> V_162 ) {
case V_163 :
V_161 -> V_162 = V_157 ;
F_2 ( & V_5 [ V_19 ] . V_6 ) ;
V_161 -> V_164 = V_161 -> V_165 = V_155 ?
& V_5 [ V_19 ] . V_2 : & V_5 [ V_19 ] . V_12 ;
break;
case V_157 :
V_161 -> V_165 = V_161 -> V_165 -> V_166 ;
if ( V_161 -> V_165 != V_161 -> V_164 )
break;
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
F_2 ( & V_5 [ V_161 -> V_20 ] . V_6 ) ;
V_161 -> V_164 = V_161 -> V_165 = V_155 ?
& V_5 [ V_161 -> V_20 ] . V_2 : & V_5 [ V_161 -> V_20 ] . V_12 ;
V_161 -> V_162 = V_156 [ V_161 -> V_162 ] ;
break;
case V_158 :
V_161 -> V_165 = V_161 -> V_165 -> V_166 ;
if ( V_161 -> V_165 != V_161 -> V_164 )
break;
default:
return NULL ;
}
if ( V_154 != NULL )
++ * V_154 ;
return V_161 ;
}
static void * F_98 ( struct V_145 * V_146 , T_8 * V_54 ,
bool V_155 )
{
struct V_160 * V_161 = V_146 -> V_131 ;
unsigned int V_167 ;
V_161 -> V_162 = V_163 ;
for ( V_167 = 0 ; V_167 < * V_54 ; ++ V_167 )
if ( F_97 ( V_146 , NULL , NULL , V_155 ) == NULL )
return NULL ;
return V_161 ;
}
static void F_99 ( struct V_145 * V_146 , void * V_149 )
{
struct V_160 * V_161 = V_146 -> V_131 ;
switch ( V_161 -> V_162 ) {
case V_157 :
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
break;
case V_158 :
F_4 ( & V_5 [ V_161 -> V_20 ] . V_6 ) ;
break;
}
}
static void * F_100 ( struct V_145 * V_146 , T_8 * V_54 )
{
return F_98 ( V_146 , V_54 , false ) ;
}
static void * F_101 ( struct V_145 * V_146 , void * V_149 , T_8 * V_154 )
{
return F_97 ( V_146 , V_149 , V_154 , false ) ;
}
static int F_102 ( struct V_145 * V_146 , void * V_149 )
{
const struct V_160 * V_161 = V_146 -> V_131 ;
const struct V_11 * V_12 ;
switch ( V_161 -> V_162 ) {
case V_157 :
case V_158 :
if ( V_161 -> V_165 == V_161 -> V_164 )
return 0 ;
V_12 = F_92 ( V_161 -> V_165 , struct V_11 , V_7 ) ;
if ( * V_12 -> V_13 )
F_93 ( V_146 , L_25 , V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_103 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
struct V_160 * V_161 ;
V_161 = F_104 ( V_151 , & V_168 , sizeof( * V_161 ) ) ;
if ( ! V_161 )
return - V_65 ;
V_161 -> V_20 = ( unsigned long ) F_96 ( V_150 ) ;
return 0 ;
}
static void * F_105 ( struct V_145 * V_146 , T_8 * V_54 )
{
return F_98 ( V_146 , V_54 , true ) ;
}
static void * F_106 ( struct V_145 * V_146 , void * V_149 , T_8 * V_154 )
{
return F_97 ( V_146 , V_149 , V_154 , true ) ;
}
static int F_107 ( struct V_145 * V_146 , void * V_149 )
{
const struct V_160 * V_161 = V_146 -> V_131 ;
const struct V_1 * V_2 ;
switch ( V_161 -> V_162 ) {
case V_157 :
case V_158 :
if ( V_161 -> V_165 == V_161 -> V_164 )
return 0 ;
V_2 = F_92 ( V_161 -> V_165 , struct V_1 , V_7 ) ;
if ( * V_2 -> V_13 )
F_93 ( V_146 , L_25 , V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_108 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
struct V_160 * V_161 ;
V_161 = F_104 ( V_151 , & V_169 , sizeof( * V_161 ) ) ;
if ( ! V_161 )
return - V_65 ;
V_161 -> V_20 = ( unsigned long ) F_96 ( V_150 ) ;
return 0 ;
}
struct V_170 *
F_109 ( const struct V_121 * V_45 , T_9 * V_171 )
{
unsigned int V_47 = V_45 -> V_172 ;
T_3 V_9 , V_173 = F_110 ( V_47 ) ;
T_3 V_174 ;
struct V_170 * V_175 ;
V_175 = F_58 ( sizeof( * V_175 ) * V_173 , V_116 ) ;
if ( V_175 == NULL )
return F_16 ( - V_65 ) ;
for ( V_9 = 0 , V_174 = 0 ; V_9 < V_173 && V_47 != 0 ;
V_47 >>= 1 , ++ V_174 ) {
if ( ! ( V_47 & 1 ) )
continue;
V_175 [ V_9 ] . V_176 = V_171 ;
V_175 [ V_9 ] . V_177 = V_45 -> V_3 ;
V_175 [ V_9 ] . V_174 = V_174 ;
V_175 [ V_9 ] . V_178 = V_45 -> V_178 ;
++ V_9 ;
}
return V_175 ;
}
int F_111 ( struct V_122 * V_122 , T_1 V_3 )
{
#ifdef F_112
char V_27 [ V_179 ] ;
struct V_180 * V_181 ;
T_10 V_182 ;
T_11 V_183 ;
#endif
if ( V_3 >= F_26 ( V_21 ) )
return - V_44 ;
#ifdef F_112
V_182 = F_113 ( V_122 -> V_184 , 0 ) ;
V_183 = F_114 ( V_122 -> V_184 , 0 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_185 , sizeof( V_27 ) ) ;
V_181 = F_116 ( V_27 , 0440 , V_122 -> V_186 , & V_187 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_181 )
goto V_125;
if ( F_117 ( V_182 ) && F_118 ( V_183 ) )
F_119 ( V_181 , V_182 , V_183 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_188 , sizeof( V_27 ) ) ;
V_181 = F_116 ( V_27 , 0440 , V_122 -> V_186 , & V_189 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_181 )
goto V_190;
if ( F_117 ( V_182 ) && F_118 ( V_183 ) )
F_119 ( V_181 , V_182 , V_183 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_191 , sizeof( V_27 ) ) ;
V_181 = F_116 ( V_27 , 0440 , V_122 -> V_186 , & V_192 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_181 )
goto V_193;
if ( F_117 ( V_182 ) && F_118 ( V_183 ) )
F_119 ( V_181 , V_182 , V_183 ) ;
#endif
return 0 ;
#ifdef F_112
V_193:
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_188 , sizeof( V_27 ) ) ;
F_120 ( V_27 , V_122 -> V_186 ) ;
V_190:
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_185 , sizeof( V_27 ) ) ;
F_120 ( V_27 , V_122 -> V_186 ) ;
V_125:
return - 1 ;
#endif
}
void F_121 ( struct V_122 * V_122 , T_1 V_3 )
{
#ifdef F_112
char V_27 [ V_179 ] ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_185 , sizeof( V_27 ) ) ;
F_120 ( V_27 , V_122 -> V_186 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_191 , sizeof( V_27 ) ) ;
F_120 ( V_27 , V_122 -> V_186 ) ;
F_40 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_115 ( V_27 , V_188 , sizeof( V_27 ) ) ;
F_120 ( V_27 , V_122 -> V_186 ) ;
#endif
}
static int T_12 F_122 ( struct V_122 * V_122 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_194 ; V_9 ++ )
F_123 ( & V_122 -> V_5 . V_144 [ V_9 ] ) ;
return 0 ;
}
static int T_13 F_124 ( void )
{
unsigned int V_9 ;
int V_195 ;
F_60 (i) {
F_125 ( & F_126 ( V_196 , V_9 ) ) ;
}
V_5 = F_58 ( sizeof( struct V_60 ) * V_194 , V_116 ) ;
if ( ! V_5 )
return - V_65 ;
for ( V_9 = 0 ; V_9 < V_194 ; V_9 ++ ) {
F_127 ( & V_5 [ V_9 ] . V_6 ) ;
#ifdef F_51
F_127 ( & V_5 [ V_9 ] . V_127 ) ;
V_5 [ V_9 ] . V_62 = NULL ;
#endif
F_123 ( & V_5 [ V_9 ] . V_2 ) ;
F_123 ( & V_5 [ V_9 ] . V_12 ) ;
}
V_195 = F_128 ( & V_197 ) ;
if ( V_195 < 0 )
F_83 ( V_5 ) ;
return V_195 ;
}
static void T_14 F_129 ( void )
{
F_130 ( & V_197 ) ;
F_83 ( V_5 ) ;
}
