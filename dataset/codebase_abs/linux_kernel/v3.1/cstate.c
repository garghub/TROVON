void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & F_2 ( V_3 ) ;
V_2 -> V_6 = 0 ;
if ( F_3 () == 1 )
V_2 -> V_6 = 1 ;
else if ( V_5 -> V_7 == V_8 ) {
V_2 -> V_6 = 1 ;
}
if ( V_5 -> V_7 == V_8 &&
( V_5 -> V_9 > 0xf || ( V_5 -> V_9 == 6 && V_5 -> V_10 >= 0x0f ) ) )
V_2 -> V_11 = 0 ;
}
static long F_4 ( void * V_12 )
{
struct V_13 * V_14 = V_12 ;
long V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
unsigned int V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
F_5 ( V_23 , & V_16 , & V_17 , & V_18 , & V_19 ) ;
V_21 = ( ( V_14 -> V_24 >> V_25 ) &
V_26 ) + 1 ;
V_20 = V_19 >> ( V_21 * V_25 ) ;
V_22 = V_20 & V_27 ;
V_15 = 0 ;
if ( V_22 < ( V_14 -> V_24 & V_27 ) ) {
V_15 = - 1 ;
goto V_28;
}
if ( ! ( V_18 & V_29 ) ||
! ( V_18 & V_30 ) ) {
V_15 = - 1 ;
goto V_28;
}
if ( ! V_31 [ V_21 ] ) {
V_31 [ V_21 ] = 1 ;
F_6 ( V_32
L_1
L_2 , V_14 -> type ) ;
}
snprintf ( V_14 -> V_33 ,
V_34 , L_3 ,
V_14 -> V_24 ) ;
V_28:
return V_15 ;
}
int F_7 ( unsigned int V_3 ,
struct V_13 * V_14 , struct V_35 * V_36 )
{
struct V_37 * V_38 ;
struct V_4 * V_5 = & F_2 ( V_3 ) ;
long V_15 ;
if ( ! V_39 || V_5 -> V_40 < V_23 )
return - 1 ;
if ( V_36 -> V_41 != V_42 )
return - 1 ;
V_38 = F_8 ( V_39 , V_3 ) ;
V_38 -> V_43 [ V_14 -> V_44 ] . V_16 = 0 ;
V_38 -> V_43 [ V_14 -> V_44 ] . V_18 = 0 ;
V_15 = F_9 ( V_3 , F_4 , V_14 ) ;
if ( V_15 == 0 ) {
V_38 -> V_43 [ V_14 -> V_44 ] . V_16 = V_14 -> V_24 ;
V_38 -> V_43 [ V_14 -> V_44 ] . V_18 = V_45 ;
}
if ( ( V_5 -> V_7 == V_8 ) && ! ( V_36 -> V_46 & 0x2 ) )
V_14 -> V_47 = 1 ;
return V_15 ;
}
void F_10 ( unsigned long V_48 , unsigned long V_14 )
{
if ( ! F_11 () ) {
if ( F_12 ( V_49 ) )
F_13 ( ( void * ) & F_14 () -> V_2 ) ;
F_15 ( ( void * ) & F_14 () -> V_2 , 0 , 0 ) ;
F_16 () ;
if ( ! F_11 () )
F_17 ( V_48 , V_14 ) ;
}
}
void F_18 ( struct V_13 * V_14 )
{
unsigned int V_3 = F_19 () ;
struct V_37 * V_38 ;
V_38 = F_8 ( V_39 , V_3 ) ;
F_10 ( V_38 -> V_43 [ V_14 -> V_44 ] . V_16 ,
V_38 -> V_43 [ V_14 -> V_44 ] . V_18 ) ;
}
static int T_1 F_20 ( void )
{
struct V_4 * V_5 = & V_50 ;
if ( V_5 -> V_7 != V_8 )
return - 1 ;
V_39 = F_21 ( struct V_37 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( V_39 ) ;
V_39 = NULL ;
}
