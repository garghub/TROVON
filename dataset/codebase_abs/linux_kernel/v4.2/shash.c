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
if ( V_52 -> V_15 )
V_53 -> V_15 = F_27 ;
if ( V_52 -> V_57 )
V_53 -> V_57 = F_47 ;
if ( V_52 -> V_58 )
V_53 -> V_58 = F_49 ;
V_53 -> V_59 = sizeof( struct V_19 ) + F_25 ( V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_60 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_19 * * V_61 = F_63 ( V_2 ) ;
struct V_19 * V_20 = * V_61 ;
return F_9 ( V_20 -> V_2 , V_3 , V_4 ) ;
}
static int F_64 ( struct V_62 * V_63 )
{
struct V_19 * * V_61 = F_63 ( V_63 -> V_2 ) ;
struct V_19 * V_20 = * V_61 ;
V_20 -> V_36 = V_63 -> V_36 ;
return F_21 ( V_20 ) ;
}
static int F_65 ( struct V_62 * V_63 , struct V_42 * V_43 ,
unsigned int V_16 )
{
struct V_19 * * V_61 = F_63 ( V_63 -> V_2 ) ;
struct V_19 * V_20 = * V_61 ;
struct V_38 V_39 ;
int V_40 ;
for ( V_40 = F_66 ( V_63 , & V_39 , V_43 , V_16 ) ;
V_40 > 0 ; V_40 = F_34 ( & V_39 , V_40 ) )
V_40 = F_14 ( V_20 , V_39 . V_21 , V_40 ) ;
return V_40 ;
}
static int F_67 ( struct V_62 * V_63 , T_1 * V_26 )
{
struct V_19 * * V_61 = F_63 ( V_63 -> V_2 ) ;
return F_17 ( * V_61 , V_26 ) ;
}
static int F_68 ( struct V_62 * V_63 , struct V_42 * V_43 ,
unsigned int V_40 , T_1 * V_26 )
{
unsigned int V_45 = V_43 -> V_45 ;
int V_12 ;
if ( V_40 < F_41 ( V_43 -> V_46 , ( ( unsigned int ) ( V_47 ) ) - V_45 ) ) {
struct V_19 * * V_61 = F_63 ( V_63 -> V_2 ) ;
struct V_19 * V_20 = * V_61 ;
void * V_21 ;
V_20 -> V_36 = V_63 -> V_36 ;
V_21 = F_42 ( F_43 ( V_43 ) ) ;
V_12 = F_22 ( V_20 , V_21 + V_45 , V_40 , V_26 ) ;
F_44 ( V_21 ) ;
F_45 ( V_20 -> V_36 ) ;
goto V_26;
}
V_12 = F_64 ( V_63 ) ;
if ( V_12 )
goto V_26;
V_12 = F_65 ( V_63 , V_43 , V_40 ) ;
if ( V_12 )
goto V_26;
V_12 = F_67 ( V_63 , V_26 ) ;
V_26:
return V_12 ;
}
static void F_69 ( struct V_48 * V_2 )
{
struct V_19 * * V_61 = F_52 ( V_2 ) ;
struct V_19 * V_20 = * V_61 ;
F_53 ( V_20 -> V_2 ) ;
F_8 ( V_20 ) ;
}
static int F_70 ( struct V_48 * V_2 )
{
struct V_64 * V_53 = & V_2 -> V_65 ;
struct V_49 * V_50 = V_2 -> V_51 ;
struct V_6 * V_52 = F_55 ( V_50 ) ;
struct V_19 * * V_61 = F_52 ( V_2 ) ;
struct V_1 * V_7 ;
struct V_19 * V_20 ;
if ( ! F_57 ( V_50 ) )
return - V_54 ;
V_7 = F_58 ( V_50 , & V_55 ) ;
if ( F_59 ( V_7 ) ) {
F_60 ( V_50 ) ;
return F_61 ( V_7 ) ;
}
V_20 = F_6 ( sizeof( * V_20 ) + F_25 ( V_7 ) ,
V_13 ) ;
if ( ! V_20 ) {
F_53 ( V_7 ) ;
return - V_14 ;
}
* V_61 = V_20 ;
V_20 -> V_2 = V_7 ;
V_2 -> exit = F_69 ;
V_53 -> V_56 = F_64 ;
V_53 -> V_25 = F_65 ;
V_53 -> V_28 = F_67 ;
V_53 -> V_30 = F_68 ;
V_53 -> V_15 = F_62 ;
V_53 -> V_66 = V_52 -> V_66 ;
return 0 ;
}
static int F_71 ( struct V_48 * V_2 , T_4 type , T_4 V_17 )
{
switch ( V_17 & V_67 ) {
case V_68 :
return F_70 ( V_2 ) ;
}
return - V_69 ;
}
static unsigned int F_72 ( struct V_49 * V_52 , T_4 type ,
T_4 V_17 )
{
switch ( V_17 & V_67 ) {
case V_68 :
return sizeof( struct V_19 * ) ;
}
return 0 ;
}
static int F_73 ( struct V_48 * V_2 )
{
struct V_1 * V_70 = F_74 ( V_2 ) ;
V_70 -> V_71 = F_3 ( V_70 ) -> V_71 ;
return 0 ;
}
static int F_75 ( struct V_72 * V_73 , struct V_49 * V_52 )
{
struct V_74 V_75 ;
struct V_6 * V_76 = F_55 ( V_52 ) ;
strncpy ( V_75 . type , L_1 , sizeof( V_75 . type ) ) ;
V_75 . V_77 = V_52 -> V_78 ;
V_75 . V_66 = V_76 -> V_66 ;
if ( F_76 ( V_73 , V_79 ,
sizeof( struct V_74 ) , & V_75 ) )
goto V_80;
return 0 ;
V_80:
return - V_81 ;
}
static int F_75 ( struct V_72 * V_73 , struct V_49 * V_52 )
{
return - V_5 ;
}
static void F_77 ( struct V_82 * V_83 , struct V_49 * V_52 )
{
struct V_6 * V_76 = F_55 ( V_52 ) ;
F_78 ( V_83 , L_2 ) ;
F_78 ( V_83 , L_3 , V_52 -> V_78 ) ;
F_78 ( V_83 , L_4 , V_76 -> V_66 ) ;
}
struct V_1 * F_79 ( const char * V_84 , T_4 type ,
T_4 V_17 )
{
return F_80 ( V_84 , & V_55 , type , V_17 ) ;
}
static int F_81 ( struct V_6 * V_52 )
{
struct V_49 * V_37 = & V_52 -> V_37 ;
if ( V_52 -> V_66 > V_47 / 8 ||
V_52 -> V_71 > V_47 / 8 ||
V_52 -> V_85 > V_47 / 8 )
return - V_69 ;
V_37 -> V_86 = & V_55 ;
V_37 -> V_87 &= ~ V_67 ;
V_37 -> V_87 |= V_88 ;
if ( ! V_52 -> V_29 )
V_52 -> V_29 = F_18 ;
if ( ! V_52 -> V_30 )
V_52 -> V_30 = F_20 ;
if ( ! V_52 -> V_57 ) {
V_52 -> V_57 = F_23 ;
V_52 -> V_58 = F_26 ;
V_52 -> V_85 = V_52 -> V_71 ;
}
if ( ! V_52 -> V_15 )
V_52 -> V_15 = F_1 ;
return 0 ;
}
int F_82 ( struct V_6 * V_52 )
{
struct V_49 * V_37 = & V_52 -> V_37 ;
int V_12 ;
V_12 = F_81 ( V_52 ) ;
if ( V_12 )
return V_12 ;
return F_83 ( V_37 ) ;
}
int F_84 ( struct V_6 * V_52 )
{
return F_85 ( & V_52 -> V_37 ) ;
}
int F_86 ( struct V_6 * V_89 , int V_90 )
{
int V_91 , V_92 ;
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ ) {
V_92 = F_82 ( & V_89 [ V_91 ] ) ;
if ( V_92 )
goto V_12;
}
return 0 ;
V_12:
for ( -- V_91 ; V_91 >= 0 ; -- V_91 )
F_84 ( & V_89 [ V_91 ] ) ;
return V_92 ;
}
int F_87 ( struct V_6 * V_89 , int V_90 )
{
int V_91 , V_92 ;
for ( V_91 = V_90 - 1 ; V_91 >= 0 ; -- V_91 ) {
V_92 = F_84 ( & V_89 [ V_91 ] ) ;
if ( V_92 )
F_88 ( L_5 ,
V_89 [ V_91 ] . V_37 . V_93 ,
V_89 [ V_91 ] . V_37 . V_94 , V_92 ) ;
}
return 0 ;
}
int F_89 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
int V_12 ;
V_12 = F_81 ( & V_98 -> V_52 ) ;
if ( V_12 )
return V_12 ;
return F_90 ( V_96 , F_91 ( V_98 ) ) ;
}
void F_92 ( struct V_99 * V_98 )
{
F_93 ( F_94 ( V_98 ) ) ;
F_95 ( V_97 ( V_98 ) ) ;
}
int F_96 ( struct V_100 * V_101 ,
struct V_6 * V_52 ,
struct V_99 * V_98 )
{
return F_97 ( & V_101 -> V_37 , & V_52 -> V_37 , V_98 ,
& V_55 ) ;
}
struct V_6 * F_98 ( struct V_102 * V_103 , T_4 type , T_4 V_17 )
{
struct V_49 * V_52 ;
V_52 = F_99 ( V_103 , & V_55 , type , V_17 ) ;
return F_59 ( V_52 ) ? F_100 ( V_52 ) :
F_101 ( V_52 , struct V_6 , V_37 ) ;
}
