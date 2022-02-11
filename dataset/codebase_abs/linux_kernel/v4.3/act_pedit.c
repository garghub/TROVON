static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * V_6 ,
int V_7 , int V_8 )
{
struct V_2 * V_9 [ V_10 + 1 ] ;
struct V_11 * V_12 ;
int V_13 = 0 , V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = NULL ;
int V_19 ;
if ( V_3 == NULL )
return - V_20 ;
V_14 = F_2 ( V_9 , V_10 , V_3 , V_21 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_9 [ V_22 ] == NULL )
return - V_20 ;
V_12 = F_3 ( V_9 [ V_22 ] ) ;
V_19 = V_12 -> V_23 * sizeof( struct V_17 ) ;
if ( F_4 ( V_9 [ V_22 ] ) < sizeof( * V_12 ) + V_19 )
return - V_20 ;
if ( ! F_5 ( V_12 -> V_24 , V_6 , V_8 ) ) {
if ( ! V_12 -> V_23 )
return - V_20 ;
V_13 = F_6 ( V_12 -> V_24 , V_4 , V_6 , sizeof( * V_16 ) ,
V_8 , false ) ;
if ( V_13 )
return V_13 ;
V_16 = F_7 ( V_6 ) ;
V_18 = F_8 ( V_19 , V_25 ) ;
if ( V_18 == NULL ) {
F_9 ( V_6 , V_4 ) ;
return - V_26 ;
}
V_13 = V_27 ;
} else {
if ( V_8 )
return 0 ;
F_10 ( V_6 , V_8 ) ;
if ( ! V_7 )
return - V_28 ;
V_16 = F_7 ( V_6 ) ;
if ( V_16 -> V_29 && V_16 -> V_29 != V_12 -> V_23 ) {
V_18 = F_8 ( V_19 , V_25 ) ;
if ( V_18 == NULL )
return - V_26 ;
}
}
F_11 ( & V_16 -> V_30 ) ;
V_16 -> V_31 = V_12 -> V_32 ;
V_16 -> V_33 = V_12 -> V_34 ;
if ( V_18 ) {
F_12 ( V_16 -> V_35 ) ;
V_16 -> V_35 = V_18 ;
V_16 -> V_29 = V_12 -> V_23 ;
}
memcpy ( V_16 -> V_35 , V_12 -> V_18 , V_19 ) ;
F_13 ( & V_16 -> V_30 ) ;
if ( V_13 == V_27 )
F_14 ( V_6 ) ;
return V_13 ;
}
static void F_15 ( struct V_5 * V_6 , int V_8 )
{
struct V_15 * V_16 = V_6 -> V_36 ;
struct V_17 * V_18 = V_16 -> V_35 ;
F_12 ( V_18 ) ;
}
static int V_15 ( struct V_37 * V_38 , const struct V_5 * V_6 ,
struct V_39 * V_40 )
{
struct V_15 * V_16 = V_6 -> V_36 ;
int V_41 ;
unsigned int V_42 ;
if ( F_16 ( V_38 , V_43 ) )
return V_16 -> V_33 ;
V_42 = F_17 ( V_38 ) ;
F_18 ( & V_16 -> V_30 ) ;
V_16 -> V_44 . V_45 = V_46 ;
if ( V_16 -> V_29 > 0 ) {
struct V_17 * V_47 = V_16 -> V_35 ;
for ( V_41 = V_16 -> V_29 ; V_41 > 0 ; V_41 -- , V_47 ++ ) {
T_1 * V_48 , V_49 ;
int V_50 = V_47 -> V_42 ;
if ( V_47 -> V_51 ) {
char * V_52 , V_53 ;
V_52 = F_19 ( V_38 , V_42 + V_47 -> V_54 , 1 ,
& V_53 ) ;
if ( ! V_52 )
goto V_55;
V_50 += ( * V_52 & V_47 -> V_51 ) >> V_47 -> V_56 ;
}
if ( V_50 % 4 ) {
F_20 ( L_1
L_2 ) ;
goto V_55;
}
if ( V_50 > 0 && V_50 > V_38 -> V_57 ) {
F_20 ( L_1
L_3 ,
V_50 , V_38 -> V_57 ) ;
goto V_55;
}
V_48 = F_19 ( V_38 , V_42 + V_50 , 4 , & V_49 ) ;
if ( ! V_48 )
goto V_55;
* V_48 = ( ( * V_48 & V_47 -> V_58 ) ^ V_47 -> V_59 ) ;
if ( V_48 == & V_49 )
F_21 ( V_38 , V_42 + V_50 , V_48 , 4 ) ;
}
goto V_60;
} else
F_22 ( 1 , L_4 , V_16 -> V_61 ) ;
V_55:
V_16 -> V_62 . V_63 ++ ;
V_60:
F_23 ( & V_16 -> V_64 , V_38 ) ;
F_24 ( & V_16 -> V_30 ) ;
return V_16 -> V_33 ;
}
static int F_25 ( struct V_37 * V_38 , struct V_5 * V_6 ,
int V_8 , int V_65 )
{
unsigned char * V_66 = F_26 ( V_38 ) ;
struct V_15 * V_16 = V_6 -> V_36 ;
struct V_11 * V_67 ;
struct V_68 V_69 ;
int V_70 ;
V_70 = sizeof( * V_67 ) + V_16 -> V_29 * sizeof( struct V_17 ) ;
V_67 = F_27 ( V_70 , V_43 ) ;
if ( F_28 ( ! V_67 ) )
return - V_71 ;
memcpy ( V_67 -> V_18 , V_16 -> V_35 ,
V_16 -> V_29 * sizeof( struct V_17 ) ) ;
V_67 -> V_24 = V_16 -> V_61 ;
V_67 -> V_23 = V_16 -> V_29 ;
V_67 -> V_32 = V_16 -> V_31 ;
V_67 -> V_34 = V_16 -> V_33 ;
V_67 -> V_72 = V_16 -> V_73 - V_65 ;
V_67 -> V_74 = V_16 -> V_75 - V_8 ;
if ( F_29 ( V_38 , V_22 , V_70 , V_67 ) )
goto V_76;
V_69 . V_77 = F_30 ( V_46 - V_16 -> V_44 . V_77 ) ;
V_69 . V_45 = F_30 ( V_46 - V_16 -> V_44 . V_45 ) ;
V_69 . V_78 = F_30 ( V_16 -> V_44 . V_78 ) ;
if ( F_29 ( V_38 , V_79 , sizeof( V_69 ) , & V_69 ) )
goto V_76;
F_12 ( V_67 ) ;
return V_38 -> V_57 ;
V_76:
F_31 ( V_38 , V_66 ) ;
F_12 ( V_67 ) ;
return - 1 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_80 , V_81 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_80 ) ;
}
