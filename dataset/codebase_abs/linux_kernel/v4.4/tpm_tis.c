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
F_35 ( V_14 -> V_18 . V_30 , V_14 ) ;
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
if ( ! V_68 -> V_69 ) {
F_31 ( V_14 ) ;
F_7 ( V_14 -> V_52 ,
V_70 L_7 ) ;
}
V_68 -> V_69 = true ;
return V_28 ;
}
static bool F_40 ( struct V_13 * V_14 ,
unsigned long * V_71 )
{
int V_72 ;
T_4 V_73 ;
V_73 = F_32 ( V_14 -> V_18 . V_20 + F_41 ( 0 ) ) ;
for ( V_72 = 0 ; V_72 != F_42 ( V_74 ) ; V_72 ++ ) {
if ( V_74 [ V_72 ] . V_73 != V_73 )
continue;
memcpy ( V_71 , V_74 [ V_72 ] . V_75 ,
sizeof( V_74 [ V_72 ] . V_75 ) ) ;
return true ;
}
return false ;
}
static int F_43 ( struct V_13 * V_14 )
{
int V_28 = 0 ;
T_2 V_76 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_3 V_55 = sizeof( V_76 ) ;
bool V_77 = V_58 ;
T_5 V_18 = F_44 ( V_14 -> V_18 . V_20 + F_41 ( 0 ) ) ;
if ( V_18 != V_78 )
return 0 ;
V_58 = false ;
V_28 = F_30 ( V_14 , V_76 , V_55 ) ;
if ( V_28 == 0 )
goto V_51;
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
V_58 = true ;
V_28 = F_30 ( V_14 , V_76 , V_55 ) ;
if ( V_28 == 0 ) {
F_45 ( V_14 -> V_52 , L_8 ) ;
V_28 = 1 ;
} else
V_28 = - V_79 ;
V_51:
V_58 = V_77 ;
F_23 ( V_14 ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 0 ) ;
return V_28 ;
}
static bool F_46 ( struct V_13 * V_14 , T_2 V_48 )
{
switch ( V_14 -> V_18 . V_80 ) {
case V_81 :
return ( ( V_48 == V_44 ) ||
( V_48 == ( V_44 | V_36 ) ) ) ;
case V_82 :
return ( V_48 == ( V_44 | V_36 ) ) ;
default:
return ( V_48 == V_36 ) ;
}
}
static T_6 F_47 ( int V_30 , void * V_83 )
{
struct V_13 * V_14 = V_83 ;
T_4 V_84 ;
V_84 = F_32 ( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
if ( V_84 == 0 )
return V_85 ;
V_14 -> V_18 . V_86 = V_30 ;
F_34 ( V_84 ,
V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
return V_87 ;
}
static T_6 F_49 ( int V_88 , void * V_83 )
{
struct V_13 * V_14 = V_83 ;
T_4 V_84 ;
int V_72 ;
V_84 = F_32 ( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
if ( V_84 == 0 )
return V_85 ;
( (struct V_67 * ) V_14 -> V_18 . V_68 ) -> V_69 = true ;
if ( V_84 & V_89 )
F_50 ( & V_14 -> V_18 . V_46 ) ;
if ( V_84 & V_90 )
for ( V_72 = 0 ; V_72 < 5 ; V_72 ++ )
if ( F_14 ( V_14 , V_72 ) >= 0 )
break;
if ( V_84 &
( V_90 | V_91 |
V_92 ) )
F_50 ( & V_14 -> V_18 . V_32 ) ;
F_34 ( V_84 ,
V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
F_32 ( V_14 -> V_18 . V_20 + F_48 ( V_14 -> V_18 . V_24 ) ) ;
return V_87 ;
}
static void F_51 ( struct V_13 * V_14 )
{
if ( V_14 -> V_65 & V_66 )
F_52 ( V_14 , V_93 ) ;
F_34 ( ~ V_61 &
F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 .
V_24 ) ) ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
F_15 ( V_14 , V_14 -> V_18 . V_24 , 1 ) ;
}
static int F_53 ( struct V_94 * V_2 , struct V_95 * V_95 ,
T_7 V_96 )
{
T_4 V_18 , V_97 , V_60 ;
int V_28 , V_72 , V_98 , V_99 , V_100 ;
int V_101 = - 1 ;
struct V_13 * V_14 ;
struct V_67 * V_68 ;
V_68 = F_54 ( V_2 , sizeof( struct V_67 ) , V_102 ) ;
if ( V_68 == NULL )
return - V_103 ;
V_14 = F_55 ( V_2 , & V_104 ) ;
if ( F_56 ( V_14 ) )
return F_57 ( V_14 ) ;
V_14 -> V_18 . V_68 = V_68 ;
#ifdef F_58
V_14 -> V_96 = V_96 ;
#endif
V_14 -> V_18 . V_20 = F_59 ( V_2 , V_95 -> V_105 , V_95 -> V_55 ) ;
if ( ! V_14 -> V_18 . V_20 )
return - V_50 ;
V_14 -> V_18 . V_19 = V_106 ;
V_14 -> V_18 . V_56 = V_107 ;
V_14 -> V_18 . V_45 = V_108 ;
V_14 -> V_18 . V_38 = V_109 ;
if ( F_9 ( V_14 , 0 ) != 0 ) {
V_28 = - V_110 ;
goto V_57;
}
if ( F_17 ( V_14 , 0 ) != 0 ) {
V_28 = - V_110 ;
goto V_57;
}
V_28 = F_60 ( V_14 ) ;
if ( V_28 )
goto V_57;
V_18 = F_32 ( V_14 -> V_18 . V_20 + F_41 ( 0 ) ) ;
V_14 -> V_18 . V_80 = V_18 ;
F_45 ( V_2 , L_9 ,
( V_14 -> V_65 & V_66 ) ? L_10 : L_11 ,
V_18 >> 16 , F_10 ( V_14 -> V_18 . V_20 + F_61 ( 0 ) ) ) ;
if ( ! V_58 ) {
V_100 = F_43 ( V_14 ) ;
if ( V_100 < 0 ) {
V_28 = - V_110 ;
goto V_57;
}
V_58 = ! ! V_100 ;
}
if ( V_58 )
F_45 ( V_2 , L_12 ) ;
V_97 =
F_32 ( V_14 -> V_18 . V_20 +
F_62 ( V_14 -> V_18 . V_24 ) ) ;
F_63 ( V_2 , L_13 ,
V_97 ) ;
if ( V_97 & V_111 )
F_63 ( V_2 , L_14 ) ;
if ( V_97 & V_92 )
F_63 ( V_2 , L_15 ) ;
if ( V_97 & V_112 )
F_63 ( V_2 , L_16 ) ;
if ( V_97 & V_113 )
F_63 ( V_2 , L_17 ) ;
if ( V_97 & V_114 )
F_63 ( V_2 , L_18 ) ;
if ( V_97 & V_115 )
F_63 ( V_2 , L_19 ) ;
if ( V_97 & V_90 )
F_63 ( V_2 , L_20 ) ;
if ( V_97 & V_91 )
F_63 ( V_2 , L_21 ) ;
if ( V_97 & V_89 )
F_63 ( V_2 , L_22 ) ;
F_64 ( & V_14 -> V_18 . V_46 ) ;
F_64 ( & V_14 -> V_18 . V_32 ) ;
V_60 =
F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_60 |= V_92
| V_90 | V_89
| V_91 ;
F_34 ( V_60 ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
if ( V_116 )
V_14 -> V_18 . V_30 = V_95 -> V_30 ;
if ( V_116 && ! V_14 -> V_18 . V_30 ) {
V_98 =
F_10 ( V_14 -> V_18 . V_20 +
F_65 ( V_14 -> V_18 . V_24 ) ) ;
V_101 = V_98 ;
if ( V_98 ) {
V_99 = V_98 ;
} else {
V_98 = 3 ;
V_99 = 15 ;
}
for ( V_72 = V_98 ; V_72 <= V_99 && V_14 -> V_18 . V_30 == 0 ; V_72 ++ ) {
F_16 ( V_72 , V_14 -> V_18 . V_20 +
F_65 ( V_14 -> V_18 . V_24 ) ) ;
if ( F_66
( V_2 , V_72 , F_47 , V_117 ,
V_14 -> V_118 , V_14 ) != 0 ) {
F_45 ( V_14 -> V_52 ,
L_23 ,
V_72 ) ;
continue;
}
F_34 ( F_32
( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ,
V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
F_34 ( V_60 | V_61 ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_14 -> V_18 . V_86 = 0 ;
if ( V_14 -> V_65 & V_66 )
F_67 ( V_14 ) ;
else
F_68 ( V_14 ) ;
V_14 -> V_18 . V_30 = V_14 -> V_18 . V_86 ;
F_34 ( F_32
( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ,
V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
F_34 ( V_60 ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
F_69 ( V_2 , V_72 , V_14 ) ;
}
}
if ( V_14 -> V_18 . V_30 ) {
F_16 ( V_14 -> V_18 . V_30 ,
V_14 -> V_18 . V_20 +
F_65 ( V_14 -> V_18 . V_24 ) ) ;
if ( F_66
( V_2 , V_14 -> V_18 . V_30 , F_49 , V_117 ,
V_14 -> V_118 , V_14 ) != 0 ) {
F_45 ( V_14 -> V_52 ,
L_24 ,
V_14 -> V_18 . V_30 ) ;
V_14 -> V_18 . V_30 = 0 ;
} else {
F_34 ( F_32
( V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ,
V_14 -> V_18 . V_20 +
F_48 ( V_14 -> V_18 . V_24 ) ) ;
F_34 ( V_60 | V_61 ,
V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
}
} else if ( V_101 != - 1 )
F_16 ( V_101 , V_14 -> V_18 . V_20 +
F_65 ( V_14 -> V_18 . V_24 ) ) ;
if ( V_14 -> V_65 & V_66 ) {
V_14 -> V_18 . V_19 = F_70 ( V_119 ) ;
V_14 -> V_18 . V_56 = F_70 ( V_120 ) ;
V_14 -> V_18 . V_45 = F_70 ( V_121 ) ;
V_14 -> V_18 . V_38 = F_70 ( V_122 ) ;
V_14 -> V_18 . V_123 [ V_124 ] =
F_70 ( V_125 ) ;
V_14 -> V_18 . V_123 [ V_126 ] =
F_70 ( V_127 ) ;
V_14 -> V_18 . V_123 [ V_128 ] =
F_70 ( V_129 ) ;
V_28 = F_71 ( V_14 ) ;
if ( V_28 == V_130 ) {
F_72 ( V_2 , L_25 ) ;
V_28 = F_73 ( V_14 , V_93 ) ;
if ( ! V_28 )
V_28 = F_71 ( V_14 ) ;
}
if ( V_28 ) {
F_7 ( V_2 , L_26 ) ;
if ( V_28 > 0 )
V_28 = - V_110 ;
goto V_57;
}
} else {
if ( F_74 ( V_14 ) ) {
F_7 ( V_2 , L_27 ) ;
V_28 = - V_110 ;
goto V_57;
}
if ( F_75 ( V_14 ) ) {
F_7 ( V_2 , L_26 ) ;
V_28 = - V_110 ;
goto V_57;
}
}
return F_76 ( V_14 ) ;
V_57:
F_51 ( V_14 ) ;
return V_28 ;
}
static void F_77 ( struct V_13 * V_14 )
{
T_4 V_60 ;
F_16 ( V_14 -> V_18 . V_30 , V_14 -> V_18 . V_20 +
F_65 ( V_14 -> V_18 . V_24 ) ) ;
V_60 =
F_32 ( V_14 -> V_18 . V_20 +
F_33 ( V_14 -> V_18 . V_24 ) ) ;
V_60 |= V_92
| V_90 | V_89
| V_91 | V_61 ;
F_34 ( V_60 ,
V_14 -> V_18 . V_20 + F_33 ( V_14 -> V_18 . V_24 ) ) ;
}
static int F_78 ( struct V_94 * V_2 )
{
struct V_13 * V_14 = F_79 ( V_2 ) ;
int V_131 ;
if ( V_14 -> V_18 . V_30 )
F_77 ( V_14 ) ;
V_131 = F_80 ( V_2 ) ;
if ( V_131 )
return V_131 ;
if ( ! ( V_14 -> V_65 & V_66 ) )
F_75 ( V_14 ) ;
return 0 ;
}
static int F_81 ( struct V_132 * V_132 ,
const struct V_133 * V_134 )
{
struct V_95 V_95 = V_135 ;
T_7 V_96 = NULL ;
V_95 . V_105 = F_82 ( V_132 , 0 ) ;
V_95 . V_55 = F_83 ( V_132 , 0 ) ;
if ( F_84 ( V_132 , 0 ) )
V_95 . V_30 = F_85 ( V_132 , 0 ) ;
else
V_116 = false ;
#ifdef F_58
if ( F_86 ( V_132 ) ) {
if ( F_3 ( F_86 ( V_132 ) ) )
V_58 = true ;
V_96 = F_86 ( V_132 ) -> V_136 ;
}
#endif
return F_53 ( & V_132 -> V_2 , & V_95 , V_96 ) ;
}
static void F_87 ( struct V_132 * V_2 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
F_89 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static int F_90 ( struct V_137 * V_138 , void * V_139 )
{
struct V_95 * V_95 = (struct V_95 * ) V_139 ;
struct V_140 V_141 ;
if ( F_91 ( V_138 , 0 , & V_141 ) ) {
V_95 -> V_30 = V_141 . V_105 ;
} else if ( F_92 ( V_138 , & V_141 ) ) {
V_95 -> V_105 = V_141 . V_105 ;
V_95 -> V_55 = F_93 ( & V_141 ) ;
}
return 1 ;
}
static int F_94 ( struct V_1 * V_142 )
{
struct V_143 V_144 ;
struct V_95 V_95 = V_135 ;
int V_131 ;
if ( ! F_4 ( V_142 ) )
return - V_110 ;
F_95 ( & V_144 ) ;
V_131 = F_96 ( V_142 , & V_144 , F_90 ,
& V_95 ) ;
if ( V_131 < 0 )
return V_131 ;
F_97 ( & V_144 ) ;
if ( ! V_95 . V_30 )
V_116 = false ;
if ( F_3 ( V_142 ) )
V_58 = true ;
return F_53 ( & V_142 -> V_2 , & V_95 , V_142 -> V_136 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_79 ( & V_2 -> V_2 ) ;
F_89 ( V_14 ) ;
F_51 ( V_14 ) ;
return 0 ;
}
static int T_8 F_99 ( void )
{
int V_28 ;
#ifdef F_100
if ( ! V_25 ) {
V_28 = F_101 ( & V_145 ) ;
if ( V_28 )
return V_28 ;
}
#endif
#ifdef F_58
if ( ! V_25 ) {
V_28 = F_102 ( & V_146 ) ;
if ( V_28 ) {
#ifdef F_100
F_103 ( & V_145 ) ;
#endif
return V_28 ;
}
}
#endif
if ( ! V_25 )
return 0 ;
V_28 = F_104 ( & V_147 ) ;
if ( V_28 < 0 )
return V_28 ;
V_52 = F_105 ( L_28 , - 1 , NULL , 0 ) ;
if ( F_56 ( V_52 ) ) {
V_28 = F_57 ( V_52 ) ;
goto V_148;
}
V_28 = F_53 ( & V_52 -> V_2 , & V_135 , NULL ) ;
if ( V_28 )
goto V_149;
return 0 ;
V_149:
F_106 ( V_52 ) ;
V_148:
F_107 ( & V_147 ) ;
return V_28 ;
}
static void T_9 F_108 ( void )
{
struct V_13 * V_14 ;
#if F_109 ( F_100 ) || F_109 ( F_58 )
if ( ! V_25 ) {
#ifdef F_58
F_110 ( & V_146 ) ;
#endif
#ifdef F_100
F_103 ( & V_145 ) ;
#endif
return;
}
#endif
V_14 = F_79 ( & V_52 -> V_2 ) ;
F_89 ( V_14 ) ;
F_51 ( V_14 ) ;
F_106 ( V_52 ) ;
F_107 ( & V_147 ) ;
}
