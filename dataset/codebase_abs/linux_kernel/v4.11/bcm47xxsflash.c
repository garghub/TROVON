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
T_3 V_43 = V_40 ;
if ( ( V_39 + V_40 ) > V_22 -> V_44 )
return - V_45 ;
if ( V_39 < V_46 ) {
T_3 V_47 ;
V_47 = F_9 ( V_40 , ( T_3 ) ( V_46 - V_39 ) ) ;
F_10 ( V_42 , V_2 -> V_48 + V_39 , V_47 ) ;
V_39 += V_47 ;
V_40 -= V_47 ;
V_42 += V_47 ;
}
for (; V_40 ; V_40 -- ) {
V_2 -> V_5 ( V_2 , V_28 , V_39 ++ ) ;
F_1 ( V_2 , V_49 ) ;
* V_42 ++ = V_2 -> V_8 ( V_2 , V_15 ) ;
}
* V_41 = V_43 ;
return V_43 ;
}
static int F_11 ( struct V_21 * V_22 , T_1 V_50 , T_3 V_40 ,
const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_51 = 0 ;
F_1 ( V_2 , V_27 ) ;
V_2 -> V_5 ( V_2 , V_28 , V_50 ) ;
V_2 -> V_5 ( V_2 , V_15 , * V_42 ++ ) ;
if ( V_2 -> V_52 -> V_53 -> V_54 . V_55 < 20 ) {
F_1 ( V_2 , V_56 ) ;
return 1 ;
}
F_1 ( V_2 , V_57 | V_56 ) ;
V_50 ++ ;
V_40 -- ;
V_51 ++ ;
while ( V_40 > 0 ) {
if ( ( V_50 & 0xFF ) == 0 )
break;
F_1 ( V_2 , V_57 | * V_42 ++ ) ;
V_50 ++ ;
V_40 -- ;
V_51 ++ ;
}
V_2 -> V_5 ( V_2 , V_6 , 0 ) ;
F_5 ( 1 ) ;
if ( F_4 ( V_2 , V_34 / 10 ) )
F_3 ( L_3 ) ;
return V_51 ;
}
static int F_12 ( struct V_21 * V_22 , T_1 V_50 , T_3 V_40 ,
const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
T_1 V_58 = V_2 -> V_30 - 1 ;
T_1 V_59 = ( V_50 & ~ V_58 ) << 1 ;
T_1 V_60 = V_50 & V_58 ;
int V_51 = 0 ;
if ( V_60 || ( V_40 < V_2 -> V_30 ) ) {
int V_26 ;
V_2 -> V_5 ( V_2 , V_28 , V_59 ) ;
F_1 ( V_2 , V_61 ) ;
V_26 = F_4 ( V_2 , V_34 / 1000 ) ;
if ( V_26 ) {
F_3 ( L_4 , V_59 ) ;
return V_26 ;
}
}
while ( V_40 > 0 ) {
if ( V_60 == V_2 -> V_30 )
break;
V_2 -> V_5 ( V_2 , V_28 , V_60 ++ ) ;
V_2 -> V_5 ( V_2 , V_15 , * V_42 ++ ) ;
F_1 ( V_2 , V_62 ) ;
V_40 -- ;
V_51 ++ ;
}
V_2 -> V_5 ( V_2 , V_28 , V_59 ) ;
F_1 ( V_2 , V_63 ) ;
return V_51 ;
}
static int F_13 ( struct V_21 * V_22 , T_2 V_64 , T_3 V_40 ,
T_3 * V_41 , const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_51 ;
while ( V_40 > 0 ) {
switch ( V_2 -> type ) {
case V_13 :
V_51 = F_11 ( V_22 , V_64 , V_40 , V_42 ) ;
break;
case V_17 :
V_51 = F_12 ( V_22 , V_64 , V_40 , V_42 ) ;
break;
default:
F_14 ( 1 ) ;
}
if ( V_51 < 0 ) {
F_3 ( L_5 , V_64 ) ;
return V_51 ;
}
V_64 += ( T_2 ) V_51 ;
V_40 -= V_51 ;
* V_41 += V_51 ;
V_42 += V_51 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
V_22 -> V_25 = V_2 ;
V_22 -> V_66 . V_67 = V_66 ;
V_22 -> V_68 = L_6 ;
V_22 -> type = V_69 ;
V_22 -> V_70 = V_71 ;
V_22 -> V_44 = V_2 -> V_44 ;
V_22 -> V_72 = V_2 -> V_30 ;
V_22 -> V_73 = 1 ;
V_22 -> V_74 = 1 ;
V_22 -> V_75 = F_7 ;
V_22 -> V_76 = F_8 ;
V_22 -> V_77 = F_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_5 V_50 )
{
return F_17 ( V_2 -> V_52 , V_50 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_5 V_50 ,
T_1 V_78 )
{
F_19 ( V_2 -> V_52 , V_50 , V_78 ) ;
}
static int F_20 ( struct V_79 * V_80 )
{
struct V_65 * V_66 = & V_80 -> V_66 ;
struct V_81 * V_82 = F_21 ( V_66 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
int V_26 ;
V_2 = F_22 ( V_66 , sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
V_84 = F_23 ( V_80 , V_87 , 0 ) ;
if ( ! V_84 ) {
F_24 ( V_66 , L_7 ) ;
return - V_45 ;
}
if ( ! F_25 ( V_66 , V_84 -> V_88 , F_26 ( V_84 ) ,
V_84 -> V_68 ) ) {
F_24 ( V_66 , L_8 , V_84 ) ;
return - V_20 ;
}
V_2 -> V_52 = F_27 ( V_82 , struct V_89 , V_82 ) ;
V_2 -> V_8 = F_16 ;
V_2 -> V_5 = F_18 ;
if ( V_2 -> V_52 -> V_53 -> V_54 . V_55 == 54 )
V_2 -> V_48 = F_28 ( V_84 -> V_88 , F_26 ( V_84 ) ) ;
else
V_2 -> V_48 = F_29 ( V_84 -> V_88 , F_26 ( V_84 ) ) ;
if ( ! V_2 -> V_48 ) {
F_24 ( V_66 , L_9 , V_84 ) ;
return - V_86 ;
}
switch ( V_2 -> V_52 -> V_90 & V_91 ) {
case V_92 :
V_2 -> type = V_13 ;
break;
case V_93 :
V_2 -> type = V_17 ;
break;
}
V_2 -> V_30 = V_82 -> V_30 ;
V_2 -> V_94 = V_82 -> V_94 ;
V_2 -> V_44 = V_82 -> V_44 ;
F_15 ( V_2 , & V_80 -> V_66 ) ;
F_30 ( V_80 , V_2 ) ;
V_26 = F_31 ( & V_2 -> V_22 , V_95 , NULL , NULL , 0 ) ;
if ( V_26 ) {
F_3 ( L_10 , V_26 ) ;
F_32 ( V_2 -> V_48 ) ;
return V_26 ;
}
if ( F_4 ( V_2 , V_34 / 10 ) )
F_33 ( L_11 ) ;
return 0 ;
}
static int F_34 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_35 ( V_80 ) ;
F_36 ( & V_2 -> V_22 ) ;
F_32 ( V_2 -> V_48 ) ;
return 0 ;
}
