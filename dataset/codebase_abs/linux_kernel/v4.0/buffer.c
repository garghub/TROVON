void T_1 F_1 ( void )
{
if ( V_1 <= 32 )
;
else if ( V_1 <= 64 )
V_2 [ 0 ] = 64 ;
else if ( V_1 <= 128 )
V_2 [ 0 ] = 0 ;
else
F_2 () ;
}
int F_3 ( struct V_3 * V_4 )
{
char V_5 [ 16 ] ;
int V_6 , V_7 ;
if ( ! V_4 -> V_8 . V_9 -> V_10 &&
! ( V_4 -> V_11 -> V_12 & V_13 ) )
return 0 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
V_7 = V_2 [ V_6 ] ;
if ( ! V_7 )
continue;
snprintf ( V_5 , sizeof V_5 , L_1 , V_7 ) ;
V_4 -> V_15 [ V_6 ] = F_4 ( V_5 , V_4 -> V_8 . V_9 ,
V_7 , V_7 , 0 ) ;
if ( ! V_4 -> V_15 [ V_6 ] ) {
F_5 ( V_4 ) ;
return - V_16 ;
}
}
return 0 ;
}
void F_5 ( struct V_3 * V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
struct V_17 * V_15 = V_4 -> V_15 [ V_6 ] ;
if ( V_15 ) {
F_6 ( V_15 ) ;
V_4 -> V_15 [ V_6 ] = NULL ;
}
}
}
void * F_7 (
struct V_18 * V_19 ,
T_2 V_7 ,
T_3 V_20 ,
T_4 * V_21
)
{
struct V_3 * V_4 = F_8 ( V_19 ) ;
int V_6 ;
if ( ! V_19 -> V_9 -> V_10 &&
! ( V_4 -> V_11 -> V_12 & V_13 ) ) {
* V_21 = ~ ( T_4 ) 0 ;
return F_9 ( V_7 , V_20 ) ;
}
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
if ( V_7 <= V_2 [ V_6 ] )
return F_10 ( V_4 -> V_15 [ V_6 ] , V_20 , V_21 ) ;
}
return F_11 ( V_4 -> V_8 . V_9 , V_7 , V_21 , V_20 ) ;
}
void F_12 (
struct V_18 * V_19 ,
T_2 V_7 ,
void * V_22 ,
T_4 V_21
)
{
struct V_3 * V_4 = F_8 ( V_19 ) ;
int V_6 ;
if ( ! V_22 )
return;
if ( ! V_19 -> V_9 -> V_10 &&
! ( V_4 -> V_11 -> V_12 & V_13 ) ) {
F_13 ( V_22 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
if ( V_7 <= V_2 [ V_6 ] ) {
F_14 ( V_4 -> V_15 [ V_6 ] , V_22 , V_21 ) ;
return;
}
}
F_15 ( V_4 -> V_8 . V_9 , V_7 , V_22 , V_21 ) ;
}
