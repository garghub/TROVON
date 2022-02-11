static void F_1 ( int V_1 , T_1 * V_2 )
{
F_2 ( V_2 , F_3 ( V_1 ) ) ;
}
static void F_4 ( int V_1 , T_1 * V_2 )
{
F_2 ( V_2 , F_5 ( V_1 ) ) ;
}
static void F_6 ( int V_3 , T_1 * V_2 )
{
F_2 ( V_2 , F_7 ( V_3 ) ) ;
}
void
F_8 ( struct V_4 * V_5 )
{
int V_6 ;
if ( V_5 -> V_7 != NULL ) {
F_9 ( V_5 -> V_7 ,
F_10 () *
sizeof( V_5 -> V_7 [ 0 ] ) ) ;
}
for ( V_6 = 0 ; V_5 -> V_8 != NULL && V_6 < V_5 -> V_9 ; V_6 ++ ) {
struct V_10 * V_11 = & V_5 -> V_8 [ V_6 ] ;
if ( V_11 -> V_12 != NULL ) {
F_9 ( V_11 -> V_12 ,
sizeof( * V_11 -> V_12 ) ) ;
}
if ( V_11 -> V_13 != NULL )
F_9 ( V_11 -> V_13 , F_11 () ) ;
}
if ( V_5 -> V_8 != NULL ) {
F_9 ( V_5 -> V_8 ,
V_5 -> V_9 * sizeof( V_5 -> V_8 [ 0 ] ) ) ;
}
if ( V_5 -> V_14 != NULL )
F_9 ( V_5 -> V_14 , sizeof( * V_5 -> V_14 ) ) ;
if ( V_5 -> V_15 != NULL )
F_9 ( V_5 -> V_15 , F_11 () ) ;
F_9 ( V_5 , sizeof( * V_5 ) ) ;
}
struct V_4 *
F_12 ( unsigned int V_16 )
{
struct V_4 * V_5 ;
int V_6 ;
F_13 ( V_5 , sizeof( * V_5 ) ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_9 = V_16 ;
F_13 ( V_5 -> V_15 , F_11 () ) ;
F_13 ( V_5 -> V_14 , sizeof( * V_5 -> V_14 ) ) ;
if ( V_5 -> V_15 == NULL || V_5 -> V_14 == NULL )
goto V_17;
F_13 ( V_5 -> V_7 ,
F_10 () * sizeof( V_5 -> V_7 [ 0 ] ) ) ;
if ( V_5 -> V_7 == NULL )
goto V_17;
memset ( V_5 -> V_7 , - 1 ,
F_10 () * sizeof( V_5 -> V_7 [ 0 ] ) ) ;
F_13 ( V_5 -> V_8 , V_16 * sizeof( V_5 -> V_8 [ 0 ] ) ) ;
if ( V_5 -> V_8 == NULL )
goto V_17;
for ( V_6 = 0 ; V_6 < V_16 ; V_6 ++ ) {
struct V_10 * V_11 = & V_5 -> V_8 [ V_6 ] ;
F_13 ( V_11 -> V_13 , F_11 () ) ;
F_13 ( V_11 -> V_12 , sizeof( * V_11 -> V_12 ) ) ;
if ( V_11 -> V_13 == NULL || V_11 -> V_12 == NULL )
goto V_17;
}
F_14 ( & V_18 . V_19 ) ;
V_5 -> V_20 = V_18 . V_21 ;
F_15 ( & V_18 . V_19 ) ;
return V_5 ;
V_17:
F_8 ( V_5 ) ;
return NULL ;
}
int
F_16 ( struct V_4 * V_5 , char * V_22 , int V_23 )
{
char * V_24 = V_22 ;
int V_25 = 0 ;
int V_6 ;
int V_26 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_9 ; V_6 ++ ) {
if ( V_23 > 0 ) {
V_25 = snprintf ( V_24 , V_23 , L_1 , V_6 ) ;
V_23 -= V_25 ;
}
if ( V_23 <= 0 ) {
V_25 = - V_27 ;
goto V_28;
}
V_24 += V_25 ;
F_17 (j, cptab->ctb_parts[i].cpt_cpumask) {
V_25 = snprintf ( V_24 , V_23 , L_2 , V_26 ) ;
V_23 -= V_25 ;
if ( V_23 <= 0 ) {
V_25 = - V_27 ;
goto V_28;
}
V_24 += V_25 ;
}
* V_24 = '\n' ;
V_24 ++ ;
V_23 -- ;
}
V_28:
if ( V_25 < 0 )
return V_25 ;
return V_24 - V_22 ;
}
int
F_18 ( struct V_4 * V_5 )
{
return V_5 -> V_9 ;
}
int
F_19 ( struct V_4 * V_5 , int V_29 )
{
F_20 ( V_29 == V_30 || ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ) ;
return V_29 == V_30 ?
F_21 ( V_5 -> V_15 ) :
F_21 ( V_5 -> V_8 [ V_29 ] . V_13 ) ;
}
int
F_22 ( struct V_4 * V_5 , int V_29 )
{
F_20 ( V_29 == V_30 || ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ) ;
return V_29 == V_30 ?
F_23 ( V_5 -> V_15 ,
V_31 ) < V_32 :
F_23 ( V_5 -> V_8 [ V_29 ] . V_13 ,
V_31 ) < V_32 ;
}
T_1 *
F_24 ( struct V_4 * V_5 , int V_29 )
{
F_20 ( V_29 == V_30 || ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ) ;
return V_29 == V_30 ?
V_5 -> V_15 : V_5 -> V_8 [ V_29 ] . V_13 ;
}
T_2 *
F_25 ( struct V_4 * V_5 , int V_29 )
{
F_20 ( V_29 == V_30 || ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ) ;
return V_29 == V_30 ?
V_5 -> V_14 : V_5 -> V_8 [ V_29 ] . V_12 ;
}
int
F_26 ( struct V_4 * V_5 , int V_29 , int V_1 )
{
int V_3 ;
F_20 ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ;
if ( V_1 < 0 || V_1 >= V_32 || ! F_27 ( V_1 ) ) {
F_28 ( V_33 , L_3 , V_1 ) ;
return 0 ;
}
if ( V_5 -> V_7 [ V_1 ] != - 1 ) {
F_28 ( V_33 , L_4 ,
V_1 , V_5 -> V_7 [ V_1 ] ) ;
return 0 ;
}
V_5 -> V_7 [ V_1 ] = V_29 ;
F_20 ( ! F_29 ( V_1 , V_5 -> V_15 ) ) ;
F_20 ( ! F_29 ( V_1 , V_5 -> V_8 [ V_29 ] . V_13 ) ) ;
F_30 ( V_1 , V_5 -> V_15 ) ;
F_30 ( V_1 , V_5 -> V_8 [ V_29 ] . V_13 ) ;
V_3 = F_31 ( V_1 ) ;
if ( ! F_32 ( V_3 , * V_5 -> V_14 ) )
F_33 ( V_3 , * V_5 -> V_14 ) ;
if ( ! F_32 ( V_3 , * V_5 -> V_8 [ V_29 ] . V_12 ) )
F_33 ( V_3 , * V_5 -> V_8 [ V_29 ] . V_12 ) ;
return 1 ;
}
void
F_34 ( struct V_4 * V_5 , int V_29 , int V_1 )
{
int V_3 ;
int V_6 ;
F_20 ( V_29 == V_30 || ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ) ;
if ( V_1 < 0 || V_1 >= V_32 ) {
F_28 ( V_33 , L_5 , V_1 ) ;
return;
}
if ( V_29 == V_30 ) {
V_29 = V_5 -> V_7 [ V_1 ] ;
if ( V_29 < 0 ) {
F_28 ( V_33 , L_6 ,
V_29 , V_5 ) ;
return;
}
} else if ( V_29 != V_5 -> V_7 [ V_1 ] ) {
F_28 ( V_33 ,
L_7 , V_1 , V_29 ) ;
return;
}
F_20 ( F_29 ( V_1 , V_5 -> V_8 [ V_29 ] . V_13 ) ) ;
F_20 ( F_29 ( V_1 , V_5 -> V_15 ) ) ;
F_35 ( V_1 , V_5 -> V_8 [ V_29 ] . V_13 ) ;
F_35 ( V_1 , V_5 -> V_15 ) ;
V_5 -> V_7 [ V_1 ] = - 1 ;
V_3 = F_31 ( V_1 ) ;
F_20 ( F_32 ( V_3 , * V_5 -> V_8 [ V_29 ] . V_12 ) ) ;
F_20 ( F_32 ( V_3 , * V_5 -> V_14 ) ) ;
F_17 (i, cptab->ctb_parts[cpt].cpt_cpumask) {
if ( F_31 ( V_6 ) == V_3 )
break;
}
if ( V_6 >= V_32 )
F_36 ( V_3 , * V_5 -> V_8 [ V_29 ] . V_12 ) ;
F_17 (i, cptab->ctb_cpumask) {
if ( F_31 ( V_6 ) == V_3 )
break;
}
if ( V_6 >= V_32 )
F_36 ( V_3 , * V_5 -> V_14 ) ;
return;
}
int
F_37 ( struct V_4 * V_5 , int V_29 , T_1 * V_2 )
{
int V_6 ;
if ( F_21 ( V_2 ) == 0 ||
F_23 ( V_2 , V_31 ) >= V_32 ) {
F_28 ( V_33 , L_8 ,
V_29 ) ;
return 0 ;
}
F_17 (i, mask) {
if ( ! F_26 ( V_5 , V_29 , V_6 ) )
return 0 ;
}
return 1 ;
}
void
F_38 ( struct V_4 * V_5 , int V_29 , T_1 * V_2 )
{
int V_6 ;
F_17 (i, mask)
F_34 ( V_5 , V_29 , V_6 ) ;
}
int
F_39 ( struct V_4 * V_5 , int V_29 , int V_3 )
{
T_1 * V_2 ;
int V_25 ;
if ( V_3 < 0 || V_3 >= V_34 ) {
F_28 ( V_33 ,
L_9 , V_3 , V_29 ) ;
return 0 ;
}
F_40 ( & V_18 . V_35 ) ;
V_2 = V_18 . V_13 ;
F_6 ( V_3 , V_2 ) ;
V_25 = F_37 ( V_5 , V_29 , V_2 ) ;
F_41 ( & V_18 . V_35 ) ;
return V_25 ;
}
void
F_42 ( struct V_4 * V_5 , int V_29 , int V_3 )
{
T_1 * V_2 ;
if ( V_3 < 0 || V_3 >= V_34 ) {
F_28 ( V_33 ,
L_9 , V_3 , V_29 ) ;
return;
}
F_40 ( & V_18 . V_35 ) ;
V_2 = V_18 . V_13 ;
F_6 ( V_3 , V_2 ) ;
F_38 ( V_5 , V_29 , V_2 ) ;
F_41 ( & V_18 . V_35 ) ;
}
int
F_43 ( struct V_4 * V_5 , int V_29 , T_2 * V_2 )
{
int V_6 ;
F_44 (i, *mask) {
if ( ! F_39 ( V_5 , V_29 , V_6 ) )
return 0 ;
}
return 1 ;
}
void
F_45 ( struct V_4 * V_5 , int V_29 , T_2 * V_2 )
{
int V_6 ;
F_44 (i, *mask)
F_42 ( V_5 , V_29 , V_6 ) ;
}
void
F_46 ( struct V_4 * V_5 , int V_29 )
{
int V_36 ;
int V_6 ;
if ( V_29 == V_30 ) {
V_36 = V_5 -> V_9 - 1 ;
V_29 = 0 ;
} else {
V_36 = V_29 ;
}
for (; V_29 <= V_36 ; V_29 ++ ) {
F_17 (i, cptab->ctb_parts[cpt].cpt_cpumask)
F_34 ( V_5 , V_29 , V_6 ) ;
}
}
int
F_47 ( struct V_4 * V_5 , int V_29 )
{
T_2 * V_2 ;
int V_37 ;
int V_38 ;
int V_3 ;
if ( V_29 < 0 || V_29 >= V_5 -> V_9 ) {
V_2 = V_5 -> V_14 ;
V_38 = V_5 -> V_39 ++ ;
} else {
V_2 = V_5 -> V_8 [ V_29 ] . V_12 ;
V_38 = V_5 -> V_8 [ V_29 ] . V_40 ++ ;
}
V_37 = F_48 ( * V_2 ) ;
F_20 ( V_37 > 0 ) ;
V_38 %= V_37 ;
F_44 (node, *mask) {
if ( V_38 -- == 0 )
return V_3 ;
}
F_49 () ;
return 0 ;
}
int
F_50 ( struct V_4 * V_5 , int V_41 )
{
int V_1 = F_51 () ;
int V_29 = V_5 -> V_7 [ V_1 ] ;
if ( V_29 < 0 ) {
if ( ! V_41 )
return V_29 ;
V_29 = V_1 % V_5 -> V_9 ;
}
return V_29 ;
}
int
F_52 ( struct V_4 * V_5 , int V_1 )
{
F_20 ( V_1 >= 0 && V_1 < V_32 ) ;
return V_5 -> V_7 [ V_1 ] ;
}
int
F_53 ( struct V_4 * V_5 , int V_29 )
{
T_1 * V_42 ;
T_2 * V_43 ;
int V_25 ;
int V_6 ;
F_20 ( V_29 == V_30 || ( V_29 >= 0 && V_29 < V_5 -> V_9 ) ) ;
if ( V_29 == V_30 ) {
V_42 = V_5 -> V_15 ;
V_43 = V_5 -> V_14 ;
} else {
V_42 = V_5 -> V_8 [ V_29 ] . V_13 ;
V_43 = V_5 -> V_8 [ V_29 ] . V_12 ;
}
if ( F_23 ( V_42 , V_31 ) >= V_32 ) {
F_54 ( L_10 ,
V_29 ) ;
return - V_44 ;
}
F_55 (i) {
if ( F_29 ( V_6 , V_42 ) )
continue;
V_25 = F_56 ( V_45 , V_42 ) ;
F_57 ( * V_43 ) ;
if ( V_25 == 0 )
F_58 () ;
return V_25 ;
}
return 0 ;
}
static int
F_59 ( struct V_4 * V_5 , int V_29 ,
T_1 * V_3 , int V_46 )
{
T_1 * V_47 = NULL ;
T_1 * V_48 = NULL ;
int V_25 = 0 ;
int V_1 ;
F_20 ( V_46 > 0 ) ;
if ( V_46 >= F_21 ( V_3 ) ) {
while ( ! F_60 ( V_3 ) ) {
V_1 = F_61 ( V_3 ) ;
V_25 = F_26 ( V_5 , V_29 , V_1 ) ;
if ( ! V_25 )
return - V_44 ;
F_35 ( V_1 , V_3 ) ;
}
return 0 ;
}
F_13 ( V_47 , F_11 () ) ;
F_13 ( V_48 , F_11 () ) ;
if ( V_47 == NULL || V_48 == NULL ) {
V_25 = - V_49 ;
goto V_28;
}
while ( ! F_60 ( V_3 ) ) {
V_1 = F_61 ( V_3 ) ;
F_1 ( V_1 , V_47 ) ;
F_62 ( V_47 , V_47 , V_3 ) ;
F_20 ( ! F_60 ( V_47 ) ) ;
while ( ! F_60 ( V_47 ) ) {
int V_6 ;
F_4 ( V_1 , V_48 ) ;
F_62 ( V_48 , V_48 , V_3 ) ;
F_20 ( ! F_60 ( V_48 ) ) ;
F_17 (i, core) {
F_35 ( V_6 , V_47 ) ;
F_35 ( V_6 , V_3 ) ;
V_25 = F_26 ( V_5 , V_29 , V_6 ) ;
if ( ! V_25 ) {
V_25 = - V_44 ;
goto V_28;
}
if ( -- V_46 == 0 )
goto V_28;
}
V_1 = F_61 ( V_47 ) ;
}
}
V_28:
if ( V_47 != NULL )
F_9 ( V_47 , F_11 () ) ;
if ( V_48 != NULL )
F_9 ( V_48 , F_11 () ) ;
return V_25 ;
}
static unsigned int
F_63 ( void )
{
unsigned V_50 = F_64 () ;
unsigned V_51 = F_65 () ;
unsigned V_16 ;
if ( V_51 <= V_52 ) {
V_16 = 1 ;
goto V_28;
}
for ( V_16 = 2 ; V_51 > 2 * V_16 * V_16 ; V_16 <<= 1 )
;
if ( V_16 <= V_50 ) {
while ( V_50 > V_16 )
V_50 >>= 1 ;
} else {
while ( ( V_50 << 1 ) <= V_16 )
V_50 <<= 1 ;
}
V_16 = V_50 ;
V_28:
#if ( V_53 == 32 )
V_16 = F_66 ( 2U , V_16 ) ;
#endif
while ( V_51 % V_16 != 0 )
V_16 -- ;
return V_16 ;
}
static struct V_4 *
F_67 ( int V_16 )
{
struct V_4 * V_5 = NULL ;
T_1 * V_2 = NULL ;
int V_29 = 0 ;
int V_54 ;
int V_25 ;
int V_6 ;
V_25 = F_63 () ;
if ( V_16 <= 0 )
V_16 = V_25 ;
if ( V_16 > F_65 () || V_16 > 4 * V_25 ) {
F_68 ( L_11 ,
V_16 , V_25 ) ;
}
if ( F_65 () % V_16 != 0 ) {
F_54 ( L_12 ,
( int ) F_65 () , V_16 ) ;
goto V_17;
}
V_5 = F_12 ( V_16 ) ;
if ( V_5 == NULL ) {
F_54 ( L_13 , V_16 ) ;
goto V_17;
}
V_54 = F_65 () / V_16 ;
if ( V_54 == 0 ) {
F_54 ( L_14 ) ;
goto V_17;
}
F_13 ( V_2 , F_11 () ) ;
if ( V_2 == NULL ) {
F_54 ( L_15 ) ;
goto V_17;
}
F_69 (i) {
F_6 ( V_6 , V_2 ) ;
while ( ! F_60 ( V_2 ) ) {
struct V_10 * V_11 ;
int V_55 ;
if ( V_29 >= V_16 )
goto V_17;
V_11 = & V_5 -> V_8 [ V_29 ] ;
V_55 = V_54 - F_21 ( V_11 -> V_13 ) ;
F_20 ( V_55 > 0 ) ;
V_25 = F_59 ( V_5 , V_29 , V_2 , V_55 ) ;
if ( V_25 < 0 )
goto V_17;
F_20 ( V_54 >= F_21 ( V_11 -> V_13 ) ) ;
if ( V_54 == F_21 ( V_11 -> V_13 ) )
V_29 ++ ;
}
}
if ( V_29 != V_16 ||
V_54 != F_21 ( V_5 -> V_8 [ V_16 - 1 ] . V_13 ) ) {
F_54 ( L_16 ,
V_5 -> V_9 , V_54 , V_29 ,
F_21 ( V_5 -> V_8 [ V_16 - 1 ] . V_13 ) ) ;
goto V_17;
}
F_9 ( V_2 , F_11 () ) ;
return V_5 ;
V_17:
F_54 ( L_17 ,
V_16 , F_64 () , F_65 () ) ;
if ( V_2 != NULL )
F_9 ( V_2 , F_11 () ) ;
if ( V_5 != NULL )
F_8 ( V_5 ) ;
return NULL ;
}
static struct V_4 *
F_70 ( char * V_56 )
{
struct V_4 * V_5 ;
char * V_57 = V_56 ;
int V_3 = 0 ;
int V_58 ;
int V_16 ;
int V_59 ;
for ( V_16 = 0 ; ; V_16 ++ ) {
V_57 = strchr ( V_57 , '[' ) ;
if ( V_57 == NULL )
break;
V_57 ++ ;
}
V_57 = F_71 ( V_56 ) ;
if ( * V_57 == 'n' || * V_57 == 'N' ) {
V_56 = V_57 + 1 ;
V_3 = 1 ;
}
if ( V_16 == 0 ||
( V_3 && V_16 > F_64 () ) ||
( ! V_3 && V_16 > F_65 () ) ) {
F_54 ( L_18 ,
V_56 , V_16 ) ;
return NULL ;
}
V_58 = V_3 ? V_34 - 1 : V_32 - 1 ;
V_5 = F_12 ( V_16 ) ;
if ( V_5 == NULL ) {
F_54 ( L_19 ) ;
return NULL ;
}
for ( V_57 = F_71 ( V_56 ) , V_59 = 0 ; ; V_59 ++ ) {
struct V_60 * V_61 ;
struct V_62 * V_63 ;
char * V_64 = strchr ( V_57 , '[' ) ;
int V_29 ;
int V_25 ;
int V_6 ;
int V_55 ;
if ( V_64 == NULL ) {
if ( * V_57 != 0 ) {
F_54 ( L_20 , V_57 ) ;
goto V_17;
} else if ( V_59 != V_16 ) {
F_54 ( L_21 ,
V_16 , V_59 ) ;
goto V_17;
}
break;
}
if ( sscanf ( V_57 , L_22 , & V_29 , & V_55 ) < 1 ) {
F_54 ( L_23 , V_57 ) ;
goto V_17;
}
if ( V_29 < 0 || V_29 >= V_16 ) {
F_54 ( L_24 ,
V_29 , V_16 ) ;
goto V_17;
}
if ( F_19 ( V_5 , V_29 ) != 0 ) {
F_54 ( L_25 , V_29 ) ;
goto V_17;
}
V_57 = F_71 ( V_57 + V_55 ) ;
if ( V_57 != V_64 ) {
F_54 ( L_20 , V_57 ) ;
goto V_17;
}
V_64 = strchr ( V_57 , ']' ) ;
if ( V_64 == NULL ) {
F_54 ( L_26 ,
V_29 , V_57 ) ;
goto V_17;
}
if ( F_72 ( V_57 , ( V_64 - V_57 ) + 1 ,
0 , V_58 , & V_63 ) != 0 ) {
F_54 ( L_27 , V_57 ) ;
goto V_17;
}
F_73 (range, &el->el_exprs, re_link) {
for ( V_6 = V_61 -> V_65 ; V_6 <= V_61 -> V_66 ; V_6 ++ ) {
if ( ( V_6 - V_61 -> V_65 ) % V_61 -> V_67 != 0 )
continue;
V_25 = V_3 ? F_39 ( V_5 , V_29 , V_6 ) :
F_26 ( V_5 , V_29 , V_6 ) ;
if ( ! V_25 ) {
F_74 ( V_63 ) ;
goto V_17;
}
}
}
F_74 ( V_63 ) ;
if ( ! F_22 ( V_5 , V_29 ) ) {
F_54 ( L_28 , V_29 ) ;
goto V_17;
}
V_57 = F_71 ( V_64 + 1 ) ;
}
return V_5 ;
V_17:
F_8 ( V_5 ) ;
return NULL ;
}
static int
F_75 ( struct V_68 * V_69 , unsigned long V_70 , void * V_71 )
{
unsigned int V_1 = ( unsigned long ) V_71 ;
bool V_72 ;
switch ( V_70 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
F_14 ( & V_18 . V_19 ) ;
V_18 . V_21 ++ ;
F_15 ( & V_18 . V_19 ) ;
default:
if ( V_70 != V_73 && V_70 != V_74 ) {
F_28 ( V_33 , L_29 ,
V_1 , V_70 ) ;
break;
}
F_40 ( & V_18 . V_35 ) ;
F_4 ( V_1 , V_18 . V_13 ) ;
V_72 = F_23 ( V_18 . V_13 ,
V_31 ) >= V_32 ;
F_41 ( & V_18 . V_35 ) ;
F_28 ( V_72 ? V_77 : V_33 ,
L_30 ,
V_1 , V_70 ) ;
}
return V_78 ;
}
void
F_76 ( void )
{
if ( V_4 != NULL )
F_8 ( V_4 ) ;
#ifdef F_77
F_78 ( & V_79 ) ;
#endif
if ( V_18 . V_13 != NULL )
F_9 ( V_18 . V_13 , F_11 () ) ;
}
int
F_79 ( void )
{
F_20 ( V_4 == NULL ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_13 ( V_18 . V_13 , F_11 () ) ;
if ( V_18 . V_13 == NULL ) {
F_54 ( L_31 ) ;
return - 1 ;
}
F_80 ( & V_18 . V_19 ) ;
F_81 ( & V_18 . V_35 ) ;
#ifdef F_77
F_82 ( & V_79 ) ;
#endif
if ( * V_80 != 0 ) {
V_4 = F_70 ( V_80 ) ;
if ( V_4 == NULL ) {
F_54 ( L_32 ,
V_80 ) ;
goto V_17;
}
} else {
V_4 = F_67 ( V_81 ) ;
if ( V_4 == NULL ) {
F_54 ( L_33 ,
V_81 ) ;
goto V_17;
}
}
F_14 ( & V_18 . V_19 ) ;
if ( V_4 -> V_20 != V_18 . V_21 ) {
F_15 ( & V_18 . V_19 ) ;
F_54 ( L_34 ) ;
goto V_17;
}
F_15 ( & V_18 . V_19 ) ;
F_83 ( 0 , L_35 ,
F_65 () , F_18 ( V_4 ) ) ;
return 0 ;
V_17:
F_76 () ;
return - 1 ;
}
