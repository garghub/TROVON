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
F_8 () ;
V_30:
F_9 (sk, node, &head->chain) {
if ( V_20 -> V_31 != V_24 )
continue;
if ( ! F_10 ( V_20 , V_1 , V_15 , V_17 , V_23 , V_19 ) )
continue;
if ( F_11 ( ! F_12 ( & V_20 -> V_32 ) ) )
goto V_33;
if ( F_11 ( ! F_10 ( V_20 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
F_13 ( V_20 ) ;
goto V_30;
}
goto V_34;
}
if ( F_14 ( V_22 ) != V_25 )
goto V_30;
V_33:
V_20 = NULL ;
V_34:
F_15 () ;
return V_20 ;
}
static inline int F_16 ( struct V_12 * V_20 , struct V_1 * V_1 ,
const unsigned short V_18 ,
const struct V_2 * V_17 ,
const int V_19 )
{
int V_35 = - 1 ;
if ( F_17 ( F_18 ( V_20 ) , V_1 ) && F_19 ( V_20 ) -> V_36 == V_18 &&
V_20 -> V_37 == V_38 ) {
V_35 = 1 ;
if ( ! F_20 ( & V_20 -> V_39 ) ) {
if ( ! F_21 ( & V_20 -> V_39 , V_17 ) )
return - 1 ;
V_35 ++ ;
}
if ( V_20 -> V_40 ) {
if ( V_20 -> V_40 != V_19 )
return - 1 ;
V_35 ++ ;
}
if ( V_20 -> V_41 == F_22 () )
V_35 ++ ;
}
return V_35 ;
}
struct V_12 * F_23 ( struct V_1 * V_1 ,
struct V_13 * V_14 ,
struct V_42 * V_43 , int V_44 ,
const struct V_2 * V_15 ,
const T_3 V_16 , const struct V_2 * V_17 ,
const unsigned short V_18 , const int V_19 )
{
struct V_12 * V_20 ;
const struct V_21 * V_22 ;
struct V_12 * V_45 ;
int V_35 , V_46 , V_47 = 0 , V_48 = 0 ;
bool V_49 = true ;
T_1 V_50 = 0 ;
unsigned int V_24 = F_24 ( V_1 , V_18 ) ;
struct V_51 * V_52 = & V_14 -> V_53 [ V_24 ] ;
F_8 () ;
V_30:
V_45 = NULL ;
V_46 = 0 ;
F_25 (sk, node, &ilb->head) {
V_35 = F_16 ( V_20 , V_1 , V_18 , V_17 , V_19 ) ;
if ( V_35 > V_46 ) {
V_46 = V_35 ;
V_45 = V_20 ;
V_48 = V_20 -> V_54 ;
if ( V_48 ) {
V_50 = F_1 ( V_1 , V_17 , V_18 ,
V_15 , V_16 ) ;
if ( V_49 ) {
struct V_12 * V_55 ;
V_55 = F_26 ( V_20 , V_50 ,
V_43 , V_44 ) ;
if ( V_55 ) {
V_45 = V_55 ;
goto V_34;
}
}
V_47 = 1 ;
}
} else if ( V_35 == V_46 && V_48 ) {
V_47 ++ ;
if ( F_27 ( V_50 , V_47 ) == 0 )
V_45 = V_20 ;
V_50 = F_28 ( V_50 ) ;
}
}
if ( F_14 ( V_22 ) != V_24 + V_56 )
goto V_30;
if ( V_45 ) {
V_34:
if ( F_11 ( ! F_12 ( & V_45 -> V_32 ) ) )
V_45 = NULL ;
else if ( F_11 ( F_16 ( V_45 , V_1 , V_18 , V_17 ,
V_19 ) < V_46 ) ) {
F_29 ( V_45 ) ;
V_49 = false ;
goto V_30;
}
}
F_15 () ;
return V_45 ;
}
struct V_12 * F_30 ( struct V_1 * V_1 , struct V_13 * V_14 ,
struct V_42 * V_43 , int V_44 ,
const struct V_2 * V_15 , const T_3 V_16 ,
const struct V_2 * V_17 , const T_3 V_57 ,
const int V_19 )
{
struct V_12 * V_20 ;
F_31 () ;
V_20 = F_32 ( V_1 , V_14 , V_43 , V_44 , V_15 , V_16 , V_17 ,
F_33 ( V_57 ) , V_19 ) ;
F_34 () ;
return V_20 ;
}
static int F_35 ( struct V_58 * V_59 ,
struct V_12 * V_20 , const T_7 V_4 ,
struct V_60 * * V_61 )
{
struct V_13 * V_62 = V_59 -> V_14 ;
struct V_63 * V_64 = F_19 ( V_20 ) ;
const struct V_2 * V_17 = & V_20 -> V_39 ;
const struct V_2 * V_15 = & V_20 -> V_65 ;
const int V_19 = V_20 -> V_40 ;
const T_6 V_23 = F_7 ( V_64 -> V_66 , V_4 ) ;
struct V_1 * V_1 = F_18 ( V_20 ) ;
const unsigned int V_24 = F_1 ( V_1 , V_17 , V_4 , V_15 ,
V_64 -> V_66 ) ;
struct V_27 * V_28 = V_27 ( V_62 , V_24 ) ;
T_8 * V_67 = F_36 ( V_62 , V_24 ) ;
struct V_12 * V_55 ;
const struct V_21 * V_22 ;
struct V_60 * V_68 = NULL ;
F_37 ( V_67 ) ;
F_25 (sk2, node, &head->chain) {
if ( V_55 -> V_31 != V_24 )
continue;
if ( F_38 ( F_10 ( V_55 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
if ( V_55 -> V_69 == V_70 ) {
V_68 = F_39 ( V_55 ) ;
if ( F_40 ( V_20 , V_55 , V_61 ) )
break;
}
goto V_71;
}
}
V_64 -> V_36 = V_4 ;
V_64 -> V_72 = F_41 ( V_4 ) ;
V_20 -> V_31 = V_24 ;
F_42 ( ! F_43 ( V_20 ) ) ;
F_44 ( V_20 , & V_28 -> V_73 ) ;
if ( V_68 ) {
F_45 ( (struct V_12 * ) V_68 ) ;
F_46 ( V_1 , V_74 ) ;
}
F_47 ( V_67 ) ;
F_48 ( F_18 ( V_20 ) , V_20 -> V_75 , 1 ) ;
if ( V_61 ) {
* V_61 = V_68 ;
} else if ( V_68 ) {
F_49 ( V_68 ) ;
}
return 0 ;
V_71:
F_47 ( V_67 ) ;
return - V_76 ;
}
static T_1 F_50 ( const struct V_12 * V_20 )
{
const struct V_63 * V_64 = F_19 ( V_20 ) ;
return F_51 ( V_20 -> V_39 . V_11 ,
V_20 -> V_65 . V_11 ,
V_64 -> V_66 ) ;
}
int F_52 ( struct V_58 * V_59 ,
struct V_12 * V_20 )
{
T_1 V_77 = 0 ;
if ( ! F_19 ( V_20 ) -> V_36 )
V_77 = F_50 ( V_20 ) ;
return F_53 ( V_59 , V_20 , V_77 ,
F_35 ) ;
}
int F_54 ( struct V_12 * V_20 )
{
if ( V_20 -> V_69 != V_78 ) {
F_31 () ;
F_55 ( V_20 , NULL , V_79 ) ;
F_34 () ;
}
return 0 ;
}
int V_79 ( const struct V_12 * V_20 , const struct V_12 * V_55 ,
bool V_80 )
{
const struct V_2 * V_81 = F_56 ( V_55 ) ;
int V_82 = F_57 ( V_55 ) ;
int V_83 = F_58 ( & V_20 -> V_39 ) ;
int V_84 = V_81 ? F_58 ( V_81 ) : V_85 ;
if ( V_83 == V_85 && V_84 == V_85 ) {
if ( ! V_82 ) {
if ( V_20 -> V_86 == V_55 -> V_86 )
return 1 ;
if ( ! V_20 -> V_86 || ! V_55 -> V_86 )
return V_80 ;
}
return 0 ;
}
if ( V_83 == V_87 && V_84 == V_87 )
return 1 ;
if ( V_84 == V_87 && V_80 &&
! ( V_82 && V_83 == V_85 ) )
return 1 ;
if ( V_83 == V_87 && V_80 &&
! ( F_59 ( V_20 ) && V_84 == V_85 ) )
return 1 ;
if ( V_81 &&
F_21 ( & V_20 -> V_39 , V_81 ) )
return 1 ;
return 0 ;
}
