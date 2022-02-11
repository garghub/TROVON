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
if ( F_16 ( V_6 ) != 0 ) {
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_6 -> V_3 ; V_21 ++ ) {
struct V_9 * V_22 ;
F_10 ( & V_2 -> V_17 ) ;
while ( ( V_22 = V_6 -> V_23 [ V_21 ] ) != NULL ) {
V_6 -> V_23 [ V_21 ] = V_22 -> V_24 ;
F_11 ( & V_2 -> V_17 ) ;
F_17 ( & V_6 -> V_25 ) ;
if ( F_18 ( & V_22 -> V_26 ) )
F_19 ( V_22 ) ;
F_19 ( V_22 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
F_11 ( & V_2 -> V_17 ) ;
}
}
if ( F_20 ( F_16 ( V_6 ) != 0 ) )
F_21 ( L_1 , F_16 ( V_6 ) ) ;
F_13 ( V_6 ) ;
}
void F_22 ( struct V_27 * V_28 , struct V_9 * V_22 ,
bool V_29 )
{
struct V_27 * V_30 = V_22 -> V_31 ;
struct V_32 * V_33 ;
V_33 = F_23 ( V_30 ) -> V_34 . V_33 ;
F_24 ( V_28 ) -> V_35 = NULL ;
F_10 ( & V_33 -> V_36 ) ;
V_33 -> V_37 -- ;
F_25 ( V_22 ) -> V_38 = false ;
if ( V_22 -> V_28 )
goto V_39;
if ( ! V_29 || V_30 -> V_40 != V_41 ) {
F_11 ( & V_33 -> V_36 ) ;
F_19 ( V_22 ) ;
return;
}
V_22 -> V_26 . V_42 = V_43 + 60 * V_44 ;
if ( V_33 -> V_45 == NULL )
V_33 -> V_45 = V_22 ;
else
V_33 -> V_46 -> V_24 = V_22 ;
V_22 -> V_24 = NULL ;
V_33 -> V_46 = V_22 ;
V_33 -> V_37 ++ ;
V_39:
F_11 ( & V_33 -> V_36 ) ;
}
