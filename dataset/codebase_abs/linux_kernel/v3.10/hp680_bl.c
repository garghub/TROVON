static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
int V_5 = V_2 -> V_6 . V_7 ;
if ( V_2 -> V_6 . V_8 != V_9 )
V_5 = 0 ;
if ( V_2 -> V_6 . V_10 != V_9 )
V_5 = 0 ;
if ( V_11 )
V_5 = 0 ;
F_2 ( & V_12 , V_3 ) ;
if ( V_5 && V_13 == 0 ) {
F_3 ( V_14 ) ;
V_4 = F_4 ( V_15 ) ;
V_4 &= ~ V_16 ;
F_5 ( V_4 , V_15 ) ;
F_6 ( 255 - ( V_17 ) V_5 , V_14 ) ;
} else if ( V_5 == 0 && V_13 != 0 ) {
F_6 ( 255 - ( V_17 ) V_5 , V_14 ) ;
F_7 ( V_14 ) ;
V_4 = F_4 ( V_15 ) ;
V_4 |= V_16 ;
F_5 ( V_4 , V_15 ) ;
} else if ( V_5 ) {
F_6 ( 255 - ( V_17 ) V_5 , V_14 ) ;
}
F_8 ( & V_12 , V_3 ) ;
V_13 = V_5 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
V_11 = 1 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
V_11 = 0 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return V_13 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 V_6 ;
struct V_1 * V_2 ;
memset ( & V_6 , 0 , sizeof( struct V_22 ) ) ;
V_6 . type = V_23 ;
V_6 . V_24 = V_25 ;
V_2 = F_15 ( L_1 , & V_21 -> V_19 , NULL ,
& V_26 , & V_6 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_2 ) ;
F_18 ( V_21 , V_2 ) ;
V_2 -> V_6 . V_7 = V_27 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_20 ( V_21 ) ;
V_2 -> V_6 . V_7 = 0 ;
V_2 -> V_6 . V_8 = 0 ;
F_1 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
int V_28 ;
V_28 = F_23 ( & V_29 ) ;
if ( V_28 )
return V_28 ;
V_30 = F_24 ( L_1 , - 1 ,
NULL , 0 ) ;
if ( F_16 ( V_30 ) ) {
F_25 ( & V_29 ) ;
return F_17 ( V_30 ) ;
}
return 0 ;
}
static void T_3 F_26 ( void )
{
F_27 ( V_30 ) ;
F_25 ( & V_29 ) ;
}
