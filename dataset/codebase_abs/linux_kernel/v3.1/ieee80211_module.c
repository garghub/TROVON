static inline int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return 0 ;
V_2 -> V_3 = F_2 (
V_4 , sizeof( struct V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_7 L_1 ,
V_2 -> V_8 -> V_9 ) ;
return - V_10 ;
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
int V_11 ;
F_7 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_4 ; V_11 ++ )
F_8 ( & V_2 -> V_3 [ V_11 ] . V_14 , & V_2 -> V_12 ) ;
}
struct V_15 * F_9 ( int V_16 )
{
struct V_1 * V_2 ;
struct V_15 * V_8 ;
int V_11 , V_17 ;
F_10 ( L_2 ) ;
V_8 = F_11 ( sizeof( struct V_1 ) + V_16 ) ;
if ( ! V_8 ) {
F_12 ( L_3 ) ;
goto V_18;
}
V_2 = F_13 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 ) {
F_12 ( L_4 ,
V_17 ) ;
goto V_18;
}
F_6 ( V_2 ) ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 1 ;
V_2 -> V_25 = 1 ;
V_2 -> V_26 = 1 ;
F_7 ( & V_2 -> V_27 ) ;
F_14 ( & V_2 -> V_28 ) ;
V_2 -> V_28 . V_29 = ( unsigned long ) V_2 ;
V_2 -> V_28 . V_30 = V_31 ;
F_15 ( & V_2 -> V_32 ) ;
F_15 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_26 = 1 ;
V_2 -> V_39 = 0 ;
F_16 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ )
F_7 ( & V_2 -> V_41 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < 17 ; V_11 ++ ) {
V_2 -> V_42 [ V_11 ] = - 1 ;
V_2 -> V_43 [ V_11 ] = - 1 ;
V_2 -> V_44 [ V_11 ] = 0 ;
}
F_17 () ;
F_18 () ;
F_19 () ;
return V_8 ;
V_18:
if ( V_8 )
F_20 ( V_8 ) ;
return NULL ;
}
void F_21 ( struct V_15 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 ) ;
int V_11 ;
struct V_45 * V_46 , * V_47 ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_28 ) ;
F_24 ( V_2 , 1 ) ;
for ( V_11 = 0 ; V_11 < V_48 ; V_11 ++ ) {
struct V_49 * V_50 = V_2 -> V_50 [ V_11 ] ;
if ( V_50 ) {
if ( V_50 -> V_51 )
V_50 -> V_51 -> V_52 ( V_50 -> V_53 ) ;
F_5 ( V_50 ) ;
V_2 -> V_50 [ V_11 ] = NULL ;
}
}
F_4 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ ) {
F_25 (p, q, &ieee->ibss_mac_hash[i]) {
F_5 ( F_26 ( V_46 , struct V_54 , V_14 ) ) ;
F_27 ( V_46 ) ;
}
}
F_20 ( V_8 ) ;
}
