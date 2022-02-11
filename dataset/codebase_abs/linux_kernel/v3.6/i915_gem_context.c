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
V_6 = F_5 ( V_7 ) * 64 ;
break;
default:
F_6 () ;
}
return V_6 ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 -> V_14 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_12 -> V_15 )
F_8 ( & V_12 -> V_15 -> V_16 , V_12 -> V_17 ) ;
else
F_9 ( V_12 != V_4 -> V_18 [ V_19 ] . V_20 ) ;
F_10 ( & V_12 -> V_13 -> V_14 ) ;
F_11 ( V_12 ) ;
}
static struct V_11 *
F_12 ( struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_6 , V_17 ;
V_12 = F_13 ( sizeof( struct V_21 ) , V_22 ) ;
if ( V_12 == NULL )
return F_14 ( - V_23 ) ;
V_12 -> V_13 = F_15 ( V_2 , V_4 -> V_24 ) ;
if ( V_12 -> V_13 == NULL ) {
F_11 ( V_12 ) ;
F_16 ( L_1 ) ;
return F_14 ( - V_23 ) ;
}
V_12 -> V_18 = & V_4 -> V_18 [ V_19 ] ;
if ( V_15 == NULL )
return V_12 ;
V_12 -> V_15 = V_15 ;
V_25:
if ( F_17 ( & V_15 -> V_16 , V_22 ) == 0 ) {
V_6 = - V_23 ;
F_16 ( L_2 ) ;
goto V_26;
}
V_6 = F_18 ( & V_15 -> V_16 , V_12 ,
V_27 + 1 , & V_17 ) ;
if ( V_6 == 0 )
V_12 -> V_17 = V_17 ;
if ( V_6 == - V_28 )
goto V_25;
else if ( V_6 )
goto V_26;
return V_12 ;
V_26:
F_7 ( V_12 ) ;
return F_14 ( V_6 ) ;
}
static inline bool F_19 ( struct V_11 * V_12 )
{
return ( V_12 == V_12 -> V_18 -> V_20 ) ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_6 ;
F_9 ( ! F_21 ( & V_4 -> V_2 -> V_29 ) ) ;
V_12 = F_12 ( V_4 -> V_2 , NULL ) ;
if ( F_22 ( V_12 ) )
return F_23 ( V_12 ) ;
V_4 -> V_18 [ V_19 ] . V_20 = V_12 ;
V_6 = F_24 ( V_12 -> V_13 , V_30 , false ) ;
if ( V_6 ) {
F_7 ( V_12 ) ;
return V_6 ;
}
V_6 = F_25 ( NULL , V_12 , 0 ) ;
if ( V_6 ) {
F_26 ( V_12 -> V_13 ) ;
F_7 ( V_12 ) ;
} else {
F_16 ( L_3 ) ;
}
return V_6 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_31 ;
if ( ! F_28 ( V_2 ) ) {
V_4 -> V_32 = true ;
return;
}
if ( V_4 -> V_32 ||
V_4 -> V_18 [ V_19 ] . V_20 )
return;
V_31 = F_1 ( V_2 ) ;
V_4 -> V_24 = F_1 ( V_2 ) ;
V_4 -> V_24 = F_29 ( V_4 -> V_24 , 4096 ) ;
if ( V_31 <= 0 || V_31 > ( 1 << 20 ) ) {
V_4 -> V_32 = true ;
return;
}
if ( F_20 ( V_4 ) ) {
V_4 -> V_32 = true ;
return;
}
F_16 ( L_4 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_32 )
return;
F_31 ( V_2 ) ;
F_26 ( V_4 -> V_18 [ V_19 ] . V_20 -> V_13 ) ;
F_7 ( V_4 -> V_18 [ V_19 ] . V_20 ) ;
}
static int F_32 ( int V_17 , void * V_33 , void * V_34 )
{
struct V_11 * V_12 = V_33 ;
F_9 ( V_17 == V_27 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_21 * V_15 = V_36 -> V_37 ;
F_34 ( & V_2 -> V_29 ) ;
F_35 ( & V_15 -> V_16 , F_32 , NULL ) ;
F_36 ( & V_15 -> V_16 ) ;
F_37 ( & V_2 -> V_29 ) ;
}
static struct V_11 *
F_38 ( struct V_21 * V_15 , T_1 V_17 )
{
return (struct V_11 * ) F_39 ( & V_15 -> V_16 , V_17 ) ;
}
static inline int
F_40 ( struct V_38 * V_18 ,
struct V_11 * V_39 ,
T_1 V_40 )
{
int V_6 ;
if ( F_41 ( V_18 -> V_2 ) && V_18 -> V_41 ) {
V_6 = V_18 -> V_42 ( V_18 , 0 , 0 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_42 ( V_18 , 6 ) ;
if ( V_6 )
return V_6 ;
if ( F_43 ( V_18 -> V_2 ) )
F_44 ( V_18 , V_43 | V_44 ) ;
else
F_44 ( V_18 , V_45 ) ;
F_44 ( V_18 , V_45 ) ;
F_44 ( V_18 , V_46 ) ;
F_44 ( V_18 , V_39 -> V_13 -> V_47 |
V_48 |
V_49 |
V_50 |
V_40 ) ;
F_44 ( V_18 , V_45 ) ;
if ( F_43 ( V_18 -> V_2 ) )
F_44 ( V_18 , V_43 | V_51 ) ;
else
F_44 ( V_18 , V_45 ) ;
F_45 ( V_18 ) ;
return V_6 ;
}
static int F_25 ( struct V_52 * V_53 ,
struct V_11 * V_54 ,
T_1 V_55 )
{
struct V_38 * V_18 = NULL ;
T_1 V_40 = 0 ;
int V_6 ;
F_9 ( V_54 == NULL ) ;
F_9 ( V_53 != NULL && V_53 -> V_56 == 0 ) ;
V_6 = F_24 ( V_54 -> V_13 , V_30 , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_46 ( V_54 -> V_13 , false ) ;
if ( V_6 ) {
F_26 ( V_54 -> V_13 ) ;
return V_6 ;
}
if ( ! V_54 -> V_13 -> V_57 )
F_47 ( V_54 -> V_13 , V_54 -> V_13 -> V_58 ) ;
if ( ! V_54 -> V_59 || F_19 ( V_54 ) )
V_40 |= V_60 ;
else if ( F_48 ( V_53 == V_54 -> V_13 ) )
V_40 |= V_61 ;
V_18 = V_54 -> V_18 ;
V_6 = F_40 ( V_18 , V_54 , V_40 ) ;
if ( V_6 ) {
F_26 ( V_54 -> V_13 ) ;
return V_6 ;
}
if ( V_53 != NULL ) {
V_53 -> V_14 . V_62 = V_63 ;
F_49 ( V_53 , V_18 , V_55 ) ;
V_53 -> V_64 = 1 ;
F_9 ( V_53 -> V_18 != V_54 -> V_18 ) ;
F_26 ( V_53 ) ;
F_10 ( & V_53 -> V_14 ) ;
}
F_50 ( & V_54 -> V_13 -> V_14 ) ;
V_18 -> V_65 = V_54 -> V_13 ;
V_54 -> V_59 = true ;
return 0 ;
}
int F_51 ( struct V_38 * V_18 ,
struct V_35 * V_36 ,
int V_66 )
{
struct V_3 * V_4 = V_18 -> V_2 -> V_5 ;
struct V_21 * V_15 = NULL ;
struct V_11 * V_54 ;
struct V_52 * V_53 = V_18 -> V_65 ;
if ( V_4 -> V_32 )
return 0 ;
if ( V_18 != & V_4 -> V_18 [ V_19 ] )
return 0 ;
if ( V_36 )
V_15 = V_36 -> V_37 ;
if ( V_66 == V_27 ) {
V_54 = V_18 -> V_20 ;
} else {
V_54 = F_38 ( V_15 , V_66 ) ;
if ( V_54 == NULL )
return - V_67 ;
}
if ( V_53 == V_54 -> V_13 )
return 0 ;
return F_25 ( V_53 , V_54 , F_52 ( V_54 -> V_18 ) ) ;
}
int F_53 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_68 * args = V_34 ;
struct V_21 * V_15 = V_36 -> V_37 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_69 -> V_70 & V_71 ) )
return - V_72 ;
if ( V_4 -> V_32 )
return - V_72 ;
V_6 = F_54 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_12 ( V_2 , V_15 ) ;
F_37 ( & V_2 -> V_29 ) ;
if ( F_22 ( V_12 ) )
return F_23 ( V_12 ) ;
args -> V_73 = V_12 -> V_17 ;
F_16 ( L_5 , args -> V_73 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_74 * args = V_34 ;
struct V_21 * V_15 = V_36 -> V_37 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_2 -> V_69 -> V_70 & V_71 ) )
return - V_72 ;
V_6 = F_54 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_38 ( V_15 , args -> V_73 ) ;
if ( ! V_12 ) {
F_37 ( & V_2 -> V_29 ) ;
return - V_67 ;
}
F_7 ( V_12 ) ;
F_37 ( & V_2 -> V_29 ) ;
F_16 ( L_6 , args -> V_73 ) ;
return 0 ;
}
