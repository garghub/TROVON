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
V_6 -> V_12 = F_6 ( V_6 -> V_13 ) ;
V_6 -> V_12 += V_8 ;
if ( V_8 & V_7 ) {
unsigned int V_14 = V_7 + 1 - ( V_8 & V_7 ) ;
if ( V_9 > V_14 )
V_9 = V_14 ;
}
V_6 -> V_10 -= V_9 ;
return V_9 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_15 * V_16 ;
V_16 = V_6 -> V_16 ;
V_6 -> V_13 = F_8 ( V_16 ) ;
V_6 -> V_8 = V_16 -> V_8 ;
V_6 -> V_10 = V_16 -> V_17 ;
if ( V_6 -> V_10 > V_6 -> V_18 )
V_6 -> V_10 = V_6 -> V_18 ;
V_6 -> V_18 -= V_6 -> V_10 ;
return F_4 ( V_6 ) ;
}
int F_9 ( struct V_5 * V_6 , int V_19 )
{
unsigned int V_7 = V_6 -> V_7 ;
unsigned int V_9 = V_6 -> V_10 ;
V_6 -> V_12 -= V_6 -> V_8 ;
if ( V_9 && V_6 -> V_8 & V_7 && ! V_19 ) {
V_6 -> V_8 = F_10 ( V_6 -> V_8 , V_7 + 1 ) ;
V_6 -> V_12 += V_6 -> V_8 ;
V_9 = F_5 ( V_9 ,
( ( unsigned int ) ( V_11 ) ) - V_6 -> V_8 ) ;
V_6 -> V_10 -= V_9 ;
return V_9 ;
}
F_11 ( V_6 -> V_12 ) ;
F_12 ( V_6 -> V_20 ) ;
if ( V_19 )
return V_19 ;
if ( V_9 ) {
V_6 -> V_8 = 0 ;
V_6 -> V_13 ++ ;
return F_4 ( V_6 ) ;
}
if ( ! V_6 -> V_18 )
return 0 ;
V_6 -> V_16 = F_13 ( V_6 -> V_16 ) ;
return F_7 ( V_6 ) ;
}
int F_14 ( struct V_21 * V_22 ,
struct V_5 * V_6 )
{
V_6 -> V_18 = V_22 -> V_9 ;
if ( ! V_6 -> V_18 )
return 0 ;
V_6 -> V_7 = F_15 ( F_16 ( V_22 ) ) ;
V_6 -> V_16 = V_22 -> V_23 ;
V_6 -> V_20 = V_22 -> V_24 . V_20 ;
return F_7 ( V_6 ) ;
}
int F_17 ( struct V_25 * V_26 ,
struct V_5 * V_6 ,
struct V_15 * V_16 , unsigned int V_27 )
{
V_6 -> V_18 = V_27 ;
if ( ! V_6 -> V_18 )
return 0 ;
V_6 -> V_7 = F_18 ( V_26 -> V_28 ) ;
V_6 -> V_16 = V_16 ;
V_6 -> V_20 = V_26 -> V_20 ;
return F_7 ( V_6 ) ;
}
static int F_19 ( struct V_2 * V_28 , const T_1 * V_29 ,
unsigned int V_30 )
{
unsigned long V_7 = F_15 ( V_28 ) ;
int V_31 ;
T_1 * V_32 , * V_33 ;
unsigned long V_34 ;
V_34 = V_30 + V_7 ;
V_32 = F_20 ( V_34 , V_35 ) ;
if ( ! V_32 )
return - V_36 ;
V_33 = ( T_1 * ) F_10 ( ( unsigned long ) V_32 , V_7 + 1 ) ;
memcpy ( V_33 , V_29 , V_30 ) ;
V_31 = V_28 -> V_37 ( V_28 , V_33 , V_30 ) ;
F_21 ( V_32 ) ;
return V_31 ;
}
int F_22 ( struct V_2 * V_28 , const T_1 * V_29 ,
unsigned int V_30 )
{
unsigned long V_7 = F_15 ( V_28 ) ;
if ( ( unsigned long ) V_29 & V_7 )
return F_19 ( V_28 , V_29 , V_30 ) ;
return V_28 -> V_37 ( V_28 , V_29 , V_30 ) ;
}
static int F_23 ( struct V_2 * V_28 , const T_1 * V_29 ,
unsigned int V_30 )
{
return - V_38 ;
}
static inline unsigned int F_24 ( unsigned V_27 ,
unsigned long V_39 )
{
return V_27 + ( V_39 & ~ ( F_25 () - 1 ) ) ;
}
static void F_26 ( struct V_21 * V_22 , int V_19 )
{
struct V_40 * V_41 = V_22 -> V_41 ;
if ( V_19 == - V_42 )
return;
if ( ! V_19 )
memcpy ( V_41 -> V_43 , V_22 -> V_43 ,
F_27 ( F_16 ( V_22 ) ) ) ;
F_21 ( V_41 ) ;
}
static void F_28 ( struct V_44 * V_22 , int V_19 )
{
struct V_21 * V_45 = V_22 -> V_12 ;
struct V_40 * V_41 = V_45 -> V_41 ;
T_2 V_46 = V_41 -> V_46 ;
void * V_12 = V_41 -> V_12 ;
F_26 ( V_45 , V_19 ) ;
V_46 ( V_12 , V_19 ) ;
}
static int F_29 ( struct V_21 * V_22 ,
int (* F_30)( struct V_21 * ) )
{
struct V_2 * V_28 = F_16 ( V_22 ) ;
unsigned long V_7 = F_15 ( V_28 ) ;
unsigned int V_47 = F_27 ( V_28 ) ;
struct V_40 * V_41 ;
int V_19 ;
V_41 = F_20 ( sizeof( * V_41 ) + F_24 ( V_47 , V_7 ) ,
( V_22 -> V_24 . V_20 & V_48 ) ?
V_35 : V_49 ) ;
if ( ! V_41 )
return - V_36 ;
V_41 -> V_43 = V_22 -> V_43 ;
V_41 -> V_46 = V_22 -> V_24 . V_46 ;
V_41 -> V_12 = V_22 -> V_24 . V_12 ;
V_22 -> V_43 = F_31 ( ( T_1 * ) V_41 -> V_50 , V_7 + 1 ) ;
V_22 -> V_24 . V_46 = F_28 ;
V_22 -> V_24 . V_12 = V_22 ;
V_22 -> V_41 = V_41 ;
V_19 = F_30 ( V_22 ) ;
F_26 ( V_22 , V_19 ) ;
return V_19 ;
}
static int F_32 ( struct V_21 * V_22 ,
int (* F_30)( struct V_21 * ) )
{
struct V_2 * V_28 = F_16 ( V_22 ) ;
unsigned long V_7 = F_15 ( V_28 ) ;
if ( ( unsigned long ) V_22 -> V_43 & V_7 )
return F_29 ( V_22 , F_30 ) ;
return F_30 ( V_22 ) ;
}
int F_33 ( struct V_21 * V_22 )
{
return F_32 ( V_22 , F_16 ( V_22 ) -> V_51 ) ;
}
int F_34 ( struct V_21 * V_22 )
{
return F_32 ( V_22 , F_16 ( V_22 ) -> V_52 ) ;
}
int F_35 ( struct V_21 * V_22 )
{
return F_32 ( V_22 , F_16 ( V_22 ) -> V_53 ) ;
}
static void F_36 ( struct V_21 * V_22 , int V_19 )
{
struct V_40 * V_41 = V_22 -> V_41 ;
if ( V_19 == - V_42 )
return;
if ( ! V_19 )
memcpy ( V_41 -> V_43 , V_22 -> V_43 ,
F_27 ( F_16 ( V_22 ) ) ) ;
F_21 ( V_41 ) ;
}
static void F_37 ( struct V_44 * V_22 , int V_19 )
{
struct V_21 * V_45 = V_22 -> V_12 ;
struct V_40 * V_41 = V_45 -> V_41 ;
T_2 V_46 = V_41 -> V_46 ;
void * V_12 = V_41 -> V_12 ;
F_36 ( V_45 , V_19 ) ;
V_46 ( V_12 , V_19 ) ;
}
static int F_38 ( struct V_21 * V_22 , int V_19 )
{
if ( V_19 )
goto V_54;
V_22 -> V_24 . V_46 = F_37 ;
V_22 -> V_24 . V_20 &= ~ V_48 ;
V_19 = F_16 ( V_22 ) -> V_51 ( V_22 ) ;
V_54:
F_36 ( V_22 , V_19 ) ;
return V_19 ;
}
static void F_39 ( struct V_44 * V_22 , int V_19 )
{
struct V_21 * V_45 = V_22 -> V_12 ;
struct V_40 * V_41 = V_45 -> V_41 ;
T_2 V_46 = V_41 -> V_46 ;
void * V_12 = V_41 -> V_12 ;
V_19 = F_38 ( V_45 , V_19 ) ;
V_46 ( V_12 , V_19 ) ;
}
static int F_40 ( struct V_21 * V_22 )
{
struct V_2 * V_28 = F_16 ( V_22 ) ;
unsigned long V_7 = F_15 ( V_28 ) ;
unsigned int V_47 = F_27 ( V_28 ) ;
struct V_40 * V_41 ;
V_41 = F_20 ( sizeof( * V_41 ) + F_24 ( V_47 , V_7 ) ,
( V_22 -> V_24 . V_20 & V_48 ) ?
V_35 : V_49 ) ;
if ( ! V_41 )
return - V_36 ;
V_41 -> V_43 = V_22 -> V_43 ;
V_41 -> V_46 = V_22 -> V_24 . V_46 ;
V_41 -> V_12 = V_22 -> V_24 . V_12 ;
V_22 -> V_43 = F_31 ( ( T_1 * ) V_41 -> V_50 , V_7 + 1 ) ;
V_22 -> V_24 . V_46 = F_39 ;
V_22 -> V_24 . V_12 = V_22 ;
V_22 -> V_41 = V_41 ;
return F_38 ( V_22 , V_28 -> V_55 ( V_22 ) ) ;
}
static int F_41 ( struct V_21 * V_22 , void * V_54 )
{
return - V_38 ;
}
static int F_42 ( struct V_21 * V_22 , const void * V_56 )
{
return - V_38 ;
}
static int F_43 ( struct V_57 * V_28 )
{
struct V_2 * V_3 = F_44 ( V_28 ) ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
V_3 -> V_37 = F_23 ;
V_3 -> V_59 = F_41 ;
V_3 -> V_60 = F_42 ;
if ( V_28 -> V_61 -> V_62 != & V_63 )
return F_45 ( V_28 ) ;
V_3 -> V_64 = V_58 -> V_64 ;
V_3 -> V_55 = V_58 -> V_55 ;
V_3 -> V_51 = V_58 -> V_51 ;
V_3 -> V_52 = V_58 -> V_52 ? : F_40 ;
V_3 -> V_53 = V_58 -> V_53 ;
if ( V_58 -> V_37 )
V_3 -> V_37 = V_58 -> V_37 ;
if ( V_58 -> V_59 )
V_3 -> V_59 = V_58 -> V_59 ;
if ( V_58 -> V_60 )
V_3 -> V_60 = V_58 -> V_60 ;
return 0 ;
}
static unsigned int F_46 ( struct V_65 * V_58 )
{
if ( V_58 -> V_62 == & V_63 )
return V_58 -> V_66 ;
return sizeof( struct V_67 * ) ;
}
static int F_47 ( struct V_68 * V_69 , struct V_65 * V_58 )
{
struct V_70 V_71 ;
snprintf ( V_71 . type , V_72 , L_1 , L_2 ) ;
V_71 . V_73 = V_58 -> V_74 ;
V_71 . V_75 = F_48 ( V_58 ) -> V_75 ;
F_49 ( V_69 , V_76 ,
sizeof( struct V_70 ) , & V_71 ) ;
return 0 ;
V_77:
return - V_78 ;
}
static int F_47 ( struct V_68 * V_69 , struct V_65 * V_58 )
{
return - V_38 ;
}
static void F_50 ( struct V_79 * V_80 , struct V_65 * V_58 )
{
F_51 ( V_80 , L_3 ) ;
F_51 ( V_80 , L_4 , V_58 -> V_81 & V_82 ?
L_5 : L_6 ) ;
F_51 ( V_80 , L_7 , V_58 -> V_74 ) ;
F_51 ( V_80 , L_8 ,
F_48 ( V_58 ) -> V_75 ) ;
}
struct V_2 * F_52 ( const char * V_83 , T_3 type ,
T_3 V_39 )
{
return F_53 ( V_83 , & V_63 , type , V_39 ) ;
}
static int F_54 ( struct V_1 * V_58 )
{
struct V_65 * V_24 = & V_58 -> V_4 . V_24 ;
if ( V_58 -> V_4 . V_75 > V_11 / 8 ||
V_58 -> V_4 . V_84 > V_11 / 8 )
return - V_85 ;
V_24 -> V_62 = & V_63 ;
V_24 -> V_81 &= ~ V_86 ;
V_24 -> V_81 |= V_87 ;
return 0 ;
}
int F_55 ( struct V_1 * V_58 )
{
struct V_65 * V_24 = & V_58 -> V_4 . V_24 ;
int V_19 ;
V_19 = F_54 ( V_58 ) ;
if ( V_19 )
return V_19 ;
return F_56 ( V_24 ) ;
}
int F_57 ( struct V_1 * V_58 )
{
return F_58 ( & V_58 -> V_4 . V_24 ) ;
}
int F_59 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
int V_19 ;
V_19 = F_54 ( & V_91 -> V_58 ) ;
if ( V_19 )
return V_19 ;
return F_60 ( V_89 , F_61 ( V_91 ) ) ;
}
void F_62 ( struct V_92 * V_91 )
{
F_63 ( F_64 ( V_91 ) ) ;
F_65 ( V_90 ( V_91 ) ) ;
}
int F_66 ( struct V_93 * V_94 ,
struct V_95 * V_58 ,
struct V_92 * V_91 )
{
return F_67 ( & V_94 -> V_24 , & V_58 -> V_24 , V_91 ,
& V_63 ) ;
}
struct V_95 * F_68 ( struct V_96 * V_97 , T_3 type , T_3 V_39 )
{
struct V_65 * V_58 ;
V_58 = F_69 ( V_97 , & V_63 , type , V_39 ) ;
return F_70 ( V_58 ) ? F_71 ( V_58 ) : F_48 ( V_58 ) ;
}
