static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 ;
}
static bool
F_2 ( struct V_6 * V_7 , const struct V_1 * V_8 )
{
if ( F_3 ( V_7 , V_9 , V_8 -> V_5 ) )
goto V_10;
return false ;
V_10:
return true ;
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
if ( V_33 [ V_39 ] )
* V_34 = F_11 ( V_33 [ V_39 ] ) ;
if ( F_12 ( ! V_33 [ V_9 ] ) )
return - V_40 ;
V_38 = F_13 ( V_33 [ V_9 ] , & V_5 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_14 ( V_13 , V_33 , & V_26 ) ;
if ( V_38 )
return V_38 ;
V_5 &= F_15 ( V_21 -> V_29 ) ;
if ( V_17 == V_41 ) {
V_8 . V_5 = F_16 ( V_5 ) ;
if ( V_8 . V_5 == 0 )
return - V_42 ;
return V_23 ( V_13 , & V_8 , & V_26 , & V_26 , V_27 ) ;
}
V_36 = V_5 ;
if ( V_33 [ V_43 ] ) {
V_38 = F_13 ( V_33 [ V_43 ] , & V_36 ) ;
if ( V_38 )
return V_38 ;
if ( V_5 > V_36 )
F_17 ( V_5 , V_36 ) ;
} else if ( V_33 [ V_44 ] ) {
T_4 V_45 = F_18 ( V_33 [ V_44 ] ) ;
if ( ! V_45 || V_45 > V_46 )
return - V_47 ;
F_19 ( V_5 , V_36 , V_45 ) ;
}
V_37 = V_21 -> V_29 == 32 ? 1 : 2 << ( 32 - V_21 -> V_29 - 1 ) ;
if ( V_35 )
V_5 = F_20 ( V_21 -> V_11 . V_5 ) ;
for (; ! F_21 ( V_36 , V_5 ) ; V_5 += V_37 ) {
V_8 . V_5 = F_16 ( V_5 ) ;
if ( V_8 . V_5 == 0 )
return - V_42 ;
V_38 = V_23 ( V_13 , & V_8 , & V_26 , & V_26 , V_27 ) ;
if ( V_38 && ! F_22 ( V_38 , V_27 ) )
return V_38 ;
V_38 = 0 ;
}
return V_38 ;
}
static inline bool
F_23 ( const struct V_48 * V_49 ,
const struct V_48 * V_50 ,
T_1 * V_4 )
{
return F_24 ( & V_49 -> V_5 . V_51 , & V_50 -> V_5 . V_51 ) ;
}
static inline void
F_25 ( union V_52 * V_5 , T_4 V_53 )
{
F_26 ( V_5 , V_53 ) ;
}
static bool
F_27 ( struct V_6 * V_7 , const struct V_48 * V_8 )
{
if ( F_28 ( V_7 , V_9 , & V_8 -> V_5 . V_51 ) )
goto V_10;
return false ;
V_10:
return true ;
}
static inline void
F_29 ( struct V_1 * V_11 , const struct V_48 * V_8 )
{
}
static int
F_30 ( struct V_12 * V_13 , const struct V_6 * V_7 ,
const struct V_14 * V_15 ,
enum V_16 V_17 , struct V_18 * V_19 )
{
const struct V_20 * V_21 = V_13 -> V_22 ;
T_2 V_23 = V_13 -> V_24 -> V_17 [ V_17 ] ;
struct V_48 V_8 = { { . V_54 = { 0 } } } ;
struct V_25 V_26 = F_6 ( V_7 , V_19 , V_13 ) ;
F_31 ( V_7 , V_19 -> V_27 & V_28 , & V_8 . V_5 . V_51 ) ;
F_25 ( & V_8 . V_5 , V_21 -> V_29 ) ;
if ( F_32 ( & V_8 . V_5 . V_51 ) )
return - V_30 ;
return V_23 ( V_13 , & V_8 , & V_26 , & V_19 -> V_26 , V_19 -> V_31 ) ;
}
static int
F_33 ( struct V_12 * V_13 , struct V_32 * V_33 [] ,
enum V_16 V_17 , T_1 * V_34 , T_1 V_27 , bool V_35 )
{
const struct V_20 * V_21 = V_13 -> V_22 ;
T_2 V_23 = V_13 -> V_24 -> V_17 [ V_17 ] ;
struct V_48 V_8 = { { . V_54 = { 0 } } } ;
struct V_25 V_26 = F_10 ( V_13 ) ;
int V_38 ;
if ( V_33 [ V_39 ] )
* V_34 = F_11 ( V_33 [ V_39 ] ) ;
if ( F_12 ( ! V_33 [ V_9 ] ) )
return - V_40 ;
if ( F_12 ( V_33 [ V_43 ] ) )
return - V_55 ;
if ( F_12 ( V_33 [ V_44 ] ) ) {
T_4 V_45 = F_18 ( V_33 [ V_44 ] ) ;
if ( V_45 != V_46 )
return - V_47 ;
}
V_38 = F_34 ( V_33 [ V_9 ] , & V_8 . V_5 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_14 ( V_13 , V_33 , & V_26 ) ;
if ( V_38 )
return V_38 ;
F_25 ( & V_8 . V_5 , V_21 -> V_29 ) ;
if ( F_32 ( & V_8 . V_5 . V_51 ) )
return - V_42 ;
V_38 = V_23 ( V_13 , & V_8 , & V_26 , & V_26 , V_27 ) ;
return F_22 ( V_38 , V_27 ) ? 0 : V_38 ;
}
static int T_5
F_35 ( void )
{
return F_36 ( & V_56 ) ;
}
static void T_6
F_37 ( void )
{
F_38 () ;
F_39 ( & V_56 ) ;
}
