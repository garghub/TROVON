static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
if ( ! V_4 )
return 0 ;
F_3 (id, &acpi->pnp.ids, list) {
if ( ! strcmp ( L_1 , V_6 -> V_6 ) )
return 1 ;
}
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_7 * V_8 , int V_9 )
{
unsigned long V_10 = V_11 + V_8 -> V_12 . V_13 ;
do {
if ( F_5 ( V_8 -> V_12 . V_14 + F_6 ( V_9 ) ) &
V_15 )
return 0 ;
F_7 ( V_16 ) ;
} while ( F_8 ( V_11 , V_10 ) );
return - 1 ;
}
static int F_9 ( struct V_7 * V_8 , int V_9 )
{
if ( ( F_5 ( V_8 -> V_12 . V_14 + F_6 ( V_9 ) ) &
( V_17 | V_15 ) ) ==
( V_17 | V_15 ) )
return V_8 -> V_12 . V_18 = V_9 ;
return - 1 ;
}
static void F_10 ( struct V_7 * V_8 , int V_9 , int V_19 )
{
if ( V_19 || ( F_5 ( V_8 -> V_12 . V_14 + F_6 ( V_9 ) ) &
( V_20 | V_15 ) ) ==
( V_20 | V_15 ) )
F_11 ( V_17 ,
V_8 -> V_12 . V_14 + F_6 ( V_9 ) ) ;
}
static int F_12 ( struct V_7 * V_8 , int V_9 )
{
unsigned long V_10 , V_21 ;
long V_22 ;
if ( F_9 ( V_8 , V_9 ) >= 0 )
return V_9 ;
F_11 ( V_23 ,
V_8 -> V_12 . V_14 + F_6 ( V_9 ) ) ;
V_10 = V_11 + V_8 -> V_12 . V_13 ;
if ( V_8 -> V_12 . V_24 ) {
V_25:
V_21 = V_10 - V_11 ;
if ( ( long ) V_21 <= 0 )
return - 1 ;
V_22 = F_13 ( V_8 -> V_12 . V_26 ,
( F_9
( V_8 , V_9 ) >= 0 ) ,
V_21 ) ;
if ( V_22 > 0 )
return V_9 ;
if ( V_22 == - V_27 && F_14 ( V_28 ) ) {
F_15 ( V_29 ) ;
goto V_25;
}
} else {
do {
if ( F_9 ( V_8 , V_9 ) >= 0 )
return V_9 ;
F_7 ( V_16 ) ;
}
while ( F_8 ( V_11 , V_10 ) );
}
return - 1 ;
}
static T_1 F_16 ( struct V_7 * V_8 )
{
return F_5 ( V_8 -> V_12 . V_14 +
F_17 ( V_8 -> V_12 . V_18 ) ) ;
}
static void F_18 ( struct V_7 * V_8 )
{
F_11 ( V_30 ,
V_8 -> V_12 . V_14 + F_17 ( V_8 -> V_12 . V_18 ) ) ;
}
static int F_19 ( struct V_7 * V_8 )
{
unsigned long V_10 ;
int V_31 ;
V_10 = V_11 + V_8 -> V_12 . V_32 ;
do {
V_31 = F_5 ( V_8 -> V_12 . V_14 +
F_17 ( V_8 -> V_12 . V_18 ) + 1 ) ;
V_31 += F_5 ( V_8 -> V_12 . V_14 +
F_17 ( V_8 -> V_12 . V_18 ) +
2 ) << 8 ;
if ( V_31 )
return V_31 ;
F_7 ( V_16 ) ;
} while ( F_8 ( V_11 , V_10 ) );
return - V_33 ;
}
static int F_20 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_35 )
{
int V_36 = 0 , V_31 ;
while ( V_36 < V_35 &&
F_21 ( V_8 ,
V_37 | V_38 ,
V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_40 , true )
== 0 ) {
V_31 = F_19 ( V_8 ) ;
for (; V_31 > 0 && V_36 < V_35 ; V_31 -- )
V_34 [ V_36 ++ ] = F_5 ( V_8 -> V_12 . V_14 +
F_22 ( V_8 -> V_12 .
V_18 ) ) ;
}
return V_36 ;
}
static int F_23 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_35 )
{
int V_36 = 0 ;
int V_41 , V_42 ;
if ( V_35 < V_43 ) {
V_36 = - V_44 ;
goto V_45;
}
if ( ( V_36 =
F_20 ( V_8 , V_34 , V_43 ) ) < V_43 ) {
F_24 ( V_8 -> V_2 , L_2 ) ;
goto V_45;
}
V_41 = F_25 ( * ( V_46 * ) ( V_34 + 2 ) ) ;
if ( V_41 > V_35 ) {
V_36 = - V_44 ;
goto V_45;
}
if ( ( V_36 +=
F_20 ( V_8 , & V_34 [ V_43 ] ,
V_41 - V_43 ) ) < V_41 ) {
F_24 ( V_8 -> V_2 , L_3 ) ;
V_36 = - V_47 ;
goto V_45;
}
F_21 ( V_8 , V_38 , V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_26 , false ) ;
V_42 = F_16 ( V_8 ) ;
if ( V_42 & V_37 ) {
F_24 ( V_8 -> V_2 , L_4 ) ;
V_36 = - V_44 ;
goto V_45;
}
V_45:
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_36 ;
}
static int F_26 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_48 )
{
int V_22 , V_42 , V_31 ;
T_2 V_35 = 0 ;
if ( F_12 ( V_8 , 0 ) < 0 )
return - V_33 ;
V_42 = F_16 ( V_8 ) ;
if ( ( V_42 & V_30 ) == 0 ) {
F_18 ( V_8 ) ;
if ( F_21
( V_8 , V_30 , V_8 -> V_12 . V_49 ,
& V_8 -> V_12 . V_26 , false ) < 0 ) {
V_22 = - V_47 ;
goto V_50;
}
}
while ( V_35 < V_48 - 1 ) {
V_31 = F_19 ( V_8 ) ;
for (; V_31 > 0 && V_35 < V_48 - 1 ; V_31 -- ) {
F_11 ( V_34 [ V_35 ] , V_8 -> V_12 . V_14 +
F_22 ( V_8 -> V_12 . V_18 ) ) ;
V_35 ++ ;
}
F_21 ( V_8 , V_38 , V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_26 , false ) ;
V_42 = F_16 ( V_8 ) ;
if ( ! V_51 && ( V_42 & V_52 ) == 0 ) {
V_22 = - V_44 ;
goto V_50;
}
}
F_11 ( V_34 [ V_35 ] ,
V_8 -> V_12 . V_14 + F_22 ( V_8 -> V_12 . V_18 ) ) ;
F_21 ( V_8 , V_38 , V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_26 , false ) ;
V_42 = F_16 ( V_8 ) ;
if ( ( V_42 & V_52 ) != 0 ) {
V_22 = - V_44 ;
goto V_50;
}
return 0 ;
V_50:
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_22 ;
}
static int F_27 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_48 )
{
int V_22 ;
T_3 V_53 ;
V_22 = F_26 ( V_8 , V_34 , V_48 ) ;
if ( V_22 < 0 )
return V_22 ;
F_11 ( V_54 ,
V_8 -> V_12 . V_14 + F_17 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_8 -> V_12 . V_24 ) {
V_53 = F_25 ( * ( ( V_46 * ) ( V_34 + 6 ) ) ) ;
if ( F_21
( V_8 , V_37 | V_38 ,
F_28 ( V_8 , V_53 ) ,
& V_8 -> V_12 . V_40 , false ) < 0 ) {
V_22 = - V_47 ;
goto V_50;
}
}
return V_48 ;
V_50:
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_22 ;
}
static bool F_29 ( struct V_7 * V_8 ,
unsigned long * V_55 )
{
int V_56 ;
T_3 V_57 ;
V_57 = F_30 ( V_8 -> V_12 . V_14 + F_31 ( 0 ) ) ;
for ( V_56 = 0 ; V_56 != F_32 ( V_58 ) ; V_56 ++ ) {
if ( V_58 [ V_56 ] . V_57 != V_57 )
continue;
memcpy ( V_55 , V_58 [ V_56 ] . V_59 ,
sizeof( V_58 [ V_56 ] . V_59 ) ) ;
return true ;
}
return false ;
}
static int F_33 ( struct V_7 * V_8 )
{
int V_22 = 0 ;
T_1 V_60 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_2 V_48 = sizeof( V_60 ) ;
bool V_61 = V_51 ;
T_4 V_12 = F_34 ( V_8 -> V_12 . V_14 + F_31 ( 0 ) ) ;
if ( V_12 != V_62 )
return 0 ;
V_51 = false ;
V_22 = F_26 ( V_8 , V_60 , V_48 ) ;
if ( V_22 == 0 )
goto V_45;
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
V_51 = true ;
V_22 = F_26 ( V_8 , V_60 , V_48 ) ;
if ( V_22 == 0 ) {
F_35 ( V_8 -> V_2 , L_5 ) ;
V_22 = 1 ;
} else
V_22 = - V_63 ;
V_45:
V_51 = V_61 ;
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_22 ;
}
static bool F_36 ( struct V_7 * V_8 , T_1 V_42 )
{
switch ( V_8 -> V_12 . V_64 ) {
case V_65 :
return ( ( V_42 == V_38 ) ||
( V_42 == ( V_38 | V_30 ) ) ) ;
case V_66 :
return ( V_42 == ( V_38 | V_30 ) ) ;
default:
return ( V_42 == V_30 ) ;
}
}
static T_5 F_37 ( int V_24 , void * V_67 )
{
struct V_7 * V_8 = V_67 ;
T_3 V_68 ;
V_68 = F_30 ( V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_68 == 0 )
return V_69 ;
V_8 -> V_12 . V_70 = V_24 ;
F_39 ( V_68 ,
V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
return V_71 ;
}
static T_5 F_40 ( int V_72 , void * V_67 )
{
struct V_7 * V_8 = V_67 ;
T_3 V_68 ;
int V_56 ;
V_68 = F_30 ( V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_68 == 0 )
return V_69 ;
if ( V_68 & V_73 )
F_41 ( & V_8 -> V_12 . V_40 ) ;
if ( V_68 & V_74 )
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ )
if ( F_9 ( V_8 , V_56 ) >= 0 )
break;
if ( V_68 &
( V_74 | V_75 |
V_76 ) )
F_41 ( & V_8 -> V_12 . V_26 ) ;
F_39 ( V_68 ,
V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
F_30 ( V_8 -> V_12 . V_14 + F_38 ( V_8 -> V_12 . V_18 ) ) ;
return V_71 ;
}
static int F_42 ( struct V_77 * V_2 , T_6 V_78 ,
T_6 V_48 , unsigned int V_24 )
{
T_3 V_12 , V_79 , V_80 ;
int V_22 , V_56 , V_81 , V_82 , V_83 ;
struct V_7 * V_8 ;
if ( ! ( V_8 = F_43 ( V_2 , & V_84 ) ) )
return - V_85 ;
V_8 -> V_12 . V_14 = F_44 ( V_78 , V_48 ) ;
if ( ! V_8 -> V_12 . V_14 ) {
V_22 = - V_44 ;
goto V_50;
}
V_8 -> V_12 . V_13 = F_45 ( V_86 ) ;
V_8 -> V_12 . V_49 = F_45 ( V_87 ) ;
V_8 -> V_12 . V_39 = F_45 ( V_86 ) ;
V_8 -> V_12 . V_32 = F_45 ( V_86 ) ;
if ( F_4 ( V_8 , 0 ) != 0 ) {
V_22 = - V_85 ;
goto V_50;
}
if ( F_12 ( V_8 , 0 ) != 0 ) {
V_22 = - V_85 ;
goto V_50;
}
V_12 = F_30 ( V_8 -> V_12 . V_14 + F_31 ( 0 ) ) ;
V_8 -> V_12 . V_64 = V_12 ;
F_35 ( V_2 ,
L_6 ,
V_12 >> 16 , F_5 ( V_8 -> V_12 . V_14 + F_46 ( 0 ) ) ) ;
if ( ! V_51 ) {
V_83 = F_33 ( V_8 ) ;
if ( V_83 < 0 ) {
V_22 = - V_85 ;
goto V_50;
}
V_51 = ! ! V_83 ;
}
if ( V_51 )
F_35 ( V_2 , L_7 ) ;
V_79 =
F_30 ( V_8 -> V_12 . V_14 +
F_47 ( V_8 -> V_12 . V_18 ) ) ;
F_48 ( V_2 , L_8 ,
V_79 ) ;
if ( V_79 & V_88 )
F_48 ( V_2 , L_9 ) ;
if ( V_79 & V_76 )
F_48 ( V_2 , L_10 ) ;
if ( V_79 & V_89 )
F_48 ( V_2 , L_11 ) ;
if ( V_79 & V_90 )
F_48 ( V_2 , L_12 ) ;
if ( V_79 & V_91 )
F_48 ( V_2 , L_13 ) ;
if ( V_79 & V_92 )
F_48 ( V_2 , L_14 ) ;
if ( V_79 & V_74 )
F_48 ( V_2 , L_15 ) ;
if ( V_79 & V_75 )
F_48 ( V_2 , L_16 ) ;
if ( V_79 & V_73 )
F_48 ( V_2 , L_17 ) ;
if ( F_49 ( V_8 ) ) {
F_24 ( V_2 , L_18 ) ;
V_22 = - V_85 ;
goto V_50;
}
if ( F_50 ( V_8 ) ) {
F_24 ( V_2 , L_19 ) ;
V_22 = - V_85 ;
goto V_50;
}
F_51 ( & V_8 -> V_12 . V_40 ) ;
F_51 ( & V_8 -> V_12 . V_26 ) ;
V_80 =
F_30 ( V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
V_80 |= V_76
| V_74 | V_73
| V_75 ;
F_39 ( V_80 ,
V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_93 )
V_8 -> V_12 . V_24 = V_24 ;
if ( V_93 && ! V_8 -> V_12 . V_24 ) {
V_81 =
F_5 ( V_8 -> V_12 . V_14 +
F_53 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_81 ) {
V_82 = V_81 ;
} else {
V_81 = 3 ;
V_82 = 15 ;
}
for ( V_56 = V_81 ; V_56 <= V_82 && V_8 -> V_12 . V_24 == 0 ; V_56 ++ ) {
F_11 ( V_56 , V_8 -> V_12 . V_14 +
F_53 ( V_8 -> V_12 . V_18 ) ) ;
if ( F_54
( V_56 , F_37 , V_94 ,
V_8 -> V_12 . V_95 . V_96 , V_8 ) != 0 ) {
F_35 ( V_8 -> V_2 ,
L_20 ,
V_56 ) ;
continue;
}
F_39 ( F_30
( V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
F_39 ( V_80 | V_97 ,
V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
V_8 -> V_12 . V_70 = 0 ;
F_55 ( V_8 ) ;
V_8 -> V_12 . V_24 = V_8 -> V_12 . V_70 ;
F_39 ( F_30
( V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
F_39 ( V_80 ,
V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
F_56 ( V_56 , V_8 ) ;
}
}
if ( V_8 -> V_12 . V_24 ) {
F_11 ( V_8 -> V_12 . V_24 ,
V_8 -> V_12 . V_14 +
F_53 ( V_8 -> V_12 . V_18 ) ) ;
if ( F_54
( V_8 -> V_12 . V_24 , F_40 , V_94 ,
V_8 -> V_12 . V_95 . V_96 , V_8 ) != 0 ) {
F_35 ( V_8 -> V_2 ,
L_21 ,
V_8 -> V_12 . V_24 ) ;
V_8 -> V_12 . V_24 = 0 ;
} else {
F_39 ( F_30
( V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_38 ( V_8 -> V_12 . V_18 ) ) ;
F_39 ( V_80 | V_97 ,
V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
}
}
F_57 ( & V_8 -> V_12 . V_98 ) ;
F_58 ( & V_99 ) ;
F_59 ( & V_8 -> V_12 . V_98 , & V_100 ) ;
F_60 ( & V_99 ) ;
return 0 ;
V_50:
if ( V_8 -> V_12 . V_14 )
F_61 ( V_8 -> V_12 . V_14 ) ;
F_62 ( V_8 -> V_2 ) ;
return V_22 ;
}
static void F_63 ( struct V_7 * V_8 )
{
T_3 V_80 ;
F_11 ( V_8 -> V_12 . V_24 , V_8 -> V_12 . V_14 +
F_53 ( V_8 -> V_12 . V_18 ) ) ;
V_80 =
F_30 ( V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
V_80 |= V_76
| V_74 | V_73
| V_75 | V_97 ;
F_39 ( V_80 ,
V_8 -> V_12 . V_14 + F_52 ( V_8 -> V_12 . V_18 ) ) ;
}
static int F_64 ( struct V_77 * V_2 )
{
struct V_7 * V_8 = F_65 ( V_2 ) ;
int V_101 ;
if ( V_8 -> V_12 . V_24 )
F_63 ( V_8 ) ;
V_101 = F_66 ( V_2 ) ;
if ( ! V_101 )
F_50 ( V_8 ) ;
return V_101 ;
}
static int F_67 ( struct V_1 * V_1 ,
const struct V_102 * V_103 )
{
T_6 V_78 , V_48 ;
unsigned int V_24 = 0 ;
V_78 = F_68 ( V_1 , 0 ) ;
V_48 = F_69 ( V_1 , 0 ) ;
if ( F_70 ( V_1 , 0 ) )
V_24 = F_71 ( V_1 , 0 ) ;
else
V_93 = false ;
if ( F_1 ( V_1 ) )
V_51 = true ;
return F_42 ( & V_1 -> V_2 , V_78 , V_48 , V_24 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_73 ( V_2 ) ;
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
}
static int T_7 F_76 ( void )
{
int V_22 ;
#ifdef F_77
if ( ! V_19 )
return F_78 ( & V_104 ) ;
#endif
V_22 = F_79 ( & V_105 ) ;
if ( V_22 < 0 )
return V_22 ;
V_106 = F_80 ( L_22 , - 1 , NULL , 0 ) ;
if ( F_81 ( V_106 ) ) {
V_22 = F_82 ( V_106 ) ;
goto V_107;
}
V_22 = F_42 ( & V_106 -> V_2 , V_108 , V_109 , 0 ) ;
if ( V_22 )
goto V_110;
return 0 ;
V_110:
F_83 ( V_106 ) ;
V_107:
F_84 ( & V_105 ) ;
return V_22 ;
}
static void T_8 F_85 ( void )
{
struct V_111 * V_56 , * V_112 ;
struct V_7 * V_8 ;
F_58 ( & V_99 ) ;
F_86 (i, j, &tis_chips, list) {
V_8 = F_87 ( V_56 ) ;
F_62 ( V_8 -> V_2 ) ;
F_39 ( ~ V_97 &
F_30 ( V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 .
V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_52 ( V_8 -> V_12 . V_18 ) ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 1 ) ;
if ( V_8 -> V_12 . V_24 )
F_56 ( V_8 -> V_12 . V_24 , V_8 ) ;
F_61 ( V_56 -> V_14 ) ;
F_88 ( & V_56 -> V_98 ) ;
}
F_60 ( & V_99 ) ;
#ifdef F_77
if ( ! V_19 ) {
F_89 ( & V_104 ) ;
return;
}
#endif
F_83 ( V_106 ) ;
F_84 ( & V_105 ) ;
}
