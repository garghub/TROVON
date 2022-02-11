static int F_1 ( struct V_1 * V_2 , const void * V_3 )
{
return V_2 -> V_4 == V_3 ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_8 , NULL , V_7 ,
F_1 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
static struct V_5 * F_5 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
if ( ! F_6 ( & V_9 -> V_10 ) ) {
F_7 ( V_2 , L_1 , V_11 ) ;
return F_8 ( - V_12 ) ;
}
F_9 ( V_2 ) ;
F_10 ( V_2 -> V_4 ) ;
if ( ! F_11 ( V_2 -> V_13 -> V_14 -> V_15 ) ) {
F_12 ( V_2 -> V_4 ) ;
F_13 ( V_2 ) ;
F_14 ( & V_9 -> V_10 ) ;
return F_8 ( - V_16 ) ;
}
F_7 ( & V_9 -> V_2 , L_2 ) ;
return V_9 ;
}
static void F_15 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
F_7 ( & V_9 -> V_2 , L_3 ) ;
F_16 ( V_2 -> V_13 -> V_14 -> V_15 ) ;
F_12 ( V_2 -> V_4 ) ;
F_13 ( V_2 ) ;
F_14 ( & V_9 -> V_10 ) ;
}
static struct V_17 * F_17 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_4 ;
struct V_6 * V_18 ;
struct V_17 * V_19 ;
F_10 ( V_7 ) ;
while ( V_7 ) {
if ( F_18 ( V_7 , L_4 ) ) {
V_18 = F_19 ( V_7 , L_5 , 0 ) ;
if ( V_18 ) {
V_19 = F_20 ( V_18 ) ;
F_12 ( V_7 ) ;
return V_19 ;
}
}
V_7 = F_21 ( V_7 ) ;
}
F_12 ( V_7 ) ;
return F_8 ( - V_20 ) ;
}
static int F_22 ( struct V_5 * V_9 ,
struct V_6 * V_21 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_22 = V_2 -> V_4 ;
struct V_6 * V_23 , * V_7 , * V_24 = NULL ;
int V_25 , V_26 ;
V_26 = F_23 ( V_22 -> V_13 , V_9 -> V_27 ,
& V_9 -> V_28 ) ;
if ( V_26 == - V_12 )
return V_26 ;
if ( ! V_26 )
V_24 = V_22 -> V_13 ;
if ( F_19 ( V_21 , L_6 , 0 ) )
V_7 = V_21 ;
else
V_7 = V_22 ;
for ( V_25 = 0 ; ; V_25 ++ ) {
V_23 = F_19 ( V_7 , L_6 , V_25 ) ;
if ( ! V_23 )
break;
if ( V_23 == V_24 )
continue;
V_26 = F_23 ( V_23 , V_9 -> V_27 ,
& V_9 -> V_28 ) ;
if ( V_26 == - V_12 ) {
F_24 ( & V_9 -> V_28 ) ;
return - V_12 ;
}
}
return 0 ;
}
static int F_25 ( struct V_5 * V_9 ,
const char * V_29 ,
struct V_6 * V_21 )
{
struct V_17 * V_19 ;
int V_26 ;
V_9 = F_5 ( V_9 ) ;
if ( F_26 ( V_9 ) ) {
F_27 ( L_7 ) ;
return F_28 ( V_9 ) ;
}
V_19 = F_17 ( V_9 ) ;
if ( F_26 ( V_19 ) ) {
F_27 ( L_8 ) ;
V_26 = F_28 ( V_19 ) ;
goto V_30;
}
V_26 = F_22 ( V_9 , V_21 ) ;
if ( V_26 ) {
F_27 ( L_9 ) ;
goto V_31;
}
V_26 = F_29 ( & V_9 -> V_28 ) ;
if ( V_26 ) {
F_27 ( L_10 ) ;
goto V_32;
}
V_26 = F_30 ( V_19 , V_9 -> V_27 , V_29 ) ;
if ( V_26 ) {
F_27 ( L_11 ) ;
goto V_32;
}
V_26 = F_31 ( & V_9 -> V_28 ) ;
if ( V_26 ) {
F_27 ( L_12 ) ;
goto V_32;
}
F_32 ( V_19 ) ;
F_15 ( V_9 ) ;
return 0 ;
V_32:
F_24 ( & V_9 -> V_28 ) ;
V_31:
F_32 ( V_19 ) ;
V_30:
F_15 ( V_9 ) ;
return V_26 ;
}
static int F_33 ( struct V_6 * V_21 )
{
struct V_6 * V_33 ;
const char * V_34 ;
int V_26 = 0 ;
F_10 ( V_21 ) ;
V_33 = F_34 ( V_21 , V_35 ) ;
while ( V_33 ) {
if ( ! F_35 ( V_33 , L_13 ,
& V_34 ) ) {
V_26 = - V_20 ;
break;
}
V_33 = F_34 ( V_33 ,
V_35 ) ;
}
F_12 ( V_33 ) ;
if ( V_26 )
F_27 ( L_14 ,
V_33 ) ;
return V_26 ;
}
static int F_36 ( struct V_5 * V_9 ,
struct V_36 * V_37 )
{
const char * V_29 = NULL ;
struct V_38 * V_27 ;
int V_26 ;
V_27 = F_37 ( & V_9 -> V_2 , sizeof( * V_27 ) , V_39 ) ;
if ( ! V_27 )
return - V_40 ;
V_9 -> V_27 = V_27 ;
V_26 = F_33 ( V_37 -> V_21 ) ;
if ( V_26 )
return V_26 ;
if ( F_38 ( V_37 -> V_21 , L_15 ) )
V_27 -> V_41 |= V_42 ;
if ( F_38 ( V_37 -> V_21 , L_16 ) )
V_27 -> V_41 |= V_43 ;
if ( F_38 ( V_37 -> V_21 , L_17 ) )
V_27 -> V_41 |= V_44 ;
F_35 ( V_37 -> V_21 , L_13 , & V_29 ) ;
F_39 ( V_37 -> V_21 , L_18 ,
& V_27 -> V_45 ) ;
F_39 ( V_37 -> V_21 , L_19 ,
& V_27 -> V_46 ) ;
F_39 ( V_37 -> V_21 , L_20 ,
& V_27 -> V_47 ) ;
if ( ( V_27 -> V_41 & V_43 ) && V_29 ) {
F_27 ( L_21 ) ;
return - V_20 ;
}
if ( V_27 -> V_41 & V_43 )
return 0 ;
if ( ! V_29 ) {
F_27 ( L_22 ) ;
return - V_20 ;
}
return F_25 ( V_9 , V_29 , V_37 -> V_21 ) ;
}
static void F_40 ( struct V_5 * V_9 ,
struct V_36 * V_37 )
{
F_29 ( & V_9 -> V_28 ) ;
F_24 ( & V_9 -> V_28 ) ;
F_41 ( & V_9 -> V_2 , V_9 -> V_27 ) ;
V_9 -> V_27 = NULL ;
}
static int F_42 ( struct V_48 * V_49 ,
unsigned long V_50 , void * V_51 )
{
struct V_36 * V_37 = V_51 ;
struct V_5 * V_9 ;
int V_26 ;
switch ( V_50 ) {
case V_52 :
F_43 ( L_23 , V_11 ) ;
break;
case V_53 :
F_43 ( L_24 , V_11 ) ;
return V_54 ;
case V_55 :
F_43 ( L_25 , V_11 ) ;
return V_54 ;
case V_56 :
F_43 ( L_26 , V_11 ) ;
break;
default:
return V_54 ;
}
V_9 = F_2 ( V_37 -> V_57 ) ;
if ( ! V_9 )
return V_54 ;
V_26 = 0 ;
switch ( V_50 ) {
case V_52 :
V_26 = F_36 ( V_9 , V_37 ) ;
break;
case V_56 :
F_40 ( V_9 , V_37 ) ;
break;
}
F_13 ( & V_9 -> V_2 ) ;
if ( V_26 )
return F_44 ( V_26 ) ;
return V_54 ;
}
static int F_45 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_59 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_4 ;
struct V_5 * V_9 ;
int V_60 , V_26 = 0 ;
V_9 = F_46 ( sizeof( * V_9 ) , V_39 ) ;
if ( ! V_9 )
return - V_40 ;
V_60 = F_47 ( & V_61 , 0 , 0 , V_39 ) ;
if ( V_60 < 0 ) {
V_26 = V_60 ;
goto V_62;
}
F_48 ( & V_9 -> V_10 ) ;
F_49 ( & V_9 -> V_28 ) ;
F_50 ( & V_9 -> V_2 ) ;
V_9 -> V_2 . V_63 = V_8 ;
V_9 -> V_2 . V_13 = V_2 ;
V_9 -> V_2 . V_4 = V_7 ;
V_9 -> V_2 . V_60 = V_60 ;
F_51 ( V_2 , V_9 ) ;
V_26 = F_52 ( & V_9 -> V_2 , L_27 , V_60 ) ;
if ( V_26 )
goto V_64;
V_26 = F_53 ( & V_9 -> V_2 ) ;
if ( V_26 )
goto V_64;
F_54 ( V_7 , V_35 , NULL , & V_9 -> V_2 ) ;
F_55 ( V_2 , L_28 ) ;
return 0 ;
V_64:
F_56 ( & V_61 , V_60 ) ;
V_62:
F_57 ( V_9 ) ;
return V_26 ;
}
static int F_58 ( struct V_58 * V_59 )
{
struct V_5 * V_9 = F_59 ( V_59 ) ;
F_60 ( & V_9 -> V_2 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_9 = F_4 ( V_2 ) ;
F_56 ( & V_61 , V_9 -> V_2 . V_60 ) ;
F_57 ( V_9 ) ;
}
static int T_1 F_62 ( void )
{
int V_26 ;
V_8 = F_63 ( V_65 , L_29 ) ;
if ( F_26 ( V_8 ) )
return F_28 ( V_8 ) ;
V_8 -> V_66 = F_61 ;
V_26 = F_64 ( & V_67 ) ;
if ( V_26 )
goto V_68;
V_26 = F_65 ( & V_69 ) ;
if ( V_26 )
goto V_70;
return 0 ;
V_70:
F_66 ( & V_67 ) ;
V_68:
F_67 ( V_8 ) ;
F_68 ( & V_61 ) ;
return V_26 ;
}
static void T_2 F_69 ( void )
{
F_70 ( & V_69 ) ;
F_66 ( & V_67 ) ;
F_67 ( V_8 ) ;
F_68 ( & V_61 ) ;
}
