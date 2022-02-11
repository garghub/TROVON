static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_6 ) ;
T_1 V_8 [ 7 ] ;
int V_9 ;
if ( ! V_7 -> V_10 ) {
F_4 ( & V_6 -> V_2 , L_1 ) ;
return - V_11 ;
}
V_9 = F_5 ( V_6 , V_12 , 7 , V_8 ) ;
V_4 -> V_13 = F_6 ( V_8 [ 0 ] & V_14 ) ;
V_4 -> V_15 = F_6 ( V_8 [ 1 ] & V_16 ) ;
V_4 -> V_17 = F_6 ( V_8 [ 2 ] & V_18 ) ;
V_4 -> V_19 = F_6 ( V_8 [ 3 ] & V_20 ) ;
V_4 -> V_21 = F_6 ( V_8 [ 4 ] & V_22 ) ;
V_4 -> V_23 = F_6 ( V_8 [ 5 ] & V_24 ) - 1 ;
V_4 -> V_25 = F_6 ( V_8 [ 6 ] ) + 100 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_6 ) ;
T_1 V_8 [ 7 ] ;
int V_9 ;
if ( V_4 -> V_25 < 100 || V_4 -> V_25 >= 200 )
return - V_26 ;
V_8 [ 0 ] = F_8 ( V_4 -> V_13 ) ;
V_8 [ 1 ] = F_8 ( V_4 -> V_15 ) ;
V_8 [ 2 ] = F_8 ( V_4 -> V_17 ) ;
V_8 [ 3 ] = F_8 ( V_4 -> V_19 ) ;
V_8 [ 4 ] = F_8 ( V_4 -> V_21 ) ;
V_8 [ 5 ] = F_8 ( V_4 -> V_23 + 1 ) ;
V_8 [ 6 ] = V_4 -> V_25 - 100 ;
V_9 = F_9 ( V_6 , V_27 ,
V_28 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_10 ( V_6 , V_12 , 7 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_9 ( V_6 , V_27 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_7 -> V_10 = true ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_30 ;
V_30 = F_12 ( V_6 , V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_29 )
V_30 |= V_32 ;
else
V_30 &= ~ V_32 ;
return F_9 ( V_6 , V_31 , V_30 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_35 = & V_34 -> time ;
T_1 V_8 [ 4 ] ;
int V_9 ;
V_9 = F_5 ( V_6 , V_36 , 4 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_35 -> V_13 = - 1 ;
V_35 -> V_15 = ( V_8 [ 0 ] & V_37 ) ?
- 1 :
F_6 ( V_8 [ 0 ] & V_16 ) ;
V_35 -> V_17 = ( V_8 [ 1 ] & V_37 ) ?
- 1 :
F_6 ( V_8 [ 1 ] & V_18 ) ;
V_35 -> V_19 = ( V_8 [ 2 ] & V_37 ) ?
- 1 :
F_6 ( V_8 [ 2 ] & V_20 ) ;
V_35 -> V_21 = ( V_8 [ 3 ] & V_37 ) ?
- 1 :
F_6 ( V_8 [ 3 ] & V_22 ) ;
V_35 -> V_23 = - 1 ;
V_35 -> V_25 = - 1 ;
V_9 = F_12 ( V_6 , V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_32 )
V_34 -> V_29 = 1 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_35 = & V_34 -> time ;
T_1 V_8 [ 4 ] ;
int V_9 ;
if ( V_35 -> V_13 ) {
V_35 -> V_13 = 0 ;
V_35 -> V_15 ++ ;
if ( V_35 -> V_15 >= 60 ) {
V_35 -> V_15 = 0 ;
V_35 -> V_17 ++ ;
if ( V_35 -> V_17 >= 24 ) {
V_35 -> V_17 = 0 ;
V_35 -> V_19 ++ ;
if ( V_35 -> V_19 > 31 )
V_35 -> V_19 = 0 ;
}
}
}
V_9 = F_12 ( V_6 , V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 &= ~ V_32 ;
V_9 = F_9 ( V_6 , V_31 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 [ 0 ] = ( V_35 -> V_15 < 60 && V_35 -> V_15 >= 0 ) ?
F_8 ( V_35 -> V_15 ) : V_37 ;
V_8 [ 1 ] = ( V_35 -> V_17 < 24 && V_35 -> V_17 >= 0 ) ?
F_8 ( V_35 -> V_17 ) : V_37 ;
V_8 [ 2 ] = ( V_35 -> V_19 <= 31 && V_35 -> V_19 >= 1 ) ?
F_8 ( V_35 -> V_19 ) : V_37 ;
V_8 [ 3 ] = ( V_35 -> V_21 < 7 && V_35 -> V_21 >= 0 ) ?
F_8 ( V_35 -> V_21 ) : V_37 ;
V_9 = F_10 ( V_6 , V_36 , 4 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_11 ( V_2 , V_34 -> V_29 ) ;
}
static unsigned long F_15 ( struct V_38 * V_39 ,
unsigned long V_40 )
{
struct V_7 * V_7 = F_16 ( V_39 ) ;
struct V_5 * V_6 = V_7 -> V_6 ;
int V_9 = F_12 ( V_6 , V_41 ) ;
if ( V_9 < 0 || V_9 & V_42 )
return 0 ;
V_9 &= V_43 ;
return V_44 [ V_9 ] ;
}
static long F_17 ( struct V_38 * V_39 , unsigned long V_45 ,
unsigned long * V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_44 ) ; V_47 ++ )
if ( V_44 [ V_47 ] <= V_45 )
return V_44 [ V_47 ] ;
return 0 ;
}
static int F_19 ( struct V_38 * V_39 , unsigned long V_45 ,
unsigned long V_40 )
{
struct V_7 * V_7 = F_16 ( V_39 ) ;
struct V_5 * V_6 = V_7 -> V_6 ;
int V_9 = F_12 ( V_6 , V_41 ) ;
int V_47 ;
if ( V_9 < 0 )
return V_9 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_44 ) ; V_47 ++ )
if ( V_44 [ V_47 ] == V_45 ) {
V_9 &= ~ V_43 ;
V_9 |= V_47 ;
return F_9 ( V_6 ,
V_41 , V_9 ) ;
}
return - V_26 ;
}
static int F_20 ( struct V_38 * V_39 , bool V_48 )
{
struct V_7 * V_7 = F_16 ( V_39 ) ;
struct V_5 * V_6 = V_7 -> V_6 ;
int V_9 = F_12 ( V_6 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_48 )
V_9 &= ~ V_42 ;
else
V_9 |= V_42 ;
return F_9 ( V_6 , V_41 , V_9 ) ;
}
static int F_21 ( struct V_38 * V_39 )
{
return F_20 ( V_39 , 1 ) ;
}
static void F_22 ( struct V_38 * V_39 )
{
F_20 ( V_39 , 0 ) ;
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_7 * V_7 = F_16 ( V_39 ) ;
struct V_5 * V_6 = V_7 -> V_6 ;
int V_9 = F_12 ( V_6 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
return ! ( V_9 & V_42 ) ;
}
static struct V_49 * F_24 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_50 * V_51 = V_6 -> V_2 . V_52 ;
struct V_49 * V_49 ;
struct V_53 V_54 ;
int V_9 ;
V_9 = F_9 ( V_6 , V_41 ,
V_42 ) ;
if ( V_9 < 0 )
return F_25 ( V_9 ) ;
V_54 . V_55 = L_2 ;
V_54 . V_56 = & V_57 ;
V_54 . V_58 = V_59 ;
V_54 . V_60 = NULL ;
V_54 . V_61 = 0 ;
V_7 -> V_62 . V_54 = & V_54 ;
V_49 = F_26 ( & V_6 -> V_2 , & V_7 -> V_62 ) ;
if ( ! F_27 ( V_49 ) )
F_28 ( V_51 , V_63 , V_49 ) ;
return V_49 ;
}
static T_2 F_29 ( int V_64 , void * V_65 )
{
struct V_7 * V_7 = (struct V_7 * ) V_65 ;
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_66 * V_67 = & V_7 -> V_68 -> V_69 ;
int V_30 , V_9 ;
F_30 ( V_67 ) ;
V_30 = F_12 ( V_6 , V_31 ) ;
if ( V_30 < 0 ) {
F_31 ( & V_6 -> V_2 , L_3 ,
V_70 , V_30 ) ;
goto V_71;
}
V_30 &= ~ V_72 ;
V_9 = F_9 ( V_6 , V_31 , V_30 ) ;
if ( V_9 < 0 ) {
F_31 ( & V_6 -> V_2 , L_4 ,
V_70 , V_9 ) ;
}
V_71:
F_32 ( V_67 ) ;
return V_73 ;
}
static int F_33 ( struct V_5 * V_6 )
{
int V_9 ;
V_9 = F_9 ( V_6 , V_27 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_12 ( V_6 , V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 &= ~ V_32 ;
V_9 &= ~ V_74 ;
if ( V_9 & V_72 )
V_9 &= ~ V_72 ;
if ( V_9 & V_75 )
V_9 &= ~ V_75 ;
V_9 &= ~ V_76 ;
return F_9 ( V_6 , V_31 , V_9 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
if ( F_35 ( V_2 ) ) {
V_9 = F_36 ( V_6 -> V_64 ) ;
if ( V_9 ) {
F_31 ( V_2 , L_5 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_35 ( V_2 ) )
F_38 ( V_6 -> V_64 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 ,
const struct V_77 * V_78 )
{
struct V_7 * V_7 ;
int V_9 ;
V_7 = F_40 ( & V_6 -> V_2 , sizeof( * V_7 ) , V_79 ) ;
if ( ! V_7 )
return - V_80 ;
V_7 -> V_6 = V_6 ;
F_41 ( V_6 , V_7 ) ;
F_42 ( & V_6 -> V_2 , true ) ;
V_9 = F_33 ( V_6 ) ;
if ( V_9 ) {
F_31 ( & V_6 -> V_2 , L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_43 ( & V_6 -> V_2 , V_6 -> V_64 ,
NULL , F_29 ,
V_81 | V_82 ,
V_6 -> V_55 , V_7 ) ;
if ( V_9 < 0 ) {
F_31 ( & V_6 -> V_2 , L_7 ,
V_6 -> V_64 , V_9 ) ;
return V_9 ;
}
V_9 = F_12 ( V_6 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_7 -> V_10 = ! ( V_9 & V_83 ) ;
F_44 ( & V_6 -> V_2 , L_8 ,
V_7 -> V_10 ? L_9 : L_10 ) ;
V_7 -> V_68 = F_45 ( & V_6 -> V_2 , V_6 -> V_55 ,
& V_84 , V_85 ) ;
if ( F_27 ( V_7 -> V_68 ) )
return F_46 ( V_7 -> V_68 ) ;
#ifdef F_47
F_24 ( V_7 ) ;
#endif
return 0 ;
}
