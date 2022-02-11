static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_2 ( & V_3 -> V_5 ) )
return NULL ;
V_4 = F_3 ( V_3 -> V_5 . V_6 , struct V_1 ,
V_7 ) ;
F_4 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 )
{
F_6 ( & V_4 -> V_7 , & V_4 -> V_8 -> V_5 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_9 * V_10 , * V_11 ;
F_8 (e, tmp, &cm_id_priv->work_free_list)
F_9 ( F_3 ( V_10 , struct V_1 , V_7 ) ) ;
}
static int F_10 ( struct V_2 * V_3 , int V_12 )
{
struct V_1 * V_4 ;
F_11 ( ! F_2 ( & V_3 -> V_5 ) ) ;
while ( V_12 -- ) {
V_4 = F_12 ( sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_4 ) {
F_7 ( V_3 ) ;
return - V_14 ;
}
V_4 -> V_8 = V_3 ;
F_13 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
void * V_18 ;
V_18 = F_15 ( V_17 -> V_19 , V_17 -> V_20 , V_21 ) ;
if ( ! V_18 )
return - V_14 ;
V_17 -> V_19 = V_18 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
F_11 ( F_18 ( & V_3 -> V_22 ) == 0 ) ;
if ( F_19 ( & V_3 -> V_22 ) ) {
F_11 ( ! F_2 ( & V_3 -> V_23 ) ) ;
F_20 ( & V_3 -> V_24 ) ;
return 1 ;
}
return 0 ;
}
static void F_21 ( struct V_25 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_23 ( & V_3 -> V_22 ) ;
}
static void F_24 ( struct V_25 * V_8 )
{
struct V_2 * V_3 ;
int V_27 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
V_27 = F_25 ( V_28 , & V_3 -> V_29 ) ;
if ( F_17 ( V_3 ) && V_27 ) {
F_11 ( ! F_2 ( & V_3 -> V_23 ) ) ;
F_16 ( V_3 ) ;
}
}
struct V_25 * F_26 ( struct V_30 * V_31 ,
T_1 V_32 ,
void * V_33 )
{
struct V_2 * V_3 ;
V_3 = F_27 ( sizeof( * V_3 ) , V_13 ) ;
if ( ! V_3 )
return F_28 ( - V_14 ) ;
V_3 -> V_34 = V_35 ;
V_3 -> V_26 . V_31 = V_31 ;
V_3 -> V_26 . V_32 = V_32 ;
V_3 -> V_26 . V_33 = V_33 ;
V_3 -> V_26 . V_36 = V_37 ;
V_3 -> V_26 . F_21 = F_21 ;
V_3 -> V_26 . F_24 = F_24 ;
F_29 ( & V_3 -> V_38 ) ;
F_30 ( & V_3 -> V_22 , 1 ) ;
F_31 ( & V_3 -> V_39 ) ;
F_32 ( & V_3 -> V_24 ) ;
F_13 ( & V_3 -> V_23 ) ;
F_13 ( & V_3 -> V_5 ) ;
return & V_3 -> V_26 ;
}
static int F_33 ( struct V_40 * V_41 )
{
struct V_42 V_43 ;
if ( ! V_41 )
return - V_44 ;
V_43 . V_45 = V_46 ;
return F_34 ( V_41 , & V_43 , V_47 ) ;
}
static int F_35 ( struct V_40 * V_41 )
{
struct V_42 V_43 ;
F_11 ( V_41 == NULL ) ;
V_43 . V_45 = V_48 ;
return F_34 ( V_41 , & V_43 , V_47 ) ;
}
int F_36 ( struct V_25 * V_8 , int V_49 )
{
struct V_2 * V_3 ;
unsigned long V_29 ;
int V_50 = 0 ;
struct V_40 * V_41 = NULL ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_37 ( V_3 -> V_39 ,
! F_25 ( V_51 , & V_3 -> V_29 ) ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
switch ( V_3 -> V_34 ) {
case V_52 :
V_3 -> V_34 = V_53 ;
if ( V_3 -> V_41 )
V_41 = V_3 -> V_41 ;
else
V_50 = - V_44 ;
break;
case V_54 :
V_50 = - V_44 ;
break;
case V_53 :
case V_35 :
break;
case V_55 :
break;
case V_56 :
default:
F_39 () ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
if ( V_41 ) {
if ( V_49 )
V_50 = F_33 ( V_41 ) ;
else
V_50 = F_35 ( V_41 ) ;
V_50 = 0 ;
}
return V_50 ;
}
static void F_41 ( struct V_25 * V_8 )
{
struct V_2 * V_3 ;
unsigned long V_29 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_37 ( V_3 -> V_39 ,
! F_25 ( V_51 , & V_3 -> V_29 ) ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
switch ( V_3 -> V_34 ) {
case V_54 :
V_3 -> V_34 = V_57 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_8 -> V_31 -> V_58 -> V_59 ( V_8 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
break;
case V_52 :
V_3 -> V_34 = V_57 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
( void ) F_33 ( V_3 -> V_41 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
break;
case V_35 :
case V_53 :
V_3 -> V_34 = V_57 ;
break;
case V_55 :
V_3 -> V_34 = V_57 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_8 -> V_31 -> V_58 -> V_60 ( V_8 , NULL , 0 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
break;
case V_56 :
case V_57 :
default:
F_39 () ;
break;
}
if ( V_3 -> V_41 ) {
V_3 -> V_26 . V_31 -> V_58 -> F_24 ( V_3 -> V_41 ) ;
V_3 -> V_41 = NULL ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
( void ) F_17 ( V_3 ) ;
}
void F_42 ( struct V_25 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_11 ( F_25 ( V_28 , & V_3 -> V_29 ) ) ;
F_41 ( V_8 ) ;
F_43 ( & V_3 -> V_24 ) ;
F_16 ( V_3 ) ;
}
int F_44 ( struct V_25 * V_8 , int V_61 )
{
struct V_2 * V_3 ;
unsigned long V_29 ;
int V_50 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
if ( ! V_61 )
V_61 = V_62 ;
V_50 = F_10 ( V_3 , V_61 ) ;
if ( V_50 )
return V_50 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
switch ( V_3 -> V_34 ) {
case V_35 :
V_3 -> V_34 = V_54 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_8 -> V_31 -> V_58 -> V_63 ( V_8 , V_61 ) ;
if ( V_50 )
V_3 -> V_34 = V_35 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
break;
default:
V_50 = - V_44 ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
return V_50 ;
}
int F_45 ( struct V_25 * V_8 ,
const void * V_19 ,
T_2 V_20 )
{
struct V_2 * V_3 ;
unsigned long V_29 ;
int V_50 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_46 ( V_51 , & V_3 -> V_29 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_34 != V_55 ) {
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
return - V_44 ;
}
V_3 -> V_34 = V_35 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_8 -> V_31 -> V_58 -> V_60 ( V_8 , V_19 ,
V_20 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
return V_50 ;
}
int F_49 ( struct V_25 * V_8 ,
struct V_64 * V_65 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
unsigned long V_29 ;
int V_50 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_46 ( V_51 , & V_3 -> V_29 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_34 != V_55 ) {
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
return - V_44 ;
}
V_41 = V_8 -> V_31 -> V_58 -> V_66 ( V_8 -> V_31 , V_65 -> V_67 ) ;
if ( ! V_41 ) {
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
return - V_44 ;
}
V_8 -> V_31 -> V_58 -> F_21 ( V_41 ) ;
V_3 -> V_41 = V_41 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_8 -> V_31 -> V_58 -> V_68 ( V_8 , V_65 ) ;
if ( V_50 ) {
F_11 ( V_3 -> V_34 != V_55 ) ;
V_3 -> V_34 = V_35 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_41 ) {
V_8 -> V_31 -> V_58 -> F_24 ( V_41 ) ;
V_3 -> V_41 = NULL ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
}
return V_50 ;
}
int F_50 ( struct V_25 * V_8 , struct V_64 * V_65 )
{
struct V_2 * V_3 ;
int V_50 ;
unsigned long V_29 ;
struct V_40 * V_41 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
V_50 = F_10 ( V_3 , 4 ) ;
if ( V_50 )
return V_50 ;
F_46 ( V_51 , & V_3 -> V_29 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_34 != V_35 ) {
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
return - V_44 ;
}
V_41 = V_8 -> V_31 -> V_58 -> V_66 ( V_8 -> V_31 , V_65 -> V_67 ) ;
if ( ! V_41 ) {
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
return - V_44 ;
}
V_8 -> V_31 -> V_58 -> F_21 ( V_41 ) ;
V_3 -> V_41 = V_41 ;
V_3 -> V_34 = V_56 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_8 -> V_31 -> V_58 -> V_69 ( V_8 , V_65 ) ;
if ( V_50 ) {
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_41 ) {
V_8 -> V_31 -> V_58 -> F_24 ( V_41 ) ;
V_3 -> V_41 = NULL ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
F_11 ( V_3 -> V_34 != V_56 ) ;
V_3 -> V_34 = V_35 ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_48 ( & V_3 -> V_39 ) ;
}
return V_50 ;
}
static void F_51 ( struct V_2 * V_70 ,
struct V_16 * V_71 )
{
unsigned long V_29 ;
struct V_25 * V_8 ;
struct V_2 * V_3 ;
int V_50 ;
F_11 ( V_71 -> V_72 ) ;
V_8 = F_26 ( V_70 -> V_26 . V_31 ,
V_70 -> V_26 . V_32 ,
V_70 -> V_26 . V_33 ) ;
if ( F_52 ( V_8 ) )
goto V_73;
V_8 -> V_74 = V_71 -> V_74 ;
V_8 -> V_75 = V_71 -> V_75 ;
V_8 -> V_76 = V_71 -> V_76 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
V_3 -> V_34 = V_55 ;
F_38 ( & V_70 -> V_38 , V_29 ) ;
if ( V_70 -> V_34 != V_54 ) {
F_40 ( & V_70 -> V_38 , V_29 ) ;
F_45 ( V_8 , NULL , 0 ) ;
F_42 ( V_8 ) ;
goto V_73;
}
F_40 ( & V_70 -> V_38 , V_29 ) ;
V_50 = F_10 ( V_3 , 3 ) ;
if ( V_50 ) {
F_45 ( V_8 , NULL , 0 ) ;
F_42 ( V_8 ) ;
goto V_73;
}
V_50 = V_8 -> V_32 ( V_8 , V_71 ) ;
if ( V_50 ) {
F_45 ( V_8 , NULL , 0 ) ;
F_46 ( V_28 , & V_3 -> V_29 ) ;
F_41 ( V_8 ) ;
if ( F_18 ( & V_3 -> V_22 ) == 0 )
F_16 ( V_3 ) ;
}
V_73:
if ( V_71 -> V_20 )
F_9 ( V_71 -> V_19 ) ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_16 * V_71 )
{
unsigned long V_29 ;
int V_50 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_11 ( V_3 -> V_34 != V_55 ) ;
V_3 -> V_34 = V_52 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_3 -> V_26 . V_32 ( & V_3 -> V_26 , V_71 ) ;
F_48 ( & V_3 -> V_39 ) ;
return V_50 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_16 * V_71 )
{
unsigned long V_29 ;
int V_50 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
F_47 ( V_51 , & V_3 -> V_29 ) ;
F_11 ( V_3 -> V_34 != V_56 ) ;
if ( V_71 -> V_72 == 0 ) {
V_3 -> V_26 . V_75 = V_71 -> V_75 ;
V_3 -> V_26 . V_76 = V_71 -> V_76 ;
V_3 -> V_34 = V_52 ;
} else {
V_3 -> V_26 . V_31 -> V_58 -> F_24 ( V_3 -> V_41 ) ;
V_3 -> V_41 = NULL ;
V_3 -> V_34 = V_35 ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_3 -> V_26 . V_32 ( & V_3 -> V_26 , V_71 ) ;
if ( V_71 -> V_20 )
F_9 ( V_71 -> V_19 ) ;
F_48 ( & V_3 -> V_39 ) ;
return V_50 ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_16 * V_71 )
{
unsigned long V_29 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_34 == V_52 )
V_3 -> V_34 = V_53 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_16 * V_71 )
{
unsigned long V_29 ;
int V_50 = 0 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
if ( V_3 -> V_41 ) {
V_3 -> V_26 . V_31 -> V_58 -> F_24 ( V_3 -> V_41 ) ;
V_3 -> V_41 = NULL ;
}
switch ( V_3 -> V_34 ) {
case V_52 :
case V_53 :
V_3 -> V_34 = V_35 ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = V_3 -> V_26 . V_32 ( & V_3 -> V_26 , V_71 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
break;
case V_57 :
break;
default:
F_39 () ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
return V_50 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_16 * V_71 )
{
int V_50 = 0 ;
switch ( V_71 -> V_17 ) {
case V_77 :
F_51 ( V_3 , V_71 ) ;
break;
case V_78 :
V_50 = F_54 ( V_3 , V_71 ) ;
break;
case V_79 :
V_50 = F_53 ( V_3 , V_71 ) ;
break;
case V_80 :
F_55 ( V_3 , V_71 ) ;
break;
case V_81 :
V_50 = F_56 ( V_3 , V_71 ) ;
break;
default:
F_39 () ;
}
return V_50 ;
}
static void F_58 ( struct V_82 * V_83 )
{
struct V_1 * V_4 = F_22 ( V_83 , struct V_1 , V_4 ) ;
struct V_16 V_84 ;
struct V_2 * V_3 = V_4 -> V_8 ;
unsigned long V_29 ;
int V_85 ;
int V_50 = 0 ;
int V_86 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
V_85 = F_2 ( & V_3 -> V_23 ) ;
while ( ! V_85 ) {
V_4 = F_3 ( V_3 -> V_23 . V_6 ,
struct V_1 , V_15 ) ;
F_4 ( & V_4 -> V_15 ) ;
V_85 = F_2 ( & V_3 -> V_23 ) ;
V_84 = V_4 -> V_17 ;
F_5 ( V_4 ) ;
F_40 ( & V_3 -> V_38 , V_29 ) ;
V_50 = F_57 ( V_3 , & V_84 ) ;
if ( V_50 ) {
F_46 ( V_28 , & V_3 -> V_29 ) ;
F_41 ( & V_3 -> V_26 ) ;
}
F_11 ( F_18 ( & V_3 -> V_22 ) == 0 ) ;
V_86 = F_25 ( V_28 , & V_3 -> V_29 ) ;
if ( F_17 ( V_3 ) ) {
if ( V_86 ) {
F_11 ( ! F_2 ( & V_3 -> V_23 ) ) ;
F_16 ( V_3 ) ;
}
return;
}
if ( V_85 )
return;
F_38 ( & V_3 -> V_38 , V_29 ) ;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
}
static int V_37 ( struct V_25 * V_8 ,
struct V_16 * V_71 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
unsigned long V_29 ;
int V_50 = 0 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_50 = - V_14 ;
goto V_73;
}
F_59 ( & V_4 -> V_4 , F_58 ) ;
V_4 -> V_8 = V_3 ;
V_4 -> V_17 = * V_71 ;
if ( ( V_4 -> V_17 . V_17 == V_77 ||
V_4 -> V_17 . V_17 == V_78 ) &&
V_4 -> V_17 . V_20 ) {
V_50 = F_14 ( & V_4 -> V_17 ) ;
if ( V_50 ) {
F_5 ( V_4 ) ;
goto V_73;
}
}
F_23 ( & V_3 -> V_22 ) ;
if ( F_2 ( & V_3 -> V_23 ) ) {
F_60 ( & V_4 -> V_15 , & V_3 -> V_23 ) ;
F_61 ( V_87 , & V_4 -> V_4 ) ;
} else
F_60 ( & V_4 -> V_15 , & V_3 -> V_23 ) ;
V_73:
F_40 ( & V_3 -> V_38 , V_29 ) ;
return V_50 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
int * V_88 )
{
unsigned long V_29 ;
int V_50 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
switch ( V_3 -> V_34 ) {
case V_35 :
case V_56 :
case V_55 :
case V_52 :
* V_88 = V_47 | V_89 ;
V_43 -> V_90 = V_91 |
V_92 ;
V_50 = 0 ;
break;
default:
V_50 = - V_44 ;
break;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
return V_50 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
int * V_88 )
{
unsigned long V_29 ;
int V_50 ;
F_38 ( & V_3 -> V_38 , V_29 ) ;
switch ( V_3 -> V_34 ) {
case V_35 :
case V_56 :
case V_55 :
case V_52 :
* V_88 = 0 ;
V_50 = 0 ;
break;
default:
V_50 = - V_44 ;
break;
}
F_40 ( & V_3 -> V_38 , V_29 ) ;
return V_50 ;
}
int F_64 ( struct V_25 * V_8 ,
struct V_42 * V_43 ,
int * V_88 )
{
struct V_2 * V_3 ;
int V_50 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
switch ( V_43 -> V_45 ) {
case V_93 :
case V_94 :
V_50 = F_62 ( V_3 ,
V_43 , V_88 ) ;
break;
case V_95 :
V_50 = F_63 ( V_3 ,
V_43 , V_88 ) ;
break;
default:
V_50 = - V_44 ;
break;
}
return V_50 ;
}
static int T_3 F_65 ( void )
{
V_87 = F_66 ( L_1 ) ;
if ( ! V_87 )
return - V_14 ;
V_96 = F_67 ( & V_97 , L_2 ,
V_98 ) ;
if ( ! V_96 ) {
F_68 ( L_3 ) ;
F_69 ( V_87 ) ;
return - V_14 ;
}
return 0 ;
}
static void T_4 F_70 ( void )
{
F_71 ( V_96 ) ;
F_69 ( V_87 ) ;
}
