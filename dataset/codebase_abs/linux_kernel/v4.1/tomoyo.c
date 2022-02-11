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
static int F_16 ( const struct V_20 * V_20 )
{
return F_17 ( V_21 , V_20 , NULL ) ;
}
static int F_18 ( struct V_20 * V_20 )
{
return F_17 ( V_22 , V_20 , NULL ) ;
}
static int F_19 ( struct V_20 * V_23 , struct V_24 * V_24 )
{
struct V_20 V_20 = { V_23 -> V_25 , V_24 } ;
return F_17 ( V_26 , & V_20 , NULL ) ;
}
static int F_20 ( struct V_20 * V_23 , struct V_24 * V_24 ,
T_2 V_27 )
{
struct V_20 V_20 = { V_23 -> V_25 , V_24 } ;
return F_21 ( V_28 , & V_20 ,
V_27 & V_29 ) ;
}
static int F_22 ( struct V_20 * V_23 , struct V_24 * V_24 )
{
struct V_20 V_20 = { V_23 -> V_25 , V_24 } ;
return F_17 ( V_30 , & V_20 , NULL ) ;
}
static int F_23 ( struct V_20 * V_23 , struct V_24 * V_24 ,
const char * V_31 )
{
struct V_20 V_20 = { V_23 -> V_25 , V_24 } ;
return F_17 ( V_32 , & V_20 , V_31 ) ;
}
static int F_24 ( struct V_20 * V_23 , struct V_24 * V_24 ,
T_2 V_27 , unsigned int V_33 )
{
struct V_20 V_20 = { V_23 -> V_25 , V_24 } ;
int type = V_34 ;
const unsigned int V_35 = V_27 & V_29 ;
switch ( V_27 & V_36 ) {
case V_37 :
type = V_38 ;
break;
case V_39 :
type = V_40 ;
break;
default:
goto V_41;
}
return F_25 ( type , & V_20 , V_35 , V_33 ) ;
V_41:
switch ( V_27 & V_36 ) {
case V_42 :
type = V_43 ;
break;
case V_44 :
type = V_45 ;
break;
}
return F_21 ( type , & V_20 , V_35 ) ;
}
static int F_26 ( struct V_24 * V_46 , struct V_20 * V_47 ,
struct V_24 * V_48 )
{
struct V_20 V_49 = { V_47 -> V_25 , V_46 } ;
struct V_20 V_50 = { V_47 -> V_25 , V_48 } ;
return F_27 ( V_51 , & V_49 , & V_50 ) ;
}
static int F_28 ( struct V_20 * V_52 ,
struct V_24 * V_46 ,
struct V_20 * V_53 ,
struct V_24 * V_48 )
{
struct V_20 V_49 = { V_52 -> V_25 , V_46 } ;
struct V_20 V_50 = { V_53 -> V_25 , V_48 } ;
return F_27 ( V_54 , & V_49 , & V_50 ) ;
}
static int F_29 ( struct V_17 * V_17 , unsigned int V_55 ,
unsigned long V_56 )
{
if ( ! ( V_55 == V_57 && ( ( V_56 ^ V_17 -> V_58 ) & V_59 ) ) )
return 0 ;
return F_15 ( F_30 () , & V_17 -> V_18 ,
V_60 | ( V_56 & V_59 ) ) ;
}
static int F_31 ( struct V_17 * V_61 , const struct V_1 * V_1 )
{
int V_62 = V_61 -> V_58 ;
if ( V_63 -> V_64 )
return 0 ;
return F_15 ( F_30 () , & V_61 -> V_18 , V_62 ) ;
}
static int F_32 ( struct V_17 * V_17 , unsigned int V_55 ,
unsigned long V_56 )
{
return F_21 ( V_65 , & V_17 -> V_18 , V_55 ) ;
}
static int F_33 ( struct V_20 * V_20 , T_2 V_27 )
{
return F_21 ( V_66 , V_20 ,
V_27 & V_29 ) ;
}
static int F_34 ( struct V_20 * V_20 , T_3 V_67 , T_4 V_68 )
{
int error = 0 ;
if ( F_35 ( V_67 ) )
error = F_21 ( V_69 , V_20 ,
F_36 ( & V_70 , V_67 ) ) ;
if ( ! error && F_37 ( V_68 ) )
error = F_21 ( V_71 , V_20 ,
F_38 ( & V_70 , V_68 ) ) ;
return error ;
}
static int F_39 ( struct V_20 * V_20 )
{
return F_17 ( V_72 , V_20 , NULL ) ;
}
static int F_40 ( const char * V_73 , struct V_20 * V_20 ,
const char * type , unsigned long V_62 , void * V_74 )
{
return F_41 ( V_73 , V_20 , type , V_62 , V_74 ) ;
}
static int F_42 ( struct V_75 * V_25 , int V_62 )
{
struct V_20 V_20 = { V_25 , V_25 -> V_76 } ;
return F_17 ( V_77 , & V_20 , NULL ) ;
}
static int F_43 ( struct V_20 * V_78 , struct V_20 * V_79 )
{
return F_27 ( V_80 , V_79 , V_78 ) ;
}
static int F_44 ( struct V_81 * V_82 , int V_83 )
{
return F_45 ( V_82 ) ;
}
static int F_46 ( struct V_81 * V_82 , struct V_84 * V_85 ,
int V_86 )
{
return F_47 ( V_82 , V_85 , V_86 ) ;
}
static int F_48 ( struct V_81 * V_82 , struct V_84 * V_85 ,
int V_86 )
{
return F_49 ( V_82 , V_85 , V_86 ) ;
}
static int F_50 ( struct V_81 * V_82 , struct V_87 * V_88 ,
int V_89 )
{
return F_51 ( V_82 , V_88 , V_89 ) ;
}
static int T_5 F_52 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) F_53 () ;
if ( ! F_54 ( & V_90 ) )
return 0 ;
if ( F_55 ( & V_90 ) )
F_56 ( L_1 ) ;
F_57 ( V_91 L_2 ) ;
V_1 -> V_4 = & V_92 ;
F_58 () ;
return 0 ;
}
