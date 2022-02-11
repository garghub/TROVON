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
V_17 = F_7 ( V_2 -> V_24 . V_9 ) ;
if ( F_8 ( V_17 ) ) {
V_18 = F_9 ( V_17 ) ;
if ( V_18 != - V_22 )
goto V_25;
} else {
struct V_26 * V_27 = F_10 ( V_17 , V_7 -> V_28 ) ;
if ( F_8 ( V_27 ) ) {
V_18 = F_9 ( V_27 ) ;
goto V_25;
}
V_18 = F_11 ( V_17 , V_27 ) ;
if ( V_18 < 0 )
goto V_25;
}
V_7 -> V_10 [ V_15 ] . V_12 = V_2 ;
V_7 -> V_11 = V_15 ;
V_7 -> V_13 . V_29 = F_1 ;
V_7 -> V_13 . V_14 = F_3 ;
snprintf ( V_7 -> V_30 . V_31 , sizeof( V_7 -> V_30 . V_31 ) ,
L_1 , F_12 ( V_2 ) ) ;
V_7 -> V_30 . V_32 = V_33 ;
V_7 -> V_30 . V_13 = & V_7 -> V_13 ;
V_7 -> V_30 . V_8 = V_7 ;
V_7 -> V_30 . V_24 . V_9 = V_7 -> V_24 ;
V_7 -> V_30 . V_34 = V_2 -> V_34 ;
V_7 -> V_30 . V_35 = V_2 -> V_35 ;
V_7 -> V_30 . V_36 = V_2 -> V_36 ;
V_7 -> V_30 . V_37 = V_2 -> V_37 ;
V_7 -> V_30 . V_24 . V_38 = V_7 -> V_24 -> V_38 ;
V_18 = F_13 ( & V_7 -> V_30 ) ;
if ( V_18 < 0 )
goto V_25;
return 0 ;
V_25:
F_14 ( V_2 ) ;
V_23:
F_15 ( & V_7 -> V_10 [ V_15 ] . V_19 ) ;
V_20:
F_16 ( V_7 -> V_24 , L_2 , V_15 , V_18 ) ;
V_7 -> V_11 = - V_39 ;
return V_18 ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_18 , V_40 = V_7 -> V_11 ;
if ( V_40 < 0 )
return 0 ;
F_18 ( & V_7 -> V_30 ) ;
F_14 ( V_7 -> V_10 [ V_40 ] . V_12 ) ;
V_18 = F_15 ( & V_7 -> V_10 [ V_40 ] . V_19 ) ;
V_7 -> V_10 [ V_40 ] . V_12 = NULL ;
V_7 -> V_11 = - V_39 ;
return V_18 ;
}
static int F_19 ( struct V_6 * V_7 , T_1 V_15 )
{
int V_18 ;
if ( V_15 == V_7 -> V_11 )
return 0 ;
V_18 = F_17 ( V_7 ) ;
if ( V_18 )
return V_18 ;
return F_4 ( V_7 , V_15 ) ;
}
static T_2 F_20 ( struct V_41 * V_24 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_6 * V_7 = F_21 ( V_24 ) ;
int V_45 = 0 , V_46 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_47 && V_45 < V_48 ; V_46 ++ )
V_45 += F_22 ( V_44 + V_45 , V_48 - V_45 , L_3 ,
V_46 , V_7 -> V_10 [ V_46 ] . V_21 -> V_49 ,
V_46 == V_7 -> V_47 - 1 ? '\n' : ' ' ) ;
return V_45 ;
}
static T_2 F_23 ( struct V_41 * V_24 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_6 * V_7 = F_21 ( V_24 ) ;
return sprintf ( V_44 , L_4 , V_7 -> V_11 ) ;
}
static T_2 F_24 ( struct V_41 * V_24 ,
struct V_42 * V_43 ,
const char * V_44 , T_3 V_45 )
{
struct V_6 * V_7 = F_21 ( V_24 ) ;
unsigned int V_50 ;
int V_18 ;
V_18 = F_25 ( V_44 , 0 , & V_50 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_50 >= V_7 -> V_47 )
return - V_39 ;
V_18 = F_19 ( V_7 , V_50 ) ;
return V_18 < 0 ? V_18 : V_45 ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_24 . V_38 ;
struct V_6 * V_7 ;
struct V_55 * V_56 ;
int V_47 , V_46 , V_57 , V_20 ;
V_47 = F_27 ( V_54 , L_5 , NULL ) ;
if ( V_47 < 2 ) {
F_16 ( & V_52 -> V_24 , L_6 ) ;
return - V_39 ;
}
V_7 = F_28 ( & V_52 -> V_24 , sizeof( * V_7 )
+ V_47 * sizeof( struct V_58 ) , V_59 ) ;
V_56 = F_29 ( & V_52 -> V_24 , V_47 , sizeof( * V_56 ) , V_59 ) ;
if ( ! V_7 || ! V_56 )
return - V_60 ;
V_20 = F_30 ( V_54 , L_7 , & V_7 -> V_28 ) ;
if ( V_20 )
return V_20 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
struct V_53 * V_61 ;
V_61 = F_31 ( V_54 , L_5 , V_46 ) ;
if ( ! V_61 ) {
F_16 ( & V_52 -> V_24 , L_8 , V_46 ) ;
V_20 = - V_62 ;
goto V_63;
}
V_7 -> V_10 [ V_46 ] . V_21 = V_61 ;
V_56 [ V_46 ] . V_31 = F_32 ( & V_52 -> V_24 , L_9 , V_59 ) ;
V_56 [ V_46 ] . V_64 = F_32 ( & V_52 -> V_24 , L_10 , V_59 ) ;
V_56 [ V_46 ] . V_65 = 3 ;
F_33 ( & V_7 -> V_10 [ V_46 ] . V_19 ) ;
F_34 ( & V_7 -> V_10 [ V_46 ] . V_19 , V_61 , & V_56 [ V_46 ] ) ;
}
V_7 -> V_47 = V_47 ;
V_7 -> V_24 = & V_52 -> V_24 ;
F_35 ( V_52 , V_7 ) ;
F_4 ( V_7 , 0 ) ;
V_20 = F_36 ( & V_52 -> V_24 , & V_66 ) ;
if ( V_20 )
goto V_63;
V_20 = F_36 ( & V_52 -> V_24 , & V_67 ) ;
if ( V_20 )
goto V_68;
return 0 ;
V_68:
F_37 ( & V_52 -> V_24 , & V_66 ) ;
V_63:
for ( V_57 = 0 ; V_57 < V_46 ; V_57 ++ ) {
F_38 ( V_7 -> V_10 [ V_57 ] . V_21 ) ;
F_39 ( & V_7 -> V_10 [ V_57 ] . V_19 ) ;
}
return V_20 ;
}
static int F_40 ( struct V_51 * V_52 )
{
struct V_6 * V_7 = F_41 ( V_52 ) ;
int V_46 ;
F_37 ( & V_52 -> V_24 , & V_67 ) ;
F_37 ( & V_52 -> V_24 , & V_66 ) ;
F_17 ( V_7 ) ;
for ( V_46 = 0 ; V_46 < V_7 -> V_47 ; V_46 ++ ) {
F_38 ( V_7 -> V_10 [ V_46 ] . V_21 ) ;
F_39 ( & V_7 -> V_10 [ V_46 ] . V_19 ) ;
}
return 0 ;
}
