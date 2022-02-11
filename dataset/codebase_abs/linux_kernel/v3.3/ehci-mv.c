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
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_12 -> V_17 . V_18 ;
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_6 ;
if ( V_2 == NULL ) {
F_10 ( V_16 , L_1 ) ;
return - V_19 ;
}
V_6 = F_11 ( V_12 ) ;
if ( V_6 ) {
F_10 ( V_16 , L_2 , V_6 ) ;
return V_6 ;
}
V_12 -> V_20 = 1 ;
V_14 -> V_21 = 0x20 ;
V_6 = F_12 ( V_14 ) ;
if ( V_6 ) {
F_10 ( V_16 , L_3 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_7 = V_23 -> V_16 . V_25 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
int V_28 , V_6 = - V_19 ;
T_1 V_29 ;
T_2 V_30 ;
if ( ! V_7 ) {
F_10 ( & V_23 -> V_16 , L_4 ) ;
return - V_19 ;
}
if ( F_14 () )
return - V_19 ;
V_12 = F_15 ( & V_31 , & V_23 -> V_16 , L_5 ) ;
if ( ! V_12 )
return - V_32 ;
V_30 = sizeof( * V_2 ) + sizeof( struct V_5 * ) * V_7 -> V_4 ;
V_2 = F_16 ( V_30 , V_33 ) ;
if ( V_2 == NULL ) {
F_10 ( & V_23 -> V_16 , L_6 ) ;
V_6 = - V_32 ;
goto V_34;
}
F_17 ( V_23 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_7 -> V_4 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 ; V_28 ++ ) {
V_2 -> V_5 [ V_28 ] =
F_18 ( & V_23 -> V_16 , V_7 -> V_35 [ V_28 ] ) ;
if ( F_19 ( V_2 -> V_5 [ V_28 ] ) ) {
F_10 ( & V_23 -> V_16 , L_7 ,
V_7 -> V_35 [ V_28 ] ) ;
V_6 = F_20 ( V_2 -> V_5 [ V_28 ] ) ;
goto V_36;
}
}
V_27 = F_21 ( V_23 , V_37 , L_8 ) ;
if ( V_27 == NULL ) {
F_10 ( & V_23 -> V_16 , L_9 ) ;
V_6 = - V_19 ;
goto V_36;
}
V_2 -> V_9 = F_22 ( V_27 -> V_38 , F_23 ( V_27 ) ) ;
if ( V_2 -> V_9 == 0 ) {
F_10 ( & V_23 -> V_16 , L_10 ) ;
V_6 = - V_39 ;
goto V_36;
}
V_27 = F_21 ( V_23 , V_37 , L_11 ) ;
if ( ! V_27 ) {
F_10 ( & V_23 -> V_16 , L_12 ) ;
V_6 = - V_19 ;
goto V_40;
}
V_2 -> V_41 = F_22 ( V_27 -> V_38 , F_23 ( V_27 ) ) ;
if ( V_2 -> V_41 == NULL ) {
F_10 ( & V_23 -> V_16 , L_13 ) ;
V_6 = - V_39 ;
goto V_40;
}
V_6 = F_5 ( V_2 ) ;
if ( V_6 ) {
F_10 ( & V_23 -> V_16 , L_14 , V_6 ) ;
goto V_42;
}
V_29 = F_24 ( V_2 -> V_41 ) & V_43 ;
V_2 -> V_44 =
( void V_45 * ) ( ( unsigned long ) V_2 -> V_41 + V_29 ) ;
V_12 -> V_46 = V_27 -> V_38 ;
V_12 -> V_47 = V_27 -> V_48 - V_27 -> V_38 + 1 ;
V_12 -> V_49 = V_2 -> V_44 ;
V_12 -> V_50 = F_25 ( V_23 , 0 ) ;
if ( ! V_12 -> V_50 ) {
F_10 ( & V_23 -> V_16 , L_15 ) ;
V_6 = - V_19 ;
goto V_51;
}
V_14 = F_8 ( V_12 ) ;
V_14 -> V_52 = (struct V_53 * ) V_2 -> V_41 ;
V_14 -> V_49 = (struct V_54 * ) V_2 -> V_44 ;
V_14 -> V_55 = F_26 ( V_14 , & V_14 -> V_52 -> V_55 ) ;
V_2 -> V_56 = V_7 -> V_56 ;
if ( V_2 -> V_56 == V_57 ) {
#ifdef F_27
V_2 -> V_58 = F_28 () ;
if ( ! V_2 -> V_58 ) {
F_10 ( & V_23 -> V_16 ,
L_16 ) ;
V_6 = - V_19 ;
goto V_51;
}
V_6 = F_29 ( V_2 -> V_58 , & V_12 -> V_17 ) ;
if ( V_6 < 0 ) {
F_10 ( & V_23 -> V_16 ,
L_17 ) ;
V_6 = - V_19 ;
goto V_59;
}
F_6 ( V_2 ) ;
#else
F_30 ( & V_23 -> V_16 , L_18
L_19 ) ;
goto V_51;
#endif
} else {
if ( V_7 -> V_60 )
V_7 -> V_60 ( 1 ) ;
V_6 = F_31 ( V_12 , V_12 -> V_50 , V_61 ) ;
if ( V_6 ) {
F_10 ( & V_23 -> V_16 ,
L_20 , V_6 ) ;
goto V_62;
}
}
if ( V_7 -> V_63 )
V_7 -> V_63 ( V_2 -> V_44 , V_2 -> V_9 ) ;
F_30 ( & V_23 -> V_16 ,
L_21
L_22 , V_12 -> V_49 , V_12 -> V_50 ,
V_2 -> V_56 == V_57 ? L_23 : L_24 ) ;
return 0 ;
V_62:
if ( V_7 -> V_60 )
V_7 -> V_60 ( 0 ) ;
#ifdef F_27
V_59:
if ( V_2 -> V_58 )
F_32 ( V_2 -> V_58 ) ;
#endif
V_51:
F_6 ( V_2 ) ;
V_42:
F_33 ( V_2 -> V_41 ) ;
V_40:
F_33 ( V_2 -> V_9 ) ;
V_36:
for ( V_28 -- ; V_28 >= 0 ; V_28 -- )
F_34 ( V_2 -> V_5 [ V_28 ] ) ;
F_17 ( V_23 , NULL ) ;
F_35 ( V_2 ) ;
V_34:
F_36 ( V_12 ) ;
return V_6 ;
}
static int F_37 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
int V_28 ;
if ( V_12 -> V_64 )
F_39 ( V_12 ) ;
if ( V_2 -> V_58 ) {
F_29 ( V_2 -> V_58 , NULL ) ;
F_32 ( V_2 -> V_58 ) ;
}
if ( V_2 -> V_56 == V_65 ) {
if ( V_2 -> V_7 -> V_60 )
V_2 -> V_7 -> V_60 ( 0 ) ;
F_6 ( V_2 ) ;
}
F_33 ( V_2 -> V_41 ) ;
F_33 ( V_2 -> V_9 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 ; V_28 ++ )
F_34 ( V_2 -> V_5 [ V_28 ] ) ;
F_17 ( V_23 , NULL ) ;
F_35 ( V_2 ) ;
F_36 ( V_12 ) ;
return 0 ;
}
static void F_40 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( ! V_12 -> V_64 )
return;
if ( V_12 -> V_66 -> V_67 )
V_12 -> V_66 -> V_67 ( V_12 ) ;
}
