static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , int V_6 , int V_7 )
{
struct V_1 * V_8 [ V_9 + 1 ] ;
struct V_10 * V_11 ;
int V_12 = 0 , V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 = NULL ;
int V_20 ;
if ( V_2 == NULL )
return - V_21 ;
V_13 = F_2 ( V_8 , V_9 , V_2 , V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_8 [ V_23 ] == NULL )
return - V_21 ;
V_11 = F_3 ( V_8 [ V_23 ] ) ;
V_20 = V_11 -> V_24 * sizeof( struct V_18 ) ;
if ( F_4 ( V_8 [ V_23 ] ) < sizeof( * V_11 ) + V_20 )
return - V_21 ;
V_17 = F_5 ( V_11 -> V_25 , V_5 , V_7 , & V_26 ) ;
if ( ! V_17 ) {
if ( ! V_11 -> V_24 )
return - V_21 ;
V_17 = F_6 ( V_11 -> V_25 , V_3 , V_5 , sizeof( * V_15 ) , V_7 ,
& V_27 , & V_26 ) ;
if ( F_7 ( V_17 ) )
return F_8 ( V_17 ) ;
V_15 = F_9 ( V_17 ) ;
V_19 = F_10 ( V_20 , V_28 ) ;
if ( V_19 == NULL ) {
if ( V_3 )
F_11 ( & V_17 -> V_29 ,
& V_17 -> V_30 ) ;
F_12 ( V_17 , V_31 ) ;
return - V_32 ;
}
V_12 = V_33 ;
} else {
V_15 = F_9 ( V_17 ) ;
if ( ! V_6 ) {
F_13 ( V_17 , V_7 , & V_26 ) ;
return - V_34 ;
}
if ( V_15 -> V_35 && V_15 -> V_35 != V_11 -> V_24 ) {
V_19 = F_10 ( V_20 , V_28 ) ;
if ( V_19 == NULL )
return - V_32 ;
}
}
F_14 ( & V_15 -> V_36 ) ;
V_15 -> V_37 = V_11 -> V_38 ;
V_15 -> V_39 = V_11 -> V_40 ;
if ( V_19 ) {
F_15 ( V_15 -> V_41 ) ;
V_15 -> V_41 = V_19 ;
V_15 -> V_35 = V_11 -> V_24 ;
}
memcpy ( V_15 -> V_41 , V_11 -> V_19 , V_20 ) ;
F_16 ( & V_15 -> V_36 ) ;
if ( V_12 == V_33 )
F_17 ( V_17 , & V_26 ) ;
return V_12 ;
}
static int F_18 ( struct V_4 * V_5 , int V_7 )
{
struct V_14 * V_15 = V_5 -> V_42 ;
if ( V_15 ) {
struct V_18 * V_19 = V_15 -> V_41 ;
if ( F_13 ( & V_15 -> V_43 , V_7 , & V_26 ) ) {
F_15 ( V_19 ) ;
return 1 ;
}
}
return 0 ;
}
static int V_14 ( struct V_44 * V_45 , const struct V_4 * V_5 ,
struct V_46 * V_47 )
{
struct V_14 * V_15 = V_5 -> V_42 ;
int V_48 , V_49 = 0 ;
unsigned int V_50 ;
if ( F_19 ( V_45 ) &&
F_20 ( V_45 , 0 , 0 , V_51 ) )
return V_15 -> V_39 ;
V_50 = F_21 ( V_45 ) ;
F_22 ( & V_15 -> V_36 ) ;
V_15 -> V_52 . V_53 = V_54 ;
if ( V_15 -> V_35 > 0 ) {
struct V_18 * V_55 = V_15 -> V_41 ;
for ( V_48 = V_15 -> V_35 ; V_48 > 0 ; V_48 -- , V_55 ++ ) {
T_1 * V_56 , V_57 ;
int V_58 = V_55 -> V_50 ;
if ( V_55 -> V_59 ) {
char * V_60 , V_61 ;
V_60 = F_23 ( V_45 , V_50 + V_55 -> V_62 , 1 ,
& V_61 ) ;
if ( ! V_60 )
goto V_63;
V_58 += ( * V_60 & V_55 -> V_59 ) >> V_55 -> V_64 ;
}
if ( V_58 % 4 ) {
F_24 ( L_1
L_2 ) ;
goto V_63;
}
if ( V_58 > 0 && V_58 > V_45 -> V_65 ) {
F_24 ( L_1
L_3 ,
V_58 , V_45 -> V_65 ) ;
goto V_63;
}
V_56 = F_23 ( V_45 , V_50 + V_58 , 4 , & V_57 ) ;
if ( ! V_56 )
goto V_63;
* V_56 = ( ( * V_56 & V_55 -> V_66 ) ^ V_55 -> V_67 ) ;
if ( V_56 == & V_57 )
F_25 ( V_45 , V_50 + V_58 , V_56 , 4 ) ;
V_49 ++ ;
}
if ( V_49 )
V_45 -> V_68 = F_26 ( V_45 -> V_68 ) ;
goto V_69;
} else
F_27 ( 1 , L_4 , V_15 -> V_70 ) ;
V_63:
V_15 -> V_71 . V_72 ++ ;
V_69:
F_28 ( & V_15 -> V_73 , V_45 ) ;
F_29 ( & V_15 -> V_36 ) ;
return V_15 -> V_39 ;
}
static int F_30 ( struct V_44 * V_45 , struct V_4 * V_5 ,
int V_7 , int V_74 )
{
unsigned char * V_75 = F_31 ( V_45 ) ;
struct V_14 * V_15 = V_5 -> V_42 ;
struct V_10 * V_76 ;
struct V_77 V_78 ;
int V_79 ;
V_79 = sizeof( * V_76 ) + V_15 -> V_35 * sizeof( struct V_18 ) ;
V_76 = F_32 ( V_79 , V_51 ) ;
if ( F_33 ( ! V_76 ) )
return - V_80 ;
memcpy ( V_76 -> V_19 , V_15 -> V_41 ,
V_15 -> V_35 * sizeof( struct V_18 ) ) ;
V_76 -> V_25 = V_15 -> V_70 ;
V_76 -> V_24 = V_15 -> V_35 ;
V_76 -> V_38 = V_15 -> V_37 ;
V_76 -> V_40 = V_15 -> V_39 ;
V_76 -> V_81 = V_15 -> V_82 - V_74 ;
V_76 -> V_83 = V_15 -> V_84 - V_7 ;
if ( F_34 ( V_45 , V_23 , V_79 , V_76 ) )
goto V_85;
V_78 . V_86 = F_35 ( V_54 - V_15 -> V_52 . V_86 ) ;
V_78 . V_53 = F_35 ( V_54 - V_15 -> V_52 . V_53 ) ;
V_78 . V_87 = F_35 ( V_15 -> V_52 . V_87 ) ;
if ( F_34 ( V_45 , V_88 , sizeof( V_78 ) , & V_78 ) )
goto V_85;
F_15 ( V_76 ) ;
return V_45 -> V_65 ;
V_85:
F_36 ( V_45 , V_75 ) ;
F_15 ( V_76 ) ;
return - 1 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_89 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_89 ) ;
}
