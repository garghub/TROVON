static bool F_1 ( struct V_1 * V_2 ,
int V_3 , int * V_4 , int * V_5 )
{
int V_6 ;
bool V_7 = false ;
int V_8 = V_2 -> V_9 [ V_10 - 1 ] ;
int V_11 = V_10 - 1 ;
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_2 -> V_9 [ V_6 ] ] == V_3 ) {
V_8 = V_2 -> V_9 [ V_6 ] ;
V_11 = V_6 ;
V_7 = true ;
goto V_13;
}
}
V_13:
for ( V_6 = V_11 ; V_6 > 0 ; V_6 -- )
V_2 -> V_9 [ V_6 ] = V_2 -> V_9 [ V_6 - 1 ] ;
V_2 -> V_9 [ 0 ] = V_8 ;
* V_5 = V_8 ;
* V_4 = V_14 + V_8 ;
return V_7 ;
}
static int F_2 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_17 -> V_21 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_1 ,
V_17 -> V_21 , V_19 ) ;
return V_19 ;
}
return V_18 & V_23 ;
}
static int F_6 ( struct V_15 * V_16 ,
unsigned V_24 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
int V_19 ;
bool V_7 = false ;
int V_4 = V_17 -> V_21 ;
int V_5 = V_17 -> V_25 ;
if ( V_17 -> V_26 )
V_7 = F_1 ( V_17 , V_24 ,
& V_4 , & V_5 ) ;
if ( ! V_7 ) {
V_19 = F_7 ( V_17 -> V_20 , V_4 ,
V_23 , V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_2 ,
V_4 , V_19 ) ;
return V_19 ;
}
V_17 -> V_21 = V_4 ;
V_17 -> V_12 [ V_5 ] = V_24 ;
}
if ( V_17 -> V_26 ) {
F_8 ( V_17 -> V_27 , V_5 & 0x1 ) ;
V_17 -> V_25 = V_5 ;
}
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , unsigned int V_28 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
int V_19 ;
int V_29 ;
switch ( V_28 ) {
case V_30 :
V_29 = V_31 ;
break;
case V_32 :
V_29 = 0 ;
break;
default:
return - V_33 ;
}
V_19 = F_7 ( V_17 -> V_20 , V_34 ,
V_31 , V_29 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_2 ,
V_34 , V_19 ) ;
return V_19 ;
}
static unsigned int F_10 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_34 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_3 ,
V_34 , V_19 ) ;
return V_19 ;
}
return ( V_18 & V_31 ) ?
V_30 : V_32 ;
}
static int F_11 ( struct V_1 * V_17 ,
struct V_35 * V_36 )
{
int V_19 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
if ( V_36 -> V_39 & V_40 )
V_37 |= V_41 ;
if ( ! ( V_36 -> V_39 & V_42 ) )
V_37 |= V_43 ;
if ( V_36 -> V_39 & V_44 )
V_37 |= V_45 ;
if ( V_36 -> V_39 & V_46 )
V_37 |= V_47 ;
if ( V_36 -> V_39 & V_48 )
V_37 |= V_49 ;
if ( V_36 -> V_50 &&
V_36 -> V_50 -> V_51 . V_52 ) {
if ( V_36 -> V_50 -> V_51 . V_52 < 25000 )
V_37 |= V_53 ;
else if ( V_36 -> V_50 -> V_51 . V_52 < 50000 )
V_37 |= V_54 ;
else if ( V_36 -> V_50 -> V_51 . V_52 < 200000 )
V_37 |= V_55 ;
else
V_37 |= V_56 ;
} else {
V_37 |= V_53 ;
V_17 -> V_57 . V_52 = 12500 ;
}
if ( ! ( V_36 -> V_39 & V_58 ) )
V_38 |= V_59 ;
switch ( V_36 -> V_39 & V_60 ) {
case V_61 :
V_38 |= V_62 ;
break;
case V_63 :
V_38 |= V_64 ;
break;
case V_65 :
V_38 |= V_66 ;
break;
case V_67 :
V_38 |= V_68 ;
break;
}
switch ( V_36 -> V_39 & V_69 ) {
case V_70 :
V_38 |= V_71 ;
break;
case V_72 :
V_38 |= V_73 ;
break;
case V_74 :
V_38 |= V_75 ;
break;
case V_76 :
V_38 |= V_77 ;
break;
}
V_19 = F_12 ( V_17 -> V_20 , V_34 , V_37 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_4 ,
V_34 , V_19 ) ;
return V_19 ;
}
V_19 = F_12 ( V_17 -> V_20 , V_78 , V_38 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_4 ,
V_78 , V_19 ) ;
return V_19 ;
}
if ( V_17 -> V_79 ) {
V_19 = F_7 ( V_17 -> V_20 , V_14 ,
V_80 , 0 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_5 ,
V_14 , V_19 ) ;
}
return V_19 ;
}
static int F_13 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_35 * V_36 ;
struct V_85 V_86 = { } ;
struct V_15 * V_16 ;
struct V_1 * V_17 ;
int V_19 ;
V_36 = F_14 ( & V_82 -> V_22 ) ;
if ( ! V_36 && ! V_82 -> V_22 . V_87 ) {
F_5 ( & V_82 -> V_22 , L_6 ) ;
return - V_88 ;
}
V_17 = F_15 ( & V_82 -> V_22 , sizeof( * V_17 ) , V_89 ) ;
if ( ! V_17 )
return - V_90 ;
V_17 -> V_20 = F_16 ( V_82 , & V_91 ) ;
if ( F_17 ( V_17 -> V_20 ) ) {
V_19 = F_18 ( V_17 -> V_20 ) ;
F_5 ( & V_82 -> V_22 , L_7 , V_19 ) ;
return V_19 ;
}
F_19 ( V_82 , V_17 ) ;
V_17 -> V_92 = V_93 ;
V_17 -> V_22 = & V_82 -> V_22 ;
V_17 -> V_57 . V_94 = V_84 -> V_94 ;
V_17 -> V_57 . V_84 = 0 ;
V_17 -> V_57 . V_92 = & V_17 -> V_92 ;
V_17 -> V_57 . type = V_95 ;
V_17 -> V_57 . V_96 = V_97 ;
V_17 -> V_57 . V_98 = V_99 ;
V_17 -> V_57 . V_100 = V_101 ;
V_17 -> V_57 . V_102 = V_103 ;
if ( ! V_36 || ! V_36 -> V_104 ) {
V_17 -> V_57 . V_105 = V_14 ;
V_17 -> V_57 . V_106 = V_80 ;
V_17 -> V_92 . V_107 = V_108 ;
V_17 -> V_92 . V_109 = V_110 ;
V_17 -> V_92 . V_111 = V_112 ;
}
if ( V_36 ) {
V_17 -> V_27 = V_36 -> V_27 ;
V_17 -> V_79 = V_36 -> V_104 ;
V_17 -> V_25 = V_36 -> V_113 ;
V_17 -> V_21 = V_14 + V_36 -> V_113 ;
} else {
V_17 -> V_27 = - V_33 ;
V_17 -> V_21 = V_14 ;
}
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
if ( F_20 ( V_17 -> V_27 ) ) {
int V_114 ;
int V_6 ;
V_114 = ( V_36 -> V_113 ) ?
V_115 : V_116 ;
V_19 = F_21 ( & V_82 -> V_22 , V_17 -> V_27 ,
V_114 , L_8 ) ;
if ( V_19 ) {
F_5 ( & V_82 -> V_22 ,
L_9 ,
V_17 -> V_27 , V_19 ) ;
return V_19 ;
}
V_17 -> V_26 = true ;
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 )
V_17 -> V_9 [ V_6 ] = V_6 ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
V_17 -> V_9 [ V_17 -> V_21 ] = 0 ;
} else {
V_17 -> V_26 = false ;
}
if ( V_36 ) {
V_19 = F_11 ( V_17 , V_36 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_10 , V_19 ) ;
return V_19 ;
}
}
V_86 . V_22 = & V_82 -> V_22 ;
V_86 . V_117 = V_36 ? V_36 -> V_50 :
F_22 ( & V_82 -> V_22 , V_82 -> V_22 . V_87 ) ;
V_86 . V_118 = V_17 ;
V_86 . V_87 = V_82 -> V_22 . V_87 ;
V_86 . V_20 = V_17 -> V_20 ;
V_16 = F_23 ( & V_82 -> V_22 , & V_17 -> V_57 , & V_86 ) ;
if ( F_17 ( V_16 ) ) {
V_19 = F_18 ( V_16 ) ;
F_5 ( V_17 -> V_22 , L_11 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_119 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_119 ) ;
}
