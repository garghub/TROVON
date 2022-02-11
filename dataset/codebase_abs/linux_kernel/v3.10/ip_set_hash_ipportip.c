static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_3 == V_3 -> V_3 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static bool
F_2 ( struct V_8 * V_9 ,
const struct V_1 * V_10 )
{
if ( F_3 ( V_9 , V_11 , V_10 -> V_5 ) ||
F_3 ( V_9 , V_12 , V_10 -> V_3 ) ||
F_4 ( V_9 , V_13 , V_10 -> V_6 ) ||
F_5 ( V_9 , V_14 , V_10 -> V_7 ) )
goto V_15;
return 0 ;
V_15:
return 1 ;
}
static inline void
F_6 ( struct V_1 * V_16 ,
const struct V_1 * V_17 )
{
V_16 -> V_5 = V_17 -> V_5 ;
V_16 -> V_6 = V_17 -> V_6 ;
}
static int
F_7 ( struct V_18 * V_19 , const struct V_8 * V_9 ,
const struct V_20 * V_21 ,
enum V_22 V_23 , struct V_24 * V_25 )
{
const struct V_26 * V_27 = V_19 -> V_10 ;
T_2 V_28 = V_19 -> V_29 -> V_23 [ V_23 ] ;
struct V_1 V_30 = { } ;
struct V_31 V_32 = F_8 ( V_9 , V_25 , V_27 ) ;
if ( ! F_9 ( V_9 , V_25 -> V_33 & V_34 ,
& V_30 . V_6 , & V_30 . V_7 ) )
return - V_35 ;
F_10 ( V_9 , V_25 -> V_33 & V_36 , & V_30 . V_5 ) ;
F_10 ( V_9 , V_25 -> V_33 & V_37 , & V_30 . V_3 ) ;
return V_28 ( V_19 , & V_30 , & V_32 , & V_25 -> V_32 , V_25 -> V_38 ) ;
}
static int
F_11 ( struct V_18 * V_19 , struct V_39 * V_40 [] ,
enum V_22 V_23 , T_1 * V_41 , T_1 V_33 , bool V_42 )
{
const struct V_26 * V_27 = V_19 -> V_10 ;
T_2 V_28 = V_19 -> V_29 -> V_23 [ V_23 ] ;
struct V_1 V_30 = { } ;
struct V_31 V_32 = F_12 ( V_27 ) ;
T_1 V_5 , V_43 , V_44 = 0 , V_6 , V_45 ;
bool V_46 = false ;
int V_47 ;
if ( F_13 ( ! V_40 [ V_11 ] || ! V_40 [ V_12 ] ||
! F_14 ( V_40 , V_13 ) ||
! F_15 ( V_40 , V_48 ) ||
! F_15 ( V_40 , V_49 ) ||
! F_15 ( V_40 , V_50 ) ||
! F_15 ( V_40 , V_51 ) ) )
return - V_52 ;
if ( V_40 [ V_53 ] )
* V_41 = F_16 ( V_40 [ V_53 ] ) ;
V_47 = F_17 ( V_40 [ V_11 ] , & V_30 . V_5 ) ||
F_18 ( V_19 , V_40 , & V_32 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_17 ( V_40 [ V_12 ] , & V_30 . V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_40 [ V_13 ] )
V_30 . V_6 = F_19 ( V_40 [ V_13 ] ) ;
else
return - V_52 ;
if ( V_40 [ V_14 ] ) {
V_30 . V_7 = F_20 ( V_40 [ V_14 ] ) ;
V_46 = F_21 ( V_30 . V_7 ) ;
if ( V_30 . V_7 == 0 )
return - V_54 ;
} else
return - V_55 ;
if ( ! ( V_46 || V_30 . V_7 == V_56 ) )
V_30 . V_6 = 0 ;
if ( V_23 == V_57 ||
! ( V_40 [ V_58 ] || V_40 [ V_59 ] ||
V_40 [ V_48 ] ) ) {
V_47 = V_28 ( V_19 , & V_30 , & V_32 , & V_32 , V_33 ) ;
return F_22 ( V_47 , V_33 ) ? 0 : V_47 ;
}
V_43 = V_5 = F_23 ( V_30 . V_5 ) ;
if ( V_40 [ V_58 ] ) {
V_47 = F_24 ( V_40 [ V_58 ] , & V_43 ) ;
if ( V_47 )
return V_47 ;
if ( V_5 > V_43 )
F_25 ( V_5 , V_43 ) ;
} else if ( V_40 [ V_59 ] ) {
T_3 V_60 = F_20 ( V_40 [ V_59 ] ) ;
if ( ! V_60 || V_60 > 32 )
return - V_61 ;
F_26 ( V_5 , V_43 , V_60 ) ;
}
V_45 = V_6 = F_27 ( V_30 . V_6 ) ;
if ( V_46 && V_40 [ V_48 ] ) {
V_45 = F_28 ( V_40 [ V_48 ] ) ;
if ( V_6 > V_45 )
F_25 ( V_6 , V_45 ) ;
}
if ( V_42 )
V_5 = F_23 ( V_27 -> V_16 . V_5 ) ;
for (; ! F_29 ( V_43 , V_5 ) ; V_5 ++ ) {
V_44 = V_42 && V_5 == F_23 ( V_27 -> V_16 . V_5 ) ? F_27 ( V_27 -> V_16 . V_6 )
: V_6 ;
for (; V_44 <= V_45 ; V_44 ++ ) {
V_30 . V_5 = F_30 ( V_5 ) ;
V_30 . V_6 = F_31 ( V_44 ) ;
V_47 = V_28 ( V_19 , & V_30 , & V_32 , & V_32 , V_33 ) ;
if ( V_47 && ! F_22 ( V_47 , V_33 ) )
return V_47 ;
else
V_47 = 0 ;
}
}
return V_47 ;
}
static inline bool
F_32 ( const struct V_62 * V_2 ,
const struct V_62 * V_3 ,
T_1 * V_4 )
{
return F_33 ( & V_2 -> V_5 . V_63 , & V_3 -> V_5 . V_63 ) &&
F_33 ( & V_2 -> V_3 . V_63 , & V_3 -> V_3 . V_63 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static bool
F_34 ( struct V_8 * V_9 ,
const struct V_62 * V_10 )
{
if ( F_35 ( V_9 , V_11 , & V_10 -> V_5 . V_63 ) ||
F_35 ( V_9 , V_12 , & V_10 -> V_3 . V_63 ) ||
F_4 ( V_9 , V_13 , V_10 -> V_6 ) ||
F_5 ( V_9 , V_14 , V_10 -> V_7 ) )
goto V_15;
return 0 ;
V_15:
return 1 ;
}
static inline void
F_36 ( struct V_1 * V_16 ,
const struct V_62 * V_17 )
{
V_16 -> V_6 = V_17 -> V_6 ;
}
static int
F_37 ( struct V_18 * V_19 , const struct V_8 * V_9 ,
const struct V_20 * V_21 ,
enum V_22 V_23 , struct V_24 * V_25 )
{
const struct V_26 * V_27 = V_19 -> V_10 ;
T_2 V_28 = V_19 -> V_29 -> V_23 [ V_23 ] ;
struct V_62 V_30 = { } ;
struct V_31 V_32 = F_8 ( V_9 , V_25 , V_27 ) ;
if ( ! F_38 ( V_9 , V_25 -> V_33 & V_34 ,
& V_30 . V_6 , & V_30 . V_7 ) )
return - V_35 ;
F_39 ( V_9 , V_25 -> V_33 & V_36 , & V_30 . V_5 . V_63 ) ;
F_39 ( V_9 , V_25 -> V_33 & V_37 , & V_30 . V_3 . V_63 ) ;
return V_28 ( V_19 , & V_30 , & V_32 , & V_25 -> V_32 , V_25 -> V_38 ) ;
}
static int
F_40 ( struct V_18 * V_19 , struct V_39 * V_40 [] ,
enum V_22 V_23 , T_1 * V_41 , T_1 V_33 , bool V_42 )
{
const struct V_26 * V_27 = V_19 -> V_10 ;
T_2 V_28 = V_19 -> V_29 -> V_23 [ V_23 ] ;
struct V_62 V_30 = { } ;
struct V_31 V_32 = F_12 ( V_27 ) ;
T_1 V_6 , V_45 ;
bool V_46 = false ;
int V_47 ;
if ( F_13 ( ! V_40 [ V_11 ] || ! V_40 [ V_12 ] ||
! F_14 ( V_40 , V_13 ) ||
! F_15 ( V_40 , V_48 ) ||
! F_15 ( V_40 , V_49 ) ||
! F_15 ( V_40 , V_50 ) ||
! F_15 ( V_40 , V_51 ) ||
V_40 [ V_58 ] ||
V_40 [ V_59 ] ) )
return - V_52 ;
if ( V_40 [ V_53 ] )
* V_41 = F_16 ( V_40 [ V_53 ] ) ;
V_47 = F_41 ( V_40 [ V_11 ] , & V_30 . V_5 ) ||
F_18 ( V_19 , V_40 , & V_32 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_41 ( V_40 [ V_12 ] , & V_30 . V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_40 [ V_13 ] )
V_30 . V_6 = F_19 ( V_40 [ V_13 ] ) ;
else
return - V_52 ;
if ( V_40 [ V_14 ] ) {
V_30 . V_7 = F_20 ( V_40 [ V_14 ] ) ;
V_46 = F_21 ( V_30 . V_7 ) ;
if ( V_30 . V_7 == 0 )
return - V_54 ;
} else
return - V_55 ;
if ( ! ( V_46 || V_30 . V_7 == V_64 ) )
V_30 . V_6 = 0 ;
if ( V_23 == V_57 || ! V_46 || ! V_40 [ V_48 ] ) {
V_47 = V_28 ( V_19 , & V_30 , & V_32 , & V_32 , V_33 ) ;
return F_22 ( V_47 , V_33 ) ? 0 : V_47 ;
}
V_6 = F_27 ( V_30 . V_6 ) ;
V_45 = F_28 ( V_40 [ V_48 ] ) ;
if ( V_6 > V_45 )
F_25 ( V_6 , V_45 ) ;
if ( V_42 )
V_6 = F_27 ( V_27 -> V_16 . V_6 ) ;
for (; V_6 <= V_45 ; V_6 ++ ) {
V_30 . V_6 = F_31 ( V_6 ) ;
V_47 = V_28 ( V_19 , & V_30 , & V_32 , & V_32 , V_33 ) ;
if ( V_47 && ! F_22 ( V_47 , V_33 ) )
return V_47 ;
else
V_47 = 0 ;
}
return V_47 ;
}
static int T_4
F_42 ( void )
{
return F_43 ( & V_65 ) ;
}
static void T_5
F_44 ( void )
{
F_45 ( & V_65 ) ;
}
