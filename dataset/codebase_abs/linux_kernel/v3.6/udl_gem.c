struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( V_5 == NULL )
return NULL ;
if ( F_3 ( V_3 , & V_5 -> V_7 , V_4 ) != 0 ) {
F_4 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
static int
F_5 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
T_2 V_4 ,
T_3 * V_10 )
{
struct V_1 * V_5 ;
int V_11 ;
T_4 V_12 ;
V_4 = F_6 ( V_4 , V_13 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL )
return - V_14 ;
V_11 = F_7 ( V_9 , & V_5 -> V_7 , & V_12 ) ;
if ( V_11 ) {
F_8 ( & V_5 -> V_7 ) ;
F_4 ( V_5 ) ;
return V_11 ;
}
F_9 ( & V_5 -> V_7 ) ;
* V_10 = V_12 ;
return 0 ;
}
int F_10 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_15 * args )
{
args -> V_16 = args -> V_17 * ( ( args -> V_18 + 1 ) / 8 ) ;
args -> V_4 = args -> V_16 * args -> V_19 ;
return F_5 ( V_9 , V_3 ,
args -> V_4 , & args -> V_12 ) ;
}
int F_11 ( struct V_8 * V_9 , struct V_2 * V_3 ,
T_3 V_12 )
{
return F_12 ( V_9 , V_12 ) ;
}
int F_13 ( struct V_9 * V_20 , struct V_21 * V_22 )
{
int V_11 ;
V_11 = F_14 ( V_20 , V_22 ) ;
if ( V_11 )
return V_11 ;
V_22 -> V_23 &= ~ V_24 ;
V_22 -> V_23 |= V_25 ;
return V_11 ;
}
int F_15 ( struct V_21 * V_22 , struct V_26 * V_27 )
{
struct V_1 * V_5 = F_16 ( V_22 -> V_28 ) ;
struct V_29 * V_29 ;
unsigned int V_30 ;
int V_11 = 0 ;
V_30 = ( ( unsigned long ) V_27 -> V_31 - V_22 -> V_32 ) >>
V_33 ;
if ( ! V_5 -> V_34 )
return V_35 ;
V_29 = V_5 -> V_34 [ V_30 ] ;
V_11 = F_17 ( V_22 , ( unsigned long ) V_27 -> V_31 , V_29 ) ;
switch ( V_11 ) {
case - V_36 :
F_18 () ;
case 0 :
case - V_37 :
return V_38 ;
case - V_14 :
return V_39 ;
default:
return V_35 ;
}
}
int F_19 ( struct V_40 * V_5 )
{
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_1 * V_5 , T_5 V_41 )
{
int V_42 , V_43 ;
struct V_29 * V_29 ;
struct V_44 * V_44 ;
struct V_45 * V_46 ;
if ( V_5 -> V_34 )
return 0 ;
V_42 = V_5 -> V_7 . V_4 / V_13 ;
F_22 ( V_5 -> V_34 != NULL ) ;
V_5 -> V_34 = F_23 ( V_42 , sizeof( struct V_29 * ) ) ;
if ( V_5 -> V_34 == NULL )
return - V_14 ;
V_44 = V_5 -> V_7 . V_20 -> V_47 . V_48 -> V_49 ;
V_46 = V_44 -> V_50 ;
V_41 |= F_24 ( V_46 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_29 = F_25 ( V_46 , V_43 , V_41 ) ;
if ( F_26 ( V_29 ) )
goto V_51;
V_5 -> V_34 [ V_43 ] = V_29 ;
}
return 0 ;
V_51:
while ( V_43 -- )
F_27 ( V_5 -> V_34 [ V_43 ] ) ;
F_28 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
return F_29 ( V_29 ) ;
}
static void F_30 ( struct V_1 * V_5 )
{
int V_42 = V_5 -> V_7 . V_4 / V_13 ;
int V_43 ;
if ( V_5 -> V_7 . V_52 ) {
F_28 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
return;
}
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
F_27 ( V_5 -> V_34 [ V_43 ] ) ;
F_28 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
}
int F_31 ( struct V_1 * V_5 )
{
int V_42 = V_5 -> V_7 . V_4 / V_13 ;
int V_11 ;
if ( V_5 -> V_7 . V_52 ) {
V_11 = F_32 ( V_5 -> V_7 . V_52 -> V_53 ,
0 , V_5 -> V_7 . V_4 , V_54 ) ;
if ( V_11 )
return - V_55 ;
V_5 -> V_56 = F_33 ( V_5 -> V_7 . V_52 -> V_53 ) ;
if ( ! V_5 -> V_56 )
return - V_14 ;
return 0 ;
}
V_11 = F_21 ( V_5 , V_6 ) ;
if ( V_11 )
return V_11 ;
V_5 -> V_56 = F_34 ( V_5 -> V_34 , V_42 , 0 , V_57 ) ;
if ( ! V_5 -> V_56 )
return - V_14 ;
return 0 ;
}
void F_35 ( struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_52 ) {
F_36 ( V_5 -> V_7 . V_52 -> V_53 , V_5 -> V_56 ) ;
F_37 ( V_5 -> V_7 . V_52 -> V_53 , 0 ,
V_5 -> V_7 . V_4 , V_54 ) ;
return;
}
if ( V_5 -> V_56 )
F_38 ( V_5 -> V_56 ) ;
F_30 ( V_5 ) ;
}
void F_39 ( struct V_40 * V_58 )
{
struct V_1 * V_5 = F_16 ( V_58 ) ;
if ( V_5 -> V_56 )
F_35 ( V_5 ) ;
if ( V_58 -> V_52 )
F_40 ( V_58 , V_5 -> V_59 ) ;
if ( V_5 -> V_34 )
F_30 ( V_5 ) ;
if ( V_58 -> V_60 . V_61 )
F_41 ( V_58 ) ;
}
int F_42 ( struct V_8 * V_9 , struct V_2 * V_3 ,
T_3 V_12 , T_2 * V_62 )
{
struct V_1 * V_63 ;
struct V_40 * V_5 ;
int V_11 = 0 ;
F_43 ( & V_3 -> V_64 ) ;
V_5 = F_44 ( V_3 , V_9 , V_12 ) ;
if ( V_5 == NULL ) {
V_11 = - V_65 ;
goto V_66;
}
V_63 = F_16 ( V_5 ) ;
V_11 = F_21 ( V_63 , V_6 ) ;
if ( V_11 )
goto V_67;
if ( ! V_63 -> V_7 . V_60 . V_61 ) {
V_11 = F_45 ( V_5 ) ;
if ( V_11 )
goto V_67;
}
* V_62 = ( V_68 ) V_63 -> V_7 . V_60 . V_69 . V_70 << V_33 ;
V_67:
F_9 ( & V_63 -> V_7 ) ;
V_66:
F_46 ( & V_3 -> V_64 ) ;
return V_11 ;
}
static int F_47 ( struct V_2 * V_3 ,
T_1 V_4 ,
struct V_71 * V_59 ,
struct V_1 * * V_72 )
{
struct V_1 * V_5 ;
int V_73 ;
V_73 = V_4 / V_13 ;
* V_72 = NULL ;
V_5 = F_1 ( V_3 , V_73 * V_13 ) ;
if ( ! V_5 )
return - V_14 ;
V_5 -> V_59 = V_59 ;
V_5 -> V_34 = F_23 ( V_73 , sizeof( struct V_29 * ) ) ;
if ( V_5 -> V_34 == NULL ) {
F_48 ( L_1 , V_73 ) ;
return - V_14 ;
}
F_49 ( V_59 , V_5 -> V_34 , NULL , V_73 ) ;
* V_72 = V_5 ;
return 0 ;
}
struct V_40 * F_50 ( struct V_2 * V_3 ,
struct V_74 * V_74 )
{
struct V_75 * V_76 ;
struct V_71 * V_59 ;
struct V_1 * V_77 ;
int V_11 ;
V_76 = F_51 ( V_74 , V_3 -> V_3 ) ;
if ( F_26 ( V_76 ) )
return F_52 ( V_76 ) ;
V_59 = F_53 ( V_76 , V_54 ) ;
if ( F_26 ( V_59 ) ) {
V_11 = F_29 ( V_59 ) ;
goto V_78;
}
V_11 = F_47 ( V_3 , V_74 -> V_4 , V_59 , & V_77 ) ;
if ( V_11 ) {
goto V_79;
}
V_77 -> V_7 . V_52 = V_76 ;
return & V_77 -> V_7 ;
V_79:
F_54 ( V_76 , V_59 , V_54 ) ;
V_78:
F_55 ( V_74 , V_76 ) ;
return F_56 ( V_11 ) ;
}
