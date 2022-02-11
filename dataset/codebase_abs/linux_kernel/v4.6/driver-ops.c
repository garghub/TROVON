int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 () ;
if ( F_3 ( V_2 -> V_4 ) )
return - V_5 ;
F_4 ( V_2 ) ;
V_2 -> V_4 = true ;
F_5 () ;
V_3 = V_2 -> V_6 -> V_7 ( & V_2 -> V_8 ) ;
F_6 ( V_2 , V_3 ) ;
if ( V_3 )
V_2 -> V_4 = false ;
return V_3 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_2 () ;
if ( F_3 ( ! V_2 -> V_4 ) )
return;
F_8 ( V_2 ) ;
V_2 -> V_6 -> V_9 ( & V_2 -> V_8 ) ;
F_9 ( V_2 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_11 ( & V_2 -> V_10 ) ;
F_12 () ;
V_2 -> V_4 = false ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_3 ;
F_2 () ;
if ( F_3 ( V_12 -> V_13 . type == V_14 ||
( V_12 -> V_13 . type == V_15 &&
! F_14 ( & V_2 -> V_8 , V_16 ) &&
! ( V_12 -> V_17 . V_18 & V_19 ) ) ) )
return - V_20 ;
F_15 ( V_2 , V_12 ) ;
V_3 = V_2 -> V_6 -> V_21 ( & V_2 -> V_8 , & V_12 -> V_13 ) ;
F_6 ( V_2 , V_3 ) ;
if ( V_3 == 0 )
V_12 -> V_22 |= V_23 ;
return V_3 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
enum V_24 type , bool V_25 )
{
int V_3 ;
F_2 () ;
if ( ! F_17 ( V_12 ) )
return - V_26 ;
F_18 ( V_2 , V_12 , type , V_25 ) ;
V_3 = V_2 -> V_6 -> V_27 ( & V_2 -> V_8 , & V_12 -> V_13 , type , V_25 ) ;
F_6 ( V_2 , V_3 ) ;
return V_3 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_2 () ;
if ( ! F_17 ( V_12 ) )
return;
F_20 ( V_2 , V_12 ) ;
V_2 -> V_6 -> V_28 ( & V_2 -> V_8 , & V_12 -> V_13 ) ;
V_12 -> V_22 &= ~ V_23 ;
F_9 ( V_2 ) ;
}
T_1
int F_21 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_29 * V_30 ,
enum V_31 V_32 ,
enum V_31 V_33 )
{
int V_3 = 0 ;
F_2 () ;
V_12 = F_22 ( V_12 ) ;
if ( ! F_17 ( V_12 ) )
return - V_26 ;
F_23 ( V_2 , V_12 , & V_30 -> V_30 , V_32 , V_33 ) ;
if ( V_2 -> V_6 -> V_34 ) {
V_3 = V_2 -> V_6 -> V_34 ( & V_2 -> V_8 , & V_12 -> V_13 , & V_30 -> V_30 ,
V_32 , V_33 ) ;
} else if ( V_32 == V_35 &&
V_33 == V_36 ) {
V_3 = F_24 ( V_2 , V_12 , & V_30 -> V_30 ) ;
if ( V_3 == 0 )
V_30 -> V_37 = true ;
} else if ( V_32 == V_36 &&
V_33 == V_35 ) {
F_25 ( V_2 , V_12 , & V_30 -> V_30 ) ;
}
F_6 ( V_2 , V_3 ) ;
return V_3 ;
}
void F_26 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_38 * V_30 , T_2 V_39 )
{
V_12 = F_22 ( V_12 ) ;
if ( ! F_17 ( V_12 ) )
return;
F_3 ( V_39 & V_40 &&
( V_12 -> V_13 . type != V_41 &&
V_12 -> V_13 . type != V_42 ) ) ;
F_27 ( V_2 , V_12 , V_30 , V_39 ) ;
if ( V_2 -> V_6 -> V_43 )
V_2 -> V_6 -> V_43 ( & V_2 -> V_8 , & V_12 -> V_13 ,
V_30 , V_39 ) ;
F_9 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_3 V_44 ,
const struct V_45 * V_46 )
{
int V_3 = - V_47 ;
F_2 () ;
if ( ! F_17 ( V_12 ) )
return - V_26 ;
if ( F_29 ( V_46 -> V_48 == 0 ||
V_46 -> V_48 > V_46 -> V_49 ,
L_1 ,
V_12 -> V_50 , V_46 -> V_48 , V_46 -> V_49 ) )
return - V_20 ;
F_30 ( V_2 , V_12 , V_44 , V_46 ) ;
if ( V_2 -> V_6 -> V_51 )
V_3 = V_2 -> V_6 -> V_51 ( & V_2 -> V_8 , & V_12 -> V_13 ,
V_44 , V_46 ) ;
F_6 ( V_2 , V_3 ) ;
return V_3 ;
}
T_4 F_31 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_4 V_3 = - 1ULL ;
F_2 () ;
if ( ! F_17 ( V_12 ) )
return V_3 ;
F_32 ( V_2 , V_12 ) ;
if ( V_2 -> V_6 -> V_52 )
V_3 = V_2 -> V_6 -> V_52 ( & V_2 -> V_8 , & V_12 -> V_13 ) ;
F_33 ( V_2 , V_3 ) ;
return V_3 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_4 V_53 )
{
F_2 () ;
if ( ! F_17 ( V_12 ) )
return;
F_35 ( V_2 , V_12 , V_53 ) ;
if ( V_2 -> V_6 -> V_54 )
V_2 -> V_6 -> V_54 ( & V_2 -> V_8 , & V_12 -> V_13 , V_53 ) ;
F_9 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_2 () ;
if ( ! F_17 ( V_12 ) )
return;
F_37 ( V_2 , V_12 ) ;
if ( V_2 -> V_6 -> V_55 )
V_2 -> V_6 -> V_55 ( & V_2 -> V_8 , & V_12 -> V_13 ) ;
F_9 ( V_2 ) ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
int V_58 , enum V_59 V_60 )
{
int V_3 = 0 ;
int V_61 ;
F_2 () ;
if ( ! V_2 -> V_6 -> V_62 )
return - V_47 ;
for ( V_61 = 0 ; V_61 < V_58 ; V_61 ++ ) {
struct V_63 * V_64 =
F_39 ( V_57 [ V_61 ] . V_64 ,
struct V_63 ,
V_65 ) ;
struct V_63 * V_66 =
F_39 ( V_57 [ V_61 ] . V_66 ,
struct V_63 ,
V_65 ) ;
F_40 ( ! V_66 -> V_67 ) ;
F_40 ( ( V_60 == V_68 &&
V_64 -> V_67 ) ||
( V_60 == V_69 &&
! V_64 -> V_67 ) ) ;
}
F_41 ( V_2 , V_57 , V_58 , V_60 ) ;
V_3 = V_2 -> V_6 -> V_62 ( & V_2 -> V_8 ,
V_57 , V_58 , V_60 ) ;
F_6 ( V_2 , V_3 ) ;
if ( ! V_3 && V_60 == V_68 ) {
for ( V_61 = 0 ; V_61 < V_58 ; V_61 ++ ) {
struct V_63 * V_64 =
F_39 ( V_57 [ V_61 ] . V_64 ,
struct V_63 ,
V_65 ) ;
struct V_63 * V_66 =
F_39 ( V_57 [ V_61 ] . V_66 ,
struct V_63 ,
V_65 ) ;
V_64 -> V_67 = true ;
V_66 -> V_67 = false ;
}
}
return V_3 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_70 * V_46 )
{
int V_3 = - V_47 ;
F_2 () ;
V_12 = F_22 ( V_12 ) ;
if ( ! F_17 ( V_12 ) )
return - V_26 ;
F_43 ( V_2 , V_12 , V_46 ) ;
if ( V_2 -> V_6 -> V_71 )
V_3 = V_2 -> V_6 -> V_71 ( & V_2 -> V_8 , & V_12 -> V_13 , V_46 ) ;
F_6 ( V_2 , V_3 ) ;
return V_3 ;
}
