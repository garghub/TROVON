int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 * 2 + F_2 ( V_2 ) -> V_4 ;
}
void F_3 ( struct V_1 * V_2 , char * V_5 , struct V_6 * V_7 ,
int V_8 , bool V_9 )
{
struct V_10 * V_11 ;
int V_12 = F_4 ( V_2 ) + F_5 ( V_2 ) ;
int V_13 = F_6 ( V_2 ) ;
memcpy ( V_5 , V_2 -> V_14 , V_12 ) ;
if ( ! V_7 -> V_15 ) {
struct V_16 * V_17 = ( void * ) ( V_5 + V_13 ) ;
V_17 -> V_18 = F_7 ( V_7 -> V_19 ) ;
V_17 -> V_20 = F_7 ( V_8 + V_12 - V_13 ) ;
V_7 -> V_19 ++ ;
} else {
struct V_21 * V_17 = ( void * ) ( V_5 + V_13 ) ;
V_17 -> V_22 = F_7 ( V_8 + F_5 ( V_2 ) ) ;
}
V_11 = (struct V_10 * ) ( V_5 + F_4 ( V_2 ) ) ;
F_8 ( V_7 -> V_23 , & V_11 -> V_24 ) ;
if ( ! V_9 ) {
V_11 -> V_25 = 0 ;
V_11 -> V_26 = 0 ;
V_11 -> V_27 = 0 ;
}
}
void F_9 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_8 )
{
V_7 -> V_23 += V_8 ;
V_7 -> V_8 -= V_8 ;
V_7 -> V_14 += V_8 ;
if ( ( V_7 -> V_8 == 0 ) &&
( V_7 -> V_28 < F_2 ( V_2 ) -> V_4 ) ) {
T_1 * V_29 = & F_2 ( V_2 ) -> V_30 [ V_7 -> V_28 ] ;
V_7 -> V_8 = V_29 -> V_8 ;
V_7 -> V_14 = F_10 ( V_29 -> V_31 . V_32 ) + V_29 -> V_33 ;
V_7 -> V_28 ++ ;
}
}
void F_11 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_12 = F_4 ( V_2 ) + F_5 ( V_2 ) ;
V_7 -> V_19 = F_12 ( F_13 ( V_2 ) -> V_18 ) ;
V_7 -> V_23 = F_14 ( F_15 ( V_2 ) -> V_24 ) ;
V_7 -> V_28 = 0 ;
V_7 -> V_15 = F_16 ( V_2 ) == F_7 ( V_34 ) ;
V_7 -> V_8 = F_17 ( V_2 ) - V_12 ;
V_7 -> V_14 = V_2 -> V_14 + V_12 ;
if ( ( V_7 -> V_8 == 0 ) &&
( V_7 -> V_28 < F_2 ( V_2 ) -> V_4 ) ) {
T_1 * V_29 = & F_2 ( V_2 ) -> V_30 [ V_7 -> V_28 ] ;
V_7 -> V_8 = V_29 -> V_8 ;
V_7 -> V_14 = F_10 ( V_29 -> V_31 . V_32 ) + V_29 -> V_33 ;
V_7 -> V_28 ++ ;
}
}
