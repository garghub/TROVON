static const struct V_1 * F_1 ( const struct V_2 * V_3 )
{
static const struct V_1 V_4 ;
switch ( V_3 -> type ) {
case V_5 :
return & V_3 -> V_6 . V_7 . V_8 ;
case V_9 :
return & V_3 -> V_6 . V_10 . V_8 ;
default:
return & V_4 ;
}
}
static unsigned long F_2 ( struct V_11 * V_12 )
{
const struct V_1 * V_8 = F_1 ( V_12 -> V_3 ) ;
unsigned long V_13 , V_14 , V_15 ;
if ( V_8 -> V_16 ) {
V_13 = V_12 -> V_17 +
F_3 ( V_8 -> V_16 ) ;
if ( F_4 ( V_12 -> V_18 , V_13 ) )
return V_12 -> V_18 +
F_3 ( V_19 ) ;
}
if ( V_12 -> V_3 -> V_20 . V_21 ) {
if ( V_8 -> V_22 ) {
V_14 = V_12 -> V_23 -
F_3 ( V_8 -> V_22 ) ;
if ( F_4 ( V_12 -> V_18 , V_14 ) )
return V_14 ;
V_15 = V_12 -> V_18 +
F_3 ( V_19 ) ;
if ( F_4 ( V_15 , V_12 -> V_23 ) )
return V_15 ;
}
return V_12 -> V_23 ;
}
return V_12 -> V_17 ;
}
static void F_5 ( struct V_24 * V_25 )
{
struct V_11 * V_12 ;
unsigned long V_26 = V_27 ;
unsigned long V_28 = 0 ;
unsigned long V_29 ;
int V_30 = 0 ;
int V_31 ;
F_6 ( L_1 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_12 = & V_25 -> V_33 [ V_31 ] ;
if ( ! F_7 ( V_34 , & V_12 -> V_35 ) )
continue;
if ( F_7 ( V_36 , & V_12 -> V_35 ) )
V_29 = F_2 ( V_12 ) ;
else
V_29 = V_12 -> V_17 ;
if ( F_8 ( V_26 , V_29 ) &&
( ++ V_30 == 1 || F_4 ( V_29 , V_28 ) ) )
V_28 = V_29 ;
}
if ( ! V_30 ) {
F_6 ( L_2 ) ;
F_9 ( & V_25 -> V_37 ) ;
} else {
F_6 ( L_3 ) ;
F_10 ( & V_25 -> V_37 , V_28 ) ;
}
}
static int F_11 ( struct V_11 * V_12 , int V_38 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = V_12 -> V_3 ;
unsigned long V_26 = V_27 ;
int V_39 ;
int V_40 ;
int V_41 ;
int V_42 ;
if ( V_8 -> V_16 &&
F_4 ( V_26 ,
V_12 -> V_17 + F_3 ( V_8 -> V_16 ) ) ) {
F_6 ( L_4 ,
V_38 , V_8 -> V_43 ) ;
V_39 = F_12 ( V_26 - V_12 -> V_17 ) ;
V_40 = V_8 -> V_16 ;
V_41 = F_13 ( V_44 , V_8 -> V_43 , 0x7fff ) ;
} else if ( V_8 -> V_22 && V_3 -> V_20 . V_21 &&
F_14 ( V_26 ,
V_12 -> V_23 - F_3 ( V_8 -> V_22 ) ) &&
F_4 ( V_26 , V_12 -> V_23 ) ) {
V_39 = F_12 ( V_12 -> V_23 - V_26 ) ;
V_40 = V_8 -> V_22 ;
V_41 = F_13 ( V_44 , V_8 -> V_45 , 0x7fff ) ;
} else
return V_38 ;
V_42 = abs ( V_38 ) - V_41 ;
F_6 ( L_5 , V_42 ) ;
F_6 ( L_6 , V_39 ) ;
F_6 ( L_7 , V_40 ) ;
V_42 = V_42 * V_39 / V_40 ;
F_6 ( L_5 , V_42 ) ;
return V_38 < 0 ?
- ( V_42 + V_41 ) : ( V_42 + V_41 ) ;
}
static int F_15 ( struct V_46 * V_47 , int V_48 )
{
if ( F_7 ( V_48 , V_47 -> V_49 ) )
return V_48 ;
if ( V_48 == V_5 && F_7 ( V_50 , V_47 -> V_49 ) )
return V_50 ;
F_16 ( L_8 ) ;
return 0 ;
}
static V_44 F_17 ( V_44 V_51 , V_44 V_52 ,
V_44 V_53 , V_44 V_54 )
{
if ( ! V_52 )
return V_53 ;
if ( ! V_54 )
return V_51 ;
return ( ( ( V_55 ) ( V_51 >> 1 ) * V_52 +
( V_53 >> 1 ) * V_54 ) /
( V_52 + V_54 ) ) << 1 ;
}
static inline T_1 F_18 ( T_1 V_56 )
{
return ( ( V_57 ) V_56 ) >> ( 16 - V_58 ) ;
}
static inline T_1 F_19 ( T_1 V_56 , T_1 V_59 )
{
V_56 = ( ( V_57 ) V_56 * 0x100 ) / 0x7fff ;
return ( ( V_57 ) ( V_56 * V_59 ) ) >> V_58 ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_11 * V_12 ,
int V_60 )
{
struct V_2 * V_61 = V_12 -> V_3 ;
unsigned int V_62 , V_63 , V_31 ;
int V_64 , V_65 ;
T_1 V_66 ;
switch ( V_61 -> type ) {
case V_9 :
V_31 = V_61 -> V_51 * 360 / 0xffff ;
V_66 = F_18 ( F_11 ( V_12 ,
V_61 -> V_6 . V_10 . V_66 ,
& V_61 -> V_6 . V_10 . V_8 ) ) ;
V_64 = F_19 ( F_21 ( V_31 ) , V_66 ) * V_60 / 0xffff ;
V_65 = F_19 ( - F_22 ( V_31 ) , V_66 ) * V_60 / 0xffff ;
V_3 -> V_6 . V_67 . V_68 =
F_23 ( V_3 -> V_6 . V_67 . V_68 + V_64 , - 0x80 , 0x7f ) ;
V_3 -> V_6 . V_67 . V_69 =
F_23 ( V_3 -> V_6 . V_67 . V_69 + V_65 , - 0x80 , 0x7f ) ;
break;
case V_50 :
V_62 = ( V_55 ) V_61 -> V_6 . V_70 . V_71 * V_60 / 0xffff ;
V_63 = ( V_55 ) V_61 -> V_6 . V_70 . V_72 * V_60 / 0xffff ;
if ( V_3 -> V_6 . V_70 . V_71 + V_62 )
V_3 -> V_51 = F_17 (
V_3 -> V_51 ,
V_3 -> V_6 . V_70 . V_71 ,
V_61 -> V_51 , V_62 ) ;
else if ( V_3 -> V_6 . V_70 . V_72 + V_63 )
V_3 -> V_51 = F_17 (
V_3 -> V_51 ,
V_3 -> V_6 . V_70 . V_72 ,
V_61 -> V_51 , V_63 ) ;
else
V_3 -> V_51 = 0 ;
V_3 -> V_6 . V_70 . V_71 =
F_24 ( V_62 + V_3 -> V_6 . V_70 . V_71 ,
0xffffU ) ;
V_3 -> V_6 . V_70 . V_72 =
F_24 ( V_63 + V_3 -> V_6 . V_70 . V_72 , 0xffffU ) ;
break;
case V_5 :
V_31 = F_11 ( V_12 , abs ( V_61 -> V_6 . V_7 . V_73 ) ,
& V_61 -> V_6 . V_7 . V_8 ) ;
V_31 = V_31 * V_60 / 0x7fff ;
if ( V_3 -> V_6 . V_70 . V_71 + V_31 )
V_3 -> V_51 = F_17 (
V_3 -> V_51 ,
V_3 -> V_6 . V_70 . V_71 ,
V_61 -> V_51 , V_31 ) ;
else
V_3 -> V_51 = 0 ;
V_3 -> V_6 . V_70 . V_71 =
F_24 ( V_31 + V_3 -> V_6 . V_70 . V_71 , 0xffffU ) ;
V_3 -> V_6 . V_70 . V_72 =
F_24 ( V_31 + V_3 -> V_6 . V_70 . V_72 , 0xffffU ) ;
break;
default:
F_16 ( L_9 ) ;
break;
}
}
static int F_25 ( struct V_24 * V_25 ,
unsigned long * V_74 ,
struct V_2 * V_75 )
{
struct V_2 * V_3 ;
struct V_11 * V_12 ;
int V_48 ;
int V_31 ;
memset ( V_75 , 0 , sizeof( struct V_2 ) ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
if ( F_26 ( V_31 , V_74 ) )
continue;
V_12 = & V_25 -> V_33 [ V_31 ] ;
V_3 = V_12 -> V_3 ;
if ( ! F_7 ( V_34 , & V_12 -> V_35 ) )
continue;
if ( F_4 ( V_27 , V_12 -> V_17 ) )
continue;
V_48 = F_15 ( V_25 -> V_76 -> V_47 , V_3 -> type ) ;
if ( V_75 -> type != V_48 ) {
if ( V_75 -> type != 0 ) {
F_27 ( V_31 , V_74 ) ;
continue;
}
V_75 -> type = V_48 ;
}
if ( F_28 ( V_77 , & V_12 -> V_35 ) ) {
F_27 ( V_36 , & V_12 -> V_35 ) ;
F_27 ( V_34 , & V_12 -> V_35 ) ;
} else if ( V_3 -> V_20 . V_21 &&
F_29 ( V_27 , V_12 -> V_23 ) ) {
F_27 ( V_36 , & V_12 -> V_35 ) ;
if ( -- V_12 -> V_78 <= 0 ) {
F_27 ( V_34 , & V_12 -> V_35 ) ;
} else {
V_12 -> V_17 = V_27 +
F_3 ( V_3 -> V_20 . V_79 ) ;
V_12 -> V_23 = V_12 -> V_17 +
F_3 ( V_3 -> V_20 . V_21 ) ;
}
} else {
F_30 ( V_36 , & V_12 -> V_35 ) ;
V_12 -> V_18 = V_27 ;
F_20 ( V_75 , V_12 , V_25 -> V_60 ) ;
}
}
return V_75 -> type != 0 ;
}
static void F_31 ( struct V_24 * V_25 )
{
struct V_2 V_3 ;
F_32 ( V_80 , V_32 ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
while ( F_25 ( V_25 , V_80 , & V_3 ) )
V_25 -> V_81 ( V_25 -> V_76 , V_25 -> V_82 , & V_3 ) ;
F_5 ( V_25 ) ;
}
static void F_33 ( unsigned long V_83 )
{
struct V_84 * V_76 = (struct V_84 * ) V_83 ;
struct V_24 * V_25 = V_76 -> V_47 -> V_82 ;
unsigned long V_35 ;
F_6 ( L_10 ) ;
F_34 ( & V_76 -> V_85 , V_35 ) ;
F_31 ( V_25 ) ;
F_35 ( & V_76 -> V_85 , V_35 ) ;
}
static void F_36 ( struct V_84 * V_76 , V_44 V_60 )
{
struct V_24 * V_25 = V_76 -> V_47 -> V_82 ;
int V_31 ;
V_25 -> V_60 = V_60 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
F_27 ( V_36 , & V_25 -> V_33 [ V_31 ] . V_35 ) ;
F_31 ( V_25 ) ;
}
static int F_37 ( struct V_84 * V_76 , int V_86 , int V_38 )
{
struct V_24 * V_25 = V_76 -> V_47 -> V_82 ;
struct V_11 * V_12 = & V_25 -> V_33 [ V_86 ] ;
if ( V_38 > 0 ) {
F_6 ( L_11 ) ;
F_30 ( V_34 , & V_12 -> V_35 ) ;
V_12 -> V_78 = V_38 ;
V_12 -> V_17 = V_27 +
F_3 ( V_12 -> V_3 -> V_20 . V_79 ) ;
V_12 -> V_23 = V_12 -> V_17 +
F_3 ( V_12 -> V_3 -> V_20 . V_21 ) ;
V_12 -> V_18 = V_12 -> V_17 ;
} else {
F_6 ( L_12 ) ;
if ( F_7 ( V_36 , & V_12 -> V_35 ) )
F_30 ( V_77 , & V_12 -> V_35 ) ;
else
F_27 ( V_34 , & V_12 -> V_35 ) ;
}
F_31 ( V_25 ) ;
return 0 ;
}
static int F_38 ( struct V_84 * V_76 ,
struct V_2 * V_3 , struct V_2 * V_87 )
{
struct V_24 * V_25 = V_76 -> V_47 -> V_82 ;
struct V_11 * V_12 = & V_25 -> V_33 [ V_3 -> V_88 ] ;
F_39 ( & V_76 -> V_85 ) ;
if ( F_7 ( V_34 , & V_12 -> V_35 ) ) {
F_27 ( V_36 , & V_12 -> V_35 ) ;
V_12 -> V_17 = V_27 +
F_3 ( V_12 -> V_3 -> V_20 . V_79 ) ;
V_12 -> V_23 = V_12 -> V_17 +
F_3 ( V_12 -> V_3 -> V_20 . V_21 ) ;
V_12 -> V_18 = V_12 -> V_17 ;
F_5 ( V_25 ) ;
}
F_40 ( & V_76 -> V_85 ) ;
return 0 ;
}
static void F_41 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_82 ;
F_42 ( V_25 -> V_82 ) ;
}
int F_43 ( struct V_84 * V_76 , void * V_89 ,
int (* V_81)( struct V_84 * , void * , struct V_2 * ) )
{
struct V_24 * V_25 ;
struct V_46 * V_47 ;
int error ;
int V_31 ;
V_25 = F_44 ( sizeof( struct V_24 ) , V_90 ) ;
if ( ! V_25 )
return - V_91 ;
V_25 -> V_76 = V_76 ;
V_25 -> V_82 = V_89 ;
V_25 -> V_81 = V_81 ;
V_25 -> V_60 = 0xffff ;
F_45 ( & V_25 -> V_37 , F_33 , ( unsigned long ) V_76 ) ;
F_46 ( V_92 , V_76 -> V_49 ) ;
error = F_47 ( V_76 , V_32 ) ;
if ( error ) {
F_42 ( V_25 ) ;
return error ;
}
V_47 = V_76 -> V_47 ;
V_47 -> V_82 = V_25 ;
V_47 -> V_93 = F_38 ;
V_47 -> V_94 = F_37 ;
V_47 -> V_95 = F_36 ;
V_47 -> V_96 = F_41 ;
if ( F_7 ( V_50 , V_47 -> V_49 ) ) {
F_46 ( V_5 , V_76 -> V_49 ) ;
F_46 ( V_97 , V_76 -> V_49 ) ;
F_46 ( V_98 , V_76 -> V_49 ) ;
F_46 ( V_99 , V_76 -> V_49 ) ;
}
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
V_25 -> V_33 [ V_31 ] . V_3 = & V_47 -> V_100 [ V_31 ] ;
return 0 ;
}
