static int F_1 ( struct V_1 * V_2 ,
void * V_3 ,
T_1 V_4 ,
T_2 V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
int V_9 ;
T_3 V_10 ;
V_9 = F_2 ( V_7 -> V_11 ,
F_3 ( V_7 -> V_11 ,
V_7 -> V_12 [ V_5 - 1 ] ) ,
V_3 ,
V_4 ,
& V_10 ,
V_13 * 5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_1 , V_9 ) ;
V_7 -> V_15 = 1 ;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_5 ,
T_2 * V_16 ,
T_4 V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 * V_18 = V_7 -> V_19 ;
if ( V_7 -> V_15 )
return 0 ;
if ( V_5 == V_20 ) {
memset ( V_18 , 0 , V_21 ) ;
memcpy ( V_18 + V_21 , V_16 , V_17 ) ;
} else {
V_18 = ( ( T_2 * ) V_16 - V_21 ) ;
}
return F_1 ( V_2 ,
V_18 ,
V_17 + V_21 ,
V_5 ) ;
}
static int F_6 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
struct V_24 * V_25 ;
struct V_26 * V_5 ;
T_5 V_27 ;
int V_28 , V_29 = 0 ;
V_25 = & ( V_23 -> V_30 [ 0 ] ) ;
for ( V_28 = 0 ; V_28 < V_25 -> V_31 . V_32 ; ++ V_28 ) {
V_5 = & ( V_25 -> V_5 [ V_28 ] . V_31 ) ;
if ( ( ! ( V_7 -> V_33 ) ) &&
( V_5 -> V_34 & V_35 ) &&
( ( V_5 -> V_36 &
V_37 ) ==
V_38 ) ) {
V_27 = V_5 -> V_39 ;
V_7 -> V_40 = V_27 ;
V_7 -> V_33 =
V_5 -> V_34 ;
}
if ( ! V_7 -> V_12 [ V_29 ] &&
! ( V_5 -> V_34 & V_35 ) &&
( ( V_5 -> V_36 & V_37 ) ==
V_38 ) ) {
V_7 -> V_12 [ V_29 ] =
V_5 -> V_34 ;
V_27 = V_5 -> V_39 ;
V_7 -> V_41 [ V_29 ] = V_27 ;
V_29 ++ ;
}
if ( V_29 >= V_42 )
break;
}
if ( ! ( V_7 -> V_33 ) &&
( V_7 -> V_12 [ 0 ] ) )
return - V_43 ;
return 0 ;
}
static int F_7 ( struct V_44 * V_11 ,
T_4 V_45 ,
T_1 * V_46 ,
T_1 V_4 )
{
T_2 * V_3 ;
int V_9 = - V_47 ;
V_3 = F_8 ( 0x04 , V_48 ) ;
if ( ! V_3 )
return V_9 ;
V_9 = F_9 ( V_11 ,
F_10 ( V_11 , 0 ) ,
V_49 ,
V_50 ,
( ( V_45 & 0xffff0000 ) >> 16 ) , ( V_45 & 0xffff ) ,
( void * ) V_3 ,
V_4 ,
V_13 * 5 ) ;
* V_46 = ( V_3 [ 0 ] | ( V_3 [ 1 ] << 8 ) ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_2 ,
V_51 , V_9 ) ;
}
F_11 ( V_3 ) ;
return V_9 ;
}
static int F_12 ( struct V_44 * V_11 ,
T_4 V_45 ,
T_1 V_46 ,
T_1 V_4 )
{
T_2 * V_52 ;
int V_9 = - V_47 ;
V_52 = F_8 ( 0x04 , V_48 ) ;
if ( ! V_52 )
return V_9 ;
V_52 [ 0 ] = ( V_46 & 0x00ff ) ;
V_52 [ 1 ] = ( V_46 & 0xff00 ) >> 8 ;
V_52 [ 2 ] = 0x0 ;
V_52 [ 3 ] = 0x0 ;
V_9 = F_9 ( V_11 ,
F_13 ( V_11 , 0 ) ,
V_53 ,
V_50 ,
( ( V_45 & 0xffff0000 ) >> 16 ) ,
( V_45 & 0xffff ) ,
( void * ) V_52 ,
V_4 ,
V_13 * 5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_3 ,
V_51 , V_9 ) ;
}
F_11 ( V_52 ) ;
return V_9 ;
}
static void F_14 ( struct V_54 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_55 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
if ( V_54 -> V_9 )
return;
F_15 ( & V_7 -> V_56 . V_57 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
struct V_54 * V_54 = V_7 -> V_58 [ 0 ] ;
int V_9 ;
F_17 ( V_54 ,
V_7 -> V_11 ,
F_18 ( V_7 -> V_11 ,
V_7 -> V_33 ) ,
V_54 -> V_59 ,
3000 ,
F_14 ,
V_2 ) ;
V_9 = F_19 ( V_54 , V_48 ) ;
if ( V_9 )
F_4 ( V_14 , L_4 , V_51 ) ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 ,
T_4 V_60 ,
T_2 * V_16 ,
T_4 V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 * V_3 ;
T_2 V_10 ;
int V_9 = 0 ;
V_3 = F_21 ( 4096 , V_48 ) ;
if ( ! V_3 )
return - V_47 ;
while ( V_17 ) {
V_10 = ( T_2 ) ( F_22 ( T_4 , V_17 , 4096 ) ) ;
memcpy ( V_3 , V_16 , V_10 ) ;
V_9 = F_9 ( V_7 -> V_11 ,
F_13 ( V_7 -> V_11 , 0 ) ,
V_53 ,
V_50 ,
( ( V_60 & 0xffff0000 ) >> 16 ) ,
( V_60 & 0xffff ) ,
( void * ) V_3 ,
V_10 ,
V_13 * 5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_5 ,
V_9 ) ;
} else {
V_17 -= V_10 ;
V_16 += V_10 ;
V_60 += V_10 ;
}
}
F_11 ( V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_2 * V_61 ,
T_4 V_4 )
{
T_4 V_62 = ( ( V_61 [ 1 ] >> 4 ) & 0xf ) ;
T_2 V_5 ;
V_5 = ( ( V_62 == V_63 ) ? V_20 : V_64 ) ;
return F_5 ( V_2 ,
V_5 ,
( T_2 * ) V_61 ,
V_4 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
F_25 ( & V_7 -> V_56 ) ;
F_11 ( V_2 -> V_65 -> V_66 ) ;
F_11 ( V_7 -> V_19 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_22 * V_67 )
{
struct V_6 * V_8 ;
struct V_68 * V_69 = V_2 -> V_65 ;
int V_9 ;
V_8 = F_21 ( sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_47 ;
V_2 -> V_8 = V_8 ;
V_8 -> V_11 = F_27 ( V_67 ) ;
if ( F_6 ( V_67 , V_2 ) )
return - V_43 ;
V_2 -> V_70 = & V_67 -> V_7 ;
F_28 ( V_67 , V_2 ) ;
V_69 -> V_66 = F_8 ( 2048 , V_48 ) ;
if ( ! V_69 -> V_66 ) {
F_4 ( V_14 , L_6 ,
V_51 ) ;
return - V_47 ;
}
V_8 -> V_19 = F_8 ( 2048 , V_71 ) ;
V_8 -> V_58 [ 0 ] = F_29 ( 0 , V_48 ) ;
V_8 -> V_58 [ 0 ] -> V_59 = V_2 -> V_65 -> V_66 ;
V_8 -> V_72 = 252 ;
V_2 -> V_73 = F_16 ;
V_2 -> V_74 = F_23 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 ;
F_30 ( & V_8 -> V_56 . V_57 ) ;
V_9 = F_31 ( V_69 , & V_8 -> V_56 ,
V_79 , L_7 ) ;
if ( V_9 ) {
F_4 ( V_14 , L_8 , V_51 ) ;
goto V_80;
}
#ifdef F_32
V_2 -> V_81 = ( V_82 - 1 ) ;
#endif
F_4 ( V_83 , L_9 , V_51 ) ;
return 0 ;
V_80:
F_11 ( V_8 -> V_19 ) ;
F_11 ( V_69 -> V_66 ) ;
return V_9 ;
}
static int F_33 ( struct V_22 * V_67 ,
const struct V_84 * V_85 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_1 V_86 ;
F_4 ( V_83 , L_10 , V_51 ) ;
V_2 = F_34 () ;
if ( ! V_2 ) {
F_4 ( V_14 , L_11 ,
V_51 ) ;
return 1 ;
}
if ( F_26 ( V_2 , V_67 ) ) {
F_4 ( V_14 , L_12 ,
V_51 ) ;
goto V_87;
}
F_4 ( V_14 , L_13 , V_51 ) ;
V_7 = (struct V_6 * ) V_2 -> V_8 ;
if ( F_7 ( V_7 -> V_11 , V_88 , & V_86 , 2 ) < 0 )
goto V_89;
else
V_86 &= 1 ;
if ( ! V_86 ) {
if ( F_35 ( V_2 -> V_65 ) ) {
F_4 ( V_14 , L_14 ,
V_51 ) ;
goto V_89;
}
if ( F_12 ( V_7 -> V_11 ,
V_90 ,
V_91 , 1 ) < 0 )
goto V_89;
F_4 ( V_83 , L_15 , V_51 ) ;
}
if ( F_16 ( V_2 ) )
goto V_89;
return 0 ;
V_89:
F_24 ( V_2 ) ;
V_87:
F_36 ( V_2 ) ;
F_4 ( V_14 , L_16 , V_51 ) ;
return 1 ;
}
static void F_37 ( struct V_22 * V_67 )
{
struct V_1 * V_2 = F_38 ( V_67 ) ;
if ( ! V_2 )
return;
F_39 ( V_2 ) ;
F_24 ( V_2 ) ;
F_36 ( V_2 ) ;
F_4 ( V_92 , L_17 , V_51 ) ;
}
static int F_40 ( struct V_22 * V_93 , T_6 V_94 )
{
return - V_95 ;
}
static int F_41 ( struct V_22 * V_93 )
{
return - V_95 ;
}
static int F_42 ( void )
{
F_43 ( & V_96 ) ;
F_4 ( V_83 , L_18 , V_51 ) ;
return 0 ;
}
static void F_44 ( void )
{
F_45 ( & V_96 ) ;
F_4 ( V_92 , L_19 , V_51 ) ;
}
