int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
return V_1 -> V_3 -> V_4 ( V_1 -> V_5 . V_6 , V_2 ) ;
}
int F_2 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 )
{
return V_1 -> V_3 -> V_8 ( V_1 -> V_5 . V_6 , V_2 , V_7 ) ;
}
static int F_3 ( struct V_9 * V_5 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
struct V_1 * V_1 = F_5 ( V_5 ) ;
const struct V_14 * V_15 ;
for ( V_15 = V_13 -> V_16 ; V_15 -> V_17 ; V_15 ++ )
if ( V_15 -> V_17 == V_1 -> V_15 . V_17 &&
V_15 -> V_18 == V_1 -> V_15 . V_18 )
return 1 ;
return 0 ;
}
static int F_6 ( struct V_9 * V_5 , struct V_19 * V_20 )
{
struct V_1 * V_1 = F_5 ( V_5 ) ;
if ( F_7 ( V_20 , L_1 ,
V_1 -> V_15 . V_17 , V_1 -> V_15 . V_18 ) )
return - V_21 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_5 )
{
struct V_12 * V_13 = F_4 ( V_5 -> V_11 ) ;
return V_13 -> V_22 ( F_5 ( V_5 ) ) ;
}
static int F_9 ( struct V_9 * V_5 )
{
struct V_12 * V_13 = F_4 ( V_5 -> V_11 ) ;
if ( V_13 -> remove )
V_13 -> remove ( F_5 ( V_5 ) ) ;
return 0 ;
}
static T_2 F_10 ( struct V_9 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_1 = F_5 ( V_5 ) ;
return sprintf ( V_25 , L_2 ,
V_1 -> V_15 . V_17 , V_1 -> V_15 . V_18 ) ;
}
static void F_11 ( struct V_9 * V_5 )
{
F_12 ( F_5 ( V_5 ) ) ;
}
int F_13 ( struct V_12 * V_13 , struct V_26 * V_26 )
{
if ( ! V_13 -> V_22 )
return - V_27 ;
V_13 -> V_11 . V_28 = V_26 ;
V_13 -> V_11 . V_29 = & V_30 ;
return F_14 ( & V_13 -> V_11 ) ;
}
void F_15 ( struct V_12 * V_13 )
{
F_16 ( & V_13 -> V_11 ) ;
}
static int F_17 ( struct V_9 * V_5 , struct V_1 * V_1 )
{
int V_31 ;
V_1 -> V_5 . V_6 = V_5 ;
V_31 = F_2 ( V_1 , V_32 , 0xaa ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_1 ( V_1 , V_32 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 != 0xaa )
return - V_33 ;
V_1 -> V_15 . V_17 = F_1 ( V_1 , V_34 ) ;
V_1 -> V_15 . V_17 |= F_1 ( V_1 , V_35 ) << 8 ;
V_1 -> V_15 . V_18 = F_1 ( V_1 , V_36 ) ;
V_1 -> V_15 . V_18 |= F_1 ( V_1 , V_37 ) << 8 ;
V_1 -> V_5 . V_29 = & V_30 ;
V_1 -> V_5 . type = & V_38 ;
F_18 ( & V_1 -> V_5 , L_3 , F_19 ( V_5 ) ) ;
F_20 ( & V_1 -> V_5 , F_21 ( V_5 ) ) ;
F_22 ( L_4 , V_1 -> V_15 . V_17 , V_1 -> V_15 . V_18 ) ;
V_31 = F_23 ( & V_1 -> V_5 ) ;
if ( V_31 )
return V_31 ;
F_24 ( & V_1 -> V_5 , L_5 ,
V_1 -> V_15 . V_17 , V_1 -> V_15 . V_18 ) ;
return 0 ;
}
struct V_1 * F_25 ( struct V_9 * V_5 ,
const struct V_39 * V_3 )
{
struct V_1 * V_1 ;
int V_31 ;
V_1 = F_26 ( sizeof( * V_1 ) , V_40 ) ;
if ( ! V_1 )
return F_27 ( - V_21 ) ;
V_1 -> V_3 = V_3 ;
V_31 = F_17 ( V_5 , V_1 ) ;
if ( V_31 ) {
F_12 ( V_1 ) ;
return F_27 ( V_31 ) ;
}
return V_1 ;
}
void F_28 ( struct V_1 * V_1 )
{
F_29 ( & V_1 -> V_5 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_30 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_30 ) ;
}
