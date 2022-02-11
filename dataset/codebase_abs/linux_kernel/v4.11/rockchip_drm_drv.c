int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
V_8 = F_2 ( V_6 -> V_10 , V_4 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_1 ) ;
return V_8 ;
}
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_10 = V_6 -> V_10 ;
if ( ! V_9 )
return;
F_5 ( V_10 , V_4 ) ;
}
int F_6 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
int V_16 = F_7 ( V_13 ) ;
struct V_5 * V_17 = V_13 -> V_4 -> V_7 ;
if ( V_16 >= V_18 )
return - V_19 ;
V_17 -> V_15 [ V_16 ] = V_15 ;
return 0 ;
}
void F_8 ( struct V_12 * V_13 )
{
int V_16 = F_7 ( V_13 ) ;
struct V_5 * V_17 = V_13 -> V_4 -> V_7 ;
if ( V_16 >= V_18 )
return;
V_17 -> V_15 [ V_16 ] = NULL ;
}
static int F_9 ( struct V_1 * V_4 ,
unsigned int V_16 )
{
struct V_5 * V_17 = V_4 -> V_7 ;
struct V_12 * V_13 = F_10 ( V_4 , V_16 ) ;
if ( V_13 && V_17 -> V_15 [ V_16 ] &&
V_17 -> V_15 [ V_16 ] -> V_20 )
return V_17 -> V_15 [ V_16 ] -> V_20 ( V_13 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_4 ,
unsigned int V_16 )
{
struct V_5 * V_17 = V_4 -> V_7 ;
struct V_12 * V_13 = F_10 ( V_4 , V_16 ) ;
if ( V_13 && V_17 -> V_15 [ V_16 ] &&
V_17 -> V_15 [ V_16 ] -> V_20 )
V_17 -> V_15 [ V_16 ] -> F_12 ( V_13 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_21 * V_22 ;
T_1 V_23 , V_24 ;
if ( ! V_9 )
return 0 ;
V_6 -> V_10 = F_14 ( & V_25 ) ;
if ( ! V_6 -> V_10 )
return - V_26 ;
V_22 = & V_6 -> V_10 -> V_22 ;
V_23 = V_22 -> V_27 ;
V_24 = V_22 -> V_28 ;
F_15 ( L_2 ,
V_23 , V_24 ) ;
F_16 ( & V_6 -> V_29 , V_23 , V_24 - V_23 + 1 ) ;
F_17 ( & V_6 -> V_30 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_9 )
return;
F_19 ( & V_6 -> V_29 ) ;
F_20 ( V_6 -> V_10 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_8 ;
V_2 = F_22 ( & V_31 , V_4 ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
F_25 ( V_4 , V_2 ) ;
V_6 = F_26 ( V_2 -> V_4 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 ) {
V_8 = - V_26 ;
goto V_33;
}
V_2 -> V_7 = V_6 ;
F_27 ( & V_6 -> V_34 ) ;
F_28 ( & V_6 -> V_35 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
goto V_36;
V_8 = F_31 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_37;
F_32 ( V_2 ) ;
V_2 -> V_38 = true ;
V_8 = F_33 ( V_2 , V_18 ) ;
if ( V_8 )
goto V_39;
F_34 ( V_2 ) ;
V_8 = F_35 ( V_2 ) ;
if ( V_8 )
goto V_40;
V_8 = F_36 ( V_2 , 0 ) ;
if ( V_8 )
goto V_41;
return 0 ;
V_41:
F_37 ( V_2 ) ;
V_40:
F_38 ( V_2 ) ;
V_39:
F_39 ( V_2 ) ;
F_40 ( V_4 , V_2 ) ;
V_37:
F_18 ( V_2 ) ;
V_36:
F_41 ( V_2 ) ;
V_2 -> V_7 = NULL ;
V_33:
F_42 ( V_2 ) ;
return V_8 ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_44 ( V_4 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_4 , V_2 ) ;
F_18 ( V_2 ) ;
F_41 ( V_2 ) ;
V_2 -> V_7 = NULL ;
F_45 ( V_2 ) ;
F_42 ( V_2 ) ;
F_25 ( V_4 , NULL ) ;
}
static void F_46 ( struct V_1 * V_4 )
{
struct V_5 * V_17 = V_4 -> V_7 ;
F_47 ( & V_17 -> V_42 ) ;
}
static void F_48 ( struct V_1 * V_43 )
{
struct V_5 * V_17 = V_43 -> V_7 ;
F_49 () ;
F_50 ( & V_17 -> V_42 , 1 ) ;
F_51 () ;
}
static void F_52 ( struct V_1 * V_43 )
{
struct V_5 * V_17 = V_43 -> V_7 ;
F_49 () ;
F_50 ( & V_17 -> V_42 , 0 ) ;
F_51 () ;
}
static int F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_43 = F_44 ( V_4 ) ;
struct V_5 * V_17 = V_43 -> V_7 ;
F_54 ( V_43 ) ;
F_48 ( V_43 ) ;
V_17 -> V_44 = F_55 ( V_43 ) ;
if ( F_23 ( V_17 -> V_44 ) ) {
F_52 ( V_43 ) ;
F_56 ( V_43 ) ;
return F_24 ( V_17 -> V_44 ) ;
}
return 0 ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_43 = F_44 ( V_4 ) ;
struct V_5 * V_17 = V_43 -> V_7 ;
F_58 ( V_43 , V_17 -> V_44 ) ;
F_52 ( V_43 ) ;
F_56 ( V_43 ) ;
return 0 ;
}
static int F_59 ( struct V_3 * V_4 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
return V_4 -> V_48 == V_47 ;
}
static void F_60 ( struct V_3 * V_4 ,
struct V_49 * * V_50 ,
struct V_46 * V_51 )
{
struct V_46 * V_52 , * V_53 ;
F_61 (port, ep) {
V_53 = F_62 ( V_52 ) ;
if ( ! V_53 || ! F_63 ( V_53 ) ) {
F_64 ( V_53 ) ;
continue;
} else if ( ! F_63 ( V_53 -> V_54 ) ) {
F_65 ( V_4 , L_3 ,
V_53 -> V_55 ) ;
F_64 ( V_53 ) ;
continue;
}
F_66 ( V_4 , V_50 , F_59 , V_53 ) ;
F_64 ( V_53 ) ;
}
}
static int F_67 ( struct V_56 * V_57 )
{
struct V_3 * V_4 = & V_57 -> V_4 ;
struct V_49 * V_50 = NULL ;
struct V_46 * V_47 = V_4 -> V_48 ;
struct V_46 * V_51 ;
int V_58 ;
if ( ! V_47 )
return - V_59 ;
for ( V_58 = 0 ; ; V_58 ++ ) {
struct V_46 * V_60 ;
V_51 = F_68 ( V_47 , L_4 , V_58 ) ;
if ( ! V_51 )
break;
if ( ! F_63 ( V_51 -> V_54 ) ) {
F_64 ( V_51 ) ;
continue;
}
V_60 = F_68 ( V_51 -> V_54 , L_5 , 0 ) ;
if ( ! V_60 || ! F_63 ( V_60 -> V_54 ) ) {
F_69 ( V_4 , L_6 ,
V_51 -> V_54 -> V_55 ) ;
V_9 = false ;
}
F_64 ( V_60 ) ;
F_66 ( V_4 , & V_50 , F_59 ,
V_51 -> V_54 ) ;
F_64 ( V_51 ) ;
}
if ( V_58 == 0 ) {
F_3 ( V_4 , L_7 ) ;
return - V_59 ;
}
if ( ! V_50 ) {
F_3 ( V_4 , L_8 ) ;
return - V_59 ;
}
for ( V_58 = 0 ; ; V_58 ++ ) {
V_51 = F_68 ( V_47 , L_4 , V_58 ) ;
if ( ! V_51 )
break;
if ( ! F_63 ( V_51 -> V_54 ) ) {
F_64 ( V_51 ) ;
continue;
}
F_60 ( V_4 , & V_50 , V_51 ) ;
F_64 ( V_51 ) ;
}
return F_70 ( V_4 , & V_61 , V_50 ) ;
}
static int F_71 ( struct V_56 * V_57 )
{
F_72 ( & V_57 -> V_4 , & V_61 ) ;
return 0 ;
}
