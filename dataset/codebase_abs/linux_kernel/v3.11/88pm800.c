static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 = 0 , V_11 = 0 , V_12 = 0 ;
if ( ! V_8 ) {
F_2 ( V_2 -> V_13 ,
L_1 ) ;
return - V_14 ;
}
V_12 = F_3 ( V_8 ,
V_15 ,
V_16 ,
V_16 ) ;
if ( V_12 < 0 )
goto V_17;
V_12 = F_3 ( V_8 , V_18 ,
V_19 , V_19 ) ;
if ( V_12 < 0 )
goto V_17;
V_12 = F_3 ( V_8 , V_20 ,
( V_21 | V_22 ) ,
( V_21 | V_22 ) ) ;
if ( V_12 < 0 )
goto V_17;
V_11 = ( V_23 | V_24 |
V_25 | V_26 ) ;
if ( V_4 && ( V_4 -> V_27 == 0 ) )
V_10 = ( V_23 | V_24 |
V_25 | V_26 ) ;
else
V_10 = ( V_23 | V_25 |
V_26 ) ;
V_12 = F_3 ( V_8 , V_28 , V_11 , V_10 ) ;
if ( V_12 < 0 )
goto V_17;
F_4 ( V_2 -> V_13 , L_2 ) ;
return 0 ;
V_17:
F_4 ( V_2 -> V_13 , L_3 ) ;
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_6 ( V_2 -> V_13 , 0 , & V_29 [ 0 ] ,
F_7 ( V_29 ) , & V_30 [ 0 ] , 0 ,
NULL ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_4 ) ;
return V_12 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
V_31 [ 0 ] . V_32 = V_4 -> V_33 ;
V_31 [ 0 ] . V_34 =
V_4 -> V_33 ? sizeof( struct V_35 ) : 0 ;
V_12 = F_6 ( V_2 -> V_13 , 0 , & V_31 [ 0 ] ,
F_7 ( V_31 ) , NULL , 0 , NULL ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_6 ( V_2 -> V_13 , 0 , & V_36 [ 0 ] ,
F_7 ( V_36 ) , NULL , 0 , NULL ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_6 ) ;
return V_12 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_7 ;
unsigned long V_37 = V_38 ;
int V_10 , V_11 , V_12 = - V_14 ;
if ( ! V_8 || ! V_2 -> V_39 ) {
F_8 ( V_2 -> V_13 , L_7 ) ;
return - V_14 ;
}
V_11 =
V_40 | V_41 |
V_42 ;
V_10 = V_41 ;
V_12 = F_3 ( V_8 , V_43 , V_11 , V_10 ) ;
if ( V_12 < 0 )
goto V_17;
V_12 =
F_12 ( V_2 -> V_7 , V_2 -> V_39 , V_37 , - 1 ,
V_2 -> V_44 , & V_2 -> V_45 ) ;
V_17:
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_39 , V_2 -> V_45 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_46 * V_47 = V_2 -> V_47 ;
int V_12 = 0 ;
V_6 = V_2 -> V_6 ;
if ( ! V_6 || ! V_6 -> V_48 || ! V_6 -> V_49 )
return - V_50 ;
V_6 -> V_51 = F_16 ( V_47 -> V_52 ,
V_6 -> V_48 ) ;
if ( V_6 -> V_51 == NULL ) {
V_12 = - V_50 ;
goto V_17;
}
V_6 -> V_53 = F_17 ( V_6 -> V_51 ,
& V_54 ) ;
if ( F_18 ( V_6 -> V_53 ) ) {
V_12 = F_19 ( V_6 -> V_53 ) ;
F_8 ( V_2 -> V_13 ,
L_8 , V_12 ) ;
goto V_17;
}
F_20 ( V_6 -> V_51 , V_2 ) ;
V_6 -> V_55 = F_16 ( V_47 -> V_52 ,
V_6 -> V_49 ) ;
if ( V_6 -> V_55 == NULL ) {
V_12 = - V_50 ;
goto V_17;
}
V_6 -> V_9 = F_17 ( V_6 -> V_55 ,
& V_54 ) ;
if ( F_18 ( V_6 -> V_9 ) ) {
V_12 = F_19 ( V_6 -> V_9 ) ;
F_8 ( V_2 -> V_13 ,
L_9 , V_12 ) ;
goto V_17;
}
F_20 ( V_6 -> V_55 , V_2 ) ;
V_17:
return V_12 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = V_2 -> V_6 ;
if ( V_6 && V_6 -> V_51 )
F_22 ( V_6 -> V_51 ) ;
if ( V_6 && V_6 -> V_55 )
F_22 ( V_6 -> V_55 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
unsigned int V_56 ;
V_12 = F_24 ( V_2 -> V_7 , V_57 , & V_56 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_13 , L_10 , V_12 ) ;
goto V_17;
}
if ( V_56 & V_58 ) {
if ( V_4 && V_4 -> V_33 )
V_4 -> V_33 -> V_59 = 1 ;
}
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_13 , L_11 , V_60 ) ;
goto V_17;
}
V_2 -> V_44 = & V_61 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_13 , L_12 , V_60 ) ;
goto V_17;
}
V_12 = F_5 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_4 ) ;
goto V_62;
}
V_12 = F_9 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_5 ) ;
goto V_17;
}
V_12 = F_10 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_13 ) ;
goto V_17;
}
return 0 ;
V_62:
F_25 ( V_2 -> V_13 ) ;
F_13 ( V_2 ) ;
V_17:
return V_12 ;
}
static int F_26 ( struct V_46 * V_47 ,
const struct V_63 * V_64 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = V_47 -> V_13 . V_32 ;
struct V_5 * V_6 ;
V_12 = F_27 ( V_47 ) ;
if ( V_12 ) {
F_8 ( & V_47 -> V_13 , L_14 ) ;
goto V_65;
}
V_2 = F_28 ( V_47 ) ;
V_6 =
F_29 ( & V_47 -> V_13 , sizeof( struct V_5 ) ,
V_66 ) ;
if ( ! V_6 ) {
V_12 = - V_67 ;
goto V_68;
}
V_6 -> V_48 = V_47 -> V_69 + 1 ;
V_6 -> V_49 = V_47 -> V_69 + 2 ;
V_2 -> V_6 = V_6 ;
V_12 = F_15 ( V_2 ) ;
if ( V_12 ) {
F_8 ( & V_47 -> V_13 , L_15 ) ;
goto V_70;
}
V_12 = F_23 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_13 , L_16 ) ;
goto V_71;
}
if ( V_4 -> V_72 )
V_4 -> V_72 ( V_2 , V_4 ) ;
return 0 ;
V_71:
F_21 ( V_2 ) ;
V_70:
V_68:
F_30 () ;
V_65:
return V_12 ;
}
static int F_31 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_28 ( V_47 ) ;
F_25 ( V_2 -> V_13 ) ;
F_13 ( V_2 ) ;
F_21 ( V_2 ) ;
F_30 () ;
return 0 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_73 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_73 ) ;
}
