void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned long * V_4 ,
unsigned long * V_5 )
{
* V_4 = 0x02200000UL ;
if ( ! ( V_3 -> V_6 & V_7 ) &&
V_2 -> V_8 . V_9 != V_10
) {
V_2 -> V_11 = V_12 ;
* V_5 = 0x80000000UL ;
}
else {
V_2 -> V_11 = 0x02200000UL ;
if ( ( V_2 -> V_6 & V_13 ) ==
V_14
) {
V_2 -> V_6 &= ~ V_13 ;
V_2 -> V_6 |= V_15 ;
}
}
}
unsigned long F_2 ( struct V_16 * V_17 , unsigned long V_18 , unsigned long V_19 ,
unsigned long V_20 , unsigned long V_6 )
{
struct V_21 * V_22 ;
unsigned long V_23 ;
if ( V_19 > V_24 )
return - V_25 ;
if ( V_6 & V_26 )
return V_18 ;
if ( V_18 ) {
V_18 = F_3 ( V_18 ) ;
V_22 = F_4 ( V_27 -> V_28 , V_18 ) ;
if ( V_24 - V_19 >= V_18 &&
( ! V_22 || V_18 + V_19 <= V_22 -> V_29 ) )
goto V_30;
}
V_18 = V_12 ;
V_23 = ( V_27 -> V_28 -> V_4 - 0x00200000 ) ;
if ( V_18 + V_19 <= V_23 ) {
V_23 -= V_19 ;
if ( V_18 <= V_23 ) {
V_22 = F_4 ( V_27 -> V_28 , V_12 ) ;
for (; V_22 ; V_22 = V_22 -> V_31 ) {
if ( V_18 > V_23 )
break;
if ( V_18 + V_19 <= V_22 -> V_29 )
goto V_30;
V_18 = V_22 -> V_32 ;
}
}
}
V_18 = F_3 ( 0x80000000 ) ;
V_23 = V_24 - V_19 ;
if ( V_18 <= V_23 ) {
V_22 = F_4 ( V_27 -> V_28 , V_18 ) ;
for (; V_22 ; V_22 = V_22 -> V_31 ) {
if ( V_18 > V_23 )
break;
if ( V_18 + V_19 <= V_22 -> V_29 )
goto V_30;
V_18 = V_22 -> V_32 ;
}
if ( ! V_22 && V_18 <= V_23 )
goto V_30;
}
#if 0
printk("[area] l=%lx (ENOMEM) f='%s'\n",
len, filp ? filp->f_path.dentry->d_name.name : "");
#endif
return - V_25 ;
V_30:
#if 0
printk("[area] l=%lx ad=%lx f='%s'\n",
len, addr, filp ? filp->f_path.dentry->d_name.name : "");
#endif
return V_18 ;
}
