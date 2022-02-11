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
F_19 ( & V_13 ) ;
F_20 ( & V_11 ,
& V_8 ) ;
F_8 ( & V_7 ) ;
F_21 ( V_14 , & V_15 ) ;
}
static int F_22 ( void )
{
V_14 = F_23 ( L_4 ) ;
if ( F_24 ( ! V_14 ) )
return - V_16 ;
V_12 = true ;
F_18 () ;
F_25 ( V_14 ) ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
if ( F_27 ( & V_4 -> V_9 -> V_17 ) ) {
F_28 ( V_18 L_5 ,
V_19 , F_29 ( & V_4 -> V_20 ) ) ;
return;
}
F_30 ( L_6 , V_4 -> V_21 -> V_22 ,
V_19 , F_31 ( V_4 ) ) ;
F_32 ( & V_4 -> V_9 -> V_17 , & V_4 -> V_21 -> V_9 -> V_23 ) ;
F_17 ( V_4 ) ;
F_18 () ;
if ( V_4 -> V_24 )
F_33 ( & V_4 -> V_24 -> V_9 -> V_25 ,
V_26 , V_4 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_24 )
F_33 ( & V_4 -> V_24 -> V_9 -> V_25 ,
V_28 , V_4 ) ;
V_27 = F_35 ( & V_4 -> V_21 -> V_9 -> V_20 , & V_4 -> V_20 ,
F_29 ( & V_4 -> V_20 ) ) ;
if ( V_27 == 0 ) {
V_27 = F_35 ( & V_4 -> V_20 , & V_4 -> V_21 -> V_9 -> V_20 ,
L_7 ) ;
if ( V_27 )
F_36 ( & V_4 -> V_21 -> V_9 -> V_20 ,
F_29 ( & V_4 -> V_20 ) ) ;
}
return V_27 ;
}
static void F_37 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_21 ;
if ( V_30 ) {
F_36 ( & V_30 -> V_9 -> V_20 , F_29 ( & V_4 -> V_20 ) ) ;
F_36 ( & V_4 -> V_20 , L_7 ) ;
}
}
int F_38 ( struct V_3 * V_4 )
{
int V_27 ;
V_27 = F_34 ( V_4 ) ;
if ( ! V_27 )
F_26 ( V_4 ) ;
return V_27 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_29 * V_30 )
{
int V_27 = 0 ;
int V_31 = F_40 ( & V_13 ) ;
F_19 ( & V_32 ) ;
F_30 ( L_8 ,
V_30 -> V_24 -> V_22 , V_19 , V_30 -> V_22 , F_31 ( V_4 ) ) ;
F_24 ( ! F_3 ( & V_4 -> V_33 ) ) ;
V_4 -> V_21 = V_30 ;
V_27 = F_41 ( V_4 ) ;
if ( V_27 )
goto V_34;
if ( F_34 ( V_4 ) ) {
F_28 ( V_35 L_9 ,
V_19 , F_31 ( V_4 ) ) ;
goto V_34;
}
if ( V_4 -> V_24 -> V_36 ) {
V_27 = V_4 -> V_24 -> V_36 ( V_4 ) ;
if ( V_27 )
goto V_34;
} else if ( V_30 -> V_36 ) {
V_27 = V_30 -> V_36 ( V_4 ) ;
if ( V_27 )
goto V_34;
}
F_26 ( V_4 ) ;
V_27 = 1 ;
F_30 ( L_10 ,
V_30 -> V_24 -> V_22 , V_19 , F_31 ( V_4 ) , V_30 -> V_22 ) ;
goto V_37;
V_34:
F_42 ( V_4 ) ;
F_37 ( V_4 ) ;
V_4 -> V_21 = NULL ;
F_43 ( V_4 , NULL ) ;
if ( V_27 == - V_38 ) {
F_44 ( V_4 , L_11 , V_30 -> V_22 ) ;
F_15 ( V_4 ) ;
if ( V_31 != F_40 ( & V_13 ) )
F_18 () ;
} else if ( V_27 != - V_39 && V_27 != - V_40 ) {
F_28 ( V_18
L_12 ,
V_30 -> V_22 , F_31 ( V_4 ) , V_27 ) ;
} else {
F_30 ( L_13 ,
V_30 -> V_22 , F_31 ( V_4 ) , V_27 ) ;
}
V_27 = 0 ;
V_37:
F_45 ( & V_32 ) ;
F_46 ( & V_41 ) ;
return V_27 ;
}
int F_47 ( void )
{
F_30 ( L_14 , V_19 ,
F_40 ( & V_32 ) ) ;
if ( F_40 ( & V_32 ) )
return - V_42 ;
return 0 ;
}
void F_48 ( void )
{
F_49 ( V_41 , F_40 ( & V_32 ) == 0 ) ;
F_50 () ;
}
int F_51 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
int V_27 = 0 ;
if ( ! F_52 ( V_4 ) )
return - V_39 ;
F_30 ( L_15 ,
V_30 -> V_24 -> V_22 , V_19 , F_31 ( V_4 ) , V_30 -> V_22 ) ;
F_53 ( V_4 ) ;
V_27 = F_39 ( V_4 , V_30 ) ;
F_54 ( V_4 ) ;
return V_27 ;
}
static int F_55 ( struct V_29 * V_30 , void * V_43 )
{
struct V_3 * V_4 = V_43 ;
if ( ! F_56 ( V_30 , V_4 ) )
return 0 ;
return F_51 ( V_30 , V_4 ) ;
}
int F_57 ( struct V_3 * V_4 )
{
int V_27 = 0 ;
F_58 ( V_4 ) ;
if ( V_4 -> V_21 ) {
if ( F_27 ( & V_4 -> V_9 -> V_17 ) ) {
V_27 = 1 ;
goto V_44;
}
V_27 = F_38 ( V_4 ) ;
if ( V_27 == 0 )
V_27 = 1 ;
else {
V_4 -> V_21 = NULL ;
V_27 = 0 ;
}
} else {
V_27 = F_59 ( V_4 -> V_24 , NULL , V_4 , F_55 ) ;
F_54 ( V_4 ) ;
}
V_44:
F_60 ( V_4 ) ;
return V_27 ;
}
static int F_61 ( struct V_3 * V_4 , void * V_43 )
{
struct V_29 * V_30 = V_43 ;
if ( ! F_56 ( V_30 , V_4 ) )
return 0 ;
if ( V_4 -> V_45 )
F_58 ( V_4 -> V_45 ) ;
F_58 ( V_4 ) ;
if ( ! V_4 -> V_21 )
F_51 ( V_30 , V_4 ) ;
F_60 ( V_4 ) ;
if ( V_4 -> V_45 )
F_60 ( V_4 -> V_45 ) ;
return 0 ;
}
int F_62 ( struct V_29 * V_30 )
{
return F_63 ( V_30 -> V_24 , NULL , V_30 , F_61 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_29 * V_30 ;
V_30 = V_4 -> V_21 ;
if ( V_30 ) {
F_65 ( V_4 ) ;
F_37 ( V_4 ) ;
if ( V_4 -> V_24 )
F_33 ( & V_4 -> V_24 -> V_9 -> V_25 ,
V_46 ,
V_4 ) ;
F_66 ( V_4 ) ;
if ( V_4 -> V_24 && V_4 -> V_24 -> remove )
V_4 -> V_24 -> remove ( V_4 ) ;
else if ( V_30 -> remove )
V_30 -> remove ( V_4 ) ;
F_42 ( V_4 ) ;
V_4 -> V_21 = NULL ;
F_43 ( V_4 , NULL ) ;
F_67 ( & V_4 -> V_9 -> V_17 ) ;
if ( V_4 -> V_24 )
F_33 ( & V_4 -> V_24 -> V_9 -> V_25 ,
V_47 ,
V_4 ) ;
}
}
void F_68 ( struct V_3 * V_4 )
{
F_58 ( V_4 ) ;
F_64 ( V_4 ) ;
F_60 ( V_4 ) ;
}
void F_69 ( struct V_29 * V_30 )
{
struct V_5 * V_48 ;
struct V_3 * V_4 ;
for (; ; ) {
F_70 ( & V_30 -> V_9 -> V_23 . V_49 ) ;
if ( F_3 ( & V_30 -> V_9 -> V_23 . V_50 ) ) {
F_71 ( & V_30 -> V_9 -> V_23 . V_49 ) ;
break;
}
V_48 = F_72 ( V_30 -> V_9 -> V_23 . V_50 . V_51 ,
struct V_5 ,
V_17 . V_52 ) ;
V_4 = V_48 -> V_3 ;
F_7 ( V_4 ) ;
F_71 ( & V_30 -> V_9 -> V_23 . V_49 ) ;
if ( V_4 -> V_45 )
F_58 ( V_4 -> V_45 ) ;
F_58 ( V_4 ) ;
if ( V_4 -> V_21 == V_30 )
F_64 ( V_4 ) ;
F_60 ( V_4 ) ;
if ( V_4 -> V_45 )
F_60 ( V_4 -> V_45 ) ;
F_14 ( V_4 ) ;
}
}
void * F_73 ( const struct V_3 * V_4 )
{
if ( V_4 && V_4 -> V_9 )
return V_4 -> V_9 -> V_53 ;
return NULL ;
}
int F_43 ( struct V_3 * V_4 , void * V_43 )
{
int error ;
if ( ! V_4 -> V_9 ) {
error = F_74 ( V_4 ) ;
if ( error )
return error ;
}
V_4 -> V_9 -> V_53 = V_43 ;
return 0 ;
}
