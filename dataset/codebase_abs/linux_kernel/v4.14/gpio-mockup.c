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
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_11 ( & V_5 -> V_19 , V_3 ) ;
}
static T_1 F_12 ( struct V_20 * V_20 ,
const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
struct V_24 * V_25 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 , V_31 ;
V_30 = F_13 ( V_21 , V_22 , 0 , & V_31 ) ;
if ( V_30 )
return V_30 ;
if ( V_31 != 0 && V_31 != 1 )
return - V_32 ;
V_27 = V_20 -> V_33 ;
V_25 = V_27 -> V_34 ;
V_29 = V_25 -> V_29 ;
V_5 = V_25 -> V_5 ;
F_14 ( V_29 , V_31 ) ;
F_15 ( & V_5 -> V_19 , V_25 -> V_3 ) ;
return V_22 ;
}
static int F_16 ( struct V_35 * V_35 , struct V_20 * V_20 )
{
return F_17 ( V_20 , NULL , V_35 -> V_36 ) ;
}
static void F_18 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
struct V_24 * V_25 ;
struct V_37 * V_38 ;
struct V_1 * V_2 ;
char * V_39 ;
int V_14 ;
V_2 = & V_5 -> V_2 ;
V_5 -> V_40 = F_19 ( V_2 -> V_18 , V_41 ) ;
if ( ! V_5 -> V_40 )
goto V_42;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_39 = F_9 ( V_12 , V_16 , L_2 , V_14 ) ;
if ( ! V_39 )
goto V_42;
V_25 = F_20 ( V_12 , sizeof( * V_25 ) , V_16 ) ;
if ( ! V_25 )
goto V_42;
V_25 -> V_5 = V_5 ;
V_25 -> V_3 = V_14 ;
V_25 -> V_29 = & V_2 -> V_43 -> V_44 [ V_14 ] ;
V_38 = F_21 ( V_39 , 0200 , V_5 -> V_40 , V_25 ,
& V_45 ) ;
if ( ! V_38 )
goto V_42;
}
return;
V_42:
F_22 ( V_12 , L_3 ) ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_4 * V_5 ,
const char * V_39 , int V_46 , int V_15 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_47 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_18 = V_39 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = V_12 ;
V_2 -> V_51 = F_1 ;
V_2 -> V_52 = F_3 ;
V_2 -> V_53 = F_4 ;
V_2 -> V_54 = F_5 ;
V_2 -> V_55 = F_6 ;
V_2 -> V_56 = F_10 ;
V_5 -> V_6 = F_8 ( V_12 , V_2 -> V_15 ,
sizeof( * V_5 -> V_6 ) , V_16 ) ;
if ( ! V_5 -> V_6 )
return - V_17 ;
if ( V_57 ) {
V_47 = F_7 ( V_12 , V_5 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_24 ( V_12 , & V_5 -> V_19 , V_2 -> V_15 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_25 ( V_12 , & V_5 -> V_2 , V_5 ) ;
if ( V_47 )
return V_47 ;
if ( V_41 )
F_18 ( V_12 , V_5 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_59 )
{
int V_47 , V_14 , V_46 , V_15 , V_60 ;
struct V_11 * V_12 = & V_59 -> V_12 ;
struct V_4 * V_61 ;
char * V_62 ;
if ( V_63 < 2 || ( V_63 % 2 ) )
return - V_32 ;
V_60 = V_63 / 2 ;
V_61 = F_8 ( V_12 , V_60 , sizeof( * V_61 ) , V_16 ) ;
if ( ! V_61 )
return - V_17 ;
F_27 ( V_59 , V_61 ) ;
for ( V_14 = 0 ; V_14 < V_60 ; V_14 ++ ) {
V_46 = V_64 [ V_14 * 2 ] ;
if ( V_46 == - 1 )
V_15 = V_64 [ V_14 * 2 + 1 ] ;
else
V_15 = V_64 [ V_14 * 2 + 1 ] - V_46 ;
if ( V_15 >= 0 ) {
V_62 = F_9 ( V_12 , V_16 ,
L_4 , V_65 ,
V_66 + V_14 ) ;
if ( ! V_62 )
return - V_17 ;
V_47 = F_23 ( V_12 , & V_61 [ V_14 ] ,
V_62 , V_46 , V_15 ) ;
} else {
V_47 = - V_32 ;
}
if ( V_47 ) {
F_22 ( V_12 ,
L_5 ,
V_47 , V_46 , V_46 < 0 ? V_15 : V_46 + V_15 ) ;
return V_47 ;
}
}
return 0 ;
}
static int T_5 F_28 ( void )
{
int V_42 ;
V_41 = F_19 ( L_6 , NULL ) ;
if ( ! V_41 )
F_29 ( L_7 ,
V_65 ) ;
V_59 = F_30 ( V_65 , - 1 ) ;
if ( ! V_59 )
return - V_17 ;
V_42 = F_31 ( V_59 ) ;
if ( V_42 ) {
F_32 ( V_59 ) ;
return V_42 ;
}
V_42 = F_33 ( & V_67 ) ;
if ( V_42 ) {
F_34 ( V_59 ) ;
return V_42 ;
}
return 0 ;
}
static void T_6 F_35 ( void )
{
F_36 ( V_41 ) ;
F_37 ( & V_67 ) ;
F_34 ( V_59 ) ;
}
