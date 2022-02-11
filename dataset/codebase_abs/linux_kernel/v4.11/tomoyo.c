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
if ( V_10 -> V_11 )
return 0 ;
#ifndef F_8
if ( ! V_12 )
F_9 ( V_10 -> V_13 ) ;
#endif
F_6 ( & ( (struct V_6 * )
V_10 -> V_1 -> V_4 ) -> V_8 ) ;
V_10 -> V_1 -> V_4 = NULL ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_1 -> V_4 ;
if ( ! V_7 ) {
const int V_14 = F_11 () ;
const int V_15 = F_12 ( V_10 ) ;
F_13 ( V_14 ) ;
return V_15 ;
}
return F_14 ( V_7 , & V_10 -> V_16 -> V_17 ,
V_18 ) ;
}
static int F_15 ( const struct V_19 * V_19 )
{
return F_16 ( V_20 , V_19 , NULL ) ;
}
static int F_17 ( const struct V_19 * V_19 )
{
return F_16 ( V_21 , V_19 , NULL ) ;
}
static int F_18 ( const struct V_19 * V_22 , struct V_23 * V_23 )
{
struct V_19 V_19 = { V_22 -> V_24 , V_23 } ;
return F_16 ( V_25 , & V_19 , NULL ) ;
}
static int F_19 ( const struct V_19 * V_22 , struct V_23 * V_23 ,
T_2 V_26 )
{
struct V_19 V_19 = { V_22 -> V_24 , V_23 } ;
return F_20 ( V_27 , & V_19 ,
V_26 & V_28 ) ;
}
static int F_21 ( const struct V_19 * V_22 , struct V_23 * V_23 )
{
struct V_19 V_19 = { V_22 -> V_24 , V_23 } ;
return F_16 ( V_29 , & V_19 , NULL ) ;
}
static int F_22 ( const struct V_19 * V_22 , struct V_23 * V_23 ,
const char * V_30 )
{
struct V_19 V_19 = { V_22 -> V_24 , V_23 } ;
return F_16 ( V_31 , & V_19 , V_30 ) ;
}
static int F_23 ( const struct V_19 * V_22 , struct V_23 * V_23 ,
T_2 V_26 , unsigned int V_32 )
{
struct V_19 V_19 = { V_22 -> V_24 , V_23 } ;
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
return F_24 ( type , & V_19 , V_34 , V_32 ) ;
V_40:
switch ( V_26 & V_35 ) {
case V_41 :
type = V_42 ;
break;
case V_43 :
type = V_44 ;
break;
}
return F_20 ( type , & V_19 , V_34 ) ;
}
static int F_25 ( struct V_23 * V_45 , const struct V_19 * V_46 ,
struct V_23 * V_47 )
{
struct V_19 V_48 = { V_46 -> V_24 , V_45 } ;
struct V_19 V_49 = { V_46 -> V_24 , V_47 } ;
return F_26 ( V_50 , & V_48 , & V_49 ) ;
}
static int F_27 ( const struct V_19 * V_51 ,
struct V_23 * V_45 ,
const struct V_19 * V_52 ,
struct V_23 * V_47 )
{
struct V_19 V_48 = { V_51 -> V_24 , V_45 } ;
struct V_19 V_49 = { V_52 -> V_24 , V_47 } ;
return F_26 ( V_53 , & V_48 , & V_49 ) ;
}
static int F_28 ( struct V_16 * V_16 , unsigned int V_54 ,
unsigned long V_55 )
{
if ( ! ( V_54 == V_56 && ( ( V_55 ^ V_16 -> V_57 ) & V_58 ) ) )
return 0 ;
return F_14 ( F_29 () , & V_16 -> V_17 ,
V_59 | ( V_55 & V_58 ) ) ;
}
static int F_30 ( struct V_16 * V_60 , const struct V_1 * V_1 )
{
int V_61 = V_60 -> V_57 ;
if ( V_62 -> V_63 )
return 0 ;
return F_14 ( F_29 () , & V_60 -> V_17 , V_61 ) ;
}
static int F_31 ( struct V_16 * V_16 , unsigned int V_54 ,
unsigned long V_55 )
{
return F_20 ( V_64 , & V_16 -> V_17 , V_54 ) ;
}
static int F_32 ( const struct V_19 * V_19 , T_2 V_26 )
{
return F_20 ( V_65 , V_19 ,
V_26 & V_28 ) ;
}
static int F_33 ( const struct V_19 * V_19 , T_3 V_66 , T_4 V_67 )
{
int error = 0 ;
if ( F_34 ( V_66 ) )
error = F_20 ( V_68 , V_19 ,
F_35 ( & V_69 , V_66 ) ) ;
if ( ! error && F_36 ( V_67 ) )
error = F_20 ( V_70 , V_19 ,
F_37 ( & V_69 , V_67 ) ) ;
return error ;
}
static int F_38 ( const struct V_19 * V_19 )
{
return F_16 ( V_71 , V_19 , NULL ) ;
}
static int F_39 ( const char * V_72 , const struct V_19 * V_19 ,
const char * type , unsigned long V_61 , void * V_73 )
{
return F_40 ( V_72 , V_19 , type , V_61 , V_73 ) ;
}
static int F_41 ( struct V_74 * V_24 , int V_61 )
{
struct V_19 V_19 = { V_24 , V_24 -> V_75 } ;
return F_16 ( V_76 , & V_19 , NULL ) ;
}
static int F_42 ( const struct V_19 * V_77 , const struct V_19 * V_78 )
{
return F_26 ( V_79 , V_78 , V_77 ) ;
}
static int F_43 ( struct V_80 * V_81 , int V_82 )
{
return F_44 ( V_81 ) ;
}
static int F_45 ( struct V_80 * V_81 , struct V_83 * V_84 ,
int V_85 )
{
return F_46 ( V_81 , V_84 , V_85 ) ;
}
static int F_47 ( struct V_80 * V_81 , struct V_83 * V_84 ,
int V_85 )
{
return F_48 ( V_81 , V_84 , V_85 ) ;
}
static int F_49 ( struct V_80 * V_81 , struct V_86 * V_87 ,
int V_88 )
{
return F_50 ( V_81 , V_87 , V_88 ) ;
}
static int T_5 F_51 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) F_52 () ;
if ( ! F_53 ( L_1 ) )
return 0 ;
F_54 ( V_89 , F_55 ( V_89 ) , L_1 ) ;
F_56 ( V_90 L_2 ) ;
V_1 -> V_4 = & V_91 ;
F_57 () ;
return 0 ;
}
