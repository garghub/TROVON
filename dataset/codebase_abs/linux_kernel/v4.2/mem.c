void T_1 F_1 ( void )
{
F_2 ( 0x0 , ( V_1 << 20 ) , V_2 ) ;
F_2 ( V_1 << 20 , V_3 - ( V_1 <<
20 ) , V_4 ) ;
#ifdef F_3
{
int V_5 ;
V_5 = F_4 ( V_1 + V_6 ) ;
if ( V_5 != F_5 ( V_1 + V_6 ) )
V_5 += 20 ;
else
V_5 = V_5 + 20 - 1 ;
F_6 ( V_7 , 0x80000000ul ,
0x80000000ul , ( 1 << V_5 ) ) ;
F_7 () ;
}
#endif
#ifdef F_8
if ( V_6 > 0 )
F_2 ( V_8 ,
V_6 << 20 , V_2 ) ;
F_2 ( V_9 + 1 , V_8 -
V_9 - 1 , V_4 ) ;
#endif
}
void T_1 F_1 ( void )
{
int V_10 ;
T_2 V_11 ;
T_2 V_12 ;
for ( V_10 = 0 ; V_10 < V_13 -> V_14 ; V_10 ++ ) {
V_11 = V_13 -> V_15 [ V_10 ] . V_11 ;
V_12 = V_13 -> V_15 [ V_10 ] . V_12 ;
if ( V_11 == 0 ) {
switch ( V_12 ) {
case V_16 :
F_2 ( V_13 -> V_15 [ V_10 ] . V_17 ,
( V_18 ) V_13 -> V_15 [ V_10 ] . V_19 << 20 ,
V_2 ) ;
break;
case V_20 :
F_2 ( V_13 -> V_15 [ V_10 ] . V_17 ,
( V_18 ) V_13 -> V_15 [ V_10 ] . V_19 << 20 ,
V_2 ) ;
break;
case V_21 :
F_2 ( V_13 -> V_15 [ V_10 ] . V_17 ,
( V_18 ) V_13 -> V_15 [ V_10 ] . V_19 << 20 ,
V_4 ) ;
break;
}
}
}
}
int F_9 ( struct V_22 * V_22 , unsigned long V_23 )
{
if ( V_22 -> V_24 & V_25 )
return 1 ;
return V_23 >= F_10 ( V_26 ) ||
( ( V_23 >= V_27 ) &&
( V_23 < V_28 ) ) ;
}
T_3 F_11 ( struct V_22 * V_22 , unsigned long V_29 ,
unsigned long V_30 , T_3 V_31 )
{
unsigned long V_32 = V_29 << V_33 ;
unsigned long V_34 = V_32 + V_30 ;
if ( F_9 ( V_22 , V_32 ) ) {
if ( V_35 && ( V_32 >= V_35 ) &&
( V_34 <= V_36 ) )
return F_12 ( ( F_13 ( V_31 ) &
~ V_37 ) |
V_38 ) ;
else
return F_14 ( V_31 ) ;
}
return V_31 ;
}
static int T_1 F_15 ( void )
{
struct V_39 * V_40 = 0 ;
struct V_41 * V_42 ;
int V_43 ;
if ( V_35 )
return 0 ;
F_16 (dev) {
if ( ( V_40 -> V_44 >> 16 ) == V_45 ) {
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
V_42 = & V_40 -> V_41 [ V_43 ] ;
if ( ! V_42 -> V_47 && V_42 -> V_34 )
continue;
if ( V_42 -> V_48 & V_49 )
continue;
if ( V_42 -> V_48 & V_50 ) {
V_35 = V_42 -> V_47 ;
V_36 = V_42 -> V_34 ;
return 0 ;
}
}
}
}
return 0 ;
}
