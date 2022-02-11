static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 ( & V_7 ) ;
while ( ! F_3 ( & V_8 ) ) {
V_6 = F_4 ( & V_8 ,
F_5 ( * V_4 -> V_9 ) , V_10 ) ;
V_4 = V_6 -> V_3 ;
F_6 ( & V_6 -> V_10 ) ;
F_7 ( V_4 ) ;
F_8 ( & V_7 ) ;
F_9 () ;
F_10 ( V_4 ) ;
F_11 () ;
F_12 ( V_4 , L_1 ) ;
F_13 ( V_4 ) ;
F_2 ( & V_7 ) ;
F_14 ( V_4 ) ;
}
F_8 ( & V_7 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_2 ( & V_7 ) ;
if ( F_3 ( & V_4 -> V_9 -> V_10 ) ) {
F_12 ( V_4 , L_2 ) ;
F_16 ( & V_4 -> V_9 -> V_10 , & V_11 ) ;
}
F_8 ( & V_7 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_2 ( & V_7 ) ;
if ( ! F_3 ( & V_4 -> V_9 -> V_10 ) ) {
F_12 ( V_4 , L_3 ) ;
F_6 ( & V_4 -> V_9 -> V_10 ) ;
}
F_8 ( & V_7 ) ;
}
static void F_18 ( void )
{
if ( ! V_12 )
return;
F_2 ( & V_7 ) ;
F_19 ( & V_11 ,
& V_8 ) ;
F_8 ( & V_7 ) ;
F_20 ( V_13 , & V_14 ) ;
}
static int F_21 ( void )
{
V_13 = F_22 ( L_4 ) ;
if ( F_23 ( ! V_13 ) )
return - V_15 ;
V_12 = true ;
F_18 () ;
return 0 ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( F_25 ( & V_4 -> V_9 -> V_16 ) ) {
F_26 ( V_17 L_5 ,
V_18 , F_27 ( & V_4 -> V_19 ) ) ;
return;
}
F_28 ( L_6 , F_29 ( V_4 ) ,
V_18 , V_4 -> V_20 -> V_21 ) ;
F_30 ( & V_4 -> V_9 -> V_16 , & V_4 -> V_20 -> V_9 -> V_22 ) ;
F_17 ( V_4 ) ;
F_18 () ;
if ( V_4 -> V_23 )
F_31 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_25 , V_4 ) ;
}
static int F_32 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_23 )
F_31 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_27 , V_4 ) ;
V_26 = F_33 ( & V_4 -> V_20 -> V_9 -> V_19 , & V_4 -> V_19 ,
F_27 ( & V_4 -> V_19 ) ) ;
if ( V_26 == 0 ) {
V_26 = F_33 ( & V_4 -> V_19 , & V_4 -> V_20 -> V_9 -> V_19 ,
L_7 ) ;
if ( V_26 )
F_34 ( & V_4 -> V_20 -> V_9 -> V_19 ,
F_27 ( & V_4 -> V_19 ) ) ;
}
return V_26 ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_20 ;
if ( V_29 ) {
F_34 ( & V_29 -> V_9 -> V_19 , F_27 ( & V_4 -> V_19 ) ) ;
F_34 ( & V_4 -> V_19 , L_7 ) ;
}
}
int F_36 ( struct V_3 * V_4 )
{
int V_26 ;
V_26 = F_32 ( V_4 ) ;
if ( ! V_26 )
F_24 ( V_4 ) ;
return V_26 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_28 * V_29 )
{
int V_26 = 0 ;
F_38 ( & V_30 ) ;
F_28 ( L_8 ,
V_29 -> V_23 -> V_21 , V_18 , V_29 -> V_21 , F_29 ( V_4 ) ) ;
F_23 ( ! F_3 ( & V_4 -> V_31 ) ) ;
V_4 -> V_20 = V_29 ;
if ( F_32 ( V_4 ) ) {
F_26 ( V_32 L_9 ,
V_18 , F_29 ( V_4 ) ) ;
goto V_33;
}
if ( V_4 -> V_23 -> V_34 ) {
V_26 = V_4 -> V_23 -> V_34 ( V_4 ) ;
if ( V_26 )
goto V_33;
} else if ( V_29 -> V_34 ) {
V_26 = V_29 -> V_34 ( V_4 ) ;
if ( V_26 )
goto V_33;
}
F_24 ( V_4 ) ;
V_26 = 1 ;
F_28 ( L_10 ,
V_29 -> V_23 -> V_21 , V_18 , F_29 ( V_4 ) , V_29 -> V_21 ) ;
goto V_35;
V_33:
F_39 ( V_4 ) ;
F_35 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_40 ( V_4 , NULL ) ;
if ( V_26 == - V_36 ) {
F_41 ( V_4 , L_11 , V_29 -> V_21 ) ;
F_15 ( V_4 ) ;
} else if ( V_26 != - V_37 && V_26 != - V_38 ) {
F_26 ( V_17
L_12 ,
V_29 -> V_21 , F_29 ( V_4 ) , V_26 ) ;
} else {
F_28 ( L_13 ,
V_29 -> V_21 , F_29 ( V_4 ) , V_26 ) ;
}
V_26 = 0 ;
V_35:
F_42 ( & V_30 ) ;
F_43 ( & V_39 ) ;
return V_26 ;
}
int F_44 ( void )
{
F_28 ( L_14 , V_18 ,
F_45 ( & V_30 ) ) ;
if ( F_45 ( & V_30 ) )
return - V_40 ;
return 0 ;
}
void F_46 ( void )
{
F_47 ( V_39 , F_45 ( & V_30 ) == 0 ) ;
F_48 () ;
}
int F_49 ( struct V_28 * V_29 , struct V_3 * V_4 )
{
int V_26 = 0 ;
if ( ! F_50 ( V_4 ) )
return - V_37 ;
F_28 ( L_15 ,
V_29 -> V_23 -> V_21 , V_18 , F_29 ( V_4 ) , V_29 -> V_21 ) ;
F_51 ( V_4 ) ;
V_26 = F_37 ( V_4 , V_29 ) ;
F_52 ( V_4 ) ;
return V_26 ;
}
static int F_53 ( struct V_28 * V_29 , void * V_41 )
{
struct V_3 * V_4 = V_41 ;
if ( ! F_54 ( V_29 , V_4 ) )
return 0 ;
return F_49 ( V_29 , V_4 ) ;
}
int F_55 ( struct V_3 * V_4 )
{
int V_26 = 0 ;
F_56 ( V_4 ) ;
if ( V_4 -> V_20 ) {
if ( F_25 ( & V_4 -> V_9 -> V_16 ) ) {
V_26 = 1 ;
goto V_42;
}
V_26 = F_36 ( V_4 ) ;
if ( V_26 == 0 )
V_26 = 1 ;
else {
V_4 -> V_20 = NULL ;
V_26 = 0 ;
}
} else {
V_26 = F_57 ( V_4 -> V_23 , NULL , V_4 , F_53 ) ;
F_52 ( V_4 ) ;
}
V_42:
F_58 ( V_4 ) ;
return V_26 ;
}
static int F_59 ( struct V_3 * V_4 , void * V_41 )
{
struct V_28 * V_29 = V_41 ;
if ( ! F_54 ( V_29 , V_4 ) )
return 0 ;
if ( V_4 -> V_43 )
F_56 ( V_4 -> V_43 ) ;
F_56 ( V_4 ) ;
if ( ! V_4 -> V_20 )
F_49 ( V_29 , V_4 ) ;
F_58 ( V_4 ) ;
if ( V_4 -> V_43 )
F_58 ( V_4 -> V_43 ) ;
return 0 ;
}
int F_60 ( struct V_28 * V_29 )
{
return F_61 ( V_29 -> V_23 , NULL , V_29 , F_59 ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_28 * V_29 ;
V_29 = V_4 -> V_20 ;
if ( V_29 ) {
F_63 ( V_4 ) ;
F_35 ( V_4 ) ;
if ( V_4 -> V_23 )
F_31 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_44 ,
V_4 ) ;
F_64 ( V_4 ) ;
if ( V_4 -> V_23 && V_4 -> V_23 -> remove )
V_4 -> V_23 -> remove ( V_4 ) ;
else if ( V_29 -> remove )
V_29 -> remove ( V_4 ) ;
F_39 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_40 ( V_4 , NULL ) ;
F_65 ( & V_4 -> V_9 -> V_16 ) ;
if ( V_4 -> V_23 )
F_31 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_45 ,
V_4 ) ;
}
}
void F_66 ( struct V_3 * V_4 )
{
F_56 ( V_4 ) ;
F_62 ( V_4 ) ;
F_58 ( V_4 ) ;
}
void F_67 ( struct V_28 * V_29 )
{
struct V_5 * V_46 ;
struct V_3 * V_4 ;
for (; ; ) {
F_68 ( & V_29 -> V_9 -> V_22 . V_47 ) ;
if ( F_3 ( & V_29 -> V_9 -> V_22 . V_48 ) ) {
F_69 ( & V_29 -> V_9 -> V_22 . V_47 ) ;
break;
}
V_46 = F_70 ( V_29 -> V_9 -> V_22 . V_48 . V_49 ,
struct V_5 ,
V_16 . V_50 ) ;
V_4 = V_46 -> V_3 ;
F_7 ( V_4 ) ;
F_69 ( & V_29 -> V_9 -> V_22 . V_47 ) ;
if ( V_4 -> V_43 )
F_56 ( V_4 -> V_43 ) ;
F_56 ( V_4 ) ;
if ( V_4 -> V_20 == V_29 )
F_62 ( V_4 ) ;
F_58 ( V_4 ) ;
if ( V_4 -> V_43 )
F_58 ( V_4 -> V_43 ) ;
F_14 ( V_4 ) ;
}
}
void * F_71 ( const struct V_3 * V_4 )
{
if ( V_4 && V_4 -> V_9 )
return V_4 -> V_9 -> V_51 ;
return NULL ;
}
int F_40 ( struct V_3 * V_4 , void * V_41 )
{
int error ;
if ( ! V_4 -> V_9 ) {
error = F_72 ( V_4 ) ;
if ( error )
return error ;
}
V_4 -> V_9 -> V_51 = V_41 ;
return 0 ;
}
