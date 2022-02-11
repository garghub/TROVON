bool F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 ,
V_5 ) ;
T_1 V_6 ;
if ( F_3 ( V_2 -> V_7 . V_8 , V_3 , NULL ,
NULL , NULL , & V_6 ) ) {
struct V_9 * V_10 =
(struct V_9 * ) ( V_2 -> V_7 . V_8 -> V_11 +
V_6 ) ;
if ( F_4 ( V_10 -> V_12 ) &
V_13 )
return true ;
}
return false ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 ,
V_5 ) ;
T_1 V_6 ;
if ( F_3 ( V_2 -> V_7 . V_8 , V_3 , NULL ,
NULL , NULL , & V_6 ) ) {
struct V_9 * V_10 =
(struct V_9 * ) ( V_2 -> V_7 . V_8 -> V_11 +
V_6 ) ;
V_2 -> V_14 =
F_4 ( V_10 -> V_15 ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_2 -> V_18 [ V_16 ] = F_7 ( V_2 -> V_14 + V_16 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
int V_16 ;
V_2 -> V_18 [ 7 ] &= ~ V_19 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_9 ( V_2 -> V_14 + V_16 , V_2 -> V_18 [ V_16 ] ) ;
}
void F_10 ( struct V_1 * V_2 ,
bool V_20 )
{
T_2 V_21 = F_7 ( V_2 -> V_14 + 3 ) ;
if ( V_20 )
V_21 |= V_22 ;
else
V_21 &= ~ V_22 ;
F_9 ( V_2 -> V_14 + 3 , V_21 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_23 = V_2 -> V_7 . V_8 ;
int V_3 = F_2 ( V_4 ,
V_24 ) ;
T_1 V_6 ;
int V_25 = 0 ;
if ( F_3 ( V_23 , V_3 , NULL , NULL , NULL , & V_6 ) ) {
struct V_26 * V_27 =
(struct V_26 * ) ( V_23 -> V_11 + V_6 ) ;
F_12 ( L_1 ,
F_4 ( V_27 -> V_28 ) ,
F_13 ( V_27 -> V_29 ) ,
F_13 ( V_27 -> V_30 ) ) ;
V_25 = F_13 ( V_27 -> V_30 ) * 1024 ;
}
V_23 -> V_31 = 0 ;
if ( V_25 == 0 )
V_25 = 20 * 1024 ;
V_23 -> V_32 = F_14 ( V_25 , V_33 ) ;
if ( ! V_23 -> V_32 )
return - V_34 ;
V_23 -> V_31 = V_25 ;
return 0 ;
}
