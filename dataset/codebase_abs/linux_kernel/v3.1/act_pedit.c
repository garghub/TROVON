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
F_11 ( V_17 ) ;
return - V_29 ;
}
V_12 = V_30 ;
} else {
V_15 = F_9 ( V_17 ) ;
if ( ! V_6 ) {
F_12 ( V_17 , V_7 , & V_26 ) ;
return - V_31 ;
}
if ( V_15 -> V_32 && V_15 -> V_32 != V_11 -> V_24 ) {
V_19 = F_10 ( V_20 , V_28 ) ;
if ( V_19 == NULL )
return - V_29 ;
}
}
F_13 ( & V_15 -> V_33 ) ;
V_15 -> V_34 = V_11 -> V_35 ;
V_15 -> V_36 = V_11 -> V_37 ;
if ( V_19 ) {
F_11 ( V_15 -> V_38 ) ;
V_15 -> V_38 = V_19 ;
V_15 -> V_32 = V_11 -> V_24 ;
}
memcpy ( V_15 -> V_38 , V_11 -> V_19 , V_20 ) ;
F_14 ( & V_15 -> V_33 ) ;
if ( V_12 == V_30 )
F_15 ( V_17 , & V_26 ) ;
return V_12 ;
}
static int F_16 ( struct V_4 * V_5 , int V_7 )
{
struct V_14 * V_15 = V_5 -> V_39 ;
if ( V_15 ) {
struct V_18 * V_19 = V_15 -> V_38 ;
if ( F_12 ( & V_15 -> V_40 , V_7 , & V_26 ) ) {
F_11 ( V_19 ) ;
return 1 ;
}
}
return 0 ;
}
static int V_14 ( struct V_41 * V_42 , const struct V_4 * V_5 ,
struct V_43 * V_44 )
{
struct V_14 * V_15 = V_5 -> V_39 ;
int V_45 , V_46 = 0 ;
unsigned int V_47 ;
if ( F_17 ( V_42 ) &&
F_18 ( V_42 , 0 , 0 , V_48 ) )
return V_15 -> V_36 ;
V_47 = F_19 ( V_42 ) ;
F_20 ( & V_15 -> V_33 ) ;
V_15 -> V_49 . V_50 = V_51 ;
if ( V_15 -> V_32 > 0 ) {
struct V_18 * V_52 = V_15 -> V_38 ;
for ( V_45 = V_15 -> V_32 ; V_45 > 0 ; V_45 -- , V_52 ++ ) {
T_1 * V_53 , V_54 ;
int V_55 = V_52 -> V_47 ;
if ( V_52 -> V_56 ) {
char * V_57 , V_58 ;
V_57 = F_21 ( V_42 , V_47 + V_52 -> V_59 , 1 ,
& V_58 ) ;
if ( ! V_57 )
goto V_60;
V_55 += ( * V_57 & V_52 -> V_56 ) >> V_52 -> V_61 ;
}
if ( V_55 % 4 ) {
F_22 ( L_1
L_2 ) ;
goto V_60;
}
if ( V_55 > 0 && V_55 > V_42 -> V_62 ) {
F_22 ( L_1
L_3 ,
V_55 , V_42 -> V_62 ) ;
goto V_60;
}
V_53 = F_21 ( V_42 , V_47 + V_55 , 4 , & V_54 ) ;
if ( ! V_53 )
goto V_60;
* V_53 = ( ( * V_53 & V_52 -> V_63 ) ^ V_52 -> V_64 ) ;
if ( V_53 == & V_54 )
F_23 ( V_42 , V_47 + V_55 , V_53 , 4 ) ;
V_46 ++ ;
}
if ( V_46 )
V_42 -> V_65 = F_24 ( V_42 -> V_65 ) ;
goto V_66;
} else
F_25 ( 1 , L_4 , V_15 -> V_67 ) ;
V_60:
V_15 -> V_68 . V_69 ++ ;
V_66:
F_26 ( & V_15 -> V_70 , V_42 ) ;
F_27 ( & V_15 -> V_33 ) ;
return V_15 -> V_36 ;
}
static int F_28 ( struct V_41 * V_42 , struct V_4 * V_5 ,
int V_7 , int V_71 )
{
unsigned char * V_72 = F_29 ( V_42 ) ;
struct V_14 * V_15 = V_5 -> V_39 ;
struct V_10 * V_73 ;
struct V_74 V_75 ;
int V_76 ;
V_76 = sizeof( * V_73 ) + V_15 -> V_32 * sizeof( struct V_18 ) ;
V_73 = F_30 ( V_76 , V_48 ) ;
if ( F_31 ( ! V_73 ) )
return - V_77 ;
memcpy ( V_73 -> V_19 , V_15 -> V_38 ,
V_15 -> V_32 * sizeof( struct V_18 ) ) ;
V_73 -> V_25 = V_15 -> V_67 ;
V_73 -> V_24 = V_15 -> V_32 ;
V_73 -> V_35 = V_15 -> V_34 ;
V_73 -> V_37 = V_15 -> V_36 ;
V_73 -> V_78 = V_15 -> V_79 - V_71 ;
V_73 -> V_80 = V_15 -> V_81 - V_7 ;
F_32 ( V_42 , V_23 , V_76 , V_73 ) ;
V_75 . V_82 = F_33 ( V_51 - V_15 -> V_49 . V_82 ) ;
V_75 . V_50 = F_33 ( V_51 - V_15 -> V_49 . V_50 ) ;
V_75 . V_83 = F_33 ( V_15 -> V_49 . V_83 ) ;
F_32 ( V_42 , V_84 , sizeof( V_75 ) , & V_75 ) ;
F_11 ( V_73 ) ;
return V_42 -> V_62 ;
V_85:
F_34 ( V_42 , V_72 ) ;
F_11 ( V_73 ) ;
return - 1 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_86 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_86 ) ;
}
