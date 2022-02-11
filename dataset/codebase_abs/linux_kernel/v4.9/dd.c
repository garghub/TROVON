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
F_21 ( & V_14 ) ;
}
void F_22 ( void )
{
V_15 = true ;
F_23 () ;
}
void F_24 ( void )
{
V_15 = false ;
F_18 () ;
}
static int F_25 ( void )
{
V_12 = true ;
F_18 () ;
F_26 ( & V_14 ) ;
return 0 ;
}
bool F_27 ( struct V_3 * V_4 )
{
return V_4 -> V_9 && F_28 ( & V_4 -> V_9 -> V_16 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
if ( F_27 ( V_4 ) ) {
F_30 ( V_17 L_4 ,
V_18 , F_31 ( & V_4 -> V_19 ) ) ;
return;
}
F_32 ( L_5 , V_4 -> V_20 -> V_21 ,
V_18 , F_33 ( V_4 ) ) ;
F_34 ( & V_4 -> V_9 -> V_16 , & V_4 -> V_20 -> V_9 -> V_22 ) ;
F_35 ( V_4 ) ;
F_17 ( V_4 ) ;
F_18 () ;
if ( V_4 -> V_23 )
F_36 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_25 , V_4 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_23 )
F_36 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_27 , V_4 ) ;
V_26 = F_38 ( & V_4 -> V_20 -> V_9 -> V_19 , & V_4 -> V_19 ,
F_31 ( & V_4 -> V_19 ) ) ;
if ( V_26 == 0 ) {
V_26 = F_38 ( & V_4 -> V_19 , & V_4 -> V_20 -> V_9 -> V_19 ,
L_6 ) ;
if ( V_26 )
F_39 ( & V_4 -> V_20 -> V_9 -> V_19 ,
F_31 ( & V_4 -> V_19 ) ) ;
}
return V_26 ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_20 ;
if ( V_29 ) {
F_39 ( & V_29 -> V_9 -> V_19 , F_31 ( & V_4 -> V_19 ) ) ;
F_39 ( & V_4 -> V_19 , L_6 ) ;
}
}
int F_41 ( struct V_3 * V_4 )
{
int V_26 ;
V_26 = F_37 ( V_4 ) ;
if ( ! V_26 )
F_29 ( V_4 ) ;
else if ( V_4 -> V_23 )
F_36 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_30 , V_4 ) ;
return V_26 ;
}
static int F_42 ( struct V_3 * V_4 , struct V_28 * V_29 )
{
int V_26 = - V_31 ;
int V_32 = F_43 ( & V_13 ) ;
bool V_33 = F_44 ( V_34 ) &&
! V_29 -> V_35 ;
if ( V_15 ) {
F_12 ( V_4 , L_7 , V_29 -> V_21 ) ;
F_15 ( V_4 ) ;
return V_26 ;
}
F_19 ( & V_36 ) ;
F_32 ( L_8 ,
V_29 -> V_23 -> V_21 , V_18 , V_29 -> V_21 , F_33 ( V_4 ) ) ;
F_45 ( ! F_3 ( & V_4 -> V_37 ) ) ;
V_38:
V_4 -> V_20 = V_29 ;
V_26 = F_46 ( V_4 ) ;
if ( V_26 )
goto V_39;
if ( F_37 ( V_4 ) ) {
F_30 ( V_40 L_9 ,
V_18 , F_33 ( V_4 ) ) ;
goto V_41;
}
if ( V_4 -> V_42 && V_4 -> V_42 -> V_43 ) {
V_26 = V_4 -> V_42 -> V_43 ( V_4 ) ;
if ( V_26 )
goto V_41;
}
F_47 ( V_4 ) ;
if ( V_4 -> V_23 -> V_44 ) {
V_26 = V_4 -> V_23 -> V_44 ( V_4 ) ;
if ( V_26 )
goto V_41;
} else if ( V_29 -> V_44 ) {
V_26 = V_29 -> V_44 ( V_4 ) ;
if ( V_26 )
goto V_41;
}
if ( V_33 ) {
V_33 = false ;
if ( V_4 -> V_23 -> remove )
V_4 -> V_23 -> remove ( V_4 ) ;
else if ( V_29 -> remove )
V_29 -> remove ( V_4 ) ;
F_48 ( V_4 ) ;
F_40 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_49 ( V_4 , NULL ) ;
if ( V_4 -> V_42 && V_4 -> V_42 -> V_45 )
V_4 -> V_42 -> V_45 ( V_4 ) ;
F_50 ( V_4 ) ;
goto V_38;
}
F_51 ( V_4 ) ;
if ( V_4 -> V_42 && V_4 -> V_42 -> V_46 )
V_4 -> V_42 -> V_46 ( V_4 ) ;
F_29 ( V_4 ) ;
V_26 = 1 ;
F_32 ( L_10 ,
V_29 -> V_23 -> V_21 , V_18 , F_33 ( V_4 ) , V_29 -> V_21 ) ;
goto V_47;
V_41:
if ( V_4 -> V_23 )
F_36 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_30 , V_4 ) ;
V_39:
F_48 ( V_4 ) ;
F_40 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_49 ( V_4 , NULL ) ;
if ( V_4 -> V_42 && V_4 -> V_42 -> V_45 )
V_4 -> V_42 -> V_45 ( V_4 ) ;
F_50 ( V_4 ) ;
switch ( V_26 ) {
case - V_31 :
F_12 ( V_4 , L_11 , V_29 -> V_21 ) ;
F_15 ( V_4 ) ;
if ( V_32 != F_43 ( & V_13 ) )
F_18 () ;
break;
case - V_48 :
case - V_49 :
F_32 ( L_12 ,
V_29 -> V_21 , F_33 ( V_4 ) , V_26 ) ;
break;
default:
F_30 ( V_17
L_13 ,
V_29 -> V_21 , F_33 ( V_4 ) , V_26 ) ;
}
V_26 = 0 ;
V_47:
F_52 ( & V_36 ) ;
F_53 ( & V_50 ) ;
return V_26 ;
}
int F_54 ( void )
{
F_32 ( L_14 , V_18 ,
F_43 ( & V_36 ) ) ;
if ( F_43 ( & V_36 ) )
return - V_51 ;
return 0 ;
}
void F_23 ( void )
{
F_26 ( & V_14 ) ;
F_55 ( V_50 , F_43 ( & V_36 ) == 0 ) ;
F_56 () ;
}
int F_57 ( struct V_28 * V_29 , struct V_3 * V_4 )
{
int V_26 = 0 ;
if ( ! F_58 ( V_4 ) )
return - V_48 ;
F_32 ( L_15 ,
V_29 -> V_23 -> V_21 , V_18 , F_33 ( V_4 ) , V_29 -> V_21 ) ;
if ( V_4 -> V_52 )
F_59 ( V_4 -> V_52 ) ;
F_60 ( V_4 ) ;
V_26 = F_42 ( V_4 , V_29 ) ;
F_61 ( V_4 ) ;
if ( V_4 -> V_52 )
F_62 ( V_4 -> V_52 ) ;
return V_26 ;
}
bool F_63 ( struct V_28 * V_29 )
{
switch ( V_29 -> V_53 ) {
case V_54 :
return true ;
case V_55 :
return false ;
default:
if ( F_64 ( V_29 -> V_56 ) )
return true ;
return false ;
}
}
static int F_65 ( struct V_28 * V_29 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_3 * V_4 = V_59 -> V_4 ;
bool V_60 ;
int V_26 ;
if ( V_4 -> V_20 )
return - V_51 ;
V_26 = F_66 ( V_29 , V_4 ) ;
if ( V_26 == 0 ) {
return 0 ;
} else if ( V_26 == - V_31 ) {
F_12 ( V_4 , L_16 ) ;
F_15 ( V_4 ) ;
} else if ( V_26 < 0 ) {
F_12 ( V_4 , L_17 , V_26 ) ;
return V_26 ;
}
V_60 = F_63 ( V_29 ) ;
if ( V_60 )
V_59 -> V_61 = true ;
if ( V_59 -> V_62 && V_60 != V_59 -> V_63 )
return 0 ;
return F_57 ( V_29 , V_4 ) ;
}
static void F_67 ( void * V_64 , T_1 V_65 )
{
struct V_3 * V_4 = V_64 ;
struct V_58 V_59 = {
. V_4 = V_4 ,
. V_62 = true ,
. V_63 = true ,
} ;
F_68 ( V_4 ) ;
if ( V_4 -> V_52 )
F_59 ( V_4 -> V_52 ) ;
F_69 ( V_4 -> V_23 , NULL , & V_59 , F_65 ) ;
F_12 ( V_4 , L_18 ) ;
F_61 ( V_4 ) ;
if ( V_4 -> V_52 )
F_62 ( V_4 -> V_52 ) ;
F_70 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static int F_71 ( struct V_3 * V_4 , bool V_66 )
{
int V_26 = 0 ;
F_68 ( V_4 ) ;
if ( V_4 -> V_20 ) {
if ( F_27 ( V_4 ) ) {
V_26 = 1 ;
goto V_67;
}
V_26 = F_41 ( V_4 ) ;
if ( V_26 == 0 )
V_26 = 1 ;
else {
V_4 -> V_20 = NULL ;
V_26 = 0 ;
}
} else {
struct V_58 V_59 = {
. V_4 = V_4 ,
. V_62 = V_66 ,
. V_63 = false ,
} ;
if ( V_4 -> V_52 )
F_59 ( V_4 -> V_52 ) ;
V_26 = F_69 ( V_4 -> V_23 , NULL , & V_59 ,
F_65 ) ;
if ( ! V_26 && V_66 && V_59 . V_61 ) {
F_12 ( V_4 , L_19 ) ;
F_7 ( V_4 ) ;
F_72 ( F_67 , V_4 ) ;
} else {
F_61 ( V_4 ) ;
}
if ( V_4 -> V_52 )
F_62 ( V_4 -> V_52 ) ;
}
V_67:
F_70 ( V_4 ) ;
return V_26 ;
}
int F_73 ( struct V_3 * V_4 )
{
return F_71 ( V_4 , false ) ;
}
void F_74 ( struct V_3 * V_4 )
{
F_71 ( V_4 , true ) ;
}
static int F_75 ( struct V_3 * V_4 , void * V_59 )
{
struct V_28 * V_29 = V_59 ;
int V_26 ;
V_26 = F_66 ( V_29 , V_4 ) ;
if ( V_26 == 0 ) {
return 0 ;
} else if ( V_26 == - V_31 ) {
F_12 ( V_4 , L_16 ) ;
F_15 ( V_4 ) ;
} else if ( V_26 < 0 ) {
F_12 ( V_4 , L_17 , V_26 ) ;
return V_26 ;
}
if ( V_4 -> V_52 )
F_68 ( V_4 -> V_52 ) ;
F_68 ( V_4 ) ;
if ( ! V_4 -> V_20 )
F_57 ( V_29 , V_4 ) ;
F_70 ( V_4 ) ;
if ( V_4 -> V_52 )
F_70 ( V_4 -> V_52 ) ;
return 0 ;
}
int F_76 ( struct V_28 * V_29 )
{
return F_77 ( V_29 -> V_23 , NULL , V_29 , F_75 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
struct V_28 * V_29 ;
V_29 = V_4 -> V_20 ;
if ( V_29 ) {
if ( F_63 ( V_29 ) )
F_56 () ;
F_59 ( V_4 ) ;
F_40 ( V_4 ) ;
if ( V_4 -> V_23 )
F_36 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_68 ,
V_4 ) ;
F_79 ( V_4 ) ;
if ( V_4 -> V_23 && V_4 -> V_23 -> remove )
V_4 -> V_23 -> remove ( V_4 ) ;
else if ( V_29 -> remove )
V_29 -> remove ( V_4 ) ;
F_48 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_49 ( V_4 , NULL ) ;
if ( V_4 -> V_42 && V_4 -> V_42 -> V_45 )
V_4 -> V_42 -> V_45 ( V_4 ) ;
F_50 ( V_4 ) ;
F_80 ( & V_4 -> V_9 -> V_16 ) ;
F_35 ( V_4 ) ;
if ( V_4 -> V_23 )
F_36 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_69 ,
V_4 ) ;
}
}
void F_81 ( struct V_3 * V_4 )
{
F_68 ( V_4 ) ;
F_78 ( V_4 ) ;
F_70 ( V_4 ) ;
}
void F_82 ( struct V_28 * V_29 )
{
struct V_5 * V_70 ;
struct V_3 * V_4 ;
for (; ; ) {
F_83 ( & V_29 -> V_9 -> V_22 . V_71 ) ;
if ( F_3 ( & V_29 -> V_9 -> V_22 . V_72 ) ) {
F_84 ( & V_29 -> V_9 -> V_22 . V_71 ) ;
break;
}
V_70 = F_85 ( V_29 -> V_9 -> V_22 . V_72 . V_73 ,
struct V_5 ,
V_16 . V_74 ) ;
V_4 = V_70 -> V_3 ;
F_7 ( V_4 ) ;
F_84 ( & V_29 -> V_9 -> V_22 . V_71 ) ;
if ( V_4 -> V_52 )
F_68 ( V_4 -> V_52 ) ;
F_68 ( V_4 ) ;
if ( V_4 -> V_20 == V_29 )
F_78 ( V_4 ) ;
F_70 ( V_4 ) ;
if ( V_4 -> V_52 )
F_70 ( V_4 -> V_52 ) ;
F_14 ( V_4 ) ;
}
}
