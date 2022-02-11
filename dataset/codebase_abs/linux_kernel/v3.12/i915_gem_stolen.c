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
F_5 ( L_2 ,
V_8 , V_8 + ( V_13 ) V_4 -> V_11 . V_12 ) ;
V_8 = 0 ;
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
if ( V_4 -> V_11 . V_12 == 0 )
return 0 ;
V_4 -> V_22 . V_31 = F_1 ( V_2 ) ;
if ( V_4 -> V_22 . V_31 == 0 )
return 0 ;
F_12 ( L_5 ,
V_4 -> V_11 . V_12 , V_4 -> V_22 . V_31 ) ;
if ( F_22 ( V_2 ) )
V_35 = 1024 * 1024 ;
if ( F_23 ( V_35 > V_4 -> V_11 . V_12 ) )
return 0 ;
F_24 ( & V_4 -> V_22 . V_23 , 0 , V_4 -> V_11 . V_12 -
V_35 ) ;
return 0 ;
}
static struct V_36 *
F_25 ( struct V_1 * V_2 ,
T_1 V_37 , T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_36 * V_38 ;
struct V_39 * V_40 ;
F_26 ( L_6 , V_37 , V_14 ) ;
F_27 ( V_37 > V_4 -> V_11 . V_12 - V_14 ) ;
V_38 = F_28 ( sizeof( * V_38 ) , V_20 ) ;
if ( V_38 == NULL )
return NULL ;
if ( F_29 ( V_38 , 1 , V_20 ) ) {
F_13 ( V_38 ) ;
return NULL ;
}
V_40 = V_38 -> V_41 ;
V_40 -> V_37 = V_37 ;
V_40 -> V_42 = V_14 ;
F_30 ( V_40 ) = ( V_43 ) V_4 -> V_22 . V_31 + V_37 ;
F_31 ( V_40 ) = V_14 ;
return V_38 ;
}
static int F_32 ( struct V_44 * V_45 )
{
F_33 () ;
return - V_46 ;
}
static void F_34 ( struct V_44 * V_45 )
{
F_35 ( V_45 -> V_47 ) ;
F_13 ( V_45 -> V_47 ) ;
}
static struct V_44 *
F_36 ( struct V_1 * V_2 ,
struct V_15 * V_23 )
{
struct V_44 * V_45 ;
V_45 = F_37 ( V_2 ) ;
if ( V_45 == NULL )
return NULL ;
F_38 ( V_2 , & V_45 -> V_8 , V_23 -> V_14 ) ;
F_39 ( V_45 , & V_48 ) ;
V_45 -> V_47 = F_25 ( V_2 ,
V_23 -> V_26 , V_23 -> V_14 ) ;
if ( V_45 -> V_47 == NULL )
goto V_49;
V_45 -> V_50 = true ;
F_40 ( V_45 ) ;
V_45 -> V_23 = V_23 ;
V_45 -> V_8 . V_51 = V_52 | V_53 ;
V_45 -> V_54 = F_41 ( V_2 ) ? V_55 : V_56 ;
return V_45 ;
V_49:
F_42 ( V_45 ) ;
return NULL ;
}
struct V_44 *
F_43 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_44 * V_45 ;
struct V_15 * V_23 ;
int V_19 ;
if ( ! F_17 ( & V_4 -> V_22 . V_23 ) )
return NULL ;
F_12 ( L_7 , V_14 ) ;
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
V_45 = F_36 ( V_2 , V_23 ) ;
if ( V_45 )
return V_45 ;
F_14 ( V_23 ) ;
F_13 ( V_23 ) ;
return NULL ;
}
struct V_44 *
F_44 ( struct V_1 * V_2 ,
T_1 V_57 ,
T_1 V_58 ,
T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_59 * V_60 = & V_4 -> V_11 . V_8 ;
struct V_44 * V_45 ;
struct V_15 * V_23 ;
struct V_61 * V_62 ;
int V_19 ;
if ( ! F_17 ( & V_4 -> V_22 . V_23 ) )
return NULL ;
F_12 ( L_8 ,
V_57 , V_58 , V_14 ) ;
F_27 ( V_57 & 4095 ) ;
F_27 ( V_14 & 4095 ) ;
if ( F_23 ( V_14 == 0 ) )
return NULL ;
V_23 = F_7 ( sizeof( * V_23 ) , V_20 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_26 = V_57 ;
V_23 -> V_14 = V_14 ;
V_19 = F_45 ( & V_4 -> V_22 . V_23 , V_23 ) ;
if ( V_19 ) {
F_12 ( L_9 ) ;
F_13 ( V_23 ) ;
return NULL ;
}
V_45 = F_36 ( V_2 , V_23 ) ;
if ( V_45 == NULL ) {
F_12 ( L_10 ) ;
F_14 ( V_23 ) ;
F_13 ( V_23 ) ;
return NULL ;
}
if ( V_58 == V_63 )
return V_45 ;
V_62 = F_46 ( V_45 , V_60 ) ;
if ( F_47 ( V_62 ) ) {
V_19 = F_48 ( V_62 ) ;
goto V_64;
}
V_62 -> V_65 . V_26 = V_58 ;
V_62 -> V_65 . V_14 = V_14 ;
if ( F_17 ( & V_60 -> V_22 ) ) {
V_19 = F_45 ( & V_60 -> V_22 , & V_62 -> V_65 ) ;
if ( V_19 ) {
F_12 ( L_11 ) ;
goto V_66;
}
}
V_45 -> V_67 = 1 ;
F_49 ( & V_45 -> V_68 , & V_4 -> V_22 . V_69 ) ;
F_49 ( & V_62 -> V_70 , & V_60 -> V_71 ) ;
return V_45 ;
V_66:
F_50 ( V_62 ) ;
V_64:
F_14 ( V_23 ) ;
F_13 ( V_23 ) ;
F_51 ( & V_45 -> V_8 ) ;
return NULL ;
}
void
F_52 ( struct V_44 * V_45 )
{
if ( V_45 -> V_23 ) {
F_14 ( V_45 -> V_23 ) ;
F_13 ( V_45 -> V_23 ) ;
V_45 -> V_23 = NULL ;
}
}
