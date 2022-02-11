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
if ( V_18 -> V_39 ) {
V_20 = F_21 ( V_16 , V_18 , V_11 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_8 ( V_16 , V_18 , V_19 , V_11 ) ;
if ( V_20 )
return V_20 ;
F_22 ( V_11 ) ;
}
V_16 -> V_36 ++ ;
return 0 ;
}
static void F_23 ( struct V_15 * V_16 )
{
struct V_10 * V_11 ;
if ( ! V_16 -> V_36 )
return;
V_11 = & V_16 -> V_35 [ V_16 -> V_36 - 1 ] ;
for (; V_16 -> V_36 ; V_16 -> V_36 -- , V_11 -- ) {
if ( V_11 -> V_12 . V_26 )
F_24 ( V_16 -> V_22 , & V_11 -> V_12 ) ;
if ( V_11 -> V_21 &&
F_25 ( V_11 -> V_21 ) < F_26 ( V_11 -> V_21 ) )
F_14 ( V_16 -> V_22 , L_3 ) ;
}
}
static int F_27 ( void * V_40 , struct V_41 * V_42 ,
struct V_41 * V_43 )
{
struct V_17 * V_44 = F_28 ( V_42 , struct V_17 , V_45 ) ;
struct V_17 * V_46 = F_28 ( V_43 , struct V_17 , V_45 ) ;
return V_44 -> V_19 - V_46 -> V_19 ;
}
static int F_29 ( struct V_15 * V_16 , struct V_47 * V_48 )
{
struct V_49 * V_50 = V_16 -> V_22 -> V_51 , * V_52 ;
unsigned long V_26 , V_53 , V_54 ;
struct V_17 * V_55 , * V_18 ;
struct V_41 V_56 ;
unsigned int V_57 , V_58 = 0 ;
const char * V_25 ;
int V_20 = 0 ;
F_30 ( & V_56 ) ;
V_26 = F_31 ( V_48 ) ;
V_57 = ( V_50 ) ? F_32 ( V_50 ) + 1 : 1 ;
V_55 = F_33 ( ( V_57 ) * sizeof( * V_55 ) , V_28 ) ;
if ( ! V_55 )
return - V_29 ;
V_18 = & V_55 [ 0 ] ;
F_34 (np, child) {
struct V_47 V_59 ;
V_20 = F_35 ( V_52 , 0 , & V_59 ) ;
if ( V_20 < 0 ) {
F_14 ( V_16 -> V_22 ,
L_4 ,
V_52 ) ;
goto V_60;
}
if ( V_59 . V_19 < V_48 -> V_19 || V_59 . V_61 > V_48 -> V_61 ) {
F_14 ( V_16 -> V_22 ,
L_5 ,
V_52 ) ;
V_20 = - V_62 ;
goto V_60;
}
V_18 -> V_19 = V_59 . V_19 - V_48 -> V_19 ;
V_18 -> V_26 = F_31 ( & V_59 ) ;
F_36 ( & V_18 -> V_45 , & V_56 ) ;
if ( F_37 ( V_52 , L_6 , NULL ) )
V_18 -> V_38 = true ;
if ( F_37 ( V_52 , L_7 , NULL ) )
V_18 -> V_21 = true ;
if ( F_37 ( V_52 , L_8 , NULL ) )
V_18 -> V_39 = true ;
if ( ( V_18 -> V_38 || V_18 -> V_21 || V_18 -> V_39 ) &&
V_18 -> V_26 ) {
V_58 ++ ;
V_25 = NULL ;
V_20 = F_38 ( V_52 , L_9 , & V_25 ) ;
if ( V_20 && V_20 != - V_62 ) {
F_14 ( V_16 -> V_22 ,
L_10 ,
V_52 ) ;
goto V_60;
}
if ( ! V_25 )
V_25 = V_52 -> V_27 ;
V_18 -> V_25 = F_39 ( V_16 -> V_22 ,
V_25 , V_28 ) ;
if ( ! V_18 -> V_25 ) {
V_20 = - V_29 ;
goto V_60;
}
F_40 ( V_16 -> V_22 , L_11 ,
V_18 -> V_38 ? L_12 : L_13 , V_18 -> V_25 ,
V_18 -> V_19 , V_18 -> V_19 + V_18 -> V_26 ) ;
} else {
F_40 ( V_16 -> V_22 , L_14 ,
V_18 -> V_19 , V_18 -> V_19 + V_18 -> V_26 ) ;
}
V_18 ++ ;
}
V_52 = NULL ;
V_55 [ V_57 - 1 ] . V_19 = V_26 ;
V_55 [ V_57 - 1 ] . V_26 = 0 ;
F_36 ( & V_55 [ V_57 - 1 ] . V_45 , & V_56 ) ;
F_41 ( NULL , & V_56 , F_27 ) ;
if ( V_58 ) {
V_16 -> V_35 = F_42 ( V_16 -> V_22 ,
V_58 * sizeof( * V_16 -> V_35 ) ,
V_28 ) ;
if ( ! V_16 -> V_35 ) {
V_20 = - V_29 ;
goto V_60;
}
}
V_53 = 0 ;
F_43 (block, &reserve_list, list) {
if ( V_18 -> V_19 < V_53 ) {
F_14 ( V_16 -> V_22 ,
L_15 ,
V_18 -> V_19 , V_53 ) ;
V_20 = - V_62 ;
F_23 ( V_16 ) ;
goto V_60;
}
if ( ( V_18 -> V_38 || V_18 -> V_21 || V_18 -> V_39 ) &&
V_18 -> V_26 ) {
V_20 = F_19 ( V_16 , V_18 ,
V_48 -> V_19 + V_18 -> V_19 ) ;
if ( V_20 ) {
F_23 ( V_16 ) ;
goto V_60;
}
}
if ( V_18 -> V_19 == V_53 ) {
V_53 = V_18 -> V_19 + V_18 -> V_26 ;
continue;
}
V_54 = V_18 -> V_19 - V_53 ;
F_40 ( V_16 -> V_22 , L_16 ,
V_53 , V_53 + V_54 ) ;
V_20 = F_13 ( V_16 -> V_21 ,
( unsigned long ) V_16 -> V_37 + V_53 ,
V_48 -> V_19 + V_53 , V_54 , - 1 ) ;
if ( V_20 < 0 ) {
F_23 ( V_16 ) ;
goto V_60;
}
V_53 = V_18 -> V_19 + V_18 -> V_26 ;
}
V_60:
if ( V_52 )
F_44 ( V_52 ) ;
F_45 ( V_55 ) ;
return V_20 ;
}
static int F_46 ( void )
{
struct V_63 * V_63 ;
T_5 V_64 ;
V_63 = F_47 ( L_17 ) ;
if ( F_11 ( V_63 ) )
return - V_65 ;
return F_48 ( V_63 , V_66 , V_64 ,
V_64 & V_67 ,
10000 , 500000 ) ;
}
static int F_49 ( struct V_68 * V_69 )
{
struct V_15 * V_16 ;
struct V_47 * V_48 ;
T_3 V_26 ;
int V_20 ;
int (* F_50)( void );
V_16 = F_42 ( & V_69 -> V_22 , sizeof( * V_16 ) , V_28 ) ;
if ( ! V_16 )
return - V_29 ;
V_16 -> V_22 = & V_69 -> V_22 ;
V_48 = F_51 ( V_69 , V_70 , 0 ) ;
if ( ! V_48 ) {
F_14 ( V_16 -> V_22 , L_18 ) ;
return - V_62 ;
}
V_26 = F_31 ( V_48 ) ;
if ( ! F_52 ( V_16 -> V_22 , V_48 -> V_19 , V_26 , V_69 -> V_27 ) ) {
F_14 ( V_16 -> V_22 , L_19 ) ;
return - V_71 ;
}
if ( F_53 ( V_69 -> V_22 . V_51 , L_20 ) )
V_16 -> V_37 = F_54 ( V_16 -> V_22 , V_48 -> V_19 , V_26 ) ;
else
V_16 -> V_37 = F_55 ( V_16 -> V_22 , V_48 -> V_19 , V_26 ) ;
if ( ! V_16 -> V_37 )
return - V_29 ;
V_16 -> V_21 = F_9 ( V_16 -> V_22 , F_10 ( V_23 ) ,
V_24 , NULL ) ;
if ( F_11 ( V_16 -> V_21 ) )
return F_12 ( V_16 -> V_21 ) ;
V_20 = F_29 ( V_16 , V_48 ) ;
if ( V_20 )
return V_20 ;
V_16 -> V_72 = F_56 ( V_16 -> V_22 , NULL ) ;
if ( F_11 ( V_16 -> V_72 ) )
V_16 -> V_72 = NULL ;
else
F_57 ( V_16 -> V_72 ) ;
F_58 ( V_69 , V_16 ) ;
F_50 = F_59 ( & V_69 -> V_22 ) ;
if ( F_50 ) {
V_20 = F_50 () ;
if ( V_20 )
return V_20 ;
}
F_40 ( V_16 -> V_22 , L_21 ,
F_26 ( V_16 -> V_21 ) / 1024 , V_16 -> V_37 ) ;
return 0 ;
}
static int F_60 ( struct V_68 * V_69 )
{
struct V_15 * V_16 = F_61 ( V_69 ) ;
F_23 ( V_16 ) ;
if ( F_25 ( V_16 -> V_21 ) < F_26 ( V_16 -> V_21 ) )
F_14 ( V_16 -> V_22 , L_22 ) ;
if ( V_16 -> V_72 )
F_62 ( V_16 -> V_72 ) ;
return 0 ;
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_73 ) ;
}
