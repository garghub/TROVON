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
return V_24 . V_23 < V_25 . V_23 ;
}
}
static inline void F_21 ( const T_2 V_8 ,
union V_14 * V_26 ,
union V_14 V_27 )
{
if ( F_8 ( V_8 ) == V_19 ) {
V_26 -> V_18 += V_27 . V_18 ;
} else {
V_26 -> V_23 += V_27 . V_23 ;
}
}
static inline union V_14 F_22 ( const T_2 V_8 ,
union V_14 V_28 ,
union V_14 V_29 )
{
if ( F_8 ( V_8 ) == V_19 ) {
V_28 . V_18 -= V_29 . V_18 ;
} else {
V_28 . V_23 -= V_29 . V_23 ;
}
return V_28 ;
}
static void F_23 ( struct V_30 * V_31 ,
union V_14 V_24 )
{
int V_32 ;
if ( V_31 -> V_33 . V_23 . V_34 . V_18 == 0 )
return;
if ( F_8 ( V_31 -> V_35 ) == V_19 ) {
unsigned long long V_36 , V_34 ;
if ( V_24 . V_18 < V_31 -> V_33 . V_23 . V_37 . V_18 )
return;
V_34 = V_31 -> V_33 . V_23 . V_34 . V_18 ;
V_36 = V_24 . V_18 + V_34 - V_31 -> V_33 . V_23 . V_37 . V_18 ;
for ( V_32 = 0 ; V_34 < V_36 - V_34 ; V_32 ++ )
V_34 = V_34 << 1 ;
for (; V_32 >= 0 ; V_34 >>= 1 , V_32 -- ) {
if ( V_36 < V_34 )
continue;
V_31 -> V_33 . V_23 . V_37 . V_18 += V_34 ;
V_31 -> V_38 += 1 << V_32 ;
V_36 -= V_34 ;
}
} else {
T_1 V_36 , V_34 ;
if ( V_24 . V_23 < V_31 -> V_33 . V_23 . V_37 . V_23 )
return;
V_34 = V_31 -> V_33 . V_23 . V_34 . V_23 ;
V_36 = V_24 . V_23 + V_34 - V_31 -> V_33 . V_23 . V_37 . V_23 ;
for ( V_32 = 0 ; V_34 < V_36 - V_34 ; V_32 ++ )
V_34 += V_34 ;
for (; V_32 >= 0 ; V_34 = V_34 >> 1 , V_32 -- ) {
if ( V_36 < V_34 )
continue;
V_31 -> V_33 . V_23 . V_37 . V_23 += V_34 ;
V_31 -> V_38 += 1 << V_32 ;
V_36 -= V_34 ;
}
}
}
static inline T_1 F_24 ( struct V_1 * V_9 )
{
return V_9 -> V_39 + V_9 -> V_40 ;
}
static inline T_1 F_25 ( struct V_1 * V_9 )
{
return V_9 -> V_39 ;
}
static int
F_26 ( const T_2 V_8 , struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( ! error ) {
V_16 -> V_20 = 0 ;
V_16 -> V_22 = ( ( V_21 + V_41 - 1 ) / V_41 ) ;
if ( F_8 ( V_8 ) == V_19 ) {
V_16 -> V_22 = 1 ;
}
}
return error ;
}
static int
F_27 ( const T_2 V_8 , const struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( error == 0 ) {
error = - V_42 ;
}
return error ;
}
static int F_28 ( const T_2 V_8 , struct V_1 * V_9 ,
union V_14 * V_23 )
{
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
V_23 -> V_23 = F_24 ( V_9 ) ;
break;
case V_43 :
V_23 -> V_23 = F_25 ( V_9 ) ;
break;
case V_19 :
V_23 -> V_18 = F_29 ( V_9 ) ;
break;
}
return 0 ;
}
void F_30 ( struct V_1 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_44 -> signal ;
struct V_1 * V_49 ;
V_46 -> V_39 = V_48 -> V_39 ;
V_46 -> V_40 = V_48 -> V_40 ;
V_46 -> V_50 = V_48 -> V_51 ;
F_9 () ;
if ( ! F_31 ( F_32 ( V_44 ) ) )
goto V_52;
V_49 = V_44 ;
do {
V_46 -> V_39 += V_49 -> V_39 ;
V_46 -> V_40 += V_49 -> V_40 ;
V_46 -> V_50 += F_29 ( V_49 ) ;
} while_each_thread(tsk, t) ;
void F_33 ( struct V_45 * V_28 , struct V_45 * V_29 )
{
if ( V_29 -> V_39 > V_28 -> V_39 )
V_28 -> V_39 = V_29 -> V_39 ;
if ( V_29 -> V_40 > V_28 -> V_40 )
V_28 -> V_40 = V_29 -> V_40 ;
if ( V_29 -> V_50 > V_28 -> V_50 )
V_28 -> V_50 = V_29 -> V_50 ;
}
void F_34 ( struct V_1 * V_44 , struct V_45 * V_46 )
{
struct F_34 * V_53 = & V_44 -> signal -> V_53 ;
struct V_45 V_54 ;
unsigned long V_55 ;
if ( ! V_53 -> V_56 ) {
F_30 ( V_44 , & V_54 ) ;
F_35 ( & V_53 -> V_57 , V_55 ) ;
V_53 -> V_56 = 1 ;
F_33 ( & V_53 -> V_4 , & V_54 ) ;
} else
F_35 ( & V_53 -> V_57 , V_55 ) ;
* V_46 = V_53 -> V_4 ;
F_36 ( & V_53 -> V_57 , V_55 ) ;
}
static int F_37 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct V_45 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_30 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_39 + V_4 . V_40 ;
break;
case V_43 :
F_30 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_39 ;
break;
case V_19 :
F_30 ( V_9 , & V_4 ) ;
V_23 -> V_18 = V_4 . V_50 ;
break;
}
return 0 ;
}
static int F_38 ( const T_2 V_8 , struct V_15 * V_16 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int error = - V_12 ;
union V_14 V_58 ;
if ( V_10 == 0 ) {
if ( F_11 ( V_8 ) ) {
error = F_28 ( V_8 ,
V_13 , & V_58 ) ;
} else {
F_39 ( & V_59 ) ;
error = F_37 ( V_8 ,
V_13 , & V_58 ) ;
F_40 ( & V_59 ) ;
}
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 ) {
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_9 , V_13 ) ) {
error = F_28 ( V_8 ,
V_9 , & V_58 ) ;
}
} else {
F_39 ( & V_59 ) ;
if ( F_41 ( V_9 ) && V_9 -> V_5 ) {
error =
F_37 ( V_8 ,
V_9 , & V_58 ) ;
}
F_40 ( & V_59 ) ;
}
}
F_14 () ;
}
if ( error )
return error ;
F_17 ( V_8 , V_58 , V_16 ) ;
return 0 ;
}
static int F_42 ( struct V_30 * V_60 )
{
int V_17 = 0 ;
const T_3 V_10 = F_7 ( V_60 -> V_35 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_60 -> V_35 ) >= V_11 )
return - V_12 ;
F_43 ( & V_60 -> V_33 . V_23 . V_61 ) ;
F_9 () ;
if ( F_11 ( V_60 -> V_35 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_62 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_60 -> V_33 . V_23 . V_2 = V_9 ;
if ( V_9 ) {
F_44 ( V_9 ) ;
} else {
V_17 = - V_12 ;
}
F_14 () ;
return V_17 ;
}
static int F_45 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
int V_17 = 0 ;
if ( F_31 ( V_9 != NULL ) ) {
F_39 ( & V_59 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_47 ( ! F_48 ( & V_31 -> V_33 . V_23 . V_61 ) ) ;
} else {
F_49 ( & V_9 -> V_5 -> V_6 ) ;
if ( V_31 -> V_33 . V_23 . V_63 )
V_17 = V_64 ;
else
F_50 ( & V_31 -> V_33 . V_23 . V_61 ) ;
F_51 ( & V_9 -> V_5 -> V_6 ) ;
}
F_40 ( & V_59 ) ;
if ( ! V_17 )
F_52 ( V_9 ) ;
}
return V_17 ;
}
static void F_53 ( struct V_65 * V_66 ,
T_1 V_39 , T_1 V_40 ,
unsigned long long V_50 )
{
struct V_67 * V_31 , * V_68 ;
T_1 V_69 = V_39 + V_40 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_61 ) ;
if ( V_31 -> V_37 . V_23 < V_69 ) {
V_31 -> V_37 . V_23 = 0 ;
} else {
V_31 -> V_37 . V_23 -= V_69 ;
}
}
++ V_66 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_61 ) ;
if ( V_31 -> V_37 . V_23 < V_39 ) {
V_31 -> V_37 . V_23 = 0 ;
} else {
V_31 -> V_37 . V_23 -= V_39 ;
}
}
++ V_66 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_61 ) ;
if ( V_31 -> V_37 . V_18 < V_50 ) {
V_31 -> V_37 . V_18 = 0 ;
} else {
V_31 -> V_37 . V_18 -= V_50 ;
}
}
}
void F_56 ( struct V_1 * V_44 )
{
F_53 ( V_44 -> V_70 ,
V_44 -> V_39 , V_44 -> V_40 , V_44 -> V_71 . V_50 ) ;
}
void F_57 ( struct V_1 * V_44 )
{
struct V_47 * const V_48 = V_44 -> signal ;
F_53 ( V_44 -> signal -> V_70 ,
V_44 -> V_39 + V_48 -> V_39 , V_44 -> V_40 + V_48 -> V_40 ,
V_44 -> V_71 . V_50 + V_48 -> V_51 ) ;
}
static void F_58 ( struct V_30 * V_31 , union V_14 V_24 )
{
F_52 ( V_31 -> V_33 . V_23 . V_2 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
V_31 -> V_33 . V_23 . V_37 = F_22 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 ,
V_24 ) ;
}
static inline int F_59 ( T_1 V_37 , T_1 V_72 )
{
return V_37 == 0 || V_37 > V_72 ;
}
static void F_60 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
struct V_65 * V_66 , * V_73 ;
struct V_45 * V_74 ;
struct V_67 * const V_75 = & V_31 -> V_33 . V_23 ;
struct V_67 * V_68 ;
if ( F_11 ( V_31 -> V_35 ) ) {
V_66 = V_9 -> V_70 ;
V_74 = & V_9 -> V_74 ;
} else {
V_66 = V_9 -> signal -> V_70 ;
V_74 = & V_9 -> signal -> V_74 ;
}
V_66 += F_8 ( V_31 -> V_35 ) ;
V_73 = V_66 ;
F_61 (next, head, entry) {
if ( F_20 ( V_31 -> V_35 , V_75 -> V_37 , V_68 -> V_37 ) )
break;
V_73 = & V_68 -> V_61 ;
}
F_62 ( & V_75 -> V_61 , V_73 ) ;
if ( V_73 == V_66 ) {
union V_14 * exp = & V_75 -> V_37 ;
switch ( F_8 ( V_31 -> V_35 ) ) {
case V_7 :
if ( F_59 ( V_74 -> V_76 , exp -> V_23 ) )
V_74 -> V_76 = exp -> V_23 ;
break;
case V_43 :
if ( F_59 ( V_74 -> V_77 , exp -> V_23 ) )
V_74 -> V_77 = exp -> V_23 ;
break;
case V_19 :
if ( V_74 -> V_78 == 0 ||
V_74 -> V_78 > exp -> V_18 )
V_74 -> V_78 = exp -> V_18 ;
break;
}
}
}
static void F_63 ( struct V_30 * V_31 )
{
if ( ( V_31 -> V_79 & ~ V_80 ) == V_81 ) {
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( F_46 ( V_31 -> V_82 == NULL ) ) {
F_64 ( V_31 -> V_83 ) ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( V_31 -> V_33 . V_23 . V_34 . V_18 == 0 ) {
F_65 ( V_31 , 0 ) ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( F_65 ( V_31 , ++ V_31 -> V_84 ) ) {
F_66 ( V_31 ) ;
}
}
static int F_67 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct V_45 V_4 ;
F_34 ( V_9 , & V_4 ) ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
V_23 -> V_23 = V_4 . V_39 + V_4 . V_40 ;
break;
case V_43 :
V_23 -> V_23 = V_4 . V_39 ;
break;
case V_19 :
V_23 -> V_18 = V_4 . V_50 + F_68 ( V_9 ) ;
break;
}
return 0 ;
}
static int F_69 ( struct V_30 * V_31 , int V_55 ,
struct V_85 * V_86 , struct V_85 * V_87 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
union V_14 V_88 , V_89 , V_90 , V_27 ;
int V_17 ;
if ( F_46 ( V_9 == NULL ) ) {
return - V_91 ;
}
V_89 = F_15 ( V_31 -> V_35 , & V_86 -> V_92 ) ;
F_39 ( & V_59 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_40 ( & V_59 ) ;
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
return - V_91 ;
}
F_47 ( ! F_70 () ) ;
V_17 = 0 ;
V_90 = V_31 -> V_33 . V_23 . V_34 ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
V_88 = V_31 -> V_33 . V_23 . V_37 ;
if ( F_46 ( V_31 -> V_33 . V_23 . V_63 ) ) {
V_31 -> V_33 . V_23 . V_63 = - 1 ;
V_17 = V_64 ;
} else
F_55 ( & V_31 -> V_33 . V_23 . V_61 ) ;
if ( F_11 ( V_31 -> V_35 ) ) {
F_28 ( V_31 -> V_35 , V_9 , & V_27 ) ;
} else {
F_67 ( V_31 -> V_35 , V_9 , & V_27 ) ;
}
if ( V_87 ) {
if ( V_88 . V_18 == 0 ) {
V_87 -> V_92 . V_20 = 0 ;
V_87 -> V_92 . V_22 = 0 ;
} else {
F_23 ( V_31 , V_27 ) ;
if ( F_20 ( V_31 -> V_35 , V_27 ,
V_31 -> V_33 . V_23 . V_37 ) ) {
V_88 = F_22 (
V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 , V_27 ) ;
F_17 ( V_31 -> V_35 ,
V_88 ,
& V_87 -> V_92 ) ;
} else {
V_87 -> V_92 . V_22 = 1 ;
V_87 -> V_92 . V_20 = 0 ;
}
}
}
if ( F_46 ( V_17 ) ) {
F_51 ( & V_9 -> V_5 -> V_6 ) ;
F_40 ( & V_59 ) ;
goto V_52;
}
if ( V_89 . V_18 != 0 && ! ( V_55 & V_93 ) ) {
F_21 ( V_31 -> V_35 , & V_89 , V_27 ) ;
}
V_31 -> V_33 . V_23 . V_37 = V_89 ;
if ( V_89 . V_18 != 0 &&
F_20 ( V_31 -> V_35 , V_27 , V_89 ) ) {
F_60 ( V_31 ) ;
}
F_51 ( & V_9 -> V_5 -> V_6 ) ;
F_40 ( & V_59 ) ;
V_31 -> V_33 . V_23 . V_34 = F_15 ( V_31 -> V_35 ,
& V_86 -> V_94 ) ;
V_31 -> V_84 = ( V_31 -> V_84 + 2 ) &
~ V_95 ;
V_31 -> V_96 = 0 ;
V_31 -> V_38 = - 1 ;
if ( V_89 . V_18 != 0 &&
! F_20 ( V_31 -> V_35 , V_27 , V_89 ) ) {
F_63 ( V_31 ) ;
}
V_17 = 0 ;
V_52:
if ( V_87 ) {
F_17 ( V_31 -> V_35 ,
V_90 , & V_87 -> V_94 ) ;
}
return V_17 ;
}
static void F_71 ( struct V_30 * V_31 , struct V_85 * V_97 )
{
union V_14 V_24 ;
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
int V_98 ;
F_17 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_34 , & V_97 -> V_94 ) ;
if ( V_31 -> V_33 . V_23 . V_37 . V_18 == 0 ) {
V_97 -> V_92 . V_20 = V_97 -> V_92 . V_22 = 0 ;
return;
}
if ( F_46 ( V_9 == NULL ) ) {
V_99:
F_17 ( V_31 -> V_35 , V_31 -> V_33 . V_23 . V_37 ,
& V_97 -> V_92 ) ;
return;
}
if ( F_11 ( V_31 -> V_35 ) ) {
F_28 ( V_31 -> V_35 , V_9 , & V_24 ) ;
V_98 = V_9 -> V_100 ;
} else {
F_39 ( & V_59 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
F_40 ( & V_59 ) ;
goto V_99;
} else {
F_67 ( V_31 -> V_35 , V_9 , & V_24 ) ;
V_98 = ( F_46 ( V_9 -> V_100 ) &&
F_72 ( V_9 ) ) ;
}
F_40 ( & V_59 ) ;
}
if ( F_46 ( V_98 ) ) {
F_58 ( V_31 , V_24 ) ;
goto V_99;
}
if ( F_20 ( V_31 -> V_35 , V_24 , V_31 -> V_33 . V_23 . V_37 ) ) {
F_17 ( V_31 -> V_35 ,
F_22 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 , V_24 ) ,
& V_97 -> V_92 ) ;
} else {
V_97 -> V_92 . V_22 = 1 ;
V_97 -> V_92 . V_20 = 0 ;
}
}
static void F_73 ( struct V_1 * V_44 ,
struct V_65 * V_63 )
{
int V_101 ;
struct V_65 * V_102 = V_44 -> V_70 ;
struct V_47 * const V_48 = V_44 -> signal ;
unsigned long V_103 ;
V_101 = 20 ;
V_44 -> V_74 . V_76 = 0 ;
while ( ! F_48 ( V_102 ) ) {
struct V_67 * V_49 = F_74 ( V_102 ,
struct V_67 ,
V_61 ) ;
if ( ! -- V_101 || F_24 ( V_44 ) < V_49 -> V_37 . V_23 ) {
V_44 -> V_74 . V_76 = V_49 -> V_37 . V_23 ;
break;
}
V_49 -> V_63 = 1 ;
F_75 ( & V_49 -> V_61 , V_63 ) ;
}
++ V_102 ;
V_101 = 20 ;
V_44 -> V_74 . V_77 = 0 ;
while ( ! F_48 ( V_102 ) ) {
struct V_67 * V_49 = F_74 ( V_102 ,
struct V_67 ,
V_61 ) ;
if ( ! -- V_101 || F_25 ( V_44 ) < V_49 -> V_37 . V_23 ) {
V_44 -> V_74 . V_77 = V_49 -> V_37 . V_23 ;
break;
}
V_49 -> V_63 = 1 ;
F_75 ( & V_49 -> V_61 , V_63 ) ;
}
++ V_102 ;
V_101 = 20 ;
V_44 -> V_74 . V_78 = 0 ;
while ( ! F_48 ( V_102 ) ) {
struct V_67 * V_49 = F_74 ( V_102 ,
struct V_67 ,
V_61 ) ;
if ( ! -- V_101 || V_44 -> V_71 . V_50 < V_49 -> V_37 . V_18 ) {
V_44 -> V_74 . V_78 = V_49 -> V_37 . V_18 ;
break;
}
V_49 -> V_63 = 1 ;
F_75 ( & V_49 -> V_61 , V_63 ) ;
}
V_103 = F_76 ( V_48 -> V_104 [ V_105 ] . V_106 ) ;
if ( V_103 != V_107 ) {
unsigned long V_108 =
F_76 ( V_48 -> V_104 [ V_105 ] . V_109 ) ;
if ( V_108 != V_107 &&
V_44 -> V_110 . V_111 > F_77 ( V_108 , V_112 / V_41 ) ) {
F_78 ( V_113 , V_114 , V_44 ) ;
return;
}
if ( V_44 -> V_110 . V_111 > F_77 ( V_103 , V_112 / V_41 ) ) {
if ( V_103 < V_108 ) {
V_103 += V_112 ;
V_48 -> V_104 [ V_105 ] . V_106 = V_103 ;
}
F_79 ( V_115
L_1 ,
V_44 -> V_116 , F_80 ( V_44 ) ) ;
F_78 ( V_117 , V_114 , V_44 ) ;
}
}
}
static void F_81 ( struct V_47 * V_48 )
{
struct F_34 * V_53 = & V_48 -> V_53 ;
unsigned long V_55 ;
F_35 ( & V_53 -> V_57 , V_55 ) ;
V_53 -> V_56 = 0 ;
F_36 ( & V_53 -> V_57 , V_55 ) ;
}
static void F_82 ( struct V_1 * V_44 , struct V_118 * V_33 ,
T_1 * V_37 , T_1 V_119 , int V_120 )
{
if ( ! V_33 -> V_37 )
return;
if ( V_119 >= V_33 -> V_37 ) {
if ( V_33 -> V_34 ) {
V_33 -> V_37 += V_33 -> V_34 ;
V_33 -> error += V_33 -> V_121 ;
if ( V_33 -> error >= V_122 ) {
V_33 -> V_37 -= V_123 ;
V_33 -> error -= V_122 ;
}
} else {
V_33 -> V_37 = 0 ;
}
F_83 ( V_120 == V_124 ?
V_125 : V_126 ,
V_44 -> signal -> V_127 , V_119 ) ;
F_78 ( V_120 , V_114 , V_44 ) ;
}
if ( V_33 -> V_37 && ( ! * V_37 || V_33 -> V_37 < * V_37 ) ) {
* V_37 = V_33 -> V_37 ;
}
}
static inline int F_84 ( const struct V_45 * V_4 )
{
if ( ! V_4 -> V_39 && ! V_4 -> V_40 && ! V_4 -> V_50 )
return 1 ;
return 0 ;
}
static void F_85 ( struct V_1 * V_44 ,
struct V_65 * V_63 )
{
int V_101 ;
struct V_47 * const V_48 = V_44 -> signal ;
T_1 V_39 , V_69 , V_128 , V_129 ;
unsigned long long V_51 , V_130 ;
struct V_65 * V_102 = V_48 -> V_70 ;
struct V_45 V_4 ;
unsigned long V_103 ;
F_34 ( V_44 , & V_4 ) ;
V_39 = V_4 . V_39 ;
V_69 = V_39 + V_4 . V_40 ;
V_51 = V_4 . V_50 ;
V_101 = 20 ;
V_129 = 0 ;
while ( ! F_48 ( V_102 ) ) {
struct V_67 * V_131 = F_74 ( V_102 ,
struct V_67 ,
V_61 ) ;
if ( ! -- V_101 || V_69 < V_131 -> V_37 . V_23 ) {
V_129 = V_131 -> V_37 . V_23 ;
break;
}
V_131 -> V_63 = 1 ;
F_75 ( & V_131 -> V_61 , V_63 ) ;
}
++ V_102 ;
V_101 = 20 ;
V_128 = 0 ;
while ( ! F_48 ( V_102 ) ) {
struct V_67 * V_131 = F_74 ( V_102 ,
struct V_67 ,
V_61 ) ;
if ( ! -- V_101 || V_39 < V_131 -> V_37 . V_23 ) {
V_128 = V_131 -> V_37 . V_23 ;
break;
}
V_131 -> V_63 = 1 ;
F_75 ( & V_131 -> V_61 , V_63 ) ;
}
++ V_102 ;
V_101 = 20 ;
V_130 = 0 ;
while ( ! F_48 ( V_102 ) ) {
struct V_67 * V_131 = F_74 ( V_102 ,
struct V_67 ,
V_61 ) ;
if ( ! -- V_101 || V_51 < V_131 -> V_37 . V_18 ) {
V_130 = V_131 -> V_37 . V_18 ;
break;
}
V_131 -> V_63 = 1 ;
F_75 ( & V_131 -> V_61 , V_63 ) ;
}
F_82 ( V_44 , & V_48 -> V_33 [ V_7 ] , & V_129 , V_69 ,
V_124 ) ;
F_82 ( V_44 , & V_48 -> V_33 [ V_43 ] , & V_128 , V_39 ,
V_132 ) ;
V_103 = F_76 ( V_48 -> V_104 [ V_133 ] . V_106 ) ;
if ( V_103 != V_107 ) {
unsigned long V_134 = F_86 ( V_69 ) ;
unsigned long V_108 =
F_76 ( V_48 -> V_104 [ V_133 ] . V_109 ) ;
T_1 V_135 ;
if ( V_134 >= V_108 ) {
F_78 ( V_113 , V_114 , V_44 ) ;
return;
}
if ( V_134 >= V_103 ) {
F_78 ( V_117 , V_114 , V_44 ) ;
if ( V_103 < V_108 ) {
V_103 ++ ;
V_48 -> V_104 [ V_133 ] . V_106 = V_103 ;
}
}
V_135 = F_2 ( V_103 ) ;
if ( ! V_129 || V_135 < V_129 ) {
V_129 = V_135 ;
}
}
V_48 -> V_74 . V_76 = V_129 ;
V_48 -> V_74 . V_77 = V_128 ;
V_48 -> V_74 . V_78 = V_130 ;
if ( F_84 ( & V_48 -> V_74 ) )
F_81 ( V_48 ) ;
}
void F_66 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
union V_14 V_24 ;
if ( F_46 ( V_9 == NULL ) )
goto V_52;
if ( F_11 ( V_31 -> V_35 ) ) {
F_28 ( V_31 -> V_35 , V_9 , & V_24 ) ;
F_23 ( V_31 , V_24 ) ;
if ( F_46 ( V_9 -> V_100 ) ) {
F_58 ( V_31 , V_24 ) ;
goto V_52;
}
F_39 ( & V_59 ) ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
} else {
F_39 ( & V_59 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = V_9 = NULL ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
goto V_136;
} else if ( F_46 ( V_9 -> V_100 ) && F_72 ( V_9 ) ) {
F_58 ( V_31 , V_24 ) ;
goto V_136;
}
F_49 ( & V_9 -> V_5 -> V_6 ) ;
F_67 ( V_31 -> V_35 , V_9 , & V_24 ) ;
F_23 ( V_31 , V_24 ) ;
}
F_47 ( ! F_70 () ) ;
F_60 ( V_31 ) ;
F_51 ( & V_9 -> V_5 -> V_6 ) ;
V_136:
F_40 ( & V_59 ) ;
V_52:
V_31 -> V_96 = V_31 -> V_38 ;
V_31 -> V_38 = - 1 ;
++ V_31 -> V_84 ;
}
static inline int F_87 ( const struct V_45 * V_137 ,
const struct V_45 * V_37 )
{
if ( V_37 -> V_39 && V_137 -> V_39 >= V_37 -> V_39 )
return 1 ;
if ( V_37 -> V_40 && V_137 -> V_39 + V_137 -> V_40 >= V_37 -> V_40 )
return 1 ;
if ( V_37 -> V_50 != 0 &&
V_137 -> V_50 >= V_37 -> V_50 )
return 1 ;
return 0 ;
}
static inline int F_88 ( struct V_1 * V_44 )
{
struct V_47 * V_48 ;
if ( ! F_84 ( & V_44 -> V_74 ) ) {
struct V_45 V_138 = {
. V_39 = V_44 -> V_39 ,
. V_40 = V_44 -> V_40 ,
. V_50 = V_44 -> V_71 . V_50
} ;
if ( F_87 ( & V_138 , & V_44 -> V_74 ) )
return 1 ;
}
V_48 = V_44 -> signal ;
if ( V_48 -> V_53 . V_56 ) {
struct V_45 V_139 ;
F_89 ( & V_48 -> V_53 . V_57 ) ;
V_139 = V_48 -> V_53 . V_4 ;
F_90 ( & V_48 -> V_53 . V_57 ) ;
if ( F_87 ( & V_139 , & V_48 -> V_74 ) )
return 1 ;
}
return 0 ;
}
void F_91 ( struct V_1 * V_44 )
{
F_92 ( V_63 ) ;
struct V_30 * V_31 , * V_68 ;
unsigned long V_55 ;
F_47 ( ! F_70 () ) ;
if ( ! F_88 ( V_44 ) )
return;
if ( ! F_93 ( V_44 , & V_55 ) )
return;
F_73 ( V_44 , & V_63 ) ;
if ( V_44 -> signal -> V_53 . V_56 )
F_85 ( V_44 , & V_63 ) ;
F_94 ( V_44 , & V_55 ) ;
F_54 (timer, next, &firing, it.cpu.entry) {
int V_140 ;
F_49 ( & V_31 -> V_141 ) ;
F_55 ( & V_31 -> V_33 . V_23 . V_61 ) ;
V_140 = V_31 -> V_33 . V_23 . V_63 ;
V_31 -> V_33 . V_23 . V_63 = 0 ;
if ( F_31 ( V_140 >= 0 ) )
F_63 ( V_31 ) ;
F_51 ( & V_31 -> V_141 ) ;
}
}
void F_4 ( struct V_1 * V_44 , unsigned int V_142 ,
T_1 * V_143 , T_1 * V_144 )
{
union V_14 V_24 ;
F_47 ( V_142 == V_19 ) ;
F_67 ( V_142 , V_44 , & V_24 ) ;
if ( V_144 ) {
if ( * V_144 ) {
if ( * V_144 <= V_24 . V_23 ) {
* V_144 = V_123 ;
} else {
* V_144 -= V_24 . V_23 ;
}
}
if ( ! * V_143 )
return;
* V_143 += V_24 . V_23 ;
}
switch ( V_142 ) {
case V_7 :
if ( F_59 ( V_44 -> signal -> V_74 . V_76 , * V_143 ) )
V_44 -> signal -> V_74 . V_76 = * V_143 ;
break;
case V_43 :
if ( F_59 ( V_44 -> signal -> V_74 . V_77 , * V_143 ) )
V_44 -> signal -> V_74 . V_77 = * V_143 ;
break;
}
}
static int F_95 ( const T_2 V_8 , int V_55 ,
struct V_15 * V_145 , struct V_85 * V_33 )
{
struct V_30 V_31 ;
int error ;
memset ( & V_31 , 0 , sizeof V_31 ) ;
F_96 ( & V_31 . V_141 ) ;
V_31 . V_35 = V_8 ;
V_31 . V_38 = - 1 ;
error = F_42 ( & V_31 ) ;
V_31 . V_83 = V_13 ;
if ( ! error ) {
static struct V_85 V_146 ;
memset ( V_33 , 0 , sizeof *V_33 ) ;
V_33 -> V_92 = * V_145 ;
F_3 ( & V_31 . V_141 ) ;
error = F_69 ( & V_31 , V_55 , V_33 , NULL ) ;
if ( error ) {
F_5 ( & V_31 . V_141 ) ;
return error ;
}
while ( ! F_97 ( V_13 ) ) {
if ( V_31 . V_33 . V_23 . V_37 . V_18 == 0 ) {
F_5 ( & V_31 . V_141 ) ;
return 0 ;
}
F_98 ( V_147 ) ;
F_5 ( & V_31 . V_141 ) ;
F_99 () ;
F_3 ( & V_31 . V_141 ) ;
}
F_17 ( V_8 , V_31 . V_33 . V_23 . V_37 , V_145 ) ;
F_69 ( & V_31 , 0 , & V_146 , V_33 ) ;
F_5 ( & V_31 . V_141 ) ;
if ( ( V_33 -> V_92 . V_20 | V_33 -> V_92 . V_22 ) == 0 ) {
return 0 ;
}
error = - V_148 ;
}
return error ;
}
static int F_100 ( const T_2 V_8 , int V_55 ,
struct V_15 * V_145 , struct V_15 T_4 * V_149 )
{
struct V_150 * V_150 =
& F_101 () -> V_150 ;
struct V_85 V_33 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_95 ( V_8 , V_55 , V_145 , & V_33 ) ;
if ( error == - V_148 ) {
if ( V_55 & V_93 )
return - V_151 ;
if ( V_149 && F_102 ( V_149 , & V_33 . V_92 , sizeof *V_149 ) )
return - V_152 ;
V_150 -> V_153 = V_154 ;
V_150 -> V_155 . V_156 = V_8 ;
V_150 -> V_155 . V_149 = V_149 ;
V_150 -> V_155 . V_37 = F_103 ( V_145 ) ;
}
return error ;
}
static long V_154 ( struct V_150 * V_150 )
{
T_2 V_8 = V_150 -> V_155 . V_156 ;
struct V_15 V_49 ;
struct V_85 V_33 ;
int error ;
V_49 = F_18 ( V_150 -> V_155 . V_37 ) ;
error = F_95 ( V_8 , V_93 , & V_49 , & V_33 ) ;
if ( error == - V_148 ) {
struct V_15 T_4 * V_149 = V_150 -> V_155 . V_149 ;
if ( V_149 && F_102 ( V_149 , & V_33 . V_92 , sizeof *V_149 ) )
return - V_152 ;
V_150 -> V_155 . V_37 = F_103 ( & V_49 ) ;
}
return error ;
}
static int F_104 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_26 ( V_157 , V_16 ) ;
}
static int F_105 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_38 ( V_157 , V_16 ) ;
}
static int F_106 ( struct V_30 * V_31 )
{
V_31 -> V_35 = V_157 ;
return F_42 ( V_31 ) ;
}
static int F_107 ( const T_2 V_8 , int V_55 ,
struct V_15 * V_145 ,
struct V_15 T_4 * V_149 )
{
return F_100 ( V_157 , V_55 , V_145 , V_149 ) ;
}
static long F_108 ( struct V_150 * V_150 )
{
return - V_12 ;
}
static int F_109 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_26 ( V_158 , V_16 ) ;
}
static int F_110 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_38 ( V_158 , V_16 ) ;
}
static int F_111 ( struct V_30 * V_31 )
{
V_31 -> V_35 = V_158 ;
return F_42 ( V_31 ) ;
}
static T_5 int F_112 ( void )
{
struct V_159 V_160 = {
. V_161 = F_104 ,
. V_162 = F_105 ,
. V_163 = F_106 ,
. V_164 = F_107 ,
. V_165 = F_108 ,
} ;
struct V_159 V_166 = {
. V_161 = F_109 ,
. V_162 = F_110 ,
. V_163 = F_111 ,
} ;
struct V_15 V_167 ;
F_113 ( V_168 , & V_160 ) ;
F_113 ( V_169 , & V_166 ) ;
F_19 ( V_123 , & V_167 ) ;
V_122 = V_167 . V_22 ;
F_114 ( V_167 . V_20 != 0 ) ;
return 0 ;
}
