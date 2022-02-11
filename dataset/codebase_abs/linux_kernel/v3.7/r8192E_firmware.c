void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
V_6 -> V_8 = F_3 (
V_9 ) ;
}
static bool F_4 ( struct V_1 * V_2 , T_1 * V_10 ,
T_2 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_12 = true ;
T_3 V_13 ;
T_3 V_14 , V_15 = 0 ;
int V_16 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_17 * V_18 ;
unsigned char * V_19 ;
struct V_20 * V_21 ;
T_1 V_22 ;
F_1 ( V_2 ) ;
V_13 = V_6 -> V_8 ;
do {
if ( ( V_11 - V_15 ) > V_13 ) {
V_14 = V_13 ;
V_22 = 0 ;
} else {
V_14 = V_11 - V_15 ;
V_22 = 1 ;
}
V_18 = F_5 ( V_14 + 4 ) ;
memcpy ( ( unsigned char * ) ( V_18 -> V_23 ) , & V_2 , sizeof( V_2 ) ) ;
V_21 = (struct V_20 * ) ( V_18 -> V_23 + V_24 ) ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = V_28 ;
V_21 -> V_22 = V_22 ;
V_19 = V_18 -> V_29 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 += 4 ) {
* V_19 ++ = ( ( V_16 + 0 ) < V_14 ) ?
V_10 [ V_16 + 3 ] : 0 ;
* V_19 ++ = ( ( V_16 + 1 ) < V_14 ) ?
V_10 [ V_16 + 2 ] : 0 ;
* V_19 ++ = ( ( V_16 + 2 ) < V_14 ) ?
V_10 [ V_16 + 1 ] : 0 ;
* V_19 ++ = ( ( V_16 + 3 ) < V_14 ) ?
V_10 [ V_16 + 0 ] : 0 ;
}
V_21 -> V_30 = ( T_3 ) V_16 ;
F_6 ( V_18 , V_16 ) ;
if ( ! V_4 -> V_31 -> V_32 ( V_2 , V_21 -> V_25 ) ||
( ! F_7 ( & V_4 -> V_31 -> V_33 [ V_21 -> V_25 ] ) ) ||
( V_4 -> V_31 -> V_34 ) ) {
F_8 ( V_35 , L_1
L_2 ) ;
F_9 ( & V_4 -> V_31 -> V_33
[ V_21 -> V_25 ] , V_18 ) ;
} else {
V_4 -> V_31 -> V_36 ( V_18 , V_2 ) ;
}
V_10 += V_14 ;
V_15 += V_14 ;
} while ( V_15 < V_11 );
F_10 ( V_2 , V_37 , V_38 ) ;
return V_12 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
bool V_12 = true ;
T_2 V_39 = 0 ;
unsigned long V_40 ;
V_40 = V_41 + F_12 ( 200 ) ;
while ( F_13 ( V_41 , V_40 ) ) {
V_39 = F_14 ( V_2 , V_42 ) ;
if ( V_39 & V_43 )
break;
F_15 ( 2 ) ;
}
if ( ! ( V_39 & V_43 ) ) {
F_8 ( V_44 , L_3 ) ;
goto V_45;
} else {
F_8 ( V_35 , L_4 ) ;
}
V_39 = F_14 ( V_2 , V_42 ) ;
F_10 ( V_2 , V_42 ,
( T_1 ) ( ( V_39 | V_46 ) & 0xff ) ) ;
F_15 ( 1 ) ;
V_40 = V_41 + F_12 ( 200 ) ;
while ( F_13 ( V_41 , V_40 ) ) {
V_39 = F_14 ( V_2 , V_42 ) ;
if ( V_39 & V_47 )
break;
F_15 ( 2 ) ;
}
if ( ! ( V_39 & V_47 ) )
goto V_45;
else
F_8 ( V_35 , L_5 ) ;
return V_12 ;
V_45:
F_8 ( V_44 , L_6 , V_48 ) ;
V_12 = false ;
return V_12 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
bool V_12 = true ;
T_2 V_39 = 0 ;
unsigned long V_40 ;
V_40 = V_41 + F_12 ( 20 ) ;
while ( F_13 ( V_41 , V_40 ) ) {
V_39 = F_14 ( V_2 , V_42 ) ;
if ( V_39 & V_49 )
break;
F_15 ( 2 ) ;
}
if ( ! ( V_39 & V_49 ) )
goto V_50;
else
F_8 ( V_35 , L_7 ) ;
return V_12 ;
V_50:
F_8 ( V_44 , L_6 , V_48 ) ;
V_12 = false ;
return V_12 ;
}
static bool F_17 ( struct V_1 * V_2 ,
T_1 V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
bool V_12 = true ;
switch ( V_51 ) {
case V_52 :
V_6 -> V_53 = V_54 ;
break;
case V_55 :
V_6 -> V_53 = V_56 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 )
V_6 -> V_53 = V_57 ;
else
F_8 ( V_35 , L_8
L_9 ) ;
break;
case V_58 :
V_6 -> V_53 = V_59 ;
F_15 ( 1 ) ;
V_12 = F_16 ( V_2 ) ;
if ( V_12 )
V_6 -> V_53 = V_60 ;
else
F_8 ( V_35 , L_10
L_11 , V_12 ) ;
break;
default:
V_12 = false ;
F_8 ( V_35 , L_12 ) ;
break;
}
return V_12 ;
}
bool F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_12 = true ;
T_1 * V_61 [ 3 ] = { & V_62 [ 0 ] ,
& V_63 [ 0 ] ,
& V_64 [ 0 ] } ;
T_2 V_65 [ 3 ] = { sizeof( V_62 ) ,
sizeof( V_63 ) ,
sizeof( V_64 ) } ;
T_2 V_66 = 0 ;
T_1 * V_67 = NULL ;
T_1 V_68 = 0 ;
enum V_69 V_70 = V_71 ;
enum V_72 V_73 = V_52 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_8 ( V_35 , L_13 ) ;
if ( V_6 -> V_53 == V_74 ) {
V_70 = V_71 ;
V_73 = V_52 ;
} else if ( V_6 -> V_53 == V_60 ) {
V_70 = V_75 ;
V_73 = V_58 ;
} else {
F_8 ( V_35 , L_14
L_15 ) ;
}
V_4 -> V_76 = V_77 ;
for ( V_68 = V_73 ; V_68 <= V_58 ;
V_68 ++ ) {
if ( V_70 == V_71 ) {
switch ( V_4 -> V_76 ) {
case V_77 :
{
if ( V_6 -> V_78 [ V_68 ] == 0 ) {
const char * V_79 [ 3 ] = {
V_80 ,
V_81 ,
V_82
} ;
const struct V_83 * V_84 ;
int V_85 ;
V_85 = F_19 ( & V_84 ,
V_79 [ V_68 ] , & V_4 -> V_86 -> V_2 ) ;
if ( V_85 < 0 ) {
F_8 ( V_35 , L_16
L_17 ) ;
goto V_87;
}
if ( V_84 -> V_88 >
sizeof( V_6 -> V_89 [ V_68 ] ) ) {
F_8 ( V_35 , L_18
L_19
L_20 ) ;
goto V_87;
}
if ( V_68 != V_55 ) {
memcpy ( V_6 -> V_89 [ V_68 ] ,
V_84 -> V_29 , V_84 -> V_88 ) ;
V_6 -> V_78 [ V_68 ] =
V_84 -> V_88 ;
} else {
memset ( V_6 -> V_89 [ V_68 ] ,
0 , 128 ) ;
memcpy ( & V_6 -> V_89 [ V_68 ] [ 128 ] ,
V_84 -> V_29 , V_84 -> V_88 ) ;
V_6 -> V_78 [ V_68 ] =
V_84 -> V_88 + 128 ;
}
if ( V_70 == V_71 )
F_20 ( V_84 ) ;
}
V_67 = V_6 -> V_89 [ V_68 ] ;
V_66 = V_6 -> V_78 [ V_68 ] ;
break;
}
case V_90 :
V_67 = V_61 [ V_68 ] ;
V_66 = V_65 [ V_68 ] ;
if ( V_68 == V_58 ) {
memcpy ( V_6 -> V_89 [ V_68 ] , V_67 , V_66 ) ;
V_6 -> V_78 [ V_68 ] = V_66 ;
}
break;
default:
break;
}
} else if ( V_70 == V_75 ) {
V_67 = V_6 -> V_89 [ V_68 ] ;
V_66 = V_6 -> V_78 [ V_68 ] ;
}
V_12 = F_4 ( V_2 , V_67 , V_66 ) ;
if ( V_12 != true ) {
goto V_87;
}
if ( ! F_17 ( V_2 , V_68 ) ) {
goto V_87;
}
}
F_8 ( V_35 , L_21 ) ;
return V_12 ;
V_87:
F_8 ( V_44 , L_6 , V_48 ) ;
V_12 = false ;
return V_12 ;
}
