int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_4 ( V_2 , V_3 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= 0xff ;
* V_4 = V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , int V_9 , T_1 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_7 ( V_2 , V_3 , V_9 , V_10 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_9 ( V_2 , V_3 , V_11 ) ;
F_5 ( & V_6 -> V_8 ) ;
return V_7 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , int V_9 , T_1 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_11 ( V_2 , V_3 , V_9 , V_10 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 , T_1 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_4 ( V_2 , V_3 ) ;
if ( V_7 >= 0 ) {
T_1 V_14 = V_7 & 0xff ;
T_1 V_15 = ( V_12 & V_13 ) | ( V_14 & ( ~ V_13 ) ) ;
V_7 = F_9 ( V_2 , V_3 , V_15 ) ;
}
F_5 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 = V_2 -> V_20 . V_21 ;
int V_7 = 0 ;
V_6 = F_14 ( sizeof( struct V_5 ) , V_22 ) ;
if ( V_6 == NULL )
return - V_23 ;
F_15 ( V_2 , V_6 ) ;
V_6 -> V_20 = & V_2 -> V_20 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_17 -> V_24 ;
V_6 -> V_25 = V_2 -> V_25 ;
if ( ! V_19 )
goto V_26;
V_6 -> V_27 = V_19 -> V_27 ;
F_16 ( & V_6 -> V_8 ) ;
V_6 -> V_28 = F_17 ( V_2 -> V_29 , V_30 ) ;
F_15 ( V_6 -> V_28 , V_6 ) ;
V_6 -> V_31 = F_17 ( V_2 -> V_29 , V_32 ) ;
F_15 ( V_6 -> V_31 , V_6 ) ;
V_6 -> V_33 = F_17 ( V_2 -> V_29 , V_34 ) ;
F_15 ( V_6 -> V_33 , V_6 ) ;
F_18 ( V_6 -> V_20 ) ;
F_19 ( V_6 ) ;
F_20 ( V_6 -> V_20 , - 1 , V_35 ,
F_21 ( V_35 ) ,
NULL , 0 , NULL ) ;
if ( V_7 < 0 )
goto V_36;
F_22 ( V_6 -> V_20 , V_19 -> V_37 ) ;
return V_7 ;
V_36:
F_23 ( V_6 -> V_20 ) ;
F_24 ( V_6 -> V_33 ) ;
F_24 ( V_6 -> V_31 ) ;
F_24 ( V_6 -> V_28 ) ;
V_26:
F_25 ( V_6 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( V_6 -> V_20 ) ;
F_24 ( V_6 -> V_33 ) ;
F_24 ( V_6 -> V_31 ) ;
F_24 ( V_6 -> V_28 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
static int F_27 ( struct V_38 * V_20 )
{
struct V_1 * V_2 = F_28 ( V_20 , struct V_1 , V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < F_21 ( V_40 ) ; V_39 ++ )
F_1 ( V_2 , V_40 [ V_39 ] ,
& V_6 -> V_41 [ V_39 ] ) ;
for ( V_39 = 0 ; V_39 < F_21 ( V_42 ) ; V_39 ++ )
F_1 ( V_2 , V_42 [ V_39 ] ,
& V_6 -> V_41 [ V_39 + V_43 ] ) ;
for ( V_39 = 0 ; V_39 < F_21 ( V_44 ) ; V_39 ++ )
F_1 ( V_2 , V_44 [ V_39 ] ,
& V_6 -> V_41 [ V_39 + V_43 +
V_45 ] ) ;
return 0 ;
}
static int F_29 ( struct V_38 * V_20 )
{
struct V_1 * V_2 = F_28 ( V_20 , struct V_1 , V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < F_21 ( V_40 ) ; V_39 ++ )
F_8 ( V_2 , V_40 [ V_39 ] ,
V_6 -> V_41 [ V_39 ] ) ;
for ( V_39 = 0 ; V_39 < F_21 ( V_42 ) ; V_39 ++ )
F_8 ( V_2 , V_42 [ V_39 ] ,
V_6 -> V_41 [ V_39 + V_43 ] ) ;
for ( V_39 = 0 ; V_39 < F_21 ( V_44 ) ; V_39 ++ )
F_8 ( V_2 , V_44 [ V_39 ] ,
V_6 -> V_41 [ V_39 + V_43 +
V_45 ] ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_20 )
{
struct V_1 * V_2 = F_28 ( V_20 , struct V_1 , V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_31 ( V_20 ) )
F_32 ( V_6 -> V_25 , 1 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_20 )
{
struct V_1 * V_2 = F_28 ( V_20 , struct V_1 , V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_31 ( V_20 ) )
F_32 ( V_6 -> V_25 , 0 ) ;
return F_34 ( V_6 ) ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_46 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_46 ) ;
}
