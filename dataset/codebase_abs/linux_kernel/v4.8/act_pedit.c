static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * * V_6 ,
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
& V_28 , V_8 , false ) ;
if ( V_16 )
return V_16 ;
V_19 = F_8 ( * V_6 ) ;
V_21 = F_9 ( V_22 , V_29 ) ;
if ( V_21 == NULL ) {
F_10 ( * V_6 , V_4 ) ;
return - V_30 ;
}
V_16 = V_31 ;
} else {
if ( V_8 )
return 0 ;
F_11 ( * V_6 , V_8 ) ;
if ( ! V_7 )
return - V_32 ;
V_19 = F_8 ( * V_6 ) ;
if ( V_19 -> V_33 && V_19 -> V_33 != V_15 -> V_26 ) {
V_21 = F_9 ( V_22 , V_29 ) ;
if ( V_21 == NULL )
return - V_30 ;
}
}
F_12 ( & V_19 -> V_34 ) ;
V_19 -> V_35 = V_15 -> V_36 ;
V_19 -> V_37 = V_15 -> V_38 ;
if ( V_21 ) {
F_13 ( V_19 -> V_39 ) ;
V_19 -> V_39 = V_21 ;
V_19 -> V_33 = V_15 -> V_26 ;
}
memcpy ( V_19 -> V_39 , V_15 -> V_21 , V_22 ) ;
F_14 ( & V_19 -> V_34 ) ;
if ( V_16 == V_31 )
F_15 ( V_10 , * V_6 ) ;
return V_16 ;
}
static void F_16 ( struct V_5 * V_6 , int V_8 )
{
struct V_18 * V_19 = F_8 ( V_6 ) ;
struct V_20 * V_21 = V_19 -> V_39 ;
F_13 ( V_21 ) ;
}
static int V_18 ( struct V_40 * V_41 , const struct V_5 * V_6 ,
struct V_42 * V_43 )
{
struct V_18 * V_19 = F_8 ( V_6 ) ;
int V_44 ;
unsigned int V_45 ;
if ( F_17 ( V_41 , V_46 ) )
return V_19 -> V_37 ;
V_45 = F_18 ( V_41 ) ;
F_19 ( & V_19 -> V_34 ) ;
F_20 ( & V_19 -> V_47 ) ;
if ( V_19 -> V_33 > 0 ) {
struct V_20 * V_48 = V_19 -> V_39 ;
for ( V_44 = V_19 -> V_33 ; V_44 > 0 ; V_44 -- , V_48 ++ ) {
T_1 * V_49 , V_50 ;
int V_51 = V_48 -> V_45 ;
if ( V_48 -> V_52 ) {
char * V_53 , V_54 ;
V_53 = F_21 ( V_41 , V_45 + V_48 -> V_55 , 1 ,
& V_54 ) ;
if ( ! V_53 )
goto V_56;
V_51 += ( * V_53 & V_48 -> V_52 ) >> V_48 -> V_57 ;
}
if ( V_51 % 4 ) {
F_22 ( L_1
L_2 ) ;
goto V_56;
}
if ( V_51 > 0 && V_51 > V_41 -> V_58 ) {
F_22 ( L_1
L_3 ,
V_51 , V_41 -> V_58 ) ;
goto V_56;
}
V_49 = F_21 ( V_41 , V_45 + V_51 , 4 , & V_50 ) ;
if ( ! V_49 )
goto V_56;
* V_49 = ( ( * V_49 & V_48 -> V_59 ) ^ V_48 -> V_60 ) ;
if ( V_49 == & V_50 )
F_23 ( V_41 , V_45 + V_51 , V_49 , 4 ) ;
}
goto V_61;
} else
F_24 ( 1 , L_4 , V_19 -> V_62 ) ;
V_56:
V_19 -> V_63 . V_64 ++ ;
V_61:
F_25 ( & V_19 -> V_65 , V_41 ) ;
F_26 ( & V_19 -> V_34 ) ;
return V_19 -> V_37 ;
}
static int F_27 ( struct V_40 * V_41 , struct V_5 * V_6 ,
int V_8 , int V_66 )
{
unsigned char * V_67 = F_28 ( V_41 ) ;
struct V_18 * V_19 = F_8 ( V_6 ) ;
struct V_14 * V_68 ;
struct V_69 V_70 ;
int V_71 ;
V_71 = sizeof( * V_68 ) + V_19 -> V_33 * sizeof( struct V_20 ) ;
V_68 = F_29 ( V_71 , V_46 ) ;
if ( F_30 ( ! V_68 ) )
return - V_72 ;
memcpy ( V_68 -> V_21 , V_19 -> V_39 ,
V_19 -> V_33 * sizeof( struct V_20 ) ) ;
V_68 -> V_27 = V_19 -> V_62 ;
V_68 -> V_26 = V_19 -> V_33 ;
V_68 -> V_36 = V_19 -> V_35 ;
V_68 -> V_38 = V_19 -> V_37 ;
V_68 -> V_73 = V_19 -> V_74 - V_66 ;
V_68 -> V_75 = V_19 -> V_76 - V_8 ;
if ( F_31 ( V_41 , V_25 , V_71 , V_68 ) )
goto V_77;
F_32 ( & V_70 , & V_19 -> V_47 ) ;
if ( F_33 ( V_41 , V_78 , sizeof( V_70 ) , & V_70 , V_79 ) )
goto V_77;
F_13 ( V_68 ) ;
return V_41 -> V_58 ;
V_77:
F_34 ( V_41 , V_67 ) ;
F_13 ( V_68 ) ;
return - 1 ;
}
static int F_35 ( struct V_1 * V_1 , struct V_40 * V_41 ,
struct V_80 * V_81 , int type ,
const struct V_82 * V_83 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_36 ( V_10 , V_41 , V_81 , type , V_83 ) ;
}
static int F_37 ( struct V_1 * V_1 , struct V_5 * * V_6 , T_1 V_27 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_38 ( V_10 , V_6 , V_27 ) ;
}
static T_2 int F_39 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_40 ( V_10 , & V_28 , V_84 ) ;
}
static void T_3 F_41 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_42 ( V_10 ) ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_28 , & V_85 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_28 , & V_85 ) ;
}
