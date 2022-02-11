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
goto V_23;
}
V_17 = F_7 ( V_2 -> V_24 . V_9 , V_7 -> V_25 ) ;
if ( F_8 ( V_17 ) ) {
V_18 = F_9 ( V_17 ) ;
goto V_26;
}
V_7 -> V_10 [ V_15 ] . V_12 = V_2 ;
V_7 -> V_11 = V_15 ;
V_7 -> V_13 . V_27 = F_1 ;
V_7 -> V_13 . V_14 = F_3 ;
snprintf ( V_7 -> V_28 . V_29 , sizeof( V_7 -> V_28 . V_29 ) ,
L_1 , F_10 ( V_2 ) ) ;
V_7 -> V_28 . V_30 = V_31 ;
V_7 -> V_28 . V_13 = & V_7 -> V_13 ;
V_7 -> V_28 . V_8 = V_7 ;
V_7 -> V_28 . V_24 . V_9 = V_7 -> V_24 ;
V_7 -> V_28 . V_32 = V_2 -> V_32 ;
V_7 -> V_28 . V_33 = V_2 -> V_33 ;
V_7 -> V_28 . V_34 = V_2 -> V_34 ;
V_7 -> V_28 . V_35 = V_2 -> V_35 ;
V_7 -> V_28 . V_24 . V_36 = V_7 -> V_24 -> V_36 ;
V_18 = F_11 ( & V_7 -> V_28 ) ;
if ( V_18 < 0 )
goto V_26;
return 0 ;
V_26:
F_12 ( V_2 ) ;
V_23:
F_13 ( & V_7 -> V_10 [ V_15 ] . V_19 ) ;
V_20:
F_14 ( V_7 -> V_24 , L_2 , V_15 , V_18 ) ;
V_7 -> V_11 = - V_37 ;
return V_18 ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_18 , V_38 = V_7 -> V_11 ;
if ( V_38 < 0 )
return 0 ;
F_16 ( & V_7 -> V_28 ) ;
F_12 ( V_7 -> V_10 [ V_38 ] . V_12 ) ;
V_18 = F_13 ( & V_7 -> V_10 [ V_38 ] . V_19 ) ;
V_7 -> V_10 [ V_38 ] . V_12 = NULL ;
V_7 -> V_11 = - V_37 ;
return V_18 ;
}
static int F_17 ( struct V_6 * V_7 , T_1 V_15 )
{
int V_18 ;
if ( V_15 == V_7 -> V_11 )
return 0 ;
V_18 = F_15 ( V_7 ) ;
if ( V_18 )
return V_18 ;
return F_4 ( V_7 , V_15 ) ;
}
static T_2 F_18 ( struct V_39 * V_24 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_6 * V_7 = F_19 ( V_24 ) ;
int V_43 = 0 , V_44 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 && V_43 < V_46 ; V_44 ++ )
V_43 += F_20 ( V_42 + V_43 , V_46 - V_43 , L_3 ,
V_44 , V_7 -> V_10 [ V_44 ] . V_21 -> V_47 ,
V_44 == V_7 -> V_45 - 1 ? '\n' : ' ' ) ;
return V_43 ;
}
static T_2 F_21 ( struct V_39 * V_24 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_6 * V_7 = F_19 ( V_24 ) ;
return sprintf ( V_42 , L_4 , V_7 -> V_11 ) ;
}
static T_2 F_22 ( struct V_39 * V_24 ,
struct V_40 * V_41 ,
const char * V_42 , T_3 V_43 )
{
struct V_6 * V_7 = F_19 ( V_24 ) ;
unsigned int V_48 ;
int V_18 ;
V_18 = F_23 ( V_42 , 0 , & V_48 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_48 >= V_7 -> V_45 )
return - V_37 ;
V_18 = F_17 ( V_7 , V_48 ) ;
return V_18 < 0 ? V_18 : V_43 ;
}
static int F_24 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_24 . V_36 ;
struct V_6 * V_7 ;
struct V_53 * V_54 ;
int V_45 , V_44 , V_55 , V_20 ;
V_45 = F_25 ( V_52 , L_5 , NULL ) ;
if ( V_45 < 2 ) {
F_14 ( & V_50 -> V_24 , L_6 ) ;
return - V_37 ;
}
V_7 = F_26 ( & V_50 -> V_24 , sizeof( * V_7 )
+ V_45 * sizeof( struct V_56 ) , V_57 ) ;
V_54 = F_27 ( & V_50 -> V_24 , V_45 , sizeof( * V_54 ) , V_57 ) ;
if ( ! V_7 || ! V_54 )
return - V_58 ;
V_20 = F_28 ( V_52 , L_7 , & V_7 -> V_25 ) ;
if ( V_20 )
return V_20 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
struct V_51 * V_59 ;
V_59 = F_29 ( V_52 , L_5 , V_44 ) ;
if ( ! V_59 ) {
F_14 ( & V_50 -> V_24 , L_8 , V_44 ) ;
V_20 = - V_60 ;
goto V_61;
}
V_7 -> V_10 [ V_44 ] . V_21 = V_59 ;
V_54 [ V_44 ] . V_29 = F_30 ( & V_50 -> V_24 , L_9 , V_57 ) ;
V_54 [ V_44 ] . V_62 = F_30 ( & V_50 -> V_24 , L_10 , V_57 ) ;
V_54 [ V_44 ] . V_63 = 3 ;
F_31 ( & V_7 -> V_10 [ V_44 ] . V_19 ) ;
F_32 ( & V_7 -> V_10 [ V_44 ] . V_19 , V_59 , & V_54 [ V_44 ] ) ;
}
V_7 -> V_45 = V_45 ;
V_7 -> V_24 = & V_50 -> V_24 ;
F_33 ( V_50 , V_7 ) ;
F_4 ( V_7 , 0 ) ;
V_20 = F_34 ( & V_50 -> V_24 , & V_64 ) ;
if ( V_20 )
goto V_61;
V_20 = F_34 ( & V_50 -> V_24 , & V_65 ) ;
if ( V_20 )
goto V_66;
return 0 ;
V_66:
F_35 ( & V_50 -> V_24 , & V_64 ) ;
V_61:
for ( V_55 = 0 ; V_55 < V_44 ; V_55 ++ ) {
F_36 ( V_7 -> V_10 [ V_55 ] . V_21 ) ;
F_37 ( & V_7 -> V_10 [ V_55 ] . V_19 ) ;
}
return V_20 ;
}
static int F_38 ( struct V_49 * V_50 )
{
struct V_6 * V_7 = F_39 ( V_50 ) ;
int V_44 ;
F_35 ( & V_50 -> V_24 , & V_65 ) ;
F_35 ( & V_50 -> V_24 , & V_64 ) ;
F_15 ( V_7 ) ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
F_36 ( V_7 -> V_10 [ V_44 ] . V_21 ) ;
F_37 ( & V_7 -> V_10 [ V_44 ] . V_19 ) ;
}
return 0 ;
}
