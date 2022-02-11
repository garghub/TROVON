static inline int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_6 = V_3 * ( V_2 -> V_7 - 1 ) ;
V_6 /= V_5 -> V_8 . V_9 ;
return V_6 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
struct V_10 * V_11
= F_3 ( V_2 -> V_12 -> V_13 . V_14 ) ;
return V_11 -> V_15 ( V_11 , V_16 ,
( V_17 ) V_2 -> V_18 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_11
= F_3 ( V_2 -> V_12 -> V_13 . V_14 ) ;
return V_11 -> V_15 ( V_11 , V_16 , 0x0 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
return V_5 -> V_8 . V_3 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( & V_5 -> V_13 ) ;
struct V_10 * V_11 =
F_3 ( V_2 -> V_12 -> V_13 . V_14 ) ;
int V_3 = V_5 -> V_8 . V_3 ;
int V_19 ;
if ( ( V_3 < 0 ) || ( V_5 -> V_8 . V_9 < V_3 ) ) {
F_7 ( & V_5 -> V_13 , L_1 , V_3 ) ;
return - V_20 ;
}
F_8 ( & V_5 -> V_13 , L_2 ,
V_5 -> V_8 . V_3 , V_5 -> V_8 . V_21 , V_5 -> V_8 . V_22 ) ;
if ( ( V_5 -> V_8 . V_21 != V_23 ) ||
( V_5 -> V_8 . V_22 & V_24 ) ||
( V_5 -> V_8 . V_22 & V_25 ) )
V_3 = 0 ;
V_19 = V_11 -> V_15 ( V_11 , V_26 ,
( V_17 ) F_1 ( V_2 , V_3 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_3 == 0 ) {
V_19 = F_4 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
} else if ( V_2 -> V_3 == 0 ) {
V_19 = F_2 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_2 -> V_3 = V_3 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , struct V_27 * V_28 )
{
return 1 ;
}
static int F_10 ( struct V_29 * V_12 )
{
struct V_30 * V_31 = V_12 -> V_13 . V_32 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_33 V_8 ;
int V_19 = 0 ;
if ( ! V_31 ) {
F_7 ( & V_12 -> V_13 , L_3 ) ;
V_19 = - V_34 ;
goto V_35;
}
if ( V_12 -> V_36 != V_37 ) {
F_7 ( & V_12 -> V_13 , L_4 , V_12 -> V_36 ) ;
V_19 = - V_20 ;
goto V_35;
}
V_2 = F_11 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) ,
V_38 ) ;
if ( ! V_2 ) {
F_7 ( & V_12 -> V_13 ,
L_5 ) ;
V_19 = - V_39 ;
goto V_35;
}
memset ( & V_8 , 0 , sizeof( struct V_33 ) ) ;
V_8 . type = V_40 ;
V_5 = F_12 ( L_6 , & V_12 -> V_13 ,
V_2 , & V_41 , & V_8 ) ;
if ( F_13 ( V_5 ) ) {
F_7 ( & V_12 -> V_13 ,
L_7 ) ;
V_19 = F_14 ( V_5 ) ;
goto V_35;
}
V_2 -> V_12 = V_12 ;
F_15 ( V_12 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( V_31 -> V_18 > 0 )
V_2 -> V_18 = V_31 -> V_18 ;
else
V_2 -> V_18 = V_42 ;
if ( V_31 -> V_7 > 0 )
V_2 -> V_7 = V_31 -> V_7 ;
else
V_2 -> V_7 = V_43 ;
if ( V_31 -> V_9 > 0 )
V_5 -> V_8 . V_9 = V_31 -> V_9 ;
else
V_5 -> V_8 . V_9 = 255 ;
V_2 -> V_3 = 0 ;
V_5 -> V_8 . V_21 = V_23 ;
V_5 -> V_8 . V_3 = V_5 -> V_8 . V_9 ;
V_19 = F_6 ( V_5 ) ;
if ( V_19 < 0 ) {
F_7 ( & V_12 -> V_13 , L_8 ) ;
goto V_44;
}
return 0 ;
V_44:
F_16 ( V_5 ) ;
V_35:
return V_19 ;
}
static int F_17 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_8 . V_21 = V_45 ;
V_5 -> V_8 . V_3 = 0 ;
F_19 ( V_5 ) ;
F_16 ( V_5 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_46 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_46 ) ;
}
