int
F_1 ( struct V_1 * V_2 )
{
char V_3 [ 20 ] ;
sprintf ( V_3 , L_1 , V_2 -> V_4 / 2 ) ;
V_2 -> V_5 = F_2 (
& V_2 -> V_6 -> V_7 ,
F_3 ( V_8 , V_2 -> V_4 ) ,
& V_9 ,
V_3 ,
L_2
) ;
V_3 [ 0 ] = 'r' ;
V_2 -> V_10 = F_2 (
& V_2 -> V_6 -> V_7 ,
F_3 ( V_8 , V_2 -> V_4 + 1 ) ,
& V_9 ,
V_3 ,
L_3
) ;
return 0 ;
}
void
F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_6 -> V_7 , V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
F_5 ( & V_2 -> V_6 -> V_7 , V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_12 * V_13 ;
if ( V_2 -> V_14 . V_15 != NULL &&
V_2 -> V_14 . V_15 -> V_16 == V_11 )
return 0 ;
if ( V_11 > V_17 ) {
F_7 ( 3 , L_4 ,
V_11 , V_17 ) ;
return - V_18 ;
}
V_13 = F_8 ( V_11 , 0 ) ;
if ( F_9 ( V_13 ) )
return - V_19 ;
if ( V_2 -> V_14 . V_15 != NULL )
F_10 ( V_2 -> V_14 . V_15 ) ;
V_2 -> V_14 . V_15 = V_13 ;
return 0 ;
}
static T_2
F_11 ( struct V_20 * V_21 , char T_3 * V_22 , T_1 V_23 , T_4 * V_24 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
T_1 V_11 ;
int V_27 ;
F_7 ( 6 , L_5 ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
if( V_2 -> V_29 ) {
return F_12 ( V_2 ) ;
}
if ( V_2 -> V_14 . V_11 != 0 ) {
if ( V_23 < V_2 -> V_14 . V_11 ) {
F_7 ( 3 , L_6
L_7 ) ;
return - V_18 ;
}
V_11 = V_2 -> V_14 . V_11 ;
} else {
V_11 = V_23 ;
}
V_27 = F_6 ( V_2 , V_11 ) ;
if ( V_27 )
return V_27 ;
F_7 ( 6 , L_8 , V_11 ) ;
V_26 = V_2 -> V_30 -> V_31 ( V_2 , V_11 ) ;
if ( F_9 ( V_26 ) )
return F_13 ( V_26 ) ;
V_27 = F_14 ( V_2 , V_26 ) ;
if ( V_27 == 0 ) {
V_27 = V_11 - V_26 -> V_32 ;
F_7 ( 6 , L_9 , V_27 ) ;
if ( F_15 ( V_2 -> V_14 . V_15 ,
V_22 , V_27 ) != 0 )
V_27 = - V_33 ;
}
F_16 ( V_26 ) ;
return V_27 ;
}
static T_2
F_17 ( struct V_20 * V_21 , const char T_3 * V_22 , T_1 V_23 , T_4 * V_24 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
T_1 V_11 ;
T_1 V_34 ;
int V_35 ;
int V_36 , V_27 ;
F_7 ( 6 , L_10 ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
if ( V_2 -> V_14 . V_11 != 0 ) {
if ( V_23 < V_2 -> V_14 . V_11 ) {
F_7 ( 3 , L_11
L_7 ) ;
return - V_18 ;
}
V_11 = V_2 -> V_14 . V_11 ;
V_35 = V_23 / V_11 ;
} else {
V_11 = V_23 ;
V_35 = 1 ;
}
V_27 = F_6 ( V_2 , V_11 ) ;
if ( V_27 )
return V_27 ;
F_7 ( 6 , L_8 , V_11 ) ;
F_7 ( 6 , L_12 , V_35 ) ;
V_26 = V_2 -> V_30 -> V_37 ( V_2 , V_11 ) ;
if ( F_9 ( V_26 ) )
return F_13 ( V_26 ) ;
V_27 = 0 ;
V_34 = 0 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
if ( F_18 ( V_2 -> V_14 . V_15 ,
V_22 , V_11 ) ) {
V_27 = - V_33 ;
break;
}
V_27 = F_14 ( V_2 , V_26 ) ;
if ( V_27 )
break;
F_7 ( 6 , L_13 ,
V_11 - V_26 -> V_32 ) ;
V_34 += V_11 - V_26 -> V_32 ;
if ( V_26 -> V_32 != 0 )
break;
V_22 += V_11 ;
}
F_16 ( V_26 ) ;
if ( V_27 == - V_38 ) {
if ( V_2 -> V_30 -> V_39 )
V_2 -> V_30 -> V_39 ( V_2 ) ;
if ( V_34 > 0 )
V_27 = 0 ;
}
if ( ! V_27 )
V_2 -> V_29 = 2 ;
return V_27 ? V_27 : V_34 ;
}
static int
F_19 ( struct V_40 * V_40 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
int V_41 , V_27 ;
F_7 ( 6 , L_14 ,
F_20 ( F_21 ( V_21 ) ) ,
F_22 ( F_21 ( V_21 ) ) ) ;
if ( F_20 ( F_21 ( V_21 ) ) != V_8 )
return - V_42 ;
V_41 = F_22 ( F_21 ( V_21 ) ) ;
V_2 = F_23 ( V_41 / V_43 ) ;
if ( F_9 ( V_2 ) ) {
F_7 ( 3 , L_15 ) ;
return F_13 ( V_2 ) ;
}
V_27 = F_24 ( V_2 ) ;
if ( V_27 == 0 ) {
V_21 -> V_28 = V_2 ;
F_25 ( V_40 , V_21 ) ;
} else
F_26 ( V_2 ) ;
return V_27 ;
}
static int
F_27 ( struct V_40 * V_40 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
F_7 ( 6 , L_16 , F_22 ( V_40 ) ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
if ( ( F_22 ( V_40 ) & 1 ) != 0 ) {
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
F_28 ( V_2 , V_44 , 1 ) ;
} else {
if ( V_2 -> V_29 > 1 ) {
if ( F_28 ( V_2 , V_45 , 1 ) == 0 )
V_2 -> V_29 -- ;
}
}
if ( V_2 -> V_14 . V_15 != NULL ) {
F_10 ( V_2 -> V_14 . V_15 ) ;
V_2 -> V_14 . V_15 = NULL ;
}
F_29 ( V_2 ) ;
V_21 -> V_28 = NULL ;
F_26 ( V_2 ) ;
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 ,
unsigned int V_46 , unsigned long V_22 )
{
int V_27 ;
if ( V_46 == V_47 ) {
struct V_48 V_49 ;
if ( F_31 ( & V_49 , ( char T_3 * ) V_22 , sizeof( V_49 ) ) != 0 )
return - V_33 ;
if ( V_49 . V_50 < 0 )
return - V_18 ;
switch ( V_49 . V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_44 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
default:
;
}
V_27 = F_28 ( V_2 , V_49 . V_51 , V_49 . V_50 ) ;
if ( V_49 . V_51 == V_45 && V_27 == 0 ) {
if ( V_49 . V_50 > V_2 -> V_29 )
V_2 -> V_29 = 0 ;
else
V_2 -> V_29 -= V_49 . V_50 ;
}
return V_27 ;
}
if ( V_46 == V_62 ) {
struct V_63 V_64 ;
V_27 = F_28 ( V_2 , V_65 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
V_64 . V_66 = V_27 ;
if ( F_32 ( ( char T_3 * ) V_22 , & V_64 , sizeof( V_64 ) ) != 0 )
return - V_33 ;
return 0 ;
}
if ( V_46 == V_67 ) {
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 = V_71 ;
V_69 . V_72 = 0 ;
V_69 . V_73 =
( ( V_2 -> V_14 . V_11 << V_74 )
& V_75 ) ;
V_69 . V_76 = 0 ;
V_69 . V_77 = 0 ;
V_69 . V_78 = 0 ;
V_69 . V_76 = V_2 -> V_79 ;
if ( V_2 -> V_80 == V_81 ) {
V_27 = F_28 ( V_2 , V_65 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 0 )
V_69 . V_76 |= F_33 ( ~ 0 ) ;
V_69 . V_66 = V_27 ;
}
if ( F_32 ( ( char T_3 * ) V_22 , & V_69 , sizeof( V_69 ) ) != 0 )
return - V_33 ;
return 0 ;
}
if ( V_2 -> V_30 -> V_82 == NULL )
return - V_18 ;
return V_2 -> V_30 -> V_82 ( V_2 , V_46 , V_22 ) ;
}
static long
F_34 ( struct V_20 * V_21 , unsigned int V_46 , unsigned long V_22 )
{
struct V_1 * V_2 ;
long V_27 ;
F_7 ( 6 , L_17 ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
F_35 ( & V_2 -> V_83 ) ;
V_27 = F_30 ( V_2 , V_46 , V_22 ) ;
F_36 ( & V_2 -> V_83 ) ;
return V_27 ;
}
static long
F_37 ( struct V_20 * V_21 , unsigned int V_46 , unsigned long V_22 )
{
struct V_1 * V_2 = V_21 -> V_28 ;
int V_84 = - V_85 ;
unsigned long V_86 ;
V_86 = ( unsigned long ) F_38 ( V_22 ) ;
if ( V_2 -> V_30 -> V_82 ) {
F_35 ( & V_2 -> V_83 ) ;
V_84 = V_2 -> V_30 -> V_82 ( V_2 , V_46 , V_86 ) ;
F_36 ( & V_2 -> V_83 ) ;
if ( V_84 == - V_18 )
V_84 = - V_85 ;
}
return V_84 ;
}
int
F_39 ( void )
{
T_5 V_7 ;
if ( F_40 ( & V_7 , 0 , 256 , L_18 ) != 0 )
return - 1 ;
V_8 = F_41 ( V_7 ) ;
return 0 ;
}
void
F_42 ( void )
{
F_43 ( F_3 ( V_8 , 0 ) , 256 ) ;
}
