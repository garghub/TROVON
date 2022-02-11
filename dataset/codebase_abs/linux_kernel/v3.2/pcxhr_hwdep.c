static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
int V_6 ;
if ( V_2 -> V_7 )
V_6 = V_2 -> V_8 * 2 ;
else
V_6 = V_2 -> V_8 ;
V_6 += V_2 -> V_9 * V_10 ;
F_2 ( V_2 ) ;
F_3 ( & V_5 , V_11 ) ;
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_5 . V_12 [ 0 ] & V_13 ) != V_2 -> V_9 * 2 )
return - V_14 ;
if ( ( ( V_5 . V_12 [ 0 ] >> ( 2 * V_15 ) ) & V_13 ) <
V_2 -> V_8 * 2 )
return - V_14 ;
if ( ( V_5 . V_12 [ 1 ] & 0x5F ) < V_6 )
return - V_14 ;
if ( ( ( V_5 . V_12 [ 1 ] >> 7 ) & 0x5F ) < V_10 )
return - V_14 ;
F_5 ( L_1 ,
V_5 . V_12 [ 2 ] , V_5 . V_12 [ 3 ] ) ;
F_3 ( & V_5 , V_16 ) ;
V_5 . V_17 [ 0 ] |= V_2 -> V_18 ;
V_5 . V_17 [ 1 ] = ( 1 << 23 ) + V_2 -> V_19 ;
V_5 . V_20 = 2 ;
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
F_5 ( L_2 , ( V_5 . V_12 [ 0 ] >> 16 ) & 0xff ,
( V_5 . V_12 [ 0 ] >> 8 ) & 0xff , V_5 . V_12 [ 0 ] & 0xff ) ;
V_2 -> V_21 = V_5 . V_12 [ 0 ] ;
if ( V_2 -> V_22 )
V_3 = F_6 ( V_2 ) ;
else
V_3 = F_7 ( V_2 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
F_3 ( & V_5 , V_23 ) ;
V_5 . V_17 [ 0 ] |= V_24 ;
V_5 . V_17 [ 1 ] = V_25 ;
V_5 . V_20 = 2 ;
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_5 . V_12 [ 1 ] & V_26 ) ==
V_27 )
V_2 -> V_28 = 1 ;
V_3 = F_8 ( V_2 , V_29 ,
V_29 , NULL ) ;
if ( V_3 )
return V_3 ;
F_3 ( & V_5 , V_23 ) ;
V_5 . V_17 [ 0 ] |= V_30 ;
if ( F_9 ( V_2 ) ) {
V_5 . V_17 [ 1 ] = 1 ;
V_5 . V_20 = 2 ;
}
V_3 = F_4 ( V_2 , & V_5 ) ;
return V_3 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
if ( V_2 -> V_31 & ( 1 << V_32 ) ) {
if ( ! V_2 -> V_22 ) {
F_3 ( & V_5 , V_33 ) ;
V_5 . V_17 [ 0 ] |= V_30 ;
F_4 ( V_2 , & V_5 ) ;
F_8 ( V_2 , V_29 ,
0 , NULL ) ;
}
}
if ( V_2 -> V_31 & ( 1 << V_34 ) )
F_11 ( V_2 ) ;
if ( V_2 -> V_31 & ( 1 << V_35 ) ) {
F_12 ( V_2 ) ;
V_2 -> V_31 = 1 ;
}
return;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
int V_38 , int V_39 )
{
int V_40 , V_41 ;
int V_3 ;
struct V_4 V_5 ;
if ( V_38 ) {
V_40 = 1 ;
if ( V_2 -> V_7 )
V_41 = 1 ;
else
V_41 = 2 ;
} else {
V_40 = V_10 ;
V_41 = 2 ;
}
F_5 ( L_3 ,
V_39 , V_38 ? 'c' : 'p' ) ;
V_37 -> V_38 = V_38 ;
V_37 -> V_42 = V_39 ;
F_3 ( & V_5 , V_43 ) ;
F_14 ( & V_5 , V_38 , V_39 ,
V_41 , V_40 ) ;
V_5 . V_17 [ 1 ] |= 0x020000 ;
if ( F_9 ( V_2 ) ) {
V_5 . V_17 [ V_5 . V_20 ++ ] = ( V_41 == 1 ) ? 0x01 : 0x03 ;
}
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 < 0 ) {
F_15 ( V_44 L_4
L_5 , V_3 ) ;
return V_3 ;
}
V_37 -> V_45 = V_46 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 , V_47 , V_48 ;
struct V_49 * V_50 ;
struct V_36 * V_37 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_51 ; V_47 ++ ) {
V_50 = V_2 -> V_50 [ V_47 ] ;
if ( V_50 -> V_52 ) {
V_37 = & V_50 -> V_53 ;
V_3 = F_13 ( V_2 , V_37 , 0 , V_47 * 2 ) ;
if ( V_3 )
return V_3 ;
for( V_48 = 0 ; V_48 < V_50 -> V_52 ; V_48 ++ )
V_50 -> V_54 [ V_48 ] . V_37 = V_37 ;
}
for ( V_48 = 0 ; V_48 < V_50 -> V_55 ; V_48 ++ ) {
V_37 = & V_50 -> V_56 [ V_48 ] ;
V_3 = F_13 ( V_2 , V_37 , 1 , V_47 * 2 + V_48 ) ;
if ( V_3 )
return V_3 ;
V_50 -> V_57 [ V_48 ] . V_37 = V_37 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_47 , V_48 ;
struct V_49 * V_50 ;
int V_58 = 0 ;
int V_59 = 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_51 ; V_47 ++ ) {
V_50 = V_2 -> V_50 [ V_47 ] ;
if ( V_50 -> V_52 )
V_58 |= 1 << V_50 -> V_53 . V_42 ;
for ( V_48 = 0 ; V_48 < V_50 -> V_55 ; V_48 ++ )
V_59 |= 1 << V_50 -> V_56 [ V_48 ] . V_42 ;
}
return F_18 ( V_2 , V_58 , V_59 , 1 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_60 ,
const struct V_61 * V_62 )
{
int V_3 , V_63 ;
F_5 ( L_6 , V_60 , V_62 -> V_64 ) ;
switch ( V_60 ) {
case V_65 :
F_12 ( V_2 ) ;
return F_20 ( V_2 , V_62 , 0 ) ;
case V_35 :
F_12 ( V_2 ) ;
return F_20 ( V_2 , V_62 , 1 ) ;
case V_34 :
F_11 ( V_2 ) ;
return F_21 ( V_2 , V_62 ) ;
case V_66 :
return F_22 ( V_2 , V_62 ) ;
case V_32 :
V_3 = F_23 ( V_2 , V_62 ) ;
if ( V_3 )
return V_3 ;
break;
default:
F_15 ( V_44 L_7 ) ;
return - V_67 ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( V_44 L_8 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( V_44 L_9 ) ;
return V_3 ;
}
for ( V_63 = 0 ; V_63 < V_2 -> V_51 ; V_63 ++ ) {
struct V_49 * V_50 = V_2 -> V_50 [ V_63 ] ;
if ( ( V_3 = F_24 ( V_50 ) ) < 0 )
return V_3 ;
if ( V_63 == 0 ) {
if ( ( V_3 = F_25 ( V_50 -> V_2 ) ) < 0 )
return V_3 ;
}
if ( ( V_3 = F_26 ( V_50 -> V_68 ) ) < 0 )
return V_3 ;
}
V_3 = F_17 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( V_44 L_10 ) ;
return V_3 ;
}
F_5 ( L_11 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
static char * V_69 [] [ 5 ] = {
[ 0 ] = { L_12 , L_13 ,
L_14 , L_15 , L_16 } ,
[ 1 ] = { L_12 , L_17 ,
L_14 , L_18 , L_16 } ,
[ 2 ] = { L_12 , L_19 ,
L_14 , L_20 , L_21 } ,
[ 3 ] = { L_12 , L_22 ,
L_14 , L_23 , L_21 } ,
[ 4 ] = { NULL , L_24 ,
L_25 , L_26 , L_27 } ,
[ 5 ] = { NULL , L_28 ,
L_25 , L_26 , L_27 } ,
} ;
char V_70 [ 32 ] ;
const struct V_61 * V_71 ;
int V_47 , V_3 ;
int V_72 = V_2 -> V_73 ;
for ( V_47 = 0 ; V_47 < 5 ; V_47 ++ ) {
if ( ! V_69 [ V_72 ] [ V_47 ] )
continue;
sprintf ( V_70 , L_29 , V_69 [ V_72 ] [ V_47 ] ) ;
if ( F_28 ( & V_71 , V_70 , & V_2 -> V_74 -> V_75 ) ) {
F_15 ( V_44 L_30 ,
V_70 ) ;
return - V_76 ;
}
V_3 = F_19 ( V_2 , V_47 , V_71 ) ;
F_29 ( V_71 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_31 |= 1 << V_47 ;
}
return 0 ;
}
static int F_30 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
sprintf ( V_80 -> V_82 , L_31 , V_2 -> V_73 ) ;
V_80 -> V_83 = V_84 ;
if ( V_78 -> V_31 & ( 1 << V_32 ) )
V_80 -> V_85 = 1 ;
V_80 -> V_86 = V_87 ;
return 0 ;
}
static int F_31 ( struct V_77 * V_78 ,
struct V_88 * V_62 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
int V_3 ;
struct V_61 V_89 ;
V_89 . V_64 = V_62 -> V_90 ;
V_89 . V_91 = F_32 ( V_89 . V_64 ) ;
if ( ! V_89 . V_91 ) {
F_15 ( V_44 L_32
L_33 , ( unsigned long ) V_89 . V_64 ) ;
return - V_92 ;
}
if ( F_33 ( ( void * ) V_89 . V_91 , V_62 -> V_93 , V_62 -> V_90 ) ) {
F_34 ( V_89 . V_91 ) ;
return - V_67 ;
}
V_3 = F_19 ( V_2 , V_62 -> V_60 , & V_89 ) ;
F_34 ( V_89 . V_91 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_31 |= 1 << V_62 -> V_60 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_77 * V_78 ;
V_3 = F_35 ( V_2 -> V_50 [ 0 ] -> V_68 , V_94 , 0 , & V_78 ) ;
if ( V_3 < 0 )
return V_3 ;
V_78 -> V_95 = V_96 ;
V_78 -> V_81 = V_2 ;
V_78 -> V_97 . V_98 = F_30 ;
V_78 -> V_97 . V_99 = F_31 ;
V_78 -> V_100 = 1 ;
V_78 -> V_31 = V_2 -> V_22 ? 1 : 0 ;
V_2 -> V_31 = 0 ;
sprintf ( V_78 -> V_101 , V_94 ) ;
V_3 = F_26 ( V_2 -> V_50 [ 0 ] -> V_68 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
