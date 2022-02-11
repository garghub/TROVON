static void F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned char V_3 )
{
F_4 ( V_2 , V_3 ) ;
}
static unsigned char F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 ) ;
}
static unsigned char F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) ;
}
static unsigned char F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) ;
}
static inline void F_11 ( struct V_1 * V_4 , int V_5 ,
const struct V_6 * V_7 )
{
T_1 V_8 = V_9 [ V_7 -> V_10 ] ( V_4 ) ;
if ( ( V_7 -> V_11 && ! V_5 ) || ( ! V_7 -> V_11 && V_5 ) )
V_12 [ V_7 -> V_10 ] ( V_4 , V_8 | V_7 -> V_13 ) ;
else
V_12 [ V_7 -> V_10 ] ( V_4 , V_8 & ~ V_7 -> V_13 ) ;
}
static inline int F_12 ( struct V_1 * V_4 ,
const struct V_6 * V_7 )
{
T_1 V_8 = V_9 [ V_7 -> V_10 ] ( V_4 ) ;
return ( ( V_7 -> V_11 && ( V_8 & V_7 -> V_13 ) != V_7 -> V_13 )
|| ( ! V_7 -> V_11 && ( V_8 & V_7 -> V_13 ) == V_7 -> V_13 ) ) ;
}
static void F_13 ( void * V_4 , int V_5 )
{
F_11 ( (struct V_1 * ) V_4 , V_5 , & V_14 [ type ] . V_15 ) ;
}
static void F_14 ( void * V_4 , int V_5 )
{
F_11 ( (struct V_1 * ) V_4 , V_5 , & V_14 [ type ] . V_16 ) ;
}
static int F_15 ( void * V_4 )
{
return F_12 ( (struct V_1 * ) V_4 , & V_14 [ type ] . V_17 ) ;
}
static int F_16 ( void * V_4 )
{
return F_12 ( (struct V_1 * ) V_4 , & V_14 [ type ] . V_18 ) ;
}
void F_17 ( void * V_4 )
{
struct V_19 * V_20 = V_4 ;
struct V_21 * V_22 = V_20 -> V_22 ;
if ( V_22 ) {
F_18 ( & V_22 -> V_23 , L_1 ) ;
F_19 ( V_22 ) ;
} else
F_18 ( & V_20 -> V_20 . V_23 ,
L_2 ) ;
}
static void F_20 ( struct V_1 * V_10 )
{
struct V_19 * V_20 ;
V_20 = F_21 ( sizeof( struct V_19 ) , V_24 ) ;
if ( V_20 == NULL ) {
F_22 ( V_25 L_3 ) ;
return;
}
F_23 ( L_4 , V_10 -> V_26 ) ;
F_24 ( V_10 ) ;
V_20 -> V_27 = F_25 ( V_10 , L_5 ,
NULL , NULL , F_17 , V_28 , V_20 ) ;
if ( ! V_20 -> V_27 ) {
F_22 ( V_25 L_6 ) ;
goto V_29;
}
V_20 -> V_20 . V_30 = V_31 ;
V_20 -> V_20 . V_32 = V_33 ;
F_26 ( V_20 -> V_20 . V_26 , L_7 ,
sizeof( V_20 -> V_20 . V_26 ) ) ;
V_20 -> V_34 = V_35 ;
if ( ! V_14 [ type ] . V_17 . V_13 ) {
V_20 -> V_34 . V_17 = NULL ;
V_20 -> V_34 . V_36 = 50 ;
}
V_20 -> V_34 . V_4 = V_10 ;
V_20 -> V_20 . V_34 = & V_20 -> V_34 ;
V_20 -> V_20 . V_23 . V_37 = V_10 -> V_38 -> V_23 ;
if ( F_27 ( V_20 -> V_27 ) < 0 ) {
F_22 ( V_25 L_8 ) ;
goto V_39;
}
F_14 ( V_10 , 1 ) ;
F_13 ( V_10 , 1 ) ;
if ( V_14 [ type ] . V_40 . V_13 ) {
F_11 ( V_10 , 1 , & V_14 [ type ] . V_40 ) ;
F_28 ( 100 ) ;
}
if ( F_29 ( & V_20 -> V_20 ) < 0 ) {
F_22 ( V_25 L_9 ) ;
goto V_39;
}
if ( V_14 [ type ] . V_41 ) {
V_20 -> V_42 . V_43 = 1 ;
V_20 -> V_22 = F_30 ( & V_20 -> V_20 ,
& V_20 -> V_42 ) ;
if ( V_20 -> V_22 )
F_31 ( V_10 ) ;
else
F_22 ( V_44 L_10
L_11 ) ;
}
F_32 ( & V_45 ) ;
F_33 ( & V_20 -> V_46 , & V_47 ) ;
F_34 ( & V_45 ) ;
return;
V_39:
F_35 ( V_20 -> V_27 ) ;
F_36 ( V_20 -> V_27 ) ;
V_29:
F_37 ( V_20 ) ;
}
static void F_38 ( struct V_1 * V_10 )
{
struct V_19 * V_20 , * V_48 ;
F_32 ( & V_45 ) ;
F_39 (adapter, _n, &adapter_list, node) {
if ( V_20 -> V_27 -> V_10 == V_10 ) {
if ( V_20 -> V_22 ) {
F_24 ( V_10 ) ;
F_40 ( V_20 -> V_22 ) ;
}
F_41 ( & V_20 -> V_20 ) ;
if ( V_14 [ type ] . V_40 . V_13 )
F_11 ( V_10 , 0 , & V_14 [ type ] . V_40 ) ;
F_35 ( V_20 -> V_27 ) ;
F_36 ( V_20 -> V_27 ) ;
F_42 ( & V_20 -> V_46 ) ;
F_37 ( V_20 ) ;
}
}
F_34 ( & V_45 ) ;
}
static int T_2 F_43 ( void )
{
if ( type < 0 ) {
F_22 ( V_44 L_12 ) ;
return - V_49 ;
}
if ( type >= F_44 ( V_14 ) ) {
F_22 ( V_44 L_13 , type ) ;
return - V_49 ;
}
return F_45 ( & V_50 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_50 ) ;
}
