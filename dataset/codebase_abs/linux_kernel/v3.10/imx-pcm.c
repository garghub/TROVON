int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 -> V_10 , V_4 ,
V_6 -> V_11 , V_6 -> V_12 , V_6 -> V_13 ) ;
F_3 ( L_1 , V_14 , V_7 ,
V_6 -> V_11 ,
V_6 -> V_12 ,
V_6 -> V_13 ) ;
return V_7 ;
}
static int F_4 ( struct V_15 * V_8 , int V_16 )
{
struct V_1 * V_2 = V_8 -> V_17 [ V_16 ] . V_2 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
T_1 V_21 = V_22 ;
V_19 -> V_10 . type = V_23 ;
V_19 -> V_10 . V_10 = V_8 -> V_9 -> V_10 ;
V_19 -> V_24 = NULL ;
V_19 -> V_25 = F_5 ( V_8 -> V_9 -> V_10 , V_21 ,
& V_19 -> V_26 , V_27 ) ;
if ( ! V_19 -> V_25 )
return - V_28 ;
V_19 -> V_29 = V_21 ;
return 0 ;
}
int F_6 ( struct V_30 * V_31 )
{
struct V_32 * V_9 = V_31 -> V_9 -> V_32 ;
struct V_15 * V_8 = V_31 -> V_8 ;
int V_7 = 0 ;
if ( ! V_9 -> V_10 -> V_33 )
V_9 -> V_10 -> V_33 = & V_34 ;
if ( ! V_9 -> V_10 -> V_35 )
V_9 -> V_10 -> V_35 = F_7 ( 32 ) ;
if ( V_8 -> V_17 [ V_36 ] . V_2 ) {
V_7 = F_4 ( V_8 ,
V_36 ) ;
if ( V_7 )
goto V_37;
}
if ( V_8 -> V_17 [ V_38 ] . V_2 ) {
V_7 = F_4 ( V_8 ,
V_38 ) ;
if ( V_7 )
goto V_37;
}
V_37:
return V_7 ;
}
void F_8 ( struct V_15 * V_8 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_2 = V_8 -> V_17 [ V_16 ] . V_2 ;
if ( ! V_2 )
continue;
V_19 = & V_2 -> V_20 ;
if ( ! V_19 -> V_25 )
continue;
F_9 ( V_8 -> V_9 -> V_10 , V_19 -> V_29 ,
V_19 -> V_25 , V_19 -> V_26 ) ;
V_19 -> V_25 = NULL ;
}
}
static int F_10 ( struct V_39 * V_40 )
{
if ( strcmp ( V_40 -> V_41 -> V_42 , L_2 ) == 0 )
return F_11 ( V_40 ) ;
return F_12 ( V_40 ) ;
}
static int F_13 ( struct V_39 * V_40 )
{
if ( strcmp ( V_40 -> V_41 -> V_42 , L_2 ) == 0 )
F_14 ( & V_40 -> V_10 ) ;
else
F_15 ( V_40 ) ;
return 0 ;
}
