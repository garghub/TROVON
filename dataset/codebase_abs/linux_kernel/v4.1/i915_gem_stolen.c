static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
T_1 V_8 ;
V_8 = 0 ;
if ( F_2 ( V_2 ) -> V_9 >= 3 ) {
F_3 ( V_2 -> V_10 , 0x5c , & V_8 ) ;
V_8 &= ~ ( ( 1 << 20 ) - 1 ) ;
} else {
#if 0
base = max_low_pfn_mapped << PAGE_SHIFT;
#endif
}
if ( V_8 == 0 )
return 0 ;
if ( F_2 ( V_2 ) -> V_9 <= 4 && ! F_4 ( V_2 ) && ! F_5 ( V_2 ) ) {
struct {
T_1 V_11 , V_12 ;
} V_13 [ 2 ] = {
{ . V_11 = V_8 , . V_12 = V_8 + V_4 -> V_14 . V_15 , } ,
{ . V_11 = V_8 , . V_12 = V_8 + V_4 -> V_14 . V_15 , } ,
} ;
T_2 V_16 , V_17 ;
V_16 = F_6 ( V_18 ) ;
if ( F_7 ( V_2 ) )
V_16 = ( V_16 & V_19 ) |
( V_16 & V_20 ) << 28 ;
else
V_16 &= V_19 ;
V_17 = V_16 + F_8 ( V_4 -> V_14 ) * 4 ;
if ( V_16 >= V_13 [ 0 ] . V_11 && V_16 < V_13 [ 0 ] . V_12 )
V_13 [ 0 ] . V_12 = V_16 ;
if ( V_17 > V_13 [ 1 ] . V_11 && V_17 <= V_13 [ 1 ] . V_12 )
V_13 [ 1 ] . V_11 = V_17 ;
if ( V_13 [ 0 ] . V_12 - V_13 [ 0 ] . V_11 >
V_13 [ 1 ] . V_12 - V_13 [ 1 ] . V_11 ) {
V_8 = V_13 [ 0 ] . V_11 ;
V_4 -> V_14 . V_15 = V_13 [ 0 ] . V_12 - V_13 [ 0 ] . V_11 ;
} else {
V_8 = V_13 [ 1 ] . V_11 ;
V_4 -> V_14 . V_15 = V_13 [ 1 ] . V_12 - V_13 [ 1 ] . V_11 ;
}
if ( V_13 [ 0 ] . V_11 != V_13 [ 1 ] . V_11 ||
V_13 [ 0 ] . V_12 != V_13 [ 1 ] . V_12 ) {
F_9 ( L_1 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_17 - 1 ) ;
F_9 ( L_2 ,
V_8 , V_8 + ( T_1 ) V_4 -> V_14 . V_15 - 1 ) ;
}
}
V_7 = F_10 ( V_2 -> V_2 , V_8 , V_4 -> V_14 . V_15 ,
L_3 ) ;
if ( V_7 == NULL ) {
V_7 = F_10 ( V_2 -> V_2 , V_8 + 1 ,
V_4 -> V_14 . V_15 - 1 ,
L_3 ) ;
if ( V_7 == NULL && ! F_11 ( V_2 ) ) {
F_12 ( L_4 ,
V_8 , V_8 + ( V_21 ) V_4 -> V_14 . V_15 ) ;
V_8 = 0 ;
}
}
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
int V_24 ,
int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_26 = 1 ;
int V_27 ;
V_27 = F_14 ( & V_4 -> V_28 . V_13 , V_23 ,
V_24 <<= 1 , 4096 , V_29 ) ;
if ( V_27 == 0 )
return V_26 ;
V_30:
if ( V_26 > 4 ||
( V_25 == 2 && V_26 == 2 ) )
return 0 ;
V_27 = F_14 ( & V_4 -> V_28 . V_13 , V_23 ,
V_24 >>= 1 , 4096 ,
V_29 ) ;
if ( V_27 && F_2 ( V_2 ) -> V_9 <= 4 ) {
return 0 ;
} else if ( V_27 ) {
V_26 <<= 1 ;
goto V_30;
} else {
return V_26 ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_24 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_31 ( V_32 ) ;
int V_27 ;
V_27 = F_13 ( V_2 , & V_4 -> V_33 . V_34 ,
V_24 , V_25 ) ;
if ( ! V_27 )
goto V_35;
else if ( V_27 > 1 ) {
F_16 ( L_5 ) ;
}
V_4 -> V_33 . V_36 = V_27 ;
if ( F_17 ( V_2 ) )
F_18 ( V_37 , V_4 -> V_33 . V_34 . V_11 ) ;
else if ( F_19 ( V_2 ) ) {
F_18 ( V_38 , V_4 -> V_33 . V_34 . V_11 ) ;
} else {
V_32 = F_20 ( sizeof( * V_32 ) , V_39 ) ;
if ( ! V_32 )
goto V_40;
V_27 = F_14 ( & V_4 -> V_28 . V_13 , V_32 ,
4096 , 4096 , V_29 ) ;
if ( V_27 )
goto V_40;
V_4 -> V_33 . V_32 = V_32 ;
F_18 ( V_41 ,
V_4 -> V_28 . V_42 + V_4 -> V_33 . V_34 . V_11 ) ;
F_18 ( V_43 ,
V_4 -> V_28 . V_42 + V_32 -> V_11 ) ;
}
V_4 -> V_33 . V_44 = V_24 ;
F_9 ( L_6 ,
V_24 ) ;
return 0 ;
V_40:
F_21 ( V_32 ) ;
F_22 ( & V_4 -> V_33 . V_34 ) ;
V_35:
F_23 ( L_7 , V_24 ) ;
return - V_45 ;
}
int F_24 ( struct V_1 * V_2 , int V_24 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_25 ( & V_4 -> V_28 . V_13 ) )
return - V_46 ;
if ( V_24 <= V_4 -> V_33 . V_44 )
return 0 ;
F_26 ( V_2 ) ;
return F_15 ( V_2 , V_24 , V_25 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_33 . V_44 == 0 )
return;
F_22 ( & V_4 -> V_33 . V_34 ) ;
if ( V_4 -> V_33 . V_32 ) {
F_22 ( V_4 -> V_33 . V_32 ) ;
F_21 ( V_4 -> V_33 . V_32 ) ;
}
V_4 -> V_33 . V_44 = 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_25 ( & V_4 -> V_28 . V_13 ) )
return;
F_26 ( V_2 ) ;
F_28 ( & V_4 -> V_28 . V_13 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
int V_48 = 0 ;
#ifdef F_30
if ( V_49 && F_2 ( V_2 ) -> V_9 < 8 ) {
F_16 ( L_8 ) ;
return 0 ;
}
#endif
if ( V_4 -> V_14 . V_15 == 0 )
return 0 ;
V_4 -> V_28 . V_42 = F_1 ( V_2 ) ;
if ( V_4 -> V_28 . V_42 == 0 )
return 0 ;
F_9 ( L_9 ,
V_4 -> V_14 . V_15 , V_4 -> V_28 . V_42 ) ;
if ( F_2 ( V_2 ) -> V_9 >= 8 ) {
V_47 = F_6 ( V_50 ) ;
V_47 >>= V_51 ;
V_47 &= V_52 ;
V_48 = ( 1024 * 1024 ) << V_47 ;
} else if ( F_31 ( V_2 ) ) {
V_47 = F_6 ( V_50 ) ;
V_48 = V_47 & V_53 ?
256 * 1024 : 1024 * 1024 ;
}
if ( F_32 ( V_48 > V_4 -> V_14 . V_15 ) )
return 0 ;
F_33 ( & V_4 -> V_28 . V_13 , 0 , V_4 -> V_14 . V_15 -
V_48 ) ;
return 0 ;
}
static struct V_54 *
F_34 ( struct V_1 * V_2 ,
T_1 V_55 , T_1 V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_54 * V_56 ;
struct V_57 * V_58 ;
F_35 ( L_10 , V_55 , V_24 ) ;
F_36 ( V_55 > V_4 -> V_14 . V_15 - V_24 ) ;
V_56 = F_37 ( sizeof( * V_56 ) , V_39 ) ;
if ( V_56 == NULL )
return NULL ;
if ( F_38 ( V_56 , 1 , V_39 ) ) {
F_21 ( V_56 ) ;
return NULL ;
}
V_58 = V_56 -> V_59 ;
V_58 -> V_55 = 0 ;
V_58 -> V_60 = V_24 ;
F_39 ( V_58 ) = ( V_61 ) V_4 -> V_28 . V_42 + V_55 ;
F_40 ( V_58 ) = V_24 ;
return V_56 ;
}
static int F_41 ( struct V_62 * V_63 )
{
F_42 () ;
return - V_64 ;
}
static void F_43 ( struct V_62 * V_63 )
{
F_44 ( V_63 -> V_65 ) ;
F_21 ( V_63 -> V_65 ) ;
}
static void
F_45 ( struct V_62 * V_63 )
{
if ( V_63 -> V_13 ) {
F_22 ( V_63 -> V_13 ) ;
F_21 ( V_63 -> V_13 ) ;
V_63 -> V_13 = NULL ;
}
}
static struct V_62 *
F_46 ( struct V_1 * V_2 ,
struct V_22 * V_13 )
{
struct V_62 * V_63 ;
V_63 = F_47 ( V_2 ) ;
if ( V_63 == NULL )
return NULL ;
F_48 ( V_2 , & V_63 -> V_8 , V_13 -> V_24 ) ;
F_49 ( V_63 , & V_66 ) ;
V_63 -> V_65 = F_34 ( V_2 ,
V_13 -> V_11 , V_13 -> V_24 ) ;
if ( V_63 -> V_65 == NULL )
goto V_67;
V_63 -> V_68 = true ;
F_50 ( V_63 ) ;
V_63 -> V_13 = V_13 ;
V_63 -> V_8 . V_69 = V_70 | V_71 ;
V_63 -> V_72 = F_51 ( V_2 ) ? V_73 : V_74 ;
return V_63 ;
V_67:
F_52 ( V_63 ) ;
return NULL ;
}
struct V_62 *
F_53 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
struct V_22 * V_13 ;
int V_27 ;
if ( ! F_25 ( & V_4 -> V_28 . V_13 ) )
return NULL ;
F_9 ( L_11 , V_24 ) ;
if ( V_24 == 0 )
return NULL ;
V_13 = F_20 ( sizeof( * V_13 ) , V_39 ) ;
if ( ! V_13 )
return NULL ;
V_27 = F_14 ( & V_4 -> V_28 . V_13 , V_13 , V_24 ,
4096 , V_29 ) ;
if ( V_27 ) {
F_21 ( V_13 ) ;
return NULL ;
}
V_63 = F_46 ( V_2 , V_13 ) ;
if ( V_63 )
return V_63 ;
F_22 ( V_13 ) ;
F_21 ( V_13 ) ;
return NULL ;
}
struct V_62 *
F_54 ( struct V_1 * V_2 ,
T_1 V_75 ,
T_1 V_76 ,
T_1 V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_78 = & V_4 -> V_14 . V_8 ;
struct V_62 * V_63 ;
struct V_22 * V_13 ;
struct V_79 * V_80 ;
int V_27 ;
if ( ! F_25 ( & V_4 -> V_28 . V_13 ) )
return NULL ;
F_9 ( L_12 ,
V_75 , V_76 , V_24 ) ;
if ( F_32 ( V_24 == 0 ) || F_32 ( V_24 & 4095 ) ||
F_32 ( V_75 & 4095 ) )
return NULL ;
V_13 = F_20 ( sizeof( * V_13 ) , V_39 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_11 = V_75 ;
V_13 -> V_24 = V_24 ;
V_27 = F_55 ( & V_4 -> V_28 . V_13 , V_13 ) ;
if ( V_27 ) {
F_9 ( L_13 ) ;
F_21 ( V_13 ) ;
return NULL ;
}
V_63 = F_46 ( V_2 , V_13 ) ;
if ( V_63 == NULL ) {
F_9 ( L_14 ) ;
F_22 ( V_13 ) ;
F_21 ( V_13 ) ;
return NULL ;
}
if ( V_76 == V_81 )
return V_63 ;
V_80 = F_56 ( V_63 , V_78 ) ;
if ( F_57 ( V_80 ) ) {
V_27 = F_58 ( V_80 ) ;
goto V_82;
}
V_80 -> V_23 . V_11 = V_76 ;
V_80 -> V_23 . V_24 = V_24 ;
if ( F_25 ( & V_78 -> V_28 ) ) {
V_27 = F_55 ( & V_78 -> V_28 , & V_80 -> V_23 ) ;
if ( V_27 ) {
F_9 ( L_15 ) ;
goto V_83;
}
}
V_80 -> V_84 |= V_85 ;
F_59 ( & V_63 -> V_86 , & V_4 -> V_28 . V_87 ) ;
F_59 ( & V_80 -> V_88 , & V_78 -> V_89 ) ;
F_50 ( V_63 ) ;
return V_63 ;
V_83:
F_60 ( V_80 ) ;
V_82:
F_22 ( V_13 ) ;
F_21 ( V_13 ) ;
F_61 ( & V_63 -> V_8 ) ;
return NULL ;
}
