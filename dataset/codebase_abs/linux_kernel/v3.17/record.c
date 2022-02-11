static int F_1 ( T_1 V_1 , int V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 = F_2 () ;
int V_9 = - V_10 , V_11 ;
V_5 = F_3 () ;
if ( ! V_5 )
return - V_12 ;
if ( F_4 ( V_5 , V_3 ) )
goto V_13;
V_7 = F_5 ( V_5 ) ;
V_11 = F_6 ( & V_7 -> V_14 , - 1 , V_2 , - 1 , V_8 ) ;
if ( V_11 < 0 )
goto V_13;
F_7 ( V_11 ) ;
V_1 ( V_7 ) ;
V_11 = F_6 ( & V_7 -> V_14 , - 1 , V_2 , - 1 , V_8 ) ;
if ( V_11 < 0 ) {
if ( V_15 == V_16 )
V_9 = - V_16 ;
goto V_13;
}
F_7 ( V_11 ) ;
V_9 = 0 ;
V_13:
F_8 ( V_5 ) ;
return V_9 ;
}
static bool F_9 ( T_1 V_1 )
{
const char * V_17 [] = { L_1 , L_2 , L_3 , NULL } ;
struct V_18 * V_19 ;
int V_2 , V_20 , V_21 = 0 ;
V_19 = F_10 ( NULL ) ;
if ( ! V_19 )
return false ;
V_2 = V_19 -> V_22 [ 0 ] ;
F_11 ( V_19 ) ;
do {
V_20 = F_1 ( V_1 , V_2 , V_17 [ V_21 ++ ] ) ;
if ( ! V_20 )
return true ;
} while ( V_20 == - V_10 && V_17 [ V_21 ] );
return false ;
}
static void F_12 ( struct V_6 * V_7 )
{
V_7 -> V_14 . V_23 |= V_24 ;
}
static void F_13 ( struct V_6 * V_7 )
{
V_7 -> V_14 . V_25 = 1 ;
}
bool F_14 ( void )
{
return F_9 ( F_12 ) ;
}
static bool F_15 ( void )
{
return F_9 ( F_13 ) ;
}
void F_16 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
struct V_6 * V_7 ;
bool V_28 = false ;
bool V_29 ;
if ( V_27 -> V_30 )
F_17 ( V_5 ) ;
if ( V_5 -> V_19 -> V_22 [ 0 ] < 0 )
V_27 -> V_31 = true ;
V_29 = F_15 () ;
F_18 (evlist, evsel) {
F_19 ( V_7 , V_27 ) ;
if ( ! V_7 -> V_32 && V_29 )
V_7 -> V_14 . V_25 = 1 ;
}
if ( V_5 -> V_33 > 1 ) {
struct V_6 * V_34 = F_5 ( V_5 ) ;
F_18 (evlist, evsel) {
if ( V_7 -> V_14 . V_23 == V_34 -> V_14 . V_23 )
continue;
V_28 = F_14 () ;
break;
}
F_18 (evlist, evsel)
F_20 ( V_7 , V_28 ) ;
}
F_21 ( V_5 ) ;
}
static int F_22 ( unsigned int * V_35 )
{
char V_36 [ V_37 ] ;
const char * V_38 = F_23 () ;
if ( ! V_38 )
return - 1 ;
snprintf ( V_36 , V_37 ,
L_4 , V_38 ) ;
return F_24 ( V_36 , ( int * ) V_35 ) ;
}
static int F_25 ( struct V_26 * V_27 )
{
bool V_39 = V_27 -> V_39 != V_40 ;
unsigned int V_41 ;
if ( V_27 -> V_42 != V_43 )
V_27 -> V_44 = V_27 -> V_42 ;
if ( V_39 )
V_27 -> V_45 = V_27 -> V_39 ;
if ( V_27 -> V_44 )
V_27 -> V_45 = 0 ;
else if ( V_27 -> V_45 ) {
V_27 -> V_44 = V_27 -> V_45 ;
} else {
F_26 ( L_5 ) ;
return - 1 ;
}
if ( F_22 ( & V_41 ) )
return 0 ;
if ( V_39 && ( V_41 < V_27 -> V_45 ) ) {
F_26 ( L_6
L_7
L_8 ,
V_41 ) ;
return - 1 ;
}
if ( V_41 < V_27 -> V_45 ) {
F_27 ( L_9
L_10
L_11 ,
V_41 ) ;
V_27 -> V_45 = V_41 ;
}
return 0 ;
}
int F_28 ( struct V_26 * V_27 )
{
return F_25 ( V_27 ) ;
}
bool F_29 ( struct V_4 * V_5 , const char * V_3 )
{
struct V_4 * V_46 ;
struct V_6 * V_7 ;
int V_9 , V_11 , V_2 ;
bool V_20 = false ;
V_46 = F_3 () ;
if ( ! V_46 )
return false ;
V_9 = F_4 ( V_46 , V_3 ) ;
if ( V_9 )
goto V_13;
V_7 = F_30 ( V_46 ) ;
if ( ! V_5 || F_31 ( V_5 -> V_19 ) ) {
struct V_18 * V_19 = F_10 ( NULL ) ;
V_2 = V_19 ? V_19 -> V_22 [ 0 ] : 0 ;
F_11 ( V_19 ) ;
} else {
V_2 = V_5 -> V_19 -> V_22 [ 0 ] ;
}
V_11 = F_6 ( & V_7 -> V_14 , - 1 , V_2 , - 1 ,
F_2 () ) ;
if ( V_11 >= 0 ) {
F_7 ( V_11 ) ;
V_20 = true ;
}
V_13:
F_8 ( V_46 ) ;
return V_20 ;
}
