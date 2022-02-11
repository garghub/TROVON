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
F_36 ( V_4 ) ;
F_17 ( V_4 ) ;
F_18 () ;
if ( V_4 -> V_23 )
F_37 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_25 , V_4 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_23 )
F_37 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_27 , V_4 ) ;
V_26 = F_39 ( & V_4 -> V_20 -> V_9 -> V_19 , & V_4 -> V_19 ,
F_31 ( & V_4 -> V_19 ) ) ;
if ( V_26 == 0 ) {
V_26 = F_39 ( & V_4 -> V_19 , & V_4 -> V_20 -> V_9 -> V_19 ,
L_6 ) ;
if ( V_26 )
F_40 ( & V_4 -> V_20 -> V_9 -> V_19 ,
F_31 ( & V_4 -> V_19 ) ) ;
}
return V_26 ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_20 ;
if ( V_29 ) {
F_40 ( & V_29 -> V_9 -> V_19 , F_31 ( & V_4 -> V_19 ) ) ;
F_40 ( & V_4 -> V_19 , L_6 ) ;
}
}
int F_42 ( struct V_3 * V_4 )
{
int V_26 ;
V_26 = F_38 ( V_4 ) ;
if ( ! V_26 )
F_29 ( V_4 ) ;
else if ( V_4 -> V_23 )
F_37 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_30 , V_4 ) ;
return V_26 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_28 * V_29 )
{
int V_26 = - V_31 ;
int V_32 = F_44 ( & V_13 ) ;
bool V_33 = F_45 ( V_34 ) &&
! V_29 -> V_35 ;
if ( V_15 ) {
F_12 ( V_4 , L_7 , V_29 -> V_21 ) ;
F_15 ( V_4 ) ;
return V_26 ;
}
V_26 = F_46 ( V_4 ) ;
if ( V_26 )
return V_26 ;
F_19 ( & V_36 ) ;
F_32 ( L_8 ,
V_29 -> V_23 -> V_21 , V_18 , V_29 -> V_21 , F_33 ( V_4 ) ) ;
F_47 ( ! F_3 ( & V_4 -> V_37 ) ) ;
V_38:
V_4 -> V_20 = V_29 ;
V_26 = F_48 ( V_4 ) ;
if ( V_26 )
goto V_39;
V_26 = F_49 ( V_4 ) ;
if ( V_26 )
goto V_40;
if ( F_38 ( V_4 ) ) {
F_30 ( V_41 L_9 ,
V_18 , F_33 ( V_4 ) ) ;
goto V_42;
}
if ( V_4 -> V_43 && V_4 -> V_43 -> V_44 ) {
V_26 = V_4 -> V_43 -> V_44 ( V_4 ) ;
if ( V_26 )
goto V_42;
}
F_50 ( V_4 ) ;
if ( V_4 -> V_23 -> V_45 ) {
V_26 = V_4 -> V_23 -> V_45 ( V_4 ) ;
if ( V_26 )
goto V_42;
} else if ( V_29 -> V_45 ) {
V_26 = V_29 -> V_45 ( V_4 ) ;
if ( V_26 )
goto V_42;
}
if ( V_33 ) {
V_33 = false ;
if ( V_4 -> V_23 -> remove )
V_4 -> V_23 -> remove ( V_4 ) ;
else if ( V_29 -> remove )
V_29 -> remove ( V_4 ) ;
F_51 ( V_4 ) ;
F_41 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_52 ( V_4 , NULL ) ;
if ( V_4 -> V_43 && V_4 -> V_43 -> V_46 )
V_4 -> V_43 -> V_46 ( V_4 ) ;
F_53 ( V_4 ) ;
goto V_38;
}
F_54 ( V_4 ) ;
if ( V_4 -> V_43 && V_4 -> V_43 -> V_47 )
V_4 -> V_43 -> V_47 ( V_4 ) ;
F_29 ( V_4 ) ;
V_26 = 1 ;
F_32 ( L_10 ,
V_29 -> V_23 -> V_21 , V_18 , F_33 ( V_4 ) , V_29 -> V_21 ) ;
goto V_48;
V_42:
F_55 ( V_4 ) ;
V_40:
if ( V_4 -> V_23 )
F_37 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_30 , V_4 ) ;
V_39:
F_56 ( V_4 ) ;
F_51 ( V_4 ) ;
F_41 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_52 ( V_4 , NULL ) ;
if ( V_4 -> V_43 && V_4 -> V_43 -> V_46 )
V_4 -> V_43 -> V_46 ( V_4 ) ;
F_53 ( V_4 ) ;
switch ( V_26 ) {
case - V_31 :
F_12 ( V_4 , L_11 , V_29 -> V_21 ) ;
F_15 ( V_4 ) ;
if ( V_32 != F_44 ( & V_13 ) )
F_18 () ;
break;
case - V_49 :
case - V_50 :
F_32 ( L_12 ,
V_29 -> V_21 , F_33 ( V_4 ) , V_26 ) ;
break;
default:
F_30 ( V_17
L_13 ,
V_29 -> V_21 , F_33 ( V_4 ) , V_26 ) ;
}
V_26 = 0 ;
V_48:
F_57 ( & V_36 ) ;
F_58 ( & V_51 ) ;
return V_26 ;
}
int F_59 ( void )
{
F_32 ( L_14 , V_18 ,
F_44 ( & V_36 ) ) ;
if ( F_44 ( & V_36 ) )
return - V_52 ;
return 0 ;
}
void F_23 ( void )
{
F_26 ( & V_14 ) ;
F_60 ( V_51 , F_44 ( & V_36 ) == 0 ) ;
F_61 () ;
}
int F_62 ( struct V_28 * V_29 , struct V_3 * V_4 )
{
int V_26 = 0 ;
if ( ! F_63 ( V_4 ) )
return - V_49 ;
F_32 ( L_15 ,
V_29 -> V_23 -> V_21 , V_18 , F_33 ( V_4 ) , V_29 -> V_21 ) ;
F_64 ( V_4 ) ;
if ( V_4 -> V_53 )
F_65 ( V_4 -> V_53 ) ;
F_66 ( V_4 ) ;
V_26 = F_43 ( V_4 , V_29 ) ;
F_67 ( V_4 ) ;
if ( V_4 -> V_53 )
F_68 ( V_4 -> V_53 ) ;
F_69 ( V_4 ) ;
return V_26 ;
}
bool F_70 ( struct V_28 * V_29 )
{
switch ( V_29 -> V_54 ) {
case V_55 :
return true ;
case V_56 :
return false ;
default:
if ( F_71 ( V_29 -> V_57 ) )
return true ;
return false ;
}
}
static int F_72 ( struct V_28 * V_29 , void * V_58 )
{
struct V_59 * V_60 = V_58 ;
struct V_3 * V_4 = V_60 -> V_4 ;
bool V_61 ;
int V_26 ;
if ( V_4 -> V_20 )
return - V_52 ;
V_26 = F_73 ( V_29 , V_4 ) ;
if ( V_26 == 0 ) {
return 0 ;
} else if ( V_26 == - V_31 ) {
F_12 ( V_4 , L_16 ) ;
F_15 ( V_4 ) ;
} else if ( V_26 < 0 ) {
F_12 ( V_4 , L_17 , V_26 ) ;
return V_26 ;
}
V_61 = F_70 ( V_29 ) ;
if ( V_61 )
V_60 -> V_62 = true ;
if ( V_60 -> V_63 && V_61 != V_60 -> V_64 )
return 0 ;
return F_62 ( V_29 , V_4 ) ;
}
static void F_74 ( void * V_65 , T_1 V_66 )
{
struct V_3 * V_4 = V_65 ;
struct V_59 V_60 = {
. V_4 = V_4 ,
. V_63 = true ,
. V_64 = true ,
} ;
F_75 ( V_4 ) ;
if ( V_4 -> V_53 )
F_65 ( V_4 -> V_53 ) ;
F_76 ( V_4 -> V_23 , NULL , & V_60 , F_72 ) ;
F_12 ( V_4 , L_18 ) ;
F_67 ( V_4 ) ;
if ( V_4 -> V_53 )
F_68 ( V_4 -> V_53 ) ;
F_77 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static int F_78 ( struct V_3 * V_4 , bool V_67 )
{
int V_26 = 0 ;
F_75 ( V_4 ) ;
if ( V_4 -> V_20 ) {
if ( F_27 ( V_4 ) ) {
V_26 = 1 ;
goto V_68;
}
V_26 = F_42 ( V_4 ) ;
if ( V_26 == 0 )
V_26 = 1 ;
else {
V_4 -> V_20 = NULL ;
V_26 = 0 ;
}
} else {
struct V_59 V_60 = {
. V_4 = V_4 ,
. V_63 = V_67 ,
. V_64 = false ,
} ;
if ( V_4 -> V_53 )
F_65 ( V_4 -> V_53 ) ;
V_26 = F_76 ( V_4 -> V_23 , NULL , & V_60 ,
F_72 ) ;
if ( ! V_26 && V_67 && V_60 . V_62 ) {
F_12 ( V_4 , L_19 ) ;
F_7 ( V_4 ) ;
F_79 ( F_74 , V_4 ) ;
} else {
F_67 ( V_4 ) ;
}
if ( V_4 -> V_53 )
F_68 ( V_4 -> V_53 ) ;
}
V_68:
F_77 ( V_4 ) ;
return V_26 ;
}
int F_80 ( struct V_3 * V_4 )
{
return F_78 ( V_4 , false ) ;
}
void F_81 ( struct V_3 * V_4 )
{
F_78 ( V_4 , true ) ;
}
static int F_82 ( struct V_3 * V_4 , void * V_60 )
{
struct V_28 * V_29 = V_60 ;
int V_26 ;
V_26 = F_73 ( V_29 , V_4 ) ;
if ( V_26 == 0 ) {
return 0 ;
} else if ( V_26 == - V_31 ) {
F_12 ( V_4 , L_16 ) ;
F_15 ( V_4 ) ;
} else if ( V_26 < 0 ) {
F_12 ( V_4 , L_17 , V_26 ) ;
return V_26 ;
}
if ( V_4 -> V_53 )
F_75 ( V_4 -> V_53 ) ;
F_75 ( V_4 ) ;
if ( ! V_4 -> V_20 )
F_62 ( V_29 , V_4 ) ;
F_77 ( V_4 ) ;
if ( V_4 -> V_53 )
F_77 ( V_4 -> V_53 ) ;
return 0 ;
}
int F_83 ( struct V_28 * V_29 )
{
return F_84 ( V_29 -> V_23 , NULL , V_29 , F_82 ) ;
}
static void F_85 ( struct V_3 * V_4 , struct V_3 * V_53 )
{
struct V_28 * V_29 ;
V_29 = V_4 -> V_20 ;
if ( V_29 ) {
if ( F_70 ( V_29 ) )
F_61 () ;
while ( F_86 ( V_4 ) ) {
F_77 ( V_4 ) ;
if ( V_53 )
F_77 ( V_53 ) ;
F_87 ( V_4 ) ;
if ( V_53 )
F_75 ( V_53 ) ;
F_75 ( V_4 ) ;
if ( V_4 -> V_20 != V_29 )
return;
}
F_65 ( V_4 ) ;
F_88 ( V_4 ) ;
F_41 ( V_4 ) ;
if ( V_4 -> V_23 )
F_37 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_69 ,
V_4 ) ;
F_89 ( V_4 ) ;
if ( V_4 -> V_23 && V_4 -> V_23 -> remove )
V_4 -> V_23 -> remove ( V_4 ) ;
else if ( V_29 -> remove )
V_29 -> remove ( V_4 ) ;
F_90 ( V_4 ) ;
F_55 ( V_4 ) ;
F_51 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_52 ( V_4 , NULL ) ;
if ( V_4 -> V_43 && V_4 -> V_43 -> V_46 )
V_4 -> V_43 -> V_46 ( V_4 ) ;
F_53 ( V_4 ) ;
F_91 ( & V_4 -> V_9 -> V_16 ) ;
F_36 ( V_4 ) ;
if ( V_4 -> V_23 )
F_37 ( & V_4 -> V_23 -> V_9 -> V_24 ,
V_70 ,
V_4 ) ;
}
}
void F_92 ( struct V_3 * V_4 ,
struct V_28 * V_29 ,
struct V_3 * V_53 )
{
if ( V_53 )
F_75 ( V_53 ) ;
F_75 ( V_4 ) ;
if ( ! V_29 || V_29 == V_4 -> V_20 )
F_85 ( V_4 , V_53 ) ;
F_77 ( V_4 ) ;
if ( V_53 )
F_77 ( V_53 ) ;
}
void F_93 ( struct V_3 * V_4 )
{
F_92 ( V_4 , NULL , NULL ) ;
}
void F_94 ( struct V_28 * V_29 )
{
struct V_5 * V_71 ;
struct V_3 * V_4 ;
for (; ; ) {
F_95 ( & V_29 -> V_9 -> V_22 . V_72 ) ;
if ( F_3 ( & V_29 -> V_9 -> V_22 . V_73 ) ) {
F_96 ( & V_29 -> V_9 -> V_22 . V_72 ) ;
break;
}
V_71 = F_97 ( V_29 -> V_9 -> V_22 . V_73 . V_74 ,
struct V_5 ,
V_16 . V_75 ) ;
V_4 = V_71 -> V_3 ;
F_7 ( V_4 ) ;
F_96 ( & V_29 -> V_9 -> V_22 . V_72 ) ;
F_92 ( V_4 , V_29 , V_4 -> V_53 ) ;
F_14 ( V_4 ) ;
}
}
