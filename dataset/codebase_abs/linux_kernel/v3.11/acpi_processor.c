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
static int F_7 ( struct V_17 * V_18 )
{
int V_19 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_18 )
return - V_5 ;
V_2 = F_3 ( V_11 ,
V_20 , V_13 ,
V_13 , NULL ) ;
if ( V_2 ) {
V_19 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
return V_19 ;
}
static int F_8 ( struct V_17 * V_18 )
{
unsigned long long V_21 ;
T_2 V_22 ;
int V_23 ;
V_22 = F_9 ( V_18 -> V_24 , L_8 , NULL , & V_21 ) ;
if ( F_10 ( V_22 ) || ! ( V_21 & V_25 ) )
return - V_26 ;
V_23 = F_11 ( V_18 -> V_24 , & V_18 -> V_27 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_12 ( V_18 -> V_27 ) ;
if ( V_23 ) {
F_13 ( V_18 -> V_27 ) ;
return V_23 ;
}
F_14 ( L_9 , V_18 -> V_27 ) ;
V_18 -> V_28 . V_29 = 1 ;
return 0 ;
}
static inline int F_8 ( struct V_17 * V_18 )
{
return - V_26 ;
}
static int F_15 ( struct V_30 * V_31 )
{
union V_32 V_33 = { 0 } ;
struct V_34 V_35 = { sizeof( union V_32 ) , & V_33 } ;
struct V_17 * V_18 = F_16 ( V_31 ) ;
int V_36 , V_37 = 0 ;
T_2 V_22 = V_38 ;
static int V_39 ;
if ( F_17 () > 1 )
V_8 . V_40 = TRUE ;
F_7 ( V_18 ) ;
if ( V_41 . V_42 && V_41 . V_43 ) {
V_18 -> V_28 . V_44 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_18 ( V_31 ) , V_45 ) ) {
V_22 = F_19 ( V_18 -> V_24 , NULL , NULL , & V_35 ) ;
if ( F_10 ( V_22 ) ) {
F_20 ( & V_31 -> V_2 ,
L_12 ,
V_22 ) ;
return - V_26 ;
}
V_18 -> V_46 = V_33 . V_47 . V_48 ;
} else {
unsigned long long V_49 ;
V_22 = F_9 ( V_18 -> V_24 , V_50 ,
NULL , & V_49 ) ;
if ( F_10 ( V_22 ) ) {
F_20 ( & V_31 -> V_2 ,
L_13 ,
V_22 ) ;
return - V_26 ;
}
V_37 = 1 ;
V_18 -> V_46 = V_49 ;
}
V_36 = F_21 ( V_18 -> V_24 , V_37 , V_18 -> V_46 ) ;
if ( ! V_39 && ( V_36 == - 1 ) &&
( F_17 () == 1 ) ) {
V_36 = 0 ;
}
V_39 = 1 ;
V_18 -> V_27 = V_36 ;
if ( V_18 -> V_27 == - 1 ) {
int V_23 = F_8 ( V_18 ) ;
if ( V_23 )
return V_23 ;
}
sprintf ( F_22 ( V_31 ) , L_14 , V_18 -> V_27 ) ;
F_2 ( ( V_7 , L_15 , V_18 -> V_27 ,
V_18 -> V_46 ) ) ;
if ( ! V_33 . V_47 . V_51 )
F_2 ( ( V_7 , L_16 ) ) ;
else if ( V_33 . V_47 . V_52 != 6 )
F_20 ( & V_31 -> V_2 , L_17 ,
V_33 . V_47 . V_52 ) ;
else {
V_18 -> V_53 . V_54 = V_33 . V_47 . V_51 ;
V_18 -> V_53 . V_55 = V_41 . V_55 ;
V_18 -> V_53 . V_56 = V_41 . V_56 ;
V_18 -> V_57 = V_33 . V_47 . V_51 ;
F_23 ( V_18 -> V_53 . V_54 , 6 , L_18 ) ;
}
V_22 = F_19 ( V_18 -> V_24 , L_19 , NULL , & V_35 ) ;
if ( F_24 ( V_22 ) )
F_25 ( V_18 -> V_27 , V_33 . integer . V_49 ) ;
return 0 ;
}
static int F_26 ( struct V_30 * V_31 ,
const struct V_58 * V_27 )
{
struct V_17 * V_18 ;
struct V_31 * V_2 ;
int V_19 = 0 ;
V_18 = F_27 ( sizeof( struct V_17 ) , V_59 ) ;
if ( ! V_18 )
return - V_60 ;
if ( ! F_28 ( & V_18 -> V_53 . V_61 , V_59 ) ) {
V_19 = - V_60 ;
goto V_62;
}
V_18 -> V_24 = V_31 -> V_24 ;
strcpy ( F_29 ( V_31 ) , V_63 ) ;
strcpy ( F_30 ( V_31 ) , V_64 ) ;
V_31 -> V_65 = V_18 ;
V_19 = F_15 ( V_31 ) ;
if ( V_19 )
return 0 ;
#ifdef F_31
if ( V_18 -> V_27 >= V_66 && V_18 -> V_27 != 0 )
return 0 ;
#endif
F_32 ( V_18 -> V_27 >= V_67 ) ;
if ( F_33 ( V_68 , V_18 -> V_27 ) != NULL &&
F_33 ( V_68 , V_18 -> V_27 ) != V_31 ) {
F_34 ( & V_31 -> V_2 ,
L_20 ,
V_18 -> V_27 ) ;
goto V_69;
}
F_33 ( V_68 , V_18 -> V_27 ) = V_31 ;
F_33 ( V_70 , V_18 -> V_27 ) = V_18 ;
V_2 = F_35 ( V_18 -> V_27 ) ;
if ( ! V_2 ) {
V_19 = - V_26 ;
goto V_69;
}
V_19 = F_36 ( V_2 , V_18 -> V_24 ) ;
if ( V_19 )
goto V_69;
V_18 -> V_2 = V_2 ;
V_2 -> V_71 = V_18 -> V_28 . V_29 ;
if ( F_37 ( V_2 ) >= 0 )
return 1 ;
F_20 ( V_2 , L_21 ) ;
F_38 ( V_2 ) ;
V_69:
F_39 ( V_18 -> V_53 . V_61 ) ;
V_31 -> V_65 = NULL ;
F_33 ( V_70 , V_18 -> V_27 ) = NULL ;
V_62:
F_40 ( V_18 ) ;
return V_19 ;
}
static void F_41 ( struct V_30 * V_31 )
{
struct V_17 * V_18 ;
if ( ! V_31 || ! F_16 ( V_31 ) )
return;
V_18 = F_16 ( V_31 ) ;
if ( V_18 -> V_27 >= V_67 )
goto V_72;
F_42 ( V_18 -> V_2 ) ;
F_38 ( V_18 -> V_2 ) ;
F_33 ( V_68 , V_18 -> V_27 ) = NULL ;
F_33 ( V_70 , V_18 -> V_27 ) = NULL ;
F_43 () ;
F_44 ( V_18 -> V_27 ) ;
F_13 ( V_18 -> V_27 ) ;
F_45 () ;
F_46 ( F_47 ( V_18 -> V_27 ) ) ;
V_72:
F_39 ( V_18 -> V_53 . V_61 ) ;
F_40 ( V_18 ) ;
}
void T_3 F_48 ( void )
{
F_49 ( & V_73 , L_22 ) ;
}
