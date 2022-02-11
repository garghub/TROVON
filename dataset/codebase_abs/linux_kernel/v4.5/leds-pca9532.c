static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
enum V_5 V_6 )
{
int V_7 = 0 , V_8 = 0 , V_9 = 0 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_11 -> V_12 -> V_13 ; V_9 ++ ) {
if ( V_11 -> V_14 [ V_9 ] . type == V_15 &&
V_11 -> V_14 [ V_9 ] . V_16 == V_17 + V_3 ) {
V_7 ++ ;
V_8 += V_11 -> V_14 [ V_9 ] . V_18 . V_19 ;
}
}
if ( V_7 == 0 ) {
F_3 ( & V_2 -> V_20 ,
L_1 ,
V_8 , V_7 , V_6 ) ;
return - V_21 ;
}
V_8 = V_8 / V_7 ;
if ( V_8 > 0xFF )
return - V_21 ;
V_11 -> V_3 [ V_3 ] = V_8 ;
V_11 -> V_22 [ V_3 ] = V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
F_5 ( & V_11 -> V_24 ) ;
F_6 ( V_2 , F_7 ( V_23 , V_3 ) ,
V_11 -> V_3 [ V_3 ] ) ;
F_6 ( V_2 , F_8 ( V_23 , V_3 ) ,
V_11 -> V_22 [ V_3 ] ) ;
F_9 ( & V_11 -> V_24 ) ;
return 0 ;
}
static void F_10 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
char V_27 ;
F_5 ( & V_11 -> V_24 ) ;
V_27 = F_11 ( V_2 , F_12 ( V_23 , V_26 -> V_28 ) ) ;
V_27 = V_27 & ~ ( 0x3 << F_13 ( V_26 -> V_28 ) * 2 ) ;
V_27 = V_27 | ( V_26 -> V_16 << F_13 ( V_26 -> V_28 ) * 2 ) ;
F_6 ( V_2 , F_12 ( V_23 , V_26 -> V_28 ) , V_27 ) ;
F_9 ( & V_11 -> V_24 ) ;
}
static int F_14 ( struct V_29 * V_30 ,
enum V_5 V_6 )
{
int V_31 = 0 ;
struct V_25 * V_26 = F_15 ( V_30 ) ;
if ( V_6 == V_32 )
V_26 -> V_16 = V_33 ;
else if ( V_6 == V_34 )
V_26 -> V_16 = V_35 ;
else {
V_26 -> V_16 = V_17 ;
V_31 = F_1 ( V_26 -> V_2 , 0 , 0 , V_6 ) ;
if ( V_31 )
return V_31 ;
}
if ( V_26 -> V_16 == V_17 )
F_4 ( V_26 -> V_2 , 0 ) ;
F_10 ( V_26 ) ;
return V_31 ;
}
static int F_16 ( struct V_29 * V_30 ,
unsigned long * V_36 , unsigned long * V_37 )
{
struct V_25 * V_26 = F_15 ( V_30 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_22 ;
int V_31 = 0 ;
if ( * V_36 == 0 && * V_37 == 0 ) {
* V_36 = 1000 ;
* V_37 = 1000 ;
}
if ( * V_36 != * V_37 || * V_36 > 1690 || * V_36 < 6 )
return - V_21 ;
V_22 = ( * V_36 * 152 - 1 ) / 1000 ;
V_31 = F_1 ( V_2 , 0 , V_22 , V_30 -> V_19 ) ;
if ( V_31 )
return V_31 ;
if ( V_26 -> V_16 == V_17 )
F_4 ( V_26 -> V_2 , 0 ) ;
F_10 ( V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_38 * V_20 , unsigned int type ,
unsigned int V_39 , int V_6 )
{
struct V_10 * V_11 = F_18 ( V_20 ) ;
if ( ! ( type == V_40 && ( V_39 == V_41 || V_39 == V_42 ) ) )
return - 1 ;
if ( V_6 > 1 && V_6 < 32767 )
V_11 -> V_3 [ 1 ] = 127 ;
else
V_11 -> V_3 [ 1 ] = 0 ;
F_19 ( & V_11 -> V_43 ) ;
return 0 ;
}
static void F_20 ( struct V_44 * V_43 )
{
struct V_10 * V_11 =
F_21 ( V_43 , struct V_10 , V_43 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
F_5 ( & V_11 -> V_24 ) ;
F_6 ( V_11 -> V_2 , F_7 ( V_23 , 1 ) ,
V_11 -> V_3 [ 1 ] ) ;
F_9 ( & V_11 -> V_24 ) ;
}
static int F_22 ( struct V_45 * V_46 , unsigned V_47 )
{
struct V_10 * V_11 = F_23 ( V_46 ) ;
struct V_25 * V_26 = & V_11 -> V_14 [ V_47 ] ;
if ( V_26 -> type == V_48 )
return 0 ;
return - V_49 ;
}
static void F_24 ( struct V_45 * V_46 , unsigned V_47 , int V_50 )
{
struct V_10 * V_11 = F_23 ( V_46 ) ;
struct V_25 * V_26 = & V_11 -> V_14 [ V_47 ] ;
if ( V_50 )
V_26 -> V_16 = V_35 ;
else
V_26 -> V_16 = V_33 ;
F_10 ( V_26 ) ;
}
static int F_25 ( struct V_45 * V_46 , unsigned V_47 )
{
struct V_10 * V_11 = F_23 ( V_46 ) ;
unsigned char V_27 ;
V_27 = F_11 ( V_11 -> V_2 , F_26 ( V_47 ) ) ;
return ! ! ( V_27 & ( 1 << ( V_47 % 8 ) ) ) ;
}
static int F_27 ( struct V_45 * V_46 , unsigned V_47 )
{
F_24 ( V_46 , V_47 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 , unsigned V_47 , int V_50 )
{
F_24 ( V_46 , V_47 , V_50 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , int V_51 )
{
int V_9 = V_51 ;
if ( ! V_11 )
return - V_21 ;
while ( -- V_9 >= 0 ) {
switch ( V_11 -> V_14 [ V_9 ] . type ) {
case V_52 :
case V_48 :
break;
case V_15 :
F_30 ( & V_11 -> V_14 [ V_9 ] . V_18 ) ;
break;
case V_53 :
if ( V_11 -> V_54 != NULL ) {
F_31 ( & V_11 -> V_43 ) ;
V_11 -> V_54 = NULL ;
}
break;
}
}
#ifdef F_32
if ( V_11 -> V_55 . V_56 )
F_33 ( & V_11 -> V_55 ) ;
#endif
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_57 * V_58 )
{
int V_9 , V_31 = 0 ;
int V_59 = 0 ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_11 -> V_3 [ V_9 ] = V_58 -> V_3 [ V_9 ] ;
V_11 -> V_22 [ V_9 ] = V_58 -> V_22 [ V_9 ] ;
F_6 ( V_2 , F_7 ( V_23 , V_9 ) ,
V_11 -> V_3 [ V_9 ] ) ;
F_6 ( V_2 , F_8 ( V_23 , V_9 ) ,
V_11 -> V_22 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_11 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_25 * V_26 = & V_11 -> V_14 [ V_9 ] ;
struct V_25 * V_60 = & V_58 -> V_14 [ V_9 ] ;
V_26 -> V_2 = V_2 ;
V_26 -> V_28 = V_9 ;
V_26 -> type = V_60 -> type ;
switch ( V_26 -> type ) {
case V_52 :
break;
case V_48 :
V_59 ++ ;
break;
case V_15 :
V_26 -> V_16 = V_60 -> V_16 ;
V_26 -> V_61 = V_60 -> V_61 ;
V_26 -> V_18 . V_61 = V_26 -> V_61 ;
V_26 -> V_18 . V_19 = V_32 ;
V_26 -> V_18 . V_62 =
F_14 ;
V_26 -> V_18 . V_63 = F_16 ;
V_31 = F_35 ( & V_2 -> V_20 , & V_26 -> V_18 ) ;
if ( V_31 < 0 ) {
F_3 ( & V_2 -> V_20 ,
L_2 ,
V_26 -> V_61 ) ;
goto exit;
}
F_10 ( V_26 ) ;
break;
case V_53 :
F_36 ( V_11 -> V_54 ) ;
V_26 -> V_16 = V_64 ;
F_10 ( V_26 ) ;
V_11 -> V_54 = F_37 ( & V_2 -> V_20 ) ;
if ( V_11 -> V_54 == NULL ) {
V_31 = - V_65 ;
goto exit;
}
V_11 -> V_54 -> V_61 = V_60 -> V_61 ;
V_11 -> V_54 -> V_66 = L_3 ;
V_11 -> V_54 -> V_28 . V_67 = V_68 ;
V_11 -> V_54 -> V_28 . V_69 = 0x001f ;
V_11 -> V_54 -> V_28 . V_70 = 0x0001 ;
V_11 -> V_54 -> V_28 . V_71 = 0x0100 ;
V_11 -> V_54 -> V_72 [ 0 ] = F_38 ( V_40 ) ;
V_11 -> V_54 -> V_73 [ 0 ] = F_38 ( V_41 ) |
F_38 ( V_42 ) ;
V_11 -> V_54 -> V_74 = F_17 ;
F_39 ( V_11 -> V_54 , V_11 ) ;
F_40 ( & V_11 -> V_43 , F_20 ) ;
V_31 = F_41 ( V_11 -> V_54 ) ;
if ( V_31 ) {
F_31 ( & V_11 -> V_43 ) ;
V_11 -> V_54 = NULL ;
goto exit;
}
break;
}
}
#ifdef F_32
if ( V_59 ) {
V_11 -> V_55 . V_75 = L_4 ;
V_11 -> V_55 . V_76 = F_27 ;
V_11 -> V_55 . V_77 = F_28 ;
V_11 -> V_55 . V_78 = F_24 ;
V_11 -> V_55 . V_79 = F_25 ;
V_11 -> V_55 . V_80 = F_22 ;
V_11 -> V_55 . V_81 = 1 ;
V_11 -> V_55 . V_82 = V_58 -> V_83 ;
V_11 -> V_55 . V_84 = V_11 -> V_12 -> V_13 ;
V_11 -> V_55 . V_56 = & V_2 -> V_20 ;
V_11 -> V_55 . V_85 = V_86 ;
V_31 = F_42 ( & V_11 -> V_55 , V_11 ) ;
if ( V_31 ) {
V_11 -> V_55 . V_56 = NULL ;
F_43 ( & V_2 -> V_20 , L_5 ) ;
} else {
F_44 ( & V_2 -> V_20 , L_6 ,
V_11 -> V_55 . V_82 , V_11 -> V_55 . V_82 +
V_11 -> V_55 . V_84 - 1 ) ;
}
}
#endif
return 0 ;
exit:
F_29 ( V_11 , V_9 ) ;
return V_31 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_87 * V_28 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_57 * V_88 =
F_46 ( & V_2 -> V_20 ) ;
if ( ! V_88 )
return - V_89 ;
if ( ! F_47 ( V_2 -> V_90 ,
V_91 ) )
return - V_89 ;
V_11 = F_48 ( & V_2 -> V_20 , sizeof( * V_11 ) , V_92 ) ;
if ( ! V_11 )
return - V_65 ;
V_11 -> V_12 = & V_93 [ V_28 -> V_94 ] ;
F_44 ( & V_2 -> V_20 , L_7 ) ;
F_49 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
F_50 ( & V_11 -> V_24 ) ;
return F_34 ( V_2 , V_11 , V_88 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_31 ;
V_31 = F_29 ( V_11 , V_11 -> V_12 -> V_13 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
