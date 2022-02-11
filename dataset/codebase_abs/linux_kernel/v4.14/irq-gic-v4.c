int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_2 -> V_5 = F_2 ( L_1 ,
F_3 ( V_6 ) ) ;
if ( ! V_2 -> V_5 )
goto V_7;
V_2 -> V_8 = F_4 ( V_9 , 0 , V_2 -> V_10 ,
V_2 -> V_5 , V_11 ,
V_2 ) ;
if ( ! V_2 -> V_8 )
goto V_7;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 ; V_4 ++ ) {
V_2 -> V_12 [ V_4 ] -> V_1 = V_2 ;
V_2 -> V_12 [ V_4 ] -> V_13 = true ;
}
V_3 = F_5 ( V_2 -> V_8 , - 1 , V_2 -> V_10 ,
V_14 , V_2 ,
false , NULL ) ;
if ( V_3 <= 0 )
goto V_7;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 ; V_4 ++ )
V_2 -> V_12 [ V_4 ] -> V_15 = V_3 + V_4 ;
return 0 ;
V_7:
if ( V_2 -> V_8 )
F_6 ( V_2 -> V_8 ) ;
if ( V_2 -> V_5 )
F_7 ( V_2 -> V_5 ) ;
return - V_16 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 [ 0 ] -> V_15 , V_2 -> V_10 ) ;
F_6 ( V_2 -> V_8 ) ;
F_7 ( V_2 -> V_5 ) ;
}
static int F_10 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
return F_11 ( V_18 -> V_15 , V_20 ) ;
}
int F_12 ( struct V_17 * V_18 , bool V_21 )
{
struct V_19 V_20 ;
F_13 ( F_14 () ) ;
V_20 . V_22 = V_21 ? V_23 : V_24 ;
return F_10 ( V_18 , & V_20 ) ;
}
int F_15 ( struct V_17 * V_18 )
{
struct V_19 V_20 = {
. V_22 = V_25 ,
} ;
return F_10 ( V_18 , & V_20 ) ;
}
int F_16 ( int V_15 , struct V_26 * V_27 )
{
struct V_19 V_20 = {
. V_22 = V_28 ,
{
. V_27 = V_27 ,
} ,
} ;
F_17 ( V_15 , V_29 ) ;
return F_11 ( V_15 , & V_20 ) ;
}
int F_18 ( int V_15 , struct V_26 * V_27 )
{
struct V_19 V_20 = {
. V_22 = V_30 ,
{
. V_27 = V_27 ,
} ,
} ;
return F_11 ( V_15 , & V_20 ) ;
}
int F_19 ( int V_15 )
{
F_20 ( V_15 , V_29 ) ;
return F_11 ( V_15 , NULL ) ;
}
int F_21 ( int V_15 , T_1 V_31 , bool V_32 )
{
struct V_19 V_20 = {
. V_22 = V_32 ? V_33 : V_34 ,
{
. V_31 = V_31 ,
} ,
} ;
return F_11 ( V_15 , & V_20 ) ;
}
int F_22 ( struct V_35 * V_8 , const struct V_36 * V_37 )
{
if ( V_8 ) {
F_23 ( L_2 ) ;
V_9 = V_8 ;
V_11 = V_37 ;
return 0 ;
}
F_24 ( L_3 ) ;
return - V_38 ;
}
