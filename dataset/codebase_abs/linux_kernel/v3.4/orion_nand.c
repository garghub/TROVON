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
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_29 * V_30 ;
void T_3 * V_22 ;
int V_31 = 0 ;
V_6 = F_6 ( sizeof( struct V_5 ) + sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_6 ) {
F_7 ( V_33 L_2 ) ;
V_31 = - V_34 ;
goto V_35;
}
V_2 = (struct V_1 * ) ( V_6 + 1 ) ;
V_30 = F_8 ( V_28 , V_36 , 0 ) ;
if ( ! V_30 ) {
V_31 = - V_37 ;
goto V_35;
}
V_22 = F_9 ( V_30 -> V_38 , F_10 ( V_30 ) ) ;
if ( ! V_22 ) {
F_7 ( V_33 L_3 ) ;
V_31 = - V_39 ;
goto V_35;
}
V_9 = V_28 -> V_40 . V_41 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_42 = V_43 ;
V_6 -> V_7 = V_9 ;
V_6 -> V_23 = V_6 -> V_18 = V_22 ;
V_6 -> V_44 = F_1 ;
V_6 -> V_45 = F_3 ;
V_6 -> V_46 . V_47 = V_48 ;
if ( V_9 -> V_49 )
V_6 -> V_49 = V_9 -> V_49 ;
if ( V_9 -> V_50 == 16 )
V_6 -> V_16 |= V_17 ;
if ( V_9 -> V_51 )
V_6 -> V_51 = V_9 -> V_51 ;
F_11 ( V_28 , V_2 ) ;
if ( F_12 ( V_2 , 1 ) ) {
V_31 = - V_52 ;
goto V_53;
}
V_2 -> V_54 = L_4 ;
V_31 = F_13 ( V_2 , NULL , NULL , V_9 -> V_55 ,
V_9 -> V_56 ) ;
if ( V_31 ) {
F_14 ( V_2 ) ;
goto V_53;
}
return 0 ;
V_53:
F_11 ( V_28 , NULL ) ;
F_15 ( V_22 ) ;
V_35:
F_16 ( V_6 ) ;
return V_31 ;
}
static int T_7 F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_14 ( V_2 ) ;
F_15 ( V_6 -> V_18 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
static int T_6 F_19 ( void )
{
return F_20 ( & V_57 , F_5 ) ;
}
static void T_8 F_21 ( void )
{
F_22 ( & V_57 ) ;
}
