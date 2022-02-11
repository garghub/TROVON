static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
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
if ( ( F_5 ( V_8 -> V_10 . V_11 + F_6 ( V_9 ) ) &
( V_12 | V_13 ) ) ==
( V_12 | V_13 ) )
return V_8 -> V_10 . V_14 = V_9 ;
return - 1 ;
}
static void F_7 ( struct V_7 * V_8 , int V_9 , int V_15 )
{
if ( V_15 || ( F_5 ( V_8 -> V_10 . V_11 + F_6 ( V_9 ) ) &
( V_16 | V_13 ) ) ==
( V_16 | V_13 ) )
F_8 ( V_12 ,
V_8 -> V_10 . V_11 + F_6 ( V_9 ) ) ;
}
static int F_9 ( struct V_7 * V_8 , int V_9 )
{
unsigned long V_17 , V_18 ;
long V_19 ;
if ( F_4 ( V_8 , V_9 ) >= 0 )
return V_9 ;
F_8 ( V_20 ,
V_8 -> V_10 . V_11 + F_6 ( V_9 ) ) ;
V_17 = V_21 + V_8 -> V_10 . V_22 ;
if ( V_8 -> V_10 . V_23 ) {
V_24:
V_18 = V_17 - V_21 ;
if ( ( long ) V_18 <= 0 )
return - 1 ;
V_19 = F_10 ( V_8 -> V_10 . V_25 ,
( F_4
( V_8 , V_9 ) >= 0 ) ,
V_18 ) ;
if ( V_19 > 0 )
return V_9 ;
if ( V_19 == - V_26 && F_11 ( V_27 ) ) {
F_12 ( V_28 ) ;
goto V_24;
}
} else {
do {
if ( F_4 ( V_8 , V_9 ) >= 0 )
return V_9 ;
F_13 ( V_29 ) ;
}
while ( F_14 ( V_21 , V_17 ) );
}
return - 1 ;
}
static T_1 F_15 ( struct V_7 * V_8 )
{
return F_5 ( V_8 -> V_10 . V_11 +
F_16 ( V_8 -> V_10 . V_14 ) ) ;
}
static void F_17 ( struct V_7 * V_8 )
{
F_8 ( V_30 ,
V_8 -> V_10 . V_11 + F_16 ( V_8 -> V_10 . V_14 ) ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
unsigned long V_17 ;
int V_31 ;
V_17 = V_21 + V_8 -> V_10 . V_32 ;
do {
V_31 = F_5 ( V_8 -> V_10 . V_11 +
F_16 ( V_8 -> V_10 . V_14 ) + 1 ) ;
V_31 += F_5 ( V_8 -> V_10 . V_11 +
F_16 ( V_8 -> V_10 . V_14 ) +
2 ) << 8 ;
if ( V_31 )
return V_31 ;
F_13 ( V_29 ) ;
} while ( F_14 ( V_21 , V_17 ) );
return - V_33 ;
}
static int F_19 ( struct V_7 * V_8 , T_1 V_34 , unsigned long V_18 ,
T_2 * V_35 )
{
unsigned long V_17 ;
long V_19 ;
T_1 V_36 ;
V_36 = F_15 ( V_8 ) ;
if ( ( V_36 & V_34 ) == V_34 )
return 0 ;
V_17 = V_21 + V_18 ;
if ( V_8 -> V_10 . V_23 ) {
V_24:
V_18 = V_17 - V_21 ;
if ( ( long ) V_18 <= 0 )
return - V_37 ;
V_19 = F_10 ( * V_35 ,
( ( F_15
( V_8 ) & V_34 ) ==
V_34 ) , V_18 ) ;
if ( V_19 > 0 )
return 0 ;
if ( V_19 == - V_26 && F_11 ( V_27 ) ) {
F_12 ( V_28 ) ;
goto V_24;
}
} else {
do {
F_13 ( V_29 ) ;
V_36 = F_15 ( V_8 ) ;
if ( ( V_36 & V_34 ) == V_34 )
return 0 ;
} while ( F_14 ( V_21 , V_17 ) );
}
return - V_37 ;
}
static int F_20 ( struct V_7 * V_8 , T_1 * V_38 , T_3 V_39 )
{
int V_40 = 0 , V_31 ;
while ( V_40 < V_39 &&
F_19 ( V_8 ,
V_41 | V_42 ,
V_8 -> V_10 . V_43 ,
& V_8 -> V_10 . V_44 )
== 0 ) {
V_31 = F_18 ( V_8 ) ;
for (; V_31 > 0 && V_40 < V_39 ; V_31 -- )
V_38 [ V_40 ++ ] = F_5 ( V_8 -> V_10 . V_11 +
F_21 ( V_8 -> V_10 .
V_14 ) ) ;
}
return V_40 ;
}
static int F_22 ( struct V_7 * V_8 , T_1 * V_38 , T_3 V_39 )
{
int V_40 = 0 ;
int V_45 , V_36 ;
if ( V_39 < V_46 ) {
V_40 = - V_47 ;
goto V_48;
}
if ( ( V_40 =
F_20 ( V_8 , V_38 , V_46 ) ) < V_46 ) {
F_23 ( V_8 -> V_2 , L_2 ) ;
goto V_48;
}
V_45 = F_24 ( * ( V_49 * ) ( V_38 + 2 ) ) ;
if ( V_45 > V_39 ) {
V_40 = - V_47 ;
goto V_48;
}
if ( ( V_40 +=
F_20 ( V_8 , & V_38 [ V_46 ] ,
V_45 - V_46 ) ) < V_45 ) {
F_23 ( V_8 -> V_2 , L_3 ) ;
V_40 = - V_37 ;
goto V_48;
}
F_19 ( V_8 , V_42 , V_8 -> V_10 . V_43 ,
& V_8 -> V_10 . V_25 ) ;
V_36 = F_15 ( V_8 ) ;
if ( V_36 & V_41 ) {
F_23 ( V_8 -> V_2 , L_4 ) ;
V_40 = - V_47 ;
goto V_48;
}
V_48:
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_40 ;
}
static int F_25 ( struct V_7 * V_8 , T_1 * V_38 , T_3 V_50 )
{
int V_19 , V_36 , V_31 ;
T_3 V_39 = 0 ;
if ( F_9 ( V_8 , 0 ) < 0 )
return - V_33 ;
V_36 = F_15 ( V_8 ) ;
if ( ( V_36 & V_30 ) == 0 ) {
F_17 ( V_8 ) ;
if ( F_19
( V_8 , V_30 , V_8 -> V_10 . V_51 ,
& V_8 -> V_10 . V_25 ) < 0 ) {
V_19 = - V_37 ;
goto V_52;
}
}
while ( V_39 < V_50 - 1 ) {
V_31 = F_18 ( V_8 ) ;
for (; V_31 > 0 && V_39 < V_50 - 1 ; V_31 -- ) {
F_8 ( V_38 [ V_39 ] , V_8 -> V_10 . V_11 +
F_21 ( V_8 -> V_10 . V_14 ) ) ;
V_39 ++ ;
}
F_19 ( V_8 , V_42 , V_8 -> V_10 . V_43 ,
& V_8 -> V_10 . V_25 ) ;
V_36 = F_15 ( V_8 ) ;
if ( ! V_53 && ( V_36 & V_54 ) == 0 ) {
V_19 = - V_47 ;
goto V_52;
}
}
F_8 ( V_38 [ V_39 ] ,
V_8 -> V_10 . V_11 + F_21 ( V_8 -> V_10 . V_14 ) ) ;
F_19 ( V_8 , V_42 , V_8 -> V_10 . V_43 ,
& V_8 -> V_10 . V_25 ) ;
V_36 = F_15 ( V_8 ) ;
if ( ( V_36 & V_54 ) != 0 ) {
V_19 = - V_47 ;
goto V_52;
}
return 0 ;
V_52:
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_19 ;
}
static int F_26 ( struct V_7 * V_8 , T_1 * V_38 , T_3 V_50 )
{
int V_19 ;
T_4 V_55 ;
V_19 = F_25 ( V_8 , V_38 , V_50 ) ;
if ( V_19 < 0 )
return V_19 ;
F_8 ( V_56 ,
V_8 -> V_10 . V_11 + F_16 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_8 -> V_10 . V_23 ) {
V_55 = F_24 ( * ( ( V_49 * ) ( V_38 + 6 ) ) ) ;
if ( F_19
( V_8 , V_41 | V_42 ,
F_27 ( V_8 , V_55 ) ,
& V_8 -> V_10 . V_44 ) < 0 ) {
V_19 = - V_37 ;
goto V_52;
}
}
return V_50 ;
V_52:
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_19 ;
}
static int F_28 ( struct V_7 * V_8 )
{
int V_19 = 0 ;
T_1 V_57 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_3 V_50 = sizeof( V_57 ) ;
int V_58 = V_53 ;
V_53 = 0 ;
V_19 = F_25 ( V_8 , V_57 , V_50 ) ;
if ( V_19 == 0 )
goto V_48;
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
V_53 = 1 ;
V_19 = F_25 ( V_8 , V_57 , V_50 ) ;
if ( V_19 == 0 ) {
F_29 ( V_8 -> V_2 , L_5 ) ;
V_19 = 1 ;
} else
V_19 = - V_59 ;
V_48:
V_53 = V_58 ;
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_19 ;
}
static T_5 F_30 ( int V_23 , void * V_60 )
{
struct V_7 * V_8 = V_60 ;
T_4 V_61 ;
V_61 = F_31 ( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_61 == 0 )
return V_62 ;
V_8 -> V_10 . V_63 = V_23 ;
F_33 ( V_61 ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
return V_64 ;
}
static T_5 F_34 ( int V_65 , void * V_60 )
{
struct V_7 * V_8 = V_60 ;
T_4 V_61 ;
int V_66 ;
V_61 = F_31 ( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_61 == 0 )
return V_62 ;
if ( V_61 & V_67 )
F_35 ( & V_8 -> V_10 . V_44 ) ;
if ( V_61 & V_68 )
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ )
if ( F_4 ( V_8 , V_66 ) >= 0 )
break;
if ( V_61 &
( V_68 | V_69 |
V_70 ) )
F_35 ( & V_8 -> V_10 . V_25 ) ;
F_33 ( V_61 ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_31 ( V_8 -> V_10 . V_11 + F_32 ( V_8 -> V_10 . V_14 ) ) ;
return V_64 ;
}
static int F_36 ( struct V_71 * V_2 , T_6 V_72 ,
T_6 V_50 , unsigned int V_23 )
{
T_4 V_10 , V_73 , V_74 ;
int V_19 , V_66 , V_75 , V_76 ;
struct V_7 * V_8 ;
if ( ! ( V_8 = F_37 ( V_2 , & V_77 ) ) )
return - V_78 ;
V_8 -> V_10 . V_11 = F_38 ( V_72 , V_50 ) ;
if ( ! V_8 -> V_10 . V_11 ) {
V_19 = - V_47 ;
goto V_52;
}
V_8 -> V_10 . V_22 = F_39 ( V_79 ) ;
V_8 -> V_10 . V_51 = F_39 ( V_80 ) ;
V_8 -> V_10 . V_43 = F_39 ( V_79 ) ;
V_8 -> V_10 . V_32 = F_39 ( V_79 ) ;
if ( F_9 ( V_8 , 0 ) != 0 ) {
V_19 = - V_78 ;
goto V_52;
}
V_10 = F_31 ( V_8 -> V_10 . V_11 + F_40 ( 0 ) ) ;
F_29 ( V_2 ,
L_6 ,
V_10 >> 16 , F_5 ( V_8 -> V_10 . V_11 + F_41 ( 0 ) ) ) ;
if ( ! V_53 ) {
V_53 = F_28 ( V_8 ) ;
if ( V_53 < 0 ) {
V_19 = - V_78 ;
goto V_52;
}
}
if ( V_53 )
F_29 ( V_2 , L_7 ) ;
V_73 =
F_31 ( V_8 -> V_10 . V_11 +
F_42 ( V_8 -> V_10 . V_14 ) ) ;
F_43 ( V_2 , L_8 ,
V_73 ) ;
if ( V_73 & V_81 )
F_43 ( V_2 , L_9 ) ;
if ( V_73 & V_70 )
F_43 ( V_2 , L_10 ) ;
if ( V_73 & V_82 )
F_43 ( V_2 , L_11 ) ;
if ( V_73 & V_83 )
F_43 ( V_2 , L_12 ) ;
if ( V_73 & V_84 )
F_43 ( V_2 , L_13 ) ;
if ( V_73 & V_85 )
F_43 ( V_2 , L_14 ) ;
if ( V_73 & V_68 )
F_43 ( V_2 , L_15 ) ;
if ( V_73 & V_69 )
F_43 ( V_2 , L_16 ) ;
if ( V_73 & V_67 )
F_43 ( V_2 , L_17 ) ;
F_44 ( V_8 ) ;
F_45 ( & V_8 -> V_10 . V_44 ) ;
F_45 ( & V_8 -> V_10 . V_25 ) ;
V_74 =
F_31 ( V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
V_74 |= V_70
| V_68 | V_67
| V_69 ;
F_33 ( V_74 ,
V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_86 )
V_8 -> V_10 . V_23 = V_23 ;
if ( V_86 && ! V_8 -> V_10 . V_23 ) {
V_75 =
F_5 ( V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_75 ) {
V_76 = V_75 ;
} else {
V_75 = 3 ;
V_76 = 15 ;
}
for ( V_66 = V_75 ; V_66 <= V_76 && V_8 -> V_10 . V_23 == 0 ; V_66 ++ ) {
F_8 ( V_66 , V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
if ( F_48
( V_66 , F_30 , V_87 ,
V_8 -> V_10 . V_88 . V_89 , V_8 ) != 0 ) {
F_29 ( V_8 -> V_2 ,
L_18 ,
V_66 ) ;
continue;
}
F_33 ( F_31
( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_33 ( V_74 | V_90 ,
V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
V_8 -> V_10 . V_63 = 0 ;
F_49 ( V_8 ) ;
V_8 -> V_10 . V_23 = V_8 -> V_10 . V_63 ;
F_33 ( F_31
( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_33 ( V_74 ,
V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
F_50 ( V_66 , V_8 ) ;
}
}
if ( V_8 -> V_10 . V_23 ) {
F_8 ( V_8 -> V_10 . V_23 ,
V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
if ( F_48
( V_8 -> V_10 . V_23 , F_34 , V_87 ,
V_8 -> V_10 . V_88 . V_89 , V_8 ) != 0 ) {
F_29 ( V_8 -> V_2 ,
L_19 ,
V_8 -> V_10 . V_23 ) ;
V_8 -> V_10 . V_23 = 0 ;
} else {
F_33 ( F_31
( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_33 ( V_74 | V_90 ,
V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
}
}
F_51 ( & V_8 -> V_10 . V_91 ) ;
F_52 ( & V_92 ) ;
F_53 ( & V_8 -> V_10 . V_91 , & V_93 ) ;
F_54 ( & V_92 ) ;
F_55 ( V_8 ) ;
return 0 ;
V_52:
if ( V_8 -> V_10 . V_11 )
F_56 ( V_8 -> V_10 . V_11 ) ;
F_57 ( V_8 -> V_2 ) ;
return V_19 ;
}
static void F_58 ( struct V_7 * V_8 )
{
T_4 V_74 ;
F_8 ( V_8 -> V_10 . V_23 , V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
V_74 =
F_31 ( V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
V_74 |= V_70
| V_68 | V_67
| V_69 | V_90 ;
F_33 ( V_74 ,
V_8 -> V_10 . V_11 + F_46 ( V_8 -> V_10 . V_14 ) ) ;
}
static int T_7 F_59 ( struct V_1 * V_1 ,
const struct V_94 * V_95 )
{
T_6 V_72 , V_50 ;
unsigned int V_23 = 0 ;
V_72 = F_60 ( V_1 , 0 ) ;
V_50 = F_61 ( V_1 , 0 ) ;
if ( F_62 ( V_1 , 0 ) )
V_23 = F_63 ( V_1 , 0 ) ;
else
V_86 = 0 ;
if ( F_1 ( V_1 ) )
V_53 = 1 ;
return F_36 ( & V_1 -> V_2 , V_72 , V_50 , V_23 ) ;
}
static int F_64 ( struct V_1 * V_2 , T_8 V_96 )
{
return F_65 ( & V_2 -> V_2 , V_96 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_67 ( V_2 ) ;
int V_97 ;
if ( V_8 -> V_10 . V_23 )
F_58 ( V_8 ) ;
V_97 = F_68 ( & V_2 -> V_2 ) ;
if ( ! V_97 )
F_55 ( V_8 ) ;
return V_97 ;
}
static T_9 void F_69 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_67 ( V_2 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
}
static int F_72 ( struct V_98 * V_2 , T_8 V_96 )
{
return F_65 ( & V_2 -> V_2 , V_96 ) ;
}
static int F_73 ( struct V_98 * V_2 )
{
struct V_7 * V_8 = F_74 ( & V_2 -> V_2 ) ;
if ( V_8 -> V_10 . V_23 )
F_58 ( V_8 ) ;
return F_68 ( & V_2 -> V_2 ) ;
}
static int T_10 F_75 ( void )
{
int V_19 ;
#ifdef F_76
if ( ! V_15 )
return F_77 ( & V_99 ) ;
#endif
V_19 = F_78 ( & V_100 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_79 ( V_101 = F_80 ( L_20 , - 1 , NULL , 0 ) ) )
return F_81 ( V_101 ) ;
if( ( V_19 = F_36 ( & V_101 -> V_2 , V_102 , V_103 , 0 ) ) != 0 ) {
F_82 ( V_101 ) ;
F_83 ( & V_100 ) ;
}
return V_19 ;
}
static void T_11 F_84 ( void )
{
struct V_104 * V_66 , * V_105 ;
struct V_7 * V_8 ;
F_52 ( & V_92 ) ;
F_85 (i, j, &tis_chips, list) {
V_8 = F_86 ( V_66 ) ;
F_57 ( V_8 -> V_2 ) ;
F_33 ( ~ V_90 &
F_31 ( V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 .
V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_46 ( V_8 -> V_10 . V_14 ) ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 1 ) ;
if ( V_8 -> V_10 . V_23 )
F_50 ( V_8 -> V_10 . V_23 , V_8 ) ;
F_56 ( V_66 -> V_11 ) ;
F_87 ( & V_66 -> V_91 ) ;
}
F_54 ( & V_92 ) ;
#ifdef F_76
if ( ! V_15 ) {
F_88 ( & V_99 ) ;
return;
}
#endif
F_82 ( V_101 ) ;
F_83 ( & V_100 ) ;
}
