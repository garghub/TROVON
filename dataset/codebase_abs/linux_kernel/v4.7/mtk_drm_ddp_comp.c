static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
F_2 ( V_3 , V_2 -> V_6 + V_7 ) ;
F_2 ( V_4 , V_2 -> V_6 + V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_9 | V_10 ,
V_2 -> V_6 + V_11 ) ;
F_2 ( 0x1 , V_2 -> V_6 + V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
F_2 ( V_3 << 16 | V_4 , V_2 -> V_6 + V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_14 , V_2 -> V_6 + V_15 ) ;
F_2 ( 1 , V_2 -> V_6 + V_16 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_17 , V_2 -> V_6 + V_18 ) ;
}
int F_7 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
int V_23 = F_8 ( V_20 , V_24 [ V_22 ] ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_9 ( V_26 ) ; V_25 ++ ) {
if ( V_22 == V_26 [ V_25 ] . type &&
( V_23 < 0 || V_23 == V_26 [ V_25 ] . V_27 ) )
return V_25 ;
}
return - V_28 ;
}
int F_10 ( struct V_29 * V_30 , struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_31 V_32 ,
const struct V_33 * V_34 )
{
enum V_21 type ;
struct V_19 * V_35 ;
struct V_36 * V_37 ;
if ( V_32 < 0 || V_32 >= V_38 )
return - V_28 ;
V_2 -> V_23 = V_32 ;
V_2 -> V_34 = V_34 ? : V_26 [ V_32 ] . V_34 ;
if ( V_32 == V_39 ||
V_32 == V_40 ||
V_32 == V_41 ) {
V_2 -> V_6 = NULL ;
V_2 -> V_42 = NULL ;
V_2 -> V_43 = 0 ;
return 0 ;
}
V_2 -> V_6 = F_11 ( V_20 , 0 ) ;
V_2 -> V_43 = F_12 ( V_20 , 0 ) ;
V_2 -> V_42 = F_13 ( V_20 , 0 ) ;
if ( F_14 ( V_2 -> V_42 ) )
V_2 -> V_42 = NULL ;
type = V_26 [ V_32 ] . type ;
V_2 -> V_44 = NULL ;
if ( type != V_45 &&
type != V_46 &&
type != V_47 )
return 0 ;
V_35 = F_15 ( V_20 , L_1 , 0 ) ;
if ( ! V_35 ) {
F_16 ( V_30 ,
L_2 ,
V_20 -> V_48 ) ;
return - V_28 ;
}
V_37 = F_17 ( V_35 ) ;
if ( ! V_37 ) {
F_18 ( V_30 , L_3 ,
V_35 -> V_48 ) ;
F_19 ( V_35 ) ;
return - V_49 ;
}
F_19 ( V_35 ) ;
V_2 -> V_44 = & V_37 -> V_30 ;
return 0 ;
}
int F_20 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_52 * V_53 = V_51 -> V_54 ;
if ( V_53 -> V_55 [ V_2 -> V_23 ] )
return - V_56 ;
V_53 -> V_55 [ V_2 -> V_23 ] = V_2 ;
return 0 ;
}
void F_21 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_52 * V_53 = V_51 -> V_54 ;
V_53 -> V_55 [ V_2 -> V_23 ] = NULL ;
}
