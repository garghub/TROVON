static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * V_6 ,
int V_7 , int V_8 )
{
struct V_2 * V_9 [ V_10 + 1 ] ;
struct V_11 * V_12 ;
int V_13 = 0 , V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = NULL ;
int V_21 ;
if ( V_3 == NULL )
return - V_22 ;
V_14 = F_2 ( V_9 , V_10 , V_3 , V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_9 [ V_24 ] == NULL )
return - V_22 ;
V_12 = F_3 ( V_9 [ V_24 ] ) ;
V_21 = V_12 -> V_25 * sizeof( struct V_19 ) ;
if ( F_4 ( V_9 [ V_24 ] ) < sizeof( * V_12 ) + V_21 )
return - V_22 ;
V_18 = F_5 ( V_12 -> V_26 , V_6 , V_8 , & V_27 ) ;
if ( ! V_18 ) {
if ( ! V_12 -> V_25 )
return - V_22 ;
V_18 = F_6 ( V_12 -> V_26 , V_4 , V_6 , sizeof( * V_16 ) , V_8 ,
& V_28 , & V_27 ) ;
if ( F_7 ( V_18 ) )
return F_8 ( V_18 ) ;
V_16 = F_9 ( V_18 ) ;
V_20 = F_10 ( V_21 , V_29 ) ;
if ( V_20 == NULL ) {
if ( V_4 )
F_11 ( & V_18 -> V_30 ,
& V_18 -> V_31 ) ;
F_12 ( V_18 , V_32 ) ;
return - V_33 ;
}
V_13 = V_34 ;
} else {
V_16 = F_9 ( V_18 ) ;
F_13 ( V_18 , V_8 , & V_27 ) ;
if ( V_8 )
return 0 ;
if ( ! V_7 )
return - V_35 ;
if ( V_16 -> V_36 && V_16 -> V_36 != V_12 -> V_25 ) {
V_20 = F_10 ( V_21 , V_29 ) ;
if ( V_20 == NULL )
return - V_33 ;
}
}
F_14 ( & V_16 -> V_37 ) ;
V_16 -> V_38 = V_12 -> V_39 ;
V_16 -> V_40 = V_12 -> V_41 ;
if ( V_20 ) {
F_15 ( V_16 -> V_42 ) ;
V_16 -> V_42 = V_20 ;
V_16 -> V_36 = V_12 -> V_25 ;
}
memcpy ( V_16 -> V_42 , V_12 -> V_20 , V_21 ) ;
F_16 ( & V_16 -> V_37 ) ;
if ( V_13 == V_34 )
F_17 ( V_18 , & V_27 ) ;
return V_13 ;
}
static int F_18 ( struct V_5 * V_6 , int V_8 )
{
struct V_15 * V_16 = V_6 -> V_43 ;
if ( V_16 ) {
struct V_19 * V_20 = V_16 -> V_42 ;
if ( F_13 ( & V_16 -> V_44 , V_8 , & V_27 ) ) {
F_15 ( V_20 ) ;
return 1 ;
}
}
return 0 ;
}
static int V_15 ( struct V_45 * V_46 , const struct V_5 * V_6 ,
struct V_47 * V_48 )
{
struct V_15 * V_16 = V_6 -> V_43 ;
int V_49 , V_50 = 0 ;
unsigned int V_51 ;
if ( F_19 ( V_46 , V_52 ) )
return V_16 -> V_40 ;
V_51 = F_20 ( V_46 ) ;
F_21 ( & V_16 -> V_37 ) ;
V_16 -> V_53 . V_54 = V_55 ;
if ( V_16 -> V_36 > 0 ) {
struct V_19 * V_56 = V_16 -> V_42 ;
for ( V_49 = V_16 -> V_36 ; V_49 > 0 ; V_49 -- , V_56 ++ ) {
T_1 * V_57 , V_58 ;
int V_59 = V_56 -> V_51 ;
if ( V_56 -> V_60 ) {
char * V_61 , V_62 ;
V_61 = F_22 ( V_46 , V_51 + V_56 -> V_63 , 1 ,
& V_62 ) ;
if ( ! V_61 )
goto V_64;
V_59 += ( * V_61 & V_56 -> V_60 ) >> V_56 -> V_65 ;
}
if ( V_59 % 4 ) {
F_23 ( L_1
L_2 ) ;
goto V_64;
}
if ( V_59 > 0 && V_59 > V_46 -> V_66 ) {
F_23 ( L_1
L_3 ,
V_59 , V_46 -> V_66 ) ;
goto V_64;
}
V_57 = F_22 ( V_46 , V_51 + V_59 , 4 , & V_58 ) ;
if ( ! V_57 )
goto V_64;
* V_57 = ( ( * V_57 & V_56 -> V_67 ) ^ V_56 -> V_68 ) ;
if ( V_57 == & V_58 )
F_24 ( V_46 , V_51 + V_59 , V_57 , 4 ) ;
V_50 ++ ;
}
if ( V_50 )
V_46 -> V_69 = F_25 ( V_46 -> V_69 ) ;
goto V_70;
} else
F_26 ( 1 , L_4 , V_16 -> V_71 ) ;
V_64:
V_16 -> V_72 . V_73 ++ ;
V_70:
F_27 ( & V_16 -> V_74 , V_46 ) ;
F_28 ( & V_16 -> V_37 ) ;
return V_16 -> V_40 ;
}
static int F_29 ( struct V_45 * V_46 , struct V_5 * V_6 ,
int V_8 , int V_75 )
{
unsigned char * V_76 = F_30 ( V_46 ) ;
struct V_15 * V_16 = V_6 -> V_43 ;
struct V_11 * V_77 ;
struct V_78 V_79 ;
int V_80 ;
V_80 = sizeof( * V_77 ) + V_16 -> V_36 * sizeof( struct V_19 ) ;
V_77 = F_31 ( V_80 , V_52 ) ;
if ( F_32 ( ! V_77 ) )
return - V_81 ;
memcpy ( V_77 -> V_20 , V_16 -> V_42 ,
V_16 -> V_36 * sizeof( struct V_19 ) ) ;
V_77 -> V_26 = V_16 -> V_71 ;
V_77 -> V_25 = V_16 -> V_36 ;
V_77 -> V_39 = V_16 -> V_38 ;
V_77 -> V_41 = V_16 -> V_40 ;
V_77 -> V_82 = V_16 -> V_83 - V_75 ;
V_77 -> V_84 = V_16 -> V_85 - V_8 ;
if ( F_33 ( V_46 , V_24 , V_80 , V_77 ) )
goto V_86;
V_79 . V_87 = F_34 ( V_55 - V_16 -> V_53 . V_87 ) ;
V_79 . V_54 = F_34 ( V_55 - V_16 -> V_53 . V_54 ) ;
V_79 . V_88 = F_34 ( V_16 -> V_53 . V_88 ) ;
if ( F_33 ( V_46 , V_89 , sizeof( V_79 ) , & V_79 ) )
goto V_86;
F_15 ( V_77 ) ;
return V_46 -> V_66 ;
V_86:
F_35 ( V_46 , V_76 ) ;
F_15 ( V_77 ) ;
return - 1 ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_90 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_90 ) ;
}
