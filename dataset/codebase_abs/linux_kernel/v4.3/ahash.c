static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
unsigned int V_7 = V_6 -> V_7 ;
unsigned int V_8 = V_6 -> V_8 ;
unsigned int V_9 = F_5 ( V_6 -> V_10 ,
( ( unsigned int ) ( V_11 ) ) - V_8 ) ;
if ( V_6 -> V_12 & V_13 )
V_6 -> V_14 = F_6 ( V_6 -> V_15 ) ;
else
V_6 -> V_14 = F_7 ( V_6 -> V_15 ) ;
V_6 -> V_14 += V_8 ;
if ( V_8 & V_7 ) {
unsigned int V_16 = V_7 + 1 - ( V_8 & V_7 ) ;
if ( V_9 > V_16 )
V_9 = V_16 ;
}
V_6 -> V_10 -= V_9 ;
return V_9 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_17 * V_18 ;
V_18 = V_6 -> V_18 ;
V_6 -> V_15 = F_9 ( V_18 ) ;
V_6 -> V_8 = V_18 -> V_8 ;
V_6 -> V_10 = V_18 -> V_19 ;
if ( V_6 -> V_10 > V_6 -> V_20 )
V_6 -> V_10 = V_6 -> V_20 ;
V_6 -> V_20 -= V_6 -> V_10 ;
return F_4 ( V_6 ) ;
}
int F_10 ( struct V_5 * V_6 , int V_21 )
{
unsigned int V_7 = V_6 -> V_7 ;
unsigned int V_9 = V_6 -> V_10 ;
V_6 -> V_14 -= V_6 -> V_8 ;
if ( V_9 && V_6 -> V_8 & V_7 && ! V_21 ) {
V_6 -> V_8 = F_11 ( V_6 -> V_8 , V_7 + 1 ) ;
V_6 -> V_14 += V_6 -> V_8 ;
V_9 = F_5 ( V_9 ,
( ( unsigned int ) ( V_11 ) ) - V_6 -> V_8 ) ;
V_6 -> V_10 -= V_9 ;
return V_9 ;
}
if ( V_6 -> V_12 & V_13 )
F_12 ( V_6 -> V_15 ) ;
else {
F_13 ( V_6 -> V_14 ) ;
F_14 ( V_6 -> V_12 ) ;
}
if ( V_21 )
return V_21 ;
if ( V_9 ) {
V_6 -> V_8 = 0 ;
V_6 -> V_15 ++ ;
return F_4 ( V_6 ) ;
}
if ( ! V_6 -> V_20 )
return 0 ;
V_6 -> V_18 = F_15 ( V_6 -> V_18 ) ;
return F_8 ( V_6 ) ;
}
int F_16 ( struct V_22 * V_23 ,
struct V_5 * V_6 )
{
V_6 -> V_20 = V_23 -> V_9 ;
if ( ! V_6 -> V_20 ) {
V_6 -> V_10 = 0 ;
return 0 ;
}
V_6 -> V_7 = F_17 ( F_18 ( V_23 ) ) ;
V_6 -> V_18 = V_23 -> V_24 ;
V_6 -> V_12 = V_23 -> V_25 . V_12 & V_26 ;
return F_8 ( V_6 ) ;
}
int F_19 ( struct V_22 * V_23 ,
struct V_5 * V_6 )
{
V_6 -> V_20 = V_23 -> V_9 ;
if ( ! V_6 -> V_20 ) {
V_6 -> V_10 = 0 ;
return 0 ;
}
V_6 -> V_7 = F_17 ( F_18 ( V_23 ) ) ;
V_6 -> V_18 = V_23 -> V_24 ;
V_6 -> V_12 = V_23 -> V_25 . V_12 & V_26 ;
V_6 -> V_12 |= V_13 ;
F_20 ( V_26 & V_13 ) ;
return F_8 ( V_6 ) ;
}
int F_21 ( struct V_27 * V_28 ,
struct V_5 * V_6 ,
struct V_17 * V_18 , unsigned int V_29 )
{
V_6 -> V_20 = V_29 ;
if ( ! V_6 -> V_20 ) {
V_6 -> V_10 = 0 ;
return 0 ;
}
V_6 -> V_7 = F_22 ( V_28 -> V_30 ) ;
V_6 -> V_18 = V_18 ;
V_6 -> V_12 = V_28 -> V_12 & V_26 ;
return F_8 ( V_6 ) ;
}
static int F_23 ( struct V_2 * V_30 , const T_1 * V_31 ,
unsigned int V_32 )
{
unsigned long V_7 = F_17 ( V_30 ) ;
int V_33 ;
T_1 * V_34 , * V_35 ;
unsigned long V_36 ;
V_36 = V_32 + V_7 ;
V_34 = F_24 ( V_36 , V_37 ) ;
if ( ! V_34 )
return - V_38 ;
V_35 = ( T_1 * ) F_11 ( ( unsigned long ) V_34 , V_7 + 1 ) ;
memcpy ( V_35 , V_31 , V_32 ) ;
V_33 = V_30 -> V_39 ( V_30 , V_35 , V_32 ) ;
F_25 ( V_34 ) ;
return V_33 ;
}
int F_26 ( struct V_2 * V_30 , const T_1 * V_31 ,
unsigned int V_32 )
{
unsigned long V_7 = F_17 ( V_30 ) ;
if ( ( unsigned long ) V_31 & V_7 )
return F_23 ( V_30 , V_31 , V_32 ) ;
return V_30 -> V_39 ( V_30 , V_31 , V_32 ) ;
}
static int F_27 ( struct V_2 * V_30 , const T_1 * V_31 ,
unsigned int V_32 )
{
return - V_40 ;
}
static inline unsigned int F_28 ( unsigned V_29 ,
unsigned long V_41 )
{
return V_29 + ( V_41 & ~ ( F_29 () - 1 ) ) ;
}
static int F_30 ( struct V_22 * V_23 , T_2 V_42 )
{
struct V_2 * V_30 = F_18 ( V_23 ) ;
unsigned long V_7 = F_17 ( V_30 ) ;
unsigned int V_43 = F_31 ( V_30 ) ;
struct V_44 * V_45 ;
V_45 = F_24 ( sizeof( * V_45 ) + F_28 ( V_43 , V_7 ) ,
( V_23 -> V_25 . V_12 & V_46 ) ?
V_37 : V_47 ) ;
if ( ! V_45 )
return - V_38 ;
V_45 -> V_48 = V_23 -> V_48 ;
V_45 -> V_49 = V_23 -> V_25 . V_49 ;
V_45 -> V_14 = V_23 -> V_25 . V_14 ;
V_23 -> V_48 = F_32 ( ( T_1 * ) V_45 -> V_50 , V_7 + 1 ) ;
V_23 -> V_25 . V_49 = V_42 ;
V_23 -> V_25 . V_14 = V_23 ;
V_23 -> V_45 = V_45 ;
return 0 ;
}
static void F_33 ( struct V_22 * V_23 )
{
struct V_44 * V_45 = V_23 -> V_45 ;
V_23 -> V_48 = V_45 -> V_48 ;
V_23 -> V_25 . V_49 = V_45 -> V_49 ;
V_23 -> V_25 . V_14 = V_45 -> V_14 ;
V_23 -> V_45 = NULL ;
F_25 ( V_45 ) ;
}
static void F_34 ( struct V_22 * V_23 , int V_21 )
{
struct V_44 * V_45 = V_23 -> V_45 ;
if ( V_21 == - V_51 )
return;
if ( ! V_21 )
memcpy ( V_45 -> V_48 , V_23 -> V_48 ,
F_31 ( F_18 ( V_23 ) ) ) ;
F_33 ( V_23 ) ;
}
static void F_35 ( struct V_52 * V_23 , int V_21 )
{
struct V_22 * V_53 = V_23 -> V_14 ;
F_34 ( V_53 , V_21 ) ;
V_53 -> V_25 . V_49 ( & V_53 -> V_25 , V_21 ) ;
}
static int F_36 ( struct V_22 * V_23 ,
int (* F_37)( struct V_22 * ) )
{
int V_21 ;
V_21 = F_30 ( V_23 , F_35 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_37 ( V_23 ) ;
F_34 ( V_23 , V_21 ) ;
return V_21 ;
}
static int F_38 ( struct V_22 * V_23 ,
int (* F_37)( struct V_22 * ) )
{
struct V_2 * V_30 = F_18 ( V_23 ) ;
unsigned long V_7 = F_17 ( V_30 ) ;
if ( ( unsigned long ) V_23 -> V_48 & V_7 )
return F_36 ( V_23 , F_37 ) ;
return F_37 ( V_23 ) ;
}
int F_39 ( struct V_22 * V_23 )
{
return F_38 ( V_23 , F_18 ( V_23 ) -> V_54 ) ;
}
int F_40 ( struct V_22 * V_23 )
{
return F_38 ( V_23 , F_18 ( V_23 ) -> V_55 ) ;
}
int F_41 ( struct V_22 * V_23 )
{
return F_38 ( V_23 , F_18 ( V_23 ) -> V_56 ) ;
}
static void F_42 ( struct V_22 * V_23 , int V_21 )
{
struct V_44 * V_45 = V_23 -> V_45 ;
if ( V_21 == - V_51 )
return;
if ( ! V_21 )
memcpy ( V_45 -> V_48 , V_23 -> V_48 ,
F_31 ( F_18 ( V_23 ) ) ) ;
F_33 ( V_23 ) ;
}
static void F_43 ( struct V_52 * V_23 , int V_21 )
{
struct V_22 * V_53 = V_23 -> V_14 ;
F_42 ( V_53 , V_21 ) ;
V_53 -> V_25 . V_49 ( & V_53 -> V_25 , V_21 ) ;
}
static int F_44 ( struct V_22 * V_23 , int V_21 )
{
if ( V_21 )
goto V_57;
V_23 -> V_25 . V_49 = F_43 ;
V_23 -> V_25 . V_12 &= ~ V_46 ;
V_21 = F_18 ( V_23 ) -> V_54 ( V_23 ) ;
V_57:
F_42 ( V_23 , V_21 ) ;
return V_21 ;
}
static void F_45 ( struct V_52 * V_23 , int V_21 )
{
struct V_22 * V_53 = V_23 -> V_14 ;
V_21 = F_44 ( V_53 , V_21 ) ;
V_53 -> V_25 . V_49 ( & V_53 -> V_25 , V_21 ) ;
}
static int F_46 ( struct V_22 * V_23 )
{
struct V_2 * V_30 = F_18 ( V_23 ) ;
int V_21 ;
V_21 = F_30 ( V_23 , F_45 ) ;
if ( V_21 )
return V_21 ;
V_21 = V_30 -> V_58 ( V_23 ) ;
return F_44 ( V_23 , V_21 ) ;
}
static int F_47 ( struct V_22 * V_23 , void * V_57 )
{
return - V_40 ;
}
static int F_48 ( struct V_22 * V_23 , const void * V_59 )
{
return - V_40 ;
}
static int F_49 ( struct V_60 * V_30 )
{
struct V_2 * V_3 = F_50 ( V_30 ) ;
struct V_1 * V_61 = F_1 ( V_3 ) ;
V_3 -> V_39 = F_27 ;
V_3 -> V_62 = F_47 ;
V_3 -> V_63 = F_48 ;
if ( V_30 -> V_64 -> V_65 != & V_66 )
return F_51 ( V_30 ) ;
V_3 -> V_67 = V_61 -> V_67 ;
V_3 -> V_58 = V_61 -> V_58 ;
V_3 -> V_54 = V_61 -> V_54 ;
V_3 -> V_55 = V_61 -> V_55 ? : F_46 ;
V_3 -> V_56 = V_61 -> V_56 ;
if ( V_61 -> V_39 )
V_3 -> V_39 = V_61 -> V_39 ;
if ( V_61 -> V_62 )
V_3 -> V_62 = V_61 -> V_62 ;
if ( V_61 -> V_63 )
V_3 -> V_63 = V_61 -> V_63 ;
return 0 ;
}
static unsigned int F_52 ( struct V_68 * V_61 )
{
if ( V_61 -> V_65 == & V_66 )
return V_61 -> V_69 ;
return sizeof( struct V_70 * ) ;
}
static int F_53 ( struct V_71 * V_72 , struct V_68 * V_61 )
{
struct V_73 V_74 ;
strncpy ( V_74 . type , L_1 , sizeof( V_74 . type ) ) ;
V_74 . V_75 = V_61 -> V_76 ;
V_74 . V_77 = F_54 ( V_61 ) -> V_77 ;
if ( F_55 ( V_72 , V_78 ,
sizeof( struct V_73 ) , & V_74 ) )
goto V_79;
return 0 ;
V_79:
return - V_80 ;
}
static int F_53 ( struct V_71 * V_72 , struct V_68 * V_61 )
{
return - V_40 ;
}
static void F_56 ( struct V_81 * V_82 , struct V_68 * V_61 )
{
F_57 ( V_82 , L_2 ) ;
F_57 ( V_82 , L_3 , V_61 -> V_83 & V_13 ?
L_4 : L_5 ) ;
F_57 ( V_82 , L_6 , V_61 -> V_76 ) ;
F_57 ( V_82 , L_7 ,
F_54 ( V_61 ) -> V_77 ) ;
}
struct V_2 * F_58 ( const char * V_84 , T_3 type ,
T_3 V_41 )
{
return F_59 ( V_84 , & V_66 , type , V_41 ) ;
}
static int F_60 ( struct V_1 * V_61 )
{
struct V_68 * V_25 = & V_61 -> V_4 . V_25 ;
if ( V_61 -> V_4 . V_77 > V_11 / 8 ||
V_61 -> V_4 . V_85 > V_11 / 8 ||
V_61 -> V_4 . V_85 == 0 )
return - V_86 ;
V_25 -> V_65 = & V_66 ;
V_25 -> V_83 &= ~ V_87 ;
V_25 -> V_83 |= V_88 ;
return 0 ;
}
int F_61 ( struct V_1 * V_61 )
{
struct V_68 * V_25 = & V_61 -> V_4 . V_25 ;
int V_21 ;
V_21 = F_60 ( V_61 ) ;
if ( V_21 )
return V_21 ;
return F_62 ( V_25 ) ;
}
int F_63 ( struct V_1 * V_61 )
{
return F_64 ( & V_61 -> V_4 . V_25 ) ;
}
int F_65 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
int V_21 ;
V_21 = F_60 ( & V_92 -> V_61 ) ;
if ( V_21 )
return V_21 ;
return F_66 ( V_90 , F_67 ( V_92 ) ) ;
}
void F_68 ( struct V_93 * V_92 )
{
F_69 ( F_70 ( V_92 ) ) ;
F_71 ( V_91 ( V_92 ) ) ;
}
int F_72 ( struct V_94 * V_95 ,
struct V_96 * V_61 ,
struct V_93 * V_92 )
{
return F_73 ( & V_95 -> V_25 , & V_61 -> V_25 , V_92 ,
& V_66 ) ;
}
struct V_96 * F_74 ( struct V_97 * V_98 , T_3 type , T_3 V_41 )
{
struct V_68 * V_61 ;
V_61 = F_75 ( V_98 , & V_66 , type , V_41 ) ;
return F_76 ( V_61 ) ? F_77 ( V_61 ) : F_54 ( V_61 ) ;
}
