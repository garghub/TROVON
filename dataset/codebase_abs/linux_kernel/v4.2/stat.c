void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
double V_3 ;
V_1 -> V_4 ++ ;
V_3 = V_2 - V_1 -> V_5 ;
V_1 -> V_5 += V_3 / V_1 -> V_4 ;
V_1 -> V_6 += V_3 * ( V_2 - V_1 -> V_5 ) ;
if ( V_2 > V_1 -> V_7 )
V_1 -> V_7 = V_2 ;
if ( V_2 < V_1 -> V_8 )
V_1 -> V_8 = V_2 ;
}
double F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_5 ;
}
double F_3 ( struct V_1 * V_1 )
{
double V_9 , V_10 ;
if ( V_1 -> V_4 < 2 )
return 0.0 ;
V_9 = V_1 -> V_6 / ( V_1 -> V_4 - 1 ) ;
V_10 = V_9 / V_1 -> V_4 ;
return sqrt ( V_10 ) ;
}
double F_4 ( double V_11 , double V_12 )
{
double V_13 = 0.0 ;
if ( V_12 )
V_13 = 100.0 * V_11 / V_12 ;
return V_13 ;
}
bool F_5 ( struct V_14 * V_15 ,
enum V_16 V_17 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
return V_19 -> V_17 == V_17 ;
}
void F_6 ( struct V_14 * V_15 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( ! strcmp ( F_7 ( V_15 ) , V_23 [ V_21 ] ) ) {
V_19 -> V_17 = V_21 ;
break;
}
}
}
struct V_24 * F_8 ( int V_25 , int V_26 )
{
struct V_24 * V_27 = F_9 ( sizeof( * V_27 ) ) ;
if ( V_27 ) {
struct V_28 * V_29 ;
V_29 = F_10 ( V_25 , V_26 , sizeof( struct V_30 ) ) ;
if ( ! V_29 ) {
free ( V_27 ) ;
return NULL ;
}
V_27 -> V_29 = V_29 ;
}
return V_27 ;
}
void F_11 ( struct V_24 * V_27 )
{
if ( V_27 ) {
F_12 ( V_27 -> V_29 ) ;
free ( V_27 ) ;
}
}
static void F_13 ( struct V_24 * V_27 )
{
F_14 ( V_27 -> V_29 ) ;
}
void F_15 ( struct V_14 * V_15 )
{
F_13 ( V_15 -> V_27 ) ;
}
int F_16 ( struct V_14 * V_15 , int V_25 , int V_26 )
{
V_15 -> V_27 = F_8 ( V_25 , V_26 ) ;
return V_15 -> V_27 != NULL ? 0 : - V_31 ;
}
void F_17 ( struct V_14 * V_15 )
{
F_11 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
}
void F_18 ( struct V_14 * V_15 )
{
int V_21 ;
struct V_18 * V_19 = V_15 -> V_20 ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
F_19 ( & V_19 -> V_32 [ V_21 ] ) ;
F_6 ( V_15 ) ;
}
int F_20 ( struct V_14 * V_15 )
{
V_15 -> V_20 = F_9 ( sizeof( struct V_18 ) ) ;
if ( V_15 -> V_20 == NULL )
return - V_31 ;
F_18 ( V_15 ) ;
return 0 ;
}
void F_21 ( struct V_14 * V_15 )
{
F_22 ( & V_15 -> V_20 ) ;
}
int F_23 ( struct V_14 * V_15 ,
int V_25 , int V_26 )
{
struct V_24 * V_27 ;
V_27 = F_8 ( V_25 , V_26 ) ;
if ( V_27 )
V_15 -> V_33 = V_27 ;
return V_27 ? 0 : - V_31 ;
}
void F_24 ( struct V_14 * V_15 )
{
F_11 ( V_15 -> V_33 ) ;
V_15 -> V_33 = NULL ;
}
int F_25 ( struct V_14 * V_15 , bool V_34 )
{
int V_25 = F_26 ( V_15 ) ;
int V_26 = F_27 ( V_15 -> V_35 ) ;
if ( F_20 ( V_15 ) < 0 ||
F_16 ( V_15 , V_25 , V_26 ) < 0 ||
( V_34 && F_23 ( V_15 , V_25 , V_26 ) < 0 ) )
return - V_31 ;
return 0 ;
}
int F_28 ( struct V_36 * V_37 , bool V_34 )
{
struct V_14 * V_15 ;
F_29 (evlist, evsel) {
if ( F_25 ( V_15 , V_34 ) )
goto V_38;
}
return 0 ;
V_38:
F_30 ( V_37 ) ;
return - 1 ;
}
void F_30 ( struct V_36 * V_37 )
{
struct V_14 * V_15 ;
F_29 (evlist, evsel) {
F_21 ( V_15 ) ;
F_17 ( V_15 ) ;
F_24 ( V_15 ) ;
}
}
void F_31 ( struct V_36 * V_37 )
{
struct V_14 * V_15 ;
F_29 (evlist, evsel) {
F_18 ( V_15 ) ;
F_15 ( V_15 ) ;
}
}
