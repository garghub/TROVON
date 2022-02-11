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
case 8 :
V_6 = V_12 ;
break;
default:
F_7 () ;
}
return V_6 ;
}
void F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ,
F_10 ( * V_16 ) , V_17 ) ;
F_11 ( & V_16 -> V_18 ) ;
F_12 ( & V_16 -> V_19 -> V_20 ) ;
F_13 ( V_16 ) ;
}
static struct V_15 *
F_14 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 ;
int V_6 ;
V_16 = F_15 ( sizeof( * V_16 ) , V_23 ) ;
if ( V_16 == NULL )
return F_16 ( - V_24 ) ;
F_17 ( & V_16 -> V_17 ) ;
V_16 -> V_19 = F_18 ( V_2 , V_4 -> V_25 ) ;
F_19 ( & V_16 -> V_18 ) ;
if ( V_16 -> V_19 == NULL ) {
F_13 ( V_16 ) ;
F_20 ( L_1 ) ;
return F_16 ( - V_24 ) ;
}
if ( F_2 ( V_2 ) -> V_8 >= 7 ) {
V_6 = F_21 ( V_16 -> V_19 ,
V_26 ) ;
if ( F_22 ( V_6 ) )
goto V_27;
}
V_16 -> V_28 = & V_4 -> V_28 [ V_29 ] ;
F_23 ( & V_16 -> V_18 , & V_4 -> V_30 ) ;
if ( V_22 == NULL )
return V_16 ;
V_6 = F_24 ( & V_22 -> V_31 , V_16 , V_32 + 1 , 0 ,
V_23 ) ;
if ( V_6 < 0 )
goto V_27;
V_16 -> V_22 = V_22 ;
V_16 -> V_33 = V_6 ;
V_16 -> V_34 = ( 1 << F_25 ( V_2 ) ) - 1 ;
return V_16 ;
V_27:
F_26 ( V_16 ) ;
return F_16 ( V_6 ) ;
}
static inline bool F_27 ( struct V_15 * V_16 )
{
return ( V_16 == V_16 -> V_28 -> V_35 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_15 * V_16 ;
int V_6 ;
F_29 ( ! F_30 ( & V_4 -> V_2 -> V_36 ) ) ;
V_16 = F_14 ( V_4 -> V_2 , NULL ) ;
if ( F_31 ( V_16 ) )
return F_32 ( V_16 ) ;
V_6 = F_33 ( V_16 -> V_19 , V_37 , false , false ) ;
if ( V_6 ) {
F_20 ( L_2 , V_6 ) ;
goto V_38;
}
V_6 = F_34 ( V_16 ) ;
if ( V_6 ) {
F_20 ( L_3 , V_6 ) ;
goto V_39;
}
V_4 -> V_28 [ V_29 ] . V_35 = V_16 ;
F_20 ( L_4 ) ;
return 0 ;
V_39:
F_35 ( V_16 -> V_19 ) ;
V_38:
F_26 ( V_16 ) ;
return V_6 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
if ( ! F_37 ( V_2 ) )
return 0 ;
if ( V_4 -> V_28 [ V_29 ] . V_35 )
return 0 ;
V_4 -> V_25 = F_38 ( F_1 ( V_2 ) , 4096 ) ;
if ( V_4 -> V_25 > ( 1 << 20 ) ) {
F_20 ( L_5 ) ;
return - V_40 ;
}
V_6 = F_28 ( V_4 ) ;
if ( V_6 ) {
F_20 ( L_6 ,
V_6 ) ;
return V_6 ;
}
F_20 ( L_7 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_41 = V_4 -> V_28 [ V_29 ] . V_35 ;
if ( ! F_37 ( V_2 ) )
return;
F_40 ( V_2 ) ;
F_22 ( ! V_4 -> V_28 [ V_29 ] . V_42 ) ;
if ( V_4 -> V_28 [ V_29 ] . V_42 == V_41 ) {
F_22 ( V_41 -> V_19 -> V_43 ) ;
F_35 ( V_41 -> V_19 ) ;
F_26 ( V_41 ) ;
}
F_35 ( V_41 -> V_19 ) ;
F_26 ( V_41 ) ;
V_4 -> V_28 [ V_29 ] . V_35 = NULL ;
V_4 -> V_28 [ V_29 ] . V_42 = NULL ;
}
static int F_41 ( int V_33 , void * V_44 , void * V_45 )
{
struct V_15 * V_16 = V_44 ;
F_29 ( V_33 == V_32 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
struct V_46 *
F_42 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
T_1 V_33 )
{
struct V_21 * V_22 = V_48 -> V_49 ;
struct V_15 * V_16 ;
if ( V_33 == V_32 )
return & V_22 -> V_50 ;
if ( ! F_37 ( V_2 ) )
return F_16 ( - V_51 ) ;
V_16 = F_43 ( V_48 -> V_49 , V_33 ) ;
if ( V_16 == NULL )
return F_16 ( - V_51 ) ;
return & V_16 -> V_50 ;
}
void F_44 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_21 * V_22 = V_48 -> V_49 ;
F_45 ( & V_22 -> V_31 , F_41 , NULL ) ;
F_46 ( & V_22 -> V_31 ) ;
}
static struct V_15 *
F_43 ( struct V_21 * V_22 , T_1 V_33 )
{
return (struct V_15 * ) F_47 ( & V_22 -> V_31 , V_33 ) ;
}
static inline int
F_48 ( struct V_52 * V_28 ,
struct V_15 * V_53 ,
T_1 V_54 )
{
int V_6 ;
if ( F_49 ( V_28 -> V_2 ) && V_28 -> V_55 ) {
V_6 = V_28 -> V_56 ( V_28 , V_57 , 0 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_50 ( V_28 , 6 ) ;
if ( V_6 )
return V_6 ;
if ( F_51 ( V_28 -> V_2 ) )
F_52 ( V_28 , V_58 | V_59 ) ;
else
F_52 ( V_28 , V_60 ) ;
F_52 ( V_28 , V_60 ) ;
F_52 ( V_28 , V_61 ) ;
F_52 ( V_28 , F_53 ( V_53 -> V_19 ) |
V_62 |
V_63 |
V_64 |
V_54 ) ;
F_52 ( V_28 , V_60 ) ;
if ( F_51 ( V_28 -> V_2 ) )
F_52 ( V_28 , V_58 | V_65 ) ;
else
F_52 ( V_28 , V_60 ) ;
F_54 ( V_28 ) ;
return V_6 ;
}
static int F_34 ( struct V_15 * V_66 )
{
struct V_52 * V_28 = V_66 -> V_28 ;
struct V_15 * V_67 = V_28 -> V_42 ;
T_1 V_54 = 0 ;
int V_6 , V_68 ;
F_29 ( V_67 != NULL && V_67 -> V_19 != NULL && V_67 -> V_19 -> V_69 == 0 ) ;
if ( V_67 == V_66 && ! V_66 -> V_34 )
return 0 ;
V_6 = F_33 ( V_66 -> V_19 , V_37 , false , false ) ;
if ( V_6 )
return V_6 ;
V_67 = V_28 -> V_42 ;
V_6 = F_55 ( V_66 -> V_19 , false ) ;
if ( V_6 ) {
F_35 ( V_66 -> V_19 ) ;
return V_6 ;
}
if ( ! V_66 -> V_19 -> V_70 )
F_56 ( V_66 -> V_19 , V_66 -> V_19 -> V_71 ) ;
if ( ! V_66 -> V_72 || F_27 ( V_66 ) )
V_54 |= V_73 ;
V_6 = F_48 ( V_28 , V_66 , V_54 ) ;
if ( V_6 ) {
F_35 ( V_66 -> V_19 ) ;
return V_6 ;
}
for ( V_68 = 0 ; V_68 < V_74 ; V_68 ++ ) {
if ( ! ( V_66 -> V_34 & ( 1 << V_68 ) ) )
continue;
V_6 = F_57 ( V_28 , V_68 ) ;
if ( V_6 )
F_20 ( L_8 ) ;
else
V_66 -> V_34 &= ~ ( 1 << V_68 ) ;
}
if ( V_67 != NULL ) {
V_67 -> V_19 -> V_20 . V_75 = V_76 ;
F_58 ( F_59 ( V_67 -> V_19 ) , V_28 ) ;
V_67 -> V_19 -> V_77 = 1 ;
F_29 ( V_67 -> V_19 -> V_28 != V_28 ) ;
F_35 ( V_67 -> V_19 ) ;
F_26 ( V_67 ) ;
}
F_60 ( V_66 ) ;
V_28 -> V_42 = V_66 ;
V_66 -> V_72 = true ;
return 0 ;
}
int F_61 ( struct V_52 * V_28 ,
struct V_47 * V_48 ,
int V_78 )
{
struct V_3 * V_4 = V_28 -> V_2 -> V_5 ;
struct V_15 * V_66 ;
if ( ! F_37 ( V_28 -> V_2 ) )
return 0 ;
F_22 ( ! F_30 ( & V_4 -> V_2 -> V_36 ) ) ;
if ( V_28 != & V_4 -> V_28 [ V_29 ] )
return 0 ;
if ( V_78 == V_32 ) {
V_66 = V_28 -> V_35 ;
} else {
if ( V_48 == NULL )
return - V_79 ;
V_66 = F_43 ( V_48 -> V_49 , V_78 ) ;
if ( V_66 == NULL )
return - V_51 ;
}
return F_34 ( V_66 ) ;
}
int F_62 ( struct V_1 * V_2 , void * V_45 ,
struct V_47 * V_48 )
{
struct V_80 * args = V_45 ;
struct V_21 * V_22 = V_48 -> V_49 ;
struct V_15 * V_16 ;
int V_6 ;
if ( ! ( V_2 -> V_81 -> V_82 & V_83 ) )
return - V_84 ;
if ( ! F_37 ( V_2 ) )
return - V_84 ;
V_6 = F_63 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_16 = F_14 ( V_2 , V_22 ) ;
F_64 ( & V_2 -> V_36 ) ;
if ( F_31 ( V_16 ) )
return F_32 ( V_16 ) ;
args -> V_85 = V_16 -> V_33 ;
F_20 ( L_9 , args -> V_85 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , void * V_45 ,
struct V_47 * V_48 )
{
struct V_86 * args = V_45 ;
struct V_21 * V_22 = V_48 -> V_49 ;
struct V_15 * V_16 ;
int V_6 ;
if ( ! ( V_2 -> V_81 -> V_82 & V_83 ) )
return - V_84 ;
V_6 = F_63 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_16 = F_43 ( V_22 , args -> V_85 ) ;
if ( ! V_16 ) {
F_64 ( & V_2 -> V_36 ) ;
return - V_51 ;
}
F_66 ( & V_16 -> V_22 -> V_31 , V_16 -> V_33 ) ;
F_26 ( V_16 ) ;
F_64 ( & V_2 -> V_36 ) ;
F_20 ( L_10 , args -> V_85 ) ;
return 0 ;
}
