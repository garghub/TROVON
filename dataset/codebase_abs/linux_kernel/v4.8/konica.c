static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
V_6 = F_2 ( V_5 , F_3 ( V_5 , 0 ) ,
0x02 ,
V_8 | V_9 | V_10 ,
V_2 ,
V_3 ,
NULL ,
0 ,
1000 ) ;
if ( V_6 < 0 ) {
F_4 ( L_1 ,
V_2 , V_3 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
V_6 = F_2 ( V_5 , F_6 ( V_5 , 0 ) ,
0x03 ,
V_11 | V_9 | V_10 ,
V_2 ,
V_3 ,
V_1 -> V_12 ,
2 ,
1000 ) ;
if ( V_6 < 0 ) {
F_4 ( L_2 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static void F_7 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 1 , 0x0b ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 , 0x0b ) ;
}
static int F_9 ( struct V_1 * V_1 ,
const struct V_13 * V_14 )
{
V_1 -> V_15 . V_16 = V_17 ;
V_1 -> V_15 . V_18 = F_10 ( V_17 ) ;
V_1 -> V_15 . V_19 = 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_20 ;
F_12 ( 6000 ) ;
for ( V_20 = 0 ; V_20 < 20 ; V_20 ++ ) {
F_5 ( V_1 , 0 , 0x10 ) ;
if ( V_1 -> V_12 [ 0 ] == 3 )
break;
F_12 ( 100 ) ;
}
F_1 ( V_1 , 0 , 0x0d ) ;
return V_1 -> V_7 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
struct V_22 * V_22 ;
int V_20 , V_23 , V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_28 = F_14 ( V_21 -> V_1 . V_5 , V_21 -> V_1 . V_29 ) ;
V_26 = F_15 ( V_28 , V_21 -> V_1 . V_26 ) ;
if ( ! V_26 ) {
F_4 ( L_3 ) ;
return - V_30 ;
}
V_24 = F_16 ( V_26 -> V_31 [ 0 ] . V_32 . V_33 ) ;
V_23 = V_1 -> V_15 . V_16 [ V_1 -> V_34 ] . V_35 ;
F_1 ( V_1 , V_23 , 0x08 ) ;
F_7 ( V_1 ) ;
if ( V_1 -> V_7 )
return V_1 -> V_7 ;
#if V_36 < 4
#error "Not enough URBs in the gspca table"
#endif
#define F_17 32
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
V_20 = V_23 & 1 ? 0 : 1 ;
V_24 =
F_16 ( V_26 -> V_31 [ V_20 ] . V_32 . V_33 ) ;
V_22 = F_18 ( F_17 , V_37 ) ;
if ( ! V_22 ) {
F_4 ( L_4 ) ;
return - V_38 ;
}
V_1 -> V_22 [ V_23 ] = V_22 ;
V_22 -> V_39 = F_19 ( V_1 -> V_5 ,
V_24 * F_17 ,
V_37 ,
& V_22 -> V_40 ) ;
if ( V_22 -> V_39 == NULL ) {
F_4 ( L_5 ) ;
return - V_38 ;
}
V_22 -> V_5 = V_1 -> V_5 ;
V_22 -> V_41 = V_1 ;
V_22 -> V_42 = V_24 * F_17 ;
V_22 -> V_43 = F_20 ( V_1 -> V_5 ,
V_23 & 1 ? 0x81 : 0x82 ) ;
V_22 -> V_44 = V_45
| V_46 ;
V_22 -> V_47 = 1 ;
V_22 -> V_48 = V_49 ;
V_22 -> V_50 = F_17 ;
for ( V_20 = 0 ; V_20 < F_17 ; V_20 ++ ) {
V_22 -> V_51 [ V_20 ] . V_52 = V_24 ;
V_22 -> V_51 [ V_20 ] . V_53 = V_24 * V_20 ;
}
}
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_21 * V_21 V_54 = (struct V_21 * ) V_1 ;
F_8 ( V_1 ) ;
#if F_22 ( V_55 )
if ( V_21 -> V_56 ) {
F_23 ( V_1 -> V_57 , V_58 , 0 ) ;
F_24 ( V_1 -> V_57 ) ;
V_21 -> V_56 = 0 ;
}
#endif
}
static void V_49 ( struct V_22 * V_22 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 -> V_41 ;
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
struct V_22 * V_59 , * V_60 ;
T_2 * V_61 ;
int V_20 , V_62 ;
F_25 ( V_63 , L_6 ) ;
if ( ! V_1 -> V_64 )
return;
if ( V_22 -> V_65 != 0 ) {
if ( V_22 -> V_65 == - V_66 )
return;
#ifdef F_26
if ( V_1 -> V_67 )
return;
#endif
F_27 ( L_7 , V_22 -> V_65 ) ;
V_62 = F_28 ( V_22 , V_68 ) ;
if ( V_62 < 0 )
F_4 ( L_8 , V_62 ) ;
return;
}
if ( V_22 -> V_42 > 32 ) {
V_21 -> V_69 = V_22 ;
return;
}
V_60 = V_22 ;
V_59 = V_21 -> V_69 ;
V_21 -> V_69 = NULL ;
if ( ! V_59 || V_59 -> V_70 != V_60 -> V_70 ) {
F_27 ( L_9 ) ;
goto V_71;
}
if ( V_59 -> V_50 != V_60 -> V_50 ) {
F_27 ( L_10 ,
V_59 -> V_50 ,
V_60 -> V_50 ) ;
goto V_71;
}
for ( V_20 = 0 ; V_20 < V_60 -> V_50 ; V_20 ++ ) {
if ( V_59 -> V_51 [ V_20 ] . V_65 ||
V_60 -> V_51 [ V_20 ] . V_65 ) {
F_27 ( L_11 , V_20 ,
V_59 -> V_51 [ V_20 ] . V_65 ,
V_60 -> V_51 [ V_20 ] . V_65 ) ;
V_1 -> V_72 = V_73 ;
continue;
}
if ( V_60 -> V_51 [ V_20 ] . V_74 != 1 ) {
F_27 ( L_12 ,
V_60 -> V_51 [ V_20 ] . V_74 ) ;
V_1 -> V_72 = V_73 ;
continue;
}
V_62 = * ( ( T_2 * ) V_60 -> V_39
+ V_60 -> V_51 [ V_20 ] . V_53 ) ;
V_61 = ( T_2 * ) V_59 -> V_39
+ V_59 -> V_51 [ V_20 ] . V_53 ;
if ( V_62 & 0x80 ) {
F_29 ( V_1 , V_75 , NULL , 0 ) ;
F_29 ( V_1 , V_76 , NULL , 0 ) ;
} else {
#if F_22 ( V_55 )
T_2 V_77 = V_62 & 0x40 ? 1 : 0 ;
if ( V_21 -> V_56 != V_77 ) {
F_23 ( V_1 -> V_57 ,
V_58 ,
V_77 ) ;
F_24 ( V_1 -> V_57 ) ;
V_21 -> V_56 = V_77 ;
}
#endif
if ( V_62 & 0x01 )
continue;
}
F_29 ( V_1 , V_78 , V_61 ,
V_59 -> V_51 [ V_20 ] . V_74 ) ;
}
V_71:
if ( V_59 ) {
V_62 = F_28 ( V_59 , V_68 ) ;
if ( V_62 < 0 )
F_27 ( L_13 , V_62 ) ;
}
V_62 = F_28 ( V_60 , V_68 ) ;
if ( V_62 < 0 )
F_27 ( L_14 , V_62 ) ;
}
static int F_30 ( struct V_79 * V_80 )
{
struct V_1 * V_1 =
F_31 ( V_80 -> V_81 , struct V_1 , V_82 ) ;
V_1 -> V_7 = 0 ;
if ( ! V_1 -> V_64 )
return 0 ;
switch ( V_80 -> V_14 ) {
case V_83 :
F_8 ( V_1 ) ;
F_1 ( V_1 , V_80 -> V_84 , V_85 ) ;
F_7 ( V_1 ) ;
break;
case V_86 :
F_8 ( V_1 ) ;
F_1 ( V_1 , V_80 -> V_84 , V_87 ) ;
F_7 ( V_1 ) ;
break;
case V_88 :
F_8 ( V_1 ) ;
F_1 ( V_1 , V_80 -> V_84 , V_89 ) ;
F_7 ( V_1 ) ;
break;
case V_90 :
F_8 ( V_1 ) ;
F_1 ( V_1 , V_80 -> V_84 , V_91 ) ;
F_7 ( V_1 ) ;
break;
case V_92 :
F_8 ( V_1 ) ;
F_1 ( V_1 , V_80 -> V_84 , V_93 ) ;
F_7 ( V_1 ) ;
break;
}
return V_1 -> V_7 ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_94 * V_95 = & V_1 -> V_82 ;
V_1 -> V_96 . V_82 = V_95 ;
F_33 ( V_95 , 5 ) ;
F_34 ( V_95 , & V_97 ,
V_83 , 0 , 9 , 1 , 4 ) ;
F_34 ( V_95 , & V_97 ,
V_86 , 0 , 9 , 1 , 4 ) ;
F_34 ( V_95 , & V_97 ,
V_88 , 0 , 9 , 1 , 4 ) ;
F_34 ( V_95 , & V_97 ,
V_90 ,
0 , 33 , 1 , 25 ) ;
F_34 ( V_95 , & V_97 ,
V_92 , 0 , 9 , 1 , 4 ) ;
if ( V_95 -> error ) {
F_4 ( L_15 ) ;
return V_95 -> error ;
}
return 0 ;
}
static int F_35 ( struct V_27 * V_28 ,
const struct V_13 * V_14 )
{
return F_36 ( V_28 , V_14 , & V_98 , sizeof( struct V_21 ) ,
V_99 ) ;
}
