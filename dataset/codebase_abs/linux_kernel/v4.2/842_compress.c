static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
int V_6 ;
if ( V_4 <= V_5 )
return - V_7 ;
V_6 = F_2 ( V_2 , V_3 >> V_5 , V_4 - V_5 ) ;
if ( V_6 )
return V_6 ;
return F_2 ( V_2 , V_3 & F_3 ( V_5 - 1 , 0 ) , V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = V_2 -> V_9 , V_10 = V_8 + V_4 , V_5 = F_4 ( V_10 , 8 ) - V_10 ;
T_1 V_11 ;
T_2 * V_12 = V_2 -> V_12 ;
F_5 ( L_1 , ( unsigned char ) V_4 , ( unsigned long ) V_3 ) ;
if ( V_4 > 64 )
return - V_7 ;
if ( V_10 > 64 )
return F_1 ( V_2 , V_3 , V_4 , 32 ) ;
else if ( V_2 -> V_13 < 8 && V_10 > 32 && V_10 <= 56 )
return F_1 ( V_2 , V_3 , V_4 , 16 ) ;
else if ( V_2 -> V_13 < 4 && V_10 > 16 && V_10 <= 24 )
return F_1 ( V_2 , V_3 , V_4 , 8 ) ;
if ( F_6 ( V_10 , 8 ) > V_2 -> V_13 )
return - V_14 ;
V_11 = * V_12 & V_15 [ V_8 ] ;
V_3 <<= V_5 ;
if ( V_10 <= 8 )
* V_12 = V_11 | V_3 ;
else if ( V_10 <= 16 )
F_7 ( F_8 ( V_11 << 8 | V_3 ) , ( V_16 * ) V_12 ) ;
else if ( V_10 <= 24 )
F_7 ( F_9 ( V_11 << 24 | V_3 << 8 ) , ( V_17 * ) V_12 ) ;
else if ( V_10 <= 32 )
F_7 ( F_9 ( V_11 << 24 | V_3 ) , ( V_17 * ) V_12 ) ;
else if ( V_10 <= 40 )
F_7 ( F_10 ( V_11 << 56 | V_3 << 24 ) , ( V_18 * ) V_12 ) ;
else if ( V_10 <= 48 )
F_7 ( F_10 ( V_11 << 56 | V_3 << 16 ) , ( V_18 * ) V_12 ) ;
else if ( V_10 <= 56 )
F_7 ( F_10 ( V_11 << 56 | V_3 << 8 ) , ( V_18 * ) V_12 ) ;
else
F_7 ( F_10 ( V_11 << 56 | V_3 ) , ( V_18 * ) V_12 ) ;
V_2 -> V_9 += V_4 ;
if ( V_2 -> V_9 > 7 ) {
V_2 -> V_12 += V_2 -> V_9 / 8 ;
V_2 -> V_13 -= V_2 -> V_9 / 8 ;
V_2 -> V_9 %= 8 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_6 , V_20 , V_8 = 0 ;
T_2 * V_21 = V_22 [ V_19 ] ;
bool V_23 = false ;
if ( V_19 >= V_24 )
return - V_7 ;
F_5 ( L_2 , V_21 [ 4 ] ) ;
V_6 = F_2 ( V_2 , V_21 [ 4 ] , V_25 ) ;
if ( V_6 )
return V_6 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
F_5 ( L_3 , V_21 [ V_20 ] ) ;
switch ( V_21 [ V_20 ] & V_26 ) {
case V_27 :
if ( V_8 )
V_23 = true ;
else if ( V_21 [ V_20 ] & V_28 )
V_6 = F_2 ( V_2 , V_2 -> V_29 [ 0 ] , V_30 ) ;
else if ( V_21 [ V_20 ] & V_31 )
V_6 = F_2 ( V_2 , V_2 -> V_32 [ 0 ] , 64 ) ;
else
V_23 = true ;
break;
case V_33 :
if ( V_8 == 2 && V_21 [ V_20 ] & V_31 )
V_6 = F_2 ( V_2 , F_12 ( V_2 , 2 , 32 ) , 32 ) ;
else if ( V_8 != 0 && V_8 != 4 )
V_23 = true ;
else if ( V_21 [ V_20 ] & V_28 )
V_6 = F_2 ( V_2 , V_2 -> V_34 [ V_8 >> 2 ] , V_35 ) ;
else if ( V_21 [ V_20 ] & V_31 )
V_6 = F_2 ( V_2 , V_2 -> V_36 [ V_8 >> 2 ] , 32 ) ;
else
V_23 = true ;
break;
case V_37 :
if ( V_8 != 0 && V_8 != 2 && V_8 != 4 && V_8 != 6 )
V_23 = true ;
if ( V_21 [ V_20 ] & V_28 )
V_6 = F_2 ( V_2 , V_2 -> V_38 [ V_8 >> 1 ] , V_39 ) ;
else if ( V_21 [ V_20 ] & V_31 )
V_6 = F_2 ( V_2 , V_2 -> V_40 [ V_8 >> 1 ] , 16 ) ;
else
V_23 = true ;
break;
case V_41 :
V_23 = ( V_8 != 8 ) || ! ( V_21 [ V_20 ] & V_42 ) ;
break;
default:
V_23 = true ;
break;
}
if ( V_6 )
return V_6 ;
if ( V_23 ) {
F_13 ( L_4 ,
V_19 , V_20 , V_21 [ 0 ] , V_21 [ 1 ] , V_21 [ 2 ] , V_21 [ 3 ] ) ;
return - V_7 ;
}
V_8 += V_21 [ V_20 ] & V_26 ;
}
if ( V_8 != 8 ) {
F_13 ( L_5 ,
V_19 , V_8 , V_21 [ 0 ] , V_21 [ 1 ] , V_21 [ 2 ] , V_21 [ 3 ] ) ;
return - V_7 ;
}
if ( V_43 )
F_14 ( & V_44 [ V_21 [ 4 ] ] ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_45 )
{
int V_6 ;
if ( ! V_45 || -- V_45 > V_46 )
return - V_7 ;
V_6 = F_2 ( V_2 , V_47 , V_25 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_2 , V_45 , V_48 ) ;
if ( V_6 )
return V_6 ;
if ( V_43 )
F_14 ( & V_49 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_6 , V_20 ;
if ( ! V_8 || V_8 > V_50 )
return - V_7 ;
V_6 = F_2 ( V_2 , V_51 , V_25 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_2 , V_8 , V_52 ) ;
if ( V_6 )
return V_6 ;
for ( V_20 = 0 ; V_20 < V_8 ; V_20 ++ ) {
V_6 = F_2 ( V_2 , V_2 -> V_53 [ V_20 ] , 8 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_43 )
F_14 ( & V_54 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_6 = F_2 ( V_2 , V_55 , V_25 ) ;
if ( V_6 )
return V_6 ;
if ( V_43 )
F_14 ( & V_56 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_6 = F_2 ( V_2 , V_57 , V_25 ) ;
if ( V_6 )
return V_6 ;
if ( V_43 )
F_14 ( & V_58 ) ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 , T_2 V_19 )
{
T_2 * V_21 = V_22 [ V_19 ] ;
int V_20 , V_59 , V_8 = 0 ;
if ( V_19 >= V_24 )
return false ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
if ( V_21 [ V_20 ] & V_28 ) {
if ( V_21 [ V_20 ] & V_37 )
V_59 = F_20 ( V_2 , 2 , V_8 >> 1 ) ;
else if ( V_21 [ V_20 ] & V_33 )
V_59 = F_20 ( V_2 , 4 , V_8 >> 2 ) ;
else if ( V_21 [ V_20 ] & V_27 )
V_59 = F_20 ( V_2 , 8 , 0 ) ;
else
return false ;
if ( ! V_59 )
return false ;
}
V_8 += V_21 [ V_20 ] & V_26 ;
}
return true ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_32 [ 0 ] = F_12 ( V_2 , 0 , 64 ) ;
V_2 -> V_36 [ 0 ] = F_12 ( V_2 , 0 , 32 ) ;
V_2 -> V_36 [ 1 ] = F_12 ( V_2 , 4 , 32 ) ;
V_2 -> V_40 [ 0 ] = F_12 ( V_2 , 0 , 16 ) ;
V_2 -> V_40 [ 1 ] = F_12 ( V_2 , 2 , 16 ) ;
V_2 -> V_40 [ 2 ] = F_12 ( V_2 , 4 , 16 ) ;
V_2 -> V_40 [ 3 ] = F_12 ( V_2 , 6 , 16 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_60 = V_2 -> V_53 - V_2 -> V_61 ;
T_1 V_62 = ( V_60 >> 3 ) % ( 1 << V_30 ) ;
T_1 V_63 = ( V_60 >> 2 ) % ( 1 << V_35 ) ;
T_1 V_64 = ( V_60 >> 1 ) % ( 1 << V_39 ) ;
F_23 ( V_2 , 8 , V_62 , 0 ) ;
F_23 ( V_2 , 4 , V_63 , 0 ) ;
F_23 ( V_2 , 4 , V_63 , 1 ) ;
F_23 ( V_2 , 2 , V_64 , 0 ) ;
F_23 ( V_2 , 2 , V_64 , 1 ) ;
F_23 ( V_2 , 2 , V_64 , 2 ) ;
F_23 ( V_2 , 2 , V_64 , 3 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_6 , V_20 ;
V_2 -> V_29 [ 0 ] = V_65 ;
V_2 -> V_34 [ 0 ] = V_65 ;
V_2 -> V_34 [ 1 ] = V_65 ;
V_2 -> V_38 [ 0 ] = V_65 ;
V_2 -> V_38 [ 1 ] = V_65 ;
V_2 -> V_38 [ 2 ] = V_65 ;
V_2 -> V_38 [ 3 ] = V_65 ;
for ( V_20 = 0 ; V_20 < V_24 - 1 ; V_20 ++ ) {
if ( F_19 ( V_2 , V_20 ) )
break;
}
V_6 = F_11 ( V_2 , V_20 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
int F_25 ( const T_2 * V_53 , unsigned int V_66 ,
T_2 * V_12 , unsigned int * V_13 , void * V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
int V_6 ;
T_1 V_68 , V_69 , V_70 , V_71 ;
T_2 V_72 = 0 ;
F_26 ( sizeof( * V_2 ) > V_73 ) ;
F_27 ( V_2 , 8 ) ;
F_27 ( V_2 , 4 ) ;
F_27 ( V_2 , 2 ) ;
V_2 -> V_53 = ( T_2 * ) V_53 ;
V_2 -> V_61 = V_2 -> V_53 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = * V_13 ;
V_2 -> V_9 = 0 ;
V_71 = V_2 -> V_13 ;
* V_13 = 0 ;
if ( V_74 && ( V_66 % 8 ) ) {
F_13 ( L_6 , V_66 ) ;
return - V_7 ;
}
if ( F_28 ( V_66 < 8 ) )
goto V_75;
V_68 = ~ F_29 ( ( T_1 * ) V_2 -> V_53 ) ;
while ( V_2 -> V_66 > 7 ) {
V_69 = F_29 ( ( T_1 * ) V_2 -> V_53 ) ;
F_21 ( V_2 ) ;
if ( V_69 == V_68 ) {
if ( ++ V_72 <= V_46 )
goto V_76;
}
if ( V_72 ) {
V_6 = F_15 ( V_2 , V_72 ) ;
V_72 = 0 ;
if ( V_69 == V_68 )
goto V_76;
}
if ( V_69 == 0 )
V_6 = F_17 ( V_2 ) ;
else
V_6 = F_24 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_76:
V_68 = V_69 ;
F_22 ( V_2 ) ;
V_2 -> V_53 += 8 ;
V_2 -> V_66 -= 8 ;
}
if ( V_72 ) {
V_6 = F_15 ( V_2 , V_72 ) ;
if ( V_6 )
return V_6 ;
}
V_75:
if ( V_2 -> V_66 > 0 ) {
V_6 = F_16 ( V_2 , V_2 -> V_66 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_53 += V_2 -> V_66 ;
V_2 -> V_66 = 0 ;
}
V_6 = F_18 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_9 ) {
V_2 -> V_12 ++ ;
V_2 -> V_13 -- ;
V_2 -> V_9 = 0 ;
}
V_70 = ( 8 - ( ( V_71 - V_2 -> V_13 ) % 8 ) ) % 8 ;
if ( V_70 ) {
if ( V_70 > V_2 -> V_13 )
return - V_14 ;
memset ( V_2 -> V_12 , 0 , V_70 ) ;
V_2 -> V_12 += V_70 ;
V_2 -> V_13 -= V_70 ;
}
if ( F_28 ( ( V_71 - V_2 -> V_13 ) > V_77 ) )
return - V_14 ;
* V_13 = V_71 - V_2 -> V_13 ;
return 0 ;
}
static int T_3 F_30 ( void )
{
if ( V_43 )
F_31 () ;
return 0 ;
}
static void T_4 F_32 ( void )
{
if ( V_43 )
F_33 () ;
}
