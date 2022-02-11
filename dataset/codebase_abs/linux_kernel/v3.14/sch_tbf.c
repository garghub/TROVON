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
static struct V_10 * F_23 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_10 * V_11 ;
V_11 = V_16 -> V_25 -> V_32 -> V_34 ( V_16 -> V_25 ) ;
if ( V_11 ) {
T_3 V_35 ;
T_3 V_36 ;
T_3 V_37 = 0 ;
unsigned int V_4 = F_20 ( V_11 ) ;
V_35 = F_24 ( F_25 () ) ;
V_36 = F_26 ( T_3 , V_35 - V_16 -> V_38 , V_16 -> V_39 ) ;
if ( V_16 -> V_40 ) {
V_37 = V_36 + V_16 -> V_41 ;
if ( V_37 > V_16 -> V_42 )
V_37 = V_16 -> V_42 ;
V_37 -= ( T_3 ) F_27 ( & V_16 -> V_43 , V_4 ) ;
}
V_36 += V_16 -> V_44 ;
if ( V_36 > V_16 -> V_39 )
V_36 = V_16 -> V_39 ;
V_36 -= ( T_3 ) F_27 ( & V_16 -> V_45 , V_4 ) ;
if ( ( V_36 | V_37 ) >= 0 ) {
V_11 = F_28 ( V_16 -> V_25 ) ;
if ( F_3 ( ! V_11 ) )
return NULL ;
V_16 -> V_38 = V_35 ;
V_16 -> V_44 = V_36 ;
V_16 -> V_41 = V_37 ;
V_14 -> V_16 . V_29 -- ;
F_29 ( V_14 ) ;
F_30 ( V_14 , V_11 ) ;
return V_11 ;
}
F_31 ( & V_16 -> V_46 ,
V_35 + F_32 ( long , - V_36 , - V_37 ) ) ;
V_14 -> V_27 . V_47 ++ ;
}
return NULL ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_34 ( V_16 -> V_25 ) ;
V_14 -> V_16 . V_29 = 0 ;
V_16 -> V_38 = F_24 ( F_25 () ) ;
V_16 -> V_44 = V_16 -> V_39 ;
V_16 -> V_41 = V_16 -> V_42 ;
F_35 ( & V_16 -> V_46 ) ;
}
static int F_36 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
int V_50 ;
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_48 * V_51 [ V_52 + 1 ] ;
struct V_53 * V_54 ;
struct V_13 * V_55 = NULL ;
struct V_1 V_45 ;
struct V_1 V_43 ;
T_1 V_31 ;
T_3 V_39 , V_42 ;
T_1 V_56 = 0 , V_57 = 0 ;
V_50 = F_37 ( V_51 , V_52 , V_49 , V_58 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = - V_59 ;
if ( V_51 [ V_60 ] == NULL )
goto V_61;
V_54 = F_38 ( V_51 [ V_60 ] ) ;
if ( V_54 -> V_45 . V_7 == V_62 )
F_39 ( F_40 ( & V_54 -> V_45 ,
V_51 [ V_63 ] ) ) ;
if ( V_54 -> V_64 . V_7 == V_62 )
F_39 ( F_40 ( & V_54 -> V_64 ,
V_51 [ V_65 ] ) ) ;
V_39 = F_26 ( T_1 , F_41 ( V_54 -> V_39 ) , ~ 0U ) ;
V_42 = F_26 ( T_1 , F_41 ( V_54 -> V_42 ) , ~ 0U ) ;
if ( V_51 [ V_66 ] )
V_56 = F_42 ( V_51 [ V_66 ] ) ;
F_43 ( & V_45 , & V_54 -> V_45 , V_56 ) ;
if ( V_51 [ V_67 ] ) {
V_31 = F_44 ( V_51 [ V_67 ] ) ;
V_39 = F_27 ( & V_45 , V_31 ) ;
} else {
V_31 = F_26 ( T_1 , F_1 ( & V_45 , V_39 ) , ~ 0U ) ;
}
if ( V_54 -> V_64 . V_45 ) {
if ( V_51 [ V_68 ] )
V_57 = F_42 ( V_51 [ V_68 ] ) ;
F_43 ( & V_43 , & V_54 -> V_64 , V_57 ) ;
if ( V_43 . V_5 <= V_45 . V_5 ) {
F_45 ( L_1 ,
V_43 . V_5 , V_45 . V_5 ) ;
V_50 = - V_59 ;
goto V_61;
}
if ( V_51 [ V_69 ] ) {
T_4 V_70 = F_44 ( V_51 [ V_69 ] ) ;
V_31 = F_26 ( T_4 , V_31 , V_70 ) ;
V_42 = F_27 ( & V_43 , V_70 ) ;
} else {
V_31 = F_26 ( T_1 , V_31 , F_1 ( & V_43 , V_42 ) ) ;
}
}
if ( V_31 < F_46 ( F_47 ( V_14 ) ) )
F_45 ( L_2 ,
V_31 , F_47 ( V_14 ) -> V_71 ,
F_46 ( F_47 ( V_14 ) ) ) ;
if ( ! V_31 ) {
V_50 = - V_59 ;
goto V_61;
}
if ( V_16 -> V_25 != & V_72 ) {
V_50 = F_48 ( V_16 -> V_25 , V_54 -> V_73 ) ;
if ( V_50 )
goto V_61;
} else if ( V_54 -> V_73 > 0 ) {
V_55 = F_49 ( V_14 , & V_74 , V_54 -> V_73 ) ;
if ( F_50 ( V_55 ) ) {
V_50 = F_51 ( V_55 ) ;
goto V_61;
}
}
F_52 ( V_14 ) ;
if ( V_55 ) {
F_17 ( V_16 -> V_25 , V_16 -> V_25 -> V_16 . V_29 ) ;
F_53 ( V_16 -> V_25 ) ;
V_16 -> V_25 = V_55 ;
}
V_16 -> V_73 = V_54 -> V_73 ;
if ( V_51 [ V_69 ] )
V_16 -> V_42 = V_42 ;
else
V_16 -> V_42 = F_41 ( V_54 -> V_42 ) ;
V_16 -> V_31 = V_31 ;
if ( V_51 [ V_67 ] )
V_16 -> V_39 = V_39 ;
else
V_16 -> V_39 = F_41 ( V_54 -> V_39 ) ;
V_16 -> V_44 = V_16 -> V_39 ;
V_16 -> V_41 = V_16 -> V_42 ;
memcpy ( & V_16 -> V_45 , & V_45 , sizeof( struct V_1 ) ) ;
if ( V_54 -> V_64 . V_45 ) {
memcpy ( & V_16 -> V_43 , & V_43 , sizeof( struct V_1 ) ) ;
V_16 -> V_40 = true ;
} else {
V_16 -> V_40 = false ;
}
F_54 ( V_14 ) ;
V_50 = 0 ;
V_61:
return V_50 ;
}
static int F_55 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_49 == NULL )
return - V_59 ;
V_16 -> V_38 = F_24 ( F_25 () ) ;
F_56 ( & V_16 -> V_46 , V_14 ) ;
V_16 -> V_25 = & V_72 ;
return F_36 ( V_14 , V_49 ) ;
}
static void F_57 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
F_35 ( & V_16 -> V_46 ) ;
F_53 ( V_16 -> V_25 ) ;
}
static int F_58 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
struct V_48 * V_75 ;
struct V_53 V_49 ;
V_14 -> V_27 . V_76 = V_16 -> V_25 -> V_27 . V_76 ;
V_75 = F_59 ( V_11 , V_77 ) ;
if ( V_75 == NULL )
goto V_78;
V_49 . V_73 = V_16 -> V_73 ;
F_60 ( & V_49 . V_45 , & V_16 -> V_45 ) ;
if ( V_16 -> V_40 )
F_60 ( & V_49 . V_64 , & V_16 -> V_43 ) ;
else
memset ( & V_49 . V_64 , 0 , sizeof( V_49 . V_64 ) ) ;
V_49 . V_42 = F_61 ( V_16 -> V_42 ) ;
V_49 . V_39 = F_61 ( V_16 -> V_39 ) ;
if ( F_62 ( V_11 , V_60 , sizeof( V_49 ) , & V_49 ) )
goto V_78;
if ( V_16 -> V_45 . V_5 >= ( 1ULL << 32 ) &&
F_63 ( V_11 , V_66 , V_16 -> V_45 . V_5 ) )
goto V_78;
if ( V_16 -> V_40 &&
V_16 -> V_43 . V_5 >= ( 1ULL << 32 ) &&
F_63 ( V_11 , V_68 , V_16 -> V_43 . V_5 ) )
goto V_78;
F_64 ( V_11 , V_75 ) ;
return V_11 -> V_4 ;
V_78:
F_65 ( V_11 , V_75 ) ;
return - 1 ;
}
static int F_66 ( struct V_13 * V_14 , unsigned long V_79 ,
struct V_10 * V_11 , struct V_80 * V_81 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
V_81 -> V_82 |= F_67 ( 1 ) ;
V_81 -> V_83 = V_16 -> V_25 -> V_84 ;
return 0 ;
}
static int F_68 ( struct V_13 * V_14 , unsigned long V_85 , struct V_13 * V_86 ,
struct V_13 * * V_87 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
if ( V_86 == NULL )
V_86 = & V_72 ;
F_52 ( V_14 ) ;
* V_87 = V_16 -> V_25 ;
V_16 -> V_25 = V_86 ;
F_17 ( * V_87 , ( * V_87 ) -> V_16 . V_29 ) ;
F_34 ( * V_87 ) ;
F_54 ( V_14 ) ;
return 0 ;
}
static struct V_13 * F_69 ( struct V_13 * V_14 , unsigned long V_85 )
{
struct V_15 * V_16 = F_9 ( V_14 ) ;
return V_16 -> V_25 ;
}
static unsigned long F_70 ( struct V_13 * V_14 , T_4 V_88 )
{
return 1 ;
}
static void F_71 ( struct V_13 * V_14 , unsigned long V_85 )
{
}
static void F_72 ( struct V_13 * V_14 , struct V_89 * V_90 )
{
if ( ! V_90 -> V_91 ) {
if ( V_90 -> V_92 >= V_90 -> V_93 )
if ( V_90 -> V_94 ( V_14 , 1 , V_90 ) < 0 ) {
V_90 -> V_91 = 1 ;
return;
}
V_90 -> V_92 ++ ;
}
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_95 ) ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_95 ) ;
}
