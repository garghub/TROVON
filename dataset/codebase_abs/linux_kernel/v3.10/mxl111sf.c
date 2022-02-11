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
static int F_15 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_16 ( V_39 ) ;
struct V_12 * V_13 = F_17 ( V_39 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_39 -> V_26 ] ;
int F_8 ;
if ( ! V_13 -> V_30 ) {
F_7 ( L_18 ) ;
goto V_18;
}
F_18 ( L_19 , V_11 ) ;
F_19 ( & V_13 -> V_42 ) ;
V_13 -> V_43 = V_41 -> V_43 ;
if ( F_20 ( V_2 -> V_44 , 0 , V_13 -> V_43 ) < 0 )
F_8 ( L_20 ) ;
F_8 = F_21 ( V_13 ) ;
F_5 ( F_8 ) ;
F_8 = F_22 ( V_13 ) ;
F_5 ( F_8 ) ;
F_8 = F_23 ( V_13 , V_41 -> V_45 ) ;
F_5 ( F_8 ) ;
F_24 ( V_13 ) ;
F_5 ( F_8 ) ;
F_25 ( V_13 , 1 ) ;
F_5 ( F_8 ) ;
if ( ( V_46 != V_41 -> V_47 ) &&
( V_13 -> V_34 > V_35 ) ) {
F_26 ( V_13 ,
V_48 ) ;
F_5 ( F_8 ) ;
}
F_8 = F_27 ( V_13 ) ;
if ( ! F_5 ( F_8 ) ) {
V_13 -> V_47 = V_41 -> V_47 ;
F_8 = F_28 ( V_13 , V_13 -> V_47 ) ;
F_5 ( F_8 ) ;
#if 0
err = fe->ops.init(fe);
#endif
F_29 ( 100 ) ;
}
return ( V_41 -> V_49 ) ? V_41 -> V_49 ( V_39 ) : 0 ;
V_18:
return - V_50 ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_12 * V_13 = F_17 ( V_39 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_39 -> V_26 ] ;
int F_8 ;
if ( ! V_13 -> V_30 ) {
F_7 ( L_18 ) ;
goto V_18;
}
F_18 ( L_19 , V_11 ) ;
F_8 = ( V_41 -> V_51 ) ? V_41 -> V_51 ( V_39 ) : 0 ;
F_31 ( & V_13 -> V_42 ) ;
return F_8 ;
V_18:
return - V_50 ;
}
static int F_32 ( struct V_38 * V_39 , int V_52 )
{
struct V_12 * V_13 = F_17 ( V_39 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_39 -> V_26 ] ;
int V_9 = 0 ;
F_18 ( L_21 , V_11 , V_52 ) ;
if ( V_52 ) {
V_9 = F_24 ( V_13 ) ;
F_5 ( V_9 ) ;
V_9 = F_33 ( V_13 , 1 , 1 ,
V_41 -> V_53 ,
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
static int F_34 ( struct V_38 * V_39 , int V_52 )
{
struct V_12 * V_13 = F_17 ( V_39 ) ;
int V_9 = 0 ;
F_18 ( L_21 , V_11 , V_52 ) ;
if ( V_52 ) {
V_9 = F_24 ( V_13 ) ;
F_5 ( V_9 ) ;
V_9 = F_35 ( V_13 , 200 ) ;
F_5 ( V_9 ) ;
V_9 = F_36 ( V_13 , 0 , 15 ) ;
F_5 ( V_9 ) ;
} else {
V_9 = F_37 ( V_13 ) ;
F_5 ( V_9 ) ;
}
if ( V_13 -> V_34 > V_35 )
V_9 = F_38 ( V_13 , V_52 ) ;
F_5 ( V_9 ) ;
return V_9 ;
}
static int F_39 ( struct V_38 * V_39 , int V_52 )
{
struct V_12 * V_13 = F_17 ( V_39 ) ;
int V_9 = 0 ;
F_18 ( L_21 , V_11 , V_52 ) ;
if ( V_52 ) {
V_9 = F_24 ( V_13 ) ;
F_5 ( V_9 ) ;
}
return V_9 ;
}
static int F_40 ( struct V_54 * V_55 , T_1 V_56 )
{
struct V_1 * V_2 = F_41 ( V_55 ) ;
struct V_12 * V_13 = F_42 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_56 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_43 = ( V_57 ) ? 2 : 1 ;
V_13 -> V_43 = V_41 -> V_43 ;
if ( F_20 ( V_2 -> V_44 , 0 , V_13 -> V_43 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_47 = V_58 ;
V_41 -> V_47 = V_13 -> V_47 ;
V_41 -> V_45 = V_59 ;
V_41 -> V_53 = 1 ;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , V_41 -> V_45 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_27 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_28 ( V_13 , V_13 -> V_47 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_55 -> V_39 [ V_56 ] = F_43 ( V_60 ,
& V_61 ,
& V_2 -> V_62 ) ;
if ( V_55 -> V_39 [ V_56 ] ) {
V_13 -> V_63 ++ ;
V_41 -> V_49 = V_55 -> V_39 [ V_56 ] -> V_64 . V_65 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_65 = F_15 ;
V_41 -> V_51 = V_55 -> V_39 [ V_56 ] -> V_64 . V_66 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_66 = F_30 ;
return 0 ;
}
V_9 = - V_67 ;
V_18:
return V_9 ;
}
static int F_44 ( struct V_54 * V_55 , T_1 V_56 )
{
struct V_1 * V_2 = F_41 ( V_55 ) ;
struct V_12 * V_13 = F_42 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_56 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_43 = ( V_57 ) ? 2 : 1 ;
V_13 -> V_43 = V_41 -> V_43 ;
if ( F_20 ( V_2 -> V_44 , 0 , V_13 -> V_43 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_47 = V_68 ;
V_41 -> V_47 = V_13 -> V_47 ;
V_41 -> V_45 = V_59 ;
V_41 -> V_53 = 1 ;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , V_41 -> V_45 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_27 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_28 ( V_13 , V_13 -> V_47 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_45 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_55 -> V_39 [ V_56 ] = F_43 ( V_69 ,
& V_70 ,
& V_2 -> V_62 ) ;
if ( V_55 -> V_39 [ V_56 ] ) {
V_13 -> V_63 ++ ;
V_41 -> V_49 = V_55 -> V_39 [ V_56 ] -> V_64 . V_65 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_65 = F_15 ;
V_41 -> V_51 = V_55 -> V_39 [ V_56 ] -> V_64 . V_66 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_66 = F_30 ;
return 0 ;
}
V_9 = - V_67 ;
V_18:
return V_9 ;
}
static int F_46 ( struct V_54 * V_55 , T_1 V_56 )
{
struct V_1 * V_2 = F_41 ( V_55 ) ;
struct V_12 * V_13 = F_42 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_56 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_43 = ( V_57 ) ? 2 : 1 ;
V_13 -> V_43 = V_41 -> V_43 ;
if ( F_20 ( V_2 -> V_44 , 0 , V_13 -> V_43 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_47 = V_68 ;
V_41 -> V_47 = V_13 -> V_47 ;
V_41 -> V_45 = V_59 ;
V_41 -> V_53 = 1 ;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , V_41 -> V_45 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_27 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_28 ( V_13 , V_13 -> V_47 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_45 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_55 -> V_39 [ V_56 ] = F_43 ( V_69 ,
( V_37 == V_13 -> V_34 ) ?
& V_71 :
& V_72 ,
& V_2 -> V_62 ) ;
if ( V_55 -> V_39 [ V_56 ] ) {
V_13 -> V_63 ++ ;
V_41 -> V_49 = V_55 -> V_39 [ V_56 ] -> V_64 . V_65 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_65 = F_15 ;
V_41 -> V_51 = V_55 -> V_39 [ V_56 ] -> V_64 . V_66 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_66 = F_30 ;
return 0 ;
}
V_9 = - V_67 ;
V_18:
return V_9 ;
}
static int F_47 ( struct V_54 * V_55 , T_1 V_56 )
{
struct V_1 * V_2 = F_41 ( V_55 ) ;
struct V_12 * V_13 = F_42 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_56 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_43 = ( V_57 ) ? 2 : 1 ;
V_13 -> V_43 = V_41 -> V_43 ;
if ( F_20 ( V_2 -> V_44 , 0 , V_13 -> V_43 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_47 = V_68 ;
V_41 -> V_47 = V_13 -> V_47 ;
V_41 -> V_45 = V_59 ;
V_41 -> V_53 = 0 ;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , V_41 -> V_45 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_27 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_28 ( V_13 , V_13 -> V_47 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_45 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_55 -> V_39 [ V_56 ] = F_43 ( V_69 ,
( V_37 == V_13 -> V_34 ) ?
& V_73 :
& V_74 ,
& V_2 -> V_62 ) ;
if ( V_55 -> V_39 [ V_56 ] ) {
V_13 -> V_63 ++ ;
V_41 -> V_49 = V_55 -> V_39 [ V_56 ] -> V_64 . V_65 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_65 = F_15 ;
V_41 -> V_51 = V_55 -> V_39 [ V_56 ] -> V_64 . V_66 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_66 = F_30 ;
return 0 ;
}
V_9 = - V_67 ;
V_18:
return V_9 ;
}
static int F_48 ( struct V_54 * V_55 , T_1 V_56 )
{
struct V_1 * V_2 = F_41 ( V_55 ) ;
struct V_12 * V_13 = F_42 ( V_2 ) ;
struct V_40 * V_41 = & V_13 -> V_41 [ V_56 ] ;
int V_9 ;
F_2 ( L_19 , V_11 ) ;
V_13 -> V_2 = V_2 ;
V_41 -> V_43 = ( V_57 ) ? 1 : 2 ;
V_13 -> V_43 = V_41 -> V_43 ;
if ( F_20 ( V_2 -> V_44 , 0 , V_13 -> V_43 ) < 0 )
F_8 ( L_20 ) ;
V_13 -> V_47 = V_46 ;
V_41 -> V_47 = V_13 -> V_47 ;
V_41 -> V_45 = V_75 ;
V_41 -> V_53 = 1 ;
V_9 = F_21 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_22 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_23 ( V_13 , V_41 -> V_45 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_24 ( V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
V_9 = F_25 ( V_13 , 1 ) ;
if ( F_5 ( V_9 ) )
goto V_18;
F_27 ( V_13 ) ;
V_55 -> V_39 [ V_56 ] = F_43 ( V_76 , V_13 ,
& V_77 ) ;
if ( V_55 -> V_39 [ V_56 ] ) {
V_13 -> V_63 ++ ;
V_41 -> V_49 = V_55 -> V_39 [ V_56 ] -> V_64 . V_65 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_65 = F_15 ;
V_41 -> V_51 = V_55 -> V_39 [ V_56 ] -> V_64 . V_66 ;
V_55 -> V_39 [ V_56 ] -> V_64 . V_66 = F_30 ;
return 0 ;
}
V_9 = - V_67 ;
V_18:
return V_9 ;
}
static inline int F_49 ( struct V_12 * V_13 ,
int V_78 )
{
return F_50 ( V_13 , 1 , 1 ,
( V_78 == V_79 ) ?
0x3f : 0x00 , 0 ) ;
}
static int F_51 ( struct V_38 * V_39 )
{
struct V_12 * V_13 = F_17 ( V_39 ) ;
int V_80 = V_81 ;
T_2 V_82 , V_83 , V_84 , V_85 ;
F_49 ( V_13 , V_80 == V_86 ?
V_87 : V_80 ) ;
if ( V_80 == V_86 ) {
#if 0
msleep(ANT_HUNT_SLEEP);
#endif
V_39 -> V_64 . V_88 . V_89 ( V_39 , & V_82 ) ;
F_49 ( V_13 , V_87 ) ;
F_29 ( V_90 ) ;
V_39 -> V_64 . V_88 . V_89 ( V_39 , & V_83 ) ;
F_49 ( V_13 , V_87 ) ;
F_29 ( V_90 ) ;
V_39 -> V_64 . V_88 . V_89 ( V_39 , & V_84 ) ;
F_49 ( V_13 , V_79 ) ;
F_29 ( V_90 ) ;
V_39 -> V_64 . V_88 . V_89 ( V_39 , & V_85 ) ;
if ( V_84 + V_91 >= V_85 ) {
F_49 ( V_13 , V_87 ) ;
F_52 ( V_87 , V_82 ,
V_83 , V_84 , V_85 ) ;
} else {
F_52 ( V_79 , V_82 ,
V_83 , V_84 , V_85 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_54 * V_55 )
{
struct V_12 * V_13 = F_54 ( V_55 ) ;
int V_25 ;
F_2 ( L_19 , V_11 ) ;
for ( V_25 = 0 ; V_25 < V_13 -> V_63 ; V_25 ++ ) {
if ( F_43 ( V_92 , V_55 -> V_39 [ V_25 ] , V_13 ,
& V_93 ) == NULL )
return - V_67 ;
V_55 -> V_39 [ V_25 ] -> V_64 . V_94 = V_55 -> V_39 [ V_25 ] -> V_64 . V_88 . V_89 ;
}
return 0 ;
}
static T_3 F_55 ( struct V_95 * V_96 )
{
return V_97 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_42 ( V_2 ) ;
int V_9 ;
static T_1 V_98 [ 256 ] ;
struct V_99 V_100 ;
V_9 = F_45 ( V_13 ) ;
if ( F_5 ( V_9 ) )
F_8 ( L_22 ) ;
F_57 ( & V_13 -> V_42 ) ;
if ( V_13 -> V_34 > V_35 )
F_26 ( V_13 , V_48 ) ;
V_100 . V_96 = & V_2 -> V_62 ;
V_100 . V_14 = 0xa0 >> 1 ;
V_9 = F_58 ( & V_100 , V_98 , sizeof( V_98 ) ) ;
if ( F_5 ( V_9 ) )
return 0 ;
F_59 ( & V_100 , & V_13 -> V_101 , ( 0x84 == V_98 [ 0xa0 ] ) ?
V_98 + 0xa0 : V_98 + 0x80 ) ;
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
static int F_60 ( struct V_54 * V_55 )
{
return F_48 ( V_55 , 0 ) ;
}
static int F_61 ( struct V_54 * V_55 )
{
return F_40 ( V_55 , 0 ) ;
}
static int F_62 ( struct V_54 * V_55 )
{
return F_44 ( V_55 , 0 ) ;
}
static int F_63 ( struct V_54 * V_55 )
{
int V_9 ;
F_18 ( L_23 , V_11 ) ;
V_9 = F_40 ( V_55 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_48 ( V_55 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_44 ( V_55 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 ;
}
static int F_64 ( struct V_54 * V_55 )
{
int V_9 ;
F_18 ( L_23 , V_11 ) ;
V_9 = F_40 ( V_55 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_48 ( V_55 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_47 ( V_55 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 ;
}
static int F_65 ( struct V_54 * V_55 )
{
int V_9 ;
F_18 ( L_23 , V_11 ) ;
V_9 = F_48 ( V_55 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_102 )
V_9 = F_46 ( V_55 , 1 ) ;
else
V_9 = F_47 ( V_55 , 1 ) ;
return V_9 ;
}
static void F_66 ( struct V_103 * V_104 , T_1 V_105 )
{
F_18 ( L_24 , V_11 , V_105 ) ;
V_104 -> type = V_106 ;
V_104 -> V_107 = 5 ;
V_104 -> V_105 = V_105 ;
V_104 -> V_108 . V_109 . V_110 = 8192 ;
}
static void F_67 ( struct V_103 * V_104 ,
T_1 V_105 , int V_111 , int V_112 )
{
F_18 ( L_25 , V_11 , V_105 ,
V_111 * V_112 ) ;
V_104 -> type = V_113 ;
V_104 -> V_107 = 5 ;
V_104 -> V_105 = V_105 ;
V_104 -> V_108 . V_114 . V_111 = V_111 ;
V_104 -> V_108 . V_114 . V_112 = V_112 ;
V_104 -> V_108 . V_114 . V_115 = 1 ;
}
static int F_68 ( struct V_38 * V_39 ,
T_1 * V_116 , struct V_103 * V_104 )
{
F_18 ( L_26 , V_11 , V_39 -> V_26 ) ;
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 4 , 96 , 564 ) ;
else
F_66 ( V_104 , 4 ) ;
return 0 ;
}
static int F_69 ( struct V_38 * V_39 ,
T_1 * V_116 , struct V_103 * V_104 )
{
F_18 ( L_26 , V_11 , V_39 -> V_26 ) ;
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 6 , 24 , 3072 ) ;
else
F_66 ( V_104 , 6 ) ;
return 0 ;
}
static int F_70 ( struct V_38 * V_39 ,
T_1 * V_116 , struct V_103 * V_104 )
{
F_18 ( L_26 , V_11 , V_39 -> V_26 ) ;
* V_116 = V_118 ;
if ( V_57 )
F_67 ( V_104 , 5 , 96 , 200 ) ;
else
F_66 ( V_104 , 5 ) ;
return 0 ;
}
static int F_71 ( struct V_38 * V_39 ,
T_1 * V_116 , struct V_103 * V_104 )
{
F_18 ( L_26 , V_11 , V_39 -> V_26 ) ;
if ( V_39 -> V_26 == 0 ) {
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 6 , 24 , 3072 ) ;
else
F_66 ( V_104 , 6 ) ;
} else if ( V_39 -> V_26 == 1 ) {
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 4 , 96 , 564 ) ;
else
F_66 ( V_104 , 4 ) ;
} else if ( V_39 -> V_26 == 2 ) {
* V_116 = V_118 ;
if ( V_57 )
F_67 ( V_104 , 5 , 96 , 200 ) ;
else
F_66 ( V_104 , 5 ) ;
}
return 0 ;
}
static int F_72 ( struct V_38 * V_39 , int V_52 )
{
F_18 ( L_27 , V_11 , V_39 -> V_26 , V_52 ) ;
if ( V_39 -> V_26 == 0 )
return F_32 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 1 )
return F_39 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 2 )
return F_34 ( V_39 , V_52 ) ;
return 0 ;
}
static int F_73 ( struct V_38 * V_39 ,
T_1 * V_116 , struct V_103 * V_104 )
{
F_18 ( L_26 , V_11 , V_39 -> V_26 ) ;
if ( V_39 -> V_26 == 0 ) {
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 6 , 24 , 3072 ) ;
else
F_66 ( V_104 , 6 ) ;
} else if ( V_39 -> V_26 == 1 ) {
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 4 , 96 , 564 ) ;
else
F_66 ( V_104 , 4 ) ;
} else if ( V_39 -> V_26 == 2 && V_102 ) {
* V_116 = V_118 ;
if ( V_57 )
F_67 ( V_104 , 5 , 96 , 200 ) ;
else
F_66 ( V_104 , 5 ) ;
} else if ( V_39 -> V_26 == 2 && ! V_102 ) {
* V_116 = V_118 ;
if ( V_57 )
F_67 ( V_104 , 6 , 24 , 3072 ) ;
else
F_66 ( V_104 , 6 ) ;
}
return 0 ;
}
static int F_74 ( struct V_38 * V_39 , int V_52 )
{
F_18 ( L_27 , V_11 , V_39 -> V_26 , V_52 ) ;
if ( V_39 -> V_26 == 0 )
return F_32 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 1 )
return F_39 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 2 && V_102 )
return F_34 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 2 && ! V_102 )
return F_32 ( V_39 , V_52 ) ;
return 0 ;
}
static int F_75 ( struct V_38 * V_39 ,
T_1 * V_116 , struct V_103 * V_104 )
{
F_18 ( L_26 , V_11 , V_39 -> V_26 ) ;
if ( V_39 -> V_26 == 0 ) {
* V_116 = V_117 ;
if ( V_57 )
F_67 ( V_104 , 4 , 96 , 564 ) ;
else
F_66 ( V_104 , 4 ) ;
} else if ( V_39 -> V_26 == 1 && V_102 ) {
* V_116 = V_118 ;
if ( V_57 )
F_67 ( V_104 , 5 , 96 , 200 ) ;
else
F_66 ( V_104 , 5 ) ;
} else if ( V_39 -> V_26 == 1 && ! V_102 ) {
* V_116 = V_118 ;
if ( V_57 )
F_67 ( V_104 , 6 , 24 , 3072 ) ;
else
F_66 ( V_104 , 6 ) ;
}
return 0 ;
}
static int F_76 ( struct V_38 * V_39 , int V_52 )
{
F_18 ( L_27 , V_11 , V_39 -> V_26 , V_52 ) ;
if ( V_39 -> V_26 == 0 )
return F_39 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 1 && V_102 )
return F_34 ( V_39 , V_52 ) ;
else if ( V_39 -> V_26 == 1 && ! V_102 )
return F_32 ( V_39 , V_52 ) ;
return 0 ;
}
