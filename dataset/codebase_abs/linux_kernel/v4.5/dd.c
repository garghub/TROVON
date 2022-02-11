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
void F_22 ( void )
{
V_16 = true ;
F_23 () ;
}
void F_24 ( void )
{
V_16 = false ;
F_18 () ;
}
static int F_25 ( void )
{
V_14 = F_26 ( L_4 ) ;
if ( F_27 ( ! V_14 ) )
return - V_17 ;
V_12 = true ;
F_18 () ;
F_28 ( V_14 ) ;
return 0 ;
}
bool F_29 ( struct V_3 * V_4 )
{
return V_4 -> V_9 && F_30 ( & V_4 -> V_9 -> V_18 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
if ( F_29 ( V_4 ) ) {
F_32 ( V_19 L_5 ,
V_20 , F_33 ( & V_4 -> V_21 ) ) ;
return;
}
F_34 ( L_6 , V_4 -> V_22 -> V_23 ,
V_20 , F_35 ( V_4 ) ) ;
F_36 ( & V_4 -> V_9 -> V_18 , & V_4 -> V_22 -> V_9 -> V_24 ) ;
F_37 ( V_4 ) ;
F_17 ( V_4 ) ;
F_18 () ;
if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_25 -> V_9 -> V_26 ,
V_27 , V_4 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
int V_28 ;
if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_25 -> V_9 -> V_26 ,
V_29 , V_4 ) ;
V_28 = F_40 ( & V_4 -> V_22 -> V_9 -> V_21 , & V_4 -> V_21 ,
F_33 ( & V_4 -> V_21 ) ) ;
if ( V_28 == 0 ) {
V_28 = F_40 ( & V_4 -> V_21 , & V_4 -> V_22 -> V_9 -> V_21 ,
L_7 ) ;
if ( V_28 )
F_41 ( & V_4 -> V_22 -> V_9 -> V_21 ,
F_33 ( & V_4 -> V_21 ) ) ;
}
return V_28 ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = V_4 -> V_22 ;
if ( V_31 ) {
F_41 ( & V_31 -> V_9 -> V_21 , F_33 ( & V_4 -> V_21 ) ) ;
F_41 ( & V_4 -> V_21 , L_7 ) ;
}
}
int F_43 ( struct V_3 * V_4 )
{
int V_28 ;
V_28 = F_39 ( V_4 ) ;
if ( ! V_28 )
F_31 ( V_4 ) ;
else if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_25 -> V_9 -> V_26 ,
V_32 , V_4 ) ;
return V_28 ;
}
static int F_44 ( struct V_3 * V_4 , struct V_30 * V_31 )
{
int V_28 = - V_33 ;
int V_34 = F_45 ( & V_13 ) ;
if ( V_16 ) {
F_12 ( V_4 , L_8 , V_31 -> V_23 ) ;
F_15 ( V_4 ) ;
return V_28 ;
}
F_19 ( & V_35 ) ;
F_34 ( L_9 ,
V_31 -> V_25 -> V_23 , V_20 , V_31 -> V_23 , F_35 ( V_4 ) ) ;
F_27 ( ! F_3 ( & V_4 -> V_36 ) ) ;
V_4 -> V_22 = V_31 ;
V_28 = F_46 ( V_4 ) ;
if ( V_28 )
goto V_37;
if ( F_39 ( V_4 ) ) {
F_32 ( V_38 L_10 ,
V_20 , F_35 ( V_4 ) ) ;
goto V_39;
}
if ( V_4 -> V_40 && V_4 -> V_40 -> V_41 ) {
V_28 = V_4 -> V_40 -> V_41 ( V_4 ) ;
if ( V_28 )
goto V_39;
}
F_47 ( V_4 ) ;
if ( V_4 -> V_25 -> V_42 ) {
V_28 = V_4 -> V_25 -> V_42 ( V_4 ) ;
if ( V_28 )
goto V_39;
} else if ( V_31 -> V_42 ) {
V_28 = V_31 -> V_42 ( V_4 ) ;
if ( V_28 )
goto V_39;
}
F_48 ( V_4 ) ;
if ( V_4 -> V_40 && V_4 -> V_40 -> V_43 )
V_4 -> V_40 -> V_43 ( V_4 ) ;
F_31 ( V_4 ) ;
V_28 = 1 ;
F_34 ( L_11 ,
V_31 -> V_25 -> V_23 , V_20 , F_35 ( V_4 ) , V_31 -> V_23 ) ;
goto V_44;
V_39:
if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_25 -> V_9 -> V_26 ,
V_32 , V_4 ) ;
V_37:
F_49 ( V_4 ) ;
F_42 ( V_4 ) ;
V_4 -> V_22 = NULL ;
F_50 ( V_4 , NULL ) ;
if ( V_4 -> V_40 && V_4 -> V_40 -> V_45 )
V_4 -> V_40 -> V_45 ( V_4 ) ;
F_51 ( V_4 ) ;
switch ( V_28 ) {
case - V_33 :
F_12 ( V_4 , L_12 , V_31 -> V_23 ) ;
F_15 ( V_4 ) ;
if ( V_34 != F_45 ( & V_13 ) )
F_18 () ;
break;
case - V_46 :
case - V_47 :
F_34 ( L_13 ,
V_31 -> V_23 , F_35 ( V_4 ) , V_28 ) ;
break;
default:
F_32 ( V_19
L_14 ,
V_31 -> V_23 , F_35 ( V_4 ) , V_28 ) ;
}
V_28 = 0 ;
V_44:
F_52 ( & V_35 ) ;
F_53 ( & V_48 ) ;
return V_28 ;
}
int F_54 ( void )
{
F_34 ( L_15 , V_20 ,
F_45 ( & V_35 ) ) ;
if ( F_45 ( & V_35 ) )
return - V_49 ;
return 0 ;
}
void F_23 ( void )
{
if ( V_12 )
F_28 ( V_14 ) ;
F_55 ( V_48 , F_45 ( & V_35 ) == 0 ) ;
F_56 () ;
}
int F_57 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
int V_28 = 0 ;
if ( ! F_58 ( V_4 ) )
return - V_46 ;
F_34 ( L_16 ,
V_31 -> V_25 -> V_23 , V_20 , F_35 ( V_4 ) , V_31 -> V_23 ) ;
if ( V_4 -> V_50 )
F_59 ( V_4 -> V_50 ) ;
F_60 ( V_4 ) ;
V_28 = F_44 ( V_4 , V_31 ) ;
F_61 ( V_4 ) ;
if ( V_4 -> V_50 )
F_62 ( V_4 -> V_50 ) ;
return V_28 ;
}
bool F_63 ( struct V_30 * V_31 )
{
switch ( V_31 -> V_51 ) {
case V_52 :
return true ;
case V_53 :
return false ;
default:
if ( F_64 ( V_31 -> V_54 ) )
return true ;
return false ;
}
}
static int F_65 ( struct V_30 * V_31 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_3 * V_4 = V_57 -> V_4 ;
bool V_58 ;
if ( V_4 -> V_22 )
return - V_49 ;
if ( ! F_66 ( V_31 , V_4 ) )
return 0 ;
V_58 = F_63 ( V_31 ) ;
if ( V_58 )
V_57 -> V_59 = true ;
if ( V_57 -> V_60 && V_58 != V_57 -> V_61 )
return 0 ;
return F_57 ( V_31 , V_4 ) ;
}
static void F_67 ( void * V_62 , T_1 V_63 )
{
struct V_3 * V_4 = V_62 ;
struct V_56 V_57 = {
. V_4 = V_4 ,
. V_60 = true ,
. V_61 = true ,
} ;
F_68 ( V_4 ) ;
if ( V_4 -> V_50 )
F_59 ( V_4 -> V_50 ) ;
F_69 ( V_4 -> V_25 , NULL , & V_57 , F_65 ) ;
F_12 ( V_4 , L_17 ) ;
F_61 ( V_4 ) ;
if ( V_4 -> V_50 )
F_62 ( V_4 -> V_50 ) ;
F_70 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static int F_71 ( struct V_3 * V_4 , bool V_64 )
{
int V_28 = 0 ;
F_68 ( V_4 ) ;
if ( V_4 -> V_22 ) {
if ( F_29 ( V_4 ) ) {
V_28 = 1 ;
goto V_65;
}
V_28 = F_43 ( V_4 ) ;
if ( V_28 == 0 )
V_28 = 1 ;
else {
V_4 -> V_22 = NULL ;
V_28 = 0 ;
}
} else {
struct V_56 V_57 = {
. V_4 = V_4 ,
. V_60 = V_64 ,
. V_61 = false ,
} ;
if ( V_4 -> V_50 )
F_59 ( V_4 -> V_50 ) ;
V_28 = F_69 ( V_4 -> V_25 , NULL , & V_57 ,
F_65 ) ;
if ( ! V_28 && V_64 && V_57 . V_59 ) {
F_12 ( V_4 , L_18 ) ;
F_7 ( V_4 ) ;
F_72 ( F_67 , V_4 ) ;
} else {
F_61 ( V_4 ) ;
}
if ( V_4 -> V_50 )
F_62 ( V_4 -> V_50 ) ;
}
V_65:
F_70 ( V_4 ) ;
return V_28 ;
}
int F_73 ( struct V_3 * V_4 )
{
return F_71 ( V_4 , false ) ;
}
void F_74 ( struct V_3 * V_4 )
{
F_71 ( V_4 , true ) ;
}
static int F_75 ( struct V_3 * V_4 , void * V_57 )
{
struct V_30 * V_31 = V_57 ;
if ( ! F_66 ( V_31 , V_4 ) )
return 0 ;
if ( V_4 -> V_50 )
F_68 ( V_4 -> V_50 ) ;
F_68 ( V_4 ) ;
if ( ! V_4 -> V_22 )
F_57 ( V_31 , V_4 ) ;
F_70 ( V_4 ) ;
if ( V_4 -> V_50 )
F_70 ( V_4 -> V_50 ) ;
return 0 ;
}
int F_76 ( struct V_30 * V_31 )
{
return F_77 ( V_31 -> V_25 , NULL , V_31 , F_75 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
struct V_30 * V_31 ;
V_31 = V_4 -> V_22 ;
if ( V_31 ) {
if ( F_63 ( V_31 ) )
F_56 () ;
F_59 ( V_4 ) ;
F_42 ( V_4 ) ;
if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_25 -> V_9 -> V_26 ,
V_66 ,
V_4 ) ;
F_79 ( V_4 ) ;
if ( V_4 -> V_25 && V_4 -> V_25 -> remove )
V_4 -> V_25 -> remove ( V_4 ) ;
else if ( V_31 -> remove )
V_31 -> remove ( V_4 ) ;
F_49 ( V_4 ) ;
V_4 -> V_22 = NULL ;
F_50 ( V_4 , NULL ) ;
if ( V_4 -> V_40 && V_4 -> V_40 -> V_45 )
V_4 -> V_40 -> V_45 ( V_4 ) ;
F_51 ( V_4 ) ;
F_80 ( & V_4 -> V_9 -> V_18 ) ;
F_37 ( V_4 ) ;
if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_25 -> V_9 -> V_26 ,
V_67 ,
V_4 ) ;
}
}
void F_81 ( struct V_3 * V_4 )
{
F_68 ( V_4 ) ;
F_78 ( V_4 ) ;
F_70 ( V_4 ) ;
}
void F_82 ( struct V_30 * V_31 )
{
struct V_5 * V_68 ;
struct V_3 * V_4 ;
for (; ; ) {
F_83 ( & V_31 -> V_9 -> V_24 . V_69 ) ;
if ( F_3 ( & V_31 -> V_9 -> V_24 . V_70 ) ) {
F_84 ( & V_31 -> V_9 -> V_24 . V_69 ) ;
break;
}
V_68 = F_85 ( V_31 -> V_9 -> V_24 . V_70 . V_71 ,
struct V_5 ,
V_18 . V_72 ) ;
V_4 = V_68 -> V_3 ;
F_7 ( V_4 ) ;
F_84 ( & V_31 -> V_9 -> V_24 . V_69 ) ;
if ( V_4 -> V_50 )
F_68 ( V_4 -> V_50 ) ;
F_68 ( V_4 ) ;
if ( V_4 -> V_22 == V_31 )
F_78 ( V_4 ) ;
F_70 ( V_4 ) ;
if ( V_4 -> V_50 )
F_70 ( V_4 -> V_50 ) ;
F_14 ( V_4 ) ;
}
}
