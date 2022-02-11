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
static inline int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 )
{
unsigned long V_9 = V_10 + V_7 -> V_11 . V_12 ;
do {
if ( F_5 ( V_7 -> V_11 . V_13 + F_6 ( V_8 ) ) &
V_14 )
return 0 ;
F_7 ( V_15 ) ;
} while ( F_8 ( V_10 , V_9 ) );
return - 1 ;
}
static int F_9 ( struct V_6 * V_7 , int V_8 )
{
if ( ( F_5 ( V_7 -> V_11 . V_13 + F_6 ( V_8 ) ) &
( V_16 | V_14 ) ) ==
( V_16 | V_14 ) )
return V_7 -> V_11 . V_17 = V_8 ;
return - 1 ;
}
static void F_10 ( struct V_6 * V_7 , int V_8 , int V_18 )
{
if ( V_18 || ( F_5 ( V_7 -> V_11 . V_13 + F_6 ( V_8 ) ) &
( V_19 | V_14 ) ) ==
( V_19 | V_14 ) )
F_11 ( V_16 ,
V_7 -> V_11 . V_13 + F_6 ( V_8 ) ) ;
}
static int F_12 ( struct V_6 * V_7 , int V_8 )
{
unsigned long V_9 , V_20 ;
long V_21 ;
if ( F_9 ( V_7 , V_8 ) >= 0 )
return V_8 ;
F_11 ( V_22 ,
V_7 -> V_11 . V_13 + F_6 ( V_8 ) ) ;
V_9 = V_10 + V_7 -> V_11 . V_12 ;
if ( V_7 -> V_11 . V_23 ) {
V_24:
V_20 = V_9 - V_10 ;
if ( ( long ) V_20 <= 0 )
return - 1 ;
V_21 = F_13 ( V_7 -> V_11 . V_25 ,
( F_9
( V_7 , V_8 ) >= 0 ) ,
V_20 ) ;
if ( V_21 > 0 )
return V_8 ;
if ( V_21 == - V_26 && F_14 ( V_27 ) ) {
F_15 ( V_28 ) ;
goto V_24;
}
} else {
do {
if ( F_9 ( V_7 , V_8 ) >= 0 )
return V_8 ;
F_7 ( V_15 ) ;
}
while ( F_8 ( V_10 , V_9 ) );
}
return - 1 ;
}
static T_1 F_16 ( struct V_6 * V_7 )
{
return F_5 ( V_7 -> V_11 . V_13 +
F_17 ( V_7 -> V_11 . V_17 ) ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
F_11 ( V_29 ,
V_7 -> V_11 . V_13 + F_17 ( V_7 -> V_11 . V_17 ) ) ;
}
static int F_19 ( struct V_6 * V_7 )
{
unsigned long V_9 ;
int V_30 ;
V_9 = V_10 + V_7 -> V_11 . V_31 ;
do {
V_30 = F_5 ( V_7 -> V_11 . V_13 +
F_17 ( V_7 -> V_11 . V_17 ) + 1 ) ;
V_30 += F_5 ( V_7 -> V_11 . V_13 +
F_17 ( V_7 -> V_11 . V_17 ) +
2 ) << 8 ;
if ( V_30 )
return V_30 ;
F_7 ( V_15 ) ;
} while ( F_8 ( V_10 , V_9 ) );
return - V_32 ;
}
static int F_20 ( struct V_6 * V_7 , T_1 * V_33 , T_2 V_34 )
{
int V_35 = 0 , V_30 ;
while ( V_35 < V_34 &&
F_21 ( V_7 ,
V_36 | V_37 ,
V_7 -> V_11 . V_38 ,
& V_7 -> V_11 . V_39 , true )
== 0 ) {
V_30 = F_19 ( V_7 ) ;
for (; V_30 > 0 && V_35 < V_34 ; V_30 -- )
V_33 [ V_35 ++ ] = F_5 ( V_7 -> V_11 . V_13 +
F_22 ( V_7 -> V_11 .
V_17 ) ) ;
}
return V_35 ;
}
static int F_23 ( struct V_6 * V_7 , T_1 * V_33 , T_2 V_34 )
{
int V_35 = 0 ;
int V_40 , V_41 ;
if ( V_34 < V_42 ) {
V_35 = - V_43 ;
goto V_44;
}
if ( ( V_35 =
F_20 ( V_7 , V_33 , V_42 ) ) < V_42 ) {
F_24 ( V_7 -> V_45 , L_2 ) ;
goto V_44;
}
V_40 = F_25 ( * ( V_46 * ) ( V_33 + 2 ) ) ;
if ( V_40 > V_34 ) {
V_35 = - V_43 ;
goto V_44;
}
if ( ( V_35 +=
F_20 ( V_7 , & V_33 [ V_42 ] ,
V_40 - V_42 ) ) < V_40 ) {
F_24 ( V_7 -> V_45 , L_3 ) ;
V_35 = - V_47 ;
goto V_44;
}
F_21 ( V_7 , V_37 , V_7 -> V_11 . V_38 ,
& V_7 -> V_11 . V_25 , false ) ;
V_41 = F_16 ( V_7 ) ;
if ( V_41 & V_36 ) {
F_24 ( V_7 -> V_45 , L_4 ) ;
V_35 = - V_43 ;
goto V_44;
}
V_44:
F_18 ( V_7 ) ;
F_10 ( V_7 , V_7 -> V_11 . V_17 , 0 ) ;
return V_35 ;
}
static int F_26 ( struct V_6 * V_7 , T_1 * V_33 , T_2 V_48 )
{
int V_21 , V_41 , V_30 ;
T_2 V_34 = 0 ;
if ( F_12 ( V_7 , 0 ) < 0 )
return - V_32 ;
V_41 = F_16 ( V_7 ) ;
if ( ( V_41 & V_29 ) == 0 ) {
F_18 ( V_7 ) ;
if ( F_21
( V_7 , V_29 , V_7 -> V_11 . V_49 ,
& V_7 -> V_11 . V_25 , false ) < 0 ) {
V_21 = - V_47 ;
goto V_50;
}
}
while ( V_34 < V_48 - 1 ) {
V_30 = F_19 ( V_7 ) ;
for (; V_30 > 0 && V_34 < V_48 - 1 ; V_30 -- ) {
F_11 ( V_33 [ V_34 ] , V_7 -> V_11 . V_13 +
F_22 ( V_7 -> V_11 . V_17 ) ) ;
V_34 ++ ;
}
F_21 ( V_7 , V_37 , V_7 -> V_11 . V_38 ,
& V_7 -> V_11 . V_25 , false ) ;
V_41 = F_16 ( V_7 ) ;
if ( ! V_51 && ( V_41 & V_52 ) == 0 ) {
V_21 = - V_43 ;
goto V_50;
}
}
F_11 ( V_33 [ V_34 ] ,
V_7 -> V_11 . V_13 + F_22 ( V_7 -> V_11 . V_17 ) ) ;
F_21 ( V_7 , V_37 , V_7 -> V_11 . V_38 ,
& V_7 -> V_11 . V_25 , false ) ;
V_41 = F_16 ( V_7 ) ;
if ( ( V_41 & V_52 ) != 0 ) {
V_21 = - V_43 ;
goto V_50;
}
return 0 ;
V_50:
F_18 ( V_7 ) ;
F_10 ( V_7 , V_7 -> V_11 . V_17 , 0 ) ;
return V_21 ;
}
static void F_27 ( struct V_6 * V_7 )
{
T_3 V_53 ;
V_53 =
F_28 ( V_7 -> V_11 . V_13 +
F_29 ( V_7 -> V_11 . V_17 ) ) ;
V_53 &= ~ V_54 ;
F_30 ( V_53 ,
V_7 -> V_11 . V_13 +
F_29 ( V_7 -> V_11 . V_17 ) ) ;
F_31 ( V_7 -> V_45 , V_7 -> V_11 . V_23 , V_7 ) ;
V_7 -> V_11 . V_23 = 0 ;
}
static int F_32 ( struct V_6 * V_7 , T_1 * V_33 , T_2 V_48 )
{
int V_21 ;
T_3 V_55 ;
unsigned long V_56 ;
V_21 = F_26 ( V_7 , V_33 , V_48 ) ;
if ( V_21 < 0 )
return V_21 ;
F_11 ( V_57 ,
V_7 -> V_11 . V_13 + F_17 ( V_7 -> V_11 . V_17 ) ) ;
if ( V_7 -> V_11 . V_23 ) {
V_55 = F_25 ( * ( ( V_46 * ) ( V_33 + 6 ) ) ) ;
if ( V_7 -> V_58 & V_59 )
V_56 = F_33 ( V_7 , V_55 ) ;
else
V_56 = F_34 ( V_7 , V_55 ) ;
if ( F_21
( V_7 , V_36 | V_37 , V_56 ,
& V_7 -> V_11 . V_39 , false ) < 0 ) {
V_21 = - V_47 ;
goto V_50;
}
}
return V_48 ;
V_50:
F_18 ( V_7 ) ;
F_10 ( V_7 , V_7 -> V_11 . V_17 , 0 ) ;
return V_21 ;
}
static int F_35 ( struct V_6 * V_7 , T_1 * V_33 , T_2 V_48 )
{
int V_21 , V_23 ;
struct V_60 * V_61 = V_7 -> V_11 . V_61 ;
if ( ! V_7 -> V_11 . V_23 || V_61 -> V_62 )
return F_32 ( V_7 , V_33 , V_48 ) ;
V_23 = V_7 -> V_11 . V_23 ;
V_7 -> V_11 . V_23 = 0 ;
V_21 = F_32 ( V_7 , V_33 , V_48 ) ;
V_7 -> V_11 . V_23 = V_23 ;
if ( ! V_61 -> V_62 )
F_7 ( 1 ) ;
if ( ! V_61 -> V_62 )
F_27 ( V_7 ) ;
V_61 -> V_62 = true ;
return V_21 ;
}
static bool F_36 ( struct V_6 * V_7 ,
unsigned long * V_63 )
{
int V_64 ;
T_3 V_65 ;
V_65 = F_28 ( V_7 -> V_11 . V_13 + F_37 ( 0 ) ) ;
for ( V_64 = 0 ; V_64 != F_38 ( V_66 ) ; V_64 ++ ) {
if ( V_66 [ V_64 ] . V_65 != V_65 )
continue;
memcpy ( V_63 , V_66 [ V_64 ] . V_67 ,
sizeof( V_66 [ V_64 ] . V_67 ) ) ;
return true ;
}
return false ;
}
static int F_39 ( struct V_6 * V_7 )
{
int V_21 = 0 ;
T_1 V_68 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_2 V_48 = sizeof( V_68 ) ;
bool V_69 = V_51 ;
T_4 V_11 = F_40 ( V_7 -> V_11 . V_13 + F_37 ( 0 ) ) ;
if ( V_11 != V_70 )
return 0 ;
V_51 = false ;
V_21 = F_26 ( V_7 , V_68 , V_48 ) ;
if ( V_21 == 0 )
goto V_44;
F_18 ( V_7 ) ;
F_10 ( V_7 , V_7 -> V_11 . V_17 , 0 ) ;
V_51 = true ;
V_21 = F_26 ( V_7 , V_68 , V_48 ) ;
if ( V_21 == 0 ) {
F_41 ( V_7 -> V_45 , L_5 ) ;
V_21 = 1 ;
} else
V_21 = - V_71 ;
V_44:
V_51 = V_69 ;
F_18 ( V_7 ) ;
F_10 ( V_7 , V_7 -> V_11 . V_17 , 0 ) ;
return V_21 ;
}
static bool F_42 ( struct V_6 * V_7 , T_1 V_41 )
{
switch ( V_7 -> V_11 . V_72 ) {
case V_73 :
return ( ( V_41 == V_37 ) ||
( V_41 == ( V_37 | V_29 ) ) ) ;
case V_74 :
return ( V_41 == ( V_37 | V_29 ) ) ;
default:
return ( V_41 == V_29 ) ;
}
}
static T_5 F_43 ( int V_75 , void * V_76 )
{
struct V_6 * V_7 = V_76 ;
T_3 V_77 ;
int V_64 ;
V_77 = F_28 ( V_7 -> V_11 . V_13 +
F_44 ( V_7 -> V_11 . V_17 ) ) ;
if ( V_77 == 0 )
return V_78 ;
( (struct V_60 * ) V_7 -> V_11 . V_61 ) -> V_62 = true ;
if ( V_77 & V_79 )
F_45 ( & V_7 -> V_11 . V_39 ) ;
if ( V_77 & V_80 )
for ( V_64 = 0 ; V_64 < 5 ; V_64 ++ )
if ( F_9 ( V_7 , V_64 ) >= 0 )
break;
if ( V_77 &
( V_80 | V_81 |
V_82 ) )
F_45 ( & V_7 -> V_11 . V_25 ) ;
F_30 ( V_77 ,
V_7 -> V_11 . V_13 +
F_44 ( V_7 -> V_11 . V_17 ) ) ;
F_28 ( V_7 -> V_11 . V_13 + F_44 ( V_7 -> V_11 . V_17 ) ) ;
return V_83 ;
}
static int F_46 ( struct V_6 * V_7 , T_3 V_53 ,
int V_58 , int V_23 )
{
struct V_60 * V_61 = V_7 -> V_11 . V_61 ;
T_1 V_84 ;
if ( F_47 ( V_7 -> V_45 , V_23 , F_43 , V_58 ,
V_7 -> V_85 , V_7 ) != 0 ) {
F_41 ( V_7 -> V_45 , L_6 ,
V_23 ) ;
return - 1 ;
}
V_7 -> V_11 . V_23 = V_23 ;
V_84 = F_5 ( V_7 -> V_11 . V_13 +
F_48 ( V_7 -> V_11 . V_17 ) ) ;
F_11 ( V_23 ,
V_7 -> V_11 . V_13 + F_48 ( V_7 -> V_11 . V_17 ) ) ;
F_30 ( F_28 ( V_7 -> V_11 . V_13 +
F_44 ( V_7 -> V_11 . V_17 ) ) ,
V_7 -> V_11 . V_13 + F_44 ( V_7 -> V_11 . V_17 ) ) ;
F_30 ( V_53 | V_54 ,
V_7 -> V_11 . V_13 + F_29 ( V_7 -> V_11 . V_17 ) ) ;
V_61 -> V_62 = false ;
if ( V_7 -> V_58 & V_59 )
F_49 ( V_7 ) ;
else
F_50 ( V_7 ) ;
if ( ! V_7 -> V_11 . V_23 ) {
F_11 ( V_84 ,
V_7 -> V_11 . V_13 +
F_48 ( V_7 -> V_11 . V_17 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_51 ( struct V_6 * V_7 , T_3 V_53 )
{
T_1 V_84 ;
int V_64 ;
V_84 = F_5 ( V_7 -> V_11 . V_13 +
F_48 ( V_7 -> V_11 . V_17 ) ) ;
if ( ! V_84 ) {
if ( F_52 ( V_86 ) )
for ( V_64 = 3 ; V_64 <= 15 ; V_64 ++ )
if ( ! F_46 ( V_7 , V_53 , 0 ,
V_64 ) )
return;
} else if ( ! F_46 ( V_7 , V_53 , 0 ,
V_84 ) )
return;
}
static void F_53 ( struct V_6 * V_7 )
{
if ( V_7 -> V_58 & V_59 )
F_54 ( V_7 , V_87 ) ;
F_30 ( ~ V_54 &
F_28 ( V_7 -> V_11 . V_13 +
F_29 ( V_7 -> V_11 .
V_17 ) ) ,
V_7 -> V_11 . V_13 +
F_29 ( V_7 -> V_11 . V_17 ) ) ;
F_10 ( V_7 , V_7 -> V_11 . V_17 , 1 ) ;
}
static int F_55 ( struct V_88 * V_2 , struct V_89 * V_89 ,
T_6 V_90 )
{
T_3 V_11 , V_91 , V_53 ;
int V_21 , V_92 ;
struct V_6 * V_7 ;
struct V_60 * V_61 ;
V_61 = F_56 ( V_2 , sizeof( struct V_60 ) , V_93 ) ;
if ( V_61 == NULL )
return - V_94 ;
V_7 = F_57 ( V_2 , & V_95 ) ;
if ( F_58 ( V_7 ) )
return F_59 ( V_7 ) ;
V_7 -> V_11 . V_61 = V_61 ;
#ifdef F_60
V_7 -> V_90 = V_90 ;
#endif
V_7 -> V_11 . V_13 = F_61 ( V_2 , & V_89 -> V_96 ) ;
if ( F_58 ( V_7 -> V_11 . V_13 ) )
return F_59 ( V_7 -> V_11 . V_13 ) ;
V_7 -> V_11 . V_12 = V_97 ;
V_7 -> V_11 . V_49 = V_98 ;
V_7 -> V_11 . V_38 = V_99 ;
V_7 -> V_11 . V_31 = V_100 ;
if ( F_4 ( V_7 , 0 ) != 0 ) {
V_21 = - V_101 ;
goto V_50;
}
V_53 = F_28 ( V_7 -> V_11 . V_13 +
F_29 ( V_7 -> V_11 . V_17 ) ) ;
V_53 |= V_82 | V_80 |
V_79 | V_81 ;
V_53 &= ~ V_54 ;
F_30 ( V_53 ,
V_7 -> V_11 . V_13 + F_29 ( V_7 -> V_11 . V_17 ) ) ;
if ( F_12 ( V_7 , 0 ) != 0 ) {
V_21 = - V_101 ;
goto V_50;
}
V_21 = F_62 ( V_7 ) ;
if ( V_21 )
goto V_50;
V_11 = F_28 ( V_7 -> V_11 . V_13 + F_37 ( 0 ) ) ;
V_7 -> V_11 . V_72 = V_11 ;
F_41 ( V_2 , L_7 ,
( V_7 -> V_58 & V_59 ) ? L_8 : L_9 ,
V_11 >> 16 , F_5 ( V_7 -> V_11 . V_13 + F_63 ( 0 ) ) ) ;
if ( ! V_51 ) {
V_92 = F_39 ( V_7 ) ;
if ( V_92 < 0 ) {
V_21 = - V_101 ;
goto V_50;
}
V_51 = ! ! V_92 ;
}
if ( V_51 )
F_41 ( V_2 , L_10 ) ;
V_91 =
F_28 ( V_7 -> V_11 . V_13 +
F_64 ( V_7 -> V_11 . V_17 ) ) ;
F_65 ( V_2 , L_11 ,
V_91 ) ;
if ( V_91 & V_102 )
F_65 ( V_2 , L_12 ) ;
if ( V_91 & V_82 )
F_65 ( V_2 , L_13 ) ;
if ( V_91 & V_103 )
F_65 ( V_2 , L_14 ) ;
if ( V_91 & V_104 )
F_65 ( V_2 , L_15 ) ;
if ( V_91 & V_105 )
F_65 ( V_2 , L_16 ) ;
if ( V_91 & V_106 )
F_65 ( V_2 , L_17 ) ;
if ( V_91 & V_80 )
F_65 ( V_2 , L_18 ) ;
if ( V_91 & V_81 )
F_65 ( V_2 , L_19 ) ;
if ( V_91 & V_79 )
F_65 ( V_2 , L_20 ) ;
if ( F_66 ( V_7 ) ) {
F_24 ( V_2 , L_21 ) ;
V_21 = - V_101 ;
goto V_50;
}
F_67 ( & V_7 -> V_11 . V_39 ) ;
F_67 ( & V_7 -> V_11 . V_25 ) ;
if ( V_107 && V_89 -> V_23 != - 1 ) {
if ( V_89 -> V_23 ) {
F_46 ( V_7 , V_53 , V_108 ,
V_89 -> V_23 ) ;
if ( ! V_7 -> V_11 . V_23 )
F_24 ( V_7 -> V_45 , V_109
L_22 ) ;
} else
F_51 ( V_7 , V_53 ) ;
}
if ( V_7 -> V_58 & V_59 ) {
V_21 = F_68 ( V_7 ) ;
if ( V_21 == V_110 ) {
F_69 ( V_2 , L_23 ) ;
V_21 = F_70 ( V_7 , V_87 ) ;
if ( ! V_21 )
V_21 = F_68 ( V_7 ) ;
}
if ( V_21 ) {
F_24 ( V_2 , L_24 ) ;
if ( V_21 > 0 )
V_21 = - V_101 ;
goto V_50;
}
} else {
if ( F_71 ( V_7 ) ) {
F_24 ( V_2 , L_24 ) ;
V_21 = - V_101 ;
goto V_50;
}
}
return F_72 ( V_7 ) ;
V_50:
F_53 ( V_7 ) ;
return V_21 ;
}
static void F_73 ( struct V_6 * V_7 )
{
T_3 V_53 ;
F_11 ( V_7 -> V_11 . V_23 , V_7 -> V_11 . V_13 +
F_48 ( V_7 -> V_11 . V_17 ) ) ;
V_53 =
F_28 ( V_7 -> V_11 . V_13 +
F_29 ( V_7 -> V_11 . V_17 ) ) ;
V_53 |= V_82
| V_80 | V_79
| V_81 | V_54 ;
F_30 ( V_53 ,
V_7 -> V_11 . V_13 + F_29 ( V_7 -> V_11 . V_17 ) ) ;
}
static int F_74 ( struct V_88 * V_2 )
{
struct V_6 * V_7 = F_75 ( V_2 ) ;
int V_111 ;
if ( V_7 -> V_11 . V_23 )
F_73 ( V_7 ) ;
V_111 = F_76 ( V_2 ) ;
if ( V_111 )
return V_111 ;
if ( ! ( V_7 -> V_58 & V_59 ) )
F_71 ( V_7 ) ;
return 0 ;
}
static int F_77 ( struct V_112 * V_112 ,
const struct V_113 * V_114 )
{
struct V_89 V_89 = {} ;
T_6 V_90 = NULL ;
struct V_115 * V_96 ;
V_96 = F_78 ( V_112 , V_116 , 0 ) ;
if ( ! V_96 )
return - V_101 ;
V_89 . V_96 = * V_96 ;
if ( F_79 ( V_112 , 0 ) )
V_89 . V_23 = F_80 ( V_112 , 0 ) ;
else
V_89 . V_23 = - 1 ;
if ( F_81 ( V_112 ) ) {
if ( F_3 ( F_81 ( V_112 ) ) )
V_51 = true ;
V_90 = F_82 ( & V_112 -> V_2 ) ;
}
return F_55 ( & V_112 -> V_2 , & V_89 , V_90 ) ;
}
static void F_83 ( struct V_112 * V_2 )
{
struct V_6 * V_7 = F_84 ( V_2 ) ;
F_85 ( V_7 ) ;
F_53 ( V_7 ) ;
}
static int F_86 ( struct V_117 * V_118 , void * V_119 )
{
struct V_89 * V_89 = (struct V_89 * ) V_119 ;
struct V_115 V_96 ;
if ( F_87 ( V_118 , 0 , & V_96 ) )
V_89 -> V_23 = V_96 . V_120 ;
else if ( F_88 ( V_118 , & V_96 ) ) {
V_89 -> V_96 = V_96 ;
V_89 -> V_96 . V_121 = NULL ;
}
return 1 ;
}
static int F_89 ( struct V_1 * V_122 )
{
struct V_123 * V_124 ;
T_7 V_125 ;
struct V_126 V_127 ;
struct V_89 V_89 = {} ;
int V_111 ;
V_125 = F_90 ( V_128 , 1 ,
(struct V_129 * * ) & V_124 ) ;
if ( F_91 ( V_125 ) || V_124 -> V_130 . V_131 < sizeof( * V_124 ) ) {
F_24 ( & V_122 -> V_2 ,
V_109 L_25 ) ;
return - V_132 ;
}
if ( V_124 -> V_133 != V_134 )
return - V_101 ;
F_92 ( & V_127 ) ;
V_89 . V_23 = - 1 ;
V_111 = F_93 ( V_122 , & V_127 , F_86 ,
& V_89 ) ;
if ( V_111 < 0 )
return V_111 ;
F_94 ( & V_127 ) ;
if ( F_95 ( & V_89 . V_96 ) != V_116 ) {
F_24 ( & V_122 -> V_2 ,
V_109 L_26 ) ;
return - V_132 ;
}
if ( F_3 ( V_122 ) )
V_51 = true ;
return F_55 ( & V_122 -> V_2 , & V_89 , V_122 -> V_135 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_75 ( & V_2 -> V_2 ) ;
F_85 ( V_7 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
static int F_97 ( struct V_136 * V_45 )
{
struct V_89 V_89 = {} ;
struct V_115 * V_96 ;
V_96 = F_98 ( V_45 , V_116 , 0 ) ;
if ( V_96 == NULL ) {
F_24 ( & V_45 -> V_2 , L_27 ) ;
return - V_101 ;
}
V_89 . V_96 = * V_96 ;
V_96 = F_98 ( V_45 , V_137 , 0 ) ;
if ( V_96 ) {
V_89 . V_23 = V_96 -> V_120 ;
} else {
if ( V_45 == V_138 )
V_89 . V_23 = - 1 ;
else
V_89 . V_23 = 0 ;
}
return F_55 ( & V_45 -> V_2 , & V_89 , NULL ) ;
}
static int F_99 ( struct V_136 * V_45 )
{
struct V_6 * V_7 = F_75 ( & V_45 -> V_2 ) ;
F_85 ( V_7 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
static int F_100 ( void )
{
struct V_136 * V_45 ;
static const struct V_115 V_139 [] = {
{
. V_120 = 0xFED40000 ,
. V_140 = 0xFED40000 + V_141 - 1 ,
. V_58 = V_116 ,
} ,
} ;
if ( ! V_18 )
return 0 ;
V_45 = F_101 ( L_28 , - 1 , V_139 ,
F_38 ( V_139 ) ) ;
if ( F_58 ( V_45 ) )
return F_59 ( V_45 ) ;
V_138 = V_45 ;
return 0 ;
}
static int T_8 F_102 ( void )
{
int V_21 ;
V_21 = F_100 () ;
if ( V_21 )
goto V_142;
V_21 = F_103 ( & V_143 ) ;
if ( V_21 )
goto V_144;
#ifdef F_60
V_21 = F_104 ( & V_145 ) ;
if ( V_21 )
goto V_146;
#endif
if ( F_52 ( V_147 ) ) {
V_21 = F_105 ( & V_148 ) ;
if ( V_21 )
goto V_149;
}
return 0 ;
V_149:
#ifdef F_60
F_106 ( & V_145 ) ;
V_146:
#endif
F_107 ( V_138 ) ;
V_144:
if ( V_138 )
F_107 ( V_138 ) ;
V_142:
return V_21 ;
}
static void T_9 F_108 ( void )
{
F_109 ( & V_148 ) ;
#ifdef F_60
F_106 ( & V_145 ) ;
#endif
F_110 ( & V_143 ) ;
if ( V_138 )
F_107 ( V_138 ) ;
}
