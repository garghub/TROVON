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
F_11 () ;
F_12 () ;
V_23 = F_13 ( V_18 -> V_24 , & V_18 -> V_27 ) ;
if ( V_23 )
goto V_28;
V_23 = F_14 ( V_18 -> V_27 ) ;
if ( V_23 ) {
F_15 ( V_18 -> V_27 ) ;
goto V_28;
}
F_16 ( L_9 , V_18 -> V_27 ) ;
V_18 -> V_29 . V_30 = 1 ;
V_28:
F_17 () ;
F_18 () ;
return V_23 ;
}
static inline int F_8 ( struct V_17 * V_18 )
{
return - V_26 ;
}
static int F_19 ( struct V_31 * V_32 )
{
union V_33 V_34 = { 0 } ;
struct V_35 V_36 = { sizeof( union V_33 ) , & V_34 } ;
struct V_17 * V_18 = F_20 ( V_32 ) ;
int V_37 , V_38 = 0 ;
T_2 V_22 = V_39 ;
static int V_40 ;
if ( F_21 () > 1 )
V_8 . V_41 = TRUE ;
F_7 ( V_18 ) ;
if ( V_42 . V_43 && V_42 . V_44 ) {
V_18 -> V_29 . V_45 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_22 ( V_32 ) , V_46 ) ) {
V_22 = F_23 ( V_18 -> V_24 , NULL , NULL , & V_36 ) ;
if ( F_10 ( V_22 ) ) {
F_24 ( & V_32 -> V_2 ,
L_12 ,
V_22 ) ;
return - V_26 ;
}
V_18 -> V_47 = V_34 . V_48 . V_49 ;
} else {
unsigned long long V_50 ;
V_22 = F_9 ( V_18 -> V_24 , V_51 ,
NULL , & V_50 ) ;
if ( F_10 ( V_22 ) ) {
F_24 ( & V_32 -> V_2 ,
L_13 ,
V_22 ) ;
return - V_26 ;
}
V_38 = 1 ;
V_18 -> V_47 = V_50 ;
}
V_37 = F_25 ( V_18 -> V_24 , V_38 , V_18 -> V_47 ) ;
if ( ! V_40 && ( V_37 == - 1 ) &&
( F_21 () == 1 ) ) {
V_37 = 0 ;
}
V_40 = 1 ;
V_18 -> V_27 = V_37 ;
if ( V_18 -> V_27 == - 1 ) {
int V_23 = F_8 ( V_18 ) ;
if ( V_23 )
return V_23 ;
}
sprintf ( F_26 ( V_32 ) , L_14 , V_18 -> V_27 ) ;
F_2 ( ( V_7 , L_15 , V_18 -> V_27 ,
V_18 -> V_47 ) ) ;
if ( ! V_34 . V_48 . V_52 )
F_2 ( ( V_7 , L_16 ) ) ;
else if ( V_34 . V_48 . V_53 != 6 )
F_24 ( & V_32 -> V_2 , L_17 ,
V_34 . V_48 . V_53 ) ;
else {
V_18 -> V_54 . V_55 = V_34 . V_48 . V_52 ;
V_18 -> V_54 . V_56 = V_42 . V_56 ;
V_18 -> V_54 . V_57 = V_42 . V_57 ;
V_18 -> V_58 = V_34 . V_48 . V_52 ;
F_27 ( V_18 -> V_54 . V_55 , 6 , L_18 ) ;
}
V_22 = F_23 ( V_18 -> V_24 , L_19 , NULL , & V_36 ) ;
if ( F_28 ( V_22 ) )
F_29 ( V_18 -> V_27 , V_34 . integer . V_50 ) ;
return 0 ;
}
static int F_30 ( struct V_31 * V_32 ,
const struct V_59 * V_27 )
{
struct V_17 * V_18 ;
struct V_32 * V_2 ;
int V_19 = 0 ;
V_18 = F_31 ( sizeof( struct V_17 ) , V_60 ) ;
if ( ! V_18 )
return - V_61 ;
if ( ! F_32 ( & V_18 -> V_54 . V_62 , V_60 ) ) {
V_19 = - V_61 ;
goto V_63;
}
V_18 -> V_24 = V_32 -> V_24 ;
strcpy ( F_33 ( V_32 ) , V_64 ) ;
strcpy ( F_34 ( V_32 ) , V_65 ) ;
V_32 -> V_66 = V_18 ;
V_19 = F_19 ( V_32 ) ;
if ( V_19 )
return 0 ;
#ifdef F_35
if ( V_18 -> V_27 >= V_67 && V_18 -> V_27 != 0 )
return 0 ;
#endif
F_36 ( V_18 -> V_27 >= V_68 ) ;
if ( F_37 ( V_69 , V_18 -> V_27 ) != NULL &&
F_37 ( V_69 , V_18 -> V_27 ) != V_32 ) {
F_38 ( & V_32 -> V_2 ,
L_20 ,
V_18 -> V_27 ) ;
goto V_70;
}
F_37 ( V_69 , V_18 -> V_27 ) = V_32 ;
F_37 ( V_71 , V_18 -> V_27 ) = V_18 ;
V_2 = F_39 ( V_18 -> V_27 ) ;
if ( ! V_2 ) {
V_19 = - V_26 ;
goto V_70;
}
V_19 = F_40 ( V_2 , V_18 -> V_24 ) ;
if ( V_19 )
goto V_70;
V_18 -> V_2 = V_2 ;
V_2 -> V_72 = V_18 -> V_29 . V_30 ;
if ( F_41 ( V_2 ) >= 0 )
return 1 ;
F_24 ( V_2 , L_21 ) ;
F_42 ( V_2 ) ;
V_70:
F_43 ( V_18 -> V_54 . V_62 ) ;
V_32 -> V_66 = NULL ;
F_37 ( V_71 , V_18 -> V_27 ) = NULL ;
V_63:
F_44 ( V_18 ) ;
return V_19 ;
}
static void F_45 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
if ( ! V_32 || ! F_20 ( V_32 ) )
return;
V_18 = F_20 ( V_32 ) ;
if ( V_18 -> V_27 >= V_68 )
goto V_28;
F_46 ( V_18 -> V_2 ) ;
F_42 ( V_18 -> V_2 ) ;
F_37 ( V_69 , V_18 -> V_27 ) = NULL ;
F_37 ( V_71 , V_18 -> V_27 ) = NULL ;
F_11 () ;
F_12 () ;
F_47 ( V_18 -> V_27 ) ;
F_15 ( V_18 -> V_27 ) ;
F_17 () ;
F_18 () ;
F_48 ( F_49 ( V_18 -> V_27 ) ) ;
V_28:
F_43 ( V_18 -> V_54 . V_62 ) ;
F_44 ( V_18 ) ;
}
void T_3 F_50 ( void )
{
F_51 ( & V_73 , L_22 ) ;
}
