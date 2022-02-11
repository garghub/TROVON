static inline int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return 0 ;
V_2 -> V_3 = F_2 (
V_4 , sizeof( struct V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_2 -> V_7 , L_1 ) ;
return - V_8 ;
}
return 0 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_5 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
int V_9 ;
F_7 ( & V_2 -> V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ )
F_8 ( & V_2 -> V_3 [ V_9 ] . V_12 , & V_2 -> V_10 ) ;
}
struct V_13 * F_9 ( int V_14 )
{
struct V_1 * V_2 ;
struct V_13 * V_7 ;
int V_9 , V_15 ;
F_10 ( L_2 ) ;
V_7 = F_11 ( sizeof( struct V_1 ) + V_14 ) ;
if ( ! V_7 ) {
F_12 ( L_3 ) ;
goto V_16;
}
V_2 = F_13 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 ) {
F_12 ( L_4 ,
V_15 ) ;
goto V_16;
}
F_6 ( V_2 ) ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 1 ;
F_7 ( & V_2 -> V_25 ) ;
F_14 ( & V_2 -> V_26 ) ;
V_2 -> V_26 . V_27 = ( unsigned long ) V_2 ;
V_2 -> V_26 . V_28 = V_29 ;
F_15 ( & V_2 -> V_30 ) ;
F_15 ( & V_2 -> V_31 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_24 = 1 ;
V_2 -> V_37 = 0 ;
F_16 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ )
F_7 ( & V_2 -> V_39 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < 17 ; V_9 ++ ) {
V_2 -> V_40 [ V_9 ] = - 1 ;
V_2 -> V_41 [ V_9 ] = - 1 ;
V_2 -> V_42 [ V_9 ] = 0 ;
}
F_17 () ;
F_18 () ;
F_19 () ;
return V_7 ;
V_16:
if ( V_7 )
F_20 ( V_7 ) ;
return NULL ;
}
void F_21 ( struct V_13 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
int V_9 ;
struct V_43 * V_44 , * V_45 ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_26 ) ;
F_24 ( V_2 , 1 ) ;
for ( V_9 = 0 ; V_9 < V_46 ; V_9 ++ ) {
struct V_47 * V_48 = V_2 -> V_48 [ V_9 ] ;
if ( V_48 ) {
if ( V_48 -> V_49 )
V_48 -> V_49 -> V_50 ( V_48 -> V_51 ) ;
F_5 ( V_48 ) ;
V_2 -> V_48 [ V_9 ] = NULL ;
}
}
F_4 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
F_25 (p, q, &ieee->ibss_mac_hash[i]) {
F_5 ( F_26 ( V_44 , struct V_52 , V_12 ) ) ;
F_27 ( V_44 ) ;
}
}
F_20 ( V_7 ) ;
}
