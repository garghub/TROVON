static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , const T_2 * V_6 )
{
struct V_7 V_8 = {
. V_4 = F_2 ( V_4 ) ,
. V_5 = F_2 ( V_5 ) ,
. type = F_2 ( V_3 ) ,
. V_9 = V_10 ,
} ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = { sizeof( struct V_7 ) , V_5 } ,
. V_16 = V_17 ,
. V_6 = { & V_8 , V_6 } ,
. V_18 = { 0 , V_19 } ,
} ;
return F_3 ( V_2 , & V_12 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_2 * V_6 )
{
struct V_7 V_8 = {
. V_4 = F_2 ( V_4 ) ,
. V_5 = F_2 ( V_5 ) ,
. type = F_2 ( V_3 ) ,
. V_9 = V_20 ,
} ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_16 = V_25 | V_17 ,
. V_6 = { & V_8 , } ,
} ;
int V_26 , V_27 , V_28 ;
T_2 * V_29 ;
V_12 . V_15 [ 0 ] = sizeof( struct V_7 ) ;
V_26 = F_3 ( V_2 , & V_12 ) ;
if ( V_26 )
return V_26 ;
V_24 = V_12 . V_30 ;
if ( V_24 -> V_31 . V_16 & V_32 ) {
F_5 ( V_2 , L_1 ,
V_24 -> V_31 . V_16 ) ;
V_26 = - V_33 ;
goto exit;
}
V_22 = ( void * ) V_24 -> V_6 ;
V_26 = F_6 ( V_22 -> V_34 ) ;
V_27 = F_6 ( V_22 -> V_5 ) ;
V_28 = F_6 ( V_22 -> V_4 ) ;
V_29 = V_22 -> V_6 ;
if ( V_26 ) {
if ( ( V_4 != 0 ) &&
( V_26 == V_35 ) ) {
F_7 ( V_2 -> V_36 -> V_37 ,
L_2 ,
V_4 ) ;
V_26 = 0 ;
} else {
F_7 ( V_2 -> V_36 -> V_37 ,
L_3 ,
V_26 , V_2 -> V_38 -> V_39 ) ;
V_26 = - V_33 ;
}
goto exit;
}
if ( V_28 != V_4 ) {
F_5 ( V_2 , L_4 ,
V_28 ) ;
V_26 = - V_40 ;
goto exit;
}
memcpy ( V_6 + V_4 , V_29 , V_27 ) ;
V_26 = V_27 ;
exit:
F_8 ( & V_12 ) ;
return V_26 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
const T_2 * V_6 , T_1 V_5 )
{
int V_4 = 0 ;
while ( V_4 < V_5 ) {
int V_41 , V_26 ;
V_41 = F_10 ( V_42 ,
V_5 - V_4 ) ;
V_26 = F_1 ( V_2 , V_3 , V_4 ,
V_41 , V_6 + V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
V_4 += V_41 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_6 , T_3 V_43 )
{
T_1 V_5 , V_4 = 0 ;
int V_26 ;
V_5 = V_42 ;
V_26 = V_5 ;
while ( V_26 == V_5 ) {
if ( ( V_43 + V_4 + V_5 ) >
V_2 -> V_38 -> V_44 -> V_45 ) {
F_5 ( V_2 , L_5 ) ;
return - V_46 ;
}
V_26 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_26 < 0 ) {
F_7 ( V_2 -> V_36 -> V_37 ,
L_6 ,
V_3 , V_4 , V_5 ) ;
return V_26 ;
}
V_4 += V_26 ;
}
F_7 ( V_2 -> V_36 -> V_37 ,
L_7 , V_3 ) ;
return V_4 ;
}
static struct V_47 *
F_12 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
const T_4 * V_51 , * V_52 , * V_53 , * V_54 , * V_55 ;
if ( V_2 -> V_36 -> V_38 -> V_56 != V_57 ) {
if ( ! V_2 -> V_50 [ V_58 ] . V_6 ||
! V_2 -> V_50 [ V_2 -> V_38 -> V_59 ] . V_6 ) {
F_5 ( V_2 , L_8 ) ;
return NULL ;
}
} else {
if ( ! V_2 -> V_50 [ V_58 ] . V_6 ||
! V_2 -> V_50 [ V_60 ] . V_6 ) {
F_5 ( V_2 ,
L_9 ) ;
return NULL ;
}
if ( ! V_2 -> V_50 [ V_2 -> V_38 -> V_59 ] . V_6 &&
! V_2 -> V_50 [ V_61 ] . V_6 ) {
F_5 ( V_2 ,
L_10 ) ;
return NULL ;
}
}
if ( F_13 ( ! V_2 -> V_38 ) )
return NULL ;
V_51 = ( const T_4 * ) V_49 [ V_2 -> V_38 -> V_59 ] . V_6 ;
V_52 = ( const T_4 * ) V_49 [ V_58 ] . V_6 ;
V_53 = ( const T_4 * ) V_49 [ V_62 ] . V_6 ;
V_54 = ( const T_4 * ) V_49 [ V_60 ] . V_6 ;
V_55 =
( const T_4 * ) V_49 [ V_61 ] . V_6 ;
return F_14 ( V_2 -> V_36 -> V_37 , V_2 -> V_38 , V_51 , V_52 , V_53 ,
V_54 , V_55 ,
V_2 -> V_63 -> V_64 ,
V_2 -> V_63 -> V_65 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_26 , V_66 ;
T_1 V_67 ;
const struct V_68 * V_69 ;
const struct {
T_4 V_70 ;
T_4 V_71 ;
T_2 V_6 [] ;
} * V_72 ;
const T_2 * V_73 , * V_74 ;
int V_75 ;
#define F_16 ( T_5 ) (8 * (x & 0x03FF))
#define F_17 ( T_5 ) (x >> 12)
#define F_18 ( T_5 ) (2 * ((x & 0xFF) << 8 | x >> 8))
#define F_19 ( T_5 ) (x >> 4)
F_7 ( V_2 -> V_36 -> V_37 , L_11 ) ;
if ( V_2 -> V_36 -> V_38 -> V_56 != V_57 )
V_75 = V_76 ;
else if ( F_20 ( V_2 -> V_36 -> V_77 ) == V_78 )
V_75 = V_79 ;
else
V_75 = V_80 ;
V_26 = F_21 ( & V_69 , V_2 -> V_81 ,
V_2 -> V_36 -> V_37 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_12 ,
V_2 -> V_81 , V_26 ) ;
return V_26 ;
}
F_22 ( V_2 , L_13 ,
V_2 -> V_81 , V_69 -> V_82 ) ;
if ( V_69 -> V_82 < sizeof( * V_72 ) ) {
F_5 ( V_2 , L_14 ) ;
V_26 = - V_40 ;
goto V_83;
}
if ( V_69 -> V_82 > V_84 ) {
F_5 ( V_2 , L_15 ) ;
V_26 = - V_40 ;
goto V_83;
}
V_73 = V_69 -> V_6 + V_69 -> V_82 ;
V_72 = ( void * ) V_69 -> V_6 ;
while ( true ) {
if ( V_72 -> V_6 > V_73 ) {
F_5 ( V_2 ,
L_16 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_72 -> V_70 && ! V_72 -> V_71 ) {
V_26 = 0 ;
break;
}
if ( V_2 -> V_36 -> V_38 -> V_56 != V_57 ) {
V_66 =
2 * F_16 ( F_6 ( V_72 -> V_70 ) ) ;
V_67 = F_17 ( F_6 ( V_72 -> V_71 ) ) ;
} else {
V_66 = 2 * F_18 (
F_6 ( V_72 -> V_71 ) ) ;
V_67 = F_19 (
F_6 ( V_72 -> V_70 ) ) ;
}
if ( V_66 > V_75 ) {
F_5 ( V_2 , L_17 ,
V_66 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_66 ) {
F_5 ( V_2 , L_18 ) ;
V_26 = - V_40 ;
break;
}
if ( V_72 -> V_6 + V_66 > V_73 ) {
F_5 ( V_2 ,
L_19 ,
V_66 ) ;
V_26 = - V_40 ;
break;
}
if ( F_23 ( V_67 >= V_85 ,
L_20 , V_67 ) ) {
V_26 = - V_40 ;
break;
}
V_74 = F_24 ( V_72 -> V_6 , V_66 , V_86 ) ;
if ( ! V_74 ) {
V_26 = - V_87 ;
break;
}
V_2 -> V_50 [ V_67 ] . V_6 = V_74 ;
V_2 -> V_50 [ V_67 ] . V_5 = V_66 ;
V_72 = ( void * ) ( V_72 -> V_6 + V_66 ) ;
}
V_83:
F_25 ( V_69 ) ;
return V_26 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_88 , V_26 = 0 ;
struct V_48 * V_49 = V_2 -> V_50 ;
F_7 ( V_2 -> V_36 -> V_37 , L_21 ) ;
for ( V_88 = 0 ; V_88 < F_27 ( V_2 -> V_50 ) ; V_88 ++ ) {
if ( ! V_2 -> V_50 [ V_88 ] . V_6 || ! V_2 -> V_50 [ V_88 ] . V_5 )
continue;
V_26 = F_9 ( V_2 , V_88 , V_49 [ V_88 ] . V_6 ,
V_49 [ V_88 ] . V_5 ) ;
if ( V_26 < 0 ) {
F_5 ( V_2 , L_22 , V_26 ) ;
break;
}
}
return V_26 ;
}
int F_28 ( struct V_1 * V_2 , bool V_89 )
{
int V_26 , V_3 ;
T_3 V_43 = 0 ;
T_2 * V_90 , * V_74 ;
if ( F_29 ( V_2 -> V_38 -> V_59 >= V_85 ) )
return - V_40 ;
if ( V_89 ) {
F_7 ( V_2 -> V_36 -> V_37 , L_23 ) ;
V_90 = F_30 ( V_2 -> V_38 -> V_44 -> V_45 ,
V_86 ) ;
if ( ! V_90 )
return - V_87 ;
for ( V_3 = 0 ; V_3 < V_85 ; V_3 ++ ) {
V_26 = F_11 ( V_2 , V_3 , V_90 ,
V_43 ) ;
if ( V_26 < 0 )
continue;
V_43 += V_26 ;
V_74 = F_24 ( V_90 , V_26 , V_86 ) ;
if ( ! V_74 ) {
V_26 = - V_87 ;
break;
}
V_2 -> V_50 [ V_3 ] . V_6 = V_74 ;
V_2 -> V_50 [ V_3 ] . V_5 = V_26 ;
#ifdef F_31
switch ( V_3 ) {
case V_58 :
V_2 -> V_91 . V_6 = V_74 ;
V_2 -> V_91 . V_82 = V_26 ;
break;
case V_62 :
V_2 -> V_92 . V_6 = V_74 ;
V_2 -> V_92 . V_82 = V_26 ;
break;
case V_93 :
V_2 -> V_94 . V_6 = V_74 ;
V_2 -> V_94 . V_82 = V_26 ;
break;
default:
if ( V_3 == V_2 -> V_38 -> V_59 ) {
V_2 -> V_95 . V_6 = V_74 ;
V_2 -> V_95 . V_82 = V_26 ;
break;
}
}
#endif
}
if ( ! V_43 )
F_5 ( V_2 , L_24 ) ;
F_32 ( V_90 ) ;
}
if ( V_2 -> V_81 ) {
V_26 = F_15 ( V_2 ) ;
if ( V_26 )
return V_26 ;
}
V_2 -> V_96 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_96 )
return - V_97 ;
return 0 ;
}
