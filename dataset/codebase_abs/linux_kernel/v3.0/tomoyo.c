static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = NULL ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , const struct V_1 * V_5 ,
T_1 V_3 )
{
struct V_6 * V_7 = V_5 -> V_4 ;
V_2 -> V_4 = V_7 ;
if ( V_7 )
F_3 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_1 * V_5 )
{
F_2 ( V_2 , V_5 , 0 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = V_1 -> V_4 ;
if ( V_7 )
F_6 ( & V_7 -> V_8 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 )
return V_11 ;
if ( V_10 -> V_12 )
return 0 ;
if ( ! V_13 )
F_9 ( V_10 -> V_14 ) ;
F_6 ( & ( (struct V_6 * )
V_10 -> V_1 -> V_4 ) -> V_8 ) ;
V_10 -> V_1 -> V_4 = NULL ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_1 -> V_4 ;
if ( ! V_7 ) {
const int V_15 = F_11 () ;
const int V_16 = F_12 ( V_10 ) ;
F_13 ( V_15 ) ;
return V_16 ;
}
return F_14 ( V_7 , & V_10 -> V_17 -> V_18 , V_19 ) ;
}
static int F_15 ( struct V_20 * V_20 )
{
return F_16 ( V_21 , V_20 ) ;
}
static int F_17 ( struct V_20 * V_22 , struct V_23 * V_23 )
{
struct V_20 V_20 = { V_22 -> V_24 , V_23 } ;
return F_16 ( V_25 , & V_20 ) ;
}
static int F_18 ( struct V_20 * V_22 , struct V_23 * V_23 ,
int V_26 )
{
struct V_20 V_20 = { V_22 -> V_24 , V_23 } ;
return F_19 ( V_27 , & V_20 ,
V_26 & V_28 ) ;
}
static int F_20 ( struct V_20 * V_22 , struct V_23 * V_23 )
{
struct V_20 V_20 = { V_22 -> V_24 , V_23 } ;
return F_16 ( V_29 , & V_20 ) ;
}
static int F_21 ( struct V_20 * V_22 , struct V_23 * V_23 ,
const char * V_30 )
{
struct V_20 V_20 = { V_22 -> V_24 , V_23 } ;
return F_16 ( V_31 , & V_20 ) ;
}
static int F_22 ( struct V_20 * V_22 , struct V_23 * V_23 ,
int V_26 , unsigned int V_32 )
{
struct V_20 V_20 = { V_22 -> V_24 , V_23 } ;
int type = V_33 ;
const unsigned int V_34 = V_26 & V_28 ;
switch ( V_26 & V_35 ) {
case V_36 :
type = V_37 ;
break;
case V_38 :
type = V_39 ;
break;
default:
goto V_40;
}
return F_23 ( type , & V_20 , V_34 , V_32 ) ;
V_40:
switch ( V_26 & V_35 ) {
case V_41 :
type = V_42 ;
break;
case V_43 :
type = V_44 ;
break;
}
return F_19 ( type , & V_20 , V_34 ) ;
}
static int F_24 ( struct V_23 * V_45 , struct V_20 * V_46 ,
struct V_23 * V_47 )
{
struct V_20 V_48 = { V_46 -> V_24 , V_45 } ;
struct V_20 V_49 = { V_46 -> V_24 , V_47 } ;
return F_25 ( V_50 , & V_48 , & V_49 ) ;
}
static int F_26 ( struct V_20 * V_51 ,
struct V_23 * V_45 ,
struct V_20 * V_52 ,
struct V_23 * V_47 )
{
struct V_20 V_48 = { V_51 -> V_24 , V_45 } ;
struct V_20 V_49 = { V_52 -> V_24 , V_47 } ;
return F_25 ( V_53 , & V_48 , & V_49 ) ;
}
static int F_27 ( struct V_17 * V_17 , unsigned int V_54 ,
unsigned long V_55 )
{
if ( V_54 == V_56 && ( ( V_55 ^ V_17 -> V_57 ) & V_58 ) )
return F_16 ( V_59 , & V_17 -> V_18 ) ;
return 0 ;
}
static int F_28 ( struct V_17 * V_60 , const struct V_1 * V_1 )
{
int V_61 = V_60 -> V_57 ;
if ( V_62 -> V_63 )
return 0 ;
return F_14 ( F_29 () , & V_60 -> V_18 , V_61 ) ;
}
static int F_30 ( struct V_17 * V_17 , unsigned int V_54 ,
unsigned long V_55 )
{
return F_19 ( V_64 , & V_17 -> V_18 , V_54 ) ;
}
static int F_31 ( struct V_23 * V_23 , struct V_65 * V_24 ,
T_2 V_26 )
{
struct V_20 V_20 = { V_24 , V_23 } ;
return F_19 ( V_66 , & V_20 ,
V_26 & V_28 ) ;
}
static int F_32 ( struct V_20 * V_20 , T_3 V_67 , T_4 V_68 )
{
int error = 0 ;
if ( V_67 != ( T_3 ) - 1 )
error = F_19 ( V_69 , V_20 , V_67 ) ;
if ( ! error && V_68 != ( T_4 ) - 1 )
error = F_19 ( V_70 , V_20 , V_68 ) ;
return error ;
}
static int F_33 ( struct V_20 * V_20 )
{
return F_16 ( V_71 , V_20 ) ;
}
static int F_34 ( char * V_72 , struct V_20 * V_20 ,
char * type , unsigned long V_61 , void * V_73 )
{
return F_35 ( V_72 , V_20 , type , V_61 , V_73 ) ;
}
static int F_36 ( struct V_65 * V_24 , int V_61 )
{
struct V_20 V_20 = { V_24 , V_24 -> V_74 } ;
return F_16 ( V_75 , & V_20 ) ;
}
static int F_37 ( struct V_20 * V_76 , struct V_20 * V_77 )
{
return F_25 ( V_78 , V_77 , V_76 ) ;
}
static int T_5 F_38 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) F_39 () ;
if ( ! F_40 ( & V_79 ) )
return 0 ;
if ( F_41 ( & V_79 ) ||
F_42 ( & V_80 ) )
F_43 ( L_1 ) ;
F_44 ( V_81 L_2 ) ;
V_1 -> V_4 = & V_82 ;
F_45 () ;
return 0 ;
}
