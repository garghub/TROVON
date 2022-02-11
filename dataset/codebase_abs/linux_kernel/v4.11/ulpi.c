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
if ( V_1 -> V_15 . V_16 == 0 )
return F_6 ( V_5 , V_11 ) ;
for ( V_15 = V_13 -> V_17 ; V_15 -> V_16 ; V_15 ++ )
if ( V_15 -> V_16 == V_1 -> V_15 . V_16 &&
V_15 -> V_18 == V_1 -> V_15 . V_18 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_5 , struct V_19 * V_20 )
{
struct V_1 * V_1 = F_5 ( V_5 ) ;
int V_21 ;
V_21 = F_8 ( V_5 , V_20 ) ;
if ( V_21 != - V_22 )
return V_21 ;
if ( F_9 ( V_20 , L_1 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_18 ) )
return - V_23 ;
return 0 ;
}
static int F_10 ( struct V_9 * V_5 )
{
struct V_12 * V_13 = F_4 ( V_5 -> V_11 ) ;
int V_21 ;
V_21 = F_11 ( V_5 -> V_24 , false ) ;
if ( V_21 < 0 )
return V_21 ;
return V_13 -> V_25 ( F_5 ( V_5 ) ) ;
}
static int F_12 ( struct V_9 * V_5 )
{
struct V_12 * V_13 = F_4 ( V_5 -> V_11 ) ;
if ( V_13 -> remove )
V_13 -> remove ( F_5 ( V_5 ) ) ;
return 0 ;
}
static T_2 F_13 ( struct V_9 * V_5 , struct V_26 * V_27 ,
char * V_28 )
{
int V_29 ;
struct V_1 * V_1 = F_5 ( V_5 ) ;
V_29 = F_14 ( V_5 , V_28 , V_30 - 1 ) ;
if ( V_29 != - V_22 )
return V_29 ;
return sprintf ( V_28 , L_2 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_18 ) ;
}
static void F_15 ( struct V_9 * V_5 )
{
F_16 ( F_5 ( V_5 ) ) ;
}
int F_17 ( struct V_12 * V_13 , struct V_31 * V_31 )
{
if ( ! V_13 -> V_25 )
return - V_32 ;
V_13 -> V_11 . V_33 = V_31 ;
V_13 -> V_11 . V_34 = & V_35 ;
return F_18 ( & V_13 -> V_11 ) ;
}
void F_19 ( struct V_12 * V_13 )
{
F_20 ( & V_13 -> V_11 ) ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_36 * V_37 = NULL , * V_38 ;
struct V_9 * V_6 ;
V_6 = V_1 -> V_5 . V_6 ;
if ( V_6 -> V_24 )
V_37 = F_22 ( V_6 -> V_24 , L_3 ) ;
else if ( V_6 -> V_6 && V_6 -> V_6 -> V_24 )
V_37 = F_22 ( V_6 -> V_6 -> V_24 , L_3 ) ;
if ( ! V_37 )
return 0 ;
V_38 = F_23 ( V_37 , NULL ) ;
F_24 ( V_37 ) ;
if ( ! V_38 )
return - V_32 ;
V_1 -> V_5 . V_24 = V_38 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
int V_21 ;
V_21 = F_2 ( V_1 , V_39 , 0xaa ) ;
if ( V_21 < 0 )
goto V_40;
V_21 = F_1 ( V_1 , V_39 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != 0xaa )
goto V_40;
V_1 -> V_15 . V_16 = F_1 ( V_1 , V_41 ) ;
V_1 -> V_15 . V_16 |= F_1 ( V_1 , V_42 ) << 8 ;
V_1 -> V_15 . V_18 = F_1 ( V_1 , V_43 ) ;
V_1 -> V_15 . V_18 |= F_1 ( V_1 , V_44 ) << 8 ;
if ( V_1 -> V_15 . V_16 == 0 )
goto V_40;
F_26 ( L_4 , V_1 -> V_15 . V_16 , V_1 -> V_15 . V_18 ) ;
return 0 ;
V_40:
F_27 ( & V_1 -> V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_9 * V_5 , struct V_1 * V_1 )
{
int V_21 ;
V_1 -> V_5 . V_6 = V_5 ;
V_1 -> V_5 . V_34 = & V_35 ;
V_1 -> V_5 . type = & V_45 ;
F_29 ( & V_1 -> V_5 , L_5 , F_30 ( V_5 ) ) ;
F_31 ( & V_1 -> V_5 , F_32 ( V_5 ) ) ;
V_21 = F_21 ( V_1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_33 ( & V_1 -> V_5 ) ;
if ( V_21 )
return V_21 ;
F_34 ( & V_1 -> V_5 , L_6 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_18 ) ;
return 0 ;
}
struct V_1 * F_35 ( struct V_9 * V_5 ,
const struct V_46 * V_3 )
{
struct V_1 * V_1 ;
int V_21 ;
V_1 = F_36 ( sizeof( * V_1 ) , V_47 ) ;
if ( ! V_1 )
return F_37 ( - V_23 ) ;
V_1 -> V_3 = V_3 ;
V_21 = F_28 ( V_5 , V_1 ) ;
if ( V_21 ) {
F_16 ( V_1 ) ;
return F_37 ( V_21 ) ;
}
return V_1 ;
}
void F_38 ( struct V_1 * V_1 )
{
F_24 ( V_1 -> V_5 . V_24 ) ;
F_39 ( & V_1 -> V_5 ) ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_35 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_35 ) ;
}
