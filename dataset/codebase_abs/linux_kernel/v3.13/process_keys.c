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
F_24 ( V_21 ) ;
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
void F_27 ( struct V_32 * V_33 )
{
F_17 ( ! V_33 -> V_3 ) ;
if ( V_33 -> V_3 -> V_25 ) {
F_28 ( & V_33 -> V_3 -> V_25 -> V_34 ) ;
V_33 -> V_3 -> V_25 -> V_10 = V_33 -> V_3 -> V_35 ;
F_29 ( & V_33 -> V_3 -> V_25 -> V_34 ) ;
}
}
void F_30 ( struct V_32 * V_33 )
{
F_17 ( ! V_33 -> V_3 ) ;
if ( V_33 -> V_3 -> V_25 ) {
F_28 ( & V_33 -> V_3 -> V_25 -> V_34 ) ;
V_33 -> V_3 -> V_25 -> V_22 = V_33 -> V_3 -> V_36 ;
F_29 ( & V_33 -> V_3 -> V_25 -> V_34 ) ;
}
}
T_3 F_31 ( struct V_37 * V_38 )
{
T_3 V_39 , V_9 , V_40 ;
V_39 = NULL ;
V_9 = NULL ;
V_40 = F_32 ( - V_41 ) ;
if ( V_38 -> V_3 -> V_25 ) {
V_39 = F_33 (
F_34 ( V_38 -> V_3 -> V_25 , 1 ) , V_38 ) ;
if ( ! F_8 ( V_39 ) )
goto V_42;
switch ( F_10 ( V_39 ) ) {
case - V_41 :
case - V_43 :
V_9 = V_39 ;
break;
default:
V_40 = V_39 ;
break;
}
}
if ( V_38 -> V_3 -> V_27 ) {
V_39 = F_33 (
F_34 ( V_38 -> V_3 -> V_27 , 1 ) , V_38 ) ;
if ( ! F_8 ( V_39 ) )
goto V_42;
switch ( F_10 ( V_39 ) ) {
case - V_41 :
if ( V_9 )
break;
case - V_43 :
V_9 = V_39 ;
break;
default:
V_40 = V_39 ;
break;
}
}
if ( V_38 -> V_3 -> V_6 ) {
F_35 () ;
V_39 = F_33 (
F_34 ( F_36 ( V_38 -> V_3 -> V_6 ) , 1 ) ,
V_38 ) ;
F_37 () ;
if ( ! F_8 ( V_39 ) )
goto V_42;
switch ( F_10 ( V_39 ) ) {
case - V_41 :
if ( V_9 )
break;
case - V_43 :
V_9 = V_39 ;
break;
default:
V_40 = V_39 ;
break;
}
}
else if ( V_38 -> V_3 -> V_2 -> V_6 ) {
V_39 = F_33 (
F_34 ( V_38 -> V_3 -> V_2 -> V_6 , 1 ) ,
V_38 ) ;
if ( ! F_8 ( V_39 ) )
goto V_42;
switch ( F_10 ( V_39 ) ) {
case - V_41 :
if ( V_9 )
break;
case - V_43 :
V_9 = V_39 ;
break;
default:
V_40 = V_39 ;
break;
}
}
V_39 = V_9 ? V_9 : V_40 ;
V_42:
return V_39 ;
}
T_3 F_38 ( struct V_37 * V_38 )
{
struct V_44 * V_45 ;
T_3 V_39 , V_9 = F_32 ( - V_46 ) , V_40 ;
F_23 () ;
V_39 = F_31 ( V_38 ) ;
if ( ! F_8 ( V_39 ) )
goto V_42;
V_40 = V_39 ;
if ( V_38 -> V_3 -> V_44 &&
V_38 -> V_3 == F_2 () &&
V_38 -> V_47 . type != & V_48
) {
const struct V_3 * V_3 = V_38 -> V_3 ;
F_39 ( & V_3 -> V_44 -> V_34 ) ;
if ( F_40 ( V_38 -> V_3 -> V_44 ) == 0 ) {
V_45 = V_38 -> V_3 -> V_44 -> V_49 . V_50 ;
V_38 -> V_3 = V_45 -> V_3 ;
V_39 = F_38 ( V_38 ) ;
V_38 -> V_3 = V_3 ;
F_41 ( & V_3 -> V_44 -> V_34 ) ;
if ( ! F_8 ( V_39 ) )
goto V_42;
V_9 = V_39 ;
} else {
F_41 ( & V_3 -> V_44 -> V_34 ) ;
}
}
if ( V_40 == F_32 ( - V_43 ) || V_9 == F_32 ( - V_43 ) )
V_39 = F_32 ( - V_43 ) ;
else if ( V_40 == F_32 ( - V_46 ) )
V_39 = V_9 ;
else
V_39 = V_40 ;
V_42:
return V_39 ;
}
int F_42 ( const struct V_4 * V_4 , const void * V_51 )
{
return V_4 == V_51 ;
}
T_3 F_43 ( T_4 V_52 , unsigned long V_53 ,
T_1 V_54 )
{
struct V_37 V_38 = {
. V_55 = F_42 ,
. V_29 = ( V_56 |
V_57 ) ,
} ;
struct V_44 * V_45 ;
struct V_4 * V_4 ;
T_3 V_39 , V_58 ;
int V_9 ;
V_59:
V_38 . V_3 = F_44 () ;
V_39 = F_32 ( - V_43 ) ;
switch ( V_52 ) {
case V_60 :
if ( ! V_38 . V_3 -> V_25 ) {
if ( ! ( V_53 & V_61 ) )
goto error;
V_9 = F_15 () ;
if ( V_9 < 0 ) {
V_39 = F_32 ( V_9 ) ;
goto error;
}
goto V_62;
}
V_4 = V_38 . V_3 -> V_25 ;
F_24 ( V_4 ) ;
V_39 = F_34 ( V_4 , 1 ) ;
break;
case V_63 :
if ( ! V_38 . V_3 -> V_27 ) {
if ( ! ( V_53 & V_61 ) )
goto error;
V_9 = F_21 () ;
if ( V_9 < 0 ) {
V_39 = F_32 ( V_9 ) ;
goto error;
}
goto V_62;
}
V_4 = V_38 . V_3 -> V_27 ;
F_24 ( V_4 ) ;
V_39 = F_34 ( V_4 , 1 ) ;
break;
case V_64 :
if ( ! V_38 . V_3 -> V_6 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
if ( V_53 & V_61 )
V_9 = F_45 ( NULL ) ;
else
V_9 = F_26 (
V_38 . V_3 -> V_2 -> V_6 ) ;
if ( V_9 < 0 )
goto error;
goto V_62;
} else if ( V_38 . V_3 -> V_6 ==
V_38 . V_3 -> V_2 -> V_6 &&
V_53 & V_61 ) {
V_9 = F_45 ( NULL ) ;
if ( V_9 < 0 )
goto error;
goto V_62;
}
F_35 () ;
V_4 = F_36 ( V_38 . V_3 -> V_6 ) ;
F_24 ( V_4 ) ;
F_37 () ;
V_39 = F_34 ( V_4 , 1 ) ;
break;
case V_65 :
if ( ! V_38 . V_3 -> V_2 -> V_5 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
}
V_4 = V_38 . V_3 -> V_2 -> V_5 ;
F_24 ( V_4 ) ;
V_39 = F_34 ( V_4 , 1 ) ;
break;
case V_66 :
if ( ! V_38 . V_3 -> V_2 -> V_6 ) {
V_9 = F_1 () ;
if ( V_9 < 0 )
goto error;
}
V_4 = V_38 . V_3 -> V_2 -> V_6 ;
F_24 ( V_4 ) ;
V_39 = F_34 ( V_4 , 1 ) ;
break;
case V_67 :
V_39 = F_32 ( - V_68 ) ;
goto error;
case V_69 :
V_4 = V_38 . V_3 -> V_44 ;
if ( ! V_4 )
goto error;
F_24 ( V_4 ) ;
V_39 = F_34 ( V_4 , 1 ) ;
break;
case V_70 :
if ( ! V_38 . V_3 -> V_44 )
goto error;
F_39 ( & V_38 . V_3 -> V_44 -> V_34 ) ;
if ( F_46 ( V_71 ,
& V_38 . V_3 -> V_44 -> V_29 ) ) {
V_39 = F_32 ( - V_72 ) ;
V_4 = NULL ;
} else {
V_45 = V_38 . V_3 -> V_44 -> V_49 . V_50 ;
V_4 = V_45 -> V_73 ;
F_24 ( V_4 ) ;
}
F_41 ( & V_38 . V_3 -> V_44 -> V_34 ) ;
if ( ! V_4 )
goto error;
V_39 = F_34 ( V_4 , 1 ) ;
break;
default:
V_39 = F_32 ( - V_68 ) ;
if ( V_52 < 1 )
goto error;
V_4 = F_47 ( V_52 ) ;
if ( F_8 ( V_4 ) ) {
V_39 = F_48 ( V_4 ) ;
goto error;
}
V_39 = F_34 ( V_4 , 0 ) ;
V_38 . V_47 . type = V_4 -> type ;
V_38 . V_47 . V_74 = V_4 -> V_74 ;
V_38 . V_47 . V_75 = strlen ( V_4 -> V_74 ) ;
V_38 . V_76 = V_4 ;
F_49 ( L_10 ) ;
V_58 = F_38 ( & V_38 ) ;
F_49 ( L_11 , V_58 ) ;
if ( ! F_8 ( V_58 ) ) {
F_13 ( V_4 ) ;
V_39 = V_58 ;
}
break;
}
if ( V_53 & V_77 ) {
V_9 = 0 ;
goto error;
}
if ( ! ( V_53 & V_78 ) ) {
V_9 = F_50 ( V_4 , true ) ;
switch ( V_9 ) {
case - V_79 :
goto V_80;
default:
if ( V_54 )
goto V_80;
case 0 :
break;
}
} else if ( V_54 ) {
V_9 = F_40 ( V_4 ) ;
if ( V_9 < 0 )
goto V_80;
}
V_9 = - V_81 ;
if ( ! ( V_53 & V_78 ) &&
! F_46 ( V_82 , & V_4 -> V_29 ) )
goto V_80;
V_9 = F_51 ( V_39 , V_38 . V_3 , V_54 ) ;
if ( V_9 < 0 )
goto V_80;
V_4 -> V_83 = F_52 () . V_84 ;
error:
F_53 ( V_38 . V_3 ) ;
return V_39 ;
V_80:
F_54 ( V_39 ) ;
V_39 = F_32 ( V_9 ) ;
goto error;
V_62:
F_53 ( V_38 . V_3 ) ;
goto V_59;
}
long F_45 ( const char * V_85 )
{
const struct V_3 * V_30 ;
struct V_3 * V_20 ;
struct V_4 * V_21 ;
long V_9 , V_86 ;
V_20 = F_16 () ;
if ( ! V_20 )
return - V_26 ;
V_30 = F_2 () ;
if ( ! V_85 ) {
V_9 = F_22 ( V_20 , NULL ) ;
if ( V_9 < 0 )
goto error;
V_86 = V_20 -> V_6 -> V_86 ;
V_9 = F_19 ( V_20 ) ;
if ( V_9 == 0 )
V_9 = V_86 ;
goto V_87;
}
F_6 ( & V_88 ) ;
V_21 = F_7 ( V_85 , false ) ;
if ( F_10 ( V_21 ) == - V_43 ) {
V_21 = F_9 (
V_85 , V_30 -> V_10 , V_30 -> V_22 , V_30 ,
V_11 | V_23 | V_31 | V_89 ,
V_17 , NULL ) ;
if ( F_8 ( V_21 ) ) {
V_9 = F_10 ( V_21 ) ;
goto V_90;
}
} else if ( F_8 ( V_21 ) ) {
V_9 = F_10 ( V_21 ) ;
goto V_90;
} else if ( V_21 == V_20 -> V_6 ) {
V_9 = 0 ;
goto V_90;
}
V_9 = F_22 ( V_20 , V_21 ) ;
if ( V_9 < 0 )
goto V_90;
F_19 ( V_20 ) ;
F_12 ( & V_88 ) ;
V_9 = V_21 -> V_86 ;
F_13 ( V_21 ) ;
V_87:
return V_9 ;
V_90:
F_12 ( & V_88 ) ;
error:
F_18 ( V_20 ) ;
return V_9 ;
}
void F_55 ( struct V_91 * V_92 )
{
const struct V_3 * V_30 = F_2 () ;
struct V_3 * V_20 = F_56 ( V_92 , struct V_3 , V_93 ) ;
if ( F_57 ( V_94 -> V_29 & V_95 ) ) {
F_53 ( V_20 ) ;
return;
}
V_20 -> V_10 = V_30 -> V_10 ;
V_20 -> V_96 = V_30 -> V_96 ;
V_20 -> V_97 = V_30 -> V_97 ;
V_20 -> V_35 = V_30 -> V_35 ;
V_20 -> V_22 = V_30 -> V_22 ;
V_20 -> V_98 = V_30 -> V_98 ;
V_20 -> V_99 = V_30 -> V_99 ;
V_20 -> V_36 = V_30 -> V_36 ;
V_20 -> V_2 = F_58 ( V_30 -> V_2 ) ;
V_20 -> V_14 = F_59 ( V_30 -> V_14 ) ;
V_20 -> V_100 = F_60 ( V_30 -> V_100 ) ;
V_20 -> V_101 = V_30 -> V_101 ;
V_20 -> V_102 = V_30 -> V_102 ;
V_20 -> V_103 = V_30 -> V_103 ;
V_20 -> V_104 = V_30 -> V_104 ;
V_20 -> V_105 = V_30 -> V_105 ;
V_20 -> V_106 = V_30 -> V_106 ;
V_20 -> V_25 = F_61 ( V_30 -> V_25 ) ;
V_20 -> V_27 = F_61 ( V_30 -> V_27 ) ;
F_62 ( V_20 , V_30 ) ;
F_19 ( V_20 ) ;
}
static int T_5 F_63 ( void )
{
return F_1 () ;
}
