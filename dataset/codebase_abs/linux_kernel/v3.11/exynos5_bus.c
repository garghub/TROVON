static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 ++ ) {
void T_1 * V_6 = V_2 -> V_7 [ V_3 ] . V_8 ;
F_2 ( V_6 ) ;
V_2 -> V_7 [ V_3 ] . V_9 [ V_10 ] = V_11 ;
F_3 ( V_6 , V_10 ,
V_2 -> V_7 [ V_3 ] . V_9 [ V_10 ] ) ;
F_4 ( V_6 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 , V_12 ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 ++ ) {
void T_1 * V_6 = V_2 -> V_7 [ V_3 ] . V_8 ;
F_6 ( V_6 ) ;
V_2 -> V_7 [ V_3 ] . V_13 = F_7 ( V_6 + V_14 ) ;
for ( V_12 = V_15 ; V_12 < V_16 ; V_12 ++ ) {
if ( V_2 -> V_7 [ V_3 ] . V_9 [ V_12 ] == 0 )
V_2 -> V_7 [ V_3 ] . V_17 [ V_12 ] = 0 ;
else
V_2 -> V_7 [ V_3 ] . V_17 [ V_12 ] =
F_8 ( V_6 , V_12 ) ;
}
}
F_1 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
return F_10 ( V_2 -> V_19 , V_18 , V_20 ) ;
}
static int F_11 ( struct V_21 * V_22 , unsigned long * V_23 ,
T_2 V_24 )
{
int V_25 = 0 ;
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
struct V_28 * V_28 ;
unsigned long V_29 , V_30 ;
unsigned long V_18 ;
F_14 () ;
V_28 = F_15 ( V_22 , V_23 , V_24 ) ;
if ( F_16 ( V_28 ) ) {
F_17 () ;
F_18 ( V_22 , L_1 , V_31 ) ;
return F_19 ( V_28 ) ;
}
V_30 = F_20 ( V_28 ) ;
V_18 = F_21 ( V_28 ) ;
F_17 () ;
V_29 = V_2 -> V_32 ;
if ( V_29 == V_30 )
return 0 ;
F_22 ( V_22 , L_2 , V_30 , V_18 ) ;
F_23 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_34 )
goto V_35;
if ( V_30 > V_36 [ 0 ] . V_37 )
F_24 ( & V_2 -> V_38 , V_30 * 16 / 1000 ) ;
else
F_24 ( & V_2 -> V_38 , - 1 ) ;
if ( V_29 < V_30 )
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
goto V_35;
V_25 = F_25 ( V_2 -> V_39 , V_30 * 1000 ) ;
if ( V_25 )
goto V_35;
if ( V_29 > V_30 )
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
goto V_35;
V_2 -> V_32 = V_30 ;
V_35:
F_26 ( & V_2 -> V_33 ) ;
return V_25 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_3 , V_12 ;
int V_40 = 0 ;
unsigned int V_41 = 0 ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 ++ ) {
for ( V_12 = V_15 ; V_12 < V_16 ; V_12 ++ ) {
if ( V_2 -> V_7 [ V_3 ] . V_17 [ V_12 ] > V_41 ) {
V_41 = V_2 -> V_7 [ V_3 ] . V_17 [ V_12 ] ;
V_40 = V_3 ;
}
}
}
return V_40 ;
}
static int F_28 ( struct V_21 * V_22 ,
struct V_42 * V_43 )
{
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_44 ;
F_5 ( V_2 ) ;
V_44 = F_27 ( V_2 ) ;
V_43 -> V_45 = V_2 -> V_32 ;
V_43 -> V_46 = V_2 -> V_7 [ V_44 ] . V_17 [ V_10 ] ;
V_43 -> V_46 *= 100 / V_47 ;
V_43 -> V_48 = V_2 -> V_7 [ V_44 ] . V_13 ;
return 0 ;
}
static void F_29 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_30 ( V_22 , V_2 -> V_49 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_3 , V_25 = 0 ;
for ( V_3 = V_50 ; V_3 < V_51 ; V_3 ++ ) {
V_25 = F_32 ( V_2 -> V_22 , V_36 [ V_3 ] . V_37 ,
V_36 [ V_3 ] . V_18 ) ;
if ( V_25 ) {
F_18 ( V_2 -> V_22 , L_3 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_33 ( struct V_52 * V_53 ,
unsigned long V_9 , void * V_54 )
{
struct V_1 * V_2 = F_12 ( V_53 ,
struct V_1 , V_55 ) ;
struct V_28 * V_28 ;
unsigned long V_56 = V_57 ;
unsigned long V_30 ;
unsigned long V_18 ;
int V_25 = 0 ;
switch ( V_9 ) {
case V_58 :
F_23 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = true ;
F_14 () ;
V_28 = F_34 ( V_2 -> V_22 , & V_56 ) ;
if ( F_16 ( V_28 ) ) {
F_17 () ;
V_25 = F_19 ( V_28 ) ;
goto V_59;
}
V_30 = F_20 ( V_28 ) ;
V_18 = F_21 ( V_28 ) ;
F_17 () ;
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
goto V_59;
V_25 = F_25 ( V_2 -> V_39 , V_30 * 1000 ) ;
if ( V_25 )
goto V_59;
V_2 -> V_32 = V_30 ;
V_59:
F_26 ( & V_2 -> V_33 ) ;
if ( V_25 )
return V_60 ;
return V_61 ;
case V_62 :
case V_63 :
F_23 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = false ;
F_26 ( & V_2 -> V_33 ) ;
return V_61 ;
}
return V_64 ;
}
static int F_35 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_28 ;
struct V_21 * V_22 = & V_27 -> V_22 ;
struct V_65 * V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
int V_25 = 0 ;
int V_3 ;
V_2 = F_36 ( & V_27 -> V_22 , sizeof( struct V_1 ) ,
V_69 ) ;
if ( V_2 == NULL ) {
F_18 ( V_22 , L_4 ) ;
return - V_70 ;
}
V_66 = F_37 ( NULL , NULL , L_5 ) ;
if ( V_66 == NULL ) {
F_38 ( L_6 ) ;
return - V_71 ;
}
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_8 = F_39 ( V_66 , V_3 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_8 == NULL ) {
F_18 ( & V_27 -> V_22 , L_7 ) ;
return - V_70 ;
}
}
V_2 -> V_55 . V_72 = F_33 ;
V_2 -> V_22 = V_22 ;
F_40 ( & V_2 -> V_33 ) ;
V_25 = F_31 ( V_2 ) ;
if ( V_25 )
goto V_73;
V_2 -> V_19 = F_41 ( V_22 , L_8 ) ;
if ( F_16 ( V_2 -> V_19 ) ) {
F_18 ( V_22 , L_9 ) ;
V_25 = F_19 ( V_2 -> V_19 ) ;
goto V_73;
}
V_2 -> V_39 = F_42 ( V_22 , L_10 ) ;
if ( F_16 ( V_2 -> V_39 ) ) {
F_18 ( V_22 , L_11 ) ;
V_25 = F_19 ( V_2 -> V_39 ) ;
goto V_74;
}
F_14 () ;
V_28 = F_34 ( V_22 ,
& V_75 . V_67 ) ;
if ( F_16 ( V_28 ) ) {
F_17 () ;
F_18 ( V_22 , L_12 ,
V_75 . V_67 ) ;
V_25 = F_19 ( V_28 ) ;
goto V_76;
}
V_67 = F_20 ( V_28 ) ;
V_68 = F_21 ( V_28 ) ;
F_17 () ;
V_2 -> V_32 = V_67 ;
V_25 = F_25 ( V_2 -> V_39 , V_67 * 1000 ) ;
if ( V_25 ) {
F_18 ( V_22 , L_13 ) ;
goto V_76;
}
V_25 = F_9 ( V_2 , V_68 ) ;
if ( V_25 )
goto V_76;
F_43 ( V_27 , V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_49 = F_44 ( V_22 , & V_75 ,
L_14 , NULL ) ;
if ( F_16 ( V_2 -> V_49 ) ) {
V_25 = F_19 ( V_2 -> V_49 ) ;
goto V_77;
}
F_45 ( V_22 , V_2 -> V_49 ) ;
V_25 = F_46 ( & V_2 -> V_55 ) ;
if ( V_25 ) {
F_18 ( V_22 , L_15 ) ;
goto V_77;
}
F_47 ( & V_2 -> V_38 , V_78 , - 1 ) ;
return 0 ;
V_77:
F_48 ( V_2 -> V_49 ) ;
F_43 ( V_27 , NULL ) ;
V_76:
F_49 ( V_2 -> V_39 ) ;
V_74:
F_50 ( V_2 -> V_19 ) ;
V_73:
return V_25 ;
}
static int F_51 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_52 ( & V_2 -> V_38 ) ;
F_53 ( & V_2 -> V_55 ) ;
F_48 ( V_2 -> V_49 ) ;
F_50 ( V_2 -> V_19 ) ;
F_49 ( V_2 -> V_39 ) ;
F_43 ( V_27 , NULL ) ;
return 0 ;
}
static int F_54 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int T_3 F_55 ( void )
{
int V_79 ;
V_79 = F_56 ( & V_80 ) ;
if ( V_79 < 0 )
goto V_35;
V_81 =
F_57 ( L_16 , - 1 , NULL , 0 ) ;
if ( F_58 ( V_81 ) ) {
V_79 = F_19 ( V_81 ) ;
goto V_82;
}
return 0 ;
V_82:
F_59 ( & V_80 ) ;
V_35:
return V_79 ;
}
static void T_4 F_60 ( void )
{
F_61 ( V_81 ) ;
F_59 ( & V_80 ) ;
}
