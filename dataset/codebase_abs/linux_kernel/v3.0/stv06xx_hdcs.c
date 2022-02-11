static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 * V_3 , T_1 V_4 )
{
T_1 V_5 [ V_6 * 2 ] ;
int V_7 ;
if ( F_2 ( ( V_4 <= 0 ) || ( V_4 >= V_6 ) ||
( V_2 + V_4 > 0xff ) ) )
return - V_8 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
V_5 [ 2 * V_7 ] = V_2 ;
V_5 [ 2 * V_7 + 1 ] = V_3 [ V_7 ] ;
V_2 += 2 ;
}
return F_3 ( V_1 , V_5 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_1 , enum V_9 V_10 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
T_1 V_13 ;
int V_14 ;
if ( V_11 -> V_10 == V_10 )
return 0 ;
if ( V_11 -> V_10 != V_15 ) {
V_14 = F_5 ( V_1 , F_6 ( V_1 ) , 0 ) ;
if ( V_14 )
return V_14 ;
}
V_11 -> V_10 = V_15 ;
if ( V_10 == V_15 )
return 0 ;
switch ( V_10 ) {
case V_16 :
V_13 = V_17 ;
break;
case V_18 :
V_13 = V_19 ;
break;
default:
return - V_8 ;
}
V_14 = F_5 ( V_1 , F_6 ( V_1 ) , V_13 ) ;
if ( ! V_14 )
V_11 -> V_10 = V_10 ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
int V_20 ;
V_20 = F_5 ( V_1 , F_6 ( V_1 ) , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_5 ( V_1 , F_6 ( V_1 ) , 0 ) ;
if ( V_20 < 0 )
V_11 -> V_10 = V_15 ;
return V_20 ;
}
static int F_8 ( struct V_21 * V_21 , T_2 * V_13 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 ;
struct V_11 * V_11 = V_1 -> V_12 ;
* V_13 = V_11 -> V_22 ;
return 0 ;
}
static int F_9 ( struct V_21 * V_21 , T_2 V_13 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 ;
struct V_11 * V_11 = V_1 -> V_12 ;
int V_23 , V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 , V_20 ;
T_1 exp [ 14 ] ;
V_13 &= 0xff ;
V_11 -> V_22 = V_13 ;
V_30 = V_13 * V_31 * 257 ;
V_26 = V_11 -> exp . V_32 + V_11 -> V_33 + ( V_34 + 2 ) ;
V_27 = V_11 -> exp . V_32 + ( V_11 -> V_35 * V_26 / 2 ) ;
V_28 = V_11 -> exp . V_36 + V_27 ;
V_23 = V_30 / V_28 ;
V_30 -= V_23 * V_28 ;
if ( F_10 ( V_1 ) ) {
V_24 = V_11 -> V_35 - ( V_30 + V_11 -> exp . V_37 + 13 ) / V_26 ;
V_29 = ( V_11 -> exp . V_37 + 12 + V_26 - 1 ) / V_26 ;
V_25 = V_11 -> V_35 - V_29 ;
} else {
V_24 = V_27 - V_11 -> exp . V_37 - 6 - V_30 ;
V_29 = ( V_11 -> exp . V_37 + 5 + V_26 - 1 ) / V_26 ;
V_25 = V_27 - V_29 * V_26 - 1 ;
}
if ( V_24 < 0 )
V_24 = 0 ;
else if ( V_24 > V_25 )
V_24 = V_25 ;
if ( F_10 ( V_1 ) ) {
exp [ 0 ] = V_38 ;
exp [ 1 ] = 0x00 ;
exp [ 2 ] = V_39 ;
exp [ 3 ] = V_23 & 0xff ;
exp [ 4 ] = V_40 ;
exp [ 5 ] = V_23 >> 8 ;
exp [ 6 ] = V_41 ;
exp [ 7 ] = ( V_24 >> 2 ) & 0xff ;
exp [ 8 ] = V_42 ;
exp [ 9 ] = 0x10 ;
exp [ 10 ] = V_38 ;
exp [ 11 ] = 0x04 ;
V_20 = F_3 ( V_1 , exp , 6 ) ;
} else {
exp [ 0 ] = V_43 ;
exp [ 1 ] = 0x00 ;
exp [ 2 ] = V_39 ;
exp [ 3 ] = V_23 & 0xff ;
exp [ 4 ] = V_40 ;
exp [ 5 ] = V_23 >> 8 ;
exp [ 6 ] = V_44 ;
exp [ 7 ] = V_24 & 0xff ;
exp [ 8 ] = V_45 ;
exp [ 9 ] = V_24 >> 8 ;
exp [ 10 ] = V_46 ;
exp [ 11 ] = 0x10 ;
exp [ 12 ] = V_43 ;
exp [ 13 ] = 0x04 ;
V_20 = F_3 ( V_1 , exp , 7 ) ;
if ( V_20 < 0 )
return V_20 ;
}
F_11 ( V_47 , L_1 ,
V_13 , V_23 , V_24 ) ;
return V_20 ;
}
static int F_12 ( struct V_1 * V_1 , T_1 V_48 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
int V_20 ;
T_1 V_49 [ 4 ] ;
V_11 -> V_50 = V_48 ;
if ( V_48 > 127 )
V_48 = 0x80 | ( V_48 / 2 ) ;
V_49 [ 0 ] = V_48 ;
V_49 [ 1 ] = V_48 ;
V_49 [ 2 ] = V_48 ;
V_49 [ 3 ] = V_48 ;
V_20 = F_1 ( V_1 , V_51 , V_49 , 4 ) ;
return V_20 ;
}
static int F_13 ( struct V_21 * V_21 , T_2 * V_13 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 ;
struct V_11 * V_11 = V_1 -> V_12 ;
* V_13 = V_11 -> V_50 ;
return 0 ;
}
static int F_14 ( struct V_21 * V_21 , T_2 V_13 )
{
F_11 ( V_47 , L_2 , V_13 ) ;
return F_12 ( (struct V_1 * ) V_21 ,
V_13 & 0xff ) ;
}
static int F_15 ( struct V_1 * V_1 ,
unsigned int V_52 , unsigned int V_53 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
T_1 V_54 [ 4 ] ;
unsigned int V_55 , V_56 ;
int V_20 ;
V_52 = ( V_52 + 3 ) & ~ 0x3 ;
V_53 = ( V_53 + 3 ) & ~ 0x3 ;
if ( V_52 > V_11 -> V_57 . V_52 )
V_52 = V_11 -> V_57 . V_52 ;
if ( F_10 ( V_1 ) ) {
if ( V_53 + 2 * V_11 -> V_57 . V_58 + V_59
> V_11 -> V_57 . V_53 )
V_53 = V_11 -> V_57 . V_53 - 2 * V_11 -> V_57 . V_58 -
V_59 ;
V_56 = ( V_11 -> V_57 . V_53 - V_59 - V_53 ) / 2
+ V_11 -> V_57 . V_60 ;
} else {
if ( V_53 > V_11 -> V_57 . V_53 )
V_53 = V_11 -> V_57 . V_53 ;
V_56 = V_11 -> V_57 . V_60 + ( V_11 -> V_57 . V_53 - V_53 ) / 2 ;
}
V_55 = V_11 -> V_57 . V_61 + ( V_11 -> V_57 . V_52 - V_52 ) / 2 ;
V_54 [ 0 ] = V_56 / 4 ;
V_54 [ 1 ] = V_55 / 4 ;
V_54 [ 2 ] = ( V_56 + V_53 ) / 4 - 1 ;
V_54 [ 3 ] = ( V_55 + V_52 ) / 4 - 1 ;
V_20 = F_1 ( V_1 , V_62 , V_54 , 4 ) ;
if ( V_20 < 0 )
return V_20 ;
V_11 -> V_35 = V_52 ;
V_11 -> V_63 = V_53 ;
return V_20 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_11 * V_11 ;
T_3 V_64 ;
int V_14 ;
V_14 = F_17 ( V_1 , V_65 , & V_64 ) ;
if ( V_14 < 0 || V_64 != 0x08 )
return - V_66 ;
F_18 ( L_3 ) ;
V_1 -> V_21 . V_67 . V_68 = V_69 ;
V_1 -> V_21 . V_67 . V_70 = F_19 ( V_69 ) ;
V_1 -> V_71 . V_72 = V_73 ;
V_1 -> V_71 . V_74 = F_19 ( V_73 ) ;
V_11 = F_20 ( sizeof( struct V_11 ) , V_75 ) ;
if ( ! V_11 )
return - V_76 ;
V_11 -> V_57 . V_61 = 8 ;
V_11 -> V_57 . V_60 = 8 ;
V_11 -> V_57 . V_52 = V_77 ;
V_11 -> V_57 . V_53 = V_78 ;
V_11 -> V_57 . V_58 = 4 ;
V_11 -> exp . V_32 = 4 ;
V_11 -> exp . V_79 = 2 ;
V_11 -> exp . V_36 = 186 ;
V_11 -> exp . V_37 = 100 ;
V_11 -> V_33 = ( V_1 -> V_80 == V_81 ) ? 20 : 5 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_11 * V_11 ;
T_3 V_64 ;
int V_14 ;
V_14 = F_17 ( V_1 , V_65 , & V_64 ) ;
if ( V_14 < 0 || V_64 != 0x10 )
return - V_66 ;
F_18 ( L_4 ) ;
V_1 -> V_21 . V_67 . V_68 = V_82 ;
V_1 -> V_21 . V_67 . V_70 = F_19 ( V_82 ) ;
V_1 -> V_71 . V_72 = V_83 ;
V_1 -> V_71 . V_74 = F_19 ( V_83 ) ;
V_11 = F_20 ( sizeof( struct V_11 ) , V_75 ) ;
if ( ! V_11 )
return - V_76 ;
V_11 -> V_57 . V_61 = 24 ;
V_11 -> V_57 . V_60 = 4 ;
V_11 -> V_57 . V_52 = V_84 ;
V_11 -> V_57 . V_53 = 304 ;
V_11 -> V_57 . V_58 = 4 ;
V_11 -> V_33 = 6 ;
V_11 -> exp . V_32 = 3 ;
V_11 -> exp . V_79 = 3 ;
V_11 -> exp . V_36 = 155 ;
V_11 -> exp . V_37 = 96 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
F_11 ( V_85 , L_5 ) ;
return F_4 ( V_1 , V_18 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
F_11 ( V_85 , L_6 ) ;
return F_4 ( V_1 , V_16 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
F_11 ( V_86 , L_7 ) ;
F_25 ( V_1 -> V_12 ) ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
int V_7 , V_20 = 0 ;
if ( V_1 -> V_80 == V_81 )
F_27 ( V_1 , V_87 , 1 ) ;
for ( V_7 = 0 ; V_7 < F_19 ( V_88 ) && ! V_20 ; V_7 ++ ) {
V_20 = F_27 ( V_1 , V_88 [ V_7 ] [ 0 ] ,
V_88 [ V_7 ] [ 1 ] ) ;
}
if ( V_20 < 0 )
return V_20 ;
F_7 ( V_1 ) ;
for ( V_7 = 0 ; V_7 < F_19 ( V_89 ) && ! V_20 ; V_7 ++ ) {
V_20 = F_5 ( V_1 , V_89 [ V_7 ] [ 0 ] ,
V_89 [ V_7 ] [ 1 ] ) ;
}
if ( V_20 < 0 )
return V_20 ;
V_20 = F_5 ( V_1 , F_28 ( V_1 ) , F_29 ( 3 ) ) ;
if ( V_20 < 0 )
return V_20 ;
if ( F_10 ( V_1 ) )
V_20 = F_5 ( V_1 , V_90 ,
( V_34 << 6 ) | V_11 -> V_33 ) ;
else
V_20 = F_5 ( V_1 , V_90 ,
( V_34 << 5 ) | V_11 -> V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_12 ( V_1 , V_91 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_15 ( V_1 , V_11 -> V_57 . V_52 , V_11 -> V_57 . V_53 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_9 ( & V_1 -> V_21 , V_92 ) ;
return V_20 ;
}
static int F_30 ( struct V_1 * V_1 )
{
T_3 V_2 , V_13 ;
F_18 ( L_8 ) ;
for ( V_2 = V_65 ; V_2 <= V_40 ; V_2 ++ ) {
F_17 ( V_1 , V_2 , & V_13 ) ;
F_18 ( L_9 , V_2 , V_13 ) ;
}
return 0 ;
}
