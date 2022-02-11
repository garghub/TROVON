static T_1 F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 = V_3 * V_2 -> V_5 ;
F_2 ( V_4 , V_6 ) ;
if ( F_3 ( V_2 -> V_7 == V_8 ) ) {
F_2 ( V_4 , 53 ) ;
V_4 = V_4 * 48 ;
}
if ( V_4 > V_2 -> V_9 )
V_4 -= V_2 -> V_9 ;
else
V_4 = 0 ;
return V_4 ;
}
static unsigned int F_4 ( const struct V_10 * V_11 )
{
unsigned int V_12 = F_5 ( V_11 ) - F_6 ( V_11 ) ;
return V_12 + F_7 ( V_11 ) ;
}
static int F_8 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_10 * V_17 , * V_18 ;
T_2 V_19 = F_10 ( V_11 ) ;
int V_20 , V_21 ;
V_17 = F_11 ( V_11 , V_19 & ~ V_22 ) ;
if ( F_12 ( V_17 ) )
return F_13 ( V_11 , V_14 ) ;
V_21 = 0 ;
while ( V_17 ) {
V_18 = V_17 -> V_23 ;
V_17 -> V_23 = NULL ;
F_14 ( V_17 ) -> V_24 = V_17 -> V_4 ;
V_20 = F_15 ( V_17 , V_16 -> V_25 ) ;
if ( V_20 != V_26 ) {
if ( F_16 ( V_20 ) )
F_17 ( V_14 ) ;
} else {
V_21 ++ ;
}
V_17 = V_18 ;
}
V_14 -> V_16 . V_27 += V_21 ;
if ( V_21 > 1 )
F_18 ( V_14 , 1 - V_21 ) ;
F_19 ( V_11 ) ;
return V_21 > 0 ? V_26 : V_28 ;
}
static int F_20 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
int V_20 ;
if ( F_21 ( V_11 ) > V_16 -> V_29 ) {
if ( F_22 ( V_11 ) && F_4 ( V_11 ) <= V_16 -> V_29 )
return F_8 ( V_11 , V_14 ) ;
return F_13 ( V_11 , V_14 ) ;
}
V_20 = F_15 ( V_11 , V_16 -> V_25 ) ;
if ( V_20 != V_26 ) {
if ( F_16 ( V_20 ) )
F_17 ( V_14 ) ;
return V_20 ;
}
V_14 -> V_16 . V_27 ++ ;
return V_26 ;
}
static unsigned int F_23 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
unsigned int V_4 = 0 ;
if ( V_16 -> V_25 -> V_30 -> V_31 && ( V_4 = V_16 -> V_25 -> V_30 -> V_31 ( V_16 -> V_25 ) ) != 0 ) {
V_14 -> V_16 . V_27 -- ;
F_17 ( V_14 ) ;
}
return V_4 ;
}
static bool F_24 ( const struct V_15 * V_16 )
{
return V_16 -> V_32 . V_5 ;
}
static struct V_10 * F_25 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_10 * V_11 ;
V_11 = V_16 -> V_25 -> V_30 -> V_33 ( V_16 -> V_25 ) ;
if ( V_11 ) {
T_3 V_34 ;
T_3 V_35 ;
T_3 V_36 = 0 ;
unsigned int V_4 = F_21 ( V_11 ) ;
V_34 = F_26 () ;
V_35 = F_27 ( T_3 , V_34 - V_16 -> V_37 , V_16 -> V_38 ) ;
if ( F_24 ( V_16 ) ) {
V_36 = V_35 + V_16 -> V_39 ;
if ( V_36 > V_16 -> V_40 )
V_36 = V_16 -> V_40 ;
V_36 -= ( T_3 ) F_28 ( & V_16 -> V_32 , V_4 ) ;
}
V_35 += V_16 -> V_41 ;
if ( V_35 > V_16 -> V_38 )
V_35 = V_16 -> V_38 ;
V_35 -= ( T_3 ) F_28 ( & V_16 -> V_42 , V_4 ) ;
if ( ( V_35 | V_36 ) >= 0 ) {
V_11 = F_29 ( V_16 -> V_25 ) ;
if ( F_3 ( ! V_11 ) )
return NULL ;
V_16 -> V_37 = V_34 ;
V_16 -> V_41 = V_35 ;
V_16 -> V_39 = V_36 ;
V_14 -> V_16 . V_27 -- ;
F_30 ( V_14 ) ;
F_31 ( V_14 , V_11 ) ;
return V_11 ;
}
F_32 ( & V_16 -> V_43 ,
V_34 + F_33 ( long , - V_35 , - V_36 ) ,
true ) ;
F_34 ( V_14 ) ;
}
return NULL ;
}
static void F_35 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_36 ( V_16 -> V_25 ) ;
V_14 -> V_16 . V_27 = 0 ;
V_16 -> V_37 = F_26 () ;
V_16 -> V_41 = V_16 -> V_38 ;
V_16 -> V_39 = V_16 -> V_40 ;
F_37 ( & V_16 -> V_43 ) ;
}
static int F_38 ( struct V_13 * V_14 , struct V_44 * V_45 )
{
int V_46 ;
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_44 * V_47 [ V_48 + 1 ] ;
struct V_49 * V_50 ;
struct V_13 * V_51 = NULL ;
struct V_1 V_42 ;
struct V_1 V_32 ;
T_1 V_29 ;
T_3 V_38 , V_40 ;
T_1 V_52 = 0 , V_53 = 0 ;
V_46 = F_39 ( V_47 , V_48 , V_45 , V_54 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = - V_55 ;
if ( V_47 [ V_56 ] == NULL )
goto V_57;
V_50 = F_40 ( V_47 [ V_56 ] ) ;
if ( V_50 -> V_42 . V_7 == V_58 )
F_41 ( F_42 ( & V_50 -> V_42 ,
V_47 [ V_59 ] ) ) ;
if ( V_50 -> V_60 . V_7 == V_58 )
F_41 ( F_42 ( & V_50 -> V_60 ,
V_47 [ V_61 ] ) ) ;
V_38 = F_27 ( T_1 , F_43 ( V_50 -> V_38 ) , ~ 0U ) ;
V_40 = F_27 ( T_1 , F_43 ( V_50 -> V_40 ) , ~ 0U ) ;
if ( V_47 [ V_62 ] )
V_52 = F_44 ( V_47 [ V_62 ] ) ;
F_45 ( & V_42 , & V_50 -> V_42 , V_52 ) ;
if ( V_47 [ V_63 ] ) {
V_29 = F_46 ( V_47 [ V_63 ] ) ;
V_38 = F_28 ( & V_42 , V_29 ) ;
} else {
V_29 = F_27 ( T_1 , F_1 ( & V_42 , V_38 ) , ~ 0U ) ;
}
if ( V_50 -> V_60 . V_42 ) {
if ( V_47 [ V_64 ] )
V_53 = F_44 ( V_47 [ V_64 ] ) ;
F_45 ( & V_32 , & V_50 -> V_60 , V_53 ) ;
if ( V_32 . V_5 <= V_42 . V_5 ) {
F_47 ( L_1 ,
V_32 . V_5 , V_42 . V_5 ) ;
V_46 = - V_55 ;
goto V_57;
}
if ( V_47 [ V_65 ] ) {
T_4 V_66 = F_46 ( V_47 [ V_65 ] ) ;
V_29 = F_27 ( T_4 , V_29 , V_66 ) ;
V_40 = F_28 ( & V_32 , V_66 ) ;
} else {
V_29 = F_27 ( T_1 , V_29 , F_1 ( & V_32 , V_40 ) ) ;
}
} else {
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
}
if ( V_29 < F_48 ( F_49 ( V_14 ) ) )
F_47 ( L_2 ,
V_29 , F_49 ( V_14 ) -> V_67 ,
F_48 ( F_49 ( V_14 ) ) ) ;
if ( ! V_29 ) {
V_46 = - V_55 ;
goto V_57;
}
if ( V_16 -> V_25 != & V_68 ) {
V_46 = F_50 ( V_16 -> V_25 , V_50 -> V_69 ) ;
if ( V_46 )
goto V_57;
} else if ( V_50 -> V_69 > 0 ) {
V_51 = F_51 ( V_14 , & V_70 , V_50 -> V_69 ) ;
if ( F_52 ( V_51 ) ) {
V_46 = F_53 ( V_51 ) ;
goto V_57;
}
}
F_54 ( V_14 ) ;
if ( V_51 ) {
F_18 ( V_16 -> V_25 , V_16 -> V_25 -> V_16 . V_27 ) ;
F_55 ( V_16 -> V_25 ) ;
V_16 -> V_25 = V_51 ;
}
V_16 -> V_69 = V_50 -> V_69 ;
if ( V_47 [ V_65 ] )
V_16 -> V_40 = V_40 ;
else
V_16 -> V_40 = F_43 ( V_50 -> V_40 ) ;
V_16 -> V_29 = V_29 ;
if ( V_47 [ V_63 ] )
V_16 -> V_38 = V_38 ;
else
V_16 -> V_38 = F_43 ( V_50 -> V_38 ) ;
V_16 -> V_41 = V_16 -> V_38 ;
V_16 -> V_39 = V_16 -> V_40 ;
memcpy ( & V_16 -> V_42 , & V_42 , sizeof( struct V_1 ) ) ;
memcpy ( & V_16 -> V_32 , & V_32 , sizeof( struct V_1 ) ) ;
F_56 ( V_14 ) ;
V_46 = 0 ;
V_57:
return V_46 ;
}
static int F_57 ( struct V_13 * V_14 , struct V_44 * V_45 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_45 == NULL )
return - V_55 ;
V_16 -> V_37 = F_26 () ;
F_58 ( & V_16 -> V_43 , V_14 ) ;
V_16 -> V_25 = & V_68 ;
return F_38 ( V_14 , V_45 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_37 ( & V_16 -> V_43 ) ;
F_55 ( V_16 -> V_25 ) ;
}
static int F_60 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_44 * V_71 ;
struct V_49 V_45 ;
V_14 -> V_72 . V_73 = V_16 -> V_25 -> V_72 . V_73 ;
V_71 = F_61 ( V_11 , V_74 ) ;
if ( V_71 == NULL )
goto V_75;
V_45 . V_69 = V_16 -> V_69 ;
F_62 ( & V_45 . V_42 , & V_16 -> V_42 ) ;
if ( F_24 ( V_16 ) )
F_62 ( & V_45 . V_60 , & V_16 -> V_32 ) ;
else
memset ( & V_45 . V_60 , 0 , sizeof( V_45 . V_60 ) ) ;
V_45 . V_40 = F_63 ( V_16 -> V_40 ) ;
V_45 . V_38 = F_63 ( V_16 -> V_38 ) ;
if ( F_64 ( V_11 , V_56 , sizeof( V_45 ) , & V_45 ) )
goto V_75;
if ( V_16 -> V_42 . V_5 >= ( 1ULL << 32 ) &&
F_65 ( V_11 , V_62 , V_16 -> V_42 . V_5 ) )
goto V_75;
if ( F_24 ( V_16 ) &&
V_16 -> V_32 . V_5 >= ( 1ULL << 32 ) &&
F_65 ( V_11 , V_64 , V_16 -> V_32 . V_5 ) )
goto V_75;
return F_66 ( V_11 , V_71 ) ;
V_75:
F_67 ( V_11 , V_71 ) ;
return - 1 ;
}
static int F_68 ( struct V_13 * V_14 , unsigned long V_76 ,
struct V_10 * V_11 , struct V_77 * V_78 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
V_78 -> V_79 |= F_69 ( 1 ) ;
V_78 -> V_80 = V_16 -> V_25 -> V_81 ;
return 0 ;
}
static int F_70 ( struct V_13 * V_14 , unsigned long V_82 , struct V_13 * V_83 ,
struct V_13 * * V_84 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_83 == NULL )
V_83 = & V_68 ;
F_54 ( V_14 ) ;
* V_84 = V_16 -> V_25 ;
V_16 -> V_25 = V_83 ;
F_18 ( * V_84 , ( * V_84 ) -> V_16 . V_27 ) ;
F_36 ( * V_84 ) ;
F_56 ( V_14 ) ;
return 0 ;
}
static struct V_13 * F_71 ( struct V_13 * V_14 , unsigned long V_82 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
return V_16 -> V_25 ;
}
static unsigned long F_72 ( struct V_13 * V_14 , T_4 V_85 )
{
return 1 ;
}
static void F_73 ( struct V_13 * V_14 , unsigned long V_82 )
{
}
static void F_74 ( struct V_13 * V_14 , struct V_86 * V_87 )
{
if ( ! V_87 -> V_88 ) {
if ( V_87 -> V_89 >= V_87 -> V_90 )
if ( V_87 -> V_91 ( V_14 , 1 , V_87 ) < 0 ) {
V_87 -> V_88 = 1 ;
return;
}
V_87 -> V_89 ++ ;
}
}
static int T_5 F_75 ( void )
{
return F_76 ( & V_92 ) ;
}
static void T_6 F_77 ( void )
{
F_78 ( & V_92 ) ;
}
