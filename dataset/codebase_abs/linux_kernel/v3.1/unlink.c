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
F_16 ( V_18 , F_17 ( V_3 ) -> V_20 ) ;
}
static void F_18 ( void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_21 * V_22 = V_2 -> V_3 -> V_23 ;
F_9 ( V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
F_19 ( V_22 ) ;
}
void F_20 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_24 * V_25 = F_17 ( V_2 -> V_3 ) ;
if ( F_21 ( V_25 , & V_2 -> args . V_26 ,
& V_2 -> V_27 . V_28 , 1 , V_18 ) )
return;
F_22 ( V_18 ) ;
}
static int F_23 ( struct V_6 * V_29 , struct V_12 * V_3 , struct V_1 * V_2 )
{
struct V_30 V_31 = {
. V_32 = & V_2 -> args ,
. V_33 = & V_2 -> V_27 ,
. V_34 = V_2 -> V_4 ,
} ;
struct V_35 V_36 = {
. V_30 = & V_31 ,
. V_37 = & V_38 ,
. V_39 = V_2 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
} ;
struct V_17 * V_18 ;
struct V_6 * V_44 ;
V_44 = F_24 ( V_29 , & V_2 -> args . V_5 ) ;
if ( V_44 != NULL ) {
int V_45 ;
void * V_46 = NULL ;
F_8 ( V_2 ) ;
V_45 = F_5 ( V_44 , V_2 ) ;
F_25 ( & V_44 -> V_47 ) ;
if ( V_45 == 0 && V_44 -> V_48 != NULL &&
! ( V_44 -> V_49 & V_50 ) ) {
V_46 = V_44 -> V_51 ;
V_44 -> V_51 = V_2 ;
V_44 -> V_49 |= V_50 ;
V_45 = 1 ;
} else
V_45 = 0 ;
F_26 ( & V_44 -> V_47 ) ;
F_9 ( V_3 ) ;
F_27 ( V_44 ) ;
F_4 ( V_46 ) ;
return V_45 ;
}
V_2 -> V_3 = F_28 ( V_3 ) ;
if ( ! V_2 -> V_3 ) {
F_9 ( V_3 ) ;
return 0 ;
}
F_29 ( V_3 -> V_23 ) ;
V_2 -> args . V_52 = F_30 ( V_3 ) ;
F_31 ( V_2 -> V_27 . V_53 ) ;
F_14 ( V_3 ) -> F_32 ( & V_31 , V_3 ) ;
V_36 . V_54 = F_33 ( V_3 ) ;
V_18 = F_34 ( & V_36 ) ;
if ( ! F_35 ( V_18 ) )
F_36 ( V_18 ) ;
return 1 ;
}
static int F_37 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
struct V_6 * V_29 ;
struct V_12 * V_3 ;
int V_45 = 0 ;
V_29 = F_38 ( V_6 ) ;
if ( V_29 == NULL )
goto V_55;
V_3 = V_29 -> V_48 ;
F_25 ( & V_3 -> V_56 ) ;
if ( F_39 ( & F_10 ( V_3 ) -> V_15 ) == 0 ) {
F_40 ( & V_2 -> V_57 , & F_10 ( V_3 ) -> V_58 ) ;
F_26 ( & V_3 -> V_56 ) ;
V_45 = 1 ;
goto V_59;
}
F_26 ( & V_3 -> V_56 ) ;
V_45 = F_23 ( V_29 , V_3 , V_2 ) ;
V_59:
F_27 ( V_29 ) ;
V_55:
return V_45 ;
}
void F_41 ( struct V_6 * V_6 )
{
struct V_13 * V_14 = F_10 ( V_6 -> V_48 ) ;
F_42 ( V_14 -> V_16 , F_43 ( & V_14 -> V_15 , 1 , 0 ) == 1 ) ;
}
void F_44 ( struct V_6 * V_6 )
{
struct V_12 * V_3 = V_6 -> V_48 ;
struct V_13 * V_14 = F_10 ( V_3 ) ;
struct V_1 * V_2 ;
F_45 ( & V_14 -> V_15 ) ;
F_25 ( & V_3 -> V_56 ) ;
while ( ! F_46 ( & V_14 -> V_58 ) ) {
if ( ! F_39 ( & V_14 -> V_15 ) )
break;
V_2 = F_47 ( V_14 -> V_58 . V_60 , struct V_1 , V_57 ) ;
F_48 ( & V_2 -> V_57 ) ;
F_26 ( & V_3 -> V_56 ) ;
if ( F_23 ( V_6 , V_3 , V_2 ) == 0 )
F_1 ( V_2 ) ;
F_25 ( & V_3 -> V_56 ) ;
}
F_26 ( & V_3 -> V_56 ) ;
}
static int
F_49 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_61 = - V_11 ;
void * V_46 = NULL ;
V_2 = F_50 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
goto V_62;
V_2 -> V_4 = F_51 () ;
if ( F_35 ( V_2 -> V_4 ) ) {
V_61 = F_52 ( V_2 -> V_4 ) ;
goto V_55;
}
V_2 -> V_27 . V_53 = & V_2 -> V_53 ;
V_61 = - V_63 ;
F_25 ( & V_6 -> V_47 ) ;
if ( V_6 -> V_49 & V_50 )
goto V_64;
V_6 -> V_49 |= V_50 ;
V_46 = V_6 -> V_51 ;
V_6 -> V_51 = V_2 ;
F_26 ( & V_6 -> V_47 ) ;
if ( V_46 )
F_4 ( V_46 ) ;
return 0 ;
V_64:
F_26 ( & V_6 -> V_47 ) ;
F_3 ( V_2 -> V_4 ) ;
V_55:
F_4 ( V_2 ) ;
V_62:
return V_61 ;
}
void
F_53 ( struct V_6 * V_6 , struct V_12 * V_12 )
{
struct V_1 * V_2 = NULL ;
F_25 ( & V_6 -> V_47 ) ;
if ( V_6 -> V_49 & V_50 ) {
V_6 -> V_49 &= ~ V_50 ;
V_2 = V_6 -> V_51 ;
V_6 -> V_51 = NULL ;
}
F_26 ( & V_6 -> V_47 ) ;
if ( V_2 != NULL && ( F_54 ( V_12 ) || ! F_37 ( V_6 , V_2 ) ) )
F_1 ( V_2 ) ;
}
static void
F_55 ( struct V_6 * V_6 )
{
F_25 ( & V_6 -> V_47 ) ;
if ( V_6 -> V_49 & V_50 ) {
struct V_1 * V_2 = V_6 -> V_51 ;
V_6 -> V_49 &= ~ V_50 ;
V_6 -> V_51 = NULL ;
F_26 ( & V_6 -> V_47 ) ;
F_1 ( V_2 ) ;
return;
}
F_26 ( & V_6 -> V_47 ) ;
}
static void F_56 ( struct V_17 * V_18 , void * V_19 )
{
struct V_65 * V_2 = V_19 ;
struct V_12 * V_66 = V_2 -> V_66 ;
struct V_12 * V_67 = V_2 -> V_67 ;
struct V_6 * V_68 = V_2 -> V_68 ;
struct V_6 * V_69 = V_2 -> V_69 ;
if ( ! F_14 ( V_66 ) -> F_57 ( V_18 , V_66 , V_67 ) ) {
F_16 ( V_18 , F_17 ( V_66 ) -> V_20 ) ;
return;
}
if ( V_18 -> V_70 != 0 ) {
F_55 ( V_68 ) ;
return;
}
F_58 ( V_68 ) ;
F_58 ( V_69 ) ;
}
static void F_59 ( void * V_19 )
{
struct V_65 * V_2 = V_19 ;
struct V_21 * V_22 = V_2 -> V_66 -> V_23 ;
if ( V_2 -> V_68 -> V_48 )
F_60 ( V_2 -> V_68 -> V_48 ) ;
F_27 ( V_2 -> V_68 ) ;
F_27 ( V_2 -> V_69 ) ;
F_2 ( V_2 -> V_66 ) ;
F_2 ( V_2 -> V_67 ) ;
F_19 ( V_22 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
}
static void F_61 ( struct V_17 * V_18 , void * V_19 )
{
struct V_65 * V_2 = V_19 ;
struct V_24 * V_25 = F_17 ( V_2 -> V_66 ) ;
if ( F_21 ( V_25 , & V_2 -> args . V_26 ,
& V_2 -> V_27 . V_28 , 1 , V_18 ) )
return;
F_22 ( V_18 ) ;
}
static struct V_17 *
F_62 ( struct V_12 * V_66 , struct V_12 * V_67 ,
struct V_6 * V_68 , struct V_6 * V_69 )
{
struct V_65 * V_2 ;
struct V_30 V_31 = { } ;
struct V_35 V_36 = {
. V_30 = & V_31 ,
. V_37 = & V_71 ,
. V_40 = V_41 ,
. V_54 = F_33 ( V_66 ) ,
. V_42 = V_43 ,
} ;
V_2 = F_50 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
return F_63 ( - V_11 ) ;
V_36 . V_39 = V_2 ;
V_2 -> V_4 = F_51 () ;
if ( F_35 ( V_2 -> V_4 ) ) {
struct V_17 * V_18 = F_64 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
return V_18 ;
}
V_31 . V_32 = & V_2 -> args ;
V_31 . V_33 = & V_2 -> V_27 ;
V_31 . V_34 = V_2 -> V_4 ;
V_2 -> V_66 = V_66 ;
F_65 ( V_66 ) ;
V_2 -> V_67 = V_67 ;
F_65 ( V_67 ) ;
V_2 -> V_68 = F_66 ( V_68 ) ;
V_2 -> V_69 = F_66 ( V_69 ) ;
F_31 ( & V_2 -> V_72 ) ;
F_31 ( & V_2 -> V_73 ) ;
V_2 -> args . V_66 = F_30 ( V_66 ) ;
V_2 -> args . V_74 = & V_68 -> V_9 ;
V_2 -> args . V_67 = F_30 ( V_67 ) ;
V_2 -> args . V_75 = & V_69 -> V_9 ;
V_2 -> V_27 . V_72 = & V_2 -> V_72 ;
V_2 -> V_27 . V_73 = & V_2 -> V_73 ;
F_29 ( V_66 -> V_23 ) ;
F_14 ( V_2 -> V_66 ) -> F_67 ( & V_31 , V_66 ) ;
return F_34 ( & V_36 ) ;
}
int
F_68 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
static unsigned int V_76 ;
const int V_77 = sizeof( F_69 ( V_6 -> V_48 ) ) * 2 ;
const int V_78 = sizeof( V_76 ) * 2 ;
const int V_79 = sizeof( L_1 ) + V_77 + V_78 - 1 ;
char V_80 [ V_79 + 1 ] ;
struct V_6 * V_81 ;
struct V_17 * V_18 ;
int error = - V_82 ;
F_70 ( V_83 , L_2 ,
V_6 -> V_84 -> V_9 . V_5 , V_6 -> V_9 . V_5 ,
V_6 -> V_85 ) ;
F_71 ( V_3 , V_86 ) ;
error = - V_63 ;
if ( V_6 -> V_49 & V_50 )
goto V_62;
sprintf ( V_80 , L_3 ,
V_77 , V_77 ,
( unsigned long long ) F_69 ( V_6 -> V_48 ) ) ;
F_72 ( V_6 -> V_48 ) ;
V_81 = NULL ;
do {
char * V_87 = V_80 + V_79 - V_78 ;
F_27 ( V_81 ) ;
V_76 ++ ;
sprintf ( V_87 , L_4 , V_78 , V_78 , V_76 ) ;
F_70 ( V_83 , L_5 ,
V_6 -> V_9 . V_5 , V_80 ) ;
V_81 = F_73 ( V_80 , V_6 -> V_84 , V_79 ) ;
if ( F_35 ( V_81 ) )
goto V_62;
} while ( V_81 -> V_48 != NULL );
error = F_49 ( V_3 , V_6 ) ;
if ( error )
goto V_59;
error = F_5 ( V_81 ,
(struct V_1 * ) V_6 -> V_51 ) ;
if ( error ) {
F_55 ( V_6 ) ;
goto V_59;
}
V_18 = F_62 ( V_3 , V_3 , V_6 , V_81 ) ;
if ( F_35 ( V_18 ) ) {
error = - V_63 ;
F_55 ( V_6 ) ;
goto V_59;
}
error = F_74 ( V_18 ) ;
if ( error == 0 )
error = V_18 -> V_70 ;
F_75 ( V_18 ) ;
V_59:
F_27 ( V_81 ) ;
V_62:
return error ;
}
