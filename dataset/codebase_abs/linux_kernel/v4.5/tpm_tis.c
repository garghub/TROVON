static int F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
F_2 (id, &dev->pnp.ids, list)
if ( ! strcmp ( V_3 , V_5 -> V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , L_1 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
T_1 V_8 ;
if ( ! F_1 ( V_2 , L_2 ) )
return 1 ;
V_8 = F_5 ( V_9 , 1 ,
(struct V_10 * * ) & V_7 ) ;
if ( F_6 ( V_8 ) ) {
F_7 ( & V_2 -> V_2 , L_3 ) ;
return 0 ;
}
if ( F_8 ( V_7 -> V_11 ) != V_12 )
return 0 ;
return 1 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_9 ( struct V_13 * V_14 , int V_15 )
{
unsigned long V_16 = V_17 + V_14 -> V_18 . V_19 ;
do {
if ( F_10 ( V_14 -> V_18 . V_20 + F_11 ( V_15 ) ) &
V_21 )
return 0 ;
F_12 ( V_22 ) ;
} while ( F_13 ( V_17 , V_16 ) );
return - 1 ;
}
static int F_14 ( struct V_13 * V_14 , int V_15 )
{
if ( ( F_10 ( V_14 -> V_18 . V_20 + F_11 ( V_15 ) ) &
( V_23 | V_21 ) ) ==
( V_23 | V_21 ) )
return V_14 -> V_18 . V_24 = V_15 ;
return - 1 ;
}
static void F_15 ( struct V_13 * V_14 , int V_15 , int V_25 )
{
if ( V_25 || ( F_10 ( V_14 -> V_18 . V_20 + F_11 ( V_15 ) ) &
( V_26 | V_21 ) ) ==
( V_26 | V_21 ) )
F_16 ( V_23 ,
V_14 -> V_18 . V_20 + F_11 ( V_15 ) ) ;
}
static int F_17 ( struct V_13 * V_14 , int V_15 )
{
unsigned long V_16 , V_27 ;
long V_28 ;
if ( F_14 ( V_14 , V_15 ) >= 0 )
return V_15 ;
F_16 ( V_29 ,
V_14 -> V_18 . V_20 + F_11 ( V_15 ) ) ;
V_16 = V_17 + V_14 -> V_18 . V_19 ;
if ( V_14 -> V_18 . V_30 ) {
V_31:
V_27 = V_16 - V_17 ;
if ( ( long ) V_27 <= 0 )
return - 1 ;
V_28 = F_18 ( V_14 -> V_18 . V_32 ,
( F_14
( V_14 , V_15 ) >= 0 ) ,
V_27 ) ;
if ( V_28 > 0 )
return V_15 ;
if ( V_28 == - V_33 && F_19 ( V_34 ) ) {
F_20 ( V_35 ) ;
goto V_31;
}
} else {
do {
if ( F_14 ( V_14 , V_15 ) >= 0 )
return V_15 ;
F_12 ( V_22 ) ;
}
while ( F_13 ( V_17 , V_16 ) );
}
return - 1 ;
}
static T_2 F_21 ( struct V_13 * V_14 )
{
return F_10 ( V_14 -> V_18 . V_20 +
F_22 ( V_14 -> V_18 . V_24 ) ) ;
}
static void F_23 ( struct V_13 * V_14 )
{
F_16 ( V_36 ,
V_14 -> V_18 . V_20 + F_22 ( V_14 -> V_18 . V_24 ) ) ;
}
static int F_24 ( struct V_13 * V_14 )
{
unsigned long V_16 ;
int V_37 ;
V_16 = V_17 + V_14 -> V_18 . V_38 ;
do {
V_37 = F_10 ( V_14 -> V_18 . V_20 +
F_22 ( V_14 -> V_18 . V_24 ) + 1 ) ;
V_37 += F_10 ( V_14 -> V_18 . V_20 +
F_22 ( V_14 -> V_18 . V_24 ) +
2 ) << 8 ;
if ( V_37 )
return V_37 ;
F_12 ( V_22 ) ;
} while ( F_13 ( V_17 , V_16 ) );
return - V_39 ;
}
static int F_25 ( struct V_13 * V_14 , T_2 * V_40 , T_3 V_41 )
{
int V_42 = 0 , V_37 ;
while ( V_42 < V_41 &&
F_26 ( V_14 ,
V_43 | V_44 ,
V_14 -> V_18 . V_45 ,
& V_14 -> V_18 . V_46 , true )
== 0 ) {
V_37 = F_24 ( V_14 ) ;
for (; V_37 > 0 && V_42 < V_41 ; V_37 -- )
V_40 [ V_42 ++ ] = F_10 ( V_14 -> V_18 . V_20 +
F_27 ( V_14 -> V_18 .
V_24 ) ) ;
}
return V_42 ;
}
static int F_28 ( struct V_13 * V_14 , T_2 * V_40 , T_3 V_41 )
{
int V_42 = 0 ;
int V_47 , V_48 ;
if ( V_41 < V_49 ) {
V_42 = - V_50 ;
goto V_51;
}
if ( ( V_42 =
F_25 ( V_14 , V_40 , V_49 ) ) < V_49 ) {
F_7 ( V_14 -> V_52 , L_4 ) ;
goto V_51;
}
V_47 = F_29 ( * ( V_53 * ) ( V_40 + 2 ) ) ;
if ( V_47 > V_41 ) {
V_42 = - V_50 ;
goto V_51;
}
if ( ( V_42 +=
F_25 ( V_14 , & V_40 [ V_49 ] ,
V_47 - V_49 ) ) < V_47 ) {
F_7 ( V_14 -> V_52 , L_5 ) ;
V_42 = - V_54 ;
goto V_51;
}
F_26 ( V_14 , V_44 , V_14 -> V_18 . V_45 ,
& V_14 -> V_18 . V_32 , false ) ;
V_48 = F_21 ( V_14 ) ;
if ( V_48 & V_43 ) {
F_7 ( V_14 -> V_52 , L_6 ) ;
V_42 = - V_50 ;
goto V_51;
}
V_51:
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
return V_42 ;
}
static int F_30 ( struct V_13 * V_14 , T_2 * V_40 , T_3 V_55 )
{
int V_28 , V_48 , V_37 ;
T_3 V_41 = 0 ;
if ( F_17 ( V_14 , 0 ) < 0 )
return - V_39 ;
V_48 = F_21 ( V_14 ) ;
if ( ( V_48 & V_36 ) == 0 ) {
F_23 ( V_14 ) ;
if ( F_26
( V_14 , V_36 , V_14 -> V_18 . V_56 ,
& V_14 -> V_18 . V_32 , false ) < 0 ) {
V_28 = - V_54 ;
goto V_57;
}
}
while ( V_41 < V_55 - 1 ) {
V_37 = F_24 ( V_14 ) ;
for (; V_37 > 0 && V_41 < V_55 - 1 ; V_37 -- ) {
F_16 ( V_40 [ V_41 ] , V_14 -> V_18 . V_20 +
F_27 ( V_14 -> V_18 . V_24 ) ) ;
V_41 ++ ;
}
F_26 ( V_14 , V_44 , V_14 -> V_18 . V_45 ,
& V_14 -> V_18 . V_32 , false ) ;
V_48 = F_21 ( V_14 ) ;
if ( ! V_58 && ( V_48 & V_59 ) == 0 ) {
V_28 = - V_50 ;
goto V_57;
}
}
F_16 ( V_40 [ V_41 ] ,
V_14 -> V_18 . V_20 + F_27 ( V_14 -> V_18 . V_24 ) ) ;
F_26 ( V_14 , V_44 , V_14 -> V_18 . V_45 ,
& V_14 -> V_18 . V_32 , false ) ;
V_48 = F_21 ( V_14 ) ;
if ( ( V_48 & V_59 ) != 0 ) {
V_28 = - V_50 ;
goto V_57;
}
return 0 ;
V_57:
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
return V_28 ;
}
static void F_31 ( struct V_13 * V_14 )
{
T_4 V_60 ;
V_60 =
F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_60 &= ~ V_61 ;
F_34 ( V_60 ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
F_35 ( V_14 -> V_52 , V_14 -> V_18 . V_30 , V_14 ) ;
V_14 -> V_18 . V_30 = 0 ;
}
static int F_36 ( struct V_13 * V_14 , T_2 * V_40 , T_3 V_55 )
{
int V_28 ;
T_4 V_62 ;
unsigned long V_63 ;
V_28 = F_30 ( V_14 , V_40 , V_55 ) ;
if ( V_28 < 0 )
return V_28 ;
F_16 ( V_64 ,
V_14 -> V_18 . V_20 + F_22 ( V_14 -> V_18 . V_24 ) ) ;
if ( V_14 -> V_18 . V_30 ) {
V_62 = F_29 ( * ( ( V_53 * ) ( V_40 + 6 ) ) ) ;
if ( V_14 -> V_65 & V_66 )
V_63 = F_37 ( V_14 , V_62 ) ;
else
V_63 = F_38 ( V_14 , V_62 ) ;
if ( F_26
( V_14 , V_43 | V_44 , V_63 ,
& V_14 -> V_18 . V_46 , false ) < 0 ) {
V_28 = - V_54 ;
goto V_57;
}
}
return V_55 ;
V_57:
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
return V_28 ;
}
static int F_39 ( struct V_13 * V_14 , T_2 * V_40 , T_3 V_55 )
{
int V_28 , V_30 ;
struct V_67 * V_68 = V_14 -> V_18 . V_68 ;
if ( ! V_14 -> V_18 . V_30 || V_68 -> V_69 )
return F_36 ( V_14 , V_40 , V_55 ) ;
V_30 = V_14 -> V_18 . V_30 ;
V_14 -> V_18 . V_30 = 0 ;
V_28 = F_36 ( V_14 , V_40 , V_55 ) ;
V_14 -> V_18 . V_30 = V_30 ;
if ( ! V_68 -> V_69 )
F_12 ( 1 ) ;
if ( ! V_68 -> V_69 )
F_31 ( V_14 ) ;
V_68 -> V_69 = true ;
return V_28 ;
}
static bool F_40 ( struct V_13 * V_14 ,
unsigned long * V_70 )
{
int V_71 ;
T_4 V_72 ;
V_72 = F_32 ( V_14 -> V_18 . V_20 + F_41 ( 0 ) ) ;
for ( V_71 = 0 ; V_71 != F_42 ( V_73 ) ; V_71 ++ ) {
if ( V_73 [ V_71 ] . V_72 != V_72 )
continue;
memcpy ( V_70 , V_73 [ V_71 ] . V_74 ,
sizeof( V_73 [ V_71 ] . V_74 ) ) ;
return true ;
}
return false ;
}
static int F_43 ( struct V_13 * V_14 )
{
int V_28 = 0 ;
T_2 V_75 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_3 V_55 = sizeof( V_75 ) ;
bool V_76 = V_58 ;
T_5 V_18 = F_44 ( V_14 -> V_18 . V_20 + F_41 ( 0 ) ) ;
if ( V_18 != V_77 )
return 0 ;
V_58 = false ;
V_28 = F_30 ( V_14 , V_75 , V_55 ) ;
if ( V_28 == 0 )
goto V_51;
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
V_58 = true ;
V_28 = F_30 ( V_14 , V_75 , V_55 ) ;
if ( V_28 == 0 ) {
F_45 ( V_14 -> V_52 , L_7 ) ;
V_28 = 1 ;
} else
V_28 = - V_78 ;
V_51:
V_58 = V_76 ;
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
return V_28 ;
}
static bool F_46 ( struct V_13 * V_14 , T_2 V_48 )
{
switch ( V_14 -> V_18 . V_79 ) {
case V_80 :
return ( ( V_48 == V_44 ) ||
( V_48 == ( V_44 | V_36 ) ) ) ;
case V_81 :
return ( V_48 == ( V_44 | V_36 ) ) ;
default:
return ( V_48 == V_36 ) ;
}
}
static T_6 F_47 ( int V_82 , void * V_83 )
{
struct V_13 * V_14 = V_83 ;
T_4 V_84 ;
int V_71 ;
V_84 = F_32 ( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
if ( V_84 == 0 )
return V_85 ;
( (struct V_67 * ) V_14 -> V_18 . V_68 ) -> V_69 = true ;
if ( V_84 & V_86 )
F_49 ( & V_14 -> V_18 . V_46 ) ;
if ( V_84 & V_87 )
for ( V_71 = 0 ; V_71 < 5 ; V_71 ++ )
if ( F_14 ( V_14 , V_71 ) >= 0 )
break;
if ( V_84 &
( V_87 | V_88 |
V_89 ) )
F_49 ( & V_14 -> V_18 . V_32 ) ;
F_34 ( V_84 ,
V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
F_32 ( V_14 -> V_18 . V_20 + F_48 ( V_14 -> V_18 . V_24 ) ) ;
return V_90 ;
}
static int F_50 ( struct V_13 * V_14 , T_4 V_60 ,
int V_65 , int V_30 )
{
struct V_67 * V_68 = V_14 -> V_18 . V_68 ;
T_2 V_91 ;
if ( F_51 ( V_14 -> V_52 , V_30 , F_47 , V_65 ,
V_14 -> V_92 , V_14 ) != 0 ) {
F_45 ( V_14 -> V_52 , L_8 ,
V_30 ) ;
return - 1 ;
}
V_14 -> V_18 . V_30 = V_30 ;
V_91 = F_10 ( V_14 -> V_18 . V_20 +
F_52 ( V_14 -> V_18 . V_24 ) ) ;
F_16 ( V_30 ,
V_14 -> V_18 . V_20 + F_52 ( V_14 -> V_18 . V_24 ) ) ;
F_34 ( F_32 ( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ,
V_14 -> V_18 . V_20 + F_48 ( V_14 -> V_18 . V_24 ) ) ;
F_34 ( V_60 | V_61 ,
V_14 -> V_18 . V_20 + F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_68 -> V_69 = false ;
if ( V_14 -> V_65 & V_66 )
F_53 ( V_14 ) ;
else
F_54 ( V_14 ) ;
if ( ! V_14 -> V_18 . V_30 ) {
F_16 ( V_91 ,
V_14 -> V_18 . V_20 +
F_52 ( V_14 -> V_18 . V_24 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_55 ( struct V_13 * V_14 , T_4 V_60 )
{
T_2 V_91 ;
int V_71 ;
V_91 = F_10 ( V_14 -> V_18 . V_20 +
F_52 ( V_14 -> V_18 . V_24 ) ) ;
if ( ! V_91 ) {
if ( F_56 ( V_93 ) )
for ( V_71 = 3 ; V_71 <= 15 ; V_71 ++ )
if ( ! F_50 ( V_14 , V_60 , 0 ,
V_71 ) )
return;
} else if ( ! F_50 ( V_14 , V_60 , 0 ,
V_91 ) )
return;
}
static void F_57 ( struct V_13 * V_14 )
{
if ( V_14 -> V_65 & V_66 )
F_58 ( V_14 , V_94 ) ;
F_34 ( ~ V_61 &
F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 .
V_24 ) ) ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 1 ) ;
}
static int F_59 ( struct V_95 * V_2 , struct V_96 * V_96 ,
T_7 V_97 )
{
T_4 V_18 , V_98 , V_60 ;
int V_28 , V_99 ;
struct V_13 * V_14 ;
struct V_67 * V_68 ;
V_68 = F_60 ( V_2 , sizeof( struct V_67 ) , V_100 ) ;
if ( V_68 == NULL )
return - V_101 ;
V_14 = F_61 ( V_2 , & V_102 ) ;
if ( F_62 ( V_14 ) )
return F_63 ( V_14 ) ;
V_14 -> V_18 . V_68 = V_68 ;
#ifdef F_64
V_14 -> V_97 = V_97 ;
#endif
V_14 -> V_18 . V_20 = F_65 ( V_2 , V_96 -> V_103 , V_96 -> V_55 ) ;
if ( ! V_14 -> V_18 . V_20 )
return - V_50 ;
V_14 -> V_18 . V_19 = V_104 ;
V_14 -> V_18 . V_56 = V_105 ;
V_14 -> V_18 . V_45 = V_106 ;
V_14 -> V_18 . V_38 = V_107 ;
if ( F_9 ( V_14 , 0 ) != 0 ) {
V_28 = - V_108 ;
goto V_57;
}
V_60 = F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_60 |= V_89 | V_87 |
V_86 | V_88 ;
V_60 &= ~ V_61 ;
F_34 ( V_60 ,
V_14 -> V_18 . V_20 + F_33 ( V_14 -> V_18 . V_24 ) ) ;
if ( F_17 ( V_14 , 0 ) != 0 ) {
V_28 = - V_108 ;
goto V_57;
}
V_28 = F_66 ( V_14 ) ;
if ( V_28 )
goto V_57;
V_18 = F_32 ( V_14 -> V_18 . V_20 + F_41 ( 0 ) ) ;
V_14 -> V_18 . V_79 = V_18 ;
F_45 ( V_2 , L_9 ,
( V_14 -> V_65 & V_66 ) ? L_10 : L_11 ,
V_18 >> 16 , F_10 ( V_14 -> V_18 . V_20 + F_67 ( 0 ) ) ) ;
if ( ! V_58 ) {
V_99 = F_43 ( V_14 ) ;
if ( V_99 < 0 ) {
V_28 = - V_108 ;
goto V_57;
}
V_58 = ! ! V_99 ;
}
if ( V_58 )
F_45 ( V_2 , L_12 ) ;
V_98 =
F_32 ( V_14 -> V_18 . V_20 +
F_68 ( V_14 -> V_18 . V_24 ) ) ;
F_69 ( V_2 , L_13 ,
V_98 ) ;
if ( V_98 & V_109 )
F_69 ( V_2 , L_14 ) ;
if ( V_98 & V_89 )
F_69 ( V_2 , L_15 ) ;
if ( V_98 & V_110 )
F_69 ( V_2 , L_16 ) ;
if ( V_98 & V_111 )
F_69 ( V_2 , L_17 ) ;
if ( V_98 & V_112 )
F_69 ( V_2 , L_18 ) ;
if ( V_98 & V_113 )
F_69 ( V_2 , L_19 ) ;
if ( V_98 & V_87 )
F_69 ( V_2 , L_20 ) ;
if ( V_98 & V_88 )
F_69 ( V_2 , L_21 ) ;
if ( V_98 & V_86 )
F_69 ( V_2 , L_22 ) ;
if ( F_70 ( V_14 ) ) {
F_7 ( V_2 , L_23 ) ;
V_28 = - V_108 ;
goto V_57;
}
F_71 ( & V_14 -> V_18 . V_46 ) ;
F_71 ( & V_14 -> V_18 . V_32 ) ;
if ( V_114 ) {
if ( V_96 -> V_30 ) {
F_50 ( V_14 , V_60 , V_115 ,
V_96 -> V_30 ) ;
if ( ! V_14 -> V_18 . V_30 )
F_7 ( V_14 -> V_52 , V_116
L_24 ) ;
} else
F_55 ( V_14 , V_60 ) ;
}
if ( V_14 -> V_65 & V_66 ) {
V_28 = F_72 ( V_14 ) ;
if ( V_28 == V_117 ) {
F_73 ( V_2 , L_25 ) ;
V_28 = F_74 ( V_14 , V_94 ) ;
if ( ! V_28 )
V_28 = F_72 ( V_14 ) ;
}
if ( V_28 ) {
F_7 ( V_2 , L_26 ) ;
if ( V_28 > 0 )
V_28 = - V_108 ;
goto V_57;
}
} else {
if ( F_75 ( V_14 ) ) {
F_7 ( V_2 , L_26 ) ;
V_28 = - V_108 ;
goto V_57;
}
}
return F_76 ( V_14 ) ;
V_57:
F_57 ( V_14 ) ;
return V_28 ;
}
static void F_77 ( struct V_13 * V_14 )
{
T_4 V_60 ;
F_16 ( V_14 -> V_18 . V_30 , V_14 -> V_18 . V_20 +
F_52 ( V_14 -> V_18 . V_24 ) ) ;
V_60 =
F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_60 |= V_89
| V_87 | V_86
| V_88 | V_61 ;
F_34 ( V_60 ,
V_14 -> V_18 . V_20 + F_33 ( V_14 -> V_18 . V_24 ) ) ;
}
static int F_78 ( struct V_95 * V_2 )
{
struct V_13 * V_14 = F_79 ( V_2 ) ;
int V_118 ;
if ( V_14 -> V_18 . V_30 )
F_77 ( V_14 ) ;
V_118 = F_80 ( V_2 ) ;
if ( V_118 )
return V_118 ;
if ( ! ( V_14 -> V_65 & V_66 ) )
F_75 ( V_14 ) ;
return 0 ;
}
static int F_81 ( struct V_119 * V_119 ,
const struct V_120 * V_121 )
{
struct V_96 V_96 = V_122 ;
T_7 V_97 = NULL ;
V_96 . V_103 = F_82 ( V_119 , 0 ) ;
V_96 . V_55 = F_83 ( V_119 , 0 ) ;
if ( F_84 ( V_119 , 0 ) )
V_96 . V_30 = F_85 ( V_119 , 0 ) ;
else
V_114 = false ;
#ifdef F_64
if ( F_86 ( V_119 ) ) {
if ( F_3 ( F_86 ( V_119 ) ) )
V_58 = true ;
V_97 = F_86 ( V_119 ) -> V_123 ;
}
#endif
return F_59 ( & V_119 -> V_2 , & V_96 , V_97 ) ;
}
static void F_87 ( struct V_119 * V_2 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
F_89 ( V_14 ) ;
F_57 ( V_14 ) ;
}
static int F_90 ( struct V_124 * V_125 , void * V_126 )
{
struct V_96 * V_96 = (struct V_96 * ) V_126 ;
struct V_127 V_128 ;
if ( F_91 ( V_125 , 0 , & V_128 ) ) {
V_96 -> V_30 = V_128 . V_103 ;
} else if ( F_92 ( V_125 , & V_128 ) ) {
V_96 -> V_103 = V_128 . V_103 ;
V_96 -> V_55 = F_93 ( & V_128 ) ;
}
return 1 ;
}
static int F_94 ( struct V_1 * V_129 )
{
struct V_130 V_131 ;
struct V_96 V_96 = V_122 ;
int V_118 ;
if ( ! F_4 ( V_129 ) )
return - V_108 ;
F_95 ( & V_131 ) ;
V_118 = F_96 ( V_129 , & V_131 , F_90 ,
& V_96 ) ;
if ( V_118 < 0 )
return V_118 ;
F_97 ( & V_131 ) ;
if ( ! V_96 . V_30 )
V_114 = false ;
if ( F_3 ( V_129 ) )
V_58 = true ;
return F_59 ( & V_129 -> V_2 , & V_96 , V_129 -> V_123 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_79 ( & V_2 -> V_2 ) ;
F_89 ( V_14 ) ;
F_57 ( V_14 ) ;
return 0 ;
}
static int T_8 F_99 ( void )
{
int V_28 ;
#ifdef F_100
if ( ! V_25 ) {
V_28 = F_101 ( & V_132 ) ;
if ( V_28 )
return V_28 ;
}
#endif
#ifdef F_64
if ( ! V_25 ) {
V_28 = F_102 ( & V_133 ) ;
if ( V_28 ) {
#ifdef F_100
F_103 ( & V_132 ) ;
#endif
return V_28 ;
}
}
#endif
if ( ! V_25 )
return 0 ;
V_28 = F_104 ( & V_134 ) ;
if ( V_28 < 0 )
return V_28 ;
V_52 = F_105 ( L_27 , - 1 , NULL , 0 ) ;
if ( F_62 ( V_52 ) ) {
V_28 = F_63 ( V_52 ) ;
goto V_135;
}
V_28 = F_59 ( & V_52 -> V_2 , & V_122 , NULL ) ;
if ( V_28 )
goto V_136;
return 0 ;
V_136:
F_106 ( V_52 ) ;
V_135:
F_107 ( & V_134 ) ;
return V_28 ;
}
static void T_9 F_108 ( void )
{
struct V_13 * V_14 ;
#if F_109 ( F_100 ) || F_109 ( F_64 )
if ( ! V_25 ) {
#ifdef F_64
F_110 ( & V_133 ) ;
#endif
#ifdef F_100
F_103 ( & V_132 ) ;
#endif
return;
}
#endif
V_14 = F_79 ( & V_52 -> V_2 ) ;
F_89 ( V_14 ) ;
F_57 ( V_14 ) ;
F_106 ( V_52 ) ;
F_107 ( & V_134 ) ;
}
