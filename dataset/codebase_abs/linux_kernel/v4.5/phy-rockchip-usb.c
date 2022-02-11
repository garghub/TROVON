static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 , V_2 -> V_6 ,
V_7 | ( V_3 ? V_8 : V_9 ) ) ;
}
static unsigned long F_3 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
return 480000000 ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 ,
struct V_1 ,
V_13 ) ;
F_1 ( V_2 , 1 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 ,
struct V_1 ,
V_13 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 ,
struct V_1 ,
V_13 ) ;
int V_14 ;
T_1 V_15 ;
V_14 = F_8 ( V_2 -> V_4 -> V_5 , V_2 -> V_6 , & V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
return ( V_15 & V_8 ) ? 0 : 1 ;
}
static int F_9 ( struct V_2 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_11 ( V_2 -> V_17 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
return F_13 ( V_2 -> V_17 ) ;
}
static void F_14 ( void * V_18 )
{
struct V_1 * V_19 = V_18 ;
F_15 ( V_19 -> V_20 ) ;
F_16 ( V_19 -> V_17 ) ;
if ( V_19 -> V_21 )
F_17 ( V_19 -> V_21 ) ;
}
static int F_18 ( struct V_22 * V_4 ,
struct V_23 * V_24 )
{
struct V_1 * V_19 ;
unsigned int V_6 ;
const char * V_25 ;
struct V_26 V_27 ;
int V_28 , V_29 ;
V_19 = F_19 ( V_4 -> V_30 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 )
return - V_32 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_20 = V_24 ;
if ( F_20 ( V_24 , L_1 , & V_6 ) ) {
F_21 ( V_4 -> V_30 , L_2 ,
V_24 -> V_33 ) ;
return - V_34 ;
}
V_19 -> V_6 = V_6 ;
V_19 -> V_21 = F_22 ( V_24 , L_3 ) ;
if ( F_23 ( V_19 -> V_21 ) )
V_19 -> V_21 = NULL ;
V_29 = 0 ;
V_27 . V_33 = NULL ;
while ( V_4 -> V_35 -> V_36 [ V_29 ] . V_37 ) {
if ( V_4 -> V_35 -> V_36 [ V_29 ] . V_37 == V_6 ) {
V_27 . V_33 = V_4 -> V_35 -> V_36 [ V_29 ] . V_38 ;
break;
}
V_29 ++ ;
}
if ( ! V_27 . V_33 ) {
F_21 ( V_4 -> V_30 , L_4 ) ;
return - V_34 ;
}
if ( V_19 -> V_21 ) {
V_25 = F_24 ( V_19 -> V_21 ) ;
V_27 . V_39 = 0 ;
V_27 . V_40 = & V_25 ;
V_27 . V_41 = 1 ;
} else {
V_27 . V_39 = V_42 ;
V_27 . V_40 = NULL ;
V_27 . V_41 = 0 ;
}
V_27 . V_43 = & V_44 ;
V_19 -> V_13 . V_27 = & V_27 ;
V_19 -> V_17 = F_25 ( V_4 -> V_30 , & V_19 -> V_13 ) ;
if ( F_23 ( V_19 -> V_17 ) ) {
V_28 = F_26 ( V_19 -> V_17 ) ;
goto V_45;
}
V_28 = F_27 ( V_24 , V_46 ,
V_19 -> V_17 ) ;
if ( V_28 < 0 )
goto V_47;
V_28 = F_28 ( V_4 -> V_30 , F_14 , V_19 ) ;
if ( V_28 )
goto V_48;
V_19 -> V_2 = F_29 ( V_4 -> V_30 , V_24 , & V_43 ) ;
if ( F_23 ( V_19 -> V_2 ) ) {
F_21 ( V_4 -> V_30 , L_5 ) ;
return F_26 ( V_19 -> V_2 ) ;
}
F_30 ( V_19 -> V_2 , V_19 ) ;
return F_1 ( V_19 , 1 ) ;
V_48:
F_15 ( V_24 ) ;
V_47:
F_16 ( V_19 -> V_17 ) ;
V_45:
if ( V_19 -> V_21 )
F_17 ( V_19 -> V_21 ) ;
return V_28 ;
}
static int F_31 ( struct V_49 * V_50 )
{
struct V_51 * V_30 = & V_50 -> V_30 ;
struct V_22 * V_52 ;
struct V_53 * V_53 ;
const struct V_54 * V_55 ;
struct V_23 * V_24 ;
int V_28 ;
V_52 = F_19 ( V_30 , sizeof( * V_52 ) , V_31 ) ;
if ( ! V_52 )
return - V_32 ;
V_55 = F_32 ( V_30 -> V_56 -> V_57 , V_30 ) ;
if ( ! V_55 || ! V_55 -> V_18 ) {
F_21 ( V_30 , L_6 ) ;
return - V_34 ;
}
V_52 -> V_35 = V_55 -> V_18 ;
V_52 -> V_30 = V_30 ;
V_52 -> V_5 = F_33 ( V_30 -> V_58 ,
L_7 ) ;
if ( F_23 ( V_52 -> V_5 ) ) {
F_21 ( & V_50 -> V_30 , L_8 ) ;
return F_26 ( V_52 -> V_5 ) ;
}
F_34 (dev->of_node, child) {
V_28 = F_18 ( V_52 , V_24 ) ;
if ( V_28 ) {
F_35 ( V_24 ) ;
return V_28 ;
}
}
V_53 = F_36 ( V_30 , V_59 ) ;
return F_37 ( V_53 ) ;
}
