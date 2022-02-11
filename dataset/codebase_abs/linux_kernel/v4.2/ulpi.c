int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
return V_1 -> V_3 -> V_4 ( V_1 -> V_3 , V_2 ) ;
}
int F_2 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_5 )
{
return V_1 -> V_3 -> V_6 ( V_1 -> V_3 , V_2 , V_5 ) ;
}
static int F_3 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_1 = F_5 ( V_8 ) ;
const struct V_13 * V_14 ;
for ( V_14 = V_12 -> V_15 ; V_14 -> V_16 ; V_14 ++ )
if ( V_14 -> V_16 == V_1 -> V_14 . V_16 &&
V_14 -> V_17 == V_1 -> V_14 . V_17 )
return 1 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 , struct V_18 * V_19 )
{
struct V_1 * V_1 = F_5 ( V_8 ) ;
if ( F_7 ( V_19 , L_1 ,
V_1 -> V_14 . V_16 , V_1 -> V_14 . V_17 ) )
return - V_20 ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_4 ( V_8 -> V_10 ) ;
return V_12 -> V_21 ( F_5 ( V_8 ) ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_4 ( V_8 -> V_10 ) ;
if ( V_12 -> remove )
V_12 -> remove ( F_5 ( V_8 ) ) ;
return 0 ;
}
static T_2 F_10 ( struct V_7 * V_8 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_1 * V_1 = F_5 ( V_8 ) ;
return sprintf ( V_24 , L_2 ,
V_1 -> V_14 . V_16 , V_1 -> V_14 . V_17 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
F_12 ( F_5 ( V_8 ) ) ;
}
int F_13 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_21 )
return - V_25 ;
V_12 -> V_10 . V_26 = & V_27 ;
return F_14 ( & V_12 -> V_10 ) ;
}
void F_15 ( struct V_11 * V_12 )
{
F_16 ( & V_12 -> V_10 ) ;
}
static int F_17 ( struct V_7 * V_8 , struct V_1 * V_1 )
{
int V_28 ;
V_28 = F_2 ( V_1 , V_29 , 0xaa ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_1 ( V_1 , V_29 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 != 0xaa )
return - V_30 ;
V_1 -> V_14 . V_16 = F_1 ( V_1 , V_31 ) ;
V_1 -> V_14 . V_16 |= F_1 ( V_1 , V_32 ) << 8 ;
V_1 -> V_14 . V_17 = F_1 ( V_1 , V_33 ) ;
V_1 -> V_14 . V_17 |= F_1 ( V_1 , V_34 ) << 8 ;
V_1 -> V_8 . V_35 = V_8 ;
V_1 -> V_8 . V_26 = & V_27 ;
V_1 -> V_8 . type = & V_36 ;
F_18 ( & V_1 -> V_8 , L_3 , F_19 ( V_8 ) ) ;
F_20 ( & V_1 -> V_8 , F_21 ( V_8 ) ) ;
F_22 ( L_4 , V_1 -> V_14 . V_16 , V_1 -> V_14 . V_17 ) ;
V_28 = F_23 ( & V_1 -> V_8 ) ;
if ( V_28 )
return V_28 ;
F_24 ( & V_1 -> V_8 , L_5 ,
V_1 -> V_14 . V_16 , V_1 -> V_14 . V_17 ) ;
return 0 ;
}
struct V_1 * F_25 ( struct V_7 * V_8 , struct V_37 * V_3 )
{
struct V_1 * V_1 ;
int V_28 ;
V_1 = F_26 ( sizeof( * V_1 ) , V_38 ) ;
if ( ! V_1 )
return F_27 ( - V_20 ) ;
V_1 -> V_3 = V_3 ;
V_3 -> V_8 = V_8 ;
V_28 = F_17 ( V_8 , V_1 ) ;
if ( V_28 ) {
F_12 ( V_1 ) ;
return F_27 ( V_28 ) ;
}
return V_1 ;
}
void F_28 ( struct V_1 * V_1 )
{
F_29 ( & V_1 -> V_8 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_27 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_27 ) ;
}
