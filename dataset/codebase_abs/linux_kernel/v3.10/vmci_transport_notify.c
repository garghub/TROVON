static bool F_1 ( struct V_1 * V_2 )
{
#if F_2 ( V_3 )
bool V_4 ;
T_1 V_5 ;
if ( ! F_3 ( V_2 , V_6 ) )
return false ;
#ifdef F_4
if ( ! F_3 ( V_2 , V_7 ) ) {
F_3 ( V_2 , V_7 ) = true ;
if ( F_3 ( V_2 , V_8 ) < V_9 ) {
F_3 ( V_2 , V_8 ) =
F_3 ( V_2 , V_10 ) ;
} else {
F_3 ( V_2 , V_8 ) -= V_9 ;
if ( F_3 ( V_2 , V_8 ) <
F_3 ( V_2 , V_10 ) )
F_3 ( V_2 , V_8 ) =
F_3 ( V_2 , V_10 ) ;
}
}
V_5 = F_5 ( V_2 ) -> V_11 -
F_3 ( V_2 , V_8 ) ;
#else
V_5 = 0 ;
#endif
V_4 = F_6 ( F_5 ( V_2 ) -> V_12 ) >
V_5 ;
#ifdef F_4
if ( V_4 ) {
F_3 ( V_2 , V_7 ) = false ;
}
#endif
return V_4 ;
#else
return true ;
#endif
}
static bool F_7 ( struct V_1 * V_2 )
{
#if F_2 ( V_3 )
if ( ! F_3 ( V_2 , V_13 ) )
return false ;
return F_8 ( F_5 ( V_2 ) -> V_12 ) > 0 ;
#else
return true ;
#endif
}
static void
F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_18 ,
struct V_19 * V_20 ,
struct V_19 * V_21 )
{
#if F_2 ( V_3 )
struct V_1 * V_2 ;
V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_13 ) = true ;
memcpy ( & F_3 ( V_2 , V_22 ) , & V_17 -> V_23 . V_24 ,
sizeof( F_3 ( V_2 , V_22 ) ) ) ;
if ( F_7 ( V_2 ) ) {
bool V_25 ;
if ( V_18 )
V_25 = F_11 ( V_20 , V_21 ) > 0 ;
else
V_25 = F_12 ( V_15 ) > 0 ;
if ( V_25 )
F_3 ( V_2 , V_13 ) = false ;
}
#endif
}
static void
F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_18 ,
struct V_19 * V_20 ,
struct V_19 * V_21 )
{
#if F_2 ( V_3 )
struct V_1 * V_2 ;
V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_6 ) = true ;
memcpy ( & F_3 ( V_2 , V_26 ) , & V_17 -> V_23 . V_24 ,
sizeof( F_3 ( V_2 , V_26 ) ) ) ;
if ( F_1 ( V_2 ) ) {
bool V_25 ;
if ( V_18 )
V_25 = F_14 ( V_20 , V_21 ) > 0 ;
else
V_25 = F_15 ( V_15 ) > 0 ;
if ( V_25 )
F_3 ( V_2 , V_6 ) = false ;
}
#endif
}
static void
F_16 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_18 ,
struct V_19 * V_20 , struct V_19 * V_21 )
{
#if F_2 ( V_3 )
struct V_1 * V_2 ;
V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_27 ) = false ;
#endif
V_15 -> V_28 ( V_15 ) ;
}
static bool F_17 ( struct V_14 * V_15 , T_1 V_29 )
{
#if F_2 ( V_3 )
struct V_1 * V_2 ;
struct V_30 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_1 V_34 ;
bool V_35 ;
V_2 = F_10 ( V_15 ) ;
if ( F_3 ( V_2 , V_36 ) )
return true ;
if ( F_3 ( V_2 , V_8 ) <
F_5 ( V_2 ) -> V_11 )
F_3 ( V_2 , V_8 ) =
F_18 ( F_3 ( V_2 , V_8 ) + V_9 ,
F_5 ( V_2 ) -> V_11 ) ;
F_19 ( F_5 ( V_2 ) -> V_12 , & V_32 , & V_33 ) ;
V_34 = F_5 ( V_2 ) -> V_11 - V_33 ;
if ( V_29 >= V_34 ) {
V_31 . V_37 = V_29 - V_34 ;
V_31 . V_38 =
F_3 ( V_2 , V_39 ) + 1 ;
} else {
V_31 . V_37 = V_33 + V_29 ;
V_31 . V_38 = F_3 ( V_2 , V_39 ) ;
}
V_35 = F_20 ( V_15 , & V_31 ) > 0 ;
if ( V_35 )
F_3 ( V_2 , V_36 ) = true ;
return V_35 ;
#else
return true ;
#endif
}
static bool F_21 ( struct V_14 * V_15 , T_1 V_29 )
{
#if F_2 ( V_3 )
struct V_1 * V_2 ;
struct V_30 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_1 V_34 ;
bool V_35 ;
V_2 = F_10 ( V_15 ) ;
if ( F_3 ( V_2 , V_27 ) )
return true ;
F_22 ( F_5 ( V_2 ) -> V_12 , & V_32 , & V_33 ) ;
V_34 = F_5 ( V_2 ) -> V_40 - V_32 ;
if ( V_29 + 1 >= V_34 ) {
V_31 . V_37 = V_29 + 1 - V_34 ;
V_31 . V_38 = F_3 ( V_2 , V_41 ) ;
} else {
V_31 . V_37 = V_32 + V_29 + 1 ;
V_31 . V_38 =
F_3 ( V_2 , V_41 ) - 1 ;
}
V_35 = F_23 ( V_15 , & V_31 ) > 0 ;
if ( V_35 )
F_3 ( V_2 , V_27 ) = true ;
return V_35 ;
#else
return true ;
#endif
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
bool V_42 ;
unsigned int V_43 ;
int V_44 ;
V_2 = F_10 ( V_15 ) ;
V_42 = false ;
V_43 = 0 ;
V_44 = 0 ;
if ( F_1 ( V_2 ) ) {
while ( ! ( V_2 -> V_45 & V_46 ) &&
! V_42 &&
V_43 < V_47 ) {
V_44 = F_15 ( V_15 ) ;
if ( V_44 >= 0 )
V_42 = true ;
V_43 ++ ;
}
if ( V_43 >= V_47 )
F_25 ( L_1 , V_15 ) ;
else
#if F_2 ( V_3 )
F_3 ( V_2 , V_6 ) = false ;
#endif
}
return V_44 ;
}
static void
F_26 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_18 ,
struct V_19 * V_20 , struct V_19 * V_21 )
{
#if F_2 ( V_3 )
struct V_1 * V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_36 ) = false ;
#endif
V_15 -> V_48 ( V_15 , 0 ) ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_8 ) = V_9 ;
F_3 ( V_2 , V_10 ) = V_9 ;
F_3 ( V_2 , V_13 ) = false ;
F_3 ( V_2 , V_6 ) = false ;
F_3 ( V_2 , V_7 ) = false ;
F_3 ( V_2 , V_36 ) = false ;
F_3 ( V_2 , V_27 ) = false ;
F_3 ( V_2 , V_41 ) = 0 ;
F_3 ( V_2 , V_39 ) = 0 ;
memset ( & F_3 ( V_2 , V_22 ) , 0 ,
sizeof( F_3 ( V_2 , V_22 ) ) ) ;
memset ( & F_3 ( V_2 , V_26 ) , 0 ,
sizeof( F_3 ( V_2 , V_26 ) ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
}
static int
F_29 ( struct V_14 * V_15 ,
T_2 V_49 , bool * V_50 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
if ( F_30 ( V_2 ) ) {
* V_50 = true ;
} else {
if ( V_15 -> V_51 == V_52 ) {
if ( ! F_17 ( V_15 , 1 ) )
return - 1 ;
}
* V_50 = false ;
}
return 0 ;
}
static int
F_31 ( struct V_14 * V_15 ,
T_2 V_49 , bool * V_53 )
{
T_3 V_54 ;
struct V_1 * V_2 = F_10 ( V_15 ) ;
V_54 = F_32 ( V_2 ) ;
if ( V_54 > 0 ) {
* V_53 = true ;
return 0 ;
} else if ( V_54 == 0 ) {
if ( ! F_21 ( V_15 , 1 ) )
return - 1 ;
* V_53 = false ;
}
return 0 ;
}
static int
F_33 (
struct V_14 * V_15 ,
T_2 V_49 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
#ifdef V_3
V_56 -> V_57 = 0 ;
V_56 -> V_58 = 0 ;
#ifdef F_4
V_56 -> V_59 = false ;
if ( F_3 ( V_2 , V_10 ) < V_49 + 1 ) {
F_3 ( V_2 , V_10 ) = V_49 + 1 ;
if ( F_3 ( V_2 , V_8 ) <
F_3 ( V_2 , V_10 ) ) {
F_3 ( V_2 , V_8 ) =
F_3 ( V_2 , V_10 ) ;
V_56 -> V_59 = true ;
}
}
#endif
#endif
return 0 ;
}
static int
F_34 (
struct V_14 * V_15 ,
T_2 V_49 ,
struct V_55 * V_56 )
{
int V_44 = 0 ;
if ( ! F_17 ( V_15 , V_49 ) ) {
V_44 = - V_60 ;
return V_44 ;
}
#ifdef F_4
if ( V_56 -> V_59 ) {
V_44 = F_24 ( V_15 ) ;
if ( V_44 < 0 )
return V_44 ;
V_56 -> V_59 = false ;
}
#endif
return V_44 ;
}
static int
F_35 (
struct V_14 * V_15 ,
T_2 V_49 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
#if F_2 ( V_3 )
F_19 ( F_5 ( V_2 ) -> V_12 ,
& V_56 -> V_58 ,
& V_56 -> V_57 ) ;
#endif
return 0 ;
}
static int
F_36 (
struct V_14 * V_15 ,
T_2 V_49 ,
T_4 V_61 ,
bool V_62 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 ;
int V_44 ;
V_2 = F_10 ( V_15 ) ;
V_44 = 0 ;
if ( V_62 ) {
#if F_2 ( V_3 )
if ( V_61 >=
F_5 ( V_2 ) -> V_11 - V_56 -> V_57 )
F_3 ( V_2 , V_39 ) ++ ;
#endif
V_44 = F_24 ( V_15 ) ;
if ( V_44 < 0 )
return V_44 ;
}
return V_44 ;
}
static int
F_37 (
struct V_14 * V_15 ,
struct V_63 * V_56 )
{
#ifdef V_3
V_56 -> V_57 = 0 ;
V_56 -> V_58 = 0 ;
#endif
return 0 ;
}
static int
F_38 (
struct V_14 * V_15 ,
struct V_63 * V_56 )
{
if ( ! F_21 ( V_15 , 1 ) )
return - V_60 ;
return 0 ;
}
static int
F_39 (
struct V_14 * V_15 ,
struct V_63 * V_56 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
#if F_2 ( V_3 )
F_22 ( F_5 ( V_2 ) -> V_12 ,
& V_56 -> V_58 ,
& V_56 -> V_57 ) ;
#endif
return 0 ;
}
static int
F_40 (
struct V_14 * V_15 ,
T_4 V_64 ,
struct V_63 * V_56 )
{
int V_44 = 0 ;
struct V_1 * V_2 ;
bool V_65 = false ;
int V_43 = 0 ;
V_2 = F_10 ( V_15 ) ;
#if F_2 ( V_3 )
if ( V_64 >= F_5 ( V_2 ) -> V_40 - V_56 -> V_58 )
F_3 ( V_2 , V_41 ) ++ ;
#endif
if ( F_7 ( V_2 ) ) {
while ( ! ( V_2 -> V_45 & V_46 ) &&
! V_65 &&
V_43 < V_47 ) {
V_44 = F_12 ( V_15 ) ;
if ( V_44 >= 0 )
V_65 = true ;
V_43 ++ ;
}
if ( V_43 >= V_47 ) {
F_25 ( L_2 , V_15 ) ;
return V_44 ;
} else {
#if F_2 ( V_3 )
F_3 ( V_2 , V_13 ) = false ;
#endif
}
}
return V_44 ;
}
static void
F_41 (
struct V_14 * V_15 ,
struct V_16 * V_17 ,
bool V_18 ,
struct V_19 * V_20 ,
struct V_19 * V_21 , bool * V_66 )
{
bool V_67 = false ;
switch ( V_17 -> type ) {
case V_68 :
F_26 ( V_15 , V_17 , V_18 , V_20 , V_21 ) ;
V_67 = true ;
break;
case V_69 :
F_16 ( V_15 , V_17 , V_18 , V_20 , V_21 ) ;
V_67 = true ;
break;
case V_70 :
F_13 ( V_15 , V_17 , V_18 ,
V_20 , V_21 ) ;
V_67 = true ;
break;
case V_71 :
F_9 ( V_15 , V_17 , V_18 ,
V_20 , V_21 ) ;
V_67 = true ;
break;
}
if ( V_66 )
* V_66 = V_67 ;
}
static void F_42 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_8 ) = F_5 ( V_2 ) -> V_11 ;
if ( F_5 ( V_2 ) -> V_11 <
F_3 ( V_2 , V_10 ) )
F_3 ( V_2 , V_10 ) =
F_5 ( V_2 ) -> V_11 ;
}
static void F_43 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
F_3 ( V_2 , V_8 ) = F_5 ( V_2 ) -> V_11 ;
if ( F_5 ( V_2 ) -> V_11 <
F_3 ( V_2 , V_10 ) )
F_3 ( V_2 , V_10 ) =
F_5 ( V_2 ) -> V_11 ;
}
