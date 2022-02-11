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
if ( V_22 == 0 ) {
F_6 ( V_28 L_1 , V_14 -> V_24 , V_20 ) ;
V_15 = - 1 ;
goto V_29;
}
if ( ! ( V_18 & V_30 ) ||
! ( V_18 & V_31 ) ) {
V_15 = - 1 ;
goto V_29;
}
if ( ! V_32 [ V_21 ] ) {
V_32 [ V_21 ] = 1 ;
F_7 ( V_33
L_2
L_3 , V_14 -> type ) ;
}
snprintf ( V_14 -> V_34 ,
V_35 , L_4 ,
V_14 -> V_24 ) ;
V_29:
return V_15 ;
}
int F_8 ( unsigned int V_3 ,
struct V_13 * V_14 , struct V_36 * V_37 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 = & F_2 ( V_3 ) ;
long V_15 ;
if ( ! V_40 || V_5 -> V_41 < V_23 )
return - 1 ;
if ( V_37 -> V_42 != V_43 )
return - 1 ;
V_39 = F_9 ( V_40 , V_3 ) ;
V_39 -> V_44 [ V_14 -> V_45 ] . V_16 = 0 ;
V_39 -> V_44 [ V_14 -> V_45 ] . V_18 = 0 ;
V_15 = F_10 ( V_3 , F_4 , V_14 ) ;
if ( V_15 == 0 ) {
V_39 -> V_44 [ V_14 -> V_45 ] . V_16 = V_14 -> V_24 ;
V_39 -> V_44 [ V_14 -> V_45 ] . V_18 = V_46 ;
}
if ( ( V_5 -> V_7 == V_8 ) && ! ( V_37 -> V_47 & 0x2 ) )
V_14 -> V_48 = 1 ;
return V_15 ;
}
void F_11 ( struct V_13 * V_14 )
{
unsigned int V_3 = F_12 () ;
struct V_38 * V_39 ;
V_39 = F_9 ( V_40 , V_3 ) ;
F_13 ( V_39 -> V_44 [ V_14 -> V_45 ] . V_16 ,
V_39 -> V_44 [ V_14 -> V_45 ] . V_18 ) ;
}
static int T_1 F_14 ( void )
{
struct V_4 * V_5 = & V_49 ;
if ( V_5 -> V_7 != V_8 )
return - 1 ;
V_40 = F_15 ( struct V_38 ) ;
return 0 ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_40 ) ;
V_40 = NULL ;
}
