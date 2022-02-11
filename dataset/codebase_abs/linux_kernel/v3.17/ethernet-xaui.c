static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 ) ;
if ( V_5 . V_7 == V_4 -> V_5 )
return;
V_5 = F_4 ( V_4 -> V_6 ) ;
V_4 -> V_5 = V_5 . V_7 ;
if ( V_5 . V_8 . V_9 ) {
if ( ! F_5 ( V_2 ) )
F_6 ( V_2 ) ;
if ( V_4 -> V_10 != - 1 )
F_7
( L_1 ,
V_2 -> V_11 , V_5 . V_8 . V_12 ,
( V_5 . V_8 . V_13 ) ? L_2 : L_3 ,
V_4 -> V_6 , V_4 -> V_10 ) ;
else
F_7
( L_4 ,
V_2 -> V_11 , V_5 . V_8 . V_12 ,
( V_5 . V_8 . V_13 ) ? L_2 : L_3 ,
V_4 -> V_6 ) ;
} else {
if ( F_5 ( V_2 ) )
F_8 ( V_2 ) ;
F_7 ( L_5 , V_2 -> V_11 ) ;
}
}
int F_9 ( struct V_1 * V_2 )
{
union V_14 V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 = F_10 ( V_4 -> V_6 ) ;
int V_17 = F_11 ( V_4 -> V_6 ) ;
T_1 V_5 ;
int V_18 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_15 . V_7 = F_13 ( F_14 ( V_17 , V_16 ) ) ;
V_15 . V_8 . V_19 = 1 ;
F_15 ( F_14 ( V_17 , V_16 ) , V_15 . V_7 ) ;
if ( F_16 () )
return 0 ;
if ( V_4 -> V_20 ) {
int V_21 = F_17 ( V_4 -> V_20 ) ;
if ( V_21 == 0 && V_4 -> V_20 -> V_22 == 0 )
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
} else {
V_5 = F_3 ( V_4 -> V_6 ) ;
if ( ! V_5 . V_8 . V_9 )
F_8 ( V_2 ) ;
V_4 -> V_23 = F_1 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
union V_14 V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 = F_10 ( V_4 -> V_6 ) ;
int V_17 = F_11 ( V_4 -> V_6 ) ;
V_15 . V_7 = F_13 ( F_14 ( V_17 , V_16 ) ) ;
V_15 . V_8 . V_19 = 0 ;
F_15 ( F_14 ( V_17 , V_16 ) , V_15 . V_7 ) ;
return F_20 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_2 ) ;
V_2 -> V_24 -> V_25 ( V_2 ) ;
if ( ! F_16 () && V_4 -> V_20 == NULL )
V_4 -> V_23 = F_1 ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
