static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 = V_5 -> V_7 ;
unsigned long long V_8 ;
struct V_9 V_10 ;
union V_11 V_12 ;
T_2 V_13 = V_14 ;
V_10 . V_15 = 1 ;
V_10 . V_16 = & V_12 ;
V_12 . type = V_17 ;
V_12 . integer . V_8 = V_18 ;
V_13 = F_2 ( V_7 , V_19 ,
& V_10 , & V_8 ) ;
if ( F_3 ( V_13 ) )
return - V_20 ;
if ( ! V_8 )
return - V_21 ;
* V_3 = V_8 - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned long * V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 = V_5 -> V_7 ;
unsigned long long V_22 ;
struct V_9 V_10 ;
union V_11 V_12 ;
T_2 V_13 = V_14 ;
V_10 . V_15 = 1 ;
V_10 . V_16 = & V_12 ;
V_12 . type = V_17 ;
V_12 . integer . V_8 = V_23 ;
V_13 = F_2 ( V_7 , V_19 ,
& V_10 , & V_22 ) ;
if ( F_3 ( V_13 ) )
return - V_20 ;
* V_8 = V_22 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 = V_5 -> V_7 ;
struct V_9 V_10 ;
union V_11 V_12 ;
T_2 V_13 ;
unsigned long long V_25 ;
unsigned long V_3 ;
if ( F_1 ( V_2 , & V_3 ) )
return - V_20 ;
if ( V_24 > V_3 )
return - V_21 ;
V_10 . V_15 = 1 ;
V_10 . V_16 = & V_12 ;
V_12 . type = V_17 ;
V_12 . integer . V_8 = V_24 ;
V_13 =
F_2 ( V_7 , V_26 , & V_10 ,
& V_25 ) ;
F_6 ( L_1 , V_24 , V_13 ) ;
if ( F_3 ( V_13 ) )
return - V_20 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
int V_22 = - V_27 ;
T_2 V_13 = V_14 ;
T_1 V_28 ;
struct V_1 * V_2 ;
if ( ! V_5 )
return - V_21 ;
V_13 = F_8 ( V_5 -> V_7 , V_19 , & V_28 ) ;
if ( F_3 ( V_13 ) )
goto V_29;
V_13 = F_8 ( V_5 -> V_7 , V_26 , & V_28 ) ;
if ( F_3 ( V_13 ) )
goto V_29;
V_2 = F_9 ( L_2 , V_5 ,
& V_30 ) ;
if ( F_10 ( V_2 ) ) {
V_22 = F_11 ( V_2 ) ;
goto V_29;
}
V_5 -> V_31 = V_2 ;
V_22 = F_12 ( & V_5 -> V_32 . V_33 ,
& V_2 -> V_5 . V_33 , L_3 ) ;
if ( V_22 )
goto V_34;
V_22 = F_12 ( & V_2 -> V_5 . V_33 ,
& V_5 -> V_32 . V_33 , L_4 ) ;
if ( V_22 ) {
F_13 ( & V_5 -> V_32 . V_33 , L_3 ) ;
goto V_34;
}
V_29:
return V_22 ;
V_34:
F_14 ( V_2 ) ;
return V_22 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( ! V_5 || ! V_2 )
return - V_21 ;
F_13 ( & V_5 -> V_32 . V_33 , L_3 ) ;
F_13 ( & V_2 -> V_5 . V_33 , L_4 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_17 ( T_1 V_7 , int V_35 ,
unsigned long long * V_8 )
{
T_2 V_13 ;
if ( ( V_35 != 0 && V_35 != 1 ) || ! V_8 )
return - V_21 ;
V_13 = F_2 ( V_7 , V_35 ? V_36 : V_37 ,
NULL , V_8 ) ;
if ( F_3 ( V_13 ) )
return - V_38 ;
return 0 ;
}
static int F_18 ( T_1 V_7 , int V_35 , int V_8 )
{
T_2 V_13 ;
union V_11 V_12 = {
V_17
} ;
struct V_9 args = {
1 , & V_12
} ;
unsigned long long V_25 ;
if ( V_35 != 0 && V_35 != 1 )
return - V_21 ;
V_13 = F_2 ( V_7 , V_35 ? V_37 : V_36 ,
NULL , & V_25 ) ;
if ( F_3 ( V_13 ) )
return - V_38 ;
if ( ( V_35 && V_8 < V_25 ) || ( ! V_35 && V_8 > V_25 ) )
return - V_21 ;
V_12 . integer . V_8 = V_8 ;
V_13 = F_2 ( V_7 , V_35 ? V_39 : V_40 ,
& args , & V_25 ) ;
if ( F_3 ( V_13 ) )
return - V_38 ;
return 0 ;
}
static T_3 F_19 ( struct V_5 * V_32 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_20 ( V_42 ) ;
unsigned long long V_8 ;
int V_22 ;
V_22 = F_17 ( V_45 -> V_7 , 0 , & V_8 ) ;
return V_22 ? V_22 : sprintf ( V_43 , L_5 , F_21 ( V_8 ) ) ;
}
static T_3 F_22 ( struct V_5 * V_32 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_20 ( V_42 ) ;
unsigned long long V_8 ;
int V_22 ;
V_22 = F_17 ( V_45 -> V_7 , 1 , & V_8 ) ;
return V_22 ? V_22 : sprintf ( V_43 , L_5 , F_21 ( V_8 ) ) ;
}
static T_3 F_23 ( struct V_5 * V_32 ,
struct V_41 * V_42 ,
const char * V_43 , T_4 V_15 )
{
struct V_44 * V_45 = F_20 ( V_42 ) ;
int V_8 ;
int V_22 ;
if ( ! sscanf ( V_43 , L_6 , & V_8 ) )
return - V_21 ;
if ( V_8 < 0 )
return - V_21 ;
V_22 = F_18 ( V_45 -> V_7 , 0 , F_24 ( V_8 ) ) ;
return V_22 ? V_22 : V_15 ;
}
static T_3 F_25 ( struct V_5 * V_32 ,
struct V_41 * V_42 ,
const char * V_43 , T_4 V_15 )
{
struct V_44 * V_45 = F_20 ( V_42 ) ;
int V_8 ;
int V_22 ;
if ( ! sscanf ( V_43 , L_6 , & V_8 ) )
return - V_21 ;
if ( V_8 < 0 )
return - V_21 ;
V_22 = F_18 ( V_45 -> V_7 , 1 , F_24 ( V_8 ) ) ;
return V_22 ? V_22 : V_15 ;
}
static T_3 F_26 ( struct V_5 * V_32 ,
struct V_41 * V_45 , char * V_43 )
{
T_2 V_13 ;
unsigned long long V_46 ;
V_13 = F_2 ( NULL , V_47 , NULL , & V_46 ) ;
if ( F_3 ( V_13 ) )
return - V_27 ;
return sprintf ( V_43 , L_7 , V_46 ? L_8 : L_9 ) ;
}
static int F_27 ( char * V_48 , T_5 V_49 , void * V_50 ,
void * V_51 , struct V_5 * V_32 ,
T_1 V_7 )
{
struct V_44 * V_45 ;
int V_22 ;
V_45 = F_28 ( sizeof( struct V_44 ) , V_52 ) ;
if ( ! V_45 )
return - V_53 ;
F_29 ( & V_45 -> V_45 . V_45 ) ;
V_45 -> V_45 . V_45 . V_48 = V_48 ;
V_45 -> V_45 . V_45 . V_49 = V_49 ;
V_45 -> V_45 . V_50 = V_50 ;
V_45 -> V_45 . V_51 = V_51 ;
V_45 -> V_5 = V_32 ;
V_45 -> V_7 = V_7 ;
V_22 = F_30 ( V_32 , & V_45 -> V_45 ) ;
if ( V_22 ) {
F_31 ( V_45 ) ;
return V_22 ;
}
F_32 ( & V_54 ) ;
F_33 ( & V_45 -> V_55 , & V_56 ) ;
F_34 ( & V_54 ) ;
return 0 ;
}
static T_2 F_35 ( T_1 V_7 , T_6 V_57 ,
void * V_58 , void * * V_59 )
{
T_2 V_13 ;
T_1 V_28 ;
struct V_60 * V_61 ;
int V_22 ;
V_22 = F_36 ( V_7 , ( void * * ) & V_61 ) ;
if ( V_22 )
return 0 ;
V_13 = F_8 ( V_7 , V_37 , & V_28 ) ;
if ( F_3 ( V_13 ) )
return ( V_13 == V_62 ) ? V_14 : V_13 ;
V_13 = F_8 ( V_7 , V_40 , & V_28 ) ;
if ( F_3 ( V_13 ) )
return ( V_13 == V_62 ) ? V_14 : V_13 ;
V_22 = F_27 ( L_10 , 0644 ,
F_19 , F_23 ,
& V_61 -> V_5 , V_7 ) ;
if ( V_22 )
return V_63 ;
V_13 = F_8 ( V_7 , V_36 , & V_28 ) ;
if ( F_3 ( V_13 ) )
goto V_64;
V_13 = F_8 ( V_7 , V_39 , & V_28 ) ;
if ( F_3 ( V_13 ) )
goto V_64;
V_22 = F_27 ( L_11 , 0644 ,
F_22 , F_25 ,
& V_61 -> V_5 , V_7 ) ;
if ( V_22 ) {
F_37 () ;
return V_63 ;
}
V_22 = F_27 ( L_12 , 0444 ,
F_26 , NULL ,
& V_61 -> V_5 , V_7 ) ;
if ( V_22 ) {
F_37 () ;
return V_63 ;
}
return V_14 ;
V_64:
if ( V_13 == V_62 )
return V_14 ;
F_37 () ;
return V_13 ;
}
static void F_37 ( void )
{
struct V_44 * V_65 , * V_66 ;
F_32 ( & V_54 ) ;
F_38 (pos, next, &intel_menlow_attr_list, node) {
F_39 ( & V_65 -> V_55 ) ;
F_40 ( V_65 -> V_5 , & V_65 -> V_45 ) ;
F_31 ( V_65 ) ;
}
F_34 ( & V_54 ) ;
return;
}
static int T_7 F_41 ( void )
{
int V_22 = - V_27 ;
T_2 V_13 ;
unsigned long long V_67 ;
if ( V_68 )
return V_22 ;
V_13 = F_2 ( NULL , V_47 , NULL , & V_67 ) ;
if ( F_3 ( V_13 ) || ! V_67 )
return - V_27 ;
V_22 = F_42 ( & V_69 ) ;
if ( V_22 )
return V_22 ;
V_13 = F_43 ( V_70 , V_71 ,
V_72 ,
F_35 , NULL , NULL , NULL ) ;
if ( F_3 ( V_13 ) ) {
F_44 ( & V_69 ) ;
return - V_27 ;
}
return 0 ;
}
static void T_8 F_45 ( void )
{
F_44 ( & V_69 ) ;
F_37 () ;
}
