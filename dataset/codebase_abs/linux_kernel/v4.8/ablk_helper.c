int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_7 = & V_6 -> V_8 -> V_9 ;
int V_10 ;
F_3 ( V_7 , V_11 ) ;
F_4 ( V_7 , F_5 ( V_2 )
& V_11 ) ;
V_10 = F_6 ( V_7 , V_3 , V_4 ) ;
F_4 ( V_2 , F_5 ( V_7 )
& V_12 ) ;
return V_10 ;
}
int F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 V_16 ;
V_16 . V_2 = F_9 ( V_6 -> V_8 ) ;
V_16 . V_17 = V_14 -> V_17 ;
V_16 . V_18 = 0 ;
return F_10 ( V_16 . V_2 ) -> F_11 (
& V_16 , V_14 -> V_19 , V_14 -> V_20 , V_14 -> V_21 ) ;
}
int F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_13 () ||
( F_14 () && F_15 ( V_6 -> V_8 ) ) ) {
struct V_13 * V_22 =
F_16 ( V_14 ) ;
* V_22 = * V_14 ;
F_17 ( V_22 , & V_6 -> V_8 -> V_9 ) ;
return F_18 ( V_22 ) ;
} else {
return F_7 ( V_14 ) ;
}
}
int F_19 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_13 () ||
( F_14 () && F_15 ( V_6 -> V_8 ) ) ) {
struct V_13 * V_22 =
F_16 ( V_14 ) ;
* V_22 = * V_14 ;
F_17 ( V_22 , & V_6 -> V_8 -> V_9 ) ;
return F_20 ( V_22 ) ;
} else {
struct V_15 V_16 ;
V_16 . V_2 = F_9 ( V_6 -> V_8 ) ;
V_16 . V_17 = V_14 -> V_17 ;
V_16 . V_18 = 0 ;
return F_10 ( V_16 . V_2 ) -> F_21 (
& V_16 , V_14 -> V_19 , V_14 -> V_20 , V_14 -> V_21 ) ;
}
}
void F_22 ( struct V_23 * V_2 )
{
struct V_5 * V_6 = F_23 ( V_2 ) ;
F_24 ( V_6 -> V_8 ) ;
}
int F_25 ( struct V_23 * V_2 , const char * V_24 )
{
struct V_5 * V_6 = F_23 ( V_2 ) ;
struct V_25 * V_8 ;
V_8 = F_26 ( V_24 , V_26 ,
V_26 ) ;
if ( F_27 ( V_8 ) )
return F_28 ( V_8 ) ;
V_6 -> V_8 = V_8 ;
V_2 -> V_27 . V_28 = sizeof( struct V_13 ) +
F_29 ( & V_8 -> V_9 ) ;
return 0 ;
}
int F_30 ( struct V_23 * V_2 )
{
char V_24 [ V_29 ] ;
snprintf ( V_24 , sizeof( V_24 ) , L_1 ,
F_31 ( V_2 ) ) ;
return F_25 ( V_2 , V_24 ) ;
}
