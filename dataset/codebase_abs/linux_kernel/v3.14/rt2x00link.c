static inline int F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 )
return - V_2 ;
return V_3 ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
if ( V_5 -> V_8 . V_9 . V_10 )
return F_1 ( & V_7 -> V_11 ) ;
return V_3 ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
if ( V_7 -> V_12 )
return V_7 -> V_12 ;
return V_3 ;
}
static void F_5 ( struct V_4 * V_5 ,
int V_13 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
V_7 -> V_12 = V_13 ;
}
static void F_6 ( struct V_4 * V_5 )
{
F_7 ( & V_5 -> V_8 . V_7 . V_11 , V_14 ,
V_15 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
struct V_16 V_17 ;
int V_18 ;
int V_19 = F_3 ( V_5 ) ;
int V_20 = F_4 ( V_5 ) ;
memcpy ( & V_17 , & V_7 -> V_21 , sizeof( V_17 ) ) ;
V_7 -> V_22 &= ~ V_23 ;
if ( V_19 >= V_20 ) {
F_5 ( V_5 ,
V_19 ) ;
return;
}
V_18 = ( V_7 -> V_21 . V_24 == V_25 ) ? V_26 : V_25 ;
if ( V_7 -> V_22 & V_27 )
V_17 . V_24 = V_18 ;
if ( V_7 -> V_22 & V_28 )
V_17 . V_29 = V_18 ;
F_9 ( V_5 , V_17 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
struct V_16 V_17 ;
int V_30 ;
int V_31 ;
memcpy ( & V_17 , & V_7 -> V_21 , sizeof( V_17 ) ) ;
V_30 = F_3 ( V_5 ) ;
V_31 = F_4 ( V_5 ) ;
F_5 ( V_5 , V_30 ) ;
if ( abs ( V_30 - V_31 ) < 5 )
return;
V_7 -> V_22 |= V_23 ;
if ( V_7 -> V_22 & V_27 )
V_17 . V_24 = ( V_17 . V_24 == V_25 ) ? V_26 : V_25 ;
if ( V_7 -> V_22 & V_28 )
V_17 . V_29 = ( V_17 . V_29 == V_25 ) ? V_26 : V_25 ;
F_9 ( V_5 , V_17 ) ;
}
static bool F_11 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
if ( ! ( V_7 -> V_22 & V_27 ) &&
! ( V_7 -> V_22 & V_28 ) ) {
V_7 -> V_22 = 0 ;
return true ;
}
if ( V_7 -> V_22 & V_23 ) {
F_8 ( V_5 ) ;
return true ;
} else if ( V_5 -> V_8 . V_32 & 1 ) {
F_10 ( V_5 ) ;
return true ;
}
return false ;
}
void F_12 ( struct V_4 * V_5 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_8 * V_8 = & V_5 -> V_8 ;
struct V_37 * V_9 = & V_5 -> V_8 . V_9 ;
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
struct V_38 * V_39 = (struct V_38 * ) V_34 -> V_40 ;
if ( ! V_5 -> V_41 )
return;
V_9 -> V_10 ++ ;
if ( ! F_13 ( V_39 -> V_42 ) ||
! ( V_36 -> V_43 & V_44 ) )
return;
F_14 ( & V_8 -> V_45 , - V_36 -> V_13 ) ;
F_14 ( & V_7 -> V_11 , - V_36 -> V_13 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( ! V_5 -> V_41 )
return;
if ( F_16 ( V_46 , & V_5 -> V_22 ) )
return;
F_17 ( V_5 , false ) ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_49 , V_50 ) ;
}
void F_19 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_8 . V_49 ) ;
}
void F_17 ( struct V_4 * V_5 , bool V_51 )
{
struct V_37 * V_9 = & V_5 -> V_8 . V_9 ;
T_1 V_52 = V_9 -> V_53 ;
if ( ! F_16 ( V_54 , & V_5 -> V_22 ) )
return;
V_5 -> V_8 . V_32 = 0 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
F_7 ( & V_5 -> V_8 . V_45 , V_14 ,
V_15 ) ;
V_9 -> V_53 = V_52 ;
V_5 -> V_55 -> V_56 -> V_57 ( V_5 , V_9 ) ;
if ( V_51 )
F_6 ( V_5 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
struct V_37 * V_9 = & V_5 -> V_8 . V_9 ;
V_9 -> V_10 = 0 ;
V_9 -> V_58 = 0 ;
V_9 -> V_59 = 0 ;
V_9 -> V_60 = 0 ;
}
static void F_22 ( struct V_61 * V_49 )
{
struct V_4 * V_5 =
F_23 ( V_49 , struct V_4 , V_8 . V_49 . V_49 ) ;
struct V_8 * V_8 = & V_5 -> V_8 ;
struct V_37 * V_9 = & V_5 -> V_8 . V_9 ;
if ( ! F_16 ( V_54 , & V_5 -> V_22 ) ||
F_16 ( V_46 , & V_5 -> V_22 ) )
return;
V_5 -> V_55 -> V_56 -> V_62 ( V_5 , V_9 ) ;
V_5 -> V_63 . V_64 += V_9 -> V_58 ;
if ( ! V_9 -> V_10 )
V_9 -> V_13 = V_3 ;
else
V_9 -> V_13 = F_1 ( & V_8 -> V_45 ) ;
if ( F_24 ( V_5 ) )
V_5 -> V_55 -> V_56 -> V_65 ( V_5 , V_9 , V_8 -> V_32 ) ;
F_25 ( V_5 , V_9 -> V_13 ) ;
if ( F_11 ( V_5 ) )
F_21 ( V_5 ) ;
V_8 -> V_32 ++ ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_49 , V_50 ) ;
}
void F_26 ( struct V_4 * V_5 )
{
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) &&
V_5 -> V_55 -> V_56 -> V_66 )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_67 ,
V_68 ) ;
}
void F_27 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_8 . V_67 ) ;
}
static void F_28 ( struct V_61 * V_49 )
{
struct V_4 * V_5 =
F_23 ( V_49 , struct V_4 , V_8 . V_67 . V_49 ) ;
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( ! F_16 ( V_54 , & V_5 -> V_22 ) )
return;
V_5 -> V_55 -> V_56 -> V_66 ( V_5 ) ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_67 ,
V_68 ) ;
}
void F_29 ( struct V_4 * V_5 )
{
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) &&
V_5 -> V_55 -> V_56 -> V_69 )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_70 ,
V_71 ) ;
}
void F_30 ( struct V_4 * V_5 )
{
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) &&
V_5 -> V_55 -> V_56 -> V_72 )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_73 ,
V_74 ) ;
}
void F_31 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_8 . V_70 ) ;
}
void F_32 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_8 . V_73 ) ;
}
static void F_33 ( struct V_61 * V_49 )
{
struct V_4 * V_5 =
F_23 ( V_49 , struct V_4 , V_8 . V_70 . V_49 ) ;
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( ! F_16 ( V_54 , & V_5 -> V_22 ) )
return;
V_5 -> V_55 -> V_56 -> V_69 ( V_5 ) ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_70 ,
V_71 ) ;
}
static void F_34 ( struct V_61 * V_49 )
{
struct V_4 * V_5 =
F_23 ( V_49 , struct V_4 , V_8 . V_73 . V_49 ) ;
struct V_8 * V_8 = & V_5 -> V_8 ;
if ( ! F_16 ( V_54 , & V_5 -> V_22 ) )
return;
V_5 -> V_55 -> V_56 -> V_72 ( V_5 ) ;
if ( F_16 ( V_47 , & V_5 -> V_22 ) )
F_18 ( V_5 -> V_48 ,
& V_8 -> V_73 ,
V_74 ) ;
}
void F_35 ( struct V_4 * V_5 )
{
F_36 ( & V_5 -> V_8 . V_70 , F_33 ) ;
if ( F_37 ( V_5 ) )
F_36 ( & V_5 -> V_8 . V_73 , F_34 ) ;
F_36 ( & V_5 -> V_8 . V_67 , F_28 ) ;
F_36 ( & V_5 -> V_8 . V_49 , F_22 ) ;
}
