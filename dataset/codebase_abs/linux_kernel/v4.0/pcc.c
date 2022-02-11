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
static int F_3 ( struct V_1 * V_8 )
{
unsigned int V_2 = V_8 - V_7 ;
if ( V_2 < 0 || V_2 > V_4 . V_5 )
return - V_6 ;
return V_2 ;
}
struct V_1 * F_4 ( struct V_9 * V_10 ,
int V_11 )
{
struct V_12 * V_13 = V_4 . V_13 ;
struct V_1 * V_8 ;
unsigned long V_14 ;
V_8 = F_1 ( V_11 ) ;
if ( ! V_8 || V_8 -> V_10 ) {
F_5 ( V_13 , L_1 , V_15 ) ;
return F_2 ( - V_16 ) ;
}
F_6 ( & V_8 -> V_17 , V_14 ) ;
V_8 -> V_18 = 0 ;
V_8 -> V_19 = 0 ;
V_8 -> V_20 = NULL ;
V_8 -> V_10 = V_10 ;
F_7 ( & V_8 -> V_21 ) ;
if ( V_8 -> V_22 == V_23 && V_10 -> V_24 )
V_8 -> V_22 |= V_25 ;
F_8 ( & V_8 -> V_17 , V_14 ) ;
return V_8 ;
}
void F_9 ( struct V_1 * V_8 )
{
unsigned long V_14 ;
if ( ! V_8 || ! V_8 -> V_10 )
return;
F_6 ( & V_8 -> V_17 , V_14 ) ;
V_8 -> V_10 = NULL ;
V_8 -> V_20 = NULL ;
if ( V_8 -> V_22 == ( V_23 | V_25 ) )
V_8 -> V_22 = V_23 ;
F_8 ( & V_8 -> V_17 , V_14 ) ;
}
static bool F_10 ( struct V_1 * V_8 )
{
struct V_26 * V_27 = V_8 -> V_28 ;
struct V_29 * V_30 =
(struct V_29 * ) V_27 -> V_31 ;
T_1 V_32 = V_27 -> V_33 ;
unsigned int V_34 = 0 ;
while ( ! ( F_11 ( & V_30 -> V_35 )
& V_36 ) ) {
if ( V_34 ++ < 5 )
F_12 ( V_32 ) ;
else {
F_13 ( L_2 ) ;
return false ;
}
}
return true ;
}
static int F_14 ( struct V_1 * V_8 , void * V_37 )
{
struct V_26 * V_27 = V_8 -> V_28 ;
struct V_29 * V_30 =
(struct V_29 * ) V_27 -> V_31 ;
struct V_38 V_39 ;
T_2 V_40 ;
T_2 V_41 ;
T_2 V_42 ;
T_1 V_43 = * ( T_1 * ) V_37 ;
T_1 V_44 = - 1 ;
V_44 = F_3 ( V_8 ) ;
if ( V_44 < 0 ) {
F_13 ( L_3 ) ;
return - V_45 ;
}
V_39 = V_27 -> V_46 ;
V_40 = V_27 -> V_47 ;
V_42 = V_27 -> V_48 ;
F_15 ( V_43 , & V_30 -> V_49 ) ;
F_16 ( ( V_50 | V_44 ) , & V_30 -> V_51 ) ;
F_15 ( 0 , & V_30 -> V_35 ) ;
F_17 ( & V_41 , & V_39 ) ;
F_18 ( ( V_41 & V_40 ) | V_42 ,
& V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_52 * V_53 ,
const unsigned long V_54 )
{
struct V_26 * V_27 ;
if ( V_4 . V_5 <= V_55 ) {
V_27 = (struct V_26 * ) V_53 ;
if ( V_27 -> V_53 . type !=
V_56 ) {
F_13 ( L_4 ) ;
return - V_45 ;
}
}
return 0 ;
}
static int T_3 F_20 ( void )
{
T_4 V_57 ;
struct V_58 * V_59 ;
struct V_52 * V_60 ;
int V_61 , V_62 ;
T_5 V_35 = V_63 ;
V_35 = F_21 ( V_64 , 0 ,
& V_59 ,
& V_57 ) ;
if ( F_22 ( V_35 ) || ! V_59 ) {
F_23 ( L_5 ) ;
return - V_65 ;
}
V_61 = F_24 ( V_64 ,
sizeof( struct V_66 ) ,
V_56 ,
F_19 , V_55 ) ;
if ( V_61 <= 0 ) {
F_13 ( L_6 ) ;
return - V_45 ;
}
V_7 = F_25 ( sizeof( struct V_1 ) *
V_61 , V_67 ) ;
if ( ! V_7 ) {
F_13 ( L_7 ) ;
return - V_68 ;
}
V_60 = (struct V_52 * ) (
( unsigned long ) V_59 + sizeof( struct V_66 ) ) ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_7 [ V_62 ] . V_28 = V_60 ;
V_60 = (struct V_52 * )
( ( unsigned long ) V_60 + V_60 -> V_69 ) ;
}
V_4 . V_5 = V_61 ;
F_26 ( L_8 , V_4 . V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_70 * V_71 )
{
int V_72 = 0 ;
V_4 . V_73 = V_7 ;
V_4 . V_74 = & V_75 ;
V_4 . V_76 = true ;
V_4 . V_77 = 10 ;
V_4 . V_13 = & V_71 -> V_13 ;
F_26 ( L_9 ) ;
V_72 = F_28 ( & V_4 ) ;
if ( V_72 ) {
F_13 ( L_10 , V_72 ) ;
V_72 = - V_65 ;
}
return V_72 ;
}
static int T_3 F_29 ( void )
{
int V_72 ;
struct V_70 * V_78 ;
if ( V_79 )
return - V_65 ;
V_72 = F_20 () ;
if ( V_72 ) {
F_30 ( L_11 ) ;
return - V_65 ;
}
V_78 = F_31 ( & V_80 ,
F_27 , NULL , 0 , NULL , 0 ) ;
if ( F_32 ( V_78 ) ) {
F_30 ( L_12 ) ;
return F_33 ( V_78 ) ;
}
return 0 ;
}
