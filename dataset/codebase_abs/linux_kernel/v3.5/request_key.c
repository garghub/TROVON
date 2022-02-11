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
return F_15 ( V_15 , V_16 , V_17 , V_19 ,
F_11 , F_13 ,
F_16 ( V_18 ) ) ;
}
static int F_17 ( struct V_4 * V_5 ,
const char * V_20 ,
void * V_21 )
{
const struct V_12 * V_12 = F_18 () ;
T_1 V_22 , V_23 ;
struct V_6 * V_6 = V_5 -> V_6 , * V_8 = V_5 -> V_8 , * V_13 ,
* V_24 ;
char * V_16 [ 9 ] , * V_17 [ 3 ] , V_25 [ 12 ] , V_26 [ 12 ] ;
char V_27 [ 12 ] , V_28 [ 3 ] [ 12 ] ;
char V_29 [ 20 ] ;
int V_30 , V_31 ;
F_6 ( L_2 , V_6 -> V_7 , V_8 -> V_7 , V_20 ) ;
V_30 = F_19 () ;
if ( V_30 < 0 )
goto V_32;
sprintf ( V_29 , L_3 , V_6 -> V_7 ) ;
V_12 = F_20 () ;
V_13 = F_21 ( V_29 , V_12 -> V_33 , V_12 -> V_34 , V_12 ,
V_35 , NULL ) ;
F_22 ( V_12 ) ;
if ( F_23 ( V_13 ) ) {
V_30 = F_24 ( V_13 ) ;
goto V_32;
}
V_30 = F_25 ( V_13 , V_8 ) ;
if ( V_30 < 0 )
goto V_36;
sprintf ( V_25 , L_4 , V_12 -> V_33 ) ;
sprintf ( V_26 , L_4 , V_12 -> V_34 ) ;
sprintf ( V_27 , L_4 , V_6 -> V_7 ) ;
sprintf ( V_28 [ 0 ] , L_4 ,
V_12 -> V_37 ? V_12 -> V_37 -> V_7 : 0 ) ;
V_22 = 0 ;
if ( V_12 -> V_38 -> V_39 )
V_22 = V_12 -> V_38 -> V_39 -> V_7 ;
sprintf ( V_28 [ 1 ] , L_4 , V_22 ) ;
F_26 () ;
V_24 = F_27 ( V_12 -> V_38 -> V_18 ) ;
if ( ! V_24 )
V_24 = V_12 -> V_40 -> V_18 ;
V_23 = V_24 -> V_7 ;
F_28 () ;
sprintf ( V_28 [ 2 ] , L_4 , V_23 ) ;
V_31 = 0 ;
V_17 [ V_31 ++ ] = L_5 ;
V_17 [ V_31 ++ ] = L_6 ;
V_17 [ V_31 ] = NULL ;
V_31 = 0 ;
V_16 [ V_31 ++ ] = L_7 ;
V_16 [ V_31 ++ ] = ( char * ) V_20 ;
V_16 [ V_31 ++ ] = V_27 ;
V_16 [ V_31 ++ ] = V_25 ;
V_16 [ V_31 ++ ] = V_26 ;
V_16 [ V_31 ++ ] = V_28 [ 0 ] ;
V_16 [ V_31 ++ ] = V_28 [ 1 ] ;
V_16 [ V_31 ++ ] = V_28 [ 2 ] ;
V_16 [ V_31 ] = NULL ;
V_30 = F_14 ( V_16 [ 0 ] , V_16 , V_17 , V_13 ,
V_41 ) ;
F_29 ( L_8 , V_30 ) ;
if ( V_30 >= 0 ) {
if ( F_30 ( V_42 , & V_6 -> V_1 ) ||
F_31 ( V_6 ) < 0 )
V_30 = - V_43 ;
else
V_30 = 0 ;
}
V_36:
F_9 ( V_13 ) ;
V_32:
F_5 ( V_5 , V_30 ) ;
F_32 ( L_9 , V_30 ) ;
return V_30 ;
}
static int F_33 ( struct V_6 * V_6 , const void * V_44 ,
T_2 V_45 , void * V_21 ,
struct V_6 * V_46 )
{
struct V_4 * V_5 ;
T_3 V_47 ;
struct V_6 * V_8 ;
int V_30 ;
F_6 ( L_10 , V_6 -> V_7 , V_44 , V_45 , V_21 ) ;
V_5 = F_34 ( sizeof( * V_5 ) , V_48 ) ;
if ( ! V_5 )
return - V_49 ;
V_8 = F_35 ( V_6 , V_44 , V_45 ,
V_46 ) ;
if ( F_23 ( V_8 ) ) {
F_10 ( V_5 ) ;
V_30 = F_24 ( V_8 ) ;
V_8 = NULL ;
} else {
V_5 -> V_8 = F_16 ( V_8 ) ;
V_5 -> V_6 = F_16 ( V_6 ) ;
V_47 = F_17 ;
if ( V_6 -> type -> V_50 )
V_47 = V_6 -> type -> V_50 ;
V_30 = V_47 ( V_5 , L_11 , V_21 ) ;
F_36 ( V_30 < 0 &&
! F_30 ( V_51 , & V_8 -> V_1 ) ) ;
F_9 ( V_8 ) ;
}
F_32 ( L_9 , V_30 ) ;
return V_30 ;
}
static void F_37 ( struct V_6 * * V_52 )
{
struct V_53 * V_54 ;
const struct V_12 * V_12 = F_18 () ;
struct V_6 * V_46 = * V_52 , * V_8 ;
F_6 ( L_12 , V_46 ) ;
if ( V_46 ) {
F_16 ( V_46 ) ;
} else {
switch ( V_12 -> V_55 ) {
case V_56 :
case V_57 :
if ( V_12 -> V_53 ) {
V_8 = V_12 -> V_53 ;
F_38 ( & V_8 -> V_58 ) ;
V_54 = V_8 -> V_59 . V_14 ;
if ( ! F_30 ( V_51 ,
& V_8 -> V_1 ) )
V_46 =
F_16 ( V_54 -> V_46 ) ;
F_39 ( & V_8 -> V_58 ) ;
if ( V_46 )
break;
}
case V_60 :
V_46 = F_16 ( V_12 -> V_37 ) ;
if ( V_46 )
break;
case V_61 :
V_46 = F_16 ( V_12 -> V_38 -> V_39 ) ;
if ( V_46 )
break;
case V_62 :
F_26 () ;
V_46 = F_16 (
F_27 ( V_12 -> V_38 -> V_18 ) ) ;
F_28 () ;
if ( V_46 )
break;
case V_63 :
V_46 =
F_16 ( V_12 -> V_40 -> V_18 ) ;
break;
case V_64 :
V_46 = F_16 ( V_12 -> V_40 -> V_65 ) ;
break;
case V_66 :
default:
F_40 () ;
}
}
* V_52 = V_46 ;
F_32 ( L_13 , F_41 ( V_46 ) ) ;
return;
}
static int F_42 ( struct V_67 * type ,
const char * V_68 ,
struct V_6 * V_46 ,
unsigned long V_1 ,
struct V_69 * V_40 ,
struct V_6 * * V_70 )
{
const struct V_12 * V_12 = F_18 () ;
unsigned long V_71 ;
struct V_6 * V_6 ;
T_4 V_72 ;
int V_30 ;
F_6 ( L_14 , type -> V_73 , V_68 ) ;
* V_70 = NULL ;
F_43 ( & V_40 -> V_74 ) ;
V_6 = F_44 ( type , V_68 , V_12 -> V_33 , V_12 -> V_34 , V_12 ,
V_75 , V_1 ) ;
if ( F_23 ( V_6 ) )
goto V_76;
F_45 ( V_42 , & V_6 -> V_1 ) ;
if ( V_46 ) {
V_30 = F_46 ( V_46 , type , V_68 ,
& V_71 ) ;
if ( V_30 < 0 )
goto V_77;
}
F_43 ( & V_78 ) ;
V_72 = F_47 ( type , V_68 , type -> V_79 , V_12 ) ;
if ( ! F_23 ( V_72 ) )
goto V_80;
if ( V_46 )
F_48 ( V_46 , V_6 , & V_71 ) ;
F_49 ( & V_78 ) ;
if ( V_46 )
F_50 ( V_46 , type , V_71 ) ;
F_49 ( & V_40 -> V_74 ) ;
* V_70 = V_6 ;
F_32 ( L_15 , F_41 ( V_6 ) ) ;
return 0 ;
V_80:
F_9 ( V_6 ) ;
F_49 ( & V_78 ) ;
V_6 = F_51 ( V_72 ) ;
if ( V_46 ) {
V_30 = F_52 ( V_46 , V_6 ) ;
if ( V_30 == 0 )
F_48 ( V_46 , V_6 , & V_71 ) ;
F_50 ( V_46 , type , V_71 ) ;
if ( V_30 < 0 )
goto V_81;
}
F_49 ( & V_40 -> V_74 ) ;
* V_70 = V_6 ;
F_32 ( L_16 , F_41 ( V_6 ) ) ;
return - V_82 ;
V_81:
F_49 ( & V_40 -> V_74 ) ;
F_9 ( V_6 ) ;
F_32 ( L_17 , V_30 ) ;
return V_30 ;
V_77:
F_49 ( & V_40 -> V_74 ) ;
F_32 ( L_18 , V_30 ) ;
return V_30 ;
V_76:
F_49 ( & V_40 -> V_74 ) ;
F_32 ( L_19 , F_24 ( V_6 ) ) ;
return F_24 ( V_6 ) ;
}
static struct V_6 * F_53 ( struct V_67 * type ,
const char * V_68 ,
const char * V_44 ,
T_2 V_45 ,
void * V_21 ,
struct V_6 * V_46 ,
unsigned long V_1 )
{
struct V_69 * V_40 ;
struct V_6 * V_6 ;
int V_30 ;
F_6 ( L_20 ) ;
V_40 = F_54 ( F_55 () , F_56 () ) ;
if ( ! V_40 )
return F_57 ( - V_49 ) ;
F_37 ( & V_46 ) ;
V_30 = F_42 ( type , V_68 , V_46 , V_1 , V_40 ,
& V_6 ) ;
F_58 ( V_40 ) ;
if ( V_30 == 0 ) {
V_30 = F_33 ( V_6 , V_44 , V_45 , V_21 ,
V_46 ) ;
if ( V_30 < 0 ) {
F_29 ( L_21 ) ;
goto V_83;
}
} else if ( V_30 == - V_82 ) {
V_30 = 0 ;
} else {
goto V_84;
}
F_9 ( V_46 ) ;
F_32 ( L_22 , F_41 ( V_6 ) ) ;
return V_6 ;
V_83:
F_7 ( V_6 , V_9 , NULL , NULL ) ;
F_9 ( V_6 ) ;
V_84:
F_9 ( V_46 ) ;
F_32 ( L_9 , V_30 ) ;
return F_57 ( V_30 ) ;
}
struct V_6 * F_59 ( struct V_67 * type ,
const char * V_68 ,
const void * V_44 ,
T_2 V_45 ,
void * V_21 ,
struct V_6 * V_46 ,
unsigned long V_1 )
{
const struct V_12 * V_12 = F_18 () ;
struct V_6 * V_6 ;
T_4 V_72 ;
int V_30 ;
F_6 ( L_23 ,
type -> V_73 , V_68 , V_44 , V_45 , V_21 ,
V_46 , V_1 ) ;
V_72 = F_47 ( type , V_68 , type -> V_79 , V_12 ) ;
if ( ! F_23 ( V_72 ) ) {
V_6 = F_51 ( V_72 ) ;
if ( V_46 ) {
F_37 ( & V_46 ) ;
V_30 = F_25 ( V_46 , V_6 ) ;
F_9 ( V_46 ) ;
if ( V_30 < 0 ) {
F_9 ( V_6 ) ;
V_6 = F_57 ( V_30 ) ;
goto error;
}
}
} else if ( F_24 ( V_72 ) != - V_85 ) {
V_6 = F_60 ( V_72 ) ;
} else {
V_6 = F_57 ( - V_43 ) ;
if ( ! V_44 )
goto error;
V_6 = F_53 ( type , V_68 , V_44 ,
V_45 , V_21 , V_46 ,
V_1 ) ;
}
error:
F_32 ( L_24 , V_6 ) ;
return V_6 ;
}
int F_61 ( struct V_6 * V_6 , bool V_86 )
{
int V_30 ;
V_30 = F_62 ( & V_6 -> V_1 , V_42 ,
V_86 ? F_3 : F_1 ,
V_86 ? V_87 : V_88 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( F_30 ( V_89 , & V_6 -> V_1 ) )
return V_6 -> V_90 . V_91 ;
return F_31 ( V_6 ) ;
}
struct V_6 * V_50 ( struct V_67 * type ,
const char * V_68 ,
const char * V_44 )
{
struct V_6 * V_6 ;
T_2 V_45 = 0 ;
int V_30 ;
if ( V_44 )
V_45 = strlen ( V_44 ) ;
V_6 = F_59 ( type , V_68 , V_44 , V_45 ,
NULL , NULL , V_92 ) ;
if ( ! F_23 ( V_6 ) ) {
V_30 = F_61 ( V_6 , false ) ;
if ( V_30 < 0 ) {
F_9 ( V_6 ) ;
return F_57 ( V_30 ) ;
}
}
return V_6 ;
}
struct V_6 * F_63 ( struct V_67 * type ,
const char * V_68 ,
const void * V_44 ,
T_2 V_45 ,
void * V_21 )
{
struct V_6 * V_6 ;
int V_30 ;
V_6 = F_59 ( type , V_68 , V_44 , V_45 ,
V_21 , NULL , V_92 ) ;
if ( ! F_23 ( V_6 ) ) {
V_30 = F_61 ( V_6 , false ) ;
if ( V_30 < 0 ) {
F_9 ( V_6 ) ;
return F_57 ( V_30 ) ;
}
}
return V_6 ;
}
struct V_6 * F_64 ( struct V_67 * type ,
const char * V_68 ,
const void * V_44 ,
T_2 V_45 )
{
return F_59 ( type , V_68 , V_44 ,
V_45 , NULL , NULL ,
V_92 ) ;
}
struct V_6 * F_65 ( struct V_67 * type ,
const char * V_68 ,
const void * V_44 ,
T_2 V_45 ,
void * V_21 )
{
return F_59 ( type , V_68 , V_44 ,
V_45 , V_21 , NULL , V_92 ) ;
}
