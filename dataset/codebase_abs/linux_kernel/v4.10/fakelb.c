static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 ( ! V_3 ) ;
* V_3 = 0xbe ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_4 ( & V_9 ) ;
V_7 -> V_4 = V_4 ;
V_7 -> V_5 = V_5 ;
F_5 ( & V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_6 * V_12 = V_2 -> V_8 , * V_7 ;
F_7 ( & V_9 ) ;
F_8 ( V_12 -> V_13 ) ;
F_9 (phy, &fakelb_ifup_phys, list_ifup) {
if ( V_12 == V_7 )
continue;
if ( V_12 -> V_4 == V_7 -> V_4 &&
V_12 -> V_5 == V_7 -> V_5 ) {
struct V_10 * V_14 = F_10 ( V_11 , V_15 ) ;
if ( V_14 )
F_11 ( V_7 -> V_2 , V_14 , 0xcc ) ;
}
}
F_12 ( & V_9 ) ;
F_13 ( V_2 , V_11 , false ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_4 ( & V_9 ) ;
V_7 -> V_13 = false ;
F_15 ( & V_7 -> V_16 , & V_17 ) ;
F_5 ( & V_9 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_4 ( & V_9 ) ;
V_7 -> V_13 = true ;
F_17 ( & V_7 -> V_16 ) ;
F_5 ( & V_9 ) ;
}
static int
F_18 ( struct V_1 * V_2 , const bool V_18 )
{
return 0 ;
}
static int F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_21 ;
V_2 = F_20 ( sizeof( * V_7 ) , & V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_7 = V_2 -> V_8 ;
V_7 -> V_2 = V_2 ;
V_2 -> V_7 -> V_24 . V_25 [ 0 ] |= 1 ;
V_2 -> V_7 -> V_24 . V_25 [ 0 ] |= 0x7fe ;
V_2 -> V_7 -> V_24 . V_25 [ 0 ] |= 0x7FFF800 ;
V_2 -> V_7 -> V_24 . V_25 [ 1 ] |= 1 ;
V_2 -> V_7 -> V_24 . V_25 [ 1 ] |= 0x7fe ;
V_2 -> V_7 -> V_24 . V_25 [ 2 ] |= 1 ;
V_2 -> V_7 -> V_24 . V_25 [ 2 ] |= 0x7fe ;
V_2 -> V_7 -> V_24 . V_25 [ 3 ] |= 0x3fff ;
V_2 -> V_7 -> V_24 . V_25 [ 4 ] |= 1 ;
V_2 -> V_7 -> V_24 . V_25 [ 4 ] |= 0x1e ;
V_2 -> V_7 -> V_24 . V_25 [ 4 ] |= 0xffe0 ;
V_2 -> V_7 -> V_24 . V_25 [ 5 ] |= 0xf ;
V_2 -> V_7 -> V_24 . V_25 [ 5 ] |= 0xf0 ;
V_2 -> V_7 -> V_24 . V_25 [ 6 ] |= 0x3ff ;
V_2 -> V_7 -> V_24 . V_25 [ 6 ] |= 0x3ffc00 ;
F_21 ( & V_2 -> V_7 -> V_26 ) ;
V_2 -> V_7 -> V_27 = 13 ;
V_7 -> V_5 = V_2 -> V_7 -> V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_20 ;
V_21 = F_22 ( V_2 ) ;
if ( V_21 )
goto V_31;
F_23 ( & V_32 ) ;
F_24 ( & V_7 -> V_33 , & V_34 ) ;
F_25 ( & V_32 ) ;
return 0 ;
V_31:
F_26 ( V_7 -> V_2 ) ;
return V_21 ;
}
static void F_27 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_33 ) ;
F_28 ( V_7 -> V_2 ) ;
F_26 ( V_7 -> V_2 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_6 * V_7 , * V_37 ;
int V_21 , V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_21 = F_19 ( & V_36 -> V_20 ) ;
if ( V_21 < 0 )
goto V_40;
}
F_30 ( & V_36 -> V_20 , L_1 , V_39 ) ;
return 0 ;
V_40:
F_23 ( & V_32 ) ;
F_31 (phy, tmp, &fakelb_phys, list)
F_27 ( V_7 ) ;
F_25 ( & V_32 ) ;
return V_21 ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_6 * V_7 , * V_37 ;
F_23 ( & V_32 ) ;
F_31 (phy, tmp, &fakelb_phys, list)
F_27 ( V_7 ) ;
F_25 ( & V_32 ) ;
return 0 ;
}
static T_2 int F_33 ( void )
{
V_41 = F_34 (
L_2 , - 1 , NULL , 0 ) ;
return F_35 ( & V_42 ) ;
}
static T_3 void F_36 ( void )
{
F_37 ( & V_42 ) ;
F_38 ( V_41 ) ;
}
