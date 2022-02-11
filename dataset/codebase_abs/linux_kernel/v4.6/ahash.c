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
V_6 -> V_8 = V_18 -> V_8 ;
V_6 -> V_15 = F_9 ( V_6 -> V_18 ) + ( V_6 -> V_8 >> V_19 ) ;
V_6 -> V_8 = F_10 ( V_6 -> V_8 ) ;
V_6 -> V_10 = V_18 -> V_20 ;
if ( V_6 -> V_10 > V_6 -> V_21 )
V_6 -> V_10 = V_6 -> V_21 ;
V_6 -> V_21 -= V_6 -> V_10 ;
return F_4 ( V_6 ) ;
}
int F_11 ( struct V_5 * V_6 , int V_22 )
{
unsigned int V_7 = V_6 -> V_7 ;
unsigned int V_9 = V_6 -> V_10 ;
V_6 -> V_14 -= V_6 -> V_8 ;
if ( V_9 && V_6 -> V_8 & V_7 && ! V_22 ) {
V_6 -> V_8 = F_12 ( V_6 -> V_8 , V_7 + 1 ) ;
V_6 -> V_14 += V_6 -> V_8 ;
V_9 = F_5 ( V_9 ,
( ( unsigned int ) ( V_11 ) ) - V_6 -> V_8 ) ;
V_6 -> V_10 -= V_9 ;
return V_9 ;
}
if ( V_6 -> V_12 & V_13 )
F_13 ( V_6 -> V_15 ) ;
else {
F_14 ( V_6 -> V_14 ) ;
F_15 ( V_6 -> V_12 ) ;
}
if ( V_22 )
return V_22 ;
if ( V_9 ) {
V_6 -> V_8 = 0 ;
V_6 -> V_15 ++ ;
return F_4 ( V_6 ) ;
}
if ( ! V_6 -> V_21 )
return 0 ;
V_6 -> V_18 = F_16 ( V_6 -> V_18 ) ;
return F_8 ( V_6 ) ;
}
int F_17 ( struct V_23 * V_24 ,
struct V_5 * V_6 )
{
V_6 -> V_21 = V_24 -> V_9 ;
if ( ! V_6 -> V_21 ) {
V_6 -> V_10 = 0 ;
return 0 ;
}
V_6 -> V_7 = F_18 ( F_19 ( V_24 ) ) ;
V_6 -> V_18 = V_24 -> V_25 ;
V_6 -> V_12 = V_24 -> V_26 . V_12 & V_27 ;
return F_8 ( V_6 ) ;
}
int F_20 ( struct V_23 * V_24 ,
struct V_5 * V_6 )
{
V_6 -> V_21 = V_24 -> V_9 ;
if ( ! V_6 -> V_21 ) {
V_6 -> V_10 = 0 ;
return 0 ;
}
V_6 -> V_7 = F_18 ( F_19 ( V_24 ) ) ;
V_6 -> V_18 = V_24 -> V_25 ;
V_6 -> V_12 = V_24 -> V_26 . V_12 & V_27 ;
V_6 -> V_12 |= V_13 ;
F_21 ( V_27 & V_13 ) ;
return F_8 ( V_6 ) ;
}
static int F_22 ( struct V_2 * V_28 , const T_1 * V_29 ,
unsigned int V_30 )
{
unsigned long V_7 = F_18 ( V_28 ) ;
int V_31 ;
T_1 * V_32 , * V_33 ;
unsigned long V_34 ;
V_34 = V_30 + V_7 ;
V_32 = F_23 ( V_34 , V_35 ) ;
if ( ! V_32 )
return - V_36 ;
V_33 = ( T_1 * ) F_12 ( ( unsigned long ) V_32 , V_7 + 1 ) ;
memcpy ( V_33 , V_29 , V_30 ) ;
V_31 = V_28 -> V_37 ( V_28 , V_33 , V_30 ) ;
F_24 ( V_32 ) ;
return V_31 ;
}
int F_25 ( struct V_2 * V_28 , const T_1 * V_29 ,
unsigned int V_30 )
{
unsigned long V_7 = F_18 ( V_28 ) ;
if ( ( unsigned long ) V_29 & V_7 )
return F_22 ( V_28 , V_29 , V_30 ) ;
return V_28 -> V_37 ( V_28 , V_29 , V_30 ) ;
}
static int F_26 ( struct V_2 * V_28 , const T_1 * V_29 ,
unsigned int V_30 )
{
return - V_38 ;
}
static inline unsigned int F_27 ( unsigned V_39 ,
unsigned long V_40 )
{
return V_39 + ( V_40 & ~ ( F_28 () - 1 ) ) ;
}
static int F_29 ( struct V_23 * V_24 , T_2 V_41 )
{
struct V_2 * V_28 = F_19 ( V_24 ) ;
unsigned long V_7 = F_18 ( V_28 ) ;
unsigned int V_42 = F_30 ( V_28 ) ;
struct V_43 * V_44 ;
V_44 = F_23 ( sizeof( * V_44 ) + F_27 ( V_42 , V_7 ) ,
( V_24 -> V_26 . V_12 & V_45 ) ?
V_35 : V_46 ) ;
if ( ! V_44 )
return - V_36 ;
V_44 -> V_47 = V_24 -> V_47 ;
V_44 -> V_48 = V_24 -> V_26 . V_48 ;
V_44 -> V_14 = V_24 -> V_26 . V_14 ;
V_24 -> V_47 = F_31 ( ( T_1 * ) V_44 -> V_49 , V_7 + 1 ) ;
V_24 -> V_26 . V_48 = V_41 ;
V_24 -> V_26 . V_14 = V_24 ;
V_24 -> V_44 = V_44 ;
return 0 ;
}
static void F_32 ( struct V_23 * V_24 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
V_24 -> V_47 = V_44 -> V_47 ;
V_24 -> V_26 . V_48 = V_44 -> V_48 ;
V_24 -> V_26 . V_14 = V_44 -> V_14 ;
V_24 -> V_44 = NULL ;
F_24 ( V_44 ) ;
}
static void F_33 ( struct V_23 * V_24 , int V_22 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
if ( V_22 == - V_50 )
return;
if ( ! V_22 )
memcpy ( V_44 -> V_47 , V_24 -> V_47 ,
F_30 ( F_19 ( V_24 ) ) ) ;
F_32 ( V_24 ) ;
}
static void F_34 ( struct V_51 * V_24 , int V_22 )
{
struct V_23 * V_52 = V_24 -> V_14 ;
F_33 ( V_52 , V_22 ) ;
V_52 -> V_26 . V_48 ( & V_52 -> V_26 , V_22 ) ;
}
static int F_35 ( struct V_23 * V_24 ,
int (* F_36)( struct V_23 * ) )
{
int V_22 ;
V_22 = F_29 ( V_24 , F_34 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_36 ( V_24 ) ;
F_33 ( V_24 , V_22 ) ;
return V_22 ;
}
static int F_37 ( struct V_23 * V_24 ,
int (* F_36)( struct V_23 * ) )
{
struct V_2 * V_28 = F_19 ( V_24 ) ;
unsigned long V_7 = F_18 ( V_28 ) ;
if ( ( unsigned long ) V_24 -> V_47 & V_7 )
return F_35 ( V_24 , F_36 ) ;
return F_36 ( V_24 ) ;
}
int F_38 ( struct V_23 * V_24 )
{
return F_37 ( V_24 , F_19 ( V_24 ) -> V_53 ) ;
}
int F_39 ( struct V_23 * V_24 )
{
return F_37 ( V_24 , F_19 ( V_24 ) -> V_54 ) ;
}
int F_40 ( struct V_23 * V_24 )
{
return F_37 ( V_24 , F_19 ( V_24 ) -> V_55 ) ;
}
static void F_41 ( struct V_23 * V_24 , int V_22 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
if ( V_22 == - V_50 )
return;
if ( ! V_22 )
memcpy ( V_44 -> V_47 , V_24 -> V_47 ,
F_30 ( F_19 ( V_24 ) ) ) ;
F_32 ( V_24 ) ;
}
static void F_42 ( struct V_51 * V_24 , int V_22 )
{
struct V_23 * V_52 = V_24 -> V_14 ;
F_41 ( V_52 , V_22 ) ;
V_52 -> V_26 . V_48 ( & V_52 -> V_26 , V_22 ) ;
}
static int F_43 ( struct V_23 * V_24 , int V_22 )
{
if ( V_22 )
goto V_56;
V_24 -> V_26 . V_48 = F_42 ;
V_24 -> V_26 . V_12 &= ~ V_45 ;
V_22 = F_19 ( V_24 ) -> V_53 ( V_24 ) ;
V_56:
F_41 ( V_24 , V_22 ) ;
return V_22 ;
}
static void F_44 ( struct V_51 * V_24 , int V_22 )
{
struct V_23 * V_52 = V_24 -> V_14 ;
V_22 = F_43 ( V_52 , V_22 ) ;
V_52 -> V_26 . V_48 ( & V_52 -> V_26 , V_22 ) ;
}
static int F_45 ( struct V_23 * V_24 )
{
struct V_2 * V_28 = F_19 ( V_24 ) ;
int V_22 ;
V_22 = F_29 ( V_24 , F_44 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_28 -> V_57 ( V_24 ) ;
return F_43 ( V_24 , V_22 ) ;
}
static int F_46 ( struct V_23 * V_24 , void * V_56 )
{
return - V_38 ;
}
static int F_47 ( struct V_23 * V_24 , const void * V_58 )
{
return - V_38 ;
}
static int F_48 ( struct V_59 * V_28 )
{
struct V_2 * V_3 = F_49 ( V_28 ) ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
V_3 -> V_37 = F_26 ;
V_3 -> V_61 = false ;
V_3 -> V_62 = F_46 ;
V_3 -> V_63 = F_47 ;
if ( V_28 -> V_64 -> V_65 != & V_66 )
return F_50 ( V_28 ) ;
V_3 -> V_67 = V_60 -> V_67 ;
V_3 -> V_57 = V_60 -> V_57 ;
V_3 -> V_53 = V_60 -> V_53 ;
V_3 -> V_54 = V_60 -> V_54 ? : F_45 ;
V_3 -> V_55 = V_60 -> V_55 ;
if ( V_60 -> V_37 ) {
V_3 -> V_37 = V_60 -> V_37 ;
V_3 -> V_61 = true ;
}
if ( V_60 -> V_62 )
V_3 -> V_62 = V_60 -> V_62 ;
if ( V_60 -> V_63 )
V_3 -> V_63 = V_60 -> V_63 ;
return 0 ;
}
static unsigned int F_51 ( struct V_68 * V_60 )
{
if ( V_60 -> V_65 == & V_66 )
return V_60 -> V_69 ;
return sizeof( struct V_70 * ) ;
}
static int F_52 ( struct V_71 * V_72 , struct V_68 * V_60 )
{
struct V_73 V_74 ;
strncpy ( V_74 . type , L_1 , sizeof( V_74 . type ) ) ;
V_74 . V_75 = V_60 -> V_76 ;
V_74 . V_77 = F_53 ( V_60 ) -> V_77 ;
if ( F_54 ( V_72 , V_78 ,
sizeof( struct V_73 ) , & V_74 ) )
goto V_79;
return 0 ;
V_79:
return - V_80 ;
}
static int F_52 ( struct V_71 * V_72 , struct V_68 * V_60 )
{
return - V_38 ;
}
static void F_55 ( struct V_81 * V_82 , struct V_68 * V_60 )
{
F_56 ( V_82 , L_2 ) ;
F_56 ( V_82 , L_3 , V_60 -> V_83 & V_13 ?
L_4 : L_5 ) ;
F_56 ( V_82 , L_6 , V_60 -> V_76 ) ;
F_56 ( V_82 , L_7 ,
F_53 ( V_60 ) -> V_77 ) ;
}
struct V_2 * F_57 ( const char * V_84 , T_3 type ,
T_3 V_40 )
{
return F_58 ( V_84 , & V_66 , type , V_40 ) ;
}
int F_59 ( const char * V_84 , T_3 type , T_3 V_40 )
{
return F_60 ( V_84 , & V_66 , type , V_40 ) ;
}
static int F_61 ( struct V_1 * V_60 )
{
struct V_68 * V_26 = & V_60 -> V_4 . V_26 ;
if ( V_60 -> V_4 . V_77 > V_11 / 8 ||
V_60 -> V_4 . V_85 > V_11 / 8 ||
V_60 -> V_4 . V_85 == 0 )
return - V_86 ;
V_26 -> V_65 = & V_66 ;
V_26 -> V_83 &= ~ V_87 ;
V_26 -> V_83 |= V_88 ;
return 0 ;
}
int F_62 ( struct V_1 * V_60 )
{
struct V_68 * V_26 = & V_60 -> V_4 . V_26 ;
int V_22 ;
V_22 = F_61 ( V_60 ) ;
if ( V_22 )
return V_22 ;
return F_63 ( V_26 ) ;
}
int F_64 ( struct V_1 * V_60 )
{
return F_65 ( & V_60 -> V_4 . V_26 ) ;
}
int F_66 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
int V_22 ;
V_22 = F_61 ( & V_92 -> V_60 ) ;
if ( V_22 )
return V_22 ;
return F_67 ( V_90 , F_68 ( V_92 ) ) ;
}
void F_69 ( struct V_93 * V_92 )
{
F_70 ( F_71 ( V_92 ) ) ;
F_72 ( V_91 ( V_92 ) ) ;
}
int F_73 ( struct V_94 * V_95 ,
struct V_96 * V_60 ,
struct V_93 * V_92 )
{
return F_74 ( & V_95 -> V_26 , & V_60 -> V_26 , V_92 ,
& V_66 ) ;
}
struct V_96 * F_75 ( struct V_97 * V_98 , T_3 type , T_3 V_40 )
{
struct V_68 * V_60 ;
V_60 = F_76 ( V_98 , & V_66 , type , V_40 ) ;
return F_77 ( V_60 ) ? F_78 ( V_60 ) : F_53 ( V_60 ) ;
}
