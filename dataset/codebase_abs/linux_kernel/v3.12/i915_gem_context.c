static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_1 V_7 ;
switch ( F_2 ( V_2 ) -> V_8 ) {
case 6 :
V_7 = F_3 ( V_9 ) ;
V_6 = F_4 ( V_7 ) * 64 ;
break;
case 7 :
V_7 = F_3 ( V_10 ) ;
if ( F_5 ( V_2 ) )
V_6 = V_11 ;
else
V_6 = F_6 ( V_7 ) * 64 ;
break;
default:
F_7 () ;
}
return V_6 ;
}
void F_8 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_9 ( V_13 ,
F_10 ( * V_15 ) , V_16 ) ;
F_11 ( & V_15 -> V_17 -> V_18 ) ;
F_12 ( V_15 ) ;
}
static struct V_14 *
F_13 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_14 * V_15 ;
int V_6 ;
V_15 = F_14 ( sizeof( * V_15 ) , V_21 ) ;
if ( V_15 == NULL )
return F_15 ( - V_22 ) ;
F_16 ( & V_15 -> V_16 ) ;
V_15 -> V_17 = F_17 ( V_2 , V_4 -> V_23 ) ;
if ( V_15 -> V_17 == NULL ) {
F_12 ( V_15 ) ;
F_18 ( L_1 ) ;
return F_15 ( - V_22 ) ;
}
if ( F_2 ( V_2 ) -> V_8 >= 7 ) {
V_6 = F_19 ( V_15 -> V_17 ,
V_24 ) ;
if ( F_20 ( V_6 ) )
goto V_25;
}
V_15 -> V_26 = & V_4 -> V_26 [ V_27 ] ;
if ( V_20 == NULL )
return V_15 ;
V_6 = F_21 ( & V_20 -> V_28 , V_15 , V_29 + 1 , 0 ,
V_21 ) ;
if ( V_6 < 0 )
goto V_25;
V_15 -> V_20 = V_20 ;
V_15 -> V_30 = V_6 ;
return V_15 ;
V_25:
F_22 ( V_15 ) ;
return F_15 ( V_6 ) ;
}
static inline bool F_23 ( struct V_14 * V_15 )
{
return ( V_15 == V_15 -> V_26 -> V_31 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
int V_6 ;
F_25 ( ! F_26 ( & V_4 -> V_2 -> V_32 ) ) ;
V_15 = F_13 ( V_4 -> V_2 , NULL ) ;
if ( F_27 ( V_15 ) )
return F_28 ( V_15 ) ;
V_4 -> V_26 [ V_27 ] . V_31 = V_15 ;
V_6 = F_29 ( V_15 -> V_17 , V_33 , false , false ) ;
if ( V_6 ) {
F_18 ( L_2 , V_6 ) ;
goto V_34;
}
V_6 = F_30 ( V_15 ) ;
if ( V_6 ) {
F_18 ( L_3 , V_6 ) ;
goto V_35;
}
F_18 ( L_4 ) ;
return 0 ;
V_35:
F_31 ( V_15 -> V_17 ) ;
V_34:
F_22 ( V_15 ) ;
return V_6 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_33 ( V_2 ) ) {
V_4 -> V_36 = true ;
F_18 ( L_5 ) ;
return;
}
if ( V_4 -> V_36 ||
V_4 -> V_26 [ V_27 ] . V_31 )
return;
V_4 -> V_23 = F_34 ( F_1 ( V_2 ) , 4096 ) ;
if ( V_4 -> V_23 > ( 1 << 20 ) ) {
V_4 -> V_36 = true ;
F_18 ( L_6 ) ;
return;
}
if ( F_24 ( V_4 ) ) {
V_4 -> V_36 = true ;
F_18 ( L_7 ) ;
return;
}
F_18 ( L_8 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_14 * V_37 = V_4 -> V_26 [ V_27 ] . V_31 ;
if ( V_4 -> V_36 )
return;
F_36 ( V_2 ) ;
F_31 ( V_37 -> V_17 ) ;
F_11 ( & V_37 -> V_17 -> V_18 ) ;
F_22 ( V_37 ) ;
}
static int F_37 ( int V_30 , void * V_38 , void * V_39 )
{
struct V_14 * V_15 = V_38 ;
F_25 ( V_30 == V_29 ) ;
F_22 ( V_15 ) ;
return 0 ;
}
struct V_40 *
F_38 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
T_1 V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 = V_42 -> V_43 ;
struct V_14 * V_15 ;
if ( V_30 == V_29 )
return & V_20 -> V_44 ;
V_15 = NULL ;
if ( ! V_4 -> V_36 )
V_15 = F_39 ( V_42 -> V_43 , V_30 ) ;
if ( V_15 == NULL )
return F_15 ( - V_45 ) ;
return & V_15 -> V_44 ;
}
void F_40 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
F_41 ( & V_2 -> V_32 ) ;
F_42 ( & V_20 -> V_28 , F_37 , NULL ) ;
F_43 ( & V_20 -> V_28 ) ;
F_44 ( & V_2 -> V_32 ) ;
}
static struct V_14 *
F_39 ( struct V_19 * V_20 , T_1 V_30 )
{
return (struct V_14 * ) F_45 ( & V_20 -> V_28 , V_30 ) ;
}
static inline int
F_46 ( struct V_46 * V_26 ,
struct V_14 * V_47 ,
T_1 V_48 )
{
int V_6 ;
if ( F_47 ( V_26 -> V_2 ) && V_26 -> V_49 ) {
V_6 = V_26 -> V_50 ( V_26 , V_51 , 0 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_48 ( V_26 , 6 ) ;
if ( V_6 )
return V_6 ;
if ( F_49 ( V_26 -> V_2 ) )
F_50 ( V_26 , V_52 | V_53 ) ;
else
F_50 ( V_26 , V_54 ) ;
F_50 ( V_26 , V_54 ) ;
F_50 ( V_26 , V_55 ) ;
F_50 ( V_26 , F_51 ( V_47 -> V_17 ) |
V_56 |
V_57 |
V_58 |
V_48 ) ;
F_50 ( V_26 , V_54 ) ;
if ( F_49 ( V_26 -> V_2 ) )
F_50 ( V_26 , V_52 | V_59 ) ;
else
F_50 ( V_26 , V_54 ) ;
F_52 ( V_26 ) ;
return V_6 ;
}
static int F_30 ( struct V_14 * V_60 )
{
struct V_46 * V_26 = V_60 -> V_26 ;
struct V_14 * V_61 = V_26 -> V_62 ;
T_1 V_48 = 0 ;
int V_6 ;
F_25 ( V_61 != NULL && V_61 -> V_17 != NULL && V_61 -> V_17 -> V_63 == 0 ) ;
if ( V_61 == V_60 )
return 0 ;
V_6 = F_29 ( V_60 -> V_17 , V_33 , false , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_53 ( V_60 -> V_17 , false ) ;
if ( V_6 ) {
F_31 ( V_60 -> V_17 ) ;
return V_6 ;
}
if ( ! V_60 -> V_17 -> V_64 )
F_54 ( V_60 -> V_17 , V_60 -> V_17 -> V_65 ) ;
if ( ! V_60 -> V_66 || F_23 ( V_60 ) )
V_48 |= V_67 ;
else if ( F_55 ( V_61 == V_60 ) )
V_48 |= V_68 ;
V_6 = F_46 ( V_26 , V_60 , V_48 ) ;
if ( V_6 ) {
F_31 ( V_60 -> V_17 ) ;
return V_6 ;
}
if ( V_61 != NULL ) {
struct V_3 * V_4 = V_61 -> V_17 -> V_18 . V_2 -> V_5 ;
struct V_69 * V_70 = & V_4 -> V_71 . V_18 ;
V_61 -> V_17 -> V_18 . V_72 = V_73 ;
F_56 ( & F_57 ( V_61 -> V_17 , V_70 ) -> V_74 , & V_70 -> V_75 ) ;
F_58 ( V_61 -> V_17 , V_26 ) ;
V_61 -> V_17 -> V_76 = 1 ;
F_25 ( V_61 -> V_17 -> V_26 != V_26 ) ;
V_6 = F_59 ( V_26 , NULL ) ;
if ( V_6 ) {
F_20 ( F_46 ( V_26 , V_61 , V_67 ) ) ;
return V_6 ;
}
F_31 ( V_61 -> V_17 ) ;
F_22 ( V_61 ) ;
}
F_60 ( V_60 ) ;
V_26 -> V_62 = V_60 ;
V_60 -> V_66 = true ;
return 0 ;
}
int F_61 ( struct V_46 * V_26 ,
struct V_41 * V_42 ,
int V_77 )
{
struct V_3 * V_4 = V_26 -> V_2 -> V_5 ;
struct V_14 * V_60 ;
if ( V_4 -> V_36 )
return 0 ;
F_20 ( ! F_26 ( & V_4 -> V_2 -> V_32 ) ) ;
if ( V_26 != & V_4 -> V_26 [ V_27 ] )
return 0 ;
if ( V_77 == V_29 ) {
V_60 = V_26 -> V_31 ;
} else {
if ( V_42 == NULL )
return - V_78 ;
V_60 = F_39 ( V_42 -> V_43 , V_77 ) ;
if ( V_60 == NULL )
return - V_45 ;
}
return F_30 ( V_60 ) ;
}
int F_62 ( struct V_1 * V_2 , void * V_39 ,
struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * args = V_39 ;
struct V_19 * V_20 = V_42 -> V_43 ;
struct V_14 * V_15 ;
int V_6 ;
if ( ! ( V_2 -> V_80 -> V_81 & V_82 ) )
return - V_83 ;
if ( V_4 -> V_36 )
return - V_83 ;
V_6 = F_63 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_15 = F_13 ( V_2 , V_20 ) ;
F_44 ( & V_2 -> V_32 ) ;
if ( F_27 ( V_15 ) )
return F_28 ( V_15 ) ;
args -> V_84 = V_15 -> V_30 ;
F_18 ( L_9 , args -> V_84 ) ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , void * V_39 ,
struct V_41 * V_42 )
{
struct V_85 * args = V_39 ;
struct V_19 * V_20 = V_42 -> V_43 ;
struct V_14 * V_15 ;
int V_6 ;
if ( ! ( V_2 -> V_80 -> V_81 & V_82 ) )
return - V_83 ;
V_6 = F_63 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_15 = F_39 ( V_20 , args -> V_84 ) ;
if ( ! V_15 ) {
F_44 ( & V_2 -> V_32 ) ;
return - V_45 ;
}
F_65 ( & V_15 -> V_20 -> V_28 , V_15 -> V_30 ) ;
F_22 ( V_15 ) ;
F_44 ( & V_2 -> V_32 ) ;
F_18 ( L_10 , args -> V_84 ) ;
return 0 ;
}
