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
void F_13 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 ;
bool V_26 = false ;
if ( V_25 -> V_27 )
F_14 ( V_5 ) ;
if ( V_5 -> V_18 -> V_21 [ 0 ] < 0 )
V_25 -> V_28 = true ;
F_15 (evsel, &evlist->entries, node)
F_16 ( V_7 , V_25 ) ;
if ( V_5 -> V_29 > 1 ) {
struct V_6 * V_30 = F_4 ( V_5 ) ;
F_15 (evsel, &evlist->entries, node) {
if ( V_7 -> V_13 . V_22 == V_30 -> V_13 . V_22 )
continue;
V_26 = F_12 () ;
break;
}
F_15 (evsel, &evlist->entries, node)
F_17 ( V_7 , V_26 ) ;
}
F_18 ( V_5 ) ;
}
