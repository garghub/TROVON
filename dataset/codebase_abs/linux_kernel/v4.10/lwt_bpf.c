static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_3 ,
struct V_8 * V_9 , bool V_10 )
{
int V_11 ;
F_3 () ;
F_4 () ;
F_5 ( V_6 ) ;
V_11 = F_6 ( V_3 -> V_12 , V_6 ) ;
F_7 () ;
switch ( V_11 ) {
case V_13 :
break;
case V_14 :
if ( F_8 ( ! V_10 ) ) {
F_9 ( L_1 ,
V_3 -> V_15 ? : L_2 ) ;
V_11 = V_13 ;
} else {
V_11 = F_10 ( V_6 ) ;
if ( V_11 == 0 )
V_11 = V_14 ;
}
break;
case V_16 :
F_11 ( V_6 ) ;
V_11 = - V_17 ;
break;
default:
F_9 ( L_3 , V_11 ) ;
F_11 ( V_6 ) ;
V_11 = - V_18 ;
break;
}
F_12 () ;
return V_11 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
struct V_1 * V_19 ;
int V_11 ;
V_19 = F_1 ( V_9 -> V_20 ) ;
if ( V_19 -> V_21 . V_12 ) {
V_11 = F_2 ( V_6 , & V_19 -> V_21 , V_9 , V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( F_8 ( ! V_9 -> V_20 -> V_23 ) ) {
F_9 ( L_4 ,
V_19 -> V_24 . V_15 ) ;
F_11 ( V_6 ) ;
return - V_18 ;
}
return V_9 -> V_20 -> V_23 ( V_6 ) ;
}
static int F_15 ( struct V_25 * V_25 , struct V_26 * V_27 , struct V_5 * V_6 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
struct V_1 * V_19 ;
int V_11 ;
V_19 = F_1 ( V_9 -> V_20 ) ;
if ( V_19 -> V_24 . V_12 ) {
V_11 = F_2 ( V_6 , & V_19 -> V_24 , V_9 , V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( F_8 ( ! V_9 -> V_20 -> V_28 ) ) {
F_9 ( L_5 ,
V_19 -> V_24 . V_15 ) ;
F_11 ( V_6 ) ;
return - V_18 ;
}
return V_9 -> V_20 -> V_28 ( V_25 , V_27 , V_6 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
int V_29 = F_14 ( V_6 ) -> V_30 -> V_31 ;
if ( F_17 ( V_6 ) < V_29 ) {
int V_32 = F_18 ( V_29 - F_17 ( V_6 ) ) ;
if ( F_19 ( V_6 , V_32 , 0 , V_33 ) )
return - V_34 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
struct V_1 * V_19 ;
V_19 = F_1 ( V_9 -> V_20 ) ;
if ( V_19 -> V_35 . V_12 ) {
int V_11 ;
V_11 = F_2 ( V_6 , & V_19 -> V_35 , V_9 , V_36 ) ;
switch ( V_11 ) {
case V_13 :
V_11 = F_16 ( V_6 ) ;
if ( F_8 ( V_11 ) )
return V_11 ;
return V_37 ;
case V_14 :
return V_38 ;
default:
return V_11 ;
}
}
return V_37 ;
}
static void F_21 ( struct V_7 * V_12 )
{
if ( V_12 -> V_12 )
F_22 ( V_12 -> V_12 ) ;
F_23 ( V_12 -> V_15 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_21 ( & V_19 -> V_21 ) ;
F_21 ( & V_19 -> V_24 ) ;
F_21 ( & V_19 -> V_35 ) ;
}
static int F_25 ( struct V_39 * V_40 , struct V_7 * V_12 ,
enum V_41 type )
{
struct V_39 * V_42 [ V_43 + 1 ] ;
struct V_44 * V_45 ;
int V_11 ;
T_1 V_46 ;
V_11 = F_26 ( V_42 , V_43 , V_40 , V_47 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! V_42 [ V_48 ] || ! V_42 [ V_49 ] )
return - V_18 ;
V_12 -> V_15 = F_27 ( V_42 [ V_49 ] , V_50 ) ;
if ( ! V_12 -> V_15 )
return - V_34 ;
V_46 = F_28 ( V_42 [ V_48 ] ) ;
V_45 = F_29 ( V_46 , type ) ;
if ( F_30 ( V_45 ) )
return F_31 ( V_45 ) ;
V_12 -> V_12 = V_45 ;
return 0 ;
}
static int F_32 ( struct V_51 * V_30 , struct V_39 * V_52 ,
unsigned int V_53 , const void * V_54 ,
struct V_2 * * V_55 )
{
struct V_39 * V_42 [ V_56 + 1 ] ;
struct V_2 * V_57 ;
struct V_1 * V_19 ;
int V_11 ;
if ( V_53 != V_58 && V_53 != V_59 )
return - V_60 ;
V_11 = F_26 ( V_42 , V_56 , V_52 , V_61 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! V_42 [ V_62 ] && ! V_42 [ V_63 ] && ! V_42 [ V_64 ] )
return - V_18 ;
V_57 = F_33 ( sizeof( * V_19 ) ) ;
if ( ! V_57 )
return - V_34 ;
V_57 -> type = V_65 ;
V_19 = F_1 ( V_57 ) ;
if ( V_42 [ V_62 ] ) {
V_57 -> V_66 |= V_67 ;
V_11 = F_25 ( V_42 [ V_62 ] , & V_19 -> V_21 ,
V_68 ) ;
if ( V_11 < 0 )
goto V_69;
}
if ( V_42 [ V_63 ] ) {
V_57 -> V_66 |= V_70 ;
V_11 = F_25 ( V_42 [ V_63 ] , & V_19 -> V_24 ,
V_71 ) ;
if ( V_11 < 0 )
goto V_69;
}
if ( V_42 [ V_64 ] ) {
V_57 -> V_66 |= V_72 ;
V_11 = F_25 ( V_42 [ V_64 ] , & V_19 -> V_35 ,
V_73 ) ;
if ( V_11 < 0 )
goto V_69;
}
if ( V_42 [ V_74 ] ) {
T_1 V_75 = F_28 ( V_42 [ V_74 ] ) ;
if ( V_75 > V_76 ) {
V_11 = - V_77 ;
goto V_69;
}
V_57 -> V_75 = V_75 ;
}
V_19 -> V_53 = V_53 ;
* V_55 = V_57 ;
return 0 ;
V_69:
F_24 ( V_57 ) ;
F_23 ( V_57 ) ;
return V_11 ;
}
static int F_34 ( struct V_5 * V_6 , int V_40 ,
struct V_7 * V_12 )
{
struct V_39 * V_78 ;
if ( ! V_12 -> V_12 )
return 0 ;
V_78 = F_35 ( V_6 , V_40 ) ;
if ( ! V_78 )
return - V_79 ;
if ( V_12 -> V_15 &&
F_36 ( V_6 , V_49 , V_12 -> V_15 ) )
return - V_79 ;
return F_37 ( V_6 , V_78 ) ;
}
static int F_38 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( F_34 ( V_6 , V_62 , & V_19 -> V_21 ) < 0 ||
F_34 ( V_6 , V_63 , & V_19 -> V_24 ) < 0 ||
F_34 ( V_6 , V_64 , & V_19 -> V_35 ) < 0 )
return - V_79 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_20 )
{
int V_80 = F_40 ( sizeof( struct V_39 ) ) +
F_40 ( V_81 ) +
0 ;
return V_80 +
V_80 +
V_80 +
0 ;
}
int F_41 ( struct V_7 * V_82 , struct V_7 * V_83 )
{
if ( ! V_82 -> V_15 && ! V_83 -> V_15 )
return 0 ;
if ( ! V_82 -> V_15 || ! V_83 -> V_15 )
return 1 ;
return strcmp ( V_82 -> V_15 , V_83 -> V_15 ) ;
}
static int F_42 ( struct V_2 * V_82 , struct V_2 * V_83 )
{
struct V_1 * V_84 = F_1 ( V_82 ) ;
struct V_1 * V_85 = F_1 ( V_83 ) ;
return F_41 ( & V_84 -> V_21 , & V_85 -> V_21 ) ||
F_41 ( & V_84 -> V_24 , & V_85 -> V_24 ) ||
F_41 ( & V_84 -> V_35 , & V_85 -> V_35 ) ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_86 , V_65 ) ;
}
