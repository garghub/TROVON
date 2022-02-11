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
F_24 ( V_8 -> V_46 , L_2 ) ;
goto V_45;
}
V_41 = F_25 ( * ( V_47 * ) ( V_34 + 2 ) ) ;
if ( V_41 > V_35 ) {
V_36 = - V_44 ;
goto V_45;
}
if ( ( V_36 +=
F_20 ( V_8 , & V_34 [ V_43 ] ,
V_41 - V_43 ) ) < V_41 ) {
F_24 ( V_8 -> V_46 , L_3 ) ;
V_36 = - V_48 ;
goto V_45;
}
F_21 ( V_8 , V_38 , V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_26 , false ) ;
V_42 = F_16 ( V_8 ) ;
if ( V_42 & V_37 ) {
F_24 ( V_8 -> V_46 , L_4 ) ;
V_36 = - V_44 ;
goto V_45;
}
V_45:
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_36 ;
}
static int F_26 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_49 )
{
int V_22 , V_42 , V_31 ;
T_2 V_35 = 0 ;
if ( F_12 ( V_8 , 0 ) < 0 )
return - V_33 ;
V_42 = F_16 ( V_8 ) ;
if ( ( V_42 & V_30 ) == 0 ) {
F_18 ( V_8 ) ;
if ( F_21
( V_8 , V_30 , V_8 -> V_12 . V_50 ,
& V_8 -> V_12 . V_26 , false ) < 0 ) {
V_22 = - V_48 ;
goto V_51;
}
}
while ( V_35 < V_49 - 1 ) {
V_31 = F_19 ( V_8 ) ;
for (; V_31 > 0 && V_35 < V_49 - 1 ; V_31 -- ) {
F_11 ( V_34 [ V_35 ] , V_8 -> V_12 . V_14 +
F_22 ( V_8 -> V_12 . V_18 ) ) ;
V_35 ++ ;
}
F_21 ( V_8 , V_38 , V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_26 , false ) ;
V_42 = F_16 ( V_8 ) ;
if ( ! V_52 && ( V_42 & V_53 ) == 0 ) {
V_22 = - V_44 ;
goto V_51;
}
}
F_11 ( V_34 [ V_35 ] ,
V_8 -> V_12 . V_14 + F_22 ( V_8 -> V_12 . V_18 ) ) ;
F_21 ( V_8 , V_38 , V_8 -> V_12 . V_39 ,
& V_8 -> V_12 . V_26 , false ) ;
V_42 = F_16 ( V_8 ) ;
if ( ( V_42 & V_53 ) != 0 ) {
V_22 = - V_44 ;
goto V_51;
}
return 0 ;
V_51:
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_22 ;
}
static void F_27 ( struct V_7 * V_8 )
{
T_3 V_54 ;
V_54 =
F_28 ( V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
V_54 &= ~ V_55 ;
F_30 ( V_54 ,
V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
F_31 ( V_8 -> V_12 . V_24 , V_8 ) ;
V_8 -> V_12 . V_24 = 0 ;
}
static int F_32 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_49 )
{
int V_22 ;
T_3 V_56 ;
unsigned long V_57 ;
V_22 = F_26 ( V_8 , V_34 , V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
F_11 ( V_58 ,
V_8 -> V_12 . V_14 + F_17 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_8 -> V_12 . V_24 ) {
V_56 = F_25 ( * ( ( V_47 * ) ( V_34 + 6 ) ) ) ;
if ( V_8 -> V_59 & V_60 )
V_57 = F_33 ( V_8 , V_56 ) ;
else
V_57 = F_34 ( V_8 , V_56 ) ;
if ( F_21
( V_8 , V_37 | V_38 , V_57 ,
& V_8 -> V_12 . V_40 , false ) < 0 ) {
V_22 = - V_48 ;
goto V_51;
}
}
return V_49 ;
V_51:
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_22 ;
}
static int F_35 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_49 )
{
int V_22 , V_24 ;
struct V_61 * V_62 = V_8 -> V_12 . V_62 ;
if ( ! V_8 -> V_12 . V_24 || V_62 -> V_63 )
return F_32 ( V_8 , V_34 , V_49 ) ;
V_24 = V_8 -> V_12 . V_24 ;
V_8 -> V_12 . V_24 = 0 ;
V_22 = F_32 ( V_8 , V_34 , V_49 ) ;
V_8 -> V_12 . V_24 = V_24 ;
if ( ! V_62 -> V_63 )
F_7 ( 1 ) ;
if ( ! V_62 -> V_63 ) {
F_27 ( V_8 ) ;
F_24 ( V_8 -> V_46 ,
V_64 L_5 ) ;
}
V_62 -> V_63 = true ;
return V_22 ;
}
static bool F_36 ( struct V_7 * V_8 ,
unsigned long * V_65 )
{
int V_66 ;
T_3 V_67 ;
V_67 = F_28 ( V_8 -> V_12 . V_14 + F_37 ( 0 ) ) ;
for ( V_66 = 0 ; V_66 != F_38 ( V_68 ) ; V_66 ++ ) {
if ( V_68 [ V_66 ] . V_67 != V_67 )
continue;
memcpy ( V_65 , V_68 [ V_66 ] . V_69 ,
sizeof( V_68 [ V_66 ] . V_69 ) ) ;
return true ;
}
return false ;
}
static int F_39 ( struct V_7 * V_8 )
{
int V_22 = 0 ;
T_1 V_70 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_2 V_49 = sizeof( V_70 ) ;
bool V_71 = V_52 ;
T_4 V_12 = F_40 ( V_8 -> V_12 . V_14 + F_37 ( 0 ) ) ;
if ( V_12 != V_72 )
return 0 ;
V_52 = false ;
V_22 = F_26 ( V_8 , V_70 , V_49 ) ;
if ( V_22 == 0 )
goto V_45;
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
V_52 = true ;
V_22 = F_26 ( V_8 , V_70 , V_49 ) ;
if ( V_22 == 0 ) {
F_41 ( V_8 -> V_46 , L_6 ) ;
V_22 = 1 ;
} else
V_22 = - V_73 ;
V_45:
V_52 = V_71 ;
F_18 ( V_8 ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 0 ) ;
return V_22 ;
}
static bool F_42 ( struct V_7 * V_8 , T_1 V_42 )
{
switch ( V_8 -> V_12 . V_74 ) {
case V_75 :
return ( ( V_42 == V_38 ) ||
( V_42 == ( V_38 | V_30 ) ) ) ;
case V_76 :
return ( V_42 == ( V_38 | V_30 ) ) ;
default:
return ( V_42 == V_30 ) ;
}
}
static T_5 F_43 ( int V_24 , void * V_77 )
{
struct V_7 * V_8 = V_77 ;
T_3 V_78 ;
V_78 = F_28 ( V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_78 == 0 )
return V_79 ;
V_8 -> V_12 . V_80 = V_24 ;
F_30 ( V_78 ,
V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
return V_81 ;
}
static T_5 F_45 ( int V_82 , void * V_77 )
{
struct V_7 * V_8 = V_77 ;
T_3 V_78 ;
int V_66 ;
V_78 = F_28 ( V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_78 == 0 )
return V_79 ;
( (struct V_61 * ) V_8 -> V_12 . V_62 ) -> V_63 = true ;
if ( V_78 & V_83 )
F_46 ( & V_8 -> V_12 . V_40 ) ;
if ( V_78 & V_84 )
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ )
if ( F_9 ( V_8 , V_66 ) >= 0 )
break;
if ( V_78 &
( V_84 | V_85 |
V_86 ) )
F_46 ( & V_8 -> V_12 . V_26 ) ;
F_30 ( V_78 ,
V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
F_28 ( V_8 -> V_12 . V_14 + F_44 ( V_8 -> V_12 . V_18 ) ) ;
return V_81 ;
}
static void F_47 ( struct V_7 * V_8 )
{
if ( V_8 -> V_59 & V_60 )
F_48 ( V_8 , V_87 ) ;
F_30 ( ~ V_55 &
F_28 ( V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 .
V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
F_10 ( V_8 , V_8 -> V_12 . V_18 , 1 ) ;
}
static int F_49 ( struct V_88 * V_2 , T_6 V_89 ,
T_7 V_90 , T_7 V_49 ,
unsigned int V_24 )
{
T_3 V_12 , V_91 , V_54 ;
int V_22 , V_66 , V_92 , V_93 , V_94 ;
struct V_7 * V_8 ;
struct V_61 * V_62 ;
V_62 = F_50 ( V_2 , sizeof( struct V_61 ) , V_95 ) ;
if ( V_62 == NULL )
return - V_96 ;
V_8 = F_51 ( V_2 , & V_97 ) ;
if ( F_52 ( V_8 ) )
return F_53 ( V_8 ) ;
V_8 -> V_12 . V_62 = V_62 ;
#ifdef F_54
V_8 -> V_89 = V_89 ;
#endif
V_8 -> V_12 . V_14 = F_55 ( V_2 , V_90 , V_49 ) ;
if ( ! V_8 -> V_12 . V_14 )
return - V_44 ;
V_8 -> V_12 . V_13 = V_98 ;
V_8 -> V_12 . V_50 = V_99 ;
V_8 -> V_12 . V_39 = V_100 ;
V_8 -> V_12 . V_32 = V_101 ;
if ( F_4 ( V_8 , 0 ) != 0 ) {
V_22 = - V_102 ;
goto V_51;
}
if ( F_12 ( V_8 , 0 ) != 0 ) {
V_22 = - V_102 ;
goto V_51;
}
V_22 = F_56 ( V_8 ) ;
if ( V_22 )
goto V_51;
V_12 = F_28 ( V_8 -> V_12 . V_14 + F_37 ( 0 ) ) ;
V_8 -> V_12 . V_74 = V_12 ;
F_41 ( V_2 , L_7 ,
( V_8 -> V_59 & V_60 ) ? L_8 : L_9 ,
V_12 >> 16 , F_5 ( V_8 -> V_12 . V_14 + F_57 ( 0 ) ) ) ;
if ( ! V_52 ) {
V_94 = F_39 ( V_8 ) ;
if ( V_94 < 0 ) {
V_22 = - V_102 ;
goto V_51;
}
V_52 = ! ! V_94 ;
}
if ( V_52 )
F_41 ( V_2 , L_10 ) ;
V_91 =
F_28 ( V_8 -> V_12 . V_14 +
F_58 ( V_8 -> V_12 . V_18 ) ) ;
F_59 ( V_2 , L_11 ,
V_91 ) ;
if ( V_91 & V_103 )
F_59 ( V_2 , L_12 ) ;
if ( V_91 & V_86 )
F_59 ( V_2 , L_13 ) ;
if ( V_91 & V_104 )
F_59 ( V_2 , L_14 ) ;
if ( V_91 & V_105 )
F_59 ( V_2 , L_15 ) ;
if ( V_91 & V_106 )
F_59 ( V_2 , L_16 ) ;
if ( V_91 & V_107 )
F_59 ( V_2 , L_17 ) ;
if ( V_91 & V_84 )
F_59 ( V_2 , L_18 ) ;
if ( V_91 & V_85 )
F_59 ( V_2 , L_19 ) ;
if ( V_91 & V_83 )
F_59 ( V_2 , L_20 ) ;
F_60 ( & V_8 -> V_12 . V_40 ) ;
F_60 ( & V_8 -> V_12 . V_26 ) ;
V_54 =
F_28 ( V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
V_54 |= V_86
| V_84 | V_83
| V_85 ;
F_30 ( V_54 ,
V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_108 )
V_8 -> V_12 . V_24 = V_24 ;
if ( V_108 && ! V_8 -> V_12 . V_24 ) {
V_92 =
F_5 ( V_8 -> V_12 . V_14 +
F_61 ( V_8 -> V_12 . V_18 ) ) ;
if ( V_92 ) {
V_93 = V_92 ;
} else {
V_92 = 3 ;
V_93 = 15 ;
}
for ( V_66 = V_92 ; V_66 <= V_93 && V_8 -> V_12 . V_24 == 0 ; V_66 ++ ) {
F_11 ( V_66 , V_8 -> V_12 . V_14 +
F_61 ( V_8 -> V_12 . V_18 ) ) ;
if ( F_62
( V_2 , V_66 , F_43 , V_109 ,
V_8 -> V_110 , V_8 ) != 0 ) {
F_41 ( V_8 -> V_46 ,
L_21 ,
V_66 ) ;
continue;
}
F_30 ( F_28
( V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
F_30 ( V_54 | V_55 ,
V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
V_8 -> V_12 . V_80 = 0 ;
if ( V_8 -> V_59 & V_60 )
F_63 ( V_8 ) ;
else
F_64 ( V_8 ) ;
V_8 -> V_12 . V_24 = V_8 -> V_12 . V_80 ;
F_30 ( F_28
( V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
F_30 ( V_54 ,
V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
}
}
if ( V_8 -> V_12 . V_24 ) {
F_11 ( V_8 -> V_12 . V_24 ,
V_8 -> V_12 . V_14 +
F_61 ( V_8 -> V_12 . V_18 ) ) ;
if ( F_62
( V_2 , V_8 -> V_12 . V_24 , F_45 , V_109 ,
V_8 -> V_110 , V_8 ) != 0 ) {
F_41 ( V_8 -> V_46 ,
L_22 ,
V_8 -> V_12 . V_24 ) ;
V_8 -> V_12 . V_24 = 0 ;
} else {
F_30 ( F_28
( V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ,
V_8 -> V_12 . V_14 +
F_44 ( V_8 -> V_12 . V_18 ) ) ;
F_30 ( V_54 | V_55 ,
V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
}
}
if ( V_8 -> V_59 & V_60 ) {
V_8 -> V_12 . V_13 = F_65 ( V_111 ) ;
V_8 -> V_12 . V_50 = F_65 ( V_112 ) ;
V_8 -> V_12 . V_39 = F_65 ( V_113 ) ;
V_8 -> V_12 . V_32 = F_65 ( V_114 ) ;
V_8 -> V_12 . V_115 [ V_116 ] =
F_65 ( V_117 ) ;
V_8 -> V_12 . V_115 [ V_118 ] =
F_65 ( V_119 ) ;
V_8 -> V_12 . V_115 [ V_120 ] =
F_65 ( V_121 ) ;
V_22 = F_66 ( V_8 ) ;
if ( V_22 == V_122 ) {
F_67 ( V_2 , L_23 ) ;
V_22 = F_68 ( V_8 , V_87 ) ;
if ( ! V_22 )
V_22 = F_66 ( V_8 ) ;
}
if ( V_22 ) {
F_24 ( V_2 , L_24 ) ;
if ( V_22 > 0 )
V_22 = - V_102 ;
goto V_51;
}
} else {
if ( F_69 ( V_8 ) ) {
F_24 ( V_2 , L_25 ) ;
V_22 = - V_102 ;
goto V_51;
}
if ( F_70 ( V_8 ) ) {
F_24 ( V_2 , L_24 ) ;
V_22 = - V_102 ;
goto V_51;
}
}
return F_71 ( V_8 ) ;
V_51:
F_47 ( V_8 ) ;
return V_22 ;
}
static void F_72 ( struct V_7 * V_8 )
{
T_3 V_54 ;
F_11 ( V_8 -> V_12 . V_24 , V_8 -> V_12 . V_14 +
F_61 ( V_8 -> V_12 . V_18 ) ) ;
V_54 =
F_28 ( V_8 -> V_12 . V_14 +
F_29 ( V_8 -> V_12 . V_18 ) ) ;
V_54 |= V_86
| V_84 | V_83
| V_85 | V_55 ;
F_30 ( V_54 ,
V_8 -> V_12 . V_14 + F_29 ( V_8 -> V_12 . V_18 ) ) ;
}
static int F_73 ( struct V_88 * V_2 )
{
struct V_7 * V_8 = F_74 ( V_2 ) ;
int V_123 ;
if ( V_8 -> V_12 . V_24 )
F_72 ( V_8 ) ;
V_123 = F_75 ( V_2 ) ;
if ( V_123 )
return V_123 ;
if ( ! ( V_8 -> V_59 & V_60 ) )
F_70 ( V_8 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_1 ,
const struct V_124 * V_125 )
{
T_7 V_90 , V_49 ;
unsigned int V_24 = 0 ;
T_6 V_89 = NULL ;
V_90 = F_77 ( V_1 , 0 ) ;
V_49 = F_78 ( V_1 , 0 ) ;
if ( F_79 ( V_1 , 0 ) )
V_24 = F_80 ( V_1 , 0 ) ;
else
V_108 = false ;
if ( F_1 ( V_1 ) )
V_52 = true ;
#ifdef F_54
if ( F_2 ( V_1 ) )
V_89 = F_2 ( V_1 ) -> V_126 ;
#endif
return F_49 ( & V_1 -> V_2 , V_89 , V_90 , V_49 , V_24 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_82 ( V_2 ) ;
F_83 ( V_8 ) ;
F_47 ( V_8 ) ;
}
static int T_8 F_84 ( void )
{
int V_22 ;
#ifdef F_85
if ( ! V_19 )
return F_86 ( & V_127 ) ;
#endif
V_22 = F_87 ( & V_128 ) ;
if ( V_22 < 0 )
return V_22 ;
V_46 = F_88 ( L_26 , - 1 , NULL , 0 ) ;
if ( F_52 ( V_46 ) ) {
V_22 = F_53 ( V_46 ) ;
goto V_129;
}
V_22 = F_49 ( & V_46 -> V_2 , NULL , V_130 , V_131 , 0 ) ;
if ( V_22 )
goto V_132;
return 0 ;
V_132:
F_89 ( V_46 ) ;
V_129:
F_90 ( & V_128 ) ;
return V_22 ;
}
static void T_9 F_91 ( void )
{
struct V_7 * V_8 ;
#ifdef F_85
if ( ! V_19 ) {
F_92 ( & V_127 ) ;
return;
}
#endif
V_8 = F_74 ( & V_46 -> V_2 ) ;
F_83 ( V_8 ) ;
F_47 ( V_8 ) ;
F_89 ( V_46 ) ;
F_90 ( & V_128 ) ;
}
