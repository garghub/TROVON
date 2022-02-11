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
. V_16 = V_17 | V_18 ,
. V_6 = { & V_8 , V_6 } ,
. V_19 = { 0 , V_20 } ,
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
. V_9 = V_21 ,
} ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_16 = V_17 | V_26 | V_18 ,
. V_6 = { & V_8 , } ,
} ;
int V_27 , V_28 , V_29 ;
T_2 * V_30 ;
V_12 . V_15 [ 0 ] = sizeof( struct V_7 ) ;
V_27 = F_3 ( V_2 , & V_12 ) ;
if ( V_27 )
return V_27 ;
V_25 = V_12 . V_31 ;
if ( V_25 -> V_32 . V_16 & V_33 ) {
F_5 ( V_2 , L_1 ,
V_25 -> V_32 . V_16 ) ;
V_27 = - V_34 ;
goto exit;
}
V_23 = ( void * ) V_25 -> V_6 ;
V_27 = F_6 ( V_23 -> V_35 ) ;
V_28 = F_6 ( V_23 -> V_5 ) ;
V_29 = F_6 ( V_23 -> V_4 ) ;
V_30 = V_23 -> V_6 ;
if ( V_27 ) {
F_5 ( V_2 ,
L_2 ,
V_27 , V_2 -> V_36 -> V_37 ) ;
V_27 = - V_38 ;
goto exit;
}
if ( V_29 != V_4 ) {
F_5 ( V_2 , L_3 ,
V_29 ) ;
V_27 = - V_38 ;
goto exit;
}
memcpy ( V_6 + V_4 , V_30 , V_28 ) ;
V_27 = V_28 ;
exit:
F_7 ( & V_12 ) ;
return V_27 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
const T_2 * V_6 , T_1 V_5 )
{
int V_4 = 0 ;
while ( V_4 < V_5 ) {
int V_39 , V_27 ;
V_39 = F_9 ( V_40 ,
V_5 - V_4 ) ;
V_27 = F_1 ( V_2 , V_3 , V_4 ,
V_39 , V_6 + V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
V_4 += V_39 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_6 )
{
T_1 V_5 , V_4 = 0 ;
int V_27 ;
V_5 = V_40 ;
V_27 = V_5 ;
while ( V_27 == V_5 ) {
V_27 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_27 < 0 ) {
F_5 ( V_2 ,
L_4 ,
V_3 , V_4 , V_5 ) ;
return V_27 ;
}
V_4 += V_27 ;
}
F_11 ( V_2 -> V_41 -> V_42 ,
L_5 , V_3 ) ;
return V_4 ;
}
static struct V_43 *
F_12 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
const T_3 * V_47 , * V_48 , * V_49 , * V_50 , * V_51 ;
if ( V_2 -> V_41 -> V_36 -> V_52 != V_53 ) {
if ( ! V_2 -> V_46 [ V_54 ] . V_6 ||
! V_2 -> V_46 [ V_2 -> V_36 -> V_55 ] . V_6 ) {
F_5 ( V_2 , L_6 ) ;
return NULL ;
}
} else {
if ( ! V_2 -> V_46 [ V_54 ] . V_6 ||
! V_2 -> V_46 [ V_56 ] . V_6 ||
! V_2 -> V_46 [ V_57 ] . V_6 ) {
F_5 ( V_2 ,
L_7 ) ;
return NULL ;
}
}
if ( F_13 ( ! V_2 -> V_36 ) )
return NULL ;
V_47 = ( const T_3 * ) V_45 [ V_2 -> V_36 -> V_55 ] . V_6 ;
V_48 = ( const T_3 * ) V_45 [ V_54 ] . V_6 ;
V_49 = ( const T_3 * ) V_45 [ V_58 ] . V_6 ;
V_50 = ( const T_3 * ) V_45 [ V_57 ] . V_6 ;
V_51 =
( const T_3 * ) V_45 [ V_56 ] . V_6 ;
return F_14 ( V_2 -> V_41 -> V_42 , V_2 -> V_36 , V_47 , V_48 , V_49 ,
V_50 , V_51 ,
V_2 -> V_59 -> V_60 ,
V_2 -> V_59 -> V_61 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_27 , V_62 ;
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
F_11 ( V_2 -> V_41 -> V_42 , L_8 ) ;
V_27 = F_20 ( & V_65 , V_71 . V_72 ,
V_2 -> V_41 -> V_42 ) ;
if ( V_27 ) {
F_5 ( V_2 , L_9 ,
V_71 . V_72 , V_27 ) ;
return V_27 ;
}
F_21 ( V_2 , L_10 ,
V_71 . V_72 , V_65 -> V_73 ) ;
if ( V_65 -> V_73 < sizeof( * V_68 ) ) {
F_5 ( V_2 , L_11 ) ;
V_27 = - V_38 ;
goto V_74;
}
if ( V_65 -> V_73 > V_75 ) {
F_5 ( V_2 , L_12 ) ;
V_27 = - V_38 ;
goto V_74;
}
V_69 = V_65 -> V_6 + V_65 -> V_73 ;
V_68 = ( void * ) V_65 -> V_6 ;
while ( true ) {
if ( V_68 -> V_6 > V_69 ) {
F_5 ( V_2 ,
L_13 ) ;
V_27 = - V_38 ;
break;
}
if ( ! V_68 -> V_66 && ! V_68 -> V_67 ) {
V_27 = 0 ;
break;
}
if ( V_2 -> V_41 -> V_36 -> V_52 != V_53 ) {
V_62 =
2 * F_16 ( F_6 ( V_68 -> V_66 ) ) ;
V_63 = F_17 ( F_6 ( V_68 -> V_67 ) ) ;
} else {
V_62 = 2 * F_18 (
F_6 ( V_68 -> V_67 ) ) ;
V_63 = F_19 (
F_6 ( V_68 -> V_66 ) ) ;
}
if ( V_62 > V_76 ) {
F_5 ( V_2 , L_14 ,
V_62 ) ;
V_27 = - V_38 ;
break;
}
if ( ! V_62 ) {
F_5 ( V_2 , L_15 ) ;
V_27 = - V_38 ;
break;
}
if ( V_68 -> V_6 + V_62 > V_69 ) {
F_5 ( V_2 ,
L_16 ,
V_62 ) ;
V_27 = - V_38 ;
break;
}
if ( F_22 ( V_63 >= V_77 ,
L_17 , V_63 ) ) {
V_27 = - V_38 ;
break;
}
V_70 = F_23 ( V_68 -> V_6 , V_62 , V_78 ) ;
if ( ! V_70 ) {
V_27 = - V_79 ;
break;
}
V_2 -> V_46 [ V_63 ] . V_6 = V_70 ;
V_2 -> V_46 [ V_63 ] . V_5 = V_62 ;
V_68 = ( void * ) ( V_68 -> V_6 + V_62 ) ;
}
V_74:
F_24 ( V_65 ) ;
return V_27 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_80 , V_27 = 0 ;
struct V_44 * V_45 = V_2 -> V_46 ;
F_11 ( V_2 -> V_41 -> V_42 , L_18 ) ;
for ( V_80 = 0 ; V_80 < F_26 ( V_2 -> V_46 ) ; V_80 ++ ) {
if ( ! V_2 -> V_46 [ V_80 ] . V_6 || ! V_2 -> V_46 [ V_80 ] . V_5 )
continue;
V_27 = F_8 ( V_2 , V_80 , V_45 [ V_80 ] . V_6 ,
V_45 [ V_80 ] . V_5 ) ;
if ( V_27 < 0 ) {
F_5 ( V_2 , L_19 , V_27 ) ;
break;
}
}
return V_27 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_27 , V_80 , V_3 ;
T_2 * V_81 , * V_70 ;
int V_82 [ V_77 ] ;
int V_83 ;
if ( F_28 ( V_2 -> V_36 -> V_55 >= V_77 ) )
return - V_38 ;
if ( V_71 . V_72 ) {
V_27 = F_15 ( V_2 ) ;
if ( V_27 )
return V_27 ;
} else {
if ( V_2 -> V_41 -> V_36 -> V_52 != V_53 ) {
V_82 [ 0 ] = V_2 -> V_36 -> V_55 ;
V_82 [ 1 ] = V_54 ;
V_82 [ 2 ] = V_58 ;
V_82 [ 3 ] = V_84 ;
V_83 = 4 ;
} else {
V_82 [ 0 ] = V_54 ;
V_82 [ 1 ] = V_58 ;
V_82 [ 2 ] = V_84 ;
V_82 [ 3 ] = V_57 ;
V_82 [ 4 ] = V_56 ;
V_83 = 5 ;
}
F_11 ( V_2 -> V_41 -> V_42 , L_20 ) ;
V_81 = F_29 ( V_2 -> V_36 -> V_85 -> V_86 ,
V_78 ) ;
if ( ! V_81 )
return - V_79 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ ) {
V_3 = V_82 [ V_80 ] ;
V_27 = F_10 ( V_2 , V_3 , V_81 ) ;
if ( V_27 < 0 )
break;
V_70 = F_23 ( V_81 , V_27 , V_78 ) ;
if ( ! V_70 ) {
V_27 = - V_79 ;
break;
}
V_2 -> V_46 [ V_3 ] . V_6 = V_70 ;
V_2 -> V_46 [ V_3 ] . V_5 = V_27 ;
#ifdef F_30
switch ( V_3 ) {
case V_54 :
V_2 -> V_87 . V_6 = V_70 ;
V_2 -> V_87 . V_73 = V_27 ;
break;
case V_58 :
V_2 -> V_88 . V_6 = V_70 ;
V_2 -> V_88 . V_73 = V_27 ;
break;
case V_84 :
V_2 -> V_89 . V_6 = V_70 ;
V_2 -> V_89 . V_73 = V_27 ;
break;
default:
if ( V_3 == V_2 -> V_36 -> V_55 ) {
V_2 -> V_90 . V_6 = V_70 ;
V_2 -> V_90 . V_73 = V_27 ;
break;
}
F_22 ( 1 , L_21 , V_3 ) ;
}
#endif
}
F_31 ( V_81 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_2 -> V_91 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_91 )
return - V_92 ;
return 0 ;
}
