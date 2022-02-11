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
V_2 -> V_5 . V_15 . V_16 . V_3 = V_3 ;
memset ( ( void * ) V_2 -> V_5 . V_15 . V_16 . V_3 , 0 , V_2 -> V_5 . V_6 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_15 . V_16 . V_3 == NULL ) {
return;
}
#ifdef F_3
if ( V_2 -> V_9 == V_10 || V_2 -> V_9 == V_11 ||
V_2 -> V_9 == V_12 || V_2 -> V_9 == V_13 ) {
F_6 ( ( unsigned long ) V_2 -> V_5 . V_15 . V_16 . V_3 ,
V_2 -> V_5 . V_6 >> V_14 ) ;
}
#endif
F_7 ( V_2 -> V_4 , V_2 -> V_5 . V_6 ,
( void * ) V_2 -> V_5 . V_15 . V_16 . V_3 ,
V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_15 . V_16 . V_3 = NULL ;
V_2 -> V_5 . V_7 = 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_5 . V_15 . V_18 . V_19 == NULL ) {
V_17 = F_9 ( V_2 , V_2 -> V_5 . V_6 ,
V_20 , true , V_21 ,
& V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
if ( V_17 ) {
return V_17 ;
}
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_1 V_22 ;
int V_17 ;
V_17 = F_11 ( V_2 -> V_5 . V_15 . V_18 . V_19 , false ) ;
if ( F_12 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_13 ( V_2 -> V_5 . V_15 . V_18 . V_19 ,
V_21 , & V_22 ) ;
if ( V_17 ) {
F_14 ( V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
return V_17 ;
}
V_17 = F_15 ( V_2 -> V_5 . V_15 . V_18 . V_19 ,
( void * * ) & V_2 -> V_5 . V_15 . V_18 . V_3 ) ;
if ( V_17 )
F_16 ( V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
F_14 ( V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
V_2 -> V_5 . V_7 = V_22 ;
return V_17 ;
}
void F_17 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_5 . V_15 . V_18 . V_19 == NULL ) {
return;
}
V_17 = F_11 ( V_2 -> V_5 . V_15 . V_18 . V_19 , false ) ;
if ( F_18 ( V_17 == 0 ) ) {
F_19 ( V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
F_16 ( V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
F_14 ( V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
}
F_20 ( & V_2 -> V_5 . V_15 . V_18 . V_19 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned V_23 ,
int V_24 )
{
unsigned V_25 ;
unsigned V_26 ;
int V_27 , V_28 ;
T_2 V_29 ;
if ( ! V_2 -> V_5 . V_30 ) {
F_22 ( 1 , L_1 ) ;
return;
}
V_25 = V_23 / V_31 ;
V_26 = V_25 / ( V_20 / V_31 ) ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ , V_26 ++ ) {
if ( V_2 -> V_5 . V_24 [ V_26 ] ) {
if ( ! V_2 -> V_5 . V_32 [ V_26 ] )
F_23 ( V_2 -> V_4 , V_2 -> V_5 . V_33 [ V_26 ] ,
V_20 , V_34 ) ;
V_2 -> V_5 . V_24 [ V_26 ] = NULL ;
V_2 -> V_5 . V_33 [ V_26 ] = V_2 -> V_35 . V_36 ;
V_29 = V_2 -> V_5 . V_33 [ V_26 ] ;
for ( V_28 = 0 ; V_28 < ( V_20 / V_31 ) ; V_28 ++ , V_25 ++ ) {
F_24 ( V_2 , V_25 , V_29 ) ;
V_29 += V_31 ;
}
}
}
F_25 () ;
F_26 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 , unsigned V_23 ,
int V_24 , struct V_37 * * V_38 , T_3 * V_39 )
{
unsigned V_25 ;
unsigned V_26 ;
T_1 V_29 ;
int V_27 , V_28 ;
if ( ! V_2 -> V_5 . V_30 ) {
F_22 ( 1 , L_2 ) ;
return - V_40 ;
}
V_25 = V_23 / V_31 ;
V_26 = V_25 / ( V_20 / V_31 ) ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ , V_26 ++ ) {
if ( 0 ) {
V_2 -> V_5 . V_32 [ V_26 ] = true ;
V_2 -> V_5 . V_33 [ V_26 ] = V_39 [ V_27 ] ;
} else {
V_2 -> V_5 . V_33 [ V_26 ] = F_28 ( V_2 -> V_4 , V_38 [ V_27 ] ,
0 , V_20 ,
V_34 ) ;
if ( F_29 ( V_2 -> V_4 , V_2 -> V_5 . V_33 [ V_26 ] ) ) {
F_21 ( V_2 , V_23 , V_24 ) ;
return - V_8 ;
}
}
V_2 -> V_5 . V_24 [ V_26 ] = V_38 [ V_27 ] ;
V_29 = V_2 -> V_5 . V_33 [ V_26 ] ;
for ( V_28 = 0 ; V_28 < ( V_20 / V_31 ) ; V_28 ++ , V_25 ++ ) {
F_24 ( V_2 , V_25 , V_29 ) ;
V_29 += V_31 ;
}
}
F_25 () ;
F_26 ( V_2 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
int V_27 , V_28 , V_25 ;
T_2 V_29 ;
for ( V_27 = 0 , V_25 = 0 ; V_27 < V_2 -> V_5 . V_41 ; V_27 ++ ) {
V_29 = V_2 -> V_5 . V_33 [ V_27 ] ;
for ( V_28 = 0 ; V_28 < ( V_20 / V_31 ) ; V_28 ++ , V_25 ++ ) {
F_24 ( V_2 , V_25 , V_29 ) ;
V_29 += V_31 ;
}
}
F_25 () ;
F_26 ( V_2 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_17 , V_27 ;
if ( V_2 -> V_5 . V_24 ) {
return 0 ;
}
if ( V_20 < V_31 ) {
F_32 ( L_3 ) ;
return - V_40 ;
}
V_17 = F_33 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_5 . V_41 = V_2 -> V_42 . V_43 / V_20 ;
V_2 -> V_5 . V_44 = V_2 -> V_42 . V_43 / V_31 ;
F_34 ( L_4 ,
V_2 -> V_5 . V_41 , V_2 -> V_5 . V_44 ) ;
V_2 -> V_5 . V_24 = F_35 ( sizeof( void * ) * V_2 -> V_5 . V_41 ,
V_45 ) ;
if ( V_2 -> V_5 . V_24 == NULL ) {
F_36 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_5 . V_33 = F_35 ( sizeof( T_3 ) *
V_2 -> V_5 . V_41 , V_45 ) ;
if ( V_2 -> V_5 . V_33 == NULL ) {
F_36 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_5 . V_32 = F_35 ( sizeof( bool ) *
V_2 -> V_5 . V_41 , V_45 ) ;
if ( V_2 -> V_5 . V_32 == NULL ) {
F_36 ( V_2 ) ;
return - V_8 ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_5 . V_41 ; V_27 ++ ) {
V_2 -> V_5 . V_33 [ V_27 ] = V_2 -> V_35 . V_36 ;
}
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_24 && V_2 -> V_5 . V_33 && V_2 -> V_5 . V_30 ) {
F_21 ( V_2 , 0 , V_2 -> V_5 . V_41 ) ;
}
V_2 -> V_5 . V_30 = false ;
F_37 ( V_2 -> V_5 . V_24 ) ;
F_37 ( V_2 -> V_5 . V_33 ) ;
F_37 ( V_2 -> V_5 . V_32 ) ;
V_2 -> V_5 . V_24 = NULL ;
V_2 -> V_5 . V_33 = NULL ;
V_2 -> V_5 . V_32 = NULL ;
F_38 ( V_2 ) ;
}
