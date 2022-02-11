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
if ( F_9 ( V_20 -> V_24 ) )
return - V_25 ;
V_22 = F_10 ( V_20 -> V_26 , L_8 , NULL , & V_21 ) ;
if ( F_11 ( V_22 ) || ! ( V_21 & V_27 ) )
return - V_25 ;
F_12 () ;
F_13 () ;
V_23 = F_14 ( V_20 -> V_26 , V_20 -> V_24 , & V_20 -> V_28 ) ;
if ( V_23 )
goto V_29;
V_23 = F_15 ( V_20 -> V_28 ) ;
if ( V_23 ) {
F_16 ( V_20 -> V_28 ) ;
goto V_29;
}
F_17 ( L_9 , V_20 -> V_28 ) ;
V_20 -> V_30 . V_31 = 1 ;
V_29:
F_18 () ;
F_19 () ;
return V_23 ;
}
static inline int F_8 ( struct V_19 * V_20 )
{
return - V_25 ;
}
static int F_20 ( struct V_32 * V_33 )
{
union V_34 V_35 = { 0 } ;
struct V_36 V_37 = { sizeof( union V_34 ) , & V_35 } ;
struct V_19 * V_20 = F_21 ( V_33 ) ;
int V_38 = 0 ;
T_2 V_22 = V_39 ;
static int V_40 ;
unsigned long long V_41 ;
F_7 () ;
if ( V_42 . V_43 && V_42 . V_44 ) {
V_20 -> V_30 . V_45 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_22 ( V_33 ) , V_46 ) ) {
V_22 = F_23 ( V_20 -> V_26 , NULL , NULL , & V_37 ) ;
if ( F_11 ( V_22 ) ) {
F_24 ( & V_33 -> V_2 ,
L_12 ,
V_22 ) ;
return - V_25 ;
}
V_20 -> V_47 = V_35 . V_48 . V_49 ;
} else {
V_22 = F_10 ( V_20 -> V_26 , V_50 ,
NULL , & V_41 ) ;
if ( F_11 ( V_22 ) ) {
F_24 ( & V_33 -> V_2 ,
L_13 ,
V_22 ) ;
return - V_25 ;
}
V_38 = 1 ;
V_20 -> V_47 = V_41 ;
}
V_20 -> V_24 = F_25 ( V_20 -> V_26 , V_38 ,
V_20 -> V_47 ) ;
if ( F_9 ( V_20 -> V_24 ) )
F_26 ( V_20 -> V_26 , L_14 ) ;
V_20 -> V_28 = F_27 ( V_20 -> V_24 , V_20 -> V_47 ) ;
if ( ! V_40 && ! F_28 () ) {
V_40 = 1 ;
if ( F_29 ( V_20 -> V_28 ) && ( F_30 () == 1 ) )
V_20 -> V_28 = 0 ;
}
if ( F_29 ( V_20 -> V_28 ) ) {
int V_23 = F_8 ( V_20 ) ;
if ( V_23 )
return V_23 ;
}
sprintf ( F_31 ( V_33 ) , L_15 , V_20 -> V_28 ) ;
F_2 ( ( V_7 , L_16 , V_20 -> V_28 ,
V_20 -> V_47 ) ) ;
if ( ! V_35 . V_48 . V_51 )
F_2 ( ( V_7 , L_17 ) ) ;
else if ( V_35 . V_48 . V_52 != 6 )
F_24 ( & V_33 -> V_2 , L_18 ,
V_35 . V_48 . V_52 ) ;
else {
V_20 -> V_53 . V_54 = V_35 . V_48 . V_51 ;
V_20 -> V_53 . V_55 = V_42 . V_55 ;
V_20 -> V_53 . V_56 = V_42 . V_56 ;
V_20 -> V_57 = V_35 . V_48 . V_51 ;
F_32 ( V_20 -> V_53 . V_54 , 6 , L_19 ) ;
}
V_22 = F_10 ( V_20 -> V_26 , L_20 , NULL , & V_41 ) ;
if ( F_33 ( V_22 ) )
F_34 ( V_20 -> V_28 , V_41 ) ;
return 0 ;
}
static int F_35 ( struct V_32 * V_33 ,
const struct V_58 * V_28 )
{
struct V_19 * V_20 ;
struct V_33 * V_2 ;
int V_17 = 0 ;
V_20 = F_36 ( sizeof( struct V_19 ) , V_59 ) ;
if ( ! V_20 )
return - V_60 ;
if ( ! F_37 ( & V_20 -> V_53 . V_61 , V_59 ) ) {
V_17 = - V_60 ;
goto V_62;
}
V_20 -> V_26 = V_33 -> V_26 ;
strcpy ( F_38 ( V_33 ) , V_63 ) ;
strcpy ( F_39 ( V_33 ) , V_64 ) ;
V_33 -> V_65 = V_20 ;
V_17 = F_20 ( V_33 ) ;
if ( V_17 )
return 0 ;
#ifdef F_40
if ( V_20 -> V_28 >= V_66 && V_20 -> V_28 != 0 )
return 0 ;
#endif
F_41 ( V_20 -> V_28 >= V_67 ) ;
if ( F_42 ( V_68 , V_20 -> V_28 ) != NULL &&
F_42 ( V_68 , V_20 -> V_28 ) != V_33 ) {
F_43 ( & V_33 -> V_2 ,
L_21 ,
V_20 -> V_28 ) ;
goto V_69;
}
F_42 ( V_68 , V_20 -> V_28 ) = V_33 ;
F_42 ( V_70 , V_20 -> V_28 ) = V_20 ;
V_2 = F_44 ( V_20 -> V_28 ) ;
if ( ! V_2 ) {
V_17 = - V_25 ;
goto V_69;
}
V_17 = F_45 ( V_2 , V_33 ) ;
if ( V_17 )
goto V_69;
V_20 -> V_2 = V_2 ;
if ( F_46 ( V_2 ) >= 0 )
return 1 ;
F_24 ( V_2 , L_22 ) ;
F_47 ( V_2 ) ;
V_69:
F_48 ( V_20 -> V_53 . V_61 ) ;
V_33 -> V_65 = NULL ;
F_42 ( V_70 , V_20 -> V_28 ) = NULL ;
V_62:
F_49 ( V_20 ) ;
return V_17 ;
}
static void F_50 ( struct V_32 * V_33 )
{
struct V_19 * V_20 ;
if ( ! V_33 || ! F_21 ( V_33 ) )
return;
V_20 = F_21 ( V_33 ) ;
if ( V_20 -> V_28 >= V_67 )
goto V_29;
F_51 ( V_20 -> V_2 ) ;
F_47 ( V_20 -> V_2 ) ;
F_42 ( V_68 , V_20 -> V_28 ) = NULL ;
F_42 ( V_70 , V_20 -> V_28 ) = NULL ;
F_12 () ;
F_13 () ;
F_52 ( V_20 -> V_28 ) ;
F_16 ( V_20 -> V_28 ) ;
F_18 () ;
F_19 () ;
F_53 ( F_54 ( V_20 -> V_28 ) ) ;
V_29:
F_48 ( V_20 -> V_53 . V_61 ) ;
F_49 ( V_20 ) ;
}
void T_3 F_55 ( void )
{
F_56 ( & V_71 , L_23 ) ;
}
