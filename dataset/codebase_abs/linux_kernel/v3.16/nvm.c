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
T_2 * V_6 )
{
T_1 V_5 , V_4 = 0 ;
int V_26 ;
V_5 = V_42 ;
V_26 = V_5 ;
while ( V_26 == V_5 ) {
V_26 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_26 < 0 ) {
F_7 ( V_2 -> V_36 -> V_37 ,
L_5 ,
V_3 , V_4 , V_5 ) ;
return V_26 ;
}
V_4 += V_26 ;
}
F_7 ( V_2 -> V_36 -> V_37 ,
L_6 , V_3 ) ;
return V_4 ;
}
static struct V_43 *
F_12 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
const T_3 * V_47 , * V_48 , * V_49 , * V_50 , * V_51 ;
if ( V_2 -> V_36 -> V_38 -> V_52 != V_53 ) {
if ( ! V_2 -> V_46 [ V_54 ] . V_6 ||
! V_2 -> V_46 [ V_2 -> V_38 -> V_55 ] . V_6 ) {
F_5 ( V_2 , L_7 ) ;
return NULL ;
}
} else {
if ( ! V_2 -> V_46 [ V_54 ] . V_6 ||
! V_2 -> V_46 [ V_56 ] . V_6 ) {
F_5 ( V_2 ,
L_8 ) ;
return NULL ;
}
if ( ! V_2 -> V_46 [ V_2 -> V_38 -> V_55 ] . V_6 &&
! V_2 -> V_46 [ V_57 ] . V_6 ) {
F_5 ( V_2 ,
L_9 ) ;
return NULL ;
}
}
if ( F_13 ( ! V_2 -> V_38 ) )
return NULL ;
V_47 = ( const T_3 * ) V_45 [ V_2 -> V_38 -> V_55 ] . V_6 ;
V_48 = ( const T_3 * ) V_45 [ V_54 ] . V_6 ;
V_49 = ( const T_3 * ) V_45 [ V_58 ] . V_6 ;
V_50 = ( const T_3 * ) V_45 [ V_56 ] . V_6 ;
V_51 =
( const T_3 * ) V_45 [ V_57 ] . V_6 ;
return F_14 ( V_2 -> V_36 -> V_37 , V_2 -> V_38 , V_47 , V_48 , V_49 ,
V_50 , V_51 ,
V_2 -> V_59 -> V_60 ,
V_2 -> V_59 -> V_61 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_26 , V_62 ;
T_1 V_63 ;
const struct V_64 * V_65 ;
const struct {
T_3 V_66 ;
T_3 V_67 ;
T_2 V_6 [] ;
} * V_68 ;
const T_2 * V_69 , * V_70 ;
#define F_16 ( T_4 ) (8 * (x & 0x03FF))
#define F_17 ( T_4 ) (x >> 12)
#define F_18 ( T_4 ) (2 * ((x & 0xFF) << 8 | x >> 8))
#define F_19 ( T_4 ) (x >> 4)
F_7 ( V_2 -> V_36 -> V_37 , L_10 ) ;
V_26 = F_20 ( & V_65 , V_2 -> V_71 ,
V_2 -> V_36 -> V_37 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_11 ,
V_2 -> V_71 , V_26 ) ;
return V_26 ;
}
F_21 ( V_2 , L_12 ,
V_2 -> V_71 , V_65 -> V_72 ) ;
if ( V_65 -> V_72 < sizeof( * V_68 ) ) {
F_5 ( V_2 , L_13 ) ;
V_26 = - V_40 ;
goto V_73;
}
if ( V_65 -> V_72 > V_74 ) {
F_5 ( V_2 , L_14 ) ;
V_26 = - V_40 ;
goto V_73;
}
V_69 = V_65 -> V_6 + V_65 -> V_72 ;
V_68 = ( void * ) V_65 -> V_6 ;
while ( true ) {
if ( V_68 -> V_6 > V_69 ) {
F_5 ( V_2 ,
L_15 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_68 -> V_66 && ! V_68 -> V_67 ) {
V_26 = 0 ;
break;
}
if ( V_2 -> V_36 -> V_38 -> V_52 != V_53 ) {
V_62 =
2 * F_16 ( F_6 ( V_68 -> V_66 ) ) ;
V_63 = F_17 ( F_6 ( V_68 -> V_67 ) ) ;
} else {
V_62 = 2 * F_18 (
F_6 ( V_68 -> V_67 ) ) ;
V_63 = F_19 (
F_6 ( V_68 -> V_66 ) ) ;
}
if ( V_62 > V_75 ) {
F_5 ( V_2 , L_16 ,
V_62 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_62 ) {
F_5 ( V_2 , L_17 ) ;
V_26 = - V_40 ;
break;
}
if ( V_68 -> V_6 + V_62 > V_69 ) {
F_5 ( V_2 ,
L_18 ,
V_62 ) ;
V_26 = - V_40 ;
break;
}
if ( F_22 ( V_63 >= V_76 ,
L_19 , V_63 ) ) {
V_26 = - V_40 ;
break;
}
V_70 = F_23 ( V_68 -> V_6 , V_62 , V_77 ) ;
if ( ! V_70 ) {
V_26 = - V_78 ;
break;
}
V_2 -> V_46 [ V_63 ] . V_6 = V_70 ;
V_2 -> V_46 [ V_63 ] . V_5 = V_62 ;
V_68 = ( void * ) ( V_68 -> V_6 + V_62 ) ;
}
V_73:
F_24 ( V_65 ) ;
return V_26 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_79 , V_26 = 0 ;
struct V_44 * V_45 = V_2 -> V_46 ;
F_7 ( V_2 -> V_36 -> V_37 , L_20 ) ;
for ( V_79 = 0 ; V_79 < F_26 ( V_2 -> V_46 ) ; V_79 ++ ) {
if ( ! V_2 -> V_46 [ V_79 ] . V_6 || ! V_2 -> V_46 [ V_79 ] . V_5 )
continue;
V_26 = F_9 ( V_2 , V_79 , V_45 [ V_79 ] . V_6 ,
V_45 [ V_79 ] . V_5 ) ;
if ( V_26 < 0 ) {
F_5 ( V_2 , L_21 , V_26 ) ;
break;
}
}
return V_26 ;
}
int F_27 ( struct V_1 * V_2 , bool V_80 )
{
int V_26 , V_3 ;
T_2 * V_81 , * V_70 ;
if ( F_28 ( V_2 -> V_38 -> V_55 >= V_76 ) )
return - V_40 ;
if ( V_80 ) {
F_7 ( V_2 -> V_36 -> V_37 , L_22 ) ;
V_81 = F_29 ( V_2 -> V_38 -> V_82 -> V_83 ,
V_77 ) ;
if ( ! V_81 )
return - V_78 ;
for ( V_3 = 0 ; V_3 < V_76 ; V_3 ++ ) {
V_26 = F_11 ( V_2 , V_3 , V_81 ) ;
if ( V_26 < 0 )
continue;
V_70 = F_23 ( V_81 , V_26 , V_77 ) ;
if ( ! V_70 ) {
V_26 = - V_78 ;
break;
}
V_2 -> V_46 [ V_3 ] . V_6 = V_70 ;
V_2 -> V_46 [ V_3 ] . V_5 = V_26 ;
#ifdef F_30
switch ( V_3 ) {
case V_54 :
V_2 -> V_84 . V_6 = V_70 ;
V_2 -> V_84 . V_72 = V_26 ;
break;
case V_58 :
V_2 -> V_85 . V_6 = V_70 ;
V_2 -> V_85 . V_72 = V_26 ;
break;
case V_86 :
V_2 -> V_87 . V_6 = V_70 ;
V_2 -> V_87 . V_72 = V_26 ;
break;
default:
if ( V_3 == V_2 -> V_38 -> V_55 ) {
V_2 -> V_88 . V_6 = V_70 ;
V_2 -> V_88 . V_72 = V_26 ;
break;
}
}
#endif
}
F_31 ( V_81 ) ;
}
if ( V_2 -> V_71 ) {
V_26 = F_15 ( V_2 ) ;
if ( V_26 )
return V_26 ;
}
V_2 -> V_89 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_89 )
return - V_90 ;
return 0 ;
}
