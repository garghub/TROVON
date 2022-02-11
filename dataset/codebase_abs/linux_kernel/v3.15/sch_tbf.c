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
V_14 -> V_27 . V_28 ++ ;
} else {
V_21 ++ ;
}
V_17 = V_18 ;
}
V_14 -> V_16 . V_29 += V_21 ;
if ( V_21 > 1 )
F_17 ( V_14 , 1 - V_21 ) ;
F_18 ( V_11 ) ;
return V_21 > 0 ? V_26 : V_30 ;
}
static int F_19 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
int V_20 ;
if ( F_20 ( V_11 ) > V_16 -> V_31 ) {
if ( F_21 ( V_11 ) && F_4 ( V_11 ) <= V_16 -> V_31 )
return F_8 ( V_11 , V_14 ) ;
return F_13 ( V_11 , V_14 ) ;
}
V_20 = F_15 ( V_11 , V_16 -> V_25 ) ;
if ( V_20 != V_26 ) {
if ( F_16 ( V_20 ) )
V_14 -> V_27 . V_28 ++ ;
return V_20 ;
}
V_14 -> V_16 . V_29 ++ ;
return V_26 ;
}
static unsigned int F_22 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
unsigned int V_4 = 0 ;
if ( V_16 -> V_25 -> V_32 -> V_33 && ( V_4 = V_16 -> V_25 -> V_32 -> V_33 ( V_16 -> V_25 ) ) != 0 ) {
V_14 -> V_16 . V_29 -- ;
V_14 -> V_27 . V_28 ++ ;
}
return V_4 ;
}
static bool F_23 ( const struct V_15 * V_16 )
{
return V_16 -> V_34 . V_5 ;
}
static struct V_10 * F_24 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_10 * V_11 ;
V_11 = V_16 -> V_25 -> V_32 -> V_35 ( V_16 -> V_25 ) ;
if ( V_11 ) {
T_3 V_36 ;
T_3 V_37 ;
T_3 V_38 = 0 ;
unsigned int V_4 = F_20 ( V_11 ) ;
V_36 = F_25 ( F_26 () ) ;
V_37 = F_27 ( T_3 , V_36 - V_16 -> V_39 , V_16 -> V_40 ) ;
if ( F_23 ( V_16 ) ) {
V_38 = V_37 + V_16 -> V_41 ;
if ( V_38 > V_16 -> V_42 )
V_38 = V_16 -> V_42 ;
V_38 -= ( T_3 ) F_28 ( & V_16 -> V_34 , V_4 ) ;
}
V_37 += V_16 -> V_43 ;
if ( V_37 > V_16 -> V_40 )
V_37 = V_16 -> V_40 ;
V_37 -= ( T_3 ) F_28 ( & V_16 -> V_44 , V_4 ) ;
if ( ( V_37 | V_38 ) >= 0 ) {
V_11 = F_29 ( V_16 -> V_25 ) ;
if ( F_3 ( ! V_11 ) )
return NULL ;
V_16 -> V_39 = V_36 ;
V_16 -> V_43 = V_37 ;
V_16 -> V_41 = V_38 ;
V_14 -> V_16 . V_29 -- ;
F_30 ( V_14 ) ;
F_31 ( V_14 , V_11 ) ;
return V_11 ;
}
F_32 ( & V_16 -> V_45 ,
V_36 + F_33 ( long , - V_37 , - V_38 ) ) ;
V_14 -> V_27 . V_46 ++ ;
}
return NULL ;
}
static void F_34 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_35 ( V_16 -> V_25 ) ;
V_14 -> V_16 . V_29 = 0 ;
V_16 -> V_39 = F_25 ( F_26 () ) ;
V_16 -> V_43 = V_16 -> V_40 ;
V_16 -> V_41 = V_16 -> V_42 ;
F_36 ( & V_16 -> V_45 ) ;
}
static int F_37 ( struct V_13 * V_14 , struct V_47 * V_48 )
{
int V_49 ;
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_47 * V_50 [ V_51 + 1 ] ;
struct V_52 * V_53 ;
struct V_13 * V_54 = NULL ;
struct V_1 V_44 ;
struct V_1 V_34 ;
T_1 V_31 ;
T_3 V_40 , V_42 ;
T_1 V_55 = 0 , V_56 = 0 ;
V_49 = F_38 ( V_50 , V_51 , V_48 , V_57 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = - V_58 ;
if ( V_50 [ V_59 ] == NULL )
goto V_60;
V_53 = F_39 ( V_50 [ V_59 ] ) ;
if ( V_53 -> V_44 . V_7 == V_61 )
F_40 ( F_41 ( & V_53 -> V_44 ,
V_50 [ V_62 ] ) ) ;
if ( V_53 -> V_63 . V_7 == V_61 )
F_40 ( F_41 ( & V_53 -> V_63 ,
V_50 [ V_64 ] ) ) ;
V_40 = F_27 ( T_1 , F_42 ( V_53 -> V_40 ) , ~ 0U ) ;
V_42 = F_27 ( T_1 , F_42 ( V_53 -> V_42 ) , ~ 0U ) ;
if ( V_50 [ V_65 ] )
V_55 = F_43 ( V_50 [ V_65 ] ) ;
F_44 ( & V_44 , & V_53 -> V_44 , V_55 ) ;
if ( V_50 [ V_66 ] ) {
V_31 = F_45 ( V_50 [ V_66 ] ) ;
V_40 = F_28 ( & V_44 , V_31 ) ;
} else {
V_31 = F_27 ( T_1 , F_1 ( & V_44 , V_40 ) , ~ 0U ) ;
}
if ( V_53 -> V_63 . V_44 ) {
if ( V_50 [ V_67 ] )
V_56 = F_43 ( V_50 [ V_67 ] ) ;
F_44 ( & V_34 , & V_53 -> V_63 , V_56 ) ;
if ( V_34 . V_5 <= V_44 . V_5 ) {
F_46 ( L_1 ,
V_34 . V_5 , V_44 . V_5 ) ;
V_49 = - V_58 ;
goto V_60;
}
if ( V_50 [ V_68 ] ) {
T_4 V_69 = F_45 ( V_50 [ V_68 ] ) ;
V_31 = F_27 ( T_4 , V_31 , V_69 ) ;
V_42 = F_28 ( & V_34 , V_69 ) ;
} else {
V_31 = F_27 ( T_1 , V_31 , F_1 ( & V_34 , V_42 ) ) ;
}
} else {
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
}
if ( V_31 < F_47 ( F_48 ( V_14 ) ) )
F_46 ( L_2 ,
V_31 , F_48 ( V_14 ) -> V_70 ,
F_47 ( F_48 ( V_14 ) ) ) ;
if ( ! V_31 ) {
V_49 = - V_58 ;
goto V_60;
}
if ( V_16 -> V_25 != & V_71 ) {
V_49 = F_49 ( V_16 -> V_25 , V_53 -> V_72 ) ;
if ( V_49 )
goto V_60;
} else if ( V_53 -> V_72 > 0 ) {
V_54 = F_50 ( V_14 , & V_73 , V_53 -> V_72 ) ;
if ( F_51 ( V_54 ) ) {
V_49 = F_52 ( V_54 ) ;
goto V_60;
}
}
F_53 ( V_14 ) ;
if ( V_54 ) {
F_17 ( V_16 -> V_25 , V_16 -> V_25 -> V_16 . V_29 ) ;
F_54 ( V_16 -> V_25 ) ;
V_16 -> V_25 = V_54 ;
}
V_16 -> V_72 = V_53 -> V_72 ;
if ( V_50 [ V_68 ] )
V_16 -> V_42 = V_42 ;
else
V_16 -> V_42 = F_42 ( V_53 -> V_42 ) ;
V_16 -> V_31 = V_31 ;
if ( V_50 [ V_66 ] )
V_16 -> V_40 = V_40 ;
else
V_16 -> V_40 = F_42 ( V_53 -> V_40 ) ;
V_16 -> V_43 = V_16 -> V_40 ;
V_16 -> V_41 = V_16 -> V_42 ;
memcpy ( & V_16 -> V_44 , & V_44 , sizeof( struct V_1 ) ) ;
memcpy ( & V_16 -> V_34 , & V_34 , sizeof( struct V_1 ) ) ;
F_55 ( V_14 ) ;
V_49 = 0 ;
V_60:
return V_49 ;
}
static int F_56 ( struct V_13 * V_14 , struct V_47 * V_48 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_48 == NULL )
return - V_58 ;
V_16 -> V_39 = F_25 ( F_26 () ) ;
F_57 ( & V_16 -> V_45 , V_14 ) ;
V_16 -> V_25 = & V_71 ;
return F_37 ( V_14 , V_48 ) ;
}
static void F_58 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_36 ( & V_16 -> V_45 ) ;
F_54 ( V_16 -> V_25 ) ;
}
static int F_59 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_47 * V_74 ;
struct V_52 V_48 ;
V_14 -> V_27 . V_75 = V_16 -> V_25 -> V_27 . V_75 ;
V_74 = F_60 ( V_11 , V_76 ) ;
if ( V_74 == NULL )
goto V_77;
V_48 . V_72 = V_16 -> V_72 ;
F_61 ( & V_48 . V_44 , & V_16 -> V_44 ) ;
if ( F_23 ( V_16 ) )
F_61 ( & V_48 . V_63 , & V_16 -> V_34 ) ;
else
memset ( & V_48 . V_63 , 0 , sizeof( V_48 . V_63 ) ) ;
V_48 . V_42 = F_62 ( V_16 -> V_42 ) ;
V_48 . V_40 = F_62 ( V_16 -> V_40 ) ;
if ( F_63 ( V_11 , V_59 , sizeof( V_48 ) , & V_48 ) )
goto V_77;
if ( V_16 -> V_44 . V_5 >= ( 1ULL << 32 ) &&
F_64 ( V_11 , V_65 , V_16 -> V_44 . V_5 ) )
goto V_77;
if ( F_23 ( V_16 ) &&
V_16 -> V_34 . V_5 >= ( 1ULL << 32 ) &&
F_64 ( V_11 , V_67 , V_16 -> V_34 . V_5 ) )
goto V_77;
return F_65 ( V_11 , V_74 ) ;
V_77:
F_66 ( V_11 , V_74 ) ;
return - 1 ;
}
static int F_67 ( struct V_13 * V_14 , unsigned long V_78 ,
struct V_10 * V_11 , struct V_79 * V_80 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
V_80 -> V_81 |= F_68 ( 1 ) ;
V_80 -> V_82 = V_16 -> V_25 -> V_83 ;
return 0 ;
}
static int F_69 ( struct V_13 * V_14 , unsigned long V_84 , struct V_13 * V_85 ,
struct V_13 * * V_86 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_85 == NULL )
V_85 = & V_71 ;
F_53 ( V_14 ) ;
* V_86 = V_16 -> V_25 ;
V_16 -> V_25 = V_85 ;
F_17 ( * V_86 , ( * V_86 ) -> V_16 . V_29 ) ;
F_35 ( * V_86 ) ;
F_55 ( V_14 ) ;
return 0 ;
}
static struct V_13 * F_70 ( struct V_13 * V_14 , unsigned long V_84 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
return V_16 -> V_25 ;
}
static unsigned long F_71 ( struct V_13 * V_14 , T_4 V_87 )
{
return 1 ;
}
static void F_72 ( struct V_13 * V_14 , unsigned long V_84 )
{
}
static void F_73 ( struct V_13 * V_14 , struct V_88 * V_89 )
{
if ( ! V_89 -> V_90 ) {
if ( V_89 -> V_91 >= V_89 -> V_92 )
if ( V_89 -> V_93 ( V_14 , 1 , V_89 ) < 0 ) {
V_89 -> V_90 = 1 ;
return;
}
V_89 -> V_91 ++ ;
}
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_94 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_94 ) ;
}
