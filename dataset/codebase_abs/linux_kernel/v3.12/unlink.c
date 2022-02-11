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
F_14 ( V_2 , V_18 -> V_20 ) ;
if ( ! F_15 ( V_3 ) -> F_16 ( V_18 , V_3 ) )
F_17 ( V_18 ) ;
}
static void F_18 ( void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_21 * V_22 = V_2 -> V_3 -> V_23 ;
F_9 ( V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
F_19 ( V_22 ) ;
}
static void F_20 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
F_15 ( V_2 -> V_3 ) -> F_21 ( V_18 , V_2 ) ;
}
static int F_22 ( struct V_6 * V_24 , struct V_12 * V_3 , struct V_1 * V_2 )
{
struct V_25 V_26 = {
. V_27 = & V_2 -> args ,
. V_28 = & V_2 -> V_29 ,
. V_30 = V_2 -> V_4 ,
} ;
struct V_31 V_32 = {
. V_25 = & V_26 ,
. V_33 = & V_34 ,
. V_35 = V_2 ,
. V_36 = V_37 ,
. V_38 = V_39 ,
} ;
struct V_17 * V_18 ;
struct V_6 * V_40 ;
V_40 = F_23 ( V_24 , & V_2 -> args . V_5 ) ;
if ( V_40 != NULL ) {
int V_41 ;
void * V_42 = NULL ;
F_8 ( V_2 ) ;
V_41 = F_5 ( V_40 , V_2 ) ;
F_24 ( & V_40 -> V_43 ) ;
if ( V_41 == 0 && V_40 -> V_44 != NULL &&
! ( V_40 -> V_45 & V_46 ) ) {
V_42 = V_40 -> V_47 ;
V_40 -> V_47 = V_2 ;
V_40 -> V_45 |= V_46 ;
V_41 = 1 ;
} else
V_41 = 0 ;
F_25 ( & V_40 -> V_43 ) ;
F_9 ( V_3 ) ;
F_26 ( V_40 ) ;
F_4 ( V_42 ) ;
return V_41 ;
}
V_2 -> V_3 = F_27 ( V_3 ) ;
if ( ! V_2 -> V_3 ) {
F_9 ( V_3 ) ;
return 0 ;
}
F_28 ( V_3 -> V_23 ) ;
V_2 -> args . V_48 = F_29 ( V_3 ) ;
F_30 ( V_2 -> V_29 . V_49 ) ;
F_15 ( V_3 ) -> F_31 ( & V_26 , V_3 ) ;
V_32 . V_50 = F_32 ( V_3 ) ;
V_18 = F_33 ( & V_32 ) ;
if ( ! F_34 ( V_18 ) )
F_35 ( V_18 ) ;
return 1 ;
}
static int F_36 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
struct V_6 * V_24 ;
struct V_12 * V_3 ;
int V_41 = 0 ;
V_24 = F_37 ( V_6 ) ;
if ( V_24 == NULL )
goto V_51;
V_3 = V_24 -> V_44 ;
F_24 ( & V_3 -> V_52 ) ;
if ( F_38 ( & F_10 ( V_3 ) -> V_15 ) == 0 ) {
F_39 ( & V_2 -> V_53 , & F_10 ( V_3 ) -> V_54 ) ;
F_25 ( & V_3 -> V_52 ) ;
V_41 = 1 ;
goto V_55;
}
F_25 ( & V_3 -> V_52 ) ;
V_41 = F_22 ( V_24 , V_3 , V_2 ) ;
V_55:
F_26 ( V_24 ) ;
V_51:
return V_41 ;
}
void F_40 ( struct V_6 * V_6 )
{
struct V_13 * V_14 = F_10 ( V_6 -> V_44 ) ;
F_41 ( V_14 -> V_16 , F_42 ( & V_14 -> V_15 ) <= 1 ) ;
}
void F_43 ( struct V_6 * V_6 )
{
struct V_13 * V_14 = F_10 ( V_6 -> V_44 ) ;
F_41 ( V_14 -> V_16 , F_44 ( & V_14 -> V_15 , 1 , 0 ) == 1 ) ;
}
void F_45 ( struct V_6 * V_6 )
{
struct V_12 * V_3 = V_6 -> V_44 ;
struct V_13 * V_14 = F_10 ( V_3 ) ;
struct V_1 * V_2 ;
F_46 ( & V_14 -> V_15 ) ;
F_24 ( & V_3 -> V_52 ) ;
while ( ! F_47 ( & V_14 -> V_54 ) ) {
if ( ! F_38 ( & V_14 -> V_15 ) )
break;
V_2 = F_48 ( V_14 -> V_54 . V_56 , struct V_1 , V_53 ) ;
F_49 ( & V_2 -> V_53 ) ;
F_25 ( & V_3 -> V_52 ) ;
if ( F_22 ( V_6 , V_3 , V_2 ) == 0 )
F_1 ( V_2 ) ;
F_24 ( & V_3 -> V_52 ) ;
}
F_25 ( & V_3 -> V_52 ) ;
}
static int
F_50 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_57 = - V_11 ;
void * V_42 = NULL ;
V_2 = F_51 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
goto V_58;
V_2 -> V_4 = F_52 () ;
if ( F_34 ( V_2 -> V_4 ) ) {
V_57 = F_53 ( V_2 -> V_4 ) ;
goto V_51;
}
V_2 -> V_29 . V_49 = & V_2 -> V_49 ;
V_57 = - V_59 ;
F_24 ( & V_6 -> V_43 ) ;
if ( V_6 -> V_45 & V_46 )
goto V_60;
V_6 -> V_45 |= V_46 ;
V_42 = V_6 -> V_47 ;
V_6 -> V_47 = V_2 ;
F_25 ( & V_6 -> V_43 ) ;
F_4 ( V_42 ) ;
return 0 ;
V_60:
F_25 ( & V_6 -> V_43 ) ;
F_3 ( V_2 -> V_4 ) ;
V_51:
F_4 ( V_2 ) ;
V_58:
return V_57 ;
}
void
F_54 ( struct V_6 * V_6 , struct V_12 * V_12 )
{
struct V_1 * V_2 = NULL ;
F_24 ( & V_6 -> V_43 ) ;
if ( V_6 -> V_45 & V_46 ) {
V_6 -> V_45 &= ~ V_46 ;
V_2 = V_6 -> V_47 ;
V_6 -> V_47 = NULL ;
}
F_25 ( & V_6 -> V_43 ) ;
if ( V_2 != NULL && ( F_55 ( V_12 ) || ! F_36 ( V_6 , V_2 ) ) )
F_1 ( V_2 ) ;
}
static void
F_56 ( struct V_6 * V_6 )
{
F_24 ( & V_6 -> V_43 ) ;
if ( V_6 -> V_45 & V_46 ) {
struct V_1 * V_2 = V_6 -> V_47 ;
V_6 -> V_45 &= ~ V_46 ;
V_6 -> V_47 = NULL ;
F_25 ( & V_6 -> V_43 ) ;
F_1 ( V_2 ) ;
return;
}
F_25 ( & V_6 -> V_43 ) ;
}
static void F_57 ( struct V_17 * V_18 , void * V_19 )
{
struct V_61 * V_2 = V_19 ;
struct V_12 * V_62 = V_2 -> V_62 ;
struct V_12 * V_63 = V_2 -> V_63 ;
struct V_6 * V_64 = V_2 -> V_64 ;
F_58 ( V_62 , V_64 ,
V_63 , V_2 -> V_65 , V_18 -> V_20 ) ;
if ( ! F_15 ( V_62 ) -> F_59 ( V_18 , V_62 , V_63 ) ) {
F_17 ( V_18 ) ;
return;
}
if ( V_18 -> V_20 != 0 )
F_56 ( V_64 ) ;
}
static void F_60 ( void * V_19 )
{
struct V_61 * V_2 = V_19 ;
struct V_21 * V_22 = V_2 -> V_62 -> V_23 ;
if ( V_2 -> V_64 -> V_44 )
F_61 ( V_2 -> V_64 -> V_44 ) ;
F_26 ( V_2 -> V_64 ) ;
F_26 ( V_2 -> V_65 ) ;
F_2 ( V_2 -> V_62 ) ;
F_2 ( V_2 -> V_63 ) ;
F_19 ( V_22 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
}
static void F_62 ( struct V_17 * V_18 , void * V_19 )
{
struct V_61 * V_2 = V_19 ;
F_15 ( V_2 -> V_62 ) -> F_63 ( V_18 , V_2 ) ;
}
static struct V_17 *
F_64 ( struct V_12 * V_62 , struct V_12 * V_63 ,
struct V_6 * V_64 , struct V_6 * V_65 )
{
struct V_61 * V_2 ;
struct V_25 V_26 = { } ;
struct V_31 V_32 = {
. V_25 = & V_26 ,
. V_33 = & V_66 ,
. V_36 = V_37 ,
. V_50 = F_32 ( V_62 ) ,
. V_38 = V_39 ,
} ;
V_2 = F_51 ( sizeof( * V_2 ) , V_10 ) ;
if ( V_2 == NULL )
return F_65 ( - V_11 ) ;
V_32 . V_35 = V_2 ;
V_2 -> V_4 = F_52 () ;
if ( F_34 ( V_2 -> V_4 ) ) {
struct V_17 * V_18 = F_66 ( V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
return V_18 ;
}
V_26 . V_27 = & V_2 -> args ;
V_26 . V_28 = & V_2 -> V_29 ;
V_26 . V_30 = V_2 -> V_4 ;
V_2 -> V_62 = V_62 ;
F_67 ( V_62 ) ;
V_2 -> V_63 = V_63 ;
F_67 ( V_63 ) ;
V_2 -> V_64 = F_68 ( V_64 ) ;
V_2 -> V_65 = F_68 ( V_65 ) ;
F_30 ( & V_2 -> V_67 ) ;
F_30 ( & V_2 -> V_68 ) ;
V_2 -> args . V_62 = F_29 ( V_62 ) ;
V_2 -> args . V_69 = & V_64 -> V_9 ;
V_2 -> args . V_63 = F_29 ( V_63 ) ;
V_2 -> args . V_70 = & V_65 -> V_9 ;
V_2 -> V_29 . V_67 = & V_2 -> V_67 ;
V_2 -> V_29 . V_68 = & V_2 -> V_68 ;
F_28 ( V_62 -> V_23 ) ;
F_15 ( V_2 -> V_62 ) -> F_69 ( & V_26 , V_62 ) ;
return F_33 ( & V_32 ) ;
}
int
F_70 ( struct V_12 * V_3 , struct V_6 * V_6 )
{
static unsigned int V_71 ;
unsigned char V_72 [ V_73 + 1 ] ;
unsigned long long V_74 ;
struct V_6 * V_75 ;
struct V_17 * V_18 ;
int error = - V_76 ;
F_71 ( V_77 , L_1 ,
V_6 -> V_78 -> V_9 . V_5 , V_6 -> V_9 . V_5 ,
F_72 ( V_6 ) ) ;
F_73 ( V_3 , V_79 ) ;
error = - V_59 ;
if ( V_6 -> V_45 & V_46 )
goto V_58;
V_74 = F_74 ( V_6 -> V_44 ) ;
F_15 ( V_6 -> V_44 ) -> F_75 ( V_6 -> V_44 ) ;
V_75 = NULL ;
do {
int V_80 ;
F_26 ( V_75 ) ;
V_71 ++ ;
V_80 = F_76 ( V_72 , sizeof( V_72 ) ,
V_81 L_2 ,
V_82 , V_74 ,
V_83 , V_71 ) ;
F_71 ( V_77 , L_3 ,
V_6 -> V_9 . V_5 , V_72 ) ;
V_75 = F_77 ( V_72 , V_6 -> V_78 , V_80 ) ;
if ( F_34 ( V_75 ) )
goto V_58;
} while ( V_75 -> V_44 != NULL );
error = F_50 ( V_3 , V_6 ) ;
if ( error )
goto V_55;
error = F_5 ( V_75 ,
(struct V_1 * ) V_6 -> V_47 ) ;
if ( error ) {
F_56 ( V_6 ) ;
goto V_55;
}
V_18 = F_64 ( V_3 , V_3 , V_6 , V_75 ) ;
if ( F_34 ( V_18 ) ) {
error = - V_59 ;
F_56 ( V_6 ) ;
goto V_55;
}
error = F_78 ( V_18 ) ;
if ( error == 0 )
error = V_18 -> V_20 ;
switch ( error ) {
case 0 :
F_79 ( V_6 , F_80 ( V_3 ) ) ;
F_81 ( V_6 , V_75 ) ;
break;
case - V_84 :
F_82 ( V_6 ) ;
F_82 ( V_75 ) ;
}
F_83 ( V_18 ) ;
V_55:
F_26 ( V_75 ) ;
V_58:
return error ;
}
