static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
if ( ( V_3 + 2 ) >= V_2 -> V_5 ) {
V_4 = ( T_1 ) V_2 -> V_6 -> V_7 ( V_2 ) ;
if ( V_2 -> V_8 < V_4 )
V_2 -> V_5 = V_4 - V_2 -> V_8 ;
else
V_2 -> V_5 = V_9 -
( V_2 -> V_8 - V_4 ) ;
}
if ( ( V_3 + 2 ) < V_2 -> V_5 )
return 1 ;
else
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == ( V_9 - 1 ) ) {
V_2 -> V_8 = 0 ;
V_2 -> V_10 = V_2 -> V_11 ;
} else {
V_2 -> V_8 ++ ;
V_2 -> V_10 ++ ;
}
}
static int F_3 ( struct V_1 * V_2 ,
struct V_12 * * V_12 )
{
T_1 V_3 = 1 ;
if ( F_1 ( V_2 , V_3 ) ) {
* V_12 = V_2 -> V_10 ;
memset ( * V_12 , 0 , sizeof( * * V_12 ) ) ;
F_2 ( V_2 ) ;
V_2 -> V_5 -= V_3 ;
return V_13 ;
}
return V_14 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_15 , int V_16 , T_1 V_17 )
{
struct V_18 * V_19 ;
unsigned long V_20 = 0 ;
T_2 V_21 = V_13 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
if ( F_3 ( V_2 , (struct V_12 * * ) & V_19 ) !=
V_13 ) {
V_21 = V_14 ;
goto V_23;
}
V_19 -> V_24 . V_25 = V_26 ;
V_19 -> V_24 . V_27 = 1 ;
V_19 -> V_28 = F_6 ( V_15 -> V_29 ) ;
V_19 -> V_30 = F_6 ( V_17 ) ;
F_7 ( V_16 , & V_19 -> V_16 ) ;
F_8 () ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
V_23:
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_21 ;
}
static struct V_32 *
F_10 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_2 -> V_10 ;
F_2 ( V_2 ) ;
V_33 -> V_24 . V_25 = V_34 ;
V_33 -> V_24 . V_27 = 1 ;
V_33 -> V_24 . V_35 = ( T_2 ) F_6 ( V_2 -> V_8 ) ;
return V_33 ;
}
static T_1 F_11 ( T_1 V_36 )
{
T_1 V_37 ;
V_37 = 1 ;
if ( V_36 > V_38 ) {
V_37 += ( V_36 - V_38 ) / V_39 ;
if ( ( V_36 - V_38 ) % V_39 )
V_37 ++ ;
}
return V_37 ;
}
static void F_12 ( struct V_40 * V_40 ,
struct V_41 * V_42 ,
T_1 V_43 )
{
struct V_1 * V_2 ;
T_1 V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 ;
V_48 = V_40 -> V_48 ;
V_2 = V_40 -> V_2 ;
if ( ! F_13 ( V_48 ) || V_48 -> V_52 == V_53 ) {
V_42 -> V_54 = F_14 ( 0 ) ;
return;
}
V_44 = V_38 ;
V_46 = (struct V_45 * ) & ( V_42 -> V_55 [ 0 ] ) ;
F_15 (cmd, sg, tot_dsds, i) {
T_3 V_56 ;
if ( V_44 == 0 ) {
struct V_32 * V_33 ;
V_33 = F_10 ( V_2 ) ;
V_46 =
(struct V_45 * )
& V_33 -> V_55 [ 0 ] ;
V_44 = V_39 ;
}
V_56 = F_16 ( V_50 ) ;
V_46 -> V_57 . V_58 = F_17 ( F_18 ( V_56 ) ) ;
V_46 -> V_57 . V_59 = F_17 ( F_19 ( V_56 ) ) ;
V_46 -> V_60 = F_17 ( F_20 ( V_50 ) ) ;
V_44 -- ;
V_46 ++ ;
}
}
void F_21 ( struct V_1 * V_2 )
{
T_4 V_61 = 0 ;
V_61 = 0x14 | ( V_2 -> V_62 << 5 ) ;
V_61 = V_61 | ( 0 << 8 ) | ( V_2 -> V_8 << 16 ) ;
F_22 ( V_2 , V_2 -> V_63 , V_2 -> V_8 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_64 , & V_2 -> V_65 -> V_66 ) ;
F_25 ( & V_2 -> V_65 -> V_66 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_8 , & V_2 -> V_67 -> V_68 ) ;
F_25 ( & V_2 -> V_67 -> V_68 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_64 , & V_2 -> V_67 -> V_66 ) ;
F_25 ( & V_2 -> V_67 -> V_66 ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
struct V_47 * V_48 = V_40 -> V_48 ;
struct V_15 * V_15 ;
struct V_41 * V_42 ;
int V_69 ;
T_1 V_43 ;
T_1 V_3 ;
unsigned long V_20 ;
T_4 V_70 ;
char V_71 [ 2 ] ;
V_15 = V_40 -> V_72 ;
V_43 = 0 ;
F_5 ( & V_2 -> V_22 , V_20 ) ;
V_70 = ( T_4 ) V_48 -> V_73 -> V_71 ;
if ( ! F_29 ( V_74 , & V_2 -> V_20 ) ) {
F_30 ( F_31 ( L_1
L_2 ,
V_2 -> V_75 , V_76 ) ) ;
goto V_77;
}
V_69 = F_32 ( V_48 ) ;
if ( V_69 < 0 )
goto V_77;
V_43 = V_69 ;
V_3 = F_11 ( V_43 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
goto V_77;
if ( ( V_2 -> V_78 + V_3 ) >= V_9 )
goto V_77;
V_42 = (struct V_41 * ) V_2 -> V_10 ;
memset ( V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 -> V_24 . V_25 = V_79 ;
V_42 -> V_80 = F_17 ( V_70 ) ;
V_42 -> V_28 = F_6 ( V_15 -> V_29 ) ;
V_42 -> V_81 = F_6 ( V_15 -> V_81 ) ;
F_7 ( V_48 -> V_82 -> V_16 , & V_42 -> V_16 ) ;
V_42 -> V_83 = F_17 ( V_15 -> V_84 ) ;
V_42 -> V_54 = F_17 ( F_13 ( V_48 ) ) ;
memcpy ( V_42 -> V_85 , V_48 -> V_86 , V_48 -> V_87 ) ;
V_42 -> V_88 = F_6 ( V_43 ) ;
V_42 -> V_24 . V_27 = V_3 ;
V_42 -> V_89 = V_90 ;
if ( F_13 ( V_48 ) ) {
if ( V_48 -> V_52 == V_91 )
V_42 -> V_89 = V_92 ;
else if ( V_48 -> V_52 == V_93 )
V_42 -> V_89 = V_94 ;
V_2 -> V_95 += F_13 ( V_48 ) ;
if ( V_2 -> V_95 & ~ 0xFFFFF ) {
V_2 -> V_96 += V_2 -> V_95 >> 20 ;
V_2 -> V_95 &= 0xFFFFF ;
}
}
V_42 -> V_89 |= V_97 ;
if ( F_33 ( V_48 , V_71 ) )
switch ( V_71 [ 0 ] ) {
case V_98 :
V_42 -> V_89 |= V_99 ;
break;
case V_100 :
V_42 -> V_89 |= V_101 ;
break;
}
F_2 ( V_2 ) ;
F_12 ( V_40 , V_42 , V_43 ) ;
F_8 () ;
V_40 -> V_48 -> V_102 = ( unsigned char * ) ( unsigned long ) V_70 ;
V_40 -> V_103 = V_104 ;
V_40 -> V_20 |= V_105 ;
V_2 -> V_78 += V_3 ;
V_40 -> V_78 = V_3 ;
V_2 -> V_5 -= V_3 ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_13 ;
V_77:
if ( V_43 )
F_34 ( V_48 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_14 ;
}
