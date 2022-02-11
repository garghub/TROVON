static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , & V_2 -> V_4 , V_2 -> V_5 , 1 ) ;
}
void F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_8 ;
F_4 (p, tmp, &walk->buffers, entry) {
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( V_2 ) ;
}
}
static inline void F_7 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
V_2 -> V_4 = V_7 -> V_10 ;
F_8 ( & V_2 -> V_9 , & V_7 -> V_11 ) ;
}
static inline T_1 * F_9 ( T_1 * V_12 , unsigned int V_5 )
{
T_1 * V_13 = ( T_1 * ) ( ( ( unsigned long ) ( V_12 + V_5 - 1 ) ) & V_14 ) ;
return F_10 ( V_12 , V_13 ) ;
}
static inline unsigned int F_11 ( struct V_6 * V_7 ,
unsigned int V_15 )
{
unsigned int V_16 = V_15 ;
for (; ; ) {
unsigned int V_17 = F_12 ( & V_7 -> V_10 ) ;
if ( V_17 > V_16 )
V_17 = V_16 ;
F_13 ( & V_7 -> V_10 , V_16 ) ;
if ( V_16 == V_17 )
break;
V_16 -= V_17 ;
F_14 ( & V_7 -> V_10 , F_15 ( V_7 -> V_10 . V_18 ) ) ;
}
return V_15 ;
}
static inline unsigned int F_16 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
F_13 ( & V_7 -> V_19 , V_16 ) ;
F_13 ( & V_7 -> V_10 , V_16 ) ;
return V_16 ;
}
int F_17 ( struct V_20 * V_21 ,
struct V_6 * V_7 , int V_22 )
{
struct V_23 * V_24 = V_21 -> V_25 . V_24 ;
unsigned int V_26 = 0 ;
if ( F_18 ( V_22 >= 0 ) ) {
unsigned int V_16 = V_7 -> V_26 - V_22 ;
if ( F_18 ( ! ( V_7 -> V_27 & V_28 ) ) )
V_16 = F_16 ( V_7 , V_16 ) ;
else if ( F_19 ( V_22 ) ) {
V_22 = - V_29 ;
goto V_22;
} else
V_16 = F_11 ( V_7 , V_16 ) ;
V_26 = V_7 -> V_30 - V_16 ;
V_22 = 0 ;
}
F_20 ( & V_7 -> V_19 , 0 , V_26 ) ;
F_20 ( & V_7 -> V_10 , 1 , V_26 ) ;
V_22:
V_7 -> V_30 = V_26 ;
V_7 -> V_26 = V_26 ;
if ( V_26 ) {
F_21 ( V_21 -> V_25 . V_27 ) ;
return F_22 ( V_21 , V_7 ) ;
}
if ( V_7 -> V_31 != V_21 -> V_32 )
memcpy ( V_21 -> V_32 , V_7 -> V_31 , V_24 -> V_33 . V_34 ) ;
F_6 ( V_7 -> V_35 ) ;
return V_22 ;
}
static inline int F_23 ( struct V_20 * V_21 ,
struct V_6 * V_7 ,
unsigned int V_15 ,
unsigned int V_36 ,
void * * V_37 , void * * V_38 )
{
unsigned V_39 = F_24 ( V_15 , V_36 + 1 ) ;
struct V_1 * V_2 ;
void * V_40 , * V_4 , * V_25 ;
unsigned int V_16 ;
V_16 = F_24 ( sizeof( struct V_1 ) , V_36 + 1 ) ;
V_16 += ( V_39 * 3 - ( V_36 + 1 ) +
( V_36 & ~ ( F_25 () - 1 ) ) ) ;
V_2 = F_26 ( V_16 , V_41 ) ;
if ( ! V_2 )
return F_17 ( V_21 , V_7 , - V_42 ) ;
V_25 = V_2 + 1 ;
V_4 = ( T_1 * ) F_24 ( ( unsigned long ) V_25 , V_36 + 1 ) ;
V_40 = V_4 = F_9 ( V_4 , V_15 ) ;
V_2 -> V_5 = V_15 ;
V_2 -> V_3 = V_4 ;
F_2 ( V_40 , & V_7 -> V_19 , V_15 , 0 ) ;
F_7 ( V_7 , V_2 ) ;
V_7 -> V_26 = V_15 ;
V_7 -> V_27 |= V_28 ;
* V_37 = V_40 ;
* V_38 = V_4 ;
return 0 ;
}
static inline int F_27 ( struct V_6 * V_7 ,
struct V_23 * V_24 ,
unsigned int V_36 )
{
unsigned V_43 = V_7 -> V_44 ;
unsigned int V_34 = V_24 -> V_33 . V_34 ;
unsigned V_45 = F_24 ( V_43 , V_36 + 1 ) ;
unsigned int V_46 = V_45 * 2 + V_34 + F_10 ( V_45 , V_34 ) -
( V_36 + 1 ) ;
T_1 * V_31 ;
V_46 += V_36 & ~ ( F_25 () - 1 ) ;
V_7 -> V_35 = F_26 ( V_46 , V_41 ) ;
if ( ! V_7 -> V_35 )
return - V_42 ;
V_31 = ( T_1 * ) F_24 ( ( unsigned long ) V_7 -> V_35 , V_36 + 1 ) ;
V_31 = F_9 ( V_31 , V_43 ) + V_45 ;
V_31 = F_9 ( V_31 , V_43 ) + V_45 ;
V_31 = F_9 ( V_31 , V_34 ) ;
V_7 -> V_31 = memcpy ( V_31 , V_7 -> V_31 , V_34 ) ;
return 0 ;
}
static inline int F_28 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_40 . V_47 = F_29 ( & V_7 -> V_19 ) ;
V_7 -> V_40 . V_48 = F_30 ( V_7 -> V_19 . V_48 ) ;
V_7 -> V_4 . V_47 = F_29 ( & V_7 -> V_10 ) ;
V_7 -> V_4 . V_48 = F_30 ( V_7 -> V_10 . V_48 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
struct V_23 * V_24 = V_21 -> V_25 . V_24 ;
unsigned int V_36 , V_15 , V_16 ;
void * V_40 , * V_4 ;
int V_22 ;
V_36 = F_31 ( V_24 ) ;
V_16 = V_7 -> V_30 ;
if ( F_32 ( V_16 < F_33 ( V_24 ) ) ) {
V_21 -> V_25 . V_27 |= V_49 ;
return F_17 ( V_21 , V_7 , - V_29 ) ;
}
V_7 -> V_27 &= ~ V_28 ;
V_40 = V_4 = NULL ;
V_15 = F_34 ( V_7 -> V_44 , V_16 ) ;
V_16 = F_35 ( & V_7 -> V_19 , V_16 ) ;
V_16 = F_35 ( & V_7 -> V_10 , V_16 ) ;
if ( V_16 < V_15 ||
! F_36 ( & V_7 -> V_19 , V_36 ) ||
! F_36 ( & V_7 -> V_10 , V_36 ) ) {
V_22 = F_23 ( V_21 , V_7 , V_15 , V_36 ,
& V_40 , & V_4 ) ;
goto V_50;
}
V_7 -> V_26 = V_16 ;
return F_28 ( V_21 , V_7 ) ;
V_50:
if ( V_22 >= 0 ) {
V_7 -> V_40 . V_47 = F_37 ( V_40 ) ;
V_7 -> V_4 . V_47 = F_37 ( V_4 ) ;
V_7 -> V_40 . V_48 = ( ( unsigned long ) V_40 & ( V_51 - 1 ) ) ;
V_7 -> V_4 . V_48 = ( ( unsigned long ) V_4 & ( V_51 - 1 ) ) ;
}
return V_22 ;
}
static int F_38 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
struct V_23 * V_24 = V_21 -> V_25 . V_24 ;
unsigned int V_36 ;
V_36 = F_31 ( V_24 ) ;
if ( F_39 ( F_40 () ) )
return - V_52 ;
V_7 -> V_31 = V_21 -> V_32 ;
V_7 -> V_26 = V_7 -> V_30 ;
if ( F_32 ( ! V_7 -> V_30 ) )
return 0 ;
V_7 -> V_35 = NULL ;
if ( F_32 ( ( ( unsigned long ) V_7 -> V_31 & V_36 ) ) ) {
int V_22 = F_27 ( V_7 , V_24 , V_36 ) ;
if ( V_22 )
return V_22 ;
}
F_14 ( & V_7 -> V_19 , V_7 -> V_19 . V_18 ) ;
F_14 ( & V_7 -> V_10 , V_7 -> V_10 . V_18 ) ;
return F_22 ( V_21 , V_7 ) ;
}
int F_41 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_44 = F_33 ( V_21 -> V_25 . V_24 ) ;
return F_38 ( V_21 , V_7 ) ;
}
static int F_42 ( struct V_53 * V_24 , const T_1 * V_54 ,
unsigned int V_55 )
{
struct V_56 * V_57 = F_43 ( V_24 ) ;
unsigned long V_36 = F_44 ( V_24 ) ;
int V_58 ;
T_1 * V_59 , * V_60 ;
unsigned long V_61 ;
V_61 = V_55 + V_36 ;
V_59 = F_26 ( V_61 , V_41 ) ;
if ( ! V_59 )
return - V_42 ;
V_60 = ( T_1 * ) F_24 ( ( unsigned long ) V_59 , V_36 + 1 ) ;
memcpy ( V_60 , V_54 , V_55 ) ;
V_58 = V_57 -> V_62 ( V_24 , V_60 , V_55 ) ;
memset ( V_60 , 0 , V_55 ) ;
F_6 ( V_59 ) ;
return V_58 ;
}
static int V_62 ( struct V_53 * V_24 , const T_1 * V_54 ,
unsigned int V_55 )
{
struct V_56 * V_57 = F_43 ( V_24 ) ;
unsigned long V_36 = F_44 ( V_24 ) ;
if ( V_55 < V_57 -> V_63 || V_55 > V_57 -> V_64 ) {
F_45 ( V_24 , V_65 ) ;
return - V_29 ;
}
if ( ( unsigned long ) V_54 & V_36 )
return F_42 ( V_24 , V_54 , V_55 ) ;
return V_57 -> V_62 ( V_24 , V_54 , V_55 ) ;
}
static unsigned int F_46 ( struct V_66 * V_67 , T_2 type ,
T_2 V_68 )
{
return V_67 -> V_69 ;
}
static int F_47 ( struct V_23 * V_24 , T_2 type ,
T_2 V_68 )
{
struct V_56 * V_67 = & V_24 -> V_70 -> V_71 ;
struct V_72 * V_73 = & V_24 -> V_33 ;
if ( V_67 -> V_34 > V_51 / 8 )
return - V_29 ;
V_73 -> V_62 = V_62 ;
V_73 -> V_74 = V_67 -> V_74 ;
V_73 -> V_75 = V_67 -> V_75 ;
V_73 -> V_25 = F_48 ( V_24 ) ;
V_73 -> V_34 = V_67 -> V_34 ;
return 0 ;
}
static int F_49 ( struct V_76 * V_77 , struct V_66 * V_67 )
{
struct V_78 V_79 ;
strncpy ( V_79 . type , L_1 , sizeof( V_79 . type ) ) ;
strncpy ( V_79 . V_80 , V_67 -> V_71 . V_80 ? : L_2 ,
sizeof( V_79 . V_80 ) ) ;
V_79 . V_44 = V_67 -> V_81 ;
V_79 . V_63 = V_67 -> V_71 . V_63 ;
V_79 . V_64 = V_67 -> V_71 . V_64 ;
V_79 . V_34 = V_67 -> V_71 . V_34 ;
if ( F_50 ( V_77 , V_82 ,
sizeof( struct V_78 ) , & V_79 ) )
goto V_83;
return 0 ;
V_83:
return - V_84 ;
}
static int F_49 ( struct V_76 * V_77 , struct V_66 * V_67 )
{
return - V_85 ;
}
static void F_51 ( struct V_86 * V_87 , struct V_66 * V_67 )
{
struct V_56 * V_88 = & V_67 -> V_71 ;
F_52 ( V_87 , L_3 ) ;
F_52 ( V_87 , L_4 , V_67 -> V_89 & V_90 ?
L_5 : L_6 ) ;
F_52 ( V_87 , L_7 , V_67 -> V_81 ) ;
F_52 ( V_87 , L_8 , V_88 -> V_63 ) ;
F_52 ( V_87 , L_9 , V_88 -> V_64 ) ;
F_52 ( V_87 , L_10 , V_88 -> V_34 ) ;
F_52 ( V_87 , L_11 , V_88 -> V_80 ? : L_2 ) ;
}
static int F_53 ( struct V_23 * V_24 , T_2 type ,
T_2 V_68 )
{
struct V_56 * V_67 = & V_24 -> V_70 -> V_71 ;
struct V_72 * V_73 = & V_24 -> V_33 ;
if ( V_67 -> V_34 > V_51 / 8 )
return - V_29 ;
V_73 -> V_62 = V_24 -> V_70 -> V_89 & V_91 ?
V_67 -> V_62 : V_62 ;
V_73 -> V_74 = V_67 -> V_74 ;
V_73 -> V_75 = V_67 -> V_75 ;
V_73 -> V_25 = F_48 ( V_24 ) ;
V_73 -> V_34 = V_67 -> V_34 ;
return 0 ;
}
static int F_54 ( struct V_76 * V_77 , struct V_66 * V_67 )
{
struct V_78 V_79 ;
strncpy ( V_79 . type , L_12 , sizeof( V_79 . type ) ) ;
strncpy ( V_79 . V_80 , V_67 -> V_71 . V_80 ? : L_13 ,
sizeof( V_79 . V_80 ) ) ;
V_79 . V_44 = V_67 -> V_81 ;
V_79 . V_63 = V_67 -> V_71 . V_63 ;
V_79 . V_64 = V_67 -> V_71 . V_64 ;
V_79 . V_34 = V_67 -> V_71 . V_34 ;
if ( F_50 ( V_77 , V_82 ,
sizeof( struct V_78 ) , & V_79 ) )
goto V_83;
return 0 ;
V_83:
return - V_84 ;
}
static int F_54 ( struct V_76 * V_77 , struct V_66 * V_67 )
{
return - V_85 ;
}
static void F_55 ( struct V_86 * V_87 , struct V_66 * V_67 )
{
struct V_56 * V_88 = & V_67 -> V_71 ;
F_52 ( V_87 , L_14 ) ;
F_52 ( V_87 , L_4 , V_67 -> V_89 & V_90 ?
L_5 : L_6 ) ;
F_52 ( V_87 , L_7 , V_67 -> V_81 ) ;
F_52 ( V_87 , L_8 , V_88 -> V_63 ) ;
F_52 ( V_87 , L_9 , V_88 -> V_64 ) ;
F_52 ( V_87 , L_10 , V_88 -> V_34 ) ;
F_52 ( V_87 , L_11 , V_88 -> V_80 ? : L_13 ) ;
}
