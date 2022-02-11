static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 -> args . V_5 . V_5 ) ;
F_4 ( V_2 ) ;
}
static int F_5 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
char * V_7 ;
int V_8 = V_6 -> V_9 . V_8 ;
V_7 = F_6 ( V_6 -> V_9 . V_5 , F_7 ( V_8 ) , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_2 -> args . V_5 . V_8 = V_8 ;
V_2 -> args . V_5 . V_5 = V_7 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> args . V_5 . V_5 ) ;
V_2 -> args . V_5 . V_5 = NULL ;
V_2 -> args . V_5 . V_8 = 0 ;
}
static void F_9 ( struct V_12 * V_3 )
{
struct V_13 * V_14 = F_10 ( V_3 ) ;
if ( F_11 ( & V_14 -> V_15 ) == 1 )
F_12 ( & V_14 -> V_16 ) ;
}
static void F_13 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_12 * V_3 = V_2 -> V_3 ;
if ( ! F_14 ( V_3 ) -> F_15 ( V_18 , V_3 ) )
F_16 ( V_18 ) ;
}
static void F_17 ( void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 * V_21 = V_2 -> V_3 -> V_22 ;
F_9 ( V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
F_18 ( V_21 ) ;
}
static void F_19 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
F_14 ( V_2 -> V_3 ) -> F_20 ( V_18 , V_2 ) ;
}
static int F_21 ( struct V_6 * V_23 , struct V_12 * V_3 , struct V_1 * V_2 )
{
struct V_24 V_25 = {
. V_26 = & V_2 -> args ,
. V_27 = & V_2 -> V_28 ,
. V_29 = V_2 -> V_4 ,
} ;
struct V_30 V_31 = {
. V_24 = & V_25 ,
. V_32 = & V_33 ,
. V_34 = V_2 ,
. V_35 = V_36 ,
. V_37 = V_38 ,
} ;
struct V_17 * V_18 ;
struct V_6 * V_39 ;
V_39 = F_22 ( V_23 , & V_2 -> args . V_5 ) ;
if ( V_39 != NULL ) {
int V_40 ;
void * V_41 = NULL ;
F_8 ( V_2 ) ;
V_40 = F_5 ( V_39 , V_2 ) ;
F_23 ( & V_39 -> V_42 ) ;
if ( V_40 == 0 && V_39 -> V_43 != NULL &&
! ( V_39 -> V_44 & V_45 ) ) {
V_41 = V_39 -> V_46 ;
V_39 -> V_46 = V_2 ;
V_39 -> V_44 |= V_45 ;
V_40 = 1 ;
} else
V_40 = 0 ;
F_24 ( & V_39 -> V_42 ) ;
F_9 ( V_3 ) ;
F_25 ( V_39 ) ;
F_4 ( V_41 ) ;
return V_40 ;
}
V_2 -> V_3 = F_26 ( V_3 ) ;
if ( ! V_2 -> V_3 ) {
F_9 ( V_3 ) ;
return 0 ;
}
F_27 ( V_3 -> V_22 ) ;
V_2 -> args . V_47 = F_28 ( V_3 ) ;
F_29 ( V_2 -> V_28 . V_48 ) ;
F_14 ( V_3 ) -> F_30 ( & V_25 , V_3 ) ;
V_31 . V_49 = F_31 ( V_3 ) ;
V_18 = F_32 ( & V_31 ) ;
if ( ! F_33 ( V_18 ) )
F_34 ( V_18 ) ;
return 1 ;
}
static int F_35 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
struct V_6 * V_23 ;
struct V_12 * V_3 ;
int V_40 = 0 ;
V_23 = F_36 ( V_6 ) ;
if ( V_23 == NULL )
goto V_50;
V_3 = V_23 -> V_43 ;
F_23 ( & V_3 -> V_51 ) ;
if ( F_37 ( & F_10 ( V_3 ) -> V_15 ) == 0 ) {
F_38 ( & V_2 -> V_52 , & F_10 ( V_3 ) -> V_53 ) ;
F_24 ( & V_3 -> V_51 ) ;
V_40 = 1 ;
goto V_54;
}
F_24 ( & V_3 -> V_51 ) ;
V_40 = F_21 ( V_23 , V_3 , V_2 ) ;
V_54:
F_25 ( V_23 ) ;
V_50:
return V_40 ;
}
void F_39 ( struct V_6 * V_6 )
{
struct V_13 * V_14 = F_10 ( V_6 -> V_43 ) ;
F_40 ( V_14 -> V_16 , F_41 ( & V_14 -> V_15 , 1 , 0 ) == 1 ) ;
}
void F_42 ( struct V_6 * V_6 )
{
struct V_12 * V_3 = V_6 -> V_43 ;
struct V_13 * V_14 = F_10 ( V_3 ) ;
struct V_1 * V_2 ;
F_43 ( & V_14 -> V_15 ) ;
F_23 ( & V_3 -> V_51 ) ;
while ( ! F_44 ( & V_14 -> V_53 ) ) {
if ( ! F_37 ( & V_14 -> V_15 ) )
break;
V_2 = F_45 ( V_14 -> V_53 . V_55 , struct V_1 , V_52 ) ;
F_46 ( & V_2 -> V_52 ) ;
F_24 ( & V_3 -> V_51 ) ;
if ( F_21 ( V_6 , V_3 , V_2 ) == 0 )
F_1 ( V_2 ) ;
F_23 ( & V_3 -> V_51 ) ;
}
F_24 ( & V_3 -> V_51 ) ;
}
static int
F_47 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_56 = - V_11 ;
void * V_41 = NULL ;
V_2 = F_48 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
goto V_57;
V_2 -> V_4 = F_49 () ;
if ( F_33 ( V_2 -> V_4 ) ) {
V_56 = F_50 ( V_2 -> V_4 ) ;
goto V_50;
}
V_2 -> V_28 . V_48 = & V_2 -> V_48 ;
V_56 = - V_58 ;
F_23 ( & V_6 -> V_42 ) ;
if ( V_6 -> V_44 & V_45 )
goto V_59;
V_6 -> V_44 |= V_45 ;
V_41 = V_6 -> V_46 ;
V_6 -> V_46 = V_2 ;
F_24 ( & V_6 -> V_42 ) ;
if ( V_41 )
F_4 ( V_41 ) ;
return 0 ;
V_59:
F_24 ( & V_6 -> V_42 ) ;
F_3 ( V_2 -> V_4 ) ;
V_50:
F_4 ( V_2 ) ;
V_57:
return V_56 ;
}
void
F_51 ( struct V_6 * V_6 , struct V_12 * V_12 )
{
struct V_1 * V_2 = NULL ;
F_23 ( & V_6 -> V_42 ) ;
if ( V_6 -> V_44 & V_45 ) {
V_6 -> V_44 &= ~ V_45 ;
V_2 = V_6 -> V_46 ;
V_6 -> V_46 = NULL ;
}
F_24 ( & V_6 -> V_42 ) ;
if ( V_2 != NULL && ( F_52 ( V_12 ) || ! F_35 ( V_6 , V_2 ) ) )
F_1 ( V_2 ) ;
}
static void
F_53 ( struct V_6 * V_6 )
{
F_23 ( & V_6 -> V_42 ) ;
if ( V_6 -> V_44 & V_45 ) {
struct V_1 * V_2 = V_6 -> V_46 ;
V_6 -> V_44 &= ~ V_45 ;
V_6 -> V_46 = NULL ;
F_24 ( & V_6 -> V_42 ) ;
F_1 ( V_2 ) ;
return;
}
F_24 ( & V_6 -> V_42 ) ;
}
static void F_54 ( struct V_17 * V_18 , void * V_19 )
{
struct V_60 * V_2 = V_19 ;
struct V_12 * V_61 = V_2 -> V_61 ;
struct V_12 * V_62 = V_2 -> V_62 ;
struct V_6 * V_63 = V_2 -> V_63 ;
struct V_6 * V_64 = V_2 -> V_64 ;
if ( ! F_14 ( V_61 ) -> F_55 ( V_18 , V_61 , V_62 ) ) {
F_16 ( V_18 ) ;
return;
}
if ( V_18 -> V_65 != 0 ) {
F_53 ( V_63 ) ;
return;
}
F_56 ( V_63 ) ;
F_56 ( V_64 ) ;
}
static void F_57 ( void * V_19 )
{
struct V_60 * V_2 = V_19 ;
struct V_20 * V_21 = V_2 -> V_61 -> V_22 ;
if ( V_2 -> V_63 -> V_43 )
F_58 ( V_2 -> V_63 -> V_43 ) ;
F_25 ( V_2 -> V_63 ) ;
F_25 ( V_2 -> V_64 ) ;
F_2 ( V_2 -> V_61 ) ;
F_2 ( V_2 -> V_62 ) ;
F_59 ( V_21 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
}
static void F_60 ( struct V_17 * V_18 , void * V_19 )
{
struct V_60 * V_2 = V_19 ;
F_14 ( V_2 -> V_61 ) -> F_61 ( V_18 , V_2 ) ;
}
static struct V_17 *
F_62 ( struct V_12 * V_61 , struct V_12 * V_62 ,
struct V_6 * V_63 , struct V_6 * V_64 )
{
struct V_60 * V_2 ;
struct V_24 V_25 = { } ;
struct V_30 V_31 = {
. V_24 = & V_25 ,
. V_32 = & V_66 ,
. V_35 = V_36 ,
. V_49 = F_31 ( V_61 ) ,
. V_37 = V_38 ,
} ;
V_2 = F_48 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
return F_63 ( - V_11 ) ;
V_31 . V_34 = V_2 ;
V_2 -> V_4 = F_49 () ;
if ( F_33 ( V_2 -> V_4 ) ) {
struct V_17 * V_18 = F_64 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
return V_18 ;
}
V_25 . V_26 = & V_2 -> args ;
V_25 . V_27 = & V_2 -> V_28 ;
V_25 . V_29 = V_2 -> V_4 ;
V_2 -> V_61 = V_61 ;
F_65 ( V_61 ) ;
V_2 -> V_62 = V_62 ;
F_65 ( V_62 ) ;
V_2 -> V_63 = F_66 ( V_63 ) ;
V_2 -> V_64 = F_66 ( V_64 ) ;
F_29 ( & V_2 -> V_67 ) ;
F_29 ( & V_2 -> V_68 ) ;
V_2 -> args . V_61 = F_28 ( V_61 ) ;
V_2 -> args . V_69 = & V_63 -> V_9 ;
V_2 -> args . V_62 = F_28 ( V_62 ) ;
V_2 -> args . V_70 = & V_64 -> V_9 ;
V_2 -> V_28 . V_67 = & V_2 -> V_67 ;
V_2 -> V_28 . V_68 = & V_2 -> V_68 ;
F_27 ( V_61 -> V_22 ) ;
F_14 ( V_2 -> V_61 ) -> F_67 ( & V_25 , V_61 ) ;
return F_32 ( & V_31 ) ;
}
int
F_68 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
static unsigned int V_71 ;
const int V_72 = sizeof( F_69 ( V_6 -> V_43 ) ) * 2 ;
const int V_73 = sizeof( V_71 ) * 2 ;
const int V_74 = sizeof( L_1 ) + V_72 + V_73 - 1 ;
char V_75 [ V_74 + 1 ] ;
struct V_6 * V_76 ;
struct V_17 * V_18 ;
int error = - V_77 ;
F_70 ( V_78 , L_2 ,
V_6 -> V_79 -> V_9 . V_5 , V_6 -> V_9 . V_5 ,
V_6 -> V_80 ) ;
F_71 ( V_3 , V_81 ) ;
error = - V_58 ;
if ( V_6 -> V_44 & V_45 )
goto V_57;
sprintf ( V_75 , L_3 ,
V_72 , V_72 ,
( unsigned long long ) F_69 ( V_6 -> V_43 ) ) ;
F_14 ( V_6 -> V_43 ) -> F_72 ( V_6 -> V_43 ) ;
V_76 = NULL ;
do {
char * V_82 = V_75 + V_74 - V_73 ;
F_25 ( V_76 ) ;
V_71 ++ ;
sprintf ( V_82 , L_4 , V_73 , V_73 , V_71 ) ;
F_70 ( V_78 , L_5 ,
V_6 -> V_9 . V_5 , V_75 ) ;
V_76 = F_73 ( V_75 , V_6 -> V_79 , V_74 ) ;
if ( F_33 ( V_76 ) )
goto V_57;
} while ( V_76 -> V_43 != NULL );
error = F_47 ( V_3 , V_6 ) ;
if ( error )
goto V_54;
error = F_5 ( V_76 ,
(struct V_1 * ) V_6 -> V_46 ) ;
if ( error ) {
F_53 ( V_6 ) ;
goto V_54;
}
V_18 = F_62 ( V_3 , V_3 , V_6 , V_76 ) ;
if ( F_33 ( V_18 ) ) {
error = - V_58 ;
F_53 ( V_6 ) ;
goto V_54;
}
error = F_74 ( V_18 ) ;
if ( error == 0 )
error = V_18 -> V_65 ;
F_75 ( V_18 ) ;
V_54:
F_25 ( V_76 ) ;
V_57:
return error ;
}
