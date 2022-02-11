static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_6 * V_6 = V_3 -> V_7 -> V_8 -> V_6 ;
struct V_9 * V_10 = & V_5 -> V_11 -> V_12 ;
unsigned long V_13 ;
struct V_14 V_15 ;
unsigned long V_16 ;
unsigned int V_17 ;
int div ;
V_15 . V_18 = V_10 -> V_19 - V_10 -> V_20 ;
V_15 . V_21 = V_10 -> V_22 - V_10 -> V_23 ;
V_15 . V_24 = V_10 -> V_23 - V_10 -> V_19 ;
V_15 . V_25 = V_10 -> V_26 - V_10 -> V_27 ;
V_15 . V_28 = V_10 -> V_29 - V_10 -> V_30 ;
V_15 . V_31 = V_10 -> V_30 - V_10 -> V_26 ;
F_4 ( V_6 , F_5 ( 1 ) ,
( V_15 . V_31 - 1 ) | ( ( V_15 . V_24 - 1 ) << 16 ) ) ;
F_4 ( V_6 , F_5 ( 2 ) ,
( V_15 . V_18 - 1 ) | ( V_15 . V_21 << 16 ) ) ;
F_4 ( V_6 , F_5 ( 3 ) ,
( V_15 . V_25 - 1 ) | ( ( V_15 . V_28 - 1 ) << 16 ) ) ;
F_4 ( V_6 , F_5 ( 4 ) ,
( V_10 -> V_27 - 1 ) |
( ( V_10 -> V_20 - 1 ) << 16 ) ) ;
V_17 = 0 ;
V_16 = F_6 ( V_3 -> V_7 -> V_8 -> V_32 ) ;
V_13 = V_10 -> V_33 * 1000 ;
if ( ( V_16 / 2 ) < V_13 ) {
V_16 *= 2 ;
V_17 |= V_34 ;
}
div = F_7 ( V_16 , V_13 ) ;
if ( div < 2 )
div = 2 ;
V_17 |= F_8 ( div ) ;
F_9 ( V_6 , F_5 ( 0 ) ,
V_34 | V_35 |
V_36 , V_17 ) ;
V_17 = 0 ;
if ( V_10 -> V_37 & V_38 )
V_17 |= V_39 ;
if ( V_10 -> V_37 & V_40 )
V_17 |= V_41 ;
F_9 ( V_6 , F_5 ( 5 ) ,
V_41 | V_39 |
V_42 | V_43 |
V_44 | V_45 |
V_46 | V_47 |
V_48 ,
V_17 ) ;
}
static bool F_10 ( struct V_2 * V_3 ,
const struct V_9 * V_49 ,
struct V_9 * V_12 )
{
return true ;
}
static void F_11 ( struct V_2 * V_5 )
{
struct V_50 * V_51 = V_5 -> V_51 ;
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_6 * V_6 = V_3 -> V_7 -> V_8 -> V_6 ;
unsigned int V_52 ;
if ( ! V_3 -> V_53 )
return;
F_12 ( V_5 ) ;
F_13 ( V_51 -> V_51 ) ;
F_4 ( V_6 , V_54 , V_55 ) ;
while ( ! F_14 ( V_6 , V_56 , & V_52 ) &&
( V_52 & V_55 ) )
F_15 () ;
F_4 ( V_6 , V_54 , V_57 ) ;
while ( ! F_14 ( V_6 , V_56 , & V_52 ) &&
( V_52 & V_57 ) )
F_15 () ;
F_4 ( V_6 , V_54 , V_58 ) ;
while ( ! F_14 ( V_6 , V_56 , & V_52 ) &&
( V_52 & V_58 ) )
F_15 () ;
F_16 ( V_3 -> V_7 -> V_8 -> V_32 ) ;
F_17 ( V_51 -> V_51 ) ;
F_18 ( V_51 -> V_51 ) ;
F_19 ( V_51 -> V_51 ) ;
V_3 -> V_53 = false ;
}
static void F_20 ( struct V_2 * V_5 )
{
struct V_50 * V_51 = V_5 -> V_51 ;
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_6 * V_6 = V_3 -> V_7 -> V_8 -> V_6 ;
unsigned int V_52 ;
if ( V_3 -> V_53 )
return;
F_13 ( V_51 -> V_51 ) ;
F_21 ( V_51 -> V_51 ) ;
F_22 ( V_51 -> V_51 ) ;
F_23 ( V_3 -> V_7 -> V_8 -> V_32 ) ;
F_4 ( V_6 , V_59 , V_58 ) ;
while ( ! F_14 ( V_6 , V_56 , & V_52 ) &&
! ( V_52 & V_58 ) )
F_15 () ;
F_4 ( V_6 , V_59 , V_57 ) ;
while ( ! F_14 ( V_6 , V_56 , & V_52 ) &&
! ( V_52 & V_57 ) )
F_15 () ;
F_4 ( V_6 , V_59 , V_55 ) ;
while ( ! F_14 ( V_6 , V_56 , & V_52 ) &&
! ( V_52 & V_55 ) )
F_15 () ;
F_19 ( V_51 -> V_51 ) ;
F_24 ( V_5 ) ;
V_3 -> V_53 = true ;
}
void F_25 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( V_3 -> V_53 ) {
F_11 ( V_5 ) ;
V_3 -> V_53 = true ;
}
}
void F_26 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( V_3 -> V_53 ) {
V_3 -> V_53 = false ;
F_20 ( V_5 ) ;
}
}
static int F_27 ( struct V_2 * V_5 ,
struct V_60 * V_61 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( F_28 ( V_3 -> V_7 , & V_61 -> V_12 ) != V_62 )
return - V_63 ;
return F_29 ( V_61 ) ;
}
static void F_30 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( V_5 -> V_11 -> V_64 ) {
V_5 -> V_11 -> V_64 -> V_65 = F_31 ( V_5 ) ;
F_32 ( F_33 ( V_5 ) != 0 ) ;
V_3 -> V_64 = V_5 -> V_11 -> V_64 ;
V_5 -> V_11 -> V_64 = NULL ;
}
}
static void F_34 ( struct V_2 * V_3 )
{
}
static void F_35 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
F_36 ( V_5 ) ;
F_37 ( V_3 ) ;
}
void F_38 ( struct V_2 * V_5 ,
struct V_66 * V_67 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_68 * V_64 ;
struct V_50 * V_51 = V_5 -> V_51 ;
unsigned long V_37 ;
F_39 ( & V_51 -> V_69 , V_37 ) ;
V_64 = V_3 -> V_64 ;
if ( V_64 && V_64 -> V_4 . V_70 == V_67 ) {
V_64 -> V_4 . V_71 ( & V_64 -> V_4 ) ;
F_40 ( V_51 , V_3 -> V_72 ) ;
V_3 -> V_64 = NULL ;
}
F_41 ( & V_51 -> V_69 , V_37 ) ;
}
static void F_42 ( struct V_1 * V_3 )
{
struct V_50 * V_51 = V_3 -> V_4 . V_51 ;
unsigned long V_37 ;
F_39 ( & V_51 -> V_69 , V_37 ) ;
if ( V_3 -> V_64 ) {
F_43 ( V_51 , V_3 -> V_72 , V_3 -> V_64 ) ;
F_40 ( V_51 , V_3 -> V_72 ) ;
V_3 -> V_64 = NULL ;
}
F_41 ( & V_51 -> V_69 , V_37 ) ;
}
void F_44 ( struct V_2 * V_5 )
{
F_45 ( V_5 -> V_51 , 0 ) ;
F_42 ( F_1 ( V_5 ) ) ;
}
int F_46 ( struct V_50 * V_51 )
{
struct V_73 * V_7 = V_51 -> V_74 ;
struct V_75 * V_76 = V_7 -> V_76 ;
struct V_1 * V_3 ;
int V_77 ;
int V_78 ;
V_3 = F_47 ( sizeof( * V_3 ) , V_79 ) ;
if ( ! V_3 )
return - V_80 ;
V_3 -> V_7 = V_7 ;
V_77 = F_48 ( V_51 , & V_3 -> V_4 ,
& V_76 -> V_81 -> V_4 ,
V_76 -> V_82 ? & V_76 -> V_82 -> V_4 : NULL ,
& V_83 ) ;
if ( V_77 < 0 )
goto V_84;
V_3 -> V_72 = F_31 ( & V_3 -> V_4 ) ;
if ( V_76 -> V_82 )
V_76 -> V_82 -> V_4 . V_85 = 1 << V_3 -> V_72 ;
for ( V_78 = 0 ; V_78 < V_76 -> V_86 ; V_78 ++ )
V_76 -> V_87 [ V_78 ] -> V_4 . V_85 = 1 << V_3 -> V_72 ;
F_49 ( & V_3 -> V_4 , & V_88 ) ;
F_50 ( & V_3 -> V_4 ) ;
V_7 -> V_3 = & V_3 -> V_4 ;
return 0 ;
V_84:
F_35 ( & V_3 -> V_4 ) ;
return V_77 ;
}
