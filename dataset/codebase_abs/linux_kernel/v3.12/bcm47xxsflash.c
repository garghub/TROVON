static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_2 -> V_5 ( V_2 , V_6 , V_7 | V_3 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( ! ( V_2 -> V_8 ( V_2 , V_6 ) &
V_9 ) )
return;
F_2 () ;
}
F_3 ( L_1 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_11 = V_12 + V_10 ;
do {
switch ( V_2 -> type ) {
case V_13 :
F_1 ( V_2 , V_14 ) ;
if ( ! ( V_2 -> V_8 ( V_2 , V_15 ) &
V_16 ) )
return 0 ;
break;
case V_17 :
F_1 ( V_2 , V_18 ) ;
if ( V_2 -> V_8 ( V_2 , V_15 ) &
V_19 )
return 0 ;
break;
}
F_2 () ;
F_5 ( 1 ) ;
} while ( ! F_6 ( V_12 , V_11 ) );
F_3 ( L_2 ) ;
return - V_20 ;
}
static int F_7 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_26 ;
switch ( V_2 -> type ) {
case V_13 :
F_1 ( V_2 , V_27 ) ;
V_2 -> V_5 ( V_2 , V_28 , V_24 -> V_29 ) ;
if ( V_2 -> V_30 < ( 64 * 1024 ) )
F_1 ( V_2 , V_31 ) ;
else
F_1 ( V_2 , V_32 ) ;
break;
case V_17 :
V_2 -> V_5 ( V_2 , V_28 , V_24 -> V_29 << 1 ) ;
F_1 ( V_2 , V_33 ) ;
break;
}
V_26 = F_4 ( V_2 , V_34 ) ;
if ( V_26 )
V_24 -> V_35 = V_36 ;
else
V_24 -> V_35 = V_37 ;
if ( V_24 -> V_38 )
V_24 -> V_38 ( V_24 ) ;
return V_26 ;
}
static int F_8 ( struct V_21 * V_22 , T_2 V_39 , T_3 V_40 ,
T_3 * V_41 , T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
if ( ( V_39 + V_40 ) > V_22 -> V_43 )
return - V_44 ;
F_9 ( V_42 , ( void V_45 * ) F_10 ( V_2 -> V_46 + V_39 ) ,
V_40 ) ;
* V_41 = V_40 ;
return V_40 ;
}
static int F_11 ( struct V_21 * V_22 , T_1 V_47 , T_3 V_40 ,
const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_48 = 0 ;
F_1 ( V_2 , V_27 ) ;
V_2 -> V_5 ( V_2 , V_28 , V_47 ) ;
V_2 -> V_5 ( V_2 , V_15 , * V_42 ++ ) ;
if ( V_2 -> V_49 -> V_50 -> V_51 . V_52 < 20 ) {
F_1 ( V_2 , V_53 ) ;
return 1 ;
}
F_1 ( V_2 , V_54 | V_53 ) ;
V_47 ++ ;
V_40 -- ;
V_48 ++ ;
while ( V_40 > 0 ) {
if ( ( V_47 & 0xFF ) == 0 )
break;
F_1 ( V_2 , V_54 | * V_42 ++ ) ;
V_47 ++ ;
V_40 -- ;
V_48 ++ ;
}
V_2 -> V_5 ( V_2 , V_6 , 0 ) ;
F_5 ( 1 ) ;
if ( F_4 ( V_2 , V_34 / 10 ) )
F_3 ( L_3 ) ;
return V_48 ;
}
static int F_12 ( struct V_21 * V_22 , T_1 V_47 , T_3 V_40 ,
const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
T_1 V_55 = V_2 -> V_30 - 1 ;
T_1 V_56 = ( V_47 & ~ V_55 ) << 1 ;
T_1 V_57 = V_47 & V_55 ;
int V_48 = 0 ;
if ( V_57 || ( V_40 < V_2 -> V_30 ) ) {
int V_26 ;
V_2 -> V_5 ( V_2 , V_28 , V_56 ) ;
F_1 ( V_2 , V_58 ) ;
V_26 = F_4 ( V_2 , V_34 / 1000 ) ;
if ( V_26 ) {
F_3 ( L_4 , V_56 ) ;
return V_26 ;
}
}
while ( V_40 > 0 ) {
if ( V_57 == V_2 -> V_30 )
break;
V_2 -> V_5 ( V_2 , V_28 , V_57 ++ ) ;
V_2 -> V_5 ( V_2 , V_15 , * V_42 ++ ) ;
F_1 ( V_2 , V_59 ) ;
V_40 -- ;
V_48 ++ ;
}
V_2 -> V_5 ( V_2 , V_28 , V_56 ) ;
F_1 ( V_2 , V_60 ) ;
return V_48 ;
}
static int F_13 ( struct V_21 * V_22 , T_2 V_61 , T_3 V_40 ,
T_3 * V_41 , const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_48 ;
while ( V_40 > 0 ) {
switch ( V_2 -> type ) {
case V_13 :
V_48 = F_11 ( V_22 , V_61 , V_40 , V_42 ) ;
break;
case V_17 :
V_48 = F_12 ( V_22 , V_61 , V_40 , V_42 ) ;
break;
default:
F_14 ( 1 ) ;
}
if ( V_48 < 0 ) {
F_3 ( L_5 , V_61 ) ;
return V_48 ;
}
V_61 += ( T_2 ) V_48 ;
V_40 -= V_48 ;
* V_41 += V_48 ;
V_42 += V_48 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
V_22 -> V_25 = V_2 ;
V_22 -> V_62 = L_6 ;
V_22 -> V_63 = V_64 ;
V_22 -> type = V_65 ;
V_22 -> V_66 = V_67 ;
V_22 -> V_43 = V_2 -> V_43 ;
V_22 -> V_68 = V_2 -> V_30 ;
V_22 -> V_69 = 1 ;
V_22 -> V_70 = 1 ;
V_22 -> V_71 = F_7 ;
V_22 -> V_72 = F_8 ;
V_22 -> V_73 = F_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_5 V_47 )
{
return F_17 ( V_2 -> V_49 , V_47 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_5 V_47 ,
T_1 V_74 )
{
F_19 ( V_2 -> V_49 , V_47 , V_74 ) ;
}
static int F_20 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_21 ( & V_76 -> V_79 ) ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_22 ( & V_76 -> V_79 , sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
V_78 -> V_25 = V_2 ;
V_2 -> V_49 = F_23 ( V_78 , struct V_82 , V_78 ) ;
V_2 -> V_8 = F_16 ;
V_2 -> V_5 = F_18 ;
switch ( V_2 -> V_49 -> V_83 & V_84 ) {
case V_85 :
V_2 -> type = V_13 ;
break;
case V_86 :
V_2 -> type = V_17 ;
break;
}
V_2 -> V_46 = V_78 -> V_46 ;
V_2 -> V_30 = V_78 -> V_30 ;
V_2 -> V_87 = V_78 -> V_87 ;
V_2 -> V_43 = V_78 -> V_43 ;
F_15 ( V_2 ) ;
V_26 = F_24 ( & V_2 -> V_22 , V_88 , NULL , NULL , 0 ) ;
if ( V_26 ) {
F_3 ( L_7 , V_26 ) ;
return V_26 ;
}
if ( F_4 ( V_2 , V_34 / 10 ) )
F_25 ( L_8 ) ;
return 0 ;
}
static int F_26 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_21 ( & V_76 -> V_79 ) ;
struct V_1 * V_2 = V_78 -> V_25 ;
F_27 ( & V_2 -> V_22 ) ;
return 0 ;
}
