int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_10 = ( V_6 == NULL || V_7 == 0 ) ;
int V_11 ;
if ( 1 + V_5 > V_12 ) {
F_2 ( L_1 , V_13 , V_5 ) ;
return - V_14 ;
}
F_3 ( L_2 , V_13 , V_5 , V_7 ) ;
F_4 ( & V_2 -> V_15 ) ;
memset ( V_2 -> V_16 , 0 , 1 + V_5 ) ;
memset ( V_2 -> V_17 , 0 , V_7 ) ;
V_2 -> V_16 [ 0 ] = V_3 ;
memcpy ( & V_2 -> V_16 [ 1 ] , V_4 , V_5 ) ;
V_11 = ( V_10 ) ? F_5 ( V_9 , V_2 -> V_16 , 1 + V_5 ) :
F_6 ( V_9 , V_2 -> V_16 , 1 + V_5 , V_2 -> V_17 ,
V_7 ) ;
if ( V_6 )
memcpy ( V_6 , V_2 -> V_17 , V_7 ) ;
F_7 ( & V_2 -> V_15 ) ;
F_8 ( V_11 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_19 )
{
T_1 V_20 [ 2 ] ;
int V_11 ;
V_11 = F_1 ( V_2 , V_21 , & V_18 , 1 , V_20 , 2 ) ;
if ( F_8 ( V_11 ) ) {
F_10 ( L_3 , V_18 ) ;
goto V_22;
}
if ( V_20 [ 0 ] == V_18 )
* V_19 = V_20 [ 1 ] ;
else {
F_11 ( L_4 ,
V_18 , V_20 [ 0 ] , V_20 [ 1 ] ) ;
V_11 = - V_23 ;
}
F_3 ( L_5 , V_18 , V_20 [ 1 ] ) ;
V_22:
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_19 )
{
T_1 V_20 [] = { V_18 , V_19 } ;
int V_11 ;
F_3 ( L_6 , V_18 , V_19 ) ;
V_11 = F_1 ( V_2 , V_24 , V_20 , 2 , NULL , 0 ) ;
if ( F_8 ( V_11 ) )
F_11 ( L_7 , V_18 , V_19 ) ;
return V_11 ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 V_18 , T_1 V_25 , T_1 V_19 )
{
int V_11 ;
T_1 V_26 = 0 ;
if ( V_25 != 0xff ) {
V_11 = F_9 ( V_2 , V_18 , & V_26 ) ;
#if 1
if ( F_8 ( V_11 ) )
F_11 ( L_8 ,
V_18 , V_25 , V_19 ) ;
V_11 = F_9 ( V_2 , V_18 , & V_26 ) ;
#endif
if ( F_8 ( V_11 ) )
goto V_22;
}
V_26 &= ~ V_25 ;
V_26 |= V_19 ;
V_11 = F_12 ( V_2 , V_18 , V_26 ) ;
F_8 ( V_11 ) ;
V_22:
return V_11 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_29 , V_11 = 0 ;
for ( V_29 = 0 ; V_28 [ V_29 ] . V_18 |
V_28 [ V_29 ] . V_25 |
V_28 [ V_29 ] . V_19 ; V_29 ++ ) {
V_11 = F_13 ( V_2 ,
V_28 [ V_29 ] . V_18 ,
V_28 [ V_29 ] . V_25 ,
V_28 [ V_29 ] . V_19 ) ;
if ( F_8 ( V_11 ) ) {
F_11 ( L_9 , V_29 ,
V_28 [ V_29 ] . V_18 ) ;
break;
}
}
return V_11 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_30 , V_31 ;
char * V_32 , * V_33 ;
if ( ( V_2 -> V_34 ) && ( V_2 -> V_35 ) )
return 0 ;
V_11 = F_9 ( V_2 , V_36 , & V_30 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_2 -> V_34 = V_30 ;
V_11 = F_9 ( V_2 , V_37 , & V_31 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_2 -> V_35 = V_31 ;
switch ( V_30 ) {
case 0x61 :
V_32 = L_10 ;
break;
case 0x63 :
V_32 = L_11 ;
break;
default:
V_32 = L_12 ;
break;
}
switch ( V_31 ) {
case 0x36 :
V_2 -> V_38 = V_39 ;
V_33 = L_13 ;
break;
case 0x08 :
V_2 -> V_38 = V_40 ;
V_33 = L_14 ;
break;
case 0x18 :
V_2 -> V_38 = V_41 ;
V_33 = L_15 ;
break;
default:
V_2 -> V_38 = 0 ;
V_33 = L_16 ;
break;
}
F_16 ( L_17 , V_32 , V_33 , V_31 ) ;
V_22:
return V_11 ;
}
static int F_17 ( struct V_42 * V_43 )
{
struct V_8 * V_9 = F_18 ( V_43 ) ;
struct V_1 * V_2 = F_19 ( V_43 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_43 -> V_30 ] ;
int V_46 ;
if ( ! V_2 -> V_34 ) {
F_10 ( L_18 ) ;
goto V_22;
}
F_3 ( L_19 , V_13 ) ;
F_4 ( & V_2 -> V_47 ) ;
V_2 -> V_48 = V_45 -> V_48 ;
if ( F_20 ( V_9 -> V_49 , 0 , V_2 -> V_48 ) < 0 )
F_11 ( L_20 ) ;
V_46 = F_21 ( V_2 ) ;
F_8 ( V_46 ) ;
V_46 = F_22 ( V_2 ) ;
F_8 ( V_46 ) ;
V_46 = F_23 ( V_2 , V_45 -> V_50 ) ;
F_8 ( V_46 ) ;
V_46 = F_24 ( V_2 ) ;
F_8 ( V_46 ) ;
V_46 = F_25 ( V_2 , 1 ) ;
F_8 ( V_46 ) ;
if ( ( V_51 != V_45 -> V_52 ) &&
( V_2 -> V_38 > V_39 ) ) {
F_26 ( V_2 ,
V_53 ) ;
F_8 ( V_46 ) ;
}
V_46 = F_27 ( V_2 ) ;
if ( ! F_8 ( V_46 ) ) {
V_2 -> V_52 = V_45 -> V_52 ;
V_46 = F_28 ( V_2 , V_2 -> V_52 ) ;
F_8 ( V_46 ) ;
#if 0
err = fe->ops.init(fe);
#endif
F_29 ( 100 ) ;
}
return ( V_45 -> V_54 ) ? V_45 -> V_54 ( V_43 ) : 0 ;
V_22:
return - V_55 ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_43 -> V_30 ] ;
int V_46 ;
if ( ! V_2 -> V_34 ) {
F_10 ( L_18 ) ;
goto V_22;
}
F_3 ( L_19 , V_13 ) ;
V_46 = ( V_45 -> V_56 ) ? V_45 -> V_56 ( V_43 ) : 0 ;
F_7 ( & V_2 -> V_47 ) ;
return V_46 ;
V_22:
return - V_55 ;
}
static int F_31 ( struct V_42 * V_43 , int V_57 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_43 -> V_30 ] ;
int V_11 = 0 ;
F_3 ( L_21 , V_13 , V_57 ) ;
if ( V_57 ) {
V_11 = F_24 ( V_2 ) ;
F_8 ( V_11 ) ;
V_11 = F_32 ( V_2 , 1 , 1 ,
V_45 -> V_58 ,
0 , 0 ) ;
F_8 ( V_11 ) ;
#if 0
} else {
ret = mxl111sf_disable_656_port(state);
mxl_fail(ret);
#endif
}
return V_11 ;
}
static int F_33 ( struct V_42 * V_43 , int V_57 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
int V_11 = 0 ;
F_3 ( L_21 , V_13 , V_57 ) ;
if ( V_57 ) {
V_11 = F_24 ( V_2 ) ;
F_8 ( V_11 ) ;
V_11 = F_34 ( V_2 , 200 ) ;
F_8 ( V_11 ) ;
V_11 = F_35 ( V_2 , 0 , 15 ) ;
F_8 ( V_11 ) ;
} else {
V_11 = F_36 ( V_2 ) ;
F_8 ( V_11 ) ;
}
if ( V_2 -> V_38 > V_39 )
V_11 = F_37 ( V_2 , V_57 ) ;
F_8 ( V_11 ) ;
return V_11 ;
}
static int F_38 ( struct V_42 * V_43 , int V_57 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
int V_11 = 0 ;
F_3 ( L_21 , V_13 , V_57 ) ;
if ( V_57 ) {
V_11 = F_24 ( V_2 ) ;
F_8 ( V_11 ) ;
}
return V_11 ;
}
static int F_39 ( struct V_59 * V_60 , T_1 V_61 )
{
struct V_8 * V_9 = F_40 ( V_60 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_61 ] ;
int V_11 ;
F_3 ( L_19 , V_13 ) ;
V_2 -> V_9 = V_9 ;
V_45 -> V_48 = ( V_62 ) ? 2 : 1 ;
V_2 -> V_48 = V_45 -> V_48 ;
if ( F_20 ( V_9 -> V_49 , 0 , V_2 -> V_48 ) < 0 )
F_11 ( L_20 ) ;
V_2 -> V_52 = V_63 ;
V_45 -> V_52 = V_2 -> V_52 ;
V_45 -> V_50 = V_64 ;
V_45 -> V_58 = 1 ;
V_11 = F_21 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_22 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_23 ( V_2 , V_45 -> V_50 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_24 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_25 ( V_2 , 1 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_27 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_28 ( V_2 , V_2 -> V_52 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_60 -> V_43 [ V_61 ] = F_42 ( V_65 ,
& V_66 ,
& V_9 -> V_67 ) ;
if ( V_60 -> V_43 [ V_61 ] ) {
V_2 -> V_68 ++ ;
V_45 -> V_54 = V_60 -> V_43 [ V_61 ] -> V_69 . V_70 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_70 = F_17 ;
V_45 -> V_56 = V_60 -> V_43 [ V_61 ] -> V_69 . V_71 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_71 = F_30 ;
return 0 ;
}
V_11 = - V_72 ;
V_22:
return V_11 ;
}
static int F_43 ( struct V_59 * V_60 , T_1 V_61 )
{
struct V_8 * V_9 = F_40 ( V_60 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_61 ] ;
int V_11 ;
F_3 ( L_19 , V_13 ) ;
V_2 -> V_9 = V_9 ;
V_45 -> V_48 = ( V_62 ) ? 2 : 1 ;
V_2 -> V_48 = V_45 -> V_48 ;
if ( F_20 ( V_9 -> V_49 , 0 , V_2 -> V_48 ) < 0 )
F_11 ( L_20 ) ;
V_2 -> V_52 = V_73 ;
V_45 -> V_52 = V_2 -> V_52 ;
V_45 -> V_50 = V_64 ;
V_45 -> V_58 = 1 ;
V_11 = F_21 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_22 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_23 ( V_2 , V_45 -> V_50 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_24 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_25 ( V_2 , 1 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_27 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_28 ( V_2 , V_2 -> V_52 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_44 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_60 -> V_43 [ V_61 ] = F_42 ( V_74 ,
& V_75 ,
& V_9 -> V_67 ) ;
if ( V_60 -> V_43 [ V_61 ] ) {
V_2 -> V_68 ++ ;
V_45 -> V_54 = V_60 -> V_43 [ V_61 ] -> V_69 . V_70 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_70 = F_17 ;
V_45 -> V_56 = V_60 -> V_43 [ V_61 ] -> V_69 . V_71 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_71 = F_30 ;
return 0 ;
}
V_11 = - V_72 ;
V_22:
return V_11 ;
}
static int F_45 ( struct V_59 * V_60 , T_1 V_61 )
{
struct V_8 * V_9 = F_40 ( V_60 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_61 ] ;
int V_11 ;
F_3 ( L_19 , V_13 ) ;
V_2 -> V_9 = V_9 ;
V_45 -> V_48 = ( V_62 ) ? 2 : 1 ;
V_2 -> V_48 = V_45 -> V_48 ;
if ( F_20 ( V_9 -> V_49 , 0 , V_2 -> V_48 ) < 0 )
F_11 ( L_20 ) ;
V_2 -> V_52 = V_73 ;
V_45 -> V_52 = V_2 -> V_52 ;
V_45 -> V_50 = V_64 ;
V_45 -> V_58 = 1 ;
V_11 = F_21 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_22 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_23 ( V_2 , V_45 -> V_50 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_24 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_25 ( V_2 , 1 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_27 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_28 ( V_2 , V_2 -> V_52 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_44 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_60 -> V_43 [ V_61 ] = F_42 ( V_74 ,
( V_41 == V_2 -> V_38 ) ?
& V_76 :
& V_77 ,
& V_9 -> V_67 ) ;
if ( V_60 -> V_43 [ V_61 ] ) {
V_2 -> V_68 ++ ;
V_45 -> V_54 = V_60 -> V_43 [ V_61 ] -> V_69 . V_70 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_70 = F_17 ;
V_45 -> V_56 = V_60 -> V_43 [ V_61 ] -> V_69 . V_71 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_71 = F_30 ;
return 0 ;
}
V_11 = - V_72 ;
V_22:
return V_11 ;
}
static int F_46 ( struct V_59 * V_60 , T_1 V_61 )
{
struct V_8 * V_9 = F_40 ( V_60 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_61 ] ;
int V_11 ;
F_3 ( L_19 , V_13 ) ;
V_2 -> V_9 = V_9 ;
V_45 -> V_48 = ( V_62 ) ? 2 : 1 ;
V_2 -> V_48 = V_45 -> V_48 ;
if ( F_20 ( V_9 -> V_49 , 0 , V_2 -> V_48 ) < 0 )
F_11 ( L_20 ) ;
V_2 -> V_52 = V_73 ;
V_45 -> V_52 = V_2 -> V_52 ;
V_45 -> V_50 = V_64 ;
V_45 -> V_58 = 0 ;
V_11 = F_21 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_22 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_23 ( V_2 , V_45 -> V_50 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_24 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_25 ( V_2 , 1 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_27 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_28 ( V_2 , V_2 -> V_52 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_44 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_60 -> V_43 [ V_61 ] = F_42 ( V_74 ,
( V_41 == V_2 -> V_38 ) ?
& V_78 :
& V_79 ,
& V_9 -> V_67 ) ;
if ( V_60 -> V_43 [ V_61 ] ) {
V_2 -> V_68 ++ ;
V_45 -> V_54 = V_60 -> V_43 [ V_61 ] -> V_69 . V_70 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_70 = F_17 ;
V_45 -> V_56 = V_60 -> V_43 [ V_61 ] -> V_69 . V_71 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_71 = F_30 ;
return 0 ;
}
V_11 = - V_72 ;
V_22:
return V_11 ;
}
static int F_47 ( struct V_59 * V_60 , T_1 V_61 )
{
struct V_8 * V_9 = F_40 ( V_60 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
struct V_44 * V_45 = & V_2 -> V_45 [ V_61 ] ;
int V_11 ;
F_3 ( L_19 , V_13 ) ;
V_2 -> V_9 = V_9 ;
V_45 -> V_48 = ( V_62 ) ? 1 : 2 ;
V_2 -> V_48 = V_45 -> V_48 ;
if ( F_20 ( V_9 -> V_49 , 0 , V_2 -> V_48 ) < 0 )
F_11 ( L_20 ) ;
V_2 -> V_52 = V_51 ;
V_45 -> V_52 = V_2 -> V_52 ;
V_45 -> V_50 = V_80 ;
V_45 -> V_58 = 1 ;
V_11 = F_21 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_22 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_23 ( V_2 , V_45 -> V_50 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_24 ( V_2 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
V_11 = F_25 ( V_2 , 1 ) ;
if ( F_8 ( V_11 ) )
goto V_22;
F_27 ( V_2 ) ;
V_60 -> V_43 [ V_61 ] = F_42 ( V_81 , V_2 ,
& V_82 ) ;
if ( V_60 -> V_43 [ V_61 ] ) {
V_2 -> V_68 ++ ;
V_45 -> V_54 = V_60 -> V_43 [ V_61 ] -> V_69 . V_70 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_70 = F_17 ;
V_45 -> V_56 = V_60 -> V_43 [ V_61 ] -> V_69 . V_71 ;
V_60 -> V_43 [ V_61 ] -> V_69 . V_71 = F_30 ;
return 0 ;
}
V_11 = - V_72 ;
V_22:
return V_11 ;
}
static inline int F_48 ( struct V_1 * V_2 ,
int V_83 )
{
return F_49 ( V_2 , 1 , 1 ,
( V_83 == V_84 ) ?
0x3f : 0x00 , 0 ) ;
}
static int F_50 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
int V_85 = V_86 ;
T_2 V_87 , V_88 , V_89 , V_90 ;
F_48 ( V_2 , V_85 == V_91 ?
V_92 : V_85 ) ;
if ( V_85 == V_91 ) {
#if 0
msleep(ANT_HUNT_SLEEP);
#endif
V_43 -> V_69 . V_93 . V_94 ( V_43 , & V_87 ) ;
F_48 ( V_2 , V_92 ) ;
F_29 ( V_95 ) ;
V_43 -> V_69 . V_93 . V_94 ( V_43 , & V_88 ) ;
F_48 ( V_2 , V_92 ) ;
F_29 ( V_95 ) ;
V_43 -> V_69 . V_93 . V_94 ( V_43 , & V_89 ) ;
F_48 ( V_2 , V_84 ) ;
F_29 ( V_95 ) ;
V_43 -> V_69 . V_93 . V_94 ( V_43 , & V_90 ) ;
if ( V_89 + V_96 >= V_90 ) {
F_48 ( V_2 , V_92 ) ;
F_51 ( V_92 , V_87 ,
V_88 , V_89 , V_90 ) ;
} else {
F_51 ( V_84 , V_87 ,
V_88 , V_89 , V_90 ) ;
}
}
return 0 ;
}
static int F_52 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_53 ( V_60 ) ;
#ifdef F_54
struct V_97 * V_98 = F_55 ( & V_60 -> V_99 ) ;
int V_11 ;
#endif
int V_29 ;
F_3 ( L_19 , V_13 ) ;
for ( V_29 = 0 ; V_29 < V_2 -> V_68 ; V_29 ++ ) {
if ( F_42 ( V_100 , V_60 -> V_43 [ V_29 ] , V_2 ,
& V_101 ) == NULL )
return - V_72 ;
V_60 -> V_43 [ V_29 ] -> V_69 . V_102 = V_60 -> V_43 [ V_29 ] -> V_69 . V_93 . V_94 ;
}
#ifdef F_54
V_2 -> V_103 . V_104 = V_105 ;
V_2 -> V_103 . V_106 = L_22 ;
V_2 -> V_107 [ V_108 ] . V_109 = V_110 ;
V_2 -> V_107 [ V_111 ] . V_109 = V_112 ;
V_11 = F_56 ( & V_2 -> V_103 ,
V_113 , V_2 -> V_107 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_57 ( V_98 , & V_2 -> V_103 ) ;
if ( V_11 )
return V_11 ;
#endif
return 0 ;
}
static T_3 F_58 ( struct V_114 * V_115 )
{
return V_116 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_41 ( V_9 ) ;
int V_11 ;
static T_1 V_117 [ 256 ] ;
T_1 V_118 = 0 ;
struct V_119 V_120 [ 2 ] = {
{ . V_18 = 0xa0 >> 1 , . V_121 = 1 , . V_20 = & V_118 } ,
{ . V_18 = 0xa0 >> 1 , . V_109 = V_122 ,
. V_121 = sizeof( V_117 ) , . V_20 = V_117 } ,
} ;
F_60 ( & V_2 -> V_15 ) ;
V_11 = F_44 ( V_2 ) ;
if ( F_8 ( V_11 ) )
F_11 ( L_23 ) ;
F_60 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_38 > V_39 )
F_26 ( V_2 , V_53 ) ;
V_11 = F_61 ( & V_9 -> V_67 , V_120 , 2 ) ;
if ( F_8 ( V_11 ) )
return 0 ;
F_62 ( & V_2 -> V_123 , ( 0x84 == V_117 [ 0xa0 ] ) ?
V_117 + 0xa0 : V_117 + 0x80 ) ;
#if 0
switch (state->tv.model) {
case 117001:
case 126001:
case 138001:
break;
default:
printk(KERN_WARNING "%s: warning: unknown hauppauge model #%d\n",
__func__, state->tv.model);
}
#endif
return 0 ;
}
static int F_63 ( struct V_59 * V_60 )
{
return F_47 ( V_60 , 0 ) ;
}
static int F_64 ( struct V_59 * V_60 )
{
return F_39 ( V_60 , 0 ) ;
}
static int F_65 ( struct V_59 * V_60 )
{
return F_43 ( V_60 , 0 ) ;
}
static int F_66 ( struct V_59 * V_60 )
{
int V_11 ;
F_3 ( L_24 , V_13 ) ;
V_11 = F_39 ( V_60 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_47 ( V_60 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_43 ( V_60 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_11 ;
}
static int F_67 ( struct V_59 * V_60 )
{
int V_11 ;
F_3 ( L_24 , V_13 ) ;
V_11 = F_39 ( V_60 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_47 ( V_60 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_46 ( V_60 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_11 ;
}
static int F_68 ( struct V_59 * V_60 )
{
int V_11 ;
F_3 ( L_24 , V_13 ) ;
V_11 = F_47 ( V_60 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_124 )
V_11 = F_45 ( V_60 , 1 ) ;
else
V_11 = F_46 ( V_60 , 1 ) ;
return V_11 ;
}
static void F_69 ( struct V_125 * V_126 , T_1 V_127 )
{
F_3 ( L_25 , V_13 , V_127 ) ;
V_126 -> type = V_128 ;
V_126 -> V_129 = 5 ;
V_126 -> V_127 = V_127 ;
V_126 -> V_130 . V_131 . V_132 = 8192 ;
}
static void F_70 ( struct V_125 * V_126 ,
T_1 V_127 , int V_133 , int V_134 )
{
F_3 ( L_26 , V_13 , V_127 ,
V_133 * V_134 ) ;
V_126 -> type = V_135 ;
V_126 -> V_129 = 5 ;
V_126 -> V_127 = V_127 ;
V_126 -> V_130 . V_136 . V_133 = V_133 ;
V_126 -> V_130 . V_136 . V_134 = V_134 ;
V_126 -> V_130 . V_136 . V_137 = 1 ;
}
static int F_71 ( struct V_42 * V_43 ,
T_1 * V_138 , struct V_125 * V_126 )
{
F_3 ( L_27 , V_13 , V_43 -> V_30 ) ;
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 4 , 96 , 564 ) ;
else
F_69 ( V_126 , 4 ) ;
return 0 ;
}
static int F_72 ( struct V_42 * V_43 ,
T_1 * V_138 , struct V_125 * V_126 )
{
F_3 ( L_27 , V_13 , V_43 -> V_30 ) ;
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 6 , 24 , 3072 ) ;
else
F_69 ( V_126 , 6 ) ;
return 0 ;
}
static int F_73 ( struct V_42 * V_43 ,
T_1 * V_138 , struct V_125 * V_126 )
{
F_3 ( L_27 , V_13 , V_43 -> V_30 ) ;
* V_138 = V_140 ;
if ( V_62 )
F_70 ( V_126 , 5 , 96 , 200 ) ;
else
F_69 ( V_126 , 5 ) ;
return 0 ;
}
static int F_74 ( struct V_42 * V_43 ,
T_1 * V_138 , struct V_125 * V_126 )
{
F_3 ( L_27 , V_13 , V_43 -> V_30 ) ;
if ( V_43 -> V_30 == 0 ) {
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 6 , 24 , 3072 ) ;
else
F_69 ( V_126 , 6 ) ;
} else if ( V_43 -> V_30 == 1 ) {
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 4 , 96 , 564 ) ;
else
F_69 ( V_126 , 4 ) ;
} else if ( V_43 -> V_30 == 2 ) {
* V_138 = V_140 ;
if ( V_62 )
F_70 ( V_126 , 5 , 96 , 200 ) ;
else
F_69 ( V_126 , 5 ) ;
}
return 0 ;
}
static int F_75 ( struct V_42 * V_43 , int V_57 )
{
F_3 ( L_28 , V_13 , V_43 -> V_30 , V_57 ) ;
if ( V_43 -> V_30 == 0 )
return F_31 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 1 )
return F_38 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 2 )
return F_33 ( V_43 , V_57 ) ;
return 0 ;
}
static int F_76 ( struct V_42 * V_43 ,
T_1 * V_138 , struct V_125 * V_126 )
{
F_3 ( L_27 , V_13 , V_43 -> V_30 ) ;
if ( V_43 -> V_30 == 0 ) {
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 6 , 24 , 3072 ) ;
else
F_69 ( V_126 , 6 ) ;
} else if ( V_43 -> V_30 == 1 ) {
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 4 , 96 , 564 ) ;
else
F_69 ( V_126 , 4 ) ;
} else if ( V_43 -> V_30 == 2 && V_124 ) {
* V_138 = V_140 ;
if ( V_62 )
F_70 ( V_126 , 5 , 96 , 200 ) ;
else
F_69 ( V_126 , 5 ) ;
} else if ( V_43 -> V_30 == 2 && ! V_124 ) {
* V_138 = V_140 ;
if ( V_62 )
F_70 ( V_126 , 6 , 24 , 3072 ) ;
else
F_69 ( V_126 , 6 ) ;
}
return 0 ;
}
static int F_77 ( struct V_42 * V_43 , int V_57 )
{
F_3 ( L_28 , V_13 , V_43 -> V_30 , V_57 ) ;
if ( V_43 -> V_30 == 0 )
return F_31 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 1 )
return F_38 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 2 && V_124 )
return F_33 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 2 && ! V_124 )
return F_31 ( V_43 , V_57 ) ;
return 0 ;
}
static int F_78 ( struct V_42 * V_43 ,
T_1 * V_138 , struct V_125 * V_126 )
{
F_3 ( L_27 , V_13 , V_43 -> V_30 ) ;
if ( V_43 -> V_30 == 0 ) {
* V_138 = V_139 ;
if ( V_62 )
F_70 ( V_126 , 4 , 96 , 564 ) ;
else
F_69 ( V_126 , 4 ) ;
} else if ( V_43 -> V_30 == 1 && V_124 ) {
* V_138 = V_140 ;
if ( V_62 )
F_70 ( V_126 , 5 , 96 , 200 ) ;
else
F_69 ( V_126 , 5 ) ;
} else if ( V_43 -> V_30 == 1 && ! V_124 ) {
* V_138 = V_140 ;
if ( V_62 )
F_70 ( V_126 , 6 , 24 , 3072 ) ;
else
F_69 ( V_126 , 6 ) ;
}
return 0 ;
}
static int F_79 ( struct V_42 * V_43 , int V_57 )
{
F_3 ( L_28 , V_13 , V_43 -> V_30 , V_57 ) ;
if ( V_43 -> V_30 == 0 )
return F_38 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 1 && V_124 )
return F_33 ( V_43 , V_57 ) ;
else if ( V_43 -> V_30 == 1 && ! V_124 )
return F_31 ( V_43 , V_57 ) ;
return 0 ;
}
