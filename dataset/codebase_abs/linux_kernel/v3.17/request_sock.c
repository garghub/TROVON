int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 = sizeof( struct V_5 ) ;
struct V_5 * V_6 = NULL ;
V_3 = F_2 ( V_7 , V_3 , V_8 ) ;
V_3 = F_3 ( V_7 , V_3 , 8 ) ;
V_3 = F_4 ( V_3 + 1 ) ;
V_4 += V_3 * sizeof( struct V_9 * ) ;
if ( V_4 <= ( V_10 << V_11 ) )
V_6 = F_5 ( V_4 , V_12 |
V_13 |
V_14 ) ;
if ( ! V_6 )
V_6 = F_6 ( V_4 ) ;
if ( ! V_6 )
return - V_15 ;
F_7 ( & V_6 -> V_16 , sizeof( V_6 -> V_16 ) ) ;
F_8 ( & V_2 -> V_17 ) ;
V_2 -> V_18 = NULL ;
V_6 -> V_3 = V_3 ;
V_6 -> V_19 = F_9 ( V_3 ) ;
F_10 ( & V_2 -> V_17 ) ;
V_2 -> V_20 = V_6 ;
F_11 ( & V_2 -> V_17 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_20 ) ;
}
static inline struct V_5 * F_14 (
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_10 ( & V_2 -> V_17 ) ;
V_6 = V_2 -> V_20 ;
V_2 -> V_20 = NULL ;
F_11 ( & V_2 -> V_17 ) ;
return V_6 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
if ( V_6 -> V_21 != 0 ) {
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_3 ; V_22 ++ ) {
struct V_9 * V_23 ;
while ( ( V_23 = V_6 -> V_24 [ V_22 ] ) != NULL ) {
V_6 -> V_24 [ V_22 ] = V_23 -> V_25 ;
V_6 -> V_21 -- ;
F_16 ( V_23 ) ;
}
}
}
F_17 ( V_6 -> V_21 != 0 ) ;
F_13 ( V_6 ) ;
}
void F_18 ( struct V_26 * V_27 , struct V_9 * V_23 ,
bool V_28 )
{
struct V_26 * V_29 = F_19 ( V_23 ) -> V_30 ;
struct V_31 * V_32 =
F_20 ( V_29 ) -> V_33 . V_32 ;
F_21 ( V_27 ) -> V_34 = NULL ;
F_22 ( & V_32 -> V_35 ) ;
V_32 -> V_21 -- ;
F_19 ( V_23 ) -> V_30 = NULL ;
if ( V_23 -> V_27 )
goto V_36;
if ( ! V_28 || V_29 -> V_37 != V_38 ) {
F_23 ( & V_32 -> V_35 ) ;
F_24 ( V_29 ) ;
F_16 ( V_23 ) ;
return;
}
V_23 -> V_39 = V_40 + 60 * V_41 ;
if ( V_32 -> V_42 == NULL )
V_32 -> V_42 = V_23 ;
else
V_32 -> V_43 -> V_25 = V_23 ;
V_23 -> V_25 = NULL ;
V_32 -> V_43 = V_23 ;
V_32 -> V_21 ++ ;
V_36:
F_23 ( & V_32 -> V_35 ) ;
F_24 ( V_29 ) ;
}
