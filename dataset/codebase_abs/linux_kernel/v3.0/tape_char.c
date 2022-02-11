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
#ifdef F_13
V_2 -> V_30 . V_31 = 1 ;
#endif
F_7 ( 6 , L_8 , V_11 ) ;
V_26 = V_2 -> V_32 -> V_33 ( V_2 , V_11 ) ;
if ( F_9 ( V_26 ) )
return F_14 ( V_26 ) ;
V_27 = F_15 ( V_2 , V_26 ) ;
if ( V_27 == 0 ) {
V_27 = V_11 - V_26 -> V_34 ;
F_7 ( 6 , L_9 , V_27 ) ;
if ( F_16 ( V_2 -> V_14 . V_15 ,
V_22 , V_27 ) != 0 )
V_27 = - V_35 ;
}
F_17 ( V_26 ) ;
return V_27 ;
}
static T_2
F_18 ( struct V_20 * V_21 , const char T_3 * V_22 , T_1 V_23 , T_4 * V_24 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
T_1 V_11 ;
T_1 V_36 ;
int V_37 ;
int V_38 , V_27 ;
F_7 ( 6 , L_10 ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
if ( V_2 -> V_14 . V_11 != 0 ) {
if ( V_23 < V_2 -> V_14 . V_11 ) {
F_7 ( 3 , L_11
L_7 ) ;
return - V_18 ;
}
V_11 = V_2 -> V_14 . V_11 ;
V_37 = V_23 / V_11 ;
} else {
V_11 = V_23 ;
V_37 = 1 ;
}
V_27 = F_6 ( V_2 , V_11 ) ;
if ( V_27 )
return V_27 ;
#ifdef F_13
V_2 -> V_30 . V_31 = 1 ;
#endif
F_7 ( 6 , L_8 , V_11 ) ;
F_7 ( 6 , L_12 , V_37 ) ;
V_26 = V_2 -> V_32 -> V_39 ( V_2 , V_11 ) ;
if ( F_9 ( V_26 ) )
return F_14 ( V_26 ) ;
V_27 = 0 ;
V_36 = 0 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
if ( F_19 ( V_2 -> V_14 . V_15 ,
V_22 , V_11 ) ) {
V_27 = - V_35 ;
break;
}
V_27 = F_15 ( V_2 , V_26 ) ;
if ( V_27 )
break;
F_7 ( 6 , L_13 ,
V_11 - V_26 -> V_34 ) ;
V_36 += V_11 - V_26 -> V_34 ;
if ( V_26 -> V_34 != 0 )
break;
V_22 += V_11 ;
}
F_17 ( V_26 ) ;
if ( V_27 == - V_40 ) {
if ( V_2 -> V_32 -> V_41 )
V_2 -> V_32 -> V_41 ( V_2 ) ;
if ( V_36 > 0 )
V_27 = 0 ;
}
if ( ! V_27 )
V_2 -> V_29 = 2 ;
return V_27 ? V_27 : V_36 ;
}
static int
F_20 ( struct V_42 * V_42 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
int V_43 , V_27 ;
F_7 ( 6 , L_14 ,
F_21 ( V_21 -> V_44 . V_45 -> V_46 ) ,
F_22 ( V_21 -> V_44 . V_45 -> V_46 ) ) ;
if ( F_21 ( V_21 -> V_44 . V_45 -> V_46 ) != V_8 )
return - V_47 ;
V_43 = F_22 ( V_21 -> V_44 . V_45 -> V_46 ) ;
V_2 = F_23 ( V_43 / V_48 ) ;
if ( F_9 ( V_2 ) ) {
F_7 ( 3 , L_15 ) ;
return F_14 ( V_2 ) ;
}
V_27 = F_24 ( V_2 ) ;
if ( V_27 == 0 ) {
V_21 -> V_28 = V_2 ;
F_25 ( V_42 , V_21 ) ;
} else
F_26 ( V_2 ) ;
return V_27 ;
}
static int
F_27 ( struct V_42 * V_42 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
F_7 ( 6 , L_16 , F_22 ( V_42 ) ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
if ( ( F_22 ( V_42 ) & 1 ) != 0 ) {
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
F_28 ( V_2 , V_49 , 1 ) ;
} else {
if ( V_2 -> V_29 > 1 ) {
if ( F_28 ( V_2 , V_50 , 1 ) == 0 )
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
unsigned int V_51 , unsigned long V_22 )
{
int V_27 ;
if ( V_51 == V_52 ) {
struct V_53 V_54 ;
if ( F_31 ( & V_54 , ( char T_3 * ) V_22 , sizeof( V_54 ) ) != 0 )
return - V_35 ;
if ( V_54 . V_55 < 0 )
return - V_18 ;
switch ( V_54 . V_56 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_49 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
#ifdef F_13
V_2 -> V_30 . V_31 = 1 ;
#endif
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
default:
;
}
V_27 = F_28 ( V_2 , V_54 . V_56 , V_54 . V_55 ) ;
if ( V_54 . V_56 == V_50 && V_27 == 0 ) {
if ( V_54 . V_55 > V_2 -> V_29 )
V_2 -> V_29 = 0 ;
else
V_2 -> V_29 -= V_54 . V_55 ;
}
return V_27 ;
}
if ( V_51 == V_67 ) {
struct V_68 V_69 ;
V_27 = F_28 ( V_2 , V_70 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
V_69 . V_71 = V_27 ;
if ( F_32 ( ( char T_3 * ) V_22 , & V_69 , sizeof( V_69 ) ) != 0 )
return - V_35 ;
return 0 ;
}
if ( V_51 == V_72 ) {
struct V_73 V_74 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_75 = V_76 ;
V_74 . V_77 = 0 ;
V_74 . V_78 = V_2 -> V_79 ;
V_74 . V_80 = 0 ;
V_74 . V_81 = 0 ;
V_74 . V_82 = 0 ;
V_74 . V_80 = V_2 -> V_83 ;
if ( V_2 -> V_84 == V_85 ) {
V_27 = F_28 ( V_2 , V_70 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 0 )
V_74 . V_80 |= F_33 ( ~ 0 ) ;
V_74 . V_71 = V_27 ;
}
if ( F_32 ( ( char T_3 * ) V_22 , & V_74 , sizeof( V_74 ) ) != 0 )
return - V_35 ;
return 0 ;
}
if ( V_2 -> V_32 -> V_86 == NULL )
return - V_18 ;
return V_2 -> V_32 -> V_86 ( V_2 , V_51 , V_22 ) ;
}
static long
F_34 ( struct V_20 * V_21 , unsigned int V_51 , unsigned long V_22 )
{
struct V_1 * V_2 ;
long V_27 ;
F_7 ( 6 , L_17 ) ;
V_2 = (struct V_1 * ) V_21 -> V_28 ;
F_35 ( & V_2 -> V_87 ) ;
V_27 = F_30 ( V_2 , V_51 , V_22 ) ;
F_36 ( & V_2 -> V_87 ) ;
return V_27 ;
}
static long
F_37 ( struct V_20 * V_21 , unsigned int V_51 , unsigned long V_22 )
{
struct V_1 * V_2 = V_21 -> V_28 ;
int V_88 = - V_89 ;
unsigned long V_90 ;
V_90 = ( unsigned long ) F_38 ( V_22 ) ;
if ( V_2 -> V_32 -> V_86 ) {
F_35 ( & V_2 -> V_87 ) ;
V_88 = V_2 -> V_32 -> V_86 ( V_2 , V_51 , V_90 ) ;
F_36 ( & V_2 -> V_87 ) ;
if ( V_88 == - V_18 )
V_88 = - V_89 ;
}
return V_88 ;
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
