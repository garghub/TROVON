T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 * V_5 )
{
* V_5 |= V_6 ;
}
void F_4 ( struct V_1 * V_2 , T_1 * V_7 ,
enum V_8 V_9 ,
enum V_8 V_10 )
{
T_1 * V_5 = V_7 + 5 ;
T_1 * V_11 = V_7 ;
struct V_12 * V_13 ;
T_2 * V_14 , * V_15 ;
enum V_8 V_16 ;
int V_17 = 0 ;
if ( V_10 == V_18 &&
( V_9 == V_19 ||
V_9 == V_20 ) ) {
V_17 = 1 ;
V_16 = V_9 ;
} else if ( ( V_10 == V_19 ||
V_10 == V_20 ) &&
V_9 == V_18 ) {
V_17 = 3 ;
V_16 = V_10 ;
} else {
* V_5 |= V_6 ;
return;
}
V_13 = & V_12 [ V_17 ] ;
if ( V_16 == V_19 )
V_14 = V_13 -> V_21 ;
else
V_14 = V_13 -> V_22 ;
V_15 = V_14 + 12 ;
for (; V_14 < V_15 ; V_14 += 2 )
* V_11 ++ = ( * ( V_14 + 1 ) << 16 ) | * V_14 ;
}
struct V_1 * F_5 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
F_6 ( & V_24 -> V_25 , L_1 ) ;
V_2 = F_7 ( & V_24 -> V_25 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_8 ( & V_24 -> V_25 , L_2 ) ;
return F_9 ( - V_27 ) ;
}
V_2 -> V_24 = V_24 ;
V_2 -> V_28 = F_10 ( V_24 , V_29 ,
L_3 ) ;
if ( V_2 -> V_28 == NULL ) {
F_8 ( & V_24 -> V_25 , L_4 ) ;
return F_9 ( - V_30 ) ;
}
V_2 -> V_4 = F_11 ( & V_24 -> V_25 , V_2 -> V_28 ) ;
if ( ! V_2 -> V_4 ) {
F_8 ( & V_24 -> V_25 , L_5 ) ;
return F_9 ( - V_27 ) ;
}
return V_2 ;
}
