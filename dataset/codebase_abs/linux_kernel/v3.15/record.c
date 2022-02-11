static int F_1 ( T_1 V_1 , int V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 = - V_9 , V_10 ;
V_5 = F_2 () ;
if ( ! V_5 )
return - V_11 ;
if ( F_3 ( V_5 , V_3 ) )
goto V_12;
V_7 = F_4 ( V_5 ) ;
V_10 = F_5 ( & V_7 -> V_13 , - 1 , V_2 , - 1 , 0 ) ;
if ( V_10 < 0 )
goto V_12;
F_6 ( V_10 ) ;
V_1 ( V_7 ) ;
V_10 = F_5 ( & V_7 -> V_13 , - 1 , V_2 , - 1 , 0 ) ;
if ( V_10 < 0 ) {
if ( V_14 == V_15 )
V_8 = - V_15 ;
goto V_12;
}
F_6 ( V_10 ) ;
V_8 = 0 ;
V_12:
F_7 ( V_5 ) ;
return V_8 ;
}
static bool F_8 ( T_1 V_1 )
{
const char * V_16 [] = { L_1 , L_2 , L_3 , NULL } ;
struct V_17 * V_18 ;
int V_2 , V_19 , V_20 = 0 ;
V_18 = F_9 ( NULL ) ;
if ( ! V_18 )
return false ;
V_2 = V_18 -> V_21 [ 0 ] ;
F_10 ( V_18 ) ;
do {
V_19 = F_1 ( V_1 , V_2 , V_16 [ V_20 ++ ] ) ;
if ( ! V_19 )
return true ;
} while ( V_19 == - V_9 && V_16 [ V_20 ] );
return false ;
}
static void F_11 ( struct V_6 * V_7 )
{
V_7 -> V_13 . V_22 |= V_23 ;
}
bool F_12 ( void )
{
return F_8 ( F_11 ) ;
}
void F_13 ( struct V_4 * V_5 , struct V_24 * V_25 )
{
struct V_6 * V_7 ;
bool V_26 = false ;
if ( V_25 -> V_27 )
F_14 ( V_5 ) ;
if ( V_5 -> V_18 -> V_21 [ 0 ] < 0 )
V_25 -> V_28 = true ;
F_15 (evlist, evsel)
F_16 ( V_7 , V_25 ) ;
if ( V_5 -> V_29 > 1 ) {
struct V_6 * V_30 = F_4 ( V_5 ) ;
F_15 (evlist, evsel) {
if ( V_7 -> V_13 . V_22 == V_30 -> V_13 . V_22 )
continue;
V_26 = F_12 () ;
break;
}
F_15 (evlist, evsel)
F_17 ( V_7 , V_26 ) ;
}
F_18 ( V_5 ) ;
}
static int F_19 ( unsigned int * V_31 )
{
char V_32 [ V_33 ] ;
const char * V_34 = F_20 () ;
if ( ! V_34 )
return - 1 ;
snprintf ( V_32 , V_33 ,
L_4 , V_34 ) ;
return F_21 ( V_32 , ( int * ) V_31 ) ;
}
static int F_22 ( struct V_24 * V_25 )
{
bool V_35 = V_25 -> V_35 != V_36 ;
unsigned int V_37 ;
if ( V_25 -> V_38 != V_39 )
V_25 -> V_40 = V_25 -> V_38 ;
if ( V_35 )
V_25 -> V_41 = V_25 -> V_35 ;
if ( V_25 -> V_40 )
V_25 -> V_41 = 0 ;
else if ( V_25 -> V_41 ) {
V_25 -> V_40 = V_25 -> V_41 ;
} else {
F_23 ( L_5 ) ;
return - 1 ;
}
if ( F_19 ( & V_37 ) )
return 0 ;
if ( V_35 && ( V_37 < V_25 -> V_41 ) ) {
F_23 ( L_6
L_7
L_8 ,
V_37 ) ;
return - 1 ;
}
if ( V_37 < V_25 -> V_41 ) {
F_24 ( L_9
L_10
L_11 ,
V_37 ) ;
V_25 -> V_41 = V_37 ;
}
return 0 ;
}
int F_25 ( struct V_24 * V_25 )
{
return F_22 ( V_25 ) ;
}
bool F_26 ( struct V_4 * V_5 , const char * V_3 )
{
struct V_4 * V_42 ;
struct V_6 * V_7 ;
int V_8 , V_10 , V_2 ;
bool V_19 = false ;
V_42 = F_2 () ;
if ( ! V_42 )
return false ;
V_8 = F_3 ( V_42 , V_3 ) ;
if ( V_8 )
goto V_12;
V_7 = F_27 ( V_42 ) ;
if ( ! V_5 || F_28 ( V_5 -> V_18 ) ) {
struct V_17 * V_18 = F_9 ( NULL ) ;
V_2 = V_18 ? V_18 -> V_21 [ 0 ] : 0 ;
F_10 ( V_18 ) ;
} else {
V_2 = V_5 -> V_18 -> V_21 [ 0 ] ;
}
V_10 = F_5 ( & V_7 -> V_13 , - 1 , V_2 , - 1 , 0 ) ;
if ( V_10 >= 0 ) {
F_6 ( V_10 ) ;
V_19 = true ;
}
V_12:
F_7 ( V_42 ) ;
return V_19 ;
}
