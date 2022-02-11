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
return 0 ;
}
static void F_8 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 ;
F_5 ( & V_7 -> V_10 ) ;
V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
F_7 ( V_9 , NULL ) ;
F_6 ( & V_7 -> V_10 ) ;
}
static bool F_9 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
bool V_16 = false ;
F_5 ( & V_7 -> V_10 ) ;
if ( V_9 -> V_17 >= V_18 ) {
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_7 -> V_5 . V_20 ; V_19 ++ )
if ( F_10 ( & V_7 -> V_5 , V_19 ) ) {
V_16 = true ;
break;
}
} else if ( F_11 ( V_9 ) ) {
V_16 = true ;
}
F_6 ( & V_7 -> V_10 ) ;
return V_16 ;
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
unsigned int V_21 ;
F_13 ( V_7 -> V_22 , F_14 ( V_9 -> V_17 ) , & V_21 ) ;
return V_21 & V_23 ;
}
static void F_15 ( struct V_4 * V_5 , unsigned int V_6 ,
int V_21 )
{
struct V_1 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 = & V_7 -> V_3 . V_11 [ V_6 ] ;
unsigned int V_24 = V_21 ? V_23 : 0 ;
F_16 ( V_7 -> V_22 , F_17 ( V_9 -> V_17 ) , 0 ) ;
F_16 ( V_7 -> V_22 , F_18 ( V_9 -> V_17 ) , 0 ) ;
F_16 ( V_7 -> V_22 , F_14 ( V_9 -> V_17 ) , V_24 ) ;
}
static int F_19 ( struct V_4 * V_3 ,
unsigned int V_6 )
{
return 0 ;
}
static int F_20 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
return - V_25 ;
}
static int F_21 ( struct V_4 * V_5 ,
unsigned int V_6 , int V_21 )
{
F_15 ( V_5 , V_6 , V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_7 )
{
struct V_26 * V_27 = V_7 -> V_3 . V_27 ;
F_23 ( & V_7 -> V_10 ) ;
V_7 -> V_5 . V_28 = F_24 ( V_27 ) ;
V_7 -> V_5 . V_29 = V_27 ;
V_7 -> V_5 . V_30 = F_3 ;
V_7 -> V_5 . free = F_8 ;
V_7 -> V_5 . V_31 = F_19 ;
V_7 -> V_5 . V_32 = F_20 ;
V_7 -> V_5 . V_33 = F_21 ;
V_7 -> V_5 . V_34 = F_12 ;
V_7 -> V_5 . V_35 = F_15 ;
V_7 -> V_5 . V_36 = - 1 ;
V_7 -> V_5 . V_20 = V_18 ;
V_7 -> V_5 . V_37 = true ;
return F_25 ( V_27 , & V_7 -> V_5 , V_7 ) ;
}
static inline bool F_9 ( struct V_1 * V_7 ,
struct V_8 * V_9 )
{
return false ;
}
static inline int F_22 ( struct V_1 * V_7 )
{
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_38 , int V_39 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long long V_40 ;
unsigned int V_41 ;
int V_42 ;
if ( V_39 != V_7 -> V_39 ) {
V_42 = F_27 ( V_43 * V_39 ,
V_44 * 1000 ) - 1 ;
if ( V_42 >= V_45 &&
V_42 <= V_46 ) {
F_28 ( V_7 -> V_22 , V_47 ,
V_48 , V_48 ) ;
F_16 ( V_7 -> V_22 , V_49 , V_42 ) ;
F_28 ( V_7 -> V_22 , V_47 ,
V_48 , 0x0 ) ;
F_29 ( 500 ) ;
V_7 -> V_39 = V_39 ;
} else {
F_30 ( V_3 -> V_27 ,
L_1 ) ;
return - V_25 ;
}
}
V_7 -> V_38 = V_38 ;
if ( V_38 < 1 ) {
if ( V_9 -> V_17 >= V_18 )
V_41 = V_50 ;
else
V_41 = F_18 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , V_23 ) ;
return 0 ;
}
if ( V_38 == V_39 ) {
if ( V_9 -> V_17 >= V_18 )
V_41 = V_51 ;
else
V_41 = F_17 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , 0x0 ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_50 ;
else
V_41 = F_18 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , 0x0 ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_52 ;
else
V_41 = F_14 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , V_23 ) ;
return 0 ;
}
V_40 = V_44 * ( unsigned long long ) V_38 ;
V_40 = F_31 ( V_40 , V_39 ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_51 ;
else
V_41 = F_17 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , ( int ) V_40 & 0xff ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_50 ;
else
V_41 = F_18 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , ( ( int ) V_40 >> 8 ) & 0xf ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_52 ;
else
V_41 = F_14 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_41 ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_53 ;
else
V_41 = F_33 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , 0 ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_52 ;
else
V_41 = F_14 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , 0 ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_50 ;
else
V_41 = F_18 ( V_9 -> V_17 ) ;
F_28 ( V_7 -> V_22 , V_41 , V_23 , 0x0 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_41 ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_50 ;
else
V_41 = F_18 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , V_23 ) ;
if ( V_9 -> V_17 >= V_18 )
V_41 = V_51 ;
else
V_41 = F_17 ( V_9 -> V_17 ) ;
F_16 ( V_7 -> V_22 , V_41 , 0x0 ) ;
}
static int F_35 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_9 ( V_7 , V_9 ) )
return - V_15 ;
if ( V_7 -> V_54 ++ == 0 )
return F_28 ( V_7 -> V_22 , V_47 ,
V_48 , 0x0 ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( -- V_7 -> V_54 == 0 )
F_28 ( V_7 -> V_22 , V_47 , V_48 ,
V_48 ) ;
}
static int F_37 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_1 * V_7 ;
int V_59 ;
int V_60 ;
V_7 = F_38 ( & V_56 -> V_27 , sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
return - V_62 ;
V_7 -> V_22 = F_39 ( V_56 , & V_63 ) ;
if ( F_40 ( V_7 -> V_22 ) ) {
V_59 = F_41 ( V_7 -> V_22 ) ;
F_30 ( & V_56 -> V_27 , L_2 ,
V_59 ) ;
return V_59 ;
}
V_7 -> V_38 = 0 ;
V_7 -> V_39 = V_64 ;
F_42 ( V_56 , V_7 ) ;
F_13 ( V_7 -> V_22 , V_65 , & V_60 ) ;
if ( F_43 ( & V_56 -> V_27 , L_3 ) )
V_60 |= V_66 ;
else
V_60 &= ~ V_66 ;
if ( F_43 ( & V_56 -> V_27 , L_4 ) )
V_60 &= ~ V_67 ;
else
V_60 |= V_67 ;
F_16 ( V_7 -> V_22 , V_65 , V_60 ) ;
F_16 ( V_7 -> V_22 , V_51 , 0 ) ;
F_16 ( V_7 -> V_22 , V_50 , 0 ) ;
V_7 -> V_3 . V_68 = & V_69 ;
V_7 -> V_3 . V_70 = V_18 + 1 ;
V_7 -> V_3 . V_27 = & V_56 -> V_27 ;
V_7 -> V_3 . V_36 = - 1 ;
V_59 = F_44 ( & V_7 -> V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_22 ( V_7 ) ;
if ( V_59 < 0 )
F_45 ( & V_7 -> V_3 ) ;
return V_59 ;
}
static int F_46 ( struct V_55 * V_56 )
{
struct V_1 * V_7 = F_47 ( V_56 ) ;
F_28 ( V_7 -> V_22 , V_47 , V_48 ,
V_48 ) ;
return F_45 ( & V_7 -> V_3 ) ;
}
