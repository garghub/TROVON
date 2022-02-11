static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_7 ;
T_1 V_10 ;
if ( V_3 == V_11 )
return;
if ( V_4 & V_12 )
V_10 = ( 1 << V_9 -> V_13 ) ;
else if ( V_4 & V_14 )
V_10 = ( 1 << V_9 -> V_15 ) ;
else
return;
if ( V_6 -> V_16 & V_17 )
V_10 <<= 1 ;
F_2 ( V_3 , V_6 -> V_18 + V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_2 * V_19 , int V_20 )
{
struct V_5 * V_21 = V_2 -> V_7 ;
void T_3 * V_22 = V_21 -> V_23 ;
T_4 * V_24 ;
int V_25 = 0 ;
while ( V_20 && ( unsigned long ) V_19 & 7 ) {
* V_19 ++ = F_4 ( V_22 ) ;
V_20 -- ;
}
V_24 = ( T_4 * ) V_19 ;
while ( V_25 < V_20 / 8 ) {
register T_4 T_5 V_26 ( L_1 ) ;
asm volatile ("ldrd\t%0, [%1]" : "=&r" (x) : "r" (io_base));
V_24 [ V_25 ++ ] = T_5 ;
}
V_25 *= 8 ;
while ( V_25 < V_20 )
V_19 [ V_25 ++ ] = F_4 ( V_22 ) ;
}
static int T_6 F_5 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_29 V_30 = {} ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
void T_3 * V_22 ;
int V_34 = 0 ;
T_1 V_35 = 0 ;
V_6 = F_6 ( & V_28 -> V_36 ,
sizeof( struct V_5 ) + sizeof( struct V_1 ) ,
V_37 ) ;
if ( ! V_6 )
return - V_38 ;
V_2 = (struct V_1 * ) ( V_6 + 1 ) ;
V_32 = F_7 ( V_28 , V_39 , 0 ) ;
V_22 = F_8 ( & V_28 -> V_36 , V_32 ) ;
if ( F_9 ( V_22 ) )
return F_10 ( V_22 ) ;
if ( V_28 -> V_36 . V_40 ) {
V_9 = F_6 ( & V_28 -> V_36 , sizeof( struct V_8 ) ,
V_37 ) ;
if ( ! V_9 )
return - V_38 ;
if ( ! F_11 ( V_28 -> V_36 . V_40 , L_2 , & V_35 ) )
V_9 -> V_13 = ( V_41 ) V_35 ;
else
V_9 -> V_13 = 0 ;
if ( ! F_11 ( V_28 -> V_36 . V_40 , L_3 , & V_35 ) )
V_9 -> V_15 = ( V_41 ) V_35 ;
else
V_9 -> V_15 = 1 ;
if ( ! F_11 ( V_28 -> V_36 . V_40 ,
L_4 , & V_35 ) )
V_9 -> V_42 = ( V_41 ) V_35 * 8 ;
else
V_9 -> V_42 = 8 ;
if ( ! F_11 ( V_28 -> V_36 . V_40 ,
L_5 , & V_35 ) )
V_9 -> V_43 = ( V_41 ) V_35 ;
} else {
V_9 = F_12 ( & V_28 -> V_36 ) ;
}
V_2 -> V_7 = V_6 ;
V_2 -> V_44 = V_45 ;
V_6 -> V_7 = V_9 ;
V_6 -> V_23 = V_6 -> V_18 = V_22 ;
V_6 -> V_46 = F_1 ;
V_6 -> V_47 = F_3 ;
V_6 -> V_48 . V_49 = V_50 ;
if ( V_9 -> V_43 )
V_6 -> V_43 = V_9 -> V_43 ;
F_13 ( V_9 -> V_42 > 16 ,
L_6 ,
V_9 -> V_42 ) ;
if ( V_9 -> V_42 == 16 )
V_6 -> V_16 |= V_17 ;
if ( V_9 -> V_51 )
V_6 -> V_51 = V_9 -> V_51 ;
F_14 ( V_28 , V_2 ) ;
V_33 = F_15 ( & V_28 -> V_36 , NULL ) ;
if ( ! F_9 ( V_33 ) ) {
F_16 ( V_33 ) ;
F_17 ( V_33 ) ;
}
if ( F_18 ( V_2 , 1 ) ) {
V_34 = - V_52 ;
goto V_53;
}
V_2 -> V_54 = L_7 ;
V_30 . V_40 = V_28 -> V_36 . V_40 ;
V_34 = F_19 ( V_2 , NULL , & V_30 ,
V_9 -> V_55 , V_9 -> V_56 ) ;
if ( V_34 ) {
F_20 ( V_2 ) ;
goto V_53;
}
return 0 ;
V_53:
if ( ! F_9 ( V_33 ) ) {
F_21 ( V_33 ) ;
F_17 ( V_33 ) ;
}
return V_34 ;
}
static int F_22 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_23 ( V_28 ) ;
struct V_33 * V_33 ;
F_20 ( V_2 ) ;
V_33 = F_15 ( & V_28 -> V_36 , NULL ) ;
if ( ! F_9 ( V_33 ) ) {
F_21 ( V_33 ) ;
F_17 ( V_33 ) ;
}
return 0 ;
}
