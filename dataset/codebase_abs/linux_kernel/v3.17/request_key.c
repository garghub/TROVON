void F_1 ( struct V_1 * V_2 , int error )
{
F_2 ( L_1 , V_2 -> V_3 -> V_4 , V_2 -> V_5 -> V_4 , error ) ;
if ( error < 0 )
F_3 ( V_2 -> V_3 , V_6 , NULL ,
V_2 -> V_5 ) ;
else
F_4 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_3 ) ;
F_5 ( V_2 -> V_5 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_3 * V_10 = V_8 -> V_11 ;
return F_8 ( V_9 , V_10 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_3 * V_10 = V_8 -> V_11 ;
F_5 ( V_10 ) ;
}
static int F_10 ( char * V_12 , char * * V_13 , char * * V_14 ,
struct V_3 * V_15 , int V_16 )
{
struct V_7 * V_8 ;
V_8 = F_11 ( V_12 , V_13 , V_14 , V_17 ,
F_7 , F_9 ,
V_15 ) ;
if ( ! V_8 )
return - V_18 ;
F_12 ( V_15 ) ;
return F_13 ( V_8 , V_16 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const char * V_19 ,
void * V_20 )
{
const struct V_9 * V_9 = F_15 () ;
T_1 V_21 , V_22 ;
struct V_3 * V_3 = V_2 -> V_3 , * V_5 = V_2 -> V_5 , * V_10 ,
* V_23 ;
char * V_13 [ 9 ] , * V_14 [ 3 ] , V_24 [ 12 ] , V_25 [ 12 ] ;
char V_26 [ 12 ] , V_27 [ 3 ] [ 12 ] ;
char V_28 [ 20 ] ;
int V_29 , V_30 ;
F_2 ( L_2 , V_3 -> V_4 , V_5 -> V_4 , V_19 ) ;
V_29 = F_16 () ;
if ( V_29 < 0 )
goto V_31;
sprintf ( V_28 , L_3 , V_3 -> V_4 ) ;
V_9 = F_17 () ;
V_10 = F_18 ( V_28 , V_9 -> V_32 , V_9 -> V_33 , V_9 ,
V_34 | V_35 | V_36 ,
V_37 , NULL ) ;
F_19 ( V_9 ) ;
if ( F_20 ( V_10 ) ) {
V_29 = F_21 ( V_10 ) ;
goto V_31;
}
V_29 = F_22 ( V_10 , V_5 ) ;
if ( V_29 < 0 )
goto V_38;
sprintf ( V_24 , L_4 , F_23 ( & V_39 , V_9 -> V_32 ) ) ;
sprintf ( V_25 , L_4 , F_24 ( & V_39 , V_9 -> V_33 ) ) ;
sprintf ( V_26 , L_4 , V_3 -> V_4 ) ;
sprintf ( V_27 [ 0 ] , L_4 ,
V_9 -> V_40 ? V_9 -> V_40 -> V_4 : 0 ) ;
V_21 = 0 ;
if ( V_9 -> V_41 )
V_21 = V_9 -> V_41 -> V_4 ;
sprintf ( V_27 [ 1 ] , L_4 , V_21 ) ;
F_25 () ;
V_23 = F_26 ( V_9 -> V_15 ) ;
if ( ! V_23 )
V_23 = V_9 -> V_42 -> V_15 ;
V_22 = V_23 -> V_4 ;
F_27 () ;
sprintf ( V_27 [ 2 ] , L_4 , V_22 ) ;
V_30 = 0 ;
V_14 [ V_30 ++ ] = L_5 ;
V_14 [ V_30 ++ ] = L_6 ;
V_14 [ V_30 ] = NULL ;
V_30 = 0 ;
V_13 [ V_30 ++ ] = L_7 ;
V_13 [ V_30 ++ ] = ( char * ) V_19 ;
V_13 [ V_30 ++ ] = V_26 ;
V_13 [ V_30 ++ ] = V_24 ;
V_13 [ V_30 ++ ] = V_25 ;
V_13 [ V_30 ++ ] = V_27 [ 0 ] ;
V_13 [ V_30 ++ ] = V_27 [ 1 ] ;
V_13 [ V_30 ++ ] = V_27 [ 2 ] ;
V_13 [ V_30 ] = NULL ;
V_29 = F_10 ( V_13 [ 0 ] , V_13 , V_14 , V_10 ,
V_43 ) ;
F_28 ( L_8 , V_29 ) ;
if ( V_29 >= 0 ) {
if ( F_29 ( V_44 , & V_3 -> V_45 ) ||
F_30 ( V_3 ) < 0 )
V_29 = - V_46 ;
else
V_29 = 0 ;
}
V_38:
F_5 ( V_10 ) ;
V_31:
F_1 ( V_2 , V_29 ) ;
F_31 ( L_9 , V_29 ) ;
return V_29 ;
}
static int F_32 ( struct V_3 * V_3 , const void * V_47 ,
T_2 V_48 , void * V_20 ,
struct V_3 * V_49 )
{
struct V_1 * V_2 ;
T_3 V_50 ;
struct V_3 * V_5 ;
int V_29 ;
F_2 ( L_10 , V_3 -> V_4 , V_47 , V_48 , V_20 ) ;
V_2 = F_33 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_5 = F_34 ( V_3 , V_47 , V_48 ,
V_49 ) ;
if ( F_20 ( V_5 ) ) {
F_6 ( V_2 ) ;
V_29 = F_21 ( V_5 ) ;
V_5 = NULL ;
} else {
V_2 -> V_5 = F_12 ( V_5 ) ;
V_2 -> V_3 = F_12 ( V_3 ) ;
V_50 = F_14 ;
if ( V_3 -> type -> V_51 )
V_50 = V_3 -> type -> V_51 ;
V_29 = V_50 ( V_2 , L_11 , V_20 ) ;
F_35 ( V_29 < 0 &&
! F_29 ( V_52 , & V_5 -> V_45 ) ) ;
F_5 ( V_5 ) ;
}
F_31 ( L_9 , V_29 ) ;
return V_29 ;
}
static void F_36 ( struct V_3 * * V_53 )
{
struct V_54 * V_55 ;
const struct V_9 * V_9 = F_15 () ;
struct V_3 * V_49 = * V_53 , * V_5 ;
F_2 ( L_12 , V_49 ) ;
if ( V_49 ) {
F_12 ( V_49 ) ;
} else {
switch ( V_9 -> V_56 ) {
case V_57 :
case V_58 :
if ( V_9 -> V_54 ) {
V_5 = V_9 -> V_54 ;
F_37 ( & V_5 -> V_59 ) ;
V_55 = V_5 -> V_60 . V_11 ;
if ( ! F_29 ( V_52 ,
& V_5 -> V_45 ) )
V_49 =
F_12 ( V_55 -> V_49 ) ;
F_38 ( & V_5 -> V_59 ) ;
if ( V_49 )
break;
}
case V_61 :
V_49 = F_12 ( V_9 -> V_40 ) ;
if ( V_49 )
break;
case V_62 :
V_49 = F_12 ( V_9 -> V_41 ) ;
if ( V_49 )
break;
case V_63 :
F_25 () ;
V_49 = F_12 (
F_26 ( V_9 -> V_15 ) ) ;
F_27 () ;
if ( V_49 )
break;
case V_64 :
V_49 =
F_12 ( V_9 -> V_42 -> V_15 ) ;
break;
case V_65 :
V_49 = F_12 ( V_9 -> V_42 -> V_66 ) ;
break;
case V_67 :
default:
F_39 () ;
}
}
* V_53 = V_49 ;
F_31 ( L_13 , F_40 ( V_49 ) ) ;
return;
}
static int F_41 ( struct V_68 * V_69 ,
struct V_3 * V_49 ,
unsigned long V_45 ,
struct V_70 * V_42 ,
struct V_3 * * V_71 )
{
struct V_72 * V_73 ;
struct V_3 * V_3 ;
T_4 V_74 ;
T_5 V_75 ;
int V_29 ;
F_2 ( L_14 ,
V_69 -> V_76 . type -> V_77 , V_69 -> V_76 . V_78 ) ;
* V_71 = NULL ;
F_42 ( & V_42 -> V_79 ) ;
V_74 = V_80 | V_81 | V_82 | V_83 ;
V_74 |= V_35 ;
if ( V_69 -> V_76 . type -> V_84 )
V_74 |= V_85 ;
if ( V_69 -> V_76 . type == & V_86 ||
V_69 -> V_76 . type -> V_87 )
V_74 |= V_88 ;
V_3 = F_43 ( V_69 -> V_76 . type , V_69 -> V_76 . V_78 ,
V_69 -> V_9 -> V_32 , V_69 -> V_9 -> V_33 , V_69 -> V_9 ,
V_74 , V_45 ) ;
if ( F_20 ( V_3 ) )
goto V_89;
F_44 ( V_44 , & V_3 -> V_45 ) ;
if ( V_49 ) {
V_29 = F_45 ( V_49 , & V_69 -> V_76 , & V_73 ) ;
if ( V_29 < 0 )
goto V_90;
}
F_42 ( & V_91 ) ;
V_75 = F_46 ( V_69 ) ;
if ( ! F_20 ( V_75 ) )
goto V_92;
if ( V_49 )
F_47 ( V_3 , & V_73 ) ;
F_48 ( & V_91 ) ;
if ( V_49 )
F_49 ( V_49 , & V_69 -> V_76 , V_73 ) ;
F_48 ( & V_42 -> V_79 ) ;
* V_71 = V_3 ;
F_31 ( L_15 , F_40 ( V_3 ) ) ;
return 0 ;
V_92:
F_5 ( V_3 ) ;
F_48 ( & V_91 ) ;
V_3 = F_50 ( V_75 ) ;
if ( V_49 ) {
V_29 = F_51 ( V_49 , V_3 ) ;
if ( V_29 == 0 )
F_47 ( V_3 , & V_73 ) ;
F_49 ( V_49 , & V_69 -> V_76 , V_73 ) ;
if ( V_29 < 0 )
goto V_93;
}
F_48 ( & V_42 -> V_79 ) ;
* V_71 = V_3 ;
F_31 ( L_16 , F_40 ( V_3 ) ) ;
return - V_94 ;
V_93:
F_48 ( & V_42 -> V_79 ) ;
F_5 ( V_3 ) ;
F_31 ( L_17 , V_29 ) ;
return V_29 ;
V_90:
F_48 ( & V_42 -> V_79 ) ;
F_31 ( L_18 , V_29 ) ;
return V_29 ;
V_89:
F_48 ( & V_42 -> V_79 ) ;
F_31 ( L_19 , F_21 ( V_3 ) ) ;
return F_21 ( V_3 ) ;
}
static struct V_3 * F_52 ( struct V_68 * V_69 ,
const char * V_47 ,
T_2 V_48 ,
void * V_20 ,
struct V_3 * V_49 ,
unsigned long V_45 )
{
struct V_70 * V_42 ;
struct V_3 * V_3 ;
int V_29 ;
F_2 ( L_20 ) ;
V_42 = F_53 ( F_54 () ) ;
if ( ! V_42 )
return F_55 ( - V_18 ) ;
F_36 ( & V_49 ) ;
V_29 = F_41 ( V_69 , V_49 , V_45 , V_42 , & V_3 ) ;
F_56 ( V_42 ) ;
if ( V_29 == 0 ) {
V_29 = F_32 ( V_3 , V_47 , V_48 , V_20 ,
V_49 ) ;
if ( V_29 < 0 ) {
F_28 ( L_21 ) ;
goto V_95;
}
} else if ( V_29 == - V_94 ) {
V_29 = 0 ;
} else {
goto V_96;
}
F_5 ( V_49 ) ;
F_31 ( L_22 , F_40 ( V_3 ) ) ;
return V_3 ;
V_95:
F_3 ( V_3 , V_6 , NULL , NULL ) ;
F_5 ( V_3 ) ;
V_96:
F_5 ( V_49 ) ;
F_31 ( L_9 , V_29 ) ;
return F_55 ( V_29 ) ;
}
struct V_3 * F_57 ( struct V_97 * type ,
const char * V_78 ,
const void * V_47 ,
T_2 V_48 ,
void * V_20 ,
struct V_3 * V_49 ,
unsigned long V_45 )
{
struct V_68 V_69 = {
. V_76 . type = type ,
. V_76 . V_78 = V_78 ,
. V_9 = F_15 () ,
. V_98 = type -> V_98 ,
. V_99 = V_78 ,
. V_45 = V_100 ,
} ;
struct V_3 * V_3 ;
T_5 V_75 ;
int V_29 ;
F_2 ( L_23 ,
V_69 . V_76 . type -> V_77 , V_69 . V_76 . V_78 ,
V_47 , V_48 , V_20 , V_49 , V_45 ) ;
V_75 = F_46 ( & V_69 ) ;
if ( ! F_20 ( V_75 ) ) {
V_3 = F_50 ( V_75 ) ;
if ( V_49 ) {
F_36 ( & V_49 ) ;
V_29 = F_22 ( V_49 , V_3 ) ;
F_5 ( V_49 ) ;
if ( V_29 < 0 ) {
F_5 ( V_3 ) ;
V_3 = F_55 ( V_29 ) ;
goto error;
}
}
} else if ( F_21 ( V_75 ) != - V_101 ) {
V_3 = F_58 ( V_75 ) ;
} else {
V_3 = F_55 ( - V_46 ) ;
if ( ! V_47 )
goto error;
V_3 = F_52 ( & V_69 , V_47 , V_48 ,
V_20 , V_49 , V_45 ) ;
}
error:
F_31 ( L_24 , V_3 ) ;
return V_3 ;
}
int F_59 ( struct V_3 * V_3 , bool V_102 )
{
int V_29 ;
V_29 = F_60 ( & V_3 -> V_45 , V_44 ,
V_102 ? V_103 : V_104 ) ;
if ( V_29 )
return - V_105 ;
if ( F_29 ( V_106 , & V_3 -> V_45 ) ) {
F_61 () ;
return V_3 -> V_107 . V_108 ;
}
return F_30 ( V_3 ) ;
}
struct V_3 * V_51 ( struct V_97 * type ,
const char * V_78 ,
const char * V_47 )
{
struct V_3 * V_3 ;
T_2 V_48 = 0 ;
int V_29 ;
if ( V_47 )
V_48 = strlen ( V_47 ) ;
V_3 = F_57 ( type , V_78 , V_47 , V_48 ,
NULL , NULL , V_109 ) ;
if ( ! F_20 ( V_3 ) ) {
V_29 = F_59 ( V_3 , false ) ;
if ( V_29 < 0 ) {
F_5 ( V_3 ) ;
return F_55 ( V_29 ) ;
}
}
return V_3 ;
}
struct V_3 * F_62 ( struct V_97 * type ,
const char * V_78 ,
const void * V_47 ,
T_2 V_48 ,
void * V_20 )
{
struct V_3 * V_3 ;
int V_29 ;
V_3 = F_57 ( type , V_78 , V_47 , V_48 ,
V_20 , NULL , V_109 ) ;
if ( ! F_20 ( V_3 ) ) {
V_29 = F_59 ( V_3 , false ) ;
if ( V_29 < 0 ) {
F_5 ( V_3 ) ;
return F_55 ( V_29 ) ;
}
}
return V_3 ;
}
struct V_3 * F_63 ( struct V_97 * type ,
const char * V_78 ,
const void * V_47 ,
T_2 V_48 )
{
return F_57 ( type , V_78 , V_47 ,
V_48 , NULL , NULL ,
V_109 ) ;
}
struct V_3 * F_64 ( struct V_97 * type ,
const char * V_78 ,
const void * V_47 ,
T_2 V_48 ,
void * V_20 )
{
return F_57 ( type , V_78 , V_47 ,
V_48 , V_20 , NULL , V_109 ) ;
}
