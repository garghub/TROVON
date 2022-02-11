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
void F_3 ( struct V_1 * V_2 ,
const struct V_14 * V_15 ,
enum V_3 V_4 ,
const struct V_16 * V_17 ,
T_2 * V_18 )
{
unsigned int V_19 , V_6 , V_20 ;
T_1 * V_21 ;
T_2 V_22 ;
if ( V_4 == V_9 )
V_21 = & V_2 -> V_10 . V_11 . V_12 ;
else
V_21 = & V_2 -> V_13 . V_11 . V_12 ;
if ( ! ( V_15 -> V_23 & V_24 ) ) {
if ( V_4 == V_25 )
return;
if ( F_2 ( * V_21 ) < 1024 ) {
if ( F_2 ( * V_21 ) < 512 ) {
V_6 = 1 ;
V_19 = 511 - V_6 + 1 ;
} else {
V_6 = 600 ;
V_19 = 1023 - V_6 + 1 ;
}
} else {
V_6 = 1024 ;
V_19 = 65535 - 1024 + 1 ;
}
} else {
V_6 = F_2 ( V_15 -> V_6 . V_12 ) ;
V_19 = F_2 ( V_15 -> V_7 . V_12 ) - V_6 + 1 ;
}
if ( V_15 -> V_23 & V_26 )
V_22 = F_4 ( V_2 -> V_10 . V_27 . V_28 , V_2 -> V_13 . V_27 . V_28 ,
V_4 == V_9
? V_2 -> V_13 . V_11 . V_12
: V_2 -> V_10 . V_11 . V_12 ) ;
else
V_22 = * V_18 ;
for ( V_20 = 0 ; ; ++ V_22 ) {
* V_21 = F_5 ( V_6 + V_22 % V_19 ) ;
if ( ++ V_20 != V_19 && F_6 ( V_2 , V_17 ) )
continue;
if ( ! ( V_15 -> V_23 & V_26 ) )
* V_18 = V_22 ;
return;
}
return;
}
int F_7 ( struct V_29 * V_30 ,
const struct V_14 * V_15 )
{
F_8 ( V_30 , V_31 , V_15 -> V_6 . V_12 ) ;
F_8 ( V_30 , V_32 , V_15 -> V_7 . V_12 ) ;
return 0 ;
V_33:
return - 1 ;
}
int F_9 ( struct V_34 * V_35 [] ,
struct V_14 * V_15 )
{
if ( V_35 [ V_31 ] ) {
V_15 -> V_6 . V_12 = F_10 ( V_35 [ V_31 ] ) ;
V_15 -> V_7 . V_12 = V_15 -> V_6 . V_36 . V_8 ;
V_15 -> V_23 |= V_24 ;
}
if ( V_35 [ V_32 ] ) {
V_15 -> V_7 . V_12 = F_10 ( V_35 [ V_32 ] ) ;
V_15 -> V_23 |= V_24 ;
}
return 0 ;
}
