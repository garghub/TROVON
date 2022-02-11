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
T_3 V_12 ;
T_3 V_13 , V_14 = 0 ;
int V_15 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_16 * V_17 ;
unsigned char * V_18 ;
struct V_19 * V_20 ;
T_1 V_21 ;
F_1 ( V_2 ) ;
V_12 = V_6 -> V_8 ;
do {
if ( ( V_11 - V_14 ) > V_12 ) {
V_13 = V_12 ;
V_21 = 0 ;
} else {
V_13 = V_11 - V_14 ;
V_21 = 1 ;
}
V_17 = F_5 ( V_13 + 4 ) ;
memcpy ( ( unsigned char * ) ( V_17 -> V_22 ) , & V_2 , sizeof( V_2 ) ) ;
V_20 = (struct V_19 * ) ( V_17 -> V_22 + V_23 ) ;
V_20 -> V_24 = V_25 ;
V_20 -> V_26 = V_27 ;
V_20 -> V_21 = V_21 ;
V_18 = V_17 -> V_28 ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 += 4 ) {
* V_18 ++ = ( ( V_15 + 0 ) < V_13 ) ?
V_10 [ V_15 + 3 ] : 0 ;
* V_18 ++ = ( ( V_15 + 1 ) < V_13 ) ?
V_10 [ V_15 + 2 ] : 0 ;
* V_18 ++ = ( ( V_15 + 2 ) < V_13 ) ?
V_10 [ V_15 + 1 ] : 0 ;
* V_18 ++ = ( ( V_15 + 3 ) < V_13 ) ?
V_10 [ V_15 + 0 ] : 0 ;
}
V_20 -> V_29 = ( T_3 ) V_15 ;
F_6 ( V_17 , V_15 ) ;
if ( ! V_4 -> V_30 -> V_31 ( V_2 , V_20 -> V_24 ) ||
( ! F_7 ( & V_4 -> V_30 -> V_32 [ V_20 -> V_24 ] ) ) ||
( V_4 -> V_30 -> V_33 ) ) {
F_8 ( V_34 ,
L_1 ) ;
F_9 ( & V_4 -> V_30 -> V_32
[ V_20 -> V_24 ] , V_17 ) ;
} else {
V_4 -> V_30 -> V_35 ( V_17 , V_2 ) ;
}
V_10 += V_13 ;
V_14 += V_13 ;
} while ( V_14 < V_11 );
F_10 ( V_2 , V_36 , V_37 ) ;
return true ;
}
static bool F_11 ( struct V_1 * V_2 )
{
bool V_38 = true ;
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
F_16 ( V_2 , L_2 ) ;
goto V_44;
} else {
F_8 ( V_34 , L_3 ) ;
}
V_39 = F_14 ( V_2 , V_42 ) ;
F_10 ( V_2 , V_42 ,
( T_1 ) ( ( V_39 | V_45 ) & 0xff ) ) ;
F_15 ( 1 ) ;
V_40 = V_41 + F_12 ( 200 ) ;
while ( F_13 ( V_41 , V_40 ) ) {
V_39 = F_14 ( V_2 , V_42 ) ;
if ( V_39 & V_46 )
break;
F_15 ( 2 ) ;
}
if ( ! ( V_39 & V_46 ) ) {
F_16 ( V_2 , L_4 ) ;
goto V_44;
}
F_8 ( V_34 , L_5 ) ;
return V_38 ;
V_44:
V_38 = false ;
return V_38 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
bool V_38 = true ;
T_2 V_39 = 0 ;
unsigned long V_40 ;
V_40 = V_41 + F_12 ( 20 ) ;
while ( F_13 ( V_41 , V_40 ) ) {
V_39 = F_14 ( V_2 , V_42 ) ;
if ( V_39 & V_47 )
break;
F_15 ( 2 ) ;
}
if ( ! ( V_39 & V_47 ) )
goto V_48;
else
F_8 ( V_34 , L_6 ) ;
return V_38 ;
V_48:
V_38 = false ;
return V_38 ;
}
static bool F_18 ( struct V_1 * V_2 ,
T_1 V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
bool V_38 = true ;
switch ( V_49 ) {
case V_50 :
V_6 -> V_51 = V_52 ;
break;
case V_53 :
V_6 -> V_51 = V_54 ;
V_38 = F_11 ( V_2 ) ;
if ( V_38 )
V_6 -> V_51 = V_55 ;
else
F_8 ( V_34 ,
L_7 ) ;
break;
case V_56 :
V_6 -> V_51 = V_57 ;
F_15 ( 1 ) ;
V_38 = F_17 ( V_2 ) ;
if ( V_38 )
V_6 -> V_51 = V_58 ;
else
F_8 ( V_34 ,
L_8 ,
V_38 ) ;
break;
default:
V_38 = false ;
F_8 ( V_34 , L_9 ) ;
break;
}
return V_38 ;
}
bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_38 = true ;
T_2 V_59 = 0 ;
T_1 * V_60 = NULL ;
T_1 V_15 = 0 ;
enum V_61 V_62 = V_63 ;
enum V_64 V_65 = V_50 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_8 ( V_34 , L_10 ) ;
if ( V_6 -> V_51 == V_66 ) {
V_62 = V_63 ;
V_65 = V_50 ;
} else if ( V_6 -> V_51 == V_58 ) {
V_62 = V_67 ;
V_65 = V_56 ;
} else {
F_8 ( V_34 ,
L_11 ) ;
}
for ( V_15 = V_65 ; V_15 <= V_56 ; V_15 ++ ) {
if ( V_62 == V_63 ) {
if ( V_6 -> V_68 [ V_15 ] == 0 ) {
const char * V_69 [ 3 ] = {
V_70 ,
V_71 ,
V_72
} ;
const struct V_73 * V_74 ;
int V_75 ;
V_75 = F_20 ( & V_74 ,
V_69 [ V_15 ] ,
& V_4 -> V_76 -> V_2 ) ;
if ( V_75 < 0 ) {
F_8 ( V_34 ,
L_12 ) ;
goto V_77;
}
if ( V_74 -> V_78 >
sizeof( V_6 -> V_79 [ V_15 ] ) ) {
F_8 ( V_34 ,
L_13 ) ;
goto V_77;
}
if ( V_15 != V_53 ) {
memcpy ( V_6 -> V_79 [ V_15 ] ,
V_74 -> V_28 , V_74 -> V_78 ) ;
V_6 -> V_68 [ V_15 ] =
V_74 -> V_78 ;
} else {
memset ( V_6 -> V_79 [ V_15 ] ,
0 , 128 ) ;
memcpy ( & V_6 -> V_79 [ V_15 ] [ 128 ] ,
V_74 -> V_28 , V_74 -> V_78 ) ;
V_6 -> V_68 [ V_15 ] =
V_74 -> V_78 + 128 ;
}
if ( V_62 == V_63 )
F_21 ( V_74 ) ;
}
}
V_60 = V_6 -> V_79 [ V_15 ] ;
V_59 = V_6 -> V_68 [ V_15 ] ;
V_38 = F_4 ( V_2 , V_60 , V_59 ) ;
if ( ! V_38 )
goto V_77;
if ( ! F_18 ( V_2 , V_15 ) )
goto V_77;
}
F_8 ( V_34 , L_14 ) ;
return V_38 ;
V_77:
F_16 ( V_2 , L_15 , V_80 ) ;
V_38 = false ;
return V_38 ;
}
