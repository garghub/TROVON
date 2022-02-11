int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
int V_8 = ( V_6 == NULL || V_7 == 0 ) ;
int V_9 ;
T_1 V_10 [ 1 + V_5 ] ;
F_2 ( L_1 , V_11 , V_5 , V_7 ) ;
memset ( V_10 , 0 , 1 + V_5 ) ;
V_10 [ 0 ] = V_3 ;
memcpy ( & V_10 [ 1 ] , V_4 , V_5 ) ;
V_9 = ( V_8 ) ? F_3 ( V_2 , V_10 , 1 + V_5 ) :
F_4 ( V_2 , V_10 , 1 + V_5 , V_6 , V_7 , 0 ) ;
F_5 ( V_9 ) ;
return V_9 ;
}
int F_6 ( struct V_12 * V_13 , T_1 V_14 , T_1 * V_15 )
{
T_1 V_16 [ 2 ] ;
int V_9 ;
V_9 = F_1 ( V_13 -> V_2 , V_17 , & V_14 , 1 , V_16 , 2 ) ;
if ( F_5 ( V_9 ) ) {
F_7 ( L_2 , V_14 ) ;
goto V_18;
}
if ( V_16 [ 0 ] == V_14 )
* V_15 = V_16 [ 1 ] ;
else {
F_8 ( L_3 ,
V_14 , V_16 [ 0 ] , V_16 [ 1 ] ) ;
V_9 = - V_19 ;
}
F_9 ( L_4 , V_14 , * V_15 ) ;
V_18:
return V_9 ;
}
int F_10 ( struct V_12 * V_13 , T_1 V_14 , T_1 V_15 )
{
T_1 V_16 [] = { V_14 , V_15 } ;
int V_9 ;
F_9 ( L_5 , V_14 , V_15 ) ;
V_9 = F_1 ( V_13 -> V_2 , V_20 , V_16 , 2 , NULL , 0 ) ;
if ( F_5 ( V_9 ) )
F_8 ( L_6 , V_14 , V_15 ) ;
return V_9 ;
}
int F_11 ( struct V_12 * V_13 ,
T_1 V_14 , T_1 V_21 , T_1 V_15 )
{
int V_9 ;
T_1 V_22 ;
if ( V_21 != 0xff ) {
V_9 = F_6 ( V_13 , V_14 , & V_22 ) ;
#if 1
if ( F_5 ( V_9 ) )
F_8 ( L_7
L_8 , V_14 , V_21 , V_15 ) ;
V_9 = F_6 ( V_13 , V_14 , & V_22 ) ;
#endif
if ( F_5 ( V_9 ) )
goto V_18;
}
V_22 &= ~ V_21 ;
V_22 |= V_15 ;
V_9 = F_10 ( V_13 , V_14 , V_22 ) ;
F_5 ( V_9 ) ;
V_18:
return V_9 ;
}
int F_12 ( struct V_12 * V_13 ,
struct V_23 * V_24 )
{
int V_25 , V_9 = 0 ;
for ( V_25 = 0 ; V_24 [ V_25 ] . V_14 |
V_24 [ V_25 ] . V_21 |
V_24 [ V_25 ] . V_15 ; V_25 ++ ) {
V_9 = F_11 ( V_13 ,
V_24 [ V_25 ] . V_14 ,
V_24 [ V_25 ] . V_21 ,
V_24 [ V_25 ] . V_15 ) ;
if ( F_5 ( V_9 ) ) {
F_8 ( L_9 , V_25 ,
V_24 [ V_25 ] . V_14 ) ;
break;
}
}
return V_9 ;
}
static int F_13 ( struct V_12 * V_13 )
{
int V_9 ;
T_1 V_26 , V_27 ;
char * V_28 , * V_29 ;
if ( ( V_13 -> V_30 ) && ( V_13 -> V_31 ) )
return 0 ;
V_9 = F_6 ( V_13 , V_32 , & V_26 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_13 -> V_30 = V_26 ;
V_9 = F_6 ( V_13 , V_33 , & V_27 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_13 -> V_31 = V_27 ;
switch ( V_26 ) {
case 0x61 :
V_28 = L_10 ;
break;
case 0x63 :
V_28 = L_11 ;
break;
default:
V_28 = L_12 ;
break;
}
switch ( V_27 ) {
case 0x36 :
V_13 -> V_34 = V_35 ;
V_29 = L_13 ;
break;
case 0x08 :
V_13 -> V_34 = V_36 ;
V_29 = L_14 ;
break;
case 0x18 :
V_13 -> V_34 = V_37 ;
V_29 = L_15 ;
break;
default:
V_13 -> V_34 = 0 ;
V_29 = L_16 ;
break;
}
F_14 ( L_17 , V_28 , V_29 , V_27 ) ;
V_18:
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , int V_38 )
{
return 0 ;
}
static int F_16 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 -> V_44 ;
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
struct V_46 * V_47 = V_42 -> V_48 [ V_40 -> V_26 ] . V_44 ;
int F_8 ;
if ( ! V_13 -> V_30 ) {
F_7 ( L_18 ) ;
goto V_18;
}
F_17 ( L_19 , V_11 ) ;
F_18 ( & V_13 -> V_49 ) ;
V_13 -> V_50 = V_47 -> V_50 ;
if ( F_19 ( V_42 -> V_45 -> V_51 , 0 , V_13 -> V_50 ) < 0 )
F_8 ( L_20 ) ;
F_8 = F_20 ( V_13 ) ;
F_5 ( F_8 ) ;
F_8 = F_21 ( V_13 ) ;
F_5 ( F_8 ) ;
F_8 = F_22 ( V_13 , V_47 -> V_52 ) ;
F_5 ( F_8 ) ;
F_23 ( V_13 ) ;
F_5 ( F_8 ) ;
F_24 ( V_13 , 1 ) ;
F_5 ( F_8 ) ;
if ( ( V_53 != V_47 -> V_54 ) &&
( V_13 -> V_34 > V_35 ) ) {
F_25 ( V_13 ,
V_55 ) ;
F_5 ( F_8 ) ;
}
F_8 = F_26 ( V_13 ) ;
if ( ! F_5 ( F_8 ) ) {
V_13 -> V_54 = V_47 -> V_54 ;
F_8 = F_27 ( V_13 , V_13 -> V_54 ) ;
F_5 ( F_8 ) ;
#if 0
err = fe->ops.init(fe);
#endif
F_28 ( 100 ) ;
}
return ( V_47 -> V_56 ) ? V_47 -> V_56 ( V_40 ) : 0 ;
V_18:
return - V_57 ;
}
static int F_29 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 -> V_44 ;
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
struct V_46 * V_47 = V_42 -> V_48 [ V_40 -> V_26 ] . V_44 ;
int F_8 ;
if ( ! V_13 -> V_30 ) {
F_7 ( L_18 ) ;
goto V_18;
}
F_17 ( L_19 , V_11 ) ;
F_8 = ( V_47 -> V_58 ) ? V_47 -> V_58 ( V_40 ) : 0 ;
F_30 ( & V_13 -> V_49 ) ;
return F_8 ;
V_18:
return - V_57 ;
}
static int F_31 ( struct V_41 * V_42 , int V_38 )
{
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
struct V_46 * V_47 = V_42 -> V_48 [ V_42 -> V_59 ] . V_44 ;
int V_9 = 0 ;
T_1 V_60 ;
F_17 ( L_21 , V_11 , V_38 ) ;
if ( V_38 ) {
V_9 = F_23 ( V_13 ) ;
F_5 ( V_9 ) ;
V_9 = F_32 ( V_13 , 1 , 1 ,
V_47 -> V_61 ,
0 , 0 ) ;
F_5 ( V_9 ) ;
} else {
V_9 = F_33 ( V_13 ) ;
F_5 ( V_9 ) ;
}
F_6 ( V_13 , 0x12 , & V_60 ) ;
V_60 &= ~ 0x04 ;
F_10 ( V_13 , 0x12 , V_60 ) ;
return V_9 ;
}
static int F_34 ( struct V_41 * V_42 , int V_38 )
{
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
int V_9 = 0 ;
F_17 ( L_21 , V_11 , V_38 ) ;
if ( V_38 ) {
V_9 = F_23 ( V_13 ) ;
F_5 ( V_9 ) ;
}
return V_9 ;
}
static int F_35 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
int V_62 = V_42 -> V_63 ;
struct V_46 * V_47 = V_42 -> V_48 [ V_62 ] . V_44 ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_47 -> V_50 = ( V_64 ) ? 2 : 1 ;
V_13 -> V_50 = V_47 -> V_50 ;
if ( F_19 ( V_42 -> V_45 -> V_51 , 0 , V_13 -> V_50 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_54 = V_65 ;
V_47 -> V_54 = V_13 -> V_54 ;
V_47 -> V_52 = V_66 ;
V_47 -> V_61 = 1 ;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 , V_47 -> V_52 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_26 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_27 ( V_13 , V_13 -> V_54 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_42 -> V_48 [ V_62 ] . V_40 = F_36 ( V_67 ,
& V_68 ,
& V_42 -> V_45 -> V_69 ) ;
if ( V_42 -> V_48 [ V_62 ] . V_40 ) {
V_47 -> V_56 = V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_71 ;
V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_71 = F_16 ;
V_47 -> V_58 = V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_72 ;
V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_72 = F_29 ;
return 0 ;
}
V_9 = - V_73 ;
V_18:
return V_9 ;
}
static int F_37 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
int V_62 = V_42 -> V_63 ;
struct V_46 * V_47 = V_42 -> V_48 [ V_62 ] . V_44 ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_47 -> V_50 = ( V_64 ) ? 1 : 2 ;
V_13 -> V_50 = V_47 -> V_50 ;
if ( F_19 ( V_42 -> V_45 -> V_51 , 0 , V_13 -> V_50 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_54 = V_53 ;
V_47 -> V_54 = V_13 -> V_54 ;
V_47 -> V_52 = V_74 ;
V_47 -> V_61 = 1 ;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 , V_47 -> V_52 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
F_26 ( V_13 ) ;
V_42 -> V_48 [ V_62 ] . V_40 = F_36 ( V_75 , V_13 ,
& V_76 ) ;
if ( V_42 -> V_48 [ V_62 ] . V_40 ) {
V_47 -> V_56 = V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_71 ;
V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_71 = F_16 ;
V_47 -> V_58 = V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_72 ;
V_42 -> V_48 [ V_62 ] . V_40 -> V_70 . V_72 = F_29 ;
return 0 ;
}
V_9 = - V_73 ;
V_18:
return V_9 ;
}
static inline int F_38 ( struct V_12 * V_13 ,
int V_77 )
{
return F_39 ( V_13 , 1 , 1 ,
( V_77 == V_78 ) ?
0x3f : 0x00 , 0 ) ;
}
static int F_40 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 -> V_44 ;
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
int V_79 = V_80 ;
T_2 V_81 , V_82 , V_83 , V_84 ;
F_38 ( V_13 , V_79 == V_85 ?
V_86 : V_79 ) ;
if ( V_79 == V_85 ) {
#if 0
msleep(ANT_HUNT_SLEEP);
#endif
V_40 -> V_70 . V_87 . V_88 ( V_40 , & V_81 ) ;
F_38 ( V_13 , V_86 ) ;
F_28 ( V_89 ) ;
V_40 -> V_70 . V_87 . V_88 ( V_40 , & V_82 ) ;
F_38 ( V_13 , V_86 ) ;
F_28 ( V_89 ) ;
V_40 -> V_70 . V_87 . V_88 ( V_40 , & V_83 ) ;
F_38 ( V_13 , V_78 ) ;
F_28 ( V_89 ) ;
V_40 -> V_70 . V_87 . V_88 ( V_40 , & V_84 ) ;
if ( V_83 + V_90 >= V_84 ) {
F_38 ( V_13 , V_86 ) ;
F_41 ( V_86 , V_81 ,
V_82 , V_83 , V_84 ) ;
} else {
F_41 ( V_78 , V_81 ,
V_82 , V_83 , V_84 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_45 ;
struct V_12 * V_13 = V_2 -> V_44 ;
int V_62 = V_42 -> V_63 ;
F_2 ( L_19 , V_11 ) ;
if ( NULL != F_36 ( V_91 ,
V_42 -> V_48 [ V_62 ] . V_40 , V_13 ,
& V_92 ) )
return 0 ;
return - V_73 ;
}
static int F_43 ( struct V_39 * V_40 ,
unsigned int V_3 , void * V_93 ,
unsigned int V_94 )
{
int F_8 = 0 ;
switch ( V_94 ) {
case V_95 :
switch ( V_3 ) {
case V_96 :
F_8 = V_40 -> V_70 . V_87 . V_88 ( V_40 , V_93 ) ;
if ( 0 == F_8 )
F_8 = 1 ;
break;
}
break;
case V_97 :
break;
}
return F_8 ;
}
static T_3 F_44 ( struct V_98 * V_99 )
{
return V_100 ;
}
static int F_45 ( struct V_101 * V_102 ,
const struct V_103 * V_26 )
{
struct V_1 * V_2 = NULL ;
F_2 ( L_19 , V_11 ) ;
if ( ( ( V_64 ) &&
( 0 == F_46 ( V_102 ,
& V_104 ,
V_105 , & V_2 , V_106 ) ||
0 == F_46 ( V_102 ,
& V_107 ,
V_105 , & V_2 , V_106 ) ) ) ||
0 == F_46 ( V_102 ,
& V_108 ,
V_105 , & V_2 , V_106 ) ||
0 == F_46 ( V_102 ,
& V_109 ,
V_105 , & V_2 , V_106 ) || 0 ) {
struct V_12 * V_13 = V_2 -> V_44 ;
static T_1 V_110 [ 256 ] ;
struct V_111 V_112 ;
int V_9 ;
V_9 = F_47 ( V_13 ) ;
if ( F_5 ( V_9 ) )
F_8 ( L_22 ) ;
F_48 ( & V_13 -> V_49 ) ;
if ( V_13 -> V_34 > V_35 )
F_25 ( V_13 ,
V_55 ) ;
V_112 . V_99 = & V_2 -> V_69 ;
V_112 . V_14 = 0xa0 >> 1 ;
V_9 = F_49 ( & V_112 , V_110 , sizeof( V_110 ) ) ;
if ( F_5 ( V_9 ) )
return 0 ;
F_50 ( & V_112 , & V_13 -> V_113 ,
( 0x84 == V_110 [ 0xa0 ] ) ?
V_110 + 0xa0 : V_110 + 0x80 ) ;
#if 0
switch (state->tv.model) {
case 117001:
case 126001:
case 138001:
break;
default:
printk(KERN_WARNING "%s: warning: "
"unknown hauppauge model #%d\n",
__func__, state->tv.model);
}
#endif
return 0 ;
}
F_8 ( L_23
L_24 ) ;
return - V_19 ;
}
