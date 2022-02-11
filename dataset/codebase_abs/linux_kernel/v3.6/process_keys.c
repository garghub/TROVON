int F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_3 ;
struct V_4 * V_5 , * V_6 ;
char V_7 [ 20 ] ;
int V_8 ;
V_3 = F_2 () ;
V_2 = V_3 -> V_2 ;
F_3 ( L_1 , V_2 , V_2 -> V_9 ) ;
if ( V_2 -> V_5 ) {
F_4 ( L_2 ) ;
return 0 ;
}
F_5 ( & V_10 ) ;
V_8 = 0 ;
if ( ! V_2 -> V_5 ) {
sprintf ( V_7 , L_3 , V_2 -> V_9 ) ;
V_5 = F_6 ( V_7 , true ) ;
if ( F_7 ( V_5 ) ) {
V_5 = F_8 ( V_7 , V_2 -> V_9 , ( V_11 ) - 1 ,
V_3 , V_12 ,
NULL ) ;
if ( F_7 ( V_5 ) ) {
V_8 = F_9 ( V_5 ) ;
goto error;
}
}
sprintf ( V_7 , L_4 , V_2 -> V_9 ) ;
V_6 = F_6 ( V_7 , true ) ;
if ( F_7 ( V_6 ) ) {
V_6 =
F_8 ( V_7 , V_2 -> V_9 , ( V_11 ) - 1 ,
V_3 , V_12 , NULL ) ;
if ( F_7 ( V_6 ) ) {
V_8 = F_9 ( V_6 ) ;
goto V_13;
}
V_8 = F_10 ( V_6 , V_5 ) ;
if ( V_8 < 0 )
goto V_14;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
F_11 ( & V_10 ) ;
F_4 ( L_5 ) ;
return 0 ;
V_14:
F_12 ( V_6 ) ;
V_13:
F_12 ( V_5 ) ;
error:
F_11 ( & V_10 ) ;
F_4 ( L_6 , V_8 ) ;
return V_8 ;
}
int F_13 ( struct V_3 * V_15 )
{
struct V_4 * V_16 ;
V_16 = F_8 ( L_7 , V_15 -> V_9 , V_15 -> V_17 , V_15 ,
V_18 , NULL ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
V_15 -> V_19 = V_16 ;
return 0 ;
}
static int F_14 ( void )
{
struct V_3 * V_15 ;
int V_8 ;
V_15 = F_15 () ;
if ( ! V_15 )
return - V_20 ;
F_16 ( V_15 -> V_19 ) ;
V_8 = F_13 ( V_15 ) ;
if ( V_8 < 0 ) {
F_17 ( V_15 ) ;
return V_8 ;
}
return F_18 ( V_15 ) ;
}
int F_19 ( struct V_3 * V_15 )
{
struct V_4 * V_16 ;
int V_8 ;
if ( V_15 -> V_21 -> V_22 )
return - V_23 ;
V_16 = F_8 ( L_8 , V_15 -> V_9 , V_15 -> V_17 ,
V_15 , V_18 , NULL ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
F_20 ( & V_15 -> V_21 -> V_24 ) ;
if ( ! V_15 -> V_21 -> V_22 ) {
V_15 -> V_21 -> V_22 = V_16 ;
V_16 = NULL ;
V_8 = 0 ;
} else {
V_8 = - V_23 ;
}
F_21 ( & V_15 -> V_21 -> V_24 ) ;
F_12 ( V_16 ) ;
return V_8 ;
}
static int F_22 ( void )
{
struct V_3 * V_15 ;
int V_8 ;
V_15 = F_15 () ;
if ( ! V_15 )
return - V_20 ;
V_8 = F_19 ( V_15 ) ;
if ( V_8 < 0 ) {
F_17 ( V_15 ) ;
return V_8 != - V_23 ? V_8 : 0 ;
}
return F_18 ( V_15 ) ;
}
int F_23 ( struct V_3 * V_3 , struct V_4 * V_16 )
{
unsigned long V_25 ;
struct V_4 * V_26 ;
F_24 () ;
if ( ! V_16 ) {
V_25 = V_18 ;
if ( V_3 -> V_21 -> V_6 )
V_25 = V_12 ;
V_16 = F_8 ( L_9 , V_3 -> V_9 , V_3 -> V_17 ,
V_3 , V_25 , NULL ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
} else {
F_25 ( & V_16 -> V_27 ) ;
}
F_20 ( & V_3 -> V_21 -> V_24 ) ;
V_26 = V_3 -> V_21 -> V_6 ;
F_26 ( V_3 -> V_21 -> V_6 , V_16 ) ;
F_21 ( & V_3 -> V_21 -> V_24 ) ;
if ( V_26 ) {
F_27 () ;
F_12 ( V_26 ) ;
}
return 0 ;
}
static int F_28 ( struct V_4 * V_16 )
{
struct V_3 * V_15 ;
int V_8 ;
V_15 = F_15 () ;
if ( ! V_15 )
return - V_20 ;
V_8 = F_23 ( V_15 , V_16 ) ;
if ( V_8 < 0 ) {
F_17 ( V_15 ) ;
return V_8 ;
}
return F_18 ( V_15 ) ;
}
void F_29 ( struct V_28 * V_29 )
{
F_16 ( ! V_29 -> V_3 ) ;
if ( V_29 -> V_3 -> V_19 ) {
F_30 ( & V_29 -> V_3 -> V_19 -> V_30 ) ;
V_29 -> V_3 -> V_19 -> V_9 = V_29 -> V_3 -> V_31 ;
F_31 ( & V_29 -> V_3 -> V_19 -> V_30 ) ;
}
}
void F_32 ( struct V_28 * V_29 )
{
F_16 ( ! V_29 -> V_3 ) ;
if ( V_29 -> V_3 -> V_19 ) {
F_30 ( & V_29 -> V_3 -> V_19 -> V_30 ) ;
V_29 -> V_3 -> V_19 -> V_17 = V_29 -> V_3 -> V_32 ;
F_31 ( & V_29 -> V_3 -> V_19 -> V_30 ) ;
}
}
T_1 F_33 ( struct V_33 * type ,
const void * V_34 ,
T_2 V_35 ,
bool V_36 ,
const struct V_3 * V_3 )
{
T_1 V_37 , V_8 , V_38 ;
V_37 = NULL ;
V_8 = NULL ;
V_38 = F_34 ( - V_39 ) ;
if ( V_3 -> V_19 ) {
V_37 = F_35 (
F_36 ( V_3 -> V_19 , 1 ) ,
V_3 , type , V_34 , V_35 , V_36 ) ;
if ( ! F_7 ( V_37 ) )
goto V_40;
switch ( F_9 ( V_37 ) ) {
case - V_39 :
if ( V_8 )
break;
case - V_41 :
V_8 = V_37 ;
break;
default:
V_38 = V_37 ;
break;
}
}
if ( V_3 -> V_21 -> V_22 ) {
V_37 = F_35 (
F_36 ( V_3 -> V_21 -> V_22 , 1 ) ,
V_3 , type , V_34 , V_35 , V_36 ) ;
if ( ! F_7 ( V_37 ) )
goto V_40;
switch ( F_9 ( V_37 ) ) {
case - V_39 :
if ( V_8 )
break;
case - V_41 :
V_8 = V_37 ;
break;
default:
V_38 = V_37 ;
break;
}
}
if ( V_3 -> V_21 -> V_6 ) {
F_37 () ;
V_37 = F_35 (
F_36 ( F_38 (
V_3 -> V_21 -> V_6 ) ,
1 ) ,
V_3 , type , V_34 , V_35 , V_36 ) ;
F_39 () ;
if ( ! F_7 ( V_37 ) )
goto V_40;
switch ( F_9 ( V_37 ) ) {
case - V_39 :
if ( V_8 )
break;
case - V_41 :
V_8 = V_37 ;
break;
default:
V_38 = V_37 ;
break;
}
}
else if ( V_3 -> V_2 -> V_6 ) {
V_37 = F_35 (
F_36 ( V_3 -> V_2 -> V_6 , 1 ) ,
V_3 , type , V_34 , V_35 , V_36 ) ;
if ( ! F_7 ( V_37 ) )
goto V_40;
switch ( F_9 ( V_37 ) ) {
case - V_39 :
if ( V_8 )
break;
case - V_41 :
V_8 = V_37 ;
break;
default:
V_38 = V_37 ;
break;
}
}
V_37 = V_8 ? V_8 : V_38 ;
V_40:
return V_37 ;
}
T_1 F_40 ( struct V_33 * type ,
const void * V_34 ,
T_2 V_35 ,
const struct V_3 * V_3 )
{
struct V_42 * V_43 ;
T_1 V_37 , V_8 = F_34 ( - V_44 ) , V_38 ;
F_24 () ;
V_37 = F_33 ( type , V_34 , V_35 ,
false , V_3 ) ;
if ( ! F_7 ( V_37 ) )
goto V_40;
V_38 = V_37 ;
if ( V_3 -> V_42 &&
V_3 == F_2 () &&
type != & V_45
) {
F_41 ( & V_3 -> V_42 -> V_30 ) ;
if ( F_42 ( V_3 -> V_42 ) == 0 ) {
V_43 = V_3 -> V_42 -> V_46 . V_47 ;
V_37 = F_40 ( type , V_34 ,
V_35 , V_43 -> V_3 ) ;
F_43 ( & V_3 -> V_42 -> V_30 ) ;
if ( ! F_7 ( V_37 ) )
goto V_40;
V_8 = V_37 ;
} else {
F_43 ( & V_3 -> V_42 -> V_30 ) ;
}
}
if ( V_38 == F_34 ( - V_41 ) || V_8 == F_34 ( - V_41 ) )
V_37 = F_34 ( - V_41 ) ;
else if ( V_38 == F_34 ( - V_44 ) )
V_37 = V_8 ;
else
V_37 = V_38 ;
V_40:
return V_37 ;
}
int F_44 ( const struct V_4 * V_4 , const void * V_48 )
{
return V_4 == V_48 ;
}
T_1 F_45 ( T_3 V_49 , unsigned long V_50 ,
T_4 V_51 )
{
struct V_42 * V_43 ;
const struct V_3 * V_3 ;
struct V_4 * V_4 ;
T_1 V_37 , V_52 ;
int V_8 ;
V_53:
V_3 = F_46 () ;
V_37 = F_34 ( - V_41 ) ;
switch ( V_49 ) {
case V_54 :
if ( ! V_3 -> V_19 ) {
if ( ! ( V_50 & V_55 ) )
goto error;
V_8 = F_14 () ;
if ( V_8 < 0 ) {
V_37 = F_34 ( V_8 ) ;
goto error;
}
goto V_56;
}
V_4 = V_3 -> V_19 ;
F_25 ( & V_4 -> V_27 ) ;
V_37 = F_36 ( V_4 , 1 ) ;
break;
case V_57 :
if ( ! V_3 -> V_21 -> V_22 ) {
if ( ! ( V_50 & V_55 ) )
goto error;
V_8 = F_22 () ;
if ( V_8 < 0 ) {
V_37 = F_34 ( V_8 ) ;
goto error;
}
goto V_56;
}
V_4 = V_3 -> V_21 -> V_22 ;
F_25 ( & V_4 -> V_27 ) ;
V_37 = F_36 ( V_4 , 1 ) ;
break;
case V_58 :
if ( ! V_3 -> V_21 -> V_6 ) {
V_8 = F_1 () ;
if ( V_8 < 0 )
goto error;
if ( V_50 & V_55 )
V_8 = F_47 ( NULL ) ;
else
V_8 = F_28 (
V_3 -> V_2 -> V_6 ) ;
if ( V_8 < 0 )
goto error;
goto V_56;
} else if ( V_3 -> V_21 -> V_6 ==
V_3 -> V_2 -> V_6 &&
V_50 & V_55 ) {
V_8 = F_47 ( NULL ) ;
if ( V_8 < 0 )
goto error;
goto V_56;
}
F_37 () ;
V_4 = F_38 ( V_3 -> V_21 -> V_6 ) ;
F_25 ( & V_4 -> V_27 ) ;
F_39 () ;
V_37 = F_36 ( V_4 , 1 ) ;
break;
case V_59 :
if ( ! V_3 -> V_2 -> V_5 ) {
V_8 = F_1 () ;
if ( V_8 < 0 )
goto error;
}
V_4 = V_3 -> V_2 -> V_5 ;
F_25 ( & V_4 -> V_27 ) ;
V_37 = F_36 ( V_4 , 1 ) ;
break;
case V_60 :
if ( ! V_3 -> V_2 -> V_6 ) {
V_8 = F_1 () ;
if ( V_8 < 0 )
goto error;
}
V_4 = V_3 -> V_2 -> V_6 ;
F_25 ( & V_4 -> V_27 ) ;
V_37 = F_36 ( V_4 , 1 ) ;
break;
case V_61 :
V_37 = F_34 ( - V_62 ) ;
goto error;
case V_63 :
V_4 = V_3 -> V_42 ;
if ( ! V_4 )
goto error;
F_25 ( & V_4 -> V_27 ) ;
V_37 = F_36 ( V_4 , 1 ) ;
break;
case V_64 :
if ( ! V_3 -> V_42 )
goto error;
F_41 ( & V_3 -> V_42 -> V_30 ) ;
if ( F_48 ( V_65 ,
& V_3 -> V_42 -> V_25 ) ) {
V_37 = F_34 ( - V_66 ) ;
V_4 = NULL ;
} else {
V_43 = V_3 -> V_42 -> V_46 . V_47 ;
V_4 = V_43 -> V_67 ;
F_25 ( & V_4 -> V_27 ) ;
}
F_43 ( & V_3 -> V_42 -> V_30 ) ;
if ( ! V_4 )
goto error;
V_37 = F_36 ( V_4 , 1 ) ;
break;
default:
V_37 = F_34 ( - V_62 ) ;
if ( V_49 < 1 )
goto error;
V_4 = F_49 ( V_49 ) ;
if ( F_7 ( V_4 ) ) {
V_37 = F_50 ( V_4 ) ;
goto error;
}
V_37 = F_36 ( V_4 , 0 ) ;
V_52 = F_40 ( V_4 -> type , V_4 ,
F_44 ,
V_3 ) ;
if ( ! F_7 ( V_52 ) ) {
F_12 ( V_4 ) ;
V_37 = V_52 ;
}
break;
}
if ( V_50 & V_68 ) {
V_8 = 0 ;
goto error;
}
if ( ! ( V_50 & V_69 ) ) {
V_8 = F_51 ( V_4 , true ) ;
switch ( V_8 ) {
case - V_70 :
goto V_71;
default:
if ( V_51 )
goto V_71;
case 0 :
break;
}
} else if ( V_51 ) {
V_8 = F_42 ( V_4 ) ;
if ( V_8 < 0 )
goto V_71;
}
V_8 = - V_72 ;
if ( ! ( V_50 & V_69 ) &&
! F_48 ( V_73 , & V_4 -> V_25 ) )
goto V_71;
V_8 = F_52 ( V_37 , V_3 , V_51 ) ;
if ( V_8 < 0 )
goto V_71;
V_4 -> V_74 = F_53 () . V_75 ;
error:
F_54 ( V_3 ) ;
return V_37 ;
V_71:
F_55 ( V_37 ) ;
V_37 = F_34 ( V_8 ) ;
goto error;
V_56:
F_54 ( V_3 ) ;
goto V_53;
}
long F_47 ( const char * V_76 )
{
const struct V_3 * V_26 ;
struct V_3 * V_15 ;
struct V_4 * V_16 ;
long V_8 , V_77 ;
if ( ! F_56 () )
return - V_78 ;
V_15 = F_15 () ;
if ( ! V_15 )
return - V_20 ;
V_26 = F_2 () ;
if ( ! V_76 ) {
V_8 = F_23 ( V_15 , NULL ) ;
if ( V_8 < 0 )
goto error;
V_77 = V_15 -> V_21 -> V_6 -> V_77 ;
V_8 = F_18 ( V_15 ) ;
if ( V_8 == 0 )
V_8 = V_77 ;
goto V_79;
}
F_5 ( & V_80 ) ;
V_16 = F_6 ( V_76 , false ) ;
if ( F_9 ( V_16 ) == - V_41 ) {
V_16 = F_8 ( V_76 , V_26 -> V_9 , V_26 -> V_17 , V_26 ,
V_12 , NULL ) ;
if ( F_7 ( V_16 ) ) {
V_8 = F_9 ( V_16 ) ;
goto V_81;
}
} else if ( F_7 ( V_16 ) ) {
V_8 = F_9 ( V_16 ) ;
goto V_81;
}
V_8 = F_23 ( V_15 , V_16 ) ;
if ( V_8 < 0 )
goto V_81;
F_18 ( V_15 ) ;
F_11 ( & V_80 ) ;
V_8 = V_16 -> V_77 ;
F_12 ( V_16 ) ;
V_79:
return V_8 ;
V_81:
F_11 ( & V_80 ) ;
error:
F_17 ( V_15 ) ;
return V_8 ;
}
void F_57 ( struct V_82 * V_83 )
{
const struct V_3 * V_26 = F_2 () ;
struct V_3 * V_15 = F_58 ( V_83 , struct V_3 , V_84 ) ;
if ( F_59 ( V_85 -> V_25 & V_86 ) ) {
F_54 ( V_15 ) ;
return;
}
V_15 -> V_9 = V_26 -> V_9 ;
V_15 -> V_87 = V_26 -> V_87 ;
V_15 -> V_88 = V_26 -> V_88 ;
V_15 -> V_31 = V_26 -> V_31 ;
V_15 -> V_17 = V_26 -> V_17 ;
V_15 -> V_89 = V_26 -> V_89 ;
V_15 -> V_90 = V_26 -> V_90 ;
V_15 -> V_32 = V_26 -> V_32 ;
V_15 -> V_2 = F_60 ( V_26 -> V_2 ) ;
V_15 -> V_91 = F_61 ( V_15 -> V_91 ) ;
V_15 -> V_92 = F_62 ( V_26 -> V_92 ) ;
V_15 -> V_93 = V_26 -> V_93 ;
V_15 -> V_94 = V_26 -> V_94 ;
V_15 -> V_95 = V_26 -> V_95 ;
V_15 -> V_96 = V_26 -> V_96 ;
V_15 -> V_97 = V_26 -> V_97 ;
V_15 -> V_98 = V_26 -> V_98 ;
V_15 -> V_19 = F_63 ( V_26 -> V_19 ) ;
V_15 -> V_21 -> V_99 = V_26 -> V_21 -> V_99 ;
V_15 -> V_21 -> V_22 = F_63 ( V_26 -> V_21 -> V_22 ) ;
F_64 ( V_15 , V_26 ) ;
F_18 ( V_15 ) ;
}
