T_1 F_1 ( const struct V_1 * V_1 ,
const struct V_2 * V_3 , const T_2 V_4 ,
const struct V_2 * V_5 , const T_3 V_6 )
{
static T_1 T_4 V_7 ;
static T_1 T_5 V_7 ;
T_1 V_8 , V_9 ;
F_2 ( & T_4 , sizeof( T_4 ) ) ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
V_8 = ( V_10 T_1 ) V_3 -> V_11 [ 3 ] ;
V_9 = F_3 ( V_5 , T_5 ) ;
return F_4 ( V_8 , V_4 , V_9 , V_6 ,
T_4 + F_5 ( V_1 ) ) ;
}
struct V_12 * F_6 ( struct V_1 * V_1 ,
struct V_13 * V_14 ,
const struct V_2 * V_15 ,
const T_3 V_16 ,
const struct V_2 * V_17 ,
const T_2 V_18 ,
const int V_19 )
{
struct V_12 * V_20 ;
const struct V_21 * V_22 ;
const T_6 V_23 = F_7 ( V_16 , V_18 ) ;
unsigned int V_24 = F_1 ( V_1 , V_17 , V_18 , V_15 , V_16 ) ;
unsigned int V_25 = V_24 & V_14 -> V_26 ;
struct V_27 * V_28 = & V_14 -> V_29 [ V_25 ] ;
V_30:
F_8 (sk, node, &head->chain) {
if ( V_20 -> V_31 != V_24 )
continue;
if ( ! F_9 ( V_20 , V_1 , V_15 , V_17 , V_23 , V_19 ) )
continue;
if ( F_10 ( ! F_11 ( & V_20 -> V_32 ) ) )
goto V_33;
if ( F_10 ( ! F_9 ( V_20 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
F_12 ( V_20 ) ;
goto V_30;
}
goto V_34;
}
if ( F_13 ( V_22 ) != V_25 )
goto V_30;
V_33:
V_20 = NULL ;
V_34:
return V_20 ;
}
static inline int F_14 ( struct V_12 * V_20 , struct V_1 * V_1 ,
const unsigned short V_18 ,
const struct V_2 * V_17 ,
const int V_19 )
{
int V_35 = - 1 ;
if ( F_15 ( F_16 ( V_20 ) , V_1 ) && F_17 ( V_20 ) -> V_36 == V_18 &&
V_20 -> V_37 == V_38 ) {
V_35 = 1 ;
if ( ! F_18 ( & V_20 -> V_39 ) ) {
if ( ! F_19 ( & V_20 -> V_39 , V_17 ) )
return - 1 ;
V_35 ++ ;
}
if ( V_20 -> V_40 ) {
if ( V_20 -> V_40 != V_19 )
return - 1 ;
V_35 ++ ;
}
if ( V_20 -> V_41 == F_20 () )
V_35 ++ ;
}
return V_35 ;
}
struct V_12 * F_21 ( struct V_1 * V_1 ,
struct V_13 * V_14 ,
struct V_42 * V_43 , int V_44 ,
const struct V_2 * V_15 ,
const T_3 V_16 , const struct V_2 * V_17 ,
const unsigned short V_18 , const int V_19 )
{
unsigned int V_24 = F_22 ( V_1 , V_18 ) ;
struct V_45 * V_46 = & V_14 -> V_47 [ V_24 ] ;
int V_35 , V_48 = 0 , V_49 = 0 , V_50 = 0 ;
struct V_12 * V_20 , * V_51 = NULL ;
T_1 V_52 = 0 ;
F_23 (sk, &ilb->head) {
V_35 = F_14 ( V_20 , V_1 , V_18 , V_17 , V_19 ) ;
if ( V_35 > V_48 ) {
V_50 = V_20 -> V_53 ;
if ( V_50 ) {
V_52 = F_1 ( V_1 , V_17 , V_18 ,
V_15 , V_16 ) ;
V_51 = F_24 ( V_20 , V_52 ,
V_43 , V_44 ) ;
if ( V_51 )
return V_51 ;
V_49 = 1 ;
}
V_51 = V_20 ;
V_48 = V_35 ;
} else if ( V_35 == V_48 && V_50 ) {
V_49 ++ ;
if ( F_25 ( V_52 , V_49 ) == 0 )
V_51 = V_20 ;
V_52 = F_26 ( V_52 ) ;
}
}
return V_51 ;
}
struct V_12 * F_27 ( struct V_1 * V_1 , struct V_13 * V_14 ,
struct V_42 * V_43 , int V_44 ,
const struct V_2 * V_15 , const T_3 V_16 ,
const struct V_2 * V_17 , const T_3 V_54 ,
const int V_19 )
{
struct V_12 * V_20 ;
bool V_55 ;
V_20 = F_28 ( V_1 , V_14 , V_43 , V_44 , V_15 , V_16 , V_17 ,
F_29 ( V_54 ) , V_19 , & V_55 ) ;
if ( V_20 && ! V_55 && ! F_11 ( & V_20 -> V_32 ) )
V_20 = NULL ;
return V_20 ;
}
static int F_30 ( struct V_56 * V_57 ,
struct V_12 * V_20 , const T_7 V_4 ,
struct V_58 * * V_59 )
{
struct V_13 * V_60 = V_57 -> V_14 ;
struct V_61 * V_62 = F_17 ( V_20 ) ;
const struct V_2 * V_17 = & V_20 -> V_39 ;
const struct V_2 * V_15 = & V_20 -> V_63 ;
const int V_19 = V_20 -> V_40 ;
const T_6 V_23 = F_7 ( V_62 -> V_64 , V_4 ) ;
struct V_1 * V_1 = F_16 ( V_20 ) ;
const unsigned int V_24 = F_1 ( V_1 , V_17 , V_4 , V_15 ,
V_62 -> V_64 ) ;
struct V_27 * V_28 = V_27 ( V_60 , V_24 ) ;
T_8 * V_65 = F_31 ( V_60 , V_24 ) ;
struct V_12 * V_66 ;
const struct V_21 * V_22 ;
struct V_58 * V_67 = NULL ;
F_32 ( V_65 ) ;
F_33 (sk2, node, &head->chain) {
if ( V_66 -> V_31 != V_24 )
continue;
if ( F_34 ( F_9 ( V_66 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
if ( V_66 -> V_68 == V_69 ) {
V_67 = F_35 ( V_66 ) ;
if ( F_36 ( V_20 , V_66 , V_59 ) )
break;
}
goto V_70;
}
}
V_62 -> V_36 = V_4 ;
V_62 -> V_71 = F_37 ( V_4 ) ;
V_20 -> V_31 = V_24 ;
F_38 ( ! F_39 ( V_20 ) ) ;
F_40 ( V_20 , & V_28 -> V_72 ) ;
if ( V_67 ) {
F_41 ( (struct V_12 * ) V_67 ) ;
F_42 ( V_1 , V_73 ) ;
}
F_43 ( V_65 ) ;
F_44 ( F_16 ( V_20 ) , V_20 -> V_74 , 1 ) ;
if ( V_59 ) {
* V_59 = V_67 ;
} else if ( V_67 ) {
F_45 ( V_67 ) ;
}
return 0 ;
V_70:
F_43 ( V_65 ) ;
return - V_75 ;
}
static T_1 F_46 ( const struct V_12 * V_20 )
{
const struct V_61 * V_62 = F_17 ( V_20 ) ;
return F_47 ( V_20 -> V_39 . V_11 ,
V_20 -> V_63 . V_11 ,
V_62 -> V_64 ) ;
}
int F_48 ( struct V_56 * V_57 ,
struct V_12 * V_20 )
{
T_1 V_76 = 0 ;
if ( ! F_17 ( V_20 ) -> V_36 )
V_76 = F_46 ( V_20 ) ;
return F_49 ( V_57 , V_20 , V_76 ,
F_30 ) ;
}
int F_50 ( struct V_12 * V_20 )
{
if ( V_20 -> V_68 != V_77 ) {
F_51 () ;
F_52 ( V_20 , NULL , V_78 ) ;
F_53 () ;
}
return 0 ;
}
int V_78 ( const struct V_12 * V_20 , const struct V_12 * V_66 ,
bool V_79 )
{
const struct V_2 * V_80 = F_54 ( V_66 ) ;
int V_81 = F_55 ( V_66 ) ;
int V_82 = F_56 ( & V_20 -> V_39 ) ;
int V_83 = V_80 ? F_56 ( V_80 ) : V_84 ;
if ( V_82 == V_84 && V_83 == V_84 ) {
if ( ! V_81 ) {
if ( V_20 -> V_85 == V_66 -> V_85 )
return 1 ;
if ( ! V_20 -> V_85 || ! V_66 -> V_85 )
return V_79 ;
}
return 0 ;
}
if ( V_82 == V_86 && V_83 == V_86 )
return 1 ;
if ( V_83 == V_86 && V_79 &&
! ( V_81 && V_82 == V_84 ) )
return 1 ;
if ( V_82 == V_86 && V_79 &&
! ( F_57 ( V_20 ) && V_83 == V_84 ) )
return 1 ;
if ( V_80 &&
F_19 ( & V_20 -> V_39 , V_80 ) )
return 1 ;
return 0 ;
}
