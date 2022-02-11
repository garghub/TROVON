static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_1 V_4 = 0 ;
if ( ! V_2 )
return - V_5 ;
switch ( V_2 -> V_6 ) {
case 0 :
F_2 ( ( V_7 , L_1 ) ) ;
break;
case 1 :
F_2 ( ( V_7 , L_2 ) ) ;
break;
case 2 :
F_2 ( ( V_7 , L_3 ) ) ;
break;
case 3 :
F_2 ( ( V_7 , L_4 ) ) ;
break;
default:
F_2 ( ( V_7 , L_5 ) ) ;
break;
}
switch ( V_2 -> V_6 ) {
case 0 :
case 1 :
V_8 . V_9 . V_10 = 1 ;
case 2 :
case 3 :
V_2 = F_3 ( V_11 ,
V_12 ,
V_13 , V_13 , NULL ) ;
if ( V_2 ) {
V_8 . V_9 . V_14 = F_4 ( V_2 , 4 ) ;
F_5 ( V_2 ) ;
}
V_2 = F_3 ( V_11 ,
V_15 ,
V_13 , V_13 , NULL ) ;
if ( V_2 ) {
F_6 ( V_2 , 0x76 , & V_3 ) ;
F_6 ( V_2 , 0x77 , & V_4 ) ;
if ( ( V_3 & 0x80 ) || ( V_4 & 0x80 ) )
V_8 . V_9 . V_16 = 1 ;
F_5 ( V_2 ) ;
}
break;
}
if ( V_8 . V_9 . V_14 )
F_2 ( ( V_7 ,
L_6 ) ) ;
if ( V_8 . V_9 . V_16 )
F_2 ( ( V_7 ,
L_7 ) ) ;
return 0 ;
}
static int F_7 ( void )
{
int V_17 = 0 ;
struct V_1 * V_2 = NULL ;
V_2 = F_3 ( V_11 ,
V_18 , V_13 ,
V_13 , NULL ) ;
if ( V_2 ) {
V_17 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
return V_17 ;
}
static int F_8 ( struct V_19 * V_20 )
{
unsigned long long V_21 ;
T_2 V_22 ;
int V_23 ;
if ( V_20 -> V_24 == V_25 )
return - V_26 ;
V_22 = F_9 ( V_20 -> V_27 , L_8 , NULL , & V_21 ) ;
if ( F_10 ( V_22 ) || ! ( V_21 & V_28 ) )
return - V_26 ;
F_11 () ;
F_12 () ;
V_23 = F_13 ( V_20 -> V_27 , V_20 -> V_24 , & V_20 -> V_29 ) ;
if ( V_23 )
goto V_30;
V_23 = F_14 ( V_20 -> V_29 ) ;
if ( V_23 ) {
F_15 ( V_20 -> V_29 ) ;
goto V_30;
}
F_16 ( L_9 , V_20 -> V_29 ) ;
V_20 -> V_31 . V_32 = 1 ;
V_30:
F_17 () ;
F_18 () ;
return V_23 ;
}
static inline int F_8 ( struct V_19 * V_20 )
{
return - V_26 ;
}
static int F_19 ( struct V_33 * V_34 )
{
union V_35 V_36 = { 0 } ;
struct V_37 V_38 = { sizeof( union V_35 ) , & V_36 } ;
struct V_19 * V_20 = F_20 ( V_34 ) ;
T_3 V_24 ;
int V_39 , V_40 = 0 ;
T_2 V_22 = V_41 ;
static int V_42 ;
unsigned long long V_43 ;
F_7 () ;
if ( V_44 . V_45 && V_44 . V_46 ) {
V_20 -> V_31 . V_47 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_21 ( V_34 ) , V_48 ) ) {
V_22 = F_22 ( V_20 -> V_27 , NULL , NULL , & V_38 ) ;
if ( F_10 ( V_22 ) ) {
F_23 ( & V_34 -> V_2 ,
L_12 ,
V_22 ) ;
return - V_26 ;
}
V_20 -> V_49 = V_36 . V_50 . V_51 ;
} else {
V_22 = F_9 ( V_20 -> V_27 , V_52 ,
NULL , & V_43 ) ;
if ( F_10 ( V_22 ) ) {
F_23 ( & V_34 -> V_2 ,
L_13 ,
V_22 ) ;
return - V_26 ;
}
V_40 = 1 ;
V_20 -> V_49 = V_43 ;
}
V_24 = F_24 ( V_20 -> V_27 , V_40 , V_20 -> V_49 ) ;
if ( V_24 == V_25 )
F_25 ( V_20 -> V_27 , L_14 ) ;
V_20 -> V_24 = V_24 ;
V_39 = F_26 ( V_20 -> V_24 , V_20 -> V_49 ) ;
if ( ! V_42 && ! F_27 () ) {
V_42 = 1 ;
if ( ( V_39 == - 1 ) && ( F_28 () == 1 ) )
V_39 = 0 ;
}
V_20 -> V_29 = V_39 ;
if ( V_20 -> V_29 == - 1 ) {
int V_23 = F_8 ( V_20 ) ;
if ( V_23 )
return V_23 ;
}
sprintf ( F_29 ( V_34 ) , L_15 , V_20 -> V_29 ) ;
F_2 ( ( V_7 , L_16 , V_20 -> V_29 ,
V_20 -> V_49 ) ) ;
if ( ! V_36 . V_50 . V_53 )
F_2 ( ( V_7 , L_17 ) ) ;
else if ( V_36 . V_50 . V_54 != 6 )
F_23 ( & V_34 -> V_2 , L_18 ,
V_36 . V_50 . V_54 ) ;
else {
V_20 -> V_55 . V_56 = V_36 . V_50 . V_53 ;
V_20 -> V_55 . V_57 = V_44 . V_57 ;
V_20 -> V_55 . V_58 = V_44 . V_58 ;
V_20 -> V_59 = V_36 . V_50 . V_53 ;
F_30 ( V_20 -> V_55 . V_56 , 6 , L_19 ) ;
}
V_22 = F_9 ( V_20 -> V_27 , L_20 , NULL , & V_43 ) ;
if ( F_31 ( V_22 ) )
F_32 ( V_20 -> V_29 , V_43 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_34 ,
const struct V_60 * V_29 )
{
struct V_19 * V_20 ;
struct V_34 * V_2 ;
int V_17 = 0 ;
V_20 = F_34 ( sizeof( struct V_19 ) , V_61 ) ;
if ( ! V_20 )
return - V_62 ;
if ( ! F_35 ( & V_20 -> V_55 . V_63 , V_61 ) ) {
V_17 = - V_62 ;
goto V_64;
}
V_20 -> V_27 = V_34 -> V_27 ;
strcpy ( F_36 ( V_34 ) , V_65 ) ;
strcpy ( F_37 ( V_34 ) , V_66 ) ;
V_34 -> V_67 = V_20 ;
V_17 = F_19 ( V_34 ) ;
if ( V_17 )
return 0 ;
#ifdef F_38
if ( V_20 -> V_29 >= V_68 && V_20 -> V_29 != 0 )
return 0 ;
#endif
F_39 ( V_20 -> V_29 >= V_69 ) ;
if ( F_40 ( V_70 , V_20 -> V_29 ) != NULL &&
F_40 ( V_70 , V_20 -> V_29 ) != V_34 ) {
F_41 ( & V_34 -> V_2 ,
L_21 ,
V_20 -> V_29 ) ;
goto V_71;
}
F_40 ( V_70 , V_20 -> V_29 ) = V_34 ;
F_40 ( V_72 , V_20 -> V_29 ) = V_20 ;
V_2 = F_42 ( V_20 -> V_29 ) ;
if ( ! V_2 ) {
V_17 = - V_26 ;
goto V_71;
}
V_17 = F_43 ( V_2 , V_34 ) ;
if ( V_17 )
goto V_71;
V_20 -> V_2 = V_2 ;
if ( F_44 ( V_2 ) >= 0 )
return 1 ;
F_23 ( V_2 , L_22 ) ;
F_45 ( V_2 ) ;
V_71:
F_46 ( V_20 -> V_55 . V_63 ) ;
V_34 -> V_67 = NULL ;
F_40 ( V_72 , V_20 -> V_29 ) = NULL ;
V_64:
F_47 ( V_20 ) ;
return V_17 ;
}
static void F_48 ( struct V_33 * V_34 )
{
struct V_19 * V_20 ;
if ( ! V_34 || ! F_20 ( V_34 ) )
return;
V_20 = F_20 ( V_34 ) ;
if ( V_20 -> V_29 >= V_69 )
goto V_30;
F_49 ( V_20 -> V_2 ) ;
F_45 ( V_20 -> V_2 ) ;
F_40 ( V_70 , V_20 -> V_29 ) = NULL ;
F_40 ( V_72 , V_20 -> V_29 ) = NULL ;
F_11 () ;
F_12 () ;
F_50 ( V_20 -> V_29 ) ;
F_15 ( V_20 -> V_29 ) ;
F_17 () ;
F_18 () ;
F_51 ( F_52 ( V_20 -> V_29 ) ) ;
V_30:
F_46 ( V_20 -> V_55 . V_63 ) ;
F_47 ( V_20 ) ;
}
void T_4 F_53 ( void )
{
F_54 ( & V_73 , L_23 ) ;
}
