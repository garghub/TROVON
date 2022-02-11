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
int F_30 ( T_1 V_3 , unsigned int V_52 , int V_53 )
{
struct V_54 * V_55 = & V_5 [ V_3 ] ;
if ( ! V_55 -> V_56 ) {
if ( ! V_55 -> V_57 )
return - V_44 ;
V_55 -> V_56 = F_31 ( sizeof( struct V_58 ) * V_55 -> V_57 ) ;
if ( ! V_55 -> V_56 )
return - V_59 ;
V_55 -> V_60 = 0 ;
}
if ( V_55 -> V_60 >= V_55 -> V_57 )
return - V_44 ;
if ( V_55 -> V_60 )
V_53 += V_55 -> V_56 [ V_55 -> V_60 - 1 ] . V_53 ;
V_55 -> V_56 [ V_55 -> V_60 ] . V_52 = V_52 ;
V_55 -> V_56 [ V_55 -> V_60 ] . V_53 = V_53 ;
V_55 -> V_60 ++ ;
return 0 ;
}
void F_32 ( T_1 V_3 )
{
if ( V_5 [ V_3 ] . V_56 ) {
F_33 ( V_5 [ V_3 ] . V_56 ) ;
V_5 [ V_3 ] . V_56 = NULL ;
V_5 [ V_3 ] . V_57 = 0 ;
V_5 [ V_3 ] . V_60 = 0 ;
}
}
int F_34 ( T_1 V_3 , unsigned int V_52 )
{
struct V_58 * V_61 = V_5 [ V_3 ] . V_56 ;
int V_62 , V_63 = 0 , V_64 = V_5 [ V_3 ] . V_60 - 1 ;
while ( V_63 <= V_64 ) {
V_62 = ( V_63 + V_64 ) >> 1 ;
if ( V_52 > V_61 [ V_62 ] . V_52 )
V_63 = V_62 + 1 ;
else if ( V_52 < V_61 [ V_62 ] . V_52 )
V_64 = V_62 - 1 ;
else
return V_62 ? V_61 [ V_62 - 1 ] . V_53 : 0 ;
}
return V_63 ? V_61 [ V_63 - 1 ] . V_53 : 0 ;
}
void F_35 ( T_1 V_3 , unsigned int V_57 )
{
V_5 [ V_3 ] . V_57 = V_57 ;
V_5 [ V_3 ] . V_60 = 0 ;
}
int F_36 ( const struct V_11 * V_12 )
{
T_5 V_65 = V_12 -> V_66 ? : V_12 -> V_43 ;
return F_28 ( V_12 -> V_43 ) - F_37 ( V_65 ) ;
}
int F_38 ( struct V_67 * V_15 , void * * V_68 ,
unsigned int * V_28 )
{
const struct V_11 * V_12 = V_15 -> V_69 . V_70 . V_12 ;
struct V_71 * V_72 = (struct V_71 * ) V_15 ;
int V_73 , V_74 = F_36 ( V_12 ) ;
T_5 V_75 = V_72 -> V_69 . V_76 . V_77 ;
V_15 = * V_68 ;
memcpy ( V_15 , V_72 , sizeof( * V_72 ) ) ;
if ( V_12 -> V_78 )
V_12 -> V_78 ( V_15 -> V_79 , V_72 -> V_79 ) ;
else
memcpy ( V_15 -> V_79 , V_72 -> V_79 , V_75 - sizeof( * V_72 ) ) ;
V_73 = F_28 ( V_12 -> V_43 ) - V_12 -> V_43 ;
if ( V_73 > 0 )
memset ( V_15 -> V_79 + V_12 -> V_43 , 0 , V_73 ) ;
V_75 += V_74 ;
V_15 -> V_69 . V_76 . V_77 = V_75 ;
* V_28 += V_74 ;
* V_68 += V_75 ;
return 0 ;
}
int F_39 ( const struct V_67 * V_15 ,
void T_6 * * V_68 , unsigned int * V_28 )
{
const struct V_11 * V_12 = V_15 -> V_69 . V_70 . V_12 ;
struct V_71 T_6 * V_72 = * V_68 ;
int V_74 = F_36 ( V_12 ) ;
T_5 V_75 = V_15 -> V_69 . V_76 . V_77 - V_74 ;
if ( F_40 ( V_72 , V_15 , sizeof( * V_72 ) ) ||
F_41 ( V_75 , & V_72 -> V_69 . V_76 . V_77 ) ||
F_40 ( V_72 -> V_69 . V_76 . V_13 , V_15 -> V_69 . V_70 . V_12 -> V_13 ,
strlen ( V_15 -> V_69 . V_70 . V_12 -> V_13 ) + 1 ) )
return - V_80 ;
if ( V_12 -> V_81 ) {
if ( V_12 -> V_81 ( ( void T_6 * ) V_72 -> V_79 , V_15 -> V_79 ) )
return - V_80 ;
} else {
if ( F_40 ( V_72 -> V_79 , V_15 -> V_79 , V_75 - sizeof( * V_72 ) ) )
return - V_80 ;
}
* V_28 -= V_74 ;
* V_68 += V_75 ;
return 0 ;
}
int F_42 ( struct V_82 * V_39 ,
unsigned int V_28 , T_1 V_40 , bool V_41 )
{
int V_42 ;
if ( F_28 ( V_39 -> V_2 -> V_83 ) != V_28 ) {
F_29 ( L_17
L_12 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_14 ,
F_28 ( V_39 -> V_2 -> V_83 ) , V_28 ) ;
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
int F_43 ( const struct V_1 * V_2 )
{
T_5 V_65 = V_2 -> V_66 ? : V_2 -> V_83 ;
return F_28 ( V_2 -> V_83 ) - F_37 ( V_65 ) ;
}
void F_44 ( struct V_84 * V_22 , void * * V_68 ,
unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_69 . V_70 . V_2 ;
struct V_85 * V_86 = (struct V_85 * ) V_22 ;
int V_73 , V_74 = F_43 ( V_2 ) ;
T_5 V_87 = V_86 -> V_69 . V_76 . V_88 ;
V_22 = * V_68 ;
memcpy ( V_22 , V_86 , sizeof( * V_86 ) ) ;
if ( V_2 -> V_78 )
V_2 -> V_78 ( V_22 -> V_79 , V_86 -> V_79 ) ;
else
memcpy ( V_22 -> V_79 , V_86 -> V_79 , V_87 - sizeof( * V_86 ) ) ;
V_73 = F_28 ( V_2 -> V_83 ) - V_2 -> V_83 ;
if ( V_73 > 0 )
memset ( V_22 -> V_79 + V_2 -> V_83 , 0 , V_73 ) ;
V_87 += V_74 ;
V_22 -> V_69 . V_76 . V_88 = V_87 ;
* V_28 += V_74 ;
* V_68 += V_87 ;
}
int F_45 ( const struct V_84 * V_22 ,
void T_6 * * V_68 , unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_69 . V_70 . V_2 ;
struct V_85 T_6 * V_86 = * V_68 ;
int V_74 = F_43 ( V_2 ) ;
T_5 V_87 = V_22 -> V_69 . V_76 . V_88 - V_74 ;
if ( F_40 ( V_86 , V_22 , sizeof( * V_86 ) ) ||
F_41 ( V_87 , & V_86 -> V_69 . V_76 . V_88 ) ||
F_40 ( V_86 -> V_69 . V_76 . V_13 , V_22 -> V_69 . V_70 . V_2 -> V_13 ,
strlen ( V_22 -> V_69 . V_70 . V_2 -> V_13 ) + 1 ) )
return - V_80 ;
if ( V_2 -> V_81 ) {
if ( V_2 -> V_81 ( ( void T_6 * ) V_86 -> V_79 , V_22 -> V_79 ) )
return - V_80 ;
} else {
if ( F_40 ( V_86 -> V_79 , V_22 -> V_79 , V_87 - sizeof( * V_86 ) ) )
return - V_80 ;
}
* V_28 -= V_74 ;
* V_68 += V_87 ;
return 0 ;
}
struct V_89 * F_46 ( unsigned int V_28 )
{
struct V_89 * V_90 ;
int V_91 ;
if ( ( F_47 ( V_28 ) >> V_92 ) + 2 > V_93 )
return NULL ;
V_90 = F_48 ( V_94 , V_95 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_28 = V_28 ;
F_49 (cpu) {
if ( V_28 <= V_96 )
V_90 -> V_97 [ V_91 ] = F_50 ( V_28 ,
V_95 ,
F_51 ( V_91 ) ) ;
else
V_90 -> V_97 [ V_91 ] = F_52 ( V_28 ,
F_51 ( V_91 ) ) ;
if ( V_90 -> V_97 [ V_91 ] == NULL ) {
F_53 ( V_90 ) ;
return NULL ;
}
}
return V_90 ;
}
void F_53 ( struct V_89 * V_98 )
{
int V_91 ;
F_49 (cpu)
F_54 ( V_98 -> V_97 [ V_91 ] ) ;
if ( V_98 -> V_99 != NULL ) {
F_49 (cpu)
F_54 ( V_98 -> V_99 [ V_91 ] ) ;
F_54 ( V_98 -> V_99 ) ;
}
F_55 ( V_98 -> V_100 ) ;
F_56 ( V_98 ) ;
}
struct V_101 * F_57 ( struct V_102 * V_102 , T_1 V_3 ,
const char * V_13 )
{
struct V_101 * V_22 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 && F_15 ( V_22 -> V_17 ) )
return V_22 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
void F_58 ( struct V_101 * V_45 )
{
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
}
void F_59 ( T_1 V_3 )
{
F_2 ( & V_5 [ V_3 ] . V_103 ) ;
}
void F_60 ( T_1 V_3 )
{
F_4 ( & V_5 [ V_3 ] . V_103 ) ;
}
static int F_61 ( struct V_89 * V_9 )
{
unsigned int V_28 ;
int V_91 ;
V_9 -> V_100 = F_62 (unsigned int) ;
if ( V_9 -> V_100 == NULL )
return - V_59 ;
V_28 = sizeof( void * * ) * V_104 ;
if ( V_28 > V_96 )
V_9 -> V_99 = F_63 ( V_28 ) ;
else
V_9 -> V_99 = F_48 ( V_28 , V_95 ) ;
if ( V_9 -> V_99 == NULL )
return - V_59 ;
V_9 -> V_105 *= V_106 ;
V_28 = sizeof( void * ) * V_9 -> V_105 ;
F_49 (cpu) {
if ( V_28 > V_96 )
V_9 -> V_99 [ V_91 ] = F_52 ( V_28 ,
F_51 ( V_91 ) ) ;
else
V_9 -> V_99 [ V_91 ] = F_50 ( V_28 ,
V_95 , F_51 ( V_91 ) ) ;
if ( V_9 -> V_99 [ V_91 ] == NULL )
return - V_59 ;
}
return 0 ;
}
struct V_89 *
F_64 ( struct V_101 * V_45 ,
unsigned int V_107 ,
struct V_89 * V_90 ,
int * error )
{
struct V_89 * V_108 ;
int V_42 ;
V_42 = F_61 ( V_90 ) ;
if ( V_42 < 0 ) {
* error = V_42 ;
return NULL ;
}
F_65 () ;
V_108 = V_45 -> V_108 ;
if ( V_107 != V_108 -> V_57 ) {
F_66 ( L_22 ,
V_107 , V_108 -> V_57 ) ;
F_67 () ;
* error = - V_109 ;
return NULL ;
}
V_90 -> V_110 = V_108 -> V_110 ;
F_68 () ;
V_45 -> V_108 = V_90 ;
F_67 () ;
#ifdef F_69
if ( V_111 ) {
struct V_112 * V_113 ;
V_113 = F_70 ( V_114 -> V_115 , V_95 ,
V_116 ) ;
if ( V_113 ) {
F_71 ( V_113 , L_23 ,
V_45 -> V_13 , V_45 -> V_3 ,
V_108 -> V_57 ) ;
F_72 ( V_113 ) ;
}
}
#endif
return V_108 ;
}
struct V_101 * F_73 ( struct V_102 * V_102 ,
const struct V_101 * V_117 ,
struct V_89 * V_118 ,
struct V_89 * V_90 )
{
int V_42 ;
struct V_89 * V_108 ;
struct V_101 * V_22 , * V_45 ;
V_45 = F_74 ( V_117 , sizeof( struct V_101 ) , V_95 ) ;
if ( ! V_45 ) {
V_42 = - V_59 ;
goto V_119;
}
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_22 -> V_13 , V_45 -> V_13 ) == 0 ) {
V_42 = - V_120 ;
goto V_121;
}
}
V_45 -> V_108 = V_118 ;
if ( ! F_64 ( V_45 , 0 , V_90 , & V_42 ) )
goto V_121;
V_108 = V_45 -> V_108 ;
F_66 ( L_24 , V_108 -> V_57 ) ;
V_108 -> V_110 = V_108 -> V_57 ;
F_3 ( & V_45 -> V_7 , & V_102 -> V_5 . V_122 [ V_45 -> V_3 ] ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
return V_45 ;
V_121:
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_56 ( V_45 ) ;
V_119:
return F_16 ( V_42 ) ;
}
void * F_75 ( struct V_101 * V_45 )
{
struct V_89 * V_108 ;
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
V_108 = V_45 -> V_108 ;
F_6 ( & V_45 -> V_7 ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_56 ( V_45 ) ;
return V_108 ;
}
static void * F_76 ( struct V_123 * V_124 , T_7 * V_125 )
{
struct V_126 * V_127 = V_124 -> V_108 ;
struct V_102 * V_102 = F_77 ( V_124 ) ;
T_1 V_3 = V_127 -> V_3 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
return F_78 ( & V_102 -> V_5 . V_122 [ V_3 ] , * V_125 ) ;
}
static void * F_79 ( struct V_123 * V_124 , void * V_128 , T_7 * V_125 )
{
struct V_126 * V_127 = V_124 -> V_108 ;
struct V_102 * V_102 = F_77 ( V_124 ) ;
T_1 V_3 = V_127 -> V_3 ;
return F_80 ( V_128 , & V_102 -> V_5 . V_122 [ V_3 ] , V_125 ) ;
}
static void F_81 ( struct V_123 * V_124 , void * V_128 )
{
struct V_126 * V_127 = V_124 -> V_108 ;
T_1 V_3 = V_127 -> V_3 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
static int F_82 ( struct V_123 * V_124 , void * V_128 )
{
struct V_101 * V_45 = F_83 ( V_128 , struct V_101 , V_7 ) ;
if ( strlen ( V_45 -> V_13 ) )
return F_84 ( V_124 , L_25 , V_45 -> V_13 ) ;
else
return 0 ;
}
static int F_85 ( struct V_129 * V_129 , struct V_130 * V_130 )
{
int V_42 ;
struct V_126 * V_127 ;
V_42 = F_86 ( V_129 , V_130 , & V_131 ,
sizeof( struct V_126 ) ) ;
if ( ! V_42 ) {
V_127 = ( (struct V_123 * ) V_130 -> V_132 ) -> V_108 ;
V_127 -> V_3 = ( unsigned long ) F_87 ( V_129 ) ;
}
return V_42 ;
}
static void * F_88 ( struct V_123 * V_124 , void * V_128 , T_7 * V_133 ,
bool V_134 )
{
static const T_3 V_135 [] = {
[ V_136 ] = V_137 ,
[ V_137 ] = V_138 ,
} ;
struct V_139 * V_140 = V_124 -> V_108 ;
switch ( V_140 -> V_141 ) {
case V_142 :
V_140 -> V_141 = V_136 ;
F_2 ( & V_5 [ V_19 ] . V_6 ) ;
V_140 -> V_143 = V_140 -> V_144 = V_134 ?
& V_5 [ V_19 ] . V_2 : & V_5 [ V_19 ] . V_12 ;
break;
case V_136 :
V_140 -> V_144 = V_140 -> V_144 -> V_145 ;
if ( V_140 -> V_144 != V_140 -> V_143 )
break;
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
F_2 ( & V_5 [ V_140 -> V_20 ] . V_6 ) ;
V_140 -> V_143 = V_140 -> V_144 = V_134 ?
& V_5 [ V_140 -> V_20 ] . V_2 : & V_5 [ V_140 -> V_20 ] . V_12 ;
V_140 -> V_141 = V_135 [ V_140 -> V_141 ] ;
break;
case V_137 :
V_140 -> V_144 = V_140 -> V_144 -> V_145 ;
if ( V_140 -> V_144 != V_140 -> V_143 )
break;
default:
return NULL ;
}
if ( V_133 != NULL )
++ * V_133 ;
return V_140 ;
}
static void * F_89 ( struct V_123 * V_124 , T_7 * V_125 ,
bool V_134 )
{
struct V_139 * V_140 = V_124 -> V_108 ;
unsigned int V_146 ;
V_140 -> V_141 = V_142 ;
for ( V_146 = 0 ; V_146 < * V_125 ; ++ V_146 )
if ( F_88 ( V_124 , NULL , NULL , V_134 ) == NULL )
return NULL ;
return V_140 ;
}
static void F_90 ( struct V_123 * V_124 , void * V_128 )
{
struct V_139 * V_140 = V_124 -> V_108 ;
switch ( V_140 -> V_141 ) {
case V_136 :
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
break;
case V_137 :
F_4 ( & V_5 [ V_140 -> V_20 ] . V_6 ) ;
break;
}
}
static void * F_91 ( struct V_123 * V_124 , T_7 * V_125 )
{
return F_89 ( V_124 , V_125 , false ) ;
}
static void * F_92 ( struct V_123 * V_124 , void * V_128 , T_7 * V_133 )
{
return F_88 ( V_124 , V_128 , V_133 , false ) ;
}
static int F_93 ( struct V_123 * V_124 , void * V_128 )
{
const struct V_139 * V_140 = V_124 -> V_108 ;
const struct V_11 * V_12 ;
switch ( V_140 -> V_141 ) {
case V_136 :
case V_137 :
if ( V_140 -> V_144 == V_140 -> V_143 )
return 0 ;
V_12 = F_83 ( V_140 -> V_144 , struct V_11 , V_7 ) ;
return ( * V_12 -> V_13 == '\0' ) ? 0 :
F_84 ( V_124 , L_25 , V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_94 ( struct V_129 * V_129 , struct V_130 * V_130 )
{
struct V_123 * V_124 ;
struct V_139 * V_140 ;
int V_42 ;
V_140 = F_95 ( sizeof( * V_140 ) , V_95 ) ;
if ( V_140 == NULL )
return - V_59 ;
V_42 = F_96 ( V_130 , & V_147 ) ;
if ( V_42 < 0 ) {
F_56 ( V_140 ) ;
return V_42 ;
}
V_124 = V_130 -> V_132 ;
V_124 -> V_108 = V_140 ;
V_140 -> V_20 = ( unsigned long ) F_87 ( V_129 ) ;
return 0 ;
}
static void * F_97 ( struct V_123 * V_124 , T_7 * V_125 )
{
return F_89 ( V_124 , V_125 , true ) ;
}
static void * F_98 ( struct V_123 * V_124 , void * V_128 , T_7 * V_133 )
{
return F_88 ( V_124 , V_128 , V_133 , true ) ;
}
static int F_99 ( struct V_123 * V_124 , void * V_128 )
{
const struct V_139 * V_140 = V_124 -> V_108 ;
const struct V_1 * V_2 ;
switch ( V_140 -> V_141 ) {
case V_136 :
case V_137 :
if ( V_140 -> V_144 == V_140 -> V_143 )
return 0 ;
V_2 = F_83 ( V_140 -> V_144 , struct V_1 , V_7 ) ;
return ( * V_2 -> V_13 == '\0' ) ? 0 :
F_84 ( V_124 , L_25 , V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_100 ( struct V_129 * V_129 , struct V_130 * V_130 )
{
struct V_123 * V_124 ;
struct V_139 * V_140 ;
int V_42 ;
V_140 = F_95 ( sizeof( * V_140 ) , V_95 ) ;
if ( V_140 == NULL )
return - V_59 ;
V_42 = F_96 ( V_130 , & V_148 ) ;
if ( V_42 < 0 ) {
F_56 ( V_140 ) ;
return V_42 ;
}
V_124 = V_130 -> V_132 ;
V_124 -> V_108 = V_140 ;
V_140 -> V_20 = ( unsigned long ) F_87 ( V_129 ) ;
return 0 ;
}
struct V_149 * F_101 ( const struct V_101 * V_45 , T_8 * V_150 )
{
unsigned int V_47 = V_45 -> V_151 ;
T_3 V_9 , V_152 = F_102 ( V_47 ) ;
T_3 V_153 ;
struct V_149 * V_154 ;
int V_42 ;
V_154 = F_95 ( sizeof( * V_154 ) * V_152 , V_95 ) ;
if ( V_154 == NULL )
return F_16 ( - V_59 ) ;
for ( V_9 = 0 , V_153 = 0 ; V_9 < V_152 && V_47 != 0 ;
V_47 >>= 1 , ++ V_153 ) {
if ( ! ( V_47 & 1 ) )
continue;
V_154 [ V_9 ] . V_155 = V_150 ;
V_154 [ V_9 ] . V_156 = V_45 -> V_17 ;
V_154 [ V_9 ] . V_157 = V_45 -> V_3 ;
V_154 [ V_9 ] . V_153 = V_153 ;
V_154 [ V_9 ] . V_158 = V_45 -> V_158 ;
++ V_9 ;
}
V_42 = F_103 ( V_154 , V_152 ) ;
if ( V_42 < 0 ) {
F_56 ( V_154 ) ;
return F_16 ( V_42 ) ;
}
return V_154 ;
}
void F_104 ( const struct V_101 * V_45 , struct V_149 * V_154 )
{
F_105 ( V_154 , F_102 ( V_45 -> V_151 ) ) ;
F_56 ( V_154 ) ;
}
int F_106 ( struct V_102 * V_102 , T_1 V_3 )
{
#ifdef F_107
char V_27 [ V_159 ] ;
struct V_160 * V_161 ;
#endif
if ( V_3 >= F_26 ( V_21 ) )
return - V_44 ;
#ifdef F_107
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_162 , sizeof( V_27 ) ) ;
V_161 = F_110 ( V_27 , 0440 , V_102 -> V_163 , & V_164 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_161 )
goto V_119;
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_165 , sizeof( V_27 ) ) ;
V_161 = F_110 ( V_27 , 0440 , V_102 -> V_163 , & V_166 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_161 )
goto V_167;
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_168 , sizeof( V_27 ) ) ;
V_161 = F_110 ( V_27 , 0440 , V_102 -> V_163 , & V_169 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_161 )
goto V_170;
#endif
return 0 ;
#ifdef F_107
V_170:
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_165 , sizeof( V_27 ) ) ;
F_111 ( V_27 , V_102 -> V_163 ) ;
V_167:
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_162 , sizeof( V_27 ) ) ;
F_111 ( V_27 , V_102 -> V_163 ) ;
V_119:
return - 1 ;
#endif
}
void F_112 ( struct V_102 * V_102 , T_1 V_3 )
{
#ifdef F_107
char V_27 [ V_159 ] ;
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_162 , sizeof( V_27 ) ) ;
F_111 ( V_27 , V_102 -> V_163 ) ;
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_168 , sizeof( V_27 ) ) ;
F_111 ( V_27 , V_102 -> V_163 ) ;
F_108 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_109 ( V_27 , V_165 , sizeof( V_27 ) ) ;
F_111 ( V_27 , V_102 -> V_163 ) ;
#endif
}
static int T_9 F_113 ( struct V_102 * V_102 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_171 ; V_9 ++ )
F_114 ( & V_102 -> V_5 . V_122 [ V_9 ] ) ;
return 0 ;
}
static int T_10 F_115 ( void )
{
unsigned int V_9 ;
int V_172 ;
F_49 (i) {
F_116 ( & F_117 ( V_173 , V_9 ) ) ;
}
V_5 = F_95 ( sizeof( struct V_54 ) * V_171 , V_95 ) ;
if ( ! V_5 )
return - V_59 ;
for ( V_9 = 0 ; V_9 < V_171 ; V_9 ++ ) {
F_118 ( & V_5 [ V_9 ] . V_6 ) ;
#ifdef F_119
F_118 ( & V_5 [ V_9 ] . V_103 ) ;
V_5 [ V_9 ] . V_56 = NULL ;
#endif
F_114 ( & V_5 [ V_9 ] . V_2 ) ;
F_114 ( & V_5 [ V_9 ] . V_12 ) ;
}
V_172 = F_120 ( & V_174 ) ;
if ( V_172 < 0 )
F_56 ( V_5 ) ;
return V_172 ;
}
static void T_11 F_121 ( void )
{
F_122 ( & V_174 ) ;
F_56 ( V_5 ) ;
}
