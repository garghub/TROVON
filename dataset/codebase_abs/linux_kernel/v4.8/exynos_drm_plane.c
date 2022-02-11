static int F_1 ( int V_1 , unsigned V_2 , unsigned V_3 )
{
int V_4 = V_1 + V_2 ;
int V_5 = 0 ;
if ( V_1 <= 0 ) {
if ( V_4 > 0 )
V_5 = F_2 ( unsigned , V_4 , V_3 ) ;
} else if ( V_1 <= V_3 ) {
V_5 = F_2 ( unsigned , V_3 - V_1 , V_2 ) ;
}
return V_5 ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_14 =
F_4 ( V_9 -> V_9 , V_12 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
int V_18 , V_19 ;
unsigned int V_20 , V_21 ;
unsigned int V_22 , V_23 ;
unsigned int V_24 , V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
V_18 = V_9 -> V_18 ;
V_19 = V_9 -> V_19 ;
V_20 = V_9 -> V_20 ;
V_21 = V_9 -> V_21 ;
V_22 = V_9 -> V_22 >> 16 ;
V_23 = V_9 -> V_23 >> 16 ;
V_24 = V_9 -> V_24 >> 16 ;
V_25 = V_9 -> V_25 >> 16 ;
V_7 -> V_28 = ( V_24 << 16 ) / V_20 ;
V_7 -> V_29 = ( V_25 << 16 ) / V_21 ;
V_26 = F_1 ( V_18 , V_20 , V_16 -> V_30 ) ;
V_27 = F_1 ( V_19 , V_21 , V_16 -> V_31 ) ;
if ( V_18 < 0 ) {
if ( V_26 )
V_22 += ( ( - V_18 ) * V_7 -> V_28 ) >> 16 ;
V_18 = 0 ;
}
if ( V_19 < 0 ) {
if ( V_27 )
V_23 += ( ( - V_19 ) * V_7 -> V_29 ) >> 16 ;
V_19 = 0 ;
}
V_7 -> V_32 . V_33 = V_22 ;
V_7 -> V_32 . V_34 = V_23 ;
V_7 -> V_32 . V_35 = ( V_26 * V_7 -> V_28 ) >> 16 ;
V_7 -> V_32 . V_36 = ( V_27 * V_7 -> V_29 ) >> 16 ;
V_7 -> V_12 . V_33 = V_18 ;
V_7 -> V_12 . V_34 = V_19 ;
V_7 -> V_12 . V_35 = V_26 ;
V_7 -> V_12 . V_36 = V_27 ;
F_5 ( L_1 ,
V_7 -> V_12 . V_33 , V_7 -> V_12 . V_34 ,
V_7 -> V_12 . V_35 , V_7 -> V_12 . V_36 ) ;
}
static void F_6 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_7 ( V_38 ) ;
struct V_6 * V_7 ;
if ( V_38 -> V_9 ) {
V_7 = F_8 ( V_38 -> V_9 ) ;
if ( V_7 -> V_10 . V_41 )
F_9 ( V_7 -> V_10 . V_41 ) ;
F_10 ( V_7 ) ;
V_38 -> V_9 = NULL ;
}
V_7 = F_11 ( sizeof( * V_7 ) , V_42 ) ;
if ( V_7 ) {
V_38 -> V_9 = & V_7 -> V_10 ;
V_38 -> V_9 -> V_38 = V_38 ;
V_38 -> V_9 -> V_43 = V_40 -> V_44 -> V_43 ;
}
}
static struct V_8 *
F_12 ( struct V_37 * V_38 )
{
struct V_6 * V_7 ;
struct V_6 * V_45 ;
V_7 = F_8 ( V_38 -> V_9 ) ;
V_45 = F_11 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_45 )
return NULL ;
F_13 ( V_38 , & V_45 -> V_10 ) ;
return & V_45 -> V_10 ;
}
static void F_14 ( struct V_37 * V_38 ,
struct V_8 * V_46 )
{
struct V_6 * V_47 =
F_8 ( V_46 ) ;
F_15 ( V_46 ) ;
F_10 ( V_47 ) ;
}
static int
F_16 ( const struct V_48 * V_44 ,
struct V_6 * V_9 )
{
bool V_49 = false , V_50 = false ;
if ( V_44 -> V_51 & V_52 )
return 0 ;
if ( V_9 -> V_32 . V_35 == V_9 -> V_12 . V_35 )
V_49 = true ;
if ( V_9 -> V_32 . V_36 == V_9 -> V_12 . V_36 )
V_50 = true ;
if ( ( V_44 -> V_51 & V_53 ) &&
V_9 -> V_28 == ( 1 << 15 ) )
V_49 = true ;
if ( ( V_44 -> V_51 & V_53 ) &&
V_9 -> V_29 == ( 1 << 15 ) )
V_50 = true ;
if ( V_49 && V_50 )
return 0 ;
F_5 ( L_2 ) ;
return - V_54 ;
}
static int F_17 ( struct V_37 * V_38 ,
struct V_8 * V_9 )
{
struct V_39 * V_40 = F_7 ( V_38 ) ;
struct V_6 * V_7 =
F_8 ( V_9 ) ;
int V_55 = 0 ;
if ( ! V_9 -> V_12 || ! V_9 -> V_41 )
return 0 ;
F_3 ( V_7 ) ;
V_55 = F_16 ( V_40 -> V_44 , V_7 ) ;
return V_55 ;
}
static void F_18 ( struct V_37 * V_38 ,
struct V_8 * V_46 )
{
struct V_8 * V_9 = V_38 -> V_9 ;
struct V_56 * V_57 = F_19 ( V_9 -> V_12 ) ;
struct V_39 * V_40 = F_7 ( V_38 ) ;
if ( ! V_9 -> V_12 )
return;
V_38 -> V_12 = V_9 -> V_12 ;
V_40 -> V_58 = V_9 -> V_41 ;
if ( V_57 -> V_59 -> V_60 )
V_57 -> V_59 -> V_60 ( V_57 , V_40 ) ;
}
static void F_20 ( struct V_37 * V_38 ,
struct V_8 * V_46 )
{
struct V_39 * V_40 = F_7 ( V_38 ) ;
struct V_56 * V_57 = F_19 ( V_46 -> V_12 ) ;
if ( ! V_46 -> V_12 )
return;
if ( V_57 -> V_59 -> V_61 )
V_57 -> V_59 -> V_61 ( V_57 , V_40 ) ;
}
static void F_21 ( struct V_37 * V_38 ,
bool V_62 )
{
if ( V_62 )
F_22 ( V_38 , 0 ) ;
else
F_23 ( V_38 , 0 , 0 , V_63 - 1 ) ;
}
int F_24 ( struct V_64 * V_65 ,
struct V_39 * V_40 ,
unsigned int V_66 , unsigned long V_67 ,
const struct V_48 * V_44 )
{
int V_68 ;
V_68 = F_25 ( V_65 , & V_40 -> V_10 ,
V_67 ,
& V_69 ,
V_44 -> V_70 ,
V_44 -> V_71 ,
V_44 -> type , NULL ) ;
if ( V_68 ) {
F_26 ( L_3 ) ;
return V_68 ;
}
F_27 ( & V_40 -> V_10 , & V_72 ) ;
V_40 -> V_66 = V_66 ;
V_40 -> V_44 = V_44 ;
F_21 ( & V_40 -> V_10 ,
! ( V_44 -> V_51 & V_73 ) ) ;
return 0 ;
}
