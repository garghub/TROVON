static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
strncpy ( V_6 . type , L_1 , sizeof( V_6 . type ) ) ;
if ( F_2 ( V_2 , V_7 ,
sizeof( struct V_5 ) , & V_6 ) )
goto V_8;
return 0 ;
V_8:
return - V_9 ;
}
static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return - V_10 ;
}
static void F_3 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
F_4 ( V_12 , L_2 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
return 0 ;
}
static void F_6 ( void * T_1 * V_15 )
{
int V_16 ;
if ( ! V_15 )
return;
F_7 (i)
F_8 ( * F_9 ( V_15 , V_16 ) ) ;
F_10 ( V_15 ) ;
}
static void * T_1 * F_11 ( void )
{
void * T_1 * V_15 ;
int V_16 ;
V_15 = F_12 ( void * ) ;
if ( ! V_15 )
return NULL ;
F_7 (i) {
void * V_17 ;
V_17 = F_13 ( V_18 , F_14 ( V_16 ) ) ;
if ( ! V_17 )
goto error;
* F_9 ( V_15 , V_16 ) = V_17 ;
}
return V_15 ;
error:
F_6 ( V_15 ) ;
return NULL ;
}
static void F_15 ( void )
{
if ( ! -- V_19 ) {
F_6 ( V_20 ) ;
F_6 ( V_21 ) ;
V_20 = NULL ;
V_21 = NULL ;
}
}
static int F_16 ( void )
{
if ( ! V_19 ++ ) {
V_20 = F_11 () ;
if ( ! V_20 )
return - V_22 ;
V_21 = F_11 () ;
if ( ! V_21 )
return - V_22 ;
}
return 0 ;
}
static void F_17 ( struct V_23 * V_24 )
{
int V_16 , V_25 ;
struct V_26 * V_26 ;
if ( ! V_24 )
return;
V_25 = F_18 ( V_24 ) ;
F_19 (sgl, sgl, n, i) {
V_26 = F_20 ( V_24 ) ;
if ( V_26 )
F_21 ( V_26 ) ;
}
F_22 ( V_24 ) ;
}
static struct V_23 * F_23 ( T_2 V_27 , T_3 V_28 )
{
struct V_23 * V_24 ;
struct V_26 * V_26 ;
int V_16 , V_25 ;
V_25 = ( ( V_27 - 1 ) >> V_29 ) + 1 ;
V_24 = F_24 ( V_25 , sizeof( struct V_23 ) , V_28 ) ;
if ( ! V_24 )
return NULL ;
F_25 ( V_24 , V_25 ) ;
for ( V_16 = 0 ; V_16 < V_25 ; V_16 ++ ) {
V_26 = F_26 ( V_28 ) ;
if ( ! V_26 )
goto V_30;
F_27 ( V_24 + V_16 , V_26 , V_31 , 0 ) ;
}
return V_24 ;
V_30:
F_28 ( V_24 + V_16 ) ;
F_17 ( V_24 ) ;
return NULL ;
}
static int F_29 ( struct V_32 * V_33 , int V_34 )
{
struct V_35 * V_14 = F_30 ( V_33 ) ;
void * * V_36 = F_31 ( V_14 ) ;
struct V_37 * V_38 = * V_36 ;
void * * V_39 = F_32 ( V_33 ) ;
const int V_40 = F_33 () ;
T_4 * V_41 = * F_9 ( V_20 , V_40 ) ;
T_4 * V_42 = * F_9 ( V_21 , V_40 ) ;
int V_43 ;
if ( ! V_33 -> V_44 || ! V_33 -> V_45 || V_33 -> V_45 > V_18 ) {
V_43 = - V_46 ;
goto V_47;
}
if ( V_33 -> V_48 && ! V_33 -> V_49 ) {
V_43 = - V_46 ;
goto V_47;
}
if ( ! V_33 -> V_49 || V_33 -> V_49 > V_18 )
V_33 -> V_49 = V_18 ;
F_34 ( V_41 , V_33 -> V_44 , 0 , V_33 -> V_45 , 0 ) ;
if ( V_34 )
V_43 = F_35 ( V_38 , V_41 , V_33 -> V_45 ,
V_42 , & V_33 -> V_49 , * V_39 ) ;
else
V_43 = F_36 ( V_38 , V_41 , V_33 -> V_45 ,
V_42 , & V_33 -> V_49 , * V_39 ) ;
if ( ! V_43 ) {
if ( ! V_33 -> V_48 ) {
V_33 -> V_48 = F_23 ( V_33 -> V_49 ,
V_33 -> V_50 . V_51 & V_52 ?
V_53 : V_54 ) ;
if ( ! V_33 -> V_48 )
goto V_47;
}
F_34 ( V_42 , V_33 -> V_48 , 0 , V_33 -> V_49 ,
1 ) ;
}
V_47:
F_37 () ;
return V_43 ;
}
static int F_38 ( struct V_32 * V_33 )
{
return F_29 ( V_33 , 1 ) ;
}
static int F_39 ( struct V_32 * V_33 )
{
return F_29 ( V_33 , 0 ) ;
}
static void F_40 ( struct V_13 * V_14 )
{
struct V_37 * * V_39 = F_41 ( V_14 ) ;
F_42 ( * V_39 ) ;
}
int F_43 ( struct V_13 * V_14 )
{
struct V_3 * V_55 = V_14 -> V_56 ;
struct V_35 * V_57 = F_44 ( V_14 ) ;
struct V_37 * * V_39 = F_41 ( V_14 ) ;
struct V_37 * V_38 ;
if ( ! F_45 ( V_55 ) )
return - V_58 ;
V_38 = F_46 ( V_55 , & V_59 ) ;
if ( F_47 ( V_38 ) ) {
F_48 ( V_55 ) ;
return F_49 ( V_38 ) ;
}
* V_39 = V_38 ;
V_14 -> exit = F_40 ;
V_57 -> V_60 = F_38 ;
V_57 -> V_61 = F_39 ;
V_57 -> V_62 = F_17 ;
V_57 -> V_63 = sizeof( void * ) ;
return 0 ;
}
struct V_32 * F_50 ( struct V_32 * V_33 )
{
struct V_35 * V_64 = F_30 ( V_33 ) ;
struct V_13 * V_14 = F_51 ( V_64 ) ;
struct V_37 * * V_36 = F_41 ( V_14 ) ;
struct V_37 * V_38 = * V_36 ;
void * V_39 ;
V_39 = F_52 ( V_38 ) ;
if ( F_47 ( V_39 ) ) {
F_22 ( V_33 ) ;
return NULL ;
}
* V_33 -> V_65 = V_39 ;
return V_33 ;
}
void F_53 ( struct V_32 * V_33 )
{
struct V_35 * V_64 = F_30 ( V_33 ) ;
struct V_13 * V_14 = F_51 ( V_64 ) ;
struct V_37 * * V_36 = F_41 ( V_14 ) ;
struct V_37 * V_38 = * V_36 ;
void * V_39 = * V_33 -> V_65 ;
if ( V_39 )
F_54 ( V_38 , V_39 ) ;
}
int F_55 ( struct V_66 * V_4 )
{
struct V_3 * V_50 = & V_4 -> V_50 ;
int V_43 = - V_22 ;
F_56 ( & V_67 ) ;
if ( F_16 () )
goto error;
V_50 -> V_68 = & V_59 ;
V_50 -> V_69 &= ~ V_70 ;
V_50 -> V_69 |= V_71 ;
V_43 = F_57 ( V_50 ) ;
if ( V_43 )
goto error;
F_58 ( & V_67 ) ;
return V_43 ;
error:
F_15 () ;
F_58 ( & V_67 ) ;
return V_43 ;
}
int F_59 ( struct V_66 * V_4 )
{
int V_43 ;
F_56 ( & V_67 ) ;
V_43 = F_60 ( & V_4 -> V_50 ) ;
F_15 () ;
F_58 ( & V_67 ) ;
return V_43 ;
}
