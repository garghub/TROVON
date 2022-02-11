static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static bool
F_2 ( struct V_8 * V_9 ,
const struct V_1 * V_10 )
{
if ( F_3 ( V_9 , V_11 , V_10 -> V_5 ) ||
F_4 ( V_9 , V_12 , V_10 -> V_6 ) ||
F_5 ( V_9 , V_13 , V_10 -> V_7 ) )
goto V_14;
return false ;
V_14:
return true ;
}
static inline void
F_6 ( struct V_1 * V_15 ,
const struct V_1 * V_16 )
{
V_15 -> V_5 = V_16 -> V_5 ;
V_15 -> V_6 = V_16 -> V_6 ;
}
static int
F_7 ( struct V_17 * V_18 , const struct V_8 * V_9 ,
const struct V_19 * V_20 ,
enum V_21 V_22 , struct V_23 * V_24 )
{
T_2 V_25 = V_18 -> V_26 -> V_22 [ V_22 ] ;
struct V_1 V_27 = { . V_5 = 0 } ;
struct V_28 V_29 = F_8 ( V_9 , V_24 , V_18 ) ;
if ( ! F_9 ( V_9 , V_24 -> V_30 & V_31 ,
& V_27 . V_6 , & V_27 . V_7 ) )
return - V_32 ;
F_10 ( V_9 , V_24 -> V_30 & V_33 , & V_27 . V_5 ) ;
return V_25 ( V_18 , & V_27 , & V_29 , & V_24 -> V_29 , V_24 -> V_34 ) ;
}
static int
F_11 ( struct V_17 * V_18 , struct V_35 * V_36 [] ,
enum V_21 V_22 , T_1 * V_37 , T_1 V_30 , bool V_38 )
{
const struct V_39 * V_40 = V_18 -> V_10 ;
T_2 V_25 = V_18 -> V_26 -> V_22 [ V_22 ] ;
struct V_1 V_27 = { . V_5 = 0 } ;
struct V_28 V_29 = F_12 ( V_18 ) ;
T_1 V_5 , V_41 = 0 , V_42 = 0 , V_6 , V_43 ;
bool V_44 = false ;
int V_45 ;
if ( V_36 [ V_46 ] )
* V_37 = F_13 ( V_36 [ V_46 ] ) ;
if ( F_14 ( ! V_36 [ V_11 ] ||
! F_15 ( V_36 , V_12 ) ||
! F_16 ( V_36 , V_47 ) ) )
return - V_48 ;
V_45 = F_17 ( V_36 [ V_11 ] , & V_27 . V_5 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_18 ( V_18 , V_36 , & V_29 ) ;
if ( V_45 )
return V_45 ;
V_27 . V_6 = F_19 ( V_36 [ V_12 ] ) ;
if ( V_36 [ V_13 ] ) {
V_27 . V_7 = F_20 ( V_36 [ V_13 ] ) ;
V_44 = F_21 ( V_27 . V_7 ) ;
if ( V_27 . V_7 == 0 )
return - V_49 ;
} else {
return - V_50 ;
}
if ( ! ( V_44 || V_27 . V_7 == V_51 ) )
V_27 . V_6 = 0 ;
if ( V_22 == V_52 ||
! ( V_36 [ V_53 ] || V_36 [ V_54 ] ||
V_36 [ V_47 ] ) ) {
V_45 = V_25 ( V_18 , & V_27 , & V_29 , & V_29 , V_30 ) ;
return F_22 ( V_45 , V_30 ) ? 0 : V_45 ;
}
V_41 = V_5 = F_23 ( V_27 . V_5 ) ;
if ( V_36 [ V_53 ] ) {
V_45 = F_24 ( V_36 [ V_53 ] , & V_41 ) ;
if ( V_45 )
return V_45 ;
if ( V_5 > V_41 )
F_25 ( V_5 , V_41 ) ;
} else if ( V_36 [ V_54 ] ) {
T_3 V_55 = F_20 ( V_36 [ V_54 ] ) ;
if ( ! V_55 || V_55 > V_56 )
return - V_57 ;
F_26 ( V_5 , V_41 , V_55 ) ;
}
V_43 = V_6 = F_27 ( V_27 . V_6 ) ;
if ( V_44 && V_36 [ V_47 ] ) {
V_43 = F_28 ( V_36 [ V_47 ] ) ;
if ( V_6 > V_43 )
F_25 ( V_6 , V_43 ) ;
}
if ( V_38 )
V_5 = F_23 ( V_40 -> V_15 . V_5 ) ;
for (; V_5 <= V_41 ; V_5 ++ ) {
V_42 = V_38 && V_5 == F_23 ( V_40 -> V_15 . V_5 ) ? F_27 ( V_40 -> V_15 . V_6 )
: V_6 ;
for (; V_42 <= V_43 ; V_42 ++ ) {
V_27 . V_5 = F_29 ( V_5 ) ;
V_27 . V_6 = F_30 ( V_42 ) ;
V_45 = V_25 ( V_18 , & V_27 , & V_29 , & V_29 , V_30 ) ;
if ( V_45 && ! F_22 ( V_45 , V_30 ) )
return V_45 ;
V_45 = 0 ;
}
}
return V_45 ;
}
static inline bool
F_31 ( const struct V_58 * V_2 ,
const struct V_58 * V_3 ,
T_1 * V_4 )
{
return F_32 ( & V_2 -> V_5 . V_59 , & V_3 -> V_5 . V_59 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static bool
F_33 ( struct V_8 * V_9 ,
const struct V_58 * V_10 )
{
if ( F_34 ( V_9 , V_11 , & V_10 -> V_5 . V_59 ) ||
F_4 ( V_9 , V_12 , V_10 -> V_6 ) ||
F_5 ( V_9 , V_13 , V_10 -> V_7 ) )
goto V_14;
return false ;
V_14:
return true ;
}
static inline void
F_35 ( struct V_58 * V_15 ,
const struct V_58 * V_16 )
{
V_15 -> V_6 = V_16 -> V_6 ;
}
static int
F_36 ( struct V_17 * V_18 , const struct V_8 * V_9 ,
const struct V_19 * V_20 ,
enum V_21 V_22 , struct V_23 * V_24 )
{
T_2 V_25 = V_18 -> V_26 -> V_22 [ V_22 ] ;
struct V_58 V_27 = { . V_5 = { . V_60 = { 0 } } } ;
struct V_28 V_29 = F_8 ( V_9 , V_24 , V_18 ) ;
if ( ! F_37 ( V_9 , V_24 -> V_30 & V_31 ,
& V_27 . V_6 , & V_27 . V_7 ) )
return - V_32 ;
F_38 ( V_9 , V_24 -> V_30 & V_33 , & V_27 . V_5 . V_59 ) ;
return V_25 ( V_18 , & V_27 , & V_29 , & V_24 -> V_29 , V_24 -> V_34 ) ;
}
static int
F_39 ( struct V_17 * V_18 , struct V_35 * V_36 [] ,
enum V_21 V_22 , T_1 * V_37 , T_1 V_30 , bool V_38 )
{
const struct V_61 * V_40 = V_18 -> V_10 ;
T_2 V_25 = V_18 -> V_26 -> V_22 [ V_22 ] ;
struct V_58 V_27 = { . V_5 = { . V_60 = { 0 } } } ;
struct V_28 V_29 = F_12 ( V_18 ) ;
T_1 V_6 , V_43 ;
bool V_44 = false ;
int V_45 ;
if ( V_36 [ V_46 ] )
* V_37 = F_13 ( V_36 [ V_46 ] ) ;
if ( F_14 ( ! V_36 [ V_11 ] ||
! F_15 ( V_36 , V_12 ) ||
! F_16 ( V_36 , V_47 ) ) )
return - V_48 ;
if ( F_14 ( V_36 [ V_53 ] ) )
return - V_62 ;
if ( F_14 ( V_36 [ V_54 ] ) ) {
T_3 V_55 = F_20 ( V_36 [ V_54 ] ) ;
if ( V_55 != V_56 )
return - V_57 ;
}
V_45 = F_40 ( V_36 [ V_11 ] , & V_27 . V_5 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_18 ( V_18 , V_36 , & V_29 ) ;
if ( V_45 )
return V_45 ;
V_27 . V_6 = F_19 ( V_36 [ V_12 ] ) ;
if ( V_36 [ V_13 ] ) {
V_27 . V_7 = F_20 ( V_36 [ V_13 ] ) ;
V_44 = F_21 ( V_27 . V_7 ) ;
if ( V_27 . V_7 == 0 )
return - V_49 ;
} else {
return - V_50 ;
}
if ( ! ( V_44 || V_27 . V_7 == V_63 ) )
V_27 . V_6 = 0 ;
if ( V_22 == V_52 || ! V_44 || ! V_36 [ V_47 ] ) {
V_45 = V_25 ( V_18 , & V_27 , & V_29 , & V_29 , V_30 ) ;
return F_22 ( V_45 , V_30 ) ? 0 : V_45 ;
}
V_6 = F_27 ( V_27 . V_6 ) ;
V_43 = F_28 ( V_36 [ V_47 ] ) ;
if ( V_6 > V_43 )
F_25 ( V_6 , V_43 ) ;
if ( V_38 )
V_6 = F_27 ( V_40 -> V_15 . V_6 ) ;
for (; V_6 <= V_43 ; V_6 ++ ) {
V_27 . V_6 = F_30 ( V_6 ) ;
V_45 = V_25 ( V_18 , & V_27 , & V_29 , & V_29 , V_30 ) ;
if ( V_45 && ! F_22 ( V_45 , V_30 ) )
return V_45 ;
V_45 = 0 ;
}
return V_45 ;
}
static int T_4
F_41 ( void )
{
return F_42 ( & V_64 ) ;
}
static void T_5
F_43 ( void )
{
F_44 () ;
F_45 ( & V_64 ) ;
}
