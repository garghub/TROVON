struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
return V_4 -> V_6 ;
}
static struct V_7 * F_3 ( struct V_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
return & V_4 -> V_8 ;
}
static void F_4 ( struct V_9 * V_10 )
{
F_5 ( * V_10 -> V_11 ) ;
}
static void F_6 ( struct V_9 * V_10 )
{
F_7 ( * V_10 -> V_11 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_12 , V_13 = 0 ;
F_9 (i)
V_13 += * F_10 ( V_10 -> V_11 , V_12 ) ;
return V_13 ;
}
static struct V_9 * F_11 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
struct V_9 * V_16 ;
V_8 = F_3 ( F_12 ( V_15 ) ) ;
V_16 = F_13 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_11 = F_14 ( int ) ;
if ( ! V_16 -> V_11 ) {
F_15 ( V_16 ) ;
return NULL ;
}
V_16 -> V_18 = V_15 ;
F_16 ( V_15 ) ;
return V_16 ;
}
static struct V_9 * F_17 ( struct V_14 * V_15 )
{
struct V_7 * V_8 =
F_3 ( F_12 ( V_15 ) ) ;
struct V_9 * V_16 ;
F_18 (caifd, &caifdevs->list, list) {
if ( V_16 -> V_18 == V_15 )
return V_16 ;
}
return NULL ;
}
void F_19 ( struct V_19 * V_20 )
{
struct V_9 * V_16 ;
void (* F_20)( struct V_19 * V_20 ) = NULL ;
bool V_21 ;
F_21 ( V_20 -> V_15 == NULL ) ;
F_22 () ;
V_16 = F_17 ( V_20 -> V_15 ) ;
F_6 ( V_16 ) ;
F_23 () ;
F_24 ( & V_16 -> V_22 ) ;
V_21 = V_16 -> V_23 ;
V_16 -> V_23 = 0 ;
F_20 = V_16 -> V_24 ;
if ( F_21 ( V_16 -> V_25 != V_20 ) )
V_20 = NULL ;
V_16 -> V_25 = NULL ;
V_16 -> V_24 = NULL ;
F_25 ( & V_16 -> V_22 ) ;
if ( F_20 && V_20 )
F_20 ( V_20 ) ;
if ( V_21 )
V_16 -> V_26 . V_27 ->
V_28 ( V_16 -> V_26 . V_27 ,
V_29 ,
V_16 -> V_26 . V_30 ) ;
F_4 ( V_16 ) ;
}
static int F_26 ( struct V_31 * V_26 , struct V_32 * V_33 )
{
int V_34 , V_35 = 0 , V_36 = 0 ;
struct V_37 * V_38 ;
struct V_9 * V_16 =
F_27 ( V_26 , struct V_9 , V_26 ) ;
struct V_19 * V_20 ;
struct V_39 * V_40 ;
F_28 () ;
V_20 = F_29 ( V_33 ) ;
V_20 -> V_15 = V_16 -> V_18 ;
F_30 ( V_20 ) ;
V_20 -> V_41 = F_31 ( V_42 ) ;
V_38 = F_32 ( V_16 -> V_18 ) ;
if ( F_33 ( V_16 -> V_18 -> V_43 == 0 ) )
goto V_44;
if ( F_34 ( V_16 -> V_23 ) )
goto V_44;
if ( F_33 ( ! F_35 ( V_16 -> V_18 ) ) ) {
V_40 = F_36 ( V_20 -> V_15 , 0 ) ;
V_36 = F_37 ( F_38 ( V_40 -> V_45 ) ) ;
if ( F_33 ( V_36 == 0 ) )
goto V_44;
V_35 = ( V_16 -> V_18 -> V_43 * V_46 ) / 100 ;
if ( F_33 ( V_36 < V_35 ) )
goto V_44;
}
F_24 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_23 ) {
F_25 ( & V_16 -> V_22 ) ;
goto V_44;
}
F_39 ( L_1 ,
F_35 ( V_16 -> V_18 ) ,
V_36 , V_35 ) ;
V_16 -> V_23 = 1 ;
V_16 -> V_25 = V_20 ;
V_16 -> V_24 = V_20 -> V_47 ;
V_20 -> V_47 = F_19 ;
F_25 ( & V_16 -> V_22 ) ;
V_16 -> V_26 . V_27 -> V_28 ( V_16 -> V_26 . V_27 ,
V_48 ,
V_16 -> V_26 . V_30 ) ;
V_44:
F_40 () ;
V_34 = F_41 ( V_20 ) ;
if ( V_34 > 0 )
V_34 = - V_49 ;
return V_34 ;
}
static int F_42 ( struct V_19 * V_20 , struct V_14 * V_15 ,
struct V_50 * V_51 , struct V_14 * V_52 )
{
struct V_32 * V_33 ;
struct V_9 * V_16 ;
int V_34 ;
V_33 = F_43 ( V_53 , V_20 ) ;
F_22 () ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 || ! V_16 -> V_26 . V_27 || ! V_16 -> V_26 . V_27 -> F_42 ||
! F_44 ( V_16 -> V_18 ) ) {
F_23 () ;
F_45 ( V_20 ) ;
return V_54 ;
}
F_6 ( V_16 ) ;
F_23 () ;
V_34 = V_16 -> V_26 . V_27 -> F_42 ( V_16 -> V_26 . V_27 , V_33 ) ;
if ( V_34 == - V_55 )
F_46 ( V_33 ) ;
F_4 ( V_16 ) ;
if ( V_34 != 0 )
V_34 = V_54 ;
return V_34 ;
}
static void F_47 ( struct V_14 * V_15 , int V_56 )
{
struct V_9 * V_16 ;
F_22 () ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 || ! V_16 -> V_26 . V_27 || ! V_16 -> V_26 . V_27 -> V_28 ) {
F_23 () ;
return;
}
F_6 ( V_16 ) ;
F_23 () ;
V_16 -> V_26 . V_27 -> V_28 ( V_16 -> V_26 . V_27 ,
V_56 ?
V_29 :
V_48 ,
V_16 -> V_26 . V_30 ) ;
F_4 ( V_16 ) ;
}
void F_48 ( struct V_14 * V_15 , struct V_37 * V_38 ,
struct V_31 * V_57 , int V_58 ,
struct V_31 * * V_26 , int (* * F_49)(
struct V_19 * , struct V_14 * ,
struct V_50 * , struct V_14 * ) )
{
struct V_9 * V_16 ;
enum V_59 V_60 ;
struct V_1 * V_6 = F_1 ( F_12 ( V_15 ) ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( F_12 ( V_15 ) ) ;
V_16 = F_11 ( V_15 ) ;
if ( ! V_16 )
return;
* V_26 = & V_16 -> V_26 ;
F_50 ( & V_16 -> V_22 ) ;
switch ( V_38 -> V_61 ) {
case V_62 :
V_60 = V_63 ;
break;
case V_64 :
V_60 = V_65 ;
break;
default:
V_60 = V_63 ;
break;
}
F_51 ( & V_8 -> V_66 ) ;
F_52 ( & V_16 -> V_67 , & V_8 -> V_67 ) ;
strncpy ( V_16 -> V_26 . V_68 , V_15 -> V_68 ,
sizeof( V_16 -> V_26 . V_68 ) - 1 ) ;
V_16 -> V_26 . V_68 [ sizeof( V_16 -> V_26 . V_68 ) - 1 ] = 0 ;
V_16 -> V_26 . F_26 = F_26 ;
F_53 ( V_6 ,
V_15 ,
& V_16 -> V_26 ,
V_60 ,
V_57 ,
V_38 -> V_69 ,
V_58 ) ;
F_54 ( & V_8 -> V_66 ) ;
if ( F_49 )
* F_49 = F_42 ;
}
static int F_55 ( struct V_70 * V_71 , unsigned long V_72 ,
void * V_73 )
{
struct V_14 * V_15 = V_73 ;
struct V_9 * V_16 = NULL ;
struct V_37 * V_38 ;
struct V_1 * V_6 ;
struct V_31 * V_26 , * V_57 ;
int V_58 = 0 ;
struct V_7 * V_8 ;
V_6 = F_1 ( F_12 ( V_15 ) ) ;
V_8 = F_3 ( F_12 ( V_15 ) ) ;
V_16 = F_17 ( V_15 ) ;
if ( V_16 == NULL && V_15 -> type != V_74 )
return 0 ;
switch ( V_72 ) {
case V_75 :
if ( V_16 != NULL )
break;
V_38 = F_32 ( V_15 ) ;
V_57 = NULL ;
if ( V_38 -> V_76 ) {
V_58 = 1 ;
V_57 = F_56 ( V_15 -> V_77 ,
V_38 -> V_78 ) ;
if ( ! V_57 ) {
F_57 ( L_2 ) ;
break;
}
}
F_48 ( V_15 , V_38 , V_57 , V_58 ,
& V_26 , NULL ) ;
V_38 -> V_79 = F_47 ;
break;
case V_80 :
F_22 () ;
V_16 = F_17 ( V_15 ) ;
if ( V_16 == NULL ) {
F_23 () ;
break;
}
V_16 -> V_23 = 0 ;
F_58 ( V_6 , & V_16 -> V_26 , true ) ;
F_23 () ;
break;
case V_81 :
F_22 () ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 || ! V_16 -> V_26 . V_27 || ! V_16 -> V_26 . V_27 -> V_28 ) {
F_23 () ;
return - V_82 ;
}
F_58 ( V_6 , & V_16 -> V_26 , false ) ;
F_6 ( V_16 ) ;
F_23 () ;
V_16 -> V_26 . V_27 -> V_28 ( V_16 -> V_26 . V_27 ,
V_83 ,
V_16 -> V_26 . V_30 ) ;
F_24 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_24 != NULL && V_16 -> V_25 != NULL )
V_16 -> V_25 -> V_47 = V_16 -> V_24 ;
V_16 -> V_23 = 0 ;
V_16 -> V_24 = NULL ;
V_16 -> V_25 = NULL ;
F_25 ( & V_16 -> V_22 ) ;
F_4 ( V_16 ) ;
break;
case V_84 :
F_51 ( & V_8 -> V_66 ) ;
V_16 = F_17 ( V_15 ) ;
if ( V_16 == NULL ) {
F_54 ( & V_8 -> V_66 ) ;
break;
}
F_59 ( & V_16 -> V_67 ) ;
if ( F_8 ( V_16 ) != 0 ||
F_60 ( V_6 , & V_16 -> V_26 ) != 0 ) {
F_61 ( L_3 ) ;
F_52 ( & V_16 -> V_67 , & V_8 -> V_67 ) ;
F_54 ( & V_8 -> V_66 ) ;
break;
}
F_62 () ;
F_63 ( V_16 -> V_18 ) ;
F_64 ( V_16 -> V_11 ) ;
F_15 ( V_16 ) ;
F_54 ( & V_8 -> V_66 ) ;
break;
}
return 0 ;
}
static int F_65 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , V_5 ) ;
F_66 ( & V_4 -> V_8 . V_67 ) ;
F_67 ( & V_4 -> V_8 . V_66 ) ;
V_4 -> V_6 = F_68 () ;
if ( ! V_4 -> V_6 )
return - V_85 ;
return 0 ;
}
static void F_69 ( struct V_2 * V_2 )
{
struct V_9 * V_16 , * V_86 ;
struct V_7 * V_8 =
F_3 ( V_2 ) ;
struct V_1 * V_6 = F_1 ( V_2 ) ;
F_70 () ;
F_51 ( & V_8 -> V_66 ) ;
F_71 (caifd, tmp, &caifdevs->list, list) {
int V_12 = 0 ;
F_59 ( & V_16 -> V_67 ) ;
F_58 ( V_6 , & V_16 -> V_26 , false ) ;
while ( V_12 < 10 &&
( F_8 ( V_16 ) != 0 ||
F_60 ( V_6 , & V_16 -> V_26 ) != 0 ) ) {
F_61 ( L_3 ) ;
F_72 ( 250 ) ;
V_12 ++ ;
}
F_62 () ;
F_63 ( V_16 -> V_18 ) ;
F_64 ( V_16 -> V_11 ) ;
F_15 ( V_16 ) ;
}
F_73 ( V_6 ) ;
F_54 ( & V_8 -> V_66 ) ;
F_74 () ;
}
static int T_1 F_75 ( void )
{
int V_87 ;
V_87 = F_76 ( & V_88 ) ;
if ( V_87 )
return V_87 ;
F_77 ( & V_89 ) ;
F_78 ( & V_90 ) ;
return V_87 ;
}
static void T_2 F_79 ( void )
{
F_80 ( & V_88 ) ;
F_81 ( & V_89 ) ;
F_82 ( & V_90 ) ;
}
