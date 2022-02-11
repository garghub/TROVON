static int F_1 ( T_1 V_1 , int V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 = F_2 () ;
int V_9 = - V_10 , V_11 ;
static T_2 V_12 = - 1 ;
V_5 = F_3 () ;
if ( ! V_5 )
return - V_13 ;
if ( F_4 ( V_5 , V_3 , NULL ) )
goto V_14;
V_7 = F_5 ( V_5 ) ;
while ( 1 ) {
V_11 = F_6 ( & V_7 -> V_15 , V_12 , V_2 , - 1 , V_8 ) ;
if ( V_11 < 0 ) {
if ( V_12 == - 1 && V_16 == V_17 ) {
V_12 = 0 ;
continue;
}
goto V_14;
}
break;
}
F_7 ( V_11 ) ;
V_1 ( V_7 ) ;
V_11 = F_6 ( & V_7 -> V_15 , V_12 , V_2 , - 1 , V_8 ) ;
if ( V_11 < 0 ) {
if ( V_16 == V_18 )
V_9 = - V_18 ;
goto V_14;
}
F_7 ( V_11 ) ;
V_9 = 0 ;
V_14:
F_8 ( V_5 ) ;
return V_9 ;
}
static bool F_9 ( T_1 V_1 )
{
const char * V_19 [] = { L_1 , L_2 , L_3 , NULL } ;
struct V_20 * V_21 ;
int V_2 , V_22 , V_23 = 0 ;
V_21 = F_10 ( NULL ) ;
if ( ! V_21 )
return false ;
V_2 = V_21 -> V_24 [ 0 ] ;
F_11 ( V_21 ) ;
do {
V_22 = F_1 ( V_1 , V_2 , V_19 [ V_23 ++ ] ) ;
if ( ! V_22 )
return true ;
} while ( V_22 == - V_10 && V_19 [ V_23 ] );
return false ;
}
static void F_12 ( struct V_6 * V_7 )
{
V_7 -> V_15 . V_25 |= V_26 ;
}
static void F_13 ( struct V_6 * V_7 )
{
V_7 -> V_15 . V_27 = 1 ;
}
static void F_14 ( struct V_6 * V_7 )
{
V_7 -> V_15 . V_28 = 1 ;
}
bool F_15 ( void )
{
return F_9 ( F_12 ) ;
}
static bool F_16 ( void )
{
return F_9 ( F_13 ) ;
}
bool F_17 ( void )
{
return F_9 ( F_14 ) ;
}
bool F_18 ( void )
{
struct V_29 V_15 = {
. type = V_30 ,
. V_31 = V_32 ,
. V_33 = 1 ,
} ;
struct V_20 * V_21 ;
int V_2 , V_11 ;
V_21 = F_10 ( NULL ) ;
if ( ! V_21 )
return false ;
V_2 = V_21 -> V_24 [ 0 ] ;
F_11 ( V_21 ) ;
V_11 = F_6 ( & V_15 , - 1 , V_2 , - 1 , 0 ) ;
if ( V_11 < 0 )
return false ;
F_7 ( V_11 ) ;
return true ;
}
void F_19 ( struct V_4 * V_5 , struct V_34 * V_35 )
{
struct V_6 * V_7 ;
bool V_36 = false ;
bool V_37 ;
if ( V_35 -> V_38 )
F_20 ( V_5 ) ;
if ( V_5 -> V_21 -> V_24 [ 0 ] < 0 )
V_35 -> V_39 = true ;
V_37 = F_16 () ;
F_21 (evlist, evsel) {
F_22 ( V_7 , V_35 ) ;
if ( V_7 -> V_40 && V_37 )
V_7 -> V_15 . V_27 = 1 ;
}
if ( V_35 -> V_41 ) {
V_36 = F_15 () ;
F_21 (evlist, evsel)
F_23 ( V_7 , V_36 ) ;
} else if ( V_5 -> V_42 > 1 ) {
struct V_6 * V_43 = F_5 ( V_5 ) ;
F_21 (evlist, evsel) {
if ( V_7 -> V_15 . V_25 == V_43 -> V_15 . V_25 )
continue;
V_36 = F_15 () ;
break;
}
F_21 (evlist, evsel)
F_23 ( V_7 , V_36 ) ;
}
F_24 ( V_5 ) ;
}
static int F_25 ( unsigned int * V_44 )
{
return F_26 ( L_4 , ( int * ) V_44 ) ;
}
static int F_27 ( struct V_34 * V_35 )
{
bool V_45 = V_35 -> V_45 != V_46 ;
unsigned int V_47 ;
if ( V_35 -> V_48 != V_49 )
V_35 -> V_50 = V_35 -> V_48 ;
if ( V_45 )
V_35 -> V_51 = V_35 -> V_45 ;
if ( V_35 -> V_50 )
V_35 -> V_51 = 0 ;
else if ( V_35 -> V_51 ) {
V_35 -> V_50 = V_35 -> V_51 ;
} else {
F_28 ( L_5 ) ;
return - 1 ;
}
if ( F_25 ( & V_47 ) )
return 0 ;
if ( V_45 && ( V_47 < V_35 -> V_51 ) ) {
F_28 ( L_6
L_7
L_8 ,
V_47 ) ;
return - 1 ;
}
if ( V_47 < V_35 -> V_51 ) {
F_29 ( L_9
L_10
L_11 ,
V_47 ) ;
V_35 -> V_51 = V_47 ;
}
return 0 ;
}
int F_30 ( struct V_34 * V_35 )
{
return F_27 ( V_35 ) ;
}
bool F_31 ( struct V_4 * V_5 , const char * V_3 )
{
struct V_4 * V_52 ;
struct V_6 * V_7 ;
int V_9 , V_11 , V_2 ;
bool V_22 = false ;
T_2 V_12 = - 1 ;
V_52 = F_3 () ;
if ( ! V_52 )
return false ;
V_9 = F_4 ( V_52 , V_3 , NULL ) ;
if ( V_9 )
goto V_14;
V_7 = F_32 ( V_52 ) ;
if ( ! V_5 || F_33 ( V_5 -> V_21 ) ) {
struct V_20 * V_21 = F_10 ( NULL ) ;
V_2 = V_21 ? V_21 -> V_24 [ 0 ] : 0 ;
F_11 ( V_21 ) ;
} else {
V_2 = V_5 -> V_21 -> V_24 [ 0 ] ;
}
while ( 1 ) {
V_11 = F_6 ( & V_7 -> V_15 , V_12 , V_2 , - 1 ,
F_2 () ) ;
if ( V_11 < 0 ) {
if ( V_12 == - 1 && V_16 == V_17 ) {
V_12 = 0 ;
continue;
}
goto V_14;
}
break;
}
F_7 ( V_11 ) ;
V_22 = true ;
V_14:
F_8 ( V_52 ) ;
return V_22 ;
}
