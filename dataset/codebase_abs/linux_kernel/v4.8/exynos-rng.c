static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_6 ;
int V_7 = 0 ;
for ( V_6 = 0 ; V_6 < 5 ; V_6 ++ )
F_3 ( V_1 , V_8 ,
V_9 + 4 * V_6 ) ;
if ( ! ( F_1 ( V_1 , V_10 )
& V_11 ) )
V_7 = - V_12 ;
return V_7 ;
}
static int F_6 ( struct V_13 * V_2 )
{
struct V_1 * V_1 = F_7 ( V_2 ,
struct V_1 , V_2 ) ;
int V_7 = 0 ;
F_8 ( V_1 -> V_14 ) ;
V_7 = F_5 ( V_1 ) ;
F_9 ( V_1 -> V_14 ) ;
F_10 ( V_1 -> V_14 ) ;
return V_7 ;
}
static int F_11 ( struct V_13 * V_2 , void * V_15 ,
T_2 V_16 , bool V_17 )
{
struct V_1 * V_1 = F_7 ( V_2 ,
struct V_1 , V_2 ) ;
T_1 * V_18 = V_15 ;
int V_19 = 100 ;
int V_7 = 4 ;
F_8 ( V_1 -> V_14 ) ;
F_3 ( V_1 , V_20 , 0 ) ;
while ( ! ( F_1 ( V_1 ,
V_10 ) & V_21 ) && -- V_19 )
F_12 () ;
if ( ! V_19 ) {
V_7 = - V_22 ;
goto V_23;
}
F_3 ( V_1 , V_21 , V_10 ) ;
* V_18 = F_1 ( V_1 , V_24 ) ;
V_23:
F_9 ( V_1 -> V_14 ) ;
F_13 ( V_1 -> V_14 ) ;
return V_7 ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_1 * V_1 ;
struct V_27 * V_28 ;
int V_7 ;
V_1 = F_15 ( & V_26 -> V_14 , sizeof( struct V_1 ) ,
V_29 ) ;
if ( ! V_1 )
return - V_30 ;
V_1 -> V_14 = & V_26 -> V_14 ;
V_1 -> V_2 . V_31 = L_1 ;
V_1 -> V_2 . V_32 = F_6 ;
V_1 -> V_2 . V_33 = F_11 ;
V_1 -> V_34 = F_16 ( & V_26 -> V_14 , L_2 ) ;
if ( F_17 ( V_1 -> V_34 ) ) {
F_18 ( & V_26 -> V_14 , L_3 ) ;
return - V_35 ;
}
V_28 = F_19 ( V_26 , V_36 , 0 ) ;
V_1 -> V_4 = F_20 ( & V_26 -> V_14 , V_28 ) ;
if ( F_17 ( V_1 -> V_4 ) )
return F_21 ( V_1 -> V_4 ) ;
F_22 ( V_26 , V_1 ) ;
F_23 ( & V_26 -> V_14 , V_37 ) ;
F_24 ( & V_26 -> V_14 ) ;
F_25 ( & V_26 -> V_14 ) ;
V_7 = F_26 ( & V_26 -> V_14 , & V_1 -> V_2 ) ;
if ( V_7 ) {
F_27 ( & V_26 -> V_14 ) ;
F_28 ( & V_26 -> V_14 ) ;
}
return V_7 ;
}
static int F_29 ( struct V_25 * V_26 )
{
F_27 ( & V_26 -> V_14 ) ;
F_28 ( & V_26 -> V_14 ) ;
return 0 ;
}
static int T_3 F_30 ( struct V_38 * V_14 )
{
struct V_25 * V_26 = F_31 ( V_14 ) ;
struct V_1 * V_1 = F_32 ( V_26 ) ;
F_33 ( V_1 -> V_34 ) ;
return 0 ;
}
static int T_3 F_34 ( struct V_38 * V_14 )
{
struct V_25 * V_26 = F_31 ( V_14 ) ;
struct V_1 * V_1 = F_32 ( V_26 ) ;
return F_35 ( V_1 -> V_34 ) ;
}
static int T_3 F_36 ( struct V_38 * V_14 )
{
return F_37 ( V_14 ) ;
}
static int T_3 F_38 ( struct V_38 * V_14 )
{
struct V_25 * V_26 = F_31 ( V_14 ) ;
struct V_1 * V_1 = F_32 ( V_26 ) ;
int V_7 ;
V_7 = F_39 ( V_14 ) ;
if ( V_7 )
return V_7 ;
return F_5 ( V_1 ) ;
}
