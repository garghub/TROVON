int F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_3 ;
struct V_4 * V_5 , * V_6 ;
T_1 V_7 ;
char V_8 [ 20 ] ;
int V_9 ;
T_2 V_10 ;
V_7 = ( V_11 & ~ V_12 ) | V_13 ;
V_3 = F_2 () ;
V_2 = V_3 -> V_2 ;
V_10 = F_3 ( V_3 -> V_14 , V_2 -> V_10 ) ;
F_4 ( L_1 , V_2 , V_10 ) ;
if ( V_2 -> V_5 && V_2 -> V_6 ) {
F_5 ( L_2 ) ;
return 0 ;
}
F_6 ( & V_15 ) ;
V_9 = 0 ;
if ( ! V_2 -> V_5 ) {
sprintf ( V_8 , L_3 , V_10 ) ;
V_5 = F_7 ( V_8 , true ) ;
if ( F_8 ( V_5 ) ) {
V_5 = F_9 ( V_8 , V_2 -> V_10 , V_16 ,
V_3 , V_7 ,
V_17 , NULL ) ;
if ( F_8 ( V_5 ) ) {
V_9 = F_10 ( V_5 ) ;
goto error;
}
}
sprintf ( V_8 , L_4 , V_10 ) ;
V_6 = F_7 ( V_8 , true ) ;
if ( F_8 ( V_6 ) ) {
V_6 =
F_9 ( V_8 , V_2 -> V_10 , V_16 ,
V_3 , V_7 ,
V_17 , NULL ) ;
if ( F_8 ( V_6 ) ) {
V_9 = F_10 ( V_6 ) ;
goto V_18;
}
V_9 = F_11 ( V_6 , V_5 ) ;
if ( V_9 < 0 )
goto V_19;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
F_12 ( & V_15 ) ;
F_5 ( L_5 ) ;
return 0 ;
V_19:
F_13 ( V_6 ) ;
V_18:
F_13 ( V_5 ) ;
error:
F_12 ( & V_15 ) ;
F_5 ( L_6 , V_9 ) ;
return V_9 ;
}
int F_14 ( struct V_3 * V_20 )
{
struct V_4 * V_21 ;
V_21 = F_9 ( L_7 , V_20 -> V_10 , V_20 -> V_22 , V_20 ,
V_11 | V_23 ,
V_24 , NULL ) ;
if ( F_8 ( V_21 ) )
return F_10 ( V_21 ) ;
V_20 -> V_25 = V_21 ;
return 0 ;
}
static int F_15 ( void )
{
struct V_3 * V_20 ;
int V_9 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
F_17 ( V_20 -> V_25 ) ;
V_9 = F_14 ( V_20 ) ;
if ( V_9 < 0 ) {
F_18 ( V_20 ) ;
return V_9 ;
}
return F_19 ( V_20 ) ;
}
int F_20 ( struct V_3 * V_20 )
{
struct V_4 * V_21 ;
if ( V_20 -> V_27 )
return - V_28 ;
V_21 = F_9 ( L_8 , V_20 -> V_10 , V_20 -> V_22 , V_20 ,
V_11 | V_23 ,
V_24 , NULL ) ;
if ( F_8 ( V_21 ) )
return F_10 ( V_21 ) ;
V_20 -> V_27 = V_21 ;
return 0 ;
}
static int F_21 ( void )
{
struct V_3 * V_20 ;
int V_9 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_9 = F_20 ( V_20 ) ;
if ( V_9 < 0 ) {
F_18 ( V_20 ) ;
return V_9 != - V_28 ? V_9 : 0 ;
}
return F_19 ( V_20 ) ;
}
int F_22 ( struct V_3 * V_3 , struct V_4 * V_21 )
{
unsigned long V_29 ;
struct V_4 * V_30 ;
F_23 () ;
if ( ! V_21 ) {
V_29 = V_24 ;
if ( V_3 -> V_6 )
V_29 = V_17 ;
V_21 = F_9 ( L_9 , V_3 -> V_10 , V_3 -> V_22 , V_3 ,
V_11 | V_23 | V_31 ,
V_29 , NULL ) ;
if ( F_8 ( V_21 ) )
return F_10 ( V_21 ) ;
} else {
F_24 ( & V_21 -> V_32 ) ;
}
V_30 = V_3 -> V_6 ;
F_25 ( V_3 -> V_6 , V_21 ) ;
if ( V_30 )
F_13 ( V_30 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_21 )
{
struct V_3 * V_20 ;
int V_9 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_9 = F_22 ( V_20 , V_21 ) ;
if ( V_9 < 0 ) {
F_18 ( V_20 ) ;
return V_9 ;
}
return F_19 ( V_20 ) ;
}
void F_27 ( struct V_33 * V_34 )
{
F_17 ( ! V_34 -> V_3 ) ;
if ( V_34 -> V_3 -> V_25 ) {
F_28 ( & V_34 -> V_3 -> V_25 -> V_35 ) ;
V_34 -> V_3 -> V_25 -> V_10 = V_34 -> V_3 -> V_36 ;
F_29 ( & V_34 -> V_3 -> V_25 -> V_35 ) ;
}
}
void F_30 ( struct V_33 * V_34 )
{
F_17 ( ! V_34 -> V_3 ) ;
if ( V_34 -> V_3 -> V_25 ) {
F_28 ( & V_34 -> V_3 -> V_25 -> V_35 ) ;
V_34 -> V_3 -> V_25 -> V_22 = V_34 -> V_3 -> V_37 ;
F_29 ( & V_34 -> V_3 -> V_25 -> V_35 ) ;
}
}
T_3 F_31 ( struct V_38 * type ,
const void * V_39 ,
T_4 V_40 ,
bool V_41 ,
const struct V_3 * V_3 )
{
T_3 V_42 , V_9 , V_43 ;
V_42 = NULL ;
V_9 = NULL ;
V_43 = F_32 ( - V_44 ) ;
if ( V_3 -> V_25 ) {
V_42 = F_33 (
F_34 ( V_3 -> V_25 , 1 ) ,
V_3 , type , V_39 , V_40 , V_41 ) ;
if ( ! F_8 ( V_42 ) )
goto V_45;
switch ( F_10 ( V_42 ) ) {
case - V_44 :
case - V_46 :
V_9 = V_42 ;
break;
default:
V_43 = V_42 ;
break;
}
}
if ( V_3 -> V_27 ) {
V_42 = F_33 (
F_34 ( V_3 -> V_27 , 1 ) ,
V_3 , type , V_39 , V_40 , V_41 ) ;
if ( ! F_8 ( V_42 ) )
goto V_45;
switch ( F_10 ( V_42 ) ) {
case - V_44 :
if ( V_9 )
break;
case - V_46 :
V_9 = V_42 ;
break;
default:
V_43 = V_42 ;
break;
}
}
if ( V_3 -> V_6 ) {
F_35 () ;
V_42 = F_33 (
F_34 ( F_36 ( V_3 -> V_6 ) , 1 ) ,
V_3 , type , V_39 , V_40 , V_41 ) ;
F_37 () ;
if ( ! F_8 ( V_42 ) )
goto V_45;
switch ( F_10 ( V_42 ) ) {
case - V_44 :
if ( V_9 )
break;
case - V_46 :
V_9 = V_42 ;
break;
default:
V_43 = V_42 ;
break;
}
}
else if ( V_3 -> V_2 -> V_6 ) {
V_42 = F_33 (
F_34 ( V_3 -> V_2 -> V_6 , 1 ) ,
V_3 , type , V_39 , V_40 , V_41 ) ;
if ( ! F_8 ( V_42 ) )
goto V_45;
switch ( F_10 ( V_42 ) ) {
case - V_44 :
if ( V_9 )
break;
case - V_46 :
V_9 = V_42 ;
break;
default:
V_43 = V_42 ;
break;
}
}
V_42 = V_9 ? V_9 : V_43 ;
V_45:
return V_42 ;
}
T_3 F_38 ( struct V_38 * type ,
const void * V_39 ,
T_4 V_40 ,
const struct V_3 * V_3 )
{
struct V_47 * V_48 ;
T_3 V_42 , V_9 = F_32 ( - V_49 ) , V_43 ;
F_23 () ;
V_42 = F_31 ( type , V_39 , V_40 ,
false , V_3 ) ;
if ( ! F_8 ( V_42 ) )
goto V_45;
V_43 = V_42 ;
if ( V_3 -> V_47 &&
V_3 == F_2 () &&
type != & V_50
) {
F_39 ( & V_3 -> V_47 -> V_35 ) ;
if ( F_40 ( V_3 -> V_47 ) == 0 ) {
V_48 = V_3 -> V_47 -> V_51 . V_52 ;
V_42 = F_38 ( type , V_39 ,
V_40 , V_48 -> V_3 ) ;
F_41 ( & V_3 -> V_47 -> V_35 ) ;
if ( ! F_8 ( V_42 ) )
goto V_45;
V_9 = V_42 ;
} else {
F_41 ( & V_3 -> V_47 -> V_35 ) ;
}
}
if ( V_43 == F_32 ( - V_46 ) || V_9 == F_32 ( - V_46 ) )
V_42 = F_32 ( - V_46 ) ;
else if ( V_43 == F_32 ( - V_49 ) )
V_42 = V_9 ;
else
V_42 = V_43 ;
V_45:
return V_42 ;
}
int F_42 ( const struct V_4 * V_4 , const void * V_53 )
{
return V_4 == V_53 ;
}
T_3 F_43 ( T_5 V_54 , unsigned long V_55 ,
T_1 V_56 )
{
struct V_47 * V_48 ;
const struct V_3 * V_3 ;
struct V_4 * V_4 ;
T_3 V_42 , V_57 ;
int V_9 ;
V_58:
V_3 = F_44 () ;
V_42 = F_32 ( - V_46 ) ;
switch ( V_54 ) {
case V_59 :
if ( ! V_3 -> V_25 ) {
if ( ! ( V_55 & V_60 ) )
goto error;
V_9 = F_15 () ;
if ( V_9 < 0 ) {
V_42 = F_32 ( V_9 ) ;
goto error;
}
goto V_61;
}
V_4 = V_3 -> V_25 ;
F_24 ( & V_4 -> V_32 ) ;
V_42 = F_34 ( V_4 , 1 ) ;
break;
case V_62 :
if ( ! V_3 -> V_27 ) {
if ( ! ( V_55 & V_60 ) )
goto error;
V_9 = F_21 () ;
if ( V_9 < 0 ) {
V_42 = F_32 ( V_9 ) ;
goto error;
}
goto V_61;
}
V_4 = V_3 -> V_27 ;
F_24 ( & V_4 -> V_32 ) ;
V_42 = F_34 ( V_4 , 1 ) ;
break;
case V_63 :
if ( ! V_3 -> V_6 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
if ( V_55 & V_60 )
V_9 = F_45 ( NULL ) ;
else
V_9 = F_26 (
V_3 -> V_2 -> V_6 ) ;
if ( V_9 < 0 )
goto error;
goto V_61;
} else if ( V_3 -> V_6 ==
V_3 -> V_2 -> V_6 &&
V_55 & V_60 ) {
V_9 = F_45 ( NULL ) ;
if ( V_9 < 0 )
goto error;
goto V_61;
}
F_35 () ;
V_4 = F_36 ( V_3 -> V_6 ) ;
F_24 ( & V_4 -> V_32 ) ;
F_37 () ;
V_42 = F_34 ( V_4 , 1 ) ;
break;
case V_64 :
if ( ! V_3 -> V_2 -> V_5 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
}
V_4 = V_3 -> V_2 -> V_5 ;
F_24 ( & V_4 -> V_32 ) ;
V_42 = F_34 ( V_4 , 1 ) ;
break;
case V_65 :
if ( ! V_3 -> V_2 -> V_6 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
}
V_4 = V_3 -> V_2 -> V_6 ;
F_24 ( & V_4 -> V_32 ) ;
V_42 = F_34 ( V_4 , 1 ) ;
break;
case V_66 :
V_42 = F_32 ( - V_67 ) ;
goto error;
case V_68 :
V_4 = V_3 -> V_47 ;
if ( ! V_4 )
goto error;
F_24 ( & V_4 -> V_32 ) ;
V_42 = F_34 ( V_4 , 1 ) ;
break;
case V_69 :
if ( ! V_3 -> V_47 )
goto error;
F_39 ( & V_3 -> V_47 -> V_35 ) ;
if ( F_46 ( V_70 ,
& V_3 -> V_47 -> V_29 ) ) {
V_42 = F_32 ( - V_71 ) ;
V_4 = NULL ;
} else {
V_48 = V_3 -> V_47 -> V_51 . V_52 ;
V_4 = V_48 -> V_72 ;
F_24 ( & V_4 -> V_32 ) ;
}
F_41 ( & V_3 -> V_47 -> V_35 ) ;
if ( ! V_4 )
goto error;
V_42 = F_34 ( V_4 , 1 ) ;
break;
default:
V_42 = F_32 ( - V_67 ) ;
if ( V_54 < 1 )
goto error;
V_4 = F_47 ( V_54 ) ;
if ( F_8 ( V_4 ) ) {
V_42 = F_48 ( V_4 ) ;
goto error;
}
V_42 = F_34 ( V_4 , 0 ) ;
V_57 = F_38 ( V_4 -> type , V_4 ,
F_42 ,
V_3 ) ;
if ( ! F_8 ( V_57 ) ) {
F_13 ( V_4 ) ;
V_42 = V_57 ;
}
break;
}
if ( V_55 & V_73 ) {
V_9 = 0 ;
goto error;
}
if ( ! ( V_55 & V_74 ) ) {
V_9 = F_49 ( V_4 , true ) ;
switch ( V_9 ) {
case - V_75 :
goto V_76;
default:
if ( V_56 )
goto V_76;
case 0 :
break;
}
} else if ( V_56 ) {
V_9 = F_40 ( V_4 ) ;
if ( V_9 < 0 )
goto V_76;
}
V_9 = - V_77 ;
if ( ! ( V_55 & V_74 ) &&
! F_46 ( V_78 , & V_4 -> V_29 ) )
goto V_76;
V_9 = F_50 ( V_42 , V_3 , V_56 ) ;
if ( V_9 < 0 )
goto V_76;
V_4 -> V_79 = F_51 () . V_80 ;
error:
F_52 ( V_3 ) ;
return V_42 ;
V_76:
F_53 ( V_42 ) ;
V_42 = F_32 ( V_9 ) ;
goto error;
V_61:
F_52 ( V_3 ) ;
goto V_58;
}
long F_45 ( const char * V_81 )
{
const struct V_3 * V_30 ;
struct V_3 * V_20 ;
struct V_4 * V_21 ;
long V_9 , V_82 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_30 = F_2 () ;
if ( ! V_81 ) {
V_9 = F_22 ( V_20 , NULL ) ;
if ( V_9 < 0 )
goto error;
V_82 = V_20 -> V_6 -> V_82 ;
V_9 = F_19 ( V_20 ) ;
if ( V_9 == 0 )
V_9 = V_82 ;
goto V_83;
}
F_6 ( & V_84 ) ;
V_21 = F_7 ( V_81 , false ) ;
if ( F_10 ( V_21 ) == - V_46 ) {
V_21 = F_9 (
V_81 , V_30 -> V_10 , V_30 -> V_22 , V_30 ,
V_11 | V_23 | V_31 | V_85 ,
V_17 , NULL ) ;
if ( F_8 ( V_21 ) ) {
V_9 = F_10 ( V_21 ) ;
goto V_86;
}
} else if ( F_8 ( V_21 ) ) {
V_9 = F_10 ( V_21 ) ;
goto V_86;
} else if ( V_21 == V_20 -> V_6 ) {
V_9 = 0 ;
goto V_86;
}
V_9 = F_22 ( V_20 , V_21 ) ;
if ( V_9 < 0 )
goto V_86;
F_19 ( V_20 ) ;
F_12 ( & V_84 ) ;
V_9 = V_21 -> V_82 ;
F_13 ( V_21 ) ;
V_83:
return V_9 ;
V_86:
F_12 ( & V_84 ) ;
error:
F_18 ( V_20 ) ;
return V_9 ;
}
void F_54 ( struct V_87 * V_88 )
{
const struct V_3 * V_30 = F_2 () ;
struct V_3 * V_20 = F_55 ( V_88 , struct V_3 , V_89 ) ;
if ( F_56 ( V_90 -> V_29 & V_91 ) ) {
F_52 ( V_20 ) ;
return;
}
V_20 -> V_10 = V_30 -> V_10 ;
V_20 -> V_92 = V_30 -> V_92 ;
V_20 -> V_93 = V_30 -> V_93 ;
V_20 -> V_36 = V_30 -> V_36 ;
V_20 -> V_22 = V_30 -> V_22 ;
V_20 -> V_94 = V_30 -> V_94 ;
V_20 -> V_95 = V_30 -> V_95 ;
V_20 -> V_37 = V_30 -> V_37 ;
V_20 -> V_2 = F_57 ( V_30 -> V_2 ) ;
V_20 -> V_14 = F_58 ( V_30 -> V_14 ) ;
V_20 -> V_96 = F_59 ( V_30 -> V_96 ) ;
V_20 -> V_97 = V_30 -> V_97 ;
V_20 -> V_98 = V_30 -> V_98 ;
V_20 -> V_99 = V_30 -> V_99 ;
V_20 -> V_100 = V_30 -> V_100 ;
V_20 -> V_101 = V_30 -> V_101 ;
V_20 -> V_102 = V_30 -> V_102 ;
V_20 -> V_25 = F_60 ( V_30 -> V_25 ) ;
V_20 -> V_27 = F_60 ( V_30 -> V_27 ) ;
F_61 ( V_20 , V_30 ) ;
F_19 ( V_20 ) ;
}
