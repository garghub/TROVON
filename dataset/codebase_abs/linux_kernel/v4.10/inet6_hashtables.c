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
const int V_19 , bool V_35 )
{
int V_36 = - 1 ;
if ( F_15 ( F_16 ( V_20 ) , V_1 ) && F_17 ( V_20 ) -> V_37 == V_18 &&
V_20 -> V_38 == V_39 ) {
V_36 = 1 ;
if ( ! F_18 ( & V_20 -> V_40 ) ) {
if ( ! F_19 ( & V_20 -> V_40 , V_17 ) )
return - 1 ;
V_36 ++ ;
}
if ( V_20 -> V_41 || V_35 ) {
if ( V_20 -> V_41 != V_19 )
return - 1 ;
V_36 ++ ;
}
if ( V_20 -> V_42 == F_20 () )
V_36 ++ ;
}
return V_36 ;
}
struct V_12 * F_21 ( struct V_1 * V_1 ,
struct V_13 * V_14 ,
struct V_43 * V_44 , int V_45 ,
const struct V_2 * V_15 ,
const T_3 V_16 , const struct V_2 * V_17 ,
const unsigned short V_18 , const int V_19 )
{
unsigned int V_24 = F_22 ( V_1 , V_18 ) ;
struct V_46 * V_47 = & V_14 -> V_48 [ V_24 ] ;
int V_36 , V_49 = 0 , V_50 = 0 , V_51 = 0 ;
bool V_35 = F_23 ( V_1 , V_44 ) ;
struct V_12 * V_20 , * V_52 = NULL ;
T_1 V_53 = 0 ;
F_24 (sk, &ilb->head) {
V_36 = F_14 ( V_20 , V_1 , V_18 , V_17 , V_19 , V_35 ) ;
if ( V_36 > V_49 ) {
V_51 = V_20 -> V_54 ;
if ( V_51 ) {
V_53 = F_1 ( V_1 , V_17 , V_18 ,
V_15 , V_16 ) ;
V_52 = F_25 ( V_20 , V_53 ,
V_44 , V_45 ) ;
if ( V_52 )
return V_52 ;
V_50 = 1 ;
}
V_52 = V_20 ;
V_49 = V_36 ;
} else if ( V_36 == V_49 && V_51 ) {
V_50 ++ ;
if ( F_26 ( V_53 , V_50 ) == 0 )
V_52 = V_20 ;
V_53 = F_27 ( V_53 ) ;
}
}
return V_52 ;
}
struct V_12 * F_28 ( struct V_1 * V_1 , struct V_13 * V_14 ,
struct V_43 * V_44 , int V_45 ,
const struct V_2 * V_15 , const T_3 V_16 ,
const struct V_2 * V_17 , const T_3 V_55 ,
const int V_19 )
{
struct V_12 * V_20 ;
bool V_56 ;
V_20 = F_29 ( V_1 , V_14 , V_44 , V_45 , V_15 , V_16 , V_17 ,
F_30 ( V_55 ) , V_19 , & V_56 ) ;
if ( V_20 && ! V_56 && ! F_11 ( & V_20 -> V_32 ) )
V_20 = NULL ;
return V_20 ;
}
static int F_31 ( struct V_57 * V_58 ,
struct V_12 * V_20 , const T_7 V_4 ,
struct V_59 * * V_60 )
{
struct V_13 * V_61 = V_58 -> V_14 ;
struct V_62 * V_63 = F_17 ( V_20 ) ;
const struct V_2 * V_17 = & V_20 -> V_40 ;
const struct V_2 * V_15 = & V_20 -> V_64 ;
const int V_19 = V_20 -> V_41 ;
const T_6 V_23 = F_7 ( V_63 -> V_65 , V_4 ) ;
struct V_1 * V_1 = F_16 ( V_20 ) ;
const unsigned int V_24 = F_1 ( V_1 , V_17 , V_4 , V_15 ,
V_63 -> V_65 ) ;
struct V_27 * V_28 = V_27 ( V_61 , V_24 ) ;
T_8 * V_66 = F_32 ( V_61 , V_24 ) ;
struct V_12 * V_67 ;
const struct V_21 * V_22 ;
struct V_59 * V_68 = NULL ;
F_33 ( V_66 ) ;
F_34 (sk2, node, &head->chain) {
if ( V_67 -> V_31 != V_24 )
continue;
if ( F_35 ( F_9 ( V_67 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
if ( V_67 -> V_69 == V_70 ) {
V_68 = F_36 ( V_67 ) ;
if ( F_37 ( V_20 , V_67 , V_60 ) )
break;
}
goto V_71;
}
}
V_63 -> V_37 = V_4 ;
V_63 -> V_72 = F_38 ( V_4 ) ;
V_20 -> V_31 = V_24 ;
F_39 ( ! F_40 ( V_20 ) ) ;
F_41 ( V_20 , & V_28 -> V_73 ) ;
if ( V_68 ) {
F_42 ( (struct V_12 * ) V_68 ) ;
F_43 ( V_1 , V_74 ) ;
}
F_44 ( V_66 ) ;
F_45 ( F_16 ( V_20 ) , V_20 -> V_75 , 1 ) ;
if ( V_60 ) {
* V_60 = V_68 ;
} else if ( V_68 ) {
F_46 ( V_68 ) ;
}
return 0 ;
V_71:
F_44 ( V_66 ) ;
return - V_76 ;
}
static T_1 F_47 ( const struct V_12 * V_20 )
{
const struct V_62 * V_63 = F_17 ( V_20 ) ;
return F_48 ( V_20 -> V_40 . V_11 ,
V_20 -> V_64 . V_11 ,
V_63 -> V_65 ) ;
}
int F_49 ( struct V_57 * V_58 ,
struct V_12 * V_20 )
{
T_1 V_77 = 0 ;
if ( ! F_17 ( V_20 ) -> V_37 )
V_77 = F_47 ( V_20 ) ;
return F_50 ( V_58 , V_20 , V_77 ,
F_31 ) ;
}
int F_51 ( struct V_12 * V_20 )
{
int V_78 = 0 ;
if ( V_20 -> V_69 != V_79 ) {
F_52 () ;
V_78 = F_53 ( V_20 , NULL , V_80 ) ;
F_54 () ;
}
return V_78 ;
}
int V_80 ( const struct V_12 * V_20 , const struct V_12 * V_67 ,
bool V_81 )
{
const struct V_2 * V_82 = F_55 ( V_67 ) ;
int V_83 = F_56 ( V_67 ) ;
int V_84 = F_57 ( & V_20 -> V_40 ) ;
int V_85 = V_82 ? F_57 ( V_82 ) : V_86 ;
if ( V_84 == V_86 && V_85 == V_86 ) {
if ( ! V_83 ) {
if ( V_20 -> V_87 == V_67 -> V_87 )
return 1 ;
if ( ! V_20 -> V_87 || ! V_67 -> V_87 )
return V_81 ;
}
return 0 ;
}
if ( V_84 == V_88 && V_85 == V_88 )
return 1 ;
if ( V_85 == V_88 && V_81 &&
! ( V_83 && V_84 == V_86 ) )
return 1 ;
if ( V_84 == V_88 && V_81 &&
! ( F_58 ( V_20 ) && V_85 == V_86 ) )
return 1 ;
if ( V_82 &&
F_19 ( & V_20 -> V_40 , V_82 ) )
return 1 ;
return 0 ;
}
