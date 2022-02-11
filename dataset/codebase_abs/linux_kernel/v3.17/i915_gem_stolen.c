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
if ( V_7 == NULL ) {
F_11 ( L_4 ,
V_8 , V_8 + ( V_21 ) V_4 -> V_14 . V_15 ) ;
V_8 = 0 ;
}
}
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
int V_24 ,
int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_26 = 1 ;
int V_27 ;
V_27 = F_13 ( & V_4 -> V_28 . V_13 , V_23 ,
V_24 <<= 1 , 4096 , V_29 ) ;
if ( V_27 == 0 )
return V_26 ;
V_30:
if ( V_26 > 4 ||
( V_25 == 2 && V_26 == 2 ) )
return 0 ;
V_27 = F_13 ( & V_4 -> V_28 . V_13 , V_23 ,
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
static int F_14 ( struct V_1 * V_2 , int V_24 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_31 ( V_32 ) ;
int V_27 ;
V_27 = F_12 ( V_2 , & V_4 -> V_33 . V_34 ,
V_24 , V_25 ) ;
if ( ! V_27 )
goto V_35;
else if ( V_27 > 1 ) {
F_15 ( L_5 ) ;
}
V_4 -> V_33 . V_36 = V_27 ;
if ( F_16 ( V_2 ) )
F_17 ( V_37 , V_4 -> V_33 . V_34 . V_11 ) ;
else if ( F_18 ( V_2 ) ) {
F_17 ( V_38 , V_4 -> V_33 . V_34 . V_11 ) ;
} else {
V_32 = F_19 ( sizeof( * V_32 ) , V_39 ) ;
if ( ! V_32 )
goto V_40;
V_27 = F_13 ( & V_4 -> V_28 . V_13 , V_32 ,
4096 , 4096 , V_29 ) ;
if ( V_27 )
goto V_40;
V_4 -> V_33 . V_32 = V_32 ;
F_17 ( V_41 ,
V_4 -> V_28 . V_42 + V_4 -> V_33 . V_34 . V_11 ) ;
F_17 ( V_43 ,
V_4 -> V_28 . V_42 + V_32 -> V_11 ) ;
}
V_4 -> V_33 . V_24 = V_24 / V_4 -> V_33 . V_36 ;
F_9 ( L_6 ,
V_24 ) ;
return 0 ;
V_40:
F_20 ( V_32 ) ;
F_21 ( & V_4 -> V_33 . V_34 ) ;
V_35:
F_22 ( L_7 , V_24 ) ;
return - V_44 ;
}
int F_23 ( struct V_1 * V_2 , int V_24 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_24 ( & V_4 -> V_28 . V_13 ) )
return - V_45 ;
if ( V_24 < V_4 -> V_33 . V_24 )
return 0 ;
F_25 ( V_2 ) ;
return F_14 ( V_2 , V_24 , V_25 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_33 . V_24 == 0 )
return;
F_21 ( & V_4 -> V_33 . V_34 ) ;
if ( V_4 -> V_33 . V_32 ) {
F_21 ( V_4 -> V_33 . V_32 ) ;
F_20 ( V_4 -> V_33 . V_32 ) ;
}
V_4 -> V_33 . V_24 = 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_24 ( & V_4 -> V_28 . V_13 ) )
return;
F_25 ( V_2 ) ;
F_27 ( & V_4 -> V_28 . V_13 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_46 = 0 ;
#ifdef F_29
if ( V_47 && F_2 ( V_2 ) -> V_9 < 8 ) {
F_15 ( L_8 ) ;
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
if ( F_30 ( V_2 ) )
V_46 = 1024 * 1024 ;
if ( F_31 ( V_46 > V_4 -> V_14 . V_15 ) )
return 0 ;
F_32 ( & V_4 -> V_28 . V_13 , 0 , V_4 -> V_14 . V_15 -
V_46 ) ;
return 0 ;
}
static struct V_48 *
F_33 ( struct V_1 * V_2 ,
T_1 V_49 , T_1 V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_50 ;
struct V_51 * V_52 ;
F_34 ( L_10 , V_49 , V_24 ) ;
F_35 ( V_49 > V_4 -> V_14 . V_15 - V_24 ) ;
V_50 = F_36 ( sizeof( * V_50 ) , V_39 ) ;
if ( V_50 == NULL )
return NULL ;
if ( F_37 ( V_50 , 1 , V_39 ) ) {
F_20 ( V_50 ) ;
return NULL ;
}
V_52 = V_50 -> V_53 ;
V_52 -> V_49 = 0 ;
V_52 -> V_54 = V_24 ;
F_38 ( V_52 ) = ( V_55 ) V_4 -> V_28 . V_42 + V_49 ;
F_39 ( V_52 ) = V_24 ;
return V_50 ;
}
static int F_40 ( struct V_56 * V_57 )
{
F_41 () ;
return - V_58 ;
}
static void F_42 ( struct V_56 * V_57 )
{
F_43 ( V_57 -> V_59 ) ;
F_20 ( V_57 -> V_59 ) ;
}
static void
F_44 ( struct V_56 * V_57 )
{
if ( V_57 -> V_13 ) {
F_21 ( V_57 -> V_13 ) ;
F_20 ( V_57 -> V_13 ) ;
V_57 -> V_13 = NULL ;
}
}
static struct V_56 *
F_45 ( struct V_1 * V_2 ,
struct V_22 * V_13 )
{
struct V_56 * V_57 ;
V_57 = F_46 ( V_2 ) ;
if ( V_57 == NULL )
return NULL ;
F_47 ( V_2 , & V_57 -> V_8 , V_13 -> V_24 ) ;
F_48 ( V_57 , & V_60 ) ;
V_57 -> V_59 = F_33 ( V_2 ,
V_13 -> V_11 , V_13 -> V_24 ) ;
if ( V_57 -> V_59 == NULL )
goto V_61;
V_57 -> V_62 = true ;
F_49 ( V_57 ) ;
V_57 -> V_13 = V_13 ;
V_57 -> V_8 . V_63 = V_64 | V_65 ;
V_57 -> V_66 = F_50 ( V_2 ) ? V_67 : V_68 ;
return V_57 ;
V_61:
F_51 ( V_57 ) ;
return NULL ;
}
struct V_56 *
F_52 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_56 * V_57 ;
struct V_22 * V_13 ;
int V_27 ;
if ( ! F_24 ( & V_4 -> V_28 . V_13 ) )
return NULL ;
F_9 ( L_11 , V_24 ) ;
if ( V_24 == 0 )
return NULL ;
V_13 = F_19 ( sizeof( * V_13 ) , V_39 ) ;
if ( ! V_13 )
return NULL ;
V_27 = F_13 ( & V_4 -> V_28 . V_13 , V_13 , V_24 ,
4096 , V_29 ) ;
if ( V_27 ) {
F_20 ( V_13 ) ;
return NULL ;
}
V_57 = F_45 ( V_2 , V_13 ) ;
if ( V_57 )
return V_57 ;
F_21 ( V_13 ) ;
F_20 ( V_13 ) ;
return NULL ;
}
struct V_56 *
F_53 ( struct V_1 * V_2 ,
T_1 V_69 ,
T_1 V_70 ,
T_1 V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_71 * V_72 = & V_4 -> V_14 . V_8 ;
struct V_56 * V_57 ;
struct V_22 * V_13 ;
struct V_73 * V_74 ;
int V_27 ;
if ( ! F_24 ( & V_4 -> V_28 . V_13 ) )
return NULL ;
F_9 ( L_12 ,
V_69 , V_70 , V_24 ) ;
F_35 ( V_69 & 4095 ) ;
F_35 ( V_24 & 4095 ) ;
if ( F_31 ( V_24 == 0 ) )
return NULL ;
V_13 = F_19 ( sizeof( * V_13 ) , V_39 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_11 = V_69 ;
V_13 -> V_24 = V_24 ;
V_27 = F_54 ( & V_4 -> V_28 . V_13 , V_13 ) ;
if ( V_27 ) {
F_9 ( L_13 ) ;
F_20 ( V_13 ) ;
return NULL ;
}
V_57 = F_45 ( V_2 , V_13 ) ;
if ( V_57 == NULL ) {
F_9 ( L_14 ) ;
F_21 ( V_13 ) ;
F_20 ( V_13 ) ;
return NULL ;
}
if ( V_70 == V_75 )
return V_57 ;
V_74 = F_55 ( V_57 , V_72 ) ;
if ( F_56 ( V_74 ) ) {
V_27 = F_57 ( V_74 ) ;
goto V_76;
}
V_74 -> V_23 . V_11 = V_70 ;
V_74 -> V_23 . V_24 = V_24 ;
if ( F_24 ( & V_72 -> V_28 ) ) {
V_27 = F_54 ( & V_72 -> V_28 , & V_74 -> V_23 ) ;
if ( V_27 ) {
F_9 ( L_15 ) ;
goto V_77;
}
}
V_57 -> V_78 = 1 ;
F_58 ( & V_57 -> V_79 , & V_4 -> V_28 . V_80 ) ;
F_58 ( & V_74 -> V_81 , & V_72 -> V_82 ) ;
F_49 ( V_57 ) ;
return V_57 ;
V_77:
F_59 ( V_74 ) ;
V_76:
F_21 ( V_13 ) ;
F_20 ( V_13 ) ;
F_60 ( & V_57 -> V_8 ) ;
return NULL ;
}
