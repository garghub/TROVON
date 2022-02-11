static inline int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 ;
int V_8 = 0xffff ;
while ( V_8 -- ) {
if ( ( V_3 & F_2 ( V_6 ) ) == V_3 )
return 0 ;
F_3 ( 100 ) ;
}
F_4 ( L_1 , F_2 ( V_6 ) ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( F_6 ( 2 ) | F_6 ( 10 ) | F_6 ( 18 ) |
F_6 ( 26 ) | F_6 ( 27 ) | F_6 ( 28 ) ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( F_6 ( 10 ) | F_6 ( 26 ) ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( F_6 ( 2 ) | F_6 ( 18 ) ) ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_10 ( V_2 -> V_5 -> V_5 , L_2 , V_3 ) ;
switch ( V_3 ) {
case F_6 ( 0 ) :
case F_6 ( 1 ) :
case F_6 ( 2 ) :
case F_6 ( 3 ) :
case F_6 ( 4 ) :
case F_6 ( 5 ) :
case F_6 ( 6 ) :
case F_6 ( 7 ) :
case F_6 ( 8 ) :
case F_6 ( 9 ) :
case F_6 ( 10 ) :
case F_6 ( 11 ) :
case F_6 ( 12 ) :
case F_6 ( 13 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_3 ) ;
break;
case F_6 ( 14 ) :
break;
case F_6 ( 15 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_3 ) ;
break;
case F_6 ( 16 ) :
break;
case F_6 ( 17 ) :
break;
case F_6 ( 18 ) :
case F_6 ( 19 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_4 ) ;
if ( 0 )
F_5 ( V_2 ) ;
break;
case F_6 ( 20 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_3 ) ;
break;
case F_6 ( 21 ) :
break;
case F_6 ( 22 ) :
break;
case F_6 ( 23 ) :
case F_6 ( 24 ) :
case F_6 ( 25 ) :
case F_6 ( 26 ) :
case F_6 ( 27 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_5 ) ;
F_11 ( V_10 , V_3 ) ;
F_8 ( V_2 ) ;
break;
case F_6 ( 28 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_6 ) ;
F_11 ( V_10 , V_3 ) ;
F_7 ( V_2 ) ;
break;
case F_6 ( 29 ) :
case F_6 ( 30 ) :
case F_6 ( 31 ) :
F_10 ( V_2 -> V_5 -> V_5 , L_3 ) ;
break;
}
if ( V_3 & F_2 ( V_10 ) )
F_10 ( V_2 -> V_5 -> V_5 ,
L_7 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_10 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 V_12 ;
int V_13 ;
int V_14 = 0 ;
V_12 = F_2 ( V_10 ) ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ ) {
V_3 = ( 0x00000001UL ) << V_13 ;
if ( V_12 & V_3 ) {
F_10 ( V_2 -> V_5 -> V_5 , L_8 , V_15 [ V_13 ] ) ;
V_14 = F_9 ( V_2 , V_3 ) ;
if ( V_14 )
F_4 ( L_9 ) ;
}
}
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 V_17 , T_2 V_18 , bool V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_20 ;
T_1 V_21 ;
T_2 V_22 = 0 ;
if ( V_19 ) {
V_20 = V_2 -> V_23 ;
} else {
V_20 = V_2 -> V_24 ;
}
V_21 = F_14 ( V_18 , 23 , 16 ) | F_14 ( V_17 , 15 , 8 ) |
F_14 ( V_22 , 7 , 6 ) | F_14 ( V_16 , 5 , 0 ) ;
F_11 ( V_20 , V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 * V_25 , int V_26 , bool V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_20 ;
T_1 V_27 ;
T_1 V_21 ;
T_2 * V_28 ;
T_2 V_29 , V_30 , V_31 , V_32 ;
T_2 V_22 = 0 ;
int V_13 ;
if ( V_19 ) {
V_20 = V_2 -> V_23 ;
V_27 = V_2 -> V_33 ;
} else {
V_20 = V_2 -> V_24 ;
V_27 = V_2 -> V_34 ;
}
V_28 = V_25 ;
for ( V_13 = 0 ; V_13 < V_26 / 4 ; V_13 ++ ) {
V_29 = * V_28 ++ ;
V_30 = * V_28 ++ ;
V_31 = * V_28 ++ ;
V_32 = * V_28 ++ ;
F_11 ( V_27 , V_32 << 24 | V_31 << 16 | V_30 << 8 | V_29 ) ;
}
V_13 = V_26 % 4 ;
if ( V_13 ) {
V_29 = 0 ; V_30 = 0 ; V_31 = 0 ;
switch ( V_13 ) {
case 3 :
V_29 = * V_28 ++ ;
V_30 = * V_28 ++ ;
V_31 = * V_28 ++ ;
break;
case 2 :
V_29 = * V_28 ++ ;
V_30 = * V_28 ++ ;
break;
case 1 :
V_29 = * V_28 ++ ;
break;
}
F_11 ( V_27 , V_31 << 16 | V_30 << 8 | V_29 ) ;
}
V_21 = F_14 ( V_26 , 23 , 8 ) | F_14 ( V_22 , 7 , 6 ) |
F_14 ( V_16 , 5 , 0 ) ;
F_11 ( V_20 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 * V_25 , T_3 V_26 )
{
T_2 V_17 ;
switch ( V_16 ) {
case V_35 :
case V_36 :
case V_37 :
V_17 = * V_25 ;
break;
default:
return 0 ;
}
V_2 -> V_38 = V_39 ;
if ( F_17 ( V_17 == V_40 ) ) {
F_18 ( 120 ) ;
}
if ( F_17 ( V_17 == V_41 ) ) {
F_18 ( 120 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 * V_25 , T_3 V_26 )
{
T_2 V_17 ;
switch ( V_16 ) {
case V_35 :
case V_36 :
case V_37 :
V_17 = * V_25 ;
break;
default:
return 0 ;
}
if ( F_17 ( V_17 == V_40 ) ) {
V_2 -> V_42 |= V_43 ;
F_18 ( 120 ) ;
} else if ( F_17 ( V_17 == V_41 ) ) {
V_2 -> V_42 &= ~ V_43 ;
F_18 ( 120 ) ;
} else if ( F_17 ( V_17 == V_44 ) ) {
F_18 ( 5 ) ;
}
V_2 -> V_38 = V_45 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 * V_25 , T_3 V_26 , bool V_19 )
{
int V_46 ;
V_46 = F_12 ( V_2 ) ;
if ( V_46 ) {
F_4 ( L_10 ) ;
return - V_47 ;
}
if ( V_2 -> V_38 == V_39 ) {
F_4 ( L_11 ) ;
return - V_47 ;
}
V_46 = F_16 ( V_2 , V_16 , V_25 , V_26 ) ;
if ( V_46 ) {
F_4 ( L_12 ) ;
return V_46 ;
}
switch ( V_16 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_35 :
case V_36 :
case V_54 :
V_46 = F_13 ( V_2 , V_16 , V_25 [ 0 ] , V_25 [ 1 ] , V_19 ) ;
break;
case V_55 :
case V_37 :
V_46 = F_15 ( V_2 , V_16 , V_25 , V_26 , V_19 ) ;
break;
}
F_19 ( V_2 , V_16 , V_25 , V_26 ) ;
return V_46 ;
}
int F_21 ( struct V_1 * V_2 , T_2 * V_25 ,
T_1 V_26 , bool V_19 )
{
unsigned long V_56 ;
if ( ! V_2 || ! V_25 || ! V_26 ) {
F_4 ( L_13 ) ;
return - V_57 ;
}
F_22 ( & V_2 -> V_58 , V_56 ) ;
F_20 ( V_2 , V_37 , V_25 , V_26 , V_19 ) ;
F_23 ( & V_2 -> V_58 , V_56 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_17 ,
T_2 V_18 , T_2 V_59 , bool V_19 )
{
T_2 V_25 [ 2 ] ;
unsigned long V_56 ;
T_2 V_16 ;
if ( ! V_2 ) {
F_4 ( L_14 ) ;
return - V_57 ;
}
V_25 [ 0 ] = V_17 ;
if ( V_59 ) {
V_16 = V_36 ;
V_25 [ 1 ] = V_18 ;
} else {
V_16 = V_35 ;
V_25 [ 1 ] = 0 ;
}
F_22 ( & V_2 -> V_58 , V_56 ) ;
F_20 ( V_2 , V_16 , V_25 , sizeof( V_25 ) , V_19 ) ;
F_23 ( & V_2 -> V_58 , V_56 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_2 V_60 ,
T_2 V_61 , T_2 V_59 , bool V_19 )
{
T_2 V_25 [ 2 ] ;
unsigned long V_56 ;
T_2 V_16 ;
if ( ! V_2 || V_59 > 2 ) {
F_4 ( L_14 ) ;
return - V_57 ;
}
switch ( V_59 ) {
case 0 :
V_16 = V_48 ;
V_25 [ 0 ] = 0 ;
V_25 [ 1 ] = 0 ;
break;
case 1 :
V_16 = V_49 ;
V_25 [ 0 ] = V_60 ;
V_25 [ 1 ] = 0 ;
break;
case 2 :
V_16 = V_50 ;
V_25 [ 0 ] = V_60 ;
V_25 [ 1 ] = V_61 ;
break;
}
F_22 ( & V_2 -> V_58 , V_56 ) ;
F_20 ( V_2 , V_16 , V_25 , sizeof( V_25 ) , V_19 ) ;
F_23 ( & V_2 -> V_58 , V_56 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , T_2 * V_25 ,
T_1 V_26 , bool V_19 )
{
unsigned long V_56 ;
if ( ! V_2 || ! V_25 || ! V_26 ) {
F_4 ( L_13 ) ;
return - V_57 ;
}
F_22 ( & V_2 -> V_58 , V_56 ) ;
F_20 ( V_2 , V_55 , V_25 , V_26 , V_19 ) ;
F_23 ( & V_2 -> V_58 , V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 * V_25 , T_3 V_26 , T_1 * V_62 , T_3 V_63 , bool V_19 )
{
unsigned long V_56 ;
struct V_4 * V_5 ;
int V_13 ;
T_1 V_64 ;
int V_8 = V_65 ;
if ( ! V_2 || ! V_62 || ! V_63 ) {
F_4 ( L_13 ) ;
return - V_57 ;
}
V_5 = V_2 -> V_5 ;
F_22 ( & V_2 -> V_58 , V_56 ) ;
F_11 ( V_2 -> V_11 , F_6 ( 29 ) ) ;
if ( ( F_2 ( V_2 -> V_11 ) & F_6 ( 29 ) ) )
F_4 ( L_15 ) ;
F_20 ( V_2 , V_16 , V_25 , V_26 , V_19 ) ;
while ( V_8 && ! ( F_2 ( V_2 -> V_11 ) & F_6 ( 29 ) ) ) {
F_3 ( 100 ) ;
V_8 -- ;
}
if ( ! V_8 ) {
F_23 ( & V_2 -> V_58 , V_56 ) ;
return - V_66 ;
}
F_11 ( V_2 -> V_11 , F_6 ( 29 ) ) ;
if ( V_19 )
V_64 = V_2 -> V_33 ;
else
V_64 = V_2 -> V_34 ;
for ( V_13 = 0 ; V_13 < V_63 ; V_13 ++ )
* ( V_62 + V_13 ) = F_2 ( V_64 ) ;
F_23 ( & V_2 -> V_58 , V_56 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_17 ,
T_1 * V_25 , T_3 V_26 , bool V_19 )
{
if ( ! V_2 || ! V_25 || ! V_26 ) {
F_4 ( L_13 ) ;
return - V_57 ;
}
return F_27 ( V_2 , V_54 , & V_17 , 1 ,
V_25 , V_26 , V_19 ) ;
}
int F_29 ( struct V_67 * V_68 ,
int V_69 )
{
struct V_1 * V_70 ;
struct V_71 * V_72 =
F_30 ( V_68 ) ;
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_73 * V_74 = V_5 -> V_75 ;
const struct V_76 * V_77 = & V_74 -> V_78 [ V_69 ] ;
T_1 V_79 = 0 ;
if ( ! V_68 ) {
F_4 ( L_14 ) ;
return - V_57 ;
}
V_70 = V_68 -> V_70 ;
if ( ! V_70 || F_31 ( V_70 ) ) {
V_70 = F_32 ( sizeof( struct V_1 ) ,
V_80 ) ;
if ( ! V_70 ) {
F_4 ( L_16 ) ;
return - V_81 ;
}
V_68 -> V_70 = ( void * ) V_70 ;
}
V_70 -> V_5 = V_5 ;
V_70 -> V_68 = V_68 ;
V_70 -> V_69 = V_69 ;
V_70 -> V_82 = 0 ;
V_70 -> V_42 = 0 ;
V_70 -> V_38 = V_45 ;
V_70 -> V_83 = V_77 -> V_84 ;
V_70 -> V_85 = V_77 -> V_86 ;
V_70 -> V_87 = V_77 -> V_88 ;
V_70 -> V_89 = V_77 -> V_90 ;
V_70 -> V_91 = V_77 -> V_92 ;
V_70 -> V_93 = V_77 -> V_38 ;
V_70 -> V_11 = F_33 ( V_69 ) ;
V_70 -> V_34 = F_34 ( V_69 ) ;
V_70 -> V_33 = F_35 ( V_69 ) ;
V_70 -> V_24 = F_36 ( V_69 ) ;
V_70 -> V_23 = F_37 ( V_69 ) ;
V_70 -> V_7 = F_38 ( V_69 ) ;
V_70 -> V_94 = F_39 ( V_69 ) ;
V_70 -> V_95 = F_40 ( V_69 ) ;
V_70 -> V_96 = F_41 ( V_69 ) ;
V_70 -> V_97 = F_42 ( V_69 ) ;
F_43 ( & V_70 -> V_58 ) ;
if ( F_44 ( V_5 , V_69 ) != V_98 ) {
V_79 = V_99 | V_100 ;
if ( V_69 == 0 )
V_79 |= 0x2 ;
F_11 ( F_45 ( V_69 ) , V_79 ) ;
F_2 ( F_45 ( V_69 ) ) ;
F_46 ( V_72 , V_69 ) ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_31 ( V_2 ) )
return;
F_48 ( V_2 ) ;
}
