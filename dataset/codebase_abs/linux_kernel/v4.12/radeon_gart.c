int F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 . V_6 ,
& V_2 -> V_5 . V_7 ) ;
if ( V_3 == NULL ) {
return - V_8 ;
}
#ifdef F_3
if ( V_2 -> V_9 == V_10 || V_2 -> V_9 == V_11 ||
V_2 -> V_9 == V_12 || V_2 -> V_9 == V_13 ) {
F_4 ( ( unsigned long ) V_3 ,
V_2 -> V_5 . V_6 >> V_14 ) ;
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
if ( V_2 -> V_9 == V_10 || V_2 -> V_9 == V_11 ||
V_2 -> V_9 == V_12 || V_2 -> V_9 == V_13 ) {
F_6 ( ( unsigned long ) V_2 -> V_5 . V_3 ,
V_2 -> V_5 . V_6 >> V_14 ) ;
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
int V_15 ;
if ( V_2 -> V_5 . V_16 == NULL ) {
V_15 = F_9 ( V_2 , V_2 -> V_5 . V_6 ,
V_17 , true , V_18 ,
0 , NULL , NULL , & V_2 -> V_5 . V_16 ) ;
if ( V_15 ) {
return V_15 ;
}
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_1 V_19 ;
int V_15 ;
V_15 = F_11 ( V_2 -> V_5 . V_16 , false ) ;
if ( F_12 ( V_15 != 0 ) )
return V_15 ;
V_15 = F_13 ( V_2 -> V_5 . V_16 ,
V_18 , & V_19 ) ;
if ( V_15 ) {
F_14 ( V_2 -> V_5 . V_16 ) ;
return V_15 ;
}
V_15 = F_15 ( V_2 -> V_5 . V_16 , & V_2 -> V_5 . V_3 ) ;
if ( V_15 )
F_16 ( V_2 -> V_5 . V_16 ) ;
F_14 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_7 = V_19 ;
if ( ! V_15 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_5 . V_21 ; V_20 ++ )
F_17 ( V_2 , V_20 , V_2 -> V_5 . V_22 [ V_20 ] ) ;
F_18 () ;
F_19 ( V_2 ) ;
}
return V_15 ;
}
void F_20 ( struct V_1 * V_2 )
{
int V_15 ;
if ( V_2 -> V_5 . V_16 == NULL ) {
return;
}
V_15 = F_11 ( V_2 -> V_5 . V_16 , false ) ;
if ( F_21 ( V_15 == 0 ) ) {
F_22 ( V_2 -> V_5 . V_16 ) ;
F_16 ( V_2 -> V_5 . V_16 ) ;
F_14 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_3 = NULL ;
}
}
void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_16 == NULL ) {
return;
}
F_24 ( & V_2 -> V_5 . V_16 ) ;
}
void F_25 ( struct V_1 * V_2 , unsigned V_23 ,
int V_24 )
{
unsigned V_25 ;
unsigned V_26 ;
int V_20 , V_27 ;
if ( ! V_2 -> V_5 . V_28 ) {
F_26 ( 1 , L_1 ) ;
return;
}
V_25 = V_23 / V_29 ;
V_26 = V_25 / ( V_17 / V_29 ) ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ , V_26 ++ ) {
if ( V_2 -> V_5 . V_24 [ V_26 ] ) {
V_2 -> V_5 . V_24 [ V_26 ] = NULL ;
for ( V_27 = 0 ; V_27 < ( V_17 / V_29 ) ; V_27 ++ , V_25 ++ ) {
V_2 -> V_5 . V_22 [ V_25 ] = V_2 -> V_30 . V_31 ;
if ( V_2 -> V_5 . V_3 ) {
F_17 ( V_2 , V_25 ,
V_2 -> V_30 . V_31 ) ;
}
}
}
}
if ( V_2 -> V_5 . V_3 ) {
F_18 () ;
F_19 ( V_2 ) ;
}
}
int F_27 ( struct V_1 * V_2 , unsigned V_23 ,
int V_24 , struct V_32 * * V_33 , T_2 * V_34 ,
T_3 V_35 )
{
unsigned V_25 ;
unsigned V_26 ;
T_1 V_36 , V_37 ;
int V_20 , V_27 ;
if ( ! V_2 -> V_5 . V_28 ) {
F_26 ( 1 , L_2 ) ;
return - V_38 ;
}
V_25 = V_23 / V_29 ;
V_26 = V_25 / ( V_17 / V_29 ) ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ , V_26 ++ ) {
V_2 -> V_5 . V_24 [ V_26 ] = V_33 [ V_20 ] ;
V_36 = V_34 [ V_20 ] ;
for ( V_27 = 0 ; V_27 < ( V_17 / V_29 ) ; V_27 ++ , V_25 ++ ) {
V_37 = F_28 ( V_36 , V_35 ) ;
V_2 -> V_5 . V_22 [ V_25 ] = V_37 ;
if ( V_2 -> V_5 . V_3 ) {
F_17 ( V_2 , V_25 , V_37 ) ;
}
V_36 += V_29 ;
}
}
if ( V_2 -> V_5 . V_3 ) {
F_18 () ;
F_19 ( V_2 ) ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_15 , V_20 ;
if ( V_2 -> V_5 . V_24 ) {
return 0 ;
}
if ( V_17 < V_29 ) {
F_30 ( L_3 ) ;
return - V_38 ;
}
V_15 = F_31 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_5 . V_39 = V_2 -> V_40 . V_41 / V_17 ;
V_2 -> V_5 . V_21 = V_2 -> V_40 . V_41 / V_29 ;
F_32 ( L_4 ,
V_2 -> V_5 . V_39 , V_2 -> V_5 . V_21 ) ;
V_2 -> V_5 . V_24 = F_33 ( sizeof( void * ) * V_2 -> V_5 . V_39 ) ;
if ( V_2 -> V_5 . V_24 == NULL ) {
F_34 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_5 . V_22 = F_35 ( sizeof( T_1 ) *
V_2 -> V_5 . V_21 ) ;
if ( V_2 -> V_5 . V_22 == NULL ) {
F_34 ( V_2 ) ;
return - V_8 ;
}
for ( V_20 = 0 ; V_20 < V_2 -> V_5 . V_21 ; V_20 ++ )
V_2 -> V_5 . V_22 [ V_20 ] = V_2 -> V_30 . V_31 ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_28 ) {
F_25 ( V_2 , 0 , V_2 -> V_5 . V_39 ) ;
}
V_2 -> V_5 . V_28 = false ;
F_36 ( V_2 -> V_5 . V_24 ) ;
F_36 ( V_2 -> V_5 . V_22 ) ;
V_2 -> V_5 . V_24 = NULL ;
V_2 -> V_5 . V_22 = NULL ;
F_37 ( V_2 ) ;
}
