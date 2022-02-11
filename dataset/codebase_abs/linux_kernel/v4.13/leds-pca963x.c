static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 = V_2 -> V_6 -> V_7 -> V_8
+ ( V_2 -> V_9 / 4 ) ;
T_1 V_10 ;
int V_11 = 2 * ( V_2 -> V_9 % 4 ) ;
T_1 V_12 = 0x3 << V_11 ;
int V_13 ;
V_10 = F_2 ( V_2 -> V_6 -> V_14 , V_5 ) ;
switch ( V_4 ) {
case V_15 :
V_13 = F_3 ( V_2 -> V_6 -> V_14 ,
V_5 ,
( V_10 & ~ V_12 ) | ( V_16 << V_11 ) ) ;
break;
case V_17 :
V_13 = F_3 ( V_2 -> V_6 -> V_14 ,
V_5 , V_10 & ~ V_12 ) ;
break;
default:
V_13 = F_3 ( V_2 -> V_6 -> V_14 ,
V_18 + V_2 -> V_9 ,
V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_3 ( V_2 -> V_6 -> V_14 ,
V_5 ,
( V_10 & ~ V_12 ) | ( V_19 << V_11 ) ) ;
break;
}
return V_13 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_5 = V_2 -> V_6 -> V_7 -> V_8 +
( V_2 -> V_9 / 4 ) ;
T_1 V_10 ;
T_1 V_20 = F_2 ( V_2 -> V_6 -> V_14 ,
V_21 ) ;
int V_11 = 2 * ( V_2 -> V_9 % 4 ) ;
T_1 V_12 = 0x3 << V_11 ;
F_3 ( V_2 -> V_6 -> V_14 ,
V_2 -> V_6 -> V_7 -> V_22 , V_2 -> V_23 ) ;
F_3 ( V_2 -> V_6 -> V_14 ,
V_2 -> V_6 -> V_7 -> V_24 , V_2 -> V_25 ) ;
if ( ! ( V_20 & V_26 ) )
F_3 ( V_2 -> V_6 -> V_14 , V_21 ,
V_20 | V_26 ) ;
F_5 ( & V_2 -> V_6 -> V_27 ) ;
V_10 = F_2 ( V_2 -> V_6 -> V_14 , V_5 ) ;
if ( ( V_10 & V_12 ) != ( V_28 << V_11 ) )
F_3 ( V_2 -> V_6 -> V_14 , V_5 ,
( V_10 & ~ V_12 ) | ( V_28 << V_11 ) ) ;
F_6 ( & V_2 -> V_6 -> V_27 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long * V_29 = & V_2 -> V_6 -> V_29 ;
unsigned long V_30 = V_2 -> V_6 -> V_29 ;
if ( V_2 -> V_31 . V_4 )
F_8 ( V_2 -> V_9 , V_29 ) ;
else
F_9 ( V_2 -> V_9 , V_29 ) ;
if ( ! ( * V_29 ) != ! V_30 )
return F_3 ( V_2 -> V_6 -> V_14 ,
V_32 , * V_29 ? 0 : F_10 ( 4 ) ) ;
return 0 ;
}
static int F_11 ( struct V_33 * V_31 ,
enum V_3 V_34 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_12 ( V_31 , struct V_1 , V_31 ) ;
F_5 ( & V_2 -> V_6 -> V_27 ) ;
V_13 = F_1 ( V_2 , V_34 ) ;
if ( V_13 < 0 )
goto V_35;
V_13 = F_7 ( V_2 ) ;
V_35:
F_6 ( & V_2 -> V_6 -> V_27 ) ;
return V_13 ;
}
static unsigned int F_13 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned int V_37 = V_2 -> V_6 -> V_7 -> V_37 ;
return V_37 ? F_14 ( V_36 * V_37 , 1000 ) : V_36 ;
}
static int F_15 ( struct V_33 * V_31 ,
unsigned long * V_38 , unsigned long * V_39 )
{
struct V_1 * V_2 ;
unsigned long V_40 , V_41 , V_42 ;
T_1 V_23 , V_25 ;
V_2 = F_12 ( V_31 , struct V_1 , V_31 ) ;
V_40 = * V_38 ;
V_41 = * V_39 ;
if ( ! V_40 && ! V_41 ) {
V_40 = 500 ;
V_41 = 500 ;
}
V_42 = F_13 ( V_2 , V_40 + V_41 ) ;
if ( ( V_42 < V_43 ) ||
( V_42 > V_44 ) ) {
V_40 = 500 ;
V_41 = 500 ;
V_42 = F_13 ( V_2 , 1000 ) ;
}
V_23 = ( F_13 ( V_2 , V_40 ) * 256 ) / V_42 ;
V_25 = ( V_42 * 24 / 1000 ) - 1 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_25 = V_25 ;
F_4 ( V_2 ) ;
* V_38 = V_40 ;
* V_39 = V_41 ;
return 0 ;
}
static struct V_45 *
F_16 ( struct V_46 * V_14 , struct V_47 * V_6 )
{
struct V_48 * V_49 = V_14 -> V_50 . V_51 , * V_52 ;
struct V_45 * V_53 ;
struct V_54 * V_55 ;
int V_56 ;
V_56 = F_17 ( V_49 ) ;
if ( ! V_56 || V_56 > V_6 -> V_57 )
return F_18 ( - V_58 ) ;
V_55 = F_19 ( & V_14 -> V_50 ,
sizeof( struct V_54 ) * V_6 -> V_57 , V_59 ) ;
if ( ! V_55 )
return F_18 ( - V_60 ) ;
F_20 (np, child) {
struct V_54 V_61 = {} ;
T_2 V_62 ;
int V_63 ;
V_63 = F_21 ( V_52 , L_1 , & V_62 ) ;
if ( ( V_63 != 0 ) || ( V_62 >= V_6 -> V_57 ) )
continue;
V_61 . V_64 =
F_22 ( V_52 , L_2 , NULL ) ? : V_52 -> V_64 ;
V_61 . V_65 =
F_22 ( V_52 , L_3 , NULL ) ;
V_55 [ V_62 ] = V_61 ;
}
V_53 = F_19 ( & V_14 -> V_50 ,
sizeof( struct V_45 ) , V_59 ) ;
if ( ! V_53 )
return F_18 ( - V_60 ) ;
V_53 -> V_66 . V_66 = V_55 ;
V_53 -> V_66 . V_67 = V_6 -> V_57 ;
if ( F_23 ( V_49 , L_4 ) )
V_53 -> V_68 = V_69 ;
else
V_53 -> V_68 = V_70 ;
if ( F_23 ( V_49 , L_5 ) )
V_53 -> V_71 = V_72 ;
else
V_53 -> V_71 = V_73 ;
if ( F_21 ( V_49 , L_6 , & V_6 -> V_37 ) )
V_6 -> V_37 = 1000 ;
if ( F_23 ( V_49 , L_7 ) )
V_53 -> V_74 = V_75 ;
else
V_53 -> V_74 = V_76 ;
return V_53 ;
}
static struct V_45 *
F_16 ( struct V_46 * V_14 , struct V_47 * V_6 )
{
return F_18 ( - V_58 ) ;
}
static int F_24 ( struct V_46 * V_14 ,
const struct V_77 * V_78 )
{
struct V_2 * V_79 ;
struct V_1 * V_2 ;
struct V_45 * V_53 ;
struct V_47 * V_6 ;
int V_80 , V_81 ;
if ( V_78 ) {
V_6 = & V_82 [ V_78 -> V_83 ] ;
} else {
const struct V_84 * V_85 ;
V_85 = F_25 ( V_86 , & V_14 -> V_50 ) ;
if ( ! V_85 )
return - V_58 ;
V_6 = & V_82 [ V_85 -> V_83 ] ;
}
V_53 = F_26 ( & V_14 -> V_50 ) ;
if ( ! V_53 ) {
V_53 = F_16 ( V_14 , V_6 ) ;
if ( F_27 ( V_53 ) ) {
F_28 ( & V_14 -> V_50 , L_8 ) ;
V_53 = NULL ;
}
}
if ( V_53 && ( V_53 -> V_66 . V_67 < 1 ||
V_53 -> V_66 . V_67 > V_6 -> V_57 ) ) {
F_29 ( & V_14 -> V_50 , L_9 ,
V_6 -> V_57 ) ;
return - V_87 ;
}
V_79 = F_19 ( & V_14 -> V_50 , sizeof( * V_79 ) ,
V_59 ) ;
if ( ! V_79 )
return - V_60 ;
V_2 = F_19 ( & V_14 -> V_50 , V_6 -> V_57 * sizeof( * V_2 ) ,
V_59 ) ;
if ( ! V_2 )
return - V_60 ;
F_30 ( V_14 , V_79 ) ;
F_31 ( & V_79 -> V_27 ) ;
V_79 -> V_7 = V_6 ;
V_79 -> V_14 = V_14 ;
V_79 -> V_66 = V_2 ;
for ( V_80 = 0 ; V_80 < V_6 -> V_57 / 4 ; V_80 ++ )
F_3 ( V_14 , V_6 -> V_8 + V_80 , 0x00 ) ;
for ( V_80 = 0 ; V_80 < V_6 -> V_57 ; V_80 ++ ) {
V_2 [ V_80 ] . V_9 = V_80 ;
V_2 [ V_80 ] . V_6 = V_79 ;
if ( V_53 && V_80 < V_53 -> V_66 . V_67 ) {
if ( V_53 -> V_66 . V_66 [ V_80 ] . V_64 )
snprintf ( V_2 [ V_80 ] . V_64 ,
sizeof( V_2 [ V_80 ] . V_64 ) , L_10 ,
V_53 -> V_66 . V_66 [ V_80 ] . V_64 ) ;
if ( V_53 -> V_66 . V_66 [ V_80 ] . V_65 )
V_2 [ V_80 ] . V_31 . V_65 =
V_53 -> V_66 . V_66 [ V_80 ] . V_65 ;
}
if ( ! V_53 || V_80 >= V_53 -> V_66 . V_67 ||
! V_53 -> V_66 . V_66 [ V_80 ] . V_64 )
snprintf ( V_2 [ V_80 ] . V_64 , sizeof( V_2 [ V_80 ] . V_64 ) ,
L_11 , V_14 -> V_88 -> V_89 ,
V_14 -> V_90 , V_80 ) ;
V_2 [ V_80 ] . V_31 . V_64 = V_2 [ V_80 ] . V_64 ;
V_2 [ V_80 ] . V_31 . V_91 = F_11 ;
if ( V_53 && V_53 -> V_71 == V_72 )
V_2 [ V_80 ] . V_31 . V_92 = F_15 ;
V_81 = F_32 ( & V_14 -> V_50 , & V_2 [ V_80 ] . V_31 ) ;
if ( V_81 < 0 )
goto exit;
}
F_3 ( V_14 , V_32 , F_10 ( 4 ) ) ;
if ( V_53 ) {
T_1 V_20 = F_2 ( V_2 -> V_6 -> V_14 ,
V_21 ) ;
if ( V_53 -> V_68 == V_70 )
V_20 |= 0x01 ;
else
V_20 |= 0x05 ;
if ( V_53 -> V_74 == V_75 )
V_20 |= 0x10 ;
F_3 ( V_2 -> V_6 -> V_14 , V_21 ,
V_20 ) ;
}
return 0 ;
exit:
while ( V_80 -- )
F_33 ( & V_2 [ V_80 ] . V_31 ) ;
return V_81 ;
}
static int F_34 ( struct V_46 * V_14 )
{
struct V_2 * V_2 = F_35 ( V_14 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_2 -> V_7 -> V_57 ; V_80 ++ )
F_33 ( & V_2 -> V_66 [ V_80 ] . V_31 ) ;
return 0 ;
}
