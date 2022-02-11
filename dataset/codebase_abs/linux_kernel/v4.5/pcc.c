static struct V_1 * F_1 ( int V_2 )
{
if ( V_2 < 0 || V_2 > V_3 . V_4 )
return F_2 ( - V_5 ) ;
return & V_6 [ V_2 ] ;
}
struct V_1 * F_3 ( struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 = V_3 . V_11 ;
struct V_1 * V_12 ;
unsigned long V_13 ;
V_12 = F_1 ( V_9 ) ;
if ( F_4 ( V_12 ) || V_12 -> V_8 ) {
F_5 ( V_11 , L_1 , V_9 ) ;
return F_2 ( - V_14 ) ;
}
F_6 ( & V_12 -> V_15 , V_13 ) ;
V_12 -> V_16 = 0 ;
V_12 -> V_17 = 0 ;
V_12 -> V_18 = NULL ;
V_12 -> V_8 = V_8 ;
F_7 ( & V_12 -> V_19 ) ;
if ( V_12 -> V_20 == V_21 && V_8 -> V_22 )
V_12 -> V_20 |= V_23 ;
F_8 ( & V_12 -> V_15 , V_13 ) ;
return V_12 ;
}
void F_9 ( struct V_1 * V_12 )
{
unsigned long V_13 ;
if ( ! V_12 || ! V_12 -> V_8 )
return;
F_6 ( & V_12 -> V_15 , V_13 ) ;
V_12 -> V_8 = NULL ;
V_12 -> V_18 = NULL ;
if ( V_12 -> V_20 == ( V_21 | V_23 ) )
V_12 -> V_20 = V_21 ;
F_8 ( & V_12 -> V_15 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_12 , void * V_24 )
{
struct V_25 * V_26 = V_12 -> V_27 ;
struct V_28 V_29 ;
T_1 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
V_29 = V_26 -> V_33 ;
V_30 = V_26 -> V_34 ;
V_32 = V_26 -> V_35 ;
F_11 ( & V_31 , & V_29 ) ;
F_12 ( ( V_31 & V_30 ) | V_32 ,
& V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 ,
const unsigned long V_38 )
{
struct V_25 * V_26 ;
if ( V_3 . V_4 <= V_39 ) {
V_26 = (struct V_25 * ) V_37 ;
if ( V_26 -> V_37 . type !=
V_40 ) {
F_14 ( L_2 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int T_2 F_15 ( void )
{
T_3 V_42 ;
struct V_43 * V_44 ;
struct V_36 * V_45 ;
int V_46 , V_47 ;
T_4 V_48 = V_49 ;
V_48 = F_16 ( V_50 , 0 ,
& V_44 ,
& V_42 ) ;
if ( F_17 ( V_48 ) || ! V_44 ) {
F_18 ( L_3 ) ;
return - V_51 ;
}
V_46 = F_19 ( V_50 ,
sizeof( struct V_52 ) ,
V_40 ,
F_13 , V_39 ) ;
if ( V_46 <= 0 ) {
F_14 ( L_4 ) ;
return - V_41 ;
}
V_6 = F_20 ( sizeof( struct V_1 ) *
V_46 , V_53 ) ;
if ( ! V_6 ) {
F_14 ( L_5 ) ;
return - V_54 ;
}
V_45 = (struct V_36 * ) (
( unsigned long ) V_44 + sizeof( struct V_52 ) ) ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
V_6 [ V_47 ] . V_27 = V_45 ;
V_45 = (struct V_36 * )
( ( unsigned long ) V_45 + V_45 -> V_55 ) ;
}
V_3 . V_4 = V_46 ;
F_21 ( L_6 , V_3 . V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_56 * V_57 )
{
int V_58 = 0 ;
V_3 . V_59 = V_6 ;
V_3 . V_60 = & V_61 ;
V_3 . V_11 = & V_57 -> V_11 ;
F_21 ( L_7 ) ;
V_58 = F_23 ( & V_3 ) ;
if ( V_58 ) {
F_14 ( L_8 , V_58 ) ;
V_58 = - V_51 ;
}
return V_58 ;
}
static int T_2 F_24 ( void )
{
int V_58 ;
struct V_56 * V_62 ;
if ( V_63 )
return - V_51 ;
V_58 = F_15 () ;
if ( V_58 ) {
F_25 ( L_9 ) ;
return - V_51 ;
}
V_62 = F_26 ( & V_64 ,
F_22 , NULL , 0 , NULL , 0 ) ;
if ( F_4 ( V_62 ) ) {
F_25 ( L_10 ) ;
return F_27 ( V_62 ) ;
}
return 0 ;
}
