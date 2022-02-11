int F_1 ( struct V_1 * V_2 )
{
char V_3 [ 16 ] ;
int V_4 , V_5 ;
if ( ! V_2 -> V_6 . V_7 -> V_8 &&
! ( V_2 -> V_9 -> V_10 & V_11 ) )
return 0 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_5 = V_13 [ V_4 ] ;
if ( ! V_5 )
continue;
snprintf ( V_3 , sizeof V_3 , L_1 , V_5 ) ;
V_2 -> V_14 [ V_4 ] = F_2 ( V_3 , V_2 -> V_6 . V_7 ,
V_5 , V_5 , 0 ) ;
if ( ! V_2 -> V_14 [ V_4 ] ) {
F_3 ( V_2 ) ;
return - V_15 ;
}
}
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
struct V_16 * V_14 = V_2 -> V_14 [ V_4 ] ;
if ( V_14 ) {
F_4 ( V_14 ) ;
V_2 -> V_14 [ V_4 ] = NULL ;
}
}
}
void * F_5 (
struct V_17 * V_18 ,
T_1 V_5 ,
T_2 V_19 ,
T_3 * V_20
)
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_4 ;
if ( ! V_18 -> V_7 -> V_8 &&
! ( V_2 -> V_9 -> V_10 & V_11 ) ) {
* V_20 = ~ ( T_3 ) 0 ;
return F_7 ( V_5 , V_19 ) ;
}
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( V_5 <= V_13 [ V_4 ] )
return F_8 ( V_2 -> V_14 [ V_4 ] , V_19 , V_20 ) ;
}
return F_9 ( V_2 -> V_6 . V_7 , V_5 , V_20 , V_19 ) ;
}
void F_10 (
struct V_17 * V_18 ,
T_1 V_5 ,
void * V_21 ,
T_3 V_20
)
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_4 ;
if ( ! V_21 )
return;
if ( ! V_18 -> V_7 -> V_8 &&
! ( V_2 -> V_9 -> V_10 & V_11 ) ) {
F_11 ( V_21 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( V_5 <= V_13 [ V_4 ] ) {
F_12 ( V_2 -> V_14 [ V_4 ] , V_21 , V_20 ) ;
return;
}
}
F_13 ( V_2 -> V_6 . V_7 , V_5 , V_21 , V_20 ) ;
}
