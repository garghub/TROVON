static int F_1 ( const T_1 * const * V_1 , const T_1 * const * V_2 )
{
return ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ;
}
int F_2 ( T_2 * V_4 , int V_5 , int V_6 )
{
T_1 * V_7 ;
int V_8 ;
if ( V_5 == V_9 )
return F_3 ( V_10 , V_4 ,
V_6 | V_11 ) ;
V_8 = F_4 ( V_5 ) ;
if ( V_8 == - 1 )
return F_5 ( V_5 , V_4 , V_6 ) ;
V_7 = F_6 ( V_8 ) ;
return V_7 -> V_12 ( V_7 , V_4 , V_6 ) ;
}
int F_7 ( void )
{
if ( ! V_13 )
return V_14 ;
return F_8 ( V_13 ) + V_14 ;
}
T_1 * F_6 ( int V_8 )
{
if ( V_8 < 0 )
return NULL ;
if ( V_8 < ( int ) V_14 )
return V_15 + V_8 ;
return F_9 ( V_13 , V_8 - V_14 ) ;
}
int F_4 ( int V_5 )
{
T_1 V_16 ;
int V_8 ;
if ( ( V_5 >= V_17 ) && ( V_5 <= V_18 ) )
return V_5 - V_17 ;
V_16 . V_3 = V_5 ;
if ( ! V_13 )
return - 1 ;
V_8 = F_10 ( V_13 , & V_16 ) ;
if ( V_8 == - 1 )
return - 1 ;
return V_8 + V_14 ;
}
int F_11 ( int * V_19 , int V_3 )
{
if ( F_4 ( V_3 ) == - 1 ) {
F_12 ( V_20 , V_21 ) ;
return 0 ;
}
* V_19 = V_3 ;
return 1 ;
}
int F_13 ( int V_5 , int V_6 , int (* F_14) ( T_1 * , T_2 * , int ) ,
const char * V_22 , int V_23 , void * V_24 )
{
int V_8 ;
T_1 * V_25 ;
V_6 &= ~ V_26 ;
V_6 |= V_27 ;
V_8 = F_4 ( V_5 ) ;
if ( V_8 == - 1 ) {
if ( ( V_25 = F_15 ( sizeof( * V_25 ) ) ) == NULL ) {
F_12 ( V_28 , V_29 ) ;
return 0 ;
}
V_25 -> V_6 = V_26 ;
} else
V_25 = F_6 ( V_8 ) ;
if ( V_25 -> V_6 & V_27 )
F_16 ( V_25 -> V_22 ) ;
if ( ( V_25 -> V_22 = F_17 ( V_22 ) ) == NULL ) {
F_12 ( V_28 , V_29 ) ;
goto V_30;
}
V_25 -> V_6 &= V_26 ;
V_25 -> V_6 |= V_6 ;
V_25 -> V_3 = V_5 ;
V_25 -> V_12 = F_14 ;
V_25 -> V_23 = V_23 ;
V_25 -> V_24 = V_24 ;
if ( V_8 == - 1 ) {
if ( V_13 == NULL
&& ( V_13 = F_18 ( F_1 ) ) == NULL ) {
F_12 ( V_28 , V_29 ) ;
goto V_30; ;
}
if ( ! F_19 ( V_13 , V_25 ) ) {
F_12 ( V_28 , V_29 ) ;
goto V_30;
}
}
return 1 ;
V_30:
if ( V_8 == - 1 ) {
F_16 ( V_25 -> V_22 ) ;
F_16 ( V_25 ) ;
}
return 0 ;
}
static void F_20 ( T_1 * V_31 )
{
if ( ! V_31 )
return;
if ( V_31 -> V_6 & V_26 ) {
if ( V_31 -> V_6 & V_27 )
F_16 ( V_31 -> V_22 ) ;
F_16 ( V_31 ) ;
}
}
void F_21 ( void )
{
F_22 ( V_13 , F_20 ) ;
V_13 = NULL ;
}
int F_23 ( const T_1 * V_32 )
{
return V_32 -> V_6 ;
}
char * F_24 ( const T_1 * V_32 )
{
return V_32 -> V_22 ;
}
int F_25 ( const T_1 * V_32 )
{
return V_32 -> V_3 ;
}
static int F_26 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
V_6 |= V_11 | V_33 ;
return F_3 ( V_3 -> V_23 , V_4 , V_6 ) ;
}
static int F_27 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
V_6 &= ~ ( V_11 | V_33 ) ;
return F_3 ( V_3 -> V_23 , V_4 , V_6 ) ;
}
static int F_28 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
F_29 ( V_4 , - 1 , 0 ) ;
if ( ( V_6 & V_34 ) == 0 && V_4 -> V_35 & V_36 )
return V_37 ;
else
return V_38 ;
}
static int F_3 ( int V_5 , T_2 * V_4 , int V_6 )
{
T_3 * V_39 = V_4 -> V_40 ;
int V_41 ;
if ( V_39 && V_39 -> V_42 ) {
for ( V_41 = 0 ; V_41 < F_30 ( V_39 -> V_42 ) ; V_41 ++ ) {
T_4 * V_43 = F_31 ( V_39 -> V_42 , V_41 ) ;
int V_44 = F_32 ( V_43 ) ;
if ( V_44 == V_5 || ( V_44 == V_10 &&
( V_6 & V_33 ) ) )
return V_45 ;
}
}
if ( V_39 && V_39 -> V_3 ) {
for ( V_41 = 0 ; V_41 < F_30 ( V_39 -> V_3 ) ; V_41 ++ ) {
T_4 * V_43 = F_31 ( V_39 -> V_3 , V_41 ) ;
int V_44 = F_32 ( V_43 ) ;
if ( V_44 == V_5 || ( V_44 == V_10 &&
( V_6 & V_33 ) ) )
return V_37 ;
}
return V_45 ;
}
if ( ( V_6 & V_11 ) == 0 )
return V_38 ;
return F_28 ( NULL , V_4 , V_6 ) ;
}
