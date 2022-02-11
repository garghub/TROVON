static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_9 -> V_17 ) {
case 3 :
V_14 = V_18 ;
V_16 = F_4 ( V_18 ) ;
break;
default:
V_14 = V_19 ;
V_16 = F_4 ( V_19 ) ;
break;
}
switch ( V_5 ) {
case V_20 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_5 ( V_12 , V_14 [ V_15 ] . V_21 ,
V_14 [ V_15 ] . V_22 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
struct V_9 * V_9 = V_24 -> V_9 ;
unsigned int V_25 = F_8 ( V_7 , V_26 ) ;
const struct V_27 * V_28 ;
int V_29 ;
switch ( V_2 -> V_30 ) {
case V_31 :
if ( V_25 & V_32 ) {
V_28 = V_33 ;
V_29 = F_4 ( V_33 ) ;
} else {
V_28 = V_34 ;
V_29 = F_4 ( V_34 ) ;
V_24 -> V_35 += 10 ;
}
break;
case V_36 :
if ( V_25 & V_37 ) {
V_28 = V_38 ;
V_29 = F_4 ( V_38 ) ;
} else {
V_28 = V_39 ;
V_29 = F_4 ( V_39 ) ;
V_24 -> V_35 += 10 ;
}
break;
default:
return 0 ;
}
return F_9 ( V_9 -> V_12 , V_28 , V_29 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
unsigned int V_25 = F_8 ( V_7 , V_26 ) ;
switch ( V_2 -> V_30 ) {
case V_31 :
if ( ! ( V_25 & V_32 ) ) {
F_11 ( V_7 , V_40 ,
V_41 , V_41 ) ;
F_11 ( V_7 , V_40 ,
V_41 , 0 ) ;
V_24 -> V_42 += 27 ;
}
break;
case V_36 :
if ( ! ( V_25 & V_37 ) ) {
F_11 ( V_7 , V_40 ,
V_43 , V_43 ) ;
F_11 ( V_7 , V_40 ,
V_43 , 0 ) ;
V_24 -> V_42 += 27 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
switch ( V_24 -> V_9 -> V_17 ) {
case 0 ... 3 :
break;
default:
switch ( V_5 ) {
case V_44 :
F_6 ( V_2 ) ;
break;
case V_45 :
F_10 ( V_2 ) ;
break;
default:
break;
}
break;
}
return F_13 ( V_2 , V_4 , V_5 ) ;
}
static int F_14 ( struct V_9 * V_9 , int V_46 )
{
struct V_27 V_47 = {
V_48 + V_46 * 4 , 0x80
} ;
int V_49 ;
V_49 = F_15 ( V_9 -> V_12 , & V_47 , 1 ) ;
if ( V_49 )
F_16 ( V_9 -> V_10 , L_1 ,
V_47 . V_21 , V_49 ) ;
return V_49 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_6 * V_7 = F_18 ( V_4 ) ;
struct V_52 * V_8 = F_19 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_53 * V_54 =
(struct V_53 * ) V_4 -> V_55 ;
unsigned int V_56 , V_57 ;
unsigned int V_58 = ( 0x1 << V_54 -> V_30 ) | ( 0x1 << V_54 -> V_59 ) ;
unsigned int V_60 = ( ! ! V_51 -> V_61 . integer . V_61 [ 0 ] ) << V_54 -> V_30 ;
unsigned int V_62 = ( ! ! V_51 -> V_61 . integer . V_61 [ 1 ] ) << V_54 -> V_59 ;
unsigned int V_63 , V_64 ;
unsigned int V_65 , V_66 ;
int V_49 ;
F_20 ( V_8 ) ;
V_49 = F_21 ( V_9 -> V_12 , V_67 , & V_56 ) ;
if ( V_49 ) {
F_16 ( V_9 -> V_10 , L_2 , V_49 ) ;
goto V_68;
}
V_49 = F_21 ( V_9 -> V_12 , V_26 , & V_57 ) ;
if ( V_49 ) {
F_16 ( V_9 -> V_10 , L_3 , V_49 ) ;
goto V_68;
}
V_63 = V_57 & ( 1 << V_54 -> V_30 ) ;
V_64 = V_57 & ( 1 << V_54 -> V_59 ) ;
V_65 = V_56 & ( 1 << V_54 -> V_59 ) ;
V_66 = V_56 & ( 1 << V_54 -> V_30 ) ;
if ( ( V_65 && V_60 != V_63 ) || ( V_66 && V_62 != V_64 ) ) {
F_16 ( V_9 -> V_10 , L_4 ) ;
V_49 = - V_69 ;
goto V_68;
}
V_49 = F_22 ( V_9 -> V_12 , V_26 ,
V_58 , V_60 | V_62 ) ;
if ( V_49 ) {
F_16 ( V_9 -> V_10 , L_5 , V_49 ) ;
goto V_68;
}
if ( ! V_60 && V_63 )
F_14 ( V_9 , V_54 -> V_30 ) ;
if ( ! V_62 && V_64 )
F_14 ( V_9 , V_54 -> V_59 ) ;
V_68:
F_23 ( V_8 ) ;
return V_49 ;
}
static int F_24 ( struct V_6 * V_7 , int V_70 , int V_71 ,
unsigned int V_72 , unsigned int V_73 )
{
struct V_74 * V_75 = F_7 ( V_7 ) ;
switch ( V_70 ) {
case V_76 :
return F_25 ( & V_75 -> V_77 [ 0 ] , V_71 , V_72 , V_73 ) ;
case V_78 :
return F_25 ( & V_75 -> V_77 [ 1 ] , V_71 , V_72 , V_73 ) ;
case V_79 :
return F_26 ( & V_75 -> V_77 [ 0 ] , V_71 , V_72 ,
V_73 ) ;
case V_80 :
return F_26 ( & V_75 -> V_77 [ 1 ] , V_71 , V_72 ,
V_73 ) ;
default:
return - V_81 ;
}
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_52 * V_8 = F_19 ( V_7 ) ;
struct V_74 * V_24 = F_7 ( V_7 ) ;
int V_15 , V_49 ;
V_24 -> V_82 . V_9 -> V_8 = V_8 ;
F_28 ( V_7 ) ;
F_29 ( V_7 ) ;
F_30 ( V_7 ) ;
for ( V_15 = 0 ; V_15 < V_83 ; ++ V_15 ) {
V_49 = F_31 ( & V_24 -> V_82 . V_84 [ V_15 ] , V_7 ) ;
if ( V_49 )
goto V_85;
}
V_49 = F_32 ( V_7 ,
V_86 ,
V_83 ) ;
if ( V_49 )
goto V_85;
F_33 ( V_8 , L_6 ) ;
return 0 ;
V_85:
for ( -- V_15 ; V_15 >= 0 ; -- V_15 )
F_34 ( & V_24 -> V_82 . V_84 [ V_15 ] , V_7 ) ;
return V_49 ;
}
static int F_35 ( struct V_6 * V_7 )
{
struct V_74 * V_24 = F_7 ( V_7 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_83 ; ++ V_15 )
F_34 ( & V_24 -> V_82 . V_84 [ V_15 ] , V_7 ) ;
V_24 -> V_82 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_36 ( struct V_87 * V_10 )
{
struct V_74 * V_24 = F_3 ( V_10 ) ;
return V_24 -> V_82 . V_9 -> V_12 ;
}
static int F_37 ( struct V_88 * V_89 )
{
struct V_9 * V_9 = F_3 ( V_89 -> V_10 . V_11 ) ;
struct V_74 * V_75 ;
int V_15 , V_49 ;
V_75 = F_38 ( & V_89 -> V_10 , sizeof( struct V_74 ) ,
V_90 ) ;
if ( V_75 == NULL )
return - V_91 ;
F_39 ( V_89 , V_75 ) ;
V_75 -> V_82 . V_9 = V_9 ;
V_75 -> V_82 . V_92 = 8 ;
for ( V_15 = 0 ; V_15 < V_83 ; V_15 ++ ) {
V_75 -> V_82 . V_84 [ V_15 ] . V_93 = L_7 ;
V_75 -> V_82 . V_84 [ V_15 ] . V_94 = V_15 + 1 ;
V_75 -> V_82 . V_84 [ V_15 ] . type = V_95 ;
V_75 -> V_82 . V_84 [ V_15 ] . V_10 = V_9 -> V_10 ;
V_75 -> V_82 . V_84 [ V_15 ] . V_12 = V_9 -> V_12 ;
V_75 -> V_82 . V_84 [ V_15 ] . V_96 = V_97
+ ( 0x100 * V_15 ) ;
V_75 -> V_82 . V_84 [ V_15 ] . V_98 = V_99 [ V_15 ] ;
V_75 -> V_82 . V_84 [ V_15 ] . V_100
= F_4 ( V_101 ) ;
V_49 = F_40 ( & V_75 -> V_82 . V_84 [ V_15 ] ) ;
if ( V_49 != 0 )
return V_49 ;
}
for ( V_15 = 0 ; V_15 < F_4 ( V_75 -> V_77 ) ; V_15 ++ )
V_75 -> V_77 [ V_15 ] . V_102 = 3 ;
F_41 ( V_9 , 1 , V_103 - 1 ,
V_104 , V_105 ,
& V_75 -> V_77 [ 0 ] ) ;
F_41 ( V_9 , 2 , V_106 - 1 ,
V_107 , V_108 ,
& V_75 -> V_77 [ 1 ] ) ;
F_22 ( V_9 -> V_12 , V_109 ,
V_110 , 0x11 ) ;
F_22 ( V_9 -> V_12 , V_111 ,
V_112 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_113 ) ; V_15 ++ )
F_42 ( & V_75 -> V_82 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_114 ) ; V_15 ++ )
F_22 ( V_9 -> V_12 , V_114 [ V_15 ] ,
V_115 , V_115 ) ;
F_43 ( & V_89 -> V_10 ) ;
F_44 ( & V_89 -> V_10 ) ;
return F_45 ( & V_89 -> V_10 , & V_116 ,
V_113 , F_4 ( V_113 ) ) ;
}
static int F_46 ( struct V_88 * V_89 )
{
F_47 ( & V_89 -> V_10 ) ;
F_48 ( & V_89 -> V_10 ) ;
return 0 ;
}
