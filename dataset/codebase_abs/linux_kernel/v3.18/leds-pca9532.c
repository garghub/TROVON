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
static void F_14 ( struct V_29 * V_30 ,
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
return;
}
F_16 ( & V_26 -> V_36 ) ;
}
static int F_17 ( struct V_29 * V_30 ,
unsigned long * V_37 , unsigned long * V_38 )
{
struct V_25 * V_26 = F_15 ( V_30 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_22 ;
int V_31 = 0 ;
if ( * V_37 == 0 && * V_38 == 0 ) {
* V_37 = 1000 ;
* V_38 = 1000 ;
}
if ( * V_37 != * V_38 || * V_37 > 1690 || * V_37 < 6 )
return - V_21 ;
V_22 = ( * V_37 * 152 - 1 ) / 1000 ;
V_31 = F_1 ( V_2 , 0 , V_22 , V_30 -> V_19 ) ;
if ( V_31 )
return V_31 ;
F_16 ( & V_26 -> V_36 ) ;
return 0 ;
}
static int F_18 ( struct V_39 * V_20 , unsigned int type ,
unsigned int V_40 , int V_6 )
{
struct V_10 * V_11 = F_19 ( V_20 ) ;
if ( ! ( type == V_41 && ( V_40 == V_42 || V_40 == V_43 ) ) )
return - 1 ;
if ( V_6 > 1 && V_6 < 32767 )
V_11 -> V_3 [ 1 ] = 127 ;
else
V_11 -> V_3 [ 1 ] = 0 ;
F_16 ( & V_11 -> V_36 ) ;
return 0 ;
}
static void F_20 ( struct V_44 * V_36 )
{
struct V_10 * V_11 =
F_21 ( V_36 , struct V_10 , V_36 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
F_5 ( & V_11 -> V_24 ) ;
F_6 ( V_11 -> V_2 , F_7 ( V_23 , 1 ) ,
V_11 -> V_3 [ 1 ] ) ;
F_9 ( & V_11 -> V_24 ) ;
}
static void F_22 ( struct V_44 * V_36 )
{
struct V_25 * V_26 ;
V_26 = F_21 ( V_36 , struct V_25 , V_36 ) ;
if ( V_26 -> V_16 == V_17 )
F_4 ( V_26 -> V_2 , 0 ) ;
F_10 ( V_26 ) ;
}
static int F_23 ( struct V_45 * V_46 , unsigned V_47 )
{
struct V_10 * V_11 = F_21 ( V_46 , struct V_10 , V_48 ) ;
struct V_25 * V_26 = & V_11 -> V_14 [ V_47 ] ;
if ( V_26 -> type == V_49 )
return 0 ;
return - V_50 ;
}
static void F_24 ( struct V_45 * V_46 , unsigned V_47 , int V_51 )
{
struct V_10 * V_11 = F_21 ( V_46 , struct V_10 , V_48 ) ;
struct V_25 * V_26 = & V_11 -> V_14 [ V_47 ] ;
if ( V_51 )
V_26 -> V_16 = V_35 ;
else
V_26 -> V_16 = V_33 ;
F_10 ( V_26 ) ;
}
static int F_25 ( struct V_45 * V_46 , unsigned V_47 )
{
struct V_10 * V_11 = F_21 ( V_46 , struct V_10 , V_48 ) ;
unsigned char V_27 ;
V_27 = F_11 ( V_11 -> V_2 , F_26 ( V_47 ) ) ;
return ! ! ( V_27 & ( 1 << ( V_47 % 8 ) ) ) ;
}
static int F_27 ( struct V_45 * V_46 , unsigned V_47 )
{
F_24 ( V_46 , V_47 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 , unsigned V_47 , int V_51 )
{
F_24 ( V_46 , V_47 , V_51 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , int V_52 )
{
int V_9 = V_52 ;
if ( ! V_11 )
return - V_21 ;
while ( -- V_9 >= 0 ) {
switch ( V_11 -> V_14 [ V_9 ] . type ) {
case V_53 :
case V_49 :
break;
case V_15 :
F_30 ( & V_11 -> V_14 [ V_9 ] . V_18 ) ;
F_31 ( & V_11 -> V_14 [ V_9 ] . V_36 ) ;
break;
case V_54 :
if ( V_11 -> V_55 != NULL ) {
F_31 ( & V_11 -> V_36 ) ;
V_11 -> V_55 = NULL ;
}
break;
}
}
#ifdef F_32
if ( V_11 -> V_48 . V_20 )
F_33 ( & V_11 -> V_48 ) ;
#endif
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_56 * V_57 )
{
int V_9 , V_31 = 0 ;
int V_58 = 0 ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_11 -> V_3 [ V_9 ] = V_57 -> V_3 [ V_9 ] ;
V_11 -> V_22 [ V_9 ] = V_57 -> V_22 [ V_9 ] ;
F_6 ( V_2 , F_7 ( V_23 , V_9 ) ,
V_11 -> V_3 [ V_9 ] ) ;
F_6 ( V_2 , F_8 ( V_23 , V_9 ) ,
V_11 -> V_22 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_11 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_25 * V_26 = & V_11 -> V_14 [ V_9 ] ;
struct V_25 * V_59 = & V_57 -> V_14 [ V_9 ] ;
V_26 -> V_2 = V_2 ;
V_26 -> V_28 = V_9 ;
V_26 -> type = V_59 -> type ;
switch ( V_26 -> type ) {
case V_53 :
break;
case V_49 :
V_58 ++ ;
break;
case V_15 :
V_26 -> V_16 = V_59 -> V_16 ;
V_26 -> V_60 = V_59 -> V_60 ;
V_26 -> V_18 . V_60 = V_26 -> V_60 ;
V_26 -> V_18 . V_19 = V_32 ;
V_26 -> V_18 . V_61 = F_14 ;
V_26 -> V_18 . V_62 = F_17 ;
F_35 ( & V_26 -> V_36 , F_22 ) ;
V_31 = F_36 ( & V_2 -> V_20 , & V_26 -> V_18 ) ;
if ( V_31 < 0 ) {
F_3 ( & V_2 -> V_20 ,
L_2 ,
V_26 -> V_60 ) ;
goto exit;
}
F_10 ( V_26 ) ;
break;
case V_54 :
F_37 ( V_11 -> V_55 ) ;
V_26 -> V_16 = V_63 ;
F_10 ( V_26 ) ;
V_11 -> V_55 = F_38 ( & V_2 -> V_20 ) ;
if ( V_11 -> V_55 == NULL ) {
V_31 = - V_64 ;
goto exit;
}
V_11 -> V_55 -> V_60 = V_59 -> V_60 ;
V_11 -> V_55 -> V_65 = L_3 ;
V_11 -> V_55 -> V_28 . V_66 = V_67 ;
V_11 -> V_55 -> V_28 . V_68 = 0x001f ;
V_11 -> V_55 -> V_28 . V_69 = 0x0001 ;
V_11 -> V_55 -> V_28 . V_70 = 0x0100 ;
V_11 -> V_55 -> V_71 [ 0 ] = F_39 ( V_41 ) ;
V_11 -> V_55 -> V_72 [ 0 ] = F_39 ( V_42 ) |
F_39 ( V_43 ) ;
V_11 -> V_55 -> V_73 = F_18 ;
F_40 ( V_11 -> V_55 , V_11 ) ;
F_35 ( & V_11 -> V_36 , F_20 ) ;
V_31 = F_41 ( V_11 -> V_55 ) ;
if ( V_31 ) {
F_31 ( & V_11 -> V_36 ) ;
V_11 -> V_55 = NULL ;
goto exit;
}
break;
}
}
#ifdef F_32
if ( V_58 ) {
V_11 -> V_48 . V_74 = L_4 ;
V_11 -> V_48 . V_75 = F_27 ;
V_11 -> V_48 . V_76 = F_28 ;
V_11 -> V_48 . V_77 = F_24 ;
V_11 -> V_48 . V_78 = F_25 ;
V_11 -> V_48 . V_79 = F_23 ;
V_11 -> V_48 . V_80 = 1 ;
V_11 -> V_48 . V_81 = V_57 -> V_82 ;
V_11 -> V_48 . V_83 = V_11 -> V_12 -> V_13 ;
V_11 -> V_48 . V_20 = & V_2 -> V_20 ;
V_11 -> V_48 . V_84 = V_85 ;
V_31 = F_42 ( & V_11 -> V_48 ) ;
if ( V_31 ) {
V_11 -> V_48 . V_20 = NULL ;
F_43 ( & V_2 -> V_20 , L_5 ) ;
} else {
F_44 ( & V_2 -> V_20 , L_6 ,
V_11 -> V_48 . V_81 , V_11 -> V_48 . V_81 +
V_11 -> V_48 . V_83 - 1 ) ;
}
}
#endif
return 0 ;
exit:
F_29 ( V_11 , V_9 ) ;
return V_31 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_86 * V_28 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_56 * V_87 =
F_46 ( & V_2 -> V_20 ) ;
if ( ! V_87 )
return - V_88 ;
if ( ! F_47 ( V_2 -> V_89 ,
V_90 ) )
return - V_88 ;
V_11 = F_48 ( & V_2 -> V_20 , sizeof( * V_11 ) , V_91 ) ;
if ( ! V_11 )
return - V_64 ;
V_11 -> V_12 = & V_92 [ V_28 -> V_93 ] ;
F_44 ( & V_2 -> V_20 , L_7 ) ;
F_49 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
F_50 ( & V_11 -> V_24 ) ;
return F_34 ( V_2 , V_11 , V_87 ) ;
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
