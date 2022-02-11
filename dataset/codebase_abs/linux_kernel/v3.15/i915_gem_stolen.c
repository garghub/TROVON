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
V_7 = F_4 ( V_2 -> V_2 , V_8 , V_4 -> V_11 . V_12 ,
L_1 ) ;
if ( V_7 == NULL ) {
V_7 = F_4 ( V_2 -> V_2 , V_8 + 1 ,
V_4 -> V_11 . V_12 - 1 ,
L_1 ) ;
if ( V_7 == NULL ) {
F_5 ( L_2 ,
V_8 , V_8 + ( V_13 ) V_4 -> V_11 . V_12 ) ;
V_8 = 0 ;
}
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 , * V_17 ( V_18 ) ;
int V_19 ;
V_16 = F_7 ( sizeof( * V_16 ) , V_20 ) ;
if ( ! V_16 )
goto V_21;
V_19 = F_8 ( & V_4 -> V_22 . V_23 , V_16 ,
V_14 <<= 1 , 4096 , V_24 ) ;
if ( V_19 )
V_19 = F_8 ( & V_4 -> V_22 . V_23 , V_16 ,
V_14 >>= 1 , 4096 ,
V_24 ) ;
if ( V_19 )
goto V_21;
if ( F_9 ( V_2 ) )
F_10 ( V_25 , V_16 -> V_26 ) ;
else if ( F_11 ( V_2 ) ) {
F_10 ( V_27 , V_16 -> V_26 ) ;
} else {
V_18 = F_7 ( sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 )
goto V_28;
V_19 = F_8 ( & V_4 -> V_22 . V_23 , V_18 ,
4096 , 4096 , V_24 ) ;
if ( V_19 )
goto V_28;
V_4 -> V_29 . V_18 = V_18 ;
F_10 ( V_30 ,
V_4 -> V_22 . V_31 + V_16 -> V_26 ) ;
F_10 ( V_32 ,
V_4 -> V_22 . V_31 + V_18 -> V_26 ) ;
}
V_4 -> V_29 . V_16 = V_16 ;
V_4 -> V_29 . V_14 = V_14 ;
F_12 ( L_3 ,
V_14 ) ;
return 0 ;
V_28:
F_13 ( V_18 ) ;
F_14 ( V_16 ) ;
V_21:
F_13 ( V_16 ) ;
F_15 ( L_4 , V_14 ) ;
return - V_33 ;
}
int F_16 ( struct V_1 * V_2 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( & V_4 -> V_22 . V_23 ) )
return - V_34 ;
if ( V_14 < V_4 -> V_29 . V_14 )
return 0 ;
F_18 ( V_2 ) ;
return F_6 ( V_2 , V_14 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_29 . V_14 == 0 )
return;
if ( V_4 -> V_29 . V_16 ) {
F_14 ( V_4 -> V_29 . V_16 ) ;
F_13 ( V_4 -> V_29 . V_16 ) ;
}
if ( V_4 -> V_29 . V_18 ) {
F_14 ( V_4 -> V_29 . V_18 ) ;
F_13 ( V_4 -> V_29 . V_18 ) ;
}
V_4 -> V_29 . V_14 = 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( & V_4 -> V_22 . V_23 ) )
return;
F_18 ( V_2 ) ;
F_20 ( & V_4 -> V_22 . V_23 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_35 = 0 ;
#ifdef F_22
if ( V_36 && F_2 ( V_2 ) -> V_9 < 8 ) {
F_23 ( L_5 ) ;
return 0 ;
}
#endif
if ( V_4 -> V_11 . V_12 == 0 )
return 0 ;
V_4 -> V_22 . V_31 = F_1 ( V_2 ) ;
if ( V_4 -> V_22 . V_31 == 0 )
return 0 ;
F_12 ( L_6 ,
V_4 -> V_11 . V_12 , V_4 -> V_22 . V_31 ) ;
if ( F_24 ( V_2 ) )
V_35 = 1024 * 1024 ;
if ( F_25 ( V_35 > V_4 -> V_11 . V_12 ) )
return 0 ;
F_26 ( & V_4 -> V_22 . V_23 , 0 , V_4 -> V_11 . V_12 -
V_35 ) ;
return 0 ;
}
static struct V_37 *
F_27 ( struct V_1 * V_2 ,
T_1 V_38 , T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_39 ;
struct V_40 * V_41 ;
F_28 ( L_7 , V_38 , V_14 ) ;
F_29 ( V_38 > V_4 -> V_11 . V_12 - V_14 ) ;
V_39 = F_30 ( sizeof( * V_39 ) , V_20 ) ;
if ( V_39 == NULL )
return NULL ;
if ( F_31 ( V_39 , 1 , V_20 ) ) {
F_13 ( V_39 ) ;
return NULL ;
}
V_41 = V_39 -> V_42 ;
V_41 -> V_38 = 0 ;
V_41 -> V_43 = V_14 ;
F_32 ( V_41 ) = ( V_44 ) V_4 -> V_22 . V_31 + V_38 ;
F_33 ( V_41 ) = V_14 ;
return V_39 ;
}
static int F_34 ( struct V_45 * V_46 )
{
F_35 () ;
return - V_47 ;
}
static void F_36 ( struct V_45 * V_46 )
{
F_37 ( V_46 -> V_48 ) ;
F_13 ( V_46 -> V_48 ) ;
}
static struct V_45 *
F_38 ( struct V_1 * V_2 ,
struct V_15 * V_23 )
{
struct V_45 * V_46 ;
V_46 = F_39 ( V_2 ) ;
if ( V_46 == NULL )
return NULL ;
F_40 ( V_2 , & V_46 -> V_8 , V_23 -> V_14 ) ;
F_41 ( V_46 , & V_49 ) ;
V_46 -> V_48 = F_27 ( V_2 ,
V_23 -> V_26 , V_23 -> V_14 ) ;
if ( V_46 -> V_48 == NULL )
goto V_50;
V_46 -> V_51 = true ;
F_42 ( V_46 ) ;
V_46 -> V_23 = V_23 ;
V_46 -> V_8 . V_52 = V_53 | V_54 ;
V_46 -> V_55 = F_43 ( V_2 ) ? V_56 : V_57 ;
return V_46 ;
V_50:
F_44 ( V_46 ) ;
return NULL ;
}
struct V_45 *
F_45 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_45 * V_46 ;
struct V_15 * V_23 ;
int V_19 ;
if ( ! F_17 ( & V_4 -> V_22 . V_23 ) )
return NULL ;
F_12 ( L_8 , V_14 ) ;
if ( V_14 == 0 )
return NULL ;
V_23 = F_7 ( sizeof( * V_23 ) , V_20 ) ;
if ( ! V_23 )
return NULL ;
V_19 = F_8 ( & V_4 -> V_22 . V_23 , V_23 , V_14 ,
4096 , V_24 ) ;
if ( V_19 ) {
F_13 ( V_23 ) ;
return NULL ;
}
V_46 = F_38 ( V_2 , V_23 ) ;
if ( V_46 )
return V_46 ;
F_14 ( V_23 ) ;
F_13 ( V_23 ) ;
return NULL ;
}
struct V_45 *
F_46 ( struct V_1 * V_2 ,
T_1 V_58 ,
T_1 V_59 ,
T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_60 * V_61 = & V_4 -> V_11 . V_8 ;
struct V_45 * V_46 ;
struct V_15 * V_23 ;
struct V_62 * V_63 ;
int V_19 ;
if ( ! F_17 ( & V_4 -> V_22 . V_23 ) )
return NULL ;
F_12 ( L_9 ,
V_58 , V_59 , V_14 ) ;
F_29 ( V_58 & 4095 ) ;
F_29 ( V_14 & 4095 ) ;
if ( F_25 ( V_14 == 0 ) )
return NULL ;
V_23 = F_7 ( sizeof( * V_23 ) , V_20 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_26 = V_58 ;
V_23 -> V_14 = V_14 ;
V_19 = F_47 ( & V_4 -> V_22 . V_23 , V_23 ) ;
if ( V_19 ) {
F_12 ( L_10 ) ;
F_13 ( V_23 ) ;
return NULL ;
}
V_46 = F_38 ( V_2 , V_23 ) ;
if ( V_46 == NULL ) {
F_12 ( L_11 ) ;
F_14 ( V_23 ) ;
F_13 ( V_23 ) ;
return NULL ;
}
if ( V_59 == V_64 )
return V_46 ;
V_63 = F_48 ( V_46 , V_61 ) ;
if ( F_49 ( V_63 ) ) {
V_19 = F_50 ( V_63 ) ;
goto V_65;
}
V_63 -> V_66 . V_26 = V_59 ;
V_63 -> V_66 . V_14 = V_14 ;
if ( F_17 ( & V_61 -> V_22 ) ) {
V_19 = F_47 ( & V_61 -> V_22 , & V_63 -> V_66 ) ;
if ( V_19 ) {
F_12 ( L_12 ) ;
goto V_67;
}
}
V_46 -> V_68 = 1 ;
F_51 ( & V_46 -> V_69 , & V_4 -> V_22 . V_70 ) ;
F_51 ( & V_63 -> V_71 , & V_61 -> V_72 ) ;
F_42 ( V_46 ) ;
return V_46 ;
V_67:
F_52 ( V_63 ) ;
V_65:
F_14 ( V_23 ) ;
F_13 ( V_23 ) ;
F_53 ( & V_46 -> V_8 ) ;
return NULL ;
}
void
F_54 ( struct V_45 * V_46 )
{
if ( V_46 -> V_23 ) {
F_14 ( V_46 -> V_23 ) ;
F_13 ( V_46 -> V_23 ) ;
V_46 -> V_23 = NULL ;
}
}
