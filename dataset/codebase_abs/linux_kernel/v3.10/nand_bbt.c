static int F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
if ( memcmp ( V_1 , V_3 -> V_4 , V_3 -> V_5 ) )
return - 1 ;
return 0 ;
}
static int F_2 ( T_1 * V_1 , int V_5 , int V_6 , struct V_2 * V_3 )
{
int V_7 = 0 ;
T_1 * V_8 = V_1 ;
if ( V_3 -> V_9 & V_10 )
return F_1 ( V_1 , V_3 ) ;
V_7 = V_6 + V_3 -> V_11 ;
if ( V_3 -> V_9 & V_12 )
if ( F_3 ( V_8 , 0xff , V_7 ) )
return - 1 ;
V_8 += V_7 ;
if ( memcmp ( V_8 , V_3 -> V_4 , V_3 -> V_5 ) )
return - 1 ;
if ( V_3 -> V_9 & V_12 ) {
V_8 += V_3 -> V_5 ;
V_7 += V_3 -> V_5 ;
if ( F_3 ( V_8 , 0xff , V_5 - V_7 ) )
return - 1 ;
}
return 0 ;
}
static int F_4 ( T_1 * V_1 , struct V_2 * V_3 )
{
if ( memcmp ( V_1 + V_3 -> V_11 , V_3 -> V_4 , V_3 -> V_5 ) )
return - 1 ;
return 0 ;
}
static T_2 F_5 ( struct V_2 * V_3 )
{
T_2 V_5 ;
if ( ! ( V_3 -> V_9 & V_10 ) )
return 0 ;
V_5 = V_3 -> V_5 ;
if ( V_3 -> V_9 & V_13 )
V_5 ++ ;
return V_5 ;
}
static int F_6 ( struct V_14 * V_15 , T_1 * V_1 , int V_16 , int V_17 ,
struct V_2 * V_3 , int V_11 )
{
int V_18 , V_19 = 0 , V_20 , V_21 , V_22 = 0 ;
struct V_23 * V_24 = V_15 -> V_25 ;
T_3 V_26 , V_5 , V_27 ;
T_4 V_28 ;
int V_29 = V_3 -> V_9 & V_30 ;
T_1 V_31 = ( T_1 ) ( ( 1 << V_29 ) - 1 ) ;
T_2 V_32 ;
int V_33 = V_3 -> V_33 ;
V_27 = ( V_17 * V_29 ) >> 3 ;
V_32 = F_5 ( V_3 ) ;
V_28 = ( ( T_4 ) V_16 ) << V_24 -> V_34 ;
while ( V_27 ) {
V_5 = F_7 ( V_27 , ( T_3 ) ( 1 << V_24 -> V_35 ) ) ;
if ( V_32 ) {
V_5 -= V_32 ;
V_28 += V_32 ;
V_32 = 0 ;
}
V_18 = F_8 ( V_15 , V_28 , V_5 , & V_26 , V_1 ) ;
if ( V_18 < 0 ) {
if ( F_9 ( V_18 ) ) {
F_10 ( L_1
L_2 , V_28 & ~ V_15 -> V_36 ) ;
return V_18 ;
} else if ( F_11 ( V_18 ) ) {
F_10 ( L_3
L_2 , V_28 & ~ V_15 -> V_36 ) ;
V_19 = V_18 ;
} else {
F_10 ( L_4 ) ;
return V_18 ;
}
}
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ ) {
T_1 V_37 = V_1 [ V_20 ] ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 += V_29 , V_22 += 2 ) {
T_1 V_38 = ( V_37 >> V_21 ) & V_31 ;
if ( V_38 == V_31 )
continue;
if ( V_33 && ( V_38 == V_33 ) ) {
F_10 ( L_5 ,
( T_4 ) ( ( V_11 << 2 ) + ( V_22 >> 1 ) ) << V_24 -> V_35 ) ;
V_24 -> V_39 [ V_11 + ( V_22 >> 3 ) ] |= 0x2 << ( V_22 & 0x06 ) ;
V_15 -> V_40 . V_41 ++ ;
continue;
}
F_10 ( L_6 ,
( T_4 ) ( ( V_11 << 2 ) + ( V_22 >> 1 ) ) << V_24 -> V_35 ) ;
if ( V_38 == 0 )
V_24 -> V_39 [ V_11 + ( V_22 >> 3 ) ] |= 0x3 << ( V_22 & 0x06 ) ;
else
V_24 -> V_39 [ V_11 + ( V_22 >> 3 ) ] |= 0x1 << ( V_22 & 0x06 ) ;
V_15 -> V_40 . V_42 ++ ;
}
}
V_27 -= V_5 ;
V_28 += V_5 ;
}
return V_19 ;
}
static int F_12 ( struct V_14 * V_15 , T_1 * V_1 , struct V_2 * V_3 , int V_43 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_18 = 0 , V_20 ;
if ( V_3 -> V_9 & V_44 ) {
int V_11 = 0 ;
for ( V_20 = 0 ; V_20 < V_24 -> V_45 ; V_20 ++ ) {
if ( V_43 == - 1 || V_43 == V_20 )
V_18 = F_6 ( V_15 , V_1 , V_3 -> V_46 [ V_20 ] ,
V_24 -> V_47 >> V_24 -> V_35 ,
V_3 , V_11 ) ;
if ( V_18 )
return V_18 ;
V_11 += V_24 -> V_47 >> ( V_24 -> V_35 + 2 ) ;
}
} else {
V_18 = F_6 ( V_15 , V_1 , V_3 -> V_46 [ 0 ] ,
V_15 -> V_48 >> V_24 -> V_35 , V_3 , 0 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , T_1 * V_1 , T_4 V_11 ,
struct V_2 * V_3 )
{
T_3 V_26 ;
T_3 V_5 ;
V_5 = V_3 -> V_5 ;
if ( V_3 -> V_9 & V_13 )
V_5 ++ ;
return F_8 ( V_15 , V_11 , V_5 , & V_26 , V_1 ) ;
}
static int F_14 ( struct V_14 * V_15 , T_1 * V_1 , T_4 V_11 ,
T_3 V_5 )
{
struct V_49 V_50 ;
int V_18 , V_19 = 0 ;
V_50 . V_51 = V_52 ;
V_50 . V_53 = 0 ;
V_50 . V_54 = V_15 -> V_55 ;
while ( V_5 > 0 ) {
V_50 . V_56 = V_1 ;
V_50 . V_5 = F_7 ( V_5 , ( T_3 ) V_15 -> V_36 ) ;
V_50 . V_57 = V_1 + V_50 . V_5 ;
V_18 = F_15 ( V_15 , V_11 , & V_50 ) ;
if ( V_18 ) {
if ( ! F_16 ( V_18 ) )
return V_18 ;
else if ( F_9 ( V_18 ) || ! V_19 )
V_19 = V_18 ;
}
V_1 += V_15 -> V_55 + V_15 -> V_36 ;
V_5 -= V_15 -> V_36 ;
V_11 += V_15 -> V_36 ;
}
return V_19 ;
}
static int F_17 ( struct V_14 * V_15 , T_1 * V_1 , T_4 V_11 ,
T_3 V_5 , struct V_2 * V_3 )
{
if ( V_3 -> V_9 & V_10 )
return F_13 ( V_15 , V_1 , V_11 , V_3 ) ;
else
return F_14 ( V_15 , V_1 , V_11 , V_5 ) ;
}
static int F_18 ( struct V_14 * V_15 , T_4 V_11 , T_3 V_5 ,
T_1 * V_1 , T_1 * V_58 )
{
struct V_49 V_50 ;
V_50 . V_51 = V_52 ;
V_50 . V_53 = 0 ;
V_50 . V_54 = V_15 -> V_55 ;
V_50 . V_56 = V_1 ;
V_50 . V_57 = V_58 ;
V_50 . V_5 = V_5 ;
return F_19 ( V_15 , V_11 , & V_50 ) ;
}
static T_2 F_20 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
T_2 V_59 = V_3 -> V_60 ;
if ( ! ( V_3 -> V_9 & V_10 ) )
V_59 += V_15 -> V_36 ;
return V_59 ;
}
static void F_21 ( struct V_14 * V_15 , T_1 * V_1 ,
struct V_2 * V_3 , struct V_2 * V_61 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
if ( V_3 -> V_9 & V_13 ) {
F_17 ( V_15 , V_1 , ( T_4 ) V_3 -> V_46 [ 0 ] << V_24 -> V_34 ,
V_15 -> V_36 , V_3 ) ;
V_3 -> V_62 [ 0 ] = V_1 [ F_20 ( V_15 , V_3 ) ] ;
F_10 ( L_7 ,
V_3 -> V_46 [ 0 ] , V_3 -> V_62 [ 0 ] ) ;
}
if ( V_61 && ( V_61 -> V_9 & V_13 ) ) {
F_17 ( V_15 , V_1 , ( T_4 ) V_61 -> V_46 [ 0 ] << V_24 -> V_34 ,
V_15 -> V_36 , V_61 ) ;
V_61 -> V_62 [ 0 ] = V_1 [ F_20 ( V_15 , V_61 ) ] ;
F_10 ( L_7 ,
V_61 -> V_46 [ 0 ] , V_61 -> V_62 [ 0 ] ) ;
}
}
static int F_22 ( struct V_14 * V_15 , struct V_2 * V_63 ,
T_4 V_11 , T_1 * V_1 , T_3 V_64 ,
int V_65 , int V_66 )
{
int V_19 , V_21 ;
V_19 = F_14 ( V_15 , V_1 , V_11 , V_64 ) ;
if ( V_19 && ! F_16 ( V_19 ) )
return V_19 ;
for ( V_21 = 0 ; V_21 < V_66 ; V_21 ++ , V_1 += V_65 ) {
if ( F_2 ( V_1 , V_65 , V_15 -> V_36 , V_63 ) )
return 1 ;
}
return 0 ;
}
static int F_23 ( struct V_14 * V_15 , struct V_2 * V_63 ,
T_4 V_11 , T_1 * V_1 , int V_66 )
{
struct V_49 V_50 ;
int V_21 , V_19 ;
V_50 . V_54 = V_15 -> V_55 ;
V_50 . V_57 = V_1 ;
V_50 . V_53 = 0 ;
V_50 . V_56 = NULL ;
V_50 . V_51 = V_52 ;
for ( V_21 = 0 ; V_21 < V_66 ; V_21 ++ ) {
V_19 = F_15 ( V_15 , V_11 , & V_50 ) ;
if ( V_19 && ! F_16 ( V_19 ) )
return V_19 ;
if ( F_4 ( V_1 , V_63 ) )
return 1 ;
V_11 += V_15 -> V_36 ;
}
return 0 ;
}
static int F_24 ( struct V_14 * V_15 , T_1 * V_1 ,
struct V_2 * V_63 , int V_43 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_20 , V_67 , V_66 , V_65 ;
int V_68 ;
T_4 V_28 ;
T_3 V_64 ;
F_10 ( L_8 ) ;
if ( V_63 -> V_9 & V_69 )
V_66 = 1 << ( V_24 -> V_35 - V_24 -> V_34 ) ;
else if ( V_63 -> V_9 & V_70 )
V_66 = 2 ;
else
V_66 = 1 ;
if ( ! ( V_63 -> V_9 & V_12 ) ) {
V_65 = 0 ;
V_64 = V_63 -> V_5 ;
} else {
V_65 = V_15 -> V_36 + V_15 -> V_55 ;
V_64 = V_66 * V_15 -> V_36 ;
}
if ( V_43 == - 1 ) {
V_67 = V_15 -> V_48 >> ( V_24 -> V_35 - 1 ) ;
V_68 = 0 ;
V_28 = 0 ;
} else {
if ( V_43 >= V_24 -> V_45 ) {
F_25 ( L_9 ,
V_43 + 1 , V_24 -> V_45 ) ;
return - V_71 ;
}
V_67 = V_24 -> V_47 >> ( V_24 -> V_35 - 1 ) ;
V_68 = V_43 * V_67 ;
V_67 += V_68 ;
V_28 = ( T_4 ) V_68 << ( V_24 -> V_35 - 1 ) ;
}
if ( V_24 -> V_72 & V_73 )
V_28 += V_15 -> V_74 - ( V_15 -> V_36 * V_66 ) ;
for ( V_20 = V_68 ; V_20 < V_67 ; ) {
int V_19 ;
F_26 ( V_63 -> V_9 & V_10 ) ;
if ( V_63 -> V_9 & V_69 )
V_19 = F_22 ( V_15 , V_63 , V_28 , V_1 , V_64 ,
V_65 , V_66 ) ;
else
V_19 = F_23 ( V_15 , V_63 , V_28 , V_1 , V_66 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 ) {
V_24 -> V_39 [ V_20 >> 3 ] |= 0x03 << ( V_20 & 0x6 ) ;
F_25 ( L_10 ,
V_20 >> 1 , ( unsigned long long ) V_28 ) ;
V_15 -> V_40 . V_42 ++ ;
}
V_20 += 2 ;
V_28 += ( 1 << V_24 -> V_35 ) ;
}
return 0 ;
}
static int F_27 ( struct V_14 * V_15 , T_1 * V_1 , struct V_2 * V_3 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_20 , V_75 ;
int V_29 , V_68 , V_76 , V_77 ;
int V_65 = V_15 -> V_36 + V_15 -> V_55 ;
int V_41 ;
int V_78 = V_24 -> V_35 - V_24 -> V_34 ;
if ( V_3 -> V_9 & V_79 ) {
V_68 = ( V_15 -> V_48 >> V_24 -> V_35 ) - 1 ;
V_77 = - 1 ;
} else {
V_68 = 0 ;
V_77 = 1 ;
}
if ( V_3 -> V_9 & V_44 ) {
V_75 = V_24 -> V_45 ;
V_41 = V_24 -> V_47 >> V_24 -> V_35 ;
V_68 &= V_41 - 1 ;
} else {
V_75 = 1 ;
V_41 = V_15 -> V_48 >> V_24 -> V_35 ;
}
V_29 = V_3 -> V_9 & V_30 ;
for ( V_20 = 0 ; V_20 < V_75 ; V_20 ++ ) {
V_3 -> V_62 [ V_20 ] = 0 ;
V_3 -> V_46 [ V_20 ] = - 1 ;
for ( V_76 = 0 ; V_76 < V_3 -> V_80 ; V_76 ++ ) {
int V_81 = V_68 + V_77 * V_76 ;
T_4 V_11 = ( T_4 ) V_81 << V_24 -> V_35 ;
F_17 ( V_15 , V_1 , V_11 , V_15 -> V_36 , V_3 ) ;
if ( ! F_2 ( V_1 , V_65 , V_15 -> V_36 , V_3 ) ) {
V_3 -> V_46 [ V_20 ] = V_81 << V_78 ;
if ( V_3 -> V_9 & V_13 ) {
V_11 = F_20 ( V_15 , V_3 ) ;
V_3 -> V_62 [ V_20 ] = V_1 [ V_11 ] ;
}
break;
}
}
V_68 += V_24 -> V_47 >> V_24 -> V_35 ;
}
for ( V_20 = 0 ; V_20 < V_75 ; V_20 ++ ) {
if ( V_3 -> V_46 [ V_20 ] == - 1 )
F_25 ( L_11 , V_20 ) ;
else
F_10 ( L_12
L_13 , V_3 -> V_46 [ V_20 ] , V_3 -> V_62 [ V_20 ] ) ;
}
return 0 ;
}
static void F_28 ( struct V_14 * V_15 , T_1 * V_1 ,
struct V_2 * V_3 ,
struct V_2 * V_61 )
{
F_27 ( V_15 , V_1 , V_3 ) ;
if ( V_61 )
F_27 ( V_15 , V_1 , V_61 ) ;
}
static int F_29 ( struct V_14 * V_15 , T_1 * V_1 ,
struct V_2 * V_3 , struct V_2 * V_61 ,
int V_82 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
struct V_83 V_84 ;
int V_20 , V_21 , V_18 , V_43 = 0 ;
int V_29 , V_68 , V_77 , V_16 , V_11 , V_67 , V_85 , V_86 ;
int V_87 , V_88 , V_89 , V_53 ;
T_1 V_31 [ 4 ] ;
T_1 V_90 = V_3 -> V_33 ;
T_3 V_26 , V_5 = 0 ;
T_4 V_91 ;
struct V_49 V_50 ;
V_50 . V_54 = V_15 -> V_55 ;
V_50 . V_53 = 0 ;
V_50 . V_56 = NULL ;
V_50 . V_51 = V_52 ;
if ( ! V_90 )
V_90 = 0xff ;
if ( V_3 -> V_9 & V_44 ) {
V_67 = ( int ) ( V_24 -> V_47 >> V_24 -> V_35 ) ;
if ( V_82 == - 1 ) {
V_87 = V_24 -> V_45 ;
} else {
V_87 = V_82 + 1 ;
V_43 = V_82 ;
}
} else {
V_67 = ( int ) ( V_15 -> V_48 >> V_24 -> V_35 ) ;
V_87 = 1 ;
}
for (; V_43 < V_87 ; V_43 ++ ) {
if ( V_3 -> V_46 [ V_43 ] != - 1 ) {
V_16 = V_3 -> V_46 [ V_43 ] ;
goto V_92;
}
if ( V_3 -> V_9 & V_79 ) {
V_68 = V_67 * ( V_43 + 1 ) - 1 ;
V_77 = - 1 ;
} else {
V_68 = V_43 * V_67 ;
V_77 = 1 ;
}
for ( V_20 = 0 ; V_20 < V_3 -> V_80 ; V_20 ++ ) {
int V_76 = V_68 + V_77 * V_20 ;
switch ( ( V_24 -> V_39 [ V_76 >> 2 ] >>
( 2 * ( V_76 & 0x03 ) ) ) & 0x03 ) {
case 0x01 :
case 0x03 :
continue;
}
V_16 = V_76 <<
( V_24 -> V_35 - V_24 -> V_34 ) ;
if ( ! V_61 || V_61 -> V_46 [ V_43 ] != V_16 )
goto V_92;
}
F_30 ( L_14 ) ;
return - V_93 ;
V_92:
V_29 = V_3 -> V_9 & V_30 ;
V_31 [ 2 ] = ~ V_90 ;
switch ( V_29 ) {
case 1 : V_85 = 3 ; V_86 = 0x07 ; V_31 [ 0 ] = 0x00 ; V_31 [ 1 ] = 0x01 ;
V_31 [ 3 ] = 0x01 ;
break;
case 2 : V_85 = 2 ; V_86 = 0x06 ; V_31 [ 0 ] = 0x00 ; V_31 [ 1 ] = 0x01 ;
V_31 [ 3 ] = 0x03 ;
break;
case 4 : V_85 = 1 ; V_86 = 0x04 ; V_31 [ 0 ] = 0x00 ; V_31 [ 1 ] = 0x0C ;
V_31 [ 3 ] = 0x0f ;
break;
case 8 : V_85 = 0 ; V_86 = 0x00 ; V_31 [ 0 ] = 0x00 ; V_31 [ 1 ] = 0x0F ;
V_31 [ 3 ] = 0xff ;
break;
default: return - V_71 ;
}
V_88 = V_43 * ( V_67 >> 2 ) ;
V_91 = ( ( T_4 ) V_16 ) << V_24 -> V_34 ;
if ( V_3 -> V_9 & V_94 ) {
V_91 &= ~ ( ( T_4 ) ( ( 1 << V_24 -> V_35 ) - 1 ) ) ;
V_5 = 1 << V_24 -> V_35 ;
V_18 = F_8 ( V_15 , V_91 , V_5 , & V_26 , V_1 ) ;
if ( V_18 < 0 ) {
if ( V_26 != V_5 ) {
F_10 ( L_15
L_16 ) ;
return V_18 ;
}
F_25 ( L_17
L_18 ) ;
}
V_50 . V_54 = ( V_5 >> V_24 -> V_34 ) * V_15 -> V_55 ;
V_50 . V_57 = & V_1 [ V_5 ] ;
V_18 = F_15 ( V_15 , V_91 + V_15 -> V_36 , & V_50 ) ;
if ( V_18 < 0 || V_50 . V_95 != V_50 . V_54 )
goto V_96;
V_89 = V_16 - ( int ) ( V_91 >> V_24 -> V_34 ) ;
V_11 = V_89 << V_24 -> V_34 ;
memset ( & V_1 [ V_11 ] , 0xff , ( T_3 ) ( V_67 >> V_85 ) ) ;
V_53 = V_5 + ( V_89 * V_15 -> V_55 ) ;
} else if ( V_3 -> V_9 & V_10 ) {
V_53 = 0 ;
V_11 = V_3 -> V_5 ;
if ( V_3 -> V_9 & V_13 )
V_11 ++ ;
V_5 = ( T_3 ) ( V_67 >> V_85 ) ;
V_5 += V_11 ;
V_5 = F_31 ( V_5 , V_15 -> V_36 ) ;
memset ( V_1 , 0xff , V_5 ) ;
memcpy ( V_1 , V_3 -> V_4 , V_3 -> V_5 ) ;
} else {
V_5 = ( T_3 ) ( V_67 >> V_85 ) ;
V_5 = F_31 ( V_5 , V_15 -> V_36 ) ;
memset ( V_1 , 0xff , V_5 +
( V_5 >> V_24 -> V_34 ) * V_15 -> V_55 ) ;
V_11 = 0 ;
V_53 = V_5 ;
memcpy ( & V_1 [ V_53 + V_3 -> V_11 ] , V_3 -> V_4 , V_3 -> V_5 ) ;
}
if ( V_3 -> V_9 & V_13 )
V_1 [ V_53 + V_3 -> V_60 ] = V_3 -> V_62 [ V_43 ] ;
for ( V_20 = 0 ; V_20 < V_67 ; ) {
T_1 V_37 ;
V_37 = V_24 -> V_39 [ V_88 + ( V_20 >> 2 ) ] ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ , V_20 ++ ) {
int V_97 = ( V_20 << ( 3 - V_85 ) ) & V_86 ;
V_1 [ V_11 + ( V_20 >> V_85 ) ] &=
~ ( V_31 [ V_37 & 0x03 ] << V_97 ) ;
V_37 >>= 2 ;
}
}
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_15 = V_15 ;
V_84 . V_98 = V_91 ;
V_84 . V_5 = 1 << V_24 -> V_35 ;
V_18 = F_32 ( V_15 , & V_84 , 1 ) ;
if ( V_18 < 0 )
goto V_96;
V_18 = F_18 ( V_15 , V_91 , V_5 , V_1 ,
V_3 -> V_9 & V_10 ? NULL :
& V_1 [ V_5 ] ) ;
if ( V_18 < 0 )
goto V_96;
F_10 ( L_19 ,
( unsigned long long ) V_91 , V_3 -> V_62 [ V_43 ] ) ;
V_3 -> V_46 [ V_43 ] = V_16 ;
}
return 0 ;
V_96:
F_25 ( L_20 , V_18 ) ;
return V_18 ;
}
static inline int F_33 ( struct V_14 * V_15 , struct V_2 * V_63 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
V_63 -> V_9 &= ~ V_12 ;
return F_24 ( V_15 , V_24 -> V_99 -> V_100 , V_63 , - 1 ) ;
}
static int F_34 ( struct V_14 * V_15 , T_1 * V_1 , struct V_2 * V_63 )
{
int V_20 , V_75 , V_101 , V_102 , V_82 , V_18 , V_103 ;
struct V_23 * V_24 = V_15 -> V_25 ;
struct V_2 * V_3 = V_24 -> V_104 ;
struct V_2 * V_61 = V_24 -> V_105 ;
struct V_2 * V_106 , * V_107 ;
if ( V_3 -> V_9 & V_44 )
V_75 = V_24 -> V_45 ;
else
V_75 = 1 ;
for ( V_20 = 0 ; V_20 < V_75 ; V_20 ++ ) {
V_101 = 0 ;
V_102 = 0 ;
V_106 = NULL ;
V_107 = NULL ;
V_18 = V_103 = 0 ;
V_82 = ( V_3 -> V_9 & V_44 ) ? V_20 : - 1 ;
if ( V_61 ) {
if ( V_3 -> V_46 [ V_20 ] == - 1 && V_61 -> V_46 [ V_20 ] == - 1 ) {
V_102 = 1 ;
V_101 = 0x03 ;
} else if ( V_3 -> V_46 [ V_20 ] == - 1 ) {
V_106 = V_61 ;
V_101 = 0x01 ;
} else if ( V_61 -> V_46 [ V_20 ] == - 1 ) {
V_106 = V_3 ;
V_101 = 0x02 ;
} else if ( V_3 -> V_62 [ V_20 ] == V_61 -> V_62 [ V_20 ] ) {
V_106 = V_3 ;
if ( ! ( V_3 -> V_9 & V_13 ) )
V_107 = V_61 ;
} else if ( ( ( V_108 ) ( V_3 -> V_62 [ V_20 ] - V_61 -> V_62 [ V_20 ] ) ) > 0 ) {
V_106 = V_3 ;
V_101 = 0x02 ;
} else {
V_106 = V_61 ;
V_101 = 0x01 ;
}
} else {
if ( V_3 -> V_46 [ V_20 ] == - 1 ) {
V_102 = 1 ;
V_101 = 0x01 ;
} else {
V_106 = V_3 ;
}
}
if ( V_102 ) {
if ( ! ( V_3 -> V_9 & V_109 ) )
continue;
if ( ! ( V_24 -> V_72 & V_110 ) )
F_24 ( V_15 , V_1 , V_63 , V_82 ) ;
V_3 -> V_62 [ V_20 ] = 1 ;
if ( V_61 )
V_61 -> V_62 [ V_20 ] = 1 ;
}
if ( V_106 ) {
V_18 = F_12 ( V_15 , V_1 , V_106 , V_82 ) ;
if ( F_9 ( V_18 ) ) {
V_106 -> V_46 [ V_20 ] = - 1 ;
V_106 -> V_62 [ V_20 ] = 0 ;
V_20 -- ;
continue;
}
}
if ( V_107 ) {
V_103 = F_12 ( V_15 , V_1 , V_107 , V_82 ) ;
if ( F_9 ( V_103 ) ) {
V_107 -> V_46 [ V_20 ] = - 1 ;
V_107 -> V_62 [ V_20 ] = 0 ;
V_20 -- ;
continue;
}
}
if ( F_11 ( V_18 ) || F_11 ( V_103 ) )
V_101 = 0x03 ;
if ( V_61 ) {
V_3 -> V_62 [ V_20 ] = F_35 ( V_3 -> V_62 [ V_20 ] , V_61 -> V_62 [ V_20 ] ) ;
V_61 -> V_62 [ V_20 ] = V_3 -> V_62 [ V_20 ] ;
}
if ( ( V_101 & 0x01 ) && ( V_3 -> V_9 & V_111 ) ) {
V_18 = F_29 ( V_15 , V_1 , V_3 , V_61 , V_82 ) ;
if ( V_18 < 0 )
return V_18 ;
}
if ( ( V_101 & 0x02 ) && V_61 && ( V_61 -> V_9 & V_111 ) ) {
V_18 = F_29 ( V_15 , V_1 , V_61 , V_3 , V_82 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return 0 ;
}
static void F_36 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_20 , V_21 , V_75 , V_76 , V_112 , V_113 ;
T_1 V_114 , V_115 ;
if ( V_3 -> V_9 & V_44 ) {
V_75 = V_24 -> V_45 ;
V_112 = ( int ) ( V_24 -> V_47 >> V_24 -> V_35 ) ;
} else {
V_75 = 1 ;
V_112 = ( int ) ( V_15 -> V_48 >> V_24 -> V_35 ) ;
}
for ( V_20 = 0 ; V_20 < V_75 ; V_20 ++ ) {
if ( ( V_3 -> V_9 & V_116 ) ||
! ( V_3 -> V_9 & V_111 ) ) {
if ( V_3 -> V_46 [ V_20 ] == - 1 )
continue;
V_76 = V_3 -> V_46 [ V_20 ] >> ( V_24 -> V_35 - V_24 -> V_34 ) ;
V_76 <<= 1 ;
V_114 = V_24 -> V_39 [ ( V_76 >> 3 ) ] ;
V_115 = V_114 | ( 0x2 << ( V_76 & 0x06 ) ) ;
V_24 -> V_39 [ ( V_76 >> 3 ) ] = V_115 ;
if ( ( V_114 != V_115 ) && V_3 -> V_33 )
F_37 ( V_15 , ( T_4 ) V_76 << ( V_24 -> V_35 - 1 ) ) ;
continue;
}
V_113 = 0 ;
if ( V_3 -> V_9 & V_79 )
V_76 = ( ( V_20 + 1 ) * V_112 ) - V_3 -> V_80 ;
else
V_76 = V_20 * V_112 ;
V_76 <<= 1 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_80 ; V_21 ++ ) {
V_114 = V_24 -> V_39 [ ( V_76 >> 3 ) ] ;
V_115 = V_114 | ( 0x2 << ( V_76 & 0x06 ) ) ;
V_24 -> V_39 [ ( V_76 >> 3 ) ] = V_115 ;
if ( V_114 != V_115 )
V_113 = 1 ;
V_76 += 2 ;
}
if ( V_113 && V_3 -> V_33 )
F_37 ( V_15 , ( T_4 ) ( V_76 - 2 ) << ( V_24 -> V_35 - 1 ) ) ;
}
}
static void F_38 ( struct V_14 * V_15 , struct V_2 * V_63 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
T_2 V_117 ;
T_2 V_29 ;
T_2 V_118 ;
if ( ! V_63 )
return;
V_117 = V_63 -> V_5 ;
V_29 = V_63 -> V_9 & V_30 ;
F_26 ( ( V_24 -> V_72 & V_10 ) &&
! ( V_24 -> V_72 & V_119 ) ) ;
F_26 ( ! V_29 ) ;
if ( V_63 -> V_9 & V_13 )
V_117 ++ ;
if ( V_63 -> V_9 & V_10 ) {
F_26 ( ! ( V_24 -> V_72 & V_119 ) ) ;
F_26 ( ! ( V_24 -> V_72 & V_10 ) ) ;
F_26 ( V_63 -> V_11 ) ;
if ( V_63 -> V_9 & V_13 )
F_26 ( V_63 -> V_60 != V_63 -> V_5 ) ;
F_26 ( V_63 -> V_9 & V_94 ) ;
}
if ( V_63 -> V_9 & V_44 )
V_118 = V_24 -> V_47 >> V_24 -> V_35 ;
else
V_118 = V_15 -> V_48 >> V_24 -> V_35 ;
V_118 >>= 3 ;
V_118 *= V_29 ;
if ( V_63 -> V_9 & V_10 )
V_118 += V_117 ;
F_26 ( V_118 > ( 1 << V_24 -> V_35 ) ) ;
}
int F_39 ( struct V_14 * V_15 , struct V_2 * V_63 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_5 , V_18 = 0 ;
T_1 * V_1 ;
struct V_2 * V_3 = V_24 -> V_104 ;
struct V_2 * V_61 = V_24 -> V_105 ;
V_5 = V_15 -> V_48 >> ( V_24 -> V_35 + 2 ) ;
V_24 -> V_39 = F_40 ( V_5 , V_120 ) ;
if ( ! V_24 -> V_39 )
return - V_121 ;
if ( ! V_3 ) {
if ( ( V_18 = F_33 ( V_15 , V_63 ) ) ) {
F_30 ( L_21 ) ;
F_41 ( V_24 -> V_39 ) ;
V_24 -> V_39 = NULL ;
}
return V_18 ;
}
F_38 ( V_15 , V_3 ) ;
F_38 ( V_15 , V_61 ) ;
V_5 = ( 1 << V_24 -> V_35 ) ;
V_5 += ( V_5 >> V_24 -> V_34 ) * V_15 -> V_55 ;
V_1 = F_42 ( V_5 ) ;
if ( ! V_1 ) {
F_41 ( V_24 -> V_39 ) ;
V_24 -> V_39 = NULL ;
return - V_121 ;
}
if ( V_3 -> V_9 & V_116 ) {
F_21 ( V_15 , V_1 , V_3 , V_61 ) ;
} else {
F_28 ( V_15 , V_1 , V_3 , V_61 ) ;
}
V_18 = F_34 ( V_15 , V_1 , V_63 ) ;
F_36 ( V_15 , V_3 ) ;
if ( V_61 )
F_36 ( V_15 , V_61 ) ;
F_43 ( V_1 ) ;
return V_18 ;
}
int F_37 ( struct V_14 * V_15 , T_4 V_11 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_5 , V_18 = 0 ;
int V_43 , V_82 ;
T_1 * V_1 ;
struct V_2 * V_3 = V_24 -> V_104 ;
struct V_2 * V_61 = V_24 -> V_105 ;
if ( ! V_24 -> V_39 || ! V_3 )
return - V_71 ;
V_5 = ( 1 << V_24 -> V_35 ) ;
V_5 += ( V_5 >> V_24 -> V_34 ) * V_15 -> V_55 ;
V_1 = F_44 ( V_5 , V_120 ) ;
if ( ! V_1 )
return - V_121 ;
if ( V_3 -> V_9 & V_44 ) {
V_43 = ( int ) ( V_11 >> V_24 -> V_122 ) ;
V_82 = V_43 ;
} else {
V_43 = 0 ;
V_82 = - 1 ;
}
V_3 -> V_62 [ V_43 ] ++ ;
if ( V_61 )
V_61 -> V_62 [ V_43 ] ++ ;
if ( V_3 -> V_9 & V_111 ) {
V_18 = F_29 ( V_15 , V_1 , V_3 , V_61 , V_82 ) ;
if ( V_18 < 0 )
goto V_123;
}
if ( V_61 && ( V_61 -> V_9 & V_111 ) ) {
V_18 = F_29 ( V_15 , V_1 , V_61 , V_3 , V_82 ) ;
}
V_123:
F_41 ( V_1 ) ;
return V_18 ;
}
static int F_45 ( struct V_23 * V_24 )
{
struct V_2 * V_63 ;
if ( V_24 -> V_124 ) {
F_25 ( L_22 ) ;
return - V_71 ;
}
V_63 = F_40 ( sizeof( * V_63 ) , V_120 ) ;
if ( ! V_63 )
return - V_121 ;
V_63 -> V_9 = V_24 -> V_72 & V_125 ;
V_63 -> V_11 = V_24 -> V_126 ;
V_63 -> V_5 = ( V_24 -> V_9 & V_127 ) ? 2 : 1 ;
V_63 -> V_4 = V_128 ;
V_63 -> V_9 |= V_129 ;
V_24 -> V_124 = V_63 ;
return 0 ;
}
int F_46 ( struct V_14 * V_15 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
if ( V_24 -> V_72 & V_119 ) {
if ( ! V_24 -> V_104 ) {
if ( V_24 -> V_72 & V_10 ) {
V_24 -> V_104 = & V_130 ;
V_24 -> V_105 = & V_131 ;
} else {
V_24 -> V_104 = & V_132 ;
V_24 -> V_105 = & V_133 ;
}
}
} else {
V_24 -> V_104 = NULL ;
V_24 -> V_105 = NULL ;
}
if ( ! V_24 -> V_124 )
F_45 ( V_24 ) ;
return F_39 ( V_15 , V_24 -> V_124 ) ;
}
int F_47 ( struct V_14 * V_15 , T_4 V_11 , int V_134 )
{
struct V_23 * V_24 = V_15 -> V_25 ;
int V_76 ;
T_1 V_18 ;
V_76 = ( int ) ( V_11 >> ( V_24 -> V_35 - 1 ) ) ;
V_18 = ( V_24 -> V_39 [ V_76 >> 3 ] >> ( V_76 & 0x06 ) ) & 0x03 ;
F_48 ( L_23
L_24 ,
( unsigned int ) V_11 , V_76 >> 1 , V_18 ) ;
switch ( ( int ) V_18 ) {
case 0x00 :
return 0 ;
case 0x01 :
return 1 ;
case 0x02 :
return V_134 ? 0 : 1 ;
}
return 1 ;
}
