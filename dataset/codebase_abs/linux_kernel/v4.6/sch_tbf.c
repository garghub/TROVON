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
unsigned int V_4 = 0 , V_20 = F_11 ( V_11 ) ;
int V_21 , V_22 ;
V_17 = F_12 ( V_11 , V_19 & ~ V_23 ) ;
if ( F_13 ( V_17 ) )
return F_14 ( V_11 , V_14 ) ;
V_22 = 0 ;
while ( V_17 ) {
V_18 = V_17 -> V_24 ;
V_17 -> V_24 = NULL ;
F_15 ( V_17 ) -> V_25 = V_17 -> V_4 ;
V_4 += V_17 -> V_4 ;
V_21 = F_16 ( V_17 , V_16 -> V_26 ) ;
if ( V_21 != V_27 ) {
if ( F_17 ( V_21 ) )
F_18 ( V_14 ) ;
} else {
V_22 ++ ;
}
V_17 = V_18 ;
}
V_14 -> V_16 . V_28 += V_22 ;
if ( V_22 > 1 )
F_19 ( V_14 , 1 - V_22 , V_20 - V_4 ) ;
F_20 ( V_11 ) ;
return V_22 > 0 ? V_27 : V_29 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
int V_21 ;
if ( F_11 ( V_11 ) > V_16 -> V_30 ) {
if ( F_22 ( V_11 ) && F_4 ( V_11 ) <= V_16 -> V_30 )
return F_8 ( V_11 , V_14 ) ;
return F_14 ( V_11 , V_14 ) ;
}
V_21 = F_16 ( V_11 , V_16 -> V_26 ) ;
if ( V_21 != V_27 ) {
if ( F_17 ( V_21 ) )
F_18 ( V_14 ) ;
return V_21 ;
}
V_14 -> V_16 . V_28 ++ ;
return V_27 ;
}
static unsigned int F_23 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
unsigned int V_4 = 0 ;
if ( V_16 -> V_26 -> V_31 -> V_32 && ( V_4 = V_16 -> V_26 -> V_31 -> V_32 ( V_16 -> V_26 ) ) != 0 ) {
V_14 -> V_16 . V_28 -- ;
F_18 ( V_14 ) ;
}
return V_4 ;
}
static bool F_24 ( const struct V_15 * V_16 )
{
return V_16 -> V_33 . V_5 ;
}
static struct V_10 * F_25 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_10 * V_11 ;
V_11 = V_16 -> V_26 -> V_31 -> V_34 ( V_16 -> V_26 ) ;
if ( V_11 ) {
T_3 V_35 ;
T_3 V_36 ;
T_3 V_37 = 0 ;
unsigned int V_4 = F_11 ( V_11 ) ;
V_35 = F_26 () ;
V_36 = F_27 ( T_3 , V_35 - V_16 -> V_38 , V_16 -> V_39 ) ;
if ( F_24 ( V_16 ) ) {
V_37 = V_36 + V_16 -> V_40 ;
if ( V_37 > V_16 -> V_41 )
V_37 = V_16 -> V_41 ;
V_37 -= ( T_3 ) F_28 ( & V_16 -> V_33 , V_4 ) ;
}
V_36 += V_16 -> V_42 ;
if ( V_36 > V_16 -> V_39 )
V_36 = V_16 -> V_39 ;
V_36 -= ( T_3 ) F_28 ( & V_16 -> V_43 , V_4 ) ;
if ( ( V_36 | V_37 ) >= 0 ) {
V_11 = F_29 ( V_16 -> V_26 ) ;
if ( F_3 ( ! V_11 ) )
return NULL ;
V_16 -> V_38 = V_35 ;
V_16 -> V_42 = V_36 ;
V_16 -> V_40 = V_37 ;
V_14 -> V_16 . V_28 -- ;
F_30 ( V_14 ) ;
F_31 ( V_14 , V_11 ) ;
return V_11 ;
}
F_32 ( & V_16 -> V_44 ,
V_35 + F_33 ( long , - V_36 , - V_37 ) ,
true ) ;
F_34 ( V_14 ) ;
}
return NULL ;
}
static void F_35 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_36 ( V_16 -> V_26 ) ;
V_14 -> V_16 . V_28 = 0 ;
V_16 -> V_38 = F_26 () ;
V_16 -> V_42 = V_16 -> V_39 ;
V_16 -> V_40 = V_16 -> V_41 ;
F_37 ( & V_16 -> V_44 ) ;
}
static int F_38 ( struct V_13 * V_14 , struct V_45 * V_46 )
{
int V_47 ;
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_45 * V_48 [ V_49 + 1 ] ;
struct V_50 * V_51 ;
struct V_13 * V_52 = NULL ;
struct V_1 V_43 ;
struct V_1 V_33 ;
T_1 V_30 ;
T_3 V_39 , V_41 ;
T_1 V_53 = 0 , V_54 = 0 ;
V_47 = F_39 ( V_48 , V_49 , V_46 , V_55 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = - V_56 ;
if ( V_48 [ V_57 ] == NULL )
goto V_58;
V_51 = F_40 ( V_48 [ V_57 ] ) ;
if ( V_51 -> V_43 . V_7 == V_59 )
F_41 ( F_42 ( & V_51 -> V_43 ,
V_48 [ V_60 ] ) ) ;
if ( V_51 -> V_61 . V_7 == V_59 )
F_41 ( F_42 ( & V_51 -> V_61 ,
V_48 [ V_62 ] ) ) ;
V_39 = F_27 ( T_1 , F_43 ( V_51 -> V_39 ) , ~ 0U ) ;
V_41 = F_27 ( T_1 , F_43 ( V_51 -> V_41 ) , ~ 0U ) ;
if ( V_48 [ V_63 ] )
V_53 = F_44 ( V_48 [ V_63 ] ) ;
F_45 ( & V_43 , & V_51 -> V_43 , V_53 ) ;
if ( V_48 [ V_64 ] ) {
V_30 = F_46 ( V_48 [ V_64 ] ) ;
V_39 = F_28 ( & V_43 , V_30 ) ;
} else {
V_30 = F_27 ( T_1 , F_1 ( & V_43 , V_39 ) , ~ 0U ) ;
}
if ( V_51 -> V_61 . V_43 ) {
if ( V_48 [ V_65 ] )
V_54 = F_44 ( V_48 [ V_65 ] ) ;
F_45 ( & V_33 , & V_51 -> V_61 , V_54 ) ;
if ( V_33 . V_5 <= V_43 . V_5 ) {
F_47 ( L_1 ,
V_33 . V_5 , V_43 . V_5 ) ;
V_47 = - V_56 ;
goto V_58;
}
if ( V_48 [ V_66 ] ) {
T_4 V_67 = F_46 ( V_48 [ V_66 ] ) ;
V_30 = F_27 ( T_4 , V_30 , V_67 ) ;
V_41 = F_28 ( & V_33 , V_67 ) ;
} else {
V_30 = F_27 ( T_1 , V_30 , F_1 ( & V_33 , V_41 ) ) ;
}
} else {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
}
if ( V_30 < F_48 ( F_49 ( V_14 ) ) )
F_47 ( L_2 ,
V_30 , F_49 ( V_14 ) -> V_68 ,
F_48 ( F_49 ( V_14 ) ) ) ;
if ( ! V_30 ) {
V_47 = - V_56 ;
goto V_58;
}
if ( V_16 -> V_26 != & V_69 ) {
V_47 = F_50 ( V_16 -> V_26 , V_51 -> V_70 ) ;
if ( V_47 )
goto V_58;
} else if ( V_51 -> V_70 > 0 ) {
V_52 = F_51 ( V_14 , & V_71 , V_51 -> V_70 ) ;
if ( F_52 ( V_52 ) ) {
V_47 = F_53 ( V_52 ) ;
goto V_58;
}
}
F_54 ( V_14 ) ;
if ( V_52 ) {
F_19 ( V_16 -> V_26 , V_16 -> V_26 -> V_16 . V_28 ,
V_16 -> V_26 -> V_72 . V_73 ) ;
F_55 ( V_16 -> V_26 ) ;
V_16 -> V_26 = V_52 ;
}
V_16 -> V_70 = V_51 -> V_70 ;
if ( V_48 [ V_66 ] )
V_16 -> V_41 = V_41 ;
else
V_16 -> V_41 = F_43 ( V_51 -> V_41 ) ;
V_16 -> V_30 = V_30 ;
if ( V_48 [ V_64 ] )
V_16 -> V_39 = V_39 ;
else
V_16 -> V_39 = F_43 ( V_51 -> V_39 ) ;
V_16 -> V_42 = V_16 -> V_39 ;
V_16 -> V_40 = V_16 -> V_41 ;
memcpy ( & V_16 -> V_43 , & V_43 , sizeof( struct V_1 ) ) ;
memcpy ( & V_16 -> V_33 , & V_33 , sizeof( struct V_1 ) ) ;
F_56 ( V_14 ) ;
V_47 = 0 ;
V_58:
return V_47 ;
}
static int F_57 ( struct V_13 * V_14 , struct V_45 * V_46 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_46 == NULL )
return - V_56 ;
V_16 -> V_38 = F_26 () ;
F_58 ( & V_16 -> V_44 , V_14 ) ;
V_16 -> V_26 = & V_69 ;
return F_38 ( V_14 , V_46 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_37 ( & V_16 -> V_44 ) ;
F_55 ( V_16 -> V_26 ) ;
}
static int F_60 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_45 * V_74 ;
struct V_50 V_46 ;
V_14 -> V_72 . V_73 = V_16 -> V_26 -> V_72 . V_73 ;
V_74 = F_61 ( V_11 , V_75 ) ;
if ( V_74 == NULL )
goto V_76;
V_46 . V_70 = V_16 -> V_70 ;
F_62 ( & V_46 . V_43 , & V_16 -> V_43 ) ;
if ( F_24 ( V_16 ) )
F_62 ( & V_46 . V_61 , & V_16 -> V_33 ) ;
else
memset ( & V_46 . V_61 , 0 , sizeof( V_46 . V_61 ) ) ;
V_46 . V_41 = F_63 ( V_16 -> V_41 ) ;
V_46 . V_39 = F_63 ( V_16 -> V_39 ) ;
if ( F_64 ( V_11 , V_57 , sizeof( V_46 ) , & V_46 ) )
goto V_76;
if ( V_16 -> V_43 . V_5 >= ( 1ULL << 32 ) &&
F_65 ( V_11 , V_63 , V_16 -> V_43 . V_5 ) )
goto V_76;
if ( F_24 ( V_16 ) &&
V_16 -> V_33 . V_5 >= ( 1ULL << 32 ) &&
F_65 ( V_11 , V_65 , V_16 -> V_33 . V_5 ) )
goto V_76;
return F_66 ( V_11 , V_74 ) ;
V_76:
F_67 ( V_11 , V_74 ) ;
return - 1 ;
}
static int F_68 ( struct V_13 * V_14 , unsigned long V_77 ,
struct V_10 * V_11 , struct V_78 * V_79 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
V_79 -> V_80 |= F_69 ( 1 ) ;
V_79 -> V_81 = V_16 -> V_26 -> V_82 ;
return 0 ;
}
static int F_70 ( struct V_13 * V_14 , unsigned long V_83 , struct V_13 * V_84 ,
struct V_13 * * V_85 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_84 == NULL )
V_84 = & V_69 ;
* V_85 = F_71 ( V_14 , V_84 , & V_16 -> V_26 ) ;
return 0 ;
}
static struct V_13 * F_72 ( struct V_13 * V_14 , unsigned long V_83 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
return V_16 -> V_26 ;
}
static unsigned long F_73 ( struct V_13 * V_14 , T_4 V_86 )
{
return 1 ;
}
static void F_74 ( struct V_13 * V_14 , unsigned long V_83 )
{
}
static void F_75 ( struct V_13 * V_14 , struct V_87 * V_88 )
{
if ( ! V_88 -> V_89 ) {
if ( V_88 -> V_90 >= V_88 -> V_91 )
if ( V_88 -> V_92 ( V_14 , 1 , V_88 ) < 0 ) {
V_88 -> V_89 = 1 ;
return;
}
V_88 -> V_90 ++ ;
}
}
static int T_5 F_76 ( void )
{
return F_77 ( & V_93 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_93 ) ;
}
