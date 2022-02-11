static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = V_6 ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_12 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_13 )
{
if ( V_13 == V_14 )
return V_15 ;
else
return - V_16 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_1 * V_19 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_22 , V_23 ;
char * V_24 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
V_24 = ( char * ) V_21 + V_26 [ V_22 ] . V_27 ;
V_19 [ V_22 ] = * ( T_1 * ) V_24 ;
}
for ( V_23 = 0 ; V_23 < V_21 -> V_28 -> V_29 ; V_23 ++ ) {
V_19 [ V_22 ++ ] = V_21 -> V_30 [ V_23 ] -> V_18 . V_31 ;
V_19 [ V_22 ++ ] = V_21 -> V_30 [ V_23 ] -> V_18 . V_32 ;
}
for ( V_23 = 0 ; V_23 < V_21 -> V_28 -> V_29 ; V_23 ++ ) {
V_19 [ V_22 ++ ] = V_21 -> V_33 [ V_23 ] -> V_18 . V_31 ;
V_19 [ V_22 ++ ] = V_21 -> V_33 [ V_23 ] -> V_18 . V_32 ;
}
}
static void F_5 ( struct V_1 * V_2 , T_2 V_13 , T_3 * V_19 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
T_3 * V_24 = V_19 ;
int V_22 ;
if ( V_13 == V_14 ) {
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
memcpy ( V_24 , V_26 [ V_22 ] . V_34 ,
V_35 ) ;
V_24 += V_35 ;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_28 -> V_29 ; V_22 ++ ) {
snprintf ( V_24 , V_35 , L_1 , V_22 ) ;
V_24 += V_35 ;
snprintf ( V_24 , V_35 , L_2 , V_22 ) ;
V_24 += V_35 ;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_28 -> V_29 ; V_22 ++ ) {
snprintf ( V_24 , V_35 , L_3 , V_22 ) ;
V_24 += V_35 ;
snprintf ( V_24 , V_35 , L_4 , V_22 ) ;
V_24 += V_35 ;
}
}
}
static T_2 F_6 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
return V_21 -> V_36 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_19 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
V_21 -> V_36 = V_19 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
F_9 ( V_38 -> V_39 , V_40 , 32 ) ;
F_9 ( V_38 -> V_41 , V_42 , 32 ) ;
F_9 ( V_38 -> V_43 , F_10 ( V_21 -> V_44 ) , 32 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
struct V_47 * V_48 = V_21 -> V_30 [ 0 ] ;
struct V_47 * V_49 = V_21 -> V_33 [ 0 ] ;
V_46 -> V_50 = V_51 ;
V_46 -> V_52 = V_53 ;
V_46 -> V_54 = V_49 -> V_55 ;
V_46 -> V_56 = V_48 -> V_55 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
T_2 V_57 , V_58 ;
int V_22 ;
if ( ( V_46 -> V_59 ) || ( V_46 -> V_60 ) )
return - V_61 ;
V_58 = F_13 ( T_2 , V_46 -> V_56 ,
V_62 ,
V_53 ) ;
V_58 = F_14 ( V_58 , V_63 ) ;
V_57 = F_13 ( T_2 , V_46 -> V_54 ,
V_64 ,
V_51 ) ;
V_57 = F_14 ( V_57 , V_63 ) ;
if ( ( V_58 == V_21 -> V_30 [ 0 ] -> V_55 ) &&
( V_57 == V_21 -> V_33 [ 0 ] -> V_55 ) )
return 0 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_28 -> V_29 ; V_22 ++ ) {
V_21 -> V_30 [ 0 ] -> V_55 = V_58 ;
V_21 -> V_33 [ 0 ] -> V_55 = V_57 ;
}
if ( F_15 ( V_2 ) )
F_16 ( V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
struct V_67 * V_68 = & V_21 -> V_68 ;
V_66 -> V_69 = V_68 -> V_70 ;
V_66 -> V_71 = V_68 -> V_70 ;
if ( F_18 ( V_68 -> V_72 ) )
V_66 -> V_73 = 1 ;
else
V_66 -> V_73 = V_68 -> V_72 ;
if ( F_18 ( V_68 -> V_74 ) )
V_66 -> V_75 = 1 ;
else
V_66 -> V_75 = V_68 -> V_74 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
struct V_76 * V_77 = & V_21 -> V_77 ;
struct V_67 * V_68 = & V_21 -> V_68 ;
struct V_78 * V_79 ;
int V_22 ;
if ( V_66 -> V_69 || V_66 -> V_71 )
V_68 -> V_70 = V_66 -> V_69 ;
switch ( V_66 -> V_73 ) {
case 0 :
V_68 -> V_72 = 0 ;
break;
case 1 :
V_68 -> V_72 = ( V_80
| F_20 ( V_81 ) ) ;
break;
default:
if ( ( V_66 -> V_73 < ( V_82 << 1 ) ) ||
( V_66 -> V_73 > ( V_83 << 1 ) ) )
return - V_61 ;
V_68 -> V_72 = V_66 -> V_73 ;
break;
}
switch ( V_66 -> V_75 ) {
case 0 :
V_68 -> V_74 = 0 ;
break;
case 1 :
V_68 -> V_74 = ( V_80
| F_20 ( V_84 ) ) ;
break;
default:
if ( ( V_66 -> V_75 < ( V_82 << 1 ) ) ||
( V_66 -> V_75 > ( V_83 << 1 ) ) )
return - V_61 ;
V_68 -> V_74 = V_66 -> V_75 ;
break;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_85 - V_86 ; V_22 ++ ) {
V_79 = V_21 -> V_79 [ V_22 ] ;
V_79 -> V_87 . V_88 = F_21 ( V_68 -> V_72 ) ;
F_22 ( V_77 , F_23 ( 0 , V_22 ) , V_79 -> V_87 . V_88 ) ;
V_79 -> V_89 . V_88 = F_21 ( V_68 -> V_74 ) ;
F_22 ( V_77 , F_23 ( 1 , V_22 ) , V_79 -> V_89 . V_88 ) ;
F_24 ( V_77 ) ;
}
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 , & V_90 ) ;
}
