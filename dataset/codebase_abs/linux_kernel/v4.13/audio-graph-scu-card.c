static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_4 -> V_11 ) ;
return F_4 ( V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_4 -> V_11 ) ;
F_6 ( V_10 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
int V_11 = V_4 -> V_11 ;
V_15 = F_8 ( V_7 , V_11 ) ;
V_10 = F_3 ( V_7 , V_11 ) ;
V_13 = V_15 -> V_16 ?
V_4 -> V_17 :
V_4 -> V_18 ;
return F_9 ( V_13 , V_10 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_11 ( & V_7 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_6 * V_7 ,
unsigned int V_24 ,
int V_25 , int V_26 )
{
struct V_27 * V_28 = F_13 ( V_7 ) ;
struct V_14 * V_15 = F_8 ( V_7 , V_25 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_25 ) ;
struct V_29 * V_8 = F_14 ( V_7 ) ;
int V_30 ;
if ( V_26 ) {
V_15 -> V_31 = NULL ;
V_15 -> V_32 = L_1 ;
V_15 -> V_33 = L_2 ;
V_15 -> V_16 = 1 ;
V_15 -> V_34 = 1 ;
V_30 = F_15 ( V_23 , V_15 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_16 ( V_28 , V_23 , V_15 , V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_17 ( V_28 , V_15 ,
L_3 ,
V_15 -> V_35 ) ;
if ( V_30 < 0 )
return V_30 ;
F_18 ( V_15 ,
F_19 ( V_15 -> V_36 ) == 1 ) ;
} else {
V_15 -> V_36 = NULL ;
V_15 -> V_35 = L_1 ;
V_15 -> V_37 = L_2 ;
V_15 -> V_38 = 1 ;
V_15 -> V_39 = F_10 ;
V_30 = F_20 ( V_23 , V_15 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_21 ( V_28 , V_23 , V_15 , V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_17 ( V_28 , V_15 ,
L_4 ,
V_15 -> V_32 ) ;
if ( V_30 < 0 )
return V_30 ;
F_22 ( V_8 ,
& V_7 -> V_40 ,
V_15 -> V_31 ,
L_5 ) ;
}
V_30 = F_23 ( V_23 , V_10 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_24 ( V_15 ) ;
if ( V_30 < 0 )
return V_30 ;
V_15 -> V_41 = V_24 ;
V_15 -> V_42 = 1 ;
V_15 -> V_43 = 1 ;
V_15 -> V_44 = & V_45 ;
V_15 -> V_46 = F_7 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_47 V_48 ;
struct V_27 * V_28 = F_13 ( V_7 ) ;
struct V_29 * V_8 = F_14 ( V_7 ) ;
struct V_22 * V_49 = V_28 -> V_50 ;
struct V_22 * V_51 ;
struct V_22 * V_52 ;
struct V_22 * V_53 ;
struct V_22 * V_54 ;
struct V_22 * V_55 ;
struct V_22 * V_56 ;
unsigned int V_24 = 0 ;
int V_57 , V_30 ;
int V_58 , V_59 ;
if ( ! V_49 )
return - V_60 ;
V_30 = F_26 ( V_8 , NULL , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
F_27 ( V_28 , NULL , & V_7 -> V_21 ) ;
F_28 (&it, rc, node, L_6 , NULL, 0 ) {
V_51 = V_48 . V_49 ;
V_52 = F_29 ( V_51 , NULL ) ;
V_53 = F_30 ( V_52 ) ;
V_54 = F_30 ( V_53 ) ;
F_31 ( V_52 ) ;
F_31 ( V_53 ) ;
F_31 ( V_54 ) ;
if ( ! V_53 )
continue;
if ( V_54 != V_52 ) {
F_32 ( V_28 , L_7 ,
V_52 -> V_61 , V_53 -> V_61 , V_54 -> V_61 ) ;
V_30 = - V_60 ;
goto V_62;
}
V_30 = F_33 ( V_28 , V_52 , V_53 ,
NULL , & V_24 ) ;
if ( V_30 < 0 ) {
F_31 ( V_51 ) ;
goto V_62;
}
}
V_57 = 0 ;
V_56 = NULL ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
F_28 (&it, rc, node, L_6 , NULL, 0 ) {
V_51 = V_48 . V_49 ;
V_52 = F_29 ( V_51 , NULL ) ;
V_53 = F_30 ( V_52 ) ;
V_55 = F_34 ( V_53 ) ;
F_31 ( V_52 ) ;
F_31 ( V_53 ) ;
F_31 ( V_55 ) ;
if ( V_59 ) {
if ( ! V_55 )
continue;
if ( V_56 == V_55 )
continue;
V_56 = V_55 ;
V_30 = F_12 ( V_53 , V_7 , V_24 , V_57 ++ , 0 ) ;
if ( V_30 < 0 ) {
F_31 ( V_51 ) ;
goto V_62;
}
} else {
V_30 = F_12 ( V_52 , V_7 , V_24 , V_57 ++ , 1 ) ;
if ( V_30 < 0 ) {
F_31 ( V_51 ) ;
goto V_62;
}
}
}
}
V_30 = F_35 ( V_8 , NULL ) ;
if ( V_30 )
goto V_62;
V_30 = 0 ;
V_62:
return V_30 ;
}
static int F_36 ( struct V_27 * V_28 )
{
struct V_47 V_48 ;
struct V_22 * V_49 = V_28 -> V_50 ;
struct V_22 * V_51 ;
struct V_22 * V_52 ;
struct V_22 * V_53 ;
struct V_22 * V_55 ;
struct V_22 * V_56 ;
int V_63 = 0 ;
int V_58 ;
V_56 = NULL ;
F_28 (&it, rc, node, L_6 , NULL, 0 ) {
V_51 = V_48 . V_49 ;
V_52 = F_29 ( V_51 , NULL ) ;
V_53 = F_30 ( V_52 ) ;
V_55 = F_34 ( V_53 ) ;
F_31 ( V_52 ) ;
F_31 ( V_53 ) ;
F_31 ( V_55 ) ;
if ( V_52 )
V_63 ++ ;
if ( ! V_55 )
continue;
if ( V_56 == V_55 )
continue;
V_63 ++ ;
V_56 = V_55 ;
}
return V_63 ;
}
static int F_37 ( struct V_64 * V_65 )
{
struct V_6 * V_7 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
struct V_27 * V_28 = & V_65 -> V_28 ;
struct V_29 * V_8 ;
int V_11 , V_30 ;
V_7 = F_38 ( V_28 , sizeof( * V_7 ) , V_66 ) ;
if ( ! V_7 )
return - V_67 ;
V_11 = F_36 ( V_28 ) ;
if ( V_11 == 0 )
return - V_60 ;
V_10 = F_38 ( V_28 , sizeof( * V_10 ) * V_11 , V_66 ) ;
V_15 = F_38 ( V_28 , sizeof( * V_15 ) * V_11 , V_66 ) ;
if ( ! V_10 || ! V_15 )
return - V_67 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_15 = V_15 ;
V_8 = F_14 ( V_7 ) ;
V_8 -> V_68 = V_69 ;
V_8 -> V_28 = V_28 ;
V_8 -> V_15 = V_7 -> V_15 ;
V_8 -> V_70 = V_11 ;
V_8 -> V_40 = & V_7 -> V_40 ;
V_8 -> V_71 = 1 ;
V_30 = F_25 ( V_7 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_72 )
F_32 ( V_28 , L_8 , V_30 ) ;
goto V_73;
}
F_39 ( V_8 , V_7 ) ;
V_30 = F_40 ( V_28 , V_8 ) ;
if ( V_30 < 0 )
goto V_73;
return 0 ;
V_73:
F_41 ( V_8 ) ;
return V_30 ;
}
static int F_42 ( struct V_64 * V_65 )
{
struct V_29 * V_8 = F_43 ( V_65 ) ;
return F_41 ( V_8 ) ;
}
