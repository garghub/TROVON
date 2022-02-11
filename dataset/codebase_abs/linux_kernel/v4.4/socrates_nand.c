static void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_8 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
F_2 ( V_10 -> V_11 , V_12 |
V_13 |
( V_3 [ V_5 ] << V_14 ) ) ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_8 ;
T_2 V_15 ;
V_15 = V_12 | V_16 ;
F_2 ( V_10 -> V_11 , V_15 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
V_3 [ V_5 ] = ( F_4 ( V_10 -> V_11 ) >>
V_14 ) & 0xff ;
}
}
static T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_17 ;
F_3 ( V_2 , & V_17 , sizeof( V_17 ) ) ;
return V_17 ;
}
static T_3 F_6 ( struct V_1 * V_2 )
{
T_3 V_18 ;
F_3 ( V_2 , ( T_1 * ) & V_18 , sizeof( V_18 ) ) ;
return V_18 ;
}
static void F_7 ( struct V_1 * V_2 , int V_19 ,
unsigned int V_20 )
{
struct V_6 * V_6 = V_2 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_8 ;
T_2 V_15 ;
if ( V_19 == V_21 )
return;
if ( V_20 & V_22 )
V_15 = V_23 ;
else
V_15 = V_24 ;
if ( V_20 & V_25 )
V_15 |= V_12 ;
V_15 |= ( V_19 & 0xff ) << V_14 ;
F_2 ( V_10 -> V_11 , V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_8 ;
if ( F_4 ( V_10 -> V_11 ) & V_26 )
return 0 ;
return 1 ;
}
static int F_9 ( struct V_27 * V_28 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_6 * V_6 ;
int V_29 ;
struct V_30 V_31 ;
V_10 = F_10 ( & V_28 -> V_32 , sizeof( * V_10 ) , V_33 ) ;
if ( ! V_10 )
return - V_34 ;
V_10 -> V_11 = F_11 ( V_28 -> V_32 . V_35 , 0 ) ;
if ( V_10 -> V_11 == NULL ) {
F_12 ( & V_28 -> V_32 , L_1 ) ;
return - V_36 ;
}
V_2 = & V_10 -> V_2 ;
V_6 = & V_10 -> V_6 ;
V_10 -> V_32 = & V_28 -> V_32 ;
V_6 -> V_8 = V_10 ;
V_2 -> V_8 = V_6 ;
V_2 -> V_37 = L_2 ;
V_2 -> V_32 . V_38 = & V_28 -> V_32 ;
V_31 . V_35 = V_28 -> V_32 . V_35 ;
V_6 -> V_39 = ( void * ) 0xdeadbeef ;
V_6 -> V_40 = ( void * ) 0xdeadbeef ;
V_6 -> V_41 = F_7 ;
V_6 -> V_42 = F_5 ;
V_6 -> V_43 = F_6 ;
V_6 -> V_44 = F_1 ;
V_6 -> V_45 = F_3 ;
V_6 -> V_46 = F_8 ;
V_6 -> V_47 . V_48 = V_49 ;
V_6 -> V_50 = 20 ;
F_13 ( & V_28 -> V_32 , V_10 ) ;
if ( F_14 ( V_2 , 1 , NULL ) ) {
V_29 = - V_51 ;
goto V_52;
}
if ( F_15 ( V_2 ) ) {
V_29 = - V_51 ;
goto V_52;
}
V_29 = F_16 ( V_2 , NULL , & V_31 , NULL , 0 ) ;
if ( ! V_29 )
return V_29 ;
F_17 ( V_2 ) ;
V_52:
F_18 ( V_10 -> V_11 ) ;
return V_29 ;
}
static int F_19 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_20 ( & V_28 -> V_32 ) ;
struct V_1 * V_2 = & V_10 -> V_2 ;
F_17 ( V_2 ) ;
F_18 ( V_10 -> V_11 ) ;
return 0 ;
}
