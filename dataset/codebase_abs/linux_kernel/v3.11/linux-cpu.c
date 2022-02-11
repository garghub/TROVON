void
F_1 ( int V_1 , T_1 * V_2 )
{
F_2 ( V_2 , F_3 ( V_1 ) ) ;
}
int
F_4 ( int V_1 )
{
int V_3 ;
F_5 ( & V_4 . V_5 ) ;
F_1 ( V_1 , V_4 . V_6 ) ;
V_3 = F_6 ( * V_4 . V_6 ) ;
F_7 ( & V_4 . V_5 ) ;
return V_3 ;
}
void
F_8 ( int V_1 , T_1 * V_2 )
{
F_2 ( V_2 , F_9 ( V_1 ) ) ;
}
int
F_10 ( int V_1 )
{
int V_3 ;
F_5 ( & V_4 . V_5 ) ;
F_8 ( V_1 , V_4 . V_6 ) ;
V_3 = F_6 ( * V_4 . V_6 ) ;
F_7 ( & V_4 . V_5 ) ;
return V_3 ;
}
void
F_11 ( int V_7 , T_1 * V_2 )
{
F_2 ( V_2 , F_12 ( V_7 ) ) ;
}
void
F_13 ( struct V_8 * V_9 )
{
int V_10 ;
if ( V_9 -> V_11 != NULL ) {
F_14 ( V_9 -> V_11 ,
F_15 () *
sizeof( V_9 -> V_11 [ 0 ] ) ) ;
}
for ( V_10 = 0 ; V_9 -> V_12 != NULL && V_10 < V_9 -> V_13 ; V_10 ++ ) {
struct V_14 * V_15 = & V_9 -> V_12 [ V_10 ] ;
if ( V_15 -> V_16 != NULL ) {
F_14 ( V_15 -> V_16 ,
sizeof( * V_15 -> V_16 ) ) ;
}
if ( V_15 -> V_6 != NULL )
F_14 ( V_15 -> V_6 , F_16 () ) ;
}
if ( V_9 -> V_12 != NULL ) {
F_14 ( V_9 -> V_12 ,
V_9 -> V_13 * sizeof( V_9 -> V_12 [ 0 ] ) ) ;
}
if ( V_9 -> V_17 != NULL )
F_14 ( V_9 -> V_17 , sizeof( * V_9 -> V_17 ) ) ;
if ( V_9 -> V_18 != NULL )
F_14 ( V_9 -> V_18 , F_16 () ) ;
F_14 ( V_9 , sizeof( * V_9 ) ) ;
}
struct V_8 *
F_17 ( unsigned int V_19 )
{
struct V_8 * V_9 ;
int V_10 ;
F_18 ( V_9 , sizeof( * V_9 ) ) ;
if ( V_9 == NULL )
return NULL ;
V_9 -> V_13 = V_19 ;
F_18 ( V_9 -> V_18 , F_16 () ) ;
F_18 ( V_9 -> V_17 , sizeof( * V_9 -> V_17 ) ) ;
if ( V_9 -> V_18 == NULL || V_9 -> V_17 == NULL )
goto V_20;
F_18 ( V_9 -> V_11 ,
F_15 () * sizeof( V_9 -> V_11 [ 0 ] ) ) ;
if ( V_9 -> V_11 == NULL )
goto V_20;
memset ( V_9 -> V_11 , - 1 ,
F_15 () * sizeof( V_9 -> V_11 [ 0 ] ) ) ;
F_18 ( V_9 -> V_12 , V_19 * sizeof( V_9 -> V_12 [ 0 ] ) ) ;
if ( V_9 -> V_12 == NULL )
goto V_20;
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ ) {
struct V_14 * V_15 = & V_9 -> V_12 [ V_10 ] ;
F_18 ( V_15 -> V_6 , F_16 () ) ;
F_18 ( V_15 -> V_16 , sizeof( * V_15 -> V_16 ) ) ;
if ( V_15 -> V_6 == NULL || V_15 -> V_16 == NULL )
goto V_20;
}
F_19 ( & V_4 . V_21 ) ;
V_9 -> V_22 = V_4 . V_23 ;
F_20 ( & V_4 . V_21 ) ;
return V_9 ;
V_20:
F_13 ( V_9 ) ;
return NULL ;
}
int
F_21 ( struct V_8 * V_9 , char * V_24 , int V_25 )
{
char * V_26 = V_24 ;
int V_27 = 0 ;
int V_10 ;
int V_28 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_13 ; V_10 ++ ) {
if ( V_25 > 0 ) {
V_27 = snprintf ( V_26 , V_25 , L_1 , V_10 ) ;
V_25 -= V_27 ;
}
if ( V_25 <= 0 ) {
V_27 = - V_29 ;
goto V_30;
}
V_26 += V_27 ;
F_22 (j, *cptab->ctb_parts[i].cpt_cpumask) {
V_27 = snprintf ( V_26 , V_25 , L_2 , V_28 ) ;
V_25 -= V_27 ;
if ( V_25 <= 0 ) {
V_27 = - V_29 ;
goto V_30;
}
V_26 += V_27 ;
}
* V_26 = '\n' ;
V_26 ++ ;
V_25 -- ;
}
V_30:
if ( V_27 < 0 )
return V_27 ;
return V_26 - V_24 ;
}
int
F_23 ( struct V_8 * V_9 )
{
return V_9 -> V_13 ;
}
int
F_24 ( struct V_8 * V_9 , int V_31 )
{
F_25 ( V_31 == V_32 || ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ) ;
return V_31 == V_32 ?
F_6 ( * V_9 -> V_18 ) :
F_6 ( * V_9 -> V_12 [ V_31 ] . V_6 ) ;
}
int
F_26 ( struct V_8 * V_9 , int V_31 )
{
F_25 ( V_31 == V_32 || ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ) ;
return V_31 == V_32 ?
F_27 ( * V_9 -> V_18 ) != V_33 :
F_27 ( * V_9 -> V_12 [ V_31 ] . V_6 ) != V_33 ;
}
T_1 *
F_28 ( struct V_8 * V_9 , int V_31 )
{
F_25 ( V_31 == V_32 || ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ) ;
return V_31 == V_32 ?
V_9 -> V_18 : V_9 -> V_12 [ V_31 ] . V_6 ;
}
T_2 *
F_29 ( struct V_8 * V_9 , int V_31 )
{
F_25 ( V_31 == V_32 || ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ) ;
return V_31 == V_32 ?
V_9 -> V_17 : V_9 -> V_12 [ V_31 ] . V_16 ;
}
int
F_30 ( struct V_8 * V_9 , int V_31 , int V_1 )
{
int V_7 ;
F_25 ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ;
if ( V_1 < 0 || V_1 >= V_33 || ! F_31 ( V_1 ) ) {
F_32 ( V_34 , L_3 , V_1 ) ;
return 0 ;
}
if ( V_9 -> V_11 [ V_1 ] != - 1 ) {
F_32 ( V_34 , L_4 ,
V_1 , V_9 -> V_11 [ V_1 ] ) ;
return 0 ;
}
V_9 -> V_11 [ V_1 ] = V_31 ;
F_25 ( ! F_33 ( V_1 , * V_9 -> V_18 ) ) ;
F_25 ( ! F_33 ( V_1 , * V_9 -> V_12 [ V_31 ] . V_6 ) ) ;
F_34 ( V_1 , * V_9 -> V_18 ) ;
F_34 ( V_1 , * V_9 -> V_12 [ V_31 ] . V_6 ) ;
V_7 = F_35 ( V_1 ) ;
if ( ! F_36 ( V_7 , * V_9 -> V_17 ) )
F_37 ( V_7 , * V_9 -> V_17 ) ;
if ( ! F_36 ( V_7 , * V_9 -> V_12 [ V_31 ] . V_16 ) )
F_37 ( V_7 , * V_9 -> V_12 [ V_31 ] . V_16 ) ;
return 1 ;
}
void
F_38 ( struct V_8 * V_9 , int V_31 , int V_1 )
{
int V_7 ;
int V_10 ;
F_25 ( V_31 == V_32 || ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ) ;
if ( V_1 < 0 || V_1 >= V_33 ) {
F_32 ( V_34 , L_5 , V_1 ) ;
return;
}
if ( V_31 == V_32 ) {
V_31 = V_9 -> V_11 [ V_1 ] ;
if ( V_31 < 0 ) {
F_32 ( V_34 , L_6
L_7 , V_31 , V_9 ) ;
return;
}
} else if ( V_31 != V_9 -> V_11 [ V_1 ] ) {
F_32 ( V_34 ,
L_8 , V_1 , V_31 ) ;
return;
}
F_25 ( F_33 ( V_1 , * V_9 -> V_12 [ V_31 ] . V_6 ) ) ;
F_25 ( F_33 ( V_1 , * V_9 -> V_18 ) ) ;
F_39 ( V_1 , * V_9 -> V_12 [ V_31 ] . V_6 ) ;
F_39 ( V_1 , * V_9 -> V_18 ) ;
V_9 -> V_11 [ V_1 ] = - 1 ;
V_7 = F_35 ( V_1 ) ;
F_25 ( F_36 ( V_7 , * V_9 -> V_12 [ V_31 ] . V_16 ) ) ;
F_25 ( F_36 ( V_7 , * V_9 -> V_17 ) ) ;
F_22 (i, *cptab->ctb_parts[cpt].cpt_cpumask) {
if ( F_35 ( V_10 ) == V_7 )
break;
}
if ( V_10 == V_33 )
F_40 ( V_7 , * V_9 -> V_12 [ V_31 ] . V_16 ) ;
F_22 (i, *cptab->ctb_cpumask) {
if ( F_35 ( V_10 ) == V_7 )
break;
}
if ( V_10 == V_33 )
F_40 ( V_7 , * V_9 -> V_17 ) ;
return;
}
int
F_41 ( struct V_8 * V_9 , int V_31 , T_1 * V_2 )
{
int V_10 ;
if ( F_6 ( * V_2 ) == 0 || F_27 ( * V_2 ) == V_33 ) {
F_32 ( V_34 , L_9
L_10 , V_31 ) ;
return 0 ;
}
F_22 (i, *mask) {
if ( ! F_30 ( V_9 , V_31 , V_10 ) )
return 0 ;
}
return 1 ;
}
void
F_42 ( struct V_8 * V_9 , int V_31 , T_1 * V_2 )
{
int V_10 ;
F_22 (i, *mask)
F_38 ( V_9 , V_31 , V_10 ) ;
}
int
F_43 ( struct V_8 * V_9 , int V_31 , int V_7 )
{
T_1 * V_2 ;
int V_27 ;
if ( V_7 < 0 || V_7 >= V_35 ) {
F_32 ( V_34 ,
L_11 , V_7 , V_31 ) ;
return 0 ;
}
F_5 ( & V_4 . V_5 ) ;
V_2 = V_4 . V_6 ;
F_11 ( V_7 , V_2 ) ;
V_27 = F_41 ( V_9 , V_31 , V_2 ) ;
F_7 ( & V_4 . V_5 ) ;
return V_27 ;
}
void
F_44 ( struct V_8 * V_9 , int V_31 , int V_7 )
{
T_1 * V_2 ;
if ( V_7 < 0 || V_7 >= V_35 ) {
F_32 ( V_34 ,
L_11 , V_7 , V_31 ) ;
return;
}
F_5 ( & V_4 . V_5 ) ;
V_2 = V_4 . V_6 ;
F_11 ( V_7 , V_2 ) ;
F_42 ( V_9 , V_31 , V_2 ) ;
F_7 ( & V_4 . V_5 ) ;
}
int
F_45 ( struct V_8 * V_9 , int V_31 , T_2 * V_2 )
{
int V_10 ;
F_46 (i, *mask) {
if ( ! F_43 ( V_9 , V_31 , V_10 ) )
return 0 ;
}
return 1 ;
}
void
F_47 ( struct V_8 * V_9 , int V_31 , T_2 * V_2 )
{
int V_10 ;
F_46 (i, *mask)
F_44 ( V_9 , V_31 , V_10 ) ;
}
void
F_48 ( struct V_8 * V_9 , int V_31 )
{
int V_36 ;
int V_10 ;
if ( V_31 == V_32 ) {
V_36 = V_9 -> V_13 - 1 ;
V_31 = 0 ;
} else {
V_36 = V_31 ;
}
for (; V_31 <= V_36 ; V_31 ++ ) {
F_22 (i, *cptab->ctb_parts[cpt].cpt_cpumask)
F_38 ( V_9 , V_31 , V_10 ) ;
}
}
int
F_49 ( struct V_8 * V_9 , int V_31 )
{
T_2 * V_2 ;
int V_37 ;
int V_38 ;
int V_7 ;
if ( V_31 < 0 || V_31 >= V_9 -> V_13 ) {
V_2 = V_9 -> V_17 ;
V_38 = V_9 -> V_39 ++ ;
} else {
V_2 = V_9 -> V_12 [ V_31 ] . V_16 ;
V_38 = V_9 -> V_12 [ V_31 ] . V_40 ++ ;
}
V_37 = F_50 ( * V_2 ) ;
F_25 ( V_37 > 0 ) ;
V_38 %= V_37 ;
F_46 (node, *mask) {
if ( V_38 -- == 0 )
return V_7 ;
}
F_51 () ;
return 0 ;
}
int
F_52 ( struct V_8 * V_9 , int V_41 )
{
int V_1 = F_53 () ;
int V_31 = V_9 -> V_11 [ V_1 ] ;
if ( V_31 < 0 ) {
if ( ! V_41 )
return V_31 ;
V_31 = V_1 % V_9 -> V_13 ;
}
return V_31 ;
}
int
F_54 ( struct V_8 * V_9 , int V_1 )
{
F_25 ( V_1 >= 0 && V_1 < V_33 ) ;
return V_9 -> V_11 [ V_1 ] ;
}
int
F_55 ( struct V_8 * V_9 , int V_31 )
{
T_1 * V_42 ;
T_2 * V_43 ;
int V_27 ;
int V_10 ;
F_25 ( V_31 == V_32 || ( V_31 >= 0 && V_31 < V_9 -> V_13 ) ) ;
if ( V_31 == V_32 ) {
V_42 = V_9 -> V_18 ;
V_43 = V_9 -> V_17 ;
} else {
V_42 = V_9 -> V_12 [ V_31 ] . V_6 ;
V_43 = V_9 -> V_12 [ V_31 ] . V_16 ;
}
if ( F_27 ( * V_42 ) == V_33 ) {
F_56 ( L_12
L_13
L_14 , V_31 ) ;
return - V_44 ;
}
F_57 (i) {
if ( F_33 ( V_10 , * V_42 ) )
continue;
V_27 = F_58 ( V_45 , V_42 ) ;
F_59 ( * V_43 ) ;
if ( V_27 == 0 )
F_60 () ;
return V_27 ;
}
return 0 ;
}
static int
F_61 ( struct V_8 * V_9 , int V_31 ,
T_1 * V_7 , int V_46 )
{
T_1 * V_47 = NULL ;
T_1 * V_48 = NULL ;
int V_27 = 0 ;
int V_1 ;
F_25 ( V_46 > 0 ) ;
if ( V_46 >= F_6 ( * V_7 ) ) {
while ( ! F_62 ( * V_7 ) ) {
V_1 = F_63 ( * V_7 ) ;
V_27 = F_30 ( V_9 , V_31 , V_1 ) ;
if ( ! V_27 )
return - V_44 ;
F_39 ( V_1 , * V_7 ) ;
}
return 0 ;
}
F_18 ( V_47 , F_16 () ) ;
F_18 ( V_48 , F_16 () ) ;
if ( V_47 == NULL || V_48 == NULL ) {
V_27 = - V_49 ;
goto V_30;
}
while ( ! F_62 ( * V_7 ) ) {
V_1 = F_63 ( * V_7 ) ;
F_1 ( V_1 , V_47 ) ;
F_64 ( * V_47 , * V_47 , * V_7 ) ;
F_25 ( ! F_62 ( * V_47 ) ) ;
while ( ! F_62 ( * V_47 ) ) {
int V_10 ;
F_8 ( V_1 , V_48 ) ;
F_64 ( * V_48 , * V_48 , * V_7 ) ;
F_25 ( ! F_62 ( * V_48 ) ) ;
F_22 (i, *core) {
F_39 ( V_10 , * V_47 ) ;
F_39 ( V_10 , * V_7 ) ;
V_27 = F_30 ( V_9 , V_31 , V_10 ) ;
if ( ! V_27 ) {
V_27 = - V_44 ;
goto V_30;
}
if ( -- V_46 == 0 )
goto V_30;
}
V_1 = F_63 ( * V_47 ) ;
}
}
V_30:
if ( V_47 != NULL )
F_14 ( V_47 , F_16 () ) ;
if ( V_48 != NULL )
F_14 ( V_48 , F_16 () ) ;
return V_27 ;
}
static unsigned int
F_65 ( void )
{
unsigned V_50 = F_66 () ;
unsigned V_51 = F_67 () ;
unsigned V_19 ;
if ( V_51 <= V_52 ) {
V_19 = 1 ;
goto V_30;
}
for ( V_19 = 2 ; V_51 > 2 * V_19 * V_19 ; V_19 <<= 1 ) {}
if ( V_19 <= V_50 ) {
while ( V_50 > V_19 )
V_50 >>= 1 ;
} else {
while ( ( V_50 << 1 ) <= V_19 )
V_50 <<= 1 ;
}
V_19 = V_50 ;
V_30:
#if ( V_53 == 32 )
V_19 = F_68 ( 2U , V_19 ) ;
#endif
while ( V_51 % V_19 != 0 )
V_19 -- ;
return V_19 ;
}
static struct V_8 *
F_69 ( int V_19 )
{
struct V_8 * V_9 = NULL ;
T_1 * V_2 = NULL ;
int V_31 = 0 ;
int V_3 ;
int V_27 ;
int V_10 ;
V_27 = F_65 () ;
if ( V_19 <= 0 )
V_19 = V_27 ;
if ( V_19 > F_67 () || V_19 > 4 * V_27 ) {
F_70 ( L_15
L_16
L_17 ,
V_19 , V_27 ) ;
}
if ( F_67 () % V_19 != 0 ) {
F_56 ( L_18
L_19
L_20 ,
( int ) F_67 () , V_19 ) ;
goto V_20;
}
V_9 = F_17 ( V_19 ) ;
if ( V_9 == NULL ) {
F_56 ( L_21 , V_19 ) ;
goto V_20;
}
V_3 = F_67 () / V_19 ;
if ( V_3 == 0 ) {
F_56 ( L_22 ) ;
goto V_20;
}
F_18 ( V_2 , F_16 () ) ;
if ( V_2 == NULL ) {
F_56 ( L_23 ) ;
goto V_20;
}
F_71 (i) {
F_11 ( V_10 , V_2 ) ;
while ( ! F_62 ( * V_2 ) ) {
struct V_14 * V_15 ;
int V_54 ;
if ( V_31 >= V_19 )
goto V_20;
V_15 = & V_9 -> V_12 [ V_31 ] ;
V_54 = V_3 - F_6 ( * V_15 -> V_6 ) ;
F_25 ( V_54 > 0 ) ;
V_27 = F_61 ( V_9 , V_31 , V_2 , V_54 ) ;
if ( V_27 < 0 )
goto V_20;
F_25 ( V_3 >= F_6 ( * V_15 -> V_6 ) ) ;
if ( V_3 == F_6 ( * V_15 -> V_6 ) )
V_31 ++ ;
}
}
if ( V_31 != V_19 ||
V_3 != F_6 ( * V_9 -> V_12 [ V_19 - 1 ] . V_6 ) ) {
F_56 ( L_24
L_25 ,
V_9 -> V_13 , V_3 , V_31 ,
F_6 ( * V_9 -> V_12 [ V_19 - 1 ] . V_6 ) ) ;
goto V_20;
}
F_14 ( V_2 , F_16 () ) ;
return V_9 ;
V_20:
F_56 ( L_26
L_27 ,
V_19 , F_66 () , F_67 () ) ;
if ( V_2 != NULL )
F_14 ( V_2 , F_16 () ) ;
if ( V_9 != NULL )
F_13 ( V_9 ) ;
return NULL ;
}
static struct V_8 *
F_72 ( char * V_55 )
{
struct V_8 * V_9 ;
char * V_56 = V_55 ;
int V_7 = 0 ;
int V_57 ;
int V_19 ;
int V_58 ;
for ( V_19 = 0 ; ; V_19 ++ ) {
V_56 = strchr ( V_56 , '[' ) ;
if ( V_56 == NULL )
break;
V_56 ++ ;
}
V_56 = F_73 ( V_55 ) ;
if ( * V_56 == 'n' || * V_56 == 'N' ) {
V_55 = V_56 + 1 ;
V_7 = 1 ;
}
if ( V_19 == 0 ||
( V_7 && V_19 > F_66 () ) ||
( ! V_7 && V_19 > F_67 () ) ) {
F_56 ( L_28 ,
V_55 , V_19 ) ;
return NULL ;
}
V_57 = V_7 ? V_35 - 1 : V_33 - 1 ;
V_9 = F_17 ( V_19 ) ;
if ( V_9 == NULL ) {
F_56 ( L_29 ) ;
return NULL ;
}
for ( V_56 = F_73 ( V_55 ) , V_58 = 0 ; ; V_58 ++ ) {
struct V_59 * V_60 ;
struct V_61 * V_62 ;
char * V_63 = strchr ( V_56 , '[' ) ;
int V_31 ;
int V_27 ;
int V_10 ;
int V_54 ;
if ( V_63 == NULL ) {
if ( * V_56 != 0 ) {
F_56 ( L_30 , V_56 ) ;
goto V_20;
} else if ( V_58 != V_19 ) {
F_56 ( L_31 ,
V_19 , V_58 ) ;
goto V_20;
}
break;
}
if ( sscanf ( V_56 , L_32 , & V_31 , & V_54 ) < 1 ) {
F_56 ( L_33 , V_56 ) ;
goto V_20;
}
if ( V_31 < 0 || V_31 >= V_19 ) {
F_56 ( L_34 ,
V_31 , V_19 ) ;
goto V_20;
}
if ( F_24 ( V_9 , V_31 ) != 0 ) {
F_56 ( L_35 , V_31 ) ;
goto V_20;
}
V_56 = F_73 ( V_56 + V_54 ) ;
if ( V_56 != V_63 ) {
F_56 ( L_30 , V_56 ) ;
goto V_20;
}
V_63 = strchr ( V_56 , ']' ) ;
if ( V_63 == NULL ) {
F_56 ( L_36 ,
V_31 , V_56 ) ;
goto V_20;
}
if ( F_74 ( V_56 , ( V_63 - V_56 ) + 1 ,
0 , V_57 , & V_62 ) != 0 ) {
F_56 ( L_37 , V_56 ) ;
goto V_20;
}
F_75 (range, &el->el_exprs, re_link) {
for ( V_10 = V_60 -> V_64 ; V_10 <= V_60 -> V_65 ; V_10 ++ ) {
if ( ( V_10 - V_60 -> V_64 ) % V_60 -> V_66 != 0 )
continue;
V_27 = V_7 ? F_43 ( V_9 , V_31 , V_10 ) :
F_30 ( V_9 , V_31 , V_10 ) ;
if ( ! V_27 ) {
F_76 ( V_62 ) ;
goto V_20;
}
}
}
F_76 ( V_62 ) ;
if ( ! F_26 ( V_9 , V_31 ) ) {
F_56 ( L_38 , V_31 ) ;
goto V_20;
}
V_56 = F_73 ( V_63 + 1 ) ;
}
return V_9 ;
V_20:
F_13 ( V_9 ) ;
return NULL ;
}
static int
F_77 ( struct V_67 * V_68 , unsigned long V_69 , void * V_70 )
{
unsigned int V_1 = ( unsigned long ) V_70 ;
switch ( V_69 ) {
case V_71 :
case V_72 :
case V_73 :
case V_74 :
F_19 ( & V_4 . V_21 ) ;
V_4 . V_23 ++ ;
F_20 ( & V_4 . V_21 ) ;
default:
F_70 ( L_39
L_40
L_41 , V_1 , V_69 ) ;
}
return V_75 ;
}
void
F_78 ( void )
{
if ( V_8 != NULL )
F_13 ( V_8 ) ;
#ifdef F_79
F_80 ( & V_76 ) ;
#endif
if ( V_4 . V_6 != NULL )
F_14 ( V_4 . V_6 , F_16 () ) ;
}
int
F_81 ( void )
{
F_25 ( V_8 == NULL ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_18 ( V_4 . V_6 , F_16 () ) ;
if ( V_4 . V_6 == NULL ) {
F_56 ( L_42 ) ;
return - 1 ;
}
F_82 ( & V_4 . V_21 ) ;
F_83 ( & V_4 . V_5 , 1 ) ;
#ifdef F_79
F_84 ( & V_76 ) ;
#endif
if ( * V_77 != 0 ) {
V_8 = F_72 ( V_77 ) ;
if ( V_8 == NULL ) {
F_56 ( L_43 ,
V_77 ) ;
goto V_20;
}
} else {
V_8 = F_69 ( V_78 ) ;
if ( V_8 == NULL ) {
F_56 ( L_44 ,
V_78 ) ;
goto V_20;
}
}
F_19 ( & V_4 . V_21 ) ;
if ( V_8 -> V_22 != V_4 . V_23 ) {
F_20 ( & V_4 . V_21 ) ;
F_56 ( L_45 ) ;
goto V_20;
}
F_20 ( & V_4 . V_21 ) ;
F_85 ( 0 , L_46 ,
F_67 () , F_23 ( V_8 ) ) ;
return 0 ;
V_20:
F_78 () ;
return - 1 ;
}
