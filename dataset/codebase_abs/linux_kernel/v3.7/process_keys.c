int F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_3 ;
struct V_4 * V_5 , * V_6 ;
char V_7 [ 20 ] ;
int V_8 ;
T_1 V_9 ;
V_3 = F_2 () ;
V_2 = V_3 -> V_2 ;
V_9 = F_3 ( V_3 -> V_10 , V_2 -> V_9 ) ;
F_4 ( L_1 , V_2 , V_9 ) ;
if ( V_2 -> V_5 ) {
F_5 ( L_2 ) ;
return 0 ;
}
F_6 ( & V_11 ) ;
V_8 = 0 ;
if ( ! V_2 -> V_5 ) {
sprintf ( V_7 , L_3 , V_9 ) ;
V_5 = F_7 ( V_7 , true ) ;
if ( F_8 ( V_5 ) ) {
V_5 = F_9 ( V_7 , V_2 -> V_9 , V_12 ,
V_3 , V_13 ,
NULL ) ;
if ( F_8 ( V_5 ) ) {
V_8 = F_10 ( V_5 ) ;
goto error;
}
}
sprintf ( V_7 , L_4 , V_9 ) ;
V_6 = F_7 ( V_7 , true ) ;
if ( F_8 ( V_6 ) ) {
V_6 =
F_9 ( V_7 , V_2 -> V_9 , V_12 ,
V_3 , V_13 , NULL ) ;
if ( F_8 ( V_6 ) ) {
V_8 = F_10 ( V_6 ) ;
goto V_14;
}
V_8 = F_11 ( V_6 , V_5 ) ;
if ( V_8 < 0 )
goto V_15;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
F_12 ( & V_11 ) ;
F_5 ( L_5 ) ;
return 0 ;
V_15:
F_13 ( V_6 ) ;
V_14:
F_13 ( V_5 ) ;
error:
F_12 ( & V_11 ) ;
F_5 ( L_6 , V_8 ) ;
return V_8 ;
}
int F_14 ( struct V_3 * V_16 )
{
struct V_4 * V_17 ;
V_17 = F_9 ( L_7 , V_16 -> V_9 , V_16 -> V_18 , V_16 ,
V_19 , NULL ) ;
if ( F_8 ( V_17 ) )
return F_10 ( V_17 ) ;
V_16 -> V_20 = V_17 ;
return 0 ;
}
static int F_15 ( void )
{
struct V_3 * V_16 ;
int V_8 ;
V_16 = F_16 () ;
if ( ! V_16 )
return - V_21 ;
F_17 ( V_16 -> V_20 ) ;
V_8 = F_14 ( V_16 ) ;
if ( V_8 < 0 ) {
F_18 ( V_16 ) ;
return V_8 ;
}
return F_19 ( V_16 ) ;
}
int F_20 ( struct V_3 * V_16 )
{
struct V_4 * V_17 ;
int V_8 ;
if ( V_16 -> V_22 -> V_23 )
return - V_24 ;
V_17 = F_9 ( L_8 , V_16 -> V_9 , V_16 -> V_18 ,
V_16 , V_19 , NULL ) ;
if ( F_8 ( V_17 ) )
return F_10 ( V_17 ) ;
F_21 ( & V_16 -> V_22 -> V_25 ) ;
if ( ! V_16 -> V_22 -> V_23 ) {
V_16 -> V_22 -> V_23 = V_17 ;
V_17 = NULL ;
V_8 = 0 ;
} else {
V_8 = - V_24 ;
}
F_22 ( & V_16 -> V_22 -> V_25 ) ;
F_13 ( V_17 ) ;
return V_8 ;
}
static int F_23 ( void )
{
struct V_3 * V_16 ;
int V_8 ;
V_16 = F_16 () ;
if ( ! V_16 )
return - V_21 ;
V_8 = F_20 ( V_16 ) ;
if ( V_8 < 0 ) {
F_18 ( V_16 ) ;
return V_8 != - V_24 ? V_8 : 0 ;
}
return F_19 ( V_16 ) ;
}
int F_24 ( struct V_3 * V_3 , struct V_4 * V_17 )
{
unsigned long V_26 ;
struct V_4 * V_27 ;
F_25 () ;
if ( ! V_17 ) {
V_26 = V_19 ;
if ( V_3 -> V_22 -> V_6 )
V_26 = V_13 ;
V_17 = F_9 ( L_9 , V_3 -> V_9 , V_3 -> V_18 ,
V_3 , V_26 , NULL ) ;
if ( F_8 ( V_17 ) )
return F_10 ( V_17 ) ;
} else {
F_26 ( & V_17 -> V_28 ) ;
}
F_21 ( & V_3 -> V_22 -> V_25 ) ;
V_27 = V_3 -> V_22 -> V_6 ;
F_27 ( V_3 -> V_22 -> V_6 , V_17 ) ;
F_22 ( & V_3 -> V_22 -> V_25 ) ;
if ( V_27 ) {
F_28 () ;
F_13 ( V_27 ) ;
}
return 0 ;
}
static int F_29 ( struct V_4 * V_17 )
{
struct V_3 * V_16 ;
int V_8 ;
V_16 = F_16 () ;
if ( ! V_16 )
return - V_21 ;
V_8 = F_24 ( V_16 , V_17 ) ;
if ( V_8 < 0 ) {
F_18 ( V_16 ) ;
return V_8 ;
}
return F_19 ( V_16 ) ;
}
void F_30 ( struct V_29 * V_30 )
{
F_17 ( ! V_30 -> V_3 ) ;
if ( V_30 -> V_3 -> V_20 ) {
F_31 ( & V_30 -> V_3 -> V_20 -> V_31 ) ;
V_30 -> V_3 -> V_20 -> V_9 = V_30 -> V_3 -> V_32 ;
F_32 ( & V_30 -> V_3 -> V_20 -> V_31 ) ;
}
}
void F_33 ( struct V_29 * V_30 )
{
F_17 ( ! V_30 -> V_3 ) ;
if ( V_30 -> V_3 -> V_20 ) {
F_31 ( & V_30 -> V_3 -> V_20 -> V_31 ) ;
V_30 -> V_3 -> V_20 -> V_18 = V_30 -> V_3 -> V_33 ;
F_32 ( & V_30 -> V_3 -> V_20 -> V_31 ) ;
}
}
T_2 F_34 ( struct V_34 * type ,
const void * V_35 ,
T_3 V_36 ,
bool V_37 ,
const struct V_3 * V_3 )
{
T_2 V_38 , V_8 , V_39 ;
V_38 = NULL ;
V_8 = NULL ;
V_39 = F_35 ( - V_40 ) ;
if ( V_3 -> V_20 ) {
V_38 = F_36 (
F_37 ( V_3 -> V_20 , 1 ) ,
V_3 , type , V_35 , V_36 , V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_8 )
break;
case - V_42 :
V_8 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
if ( V_3 -> V_22 -> V_23 ) {
V_38 = F_36 (
F_37 ( V_3 -> V_22 -> V_23 , 1 ) ,
V_3 , type , V_35 , V_36 , V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_8 )
break;
case - V_42 :
V_8 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
if ( V_3 -> V_22 -> V_6 ) {
F_38 () ;
V_38 = F_36 (
F_37 ( F_39 (
V_3 -> V_22 -> V_6 ) ,
1 ) ,
V_3 , type , V_35 , V_36 , V_37 ) ;
F_40 () ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_8 )
break;
case - V_42 :
V_8 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
else if ( V_3 -> V_2 -> V_6 ) {
V_38 = F_36 (
F_37 ( V_3 -> V_2 -> V_6 , 1 ) ,
V_3 , type , V_35 , V_36 , V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_8 )
break;
case - V_42 :
V_8 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
V_38 = V_8 ? V_8 : V_39 ;
V_41:
return V_38 ;
}
T_2 F_41 ( struct V_34 * type ,
const void * V_35 ,
T_3 V_36 ,
const struct V_3 * V_3 )
{
struct V_43 * V_44 ;
T_2 V_38 , V_8 = F_35 ( - V_45 ) , V_39 ;
F_25 () ;
V_38 = F_34 ( type , V_35 , V_36 ,
false , V_3 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
V_39 = V_38 ;
if ( V_3 -> V_43 &&
V_3 == F_2 () &&
type != & V_46
) {
F_42 ( & V_3 -> V_43 -> V_31 ) ;
if ( F_43 ( V_3 -> V_43 ) == 0 ) {
V_44 = V_3 -> V_43 -> V_47 . V_48 ;
V_38 = F_41 ( type , V_35 ,
V_36 , V_44 -> V_3 ) ;
F_44 ( & V_3 -> V_43 -> V_31 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
V_8 = V_38 ;
} else {
F_44 ( & V_3 -> V_43 -> V_31 ) ;
}
}
if ( V_39 == F_35 ( - V_42 ) || V_8 == F_35 ( - V_42 ) )
V_38 = F_35 ( - V_42 ) ;
else if ( V_39 == F_35 ( - V_45 ) )
V_38 = V_8 ;
else
V_38 = V_39 ;
V_41:
return V_38 ;
}
int F_45 ( const struct V_4 * V_4 , const void * V_49 )
{
return V_4 == V_49 ;
}
T_2 F_46 ( T_4 V_50 , unsigned long V_51 ,
T_5 V_52 )
{
struct V_43 * V_44 ;
const struct V_3 * V_3 ;
struct V_4 * V_4 ;
T_2 V_38 , V_53 ;
int V_8 ;
V_54:
V_3 = F_47 () ;
V_38 = F_35 ( - V_42 ) ;
switch ( V_50 ) {
case V_55 :
if ( ! V_3 -> V_20 ) {
if ( ! ( V_51 & V_56 ) )
goto error;
V_8 = F_15 () ;
if ( V_8 < 0 ) {
V_38 = F_35 ( V_8 ) ;
goto error;
}
goto V_57;
}
V_4 = V_3 -> V_20 ;
F_26 ( & V_4 -> V_28 ) ;
V_38 = F_37 ( V_4 , 1 ) ;
break;
case V_58 :
if ( ! V_3 -> V_22 -> V_23 ) {
if ( ! ( V_51 & V_56 ) )
goto error;
V_8 = F_23 () ;
if ( V_8 < 0 ) {
V_38 = F_35 ( V_8 ) ;
goto error;
}
goto V_57;
}
V_4 = V_3 -> V_22 -> V_23 ;
F_26 ( & V_4 -> V_28 ) ;
V_38 = F_37 ( V_4 , 1 ) ;
break;
case V_59 :
if ( ! V_3 -> V_22 -> V_6 ) {
V_8 = F_1 () ;
if ( V_8 < 0 )
goto error;
if ( V_51 & V_56 )
V_8 = F_48 ( NULL ) ;
else
V_8 = F_29 (
V_3 -> V_2 -> V_6 ) ;
if ( V_8 < 0 )
goto error;
goto V_57;
} else if ( V_3 -> V_22 -> V_6 ==
V_3 -> V_2 -> V_6 &&
V_51 & V_56 ) {
V_8 = F_48 ( NULL ) ;
if ( V_8 < 0 )
goto error;
goto V_57;
}
F_38 () ;
V_4 = F_39 ( V_3 -> V_22 -> V_6 ) ;
F_26 ( & V_4 -> V_28 ) ;
F_40 () ;
V_38 = F_37 ( V_4 , 1 ) ;
break;
case V_60 :
if ( ! V_3 -> V_2 -> V_5 ) {
V_8 = F_1 () ;
if ( V_8 < 0 )
goto error;
}
V_4 = V_3 -> V_2 -> V_5 ;
F_26 ( & V_4 -> V_28 ) ;
V_38 = F_37 ( V_4 , 1 ) ;
break;
case V_61 :
if ( ! V_3 -> V_2 -> V_6 ) {
V_8 = F_1 () ;
if ( V_8 < 0 )
goto error;
}
V_4 = V_3 -> V_2 -> V_6 ;
F_26 ( & V_4 -> V_28 ) ;
V_38 = F_37 ( V_4 , 1 ) ;
break;
case V_62 :
V_38 = F_35 ( - V_63 ) ;
goto error;
case V_64 :
V_4 = V_3 -> V_43 ;
if ( ! V_4 )
goto error;
F_26 ( & V_4 -> V_28 ) ;
V_38 = F_37 ( V_4 , 1 ) ;
break;
case V_65 :
if ( ! V_3 -> V_43 )
goto error;
F_42 ( & V_3 -> V_43 -> V_31 ) ;
if ( F_49 ( V_66 ,
& V_3 -> V_43 -> V_26 ) ) {
V_38 = F_35 ( - V_67 ) ;
V_4 = NULL ;
} else {
V_44 = V_3 -> V_43 -> V_47 . V_48 ;
V_4 = V_44 -> V_68 ;
F_26 ( & V_4 -> V_28 ) ;
}
F_44 ( & V_3 -> V_43 -> V_31 ) ;
if ( ! V_4 )
goto error;
V_38 = F_37 ( V_4 , 1 ) ;
break;
default:
V_38 = F_35 ( - V_63 ) ;
if ( V_50 < 1 )
goto error;
V_4 = F_50 ( V_50 ) ;
if ( F_8 ( V_4 ) ) {
V_38 = F_51 ( V_4 ) ;
goto error;
}
V_38 = F_37 ( V_4 , 0 ) ;
V_53 = F_41 ( V_4 -> type , V_4 ,
F_45 ,
V_3 ) ;
if ( ! F_8 ( V_53 ) ) {
F_13 ( V_4 ) ;
V_38 = V_53 ;
}
break;
}
if ( V_51 & V_69 ) {
V_8 = 0 ;
goto error;
}
if ( ! ( V_51 & V_70 ) ) {
V_8 = F_52 ( V_4 , true ) ;
switch ( V_8 ) {
case - V_71 :
goto V_72;
default:
if ( V_52 )
goto V_72;
case 0 :
break;
}
} else if ( V_52 ) {
V_8 = F_43 ( V_4 ) ;
if ( V_8 < 0 )
goto V_72;
}
V_8 = - V_73 ;
if ( ! ( V_51 & V_70 ) &&
! F_49 ( V_74 , & V_4 -> V_26 ) )
goto V_72;
V_8 = F_53 ( V_38 , V_3 , V_52 ) ;
if ( V_8 < 0 )
goto V_72;
V_4 -> V_75 = F_54 () . V_76 ;
error:
F_55 ( V_3 ) ;
return V_38 ;
V_72:
F_56 ( V_38 ) ;
V_38 = F_35 ( V_8 ) ;
goto error;
V_57:
F_55 ( V_3 ) ;
goto V_54;
}
long F_48 ( const char * V_77 )
{
const struct V_3 * V_27 ;
struct V_3 * V_16 ;
struct V_4 * V_17 ;
long V_8 , V_78 ;
if ( ! F_57 () )
return - V_79 ;
V_16 = F_16 () ;
if ( ! V_16 )
return - V_21 ;
V_27 = F_2 () ;
if ( ! V_77 ) {
V_8 = F_24 ( V_16 , NULL ) ;
if ( V_8 < 0 )
goto error;
V_78 = V_16 -> V_22 -> V_6 -> V_78 ;
V_8 = F_19 ( V_16 ) ;
if ( V_8 == 0 )
V_8 = V_78 ;
goto V_80;
}
F_6 ( & V_81 ) ;
V_17 = F_7 ( V_77 , false ) ;
if ( F_10 ( V_17 ) == - V_42 ) {
V_17 = F_9 ( V_77 , V_27 -> V_9 , V_27 -> V_18 , V_27 ,
V_13 , NULL ) ;
if ( F_8 ( V_17 ) ) {
V_8 = F_10 ( V_17 ) ;
goto V_82;
}
} else if ( F_8 ( V_17 ) ) {
V_8 = F_10 ( V_17 ) ;
goto V_82;
}
V_8 = F_24 ( V_16 , V_17 ) ;
if ( V_8 < 0 )
goto V_82;
F_19 ( V_16 ) ;
F_12 ( & V_81 ) ;
V_8 = V_17 -> V_78 ;
F_13 ( V_17 ) ;
V_80:
return V_8 ;
V_82:
F_12 ( & V_81 ) ;
error:
F_18 ( V_16 ) ;
return V_8 ;
}
void F_58 ( struct V_83 * V_84 )
{
const struct V_3 * V_27 = F_2 () ;
struct V_3 * V_16 = F_59 ( V_84 , struct V_3 , V_85 ) ;
if ( F_60 ( V_86 -> V_26 & V_87 ) ) {
F_55 ( V_16 ) ;
return;
}
V_16 -> V_9 = V_27 -> V_9 ;
V_16 -> V_88 = V_27 -> V_88 ;
V_16 -> V_89 = V_27 -> V_89 ;
V_16 -> V_32 = V_27 -> V_32 ;
V_16 -> V_18 = V_27 -> V_18 ;
V_16 -> V_90 = V_27 -> V_90 ;
V_16 -> V_91 = V_27 -> V_91 ;
V_16 -> V_33 = V_27 -> V_33 ;
V_16 -> V_2 = F_61 ( V_27 -> V_2 ) ;
V_16 -> V_10 = F_62 ( V_16 -> V_10 ) ;
V_16 -> V_92 = F_63 ( V_27 -> V_92 ) ;
V_16 -> V_93 = V_27 -> V_93 ;
V_16 -> V_94 = V_27 -> V_94 ;
V_16 -> V_95 = V_27 -> V_95 ;
V_16 -> V_96 = V_27 -> V_96 ;
V_16 -> V_97 = V_27 -> V_97 ;
V_16 -> V_98 = V_27 -> V_98 ;
V_16 -> V_20 = F_64 ( V_27 -> V_20 ) ;
V_16 -> V_22 -> V_99 = V_27 -> V_22 -> V_99 ;
V_16 -> V_22 -> V_23 = F_64 ( V_27 -> V_22 -> V_23 ) ;
F_65 ( V_16 , V_27 ) ;
F_19 ( V_16 ) ;
}
