static void
F_1 ( int V_1 , T_1 * V_2 )
{
const T_1 * V_3 = F_2 ( V_1 ) ;
if ( V_3 )
F_3 ( V_2 , V_3 ) ;
else
F_4 ( V_2 ) ;
}
void
F_5 ( struct V_4 * V_5 )
{
int V_6 ;
if ( V_5 -> V_7 ) {
F_6 ( V_5 -> V_7 ,
F_7 () *
sizeof( V_5 -> V_7 [ 0 ] ) ) ;
}
for ( V_6 = 0 ; V_5 -> V_8 && V_6 < V_5 -> V_9 ; V_6 ++ ) {
struct V_10 * V_11 = & V_5 -> V_8 [ V_6 ] ;
if ( V_11 -> V_12 ) {
F_6 ( V_11 -> V_12 ,
sizeof( * V_11 -> V_12 ) ) ;
}
if ( V_11 -> V_13 )
F_6 ( V_11 -> V_13 , F_8 () ) ;
}
if ( V_5 -> V_8 ) {
F_6 ( V_5 -> V_8 ,
V_5 -> V_9 * sizeof( V_5 -> V_8 [ 0 ] ) ) ;
}
if ( V_5 -> V_14 )
F_6 ( V_5 -> V_14 , sizeof( * V_5 -> V_14 ) ) ;
if ( V_5 -> V_15 )
F_6 ( V_5 -> V_15 , F_8 () ) ;
F_6 ( V_5 , sizeof( * V_5 ) ) ;
}
struct V_4 *
F_9 ( unsigned int V_16 )
{
struct V_4 * V_5 ;
int V_6 ;
F_10 ( V_5 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = V_16 ;
F_10 ( V_5 -> V_15 , F_8 () ) ;
F_10 ( V_5 -> V_14 , sizeof( * V_5 -> V_14 ) ) ;
if ( ! V_5 -> V_15 || ! V_5 -> V_14 )
goto V_17;
F_10 ( V_5 -> V_7 ,
F_7 () * sizeof( V_5 -> V_7 [ 0 ] ) ) ;
if ( ! V_5 -> V_7 )
goto V_17;
memset ( V_5 -> V_7 , - 1 ,
F_7 () * sizeof( V_5 -> V_7 [ 0 ] ) ) ;
F_10 ( V_5 -> V_8 , V_16 * sizeof( V_5 -> V_8 [ 0 ] ) ) ;
if ( ! V_5 -> V_8 )
goto V_17;
for ( V_6 = 0 ; V_6 < V_16 ; V_6 ++ ) {
struct V_10 * V_11 = & V_5 -> V_8 [ V_6 ] ;
F_10 ( V_11 -> V_13 , F_8 () ) ;
F_10 ( V_11 -> V_12 , sizeof( * V_11 -> V_12 ) ) ;
if ( ! V_11 -> V_13 || ! V_11 -> V_12 )
goto V_17;
}
F_11 ( & V_18 . V_19 ) ;
V_5 -> V_20 = V_18 . V_21 ;
F_12 ( & V_18 . V_19 ) ;
return V_5 ;
V_17:
F_5 ( V_5 ) ;
return NULL ;
}
int
F_13 ( struct V_4 * V_5 , char * V_22 , int V_23 )
{
char * V_3 = V_22 ;
int V_24 = 0 ;
int V_6 ;
int V_25 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_9 ; V_6 ++ ) {
if ( V_23 > 0 ) {
V_24 = snprintf ( V_3 , V_23 , L_1 , V_6 ) ;
V_23 -= V_24 ;
}
if ( V_23 <= 0 ) {
V_24 = - V_26 ;
goto V_27;
}
V_3 += V_24 ;
F_14 (j, cptab->ctb_parts[i].cpt_cpumask) {
V_24 = snprintf ( V_3 , V_23 , L_2 , V_25 ) ;
V_23 -= V_24 ;
if ( V_23 <= 0 ) {
V_24 = - V_26 ;
goto V_27;
}
V_3 += V_24 ;
}
* V_3 = '\n' ;
V_3 ++ ;
V_23 -- ;
}
V_27:
if ( V_24 < 0 )
return V_24 ;
return V_3 - V_22 ;
}
int
F_15 ( struct V_4 * V_5 )
{
return V_5 -> V_9 ;
}
int
F_16 ( struct V_4 * V_5 , int V_28 )
{
F_17 ( V_28 == V_29 || ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ) ;
return V_28 == V_29 ?
F_18 ( V_5 -> V_15 ) :
F_18 ( V_5 -> V_8 [ V_28 ] . V_13 ) ;
}
int
F_19 ( struct V_4 * V_5 , int V_28 )
{
F_17 ( V_28 == V_29 || ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ) ;
return V_28 == V_29 ?
F_20 ( V_5 -> V_15 ,
V_30 ) < V_31 :
F_20 ( V_5 -> V_8 [ V_28 ] . V_13 ,
V_30 ) < V_31 ;
}
T_1 *
F_21 ( struct V_4 * V_5 , int V_28 )
{
F_17 ( V_28 == V_29 || ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ) ;
return V_28 == V_29 ?
V_5 -> V_15 : V_5 -> V_8 [ V_28 ] . V_13 ;
}
T_2 *
F_22 ( struct V_4 * V_5 , int V_28 )
{
F_17 ( V_28 == V_29 || ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ) ;
return V_28 == V_29 ?
V_5 -> V_14 : V_5 -> V_8 [ V_28 ] . V_12 ;
}
int
F_23 ( struct V_4 * V_5 , int V_28 , int V_32 )
{
int V_1 ;
F_17 ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ;
if ( V_32 < 0 || V_32 >= V_31 || ! F_24 ( V_32 ) ) {
F_25 ( V_33 , L_3 , V_32 ) ;
return 0 ;
}
if ( V_5 -> V_7 [ V_32 ] != - 1 ) {
F_25 ( V_33 , L_4 ,
V_32 , V_5 -> V_7 [ V_32 ] ) ;
return 0 ;
}
V_5 -> V_7 [ V_32 ] = V_28 ;
F_17 ( ! F_26 ( V_32 , V_5 -> V_15 ) ) ;
F_17 ( ! F_26 ( V_32 , V_5 -> V_8 [ V_28 ] . V_13 ) ) ;
F_27 ( V_32 , V_5 -> V_15 ) ;
F_27 ( V_32 , V_5 -> V_8 [ V_28 ] . V_13 ) ;
V_1 = F_28 ( V_32 ) ;
if ( ! F_29 ( V_1 , * V_5 -> V_14 ) )
F_30 ( V_1 , * V_5 -> V_14 ) ;
if ( ! F_29 ( V_1 , * V_5 -> V_8 [ V_28 ] . V_12 ) )
F_30 ( V_1 , * V_5 -> V_8 [ V_28 ] . V_12 ) ;
return 1 ;
}
void
F_31 ( struct V_4 * V_5 , int V_28 , int V_32 )
{
int V_1 ;
int V_6 ;
F_17 ( V_28 == V_29 || ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ) ;
if ( V_32 < 0 || V_32 >= V_31 ) {
F_25 ( V_33 , L_5 , V_32 ) ;
return;
}
if ( V_28 == V_29 ) {
V_28 = V_5 -> V_7 [ V_32 ] ;
if ( V_28 < 0 ) {
F_25 ( V_33 , L_6 ,
V_28 , V_5 ) ;
return;
}
} else if ( V_28 != V_5 -> V_7 [ V_32 ] ) {
F_25 ( V_33 ,
L_7 , V_32 , V_28 ) ;
return;
}
F_17 ( F_26 ( V_32 , V_5 -> V_8 [ V_28 ] . V_13 ) ) ;
F_17 ( F_26 ( V_32 , V_5 -> V_15 ) ) ;
F_32 ( V_32 , V_5 -> V_8 [ V_28 ] . V_13 ) ;
F_32 ( V_32 , V_5 -> V_15 ) ;
V_5 -> V_7 [ V_32 ] = - 1 ;
V_1 = F_28 ( V_32 ) ;
F_17 ( F_29 ( V_1 , * V_5 -> V_8 [ V_28 ] . V_12 ) ) ;
F_17 ( F_29 ( V_1 , * V_5 -> V_14 ) ) ;
F_14 (i, cptab->ctb_parts[cpt].cpt_cpumask) {
if ( F_28 ( V_6 ) == V_1 )
break;
}
if ( V_6 >= V_31 )
F_33 ( V_1 , * V_5 -> V_8 [ V_28 ] . V_12 ) ;
F_14 (i, cptab->ctb_cpumask) {
if ( F_28 ( V_6 ) == V_1 )
break;
}
if ( V_6 >= V_31 )
F_33 ( V_1 , * V_5 -> V_14 ) ;
}
int
F_34 ( struct V_4 * V_5 , int V_28 , T_1 * V_2 )
{
int V_6 ;
if ( ! F_18 ( V_2 ) ||
F_20 ( V_2 , V_30 ) >= V_31 ) {
F_25 ( V_33 , L_8 ,
V_28 ) ;
return 0 ;
}
F_14 (i, mask) {
if ( ! F_23 ( V_5 , V_28 , V_6 ) )
return 0 ;
}
return 1 ;
}
void
F_35 ( struct V_4 * V_5 , int V_28 , T_1 * V_2 )
{
int V_6 ;
F_14 (i, mask)
F_31 ( V_5 , V_28 , V_6 ) ;
}
int
F_36 ( struct V_4 * V_5 , int V_28 , int V_1 )
{
T_1 * V_2 ;
int V_24 ;
if ( V_1 < 0 || V_1 >= V_34 ) {
F_25 ( V_33 ,
L_9 , V_1 , V_28 ) ;
return 0 ;
}
F_37 ( & V_18 . V_35 ) ;
V_2 = V_18 . V_13 ;
F_1 ( V_1 , V_2 ) ;
V_24 = F_34 ( V_5 , V_28 , V_2 ) ;
F_38 ( & V_18 . V_35 ) ;
return V_24 ;
}
void
F_39 ( struct V_4 * V_5 , int V_28 , int V_1 )
{
T_1 * V_2 ;
if ( V_1 < 0 || V_1 >= V_34 ) {
F_25 ( V_33 ,
L_9 , V_1 , V_28 ) ;
return;
}
F_37 ( & V_18 . V_35 ) ;
V_2 = V_18 . V_13 ;
F_1 ( V_1 , V_2 ) ;
F_35 ( V_5 , V_28 , V_2 ) ;
F_38 ( & V_18 . V_35 ) ;
}
int
F_40 ( struct V_4 * V_5 , int V_28 , T_2 * V_2 )
{
int V_6 ;
F_41 (i, *mask) {
if ( ! F_36 ( V_5 , V_28 , V_6 ) )
return 0 ;
}
return 1 ;
}
void
F_42 ( struct V_4 * V_5 , int V_28 , T_2 * V_2 )
{
int V_6 ;
F_41 (i, *mask)
F_39 ( V_5 , V_28 , V_6 ) ;
}
void
F_43 ( struct V_4 * V_5 , int V_28 )
{
int V_36 ;
int V_6 ;
if ( V_28 == V_29 ) {
V_36 = V_5 -> V_9 - 1 ;
V_28 = 0 ;
} else {
V_36 = V_28 ;
}
for (; V_28 <= V_36 ; V_28 ++ ) {
F_14 (i, cptab->ctb_parts[cpt].cpt_cpumask)
F_31 ( V_5 , V_28 , V_6 ) ;
}
}
int
F_44 ( struct V_4 * V_5 , int V_28 )
{
T_2 * V_2 ;
int V_37 ;
int V_38 ;
int V_1 ;
if ( V_28 < 0 || V_28 >= V_5 -> V_9 ) {
V_2 = V_5 -> V_14 ;
V_38 = V_5 -> V_39 ++ ;
} else {
V_2 = V_5 -> V_8 [ V_28 ] . V_12 ;
V_38 = V_5 -> V_8 [ V_28 ] . V_40 ++ ;
}
V_37 = F_45 ( * V_2 ) ;
F_17 ( V_37 > 0 ) ;
V_38 %= V_37 ;
F_41 (node, *mask) {
if ( ! V_38 -- )
return V_1 ;
}
F_46 () ;
return 0 ;
}
int
F_47 ( struct V_4 * V_5 , int V_41 )
{
int V_32 = F_48 () ;
int V_28 = V_5 -> V_7 [ V_32 ] ;
if ( V_28 < 0 ) {
if ( ! V_41 )
return V_28 ;
V_28 = V_32 % V_5 -> V_9 ;
}
return V_28 ;
}
int
F_49 ( struct V_4 * V_5 , int V_32 )
{
F_17 ( V_32 >= 0 && V_32 < V_31 ) ;
return V_5 -> V_7 [ V_32 ] ;
}
int
F_50 ( struct V_4 * V_5 , int V_28 )
{
T_1 * V_42 ;
T_2 * V_43 ;
int V_24 ;
int V_6 ;
F_17 ( V_28 == V_29 || ( V_28 >= 0 && V_28 < V_5 -> V_9 ) ) ;
if ( V_28 == V_29 ) {
V_42 = V_5 -> V_15 ;
V_43 = V_5 -> V_14 ;
} else {
V_42 = V_5 -> V_8 [ V_28 ] . V_13 ;
V_43 = V_5 -> V_8 [ V_28 ] . V_12 ;
}
if ( F_20 ( V_42 , V_30 ) >= V_31 ) {
F_51 ( L_10 ,
V_28 ) ;
return - V_44 ;
}
F_52 (i) {
if ( F_26 ( V_6 , V_42 ) )
continue;
V_24 = F_53 ( V_45 , V_42 ) ;
F_54 ( * V_43 ) ;
if ( ! V_24 )
F_55 () ;
return V_24 ;
}
return 0 ;
}
static int
F_56 ( struct V_4 * V_5 , int V_28 ,
T_1 * V_1 , int V_46 )
{
T_1 * V_47 = NULL ;
T_1 * V_48 = NULL ;
int V_24 = 0 ;
int V_32 ;
F_17 ( V_46 > 0 ) ;
if ( V_46 >= F_18 ( V_1 ) ) {
while ( ! F_57 ( V_1 ) ) {
V_32 = F_58 ( V_1 ) ;
V_24 = F_23 ( V_5 , V_28 , V_32 ) ;
if ( ! V_24 )
return - V_44 ;
F_32 ( V_32 , V_1 ) ;
}
return 0 ;
}
F_10 ( V_47 , F_8 () ) ;
F_10 ( V_48 , F_8 () ) ;
if ( ! V_47 || ! V_48 ) {
V_24 = - V_49 ;
goto V_27;
}
while ( ! F_57 ( V_1 ) ) {
V_32 = F_58 ( V_1 ) ;
F_3 ( V_47 , F_59 ( V_32 ) ) ;
F_60 ( V_47 , V_47 , V_1 ) ;
F_17 ( ! F_57 ( V_47 ) ) ;
while ( ! F_57 ( V_47 ) ) {
int V_6 ;
F_3 ( V_48 , F_61 ( V_32 ) ) ;
F_60 ( V_48 , V_48 , V_1 ) ;
F_17 ( ! F_57 ( V_48 ) ) ;
F_14 (i, core) {
F_32 ( V_6 , V_47 ) ;
F_32 ( V_6 , V_1 ) ;
V_24 = F_23 ( V_5 , V_28 , V_6 ) ;
if ( ! V_24 ) {
V_24 = - V_44 ;
goto V_27;
}
if ( ! -- V_46 )
goto V_27;
}
V_32 = F_58 ( V_47 ) ;
}
}
V_27:
if ( V_47 )
F_6 ( V_47 , F_8 () ) ;
if ( V_48 )
F_6 ( V_48 , F_8 () ) ;
return V_24 ;
}
static unsigned int
F_62 ( void )
{
unsigned int V_50 = F_63 () ;
unsigned int V_51 = F_64 () ;
unsigned int V_16 ;
if ( V_51 <= V_52 ) {
V_16 = 1 ;
goto V_27;
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
V_27:
#if ( V_53 == 32 )
V_16 = F_65 ( 2U , V_16 ) ;
#endif
while ( V_51 % V_16 )
V_16 -- ;
return V_16 ;
}
static struct V_4 *
F_66 ( int V_16 )
{
struct V_4 * V_5 = NULL ;
T_1 * V_2 = NULL ;
int V_28 = 0 ;
int V_54 ;
int V_24 ;
int V_6 ;
V_24 = F_62 () ;
if ( V_16 <= 0 )
V_16 = V_24 ;
if ( V_16 > F_64 () || V_16 > 4 * V_24 ) {
F_67 ( L_11 ,
V_16 , V_24 ) ;
}
if ( F_64 () % V_16 ) {
F_51 ( L_12 ,
( int ) F_64 () , V_16 ) ;
goto V_17;
}
V_5 = F_9 ( V_16 ) ;
if ( ! V_5 ) {
F_51 ( L_13 , V_16 ) ;
goto V_17;
}
V_54 = F_64 () / V_16 ;
if ( ! V_54 ) {
F_51 ( L_14 ) ;
goto V_17;
}
F_10 ( V_2 , F_8 () ) ;
if ( ! V_2 ) {
F_51 ( L_15 ) ;
goto V_17;
}
F_68 (i) {
F_1 ( V_6 , V_2 ) ;
while ( ! F_57 ( V_2 ) ) {
struct V_10 * V_11 ;
int V_55 ;
if ( V_28 == V_16 )
break;
V_11 = & V_5 -> V_8 [ V_28 ] ;
V_55 = V_54 - F_18 ( V_11 -> V_13 ) ;
F_17 ( V_55 > 0 ) ;
V_24 = F_56 ( V_5 , V_28 , V_2 , V_55 ) ;
if ( V_24 < 0 )
goto V_17;
F_17 ( V_54 >= F_18 ( V_11 -> V_13 ) ) ;
if ( V_54 == F_18 ( V_11 -> V_13 ) )
V_28 ++ ;
}
}
if ( V_28 != V_16 ||
V_54 != F_18 ( V_5 -> V_8 [ V_16 - 1 ] . V_13 ) ) {
F_51 ( L_16 ,
V_5 -> V_9 , V_54 , V_28 ,
F_18 ( V_5 -> V_8 [ V_16 - 1 ] . V_13 ) ) ;
goto V_17;
}
F_6 ( V_2 , F_8 () ) ;
return V_5 ;
V_17:
F_51 ( L_17 ,
V_16 , F_63 () , F_64 () ) ;
if ( V_2 )
F_6 ( V_2 , F_8 () ) ;
if ( V_5 )
F_5 ( V_5 ) ;
return NULL ;
}
static struct V_4 *
F_69 ( char * V_56 )
{
struct V_4 * V_5 ;
char * V_57 ;
int V_1 = 0 ;
int V_58 ;
int V_16 = 0 ;
int V_28 ;
int V_24 ;
int V_59 ;
int V_6 ;
V_57 = F_70 ( V_56 ) ;
if ( * V_57 == 'n' || * V_57 == 'N' ) {
V_56 = V_57 + 1 ;
if ( * V_56 != '\0' ) {
V_1 = 1 ;
} else {
V_1 = - 1 ;
V_16 = F_63 () ;
}
}
if ( ! V_16 ) {
for ( V_57 = V_56 ; ; V_57 ++ , V_16 ++ ) {
V_57 = strchr ( V_57 , '[' ) ;
if ( ! V_57 )
break;
}
}
if ( ! V_16 ||
( V_1 && V_16 > F_63 () ) ||
( ! V_1 && V_16 > F_64 () ) ) {
F_51 ( L_18 ,
V_56 , V_16 ) ;
return NULL ;
}
V_5 = F_9 ( V_16 ) ;
if ( ! V_5 ) {
F_51 ( L_19 ) ;
return NULL ;
}
if ( V_1 < 0 ) {
V_28 = 0 ;
F_68 (i) {
if ( V_28 >= V_16 ) {
F_51 ( L_20 ,
V_28 , V_16 ) ;
goto V_17;
}
V_24 = F_36 ( V_5 , V_28 ++ , V_6 ) ;
if ( ! V_24 )
goto V_17;
}
return V_5 ;
}
V_58 = V_1 ? V_34 - 1 : V_31 - 1 ;
for ( V_57 = F_70 ( V_56 ) , V_59 = 0 ; ; V_59 ++ ) {
struct V_60 * V_61 ;
struct V_62 * V_63 ;
char * V_64 = strchr ( V_57 , '[' ) ;
int V_55 ;
if ( ! V_64 ) {
if ( * V_57 ) {
F_51 ( L_21 , V_57 ) ;
goto V_17;
}
if ( V_59 != V_16 ) {
F_51 ( L_22 ,
V_16 , V_59 ) ;
goto V_17;
}
break;
}
if ( sscanf ( V_57 , L_23 , & V_28 , & V_55 ) < 1 ) {
F_51 ( L_24 , V_57 ) ;
goto V_17;
}
if ( V_28 < 0 || V_28 >= V_16 ) {
F_51 ( L_25 ,
V_28 , V_16 ) ;
goto V_17;
}
if ( F_16 ( V_5 , V_28 ) ) {
F_51 ( L_26 , V_28 ) ;
goto V_17;
}
V_57 = F_70 ( V_57 + V_55 ) ;
if ( V_57 != V_64 ) {
F_51 ( L_21 , V_57 ) ;
goto V_17;
}
V_64 = strchr ( V_57 , ']' ) ;
if ( ! V_64 ) {
F_51 ( L_27 ,
V_28 , V_57 ) ;
goto V_17;
}
if ( F_71 ( V_57 , ( V_64 - V_57 ) + 1 ,
0 , V_58 , & V_63 ) ) {
F_51 ( L_28 , V_57 ) ;
goto V_17;
}
F_72 (range, &el->el_exprs, re_link) {
for ( V_6 = V_61 -> V_65 ; V_6 <= V_61 -> V_66 ; V_6 ++ ) {
if ( ( V_6 - V_61 -> V_65 ) % V_61 -> V_67 )
continue;
V_24 = V_1 ? F_36 ( V_5 , V_28 , V_6 ) :
F_23 ( V_5 , V_28 , V_6 ) ;
if ( ! V_24 ) {
F_73 ( V_63 ) ;
goto V_17;
}
}
}
F_73 ( V_63 ) ;
if ( ! F_19 ( V_5 , V_28 ) ) {
F_51 ( L_29 , V_28 ) ;
goto V_17;
}
V_57 = F_70 ( V_64 + 1 ) ;
}
return V_5 ;
V_17:
F_5 ( V_5 ) ;
return NULL ;
}
static void F_74 ( void )
{
F_11 ( & V_18 . V_19 ) ;
V_18 . V_21 ++ ;
F_12 ( & V_18 . V_19 ) ;
}
static int F_75 ( unsigned int V_32 )
{
F_74 () ;
return 0 ;
}
static int F_76 ( unsigned int V_32 )
{
bool V_68 ;
F_74 () ;
F_37 ( & V_18 . V_35 ) ;
F_3 ( V_18 . V_13 , F_61 ( V_32 ) ) ;
V_68 = F_20 ( V_18 . V_13 ,
V_30 ) >= V_31 ;
F_38 ( & V_18 . V_35 ) ;
F_25 ( V_68 ? V_69 : V_33 ,
L_30 ,
V_32 ) ;
return 0 ;
}
void
F_77 ( void )
{
if ( V_4 )
F_5 ( V_4 ) ;
#ifdef F_78
if ( V_70 > 0 )
F_79 ( V_70 ) ;
F_79 ( V_71 ) ;
#endif
if ( V_18 . V_13 )
F_6 ( V_18 . V_13 , F_8 () ) ;
}
int
F_80 ( void )
{
int V_72 = 0 ;
F_17 ( ! V_4 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_10 ( V_18 . V_13 , F_8 () ) ;
if ( ! V_18 . V_13 ) {
F_51 ( L_31 ) ;
return - 1 ;
}
F_81 ( & V_18 . V_19 ) ;
F_82 ( & V_18 . V_35 ) ;
#ifdef F_78
V_72 = F_83 ( V_71 ,
L_32 , NULL ,
F_76 ) ;
if ( V_72 < 0 )
goto V_17;
V_72 = F_83 ( V_73 ,
L_33 ,
F_75 , NULL ) ;
if ( V_72 < 0 )
goto V_17;
V_70 = V_72 ;
#endif
V_72 = - V_44 ;
if ( * V_74 ) {
V_4 = F_69 ( V_74 ) ;
if ( ! V_4 ) {
F_51 ( L_34 ,
V_74 ) ;
goto V_17;
}
} else {
V_4 = F_66 ( V_75 ) ;
if ( ! V_4 ) {
F_51 ( L_35 ,
V_75 ) ;
goto V_17;
}
}
F_11 ( & V_18 . V_19 ) ;
if ( V_4 -> V_20 != V_18 . V_21 ) {
F_12 ( & V_18 . V_19 ) ;
F_51 ( L_36 ) ;
goto V_17;
}
F_12 ( & V_18 . V_19 ) ;
F_84 ( 0 , L_37 ,
F_64 () , F_15 ( V_4 ) ) ;
return 0 ;
V_17:
F_77 () ;
return V_72 ;
}
