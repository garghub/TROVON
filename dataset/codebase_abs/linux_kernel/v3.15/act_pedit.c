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
V_13 = F_6 ( V_12 -> V_24 , V_4 , V_6 , sizeof( * V_16 ) , V_8 ) ;
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
V_16 = F_7 ( V_6 ) ;
F_10 ( V_6 , V_8 ) ;
if ( V_8 )
return 0 ;
if ( ! V_7 )
return - V_28 ;
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
int V_41 , V_42 = 0 ;
unsigned int V_43 ;
if ( F_16 ( V_38 , V_44 ) )
return V_16 -> V_33 ;
V_43 = F_17 ( V_38 ) ;
F_18 ( & V_16 -> V_30 ) ;
V_16 -> V_45 . V_46 = V_47 ;
if ( V_16 -> V_29 > 0 ) {
struct V_17 * V_48 = V_16 -> V_35 ;
for ( V_41 = V_16 -> V_29 ; V_41 > 0 ; V_41 -- , V_48 ++ ) {
T_1 * V_49 , V_50 ;
int V_51 = V_48 -> V_43 ;
if ( V_48 -> V_52 ) {
char * V_53 , V_54 ;
V_53 = F_19 ( V_38 , V_43 + V_48 -> V_55 , 1 ,
& V_54 ) ;
if ( ! V_53 )
goto V_56;
V_51 += ( * V_53 & V_48 -> V_52 ) >> V_48 -> V_57 ;
}
if ( V_51 % 4 ) {
F_20 ( L_1
L_2 ) ;
goto V_56;
}
if ( V_51 > 0 && V_51 > V_38 -> V_58 ) {
F_20 ( L_1
L_3 ,
V_51 , V_38 -> V_58 ) ;
goto V_56;
}
V_49 = F_19 ( V_38 , V_43 + V_51 , 4 , & V_50 ) ;
if ( ! V_49 )
goto V_56;
* V_49 = ( ( * V_49 & V_48 -> V_59 ) ^ V_48 -> V_60 ) ;
if ( V_49 == & V_50 )
F_21 ( V_38 , V_43 + V_51 , V_49 , 4 ) ;
V_42 ++ ;
}
if ( V_42 )
V_38 -> V_61 = F_22 ( V_38 -> V_61 ) ;
goto V_62;
} else
F_23 ( 1 , L_4 , V_16 -> V_63 ) ;
V_56:
V_16 -> V_64 . V_65 ++ ;
V_62:
F_24 ( & V_16 -> V_66 , V_38 ) ;
F_25 ( & V_16 -> V_30 ) ;
return V_16 -> V_33 ;
}
static int F_26 ( struct V_37 * V_38 , struct V_5 * V_6 ,
int V_8 , int V_67 )
{
unsigned char * V_68 = F_27 ( V_38 ) ;
struct V_15 * V_16 = V_6 -> V_36 ;
struct V_11 * V_69 ;
struct V_70 V_71 ;
int V_72 ;
V_72 = sizeof( * V_69 ) + V_16 -> V_29 * sizeof( struct V_17 ) ;
V_69 = F_28 ( V_72 , V_44 ) ;
if ( F_29 ( ! V_69 ) )
return - V_73 ;
memcpy ( V_69 -> V_18 , V_16 -> V_35 ,
V_16 -> V_29 * sizeof( struct V_17 ) ) ;
V_69 -> V_24 = V_16 -> V_63 ;
V_69 -> V_23 = V_16 -> V_29 ;
V_69 -> V_32 = V_16 -> V_31 ;
V_69 -> V_34 = V_16 -> V_33 ;
V_69 -> V_74 = V_16 -> V_75 - V_67 ;
V_69 -> V_76 = V_16 -> V_77 - V_8 ;
if ( F_30 ( V_38 , V_22 , V_72 , V_69 ) )
goto V_78;
V_71 . V_79 = F_31 ( V_47 - V_16 -> V_45 . V_79 ) ;
V_71 . V_46 = F_31 ( V_47 - V_16 -> V_45 . V_46 ) ;
V_71 . V_80 = F_31 ( V_16 -> V_45 . V_80 ) ;
if ( F_30 ( V_38 , V_81 , sizeof( V_71 ) , & V_71 ) )
goto V_78;
F_12 ( V_69 ) ;
return V_38 -> V_58 ;
V_78:
F_32 ( V_38 , V_68 ) ;
F_12 ( V_69 ) ;
return - 1 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_82 , V_83 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_82 ) ;
}
