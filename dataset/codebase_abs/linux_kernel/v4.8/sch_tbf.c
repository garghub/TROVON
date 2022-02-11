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
static int F_8 ( struct V_10 * V_11 , struct V_13 * V_14 ,
struct V_10 * * V_15 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
struct V_10 * V_18 , * V_19 ;
T_2 V_20 = F_10 ( V_11 ) ;
unsigned int V_4 = 0 , V_21 = F_11 ( V_11 ) ;
int V_22 , V_23 ;
V_18 = F_12 ( V_11 , V_20 & ~ V_24 ) ;
if ( F_13 ( V_18 ) )
return F_14 ( V_11 , V_14 , V_15 ) ;
V_23 = 0 ;
while ( V_18 ) {
V_19 = V_18 -> V_25 ;
V_18 -> V_25 = NULL ;
F_15 ( V_18 ) -> V_26 = V_18 -> V_4 ;
V_4 += V_18 -> V_4 ;
V_22 = F_16 ( V_18 , V_17 -> V_27 , V_15 ) ;
if ( V_22 != V_28 ) {
if ( F_17 ( V_22 ) )
F_18 ( V_14 ) ;
} else {
V_23 ++ ;
}
V_18 = V_19 ;
}
V_14 -> V_17 . V_29 += V_23 ;
if ( V_23 > 1 )
F_19 ( V_14 , 1 - V_23 , V_21 - V_4 ) ;
F_20 ( V_11 ) ;
return V_23 > 0 ? V_28 : V_30 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_13 * V_14 ,
struct V_10 * * V_15 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
int V_22 ;
if ( F_11 ( V_11 ) > V_17 -> V_31 ) {
if ( F_22 ( V_11 ) && F_4 ( V_11 ) <= V_17 -> V_31 )
return F_8 ( V_11 , V_14 , V_15 ) ;
return F_14 ( V_11 , V_14 , V_15 ) ;
}
V_22 = F_16 ( V_11 , V_17 -> V_27 , V_15 ) ;
if ( V_22 != V_28 ) {
if ( F_17 ( V_22 ) )
F_18 ( V_14 ) ;
return V_22 ;
}
F_23 ( V_14 , V_11 ) ;
V_14 -> V_17 . V_29 ++ ;
return V_28 ;
}
static bool F_24 ( const struct V_16 * V_17 )
{
return V_17 -> V_32 . V_5 ;
}
static struct V_10 * F_25 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
struct V_10 * V_11 ;
V_11 = V_17 -> V_27 -> V_33 -> V_34 ( V_17 -> V_27 ) ;
if ( V_11 ) {
T_3 V_35 ;
T_3 V_36 ;
T_3 V_37 = 0 ;
unsigned int V_4 = F_11 ( V_11 ) ;
V_35 = F_26 () ;
V_36 = F_27 ( T_3 , V_35 - V_17 -> V_38 , V_17 -> V_39 ) ;
if ( F_24 ( V_17 ) ) {
V_37 = V_36 + V_17 -> V_40 ;
if ( V_37 > V_17 -> V_41 )
V_37 = V_17 -> V_41 ;
V_37 -= ( T_3 ) F_28 ( & V_17 -> V_32 , V_4 ) ;
}
V_36 += V_17 -> V_42 ;
if ( V_36 > V_17 -> V_39 )
V_36 = V_17 -> V_39 ;
V_36 -= ( T_3 ) F_28 ( & V_17 -> V_43 , V_4 ) ;
if ( ( V_36 | V_37 ) >= 0 ) {
V_11 = F_29 ( V_17 -> V_27 ) ;
if ( F_3 ( ! V_11 ) )
return NULL ;
V_17 -> V_38 = V_35 ;
V_17 -> V_42 = V_36 ;
V_17 -> V_40 = V_37 ;
F_30 ( V_14 , V_11 ) ;
V_14 -> V_17 . V_29 -- ;
F_31 ( V_14 , V_11 ) ;
return V_11 ;
}
F_32 ( & V_17 -> V_44 ,
V_35 + F_33 ( long , - V_36 , - V_37 ) ) ;
F_34 ( V_14 ) ;
}
return NULL ;
}
static void F_35 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
F_36 ( V_17 -> V_27 ) ;
V_14 -> V_45 . V_46 = 0 ;
V_14 -> V_17 . V_29 = 0 ;
V_17 -> V_38 = F_26 () ;
V_17 -> V_42 = V_17 -> V_39 ;
V_17 -> V_40 = V_17 -> V_41 ;
F_37 ( & V_17 -> V_44 ) ;
}
static int F_38 ( struct V_13 * V_14 , struct V_47 * V_48 )
{
int V_49 ;
struct V_16 * V_17 = F_9 ( V_14 ) ;
struct V_47 * V_50 [ V_51 + 1 ] ;
struct V_52 * V_53 ;
struct V_13 * V_54 = NULL ;
struct V_1 V_43 ;
struct V_1 V_32 ;
T_1 V_31 ;
T_3 V_39 , V_41 ;
T_1 V_55 = 0 , V_56 = 0 ;
V_49 = F_39 ( V_50 , V_51 , V_48 , V_57 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = - V_58 ;
if ( V_50 [ V_59 ] == NULL )
goto V_60;
V_53 = F_40 ( V_50 [ V_59 ] ) ;
if ( V_53 -> V_43 . V_7 == V_61 )
F_41 ( F_42 ( & V_53 -> V_43 ,
V_50 [ V_62 ] ) ) ;
if ( V_53 -> V_63 . V_7 == V_61 )
F_41 ( F_42 ( & V_53 -> V_63 ,
V_50 [ V_64 ] ) ) ;
V_39 = F_27 ( T_1 , F_43 ( V_53 -> V_39 ) , ~ 0U ) ;
V_41 = F_27 ( T_1 , F_43 ( V_53 -> V_41 ) , ~ 0U ) ;
if ( V_50 [ V_65 ] )
V_55 = F_44 ( V_50 [ V_65 ] ) ;
F_45 ( & V_43 , & V_53 -> V_43 , V_55 ) ;
if ( V_50 [ V_66 ] ) {
V_31 = F_46 ( V_50 [ V_66 ] ) ;
V_39 = F_28 ( & V_43 , V_31 ) ;
} else {
V_31 = F_27 ( T_1 , F_1 ( & V_43 , V_39 ) , ~ 0U ) ;
}
if ( V_53 -> V_63 . V_43 ) {
if ( V_50 [ V_67 ] )
V_56 = F_44 ( V_50 [ V_67 ] ) ;
F_45 ( & V_32 , & V_53 -> V_63 , V_56 ) ;
if ( V_32 . V_5 <= V_43 . V_5 ) {
F_47 ( L_1 ,
V_32 . V_5 , V_43 . V_5 ) ;
V_49 = - V_58 ;
goto V_60;
}
if ( V_50 [ V_68 ] ) {
T_4 V_69 = F_46 ( V_50 [ V_68 ] ) ;
V_31 = F_27 ( T_4 , V_31 , V_69 ) ;
V_41 = F_28 ( & V_32 , V_69 ) ;
} else {
V_31 = F_27 ( T_1 , V_31 , F_1 ( & V_32 , V_41 ) ) ;
}
} else {
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
}
if ( V_31 < F_48 ( F_49 ( V_14 ) ) )
F_47 ( L_2 ,
V_31 , F_49 ( V_14 ) -> V_70 ,
F_48 ( F_49 ( V_14 ) ) ) ;
if ( ! V_31 ) {
V_49 = - V_58 ;
goto V_60;
}
if ( V_17 -> V_27 != & V_71 ) {
V_49 = F_50 ( V_17 -> V_27 , V_53 -> V_72 ) ;
if ( V_49 )
goto V_60;
} else if ( V_53 -> V_72 > 0 ) {
V_54 = F_51 ( V_14 , & V_73 , V_53 -> V_72 ) ;
if ( F_52 ( V_54 ) ) {
V_49 = F_53 ( V_54 ) ;
goto V_60;
}
}
F_54 ( V_14 ) ;
if ( V_54 ) {
F_19 ( V_17 -> V_27 , V_17 -> V_27 -> V_17 . V_29 ,
V_17 -> V_27 -> V_45 . V_46 ) ;
F_55 ( V_17 -> V_27 ) ;
V_17 -> V_27 = V_54 ;
}
V_17 -> V_72 = V_53 -> V_72 ;
if ( V_50 [ V_68 ] )
V_17 -> V_41 = V_41 ;
else
V_17 -> V_41 = F_43 ( V_53 -> V_41 ) ;
V_17 -> V_31 = V_31 ;
if ( V_50 [ V_66 ] )
V_17 -> V_39 = V_39 ;
else
V_17 -> V_39 = F_43 ( V_53 -> V_39 ) ;
V_17 -> V_42 = V_17 -> V_39 ;
V_17 -> V_40 = V_17 -> V_41 ;
memcpy ( & V_17 -> V_43 , & V_43 , sizeof( struct V_1 ) ) ;
memcpy ( & V_17 -> V_32 , & V_32 , sizeof( struct V_1 ) ) ;
F_56 ( V_14 ) ;
V_49 = 0 ;
V_60:
return V_49 ;
}
static int F_57 ( struct V_13 * V_14 , struct V_47 * V_48 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
if ( V_48 == NULL )
return - V_58 ;
V_17 -> V_38 = F_26 () ;
F_58 ( & V_17 -> V_44 , V_14 ) ;
V_17 -> V_27 = & V_71 ;
return F_38 ( V_14 , V_48 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
F_37 ( & V_17 -> V_44 ) ;
F_55 ( V_17 -> V_27 ) ;
}
static int F_60 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
struct V_47 * V_74 ;
struct V_52 V_48 ;
V_14 -> V_45 . V_46 = V_17 -> V_27 -> V_45 . V_46 ;
V_74 = F_61 ( V_11 , V_75 ) ;
if ( V_74 == NULL )
goto V_76;
V_48 . V_72 = V_17 -> V_72 ;
F_62 ( & V_48 . V_43 , & V_17 -> V_43 ) ;
if ( F_24 ( V_17 ) )
F_62 ( & V_48 . V_63 , & V_17 -> V_32 ) ;
else
memset ( & V_48 . V_63 , 0 , sizeof( V_48 . V_63 ) ) ;
V_48 . V_41 = F_63 ( V_17 -> V_41 ) ;
V_48 . V_39 = F_63 ( V_17 -> V_39 ) ;
if ( F_64 ( V_11 , V_59 , sizeof( V_48 ) , & V_48 ) )
goto V_76;
if ( V_17 -> V_43 . V_5 >= ( 1ULL << 32 ) &&
F_65 ( V_11 , V_65 , V_17 -> V_43 . V_5 ,
V_77 ) )
goto V_76;
if ( F_24 ( V_17 ) &&
V_17 -> V_32 . V_5 >= ( 1ULL << 32 ) &&
F_65 ( V_11 , V_67 , V_17 -> V_32 . V_5 ,
V_77 ) )
goto V_76;
return F_66 ( V_11 , V_74 ) ;
V_76:
F_67 ( V_11 , V_74 ) ;
return - 1 ;
}
static int F_68 ( struct V_13 * V_14 , unsigned long V_78 ,
struct V_10 * V_11 , struct V_79 * V_80 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
V_80 -> V_81 |= F_69 ( 1 ) ;
V_80 -> V_82 = V_17 -> V_27 -> V_83 ;
return 0 ;
}
static int F_70 ( struct V_13 * V_14 , unsigned long V_84 , struct V_13 * V_85 ,
struct V_13 * * V_86 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
if ( V_85 == NULL )
V_85 = & V_71 ;
* V_86 = F_71 ( V_14 , V_85 , & V_17 -> V_27 ) ;
return 0 ;
}
static struct V_13 * F_72 ( struct V_13 * V_14 , unsigned long V_84 )
{
struct V_16 * V_17 = F_9 ( V_14 ) ;
return V_17 -> V_27 ;
}
static unsigned long F_73 ( struct V_13 * V_14 , T_4 V_87 )
{
return 1 ;
}
static void F_74 ( struct V_13 * V_14 , unsigned long V_84 )
{
}
static void F_75 ( struct V_13 * V_14 , struct V_88 * V_89 )
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
static int T_5 F_76 ( void )
{
return F_77 ( & V_94 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_94 ) ;
}
