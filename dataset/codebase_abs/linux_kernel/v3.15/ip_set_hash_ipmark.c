static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static bool
F_2 ( struct V_7 * V_8 ,
const struct V_1 * V_9 )
{
if ( F_3 ( V_8 , V_10 , V_9 -> V_5 ) ||
F_4 ( V_8 , V_11 , F_5 ( V_9 -> V_6 ) ) )
goto V_12;
return 0 ;
V_12:
return 1 ;
}
static inline void
F_6 ( struct V_1 * V_13 ,
const struct V_1 * V_14 )
{
V_13 -> V_5 = V_14 -> V_5 ;
}
static int
F_7 ( struct V_15 * V_16 , const struct V_7 * V_8 ,
const struct V_17 * V_18 ,
enum V_19 V_20 , struct V_21 * V_22 )
{
const struct V_23 * V_24 = V_16 -> V_9 ;
T_2 V_25 = V_16 -> V_26 -> V_20 [ V_20 ] ;
struct V_1 V_27 = { } ;
struct V_28 V_29 = F_8 ( V_8 , V_22 , V_16 ) ;
V_27 . V_6 = V_8 -> V_6 ;
V_27 . V_6 &= V_24 -> V_30 ;
F_9 ( V_8 , V_22 -> V_31 & V_32 , & V_27 . V_5 ) ;
return V_25 ( V_16 , & V_27 , & V_29 , & V_22 -> V_29 , V_22 -> V_33 ) ;
}
static int
F_10 ( struct V_15 * V_16 , struct V_34 * V_35 [] ,
enum V_19 V_20 , T_1 * V_36 , T_1 V_31 , bool V_37 )
{
const struct V_23 * V_24 = V_16 -> V_9 ;
T_2 V_25 = V_16 -> V_26 -> V_20 [ V_20 ] ;
struct V_1 V_27 = { } ;
struct V_28 V_29 = F_11 ( V_16 ) ;
T_1 V_5 , V_38 = 0 ;
int V_39 ;
if ( F_12 ( ! V_35 [ V_10 ] ||
! F_13 ( V_35 , V_11 ) ||
! F_14 ( V_35 , V_40 ) ||
! F_14 ( V_35 , V_41 ) ||
! F_14 ( V_35 , V_42 ) ) )
return - V_43 ;
if ( V_35 [ V_44 ] )
* V_36 = F_15 ( V_35 [ V_44 ] ) ;
V_39 = F_16 ( V_35 [ V_10 ] , & V_27 . V_5 ) ||
F_17 ( V_16 , V_35 , & V_29 ) ;
if ( V_39 )
return V_39 ;
V_27 . V_6 = F_18 ( F_15 ( V_35 [ V_11 ] ) ) ;
V_27 . V_6 &= V_24 -> V_30 ;
if ( V_20 == V_45 ||
! ( V_35 [ V_46 ] || V_35 [ V_47 ] ) ) {
V_39 = V_25 ( V_16 , & V_27 , & V_29 , & V_29 , V_31 ) ;
return F_19 ( V_39 , V_31 ) ? 0 : V_39 ;
}
V_38 = V_5 = F_18 ( V_27 . V_5 ) ;
if ( V_35 [ V_46 ] ) {
V_39 = F_20 ( V_35 [ V_46 ] , & V_38 ) ;
if ( V_39 )
return V_39 ;
if ( V_5 > V_38 )
F_21 ( V_5 , V_38 ) ;
} else if ( V_35 [ V_47 ] ) {
T_3 V_48 = F_22 ( V_35 [ V_47 ] ) ;
if ( ! V_48 || V_48 > 32 )
return - V_49 ;
F_23 ( V_5 , V_38 , V_48 ) ;
}
if ( V_37 )
V_5 = F_18 ( V_24 -> V_13 . V_5 ) ;
for (; ! F_24 ( V_38 , V_5 ) ; V_5 ++ ) {
V_27 . V_5 = F_5 ( V_5 ) ;
V_39 = V_25 ( V_16 , & V_27 , & V_29 , & V_29 , V_31 ) ;
if ( V_39 && ! F_19 ( V_39 , V_31 ) )
return V_39 ;
else
V_39 = 0 ;
}
return V_39 ;
}
static inline bool
F_25 ( const struct V_50 * V_2 ,
const struct V_50 * V_3 ,
T_1 * V_4 )
{
return F_26 ( & V_2 -> V_5 . V_51 , & V_3 -> V_5 . V_51 ) &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static bool
F_27 ( struct V_7 * V_8 ,
const struct V_50 * V_9 )
{
if ( F_28 ( V_8 , V_10 , & V_9 -> V_5 . V_51 ) ||
F_4 ( V_8 , V_11 , F_5 ( V_9 -> V_6 ) ) )
goto V_12;
return 0 ;
V_12:
return 1 ;
}
static inline void
F_29 ( struct V_1 * V_13 ,
const struct V_50 * V_14 )
{
}
static int
F_30 ( struct V_15 * V_16 , const struct V_7 * V_8 ,
const struct V_17 * V_18 ,
enum V_19 V_20 , struct V_21 * V_22 )
{
const struct V_23 * V_24 = V_16 -> V_9 ;
T_2 V_25 = V_16 -> V_26 -> V_20 [ V_20 ] ;
struct V_50 V_27 = { } ;
struct V_28 V_29 = F_8 ( V_8 , V_22 , V_16 ) ;
V_27 . V_6 = V_8 -> V_6 ;
V_27 . V_6 &= V_24 -> V_30 ;
F_31 ( V_8 , V_22 -> V_31 & V_32 , & V_27 . V_5 . V_51 ) ;
return V_25 ( V_16 , & V_27 , & V_29 , & V_22 -> V_29 , V_22 -> V_33 ) ;
}
static int
F_32 ( struct V_15 * V_16 , struct V_34 * V_35 [] ,
enum V_19 V_20 , T_1 * V_36 , T_1 V_31 , bool V_37 )
{
const struct V_23 * V_24 = V_16 -> V_9 ;
T_2 V_25 = V_16 -> V_26 -> V_20 [ V_20 ] ;
struct V_50 V_27 = { } ;
struct V_28 V_29 = F_11 ( V_16 ) ;
int V_39 ;
if ( F_12 ( ! V_35 [ V_10 ] ||
! F_13 ( V_35 , V_11 ) ||
! F_14 ( V_35 , V_40 ) ||
! F_14 ( V_35 , V_41 ) ||
! F_14 ( V_35 , V_42 ) ||
V_35 [ V_46 ] ||
V_35 [ V_47 ] ) )
return - V_43 ;
if ( V_35 [ V_44 ] )
* V_36 = F_15 ( V_35 [ V_44 ] ) ;
V_39 = F_33 ( V_35 [ V_10 ] , & V_27 . V_5 ) ||
F_17 ( V_16 , V_35 , & V_29 ) ;
if ( V_39 )
return V_39 ;
V_27 . V_6 = F_18 ( F_15 ( V_35 [ V_11 ] ) ) ;
V_27 . V_6 &= V_24 -> V_30 ;
if ( V_20 == V_45 ) {
V_39 = V_25 ( V_16 , & V_27 , & V_29 , & V_29 , V_31 ) ;
return F_19 ( V_39 , V_31 ) ? 0 : V_39 ;
}
V_39 = V_25 ( V_16 , & V_27 , & V_29 , & V_29 , V_31 ) ;
if ( V_39 && ! F_19 ( V_39 , V_31 ) )
return V_39 ;
else
V_39 = 0 ;
return V_39 ;
}
static int T_4
F_34 ( void )
{
return F_35 ( & V_52 ) ;
}
static void T_5
F_36 ( void )
{
F_37 ( & V_52 ) ;
}
