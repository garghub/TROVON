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
V_18 = F_5 ( V_12 -> V_26 , V_6 , V_8 ) ;
if ( ! V_18 ) {
if ( ! V_12 -> V_25 )
return - V_22 ;
V_18 = F_6 ( V_12 -> V_26 , V_4 , V_6 , sizeof( * V_16 ) , V_8 ) ;
if ( F_7 ( V_18 ) )
return F_8 ( V_18 ) ;
V_16 = F_9 ( V_18 ) ;
V_20 = F_10 ( V_21 , V_27 ) ;
if ( V_20 == NULL ) {
if ( V_4 )
F_11 ( & V_18 -> V_28 ,
& V_18 -> V_29 ) ;
F_12 ( V_18 , V_30 ) ;
return - V_31 ;
}
V_13 = V_32 ;
} else {
V_16 = F_9 ( V_18 ) ;
F_13 ( V_18 , V_8 , V_6 -> V_33 -> V_34 ) ;
if ( V_8 )
return 0 ;
if ( ! V_7 )
return - V_35 ;
if ( V_16 -> V_36 && V_16 -> V_36 != V_12 -> V_25 ) {
V_20 = F_10 ( V_21 , V_27 ) ;
if ( V_20 == NULL )
return - V_31 ;
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
if ( V_13 == V_32 )
F_17 ( V_18 , V_6 -> V_33 -> V_34 ) ;
return V_13 ;
}
static int F_18 ( struct V_5 * V_6 , int V_8 )
{
struct V_15 * V_16 = V_6 -> V_43 ;
if ( V_16 ) {
struct V_19 * V_20 = V_16 -> V_42 ;
if ( F_13 ( & V_16 -> V_44 , V_8 , & V_45 ) ) {
F_15 ( V_20 ) ;
return 1 ;
}
}
return 0 ;
}
static int V_15 ( struct V_46 * V_47 , const struct V_5 * V_6 ,
struct V_48 * V_49 )
{
struct V_15 * V_16 = V_6 -> V_43 ;
int V_50 , V_51 = 0 ;
unsigned int V_52 ;
if ( F_19 ( V_47 , V_53 ) )
return V_16 -> V_40 ;
V_52 = F_20 ( V_47 ) ;
F_21 ( & V_16 -> V_37 ) ;
V_16 -> V_54 . V_55 = V_56 ;
if ( V_16 -> V_36 > 0 ) {
struct V_19 * V_57 = V_16 -> V_42 ;
for ( V_50 = V_16 -> V_36 ; V_50 > 0 ; V_50 -- , V_57 ++ ) {
T_1 * V_58 , V_59 ;
int V_60 = V_57 -> V_52 ;
if ( V_57 -> V_61 ) {
char * V_62 , V_63 ;
V_62 = F_22 ( V_47 , V_52 + V_57 -> V_64 , 1 ,
& V_63 ) ;
if ( ! V_62 )
goto V_65;
V_60 += ( * V_62 & V_57 -> V_61 ) >> V_57 -> V_66 ;
}
if ( V_60 % 4 ) {
F_23 ( L_1
L_2 ) ;
goto V_65;
}
if ( V_60 > 0 && V_60 > V_47 -> V_67 ) {
F_23 ( L_1
L_3 ,
V_60 , V_47 -> V_67 ) ;
goto V_65;
}
V_58 = F_22 ( V_47 , V_52 + V_60 , 4 , & V_59 ) ;
if ( ! V_58 )
goto V_65;
* V_58 = ( ( * V_58 & V_57 -> V_68 ) ^ V_57 -> V_69 ) ;
if ( V_58 == & V_59 )
F_24 ( V_47 , V_52 + V_60 , V_58 , 4 ) ;
V_51 ++ ;
}
if ( V_51 )
V_47 -> V_70 = F_25 ( V_47 -> V_70 ) ;
goto V_71;
} else
F_26 ( 1 , L_4 , V_16 -> V_72 ) ;
V_65:
V_16 -> V_73 . V_74 ++ ;
V_71:
F_27 ( & V_16 -> V_75 , V_47 ) ;
F_28 ( & V_16 -> V_37 ) ;
return V_16 -> V_40 ;
}
static int F_29 ( struct V_46 * V_47 , struct V_5 * V_6 ,
int V_8 , int V_76 )
{
unsigned char * V_77 = F_30 ( V_47 ) ;
struct V_15 * V_16 = V_6 -> V_43 ;
struct V_11 * V_78 ;
struct V_79 V_80 ;
int V_81 ;
V_81 = sizeof( * V_78 ) + V_16 -> V_36 * sizeof( struct V_19 ) ;
V_78 = F_31 ( V_81 , V_53 ) ;
if ( F_32 ( ! V_78 ) )
return - V_82 ;
memcpy ( V_78 -> V_20 , V_16 -> V_42 ,
V_16 -> V_36 * sizeof( struct V_19 ) ) ;
V_78 -> V_26 = V_16 -> V_72 ;
V_78 -> V_25 = V_16 -> V_36 ;
V_78 -> V_39 = V_16 -> V_38 ;
V_78 -> V_41 = V_16 -> V_40 ;
V_78 -> V_83 = V_16 -> V_84 - V_76 ;
V_78 -> V_85 = V_16 -> V_86 - V_8 ;
if ( F_33 ( V_47 , V_24 , V_81 , V_78 ) )
goto V_87;
V_80 . V_88 = F_34 ( V_56 - V_16 -> V_54 . V_88 ) ;
V_80 . V_55 = F_34 ( V_56 - V_16 -> V_54 . V_55 ) ;
V_80 . V_89 = F_34 ( V_16 -> V_54 . V_89 ) ;
if ( F_33 ( V_47 , V_90 , sizeof( V_80 ) , & V_80 ) )
goto V_87;
F_15 ( V_78 ) ;
return V_47 -> V_67 ;
V_87:
F_35 ( V_47 , V_77 ) ;
F_15 ( V_78 ) ;
return - 1 ;
}
static int T_2 F_36 ( void )
{
int V_14 = F_37 ( & V_45 , V_91 ) ;
if ( V_14 )
return V_14 ;
return F_38 ( & V_92 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_45 ) ;
F_41 ( & V_92 ) ;
}
