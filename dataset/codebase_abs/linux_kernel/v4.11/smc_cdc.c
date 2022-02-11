static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 ;
int V_11 ;
if ( ! V_8 -> V_12 )
return;
V_10 = F_2 ( V_8 -> V_12 , struct V_9 , V_12 ) ;
F_3 ( & V_10 -> V_13 ) ;
if ( ! V_6 ) {
V_11 = F_4 ( V_8 -> V_12 -> V_14 ,
& V_8 -> V_12 -> V_15 ,
& V_8 -> V_16 ) ;
F_5 () ;
F_6 ( V_11 , & V_8 -> V_12 -> V_17 ) ;
F_7 () ;
F_8 ( & V_8 -> V_12 -> V_15 ,
F_9 ( & V_8 -> V_16 , V_8 -> V_12 ) ,
V_8 -> V_12 ) ;
}
F_10 ( V_10 ) ;
if ( V_10 -> V_13 . V_18 != V_19 )
V_10 -> V_13 . V_20 ( & V_10 -> V_13 ) ;
F_11 ( & V_10 -> V_13 ) ;
}
int F_12 ( struct V_3 * V_4 ,
struct V_21 * * V_22 ,
struct V_7 * * V_23 )
{
return F_13 ( V_4 , F_1 , V_22 ,
(struct V_1 * * ) V_23 ) ;
}
static inline void F_14 ( struct V_24 * V_12 ,
struct V_7 * V_23 )
{
F_15 (
sizeof( struct V_25 ) > V_26 ,
L_1 ) ;
F_15 (
F_16 ( struct V_25 , V_27 ) > V_28 ,
L_2 ) ;
F_15 (
sizeof( struct V_7 ) > V_29 ,
L_3 ) ;
V_23 -> V_12 = V_12 ;
V_23 -> V_16 = V_12 -> V_30 ;
V_23 -> V_31 = V_12 -> V_32 . V_33 ;
V_23 -> V_34 = V_12 -> V_35 ;
}
int F_17 ( struct V_24 * V_12 ,
struct V_21 * V_22 ,
struct V_7 * V_23 )
{
struct V_3 * V_4 ;
int V_36 ;
V_4 = & V_12 -> V_37 -> V_38 [ V_39 ] ;
F_14 ( V_12 , V_23 ) ;
V_12 -> V_35 ++ ;
V_12 -> V_32 . V_40 = V_12 -> V_35 ;
F_18 ( (struct V_25 * ) V_22 ,
& V_12 -> V_32 , V_12 ) ;
V_36 = F_19 ( V_4 , (struct V_1 * ) V_23 ) ;
if ( ! V_36 )
F_8 ( & V_12 -> V_41 ,
F_9 ( & V_12 -> V_32 . V_42 , V_12 ) ,
V_12 ) ;
return V_36 ;
}
int F_20 ( struct V_24 * V_12 )
{
struct V_7 * V_23 ;
struct V_21 * V_22 ;
int V_36 ;
V_36 = F_12 ( & V_12 -> V_37 -> V_38 [ V_39 ] , & V_22 ,
& V_23 ) ;
if ( V_36 )
return V_36 ;
return F_17 ( V_12 , V_22 , V_23 ) ;
}
static bool F_21 ( struct V_1 * V_43 ,
unsigned long V_44 )
{
struct V_24 * V_12 = (struct V_24 * ) V_44 ;
struct V_7 * V_45 =
(struct V_7 * ) V_43 ;
return V_45 -> V_12 == V_12 ;
}
static void F_22 ( struct V_1 * V_43 )
{
struct V_7 * V_45 =
(struct V_7 * ) V_43 ;
V_45 -> V_12 = NULL ;
}
void F_23 ( struct V_24 * V_12 )
{
struct V_3 * V_4 = & V_12 -> V_37 -> V_38 [ V_39 ] ;
F_24 ( V_4 , V_46 ,
F_21 , F_22 ,
( unsigned long ) V_12 ) ;
}
bool F_25 ( struct V_24 * V_12 )
{
struct V_3 * V_4 = & V_12 -> V_37 -> V_38 [ V_39 ] ;
return F_26 ( V_4 , V_46 ,
F_21 , ( unsigned long ) V_12 ) ;
}
static inline bool F_27 ( T_1 V_47 , T_1 V_48 )
{
return ( V_49 ) ( V_47 - V_48 ) < 0 ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
struct V_25 * V_50 )
{
union V_51 V_52 , V_53 ;
struct V_24 * V_12 = & V_10 -> V_12 ;
int V_54 , V_55 ;
if ( ! V_50 -> V_56 . V_57 ) {
if ( F_27 ( F_29 ( V_50 -> V_40 ) ,
V_12 -> V_58 . V_40 ) )
return;
}
F_8 ( & V_53 ,
F_9 ( & V_12 -> V_58 . V_33 , V_12 ) ,
V_12 ) ;
F_8 ( & V_52 ,
F_9 ( & V_12 -> V_58 . V_42 , V_12 ) ,
V_12 ) ;
F_30 ( & V_12 -> V_58 , V_50 , V_12 ) ;
V_54 = F_4 ( V_12 -> V_59 , & V_52 ,
& V_12 -> V_58 . V_42 ) ;
if ( V_54 ) {
F_5 () ;
F_6 ( V_54 , & V_12 -> V_60 ) ;
F_7 () ;
}
V_55 = F_4 ( V_12 -> V_61 , & V_53 ,
& V_12 -> V_58 . V_33 ) ;
if ( V_55 ) {
F_5 () ;
F_6 ( V_55 , & V_12 -> V_62 ) ;
F_7 () ;
V_10 -> V_13 . V_63 ( & V_10 -> V_13 ) ;
}
if ( V_12 -> V_58 . V_64 . V_65 ) {
V_10 -> V_13 . V_66 = V_67 ;
V_12 -> V_32 . V_64 . V_65 = 1 ;
}
if ( F_31 ( V_12 ) )
F_32 ( V_10 ) ;
if ( V_54 && F_33 ( V_12 ) ) {
F_34 ( V_12 ) ;
F_35 ( V_10 ) ;
}
if ( ! V_10 -> V_13 . V_68 )
return;
if ( ( V_12 -> V_58 . V_56 . V_69 ) ||
( V_12 -> V_58 . V_56 . V_70 ) )
F_36 ( V_12 ) ;
}
static inline void F_37 ( struct V_25 * V_50 ,
struct V_3 * V_4 , T_2 V_71 )
{
struct V_72 * V_37 = F_2 ( V_4 , struct V_72 ,
V_38 [ V_39 ] ) ;
struct V_24 * V_73 ;
struct V_9 * V_10 ;
F_38 ( & V_37 -> V_74 ) ;
V_73 = F_39 ( F_40 ( V_50 -> V_75 ) , V_37 ) ;
if ( ! V_73 ) {
F_41 ( & V_37 -> V_74 ) ;
return;
}
V_10 = F_2 ( V_73 , struct V_9 , V_12 ) ;
F_42 ( & V_10 -> V_13 ) ;
F_41 ( & V_37 -> V_74 ) ;
F_3 ( & V_10 -> V_13 ) ;
F_28 ( V_10 , V_4 , V_50 ) ;
F_11 ( & V_10 -> V_13 ) ;
F_43 ( & V_10 -> V_13 ) ;
}
static void F_44 ( struct V_76 * V_77 , void * V_78 )
{
struct V_3 * V_4 = (struct V_3 * ) V_77 -> V_79 -> V_80 ;
struct V_25 * V_50 = V_78 ;
if ( V_77 -> V_81 < F_16 ( struct V_25 , V_27 ) )
return;
if ( V_50 -> V_82 != sizeof( * V_50 ) )
return;
F_37 ( V_50 , V_4 , V_77 -> V_71 ) ;
}
int T_3 F_45 ( void )
{
struct V_83 * V_84 ;
int V_36 = 0 ;
for ( V_84 = V_85 ; V_84 -> V_84 ; V_84 ++ ) {
F_46 ( & V_84 -> V_86 ) ;
V_36 = F_47 ( V_84 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
