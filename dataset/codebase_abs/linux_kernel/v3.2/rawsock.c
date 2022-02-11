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
F_2 ( L_5 , V_17 -> V_24 ,
V_17 -> V_25 , V_17 -> V_26 ) ;
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
if ( V_17 -> V_25 > V_19 -> V_25 - 1 ||
V_17 -> V_25 < V_19 -> V_25 - V_19 -> V_31 ) {
V_20 = - V_23 ;
goto error;
}
if ( V_17 -> V_25 > V_19 -> V_25 - 1 ||
V_17 -> V_25 < V_19 -> V_25 - V_19 -> V_31 ) {
V_20 = - V_23 ;
goto error;
}
V_20 = F_14 ( V_19 , V_17 -> V_25 , V_17 -> V_26 ) ;
if ( V_20 )
goto V_32;
F_5 ( V_2 ) -> V_19 = V_19 ;
F_5 ( V_2 ) -> V_25 = V_17 -> V_25 ;
V_1 -> V_27 = V_28 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 ( V_2 ) ;
F_15 ( V_2 ) ;
return 0 ;
V_32:
F_16 ( V_19 ) ;
error:
F_15 ( V_2 ) ;
return V_20 ;
}
static int F_17 ( struct V_36 * V_37 )
{
* F_18 ( V_37 , V_38 ) = 0 ;
return 0 ;
}
static void F_19 ( void * V_39 , struct V_36 * V_37 ,
int V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_39 ;
F_20 ( F_21 () ) ;
F_2 ( L_2 , V_2 , V_6 ) ;
if ( V_6 )
goto error;
V_6 = F_17 ( V_37 ) ;
if ( V_6 )
goto error;
V_6 = F_22 ( V_2 , V_37 ) ;
if ( V_6 )
goto error;
F_3 ( & V_2 -> V_3 . V_4 ) ;
if ( ! F_23 ( & V_2 -> V_3 ) )
F_24 ( & F_5 ( V_2 ) -> V_40 ) ;
else
F_5 ( V_2 ) -> V_5 = false ;
F_6 ( & V_2 -> V_3 . V_4 ) ;
F_10 ( V_2 ) ;
return;
error:
F_7 ( V_2 , V_6 ) ;
F_10 ( V_2 ) ;
}
static void F_25 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_18 * V_19 = F_5 ( V_2 ) -> V_19 ;
T_1 V_25 = F_5 ( V_2 ) -> V_25 ;
struct V_36 * V_37 ;
int V_20 ;
F_2 ( L_6 , V_2 , V_25 ) ;
if ( V_2 -> V_7 & V_43 ) {
F_1 ( V_2 ) ;
return;
}
V_37 = F_27 ( & V_2 -> V_3 ) ;
F_28 ( V_2 ) ;
V_20 = F_29 ( V_19 , V_25 , V_37 ,
F_19 , V_2 ) ;
if ( V_20 ) {
F_7 ( V_2 , V_20 ) ;
F_10 ( V_2 ) ;
}
}
static int F_30 ( struct V_44 * V_45 , struct V_11 * V_1 ,
struct V_46 * V_47 , T_2 V_14 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_18 * V_19 = F_5 ( V_2 ) -> V_19 ;
struct V_36 * V_37 ;
int V_20 ;
F_2 ( L_7 , V_1 , V_2 , V_14 ) ;
if ( V_47 -> V_48 )
return - V_49 ;
if ( V_1 -> V_27 != V_28 )
return - V_50 ;
V_37 = F_31 ( V_2 , V_14 + V_19 -> V_51 + V_19 -> V_52 + V_38 ,
V_47 -> V_53 & V_54 , & V_20 ) ;
if ( ! V_37 )
return V_20 ;
F_32 ( V_37 , V_19 -> V_51 + V_38 ) ;
V_20 = F_33 ( F_34 ( V_37 , V_14 ) , V_47 -> V_55 , V_14 ) ;
if ( V_20 < 0 ) {
F_35 ( V_37 ) ;
return V_20 ;
}
F_3 ( & V_2 -> V_3 . V_4 ) ;
F_36 ( & V_2 -> V_3 , V_37 ) ;
if ( ! F_5 ( V_2 ) -> V_5 ) {
F_24 ( & F_5 ( V_2 ) -> V_40 ) ;
F_5 ( V_2 ) -> V_5 = true ;
}
F_6 ( & V_2 -> V_3 . V_4 ) ;
return V_14 ;
}
static int F_37 ( struct V_44 * V_45 , struct V_11 * V_1 ,
struct V_46 * V_47 , T_2 V_14 , int V_15 )
{
int V_56 = V_15 & V_54 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_36 * V_37 ;
int V_57 ;
int V_20 ;
F_2 ( L_8 , V_1 , V_2 , V_14 , V_15 ) ;
V_37 = F_38 ( V_2 , V_15 , V_56 , & V_20 ) ;
if ( ! V_37 )
return V_20 ;
V_47 -> V_48 = 0 ;
V_57 = V_37 -> V_14 ;
if ( V_14 < V_57 ) {
V_47 -> V_53 |= V_58 ;
V_57 = V_14 ;
}
V_20 = F_39 ( V_37 , 0 , V_47 -> V_55 , V_57 ) ;
F_40 ( V_2 , V_37 ) ;
return V_20 ? : V_57 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
if ( V_2 -> V_33 == V_34 ) {
F_42 ( F_5 ( V_2 ) -> V_19 ,
F_5 ( V_2 ) -> V_25 ) ;
F_16 ( F_5 ( V_2 ) -> V_19 ) ;
}
F_43 ( & V_2 -> V_59 ) ;
if ( ! F_44 ( V_2 , V_60 ) ) {
F_45 ( L_9 , V_2 ) ;
return;
}
}
static int F_46 ( struct V_61 * V_61 , struct V_11 * V_1 ,
const struct V_26 * V_62 )
{
struct V_1 * V_2 ;
F_2 ( L_3 , V_1 ) ;
if ( V_1 -> type != V_63 )
return - V_64 ;
V_1 -> V_65 = & V_66 ;
V_2 = F_47 ( V_61 , V_67 , V_68 , V_62 -> V_69 ) ;
if ( ! V_2 )
return - V_70 ;
F_48 ( V_1 , V_2 ) ;
V_2 -> V_71 = V_62 -> V_72 ;
V_2 -> V_73 = F_41 ;
V_1 -> V_27 = V_74 ;
F_49 ( & F_5 ( V_2 ) -> V_40 , F_25 ) ;
F_5 ( V_2 ) -> V_5 = false ;
return 0 ;
}
int T_3 F_50 ( void )
{
int V_20 ;
V_20 = F_51 ( & V_75 ) ;
return V_20 ;
}
void F_52 ( void )
{
F_53 ( & V_75 ) ;
}
