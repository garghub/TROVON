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
if ( F_4 ( V_5 , V_3 ) )
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
bool F_14 ( void )
{
return F_9 ( F_12 ) ;
}
static bool F_15 ( void )
{
return F_9 ( F_13 ) ;
}
void F_16 ( struct V_4 * V_5 , struct V_28 * V_29 )
{
struct V_6 * V_7 ;
bool V_30 = false ;
bool V_31 ;
if ( V_29 -> V_32 )
F_17 ( V_5 ) ;
if ( V_5 -> V_21 -> V_24 [ 0 ] < 0 )
V_29 -> V_33 = true ;
V_31 = F_15 () ;
F_18 (evlist, evsel) {
F_19 ( V_7 , V_29 ) ;
if ( V_7 -> V_34 && V_31 )
V_7 -> V_15 . V_27 = 1 ;
}
if ( V_5 -> V_35 > 1 ) {
struct V_6 * V_36 = F_5 ( V_5 ) ;
F_18 (evlist, evsel) {
if ( V_7 -> V_15 . V_25 == V_36 -> V_15 . V_25 )
continue;
V_30 = F_14 () ;
break;
}
F_18 (evlist, evsel)
F_20 ( V_7 , V_30 ) ;
}
F_21 ( V_5 ) ;
}
static int F_22 ( unsigned int * V_37 )
{
char V_38 [ V_39 ] ;
const char * V_40 = F_23 () ;
if ( ! V_40 )
return - 1 ;
snprintf ( V_38 , V_39 ,
L_4 , V_40 ) ;
return F_24 ( V_38 , ( int * ) V_37 ) ;
}
static int F_25 ( struct V_28 * V_29 )
{
bool V_41 = V_29 -> V_41 != V_42 ;
unsigned int V_43 ;
if ( V_29 -> V_44 != V_45 )
V_29 -> V_46 = V_29 -> V_44 ;
if ( V_41 )
V_29 -> V_47 = V_29 -> V_41 ;
if ( V_29 -> V_46 )
V_29 -> V_47 = 0 ;
else if ( V_29 -> V_47 ) {
V_29 -> V_46 = V_29 -> V_47 ;
} else {
F_26 ( L_5 ) ;
return - 1 ;
}
if ( F_22 ( & V_43 ) )
return 0 ;
if ( V_41 && ( V_43 < V_29 -> V_47 ) ) {
F_26 ( L_6
L_7
L_8 ,
V_43 ) ;
return - 1 ;
}
if ( V_43 < V_29 -> V_47 ) {
F_27 ( L_9
L_10
L_11 ,
V_43 ) ;
V_29 -> V_47 = V_43 ;
}
return 0 ;
}
int F_28 ( struct V_28 * V_29 )
{
return F_25 ( V_29 ) ;
}
bool F_29 ( struct V_4 * V_5 , const char * V_3 )
{
struct V_4 * V_48 ;
struct V_6 * V_7 ;
int V_9 , V_11 , V_2 ;
bool V_22 = false ;
T_2 V_12 = - 1 ;
V_48 = F_3 () ;
if ( ! V_48 )
return false ;
V_9 = F_4 ( V_48 , V_3 ) ;
if ( V_9 )
goto V_14;
V_7 = F_30 ( V_48 ) ;
if ( ! V_5 || F_31 ( V_5 -> V_21 ) ) {
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
F_8 ( V_48 ) ;
return V_22 ;
}
