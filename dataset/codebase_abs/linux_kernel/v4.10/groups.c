struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
unsigned int V_4 ;
V_4 = sizeof( struct V_1 ) + sizeof( V_5 ) * V_2 ;
V_3 = F_2 ( V_4 , V_6 | V_7 | V_8 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_4 , V_6 | V_9 , V_10 ) ;
if ( ! V_3 )
return NULL ;
F_4 ( & V_3 -> V_11 , 1 ) ;
V_3 -> V_12 = V_2 ;
return V_3 ;
}
void F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
}
static int F_7 ( T_1 T_2 * V_13 ,
const struct V_1 * V_1 )
{
struct V_14 * V_15 = F_8 () ;
int V_16 ;
unsigned int V_17 = V_1 -> V_12 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
T_1 V_18 ;
V_18 = F_9 ( V_15 , V_1 -> V_18 [ V_16 ] ) ;
if ( F_10 ( V_18 , V_13 + V_16 ) )
return - V_19 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 ,
T_1 T_2 * V_13 )
{
struct V_14 * V_15 = F_8 () ;
int V_16 ;
unsigned int V_17 = V_1 -> V_12 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
T_1 V_18 ;
V_5 V_20 ;
if ( F_12 ( V_18 , V_13 + V_16 ) )
return - V_19 ;
V_20 = F_13 ( V_15 , V_18 ) ;
if ( ! F_14 ( V_20 ) )
return - V_21 ;
V_1 -> V_18 [ V_16 ] = V_20 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
int V_22 , V_23 , V_24 ;
int V_2 = V_1 -> V_12 ;
for ( V_24 = 1 ; V_24 < V_2 ; V_24 = 3 * V_24 + 1 )
;
V_24 /= 3 ;
while ( V_24 ) {
V_23 = V_2 - V_24 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
int V_25 = V_22 ;
int V_26 = V_25 + V_24 ;
V_5 V_27 = V_1 -> V_18 [ V_26 ] ;
while ( V_25 >= 0 && F_16 ( V_1 -> V_18 [ V_25 ] , V_27 ) ) {
V_1 -> V_18 [ V_26 ] = V_1 -> V_18 [ V_25 ] ;
V_26 = V_25 ;
V_25 -= V_24 ;
}
V_1 -> V_18 [ V_26 ] = V_27 ;
}
V_24 /= 3 ;
}
}
int F_17 ( const struct V_1 * V_1 , V_5 V_28 )
{
unsigned int V_25 , V_26 ;
if ( ! V_1 )
return 0 ;
V_25 = 0 ;
V_26 = V_1 -> V_12 ;
while ( V_25 < V_26 ) {
unsigned int V_29 = ( V_25 + V_26 ) / 2 ;
if ( F_16 ( V_28 , V_1 -> V_18 [ V_29 ] ) )
V_25 = V_29 + 1 ;
else if ( F_18 ( V_28 , V_1 -> V_18 [ V_29 ] ) )
V_26 = V_29 ;
else
return 1 ;
}
return 0 ;
}
void F_19 ( struct V_30 * V_31 , struct V_1 * V_1 )
{
F_20 ( V_31 -> V_1 ) ;
F_15 ( V_1 ) ;
F_21 ( V_1 ) ;
V_31 -> V_1 = V_1 ;
}
int F_22 ( struct V_1 * V_1 )
{
struct V_30 * V_31 ;
V_31 = F_23 () ;
if ( ! V_31 )
return - V_32 ;
F_19 ( V_31 , V_1 ) ;
return F_24 ( V_31 ) ;
}
bool F_25 ( void )
{
struct V_14 * V_15 = F_8 () ;
return F_26 ( V_15 , V_33 ) &&
F_27 ( V_15 ) ;
}
int F_28 ( V_5 V_28 )
{
const struct V_30 * V_30 = F_29 () ;
int V_34 = 1 ;
if ( ! F_30 ( V_28 , V_30 -> V_35 ) )
V_34 = F_17 ( V_30 -> V_1 , V_28 ) ;
return V_34 ;
}
int F_31 ( V_5 V_28 )
{
const struct V_30 * V_30 = F_29 () ;
int V_34 = 1 ;
if ( ! F_30 ( V_28 , V_30 -> V_36 ) )
V_34 = F_17 ( V_30 -> V_1 , V_28 ) ;
return V_34 ;
}
