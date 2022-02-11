static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
F_2 ( V_2 -> V_5 [ V_3 ] ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
F_4 ( V_2 -> V_5 [ V_3 ] ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
F_1 ( V_2 ) ;
if ( V_2 -> V_7 -> V_8 ) {
V_6 = V_2 -> V_7 -> V_8 ( V_2 -> V_9 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_10 )
V_2 -> V_7 -> V_10 ( V_2 -> V_9 ) ;
F_3 ( V_2 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 . V_16 ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_6 ;
if ( V_2 == NULL ) {
F_9 ( V_14 , L_1 ) ;
return - V_17 ;
}
V_12 -> V_18 = 1 ;
V_6 = F_10 ( V_12 ) ;
if ( V_6 )
F_9 ( V_14 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_21 * V_7 = V_20 -> V_14 . V_22 ;
struct V_11 * V_12 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_27 , V_6 = - V_17 ;
T_1 V_28 ;
T_2 V_29 ;
if ( ! V_7 ) {
F_9 ( & V_20 -> V_14 , L_3 ) ;
return - V_17 ;
}
if ( F_12 () )
return - V_17 ;
V_12 = F_13 ( & V_30 , & V_20 -> V_14 , L_4 ) ;
if ( ! V_12 )
return - V_31 ;
V_29 = sizeof( * V_2 ) + sizeof( struct V_5 * ) * V_7 -> V_4 ;
V_2 = F_14 ( V_29 , V_32 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_20 -> V_14 , L_5 ) ;
V_6 = - V_31 ;
goto V_33;
}
F_15 ( V_20 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_7 -> V_4 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_4 ; V_27 ++ ) {
V_2 -> V_5 [ V_27 ] =
F_16 ( & V_20 -> V_14 , V_7 -> V_34 [ V_27 ] ) ;
if ( F_17 ( V_2 -> V_5 [ V_27 ] ) ) {
F_9 ( & V_20 -> V_14 , L_6 ,
V_7 -> V_34 [ V_27 ] ) ;
V_6 = F_18 ( V_2 -> V_5 [ V_27 ] ) ;
goto V_35;
}
}
V_26 = F_19 ( V_20 , V_36 , L_7 ) ;
if ( V_26 == NULL ) {
F_9 ( & V_20 -> V_14 , L_8 ) ;
V_6 = - V_17 ;
goto V_35;
}
V_2 -> V_9 = F_20 ( V_26 -> V_37 , F_21 ( V_26 ) ) ;
if ( V_2 -> V_9 == 0 ) {
F_9 ( & V_20 -> V_14 , L_9 ) ;
V_6 = - V_38 ;
goto V_35;
}
V_26 = F_19 ( V_20 , V_36 , L_10 ) ;
if ( ! V_26 ) {
F_9 ( & V_20 -> V_14 , L_11 ) ;
V_6 = - V_17 ;
goto V_39;
}
V_2 -> V_40 = F_20 ( V_26 -> V_37 , F_21 ( V_26 ) ) ;
if ( V_2 -> V_40 == NULL ) {
F_9 ( & V_20 -> V_14 , L_12 ) ;
V_6 = - V_38 ;
goto V_39;
}
V_6 = F_5 ( V_2 ) ;
if ( V_6 ) {
F_9 ( & V_20 -> V_14 , L_13 , V_6 ) ;
goto V_41;
}
V_28 = F_22 ( V_2 -> V_40 ) & V_42 ;
V_2 -> V_43 =
( void V_44 * ) ( ( unsigned long ) V_2 -> V_40 + V_28 ) ;
V_12 -> V_45 = V_26 -> V_37 ;
V_12 -> V_46 = V_26 -> V_47 - V_26 -> V_37 + 1 ;
V_12 -> V_48 = V_2 -> V_43 ;
V_12 -> V_49 = F_23 ( V_20 , 0 ) ;
if ( ! V_12 -> V_49 ) {
F_9 ( & V_20 -> V_14 , L_14 ) ;
V_6 = - V_17 ;
goto V_50;
}
V_24 = F_24 ( V_12 ) ;
V_24 -> V_51 = (struct V_52 * ) V_2 -> V_40 ;
V_2 -> V_53 = V_7 -> V_53 ;
if ( V_2 -> V_53 == V_54 ) {
#ifdef F_25
V_2 -> V_55 = F_26 ( V_56 ) ;
if ( F_27 ( V_2 -> V_55 ) ) {
F_9 ( & V_20 -> V_14 ,
L_15 ) ;
V_6 = - V_17 ;
goto V_50;
}
V_6 = F_28 ( V_2 -> V_55 -> V_55 , & V_12 -> V_15 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_20 -> V_14 ,
L_16 ) ;
V_6 = - V_17 ;
goto V_57;
}
F_6 ( V_2 ) ;
#else
F_29 ( & V_20 -> V_14 , L_17
L_18 ) ;
goto V_50;
#endif
} else {
if ( V_7 -> V_58 )
V_7 -> V_58 ( 1 ) ;
V_6 = F_30 ( V_12 , V_12 -> V_49 , V_59 ) ;
if ( V_6 ) {
F_9 ( & V_20 -> V_14 ,
L_19 , V_6 ) ;
goto V_60;
}
}
if ( V_7 -> V_61 )
V_7 -> V_61 ( V_2 -> V_43 , V_2 -> V_9 ) ;
F_29 ( & V_20 -> V_14 ,
L_20
L_21 , V_12 -> V_48 , V_12 -> V_49 ,
V_2 -> V_53 == V_54 ? L_22 : L_23 ) ;
return 0 ;
V_60:
if ( V_7 -> V_58 )
V_7 -> V_58 ( 0 ) ;
#ifdef F_25
V_57:
if ( ! F_27 ( V_2 -> V_55 ) )
F_31 ( V_2 -> V_55 ) ;
#endif
V_50:
F_6 ( V_2 ) ;
V_41:
F_32 ( V_2 -> V_40 ) ;
V_39:
F_32 ( V_2 -> V_9 ) ;
V_35:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- )
F_33 ( V_2 -> V_5 [ V_27 ] ) ;
F_15 ( V_20 , NULL ) ;
F_34 ( V_2 ) ;
V_33:
F_35 ( V_12 ) ;
return V_6 ;
}
static int F_36 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_37 ( V_20 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_27 ;
if ( V_12 -> V_62 )
F_38 ( V_12 ) ;
if ( ! F_27 ( V_2 -> V_55 ) ) {
F_28 ( V_2 -> V_55 -> V_55 , NULL ) ;
F_31 ( V_2 -> V_55 ) ;
}
if ( V_2 -> V_53 == V_63 ) {
if ( V_2 -> V_7 -> V_58 )
V_2 -> V_7 -> V_58 ( 0 ) ;
F_6 ( V_2 ) ;
}
F_32 ( V_2 -> V_40 ) ;
F_32 ( V_2 -> V_9 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_4 ; V_27 ++ )
F_33 ( V_2 -> V_5 [ V_27 ] ) ;
F_15 ( V_20 , NULL ) ;
F_34 ( V_2 ) ;
F_35 ( V_12 ) ;
return 0 ;
}
static void F_39 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_37 ( V_20 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( ! V_12 -> V_62 )
return;
if ( V_12 -> V_64 -> V_65 )
V_12 -> V_64 -> V_65 ( V_12 ) ;
}
