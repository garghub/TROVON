static inline int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
return - V_3 ;
return V_4 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
if ( V_6 -> V_9 . V_10 . V_11 )
return F_1 ( & V_8 -> V_12 ) ;
return V_4 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
if ( V_8 -> V_13 )
return V_8 -> V_13 ;
return V_4 ;
}
static void F_5 ( struct V_5 * V_6 ,
int V_14 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
V_8 -> V_13 = V_14 ;
}
static void F_6 ( struct V_5 * V_6 )
{
F_7 ( & V_6 -> V_9 . V_8 . V_12 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
struct V_15 V_16 ;
int V_17 ;
int V_18 = F_3 ( V_6 ) ;
int V_19 = F_4 ( V_6 ) ;
memcpy ( & V_16 , & V_8 -> V_20 , sizeof( V_16 ) ) ;
V_8 -> V_21 &= ~ V_22 ;
if ( V_18 >= V_19 ) {
F_5 ( V_6 ,
V_18 ) ;
return;
}
V_17 = ( V_8 -> V_20 . V_23 == V_24 ) ? V_25 : V_24 ;
if ( V_8 -> V_21 & V_26 )
V_16 . V_23 = V_17 ;
if ( V_8 -> V_21 & V_27 )
V_16 . V_28 = V_17 ;
F_9 ( V_6 , V_16 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
struct V_15 V_16 ;
int V_29 ;
int V_30 ;
memcpy ( & V_16 , & V_8 -> V_20 , sizeof( V_16 ) ) ;
V_29 = F_3 ( V_6 ) ;
V_30 = F_4 ( V_6 ) ;
F_5 ( V_6 , V_29 ) ;
if ( abs ( V_29 - V_30 ) < 5 )
return;
V_8 -> V_21 |= V_22 ;
if ( V_8 -> V_21 & V_26 )
V_16 . V_23 = ( V_16 . V_23 == V_24 ) ? V_25 : V_24 ;
if ( V_8 -> V_21 & V_27 )
V_16 . V_28 = ( V_16 . V_28 == V_24 ) ? V_25 : V_24 ;
F_9 ( V_6 , V_16 ) ;
}
static bool F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
if ( ! ( V_8 -> V_21 & V_26 ) &&
! ( V_8 -> V_21 & V_27 ) ) {
V_8 -> V_21 = 0 ;
return true ;
}
if ( V_8 -> V_21 & V_22 ) {
F_8 ( V_6 ) ;
return true ;
} else if ( V_6 -> V_9 . V_31 & 1 ) {
F_10 ( V_6 ) ;
return true ;
}
return false ;
}
void F_12 ( struct V_5 * V_6 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_9 * V_9 = & V_6 -> V_9 ;
struct V_36 * V_10 = & V_6 -> V_9 . V_10 ;
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
struct V_37 * V_38 = (struct V_37 * ) V_33 -> V_39 ;
if ( ! V_6 -> V_40 )
return;
V_10 -> V_11 ++ ;
if ( ! F_13 ( V_38 -> V_41 ) ||
! ( V_35 -> V_42 & V_43 ) )
return;
F_14 ( & V_9 -> V_44 , - V_35 -> V_14 ) ;
F_14 ( & V_8 -> V_12 , - V_35 -> V_14 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = & V_6 -> V_9 ;
if ( ! V_6 -> V_45 && ! V_6 -> V_40 )
return;
if ( F_16 ( V_46 , & V_6 -> V_21 ) )
return;
F_17 ( V_6 , false ) ;
if ( F_16 ( V_47 , & V_6 -> V_21 ) )
F_18 ( V_6 -> V_48 ,
& V_9 -> V_49 , V_50 ) ;
}
void F_19 ( struct V_5 * V_6 )
{
F_20 ( & V_6 -> V_9 . V_49 ) ;
}
void F_17 ( struct V_5 * V_6 , bool V_51 )
{
struct V_36 * V_10 = & V_6 -> V_9 . V_10 ;
T_1 V_52 = V_10 -> V_53 ;
if ( ! F_16 ( V_54 , & V_6 -> V_21 ) )
return;
V_6 -> V_9 . V_31 = 0 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
F_7 ( & V_6 -> V_9 . V_44 ) ;
V_10 -> V_53 = V_52 ;
V_6 -> V_55 -> V_56 -> V_57 ( V_6 , V_10 ) ;
if ( V_51 )
F_6 ( V_6 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_36 * V_10 = & V_6 -> V_9 . V_10 ;
V_10 -> V_11 = 0 ;
V_10 -> V_58 = 0 ;
V_10 -> V_59 = 0 ;
V_10 -> V_60 = 0 ;
}
static void F_22 ( struct V_5 * V_6 , struct V_9 * V_9 )
{
struct V_36 * V_10 = & V_6 -> V_9 . V_10 ;
V_6 -> V_55 -> V_56 -> V_61 ( V_6 , V_10 ) ;
V_6 -> V_62 . V_63 += V_10 -> V_58 ;
if ( ! V_10 -> V_11 )
V_10 -> V_14 = V_4 ;
else
V_10 -> V_14 = F_1 ( & V_9 -> V_44 ) ;
if ( F_23 ( V_6 ) )
V_6 -> V_55 -> V_56 -> V_64 ( V_6 , V_10 , V_9 -> V_31 ) ;
F_24 ( V_6 , V_10 -> V_14 ) ;
if ( F_11 ( V_6 ) )
F_21 ( V_6 ) ;
}
static void F_25 ( struct V_65 * V_49 )
{
struct V_5 * V_6 =
F_26 ( V_49 , struct V_5 , V_9 . V_49 . V_49 ) ;
struct V_9 * V_9 = & V_6 -> V_9 ;
if ( ! F_16 ( V_54 , & V_6 -> V_21 ) ||
F_16 ( V_46 , & V_6 -> V_21 ) )
return;
F_27 ( & V_6 -> V_66 ) ;
if ( V_6 -> V_40 )
F_22 ( V_6 , V_9 ) ;
if ( V_6 -> V_55 -> V_56 -> V_67 &&
( V_9 -> V_31 % ( V_68 / V_69 ) ) == 0 )
V_6 -> V_55 -> V_56 -> V_67 ( V_6 ) ;
if ( V_6 -> V_55 -> V_56 -> V_70 &&
F_28 ( V_6 ) &&
( V_9 -> V_31 % ( V_71 / V_69 ) ) == 0 )
V_6 -> V_55 -> V_56 -> V_70 ( V_6 ) ;
F_29 ( & V_6 -> V_66 ) ;
V_9 -> V_31 ++ ;
if ( F_16 ( V_47 , & V_6 -> V_21 ) )
F_18 ( V_6 -> V_48 ,
& V_9 -> V_49 , V_50 ) ;
}
void F_30 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = & V_6 -> V_9 ;
if ( F_16 ( V_47 , & V_6 -> V_21 ) &&
V_6 -> V_55 -> V_56 -> V_72 )
F_18 ( V_6 -> V_48 ,
& V_9 -> V_73 ,
V_74 ) ;
}
void F_31 ( struct V_5 * V_6 )
{
F_20 ( & V_6 -> V_9 . V_73 ) ;
}
static void F_32 ( struct V_65 * V_49 )
{
struct V_5 * V_6 =
F_26 ( V_49 , struct V_5 , V_9 . V_73 . V_49 ) ;
struct V_9 * V_9 = & V_6 -> V_9 ;
if ( ! F_16 ( V_54 , & V_6 -> V_21 ) )
return;
V_6 -> V_55 -> V_56 -> V_72 ( V_6 ) ;
if ( F_16 ( V_47 , & V_6 -> V_21 ) )
F_18 ( V_6 -> V_48 ,
& V_9 -> V_73 ,
V_74 ) ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( & V_6 -> V_9 . V_73 , F_32 ) ;
F_34 ( & V_6 -> V_9 . V_49 , F_25 ) ;
}
