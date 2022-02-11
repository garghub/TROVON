static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < V_4 )
V_2 -> V_3 = V_4 ;
if ( V_2 -> V_3 > V_5 )
V_2 -> V_3 = V_5 ;
if ( V_2 -> V_6 < V_4 )
V_2 -> V_6 = V_4 ;
if ( V_2 -> V_6 > V_5 )
V_2 -> V_6 = V_5 ;
#ifdef F_2
F_3 ( L_1 ,
V_2 -> V_7 ,
V_2 -> V_3 , V_2 -> V_6 ) ;
#endif
F_4 ( V_2 -> V_8 , V_2 -> V_3 , V_9 ) ;
F_4 ( V_2 -> V_8 , V_2 -> V_6 , V_10 ) ;
F_4 ( V_2 -> V_8 ,
( V_2 -> V_11 ?
V_12 : V_13 ) ,
V_14 ) ;
}
static void F_5 ( struct V_15 * V_16 )
{
V_16 -> V_17 = V_16 -> V_18 ;
F_6 ( V_16 -> V_8 ,
( unsigned char * ) & V_16 -> V_18 ,
V_19 ) ;
V_16 -> V_20 = V_16 -> V_21 ;
F_6 ( V_16 -> V_8 ,
( unsigned char * ) & V_16 -> V_21 ,
V_22 ) ;
#ifdef F_2
F_3 ( L_2 ,
V_16 -> V_7 ,
( int ) V_16 -> V_21 , ( int ) V_16 -> V_18 ) ;
#endif
}
static void F_7 ( struct V_15 * V_16 )
{
static int V_23 = 0 ;
char * type = L_3 ;
T_1 V_24 = - 1 ;
if ( V_23 != 0 )
return;
if ( V_16 -> V_18 >= V_25 [ V_16 -> V_7 ] . V_26 ||
V_16 -> V_18 < V_25 [ V_16 -> V_7 ] . V_27 ) {
type = L_4 ;
V_24 = V_16 -> V_18 ;
} else if ( V_16 -> V_21 >= V_28 [ V_16 -> V_7 ] . V_26 ||
V_16 -> V_21 < V_28 [ V_16 -> V_7 ] . V_27 ) {
type = L_5 ;
V_24 = V_16 -> V_21 ;
}
F_3 ( V_29 L_6
L_7 ,
V_16 -> V_7 , type , V_24 ) ;
F_3 ( V_29 L_8 ) ;
V_23 = 1 ;
if ( F_8 ( true ) < 0 )
F_3 ( V_29 L_9 ) ;
}
static void F_9 ( struct V_15 * V_16 , unsigned long * V_30 , int V_31 )
{
int V_32 = 0 ;
if ( F_10 ( V_33 , ( * V_30 + V_34 ) ) ) {
if ( V_16 -> V_18 >=
V_25 [ V_16 -> V_7 ] . V_35 ) {
F_3 ( V_36 L_10
L_11 ,
V_16 -> V_7 , ( int ) V_16 -> V_18 ) ;
V_32 = 1 ;
} else if ( V_16 -> V_18 <
V_25 [ V_16 -> V_7 ] . V_37 ) {
F_3 ( V_36 L_10
L_12 ,
V_16 -> V_7 , ( int ) V_16 -> V_18 ) ;
V_32 = 1 ;
}
if ( V_32 )
* V_30 = V_33 ;
} else if ( V_16 -> V_18 >= V_25 [ V_16 -> V_7 ] . V_35 ||
V_16 -> V_18 < V_25 [ V_16 -> V_7 ] . V_37 )
V_32 = 1 ;
if ( V_16 -> V_18 >= V_25 [ V_16 -> V_7 ] . V_26 ||
V_16 -> V_18 < V_25 [ V_16 -> V_7 ] . V_27 ) {
F_7 ( V_16 ) ;
V_32 = 1 ;
}
if ( V_32 ) {
V_16 -> V_38 [ V_39 ] = V_40 ;
} else if ( ( V_31 & ( 8 - 1 ) ) == 0 ) {
T_1 V_41 = V_25 [ V_16 -> V_7 ] . V_35 - 10 ;
T_1 V_42 ;
V_42 = V_41 - 3 ;
if ( V_16 -> V_43 < V_41 ) {
if ( V_16 -> V_43 >= V_42 )
V_16 -> V_38 [ V_39 ] = V_44 ;
else
V_16 -> V_38 [ V_39 ] = V_45 ;
} else {
V_16 -> V_38 [ V_39 ] = V_46 ;
}
} else {
V_16 -> V_38 [ V_39 ] = V_44 ;
}
}
static void F_11 ( struct V_15 * V_16 , unsigned long * V_30 , int V_31 )
{
int V_32 = 0 ;
if ( F_10 ( V_33 , ( * V_30 + V_34 ) ) ) {
if ( V_16 -> V_21 >=
V_28 [ V_16 -> V_7 ] . V_35 ) {
F_3 ( V_36 L_10
L_13 ,
V_16 -> V_7 , ( int ) V_16 -> V_21 ) ;
V_32 = 1 ;
} else if ( V_16 -> V_21 <
V_28 [ V_16 -> V_7 ] . V_37 ) {
F_3 ( V_36 L_10
L_14 ,
V_16 -> V_7 , ( int ) V_16 -> V_21 ) ;
V_32 = 1 ;
}
if ( V_32 )
* V_30 = V_33 ;
} else if ( V_16 -> V_21 >= V_28 [ V_16 -> V_7 ] . V_35 ||
V_16 -> V_21 < V_28 [ V_16 -> V_7 ] . V_37 )
V_32 = 1 ;
if ( V_16 -> V_21 >= V_28 [ V_16 -> V_7 ] . V_26 ||
V_16 -> V_21 < V_28 [ V_16 -> V_7 ] . V_27 ) {
F_7 ( V_16 ) ;
V_32 = 1 ;
}
if ( V_32 ) {
V_16 -> V_38 [ V_47 ] = V_40 ;
} else if ( ( V_31 & ( 8 - 1 ) ) == 0 ) {
T_1 V_48 = V_28 [ V_16 -> V_7 ] . V_35 - 10 ;
T_1 V_49 ;
V_49 = V_48 - 3 ;
if ( V_16 -> V_50 < V_48 ) {
if ( V_16 -> V_50 >= V_49 )
V_16 -> V_38 [ V_47 ] = V_44 ;
else
V_16 -> V_38 [ V_47 ] = V_45 ;
} else {
V_16 -> V_38 [ V_47 ] = V_46 ;
}
} else {
V_16 -> V_38 [ V_47 ] = V_44 ;
}
}
static void F_12 ( struct V_15 * V_16 , unsigned long * V_30 )
{
V_16 -> V_43 = ( T_1 ) ( ( int ) ( ( int ) V_16 -> V_43 + ( int ) V_16 -> V_18 ) / 2 ) ;
V_16 -> V_50 = ( T_1 ) ( ( int ) ( ( int ) V_16 -> V_50 + ( int ) V_16 -> V_21 ) / 2 ) ;
F_9 ( V_16 , V_30 , V_16 -> V_51 ) ;
F_11 ( V_16 , V_30 , V_16 -> V_51 ) ;
V_16 -> V_51 ++ ;
}
static enum V_52 F_13 ( int V_53 )
{
struct V_15 * V_16 ;
enum V_52 V_54 = V_55 ;
F_14 (tp, &all_temps, glob_list) {
if ( V_16 -> V_38 [ V_53 ] == V_40 ) {
V_54 = V_40 ;
break;
}
if ( V_16 -> V_38 [ V_53 ] == V_44 &&
V_54 != V_46 )
V_54 = V_44 ;
else if ( V_16 -> V_38 [ V_53 ] == V_46 )
V_54 = V_46 ;
else if ( V_54 != V_46 &&
V_54 != V_44 &&
V_16 -> V_38 [ V_53 ] == V_45 )
V_54 = V_45 ;
}
if ( V_54 == V_55 )
V_54 = V_44 ;
return V_54 ;
}
static int F_15 ( struct V_1 * V_2 )
{
enum V_52 V_54 = F_13 ( V_39 ) ;
int V_32 ;
if ( V_54 == V_44 )
return 0 ;
V_32 = 1 ;
if ( V_54 == V_40 ) {
if ( V_2 -> V_6 >= V_5 )
V_32 = 0 ;
else
V_2 -> V_6 = V_5 ;
} else {
if ( V_54 == V_46 ) {
if ( V_2 -> V_6 >= V_5 )
V_32 = 0 ;
else
V_2 -> V_6 += 2 ;
} else {
int V_56 = V_2 -> V_6 ;
if ( V_56 <= V_4 ||
V_56 <= ( V_2 -> V_3 - 3 ) )
V_32 = 0 ;
else
V_2 -> V_6 -= 1 ;
}
}
return V_32 ;
}
static int F_16 ( struct V_1 * V_2 )
{
enum V_52 V_54 = F_13 ( V_47 ) ;
int V_32 ;
if ( V_54 == V_44 )
return 0 ;
V_32 = 1 ;
if ( V_54 == V_40 ) {
if ( V_2 -> V_3 >= V_5 )
V_32 = 0 ;
else
V_2 -> V_3 = V_5 ;
} else {
if ( V_54 == V_46 ) {
if ( V_2 -> V_3 >= V_5 )
V_32 = 0 ;
else {
V_2 -> V_3 += 2 ;
if ( V_2 -> V_6 <
( V_2 -> V_3 - 3 ) )
V_2 -> V_6 =
V_2 -> V_3 - 3 ;
}
} else {
if ( V_2 -> V_3 <= V_4 )
V_32 = 0 ;
else
V_2 -> V_3 -= 1 ;
}
}
return V_32 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_15 ( V_2 ) ;
V_57 |= F_16 ( V_2 ) ;
if ( V_57 )
F_1 ( V_2 ) ;
}
static void F_18 ( void )
{
struct V_1 * V_2 ;
F_14 (fp, &all_fans, glob_list) {
V_2 -> V_3 = V_5 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_11 = 1 ;
F_1 ( V_2 ) ;
}
}
static int F_19 ( void * V_58 )
{
F_3 ( V_59 L_15 ) ;
V_60 = V_33 - V_34 ;
for (; ; ) {
struct V_15 * V_16 ;
struct V_1 * V_2 ;
F_20 ( V_61 ) ;
if ( F_21 () )
break;
F_14 (tp, &all_temps, glob_list) {
F_5 ( V_16 ) ;
F_12 ( V_16 , & V_60 ) ;
}
F_14 (fp, &all_fans, glob_list)
F_17 ( V_2 ) ;
}
F_3 ( V_59 L_16 ) ;
F_18 () ;
return 0 ;
}
static void F_22 ( struct V_62 * V_63 , struct V_64 * V_65 ,
int V_66 )
{
struct V_15 * V_16 ;
V_16 = F_23 ( sizeof( * V_16 ) , V_67 ) ;
if ( ! V_16 )
return;
V_16 -> V_8 = F_24 ( V_63 , V_65 ) ;
if ( ! V_16 -> V_8 ) {
F_25 ( V_16 ) ;
return;
}
V_16 -> V_7 = V_66 ;
F_26 ( & V_16 -> V_68 , & V_69 ) ;
F_26 ( & V_16 -> V_70 , & V_63 -> V_71 ) ;
F_4 ( V_16 -> V_8 , 0x00 , V_72 ) ;
F_4 ( V_16 -> V_8 , 0x02 , V_73 ) ;
F_4 ( V_16 -> V_8 , V_25 [ V_16 -> V_7 ] . V_74 ,
V_75 ) ;
F_4 ( V_16 -> V_8 , V_25 [ V_16 -> V_7 ] . V_76 ,
V_77 ) ;
F_4 ( V_16 -> V_8 , V_28 [ V_16 -> V_7 ] . V_74 ,
V_78 ) ;
F_4 ( V_16 -> V_8 , V_28 [ V_16 -> V_7 ] . V_76 ,
V_79 ) ;
F_5 ( V_16 ) ;
V_16 -> V_20 = V_16 -> V_50 = V_16 -> V_21 ;
V_16 -> V_17 = V_16 -> V_43 = V_16 -> V_18 ;
V_16 -> V_38 [ V_39 ] = V_44 ;
V_16 -> V_38 [ V_47 ] = V_44 ;
}
static void F_27 ( struct V_62 * V_63 , struct V_64 * V_65 ,
int V_80 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return;
V_2 -> V_8 = F_24 ( V_63 , V_65 ) ;
if ( ! V_2 -> V_8 ) {
F_25 ( V_2 ) ;
return;
}
V_2 -> V_7 = V_80 ;
F_26 ( & V_2 -> V_68 , & V_81 ) ;
F_26 ( & V_2 -> V_70 , & V_63 -> V_82 ) ;
V_2 -> V_11 = 1 ;
V_2 -> V_3 = ( V_5 - V_4 ) / 2 ;
V_2 -> V_3 += V_4 ;
V_2 -> V_6 = ( V_5 - V_4 ) / 2 ;
V_2 -> V_6 += V_4 ;
F_1 ( V_2 ) ;
}
static void F_28 ( struct V_15 * V_16 )
{
F_29 ( V_16 -> V_8 ) ;
F_25 ( V_16 ) ;
}
static void F_30 ( struct V_62 * V_63 )
{
struct V_15 * V_16 , * V_83 ;
F_31 (tp, tpos, &bp->temps, bp_list) {
F_32 ( & V_16 -> V_70 ) ;
F_32 ( & V_16 -> V_68 ) ;
F_28 ( V_16 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_8 ) ;
F_25 ( V_2 ) ;
}
static void F_34 ( struct V_62 * V_63 )
{
struct V_1 * V_2 , * V_84 ;
F_31 (fp, fpos, &bp->fans, bp_list) {
F_32 ( & V_2 -> V_70 ) ;
F_32 ( & V_2 -> V_68 ) ;
F_33 ( V_2 ) ;
}
}
int F_35 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
int V_85 = 0 ;
int V_86 = 0 ;
int V_87 = 0 ;
while ( ( V_65 = F_36 ( V_63 , V_87 ++ ) ) != NULL ) {
if ( ! strcmp ( V_65 -> V_88 . V_89 -> V_90 , L_17 ) )
F_22 ( V_63 , V_65 , V_85 ++ ) ;
if ( ! strcmp ( V_65 -> V_88 . V_89 -> V_90 , L_18 ) )
F_27 ( V_63 , V_65 , V_86 ++ ) ;
}
if ( V_85 != 0 && V_86 != 0 ) {
V_91 = F_37 ( F_19 , NULL , L_19 ) ;
if ( F_38 ( V_91 ) ) {
int V_92 = F_39 ( V_91 ) ;
V_91 = NULL ;
F_30 ( V_63 ) ;
F_34 ( V_63 ) ;
return V_92 ;
}
}
return 0 ;
}
void F_40 ( struct V_62 * V_63 )
{
if ( V_91 )
F_41 ( V_91 ) ;
F_30 ( V_63 ) ;
F_34 ( V_63 ) ;
}
