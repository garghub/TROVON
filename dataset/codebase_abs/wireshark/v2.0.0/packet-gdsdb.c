static int F_1 ( int V_1 )
{
return ( V_1 + ( 4 - ( V_1 & 3 ) ) ) ;
}
static int F_2 ( T_1 * V_2 , int V_3 , T_2 * V_4 , int V_5 )
{
T_3 * V_6 ;
int V_1 ;
V_6 = F_3 ( V_2 , V_3 , V_4 ,
V_5 , 4 , V_7 | V_8 ) ;
V_1 = F_1 ( F_4 ( V_4 , V_5 ) ) + 4 ;
F_5 ( V_6 , V_1 ) ;
return V_5 + V_1 ;
}
static int F_6 ( T_1 * V_2 , int V_9 , int V_10 , T_2 * V_4 , int V_5 )
{
T_3 * V_6 ;
T_4 V_1 ;
F_7 ( V_2 , V_9 , V_4 ,
V_5 , 4 , V_8 , & V_1 ) ;
V_5 += 4 ;
if ( V_1 > 0 )
{
V_6 = F_3 ( V_2 , V_10 , V_4 ,
V_5 , V_1 , V_11 ) ;
V_1 = F_1 ( V_1 ) ;
F_5 ( V_6 , V_1 ) ;
}
return V_5 + V_1 ;
}
static int
F_8 ( T_2 * V_4 V_12 , T_5 * T_6 V_12 , T_1 * V_2 V_12 , int V_5 V_12 )
{
return F_9 ( V_4 ) ;
}
static int
F_10 ( T_2 * V_4 , T_5 * T_6 , T_1 * V_2 , int V_5 )
{
int V_13 , V_14 , V_15 = 16 ;
int V_16 , V_1 = F_11 ( V_4 , V_5 ) ;
T_3 * V_6 ;
T_1 * V_17 ;
if ( V_1 < V_15 )
return - 1 ;
V_14 = F_4 ( V_4 , V_5 + 12 ) ;
V_15 += 4 + F_1 ( V_14 ) ;
if ( V_1 < V_15 + 4 )
return - 1 ;
V_13 = F_4 ( V_4 , V_5 + V_15 - 4 ) ;
V_15 += ( 4 + ( V_13 * 20 ) ) ;
if ( V_1 < V_15 )
return - 1 ;
F_3 ( V_2 , V_18 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_19 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_20 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
V_5 = F_2 ( V_2 , V_21 , V_4 , V_5 ) ;
F_3 ( V_2 , V_22 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_12 ( T_6 -> V_23 , V_24 , L_1 , F_13 ( V_4 , V_5 + 4 , F_4 ( V_4 , V_5 ) ) ) ;
V_5 = F_2 ( V_2 , V_25 , V_4 , V_5 ) ;
for( V_16 = 0 ; V_16 < V_13 ; V_16 ++ ) {
V_6 = F_3 ( V_2 , V_26 , V_4 , V_5 , 20 , V_11 ) ;
V_17 = F_14 ( V_6 , V_27 ) ;
F_3 ( V_17 , V_28 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_17 , V_29 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_17 , V_30 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_17 , V_31 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_17 , V_32 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
}
return V_5 ;
}
static int
F_15 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 ) {
return - 1 ;
}
F_3 ( V_2 , V_33 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_34 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_35 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_16 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 16 ) {
return - 1 ;
}
F_3 ( V_2 , V_36 , V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_37 , V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_38 , V_4 , V_5 , 8 , V_8 ) ;
V_5 += 8 ;
return V_5 ;
}
static int
F_17 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
int V_15 = 12 ;
int V_39 , V_1 = F_11 ( V_4 , V_5 ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_39 = F_4 ( V_4 , V_5 + 4 ) ;
V_15 += F_1 ( V_39 ) ;
if ( V_1 < V_15 )
return - 1 ;
V_39 = F_4 ( V_4 , V_5 + V_15 - 4 ) ;
V_15 += F_1 ( V_39 ) ;
if ( V_1 < V_15 )
return - 1 ;
F_3 ( V_2 , V_40 , V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_12 ( T_6 -> V_23 , V_24 , L_1 , F_13 ( V_4 , V_5 + 4 , F_4 ( V_4 , V_5 ) ) ) ;
V_5 = F_2 ( V_2 , V_41 , V_4 , V_5 ) ;
V_5 = F_2 ( V_2 , V_42 , V_4 , V_5 ) ;
return V_5 ;
}
static int
F_18 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
int V_15 = 8 ;
int V_39 , V_1 = F_11 ( V_4 , V_5 ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_39 = F_4 ( V_4 , V_5 + 4 ) ;
V_15 += F_1 ( V_39 ) ;
if ( V_1 < V_15 )
return - 1 ;
F_3 ( V_2 , V_43 , V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
V_5 = F_2 ( V_2 , V_44 , V_4 , V_5 ) ;
return V_5 ;
}
static int
F_19 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 20 ) {
return - 1 ;
}
F_3 ( V_2 , V_45 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_46 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_47 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_48 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_49 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
while ( F_11 ( V_4 , V_5 ) >= 12 ) {
F_3 ( V_2 , V_50 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_51 ,
V_4 , V_5 , 8 , V_8 ) ;
V_5 += 8 ;
}
return V_5 ;
}
static int
F_20 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 20 ) {
return - 1 ;
}
F_3 ( V_2 , V_52 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_53 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_54 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_55 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_56 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_21 ( T_1 * V_2 , T_2 * V_4 , int V_5 )
{
T_4 V_57 ;
while ( F_11 ( V_4 , V_5 ) >= 4 )
{
F_7 ( V_2 , V_58 , V_4 ,
V_5 , 4 , V_8 , & V_57 ) ;
V_5 += 4 ;
if ( V_57 == 0 )
break;
switch( V_57 )
{
case V_59 :
default:
F_3 ( V_2 , V_60 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
break;
case V_61 :
F_3 ( V_2 , V_62 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
break;
case V_63 :
case V_64 :
V_5 = F_2 ( V_2 , V_65 , V_4 , V_5 ) ;
break;
case V_66 :
V_5 = F_2 ( V_2 , V_67 , V_4 , V_5 ) ;
break;
}
}
return V_5 ;
}
static int
F_22 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
int V_15 = 16 ;
int V_1 = F_11 ( V_4 , V_5 ) ;
T_4 V_68 ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_15 += F_1 ( F_4 ( V_4 , V_5 + 12 ) ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
F_3 ( V_2 , V_69 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_70 , V_4 ,
V_5 , 8 , V_8 ) ;
V_5 += 8 ;
F_7 ( V_2 , V_71 , V_4 ,
V_5 , 4 , V_8 , & V_68 ) ;
V_5 += 4 ;
if ( V_68 > 0 )
F_3 ( V_2 , V_72 , V_4 , V_5 , V_68 , V_11 ) ;
V_5 += V_68 ;
return F_21 ( V_2 , V_4 , V_5 ) ;
}
static int
F_23 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 8 ) {
return - 1 ;
}
F_3 ( V_2 , V_73 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_74 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_24 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 4 ) {
return - 1 ;
}
F_3 ( V_2 , V_75 ,
V_4 , V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_25 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
int V_15 = 12 ;
int V_1 = F_11 ( V_4 , V_5 ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_15 += F_1 ( F_4 ( V_4 , V_5 ) ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_5 = F_2 ( V_2 , V_76 , V_4 , V_5 ) ;
F_3 ( V_2 , V_77 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_78 , V_4 , V_5 ,
8 , V_8 ) ;
V_5 += 8 ;
return V_5 ;
}
static int
F_26 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 8 ) {
return - 1 ;
}
F_3 ( V_2 , V_77 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_78 , V_4 , V_5 ,
8 , V_8 ) ;
V_5 += 8 ;
return V_5 ;
}
static int
F_27 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_28 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_29 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
int V_15 = 8 ;
int V_1 = F_11 ( V_4 , V_5 ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_15 += F_1 ( F_4 ( V_4 , V_5 + 4 ) ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
F_3 ( V_2 , V_79 , V_4 , V_5 ,
4 , V_8 ) ;
V_5 += 4 ;
V_5 = F_6 ( V_2 , V_80 , V_81 , V_4 , V_5 ) ;
return V_5 ;
}
static int
F_30 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
T_7 V_82 ;
int V_15 = 16 ;
int V_1 = F_11 ( V_4 , V_5 ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_82 = F_4 ( V_4 , V_5 - 4 ) ;
V_15 += F_1 ( F_4 ( V_4 , V_5 + 8 ) ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
if( V_82 == V_83 ) {
V_15 += F_1 ( F_4 ( V_4 , V_5 + V_15 - 8 ) ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
}
F_3 ( V_2 , V_84 , V_4 , V_5 ,
4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_85 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
V_5 = F_2 ( V_2 , V_86 , V_4 , V_5 ) ;
if( V_82 == V_83 ) {
V_5 = F_2 ( V_2 , V_87 , V_4 , V_5 ) ;
}
F_3 ( V_2 , V_88 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_31 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 16 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_32 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 4 )
return - 1 ;
F_3 ( V_2 , V_89 , V_4 , V_5 ,
4 , V_8 ) ;
return F_9 ( V_4 ) ;
}
static int
F_33 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 20 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_34 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 8 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_35 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_36 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 20 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_37 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 4 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_38 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 16 )
return - 1 ;
F_3 ( V_2 , V_90 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_91 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_92 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_93 , V_4 ,
V_5 , 4 , V_8 ) ;
return F_9 ( V_4 ) ;
}
static int
F_39 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 40 )
return - 1 ;
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_40 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
int V_15 = 20 ;
int V_1 = F_11 ( V_4 , V_5 ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
V_15 += F_1 ( F_4 ( V_4 , V_5 + 12 ) ) ;
if ( V_1 < V_15 ) {
return - 1 ;
}
F_3 ( V_2 , V_94 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_95 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_96 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_12 ( T_6 -> V_23 , V_24 , L_1 , F_13 ( V_4 , V_5 + 4 , F_4 ( V_4 , V_5 ) ) ) ;
V_5 = F_2 ( V_2 , V_97 , V_4 , V_5 ) ;
F_3 ( V_2 , V_98 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_41 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 ) {
return - 1 ;
}
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_42 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 8 ) {
return - 1 ;
}
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_43 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 8 ) {
return - 1 ;
}
F_3 ( V_2 , V_99 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
F_3 ( V_2 , V_100 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 += 4 ;
return V_5 ;
}
static int
F_44 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 ) {
return - 1 ;
}
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_45 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 12 ) {
return - 1 ;
}
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_46 ( T_2 * V_4 , T_5 * T_6 V_12 , T_1 * V_2 , int V_5 )
{
if ( F_11 ( V_4 , V_5 ) < 4 ) {
return - 1 ;
}
if ( V_2 ) {
}
return F_9 ( V_4 ) ;
}
static int
F_47 ( T_2 * V_4 , T_5 * T_6 , T_1 * V_2 , void * T_8 V_12 )
{
T_3 * V_6 ;
T_1 * V_101 ;
T_7 V_82 ;
int V_5 = 0 ;
if ( F_9 ( V_4 ) < 4 )
return 0 ;
V_82 = F_4 ( V_4 , V_5 ) ;
if( V_82 >= V_102 )
return 0 ;
F_48 ( T_6 -> V_23 , V_103 , L_2 ) ;
F_49 ( T_6 -> V_23 , V_24 ) ;
while ( F_11 ( V_4 , V_5 ) >= 4 )
{
V_82 = F_4 ( V_4 , V_5 ) ;
if( V_82 >= V_102 )
return 0 ;
F_50 ( T_6 -> V_23 , V_24 , L_3 ,
F_51 ( V_82 , V_104 , L_4 ) ) ;
V_6 = F_3 ( V_2 , V_105 , V_4 , V_5 , - 1 , V_11 ) ;
V_101 = F_14 ( V_6 , V_106 ) ;
F_3 ( V_101 , V_107 , V_4 ,
V_5 , 4 , V_8 ) ;
V_5 = V_108 [ V_82 ] ( V_4 , T_6 , V_101 , V_5 + 4 ) ;
if ( V_5 < 0 )
{
T_6 -> V_109 = V_110 ;
return - 1 ;
}
}
return V_5 ;
}
void
F_52 ( void )
{
static T_9 V_111 [] = {
{ & V_107 ,
{ L_5 , L_6 ,
V_112 , V_113 , F_53 ( V_104 ) , 0x0 ,
NULL , V_114 }
} ,
{ & V_18 ,
{ L_7 , L_8 ,
V_112 , V_113 , F_53 ( V_104 ) , 0x0 ,
NULL , V_114 }
} ,
{ & V_19 ,
{ L_9 , L_10 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_20 ,
{ L_11 , L_12 ,
V_112 , V_113 , F_53 ( V_115 ) , 0x0 ,
NULL , V_114 }
} ,
{ & V_21 ,
{ L_13 , L_14 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_22 ,
{ L_15 , L_16 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_25 ,
{ L_17 , L_18 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_26 ,
{ L_19 , L_20 ,
V_118 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_28 ,
{ L_9 , L_21 ,
V_119 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_29 ,
{ L_22 , L_23 ,
V_112 , V_113 , F_53 ( V_115 ) , 0x0 ,
NULL , V_114 }
} ,
{ & V_30 ,
{ L_24 , L_25 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_31 ,
{ L_26 , L_27 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_32 ,
{ L_28 , L_29 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_33 ,
{ L_9 , L_30 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_34 ,
{ L_22 , L_31 ,
V_112 , V_113 , F_53 ( V_115 ) , 0x0 ,
NULL , V_114 }
} ,
{ & V_35 ,
{ L_32 , L_33 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_36 ,
{ L_34 , L_35 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_37 ,
{ L_36 , L_37 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_38 ,
{ L_38 , L_39 ,
V_120 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_40 ,
{ L_40 , L_41 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_41 ,
{ L_42 , L_43 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_42 ,
{ L_44 , L_45 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_43 ,
{ L_46 , L_47 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_44 ,
{ L_48 , L_49 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_45 ,
{ L_50 , L_51 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_46 ,
{ L_52 , L_53 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_47 ,
{ L_54 , L_55 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_48 ,
{ L_56 , L_57 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_49 ,
{ L_58 , L_59 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_50 ,
{ L_60 , L_61 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_51 ,
{ L_62 , L_63 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_52 ,
{ L_64 , L_65 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_53 ,
{ L_64 , L_66 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_54 ,
{ L_64 , L_67 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_55 ,
{ L_64 , L_68 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_56 ,
{ L_64 , L_69 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_69 ,
{ L_70 , L_71 ,
V_112 , V_121 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_70 ,
{ L_72 , L_73 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_71 ,
{ L_74 , L_75 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_72 ,
{ L_76 , L_77 ,
V_122 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_58 ,
{ L_78 , L_79 ,
V_112 , V_113 , F_53 ( V_123 ) , 0x0 ,
NULL , V_114 }
} ,
{ & V_60 ,
{ L_80 , L_81 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_62 ,
{ L_82 , L_83 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_65 ,
{ L_84 , L_85 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_67 ,
{ L_86 , L_87 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_73 ,
{ L_46 , L_88 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_74 ,
{ L_46 , L_89 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{ &hf_gdsdb_transact_messages,
{ "Messages", "gdsdb.transact.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_75 ,
{ L_90 , L_91 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_76 ,
{ L_92 , L_93 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_77 ,
{ L_54 , L_94 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_78 ,
{ L_95 , L_96 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{ &hf_gdsdb_segment_blob,
{ "Blob", "gdsdb.segment.blob",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_segment_length,
{ "Length", "gdsdb.segment.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_segment_segment,
{ "Segment", "gdsdb.segment.segment",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_seekblob_blob,
{ "Blob", "gdsdb.seekblob.blob",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_seekblob_mode,
{ "Mode", "gdsdb.seekblob.mode",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_79 ,
{ L_97 , L_98 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_80 ,
{ L_99 , L_100 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_81 ,
{ L_46 , L_101 ,
V_122 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_84 ,
{ L_36 , L_102 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_85 ,
{ L_52 , L_103 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_86 ,
{ L_104 , L_105 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_87 ,
{ L_104 , L_106 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_88 ,
{ L_107 , L_108 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_89 ,
{ L_36 , L_109 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{ &hf_gdsdb_prepare2_transaction,
{ "Transaction", "gdsdb.prepare2.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_database,
{ "Database", "gdsdb.event.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_items,
{ "Event description block", "gdsdb.event.items",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_ast,
{ "ast routine", "gdsdb.event.ast",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_arg,
{ "Argument to ast routine", "gdsdb.event.arg",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_rid,
{ "ID", "gdsdb.event.id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_ddl_database,
{ "Database", "gdsdb.ddl.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_ddl_transaction,
{ "Transaction", "gdsdb.ddl.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_ddl_blr,
{ "BLR", "gdsdb.ddl.blr",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_transaction,
{ "Transaction", "gdsdb.slice.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_id,
{ "ID", "gdsdb.slice.id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_sdl,
{ "Slice description language", "gdsdb.slice.sdl",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_parameters,
{ "Parameters", "gdsdb.slice.parameters",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_sliceresponse_length,
{ "Length", "gdsdb.sliceresponse.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_90 ,
{ L_110 , L_111 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_91 ,
{ L_54 , L_112 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_92 ,
{ L_56 , L_113 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_93 ,
{ L_114 , L_115 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{ &hf_gdsdb_execute_outblr,
{ "Output BLR", "gdsdb.execute.outblr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_execute_outmsgnr,
{ "Output Message number", "gdsdb.execute.outmsgnr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_blr,
{ "BLR", "gdsdb.prepare.blr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_number,
{ "Message number", "gdsdb.prepare2.messagenumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_messages,
{ "Number of messages", "gdsdb.prepare2.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_outblr,
{ "Output BLR", "gdsdb.prepare2.outblr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_outmsgnr,
{ "Output Message number", "gdsdb.prepare2.outmsgnr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_94 ,
{ L_116 , L_117 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_95 ,
{ L_118 , L_119 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_96 ,
{ L_120 , L_121 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_97 ,
{ L_122 , L_123 ,
V_116 , V_117 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_98 ,
{ L_124 , L_125 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{ &hf_gdsdb_fetch_statement,
{ "Statement", "gdsdb.fetch.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetch_message_number,
{ "Message number", "gdsdb.fetch.messagenr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetch_messages,
{ "Number of messages", "gdsdb.fetch.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetchresponse_status,
{ "Status", "gdsdb.fetchresponse.status",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetchresponse_messages,
{ "Number of messages", "gdsdb.fetchresponse.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ & V_99 ,
{ L_110 , L_126 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_100 ,
{ L_127 , L_128 ,
V_112 , V_113 , NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{ &hf_gdsdb_insert_statement,
{ "Statement", "gdsdb.insert.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_insert_message_number,
{ "Message number", "gdsdb.insert.messagenr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_insert_messages,
{ "Number of messages", "gdsdb.insert.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_cursor_statement,
{ "Statement", "gdsdb.cursor.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_cursor_type,
{ "Type", "gdsdb.cursor.type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_sqlresponse_messages,
{ "SQL Response, Message Count", "gdsdb.sqlresponse.msgcount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
#endif
} ;
static T_10 * V_124 [] = {
& V_106 ,
& V_27
} ;
V_105 = F_54 (
L_129 ,
L_130 , L_131 ) ;
F_55 ( V_105 , V_111 , F_56 ( V_111 ) ) ;
F_57 ( V_124 , F_56 ( V_124 ) ) ;
}
void
F_58 ( void )
{
T_11 V_125 ;
V_125 = F_59 ( F_47 ,
V_105 ) ;
F_60 ( L_132 , V_126 , V_125 ) ;
}
