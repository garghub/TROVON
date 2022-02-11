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
static int F_12 ( struct V_1 * V_2 , int V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 , * V_25 ( V_26 ) ;
int V_27 ;
V_24 = F_13 ( sizeof( * V_24 ) , V_28 ) ;
if ( ! V_24 )
goto V_29;
V_27 = F_14 ( & V_4 -> V_30 . V_13 , V_24 ,
V_22 <<= 1 , 4096 , V_31 ) ;
if ( V_27 )
V_27 = F_14 ( & V_4 -> V_30 . V_13 , V_24 ,
V_22 >>= 1 , 4096 ,
V_31 ) ;
if ( V_27 )
goto V_29;
if ( F_15 ( V_2 ) )
F_16 ( V_32 , V_24 -> V_11 ) ;
else if ( F_17 ( V_2 ) ) {
F_16 ( V_33 , V_24 -> V_11 ) ;
} else {
V_26 = F_13 ( sizeof( * V_26 ) , V_28 ) ;
if ( ! V_26 )
goto V_34;
V_27 = F_14 ( & V_4 -> V_30 . V_13 , V_26 ,
4096 , 4096 , V_31 ) ;
if ( V_27 )
goto V_34;
V_4 -> V_35 . V_26 = V_26 ;
F_16 ( V_36 ,
V_4 -> V_30 . V_37 + V_24 -> V_11 ) ;
F_16 ( V_38 ,
V_4 -> V_30 . V_37 + V_26 -> V_11 ) ;
}
V_4 -> V_35 . V_24 = V_24 ;
V_4 -> V_35 . V_22 = V_22 ;
F_9 ( L_5 ,
V_22 ) ;
return 0 ;
V_34:
F_18 ( V_26 ) ;
F_19 ( V_24 ) ;
V_29:
F_18 ( V_24 ) ;
F_20 ( L_6 , V_22 ) ;
return - V_39 ;
}
int F_21 ( struct V_1 * V_2 , int V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_22 ( & V_4 -> V_30 . V_13 ) )
return - V_40 ;
if ( V_22 < V_4 -> V_35 . V_22 )
return 0 ;
F_23 ( V_2 ) ;
return F_12 ( V_2 , V_22 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_35 . V_22 == 0 )
return;
if ( V_4 -> V_35 . V_24 ) {
F_19 ( V_4 -> V_35 . V_24 ) ;
F_18 ( V_4 -> V_35 . V_24 ) ;
}
if ( V_4 -> V_35 . V_26 ) {
F_19 ( V_4 -> V_35 . V_26 ) ;
F_18 ( V_4 -> V_35 . V_26 ) ;
}
V_4 -> V_35 . V_22 = 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_22 ( & V_4 -> V_30 . V_13 ) )
return;
F_23 ( V_2 ) ;
F_25 ( & V_4 -> V_30 . V_13 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_41 = 0 ;
#ifdef F_27
if ( V_42 && F_2 ( V_2 ) -> V_9 < 8 ) {
F_28 ( L_7 ) ;
return 0 ;
}
#endif
if ( V_4 -> V_14 . V_15 == 0 )
return 0 ;
V_4 -> V_30 . V_37 = F_1 ( V_2 ) ;
if ( V_4 -> V_30 . V_37 == 0 )
return 0 ;
F_9 ( L_8 ,
V_4 -> V_14 . V_15 , V_4 -> V_30 . V_37 ) ;
if ( F_29 ( V_2 ) )
V_41 = 1024 * 1024 ;
if ( F_30 ( V_41 > V_4 -> V_14 . V_15 ) )
return 0 ;
F_31 ( & V_4 -> V_30 . V_13 , 0 , V_4 -> V_14 . V_15 -
V_41 ) ;
return 0 ;
}
static struct V_43 *
F_32 ( struct V_1 * V_2 ,
T_1 V_44 , T_1 V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_45 ;
struct V_46 * V_47 ;
F_33 ( L_9 , V_44 , V_22 ) ;
F_34 ( V_44 > V_4 -> V_14 . V_15 - V_22 ) ;
V_45 = F_35 ( sizeof( * V_45 ) , V_28 ) ;
if ( V_45 == NULL )
return NULL ;
if ( F_36 ( V_45 , 1 , V_28 ) ) {
F_18 ( V_45 ) ;
return NULL ;
}
V_47 = V_45 -> V_48 ;
V_47 -> V_44 = 0 ;
V_47 -> V_49 = V_22 ;
F_37 ( V_47 ) = ( V_50 ) V_4 -> V_30 . V_37 + V_44 ;
F_38 ( V_47 ) = V_22 ;
return V_45 ;
}
static int F_39 ( struct V_51 * V_52 )
{
F_40 () ;
return - V_53 ;
}
static void F_41 ( struct V_51 * V_52 )
{
F_42 ( V_52 -> V_54 ) ;
F_18 ( V_52 -> V_54 ) ;
}
static struct V_51 *
F_43 ( struct V_1 * V_2 ,
struct V_23 * V_13 )
{
struct V_51 * V_52 ;
V_52 = F_44 ( V_2 ) ;
if ( V_52 == NULL )
return NULL ;
F_45 ( V_2 , & V_52 -> V_8 , V_13 -> V_22 ) ;
F_46 ( V_52 , & V_55 ) ;
V_52 -> V_54 = F_32 ( V_2 ,
V_13 -> V_11 , V_13 -> V_22 ) ;
if ( V_52 -> V_54 == NULL )
goto V_56;
V_52 -> V_57 = true ;
F_47 ( V_52 ) ;
V_52 -> V_13 = V_13 ;
V_52 -> V_8 . V_58 = V_59 | V_60 ;
V_52 -> V_61 = F_48 ( V_2 ) ? V_62 : V_63 ;
return V_52 ;
V_56:
F_49 ( V_52 ) ;
return NULL ;
}
struct V_51 *
F_50 ( struct V_1 * V_2 , T_1 V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_51 * V_52 ;
struct V_23 * V_13 ;
int V_27 ;
if ( ! F_22 ( & V_4 -> V_30 . V_13 ) )
return NULL ;
F_9 ( L_10 , V_22 ) ;
if ( V_22 == 0 )
return NULL ;
V_13 = F_13 ( sizeof( * V_13 ) , V_28 ) ;
if ( ! V_13 )
return NULL ;
V_27 = F_14 ( & V_4 -> V_30 . V_13 , V_13 , V_22 ,
4096 , V_31 ) ;
if ( V_27 ) {
F_18 ( V_13 ) ;
return NULL ;
}
V_52 = F_43 ( V_2 , V_13 ) ;
if ( V_52 )
return V_52 ;
F_19 ( V_13 ) ;
F_18 ( V_13 ) ;
return NULL ;
}
struct V_51 *
F_51 ( struct V_1 * V_2 ,
T_1 V_64 ,
T_1 V_65 ,
T_1 V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_66 * V_67 = & V_4 -> V_14 . V_8 ;
struct V_51 * V_52 ;
struct V_23 * V_13 ;
struct V_68 * V_69 ;
int V_27 ;
if ( ! F_22 ( & V_4 -> V_30 . V_13 ) )
return NULL ;
F_9 ( L_11 ,
V_64 , V_65 , V_22 ) ;
F_34 ( V_64 & 4095 ) ;
F_34 ( V_22 & 4095 ) ;
if ( F_30 ( V_22 == 0 ) )
return NULL ;
V_13 = F_13 ( sizeof( * V_13 ) , V_28 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_11 = V_64 ;
V_13 -> V_22 = V_22 ;
V_27 = F_52 ( & V_4 -> V_30 . V_13 , V_13 ) ;
if ( V_27 ) {
F_9 ( L_12 ) ;
F_18 ( V_13 ) ;
return NULL ;
}
V_52 = F_43 ( V_2 , V_13 ) ;
if ( V_52 == NULL ) {
F_9 ( L_13 ) ;
F_19 ( V_13 ) ;
F_18 ( V_13 ) ;
return NULL ;
}
if ( V_65 == V_70 )
return V_52 ;
V_69 = F_53 ( V_52 , V_67 ) ;
if ( F_54 ( V_69 ) ) {
V_27 = F_55 ( V_69 ) ;
goto V_71;
}
V_69 -> V_72 . V_11 = V_65 ;
V_69 -> V_72 . V_22 = V_22 ;
if ( F_22 ( & V_67 -> V_30 ) ) {
V_27 = F_52 ( & V_67 -> V_30 , & V_69 -> V_72 ) ;
if ( V_27 ) {
F_9 ( L_14 ) ;
goto V_73;
}
}
V_52 -> V_74 = 1 ;
F_56 ( & V_52 -> V_75 , & V_4 -> V_30 . V_76 ) ;
F_56 ( & V_69 -> V_77 , & V_67 -> V_78 ) ;
F_47 ( V_52 ) ;
return V_52 ;
V_73:
F_57 ( V_69 ) ;
V_71:
F_19 ( V_13 ) ;
F_18 ( V_13 ) ;
F_58 ( & V_52 -> V_8 ) ;
return NULL ;
}
void
F_59 ( struct V_51 * V_52 )
{
if ( V_52 -> V_13 ) {
F_19 ( V_52 -> V_13 ) ;
F_18 ( V_52 -> V_13 ) ;
V_52 -> V_13 = NULL ;
}
}
