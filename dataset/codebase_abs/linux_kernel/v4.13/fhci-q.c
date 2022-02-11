static int F_1 ( T_1 V_1 )
{
if ( V_1 == V_2 )
return 0 ;
else if ( V_1 & V_3 )
return - V_4 ;
else if ( V_1 & V_5 )
return - V_6 ;
else if ( V_1 & V_7 )
return - V_8 ;
else if ( V_1 & V_9 )
return - V_6 ;
else if ( V_1 & V_10 )
return - V_4 ;
else if ( V_1 & ( V_11 | V_12 ) )
return - V_13 ;
else if ( V_1 & V_14 )
return - V_15 ;
else if ( V_1 & V_16 )
return - V_17 ;
else if ( V_1 & V_18 )
return - V_19 ;
else if ( V_1 & V_20 )
return - V_21 ;
else
return - V_22 ;
}
void F_2 ( struct V_23 * V_24 , struct V_25 * V_25 )
{
F_3 ( & V_25 -> V_26 , & V_24 -> V_27 ) ;
}
void F_4 ( struct V_28 * V_28 , struct V_25 * * V_29 , int V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
struct V_25 * V_25 = V_29 [ V_31 ] ;
F_3 ( & V_25 -> V_32 , & V_28 -> V_29 ) ;
}
if ( V_28 -> V_33 == NULL )
V_28 -> V_33 = V_29 [ 0 ] ;
}
static struct V_25 * F_5 ( struct V_28 * V_28 )
{
struct V_25 * V_25 ;
if ( ! F_6 ( & V_28 -> V_29 ) )
V_25 = F_7 ( V_28 -> V_29 . V_34 , struct V_25 , V_32 ) ;
else
V_25 = NULL ;
return V_25 ;
}
struct V_25 * F_8 ( struct V_23 * V_24 )
{
struct V_25 * V_25 ;
if ( ! F_6 ( & V_24 -> V_27 ) ) {
V_25 = F_7 ( V_24 -> V_27 . V_34 , struct V_25 , V_26 ) ;
F_9 ( V_24 -> V_27 . V_34 ) ;
} else
V_25 = NULL ;
return V_25 ;
}
struct V_25 * F_10 ( struct V_23 * V_24 )
{
struct V_25 * V_25 ;
if ( ! F_6 ( & V_24 -> V_27 ) )
V_25 = F_7 ( V_24 -> V_27 . V_34 , struct V_25 , V_26 ) ;
else
V_25 = NULL ;
return V_25 ;
}
struct V_25 * F_11 ( struct V_28 * V_28 )
{
struct V_25 * V_25 ;
if ( ! F_6 ( & V_28 -> V_29 ) ) {
V_25 = F_7 ( V_28 -> V_29 . V_34 , struct V_25 , V_32 ) ;
F_9 ( V_28 -> V_29 . V_34 ) ;
if ( ! F_6 ( & V_28 -> V_29 ) )
V_28 -> V_33 = F_7 ( V_28 -> V_29 . V_34 , struct V_25 ,
V_32 ) ;
else
V_28 -> V_33 = NULL ;
} else
V_25 = NULL ;
return V_25 ;
}
struct V_25 * F_12 ( struct V_35 * V_36 )
{
struct V_25 * V_25 ;
if ( ! F_6 ( & V_36 -> V_37 ) ) {
V_25 = F_7 ( V_36 -> V_37 . V_34 , struct V_25 , V_32 ) ;
F_9 ( V_36 -> V_37 . V_34 ) ;
} else
V_25 = NULL ;
return V_25 ;
}
void F_13 ( struct V_38 * V_39 , struct V_28 * V_28 )
{
struct V_25 * V_25 ;
V_25 = V_28 -> V_33 ;
F_9 ( & V_25 -> V_32 ) ;
if ( ! F_6 ( & V_28 -> V_29 ) )
V_28 -> V_33 = F_7 ( V_28 -> V_29 . V_34 , struct V_25 , V_32 ) ;
else {
V_28 -> V_33 = NULL ;
V_28 -> V_40 = V_41 ;
}
V_28 -> V_42 = V_25 -> V_43 ;
F_3 ( & V_25 -> V_32 , & V_39 -> V_44 -> V_37 ) ;
if ( V_25 -> V_45 )
V_39 -> V_46 ( V_39 -> V_47 ) ;
}
static void F_14 ( struct V_48 * V_47 , struct V_49 * V_49 )
{
int V_31 ;
struct V_50 * V_50 = V_49 -> V_51 ;
struct V_28 * V_28 = V_50 -> V_28 ;
for ( V_31 = 0 ; V_31 < V_50 -> V_52 ; V_31 ++ ) {
F_9 ( & V_50 -> V_53 [ V_31 ] -> V_32 ) ;
F_15 ( V_47 , V_50 -> V_53 [ V_31 ] ) ;
}
if ( ! F_6 ( & V_28 -> V_29 ) )
V_28 -> V_33 = F_7 ( V_28 -> V_29 . V_34 , struct V_25 , V_32 ) ;
else
V_28 -> V_33 = NULL ;
F_16 ( V_50 -> V_53 ) ;
F_16 ( V_50 ) ;
V_49 -> V_51 = NULL ;
if ( V_28 -> V_33 == NULL )
F_9 ( & V_28 -> V_32 ) ;
V_47 -> V_54 -- ;
}
void F_17 ( struct V_48 * V_47 , struct V_49 * V_49 )
{
F_14 ( V_47 , V_49 ) ;
if ( V_49 -> V_1 == - V_55 ) {
if ( V_49 -> V_56 != V_49 -> V_57 &&
V_49 -> V_58 & V_59 )
V_49 -> V_1 = - V_19 ;
else
V_49 -> V_1 = 0 ;
}
F_18 ( F_19 ( V_47 ) , V_49 ) ;
F_20 ( & V_47 -> V_60 ) ;
F_21 ( F_19 ( V_47 ) , V_49 , V_49 -> V_1 ) ;
F_22 ( & V_47 -> V_60 ) ;
}
void F_23 ( struct V_49 * V_49 , struct V_25 * V_25 )
{
struct V_28 * V_28 = V_25 -> V_28 ;
T_1 V_61 = V_25 -> V_1 ;
if ( V_28 -> V_62 == V_63 ) {
T_1 V_64 ;
if ( ! ( V_49 -> V_58 & V_59 &&
V_61 == V_18 ) )
V_61 = V_2 ;
if ( F_24 ( V_49 -> V_65 ) )
V_64 = V_49 -> V_66 [ V_25 -> V_67 ] . V_68 ;
else
V_64 = V_25 -> V_69 ;
V_49 -> V_56 += V_64 ;
V_49 -> V_66 [ V_25 -> V_67 ] . V_56 = V_64 ;
V_49 -> V_66 [ V_25 -> V_67 ] . V_1 =
F_1 ( V_61 ) ;
}
else {
if ( V_25 -> V_70 >= 3 )
V_49 -> V_71 = 3 ;
if ( ! ( V_49 -> V_58 & V_59 ) &&
V_61 == V_18 ) {
V_28 -> V_40 = V_72 ;
V_61 = V_2 ;
}
if ( V_61 != V_2 ) {
if ( V_49 -> V_1 == - V_55 )
V_49 -> V_1 = F_1 ( V_61 ) ;
}
if ( V_25 -> type != V_73 || V_25 -> V_67 != 0 )
V_49 -> V_56 += V_25 -> V_69 ;
}
}
void F_25 ( struct V_48 * V_47 , struct V_28 * V_28 )
{
struct V_25 * V_25 = F_5 ( V_28 ) ;
struct V_49 * V_49 = V_25 -> V_49 ;
struct V_50 * V_50 = V_49 -> V_51 ;
if ( V_50 -> V_40 == V_74 ) {
V_25 = F_11 ( V_28 ) ;
if ( V_25 -> V_1 != V_75 )
F_23 ( V_49 , V_25 ) ;
if ( ++ ( V_50 -> V_76 ) == V_50 -> V_52 )
F_17 ( V_47 , V_49 ) ;
}
}
