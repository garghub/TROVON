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
static inline int F_24 ( const struct V_39 * V_4 )
{
if ( ! V_4 -> V_40 && ! V_4 -> V_41 && ! V_4 -> V_42 )
return 1 ;
return 0 ;
}
static inline T_1 F_25 ( struct V_1 * V_9 )
{
T_1 V_40 , V_41 ;
V_39 ( V_9 , & V_40 , & V_41 ) ;
return V_40 + V_41 ;
}
static inline T_1 F_26 ( struct V_1 * V_9 )
{
T_1 V_40 ;
V_39 ( V_9 , & V_40 , NULL ) ;
return V_40 ;
}
static int
F_27 ( const T_2 V_8 , struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( ! error ) {
V_16 -> V_20 = 0 ;
V_16 -> V_22 = ( ( V_21 + V_43 - 1 ) / V_43 ) ;
if ( F_8 ( V_8 ) == V_19 ) {
V_16 -> V_22 = 1 ;
}
}
return error ;
}
static int
F_28 ( const T_2 V_8 , const struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( error == 0 ) {
error = - V_44 ;
}
return error ;
}
static int F_29 ( const T_2 V_8 , struct V_1 * V_9 ,
union V_14 * V_23 )
{
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
V_23 -> V_23 = F_25 ( V_9 ) ;
break;
case V_45 :
V_23 -> V_23 = F_26 ( V_9 ) ;
break;
case V_19 :
V_23 -> V_18 = F_30 ( V_9 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_39 * V_28 , struct V_39 * V_29 )
{
if ( V_29 -> V_40 > V_28 -> V_40 )
V_28 -> V_40 = V_29 -> V_40 ;
if ( V_29 -> V_41 > V_28 -> V_41 )
V_28 -> V_41 = V_29 -> V_41 ;
if ( V_29 -> V_42 > V_28 -> V_42 )
V_28 -> V_42 = V_29 -> V_42 ;
}
void F_32 ( struct V_1 * V_46 , struct V_39 * V_47 )
{
struct F_32 * V_48 = & V_46 -> signal -> V_48 ;
struct V_39 V_49 ;
unsigned long V_50 ;
if ( ! V_48 -> V_51 ) {
F_33 ( V_46 , & V_49 ) ;
F_34 ( & V_48 -> V_52 , V_50 ) ;
V_48 -> V_51 = 1 ;
F_31 ( & V_48 -> V_4 , & V_49 ) ;
} else
F_34 ( & V_48 -> V_52 , V_50 ) ;
* V_47 = V_48 -> V_4 ;
F_35 ( & V_48 -> V_52 , V_50 ) ;
}
static int F_36 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct V_39 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_33 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_40 + V_4 . V_41 ;
break;
case V_45 :
F_33 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_40 ;
break;
case V_19 :
F_33 ( V_9 , & V_4 ) ;
V_23 -> V_18 = V_4 . V_42 ;
break;
}
return 0 ;
}
static int F_37 ( const T_2 V_8 , struct V_15 * V_16 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int error = - V_12 ;
union V_14 V_53 ;
if ( V_10 == 0 ) {
if ( F_11 ( V_8 ) ) {
error = F_29 ( V_8 ,
V_13 , & V_53 ) ;
} else {
F_38 ( & V_54 ) ;
error = F_36 ( V_8 ,
V_13 , & V_53 ) ;
F_39 ( & V_54 ) ;
}
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 ) {
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_9 , V_13 ) ) {
error = F_29 ( V_8 ,
V_9 , & V_53 ) ;
}
} else {
F_38 ( & V_54 ) ;
if ( F_40 ( V_9 ) && V_9 -> V_5 ) {
error =
F_36 ( V_8 ,
V_9 , & V_53 ) ;
}
F_39 ( & V_54 ) ;
}
}
F_14 () ;
}
if ( error )
return error ;
F_17 ( V_8 , V_53 , V_16 ) ;
return 0 ;
}
static int F_41 ( struct V_30 * V_55 )
{
int V_17 = 0 ;
const T_3 V_10 = F_7 ( V_55 -> V_35 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_55 -> V_35 ) >= V_11 )
return - V_12 ;
F_42 ( & V_55 -> V_33 . V_23 . V_56 ) ;
F_9 () ;
if ( F_11 ( V_55 -> V_35 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_57 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_55 -> V_33 . V_23 . V_2 = V_9 ;
if ( V_9 ) {
F_43 ( V_9 ) ;
} else {
V_17 = - V_12 ;
}
F_14 () ;
return V_17 ;
}
static int F_44 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
int V_17 = 0 ;
if ( F_45 ( V_9 != NULL ) ) {
F_38 ( & V_54 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_47 ( ! F_48 ( & V_31 -> V_33 . V_23 . V_56 ) ) ;
} else {
F_49 ( & V_9 -> V_5 -> V_6 ) ;
if ( V_31 -> V_33 . V_23 . V_58 )
V_17 = V_59 ;
else
F_50 ( & V_31 -> V_33 . V_23 . V_56 ) ;
F_51 ( & V_9 -> V_5 -> V_6 ) ;
}
F_39 ( & V_54 ) ;
if ( ! V_17 )
F_52 ( V_9 ) ;
}
return V_17 ;
}
static void F_53 ( struct V_60 * V_61 ,
T_1 V_40 , T_1 V_41 ,
unsigned long long V_42 )
{
struct V_62 * V_31 , * V_63 ;
T_1 V_64 = V_40 + V_41 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_56 ) ;
if ( V_31 -> V_37 . V_23 < V_64 ) {
V_31 -> V_37 . V_23 = 0 ;
} else {
V_31 -> V_37 . V_23 -= V_64 ;
}
}
++ V_61 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_56 ) ;
if ( V_31 -> V_37 . V_23 < V_40 ) {
V_31 -> V_37 . V_23 = 0 ;
} else {
V_31 -> V_37 . V_23 -= V_40 ;
}
}
++ V_61 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_56 ) ;
if ( V_31 -> V_37 . V_18 < V_42 ) {
V_31 -> V_37 . V_18 = 0 ;
} else {
V_31 -> V_37 . V_18 -= V_42 ;
}
}
}
void F_56 ( struct V_1 * V_46 )
{
T_1 V_40 , V_41 ;
F_57 ( ( const void * ) & V_46 -> V_65 . V_42 ,
sizeof( unsigned long long ) ) ;
V_39 ( V_46 , & V_40 , & V_41 ) ;
F_53 ( V_46 -> V_66 ,
V_40 , V_41 , V_46 -> V_65 . V_42 ) ;
}
void F_58 ( struct V_1 * V_46 )
{
struct V_67 * const V_68 = V_46 -> signal ;
T_1 V_40 , V_41 ;
V_39 ( V_46 , & V_40 , & V_41 ) ;
F_53 ( V_46 -> signal -> V_66 ,
V_40 + V_68 -> V_40 , V_41 + V_68 -> V_41 ,
V_46 -> V_65 . V_42 + V_68 -> V_69 ) ;
}
static void F_59 ( struct V_30 * V_31 , union V_14 V_24 )
{
F_52 ( V_31 -> V_33 . V_23 . V_2 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
V_31 -> V_33 . V_23 . V_37 = F_22 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 ,
V_24 ) ;
}
static inline int F_60 ( T_1 V_37 , T_1 V_70 )
{
return V_37 == 0 || V_37 > V_70 ;
}
static void F_61 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
struct V_60 * V_61 , * V_71 ;
struct V_39 * V_72 ;
struct V_62 * const V_73 = & V_31 -> V_33 . V_23 ;
struct V_62 * V_63 ;
if ( F_11 ( V_31 -> V_35 ) ) {
V_61 = V_9 -> V_66 ;
V_72 = & V_9 -> V_72 ;
} else {
V_61 = V_9 -> signal -> V_66 ;
V_72 = & V_9 -> signal -> V_72 ;
}
V_61 += F_8 ( V_31 -> V_35 ) ;
V_71 = V_61 ;
F_62 (next, head, entry) {
if ( F_20 ( V_31 -> V_35 , V_73 -> V_37 , V_63 -> V_37 ) )
break;
V_71 = & V_63 -> V_56 ;
}
F_63 ( & V_73 -> V_56 , V_71 ) ;
if ( V_71 == V_61 ) {
union V_14 * exp = & V_73 -> V_37 ;
switch ( F_8 ( V_31 -> V_35 ) ) {
case V_7 :
if ( F_60 ( V_72 -> V_74 , exp -> V_23 ) )
V_72 -> V_74 = exp -> V_23 ;
break;
case V_45 :
if ( F_60 ( V_72 -> V_75 , exp -> V_23 ) )
V_72 -> V_75 = exp -> V_23 ;
break;
case V_19 :
if ( V_72 -> V_76 == 0 ||
V_72 -> V_76 > exp -> V_18 )
V_72 -> V_76 = exp -> V_18 ;
break;
}
}
}
static void F_64 ( struct V_30 * V_31 )
{
if ( ( V_31 -> V_77 & ~ V_78 ) == V_79 ) {
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( F_46 ( V_31 -> V_80 == NULL ) ) {
F_65 ( V_31 -> V_81 ) ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( V_31 -> V_33 . V_23 . V_34 . V_18 == 0 ) {
F_66 ( V_31 , 0 ) ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( F_66 ( V_31 , ++ V_31 -> V_82 ) ) {
F_67 ( V_31 ) ;
}
}
static int F_68 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct V_39 V_4 ;
F_32 ( V_9 , & V_4 ) ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
V_23 -> V_23 = V_4 . V_40 + V_4 . V_41 ;
break;
case V_45 :
V_23 -> V_23 = V_4 . V_40 ;
break;
case V_19 :
V_23 -> V_18 = V_4 . V_42 + F_69 ( V_9 ) ;
break;
}
return 0 ;
}
static void F_70 ( struct V_83 * V_84 )
{
F_71 () ;
}
static void F_72 ( void )
{
F_73 ( & V_85 ) ;
}
bool F_74 ( struct V_1 * V_46 )
{
if ( ! F_24 ( & V_46 -> V_72 ) )
return false ;
if ( V_46 -> signal -> V_48 . V_51 )
return false ;
return true ;
}
static inline void F_72 ( void ) { }
static int F_75 ( struct V_30 * V_31 , int V_50 ,
struct V_86 * V_87 , struct V_86 * V_88 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
union V_14 V_89 , V_90 , V_91 , V_27 ;
int V_17 ;
if ( F_46 ( V_9 == NULL ) ) {
return - V_92 ;
}
V_90 = F_15 ( V_31 -> V_35 , & V_87 -> V_93 ) ;
F_38 ( & V_54 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_39 ( & V_54 ) ;
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
return - V_92 ;
}
F_47 ( ! F_76 () ) ;
V_17 = 0 ;
V_91 = V_31 -> V_33 . V_23 . V_34 ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
V_89 = V_31 -> V_33 . V_23 . V_37 ;
if ( F_46 ( V_31 -> V_33 . V_23 . V_58 ) ) {
V_31 -> V_33 . V_23 . V_58 = - 1 ;
V_17 = V_59 ;
} else
F_55 ( & V_31 -> V_33 . V_23 . V_56 ) ;
if ( F_11 ( V_31 -> V_35 ) ) {
F_29 ( V_31 -> V_35 , V_9 , & V_27 ) ;
} else {
F_68 ( V_31 -> V_35 , V_9 , & V_27 ) ;
}
if ( V_88 ) {
if ( V_89 . V_18 == 0 ) {
V_88 -> V_93 . V_20 = 0 ;
V_88 -> V_93 . V_22 = 0 ;
} else {
F_23 ( V_31 , V_27 ) ;
if ( F_20 ( V_31 -> V_35 , V_27 ,
V_31 -> V_33 . V_23 . V_37 ) ) {
V_89 = F_22 (
V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 , V_27 ) ;
F_17 ( V_31 -> V_35 ,
V_89 ,
& V_88 -> V_93 ) ;
} else {
V_88 -> V_93 . V_22 = 1 ;
V_88 -> V_93 . V_20 = 0 ;
}
}
}
if ( F_46 ( V_17 ) ) {
F_51 ( & V_9 -> V_5 -> V_6 ) ;
F_39 ( & V_54 ) ;
goto V_94;
}
if ( V_90 . V_18 != 0 && ! ( V_50 & V_95 ) ) {
F_21 ( V_31 -> V_35 , & V_90 , V_27 ) ;
}
V_31 -> V_33 . V_23 . V_37 = V_90 ;
if ( V_90 . V_18 != 0 &&
F_20 ( V_31 -> V_35 , V_27 , V_90 ) ) {
F_61 ( V_31 ) ;
}
F_51 ( & V_9 -> V_5 -> V_6 ) ;
F_39 ( & V_54 ) ;
V_31 -> V_33 . V_23 . V_34 = F_15 ( V_31 -> V_35 ,
& V_87 -> V_96 ) ;
V_31 -> V_82 = ( V_31 -> V_82 + 2 ) &
~ V_97 ;
V_31 -> V_98 = 0 ;
V_31 -> V_38 = - 1 ;
if ( V_90 . V_18 != 0 &&
! F_20 ( V_31 -> V_35 , V_27 , V_90 ) ) {
F_64 ( V_31 ) ;
}
V_17 = 0 ;
V_94:
if ( V_88 ) {
F_17 ( V_31 -> V_35 ,
V_91 , & V_88 -> V_96 ) ;
}
if ( ! V_17 )
F_72 () ;
return V_17 ;
}
static void F_77 ( struct V_30 * V_31 , struct V_86 * V_99 )
{
union V_14 V_24 ;
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
int V_100 ;
F_17 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_34 , & V_99 -> V_96 ) ;
if ( V_31 -> V_33 . V_23 . V_37 . V_18 == 0 ) {
V_99 -> V_93 . V_20 = V_99 -> V_93 . V_22 = 0 ;
return;
}
if ( F_46 ( V_9 == NULL ) ) {
V_101:
F_17 ( V_31 -> V_35 , V_31 -> V_33 . V_23 . V_37 ,
& V_99 -> V_93 ) ;
return;
}
if ( F_11 ( V_31 -> V_35 ) ) {
F_29 ( V_31 -> V_35 , V_9 , & V_24 ) ;
V_100 = V_9 -> V_102 ;
} else {
F_38 ( & V_54 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
F_39 ( & V_54 ) ;
goto V_101;
} else {
F_68 ( V_31 -> V_35 , V_9 , & V_24 ) ;
V_100 = ( F_46 ( V_9 -> V_102 ) &&
F_78 ( V_9 ) ) ;
}
F_39 ( & V_54 ) ;
}
if ( F_46 ( V_100 ) ) {
F_59 ( V_31 , V_24 ) ;
goto V_101;
}
if ( F_20 ( V_31 -> V_35 , V_24 , V_31 -> V_33 . V_23 . V_37 ) ) {
F_17 ( V_31 -> V_35 ,
F_22 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 , V_24 ) ,
& V_99 -> V_93 ) ;
} else {
V_99 -> V_93 . V_22 = 1 ;
V_99 -> V_93 . V_20 = 0 ;
}
}
static void F_79 ( struct V_1 * V_46 ,
struct V_60 * V_58 )
{
int V_103 ;
struct V_60 * V_104 = V_46 -> V_66 ;
struct V_67 * const V_68 = V_46 -> signal ;
unsigned long V_105 ;
V_103 = 20 ;
V_46 -> V_72 . V_74 = 0 ;
while ( ! F_48 ( V_104 ) ) {
struct V_62 * V_106 = F_80 ( V_104 ,
struct V_62 ,
V_56 ) ;
if ( ! -- V_103 || F_25 ( V_46 ) < V_106 -> V_37 . V_23 ) {
V_46 -> V_72 . V_74 = V_106 -> V_37 . V_23 ;
break;
}
V_106 -> V_58 = 1 ;
F_81 ( & V_106 -> V_56 , V_58 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_46 -> V_72 . V_75 = 0 ;
while ( ! F_48 ( V_104 ) ) {
struct V_62 * V_106 = F_80 ( V_104 ,
struct V_62 ,
V_56 ) ;
if ( ! -- V_103 || F_26 ( V_46 ) < V_106 -> V_37 . V_23 ) {
V_46 -> V_72 . V_75 = V_106 -> V_37 . V_23 ;
break;
}
V_106 -> V_58 = 1 ;
F_81 ( & V_106 -> V_56 , V_58 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_46 -> V_72 . V_76 = 0 ;
while ( ! F_48 ( V_104 ) ) {
struct V_62 * V_106 = F_80 ( V_104 ,
struct V_62 ,
V_56 ) ;
if ( ! -- V_103 || V_46 -> V_65 . V_42 < V_106 -> V_37 . V_18 ) {
V_46 -> V_72 . V_76 = V_106 -> V_37 . V_18 ;
break;
}
V_106 -> V_58 = 1 ;
F_81 ( & V_106 -> V_56 , V_58 ) ;
}
V_105 = F_82 ( V_68 -> V_107 [ V_108 ] . V_109 ) ;
if ( V_105 != V_110 ) {
unsigned long V_111 =
F_82 ( V_68 -> V_107 [ V_108 ] . V_112 ) ;
if ( V_111 != V_110 &&
V_46 -> V_113 . V_114 > F_83 ( V_111 , V_115 / V_43 ) ) {
F_84 ( V_116 , V_117 , V_46 ) ;
return;
}
if ( V_46 -> V_113 . V_114 > F_83 ( V_105 , V_115 / V_43 ) ) {
if ( V_105 < V_111 ) {
V_105 += V_115 ;
V_68 -> V_107 [ V_108 ] . V_109 = V_105 ;
}
F_85 ( V_118
L_1 ,
V_46 -> V_119 , F_86 ( V_46 ) ) ;
F_84 ( V_120 , V_117 , V_46 ) ;
}
}
}
static void F_87 ( struct V_67 * V_68 )
{
struct F_32 * V_48 = & V_68 -> V_48 ;
unsigned long V_50 ;
F_34 ( & V_48 -> V_52 , V_50 ) ;
V_48 -> V_51 = 0 ;
F_35 ( & V_48 -> V_52 , V_50 ) ;
}
static void F_88 ( struct V_1 * V_46 , struct V_121 * V_33 ,
T_1 * V_37 , T_1 V_122 , int V_123 )
{
if ( ! V_33 -> V_37 )
return;
if ( V_122 >= V_33 -> V_37 ) {
if ( V_33 -> V_34 ) {
V_33 -> V_37 += V_33 -> V_34 ;
V_33 -> error += V_33 -> V_124 ;
if ( V_33 -> error >= V_125 ) {
V_33 -> V_37 -= V_126 ;
V_33 -> error -= V_125 ;
}
} else {
V_33 -> V_37 = 0 ;
}
F_89 ( V_123 == V_127 ?
V_128 : V_129 ,
V_46 -> signal -> V_130 , V_122 ) ;
F_84 ( V_123 , V_117 , V_46 ) ;
}
if ( V_33 -> V_37 && ( ! * V_37 || V_33 -> V_37 < * V_37 ) ) {
* V_37 = V_33 -> V_37 ;
}
}
static void F_90 ( struct V_1 * V_46 ,
struct V_60 * V_58 )
{
int V_103 ;
struct V_67 * const V_68 = V_46 -> signal ;
T_1 V_40 , V_64 , V_131 , V_132 ;
unsigned long long V_69 , V_133 ;
struct V_60 * V_104 = V_68 -> V_66 ;
struct V_39 V_4 ;
unsigned long V_105 ;
F_32 ( V_46 , & V_4 ) ;
V_40 = V_4 . V_40 ;
V_64 = V_40 + V_4 . V_41 ;
V_69 = V_4 . V_42 ;
V_103 = 20 ;
V_132 = 0 ;
while ( ! F_48 ( V_104 ) ) {
struct V_62 * V_134 = F_80 ( V_104 ,
struct V_62 ,
V_56 ) ;
if ( ! -- V_103 || V_64 < V_134 -> V_37 . V_23 ) {
V_132 = V_134 -> V_37 . V_23 ;
break;
}
V_134 -> V_58 = 1 ;
F_81 ( & V_134 -> V_56 , V_58 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_131 = 0 ;
while ( ! F_48 ( V_104 ) ) {
struct V_62 * V_134 = F_80 ( V_104 ,
struct V_62 ,
V_56 ) ;
if ( ! -- V_103 || V_40 < V_134 -> V_37 . V_23 ) {
V_131 = V_134 -> V_37 . V_23 ;
break;
}
V_134 -> V_58 = 1 ;
F_81 ( & V_134 -> V_56 , V_58 ) ;
}
++ V_104 ;
V_103 = 20 ;
V_133 = 0 ;
while ( ! F_48 ( V_104 ) ) {
struct V_62 * V_134 = F_80 ( V_104 ,
struct V_62 ,
V_56 ) ;
if ( ! -- V_103 || V_69 < V_134 -> V_37 . V_18 ) {
V_133 = V_134 -> V_37 . V_18 ;
break;
}
V_134 -> V_58 = 1 ;
F_81 ( & V_134 -> V_56 , V_58 ) ;
}
F_88 ( V_46 , & V_68 -> V_33 [ V_7 ] , & V_132 , V_64 ,
V_127 ) ;
F_88 ( V_46 , & V_68 -> V_33 [ V_45 ] , & V_131 , V_40 ,
V_135 ) ;
V_105 = F_82 ( V_68 -> V_107 [ V_136 ] . V_109 ) ;
if ( V_105 != V_110 ) {
unsigned long V_137 = F_91 ( V_64 ) ;
unsigned long V_111 =
F_82 ( V_68 -> V_107 [ V_136 ] . V_112 ) ;
T_1 V_138 ;
if ( V_137 >= V_111 ) {
F_84 ( V_116 , V_117 , V_46 ) ;
return;
}
if ( V_137 >= V_105 ) {
F_84 ( V_120 , V_117 , V_46 ) ;
if ( V_105 < V_111 ) {
V_105 ++ ;
V_68 -> V_107 [ V_136 ] . V_109 = V_105 ;
}
}
V_138 = F_2 ( V_105 ) ;
if ( ! V_132 || V_138 < V_132 ) {
V_132 = V_138 ;
}
}
V_68 -> V_72 . V_74 = V_132 ;
V_68 -> V_72 . V_75 = V_131 ;
V_68 -> V_72 . V_76 = V_133 ;
if ( F_24 ( & V_68 -> V_72 ) )
F_87 ( V_68 ) ;
}
void F_67 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
union V_14 V_24 ;
if ( F_46 ( V_9 == NULL ) )
goto V_94;
if ( F_11 ( V_31 -> V_35 ) ) {
F_29 ( V_31 -> V_35 , V_9 , & V_24 ) ;
F_23 ( V_31 , V_24 ) ;
if ( F_46 ( V_9 -> V_102 ) ) {
F_59 ( V_31 , V_24 ) ;
goto V_94;
}
F_38 ( & V_54 ) ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
} else {
F_38 ( & V_54 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = V_9 = NULL ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
goto V_139;
} else if ( F_46 ( V_9 -> V_102 ) && F_78 ( V_9 ) ) {
F_59 ( V_31 , V_24 ) ;
goto V_139;
}
F_49 ( & V_9 -> V_5 -> V_6 ) ;
F_68 ( V_31 -> V_35 , V_9 , & V_24 ) ;
F_23 ( V_31 , V_24 ) ;
}
F_47 ( ! F_76 () ) ;
F_61 ( V_31 ) ;
F_51 ( & V_9 -> V_5 -> V_6 ) ;
V_139:
F_39 ( & V_54 ) ;
V_94:
V_31 -> V_98 = V_31 -> V_38 ;
V_31 -> V_38 = - 1 ;
++ V_31 -> V_82 ;
}
static inline int F_92 ( const struct V_39 * V_140 ,
const struct V_39 * V_37 )
{
if ( V_37 -> V_40 && V_140 -> V_40 >= V_37 -> V_40 )
return 1 ;
if ( V_37 -> V_41 && V_140 -> V_40 + V_140 -> V_41 >= V_37 -> V_41 )
return 1 ;
if ( V_37 -> V_42 != 0 &&
V_140 -> V_42 >= V_37 -> V_42 )
return 1 ;
return 0 ;
}
static inline int F_93 ( struct V_1 * V_46 )
{
struct V_67 * V_68 ;
T_1 V_40 , V_41 ;
V_39 ( V_46 , & V_40 , & V_41 ) ;
if ( ! F_24 ( & V_46 -> V_72 ) ) {
struct V_39 V_141 = {
. V_40 = V_40 ,
. V_41 = V_41 ,
. V_42 = V_46 -> V_65 . V_42
} ;
if ( F_92 ( & V_141 , & V_46 -> V_72 ) )
return 1 ;
}
V_68 = V_46 -> signal ;
if ( V_68 -> V_48 . V_51 ) {
struct V_39 V_142 ;
F_94 ( & V_68 -> V_48 . V_52 ) ;
V_142 = V_68 -> V_48 . V_4 ;
F_95 ( & V_68 -> V_48 . V_52 ) ;
if ( F_92 ( & V_142 , & V_68 -> V_72 ) )
return 1 ;
}
return 0 ;
}
void F_96 ( struct V_1 * V_46 )
{
F_97 ( V_58 ) ;
struct V_30 * V_31 , * V_63 ;
unsigned long V_50 ;
F_47 ( ! F_76 () ) ;
if ( ! F_93 ( V_46 ) )
return;
if ( ! F_98 ( V_46 , & V_50 ) )
return;
F_79 ( V_46 , & V_58 ) ;
if ( V_46 -> signal -> V_48 . V_51 )
F_90 ( V_46 , & V_58 ) ;
F_99 ( V_46 , & V_50 ) ;
F_54 (timer, next, &firing, it.cpu.entry) {
int V_143 ;
F_49 ( & V_31 -> V_144 ) ;
F_55 ( & V_31 -> V_33 . V_23 . V_56 ) ;
V_143 = V_31 -> V_33 . V_23 . V_58 ;
V_31 -> V_33 . V_23 . V_58 = 0 ;
if ( F_45 ( V_143 >= 0 ) )
F_64 ( V_31 ) ;
F_51 ( & V_31 -> V_144 ) ;
}
if ( V_46 -> signal -> V_48 . V_51 )
F_72 () ;
}
void F_4 ( struct V_1 * V_46 , unsigned int V_145 ,
T_1 * V_146 , T_1 * V_147 )
{
union V_14 V_24 ;
F_47 ( V_145 == V_19 ) ;
F_68 ( V_145 , V_46 , & V_24 ) ;
if ( V_147 ) {
if ( * V_147 ) {
if ( * V_147 <= V_24 . V_23 ) {
* V_147 = V_126 ;
} else {
* V_147 -= V_24 . V_23 ;
}
}
if ( ! * V_146 )
goto V_94;
* V_146 += V_24 . V_23 ;
}
switch ( V_145 ) {
case V_7 :
if ( F_60 ( V_46 -> signal -> V_72 . V_74 , * V_146 ) )
V_46 -> signal -> V_72 . V_74 = * V_146 ;
break;
case V_45 :
if ( F_60 ( V_46 -> signal -> V_72 . V_75 , * V_146 ) )
V_46 -> signal -> V_72 . V_75 = * V_146 ;
break;
}
V_94:
F_72 () ;
}
static int F_100 ( const T_2 V_8 , int V_50 ,
struct V_15 * V_148 , struct V_86 * V_33 )
{
struct V_30 V_31 ;
int error ;
memset ( & V_31 , 0 , sizeof V_31 ) ;
F_101 ( & V_31 . V_144 ) ;
V_31 . V_35 = V_8 ;
V_31 . V_38 = - 1 ;
error = F_41 ( & V_31 ) ;
V_31 . V_81 = V_13 ;
if ( ! error ) {
static struct V_86 V_149 ;
memset ( V_33 , 0 , sizeof *V_33 ) ;
V_33 -> V_93 = * V_148 ;
F_3 ( & V_31 . V_144 ) ;
error = F_75 ( & V_31 , V_50 , V_33 , NULL ) ;
if ( error ) {
F_5 ( & V_31 . V_144 ) ;
return error ;
}
while ( ! F_102 ( V_13 ) ) {
if ( V_31 . V_33 . V_23 . V_37 . V_18 == 0 ) {
F_44 ( & V_31 ) ;
F_5 ( & V_31 . V_144 ) ;
return 0 ;
}
F_103 ( V_150 ) ;
F_5 ( & V_31 . V_144 ) ;
F_104 () ;
F_3 ( & V_31 . V_144 ) ;
}
F_17 ( V_8 , V_31 . V_33 . V_23 . V_37 , V_148 ) ;
error = F_75 ( & V_31 , 0 , & V_149 , V_33 ) ;
if ( ! error ) {
F_44 ( & V_31 ) ;
}
F_5 ( & V_31 . V_144 ) ;
while ( error == V_59 ) {
F_3 ( & V_31 . V_144 ) ;
error = F_44 ( & V_31 ) ;
F_5 ( & V_31 . V_144 ) ;
}
if ( ( V_33 -> V_93 . V_20 | V_33 -> V_93 . V_22 ) == 0 ) {
return 0 ;
}
error = - V_151 ;
}
return error ;
}
static int F_105 ( const T_2 V_8 , int V_50 ,
struct V_15 * V_148 , struct V_15 T_4 * V_152 )
{
struct V_153 * V_153 =
& F_106 () -> V_153 ;
struct V_86 V_33 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_100 ( V_8 , V_50 , V_148 , & V_33 ) ;
if ( error == - V_151 ) {
if ( V_50 & V_95 )
return - V_154 ;
if ( V_152 && F_107 ( V_152 , & V_33 . V_93 , sizeof *V_152 ) )
return - V_155 ;
V_153 -> V_156 = V_157 ;
V_153 -> V_158 . V_159 = V_8 ;
V_153 -> V_158 . V_152 = V_152 ;
V_153 -> V_158 . V_37 = F_108 ( V_148 ) ;
}
return error ;
}
static long V_157 ( struct V_153 * V_153 )
{
T_2 V_8 = V_153 -> V_158 . V_159 ;
struct V_15 V_106 ;
struct V_86 V_33 ;
int error ;
V_106 = F_18 ( V_153 -> V_158 . V_37 ) ;
error = F_100 ( V_8 , V_95 , & V_106 , & V_33 ) ;
if ( error == - V_151 ) {
struct V_15 T_4 * V_152 = V_153 -> V_158 . V_152 ;
if ( V_152 && F_107 ( V_152 , & V_33 . V_93 , sizeof *V_152 ) )
return - V_155 ;
V_153 -> V_158 . V_37 = F_108 ( & V_106 ) ;
}
return error ;
}
static int F_109 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_27 ( V_160 , V_16 ) ;
}
static int F_110 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_37 ( V_160 , V_16 ) ;
}
static int F_111 ( struct V_30 * V_31 )
{
V_31 -> V_35 = V_160 ;
return F_41 ( V_31 ) ;
}
static int F_112 ( const T_2 V_8 , int V_50 ,
struct V_15 * V_148 ,
struct V_15 T_4 * V_152 )
{
return F_105 ( V_160 , V_50 , V_148 , V_152 ) ;
}
static long F_113 ( struct V_153 * V_153 )
{
return - V_12 ;
}
static int F_114 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_27 ( V_161 , V_16 ) ;
}
static int F_115 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_37 ( V_161 , V_16 ) ;
}
static int F_116 ( struct V_30 * V_31 )
{
V_31 -> V_35 = V_161 ;
return F_41 ( V_31 ) ;
}
static T_5 int F_117 ( void )
{
struct V_162 V_163 = {
. V_164 = F_109 ,
. V_165 = F_110 ,
. V_166 = F_111 ,
. V_167 = F_112 ,
. V_168 = F_113 ,
} ;
struct V_162 V_169 = {
. V_164 = F_114 ,
. V_165 = F_115 ,
. V_166 = F_116 ,
} ;
struct V_15 V_170 ;
F_118 ( V_171 , & V_163 ) ;
F_118 ( V_172 , & V_169 ) ;
F_19 ( V_126 , & V_170 ) ;
V_125 = V_170 . V_22 ;
F_119 ( V_170 . V_20 != 0 ) ;
return 0 ;
}
