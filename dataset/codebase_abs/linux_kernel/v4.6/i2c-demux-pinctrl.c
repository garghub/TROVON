static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_10 [ V_7 -> V_11 ] . V_12 ;
return F_2 ( V_9 , V_4 , V_5 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_10 [ V_7 -> V_11 ] . V_12 ;
return V_9 -> V_13 -> V_14 ( V_9 ) ;
}
static int F_4 ( struct V_6 * V_7 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
V_18 = F_5 ( & V_7 -> V_10 [ V_15 ] . V_19 ) ;
if ( V_18 )
goto V_20;
V_2 = F_6 ( V_7 -> V_10 [ V_15 ] . V_21 ) ;
if ( ! V_2 ) {
V_18 = - V_22 ;
goto V_20;
}
V_17 = F_7 ( V_2 -> V_23 . V_9 , V_7 -> V_24 ) ;
if ( F_8 ( V_17 ) ) {
V_18 = F_9 ( V_17 ) ;
goto V_25;
}
V_7 -> V_10 [ V_15 ] . V_12 = V_2 ;
V_7 -> V_11 = V_15 ;
V_7 -> V_13 . V_26 = F_1 ;
V_7 -> V_13 . V_14 = F_3 ;
snprintf ( V_7 -> V_27 . V_28 , sizeof( V_7 -> V_27 . V_28 ) ,
L_1 , F_10 ( V_2 ) ) ;
V_7 -> V_27 . V_29 = V_30 ;
V_7 -> V_27 . V_13 = & V_7 -> V_13 ;
V_7 -> V_27 . V_8 = V_7 ;
V_7 -> V_27 . V_23 . V_9 = V_7 -> V_23 ;
V_7 -> V_27 . V_31 = V_2 -> V_31 ;
V_7 -> V_27 . V_32 = V_2 -> V_32 ;
V_7 -> V_27 . V_33 = V_2 -> V_33 ;
V_7 -> V_27 . V_34 = V_2 -> V_34 ;
V_7 -> V_27 . V_23 . V_35 = V_7 -> V_23 -> V_35 ;
V_18 = F_11 ( & V_7 -> V_27 ) ;
if ( V_18 < 0 )
goto V_25;
return 0 ;
V_25:
F_12 ( V_2 ) ;
V_20:
F_13 ( V_7 -> V_23 , L_2 , V_15 , V_18 ) ;
return V_18 ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_18 , V_36 = V_7 -> V_11 ;
if ( V_36 < 0 )
return 0 ;
F_15 ( & V_7 -> V_27 ) ;
F_12 ( V_7 -> V_10 [ V_36 ] . V_12 ) ;
V_18 = F_16 ( & V_7 -> V_10 [ V_36 ] . V_19 ) ;
V_7 -> V_10 [ V_36 ] . V_12 = NULL ;
V_7 -> V_11 = - V_37 ;
return V_18 ;
}
static int F_17 ( struct V_6 * V_7 , T_1 V_15 )
{
int V_18 ;
if ( V_15 == V_7 -> V_11 )
return 0 ;
V_18 = F_14 ( V_7 ) ;
if ( V_18 )
return V_18 ;
return F_4 ( V_7 , V_15 ) ;
}
static T_2 F_18 ( struct V_38 * V_23 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_6 * V_7 = F_19 ( V_23 ) ;
int V_42 = 0 , V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_44 && V_42 < V_45 ; V_43 ++ )
V_42 += F_20 ( V_41 + V_42 , V_45 - V_42 , L_3 ,
V_43 , V_7 -> V_10 [ V_43 ] . V_21 -> V_46 ,
V_43 == V_7 -> V_44 - 1 ? '\n' : ' ' ) ;
return V_42 ;
}
static T_2 F_21 ( struct V_38 * V_23 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_6 * V_7 = F_19 ( V_23 ) ;
return sprintf ( V_41 , L_4 , V_7 -> V_11 ) ;
}
static T_2 F_22 ( struct V_38 * V_23 ,
struct V_39 * V_40 ,
const char * V_41 , T_3 V_42 )
{
struct V_6 * V_7 = F_19 ( V_23 ) ;
unsigned int V_47 ;
int V_18 ;
V_18 = F_23 ( V_41 , 0 , & V_47 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_47 >= V_7 -> V_44 )
return - V_37 ;
V_18 = F_17 ( V_7 , V_47 ) ;
return V_18 < 0 ? V_18 : V_42 ;
}
static int F_24 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_23 . V_35 ;
struct V_6 * V_7 ;
int V_44 , V_43 , V_52 , V_20 ;
V_44 = F_25 ( V_51 , L_5 , NULL ) ;
if ( V_44 < 2 ) {
F_13 ( & V_49 -> V_23 , L_6 ) ;
return - V_37 ;
}
V_7 = F_26 ( & V_49 -> V_23 , sizeof( * V_7 )
+ V_44 * sizeof( struct V_53 ) , V_54 ) ;
if ( ! V_7 )
return - V_55 ;
V_20 = F_27 ( V_51 , L_7 , & V_7 -> V_24 ) ;
if ( V_20 )
return V_20 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
struct V_50 * V_56 ;
V_56 = F_28 ( V_51 , L_5 , V_43 ) ;
if ( ! V_56 ) {
F_13 ( & V_49 -> V_23 , L_8 , V_43 ) ;
V_20 = - V_57 ;
goto V_58;
}
V_7 -> V_10 [ V_43 ] . V_21 = V_56 ;
F_29 ( & V_7 -> V_10 [ V_43 ] . V_19 ) ;
F_30 ( & V_7 -> V_10 [ V_43 ] . V_19 , V_56 , & V_59 ) ;
}
V_7 -> V_44 = V_44 ;
V_7 -> V_23 = & V_49 -> V_23 ;
F_31 ( V_49 , V_7 ) ;
F_4 ( V_7 , 0 ) ;
V_20 = F_32 ( & V_49 -> V_23 , & V_60 ) ;
if ( V_20 )
goto V_58;
V_20 = F_32 ( & V_49 -> V_23 , & V_61 ) ;
if ( V_20 )
goto V_62;
return 0 ;
V_62:
F_33 ( & V_49 -> V_23 , & V_60 ) ;
V_58:
for ( V_52 = 0 ; V_52 < V_43 ; V_52 ++ ) {
F_34 ( V_7 -> V_10 [ V_52 ] . V_21 ) ;
F_35 ( & V_7 -> V_10 [ V_52 ] . V_19 ) ;
}
return V_20 ;
}
static int F_36 ( struct V_48 * V_49 )
{
struct V_6 * V_7 = F_37 ( V_49 ) ;
int V_43 ;
F_33 ( & V_49 -> V_23 , & V_61 ) ;
F_33 ( & V_49 -> V_23 , & V_60 ) ;
F_14 ( V_7 ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_44 ; V_43 ++ ) {
F_34 ( V_7 -> V_10 [ V_43 ] . V_21 ) ;
F_35 ( & V_7 -> V_10 [ V_43 ] . V_19 ) ;
}
return 0 ;
}
