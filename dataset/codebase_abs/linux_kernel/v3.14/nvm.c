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
const T_3 * V_47 , * V_48 , * V_49 ;
if ( ! V_2 -> V_46 [ V_50 ] . V_6 ||
! V_2 -> V_46 [ V_51 ] . V_6 ) {
F_5 ( V_2 , L_6 ) ;
return NULL ;
}
if ( F_13 ( ! V_2 -> V_36 ) )
return NULL ;
V_47 = ( const T_3 * ) V_45 [ V_51 ] . V_6 ;
V_48 = ( const T_3 * ) V_45 [ V_50 ] . V_6 ;
V_49 = ( const T_3 * ) V_45 [ V_52 ] . V_6 ;
return F_14 ( V_2 -> V_41 -> V_42 , V_2 -> V_36 , V_47 , V_48 , V_49 ,
F_15 ( V_2 -> V_53 ) ,
F_16 ( V_2 -> V_53 ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_27 , V_54 ;
T_1 V_55 ;
const struct V_56 * V_57 ;
const struct {
T_3 V_58 ;
T_3 V_59 ;
T_2 V_6 [] ;
} * V_60 ;
const T_2 * V_61 , * V_62 ;
#define F_18 ( T_4 ) (8 * (x & 0x03FF))
#define F_19 ( T_4 ) (x >> 12)
F_11 ( V_2 -> V_41 -> V_42 , L_7 ) ;
V_27 = F_20 ( & V_57 , V_63 . V_64 ,
V_2 -> V_41 -> V_42 ) ;
if ( V_27 ) {
F_5 ( V_2 , L_8 ,
V_63 . V_64 , V_27 ) ;
return V_27 ;
}
F_21 ( V_2 , L_9 ,
V_63 . V_64 , V_57 -> V_65 ) ;
if ( V_57 -> V_65 < sizeof( * V_60 ) ) {
F_5 ( V_2 , L_10 ) ;
V_27 = - V_38 ;
goto V_66;
}
if ( V_57 -> V_65 > V_67 ) {
F_5 ( V_2 , L_11 ) ;
V_27 = - V_38 ;
goto V_66;
}
V_61 = V_57 -> V_6 + V_57 -> V_65 ;
V_60 = ( void * ) V_57 -> V_6 ;
while ( true ) {
if ( V_60 -> V_6 > V_61 ) {
F_5 ( V_2 ,
L_12 ) ;
V_27 = - V_38 ;
break;
}
if ( ! V_60 -> V_58 && ! V_60 -> V_59 ) {
V_27 = 0 ;
break;
}
V_54 = 2 * F_18 ( F_6 ( V_60 -> V_58 ) ) ;
V_55 = F_19 ( F_6 ( V_60 -> V_59 ) ) ;
if ( V_54 > V_68 ) {
F_5 ( V_2 , L_13 ,
V_54 ) ;
V_27 = - V_38 ;
break;
}
if ( ! V_54 ) {
F_5 ( V_2 , L_14 ) ;
V_27 = - V_38 ;
break;
}
if ( V_60 -> V_6 + V_54 > V_61 ) {
F_5 ( V_2 ,
L_15 ,
V_54 ) ;
V_27 = - V_38 ;
break;
}
if ( F_22 ( V_55 >= V_69 ,
L_16 , V_55 ) ) {
V_27 = - V_38 ;
break;
}
V_62 = F_23 ( V_60 -> V_6 , V_54 , V_70 ) ;
if ( ! V_62 ) {
V_27 = - V_71 ;
break;
}
V_2 -> V_46 [ V_55 ] . V_6 = V_62 ;
V_2 -> V_46 [ V_55 ] . V_5 = V_54 ;
V_60 = ( void * ) ( V_60 -> V_6 + V_54 ) ;
}
V_66:
F_24 ( V_57 ) ;
return V_27 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_72 , V_27 = 0 ;
struct V_44 * V_45 = V_2 -> V_46 ;
F_11 ( V_2 -> V_41 -> V_42 , L_17 ) ;
for ( V_72 = 0 ; V_72 < F_26 ( V_2 -> V_46 ) ; V_72 ++ ) {
if ( ! V_2 -> V_46 [ V_72 ] . V_6 || ! V_2 -> V_46 [ V_72 ] . V_5 )
continue;
V_27 = F_8 ( V_2 , V_72 , V_45 [ V_72 ] . V_6 ,
V_45 [ V_72 ] . V_5 ) ;
if ( V_27 < 0 ) {
F_5 ( V_2 , L_18 , V_27 ) ;
break;
}
}
return V_27 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_27 , V_72 , V_3 ;
T_2 * V_73 , * V_62 ;
if ( V_63 . V_64 ) {
V_27 = F_17 ( V_2 ) ;
if ( V_27 )
return V_27 ;
} else {
F_11 ( V_2 -> V_41 -> V_42 , L_19 ) ;
V_73 = F_28 ( V_2 -> V_36 -> V_74 -> V_75 ,
V_70 ) ;
if ( ! V_73 )
return - V_71 ;
for ( V_72 = 0 ; V_72 < F_26 ( V_76 ) ; V_72 ++ ) {
V_3 = V_76 [ V_72 ] ;
V_27 = F_10 ( V_2 , V_3 , V_73 ) ;
if ( V_27 < 0 )
break;
V_62 = F_23 ( V_73 , V_27 , V_70 ) ;
if ( ! V_62 ) {
V_27 = - V_71 ;
break;
}
V_2 -> V_46 [ V_3 ] . V_6 = V_62 ;
V_2 -> V_46 [ V_3 ] . V_5 = V_27 ;
#ifdef F_29
switch ( V_3 ) {
case V_51 :
V_2 -> V_77 . V_6 = V_62 ;
V_2 -> V_77 . V_65 = V_27 ;
break;
case V_50 :
V_2 -> V_78 . V_6 = V_62 ;
V_2 -> V_78 . V_65 = V_27 ;
break;
case V_52 :
V_2 -> V_79 . V_6 = V_62 ;
V_2 -> V_79 . V_65 = V_27 ;
break;
case V_80 :
V_2 -> V_81 . V_6 = V_62 ;
V_2 -> V_81 . V_65 = V_27 ;
break;
default:
F_22 ( 1 , L_20 , V_3 ) ;
}
#endif
}
F_30 ( V_73 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_2 -> V_82 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_82 )
return - V_83 ;
return 0 ;
}
