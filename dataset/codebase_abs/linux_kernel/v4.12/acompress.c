static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
strncpy ( V_6 . type , L_1 , sizeof( V_6 . type ) ) ;
if ( F_2 ( V_2 , V_7 ,
sizeof( struct V_5 ) , & V_6 ) )
goto V_8;
return 0 ;
V_8:
return - V_9 ;
}
static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return - V_10 ;
}
static void F_3 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
F_4 ( V_12 , L_2 ) ;
}
static void F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_14 ) ;
struct V_17 * V_4 = F_7 ( V_16 ) ;
V_4 -> exit ( V_16 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_14 ) ;
struct V_17 * V_4 = F_7 ( V_16 ) ;
if ( V_14 -> V_18 -> V_19 != & V_20 )
return F_9 ( V_14 ) ;
V_16 -> V_21 = V_4 -> V_21 ;
V_16 -> V_22 = V_4 -> V_22 ;
V_16 -> V_23 = V_4 -> V_23 ;
V_16 -> V_24 = V_4 -> V_24 ;
if ( V_4 -> exit )
V_16 -> V_25 . exit = F_5 ;
if ( V_4 -> V_26 )
return V_4 -> V_26 ( V_16 ) ;
return 0 ;
}
static unsigned int F_10 ( struct V_3 * V_4 )
{
int V_27 = F_11 ( V_4 ) ;
if ( V_4 -> V_19 != & V_20 )
V_27 += sizeof( struct V_28 * ) ;
return V_27 ;
}
struct V_15 * F_12 ( const char * V_29 , T_1 type ,
T_1 V_30 )
{
return F_13 ( V_29 , & V_20 , type , V_30 ) ;
}
struct V_31 * F_14 ( struct V_15 * V_16 )
{
struct V_13 * V_14 = F_15 ( V_16 ) ;
struct V_31 * V_32 ;
V_32 = F_16 ( V_16 ) ;
if ( V_32 && ( V_14 -> V_18 -> V_19 != & V_20 ) )
return F_17 ( V_32 ) ;
return V_32 ;
}
void F_18 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = F_19 ( V_32 ) ;
struct V_13 * V_14 = F_15 ( V_16 ) ;
if ( V_14 -> V_18 -> V_19 != & V_20 )
F_20 ( V_32 ) ;
if ( V_32 -> V_33 & V_34 ) {
V_16 -> V_23 ( V_32 -> V_35 ) ;
V_32 -> V_35 = NULL ;
}
F_21 ( V_32 ) ;
}
int F_22 ( struct V_17 * V_4 )
{
struct V_3 * V_25 = & V_4 -> V_25 ;
V_25 -> V_19 = & V_20 ;
V_25 -> V_36 &= ~ V_37 ;
V_25 -> V_36 |= V_38 ;
return F_23 ( V_25 ) ;
}
int F_24 ( struct V_17 * V_4 )
{
return F_25 ( & V_4 -> V_25 ) ;
}
int F_26 ( struct V_17 * V_39 , int V_40 )
{
int V_41 , V_42 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
V_42 = F_22 ( & V_39 [ V_41 ] ) ;
if ( V_42 )
goto V_43;
}
return 0 ;
V_43:
for ( -- V_41 ; V_41 >= 0 ; -- V_41 )
F_24 ( & V_39 [ V_41 ] ) ;
return V_42 ;
}
void F_27 ( struct V_17 * V_39 , int V_40 )
{
int V_41 ;
for ( V_41 = V_40 - 1 ; V_41 >= 0 ; -- V_41 )
F_24 ( & V_39 [ V_41 ] ) ;
}
