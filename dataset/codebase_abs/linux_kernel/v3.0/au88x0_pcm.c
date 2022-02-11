static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( ( V_6 =
F_3 ( V_5 ,
V_7 ) ) < 0 )
return V_6 ;
if ( ( V_6 =
F_4 ( V_5 , 0 ,
V_8 ) ) < 0 )
return V_6 ;
F_5 ( V_5 , 0 ,
V_9 , 64 ) ;
if ( F_6 ( V_2 -> V_10 ) != V_11 ) {
#ifndef F_7
if ( F_6 ( V_2 -> V_10 ) == V_12 ) {
V_5 -> V_13 = V_14 ;
}
#endif
if ( F_6 ( V_2 -> V_10 ) == V_15 ) {
V_5 -> V_13 = V_16 ;
switch ( V_3 -> V_17 ) {
case 32000 :
V_5 -> V_13 . V_18 = V_19 ;
break;
case 44100 :
V_5 -> V_13 . V_18 = V_20 ;
break;
case 48000 :
V_5 -> V_13 . V_18 = V_21 ;
break;
}
}
if ( F_6 ( V_2 -> V_10 ) == V_22
|| F_6 ( V_2 -> V_10 ) == V_23 )
V_5 -> V_13 = V_24 ;
#ifdef F_8
if ( V_2 -> V_25 == V_26 &&
F_6 ( V_2 -> V_10 ) == V_22 ) {
V_5 -> V_13 . V_27 = 4 ;
F_9 ( V_5 , 0 ,
V_28 ,
& V_29 ) ;
}
#endif
V_2 -> V_5 -> V_30 = NULL ;
}
#ifndef F_10
else {
V_5 -> V_13 = V_31 ;
V_2 -> V_5 -> V_30 = NULL ;
}
#endif
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 -> V_30 ;
if ( V_25 != NULL ) {
V_25 -> V_2 = NULL ;
V_25 -> V_32 = 0 ;
}
V_2 -> V_5 -> V_30 = NULL ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
T_1 * V_35 = F_2 ( V_2 ) ;
T_2 * V_25 = ( T_2 * ) ( V_2 -> V_5 -> V_30 ) ;
int V_6 ;
V_6 =
F_13 ( V_2 , F_14 ( V_34 ) ) ;
if ( V_6 < 0 ) {
F_15 ( V_36 L_1 ) ;
return V_6 ;
}
F_16 ( & V_35 -> V_37 ) ;
if ( F_6 ( V_2 -> V_10 ) != V_11 ) {
int V_38 , type = F_6 ( V_2 -> V_10 ) ;
if ( V_25 != NULL )
F_17 ( V_35 , V_25 -> V_38 ,
V_25 -> V_32 , V_25 -> V_39 ,
V_25 -> type ) ;
V_38 =
F_17 ( V_35 , - 1 ,
F_18 ( V_34 ) ,
V_2 -> V_25 , type ) ;
if ( V_38 < 0 ) {
F_19 ( & V_35 -> V_37 ) ;
return V_38 ;
}
V_25 = V_2 -> V_5 -> V_30 = & V_35 -> V_40 [ V_38 ] ;
V_25 -> V_2 = V_2 ;
F_20 ( V_35 , V_38 ,
F_21 ( V_34 ) ,
F_22 ( V_34 ) ) ;
}
#ifndef F_10
else {
F_23 ( V_35 , V_2 -> V_41 ,
F_18 ( V_34 ) ) ;
V_25 = V_2 -> V_5 -> V_30 =
& V_35 -> V_42 [ V_2 -> V_41 ] ;
V_25 -> V_38 = V_2 -> V_41 ;
V_25 -> V_2 = V_2 ;
F_24 ( V_35 , V_2 -> V_41 ,
F_21 ( V_34 ) ,
F_22 ( V_34 ) ) ;
}
#endif
F_19 ( & V_35 -> V_37 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 * V_35 = F_2 ( V_2 ) ;
T_2 * V_25 = ( T_2 * ) ( V_2 -> V_5 -> V_30 ) ;
F_16 ( & V_35 -> V_37 ) ;
if ( F_6 ( V_2 -> V_10 ) != V_11 ) {
if ( V_25 != NULL )
F_17 ( V_35 , V_25 -> V_38 ,
V_25 -> V_32 , V_25 -> V_39 ,
V_25 -> type ) ;
}
#ifndef F_10
else {
if ( V_25 != NULL )
F_23 ( V_35 , V_25 -> V_38 , 0 ) ;
}
#endif
V_2 -> V_5 -> V_30 = NULL ;
F_19 ( & V_35 -> V_37 ) ;
return F_26 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 * V_35 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 -> V_30 ;
int V_38 = V_25 -> V_38 , V_43 , V_39 ;
if ( V_2 -> V_25 == V_26 )
V_39 = 1 ;
else
V_39 = 0 ;
V_43 = F_28 ( V_5 -> V_44 ) ;
F_16 ( & V_35 -> V_37 ) ;
if ( F_6 ( V_2 -> V_10 ) != V_11 ) {
F_29 ( V_35 , V_38 , 1 , V_39 , V_43 , 0 ,
0 ) ;
F_30 ( V_35 , V_38 , 0 ) ;
if ( F_6 ( V_2 -> V_10 ) != V_15 )
F_31 ( V_35 , V_38 , V_5 -> V_45 , V_39 ) ;
}
#ifndef F_10
else {
F_32 ( V_35 , V_38 , 1 , V_43 , 0 , 0 ) ;
F_33 ( V_35 , V_38 , 0 ) ;
}
#endif
F_19 ( & V_35 -> V_37 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_46 )
{
T_1 * V_35 = F_2 ( V_2 ) ;
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 -> V_30 ;
int V_38 = V_25 -> V_38 ;
F_35 ( & V_35 -> V_37 ) ;
switch ( V_46 ) {
case V_47 :
V_25 -> V_48 = 1 ;
if ( F_6 ( V_2 -> V_10 ) != V_11 ) {
F_36 ( V_35 , V_38 ) ;
F_37 ( V_35 , V_38 ) ;
}
#ifndef F_10
else {
F_15 ( V_49 L_2 , V_38 ) ;
F_38 ( V_35 , V_38 ) ;
}
#endif
break;
case V_50 :
V_25 -> V_48 = 0 ;
if ( F_6 ( V_2 -> V_10 ) != V_11 )
F_39 ( V_35 , V_38 ) ;
#ifndef F_10
else {
F_15 ( V_49 L_3 , V_38 ) ;
F_40 ( V_35 , V_38 ) ;
}
#endif
break;
case V_51 :
if ( F_6 ( V_2 -> V_10 ) != V_11 )
F_39 ( V_35 , V_38 ) ;
#ifndef F_10
else
F_41 ( V_35 , V_38 ) ;
#endif
break;
case V_52 :
if ( F_6 ( V_2 -> V_10 ) != V_11 )
F_42 ( V_35 , V_38 ) ;
#ifndef F_10
else
F_43 ( V_35 , V_38 ) ;
#endif
break;
default:
F_44 ( & V_35 -> V_37 ) ;
return - V_53 ;
}
F_44 ( & V_35 -> V_37 ) ;
return 0 ;
}
static T_3 F_45 ( struct V_1 * V_2 )
{
T_1 * V_35 = F_2 ( V_2 ) ;
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 -> V_30 ;
int V_38 = V_25 -> V_38 ;
T_3 V_54 = 0 ;
F_35 ( & V_35 -> V_37 ) ;
if ( F_6 ( V_2 -> V_10 ) != V_11 )
V_54 = F_46 ( V_35 , V_38 ) ;
#ifndef F_10
else
V_54 = F_47 ( V_35 , V_38 ) ;
#endif
F_44 ( & V_35 -> V_37 ) ;
return ( F_48 ( V_2 -> V_5 , V_54 ) ) ;
}
static int F_49 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
V_58 -> type = V_59 ;
V_58 -> V_60 = 1 ;
return 0 ;
}
static int F_50 ( struct V_55 * V_56 , struct V_61 * V_62 )
{
V_62 -> V_63 . V_64 . V_65 [ 0 ] = 0xff ;
V_62 -> V_63 . V_64 . V_65 [ 1 ] = 0xff ;
V_62 -> V_63 . V_64 . V_65 [ 2 ] = 0xff ;
V_62 -> V_63 . V_64 . V_65 [ 3 ] = V_66 ;
return 0 ;
}
static int F_51 ( struct V_55 * V_56 , struct V_61 * V_62 )
{
T_1 * V_3 = F_52 ( V_56 ) ;
V_62 -> V_63 . V_64 . V_65 [ 0 ] = 0x00 ;
V_62 -> V_63 . V_64 . V_65 [ 1 ] = V_67 | V_68 ;
V_62 -> V_63 . V_64 . V_65 [ 2 ] = 0x00 ;
switch ( V_3 -> V_17 ) {
case 32000 : V_62 -> V_63 . V_64 . V_65 [ 3 ] = V_69 ; break;
case 44100 : V_62 -> V_63 . V_64 . V_65 [ 3 ] = V_70 ; break;
case 48000 : V_62 -> V_63 . V_64 . V_65 [ 3 ] = V_71 ; break;
}
return 0 ;
}
static int F_53 ( struct V_55 * V_56 , struct V_61 * V_62 )
{
T_1 * V_3 = F_52 ( V_56 ) ;
int V_17 = 48000 ;
switch ( V_62 -> V_63 . V_64 . V_65 [ 3 ] & V_66 ) {
case V_69 : V_17 = 32000 ; break;
case V_70 : V_17 = 44100 ; break;
case V_71 : V_17 = 48000 ; break;
}
if ( V_17 == V_3 -> V_17 )
return 0 ;
V_3 -> V_17 = V_17 ;
F_54 ( V_3 , V_3 -> V_17 , 1 ) ;
return 1 ;
}
static int T_4 F_55 ( T_1 * V_35 , int V_72 , int V_73 )
{
struct V_74 * V_10 ;
struct V_55 * V_75 ;
int V_76 ;
int V_6 , V_77 ;
if ( ! V_35 || V_72 < 0 || V_72 >= V_78 )
return - V_79 ;
if ( V_72 == V_22 )
V_77 = V_73 ;
else
V_77 = 0 ;
V_6 = F_56 ( V_35 -> V_80 , V_81 [ V_72 ] , V_72 , V_73 ,
V_77 , & V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
snprintf ( V_10 -> V_82 , sizeof( V_10 -> V_82 ) ,
L_4 , V_83 , V_84 [ V_72 ] ) ;
V_35 -> V_10 [ V_72 ] = V_10 ;
F_6 ( V_10 ) = V_72 ;
V_10 -> V_30 = V_35 ;
F_57 ( V_10 , V_26 ,
& V_85 ) ;
if ( V_72 == V_22 )
F_57 ( V_10 , V_86 ,
& V_85 ) ;
F_58 ( V_10 , V_87 ,
F_59 ( V_35 -> V_88 ) ,
0x10000 , 0x10000 ) ;
if ( F_6 ( V_10 ) == V_15 ) {
for ( V_76 = 0 ; V_76 < F_60 ( V_89 ) ; V_76 ++ ) {
V_75 = F_61 ( & V_89 [ V_76 ] , V_35 ) ;
if ( ! V_75 )
return - V_90 ;
if ( ( V_6 = F_62 ( V_35 -> V_80 , V_75 ) ) < 0 )
return V_6 ;
}
}
return 0 ;
}
