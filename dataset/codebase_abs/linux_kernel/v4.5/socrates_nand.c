static void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
F_4 ( V_9 -> V_10 , V_11 |
V_12 |
( V_3 [ V_5 ] << V_13 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_2 V_14 ;
V_14 = V_11 | V_15 ;
F_4 ( V_9 -> V_10 , V_14 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
V_3 [ V_5 ] = ( F_6 ( V_9 -> V_10 ) >>
V_13 ) & 0xff ;
}
}
static T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_16 ;
F_5 ( V_2 , & V_16 , sizeof( V_16 ) ) ;
return V_16 ;
}
static T_3 F_8 ( struct V_1 * V_2 )
{
T_3 V_17 ;
F_5 ( V_2 , ( T_1 * ) & V_17 , sizeof( V_17 ) ) ;
return V_17 ;
}
static void F_9 ( struct V_1 * V_2 , int V_18 ,
unsigned int V_19 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_14 ;
if ( V_18 == V_20 )
return;
if ( V_19 & V_21 )
V_14 = V_22 ;
else
V_14 = V_23 ;
if ( V_19 & V_24 )
V_14 |= V_11 ;
V_14 |= ( V_18 & 0xff ) << V_13 ;
F_4 ( V_9 -> V_10 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
if ( F_6 ( V_9 -> V_10 ) & V_25 )
return 0 ;
return 1 ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_6 * V_6 ;
int V_28 ;
V_9 = F_12 ( & V_27 -> V_29 , sizeof( * V_9 ) , V_30 ) ;
if ( ! V_9 )
return - V_31 ;
V_9 -> V_10 = F_13 ( V_27 -> V_29 . V_32 , 0 ) ;
if ( V_9 -> V_10 == NULL ) {
F_14 ( & V_27 -> V_29 , L_1 ) ;
return - V_33 ;
}
V_6 = & V_9 -> V_6 ;
V_2 = F_15 ( V_6 ) ;
V_9 -> V_29 = & V_27 -> V_29 ;
F_16 ( V_6 , V_9 ) ;
F_17 ( V_6 , V_27 -> V_29 . V_32 ) ;
V_2 -> V_34 = L_2 ;
V_2 -> V_29 . V_35 = & V_27 -> V_29 ;
V_6 -> V_36 = ( void * ) 0xdeadbeef ;
V_6 -> V_37 = ( void * ) 0xdeadbeef ;
V_6 -> V_38 = F_9 ;
V_6 -> V_39 = F_7 ;
V_6 -> V_40 = F_8 ;
V_6 -> V_41 = F_1 ;
V_6 -> V_42 = F_5 ;
V_6 -> V_43 = F_10 ;
V_6 -> V_44 . V_45 = V_46 ;
V_6 -> V_47 = 20 ;
F_18 ( & V_27 -> V_29 , V_9 ) ;
if ( F_19 ( V_2 , 1 , NULL ) ) {
V_28 = - V_48 ;
goto V_49;
}
if ( F_20 ( V_2 ) ) {
V_28 = - V_48 ;
goto V_49;
}
V_28 = F_21 ( V_2 , NULL , 0 ) ;
if ( ! V_28 )
return V_28 ;
F_22 ( V_2 ) ;
V_49:
F_23 ( V_9 -> V_10 ) ;
return V_28 ;
}
static int F_24 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = F_25 ( & V_27 -> V_29 ) ;
struct V_1 * V_2 = F_15 ( & V_9 -> V_6 ) ;
F_22 ( V_2 ) ;
F_23 ( V_9 -> V_10 ) ;
return 0 ;
}
