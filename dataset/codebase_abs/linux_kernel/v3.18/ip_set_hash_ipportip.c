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
T_2 V_26 = V_19 -> V_27 -> V_23 [ V_23 ] ;
struct V_1 V_28 = { . V_5 = 0 } ;
struct V_29 V_30 = F_8 ( V_9 , V_25 , V_19 ) ;
if ( ! F_9 ( V_9 , V_25 -> V_31 & V_32 ,
& V_28 . V_6 , & V_28 . V_7 ) )
return - V_33 ;
F_10 ( V_9 , V_25 -> V_31 & V_34 , & V_28 . V_5 ) ;
F_10 ( V_9 , V_25 -> V_31 & V_35 , & V_28 . V_3 ) ;
return V_26 ( V_19 , & V_28 , & V_30 , & V_25 -> V_30 , V_25 -> V_36 ) ;
}
static int
F_11 ( struct V_18 * V_19 , struct V_37 * V_38 [] ,
enum V_22 V_23 , T_1 * V_39 , T_1 V_31 , bool V_40 )
{
const struct V_41 * V_42 = V_19 -> V_10 ;
T_2 V_26 = V_19 -> V_27 -> V_23 [ V_23 ] ;
struct V_1 V_28 = { . V_5 = 0 } ;
struct V_29 V_30 = F_12 ( V_19 ) ;
T_1 V_5 , V_43 = 0 , V_44 = 0 , V_6 , V_45 ;
bool V_46 = false ;
int V_47 ;
if ( F_13 ( ! V_38 [ V_11 ] || ! V_38 [ V_12 ] ||
! F_14 ( V_38 , V_13 ) ||
! F_15 ( V_38 , V_48 ) ||
! F_15 ( V_38 , V_49 ) ||
! F_15 ( V_38 , V_50 ) ||
! F_15 ( V_38 , V_51 ) ||
! F_15 ( V_38 , V_52 ) ||
! F_15 ( V_38 , V_53 ) ||
! F_15 ( V_38 , V_54 ) ) )
return - V_55 ;
if ( V_38 [ V_56 ] )
* V_39 = F_16 ( V_38 [ V_56 ] ) ;
V_47 = F_17 ( V_38 [ V_11 ] , & V_28 . V_5 ) ||
F_18 ( V_19 , V_38 , & V_30 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_17 ( V_38 [ V_12 ] , & V_28 . V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_38 [ V_13 ] )
V_28 . V_6 = F_19 ( V_38 [ V_13 ] ) ;
else
return - V_55 ;
if ( V_38 [ V_14 ] ) {
V_28 . V_7 = F_20 ( V_38 [ V_14 ] ) ;
V_46 = F_21 ( V_28 . V_7 ) ;
if ( V_28 . V_7 == 0 )
return - V_57 ;
} else
return - V_58 ;
if ( ! ( V_46 || V_28 . V_7 == V_59 ) )
V_28 . V_6 = 0 ;
if ( V_23 == V_60 ||
! ( V_38 [ V_61 ] || V_38 [ V_62 ] ||
V_38 [ V_48 ] ) ) {
V_47 = V_26 ( V_19 , & V_28 , & V_30 , & V_30 , V_31 ) ;
return F_22 ( V_47 , V_31 ) ? 0 : V_47 ;
}
V_43 = V_5 = F_23 ( V_28 . V_5 ) ;
if ( V_38 [ V_61 ] ) {
V_47 = F_24 ( V_38 [ V_61 ] , & V_43 ) ;
if ( V_47 )
return V_47 ;
if ( V_5 > V_43 )
F_25 ( V_5 , V_43 ) ;
} else if ( V_38 [ V_62 ] ) {
T_3 V_63 = F_20 ( V_38 [ V_62 ] ) ;
if ( ! V_63 || V_63 > 32 )
return - V_64 ;
F_26 ( V_5 , V_43 , V_63 ) ;
}
V_45 = V_6 = F_27 ( V_28 . V_6 ) ;
if ( V_46 && V_38 [ V_48 ] ) {
V_45 = F_28 ( V_38 [ V_48 ] ) ;
if ( V_6 > V_45 )
F_25 ( V_6 , V_45 ) ;
}
if ( V_40 )
V_5 = F_23 ( V_42 -> V_16 . V_5 ) ;
for (; ! F_29 ( V_43 , V_5 ) ; V_5 ++ ) {
V_44 = V_40 && V_5 == F_23 ( V_42 -> V_16 . V_5 ) ? F_27 ( V_42 -> V_16 . V_6 )
: V_6 ;
for (; V_44 <= V_45 ; V_44 ++ ) {
V_28 . V_5 = F_30 ( V_5 ) ;
V_28 . V_6 = F_31 ( V_44 ) ;
V_47 = V_26 ( V_19 , & V_28 , & V_30 , & V_30 , V_31 ) ;
if ( V_47 && ! F_22 ( V_47 , V_31 ) )
return V_47 ;
else
V_47 = 0 ;
}
}
return V_47 ;
}
static inline bool
F_32 ( const struct V_65 * V_2 ,
const struct V_65 * V_3 ,
T_1 * V_4 )
{
return F_33 ( & V_2 -> V_5 . V_66 , & V_3 -> V_5 . V_66 ) &&
F_33 ( & V_2 -> V_3 . V_66 , & V_3 -> V_3 . V_66 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static bool
F_34 ( struct V_8 * V_9 ,
const struct V_65 * V_10 )
{
if ( F_35 ( V_9 , V_11 , & V_10 -> V_5 . V_66 ) ||
F_35 ( V_9 , V_12 , & V_10 -> V_3 . V_66 ) ||
F_4 ( V_9 , V_13 , V_10 -> V_6 ) ||
F_5 ( V_9 , V_14 , V_10 -> V_7 ) )
goto V_15;
return 0 ;
V_15:
return 1 ;
}
static inline void
F_36 ( struct V_1 * V_16 ,
const struct V_65 * V_17 )
{
V_16 -> V_6 = V_17 -> V_6 ;
}
static int
F_37 ( struct V_18 * V_19 , const struct V_8 * V_9 ,
const struct V_20 * V_21 ,
enum V_22 V_23 , struct V_24 * V_25 )
{
T_2 V_26 = V_19 -> V_27 -> V_23 [ V_23 ] ;
struct V_65 V_28 = { . V_5 = { . V_67 = { 0 } } } ;
struct V_29 V_30 = F_8 ( V_9 , V_25 , V_19 ) ;
if ( ! F_38 ( V_9 , V_25 -> V_31 & V_32 ,
& V_28 . V_6 , & V_28 . V_7 ) )
return - V_33 ;
F_39 ( V_9 , V_25 -> V_31 & V_34 , & V_28 . V_5 . V_66 ) ;
F_39 ( V_9 , V_25 -> V_31 & V_35 , & V_28 . V_3 . V_66 ) ;
return V_26 ( V_19 , & V_28 , & V_30 , & V_25 -> V_30 , V_25 -> V_36 ) ;
}
static int
F_40 ( struct V_18 * V_19 , struct V_37 * V_38 [] ,
enum V_22 V_23 , T_1 * V_39 , T_1 V_31 , bool V_40 )
{
const struct V_41 * V_42 = V_19 -> V_10 ;
T_2 V_26 = V_19 -> V_27 -> V_23 [ V_23 ] ;
struct V_65 V_28 = { . V_5 = { . V_67 = { 0 } } } ;
struct V_29 V_30 = F_12 ( V_19 ) ;
T_1 V_6 , V_45 ;
bool V_46 = false ;
int V_47 ;
if ( F_13 ( ! V_38 [ V_11 ] || ! V_38 [ V_12 ] ||
! F_14 ( V_38 , V_13 ) ||
! F_15 ( V_38 , V_48 ) ||
! F_15 ( V_38 , V_49 ) ||
! F_15 ( V_38 , V_50 ) ||
! F_15 ( V_38 , V_51 ) ||
! F_15 ( V_38 , V_52 ) ||
! F_15 ( V_38 , V_53 ) ||
! F_15 ( V_38 , V_54 ) ||
V_38 [ V_61 ] ||
V_38 [ V_62 ] ) )
return - V_55 ;
if ( V_38 [ V_56 ] )
* V_39 = F_16 ( V_38 [ V_56 ] ) ;
V_47 = F_41 ( V_38 [ V_11 ] , & V_28 . V_5 ) ||
F_18 ( V_19 , V_38 , & V_30 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_41 ( V_38 [ V_12 ] , & V_28 . V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_38 [ V_13 ] )
V_28 . V_6 = F_19 ( V_38 [ V_13 ] ) ;
else
return - V_55 ;
if ( V_38 [ V_14 ] ) {
V_28 . V_7 = F_20 ( V_38 [ V_14 ] ) ;
V_46 = F_21 ( V_28 . V_7 ) ;
if ( V_28 . V_7 == 0 )
return - V_57 ;
} else
return - V_58 ;
if ( ! ( V_46 || V_28 . V_7 == V_68 ) )
V_28 . V_6 = 0 ;
if ( V_23 == V_60 || ! V_46 || ! V_38 [ V_48 ] ) {
V_47 = V_26 ( V_19 , & V_28 , & V_30 , & V_30 , V_31 ) ;
return F_22 ( V_47 , V_31 ) ? 0 : V_47 ;
}
V_6 = F_27 ( V_28 . V_6 ) ;
V_45 = F_28 ( V_38 [ V_48 ] ) ;
if ( V_6 > V_45 )
F_25 ( V_6 , V_45 ) ;
if ( V_40 )
V_6 = F_27 ( V_42 -> V_16 . V_6 ) ;
for (; V_6 <= V_45 ; V_6 ++ ) {
V_28 . V_6 = F_31 ( V_6 ) ;
V_47 = V_26 ( V_19 , & V_28 , & V_30 , & V_30 , V_31 ) ;
if ( V_47 && ! F_22 ( V_47 , V_31 ) )
return V_47 ;
else
V_47 = 0 ;
}
return V_47 ;
}
static int T_4
F_42 ( void )
{
return F_43 ( & V_69 ) ;
}
static void T_5
F_44 ( void )
{
F_45 ( & V_69 ) ;
}
