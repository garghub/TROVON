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
V_6 = F_6 ( V_7 ) * 64 ;
else
V_6 = F_7 ( V_7 ) * 64 ;
break;
default:
F_8 () ;
}
return V_6 ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 -> V_14 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_12 -> V_15 )
F_10 ( & V_12 -> V_15 -> V_16 , V_12 -> V_17 ) ;
else
F_11 ( V_12 != V_4 -> V_18 [ V_19 ] . V_20 ) ;
F_12 ( & V_12 -> V_13 -> V_14 ) ;
F_13 ( V_12 ) ;
}
static struct V_11 *
F_14 ( struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_6 , V_17 ;
V_12 = F_15 ( sizeof( * V_12 ) , V_22 ) ;
if ( V_12 == NULL )
return F_16 ( - V_23 ) ;
V_12 -> V_13 = F_17 ( V_2 , V_4 -> V_24 ) ;
if ( V_12 -> V_13 == NULL ) {
F_13 ( V_12 ) ;
F_18 ( L_1 ) ;
return F_16 ( - V_23 ) ;
}
V_12 -> V_18 = & V_4 -> V_18 [ V_19 ] ;
if ( V_15 == NULL )
return V_12 ;
V_12 -> V_15 = V_15 ;
V_25:
if ( F_19 ( & V_15 -> V_16 , V_22 ) == 0 ) {
V_6 = - V_23 ;
F_18 ( L_2 ) ;
goto V_26;
}
V_6 = F_20 ( & V_15 -> V_16 , V_12 ,
V_27 + 1 , & V_17 ) ;
if ( V_6 == 0 )
V_12 -> V_17 = V_17 ;
if ( V_6 == - V_28 )
goto V_25;
else if ( V_6 )
goto V_26;
return V_12 ;
V_26:
F_9 ( V_12 ) ;
return F_16 ( V_6 ) ;
}
static inline bool F_21 ( struct V_11 * V_12 )
{
return ( V_12 == V_12 -> V_18 -> V_20 ) ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_6 ;
F_11 ( ! F_23 ( & V_4 -> V_2 -> V_29 ) ) ;
V_12 = F_14 ( V_4 -> V_2 , NULL ) ;
if ( F_24 ( V_12 ) )
return F_25 ( V_12 ) ;
V_4 -> V_18 [ V_19 ] . V_20 = V_12 ;
V_6 = F_26 ( V_12 -> V_13 , V_30 , false , false ) ;
if ( V_6 )
goto V_31;
V_6 = F_27 ( V_12 ) ;
if ( V_6 )
goto V_32;
F_18 ( L_3 ) ;
return 0 ;
V_32:
F_28 ( V_12 -> V_13 ) ;
V_31:
F_9 ( V_12 ) ;
return V_6 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_33 ;
if ( ! F_30 ( V_2 ) ) {
V_4 -> V_34 = true ;
return;
}
if ( V_4 -> V_34 ||
V_4 -> V_18 [ V_19 ] . V_20 )
return;
V_33 = F_1 ( V_2 ) ;
V_4 -> V_24 = F_1 ( V_2 ) ;
V_4 -> V_24 = F_31 ( V_4 -> V_24 , 4096 ) ;
if ( V_33 <= 0 || V_33 > ( 1 << 20 ) ) {
V_4 -> V_34 = true ;
return;
}
if ( F_22 ( V_4 ) ) {
V_4 -> V_34 = true ;
return;
}
F_18 ( L_4 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_34 )
return;
F_33 ( V_2 ) ;
F_28 ( V_4 -> V_18 [ V_19 ] . V_20 -> V_13 ) ;
F_9 ( V_4 -> V_18 [ V_19 ] . V_20 ) ;
}
static int F_34 ( int V_17 , void * V_35 , void * V_36 )
{
struct V_11 * V_12 = V_35 ;
F_11 ( V_17 == V_27 ) ;
F_9 ( V_12 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_21 * V_15 = V_38 -> V_39 ;
F_36 ( & V_2 -> V_29 ) ;
F_37 ( & V_15 -> V_16 , F_34 , NULL ) ;
F_38 ( & V_15 -> V_16 ) ;
F_39 ( & V_2 -> V_29 ) ;
}
static struct V_11 *
F_40 ( struct V_21 * V_15 , T_1 V_17 )
{
return (struct V_11 * ) F_41 ( & V_15 -> V_16 , V_17 ) ;
}
static inline int
F_42 ( struct V_40 * V_18 ,
struct V_11 * V_41 ,
T_1 V_42 )
{
int V_6 ;
if ( F_43 ( V_18 -> V_2 ) && V_18 -> V_43 ) {
V_6 = V_18 -> V_44 ( V_18 , V_45 , 0 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_44 ( V_18 , 6 ) ;
if ( V_6 )
return V_6 ;
if ( F_45 ( V_18 -> V_2 ) )
F_46 ( V_18 , V_46 | V_47 ) ;
else
F_46 ( V_18 , V_48 ) ;
F_46 ( V_18 , V_48 ) ;
F_46 ( V_18 , V_49 ) ;
F_46 ( V_18 , V_41 -> V_13 -> V_50 |
V_51 |
V_52 |
V_53 |
V_42 ) ;
F_46 ( V_18 , V_48 ) ;
if ( F_45 ( V_18 -> V_2 ) )
F_46 ( V_18 , V_46 | V_54 ) ;
else
F_46 ( V_18 , V_48 ) ;
F_47 ( V_18 ) ;
return V_6 ;
}
static int F_27 ( struct V_11 * V_55 )
{
struct V_40 * V_18 = V_55 -> V_18 ;
struct V_56 * V_57 = V_18 -> V_58 ;
T_1 V_42 = 0 ;
int V_6 ;
F_11 ( V_57 != NULL && V_57 -> V_59 == 0 ) ;
if ( V_57 == V_55 -> V_13 )
return 0 ;
V_6 = F_26 ( V_55 -> V_13 , V_30 , false , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_48 ( V_55 -> V_13 , false ) ;
if ( V_6 ) {
F_28 ( V_55 -> V_13 ) ;
return V_6 ;
}
if ( ! V_55 -> V_13 -> V_60 )
F_49 ( V_55 -> V_13 , V_55 -> V_13 -> V_61 ) ;
if ( ! V_55 -> V_62 || F_21 ( V_55 ) )
V_42 |= V_63 ;
else if ( F_50 ( V_57 == V_55 -> V_13 ) )
V_42 |= V_64 ;
V_6 = F_42 ( V_18 , V_55 , V_42 ) ;
if ( V_6 ) {
F_28 ( V_55 -> V_13 ) ;
return V_6 ;
}
if ( V_57 != NULL ) {
V_57 -> V_14 . V_65 = V_66 ;
F_51 ( V_57 , V_18 ) ;
V_57 -> V_67 = 1 ;
F_11 ( V_57 -> V_18 != V_18 ) ;
F_28 ( V_57 ) ;
F_12 ( & V_57 -> V_14 ) ;
}
F_52 ( & V_55 -> V_13 -> V_14 ) ;
V_18 -> V_58 = V_55 -> V_13 ;
V_55 -> V_62 = true ;
return 0 ;
}
int F_53 ( struct V_40 * V_18 ,
struct V_37 * V_38 ,
int V_68 )
{
struct V_3 * V_4 = V_18 -> V_2 -> V_5 ;
struct V_11 * V_55 ;
if ( V_4 -> V_34 )
return 0 ;
if ( V_18 != & V_4 -> V_18 [ V_19 ] )
return 0 ;
if ( V_68 == V_27 ) {
V_55 = V_18 -> V_20 ;
} else {
if ( V_38 == NULL )
return - V_69 ;
V_55 = F_40 ( V_38 -> V_39 , V_68 ) ;
if ( V_55 == NULL )
return - V_70 ;
}
return F_27 ( V_55 ) ;
}
int F_54 ( struct V_1 * V_2 , void * V_36 ,
struct V_37 * V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_71 * args = V_36 ;
struct V_21 * V_15 = V_38 -> V_39 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_72 -> V_73 & V_74 ) )
return - V_75 ;
if ( V_4 -> V_34 )
return - V_75 ;
V_6 = F_55 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_14 ( V_2 , V_15 ) ;
F_39 ( & V_2 -> V_29 ) ;
if ( F_24 ( V_12 ) )
return F_25 ( V_12 ) ;
args -> V_76 = V_12 -> V_17 ;
F_18 ( L_5 , args -> V_76 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , void * V_36 ,
struct V_37 * V_38 )
{
struct V_77 * args = V_36 ;
struct V_21 * V_15 = V_38 -> V_39 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_72 -> V_73 & V_74 ) )
return - V_75 ;
V_6 = F_55 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_40 ( V_15 , args -> V_76 ) ;
if ( ! V_12 ) {
F_39 ( & V_2 -> V_29 ) ;
return - V_70 ;
}
F_9 ( V_12 ) ;
F_39 ( & V_2 -> V_29 ) ;
F_18 ( L_6 , args -> V_76 ) ;
return 0 ;
}
