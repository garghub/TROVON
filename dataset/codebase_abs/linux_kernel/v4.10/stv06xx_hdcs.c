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
static int F_8 ( struct V_21 * V_21 , T_2 V_13 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 ;
struct V_11 * V_11 = V_1 -> V_12 ;
int V_22 , V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 , V_20 ;
T_1 exp [ 14 ] ;
V_29 = V_13 * V_30 * 257 ;
V_25 = V_11 -> exp . V_31 + V_11 -> V_32 + ( V_33 + 2 ) ;
V_26 = V_11 -> exp . V_31 + ( V_11 -> V_34 * V_25 / 2 ) ;
V_27 = V_11 -> exp . V_35 + V_26 ;
V_22 = V_29 / V_27 ;
V_29 -= V_22 * V_27 ;
if ( F_9 ( V_1 ) ) {
V_23 = V_11 -> V_34 - ( V_29 + V_11 -> exp . V_36 + 13 ) / V_25 ;
V_28 = ( V_11 -> exp . V_36 + 12 + V_25 - 1 ) / V_25 ;
V_24 = V_11 -> V_34 - V_28 ;
} else {
V_23 = V_26 - V_11 -> exp . V_36 - 6 - V_29 ;
V_28 = ( V_11 -> exp . V_36 + 5 + V_25 - 1 ) / V_25 ;
V_24 = V_26 - V_28 * V_25 - 1 ;
}
if ( V_23 < 0 )
V_23 = 0 ;
else if ( V_23 > V_24 )
V_23 = V_24 ;
if ( F_9 ( V_1 ) ) {
exp [ 0 ] = V_37 ;
exp [ 1 ] = 0x00 ;
exp [ 2 ] = V_38 ;
exp [ 3 ] = V_22 & 0xff ;
exp [ 4 ] = V_39 ;
exp [ 5 ] = V_22 >> 8 ;
exp [ 6 ] = V_40 ;
exp [ 7 ] = ( V_23 >> 2 ) & 0xff ;
exp [ 8 ] = V_41 ;
exp [ 9 ] = 0x10 ;
exp [ 10 ] = V_37 ;
exp [ 11 ] = 0x04 ;
V_20 = F_3 ( V_1 , exp , 6 ) ;
} else {
exp [ 0 ] = V_42 ;
exp [ 1 ] = 0x00 ;
exp [ 2 ] = V_38 ;
exp [ 3 ] = V_22 & 0xff ;
exp [ 4 ] = V_39 ;
exp [ 5 ] = V_22 >> 8 ;
exp [ 6 ] = V_43 ;
exp [ 7 ] = V_23 & 0xff ;
exp [ 8 ] = V_44 ;
exp [ 9 ] = V_23 >> 8 ;
exp [ 10 ] = V_45 ;
exp [ 11 ] = 0x10 ;
exp [ 12 ] = V_42 ;
exp [ 13 ] = 0x04 ;
V_20 = F_3 ( V_1 , exp , 7 ) ;
if ( V_20 < 0 )
return V_20 ;
}
F_10 ( V_46 , L_1 ,
V_13 , V_22 , V_23 ) ;
return V_20 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_47 )
{
int V_20 ;
T_1 V_48 [ 4 ] ;
if ( V_47 > 127 )
V_47 = 0x80 | ( V_47 / 2 ) ;
V_48 [ 0 ] = V_47 ;
V_48 [ 1 ] = V_47 ;
V_48 [ 2 ] = V_47 ;
V_48 [ 3 ] = V_47 ;
V_20 = F_1 ( V_1 , V_49 , V_48 , 4 ) ;
return V_20 ;
}
static int F_12 ( struct V_21 * V_21 , T_2 V_13 )
{
F_10 ( V_46 , L_2 , V_13 ) ;
return F_11 ( (struct V_1 * ) V_21 ,
V_13 & 0xff ) ;
}
static int F_13 ( struct V_1 * V_1 ,
unsigned int V_50 , unsigned int V_51 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
T_1 V_52 [ 4 ] ;
unsigned int V_53 , V_54 ;
int V_20 ;
V_50 = ( V_50 + 3 ) & ~ 0x3 ;
V_51 = ( V_51 + 3 ) & ~ 0x3 ;
if ( V_50 > V_11 -> V_55 . V_50 )
V_50 = V_11 -> V_55 . V_50 ;
if ( F_9 ( V_1 ) ) {
if ( V_51 + 2 * V_11 -> V_55 . V_56 + V_57
> V_11 -> V_55 . V_51 )
V_51 = V_11 -> V_55 . V_51 - 2 * V_11 -> V_55 . V_56 -
V_57 ;
V_54 = ( V_11 -> V_55 . V_51 - V_57 - V_51 ) / 2
+ V_11 -> V_55 . V_58 ;
} else {
if ( V_51 > V_11 -> V_55 . V_51 )
V_51 = V_11 -> V_55 . V_51 ;
V_54 = V_11 -> V_55 . V_58 + ( V_11 -> V_55 . V_51 - V_51 ) / 2 ;
}
V_53 = V_11 -> V_55 . V_59 + ( V_11 -> V_55 . V_50 - V_50 ) / 2 ;
V_52 [ 0 ] = V_54 / 4 ;
V_52 [ 1 ] = V_53 / 4 ;
V_52 [ 2 ] = ( V_54 + V_51 ) / 4 - 1 ;
V_52 [ 3 ] = ( V_53 + V_50 ) / 4 - 1 ;
V_20 = F_1 ( V_1 , V_60 , V_52 , 4 ) ;
if ( V_20 < 0 )
return V_20 ;
V_11 -> V_34 = V_50 ;
V_11 -> V_61 = V_51 ;
return V_20 ;
}
static int F_14 ( struct V_62 * V_63 )
{
struct V_21 * V_21 =
F_15 ( V_63 -> V_64 , struct V_21 , V_65 ) ;
int V_20 = - V_8 ;
switch ( V_63 -> V_66 ) {
case V_67 :
V_20 = F_12 ( V_21 , V_63 -> V_13 ) ;
break;
case V_68 :
V_20 = F_8 ( V_21 , V_63 -> V_13 ) ;
break;
}
return V_20 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_69 * V_70 = & V_1 -> V_21 . V_65 ;
F_17 ( V_70 , 2 ) ;
F_18 ( V_70 , & V_71 ,
V_68 , 0 , 0xff , 1 , V_72 ) ;
F_18 ( V_70 , & V_71 ,
V_67 , 0 , 0xff , 1 , V_73 ) ;
return V_70 -> error ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_11 * V_11 ;
T_3 V_74 ;
int V_14 ;
V_14 = F_20 ( V_1 , V_75 , & V_74 ) ;
if ( V_14 < 0 || V_74 != 0x08 )
return - V_76 ;
F_21 ( L_3 ) ;
V_1 -> V_21 . V_77 . V_78 = V_79 ;
V_1 -> V_21 . V_77 . V_80 = F_22 ( V_79 ) ;
V_11 = F_23 ( sizeof( struct V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
V_11 -> V_55 . V_59 = 8 ;
V_11 -> V_55 . V_58 = 8 ;
V_11 -> V_55 . V_50 = V_83 ;
V_11 -> V_55 . V_51 = V_84 ;
V_11 -> V_55 . V_56 = 4 ;
V_11 -> exp . V_31 = 4 ;
V_11 -> exp . V_85 = 2 ;
V_11 -> exp . V_35 = 186 ;
V_11 -> exp . V_36 = 100 ;
V_11 -> V_32 = ( V_1 -> V_86 == V_87 ) ? 20 : 5 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_11 * V_11 ;
T_3 V_74 ;
int V_14 ;
V_14 = F_20 ( V_1 , V_75 , & V_74 ) ;
if ( V_14 < 0 || V_74 != 0x10 )
return - V_76 ;
F_21 ( L_4 ) ;
V_1 -> V_21 . V_77 . V_78 = V_88 ;
V_1 -> V_21 . V_77 . V_80 = F_22 ( V_88 ) ;
V_11 = F_23 ( sizeof( struct V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
V_11 -> V_55 . V_59 = 24 ;
V_11 -> V_55 . V_58 = 4 ;
V_11 -> V_55 . V_50 = V_89 ;
V_11 -> V_55 . V_51 = 304 ;
V_11 -> V_55 . V_56 = 4 ;
V_11 -> V_32 = 6 ;
V_11 -> exp . V_31 = 3 ;
V_11 -> exp . V_85 = 3 ;
V_11 -> exp . V_35 = 155 ;
V_11 -> exp . V_36 = 96 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
F_10 ( V_90 , L_5 ) ;
return F_4 ( V_1 , V_18 ) ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
F_10 ( V_90 , L_6 ) ;
return F_4 ( V_1 , V_16 ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = V_1 -> V_12 ;
int V_7 , V_20 = 0 ;
if ( V_1 -> V_86 == V_87 )
F_28 ( V_1 , V_91 , 1 ) ;
for ( V_7 = 0 ; V_7 < F_22 ( V_92 ) && ! V_20 ; V_7 ++ ) {
V_20 = F_28 ( V_1 , V_92 [ V_7 ] [ 0 ] ,
V_92 [ V_7 ] [ 1 ] ) ;
}
if ( V_20 < 0 )
return V_20 ;
F_7 ( V_1 ) ;
for ( V_7 = 0 ; V_7 < F_22 ( V_93 ) && ! V_20 ; V_7 ++ ) {
V_20 = F_5 ( V_1 , V_93 [ V_7 ] [ 0 ] ,
V_93 [ V_7 ] [ 1 ] ) ;
}
if ( V_20 < 0 )
return V_20 ;
V_20 = F_5 ( V_1 , F_29 ( V_1 ) , F_30 ( 3 ) ) ;
if ( V_20 < 0 )
return V_20 ;
if ( F_9 ( V_1 ) )
V_20 = F_5 ( V_1 , V_94 ,
( V_33 << 6 ) | V_11 -> V_32 ) ;
else
V_20 = F_5 ( V_1 , V_94 ,
( V_33 << 5 ) | V_11 -> V_32 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_13 ( V_1 , V_11 -> V_55 . V_50 , V_11 -> V_55 . V_51 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
T_3 V_2 , V_13 ;
F_21 ( L_7 ) ;
for ( V_2 = V_75 ; V_2 <= V_39 ; V_2 ++ ) {
F_20 ( V_1 , V_2 , & V_13 ) ;
F_21 ( L_8 , V_2 , V_13 ) ;
}
return 0 ;
}
