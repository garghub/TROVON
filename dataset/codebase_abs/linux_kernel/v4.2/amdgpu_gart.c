int F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 . V_6 ,
& V_2 -> V_5 . V_7 ) ;
if ( V_3 == NULL ) {
return - V_8 ;
}
#ifdef F_3
if ( 0 ) {
F_4 ( ( unsigned long ) V_3 ,
V_2 -> V_5 . V_6 >> V_9 ) ;
}
#endif
V_2 -> V_5 . V_3 = V_3 ;
memset ( ( void * ) V_2 -> V_5 . V_3 , 0 , V_2 -> V_5 . V_6 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_3 == NULL ) {
return;
}
#ifdef F_3
if ( 0 ) {
F_6 ( ( unsigned long ) V_2 -> V_5 . V_3 ,
V_2 -> V_5 . V_6 >> V_9 ) ;
}
#endif
F_7 ( V_2 -> V_4 , V_2 -> V_5 . V_6 ,
( void * ) V_2 -> V_5 . V_3 ,
V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_3 = NULL ;
V_2 -> V_5 . V_7 = 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_5 . V_11 == NULL ) {
V_10 = F_9 ( V_2 , V_2 -> V_5 . V_6 ,
V_12 , true , V_13 , 0 ,
NULL , & V_2 -> V_5 . V_11 ) ;
if ( V_10 ) {
return V_10 ;
}
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_1 V_14 ;
int V_10 ;
V_10 = F_11 ( V_2 -> V_5 . V_11 , false ) ;
if ( F_12 ( V_10 != 0 ) )
return V_10 ;
V_10 = F_13 ( V_2 -> V_5 . V_11 ,
V_13 , & V_14 ) ;
if ( V_10 ) {
F_14 ( V_2 -> V_5 . V_11 ) ;
return V_10 ;
}
V_10 = F_15 ( V_2 -> V_5 . V_11 , & V_2 -> V_5 . V_3 ) ;
if ( V_10 )
F_16 ( V_2 -> V_5 . V_11 ) ;
F_14 ( V_2 -> V_5 . V_11 ) ;
V_2 -> V_5 . V_7 = V_14 ;
return V_10 ;
}
void F_17 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_5 . V_11 == NULL ) {
return;
}
V_10 = F_11 ( V_2 -> V_5 . V_11 , false ) ;
if ( F_18 ( V_10 == 0 ) ) {
F_19 ( V_2 -> V_5 . V_11 ) ;
F_16 ( V_2 -> V_5 . V_11 ) ;
F_14 ( V_2 -> V_5 . V_11 ) ;
V_2 -> V_5 . V_3 = NULL ;
}
}
void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_11 == NULL ) {
return;
}
F_21 ( & V_2 -> V_5 . V_11 ) ;
}
void F_22 ( struct V_1 * V_2 , unsigned V_15 ,
int V_16 )
{
unsigned V_17 ;
unsigned V_18 ;
int V_19 , V_20 ;
T_2 V_21 ;
T_3 V_22 = V_23 ;
if ( ! V_2 -> V_5 . V_24 ) {
F_23 ( 1 , L_1 ) ;
return;
}
V_17 = V_15 / V_25 ;
V_18 = V_17 / ( V_12 / V_25 ) ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ , V_18 ++ ) {
if ( V_2 -> V_5 . V_16 [ V_18 ] ) {
V_2 -> V_5 . V_16 [ V_18 ] = NULL ;
V_2 -> V_5 . V_26 [ V_18 ] = V_2 -> V_27 . V_28 ;
V_21 = V_2 -> V_5 . V_26 [ V_18 ] ;
if ( ! V_2 -> V_5 . V_3 )
continue;
for ( V_20 = 0 ; V_20 < ( V_12 / V_25 ) ; V_20 ++ , V_17 ++ ) {
F_24 ( V_2 , V_2 -> V_5 . V_3 ,
V_17 , V_21 , V_22 ) ;
V_21 += V_25 ;
}
}
}
F_25 () ;
F_26 ( V_2 , 0 ) ;
}
int F_27 ( struct V_1 * V_2 , unsigned V_15 ,
int V_16 , struct V_29 * * V_30 , T_4 * V_31 ,
T_3 V_22 )
{
unsigned V_17 ;
unsigned V_18 ;
T_1 V_21 ;
int V_19 , V_20 ;
if ( ! V_2 -> V_5 . V_24 ) {
F_23 ( 1 , L_2 ) ;
return - V_32 ;
}
V_17 = V_15 / V_25 ;
V_18 = V_17 / ( V_12 / V_25 ) ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ , V_18 ++ ) {
V_2 -> V_5 . V_26 [ V_18 ] = V_31 [ V_19 ] ;
V_2 -> V_5 . V_16 [ V_18 ] = V_30 [ V_19 ] ;
if ( V_2 -> V_5 . V_3 ) {
V_21 = V_2 -> V_5 . V_26 [ V_18 ] ;
for ( V_20 = 0 ; V_20 < ( V_12 / V_25 ) ; V_20 ++ , V_17 ++ ) {
F_24 ( V_2 , V_2 -> V_5 . V_3 , V_17 , V_21 , V_22 ) ;
V_21 += V_25 ;
}
}
}
F_25 () ;
F_26 ( V_2 , 0 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_10 , V_19 ;
if ( V_2 -> V_5 . V_16 ) {
return 0 ;
}
if ( V_12 < V_25 ) {
F_29 ( L_3 ) ;
return - V_32 ;
}
V_10 = F_30 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_2 -> V_5 . V_33 = V_2 -> V_34 . V_35 / V_12 ;
V_2 -> V_5 . V_36 = V_2 -> V_34 . V_35 / V_25 ;
F_31 ( L_4 ,
V_2 -> V_5 . V_33 , V_2 -> V_5 . V_36 ) ;
V_2 -> V_5 . V_16 = F_32 ( sizeof( void * ) * V_2 -> V_5 . V_33 ) ;
if ( V_2 -> V_5 . V_16 == NULL ) {
F_33 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_5 . V_26 = F_32 ( sizeof( T_4 ) *
V_2 -> V_5 . V_33 ) ;
if ( V_2 -> V_5 . V_26 == NULL ) {
F_33 ( V_2 ) ;
return - V_8 ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_5 . V_33 ; V_19 ++ ) {
V_2 -> V_5 . V_26 [ V_19 ] = V_2 -> V_27 . V_28 ;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_16 && V_2 -> V_5 . V_26 && V_2 -> V_5 . V_24 ) {
F_22 ( V_2 , 0 , V_2 -> V_5 . V_33 ) ;
}
V_2 -> V_5 . V_24 = false ;
F_34 ( V_2 -> V_5 . V_16 ) ;
F_34 ( V_2 -> V_5 . V_26 ) ;
V_2 -> V_5 . V_16 = NULL ;
V_2 -> V_5 . V_26 = NULL ;
F_35 ( V_2 ) ;
}
