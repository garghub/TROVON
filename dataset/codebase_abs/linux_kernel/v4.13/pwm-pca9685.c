static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 ;
F_5 ( & V_7 -> V_10 ) ;
V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
if ( V_9 -> V_12 & ( V_13 | V_14 ) ) {
F_6 ( & V_7 -> V_10 ) ;
return - V_15 ;
}
F_7 ( V_9 , ( void * ) 1 ) ;
F_6 ( & V_7 -> V_10 ) ;
F_8 ( V_7 -> V_3 . V_16 ) ;
return 0 ;
}
static bool F_9 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
bool V_17 = false ;
F_5 ( & V_7 -> V_10 ) ;
if ( V_9 -> V_18 >= V_19 ) {
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_7 -> V_5 . V_21 ; V_20 ++ )
if ( F_10 ( & V_7 -> V_5 , V_20 ) ) {
V_17 = true ;
break;
}
} else if ( F_11 ( V_9 ) ) {
V_17 = true ;
}
F_6 ( & V_7 -> V_10 ) ;
return V_17 ;
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
unsigned int V_22 ;
F_13 ( V_7 -> V_23 , F_14 ( V_9 -> V_18 ) , & V_22 ) ;
return V_22 & V_24 ;
}
static void F_15 ( struct V_4 * V_5 , unsigned int V_6 ,
int V_22 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
unsigned int V_25 = V_22 ? V_24 : 0 ;
F_16 ( V_7 -> V_23 , F_17 ( V_9 -> V_18 ) , 0 ) ;
F_16 ( V_7 -> V_23 , F_18 ( V_9 -> V_18 ) , 0 ) ;
F_16 ( V_7 -> V_23 , F_14 ( V_9 -> V_18 ) , V_25 ) ;
}
static void F_19 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 ;
F_15 ( V_5 , V_6 , 0 ) ;
F_20 ( V_7 -> V_3 . V_16 ) ;
F_5 ( & V_7 -> V_10 ) ;
V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
F_7 ( V_9 , NULL ) ;
F_6 ( & V_7 -> V_10 ) ;
}
static int F_21 ( struct V_4 * V_3 ,
unsigned int V_6 )
{
return 0 ;
}
static int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
return - V_26 ;
}
static int F_23 ( struct V_4 * V_5 ,
unsigned int V_6 , int V_22 )
{
F_15 ( V_5 , V_6 , V_22 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_7 )
{
struct V_27 * V_16 = V_7 -> V_3 . V_16 ;
F_25 ( & V_7 -> V_10 ) ;
V_7 -> V_5 . V_28 = F_26 ( V_16 ) ;
V_7 -> V_5 . V_29 = V_16 ;
V_7 -> V_5 . V_30 = F_3 ;
V_7 -> V_5 . free = F_19 ;
V_7 -> V_5 . V_31 = F_21 ;
V_7 -> V_5 . V_32 = F_22 ;
V_7 -> V_5 . V_33 = F_23 ;
V_7 -> V_5 . V_34 = F_12 ;
V_7 -> V_5 . V_35 = F_15 ;
V_7 -> V_5 . V_36 = - 1 ;
V_7 -> V_5 . V_21 = V_19 ;
V_7 -> V_5 . V_37 = true ;
return F_27 ( V_16 , & V_7 -> V_5 , V_7 ) ;
}
static inline bool F_9 ( struct V_1 * V_7 ,
struct V_8 * V_9 )
{
return false ;
}
static inline int F_24 ( struct V_1 * V_7 )
{
return 0 ;
}
static void F_28 ( struct V_1 * V_7 , int V_38 )
{
F_29 ( V_7 -> V_23 , V_39 ,
V_40 , V_38 ? V_40 : 0 ) ;
if ( ! V_38 ) {
F_30 ( 500 ) ;
}
}
static int F_31 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_41 , int V_42 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long long V_43 ;
unsigned int V_44 ;
int V_45 ;
if ( V_42 != V_7 -> V_42 ) {
V_45 = F_32 ( V_46 * V_42 ,
V_47 * 1000 ) - 1 ;
if ( V_45 >= V_48 &&
V_45 <= V_49 ) {
F_28 ( V_7 , 1 ) ;
F_16 ( V_7 -> V_23 , V_50 , V_45 ) ;
F_28 ( V_7 , 0 ) ;
V_7 -> V_42 = V_42 ;
} else {
F_33 ( V_3 -> V_16 ,
L_1 ) ;
return - V_26 ;
}
}
V_7 -> V_41 = V_41 ;
if ( V_41 < 1 ) {
if ( V_9 -> V_18 >= V_19 )
V_44 = V_51 ;
else
V_44 = F_18 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , V_24 ) ;
return 0 ;
}
if ( V_41 == V_42 ) {
if ( V_9 -> V_18 >= V_19 )
V_44 = V_52 ;
else
V_44 = F_17 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , 0x0 ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_51 ;
else
V_44 = F_18 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , 0x0 ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_53 ;
else
V_44 = F_14 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , V_24 ) ;
return 0 ;
}
V_43 = V_47 * ( unsigned long long ) V_41 ;
V_43 = F_34 ( V_43 , V_42 ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_52 ;
else
V_44 = F_17 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , ( int ) V_43 & 0xff ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_51 ;
else
V_44 = F_18 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , ( ( int ) V_43 >> 8 ) & 0xf ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_53 ;
else
V_44 = F_14 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_44 ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_54 ;
else
V_44 = F_36 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , 0 ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_53 ;
else
V_44 = F_14 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , 0 ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_51 ;
else
V_44 = F_18 ( V_9 -> V_18 ) ;
F_29 ( V_7 -> V_23 , V_44 , V_24 , 0x0 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_44 ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_51 ;
else
V_44 = F_18 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , V_24 ) ;
if ( V_9 -> V_18 >= V_19 )
V_44 = V_52 ;
else
V_44 = F_17 ( V_9 -> V_18 ) ;
F_16 ( V_7 -> V_23 , V_44 , 0x0 ) ;
}
static int F_38 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_9 ( V_7 , V_9 ) )
return - V_15 ;
F_8 ( V_3 -> V_16 ) ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
F_37 ( V_3 , V_9 ) ;
F_20 ( V_3 -> V_16 ) ;
}
static int F_40 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_1 * V_7 ;
int V_59 ;
int V_60 ;
V_7 = F_41 ( & V_56 -> V_16 , sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
return - V_62 ;
V_7 -> V_23 = F_42 ( V_56 , & V_63 ) ;
if ( F_43 ( V_7 -> V_23 ) ) {
V_59 = F_44 ( V_7 -> V_23 ) ;
F_33 ( & V_56 -> V_16 , L_2 ,
V_59 ) ;
return V_59 ;
}
V_7 -> V_41 = 0 ;
V_7 -> V_42 = V_64 ;
F_45 ( V_56 , V_7 ) ;
F_13 ( V_7 -> V_23 , V_65 , & V_60 ) ;
if ( F_46 ( & V_56 -> V_16 , L_3 ) )
V_60 |= V_66 ;
else
V_60 &= ~ V_66 ;
if ( F_46 ( & V_56 -> V_16 , L_4 ) )
V_60 &= ~ V_67 ;
else
V_60 |= V_67 ;
F_16 ( V_7 -> V_23 , V_65 , V_60 ) ;
F_16 ( V_7 -> V_23 , V_52 , 0 ) ;
F_16 ( V_7 -> V_23 , V_51 , 0 ) ;
V_7 -> V_3 . V_68 = & V_69 ;
V_7 -> V_3 . V_70 = V_19 + 1 ;
V_7 -> V_3 . V_16 = & V_56 -> V_16 ;
V_7 -> V_3 . V_36 = - 1 ;
V_59 = F_47 ( & V_7 -> V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_24 ( V_7 ) ;
if ( V_59 < 0 ) {
F_48 ( & V_7 -> V_3 ) ;
return V_59 ;
}
F_49 ( & V_56 -> V_16 ) ;
F_50 ( & V_56 -> V_16 ) ;
return 0 ;
}
static int F_51 ( struct V_55 * V_56 )
{
struct V_1 * V_7 = F_52 ( V_56 ) ;
int V_59 ;
V_59 = F_48 ( & V_7 -> V_3 ) ;
if ( V_59 )
return V_59 ;
F_53 ( & V_56 -> V_16 ) ;
return 0 ;
}
static int F_54 ( struct V_27 * V_16 )
{
struct V_55 * V_56 = F_55 ( V_16 ) ;
struct V_1 * V_7 = F_52 ( V_56 ) ;
F_28 ( V_7 , 1 ) ;
return 0 ;
}
static int F_56 ( struct V_27 * V_16 )
{
struct V_55 * V_56 = F_55 ( V_16 ) ;
struct V_1 * V_7 = F_52 ( V_56 ) ;
F_28 ( V_7 , 0 ) ;
return 0 ;
}
