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
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
if ( F_17 ( V_3 ) &&
F_25 ( V_27 , & V_3 -> V_28 ) ) {
F_11 ( ! F_2 ( & V_3 -> V_23 ) ) ;
F_16 ( V_3 ) ;
}
}
struct V_25 * F_26 ( struct V_29 * V_30 ,
T_1 V_31 ,
void * V_32 )
{
struct V_2 * V_3 ;
V_3 = F_27 ( sizeof( * V_3 ) , V_13 ) ;
if ( ! V_3 )
return F_28 ( - V_14 ) ;
V_3 -> V_33 = V_34 ;
V_3 -> V_26 . V_30 = V_30 ;
V_3 -> V_26 . V_31 = V_31 ;
V_3 -> V_26 . V_32 = V_32 ;
V_3 -> V_26 . V_35 = V_36 ;
V_3 -> V_26 . F_21 = F_21 ;
V_3 -> V_26 . F_24 = F_24 ;
F_29 ( & V_3 -> V_37 ) ;
F_30 ( & V_3 -> V_22 , 1 ) ;
F_31 ( & V_3 -> V_38 ) ;
F_32 ( & V_3 -> V_24 ) ;
F_13 ( & V_3 -> V_23 ) ;
F_13 ( & V_3 -> V_5 ) ;
return & V_3 -> V_26 ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_41 V_42 ;
if ( ! V_40 )
return - V_43 ;
V_42 . V_44 = V_45 ;
return F_34 ( V_40 , & V_42 , V_46 ) ;
}
static int F_35 ( struct V_39 * V_40 )
{
struct V_41 V_42 ;
F_11 ( V_40 == NULL ) ;
V_42 . V_44 = V_47 ;
return F_34 ( V_40 , & V_42 , V_46 ) ;
}
int F_36 ( struct V_25 * V_8 , int V_48 )
{
struct V_2 * V_3 ;
unsigned long V_28 ;
int V_49 = 0 ;
struct V_39 * V_40 = NULL ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_37 ( V_3 -> V_38 ,
! F_25 ( V_50 , & V_3 -> V_28 ) ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
switch ( V_3 -> V_33 ) {
case V_51 :
V_3 -> V_33 = V_52 ;
if ( V_3 -> V_40 )
V_40 = V_3 -> V_40 ;
else
V_49 = - V_43 ;
break;
case V_53 :
V_49 = - V_43 ;
break;
case V_52 :
case V_34 :
break;
case V_54 :
break;
case V_55 :
default:
F_39 () ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
if ( V_40 ) {
if ( V_48 )
V_49 = F_33 ( V_40 ) ;
else
V_49 = F_35 ( V_40 ) ;
V_49 = 0 ;
}
return V_49 ;
}
static void F_41 ( struct V_25 * V_8 )
{
struct V_2 * V_3 ;
unsigned long V_28 ;
int V_49 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_37 ( V_3 -> V_38 ,
! F_25 ( V_50 , & V_3 -> V_28 ) ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
switch ( V_3 -> V_33 ) {
case V_53 :
V_3 -> V_33 = V_56 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_8 -> V_30 -> V_57 -> V_58 ( V_8 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
break;
case V_51 :
V_3 -> V_33 = V_56 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
( void ) F_33 ( V_3 -> V_40 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
break;
case V_34 :
case V_52 :
V_3 -> V_33 = V_56 ;
break;
case V_54 :
V_3 -> V_33 = V_56 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_8 -> V_30 -> V_57 -> V_59 ( V_8 , NULL , 0 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
break;
case V_55 :
case V_56 :
default:
F_39 () ;
break;
}
if ( V_3 -> V_40 ) {
V_3 -> V_26 . V_30 -> V_57 -> F_24 ( V_3 -> V_40 ) ;
V_3 -> V_40 = NULL ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
( void ) F_17 ( V_3 ) ;
}
void F_42 ( struct V_25 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_11 ( F_25 ( V_27 , & V_3 -> V_28 ) ) ;
F_41 ( V_8 ) ;
F_43 ( & V_3 -> V_24 ) ;
F_16 ( V_3 ) ;
}
int F_44 ( struct V_25 * V_8 , int V_60 )
{
struct V_2 * V_3 ;
unsigned long V_28 ;
int V_49 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
V_49 = F_10 ( V_3 , V_60 ) ;
if ( V_49 )
return V_49 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
switch ( V_3 -> V_33 ) {
case V_34 :
V_3 -> V_33 = V_53 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_8 -> V_30 -> V_57 -> V_61 ( V_8 , V_60 ) ;
if ( V_49 )
V_3 -> V_33 = V_34 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
break;
default:
V_49 = - V_43 ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
return V_49 ;
}
int F_45 ( struct V_25 * V_8 ,
const void * V_19 ,
T_2 V_20 )
{
struct V_2 * V_3 ;
unsigned long V_28 ;
int V_49 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_46 ( V_50 , & V_3 -> V_28 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_33 != V_54 ) {
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
return - V_43 ;
}
V_3 -> V_33 = V_34 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_8 -> V_30 -> V_57 -> V_59 ( V_8 , V_19 ,
V_20 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
return V_49 ;
}
int F_49 ( struct V_25 * V_8 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 ;
struct V_39 * V_40 ;
unsigned long V_28 ;
int V_49 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_46 ( V_50 , & V_3 -> V_28 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_33 != V_54 ) {
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
return - V_43 ;
}
V_40 = V_8 -> V_30 -> V_57 -> V_64 ( V_8 -> V_30 , V_63 -> V_65 ) ;
if ( ! V_40 ) {
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
return - V_43 ;
}
V_8 -> V_30 -> V_57 -> F_21 ( V_40 ) ;
V_3 -> V_40 = V_40 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_8 -> V_30 -> V_57 -> V_66 ( V_8 , V_63 ) ;
if ( V_49 ) {
F_11 ( V_3 -> V_33 != V_54 ) ;
V_3 -> V_33 = V_34 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_40 ) {
V_8 -> V_30 -> V_57 -> F_24 ( V_40 ) ;
V_3 -> V_40 = NULL ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
}
return V_49 ;
}
int F_50 ( struct V_25 * V_8 , struct V_62 * V_63 )
{
struct V_2 * V_3 ;
int V_49 ;
unsigned long V_28 ;
struct V_39 * V_40 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
V_49 = F_10 ( V_3 , 4 ) ;
if ( V_49 )
return V_49 ;
F_46 ( V_50 , & V_3 -> V_28 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_33 != V_34 ) {
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
return - V_43 ;
}
V_40 = V_8 -> V_30 -> V_57 -> V_64 ( V_8 -> V_30 , V_63 -> V_65 ) ;
if ( ! V_40 ) {
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
return - V_43 ;
}
V_8 -> V_30 -> V_57 -> F_21 ( V_40 ) ;
V_3 -> V_40 = V_40 ;
V_3 -> V_33 = V_55 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_8 -> V_30 -> V_57 -> V_67 ( V_8 , V_63 ) ;
if ( V_49 ) {
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_40 ) {
V_8 -> V_30 -> V_57 -> F_24 ( V_40 ) ;
V_3 -> V_40 = NULL ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
F_11 ( V_3 -> V_33 != V_55 ) ;
V_3 -> V_33 = V_34 ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_48 ( & V_3 -> V_38 ) ;
}
return V_49 ;
}
static void F_51 ( struct V_2 * V_68 ,
struct V_16 * V_69 )
{
unsigned long V_28 ;
struct V_25 * V_8 ;
struct V_2 * V_3 ;
int V_49 ;
F_11 ( V_69 -> V_70 ) ;
F_38 ( & V_68 -> V_37 , V_28 ) ;
if ( V_68 -> V_33 != V_53 ) {
F_40 ( & V_68 -> V_37 , V_28 ) ;
goto V_71;
}
F_40 ( & V_68 -> V_37 , V_28 ) ;
V_8 = F_26 ( V_68 -> V_26 . V_30 ,
V_68 -> V_26 . V_31 ,
V_68 -> V_26 . V_32 ) ;
if ( F_52 ( V_8 ) )
goto V_71;
V_8 -> V_72 = V_69 -> V_72 ;
V_8 -> V_73 = V_69 -> V_73 ;
V_8 -> V_74 = V_69 -> V_74 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
V_3 -> V_33 = V_54 ;
V_49 = F_10 ( V_3 , 3 ) ;
if ( V_49 ) {
F_45 ( V_8 , NULL , 0 ) ;
F_42 ( V_8 ) ;
goto V_71;
}
V_49 = V_8 -> V_31 ( V_8 , V_69 ) ;
if ( V_49 ) {
F_45 ( V_8 , NULL , 0 ) ;
F_46 ( V_27 , & V_3 -> V_28 ) ;
F_41 ( V_8 ) ;
if ( F_18 ( & V_3 -> V_22 ) == 0 )
F_16 ( V_3 ) ;
}
V_71:
if ( V_69 -> V_20 )
F_9 ( V_69 -> V_19 ) ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_16 * V_69 )
{
unsigned long V_28 ;
int V_49 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_11 ( V_3 -> V_33 != V_54 ) ;
V_3 -> V_33 = V_51 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_3 -> V_26 . V_31 ( & V_3 -> V_26 , V_69 ) ;
F_48 ( & V_3 -> V_38 ) ;
return V_49 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_16 * V_69 )
{
unsigned long V_28 ;
int V_49 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
F_47 ( V_50 , & V_3 -> V_28 ) ;
F_11 ( V_3 -> V_33 != V_55 ) ;
if ( V_69 -> V_70 == 0 ) {
V_3 -> V_26 . V_73 = V_69 -> V_73 ;
V_3 -> V_26 . V_74 = V_69 -> V_74 ;
V_3 -> V_33 = V_51 ;
} else {
V_3 -> V_26 . V_30 -> V_57 -> F_24 ( V_3 -> V_40 ) ;
V_3 -> V_40 = NULL ;
V_3 -> V_33 = V_34 ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_3 -> V_26 . V_31 ( & V_3 -> V_26 , V_69 ) ;
if ( V_69 -> V_20 )
F_9 ( V_69 -> V_19 ) ;
F_48 ( & V_3 -> V_38 ) ;
return V_49 ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_16 * V_69 )
{
unsigned long V_28 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_33 == V_51 )
V_3 -> V_33 = V_52 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_16 * V_69 )
{
unsigned long V_28 ;
int V_49 = 0 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
if ( V_3 -> V_40 ) {
V_3 -> V_26 . V_30 -> V_57 -> F_24 ( V_3 -> V_40 ) ;
V_3 -> V_40 = NULL ;
}
switch ( V_3 -> V_33 ) {
case V_51 :
case V_52 :
V_3 -> V_33 = V_34 ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = V_3 -> V_26 . V_31 ( & V_3 -> V_26 , V_69 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
break;
case V_56 :
break;
default:
F_39 () ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
return V_49 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_16 * V_69 )
{
int V_49 = 0 ;
switch ( V_69 -> V_17 ) {
case V_75 :
F_51 ( V_3 , V_69 ) ;
break;
case V_76 :
V_49 = F_54 ( V_3 , V_69 ) ;
break;
case V_77 :
V_49 = F_53 ( V_3 , V_69 ) ;
break;
case V_78 :
F_55 ( V_3 , V_69 ) ;
break;
case V_79 :
V_49 = F_56 ( V_3 , V_69 ) ;
break;
default:
F_39 () ;
}
return V_49 ;
}
static void F_58 ( struct V_80 * V_81 )
{
struct V_1 * V_4 = F_22 ( V_81 , struct V_1 , V_4 ) ;
struct V_16 V_82 ;
struct V_2 * V_3 = V_4 -> V_8 ;
unsigned long V_28 ;
int V_83 ;
int V_49 = 0 ;
int V_84 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
V_83 = F_2 ( & V_3 -> V_23 ) ;
while ( ! V_83 ) {
V_4 = F_3 ( V_3 -> V_23 . V_6 ,
struct V_1 , V_15 ) ;
F_4 ( & V_4 -> V_15 ) ;
V_83 = F_2 ( & V_3 -> V_23 ) ;
V_82 = V_4 -> V_17 ;
F_5 ( V_4 ) ;
F_40 ( & V_3 -> V_37 , V_28 ) ;
V_49 = F_57 ( V_3 , & V_82 ) ;
if ( V_49 ) {
F_46 ( V_27 , & V_3 -> V_28 ) ;
F_41 ( & V_3 -> V_26 ) ;
}
F_11 ( F_18 ( & V_3 -> V_22 ) == 0 ) ;
V_84 = F_25 ( V_27 , & V_3 -> V_28 ) ;
if ( F_17 ( V_3 ) ) {
if ( V_84 ) {
F_11 ( ! F_2 ( & V_3 -> V_23 ) ) ;
F_16 ( V_3 ) ;
}
return;
}
F_38 ( & V_3 -> V_37 , V_28 ) ;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
}
static int V_36 ( struct V_25 * V_8 ,
struct V_16 * V_69 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
unsigned long V_28 ;
int V_49 = 0 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_49 = - V_14 ;
goto V_71;
}
F_59 ( & V_4 -> V_4 , F_58 ) ;
V_4 -> V_8 = V_3 ;
V_4 -> V_17 = * V_69 ;
if ( ( V_4 -> V_17 . V_17 == V_75 ||
V_4 -> V_17 . V_17 == V_76 ) &&
V_4 -> V_17 . V_20 ) {
V_49 = F_14 ( & V_4 -> V_17 ) ;
if ( V_49 ) {
F_5 ( V_4 ) ;
goto V_71;
}
}
F_23 ( & V_3 -> V_22 ) ;
if ( F_2 ( & V_3 -> V_23 ) ) {
F_60 ( & V_4 -> V_15 , & V_3 -> V_23 ) ;
F_61 ( V_85 , & V_4 -> V_4 ) ;
} else
F_60 ( & V_4 -> V_15 , & V_3 -> V_23 ) ;
V_71:
F_40 ( & V_3 -> V_37 , V_28 ) ;
return V_49 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
int * V_86 )
{
unsigned long V_28 ;
int V_49 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
switch ( V_3 -> V_33 ) {
case V_34 :
case V_55 :
case V_54 :
case V_51 :
* V_86 = V_46 | V_87 ;
V_42 -> V_88 = V_89 |
V_90 ;
V_49 = 0 ;
break;
default:
V_49 = - V_43 ;
break;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
return V_49 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
int * V_86 )
{
unsigned long V_28 ;
int V_49 ;
F_38 ( & V_3 -> V_37 , V_28 ) ;
switch ( V_3 -> V_33 ) {
case V_34 :
case V_55 :
case V_54 :
case V_51 :
* V_86 = 0 ;
V_49 = 0 ;
break;
default:
V_49 = - V_43 ;
break;
}
F_40 ( & V_3 -> V_37 , V_28 ) ;
return V_49 ;
}
int F_64 ( struct V_25 * V_8 ,
struct V_41 * V_42 ,
int * V_86 )
{
struct V_2 * V_3 ;
int V_49 ;
V_3 = F_22 ( V_8 , struct V_2 , V_26 ) ;
switch ( V_42 -> V_44 ) {
case V_91 :
case V_92 :
V_49 = F_62 ( V_3 ,
V_42 , V_86 ) ;
break;
case V_93 :
V_49 = F_63 ( V_3 ,
V_42 , V_86 ) ;
break;
default:
V_49 = - V_43 ;
break;
}
return V_49 ;
}
static int T_3 F_65 ( void )
{
V_85 = F_66 ( L_1 ) ;
if ( ! V_85 )
return - V_14 ;
return 0 ;
}
static void T_4 F_67 ( void )
{
F_68 ( V_85 ) ;
}
