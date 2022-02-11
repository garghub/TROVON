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
typedef T_1 T_2 ( ( V_18 ) ) T_3;
return V_16 + ( V_17 & ~ ( F_11 ( T_3 ) - 1 ) ) ;
}
static int F_12 ( struct V_19 * V_20 , const T_1 * V_21 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
unsigned int V_22 = V_8 + 1 -
( ( unsigned long ) V_21 & V_8 ) ;
T_1 V_23 [ F_10 ( V_22 , V_8 ) ]
T_2 ( ( V_18 ) ) ;
T_1 * V_24 = F_13 ( & V_23 [ 0 ] , V_8 + 1 ) ;
int V_12 ;
if ( V_22 > V_16 )
V_22 = V_16 ;
memcpy ( V_24 , V_21 , V_22 ) ;
V_12 = V_7 -> V_25 ( V_20 , V_24 , V_22 ) ;
memset ( V_24 , 0 , V_22 ) ;
return V_12 ? :
V_7 -> V_25 ( V_20 , V_21 + V_22 , V_16 - V_22 ) ;
}
int F_14 ( struct V_19 * V_20 , const T_1 * V_21 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_21 & V_8 )
return F_12 ( V_20 , V_21 , V_16 ) ;
return V_7 -> V_25 ( V_20 , V_21 , V_16 ) ;
}
static int F_15 ( struct V_19 * V_20 , T_1 * V_26 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
unsigned long V_8 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned int V_27 = F_16 ( V_2 ) ;
T_1 V_23 [ F_10 ( V_27 , V_8 ) ]
T_2 ( ( V_18 ) ) ;
T_1 * V_24 = F_13 ( & V_23 [ 0 ] , V_8 + 1 ) ;
int V_12 ;
V_12 = V_7 -> V_28 ( V_20 , V_24 ) ;
if ( V_12 )
goto V_26;
memcpy ( V_26 , V_24 , V_27 ) ;
V_26:
memset ( V_24 , 0 , V_27 ) ;
return V_12 ;
}
int F_17 ( struct V_19 * V_20 , T_1 * V_26 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( unsigned long ) V_26 & V_8 )
return F_15 ( V_20 , V_26 ) ;
return V_7 -> V_28 ( V_20 , V_26 ) ;
}
static int F_18 ( struct V_19 * V_20 , const T_1 * V_21 ,
unsigned int V_16 , T_1 * V_26 )
{
return F_14 ( V_20 , V_21 , V_16 ) ? :
F_17 ( V_20 , V_26 ) ;
}
int F_19 ( struct V_19 * V_20 , const T_1 * V_21 ,
unsigned int V_16 , T_1 * V_26 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( ( unsigned long ) V_21 | ( unsigned long ) V_26 ) & V_8 )
return F_18 ( V_20 , V_21 , V_16 , V_26 ) ;
return V_7 -> V_29 ( V_20 , V_21 , V_16 , V_26 ) ;
}
static int F_20 ( struct V_19 * V_20 , const T_1 * V_21 ,
unsigned int V_16 , T_1 * V_26 )
{
return F_21 ( V_20 ) ? :
F_19 ( V_20 , V_21 , V_16 , V_26 ) ;
}
int F_22 ( struct V_19 * V_20 , const T_1 * V_21 ,
unsigned int V_16 , T_1 * V_26 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned long V_8 = F_4 ( V_2 ) ;
if ( ( ( unsigned long ) V_21 | ( unsigned long ) V_26 ) & V_8 )
return F_20 ( V_20 , V_21 , V_16 , V_26 ) ;
return V_7 -> V_30 ( V_20 , V_21 , V_16 , V_26 ) ;
}
static int F_23 ( struct V_19 * V_20 , void * V_26 )
{
memcpy ( V_26 , F_24 ( V_20 ) , F_25 ( V_20 -> V_2 ) ) ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 , const void * V_31 )
{
memcpy ( F_24 ( V_20 ) , V_31 , F_25 ( V_20 -> V_2 ) ) ;
return 0 ;
}
static int F_27 ( struct V_32 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_1 * * V_33 = F_28 ( V_2 ) ;
return F_9 ( * V_33 , V_3 , V_4 ) ;
}
static int F_29 ( struct V_34 * V_35 )
{
struct V_1 * * V_33 = F_28 ( F_30 ( V_35 ) ) ;
struct V_19 * V_20 = F_31 ( V_35 ) ;
V_20 -> V_2 = * V_33 ;
V_20 -> V_36 = V_35 -> V_37 . V_36 ;
return F_21 ( V_20 ) ;
}
int F_32 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_38 V_39 ;
int V_40 ;
for ( V_40 = F_33 ( V_35 , & V_39 ) ; V_40 > 0 ;
V_40 = F_34 ( & V_39 , V_40 ) )
V_40 = F_14 ( V_20 , V_39 . V_21 , V_40 ) ;
return V_40 ;
}
static int F_35 ( struct V_34 * V_35 )
{
return F_32 ( V_35 , F_31 ( V_35 ) ) ;
}
static int F_36 ( struct V_34 * V_35 )
{
return F_17 ( F_31 ( V_35 ) , V_35 -> V_41 ) ;
}
int F_37 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_38 V_39 ;
int V_40 ;
V_40 = F_33 ( V_35 , & V_39 ) ;
if ( ! V_40 )
return F_17 ( V_20 , V_35 -> V_41 ) ;
do {
V_40 = F_38 ( & V_39 ) ?
F_19 ( V_20 , V_39 . V_21 , V_40 ,
V_35 -> V_41 ) :
F_14 ( V_20 , V_39 . V_21 , V_40 ) ;
V_40 = F_34 ( & V_39 , V_40 ) ;
} while ( V_40 > 0 );
return V_40 ;
}
static int F_39 ( struct V_34 * V_35 )
{
struct V_1 * * V_33 = F_28 ( F_30 ( V_35 ) ) ;
struct V_19 * V_20 = F_31 ( V_35 ) ;
V_20 -> V_2 = * V_33 ;
V_20 -> V_36 = V_35 -> V_37 . V_36 ;
return F_37 ( V_35 , V_20 ) ;
}
int F_40 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_42 * V_43 = V_35 -> V_44 ;
unsigned int V_45 = V_43 -> V_45 ;
unsigned int V_40 = V_35 -> V_40 ;
int V_12 ;
if ( V_40 < F_41 ( V_43 -> V_46 , ( ( unsigned int ) ( V_47 ) ) - V_45 ) ) {
void * V_21 ;
V_21 = F_42 ( F_43 ( V_43 ) ) ;
V_12 = F_22 ( V_20 , V_21 + V_45 , V_40 ,
V_35 -> V_41 ) ;
F_44 ( V_21 ) ;
F_45 ( V_20 -> V_36 ) ;
} else
V_12 = F_21 ( V_20 ) ? :
F_37 ( V_35 , V_20 ) ;
return V_12 ;
}
static int F_46 ( struct V_34 * V_35 )
{
struct V_1 * * V_33 = F_28 ( F_30 ( V_35 ) ) ;
struct V_19 * V_20 = F_31 ( V_35 ) ;
V_20 -> V_2 = * V_33 ;
V_20 -> V_36 = V_35 -> V_37 . V_36 ;
return F_40 ( V_35 , V_20 ) ;
}
static int F_47 ( struct V_34 * V_35 , void * V_26 )
{
return F_48 ( F_31 ( V_35 ) , V_26 ) ;
}
static int F_49 ( struct V_34 * V_35 , const void * V_31 )
{
struct V_1 * * V_33 = F_28 ( F_30 ( V_35 ) ) ;
struct V_19 * V_20 = F_31 ( V_35 ) ;
V_20 -> V_2 = * V_33 ;
V_20 -> V_36 = V_35 -> V_37 . V_36 ;
return F_50 ( V_20 , V_31 ) ;
}
static void F_51 ( struct V_48 * V_2 )
{
struct V_1 * * V_33 = F_52 ( V_2 ) ;
F_53 ( * V_33 ) ;
}
int F_54 ( struct V_48 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_51 ;
struct V_6 * V_52 = F_55 ( V_50 ) ;
struct V_32 * V_53 = F_56 ( V_2 ) ;
struct V_1 * * V_33 = F_52 ( V_2 ) ;
struct V_1 * V_7 ;
if ( ! F_57 ( V_50 ) )
return - V_54 ;
V_7 = F_58 ( V_50 , & V_55 ) ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_50 ) ;
return F_61 ( V_7 ) ;
}
* V_33 = V_7 ;
V_2 -> exit = F_51 ;
V_53 -> V_56 = F_29 ;
V_53 -> V_25 = F_35 ;
V_53 -> V_28 = F_36 ;
V_53 -> V_29 = F_39 ;
V_53 -> V_30 = F_46 ;
V_53 -> V_15 = F_27 ;
V_53 -> V_57 = V_52 -> V_15 != F_1 ;
if ( V_52 -> V_58 )
V_53 -> V_58 = F_47 ;
if ( V_52 -> V_59 )
V_53 -> V_59 = F_49 ;
V_53 -> V_60 = sizeof( struct V_19 ) + F_25 ( V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_48 * V_2 )
{
struct V_1 * V_61 = F_63 ( V_2 ) ;
V_61 -> V_62 = F_3 ( V_61 ) -> V_62 ;
return 0 ;
}
static int F_64 ( struct V_63 * V_64 , struct V_49 * V_52 )
{
struct V_65 V_66 ;
struct V_6 * V_67 = F_55 ( V_52 ) ;
strncpy ( V_66 . type , L_1 , sizeof( V_66 . type ) ) ;
V_66 . V_68 = V_52 -> V_69 ;
V_66 . V_70 = V_67 -> V_70 ;
if ( F_65 ( V_64 , V_71 ,
sizeof( struct V_65 ) , & V_66 ) )
goto V_72;
return 0 ;
V_72:
return - V_73 ;
}
static int F_64 ( struct V_63 * V_64 , struct V_49 * V_52 )
{
return - V_5 ;
}
static void F_66 ( struct V_74 * V_75 , struct V_49 * V_52 )
{
struct V_6 * V_67 = F_55 ( V_52 ) ;
F_67 ( V_75 , L_2 ) ;
F_67 ( V_75 , L_3 , V_52 -> V_69 ) ;
F_67 ( V_75 , L_4 , V_67 -> V_70 ) ;
}
struct V_1 * F_68 ( const char * V_76 , T_4 type ,
T_4 V_17 )
{
return F_69 ( V_76 , & V_55 , type , V_17 ) ;
}
static int F_70 ( struct V_6 * V_52 )
{
struct V_49 * V_37 = & V_52 -> V_37 ;
if ( V_52 -> V_70 > V_47 / 8 ||
V_52 -> V_62 > V_47 / 8 ||
V_52 -> V_77 > V_47 / 8 )
return - V_78 ;
V_37 -> V_79 = & V_55 ;
V_37 -> V_80 &= ~ V_81 ;
V_37 -> V_80 |= V_82 ;
if ( ! V_52 -> V_29 )
V_52 -> V_29 = F_18 ;
if ( ! V_52 -> V_30 )
V_52 -> V_30 = F_20 ;
if ( ! V_52 -> V_58 ) {
V_52 -> V_58 = F_23 ;
V_52 -> V_59 = F_26 ;
V_52 -> V_77 = V_52 -> V_62 ;
}
if ( ! V_52 -> V_15 )
V_52 -> V_15 = F_1 ;
return 0 ;
}
int F_71 ( struct V_6 * V_52 )
{
struct V_49 * V_37 = & V_52 -> V_37 ;
int V_12 ;
V_12 = F_70 ( V_52 ) ;
if ( V_12 )
return V_12 ;
return F_72 ( V_37 ) ;
}
int F_73 ( struct V_6 * V_52 )
{
return F_74 ( & V_52 -> V_37 ) ;
}
int F_75 ( struct V_6 * V_83 , int V_84 )
{
int V_85 , V_86 ;
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ ) {
V_86 = F_71 ( & V_83 [ V_85 ] ) ;
if ( V_86 )
goto V_12;
}
return 0 ;
V_12:
for ( -- V_85 ; V_85 >= 0 ; -- V_85 )
F_73 ( & V_83 [ V_85 ] ) ;
return V_86 ;
}
int F_76 ( struct V_6 * V_83 , int V_84 )
{
int V_85 , V_86 ;
for ( V_85 = V_84 - 1 ; V_85 >= 0 ; -- V_85 ) {
V_86 = F_73 ( & V_83 [ V_85 ] ) ;
if ( V_86 )
F_77 ( L_5 ,
V_83 [ V_85 ] . V_37 . V_87 ,
V_83 [ V_85 ] . V_37 . V_88 , V_86 ) ;
}
return 0 ;
}
int F_78 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
int V_12 ;
V_12 = F_70 ( & V_92 -> V_52 ) ;
if ( V_12 )
return V_12 ;
return F_79 ( V_90 , F_80 ( V_92 ) ) ;
}
void F_81 ( struct V_93 * V_92 )
{
F_82 ( F_83 ( V_92 ) ) ;
F_84 ( V_91 ( V_92 ) ) ;
}
int F_85 ( struct V_94 * V_95 ,
struct V_6 * V_52 ,
struct V_93 * V_92 )
{
return F_86 ( & V_95 -> V_37 , & V_52 -> V_37 , V_92 ,
& V_55 ) ;
}
struct V_6 * F_87 ( struct V_96 * V_97 , T_4 type , T_4 V_17 )
{
struct V_49 * V_52 ;
V_52 = F_88 ( V_97 , & V_55 , type , V_17 ) ;
return F_59 ( V_52 ) ? F_89 ( V_52 ) :
F_90 ( V_52 , struct V_6 , V_37 ) ;
}
