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
V_15 = & V_9 -> V_22 [ V_7 ] ;
if ( V_12 && V_13 && V_15 -> V_23 ) {
memcpy ( V_12 -> V_23 , V_15 -> V_23 , V_15 -> V_24 ) ;
V_9 -> V_25 = V_12 -> V_26 - V_9 -> V_27 [ 0 ] . V_26 ;
F_9 ( V_9 -> V_18 ) ;
}
}
}
static int F_10 ( struct V_28 * V_18 ,
struct V_29 * V_30 )
{
return F_11 ( V_18 , F_12 ( V_30 ) ) ;
}
static int F_13 ( struct V_28 * V_18 )
{
return F_14 ( V_18 ) ;
}
static int F_15 ( struct V_28 * V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_31 ] ;
struct V_32 * V_33 = V_18 -> V_34 ;
int V_35 ;
V_9 -> V_18 = V_18 ;
V_33 -> V_36 = V_37 ;
V_35 = F_17 ( V_33 , V_38 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static int F_18 ( struct V_28 * V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_31 ] ;
V_9 -> V_18 = NULL ;
return 0 ;
}
static int F_19 ( struct V_28 * V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_31 ] ;
struct V_32 * V_33 = V_18 -> V_34 ;
unsigned int V_39 = F_20 ( V_18 ) ;
struct V_11 * V_40 , * V_41 ;
unsigned long V_5 ;
int V_42 ;
F_4 ( & V_2 -> V_17 , V_5 ) ;
F_21 ( V_2 , V_16 + V_9 -> V_6 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
if ( V_2 -> V_43 != V_33 -> V_44 ) {
T_1 V_45 ;
V_2 -> V_43 = V_33 -> V_44 ;
V_45 = ( ( 125000000 / V_33 -> V_44 ) << 16 ) +
( ( 125000000 % V_33 -> V_44 ) << 16 ) / V_33 -> V_44 ;
F_22 ( V_2 , V_46 , V_45 ) ;
}
if ( V_39 != V_47 ||
V_33 -> V_48 < V_49 ||
V_33 -> V_48 > V_50 ) {
return - V_51 ;
}
F_4 ( & V_9 -> V_17 , V_5 ) ;
F_23 ( & V_9 -> V_20 ) ;
for ( V_42 = 0 ; V_42 < V_33 -> V_48 ; V_42 ++ ) {
V_9 -> V_27 [ V_42 ] . V_26 = V_33 -> V_52 + V_39 * V_42 ;
V_9 -> V_27 [ V_42 ] . V_23 = V_33 -> V_53 + V_39 * V_42 ;
F_23 ( & V_9 -> V_27 [ V_42 ] . V_21 ) ;
F_24 ( & V_9 -> V_27 [ V_42 ] . V_21 , & V_9 -> V_20 ) ;
}
V_40 = F_7 ( & V_9 -> V_20 , struct V_11 , V_21 ) ;
F_8 ( & V_40 -> V_21 , & V_9 -> V_20 ) ;
V_41 = F_7 ( & V_9 -> V_20 , struct V_11 , V_21 ) ;
F_8 ( & V_41 -> V_21 , & V_9 -> V_20 ) ;
V_9 -> V_19 [ 0 ] = V_40 ;
V_9 -> V_19 [ 1 ] = V_41 ;
V_9 -> V_25 = 0 ;
F_5 ( & V_9 -> V_17 , V_5 ) ;
return 0 ;
}
static int F_25 ( struct V_28 * V_18 , int V_54 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_31 ] ;
unsigned long V_5 ;
int V_35 = 0 ;
switch ( V_54 ) {
case V_55 :
if ( V_9 -> V_19 [ 0 ] && V_9 -> V_19 [ 1 ] ) {
F_4 ( & V_2 -> V_17 , V_5 ) ;
F_26 ( V_2 ,
V_16 + V_9 -> V_6 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
F_27 ( & V_2 -> V_56 ,
V_57 + F_28 ( 100 ) ) ;
} else {
V_35 = - V_58 ;
}
break;
case V_59 :
F_4 ( & V_2 -> V_17 , V_5 ) ;
F_21 ( V_2 , V_16 + V_9 -> V_6 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
F_4 ( & V_9 -> V_17 , V_5 ) ;
V_9 -> V_19 [ 0 ] = NULL ;
V_9 -> V_19 [ 1 ] = NULL ;
F_5 ( & V_9 -> V_17 , V_5 ) ;
break;
default:
V_35 = - V_51 ;
}
return V_35 ;
}
static T_2 F_29 ( struct V_28 * V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
struct V_8 * V_9 = & V_2 -> V_10 [ V_18 -> V_31 ] ;
return F_30 ( V_18 -> V_34 , V_9 -> V_25 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_60 ;
struct V_62 * V_63 ;
struct V_28 * V_18 ;
unsigned int V_42 ;
int V_35 ;
V_35 = F_32 ( V_61 , V_61 -> V_64 , 0 , 0 , F_33 ( V_2 ) , & V_63 ) ;
if ( V_35 < 0 )
return V_35 ;
F_34 ( V_63 , V_65 , & V_66 ) ;
F_35 ( V_63 ) = V_2 ;
V_63 -> V_67 = 0 ;
F_36 ( V_63 -> V_68 , L_1 , sizeof( V_63 -> V_68 ) ) ;
for ( V_42 = 0 , V_18 = V_63 -> V_69 [ V_65 ] . V_70 ;
V_18 ; V_18 = V_18 -> V_13 , V_42 ++ )
snprintf ( V_18 -> V_68 , sizeof( V_18 -> V_68 ) , L_2 , V_42 ) ;
return F_37 ( V_63 ,
V_71 ,
F_38 ( V_2 -> V_72 ) ,
V_73 * V_47 ,
V_73 * V_47 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
if ( ! V_9 -> V_22 [ V_7 ] . V_23 )
continue;
F_40 ( V_2 -> V_72 , V_9 -> V_22 [ V_7 ] . V_24 ,
V_9 -> V_22 [ V_7 ] . V_23 ,
V_9 -> V_22 [ V_7 ] . V_74 ) ;
V_9 -> V_22 [ V_7 ] . V_23 = NULL ;
}
}
static int F_41 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
T_1 V_45 = V_7 ? V_75 [ V_9 -> V_6 ] : V_76 [ V_9 -> V_6 ] ;
void * V_23 ;
V_23 = F_42 ( V_2 -> V_72 , V_47 ,
& V_9 -> V_22 [ V_7 ] . V_74 ) ;
if ( ! V_23 ) {
F_43 ( & V_2 -> V_72 -> V_2 ,
L_3 ,
V_9 -> V_6 , V_7 ? L_4 : L_5 ) ;
return - V_77 ;
}
V_9 -> V_22 [ V_7 ] . V_23 = V_23 ;
V_9 -> V_22 [ V_7 ] . V_24 = V_47 ;
F_22 ( V_2 , V_45 , V_9 -> V_22 [ V_7 ] . V_74 ) ;
}
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
T_1 V_78 ;
T_1 V_79 ;
F_4 ( & V_2 -> V_17 , V_5 ) ;
V_79 = F_45 ( V_2 , V_80 ) ;
V_78 = F_45 ( V_2 , V_81 ) ;
F_22 ( V_2 , V_80 , V_79 & ~ 0xff00 ) ;
F_22 ( V_2 , V_81 , V_78 & ~ 0xff00 ) ;
F_5 ( & V_2 -> V_17 , V_5 ) ;
if ( ! V_2 -> V_60 )
return;
F_46 ( V_2 -> V_60 ) ;
V_2 -> V_60 = NULL ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_72 * V_72 = V_2 -> V_72 ;
struct V_60 * V_61 ;
int V_35 , V_6 ;
F_22 ( V_2 , V_82 , 0x80000001 ) ;
V_35 = F_48 ( & V_72 -> V_2 , V_83 ,
V_84 ,
V_85 , 0 , & V_61 ) ;
if ( V_35 < 0 )
return V_35 ;
V_2 -> V_60 = V_61 ;
F_36 ( V_61 -> V_64 , L_6 , sizeof( V_61 -> V_64 ) ) ;
F_36 ( V_61 -> V_86 , L_6 , sizeof( V_61 -> V_86 ) ) ;
F_36 ( V_61 -> V_87 , F_49 ( V_72 ) , sizeof( V_61 -> V_87 ) ) ;
F_50 ( V_61 , & V_72 -> V_2 ) ;
for ( V_6 = 0 ; V_6 < F_33 ( V_2 ) ; V_6 ++ ) {
struct V_8 * V_9 ;
V_9 = & V_2 -> V_10 [ V_6 ] ;
F_51 ( & V_9 -> V_17 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_6 = V_6 ;
V_35 = F_41 ( V_2 , V_9 ) ;
if ( V_35 < 0 )
goto V_88;
}
V_35 = F_31 ( V_2 ) ;
if ( V_35 < 0 )
goto V_88;
V_35 = F_52 ( V_61 ) ;
if ( ! V_35 )
return 0 ;
V_88:
for ( V_6 = 0 ; V_6 < F_33 ( V_2 ) ; V_6 ++ ) {
if ( ! V_2 -> V_10 [ V_6 ] . V_2 )
continue;
F_39 ( V_2 , & V_2 -> V_10 [ V_6 ] ) ;
}
F_46 ( V_61 ) ;
V_2 -> V_60 = NULL ;
return V_35 ;
}
