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
V_22 = F_9 ( V_20 -> V_24 , L_8 , NULL , & V_21 ) ;
if ( F_10 ( V_22 ) || ! ( V_21 & V_25 ) )
return - V_26 ;
F_11 () ;
F_12 () ;
V_23 = F_13 ( V_20 -> V_24 , V_20 -> V_27 , & V_20 -> V_28 ) ;
if ( V_23 )
goto V_29;
V_23 = F_14 ( V_20 -> V_28 ) ;
if ( V_23 ) {
F_15 ( V_20 -> V_28 ) ;
goto V_29;
}
F_16 ( L_9 , V_20 -> V_28 ) ;
V_20 -> V_30 . V_31 = 1 ;
V_29:
F_17 () ;
F_18 () ;
return V_23 ;
}
static inline int F_8 ( struct V_19 * V_20 )
{
return - V_26 ;
}
static int F_19 ( struct V_32 * V_33 )
{
union V_34 V_35 = { 0 } ;
struct V_36 V_37 = { sizeof( union V_34 ) , & V_35 } ;
struct V_19 * V_20 = F_20 ( V_33 ) ;
int V_38 , V_39 = 0 ;
T_2 V_22 = V_40 ;
static int V_41 ;
unsigned long long V_42 ;
F_7 () ;
if ( V_43 . V_44 && V_43 . V_45 ) {
V_20 -> V_30 . V_46 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_21 ( V_33 ) , V_47 ) ) {
V_22 = F_22 ( V_20 -> V_24 , NULL , NULL , & V_37 ) ;
if ( F_10 ( V_22 ) ) {
F_23 ( & V_33 -> V_2 ,
L_12 ,
V_22 ) ;
return - V_26 ;
}
V_20 -> V_48 = V_35 . V_49 . V_50 ;
} else {
V_22 = F_9 ( V_20 -> V_24 , V_51 ,
NULL , & V_42 ) ;
if ( F_10 ( V_22 ) ) {
F_23 ( & V_33 -> V_2 ,
L_13 ,
V_22 ) ;
return - V_26 ;
}
V_39 = 1 ;
V_20 -> V_48 = V_42 ;
}
V_20 -> V_27 = F_24 ( V_20 -> V_24 , V_39 ,
V_20 -> V_48 ) ;
V_38 = F_25 ( V_20 -> V_27 , V_20 -> V_48 ) ;
if ( ! V_41 && ( V_38 == - 1 ) &&
( F_26 () == 1 ) ) {
V_38 = 0 ;
}
V_41 = 1 ;
V_20 -> V_28 = V_38 ;
if ( V_20 -> V_28 == - 1 ) {
int V_23 = F_8 ( V_20 ) ;
if ( V_23 )
return V_23 ;
}
sprintf ( F_27 ( V_33 ) , L_14 , V_20 -> V_28 ) ;
F_2 ( ( V_7 , L_15 , V_20 -> V_28 ,
V_20 -> V_48 ) ) ;
if ( ! V_35 . V_49 . V_52 )
F_2 ( ( V_7 , L_16 ) ) ;
else if ( V_35 . V_49 . V_53 != 6 )
F_23 ( & V_33 -> V_2 , L_17 ,
V_35 . V_49 . V_53 ) ;
else {
V_20 -> V_54 . V_55 = V_35 . V_49 . V_52 ;
V_20 -> V_54 . V_56 = V_43 . V_56 ;
V_20 -> V_54 . V_57 = V_43 . V_57 ;
V_20 -> V_58 = V_35 . V_49 . V_52 ;
F_28 ( V_20 -> V_54 . V_55 , 6 , L_18 ) ;
}
V_22 = F_9 ( V_20 -> V_24 , L_19 , NULL , & V_42 ) ;
if ( F_29 ( V_22 ) )
F_30 ( V_20 -> V_28 , V_42 ) ;
return 0 ;
}
static int F_31 ( struct V_32 * V_33 ,
const struct V_59 * V_28 )
{
struct V_19 * V_20 ;
struct V_33 * V_2 ;
int V_17 = 0 ;
V_20 = F_32 ( sizeof( struct V_19 ) , V_60 ) ;
if ( ! V_20 )
return - V_61 ;
if ( ! F_33 ( & V_20 -> V_54 . V_62 , V_60 ) ) {
V_17 = - V_61 ;
goto V_63;
}
V_20 -> V_24 = V_33 -> V_24 ;
strcpy ( F_34 ( V_33 ) , V_64 ) ;
strcpy ( F_35 ( V_33 ) , V_65 ) ;
V_33 -> V_66 = V_20 ;
V_17 = F_19 ( V_33 ) ;
if ( V_17 )
return 0 ;
#ifdef F_36
if ( V_20 -> V_28 >= V_67 && V_20 -> V_28 != 0 )
return 0 ;
#endif
F_37 ( V_20 -> V_28 >= V_68 ) ;
if ( F_38 ( V_69 , V_20 -> V_28 ) != NULL &&
F_38 ( V_69 , V_20 -> V_28 ) != V_33 ) {
F_39 ( & V_33 -> V_2 ,
L_20 ,
V_20 -> V_28 ) ;
goto V_70;
}
F_38 ( V_69 , V_20 -> V_28 ) = V_33 ;
F_38 ( V_71 , V_20 -> V_28 ) = V_20 ;
V_2 = F_40 ( V_20 -> V_28 ) ;
if ( ! V_2 ) {
V_17 = - V_26 ;
goto V_70;
}
V_17 = F_41 ( V_2 , V_20 -> V_24 ) ;
if ( V_17 )
goto V_70;
V_20 -> V_2 = V_2 ;
V_2 -> V_72 = V_20 -> V_30 . V_31 ;
if ( F_42 ( V_2 ) >= 0 )
return 1 ;
F_23 ( V_2 , L_21 ) ;
F_43 ( V_2 ) ;
V_70:
F_44 ( V_20 -> V_54 . V_62 ) ;
V_33 -> V_66 = NULL ;
F_38 ( V_71 , V_20 -> V_28 ) = NULL ;
V_63:
F_45 ( V_20 ) ;
return V_17 ;
}
static void F_46 ( struct V_32 * V_33 )
{
struct V_19 * V_20 ;
if ( ! V_33 || ! F_20 ( V_33 ) )
return;
V_20 = F_20 ( V_33 ) ;
if ( V_20 -> V_28 >= V_68 )
goto V_29;
F_47 ( V_20 -> V_2 ) ;
F_43 ( V_20 -> V_2 ) ;
F_38 ( V_69 , V_20 -> V_28 ) = NULL ;
F_38 ( V_71 , V_20 -> V_28 ) = NULL ;
F_11 () ;
F_12 () ;
F_48 ( V_20 -> V_28 ) ;
F_15 ( V_20 -> V_28 ) ;
F_17 () ;
F_18 () ;
F_49 ( F_50 ( V_20 -> V_28 ) ) ;
V_29:
F_44 ( V_20 -> V_54 . V_62 ) ;
F_45 ( V_20 ) ;
}
void T_3 F_51 ( void )
{
F_52 ( & V_73 , L_22 ) ;
}
