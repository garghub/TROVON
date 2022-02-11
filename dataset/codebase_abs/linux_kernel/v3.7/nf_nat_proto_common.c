bool F_1 ( const struct V_1 * V_2 ,
enum V_3 V_4 ,
const union V_5 * V_6 ,
const union V_5 * V_7 )
{
T_1 V_8 ;
if ( V_4 == V_9 )
V_8 = V_2 -> V_10 . V_11 . V_12 ;
else
V_8 = V_2 -> V_13 . V_11 . V_12 ;
return F_2 ( V_8 ) >= F_2 ( V_6 -> V_12 ) &&
F_2 ( V_8 ) <= F_2 ( V_7 -> V_12 ) ;
}
void F_3 ( const struct V_14 * V_15 ,
struct V_1 * V_2 ,
const struct V_16 * V_17 ,
enum V_3 V_4 ,
const struct V_18 * V_19 ,
T_2 * V_20 )
{
unsigned int V_21 , V_6 , V_22 ;
T_1 * V_23 ;
T_3 V_24 ;
if ( V_4 == V_9 )
V_23 = & V_2 -> V_10 . V_11 . V_12 ;
else
V_23 = & V_2 -> V_13 . V_11 . V_12 ;
if ( ! ( V_17 -> V_25 & V_26 ) ) {
if ( V_4 == V_27 )
return;
if ( F_2 ( * V_23 ) < 1024 ) {
if ( F_2 ( * V_23 ) < 512 ) {
V_6 = 1 ;
V_21 = 511 - V_6 + 1 ;
} else {
V_6 = 600 ;
V_21 = 1023 - V_6 + 1 ;
}
} else {
V_6 = 1024 ;
V_21 = 65535 - 1024 + 1 ;
}
} else {
V_6 = F_2 ( V_17 -> V_28 . V_12 ) ;
V_21 = F_2 ( V_17 -> V_29 . V_12 ) - V_6 + 1 ;
}
if ( V_17 -> V_25 & V_30 )
V_24 = V_15 -> V_31 ( V_2 , V_4 == V_9
? V_2 -> V_13 . V_11 . V_12
: V_2 -> V_10 . V_11 . V_12 ) ;
else
V_24 = * V_20 ;
for ( V_22 = 0 ; ; ++ V_24 ) {
* V_23 = F_4 ( V_6 + V_24 % V_21 ) ;
if ( ++ V_22 != V_21 && F_5 ( V_2 , V_19 ) )
continue;
if ( ! ( V_17 -> V_25 & V_30 ) )
* V_20 = V_24 ;
return;
}
return;
}
int F_6 ( struct V_32 * V_33 [] ,
struct V_16 * V_17 )
{
if ( V_33 [ V_34 ] ) {
V_17 -> V_28 . V_12 = F_7 ( V_33 [ V_34 ] ) ;
V_17 -> V_29 . V_12 = V_17 -> V_28 . V_12 ;
V_17 -> V_25 |= V_26 ;
}
if ( V_33 [ V_35 ] ) {
V_17 -> V_29 . V_12 = F_7 ( V_33 [ V_35 ] ) ;
V_17 -> V_25 |= V_26 ;
}
return 0 ;
}
