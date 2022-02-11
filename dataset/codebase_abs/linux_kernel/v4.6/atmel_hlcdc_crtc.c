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
static void F_10 ( struct V_2 * V_5 )
{
struct V_49 * V_50 = V_5 -> V_50 ;
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_6 * V_6 = V_3 -> V_7 -> V_8 -> V_6 ;
unsigned int V_51 ;
if ( ! V_3 -> V_52 )
return;
F_11 ( V_5 ) ;
F_12 ( V_50 -> V_50 ) ;
F_4 ( V_6 , V_53 , V_54 ) ;
while ( ! F_13 ( V_6 , V_55 , & V_51 ) &&
( V_51 & V_54 ) )
F_14 () ;
F_4 ( V_6 , V_53 , V_56 ) ;
while ( ! F_13 ( V_6 , V_55 , & V_51 ) &&
( V_51 & V_56 ) )
F_14 () ;
F_4 ( V_6 , V_53 , V_57 ) ;
while ( ! F_13 ( V_6 , V_55 , & V_51 ) &&
( V_51 & V_57 ) )
F_14 () ;
F_15 ( V_3 -> V_7 -> V_8 -> V_32 ) ;
F_16 ( V_50 -> V_50 ) ;
F_17 ( V_50 -> V_50 ) ;
F_18 ( V_50 -> V_50 ) ;
V_3 -> V_52 = false ;
}
static void F_19 ( struct V_2 * V_5 )
{
struct V_49 * V_50 = V_5 -> V_50 ;
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_6 * V_6 = V_3 -> V_7 -> V_8 -> V_6 ;
unsigned int V_51 ;
if ( V_3 -> V_52 )
return;
F_12 ( V_50 -> V_50 ) ;
F_20 ( V_50 -> V_50 ) ;
F_21 ( V_50 -> V_50 ) ;
F_22 ( V_3 -> V_7 -> V_8 -> V_32 ) ;
F_4 ( V_6 , V_58 , V_57 ) ;
while ( ! F_13 ( V_6 , V_55 , & V_51 ) &&
! ( V_51 & V_57 ) )
F_14 () ;
F_4 ( V_6 , V_58 , V_56 ) ;
while ( ! F_13 ( V_6 , V_55 , & V_51 ) &&
! ( V_51 & V_56 ) )
F_14 () ;
F_4 ( V_6 , V_58 , V_54 ) ;
while ( ! F_13 ( V_6 , V_55 , & V_51 ) &&
! ( V_51 & V_54 ) )
F_14 () ;
F_18 ( V_50 -> V_50 ) ;
F_23 ( V_5 ) ;
V_3 -> V_52 = true ;
}
void F_24 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( V_3 -> V_52 ) {
F_10 ( V_5 ) ;
V_3 -> V_52 = true ;
}
}
void F_25 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( V_3 -> V_52 ) {
V_3 -> V_52 = false ;
F_19 ( V_5 ) ;
}
}
static int F_26 ( struct V_2 * V_5 ,
struct V_59 * V_60 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( F_27 ( V_3 -> V_7 , & V_60 -> V_12 ) != V_61 )
return - V_62 ;
return F_28 ( V_60 ) ;
}
static void F_29 ( struct V_2 * V_5 ,
struct V_59 * V_63 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
if ( V_5 -> V_11 -> V_64 ) {
V_5 -> V_11 -> V_64 -> V_65 = F_30 ( V_5 ) ;
F_31 ( F_32 ( V_5 ) != 0 ) ;
V_3 -> V_64 = V_5 -> V_11 -> V_64 ;
V_5 -> V_11 -> V_64 = NULL ;
}
}
static void F_33 ( struct V_2 * V_3 ,
struct V_59 * V_63 )
{
}
static void F_34 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
F_35 ( V_5 ) ;
F_36 ( V_3 ) ;
}
static void F_37 ( struct V_1 * V_3 )
{
struct V_49 * V_50 = V_3 -> V_4 . V_50 ;
unsigned long V_37 ;
F_38 ( & V_50 -> V_66 , V_37 ) ;
if ( V_3 -> V_64 ) {
F_39 ( V_50 , V_3 -> V_67 , V_3 -> V_64 ) ;
F_40 ( V_50 , V_3 -> V_67 ) ;
V_3 -> V_64 = NULL ;
}
F_41 ( & V_50 -> V_66 , V_37 ) ;
}
void F_42 ( struct V_2 * V_5 )
{
F_43 ( V_5 -> V_50 , 0 ) ;
F_37 ( F_1 ( V_5 ) ) ;
}
int F_44 ( struct V_49 * V_50 )
{
struct V_68 * V_7 = V_50 -> V_69 ;
struct V_70 * V_71 = V_7 -> V_71 ;
struct V_1 * V_3 ;
int V_72 ;
int V_73 ;
V_3 = F_45 ( sizeof( * V_3 ) , V_74 ) ;
if ( ! V_3 )
return - V_75 ;
V_3 -> V_7 = V_7 ;
V_72 = F_46 ( V_50 , & V_3 -> V_4 ,
& V_71 -> V_76 -> V_4 ,
V_71 -> V_77 ? & V_71 -> V_77 -> V_4 : NULL ,
& V_78 , NULL ) ;
if ( V_72 < 0 )
goto V_79;
V_3 -> V_67 = F_30 ( & V_3 -> V_4 ) ;
if ( V_71 -> V_77 )
V_71 -> V_77 -> V_4 . V_80 = 1 << V_3 -> V_67 ;
for ( V_73 = 0 ; V_73 < V_71 -> V_81 ; V_73 ++ )
V_71 -> V_82 [ V_73 ] -> V_4 . V_80 = 1 << V_3 -> V_67 ;
F_47 ( & V_3 -> V_4 , & V_83 ) ;
F_48 ( & V_3 -> V_4 ) ;
V_7 -> V_3 = & V_3 -> V_4 ;
return 0 ;
V_79:
F_34 ( & V_3 -> V_4 ) ;
return V_72 ;
}
