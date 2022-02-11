static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 ;
unsigned long long V_6 ;
F_2 ( V_7 L_1 , F_3 ( V_2 ) ,
F_4 ( V_8 ) ) ;
V_3 = F_5 () ;
F_6 ( V_2 ) ;
V_5 = F_5 () ;
V_4 = F_7 ( V_5 , V_3 ) ;
V_6 = ( unsigned long long ) F_8 ( V_4 ) >> 10 ;
F_2 ( V_7 L_2 ,
F_3 ( V_2 ) , V_6 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_10 ( & V_13 ) ;
while ( ! F_11 ( & V_14 ) ) {
V_12 = F_12 ( & V_14 ,
F_13 ( * V_2 -> V_15 ) , V_16 ) ;
V_2 = V_12 -> V_1 ;
F_14 ( & V_12 -> V_16 ) ;
F_15 ( V_2 ) ;
F_16 ( & V_13 ) ;
F_17 () ;
F_18 ( V_2 ) ;
F_19 () ;
F_20 ( V_2 , L_3 ) ;
if ( V_17 && ! V_18 )
F_1 ( V_2 ) ;
else
F_6 ( V_2 ) ;
F_10 ( & V_13 ) ;
F_21 ( V_2 ) ;
}
F_16 ( & V_13 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_10 ( & V_13 ) ;
if ( F_11 ( & V_2 -> V_15 -> V_16 ) ) {
F_20 ( V_2 , L_4 ) ;
F_23 ( & V_2 -> V_15 -> V_16 , & V_19 ) ;
}
F_16 ( & V_13 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_10 ( & V_13 ) ;
if ( ! F_11 ( & V_2 -> V_15 -> V_16 ) ) {
F_20 ( V_2 , L_5 ) ;
F_14 ( & V_2 -> V_15 -> V_16 ) ;
}
F_16 ( & V_13 ) ;
}
static void F_25 ( void )
{
if ( ! V_20 )
return;
F_10 ( & V_13 ) ;
F_26 ( & V_21 ) ;
F_27 ( & V_19 ,
& V_14 ) ;
F_16 ( & V_13 ) ;
F_28 ( & V_22 ) ;
}
void F_29 ( void )
{
V_23 = true ;
F_30 () ;
}
void F_31 ( void )
{
V_23 = false ;
F_25 () ;
}
static int F_32 ( void )
{
V_20 = true ;
F_25 () ;
F_33 ( & V_22 ) ;
V_18 = true ;
return 0 ;
}
bool F_34 ( struct V_1 * V_2 )
{
return V_2 -> V_15 && F_35 ( & V_2 -> V_15 -> V_24 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( F_34 ( V_2 ) ) {
F_2 ( V_25 L_6 ,
V_26 , F_37 ( & V_2 -> V_27 ) ) ;
return;
}
F_38 ( L_7 , V_2 -> V_28 -> V_29 ,
V_26 , F_3 ( V_2 ) ) ;
F_39 ( & V_2 -> V_15 -> V_24 , & V_2 -> V_28 -> V_15 -> V_30 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 () ;
if ( V_2 -> V_31 )
F_42 ( & V_2 -> V_31 -> V_15 -> V_32 ,
V_33 , V_2 ) ;
F_43 ( & V_2 -> V_27 , V_34 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_35 ;
if ( V_2 -> V_31 )
F_42 ( & V_2 -> V_31 -> V_15 -> V_32 ,
V_36 , V_2 ) ;
V_35 = F_45 ( & V_2 -> V_28 -> V_15 -> V_27 , & V_2 -> V_27 ,
F_37 ( & V_2 -> V_27 ) ) ;
if ( V_35 == 0 ) {
V_35 = F_45 ( & V_2 -> V_27 , & V_2 -> V_28 -> V_15 -> V_27 ,
L_8 ) ;
if ( V_35 )
F_46 ( & V_2 -> V_28 -> V_15 -> V_27 ,
F_37 ( & V_2 -> V_27 ) ) ;
}
return V_35 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_28 ;
if ( V_38 ) {
F_46 ( & V_38 -> V_15 -> V_27 , F_37 ( & V_2 -> V_27 ) ) ;
F_46 ( & V_2 -> V_27 , L_8 ) ;
}
}
int F_48 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_44 ( V_2 ) ;
if ( ! V_35 )
F_36 ( V_2 ) ;
else if ( V_2 -> V_31 )
F_42 ( & V_2 -> V_31 -> V_15 -> V_32 ,
V_39 , V_2 ) ;
return V_35 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
int V_35 = - V_40 ;
int V_41 = F_50 ( & V_21 ) ;
bool V_42 = F_51 ( V_43 ) &&
! V_38 -> V_44 ;
if ( V_23 ) {
F_20 ( V_2 , L_9 , V_38 -> V_29 ) ;
F_22 ( V_2 ) ;
return V_35 ;
}
V_35 = F_52 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_26 ( & V_45 ) ;
F_38 ( L_10 ,
V_38 -> V_31 -> V_29 , V_26 , V_38 -> V_29 , F_3 ( V_2 ) ) ;
F_53 ( ! F_11 ( & V_2 -> V_46 ) ) ;
V_47:
V_2 -> V_28 = V_38 ;
V_35 = F_54 ( V_2 ) ;
if ( V_35 )
goto V_48;
V_35 = F_55 ( V_2 ) ;
if ( V_35 )
goto V_49;
if ( F_44 ( V_2 ) ) {
F_2 ( V_50 L_11 ,
V_26 , F_3 ( V_2 ) ) ;
goto V_51;
}
if ( V_2 -> V_52 && V_2 -> V_52 -> V_53 ) {
V_35 = V_2 -> V_52 -> V_53 ( V_2 ) ;
if ( V_35 )
goto V_51;
}
F_56 ( V_2 ) ;
if ( V_2 -> V_31 -> V_54 ) {
V_35 = V_2 -> V_31 -> V_54 ( V_2 ) ;
if ( V_35 )
goto V_51;
} else if ( V_38 -> V_54 ) {
V_35 = V_38 -> V_54 ( V_2 ) ;
if ( V_35 )
goto V_51;
}
if ( V_42 ) {
V_42 = false ;
if ( V_2 -> V_31 -> remove )
V_2 -> V_31 -> remove ( V_2 ) ;
else if ( V_38 -> remove )
V_38 -> remove ( V_2 ) ;
F_57 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_28 = NULL ;
F_58 ( V_2 , NULL ) ;
if ( V_2 -> V_52 && V_2 -> V_52 -> V_55 )
V_2 -> V_52 -> V_55 ( V_2 ) ;
F_59 ( V_2 ) ;
goto V_47;
}
F_60 ( V_2 ) ;
if ( V_2 -> V_52 && V_2 -> V_52 -> V_56 )
V_2 -> V_52 -> V_56 ( V_2 ) ;
F_36 ( V_2 ) ;
V_35 = 1 ;
F_38 ( L_12 ,
V_38 -> V_31 -> V_29 , V_26 , F_3 ( V_2 ) , V_38 -> V_29 ) ;
goto V_57;
V_51:
F_61 ( V_2 ) ;
V_49:
if ( V_2 -> V_31 )
F_42 ( & V_2 -> V_31 -> V_15 -> V_32 ,
V_39 , V_2 ) ;
V_48:
F_62 ( V_2 ) ;
F_57 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_28 = NULL ;
F_58 ( V_2 , NULL ) ;
if ( V_2 -> V_52 && V_2 -> V_52 -> V_55 )
V_2 -> V_52 -> V_55 ( V_2 ) ;
F_59 ( V_2 ) ;
switch ( V_35 ) {
case - V_40 :
F_20 ( V_2 , L_13 , V_38 -> V_29 ) ;
F_22 ( V_2 ) ;
if ( V_41 != F_50 ( & V_21 ) )
F_25 () ;
break;
case - V_58 :
case - V_59 :
F_38 ( L_14 ,
V_38 -> V_29 , F_3 ( V_2 ) , V_35 ) ;
break;
default:
F_2 ( V_25
L_15 ,
V_38 -> V_29 , F_3 ( V_2 ) , V_35 ) ;
}
V_35 = 0 ;
V_57:
F_63 ( & V_45 ) ;
F_64 ( & V_60 ) ;
return V_35 ;
}
int F_65 ( void )
{
F_38 ( L_16 , V_26 ,
F_50 ( & V_45 ) ) ;
if ( F_50 ( & V_45 ) )
return - V_61 ;
return 0 ;
}
void F_30 ( void )
{
F_33 ( & V_22 ) ;
F_66 ( V_60 , F_50 ( & V_45 ) == 0 ) ;
F_67 () ;
}
int F_68 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
int V_35 = 0 ;
if ( ! F_69 ( V_2 ) )
return - V_58 ;
F_38 ( L_17 ,
V_38 -> V_31 -> V_29 , V_26 , F_3 ( V_2 ) , V_38 -> V_29 ) ;
F_70 ( V_2 ) ;
if ( V_2 -> V_62 )
F_71 ( V_2 -> V_62 ) ;
F_72 ( V_2 ) ;
V_35 = F_49 ( V_2 , V_38 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_62 )
F_74 ( V_2 -> V_62 ) ;
F_75 ( V_2 ) ;
return V_35 ;
}
bool F_76 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_63 ) {
case V_64 :
return true ;
case V_65 :
return false ;
default:
if ( F_77 ( V_38 -> V_66 ) )
return true ;
return false ;
}
}
static int F_78 ( struct V_37 * V_38 , void * V_67 )
{
struct V_68 * V_69 = V_67 ;
struct V_1 * V_2 = V_69 -> V_2 ;
bool V_70 ;
int V_35 ;
if ( V_2 -> V_28 )
return - V_61 ;
V_35 = F_79 ( V_38 , V_2 ) ;
if ( V_35 == 0 ) {
return 0 ;
} else if ( V_35 == - V_40 ) {
F_20 ( V_2 , L_18 ) ;
F_22 ( V_2 ) ;
} else if ( V_35 < 0 ) {
F_20 ( V_2 , L_19 , V_35 ) ;
return V_35 ;
}
V_70 = F_76 ( V_38 ) ;
if ( V_70 )
V_69 -> V_71 = true ;
if ( V_69 -> V_72 && V_70 != V_69 -> V_73 )
return 0 ;
return F_68 ( V_38 , V_2 ) ;
}
static void F_80 ( void * V_74 , T_2 V_75 )
{
struct V_1 * V_2 = V_74 ;
struct V_68 V_69 = {
. V_2 = V_2 ,
. V_72 = true ,
. V_73 = true ,
} ;
F_81 ( V_2 ) ;
if ( V_2 -> V_62 )
F_71 ( V_2 -> V_62 ) ;
F_82 ( V_2 -> V_31 , NULL , & V_69 , F_78 ) ;
F_20 ( V_2 , L_20 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_62 )
F_74 ( V_2 -> V_62 ) ;
F_83 ( V_2 ) ;
F_21 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 , bool V_76 )
{
int V_35 = 0 ;
F_81 ( V_2 ) ;
if ( V_2 -> V_28 ) {
if ( F_34 ( V_2 ) ) {
V_35 = 1 ;
goto V_77;
}
V_35 = F_48 ( V_2 ) ;
if ( V_35 == 0 )
V_35 = 1 ;
else {
V_2 -> V_28 = NULL ;
V_35 = 0 ;
}
} else {
struct V_68 V_69 = {
. V_2 = V_2 ,
. V_72 = V_76 ,
. V_73 = false ,
} ;
if ( V_2 -> V_62 )
F_71 ( V_2 -> V_62 ) ;
V_35 = F_82 ( V_2 -> V_31 , NULL , & V_69 ,
F_78 ) ;
if ( ! V_35 && V_76 && V_69 . V_71 ) {
F_20 ( V_2 , L_21 ) ;
F_15 ( V_2 ) ;
F_85 ( F_80 , V_2 ) ;
} else {
F_73 ( V_2 ) ;
}
if ( V_2 -> V_62 )
F_74 ( V_2 -> V_62 ) ;
}
V_77:
F_83 ( V_2 ) ;
return V_35 ;
}
int F_86 ( struct V_1 * V_2 )
{
return F_84 ( V_2 , false ) ;
}
void F_87 ( struct V_1 * V_2 )
{
F_84 ( V_2 , true ) ;
}
static int F_88 ( struct V_1 * V_2 , void * V_69 )
{
struct V_37 * V_38 = V_69 ;
int V_35 ;
V_35 = F_79 ( V_38 , V_2 ) ;
if ( V_35 == 0 ) {
return 0 ;
} else if ( V_35 == - V_40 ) {
F_20 ( V_2 , L_18 ) ;
F_22 ( V_2 ) ;
} else if ( V_35 < 0 ) {
F_20 ( V_2 , L_19 , V_35 ) ;
return V_35 ;
}
if ( V_2 -> V_62 )
F_81 ( V_2 -> V_62 ) ;
F_81 ( V_2 ) ;
if ( ! V_2 -> V_28 )
F_68 ( V_38 , V_2 ) ;
F_83 ( V_2 ) ;
if ( V_2 -> V_62 )
F_83 ( V_2 -> V_62 ) ;
return 0 ;
}
int F_89 ( struct V_37 * V_38 )
{
return F_90 ( V_38 -> V_31 , NULL , V_38 , F_88 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_1 * V_62 )
{
struct V_37 * V_38 ;
V_38 = V_2 -> V_28 ;
if ( V_38 ) {
if ( F_76 ( V_38 ) )
F_67 () ;
while ( F_92 ( V_2 ) ) {
F_83 ( V_2 ) ;
if ( V_62 )
F_83 ( V_62 ) ;
F_93 ( V_2 ) ;
if ( V_62 )
F_81 ( V_62 ) ;
F_81 ( V_2 ) ;
if ( V_2 -> V_28 != V_38 )
return;
}
F_71 ( V_2 ) ;
F_94 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( V_2 -> V_31 )
F_42 ( & V_2 -> V_31 -> V_15 -> V_32 ,
V_78 ,
V_2 ) ;
F_95 ( V_2 ) ;
if ( V_2 -> V_31 && V_2 -> V_31 -> remove )
V_2 -> V_31 -> remove ( V_2 ) ;
else if ( V_38 -> remove )
V_38 -> remove ( V_2 ) ;
F_96 ( V_2 ) ;
F_61 ( V_2 ) ;
F_57 ( V_2 ) ;
V_2 -> V_28 = NULL ;
F_58 ( V_2 , NULL ) ;
if ( V_2 -> V_52 && V_2 -> V_52 -> V_55 )
V_2 -> V_52 -> V_55 ( V_2 ) ;
F_59 ( V_2 ) ;
F_97 ( & V_2 -> V_15 -> V_24 ) ;
F_41 ( V_2 ) ;
if ( V_2 -> V_31 )
F_42 ( & V_2 -> V_31 -> V_15 -> V_32 ,
V_79 ,
V_2 ) ;
F_43 ( & V_2 -> V_27 , V_80 ) ;
}
}
void F_98 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_1 * V_62 )
{
if ( V_62 )
F_81 ( V_62 ) ;
F_81 ( V_2 ) ;
if ( ! V_38 || V_38 == V_2 -> V_28 )
F_91 ( V_2 , V_62 ) ;
F_83 ( V_2 ) ;
if ( V_62 )
F_83 ( V_62 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_98 ( V_2 , NULL , NULL ) ;
}
void F_100 ( struct V_37 * V_38 )
{
struct V_11 * V_81 ;
struct V_1 * V_2 ;
for (; ; ) {
F_101 ( & V_38 -> V_15 -> V_30 . V_82 ) ;
if ( F_11 ( & V_38 -> V_15 -> V_30 . V_83 ) ) {
F_102 ( & V_38 -> V_15 -> V_30 . V_82 ) ;
break;
}
V_81 = F_103 ( V_38 -> V_15 -> V_30 . V_83 . V_84 ,
struct V_11 ,
V_24 . V_85 ) ;
V_2 = V_81 -> V_1 ;
F_15 ( V_2 ) ;
F_102 ( & V_38 -> V_15 -> V_30 . V_82 ) ;
F_98 ( V_2 , V_38 , V_2 -> V_62 ) ;
F_21 ( V_2 ) ;
}
}
