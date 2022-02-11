static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
F_4 ( & V_4 ) ;
F_5 ( V_3 , & V_5 ) ;
F_6 ( F_7 ( V_3 ) , V_3 -> V_6 , 1 ) ;
F_8 ( & V_4 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_4 ( & V_4 ) ;
if ( F_10 ( V_3 ) )
F_6 ( F_7 ( V_3 ) , V_3 -> V_6 , - 1 ) ;
F_8 ( & V_4 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_8 . V_9 = V_10 ;
V_7 -> V_8 . V_11 = F_12 ( V_12 ) ;
V_7 -> V_13 = 1 ;
memset ( & V_7 -> V_8 . V_14 , 0xff , V_15 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , long V_16 )
{
F_14 ( V_3 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_18 ;
struct V_22 V_23 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_24 = - V_25 ;
struct V_26 * V_27 ;
F_16 ( V_3 ) ;
V_7 -> V_28 = 0 ;
if ( V_19 < sizeof( * V_21 ) )
goto V_29;
if ( V_21 -> V_30 != V_31 )
goto V_29;
F_17 ( & V_23 , & V_21 -> V_21 ) ;
V_27 = F_18 ( F_7 ( V_3 ) , & V_23 ) ;
if ( ! V_27 ) {
V_24 = - V_32 ;
goto V_29;
}
if ( V_27 -> type != V_33 ) {
V_24 = - V_32 ;
goto V_34;
}
V_7 -> V_35 = V_23 ;
V_7 -> V_28 = 1 ;
V_24 = 0 ;
V_34:
F_19 ( V_27 ) ;
V_29:
F_20 ( V_3 ) ;
return V_24 ;
}
static int F_21 ( struct V_2 * V_3 , int V_36 , unsigned long V_37 )
{
switch ( V_36 ) {
case V_38 :
{
int V_39 = F_22 ( V_3 ) ;
return F_23 ( V_39 , ( int V_40 * ) V_37 ) ;
}
case V_41 :
{
struct V_42 * V_43 ;
unsigned long V_39 ;
V_39 = 0 ;
F_24 ( & V_3 -> V_44 . V_45 ) ;
V_43 = F_25 ( & V_3 -> V_44 ) ;
if ( V_43 != NULL ) {
V_39 = V_43 -> V_19 - F_26 ( V_43 ) ;
}
F_27 ( & V_3 -> V_44 . V_45 ) ;
return F_23 ( V_39 , ( int V_40 * ) V_37 ) ;
}
}
return - V_46 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_17 * V_18 ,
int V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_18 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_24 = 0 ;
if ( V_19 < sizeof( * V_21 ) )
return - V_25 ;
if ( V_21 -> V_30 != V_31 )
return - V_25 ;
F_16 ( V_3 ) ;
if ( ! V_7 -> V_28 ) {
V_24 = - V_47 ;
goto V_29;
}
F_17 ( & V_7 -> V_8 , & V_21 -> V_21 ) ;
V_29:
F_20 ( V_3 ) ;
return V_24 ;
}
static int F_29 ( struct V_2 * V_3 , int V_48 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_16 ( V_3 ) ;
V_7 -> V_8 . V_9 = V_10 ;
memset ( & V_7 -> V_8 . V_14 , 0xff , V_15 ) ;
F_20 ( V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_49 * V_50 , struct V_2 * V_3 ,
struct V_51 * V_52 , T_1 V_53 )
{
struct V_26 * V_27 ;
unsigned int V_54 ;
struct V_42 * V_43 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_55 , V_56 ;
int V_24 ;
if ( V_52 -> V_57 & V_58 ) {
F_31 ( L_1 , V_52 -> V_57 ) ;
return - V_59 ;
}
if ( ! V_7 -> V_28 )
V_27 = F_32 ( F_7 ( V_3 ) , V_33 ) ;
else
V_27 = F_18 ( F_7 ( V_3 ) , & V_7 -> V_35 ) ;
if ( ! V_27 ) {
F_31 ( L_2 ) ;
V_24 = - V_60 ;
goto V_29;
}
V_54 = V_27 -> V_54 ;
F_31 ( L_3 , V_27 -> V_61 , V_54 ) ;
if ( V_53 > V_54 ) {
F_31 ( L_4 , V_53 , V_54 ) ;
V_24 = - V_62 ;
goto V_63;
}
V_55 = F_33 ( V_27 ) ;
V_56 = V_27 -> V_64 ;
V_43 = F_34 ( V_3 , V_55 + V_56 + V_53 ,
V_52 -> V_57 & V_65 ,
& V_24 ) ;
if ( ! V_43 )
goto V_63;
F_35 ( V_43 , V_55 ) ;
F_36 ( V_43 ) ;
F_37 ( V_43 ) -> V_48 = V_66 ;
if ( V_7 -> V_13 )
F_37 ( V_43 ) -> V_48 |= V_67 ;
F_37 ( V_43 ) -> V_68 = F_38 ( V_27 ) -> F_39 ( V_27 ) ;
V_24 = F_40 ( V_43 , V_27 , V_69 , & V_7 -> V_8 ,
V_7 -> V_28 ? & V_7 -> V_35 : NULL , V_53 ) ;
if ( V_24 < 0 )
goto V_70;
F_41 ( V_43 ) ;
V_24 = F_42 ( F_43 ( V_43 , V_53 ) , V_52 -> V_71 , V_53 ) ;
if ( V_24 < 0 )
goto V_70;
V_43 -> V_27 = V_27 ;
V_43 -> V_3 = V_3 ;
V_43 -> V_72 = F_44 ( V_69 ) ;
F_19 ( V_27 ) ;
V_24 = F_45 ( V_43 ) ;
if ( V_24 > 0 )
V_24 = F_46 ( V_24 ) ;
return V_24 ? : V_53 ;
V_70:
F_47 ( V_43 ) ;
V_63:
F_19 ( V_27 ) ;
V_29:
return V_24 ;
}
static int F_48 ( struct V_49 * V_50 , struct V_2 * V_3 ,
struct V_51 * V_52 , T_1 V_19 , int V_73 , int V_48 ,
int * V_74 )
{
T_1 V_75 = 0 ;
int V_24 = - V_59 ;
struct V_42 * V_43 ;
F_49 ( struct V_20 * , V_76 , V_52 -> V_77 ) ;
V_43 = F_50 ( V_3 , V_48 , V_73 , & V_24 ) ;
if ( ! V_43 )
goto V_29;
V_75 = V_43 -> V_19 ;
if ( V_19 < V_75 ) {
V_52 -> V_57 |= V_78 ;
V_75 = V_19 ;
}
V_24 = F_51 ( V_43 , 0 , V_52 -> V_71 , V_75 ) ;
if ( V_24 )
goto V_79;
F_52 ( V_52 , V_3 , V_43 ) ;
if ( V_76 ) {
V_76 -> V_30 = V_31 ;
F_53 ( & V_76 -> V_21 , & F_37 ( V_43 ) -> V_80 ) ;
* V_74 = sizeof( * V_76 ) ;
}
if ( V_48 & V_78 )
V_75 = V_43 -> V_19 ;
V_79:
F_54 ( V_3 , V_43 ) ;
V_29:
if ( V_24 )
return V_24 ;
return V_75 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
V_43 = F_56 ( V_43 , V_81 ) ;
if ( ! V_43 )
return V_82 ;
if ( F_57 ( V_3 , V_43 ) < 0 ) {
F_47 ( V_43 ) ;
return V_82 ;
}
return V_83 ;
}
static inline bool
F_58 ( T_2 V_84 , T_3 V_11 , T_3 V_85 ,
struct V_1 * V_7 )
{
if ( ! V_7 -> V_28 )
return true ;
if ( V_7 -> V_35 . V_9 == V_10 &&
V_84 == V_7 -> V_35 . V_14 )
return true ;
if ( V_7 -> V_35 . V_9 == V_86 &&
V_11 == V_7 -> V_35 . V_11 &&
V_85 == V_7 -> V_35 . V_85 )
return true ;
return false ;
}
int F_59 ( struct V_26 * V_27 , struct V_42 * V_43 )
{
struct V_2 * V_3 , * V_87 = NULL ;
int V_88 = V_83 ;
T_3 V_11 , V_85 ;
T_2 V_84 ;
F_60 ( V_27 -> type != V_33 ) ;
V_11 = F_38 ( V_27 ) -> F_61 ( V_27 ) ;
V_85 = F_38 ( V_27 ) -> F_62 ( V_27 ) ;
V_84 = F_63 ( V_27 -> V_89 ) ;
F_64 ( & V_4 ) ;
F_65 (sk, &dgram_head) {
if ( F_58 ( V_84 , V_11 , V_85 ,
F_1 ( V_3 ) ) ) {
if ( V_87 ) {
struct V_42 * V_90 ;
V_90 = F_66 ( V_43 , V_81 ) ;
if ( V_90 )
F_55 ( V_87 , V_90 ) ;
}
V_87 = V_3 ;
}
}
if ( V_87 )
F_55 ( V_87 , V_43 ) ;
else {
F_47 ( V_43 ) ;
V_88 = V_82 ;
}
F_67 ( & V_4 ) ;
return V_88 ;
}
static int F_68 ( struct V_2 * V_3 , int V_91 , int V_92 ,
char V_40 * V_93 , int V_40 * V_94 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_95 , V_19 ;
if ( V_91 != V_96 )
return - V_59 ;
if ( F_69 ( V_19 , V_94 ) )
return - V_97 ;
V_19 = F_70 (unsigned int, len, sizeof(int)) ;
switch ( V_92 ) {
case V_98 :
V_95 = V_7 -> V_13 ;
break;
default:
return - V_99 ;
}
if ( F_23 ( V_19 , V_94 ) )
return - V_97 ;
if ( F_71 ( V_93 , & V_95 , V_19 ) )
return - V_97 ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 , int V_91 , int V_92 ,
char V_40 * V_93 , unsigned int V_94 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_95 ;
int V_24 = 0 ;
if ( V_94 < sizeof( int ) )
return - V_25 ;
if ( F_69 ( V_95 , ( int V_40 * ) V_93 ) )
return - V_97 ;
F_16 ( V_3 ) ;
switch ( V_92 ) {
case V_98 :
V_7 -> V_13 = ! ! V_95 ;
break;
default:
V_24 = - V_99 ;
break;
}
F_20 ( V_3 ) ;
return V_24 ;
}
