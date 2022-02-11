static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
F_3 ( & V_2 -> V_3 . V_4 ) ;
F_4 ( & V_2 -> V_3 ) ;
F_5 ( V_2 ) -> V_5 = false ;
F_6 ( & V_2 -> V_3 . V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_6 )
{
F_2 ( L_2 , V_2 , V_6 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = - V_6 ;
V_2 -> V_10 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_8 ( struct V_11 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_2 ( L_3 , V_1 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_1 , struct V_12 * V_13 ,
int V_14 , int V_15 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = (struct V_16 * ) V_13 ;
struct V_18 * V_19 ;
int V_20 = 0 ;
F_2 ( L_4 , V_1 , V_2 , V_15 ) ;
if ( ! V_17 || V_14 < sizeof( struct V_16 ) ||
V_17 -> V_21 != V_22 )
return - V_23 ;
F_2 ( L_5 ,
V_17 -> V_24 , V_17 -> V_25 , V_17 -> V_26 ) ;
F_12 ( V_2 ) ;
if ( V_1 -> V_27 == V_28 ) {
V_20 = - V_29 ;
goto error;
}
V_19 = F_13 ( V_17 -> V_24 ) ;
if ( ! V_19 ) {
V_20 = - V_30 ;
goto error;
}
V_20 = F_14 ( V_19 , V_17 -> V_25 , V_17 -> V_26 ) ;
if ( V_20 )
goto V_31;
F_5 ( V_2 ) -> V_19 = V_19 ;
F_5 ( V_2 ) -> V_25 = V_17 -> V_25 ;
V_1 -> V_27 = V_28 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_34 ( V_2 ) ;
F_15 ( V_2 ) ;
return 0 ;
V_31:
F_16 ( V_19 ) ;
error:
F_15 ( V_2 ) ;
return V_20 ;
}
static int F_17 ( struct V_35 * V_36 )
{
* F_18 ( V_36 , V_37 ) = 0 ;
return 0 ;
}
static void F_19 ( void * V_38 , struct V_35 * V_36 ,
int V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
F_20 ( F_21 () ) ;
F_2 ( L_2 , V_2 , V_6 ) ;
if ( V_6 )
goto error;
V_6 = F_17 ( V_36 ) ;
if ( V_6 )
goto error;
V_6 = F_22 ( V_2 , V_36 ) ;
if ( V_6 )
goto error;
F_3 ( & V_2 -> V_3 . V_4 ) ;
if ( ! F_23 ( & V_2 -> V_3 ) )
F_24 ( & F_5 ( V_2 ) -> V_39 ) ;
else
F_5 ( V_2 ) -> V_5 = false ;
F_6 ( & V_2 -> V_3 . V_4 ) ;
F_10 ( V_2 ) ;
return;
error:
F_7 ( V_2 , V_6 ) ;
F_10 ( V_2 ) ;
}
static void F_25 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_26 ( V_41 ) ;
struct V_18 * V_19 = F_5 ( V_2 ) -> V_19 ;
T_1 V_25 = F_5 ( V_2 ) -> V_25 ;
struct V_35 * V_36 ;
int V_20 ;
F_2 ( L_6 , V_2 , V_25 ) ;
if ( V_2 -> V_7 & V_42 ) {
F_1 ( V_2 ) ;
return;
}
V_36 = F_27 ( & V_2 -> V_3 ) ;
F_28 ( V_2 ) ;
V_20 = F_29 ( V_19 , V_25 , V_36 ,
F_19 , V_2 ) ;
if ( V_20 ) {
F_7 ( V_2 , V_20 ) ;
F_10 ( V_2 ) ;
}
}
static int F_30 ( struct V_43 * V_44 , struct V_11 * V_1 ,
struct V_45 * V_46 , T_2 V_14 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_18 * V_19 = F_5 ( V_2 ) -> V_19 ;
struct V_35 * V_36 ;
int V_20 ;
F_2 ( L_7 , V_1 , V_2 , V_14 ) ;
if ( V_46 -> V_47 )
return - V_48 ;
if ( V_1 -> V_27 != V_28 )
return - V_49 ;
V_36 = F_31 ( V_19 , V_2 , V_46 -> V_50 , V_14 , & V_20 ) ;
if ( V_36 == NULL )
return V_20 ;
V_20 = F_32 ( F_33 ( V_36 , V_14 ) , V_46 -> V_51 , V_14 ) ;
if ( V_20 < 0 ) {
F_34 ( V_36 ) ;
return V_20 ;
}
F_3 ( & V_2 -> V_3 . V_4 ) ;
F_35 ( & V_2 -> V_3 , V_36 ) ;
if ( ! F_5 ( V_2 ) -> V_5 ) {
F_24 ( & F_5 ( V_2 ) -> V_39 ) ;
F_5 ( V_2 ) -> V_5 = true ;
}
F_6 ( & V_2 -> V_3 . V_4 ) ;
return V_14 ;
}
static int F_36 ( struct V_43 * V_44 , struct V_11 * V_1 ,
struct V_45 * V_46 , T_2 V_14 , int V_15 )
{
int V_52 = V_15 & V_53 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_35 * V_36 ;
int V_54 ;
int V_20 ;
F_2 ( L_8 , V_1 , V_2 , V_14 , V_15 ) ;
V_36 = F_37 ( V_2 , V_15 , V_52 , & V_20 ) ;
if ( ! V_36 )
return V_20 ;
V_46 -> V_47 = 0 ;
V_54 = V_36 -> V_14 ;
if ( V_14 < V_54 ) {
V_46 -> V_50 |= V_55 ;
V_54 = V_14 ;
}
V_20 = F_38 ( V_36 , 0 , V_46 -> V_51 , V_54 ) ;
F_39 ( V_2 , V_36 ) ;
return V_20 ? : V_54 ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
if ( V_2 -> V_32 == V_33 ) {
F_41 ( F_5 ( V_2 ) -> V_19 ,
F_5 ( V_2 ) -> V_25 ) ;
F_16 ( F_5 ( V_2 ) -> V_19 ) ;
}
F_42 ( & V_2 -> V_56 ) ;
if ( ! F_43 ( V_2 , V_57 ) ) {
F_44 ( L_9 , V_2 ) ;
return;
}
}
static int F_45 ( struct V_58 * V_58 , struct V_11 * V_1 ,
const struct V_26 * V_59 )
{
struct V_1 * V_2 ;
F_2 ( L_3 , V_1 ) ;
if ( V_1 -> type != V_60 )
return - V_61 ;
V_1 -> V_62 = & V_63 ;
V_2 = F_46 ( V_58 , V_64 , V_65 , V_59 -> V_66 ) ;
if ( ! V_2 )
return - V_67 ;
F_47 ( V_1 , V_2 ) ;
V_2 -> V_68 = V_59 -> V_69 ;
V_2 -> V_70 = F_40 ;
V_1 -> V_27 = V_71 ;
F_48 ( & F_5 ( V_2 ) -> V_39 , F_25 ) ;
F_5 ( V_2 ) -> V_5 = false ;
return 0 ;
}
int T_3 F_49 ( void )
{
int V_20 ;
V_20 = F_50 ( & V_72 ) ;
return V_20 ;
}
void F_51 ( void )
{
F_52 ( & V_72 ) ;
}
