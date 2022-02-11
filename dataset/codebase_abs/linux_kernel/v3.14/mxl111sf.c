int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
int V_8 = ( V_6 == NULL || V_7 == 0 ) ;
int V_9 ;
T_1 V_10 [ V_11 ] ;
if ( 1 + V_5 > sizeof( V_10 ) ) {
F_2 ( L_1 , V_12 , V_5 ) ;
return - V_13 ;
}
F_3 ( L_2 , V_12 , V_5 , V_7 ) ;
memset ( V_10 , 0 , 1 + V_5 ) ;
V_10 [ 0 ] = V_3 ;
memcpy ( & V_10 [ 1 ] , V_4 , V_5 ) ;
V_9 = ( V_8 ) ? F_4 ( V_2 , V_10 , 1 + V_5 ) :
F_5 ( V_2 , V_10 , 1 + V_5 , V_6 , V_7 ) ;
F_6 ( V_9 ) ;
return V_9 ;
}
int F_7 ( struct V_14 * V_15 , T_1 V_16 , T_1 * V_17 )
{
T_1 V_18 [ 2 ] ;
int V_9 ;
V_9 = F_1 ( V_15 -> V_2 , V_19 , & V_16 , 1 , V_18 , 2 ) ;
if ( F_6 ( V_9 ) ) {
F_8 ( L_3 , V_16 ) ;
goto V_20;
}
if ( V_18 [ 0 ] == V_16 )
* V_17 = V_18 [ 1 ] ;
else {
F_9 ( L_4 ,
V_16 , V_18 [ 0 ] , V_18 [ 1 ] ) ;
V_9 = - V_21 ;
}
F_3 ( L_5 , V_16 , V_18 [ 1 ] ) ;
V_20:
return V_9 ;
}
int F_10 ( struct V_14 * V_15 , T_1 V_16 , T_1 V_17 )
{
T_1 V_18 [] = { V_16 , V_17 } ;
int V_9 ;
F_3 ( L_6 , V_16 , V_17 ) ;
V_9 = F_1 ( V_15 -> V_2 , V_22 , V_18 , 2 , NULL , 0 ) ;
if ( F_6 ( V_9 ) )
F_9 ( L_7 , V_16 , V_17 ) ;
return V_9 ;
}
int F_11 ( struct V_14 * V_15 ,
T_1 V_16 , T_1 V_23 , T_1 V_17 )
{
int V_9 ;
T_1 V_24 ;
if ( V_23 != 0xff ) {
V_9 = F_7 ( V_15 , V_16 , & V_24 ) ;
#if 1
if ( F_6 ( V_9 ) )
F_9 ( L_8
L_9 , V_16 , V_23 , V_17 ) ;
V_9 = F_7 ( V_15 , V_16 , & V_24 ) ;
#endif
if ( F_6 ( V_9 ) )
goto V_20;
}
V_24 &= ~ V_23 ;
V_24 |= V_17 ;
V_9 = F_10 ( V_15 , V_16 , V_24 ) ;
F_6 ( V_9 ) ;
V_20:
return V_9 ;
}
int F_12 ( struct V_14 * V_15 ,
struct V_25 * V_26 )
{
int V_27 , V_9 = 0 ;
for ( V_27 = 0 ; V_26 [ V_27 ] . V_16 |
V_26 [ V_27 ] . V_23 |
V_26 [ V_27 ] . V_17 ; V_27 ++ ) {
V_9 = F_11 ( V_15 ,
V_26 [ V_27 ] . V_16 ,
V_26 [ V_27 ] . V_23 ,
V_26 [ V_27 ] . V_17 ) ;
if ( F_6 ( V_9 ) ) {
F_9 ( L_10 , V_27 ,
V_26 [ V_27 ] . V_16 ) ;
break;
}
}
return V_9 ;
}
static int F_13 ( struct V_14 * V_15 )
{
int V_9 ;
T_1 V_28 , V_29 ;
char * V_30 , * V_31 ;
if ( ( V_15 -> V_32 ) && ( V_15 -> V_33 ) )
return 0 ;
V_9 = F_7 ( V_15 , V_34 , & V_28 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_15 -> V_32 = V_28 ;
V_9 = F_7 ( V_15 , V_35 , & V_29 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_15 -> V_33 = V_29 ;
switch ( V_28 ) {
case 0x61 :
V_30 = L_11 ;
break;
case 0x63 :
V_30 = L_12 ;
break;
default:
V_30 = L_13 ;
break;
}
switch ( V_29 ) {
case 0x36 :
V_15 -> V_36 = V_37 ;
V_31 = L_14 ;
break;
case 0x08 :
V_15 -> V_36 = V_38 ;
V_31 = L_15 ;
break;
case 0x18 :
V_15 -> V_36 = V_39 ;
V_31 = L_16 ;
break;
default:
V_15 -> V_36 = 0 ;
V_31 = L_17 ;
break;
}
F_14 ( L_18 , V_30 , V_31 , V_29 ) ;
V_20:
return V_9 ;
}
static int F_15 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
struct V_14 * V_15 = F_17 ( V_41 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_41 -> V_28 ] ;
int V_44 ;
if ( ! V_15 -> V_32 ) {
F_8 ( L_19 ) ;
goto V_20;
}
F_3 ( L_20 , V_12 ) ;
F_18 ( & V_15 -> V_45 ) ;
V_15 -> V_46 = V_43 -> V_46 ;
if ( F_19 ( V_2 -> V_47 , 0 , V_15 -> V_46 ) < 0 )
F_9 ( L_21 ) ;
V_44 = F_20 ( V_15 ) ;
F_6 ( V_44 ) ;
V_44 = F_21 ( V_15 ) ;
F_6 ( V_44 ) ;
V_44 = F_22 ( V_15 , V_43 -> V_48 ) ;
F_6 ( V_44 ) ;
F_23 ( V_15 ) ;
F_6 ( V_44 ) ;
F_24 ( V_15 , 1 ) ;
F_6 ( V_44 ) ;
if ( ( V_49 != V_43 -> V_50 ) &&
( V_15 -> V_36 > V_37 ) ) {
F_25 ( V_15 ,
V_51 ) ;
F_6 ( V_44 ) ;
}
V_44 = F_26 ( V_15 ) ;
if ( ! F_6 ( V_44 ) ) {
V_15 -> V_50 = V_43 -> V_50 ;
V_44 = F_27 ( V_15 , V_15 -> V_50 ) ;
F_6 ( V_44 ) ;
#if 0
err = fe->ops.init(fe);
#endif
F_28 ( 100 ) ;
}
return ( V_43 -> V_52 ) ? V_43 -> V_52 ( V_41 ) : 0 ;
V_20:
return - V_53 ;
}
static int F_29 ( struct V_40 * V_41 )
{
struct V_14 * V_15 = F_17 ( V_41 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_41 -> V_28 ] ;
int V_44 ;
if ( ! V_15 -> V_32 ) {
F_8 ( L_19 ) ;
goto V_20;
}
F_3 ( L_20 , V_12 ) ;
V_44 = ( V_43 -> V_54 ) ? V_43 -> V_54 ( V_41 ) : 0 ;
F_30 ( & V_15 -> V_45 ) ;
return V_44 ;
V_20:
return - V_53 ;
}
static int F_31 ( struct V_40 * V_41 , int V_55 )
{
struct V_14 * V_15 = F_17 ( V_41 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_41 -> V_28 ] ;
int V_9 = 0 ;
F_3 ( L_22 , V_12 , V_55 ) ;
if ( V_55 ) {
V_9 = F_23 ( V_15 ) ;
F_6 ( V_9 ) ;
V_9 = F_32 ( V_15 , 1 , 1 ,
V_43 -> V_56 ,
0 , 0 ) ;
F_6 ( V_9 ) ;
#if 0
} else {
ret = mxl111sf_disable_656_port(state);
mxl_fail(ret);
#endif
}
return V_9 ;
}
static int F_33 ( struct V_40 * V_41 , int V_55 )
{
struct V_14 * V_15 = F_17 ( V_41 ) ;
int V_9 = 0 ;
F_3 ( L_22 , V_12 , V_55 ) ;
if ( V_55 ) {
V_9 = F_23 ( V_15 ) ;
F_6 ( V_9 ) ;
V_9 = F_34 ( V_15 , 200 ) ;
F_6 ( V_9 ) ;
V_9 = F_35 ( V_15 , 0 , 15 ) ;
F_6 ( V_9 ) ;
} else {
V_9 = F_36 ( V_15 ) ;
F_6 ( V_9 ) ;
}
if ( V_15 -> V_36 > V_37 )
V_9 = F_37 ( V_15 , V_55 ) ;
F_6 ( V_9 ) ;
return V_9 ;
}
static int F_38 ( struct V_40 * V_41 , int V_55 )
{
struct V_14 * V_15 = F_17 ( V_41 ) ;
int V_9 = 0 ;
F_3 ( L_22 , V_12 , V_55 ) ;
if ( V_55 ) {
V_9 = F_23 ( V_15 ) ;
F_6 ( V_9 ) ;
}
return V_9 ;
}
static int F_39 ( struct V_57 * V_58 , T_1 V_59 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_59 ] ;
int V_9 ;
F_3 ( L_20 , V_12 ) ;
V_15 -> V_2 = V_2 ;
V_43 -> V_46 = ( V_60 ) ? 2 : 1 ;
V_15 -> V_46 = V_43 -> V_46 ;
if ( F_19 ( V_2 -> V_47 , 0 , V_15 -> V_46 ) < 0 )
F_9 ( L_21 ) ;
V_15 -> V_50 = V_61 ;
V_43 -> V_50 = V_15 -> V_50 ;
V_43 -> V_48 = V_62 ;
V_43 -> V_56 = 1 ;
V_9 = F_20 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_21 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_22 ( V_15 , V_43 -> V_48 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_23 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_24 ( V_15 , 1 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_26 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_27 ( V_15 , V_15 -> V_50 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_58 -> V_41 [ V_59 ] = F_42 ( V_63 ,
& V_64 ,
& V_2 -> V_65 ) ;
if ( V_58 -> V_41 [ V_59 ] ) {
V_15 -> V_66 ++ ;
V_43 -> V_52 = V_58 -> V_41 [ V_59 ] -> V_67 . V_68 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_68 = F_15 ;
V_43 -> V_54 = V_58 -> V_41 [ V_59 ] -> V_67 . V_69 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_69 = F_29 ;
return 0 ;
}
V_9 = - V_70 ;
V_20:
return V_9 ;
}
static int F_43 ( struct V_57 * V_58 , T_1 V_59 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_59 ] ;
int V_9 ;
F_3 ( L_20 , V_12 ) ;
V_15 -> V_2 = V_2 ;
V_43 -> V_46 = ( V_60 ) ? 2 : 1 ;
V_15 -> V_46 = V_43 -> V_46 ;
if ( F_19 ( V_2 -> V_47 , 0 , V_15 -> V_46 ) < 0 )
F_9 ( L_21 ) ;
V_15 -> V_50 = V_71 ;
V_43 -> V_50 = V_15 -> V_50 ;
V_43 -> V_48 = V_62 ;
V_43 -> V_56 = 1 ;
V_9 = F_20 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_21 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_22 ( V_15 , V_43 -> V_48 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_23 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_24 ( V_15 , 1 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_26 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_27 ( V_15 , V_15 -> V_50 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_44 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_58 -> V_41 [ V_59 ] = F_42 ( V_72 ,
& V_73 ,
& V_2 -> V_65 ) ;
if ( V_58 -> V_41 [ V_59 ] ) {
V_15 -> V_66 ++ ;
V_43 -> V_52 = V_58 -> V_41 [ V_59 ] -> V_67 . V_68 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_68 = F_15 ;
V_43 -> V_54 = V_58 -> V_41 [ V_59 ] -> V_67 . V_69 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_69 = F_29 ;
return 0 ;
}
V_9 = - V_70 ;
V_20:
return V_9 ;
}
static int F_45 ( struct V_57 * V_58 , T_1 V_59 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_59 ] ;
int V_9 ;
F_3 ( L_20 , V_12 ) ;
V_15 -> V_2 = V_2 ;
V_43 -> V_46 = ( V_60 ) ? 2 : 1 ;
V_15 -> V_46 = V_43 -> V_46 ;
if ( F_19 ( V_2 -> V_47 , 0 , V_15 -> V_46 ) < 0 )
F_9 ( L_21 ) ;
V_15 -> V_50 = V_71 ;
V_43 -> V_50 = V_15 -> V_50 ;
V_43 -> V_48 = V_62 ;
V_43 -> V_56 = 1 ;
V_9 = F_20 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_21 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_22 ( V_15 , V_43 -> V_48 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_23 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_24 ( V_15 , 1 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_26 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_27 ( V_15 , V_15 -> V_50 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_44 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_58 -> V_41 [ V_59 ] = F_42 ( V_72 ,
( V_39 == V_15 -> V_36 ) ?
& V_74 :
& V_75 ,
& V_2 -> V_65 ) ;
if ( V_58 -> V_41 [ V_59 ] ) {
V_15 -> V_66 ++ ;
V_43 -> V_52 = V_58 -> V_41 [ V_59 ] -> V_67 . V_68 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_68 = F_15 ;
V_43 -> V_54 = V_58 -> V_41 [ V_59 ] -> V_67 . V_69 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_69 = F_29 ;
return 0 ;
}
V_9 = - V_70 ;
V_20:
return V_9 ;
}
static int F_46 ( struct V_57 * V_58 , T_1 V_59 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_59 ] ;
int V_9 ;
F_3 ( L_20 , V_12 ) ;
V_15 -> V_2 = V_2 ;
V_43 -> V_46 = ( V_60 ) ? 2 : 1 ;
V_15 -> V_46 = V_43 -> V_46 ;
if ( F_19 ( V_2 -> V_47 , 0 , V_15 -> V_46 ) < 0 )
F_9 ( L_21 ) ;
V_15 -> V_50 = V_71 ;
V_43 -> V_50 = V_15 -> V_50 ;
V_43 -> V_48 = V_62 ;
V_43 -> V_56 = 0 ;
V_9 = F_20 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_21 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_22 ( V_15 , V_43 -> V_48 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_23 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_24 ( V_15 , 1 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_26 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_27 ( V_15 , V_15 -> V_50 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_44 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_58 -> V_41 [ V_59 ] = F_42 ( V_72 ,
( V_39 == V_15 -> V_36 ) ?
& V_76 :
& V_77 ,
& V_2 -> V_65 ) ;
if ( V_58 -> V_41 [ V_59 ] ) {
V_15 -> V_66 ++ ;
V_43 -> V_52 = V_58 -> V_41 [ V_59 ] -> V_67 . V_68 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_68 = F_15 ;
V_43 -> V_54 = V_58 -> V_41 [ V_59 ] -> V_67 . V_69 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_69 = F_29 ;
return 0 ;
}
V_9 = - V_70 ;
V_20:
return V_9 ;
}
static int F_47 ( struct V_57 * V_58 , T_1 V_59 )
{
struct V_1 * V_2 = F_40 ( V_58 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_42 * V_43 = & V_15 -> V_43 [ V_59 ] ;
int V_9 ;
F_3 ( L_20 , V_12 ) ;
V_15 -> V_2 = V_2 ;
V_43 -> V_46 = ( V_60 ) ? 1 : 2 ;
V_15 -> V_46 = V_43 -> V_46 ;
if ( F_19 ( V_2 -> V_47 , 0 , V_15 -> V_46 ) < 0 )
F_9 ( L_21 ) ;
V_15 -> V_50 = V_49 ;
V_43 -> V_50 = V_15 -> V_50 ;
V_43 -> V_48 = V_78 ;
V_43 -> V_56 = 1 ;
V_9 = F_20 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_21 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_22 ( V_15 , V_43 -> V_48 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_23 ( V_15 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
V_9 = F_24 ( V_15 , 1 ) ;
if ( F_6 ( V_9 ) )
goto V_20;
F_26 ( V_15 ) ;
V_58 -> V_41 [ V_59 ] = F_42 ( V_79 , V_15 ,
& V_80 ) ;
if ( V_58 -> V_41 [ V_59 ] ) {
V_15 -> V_66 ++ ;
V_43 -> V_52 = V_58 -> V_41 [ V_59 ] -> V_67 . V_68 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_68 = F_15 ;
V_43 -> V_54 = V_58 -> V_41 [ V_59 ] -> V_67 . V_69 ;
V_58 -> V_41 [ V_59 ] -> V_67 . V_69 = F_29 ;
return 0 ;
}
V_9 = - V_70 ;
V_20:
return V_9 ;
}
static inline int F_48 ( struct V_14 * V_15 ,
int V_81 )
{
return F_49 ( V_15 , 1 , 1 ,
( V_81 == V_82 ) ?
0x3f : 0x00 , 0 ) ;
}
static int F_50 ( struct V_40 * V_41 )
{
struct V_14 * V_15 = F_17 ( V_41 ) ;
int V_83 = V_84 ;
T_2 V_85 , V_86 , V_87 , V_88 ;
F_48 ( V_15 , V_83 == V_89 ?
V_90 : V_83 ) ;
if ( V_83 == V_89 ) {
#if 0
msleep(ANT_HUNT_SLEEP);
#endif
V_41 -> V_67 . V_91 . V_92 ( V_41 , & V_85 ) ;
F_48 ( V_15 , V_90 ) ;
F_28 ( V_93 ) ;
V_41 -> V_67 . V_91 . V_92 ( V_41 , & V_86 ) ;
F_48 ( V_15 , V_90 ) ;
F_28 ( V_93 ) ;
V_41 -> V_67 . V_91 . V_92 ( V_41 , & V_87 ) ;
F_48 ( V_15 , V_82 ) ;
F_28 ( V_93 ) ;
V_41 -> V_67 . V_91 . V_92 ( V_41 , & V_88 ) ;
if ( V_87 + V_94 >= V_88 ) {
F_48 ( V_15 , V_90 ) ;
F_51 ( V_90 , V_85 ,
V_86 , V_87 , V_88 ) ;
} else {
F_51 ( V_82 , V_85 ,
V_86 , V_87 , V_88 ) ;
}
}
return 0 ;
}
static int F_52 ( struct V_57 * V_58 )
{
struct V_14 * V_15 = F_53 ( V_58 ) ;
int V_27 ;
F_3 ( L_20 , V_12 ) ;
for ( V_27 = 0 ; V_27 < V_15 -> V_66 ; V_27 ++ ) {
if ( F_42 ( V_95 , V_58 -> V_41 [ V_27 ] , V_15 ,
& V_96 ) == NULL )
return - V_70 ;
V_58 -> V_41 [ V_27 ] -> V_67 . V_97 = V_58 -> V_41 [ V_27 ] -> V_67 . V_91 . V_92 ;
}
return 0 ;
}
static T_3 F_54 ( struct V_98 * V_99 )
{
return V_100 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
int V_9 ;
static T_1 V_101 [ 256 ] ;
struct V_102 V_103 ;
V_9 = F_44 ( V_15 ) ;
if ( F_6 ( V_9 ) )
F_9 ( L_23 ) ;
F_56 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_36 > V_37 )
F_25 ( V_15 , V_51 ) ;
V_103 . V_99 = & V_2 -> V_65 ;
V_103 . V_16 = 0xa0 >> 1 ;
V_9 = F_57 ( & V_103 , V_101 , sizeof( V_101 ) ) ;
if ( F_6 ( V_9 ) )
return 0 ;
F_58 ( & V_103 , & V_15 -> V_104 , ( 0x84 == V_101 [ 0xa0 ] ) ?
V_101 + 0xa0 : V_101 + 0x80 ) ;
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
static int F_59 ( struct V_57 * V_58 )
{
return F_47 ( V_58 , 0 ) ;
}
static int F_60 ( struct V_57 * V_58 )
{
return F_39 ( V_58 , 0 ) ;
}
static int F_61 ( struct V_57 * V_58 )
{
return F_43 ( V_58 , 0 ) ;
}
static int F_62 ( struct V_57 * V_58 )
{
int V_9 ;
F_3 ( L_24 , V_12 ) ;
V_9 = F_39 ( V_58 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_47 ( V_58 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_43 ( V_58 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 ;
}
static int F_63 ( struct V_57 * V_58 )
{
int V_9 ;
F_3 ( L_24 , V_12 ) ;
V_9 = F_39 ( V_58 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_47 ( V_58 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_46 ( V_58 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 ;
}
static int F_64 ( struct V_57 * V_58 )
{
int V_9 ;
F_3 ( L_24 , V_12 ) ;
V_9 = F_47 ( V_58 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_105 )
V_9 = F_45 ( V_58 , 1 ) ;
else
V_9 = F_46 ( V_58 , 1 ) ;
return V_9 ;
}
static void F_65 ( struct V_106 * V_107 , T_1 V_108 )
{
F_3 ( L_25 , V_12 , V_108 ) ;
V_107 -> type = V_109 ;
V_107 -> V_110 = 5 ;
V_107 -> V_108 = V_108 ;
V_107 -> V_111 . V_112 . V_113 = 8192 ;
}
static void F_66 ( struct V_106 * V_107 ,
T_1 V_108 , int V_114 , int V_115 )
{
F_3 ( L_26 , V_12 , V_108 ,
V_114 * V_115 ) ;
V_107 -> type = V_116 ;
V_107 -> V_110 = 5 ;
V_107 -> V_108 = V_108 ;
V_107 -> V_111 . V_117 . V_114 = V_114 ;
V_107 -> V_111 . V_117 . V_115 = V_115 ;
V_107 -> V_111 . V_117 . V_118 = 1 ;
}
static int F_67 ( struct V_40 * V_41 ,
T_1 * V_119 , struct V_106 * V_107 )
{
F_3 ( L_27 , V_12 , V_41 -> V_28 ) ;
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 4 , 96 , 564 ) ;
else
F_65 ( V_107 , 4 ) ;
return 0 ;
}
static int F_68 ( struct V_40 * V_41 ,
T_1 * V_119 , struct V_106 * V_107 )
{
F_3 ( L_27 , V_12 , V_41 -> V_28 ) ;
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 6 , 24 , 3072 ) ;
else
F_65 ( V_107 , 6 ) ;
return 0 ;
}
static int F_69 ( struct V_40 * V_41 ,
T_1 * V_119 , struct V_106 * V_107 )
{
F_3 ( L_27 , V_12 , V_41 -> V_28 ) ;
* V_119 = V_121 ;
if ( V_60 )
F_66 ( V_107 , 5 , 96 , 200 ) ;
else
F_65 ( V_107 , 5 ) ;
return 0 ;
}
static int F_70 ( struct V_40 * V_41 ,
T_1 * V_119 , struct V_106 * V_107 )
{
F_3 ( L_27 , V_12 , V_41 -> V_28 ) ;
if ( V_41 -> V_28 == 0 ) {
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 6 , 24 , 3072 ) ;
else
F_65 ( V_107 , 6 ) ;
} else if ( V_41 -> V_28 == 1 ) {
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 4 , 96 , 564 ) ;
else
F_65 ( V_107 , 4 ) ;
} else if ( V_41 -> V_28 == 2 ) {
* V_119 = V_121 ;
if ( V_60 )
F_66 ( V_107 , 5 , 96 , 200 ) ;
else
F_65 ( V_107 , 5 ) ;
}
return 0 ;
}
static int F_71 ( struct V_40 * V_41 , int V_55 )
{
F_3 ( L_28 , V_12 , V_41 -> V_28 , V_55 ) ;
if ( V_41 -> V_28 == 0 )
return F_31 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 1 )
return F_38 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 2 )
return F_33 ( V_41 , V_55 ) ;
return 0 ;
}
static int F_72 ( struct V_40 * V_41 ,
T_1 * V_119 , struct V_106 * V_107 )
{
F_3 ( L_27 , V_12 , V_41 -> V_28 ) ;
if ( V_41 -> V_28 == 0 ) {
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 6 , 24 , 3072 ) ;
else
F_65 ( V_107 , 6 ) ;
} else if ( V_41 -> V_28 == 1 ) {
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 4 , 96 , 564 ) ;
else
F_65 ( V_107 , 4 ) ;
} else if ( V_41 -> V_28 == 2 && V_105 ) {
* V_119 = V_121 ;
if ( V_60 )
F_66 ( V_107 , 5 , 96 , 200 ) ;
else
F_65 ( V_107 , 5 ) ;
} else if ( V_41 -> V_28 == 2 && ! V_105 ) {
* V_119 = V_121 ;
if ( V_60 )
F_66 ( V_107 , 6 , 24 , 3072 ) ;
else
F_65 ( V_107 , 6 ) ;
}
return 0 ;
}
static int F_73 ( struct V_40 * V_41 , int V_55 )
{
F_3 ( L_28 , V_12 , V_41 -> V_28 , V_55 ) ;
if ( V_41 -> V_28 == 0 )
return F_31 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 1 )
return F_38 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 2 && V_105 )
return F_33 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 2 && ! V_105 )
return F_31 ( V_41 , V_55 ) ;
return 0 ;
}
static int F_74 ( struct V_40 * V_41 ,
T_1 * V_119 , struct V_106 * V_107 )
{
F_3 ( L_27 , V_12 , V_41 -> V_28 ) ;
if ( V_41 -> V_28 == 0 ) {
* V_119 = V_120 ;
if ( V_60 )
F_66 ( V_107 , 4 , 96 , 564 ) ;
else
F_65 ( V_107 , 4 ) ;
} else if ( V_41 -> V_28 == 1 && V_105 ) {
* V_119 = V_121 ;
if ( V_60 )
F_66 ( V_107 , 5 , 96 , 200 ) ;
else
F_65 ( V_107 , 5 ) ;
} else if ( V_41 -> V_28 == 1 && ! V_105 ) {
* V_119 = V_121 ;
if ( V_60 )
F_66 ( V_107 , 6 , 24 , 3072 ) ;
else
F_65 ( V_107 , 6 ) ;
}
return 0 ;
}
static int F_75 ( struct V_40 * V_41 , int V_55 )
{
F_3 ( L_28 , V_12 , V_41 -> V_28 , V_55 ) ;
if ( V_41 -> V_28 == 0 )
return F_38 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 1 && V_105 )
return F_33 ( V_41 , V_55 ) ;
else if ( V_41 -> V_28 == 1 && ! V_105 )
return F_31 ( V_41 , V_55 ) ;
return 0 ;
}
