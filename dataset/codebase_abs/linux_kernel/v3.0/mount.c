static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 = V_2 -> V_4 . V_5 . V_3 -> V_6 ;
const char * V_7 = V_2 -> V_4 . V_5 . V_7 -> V_6 ;
const char * type = V_2 -> V_4 . V_5 . type -> V_6 ;
const unsigned long V_8 = V_2 -> V_4 . V_5 . V_8 ;
if ( V_2 -> V_9 )
return 0 ;
if ( ! strcmp ( type , V_10 ) )
F_2 ( V_2 , L_1 , V_7 , V_8 ) ;
else if ( ! strcmp ( type , V_11 )
|| ! strcmp ( type , V_12 ) )
F_2 ( V_2 , L_2 , type , V_3 , V_7 ,
V_8 ) ;
else if ( ! strcmp ( type , V_13 ) ||
! strcmp ( type , V_14 ) ||
! strcmp ( type , V_15 ) ||
! strcmp ( type , V_16 ) )
F_2 ( V_2 , L_3 , type , V_7 , V_8 ) ;
else
F_2 ( V_2 , L_4 , type , V_3 , V_7 ,
V_8 ) ;
return F_3 ( V_2 ,
V_17 L_5 ,
F_4 ( V_2 -> V_4 . V_5 . V_3 ) ,
F_4 ( V_2 -> V_4 . V_5 . V_7 ) , type ,
V_8 ) ;
}
static bool F_5 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
const struct V_20 * V_21 =
F_6 ( V_19 , F_7 ( * V_21 ) , V_22 ) ;
return F_8 ( V_2 -> V_4 . V_5 . V_8 , & V_21 -> V_8 ) &&
F_9 ( V_2 -> V_4 . V_5 . type , & V_21 -> V_23 ) &&
F_9 ( V_2 -> V_4 . V_5 . V_7 , & V_21 -> V_24 ) &&
( ! V_2 -> V_4 . V_5 . V_25 ||
F_9 ( V_2 -> V_4 . V_5 . V_3 , & V_21 -> V_26 ) ) ;
}
static int V_20 ( struct V_1 * V_2 , char * V_26 ,
struct V_27 * V_7 , char * type , unsigned long V_8 )
{
struct V_27 V_27 ;
struct V_28 * V_29 = NULL ;
const char * V_30 = NULL ;
const char * V_31 = NULL ;
const char * V_32 = NULL ;
struct V_33 V_34 ;
struct V_33 V_35 ;
struct V_33 V_36 ;
int V_25 = 0 ;
int error = - V_37 ;
V_30 = F_10 ( type ) ;
if ( ! V_30 )
goto V_38;
V_34 . V_6 = V_30 ;
F_11 ( & V_34 ) ;
V_31 = F_12 ( V_7 ) ;
if ( ! V_31 ) {
error = - V_37 ;
goto V_38;
}
V_36 . V_6 = V_31 ;
F_11 ( & V_36 ) ;
if ( ! strcmp ( type , V_10 ) ) {
} else if ( ! strcmp ( type , V_13 ) ||
! strcmp ( type , V_14 ) ||
! strcmp ( type , V_15 ) ||
! strcmp ( type , V_16 ) ) {
} else if ( ! strcmp ( type , V_11 ) ||
! strcmp ( type , V_12 ) ) {
V_25 = - 1 ;
} else {
V_29 = F_13 ( type ) ;
if ( ! V_29 ) {
error = - V_39 ;
goto V_38;
}
if ( V_29 -> V_40 & V_41 )
V_25 = 1 ;
}
if ( V_25 ) {
if ( ! V_26 || F_14 ( V_26 , V_42 , & V_27 ) ) {
error = - V_43 ;
goto V_38;
}
V_32 = F_12 ( & V_27 ) ;
F_15 ( & V_27 ) ;
if ( ! V_32 ) {
error = - V_43 ;
goto V_38;
}
} else {
if ( ! V_26 )
V_26 = L_6 ;
V_32 = F_10 ( V_26 ) ;
if ( ! V_32 ) {
error = - V_37 ;
goto V_38;
}
}
V_35 . V_6 = V_32 ;
F_11 ( & V_35 ) ;
V_2 -> V_44 = V_45 ;
V_2 -> V_4 . V_5 . V_25 = V_25 ;
V_2 -> V_4 . V_5 . V_3 = & V_35 ;
V_2 -> V_4 . V_5 . V_7 = & V_36 ;
V_2 -> V_4 . V_5 . type = & V_34 ;
V_2 -> V_4 . V_5 . V_8 = V_8 ;
do {
F_16 ( V_2 , F_5 ) ;
error = F_1 ( V_2 ) ;
} while ( error == V_46 );
V_38:
F_17 ( V_32 ) ;
F_17 ( V_31 ) ;
if ( V_29 )
F_18 ( V_29 ) ;
F_17 ( V_30 ) ;
return error ;
}
int F_19 ( char * V_26 , struct V_27 * V_27 , char * type ,
unsigned long V_8 , void * V_47 )
{
struct V_1 V_2 ;
int error ;
int V_48 ;
if ( F_20 ( & V_2 , NULL , V_49 )
== V_50 )
return 0 ;
if ( ( V_8 & V_51 ) == V_52 )
V_8 &= ~ V_51 ;
if ( V_8 & V_53 ) {
type = V_10 ;
V_8 &= ~ V_53 ;
}
if ( V_8 & V_54 ) {
type = V_12 ;
V_8 &= ~ V_54 ;
}
if ( V_8 & V_55 ) {
type = V_11 ;
V_8 &= ~ V_55 ;
}
if ( V_8 & V_56 ) {
type = V_13 ;
V_8 &= ~ V_56 ;
}
if ( V_8 & V_57 ) {
type = V_14 ;
V_8 &= ~ V_57 ;
}
if ( V_8 & V_58 ) {
type = V_15 ;
V_8 &= ~ V_58 ;
}
if ( V_8 & V_59 ) {
type = V_16 ;
V_8 &= ~ V_59 ;
}
if ( ! type )
type = L_6 ;
V_48 = F_21 () ;
error = V_20 ( & V_2 , V_26 , V_27 , type , V_8 ) ;
F_22 ( V_48 ) ;
return error ;
}
static bool F_23 ( const struct V_18 * V_60 ,
const struct V_18 * V_61 )
{
const struct V_20 * V_62 = F_6 ( V_60 , F_7 ( * V_62 ) , V_22 ) ;
const struct V_20 * V_63 = F_6 ( V_61 , F_7 ( * V_63 ) , V_22 ) ;
return F_24 ( & V_62 -> V_22 , & V_63 -> V_22 ) &&
F_25 ( & V_62 -> V_26 , & V_63 -> V_26 ) &&
F_25 ( & V_62 -> V_24 , & V_63 -> V_24 ) &&
F_25 ( & V_62 -> V_23 , & V_63 -> V_23 ) &&
F_26 ( & V_62 -> V_8 , & V_63 -> V_8 ) ;
}
int F_27 ( char * V_64 , struct V_65 * V_66 ,
const bool V_67 )
{
struct V_20 V_68 = { . V_22 . type = V_45 } ;
int error = V_67 ? - V_43 : - V_37 ;
char * V_69 [ 4 ] ;
if ( ! F_28 ( V_64 , V_69 , sizeof( V_69 ) ) || ! V_69 [ 3 ] [ 0 ] )
return - V_70 ;
if ( ! F_29 ( V_69 [ 0 ] , & V_68 . V_26 ) ||
! F_29 ( V_69 [ 1 ] , & V_68 . V_24 ) ||
! F_29 ( V_69 [ 2 ] , & V_68 . V_23 ) ||
! F_30 ( V_69 [ 3 ] , & V_68 . V_8 ) )
goto V_38;
error = F_31 ( & V_68 . V_22 , sizeof( V_68 ) , V_67 , V_66 ,
F_23 , NULL ) ;
V_38:
F_32 ( & V_68 . V_26 ) ;
F_32 ( & V_68 . V_24 ) ;
F_32 ( & V_68 . V_23 ) ;
F_33 ( & V_68 . V_8 ) ;
return error ;
}
