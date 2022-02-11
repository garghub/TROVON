void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 , V_7 , & V_4 , NULL ) ;
F_5 ( & V_2 -> V_5 -> V_6 ) ;
}
static int F_6 ( const T_2 V_8 )
{
int error = 0 ;
struct V_1 * V_9 ;
const T_3 V_10 = F_7 ( V_8 ) ;
if ( F_8 ( V_8 ) >= V_11 )
return - V_12 ;
if ( V_10 == 0 )
return 0 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( ! V_9 || ! ( F_11 ( V_8 ) ?
F_12 ( V_9 , V_13 ) : F_13 ( V_9 ) ) ) {
error = - V_12 ;
}
F_14 () ;
return error ;
}
static inline union V_14
F_15 ( const T_2 V_8 , const struct V_15 * V_16 )
{
union V_14 V_17 ;
V_17 . V_18 = 0 ;
if ( F_8 ( V_8 ) == V_19 ) {
V_17 . V_18 = ( unsigned long long ) V_16 -> V_20 * V_21 + V_16 -> V_22 ;
} else {
V_17 . V_23 = F_16 ( V_16 ) ;
}
return V_17 ;
}
static void F_17 ( const T_2 V_8 ,
union V_14 V_23 ,
struct V_15 * V_16 )
{
if ( F_8 ( V_8 ) == V_19 )
* V_16 = F_18 ( V_23 . V_18 ) ;
else
F_19 ( V_23 . V_23 , V_16 ) ;
}
static inline int F_20 ( const T_2 V_8 ,
union V_14 V_24 ,
union V_14 V_25 )
{
if ( F_8 ( V_8 ) == V_19 ) {
return V_24 . V_18 < V_25 . V_18 ;
} else {
return F_21 ( V_24 . V_23 , V_25 . V_23 ) ;
}
}
static inline void F_22 ( const T_2 V_8 ,
union V_14 * V_26 ,
union V_14 V_27 )
{
if ( F_8 ( V_8 ) == V_19 ) {
V_26 -> V_18 += V_27 . V_18 ;
} else {
V_26 -> V_23 = F_23 ( V_26 -> V_23 , V_27 . V_23 ) ;
}
}
static inline union V_14 F_24 ( const T_2 V_8 ,
union V_14 V_28 ,
union V_14 V_29 )
{
if ( F_8 ( V_8 ) == V_19 ) {
V_28 . V_18 -= V_29 . V_18 ;
} else {
V_28 . V_23 = F_25 ( V_28 . V_23 , V_29 . V_23 ) ;
}
return V_28 ;
}
static inline T_1 F_26 ( T_1 time , unsigned long div )
{
T_1 V_30 = F_27 ( time , div ) ;
return F_28 ( T_1 , V_30 , 1 ) ;
}
static void F_29 ( struct V_31 * V_32 ,
union V_14 V_24 )
{
int V_33 ;
if ( V_32 -> V_34 . V_23 . V_35 . V_18 == 0 )
return;
if ( F_8 ( V_32 -> V_36 ) == V_19 ) {
unsigned long long V_37 , V_35 ;
if ( V_24 . V_18 < V_32 -> V_34 . V_23 . V_38 . V_18 )
return;
V_35 = V_32 -> V_34 . V_23 . V_35 . V_18 ;
V_37 = V_24 . V_18 + V_35 - V_32 -> V_34 . V_23 . V_38 . V_18 ;
for ( V_33 = 0 ; V_35 < V_37 - V_35 ; V_33 ++ )
V_35 = V_35 << 1 ;
for (; V_33 >= 0 ; V_35 >>= 1 , V_33 -- ) {
if ( V_37 < V_35 )
continue;
V_32 -> V_34 . V_23 . V_38 . V_18 += V_35 ;
V_32 -> V_39 += 1 << V_33 ;
V_37 -= V_35 ;
}
} else {
T_1 V_37 , V_35 ;
if ( F_21 ( V_24 . V_23 , V_32 -> V_34 . V_23 . V_38 . V_23 ) )
return;
V_35 = V_32 -> V_34 . V_23 . V_35 . V_23 ;
V_37 = F_25 ( F_23 ( V_24 . V_23 , V_35 ) ,
V_32 -> V_34 . V_23 . V_38 . V_23 ) ;
for ( V_33 = 0 ; F_21 ( V_35 , F_25 ( V_37 , V_35 ) ) ; V_33 ++ )
V_35 = F_23 ( V_35 , V_35 ) ;
for (; V_33 >= 0 ; V_35 = F_30 ( V_35 ) , V_33 -- ) {
if ( F_21 ( V_37 , V_35 ) )
continue;
V_32 -> V_34 . V_23 . V_38 . V_23 =
F_23 ( V_32 -> V_34 . V_23 . V_38 . V_23 , V_35 ) ;
V_32 -> V_39 += 1 << V_33 ;
V_37 = F_25 ( V_37 , V_35 ) ;
}
}
}
static inline T_1 F_31 ( struct V_1 * V_9 )
{
return F_23 ( V_9 -> V_40 , V_9 -> V_41 ) ;
}
static inline T_1 F_32 ( struct V_1 * V_9 )
{
return V_9 -> V_40 ;
}
static int
F_33 ( const T_2 V_8 , struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( ! error ) {
V_16 -> V_20 = 0 ;
V_16 -> V_22 = ( ( V_21 + V_42 - 1 ) / V_42 ) ;
if ( F_8 ( V_8 ) == V_19 ) {
V_16 -> V_22 = 1 ;
}
}
return error ;
}
static int
F_34 ( const T_2 V_8 , const struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( error == 0 ) {
error = - V_43 ;
}
return error ;
}
static int F_35 ( const T_2 V_8 , struct V_1 * V_9 ,
union V_14 * V_23 )
{
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
V_23 -> V_23 = F_31 ( V_9 ) ;
break;
case V_44 :
V_23 -> V_23 = F_32 ( V_9 ) ;
break;
case V_19 :
V_23 -> V_18 = F_36 ( V_9 ) ;
break;
}
return 0 ;
}
void F_37 ( struct V_1 * V_45 , struct V_46 * V_47 )
{
struct V_48 * V_49 = V_45 -> signal ;
struct V_1 * V_50 ;
V_47 -> V_40 = V_49 -> V_40 ;
V_47 -> V_41 = V_49 -> V_41 ;
V_47 -> V_51 = V_49 -> V_52 ;
F_9 () ;
if ( ! F_38 ( F_39 ( V_45 ) ) )
goto V_53;
V_50 = V_45 ;
do {
V_47 -> V_40 = F_23 ( V_47 -> V_40 , V_50 -> V_40 ) ;
V_47 -> V_41 = F_23 ( V_47 -> V_41 , V_50 -> V_41 ) ;
V_47 -> V_51 += F_36 ( V_50 ) ;
} while_each_thread(tsk, t) ;
void F_40 ( struct V_46 * V_28 , struct V_46 * V_29 )
{
if ( F_41 ( V_29 -> V_40 , V_28 -> V_40 ) )
V_28 -> V_40 = V_29 -> V_40 ;
if ( F_41 ( V_29 -> V_41 , V_28 -> V_41 ) )
V_28 -> V_41 = V_29 -> V_41 ;
if ( V_29 -> V_51 > V_28 -> V_51 )
V_28 -> V_51 = V_29 -> V_51 ;
}
void F_42 ( struct V_1 * V_45 , struct V_46 * V_47 )
{
struct F_42 * V_54 = & V_45 -> signal -> V_54 ;
struct V_46 V_55 ;
unsigned long V_56 ;
if ( ! V_54 -> V_57 ) {
F_37 ( V_45 , & V_55 ) ;
F_43 ( & V_54 -> V_58 , V_56 ) ;
V_54 -> V_57 = 1 ;
F_40 ( & V_54 -> V_4 , & V_55 ) ;
} else
F_43 ( & V_54 -> V_58 , V_56 ) ;
* V_47 = V_54 -> V_4 ;
F_44 ( & V_54 -> V_58 , V_56 ) ;
}
static int F_45 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct V_46 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_37 ( V_9 , & V_4 ) ;
V_23 -> V_23 = F_23 ( V_4 . V_40 , V_4 . V_41 ) ;
break;
case V_44 :
F_37 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_40 ;
break;
case V_19 :
F_37 ( V_9 , & V_4 ) ;
V_23 -> V_18 = V_4 . V_51 ;
break;
}
return 0 ;
}
static int F_46 ( const T_2 V_8 , struct V_15 * V_16 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int error = - V_12 ;
union V_14 V_59 ;
if ( V_10 == 0 ) {
if ( F_11 ( V_8 ) ) {
error = F_35 ( V_8 ,
V_13 , & V_59 ) ;
} else {
F_47 ( & V_60 ) ;
error = F_45 ( V_8 ,
V_13 , & V_59 ) ;
F_48 ( & V_60 ) ;
}
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 ) {
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_9 , V_13 ) ) {
error = F_35 ( V_8 ,
V_9 , & V_59 ) ;
}
} else {
F_47 ( & V_60 ) ;
if ( F_49 ( V_9 ) && V_9 -> V_5 ) {
error =
F_45 ( V_8 ,
V_9 , & V_59 ) ;
}
F_48 ( & V_60 ) ;
}
}
F_14 () ;
}
if ( error )
return error ;
F_17 ( V_8 , V_59 , V_16 ) ;
return 0 ;
}
static int F_50 ( struct V_31 * V_61 )
{
int V_17 = 0 ;
const T_3 V_10 = F_7 ( V_61 -> V_36 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_61 -> V_36 ) >= V_11 )
return - V_12 ;
F_51 ( & V_61 -> V_34 . V_23 . V_62 ) ;
F_9 () ;
if ( F_11 ( V_61 -> V_36 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_63 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_61 -> V_34 . V_23 . V_2 = V_9 ;
if ( V_9 ) {
F_52 ( V_9 ) ;
} else {
V_17 = - V_12 ;
}
F_14 () ;
return V_17 ;
}
static int F_53 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = V_32 -> V_34 . V_23 . V_2 ;
int V_17 = 0 ;
if ( F_38 ( V_9 != NULL ) ) {
F_47 ( & V_60 ) ;
if ( F_54 ( V_9 -> V_5 == NULL ) ) {
F_55 ( ! F_56 ( & V_32 -> V_34 . V_23 . V_62 ) ) ;
} else {
F_57 ( & V_9 -> V_5 -> V_6 ) ;
if ( V_32 -> V_34 . V_23 . V_64 )
V_17 = V_65 ;
else
F_58 ( & V_32 -> V_34 . V_23 . V_62 ) ;
F_59 ( & V_9 -> V_5 -> V_6 ) ;
}
F_48 ( & V_60 ) ;
if ( ! V_17 )
F_60 ( V_9 ) ;
}
return V_17 ;
}
static void F_61 ( struct V_66 * V_67 ,
T_1 V_40 , T_1 V_41 ,
unsigned long long V_51 )
{
struct V_68 * V_32 , * V_69 ;
T_1 V_70 = F_23 ( V_40 , V_41 ) ;
F_62 (timer, next, head, entry) {
F_63 ( & V_32 -> V_62 ) ;
if ( F_21 ( V_32 -> V_38 . V_23 , V_70 ) ) {
V_32 -> V_38 . V_23 = V_71 ;
} else {
V_32 -> V_38 . V_23 = F_25 ( V_32 -> V_38 . V_23 ,
V_70 ) ;
}
}
++ V_67 ;
F_62 (timer, next, head, entry) {
F_63 ( & V_32 -> V_62 ) ;
if ( F_21 ( V_32 -> V_38 . V_23 , V_40 ) ) {
V_32 -> V_38 . V_23 = V_71 ;
} else {
V_32 -> V_38 . V_23 = F_25 ( V_32 -> V_38 . V_23 ,
V_40 ) ;
}
}
++ V_67 ;
F_62 (timer, next, head, entry) {
F_63 ( & V_32 -> V_62 ) ;
if ( V_32 -> V_38 . V_18 < V_51 ) {
V_32 -> V_38 . V_18 = 0 ;
} else {
V_32 -> V_38 . V_18 -= V_51 ;
}
}
}
void F_64 ( struct V_1 * V_45 )
{
F_61 ( V_45 -> V_72 ,
V_45 -> V_40 , V_45 -> V_41 , V_45 -> V_73 . V_51 ) ;
}
void F_65 ( struct V_1 * V_45 )
{
struct V_48 * const V_49 = V_45 -> signal ;
F_61 ( V_45 -> signal -> V_72 ,
F_23 ( V_45 -> V_40 , V_49 -> V_40 ) ,
F_23 ( V_45 -> V_41 , V_49 -> V_41 ) ,
V_45 -> V_73 . V_51 + V_49 -> V_52 ) ;
}
static void F_66 ( struct V_31 * V_32 , union V_14 V_24 )
{
F_60 ( V_32 -> V_34 . V_23 . V_2 ) ;
V_32 -> V_34 . V_23 . V_2 = NULL ;
V_32 -> V_34 . V_23 . V_38 = F_24 ( V_32 -> V_36 ,
V_32 -> V_34 . V_23 . V_38 ,
V_24 ) ;
}
static inline int F_67 ( T_1 V_38 , T_1 V_74 )
{
return F_68 ( V_38 , V_71 ) ||
F_41 ( V_38 , V_74 ) ;
}
static void F_69 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = V_32 -> V_34 . V_23 . V_2 ;
struct V_66 * V_67 , * V_75 ;
struct V_46 * V_76 ;
struct V_68 * const V_77 = & V_32 -> V_34 . V_23 ;
struct V_68 * V_69 ;
if ( F_11 ( V_32 -> V_36 ) ) {
V_67 = V_9 -> V_72 ;
V_76 = & V_9 -> V_76 ;
} else {
V_67 = V_9 -> signal -> V_72 ;
V_76 = & V_9 -> signal -> V_76 ;
}
V_67 += F_8 ( V_32 -> V_36 ) ;
V_75 = V_67 ;
F_70 (next, head, entry) {
if ( F_20 ( V_32 -> V_36 , V_77 -> V_38 , V_69 -> V_38 ) )
break;
V_75 = & V_69 -> V_62 ;
}
F_71 ( & V_77 -> V_62 , V_75 ) ;
if ( V_75 == V_67 ) {
union V_14 * exp = & V_77 -> V_38 ;
switch ( F_8 ( V_32 -> V_36 ) ) {
case V_7 :
if ( F_67 ( V_76 -> V_78 , exp -> V_23 ) )
V_76 -> V_78 = exp -> V_23 ;
break;
case V_44 :
if ( F_67 ( V_76 -> V_79 , exp -> V_23 ) )
V_76 -> V_79 = exp -> V_23 ;
break;
case V_19 :
if ( V_76 -> V_80 == 0 ||
V_76 -> V_80 > exp -> V_18 )
V_76 -> V_80 = exp -> V_18 ;
break;
}
}
}
static void F_72 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_81 & ~ V_82 ) == V_83 ) {
V_32 -> V_34 . V_23 . V_38 . V_18 = 0 ;
} else if ( F_54 ( V_32 -> V_84 == NULL ) ) {
F_73 ( V_32 -> V_85 ) ;
V_32 -> V_34 . V_23 . V_38 . V_18 = 0 ;
} else if ( V_32 -> V_34 . V_23 . V_35 . V_18 == 0 ) {
F_74 ( V_32 , 0 ) ;
V_32 -> V_34 . V_23 . V_38 . V_18 = 0 ;
} else if ( F_74 ( V_32 , ++ V_32 -> V_86 ) ) {
F_75 ( V_32 ) ;
}
}
static int F_76 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct V_46 V_4 ;
F_42 ( V_9 , & V_4 ) ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
V_23 -> V_23 = F_23 ( V_4 . V_40 , V_4 . V_41 ) ;
break;
case V_44 :
V_23 -> V_23 = V_4 . V_40 ;
break;
case V_19 :
V_23 -> V_18 = V_4 . V_51 + F_77 ( V_9 ) ;
break;
}
return 0 ;
}
static int F_78 ( struct V_31 * V_32 , int V_56 ,
struct V_87 * V_88 , struct V_87 * V_89 )
{
struct V_1 * V_9 = V_32 -> V_34 . V_23 . V_2 ;
union V_14 V_90 , V_91 , V_92 , V_27 ;
int V_17 ;
if ( F_54 ( V_9 == NULL ) ) {
return - V_93 ;
}
V_91 = F_15 ( V_32 -> V_36 , & V_88 -> V_94 ) ;
F_47 ( & V_60 ) ;
if ( F_54 ( V_9 -> V_5 == NULL ) ) {
F_48 ( & V_60 ) ;
F_60 ( V_9 ) ;
V_32 -> V_34 . V_23 . V_2 = NULL ;
return - V_93 ;
}
F_55 ( ! F_79 () ) ;
V_17 = 0 ;
V_92 = V_32 -> V_34 . V_23 . V_35 ;
F_57 ( & V_9 -> V_5 -> V_6 ) ;
V_90 = V_32 -> V_34 . V_23 . V_38 ;
if ( F_54 ( V_32 -> V_34 . V_23 . V_64 ) ) {
V_32 -> V_34 . V_23 . V_64 = - 1 ;
V_17 = V_65 ;
} else
F_63 ( & V_32 -> V_34 . V_23 . V_62 ) ;
if ( F_11 ( V_32 -> V_36 ) ) {
F_35 ( V_32 -> V_36 , V_9 , & V_27 ) ;
} else {
F_76 ( V_32 -> V_36 , V_9 , & V_27 ) ;
}
if ( V_89 ) {
if ( V_90 . V_18 == 0 ) {
V_89 -> V_94 . V_20 = 0 ;
V_89 -> V_94 . V_22 = 0 ;
} else {
F_29 ( V_32 , V_27 ) ;
if ( F_20 ( V_32 -> V_36 , V_27 ,
V_32 -> V_34 . V_23 . V_38 ) ) {
V_90 = F_24 (
V_32 -> V_36 ,
V_32 -> V_34 . V_23 . V_38 , V_27 ) ;
F_17 ( V_32 -> V_36 ,
V_90 ,
& V_89 -> V_94 ) ;
} else {
V_89 -> V_94 . V_22 = 1 ;
V_89 -> V_94 . V_20 = 0 ;
}
}
}
if ( F_54 ( V_17 ) ) {
F_59 ( & V_9 -> V_5 -> V_6 ) ;
F_48 ( & V_60 ) ;
goto V_53;
}
if ( V_91 . V_18 != 0 && ! ( V_56 & V_95 ) ) {
F_22 ( V_32 -> V_36 , & V_91 , V_27 ) ;
}
V_32 -> V_34 . V_23 . V_38 = V_91 ;
if ( V_91 . V_18 != 0 &&
F_20 ( V_32 -> V_36 , V_27 , V_91 ) ) {
F_69 ( V_32 ) ;
}
F_59 ( & V_9 -> V_5 -> V_6 ) ;
F_48 ( & V_60 ) ;
V_32 -> V_34 . V_23 . V_35 = F_15 ( V_32 -> V_36 ,
& V_88 -> V_96 ) ;
V_32 -> V_86 = ( V_32 -> V_86 + 2 ) &
~ V_97 ;
V_32 -> V_98 = 0 ;
V_32 -> V_39 = - 1 ;
if ( V_91 . V_18 != 0 &&
! F_20 ( V_32 -> V_36 , V_27 , V_91 ) ) {
F_72 ( V_32 ) ;
}
V_17 = 0 ;
V_53:
if ( V_89 ) {
F_17 ( V_32 -> V_36 ,
V_92 , & V_89 -> V_96 ) ;
}
return V_17 ;
}
static void F_80 ( struct V_31 * V_32 , struct V_87 * V_99 )
{
union V_14 V_24 ;
struct V_1 * V_9 = V_32 -> V_34 . V_23 . V_2 ;
int V_100 ;
F_17 ( V_32 -> V_36 ,
V_32 -> V_34 . V_23 . V_35 , & V_99 -> V_96 ) ;
if ( V_32 -> V_34 . V_23 . V_38 . V_18 == 0 ) {
V_99 -> V_94 . V_20 = V_99 -> V_94 . V_22 = 0 ;
return;
}
if ( F_54 ( V_9 == NULL ) ) {
V_101:
F_17 ( V_32 -> V_36 , V_32 -> V_34 . V_23 . V_38 ,
& V_99 -> V_94 ) ;
return;
}
if ( F_11 ( V_32 -> V_36 ) ) {
F_35 ( V_32 -> V_36 , V_9 , & V_24 ) ;
V_100 = V_9 -> V_102 ;
} else {
F_47 ( & V_60 ) ;
if ( F_54 ( V_9 -> V_5 == NULL ) ) {
F_60 ( V_9 ) ;
V_32 -> V_34 . V_23 . V_2 = NULL ;
V_32 -> V_34 . V_23 . V_38 . V_18 = 0 ;
F_48 ( & V_60 ) ;
goto V_101;
} else {
F_76 ( V_32 -> V_36 , V_9 , & V_24 ) ;
V_100 = ( F_54 ( V_9 -> V_102 ) &&
F_81 ( V_9 ) ) ;
}
F_48 ( & V_60 ) ;
}
if ( F_54 ( V_100 ) ) {
F_66 ( V_32 , V_24 ) ;
goto V_101;
}
if ( F_20 ( V_32 -> V_36 , V_24 , V_32 -> V_34 . V_23 . V_38 ) ) {
F_17 ( V_32 -> V_36 ,
F_24 ( V_32 -> V_36 ,
V_32 -> V_34 . V_23 . V_38 , V_24 ) ,
& V_99 -> V_94 ) ;
} else {
V_99 -> V_94 . V_22 = 1 ;
V_99 -> V_94 . V_20 = 0 ;
}
}
static void F_82 ( struct V_1 * V_45 ,
struct V_66 * V_64 )
{
int V_103 ;
struct V_66 * V_104 = V_45 -> V_72 ;
struct V_48 * const V_49 = V_45 -> signal ;
unsigned long V_105 ;
V_103 = 20 ;
V_45 -> V_76 . V_78 = V_71 ;
while ( ! F_56 ( V_104 ) ) {
struct V_68 * V_50 = F_83 ( V_104 ,
struct V_68 ,
V_62 ) ;
if ( ! -- V_103 || F_21 ( F_31 ( V_45 ) , V_50 -> V_38 . V_23 ) ) {
V_45 -> V_76 . V_78 = V_50 -> V_38 . V_23 ;
break;
}
V_50 -> V_64 = 1 ;
F_84 ( & V_50 -> V_62 , V_64 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_45 -> V_76 . V_79 = V_71 ;
while ( ! F_56 ( V_104 ) ) {
struct V_68 * V_50 = F_83 ( V_104 ,
struct V_68 ,
V_62 ) ;
if ( ! -- V_103 || F_21 ( F_32 ( V_45 ) , V_50 -> V_38 . V_23 ) ) {
V_45 -> V_76 . V_79 = V_50 -> V_38 . V_23 ;
break;
}
V_50 -> V_64 = 1 ;
F_84 ( & V_50 -> V_62 , V_64 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_45 -> V_76 . V_80 = 0 ;
while ( ! F_56 ( V_104 ) ) {
struct V_68 * V_50 = F_83 ( V_104 ,
struct V_68 ,
V_62 ) ;
if ( ! -- V_103 || V_45 -> V_73 . V_51 < V_50 -> V_38 . V_18 ) {
V_45 -> V_76 . V_80 = V_50 -> V_38 . V_18 ;
break;
}
V_50 -> V_64 = 1 ;
F_84 ( & V_50 -> V_62 , V_64 ) ;
}
V_105 = F_85 ( V_49 -> V_106 [ V_107 ] . V_108 ) ;
if ( V_105 != V_109 ) {
unsigned long V_110 =
F_85 ( V_49 -> V_106 [ V_107 ] . V_111 ) ;
if ( V_110 != V_109 &&
V_45 -> V_112 . V_113 > F_86 ( V_110 , V_114 / V_42 ) ) {
F_87 ( V_115 , V_116 , V_45 ) ;
return;
}
if ( V_45 -> V_112 . V_113 > F_86 ( V_105 , V_114 / V_42 ) ) {
if ( V_105 < V_110 ) {
V_105 += V_114 ;
V_49 -> V_106 [ V_107 ] . V_108 = V_105 ;
}
F_88 ( V_117
L_1 ,
V_45 -> V_118 , F_89 ( V_45 ) ) ;
F_87 ( V_119 , V_116 , V_45 ) ;
}
}
}
static void F_90 ( struct V_48 * V_49 )
{
struct F_42 * V_54 = & V_49 -> V_54 ;
unsigned long V_56 ;
F_43 ( & V_54 -> V_58 , V_56 ) ;
V_54 -> V_57 = 0 ;
F_44 ( & V_54 -> V_58 , V_56 ) ;
}
static void F_91 ( struct V_1 * V_45 , struct V_120 * V_34 ,
T_1 * V_38 , T_1 V_121 , int V_122 )
{
if ( F_68 ( V_34 -> V_38 , V_71 ) )
return;
if ( F_92 ( V_121 , V_34 -> V_38 ) ) {
if ( ! F_68 ( V_34 -> V_35 , V_71 ) ) {
V_34 -> V_38 = F_23 ( V_34 -> V_38 , V_34 -> V_35 ) ;
V_34 -> error += V_34 -> V_123 ;
if ( V_34 -> error >= V_124 ) {
V_34 -> V_38 = F_25 ( V_34 -> V_38 ,
V_125 ) ;
V_34 -> error -= V_124 ;
}
} else {
V_34 -> V_38 = V_71 ;
}
F_93 ( V_122 == V_126 ?
V_127 : V_128 ,
V_45 -> signal -> V_129 , V_121 ) ;
F_87 ( V_122 , V_116 , V_45 ) ;
}
if ( ! F_68 ( V_34 -> V_38 , V_71 ) &&
( F_68 ( * V_38 , V_71 ) ||
F_21 ( V_34 -> V_38 , * V_38 ) ) ) {
* V_38 = V_34 -> V_38 ;
}
}
static inline int F_94 ( const struct V_46 * V_4 )
{
if ( F_68 ( V_4 -> V_40 , V_71 ) &&
F_68 ( V_4 -> V_41 , V_71 ) &&
V_4 -> V_51 == 0 )
return 1 ;
return 0 ;
}
static void F_95 ( struct V_1 * V_45 ,
struct V_66 * V_64 )
{
int V_103 ;
struct V_48 * const V_49 = V_45 -> signal ;
T_1 V_40 , V_70 , V_130 , V_131 ;
unsigned long long V_52 , V_132 ;
struct V_66 * V_104 = V_49 -> V_72 ;
struct V_46 V_4 ;
unsigned long V_105 ;
F_42 ( V_45 , & V_4 ) ;
V_40 = V_4 . V_40 ;
V_70 = F_23 ( V_40 , V_4 . V_41 ) ;
V_52 = V_4 . V_51 ;
V_103 = 20 ;
V_131 = V_71 ;
while ( ! F_56 ( V_104 ) ) {
struct V_68 * V_133 = F_83 ( V_104 ,
struct V_68 ,
V_62 ) ;
if ( ! -- V_103 || F_21 ( V_70 , V_133 -> V_38 . V_23 ) ) {
V_131 = V_133 -> V_38 . V_23 ;
break;
}
V_133 -> V_64 = 1 ;
F_84 ( & V_133 -> V_62 , V_64 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_130 = V_71 ;
while ( ! F_56 ( V_104 ) ) {
struct V_68 * V_133 = F_83 ( V_104 ,
struct V_68 ,
V_62 ) ;
if ( ! -- V_103 || F_21 ( V_40 , V_133 -> V_38 . V_23 ) ) {
V_130 = V_133 -> V_38 . V_23 ;
break;
}
V_133 -> V_64 = 1 ;
F_84 ( & V_133 -> V_62 , V_64 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_132 = 0 ;
while ( ! F_56 ( V_104 ) ) {
struct V_68 * V_133 = F_83 ( V_104 ,
struct V_68 ,
V_62 ) ;
if ( ! -- V_103 || V_52 < V_133 -> V_38 . V_18 ) {
V_132 = V_133 -> V_38 . V_18 ;
break;
}
V_133 -> V_64 = 1 ;
F_84 ( & V_133 -> V_62 , V_64 ) ;
}
F_91 ( V_45 , & V_49 -> V_34 [ V_7 ] , & V_131 , V_70 ,
V_126 ) ;
F_91 ( V_45 , & V_49 -> V_34 [ V_44 ] , & V_130 , V_40 ,
V_134 ) ;
V_105 = F_85 ( V_49 -> V_106 [ V_135 ] . V_108 ) ;
if ( V_105 != V_109 ) {
unsigned long V_136 = F_96 ( V_70 ) ;
unsigned long V_110 =
F_85 ( V_49 -> V_106 [ V_135 ] . V_111 ) ;
T_1 V_137 ;
if ( V_136 >= V_110 ) {
F_87 ( V_115 , V_116 , V_45 ) ;
return;
}
if ( V_136 >= V_105 ) {
F_87 ( V_119 , V_116 , V_45 ) ;
if ( V_105 < V_110 ) {
V_105 ++ ;
V_49 -> V_106 [ V_135 ] . V_108 = V_105 ;
}
}
V_137 = F_2 ( V_105 ) ;
if ( F_68 ( V_131 , V_71 ) ||
F_21 ( V_137 , V_131 ) ) {
V_131 = V_137 ;
}
}
V_49 -> V_76 . V_78 = V_131 ;
V_49 -> V_76 . V_79 = V_130 ;
V_49 -> V_76 . V_80 = V_132 ;
if ( F_94 ( & V_49 -> V_76 ) )
F_90 ( V_49 ) ;
}
void F_75 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = V_32 -> V_34 . V_23 . V_2 ;
union V_14 V_24 ;
if ( F_54 ( V_9 == NULL ) )
goto V_53;
if ( F_11 ( V_32 -> V_36 ) ) {
F_35 ( V_32 -> V_36 , V_9 , & V_24 ) ;
F_29 ( V_32 , V_24 ) ;
if ( F_54 ( V_9 -> V_102 ) ) {
F_66 ( V_32 , V_24 ) ;
goto V_53;
}
F_47 ( & V_60 ) ;
F_57 ( & V_9 -> V_5 -> V_6 ) ;
} else {
F_47 ( & V_60 ) ;
if ( F_54 ( V_9 -> V_5 == NULL ) ) {
F_60 ( V_9 ) ;
V_32 -> V_34 . V_23 . V_2 = V_9 = NULL ;
V_32 -> V_34 . V_23 . V_38 . V_18 = 0 ;
goto V_138;
} else if ( F_54 ( V_9 -> V_102 ) && F_81 ( V_9 ) ) {
F_66 ( V_32 , V_24 ) ;
goto V_138;
}
F_57 ( & V_9 -> V_5 -> V_6 ) ;
F_76 ( V_32 -> V_36 , V_9 , & V_24 ) ;
F_29 ( V_32 , V_24 ) ;
}
F_55 ( ! F_79 () ) ;
F_69 ( V_32 ) ;
F_59 ( & V_9 -> V_5 -> V_6 ) ;
V_138:
F_48 ( & V_60 ) ;
V_53:
V_32 -> V_98 = V_32 -> V_39 ;
V_32 -> V_39 = - 1 ;
++ V_32 -> V_86 ;
}
static inline int F_97 ( const struct V_46 * V_139 ,
const struct V_46 * V_38 )
{
if ( ! F_68 ( V_38 -> V_40 , V_71 ) &&
F_92 ( V_139 -> V_40 , V_38 -> V_40 ) )
return 1 ;
if ( ! F_68 ( V_38 -> V_41 , V_71 ) &&
F_92 ( F_23 ( V_139 -> V_40 , V_139 -> V_41 ) ,
V_38 -> V_41 ) )
return 1 ;
if ( V_38 -> V_51 != 0 &&
V_139 -> V_51 >= V_38 -> V_51 )
return 1 ;
return 0 ;
}
static inline int F_98 ( struct V_1 * V_45 )
{
struct V_48 * V_49 ;
if ( ! F_94 ( & V_45 -> V_76 ) ) {
struct V_46 V_140 = {
. V_40 = V_45 -> V_40 ,
. V_41 = V_45 -> V_41 ,
. V_51 = V_45 -> V_73 . V_51
} ;
if ( F_97 ( & V_140 , & V_45 -> V_76 ) )
return 1 ;
}
V_49 = V_45 -> signal ;
if ( V_49 -> V_54 . V_57 ) {
struct V_46 V_141 ;
F_99 ( & V_49 -> V_54 . V_58 ) ;
V_141 = V_49 -> V_54 . V_4 ;
F_100 ( & V_49 -> V_54 . V_58 ) ;
if ( F_97 ( & V_141 , & V_49 -> V_76 ) )
return 1 ;
}
return 0 ;
}
void F_101 ( struct V_1 * V_45 )
{
F_102 ( V_64 ) ;
struct V_31 * V_32 , * V_69 ;
unsigned long V_56 ;
F_55 ( ! F_79 () ) ;
if ( ! F_98 ( V_45 ) )
return;
if ( ! F_103 ( V_45 , & V_56 ) )
return;
F_82 ( V_45 , & V_64 ) ;
if ( V_45 -> signal -> V_54 . V_57 )
F_95 ( V_45 , & V_64 ) ;
F_104 ( V_45 , & V_56 ) ;
F_62 (timer, next, &firing, it.cpu.entry) {
int V_142 ;
F_57 ( & V_32 -> V_143 ) ;
F_63 ( & V_32 -> V_34 . V_23 . V_62 ) ;
V_142 = V_32 -> V_34 . V_23 . V_64 ;
V_32 -> V_34 . V_23 . V_64 = 0 ;
if ( F_38 ( V_142 >= 0 ) )
F_72 ( V_32 ) ;
F_59 ( & V_32 -> V_143 ) ;
}
}
void F_4 ( struct V_1 * V_45 , unsigned int V_144 ,
T_1 * V_145 , T_1 * V_146 )
{
union V_14 V_24 ;
F_55 ( V_144 == V_19 ) ;
F_76 ( V_144 , V_45 , & V_24 ) ;
if ( V_146 ) {
if ( ! F_68 ( * V_146 , V_71 ) ) {
if ( F_105 ( * V_146 , V_24 . V_23 ) ) {
* V_146 = V_125 ;
} else {
* V_146 = F_25 ( * V_146 , V_24 . V_23 ) ;
}
}
if ( F_68 ( * V_145 , V_71 ) )
return;
* V_145 = F_23 ( * V_145 , V_24 . V_23 ) ;
}
switch ( V_144 ) {
case V_7 :
if ( F_67 ( V_45 -> signal -> V_76 . V_78 , * V_145 ) )
V_45 -> signal -> V_76 . V_78 = * V_145 ;
break;
case V_44 :
if ( F_67 ( V_45 -> signal -> V_76 . V_79 , * V_145 ) )
V_45 -> signal -> V_76 . V_79 = * V_145 ;
break;
}
}
static int F_106 ( const T_2 V_8 , int V_56 ,
struct V_15 * V_147 , struct V_87 * V_34 )
{
struct V_31 V_32 ;
int error ;
memset ( & V_32 , 0 , sizeof V_32 ) ;
F_107 ( & V_32 . V_143 ) ;
V_32 . V_36 = V_8 ;
V_32 . V_39 = - 1 ;
error = F_50 ( & V_32 ) ;
V_32 . V_85 = V_13 ;
if ( ! error ) {
static struct V_87 V_148 ;
memset ( V_34 , 0 , sizeof *V_34 ) ;
V_34 -> V_94 = * V_147 ;
F_3 ( & V_32 . V_143 ) ;
error = F_78 ( & V_32 , V_56 , V_34 , NULL ) ;
if ( error ) {
F_5 ( & V_32 . V_143 ) ;
return error ;
}
while ( ! F_108 ( V_13 ) ) {
if ( V_32 . V_34 . V_23 . V_38 . V_18 == 0 ) {
F_5 ( & V_32 . V_143 ) ;
return 0 ;
}
F_109 ( V_149 ) ;
F_5 ( & V_32 . V_143 ) ;
F_110 () ;
F_3 ( & V_32 . V_143 ) ;
}
F_17 ( V_8 , V_32 . V_34 . V_23 . V_38 , V_147 ) ;
F_78 ( & V_32 , 0 , & V_148 , V_34 ) ;
F_5 ( & V_32 . V_143 ) ;
if ( ( V_34 -> V_94 . V_20 | V_34 -> V_94 . V_22 ) == 0 ) {
return 0 ;
}
error = - V_150 ;
}
return error ;
}
static int F_111 ( const T_2 V_8 , int V_56 ,
struct V_15 * V_147 , struct V_15 T_4 * V_151 )
{
struct V_152 * V_152 =
& F_112 () -> V_152 ;
struct V_87 V_34 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_106 ( V_8 , V_56 , V_147 , & V_34 ) ;
if ( error == - V_150 ) {
if ( V_56 & V_95 )
return - V_153 ;
if ( V_151 && F_113 ( V_151 , & V_34 . V_94 , sizeof *V_151 ) )
return - V_154 ;
V_152 -> V_155 = V_156 ;
V_152 -> V_157 . V_158 = V_8 ;
V_152 -> V_157 . V_151 = V_151 ;
V_152 -> V_157 . V_38 = F_114 ( V_147 ) ;
}
return error ;
}
static long V_156 ( struct V_152 * V_152 )
{
T_2 V_8 = V_152 -> V_157 . V_158 ;
struct V_15 V_50 ;
struct V_87 V_34 ;
int error ;
V_50 = F_18 ( V_152 -> V_157 . V_38 ) ;
error = F_106 ( V_8 , V_95 , & V_50 , & V_34 ) ;
if ( error == - V_150 ) {
struct V_15 T_4 * V_151 = V_152 -> V_157 . V_151 ;
if ( V_151 && F_113 ( V_151 , & V_34 . V_94 , sizeof *V_151 ) )
return - V_154 ;
V_152 -> V_157 . V_38 = F_114 ( & V_50 ) ;
}
return error ;
}
static int F_115 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_33 ( V_159 , V_16 ) ;
}
static int F_116 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_46 ( V_159 , V_16 ) ;
}
static int F_117 ( struct V_31 * V_32 )
{
V_32 -> V_36 = V_159 ;
return F_50 ( V_32 ) ;
}
static int F_118 ( const T_2 V_8 , int V_56 ,
struct V_15 * V_147 ,
struct V_15 T_4 * V_151 )
{
return F_111 ( V_159 , V_56 , V_147 , V_151 ) ;
}
static long F_119 ( struct V_152 * V_152 )
{
return - V_12 ;
}
static int F_120 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_33 ( V_160 , V_16 ) ;
}
static int F_121 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_46 ( V_160 , V_16 ) ;
}
static int F_122 ( struct V_31 * V_32 )
{
V_32 -> V_36 = V_160 ;
return F_50 ( V_32 ) ;
}
static T_5 int F_123 ( void )
{
struct V_161 V_162 = {
. V_163 = F_115 ,
. V_164 = F_116 ,
. V_165 = F_117 ,
. V_166 = F_118 ,
. V_167 = F_119 ,
} ;
struct V_161 V_168 = {
. V_163 = F_120 ,
. V_164 = F_121 ,
. V_165 = F_122 ,
} ;
struct V_15 V_169 ;
F_124 ( V_170 , & V_162 ) ;
F_124 ( V_171 , & V_168 ) ;
F_19 ( V_125 , & V_169 ) ;
V_124 = V_169 . V_22 ;
F_125 ( V_169 . V_20 != 0 ) ;
return 0 ;
}
