int F_1 ( T_1 * V_1 )
{
return V_1 -> V_2 -> V_3 ( V_1 ) ;
}
int F_2 ( unsigned char * V_4 , const T_2 * V_5 , T_1 * V_1 )
{
return V_1 -> V_2 -> V_6 ( V_4 , V_5 , V_1 ) ;
}
int F_3 ( unsigned char * V_4 , const T_2 * V_5 , T_1 * V_1 )
{
int V_7 , V_8 ;
V_7 = V_1 -> V_2 -> V_6 ( V_4 , V_5 , V_1 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_8 = F_4 ( V_1 -> V_9 ) - V_7 ;
if ( V_8 > 0 ) {
memmove ( V_4 + V_8 , V_4 , V_7 ) ;
memset ( V_4 , 0 , V_8 ) ;
}
return V_7 + V_8 ;
}
const T_3 * F_5 ( void )
{
return & V_10 ;
}
static int V_3 ( T_1 * V_1 )
{
int V_11 = 0 ;
int V_12 = 0 ;
unsigned V_13 ;
T_4 * V_14 ;
T_5 * V_15 = NULL ;
T_2 * V_5 = NULL , * V_16 = NULL ;
V_14 = F_6 () ;
if ( V_14 == NULL )
goto V_17;
if ( V_1 -> V_16 == NULL ) {
V_16 = F_7 () ;
if ( V_16 == NULL )
goto V_17;
V_12 = 1 ;
} else
V_16 = V_1 -> V_16 ;
if ( V_1 -> V_5 == NULL ) {
V_5 = F_8 () ;
if ( V_5 == NULL )
goto V_17;
} else
V_5 = V_1 -> V_5 ;
if ( V_1 -> V_18 & V_19 ) {
V_15 = F_9 ( & V_1 -> V_20 ,
V_1 -> V_21 , V_1 -> V_9 , V_14 ) ;
if ( ! V_15 )
goto V_17;
}
if ( V_12 ) {
if ( V_1 -> V_22 ) {
do {
if ( ! F_10 ( V_16 , V_1 -> V_22 ) )
goto V_17;
}
while ( F_11 ( V_16 ) || F_12 ( V_16 ) );
} else {
V_13 = V_1 -> V_23 ? V_1 -> V_23 : F_13 ( V_1 -> V_9 ) - 1 ;
if ( ! F_14 ( V_16 , V_13 , V_24 , V_25 ) )
goto V_17;
}
}
{
T_2 * V_26 = F_8 () ;
if ( V_26 == NULL )
goto V_17;
F_15 ( V_26 , V_16 , V_27 ) ;
if ( ! V_1 -> V_2 -> V_28 ( V_1 , V_5 , V_1 -> V_29 , V_26 , V_1 -> V_9 , V_14 , V_15 ) ) {
F_16 ( V_26 ) ;
goto V_17;
}
F_16 ( V_26 ) ;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_16 = V_16 ;
V_11 = 1 ;
V_17:
if ( V_11 != 1 )
F_17 ( V_30 , V_31 ) ;
if ( V_5 != V_1 -> V_5 )
F_16 ( V_5 ) ;
if ( V_16 != V_1 -> V_16 )
F_16 ( V_16 ) ;
F_18 ( V_14 ) ;
return ( V_11 ) ;
}
static int V_6 ( unsigned char * V_4 , const T_2 * V_5 , T_1 * V_1 )
{
T_4 * V_14 = NULL ;
T_5 * V_15 = NULL ;
T_2 * V_32 ;
int V_33 = - 1 ;
int V_34 ;
if ( F_13 ( V_1 -> V_9 ) > V_35 ) {
F_17 ( V_36 , V_37 ) ;
goto V_17;
}
V_14 = F_6 () ;
if ( V_14 == NULL )
goto V_17;
F_19 ( V_14 ) ;
V_32 = F_20 ( V_14 ) ;
if ( V_1 -> V_16 == NULL ) {
F_17 ( V_36 , V_38 ) ;
goto V_17;
}
if ( V_1 -> V_18 & V_19 ) {
V_15 = F_9 ( & V_1 -> V_20 ,
V_1 -> V_21 , V_1 -> V_9 , V_14 ) ;
F_21 ( V_1 -> V_16 , V_27 ) ;
if ( ! V_15 )
goto V_17;
}
if ( ! F_22 ( V_1 , V_5 , & V_34 ) || V_34 ) {
F_17 ( V_36 , V_39 ) ;
goto V_17;
}
if ( ! V_1 ->
V_2 -> V_28 ( V_1 , V_32 , V_5 , V_1 -> V_16 , V_1 -> V_9 , V_14 , V_15 ) ) {
F_17 ( V_36 , V_31 ) ;
goto V_17;
}
V_33 = F_23 ( V_32 , V_4 ) ;
V_17:
if ( V_14 != NULL ) {
F_24 ( V_14 ) ;
F_18 ( V_14 ) ;
}
return ( V_33 ) ;
}
static int F_25 ( const T_1 * V_1 , T_2 * V_40 ,
const T_2 * V_41 , const T_2 * V_9 ,
const T_2 * V_42 , T_4 * V_14 , T_5 * V_43 )
{
return F_26 ( V_40 , V_41 , V_9 , V_42 , V_14 , V_43 ) ;
}
static int F_27 ( T_1 * V_1 )
{
V_1 -> V_18 |= V_19 ;
return ( 1 ) ;
}
static int F_28 ( T_1 * V_1 )
{
F_29 ( V_1 -> V_20 ) ;
return ( 1 ) ;
}
