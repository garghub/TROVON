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
struct V_28 * V_29 ;
unsigned long V_30 , V_31 ;
unsigned long V_18 ;
F_14 () ;
V_29 = F_15 ( V_22 , V_23 , V_24 ) ;
if ( F_16 ( V_29 ) ) {
F_17 () ;
F_18 ( V_22 , L_1 , V_32 ) ;
return F_19 ( V_29 ) ;
}
V_31 = F_20 ( V_29 ) ;
V_18 = F_21 ( V_29 ) ;
F_17 () ;
V_30 = V_2 -> V_33 ;
if ( V_30 == V_31 )
return 0 ;
F_22 ( V_22 , L_2 , V_31 , V_18 ) ;
F_23 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_35 )
goto V_36;
if ( V_31 > V_37 [ 0 ] . V_38 )
F_24 ( & V_2 -> V_39 , V_31 * 16 / 1000 ) ;
else
F_24 ( & V_2 -> V_39 , - 1 ) ;
if ( V_30 < V_31 )
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
goto V_36;
V_25 = F_25 ( V_2 -> V_40 , V_31 * 1000 ) ;
if ( V_25 )
goto V_36;
if ( V_30 > V_31 )
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
goto V_36;
V_2 -> V_33 = V_31 ;
V_36:
F_26 ( & V_2 -> V_34 ) ;
return V_25 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_3 , V_12 ;
int V_41 = 0 ;
unsigned int V_42 = 0 ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 ++ ) {
for ( V_12 = V_15 ; V_12 < V_16 ; V_12 ++ ) {
if ( V_2 -> V_7 [ V_3 ] . V_17 [ V_12 ] > V_42 ) {
V_42 = V_2 -> V_7 [ V_3 ] . V_17 [ V_12 ] ;
V_41 = V_3 ;
}
}
}
return V_41 ;
}
static int F_28 ( struct V_21 * V_22 ,
struct V_43 * V_44 )
{
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_45 ;
F_5 ( V_2 ) ;
V_45 = F_27 ( V_2 ) ;
V_44 -> V_46 = V_2 -> V_33 ;
V_44 -> V_47 = V_2 -> V_7 [ V_45 ] . V_17 [ V_10 ] ;
V_44 -> V_47 *= 100 / V_48 ;
V_44 -> V_49 = V_2 -> V_7 [ V_45 ] . V_13 ;
return 0 ;
}
static void F_29 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_30 ( V_22 , V_2 -> V_50 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_3 , V_25 = 0 ;
for ( V_3 = V_51 ; V_3 < V_52 ; V_3 ++ ) {
V_25 = F_32 ( V_2 -> V_22 , V_37 [ V_3 ] . V_38 ,
V_37 [ V_3 ] . V_18 ) ;
if ( V_25 ) {
F_18 ( V_2 -> V_22 , L_3 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_33 ( struct V_53 * V_54 ,
unsigned long V_9 , void * V_55 )
{
struct V_1 * V_2 = F_12 ( V_54 ,
struct V_1 , V_56 ) ;
struct V_28 * V_29 ;
unsigned long V_57 = V_58 ;
unsigned long V_31 ;
unsigned long V_18 ;
int V_25 = 0 ;
switch ( V_9 ) {
case V_59 :
F_23 ( & V_2 -> V_34 ) ;
V_2 -> V_35 = true ;
F_14 () ;
V_29 = F_34 ( V_2 -> V_22 , & V_57 ) ;
if ( F_16 ( V_29 ) ) {
F_17 () ;
V_25 = F_19 ( V_29 ) ;
goto V_60;
}
V_31 = F_20 ( V_29 ) ;
V_18 = F_21 ( V_29 ) ;
F_17 () ;
V_25 = F_9 ( V_2 , V_18 ) ;
if ( V_25 )
goto V_60;
V_25 = F_25 ( V_2 -> V_40 , V_31 * 1000 ) ;
if ( V_25 )
goto V_60;
V_2 -> V_33 = V_31 ;
V_60:
F_26 ( & V_2 -> V_34 ) ;
if ( V_25 )
return V_61 ;
return V_62 ;
case V_63 :
case V_64 :
F_23 ( & V_2 -> V_34 ) ;
V_2 -> V_35 = false ;
F_26 ( & V_2 -> V_34 ) ;
return V_62 ;
}
return V_65 ;
}
static int F_35 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_21 * V_22 = & V_27 -> V_22 ;
struct V_66 * V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
int V_25 = 0 ;
int V_3 ;
V_2 = F_36 ( & V_27 -> V_22 , sizeof( struct V_1 ) ,
V_70 ) ;
if ( V_2 == NULL ) {
F_18 ( V_22 , L_4 ) ;
return - V_71 ;
}
V_67 = F_37 ( NULL , NULL , L_5 ) ;
if ( V_67 == NULL ) {
F_38 ( L_6 ) ;
return - V_72 ;
}
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_8 = F_39 ( V_67 , V_3 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_8 == NULL ) {
F_18 ( & V_27 -> V_22 , L_7 ) ;
return - V_71 ;
}
}
V_2 -> V_56 . V_73 = F_33 ;
V_2 -> V_22 = V_22 ;
F_40 ( & V_2 -> V_34 ) ;
V_25 = F_31 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_2 -> V_19 = F_41 ( V_22 , L_8 ) ;
if ( F_16 ( V_2 -> V_19 ) ) {
F_18 ( V_22 , L_9 ) ;
return F_19 ( V_2 -> V_19 ) ;
}
V_2 -> V_40 = F_42 ( V_22 , L_10 ) ;
if ( F_16 ( V_2 -> V_40 ) ) {
F_18 ( V_22 , L_11 ) ;
return F_19 ( V_2 -> V_40 ) ;
}
F_14 () ;
V_29 = F_34 ( V_22 ,
& V_74 . V_68 ) ;
if ( F_16 ( V_29 ) ) {
F_17 () ;
F_18 ( V_22 , L_12 ,
V_74 . V_68 ) ;
return F_19 ( V_29 ) ;
}
V_68 = F_20 ( V_29 ) ;
V_69 = F_21 ( V_29 ) ;
F_17 () ;
V_2 -> V_33 = V_68 ;
V_25 = F_25 ( V_2 -> V_40 , V_68 * 1000 ) ;
if ( V_25 ) {
F_18 ( V_22 , L_13 ) ;
return V_25 ;
}
V_25 = F_9 ( V_2 , V_69 ) ;
if ( V_25 )
return V_25 ;
F_43 ( V_27 , V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_50 = F_44 ( V_22 , & V_74 ,
L_14 , NULL ) ;
if ( F_16 ( V_2 -> V_50 ) ) {
V_25 = F_19 ( V_2 -> V_50 ) ;
goto V_75;
}
F_45 ( V_22 , V_2 -> V_50 ) ;
V_25 = F_46 ( & V_2 -> V_56 ) ;
if ( V_25 ) {
F_18 ( V_22 , L_15 ) ;
goto V_75;
}
F_47 ( & V_2 -> V_39 , V_76 , - 1 ) ;
return 0 ;
V_75:
F_48 ( V_2 -> V_50 ) ;
return V_25 ;
}
static int F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_50 ( & V_2 -> V_39 ) ;
F_51 ( & V_2 -> V_56 ) ;
F_48 ( V_2 -> V_50 ) ;
return 0 ;
}
static int F_52 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = F_12 ( V_22 , struct V_26 ,
V_22 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int T_3 F_53 ( void )
{
int V_77 ;
V_77 = F_54 ( & V_78 ) ;
if ( V_77 < 0 )
goto V_36;
V_79 =
F_55 ( L_16 , - 1 , NULL , 0 ) ;
if ( F_16 ( V_79 ) ) {
V_77 = F_19 ( V_79 ) ;
goto V_80;
}
return 0 ;
V_80:
F_56 ( & V_78 ) ;
V_36:
return V_77 ;
}
static void T_4 F_57 ( void )
{
F_58 ( V_79 ) ;
F_56 ( & V_78 ) ;
}
