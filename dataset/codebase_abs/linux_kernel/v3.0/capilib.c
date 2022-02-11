static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = 0 ;
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
V_2 -> V_8 = & V_2 -> V_7 [ 0 ] ;
for ( V_3 = 1 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_10 = V_2 -> V_8 ;
V_2 -> V_8 = & V_2 -> V_7 [ V_3 ] ;
}
}
static inline int F_2 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_12 * V_13 ;
if ( ( V_13 = V_2 -> V_8 ) == NULL )
return 0 ;
V_2 -> V_8 = V_13 -> V_10 ;
V_13 -> V_11 = V_11 ;
V_13 -> V_10 = NULL ;
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_10 = V_13 ;
V_2 -> V_5 = V_13 ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_13 ;
V_2 -> V_6 ++ ;
return 1 ;
}
static inline int F_3 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_12 * * V_14 ;
for ( V_14 = & V_2 -> V_4 ; * V_14 ; V_14 = & ( * V_14 ) -> V_10 ) {
if ( ( * V_14 ) -> V_11 == V_11 ) {
struct V_12 * V_13 = * V_14 ;
* V_14 = V_13 -> V_10 ;
if ( V_13 == V_2 -> V_5 )
V_2 -> V_5 = NULL ;
V_13 -> V_10 = V_2 -> V_8 ;
V_2 -> V_8 = V_13 ;
V_2 -> V_6 -- ;
return 1 ;
}
}
return 0 ;
}
void F_4 ( struct V_15 * V_16 , T_2 V_17 , T_3 V_18 , T_3 V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 ) {
F_6 ( V_20 L_1 ) ;
return;
}
if ( V_9 > V_21 ) {
F_6 ( V_22 L_2 ,
V_9 ) ;
V_9 = V_21 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_9 = V_9 ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_23 , V_16 ) ;
F_8 ( L_3 , V_17 , V_18 ) ;
}
void F_9 ( struct V_15 * V_16 , T_2 V_17 , T_3 V_18 )
{
struct V_15 * V_24 ;
struct V_1 * V_2 ;
F_10 (l, head) {
V_2 = F_11 ( V_24 , struct V_1 , V_23 ) ;
if ( V_2 -> V_17 != V_17 )
continue;
if ( V_2 -> V_18 != V_18 )
continue;
F_6 ( V_25 L_4 , V_17 , V_18 ) ;
F_12 ( & V_2 -> V_23 ) ;
F_13 ( V_2 ) ;
return;
}
F_6 ( V_22 L_5 , V_18 ) ;
}
void F_14 ( struct V_15 * V_16 , T_2 V_17 )
{
struct V_15 * V_24 , * V_26 ;
struct V_1 * V_2 ;
F_15 (l, n, head) {
V_2 = F_11 ( V_24 , struct V_1 , V_23 ) ;
if ( V_2 -> V_17 != V_17 )
continue;
F_6 ( V_25 L_6 , V_17 , V_2 -> V_18 ) ;
F_12 ( & V_2 -> V_23 ) ;
F_13 ( V_2 ) ;
}
}
void F_16 ( struct V_15 * V_16 )
{
struct V_15 * V_24 , * V_26 ;
struct V_1 * V_2 ;
F_15 (l, n, head) {
V_2 = F_11 ( V_24 , struct V_1 , V_23 ) ;
F_6 ( V_25 L_6 , V_2 -> V_17 , V_2 -> V_18 ) ;
F_12 ( & V_2 -> V_23 ) ;
F_13 ( V_2 ) ;
}
}
T_2 F_17 ( struct V_15 * V_16 , T_2 V_17 , T_3 V_18 , T_2 V_11 )
{
struct V_15 * V_24 ;
struct V_1 * V_2 ;
F_10 (l, head) {
V_2 = F_11 ( V_24 , struct V_1 , V_23 ) ;
if ( V_2 -> V_17 != V_17 )
continue;
if ( V_2 -> V_18 != V_18 )
continue;
if ( F_2 ( V_2 , V_11 ) == 0 )
return V_27 ;
return V_28 ;
}
F_6 ( V_22 L_7 , V_18 ) ;
return V_28 ;
}
void F_18 ( struct V_15 * V_16 , T_2 V_17 , T_3 V_18 , T_2 V_11 )
{
struct V_15 * V_24 ;
struct V_1 * V_2 ;
F_10 (l, head) {
V_2 = F_11 ( V_24 , struct V_1 , V_23 ) ;
if ( V_2 -> V_17 != V_17 )
continue;
if ( V_2 -> V_18 != V_18 )
continue;
if ( F_3 ( V_2 , V_11 ) == 0 ) {
F_6 ( V_22 L_8 ,
V_11 , V_18 ) ;
}
return;
}
F_6 ( V_22 L_9 , V_18 ) ;
}
