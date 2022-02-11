int F_1 ( T_1 V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
V_1 ++ ;
for ( V_5 = 16 ; V_5 < V_1 ; V_5 <<= 1 )
;
V_4 = F_2 ( V_5 * sizeof( struct V_3 ) ) ;
if ( V_4 == NULL )
return - V_6 ;
V_7 . V_8 = V_4 ;
V_7 . V_9 = V_1 ;
V_7 . V_10 = 1 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = 0 ;
V_7 . V_13 = V_5 - 1 ;
V_7 . V_14 = V_2 & ~ V_7 . V_13 ;
return 0 ;
}
void F_3 ( void )
{
if ( ! V_7 . V_8 )
return;
F_4 ( V_7 . V_8 ) ;
V_7 . V_8 = NULL ;
}
T_1 F_5 ( void * V_15 , T_2 * * V_16 )
{
T_1 V_17 ;
T_1 V_13 ;
T_1 V_18 ;
T_1 V_19 ;
struct V_3 * V_20 = NULL ;
if ( ! V_15 ) {
F_6 ( L_1 ) ;
return 0 ;
}
if ( ! V_7 . V_8 ) {
F_6 ( L_2 ) ;
return 0 ;
}
F_7 ( & V_21 ) ;
if ( V_7 . V_11 ) {
V_17 = V_7 . V_11 ;
V_20 = & ( V_7 . V_8 [ V_17 ] ) ;
V_13 = V_7 . V_13 ;
V_18 = V_20 -> V_19 ;
V_7 . V_11 = V_18 & V_13 ;
V_19 = ( V_18 & ~ V_13 ) + V_17 ;
} else if ( V_7 . V_10 < V_7 . V_9 ) {
V_17 = V_7 . V_10 ++ ;
V_20 = & ( V_7 . V_8 [ V_17 ] ) ;
F_8 ( & V_20 -> V_16 ) ;
V_19 = V_7 . V_14 + V_17 ;
} else {
V_19 = 0 ;
}
F_9 ( & V_21 ) ;
if ( V_20 ) {
F_10 ( & V_20 -> V_16 ) ;
V_20 -> V_19 = V_19 ;
V_20 -> V_15 = V_15 ;
* V_16 = & V_20 -> V_16 ;
}
return V_19 ;
}
void F_11 ( T_1 V_19 )
{
struct V_3 * V_20 ;
T_1 V_17 ;
T_1 V_13 ;
if ( ! V_7 . V_8 ) {
F_6 ( L_3 ) ;
return;
}
V_13 = V_7 . V_13 ;
V_17 = V_19 & V_13 ;
V_20 = & ( V_7 . V_8 [ V_17 ] ) ;
F_7 ( & V_21 ) ;
if ( ! V_20 -> V_15 ) {
F_6 ( L_4 ) ;
goto exit;
}
if ( V_20 -> V_19 != V_19 ) {
F_6 ( L_5 ) ;
goto exit;
}
V_20 -> V_15 = NULL ;
V_20 -> V_19 = ( V_19 & ~ V_13 ) + ( V_13 + 1 ) ;
if ( V_7 . V_11 == 0 )
V_7 . V_11 = V_17 ;
else
V_7 . V_8 [ V_7 . V_12 ] . V_19 |= V_17 ;
V_7 . V_12 = V_17 ;
exit:
F_9 ( & V_21 ) ;
}
void * F_12 ( T_1 V_19 )
{
if ( F_13 ( V_7 . V_8 ) ) {
struct V_3 * V_20 ;
V_20 = & V_7 . V_8 [ V_19 &
V_7 . V_13 ] ;
if ( F_13 ( V_20 -> V_19 != 0 ) ) {
F_10 ( & V_20 -> V_16 ) ;
if ( F_13 ( ( V_20 -> V_19 == V_19 ) && ( V_20 -> V_15 ) ) )
return V_20 -> V_15 ;
F_14 ( & V_20 -> V_16 ) ;
}
}
return NULL ;
}
void * F_15 ( T_1 V_19 )
{
if ( F_13 ( V_7 . V_8 ) ) {
struct V_3 * V_20 ;
V_20 = & V_7 . V_8 [ V_19 &
V_7 . V_13 ] ;
if ( F_13 ( V_20 -> V_19 == V_19 ) )
return V_20 -> V_15 ;
}
return NULL ;
}
