static int F_1 ( void * V_1 )
{
F_2 () ;
return 0 ;
}
static int F_3 ( void * V_1 )
{
F_2 () ;
return F_4 ( V_2 ) ? - V_3 : 0 ;
}
void F_5 ( struct V_4 * V_5 , int error )
{
F_6 ( L_1 , V_5 -> V_6 -> V_7 , V_5 -> V_8 -> V_7 , error ) ;
if ( error < 0 )
F_7 ( V_5 -> V_6 , V_9 , NULL ,
V_5 -> V_8 ) ;
else
F_8 ( V_5 -> V_8 ) ;
F_9 ( V_5 -> V_6 ) ;
F_9 ( V_5 -> V_8 ) ;
F_10 ( V_5 ) ;
}
static int F_11 ( struct V_10 * V_11 , struct V_12 * V_12 )
{
struct V_6 * V_13 = V_11 -> V_14 ;
return F_12 ( V_12 , V_13 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_6 * V_13 = V_11 -> V_14 ;
F_9 ( V_13 ) ;
}
static int F_14 ( char * V_15 , char * * V_16 , char * * V_17 ,
struct V_6 * V_18 , enum V_19 V_20 )
{
T_1 V_21 = ( V_20 == V_22 ) ? V_23 : V_24 ;
struct V_10 * V_11 =
F_15 ( V_15 , V_16 , V_17 , V_21 ) ;
if ( ! V_11 )
return - V_25 ;
F_16 ( V_11 , F_11 , F_13 ,
F_17 ( V_18 ) ) ;
return F_18 ( V_11 , V_20 ) ;
}
static int F_19 ( struct V_4 * V_5 ,
const char * V_26 ,
void * V_27 )
{
const struct V_12 * V_12 = F_20 () ;
T_2 V_28 , V_29 ;
struct V_6 * V_6 = V_5 -> V_6 , * V_8 = V_5 -> V_8 , * V_13 ,
* V_30 ;
char * V_16 [ 9 ] , * V_17 [ 3 ] , V_31 [ 12 ] , V_32 [ 12 ] ;
char V_33 [ 12 ] , V_34 [ 3 ] [ 12 ] ;
char V_35 [ 20 ] ;
int V_36 , V_37 ;
F_6 ( L_2 , V_6 -> V_7 , V_8 -> V_7 , V_26 ) ;
V_36 = F_21 () ;
if ( V_36 < 0 )
goto V_38;
sprintf ( V_35 , L_3 , V_6 -> V_7 ) ;
V_12 = F_22 () ;
V_13 = F_23 ( V_35 , V_12 -> V_39 , V_12 -> V_40 , V_12 ,
V_41 , NULL ) ;
F_24 ( V_12 ) ;
if ( F_25 ( V_13 ) ) {
V_36 = F_26 ( V_13 ) ;
goto V_38;
}
V_36 = F_27 ( V_13 , V_8 ) ;
if ( V_36 < 0 )
goto V_42;
sprintf ( V_31 , L_4 , V_12 -> V_39 ) ;
sprintf ( V_32 , L_4 , V_12 -> V_40 ) ;
sprintf ( V_33 , L_4 , V_6 -> V_7 ) ;
sprintf ( V_34 [ 0 ] , L_4 ,
V_12 -> V_43 ? V_12 -> V_43 -> V_7 : 0 ) ;
V_28 = 0 ;
if ( V_12 -> V_44 -> V_45 )
V_28 = V_12 -> V_44 -> V_45 -> V_7 ;
sprintf ( V_34 [ 1 ] , L_4 , V_28 ) ;
F_28 () ;
V_30 = F_29 ( V_12 -> V_44 -> V_18 ) ;
if ( ! V_30 )
V_30 = V_12 -> V_46 -> V_18 ;
V_29 = V_30 -> V_7 ;
F_30 () ;
sprintf ( V_34 [ 2 ] , L_4 , V_29 ) ;
V_37 = 0 ;
V_17 [ V_37 ++ ] = L_5 ;
V_17 [ V_37 ++ ] = L_6 ;
V_17 [ V_37 ] = NULL ;
V_37 = 0 ;
V_16 [ V_37 ++ ] = L_7 ;
V_16 [ V_37 ++ ] = ( char * ) V_26 ;
V_16 [ V_37 ++ ] = V_33 ;
V_16 [ V_37 ++ ] = V_31 ;
V_16 [ V_37 ++ ] = V_32 ;
V_16 [ V_37 ++ ] = V_34 [ 0 ] ;
V_16 [ V_37 ++ ] = V_34 [ 1 ] ;
V_16 [ V_37 ++ ] = V_34 [ 2 ] ;
V_16 [ V_37 ] = NULL ;
V_36 = F_14 ( V_16 [ 0 ] , V_16 , V_17 , V_13 ,
V_47 ) ;
F_31 ( L_8 , V_36 ) ;
if ( V_36 >= 0 ) {
if ( F_32 ( V_48 , & V_6 -> V_1 ) ||
F_33 ( V_6 ) < 0 )
V_36 = - V_49 ;
else
V_36 = 0 ;
}
V_42:
F_9 ( V_13 ) ;
V_38:
F_5 ( V_5 , V_36 ) ;
F_34 ( L_9 , V_36 ) ;
return V_36 ;
}
static int F_35 ( struct V_6 * V_6 , const void * V_50 ,
T_3 V_51 , void * V_27 ,
struct V_6 * V_52 )
{
struct V_4 * V_5 ;
T_4 V_53 ;
struct V_6 * V_8 ;
int V_36 ;
F_6 ( L_10 , V_6 -> V_7 , V_50 , V_51 , V_27 ) ;
V_5 = F_36 ( sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
V_8 = F_37 ( V_6 , V_50 , V_51 ,
V_52 ) ;
if ( F_25 ( V_8 ) ) {
F_10 ( V_5 ) ;
V_36 = F_26 ( V_8 ) ;
V_8 = NULL ;
} else {
V_5 -> V_8 = F_17 ( V_8 ) ;
V_5 -> V_6 = F_17 ( V_6 ) ;
V_53 = F_19 ;
if ( V_6 -> type -> V_54 )
V_53 = V_6 -> type -> V_54 ;
V_36 = V_53 ( V_5 , L_11 , V_27 ) ;
F_38 ( V_36 < 0 &&
! F_32 ( V_55 , & V_8 -> V_1 ) ) ;
F_9 ( V_8 ) ;
}
F_34 ( L_9 , V_36 ) ;
return V_36 ;
}
static void F_39 ( struct V_6 * * V_56 )
{
struct V_57 * V_58 ;
const struct V_12 * V_12 = F_20 () ;
struct V_6 * V_52 = * V_56 , * V_8 ;
F_6 ( L_12 , V_52 ) ;
if ( V_52 ) {
F_17 ( V_52 ) ;
} else {
switch ( V_12 -> V_59 ) {
case V_60 :
case V_61 :
if ( V_12 -> V_57 ) {
V_8 = V_12 -> V_57 ;
F_40 ( & V_8 -> V_62 ) ;
V_58 = V_8 -> V_63 . V_14 ;
if ( ! F_32 ( V_55 ,
& V_8 -> V_1 ) )
V_52 =
F_17 ( V_58 -> V_52 ) ;
F_41 ( & V_8 -> V_62 ) ;
if ( V_52 )
break;
}
case V_64 :
V_52 = F_17 ( V_12 -> V_43 ) ;
if ( V_52 )
break;
case V_65 :
V_52 = F_17 ( V_12 -> V_44 -> V_45 ) ;
if ( V_52 )
break;
case V_66 :
F_28 () ;
V_52 = F_17 (
F_29 ( V_12 -> V_44 -> V_18 ) ) ;
F_30 () ;
if ( V_52 )
break;
case V_67 :
V_52 =
F_17 ( V_12 -> V_46 -> V_18 ) ;
break;
case V_68 :
V_52 = F_17 ( V_12 -> V_46 -> V_69 ) ;
break;
case V_70 :
default:
F_42 () ;
}
}
* V_56 = V_52 ;
F_34 ( L_13 , F_43 ( V_52 ) ) ;
return;
}
static int F_44 ( struct V_71 * type ,
const char * V_72 ,
struct V_6 * V_52 ,
unsigned long V_1 ,
struct V_73 * V_46 ,
struct V_6 * * V_74 )
{
const struct V_12 * V_12 = F_20 () ;
unsigned long V_75 ;
struct V_6 * V_6 ;
T_5 V_76 ;
int V_36 ;
F_6 ( L_14 , type -> V_77 , V_72 ) ;
* V_74 = NULL ;
F_45 ( & V_46 -> V_78 ) ;
V_6 = F_46 ( type , V_72 , V_12 -> V_39 , V_12 -> V_40 , V_12 ,
V_79 , V_1 ) ;
if ( F_25 ( V_6 ) )
goto V_80;
F_47 ( V_48 , & V_6 -> V_1 ) ;
if ( V_52 ) {
V_36 = F_48 ( V_52 , type , V_72 ,
& V_75 ) ;
if ( V_36 < 0 )
goto V_81;
}
F_45 ( & V_82 ) ;
V_76 = F_49 ( type , V_72 , type -> V_83 , V_12 ) ;
if ( ! F_25 ( V_76 ) )
goto V_84;
if ( V_52 )
F_50 ( V_52 , V_6 , & V_75 ) ;
F_51 ( & V_82 ) ;
if ( V_52 )
F_52 ( V_52 , type , V_75 ) ;
F_51 ( & V_46 -> V_78 ) ;
* V_74 = V_6 ;
F_34 ( L_15 , F_43 ( V_6 ) ) ;
return 0 ;
V_84:
F_9 ( V_6 ) ;
F_51 ( & V_82 ) ;
V_6 = F_53 ( V_76 ) ;
if ( V_52 ) {
V_36 = F_54 ( V_52 , V_6 ) ;
if ( V_36 == 0 )
F_50 ( V_52 , V_6 , & V_75 ) ;
F_52 ( V_52 , type , V_75 ) ;
if ( V_36 < 0 )
goto V_85;
}
F_51 ( & V_46 -> V_78 ) ;
* V_74 = V_6 ;
F_34 ( L_16 , F_43 ( V_6 ) ) ;
return - V_86 ;
V_85:
F_51 ( & V_46 -> V_78 ) ;
F_9 ( V_6 ) ;
F_34 ( L_17 , V_36 ) ;
return V_36 ;
V_81:
F_51 ( & V_46 -> V_78 ) ;
F_34 ( L_18 , V_36 ) ;
return V_36 ;
V_80:
F_51 ( & V_46 -> V_78 ) ;
F_34 ( L_19 , F_26 ( V_6 ) ) ;
return F_26 ( V_6 ) ;
}
static struct V_6 * F_55 ( struct V_71 * type ,
const char * V_72 ,
const char * V_50 ,
T_3 V_51 ,
void * V_27 ,
struct V_6 * V_52 ,
unsigned long V_1 )
{
struct V_73 * V_46 ;
struct V_6 * V_6 ;
int V_36 ;
F_6 ( L_20 ) ;
V_46 = F_56 ( F_57 () , F_58 () ) ;
if ( ! V_46 )
return F_59 ( - V_25 ) ;
F_39 ( & V_52 ) ;
V_36 = F_44 ( type , V_72 , V_52 , V_1 , V_46 ,
& V_6 ) ;
F_60 ( V_46 ) ;
if ( V_36 == 0 ) {
V_36 = F_35 ( V_6 , V_50 , V_51 , V_27 ,
V_52 ) ;
if ( V_36 < 0 ) {
F_31 ( L_21 ) ;
goto V_87;
}
} else if ( V_36 == - V_86 ) {
V_36 = 0 ;
} else {
goto V_88;
}
F_9 ( V_52 ) ;
F_34 ( L_22 , F_43 ( V_6 ) ) ;
return V_6 ;
V_87:
F_7 ( V_6 , V_9 , NULL , NULL ) ;
F_9 ( V_6 ) ;
V_88:
F_9 ( V_52 ) ;
F_34 ( L_9 , V_36 ) ;
return F_59 ( V_36 ) ;
}
struct V_6 * F_61 ( struct V_71 * type ,
const char * V_72 ,
const void * V_50 ,
T_3 V_51 ,
void * V_27 ,
struct V_6 * V_52 ,
unsigned long V_1 )
{
const struct V_12 * V_12 = F_20 () ;
struct V_6 * V_6 ;
T_5 V_76 ;
int V_36 ;
F_6 ( L_23 ,
type -> V_77 , V_72 , V_50 , V_51 , V_27 ,
V_52 , V_1 ) ;
V_76 = F_49 ( type , V_72 , type -> V_83 , V_12 ) ;
if ( ! F_25 ( V_76 ) ) {
V_6 = F_53 ( V_76 ) ;
if ( V_52 ) {
F_39 ( & V_52 ) ;
V_36 = F_27 ( V_52 , V_6 ) ;
F_9 ( V_52 ) ;
if ( V_36 < 0 ) {
F_9 ( V_6 ) ;
V_6 = F_59 ( V_36 ) ;
goto error;
}
}
} else if ( F_26 ( V_76 ) != - V_89 ) {
V_6 = F_62 ( V_76 ) ;
} else {
V_6 = F_59 ( - V_49 ) ;
if ( ! V_50 )
goto error;
V_6 = F_55 ( type , V_72 , V_50 ,
V_51 , V_27 , V_52 ,
V_1 ) ;
}
error:
F_34 ( L_24 , V_6 ) ;
return V_6 ;
}
int F_63 ( struct V_6 * V_6 , bool V_90 )
{
int V_36 ;
V_36 = F_64 ( & V_6 -> V_1 , V_48 ,
V_90 ? F_3 : F_1 ,
V_90 ? V_91 : V_92 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( F_32 ( V_93 , & V_6 -> V_1 ) )
return V_6 -> V_94 . V_95 ;
return F_33 ( V_6 ) ;
}
struct V_6 * V_54 ( struct V_71 * type ,
const char * V_72 ,
const char * V_50 )
{
struct V_6 * V_6 ;
T_3 V_51 = 0 ;
int V_36 ;
if ( V_50 )
V_51 = strlen ( V_50 ) ;
V_6 = F_61 ( type , V_72 , V_50 , V_51 ,
NULL , NULL , V_96 ) ;
if ( ! F_25 ( V_6 ) ) {
V_36 = F_63 ( V_6 , false ) ;
if ( V_36 < 0 ) {
F_9 ( V_6 ) ;
return F_59 ( V_36 ) ;
}
}
return V_6 ;
}
struct V_6 * F_65 ( struct V_71 * type ,
const char * V_72 ,
const void * V_50 ,
T_3 V_51 ,
void * V_27 )
{
struct V_6 * V_6 ;
int V_36 ;
V_6 = F_61 ( type , V_72 , V_50 , V_51 ,
V_27 , NULL , V_96 ) ;
if ( ! F_25 ( V_6 ) ) {
V_36 = F_63 ( V_6 , false ) ;
if ( V_36 < 0 ) {
F_9 ( V_6 ) ;
return F_59 ( V_36 ) ;
}
}
return V_6 ;
}
struct V_6 * F_66 ( struct V_71 * type ,
const char * V_72 ,
const void * V_50 ,
T_3 V_51 )
{
return F_61 ( type , V_72 , V_50 ,
V_51 , NULL , NULL ,
V_96 ) ;
}
struct V_6 * F_67 ( struct V_71 * type ,
const char * V_72 ,
const void * V_50 ,
T_3 V_51 ,
void * V_27 )
{
return F_61 ( type , V_72 , V_50 ,
V_51 , V_27 , NULL , V_96 ) ;
}
