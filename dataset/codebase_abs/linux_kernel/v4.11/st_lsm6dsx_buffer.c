static int F_1 ( T_1 V_1 )
{
const int V_2 = F_2 ( V_3 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( V_3 [ V_4 ] . V_5 == V_1 )
break;
return V_4 == V_2 ? 0 : V_3 [ V_4 ] . V_1 ;
}
static void F_3 ( struct V_6 * V_7 ,
T_2 * V_8 , T_2 * V_9 )
{
struct V_10 * V_11 ;
int V_4 ;
* V_8 = 0 , * V_9 = ~ 0 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_11 = F_4 ( V_7 -> V_13 [ V_4 ] ) ;
if ( ! ( V_7 -> V_14 & F_5 ( V_11 -> V_15 ) ) )
continue;
* V_8 = F_6 ( T_2 , * V_8 , V_11 -> V_16 ) ;
* V_9 = F_7 ( T_2 , * V_9 , V_11 -> V_16 ) ;
}
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
T_2 V_8 , V_9 , V_17 = 0 ;
int V_18 , V_4 ;
T_1 V_19 ;
F_3 ( V_7 , & V_8 , & V_9 ) ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_11 = F_4 ( V_7 -> V_13 [ V_4 ] ) ;
if ( V_7 -> V_14 & F_5 ( V_11 -> V_15 ) ) {
V_11 -> V_17 = V_11 -> V_16 / V_9 ;
V_11 -> V_5 = V_8 / V_11 -> V_16 ;
V_19 = F_1 ( V_11 -> V_5 ) ;
} else {
V_11 -> V_17 = 0 ;
V_11 -> V_5 = 0 ;
V_19 = 0 ;
}
V_18 = F_9 ( V_7 ,
V_20 ,
V_11 -> V_21 , V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_17 += V_11 -> V_17 ;
}
V_7 -> V_17 = V_17 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
enum V_22 V_23 )
{
T_1 V_19 ;
int V_18 ;
switch ( V_23 ) {
case V_24 :
V_19 = V_23 ;
break;
case V_25 :
V_19 = ( V_26 <<
F_11 ( V_27 ) ) | V_23 ;
break;
default:
return - V_28 ;
}
V_18 = V_7 -> V_29 -> V_30 ( V_7 -> V_31 , V_32 ,
sizeof( V_19 ) , & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_7 -> V_23 = V_23 ;
return 0 ;
}
int F_12 ( struct V_10 * V_11 , T_2 V_33 )
{
T_2 V_34 = ~ 0 , V_35 , V_17 = 0 ;
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_10 * V_36 ;
T_3 V_37 ;
int V_4 , V_18 ;
T_1 V_19 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_36 = F_4 ( V_7 -> V_13 [ V_4 ] ) ;
if ( ! ( V_7 -> V_14 & F_5 ( V_36 -> V_15 ) ) )
continue;
V_35 = ( V_36 == V_11 ) ? V_33
: V_36 -> V_33 ;
V_34 = F_7 ( T_2 , V_34 , V_35 ) ;
V_17 += V_36 -> V_17 ;
}
if ( ! V_17 )
return 0 ;
V_34 = F_6 ( T_2 , V_34 , V_17 ) ;
V_34 = ( V_34 / V_17 ) * V_17 ;
V_34 = V_34 * V_38 ;
F_13 ( & V_7 -> V_39 ) ;
V_18 = V_7 -> V_29 -> V_40 ( V_7 -> V_31 , V_41 ,
sizeof( V_19 ) , & V_19 ) ;
if ( V_18 < 0 )
goto V_42;
V_34 = ( ( V_19 << 8 ) & ~ V_43 ) |
( V_34 & V_43 ) ;
V_37 = F_14 ( V_34 ) ;
V_18 = V_7 -> V_29 -> V_30 ( V_7 -> V_31 , V_44 ,
sizeof( V_37 ) , ( T_1 * ) & V_37 ) ;
V_42:
F_15 ( & V_7 -> V_39 ) ;
return V_18 < 0 ? V_18 : 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
T_2 V_45 , V_46 = V_7 -> V_17 * V_47 ;
int V_18 , V_48 , V_49 , V_50 , V_51 , V_52 ;
struct V_10 * V_53 , * V_54 ;
T_4 V_55 , V_56 , V_57 , V_58 ;
T_1 V_59 [ F_17 ( V_47 , sizeof( T_4 ) ) + sizeof( T_4 ) ] ;
T_1 V_60 [ V_46 ] ;
T_3 V_61 ;
V_18 = V_7 -> V_29 -> V_40 ( V_7 -> V_31 , V_62 ,
sizeof( V_61 ) , ( T_1 * ) & V_61 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_61 & F_14 ( V_63 ) )
return 0 ;
V_45 = ( F_18 ( V_61 ) & V_64 ) *
V_65 ;
V_51 = V_45 / V_47 ;
V_45 = ( V_45 / V_46 ) * V_46 ;
V_53 = F_4 ( V_7 -> V_13 [ V_66 ] ) ;
V_55 = V_53 -> V_67 - V_53 -> V_68 ;
V_56 = F_19 ( V_53 -> V_68 * V_53 -> V_5 ,
V_51 ) ;
V_54 = F_4 ( V_7 -> V_13 [ V_69 ] ) ;
V_57 = V_54 -> V_67 - V_54 -> V_68 ;
V_58 = F_19 ( V_54 -> V_68 * V_54 -> V_5 ,
V_51 ) ;
for ( V_50 = 0 ; V_50 < V_45 ; V_50 += V_46 ) {
V_18 = V_7 -> V_29 -> V_40 ( V_7 -> V_31 , V_70 ,
sizeof( V_60 ) , V_60 ) ;
if ( V_18 < 0 )
return V_18 ;
V_49 = V_54 -> V_17 ;
V_48 = V_53 -> V_17 ;
V_52 = 0 ;
while ( V_48 > 0 || V_49 > 0 ) {
if ( V_49 -- > 0 ) {
memcpy ( V_59 , & V_60 [ V_52 ] ,
V_47 ) ;
F_20 (
V_7 -> V_13 [ V_69 ] ,
V_59 , V_57 ) ;
V_52 += V_47 ;
V_57 += V_58 ;
}
if ( V_48 -- > 0 ) {
memcpy ( V_59 , & V_60 [ V_52 ] ,
V_47 ) ;
F_20 (
V_7 -> V_13 [ V_66 ] ,
V_59 , V_55 ) ;
V_52 += V_47 ;
V_55 += V_56 ;
}
}
}
return V_50 ;
}
static int F_21 ( struct V_6 * V_7 )
{
int V_18 ;
F_13 ( & V_7 -> V_71 ) ;
F_16 ( V_7 ) ;
V_18 = F_10 ( V_7 , V_24 ) ;
F_15 ( & V_7 -> V_71 ) ;
return V_18 ;
}
static int F_22 ( struct V_72 * V_72 , bool V_73 )
{
struct V_10 * V_11 = F_4 ( V_72 ) ;
struct V_6 * V_7 = V_11 -> V_7 ;
int V_18 ;
if ( V_7 -> V_23 != V_24 ) {
V_18 = F_21 ( V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
}
if ( V_73 ) {
V_18 = F_23 ( V_11 ) ;
if ( V_18 < 0 )
return V_18 ;
} else {
V_18 = F_24 ( V_11 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_18 = F_8 ( V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_12 ( V_11 , V_11 -> V_33 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_7 -> V_14 ) {
V_18 = F_10 ( V_7 , V_25 ) ;
if ( V_18 < 0 )
return V_18 ;
V_11 -> V_67 = F_25 ( V_72 ) ;
}
return 0 ;
}
static T_5 F_26 ( int V_74 , void * V_75 )
{
struct V_6 * V_7 = (struct V_6 * ) V_75 ;
struct V_10 * V_11 ;
int V_4 ;
if ( ! V_7 -> V_17 )
return V_76 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_11 = F_4 ( V_7 -> V_13 [ V_4 ] ) ;
if ( V_11 -> V_17 > 0 ) {
T_4 V_77 ;
V_77 = F_25 ( V_7 -> V_13 [ V_4 ] ) ;
V_11 -> V_68 = V_77 - V_11 -> V_67 ;
V_11 -> V_67 = V_77 ;
}
}
return V_78 ;
}
static T_5 F_27 ( int V_74 , void * V_75 )
{
struct V_6 * V_7 = (struct V_6 * ) V_75 ;
int V_79 ;
F_13 ( & V_7 -> V_71 ) ;
V_79 = F_16 ( V_7 ) ;
F_15 ( & V_7 -> V_71 ) ;
return ! V_79 ? V_76 : V_80 ;
}
static int F_28 ( struct V_72 * V_72 )
{
return F_22 ( V_72 , true ) ;
}
static int F_29 ( struct V_72 * V_72 )
{
return F_22 ( V_72 , false ) ;
}
int F_30 ( struct V_6 * V_7 )
{
struct V_81 * V_82 ;
unsigned long V_83 ;
int V_4 , V_18 ;
V_83 = F_31 ( F_32 ( V_7 -> V_74 ) ) ;
switch ( V_83 ) {
case V_84 :
case V_85 :
break;
default:
F_33 ( V_7 -> V_31 , L_1 , V_83 ) ;
return - V_28 ;
}
V_18 = F_34 ( V_7 -> V_31 , V_7 -> V_74 ,
F_26 ,
F_27 ,
V_83 | V_86 ,
L_2 , V_7 ) ;
if ( V_18 ) {
F_35 ( V_7 -> V_31 , L_3 ,
V_7 -> V_74 ) ;
return V_18 ;
}
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_82 = F_36 ( V_7 -> V_31 ) ;
if ( ! V_82 )
return - V_87 ;
F_37 ( V_7 -> V_13 [ V_4 ] , V_82 ) ;
V_7 -> V_13 [ V_4 ] -> V_88 |= V_89 ;
V_7 -> V_13 [ V_4 ] -> V_90 = & V_91 ;
}
return 0 ;
}
