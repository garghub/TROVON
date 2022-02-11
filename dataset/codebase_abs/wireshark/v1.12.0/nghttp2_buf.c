void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = NULL ;
V_1 -> V_3 = NULL ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> V_6 = NULL ;
}
int F_2 ( T_1 * V_1 , T_2 V_7 )
{
F_1 ( V_1 ) ;
return F_3 ( V_1 , V_7 ) ;
}
void F_4 ( T_1 * V_1 )
{
free ( V_1 -> V_2 ) ;
}
int F_3 ( T_1 * V_1 , T_2 V_8 )
{
T_3 * V_9 ;
T_2 V_10 ;
V_10 = F_5 ( V_1 ) ;
if( V_10 >= V_8 ) {
return 0 ;
}
V_8 = F_6 ( V_8 , V_10 * 2 ) ;
V_9 = ( T_3 * ) realloc ( V_1 -> V_2 , V_8 ) ;
if( V_9 == NULL ) {
return V_11 ;
}
V_1 -> V_4 = V_9 + ( V_1 -> V_4 - V_1 -> V_2 ) ;
V_1 -> V_5 = V_9 + ( V_1 -> V_5 - V_1 -> V_2 ) ;
V_1 -> V_6 = V_9 + ( V_1 -> V_6 - V_1 -> V_2 ) ;
V_1 -> V_2 = V_9 ;
V_1 -> V_3 = V_9 + V_8 ;
return 0 ;
}
int F_7 ( T_1 * V_1 , T_2 V_12 )
{
return F_3 ( V_1 , F_8 ( V_1 ) + V_12 ) ;
}
int F_9 ( T_1 * V_1 , T_2 V_12 )
{
return F_3 ( V_1 , F_10 ( V_1 ) + V_12 ) ;
}
void F_11 ( T_1 * V_1 )
{
V_1 -> V_4 = V_1 -> V_5 = V_1 -> V_6 = V_1 -> V_2 ;
}
void F_12 ( T_1 * V_1 , T_3 * V_2 , T_2 V_13 )
{
V_1 -> V_2 = V_1 -> V_4 = V_1 -> V_5 = V_1 -> V_6 = V_2 ;
V_1 -> V_3 = V_2 + V_13 ;
}
static int F_13 ( T_4 * * V_14 , T_2 V_15 )
{
int V_16 ;
* V_14 = ( T_4 * ) malloc ( sizeof( T_4 ) ) ;
if( * V_14 == NULL ) {
return V_11 ;
}
( * V_14 ) -> V_17 = NULL ;
V_16 = F_2 ( & ( * V_14 ) -> V_1 , V_15 ) ;
if( V_16 != 0 ) {
free ( * V_14 ) ;
return V_11 ;
}
return 0 ;
}
static void F_14 ( T_4 * V_14 )
{
F_4 ( & V_14 -> V_1 ) ;
free ( V_14 ) ;
}
int F_15 ( T_5 * V_18 , T_2 V_15 ,
T_2 V_19 )
{
return F_16 ( V_18 , V_15 , V_19 , 0 ) ;
}
int F_16 ( T_5 * V_18 , T_2 V_15 ,
T_2 V_19 , T_2 V_20 )
{
return F_17 ( V_18 , V_15 , V_19 , V_19 , V_20 ) ;
}
int F_17 ( T_5 * V_18 , T_2 V_15 ,
T_2 V_19 , T_2 V_21 , T_2 V_20 )
{
int V_16 ;
T_4 * V_14 ;
if( V_21 == 0 || V_19 < V_21 || V_15 < V_20 ) {
return V_22 ;
}
V_16 = F_13 ( & V_14 , V_15 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
V_18 -> V_20 = V_20 ;
V_18 -> V_23 = V_14 ;
V_18 -> V_24 = V_18 -> V_23 ;
F_18 ( & V_18 -> V_24 -> V_1 , V_20 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_25 = 1 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_21 = V_21 ;
return 0 ;
}
void F_19 ( T_5 * V_18 )
{
T_4 * V_14 , * V_26 ;
for( V_14 = V_18 -> V_23 ; V_14 ; ) {
V_26 = V_14 -> V_17 ;
F_14 ( V_14 ) ;
V_14 = V_26 ;
}
}
int F_20 ( T_5 * V_18 , T_3 * V_2 , T_2 V_13 )
{
T_4 * V_14 ;
V_14 = ( T_4 * ) malloc ( sizeof( T_4 ) ) ;
if( V_14 == NULL ) {
return V_11 ;
}
V_14 -> V_17 = NULL ;
F_12 ( & V_14 -> V_1 , V_2 , V_13 ) ;
V_18 -> V_20 = 0 ;
V_18 -> V_23 = V_14 ;
V_18 -> V_24 = V_18 -> V_23 ;
V_18 -> V_15 = V_13 ;
V_18 -> V_25 = 1 ;
V_18 -> V_19 = 1 ;
V_18 -> V_21 = 1 ;
return 0 ;
}
void F_21 ( T_5 * V_18 )
{
free ( V_18 -> V_23 ) ;
}
void F_22 ( T_5 * V_18 )
{
T_4 * V_27 ;
for( V_27 = V_18 -> V_24 ; V_27 ; V_27 = V_27 -> V_17 ) {
if( F_23 ( & V_27 -> V_1 ) == 0 ) {
return;
} else {
V_18 -> V_24 = V_27 ;
}
}
}
T_6 F_24 ( T_5 * V_18 )
{
T_4 * V_27 ;
T_6 V_13 ;
V_13 = 0 ;
for( V_27 = V_18 -> V_23 ; V_27 ; V_27 = V_27 -> V_17 ) {
V_13 += F_23 ( & V_27 -> V_1 ) ;
}
return V_13 ;
}
static T_6 F_25 ( T_5 * V_18 )
{
return ( T_6 ) ( F_26 ( & V_18 -> V_24 -> V_1 ) +
( V_18 -> V_15 - V_18 -> V_20 ) * ( V_18 -> V_19 - V_18 -> V_25 ) ) ;
}
static int F_27 ( T_5 * V_18 )
{
int V_16 ;
T_4 * V_14 ;
if( V_18 -> V_24 -> V_17 ) {
V_18 -> V_24 = V_18 -> V_24 -> V_17 ;
return 0 ;
}
if( V_18 -> V_19 == V_18 -> V_25 ) {
return V_28 ;
}
V_16 = F_13 ( & V_14 , V_18 -> V_15 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
F_28 ( fprintf ( V_29 ,
L_1 ,
V_18 -> V_15 , V_18 , V_18 -> V_25 ) ) ;
++ V_18 -> V_25 ;
V_18 -> V_24 -> V_17 = V_14 ;
V_18 -> V_24 = V_14 ;
F_18 ( & V_18 -> V_24 -> V_1 , V_18 -> V_20 ) ;
return 0 ;
}
int F_29 ( T_5 * V_18 , const void * V_30 , T_2 V_13 )
{
int V_16 ;
T_2 V_31 ;
T_1 * V_1 ;
const T_3 * V_32 ;
if( F_25 ( V_18 ) < ( T_6 ) V_13 ) {
return V_28 ;
}
V_32 = ( const T_3 * ) V_30 ;
while( V_13 ) {
V_1 = & V_18 -> V_24 -> V_1 ;
V_31 = F_30 ( ( T_2 ) F_26 ( V_1 ) , V_13 ) ;
if( V_31 == 0 ) {
V_16 = F_27 ( V_18 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
continue;
}
V_1 -> V_5 = F_31 ( V_1 -> V_5 , V_32 , V_31 ) ;
V_32 += V_13 ;
V_13 -= V_31 ;
}
return 0 ;
}
static int F_32 ( T_5 * V_18 )
{
int V_16 ;
T_1 * V_1 ;
V_1 = & V_18 -> V_24 -> V_1 ;
if( F_26 ( V_1 ) > 0 ) {
return 0 ;
}
V_16 = F_27 ( V_18 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
return 0 ;
}
int F_33 ( T_5 * V_18 , T_3 V_33 )
{
int V_16 ;
V_16 = F_32 ( V_18 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
* V_18 -> V_24 -> V_1 . V_5 ++ = V_33 ;
return 0 ;
}
int F_34 ( T_5 * V_18 , T_3 V_33 )
{
int V_16 ;
V_16 = F_32 ( V_18 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
* V_18 -> V_24 -> V_1 . V_5 = V_33 ;
return 0 ;
}
int F_35 ( T_5 * V_18 , T_3 V_33 )
{
int V_16 ;
V_16 = F_32 ( V_18 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
* V_18 -> V_24 -> V_1 . V_5 ++ |= V_33 ;
return 0 ;
}
int F_36 ( T_5 * V_18 , T_3 V_33 )
{
int V_16 ;
V_16 = F_32 ( V_18 ) ;
if( V_16 != 0 ) {
return V_16 ;
}
* V_18 -> V_24 -> V_1 . V_5 |= V_33 ;
return 0 ;
}
T_6 F_37 ( T_5 * V_18 , T_3 * * V_34 )
{
T_2 V_13 ;
T_4 * V_14 ;
T_1 * V_1 ;
T_3 * V_35 ;
T_1 V_36 ;
V_13 = 0 ;
for( V_14 = V_18 -> V_23 ; V_14 ; V_14 = V_14 -> V_17 ) {
V_13 += F_23 ( & V_14 -> V_1 ) ;
}
if( ! V_13 ) {
V_35 = NULL ;
} else {
V_35 = ( T_3 * ) malloc ( V_13 ) ;
if( V_35 == NULL ) {
return V_11 ;
}
}
F_12 ( & V_36 , V_35 , V_13 ) ;
for( V_14 = V_18 -> V_23 ; V_14 ; V_14 = V_14 -> V_17 ) {
V_1 = & V_14 -> V_1 ;
if( V_36 . V_5 ) {
V_36 . V_5 = F_31 ( V_36 . V_5 ,
V_1 -> V_4 , F_23 ( V_1 ) ) ;
}
F_11 ( V_1 ) ;
F_18 ( & V_14 -> V_1 , V_18 -> V_20 ) ;
}
V_18 -> V_24 = V_18 -> V_23 ;
* V_34 = V_35 ;
return ( T_6 ) V_13 ;
}
void F_38 ( T_5 * V_18 )
{
T_4 * V_14 , * V_27 ;
T_2 V_37 ;
V_37 = V_18 -> V_21 ;
for( V_27 = V_18 -> V_23 ; V_27 ; V_27 = V_27 -> V_17 ) {
F_11 ( & V_27 -> V_1 ) ;
F_18 ( & V_27 -> V_1 , V_18 -> V_20 ) ;
if( -- V_37 == 0 ) {
break;
}
}
if( V_27 ) {
V_14 = V_27 -> V_17 ;
V_27 -> V_17 = NULL ;
for( V_27 = V_14 ; V_27 ; ) {
V_14 = V_27 -> V_17 ;
F_14 ( V_27 ) ;
V_27 = V_14 ;
}
V_18 -> V_25 = V_18 -> V_21 ;
}
V_18 -> V_24 = V_18 -> V_23 ;
}
int F_39 ( T_5 * V_18 )
{
return F_27 ( V_18 ) ;
}
int F_40 ( T_5 * V_18 )
{
T_4 * V_14 ;
V_14 = V_18 -> V_24 -> V_17 ;
return V_14 && F_23 ( & V_14 -> V_1 ) ;
}
