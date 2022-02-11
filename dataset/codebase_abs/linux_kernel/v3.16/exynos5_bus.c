static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 , unsigned long * V_8 ,
T_1 V_9 )
{
int V_10 = 0 ;
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 ,
V_7 ) ;
struct V_1 * V_2 = F_5 ( V_12 ) ;
struct V_13 * V_14 ;
unsigned long V_15 , V_16 ;
unsigned long V_3 ;
F_6 () ;
V_14 = F_7 ( V_7 , V_8 , V_9 ) ;
if ( F_8 ( V_14 ) ) {
F_9 () ;
F_10 ( V_7 , L_1 , V_17 ) ;
return F_11 ( V_14 ) ;
}
V_16 = F_12 ( V_14 ) ;
V_3 = F_13 ( V_14 ) ;
F_9 () ;
V_15 = V_2 -> V_18 ;
if ( V_15 == V_16 )
return 0 ;
F_14 ( V_7 , L_2 , V_16 , V_3 ) ;
F_15 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_20 )
goto V_21;
if ( V_16 > V_22 [ 0 ] . V_23 )
F_16 ( & V_2 -> V_24 , V_16 * 16 / 1000 ) ;
else
F_16 ( & V_2 -> V_24 , - 1 ) ;
if ( V_15 < V_16 )
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 )
goto V_21;
V_10 = F_17 ( V_2 -> V_25 , V_16 * 1000 ) ;
if ( V_10 )
goto V_21;
if ( V_15 > V_16 )
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 )
goto V_21;
V_2 -> V_18 = V_16 ;
V_21:
F_18 ( & V_2 -> V_19 ) ;
return V_10 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 ,
V_7 ) ;
struct V_1 * V_2 = F_5 ( V_12 ) ;
struct V_28 * V_29 = & V_2 -> V_29 ;
int V_30 ;
F_20 ( V_29 ) ;
V_30 = F_21 ( V_29 ) ;
V_27 -> V_31 = V_2 -> V_18 ;
V_27 -> V_32 = V_29 -> V_33 [ V_30 ] . V_34 [ V_35 ] ;
V_27 -> V_32 *= 100 / V_36 ;
V_27 -> V_37 = V_29 -> V_33 [ V_30 ] . V_38 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_39 , V_10 = 0 ;
for ( V_39 = V_40 ; V_39 < V_41 ; V_39 ++ ) {
V_10 = F_23 ( V_2 -> V_7 , V_22 [ V_39 ] . V_23 ,
V_22 [ V_39 ] . V_3 ) ;
if ( V_10 ) {
F_10 ( V_2 -> V_7 , L_3 ) ;
return V_10 ;
}
}
return 0 ;
}
static int F_24 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_1 * V_2 = F_4 ( V_43 ,
struct V_1 , V_46 ) ;
struct V_13 * V_14 ;
unsigned long V_47 = V_48 ;
unsigned long V_16 ;
unsigned long V_3 ;
int V_10 = 0 ;
switch ( V_44 ) {
case V_49 :
F_15 ( & V_2 -> V_19 ) ;
V_2 -> V_20 = true ;
F_6 () ;
V_14 = F_25 ( V_2 -> V_7 , & V_47 ) ;
if ( F_8 ( V_14 ) ) {
F_9 () ;
V_10 = F_11 ( V_14 ) ;
goto V_50;
}
V_16 = F_12 ( V_14 ) ;
V_3 = F_13 ( V_14 ) ;
F_9 () ;
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 )
goto V_50;
V_10 = F_17 ( V_2 -> V_25 , V_16 * 1000 ) ;
if ( V_10 )
goto V_50;
V_2 -> V_18 = V_16 ;
V_50:
F_18 ( & V_2 -> V_19 ) ;
if ( V_10 )
return V_51 ;
return V_52 ;
case V_53 :
case V_54 :
F_15 ( & V_2 -> V_19 ) ;
V_2 -> V_20 = false ;
F_18 ( & V_2 -> V_19 ) ;
return V_52 ;
}
return V_55 ;
}
static int F_26 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_13 * V_14 ;
struct V_6 * V_7 = & V_12 -> V_7 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
unsigned long V_59 ;
int V_10 = 0 ;
int V_39 ;
V_2 = F_27 ( & V_12 -> V_7 , sizeof( struct V_1 ) ,
V_60 ) ;
if ( V_2 == NULL ) {
F_10 ( V_7 , L_4 ) ;
return - V_61 ;
}
V_29 = & V_2 -> V_29 ;
V_29 -> V_62 = V_63 ;
V_29 -> V_33 = F_27 ( V_7 ,
sizeof( struct V_64 ) * V_63 ,
V_60 ) ;
if ( ! V_29 -> V_33 ) {
F_10 ( V_7 , L_5 ) ;
return - V_61 ;
}
V_57 = F_28 ( NULL , NULL , L_6 ) ;
if ( V_57 == NULL ) {
F_29 ( L_7 ) ;
return - V_65 ;
}
for ( V_39 = 0 ; V_39 < V_29 -> V_62 ; V_39 ++ ) {
V_29 -> V_33 [ V_39 ] . V_66 = F_30 ( V_57 , V_39 ) ;
if ( V_29 -> V_33 [ V_39 ] . V_66 == NULL ) {
F_10 ( & V_12 -> V_7 , L_8 ) ;
return - V_61 ;
}
}
V_2 -> V_46 . V_67 = F_24 ;
V_2 -> V_7 = V_7 ;
F_31 ( & V_2 -> V_19 ) ;
V_10 = F_22 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_2 -> V_4 = F_32 ( V_7 , L_9 ) ;
if ( F_8 ( V_2 -> V_4 ) ) {
F_10 ( V_7 , L_10 ) ;
return F_11 ( V_2 -> V_4 ) ;
}
V_2 -> V_25 = F_33 ( V_7 , L_11 ) ;
if ( F_8 ( V_2 -> V_25 ) ) {
F_10 ( V_7 , L_12 ) ;
return F_11 ( V_2 -> V_25 ) ;
}
F_6 () ;
V_14 = F_25 ( V_7 ,
& V_68 . V_58 ) ;
if ( F_8 ( V_14 ) ) {
F_9 () ;
F_10 ( V_7 , L_13 ,
V_68 . V_58 ) ;
return F_11 ( V_14 ) ;
}
V_58 = F_12 ( V_14 ) ;
V_59 = F_13 ( V_14 ) ;
F_9 () ;
V_2 -> V_18 = V_58 ;
V_10 = F_17 ( V_2 -> V_25 , V_58 * 1000 ) ;
if ( V_10 ) {
F_10 ( V_7 , L_14 ) ;
return V_10 ;
}
V_10 = F_1 ( V_2 , V_59 ) ;
if ( V_10 )
return V_10 ;
F_34 ( V_12 , V_2 ) ;
F_35 ( V_29 ) ;
V_2 -> V_69 = F_36 ( V_7 , & V_68 ,
L_15 , NULL ) ;
if ( F_8 ( V_2 -> V_69 ) )
return F_11 ( V_2 -> V_69 ) ;
V_10 = F_37 ( V_7 , V_2 -> V_69 ) ;
if ( V_10 < 0 ) {
F_10 ( V_7 , L_16 ) ;
return V_10 ;
}
V_10 = F_38 ( & V_2 -> V_46 ) ;
if ( V_10 ) {
F_10 ( V_7 , L_17 ) ;
return V_10 ;
}
F_39 ( & V_2 -> V_24 , V_70 , - 1 ) ;
return 0 ;
}
static int F_40 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
F_41 ( & V_2 -> V_24 ) ;
F_42 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 ,
V_7 ) ;
struct V_1 * V_2 = F_5 ( V_12 ) ;
struct V_28 * V_29 = & V_2 -> V_29 ;
F_35 ( V_29 ) ;
return 0 ;
}
static int T_2 F_44 ( void )
{
int V_71 ;
V_71 = F_45 ( & V_72 ) ;
if ( V_71 < 0 )
goto V_21;
V_73 =
F_46 ( L_18 , - 1 , NULL , 0 ) ;
if ( F_8 ( V_73 ) ) {
V_71 = F_11 ( V_73 ) ;
goto V_74;
}
return 0 ;
V_74:
F_47 ( & V_72 ) ;
V_21:
return V_71 ;
}
static void T_3 F_48 ( void )
{
F_49 ( V_73 ) ;
F_47 ( & V_72 ) ;
}
