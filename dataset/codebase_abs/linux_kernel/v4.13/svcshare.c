static inline int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return V_2 -> V_5 . V_6 == V_4 -> V_6
&& ! memcmp ( V_2 -> V_5 . V_7 , V_4 -> V_7 , V_4 -> V_6 ) ;
}
T_1
F_2 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_13 -> V_14 . V_4 ;
T_2 * V_15 ;
for ( V_2 = V_11 -> V_16 ; V_2 ; V_2 = V_2 -> V_17 ) {
if ( V_2 -> V_18 == V_9 && F_1 ( V_2 , V_4 ) )
goto V_19;
if ( ( V_13 -> V_20 & V_2 -> V_21 )
|| ( V_13 -> V_22 & V_2 -> V_23 ) )
return V_24 ;
}
V_2 = F_3 ( sizeof( * V_2 ) + V_4 -> V_6 ,
V_25 ) ;
if ( V_2 == NULL )
return V_26 ;
V_15 = ( T_2 * ) ( V_2 + 1 ) ;
memcpy ( V_15 , V_4 -> V_7 , V_4 -> V_6 ) ;
V_2 -> V_27 = V_11 ;
V_2 -> V_18 = V_9 ;
V_2 -> V_5 . V_7 = V_15 ;
V_2 -> V_5 . V_6 = V_4 -> V_6 ;
V_2 -> V_17 = V_11 -> V_16 ;
V_11 -> V_16 = V_2 ;
V_19:
V_2 -> V_23 = V_13 -> V_20 ;
V_2 -> V_21 = V_13 -> V_22 ;
return V_28 ;
}
T_1
F_4 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 , * * V_29 ;
struct V_3 * V_4 = & V_13 -> V_14 . V_4 ;
for ( V_29 = & V_11 -> V_16 ; ( V_2 = * V_29 ) != NULL ;
V_29 = & V_2 -> V_17 ) {
if ( V_2 -> V_18 == V_9 && F_1 ( V_2 , V_4 ) ) {
* V_29 = V_2 -> V_17 ;
F_5 ( V_2 ) ;
return V_28 ;
}
}
return V_28 ;
}
void F_6 ( struct V_8 * V_9 , struct V_10 * V_11 ,
T_3 V_30 )
{
struct V_1 * V_2 , * * V_29 ;
V_29 = & V_11 -> V_16 ;
while ( ( V_2 = * V_29 ) != NULL ) {
if ( V_30 ( V_2 -> V_18 , V_9 ) ) {
* V_29 = V_2 -> V_17 ;
F_5 ( V_2 ) ;
continue;
}
V_29 = & V_2 -> V_17 ;
}
}
