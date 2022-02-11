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
T_1 V_39 , V_40 ;
F_25 ( V_9 , & V_39 , & V_40 ) ;
return V_39 + V_40 ;
}
static inline T_1 F_26 ( struct V_1 * V_9 )
{
T_1 V_39 ;
F_25 ( V_9 , & V_39 , NULL ) ;
return V_39 ;
}
static int
F_27 ( const T_2 V_8 , struct V_15 * V_16 )
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
F_28 ( const T_2 V_8 , const struct V_15 * V_16 )
{
int error = F_6 ( V_8 ) ;
if ( error == 0 ) {
error = - V_42 ;
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
V_23 -> V_23 = F_24 ( V_9 ) ;
break;
case V_43 :
V_23 -> V_23 = F_26 ( V_9 ) ;
break;
case V_19 :
V_23 -> V_18 = F_30 ( V_9 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct F_25 * V_28 , struct F_25 * V_29 )
{
if ( V_29 -> V_39 > V_28 -> V_39 )
V_28 -> V_39 = V_29 -> V_39 ;
if ( V_29 -> V_40 > V_28 -> V_40 )
V_28 -> V_40 = V_29 -> V_40 ;
if ( V_29 -> V_44 > V_28 -> V_44 )
V_28 -> V_44 = V_29 -> V_44 ;
}
void F_32 ( struct V_1 * V_45 , struct F_25 * V_46 )
{
struct F_32 * V_47 = & V_45 -> signal -> V_47 ;
struct F_25 V_48 ;
unsigned long V_49 ;
if ( ! V_47 -> V_50 ) {
F_33 ( V_45 , & V_48 ) ;
F_34 ( & V_47 -> V_51 , V_49 ) ;
V_47 -> V_50 = 1 ;
F_31 ( & V_47 -> V_4 , & V_48 ) ;
} else
F_34 ( & V_47 -> V_51 , V_49 ) ;
* V_46 = V_47 -> V_4 ;
F_35 ( & V_47 -> V_51 , V_49 ) ;
}
static int F_36 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct F_25 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_33 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_39 + V_4 . V_40 ;
break;
case V_43 :
F_33 ( V_9 , & V_4 ) ;
V_23 -> V_23 = V_4 . V_39 ;
break;
case V_19 :
F_33 ( V_9 , & V_4 ) ;
V_23 -> V_18 = V_4 . V_44 ;
break;
}
return 0 ;
}
static int F_37 ( const T_2 V_8 , struct V_15 * V_16 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int error = - V_12 ;
union V_14 V_52 ;
if ( V_10 == 0 ) {
if ( F_11 ( V_8 ) ) {
error = F_29 ( V_8 ,
V_13 , & V_52 ) ;
} else {
F_38 ( & V_53 ) ;
error = F_36 ( V_8 ,
V_13 , & V_52 ) ;
F_39 ( & V_53 ) ;
}
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 ) {
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_9 , V_13 ) ) {
error = F_29 ( V_8 ,
V_9 , & V_52 ) ;
}
} else {
F_38 ( & V_53 ) ;
if ( F_40 ( V_9 ) && V_9 -> V_5 ) {
error =
F_36 ( V_8 ,
V_9 , & V_52 ) ;
}
F_39 ( & V_53 ) ;
}
}
F_14 () ;
}
if ( error )
return error ;
F_17 ( V_8 , V_52 , V_16 ) ;
return 0 ;
}
static int F_41 ( struct V_30 * V_54 )
{
int V_17 = 0 ;
const T_3 V_10 = F_7 ( V_54 -> V_35 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_54 -> V_35 ) >= V_11 )
return - V_12 ;
F_42 ( & V_54 -> V_33 . V_23 . V_55 ) ;
F_9 () ;
if ( F_11 ( V_54 -> V_35 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_56 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_54 -> V_33 . V_23 . V_2 = V_9 ;
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
F_38 ( & V_53 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_47 ( ! F_48 ( & V_31 -> V_33 . V_23 . V_55 ) ) ;
} else {
F_49 ( & V_9 -> V_5 -> V_6 ) ;
if ( V_31 -> V_33 . V_23 . V_57 )
V_17 = V_58 ;
else
F_50 ( & V_31 -> V_33 . V_23 . V_55 ) ;
F_51 ( & V_9 -> V_5 -> V_6 ) ;
}
F_39 ( & V_53 ) ;
if ( ! V_17 )
F_52 ( V_9 ) ;
}
return V_17 ;
}
static void F_53 ( struct V_59 * V_60 ,
T_1 V_39 , T_1 V_40 ,
unsigned long long V_44 )
{
struct V_61 * V_31 , * V_62 ;
T_1 V_63 = V_39 + V_40 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_55 ) ;
if ( V_31 -> V_37 . V_23 < V_63 ) {
V_31 -> V_37 . V_23 = 0 ;
} else {
V_31 -> V_37 . V_23 -= V_63 ;
}
}
++ V_60 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_55 ) ;
if ( V_31 -> V_37 . V_23 < V_39 ) {
V_31 -> V_37 . V_23 = 0 ;
} else {
V_31 -> V_37 . V_23 -= V_39 ;
}
}
++ V_60 ;
F_54 (timer, next, head, entry) {
F_55 ( & V_31 -> V_55 ) ;
if ( V_31 -> V_37 . V_18 < V_44 ) {
V_31 -> V_37 . V_18 = 0 ;
} else {
V_31 -> V_37 . V_18 -= V_44 ;
}
}
}
void F_56 ( struct V_1 * V_45 )
{
T_1 V_39 , V_40 ;
F_57 ( ( const void * ) & V_45 -> V_64 . V_44 ,
sizeof( unsigned long long ) ) ;
F_25 ( V_45 , & V_39 , & V_40 ) ;
F_53 ( V_45 -> V_65 ,
V_39 , V_40 , V_45 -> V_64 . V_44 ) ;
}
void F_58 ( struct V_1 * V_45 )
{
struct V_66 * const V_67 = V_45 -> signal ;
T_1 V_39 , V_40 ;
F_25 ( V_45 , & V_39 , & V_40 ) ;
F_53 ( V_45 -> signal -> V_65 ,
V_39 + V_67 -> V_39 , V_40 + V_67 -> V_40 ,
V_45 -> V_64 . V_44 + V_67 -> V_68 ) ;
}
static void F_59 ( struct V_30 * V_31 , union V_14 V_24 )
{
F_52 ( V_31 -> V_33 . V_23 . V_2 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
V_31 -> V_33 . V_23 . V_37 = F_22 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 ,
V_24 ) ;
}
static inline int F_60 ( T_1 V_37 , T_1 V_69 )
{
return V_37 == 0 || V_37 > V_69 ;
}
static void F_61 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
struct V_59 * V_60 , * V_70 ;
struct F_25 * V_71 ;
struct V_61 * const V_72 = & V_31 -> V_33 . V_23 ;
struct V_61 * V_62 ;
if ( F_11 ( V_31 -> V_35 ) ) {
V_60 = V_9 -> V_65 ;
V_71 = & V_9 -> V_71 ;
} else {
V_60 = V_9 -> signal -> V_65 ;
V_71 = & V_9 -> signal -> V_71 ;
}
V_60 += F_8 ( V_31 -> V_35 ) ;
V_70 = V_60 ;
F_62 (next, head, entry) {
if ( F_20 ( V_31 -> V_35 , V_72 -> V_37 , V_62 -> V_37 ) )
break;
V_70 = & V_62 -> V_55 ;
}
F_63 ( & V_72 -> V_55 , V_70 ) ;
if ( V_70 == V_60 ) {
union V_14 * exp = & V_72 -> V_37 ;
switch ( F_8 ( V_31 -> V_35 ) ) {
case V_7 :
if ( F_60 ( V_71 -> V_73 , exp -> V_23 ) )
V_71 -> V_73 = exp -> V_23 ;
break;
case V_43 :
if ( F_60 ( V_71 -> V_74 , exp -> V_23 ) )
V_71 -> V_74 = exp -> V_23 ;
break;
case V_19 :
if ( V_71 -> V_75 == 0 ||
V_71 -> V_75 > exp -> V_18 )
V_71 -> V_75 = exp -> V_18 ;
break;
}
}
}
static void F_64 ( struct V_30 * V_31 )
{
if ( ( V_31 -> V_76 & ~ V_77 ) == V_78 ) {
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( F_46 ( V_31 -> V_79 == NULL ) ) {
F_65 ( V_31 -> V_80 ) ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( V_31 -> V_33 . V_23 . V_34 . V_18 == 0 ) {
F_66 ( V_31 , 0 ) ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
} else if ( F_66 ( V_31 , ++ V_31 -> V_81 ) ) {
F_67 ( V_31 ) ;
}
}
static int F_68 ( const T_2 V_8 ,
struct V_1 * V_9 ,
union V_14 * V_23 )
{
struct F_25 V_4 ;
F_32 ( V_9 , & V_4 ) ;
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
V_23 -> V_18 = V_4 . V_44 + F_69 ( V_9 ) ;
break;
}
return 0 ;
}
static int F_70 ( struct V_30 * V_31 , int V_49 ,
struct V_82 * V_83 , struct V_82 * V_84 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
union V_14 V_85 , V_86 , V_87 , V_27 ;
int V_17 ;
if ( F_46 ( V_9 == NULL ) ) {
return - V_88 ;
}
V_86 = F_15 ( V_31 -> V_35 , & V_83 -> V_89 ) ;
F_38 ( & V_53 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_39 ( & V_53 ) ;
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
return - V_88 ;
}
F_47 ( ! F_71 () ) ;
V_17 = 0 ;
V_87 = V_31 -> V_33 . V_23 . V_34 ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
V_85 = V_31 -> V_33 . V_23 . V_37 ;
if ( F_46 ( V_31 -> V_33 . V_23 . V_57 ) ) {
V_31 -> V_33 . V_23 . V_57 = - 1 ;
V_17 = V_58 ;
} else
F_55 ( & V_31 -> V_33 . V_23 . V_55 ) ;
if ( F_11 ( V_31 -> V_35 ) ) {
F_29 ( V_31 -> V_35 , V_9 , & V_27 ) ;
} else {
F_68 ( V_31 -> V_35 , V_9 , & V_27 ) ;
}
if ( V_84 ) {
if ( V_85 . V_18 == 0 ) {
V_84 -> V_89 . V_20 = 0 ;
V_84 -> V_89 . V_22 = 0 ;
} else {
F_23 ( V_31 , V_27 ) ;
if ( F_20 ( V_31 -> V_35 , V_27 ,
V_31 -> V_33 . V_23 . V_37 ) ) {
V_85 = F_22 (
V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 , V_27 ) ;
F_17 ( V_31 -> V_35 ,
V_85 ,
& V_84 -> V_89 ) ;
} else {
V_84 -> V_89 . V_22 = 1 ;
V_84 -> V_89 . V_20 = 0 ;
}
}
}
if ( F_46 ( V_17 ) ) {
F_51 ( & V_9 -> V_5 -> V_6 ) ;
F_39 ( & V_53 ) ;
goto V_90;
}
if ( V_86 . V_18 != 0 && ! ( V_49 & V_91 ) ) {
F_21 ( V_31 -> V_35 , & V_86 , V_27 ) ;
}
V_31 -> V_33 . V_23 . V_37 = V_86 ;
if ( V_86 . V_18 != 0 &&
F_20 ( V_31 -> V_35 , V_27 , V_86 ) ) {
F_61 ( V_31 ) ;
}
F_51 ( & V_9 -> V_5 -> V_6 ) ;
F_39 ( & V_53 ) ;
V_31 -> V_33 . V_23 . V_34 = F_15 ( V_31 -> V_35 ,
& V_83 -> V_92 ) ;
V_31 -> V_81 = ( V_31 -> V_81 + 2 ) &
~ V_93 ;
V_31 -> V_94 = 0 ;
V_31 -> V_38 = - 1 ;
if ( V_86 . V_18 != 0 &&
! F_20 ( V_31 -> V_35 , V_27 , V_86 ) ) {
F_64 ( V_31 ) ;
}
V_17 = 0 ;
V_90:
if ( V_84 ) {
F_17 ( V_31 -> V_35 ,
V_87 , & V_84 -> V_92 ) ;
}
return V_17 ;
}
static void F_72 ( struct V_30 * V_31 , struct V_82 * V_95 )
{
union V_14 V_24 ;
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
int V_96 ;
F_17 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_34 , & V_95 -> V_92 ) ;
if ( V_31 -> V_33 . V_23 . V_37 . V_18 == 0 ) {
V_95 -> V_89 . V_20 = V_95 -> V_89 . V_22 = 0 ;
return;
}
if ( F_46 ( V_9 == NULL ) ) {
V_97:
F_17 ( V_31 -> V_35 , V_31 -> V_33 . V_23 . V_37 ,
& V_95 -> V_89 ) ;
return;
}
if ( F_11 ( V_31 -> V_35 ) ) {
F_29 ( V_31 -> V_35 , V_9 , & V_24 ) ;
V_96 = V_9 -> V_98 ;
} else {
F_38 ( & V_53 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = NULL ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
F_39 ( & V_53 ) ;
goto V_97;
} else {
F_68 ( V_31 -> V_35 , V_9 , & V_24 ) ;
V_96 = ( F_46 ( V_9 -> V_98 ) &&
F_73 ( V_9 ) ) ;
}
F_39 ( & V_53 ) ;
}
if ( F_46 ( V_96 ) ) {
F_59 ( V_31 , V_24 ) ;
goto V_97;
}
if ( F_20 ( V_31 -> V_35 , V_24 , V_31 -> V_33 . V_23 . V_37 ) ) {
F_17 ( V_31 -> V_35 ,
F_22 ( V_31 -> V_35 ,
V_31 -> V_33 . V_23 . V_37 , V_24 ) ,
& V_95 -> V_89 ) ;
} else {
V_95 -> V_89 . V_22 = 1 ;
V_95 -> V_89 . V_20 = 0 ;
}
}
static void F_74 ( struct V_1 * V_45 ,
struct V_59 * V_57 )
{
int V_99 ;
struct V_59 * V_100 = V_45 -> V_65 ;
struct V_66 * const V_67 = V_45 -> signal ;
unsigned long V_101 ;
V_99 = 20 ;
V_45 -> V_71 . V_73 = 0 ;
while ( ! F_48 ( V_100 ) ) {
struct V_61 * V_102 = F_75 ( V_100 ,
struct V_61 ,
V_55 ) ;
if ( ! -- V_99 || F_24 ( V_45 ) < V_102 -> V_37 . V_23 ) {
V_45 -> V_71 . V_73 = V_102 -> V_37 . V_23 ;
break;
}
V_102 -> V_57 = 1 ;
F_76 ( & V_102 -> V_55 , V_57 ) ;
}
++ V_100 ;
V_99 = 20 ;
V_45 -> V_71 . V_74 = 0 ;
while ( ! F_48 ( V_100 ) ) {
struct V_61 * V_102 = F_75 ( V_100 ,
struct V_61 ,
V_55 ) ;
if ( ! -- V_99 || F_26 ( V_45 ) < V_102 -> V_37 . V_23 ) {
V_45 -> V_71 . V_74 = V_102 -> V_37 . V_23 ;
break;
}
V_102 -> V_57 = 1 ;
F_76 ( & V_102 -> V_55 , V_57 ) ;
}
++ V_100 ;
V_99 = 20 ;
V_45 -> V_71 . V_75 = 0 ;
while ( ! F_48 ( V_100 ) ) {
struct V_61 * V_102 = F_75 ( V_100 ,
struct V_61 ,
V_55 ) ;
if ( ! -- V_99 || V_45 -> V_64 . V_44 < V_102 -> V_37 . V_18 ) {
V_45 -> V_71 . V_75 = V_102 -> V_37 . V_18 ;
break;
}
V_102 -> V_57 = 1 ;
F_76 ( & V_102 -> V_55 , V_57 ) ;
}
V_101 = F_77 ( V_67 -> V_103 [ V_104 ] . V_105 ) ;
if ( V_101 != V_106 ) {
unsigned long V_107 =
F_77 ( V_67 -> V_103 [ V_104 ] . V_108 ) ;
if ( V_107 != V_106 &&
V_45 -> V_109 . V_110 > F_78 ( V_107 , V_111 / V_41 ) ) {
F_79 ( V_112 , V_113 , V_45 ) ;
return;
}
if ( V_45 -> V_109 . V_110 > F_78 ( V_101 , V_111 / V_41 ) ) {
if ( V_101 < V_107 ) {
V_101 += V_111 ;
V_67 -> V_103 [ V_104 ] . V_105 = V_101 ;
}
F_80 ( V_114
L_1 ,
V_45 -> V_115 , F_81 ( V_45 ) ) ;
F_79 ( V_116 , V_113 , V_45 ) ;
}
}
}
static void F_82 ( struct V_66 * V_67 )
{
struct F_32 * V_47 = & V_67 -> V_47 ;
unsigned long V_49 ;
F_34 ( & V_47 -> V_51 , V_49 ) ;
V_47 -> V_50 = 0 ;
F_35 ( & V_47 -> V_51 , V_49 ) ;
}
static void F_83 ( struct V_1 * V_45 , struct V_117 * V_33 ,
T_1 * V_37 , T_1 V_118 , int V_119 )
{
if ( ! V_33 -> V_37 )
return;
if ( V_118 >= V_33 -> V_37 ) {
if ( V_33 -> V_34 ) {
V_33 -> V_37 += V_33 -> V_34 ;
V_33 -> error += V_33 -> V_120 ;
if ( V_33 -> error >= V_121 ) {
V_33 -> V_37 -= V_122 ;
V_33 -> error -= V_121 ;
}
} else {
V_33 -> V_37 = 0 ;
}
F_84 ( V_119 == V_123 ?
V_124 : V_125 ,
V_45 -> signal -> V_126 , V_118 ) ;
F_79 ( V_119 , V_113 , V_45 ) ;
}
if ( V_33 -> V_37 && ( ! * V_37 || V_33 -> V_37 < * V_37 ) ) {
* V_37 = V_33 -> V_37 ;
}
}
static inline int F_85 ( const struct F_25 * V_4 )
{
if ( ! V_4 -> V_39 && ! V_4 -> V_40 && ! V_4 -> V_44 )
return 1 ;
return 0 ;
}
static void F_86 ( struct V_1 * V_45 ,
struct V_59 * V_57 )
{
int V_99 ;
struct V_66 * const V_67 = V_45 -> signal ;
T_1 V_39 , V_63 , V_127 , V_128 ;
unsigned long long V_68 , V_129 ;
struct V_59 * V_100 = V_67 -> V_65 ;
struct F_25 V_4 ;
unsigned long V_101 ;
F_32 ( V_45 , & V_4 ) ;
V_39 = V_4 . V_39 ;
V_63 = V_39 + V_4 . V_40 ;
V_68 = V_4 . V_44 ;
V_99 = 20 ;
V_128 = 0 ;
while ( ! F_48 ( V_100 ) ) {
struct V_61 * V_130 = F_75 ( V_100 ,
struct V_61 ,
V_55 ) ;
if ( ! -- V_99 || V_63 < V_130 -> V_37 . V_23 ) {
V_128 = V_130 -> V_37 . V_23 ;
break;
}
V_130 -> V_57 = 1 ;
F_76 ( & V_130 -> V_55 , V_57 ) ;
}
++ V_100 ;
V_99 = 20 ;
V_127 = 0 ;
while ( ! F_48 ( V_100 ) ) {
struct V_61 * V_130 = F_75 ( V_100 ,
struct V_61 ,
V_55 ) ;
if ( ! -- V_99 || V_39 < V_130 -> V_37 . V_23 ) {
V_127 = V_130 -> V_37 . V_23 ;
break;
}
V_130 -> V_57 = 1 ;
F_76 ( & V_130 -> V_55 , V_57 ) ;
}
++ V_100 ;
V_99 = 20 ;
V_129 = 0 ;
while ( ! F_48 ( V_100 ) ) {
struct V_61 * V_130 = F_75 ( V_100 ,
struct V_61 ,
V_55 ) ;
if ( ! -- V_99 || V_68 < V_130 -> V_37 . V_18 ) {
V_129 = V_130 -> V_37 . V_18 ;
break;
}
V_130 -> V_57 = 1 ;
F_76 ( & V_130 -> V_55 , V_57 ) ;
}
F_83 ( V_45 , & V_67 -> V_33 [ V_7 ] , & V_128 , V_63 ,
V_123 ) ;
F_83 ( V_45 , & V_67 -> V_33 [ V_43 ] , & V_127 , V_39 ,
V_131 ) ;
V_101 = F_77 ( V_67 -> V_103 [ V_132 ] . V_105 ) ;
if ( V_101 != V_106 ) {
unsigned long V_133 = F_87 ( V_63 ) ;
unsigned long V_107 =
F_77 ( V_67 -> V_103 [ V_132 ] . V_108 ) ;
T_1 V_134 ;
if ( V_133 >= V_107 ) {
F_79 ( V_112 , V_113 , V_45 ) ;
return;
}
if ( V_133 >= V_101 ) {
F_79 ( V_116 , V_113 , V_45 ) ;
if ( V_101 < V_107 ) {
V_101 ++ ;
V_67 -> V_103 [ V_132 ] . V_105 = V_101 ;
}
}
V_134 = F_2 ( V_101 ) ;
if ( ! V_128 || V_134 < V_128 ) {
V_128 = V_134 ;
}
}
V_67 -> V_71 . V_73 = V_128 ;
V_67 -> V_71 . V_74 = V_127 ;
V_67 -> V_71 . V_75 = V_129 ;
if ( F_85 ( & V_67 -> V_71 ) )
F_82 ( V_67 ) ;
}
void F_67 ( struct V_30 * V_31 )
{
struct V_1 * V_9 = V_31 -> V_33 . V_23 . V_2 ;
union V_14 V_24 ;
if ( F_46 ( V_9 == NULL ) )
goto V_90;
if ( F_11 ( V_31 -> V_35 ) ) {
F_29 ( V_31 -> V_35 , V_9 , & V_24 ) ;
F_23 ( V_31 , V_24 ) ;
if ( F_46 ( V_9 -> V_98 ) ) {
F_59 ( V_31 , V_24 ) ;
goto V_90;
}
F_38 ( & V_53 ) ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
} else {
F_38 ( & V_53 ) ;
if ( F_46 ( V_9 -> V_5 == NULL ) ) {
F_52 ( V_9 ) ;
V_31 -> V_33 . V_23 . V_2 = V_9 = NULL ;
V_31 -> V_33 . V_23 . V_37 . V_18 = 0 ;
goto V_135;
} else if ( F_46 ( V_9 -> V_98 ) && F_73 ( V_9 ) ) {
F_59 ( V_31 , V_24 ) ;
goto V_135;
}
F_49 ( & V_9 -> V_5 -> V_6 ) ;
F_68 ( V_31 -> V_35 , V_9 , & V_24 ) ;
F_23 ( V_31 , V_24 ) ;
}
F_47 ( ! F_71 () ) ;
F_61 ( V_31 ) ;
F_51 ( & V_9 -> V_5 -> V_6 ) ;
V_135:
F_39 ( & V_53 ) ;
V_90:
V_31 -> V_94 = V_31 -> V_38 ;
V_31 -> V_38 = - 1 ;
++ V_31 -> V_81 ;
}
static inline int F_88 ( const struct F_25 * V_136 ,
const struct F_25 * V_37 )
{
if ( V_37 -> V_39 && V_136 -> V_39 >= V_37 -> V_39 )
return 1 ;
if ( V_37 -> V_40 && V_136 -> V_39 + V_136 -> V_40 >= V_37 -> V_40 )
return 1 ;
if ( V_37 -> V_44 != 0 &&
V_136 -> V_44 >= V_37 -> V_44 )
return 1 ;
return 0 ;
}
static inline int F_89 ( struct V_1 * V_45 )
{
struct V_66 * V_67 ;
T_1 V_39 , V_40 ;
F_25 ( V_45 , & V_39 , & V_40 ) ;
if ( ! F_85 ( & V_45 -> V_71 ) ) {
struct F_25 V_137 = {
. V_39 = V_39 ,
. V_40 = V_40 ,
. V_44 = V_45 -> V_64 . V_44
} ;
if ( F_88 ( & V_137 , & V_45 -> V_71 ) )
return 1 ;
}
V_67 = V_45 -> signal ;
if ( V_67 -> V_47 . V_50 ) {
struct F_25 V_138 ;
F_90 ( & V_67 -> V_47 . V_51 ) ;
V_138 = V_67 -> V_47 . V_4 ;
F_91 ( & V_67 -> V_47 . V_51 ) ;
if ( F_88 ( & V_138 , & V_67 -> V_71 ) )
return 1 ;
}
return 0 ;
}
void F_92 ( struct V_1 * V_45 )
{
F_93 ( V_57 ) ;
struct V_30 * V_31 , * V_62 ;
unsigned long V_49 ;
F_47 ( ! F_71 () ) ;
if ( ! F_89 ( V_45 ) )
return;
if ( ! F_94 ( V_45 , & V_49 ) )
return;
F_74 ( V_45 , & V_57 ) ;
if ( V_45 -> signal -> V_47 . V_50 )
F_86 ( V_45 , & V_57 ) ;
F_95 ( V_45 , & V_49 ) ;
F_54 (timer, next, &firing, it.cpu.entry) {
int V_139 ;
F_49 ( & V_31 -> V_140 ) ;
F_55 ( & V_31 -> V_33 . V_23 . V_55 ) ;
V_139 = V_31 -> V_33 . V_23 . V_57 ;
V_31 -> V_33 . V_23 . V_57 = 0 ;
if ( F_45 ( V_139 >= 0 ) )
F_64 ( V_31 ) ;
F_51 ( & V_31 -> V_140 ) ;
}
}
void F_4 ( struct V_1 * V_45 , unsigned int V_141 ,
T_1 * V_142 , T_1 * V_143 )
{
union V_14 V_24 ;
F_47 ( V_141 == V_19 ) ;
F_68 ( V_141 , V_45 , & V_24 ) ;
if ( V_143 ) {
if ( * V_143 ) {
if ( * V_143 <= V_24 . V_23 ) {
* V_143 = V_122 ;
} else {
* V_143 -= V_24 . V_23 ;
}
}
if ( ! * V_142 )
return;
* V_142 += V_24 . V_23 ;
}
switch ( V_141 ) {
case V_7 :
if ( F_60 ( V_45 -> signal -> V_71 . V_73 , * V_142 ) )
V_45 -> signal -> V_71 . V_73 = * V_142 ;
break;
case V_43 :
if ( F_60 ( V_45 -> signal -> V_71 . V_74 , * V_142 ) )
V_45 -> signal -> V_71 . V_74 = * V_142 ;
break;
}
}
static int F_96 ( const T_2 V_8 , int V_49 ,
struct V_15 * V_144 , struct V_82 * V_33 )
{
struct V_30 V_31 ;
int error ;
memset ( & V_31 , 0 , sizeof V_31 ) ;
F_97 ( & V_31 . V_140 ) ;
V_31 . V_35 = V_8 ;
V_31 . V_38 = - 1 ;
error = F_41 ( & V_31 ) ;
V_31 . V_80 = V_13 ;
if ( ! error ) {
static struct V_82 V_145 ;
memset ( V_33 , 0 , sizeof *V_33 ) ;
V_33 -> V_89 = * V_144 ;
F_3 ( & V_31 . V_140 ) ;
error = F_70 ( & V_31 , V_49 , V_33 , NULL ) ;
if ( error ) {
F_5 ( & V_31 . V_140 ) ;
return error ;
}
while ( ! F_98 ( V_13 ) ) {
if ( V_31 . V_33 . V_23 . V_37 . V_18 == 0 ) {
F_44 ( & V_31 ) ;
F_5 ( & V_31 . V_140 ) ;
return 0 ;
}
F_99 ( V_146 ) ;
F_5 ( & V_31 . V_140 ) ;
F_100 () ;
F_3 ( & V_31 . V_140 ) ;
}
F_17 ( V_8 , V_31 . V_33 . V_23 . V_37 , V_144 ) ;
error = F_70 ( & V_31 , 0 , & V_145 , V_33 ) ;
if ( ! error ) {
F_44 ( & V_31 ) ;
}
F_5 ( & V_31 . V_140 ) ;
while ( error == V_58 ) {
F_3 ( & V_31 . V_140 ) ;
error = F_44 ( & V_31 ) ;
F_5 ( & V_31 . V_140 ) ;
}
if ( ( V_33 -> V_89 . V_20 | V_33 -> V_89 . V_22 ) == 0 ) {
return 0 ;
}
error = - V_147 ;
}
return error ;
}
static int F_101 ( const T_2 V_8 , int V_49 ,
struct V_15 * V_144 , struct V_15 T_4 * V_148 )
{
struct V_149 * V_149 =
& F_102 () -> V_149 ;
struct V_82 V_33 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_96 ( V_8 , V_49 , V_144 , & V_33 ) ;
if ( error == - V_147 ) {
if ( V_49 & V_91 )
return - V_150 ;
if ( V_148 && F_103 ( V_148 , & V_33 . V_89 , sizeof *V_148 ) )
return - V_151 ;
V_149 -> V_152 = V_153 ;
V_149 -> V_154 . V_155 = V_8 ;
V_149 -> V_154 . V_148 = V_148 ;
V_149 -> V_154 . V_37 = F_104 ( V_144 ) ;
}
return error ;
}
static long V_153 ( struct V_149 * V_149 )
{
T_2 V_8 = V_149 -> V_154 . V_155 ;
struct V_15 V_102 ;
struct V_82 V_33 ;
int error ;
V_102 = F_18 ( V_149 -> V_154 . V_37 ) ;
error = F_96 ( V_8 , V_91 , & V_102 , & V_33 ) ;
if ( error == - V_147 ) {
struct V_15 T_4 * V_148 = V_149 -> V_154 . V_148 ;
if ( V_148 && F_103 ( V_148 , & V_33 . V_89 , sizeof *V_148 ) )
return - V_151 ;
V_149 -> V_154 . V_37 = F_104 ( & V_102 ) ;
}
return error ;
}
static int F_105 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_27 ( V_156 , V_16 ) ;
}
static int F_106 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_37 ( V_156 , V_16 ) ;
}
static int F_107 ( struct V_30 * V_31 )
{
V_31 -> V_35 = V_156 ;
return F_41 ( V_31 ) ;
}
static int F_108 ( const T_2 V_8 , int V_49 ,
struct V_15 * V_144 ,
struct V_15 T_4 * V_148 )
{
return F_101 ( V_156 , V_49 , V_144 , V_148 ) ;
}
static long F_109 ( struct V_149 * V_149 )
{
return - V_12 ;
}
static int F_110 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_27 ( V_157 , V_16 ) ;
}
static int F_111 ( const T_2 V_8 ,
struct V_15 * V_16 )
{
return F_37 ( V_157 , V_16 ) ;
}
static int F_112 ( struct V_30 * V_31 )
{
V_31 -> V_35 = V_157 ;
return F_41 ( V_31 ) ;
}
static T_5 int F_113 ( void )
{
struct V_158 V_159 = {
. V_160 = F_105 ,
. V_161 = F_106 ,
. V_162 = F_107 ,
. V_163 = F_108 ,
. V_164 = F_109 ,
} ;
struct V_158 V_165 = {
. V_160 = F_110 ,
. V_161 = F_111 ,
. V_162 = F_112 ,
} ;
struct V_15 V_166 ;
F_114 ( V_167 , & V_159 ) ;
F_114 ( V_168 , & V_165 ) ;
F_19 ( V_122 , & V_166 ) ;
V_121 = V_166 . V_22 ;
F_115 ( V_166 . V_20 != 0 ) ;
return 0 ;
}
