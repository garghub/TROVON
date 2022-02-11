struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_1 ;
int V_3 ;
int V_4 ;
V_3 = ( V_2 + V_5 - 1 ) / V_5 ;
V_3 = V_3 ? : 1 ;
V_1 = F_2 ( sizeof( * V_1 ) + V_3 * sizeof( V_6 * ) , V_7 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_8 = V_2 ;
V_1 -> V_3 = V_3 ;
F_3 ( & V_1 -> V_9 , 1 ) ;
if ( V_2 <= V_10 )
V_1 -> V_11 [ 0 ] = V_1 -> V_12 ;
else {
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
T_1 * V_13 ;
V_13 = ( void * ) F_4 ( V_7 ) ;
if ( ! V_13 )
goto V_14;
V_1 -> V_11 [ V_4 ] = V_13 ;
}
}
return V_1 ;
V_14:
while ( -- V_4 >= 0 ) {
F_5 ( ( unsigned long ) V_1 -> V_11 [ V_4 ] ) ;
}
F_6 ( V_1 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_1 )
{
if ( V_1 -> V_11 [ 0 ] != V_1 -> V_12 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_3 ; V_4 ++ )
F_5 ( ( unsigned long ) V_1 -> V_11 [ V_4 ] ) ;
}
F_6 ( V_1 ) ;
}
static int F_8 ( V_6 T_2 * V_15 ,
const struct V_1 * V_1 )
{
struct V_16 * V_17 = F_9 () ;
int V_4 ;
unsigned int V_18 = V_1 -> V_8 ;
for ( V_4 = 0 ; V_4 < V_18 ; V_4 ++ ) {
V_6 V_19 ;
V_19 = F_10 ( V_17 , F_11 ( V_1 , V_4 ) ) ;
if ( F_12 ( V_19 , V_15 + V_4 ) )
return - V_20 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_1 ,
V_6 T_2 * V_15 )
{
struct V_16 * V_17 = F_9 () ;
int V_4 ;
unsigned int V_18 = V_1 -> V_8 ;
for ( V_4 = 0 ; V_4 < V_18 ; V_4 ++ ) {
V_6 V_19 ;
T_1 V_21 ;
if ( F_14 ( V_19 , V_15 + V_4 ) )
return - V_20 ;
V_21 = F_15 ( V_17 , V_19 ) ;
if ( ! F_16 ( V_21 ) )
return - V_22 ;
F_11 ( V_1 , V_4 ) = V_21 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_1 )
{
int V_23 , V_24 , V_25 ;
int V_2 = V_1 -> V_8 ;
for ( V_25 = 1 ; V_25 < V_2 ; V_25 = 3 * V_25 + 1 )
;
V_25 /= 3 ;
while ( V_25 ) {
V_24 = V_2 - V_25 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
int V_26 = V_23 ;
int V_27 = V_26 + V_25 ;
T_1 V_28 = F_11 ( V_1 , V_27 ) ;
while ( V_26 >= 0 && F_18 ( F_11 ( V_1 , V_26 ) , V_28 ) ) {
F_11 ( V_1 , V_27 ) =
F_11 ( V_1 , V_26 ) ;
V_27 = V_26 ;
V_26 -= V_25 ;
}
F_11 ( V_1 , V_27 ) = V_28 ;
}
V_25 /= 3 ;
}
}
int F_19 ( const struct V_1 * V_1 , T_1 V_29 )
{
unsigned int V_26 , V_27 ;
if ( ! V_1 )
return 0 ;
V_26 = 0 ;
V_27 = V_1 -> V_8 ;
while ( V_26 < V_27 ) {
unsigned int V_30 = ( V_26 + V_27 ) / 2 ;
if ( F_18 ( V_29 , F_11 ( V_1 , V_30 ) ) )
V_26 = V_30 + 1 ;
else if ( F_20 ( V_29 , F_11 ( V_1 , V_30 ) ) )
V_27 = V_30 ;
else
return 1 ;
}
return 0 ;
}
int F_21 ( struct V_31 * V_32 , struct V_1 * V_1 )
{
F_22 ( V_32 -> V_1 ) ;
F_17 ( V_1 ) ;
F_23 ( V_1 ) ;
V_32 -> V_1 = V_1 ;
return 0 ;
}
int F_24 ( struct V_1 * V_1 )
{
struct V_31 * V_32 ;
int V_33 ;
V_32 = F_25 () ;
if ( ! V_32 )
return - V_34 ;
V_33 = F_21 ( V_32 , V_1 ) ;
if ( V_33 < 0 ) {
F_26 ( V_32 ) ;
return V_33 ;
}
return F_27 ( V_32 ) ;
}
int F_28 ( T_1 V_29 )
{
const struct V_31 * V_31 = F_29 () ;
int V_35 = 1 ;
if ( ! F_30 ( V_29 , V_31 -> V_36 ) )
V_35 = F_19 ( V_31 -> V_1 , V_29 ) ;
return V_35 ;
}
int F_31 ( T_1 V_29 )
{
const struct V_31 * V_31 = F_29 () ;
int V_35 = 1 ;
if ( ! F_30 ( V_29 , V_31 -> V_37 ) )
V_35 = F_19 ( V_31 -> V_1 , V_29 ) ;
return V_35 ;
}
