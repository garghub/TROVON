static T_1
F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_4 = 0 ;
V_3 -> V_5 . V_6 . V_7 = V_8 ;
F_2 ( & V_3 -> V_5 . V_6 . V_9 ) ;
V_4 = F_3 ( V_3 , - 1 ) ;
F_4 ( & V_3 -> V_10 [ V_11 ] ,
V_4 ,
1 ,
1 ) ;
return V_12 ;
}
static T_1
F_5 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_13 = 0 ;
V_3 -> V_5 . V_6 . V_7 = V_8 ;
F_2 ( & V_3 -> V_5 . V_6 . V_14 ) ;
V_13 = F_6 ( V_3 , - 1 ) ;
F_4 ( & V_3 -> V_10 [ V_15 ] ,
V_13 ,
1 ,
1 ) ;
return V_12 ;
}
static T_1
F_7 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
V_3 -> V_5 . V_6 . V_7 = V_8 ;
F_2 ( & V_3 -> V_5 . V_6 . V_16 ) ;
F_8 ( & V_3 -> V_10 [ V_17 ] ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
return V_12 ;
}
void
F_11 ( struct V_3 * V_3 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_12 ( V_3 -> V_19 ) ; V_18 ++ ) {
if ( V_3 -> V_19 [ V_18 ] . V_20 ) {
F_13 ( F_14 ( V_3 -> V_21 , V_18 ) ,
V_3 -> V_19 [ V_18 ] . V_22 ) ;
}
}
}
int
F_15 ( struct V_3 * V_3 )
{
int V_23 = 0 , V_18 ;
enum V_24 V_25 ;
V_25 = F_16 ( V_3 -> V_26 ) ;
F_17 ( V_25 != V_27 ) ;
sprintf ( V_3 -> V_19 [ V_11 ] . V_28 ,
L_1 ,
V_3 -> V_29 ) ;
V_3 -> V_19 [ V_11 ] . V_30 = F_1 ;
V_3 -> V_19 [ V_11 ] . V_22 = V_3 ;
sprintf ( V_3 -> V_19 [ V_15 ] . V_28 ,
L_2 ,
V_3 -> V_29 ) ;
V_3 -> V_19 [ V_15 ] . V_30 = F_5 ;
V_3 -> V_19 [ V_15 ] . V_22 = V_3 ;
sprintf ( V_3 -> V_19 [ V_17 ] . V_28 ,
L_3 ,
V_3 -> V_29 ) ;
V_3 -> V_19 [ V_17 ] . V_30 = F_7 ;
V_3 -> V_19 [ V_17 ] . V_22 = V_3 ;
for ( V_18 = 0 ; V_18 < F_12 ( V_3 -> V_19 ) ; V_18 ++ ) {
V_23 = F_18 ( F_14 ( V_3 -> V_21 , V_18 ) ,
V_3 -> V_19 [ V_18 ] . V_30 ,
0 ,
V_3 -> V_19 [ V_18 ] . V_28 ,
V_3 -> V_19 [ V_18 ] . V_22 ) ;
if ( V_23 ) {
F_19 ( V_3 -> V_31 ,
L_4 ,
V_18 ,
V_23 ) ;
F_11 ( V_3 ) ;
break;
}
V_3 -> V_19 [ V_18 ] . V_20 = 1 ;
}
return V_23 ;
}
int
F_20 ( struct V_3 * V_3 )
{
unsigned int V_32 = F_12 ( V_3 -> V_33 ) ;
unsigned int V_34 = V_35 ;
unsigned int V_36 = V_32 + V_34 + 1 ;
F_21 ( ( F_12 ( V_3 -> V_33 ) + V_35 ) >
F_12 ( V_3 -> V_10 ) ) ;
if ( V_3 -> V_37 < V_32 || V_3 -> V_38 < V_32 + V_34 )
goto V_39;
if ( F_22 ( V_3 -> V_21 , V_36 , V_36 , V_40 ) < 0 )
goto V_39;
V_3 -> V_37 = V_32 ;
V_3 -> V_38 = V_32 + V_34 ;
V_3 -> V_41 = V_36 ;
V_3 -> V_42 = V_17 ;
F_23 ( V_3 -> V_31 , L_5 ) ;
F_24 ( V_3 -> V_26 , V_27 ) ;
return 0 ;
V_39:
F_24 ( V_3 -> V_26 , V_43 ) ;
return - V_44 ;
}
void
F_25 ( struct V_3 * V_3 )
{
F_26 ( V_3 -> V_21 ) ;
F_24 ( V_3 -> V_26 , V_45 ) ;
}
