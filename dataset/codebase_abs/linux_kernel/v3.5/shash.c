static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return - V_5 ;
}
static int F_2 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
unsigned long V_9 ;
T_1 * V_10 , * V_11 ;
int V_12 ;
V_9 = V_4 + ( V_8 & ~ ( F_5 () - 1 ) ) ;
V_10 = F_6 ( V_9 , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_11 = ( T_1 * ) F_7 ( ( unsigned long ) V_10 , V_8 + 1 ) ;
memcpy ( V_11 , V_3 , V_4 ) ;
V_12 = V_7 -> V_15 ( V_2 , V_11 , V_4 ) ;
F_8 ( V_10 ) ;
return V_12 ;
}
int F_9 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_3 & V_8 )
return F_2 ( V_2 , V_3 , V_4 ) ;
return V_7 -> V_15 ( V_2 , V_3 , V_4 ) ;
}
static inline unsigned int F_10 ( unsigned V_16 ,
unsigned long V_17 )
{
return V_16 + ( V_17 & ~ ( F_11 (u8 __attribute__ ((aligned))) - 1 ) ) ;
}
static int F_12 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
unsigned int V_21 = V_8 + 1 -
( ( unsigned long ) V_20 & V_8 ) ;
T_1 V_22 [ F_10 ( V_21 , V_8 ) ]
V_23 ( ( V_24 ) ) ;
T_1 * V_25 = F_13 ( & V_22 [ 0 ] , V_8 + 1 ) ;
int V_12 ;
if ( V_21 > V_16 )
V_21 = V_16 ;
memcpy ( V_25 , V_20 , V_21 ) ;
V_12 = V_7 -> V_26 ( V_19 , V_25 , V_21 ) ;
memset ( V_25 , 0 , V_21 ) ;
return V_12 ? :
V_7 -> V_26 ( V_19 , V_20 + V_21 , V_16 - V_21 ) ;
}
int F_14 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_20 & V_8 )
return F_12 ( V_19 , V_20 , V_16 ) ;
return V_7 -> V_26 ( V_19 , V_20 , V_16 ) ;
}
static int F_15 ( struct V_18 * V_19 , T_1 * V_27 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_8 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned int V_28 = F_16 ( V_2 ) ;
T_1 V_22 [ F_10 ( V_28 , V_8 ) ]
V_23 ( ( V_24 ) ) ;
T_1 * V_25 = F_13 ( & V_22 [ 0 ] , V_8 + 1 ) ;
int V_12 ;
V_12 = V_7 -> V_29 ( V_19 , V_25 ) ;
if ( V_12 )
goto V_27;
memcpy ( V_27 , V_25 , V_28 ) ;
V_27:
memset ( V_25 , 0 , V_28 ) ;
return V_12 ;
}
int F_17 ( struct V_18 * V_19 , T_1 * V_27 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_27 & V_8 )
return F_15 ( V_19 , V_27 ) ;
return V_7 -> V_29 ( V_19 , V_27 ) ;
}
static int F_18 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_27 )
{
return F_14 ( V_19 , V_20 , V_16 ) ? :
F_17 ( V_19 , V_27 ) ;
}
int F_19 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_27 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( ( unsigned long ) V_20 | ( unsigned long ) V_27 ) & V_8 )
return F_18 ( V_19 , V_20 , V_16 , V_27 ) ;
return V_7 -> V_30 ( V_19 , V_20 , V_16 , V_27 ) ;
}
static int F_20 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_27 )
{
return F_21 ( V_19 ) ? :
F_19 ( V_19 , V_20 , V_16 , V_27 ) ;
}
int F_22 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_27 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( ( unsigned long ) V_20 | ( unsigned long ) V_27 ) & V_8 )
return F_20 ( V_19 , V_20 , V_16 , V_27 ) ;
return V_7 -> V_31 ( V_19 , V_20 , V_16 , V_27 ) ;
}
static int F_23 ( struct V_18 * V_19 , void * V_27 )
{
memcpy ( V_27 , F_24 ( V_19 ) , F_25 ( V_19 -> V_2 ) ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , const void * V_32 )
{
memcpy ( F_24 ( V_19 ) , V_32 , F_25 ( V_19 -> V_2 ) ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_1 * * V_34 = F_28 ( V_2 ) ;
return F_9 ( * V_34 , V_3 , V_4 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_1 * * V_34 = F_28 ( F_30 ( V_36 ) ) ;
struct V_18 * V_19 = F_31 ( V_36 ) ;
V_19 -> V_2 = * V_34 ;
V_19 -> V_37 = V_36 -> V_38 . V_37 ;
return F_21 ( V_19 ) ;
}
int F_32 ( struct V_35 * V_36 , struct V_18 * V_19 )
{
struct V_39 V_40 ;
int V_41 ;
for ( V_41 = F_33 ( V_36 , & V_40 ) ; V_41 > 0 ;
V_41 = F_34 ( & V_40 , V_41 ) )
V_41 = F_14 ( V_19 , V_40 . V_20 , V_41 ) ;
return V_41 ;
}
static int F_35 ( struct V_35 * V_36 )
{
return F_32 ( V_36 , F_31 ( V_36 ) ) ;
}
static int F_36 ( struct V_35 * V_36 )
{
return F_17 ( F_31 ( V_36 ) , V_36 -> V_42 ) ;
}
int F_37 ( struct V_35 * V_36 , struct V_18 * V_19 )
{
struct V_39 V_40 ;
int V_41 ;
V_41 = F_33 ( V_36 , & V_40 ) ;
if ( ! V_41 )
return F_17 ( V_19 , V_36 -> V_42 ) ;
do {
V_41 = F_38 ( & V_40 ) ?
F_19 ( V_19 , V_40 . V_20 , V_41 ,
V_36 -> V_42 ) :
F_14 ( V_19 , V_40 . V_20 , V_41 ) ;
V_41 = F_34 ( & V_40 , V_41 ) ;
} while ( V_41 > 0 );
return V_41 ;
}
static int F_39 ( struct V_35 * V_36 )
{
struct V_1 * * V_34 = F_28 ( F_30 ( V_36 ) ) ;
struct V_18 * V_19 = F_31 ( V_36 ) ;
V_19 -> V_2 = * V_34 ;
V_19 -> V_37 = V_36 -> V_38 . V_37 ;
return F_37 ( V_36 , V_19 ) ;
}
int F_40 ( struct V_35 * V_36 , struct V_18 * V_19 )
{
struct V_43 * V_44 = V_36 -> V_45 ;
unsigned int V_46 = V_44 -> V_46 ;
unsigned int V_41 = V_36 -> V_41 ;
int V_12 ;
if ( V_41 < F_41 ( V_44 -> V_47 , ( ( unsigned int ) ( V_48 ) ) - V_46 ) ) {
void * V_20 ;
V_20 = F_42 ( F_43 ( V_44 ) ) ;
V_12 = F_22 ( V_19 , V_20 + V_46 , V_41 ,
V_36 -> V_42 ) ;
F_44 ( V_20 ) ;
F_45 ( V_19 -> V_37 ) ;
} else
V_12 = F_21 ( V_19 ) ? :
F_37 ( V_36 , V_19 ) ;
return V_12 ;
}
static int F_46 ( struct V_35 * V_36 )
{
struct V_1 * * V_34 = F_28 ( F_30 ( V_36 ) ) ;
struct V_18 * V_19 = F_31 ( V_36 ) ;
V_19 -> V_2 = * V_34 ;
V_19 -> V_37 = V_36 -> V_38 . V_37 ;
return F_40 ( V_36 , V_19 ) ;
}
static int F_47 ( struct V_35 * V_36 , void * V_27 )
{
return F_48 ( F_31 ( V_36 ) , V_27 ) ;
}
static int F_49 ( struct V_35 * V_36 , const void * V_32 )
{
struct V_1 * * V_34 = F_28 ( F_30 ( V_36 ) ) ;
struct V_18 * V_19 = F_31 ( V_36 ) ;
V_19 -> V_2 = * V_34 ;
V_19 -> V_37 = V_36 -> V_38 . V_37 ;
return F_50 ( V_19 , V_32 ) ;
}
static void F_51 ( struct V_49 * V_2 )
{
struct V_1 * * V_34 = F_52 ( V_2 ) ;
F_53 ( * V_34 ) ;
}
int F_54 ( struct V_49 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_6 * V_53 = F_55 ( V_51 ) ;
struct V_33 * V_54 = F_56 ( V_2 ) ;
struct V_1 * * V_34 = F_52 ( V_2 ) ;
struct V_1 * V_7 ;
if ( ! F_57 ( V_51 ) )
return - V_55 ;
V_7 = F_58 ( V_51 , & V_56 ) ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_51 ) ;
return F_61 ( V_7 ) ;
}
* V_34 = V_7 ;
V_2 -> exit = F_51 ;
V_54 -> V_57 = F_29 ;
V_54 -> V_26 = F_35 ;
V_54 -> V_29 = F_36 ;
V_54 -> V_30 = F_39 ;
V_54 -> V_31 = F_46 ;
if ( V_53 -> V_15 )
V_54 -> V_15 = F_27 ;
if ( V_53 -> V_58 )
V_54 -> V_58 = F_47 ;
if ( V_53 -> V_59 )
V_54 -> V_59 = F_49 ;
V_54 -> V_60 = sizeof( struct V_18 ) + F_25 ( V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_61 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_18 * * V_62 = F_63 ( V_2 ) ;
struct V_18 * V_19 = * V_62 ;
return F_9 ( V_19 -> V_2 , V_3 , V_4 ) ;
}
static int F_64 ( struct V_63 * V_64 )
{
struct V_18 * * V_62 = F_63 ( V_64 -> V_2 ) ;
struct V_18 * V_19 = * V_62 ;
V_19 -> V_37 = V_64 -> V_37 ;
return F_21 ( V_19 ) ;
}
static int F_65 ( struct V_63 * V_64 , struct V_43 * V_44 ,
unsigned int V_16 )
{
struct V_18 * * V_62 = F_63 ( V_64 -> V_2 ) ;
struct V_18 * V_19 = * V_62 ;
struct V_39 V_40 ;
int V_41 ;
for ( V_41 = F_66 ( V_64 , & V_40 , V_44 , V_16 ) ;
V_41 > 0 ; V_41 = F_34 ( & V_40 , V_41 ) )
V_41 = F_14 ( V_19 , V_40 . V_20 , V_41 ) ;
return V_41 ;
}
static int F_67 ( struct V_63 * V_64 , T_1 * V_27 )
{
struct V_18 * * V_62 = F_63 ( V_64 -> V_2 ) ;
return F_17 ( * V_62 , V_27 ) ;
}
static int F_68 ( struct V_63 * V_64 , struct V_43 * V_44 ,
unsigned int V_41 , T_1 * V_27 )
{
unsigned int V_46 = V_44 -> V_46 ;
int V_12 ;
if ( V_41 < F_41 ( V_44 -> V_47 , ( ( unsigned int ) ( V_48 ) ) - V_46 ) ) {
struct V_18 * * V_62 = F_63 ( V_64 -> V_2 ) ;
struct V_18 * V_19 = * V_62 ;
void * V_20 ;
V_19 -> V_37 = V_64 -> V_37 ;
V_20 = F_42 ( F_43 ( V_44 ) ) ;
V_12 = F_22 ( V_19 , V_20 + V_46 , V_41 , V_27 ) ;
F_44 ( V_20 ) ;
F_45 ( V_19 -> V_37 ) ;
goto V_27;
}
V_12 = F_64 ( V_64 ) ;
if ( V_12 )
goto V_27;
V_12 = F_65 ( V_64 , V_44 , V_41 ) ;
if ( V_12 )
goto V_27;
V_12 = F_67 ( V_64 , V_27 ) ;
V_27:
return V_12 ;
}
static void F_69 ( struct V_49 * V_2 )
{
struct V_18 * * V_62 = F_52 ( V_2 ) ;
struct V_18 * V_19 = * V_62 ;
F_53 ( V_19 -> V_2 ) ;
F_8 ( V_19 ) ;
}
static int F_70 ( struct V_49 * V_2 )
{
struct V_65 * V_54 = & V_2 -> V_66 ;
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_6 * V_53 = F_55 ( V_51 ) ;
struct V_18 * * V_62 = F_52 ( V_2 ) ;
struct V_1 * V_7 ;
struct V_18 * V_19 ;
if ( ! F_57 ( V_51 ) )
return - V_55 ;
V_7 = F_58 ( V_51 , & V_56 ) ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_51 ) ;
return F_61 ( V_7 ) ;
}
V_19 = F_6 ( sizeof( * V_19 ) + F_25 ( V_7 ) ,
V_13 ) ;
if ( ! V_19 ) {
F_53 ( V_7 ) ;
return - V_14 ;
}
* V_62 = V_19 ;
V_19 -> V_2 = V_7 ;
V_2 -> exit = F_69 ;
V_54 -> V_57 = F_64 ;
V_54 -> V_26 = F_65 ;
V_54 -> V_29 = F_67 ;
V_54 -> V_31 = F_68 ;
V_54 -> V_15 = F_62 ;
V_54 -> V_67 = V_53 -> V_67 ;
return 0 ;
}
static int F_71 ( struct V_49 * V_2 , T_2 type , T_2 V_17 )
{
switch ( V_17 & V_68 ) {
case V_69 :
return F_70 ( V_2 ) ;
}
return - V_70 ;
}
static unsigned int F_72 ( struct V_50 * V_53 , T_2 type ,
T_2 V_17 )
{
switch ( V_17 & V_68 ) {
case V_69 :
return sizeof( struct V_18 * ) ;
}
return 0 ;
}
static int F_73 ( struct V_49 * V_2 )
{
struct V_1 * V_71 = F_74 ( V_2 ) ;
V_71 -> V_72 = F_3 ( V_71 ) -> V_72 ;
return 0 ;
}
static unsigned int F_75 ( struct V_50 * V_53 )
{
return V_53 -> V_73 ;
}
static int F_76 ( struct V_74 * V_75 , struct V_50 * V_53 )
{
struct V_76 V_77 ;
struct V_6 * V_78 = F_55 ( V_53 ) ;
snprintf ( V_77 . type , V_79 , L_1 , L_2 ) ;
V_77 . V_80 = V_53 -> V_81 ;
V_77 . V_67 = V_78 -> V_67 ;
if ( F_77 ( V_75 , V_82 ,
sizeof( struct V_76 ) , & V_77 ) )
goto V_83;
return 0 ;
V_83:
return - V_84 ;
}
static int F_76 ( struct V_74 * V_75 , struct V_50 * V_53 )
{
return - V_5 ;
}
static void F_78 ( struct V_85 * V_86 , struct V_50 * V_53 )
{
struct V_6 * V_78 = F_55 ( V_53 ) ;
F_79 ( V_86 , L_3 ) ;
F_79 ( V_86 , L_4 , V_53 -> V_81 ) ;
F_79 ( V_86 , L_5 , V_78 -> V_67 ) ;
}
struct V_1 * F_80 ( const char * V_87 , T_2 type ,
T_2 V_17 )
{
return F_81 ( V_87 , & V_56 , type , V_17 ) ;
}
static int F_82 ( struct V_6 * V_53 )
{
struct V_50 * V_38 = & V_53 -> V_38 ;
if ( V_53 -> V_67 > V_48 / 8 ||
V_53 -> V_72 > V_48 / 8 ||
V_53 -> V_88 > V_48 / 8 )
return - V_70 ;
V_38 -> V_89 = & V_56 ;
V_38 -> V_90 &= ~ V_68 ;
V_38 -> V_90 |= V_91 ;
if ( ! V_53 -> V_30 )
V_53 -> V_30 = F_18 ;
if ( ! V_53 -> V_31 )
V_53 -> V_31 = F_20 ;
if ( ! V_53 -> V_58 ) {
V_53 -> V_58 = F_23 ;
V_53 -> V_59 = F_26 ;
V_53 -> V_88 = V_53 -> V_72 ;
}
if ( ! V_53 -> V_15 )
V_53 -> V_15 = F_1 ;
return 0 ;
}
int F_83 ( struct V_6 * V_53 )
{
struct V_50 * V_38 = & V_53 -> V_38 ;
int V_12 ;
V_12 = F_82 ( V_53 ) ;
if ( V_12 )
return V_12 ;
return F_84 ( V_38 ) ;
}
int F_85 ( struct V_6 * V_53 )
{
return F_86 ( & V_53 -> V_38 ) ;
}
int F_87 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
int V_12 ;
V_12 = F_82 ( & V_95 -> V_53 ) ;
if ( V_12 )
return V_12 ;
return F_88 ( V_93 , F_89 ( V_95 ) ) ;
}
void F_90 ( struct V_96 * V_95 )
{
F_91 ( F_92 ( V_95 ) ) ;
F_93 ( V_94 ( V_95 ) ) ;
}
int F_94 ( struct V_97 * V_98 ,
struct V_6 * V_53 ,
struct V_96 * V_95 )
{
return F_95 ( & V_98 -> V_38 , & V_53 -> V_38 , V_95 ,
& V_56 ) ;
}
struct V_6 * F_96 ( struct V_99 * V_100 , T_2 type , T_2 V_17 )
{
struct V_50 * V_53 ;
V_53 = F_97 ( V_100 , & V_56 , type , V_17 ) ;
return F_59 ( V_53 ) ? F_98 ( V_53 ) :
F_99 ( V_53 , struct V_6 , V_38 ) ;
}
