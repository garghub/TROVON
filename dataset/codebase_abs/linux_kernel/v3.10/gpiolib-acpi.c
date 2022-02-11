static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
int F_3 ( char * V_5 , int V_6 )
{
struct V_1 * V_7 ;
T_1 V_8 ;
T_2 V_9 ;
V_9 = F_4 ( NULL , V_5 , & V_8 ) ;
if ( F_5 ( V_9 ) )
return - V_10 ;
V_7 = F_6 ( V_8 , F_1 ) ;
if ( ! V_7 )
return - V_10 ;
if ( ! F_7 ( V_7 -> V_11 + V_6 ) )
return - V_12 ;
return V_7 -> V_11 + V_6 ;
}
static T_3 F_8 ( int V_13 , void * V_3 )
{
T_1 V_8 = V_3 ;
F_9 ( V_8 , NULL , NULL , NULL ) ;
return V_14 ;
}
static T_3 F_10 ( int V_13 , void * V_3 )
{
struct V_15 * V_16 = V_3 ;
struct V_17 args ;
union V_18 V_19 ;
V_19 . type = V_20 ;
V_19 . integer . V_21 = V_16 -> V_6 ;
args . V_22 = 1 ;
args . V_23 = & V_19 ;
F_9 ( V_16 -> V_24 , NULL , & args , NULL ) ;
return V_14 ;
}
static void F_11 ( T_1 V_8 , void * V_3 )
{
}
void F_12 ( struct V_1 * V_7 )
{
struct V_25 V_26 = { V_27 , NULL } ;
struct V_28 * V_29 ;
T_1 V_8 , V_24 ;
struct V_30 * V_31 = NULL ;
T_2 V_9 ;
unsigned int V_6 ;
int V_13 , V_32 ;
char V_33 [ 5 ] ;
if ( ! V_7 -> V_4 || ! V_7 -> V_34 )
return;
V_8 = F_2 ( V_7 -> V_4 ) ;
if ( ! V_8 )
return;
V_9 = F_13 ( V_8 , & V_26 ) ;
if ( F_5 ( V_9 ) )
return;
V_9 = F_4 ( V_8 , L_1 , & V_24 ) ;
if ( F_14 ( V_9 ) ) {
V_31 = F_15 ( sizeof( * V_31 ) , V_35 ) ;
if ( V_31 ) {
F_16 ( V_31 ) ;
V_9 = F_17 ( V_8 , F_11 ,
V_31 ) ;
if ( F_5 ( V_9 ) ) {
F_18 ( V_31 ) ;
V_31 = NULL ;
}
}
}
for ( V_29 = V_26 . V_23 ;
V_29 && ( V_29 -> type != V_36 ) ;
V_29 = F_19 ( V_29 ) ) {
T_4 V_37 = NULL ;
void * V_3 ;
if ( V_29 -> type != V_38 ||
V_29 -> V_3 . V_39 . V_40 !=
V_41 )
continue;
V_6 = V_29 -> V_3 . V_39 . V_42 [ 0 ] ;
if ( V_6 > V_7 -> V_43 )
continue;
V_13 = V_7 -> V_34 ( V_7 , V_6 ) ;
if ( V_13 < 0 )
continue;
if ( V_6 <= 255 ) {
T_1 V_44 ;
sprintf ( V_33 , L_2 ,
V_29 -> V_3 . V_39 . V_45 ? 'E' : 'L' , V_6 ) ;
V_9 = F_4 ( V_8 , V_33 , & V_44 ) ;
if ( F_14 ( V_9 ) ) {
V_37 = F_8 ;
V_3 = V_44 ;
}
}
if ( ! V_37 && V_31 ) {
struct V_15 * V_16 ;
V_16 = F_15 ( sizeof( * V_16 ) , V_35 ) ;
if ( ! V_16 )
continue;
F_20 ( & V_16 -> V_46 , V_31 ) ;
V_16 -> V_24 = V_24 ;
V_16 -> V_6 = V_6 ;
V_16 -> V_13 = V_13 ;
V_37 = F_10 ;
V_3 = V_16 ;
}
if ( ! V_37 )
continue;
V_32 = F_21 ( V_7 -> V_4 , V_13 , NULL , V_37 ,
0 , L_3 ,
V_3 ) ;
if ( V_32 )
F_22 ( V_7 -> V_4 ,
L_4 ,
V_13 ) ;
}
}
static int F_23 ( struct V_28 * V_47 , void * V_3 )
{
struct V_48 * V_49 = V_3 ;
if ( V_47 -> type != V_38 )
return 1 ;
if ( V_49 -> V_50 ++ == V_49 -> V_51 && V_49 -> V_39 < 0 ) {
const struct V_52 * V_53 = & V_47 -> V_3 . V_39 ;
V_49 -> V_39 = F_3 ( V_53 -> V_54 . V_55 ,
V_53 -> V_42 [ 0 ] ) ;
V_49 -> V_56 . V_57 =
V_53 -> V_40 == V_41 ;
}
return 1 ;
}
int F_24 ( struct V_58 * V_4 , int V_51 ,
struct V_59 * V_56 )
{
struct V_48 V_49 ;
struct V_30 V_60 ;
struct V_61 * V_62 ;
T_1 V_8 ;
int V_32 ;
if ( ! V_4 )
return - V_12 ;
V_8 = F_2 ( V_4 ) ;
if ( ! V_8 || F_25 ( V_8 , & V_62 ) )
return - V_10 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_51 = V_51 ;
V_49 . V_39 = - V_10 ;
F_16 ( & V_60 ) ;
V_32 = F_26 ( V_62 , & V_60 , F_23 ,
& V_49 ) ;
if ( V_32 < 0 )
return V_32 ;
F_27 ( & V_60 ) ;
if ( V_49 . V_39 >= 0 && V_56 )
* V_56 = V_49 . V_56 ;
return V_49 . V_39 ;
}
void F_28 ( struct V_1 * V_7 )
{
T_1 V_8 ;
T_2 V_9 ;
struct V_30 * V_31 ;
struct V_15 * V_16 , * V_63 ;
if ( ! V_7 -> V_4 || ! V_7 -> V_34 )
return;
V_8 = F_2 ( V_7 -> V_4 ) ;
if ( ! V_8 )
return;
V_9 = F_29 ( V_8 , F_11 , ( void * * ) & V_31 ) ;
if ( F_5 ( V_9 ) )
return;
F_30 (evt_pin, ep, evt_pins, node) {
F_31 ( V_7 -> V_4 , V_16 -> V_13 , V_16 ) ;
F_32 ( & V_16 -> V_46 ) ;
F_18 ( V_16 ) ;
}
F_33 ( V_8 , F_11 ) ;
F_18 ( V_31 ) ;
}
