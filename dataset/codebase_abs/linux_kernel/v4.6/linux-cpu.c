void
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 ) {
F_2 ( V_2 -> V_4 ,
F_3 () *
sizeof( V_2 -> V_4 [ 0 ] ) ) ;
}
for ( V_3 = 0 ; V_2 -> V_5 && V_3 < V_2 -> V_6 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_5 [ V_3 ] ;
if ( V_8 -> V_9 ) {
F_2 ( V_8 -> V_9 ,
sizeof( * V_8 -> V_9 ) ) ;
}
if ( V_8 -> V_10 )
F_2 ( V_8 -> V_10 , F_4 () ) ;
}
if ( V_2 -> V_5 ) {
F_2 ( V_2 -> V_5 ,
V_2 -> V_6 * sizeof( V_2 -> V_5 [ 0 ] ) ) ;
}
if ( V_2 -> V_11 )
F_2 ( V_2 -> V_11 , sizeof( * V_2 -> V_11 ) ) ;
if ( V_2 -> V_12 )
F_2 ( V_2 -> V_12 , F_4 () ) ;
F_2 ( V_2 , sizeof( * V_2 ) ) ;
}
struct V_1 *
F_5 ( unsigned int V_13 )
{
struct V_1 * V_2 ;
int V_3 ;
F_6 ( V_2 , sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = V_13 ;
F_6 ( V_2 -> V_12 , F_4 () ) ;
F_6 ( V_2 -> V_11 , sizeof( * V_2 -> V_11 ) ) ;
if ( ! V_2 -> V_12 || ! V_2 -> V_11 )
goto V_14;
F_6 ( V_2 -> V_4 ,
F_3 () * sizeof( V_2 -> V_4 [ 0 ] ) ) ;
if ( ! V_2 -> V_4 )
goto V_14;
memset ( V_2 -> V_4 , - 1 ,
F_3 () * sizeof( V_2 -> V_4 [ 0 ] ) ) ;
F_6 ( V_2 -> V_5 , V_13 * sizeof( V_2 -> V_5 [ 0 ] ) ) ;
if ( ! V_2 -> V_5 )
goto V_14;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_5 [ V_3 ] ;
F_6 ( V_8 -> V_10 , F_4 () ) ;
F_6 ( V_8 -> V_9 , sizeof( * V_8 -> V_9 ) ) ;
if ( ! V_8 -> V_10 || ! V_8 -> V_9 )
goto V_14;
}
F_7 ( & V_15 . V_16 ) ;
V_2 -> V_17 = V_15 . V_18 ;
F_8 ( & V_15 . V_16 ) ;
return V_2 ;
V_14:
F_1 ( V_2 ) ;
return NULL ;
}
int
F_9 ( struct V_1 * V_2 , char * V_19 , int V_20 )
{
char * V_21 = V_19 ;
int V_22 = 0 ;
int V_3 ;
int V_23 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
if ( V_20 > 0 ) {
V_22 = snprintf ( V_21 , V_20 , L_1 , V_3 ) ;
V_20 -= V_22 ;
}
if ( V_20 <= 0 ) {
V_22 = - V_24 ;
goto V_25;
}
V_21 += V_22 ;
F_10 (j, cptab->ctb_parts[i].cpt_cpumask) {
V_22 = snprintf ( V_21 , V_20 , L_2 , V_23 ) ;
V_20 -= V_22 ;
if ( V_20 <= 0 ) {
V_22 = - V_24 ;
goto V_25;
}
V_21 += V_22 ;
}
* V_21 = '\n' ;
V_21 ++ ;
V_20 -- ;
}
V_25:
if ( V_22 < 0 )
return V_22 ;
return V_21 - V_19 ;
}
int
F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
int
F_12 ( struct V_1 * V_2 , int V_26 )
{
F_13 ( V_26 == V_27 || ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ) ;
return V_26 == V_27 ?
F_14 ( V_2 -> V_12 ) :
F_14 ( V_2 -> V_5 [ V_26 ] . V_10 ) ;
}
int
F_15 ( struct V_1 * V_2 , int V_26 )
{
F_13 ( V_26 == V_27 || ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ) ;
return V_26 == V_27 ?
F_16 ( V_2 -> V_12 ,
V_28 ) < V_29 :
F_16 ( V_2 -> V_5 [ V_26 ] . V_10 ,
V_28 ) < V_29 ;
}
T_1 *
F_17 ( struct V_1 * V_2 , int V_26 )
{
F_13 ( V_26 == V_27 || ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ) ;
return V_26 == V_27 ?
V_2 -> V_12 : V_2 -> V_5 [ V_26 ] . V_10 ;
}
T_2 *
F_18 ( struct V_1 * V_2 , int V_26 )
{
F_13 ( V_26 == V_27 || ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ) ;
return V_26 == V_27 ?
V_2 -> V_11 : V_2 -> V_5 [ V_26 ] . V_9 ;
}
int
F_19 ( struct V_1 * V_2 , int V_26 , int V_30 )
{
int V_31 ;
F_13 ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ;
if ( V_30 < 0 || V_30 >= V_29 || ! F_20 ( V_30 ) ) {
F_21 ( V_32 , L_3 , V_30 ) ;
return 0 ;
}
if ( V_2 -> V_4 [ V_30 ] != - 1 ) {
F_21 ( V_32 , L_4 ,
V_30 , V_2 -> V_4 [ V_30 ] ) ;
return 0 ;
}
V_2 -> V_4 [ V_30 ] = V_26 ;
F_13 ( ! F_22 ( V_30 , V_2 -> V_12 ) ) ;
F_13 ( ! F_22 ( V_30 , V_2 -> V_5 [ V_26 ] . V_10 ) ) ;
F_23 ( V_30 , V_2 -> V_12 ) ;
F_23 ( V_30 , V_2 -> V_5 [ V_26 ] . V_10 ) ;
V_31 = F_24 ( V_30 ) ;
if ( ! F_25 ( V_31 , * V_2 -> V_11 ) )
F_26 ( V_31 , * V_2 -> V_11 ) ;
if ( ! F_25 ( V_31 , * V_2 -> V_5 [ V_26 ] . V_9 ) )
F_26 ( V_31 , * V_2 -> V_5 [ V_26 ] . V_9 ) ;
return 1 ;
}
void
F_27 ( struct V_1 * V_2 , int V_26 , int V_30 )
{
int V_31 ;
int V_3 ;
F_13 ( V_26 == V_27 || ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ) ;
if ( V_30 < 0 || V_30 >= V_29 ) {
F_21 ( V_32 , L_5 , V_30 ) ;
return;
}
if ( V_26 == V_27 ) {
V_26 = V_2 -> V_4 [ V_30 ] ;
if ( V_26 < 0 ) {
F_21 ( V_32 , L_6 ,
V_26 , V_2 ) ;
return;
}
} else if ( V_26 != V_2 -> V_4 [ V_30 ] ) {
F_21 ( V_32 ,
L_7 , V_30 , V_26 ) ;
return;
}
F_13 ( F_22 ( V_30 , V_2 -> V_5 [ V_26 ] . V_10 ) ) ;
F_13 ( F_22 ( V_30 , V_2 -> V_12 ) ) ;
F_28 ( V_30 , V_2 -> V_5 [ V_26 ] . V_10 ) ;
F_28 ( V_30 , V_2 -> V_12 ) ;
V_2 -> V_4 [ V_30 ] = - 1 ;
V_31 = F_24 ( V_30 ) ;
F_13 ( F_25 ( V_31 , * V_2 -> V_5 [ V_26 ] . V_9 ) ) ;
F_13 ( F_25 ( V_31 , * V_2 -> V_11 ) ) ;
F_10 (i, cptab->ctb_parts[cpt].cpt_cpumask) {
if ( F_24 ( V_3 ) == V_31 )
break;
}
if ( V_3 >= V_29 )
F_29 ( V_31 , * V_2 -> V_5 [ V_26 ] . V_9 ) ;
F_10 (i, cptab->ctb_cpumask) {
if ( F_24 ( V_3 ) == V_31 )
break;
}
if ( V_3 >= V_29 )
F_29 ( V_31 , * V_2 -> V_11 ) ;
}
int
F_30 ( struct V_1 * V_2 , int V_26 , T_1 * V_33 )
{
int V_3 ;
if ( F_14 ( V_33 ) == 0 ||
F_16 ( V_33 , V_28 ) >= V_29 ) {
F_21 ( V_32 , L_8 ,
V_26 ) ;
return 0 ;
}
F_10 (i, mask) {
if ( ! F_19 ( V_2 , V_26 , V_3 ) )
return 0 ;
}
return 1 ;
}
void
F_31 ( struct V_1 * V_2 , int V_26 , T_1 * V_33 )
{
int V_3 ;
F_10 (i, mask)
F_27 ( V_2 , V_26 , V_3 ) ;
}
int
F_32 ( struct V_1 * V_2 , int V_26 , int V_31 )
{
T_1 * V_33 ;
int V_22 ;
if ( V_31 < 0 || V_31 >= V_34 ) {
F_21 ( V_32 ,
L_9 , V_31 , V_26 ) ;
return 0 ;
}
F_33 ( & V_15 . V_35 ) ;
V_33 = V_15 . V_10 ;
F_34 ( V_33 , F_35 ( V_31 ) ) ;
V_22 = F_30 ( V_2 , V_26 , V_33 ) ;
F_36 ( & V_15 . V_35 ) ;
return V_22 ;
}
void
F_37 ( struct V_1 * V_2 , int V_26 , int V_31 )
{
T_1 * V_33 ;
if ( V_31 < 0 || V_31 >= V_34 ) {
F_21 ( V_32 ,
L_9 , V_31 , V_26 ) ;
return;
}
F_33 ( & V_15 . V_35 ) ;
V_33 = V_15 . V_10 ;
F_34 ( V_33 , F_35 ( V_31 ) ) ;
F_31 ( V_2 , V_26 , V_33 ) ;
F_36 ( & V_15 . V_35 ) ;
}
int
F_38 ( struct V_1 * V_2 , int V_26 , T_2 * V_33 )
{
int V_3 ;
F_39 (i, *mask) {
if ( ! F_32 ( V_2 , V_26 , V_3 ) )
return 0 ;
}
return 1 ;
}
void
F_40 ( struct V_1 * V_2 , int V_26 , T_2 * V_33 )
{
int V_3 ;
F_39 (i, *mask)
F_37 ( V_2 , V_26 , V_3 ) ;
}
void
F_41 ( struct V_1 * V_2 , int V_26 )
{
int V_36 ;
int V_3 ;
if ( V_26 == V_27 ) {
V_36 = V_2 -> V_6 - 1 ;
V_26 = 0 ;
} else {
V_36 = V_26 ;
}
for (; V_26 <= V_36 ; V_26 ++ ) {
F_10 (i, cptab->ctb_parts[cpt].cpt_cpumask)
F_27 ( V_2 , V_26 , V_3 ) ;
}
}
int
F_42 ( struct V_1 * V_2 , int V_26 )
{
T_2 * V_33 ;
int V_37 ;
int V_38 ;
int V_31 ;
if ( V_26 < 0 || V_26 >= V_2 -> V_6 ) {
V_33 = V_2 -> V_11 ;
V_38 = V_2 -> V_39 ++ ;
} else {
V_33 = V_2 -> V_5 [ V_26 ] . V_9 ;
V_38 = V_2 -> V_5 [ V_26 ] . V_40 ++ ;
}
V_37 = F_43 ( * V_33 ) ;
F_13 ( V_37 > 0 ) ;
V_38 %= V_37 ;
F_39 (node, *mask) {
if ( V_38 -- == 0 )
return V_31 ;
}
F_44 () ;
return 0 ;
}
int
F_45 ( struct V_1 * V_2 , int V_41 )
{
int V_30 = F_46 () ;
int V_26 = V_2 -> V_4 [ V_30 ] ;
if ( V_26 < 0 ) {
if ( ! V_41 )
return V_26 ;
V_26 = V_30 % V_2 -> V_6 ;
}
return V_26 ;
}
int
F_47 ( struct V_1 * V_2 , int V_30 )
{
F_13 ( V_30 >= 0 && V_30 < V_29 ) ;
return V_2 -> V_4 [ V_30 ] ;
}
int
F_48 ( struct V_1 * V_2 , int V_26 )
{
T_1 * V_42 ;
T_2 * V_43 ;
int V_22 ;
int V_3 ;
F_13 ( V_26 == V_27 || ( V_26 >= 0 && V_26 < V_2 -> V_6 ) ) ;
if ( V_26 == V_27 ) {
V_42 = V_2 -> V_12 ;
V_43 = V_2 -> V_11 ;
} else {
V_42 = V_2 -> V_5 [ V_26 ] . V_10 ;
V_43 = V_2 -> V_5 [ V_26 ] . V_9 ;
}
if ( F_16 ( V_42 , V_28 ) >= V_29 ) {
F_49 ( L_10 ,
V_26 ) ;
return - V_44 ;
}
F_50 (i) {
if ( F_22 ( V_3 , V_42 ) )
continue;
V_22 = F_51 ( V_45 , V_42 ) ;
F_52 ( * V_43 ) ;
if ( V_22 == 0 )
F_53 () ;
return V_22 ;
}
return 0 ;
}
static int
F_54 ( struct V_1 * V_2 , int V_26 ,
T_1 * V_31 , int V_46 )
{
T_1 * V_47 = NULL ;
T_1 * V_48 = NULL ;
int V_22 = 0 ;
int V_30 ;
F_13 ( V_46 > 0 ) ;
if ( V_46 >= F_14 ( V_31 ) ) {
while ( ! F_55 ( V_31 ) ) {
V_30 = F_56 ( V_31 ) ;
V_22 = F_19 ( V_2 , V_26 , V_30 ) ;
if ( ! V_22 )
return - V_44 ;
F_28 ( V_30 , V_31 ) ;
}
return 0 ;
}
F_6 ( V_47 , F_4 () ) ;
F_6 ( V_48 , F_4 () ) ;
if ( ! V_47 || ! V_48 ) {
V_22 = - V_49 ;
goto V_25;
}
while ( ! F_55 ( V_31 ) ) {
V_30 = F_56 ( V_31 ) ;
F_34 ( V_47 , F_57 ( V_30 ) ) ;
F_58 ( V_47 , V_47 , V_31 ) ;
F_13 ( ! F_55 ( V_47 ) ) ;
while ( ! F_55 ( V_47 ) ) {
int V_3 ;
F_34 ( V_48 , F_59 ( V_30 ) ) ;
F_58 ( V_48 , V_48 , V_31 ) ;
F_13 ( ! F_55 ( V_48 ) ) ;
F_10 (i, core) {
F_28 ( V_3 , V_47 ) ;
F_28 ( V_3 , V_31 ) ;
V_22 = F_19 ( V_2 , V_26 , V_3 ) ;
if ( ! V_22 ) {
V_22 = - V_44 ;
goto V_25;
}
if ( -- V_46 == 0 )
goto V_25;
}
V_30 = F_56 ( V_47 ) ;
}
}
V_25:
if ( V_47 )
F_2 ( V_47 , F_4 () ) ;
if ( V_48 )
F_2 ( V_48 , F_4 () ) ;
return V_22 ;
}
static unsigned int
F_60 ( void )
{
unsigned V_50 = F_61 () ;
unsigned V_51 = F_62 () ;
unsigned V_13 ;
if ( V_51 <= V_52 ) {
V_13 = 1 ;
goto V_25;
}
for ( V_13 = 2 ; V_51 > 2 * V_13 * V_13 ; V_13 <<= 1 )
;
if ( V_13 <= V_50 ) {
while ( V_50 > V_13 )
V_50 >>= 1 ;
} else {
while ( ( V_50 << 1 ) <= V_13 )
V_50 <<= 1 ;
}
V_13 = V_50 ;
V_25:
#if ( V_53 == 32 )
V_13 = F_63 ( 2U , V_13 ) ;
#endif
while ( V_51 % V_13 != 0 )
V_13 -- ;
return V_13 ;
}
static struct V_1 *
F_64 ( int V_13 )
{
struct V_1 * V_2 = NULL ;
T_1 * V_33 = NULL ;
int V_26 = 0 ;
int V_54 ;
int V_22 ;
int V_3 ;
V_22 = F_60 () ;
if ( V_13 <= 0 )
V_13 = V_22 ;
if ( V_13 > F_62 () || V_13 > 4 * V_22 ) {
F_65 ( L_11 ,
V_13 , V_22 ) ;
}
if ( F_62 () % V_13 != 0 ) {
F_49 ( L_12 ,
( int ) F_62 () , V_13 ) ;
goto V_14;
}
V_2 = F_5 ( V_13 ) ;
if ( ! V_2 ) {
F_49 ( L_13 , V_13 ) ;
goto V_14;
}
V_54 = F_62 () / V_13 ;
if ( V_54 == 0 ) {
F_49 ( L_14 ) ;
goto V_14;
}
F_6 ( V_33 , F_4 () ) ;
if ( ! V_33 ) {
F_49 ( L_15 ) ;
goto V_14;
}
F_66 (i) {
F_34 ( V_33 , F_35 ( V_3 ) ) ;
while ( ! F_55 ( V_33 ) ) {
struct V_7 * V_8 ;
int V_55 ;
if ( V_26 >= V_13 )
goto V_14;
V_8 = & V_2 -> V_5 [ V_26 ] ;
V_55 = V_54 - F_14 ( V_8 -> V_10 ) ;
F_13 ( V_55 > 0 ) ;
V_22 = F_54 ( V_2 , V_26 , V_33 , V_55 ) ;
if ( V_22 < 0 )
goto V_14;
F_13 ( V_54 >= F_14 ( V_8 -> V_10 ) ) ;
if ( V_54 == F_14 ( V_8 -> V_10 ) )
V_26 ++ ;
}
}
if ( V_26 != V_13 ||
V_54 != F_14 ( V_2 -> V_5 [ V_13 - 1 ] . V_10 ) ) {
F_49 ( L_16 ,
V_2 -> V_6 , V_54 , V_26 ,
F_14 ( V_2 -> V_5 [ V_13 - 1 ] . V_10 ) ) ;
goto V_14;
}
F_2 ( V_33 , F_4 () ) ;
return V_2 ;
V_14:
F_49 ( L_17 ,
V_13 , F_61 () , F_62 () ) ;
if ( V_33 )
F_2 ( V_33 , F_4 () ) ;
if ( V_2 )
F_1 ( V_2 ) ;
return NULL ;
}
static struct V_1 *
F_67 ( char * V_56 )
{
struct V_1 * V_2 ;
char * V_57 = V_56 ;
int V_31 = 0 ;
int V_58 ;
int V_13 ;
int V_59 ;
for ( V_13 = 0 ; ; V_13 ++ ) {
V_57 = strchr ( V_57 , '[' ) ;
if ( ! V_57 )
break;
V_57 ++ ;
}
V_57 = F_68 ( V_56 ) ;
if ( * V_57 == 'n' || * V_57 == 'N' ) {
V_56 = V_57 + 1 ;
V_31 = 1 ;
}
if ( V_13 == 0 ||
( V_31 && V_13 > F_61 () ) ||
( ! V_31 && V_13 > F_62 () ) ) {
F_49 ( L_18 ,
V_56 , V_13 ) ;
return NULL ;
}
V_58 = V_31 ? V_34 - 1 : V_29 - 1 ;
V_2 = F_5 ( V_13 ) ;
if ( ! V_2 ) {
F_49 ( L_19 ) ;
return NULL ;
}
for ( V_57 = F_68 ( V_56 ) , V_59 = 0 ; ; V_59 ++ ) {
struct V_60 * V_61 ;
struct V_62 * V_63 ;
char * V_64 = strchr ( V_57 , '[' ) ;
int V_26 ;
int V_22 ;
int V_3 ;
int V_55 ;
if ( ! V_64 ) {
if ( * V_57 != 0 ) {
F_49 ( L_20 , V_57 ) ;
goto V_14;
}
if ( V_59 != V_13 ) {
F_49 ( L_21 ,
V_13 , V_59 ) ;
goto V_14;
}
break;
}
if ( sscanf ( V_57 , L_22 , & V_26 , & V_55 ) < 1 ) {
F_49 ( L_23 , V_57 ) ;
goto V_14;
}
if ( V_26 < 0 || V_26 >= V_13 ) {
F_49 ( L_24 ,
V_26 , V_13 ) ;
goto V_14;
}
if ( F_12 ( V_2 , V_26 ) != 0 ) {
F_49 ( L_25 , V_26 ) ;
goto V_14;
}
V_57 = F_68 ( V_57 + V_55 ) ;
if ( V_57 != V_64 ) {
F_49 ( L_20 , V_57 ) ;
goto V_14;
}
V_64 = strchr ( V_57 , ']' ) ;
if ( ! V_64 ) {
F_49 ( L_26 ,
V_26 , V_57 ) ;
goto V_14;
}
if ( F_69 ( V_57 , ( V_64 - V_57 ) + 1 ,
0 , V_58 , & V_63 ) != 0 ) {
F_49 ( L_27 , V_57 ) ;
goto V_14;
}
F_70 (range, &el->el_exprs, re_link) {
for ( V_3 = V_61 -> V_65 ; V_3 <= V_61 -> V_66 ; V_3 ++ ) {
if ( ( V_3 - V_61 -> V_65 ) % V_61 -> V_67 != 0 )
continue;
V_22 = V_31 ? F_32 ( V_2 , V_26 , V_3 ) :
F_19 ( V_2 , V_26 , V_3 ) ;
if ( ! V_22 ) {
F_71 ( V_63 ) ;
goto V_14;
}
}
}
F_71 ( V_63 ) ;
if ( ! F_15 ( V_2 , V_26 ) ) {
F_49 ( L_28 , V_26 ) ;
goto V_14;
}
V_57 = F_68 ( V_64 + 1 ) ;
}
return V_2 ;
V_14:
F_1 ( V_2 ) ;
return NULL ;
}
static int
F_72 ( struct V_68 * V_69 , unsigned long V_70 , void * V_71 )
{
unsigned int V_30 = ( unsigned long ) V_71 ;
bool V_72 ;
switch ( V_70 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
F_7 ( & V_15 . V_16 ) ;
V_15 . V_18 ++ ;
F_8 ( & V_15 . V_16 ) ;
default:
if ( V_70 != V_73 && V_70 != V_74 ) {
F_21 ( V_32 , L_29 ,
V_30 , V_70 ) ;
break;
}
F_33 ( & V_15 . V_35 ) ;
F_34 ( V_15 . V_10 ,
F_59 ( V_30 ) ) ;
V_72 = F_16 ( V_15 . V_10 ,
V_28 ) >= V_29 ;
F_36 ( & V_15 . V_35 ) ;
F_21 ( V_72 ? V_77 : V_32 ,
L_30 ,
V_30 , V_70 ) ;
}
return V_78 ;
}
void
F_73 ( void )
{
if ( V_1 )
F_1 ( V_1 ) ;
#ifdef F_74
F_75 ( & V_79 ) ;
#endif
if ( V_15 . V_10 )
F_2 ( V_15 . V_10 , F_4 () ) ;
}
int
F_76 ( void )
{
F_13 ( ! V_1 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
F_6 ( V_15 . V_10 , F_4 () ) ;
if ( ! V_15 . V_10 ) {
F_49 ( L_31 ) ;
return - 1 ;
}
F_77 ( & V_15 . V_16 ) ;
F_78 ( & V_15 . V_35 ) ;
#ifdef F_74
F_79 ( & V_79 ) ;
#endif
if ( * V_80 != 0 ) {
V_1 = F_67 ( V_80 ) ;
if ( ! V_1 ) {
F_49 ( L_32 ,
V_80 ) ;
goto V_14;
}
} else {
V_1 = F_64 ( V_81 ) ;
if ( ! V_1 ) {
F_49 ( L_33 ,
V_81 ) ;
goto V_14;
}
}
F_7 ( & V_15 . V_16 ) ;
if ( V_1 -> V_17 != V_15 . V_18 ) {
F_8 ( & V_15 . V_16 ) ;
F_49 ( L_34 ) ;
goto V_14;
}
F_8 ( & V_15 . V_16 ) ;
F_80 ( 0 , L_35 ,
F_62 () , F_11 ( V_1 ) ) ;
return 0 ;
V_14:
F_73 () ;
return - 1 ;
}
