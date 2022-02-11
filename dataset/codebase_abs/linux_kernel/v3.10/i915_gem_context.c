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
if ( F_2 ( V_2 ) -> V_8 >= 7 ) {
V_6 = F_18 ( V_12 -> V_16 ,
V_22 ) ;
if ( V_6 )
goto V_23;
}
V_12 -> V_24 = & V_4 -> V_24 [ V_25 ] ;
if ( V_13 == NULL )
return V_12 ;
V_12 -> V_13 = V_13 ;
V_6 = F_19 ( & V_13 -> V_14 , V_12 , V_26 + 1 , 0 ,
V_19 ) ;
if ( V_6 < 0 )
goto V_23;
V_12 -> V_15 = V_6 ;
return V_12 ;
V_23:
F_9 ( V_12 ) ;
return F_15 ( V_6 ) ;
}
static inline bool F_20 ( struct V_11 * V_12 )
{
return ( V_12 == V_12 -> V_24 -> V_27 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_6 ;
F_22 ( ! F_23 ( & V_4 -> V_2 -> V_28 ) ) ;
V_12 = F_13 ( V_4 -> V_2 , NULL ) ;
if ( F_24 ( V_12 ) )
return F_25 ( V_12 ) ;
V_4 -> V_24 [ V_25 ] . V_27 = V_12 ;
V_6 = F_26 ( V_12 -> V_16 , V_29 , false , false ) ;
if ( V_6 )
goto V_30;
V_6 = F_27 ( V_12 ) ;
if ( V_6 )
goto V_31;
F_17 ( L_2 ) ;
return 0 ;
V_31:
F_28 ( V_12 -> V_16 ) ;
V_30:
F_9 ( V_12 ) ;
return V_6 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_30 ( V_2 ) ) {
V_4 -> V_32 = true ;
return;
}
if ( V_4 -> V_32 ||
V_4 -> V_24 [ V_25 ] . V_27 )
return;
V_4 -> V_21 = F_31 ( F_1 ( V_2 ) , 4096 ) ;
if ( V_4 -> V_21 > ( 1 << 20 ) ) {
V_4 -> V_32 = true ;
return;
}
if ( F_21 ( V_4 ) ) {
V_4 -> V_32 = true ;
return;
}
F_17 ( L_3 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_32 )
return;
F_33 ( V_2 ) ;
F_28 ( V_4 -> V_24 [ V_25 ] . V_27 -> V_16 ) ;
F_9 ( V_4 -> V_24 [ V_25 ] . V_27 ) ;
}
static int F_34 ( int V_15 , void * V_33 , void * V_34 )
{
struct V_11 * V_12 = V_33 ;
F_22 ( V_15 == V_26 ) ;
F_9 ( V_12 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_18 * V_13 = V_36 -> V_37 ;
F_36 ( & V_2 -> V_28 ) ;
F_37 ( & V_13 -> V_14 , F_34 , NULL ) ;
F_38 ( & V_13 -> V_14 ) ;
F_39 ( & V_2 -> V_28 ) ;
}
static struct V_11 *
F_40 ( struct V_18 * V_13 , T_1 V_15 )
{
return (struct V_11 * ) F_41 ( & V_13 -> V_14 , V_15 ) ;
}
static inline int
F_42 ( struct V_38 * V_24 ,
struct V_11 * V_39 ,
T_1 V_40 )
{
int V_6 ;
if ( F_43 ( V_24 -> V_2 ) && V_24 -> V_41 ) {
V_6 = V_24 -> V_42 ( V_24 , V_43 , 0 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_44 ( V_24 , 6 ) ;
if ( V_6 )
return V_6 ;
if ( F_45 ( V_24 -> V_2 ) )
F_46 ( V_24 , V_44 | V_45 ) ;
else
F_46 ( V_24 , V_46 ) ;
F_46 ( V_24 , V_46 ) ;
F_46 ( V_24 , V_47 ) ;
F_46 ( V_24 , V_39 -> V_16 -> V_48 |
V_49 |
V_50 |
V_51 |
V_40 ) ;
F_46 ( V_24 , V_46 ) ;
if ( F_45 ( V_24 -> V_2 ) )
F_46 ( V_24 , V_44 | V_52 ) ;
else
F_46 ( V_24 , V_46 ) ;
F_47 ( V_24 ) ;
return V_6 ;
}
static int F_27 ( struct V_11 * V_53 )
{
struct V_38 * V_24 = V_53 -> V_24 ;
struct V_54 * V_55 = V_24 -> V_56 ;
T_1 V_40 = 0 ;
int V_6 ;
F_22 ( V_55 != NULL && V_55 -> V_57 == 0 ) ;
if ( V_55 == V_53 -> V_16 )
return 0 ;
V_6 = F_26 ( V_53 -> V_16 , V_29 , false , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_48 ( V_53 -> V_16 , false ) ;
if ( V_6 ) {
F_28 ( V_53 -> V_16 ) ;
return V_6 ;
}
if ( ! V_53 -> V_16 -> V_58 )
F_49 ( V_53 -> V_16 , V_53 -> V_16 -> V_59 ) ;
if ( ! V_53 -> V_60 || F_20 ( V_53 ) )
V_40 |= V_61 ;
else if ( F_50 ( V_55 == V_53 -> V_16 ) )
V_40 |= V_62 ;
V_6 = F_42 ( V_24 , V_53 , V_40 ) ;
if ( V_6 ) {
F_28 ( V_53 -> V_16 ) ;
return V_6 ;
}
if ( V_55 != NULL ) {
V_55 -> V_17 . V_63 = V_64 ;
F_51 ( V_55 , V_24 ) ;
V_55 -> V_65 = 1 ;
F_22 ( V_55 -> V_24 != V_24 ) ;
F_28 ( V_55 ) ;
F_11 ( & V_55 -> V_17 ) ;
}
F_52 ( & V_53 -> V_16 -> V_17 ) ;
V_24 -> V_56 = V_53 -> V_16 ;
V_53 -> V_60 = true ;
return 0 ;
}
int F_53 ( struct V_38 * V_24 ,
struct V_35 * V_36 ,
int V_66 )
{
struct V_3 * V_4 = V_24 -> V_2 -> V_5 ;
struct V_11 * V_53 ;
if ( V_4 -> V_32 )
return 0 ;
if ( V_24 != & V_4 -> V_24 [ V_25 ] )
return 0 ;
if ( V_66 == V_26 ) {
V_53 = V_24 -> V_27 ;
} else {
if ( V_36 == NULL )
return - V_67 ;
V_53 = F_40 ( V_36 -> V_37 , V_66 ) ;
if ( V_53 == NULL )
return - V_68 ;
}
return F_27 ( V_53 ) ;
}
int F_54 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_69 * args = V_34 ;
struct V_18 * V_13 = V_36 -> V_37 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_70 -> V_71 & V_72 ) )
return - V_73 ;
if ( V_4 -> V_32 )
return - V_73 ;
V_6 = F_55 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_13 ( V_2 , V_13 ) ;
F_39 ( & V_2 -> V_28 ) ;
if ( F_24 ( V_12 ) )
return F_25 ( V_12 ) ;
args -> V_74 = V_12 -> V_15 ;
F_17 ( L_4 , args -> V_74 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_75 * args = V_34 ;
struct V_18 * V_13 = V_36 -> V_37 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_70 -> V_71 & V_72 ) )
return - V_73 ;
V_6 = F_55 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_40 ( V_13 , args -> V_74 ) ;
if ( ! V_12 ) {
F_39 ( & V_2 -> V_28 ) ;
return - V_68 ;
}
F_9 ( V_12 ) ;
F_39 ( & V_2 -> V_28 ) ;
F_17 ( L_5 , args -> V_74 ) ;
return 0 ;
}
