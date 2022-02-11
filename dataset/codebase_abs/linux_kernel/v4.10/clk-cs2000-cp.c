static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_2 V_6 ;
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 &= ~ V_4 ;
V_6 |= ( V_5 & V_4 ) ;
return F_3 ( V_2 , V_3 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , bool V_7 )
{
int V_8 ;
V_8 = F_1 ( V_2 , V_9 , V_10 ,
V_7 ? V_10 : 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_11 , V_12 ,
V_7 ? V_12 : 0 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_3 V_13 )
{
T_3 V_5 ;
if ( V_13 >= 32000000 && V_13 < 56000000 )
V_5 = 0x0 ;
else if ( V_13 >= 16000000 && V_13 < 28000000 )
V_5 = 0x1 ;
else if ( V_13 >= 8000000 && V_13 < 14000000 )
V_5 = 0x2 ;
else
return - V_14 ;
return F_1 ( V_2 , V_15 , 0x3 << 3 , V_5 << 3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_7 ( V_2 ) ;
T_2 V_5 ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
V_5 = F_2 ( V_2 , V_19 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( V_5 & V_20 ) )
return 0 ;
F_8 ( 1 ) ;
}
F_9 ( V_17 , L_1 ) ;
return - V_21 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_7 )
{
return F_3 ( V_2 , V_19 , V_7 ? 0 : 0x3 ) ;
}
static T_3 F_11 ( T_3 V_13 , T_3 V_22 )
{
T_4 V_23 ;
V_23 = ( T_4 ) V_22 << 20 ;
F_12 ( V_23 , V_13 ) ;
return V_23 ;
}
static unsigned long F_13 ( T_3 V_23 , T_3 V_13 )
{
T_4 V_22 ;
V_22 = ( T_4 ) V_23 * V_13 ;
return V_22 >> 20 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_24 , T_3 V_13 , T_3 V_22 )
{
T_3 V_5 ;
unsigned int V_18 ;
int V_8 ;
if ( F_15 ( V_24 ) )
return - V_14 ;
V_5 = F_11 ( V_13 , V_22 ) ;
for ( V_18 = 0 ; V_18 < V_25 ; V_18 ++ ) {
V_8 = F_3 ( V_2 ,
F_16 ( V_24 , V_18 ) ,
F_17 ( V_5 , V_18 ) ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static T_3 F_18 ( struct V_1 * V_2 , int V_24 )
{
T_2 V_26 ;
T_3 V_5 ;
unsigned int V_18 ;
V_5 = 0 ;
for ( V_18 = 0 ; V_18 < V_25 ; V_18 ++ ) {
V_26 = F_2 ( V_2 , F_16 ( V_24 , V_18 ) ) ;
if ( V_26 < 0 )
return 0 ;
V_5 |= F_19 ( V_26 , V_18 ) ;
}
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 , int V_24 )
{
int V_8 ;
if ( F_15 ( V_24 ) )
return - V_14 ;
V_8 = F_1 ( V_2 , V_9 , V_27 , F_21 ( V_24 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_2 , V_28 , 0x0 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static unsigned long F_22 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
struct V_1 * V_2 = F_23 ( V_30 ) ;
int V_24 = 0 ;
T_3 V_23 ;
V_23 = F_18 ( V_2 , V_24 ) ;
return F_13 ( V_23 , V_31 ) ;
}
static long F_24 ( struct V_29 * V_30 , unsigned long V_32 ,
unsigned long * V_31 )
{
T_3 V_23 ;
V_23 = F_11 ( * V_31 , V_32 ) ;
return F_13 ( V_23 , * V_31 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_24 ,
unsigned long V_32 , unsigned long V_31 )
{
int V_8 ;
V_8 = F_5 ( V_2 , V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_14 ( V_2 , V_24 , V_31 , V_32 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_20 ( V_2 , V_24 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_26 ( struct V_29 * V_30 ,
unsigned long V_32 , unsigned long V_31 )
{
struct V_1 * V_2 = F_23 ( V_30 ) ;
int V_24 = 0 ;
return F_25 ( V_2 , V_24 , V_32 , V_31 ) ;
}
static int F_27 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_30 ) ;
int V_8 ;
V_8 = F_4 ( V_2 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_2 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_8 ;
}
static void F_28 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_30 ) ;
F_4 ( V_2 , false ) ;
F_10 ( V_2 , false ) ;
}
static T_1 F_29 ( struct V_29 * V_30 )
{
return V_33 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_31 ( V_2 ) ;
struct V_16 * V_17 = & V_35 -> V_17 ;
struct V_36 * V_37 , * V_38 ;
V_37 = F_32 ( V_17 , L_2 ) ;
if ( F_33 ( V_37 ) )
return - V_39 ;
V_38 = F_32 ( V_17 , L_3 ) ;
if ( F_33 ( V_38 ) )
return - V_39 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_38 = V_38 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_7 ( V_2 ) ;
struct V_40 * V_41 = V_17 -> V_42 ;
struct V_43 V_44 ;
const char * V_45 = V_41 -> V_45 ;
static const char * V_46 [ V_47 ] ;
int V_24 = 0 ;
int V_32 ;
int V_8 ;
F_35 ( V_41 , L_4 , & V_45 ) ;
V_32 = F_36 ( V_2 -> V_38 ) ;
V_8 = F_25 ( V_2 , V_24 , V_32 , V_32 ) ;
if ( V_8 < 0 )
return V_8 ;
V_46 [ V_48 ] = F_37 ( V_2 -> V_37 ) ;
V_46 [ V_33 ] = F_37 ( V_2 -> V_38 ) ;
V_44 . V_45 = V_45 ;
V_44 . V_49 = & V_50 ;
V_44 . V_51 = V_52 ;
V_44 . V_46 = V_46 ;
V_44 . V_53 = F_38 ( V_46 ) ;
V_2 -> V_30 . V_44 = & V_44 ;
V_8 = F_39 ( V_17 , & V_2 -> V_30 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_40 ( V_41 , V_54 , & V_2 -> V_30 ) ;
if ( V_8 < 0 ) {
F_41 ( & V_2 -> V_30 ) ;
return V_8 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_31 ( V_2 ) ;
struct V_16 * V_17 = & V_35 -> V_17 ;
T_2 V_5 ;
const char * V_55 ;
V_5 = F_2 ( V_2 , V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 >> 3 )
return - V_57 ;
switch ( V_5 & V_58 ) {
case V_59 :
V_55 = L_5 ;
break;
case V_60 :
V_55 = L_6 ;
break;
default:
return - V_57 ;
}
F_43 ( V_17 , L_7 , V_55 ) ;
return 0 ;
}
static int F_44 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_45 ( V_35 ) ;
struct V_16 * V_17 = & V_35 -> V_17 ;
struct V_40 * V_41 = V_17 -> V_42 ;
F_46 ( V_41 ) ;
F_41 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_47 ( struct V_34 * V_35 ,
const struct V_61 * V_62 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 = & V_35 -> V_17 ;
int V_8 ;
V_2 = F_48 ( V_17 , sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_35 = V_35 ;
F_49 ( V_35 , V_2 ) ;
V_8 = F_30 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_34 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_42 ( V_2 ) ;
if ( V_8 < 0 )
goto V_65;
return 0 ;
V_65:
F_44 ( V_35 ) ;
return V_8 ;
}
