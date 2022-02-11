static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
if ( V_2 < 0 || V_2 > V_4 . V_5 )
return F_2 ( - V_6 ) ;
V_3 = (struct V_1 * )
( unsigned long ) V_7 +
( V_2 * sizeof( * V_3 ) ) ;
return V_3 ;
}
struct V_1 * F_3 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_11 * V_12 = V_4 . V_12 ;
struct V_1 * V_13 ;
unsigned long V_14 ;
V_13 = F_1 ( V_10 ) ;
if ( ! V_13 || V_13 -> V_9 ) {
F_4 ( V_12 , L_1 , V_10 ) ;
return F_2 ( - V_15 ) ;
}
F_5 ( & V_13 -> V_16 , V_14 ) ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 = 0 ;
V_13 -> V_19 = NULL ;
V_13 -> V_9 = V_9 ;
F_6 ( & V_13 -> V_20 ) ;
if ( V_13 -> V_21 == V_22 && V_9 -> V_23 )
V_13 -> V_21 |= V_24 ;
F_7 ( & V_13 -> V_16 , V_14 ) ;
return V_13 ;
}
void F_8 ( struct V_1 * V_13 )
{
unsigned long V_14 ;
if ( ! V_13 || ! V_13 -> V_9 )
return;
F_5 ( & V_13 -> V_16 , V_14 ) ;
V_13 -> V_9 = NULL ;
V_13 -> V_19 = NULL ;
if ( V_13 -> V_21 == ( V_22 | V_24 ) )
V_13 -> V_21 = V_22 ;
F_7 ( & V_13 -> V_16 , V_14 ) ;
}
static int F_9 ( struct V_1 * V_13 , void * V_25 )
{
struct V_26 * V_27 = V_13 -> V_28 ;
struct V_29 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
V_30 = V_27 -> V_34 ;
V_31 = V_27 -> V_35 ;
V_33 = V_27 -> V_36 ;
F_10 ( & V_32 , & V_30 ) ;
F_11 ( ( V_32 & V_31 ) | V_33 ,
& V_30 ) ;
return 0 ;
}
static int F_12 ( struct V_37 * V_38 ,
const unsigned long V_39 )
{
struct V_26 * V_27 ;
if ( V_4 . V_5 <= V_40 ) {
V_27 = (struct V_26 * ) V_38 ;
if ( V_27 -> V_38 . type !=
V_41 ) {
F_13 ( L_2 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int T_2 F_14 ( void )
{
T_3 V_43 ;
struct V_44 * V_45 ;
struct V_37 * V_46 ;
int V_47 , V_48 ;
T_4 V_49 = V_50 ;
V_49 = F_15 ( V_51 , 0 ,
& V_45 ,
& V_43 ) ;
if ( F_16 ( V_49 ) || ! V_45 ) {
F_17 ( L_3 ) ;
return - V_52 ;
}
V_47 = F_18 ( V_51 ,
sizeof( struct V_53 ) ,
V_41 ,
F_12 , V_40 ) ;
if ( V_47 <= 0 ) {
F_13 ( L_4 ) ;
return - V_42 ;
}
V_7 = F_19 ( sizeof( struct V_1 ) *
V_47 , V_54 ) ;
if ( ! V_7 ) {
F_13 ( L_5 ) ;
return - V_55 ;
}
V_46 = (struct V_37 * ) (
( unsigned long ) V_45 + sizeof( struct V_53 ) ) ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
V_7 [ V_48 ] . V_28 = V_46 ;
V_46 = (struct V_37 * )
( ( unsigned long ) V_46 + V_46 -> V_56 ) ;
}
V_4 . V_5 = V_47 ;
F_20 ( L_6 , V_4 . V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 )
{
int V_59 = 0 ;
V_4 . V_60 = V_7 ;
V_4 . V_61 = & V_62 ;
V_4 . V_12 = & V_58 -> V_12 ;
F_20 ( L_7 ) ;
V_59 = F_22 ( & V_4 ) ;
if ( V_59 ) {
F_13 ( L_8 , V_59 ) ;
V_59 = - V_52 ;
}
return V_59 ;
}
static int T_2 F_23 ( void )
{
int V_59 ;
struct V_57 * V_63 ;
if ( V_64 )
return - V_52 ;
V_59 = F_14 () ;
if ( V_59 ) {
F_24 ( L_9 ) ;
return - V_52 ;
}
V_63 = F_25 ( & V_65 ,
F_21 , NULL , 0 , NULL , 0 ) ;
if ( F_26 ( V_63 ) ) {
F_24 ( L_10 ) ;
return F_27 ( V_63 ) ;
}
return 0 ;
}
