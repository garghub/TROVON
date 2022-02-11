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
const struct V_13 * V_14 = F_7 ( V_11 ) ;
if ( F_8 ( V_14 -> V_15 & ( V_16 | V_17 ) ) )
V_12 += F_9 ( V_11 ) ;
else
V_12 += sizeof( struct V_18 ) ;
return V_12 + V_14 -> V_19 ;
}
static int F_10 ( struct V_10 * V_11 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
struct V_10 * V_24 , * V_25 ;
T_2 V_26 = F_12 ( V_11 ) ;
int V_27 , V_28 ;
V_24 = F_13 ( V_11 , V_26 & ~ V_29 ) ;
if ( F_14 ( V_24 ) )
return F_15 ( V_11 , V_21 ) ;
V_28 = 0 ;
while ( V_24 ) {
V_25 = V_24 -> V_30 ;
V_24 -> V_30 = NULL ;
F_16 ( V_24 ) -> V_31 = V_24 -> V_4 ;
V_27 = F_17 ( V_24 , V_23 -> V_32 ) ;
if ( V_27 != V_33 ) {
if ( F_18 ( V_27 ) )
V_21 -> V_34 . V_35 ++ ;
} else {
V_28 ++ ;
}
V_24 = V_25 ;
}
V_21 -> V_23 . V_36 += V_28 ;
if ( V_28 > 1 )
F_19 ( V_21 , 1 - V_28 ) ;
F_20 ( V_11 ) ;
return V_28 > 0 ? V_33 : V_37 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
int V_27 ;
if ( F_22 ( V_11 ) > V_23 -> V_38 ) {
if ( F_23 ( V_11 ) && F_4 ( V_11 ) <= V_23 -> V_38 )
return F_10 ( V_11 , V_21 ) ;
return F_15 ( V_11 , V_21 ) ;
}
V_27 = F_17 ( V_11 , V_23 -> V_32 ) ;
if ( V_27 != V_33 ) {
if ( F_18 ( V_27 ) )
V_21 -> V_34 . V_35 ++ ;
return V_27 ;
}
V_21 -> V_23 . V_36 ++ ;
return V_33 ;
}
static unsigned int F_24 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
unsigned int V_4 = 0 ;
if ( V_23 -> V_32 -> V_39 -> V_40 && ( V_4 = V_23 -> V_32 -> V_39 -> V_40 ( V_23 -> V_32 ) ) != 0 ) {
V_21 -> V_23 . V_36 -- ;
V_21 -> V_34 . V_35 ++ ;
}
return V_4 ;
}
static struct V_10 * F_25 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
struct V_10 * V_11 ;
V_11 = V_23 -> V_32 -> V_39 -> V_41 ( V_23 -> V_32 ) ;
if ( V_11 ) {
T_3 V_42 ;
T_3 V_43 ;
T_3 V_44 = 0 ;
unsigned int V_4 = F_22 ( V_11 ) ;
V_42 = F_26 ( F_27 () ) ;
V_43 = F_28 ( T_3 , V_42 - V_23 -> V_45 , V_23 -> V_46 ) ;
if ( V_23 -> V_47 ) {
V_44 = V_43 + V_23 -> V_48 ;
if ( V_44 > V_23 -> V_49 )
V_44 = V_23 -> V_49 ;
V_44 -= ( T_3 ) F_29 ( & V_23 -> V_50 , V_4 ) ;
}
V_43 += V_23 -> V_51 ;
if ( V_43 > V_23 -> V_46 )
V_43 = V_23 -> V_46 ;
V_43 -= ( T_3 ) F_29 ( & V_23 -> V_52 , V_4 ) ;
if ( ( V_43 | V_44 ) >= 0 ) {
V_11 = F_30 ( V_23 -> V_32 ) ;
if ( F_3 ( ! V_11 ) )
return NULL ;
V_23 -> V_45 = V_42 ;
V_23 -> V_51 = V_43 ;
V_23 -> V_48 = V_44 ;
V_21 -> V_23 . V_36 -- ;
F_31 ( V_21 ) ;
F_32 ( V_21 , V_11 ) ;
return V_11 ;
}
F_33 ( & V_23 -> V_53 ,
V_42 + F_34 ( long , - V_43 , - V_44 ) ) ;
V_21 -> V_34 . V_54 ++ ;
}
return NULL ;
}
static void F_35 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
F_36 ( V_23 -> V_32 ) ;
V_21 -> V_23 . V_36 = 0 ;
V_23 -> V_45 = F_26 ( F_27 () ) ;
V_23 -> V_51 = V_23 -> V_46 ;
V_23 -> V_48 = V_23 -> V_49 ;
F_37 ( & V_23 -> V_53 ) ;
}
static int F_38 ( struct V_20 * V_21 , struct V_55 * V_56 )
{
int V_57 ;
struct V_22 * V_23 = F_11 ( V_21 ) ;
struct V_55 * V_58 [ V_59 + 1 ] ;
struct V_60 * V_61 ;
struct V_20 * V_62 = NULL ;
struct V_1 V_52 ;
struct V_1 V_50 ;
T_1 V_38 ;
T_3 V_46 , V_49 ;
T_1 V_63 = 0 , V_64 = 0 ;
V_57 = F_39 ( V_58 , V_59 , V_56 , V_65 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = - V_66 ;
if ( V_58 [ V_67 ] == NULL )
goto V_68;
V_61 = F_40 ( V_58 [ V_67 ] ) ;
if ( V_61 -> V_52 . V_7 == V_69 )
F_41 ( F_42 ( & V_61 -> V_52 ,
V_58 [ V_70 ] ) ) ;
if ( V_61 -> V_71 . V_7 == V_69 )
F_41 ( F_42 ( & V_61 -> V_71 ,
V_58 [ V_72 ] ) ) ;
if ( V_23 -> V_32 != & V_73 ) {
V_57 = F_43 ( V_23 -> V_32 , V_61 -> V_74 ) ;
if ( V_57 )
goto V_68;
} else if ( V_61 -> V_74 > 0 ) {
V_62 = F_44 ( V_21 , & V_75 , V_61 -> V_74 ) ;
if ( F_45 ( V_62 ) ) {
V_57 = F_46 ( V_62 ) ;
goto V_68;
}
}
V_46 = F_28 ( T_1 , F_47 ( V_61 -> V_46 ) , ~ 0U ) ;
V_49 = F_28 ( T_1 , F_47 ( V_61 -> V_49 ) , ~ 0U ) ;
if ( V_58 [ V_76 ] )
V_63 = F_48 ( V_58 [ V_76 ] ) ;
F_49 ( & V_52 , & V_61 -> V_52 , V_63 ) ;
V_38 = F_28 ( T_1 , F_1 ( & V_52 , V_46 ) , ~ 0U ) ;
if ( V_61 -> V_71 . V_52 ) {
if ( V_58 [ V_77 ] )
V_64 = F_48 ( V_58 [ V_77 ] ) ;
F_49 ( & V_50 , & V_61 -> V_71 , V_64 ) ;
if ( V_50 . V_5 <= V_52 . V_5 ) {
F_50 ( L_1 ,
V_50 . V_5 , V_52 . V_5 ) ;
V_57 = - V_66 ;
goto V_68;
}
V_38 = F_28 ( T_1 , V_38 , F_1 ( & V_50 , V_49 ) ) ;
}
if ( V_38 < F_51 ( F_52 ( V_21 ) ) )
F_50 ( L_2 ,
V_38 , F_52 ( V_21 ) -> V_78 ,
F_51 ( F_52 ( V_21 ) ) ) ;
if ( ! V_38 ) {
V_57 = - V_66 ;
goto V_68;
}
F_53 ( V_21 ) ;
if ( V_62 ) {
F_19 ( V_23 -> V_32 , V_23 -> V_32 -> V_23 . V_36 ) ;
F_54 ( V_23 -> V_32 ) ;
V_23 -> V_32 = V_62 ;
}
V_23 -> V_74 = V_61 -> V_74 ;
V_23 -> V_49 = F_47 ( V_61 -> V_49 ) ;
V_23 -> V_38 = V_38 ;
V_23 -> V_46 = F_47 ( V_61 -> V_46 ) ;
V_23 -> V_51 = V_23 -> V_46 ;
V_23 -> V_48 = V_23 -> V_49 ;
memcpy ( & V_23 -> V_52 , & V_52 , sizeof( struct V_1 ) ) ;
if ( V_61 -> V_71 . V_52 ) {
memcpy ( & V_23 -> V_50 , & V_50 , sizeof( struct V_1 ) ) ;
V_23 -> V_47 = true ;
} else {
V_23 -> V_47 = false ;
}
F_55 ( V_21 ) ;
V_57 = 0 ;
V_68:
return V_57 ;
}
static int F_56 ( struct V_20 * V_21 , struct V_55 * V_56 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
if ( V_56 == NULL )
return - V_66 ;
V_23 -> V_45 = F_26 ( F_27 () ) ;
F_57 ( & V_23 -> V_53 , V_21 ) ;
V_23 -> V_32 = & V_73 ;
return F_38 ( V_21 , V_56 ) ;
}
static void F_58 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
F_37 ( & V_23 -> V_53 ) ;
F_54 ( V_23 -> V_32 ) ;
}
static int F_59 ( struct V_20 * V_21 , struct V_10 * V_11 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
struct V_55 * V_79 ;
struct V_60 V_56 ;
V_21 -> V_34 . V_80 = V_23 -> V_32 -> V_34 . V_80 ;
V_79 = F_60 ( V_11 , V_81 ) ;
if ( V_79 == NULL )
goto V_82;
V_56 . V_74 = V_23 -> V_74 ;
F_61 ( & V_56 . V_52 , & V_23 -> V_52 ) ;
if ( V_23 -> V_47 )
F_61 ( & V_56 . V_71 , & V_23 -> V_50 ) ;
else
memset ( & V_56 . V_71 , 0 , sizeof( V_56 . V_71 ) ) ;
V_56 . V_49 = F_62 ( V_23 -> V_49 ) ;
V_56 . V_46 = F_62 ( V_23 -> V_46 ) ;
if ( F_63 ( V_11 , V_67 , sizeof( V_56 ) , & V_56 ) )
goto V_82;
if ( V_23 -> V_52 . V_5 >= ( 1ULL << 32 ) &&
F_64 ( V_11 , V_76 , V_23 -> V_52 . V_5 ) )
goto V_82;
if ( V_23 -> V_47 &&
V_23 -> V_50 . V_5 >= ( 1ULL << 32 ) &&
F_64 ( V_11 , V_77 , V_23 -> V_50 . V_5 ) )
goto V_82;
F_65 ( V_11 , V_79 ) ;
return V_11 -> V_4 ;
V_82:
F_66 ( V_11 , V_79 ) ;
return - 1 ;
}
static int F_67 ( struct V_20 * V_21 , unsigned long V_83 ,
struct V_10 * V_11 , struct V_84 * V_85 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
V_85 -> V_86 |= F_68 ( 1 ) ;
V_85 -> V_87 = V_23 -> V_32 -> V_88 ;
return 0 ;
}
static int F_69 ( struct V_20 * V_21 , unsigned long V_89 , struct V_20 * V_90 ,
struct V_20 * * V_91 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
if ( V_90 == NULL )
V_90 = & V_73 ;
F_53 ( V_21 ) ;
* V_91 = V_23 -> V_32 ;
V_23 -> V_32 = V_90 ;
F_19 ( * V_91 , ( * V_91 ) -> V_23 . V_36 ) ;
F_36 ( * V_91 ) ;
F_55 ( V_21 ) ;
return 0 ;
}
static struct V_20 * F_70 ( struct V_20 * V_21 , unsigned long V_89 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
return V_23 -> V_32 ;
}
static unsigned long F_71 ( struct V_20 * V_21 , T_4 V_92 )
{
return 1 ;
}
static void F_72 ( struct V_20 * V_21 , unsigned long V_89 )
{
}
static void F_73 ( struct V_20 * V_21 , struct V_93 * V_94 )
{
if ( ! V_94 -> V_95 ) {
if ( V_94 -> V_96 >= V_94 -> V_97 )
if ( V_94 -> V_98 ( V_21 , 1 , V_94 ) < 0 ) {
V_94 -> V_95 = 1 ;
return;
}
V_94 -> V_96 ++ ;
}
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_99 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_99 ) ;
}
