void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
#define F_2 ( T_1 ) dev_dbg(dev, "%-35s %08x\n", #r, \
ioread32(csc->base + CSC_##r))
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
#undef F_2
}
void F_3 ( struct V_1 * V_2 , T_2 * V_12 )
{
* V_12 |= V_13 ;
}
void F_4 ( struct V_1 * V_2 , T_2 * V_14 ,
enum V_15 V_16 ,
enum V_15 V_17 )
{
T_2 * V_12 = V_14 + 5 ;
T_2 * V_18 = V_14 ;
struct V_19 * V_20 ;
T_3 * V_21 , * V_22 ;
enum V_15 V_23 ;
int V_24 = 0 ;
if ( V_17 == V_25 &&
( V_16 == V_26 ||
V_16 == V_27 ) ) {
V_24 = 1 ;
V_23 = V_16 ;
} else if ( ( V_17 == V_26 ||
V_17 == V_27 ) &&
V_16 == V_25 ) {
V_24 = 3 ;
V_23 = V_17 ;
} else {
* V_12 |= V_13 ;
return;
}
V_20 = & V_19 [ V_24 ] ;
if ( V_23 == V_26 )
V_21 = V_20 -> V_28 ;
else
V_21 = V_20 -> V_29 ;
V_22 = V_21 + 12 ;
for (; V_21 < V_22 ; V_21 += 2 )
* V_18 ++ = ( * ( V_21 + 1 ) << 16 ) | * V_21 ;
}
struct V_1 * F_5 ( struct V_30 * V_5 )
{
struct V_1 * V_2 ;
F_6 ( & V_5 -> V_4 , L_1 ) ;
V_2 = F_7 ( & V_5 -> V_4 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_8 ( & V_5 -> V_4 , L_2 ) ;
return F_9 ( - V_32 ) ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_33 = F_10 ( V_5 , V_34 ,
L_3 ) ;
if ( V_2 -> V_33 == NULL ) {
F_8 ( & V_5 -> V_4 , L_4 ) ;
return F_9 ( - V_35 ) ;
}
V_2 -> V_36 = F_11 ( & V_5 -> V_4 , V_2 -> V_33 ) ;
if ( F_12 ( V_2 -> V_36 ) ) {
F_8 ( & V_5 -> V_4 , L_5 ) ;
return F_13 ( V_2 -> V_36 ) ;
}
return V_2 ;
}
