static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 2 ;
V_2 -> V_4 = 20 ;
V_2 -> V_5 = F_2 ( 30 * V_6 ) ;
V_2 -> V_7 = 1000 ;
V_2 -> V_8 = F_3 ( 20 * V_9 ) ;
V_2 -> V_10 = false ;
V_2 -> V_11 = false ;
}
static void F_4 ( struct V_12 * V_13 )
{
V_13 -> V_14 = V_15 ;
V_13 -> V_16 = 0 ;
V_13 -> V_17 = F_3 ( 100 * V_9 ) ;
}
static bool F_5 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
T_1 V_23 ;
T_1 V_24 = V_22 -> V_13 . V_25 ;
T_1 V_26 = F_7 ( F_8 ( V_19 ) ) ;
if ( V_22 -> V_13 . V_17 > 0 )
return false ;
if ( ( V_22 -> V_13 . V_27 < V_22 -> V_2 . V_8 / 2 )
&& ( V_22 -> V_13 . V_25 < V_28 / 5 ) )
return false ;
if ( V_19 -> V_29 . V_30 < 2 * V_26 )
return false ;
if ( V_22 -> V_2 . V_11 && V_20 <= V_26 )
V_24 = ( V_24 / V_26 ) * V_20 ;
else
V_24 = V_22 -> V_13 . V_25 ;
V_23 = F_9 () ;
if ( V_23 < V_24 )
return true ;
return false ;
}
static int F_10 ( struct V_31 * V_32 , struct V_18 * V_19 ,
struct V_31 * * V_33 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
bool V_34 = false ;
if ( F_11 ( F_12 ( V_19 ) >= V_19 -> V_7 ) ) {
V_22 -> V_35 . V_36 ++ ;
goto V_37;
}
if ( ! F_5 ( V_19 , V_32 -> V_38 ) ) {
V_34 = true ;
} else if ( V_22 -> V_2 . V_10 && ( V_22 -> V_13 . V_25 <= V_28 / 10 ) &&
F_13 ( V_32 ) ) {
V_22 -> V_35 . V_39 ++ ;
V_34 = true ;
}
if ( V_34 ) {
V_22 -> V_35 . V_40 ++ ;
if ( F_12 ( V_19 ) > V_22 -> V_35 . V_41 )
V_22 -> V_35 . V_41 = F_12 ( V_19 ) ;
return F_14 ( V_32 , V_19 ) ;
}
V_37:
V_22 -> V_35 . V_42 ++ ;
return F_15 ( V_32 , V_19 , V_33 ) ;
}
static int F_16 ( struct V_18 * V_19 , struct V_43 * V_44 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_43 * V_45 [ V_46 + 1 ] ;
unsigned int V_47 , V_42 = 0 ;
int V_48 ;
if ( ! V_44 )
return - V_49 ;
V_48 = F_17 ( V_45 , V_46 , V_44 , V_50 ) ;
if ( V_48 < 0 )
return V_48 ;
F_18 ( V_19 ) ;
if ( V_45 [ V_51 ] ) {
T_1 V_8 = F_19 ( V_45 [ V_51 ] ) ;
V_22 -> V_2 . V_8 = F_3 ( ( V_52 ) V_8 * V_53 ) ;
}
if ( V_45 [ V_54 ] )
V_22 -> V_2 . V_5 = F_2 ( F_19 ( V_45 [ V_54 ] ) ) ;
if ( V_45 [ V_55 ] ) {
T_1 V_7 = F_19 ( V_45 [ V_55 ] ) ;
V_22 -> V_2 . V_7 = V_7 ;
V_19 -> V_7 = V_7 ;
}
if ( V_45 [ V_56 ] )
V_22 -> V_2 . V_3 = F_19 ( V_45 [ V_56 ] ) ;
if ( V_45 [ V_57 ] )
V_22 -> V_2 . V_4 = F_19 ( V_45 [ V_57 ] ) ;
if ( V_45 [ V_58 ] )
V_22 -> V_2 . V_10 = F_19 ( V_45 [ V_58 ] ) ;
if ( V_45 [ V_59 ] )
V_22 -> V_2 . V_11 = F_19 ( V_45 [ V_59 ] ) ;
V_47 = V_19 -> V_22 . V_47 ;
while ( V_19 -> V_22 . V_47 > V_19 -> V_7 ) {
struct V_31 * V_32 = F_20 ( & V_19 -> V_22 ) ;
V_42 += F_21 ( V_32 ) ;
F_22 ( V_19 , V_32 ) ;
F_23 ( V_32 , V_19 ) ;
}
F_24 ( V_19 , V_47 - V_19 -> V_22 . V_47 , V_42 ) ;
F_25 ( V_19 ) ;
return 0 ;
}
static void F_26 ( struct V_18 * V_19 , struct V_31 * V_32 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
int V_47 = V_19 -> V_29 . V_30 ;
if ( V_47 >= V_60 && V_22 -> V_13 . V_14 == V_15 ) {
V_22 -> V_13 . V_61 = F_27 () ;
V_22 -> V_13 . V_14 = 0 ;
}
if ( V_22 -> V_13 . V_14 != V_15 ) {
V_22 -> V_13 . V_14 += V_32 -> V_38 ;
if ( V_22 -> V_13 . V_14 >= V_60 ) {
T_2 V_62 = F_27 () ;
T_1 V_63 = V_62 - V_22 -> V_13 . V_61 ;
T_1 V_64 = V_22 -> V_13 . V_14 << V_65 ;
if ( V_63 == 0 )
return;
V_64 = V_64 / V_63 ;
if ( V_22 -> V_13 . V_16 == 0 )
V_22 -> V_13 . V_16 = V_64 ;
else
V_22 -> V_13 . V_16 =
( V_22 -> V_13 . V_16 -
( V_22 -> V_13 . V_16 >> 3 ) ) + ( V_64 >> 3 ) ;
if ( V_47 < V_60 )
V_22 -> V_13 . V_14 = V_15 ;
else {
V_22 -> V_13 . V_14 = 0 ;
V_22 -> V_13 . V_61 = F_27 () ;
}
if ( V_22 -> V_13 . V_17 > 0 ) {
if ( V_22 -> V_13 . V_17 > V_63 )
V_22 -> V_13 . V_17 -= V_63 ;
else
V_22 -> V_13 . V_17 = 0 ;
}
}
}
}
static void F_28 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
T_1 V_47 = V_19 -> V_29 . V_30 ;
T_2 V_27 = 0 ;
T_2 V_66 = V_22 -> V_13 . V_27 ;
T_3 V_67 = 0 ;
T_1 V_68 ;
T_1 V_3 , V_4 ;
bool V_69 = true ;
V_22 -> V_13 . V_66 = V_22 -> V_13 . V_27 ;
if ( V_22 -> V_13 . V_16 > 0 )
V_27 = ( V_47 << V_65 ) / V_22 -> V_13 . V_16 ;
else
V_27 = 0 ;
if ( V_27 == 0 && V_47 != 0 )
V_69 = false ;
if ( V_22 -> V_13 . V_25 < V_28 / 100 ) {
V_3 =
( V_22 -> V_2 . V_3 * ( V_28 / V_70 ) ) >> 7 ;
V_4 =
( V_22 -> V_2 . V_4 * ( V_28 / V_70 ) ) >> 7 ;
} else if ( V_22 -> V_13 . V_25 < V_28 / 10 ) {
V_3 =
( V_22 -> V_2 . V_3 * ( V_28 / V_70 ) ) >> 5 ;
V_4 =
( V_22 -> V_2 . V_4 * ( V_28 / V_70 ) ) >> 5 ;
} else {
V_3 =
( V_22 -> V_2 . V_3 * ( V_28 / V_70 ) ) >> 4 ;
V_4 =
( V_22 -> V_2 . V_4 * ( V_28 / V_70 ) ) >> 4 ;
}
V_67 += V_3 * ( ( V_27 - V_22 -> V_2 . V_8 ) ) ;
V_67 += V_4 * ( ( V_27 - V_66 ) ) ;
V_68 = V_22 -> V_13 . V_25 ;
if ( V_67 > ( T_3 ) ( V_28 / ( 100 / 2 ) ) &&
V_22 -> V_13 . V_25 >= V_28 / 10 )
V_67 = ( V_28 / 100 ) * 2 ;
if ( V_27 > ( F_3 ( 250 * V_9 ) ) )
V_67 += V_28 / ( 100 / 2 ) ;
V_22 -> V_13 . V_25 += V_67 ;
if ( V_67 > 0 ) {
if ( V_22 -> V_13 . V_25 < V_68 ) {
V_22 -> V_13 . V_25 = V_28 ;
V_69 = false ;
}
} else {
if ( V_22 -> V_13 . V_25 > V_68 )
V_22 -> V_13 . V_25 = 0 ;
}
if ( ( V_27 == 0 ) && ( V_66 == 0 ) && V_69 )
V_22 -> V_13 . V_25 = ( V_22 -> V_13 . V_25 * 98 ) / 100 ;
V_22 -> V_13 . V_27 = V_27 ;
V_22 -> V_13 . V_71 = V_47 ;
if ( ( V_22 -> V_13 . V_27 < V_22 -> V_2 . V_8 / 2 ) &&
( V_22 -> V_13 . V_66 < V_22 -> V_2 . V_8 / 2 ) &&
( V_22 -> V_13 . V_25 == 0 ) &&
( V_22 -> V_13 . V_16 > 0 ) )
F_4 ( & V_22 -> V_13 ) ;
}
static void F_29 ( unsigned long V_72 )
{
struct V_18 * V_19 = (struct V_18 * ) V_72 ;
struct V_21 * V_22 = F_6 ( V_19 ) ;
T_4 * V_73 = F_30 ( F_31 ( V_19 ) ) ;
F_32 ( V_73 ) ;
F_28 ( V_19 ) ;
if ( V_22 -> V_2 . V_5 )
F_33 ( & V_22 -> V_74 , V_75 + V_22 -> V_2 . V_5 ) ;
F_34 ( V_73 ) ;
}
static int F_35 ( struct V_18 * V_19 , struct V_43 * V_44 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_1 ( & V_22 -> V_2 ) ;
F_4 ( & V_22 -> V_13 ) ;
V_19 -> V_7 = V_22 -> V_2 . V_7 ;
F_36 ( & V_22 -> V_74 , F_29 , ( unsigned long ) V_19 ) ;
if ( V_44 ) {
int V_48 = F_16 ( V_19 , V_44 ) ;
if ( V_48 )
return V_48 ;
}
F_33 ( & V_22 -> V_74 , V_75 + V_76 / 2 ) ;
return 0 ;
}
static int F_37 ( struct V_18 * V_19 , struct V_31 * V_32 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_43 * V_77 ;
V_77 = F_38 ( V_32 , V_78 ) ;
if ( V_77 == NULL )
goto V_79;
if ( F_39 ( V_32 , V_51 ,
( ( T_1 ) F_40 ( V_22 -> V_2 . V_8 ) ) /
V_53 ) ||
F_39 ( V_32 , V_55 , V_19 -> V_7 ) ||
F_39 ( V_32 , V_54 , F_41 ( V_22 -> V_2 . V_5 ) ) ||
F_39 ( V_32 , V_56 , V_22 -> V_2 . V_3 ) ||
F_39 ( V_32 , V_57 , V_22 -> V_2 . V_4 ) ||
F_39 ( V_32 , V_58 , V_22 -> V_2 . V_10 ) ||
F_39 ( V_32 , V_59 , V_22 -> V_2 . V_11 ) )
goto V_79;
return F_42 ( V_32 , V_77 ) ;
V_79:
F_43 ( V_32 , V_77 ) ;
return - 1 ;
}
static int F_44 ( struct V_18 * V_19 , struct V_80 * V_81 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_82 V_83 = {
. V_25 = V_22 -> V_13 . V_25 ,
. V_84 = ( ( T_1 ) F_40 ( V_22 -> V_13 . V_27 ) ) /
V_53 ,
. V_16 = V_22 -> V_13 . V_16 *
( V_70 ) >> V_65 ,
. V_40 = V_22 -> V_35 . V_40 ,
. V_36 = V_22 -> V_35 . V_36 ,
. V_41 = V_22 -> V_35 . V_41 ,
. V_42 = V_22 -> V_35 . V_42 ,
. V_39 = V_22 -> V_35 . V_39 ,
} ;
return F_45 ( V_81 , & V_83 , sizeof( V_83 ) ) ;
}
static struct V_31 * F_46 ( struct V_18 * V_19 )
{
struct V_31 * V_32 ;
V_32 = F_47 ( V_19 , & V_19 -> V_22 ) ;
if ( ! V_32 )
return NULL ;
F_26 ( V_19 , V_32 ) ;
return V_32 ;
}
static void F_48 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_49 ( V_19 ) ;
F_4 ( & V_22 -> V_13 ) ;
}
static void F_50 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
V_22 -> V_2 . V_5 = 0 ;
F_51 ( & V_22 -> V_74 ) ;
}
static int T_5 F_52 ( void )
{
return F_53 ( & V_85 ) ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_85 ) ;
}
