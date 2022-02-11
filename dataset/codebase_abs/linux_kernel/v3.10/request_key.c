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
struct V_10 * V_11 ;
V_11 = F_15 ( V_15 , V_16 , V_17 , V_20 ,
F_11 , F_13 ,
V_18 ) ;
if ( ! V_11 )
return - V_21 ;
F_16 ( V_18 ) ;
return F_17 ( V_11 , V_19 ) ;
}
static int F_18 ( struct V_4 * V_5 ,
const char * V_22 ,
void * V_23 )
{
const struct V_12 * V_12 = F_19 () ;
T_1 V_24 , V_25 ;
struct V_6 * V_6 = V_5 -> V_6 , * V_8 = V_5 -> V_8 , * V_13 ,
* V_26 ;
char * V_16 [ 9 ] , * V_17 [ 3 ] , V_27 [ 12 ] , V_28 [ 12 ] ;
char V_29 [ 12 ] , V_30 [ 3 ] [ 12 ] ;
char V_31 [ 20 ] ;
int V_32 , V_33 ;
F_6 ( L_2 , V_6 -> V_7 , V_8 -> V_7 , V_22 ) ;
V_32 = F_20 () ;
if ( V_32 < 0 )
goto V_34;
sprintf ( V_31 , L_3 , V_6 -> V_7 ) ;
V_12 = F_21 () ;
V_13 = F_22 ( V_31 , V_12 -> V_35 , V_12 -> V_36 , V_12 ,
V_37 | V_38 | V_39 ,
V_40 , NULL ) ;
F_23 ( V_12 ) ;
if ( F_24 ( V_13 ) ) {
V_32 = F_25 ( V_13 ) ;
goto V_34;
}
V_32 = F_26 ( V_13 , V_8 ) ;
if ( V_32 < 0 )
goto V_41;
sprintf ( V_27 , L_4 , F_27 ( & V_42 , V_12 -> V_35 ) ) ;
sprintf ( V_28 , L_4 , F_28 ( & V_42 , V_12 -> V_36 ) ) ;
sprintf ( V_29 , L_4 , V_6 -> V_7 ) ;
sprintf ( V_30 [ 0 ] , L_4 ,
V_12 -> V_43 ? V_12 -> V_43 -> V_7 : 0 ) ;
V_24 = 0 ;
if ( V_12 -> V_44 )
V_24 = V_12 -> V_44 -> V_7 ;
sprintf ( V_30 [ 1 ] , L_4 , V_24 ) ;
F_29 () ;
V_26 = F_30 ( V_12 -> V_18 ) ;
if ( ! V_26 )
V_26 = V_12 -> V_45 -> V_18 ;
V_25 = V_26 -> V_7 ;
F_31 () ;
sprintf ( V_30 [ 2 ] , L_4 , V_25 ) ;
V_33 = 0 ;
V_17 [ V_33 ++ ] = L_5 ;
V_17 [ V_33 ++ ] = L_6 ;
V_17 [ V_33 ] = NULL ;
V_33 = 0 ;
V_16 [ V_33 ++ ] = L_7 ;
V_16 [ V_33 ++ ] = ( char * ) V_22 ;
V_16 [ V_33 ++ ] = V_29 ;
V_16 [ V_33 ++ ] = V_27 ;
V_16 [ V_33 ++ ] = V_28 ;
V_16 [ V_33 ++ ] = V_30 [ 0 ] ;
V_16 [ V_33 ++ ] = V_30 [ 1 ] ;
V_16 [ V_33 ++ ] = V_30 [ 2 ] ;
V_16 [ V_33 ] = NULL ;
V_32 = F_14 ( V_16 [ 0 ] , V_16 , V_17 , V_13 ,
V_46 ) ;
F_32 ( L_8 , V_32 ) ;
if ( V_32 >= 0 ) {
if ( F_33 ( V_47 , & V_6 -> V_1 ) ||
F_34 ( V_6 ) < 0 )
V_32 = - V_48 ;
else
V_32 = 0 ;
}
V_41:
F_9 ( V_13 ) ;
V_34:
F_5 ( V_5 , V_32 ) ;
F_35 ( L_9 , V_32 ) ;
return V_32 ;
}
static int F_36 ( struct V_6 * V_6 , const void * V_49 ,
T_2 V_50 , void * V_23 ,
struct V_6 * V_51 )
{
struct V_4 * V_5 ;
T_3 V_52 ;
struct V_6 * V_8 ;
int V_32 ;
F_6 ( L_10 , V_6 -> V_7 , V_49 , V_50 , V_23 ) ;
V_5 = F_37 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return - V_21 ;
V_8 = F_38 ( V_6 , V_49 , V_50 ,
V_51 ) ;
if ( F_24 ( V_8 ) ) {
F_10 ( V_5 ) ;
V_32 = F_25 ( V_8 ) ;
V_8 = NULL ;
} else {
V_5 -> V_8 = F_16 ( V_8 ) ;
V_5 -> V_6 = F_16 ( V_6 ) ;
V_52 = F_18 ;
if ( V_6 -> type -> V_53 )
V_52 = V_6 -> type -> V_53 ;
V_32 = V_52 ( V_5 , L_11 , V_23 ) ;
F_39 ( V_32 < 0 &&
! F_33 ( V_54 , & V_8 -> V_1 ) ) ;
F_9 ( V_8 ) ;
}
F_35 ( L_9 , V_32 ) ;
return V_32 ;
}
static void F_40 ( struct V_6 * * V_55 )
{
struct V_56 * V_57 ;
const struct V_12 * V_12 = F_19 () ;
struct V_6 * V_51 = * V_55 , * V_8 ;
F_6 ( L_12 , V_51 ) ;
if ( V_51 ) {
F_16 ( V_51 ) ;
} else {
switch ( V_12 -> V_58 ) {
case V_59 :
case V_60 :
if ( V_12 -> V_56 ) {
V_8 = V_12 -> V_56 ;
F_41 ( & V_8 -> V_61 ) ;
V_57 = V_8 -> V_62 . V_14 ;
if ( ! F_33 ( V_54 ,
& V_8 -> V_1 ) )
V_51 =
F_16 ( V_57 -> V_51 ) ;
F_42 ( & V_8 -> V_61 ) ;
if ( V_51 )
break;
}
case V_63 :
V_51 = F_16 ( V_12 -> V_43 ) ;
if ( V_51 )
break;
case V_64 :
V_51 = F_16 ( V_12 -> V_44 ) ;
if ( V_51 )
break;
case V_65 :
F_29 () ;
V_51 = F_16 (
F_30 ( V_12 -> V_18 ) ) ;
F_31 () ;
if ( V_51 )
break;
case V_66 :
V_51 =
F_16 ( V_12 -> V_45 -> V_18 ) ;
break;
case V_67 :
V_51 = F_16 ( V_12 -> V_45 -> V_68 ) ;
break;
case V_69 :
default:
F_43 () ;
}
}
* V_55 = V_51 ;
F_35 ( L_13 , F_44 ( V_51 ) ) ;
return;
}
static int F_45 ( struct V_70 * type ,
const char * V_71 ,
struct V_6 * V_51 ,
unsigned long V_1 ,
struct V_72 * V_45 ,
struct V_6 * * V_73 )
{
const struct V_12 * V_12 = F_19 () ;
unsigned long V_74 ;
struct V_6 * V_6 ;
T_4 V_75 ;
T_5 V_76 ;
int V_32 ;
F_6 ( L_14 , type -> V_77 , V_71 ) ;
* V_73 = NULL ;
F_46 ( & V_45 -> V_78 ) ;
V_75 = V_79 | V_80 | V_81 | V_82 ;
V_75 |= V_38 ;
if ( type -> V_83 )
V_75 |= V_84 ;
if ( type == & V_85 || type -> V_86 )
V_75 |= V_87 ;
V_6 = F_47 ( type , V_71 , V_12 -> V_35 , V_12 -> V_36 , V_12 ,
V_75 , V_1 ) ;
if ( F_24 ( V_6 ) )
goto V_88;
F_48 ( V_47 , & V_6 -> V_1 ) ;
if ( V_51 ) {
V_32 = F_49 ( V_51 , type , V_71 ,
& V_74 ) ;
if ( V_32 < 0 )
goto V_89;
}
F_46 ( & V_90 ) ;
V_76 = F_50 ( type , V_71 , type -> V_91 , V_12 ) ;
if ( ! F_24 ( V_76 ) )
goto V_92;
if ( V_51 )
F_51 ( V_51 , V_6 , & V_74 ) ;
F_52 ( & V_90 ) ;
if ( V_51 )
F_53 ( V_51 , type , V_74 ) ;
F_52 ( & V_45 -> V_78 ) ;
* V_73 = V_6 ;
F_35 ( L_15 , F_44 ( V_6 ) ) ;
return 0 ;
V_92:
F_9 ( V_6 ) ;
F_52 ( & V_90 ) ;
V_6 = F_54 ( V_76 ) ;
if ( V_51 ) {
V_32 = F_55 ( V_51 , V_6 ) ;
if ( V_32 == 0 )
F_51 ( V_51 , V_6 , & V_74 ) ;
F_53 ( V_51 , type , V_74 ) ;
if ( V_32 < 0 )
goto V_93;
}
F_52 ( & V_45 -> V_78 ) ;
* V_73 = V_6 ;
F_35 ( L_16 , F_44 ( V_6 ) ) ;
return - V_94 ;
V_93:
F_52 ( & V_45 -> V_78 ) ;
F_9 ( V_6 ) ;
F_35 ( L_17 , V_32 ) ;
return V_32 ;
V_89:
F_52 ( & V_45 -> V_78 ) ;
F_35 ( L_18 , V_32 ) ;
return V_32 ;
V_88:
F_52 ( & V_45 -> V_78 ) ;
F_35 ( L_19 , F_25 ( V_6 ) ) ;
return F_25 ( V_6 ) ;
}
static struct V_6 * F_56 ( struct V_70 * type ,
const char * V_71 ,
const char * V_49 ,
T_2 V_50 ,
void * V_23 ,
struct V_6 * V_51 ,
unsigned long V_1 )
{
struct V_72 * V_45 ;
struct V_6 * V_6 ;
int V_32 ;
F_6 ( L_20 ) ;
V_45 = F_57 ( F_58 () ) ;
if ( ! V_45 )
return F_59 ( - V_21 ) ;
F_40 ( & V_51 ) ;
V_32 = F_45 ( type , V_71 , V_51 , V_1 , V_45 ,
& V_6 ) ;
F_60 ( V_45 ) ;
if ( V_32 == 0 ) {
V_32 = F_36 ( V_6 , V_49 , V_50 , V_23 ,
V_51 ) ;
if ( V_32 < 0 ) {
F_32 ( L_21 ) ;
goto V_95;
}
} else if ( V_32 == - V_94 ) {
V_32 = 0 ;
} else {
goto V_96;
}
F_9 ( V_51 ) ;
F_35 ( L_22 , F_44 ( V_6 ) ) ;
return V_6 ;
V_95:
F_7 ( V_6 , V_9 , NULL , NULL ) ;
F_9 ( V_6 ) ;
V_96:
F_9 ( V_51 ) ;
F_35 ( L_9 , V_32 ) ;
return F_59 ( V_32 ) ;
}
struct V_6 * F_61 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_2 V_50 ,
void * V_23 ,
struct V_6 * V_51 ,
unsigned long V_1 )
{
const struct V_12 * V_12 = F_19 () ;
struct V_6 * V_6 ;
T_5 V_76 ;
int V_32 ;
F_6 ( L_23 ,
type -> V_77 , V_71 , V_49 , V_50 , V_23 ,
V_51 , V_1 ) ;
V_76 = F_50 ( type , V_71 , type -> V_91 , V_12 ) ;
if ( ! F_24 ( V_76 ) ) {
V_6 = F_54 ( V_76 ) ;
if ( V_51 ) {
F_40 ( & V_51 ) ;
V_32 = F_26 ( V_51 , V_6 ) ;
F_9 ( V_51 ) ;
if ( V_32 < 0 ) {
F_9 ( V_6 ) ;
V_6 = F_59 ( V_32 ) ;
goto error;
}
}
} else if ( F_25 ( V_76 ) != - V_97 ) {
V_6 = F_62 ( V_76 ) ;
} else {
V_6 = F_59 ( - V_48 ) ;
if ( ! V_49 )
goto error;
V_6 = F_56 ( type , V_71 , V_49 ,
V_50 , V_23 , V_51 ,
V_1 ) ;
}
error:
F_35 ( L_24 , V_6 ) ;
return V_6 ;
}
int F_63 ( struct V_6 * V_6 , bool V_98 )
{
int V_32 ;
V_32 = F_64 ( & V_6 -> V_1 , V_47 ,
V_98 ? F_3 : F_1 ,
V_98 ? V_99 : V_100 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( F_33 ( V_101 , & V_6 -> V_1 ) )
return V_6 -> V_102 . V_103 ;
return F_34 ( V_6 ) ;
}
struct V_6 * V_53 ( struct V_70 * type ,
const char * V_71 ,
const char * V_49 )
{
struct V_6 * V_6 ;
T_2 V_50 = 0 ;
int V_32 ;
if ( V_49 )
V_50 = strlen ( V_49 ) ;
V_6 = F_61 ( type , V_71 , V_49 , V_50 ,
NULL , NULL , V_104 ) ;
if ( ! F_24 ( V_6 ) ) {
V_32 = F_63 ( V_6 , false ) ;
if ( V_32 < 0 ) {
F_9 ( V_6 ) ;
return F_59 ( V_32 ) ;
}
}
return V_6 ;
}
struct V_6 * F_65 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_2 V_50 ,
void * V_23 )
{
struct V_6 * V_6 ;
int V_32 ;
V_6 = F_61 ( type , V_71 , V_49 , V_50 ,
V_23 , NULL , V_104 ) ;
if ( ! F_24 ( V_6 ) ) {
V_32 = F_63 ( V_6 , false ) ;
if ( V_32 < 0 ) {
F_9 ( V_6 ) ;
return F_59 ( V_32 ) ;
}
}
return V_6 ;
}
struct V_6 * F_66 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_2 V_50 )
{
return F_61 ( type , V_71 , V_49 ,
V_50 , NULL , NULL ,
V_104 ) ;
}
struct V_6 * F_67 ( struct V_70 * type ,
const char * V_71 ,
const void * V_49 ,
T_2 V_50 ,
void * V_23 )
{
return F_61 ( type , V_71 , V_49 ,
V_50 , V_23 , NULL , V_104 ) ;
}
