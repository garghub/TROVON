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
struct V_23 V_24 ;
if ( V_19 > V_25 )
return - V_26 ;
if ( V_6 & V_27 )
return V_18 ;
if ( V_18 ) {
V_18 = F_3 ( V_18 ) ;
V_22 = F_4 ( V_28 -> V_29 , V_18 ) ;
if ( V_25 - V_19 >= V_18 &&
( ! V_22 || V_18 + V_19 <= F_5 ( V_22 ) ) )
goto V_30;
}
V_24 . V_6 = 0 ;
V_24 . V_31 = V_19 ;
V_24 . V_32 = V_12 ;
V_24 . V_33 = ( V_28 -> V_29 -> V_4 - 0x00200000 ) ;
V_24 . V_34 = 0 ;
V_24 . V_35 = 0 ;
V_18 = F_6 ( & V_24 ) ;
if ( ! ( V_18 & ~ V_36 ) )
goto V_30;
F_7 ( V_18 != - V_26 ) ;
V_24 . V_32 = F_3 ( 0x80000000 ) ;
V_24 . V_33 = V_25 ;
V_18 = F_6 ( & V_24 ) ;
if ( ! ( V_18 & ~ V_36 ) )
goto V_30;
F_7 ( V_18 != - V_26 ) ;
#if 0
printk("[area] l=%lx (ENOMEM) f='%s'\n",
len, filp ? filp->f_path.dentry->d_name.name : "");
#endif
return - V_26 ;
V_30:
#if 0
printk("[area] l=%lx ad=%lx f='%s'\n",
len, addr, filp ? filp->f_path.dentry->d_name.name : "");
#endif
return V_18 ;
}
