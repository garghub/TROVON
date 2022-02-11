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
V_12 , true , V_13 ,
V_14 ,
NULL , NULL , & V_2 -> V_5 . V_11 ) ;
if ( V_10 ) {
return V_10 ;
}
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_1 V_15 ;
int V_10 ;
V_10 = F_11 ( V_2 -> V_5 . V_11 , false ) ;
if ( F_12 ( V_10 != 0 ) )
return V_10 ;
V_10 = F_13 ( V_2 -> V_5 . V_11 ,
V_13 , & V_15 ) ;
if ( V_10 ) {
F_14 ( V_2 -> V_5 . V_11 ) ;
return V_10 ;
}
V_10 = F_15 ( V_2 -> V_5 . V_11 , & V_2 -> V_5 . V_3 ) ;
if ( V_10 )
F_16 ( V_2 -> V_5 . V_11 ) ;
F_14 ( V_2 -> V_5 . V_11 ) ;
V_2 -> V_5 . V_7 = V_15 ;
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
void F_22 ( struct V_1 * V_2 , unsigned V_16 ,
int V_17 )
{
unsigned V_18 ;
unsigned V_19 ;
int V_20 , V_21 ;
T_2 V_22 ;
T_3 V_23 = V_24 ;
if ( ! V_2 -> V_5 . V_25 ) {
F_23 ( 1 , L_1 ) ;
return;
}
V_18 = V_16 / V_26 ;
V_19 = V_18 / ( V_12 / V_26 ) ;
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ , V_19 ++ ) {
#ifdef F_24
V_2 -> V_5 . V_17 [ V_19 ] = NULL ;
#endif
V_22 = V_2 -> V_27 . V_28 ;
if ( ! V_2 -> V_5 . V_3 )
continue;
for ( V_21 = 0 ; V_21 < ( V_12 / V_26 ) ; V_21 ++ , V_18 ++ ) {
F_25 ( V_2 , V_2 -> V_5 . V_3 ,
V_18 , V_22 , V_23 ) ;
V_22 += V_26 ;
}
}
F_26 () ;
F_27 ( V_2 , 0 ) ;
}
int F_28 ( struct V_1 * V_2 , unsigned V_16 ,
int V_17 , struct V_29 * * V_30 , T_4 * V_31 ,
T_3 V_23 )
{
unsigned V_18 ;
unsigned V_19 ;
T_1 V_22 ;
int V_20 , V_21 ;
if ( ! V_2 -> V_5 . V_25 ) {
F_23 ( 1 , L_2 ) ;
return - V_32 ;
}
V_18 = V_16 / V_26 ;
V_19 = V_18 / ( V_12 / V_26 ) ;
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ , V_19 ++ ) {
#ifdef F_24
V_2 -> V_5 . V_17 [ V_19 ] = V_30 [ V_20 ] ;
#endif
if ( V_2 -> V_5 . V_3 ) {
V_22 = V_31 [ V_20 ] ;
for ( V_21 = 0 ; V_21 < ( V_12 / V_26 ) ; V_21 ++ , V_18 ++ ) {
F_25 ( V_2 , V_2 -> V_5 . V_3 , V_18 , V_22 , V_23 ) ;
V_22 += V_26 ;
}
}
}
F_26 () ;
F_27 ( V_2 , 0 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_27 . V_29 )
return 0 ;
if ( V_12 < V_26 ) {
F_30 ( L_3 ) ;
return - V_32 ;
}
V_10 = F_31 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_2 -> V_5 . V_33 = V_2 -> V_34 . V_35 / V_12 ;
V_2 -> V_5 . V_36 = V_2 -> V_34 . V_35 / V_26 ;
F_32 ( L_4 ,
V_2 -> V_5 . V_33 , V_2 -> V_5 . V_36 ) ;
#ifdef F_24
V_2 -> V_5 . V_17 = F_33 ( sizeof( void * ) * V_2 -> V_5 . V_33 ) ;
if ( V_2 -> V_5 . V_17 == NULL ) {
F_34 ( V_2 ) ;
return - V_8 ;
}
#endif
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_25 ) {
F_22 ( V_2 , 0 , V_2 -> V_5 . V_33 ) ;
}
V_2 -> V_5 . V_25 = false ;
#ifdef F_24
F_35 ( V_2 -> V_5 . V_17 ) ;
V_2 -> V_5 . V_17 = NULL ;
#endif
F_36 ( V_2 ) ;
}
