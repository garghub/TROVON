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
F_20 ( V_21 -> V_42 . V_43 -> V_44 ) ,
F_21 ( V_21 -> V_42 . V_43 -> V_44 ) ) ;
if ( F_20 ( V_21 -> V_42 . V_43 -> V_44 ) != V_8 )
return - V_45 ;
V_41 = F_21 ( V_21 -> V_42 . V_43 -> V_44 ) ;
V_2 = F_22 ( V_41 / V_46 ) ;
if ( F_9 ( V_2 ) ) {
F_7 ( 3 , L_15 ) ;
return F_13 ( V_2 ) ;
}
V_27 = F_23 ( V_2 ) ;
if ( V_27 == 0 ) {
V_21 -> V_28 = V_2 ;
F_24 ( V_40 , V_21 ) ;
} else
F_25 ( V_2 ) ;
return V_27 ;
}
static int
F_26 ( struct V_40 * V_40 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
F_7 ( 6 , L_16 , F_21 ( V_40 ) ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
if ( ( F_21 ( V_40 ) & 1 ) != 0 ) {
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
F_27 ( V_2 , V_47 , 1 ) ;
} else {
if ( V_2 -> V_29 > 1 ) {
if ( F_27 ( V_2 , V_48 , 1 ) == 0 )
V_2 -> V_29 -- ;
}
}
if ( V_2 -> V_14 . V_15 != NULL ) {
F_10 ( V_2 -> V_14 . V_15 ) ;
V_2 -> V_14 . V_15 = NULL ;
}
F_28 ( V_2 ) ;
V_21 -> V_28 = NULL ;
F_25 ( V_2 ) ;
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 ,
unsigned int V_49 , unsigned long V_22 )
{
int V_27 ;
if ( V_49 == V_50 ) {
struct V_51 V_52 ;
if ( F_30 ( & V_52 , ( char T_3 * ) V_22 , sizeof( V_52 ) ) != 0 )
return - V_33 ;
if ( V_52 . V_53 < 0 )
return - V_18 ;
switch ( V_52 . V_54 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_47 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
default:
;
}
V_27 = F_27 ( V_2 , V_52 . V_54 , V_52 . V_53 ) ;
if ( V_52 . V_54 == V_48 && V_27 == 0 ) {
if ( V_52 . V_53 > V_2 -> V_29 )
V_2 -> V_29 = 0 ;
else
V_2 -> V_29 -= V_52 . V_53 ;
}
return V_27 ;
}
if ( V_49 == V_65 ) {
struct V_66 V_67 ;
V_27 = F_27 ( V_2 , V_68 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
V_67 . V_69 = V_27 ;
if ( F_31 ( ( char T_3 * ) V_22 , & V_67 , sizeof( V_67 ) ) != 0 )
return - V_33 ;
return 0 ;
}
if ( V_49 == V_70 ) {
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_73 = V_74 ;
V_72 . V_75 = 0 ;
V_72 . V_76 = V_2 -> V_77 ;
V_72 . V_78 = 0 ;
V_72 . V_79 = 0 ;
V_72 . V_80 = 0 ;
V_72 . V_78 = V_2 -> V_81 ;
if ( V_2 -> V_82 == V_83 ) {
V_27 = F_27 ( V_2 , V_68 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 0 )
V_72 . V_78 |= F_32 ( ~ 0 ) ;
V_72 . V_69 = V_27 ;
}
if ( F_31 ( ( char T_3 * ) V_22 , & V_72 , sizeof( V_72 ) ) != 0 )
return - V_33 ;
return 0 ;
}
if ( V_2 -> V_30 -> V_84 == NULL )
return - V_18 ;
return V_2 -> V_30 -> V_84 ( V_2 , V_49 , V_22 ) ;
}
static long
F_33 ( struct V_20 * V_21 , unsigned int V_49 , unsigned long V_22 )
{
struct V_1 * V_2 ;
long V_27 ;
F_7 ( 6 , L_17 ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
F_34 ( & V_2 -> V_85 ) ;
V_27 = F_29 ( V_2 , V_49 , V_22 ) ;
F_35 ( & V_2 -> V_85 ) ;
return V_27 ;
}
static long
F_36 ( struct V_20 * V_21 , unsigned int V_49 , unsigned long V_22 )
{
struct V_1 * V_2 = V_21 -> V_28 ;
int V_86 = - V_87 ;
unsigned long V_88 ;
V_88 = ( unsigned long ) F_37 ( V_22 ) ;
if ( V_2 -> V_30 -> V_84 ) {
F_34 ( & V_2 -> V_85 ) ;
V_86 = V_2 -> V_30 -> V_84 ( V_2 , V_49 , V_88 ) ;
F_35 ( & V_2 -> V_85 ) ;
if ( V_86 == - V_18 )
V_86 = - V_87 ;
}
return V_86 ;
}
int
F_38 ( void )
{
T_5 V_7 ;
if ( F_39 ( & V_7 , 0 , 256 , L_18 ) != 0 )
return - 1 ;
V_8 = F_40 ( V_7 ) ;
return 0 ;
}
void
F_41 ( void )
{
F_42 ( F_3 ( V_8 , 0 ) , 256 ) ;
}
