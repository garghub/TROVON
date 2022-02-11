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
T_4 * V_23 ;
int V_24 = 0 ;
while ( V_19 && ( unsigned long ) V_18 & 7 ) {
* V_18 ++ = F_6 ( V_21 ) ;
V_19 -- ;
}
V_23 = ( T_4 * ) V_18 ;
while ( V_24 < V_19 / 8 ) {
register T_4 T_5 V_25 ( L_1 ) ;
asm volatile ("ldrd\t%0, [%1]" : "=&r" (x) : "r" (io_base));
V_23 [ V_24 ++ ] = T_5 ;
}
V_24 *= 8 ;
while ( V_24 < V_19 )
V_18 [ V_24 ++ ] = F_6 ( V_21 ) ;
}
static int T_6 F_7 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_30 * V_31 ;
void T_3 * V_21 ;
int V_32 = 0 ;
T_1 V_33 = 0 ;
V_29 = F_8 ( & V_27 -> V_34 ,
sizeof( struct V_28 ) ,
V_35 ) ;
if ( ! V_29 )
return - V_36 ;
V_6 = & V_29 -> V_20 ;
V_2 = F_9 ( V_6 ) ;
V_31 = F_10 ( V_27 , V_37 , 0 ) ;
V_21 = F_11 ( & V_27 -> V_34 , V_31 ) ;
if ( F_12 ( V_21 ) )
return F_13 ( V_21 ) ;
if ( V_27 -> V_34 . V_38 ) {
V_8 = F_8 ( & V_27 -> V_34 , sizeof( struct V_7 ) ,
V_35 ) ;
if ( ! V_8 )
return - V_36 ;
if ( ! F_14 ( V_27 -> V_34 . V_38 , L_2 , & V_33 ) )
V_8 -> V_12 = ( V_39 ) V_33 ;
else
V_8 -> V_12 = 0 ;
if ( ! F_14 ( V_27 -> V_34 . V_38 , L_3 , & V_33 ) )
V_8 -> V_14 = ( V_39 ) V_33 ;
else
V_8 -> V_14 = 1 ;
if ( ! F_14 ( V_27 -> V_34 . V_38 ,
L_4 , & V_33 ) )
V_8 -> V_40 = ( V_39 ) V_33 * 8 ;
else
V_8 -> V_40 = 8 ;
if ( ! F_14 ( V_27 -> V_34 . V_38 ,
L_5 , & V_33 ) )
V_8 -> V_41 = ( V_39 ) V_33 ;
} else {
V_8 = F_15 ( & V_27 -> V_34 ) ;
}
V_2 -> V_34 . V_42 = & V_27 -> V_34 ;
F_16 ( V_6 , V_8 ) ;
F_17 ( V_6 , V_27 -> V_34 . V_38 ) ;
V_6 -> V_22 = V_6 -> V_17 = V_21 ;
V_6 -> V_43 = F_1 ;
V_6 -> V_44 = F_5 ;
V_6 -> V_45 . V_46 = V_47 ;
V_6 -> V_45 . V_48 = V_49 ;
if ( V_8 -> V_41 )
V_6 -> V_41 = V_8 -> V_41 ;
F_18 ( V_8 -> V_40 > 16 ,
L_6 ,
V_8 -> V_40 ) ;
if ( V_8 -> V_40 == 16 )
V_6 -> V_15 |= V_16 ;
if ( V_8 -> V_50 )
V_6 -> V_50 = V_8 -> V_50 ;
F_19 ( V_27 , V_29 ) ;
V_29 -> V_51 = F_20 ( & V_27 -> V_34 , NULL ) ;
if ( F_12 ( V_29 -> V_51 ) ) {
V_32 = F_13 ( V_29 -> V_51 ) ;
if ( V_32 == - V_52 ) {
V_29 -> V_51 = NULL ;
} else {
F_21 ( & V_27 -> V_34 , L_7 ) ;
return V_32 ;
}
}
V_32 = F_22 ( V_29 -> V_51 ) ;
if ( V_32 ) {
F_21 ( & V_27 -> V_34 , L_8 ) ;
return V_32 ;
}
V_32 = F_23 ( V_2 , 1 ) ;
if ( V_32 )
goto V_53;
V_2 -> V_54 = L_9 ;
V_32 = F_24 ( V_2 , V_8 -> V_55 , V_8 -> V_56 ) ;
if ( V_32 ) {
F_25 ( V_2 ) ;
goto V_53;
}
return 0 ;
V_53:
F_26 ( V_29 -> V_51 ) ;
return V_32 ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_28 ( V_27 ) ;
struct V_5 * V_20 = & V_29 -> V_20 ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
F_25 ( V_2 ) ;
F_26 ( V_29 -> V_51 ) ;
return 0 ;
}
