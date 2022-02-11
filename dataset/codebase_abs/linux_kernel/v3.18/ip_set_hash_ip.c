static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 ;
}
static inline bool
F_2 ( struct V_6 * V_7 , const struct V_1 * V_8 )
{
if ( F_3 ( V_7 , V_9 , V_8 -> V_5 ) )
goto V_10;
return 0 ;
V_10:
return 1 ;
}
static inline void
F_4 ( struct V_1 * V_11 , const struct V_1 * V_8 )
{
V_11 -> V_5 = V_8 -> V_5 ;
}
static int
F_5 ( struct V_12 * V_13 , const struct V_6 * V_7 ,
const struct V_14 * V_15 ,
enum V_16 V_17 , struct V_18 * V_19 )
{
const struct V_20 * V_21 = V_13 -> V_22 ;
T_2 V_23 = V_13 -> V_24 -> V_17 [ V_17 ] ;
struct V_1 V_8 = { 0 } ;
struct V_25 V_26 = F_6 ( V_7 , V_19 , V_13 ) ;
T_3 V_5 ;
F_7 ( V_7 , V_19 -> V_27 & V_28 , & V_5 ) ;
V_5 &= F_8 ( V_21 -> V_29 ) ;
if ( V_5 == 0 )
return - V_30 ;
V_8 . V_5 = V_5 ;
return V_23 ( V_13 , & V_8 , & V_26 , & V_19 -> V_26 , V_19 -> V_31 ) ;
}
static int
F_9 ( struct V_12 * V_13 , struct V_32 * V_33 [] ,
enum V_16 V_17 , T_1 * V_34 , T_1 V_27 , bool V_35 )
{
const struct V_20 * V_21 = V_13 -> V_22 ;
T_2 V_23 = V_13 -> V_24 -> V_17 [ V_17 ] ;
struct V_1 V_8 = { 0 } ;
struct V_25 V_26 = F_10 ( V_13 ) ;
T_1 V_5 = 0 , V_36 = 0 , V_37 ;
int V_38 = 0 ;
if ( F_11 ( ! V_33 [ V_9 ] ||
! F_12 ( V_33 , V_39 ) ||
! F_12 ( V_33 , V_40 ) ||
! F_12 ( V_33 , V_41 ) ||
! F_12 ( V_33 , V_42 ) ||
! F_12 ( V_33 , V_43 ) ||
! F_12 ( V_33 , V_44 ) ) )
return - V_45 ;
if ( V_33 [ V_46 ] )
* V_34 = F_13 ( V_33 [ V_46 ] ) ;
V_38 = F_14 ( V_33 [ V_9 ] , & V_5 ) ||
F_15 ( V_13 , V_33 , & V_26 ) ;
if ( V_38 )
return V_38 ;
V_5 &= F_16 ( V_21 -> V_29 ) ;
if ( V_17 == V_47 ) {
V_8 . V_5 = F_17 ( V_5 ) ;
if ( V_8 . V_5 == 0 )
return - V_48 ;
return V_23 ( V_13 , & V_8 , & V_26 , & V_26 , V_27 ) ;
}
V_36 = V_5 ;
if ( V_33 [ V_49 ] ) {
V_38 = F_14 ( V_33 [ V_49 ] , & V_36 ) ;
if ( V_38 )
return V_38 ;
if ( V_5 > V_36 )
F_18 ( V_5 , V_36 ) ;
} else if ( V_33 [ V_50 ] ) {
T_4 V_51 = F_19 ( V_33 [ V_50 ] ) ;
if ( ! V_51 || V_51 > 32 )
return - V_52 ;
F_20 ( V_5 , V_36 , V_51 ) ;
}
V_37 = V_21 -> V_29 == 32 ? 1 : 2 << ( 32 - V_21 -> V_29 - 1 ) ;
if ( V_35 )
V_5 = F_21 ( V_21 -> V_11 . V_5 ) ;
for (; ! F_22 ( V_36 , V_5 ) ; V_5 += V_37 ) {
V_8 . V_5 = F_17 ( V_5 ) ;
if ( V_8 . V_5 == 0 )
return - V_48 ;
V_38 = V_23 ( V_13 , & V_8 , & V_26 , & V_26 , V_27 ) ;
if ( V_38 && ! F_23 ( V_38 , V_27 ) )
return V_38 ;
else
V_38 = 0 ;
}
return V_38 ;
}
static inline bool
F_24 ( const struct V_53 * V_54 ,
const struct V_53 * V_55 ,
T_1 * V_4 )
{
return F_25 ( & V_54 -> V_5 . V_56 , & V_55 -> V_5 . V_56 ) ;
}
static inline void
F_26 ( union V_57 * V_5 , T_4 V_58 )
{
F_27 ( V_5 , V_58 ) ;
}
static bool
F_28 ( struct V_6 * V_7 , const struct V_53 * V_8 )
{
if ( F_29 ( V_7 , V_9 , & V_8 -> V_5 . V_56 ) )
goto V_10;
return 0 ;
V_10:
return 1 ;
}
static inline void
F_30 ( struct V_1 * V_11 , const struct V_53 * V_8 )
{
}
static int
F_31 ( struct V_12 * V_13 , const struct V_6 * V_7 ,
const struct V_14 * V_15 ,
enum V_16 V_17 , struct V_18 * V_19 )
{
const struct V_20 * V_21 = V_13 -> V_22 ;
T_2 V_23 = V_13 -> V_24 -> V_17 [ V_17 ] ;
struct V_53 V_8 = { { . V_59 = { 0 } } } ;
struct V_25 V_26 = F_6 ( V_7 , V_19 , V_13 ) ;
F_32 ( V_7 , V_19 -> V_27 & V_28 , & V_8 . V_5 . V_56 ) ;
F_26 ( & V_8 . V_5 , V_21 -> V_29 ) ;
if ( F_33 ( & V_8 . V_5 . V_56 ) )
return - V_30 ;
return V_23 ( V_13 , & V_8 , & V_26 , & V_19 -> V_26 , V_19 -> V_31 ) ;
}
static int
F_34 ( struct V_12 * V_13 , struct V_32 * V_33 [] ,
enum V_16 V_17 , T_1 * V_34 , T_1 V_27 , bool V_35 )
{
const struct V_20 * V_21 = V_13 -> V_22 ;
T_2 V_23 = V_13 -> V_24 -> V_17 [ V_17 ] ;
struct V_53 V_8 = { { . V_59 = { 0 } } } ;
struct V_25 V_26 = F_10 ( V_13 ) ;
int V_38 ;
if ( F_11 ( ! V_33 [ V_9 ] ||
! F_12 ( V_33 , V_39 ) ||
! F_12 ( V_33 , V_40 ) ||
! F_12 ( V_33 , V_41 ) ||
! F_12 ( V_33 , V_42 ) ||
! F_12 ( V_33 , V_43 ) ||
! F_12 ( V_33 , V_44 ) ||
V_33 [ V_49 ] ||
V_33 [ V_50 ] ) )
return - V_45 ;
if ( V_33 [ V_46 ] )
* V_34 = F_13 ( V_33 [ V_46 ] ) ;
V_38 = F_35 ( V_33 [ V_9 ] , & V_8 . V_5 ) ||
F_15 ( V_13 , V_33 , & V_26 ) ;
if ( V_38 )
return V_38 ;
F_26 ( & V_8 . V_5 , V_21 -> V_29 ) ;
if ( F_33 ( & V_8 . V_5 . V_56 ) )
return - V_48 ;
V_38 = V_23 ( V_13 , & V_8 , & V_26 , & V_26 , V_27 ) ;
return F_23 ( V_38 , V_27 ) ? 0 : V_38 ;
}
static int T_5
F_36 ( void )
{
return F_37 ( & V_60 ) ;
}
static void T_6
F_38 ( void )
{
F_39 ( & V_60 ) ;
}
