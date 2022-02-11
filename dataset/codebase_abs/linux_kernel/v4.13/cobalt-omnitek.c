static char * F_1 ( T_1 V_1 )
{
switch ( V_1 & V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
case V_5 : return L_3 ;
}
return L_4 ;
}
static void F_2 ( struct V_6 * V_6 )
{
T_1 V_7 = F_3 ( V_8 ) ;
T_1 V_9 = F_3 ( V_10 ) ;
T_1 V_11 ;
F_4 ( L_5 ,
V_7 & 0xff , ( V_7 >> 8 ) & 0xff ,
( V_7 >> 16 ) & 0xffff , ( V_9 >> 24 ) & 0xff ) ;
switch ( ( V_9 >> 8 ) & 0x3 ) {
case 0 :
F_4 ( L_6 ) ;
break;
case 1 :
F_4 ( L_7 ) ;
break;
case 3 :
F_4 ( L_8 ) ;
break;
}
for ( V_11 = 0 ; V_11 < ( V_9 & 0xf ) ; V_11 ++ ) {
T_1 V_1 = F_3 ( F_5 ( V_11 ) ) ;
F_4 ( L_9 , V_11 ,
V_1 & V_12 ? L_10 : L_11 ,
F_1 ( V_1 ) ) ;
}
}
void F_6 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_6 * V_6 = V_14 -> V_6 ;
F_7 ( ( T_1 ) ( ( V_17 ) V_16 -> V_18 >> 32 ) , F_8 ( V_14 -> V_19 ) + 4 ) ;
F_7 ( ( T_1 ) V_16 -> V_18 & V_20 , F_8 ( V_14 -> V_19 ) ) ;
F_7 ( V_21 | V_22 | V_23 , F_5 ( V_14 -> V_19 ) ) ;
}
bool F_9 ( struct V_13 * V_14 )
{
struct V_6 * V_6 = V_14 -> V_6 ;
if ( F_3 ( F_5 ( V_14 -> V_19 ) ) & V_24 )
return true ;
return false ;
}
void F_10 ( struct V_13 * V_14 )
{
struct V_6 * V_6 = V_14 -> V_6 ;
if ( F_9 ( V_14 ) == false )
F_7 ( ABORT , F_5 ( V_14 -> V_19 ) ) ;
}
int F_11 ( struct V_6 * V_6 )
{
T_1 V_9 = F_3 ( V_10 ) ;
int V_11 ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = V_9 & 0xf ;
if ( V_9 & V_27 )
V_6 -> V_28 = false ;
else
V_6 -> V_28 = true ;
for ( V_11 = 0 ; V_11 < V_6 -> V_26 ; V_11 ++ ) {
T_1 V_1 = F_3 ( F_5 ( V_11 ) ) ;
T_1 V_29 = F_3 ( F_5 ( V_11 ) ) ;
if ( ! ( V_29 & V_24 ) )
F_7 ( ABORT , F_5 ( V_11 ) ) ;
if ( ! ( V_1 & V_12 ) )
V_6 -> V_25 ++ ;
}
F_2 ( V_6 ) ;
return 0 ;
}
int F_12 ( struct V_6 * V_6 ,
struct V_30 * V_31 , bool V_32 , unsigned V_33 ,
unsigned V_34 , unsigned V_35 , unsigned V_36 ,
struct V_15 * V_16 )
{
struct V_37 * V_38 = (struct V_37 * ) V_16 -> V_39 ;
T_2 V_40 = V_16 -> V_18 ;
unsigned V_41 = 0 ;
unsigned V_42 = V_35 ;
unsigned V_43 = 0 ;
bool V_44 = true ;
F_13 ( F_14 ( V_31 ) & 3 ) ;
F_13 ( V_34 & 3 ) ;
F_13 ( V_40 & 3 ) ;
F_13 ( V_36 & 3 ) ;
F_13 ( V_36 < V_35 ) ;
if ( V_35 >= V_36 )
V_42 = V_36 = V_34 ;
while ( V_34 ) {
T_2 V_45 = F_14 ( V_31 ) + V_41 ;
unsigned V_46 ;
if ( V_45 == 0 )
return - V_47 ;
if ( V_6 -> V_28 ) {
F_13 ( ( V_17 ) V_45 >> 32 ) ;
if ( ( V_17 ) V_45 >> 32 )
return - V_47 ;
}
V_38 -> V_48 = V_45 & 0xffffffff ;
V_38 -> V_49 = ( V_17 ) V_45 >> 32 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
V_46 = F_15 ( F_16 ( V_31 ) - V_41 ,
V_42 - V_43 ) ;
if ( V_44 ) {
if ( V_32 )
V_38 -> V_50 = 0x11111111 ;
V_44 = false ;
if ( V_33 == 1 ) {
V_38 -> V_46 = ( V_46 / 2 ) & ~ 3 ;
V_38 -> V_52 = 0 ;
V_34 -= V_38 -> V_46 ;
V_43 += V_38 -> V_46 ;
V_41 += V_38 -> V_46 ;
V_45 += V_38 -> V_46 ;
V_40 += sizeof( struct V_37 ) ;
V_38 -> V_53 = ( T_1 ) ( ( V_17 ) V_40 >> 32 ) ;
V_38 -> V_54 = ( T_1 ) V_40 |
( V_32 ? V_55 : 0 ) ;
V_46 -= V_38 -> V_46 ;
V_38 ++ ;
V_38 -> V_48 = V_45 & 0xffffffff ;
V_38 -> V_49 = ( V_17 ) V_45 >> 32 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
}
}
V_38 -> V_46 = V_46 ;
V_38 -> V_52 = 0 ;
V_34 -= V_46 ;
V_43 += V_46 ;
V_41 += V_46 ;
if ( V_43 == V_42 ) {
while ( V_43 < V_36 ) {
V_46 = F_15 ( F_16 ( V_31 ) - V_41 ,
V_36 - V_43 ) ;
V_43 += V_46 ;
V_41 += V_46 ;
V_34 -= V_46 ;
if ( F_16 ( V_31 ) == V_41 ) {
V_41 = 0 ;
V_31 = F_17 ( V_31 ) ;
}
}
V_43 = 0 ;
} else {
V_41 = 0 ;
V_31 = F_17 ( V_31 ) ;
}
V_40 += sizeof( struct V_37 ) ;
if ( V_34 == 0 ) {
V_38 -> V_53 = ( T_1 ) ( ( V_17 ) V_16 -> V_18 >> 32 ) ;
V_38 -> V_54 = ( T_1 ) V_16 -> V_18 |
( V_32 ? V_55 : 0 ) | V_56 ;
if ( ! V_32 )
V_38 -> V_50 = 0x22222222 ;
V_16 -> V_57 = V_38 ;
} else {
V_38 -> V_53 = ( T_1 ) ( ( V_17 ) V_40 >> 32 ) ;
V_38 -> V_54 = ( T_1 ) V_40 | ( V_32 ? V_55 : 0 ) ;
}
V_38 ++ ;
}
return 0 ;
}
void F_18 ( struct V_15 * V_58 ,
struct V_15 * V_40 )
{
struct V_37 * V_38 = V_58 -> V_57 ;
T_1 V_59 = V_38 -> V_54 & V_55 ;
if ( V_40 == NULL ) {
V_38 -> V_53 = 0 ;
V_38 -> V_54 = V_59 | V_56 | V_60 ;
} else {
V_38 -> V_53 = ( T_1 ) ( ( V_17 ) V_40 -> V_18 >> 32 ) ;
V_38 -> V_54 = ( T_1 ) V_40 -> V_18 | V_59 | V_56 ;
}
}
void * F_19 ( struct V_15 * V_16 , T_3 V_46 )
{
V_16 -> V_34 = V_46 ;
V_16 -> V_39 = F_20 ( V_16 -> V_61 , V_46 ,
& V_16 -> V_18 , V_62 ) ;
return V_16 -> V_39 ;
}
void F_21 ( struct V_15 * V_16 )
{
if ( V_16 -> V_39 )
F_22 ( V_16 -> V_61 , V_16 -> V_34 ,
V_16 -> V_39 , V_16 -> V_18 ) ;
V_16 -> V_39 = NULL ;
}
void F_23 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_57 ;
V_38 -> V_54 |= V_56 ;
}
void F_24 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_57 ;
V_38 -> V_54 &= ~ V_56 ;
}
void F_25 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_57 ;
V_38 -> V_53 = ( T_1 ) ( ( V_17 ) V_16 -> V_18 >> 32 ) ;
V_38 -> V_54 = ( T_1 ) V_16 -> V_18 | ( V_38 -> V_54 & V_63 ) ;
}
void F_26 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_57 ;
V_38 -> V_54 |= V_60 ;
}
