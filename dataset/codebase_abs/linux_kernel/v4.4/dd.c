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
if ( V_4 -> V_36 && V_4 -> V_36 -> V_37 ) {
V_27 = V_4 -> V_36 -> V_37 ( V_4 ) ;
if ( V_27 )
goto V_34;
}
F_42 ( V_4 ) ;
if ( V_4 -> V_24 -> V_38 ) {
V_27 = V_4 -> V_24 -> V_38 ( V_4 ) ;
if ( V_27 )
goto V_34;
} else if ( V_30 -> V_38 ) {
V_27 = V_30 -> V_38 ( V_4 ) ;
if ( V_27 )
goto V_34;
}
F_43 ( V_4 ) ;
if ( V_4 -> V_36 && V_4 -> V_36 -> V_39 )
V_4 -> V_36 -> V_39 ( V_4 ) ;
F_26 ( V_4 ) ;
V_27 = 1 ;
F_30 ( L_10 ,
V_30 -> V_24 -> V_22 , V_19 , F_31 ( V_4 ) , V_30 -> V_22 ) ;
goto V_40;
V_34:
F_44 ( V_4 ) ;
F_37 ( V_4 ) ;
V_4 -> V_21 = NULL ;
F_45 ( V_4 , NULL ) ;
if ( V_4 -> V_36 && V_4 -> V_36 -> V_41 )
V_4 -> V_36 -> V_41 ( V_4 ) ;
switch ( V_27 ) {
case - V_42 :
F_12 ( V_4 , L_11 , V_30 -> V_22 ) ;
F_15 ( V_4 ) ;
if ( V_31 != F_40 ( & V_13 ) )
F_18 () ;
break;
case - V_43 :
case - V_44 :
F_30 ( L_12 ,
V_30 -> V_22 , F_31 ( V_4 ) , V_27 ) ;
break;
default:
F_28 ( V_18
L_13 ,
V_30 -> V_22 , F_31 ( V_4 ) , V_27 ) ;
}
V_27 = 0 ;
V_40:
F_46 ( & V_32 ) ;
F_47 ( & V_45 ) ;
return V_27 ;
}
int F_48 ( void )
{
F_30 ( L_14 , V_19 ,
F_40 ( & V_32 ) ) ;
if ( F_40 ( & V_32 ) )
return - V_46 ;
return 0 ;
}
void F_49 ( void )
{
F_50 ( V_45 , F_40 ( & V_32 ) == 0 ) ;
F_51 () ;
}
int F_52 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
int V_27 = 0 ;
if ( ! F_53 ( V_4 ) )
return - V_43 ;
F_30 ( L_15 ,
V_30 -> V_24 -> V_22 , V_19 , F_31 ( V_4 ) , V_30 -> V_22 ) ;
if ( V_4 -> V_47 )
F_54 ( V_4 -> V_47 ) ;
F_55 ( V_4 ) ;
V_27 = F_39 ( V_4 , V_30 ) ;
F_56 ( V_4 ) ;
if ( V_4 -> V_47 )
F_57 ( V_4 -> V_47 ) ;
return V_27 ;
}
bool F_58 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_48 ) {
case V_49 :
return true ;
case V_50 :
return false ;
default:
if ( F_59 ( V_30 -> V_51 ) )
return true ;
return false ;
}
}
static int F_60 ( struct V_29 * V_30 , void * V_52 )
{
struct V_53 * V_54 = V_52 ;
struct V_3 * V_4 = V_54 -> V_4 ;
bool V_55 ;
if ( V_4 -> V_21 )
return - V_46 ;
if ( ! F_61 ( V_30 , V_4 ) )
return 0 ;
V_55 = F_58 ( V_30 ) ;
if ( V_55 )
V_54 -> V_56 = true ;
if ( V_54 -> V_57 && V_55 != V_54 -> V_58 )
return 0 ;
return F_52 ( V_30 , V_4 ) ;
}
static void F_62 ( void * V_59 , T_1 V_60 )
{
struct V_3 * V_4 = V_59 ;
struct V_53 V_54 = {
. V_4 = V_4 ,
. V_57 = true ,
. V_58 = true ,
} ;
F_63 ( V_4 ) ;
if ( V_4 -> V_47 )
F_54 ( V_4 -> V_47 ) ;
F_64 ( V_4 -> V_24 , NULL , & V_54 , F_60 ) ;
F_12 ( V_4 , L_16 ) ;
F_56 ( V_4 ) ;
if ( V_4 -> V_47 )
F_57 ( V_4 -> V_47 ) ;
F_65 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static int F_66 ( struct V_3 * V_4 , bool V_61 )
{
int V_27 = 0 ;
F_63 ( V_4 ) ;
if ( V_4 -> V_21 ) {
if ( F_27 ( & V_4 -> V_9 -> V_17 ) ) {
V_27 = 1 ;
goto V_62;
}
V_27 = F_38 ( V_4 ) ;
if ( V_27 == 0 )
V_27 = 1 ;
else {
V_4 -> V_21 = NULL ;
V_27 = 0 ;
}
} else {
struct V_53 V_54 = {
. V_4 = V_4 ,
. V_57 = V_61 ,
. V_58 = false ,
} ;
if ( V_4 -> V_47 )
F_54 ( V_4 -> V_47 ) ;
V_27 = F_64 ( V_4 -> V_24 , NULL , & V_54 ,
F_60 ) ;
if ( ! V_27 && V_61 && V_54 . V_56 ) {
F_12 ( V_4 , L_17 ) ;
F_7 ( V_4 ) ;
F_67 ( F_62 , V_4 ) ;
} else {
F_56 ( V_4 ) ;
}
if ( V_4 -> V_47 )
F_57 ( V_4 -> V_47 ) ;
}
V_62:
F_65 ( V_4 ) ;
return V_27 ;
}
int F_68 ( struct V_3 * V_4 )
{
return F_66 ( V_4 , false ) ;
}
void F_69 ( struct V_3 * V_4 )
{
F_66 ( V_4 , true ) ;
}
static int F_70 ( struct V_3 * V_4 , void * V_54 )
{
struct V_29 * V_30 = V_54 ;
if ( ! F_61 ( V_30 , V_4 ) )
return 0 ;
if ( V_4 -> V_47 )
F_63 ( V_4 -> V_47 ) ;
F_63 ( V_4 ) ;
if ( ! V_4 -> V_21 )
F_52 ( V_30 , V_4 ) ;
F_65 ( V_4 ) ;
if ( V_4 -> V_47 )
F_65 ( V_4 -> V_47 ) ;
return 0 ;
}
int F_71 ( struct V_29 * V_30 )
{
return F_72 ( V_30 -> V_24 , NULL , V_30 , F_70 ) ;
}
static void F_73 ( struct V_3 * V_4 )
{
struct V_29 * V_30 ;
V_30 = V_4 -> V_21 ;
if ( V_30 ) {
if ( F_58 ( V_30 ) )
F_51 () ;
F_54 ( V_4 ) ;
F_37 ( V_4 ) ;
if ( V_4 -> V_24 )
F_33 ( & V_4 -> V_24 -> V_9 -> V_25 ,
V_63 ,
V_4 ) ;
F_74 ( V_4 ) ;
if ( V_4 -> V_24 && V_4 -> V_24 -> remove )
V_4 -> V_24 -> remove ( V_4 ) ;
else if ( V_30 -> remove )
V_30 -> remove ( V_4 ) ;
F_44 ( V_4 ) ;
V_4 -> V_21 = NULL ;
F_45 ( V_4 , NULL ) ;
if ( V_4 -> V_36 && V_4 -> V_36 -> V_41 )
V_4 -> V_36 -> V_41 ( V_4 ) ;
F_75 ( & V_4 -> V_9 -> V_17 ) ;
if ( V_4 -> V_24 )
F_33 ( & V_4 -> V_24 -> V_9 -> V_25 ,
V_64 ,
V_4 ) ;
}
}
void F_76 ( struct V_3 * V_4 )
{
F_63 ( V_4 ) ;
F_73 ( V_4 ) ;
F_65 ( V_4 ) ;
}
void F_77 ( struct V_29 * V_30 )
{
struct V_5 * V_65 ;
struct V_3 * V_4 ;
for (; ; ) {
F_78 ( & V_30 -> V_9 -> V_23 . V_66 ) ;
if ( F_3 ( & V_30 -> V_9 -> V_23 . V_67 ) ) {
F_79 ( & V_30 -> V_9 -> V_23 . V_66 ) ;
break;
}
V_65 = F_80 ( V_30 -> V_9 -> V_23 . V_67 . V_68 ,
struct V_5 ,
V_17 . V_69 ) ;
V_4 = V_65 -> V_3 ;
F_7 ( V_4 ) ;
F_79 ( & V_30 -> V_9 -> V_23 . V_66 ) ;
if ( V_4 -> V_47 )
F_63 ( V_4 -> V_47 ) ;
F_63 ( V_4 ) ;
if ( V_4 -> V_21 == V_30 )
F_73 ( V_4 ) ;
F_65 ( V_4 ) ;
if ( V_4 -> V_47 )
F_65 ( V_4 -> V_47 ) ;
F_14 ( V_4 ) ;
}
}
