static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
static struct V_5 * F_3 ( char * V_6 , int V_7 )
{
struct V_1 * V_8 ;
T_1 V_9 ;
T_2 V_10 ;
V_10 = F_4 ( NULL , V_6 , & V_9 ) ;
if ( F_5 ( V_10 ) )
return F_6 ( - V_11 ) ;
V_8 = F_7 ( V_9 , F_1 ) ;
if ( ! V_8 )
return F_6 ( - V_11 ) ;
if ( V_7 < 0 || V_7 > V_8 -> V_12 )
return F_6 ( - V_13 ) ;
return F_8 ( V_8 -> V_14 + V_7 ) ;
}
static T_3 F_9 ( int V_15 , void * V_3 )
{
T_1 V_9 = V_3 ;
F_10 ( V_9 , NULL , NULL , NULL ) ;
return V_16 ;
}
static T_3 F_11 ( int V_15 , void * V_3 )
{
struct V_17 * V_18 = V_3 ;
F_12 ( V_18 -> V_19 , NULL , V_18 -> V_7 ) ;
return V_16 ;
}
static void F_13 ( T_1 V_9 , void * V_3 )
{
}
static void F_14 ( struct V_1 * V_8 )
{
struct V_20 V_21 = { V_22 , NULL } ;
struct V_23 * V_24 ;
T_1 V_9 , V_19 ;
struct V_25 * V_26 = NULL ;
T_2 V_10 ;
unsigned int V_7 ;
int V_15 , V_27 ;
char V_28 [ 5 ] ;
if ( ! V_8 -> V_4 || ! V_8 -> V_29 )
return;
V_9 = F_2 ( V_8 -> V_4 ) ;
if ( ! V_9 )
return;
V_10 = F_15 ( V_9 , & V_21 ) ;
if ( F_5 ( V_10 ) )
return;
V_10 = F_4 ( V_9 , L_1 , & V_19 ) ;
if ( F_16 ( V_10 ) ) {
V_26 = F_17 ( sizeof( * V_26 ) , V_30 ) ;
if ( V_26 ) {
F_18 ( V_26 ) ;
V_10 = F_19 ( V_9 , F_13 ,
V_26 ) ;
if ( F_5 ( V_10 ) ) {
F_20 ( V_26 ) ;
V_26 = NULL ;
}
}
}
for ( V_24 = V_21 . V_31 ;
V_24 && ( V_24 -> type != V_32 ) ;
V_24 = F_21 ( V_24 ) ) {
T_4 V_33 = NULL ;
void * V_3 ;
if ( V_24 -> type != V_34 ||
V_24 -> V_3 . V_35 . V_36 !=
V_37 )
continue;
V_7 = V_24 -> V_3 . V_35 . V_38 [ 0 ] ;
if ( V_7 > V_8 -> V_12 )
continue;
V_15 = V_8 -> V_29 ( V_8 , V_7 ) ;
if ( V_15 < 0 )
continue;
if ( V_7 <= 255 ) {
T_1 V_39 ;
sprintf ( V_28 , L_2 ,
V_24 -> V_3 . V_35 . V_40 ? 'E' : 'L' , V_7 ) ;
V_10 = F_4 ( V_9 , V_28 , & V_39 ) ;
if ( F_16 ( V_10 ) ) {
V_33 = F_9 ;
V_3 = V_39 ;
}
}
if ( ! V_33 && V_26 ) {
struct V_17 * V_18 ;
V_18 = F_17 ( sizeof( * V_18 ) , V_30 ) ;
if ( ! V_18 )
continue;
F_22 ( & V_18 -> V_41 , V_26 ) ;
V_18 -> V_19 = V_19 ;
V_18 -> V_7 = V_7 ;
V_18 -> V_15 = V_15 ;
V_33 = F_11 ;
V_3 = V_18 ;
}
if ( ! V_33 )
continue;
V_27 = F_23 ( V_8 -> V_4 , V_15 , NULL , V_33 ,
0 , L_3 ,
V_3 ) ;
if ( V_27 )
F_24 ( V_8 -> V_4 ,
L_4 ,
V_15 ) ;
}
}
static void F_25 ( struct V_1 * V_8 )
{
T_1 V_9 ;
T_2 V_10 ;
struct V_25 * V_26 ;
struct V_17 * V_18 , * V_42 ;
if ( ! V_8 -> V_4 || ! V_8 -> V_29 )
return;
V_9 = F_2 ( V_8 -> V_4 ) ;
if ( ! V_9 )
return;
V_10 = F_26 ( V_9 , F_13 , ( void * * ) & V_26 ) ;
if ( F_5 ( V_10 ) )
return;
F_27 (evt_pin, ep, evt_pins, node) {
F_28 ( V_8 -> V_4 , V_18 -> V_15 , V_18 ) ;
F_29 ( & V_18 -> V_41 ) ;
F_20 ( V_18 ) ;
}
F_30 ( V_9 , F_13 ) ;
F_20 ( V_26 ) ;
}
static int F_31 ( struct V_23 * V_43 , void * V_3 )
{
struct V_44 * V_45 = V_3 ;
if ( V_43 -> type != V_34 )
return 1 ;
if ( V_45 -> V_46 ++ == V_45 -> V_47 && ! V_45 -> V_48 ) {
const struct V_49 * V_50 = & V_43 -> V_3 . V_35 ;
V_45 -> V_48 = F_3 ( V_50 -> V_51 . V_52 ,
V_50 -> V_38 [ 0 ] ) ;
V_45 -> V_53 . V_54 =
V_50 -> V_36 == V_37 ;
V_45 -> V_53 . V_55 =
V_50 -> V_56 == V_57 ;
}
return 1 ;
}
struct V_5 * F_32 ( struct V_58 * V_4 , int V_47 ,
struct V_59 * V_53 )
{
struct V_44 V_45 ;
struct V_25 V_60 ;
struct V_61 * V_62 ;
T_1 V_9 ;
int V_27 ;
if ( ! V_4 )
return F_6 ( - V_13 ) ;
V_9 = F_2 ( V_4 ) ;
if ( ! V_9 || F_33 ( V_9 , & V_62 ) )
return F_6 ( - V_11 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_47 = V_47 ;
F_18 ( & V_60 ) ;
V_27 = F_34 ( V_62 , & V_60 , F_31 ,
& V_45 ) ;
if ( V_27 < 0 )
return F_6 ( V_27 ) ;
F_35 ( & V_60 ) ;
if ( V_45 . V_48 && V_53 )
* V_53 = V_45 . V_53 ;
return V_45 . V_48 ? V_45 . V_48 : F_6 ( - V_63 ) ;
}
void F_36 ( struct V_1 * V_8 )
{
F_14 ( V_8 ) ;
}
void F_37 ( struct V_1 * V_8 )
{
F_25 ( V_8 ) ;
}
