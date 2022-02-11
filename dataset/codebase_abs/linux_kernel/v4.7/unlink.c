static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> args . V_4 . V_4 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_5 * V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_8 * V_9 = F_5 ( V_2 -> V_10 -> V_11 ) ;
F_6 ( V_2 , V_6 -> V_12 ) ;
if ( ! F_7 ( V_9 ) -> F_8 ( V_6 , V_9 ) )
F_9 ( V_6 ) ;
}
static void F_10 ( void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_10 * V_10 = V_2 -> V_10 ;
struct V_13 * V_14 = V_10 -> V_15 ;
F_11 ( & F_12 ( F_5 ( V_10 -> V_11 ) ) -> V_16 ) ;
F_13 ( V_10 ) ;
F_1 ( V_2 ) ;
F_14 ( V_10 ) ;
F_15 ( V_14 ) ;
}
static void F_16 ( struct V_5 * V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_8 * V_9 = F_5 ( V_2 -> V_10 -> V_11 ) ;
F_7 ( V_9 ) -> F_17 ( V_6 , V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_17 V_18 = {
. V_19 = & V_2 -> args ,
. V_20 = & V_2 -> V_21 ,
. V_22 = V_2 -> V_3 ,
} ;
struct V_23 V_24 = {
. V_17 = & V_18 ,
. V_25 = & V_26 ,
. V_27 = V_2 ,
. V_28 = V_29 ,
. V_30 = V_31 ,
} ;
struct V_5 * V_6 ;
struct V_8 * V_9 = F_5 ( V_2 -> V_10 -> V_11 ) ;
F_19 ( V_9 -> V_32 ) ;
V_2 -> args . V_33 = F_20 ( V_9 ) ;
F_21 ( V_2 -> V_21 . V_34 ) ;
F_7 ( V_9 ) -> F_22 ( & V_18 , V_9 ) ;
V_24 . V_35 = F_23 ( V_9 ) ;
V_6 = F_24 ( & V_24 ) ;
if ( ! F_25 ( V_6 ) )
F_26 ( V_6 ) ;
}
static int F_27 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_10 -> V_11 ) ;
struct V_10 * V_36 ;
F_28 ( & F_12 ( V_9 ) -> V_16 ) ;
V_36 = F_29 ( V_10 -> V_11 , & V_2 -> args . V_4 , & V_2 -> V_37 ) ;
if ( F_25 ( V_36 ) ) {
F_11 ( & F_12 ( V_9 ) -> V_16 ) ;
return 0 ;
}
if ( ! F_30 ( V_36 ) ) {
int V_38 ;
void * V_39 = NULL ;
F_31 ( & V_36 -> V_40 ) ;
if ( F_32 ( V_36 ) &&
! ( V_36 -> V_41 & V_42 ) ) {
V_39 = V_36 -> V_43 ;
V_36 -> V_43 = V_2 ;
V_36 -> V_41 |= V_42 ;
V_38 = 1 ;
} else
V_38 = 0 ;
F_33 ( & V_36 -> V_40 ) ;
F_14 ( V_36 ) ;
F_11 ( & F_12 ( V_9 ) -> V_16 ) ;
F_3 ( V_39 ) ;
return V_38 ;
}
V_2 -> V_10 = V_36 ;
F_18 ( V_2 ) ;
return 1 ;
}
static int
F_34 ( struct V_10 * V_10 , struct V_44 * V_4 )
{
struct V_1 * V_2 ;
int V_45 = - V_46 ;
void * V_39 = NULL ;
V_2 = F_35 ( sizeof( * V_2 ) , V_47 ) ;
if ( V_2 == NULL )
goto V_48;
V_2 -> args . V_4 . V_4 = F_36 ( V_4 -> V_4 , V_47 ) ;
if ( ! V_2 -> args . V_4 . V_4 )
goto V_49;
V_2 -> args . V_4 . V_50 = V_4 -> V_50 ;
V_2 -> V_3 = F_37 () ;
if ( F_25 ( V_2 -> V_3 ) ) {
V_45 = F_38 ( V_2 -> V_3 ) ;
goto V_51;
}
V_2 -> V_21 . V_34 = & V_2 -> V_34 ;
F_39 ( & V_2 -> V_37 ) ;
V_45 = - V_52 ;
F_31 ( & V_10 -> V_40 ) ;
if ( V_10 -> V_41 & V_42 )
goto V_53;
V_10 -> V_41 |= V_42 ;
V_39 = V_10 -> V_43 ;
V_10 -> V_43 = V_2 ;
F_33 ( & V_10 -> V_40 ) ;
F_3 ( V_39 ) ;
return 0 ;
V_53:
F_33 ( & V_10 -> V_40 ) ;
F_2 ( V_2 -> V_3 ) ;
V_51:
F_3 ( V_2 -> args . V_4 . V_4 ) ;
V_49:
F_3 ( V_2 ) ;
V_48:
return V_45 ;
}
void
F_40 ( struct V_10 * V_10 , struct V_8 * V_8 )
{
struct V_1 * V_2 ;
F_31 ( & V_10 -> V_40 ) ;
V_10 -> V_41 &= ~ V_42 ;
V_2 = V_10 -> V_43 ;
V_10 -> V_43 = NULL ;
F_33 ( & V_10 -> V_40 ) ;
if ( F_41 ( V_8 ) || ! F_27 ( V_10 , V_2 ) )
F_1 ( V_2 ) ;
}
static void
F_42 ( struct V_10 * V_10 )
{
F_31 ( & V_10 -> V_40 ) ;
if ( V_10 -> V_41 & V_42 ) {
struct V_1 * V_2 = V_10 -> V_43 ;
V_10 -> V_41 &= ~ V_42 ;
V_10 -> V_43 = NULL ;
F_33 ( & V_10 -> V_40 ) ;
F_1 ( V_2 ) ;
return;
}
F_33 ( & V_10 -> V_40 ) ;
}
static void F_43 ( struct V_5 * V_6 , void * V_7 )
{
struct V_54 * V_2 = V_7 ;
struct V_8 * V_55 = V_2 -> V_55 ;
struct V_8 * V_56 = V_2 -> V_56 ;
struct V_10 * V_57 = V_2 -> V_57 ;
F_44 ( V_55 , V_57 ,
V_56 , V_2 -> V_58 , V_6 -> V_12 ) ;
if ( ! F_7 ( V_55 ) -> F_45 ( V_6 , V_55 , V_56 ) ) {
F_9 ( V_6 ) ;
return;
}
if ( V_2 -> V_59 )
V_2 -> V_59 ( V_6 , V_2 ) ;
}
static void F_46 ( void * V_7 )
{
struct V_54 * V_2 = V_7 ;
struct V_13 * V_14 = V_2 -> V_55 -> V_32 ;
if ( F_32 ( V_2 -> V_57 ) )
F_47 ( F_5 ( V_2 -> V_57 ) ) ;
F_14 ( V_2 -> V_57 ) ;
F_14 ( V_2 -> V_58 ) ;
F_48 ( V_2 -> V_55 ) ;
F_48 ( V_2 -> V_56 ) ;
F_15 ( V_14 ) ;
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
}
static void F_49 ( struct V_5 * V_6 , void * V_7 )
{
struct V_54 * V_2 = V_7 ;
F_7 ( V_2 -> V_55 ) -> F_50 ( V_6 , V_2 ) ;
}
struct V_5 *
F_51 ( struct V_8 * V_55 , struct V_8 * V_56 ,
struct V_10 * V_57 , struct V_10 * V_58 ,
void (* V_59)( struct V_5 * , struct V_54 * ) )
{
struct V_54 * V_2 ;
struct V_17 V_18 = { } ;
struct V_23 V_24 = {
. V_17 = & V_18 ,
. V_25 = & V_60 ,
. V_28 = V_29 ,
. V_35 = F_23 ( V_55 ) ,
. V_30 = V_31 ,
} ;
V_2 = F_35 ( sizeof( * V_2 ) , V_47 ) ;
if ( V_2 == NULL )
return F_52 ( - V_46 ) ;
V_24 . V_27 = V_2 ;
V_2 -> V_3 = F_37 () ;
if ( F_25 ( V_2 -> V_3 ) ) {
struct V_5 * V_6 = F_53 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
return V_6 ;
}
V_18 . V_19 = & V_2 -> args ;
V_18 . V_20 = & V_2 -> V_21 ;
V_18 . V_22 = V_2 -> V_3 ;
V_2 -> V_55 = V_55 ;
F_54 ( V_55 ) ;
V_2 -> V_56 = V_56 ;
F_54 ( V_56 ) ;
V_2 -> V_57 = F_55 ( V_57 ) ;
V_2 -> V_58 = F_55 ( V_58 ) ;
F_21 ( & V_2 -> V_61 ) ;
F_21 ( & V_2 -> V_62 ) ;
V_2 -> V_59 = V_59 ;
V_2 -> args . V_55 = F_20 ( V_55 ) ;
V_2 -> args . V_63 = & V_57 -> V_64 ;
V_2 -> args . V_56 = F_20 ( V_56 ) ;
V_2 -> args . V_65 = & V_58 -> V_64 ;
V_2 -> V_21 . V_61 = & V_2 -> V_61 ;
V_2 -> V_21 . V_62 = & V_2 -> V_62 ;
F_19 ( V_55 -> V_32 ) ;
F_7 ( V_2 -> V_55 ) -> F_56 ( & V_18 , V_55 ) ;
return F_24 ( & V_24 ) ;
}
static void
F_57 ( struct V_5 * V_6 , struct V_54 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_57 ;
if ( V_6 -> V_12 != 0 ) {
F_42 ( V_10 ) ;
return;
}
F_58 ( V_10 , 0 ) ;
}
int
F_59 ( struct V_8 * V_9 , struct V_10 * V_10 )
{
static unsigned int V_66 ;
unsigned char V_67 [ V_68 + 1 ] ;
unsigned long long V_69 ;
struct V_10 * V_70 ;
struct V_5 * V_6 ;
int error = - V_52 ;
F_60 ( V_71 , L_1 ,
V_10 , F_61 ( V_10 ) ) ;
F_62 ( V_9 , V_72 ) ;
if ( V_10 -> V_41 & V_42 )
goto V_48;
V_69 = F_63 ( F_5 ( V_10 ) ) ;
F_7 ( F_5 ( V_10 ) ) -> F_64 ( F_5 ( V_10 ) ) ;
V_70 = NULL ;
do {
int V_73 ;
F_14 ( V_70 ) ;
V_66 ++ ;
V_73 = F_65 ( V_67 , sizeof( V_67 ) ,
V_74 L_2 ,
V_75 , V_69 ,
V_76 , V_66 ) ;
F_60 ( V_71 , L_3 ,
V_10 , V_67 ) ;
V_70 = F_66 ( V_67 , V_10 -> V_11 , V_73 ) ;
if ( F_25 ( V_70 ) )
goto V_48;
} while ( F_5 ( V_70 ) != NULL );
error = F_34 ( V_10 , & V_70 -> V_64 ) ;
if ( error )
goto V_77;
V_6 = F_51 ( V_9 , V_9 , V_10 , V_70 ,
F_57 ) ;
if ( F_25 ( V_6 ) ) {
error = - V_52 ;
F_42 ( V_10 ) ;
goto V_77;
}
error = F_67 ( V_6 ) ;
if ( error == 0 )
error = V_6 -> V_12 ;
switch ( error ) {
case 0 :
F_68 ( V_10 , F_69 ( V_9 ) ) ;
F_70 ( V_10 , V_70 ) ;
break;
case - V_78 :
F_71 ( V_10 ) ;
F_71 ( V_70 ) ;
}
F_72 ( V_6 ) ;
V_77:
F_14 ( V_70 ) ;
V_48:
return error ;
}
