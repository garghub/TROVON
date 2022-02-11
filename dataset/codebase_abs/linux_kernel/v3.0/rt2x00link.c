static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
if ( V_4 -> V_6 . V_7 && V_2 -> V_5 . V_8 . V_9 )
return V_4 -> V_6 . V_7 ;
return V_10 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
if ( V_4 -> V_11 )
return V_4 -> V_11 ;
return V_10 ;
}
static void F_3 ( struct V_1 * V_2 ,
int V_12 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
V_4 -> V_11 = V_12 ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_4 . V_6 . V_7 = 0 ;
V_2 -> V_5 . V_4 . V_6 . V_13 = 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_14 V_15 ;
int V_16 ;
int V_17 = F_1 ( V_2 ) ;
int V_18 = F_2 ( V_2 ) ;
memcpy ( & V_15 , & V_4 -> V_19 , sizeof( V_15 ) ) ;
V_4 -> V_20 &= ~ V_21 ;
if ( V_17 >= V_18 ) {
F_3 ( V_2 ,
V_17 ) ;
return;
}
V_16 = ( V_4 -> V_19 . V_22 == V_23 ) ? V_24 : V_23 ;
if ( V_4 -> V_20 & V_25 )
V_15 . V_22 = V_16 ;
if ( V_4 -> V_20 & V_26 )
V_15 . V_27 = V_16 ;
F_6 ( V_2 , V_15 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_14 V_15 ;
int V_28 ;
int V_29 ;
memcpy ( & V_15 , & V_4 -> V_19 , sizeof( V_15 ) ) ;
V_28 = F_1 ( V_2 ) ;
V_29 = F_2 ( V_2 ) ;
F_3 ( V_2 , V_28 ) ;
if ( abs ( V_28 - V_29 ) < 5 )
return;
V_4 -> V_20 |= V_21 ;
if ( V_4 -> V_20 & V_25 )
V_15 . V_22 = ( V_15 . V_22 == V_23 ) ? V_24 : V_23 ;
if ( V_4 -> V_20 & V_26 )
V_15 . V_27 = ( V_15 . V_27 == V_23 ) ? V_24 : V_23 ;
F_6 ( V_2 , V_15 ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
if ( ! ( V_4 -> V_20 & V_25 ) &&
! ( V_4 -> V_20 & V_26 ) ) {
V_4 -> V_20 = 0 ;
return true ;
}
if ( V_4 -> V_20 & V_21 ) {
F_5 ( V_2 ) ;
return true ;
} else if ( V_2 -> V_5 . V_30 & 1 ) {
F_7 ( V_2 ) ;
return true ;
}
return false ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_5 * V_5 = & V_2 -> V_5 ;
struct V_35 * V_8 = & V_2 -> V_5 . V_8 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_36 * V_37 = (struct V_36 * ) V_32 -> V_38 ;
if ( ! V_2 -> V_39 )
return;
V_8 -> V_9 ++ ;
if ( ! F_10 ( V_37 -> V_40 ) ||
! ( V_34 -> V_41 & V_42 ) )
return;
V_5 -> V_43 = F_11 ( V_5 -> V_43 , V_34 -> V_12 ) ;
V_4 -> V_6 = F_11 ( V_4 -> V_6 , V_34 -> V_12 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_5 ;
if ( ! V_2 -> V_39 )
return;
if ( F_13 ( V_44 , & V_2 -> V_20 ) )
return;
F_14 ( V_2 , false ) ;
if ( F_13 ( V_45 , & V_2 -> V_20 ) )
F_15 ( V_2 -> V_46 ,
& V_5 -> V_47 , V_48 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_5 . V_47 ) ;
}
void F_14 ( struct V_1 * V_2 , bool V_49 )
{
struct V_35 * V_8 = & V_2 -> V_5 . V_8 ;
T_1 V_50 = V_8 -> V_51 ;
if ( ! F_13 ( V_52 , & V_2 -> V_20 ) )
return;
V_2 -> V_5 . V_30 = 0 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_51 = V_50 ;
V_2 -> V_53 -> V_54 -> V_55 ( V_2 , V_8 ) ;
if ( V_49 )
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_35 * V_8 = & V_2 -> V_5 . V_8 ;
V_8 -> V_9 = 0 ;
V_8 -> V_56 = 0 ;
V_8 -> V_57 = 0 ;
V_8 -> V_58 = 0 ;
}
static void F_19 ( struct V_59 * V_47 )
{
struct V_1 * V_2 =
F_20 ( V_47 , struct V_1 , V_5 . V_47 . V_47 ) ;
struct V_5 * V_5 = & V_2 -> V_5 ;
struct V_35 * V_8 = & V_2 -> V_5 . V_8 ;
if ( ! F_13 ( V_52 , & V_2 -> V_20 ) ||
F_13 ( V_44 , & V_2 -> V_20 ) )
return;
V_2 -> V_53 -> V_54 -> V_60 ( V_2 , V_8 ) ;
V_2 -> V_61 . V_62 += V_8 -> V_56 ;
if ( ! V_5 -> V_43 . V_7 || ! V_8 -> V_9 )
V_8 -> V_12 = V_10 ;
else
V_8 -> V_12 = V_5 -> V_43 . V_7 ;
if ( F_13 ( V_63 , & V_2 -> V_64 ) )
V_2 -> V_53 -> V_54 -> V_65 ( V_2 , V_8 , V_5 -> V_30 ) ;
F_21 ( V_2 , V_8 -> V_12 ) ;
if ( F_8 ( V_2 ) )
F_18 ( V_2 ) ;
V_5 -> V_30 ++ ;
if ( F_13 ( V_45 , & V_2 -> V_20 ) )
F_15 ( V_2 -> V_46 ,
& V_5 -> V_47 , V_48 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_5 ;
if ( F_13 ( V_45 , & V_2 -> V_20 ) &&
V_2 -> V_53 -> V_54 -> V_66 )
F_15 ( V_2 -> V_46 ,
& V_5 -> V_67 ,
V_68 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_5 . V_67 ) ;
}
static void F_24 ( struct V_59 * V_47 )
{
struct V_1 * V_2 =
F_20 ( V_47 , struct V_1 , V_5 . V_67 . V_47 ) ;
struct V_5 * V_5 = & V_2 -> V_5 ;
if ( ! F_13 ( V_52 , & V_2 -> V_20 ) )
return;
V_2 -> V_53 -> V_54 -> V_66 ( V_2 ) ;
if ( F_13 ( V_45 , & V_2 -> V_20 ) )
F_15 ( V_2 -> V_46 ,
& V_5 -> V_67 ,
V_68 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_5 ;
if ( F_13 ( V_45 , & V_2 -> V_20 ) &&
V_2 -> V_53 -> V_54 -> V_69 )
F_15 ( V_2 -> V_46 ,
& V_5 -> V_70 ,
V_71 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_5 . V_70 ) ;
}
static void F_27 ( struct V_59 * V_47 )
{
struct V_1 * V_2 =
F_20 ( V_47 , struct V_1 , V_5 . V_70 . V_47 ) ;
struct V_5 * V_5 = & V_2 -> V_5 ;
if ( ! F_13 ( V_52 , & V_2 -> V_20 ) )
return;
V_2 -> V_53 -> V_54 -> V_69 ( V_2 ) ;
if ( F_13 ( V_45 , & V_2 -> V_20 ) )
F_15 ( V_2 -> V_46 ,
& V_5 -> V_70 ,
V_71 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_5 . V_70 , F_27 ) ;
F_29 ( & V_2 -> V_5 . V_67 , F_24 ) ;
F_29 ( & V_2 -> V_5 . V_47 , F_19 ) ;
}
