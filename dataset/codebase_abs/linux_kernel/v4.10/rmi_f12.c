static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
int V_11 ;
int V_12 ;
T_1 V_13 [ 15 ] ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
V_4 = F_2 ( & V_2 -> V_19 , 8 ) ;
if ( ! V_4 ) {
F_3 ( & V_8 -> V_20 ,
L_1 ) ;
return - V_21 ;
}
V_12 = F_4 ( & V_2 -> V_19 , 8 ) ;
if ( V_4 -> V_22 > sizeof( V_13 ) ) {
F_3 ( & V_8 -> V_20 ,
L_2 ,
sizeof( V_13 ) , V_4 -> V_22 ) ;
return - V_21 ;
}
V_11 = F_5 ( V_10 , V_8 -> V_23 . V_24 + V_12 , V_13 ,
V_4 -> V_22 ) ;
if ( V_11 )
return V_11 ;
V_12 = 0 ;
if ( F_6 ( V_4 , 0 ) ) {
V_6 -> V_25 = ( V_13 [ V_12 + 1 ] << 8 ) | V_13 [ V_12 ] ;
V_6 -> V_26 = ( V_13 [ V_12 + 3 ] << 8 ) | V_13 [ V_12 + 2 ] ;
V_12 += 4 ;
}
F_7 ( V_27 , & V_8 -> V_20 , L_3 , V_28 ,
V_6 -> V_25 , V_6 -> V_26 ) ;
if ( F_6 ( V_4 , 1 ) ) {
V_14 = ( V_13 [ V_12 + 1 ] << 8 ) | V_13 [ V_12 ] ;
V_15 = ( V_13 [ V_12 + 3 ] << 8 ) | V_13 [ V_12 + 2 ] ;
V_12 += 4 ;
}
if ( F_6 ( V_4 , 2 ) ) {
V_6 -> V_29 . V_30 = V_13 [ V_12 ] ;
V_6 -> V_29 . V_31 = V_6 -> V_25
- V_13 [ V_12 + 1 ] ;
V_6 -> V_29 . V_32 = V_13 [ V_12 + 2 ] ;
V_6 -> V_29 . V_33 = V_6 -> V_26
- V_13 [ V_12 + 3 ] ;
V_12 += 4 ;
}
F_7 ( V_27 , & V_8 -> V_20 , L_4 ,
V_28 ,
V_6 -> V_29 . V_30 , V_6 -> V_29 . V_31 ,
V_6 -> V_29 . V_32 , V_6 -> V_29 . V_33 ) ;
if ( F_6 ( V_4 , 3 ) ) {
V_16 = V_13 [ V_12 ] ;
V_17 = V_13 [ V_12 + 1 ] ;
V_12 += 2 ;
}
if ( F_6 ( V_4 , 4 ) ) {
V_18 = V_13 [ V_12 ] ;
V_12 += 1 ;
}
V_6 -> V_34 = ( V_14 * V_16 ) >> 12 ;
V_6 -> V_35 = ( V_15 * V_17 ) >> 12 ;
F_7 ( V_27 , & V_8 -> V_20 , L_5 , V_28 ,
V_6 -> V_34 , V_6 -> V_35 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_36 , int V_37 )
{
int V_38 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_39 = V_2 -> V_36 -> V_40 ;
if ( ( V_2 -> V_36 -> V_40 * V_41 ) > V_37 )
V_39 = V_37 / V_41 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
struct V_42 * V_43 = & V_6 -> V_44 [ V_38 ] ;
V_43 -> type = V_45 ;
V_43 -> V_46 = V_47 ;
switch ( V_36 [ 0 ] ) {
case V_48 :
V_43 -> type = V_49 ;
break;
case V_50 :
V_43 -> type = V_51 ;
V_43 -> V_46 = V_52 ;
break;
case V_53 :
V_43 -> type = V_54 ;
V_43 -> V_46 = V_55 ;
break;
case V_56 :
V_43 -> type = V_57 ;
break;
}
V_43 -> V_58 = ( V_36 [ 2 ] << 8 ) | V_36 [ 1 ] ;
V_43 -> V_59 = ( V_36 [ 4 ] << 8 ) | V_36 [ 3 ] ;
V_43 -> V_60 = V_36 [ 5 ] ;
V_43 -> V_61 = V_36 [ 6 ] ;
V_43 -> V_62 = V_36 [ 7 ] ;
F_9 ( V_6 , V_43 , V_38 ) ;
V_36 += V_41 ;
}
if ( V_6 -> V_63 )
F_10 ( V_6 -> V_64 ,
V_6 -> V_65 ,
V_6 -> V_66 ,
V_6 -> V_67 ,
V_6 -> V_68 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_11 ( V_6 , & V_6 -> V_44 [ V_38 ] , V_38 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
unsigned long * V_69 )
{
int V_70 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_71 * V_72 = F_13 ( & V_10 -> V_20 ) ;
struct V_1 * V_2 = F_13 ( & V_8 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_73 = V_6 -> V_74 ;
if ( V_72 -> V_75 . V_76 ) {
if ( V_6 -> V_77 > V_72 -> V_75 . V_37 )
V_73 = V_72 -> V_75 . V_37 ;
else
V_73 = V_6 -> V_77 ;
memcpy ( V_6 -> V_78 , V_72 -> V_75 . V_76 ,
V_73 ) ;
V_72 -> V_75 . V_76 += V_6 -> V_77 ;
V_72 -> V_75 . V_37 -= V_6 -> V_77 ;
} else {
V_70 = F_5 ( V_10 , V_2 -> V_79 ,
V_6 -> V_78 , V_6 -> V_74 ) ;
if ( V_70 < 0 ) {
F_3 ( & V_8 -> V_20 , L_6 ,
V_70 ) ;
return V_70 ;
}
}
if ( V_2 -> V_36 )
F_8 ( V_2 ,
& V_6 -> V_78 [ V_2 -> V_80 ] , V_73 ) ;
F_14 ( V_6 -> V_64 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
int V_11 ;
const struct V_3 * V_4 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_1 * V_2 = F_13 ( & V_8 -> V_20 ) ;
int V_81 ;
char V_13 [ 3 ] ;
T_2 V_82 = 0 ;
T_1 V_83 = 0 ;
if ( V_2 -> V_84
&& ( V_2 -> V_6 . V_85 != V_86 ) ) {
V_4 = F_2 ( & V_2 -> V_19 , 20 ) ;
if ( V_4 ) {
V_82 = F_4 (
& V_2 -> V_19 , 20 ) ;
V_81 = F_16 ( V_4 -> V_22 , 3UL ) ;
V_11 = F_5 ( V_10 , V_8 -> V_23 . V_24
+ V_82 , V_13 , V_81 ) ;
if ( V_11 )
return V_11 ;
if ( F_6 ( V_4 , 0 ) )
V_83 += 1 ;
switch ( V_2 -> V_6 . V_85 ) {
case V_87 :
V_13 [ V_83 ] &= ~ F_17 ( 2 ) ;
break;
case V_88 :
V_13 [ V_83 ] |= F_17 ( 2 ) ;
break;
case V_86 :
default:
break;
}
V_11 = F_18 ( V_10 ,
V_8 -> V_23 . V_24 + V_82 ,
V_13 , V_81 ) ;
if ( V_11 )
return V_11 ;
}
}
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_89 * V_90 = V_8 -> V_10 -> V_91 ;
int V_11 ;
V_90 -> V_92 ( V_8 -> V_10 , V_8 -> V_93 ) ;
V_11 = F_15 ( V_8 ) ;
if ( V_11 )
F_20 ( & V_8 -> V_20 ,
L_7 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_11 ;
struct V_9 * V_10 = V_8 -> V_10 ;
char V_13 ;
T_2 V_94 = V_8 -> V_23 . V_95 ;
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_96 * V_97 = F_22 ( V_10 ) ;
struct V_71 * V_72 = F_13 ( & V_10 -> V_20 ) ;
T_2 V_98 = 0 ;
F_7 ( V_27 , & V_8 -> V_20 , L_8 , V_28 ) ;
V_11 = F_23 ( V_8 -> V_10 , V_94 , & V_13 ) ;
if ( V_11 < 0 ) {
F_3 ( & V_8 -> V_20 , L_9 ,
V_11 ) ;
return - V_21 ;
}
++ V_94 ;
if ( ! ( V_13 & F_17 ( 0 ) ) ) {
F_3 ( & V_8 -> V_20 ,
L_10 ) ;
return - V_21 ;
}
V_2 = F_24 ( & V_8 -> V_20 , sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_84 = ! ! ( V_13 & F_17 ( 3 ) ) ;
if ( V_8 -> V_20 . V_101 ) {
V_11 = F_25 ( & V_8 -> V_20 , & V_2 -> V_102 ) ;
if ( V_11 )
return V_11 ;
} else {
V_2 -> V_102 = V_97 -> V_102 ;
}
V_11 = F_26 ( V_10 , V_94 ,
& V_2 -> V_103 ) ;
if ( V_11 ) {
F_3 ( & V_8 -> V_20 ,
L_11 ,
V_11 ) ;
return V_11 ;
}
V_94 += 3 ;
V_11 = F_26 ( V_10 , V_94 ,
& V_2 -> V_19 ) ;
if ( V_11 ) {
F_3 ( & V_8 -> V_20 ,
L_12 ,
V_11 ) ;
return V_11 ;
}
V_94 += 3 ;
V_11 = F_26 ( V_10 , V_94 ,
& V_2 -> V_104 ) ;
if ( V_11 ) {
F_3 ( & V_8 -> V_20 ,
L_13 ,
V_11 ) ;
return V_11 ;
}
V_94 += 3 ;
V_6 = & V_2 -> V_6 ;
V_6 -> V_8 = V_8 ;
V_2 -> V_79 = V_8 -> V_23 . V_105 ;
V_6 -> V_74 = F_27 ( & V_2 -> V_104 ) ;
V_6 -> V_29 =
V_2 -> V_102 . V_29 ;
V_6 -> V_34 = V_2 -> V_102 . V_34 ;
V_6 -> V_35 = V_2 -> V_102 . V_35 ;
V_6 -> V_85 = V_2 -> V_102 . V_85 ;
if ( V_6 -> V_106 == V_107 )
V_6 -> V_106 =
V_2 -> V_102 . V_106 ;
F_7 ( V_27 , & V_8 -> V_20 , L_14 , V_28 ,
V_6 -> V_74 ) ;
V_6 -> V_78 = F_24 ( & V_8 -> V_20 , V_6 -> V_74 , V_99 ) ;
if ( ! V_6 -> V_78 )
return - V_100 ;
F_28 ( & V_8 -> V_20 , V_2 ) ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_4 = F_2 ( & V_2 -> V_104 , 0 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 1 ) ;
if ( V_4 ) {
V_2 -> V_36 = V_4 ;
V_2 -> V_80 = V_98 ;
V_98 += V_4 -> V_22 ;
V_6 -> V_67 = V_4 -> V_40 ;
V_6 -> V_108 = 1 ;
V_6 -> V_77 += V_4 -> V_22 ;
}
V_4 = F_2 ( & V_2 -> V_104 , 2 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 3 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 4 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 5 ) ;
if ( V_4 ) {
V_2 -> V_109 = V_4 ;
V_2 -> V_110 = V_98 ;
V_98 += V_4 -> V_22 ;
V_6 -> V_77 += V_4 -> V_22 ;
}
V_4 = F_2 ( & V_2 -> V_104 , 6 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 ) {
V_2 -> V_111 = V_4 ;
V_2 -> V_112 = V_98 ;
V_98 += V_4 -> V_22 ;
}
V_4 = F_2 ( & V_2 -> V_104 , 7 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 8 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 9 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 ) {
V_2 -> V_113 = V_4 ;
V_2 -> V_114 = V_98 ;
V_98 += V_4 -> V_22 ;
if ( ! V_6 -> V_108 )
V_6 -> V_115 = 1 ;
}
V_4 = F_2 ( & V_2 -> V_104 , 10 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 11 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 12 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 13 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 14 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 )
V_98 += V_4 -> V_22 ;
V_4 = F_2 ( & V_2 -> V_104 , 15 ) ;
if ( V_4 && ! V_72 -> V_75 . V_76 ) {
V_2 -> V_116 = V_4 ;
V_2 -> V_117 = V_98 ;
V_98 += V_4 -> V_22 ;
}
V_6 -> V_66 = F_24 ( & V_8 -> V_20 ,
sizeof( struct V_118 ) * V_6 -> V_67 ,
V_99 ) ;
V_6 -> V_65 = F_24 ( & V_8 -> V_20 ,
sizeof( int ) * V_6 -> V_67 , V_99 ) ;
V_6 -> V_44 = F_24 ( & V_8 -> V_20 ,
sizeof( struct V_42 )
* V_6 -> V_67 , V_99 ) ;
if ( ! V_6 -> V_66 || ! V_6 -> V_65 || ! V_6 -> V_44 )
return - V_100 ;
V_11 = F_29 ( V_8 , V_6 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
