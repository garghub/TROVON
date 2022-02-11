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
void F_19 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_23 * V_24 = F_20 ( V_2 -> V_3 ) ;
if ( F_21 ( V_24 , & V_2 -> args . V_25 ,
& V_2 -> V_26 . V_27 , 1 , V_18 ) )
return;
F_22 ( V_18 ) ;
}
static int F_23 ( struct V_6 * V_28 , struct V_12 * V_3 , struct V_1 * V_2 )
{
struct V_29 V_30 = {
. V_31 = & V_2 -> args ,
. V_32 = & V_2 -> V_26 ,
. V_33 = V_2 -> V_4 ,
} ;
struct V_34 V_35 = {
. V_29 = & V_30 ,
. V_36 = & V_37 ,
. V_38 = V_2 ,
. V_39 = V_40 ,
. V_41 = V_42 ,
} ;
struct V_17 * V_18 ;
struct V_6 * V_43 ;
V_43 = F_24 ( V_28 , & V_2 -> args . V_5 ) ;
if ( V_43 != NULL ) {
int V_44 ;
void * V_45 = NULL ;
F_8 ( V_2 ) ;
V_44 = F_5 ( V_43 , V_2 ) ;
F_25 ( & V_43 -> V_46 ) ;
if ( V_44 == 0 && V_43 -> V_47 != NULL &&
! ( V_43 -> V_48 & V_49 ) ) {
V_45 = V_43 -> V_50 ;
V_43 -> V_50 = V_2 ;
V_43 -> V_48 |= V_49 ;
V_44 = 1 ;
} else
V_44 = 0 ;
F_26 ( & V_43 -> V_46 ) ;
F_9 ( V_3 ) ;
F_27 ( V_43 ) ;
F_4 ( V_45 ) ;
return V_44 ;
}
V_2 -> V_3 = F_28 ( V_3 ) ;
if ( ! V_2 -> V_3 ) {
F_9 ( V_3 ) ;
return 0 ;
}
F_29 ( V_3 -> V_22 ) ;
V_2 -> args . V_51 = F_30 ( V_3 ) ;
F_31 ( V_2 -> V_26 . V_52 ) ;
F_14 ( V_3 ) -> F_32 ( & V_30 , V_3 ) ;
V_35 . V_53 = F_33 ( V_3 ) ;
V_18 = F_34 ( & V_35 ) ;
if ( ! F_35 ( V_18 ) )
F_36 ( V_18 ) ;
return 1 ;
}
static int F_37 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
struct V_6 * V_28 ;
struct V_12 * V_3 ;
int V_44 = 0 ;
V_28 = F_38 ( V_6 ) ;
if ( V_28 == NULL )
goto V_54;
V_3 = V_28 -> V_47 ;
F_25 ( & V_3 -> V_55 ) ;
if ( F_39 ( & F_10 ( V_3 ) -> V_15 ) == 0 ) {
F_40 ( & V_2 -> V_56 , & F_10 ( V_3 ) -> V_57 ) ;
F_26 ( & V_3 -> V_55 ) ;
V_44 = 1 ;
goto V_58;
}
F_26 ( & V_3 -> V_55 ) ;
V_44 = F_23 ( V_28 , V_3 , V_2 ) ;
V_58:
F_27 ( V_28 ) ;
V_54:
return V_44 ;
}
void F_41 ( struct V_6 * V_6 )
{
struct V_13 * V_14 = F_10 ( V_6 -> V_47 ) ;
F_42 ( V_14 -> V_16 , F_43 ( & V_14 -> V_15 , 1 , 0 ) == 1 ) ;
}
void F_44 ( struct V_6 * V_6 )
{
struct V_12 * V_3 = V_6 -> V_47 ;
struct V_13 * V_14 = F_10 ( V_3 ) ;
struct V_1 * V_2 ;
F_45 ( & V_14 -> V_15 ) ;
F_25 ( & V_3 -> V_55 ) ;
while ( ! F_46 ( & V_14 -> V_57 ) ) {
if ( ! F_39 ( & V_14 -> V_15 ) )
break;
V_2 = F_47 ( V_14 -> V_57 . V_59 , struct V_1 , V_56 ) ;
F_48 ( & V_2 -> V_56 ) ;
F_26 ( & V_3 -> V_55 ) ;
if ( F_23 ( V_6 , V_3 , V_2 ) == 0 )
F_1 ( V_2 ) ;
F_25 ( & V_3 -> V_55 ) ;
}
F_26 ( & V_3 -> V_55 ) ;
}
static int
F_49 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_60 = - V_11 ;
void * V_45 = NULL ;
V_2 = F_50 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
goto V_61;
V_2 -> V_4 = F_51 () ;
if ( F_35 ( V_2 -> V_4 ) ) {
V_60 = F_52 ( V_2 -> V_4 ) ;
goto V_54;
}
V_2 -> V_26 . V_52 = & V_2 -> V_52 ;
V_60 = - V_62 ;
F_25 ( & V_6 -> V_46 ) ;
if ( V_6 -> V_48 & V_49 )
goto V_63;
V_6 -> V_48 |= V_49 ;
V_45 = V_6 -> V_50 ;
V_6 -> V_50 = V_2 ;
F_26 ( & V_6 -> V_46 ) ;
if ( V_45 )
F_4 ( V_45 ) ;
return 0 ;
V_63:
F_26 ( & V_6 -> V_46 ) ;
F_3 ( V_2 -> V_4 ) ;
V_54:
F_4 ( V_2 ) ;
V_61:
return V_60 ;
}
void
F_53 ( struct V_6 * V_6 , struct V_12 * V_12 )
{
struct V_1 * V_2 = NULL ;
F_25 ( & V_6 -> V_46 ) ;
if ( V_6 -> V_48 & V_49 ) {
V_6 -> V_48 &= ~ V_49 ;
V_2 = V_6 -> V_50 ;
V_6 -> V_50 = NULL ;
}
F_26 ( & V_6 -> V_46 ) ;
if ( V_2 != NULL && ( F_54 ( V_12 ) || ! F_37 ( V_6 , V_2 ) ) )
F_1 ( V_2 ) ;
}
static void
F_55 ( struct V_6 * V_6 )
{
F_25 ( & V_6 -> V_46 ) ;
if ( V_6 -> V_48 & V_49 ) {
struct V_1 * V_2 = V_6 -> V_50 ;
V_6 -> V_48 &= ~ V_49 ;
V_6 -> V_50 = NULL ;
F_26 ( & V_6 -> V_46 ) ;
F_1 ( V_2 ) ;
return;
}
F_26 ( & V_6 -> V_46 ) ;
}
static void F_56 ( struct V_17 * V_18 , void * V_19 )
{
struct V_64 * V_2 = V_19 ;
struct V_12 * V_65 = V_2 -> V_65 ;
struct V_12 * V_66 = V_2 -> V_66 ;
struct V_6 * V_67 = V_2 -> V_67 ;
struct V_6 * V_68 = V_2 -> V_68 ;
if ( ! F_14 ( V_65 ) -> F_57 ( V_18 , V_65 , V_66 ) ) {
F_16 ( V_18 ) ;
return;
}
if ( V_18 -> V_69 != 0 ) {
F_55 ( V_67 ) ;
return;
}
F_58 ( V_67 ) ;
F_58 ( V_68 ) ;
}
static void F_59 ( void * V_19 )
{
struct V_64 * V_2 = V_19 ;
struct V_20 * V_21 = V_2 -> V_65 -> V_22 ;
if ( V_2 -> V_67 -> V_47 )
F_60 ( V_2 -> V_67 -> V_47 ) ;
F_27 ( V_2 -> V_67 ) ;
F_27 ( V_2 -> V_68 ) ;
F_2 ( V_2 -> V_65 ) ;
F_2 ( V_2 -> V_66 ) ;
F_18 ( V_21 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
}
static void F_61 ( struct V_17 * V_18 , void * V_19 )
{
struct V_64 * V_2 = V_19 ;
struct V_23 * V_24 = F_20 ( V_2 -> V_65 ) ;
if ( F_21 ( V_24 , & V_2 -> args . V_25 ,
& V_2 -> V_26 . V_27 , 1 , V_18 ) )
return;
F_22 ( V_18 ) ;
}
static struct V_17 *
F_62 ( struct V_12 * V_65 , struct V_12 * V_66 ,
struct V_6 * V_67 , struct V_6 * V_68 )
{
struct V_64 * V_2 ;
struct V_29 V_30 = { } ;
struct V_34 V_35 = {
. V_29 = & V_30 ,
. V_36 = & V_70 ,
. V_39 = V_40 ,
. V_53 = F_33 ( V_65 ) ,
. V_41 = V_42 ,
} ;
V_2 = F_50 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
return F_63 ( - V_11 ) ;
V_35 . V_38 = V_2 ;
V_2 -> V_4 = F_51 () ;
if ( F_35 ( V_2 -> V_4 ) ) {
struct V_17 * V_18 = F_64 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
return V_18 ;
}
V_30 . V_31 = & V_2 -> args ;
V_30 . V_32 = & V_2 -> V_26 ;
V_30 . V_33 = V_2 -> V_4 ;
V_2 -> V_65 = V_65 ;
F_65 ( V_65 ) ;
V_2 -> V_66 = V_66 ;
F_65 ( V_66 ) ;
V_2 -> V_67 = F_66 ( V_67 ) ;
V_2 -> V_68 = F_66 ( V_68 ) ;
F_31 ( & V_2 -> V_71 ) ;
F_31 ( & V_2 -> V_72 ) ;
V_2 -> args . V_65 = F_30 ( V_65 ) ;
V_2 -> args . V_73 = & V_67 -> V_9 ;
V_2 -> args . V_66 = F_30 ( V_66 ) ;
V_2 -> args . V_74 = & V_68 -> V_9 ;
V_2 -> V_26 . V_71 = & V_2 -> V_71 ;
V_2 -> V_26 . V_72 = & V_2 -> V_72 ;
F_29 ( V_65 -> V_22 ) ;
F_14 ( V_2 -> V_65 ) -> F_67 ( & V_30 , V_65 ) ;
return F_34 ( & V_35 ) ;
}
int
F_68 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
static unsigned int V_75 ;
const int V_76 = sizeof( F_69 ( V_6 -> V_47 ) ) * 2 ;
const int V_77 = sizeof( V_75 ) * 2 ;
const int V_78 = sizeof( L_1 ) + V_76 + V_77 - 1 ;
char V_79 [ V_78 + 1 ] ;
struct V_6 * V_80 ;
struct V_17 * V_18 ;
int error = - V_81 ;
F_70 ( V_82 , L_2 ,
V_6 -> V_83 -> V_9 . V_5 , V_6 -> V_9 . V_5 ,
V_6 -> V_84 ) ;
F_71 ( V_3 , V_85 ) ;
error = - V_62 ;
if ( V_6 -> V_48 & V_49 )
goto V_61;
sprintf ( V_79 , L_3 ,
V_76 , V_76 ,
( unsigned long long ) F_69 ( V_6 -> V_47 ) ) ;
F_72 ( V_6 -> V_47 ) ;
V_80 = NULL ;
do {
char * V_86 = V_79 + V_78 - V_77 ;
F_27 ( V_80 ) ;
V_75 ++ ;
sprintf ( V_86 , L_4 , V_77 , V_77 , V_75 ) ;
F_70 ( V_82 , L_5 ,
V_6 -> V_9 . V_5 , V_79 ) ;
V_80 = F_73 ( V_79 , V_6 -> V_83 , V_78 ) ;
if ( F_35 ( V_80 ) )
goto V_61;
} while ( V_80 -> V_47 != NULL );
error = F_49 ( V_3 , V_6 ) ;
if ( error )
goto V_58;
error = F_5 ( V_80 ,
(struct V_1 * ) V_6 -> V_50 ) ;
if ( error ) {
F_55 ( V_6 ) ;
goto V_58;
}
V_18 = F_62 ( V_3 , V_3 , V_6 , V_80 ) ;
if ( F_35 ( V_18 ) ) {
error = - V_62 ;
F_55 ( V_6 ) ;
goto V_58;
}
error = F_74 ( V_18 ) ;
if ( error == 0 )
error = V_18 -> V_69 ;
F_75 ( V_18 ) ;
V_58:
F_27 ( V_80 ) ;
V_61:
return error ;
}
