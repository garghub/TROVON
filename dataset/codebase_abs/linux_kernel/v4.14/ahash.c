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
V_44 -> V_12 = V_24 -> V_26 . V_12 ;
V_24 -> V_47 = F_31 ( ( T_1 * ) V_44 -> V_49 , V_7 + 1 ) ;
V_24 -> V_26 . V_48 = V_41 ;
V_24 -> V_26 . V_14 = V_24 ;
V_24 -> V_44 = V_44 ;
return 0 ;
}
static void F_32 ( struct V_23 * V_24 , int V_22 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
if ( ! V_22 )
memcpy ( V_44 -> V_47 , V_24 -> V_47 ,
F_30 ( F_19 ( V_24 ) ) ) ;
V_24 -> V_47 = V_44 -> V_47 ;
F_33 ( V_24 , V_44 -> V_12 ,
V_44 -> V_48 , V_44 -> V_14 ) ;
V_24 -> V_44 = NULL ;
F_24 ( V_44 ) ;
}
static void F_34 ( struct V_23 * V_24 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
struct V_50 V_51 ;
V_51 . V_14 = V_44 -> V_14 ;
V_44 -> V_48 ( & V_51 , - V_52 ) ;
}
static void F_35 ( struct V_50 * V_24 , int V_22 )
{
struct V_23 * V_53 = V_24 -> V_14 ;
if ( V_22 == - V_52 ) {
F_34 ( V_53 ) ;
return;
}
F_32 ( V_53 , V_22 ) ;
V_53 -> V_26 . V_48 ( & V_53 -> V_26 , V_22 ) ;
}
static int F_36 ( struct V_23 * V_24 ,
int (* F_37)( struct V_23 * ) )
{
int V_22 ;
V_22 = F_29 ( V_24 , F_35 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_37 ( V_24 ) ;
if ( V_22 == - V_52 ||
( V_22 == - V_54 && ( F_38 ( V_24 ) &
V_55 ) ) )
return V_22 ;
F_32 ( V_24 , V_22 ) ;
return V_22 ;
}
static int F_39 ( struct V_23 * V_24 ,
int (* F_37)( struct V_23 * ) )
{
struct V_2 * V_28 = F_19 ( V_24 ) ;
unsigned long V_7 = F_18 ( V_28 ) ;
if ( ( unsigned long ) V_24 -> V_47 & V_7 )
return F_36 ( V_24 , F_37 ) ;
return F_37 ( V_24 ) ;
}
int F_40 ( struct V_23 * V_24 )
{
return F_39 ( V_24 , F_19 ( V_24 ) -> V_56 ) ;
}
int F_41 ( struct V_23 * V_24 )
{
return F_39 ( V_24 , F_19 ( V_24 ) -> V_57 ) ;
}
int F_42 ( struct V_23 * V_24 )
{
return F_39 ( V_24 , F_19 ( V_24 ) -> V_58 ) ;
}
static void F_43 ( struct V_50 * V_24 , int V_22 )
{
struct V_23 * V_53 = V_24 -> V_14 ;
if ( V_22 == - V_52 )
return;
F_32 ( V_53 , V_22 ) ;
V_53 -> V_26 . V_48 ( & V_53 -> V_26 , V_22 ) ;
}
static int F_44 ( struct V_23 * V_24 , int V_22 )
{
if ( V_22 )
goto V_59;
V_24 -> V_26 . V_48 = F_43 ;
V_22 = F_19 ( V_24 ) -> V_56 ( V_24 ) ;
if ( V_22 == - V_52 ||
( V_22 == - V_54 && ( F_38 ( V_24 ) &
V_55 ) ) )
return V_22 ;
V_59:
F_32 ( V_24 , V_22 ) ;
return V_22 ;
}
static void F_45 ( struct V_50 * V_24 , int V_22 )
{
struct V_23 * V_53 = V_24 -> V_14 ;
if ( V_22 == - V_52 ) {
F_34 ( V_53 ) ;
return;
}
V_53 -> V_26 . V_12 &= ~ V_45 ;
V_22 = F_44 ( V_53 , V_22 ) ;
if ( V_53 -> V_44 )
return;
V_53 -> V_26 . V_48 ( & V_53 -> V_26 , V_22 ) ;
}
static int F_46 ( struct V_23 * V_24 )
{
struct V_2 * V_28 = F_19 ( V_24 ) ;
int V_22 ;
V_22 = F_29 ( V_24 , F_45 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_28 -> V_60 ( V_24 ) ;
if ( V_22 == - V_52 ||
( V_22 == - V_54 && ( F_38 ( V_24 ) &
V_55 ) ) )
return V_22 ;
return F_44 ( V_24 , V_22 ) ;
}
static int F_47 ( struct V_23 * V_24 , void * V_59 )
{
return - V_38 ;
}
static int F_48 ( struct V_23 * V_24 , const void * V_61 )
{
return - V_38 ;
}
static int F_49 ( struct V_62 * V_28 )
{
struct V_2 * V_3 = F_50 ( V_28 ) ;
struct V_1 * V_63 = F_1 ( V_3 ) ;
V_3 -> V_37 = F_26 ;
V_3 -> V_64 = false ;
V_3 -> V_65 = F_47 ;
V_3 -> V_66 = F_48 ;
if ( V_28 -> V_67 -> V_68 != & V_69 )
return F_51 ( V_28 ) ;
V_3 -> V_70 = V_63 -> V_70 ;
V_3 -> V_60 = V_63 -> V_60 ;
V_3 -> V_56 = V_63 -> V_56 ;
V_3 -> V_57 = V_63 -> V_57 ? : F_46 ;
V_3 -> V_58 = V_63 -> V_58 ;
if ( V_63 -> V_37 ) {
V_3 -> V_37 = V_63 -> V_37 ;
V_3 -> V_64 = true ;
}
if ( V_63 -> V_65 )
V_3 -> V_65 = V_63 -> V_65 ;
if ( V_63 -> V_66 )
V_3 -> V_66 = V_63 -> V_66 ;
return 0 ;
}
static unsigned int F_52 ( struct V_71 * V_63 )
{
if ( V_63 -> V_68 != & V_69 )
return sizeof( struct V_72 * ) ;
return F_53 ( V_63 ) ;
}
static int F_54 ( struct V_73 * V_74 , struct V_71 * V_63 )
{
struct V_75 V_76 ;
strncpy ( V_76 . type , L_1 , sizeof( V_76 . type ) ) ;
V_76 . V_77 = V_63 -> V_78 ;
V_76 . V_79 = F_55 ( V_63 ) -> V_79 ;
if ( F_56 ( V_74 , V_80 ,
sizeof( struct V_75 ) , & V_76 ) )
goto V_81;
return 0 ;
V_81:
return - V_82 ;
}
static int F_54 ( struct V_73 * V_74 , struct V_71 * V_63 )
{
return - V_38 ;
}
static void F_57 ( struct V_83 * V_84 , struct V_71 * V_63 )
{
F_58 ( V_84 , L_2 ) ;
F_58 ( V_84 , L_3 , V_63 -> V_85 & V_13 ?
L_4 : L_5 ) ;
F_58 ( V_84 , L_6 , V_63 -> V_78 ) ;
F_58 ( V_84 , L_7 ,
F_55 ( V_63 ) -> V_79 ) ;
}
struct V_2 * F_59 ( const char * V_86 , T_3 type ,
T_3 V_40 )
{
return F_60 ( V_86 , & V_69 , type , V_40 ) ;
}
int F_61 ( const char * V_86 , T_3 type , T_3 V_40 )
{
return F_62 ( V_86 , & V_69 , type , V_40 ) ;
}
static int F_63 ( struct V_1 * V_63 )
{
struct V_71 * V_26 = & V_63 -> V_4 . V_26 ;
if ( V_63 -> V_4 . V_79 > V_11 / 8 ||
V_63 -> V_4 . V_87 > V_11 / 8 ||
V_63 -> V_4 . V_87 == 0 )
return - V_88 ;
V_26 -> V_68 = & V_69 ;
V_26 -> V_85 &= ~ V_89 ;
V_26 -> V_85 |= V_90 ;
return 0 ;
}
int F_64 ( struct V_1 * V_63 )
{
struct V_71 * V_26 = & V_63 -> V_4 . V_26 ;
int V_22 ;
V_22 = F_63 ( V_63 ) ;
if ( V_22 )
return V_22 ;
return F_65 ( V_26 ) ;
}
int F_66 ( struct V_1 * V_63 )
{
return F_67 ( & V_63 -> V_4 . V_26 ) ;
}
int F_68 ( struct V_1 * V_91 , int V_92 )
{
int V_93 , V_31 ;
for ( V_93 = 0 ; V_93 < V_92 ; V_93 ++ ) {
V_31 = F_64 ( & V_91 [ V_93 ] ) ;
if ( V_31 )
goto V_22;
}
return 0 ;
V_22:
for ( -- V_93 ; V_93 >= 0 ; -- V_93 )
F_66 ( & V_91 [ V_93 ] ) ;
return V_31 ;
}
void F_69 ( struct V_1 * V_91 , int V_92 )
{
int V_93 ;
for ( V_93 = V_92 - 1 ; V_93 >= 0 ; -- V_93 )
F_66 ( & V_91 [ V_93 ] ) ;
}
int F_70 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
int V_22 ;
V_22 = F_63 ( & V_97 -> V_63 ) ;
if ( V_22 )
return V_22 ;
return F_71 ( V_95 , F_72 ( V_97 ) ) ;
}
void F_73 ( struct V_98 * V_97 )
{
F_74 ( F_75 ( V_97 ) ) ;
F_76 ( V_96 ( V_97 ) ) ;
}
int F_77 ( struct V_99 * V_100 ,
struct V_101 * V_63 ,
struct V_98 * V_97 )
{
return F_78 ( & V_100 -> V_26 , & V_63 -> V_26 , V_97 ,
& V_69 ) ;
}
struct V_101 * F_79 ( struct V_102 * V_103 , T_3 type , T_3 V_40 )
{
struct V_71 * V_63 ;
V_63 = F_80 ( V_103 , & V_69 , type , V_40 ) ;
return F_81 ( V_63 ) ? F_82 ( V_63 ) : F_55 ( V_63 ) ;
}
