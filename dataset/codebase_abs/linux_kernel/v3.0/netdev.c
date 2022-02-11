static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
#ifdef F_6
struct V_3 * V_4 = F_7 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
F_8 ( L_1 , V_2 -> V_12 , F_9 ( V_2 ) ) ;
V_11 = sizeof( * V_8 ) + ( V_13 + 1 ) * V_14 * 2 ;
V_10 = F_10 ( V_11 , V_15 ) ;
if ( ! V_10 ) {
F_11 ( L_2 , V_2 -> V_12 ) ;
return;
}
V_8 = ( void * ) V_10 -> V_16 ;
F_12 ( V_10 , sizeof( * V_8 ) ) ;
V_8 -> type = V_17 ;
V_8 -> V_18 = V_19 ;
if ( V_2 -> V_20 & ( V_21 | V_22 ) ) {
T_1 V_23 [ V_14 ] = { 0x01 } ;
memcpy ( F_12 ( V_10 , V_14 ) , V_23 , V_14 ) ;
memcpy ( F_12 ( V_10 , V_14 ) , V_2 -> V_24 , V_14 ) ;
V_8 -> V_25 = F_13 ( V_14 * 2 ) ;
} else {
struct V_26 * V_27 ;
int V_28 , V_25 = V_10 -> V_25 ;
if ( V_2 -> V_20 & V_29 ) {
memcpy ( F_12 ( V_10 , V_14 ) , V_2 -> V_24 , V_14 ) ;
memcpy ( F_12 ( V_10 , V_14 ) , V_2 -> V_24 , V_14 ) ;
}
V_28 = 0 ;
F_14 (ha, dev) {
if ( V_28 == V_13 )
break;
memcpy ( F_12 ( V_10 , V_14 ) , V_27 -> V_30 , V_14 ) ;
memcpy ( F_12 ( V_10 , V_14 ) , V_27 -> V_30 , V_14 ) ;
V_28 ++ ;
}
V_8 -> V_25 = F_13 ( V_10 -> V_25 - V_25 ) ;
}
F_15 ( & V_6 -> V_31 , V_10 ) ;
F_16 ( F_17 ( V_6 ) ) ;
#endif
}
static int F_18 ( struct V_1 * V_2 , void * V_32 )
{
F_8 ( L_3 , V_2 -> V_12 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_8 ( L_4 ) ;
F_20 ( V_2 ) ;
}
static inline int F_21 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_33 * V_34 = ( void * ) V_10 -> V_16 ;
if ( ( V_34 -> V_35 [ 0 ] & 1 ) && ! F_22 ( F_23 ( V_34 -> V_35 ) , ( V_36 * ) & V_4 -> V_37 ) )
return 1 ;
return 0 ;
}
static inline T_2 F_24 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = ( void * ) V_10 -> V_16 ;
T_2 V_38 = F_25 ( V_34 -> V_39 ) ;
if ( V_38 >= 1536 )
return V_38 ;
if ( F_26 ( ( V_40 * ) V_10 -> V_16 ) == F_13 ( 0xFFFF ) )
return V_41 ;
return V_42 ;
}
static inline int F_27 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
T_2 V_38 = F_24 ( V_10 ) ;
struct V_43 * V_44 = V_4 -> V_45 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_46 && V_44 [ V_28 ] . V_47 ; V_28 ++ ) {
if ( V_38 >= V_44 [ V_28 ] . V_23 && V_38 <= V_44 [ V_28 ] . V_47 )
return 0 ;
}
F_8 ( L_5 , V_10 , V_38 ) ;
return 1 ;
}
static T_3 F_28 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_5 -> V_6 ;
F_8 ( L_6 , V_10 , V_2 ) ;
#ifdef F_6
if ( F_21 ( V_10 , V_4 ) ) {
F_29 ( V_10 ) ;
return V_48 ;
}
#endif
#ifdef F_30
if ( F_27 ( V_10 , V_4 ) ) {
F_29 ( V_10 ) ;
return V_48 ;
}
#endif
V_2 -> V_49 = V_50 ;
F_15 ( & V_6 -> V_31 , V_10 ) ;
F_16 ( F_17 ( V_6 ) ) ;
if ( F_31 ( & V_6 -> V_31 ) >= V_51 ) {
F_8 ( L_7 ) ;
F_4 ( V_2 ) ;
}
return V_48 ;
}
void F_32 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_24 , 0xff , V_14 ) ;
V_2 -> V_52 = V_14 ;
F_33 ( V_2 ) ;
V_2 -> V_53 = & V_54 ;
V_2 -> V_55 = V_56 * 2 ;
}
