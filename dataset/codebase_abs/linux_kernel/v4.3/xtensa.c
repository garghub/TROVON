static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 -> V_6 ) ;
int V_7 = 0 ;
while ( V_5 -> V_8 -> V_9 [ V_7 ] . V_2 ) {
if ( V_7 ++ == V_3 ) {
V_2 -> V_10 = V_5 -> V_8 -> V_9 [ V_3 ] ;
return V_3 ;
}
}
return V_7 ;
}
static int
F_2 ( struct V_11 * V_12 , struct V_13 * V_14 ,
int V_15 , struct V_13 * * V_16 )
{
return F_3 ( V_12 -> V_6 -> V_17 . V_18 , 0x10000 , V_15 ,
true , V_14 , V_16 ) ;
}
static void
F_4 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_4 ( V_6 ) ;
struct V_20 * V_17 = & V_5 -> V_6 . V_17 ;
struct V_21 * V_18 = V_17 -> V_18 ;
const T_1 V_10 = V_5 -> V_22 ;
T_1 V_23 = F_5 ( V_18 , V_10 + 0xd04 ) ;
T_1 V_24 = F_5 ( V_18 , V_10 + 0xc20 ) ;
T_1 V_25 = F_5 ( V_18 , V_10 + 0xc28 ) ;
T_1 V_26 = F_5 ( V_18 , V_10 + 0xd0c ) ;
if ( V_24 & 0x10 )
F_6 ( V_17 , L_1 ) ;
F_7 ( V_18 , V_10 + 0xc20 , V_24 ) ;
V_24 = F_5 ( V_18 , V_10 + 0xc20 ) ;
if ( V_23 == 0x10001 && V_26 == 0x200 && V_25 && ! V_24 ) {
F_8 ( V_17 , L_2 ) ;
F_9 ( V_18 , V_5 -> V_22 + 0xd94 , 0 , V_5 -> V_8 -> V_27 ) ;
}
}
static int
F_10 ( struct V_19 * V_6 , bool V_28 )
{
struct V_4 * V_5 = V_4 ( V_6 ) ;
struct V_21 * V_18 = V_5 -> V_6 . V_17 . V_18 ;
const T_1 V_10 = V_5 -> V_22 ;
F_7 ( V_18 , V_10 + 0xd84 , 0 ) ;
F_7 ( V_18 , V_10 + 0xd94 , 0 ) ;
if ( ! V_28 )
F_11 ( & V_5 -> V_29 ) ;
return 0 ;
}
static int
F_12 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_4 ( V_6 ) ;
struct V_20 * V_17 = & V_5 -> V_6 . V_17 ;
struct V_21 * V_18 = V_17 -> V_18 ;
const T_1 V_10 = V_5 -> V_22 ;
const struct V_30 * V_31 ;
char V_32 [ 32 ] ;
int V_33 , V_34 ;
T_2 V_22 , V_35 ;
T_1 V_36 ;
if ( ! V_5 -> V_29 ) {
snprintf ( V_32 , sizeof( V_32 ) , L_3 ,
V_5 -> V_22 >> 12 ) ;
V_34 = F_13 ( & V_31 , V_32 , V_18 -> V_37 ) ;
if ( V_34 ) {
F_6 ( V_17 , L_4 , V_32 ) ;
return V_34 ;
}
if ( V_31 -> V_35 > 0x40000 ) {
F_6 ( V_17 , L_5 , V_32 ) ;
F_14 ( V_31 ) ;
return - V_38 ;
}
V_34 = F_15 ( V_18 , V_39 ,
0x40000 , 0x1000 , false ,
& V_5 -> V_29 ) ;
if ( V_34 ) {
F_14 ( V_31 ) ;
return V_34 ;
}
F_16 ( V_5 -> V_29 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_35 / 4 ; V_33 ++ )
F_17 ( V_5 -> V_29 , V_33 * 4 , * ( ( T_1 * ) V_31 -> V_40 + V_33 ) ) ;
F_18 ( V_5 -> V_29 ) ;
F_14 ( V_31 ) ;
}
V_22 = F_19 ( V_5 -> V_29 ) ;
V_35 = F_20 ( V_5 -> V_29 ) ;
F_7 ( V_18 , V_10 + 0xd10 , 0x1fffffff ) ;
F_7 ( V_18 , V_10 + 0xd08 , 0x0fffffff ) ;
F_7 ( V_18 , V_10 + 0xd28 , V_5 -> V_8 -> V_41 ) ;
F_7 ( V_18 , V_10 + 0xc20 , 0x3f ) ;
F_7 ( V_18 , V_10 + 0xd84 , 0x3f ) ;
F_7 ( V_18 , V_10 + 0xcc0 , V_22 >> 8 ) ;
F_7 ( V_18 , V_10 + 0xcc4 , 0x1c ) ;
F_7 ( V_18 , V_10 + 0xcc8 , V_35 >> 8 ) ;
V_36 = F_5 ( V_18 , 0x0 ) ;
F_7 ( V_18 , V_10 + 0xde0 , V_36 ) ;
F_7 ( V_18 , V_10 + 0xce8 , 0xf ) ;
F_7 ( V_18 , V_10 + 0xc20 , 0x3f ) ;
F_7 ( V_18 , V_10 + 0xd84 , 0x3f ) ;
return 0 ;
}
static void *
F_21 ( struct V_19 * V_6 )
{
return V_4 ( V_6 ) ;
}
int
F_22 ( const struct V_42 * V_8 ,
struct V_21 * V_18 , int V_3 , bool V_43 ,
T_1 V_22 , struct V_19 * * V_44 )
{
struct V_4 * V_5 ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_45 ) ) )
return - V_46 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_22 = V_22 ;
* V_44 = & V_5 -> V_6 ;
return F_24 ( & V_4 , V_18 , V_3 , V_8 -> V_47 ,
V_43 , & V_5 -> V_6 ) ;
}
