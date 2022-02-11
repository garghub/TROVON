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
struct V_6 * V_18 , int V_19 )
{
T_1 V_20 = ( V_19 == V_21 ) ? V_22 : V_23 ;
struct V_10 * V_11 =
F_15 ( V_15 , V_16 , V_17 , V_20 ) ;
if ( ! V_11 )
return - V_24 ;
F_16 ( V_11 , F_11 , F_13 ,
F_17 ( V_18 ) ) ;
return F_18 ( V_11 , V_19 ) ;
}
static int F_19 ( struct V_4 * V_5 ,
const char * V_25 ,
void * V_26 )
{
const struct V_12 * V_12 = F_20 () ;
T_2 V_27 , V_28 ;
struct V_6 * V_6 = V_5 -> V_6 , * V_8 = V_5 -> V_8 , * V_13 ,
* V_29 ;
char * V_16 [ 9 ] , * V_17 [ 3 ] , V_30 [ 12 ] , V_31 [ 12 ] ;
char V_32 [ 12 ] , V_33 [ 3 ] [ 12 ] ;
char V_34 [ 20 ] ;
int V_35 , V_36 ;
F_6 ( L_2 , V_6 -> V_7 , V_8 -> V_7 , V_25 ) ;
V_35 = F_21 () ;
if ( V_35 < 0 )
goto V_37;
sprintf ( V_34 , L_3 , V_6 -> V_7 ) ;
V_12 = F_22 () ;
V_13 = F_23 ( V_34 , V_12 -> V_38 , V_12 -> V_39 , V_12 ,
V_40 , NULL ) ;
F_24 ( V_12 ) ;
if ( F_25 ( V_13 ) ) {
V_35 = F_26 ( V_13 ) ;
goto V_37;
}
V_35 = F_27 ( V_13 , V_8 ) ;
if ( V_35 < 0 )
goto V_41;
sprintf ( V_30 , L_4 , V_12 -> V_38 ) ;
sprintf ( V_31 , L_4 , V_12 -> V_39 ) ;
sprintf ( V_32 , L_4 , V_6 -> V_7 ) ;
sprintf ( V_33 [ 0 ] , L_4 ,
V_12 -> V_42 ? V_12 -> V_42 -> V_7 : 0 ) ;
V_27 = 0 ;
if ( V_12 -> V_43 -> V_44 )
V_27 = V_12 -> V_43 -> V_44 -> V_7 ;
sprintf ( V_33 [ 1 ] , L_4 , V_27 ) ;
F_28 () ;
V_29 = F_29 ( V_12 -> V_43 -> V_18 ) ;
if ( ! V_29 )
V_29 = V_12 -> V_45 -> V_18 ;
V_28 = V_29 -> V_7 ;
F_30 () ;
sprintf ( V_33 [ 2 ] , L_4 , V_28 ) ;
V_36 = 0 ;
V_17 [ V_36 ++ ] = L_5 ;
V_17 [ V_36 ++ ] = L_6 ;
V_17 [ V_36 ] = NULL ;
V_36 = 0 ;
V_16 [ V_36 ++ ] = L_7 ;
V_16 [ V_36 ++ ] = ( char * ) V_25 ;
V_16 [ V_36 ++ ] = V_32 ;
V_16 [ V_36 ++ ] = V_30 ;
V_16 [ V_36 ++ ] = V_31 ;
V_16 [ V_36 ++ ] = V_33 [ 0 ] ;
V_16 [ V_36 ++ ] = V_33 [ 1 ] ;
V_16 [ V_36 ++ ] = V_33 [ 2 ] ;
V_16 [ V_36 ] = NULL ;
V_35 = F_14 ( V_16 [ 0 ] , V_16 , V_17 , V_13 ,
V_46 ) ;
F_31 ( L_8 , V_35 ) ;
if ( V_35 >= 0 ) {
if ( F_32 ( V_47 , & V_6 -> V_1 ) ||
F_33 ( V_6 ) < 0 )
V_35 = - V_48 ;
else
V_35 = 0 ;
}
V_41:
F_9 ( V_13 ) ;
V_37:
F_5 ( V_5 , V_35 ) ;
F_34 ( L_9 , V_35 ) ;
return V_35 ;
}
static int F_35 ( struct V_6 * V_6 , const void * V_49 ,
T_3 V_50 , void * V_26 ,
struct V_6 * V_51 )
{
struct V_4 * V_5 ;
T_4 V_52 ;
struct V_6 * V_8 ;
int V_35 ;
F_6 ( L_10 , V_6 -> V_7 , V_49 , V_50 , V_26 ) ;
V_5 = F_36 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return - V_24 ;
V_8 = F_37 ( V_6 , V_49 , V_50 ,
V_51 ) ;
if ( F_25 ( V_8 ) ) {
F_10 ( V_5 ) ;
V_35 = F_26 ( V_8 ) ;
V_8 = NULL ;
} else {
V_5 -> V_8 = F_17 ( V_8 ) ;
V_5 -> V_6 = F_17 ( V_6 ) ;
V_52 = F_19 ;
if ( V_6 -> type -> V_53 )
V_52 = V_6 -> type -> V_53 ;
V_35 = V_52 ( V_5 , L_11 , V_26 ) ;
F_38 ( V_35 < 0 &&
! F_32 ( V_54 , & V_8 -> V_1 ) ) ;
F_9 ( V_8 ) ;
}
F_34 ( L_9 , V_35 ) ;
return V_35 ;
}
static void F_39 ( struct V_6 * * V_55 )
{
struct V_56 * V_57 ;
const struct V_12 * V_12 = F_20 () ;
struct V_6 * V_51 = * V_55 , * V_8 ;
F_6 ( L_12 , V_51 ) ;
if ( V_51 ) {
F_17 ( V_51 ) ;
} else {
switch ( V_12 -> V_58 ) {
case V_59 :
case V_60 :
if ( V_12 -> V_56 ) {
V_8 = V_12 -> V_56 ;
F_40 ( & V_8 -> V_61 ) ;
V_57 = V_8 -> V_62 . V_14 ;
if ( ! F_32 ( V_54 ,
& V_8 -> V_1 ) )
V_51 =
F_17 ( V_57 -> V_51 ) ;
F_41 ( & V_8 -> V_61 ) ;
if ( V_51 )
break;
}
case V_63 :
V_51 = F_17 ( V_12 -> V_42 ) ;
if ( V_51 )
break;
case V_64 :
V_51 = F_17 ( V_12 -> V_43 -> V_44 ) ;
if ( V_51 )
break;
case V_65 :
F_28 () ;
V_51 = F_17 (
F_29 ( V_12 -> V_43 -> V_18 ) ) ;
F_30 () ;
if ( V_51 )
break;
case V_66 :
V_51 =
F_17 ( V_12 -> V_45 -> V_18 ) ;
break;
case V_67 :
V_51 = F_17 ( V_12 -> V_45 -> V_68 ) ;
break;
case V_69 :
default:
F_42 () ;
}
}
* V_55 = V_51 ;
F_34 ( L_13 , F_43 ( V_51 ) ) ;
return;
}
static int F_44 ( struct V_70 * type ,
const char * V_71 ,
struct V_6 * V_51 ,
unsigned long V_1 ,
struct V_72 * V_45 ,
struct V_6 * * V_73 )
{
const struct V_12 * V_12 = F_20 () ;
unsigned long V_74 ;
struct V_6 * V_6 ;
T_5 V_75 ;
int V_35 ;
F_6 ( L_14 , type -> V_76 , V_71 ) ;
* V_73 = NULL ;
F_45 ( & V_45 -> V_77 ) ;
V_6 = F_46 ( type , V_71 , V_12 -> V_38 , V_12 -> V_39 , V_12 ,
V_78 , V_1 ) ;
if ( F_25 ( V_6 ) )
goto V_79;
F_47 ( V_47 , & V_6 -> V_1 ) ;
if ( V_51 ) {
V_35 = F_48 ( V_51 , type , V_71 ,
& V_74 ) ;
if ( V_35 < 0 )
goto V_80;
}
F_45 ( & V_81 ) ;
V_75 = F_49 ( type , V_71 , type -> V_82 , V_12 ) ;
if ( ! F_25 ( V_75 ) )
goto V_83;
if ( V_51 )
F_50 ( V_51 , V_6 , & V_74 ) ;
F_51 ( & V_81 ) ;
if ( V_51 )
F_52 ( V_51 , type , V_74 ) ;
F_51 ( & V_45 -> V_77 ) ;
* V_73 = V_6 ;
F_34 ( L_15 , F_43 ( V_6 ) ) ;
return 0 ;
V_83:
F_9 ( V_6 ) ;
F_51 ( & V_81 ) ;
V_6 = F_53 ( V_75 ) ;
if ( V_51 ) {
V_35 = F_54 ( V_51 , V_6 ) ;
if ( V_35 == 0 )
F_50 ( V_51 , V_6 , & V_74 ) ;
F_52 ( V_51 , type , V_74 ) ;
if ( V_35 < 0 )
goto V_84;
}
F_51 ( & V_45 -> V_77 ) ;
* V_73 = V_6 ;
F_34 ( L_16 , F_43 ( V_6 ) ) ;
return - V_85 ;
V_84:
F_51 ( & V_45 -> V_77 ) ;
F_9 ( V_6 ) ;
F_34 ( L_17 , V_35 ) ;
return V_35 ;
V_80:
F_51 ( & V_45 -> V_77 ) ;
F_34 ( L_18 , V_35 ) ;
return V_35 ;
V_79:
F_51 ( & V_45 -> V_77 ) ;
F_34 ( L_19 , F_26 ( V_6 ) ) ;
return F_26 ( V_6 ) ;
}
static struct V_6 * F_55 ( struct V_70 * type ,
const char * V_71 ,
const char * V_49 ,
T_3 V_50 ,
void * V_26 ,
struct V_6 * V_51 ,
unsigned long V_1 )
{
struct V_72 * V_45 ;
struct V_6 * V_6 ;
int V_35 ;
F_6 ( L_20 ) ;
V_45 = F_56 ( F_57 () , F_58 () ) ;
if ( ! V_45 )
return F_59 ( - V_24 ) ;
F_39 ( & V_51 ) ;
V_35 = F_44 ( type , V_71 , V_51 , V_1 , V_45 ,
& V_6 ) ;
F_60 ( V_45 ) ;
if ( V_35 == 0 ) {
V_35 = F_35 ( V_6 , V_49 , V_50 , V_26 ,
V_51 ) ;
if ( V_35 < 0 ) {
F_31 ( L_21 ) ;
goto V_86;
}
} else if ( V_35 == - V_85 ) {
V_35 = 0 ;
} else {
goto V_87;
}
F_9 ( V_51 ) ;
F_34 ( L_22 , F_43 ( V_6 ) ) ;
return V_6 ;
V_86:
F_7 ( V_6 , V_9 , NULL , NULL ) ;
F_9 ( V_6 ) ;
V_87:
F_9 ( V_51 ) ;
F_34 ( L_9 , V_35 ) ;
return F_59 ( V_35 ) ;
}
struct V_6 * F_61 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_3 V_50 ,
void * V_26 ,
struct V_6 * V_51 ,
unsigned long V_1 )
{
const struct V_12 * V_12 = F_20 () ;
struct V_6 * V_6 ;
T_5 V_75 ;
int V_35 ;
F_6 ( L_23 ,
type -> V_76 , V_71 , V_49 , V_50 , V_26 ,
V_51 , V_1 ) ;
V_75 = F_49 ( type , V_71 , type -> V_82 , V_12 ) ;
if ( ! F_25 ( V_75 ) ) {
V_6 = F_53 ( V_75 ) ;
if ( V_51 ) {
F_39 ( & V_51 ) ;
V_35 = F_27 ( V_51 , V_6 ) ;
F_9 ( V_51 ) ;
if ( V_35 < 0 ) {
F_9 ( V_6 ) ;
V_6 = F_59 ( V_35 ) ;
goto error;
}
}
} else if ( F_26 ( V_75 ) != - V_88 ) {
V_6 = F_62 ( V_75 ) ;
} else {
V_6 = F_59 ( - V_48 ) ;
if ( ! V_49 )
goto error;
V_6 = F_55 ( type , V_71 , V_49 ,
V_50 , V_26 , V_51 ,
V_1 ) ;
}
error:
F_34 ( L_24 , V_6 ) ;
return V_6 ;
}
int F_63 ( struct V_6 * V_6 , bool V_89 )
{
int V_35 ;
V_35 = F_64 ( & V_6 -> V_1 , V_47 ,
V_89 ? F_3 : F_1 ,
V_89 ? V_90 : V_91 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_32 ( V_92 , & V_6 -> V_1 ) )
return V_6 -> V_93 . V_94 ;
return F_33 ( V_6 ) ;
}
struct V_6 * V_53 ( struct V_70 * type ,
const char * V_71 ,
const char * V_49 )
{
struct V_6 * V_6 ;
T_3 V_50 = 0 ;
int V_35 ;
if ( V_49 )
V_50 = strlen ( V_49 ) ;
V_6 = F_61 ( type , V_71 , V_49 , V_50 ,
NULL , NULL , V_95 ) ;
if ( ! F_25 ( V_6 ) ) {
V_35 = F_63 ( V_6 , false ) ;
if ( V_35 < 0 ) {
F_9 ( V_6 ) ;
return F_59 ( V_35 ) ;
}
}
return V_6 ;
}
struct V_6 * F_65 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_3 V_50 ,
void * V_26 )
{
struct V_6 * V_6 ;
int V_35 ;
V_6 = F_61 ( type , V_71 , V_49 , V_50 ,
V_26 , NULL , V_95 ) ;
if ( ! F_25 ( V_6 ) ) {
V_35 = F_63 ( V_6 , false ) ;
if ( V_35 < 0 ) {
F_9 ( V_6 ) ;
return F_59 ( V_35 ) ;
}
}
return V_6 ;
}
struct V_6 * F_66 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_3 V_50 )
{
return F_61 ( type , V_71 , V_49 ,
V_50 , NULL , NULL ,
V_95 ) ;
}
struct V_6 * F_67 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_3 V_50 ,
void * V_26 )
{
return F_61 ( type , V_71 , V_49 ,
V_50 , V_26 , NULL , V_95 ) ;
}
