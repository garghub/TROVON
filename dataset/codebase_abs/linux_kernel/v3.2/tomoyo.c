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
#ifndef F_9
if ( ! V_13 )
F_10 ( V_10 -> V_14 ) ;
#endif
F_6 ( & ( (struct V_6 * )
V_10 -> V_1 -> V_4 ) -> V_8 ) ;
V_10 -> V_1 -> V_4 = NULL ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_1 -> V_4 ;
if ( ! V_7 ) {
const int V_15 = F_12 () ;
const int V_16 = F_13 ( V_10 ) ;
F_14 ( V_15 ) ;
return V_16 ;
}
return F_15 ( V_7 , & V_10 -> V_17 -> V_18 ,
V_19 ) ;
}
static int F_16 ( struct V_20 * V_21 , struct V_22 * V_22 )
{
struct V_23 V_23 = { V_21 , V_22 } ;
return F_17 ( V_24 , & V_23 , NULL ) ;
}
static int F_18 ( struct V_23 * V_23 )
{
return F_17 ( V_25 , V_23 , NULL ) ;
}
static int F_19 ( struct V_23 * V_26 , struct V_22 * V_22 )
{
struct V_23 V_23 = { V_26 -> V_21 , V_22 } ;
return F_17 ( V_27 , & V_23 , NULL ) ;
}
static int F_20 ( struct V_23 * V_26 , struct V_22 * V_22 ,
int V_28 )
{
struct V_23 V_23 = { V_26 -> V_21 , V_22 } ;
return F_21 ( V_29 , & V_23 ,
V_28 & V_30 ) ;
}
static int F_22 ( struct V_23 * V_26 , struct V_22 * V_22 )
{
struct V_23 V_23 = { V_26 -> V_21 , V_22 } ;
return F_17 ( V_31 , & V_23 , NULL ) ;
}
static int F_23 ( struct V_23 * V_26 , struct V_22 * V_22 ,
const char * V_32 )
{
struct V_23 V_23 = { V_26 -> V_21 , V_22 } ;
return F_17 ( V_33 , & V_23 , V_32 ) ;
}
static int F_24 ( struct V_23 * V_26 , struct V_22 * V_22 ,
int V_28 , unsigned int V_34 )
{
struct V_23 V_23 = { V_26 -> V_21 , V_22 } ;
int type = V_35 ;
const unsigned int V_36 = V_28 & V_30 ;
switch ( V_28 & V_37 ) {
case V_38 :
type = V_39 ;
break;
case V_40 :
type = V_41 ;
break;
default:
goto V_42;
}
return F_25 ( type , & V_23 , V_36 , V_34 ) ;
V_42:
switch ( V_28 & V_37 ) {
case V_43 :
type = V_44 ;
break;
case V_45 :
type = V_46 ;
break;
}
return F_21 ( type , & V_23 , V_36 ) ;
}
static int F_26 ( struct V_22 * V_47 , struct V_23 * V_48 ,
struct V_22 * V_49 )
{
struct V_23 V_50 = { V_48 -> V_21 , V_47 } ;
struct V_23 V_51 = { V_48 -> V_21 , V_49 } ;
return F_27 ( V_52 , & V_50 , & V_51 ) ;
}
static int F_28 ( struct V_23 * V_53 ,
struct V_22 * V_47 ,
struct V_23 * V_54 ,
struct V_22 * V_49 )
{
struct V_23 V_50 = { V_53 -> V_21 , V_47 } ;
struct V_23 V_51 = { V_54 -> V_21 , V_49 } ;
return F_27 ( V_55 , & V_50 , & V_51 ) ;
}
static int F_29 ( struct V_17 * V_17 , unsigned int V_56 ,
unsigned long V_57 )
{
if ( ! ( V_56 == V_58 && ( ( V_57 ^ V_17 -> V_59 ) & V_60 ) ) )
return 0 ;
return F_15 ( F_30 () , & V_17 -> V_18 ,
V_61 | ( V_57 & V_60 ) ) ;
}
static int F_31 ( struct V_17 * V_62 , const struct V_1 * V_1 )
{
int V_63 = V_62 -> V_59 ;
if ( V_64 -> V_65 )
return 0 ;
return F_15 ( F_30 () , & V_62 -> V_18 , V_63 ) ;
}
static int F_32 ( struct V_17 * V_17 , unsigned int V_56 ,
unsigned long V_57 )
{
return F_21 ( V_66 , & V_17 -> V_18 , V_56 ) ;
}
static int F_33 ( struct V_22 * V_22 , struct V_20 * V_21 ,
T_2 V_28 )
{
struct V_23 V_23 = { V_21 , V_22 } ;
return F_21 ( V_67 , & V_23 ,
V_28 & V_30 ) ;
}
static int F_34 ( struct V_23 * V_23 , T_3 V_68 , T_4 V_69 )
{
int error = 0 ;
if ( V_68 != ( T_3 ) - 1 )
error = F_21 ( V_70 , V_23 , V_68 ) ;
if ( ! error && V_69 != ( T_4 ) - 1 )
error = F_21 ( V_71 , V_23 , V_69 ) ;
return error ;
}
static int F_35 ( struct V_23 * V_23 )
{
return F_17 ( V_72 , V_23 , NULL ) ;
}
static int F_36 ( char * V_73 , struct V_23 * V_23 ,
char * type , unsigned long V_63 , void * V_74 )
{
return F_37 ( V_73 , V_23 , type , V_63 , V_74 ) ;
}
static int F_38 ( struct V_20 * V_21 , int V_63 )
{
struct V_23 V_23 = { V_21 , V_21 -> V_75 } ;
return F_17 ( V_76 , & V_23 , NULL ) ;
}
static int F_39 ( struct V_23 * V_77 , struct V_23 * V_78 )
{
return F_27 ( V_79 , V_78 , V_77 ) ;
}
static int F_40 ( struct V_80 * V_81 , int V_82 )
{
return F_41 ( V_81 ) ;
}
static int F_42 ( struct V_80 * V_81 , struct V_83 * V_84 ,
int V_85 )
{
return F_43 ( V_81 , V_84 , V_85 ) ;
}
static int F_44 ( struct V_80 * V_81 , struct V_83 * V_84 ,
int V_85 )
{
return F_45 ( V_81 , V_84 , V_85 ) ;
}
static int F_46 ( struct V_80 * V_81 , struct V_86 * V_87 ,
int V_88 )
{
return F_47 ( V_81 , V_87 , V_88 ) ;
}
static int T_5 F_48 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) F_49 () ;
if ( ! F_50 ( & V_89 ) )
return 0 ;
if ( F_51 ( & V_89 ) ||
F_52 ( & V_90 ) )
F_53 ( L_1 ) ;
F_54 ( V_91 L_2 ) ;
V_1 -> V_4 = & V_92 ;
F_55 () ;
return 0 ;
}
