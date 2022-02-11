static void F_1 ( T_1 * V_1 )
{
unsigned int V_2 = 0 , V_3 = 0 ;
T_2 * V_4 = V_1 -> V_5 . V_6 ;
T_3 * V_7 = & V_1 -> V_7 ;
fprintf ( V_8 , L_1 , V_1 ) ;
while ( V_2 < V_1 -> V_9 ) {
fprintf ( V_8 , L_2 , V_4 -> V_10 [ V_2 ++ % V_11 ] . V_12 ) ;
if ( ! ( V_2 % V_11 ) )
V_4 = V_4 -> V_13 ;
}
fprintf ( V_8 , L_3 ) ;
V_2 = 0 ;
fprintf ( V_8 , L_4 ) ;
while ( V_3 < V_7 -> V_14 ) {
while ( V_2 ++ < V_7 -> V_15 [ V_3 ] )
fprintf ( V_8 , L_5 ) ;
fprintf ( V_8 , L_6 ) ;
V_2 ++ ;
V_3 ++ ;
}
fprintf ( V_8 , L_3 ) ;
}
T_1 * F_2 ( void )
{
T_1 * V_16 ;
if ( ( V_16 = F_3 ( sizeof( * V_16 ) ) ) == NULL ) {
F_4 ( V_17 , V_18 ) ;
return NULL ;
}
F_5 ( & V_16 -> V_5 ) ;
F_6 ( & V_16 -> V_7 ) ;
return V_16 ;
}
T_1 * F_7 ( void )
{
T_1 * V_16 = F_2 () ;
if ( V_16 != NULL )
V_16 -> V_19 = V_20 ;
return V_16 ;
}
void F_8 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
#ifdef F_9
{
T_2 * V_5 = V_1 -> V_5 . V_6 ;
fprintf ( V_8 , L_7 ,
V_1 -> V_7 . V_21 , V_1 -> V_5 . V_21 ) ;
fprintf ( V_8 , L_8 ) ;
while ( V_5 ) {
unsigned V_22 = 0 ;
while ( V_22 < V_11 )
fprintf ( V_8 , L_9 , V_5 -> V_10 [ V_22 ++ ] . V_12 ) ;
V_5 = V_5 -> V_13 ;
}
fprintf ( V_8 , L_3 ) ;
}
#endif
F_10 ( & V_1 -> V_7 ) ;
F_11 ( & V_1 -> V_5 ) ;
F_12 ( V_1 ) ;
}
void F_13 ( T_1 * V_1 )
{
F_14 ( L_10 , V_1 ) ;
if ( V_1 -> V_23 || V_1 -> V_24 )
V_1 -> V_23 ++ ;
else if ( ! F_15 ( & V_1 -> V_7 , V_1 -> V_9 ) ) {
F_4 ( V_25 , V_26 ) ;
V_1 -> V_23 ++ ;
}
F_16 ( V_1 ) ;
}
void F_17 ( T_1 * V_1 )
{
F_14 ( L_11 , V_1 ) ;
if ( V_1 -> V_23 )
V_1 -> V_23 -- ;
else {
unsigned int V_27 = F_18 ( & V_1 -> V_7 ) ;
if ( V_27 < V_1 -> V_9 )
F_19 ( & V_1 -> V_5 , V_1 -> V_9 - V_27 ) ;
V_1 -> V_9 = V_27 ;
V_1 -> V_24 = 0 ;
}
F_16 ( V_1 ) ;
}
T_4 * F_20 ( T_1 * V_1 )
{
T_4 * V_16 ;
F_14 ( L_12 , V_1 ) ;
if ( V_1 -> V_23 || V_1 -> V_24 )
return NULL ;
if ( ( V_16 = F_21 ( & V_1 -> V_5 , V_1 -> V_19 ) ) == NULL ) {
V_1 -> V_24 = 1 ;
F_4 ( V_28 , V_26 ) ;
return NULL ;
}
F_22 ( V_16 ) ;
V_1 -> V_9 ++ ;
F_23 ( V_1 , V_16 ) ;
return V_16 ;
}
static void F_6 ( T_3 * V_29 )
{
V_29 -> V_15 = NULL ;
V_29 -> V_14 = V_29 -> V_21 = 0 ;
}
static void F_10 ( T_3 * V_29 )
{
F_12 ( V_29 -> V_15 ) ;
V_29 -> V_15 = NULL ;
}
static int F_15 ( T_3 * V_29 , unsigned int V_30 )
{
if ( V_29 -> V_14 == V_29 -> V_21 ) {
unsigned int V_31 =
V_29 -> V_21 ? ( V_29 -> V_21 * 3 / 2 ) : V_32 ;
unsigned int * V_33 = F_24 ( sizeof( * V_33 ) * V_31 ) ;
if ( V_33 == NULL )
return 0 ;
if ( V_29 -> V_14 )
memcpy ( V_33 , V_29 -> V_15 , sizeof( * V_33 ) * V_29 -> V_14 ) ;
F_12 ( V_29 -> V_15 ) ;
V_29 -> V_15 = V_33 ;
V_29 -> V_21 = V_31 ;
}
V_29 -> V_15 [ ( V_29 -> V_14 ) ++ ] = V_30 ;
return 1 ;
}
static unsigned int F_18 ( T_3 * V_29 )
{
return V_29 -> V_15 [ -- ( V_29 -> V_14 ) ] ;
}
static void F_5 ( T_5 * V_34 )
{
V_34 -> V_6 = V_34 -> V_35 = V_34 -> V_36 = NULL ;
V_34 -> V_9 = V_34 -> V_21 = 0 ;
}
static void F_11 ( T_5 * V_34 )
{
unsigned int V_22 ;
T_4 * V_37 ;
while ( V_34 -> V_6 ) {
for ( V_22 = 0 , V_37 = V_34 -> V_6 -> V_10 ; V_22 ++ < V_11 ; V_37 ++ )
if ( V_37 -> V_38 )
F_25 ( V_37 ) ;
V_34 -> V_35 = V_34 -> V_6 -> V_13 ;
F_12 ( V_34 -> V_6 ) ;
V_34 -> V_6 = V_34 -> V_35 ;
}
}
static T_4 * F_21 ( T_5 * V_34 , int V_39 )
{
T_4 * V_37 ;
unsigned int V_22 ;
if ( V_34 -> V_9 == V_34 -> V_21 ) {
T_2 * V_4 = F_24 ( sizeof( * V_4 ) ) ;
if ( V_4 == NULL )
return NULL ;
for ( V_22 = 0 , V_37 = V_4 -> V_10 ; V_22 ++ < V_11 ; V_37 ++ ) {
F_26 ( V_37 ) ;
if ( ( V_39 & V_20 ) != 0 )
F_27 ( V_37 , V_20 ) ;
}
V_4 -> V_40 = V_34 -> V_36 ;
V_4 -> V_13 = NULL ;
if ( V_34 -> V_6 == NULL )
V_34 -> V_6 = V_34 -> V_35 = V_34 -> V_36 = V_4 ;
else {
V_34 -> V_36 -> V_13 = V_4 ;
V_34 -> V_36 = V_4 ;
V_34 -> V_35 = V_4 ;
}
V_34 -> V_21 += V_11 ;
V_34 -> V_9 ++ ;
return V_4 -> V_10 ;
}
if ( ! V_34 -> V_9 )
V_34 -> V_35 = V_34 -> V_6 ;
else if ( ( V_34 -> V_9 % V_11 ) == 0 )
V_34 -> V_35 = V_34 -> V_35 -> V_13 ;
return V_34 -> V_35 -> V_10 + ( ( V_34 -> V_9 ++ ) % V_11 ) ;
}
static void F_19 ( T_5 * V_34 , unsigned int V_41 )
{
unsigned int V_42 = ( V_34 -> V_9 - 1 ) % V_11 ;
V_34 -> V_9 -= V_41 ;
while ( V_41 -- ) {
F_28 ( V_34 -> V_35 -> V_10 + V_42 ) ;
if ( V_42 == 0 ) {
V_42 = V_11 - 1 ;
V_34 -> V_35 = V_34 -> V_35 -> V_40 ;
} else
V_42 -- ;
}
}
