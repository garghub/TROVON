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
static int F_1 ( struct V_1 * V_2 )
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
unsigned long V_17 ;
long V_18 ;
if ( F_4 ( V_8 , V_9 ) >= 0 )
return V_9 ;
F_8 ( V_19 ,
V_8 -> V_10 . V_11 + F_6 ( V_9 ) ) ;
if ( V_8 -> V_10 . V_20 ) {
V_18 = F_10 ( V_8 -> V_10 . V_21 ,
( F_4
( V_8 , V_9 ) >= 0 ) ,
V_8 -> V_10 . V_22 ) ;
if ( V_18 > 0 )
return V_9 ;
} else {
V_17 = V_23 + V_8 -> V_10 . V_22 ;
do {
if ( F_4 ( V_8 , V_9 ) >= 0 )
return V_9 ;
F_11 ( V_24 ) ;
}
while ( F_12 ( V_23 , V_17 ) );
}
return - 1 ;
}
static T_1 F_13 ( struct V_7 * V_8 )
{
return F_5 ( V_8 -> V_10 . V_11 +
F_14 ( V_8 -> V_10 . V_14 ) ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
F_8 ( V_25 ,
V_8 -> V_10 . V_11 + F_14 ( V_8 -> V_10 . V_14 ) ) ;
}
static int F_16 ( struct V_7 * V_8 )
{
unsigned long V_17 ;
int V_26 ;
V_17 = V_23 + V_8 -> V_10 . V_27 ;
do {
V_26 = F_5 ( V_8 -> V_10 . V_11 +
F_14 ( V_8 -> V_10 . V_14 ) + 1 ) ;
V_26 += F_5 ( V_8 -> V_10 . V_11 +
F_14 ( V_8 -> V_10 . V_14 ) +
2 ) << 8 ;
if ( V_26 )
return V_26 ;
F_11 ( V_24 ) ;
} while ( F_12 ( V_23 , V_17 ) );
return - V_28 ;
}
static int F_17 ( struct V_7 * V_8 , T_1 V_29 , unsigned long V_30 ,
T_2 * V_31 )
{
unsigned long V_17 ;
long V_18 ;
T_1 V_32 ;
V_32 = F_13 ( V_8 ) ;
if ( ( V_32 & V_29 ) == V_29 )
return 0 ;
if ( V_8 -> V_10 . V_20 ) {
V_18 = F_10 ( * V_31 ,
( ( F_13
( V_8 ) & V_29 ) ==
V_29 ) , V_30 ) ;
if ( V_18 > 0 )
return 0 ;
} else {
V_17 = V_23 + V_30 ;
do {
F_11 ( V_24 ) ;
V_32 = F_13 ( V_8 ) ;
if ( ( V_32 & V_29 ) == V_29 )
return 0 ;
} while ( F_12 ( V_23 , V_17 ) );
}
return - V_33 ;
}
static int F_18 ( struct V_7 * V_8 , T_1 * V_34 , T_3 V_35 )
{
int V_36 = 0 , V_26 ;
while ( V_36 < V_35 &&
F_17 ( V_8 ,
V_37 | V_38 ,
V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_40 )
== 0 ) {
V_26 = F_16 ( V_8 ) ;
for (; V_26 > 0 && V_36 < V_35 ; V_26 -- )
V_34 [ V_36 ++ ] = F_5 ( V_8 -> V_10 . V_11 +
F_19 ( V_8 -> V_10 .
V_14 ) ) ;
}
return V_36 ;
}
static int F_20 ( struct V_7 * V_8 , T_1 * V_34 , T_3 V_35 )
{
int V_36 = 0 ;
int V_41 , V_32 ;
if ( V_35 < V_42 ) {
V_36 = - V_43 ;
goto V_44;
}
if ( ( V_36 =
F_18 ( V_8 , V_34 , V_42 ) ) < V_42 ) {
F_21 ( V_8 -> V_2 , L_2 ) ;
goto V_44;
}
V_41 = F_22 ( * ( V_45 * ) ( V_34 + 2 ) ) ;
if ( V_41 > V_35 ) {
V_36 = - V_43 ;
goto V_44;
}
if ( ( V_36 +=
F_18 ( V_8 , & V_34 [ V_42 ] ,
V_41 - V_42 ) ) < V_41 ) {
F_21 ( V_8 -> V_2 , L_3 ) ;
V_36 = - V_33 ;
goto V_44;
}
F_17 ( V_8 , V_38 , V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_21 ) ;
V_32 = F_13 ( V_8 ) ;
if ( V_32 & V_37 ) {
F_21 ( V_8 -> V_2 , L_4 ) ;
V_36 = - V_43 ;
goto V_44;
}
V_44:
F_15 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_36 ;
}
static int F_23 ( struct V_7 * V_8 , T_1 * V_34 , T_3 V_46 )
{
int V_18 , V_32 , V_26 ;
T_3 V_35 = 0 ;
T_4 V_47 ;
if ( F_9 ( V_8 , 0 ) < 0 )
return - V_28 ;
V_32 = F_13 ( V_8 ) ;
if ( ( V_32 & V_25 ) == 0 ) {
F_15 ( V_8 ) ;
if ( F_17
( V_8 , V_25 , V_8 -> V_10 . V_48 ,
& V_8 -> V_10 . V_21 ) < 0 ) {
V_18 = - V_33 ;
goto V_49;
}
}
while ( V_35 < V_46 - 1 ) {
V_26 = F_16 ( V_8 ) ;
for (; V_26 > 0 && V_35 < V_46 - 1 ; V_26 -- ) {
F_8 ( V_34 [ V_35 ] , V_8 -> V_10 . V_11 +
F_19 ( V_8 -> V_10 . V_14 ) ) ;
V_35 ++ ;
}
F_17 ( V_8 , V_38 , V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_21 ) ;
V_32 = F_13 ( V_8 ) ;
if ( ! V_50 && ( V_32 & V_51 ) == 0 ) {
V_18 = - V_43 ;
goto V_49;
}
}
F_8 ( V_34 [ V_35 ] ,
V_8 -> V_10 . V_11 +
F_19 ( V_8 -> V_10 . V_14 ) ) ;
F_17 ( V_8 , V_38 , V_8 -> V_10 . V_39 ,
& V_8 -> V_10 . V_21 ) ;
V_32 = F_13 ( V_8 ) ;
if ( ( V_32 & V_51 ) != 0 ) {
V_18 = - V_43 ;
goto V_49;
}
F_8 ( V_52 ,
V_8 -> V_10 . V_11 + F_14 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_8 -> V_10 . V_20 ) {
V_47 = F_22 ( * ( ( V_45 * ) ( V_34 + 6 ) ) ) ;
if ( F_17
( V_8 , V_37 | V_38 ,
F_24 ( V_8 , V_47 ) ,
& V_8 -> V_10 . V_40 ) < 0 ) {
V_18 = - V_33 ;
goto V_49;
}
}
return V_46 ;
V_49:
F_15 ( V_8 ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 0 ) ;
return V_18 ;
}
static T_5 F_25 ( int V_20 , void * V_53 )
{
struct V_7 * V_8 = V_53 ;
T_4 V_54 ;
V_54 = F_26 ( V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_54 == 0 )
return V_55 ;
V_8 -> V_10 . V_20 = V_20 ;
F_28 ( V_54 ,
V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ;
return V_56 ;
}
static T_5 F_29 ( int V_57 , void * V_53 )
{
struct V_7 * V_8 = V_53 ;
T_4 V_54 ;
int V_58 ;
V_54 = F_26 ( V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_54 == 0 )
return V_55 ;
if ( V_54 & V_59 )
F_30 ( & V_8 -> V_10 . V_40 ) ;
if ( V_54 & V_60 )
for ( V_58 = 0 ; V_58 < 5 ; V_58 ++ )
if ( F_4 ( V_8 , V_58 ) >= 0 )
break;
if ( V_54 &
( V_60 | V_61 |
V_62 ) )
F_30 ( & V_8 -> V_10 . V_21 ) ;
F_28 ( V_54 ,
V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ;
F_26 ( V_8 -> V_10 . V_11 + F_27 ( V_8 -> V_10 . V_14 ) ) ;
return V_56 ;
}
static int F_31 ( struct V_63 * V_2 , T_6 V_64 ,
T_6 V_46 , unsigned int V_20 )
{
T_4 V_10 , V_65 , V_66 ;
int V_18 , V_58 ;
struct V_7 * V_8 ;
if ( ! ( V_8 = F_32 ( V_2 , & V_67 ) ) )
return - V_68 ;
V_8 -> V_10 . V_11 = F_33 ( V_64 , V_46 ) ;
if ( ! V_8 -> V_10 . V_11 ) {
V_18 = - V_43 ;
goto V_49;
}
V_8 -> V_10 . V_22 = F_34 ( V_69 ) ;
V_8 -> V_10 . V_48 = F_34 ( V_70 ) ;
V_8 -> V_10 . V_39 = F_34 ( V_69 ) ;
V_8 -> V_10 . V_27 = F_34 ( V_69 ) ;
if ( F_9 ( V_8 , 0 ) != 0 ) {
V_18 = - V_68 ;
goto V_49;
}
V_10 = F_26 ( V_8 -> V_10 . V_11 + F_35 ( 0 ) ) ;
F_36 ( V_2 ,
L_5 ,
V_10 >> 16 , F_5 ( V_8 -> V_10 . V_11 + F_37 ( 0 ) ) ) ;
if ( V_50 )
F_36 ( V_2 , L_6 ) ;
V_65 =
F_26 ( V_8 -> V_10 . V_11 +
F_38 ( V_8 -> V_10 . V_14 ) ) ;
F_39 ( V_2 , L_7 ,
V_65 ) ;
if ( V_65 & V_71 )
F_39 ( V_2 , L_8 ) ;
if ( V_65 & V_62 )
F_39 ( V_2 , L_9 ) ;
if ( V_65 & V_72 )
F_39 ( V_2 , L_10 ) ;
if ( V_65 & V_73 )
F_39 ( V_2 , L_11 ) ;
if ( V_65 & V_74 )
F_39 ( V_2 , L_12 ) ;
if ( V_65 & V_75 )
F_39 ( V_2 , L_13 ) ;
if ( V_65 & V_60 )
F_39 ( V_2 , L_14 ) ;
if ( V_65 & V_61 )
F_39 ( V_2 , L_15 ) ;
if ( V_65 & V_59 )
F_39 ( V_2 , L_16 ) ;
F_40 ( & V_8 -> V_10 . V_40 ) ;
F_40 ( & V_8 -> V_10 . V_21 ) ;
V_66 =
F_26 ( V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 . V_14 ) ) ;
V_66 |= V_62
| V_60 | V_59
| V_61 ;
F_28 ( V_66 ,
V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 . V_14 ) ) ;
if ( V_76 )
V_8 -> V_10 . V_20 = V_20 ;
if ( V_76 && ! V_8 -> V_10 . V_20 ) {
V_8 -> V_10 . V_20 =
F_5 ( V_8 -> V_10 . V_11 +
F_42 ( V_8 -> V_10 . V_14 ) ) ;
for ( V_58 = 3 ; V_58 < 16 && V_8 -> V_10 . V_20 == 0 ; V_58 ++ ) {
F_8 ( V_58 , V_8 -> V_10 . V_11 +
F_42 ( V_8 -> V_10 . V_14 ) ) ;
if ( F_43
( V_58 , F_25 , V_77 ,
V_8 -> V_10 . V_78 . V_79 , V_8 ) != 0 ) {
F_36 ( V_8 -> V_2 ,
L_17 ,
V_58 ) ;
continue;
}
F_28 ( F_26
( V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ;
F_28 ( V_66 | V_80 ,
V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 . V_14 ) ) ;
F_44 ( V_8 ) ;
F_28 ( V_66 ,
V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 . V_14 ) ) ;
F_45 ( V_58 , V_8 ) ;
}
}
if ( V_8 -> V_10 . V_20 ) {
F_8 ( V_8 -> V_10 . V_20 ,
V_8 -> V_10 . V_11 +
F_42 ( V_8 -> V_10 . V_14 ) ) ;
if ( F_43
( V_8 -> V_10 . V_20 , F_29 , V_77 ,
V_8 -> V_10 . V_78 . V_79 , V_8 ) != 0 ) {
F_36 ( V_8 -> V_2 ,
L_18 ,
V_8 -> V_10 . V_20 ) ;
V_8 -> V_10 . V_20 = 0 ;
} else {
F_28 ( F_26
( V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_27 ( V_8 -> V_10 . V_14 ) ) ;
F_28 ( V_66 | V_80 ,
V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 . V_14 ) ) ;
}
}
F_46 ( & V_8 -> V_10 . V_81 ) ;
F_47 ( & V_82 ) ;
F_48 ( & V_8 -> V_10 . V_81 , & V_83 ) ;
F_49 ( & V_82 ) ;
F_50 ( V_8 ) ;
F_51 ( V_8 ) ;
return 0 ;
V_49:
if ( V_8 -> V_10 . V_11 )
F_52 ( V_8 -> V_10 . V_11 ) ;
F_53 ( V_8 -> V_2 ) ;
return V_18 ;
}
static int T_7 F_54 ( struct V_1 * V_1 ,
const struct V_84 * V_85 )
{
T_6 V_64 , V_46 ;
unsigned int V_20 = 0 ;
V_64 = F_55 ( V_1 , 0 ) ;
V_46 = F_56 ( V_1 , 0 ) ;
if ( F_57 ( V_1 , 0 ) )
V_20 = F_58 ( V_1 , 0 ) ;
else
V_76 = 0 ;
if ( F_1 ( V_1 ) )
V_50 = 1 ;
return F_31 ( & V_1 -> V_2 , V_64 , V_46 , V_20 ) ;
}
static int F_59 ( struct V_1 * V_2 , T_8 V_86 )
{
return F_60 ( & V_2 -> V_2 , V_86 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_62 ( V_2 ) ;
int V_87 ;
V_87 = F_63 ( & V_2 -> V_2 ) ;
if ( ! V_87 )
F_51 ( V_8 ) ;
return V_87 ;
}
static T_9 void F_64 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_62 ( V_2 ) ;
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
}
static int F_67 ( struct V_88 * V_2 , T_8 V_86 )
{
return F_60 ( & V_2 -> V_2 , V_86 ) ;
}
static int F_68 ( struct V_88 * V_2 )
{
return F_63 ( & V_2 -> V_2 ) ;
}
static int T_10 F_69 ( void )
{
int V_18 ;
#ifdef F_70
if ( ! V_15 )
return F_71 ( & V_89 ) ;
#endif
V_18 = F_72 ( & V_90 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( F_73 ( V_91 = F_74 ( L_19 , - 1 , NULL , 0 ) ) )
return F_75 ( V_91 ) ;
if( ( V_18 = F_31 ( & V_91 -> V_2 , V_92 , V_93 , 0 ) ) != 0 ) {
F_76 ( V_91 ) ;
F_77 ( & V_90 ) ;
}
return V_18 ;
}
static void T_11 F_78 ( void )
{
struct V_94 * V_58 , * V_95 ;
struct V_7 * V_8 ;
F_47 ( & V_82 ) ;
F_79 (i, j, &tis_chips, list) {
V_8 = F_80 ( V_58 ) ;
F_53 ( V_8 -> V_2 ) ;
F_28 ( ~ V_80 &
F_26 ( V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 .
V_14 ) ) ,
V_8 -> V_10 . V_11 +
F_41 ( V_8 -> V_10 . V_14 ) ) ;
F_7 ( V_8 , V_8 -> V_10 . V_14 , 1 ) ;
if ( V_8 -> V_10 . V_20 )
F_45 ( V_8 -> V_10 . V_20 , V_8 ) ;
F_52 ( V_58 -> V_11 ) ;
F_81 ( & V_58 -> V_81 ) ;
}
F_49 ( & V_82 ) ;
#ifdef F_70
if ( ! V_15 ) {
F_82 ( & V_89 ) ;
return;
}
#endif
F_76 ( V_91 ) ;
F_77 ( & V_90 ) ;
}
