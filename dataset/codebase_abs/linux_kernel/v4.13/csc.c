void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
#define F_2 ( T_1 ) dev_dbg(dev, "%-35s %08x\n", #r, \
ioread32(csc->base + CSC_##r))
F_3 ( V_4 , L_1 , & V_2 -> V_6 -> V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
#undef F_2
}
void F_4 ( struct V_1 * V_2 , T_2 * V_14 )
{
* V_14 |= V_15 ;
}
void F_5 ( struct V_1 * V_2 , T_2 * V_16 ,
enum V_17 V_18 ,
enum V_17 V_19 )
{
T_2 * V_14 = V_16 + 5 ;
T_2 * V_20 = V_16 ;
struct V_21 * V_22 ;
T_3 * V_23 , * V_24 ;
enum V_17 V_25 ;
int V_26 = 0 ;
if ( V_19 == V_27 &&
( V_18 == V_28 ||
V_18 == V_29 ) ) {
V_26 = 1 ;
V_25 = V_18 ;
} else if ( ( V_19 == V_28 ||
V_19 == V_29 ) &&
V_18 == V_27 ) {
V_26 = 3 ;
V_25 = V_19 ;
} else {
* V_14 |= V_15 ;
return;
}
V_22 = & V_21 [ V_26 ] ;
if ( V_25 == V_28 )
V_23 = V_22 -> V_30 ;
else
V_23 = V_22 -> V_31 ;
V_24 = V_23 + 12 ;
for (; V_23 < V_24 ; V_23 += 2 )
* V_20 ++ = ( * ( V_23 + 1 ) << 16 ) | * V_23 ;
}
struct V_1 * F_6 ( struct V_32 * V_5 , const char * V_33 )
{
struct V_1 * V_2 ;
F_3 ( & V_5 -> V_4 , L_2 ) ;
V_2 = F_7 ( & V_5 -> V_4 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
F_8 ( & V_5 -> V_4 , L_3 ) ;
return F_9 ( - V_35 ) ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = F_10 ( V_5 , V_36 ,
V_33 ) ;
if ( V_2 -> V_6 == NULL ) {
F_8 ( & V_5 -> V_4 , L_4 ,
V_33 ) ;
return F_9 ( - V_37 ) ;
}
V_2 -> V_38 = F_11 ( & V_5 -> V_4 , V_2 -> V_6 ) ;
if ( F_12 ( V_2 -> V_38 ) ) {
F_8 ( & V_5 -> V_4 , L_5 ) ;
return F_13 ( V_2 -> V_38 ) ;
}
return V_2 ;
}
