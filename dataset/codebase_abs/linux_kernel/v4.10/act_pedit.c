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
static bool F_17 ( struct V_40 * V_41 , int V_42 )
{
if ( V_42 > 0 && V_42 > V_41 -> V_43 )
return false ;
if ( V_42 < 0 && - V_42 > F_18 ( V_41 ) )
return false ;
return true ;
}
static int V_18 ( struct V_40 * V_41 , const struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_18 * V_19 = F_8 ( V_6 ) ;
int V_46 ;
unsigned int V_47 ;
if ( F_19 ( V_41 , V_48 ) )
return V_19 -> V_37 ;
V_47 = F_20 ( V_41 ) ;
F_21 ( & V_19 -> V_34 ) ;
F_22 ( & V_19 -> V_49 ) ;
if ( V_19 -> V_33 > 0 ) {
struct V_20 * V_50 = V_19 -> V_39 ;
for ( V_46 = V_19 -> V_33 ; V_46 > 0 ; V_46 -- , V_50 ++ ) {
T_1 * V_51 , V_52 ;
int V_42 = V_50 -> V_47 ;
if ( V_50 -> V_53 ) {
char * V_54 , V_55 ;
if ( ! F_17 ( V_41 , V_47 + V_50 -> V_56 ) ) {
F_23 ( L_1 ,
V_47 + V_50 -> V_56 ) ;
goto V_57;
}
V_54 = F_24 ( V_41 , V_47 + V_50 -> V_56 , 1 ,
& V_55 ) ;
if ( ! V_54 )
goto V_57;
V_42 += ( * V_54 & V_50 -> V_53 ) >> V_50 -> V_58 ;
}
if ( V_42 % 4 ) {
F_23 ( L_2
L_3 ) ;
goto V_57;
}
if ( ! F_17 ( V_41 , V_47 + V_42 ) ) {
F_23 ( L_4 ,
V_42 ) ;
goto V_57;
}
V_51 = F_24 ( V_41 , V_47 + V_42 , 4 , & V_52 ) ;
if ( ! V_51 )
goto V_57;
* V_51 = ( ( * V_51 & V_50 -> V_59 ) ^ V_50 -> V_60 ) ;
if ( V_51 == & V_52 )
F_25 ( V_41 , V_47 + V_42 , V_51 , 4 ) ;
}
goto V_61;
} else
F_26 ( 1 , L_5 , V_19 -> V_62 ) ;
V_57:
V_19 -> V_63 . V_64 ++ ;
V_61:
F_27 ( & V_19 -> V_65 , V_41 ) ;
F_28 ( & V_19 -> V_34 ) ;
return V_19 -> V_37 ;
}
static int F_29 ( struct V_40 * V_41 , struct V_5 * V_6 ,
int V_8 , int V_66 )
{
unsigned char * V_67 = F_30 ( V_41 ) ;
struct V_18 * V_19 = F_8 ( V_6 ) ;
struct V_14 * V_68 ;
struct V_69 V_70 ;
int V_71 ;
V_71 = sizeof( * V_68 ) + V_19 -> V_33 * sizeof( struct V_20 ) ;
V_68 = F_31 ( V_71 , V_48 ) ;
if ( F_32 ( ! V_68 ) )
return - V_72 ;
memcpy ( V_68 -> V_21 , V_19 -> V_39 ,
V_19 -> V_33 * sizeof( struct V_20 ) ) ;
V_68 -> V_27 = V_19 -> V_62 ;
V_68 -> V_26 = V_19 -> V_33 ;
V_68 -> V_36 = V_19 -> V_35 ;
V_68 -> V_38 = V_19 -> V_37 ;
V_68 -> V_73 = V_19 -> V_74 - V_66 ;
V_68 -> V_75 = V_19 -> V_76 - V_8 ;
if ( F_33 ( V_41 , V_25 , V_71 , V_68 ) )
goto V_77;
F_34 ( & V_70 , & V_19 -> V_49 ) ;
if ( F_35 ( V_41 , V_78 , sizeof( V_70 ) , & V_70 , V_79 ) )
goto V_77;
F_13 ( V_68 ) ;
return V_41 -> V_43 ;
V_77:
F_36 ( V_41 , V_67 ) ;
F_13 ( V_68 ) ;
return - 1 ;
}
static int F_37 ( struct V_1 * V_1 , struct V_40 * V_41 ,
struct V_80 * V_81 , int type ,
const struct V_82 * V_83 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_38 ( V_10 , V_41 , V_81 , type , V_83 ) ;
}
static int F_39 ( struct V_1 * V_1 , struct V_5 * * V_6 , T_1 V_27 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_40 ( V_10 , V_6 , V_27 ) ;
}
static T_2 int F_41 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_42 ( V_10 , & V_28 , V_84 ) ;
}
static void T_3 F_43 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_44 ( V_10 ) ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_28 , & V_85 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_28 , & V_85 ) ;
}
