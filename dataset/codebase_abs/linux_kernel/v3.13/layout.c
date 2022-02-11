int F_1 ( void )
{
int V_1 ;
int V_2 ;
int V_3 ;
struct V_4 * V_5 = NULL ;
for ( V_1 = 0 ; V_1 < F_2 ( V_6 ) ; ++ V_1 ) {
V_5 = V_6 [ V_1 ] ;
V_5 -> V_7 = V_1 ;
for ( V_2 = 0 ; V_2 < V_8 ; ++ V_2 ) {
F_3 ( V_5 -> V_9 [ V_2 ] . V_10 <= V_11 ) ;
for ( V_3 = 0 ; V_3 < V_5 -> V_9 [ V_2 ] . V_10 ; ++ V_3 ) {
struct V_12 * V_13 ;
V_13 = ( F_4 ( V_13 ) ) V_5 -> V_9 [ V_2 ] . V_14 [ V_3 ] ;
F_3 ( ! ( V_13 -> V_15 & V_16 )
|| V_13 -> V_17 > 0 ) ;
F_3 ( V_13 -> V_18 [ V_1 ] [ V_2 ] == 0 ) ;
V_13 -> V_18 [ V_1 ] [ V_2 ] = V_3 + 1 ;
}
}
}
return 0 ;
}
void F_5 ( void )
{
}
void F_6 ( struct V_19 * V_20 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_20 -> V_21 [ V_22 ] ) ; V_1 ++ ) {
V_20 -> V_21 [ V_22 ] [ V_1 ] = - 1 ;
V_20 -> V_21 [ V_23 ] [ V_1 ] = - 1 ;
}
}
void F_7 ( struct V_19 * V_20 ,
struct V_24 * V_25 ,
enum V_26 V_27 )
{
F_3 ( V_27 == V_23 || V_27 == V_22 ) ;
if ( V_25 != NULL && V_20 == & V_25 -> V_28 && V_25 -> V_29 )
return;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_30 = V_25 ;
V_20 -> V_31 = V_27 ;
F_6 ( V_20 ) ;
if ( V_25 != NULL && V_20 == & V_25 -> V_28 )
V_25 -> V_29 = 1 ;
}
void F_8 ( struct V_19 * V_20 )
{
}
static int F_9 ( const struct V_4 * V_32 )
{
return
0 <= V_32 -> V_7 && V_32 -> V_7 < F_2 ( V_6 ) &&
V_6 [ V_32 -> V_7 ] == V_32 ;
}
static struct V_33 * F_10 ( const struct V_19 * V_20 ,
enum V_26 V_34 )
{
struct V_24 * V_25 ;
V_25 = V_20 -> V_30 ;
return V_34 == V_22 ? V_25 -> V_35 : V_25 -> V_36 ;
}
void F_11 ( struct V_19 * V_20 , const struct V_4 * V_32 )
{
F_3 ( V_20 -> V_37 == NULL || V_20 -> V_37 == V_32 ) ;
F_3 ( F_9 ( V_32 ) ) ;
V_20 -> V_37 = V_32 ;
}
int F_12 ( struct V_19 * V_20 ,
enum V_26 V_34 )
{
const struct V_4 * V_32 = V_20 -> V_37 ;
int V_1 ;
F_3 ( V_32 != NULL ) ;
for ( V_1 = 0 ; V_1 < V_32 -> V_9 [ V_34 ] . V_10 ; ++ V_1 ) {
if ( V_20 -> V_21 [ V_34 ] [ V_1 ] == - 1 ) {
V_20 -> V_21 [ V_34 ] [ V_1 ] =
V_32 -> V_9 [ V_34 ] . V_14 [ V_1 ] -> V_17 ;
if ( V_20 -> V_21 [ V_34 ] [ V_1 ] == - 1 ) {
F_3 ( V_34 != V_23 ) ;
break;
}
}
}
return V_1 ;
}
int F_13 ( struct V_19 * V_20 )
{
const struct V_4 * V_32 ;
int V_38 ;
int V_39 ;
F_3 ( V_20 -> V_31 == V_23 ) ;
V_32 = V_20 -> V_37 ;
F_3 ( V_32 != NULL ) ;
V_38 = F_12 ( V_20 , V_23 ) ;
V_39 = F_14 ( V_20 -> V_30 , V_38 ,
V_20 -> V_21 [ V_23 ] , NULL ) ;
if ( V_39 != 0 ) {
F_15 ( V_40 , V_20 -> V_30 ,
L_1 ,
V_38 , V_32 -> V_41 ) ;
}
return V_39 ;
}
static int F_16 ( const struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 )
{
int V_42 ;
V_42 = V_13 -> V_18 [ V_20 -> V_37 -> V_7 ] [ V_34 ] ;
F_17 ( V_42 > 0 , L_2 ,
V_20 -> V_37 -> V_41 ,
V_13 -> V_43 , V_42 , V_34 ) ;
V_42 -- ;
F_3 ( 0 <= V_42 && V_42 < V_11 ) ;
return V_42 ;
}
static
void
F_18 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 ,
int V_42 ,
void * V_44 , int V_45 , int V_46 , void (* F_19)( void * ) )
{
void * V_47 ;
int V_1 ;
int V_48 ;
int V_49 ;
int V_50 = V_34 == V_22 ;
F_19 = F_19 ? : V_13 -> V_51 ;
if ( F_20 ( V_20 -> V_30 , V_50 , V_42 ) &&
F_19 != NULL && V_44 != NULL )
V_49 = 1 ;
else
V_49 = 0 ;
if ( ! ( V_13 -> V_15 & V_16 ) ) {
if ( V_46 && V_13 -> V_52 ) {
F_21 ( V_53 , L_3 ,
V_49 ? L_4 : L_5 , V_13 -> V_43 ) ;
V_13 -> V_52 ( V_44 ) ;
}
if ( ! V_49 )
return;
F_19 ( V_44 ) ;
F_22 ( V_20 -> V_30 , V_50 , V_42 ) ;
if ( V_46 ) {
F_21 ( V_53 , L_6
L_7 , V_13 -> V_43 ) ;
V_13 -> V_52 ( V_44 ) ;
}
return;
}
F_3 ( ( V_45 % V_13 -> V_17 ) == 0 ) ;
for ( V_47 = V_44 , V_1 = 0 , V_48 = V_45 / V_13 -> V_17 ;
V_1 < V_48 ;
V_1 ++ , V_47 += V_13 -> V_17 ) {
if ( V_46 && V_13 -> V_52 ) {
F_21 ( V_53 , L_8
L_9 ,
V_49 ? L_4 : L_5 , V_13 -> V_43 , V_1 ) ;
V_13 -> V_52 ( V_47 ) ;
}
if ( ! V_49 )
continue;
F_19 ( V_47 ) ;
if ( V_46 && V_13 -> V_52 ) {
F_21 ( V_53 , L_10
L_9 , V_13 -> V_43 , V_1 ) ;
V_13 -> V_52 ( V_44 ) ;
}
}
if ( V_49 )
F_22 ( V_20 -> V_30 , V_50 , V_42 ) ;
}
static void * F_23 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 ,
void (* F_19)( void * ) ,
int V_46 )
{
const struct V_4 * V_32 ;
struct V_33 * V_54 ;
void * V_44 ;
int V_45 ;
int V_42 ;
void * (* F_24)( struct V_33 * V_55 , int V_48 , int V_56 );
static const char * V_57 [ V_8 ] = {
[ V_22 ] = L_11 ,
[ V_23 ] = L_12
} ;
F_3 ( V_20 != NULL ) ;
F_3 ( V_20 != V_58 ) ;
V_32 = V_20 -> V_37 ;
F_3 ( V_32 != NULL ) ;
F_3 ( V_32 != V_58 ) ;
F_3 ( F_9 ( V_32 ) ) ;
V_42 = F_16 ( V_20 , V_13 , V_34 ) ;
V_54 = F_10 ( V_20 , V_34 ) ;
F_3 ( V_54 != NULL ) ;
F_24 = ( V_13 -> V_15 & V_59 ) ?
( F_4 ( F_24 ) ) V_60 : V_61 ;
if ( V_13 -> V_15 & V_16 ) {
V_45 = F_25 ( V_54 , V_42 ) ;
if ( ( V_45 % V_13 -> V_17 ) != 0 ) {
F_26 ( L_13
L_14 ,
V_13 -> V_43 , V_45 , V_13 -> V_17 , V_34 ) ;
return NULL ;
}
} else if ( V_20 -> V_21 [ V_34 ] [ V_42 ] != - 1 ) {
V_45 = V_20 -> V_21 [ V_34 ] [ V_42 ] ;
} else {
V_45 = F_27 ( V_13 -> V_17 , 0 ) ;
}
V_44 = F_24 ( V_54 , V_42 , V_45 ) ;
if ( V_44 == NULL ) {
F_15 ( V_40 , V_20 -> V_30 ,
L_15
L_16 ,
V_13 -> V_43 , V_42 , F_28 ( V_54 ) ,
V_32 -> V_41 , F_25 ( V_54 , V_42 ) , V_45 ,
V_57 [ V_34 ] ) ;
} else {
F_18 ( V_20 , V_13 , V_34 , V_42 , V_44 , V_45 ,
V_46 , F_19 ) ;
}
return V_44 ;
}
void F_29 ( struct V_19 * V_20 , enum V_26 V_34 )
{
const struct V_4 * V_32 ;
const struct V_12 * V_13 ;
int V_45 ;
int V_1 ;
V_32 = V_20 -> V_37 ;
F_15 ( V_53 , V_20 -> V_30 , L_17 ) ;
for ( V_1 = 0 ; V_1 < V_32 -> V_9 [ V_34 ] . V_10 ; ++ V_1 ) {
V_13 = F_30 ( V_32 , V_34 , V_1 ) ;
if ( V_13 -> V_52 == NULL ) {
V_45 = F_31 ( V_20 , V_13 , V_34 ) ;
F_21 ( V_53 , L_18
L_19 , V_13 -> V_43 , V_45 ) ;
} else {
( void ) F_23 ( V_20 , V_13 , V_34 , NULL , 1 ) ;
}
}
F_21 ( V_53 , L_20 ) ;
}
void F_32 ( struct V_19 * V_20 )
{
F_29 ( V_20 , V_22 ) ;
}
void F_33 ( struct V_19 * V_20 )
{
F_29 ( V_20 , V_23 ) ;
}
void * F_34 ( struct V_19 * V_20 ,
const struct V_12 * V_13 )
{
return F_23 ( V_20 , V_13 , V_22 , NULL , 0 ) ;
}
void * F_35 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
void * F_19 )
{
return F_23 ( V_20 , V_13 , V_22 , F_19 , 0 ) ;
}
void * F_36 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
int V_45 )
{
F_37 ( V_20 , V_13 , V_22 , V_45 ) ;
return F_23 ( V_20 , V_13 , V_22 , NULL , 0 ) ;
}
void * F_38 ( struct V_19 * V_20 ,
const struct V_12 * V_13 )
{
return F_23 ( V_20 , V_13 , V_23 , NULL , 0 ) ;
}
void * F_39 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
void * F_19 )
{
return F_23 ( V_20 , V_13 , V_23 , F_19 , 0 ) ;
}
void * F_40 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
int V_45 )
{
F_37 ( V_20 , V_13 , V_23 , V_45 ) ;
return F_23 ( V_20 , V_13 , V_23 , NULL , 0 ) ;
}
void * F_41 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
int V_45 , void * F_19 )
{
F_37 ( V_20 , V_13 , V_23 , V_45 ) ;
return F_23 ( V_20 , V_13 , V_23 , F_19 , 0 ) ;
}
const void * F_42 ( struct V_19 * V_20 ,
const struct V_12 * V_13 )
{
return F_23 ( V_20 , V_13 , V_20 -> V_31 ^ 1 , NULL , 0 ) ;
}
void F_37 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 , int V_62 )
{
F_3 ( V_34 == V_23 || V_34 == V_22 ) ;
if ( ( V_62 != V_13 -> V_17 ) &&
( V_13 -> V_17 != - 1 ) &&
! ( V_13 -> V_15 & V_63 ) &&
( V_62 > 0 ) ) {
if ( ( V_13 -> V_15 & V_16 ) &&
( V_62 % V_13 -> V_17 != 0 ) ) {
F_26 ( L_13
L_21 ,
V_13 -> V_43 , V_62 , V_13 -> V_17 , V_34 ) ;
F_43 () ;
} else if ( ! ( V_13 -> V_15 & V_16 ) &&
V_62 < V_13 -> V_17 ) {
F_26 ( L_22 ,
V_13 -> V_43 , V_62 , V_13 -> V_17 , V_34 ) ;
F_43 () ;
}
}
V_20 -> V_21 [ V_34 ] [ F_16 ( V_20 , V_13 , V_34 ) ] = V_62 ;
}
int F_31 ( const struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 )
{
F_3 ( V_34 == V_23 || V_34 == V_22 ) ;
return F_25 ( F_10 ( V_20 , V_34 ) ,
F_16 ( V_20 , V_13 , V_34 ) ) ;
}
int F_44 ( struct V_19 * V_20 , enum V_26 V_34 )
{
return F_45 ( V_20 -> V_30 -> V_64 -> V_65 ,
V_20 -> V_37 -> V_9 [ V_34 ] . V_10 ,
V_20 -> V_21 [ V_34 ] ) ;
}
int F_46 ( T_1 V_66 , const struct V_4 * V_32 ,
enum V_26 V_34 )
{
int V_62 , V_1 = 0 ;
V_62 = F_47 ( V_66 , V_32 -> V_9 [ V_34 ] . V_10 ) ;
if ( V_62 < 0 )
return V_62 ;
for (; V_1 < V_32 -> V_9 [ V_34 ] . V_10 ; ++ V_1 )
if ( V_32 -> V_9 [ V_34 ] . V_14 [ V_1 ] -> V_17 != - 1 )
V_62 += F_48 ( V_32 -> V_9 [ V_34 ] . V_14 [ V_1 ] ->
V_17 ) ;
return V_62 ;
}
void F_49 ( struct V_19 * V_20 , const struct V_4 * V_32 )
{
int V_1 ;
int V_2 ;
const struct V_4 * V_67 ;
F_3 ( V_20 -> V_37 != NULL ) ;
F_3 ( F_9 ( V_32 ) ) ;
V_67 = V_20 -> V_37 ;
for ( V_1 = 0 ; V_1 < V_8 ; ++ V_1 ) {
F_3 ( V_32 -> V_9 [ V_1 ] . V_10 >= V_67 -> V_9 [ V_1 ] . V_10 ) ;
for ( V_2 = 0 ; V_2 < V_67 -> V_9 [ V_1 ] . V_10 - 1 ; ++ V_2 ) {
const struct V_12 * V_68 = F_30 ( V_67 , V_1 , V_2 ) ;
if ( V_68 -> V_51 == NULL &&
( V_68 -> V_15 & ~ V_63 ) == 0 &&
( V_68 -> V_17 == - 1 ||
V_68 -> V_15 == V_63 ) )
continue;
F_3 ( F_30 ( V_32 , V_1 , V_2 ) == F_30 ( V_67 , V_1 , V_2 ) ) ;
}
F_3 ( F_30 ( V_32 , V_1 , V_2 ) -> V_17 >=
F_30 ( V_67 , V_1 , V_2 ) -> V_17 ) ;
}
V_20 -> V_37 = V_32 ;
}
int F_50 ( const struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 )
{
F_3 ( V_34 == V_23 || V_34 == V_22 ) ;
return V_13 -> V_18 [ V_20 -> V_37 -> V_7 ] [ V_34 ] ;
}
int F_51 ( const struct V_19 * V_20 ,
const struct V_12 * V_13 ,
enum V_26 V_34 )
{
int V_42 ;
F_3 ( V_34 == V_23 || V_34 == V_22 ) ;
F_3 ( F_50 ( V_20 , V_13 , V_34 ) ) ;
V_42 = F_16 ( V_20 , V_13 , V_34 ) ;
return F_28 ( F_10 ( V_20 , V_34 ) ) > V_42 ;
}
void F_52 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
unsigned int V_69 ,
enum V_26 V_34 )
{
const struct V_4 * V_32 ;
struct V_33 * V_54 ;
int V_45 ;
int V_42 ;
V_32 = V_20 -> V_37 ;
F_3 ( V_32 != NULL ) ;
F_3 ( F_9 ( V_32 ) ) ;
F_3 ( F_50 ( V_20 , V_13 , V_34 ) ) ;
F_3 ( F_51 ( V_20 , V_13 , V_34 ) ) ;
V_42 = F_16 ( V_20 , V_13 , V_34 ) ;
V_54 = F_10 ( V_20 , V_34 ) ;
V_45 = F_25 ( V_54 , V_42 ) ;
F_17 ( V_69 <= V_45 , L_23 ,
V_32 -> V_41 , V_13 -> V_43 , V_45 , V_69 ) ;
if ( V_34 == V_22 )
V_20 -> V_30 -> V_70 = F_53 ( V_54 , V_42 , V_69 ,
1 ) ;
else
V_20 -> V_30 -> V_71 = F_53 ( V_54 , V_42 , V_69 ,
1 ) ;
}
int F_54 ( struct V_19 * V_20 ,
const struct V_12 * V_13 ,
unsigned int V_69 )
{
struct V_72 * V_73 = V_20 -> V_30 -> V_74 , * V_75 ;
char * V_76 , * V_77 ;
int V_42 , V_45 , V_39 ;
F_3 ( V_20 -> V_37 != NULL ) ;
F_3 ( F_9 ( V_20 -> V_37 ) ) ;
F_3 ( F_50 ( V_20 , V_13 , V_23 ) ) ;
F_3 ( F_51 ( V_20 , V_13 , V_23 ) ) ;
V_45 = F_31 ( V_20 , V_13 , V_23 ) ;
V_42 = F_16 ( V_20 , V_13 , V_23 ) ;
if ( V_20 -> V_30 -> V_78 >=
F_55 ( V_20 -> V_30 -> V_36 ) - V_45 + V_69 )
F_26 ( L_24 ) ;
V_20 -> V_30 -> V_74 = NULL ;
F_37 ( V_20 , V_13 , V_23 , V_69 ) ;
V_39 = F_13 ( V_20 ) ;
if ( V_39 ) {
V_20 -> V_30 -> V_74 = V_73 ;
return V_39 ;
}
V_75 = V_20 -> V_30 -> V_74 ;
V_77 = V_61 ( V_75 -> V_79 , 0 , 0 ) ;
V_76 = V_61 ( V_73 -> V_79 , 0 , 0 ) ;
V_45 = ( char * ) V_61 ( V_73 -> V_79 , V_42 , 0 ) - V_76 ;
memcpy ( V_77 , V_76 , V_45 ) ;
if ( V_73 -> V_79 -> V_80 > V_42 + 1 ) {
V_77 = V_61 ( V_75 -> V_79 , V_42 + 1 , 0 ) ;
V_76 = V_61 ( V_73 -> V_79 , V_42 + 1 , 0 ) ;
V_42 = V_73 -> V_79 -> V_80 - 1 ;
V_45 = ( char * ) V_61 ( V_73 -> V_79 , V_42 , 0 ) +
F_48 ( V_73 -> V_79 -> V_81 [ V_42 ] ) - V_76 ;
memcpy ( V_77 , V_76 , V_45 ) ;
}
if ( V_73 -> V_82 ) {
int V_1 ;
V_75 -> V_82 = 1 ;
V_75 -> V_83 = V_73 -> V_83 ;
for ( V_1 = 0 ; V_1 < V_73 -> V_84 ; V_1 ++ ) {
V_75 -> V_85 [ V_1 ] = V_73 -> V_85 [ V_1 ] ;
V_75 -> V_86 [ V_1 ] = V_73 -> V_86 [ V_1 ] ;
V_75 -> V_84 ++ ;
}
V_73 -> V_84 = 0 ;
V_73 -> V_82 = 0 ;
V_73 -> V_83 = 0 ;
}
F_56 ( V_73 ) ;
return 0 ;
}
