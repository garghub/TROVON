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
return 0 ;
V_14:
return 1 ;
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
const struct V_25 * V_26 = V_18 -> V_10 ;
T_2 V_27 = V_18 -> V_28 -> V_22 [ V_22 ] ;
struct V_1 V_29 = { } ;
struct V_30 V_31 = F_8 ( V_9 , V_24 , V_26 ) ;
if ( ! F_9 ( V_9 , V_24 -> V_32 & V_33 ,
& V_29 . V_6 , & V_29 . V_7 ) )
return - V_34 ;
F_10 ( V_9 , V_24 -> V_32 & V_35 , & V_29 . V_5 ) ;
return V_27 ( V_18 , & V_29 , & V_31 , & V_24 -> V_31 , V_24 -> V_36 ) ;
}
static int
F_11 ( struct V_17 * V_18 , struct V_37 * V_38 [] ,
enum V_21 V_22 , T_1 * V_39 , T_1 V_32 , bool V_40 )
{
const struct V_25 * V_26 = V_18 -> V_10 ;
T_2 V_27 = V_18 -> V_28 -> V_22 [ V_22 ] ;
struct V_1 V_29 = { } ;
struct V_30 V_31 = F_12 ( V_26 ) ;
T_1 V_5 , V_41 , V_42 = 0 , V_6 , V_43 ;
bool V_44 = false ;
int V_45 ;
if ( F_13 ( ! V_38 [ V_11 ] ||
! F_14 ( V_38 , V_12 ) ||
! F_15 ( V_38 , V_46 ) ||
! F_15 ( V_38 , V_47 ) ||
! F_15 ( V_38 , V_48 ) ||
! F_15 ( V_38 , V_49 ) ) )
return - V_50 ;
if ( V_38 [ V_51 ] )
* V_39 = F_16 ( V_38 [ V_51 ] ) ;
V_45 = F_17 ( V_38 [ V_11 ] , & V_29 . V_5 ) ||
F_18 ( V_18 , V_38 , & V_31 ) ;
if ( V_45 )
return V_45 ;
if ( V_38 [ V_12 ] )
V_29 . V_6 = F_19 ( V_38 [ V_12 ] ) ;
else
return - V_50 ;
if ( V_38 [ V_13 ] ) {
V_29 . V_7 = F_20 ( V_38 [ V_13 ] ) ;
V_44 = F_21 ( V_29 . V_7 ) ;
if ( V_29 . V_7 == 0 )
return - V_52 ;
} else
return - V_53 ;
if ( ! ( V_44 || V_29 . V_7 == V_54 ) )
V_29 . V_6 = 0 ;
if ( V_22 == V_55 ||
! ( V_38 [ V_56 ] || V_38 [ V_57 ] ||
V_38 [ V_46 ] ) ) {
V_45 = V_27 ( V_18 , & V_29 , & V_31 , & V_31 , V_32 ) ;
return F_22 ( V_45 , V_32 ) ? 0 : V_45 ;
}
V_41 = V_5 = F_23 ( V_29 . V_5 ) ;
if ( V_38 [ V_56 ] ) {
V_45 = F_24 ( V_38 [ V_56 ] , & V_41 ) ;
if ( V_45 )
return V_45 ;
if ( V_5 > V_41 )
F_25 ( V_5 , V_41 ) ;
} else if ( V_38 [ V_57 ] ) {
T_3 V_58 = F_20 ( V_38 [ V_57 ] ) ;
if ( ! V_58 || V_58 > 32 )
return - V_59 ;
F_26 ( V_5 , V_41 , V_58 ) ;
}
V_43 = V_6 = F_27 ( V_29 . V_6 ) ;
if ( V_44 && V_38 [ V_46 ] ) {
V_43 = F_28 ( V_38 [ V_46 ] ) ;
if ( V_6 > V_43 )
F_25 ( V_6 , V_43 ) ;
}
if ( V_40 )
V_5 = F_23 ( V_26 -> V_15 . V_5 ) ;
for (; ! F_29 ( V_41 , V_5 ) ; V_5 ++ ) {
V_42 = V_40 && V_5 == F_23 ( V_26 -> V_15 . V_5 ) ? F_27 ( V_26 -> V_15 . V_6 )
: V_6 ;
for (; V_42 <= V_43 ; V_42 ++ ) {
V_29 . V_5 = F_30 ( V_5 ) ;
V_29 . V_6 = F_31 ( V_42 ) ;
V_45 = V_27 ( V_18 , & V_29 , & V_31 , & V_31 , V_32 ) ;
if ( V_45 && ! F_22 ( V_45 , V_32 ) )
return V_45 ;
else
V_45 = 0 ;
}
}
return V_45 ;
}
static inline bool
F_32 ( const struct V_60 * V_2 ,
const struct V_60 * V_3 ,
T_1 * V_4 )
{
return F_33 ( & V_2 -> V_5 . V_61 , & V_3 -> V_5 . V_61 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static bool
F_34 ( struct V_8 * V_9 ,
const struct V_60 * V_10 )
{
if ( F_35 ( V_9 , V_11 , & V_10 -> V_5 . V_61 ) ||
F_4 ( V_9 , V_12 , V_10 -> V_6 ) ||
F_5 ( V_9 , V_13 , V_10 -> V_7 ) )
goto V_14;
return 0 ;
V_14:
return 1 ;
}
static inline void
F_36 ( struct V_1 * V_15 ,
const struct V_60 * V_16 )
{
V_15 -> V_6 = V_16 -> V_6 ;
}
static int
F_37 ( struct V_17 * V_18 , const struct V_8 * V_9 ,
const struct V_19 * V_20 ,
enum V_21 V_22 , struct V_23 * V_24 )
{
const struct V_25 * V_26 = V_18 -> V_10 ;
T_2 V_27 = V_18 -> V_28 -> V_22 [ V_22 ] ;
struct V_60 V_29 = { } ;
struct V_30 V_31 = F_8 ( V_9 , V_24 , V_26 ) ;
if ( ! F_38 ( V_9 , V_24 -> V_32 & V_33 ,
& V_29 . V_6 , & V_29 . V_7 ) )
return - V_34 ;
F_39 ( V_9 , V_24 -> V_32 & V_35 , & V_29 . V_5 . V_61 ) ;
return V_27 ( V_18 , & V_29 , & V_31 , & V_24 -> V_31 , V_24 -> V_36 ) ;
}
static int
F_40 ( struct V_17 * V_18 , struct V_37 * V_38 [] ,
enum V_21 V_22 , T_1 * V_39 , T_1 V_32 , bool V_40 )
{
const struct V_25 * V_26 = V_18 -> V_10 ;
T_2 V_27 = V_18 -> V_28 -> V_22 [ V_22 ] ;
struct V_60 V_29 = { } ;
struct V_30 V_31 = F_12 ( V_26 ) ;
T_1 V_6 , V_43 ;
bool V_44 = false ;
int V_45 ;
if ( F_13 ( ! V_38 [ V_11 ] ||
! F_14 ( V_38 , V_12 ) ||
! F_15 ( V_38 , V_46 ) ||
! F_15 ( V_38 , V_47 ) ||
! F_15 ( V_38 , V_48 ) ||
! F_15 ( V_38 , V_49 ) ||
V_38 [ V_56 ] ||
V_38 [ V_57 ] ) )
return - V_50 ;
if ( V_38 [ V_51 ] )
* V_39 = F_16 ( V_38 [ V_51 ] ) ;
V_45 = F_41 ( V_38 [ V_11 ] , & V_29 . V_5 ) ||
F_18 ( V_18 , V_38 , & V_31 ) ;
if ( V_45 )
return V_45 ;
if ( V_38 [ V_12 ] )
V_29 . V_6 = F_19 ( V_38 [ V_12 ] ) ;
else
return - V_50 ;
if ( V_38 [ V_13 ] ) {
V_29 . V_7 = F_20 ( V_38 [ V_13 ] ) ;
V_44 = F_21 ( V_29 . V_7 ) ;
if ( V_29 . V_7 == 0 )
return - V_52 ;
} else
return - V_53 ;
if ( ! ( V_44 || V_29 . V_7 == V_62 ) )
V_29 . V_6 = 0 ;
if ( V_22 == V_55 || ! V_44 || ! V_38 [ V_46 ] ) {
V_45 = V_27 ( V_18 , & V_29 , & V_31 , & V_31 , V_32 ) ;
return F_22 ( V_45 , V_32 ) ? 0 : V_45 ;
}
V_6 = F_27 ( V_29 . V_6 ) ;
V_43 = F_28 ( V_38 [ V_46 ] ) ;
if ( V_6 > V_43 )
F_25 ( V_6 , V_43 ) ;
if ( V_40 )
V_6 = F_27 ( V_26 -> V_15 . V_6 ) ;
for (; V_6 <= V_43 ; V_6 ++ ) {
V_29 . V_6 = F_31 ( V_6 ) ;
V_45 = V_27 ( V_18 , & V_29 , & V_31 , & V_31 , V_32 ) ;
if ( V_45 && ! F_22 ( V_45 , V_32 ) )
return V_45 ;
else
V_45 = 0 ;
}
return V_45 ;
}
static int T_4
F_42 ( void )
{
return F_43 ( & V_63 ) ;
}
static void T_5
F_44 ( void )
{
F_45 ( & V_63 ) ;
}
