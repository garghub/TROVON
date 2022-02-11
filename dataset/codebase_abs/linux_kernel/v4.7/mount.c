static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , L_1 ,
V_2 -> V_3 . V_4 . V_5 -> V_6 ,
V_2 -> V_3 . V_4 . V_7 -> V_6 ,
V_2 -> V_3 . V_4 . type -> V_6 ,
V_2 -> V_3 . V_4 . V_8 ) ;
}
static bool F_3 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
const struct V_11 * V_12 =
F_4 ( V_10 , F_5 ( * V_12 ) , V_13 ) ;
return F_6 ( V_2 -> V_3 . V_4 . V_8 ,
& V_12 -> V_8 ) &&
F_7 ( V_2 -> V_3 . V_4 . type ,
& V_12 -> V_14 ) &&
F_7 ( V_2 -> V_3 . V_4 . V_7 ,
& V_12 -> V_15 ) &&
( ! V_2 -> V_3 . V_4 . V_16 ||
F_7 ( V_2 -> V_3 . V_4 . V_5 ,
& V_12 -> V_17 ) ) ;
}
static int V_11 ( struct V_1 * V_2 ,
const char * V_17 ,
const struct V_18 * V_7 , const char * type ,
unsigned long V_8 )
{
struct V_19 V_20 = { } ;
struct V_18 V_18 ;
struct V_21 * V_22 = NULL ;
const char * V_23 = NULL ;
const char * V_24 = NULL ;
const char * V_25 = NULL ;
struct V_26 V_27 ;
struct V_26 V_28 ;
struct V_26 V_29 ;
int V_16 = 0 ;
int error = - V_30 ;
V_2 -> V_20 = & V_20 ;
V_23 = F_8 ( type ) ;
if ( ! V_23 )
goto V_31;
V_27 . V_6 = V_23 ;
F_9 ( & V_27 ) ;
V_20 . V_32 = * V_7 ;
V_24 = F_10 ( V_7 ) ;
if ( ! V_24 ) {
error = - V_30 ;
goto V_31;
}
V_29 . V_6 = V_24 ;
F_9 ( & V_29 ) ;
if ( type == V_33 [ V_34 ] ) {
} else if ( type == V_33 [ V_35 ] ||
type == V_33 [ V_36 ] ||
type == V_33 [ V_37 ] ||
type == V_33 [ V_38 ] ) {
} else if ( type == V_33 [ V_39 ] ||
type == V_33 [ V_40 ] ) {
V_16 = - 1 ;
} else {
V_22 = F_11 ( type ) ;
if ( ! V_22 ) {
error = - V_41 ;
goto V_31;
}
if ( V_22 -> V_42 & V_43 )
V_16 = 1 ;
}
if ( V_16 ) {
if ( ! V_17 || F_12 ( V_17 , V_44 , & V_18 ) ) {
error = - V_45 ;
goto V_31;
}
V_20 . V_46 = V_18 ;
V_25 = F_10 ( & V_18 ) ;
if ( ! V_25 ) {
error = - V_45 ;
goto V_31;
}
} else {
if ( ! V_17 )
V_17 = L_2 ;
V_25 = F_8 ( V_17 ) ;
if ( ! V_25 ) {
error = - V_30 ;
goto V_31;
}
}
V_28 . V_6 = V_25 ;
F_9 ( & V_28 ) ;
V_2 -> V_47 = V_48 ;
V_2 -> V_3 . V_4 . V_16 = V_16 ;
V_2 -> V_3 . V_4 . V_5 = & V_28 ;
V_2 -> V_3 . V_4 . V_7 = & V_29 ;
V_2 -> V_3 . V_4 . type = & V_27 ;
V_2 -> V_3 . V_4 . V_8 = V_8 ;
do {
F_13 ( V_2 , F_3 ) ;
error = F_1 ( V_2 ) ;
} while ( error == V_49 );
V_31:
F_14 ( V_25 ) ;
F_14 ( V_24 ) ;
if ( V_22 )
F_15 ( V_22 ) ;
F_14 ( V_23 ) ;
if ( V_20 . V_46 . V_50 )
F_16 ( & V_20 . V_46 ) ;
return error ;
}
int F_17 ( const char * V_17 , const struct V_18 * V_18 ,
const char * type , unsigned long V_8 ,
void * V_51 )
{
struct V_1 V_2 ;
int error ;
int V_52 ;
if ( F_18 ( & V_2 , NULL , V_53 )
== V_54 )
return 0 ;
if ( ( V_8 & V_55 ) == V_56 )
V_8 &= ~ V_55 ;
if ( V_8 & V_57 ) {
type = V_33 [ V_34 ] ;
V_8 &= ~ V_57 ;
} else if ( V_8 & V_58 ) {
type = V_33 [ V_39 ] ;
V_8 &= ~ V_58 ;
} else if ( V_8 & V_59 ) {
if ( V_8 & ( V_60 | V_61 | V_62 ) )
return - V_63 ;
type = V_33 [ V_38 ] ;
V_8 &= ~ V_59 ;
} else if ( V_8 & V_60 ) {
if ( V_8 & ( V_59 | V_61 | V_62 ) )
return - V_63 ;
type = V_33 [ V_36 ] ;
V_8 &= ~ V_60 ;
} else if ( V_8 & V_61 ) {
if ( V_8 & ( V_59 | V_60 | V_62 ) )
return - V_63 ;
type = V_33 [ V_37 ] ;
V_8 &= ~ V_61 ;
} else if ( V_8 & V_62 ) {
if ( V_8 & ( V_59 | V_60 | V_61 ) )
return - V_63 ;
type = V_33 [ V_35 ] ;
V_8 &= ~ V_62 ;
} else if ( V_8 & V_64 ) {
type = V_33 [ V_40 ] ;
V_8 &= ~ V_64 ;
}
if ( ! type )
type = L_2 ;
V_52 = F_19 () ;
error = V_11 ( & V_2 , V_17 , V_18 , type , V_8 ) ;
F_20 ( V_52 ) ;
return error ;
}
