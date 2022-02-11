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
if ( V_12 -> V_13 )
F_10 ( & V_12 -> V_13 -> V_14 , V_12 -> V_15 ) ;
F_11 ( & V_12 -> V_16 -> V_17 ) ;
F_12 ( V_12 ) ;
}
static struct V_11 *
F_13 ( struct V_1 * V_2 ,
struct V_18 * V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_6 ;
V_12 = F_14 ( sizeof( * V_12 ) , V_19 ) ;
if ( V_12 == NULL )
return F_15 ( - V_20 ) ;
V_12 -> V_16 = F_16 ( V_2 , V_4 -> V_21 ) ;
if ( V_12 -> V_16 == NULL ) {
F_12 ( V_12 ) ;
F_17 ( L_1 ) ;
return F_15 ( - V_20 ) ;
}
V_12 -> V_22 = & V_4 -> V_22 [ V_23 ] ;
if ( V_13 == NULL )
return V_12 ;
V_12 -> V_13 = V_13 ;
V_6 = F_18 ( & V_13 -> V_14 , V_12 , V_24 + 1 , 0 ,
V_19 ) ;
if ( V_6 < 0 )
goto V_25;
V_12 -> V_15 = V_6 ;
return V_12 ;
V_25:
F_9 ( V_12 ) ;
return F_15 ( V_6 ) ;
}
static inline bool F_19 ( struct V_11 * V_12 )
{
return ( V_12 == V_12 -> V_22 -> V_26 ) ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_6 ;
F_21 ( ! F_22 ( & V_4 -> V_2 -> V_27 ) ) ;
V_12 = F_13 ( V_4 -> V_2 , NULL ) ;
if ( F_23 ( V_12 ) )
return F_24 ( V_12 ) ;
V_4 -> V_22 [ V_23 ] . V_26 = V_12 ;
V_6 = F_25 ( V_12 -> V_16 , V_28 , false , false ) ;
if ( V_6 )
goto V_29;
V_6 = F_26 ( V_12 ) ;
if ( V_6 )
goto V_30;
F_17 ( L_2 ) ;
return 0 ;
V_30:
F_27 ( V_12 -> V_16 ) ;
V_29:
F_9 ( V_12 ) ;
return V_6 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_29 ( V_2 ) ) {
V_4 -> V_31 = true ;
return;
}
if ( V_4 -> V_31 ||
V_4 -> V_22 [ V_23 ] . V_26 )
return;
V_4 -> V_21 = F_30 ( F_1 ( V_2 ) , 4096 ) ;
if ( V_4 -> V_21 > ( 1 << 20 ) ) {
V_4 -> V_31 = true ;
return;
}
if ( F_20 ( V_4 ) ) {
V_4 -> V_31 = true ;
return;
}
F_17 ( L_3 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_31 )
return;
F_32 ( V_2 ) ;
F_27 ( V_4 -> V_22 [ V_23 ] . V_26 -> V_16 ) ;
F_9 ( V_4 -> V_22 [ V_23 ] . V_26 ) ;
}
static int F_33 ( int V_15 , void * V_32 , void * V_33 )
{
struct V_11 * V_12 = V_32 ;
F_21 ( V_15 == V_24 ) ;
F_9 ( V_12 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_18 * V_13 = V_35 -> V_36 ;
F_35 ( & V_2 -> V_27 ) ;
F_36 ( & V_13 -> V_14 , F_33 , NULL ) ;
F_37 ( & V_13 -> V_14 ) ;
F_38 ( & V_2 -> V_27 ) ;
}
static struct V_11 *
F_39 ( struct V_18 * V_13 , T_1 V_15 )
{
return (struct V_11 * ) F_40 ( & V_13 -> V_14 , V_15 ) ;
}
static inline int
F_41 ( struct V_37 * V_22 ,
struct V_11 * V_38 ,
T_1 V_39 )
{
int V_6 ;
if ( F_42 ( V_22 -> V_2 ) && V_22 -> V_40 ) {
V_6 = V_22 -> V_41 ( V_22 , V_42 , 0 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_43 ( V_22 , 6 ) ;
if ( V_6 )
return V_6 ;
if ( F_44 ( V_22 -> V_2 ) )
F_45 ( V_22 , V_43 | V_44 ) ;
else
F_45 ( V_22 , V_45 ) ;
F_45 ( V_22 , V_45 ) ;
F_45 ( V_22 , V_46 ) ;
F_45 ( V_22 , V_38 -> V_16 -> V_47 |
V_48 |
V_49 |
V_50 |
V_39 ) ;
F_45 ( V_22 , V_45 ) ;
if ( F_44 ( V_22 -> V_2 ) )
F_45 ( V_22 , V_43 | V_51 ) ;
else
F_45 ( V_22 , V_45 ) ;
F_46 ( V_22 ) ;
return V_6 ;
}
static int F_26 ( struct V_11 * V_52 )
{
struct V_37 * V_22 = V_52 -> V_22 ;
struct V_53 * V_54 = V_22 -> V_55 ;
T_1 V_39 = 0 ;
int V_6 ;
F_21 ( V_54 != NULL && V_54 -> V_56 == 0 ) ;
if ( V_54 == V_52 -> V_16 )
return 0 ;
V_6 = F_25 ( V_52 -> V_16 , V_28 , false , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_47 ( V_52 -> V_16 , false ) ;
if ( V_6 ) {
F_27 ( V_52 -> V_16 ) ;
return V_6 ;
}
if ( ! V_52 -> V_16 -> V_57 )
F_48 ( V_52 -> V_16 , V_52 -> V_16 -> V_58 ) ;
if ( ! V_52 -> V_59 || F_19 ( V_52 ) )
V_39 |= V_60 ;
else if ( F_49 ( V_54 == V_52 -> V_16 ) )
V_39 |= V_61 ;
V_6 = F_41 ( V_22 , V_52 , V_39 ) ;
if ( V_6 ) {
F_27 ( V_52 -> V_16 ) ;
return V_6 ;
}
if ( V_54 != NULL ) {
V_54 -> V_17 . V_62 = V_63 ;
F_50 ( V_54 , V_22 ) ;
V_54 -> V_64 = 1 ;
F_21 ( V_54 -> V_22 != V_22 ) ;
F_27 ( V_54 ) ;
F_11 ( & V_54 -> V_17 ) ;
}
F_51 ( & V_52 -> V_16 -> V_17 ) ;
V_22 -> V_55 = V_52 -> V_16 ;
V_52 -> V_59 = true ;
return 0 ;
}
int F_52 ( struct V_37 * V_22 ,
struct V_34 * V_35 ,
int V_65 )
{
struct V_3 * V_4 = V_22 -> V_2 -> V_5 ;
struct V_11 * V_52 ;
if ( V_4 -> V_31 )
return 0 ;
if ( V_22 != & V_4 -> V_22 [ V_23 ] )
return 0 ;
if ( V_65 == V_24 ) {
V_52 = V_22 -> V_26 ;
} else {
if ( V_35 == NULL )
return - V_66 ;
V_52 = F_39 ( V_35 -> V_36 , V_65 ) ;
if ( V_52 == NULL )
return - V_67 ;
}
return F_26 ( V_52 ) ;
}
int F_53 ( struct V_1 * V_2 , void * V_33 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_68 * args = V_33 ;
struct V_18 * V_13 = V_35 -> V_36 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_69 -> V_70 & V_71 ) )
return - V_72 ;
if ( V_4 -> V_31 )
return - V_72 ;
V_6 = F_54 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_13 ( V_2 , V_13 ) ;
F_38 ( & V_2 -> V_27 ) ;
if ( F_23 ( V_12 ) )
return F_24 ( V_12 ) ;
args -> V_73 = V_12 -> V_15 ;
F_17 ( L_4 , args -> V_73 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , void * V_33 ,
struct V_34 * V_35 )
{
struct V_74 * args = V_33 ;
struct V_18 * V_13 = V_35 -> V_36 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_69 -> V_70 & V_71 ) )
return - V_72 ;
V_6 = F_54 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_39 ( V_13 , args -> V_73 ) ;
if ( ! V_12 ) {
F_38 ( & V_2 -> V_27 ) ;
return - V_67 ;
}
F_9 ( V_12 ) ;
F_38 ( & V_2 -> V_27 ) ;
F_17 ( L_5 , args -> V_73 ) ;
return 0 ;
}
