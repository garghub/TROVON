static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_4 , & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_6 ( V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
F_8 ( L_1 , V_4 ) ;
F_9 ( & V_4 -> V_7 . V_5 ) ;
F_10 ( & V_4 -> V_7 ) ;
F_11 ( V_4 ) -> V_8 = false ;
F_12 ( & V_4 -> V_7 . V_5 ) ;
}
static void F_13 ( struct V_3 * V_4 , int V_9 )
{
F_8 ( L_2 , V_4 , V_9 ) ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = - V_9 ;
V_4 -> V_13 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static int F_14 ( struct V_14 * V_3 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
F_8 ( L_3 , V_3 , V_4 ) ;
if ( ! V_4 )
return 0 ;
if ( V_3 -> type == V_15 )
F_5 ( & V_16 , V_4 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_3 , struct V_17 * V_18 ,
int V_19 , int V_20 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
struct V_21 * V_22 = (struct V_21 * ) V_18 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
F_8 ( L_4 , V_3 , V_4 , V_20 ) ;
if ( ! V_22 || V_19 < sizeof( struct V_21 ) ||
V_22 -> V_26 != V_27 )
return - V_28 ;
F_8 ( L_5 ,
V_22 -> V_29 , V_22 -> V_30 , V_22 -> V_31 ) ;
F_18 ( V_4 ) ;
if ( V_3 -> V_32 == V_33 ) {
V_25 = - V_34 ;
goto error;
}
V_24 = F_19 ( V_22 -> V_29 ) ;
if ( ! V_24 ) {
V_25 = - V_35 ;
goto error;
}
if ( V_22 -> V_30 > V_24 -> V_36 - 1 ||
V_22 -> V_30 < V_24 -> V_36 - V_24 -> V_37 ) {
V_25 = - V_28 ;
goto error;
}
V_25 = F_20 ( V_24 , V_22 -> V_30 , V_22 -> V_31 ) ;
if ( V_25 )
goto V_38;
F_11 ( V_4 ) -> V_24 = V_24 ;
F_11 ( V_4 ) -> V_30 = V_22 -> V_30 ;
V_3 -> V_32 = V_33 ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 ( V_4 ) ;
F_21 ( V_4 ) ;
return 0 ;
V_38:
F_22 ( V_24 ) ;
error:
F_21 ( V_4 ) ;
return V_25 ;
}
static int F_23 ( struct V_42 * V_43 )
{
* F_24 ( V_43 , V_44 ) = 0 ;
return 0 ;
}
static void F_25 ( void * V_45 , struct V_42 * V_43 ,
int V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
F_26 ( F_27 () ) ;
F_8 ( L_2 , V_4 , V_9 ) ;
if ( V_9 )
goto error;
V_9 = F_23 ( V_43 ) ;
if ( V_9 )
goto V_46;
V_9 = F_28 ( V_4 , V_43 ) ;
if ( V_9 )
goto V_46;
F_9 ( & V_4 -> V_7 . V_5 ) ;
if ( ! F_29 ( & V_4 -> V_7 ) )
F_30 ( & F_11 ( V_4 ) -> V_47 ) ;
else
F_11 ( V_4 ) -> V_8 = false ;
F_12 ( & V_4 -> V_7 . V_5 ) ;
F_16 ( V_4 ) ;
return;
V_46:
F_31 ( V_43 ) ;
error:
F_13 ( V_4 , V_9 ) ;
F_16 ( V_4 ) ;
}
static void F_32 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_33 ( V_49 ) ;
struct V_23 * V_24 = F_11 ( V_4 ) -> V_24 ;
T_1 V_30 = F_11 ( V_4 ) -> V_30 ;
struct V_42 * V_43 ;
int V_25 ;
F_8 ( L_6 , V_4 , V_30 ) ;
if ( V_4 -> V_10 & V_50 ) {
F_7 ( V_4 ) ;
return;
}
V_43 = F_34 ( & V_4 -> V_7 ) ;
F_35 ( V_4 ) ;
V_25 = F_36 ( V_24 , V_30 , V_43 ,
F_25 , V_4 ) ;
if ( V_25 ) {
F_13 ( V_4 , V_25 ) ;
F_16 ( V_4 ) ;
}
}
static int F_37 ( struct V_14 * V_3 , struct V_51 * V_52 , T_2 V_19 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
struct V_23 * V_24 = F_11 ( V_4 ) -> V_24 ;
struct V_42 * V_43 ;
int V_25 ;
F_8 ( L_7 , V_3 , V_4 , V_19 ) ;
if ( V_52 -> V_53 )
return - V_54 ;
if ( V_3 -> V_32 != V_33 )
return - V_55 ;
V_43 = F_38 ( V_24 , V_4 , V_52 -> V_56 , V_19 , & V_25 ) ;
if ( V_43 == NULL )
return V_25 ;
V_25 = F_39 ( F_40 ( V_43 , V_19 ) , V_52 , V_19 ) ;
if ( V_25 < 0 ) {
F_31 ( V_43 ) ;
return V_25 ;
}
F_9 ( & V_4 -> V_7 . V_5 ) ;
F_41 ( & V_4 -> V_7 , V_43 ) ;
if ( ! F_11 ( V_4 ) -> V_8 ) {
F_30 ( & F_11 ( V_4 ) -> V_47 ) ;
F_11 ( V_4 ) -> V_8 = true ;
}
F_12 ( & V_4 -> V_7 . V_5 ) ;
return V_19 ;
}
static int F_42 ( struct V_14 * V_3 , struct V_51 * V_52 , T_2 V_19 ,
int V_20 )
{
int V_57 = V_20 & V_58 ;
struct V_3 * V_4 = V_3 -> V_4 ;
struct V_42 * V_43 ;
int V_59 ;
int V_25 ;
F_8 ( L_8 , V_3 , V_4 , V_19 , V_20 ) ;
V_43 = F_43 ( V_4 , V_20 , V_57 , & V_25 ) ;
if ( ! V_43 )
return V_25 ;
V_59 = V_43 -> V_19 ;
if ( V_19 < V_59 ) {
V_52 -> V_56 |= V_60 ;
V_59 = V_19 ;
}
V_25 = F_44 ( V_43 , 0 , V_52 , V_59 ) ;
F_45 ( V_4 , V_43 ) ;
return V_25 ? : V_59 ;
}
static void F_46 ( struct V_3 * V_4 )
{
F_8 ( L_1 , V_4 ) ;
if ( V_4 -> V_39 == V_40 ) {
F_47 ( F_11 ( V_4 ) -> V_24 ,
F_11 ( V_4 ) -> V_30 ) ;
F_22 ( F_11 ( V_4 ) -> V_24 ) ;
}
F_48 ( & V_4 -> V_61 ) ;
if ( ! F_49 ( V_4 , V_62 ) ) {
F_50 ( L_9 , V_4 ) ;
return;
}
}
static int F_51 ( struct V_63 * V_63 , struct V_14 * V_3 ,
const struct V_31 * V_64 , int V_65 )
{
struct V_3 * V_4 ;
F_8 ( L_10 , V_3 ) ;
if ( ( V_3 -> type != V_66 ) && ( V_3 -> type != V_15 ) )
return - V_67 ;
if ( V_3 -> type == V_15 )
V_3 -> V_68 = & V_69 ;
else
V_3 -> V_68 = & V_70 ;
V_4 = F_52 ( V_63 , V_71 , V_72 , V_64 -> V_73 , V_65 ) ;
if ( ! V_4 )
return - V_74 ;
F_53 ( V_3 , V_4 ) ;
V_4 -> V_75 = V_64 -> V_76 ;
V_4 -> V_77 = F_46 ;
V_3 -> V_32 = V_78 ;
if ( V_3 -> type == V_15 )
F_1 ( & V_16 , V_4 ) ;
else {
F_54 ( & F_11 ( V_4 ) -> V_47 , F_32 ) ;
F_11 ( V_4 ) -> V_8 = false ;
}
return 0 ;
}
void F_55 ( struct V_23 * V_24 , struct V_42 * V_43 ,
T_3 V_79 , T_3 V_80 )
{
struct V_42 * V_81 = NULL , * V_82 ;
struct V_3 * V_4 ;
T_3 * V_83 ;
F_56 ( & V_16 . V_5 ) ;
F_57 (sk, &raw_sk_list.head) {
if ( ! V_81 ) {
V_81 = F_58 ( V_43 , V_84 ,
V_72 , true ) ;
if ( ! V_81 )
continue;
V_83 = F_24 ( V_81 , V_84 ) ;
V_83 [ 0 ] = V_24 ? V_24 -> V_85 : 0xFF ;
V_83 [ 1 ] = V_80 & 0x01 ;
V_83 [ 1 ] |= ( V_79 << 1 ) ;
}
V_82 = F_59 ( V_81 , V_72 ) ;
if ( ! V_82 )
continue;
if ( F_28 ( V_4 , V_82 ) )
F_31 ( V_82 ) ;
}
F_60 ( & V_16 . V_5 ) ;
F_31 ( V_81 ) ;
}
int T_4 F_61 ( void )
{
int V_25 ;
V_25 = F_62 ( & V_86 ) ;
return V_25 ;
}
void F_63 ( void )
{
F_64 ( & V_86 ) ;
}
