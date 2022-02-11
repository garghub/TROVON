static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_7 = F_6 ( V_2 -> V_8 , 3 ) ;
V_6 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_10 ) {
switch ( V_7 ) {
case 4 :
* V_2 -> V_10 ++ = ( V_6 >> 24 ) & 0xff ;
case 3 :
* V_2 -> V_10 ++ = ( V_6 >> 16 ) & 0xff ;
case 2 :
* V_2 -> V_10 ++ = ( V_6 >> 8 ) & 0xff ;
case 1 :
* V_2 -> V_10 ++ = ( V_6 >> 0 ) & 0xff ;
}
}
V_2 -> V_8 -= V_7 ;
V_2 -> V_11 -= V_7 ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
T_1 V_6 ;
T_2 V_12 ;
int V_7 ;
int V_13 ;
V_7 = F_6 ( V_2 -> V_14 , 3 ) ;
V_6 = 0 ;
for ( V_13 = 0 ; V_13 < V_7 ; V_13 ++ ) {
V_12 = V_2 -> V_15 ? * V_2 -> V_15 ++ : 0 ;
V_6 |= V_12 << ( 8 * ( 2 - V_13 ) ) ;
}
V_6 |= ( V_7 * 8 ) << 24 ;
V_2 -> V_14 -= V_7 ;
V_2 -> V_11 += V_7 ;
if ( V_2 -> V_14 )
F_3 ( V_2 , V_16 , V_6 ) ;
else
F_3 ( V_2 , V_9 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_17 , 0 ) ;
F_3 ( V_2 , V_18 ,
V_19 ) ;
}
static T_3 F_9 ( int V_20 , void * V_21 )
{
struct V_22 * V_23 = V_21 ;
struct V_1 * V_2 = F_10 ( V_23 ) ;
T_3 V_24 = V_25 ;
while ( V_2 -> V_8 &&
( ! ( F_1 ( V_2 , V_26 ) &
V_27 ) ) ) {
F_5 ( V_2 ) ;
V_24 = V_28 ;
}
while ( V_2 -> V_14 &&
( V_2 -> V_11 < 12 ) &&
( ! ( F_1 ( V_2 , V_26 ) &
V_29 ) ) ) {
F_7 ( V_2 ) ;
V_24 = V_28 ;
}
while ( V_2 -> V_8 &&
( ! ( F_1 ( V_2 , V_26 ) &
V_30 ) ) ) {
F_5 ( V_2 ) ;
V_24 = V_28 ;
}
if ( ! V_2 -> V_8 ) {
F_8 ( V_2 ) ;
F_11 ( & V_23 -> V_31 ) ;
}
return V_24 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
F_3 ( V_2 , V_17 , V_2 -> V_36 [ 1 ] |
V_37 |
V_38 ) ;
return 1 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
F_3 ( V_2 , V_17 , V_2 -> V_36 [ 1 ] ) ;
F_3 ( V_2 , V_18 , V_2 -> V_36 [ 0 ] ) ;
while ( ( V_2 -> V_14 ) &&
( V_2 -> V_11 < 12 ) &&
( ! ( F_1 ( V_2 , V_26 ) &
V_29 ) ) ) {
F_7 ( V_2 ) ;
}
return F_12 ( V_23 , V_33 , V_35 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
unsigned long V_39 ;
T_1 V_40 ;
F_3 ( V_2 , V_17 , V_2 -> V_36 [ 1 ] ) ;
F_3 ( V_2 , V_18 , V_2 -> V_36 [ 0 ] ) ;
V_39 = V_41 + V_42 ;
while ( V_2 -> V_8 ) {
V_40 = F_1 ( V_2 , V_26 ) ;
if ( ( V_2 -> V_14 ) && ( ! ( V_40 & V_29 ) ) ) {
F_7 ( V_2 ) ;
continue;
}
if ( ! ( V_40 & V_27 ) ) {
F_5 ( V_2 ) ;
continue;
}
if ( ! ( V_40 & V_30 ) ) {
F_5 ( V_2 ) ;
continue;
}
if ( V_2 -> V_8 && F_15 ( V_41 , V_39 ) ) {
F_16 ( & V_33 -> V_43 ,
L_1 ,
V_41 - V_39 ,
V_2 -> V_14 , V_2 -> V_8 ) ;
return F_12 ( V_23 ,
V_33 , V_35 ) ;
}
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
unsigned long V_44 , V_45 , V_46 ;
unsigned long V_47 ;
unsigned long long V_48 ;
V_2 -> V_36 [ 0 ] = V_49 |
V_50 |
V_51 ;
V_2 -> V_36 [ 1 ] = V_52 ;
V_44 = V_35 -> V_53 ;
V_45 = F_18 ( V_2 -> V_54 ) ;
if ( V_44 >= V_45 / 2 ) {
V_46 = 0 ;
} else if ( V_44 ) {
V_46 = F_19 ( V_45 , 2 * V_44 ) - 1 ;
if ( V_46 > V_55 )
V_46 = V_55 ;
} else {
V_46 = V_55 ;
}
V_2 -> V_36 [ 0 ] |= V_46 << V_56 ;
V_47 = V_45 / ( 2 * ( V_46 + 1 ) ) ;
if ( V_33 -> V_57 & V_58 )
V_2 -> V_36 [ 0 ] |= V_59 ;
if ( V_33 -> V_57 & V_60 )
V_2 -> V_36 [ 0 ] |= V_61 |
V_62 ;
V_2 -> V_15 = V_35 -> V_15 ;
V_2 -> V_10 = V_35 -> V_10 ;
V_2 -> V_14 = V_35 -> V_63 ;
V_2 -> V_8 = V_35 -> V_63 ;
V_2 -> V_11 = 0 ;
V_48 = V_35 -> V_63 * 9 * 1000000 ;
F_20 ( V_48 , V_47 ) ;
if ( V_48 < V_64 )
return F_14 ( V_23 , V_33 , V_35 ) ;
return F_13 ( V_23 , V_33 , V_35 ) ;
}
static void F_21 ( struct V_22 * V_23 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
F_8 ( V_2 ) ;
}
static int F_22 ( struct V_67 * V_68 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
unsigned long V_45 ;
int V_71 ;
V_23 = F_23 ( & V_68 -> V_43 , sizeof( * V_2 ) ) ;
if ( ! V_23 ) {
F_24 ( & V_68 -> V_43 , L_2 ) ;
return - V_72 ;
}
F_25 ( V_68 , V_23 ) ;
V_23 -> V_73 = V_74 ;
V_23 -> V_75 = F_26 ( 8 ) ;
V_23 -> V_76 = - 1 ;
V_23 -> V_77 = F_17 ;
V_23 -> V_78 = F_21 ;
V_23 -> V_43 . V_79 = V_68 -> V_43 . V_79 ;
V_2 = F_10 ( V_23 ) ;
V_70 = F_27 ( V_68 , V_80 , 0 ) ;
V_2 -> V_4 = F_28 ( & V_68 -> V_43 , V_70 ) ;
if ( F_29 ( V_2 -> V_4 ) ) {
V_71 = F_30 ( V_2 -> V_4 ) ;
goto V_81;
}
V_2 -> V_54 = F_31 ( & V_68 -> V_43 , NULL ) ;
if ( ( ! V_2 -> V_54 ) || ( F_29 ( V_2 -> V_54 ) ) ) {
V_71 = F_30 ( V_2 -> V_54 ) ;
F_24 ( & V_68 -> V_43 , L_3 , V_71 ) ;
goto V_81;
}
V_2 -> V_20 = F_32 ( V_68 , 0 ) ;
if ( V_2 -> V_20 <= 0 ) {
F_24 ( & V_68 -> V_43 , L_4 , V_2 -> V_20 ) ;
V_71 = V_2 -> V_20 ? V_2 -> V_20 : - V_82 ;
goto V_81;
}
V_71 = F_33 ( V_2 -> V_54 ) ;
if ( V_71 ) {
F_24 ( & V_68 -> V_43 , L_5 , V_71 ) ;
goto V_81;
}
V_45 = F_18 ( V_2 -> V_54 ) ;
if ( ! V_45 ) {
F_24 ( & V_68 -> V_43 , L_6 ) ;
V_71 = - V_82 ;
goto V_83;
}
F_8 ( V_2 ) ;
V_71 = F_34 ( & V_68 -> V_43 , V_2 -> V_20 ,
F_9 ,
V_84 ,
F_35 ( & V_68 -> V_43 ) , V_23 ) ;
if ( V_71 ) {
F_24 ( & V_68 -> V_43 , L_7 , V_71 ) ;
goto V_83;
}
V_71 = F_36 ( & V_68 -> V_43 , V_23 ) ;
if ( V_71 ) {
F_24 ( & V_68 -> V_43 , L_8 , V_71 ) ;
goto V_83;
}
return 0 ;
V_83:
F_37 ( V_2 -> V_54 ) ;
V_81:
F_38 ( V_23 ) ;
return V_71 ;
}
static int F_39 ( struct V_67 * V_68 )
{
struct V_22 * V_23 = F_40 ( V_68 ) ;
struct V_1 * V_2 = F_10 ( V_23 ) ;
F_8 ( V_2 ) ;
F_37 ( V_2 -> V_54 ) ;
return 0 ;
}
