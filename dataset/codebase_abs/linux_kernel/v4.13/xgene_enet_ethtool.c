static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
strcpy ( V_4 -> V_9 , L_1 ) ;
strcpy ( V_4 -> V_10 , V_11 ) ;
snprintf ( V_4 -> V_12 , V_13 , L_2 ) ;
sprintf ( V_4 -> V_14 , L_3 , V_8 -> V_15 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_20 ;
if ( F_4 ( V_6 -> V_21 ) ) {
if ( V_19 == NULL )
return - V_22 ;
F_5 ( V_19 , V_17 ) ;
return 0 ;
} else if ( V_6 -> V_21 == V_23 ) {
if ( V_6 -> V_24 ) {
if ( ! V_19 )
return - V_22 ;
F_5 ( V_19 , V_17 ) ;
return 0 ;
}
V_20 = V_25 | V_26 |
V_27 ;
F_6 (
V_17 -> V_28 . V_20 ,
V_20 ) ;
F_6 (
V_17 -> V_28 . V_29 ,
V_20 ) ;
V_17 -> V_30 . V_31 = V_32 ;
V_17 -> V_30 . V_33 = V_34 ;
V_17 -> V_30 . V_35 = V_36 ;
V_17 -> V_30 . V_37 = V_38 ;
} else {
V_20 = V_39 | V_40 ;
F_6 (
V_17 -> V_28 . V_20 ,
V_20 ) ;
F_6 (
V_17 -> V_28 . V_29 ,
V_20 ) ;
V_17 -> V_30 . V_31 = V_41 ;
V_17 -> V_30 . V_33 = V_34 ;
V_17 -> V_30 . V_35 = V_42 ;
V_17 -> V_30 . V_37 = V_43 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
if ( F_4 ( V_6 -> V_21 ) ) {
if ( ! V_19 )
return - V_22 ;
return F_8 ( V_19 , V_17 ) ;
}
if ( V_6 -> V_21 == V_23 ) {
if ( V_6 -> V_24 ) {
if ( ! V_19 )
return - V_22 ;
return F_8 ( V_19 , V_17 ) ;
}
}
return - V_44 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_45 , T_2 * V_46 )
{
int V_47 ;
T_2 * V_48 = V_46 ;
if ( V_45 != V_49 )
return;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
memcpy ( V_48 , V_51 [ V_47 ] . V_15 , V_52 ) ;
V_48 += V_52 ;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
memcpy ( V_48 , V_54 [ V_47 ] . V_15 , V_52 ) ;
V_48 += V_52 ;
}
}
static int F_10 ( struct V_1 * V_2 , int V_55 )
{
if ( V_55 != V_49 )
return - V_44 ;
return V_50 + V_53 ;
}
static void F_11 ( struct V_5 * V_6 )
{
T_1 V_56 , V_57 ;
T_1 V_58 , V_59 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_59 = F_12 ( V_6 , V_54 [ V_47 ] . V_60 ) ;
if ( V_54 [ V_47 ] . V_58 ) {
V_58 = F_13 ( V_54 [ V_47 ] . V_58 - 1 , 0 ) ;
V_6 -> V_61 [ V_47 ] += ( V_59 & V_58 ) ;
}
}
if ( V_6 -> V_21 == V_62 ) {
V_6 -> V_61 [ V_63 ] = 0 ;
} else {
V_6 -> V_61 [ V_64 ] -= V_6 -> V_61 [ V_63 ] ;
V_6 -> V_61 [ V_65 ] -= V_6 -> V_61 [ V_66 ] ;
V_6 -> V_61 [ V_67 ] -= V_6 -> V_61 [ V_68 ] ;
}
V_6 -> V_69 -> V_70 ( V_6 , & V_56 , & V_57 ) ;
V_6 -> V_61 [ V_71 ] += V_56 ;
V_6 -> V_61 [ V_72 ] += V_57 ;
V_6 -> V_61 [ V_73 ] = V_6 -> V_74 ;
V_6 -> V_61 [ V_75 ] = V_6 -> V_76 ;
}
int F_14 ( struct V_5 * V_6 )
{
V_6 -> V_61 = F_15 ( & V_6 -> V_8 -> V_77 ,
V_53 , sizeof( V_78 ) , V_79 ) ;
if ( ! V_6 -> V_61 )
return - V_80 ;
F_11 ( V_6 ) ;
memset ( V_6 -> V_61 , 0 , V_53 * sizeof( V_78 ) ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
V_78 * V_46 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_83 V_84 ;
int V_47 ;
F_17 ( V_2 , & V_84 ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
V_46 [ V_47 ] = * ( V_78 * ) ( ( char * ) & V_84 + V_51 [ V_47 ] . V_85 ) ;
F_11 ( V_6 ) ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ )
V_46 [ V_47 + V_50 ] = V_6 -> V_61 [ V_47 ] ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_87 -> V_37 = V_6 -> V_88 ;
V_87 -> V_89 = V_6 -> V_89 ;
V_87 -> V_90 = V_6 -> V_90 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_91 , V_92 ;
if ( F_4 ( V_6 -> V_21 ) ||
V_6 -> V_21 == V_23 ) {
if ( ! V_19 )
return - V_44 ;
if ( ! ( V_19 -> V_20 & V_93 ) ||
( ! ( V_19 -> V_20 & V_94 ) &&
V_87 -> V_90 != V_87 -> V_89 ) )
return - V_44 ;
V_6 -> V_88 = V_87 -> V_37 ;
V_6 -> V_89 = V_87 -> V_89 ;
V_6 -> V_90 = V_87 -> V_90 ;
V_91 = V_19 -> V_29 ;
V_92 = V_91 & ~ ( V_95 | V_96 ) ;
if ( V_87 -> V_90 )
V_92 |= V_95 | V_96 ;
if ( V_87 -> V_89 )
V_92 ^= V_96 ;
if ( V_91 ^ V_92 ) {
V_19 -> V_29 = V_92 ;
if ( V_19 -> V_37 )
return F_20 ( V_19 ) ;
if ( ! V_87 -> V_37 ) {
V_6 -> V_69 -> V_97 ( V_6 ,
V_6 -> V_89 ) ;
V_6 -> V_69 -> V_98 ( V_6 ,
V_6 -> V_90 ) ;
}
}
} else {
if ( V_87 -> V_37 )
return - V_44 ;
V_6 -> V_89 = V_87 -> V_89 ;
V_6 -> V_90 = V_87 -> V_90 ;
V_6 -> V_69 -> V_97 ( V_6 , V_6 -> V_89 ) ;
V_6 -> V_69 -> V_98 ( V_6 , V_6 -> V_90 ) ;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_99 = & V_100 ;
}
