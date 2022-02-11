static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
V_11 = F_2 ( V_6 , struct V_10 , V_12 ) ;
F_3 ( & V_11 -> V_13 ) ;
F_4 ( V_7 , V_11 -> V_14 + V_8 , V_9 ) ;
F_5 ( & V_11 -> V_13 ) ;
return V_9 ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
V_11 = F_2 ( V_6 , struct V_10 , V_12 ) ;
F_3 ( & V_11 -> V_13 ) ;
F_7 ( V_11 -> V_14 + V_8 , V_7 , V_9 ) ;
F_5 ( & V_11 -> V_13 ) ;
return V_9 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_17 * V_18 ,
T_4 V_19 , struct V_10 * V_11 )
{
int V_20 ;
V_11 -> V_21 = F_9 ( V_16 -> V_22 , F_10 ( V_23 ) ,
V_24 , V_18 -> V_25 ) ;
if ( F_11 ( V_11 -> V_21 ) )
return F_12 ( V_11 -> V_21 ) ;
V_20 = F_13 ( V_11 -> V_21 , ( unsigned long ) V_11 -> V_14 , V_19 ,
V_18 -> V_26 , V_24 ) ;
if ( V_20 < 0 ) {
F_14 ( V_16 -> V_22 , L_1 , V_20 ) ;
return V_20 ;
}
return 0 ;
}
static int F_15 ( struct V_15 * V_16 , struct V_17 * V_18 ,
T_4 V_19 , struct V_10 * V_11 )
{
F_16 ( & V_11 -> V_12 ) ;
V_11 -> V_12 . V_6 . V_27 = F_17 ( V_16 -> V_22 , V_28 ,
L_2 ,
( unsigned long long ) V_19 ) ;
if ( ! V_11 -> V_12 . V_6 . V_27 )
return - V_29 ;
V_11 -> V_12 . V_6 . V_30 = V_31 | V_32 ;
V_11 -> V_12 . V_33 = F_1 ;
V_11 -> V_12 . V_34 = F_6 ;
V_11 -> V_12 . V_26 = V_18 -> V_26 ;
return F_18 ( V_16 -> V_22 , & V_11 -> V_12 ) ;
}
static int F_19 ( struct V_15 * V_16 , struct V_17 * V_18 ,
T_4 V_19 )
{
int V_20 ;
struct V_10 * V_11 = & V_16 -> V_35 [ V_16 -> V_36 ] ;
F_20 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = V_16 -> V_37 + V_18 -> V_19 ;
if ( V_18 -> V_21 ) {
V_20 = F_8 ( V_16 , V_18 , V_19 , V_11 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_18 -> V_38 ) {
V_20 = F_15 ( V_16 , V_18 , V_19 , V_11 ) ;
if ( V_20 )
return V_20 ;
}
V_16 -> V_36 ++ ;
return 0 ;
}
static void F_21 ( struct V_15 * V_16 )
{
struct V_10 * V_11 ;
if ( ! V_16 -> V_36 )
return;
V_11 = & V_16 -> V_35 [ V_16 -> V_36 - 1 ] ;
for (; V_16 -> V_36 ; V_16 -> V_36 -- , V_11 -- ) {
if ( V_11 -> V_12 . V_26 )
F_22 ( V_16 -> V_22 , & V_11 -> V_12 ) ;
if ( V_11 -> V_21 &&
F_23 ( V_11 -> V_21 ) < F_24 ( V_11 -> V_21 ) )
F_14 ( V_16 -> V_22 , L_3 ) ;
}
}
static int F_25 ( void * V_39 , struct V_40 * V_41 ,
struct V_40 * V_42 )
{
struct V_17 * V_43 = F_26 ( V_41 , struct V_17 , V_44 ) ;
struct V_17 * V_45 = F_26 ( V_42 , struct V_17 , V_44 ) ;
return V_43 -> V_19 - V_45 -> V_19 ;
}
static int F_27 ( struct V_15 * V_16 , struct V_46 * V_47 )
{
struct V_48 * V_49 = V_16 -> V_22 -> V_50 , * V_51 ;
unsigned long V_26 , V_52 , V_53 ;
struct V_17 * V_54 , * V_18 ;
struct V_40 V_55 ;
unsigned int V_56 , V_57 = 0 ;
const char * V_25 ;
int V_20 = 0 ;
F_28 ( & V_55 ) ;
V_26 = F_29 ( V_47 ) ;
V_56 = ( V_49 ) ? F_30 ( V_49 ) + 1 : 1 ;
V_54 = F_31 ( ( V_56 ) * sizeof( * V_54 ) , V_28 ) ;
if ( ! V_54 )
return - V_29 ;
V_18 = & V_54 [ 0 ] ;
F_32 (np, child) {
struct V_46 V_58 ;
V_20 = F_33 ( V_51 , 0 , & V_58 ) ;
if ( V_20 < 0 ) {
F_14 ( V_16 -> V_22 ,
L_4 ,
V_51 -> V_59 ) ;
goto V_60;
}
if ( V_58 . V_19 < V_47 -> V_19 || V_58 . V_61 > V_47 -> V_61 ) {
F_14 ( V_16 -> V_22 ,
L_5 ,
V_51 -> V_59 ) ;
V_20 = - V_62 ;
goto V_60;
}
V_18 -> V_19 = V_58 . V_19 - V_47 -> V_19 ;
V_18 -> V_26 = F_29 ( & V_58 ) ;
F_34 ( & V_18 -> V_44 , & V_55 ) ;
if ( F_35 ( V_51 , L_6 , NULL ) )
V_18 -> V_38 = true ;
if ( F_35 ( V_51 , L_7 , NULL ) )
V_18 -> V_21 = true ;
if ( ( V_18 -> V_38 || V_18 -> V_21 ) && V_18 -> V_26 ) {
V_57 ++ ;
V_25 = NULL ;
V_20 = F_36 ( V_51 , L_8 , & V_25 ) ;
if ( V_20 && V_20 != - V_62 ) {
F_14 ( V_16 -> V_22 ,
L_9 ,
V_51 -> V_59 ) ;
goto V_60;
}
if ( ! V_25 )
V_25 = V_51 -> V_27 ;
V_18 -> V_25 = F_37 ( V_16 -> V_22 ,
V_25 , V_28 ) ;
if ( ! V_18 -> V_25 )
goto V_60;
F_38 ( V_16 -> V_22 , L_10 ,
V_18 -> V_38 ? L_11 : L_12 , V_18 -> V_25 ,
V_18 -> V_19 , V_18 -> V_19 + V_18 -> V_26 ) ;
} else {
F_38 ( V_16 -> V_22 , L_13 ,
V_18 -> V_19 , V_18 -> V_19 + V_18 -> V_26 ) ;
}
V_18 ++ ;
}
V_51 = NULL ;
V_54 [ V_56 - 1 ] . V_19 = V_26 ;
V_54 [ V_56 - 1 ] . V_26 = 0 ;
F_34 ( & V_54 [ V_56 - 1 ] . V_44 , & V_55 ) ;
F_39 ( NULL , & V_55 , F_25 ) ;
if ( V_57 ) {
V_16 -> V_35 = F_40 ( V_16 -> V_22 ,
V_57 * sizeof( * V_16 -> V_35 ) ,
V_28 ) ;
if ( ! V_16 -> V_35 ) {
V_20 = - V_29 ;
goto V_60;
}
}
V_52 = 0 ;
F_41 (block, &reserve_list, list) {
if ( V_18 -> V_19 < V_52 ) {
F_14 ( V_16 -> V_22 ,
L_14 ,
V_18 -> V_19 , V_52 ) ;
V_20 = - V_62 ;
F_21 ( V_16 ) ;
goto V_60;
}
if ( ( V_18 -> V_38 || V_18 -> V_21 ) && V_18 -> V_26 ) {
V_20 = F_19 ( V_16 , V_18 ,
V_47 -> V_19 + V_18 -> V_19 ) ;
if ( V_20 ) {
F_21 ( V_16 ) ;
goto V_60;
}
}
if ( V_18 -> V_19 == V_52 ) {
V_52 = V_18 -> V_19 + V_18 -> V_26 ;
continue;
}
V_53 = V_18 -> V_19 - V_52 ;
F_38 ( V_16 -> V_22 , L_15 ,
V_52 , V_52 + V_53 ) ;
V_20 = F_13 ( V_16 -> V_21 ,
( unsigned long ) V_16 -> V_37 + V_52 ,
V_47 -> V_19 + V_52 , V_53 , - 1 ) ;
if ( V_20 < 0 ) {
F_21 ( V_16 ) ;
goto V_60;
}
V_52 = V_18 -> V_19 + V_18 -> V_26 ;
}
V_60:
if ( V_51 )
F_42 ( V_51 ) ;
F_43 ( V_54 ) ;
return V_20 ;
}
static int F_44 ( struct V_63 * V_64 )
{
struct V_15 * V_16 ;
struct V_46 * V_47 ;
T_3 V_26 ;
int V_20 ;
V_16 = F_40 ( & V_64 -> V_22 , sizeof( * V_16 ) , V_28 ) ;
if ( ! V_16 )
return - V_29 ;
V_16 -> V_22 = & V_64 -> V_22 ;
V_47 = F_45 ( V_64 , V_65 , 0 ) ;
if ( ! V_47 ) {
F_14 ( V_16 -> V_22 , L_16 ) ;
return - V_62 ;
}
V_26 = F_29 ( V_47 ) ;
if ( ! F_46 ( V_16 -> V_22 , V_47 -> V_19 , V_26 , V_64 -> V_27 ) ) {
F_14 ( V_16 -> V_22 , L_17 ) ;
return - V_66 ;
}
V_16 -> V_37 = F_47 ( V_16 -> V_22 , V_47 -> V_19 , V_26 ) ;
if ( F_11 ( V_16 -> V_37 ) )
return F_12 ( V_16 -> V_37 ) ;
V_16 -> V_21 = F_9 ( V_16 -> V_22 , F_10 ( V_23 ) ,
V_24 , NULL ) ;
if ( F_11 ( V_16 -> V_21 ) )
return F_12 ( V_16 -> V_21 ) ;
V_20 = F_27 ( V_16 , V_47 ) ;
if ( V_20 )
return V_20 ;
V_16 -> V_67 = F_48 ( V_16 -> V_22 , NULL ) ;
if ( F_11 ( V_16 -> V_67 ) )
V_16 -> V_67 = NULL ;
else
F_49 ( V_16 -> V_67 ) ;
F_50 ( V_64 , V_16 ) ;
F_38 ( V_16 -> V_22 , L_18 ,
F_24 ( V_16 -> V_21 ) / 1024 , V_16 -> V_37 ) ;
return 0 ;
}
static int F_51 ( struct V_63 * V_64 )
{
struct V_15 * V_16 = F_52 ( V_64 ) ;
F_21 ( V_16 ) ;
if ( F_23 ( V_16 -> V_21 ) < F_24 ( V_16 -> V_21 ) )
F_14 ( V_16 -> V_22 , L_19 ) ;
if ( V_16 -> V_67 )
F_53 ( V_16 -> V_67 ) ;
return 0 ;
}
static int T_5 F_54 ( void )
{
return F_55 ( & V_68 ) ;
}
