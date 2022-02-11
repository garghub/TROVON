static int F_1 ( const struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_5 ) ;
if ( V_3 )
goto V_6;
V_3 = F_3 ( V_2 -> V_7 ) ;
if ( V_3 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_2 -> V_5 ) ;
V_6:
F_5 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_6 ( const struct V_1 * V_2 )
{
F_4 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_4 ) ;
}
int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_13 = F_8 ( V_12 -> V_14 ) ;
int V_3 ;
V_3 = F_1 ( V_13 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_1 ( & V_12 -> V_2 ) ;
if ( V_3 ) {
F_6 ( V_13 ) ;
return V_3 ;
}
F_9 ( * V_12 -> V_15 , V_12 -> V_16 + V_17 ) ;
return 0 ;
}
void F_10 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_13 = F_8 ( V_12 -> V_14 ) ;
F_6 ( & V_12 -> V_2 ) ;
F_6 ( V_13 ) ;
}
static int
F_11 ( struct V_9 * V_4 , struct V_9 * V_18 , void * V_19 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
struct V_20 * V_21 = V_19 ;
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
if ( V_4 == V_21 -> V_24 [ V_22 ] . V_4 ) {
V_12 -> V_15 = & V_21 -> V_24 [ V_22 ] . V_15 ;
return 0 ;
}
}
return - V_25 ;
}
static void
F_12 ( struct V_9 * V_4 , struct V_9 * V_18 , void * V_19 )
{
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 ;
struct V_9 * V_4 = & V_27 -> V_4 ;
struct V_30 * V_31 ;
struct V_26 * V_32 ;
if ( ! V_4 -> V_33 )
return - V_34 ;
V_12 = F_14 ( V_4 , sizeof( * V_12 ) , V_35 ) ;
if ( ! V_12 )
return - V_36 ;
V_29 = F_15 ( V_27 , V_37 , 0 ) ;
V_12 -> V_16 = F_16 ( V_4 , V_29 ) ;
if ( F_17 ( V_12 -> V_16 ) )
return F_18 ( V_12 -> V_16 ) ;
V_12 -> V_2 . V_5 = F_19 ( V_4 , L_1 ) ;
if ( F_17 ( V_12 -> V_2 . V_5 ) )
return F_18 ( V_12 -> V_2 . V_5 ) ;
V_12 -> V_2 . V_7 = F_19 ( V_4 , L_2 ) ;
if ( F_17 ( V_12 -> V_2 . V_7 ) )
return F_18 ( V_12 -> V_2 . V_7 ) ;
V_12 -> V_2 . V_4 = V_4 ;
V_31 = F_20 ( V_4 -> V_38 , L_3 , 0 ) ;
if ( ! V_31 )
return - V_39 ;
V_32 = F_21 ( V_31 ) ;
F_22 ( V_31 ) ;
if ( V_32 ) {
V_12 -> V_14 = & V_32 -> V_4 ;
} else {
F_23 ( V_4 , L_4 ) ;
return - V_39 ;
}
F_24 ( V_4 ) ;
F_25 ( V_27 , V_12 ) ;
return F_26 ( V_4 , & V_40 ) ;
}
static int F_27 ( struct V_26 * V_27 )
{
F_28 ( & V_27 -> V_4 ) ;
F_29 ( & V_27 -> V_4 , & V_40 ) ;
return 0 ;
}
static int F_30 ( struct V_26 * V_27 )
{
struct V_9 * V_4 = & V_27 -> V_4 ;
struct V_1 * V_13 ;
if ( ! V_4 -> V_33 )
return - V_34 ;
V_13 = F_14 ( V_4 , sizeof( * V_13 ) , V_35 ) ;
if ( ! V_13 )
return - V_36 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_5 = F_19 ( V_4 , L_1 ) ;
if ( F_17 ( V_13 -> V_5 ) )
return F_18 ( V_13 -> V_5 ) ;
V_13 -> V_7 = F_19 ( V_4 , L_2 ) ;
if ( F_17 ( V_13 -> V_7 ) )
return F_18 ( V_13 -> V_7 ) ;
F_24 ( V_4 ) ;
F_25 ( V_27 , V_13 ) ;
return 0 ;
}
static int F_31 ( struct V_26 * V_27 )
{
F_28 ( & V_27 -> V_4 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
int V_3 ;
V_3 = F_33 ( & V_41 ) ;
if ( V_3 != 0 ) {
F_34 ( L_5 ) ;
return V_3 ;
}
V_3 = F_33 ( & V_42 ) ;
if ( V_3 != 0 ) {
F_34 ( L_6 ) ;
goto V_43;
}
return V_3 ;
V_43:
F_35 ( & V_41 ) ;
return V_3 ;
}
