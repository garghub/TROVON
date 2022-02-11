static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 [ V_3 ] . V_7 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 [ V_3 ] . V_7 = ! ! V_7 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_2 , V_3 , V_7 ) ;
V_5 -> V_6 [ V_3 ] . V_8 = V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 [ V_3 ] . V_8 = V_10 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 [ V_3 ] . V_8 ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
char * * V_13 ;
int V_14 ;
V_13 = F_8 ( V_12 , V_2 -> V_15 , sizeof( char * ) , V_16 ) ;
if ( ! V_13 )
return - V_17 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_13 [ V_14 ] = F_9 ( V_12 , V_16 ,
L_1 , V_2 -> V_18 , V_14 ) ;
if ( ! V_13 [ V_14 ] )
return - V_17 ;
}
V_2 -> V_13 = ( const char * const * ) V_13 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_5 , unsigned int V_3 )
{
return V_5 -> V_19 + V_3 ;
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 [ V_21 -> V_22 - V_2 -> V_19 ] . V_23 = false ;
}
static void F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 [ V_21 -> V_22 - V_2 -> V_19 ] . V_23 = true ;
}
static void F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_15 ( V_25 , struct V_26 , V_25 ) ;
F_16 ( F_17 ( V_27 -> V_22 ) ) ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_19 , V_14 ;
V_19 = F_19 ( V_12 , - 1 , 0 , V_2 -> V_15 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_28 = & V_29 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
F_20 ( V_19 + V_14 , V_2 -> V_28 ) ;
F_21 ( V_19 + V_14 , V_2 ) ;
F_22 ( V_19 + V_14 , & F_16 ) ;
F_23 ( V_19 + V_14 ,
V_30 | V_31 , V_32 ) ;
}
F_24 ( & V_5 -> V_27 . V_25 , F_14 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_33 * V_33 ,
const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_37 * V_38 ;
struct V_4 * V_5 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
int V_43 , V_44 ;
V_43 = F_26 ( V_34 , V_35 , 0 , & V_44 ) ;
if ( V_43 )
return V_43 ;
if ( V_44 != 0 && V_44 != 1 )
return - V_45 ;
V_40 = V_33 -> V_46 ;
V_38 = V_40 -> V_47 ;
V_42 = V_38 -> V_42 ;
V_5 = V_38 -> V_5 ;
V_2 = & V_5 -> V_2 ;
if ( V_5 -> V_6 [ V_38 -> V_3 ] . V_23 ) {
F_27 ( V_42 , V_44 ) ;
V_38 -> V_5 -> V_27 . V_22 = V_2 -> V_19 + V_38 -> V_3 ;
F_28 ( & V_38 -> V_5 -> V_27 . V_25 ) ;
}
return V_35 ;
}
static int F_29 ( struct V_48 * V_48 , struct V_33 * V_33 )
{
return F_30 ( V_33 , NULL , V_48 -> V_49 ) ;
}
static void F_31 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
struct V_37 * V_38 ;
struct V_50 * V_51 ;
struct V_1 * V_2 ;
char * V_52 ;
int V_14 ;
V_2 = & V_5 -> V_2 ;
V_5 -> V_53 = F_32 ( V_2 -> V_18 , V_54 ) ;
if ( ! V_5 -> V_53 )
goto V_55;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_52 = F_9 ( V_12 , V_16 , L_2 , V_14 ) ;
if ( ! V_52 )
goto V_55;
V_38 = F_33 ( V_12 , sizeof( * V_38 ) , V_16 ) ;
if ( ! V_38 )
goto V_55;
V_38 -> V_5 = V_5 ;
V_38 -> V_3 = V_14 ;
V_38 -> V_42 = & V_2 -> V_56 -> V_57 [ V_14 ] ;
V_51 = F_34 ( V_52 , 0200 , V_5 -> V_53 , V_38 ,
& V_58 ) ;
if ( ! V_51 )
goto V_55;
}
return;
V_55:
F_35 ( V_12 , L_3 ) ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_4 * V_5 ,
const char * V_52 , int V_59 , int V_15 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_60 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_18 = V_52 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_63 = V_12 ;
V_2 -> V_64 = F_1 ;
V_2 -> V_65 = F_3 ;
V_2 -> V_66 = F_4 ;
V_2 -> V_67 = F_5 ;
V_2 -> V_68 = F_6 ;
V_2 -> V_69 = F_10 ;
V_5 -> V_6 = F_8 ( V_12 , V_2 -> V_15 ,
sizeof( * V_5 -> V_6 ) , V_16 ) ;
if ( ! V_5 -> V_6 )
return - V_17 ;
if ( V_70 ) {
V_60 = F_7 ( V_12 , V_5 ) ;
if ( V_60 )
return V_60 ;
}
V_60 = F_18 ( V_12 , V_5 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_37 ( V_12 , & V_5 -> V_2 , V_5 ) ;
if ( V_60 )
return V_60 ;
if ( V_54 )
F_31 ( V_12 , V_5 ) ;
return 0 ;
}
static int F_38 ( struct V_71 * V_72 )
{
int V_60 , V_14 , V_59 , V_15 , V_73 ;
struct V_11 * V_12 = & V_72 -> V_12 ;
struct V_4 * V_74 ;
char * V_75 ;
if ( V_76 < 2 || ( V_76 % 2 ) )
return - V_45 ;
V_73 = V_76 / 2 ;
V_74 = F_8 ( V_12 , V_73 , sizeof( * V_74 ) , V_16 ) ;
if ( ! V_74 )
return - V_17 ;
F_39 ( V_72 , V_74 ) ;
for ( V_14 = 0 ; V_14 < V_73 ; V_14 ++ ) {
V_59 = V_77 [ V_14 * 2 ] ;
if ( V_59 == - 1 )
V_15 = V_77 [ V_14 * 2 + 1 ] ;
else
V_15 = V_77 [ V_14 * 2 + 1 ] - V_59 ;
if ( V_15 >= 0 ) {
V_75 = F_9 ( V_12 , V_16 ,
L_4 , V_78 ,
V_79 + V_14 ) ;
if ( ! V_75 )
return - V_17 ;
V_60 = F_36 ( V_12 , & V_74 [ V_14 ] ,
V_75 , V_59 , V_15 ) ;
} else {
V_60 = - V_45 ;
}
if ( V_60 ) {
F_35 ( V_12 ,
L_5 ,
V_60 , V_59 , V_59 < 0 ? V_15 : V_59 + V_15 ) ;
return V_60 ;
}
}
return 0 ;
}
static int T_5 F_40 ( void )
{
int V_55 ;
V_54 = F_32 ( L_6 , NULL ) ;
if ( ! V_54 )
F_41 ( L_7 ,
V_78 ) ;
V_72 = F_42 ( V_78 , - 1 ) ;
if ( ! V_72 )
return - V_17 ;
V_55 = F_43 ( V_72 ) ;
if ( V_55 ) {
F_44 ( V_72 ) ;
return V_55 ;
}
V_55 = F_45 ( & V_80 ) ;
if ( V_55 ) {
F_46 ( V_72 ) ;
return V_55 ;
}
return 0 ;
}
static void T_6 F_47 ( void )
{
F_48 ( V_54 ) ;
F_49 ( & V_80 ) ;
F_46 ( V_72 ) ;
}
