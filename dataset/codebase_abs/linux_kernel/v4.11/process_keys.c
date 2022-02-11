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
V_17 ,
NULL , NULL ) ;
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
V_17 ,
NULL , NULL ) ;
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
if ( V_20 -> V_22 )
return 0 ;
V_21 = F_9 ( L_7 , V_20 -> V_10 , V_20 -> V_23 , V_20 ,
V_11 | V_24 ,
V_25 ,
NULL , NULL ) ;
if ( F_8 ( V_21 ) )
return F_10 ( V_21 ) ;
V_20 -> V_22 = V_21 ;
return 0 ;
}
static int F_15 ( void )
{
struct V_3 * V_20 ;
int V_9 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_9 = F_14 ( V_20 ) ;
if ( V_9 < 0 ) {
F_17 ( V_20 ) ;
return V_9 ;
}
return F_18 ( V_20 ) ;
}
int F_19 ( struct V_3 * V_20 )
{
struct V_4 * V_21 ;
if ( V_20 -> V_27 )
return 0 ;
V_21 = F_9 ( L_8 , V_20 -> V_10 , V_20 -> V_23 , V_20 ,
V_11 | V_24 ,
V_25 ,
NULL , NULL ) ;
if ( F_8 ( V_21 ) )
return F_10 ( V_21 ) ;
V_20 -> V_27 = V_21 ;
return 0 ;
}
static int F_20 ( void )
{
struct V_3 * V_20 ;
int V_9 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_9 = F_19 ( V_20 ) ;
if ( V_9 < 0 ) {
F_17 ( V_20 ) ;
return V_9 ;
}
return F_18 ( V_20 ) ;
}
int F_21 ( struct V_3 * V_3 , struct V_4 * V_21 )
{
unsigned long V_28 ;
struct V_4 * V_29 ;
F_22 () ;
if ( ! V_21 ) {
V_28 = V_25 ;
if ( V_3 -> V_6 )
V_28 = V_17 ;
V_21 = F_9 ( L_9 , V_3 -> V_10 , V_3 -> V_23 , V_3 ,
V_11 | V_24 | V_30 ,
V_28 , NULL , NULL ) ;
if ( F_8 ( V_21 ) )
return F_10 ( V_21 ) ;
} else {
F_23 ( V_21 ) ;
}
V_29 = V_3 -> V_6 ;
F_24 ( V_3 -> V_6 , V_21 ) ;
if ( V_29 )
F_13 ( V_29 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_21 )
{
struct V_3 * V_20 ;
int V_9 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_9 = F_21 ( V_20 , V_21 ) ;
if ( V_9 < 0 ) {
F_17 ( V_20 ) ;
return V_9 ;
}
return F_18 ( V_20 ) ;
}
void F_26 ( struct V_31 * V_32 )
{
F_27 ( ! V_32 -> V_3 ) ;
if ( V_32 -> V_3 -> V_22 ) {
F_28 ( & V_32 -> V_3 -> V_22 -> V_33 ) ;
V_32 -> V_3 -> V_22 -> V_10 = V_32 -> V_3 -> V_34 ;
F_29 ( & V_32 -> V_3 -> V_22 -> V_33 ) ;
}
}
void F_30 ( struct V_31 * V_32 )
{
F_27 ( ! V_32 -> V_3 ) ;
if ( V_32 -> V_3 -> V_22 ) {
F_28 ( & V_32 -> V_3 -> V_22 -> V_33 ) ;
V_32 -> V_3 -> V_22 -> V_23 = V_32 -> V_3 -> V_35 ;
F_29 ( & V_32 -> V_3 -> V_22 -> V_33 ) ;
}
}
T_3 F_31 ( struct V_36 * V_37 )
{
T_3 V_38 , V_9 , V_39 ;
V_38 = NULL ;
V_9 = NULL ;
V_39 = F_32 ( - V_40 ) ;
if ( V_37 -> V_3 -> V_22 ) {
V_38 = F_33 (
F_34 ( V_37 -> V_3 -> V_22 , 1 ) , V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
case - V_42 :
V_9 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
if ( V_37 -> V_3 -> V_27 ) {
V_38 = F_33 (
F_34 ( V_37 -> V_3 -> V_27 , 1 ) , V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_9 )
break;
case - V_42 :
V_9 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
if ( V_37 -> V_3 -> V_6 ) {
F_35 () ;
V_38 = F_33 (
F_34 ( F_36 ( V_37 -> V_3 -> V_6 ) , 1 ) ,
V_37 ) ;
F_37 () ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_9 )
break;
case - V_42 :
V_9 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
else if ( V_37 -> V_3 -> V_2 -> V_6 ) {
V_38 = F_33 (
F_34 ( V_37 -> V_3 -> V_2 -> V_6 , 1 ) ,
V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
switch ( F_10 ( V_38 ) ) {
case - V_40 :
if ( V_9 )
break;
case - V_42 :
V_9 = V_38 ;
break;
default:
V_39 = V_38 ;
break;
}
}
V_38 = V_9 ? V_9 : V_39 ;
V_41:
return V_38 ;
}
T_3 F_38 ( struct V_36 * V_37 )
{
struct V_43 * V_44 ;
T_3 V_38 , V_9 = F_32 ( - V_45 ) , V_39 ;
F_22 () ;
V_38 = F_31 ( V_37 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
V_39 = V_38 ;
if ( V_37 -> V_3 -> V_43 &&
V_37 -> V_3 == F_2 () &&
V_37 -> V_46 . type != & V_47
) {
const struct V_3 * V_3 = V_37 -> V_3 ;
F_39 ( & V_3 -> V_43 -> V_33 ) ;
if ( F_40 ( V_37 -> V_3 -> V_43 ) == 0 ) {
V_44 = V_37 -> V_3 -> V_43 -> V_48 . V_49 [ 0 ] ;
V_37 -> V_3 = V_44 -> V_3 ;
V_38 = F_38 ( V_37 ) ;
V_37 -> V_3 = V_3 ;
F_41 ( & V_3 -> V_43 -> V_33 ) ;
if ( ! F_8 ( V_38 ) )
goto V_41;
V_9 = V_38 ;
} else {
F_41 ( & V_3 -> V_43 -> V_33 ) ;
}
}
if ( V_39 == F_32 ( - V_42 ) || V_9 == F_32 ( - V_42 ) )
V_38 = F_32 ( - V_42 ) ;
else if ( V_39 == F_32 ( - V_45 ) )
V_38 = V_9 ;
else
V_38 = V_39 ;
V_41:
return V_38 ;
}
bool F_42 ( const struct V_4 * V_4 ,
const struct V_50 * V_51 )
{
return V_4 == V_51 -> V_52 ;
}
T_3 F_43 ( T_4 V_53 , unsigned long V_54 ,
T_1 V_55 )
{
struct V_36 V_37 = {
. V_51 . V_56 = F_42 ,
. V_51 . V_57 = V_58 ,
. V_28 = V_59 ,
} ;
struct V_43 * V_44 ;
struct V_4 * V_4 ;
T_3 V_38 , V_60 ;
int V_9 ;
V_61:
V_37 . V_3 = F_44 () ;
V_38 = F_32 ( - V_42 ) ;
switch ( V_53 ) {
case V_62 :
if ( ! V_37 . V_3 -> V_22 ) {
if ( ! ( V_54 & V_63 ) )
goto error;
V_9 = F_15 () ;
if ( V_9 < 0 ) {
V_38 = F_32 ( V_9 ) ;
goto error;
}
goto V_64;
}
V_4 = V_37 . V_3 -> V_22 ;
F_23 ( V_4 ) ;
V_38 = F_34 ( V_4 , 1 ) ;
break;
case V_65 :
if ( ! V_37 . V_3 -> V_27 ) {
if ( ! ( V_54 & V_63 ) )
goto error;
V_9 = F_20 () ;
if ( V_9 < 0 ) {
V_38 = F_32 ( V_9 ) ;
goto error;
}
goto V_64;
}
V_4 = V_37 . V_3 -> V_27 ;
F_23 ( V_4 ) ;
V_38 = F_34 ( V_4 , 1 ) ;
break;
case V_66 :
if ( ! V_37 . V_3 -> V_6 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
if ( V_54 & V_63 )
V_9 = F_45 ( NULL ) ;
else
V_9 = F_25 (
V_37 . V_3 -> V_2 -> V_6 ) ;
if ( V_9 < 0 )
goto error;
goto V_64;
} else if ( V_37 . V_3 -> V_6 ==
V_37 . V_3 -> V_2 -> V_6 &&
V_54 & V_63 ) {
V_9 = F_45 ( NULL ) ;
if ( V_9 < 0 )
goto error;
goto V_64;
}
F_35 () ;
V_4 = F_36 ( V_37 . V_3 -> V_6 ) ;
F_23 ( V_4 ) ;
F_37 () ;
V_38 = F_34 ( V_4 , 1 ) ;
break;
case V_67 :
if ( ! V_37 . V_3 -> V_2 -> V_5 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
}
V_4 = V_37 . V_3 -> V_2 -> V_5 ;
F_23 ( V_4 ) ;
V_38 = F_34 ( V_4 , 1 ) ;
break;
case V_68 :
if ( ! V_37 . V_3 -> V_2 -> V_6 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
}
V_4 = V_37 . V_3 -> V_2 -> V_6 ;
F_23 ( V_4 ) ;
V_38 = F_34 ( V_4 , 1 ) ;
break;
case V_69 :
V_38 = F_32 ( - V_70 ) ;
goto error;
case V_71 :
V_4 = V_37 . V_3 -> V_43 ;
if ( ! V_4 )
goto error;
F_23 ( V_4 ) ;
V_38 = F_34 ( V_4 , 1 ) ;
break;
case V_72 :
if ( ! V_37 . V_3 -> V_43 )
goto error;
F_39 ( & V_37 . V_3 -> V_43 -> V_33 ) ;
if ( F_46 ( V_73 ,
& V_37 . V_3 -> V_43 -> V_28 ) ) {
V_38 = F_32 ( - V_74 ) ;
V_4 = NULL ;
} else {
V_44 = V_37 . V_3 -> V_43 -> V_48 . V_49 [ 0 ] ;
V_4 = V_44 -> V_75 ;
F_23 ( V_4 ) ;
}
F_41 ( & V_37 . V_3 -> V_43 -> V_33 ) ;
if ( ! V_4 )
goto error;
V_38 = F_34 ( V_4 , 1 ) ;
break;
default:
V_38 = F_32 ( - V_70 ) ;
if ( V_53 < 1 )
goto error;
V_4 = F_47 ( V_53 ) ;
if ( F_8 ( V_4 ) ) {
V_38 = F_48 ( V_4 ) ;
goto error;
}
V_38 = F_34 ( V_4 , 0 ) ;
V_37 . V_46 . type = V_4 -> type ;
V_37 . V_46 . V_76 = V_4 -> V_76 ;
V_37 . V_46 . V_77 = strlen ( V_4 -> V_76 ) ;
V_37 . V_51 . V_52 = V_4 ;
F_49 ( L_10 ) ;
V_60 = F_38 ( & V_37 ) ;
F_49 ( L_11 , V_60 ) ;
if ( ! F_8 ( V_60 ) ) {
F_13 ( V_4 ) ;
V_38 = V_60 ;
}
break;
}
if ( V_54 & V_78 ) {
V_9 = 0 ;
goto error;
}
if ( ! ( V_54 & V_79 ) ) {
V_9 = F_50 ( V_4 , true ) ;
switch ( V_9 ) {
case - V_80 :
goto V_81;
default:
if ( V_55 )
goto V_81;
case 0 :
break;
}
} else if ( V_55 ) {
V_9 = F_40 ( V_4 ) ;
if ( V_9 < 0 )
goto V_81;
}
V_9 = - V_82 ;
if ( ! ( V_54 & V_79 ) &&
! F_46 ( V_83 , & V_4 -> V_28 ) )
goto V_81;
V_9 = F_51 ( V_38 , V_37 . V_3 , V_55 ) ;
if ( V_9 < 0 )
goto V_81;
V_4 -> V_84 = F_52 () . V_85 ;
error:
F_53 ( V_37 . V_3 ) ;
return V_38 ;
V_81:
F_54 ( V_38 ) ;
V_38 = F_32 ( V_9 ) ;
goto error;
V_64:
F_53 ( V_37 . V_3 ) ;
goto V_61;
}
long F_45 ( const char * V_86 )
{
const struct V_3 * V_29 ;
struct V_3 * V_20 ;
struct V_4 * V_21 ;
long V_9 , V_87 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_29 = F_2 () ;
if ( ! V_86 ) {
V_9 = F_21 ( V_20 , NULL ) ;
if ( V_9 < 0 )
goto error;
V_87 = V_20 -> V_6 -> V_87 ;
V_9 = F_18 ( V_20 ) ;
if ( V_9 == 0 )
V_9 = V_87 ;
goto V_88;
}
F_6 ( & V_89 ) ;
V_21 = F_7 ( V_86 , false ) ;
if ( F_10 ( V_21 ) == - V_42 ) {
V_21 = F_9 (
V_86 , V_29 -> V_10 , V_29 -> V_23 , V_29 ,
V_11 | V_24 | V_30 | V_90 ,
V_17 , NULL , NULL ) ;
if ( F_8 ( V_21 ) ) {
V_9 = F_10 ( V_21 ) ;
goto V_91;
}
} else if ( F_8 ( V_21 ) ) {
V_9 = F_10 ( V_21 ) ;
goto V_91;
} else if ( V_21 == V_20 -> V_6 ) {
F_13 ( V_21 ) ;
V_9 = 0 ;
goto V_91;
}
V_9 = F_21 ( V_20 , V_21 ) ;
if ( V_9 < 0 )
goto V_91;
F_18 ( V_20 ) ;
F_12 ( & V_89 ) ;
V_9 = V_21 -> V_87 ;
F_13 ( V_21 ) ;
V_88:
return V_9 ;
V_91:
F_12 ( & V_89 ) ;
error:
F_17 ( V_20 ) ;
return V_9 ;
}
void F_55 ( struct V_92 * V_93 )
{
const struct V_3 * V_29 = F_2 () ;
struct V_3 * V_20 = F_56 ( V_93 , struct V_3 , V_94 ) ;
if ( F_57 ( V_95 -> V_28 & V_96 ) ) {
F_53 ( V_20 ) ;
return;
}
V_20 -> V_10 = V_29 -> V_10 ;
V_20 -> V_97 = V_29 -> V_97 ;
V_20 -> V_98 = V_29 -> V_98 ;
V_20 -> V_34 = V_29 -> V_34 ;
V_20 -> V_23 = V_29 -> V_23 ;
V_20 -> V_99 = V_29 -> V_99 ;
V_20 -> V_100 = V_29 -> V_100 ;
V_20 -> V_35 = V_29 -> V_35 ;
V_20 -> V_2 = F_58 ( V_29 -> V_2 ) ;
V_20 -> V_14 = F_59 ( V_29 -> V_14 ) ;
V_20 -> V_101 = F_60 ( V_29 -> V_101 ) ;
V_20 -> V_102 = V_29 -> V_102 ;
V_20 -> V_103 = V_29 -> V_103 ;
V_20 -> V_104 = V_29 -> V_104 ;
V_20 -> V_105 = V_29 -> V_105 ;
V_20 -> V_106 = V_29 -> V_106 ;
V_20 -> V_107 = V_29 -> V_107 ;
V_20 -> V_108 = V_29 -> V_108 ;
V_20 -> V_22 = F_61 ( V_29 -> V_22 ) ;
V_20 -> V_27 = F_61 ( V_29 -> V_27 ) ;
F_62 ( V_20 , V_29 ) ;
F_18 ( V_20 ) ;
}
static int T_5 F_63 ( void )
{
return F_1 () ;
}
