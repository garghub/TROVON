struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
unsigned int V_4 ;
V_4 = sizeof( struct V_1 ) + sizeof( V_5 ) * V_2 ;
V_3 = F_2 ( V_4 , V_6 | V_7 | V_8 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_4 , V_6 , V_9 ) ;
if ( ! V_3 )
return NULL ;
F_4 ( & V_3 -> V_10 , 1 ) ;
V_3 -> V_11 = V_2 ;
return V_3 ;
}
void F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
}
static int F_7 ( T_1 T_2 * V_12 ,
const struct V_1 * V_1 )
{
struct V_13 * V_14 = F_8 () ;
int V_15 ;
unsigned int V_16 = V_1 -> V_11 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
T_1 V_17 ;
V_17 = F_9 ( V_14 , V_1 -> V_17 [ V_15 ] ) ;
if ( F_10 ( V_17 , V_12 + V_15 ) )
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 ,
T_1 T_2 * V_12 )
{
struct V_13 * V_14 = F_8 () ;
int V_15 ;
unsigned int V_16 = V_1 -> V_11 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
T_1 V_17 ;
V_5 V_19 ;
if ( F_12 ( V_17 , V_12 + V_15 ) )
return - V_18 ;
V_19 = F_13 ( V_14 , V_17 ) ;
if ( ! F_14 ( V_19 ) )
return - V_20 ;
V_1 -> V_17 [ V_15 ] = V_19 ;
}
return 0 ;
}
static int F_15 ( const void * V_21 , const void * V_22 )
{
V_5 V_23 = * ( V_5 * ) V_21 ;
V_5 V_24 = * ( V_5 * ) V_22 ;
return F_16 ( V_23 , V_24 ) - F_17 ( V_23 , V_24 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
F_19 ( V_1 -> V_17 , V_1 -> V_11 , sizeof( * V_1 -> V_17 ) ,
F_15 , NULL ) ;
}
int F_20 ( const struct V_1 * V_1 , V_5 V_25 )
{
unsigned int V_26 , V_27 ;
if ( ! V_1 )
return 0 ;
V_26 = 0 ;
V_27 = V_1 -> V_11 ;
while ( V_26 < V_27 ) {
unsigned int V_28 = ( V_26 + V_27 ) / 2 ;
if ( F_16 ( V_25 , V_1 -> V_17 [ V_28 ] ) )
V_26 = V_28 + 1 ;
else if ( F_17 ( V_25 , V_1 -> V_17 [ V_28 ] ) )
V_27 = V_28 ;
else
return 1 ;
}
return 0 ;
}
void F_21 ( struct V_29 * V_30 , struct V_1 * V_1 )
{
F_22 ( V_30 -> V_1 ) ;
F_18 ( V_1 ) ;
F_23 ( V_1 ) ;
V_30 -> V_1 = V_1 ;
}
int F_24 ( struct V_1 * V_1 )
{
struct V_29 * V_30 ;
V_30 = F_25 () ;
if ( ! V_30 )
return - V_31 ;
F_21 ( V_30 , V_1 ) ;
return F_26 ( V_30 ) ;
}
bool F_27 ( void )
{
struct V_13 * V_14 = F_8 () ;
return F_28 ( V_14 , V_32 ) &&
F_29 ( V_14 ) ;
}
int F_30 ( V_5 V_25 )
{
const struct V_29 * V_29 = F_31 () ;
int V_33 = 1 ;
if ( ! F_32 ( V_25 , V_29 -> V_34 ) )
V_33 = F_20 ( V_29 -> V_1 , V_25 ) ;
return V_33 ;
}
int F_33 ( V_5 V_25 )
{
const struct V_29 * V_29 = F_31 () ;
int V_33 = 1 ;
if ( ! F_32 ( V_25 , V_29 -> V_35 ) )
V_33 = F_20 ( V_29 -> V_1 , V_25 ) ;
return V_33 ;
}
