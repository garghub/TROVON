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
sprintf ( V_25 , L_4 , F_26 ( & V_37 , V_12 -> V_33 ) ) ;
sprintf ( V_26 , L_4 , F_27 ( & V_37 , V_12 -> V_34 ) ) ;
sprintf ( V_27 , L_4 , V_6 -> V_7 ) ;
sprintf ( V_28 [ 0 ] , L_4 ,
V_12 -> V_38 ? V_12 -> V_38 -> V_7 : 0 ) ;
V_22 = 0 ;
if ( V_12 -> V_39 -> V_40 )
V_22 = V_12 -> V_39 -> V_40 -> V_7 ;
sprintf ( V_28 [ 1 ] , L_4 , V_22 ) ;
F_28 () ;
V_24 = F_29 ( V_12 -> V_39 -> V_18 ) ;
if ( ! V_24 )
V_24 = V_12 -> V_41 -> V_18 ;
V_23 = V_24 -> V_7 ;
F_30 () ;
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
V_42 ) ;
F_31 ( L_8 , V_30 ) ;
if ( V_30 >= 0 ) {
if ( F_32 ( V_43 , & V_6 -> V_1 ) ||
F_33 ( V_6 ) < 0 )
V_30 = - V_44 ;
else
V_30 = 0 ;
}
V_36:
F_9 ( V_13 ) ;
V_32:
F_5 ( V_5 , V_30 ) ;
F_34 ( L_9 , V_30 ) ;
return V_30 ;
}
static int F_35 ( struct V_6 * V_6 , const void * V_45 ,
T_2 V_46 , void * V_21 ,
struct V_6 * V_47 )
{
struct V_4 * V_5 ;
T_3 V_48 ;
struct V_6 * V_8 ;
int V_30 ;
F_6 ( L_10 , V_6 -> V_7 , V_45 , V_46 , V_21 ) ;
V_5 = F_36 ( sizeof( * V_5 ) , V_49 ) ;
if ( ! V_5 )
return - V_50 ;
V_8 = F_37 ( V_6 , V_45 , V_46 ,
V_47 ) ;
if ( F_23 ( V_8 ) ) {
F_10 ( V_5 ) ;
V_30 = F_24 ( V_8 ) ;
V_8 = NULL ;
} else {
V_5 -> V_8 = F_16 ( V_8 ) ;
V_5 -> V_6 = F_16 ( V_6 ) ;
V_48 = F_17 ;
if ( V_6 -> type -> V_51 )
V_48 = V_6 -> type -> V_51 ;
V_30 = V_48 ( V_5 , L_11 , V_21 ) ;
F_38 ( V_30 < 0 &&
! F_32 ( V_52 , & V_8 -> V_1 ) ) ;
F_9 ( V_8 ) ;
}
F_34 ( L_9 , V_30 ) ;
return V_30 ;
}
static void F_39 ( struct V_6 * * V_53 )
{
struct V_54 * V_55 ;
const struct V_12 * V_12 = F_18 () ;
struct V_6 * V_47 = * V_53 , * V_8 ;
F_6 ( L_12 , V_47 ) ;
if ( V_47 ) {
F_16 ( V_47 ) ;
} else {
switch ( V_12 -> V_56 ) {
case V_57 :
case V_58 :
if ( V_12 -> V_54 ) {
V_8 = V_12 -> V_54 ;
F_40 ( & V_8 -> V_59 ) ;
V_55 = V_8 -> V_60 . V_14 ;
if ( ! F_32 ( V_52 ,
& V_8 -> V_1 ) )
V_47 =
F_16 ( V_55 -> V_47 ) ;
F_41 ( & V_8 -> V_59 ) ;
if ( V_47 )
break;
}
case V_61 :
V_47 = F_16 ( V_12 -> V_38 ) ;
if ( V_47 )
break;
case V_62 :
V_47 = F_16 ( V_12 -> V_39 -> V_40 ) ;
if ( V_47 )
break;
case V_63 :
F_28 () ;
V_47 = F_16 (
F_29 ( V_12 -> V_39 -> V_18 ) ) ;
F_30 () ;
if ( V_47 )
break;
case V_64 :
V_47 =
F_16 ( V_12 -> V_41 -> V_18 ) ;
break;
case V_65 :
V_47 = F_16 ( V_12 -> V_41 -> V_66 ) ;
break;
case V_67 :
default:
F_42 () ;
}
}
* V_53 = V_47 ;
F_34 ( L_13 , F_43 ( V_47 ) ) ;
return;
}
static int F_44 ( struct V_68 * type ,
const char * V_69 ,
struct V_6 * V_47 ,
unsigned long V_1 ,
struct V_70 * V_41 ,
struct V_6 * * V_71 )
{
const struct V_12 * V_12 = F_18 () ;
unsigned long V_72 ;
struct V_6 * V_6 ;
T_4 V_73 ;
int V_30 ;
F_6 ( L_14 , type -> V_74 , V_69 ) ;
* V_71 = NULL ;
F_45 ( & V_41 -> V_75 ) ;
V_6 = F_46 ( type , V_69 , V_12 -> V_33 , V_12 -> V_34 , V_12 ,
V_76 , V_1 ) ;
if ( F_23 ( V_6 ) )
goto V_77;
F_47 ( V_43 , & V_6 -> V_1 ) ;
if ( V_47 ) {
V_30 = F_48 ( V_47 , type , V_69 ,
& V_72 ) ;
if ( V_30 < 0 )
goto V_78;
}
F_45 ( & V_79 ) ;
V_73 = F_49 ( type , V_69 , type -> V_80 , V_12 ) ;
if ( ! F_23 ( V_73 ) )
goto V_81;
if ( V_47 )
F_50 ( V_47 , V_6 , & V_72 ) ;
F_51 ( & V_79 ) ;
if ( V_47 )
F_52 ( V_47 , type , V_72 ) ;
F_51 ( & V_41 -> V_75 ) ;
* V_71 = V_6 ;
F_34 ( L_15 , F_43 ( V_6 ) ) ;
return 0 ;
V_81:
F_9 ( V_6 ) ;
F_51 ( & V_79 ) ;
V_6 = F_53 ( V_73 ) ;
if ( V_47 ) {
V_30 = F_54 ( V_47 , V_6 ) ;
if ( V_30 == 0 )
F_50 ( V_47 , V_6 , & V_72 ) ;
F_52 ( V_47 , type , V_72 ) ;
if ( V_30 < 0 )
goto V_82;
}
F_51 ( & V_41 -> V_75 ) ;
* V_71 = V_6 ;
F_34 ( L_16 , F_43 ( V_6 ) ) ;
return - V_83 ;
V_82:
F_51 ( & V_41 -> V_75 ) ;
F_9 ( V_6 ) ;
F_34 ( L_17 , V_30 ) ;
return V_30 ;
V_78:
F_51 ( & V_41 -> V_75 ) ;
F_34 ( L_18 , V_30 ) ;
return V_30 ;
V_77:
F_51 ( & V_41 -> V_75 ) ;
F_34 ( L_19 , F_24 ( V_6 ) ) ;
return F_24 ( V_6 ) ;
}
static struct V_6 * F_55 ( struct V_68 * type ,
const char * V_69 ,
const char * V_45 ,
T_2 V_46 ,
void * V_21 ,
struct V_6 * V_47 ,
unsigned long V_1 )
{
struct V_70 * V_41 ;
struct V_6 * V_6 ;
int V_30 ;
F_6 ( L_20 ) ;
V_41 = F_56 ( F_57 () ) ;
if ( ! V_41 )
return F_58 ( - V_50 ) ;
F_39 ( & V_47 ) ;
V_30 = F_44 ( type , V_69 , V_47 , V_1 , V_41 ,
& V_6 ) ;
F_59 ( V_41 ) ;
if ( V_30 == 0 ) {
V_30 = F_35 ( V_6 , V_45 , V_46 , V_21 ,
V_47 ) ;
if ( V_30 < 0 ) {
F_31 ( L_21 ) ;
goto V_84;
}
} else if ( V_30 == - V_83 ) {
V_30 = 0 ;
} else {
goto V_85;
}
F_9 ( V_47 ) ;
F_34 ( L_22 , F_43 ( V_6 ) ) ;
return V_6 ;
V_84:
F_7 ( V_6 , V_9 , NULL , NULL ) ;
F_9 ( V_6 ) ;
V_85:
F_9 ( V_47 ) ;
F_34 ( L_9 , V_30 ) ;
return F_58 ( V_30 ) ;
}
struct V_6 * F_60 ( struct V_68 * type ,
const char * V_69 ,
const void * V_45 ,
T_2 V_46 ,
void * V_21 ,
struct V_6 * V_47 ,
unsigned long V_1 )
{
const struct V_12 * V_12 = F_18 () ;
struct V_6 * V_6 ;
T_4 V_73 ;
int V_30 ;
F_6 ( L_23 ,
type -> V_74 , V_69 , V_45 , V_46 , V_21 ,
V_47 , V_1 ) ;
V_73 = F_49 ( type , V_69 , type -> V_80 , V_12 ) ;
if ( ! F_23 ( V_73 ) ) {
V_6 = F_53 ( V_73 ) ;
if ( V_47 ) {
F_39 ( & V_47 ) ;
V_30 = F_25 ( V_47 , V_6 ) ;
F_9 ( V_47 ) ;
if ( V_30 < 0 ) {
F_9 ( V_6 ) ;
V_6 = F_58 ( V_30 ) ;
goto error;
}
}
} else if ( F_24 ( V_73 ) != - V_86 ) {
V_6 = F_61 ( V_73 ) ;
} else {
V_6 = F_58 ( - V_44 ) ;
if ( ! V_45 )
goto error;
V_6 = F_55 ( type , V_69 , V_45 ,
V_46 , V_21 , V_47 ,
V_1 ) ;
}
error:
F_34 ( L_24 , V_6 ) ;
return V_6 ;
}
int F_62 ( struct V_6 * V_6 , bool V_87 )
{
int V_30 ;
V_30 = F_63 ( & V_6 -> V_1 , V_43 ,
V_87 ? F_3 : F_1 ,
V_87 ? V_88 : V_89 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( F_32 ( V_90 , & V_6 -> V_1 ) )
return V_6 -> V_91 . V_92 ;
return F_33 ( V_6 ) ;
}
struct V_6 * V_51 ( struct V_68 * type ,
const char * V_69 ,
const char * V_45 )
{
struct V_6 * V_6 ;
T_2 V_46 = 0 ;
int V_30 ;
if ( V_45 )
V_46 = strlen ( V_45 ) ;
V_6 = F_60 ( type , V_69 , V_45 , V_46 ,
NULL , NULL , V_93 ) ;
if ( ! F_23 ( V_6 ) ) {
V_30 = F_62 ( V_6 , false ) ;
if ( V_30 < 0 ) {
F_9 ( V_6 ) ;
return F_58 ( V_30 ) ;
}
}
return V_6 ;
}
struct V_6 * F_64 ( struct V_68 * type ,
const char * V_69 ,
const void * V_45 ,
T_2 V_46 ,
void * V_21 )
{
struct V_6 * V_6 ;
int V_30 ;
V_6 = F_60 ( type , V_69 , V_45 , V_46 ,
V_21 , NULL , V_93 ) ;
if ( ! F_23 ( V_6 ) ) {
V_30 = F_62 ( V_6 , false ) ;
if ( V_30 < 0 ) {
F_9 ( V_6 ) ;
return F_58 ( V_30 ) ;
}
}
return V_6 ;
}
struct V_6 * F_65 ( struct V_68 * type ,
const char * V_69 ,
const void * V_45 ,
T_2 V_46 )
{
return F_60 ( type , V_69 , V_45 ,
V_46 , NULL , NULL ,
V_93 ) ;
}
struct V_6 * F_66 ( struct V_68 * type ,
const char * V_69 ,
const void * V_45 ,
T_2 V_46 ,
void * V_21 )
{
return F_60 ( type , V_69 , V_45 ,
V_46 , V_21 , NULL , V_93 ) ;
}
