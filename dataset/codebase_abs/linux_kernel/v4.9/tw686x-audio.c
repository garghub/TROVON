void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
F_2 (ch, &requests, max_channels(dev)) {
struct V_8 * V_9 = & V_2 -> V_10 [ V_6 ] ;
struct V_11 * V_12 = NULL ;
struct V_11 * V_13 = NULL ;
struct V_14 * V_15 ;
V_7 = ! ! ( V_4 & F_3 ( V_16 + V_6 ) ) ;
F_4 ( & V_9 -> V_17 , V_5 ) ;
if ( ! V_9 -> V_18 || ! V_9 -> V_19 [ 0 ] || ! V_9 -> V_19 [ 1 ] ) {
F_5 ( & V_9 -> V_17 , V_5 ) ;
continue;
}
if ( ! F_6 ( & V_9 -> V_20 ) ) {
V_13 = F_7 ( & V_9 -> V_20 ,
struct V_11 , V_21 ) ;
F_8 ( & V_13 -> V_21 , & V_9 -> V_20 ) ;
V_12 = V_9 -> V_19 [ ! V_7 ] ;
V_9 -> V_19 [ V_7 ] = V_13 ;
}
F_5 ( & V_9 -> V_17 , V_5 ) ;
if ( ! V_12 || ! V_13 )
continue;
V_15 = & V_9 -> V_22 [ V_7 ] ;
if ( V_15 -> V_23 ) {
memcpy ( V_12 -> V_23 , V_15 -> V_23 ,
V_2 -> V_24 ) ;
} else {
T_1 V_25 = V_7 ? V_26 [ V_6 ] : V_27 [ V_6 ] ;
F_9 ( V_2 , V_25 , V_13 -> V_28 ) ;
}
V_9 -> V_29 = V_12 -> V_28 - V_9 -> V_30 [ 0 ] . V_28 ;
F_10 ( V_9 -> V_18 ) ;
}
}
static int F_11 ( struct V_31 * V_18 ,
struct V_32 * V_33 )
{
return F_12 ( V_18 , F_13 ( V_33 ) ) ;
}
static int F_14 ( struct V_31 * V_18 )
{
return F_15 ( V_18 ) ;
}
static int F_16 ( struct V_31 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_34 ] ;
struct V_35 * V_36 = V_18 -> V_37 ;
int V_38 ;
V_9 -> V_18 = V_18 ;
V_36 -> V_39 = V_40 ;
V_38 = F_18 ( V_36 , V_41 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_19 ( struct V_31 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_34 ] ;
V_9 -> V_18 = NULL ;
return 0 ;
}
static int F_20 ( struct V_31 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_34 ] ;
struct V_35 * V_36 = V_18 -> V_37 ;
unsigned int V_24 = F_21 ( V_18 ) ;
struct V_11 * V_42 , * V_43 ;
unsigned long V_5 ;
int V_44 ;
F_4 ( & V_2 -> V_17 , V_5 ) ;
if ( ( ( V_2 -> V_45 != V_36 -> V_46 ) ||
( V_2 -> V_24 != V_24 ) ) && V_2 -> V_47 )
goto V_48;
F_22 ( V_2 , V_16 + V_9 -> V_6 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
if ( V_2 -> V_45 != V_36 -> V_46 ) {
T_1 V_25 ;
V_2 -> V_45 = V_36 -> V_46 ;
V_25 = ( ( 125000000 / V_36 -> V_46 ) << 16 ) +
( ( 125000000 % V_36 -> V_46 ) << 16 ) / V_36 -> V_46 ;
F_9 ( V_2 , V_49 , V_25 ) ;
}
if ( V_2 -> V_24 != V_24 ) {
T_1 V_25 ;
V_2 -> V_24 = V_24 ;
V_25 = F_23 ( V_2 , V_50 ) ;
V_25 &= ~ ( V_51 << V_52 ) ;
V_25 |= V_24 << V_52 ;
F_9 ( V_2 , V_50 , V_25 ) ;
}
if ( V_36 -> V_53 < V_54 ||
V_36 -> V_53 > V_55 )
return - V_56 ;
F_4 ( & V_9 -> V_17 , V_5 ) ;
F_24 ( & V_9 -> V_20 ) ;
for ( V_44 = 0 ; V_44 < V_36 -> V_53 ; V_44 ++ ) {
V_9 -> V_30 [ V_44 ] . V_28 = V_36 -> V_57 + V_24 * V_44 ;
V_9 -> V_30 [ V_44 ] . V_23 = V_36 -> V_58 + V_24 * V_44 ;
F_24 ( & V_9 -> V_30 [ V_44 ] . V_21 ) ;
F_25 ( & V_9 -> V_30 [ V_44 ] . V_21 , & V_9 -> V_20 ) ;
}
V_42 = F_7 ( & V_9 -> V_20 , struct V_11 , V_21 ) ;
F_8 ( & V_42 -> V_21 , & V_9 -> V_20 ) ;
V_43 = F_7 ( & V_9 -> V_20 , struct V_11 , V_21 ) ;
F_8 ( & V_43 -> V_21 , & V_9 -> V_20 ) ;
V_9 -> V_19 [ 0 ] = V_42 ;
V_9 -> V_19 [ 1 ] = V_43 ;
V_9 -> V_29 = 0 ;
if ( V_2 -> V_59 != V_60 ) {
F_9 ( V_2 , V_27 [ V_9 -> V_6 ] , V_42 -> V_28 ) ;
F_9 ( V_2 , V_26 [ V_9 -> V_6 ] , V_43 -> V_28 ) ;
}
F_5 ( & V_9 -> V_17 , V_5 ) ;
return 0 ;
V_48:
F_5 ( & V_2 -> V_17 , V_5 ) ;
return - V_61 ;
}
static int F_26 ( struct V_31 * V_18 , int V_62 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_34 ] ;
unsigned long V_5 ;
int V_38 = 0 ;
switch ( V_62 ) {
case V_63 :
if ( V_9 -> V_19 [ 0 ] && V_9 -> V_19 [ 1 ] ) {
F_4 ( & V_2 -> V_17 , V_5 ) ;
V_2 -> V_47 = 1 ;
F_27 ( V_2 ,
V_16 + V_9 -> V_6 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
F_28 ( & V_2 -> V_64 ,
V_65 + F_29 ( 100 ) ) ;
} else {
V_38 = - V_66 ;
}
break;
case V_67 :
F_4 ( & V_2 -> V_17 , V_5 ) ;
V_2 -> V_47 = 0 ;
F_22 ( V_2 , V_16 + V_9 -> V_6 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
F_4 ( & V_9 -> V_17 , V_5 ) ;
V_9 -> V_19 [ 0 ] = NULL ;
V_9 -> V_19 [ 1 ] = NULL ;
F_5 ( & V_9 -> V_17 , V_5 ) ;
break;
default:
V_38 = - V_56 ;
}
return V_38 ;
}
static T_2 F_30 ( struct V_31 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_34 ] ;
return F_31 ( V_18 -> V_37 , V_9 -> V_29 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_68 ;
struct V_70 * V_71 ;
struct V_31 * V_18 ;
unsigned int V_44 ;
int V_38 ;
V_38 = F_33 ( V_69 , V_69 -> V_72 , 0 , 0 , F_34 ( V_2 ) , & V_71 ) ;
if ( V_38 < 0 )
return V_38 ;
F_35 ( V_71 , V_73 , & V_74 ) ;
F_36 ( V_71 ) = V_2 ;
V_71 -> V_75 = 0 ;
F_37 ( V_71 -> V_76 , L_1 , sizeof( V_71 -> V_76 ) ) ;
for ( V_44 = 0 , V_18 = V_71 -> V_77 [ V_73 ] . V_78 ;
V_18 ; V_18 = V_18 -> V_13 , V_44 ++ )
snprintf ( V_18 -> V_76 , sizeof( V_18 -> V_76 ) , L_2 , V_44 ) ;
return F_38 ( V_71 ,
V_79 ,
F_39 ( V_2 -> V_80 ) ,
V_81 * V_82 ,
V_81 * V_82 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
if ( ! V_9 -> V_22 [ V_7 ] . V_23 )
continue;
F_41 ( V_2 -> V_80 , V_9 -> V_22 [ V_7 ] . V_83 ,
V_9 -> V_22 [ V_7 ] . V_23 ,
V_9 -> V_22 [ V_7 ] . V_84 ) ;
V_9 -> V_22 [ V_7 ] . V_23 = NULL ;
}
}
static int F_42 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_7 ;
if ( V_2 -> V_59 != V_60 )
return 0 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
T_1 V_25 = V_7 ? V_26 [ V_9 -> V_6 ] : V_27 [ V_9 -> V_6 ] ;
void * V_23 ;
V_23 = F_43 ( V_2 -> V_80 , V_82 ,
& V_9 -> V_22 [ V_7 ] . V_84 ) ;
if ( ! V_23 ) {
F_44 ( & V_2 -> V_80 -> V_2 ,
L_3 ,
V_9 -> V_6 , V_7 ? L_4 : L_5 ) ;
return - V_85 ;
}
V_9 -> V_22 [ V_7 ] . V_23 = V_23 ;
V_9 -> V_22 [ V_7 ] . V_83 = V_82 ;
F_9 ( V_2 , V_25 , V_9 -> V_22 [ V_7 ] . V_84 ) ;
}
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
T_1 V_86 ;
T_1 V_87 ;
F_4 ( & V_2 -> V_17 , V_5 ) ;
V_87 = F_23 ( V_2 , V_88 ) ;
V_86 = F_23 ( V_2 , V_89 ) ;
F_9 ( V_2 , V_88 , V_87 & ~ 0xff00 ) ;
F_9 ( V_2 , V_89 , V_86 & ~ 0xff00 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
if ( ! V_2 -> V_68 )
return;
F_46 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_80 * V_80 = V_2 -> V_80 ;
struct V_68 * V_69 ;
int V_38 , V_6 ;
F_9 ( V_2 , V_50 , F_3 ( 0 ) ) ;
V_38 = F_48 ( & V_80 -> V_2 , V_90 ,
V_91 ,
V_92 , 0 , & V_69 ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 -> V_68 = V_69 ;
F_37 ( V_69 -> V_72 , L_6 , sizeof( V_69 -> V_72 ) ) ;
F_37 ( V_69 -> V_93 , L_6 , sizeof( V_69 -> V_93 ) ) ;
F_37 ( V_69 -> V_94 , F_49 ( V_80 ) , sizeof( V_69 -> V_94 ) ) ;
F_50 ( V_69 , & V_80 -> V_2 ) ;
for ( V_6 = 0 ; V_6 < F_34 ( V_2 ) ; V_6 ++ ) {
struct V_8 * V_9 ;
V_9 = & V_2 -> V_10 [ V_6 ] ;
F_51 ( & V_9 -> V_17 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_6 = V_6 ;
V_38 = F_42 ( V_2 , V_9 ) ;
if ( V_38 < 0 )
goto V_95;
}
V_38 = F_32 ( V_2 ) ;
if ( V_38 < 0 )
goto V_95;
V_38 = F_52 ( V_69 ) ;
if ( ! V_38 )
return 0 ;
V_95:
for ( V_6 = 0 ; V_6 < F_34 ( V_2 ) ; V_6 ++ ) {
if ( ! V_2 -> V_10 [ V_6 ] . V_2 )
continue;
F_40 ( V_2 , & V_2 -> V_10 [ V_6 ] ) ;
}
F_46 ( V_69 ) ;
V_2 -> V_68 = NULL ;
return V_38 ;
}
