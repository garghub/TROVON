static int F_1 ( struct V_1 * V_2 ,
char * V_3 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_13 = V_2 -> V_14 ;
V_9 = & V_2 -> V_15 [ V_4 ] ;
V_11 = & V_2 -> V_16 [ V_4 * 3 ] ;
V_7 = & V_2 -> V_7 [ V_4 ] ;
V_9 -> V_3 = V_3 ;
V_9 -> V_16 = V_11 ;
V_9 -> V_17 = 3 ;
V_9 -> V_18 = V_19 ++ ;
V_7 -> V_5 = V_5 ;
V_9 -> V_20 = V_7 ;
V_9 -> V_21 = sizeof( * V_7 ) ;
V_11 -> V_22 = V_23 ;
V_11 -> V_24 = & V_13 -> V_10 [ 3 ] ;
V_11 -> V_25 = V_13 -> V_10 [ 3 ] . V_25 + ( V_26 * V_5 ) ;
V_11 -> V_27 = V_11 -> V_25 + V_26 - 1 ;
V_11 ++ ;
V_11 -> V_22 = V_23 ;
V_11 -> V_24 = & V_13 -> V_10 [ 4 ] ;
V_11 -> V_25 = V_13 -> V_10 [ 4 ] . V_25 ;
V_11 -> V_27 = V_13 -> V_10 [ 4 ] . V_27 ;
V_11 ++ ;
V_11 -> V_22 = V_28 ;
V_11 -> V_24 = NULL ;
V_11 -> V_25 = 0 ;
V_11 -> V_27 = 0 ;
V_11 ++ ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_12 * V_14 = V_2 -> V_14 ;
unsigned int V_29 = 0 ;
char * V_3 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_3 = V_32 [ V_30 ] ;
if ( ! strcmp ( V_3 , L_1 ) || ! strcmp ( V_3 , L_2 ) )
continue;
F_3 ( & V_2 -> V_14 -> V_33 , L_3 , V_30 , V_3 ) ;
F_1 ( V_2 , V_3 , V_29 , V_30 ) ;
V_29 ++ ;
}
if ( V_29 == 0 ) {
F_4 ( & V_2 -> V_14 -> V_33 , L_4
L_5
L_6
L_7 ) ;
return - V_34 ;
}
return F_5 ( & V_14 -> V_33 , 0 , V_2 -> V_15 ,
V_29 , NULL , V_14 -> V_35 , NULL ) ;
}
static T_1 F_6 ( struct V_36 * V_33 , struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_2 = F_7 ( V_33 ) ;
return snprintf ( V_39 , V_40 , L_8 , V_2 -> V_41 ) ;
}
static int F_8 ( struct V_12 * V_33 ,
const struct V_42 * V_18 )
{
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_9 ( & V_33 -> V_33 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 ) {
F_4 ( & V_33 -> V_33 , L_9 ) ;
return - V_45 ;
}
F_10 ( V_33 , V_2 ) ;
V_2 -> V_14 = V_33 ;
V_43 = F_11 ( V_33 ) ;
if ( V_43 ) {
F_4 ( & V_33 -> V_33 , L_10 ) ;
return V_43 ;
}
F_12 ( V_33 ) ;
V_43 = F_13 ( V_33 , V_46 ) ;
if ( V_43 ) {
F_4 ( & V_33 -> V_33 , L_11 ) ;
goto V_47;
}
V_2 -> V_48 = F_14 ( V_33 , 4 ) ;
if ( ! V_2 -> V_48 ) {
F_4 ( & V_33 -> V_33 , L_12 ) ;
V_43 = - V_45 ;
goto V_49;
}
V_2 -> V_41 = F_15 ( & V_2 -> V_48 -> V_50 ) ;
V_43 = F_16 ( & V_33 -> V_33 . V_51 , & V_52 ) ;
if ( V_43 ) {
F_4 ( & V_33 -> V_33 , L_13 ) ;
goto V_53;
}
F_17 ( 0xf , & V_2 -> V_48 -> V_54 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_43 ) {
F_4 ( & V_33 -> V_33 , L_14 ) ;
goto V_55;
}
return 0 ;
V_55:
F_18 ( & V_33 -> V_33 . V_51 , & V_52 ) ;
V_53:
F_19 ( V_2 -> V_48 ) ;
V_49:
F_20 ( V_33 ) ;
V_47:
F_21 ( V_33 ) ;
return V_43 ;
}
static void F_22 ( struct V_12 * V_33 )
{
struct V_1 * V_2 = F_23 ( V_33 ) ;
F_24 ( & V_33 -> V_33 ) ;
F_18 ( & V_33 -> V_33 . V_51 , & V_52 ) ;
F_19 ( V_2 -> V_48 ) ;
F_20 ( V_33 ) ;
F_21 ( V_33 ) ;
}
