int T_1 F_1 ( unsigned long V_1 ,
unsigned long V_2 ,
unsigned long V_3 )
{
int V_4 = F_2 ( V_1 , V_1 + V_2 , V_3 ,
F_3 ( V_5 ) ,
V_6 , V_7 ) ;
if ( V_4 < 0 ) {
int V_8 = F_4 ( V_1 , V_1 + V_2 ,
V_6 ,
V_7 ) ;
F_5 ( V_8 && ( V_8 != - V_9 ) ) ;
}
return V_4 ;
}
void F_6 ( unsigned long V_1 ,
unsigned long V_2 )
{
int V_4 = F_4 ( V_1 , V_1 + V_2 ,
V_6 ,
V_7 ) ;
F_5 ( ( V_4 < 0 ) && ( V_4 != - V_9 ) ) ;
F_7 ( V_4 == - V_9 ) ;
}
int F_8 ( unsigned long V_10 , unsigned long V_11 , unsigned long V_12 )
{
T_2 * V_13 ;
T_3 * V_14 ;
T_4 * V_15 ;
T_5 * V_16 ;
F_9 ( V_17 > V_18 ) ;
if ( F_10 () ) {
V_13 = F_11 ( V_10 ) ;
V_14 = F_12 ( & V_19 , V_13 , V_10 ) ;
if ( ! V_14 )
return - V_20 ;
V_15 = F_13 ( & V_19 , V_14 , V_10 ) ;
if ( ! V_15 )
return - V_20 ;
V_16 = F_14 ( V_15 , V_10 ) ;
if ( ! V_16 )
return - V_20 ;
F_15 ( & V_19 , V_10 , V_16 , F_16 ( V_11 >> V_21 ,
F_17 ( V_12 ) ) ) ;
} else {
if ( F_2 ( V_10 , V_10 + V_22 , V_11 , V_12 ,
V_23 , V_7 ) ) {
F_18 ( V_24 L_1
L_2 , V_11 ) ;
return - V_20 ;
}
}
F_19 () ;
return 0 ;
}
unsigned long F_20 ( struct V_25 * V_26 , unsigned long V_27 ,
T_4 * V_15 , unsigned long V_28 ,
unsigned long V_29 )
{
T_6 V_30 , V_31 ;
unsigned long V_32 ;
#ifdef F_21
F_7 ( ! F_22 ( * V_15 ) ) ;
F_23 ( & V_26 -> V_33 ) ;
#endif
__asm__ __volatile__(
"1: ldarx %0,0,%3\n\
and. %1,%0,%6\n\
bne- 1b \n\
andc %1,%0,%4 \n\
or %1,%1,%7\n\
stdcx. %1,0,%3 \n\
bne- 1b"
: "=&r" (old_be), "=&r" (tmp), "=m" (*pmdp)
: "r" (pmdp), "r" (cpu_to_be64(clr)), "m" (*pmdp),
"r" (cpu_to_be64(H_PAGE_BUSY)), "r" (cpu_to_be64(set))
: "cc" );
V_32 = F_24 ( V_30 ) ;
F_25 ( V_27 , V_32 , V_28 , V_29 ) ;
if ( V_32 & V_34 )
F_26 ( V_26 , V_27 , V_15 , V_32 ) ;
return V_32 ;
}
T_4 F_27 ( struct V_35 * V_36 , unsigned long V_37 ,
T_4 * V_15 )
{
T_4 V_38 ;
F_28 ( V_37 & ~ V_39 ) ;
F_28 ( F_22 ( * V_15 ) ) ;
V_38 = * V_15 ;
F_29 ( V_15 ) ;
F_30 () ;
F_31 ( V_36 -> V_40 , & V_38 , V_37 ) ;
return V_38 ;
}
void F_32 ( struct V_25 * V_26 , T_4 * V_15 ,
T_7 V_41 )
{
T_7 * V_42 ;
F_23 ( & V_26 -> V_33 ) ;
V_42 = ( T_7 * ) V_15 + V_43 ;
* V_42 = V_41 ;
F_19 () ;
}
T_7 F_33 ( struct V_25 * V_26 , T_4 * V_15 )
{
T_7 V_41 ;
T_7 * V_42 ;
F_23 ( & V_26 -> V_33 ) ;
V_42 = ( T_7 * ) V_15 + V_43 ;
V_41 = * V_42 ;
* V_42 = NULL ;
memset ( V_41 , 0 , V_44 ) ;
return V_41 ;
}
void F_34 ( struct V_35 * V_36 ,
unsigned long V_37 , T_4 * V_15 )
{
F_28 ( V_37 & ~ V_39 ) ;
F_28 ( F_35 ( V_37 ) != V_45 ) ;
F_36 ( V_36 -> V_40 , V_37 , V_15 , 0 , V_46 ) ;
}
void F_26 ( struct V_25 * V_26 , unsigned long V_27 ,
T_4 * V_15 , unsigned long V_47 )
{
int V_48 ;
unsigned int V_49 ;
unsigned long V_50 ;
unsigned long V_12 = 0 ;
const struct V_51 * V_31 ;
#ifdef F_21
V_49 = F_37 ( V_26 , V_27 ) ;
F_5 ( V_49 == V_52 ) ;
#endif
if ( V_47 & V_53 )
V_49 = V_54 ;
else
V_49 = V_55 ;
if ( ! F_38 ( V_27 ) ) {
V_48 = F_39 ( V_27 ) ;
V_50 = F_40 ( V_26 -> V_56 . V_57 , V_27 , V_48 ) ;
F_7 ( V_50 == 0 ) ;
} else {
V_50 = F_41 ( V_27 , V_7 ) ;
V_48 = V_7 ;
}
V_31 = F_42 ( F_43 () ) ;
if ( F_44 ( F_45 ( V_26 ) , V_31 ) )
V_12 |= V_58 ;
return F_46 ( V_50 , V_27 , V_15 , V_49 , V_48 , V_12 ) ;
}
T_4 F_47 ( struct V_25 * V_26 ,
unsigned long V_27 , T_4 * V_15 )
{
T_4 V_47 ;
T_7 V_41 ;
unsigned long V_32 ;
T_7 * V_42 ;
V_32 = F_36 ( V_26 , V_27 , V_15 , ~ 0UL , 0 ) ;
V_47 = F_48 ( V_32 ) ;
V_42 = ( T_7 * ) V_15 + V_43 ;
V_41 = * V_42 ;
memset ( V_41 , 0 , V_44 ) ;
F_30 () ;
return V_47 ;
}
int F_49 ( void )
{
if ( ! F_50 ( V_59 ) )
return 0 ;
if ( V_60 [ V_52 ] . V_61 != V_62 )
return 0 ;
if ( V_60 [ V_55 ] . V_61 &&
( V_60 [ V_55 ] . V_63 [ V_52 ] == - 1 ) )
return 0 ;
if ( V_60 [ V_54 ] . V_63 [ V_52 ] == - 1 )
return 0 ;
return 1 ;
}
