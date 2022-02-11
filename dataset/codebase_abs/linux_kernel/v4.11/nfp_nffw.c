static T_1 F_1 ( const struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 [ 0 ] ) >> 16 ) & 0xfff ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 [ 0 ] ) >> 0 ) & 1 ;
}
static T_1 F_4 ( const struct V_4 * V_5 )
{
return ( F_2 ( V_5 -> V_6 ) >> 31 ) & 1 ;
}
static T_1 F_5 ( const struct V_4 * V_5 )
{
return F_2 ( V_5 -> V_7 ) ;
}
static T_1 F_6 ( const struct V_4 * V_5 )
{
return ( F_2 ( V_5 -> V_6 ) >> 8 ) & 1 ;
}
static T_2 F_7 ( const struct V_4 * V_5 )
{
T_2 V_8 = F_2 ( V_5 -> V_6 ) ;
return ( V_8 & 0xFF ) << 32 | F_2 ( V_5 -> V_9 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
unsigned int V_12 , V_13 ;
T_1 V_14 , V_15 ;
int V_16 ;
V_14 = 0x000a0000 + V_17 * 4 ;
V_16 = F_9 ( V_11 , V_14 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
V_12 = F_10 ( V_15 ) ;
V_13 = ! ! ( V_15 & V_18 ) ;
return F_11 ( V_12 , V_13 ) ;
}
static unsigned int
F_12 ( struct V_1 * V_19 , struct V_4 * * V_20 )
{
switch ( F_1 ( V_19 ) ) {
case 0 :
case 1 :
* V_20 = & V_19 -> V_21 . V_22 . V_23 [ 0 ] ;
return V_24 ;
case 2 :
* V_20 = & V_19 -> V_21 . V_25 . V_23 [ 0 ] ;
return V_26 ;
default:
* V_20 = NULL ;
return 0 ;
}
}
struct V_27 * F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_19 ;
struct V_27 * V_28 ;
T_1 V_29 ;
int V_16 ;
V_28 = F_14 ( sizeof( * V_28 ) , V_30 ) ;
if ( ! V_28 )
return F_15 ( - V_31 ) ;
V_28 -> V_2 = F_16 ( V_11 , V_32 ) ;
if ( F_17 ( V_28 -> V_2 ) )
goto V_33;
V_19 = & V_28 -> V_19 ;
if ( sizeof( * V_19 ) > F_18 ( V_28 -> V_2 ) )
goto V_34;
V_16 = F_19 ( V_11 , F_20 ( V_28 -> V_2 ) ,
F_21 ( V_28 -> V_2 ) ,
V_19 , sizeof( * V_19 ) ) ;
if ( V_16 < sizeof( * V_19 ) )
goto V_34;
if ( ! F_3 ( V_19 ) )
goto V_34;
V_29 = F_1 ( V_19 ) ;
if ( V_29 > V_35 )
goto V_34;
V_28 -> V_11 = V_11 ;
return V_28 ;
V_34:
F_22 ( V_28 -> V_2 ) ;
V_33:
F_23 ( V_28 ) ;
return F_15 ( - V_36 ) ;
}
void F_24 ( struct V_27 * V_28 )
{
F_22 ( V_28 -> V_2 ) ;
F_23 ( V_28 ) ;
}
static struct V_4 * F_25 ( struct V_27 * V_28 )
{
struct V_4 * V_23 ;
unsigned int V_37 , V_38 ;
V_37 = F_12 ( & V_28 -> V_19 , & V_23 ) ;
if ( ! V_37 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
if ( F_4 ( & V_23 [ V_38 ] ) )
return & V_23 [ V_38 ] ;
return NULL ;
}
int F_26 ( struct V_27 * V_28 , T_1 * V_39 , T_2 * V_40 )
{
struct V_4 * V_23 ;
V_23 = F_25 ( V_28 ) ;
if ( ! V_23 )
return - V_41 ;
* V_39 = F_5 ( V_23 ) ;
* V_40 = F_7 ( V_23 ) ;
if ( F_6 ( V_23 ) ) {
int V_42 ;
if ( F_27 ( * V_39 ) != V_17 )
return 0 ;
V_42 = F_8 ( V_28 -> V_11 ) ;
if ( V_42 < 0 )
return V_42 ;
* V_40 &= ~ ( V_43 << V_42 ) ;
* V_40 |= V_44 << V_42 ;
}
return 0 ;
}
