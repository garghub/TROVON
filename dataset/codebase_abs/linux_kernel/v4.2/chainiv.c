static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
unsigned int V_9 ;
int V_10 ;
F_5 ( V_8 , F_6 ( V_4 ) ) ;
F_7 ( V_8 , V_2 -> V_11 . V_12 . V_13 &
~ V_14 ,
V_2 -> V_11 . V_12 . V_15 ,
V_2 -> V_11 . V_12 . V_16 ) ;
F_8 ( V_8 , V_2 -> V_11 . V_17 , V_2 -> V_11 . V_18 ,
V_2 -> V_11 . V_19 , V_2 -> V_11 . V_20 ) ;
F_9 ( & V_6 -> V_21 ) ;
V_9 = F_10 ( V_4 ) ;
memcpy ( V_2 -> V_22 , V_6 -> V_23 , V_9 ) ;
memcpy ( V_8 -> V_20 , V_6 -> V_23 , V_9 ) ;
V_10 = F_11 ( V_8 ) ;
if ( V_10 )
goto V_24;
memcpy ( V_6 -> V_23 , V_8 -> V_20 , V_9 ) ;
V_24:
F_12 ( & V_6 -> V_21 ) ;
return V_10 ;
}
static int F_13 ( struct V_25 * V_26 , char V_23 [] )
{
struct V_3 * V_4 = F_14 ( V_26 ) ;
int V_10 = 0 ;
V_26 -> V_27 . V_28 = sizeof( struct V_7 ) ;
if ( V_23 ) {
V_10 = F_15 ( V_29 , V_23 ,
F_10 ( V_4 ) ) ;
F_16 () ;
}
return V_10 ? : F_17 ( V_26 ) ;
}
static int F_18 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_14 ( V_26 ) ;
struct V_5 * V_6 = F_19 ( V_26 ) ;
char * V_23 ;
F_20 ( & V_6 -> V_21 ) ;
V_23 = NULL ;
if ( ! F_21 () ) {
F_22 ( V_4 ) -> V_30 = F_1 ;
V_23 = V_6 -> V_23 ;
}
return F_13 ( V_26 , V_23 ) ;
}
static int F_23 ( struct V_31 * V_6 )
{
int V_32 ;
int V_10 = V_6 -> V_10 ;
if ( ! V_6 -> V_33 . V_34 ) {
F_24 () ;
F_25 ( V_35 , & V_6 -> V_36 ) ;
if ( ! V_6 -> V_33 . V_34 ||
F_26 ( V_35 , & V_6 -> V_36 ) )
goto V_37;
}
V_32 = F_27 ( V_38 , & V_6 -> V_39 ) ;
F_28 ( ! V_32 ) ;
V_37:
return V_10 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
int V_10 ;
F_9 ( & V_6 -> V_21 ) ;
V_10 = F_30 ( & V_6 -> V_33 , V_2 ) ;
F_12 ( & V_6 -> V_21 ) ;
if ( F_26 ( V_35 , & V_6 -> V_36 ) )
return V_10 ;
V_6 -> V_10 = V_10 ;
return F_23 ( V_6 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
unsigned int V_9 = F_10 ( V_4 ) ;
memcpy ( V_2 -> V_22 , V_6 -> V_23 , V_9 ) ;
memcpy ( V_8 -> V_20 , V_6 -> V_23 , V_9 ) ;
V_6 -> V_10 = F_11 ( V_8 ) ;
if ( V_6 -> V_10 )
goto V_37;
memcpy ( V_6 -> V_23 , V_8 -> V_20 , V_9 ) ;
V_37:
return F_23 ( V_6 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
F_5 ( V_8 , F_6 ( V_4 ) ) ;
F_7 ( V_8 , V_2 -> V_11 . V_12 . V_13 ,
V_2 -> V_11 . V_12 . V_15 ,
V_2 -> V_11 . V_12 . V_16 ) ;
F_8 ( V_8 , V_2 -> V_11 . V_17 , V_2 -> V_11 . V_18 ,
V_2 -> V_11 . V_19 , V_2 -> V_11 . V_20 ) ;
if ( F_26 ( V_35 , & V_6 -> V_36 ) )
goto V_40;
if ( V_6 -> V_33 . V_34 ) {
F_25 ( V_35 , & V_6 -> V_36 ) ;
goto V_40;
}
return F_31 ( V_2 ) ;
V_40:
return F_29 ( V_2 ) ;
}
static void F_33 ( struct V_41 * V_42 )
{
struct V_31 * V_6 = F_34 ( V_42 ,
struct V_31 ,
V_39 ) ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_10 ;
F_9 ( & V_6 -> V_21 ) ;
V_2 = F_35 ( & V_6 -> V_33 ) ;
F_12 ( & V_6 -> V_21 ) ;
if ( ! V_2 ) {
F_23 ( V_6 ) ;
return;
}
V_8 = F_4 ( V_2 ) ;
V_8 -> V_12 . V_13 |= V_14 ;
V_10 = F_31 ( V_2 ) ;
F_36 () ;
F_37 ( V_2 , V_10 ) ;
F_38 () ;
}
static int F_39 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_14 ( V_26 ) ;
struct V_31 * V_6 = F_19 ( V_26 ) ;
char * V_23 ;
F_20 ( & V_6 -> V_21 ) ;
F_40 ( & V_6 -> V_33 , 100 ) ;
F_41 ( & V_6 -> V_39 , F_33 ) ;
V_23 = NULL ;
if ( ! F_21 () ) {
F_22 ( V_4 ) -> V_30 =
F_32 ;
V_23 = V_6 -> V_23 ;
}
return F_13 ( V_26 , V_23 ) ;
}
static void F_42 ( struct V_25 * V_26 )
{
struct V_31 * V_6 = F_19 ( V_26 ) ;
F_28 ( F_43 ( V_35 , & V_6 -> V_36 ) || V_6 -> V_33 . V_34 ) ;
F_44 ( V_26 ) ;
}
static struct V_43 * F_45 ( struct V_44 * * V_45 )
{
struct V_46 * V_47 ;
struct V_43 * V_48 ;
V_47 = F_46 ( V_45 ) ;
if ( F_47 ( V_47 ) )
return F_48 ( V_47 ) ;
V_48 = F_49 ( & V_49 , V_45 , 0 , 0 ) ;
if ( F_47 ( V_48 ) )
goto V_37;
V_48 -> V_50 . V_51 = F_18 ;
V_48 -> V_50 . V_52 = F_44 ;
V_48 -> V_50 . V_53 = sizeof( struct V_5 ) ;
if ( ! F_50 ( V_47 -> type , V_47 -> V_54 ) ) {
V_48 -> V_50 . V_55 |= V_56 ;
V_48 -> V_50 . V_51 = F_39 ;
V_48 -> V_50 . V_52 = F_42 ;
V_48 -> V_50 . V_53 = sizeof( struct V_31 ) ;
}
V_48 -> V_50 . V_53 += V_48 -> V_50 . V_57 . V_9 ;
V_37:
return V_48 ;
}
static int T_1 F_51 ( void )
{
return F_52 ( & V_49 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_49 ) ;
}
