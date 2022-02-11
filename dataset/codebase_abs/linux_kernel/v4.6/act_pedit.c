static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * V_6 ,
int V_7 , int V_8 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
struct V_2 * V_12 [ V_13 + 1 ] ;
struct V_14 * V_15 ;
int V_16 = 0 , V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 = NULL ;
int V_22 ;
if ( V_3 == NULL )
return - V_23 ;
V_17 = F_3 ( V_12 , V_13 , V_3 , V_24 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_12 [ V_25 ] == NULL )
return - V_23 ;
V_15 = F_4 ( V_12 [ V_25 ] ) ;
V_22 = V_15 -> V_26 * sizeof( struct V_20 ) ;
if ( F_5 ( V_12 [ V_25 ] ) < sizeof( * V_15 ) + V_22 )
return - V_23 ;
if ( ! F_6 ( V_10 , V_15 -> V_27 , V_6 , V_8 ) ) {
if ( ! V_15 -> V_26 )
return - V_23 ;
V_16 = F_7 ( V_10 , V_15 -> V_27 , V_4 , V_6 ,
sizeof( * V_19 ) , V_8 , false ) ;
if ( V_16 )
return V_16 ;
V_19 = F_8 ( V_6 ) ;
V_21 = F_9 ( V_22 , V_28 ) ;
if ( V_21 == NULL ) {
F_10 ( V_6 , V_4 ) ;
return - V_29 ;
}
V_16 = V_30 ;
} else {
if ( V_8 )
return 0 ;
F_11 ( V_6 , V_8 ) ;
if ( ! V_7 )
return - V_31 ;
V_19 = F_8 ( V_6 ) ;
if ( V_19 -> V_32 && V_19 -> V_32 != V_15 -> V_26 ) {
V_21 = F_9 ( V_22 , V_28 ) ;
if ( V_21 == NULL )
return - V_29 ;
}
}
F_12 ( & V_19 -> V_33 ) ;
V_19 -> V_34 = V_15 -> V_35 ;
V_19 -> V_36 = V_15 -> V_37 ;
if ( V_21 ) {
F_13 ( V_19 -> V_38 ) ;
V_19 -> V_38 = V_21 ;
V_19 -> V_32 = V_15 -> V_26 ;
}
memcpy ( V_19 -> V_38 , V_15 -> V_21 , V_22 ) ;
F_14 ( & V_19 -> V_33 ) ;
if ( V_16 == V_30 )
F_15 ( V_10 , V_6 ) ;
return V_16 ;
}
static void F_16 ( struct V_5 * V_6 , int V_8 )
{
struct V_18 * V_19 = V_6 -> V_39 ;
struct V_20 * V_21 = V_19 -> V_38 ;
F_13 ( V_21 ) ;
}
static int V_18 ( struct V_40 * V_41 , const struct V_5 * V_6 ,
struct V_42 * V_43 )
{
struct V_18 * V_19 = V_6 -> V_39 ;
int V_44 ;
unsigned int V_45 ;
if ( F_17 ( V_41 , V_46 ) )
return V_19 -> V_36 ;
V_45 = F_18 ( V_41 ) ;
F_19 ( & V_19 -> V_33 ) ;
V_19 -> V_47 . V_48 = V_49 ;
if ( V_19 -> V_32 > 0 ) {
struct V_20 * V_50 = V_19 -> V_38 ;
for ( V_44 = V_19 -> V_32 ; V_44 > 0 ; V_44 -- , V_50 ++ ) {
T_1 * V_51 , V_52 ;
int V_53 = V_50 -> V_45 ;
if ( V_50 -> V_54 ) {
char * V_55 , V_56 ;
V_55 = F_20 ( V_41 , V_45 + V_50 -> V_57 , 1 ,
& V_56 ) ;
if ( ! V_55 )
goto V_58;
V_53 += ( * V_55 & V_50 -> V_54 ) >> V_50 -> V_59 ;
}
if ( V_53 % 4 ) {
F_21 ( L_1
L_2 ) ;
goto V_58;
}
if ( V_53 > 0 && V_53 > V_41 -> V_60 ) {
F_21 ( L_1
L_3 ,
V_53 , V_41 -> V_60 ) ;
goto V_58;
}
V_51 = F_20 ( V_41 , V_45 + V_53 , 4 , & V_52 ) ;
if ( ! V_51 )
goto V_58;
* V_51 = ( ( * V_51 & V_50 -> V_61 ) ^ V_50 -> V_62 ) ;
if ( V_51 == & V_52 )
F_22 ( V_41 , V_45 + V_53 , V_51 , 4 ) ;
}
goto V_63;
} else
F_23 ( 1 , L_4 , V_19 -> V_64 ) ;
V_58:
V_19 -> V_65 . V_66 ++ ;
V_63:
F_24 ( & V_19 -> V_67 , V_41 ) ;
F_25 ( & V_19 -> V_33 ) ;
return V_19 -> V_36 ;
}
static int F_26 ( struct V_40 * V_41 , struct V_5 * V_6 ,
int V_8 , int V_68 )
{
unsigned char * V_69 = F_27 ( V_41 ) ;
struct V_18 * V_19 = V_6 -> V_39 ;
struct V_14 * V_70 ;
struct V_71 V_72 ;
int V_73 ;
V_73 = sizeof( * V_70 ) + V_19 -> V_32 * sizeof( struct V_20 ) ;
V_70 = F_28 ( V_73 , V_46 ) ;
if ( F_29 ( ! V_70 ) )
return - V_74 ;
memcpy ( V_70 -> V_21 , V_19 -> V_38 ,
V_19 -> V_32 * sizeof( struct V_20 ) ) ;
V_70 -> V_27 = V_19 -> V_64 ;
V_70 -> V_26 = V_19 -> V_32 ;
V_70 -> V_35 = V_19 -> V_34 ;
V_70 -> V_37 = V_19 -> V_36 ;
V_70 -> V_75 = V_19 -> V_76 - V_68 ;
V_70 -> V_77 = V_19 -> V_78 - V_8 ;
if ( F_30 ( V_41 , V_25 , V_73 , V_70 ) )
goto V_79;
V_72 . V_80 = F_31 ( V_49 - V_19 -> V_47 . V_80 ) ;
V_72 . V_48 = F_31 ( V_49 - V_19 -> V_47 . V_48 ) ;
V_72 . V_81 = F_31 ( V_19 -> V_47 . V_81 ) ;
if ( F_30 ( V_41 , V_82 , sizeof( V_72 ) , & V_72 ) )
goto V_79;
F_13 ( V_70 ) ;
return V_41 -> V_60 ;
V_79:
F_32 ( V_41 , V_69 ) ;
F_13 ( V_70 ) ;
return - 1 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_40 * V_41 ,
struct V_83 * V_84 , int type ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_34 ( V_10 , V_41 , V_84 , type , V_6 ) ;
}
static int F_35 ( struct V_1 * V_1 , struct V_5 * V_6 , T_1 V_27 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_36 ( V_10 , V_6 , V_27 ) ;
}
static T_2 int F_37 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_38 ( V_10 , & V_85 , V_86 ) ;
}
static void T_3 F_39 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_40 ( V_10 ) ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_85 , & V_87 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_85 , & V_87 ) ;
}
