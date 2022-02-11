static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_9 ;
if ( V_3 == V_10 )
return;
if ( V_4 & V_11 )
V_9 = ( 1 << V_8 -> V_12 ) ;
else if ( V_4 & V_13 )
V_9 = ( 1 << V_8 -> V_14 ) ;
else
return;
if ( V_6 -> V_15 & V_16 )
V_9 <<= 1 ;
F_4 ( V_3 , V_6 -> V_17 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_18 , int V_19 )
{
struct V_5 * V_20 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_20 -> V_22 ;
#if V_23 >= 5
T_4 * V_24 ;
#endif
int V_25 = 0 ;
while ( V_19 && ( unsigned long ) V_18 & 7 ) {
* V_18 ++ = F_6 ( V_21 ) ;
V_19 -- ;
}
#if V_23 >= 5
V_24 = ( T_4 * ) V_18 ;
while ( V_25 < V_19 / 8 ) {
register T_4 T_5 V_26 ( L_1 ) ;
asm volatile ("ldrd\t%0, [%1]" : "=&r" (x) : "r" (io_base));
V_24 [ V_25 ++ ] = T_5 ;
}
V_25 *= 8 ;
#else
F_7 ( V_21 , V_18 , V_19 / 4 ) ;
V_25 = V_19 / 4 * 4 ;
#endif
while ( V_25 < V_19 )
V_18 [ V_25 ++ ] = F_6 ( V_21 ) ;
}
static int T_6 F_8 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_31 * V_32 ;
void T_3 * V_21 ;
int V_33 = 0 ;
T_1 V_34 = 0 ;
V_30 = F_9 ( & V_28 -> V_35 ,
sizeof( struct V_29 ) ,
V_36 ) ;
if ( ! V_30 )
return - V_37 ;
V_6 = & V_30 -> V_20 ;
V_2 = F_10 ( V_6 ) ;
V_32 = F_11 ( V_28 , V_38 , 0 ) ;
V_21 = F_12 ( & V_28 -> V_35 , V_32 ) ;
if ( F_13 ( V_21 ) )
return F_14 ( V_21 ) ;
if ( V_28 -> V_35 . V_39 ) {
V_8 = F_9 ( & V_28 -> V_35 , sizeof( struct V_7 ) ,
V_36 ) ;
if ( ! V_8 )
return - V_37 ;
if ( ! F_15 ( V_28 -> V_35 . V_39 , L_2 , & V_34 ) )
V_8 -> V_12 = ( V_40 ) V_34 ;
else
V_8 -> V_12 = 0 ;
if ( ! F_15 ( V_28 -> V_35 . V_39 , L_3 , & V_34 ) )
V_8 -> V_14 = ( V_40 ) V_34 ;
else
V_8 -> V_14 = 1 ;
if ( ! F_15 ( V_28 -> V_35 . V_39 ,
L_4 , & V_34 ) )
V_8 -> V_41 = ( V_40 ) V_34 * 8 ;
else
V_8 -> V_41 = 8 ;
if ( ! F_15 ( V_28 -> V_35 . V_39 ,
L_5 , & V_34 ) )
V_8 -> V_42 = ( V_40 ) V_34 ;
} else {
V_8 = F_16 ( & V_28 -> V_35 ) ;
}
V_2 -> V_35 . V_43 = & V_28 -> V_35 ;
F_17 ( V_6 , V_8 ) ;
F_18 ( V_6 , V_28 -> V_35 . V_39 ) ;
V_6 -> V_22 = V_6 -> V_17 = V_21 ;
V_6 -> V_44 = F_1 ;
V_6 -> V_45 = F_5 ;
V_6 -> V_46 . V_47 = V_48 ;
V_6 -> V_46 . V_49 = V_50 ;
if ( V_8 -> V_42 )
V_6 -> V_42 = V_8 -> V_42 ;
F_19 ( V_8 -> V_41 > 16 ,
L_6 ,
V_8 -> V_41 ) ;
if ( V_8 -> V_41 == 16 )
V_6 -> V_15 |= V_16 ;
if ( V_8 -> V_51 )
V_6 -> V_51 = V_8 -> V_51 ;
F_20 ( V_28 , V_30 ) ;
V_30 -> V_52 = F_21 ( & V_28 -> V_35 , NULL ) ;
if ( F_13 ( V_30 -> V_52 ) ) {
V_33 = F_14 ( V_30 -> V_52 ) ;
if ( V_33 == - V_53 ) {
V_30 -> V_52 = NULL ;
} else {
F_22 ( & V_28 -> V_35 , L_7 ) ;
return V_33 ;
}
}
V_33 = F_23 ( V_30 -> V_52 ) ;
if ( V_33 ) {
F_22 ( & V_28 -> V_35 , L_8 ) ;
return V_33 ;
}
V_33 = F_24 ( V_2 , 1 ) ;
if ( V_33 )
goto V_54;
V_2 -> V_55 = L_9 ;
V_33 = F_25 ( V_2 , V_8 -> V_56 , V_8 -> V_57 ) ;
if ( V_33 ) {
F_26 ( V_2 ) ;
goto V_54;
}
return 0 ;
V_54:
F_27 ( V_30 -> V_52 ) ;
return V_33 ;
}
static int F_28 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_29 ( V_28 ) ;
struct V_5 * V_20 = & V_30 -> V_20 ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
F_26 ( V_2 ) ;
F_27 ( V_30 -> V_52 ) ;
return 0 ;
}
