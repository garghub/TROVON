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
static void F_17 ( void * V_4 )
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
int V_24 ;
struct V_25 V_26 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
if ( V_1 [ V_24 ] == - 1 )
continue;
if ( V_10 -> V_28 == V_1 [ V_24 ] )
break;
}
if ( V_24 == V_27 ) {
F_21 ( L_3 , V_10 -> V_28 ) ;
return;
}
V_20 = F_22 ( sizeof( struct V_19 ) , V_29 ) ;
if ( ! V_20 )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_30 = V_31 ;
V_26 . V_32 = F_17 ;
V_26 . V_33 = V_20 ;
F_21 ( L_4 , V_10 -> V_34 ) ;
F_23 ( V_10 ) ;
V_20 -> V_35 = F_24 ( V_10 , L_5 ,
& V_26 , V_24 ) ;
if ( ! V_20 -> V_35 ) {
F_25 ( L_6 ) ;
goto V_36;
}
V_20 -> V_20 . V_37 = V_38 ;
V_20 -> V_20 . V_39 = V_40 ;
F_26 ( V_20 -> V_20 . V_34 , L_7 ,
sizeof( V_20 -> V_20 . V_34 ) ) ;
V_20 -> V_41 = V_42 ;
if ( ! V_14 [ type ] . V_17 . V_13 ) {
V_20 -> V_41 . V_17 = NULL ;
V_20 -> V_41 . V_43 = 50 ;
}
V_20 -> V_41 . V_4 = V_10 ;
V_20 -> V_20 . V_41 = & V_20 -> V_41 ;
V_20 -> V_20 . V_23 . V_44 = V_10 -> V_45 -> V_23 ;
if ( F_27 ( V_20 -> V_35 ) < 0 ) {
F_28 ( & V_20 -> V_35 -> V_23 ,
L_8 ) ;
goto V_46;
}
F_14 ( V_10 , 1 ) ;
F_13 ( V_10 , 1 ) ;
if ( V_14 [ type ] . V_47 . V_13 ) {
F_11 ( V_10 , 1 , & V_14 [ type ] . V_47 ) ;
F_29 ( 100 ) ;
}
if ( F_30 ( & V_20 -> V_20 ) < 0 ) {
F_28 ( & V_20 -> V_35 -> V_23 , L_9 ) ;
goto V_46;
}
if ( V_14 [ type ] . V_48 ) {
V_20 -> V_49 . V_50 = 1 ;
V_20 -> V_22 = F_31 ( & V_20 -> V_20 ,
& V_20 -> V_49 ) ;
if ( V_20 -> V_22 )
F_32 ( V_10 ) ;
else
F_33 ( & V_20 -> V_35 -> V_23 ,
L_10 ) ;
}
F_34 ( & V_51 ) ;
F_35 ( & V_20 -> V_52 , & V_53 ) ;
F_36 ( & V_51 ) ;
return;
V_46:
F_37 ( V_20 -> V_35 ) ;
F_38 ( V_20 -> V_35 ) ;
V_36:
F_39 ( V_20 ) ;
}
static void F_40 ( struct V_1 * V_10 )
{
struct V_19 * V_20 , * V_54 ;
F_34 ( & V_51 ) ;
F_41 (adapter, _n, &adapter_list, node) {
if ( V_20 -> V_35 -> V_10 == V_10 ) {
if ( V_20 -> V_22 ) {
F_23 ( V_10 ) ;
F_42 ( V_20 -> V_22 ) ;
}
F_43 ( & V_20 -> V_20 ) ;
if ( V_14 [ type ] . V_47 . V_13 )
F_11 ( V_10 , 0 , & V_14 [ type ] . V_47 ) ;
F_37 ( V_20 -> V_35 ) ;
F_38 ( V_20 -> V_35 ) ;
F_44 ( & V_20 -> V_52 ) ;
F_39 ( V_20 ) ;
}
}
F_36 ( & V_51 ) ;
}
static int T_2 F_45 ( void )
{
if ( type < 0 ) {
F_46 ( L_11 ) ;
return - V_55 ;
}
if ( type >= F_47 ( V_14 ) ) {
F_46 ( L_12 , type ) ;
return - V_55 ;
}
return F_48 ( & V_56 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_56 ) ;
}
