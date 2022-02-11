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
typedef T_1 T_2 T_3;
return V_16 + ( V_17 & ~ ( F_11 ( T_3 ) - 1 ) ) ;
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
T_2 ;
T_1 * V_23 = F_13 ( & V_22 [ 0 ] , V_8 + 1 ) ;
int V_12 ;
if ( V_21 > V_16 )
V_21 = V_16 ;
memcpy ( V_23 , V_20 , V_21 ) ;
V_12 = V_7 -> V_24 ( V_19 , V_23 , V_21 ) ;
memset ( V_23 , 0 , V_21 ) ;
return V_12 ? :
V_7 -> V_24 ( V_19 , V_20 + V_21 , V_16 - V_21 ) ;
}
int F_14 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_20 & V_8 )
return F_12 ( V_19 , V_20 , V_16 ) ;
return V_7 -> V_24 ( V_19 , V_20 , V_16 ) ;
}
static int F_15 ( struct V_18 * V_19 , T_1 * V_25 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_8 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned int V_26 = F_16 ( V_2 ) ;
T_1 V_22 [ F_10 ( V_26 , V_8 ) ]
T_2 ;
T_1 * V_23 = F_13 ( & V_22 [ 0 ] , V_8 + 1 ) ;
int V_12 ;
V_12 = V_7 -> V_27 ( V_19 , V_23 ) ;
if ( V_12 )
goto V_25;
memcpy ( V_25 , V_23 , V_26 ) ;
V_25:
memset ( V_23 , 0 , V_26 ) ;
return V_12 ;
}
int F_17 ( struct V_18 * V_19 , T_1 * V_25 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_25 & V_8 )
return F_15 ( V_19 , V_25 ) ;
return V_7 -> V_27 ( V_19 , V_25 ) ;
}
static int F_18 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_25 )
{
return F_14 ( V_19 , V_20 , V_16 ) ? :
F_17 ( V_19 , V_25 ) ;
}
int F_19 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_25 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( ( unsigned long ) V_20 | ( unsigned long ) V_25 ) & V_8 )
return F_18 ( V_19 , V_20 , V_16 , V_25 ) ;
return V_7 -> V_28 ( V_19 , V_20 , V_16 , V_25 ) ;
}
static int F_20 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_25 )
{
return F_21 ( V_19 ) ? :
F_19 ( V_19 , V_20 , V_16 , V_25 ) ;
}
int F_22 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_16 , T_1 * V_25 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( ( unsigned long ) V_20 | ( unsigned long ) V_25 ) & V_8 )
return F_20 ( V_19 , V_20 , V_16 , V_25 ) ;
return V_7 -> V_29 ( V_19 , V_20 , V_16 , V_25 ) ;
}
static int F_23 ( struct V_18 * V_19 , void * V_25 )
{
memcpy ( V_25 , F_24 ( V_19 ) , F_25 ( V_19 -> V_2 ) ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , const void * V_30 )
{
memcpy ( F_24 ( V_19 ) , V_30 , F_25 ( V_19 -> V_2 ) ) ;
return 0 ;
}
static int F_27 ( struct V_31 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_1 * * V_32 = F_28 ( V_2 ) ;
return F_9 ( * V_32 , V_3 , V_4 ) ;
}
static int F_29 ( struct V_33 * V_34 )
{
struct V_1 * * V_32 = F_28 ( F_30 ( V_34 ) ) ;
struct V_18 * V_19 = F_31 ( V_34 ) ;
V_19 -> V_2 = * V_32 ;
V_19 -> V_35 = V_34 -> V_36 . V_35 ;
return F_21 ( V_19 ) ;
}
int F_32 ( struct V_33 * V_34 , struct V_18 * V_19 )
{
struct V_37 V_38 ;
int V_39 ;
for ( V_39 = F_33 ( V_34 , & V_38 ) ; V_39 > 0 ;
V_39 = F_34 ( & V_38 , V_39 ) )
V_39 = F_14 ( V_19 , V_38 . V_20 , V_39 ) ;
return V_39 ;
}
static int F_35 ( struct V_33 * V_34 )
{
return F_32 ( V_34 , F_31 ( V_34 ) ) ;
}
static int F_36 ( struct V_33 * V_34 )
{
return F_17 ( F_31 ( V_34 ) , V_34 -> V_40 ) ;
}
int F_37 ( struct V_33 * V_34 , struct V_18 * V_19 )
{
struct V_37 V_38 ;
int V_39 ;
V_39 = F_33 ( V_34 , & V_38 ) ;
if ( ! V_39 )
return F_17 ( V_19 , V_34 -> V_40 ) ;
do {
V_39 = F_38 ( & V_38 ) ?
F_19 ( V_19 , V_38 . V_20 , V_39 ,
V_34 -> V_40 ) :
F_14 ( V_19 , V_38 . V_20 , V_39 ) ;
V_39 = F_34 ( & V_38 , V_39 ) ;
} while ( V_39 > 0 );
return V_39 ;
}
static int F_39 ( struct V_33 * V_34 )
{
struct V_1 * * V_32 = F_28 ( F_30 ( V_34 ) ) ;
struct V_18 * V_19 = F_31 ( V_34 ) ;
V_19 -> V_2 = * V_32 ;
V_19 -> V_35 = V_34 -> V_36 . V_35 ;
return F_37 ( V_34 , V_19 ) ;
}
int F_40 ( struct V_33 * V_34 , struct V_18 * V_19 )
{
unsigned int V_39 = V_34 -> V_39 ;
struct V_41 * V_42 ;
unsigned int V_43 ;
int V_12 ;
if ( V_39 &&
( V_42 = V_34 -> V_44 , V_43 = V_42 -> V_43 ,
V_39 < F_41 ( V_42 -> V_45 , ( ( unsigned int ) ( V_46 ) ) - V_43 ) ) ) {
void * V_20 ;
V_20 = F_42 ( F_43 ( V_42 ) ) ;
V_12 = F_22 ( V_19 , V_20 + V_43 , V_39 ,
V_34 -> V_40 ) ;
F_44 ( V_20 ) ;
F_45 ( V_19 -> V_35 ) ;
} else
V_12 = F_21 ( V_19 ) ? :
F_37 ( V_34 , V_19 ) ;
return V_12 ;
}
static int F_46 ( struct V_33 * V_34 )
{
struct V_1 * * V_32 = F_28 ( F_30 ( V_34 ) ) ;
struct V_18 * V_19 = F_31 ( V_34 ) ;
V_19 -> V_2 = * V_32 ;
V_19 -> V_35 = V_34 -> V_36 . V_35 ;
return F_40 ( V_34 , V_19 ) ;
}
static int F_47 ( struct V_33 * V_34 , void * V_25 )
{
return F_48 ( F_31 ( V_34 ) , V_25 ) ;
}
static int F_49 ( struct V_33 * V_34 , const void * V_30 )
{
struct V_1 * * V_32 = F_28 ( F_30 ( V_34 ) ) ;
struct V_18 * V_19 = F_31 ( V_34 ) ;
V_19 -> V_2 = * V_32 ;
V_19 -> V_35 = V_34 -> V_36 . V_35 ;
return F_50 ( V_19 , V_30 ) ;
}
static void F_51 ( struct V_47 * V_2 )
{
struct V_1 * * V_32 = F_52 ( V_2 ) ;
F_53 ( * V_32 ) ;
}
int F_54 ( struct V_47 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
struct V_6 * V_51 = F_55 ( V_49 ) ;
struct V_31 * V_52 = F_56 ( V_2 ) ;
struct V_1 * * V_32 = F_52 ( V_2 ) ;
struct V_1 * V_7 ;
if ( ! F_57 ( V_49 ) )
return - V_53 ;
V_7 = F_58 ( V_49 , & V_54 ) ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_49 ) ;
return F_61 ( V_7 ) ;
}
* V_32 = V_7 ;
V_2 -> exit = F_51 ;
V_52 -> V_55 = F_29 ;
V_52 -> V_24 = F_35 ;
V_52 -> V_27 = F_36 ;
V_52 -> V_28 = F_39 ;
V_52 -> V_29 = F_46 ;
V_52 -> V_15 = F_27 ;
V_52 -> V_56 = V_51 -> V_15 != F_1 ;
if ( V_51 -> V_57 )
V_52 -> V_57 = F_47 ;
if ( V_51 -> V_58 )
V_52 -> V_58 = F_49 ;
V_52 -> V_59 = sizeof( struct V_18 ) + F_25 ( V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_47 * V_2 )
{
struct V_1 * V_60 = F_63 ( V_2 ) ;
V_60 -> V_61 = F_3 ( V_60 ) -> V_61 ;
return 0 ;
}
static int F_64 ( struct V_62 * V_63 , struct V_48 * V_51 )
{
struct V_64 V_65 ;
struct V_6 * V_66 = F_55 ( V_51 ) ;
strncpy ( V_65 . type , L_1 , sizeof( V_65 . type ) ) ;
V_65 . V_67 = V_51 -> V_68 ;
V_65 . V_69 = V_66 -> V_69 ;
if ( F_65 ( V_63 , V_70 ,
sizeof( struct V_64 ) , & V_65 ) )
goto V_71;
return 0 ;
V_71:
return - V_72 ;
}
static int F_64 ( struct V_62 * V_63 , struct V_48 * V_51 )
{
return - V_5 ;
}
static void F_66 ( struct V_73 * V_74 , struct V_48 * V_51 )
{
struct V_6 * V_66 = F_55 ( V_51 ) ;
F_67 ( V_74 , L_2 ) ;
F_67 ( V_74 , L_3 , V_51 -> V_68 ) ;
F_67 ( V_74 , L_4 , V_66 -> V_69 ) ;
}
struct V_1 * F_68 ( const char * V_75 , T_4 type ,
T_4 V_17 )
{
return F_69 ( V_75 , & V_54 , type , V_17 ) ;
}
static int F_70 ( struct V_6 * V_51 )
{
struct V_48 * V_36 = & V_51 -> V_36 ;
if ( V_51 -> V_69 > V_46 / 8 ||
V_51 -> V_61 > V_46 / 8 ||
V_51 -> V_76 > V_46 / 8 )
return - V_77 ;
V_36 -> V_78 = & V_54 ;
V_36 -> V_79 &= ~ V_80 ;
V_36 -> V_79 |= V_81 ;
if ( ! V_51 -> V_28 )
V_51 -> V_28 = F_18 ;
if ( ! V_51 -> V_29 )
V_51 -> V_29 = F_20 ;
if ( ! V_51 -> V_57 ) {
V_51 -> V_57 = F_23 ;
V_51 -> V_58 = F_26 ;
V_51 -> V_76 = V_51 -> V_61 ;
}
if ( ! V_51 -> V_15 )
V_51 -> V_15 = F_1 ;
return 0 ;
}
int F_71 ( struct V_6 * V_51 )
{
struct V_48 * V_36 = & V_51 -> V_36 ;
int V_12 ;
V_12 = F_70 ( V_51 ) ;
if ( V_12 )
return V_12 ;
return F_72 ( V_36 ) ;
}
int F_73 ( struct V_6 * V_51 )
{
return F_74 ( & V_51 -> V_36 ) ;
}
int F_75 ( struct V_6 * V_82 , int V_83 )
{
int V_84 , V_85 ;
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
V_85 = F_71 ( & V_82 [ V_84 ] ) ;
if ( V_85 )
goto V_12;
}
return 0 ;
V_12:
for ( -- V_84 ; V_84 >= 0 ; -- V_84 )
F_73 ( & V_82 [ V_84 ] ) ;
return V_85 ;
}
int F_76 ( struct V_6 * V_82 , int V_83 )
{
int V_84 , V_85 ;
for ( V_84 = V_83 - 1 ; V_84 >= 0 ; -- V_84 ) {
V_85 = F_73 ( & V_82 [ V_84 ] ) ;
if ( V_85 )
F_77 ( L_5 ,
V_82 [ V_84 ] . V_36 . V_86 ,
V_82 [ V_84 ] . V_36 . V_87 , V_85 ) ;
}
return 0 ;
}
int F_78 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
int V_12 ;
V_12 = F_70 ( & V_91 -> V_51 ) ;
if ( V_12 )
return V_12 ;
return F_79 ( V_89 , F_80 ( V_91 ) ) ;
}
void F_81 ( struct V_92 * V_91 )
{
F_82 ( F_83 ( V_91 ) ) ;
F_84 ( V_90 ( V_91 ) ) ;
}
int F_85 ( struct V_93 * V_94 ,
struct V_6 * V_51 ,
struct V_92 * V_91 )
{
return F_86 ( & V_94 -> V_36 , & V_51 -> V_36 , V_91 ,
& V_54 ) ;
}
struct V_6 * F_87 ( struct V_95 * V_96 , T_4 type , T_4 V_17 )
{
struct V_48 * V_51 ;
V_51 = F_88 ( V_96 , & V_54 , type , V_17 ) ;
return F_59 ( V_51 ) ? F_89 ( V_51 ) :
F_90 ( V_51 , struct V_6 , V_36 ) ;
}
