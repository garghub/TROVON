static inline int F_1 ( int V_1 )
{
T_1 V_2 = ( ( T_1 ) V_1 ) >> 11 ;
T_2 V_3 = ( ( ( T_1 ) ( V_1 << 5 ) ) >> 5 ) ;
V_2 += 6 ;
return ( V_2 < 0 ? V_3 > > - V_2 : V_3 << V_2 ) ;
}
static int F_2 ( struct V_4 * V_5 , int V_6 ,
int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_12 :
V_11 = F_5 ( V_5 , V_6 , V_13 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 ) > F_1 ( V_1 -> V_14 ) )
V_1 -> V_14 = V_11 ;
V_11 = V_1 -> V_14 ;
}
break;
case V_15 :
V_11 = F_5 ( V_5 , V_6 , V_16 ) ;
if ( V_11 >= 0 ) {
if ( V_11 > V_1 -> V_17 [ V_6 ] )
V_1 -> V_17 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_17 [ V_6 ] ;
}
break;
case V_18 :
V_11 = F_5 ( V_5 , V_6 ,
V_19 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
> F_1 ( V_1 -> V_20 [ V_6 ] ) )
V_1 -> V_20 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_20 [ V_6 ] ;
}
break;
case V_21 :
case V_22 :
case V_23 :
V_11 = 0 ;
break;
default:
V_11 = - V_24 ;
break;
}
return V_11 ;
}
static int F_6 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_25 :
V_11 = F_5 ( V_5 , V_6 , V_26 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 ) < F_1 ( V_1 -> V_27 ) )
V_1 -> V_27 = V_11 ;
V_11 = V_1 -> V_27 ;
}
break;
case V_28 :
V_11 = F_5 ( V_5 , V_6 , V_29 ) ;
if ( V_11 >= 0 ) {
if ( V_1 -> V_17 [ V_6 ] && V_11 > V_1 -> V_17 [ V_6 ] )
V_11 = V_1 -> V_17 [ V_6 ] ;
if ( V_11 < V_1 -> V_30 [ V_6 ] )
V_1 -> V_30 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_30 [ V_6 ] ;
}
break;
case V_31 :
V_11 = F_5 ( V_5 , V_6 ,
V_32 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
< F_1 ( V_1 -> V_33 [ V_6 ] ) )
V_1 -> V_33 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_33 [ V_6 ] ;
}
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_11 = - V_38 ;
break;
default:
V_11 = F_2 ( V_5 , V_6 , V_7 ) ;
break;
}
return V_11 ;
}
static int F_7 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_34 :
V_11 = F_5 ( V_5 , V_6 , V_39 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
> F_1 ( V_1 -> V_40 [ V_6 ] ) )
V_1 -> V_40 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_40 [ V_6 ] ;
}
break;
case V_41 :
V_11 = F_5 ( V_5 , V_6 , V_42 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
< F_1 ( V_1 -> V_43 [ V_6 ] ) )
V_1 -> V_43 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_43 [ V_6 ] ;
}
break;
case V_35 :
V_11 = 0 ;
break;
default:
V_11 = F_6 ( V_5 , V_6 , V_7 ) ;
break;
}
return V_11 ;
}
static int F_8 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_34 :
V_11 = F_5 ( V_5 , V_6 , V_44 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
> F_1 ( V_1 -> V_40 [ V_6 ] ) )
V_1 -> V_40 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_40 [ V_6 ] ;
}
break;
case V_36 :
V_11 = F_5 ( V_5 , V_6 ,
V_45 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 ) > F_1 ( V_1 -> V_46 ) )
V_1 -> V_46 = V_11 ;
V_11 = V_1 -> V_46 ;
}
break;
case V_25 :
case V_28 :
case V_31 :
V_11 = - V_38 ;
break;
case V_35 :
case V_37 :
V_11 = 0 ;
break;
default:
V_11 = F_2 ( V_5 , V_6 , V_7 ) ;
break;
}
return V_11 ;
}
static int F_9 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_47 :
V_11 = F_5 ( V_5 , V_6 , V_48 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
> F_1 ( V_1 -> V_49 ) )
V_1 -> V_49 = V_11 ;
V_11 = V_1 -> V_49 ;
}
break;
case V_50 :
V_11 = 0 ;
break;
default:
V_11 = F_8 ( V_5 , V_6 , V_7 ) ;
break;
}
return V_11 ;
}
static int F_10 ( struct V_4 * V_5 , int V_6 ,
enum V_51 V_52 )
{
int V_11 ;
if ( V_52 == V_53 || V_52 == V_54 )
V_11 = F_11 ( V_5 , 0 , V_55 ) ;
else
V_11 = F_11 ( V_5 , V_6 , V_56 ) ;
return V_11 ;
}
static int F_12 ( struct V_4 * V_5 , int V_6 ,
int V_7 , T_3 V_57 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_50 :
V_1 -> V_49 = 0x7c00 ;
V_11 = F_10 ( V_5 , V_6 , V_1 -> V_52 ) ;
break;
case V_35 :
V_1 -> V_40 [ V_6 ] = 0x7c00 ;
V_1 -> V_43 [ V_6 ] = 0xfbff ;
V_11 = F_10 ( V_5 , V_6 , V_1 -> V_52 ) ;
break;
case V_37 :
V_1 -> V_46 = 0x7c00 ;
V_11 = F_10 ( V_5 , V_6 , V_1 -> V_52 ) ;
break;
case V_21 :
V_1 -> V_30 [ V_6 ] = 0xffff ;
V_1 -> V_17 [ V_6 ] = 0 ;
V_11 = F_10 ( V_5 , V_6 , V_1 -> V_52 ) ;
break;
case V_22 :
V_1 -> V_27 = 0x7bff ;
V_1 -> V_14 = 0x7c00 ;
V_11 = F_10 ( V_5 , V_6 , V_1 -> V_52 ) ;
break;
case V_23 :
V_1 -> V_33 [ V_6 ] = 0x7bff ;
V_1 -> V_20 [ V_6 ] = 0x7c00 ;
V_11 = F_10 ( V_5 , V_6 , V_1 -> V_52 ) ;
break;
default:
V_11 = - V_24 ;
break;
}
return V_11 ;
}
static int F_13 ( struct V_4 * V_5 ,
const struct V_58 * V_52 )
{
int V_59 , V_60 ;
struct V_10 * V_1 ;
struct V_8 * V_9 ;
if ( ! F_14 ( V_5 -> V_61 ,
V_62 ) )
return - V_63 ;
V_1 = F_15 ( & V_5 -> V_64 , sizeof( struct V_10 ) ,
V_65 ) ;
if ( ! V_1 )
return - V_66 ;
V_59 = F_16 ( V_5 , V_67 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 == V_68 ) {
V_1 -> V_52 = V_69 ;
} else if ( V_59 == V_70 ) {
V_1 -> V_52 = V_71 ;
} else if ( V_59 == V_72 || V_59 == V_73 ||
V_59 == V_74 ) {
V_1 -> V_52 = V_75 ;
} else if ( ( V_59 & V_76 ) == V_77 ) {
V_1 -> V_52 = V_53 ;
} else if ( ( V_59 & V_78 ) == V_79 ) {
V_1 -> V_52 = V_54 ;
} else {
F_17 ( & V_5 -> V_64 , L_1 , V_59 ) ;
return - V_63 ;
}
if ( V_1 -> V_52 != V_52 -> V_80 )
F_18 ( & V_5 -> V_64 ,
L_2 ,
V_52 -> V_81 ,
V_82 [ V_1 -> V_52 ] . V_81 ) ;
V_9 = & V_1 -> V_9 ;
V_9 -> V_83 = F_12 ;
V_1 -> V_27 = 0x7bff ;
V_1 -> V_14 = 0x7c00 ;
for ( V_60 = 0 ; V_60 < F_19 ( V_1 -> V_30 ) ; V_60 ++ )
V_1 -> V_30 [ V_60 ] = 0xffff ;
for ( V_60 = 0 ; V_60 < F_19 ( V_1 -> V_43 ) ; V_60 ++ )
V_1 -> V_43 [ V_60 ] = 0xfbff ;
for ( V_60 = 0 ; V_60 < F_19 ( V_1 -> V_40 ) ; V_60 ++ )
V_1 -> V_40 [ V_60 ] = 0x7c00 ;
for ( V_60 = 0 ; V_60 < F_19 ( V_1 -> V_33 ) ; V_60 ++ )
V_1 -> V_33 [ V_60 ] = 0x7bff ;
for ( V_60 = 0 ; V_60 < F_19 ( V_1 -> V_20 ) ; V_60 ++ )
V_1 -> V_20 [ V_60 ] = 0x7c00 ;
V_1 -> V_46 = 0x7c00 ;
switch ( V_1 -> V_52 ) {
case V_69 :
V_9 -> V_84 = F_7 ;
V_9 -> V_85 = V_86 ;
V_9 -> V_87 [ 0 ] = V_88 | V_89
| V_90 ;
for ( V_60 = 0 ; V_60 < V_9 -> V_85 ; V_60 ++ ) {
V_9 -> V_87 [ V_60 ] |= V_91
| V_92 | V_93
| V_94 | V_95
| V_96 | V_97 ;
}
break;
case V_71 :
case V_75 :
V_9 -> V_84 = F_6 ;
V_9 -> V_85 = V_98 ;
V_9 -> V_87 [ 0 ] = V_88 | V_89
| V_91 | V_92
| V_94 | V_95 ;
for ( V_60 = 1 ; V_60 < V_98 ; V_60 ++ ) {
V_9 -> V_87 [ V_60 ] = V_91
| V_92 ;
}
break;
case V_53 :
V_9 -> V_84 = F_8 ;
V_9 -> V_85 = V_99 ;
V_9 -> V_87 [ 0 ] = V_88 | V_100
| V_89
| V_91 | V_92
| V_96 | V_97
| V_93 | V_94
| V_90 | V_95 ;
V_9 -> V_87 [ 1 ] = V_91 | V_92
| V_96 | V_97
| V_93
| V_94 | V_95 ;
break;
case V_54 :
V_9 -> V_84 = F_9 ;
V_9 -> V_85 = V_101 ;
V_9 -> V_87 [ 0 ] = V_88 | V_100
| V_89
| V_91 | V_92
| V_96 | V_97
| V_102 | V_93 | V_94
| V_90 | V_95 ;
break;
default:
return - V_63 ;
}
return F_20 ( V_5 , V_52 , V_9 ) ;
}
