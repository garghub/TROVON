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
V_6 = F_6 ( sizeof( struct V_5 ) + sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_6 ) {
F_7 ( V_37 L_2 ) ;
V_34 = - V_38 ;
goto V_39;
}
V_2 = (struct V_1 * ) ( V_6 + 1 ) ;
V_32 = F_8 ( V_28 , V_40 , 0 ) ;
if ( ! V_32 ) {
V_34 = - V_41 ;
goto V_39;
}
V_22 = F_9 ( V_32 -> V_42 , F_10 ( V_32 ) ) ;
if ( ! V_22 ) {
F_7 ( V_37 L_3 ) ;
V_34 = - V_43 ;
goto V_39;
}
if ( V_28 -> V_44 . V_45 ) {
V_9 = F_11 ( & V_28 -> V_44 , sizeof( struct V_8 ) ,
V_36 ) ;
if ( ! V_9 ) {
F_7 ( V_37 L_4 ) ;
V_34 = - V_38 ;
goto V_39;
}
if ( ! F_12 ( V_28 -> V_44 . V_45 , L_5 , & V_35 ) )
V_9 -> V_13 = ( V_46 ) V_35 ;
else
V_9 -> V_13 = 0 ;
if ( ! F_12 ( V_28 -> V_44 . V_45 , L_6 , & V_35 ) )
V_9 -> V_15 = ( V_46 ) V_35 ;
else
V_9 -> V_15 = 1 ;
if ( ! F_12 ( V_28 -> V_44 . V_45 ,
L_7 , & V_35 ) )
V_9 -> V_47 = ( V_46 ) V_35 * 8 ;
else
V_9 -> V_47 = 8 ;
if ( ! F_12 ( V_28 -> V_44 . V_45 ,
L_8 , & V_35 ) )
V_9 -> V_48 = ( V_46 ) V_35 ;
} else
V_9 = V_28 -> V_44 . V_49 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_50 = V_51 ;
V_6 -> V_7 = V_9 ;
V_6 -> V_23 = V_6 -> V_18 = V_22 ;
V_6 -> V_52 = F_1 ;
V_6 -> V_53 = F_3 ;
V_6 -> V_54 . V_55 = V_56 ;
if ( V_9 -> V_48 )
V_6 -> V_48 = V_9 -> V_48 ;
F_13 ( V_9 -> V_47 > 16 ,
L_9 ,
V_9 -> V_47 ) ;
if ( V_9 -> V_47 == 16 )
V_6 -> V_16 |= V_17 ;
if ( V_9 -> V_57 )
V_6 -> V_57 = V_9 -> V_57 ;
F_14 ( V_28 , V_2 ) ;
V_33 = F_15 ( & V_28 -> V_44 , NULL ) ;
if ( ! F_16 ( V_33 ) ) {
F_17 ( V_33 ) ;
F_18 ( V_33 ) ;
}
if ( F_19 ( V_2 , 1 ) ) {
V_34 = - V_58 ;
goto V_59;
}
V_2 -> V_60 = L_10 ;
V_30 . V_45 = V_28 -> V_44 . V_45 ;
V_34 = F_20 ( V_2 , NULL , & V_30 ,
V_9 -> V_61 , V_9 -> V_62 ) ;
if ( V_34 ) {
F_21 ( V_2 ) ;
goto V_59;
}
return 0 ;
V_59:
F_14 ( V_28 , NULL ) ;
F_22 ( V_22 ) ;
V_39:
F_23 ( V_6 ) ;
return V_34 ;
}
static int T_7 F_24 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_25 ( V_28 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_33 * V_33 ;
F_21 ( V_2 ) ;
F_22 ( V_6 -> V_18 ) ;
F_23 ( V_6 ) ;
V_33 = F_15 ( & V_28 -> V_44 , NULL ) ;
if ( ! F_16 ( V_33 ) ) {
F_26 ( V_33 ) ;
F_18 ( V_33 ) ;
}
return 0 ;
}
static int T_6 F_27 ( void )
{
return F_28 ( & V_63 , F_5 ) ;
}
static void T_8 F_29 ( void )
{
F_30 ( & V_63 ) ;
}
