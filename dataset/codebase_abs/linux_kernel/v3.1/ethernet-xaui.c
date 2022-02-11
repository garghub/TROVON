int F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_6 -> V_8 ) ;
int V_9 = F_4 ( V_6 -> V_8 ) ;
T_1 V_10 ;
V_4 . V_11 = F_5 ( F_6 ( V_9 , V_7 ) ) ;
V_4 . V_12 . V_13 = 1 ;
F_7 ( F_6 ( V_9 , V_7 ) , V_4 . V_11 ) ;
if ( ! F_8 () ) {
V_10 = F_9 ( V_6 -> V_8 ) ;
if ( ! V_10 . V_12 . V_14 )
F_10 ( V_2 ) ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_6 -> V_8 ) ;
int V_9 = F_4 ( V_6 -> V_8 ) ;
V_4 . V_11 = F_5 ( F_6 ( V_9 , V_7 ) ) ;
V_4 . V_12 . V_13 = 0 ;
F_7 ( F_6 ( V_9 , V_7 ) , V_4 . V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_6 -> V_8 ) ;
if ( V_10 . V_11 == V_6 -> V_10 )
return;
V_10 = F_13 ( V_6 -> V_8 ) ;
V_6 -> V_10 = V_10 . V_11 ;
if ( V_10 . V_12 . V_14 ) {
if ( ! F_14 ( V_2 ) )
F_15 ( V_2 ) ;
if ( V_6 -> V_15 != - 1 )
F_16
( L_1 ,
V_2 -> V_16 , V_10 . V_12 . V_17 ,
( V_10 . V_12 . V_18 ) ? L_2 : L_3 ,
V_6 -> V_8 , V_6 -> V_15 ) ;
else
F_16
( L_4 ,
V_2 -> V_16 , V_10 . V_12 . V_17 ,
( V_10 . V_12 . V_18 ) ? L_2 : L_3 ,
V_6 -> V_8 ) ;
} else {
if ( F_14 ( V_2 ) )
F_10 ( V_2 ) ;
F_16 ( L_5 , V_2 -> V_16 ) ;
}
}
int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_19 -> V_20 ( V_2 ) ;
if ( ! F_8 () && V_6 -> V_21 == NULL )
V_6 -> V_22 = F_12 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
