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
static int F_19 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_35 )
{
int V_36 = 0 , V_31 ;
while ( V_36 < V_35 &&
F_20 ( V_8 ,
V_37 | V_38 ,
V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_40 )
== 0 ) {
V_31 = F_18 ( V_8 ) ;
for (; V_31 > 0 && V_36 < V_35 ; V_31 -- )
V_34 [ V_36 ++ ] = F_5 ( V_8 -> V_10 . V_11 +
F_21 ( V_8 -> V_10 .
V_14 ) ) ;
}
return V_36 ;
}
static int F_22 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_35 )
{
int V_36 = 0 ;
int V_41 , V_42 ;
if ( V_35 < V_43 ) {
V_36 = - V_44 ;
goto V_45;
}
if ( ( V_36 =
F_19 ( V_8 , V_34 , V_43 ) ) < V_43 ) {
F_23 ( V_8 -> V_2 , L_2 ) ;
goto V_45;
}
V_41 = F_24 ( * ( V_46 * ) ( V_34 + 2 ) ) ;
if ( V_41 > V_35 ) {
V_36 = - V_44 ;
goto V_45;
}
if ( ( V_36 +=
F_19 ( V_8 , & V_34 [ V_43 ] ,
V_41 - V_43 ) ) < V_41 ) {
F_23 ( V_8 -> V_2 , L_3 ) ;
V_36 = - V_47 ;
goto V_45;
}
F_20 ( V_8 , V_38 , V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_25 ) ;
V_42 = F_15 ( V_8 ) ;
if ( V_42 & V_37 ) {
F_23 ( V_8 -> V_2 , L_4 ) ;
V_36 = - V_44 ;
goto V_45;
}
V_45:
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_36 ;
}
static int F_25 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_48 )
{
int V_19 , V_42 , V_31 ;
T_2 V_35 = 0 ;
if ( F_9 ( V_8 , 0 ) < 0 )
return - V_33 ;
V_42 = F_15 ( V_8 ) ;
if ( ( V_42 & V_30 ) == 0 ) {
F_17 ( V_8 ) ;
if ( F_20
( V_8 , V_30 , V_8 -> V_10 . V_49 ,
& V_8 -> V_10 . V_25 ) < 0 ) {
V_19 = - V_47 ;
goto V_50;
}
}
while ( V_35 < V_48 - 1 ) {
V_31 = F_18 ( V_8 ) ;
for (; V_31 > 0 && V_35 < V_48 - 1 ; V_31 -- ) {
F_8 ( V_34 [ V_35 ] , V_8 -> V_10 . V_11 +
F_21 ( V_8 -> V_10 . V_14 ) ) ;
V_35 ++ ;
}
F_20 ( V_8 , V_38 , V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_25 ) ;
V_42 = F_15 ( V_8 ) ;
if ( ! V_51 && ( V_42 & V_52 ) == 0 ) {
V_19 = - V_44 ;
goto V_50;
}
}
F_8 ( V_34 [ V_35 ] ,
V_8 -> V_10 . V_11 + F_21 ( V_8 -> V_10 . V_14 ) ) ;
F_20 ( V_8 , V_38 , V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_25 ) ;
V_42 = F_15 ( V_8 ) ;
if ( ( V_42 & V_52 ) != 0 ) {
V_19 = - V_44 ;
goto V_50;
}
return 0 ;
V_50:
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_19 ;
}
static int F_26 ( struct V_7 * V_8 , T_1 * V_34 , T_2 V_48 )
{
int V_19 ;
T_3 V_53 ;
V_19 = F_25 ( V_8 , V_34 , V_48 ) ;
if ( V_19 < 0 )
return V_19 ;
F_8 ( V_54 ,
V_8 -> V_10 . V_11 + F_16 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_8 -> V_10 . V_23 ) {
V_53 = F_24 ( * ( ( V_46 * ) ( V_34 + 6 ) ) ) ;
if ( F_20
( V_8 , V_37 | V_38 ,
F_27 ( V_8 , V_53 ) ,
& V_8 -> V_10 . V_40 ) < 0 ) {
V_19 = - V_47 ;
goto V_50;
}
}
return V_48 ;
V_50:
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_19 ;
}
static int F_28 ( struct V_7 * V_8 )
{
int V_19 = 0 ;
T_1 V_55 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_2 V_48 = sizeof( V_55 ) ;
int V_56 = V_51 ;
V_51 = 0 ;
V_19 = F_25 ( V_8 , V_55 , V_48 ) ;
if ( V_19 == 0 )
goto V_45;
F_17 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
V_51 = 1 ;
V_19 = F_25 ( V_8 , V_55 , V_48 ) ;
if ( V_19 == 0 ) {
F_29 ( V_8 -> V_2 , L_5 ) ;
V_19 = 1 ;
} else
V_19 = - V_57 ;
V_45:
V_51 = V_56 ;
F_17 ( V_8 ) ;
F_13 ( V_8 -> V_10 . V_49 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_19 ;
}
static T_4 F_30 ( int V_23 , void * V_58 )
{
struct V_7 * V_8 = V_58 ;
T_3 V_59 ;
V_59 = F_31 ( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_59 == 0 )
return V_60 ;
V_8 -> V_10 . V_61 = V_23 ;
F_33 ( V_59 ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
return V_62 ;
}
static T_4 F_34 ( int V_63 , void * V_58 )
{
struct V_7 * V_8 = V_58 ;
T_3 V_59 ;
int V_64 ;
V_59 = F_31 ( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_59 == 0 )
return V_60 ;
if ( V_59 & V_65 )
F_35 ( & V_8 -> V_10 . V_40 ) ;
if ( V_59 & V_66 )
for ( V_64 = 0 ; V_64 < 5 ; V_64 ++ )
if ( F_4 ( V_8 , V_64 ) >= 0 )
break;
if ( V_59 &
( V_66 | V_67 |
V_68 ) )
F_35 ( & V_8 -> V_10 . V_25 ) ;
F_33 ( V_59 ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_31 ( V_8 -> V_10 . V_11 + F_32 ( V_8 -> V_10 . V_14 ) ) ;
return V_62 ;
}
static int F_36 ( struct V_69 * V_2 , T_5 V_70 ,
T_5 V_48 , unsigned int V_23 )
{
T_3 V_10 , V_71 , V_72 ;
int V_19 , V_64 , V_73 , V_74 ;
struct V_7 * V_8 ;
if ( ! ( V_8 = F_37 ( V_2 , & V_75 ) ) )
return - V_76 ;
V_8 -> V_10 . V_11 = F_38 ( V_70 , V_48 ) ;
if ( ! V_8 -> V_10 . V_11 ) {
V_19 = - V_44 ;
goto V_50;
}
V_8 -> V_10 . V_22 = F_39 ( V_77 ) ;
V_8 -> V_10 . V_49 = F_39 ( V_78 ) ;
V_8 -> V_10 . V_39 = F_39 ( V_77 ) ;
V_8 -> V_10 . V_32 = F_39 ( V_77 ) ;
if ( F_9 ( V_8 , 0 ) != 0 ) {
V_19 = - V_76 ;
goto V_50;
}
V_10 = F_31 ( V_8 -> V_10 . V_11 + F_40 ( 0 ) ) ;
F_29 ( V_2 ,
L_6 ,
V_10 >> 16 , F_5 ( V_8 -> V_10 . V_11 + F_41 ( 0 ) ) ) ;
if ( ! V_51 ) {
V_51 = F_28 ( V_8 ) ;
if ( V_51 < 0 ) {
V_19 = - V_76 ;
goto V_50;
}
}
if ( V_51 )
F_29 ( V_2 , L_7 ) ;
V_71 =
F_31 ( V_8 -> V_10 . V_11 +
F_42 ( V_8 -> V_10 . V_14 ) ) ;
F_43 ( V_2 , L_8 ,
V_71 ) ;
if ( V_71 & V_79 )
F_43 ( V_2 , L_9 ) ;
if ( V_71 & V_68 )
F_43 ( V_2 , L_10 ) ;
if ( V_71 & V_80 )
F_43 ( V_2 , L_11 ) ;
if ( V_71 & V_81 )
F_43 ( V_2 , L_12 ) ;
if ( V_71 & V_82 )
F_43 ( V_2 , L_13 ) ;
if ( V_71 & V_83 )
F_43 ( V_2 , L_14 ) ;
if ( V_71 & V_66 )
F_43 ( V_2 , L_15 ) ;
if ( V_71 & V_67 )
F_43 ( V_2 , L_16 ) ;
if ( V_71 & V_65 )
F_43 ( V_2 , L_17 ) ;
if ( F_44 ( V_8 ) ) {
F_23 ( V_2 , L_18 ) ;
V_19 = - V_76 ;
goto V_50;
}
if ( F_45 ( V_8 ) ) {
F_23 ( V_2 , L_19 ) ;
V_19 = - V_76 ;
goto V_50;
}
F_46 ( & V_8 -> V_10 . V_40 ) ;
F_46 ( & V_8 -> V_10 . V_25 ) ;
V_72 =
F_31 ( V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
V_72 |= V_68
| V_66 | V_65
| V_67 ;
F_33 ( V_72 ,
V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_84 )
V_8 -> V_10 . V_23 = V_23 ;
if ( V_84 && ! V_8 -> V_10 . V_23 ) {
V_73 =
F_5 ( V_8 -> V_10 . V_11 +
F_48 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_73 ) {
V_74 = V_73 ;
} else {
V_73 = 3 ;
V_74 = 15 ;
}
for ( V_64 = V_73 ; V_64 <= V_74 && V_8 -> V_10 . V_23 == 0 ; V_64 ++ ) {
F_8 ( V_64 , V_8 -> V_10 . V_11 +
F_48 ( V_8 -> V_10 . V_14 ) ) ;
if ( F_49
( V_64 , F_30 , V_85 ,
V_8 -> V_10 . V_86 . V_87 , V_8 ) != 0 ) {
F_29 ( V_8 -> V_2 ,
L_20 ,
V_64 ) ;
continue;
}
F_33 ( F_31
( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_33 ( V_72 | V_88 ,
V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
V_8 -> V_10 . V_61 = 0 ;
F_50 ( V_8 ) ;
V_8 -> V_10 . V_23 = V_8 -> V_10 . V_61 ;
F_33 ( F_31
( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_33 ( V_72 ,
V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
F_51 ( V_64 , V_8 ) ;
}
}
if ( V_8 -> V_10 . V_23 ) {
F_8 ( V_8 -> V_10 . V_23 ,
V_8 -> V_10 . V_11 +
F_48 ( V_8 -> V_10 . V_14 ) ) ;
if ( F_49
( V_8 -> V_10 . V_23 , F_34 , V_85 ,
V_8 -> V_10 . V_86 . V_87 , V_8 ) != 0 ) {
F_29 ( V_8 -> V_2 ,
L_21 ,
V_8 -> V_10 . V_23 ) ;
V_8 -> V_10 . V_23 = 0 ;
} else {
F_33 ( F_31
( V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_32 ( V_8 -> V_10 . V_14 ) ) ;
F_33 ( V_72 | V_88 ,
V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
}
}
F_52 ( & V_8 -> V_10 . V_89 ) ;
F_53 ( & V_90 ) ;
F_54 ( & V_8 -> V_10 . V_89 , & V_91 ) ;
F_55 ( & V_90 ) ;
return 0 ;
V_50:
if ( V_8 -> V_10 . V_11 )
F_56 ( V_8 -> V_10 . V_11 ) ;
F_57 ( V_8 -> V_2 ) ;
return V_19 ;
}
static void F_58 ( struct V_7 * V_8 )
{
T_3 V_72 ;
F_8 ( V_8 -> V_10 . V_23 , V_8 -> V_10 . V_11 +
F_48 ( V_8 -> V_10 . V_14 ) ) ;
V_72 =
F_31 ( V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
V_72 |= V_68
| V_66 | V_65
| V_67 | V_88 ;
F_33 ( V_72 ,
V_8 -> V_10 . V_11 + F_47 ( V_8 -> V_10 . V_14 ) ) ;
}
static int T_6 F_59 ( struct V_1 * V_1 ,
const struct V_92 * V_93 )
{
T_5 V_70 , V_48 ;
unsigned int V_23 = 0 ;
V_70 = F_60 ( V_1 , 0 ) ;
V_48 = F_61 ( V_1 , 0 ) ;
if ( F_62 ( V_1 , 0 ) )
V_23 = F_63 ( V_1 , 0 ) ;
else
V_84 = 0 ;
if ( F_1 ( V_1 ) )
V_51 = 1 ;
return F_36 ( & V_1 -> V_2 , V_70 , V_48 , V_23 ) ;
}
static int F_64 ( struct V_1 * V_2 , T_7 V_94 )
{
return F_65 ( & V_2 -> V_2 , V_94 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_67 ( V_2 ) ;
int V_95 ;
if ( V_8 -> V_10 . V_23 )
F_58 ( V_8 ) ;
V_95 = F_68 ( & V_2 -> V_2 ) ;
if ( ! V_95 )
F_45 ( V_8 ) ;
return V_95 ;
}
static T_8 void F_69 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_67 ( V_2 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
}
static int F_72 ( struct V_96 * V_2 , T_7 V_94 )
{
return F_65 ( & V_2 -> V_2 , V_94 ) ;
}
static int F_73 ( struct V_96 * V_2 )
{
struct V_7 * V_8 = F_74 ( & V_2 -> V_2 ) ;
if ( V_8 -> V_10 . V_23 )
F_58 ( V_8 ) ;
return F_68 ( & V_2 -> V_2 ) ;
}
static int T_9 F_75 ( void )
{
int V_19 ;
#ifdef F_76
if ( ! V_15 )
return F_77 ( & V_97 ) ;
#endif
V_19 = F_78 ( & V_98 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_79 ( V_99 = F_80 ( L_22 , - 1 , NULL , 0 ) ) )
return F_81 ( V_99 ) ;
if( ( V_19 = F_36 ( & V_99 -> V_2 , V_100 , V_101 , 0 ) ) != 0 ) {
F_82 ( V_99 ) ;
F_83 ( & V_98 ) ;
}
return V_19 ;
}
static void T_10 F_84 ( void )
{
struct V_102 * V_64 , * V_103 ;
struct V_7 * V_8 ;
F_53 ( & V_90 ) ;
F_85 (i, j, &tis_chips, list) {
V_8 = F_86 ( V_64 ) ;
F_57 ( V_8 -> V_2 ) ;
F_33 ( ~ V_88 &
F_31 ( V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 .
V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_47 ( V_8 -> V_10 . V_14 ) ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 1 ) ;
if ( V_8 -> V_10 . V_23 )
F_51 ( V_8 -> V_10 . V_23 , V_8 ) ;
F_56 ( V_64 -> V_11 ) ;
F_87 ( & V_64 -> V_89 ) ;
}
F_55 ( & V_90 ) ;
#ifdef F_76
if ( ! V_15 ) {
F_88 ( & V_97 ) ;
return;
}
#endif
F_82 ( V_99 ) ;
F_83 ( & V_98 ) ;
}
