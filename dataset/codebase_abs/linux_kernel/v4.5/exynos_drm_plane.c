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
struct V_11 * V_12 = V_7 -> V_10 . V_12 ;
struct V_13 * V_14 = & V_12 -> V_9 -> V_15 ;
int V_16 , V_17 ;
unsigned int V_18 , V_19 ;
unsigned int V_20 , V_21 ;
unsigned int V_22 , V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
V_16 = V_9 -> V_16 ;
V_17 = V_9 -> V_17 ;
V_18 = V_9 -> V_18 ;
V_19 = V_9 -> V_19 ;
V_20 = V_9 -> V_20 >> 16 ;
V_21 = V_9 -> V_21 >> 16 ;
V_22 = V_9 -> V_22 >> 16 ;
V_23 = V_9 -> V_23 >> 16 ;
V_7 -> V_26 = ( V_22 << 16 ) / V_18 ;
V_7 -> V_27 = ( V_23 << 16 ) / V_19 ;
V_24 = F_1 ( V_16 , V_18 , V_14 -> V_28 ) ;
V_25 = F_1 ( V_17 , V_19 , V_14 -> V_29 ) ;
if ( V_16 < 0 ) {
if ( V_24 )
V_20 += ( ( - V_16 ) * V_7 -> V_26 ) >> 16 ;
V_16 = 0 ;
}
if ( V_17 < 0 ) {
if ( V_25 )
V_21 += ( ( - V_17 ) * V_7 -> V_27 ) >> 16 ;
V_17 = 0 ;
}
V_7 -> V_30 . V_31 = V_20 ;
V_7 -> V_30 . V_32 = V_21 ;
V_7 -> V_30 . V_33 = ( V_24 * V_7 -> V_26 ) >> 16 ;
V_7 -> V_30 . V_34 = ( V_25 * V_7 -> V_27 ) >> 16 ;
V_7 -> V_12 . V_31 = V_16 ;
V_7 -> V_12 . V_32 = V_17 ;
V_7 -> V_12 . V_33 = V_24 ;
V_7 -> V_12 . V_34 = V_25 ;
F_4 ( L_1 ,
V_7 -> V_12 . V_31 , V_7 -> V_12 . V_32 ,
V_7 -> V_12 . V_33 , V_7 -> V_12 . V_34 ) ;
}
static void F_5 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_6 ( V_36 ) ;
struct V_6 * V_7 ;
if ( V_36 -> V_9 ) {
V_7 = F_7 ( V_36 -> V_9 ) ;
if ( V_7 -> V_10 . V_39 )
F_8 ( V_7 -> V_10 . V_39 ) ;
F_9 ( V_7 ) ;
V_36 -> V_9 = NULL ;
}
V_7 = F_10 ( sizeof( * V_7 ) , V_40 ) ;
if ( V_7 ) {
V_7 -> V_41 = V_38 -> V_42 -> V_41 ;
V_36 -> V_9 = & V_7 -> V_10 ;
V_36 -> V_9 -> V_36 = V_36 ;
}
}
static struct V_8 *
F_11 ( struct V_35 * V_36 )
{
struct V_6 * V_7 ;
struct V_6 * V_43 ;
V_7 = F_7 ( V_36 -> V_9 ) ;
V_43 = F_10 ( sizeof( * V_7 ) , V_40 ) ;
if ( ! V_43 )
return NULL ;
F_12 ( V_36 , & V_43 -> V_10 ) ;
V_43 -> V_41 = V_7 -> V_41 ;
return & V_43 -> V_10 ;
}
static void F_13 ( struct V_35 * V_36 ,
struct V_8 * V_44 )
{
struct V_6 * V_45 =
F_7 ( V_44 ) ;
F_14 ( V_36 , V_44 ) ;
F_9 ( V_45 ) ;
}
static int F_15 ( struct V_35 * V_36 ,
struct V_8 * V_9 ,
struct V_46 * V_47 ,
T_1 V_48 )
{
struct V_37 * V_38 = F_6 ( V_36 ) ;
struct V_6 * V_7 =
F_7 ( V_9 ) ;
struct V_49 * V_50 = V_36 -> V_51 -> V_52 ;
const struct V_53 * V_42 = V_38 -> V_42 ;
if ( V_47 == V_50 -> V_54 &&
( V_42 -> V_55 & V_56 ) )
V_7 -> V_41 = V_48 ;
else
return - V_57 ;
return 0 ;
}
static int F_16 ( struct V_35 * V_36 ,
const struct V_8 * V_9 ,
struct V_46 * V_47 ,
T_1 * V_48 )
{
const struct V_6 * V_7 =
F_17 ( V_9 , const struct V_6 , V_10 ) ;
struct V_49 * V_50 = V_36 -> V_51 -> V_52 ;
if ( V_47 == V_50 -> V_54 )
* V_48 = V_7 -> V_41 ;
else
return - V_57 ;
return 0 ;
}
static int
F_18 ( const struct V_53 * V_42 ,
struct V_6 * V_9 )
{
bool V_58 = false , V_59 = false ;
if ( V_42 -> V_55 & V_60 )
return 0 ;
if ( V_9 -> V_30 . V_33 == V_9 -> V_12 . V_33 )
V_58 = true ;
if ( V_9 -> V_30 . V_34 == V_9 -> V_12 . V_34 )
V_59 = true ;
if ( ( V_42 -> V_55 & V_61 ) &&
V_9 -> V_26 == ( 1 << 15 ) )
V_58 = true ;
if ( ( V_42 -> V_55 & V_61 ) &&
V_9 -> V_27 == ( 1 << 15 ) )
V_59 = true ;
if ( V_58 & V_59 )
return 0 ;
F_4 ( L_2 ) ;
return - V_62 ;
}
static int F_19 ( struct V_35 * V_36 ,
struct V_8 * V_9 )
{
struct V_37 * V_38 = F_6 ( V_36 ) ;
struct V_6 * V_7 =
F_7 ( V_9 ) ;
int V_63 = 0 ;
if ( ! V_9 -> V_12 || ! V_9 -> V_39 )
return 0 ;
F_3 ( V_7 ) ;
V_63 = F_18 ( V_38 -> V_42 , V_7 ) ;
return V_63 ;
}
static void F_20 ( struct V_35 * V_36 ,
struct V_8 * V_44 )
{
struct V_8 * V_9 = V_36 -> V_9 ;
struct V_64 * V_65 = F_21 ( V_9 -> V_12 ) ;
struct V_37 * V_38 = F_6 ( V_36 ) ;
if ( ! V_9 -> V_12 )
return;
V_36 -> V_12 = V_9 -> V_12 ;
V_38 -> V_66 = V_9 -> V_39 ;
if ( V_65 -> V_67 -> V_68 )
V_65 -> V_67 -> V_68 ( V_65 , V_38 ) ;
}
static void F_22 ( struct V_35 * V_36 ,
struct V_8 * V_44 )
{
struct V_37 * V_38 = F_6 ( V_36 ) ;
struct V_64 * V_65 = F_21 ( V_44 -> V_12 ) ;
if ( ! V_44 -> V_12 )
return;
if ( V_65 -> V_67 -> V_69 )
V_65 -> V_67 -> V_69 ( V_65 , V_38 ) ;
}
static void F_23 ( struct V_35 * V_36 ,
unsigned int V_41 )
{
struct V_70 * V_51 = V_36 -> V_51 ;
struct V_49 * V_50 = V_51 -> V_52 ;
struct V_46 * V_71 ;
V_71 = V_50 -> V_54 ;
if ( ! V_71 ) {
V_71 = F_24 ( V_51 , 0 , L_3 ,
0 , V_72 - 1 ) ;
if ( ! V_71 )
return;
V_50 -> V_54 = V_71 ;
}
F_25 ( & V_36 -> V_10 , V_71 , V_41 ) ;
}
int F_26 ( struct V_70 * V_51 ,
struct V_37 * V_38 ,
unsigned int V_73 , unsigned long V_74 ,
const struct V_53 * V_42 )
{
int V_75 ;
V_75 = F_27 ( V_51 , & V_38 -> V_10 ,
V_74 ,
& V_76 ,
V_42 -> V_77 ,
V_42 -> V_78 ,
V_42 -> type , NULL ) ;
if ( V_75 ) {
F_28 ( L_4 ) ;
return V_75 ;
}
F_29 ( & V_38 -> V_10 , & V_79 ) ;
V_38 -> V_73 = V_73 ;
V_38 -> V_42 = V_42 ;
F_23 ( & V_38 -> V_10 , V_42 -> V_41 ) ;
return 0 ;
}
