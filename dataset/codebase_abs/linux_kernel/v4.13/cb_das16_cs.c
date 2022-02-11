static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_11 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
int V_19 = F_5 ( V_6 -> V_18 ) ;
int V_20 = F_6 ( V_6 -> V_18 ) ;
int V_21 ;
int V_22 ;
F_7 ( F_8 ( V_17 ) ,
V_2 -> V_9 + V_23 ) ;
V_15 -> V_24 &= ~ ( V_25 | V_26 |
V_27 ) ;
if ( V_20 == V_28 )
V_15 -> V_24 &= ~ V_29 ;
else
V_15 -> V_24 |= V_29 ;
F_7 ( V_15 -> V_24 , V_2 -> V_9 + V_10 ) ;
V_15 -> V_30 &= ~ ( V_31 | V_32 ) ;
switch ( V_19 ) {
case 0 :
V_15 -> V_30 |= V_33 ;
break;
case 1 :
V_15 -> V_30 |= V_34 ;
break;
case 2 :
V_15 -> V_30 |= V_35 ;
break;
case 3 :
V_15 -> V_30 |= V_36 ;
break;
}
F_7 ( V_15 -> V_30 , V_2 -> V_9 + V_37 ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_38 ; V_22 ++ ) {
F_7 ( 0 , V_2 -> V_9 + V_39 ) ;
V_21 = F_9 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_21 )
return V_21 ;
V_13 [ V_22 ] = F_2 ( V_2 -> V_9 + V_39 ) ;
}
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_40 = V_4 -> V_41 [ V_17 ] ;
unsigned short V_24 ;
int V_42 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_38 ; V_22 ++ ) {
V_40 = V_13 [ V_22 ] ;
F_7 ( V_15 -> V_24 , V_2 -> V_9 + V_10 ) ;
F_11 ( 1 ) ;
V_24 = V_15 -> V_24 & ~ V_43 ;
if ( V_17 )
V_24 |= V_44 ;
else
V_24 |= V_45 ;
F_7 ( V_24 , V_2 -> V_9 + V_10 ) ;
F_11 ( 1 ) ;
for ( V_42 = 15 ; V_42 >= 0 ; V_42 -- ) {
if ( ( V_40 >> V_42 ) & 0x1 )
V_24 |= V_46 ;
else
V_24 &= ~ V_46 ;
F_7 ( V_24 , V_2 -> V_9 + V_10 ) ;
F_11 ( 1 ) ;
F_7 ( V_24 | V_47 ,
V_2 -> V_9 + V_10 ) ;
F_11 ( 1 ) ;
}
F_7 ( V_24 | V_44 | V_45 ,
V_2 -> V_9 + V_10 ) ;
}
V_4 -> V_41 [ V_17 ] = V_40 ;
return V_6 -> V_38 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
if ( F_13 ( V_4 , V_13 ) )
F_7 ( V_4 -> V_48 , V_2 -> V_9 + V_49 ) ;
V_13 [ 1 ] = F_2 ( V_2 -> V_9 + V_49 ) ;
return V_6 -> V_38 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_50 ;
int V_21 ;
if ( V_17 < 4 )
V_50 = 0x0f ;
else
V_50 = 0xf0 ;
V_21 = F_15 ( V_2 , V_4 , V_6 , V_13 , V_50 ) ;
if ( V_21 )
return V_21 ;
if ( V_4 -> V_51 & 0xf0 )
V_15 -> V_30 |= V_52 ;
else
V_15 -> V_30 &= ~ V_52 ;
if ( V_4 -> V_51 & 0x0f )
V_15 -> V_30 |= V_53 ;
else
V_15 -> V_30 &= ~ V_53 ;
F_7 ( V_15 -> V_30 , V_2 -> V_9 + V_37 ) ;
return V_6 -> V_38 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
switch ( V_13 [ 0 ] ) {
case V_54 :
switch ( V_13 [ 1 ] ) {
case 0 :
V_15 -> V_30 |= V_55 ;
break;
case 1 :
V_15 -> V_30 &= ~ V_55 ;
break;
default:
return - V_56 ;
}
F_7 ( V_15 -> V_30 , V_2 -> V_9 + V_37 ) ;
break;
case V_57 :
if ( V_15 -> V_30 & V_55 ) {
V_13 [ 1 ] = 0 ;
V_13 [ 2 ] = V_58 ;
} else {
V_13 [ 1 ] = 1 ;
V_13 [ 2 ] = 0 ;
}
break;
default:
return - V_56 ;
}
return V_6 -> V_38 ;
}
static const void * F_17 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
const struct V_61 * V_62 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_18 ( V_63 ) ; V_22 ++ ) {
V_62 = & V_63 [ V_22 ] ;
if ( V_62 -> V_64 == V_60 -> V_65 )
return V_62 ;
}
return NULL ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_59 * V_60 = F_20 ( V_2 ) ;
const struct V_61 * V_62 ;
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_21 ;
V_62 = F_17 ( V_2 , V_60 ) ;
if ( ! V_62 )
return - V_66 ;
V_2 -> V_67 = V_62 ;
V_2 -> V_68 = V_62 -> V_69 ;
V_60 -> V_70 |= V_71 | V_72 ;
V_21 = F_21 ( V_2 , NULL ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_9 = V_60 -> V_73 [ 0 ] -> V_74 ;
V_60 -> V_75 = V_2 ;
V_15 = F_22 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_76 ;
V_2 -> V_77 = F_23 ( V_2 -> V_9 + V_78 ,
V_79 , V_80 , 0 ) ;
if ( ! V_2 -> V_77 )
return - V_76 ;
V_21 = F_24 ( V_2 , 4 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_81 [ 0 ] ;
V_4 -> type = V_82 ;
V_4 -> V_83 = V_84 | V_85 | V_86 ;
V_4 -> V_87 = 16 ;
V_4 -> V_88 = 0xffff ;
V_4 -> V_89 = & V_90 ;
V_4 -> V_91 = F_3 ;
V_4 = & V_2 -> V_81 [ 1 ] ;
if ( V_62 -> V_92 ) {
V_4 -> type = V_93 ;
V_4 -> V_83 = V_94 ;
V_4 -> V_87 = 2 ;
V_4 -> V_88 = 0xffff ;
V_4 -> V_89 = & V_95 ;
V_4 -> V_96 = & F_10 ;
V_21 = F_25 ( V_4 ) ;
if ( V_21 )
return V_21 ;
} else {
V_4 -> type = V_97 ;
}
V_4 = & V_2 -> V_81 [ 2 ] ;
V_4 -> type = V_98 ;
V_4 -> V_83 = V_84 | V_94 ;
V_4 -> V_87 = V_62 -> V_99 ? 4 : 8 ;
V_4 -> V_88 = 1 ;
V_4 -> V_89 = & V_100 ;
V_4 -> V_101 = F_12 ;
V_4 -> V_102 = F_14 ;
V_4 = & V_2 -> V_81 [ 3 ] ;
F_26 ( V_4 , V_2 -> V_77 ) ;
V_2 -> V_77 -> V_102 = F_16 ;
F_27 ( V_2 -> V_77 , 1 , true ) ;
F_27 ( V_2 -> V_77 , 2 , true ) ;
return 0 ;
}
static int F_28 ( struct V_59 * V_60 )
{
return F_29 ( V_60 , & V_103 ) ;
}
