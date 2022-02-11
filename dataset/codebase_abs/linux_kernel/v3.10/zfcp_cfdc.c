static int F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
unsigned int V_4 ;
unsigned int V_5 = V_6 ;
while ( V_5 ) {
V_4 = F_2 ( ( unsigned int ) V_5 , V_2 -> V_4 ) ;
if ( F_3 ( F_4 ( V_2 ++ ) , V_3 , V_4 ) )
return - V_7 ;
V_3 += V_4 ;
V_5 -= V_4 ;
}
return 0 ;
}
static int F_5 ( void T_1 * V_3 ,
struct V_1 * V_2 )
{
unsigned int V_4 ;
unsigned int V_5 = V_6 ;
while ( V_5 ) {
V_4 = F_2 ( ( unsigned int ) V_5 , V_2 -> V_4 ) ;
if ( F_6 ( V_3 , F_4 ( V_2 ++ ) , V_4 ) )
return - V_7 ;
V_3 += V_4 ;
V_5 -= V_4 ;
}
return 0 ;
}
static struct V_8 * F_7 ( T_2 V_9 )
{
char V_10 [ 9 ] ;
struct V_11 * V_12 ;
struct V_8 * V_13 ;
snprintf ( V_10 , sizeof( V_10 ) , L_1 , V_9 ) ;
V_12 = F_8 ( & V_14 , V_10 ) ;
if ( ! V_12 )
return NULL ;
V_13 = F_9 ( V_12 ) ;
F_10 ( & V_12 -> V_15 ) ;
return V_13 ;
}
static int F_11 ( struct V_16 * V_17 , int V_18 )
{
switch ( V_18 ) {
case V_19 :
V_17 -> V_18 = V_20 ;
V_17 -> V_21 = V_22 ;
break;
case V_23 :
V_17 -> V_18 = V_20 ;
V_17 -> V_21 = V_24 ;
break;
case V_25 :
V_17 -> V_18 = V_20 ;
V_17 -> V_21 = V_26 ;
break;
case V_27 :
V_17 -> V_18 = V_20 ;
V_17 -> V_21 = V_28 ;
break;
case V_29 :
V_17 -> V_18 = V_30 ;
V_17 -> V_21 = 0 ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_12 ( int V_18 , struct V_1 * V_2 ,
T_3 T_1 * V_32 )
{
int V_33 ;
V_33 = F_13 ( V_2 , V_34 ) ;
if ( V_33 )
return V_33 ;
V_2 [ V_34 - 1 ] . V_4 = V_6 % V_35 ;
if ( V_18 & V_36 &&
V_18 & V_37 ) {
V_33 = F_1 ( V_2 , V_32 ) ;
if ( V_33 ) {
F_14 ( V_2 , V_34 ) ;
return - V_7 ;
}
}
return 0 ;
}
static void F_15 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
V_39 -> V_42 = V_41 -> V_43 -> V_44 . V_42 ;
memcpy ( & V_39 -> V_45 , & V_41 -> V_43 -> V_44 . V_45 ,
sizeof( union V_45 ) ) ;
memcpy ( & V_39 -> V_46 , & V_41 -> V_43 -> V_47 . V_48 . V_49 ,
sizeof( V_41 -> V_43 -> V_47 . V_48 . V_49 ) ) ;
}
static long F_16 ( struct V_50 * V_50 , unsigned int V_18 ,
unsigned long V_51 )
{
struct V_38 * V_39 ;
struct V_38 T_1 * V_52 ;
struct V_8 * V_13 ;
struct V_40 * V_41 ;
struct V_16 * V_17 ;
int V_33 ;
if ( V_18 != V_53 )
return - V_54 ;
if ( F_17 () )
V_52 = F_18 ( V_51 ) ;
else
V_52 = ( void T_1 * ) V_51 ;
if ( ! V_52 )
return - V_31 ;
V_17 = F_19 ( sizeof( struct V_16 ) , V_55 ) ;
if ( ! V_17 )
return - V_56 ;
V_39 = F_20 ( V_52 , sizeof( * V_52 ) ) ;
if ( F_21 ( V_39 ) ) {
V_33 = F_22 ( V_39 ) ;
goto V_57;
}
if ( V_39 -> V_58 != 0xCFDCACDF ) {
V_33 = - V_31 ;
goto V_59;
}
V_33 = F_11 ( V_17 , V_39 -> V_18 ) ;
V_13 = F_7 ( V_39 -> V_9 ) ;
if ( ! V_13 ) {
V_33 = - V_60 ;
goto V_59;
}
V_33 = F_12 ( V_39 -> V_18 , V_17 -> V_2 ,
V_52 -> V_32 ) ;
if ( V_33 )
goto V_61;
V_41 = F_23 ( V_13 , V_17 ) ;
if ( F_21 ( V_41 ) ) {
V_33 = F_22 ( V_41 ) ;
goto V_62;
}
if ( V_41 -> V_63 & V_64 ) {
V_33 = - V_60 ;
goto V_65;
}
F_15 ( V_39 , V_41 ) ;
V_33 = F_6 ( V_52 , V_39 , sizeof( * V_52 ) ) ;
if ( V_33 ) {
V_33 = - V_7 ;
goto V_65;
}
if ( V_39 -> V_18 & V_66 )
V_33 = F_5 ( & V_52 -> V_32 ,
V_17 -> V_2 ) ;
V_65:
F_24 ( V_41 ) ;
V_62:
F_14 ( V_17 -> V_2 , V_34 ) ;
V_61:
F_25 ( V_13 ) ;
V_59:
F_26 ( V_39 ) ;
V_57:
F_26 ( V_17 ) ;
return V_33 ;
}
void F_27 ( struct V_8 * V_13 )
{
unsigned long V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
int V_63 ;
if ( V_13 -> V_74 & V_75 )
return;
F_28 ( & V_13 -> V_76 , V_67 ) ;
F_29 (port, &adapter->port_list, list) {
V_63 = F_30 ( & V_69 -> V_63 ) ;
if ( ( V_63 & V_77 ) ||
( V_63 & V_78 ) )
F_31 ( V_69 ,
V_79 ,
L_2 ) ;
}
F_32 ( & V_13 -> V_76 , V_67 ) ;
F_33 (sdev, adapter->scsi_host) {
V_73 = F_34 ( V_71 ) ;
V_63 = F_30 ( & V_73 -> V_63 ) ;
if ( ( V_63 & V_77 ) ||
( V_63 & V_78 ) )
F_35 ( V_71 ,
V_79 ,
L_3 ) ;
}
}
static void F_36 ( struct V_8 * V_13 , T_2 V_80 )
{
T_4 V_81 = V_80 >> 16 ;
T_4 V_82 = V_80 & 0xffff ;
const char * V_83 [] = { L_4 , L_5 , L_6 , L_7 , L_8 } ;
if ( V_81 && V_81 < F_37 ( V_83 ) )
F_38 ( & V_13 -> V_11 -> V_15 ,
L_9
L_10 , V_83 [ V_81 ] , V_82 ) ;
}
void F_39 ( struct V_68 * V_69 ,
union V_45 * V_84 )
{
F_38 ( & V_69 -> V_13 -> V_11 -> V_15 ,
L_11 ,
( unsigned long long ) V_69 -> V_85 ) ;
F_36 ( V_69 -> V_13 , V_84 -> V_86 [ 0 ] ) ;
F_36 ( V_69 -> V_13 , V_84 -> V_86 [ 1 ] ) ;
F_40 ( V_69 ,
V_79 |
V_77 ) ;
}
void F_41 ( struct V_70 * V_71 ,
union V_45 * V_84 )
{
struct V_72 * V_73 = F_34 ( V_71 ) ;
F_38 ( & V_73 -> V_69 -> V_13 -> V_11 -> V_15 ,
L_12 ,
F_42 ( V_71 ) ,
( unsigned long long ) V_73 -> V_69 -> V_85 ) ;
F_36 ( V_73 -> V_69 -> V_13 , V_84 -> V_86 [ 0 ] ) ;
F_36 ( V_73 -> V_69 -> V_13 , V_84 -> V_86 [ 1 ] ) ;
F_43 ( V_71 ,
V_79 |
V_77 ) ;
F_44 ( V_87 , & V_73 -> V_63 ) ;
F_44 ( V_88 , & V_73 -> V_63 ) ;
}
void F_45 ( struct V_70 * V_71 ,
union V_45 * V_84 )
{
struct V_72 * V_73 = F_34 ( V_71 ) ;
if ( V_84 -> V_89 [ 0 ] )
F_38 ( & V_73 -> V_69 -> V_13 -> V_11 -> V_15 ,
L_13
L_14 ,
F_42 ( V_71 ) ,
( unsigned long long ) V_73 -> V_69 -> V_85 ,
V_84 -> V_90 . V_91 ,
V_84 -> V_90 . V_92 ) ;
else
F_36 ( V_73 -> V_69 -> V_13 , V_84 -> V_89 [ 2 ] ) ;
F_43 ( V_71 ,
V_79 |
V_77 ) ;
F_44 ( V_87 , & V_73 -> V_63 ) ;
F_44 ( V_88 , & V_73 -> V_63 ) ;
}
int F_46 ( struct V_70 * V_71 ,
struct V_93 * V_47 )
{
int V_94 , V_95 ;
struct V_72 * V_73 = F_34 ( V_71 ) ;
struct V_8 * V_13 = V_73 -> V_69 -> V_13 ;
if ( ( V_13 -> V_74 & V_75 ) ||
! ( V_13 -> V_96 & V_97 ) ||
F_47 ( V_13 ) )
return 0 ;
V_94 = ! ( V_47 -> V_98 & V_99 ) ;
V_95 = ( V_47 -> V_98 & V_100 ) ;
if ( V_94 )
F_48 ( V_87 , & V_73 -> V_63 ) ;
if ( ! V_95 ) {
F_48 ( V_88 , & V_73 -> V_63 ) ;
F_49 ( & V_13 -> V_11 -> V_15 , L_15
L_16 ,
F_42 ( V_71 ) ,
( unsigned long long ) V_73 -> V_69 -> V_85 ) ;
}
if ( ! V_94 && ! V_95 ) {
F_50 ( & V_13 -> V_11 -> V_15 , L_17
L_18 ,
F_42 ( V_71 ) ,
( unsigned long long ) V_73 -> V_69 -> V_85 ) ;
F_43 ( V_71 , V_79 ) ;
F_51 ( V_71 , 0 , L_19 ) ;
return - V_101 ;
}
if ( V_94 && V_95 ) {
F_50 ( & V_13 -> V_11 -> V_15 ,
L_20
L_21 ,
F_42 ( V_71 ) ,
( unsigned long long ) V_73 -> V_69 -> V_85 ) ;
F_43 ( V_71 , V_79 ) ;
F_51 ( V_71 , 0 , L_22 ) ;
return - V_101 ;
}
return 0 ;
}
