void * F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 != V_4 ) ;
F_2 ( V_2 -> type != V_5 ) ;
if ( F_3 ( V_2 ) ) {
return NULL ;
} else {
#ifdef F_4
struct V_6 * V_7 =
(struct V_6 * ) ( V_2 -> V_8 . V_9 + V_2 -> V_10 * V_2 -> V_11 ) ;
#ifdef F_5
F_2 ( V_7 -> V_3 != F_6 ( ~ V_12 ) ) ;
V_7 -> V_3 = F_7 ( V_12 ) ;
#endif
return V_7 ;
#else
return V_2 -> V_8 . V_9 + V_2 -> V_10 * V_2 -> V_11 ;
#endif
}
}
void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 != V_4 ) ;
F_2 ( V_2 -> type != V_5 ) ;
if ( ! F_3 ( V_2 ) ) {
V_2 -> V_10 = ( V_2 -> V_10 + 1 ) % V_2 -> V_13 ;
V_2 -> V_14 ++ ;
F_9 ( ( V_15 V_16 ) F_10 ( V_2 -> V_10 ) , & V_2 -> V_17 -> V_18 ) ;
}
}
void * F_11 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 != V_4 ) ;
F_2 ( V_2 -> type != V_19 ) ;
if ( F_12 ( V_2 ) ) {
return NULL ;
} else {
#ifdef F_4
struct V_6 * V_7 = (struct V_6 * )
( V_2 -> V_8 . V_9 + V_2 -> V_10 * V_2 -> V_11 ) ;
#ifdef F_5
F_2 ( V_7 -> V_3 != F_6 ( V_12 ) ) ;
#endif
return V_7 ;
#else
return V_2 -> V_8 . V_9 + V_2 -> V_10 * V_2 -> V_11 ;
#endif
}
}
void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 != V_4 ) ;
F_2 ( V_2 -> type != V_19 ) ;
if ( ! F_12 ( V_2 ) ) {
#ifdef F_5
{
struct V_6 T_1 * V_7 = (struct V_6 T_1 * )
( V_2 -> V_8 . V_20 + V_2 -> V_10 * V_2 -> V_11 ) ;
F_14 ( F_7 ( ~ V_12 ) , & V_7 -> V_3 ) ;
}
#endif
V_2 -> V_10 = ( V_2 -> V_10 + 1 ) % V_2 -> V_13 ;
F_9 ( ( V_15 V_16 ) F_10 ( V_2 -> V_10 ) , & V_2 -> V_17 -> V_18 ) ;
}
}
void F_15 ( struct V_1 * V_2 , T_2 V_21 )
{
F_2 ( V_2 -> V_3 != V_4 ) ;
F_2 ( V_2 -> type != V_5 ) ;
while ( V_21 -- ) {
F_2 ( F_12 ( V_2 ) ) ;
* V_2 -> V_18 = F_10 ( ( F_16 ( * V_2 -> V_18 ) + 1 ) % V_2 -> V_13 ) ;
}
}
void F_17 ( struct V_1 * V_2 , T_2 V_22 , T_2 V_13 , T_2 V_11 ,
T_3 T_1 * V_23 , V_16 T_1 * V_17 , T_2 type )
{
F_2 ( ! V_2 -> V_18 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_8 . V_20 = V_23 ;
V_2 -> V_17 = (struct V_24 T_1 * ) V_17 ;
V_2 -> V_3 = V_4 ;
V_2 -> type = type ;
V_2 -> V_10 = 0 ;
V_2 -> V_14 = 0 ;
return;
}
void F_18 ( struct V_1 * V_2 , T_2 V_22 , T_2 V_13 , T_2 V_11 ,
T_3 * V_23 , V_16 T_1 * V_17 , T_2 type )
{
F_2 ( ! V_2 -> V_18 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_8 . V_9 = V_23 ;
V_2 -> V_17 = (struct V_24 T_1 * ) V_17 ;
V_2 -> V_3 = V_4 ;
V_2 -> type = type ;
V_2 -> V_10 = 0 ;
V_2 -> V_14 = 0 ;
return;
}
