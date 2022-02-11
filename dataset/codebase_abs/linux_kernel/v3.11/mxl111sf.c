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
F_4 ( V_2 , V_10 , 1 + V_5 , V_6 , V_7 ) ;
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
F_2 ( L_4 , V_14 , * V_15 ) ;
V_18:
return V_9 ;
}
int F_9 ( struct V_12 * V_13 , T_1 V_14 , T_1 V_15 )
{
T_1 V_16 [] = { V_14 , V_15 } ;
int V_9 ;
F_2 ( L_5 , V_14 , V_15 ) ;
V_9 = F_1 ( V_13 -> V_2 , V_20 , V_16 , 2 , NULL , 0 ) ;
if ( F_5 ( V_9 ) )
F_8 ( L_6 , V_14 , V_15 ) ;
return V_9 ;
}
int F_10 ( struct V_12 * V_13 ,
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
V_9 = F_9 ( V_13 , V_14 , V_22 ) ;
F_5 ( V_9 ) ;
V_18:
return V_9 ;
}
int F_11 ( struct V_12 * V_13 ,
struct V_23 * V_24 )
{
int V_25 , V_9 = 0 ;
for ( V_25 = 0 ; V_24 [ V_25 ] . V_14 |
V_24 [ V_25 ] . V_21 |
V_24 [ V_25 ] . V_15 ; V_25 ++ ) {
V_9 = F_10 ( V_13 ,
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
static int F_12 ( struct V_12 * V_13 )
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
F_13 ( L_17 , V_28 , V_29 , V_27 ) ;
V_18:
return V_9 ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_15 ( V_39 ) ;
struct V_12 * V_13 = F_16 ( V_39 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_39 -> V_26 ] ;
int V_42 ;
if ( ! V_13 -> V_30 ) {
F_7 ( L_18 ) ;
goto V_18;
}
F_2 ( L_19 , V_11 ) ;
F_17 ( & V_13 -> V_43 ) ;
V_13 -> V_44 = V_41 -> V_44 ;
if ( F_18 ( V_2 -> V_45 , 0 , V_13 -> V_44 ) < 0 )
F_8 ( L_20 ) ;
V_42 = F_19 ( V_13 ) ;
F_5 ( V_42 ) ;
V_42 = F_20 ( V_13 ) ;
F_5 ( V_42 ) ;
V_42 = F_21 ( V_13 , V_41 -> V_46 ) ;
F_5 ( V_42 ) ;
F_22 ( V_13 ) ;
F_5 ( V_42 ) ;
F_23 ( V_13 , 1 ) ;
F_5 ( V_42 ) ;
if ( ( V_47 != V_41 -> V_48 ) &&
( V_13 -> V_34 > V_35 ) ) {
F_24 ( V_13 ,
V_49 ) ;
F_5 ( V_42 ) ;
}
V_42 = F_25 ( V_13 ) ;
if ( ! F_5 ( V_42 ) ) {
V_13 -> V_48 = V_41 -> V_48 ;
V_42 = F_26 ( V_13 , V_13 -> V_48 ) ;
F_5 ( V_42 ) ;
#if 0
err = fe->ops.init(fe);
#endif
F_27 ( 100 ) ;
}
return ( V_41 -> V_50 ) ? V_41 -> V_50 ( V_39 ) : 0 ;
V_18:
return - V_51 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_12 * V_13 = F_16 ( V_39 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_39 -> V_26 ] ;
int V_42 ;
if ( ! V_13 -> V_30 ) {
F_7 ( L_18 ) ;
goto V_18;
}
F_2 ( L_19 , V_11 ) ;
V_42 = ( V_41 -> V_52 ) ? V_41 -> V_52 ( V_39 ) : 0 ;
F_29 ( & V_13 -> V_43 ) ;
return V_42 ;
V_18:
return - V_51 ;
}
static int F_30 ( struct V_38 * V_39 , int V_53 )
{
struct V_12 * V_13 = F_16 ( V_39 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_39 -> V_26 ] ;
int V_9 = 0 ;
F_2 ( L_21 , V_11 , V_53 ) ;
if ( V_53 ) {
V_9 = F_22 ( V_13 ) ;
F_5 ( V_9 ) ;
V_9 = F_31 ( V_13 , 1 , 1 ,
V_41 -> V_54 ,
0 , 0 ) ;
F_5 ( V_9 ) ;
#if 0
} else {
ret = mxl111sf_disable_656_port(state);
mxl_fail(ret);
#endif
}
return V_9 ;
}
static int F_32 ( struct V_38 * V_39 , int V_53 )
{
struct V_12 * V_13 = F_16 ( V_39 ) ;
int V_9 = 0 ;
F_2 ( L_21 , V_11 , V_53 ) ;
if ( V_53 ) {
V_9 = F_22 ( V_13 ) ;
F_5 ( V_9 ) ;
V_9 = F_33 ( V_13 , 200 ) ;
F_5 ( V_9 ) ;
V_9 = F_34 ( V_13 , 0 , 15 ) ;
F_5 ( V_9 ) ;
} else {
V_9 = F_35 ( V_13 ) ;
F_5 ( V_9 ) ;
}
if ( V_13 -> V_34 > V_35 )
V_9 = F_36 ( V_13 , V_53 ) ;
F_5 ( V_9 ) ;
return V_9 ;
}
static int F_37 ( struct V_38 * V_39 , int V_53 )
{
struct V_12 * V_13 = F_16 ( V_39 ) ;
int V_9 = 0 ;
F_2 ( L_21 , V_11 , V_53 ) ;
if ( V_53 ) {
V_9 = F_22 ( V_13 ) ;
F_5 ( V_9 ) ;
}
return V_9 ;
}
static int F_38 ( struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_12 * V_13 = F_40 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_57 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_44 = ( V_58 ) ? 2 : 1 ;
V_13 -> V_44 = V_41 -> V_44 ;
if ( F_18 ( V_2 -> V_45 , 0 , V_13 -> V_44 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_48 = V_59 ;
V_41 -> V_48 = V_13 -> V_48 ;
V_41 -> V_46 = V_60 ;
V_41 -> V_54 = 1 ;
V_9 = F_19 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 , V_41 -> V_46 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_26 ( V_13 , V_13 -> V_48 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_56 -> V_39 [ V_57 ] = F_41 ( V_61 ,
& V_62 ,
& V_2 -> V_63 ) ;
if ( V_56 -> V_39 [ V_57 ] ) {
V_13 -> V_64 ++ ;
V_41 -> V_50 = V_56 -> V_39 [ V_57 ] -> V_65 . V_66 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_66 = F_14 ;
V_41 -> V_52 = V_56 -> V_39 [ V_57 ] -> V_65 . V_67 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_67 = F_28 ;
return 0 ;
}
V_9 = - V_68 ;
V_18:
return V_9 ;
}
static int F_42 ( struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_12 * V_13 = F_40 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_57 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_44 = ( V_58 ) ? 2 : 1 ;
V_13 -> V_44 = V_41 -> V_44 ;
if ( F_18 ( V_2 -> V_45 , 0 , V_13 -> V_44 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_48 = V_69 ;
V_41 -> V_48 = V_13 -> V_48 ;
V_41 -> V_46 = V_60 ;
V_41 -> V_54 = 1 ;
V_9 = F_19 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 , V_41 -> V_46 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_26 ( V_13 , V_13 -> V_48 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_43 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_56 -> V_39 [ V_57 ] = F_41 ( V_70 ,
& V_71 ,
& V_2 -> V_63 ) ;
if ( V_56 -> V_39 [ V_57 ] ) {
V_13 -> V_64 ++ ;
V_41 -> V_50 = V_56 -> V_39 [ V_57 ] -> V_65 . V_66 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_66 = F_14 ;
V_41 -> V_52 = V_56 -> V_39 [ V_57 ] -> V_65 . V_67 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_67 = F_28 ;
return 0 ;
}
V_9 = - V_68 ;
V_18:
return V_9 ;
}
static int F_44 ( struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_12 * V_13 = F_40 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_57 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_44 = ( V_58 ) ? 2 : 1 ;
V_13 -> V_44 = V_41 -> V_44 ;
if ( F_18 ( V_2 -> V_45 , 0 , V_13 -> V_44 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_48 = V_69 ;
V_41 -> V_48 = V_13 -> V_48 ;
V_41 -> V_46 = V_60 ;
V_41 -> V_54 = 1 ;
V_9 = F_19 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 , V_41 -> V_46 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_26 ( V_13 , V_13 -> V_48 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_43 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_56 -> V_39 [ V_57 ] = F_41 ( V_70 ,
( V_37 == V_13 -> V_34 ) ?
& V_72 :
& V_73 ,
& V_2 -> V_63 ) ;
if ( V_56 -> V_39 [ V_57 ] ) {
V_13 -> V_64 ++ ;
V_41 -> V_50 = V_56 -> V_39 [ V_57 ] -> V_65 . V_66 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_66 = F_14 ;
V_41 -> V_52 = V_56 -> V_39 [ V_57 ] -> V_65 . V_67 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_67 = F_28 ;
return 0 ;
}
V_9 = - V_68 ;
V_18:
return V_9 ;
}
static int F_45 ( struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_12 * V_13 = F_40 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_57 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_44 = ( V_58 ) ? 2 : 1 ;
V_13 -> V_44 = V_41 -> V_44 ;
if ( F_18 ( V_2 -> V_45 , 0 , V_13 -> V_44 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_48 = V_69 ;
V_41 -> V_48 = V_13 -> V_48 ;
V_41 -> V_46 = V_60 ;
V_41 -> V_54 = 0 ;
V_9 = F_19 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 , V_41 -> V_46 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_26 ( V_13 , V_13 -> V_48 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_43 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_56 -> V_39 [ V_57 ] = F_41 ( V_70 ,
( V_37 == V_13 -> V_34 ) ?
& V_74 :
& V_75 ,
& V_2 -> V_63 ) ;
if ( V_56 -> V_39 [ V_57 ] ) {
V_13 -> V_64 ++ ;
V_41 -> V_50 = V_56 -> V_39 [ V_57 ] -> V_65 . V_66 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_66 = F_14 ;
V_41 -> V_52 = V_56 -> V_39 [ V_57 ] -> V_65 . V_67 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_67 = F_28 ;
return 0 ;
}
V_9 = - V_68 ;
V_18:
return V_9 ;
}
static int F_46 ( struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_12 * V_13 = F_40 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_57 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_44 = ( V_58 ) ? 1 : 2 ;
V_13 -> V_44 = V_41 -> V_44 ;
if ( F_18 ( V_2 -> V_45 , 0 , V_13 -> V_44 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_48 = V_47 ;
V_41 -> V_48 = V_13 -> V_48 ;
V_41 -> V_46 = V_76 ;
V_41 -> V_54 = 1 ;
V_9 = F_19 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_20 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_21 ( V_13 , V_41 -> V_46 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
F_25 ( V_13 ) ;
V_56 -> V_39 [ V_57 ] = F_41 ( V_77 , V_13 ,
& V_78 ) ;
if ( V_56 -> V_39 [ V_57 ] ) {
V_13 -> V_64 ++ ;
V_41 -> V_50 = V_56 -> V_39 [ V_57 ] -> V_65 . V_66 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_66 = F_14 ;
V_41 -> V_52 = V_56 -> V_39 [ V_57 ] -> V_65 . V_67 ;
V_56 -> V_39 [ V_57 ] -> V_65 . V_67 = F_28 ;
return 0 ;
}
V_9 = - V_68 ;
V_18:
return V_9 ;
}
static inline int F_47 ( struct V_12 * V_13 ,
int V_79 )
{
return F_48 ( V_13 , 1 , 1 ,
( V_79 == V_80 ) ?
0x3f : 0x00 , 0 ) ;
}
static int F_49 ( struct V_38 * V_39 )
{
struct V_12 * V_13 = F_16 ( V_39 ) ;
int V_81 = V_82 ;
T_2 V_83 , V_84 , V_85 , V_86 ;
F_47 ( V_13 , V_81 == V_87 ?
V_88 : V_81 ) ;
if ( V_81 == V_87 ) {
#if 0
msleep(ANT_HUNT_SLEEP);
#endif
V_39 -> V_65 . V_89 . V_90 ( V_39 , & V_83 ) ;
F_47 ( V_13 , V_88 ) ;
F_27 ( V_91 ) ;
V_39 -> V_65 . V_89 . V_90 ( V_39 , & V_84 ) ;
F_47 ( V_13 , V_88 ) ;
F_27 ( V_91 ) ;
V_39 -> V_65 . V_89 . V_90 ( V_39 , & V_85 ) ;
F_47 ( V_13 , V_80 ) ;
F_27 ( V_91 ) ;
V_39 -> V_65 . V_89 . V_90 ( V_39 , & V_86 ) ;
if ( V_85 + V_92 >= V_86 ) {
F_47 ( V_13 , V_88 ) ;
F_50 ( V_88 , V_83 ,
V_84 , V_85 , V_86 ) ;
} else {
F_50 ( V_80 , V_83 ,
V_84 , V_85 , V_86 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_55 * V_56 )
{
struct V_12 * V_13 = F_52 ( V_56 ) ;
int V_25 ;
F_2 ( L_19 , V_11 ) ;
for ( V_25 = 0 ; V_25 < V_13 -> V_64 ; V_25 ++ ) {
if ( F_41 ( V_93 , V_56 -> V_39 [ V_25 ] , V_13 ,
& V_94 ) == NULL )
return - V_68 ;
V_56 -> V_39 [ V_25 ] -> V_65 . V_95 = V_56 -> V_39 [ V_25 ] -> V_65 . V_89 . V_90 ;
}
return 0 ;
}
static T_3 F_53 ( struct V_96 * V_97 )
{
return V_98 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_40 ( V_2 ) ;
int V_9 ;
static T_1 V_99 [ 256 ] ;
struct V_100 V_101 ;
V_9 = F_43 ( V_13 ) ;
if ( F_5 ( V_9 ) )
F_8 ( L_22 ) ;
F_55 ( & V_13 -> V_43 ) ;
if ( V_13 -> V_34 > V_35 )
F_24 ( V_13 , V_49 ) ;
V_101 . V_97 = & V_2 -> V_63 ;
V_101 . V_14 = 0xa0 >> 1 ;
V_9 = F_56 ( & V_101 , V_99 , sizeof( V_99 ) ) ;
if ( F_5 ( V_9 ) )
return 0 ;
F_57 ( & V_101 , & V_13 -> V_102 , ( 0x84 == V_99 [ 0xa0 ] ) ?
V_99 + 0xa0 : V_99 + 0x80 ) ;
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
static int F_58 ( struct V_55 * V_56 )
{
return F_46 ( V_56 , 0 ) ;
}
static int F_59 ( struct V_55 * V_56 )
{
return F_38 ( V_56 , 0 ) ;
}
static int F_60 ( struct V_55 * V_56 )
{
return F_42 ( V_56 , 0 ) ;
}
static int F_61 ( struct V_55 * V_56 )
{
int V_9 ;
F_2 ( L_23 , V_11 ) ;
V_9 = F_38 ( V_56 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_46 ( V_56 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_42 ( V_56 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 ;
}
static int F_62 ( struct V_55 * V_56 )
{
int V_9 ;
F_2 ( L_23 , V_11 ) ;
V_9 = F_38 ( V_56 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_46 ( V_56 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_45 ( V_56 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 ;
}
static int F_63 ( struct V_55 * V_56 )
{
int V_9 ;
F_2 ( L_23 , V_11 ) ;
V_9 = F_46 ( V_56 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_103 )
V_9 = F_44 ( V_56 , 1 ) ;
else
V_9 = F_45 ( V_56 , 1 ) ;
return V_9 ;
}
static void F_64 ( struct V_104 * V_105 , T_1 V_106 )
{
F_2 ( L_24 , V_11 , V_106 ) ;
V_105 -> type = V_107 ;
V_105 -> V_108 = 5 ;
V_105 -> V_106 = V_106 ;
V_105 -> V_109 . V_110 . V_111 = 8192 ;
}
static void F_65 ( struct V_104 * V_105 ,
T_1 V_106 , int V_112 , int V_113 )
{
F_2 ( L_25 , V_11 , V_106 ,
V_112 * V_113 ) ;
V_105 -> type = V_114 ;
V_105 -> V_108 = 5 ;
V_105 -> V_106 = V_106 ;
V_105 -> V_109 . V_115 . V_112 = V_112 ;
V_105 -> V_109 . V_115 . V_113 = V_113 ;
V_105 -> V_109 . V_115 . V_116 = 1 ;
}
static int F_66 ( struct V_38 * V_39 ,
T_1 * V_117 , struct V_104 * V_105 )
{
F_2 ( L_26 , V_11 , V_39 -> V_26 ) ;
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 4 , 96 , 564 ) ;
else
F_64 ( V_105 , 4 ) ;
return 0 ;
}
static int F_67 ( struct V_38 * V_39 ,
T_1 * V_117 , struct V_104 * V_105 )
{
F_2 ( L_26 , V_11 , V_39 -> V_26 ) ;
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 6 , 24 , 3072 ) ;
else
F_64 ( V_105 , 6 ) ;
return 0 ;
}
static int F_68 ( struct V_38 * V_39 ,
T_1 * V_117 , struct V_104 * V_105 )
{
F_2 ( L_26 , V_11 , V_39 -> V_26 ) ;
* V_117 = V_119 ;
if ( V_58 )
F_65 ( V_105 , 5 , 96 , 200 ) ;
else
F_64 ( V_105 , 5 ) ;
return 0 ;
}
static int F_69 ( struct V_38 * V_39 ,
T_1 * V_117 , struct V_104 * V_105 )
{
F_2 ( L_26 , V_11 , V_39 -> V_26 ) ;
if ( V_39 -> V_26 == 0 ) {
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 6 , 24 , 3072 ) ;
else
F_64 ( V_105 , 6 ) ;
} else if ( V_39 -> V_26 == 1 ) {
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 4 , 96 , 564 ) ;
else
F_64 ( V_105 , 4 ) ;
} else if ( V_39 -> V_26 == 2 ) {
* V_117 = V_119 ;
if ( V_58 )
F_65 ( V_105 , 5 , 96 , 200 ) ;
else
F_64 ( V_105 , 5 ) ;
}
return 0 ;
}
static int F_70 ( struct V_38 * V_39 , int V_53 )
{
F_2 ( L_27 , V_11 , V_39 -> V_26 , V_53 ) ;
if ( V_39 -> V_26 == 0 )
return F_30 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 1 )
return F_37 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 2 )
return F_32 ( V_39 , V_53 ) ;
return 0 ;
}
static int F_71 ( struct V_38 * V_39 ,
T_1 * V_117 , struct V_104 * V_105 )
{
F_2 ( L_26 , V_11 , V_39 -> V_26 ) ;
if ( V_39 -> V_26 == 0 ) {
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 6 , 24 , 3072 ) ;
else
F_64 ( V_105 , 6 ) ;
} else if ( V_39 -> V_26 == 1 ) {
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 4 , 96 , 564 ) ;
else
F_64 ( V_105 , 4 ) ;
} else if ( V_39 -> V_26 == 2 && V_103 ) {
* V_117 = V_119 ;
if ( V_58 )
F_65 ( V_105 , 5 , 96 , 200 ) ;
else
F_64 ( V_105 , 5 ) ;
} else if ( V_39 -> V_26 == 2 && ! V_103 ) {
* V_117 = V_119 ;
if ( V_58 )
F_65 ( V_105 , 6 , 24 , 3072 ) ;
else
F_64 ( V_105 , 6 ) ;
}
return 0 ;
}
static int F_72 ( struct V_38 * V_39 , int V_53 )
{
F_2 ( L_27 , V_11 , V_39 -> V_26 , V_53 ) ;
if ( V_39 -> V_26 == 0 )
return F_30 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 1 )
return F_37 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 2 && V_103 )
return F_32 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 2 && ! V_103 )
return F_30 ( V_39 , V_53 ) ;
return 0 ;
}
static int F_73 ( struct V_38 * V_39 ,
T_1 * V_117 , struct V_104 * V_105 )
{
F_2 ( L_26 , V_11 , V_39 -> V_26 ) ;
if ( V_39 -> V_26 == 0 ) {
* V_117 = V_118 ;
if ( V_58 )
F_65 ( V_105 , 4 , 96 , 564 ) ;
else
F_64 ( V_105 , 4 ) ;
} else if ( V_39 -> V_26 == 1 && V_103 ) {
* V_117 = V_119 ;
if ( V_58 )
F_65 ( V_105 , 5 , 96 , 200 ) ;
else
F_64 ( V_105 , 5 ) ;
} else if ( V_39 -> V_26 == 1 && ! V_103 ) {
* V_117 = V_119 ;
if ( V_58 )
F_65 ( V_105 , 6 , 24 , 3072 ) ;
else
F_64 ( V_105 , 6 ) ;
}
return 0 ;
}
static int F_74 ( struct V_38 * V_39 , int V_53 )
{
F_2 ( L_27 , V_11 , V_39 -> V_26 , V_53 ) ;
if ( V_39 -> V_26 == 0 )
return F_37 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 1 && V_103 )
return F_32 ( V_39 , V_53 ) ;
else if ( V_39 -> V_26 == 1 && ! V_103 )
return F_30 ( V_39 , V_53 ) ;
return 0 ;
}
