static int F_1 ( unsigned int * V_1 , unsigned int V_2 )
{
return * V_1 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned int V_10 ;
V_10 = 1 ;
if ( V_10 )
return 0 ;
return - V_11 ;
}
static int F_3 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_12 )
{
const struct V_13 * V_14 = F_4 ( V_4 ) ;
int V_15 ;
unsigned int V_16 ;
int V_17 ;
for ( V_15 = 0 ; V_15 < V_8 -> V_15 ; V_15 ++ ) {
V_17 = F_5 ( V_4 , V_6 , V_8 , F_2 , 0 ) ;
if ( V_17 )
return V_17 ;
V_16 = 0 ;
V_16 ^= 1 << ( V_14 -> V_18 - 1 ) ;
V_12 [ V_15 ] = V_16 ;
}
return V_15 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
unsigned int V_22 ;
V_21 |= F_7 ( & V_20 -> V_23 , V_24 ) ;
V_21 |= F_7 ( & V_20 -> V_25 ,
V_26 | V_27 ) ;
V_21 |= F_7 ( & V_20 -> V_28 , V_26 | V_27 ) ;
V_21 |= F_7 ( & V_20 -> V_29 , V_30 ) ;
V_21 |= F_7 ( & V_20 -> V_31 , V_30 | V_32 ) ;
if ( V_21 )
return 1 ;
V_21 |= F_8 ( V_20 -> V_25 ) ;
V_21 |= F_8 ( V_20 -> V_28 ) ;
V_21 |= F_8 ( V_20 -> V_31 ) ;
if ( V_21 )
return 2 ;
V_21 |= F_9 ( & V_20 -> V_33 , 0 ) ;
#define F_10 10000
#define F_11 1000000000
if ( V_20 -> V_25 == V_26 ) {
V_21 |= F_12 ( & V_20 -> V_34 ,
F_10 ) ;
V_21 |= F_13 ( & V_20 -> V_34 ,
F_11 ) ;
} else {
V_21 |= F_13 ( & V_20 -> V_34 , 9 ) ;
}
if ( V_20 -> V_28 == V_26 ) {
V_21 |= F_12 ( & V_20 -> V_35 , F_10 ) ;
V_21 |= F_13 ( & V_20 -> V_35 , F_11 ) ;
} else {
V_21 |= F_13 ( & V_20 -> V_34 , 9 ) ;
}
V_21 |= F_9 ( & V_20 -> V_36 , V_20 -> V_37 ) ;
if ( V_20 -> V_31 == V_30 )
V_21 |= F_13 ( & V_20 -> V_38 , 0x00ffffff ) ;
else
V_21 |= F_9 ( & V_20 -> V_38 , 0 ) ;
if ( V_21 )
return 3 ;
if ( V_20 -> V_25 == V_26 ) {
V_22 = V_20 -> V_34 ;
F_1 ( & V_22 , V_20 -> V_2 ) ;
V_21 |= F_9 ( & V_20 -> V_34 , V_22 ) ;
}
if ( V_20 -> V_28 == V_26 ) {
V_22 = V_20 -> V_35 ;
F_1 ( & V_22 , V_20 -> V_2 ) ;
V_21 |= F_9 ( & V_20 -> V_35 , V_22 ) ;
if ( V_20 -> V_25 == V_26 ) {
V_22 = V_20 -> V_35 * V_20 -> V_36 ;
V_21 |= F_12 ( & V_20 -> V_34 ,
V_22 ) ;
}
}
if ( V_21 )
return 4 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_12 )
{
struct V_39 * V_40 = V_4 -> V_41 ;
int V_42 ;
int V_43 = F_15 ( V_8 -> V_44 ) ;
for ( V_42 = 0 ; V_42 < V_8 -> V_15 ; V_42 ++ ) {
V_40 -> V_45 [ V_43 ] = V_12 [ V_42 ] ;
}
return V_42 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_12 )
{
struct V_39 * V_40 = V_4 -> V_41 ;
int V_42 ;
int V_43 = F_15 ( V_8 -> V_44 ) ;
for ( V_42 = 0 ; V_42 < V_8 -> V_15 ; V_42 ++ )
V_12 [ V_42 ] = V_40 -> V_45 [ V_43 ] ;
return V_42 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_12 )
{
if ( F_18 ( V_6 , V_12 ) ) {
}
return V_8 -> V_15 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_12 )
{
int V_17 ;
V_17 = F_20 ( V_4 , V_6 , V_8 , V_12 , 0 ) ;
if ( V_17 )
return V_17 ;
return V_8 -> V_15 ;
}
static int F_21 ( struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_4 ( V_4 ) ;
struct V_5 * V_6 ;
int V_17 ;
V_17 = F_22 ( V_4 , 3 ) ;
if ( V_17 )
return V_17 ;
V_6 = & V_4 -> V_46 [ 0 ] ;
V_6 -> type = V_47 ;
V_6 -> V_48 = V_49 | V_50 | V_51 ;
V_6 -> V_52 = V_14 -> V_53 ;
V_6 -> V_54 = ( 1 << V_14 -> V_18 ) - 1 ;
V_6 -> V_55 = & V_56 ;
V_6 -> V_57 = 16 ;
V_6 -> V_58 = F_3 ;
V_6 -> V_59 = F_6 ;
V_6 = & V_4 -> V_46 [ 1 ] ;
V_6 -> type = V_60 ;
V_6 -> V_48 = V_61 ;
V_6 -> V_52 = 1 ;
V_6 -> V_54 = 0xffff ;
V_6 -> V_55 = & V_62 ;
V_6 -> V_63 = F_14 ;
V_6 -> V_58 = F_16 ;
V_6 = & V_4 -> V_46 [ 2 ] ;
if ( V_14 -> V_64 ) {
V_6 -> type = V_65 ;
V_6 -> V_48 = V_49 | V_61 ;
V_6 -> V_52 = 16 ;
V_6 -> V_54 = 1 ;
V_6 -> V_55 = & V_66 ;
V_6 -> V_67 = F_17 ;
V_6 -> V_68 = F_19 ;
} else {
V_6 -> type = V_69 ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , struct V_70 * V_71 )
{
const struct V_13 * V_14 ;
struct V_39 * V_40 ;
V_14 = F_4 ( V_4 ) ;
V_40 = F_24 ( V_4 , sizeof( * V_40 ) ) ;
if ( ! V_40 )
return - V_72 ;
return F_21 ( V_4 ) ;
}
static int F_25 ( struct V_3 * V_4 ,
unsigned long V_9 )
{
struct V_73 * V_74 = F_26 ( V_4 ) ;
const struct V_13 * V_14 = NULL ;
struct V_39 * V_40 ;
int V_17 ;
if ( ! F_27 ( V_75 ) )
return - V_76 ;
if ( V_9 < F_28 ( V_77 ) )
V_14 = & V_77 [ V_9 ] ;
if ( ! V_14 )
return - V_78 ;
V_4 -> V_79 = V_14 ;
V_4 -> V_80 = V_14 -> V_81 ;
V_40 = F_24 ( V_4 , sizeof( * V_40 ) ) ;
if ( ! V_40 )
return - V_72 ;
V_17 = F_29 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_82 = F_30 ( V_74 , 0 ) ;
return F_21 ( V_4 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_4 ( V_4 ) ;
struct V_39 * V_40 = V_4 -> V_41 ;
if ( ! V_14 || ! V_40 )
return;
if ( F_27 ( V_75 ) ) {
F_32 ( V_4 ) ;
} else {
F_33 ( V_4 ) ;
}
}
static int F_34 ( struct V_73 * V_4 ,
const struct V_83 * V_84 )
{
return F_35 ( V_4 , & V_85 , V_84 -> V_86 ) ;
}
