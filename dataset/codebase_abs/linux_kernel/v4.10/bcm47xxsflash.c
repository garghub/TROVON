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
F_9 ( V_42 , V_2 -> V_45 + V_39 , V_40 ) ;
* V_41 = V_40 ;
return V_40 ;
}
static int F_10 ( struct V_21 * V_22 , T_1 V_46 , T_3 V_40 ,
const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_47 = 0 ;
F_1 ( V_2 , V_27 ) ;
V_2 -> V_5 ( V_2 , V_28 , V_46 ) ;
V_2 -> V_5 ( V_2 , V_15 , * V_42 ++ ) ;
if ( V_2 -> V_48 -> V_49 -> V_50 . V_51 < 20 ) {
F_1 ( V_2 , V_52 ) ;
return 1 ;
}
F_1 ( V_2 , V_53 | V_52 ) ;
V_46 ++ ;
V_40 -- ;
V_47 ++ ;
while ( V_40 > 0 ) {
if ( ( V_46 & 0xFF ) == 0 )
break;
F_1 ( V_2 , V_53 | * V_42 ++ ) ;
V_46 ++ ;
V_40 -- ;
V_47 ++ ;
}
V_2 -> V_5 ( V_2 , V_6 , 0 ) ;
F_5 ( 1 ) ;
if ( F_4 ( V_2 , V_34 / 10 ) )
F_3 ( L_3 ) ;
return V_47 ;
}
static int F_11 ( struct V_21 * V_22 , T_1 V_46 , T_3 V_40 ,
const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
T_1 V_54 = V_2 -> V_30 - 1 ;
T_1 V_55 = ( V_46 & ~ V_54 ) << 1 ;
T_1 V_56 = V_46 & V_54 ;
int V_47 = 0 ;
if ( V_56 || ( V_40 < V_2 -> V_30 ) ) {
int V_26 ;
V_2 -> V_5 ( V_2 , V_28 , V_55 ) ;
F_1 ( V_2 , V_57 ) ;
V_26 = F_4 ( V_2 , V_34 / 1000 ) ;
if ( V_26 ) {
F_3 ( L_4 , V_55 ) ;
return V_26 ;
}
}
while ( V_40 > 0 ) {
if ( V_56 == V_2 -> V_30 )
break;
V_2 -> V_5 ( V_2 , V_28 , V_56 ++ ) ;
V_2 -> V_5 ( V_2 , V_15 , * V_42 ++ ) ;
F_1 ( V_2 , V_58 ) ;
V_40 -- ;
V_47 ++ ;
}
V_2 -> V_5 ( V_2 , V_28 , V_55 ) ;
F_1 ( V_2 , V_59 ) ;
return V_47 ;
}
static int F_12 ( struct V_21 * V_22 , T_2 V_60 , T_3 V_40 ,
T_3 * V_41 , const T_4 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_47 ;
while ( V_40 > 0 ) {
switch ( V_2 -> type ) {
case V_13 :
V_47 = F_10 ( V_22 , V_60 , V_40 , V_42 ) ;
break;
case V_17 :
V_47 = F_11 ( V_22 , V_60 , V_40 , V_42 ) ;
break;
default:
F_13 ( 1 ) ;
}
if ( V_47 < 0 ) {
F_3 ( L_5 , V_60 ) ;
return V_47 ;
}
V_60 += ( T_2 ) V_47 ;
V_40 -= V_47 ;
* V_41 += V_47 ;
V_42 += V_47 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
V_22 -> V_25 = V_2 ;
V_22 -> V_62 . V_63 = V_62 ;
V_22 -> V_64 = L_6 ;
V_22 -> type = V_65 ;
V_22 -> V_66 = V_67 ;
V_22 -> V_43 = V_2 -> V_43 ;
V_22 -> V_68 = V_2 -> V_30 ;
V_22 -> V_69 = 1 ;
V_22 -> V_70 = 1 ;
V_22 -> V_71 = F_7 ;
V_22 -> V_72 = F_8 ;
V_22 -> V_73 = F_12 ;
}
static int F_15 ( struct V_1 * V_2 , T_5 V_46 )
{
return F_16 ( V_2 -> V_48 , V_46 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_5 V_46 ,
T_1 V_74 )
{
F_18 ( V_2 -> V_48 , V_46 , V_74 ) ;
}
static int F_19 ( struct V_75 * V_76 )
{
struct V_61 * V_62 = & V_76 -> V_62 ;
struct V_77 * V_78 = F_20 ( V_62 ) ;
struct V_1 * V_2 ;
struct V_79 * V_80 ;
int V_26 ;
V_2 = F_21 ( V_62 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
V_78 -> V_25 = V_2 ;
V_80 = F_22 ( V_76 , V_83 , 0 ) ;
if ( ! V_80 ) {
F_23 ( V_62 , L_7 ) ;
return - V_44 ;
}
if ( ! F_24 ( V_62 , V_80 -> V_84 , F_25 ( V_80 ) ,
V_80 -> V_64 ) ) {
F_23 ( V_62 , L_8 , V_80 ) ;
return - V_20 ;
}
V_2 -> V_48 = F_26 ( V_78 , struct V_85 , V_78 ) ;
V_2 -> V_8 = F_15 ;
V_2 -> V_5 = F_17 ;
if ( V_2 -> V_48 -> V_49 -> V_50 . V_51 == 54 )
V_2 -> V_45 = F_27 ( V_80 -> V_84 , F_25 ( V_80 ) ) ;
else
V_2 -> V_45 = F_28 ( V_80 -> V_84 , F_25 ( V_80 ) ) ;
if ( ! V_2 -> V_45 ) {
F_23 ( V_62 , L_9 , V_80 ) ;
return - V_82 ;
}
switch ( V_2 -> V_48 -> V_86 & V_87 ) {
case V_88 :
V_2 -> type = V_13 ;
break;
case V_89 :
V_2 -> type = V_17 ;
break;
}
V_2 -> V_30 = V_78 -> V_30 ;
V_2 -> V_90 = V_78 -> V_90 ;
V_2 -> V_43 = V_78 -> V_43 ;
F_14 ( V_2 , & V_76 -> V_62 ) ;
V_26 = F_29 ( & V_2 -> V_22 , V_91 , NULL , NULL , 0 ) ;
if ( V_26 ) {
F_3 ( L_10 , V_26 ) ;
F_30 ( V_2 -> V_45 ) ;
return V_26 ;
}
if ( F_4 ( V_2 , V_34 / 10 ) )
F_31 ( L_11 ) ;
return 0 ;
}
static int F_32 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_20 ( & V_76 -> V_62 ) ;
struct V_1 * V_2 = V_78 -> V_25 ;
F_33 ( & V_2 -> V_22 ) ;
F_30 ( V_2 -> V_45 ) ;
return 0 ;
}
