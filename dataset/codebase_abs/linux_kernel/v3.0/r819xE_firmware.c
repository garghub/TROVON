void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
V_3 -> V_5 =
F_2 ( V_6 ) ;
}
static bool F_3 ( struct V_1 * V_2 , T_2 * V_7 ,
T_3 V_8 )
{
bool V_9 = true ;
T_4 V_10 ;
T_4 V_11 , V_12 = 0 ;
int V_13 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_14 * V_15 ;
unsigned char * V_16 ;
T_5 * V_17 ;
T_2 V_18 ;
F_1 ( V_2 ) ;
V_10 = V_3 -> V_5 ;
do {
if ( ( V_8 - V_12 ) > V_10 ) {
V_11 = V_10 ;
V_18 = 0 ;
} else {
V_11 = V_8 - V_12 ;
V_18 = 1 ;
}
V_15 = F_4 ( V_11 + 4 ) ;
V_17 = ( T_5 * ) ( V_15 -> V_19 + V_20 ) ;
V_17 -> V_21 = V_22 ;
V_17 -> V_23 = V_24 ;
V_17 -> V_18 = V_18 ;
V_16 = V_15 -> V_25 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 += 4 ) {
* V_16 ++ = ( ( V_13 + 0 ) < V_11 ) ?
V_7 [ V_13 + 3 ] : 0 ;
* V_16 ++ = ( ( V_13 + 1 ) < V_11 ) ?
V_7 [ V_13 + 2 ] : 0 ;
* V_16 ++ = ( ( V_13 + 2 ) < V_11 ) ?
V_7 [ V_13 + 1 ] : 0 ;
* V_16 ++ = ( ( V_13 + 3 ) < V_11 ) ?
V_7 [ V_13 + 0 ] : 0 ;
}
V_17 -> V_26 = ( T_4 ) V_13 ;
F_5 ( V_15 , V_13 ) ;
V_2 -> V_27 -> V_28 ( V_15 , V_2 -> V_27 ) ;
V_7 += V_11 ;
V_12 += V_11 ;
} while ( V_12 < V_8 );
return V_9 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
bool V_9 = true ;
T_3 V_30 = 0 ;
V_29 = V_31 + F_7 ( 20 ) ;
while ( F_8 ( V_31 , V_29 ) ) {
V_30 = F_9 ( V_2 , V_32 ) ;
if ( V_30 & V_33 )
break;
F_10 ( 2 ) ;
}
if ( ! ( V_30 & V_33 ) ) {
F_11 ( V_34 , L_1 ) ;
goto V_35;
} else {
F_11 ( V_36 , L_2 ) ;
}
V_30 = F_9 ( V_2 , V_32 ) ;
F_12 ( V_2 , V_32 ,
( T_2 ) ( ( V_30 | V_37 ) & 0xff ) ) ;
F_13 ( 1 ) ;
V_29 = V_31 + F_7 ( 20 ) ;
while ( F_8 ( V_31 , V_29 ) ) {
V_30 = F_9 ( V_2 , V_32 ) ;
if ( V_30 & V_38 )
break;
F_10 ( 2 ) ;
}
if ( ! ( V_30 & V_38 ) )
goto V_35;
else
F_11 ( V_36 , L_3 ) ;
return V_9 ;
V_35:
F_11 ( V_34 , L_4 , V_39 ) ;
V_9 = FALSE ;
return V_9 ;
}
static bool F_14 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
bool V_9 = true ;
T_3 V_30 = 0 ;
V_29 = V_31 + F_7 ( 20 ) ;
while ( F_8 ( V_31 , V_29 ) ) {
V_30 = F_9 ( V_2 , V_32 ) ;
if ( V_30 & V_40 )
break;
F_10 ( 2 ) ;
}
if ( ! ( V_30 & V_40 ) )
goto V_41;
else
F_11 ( V_36 , L_5 ) ;
return V_9 ;
V_41:
F_11 ( V_34 , L_4 , V_39 ) ;
V_9 = false ;
return V_9 ;
}
bool F_15 ( struct V_1 * V_2 )
{
bool V_9 = true ;
T_3 V_42 = 0 ;
T_2 * V_43 = NULL ;
T_3 V_44 = 0 ;
enum V_45 V_46 = V_47 ;
enum V_48 V_49 = V_50 ;
T_1 * V_3 = V_2 -> V_4 ;
const struct V_51 * V_52 ;
const char * V_53 [ 3 ] = { L_6 ,
L_7 ,
L_8 } ;
int V_54 ;
F_11 ( V_36 , L_9 ) ;
if ( V_3 -> V_55 == V_56 ) {
V_46 = V_47 ;
V_49 = V_50 ;
} else if ( V_3 -> V_55 == V_57 ) {
V_46 = V_58 ;
V_49 = V_59 ;
} else {
F_11 ( V_36 ,
L_10 ) ;
}
for ( V_44 = V_49 ; V_44 <= V_59 ;
V_44 ++ ) {
if ( V_46 == V_47 ) {
if ( V_3 -> V_60 [ V_44 ] == 0 ) {
V_54 = F_16 ( & V_52 ,
V_53 [ V_44 ] , & V_2 -> V_61 -> V_62 ) ;
if ( V_54 < 0 ) {
F_11 ( V_36 , L_11 ) ;
goto V_63;
}
if ( V_52 -> V_64 > sizeof( V_3 -> V_65 [ V_44 ] ) ) {
F_11 ( V_36 ,
L_12 ) ;
goto V_63;
}
if ( V_44 != V_66 ) {
memcpy ( V_3 -> V_65 [ V_44 ] ,
V_52 -> V_25 , V_52 -> V_64 ) ;
V_3 -> V_60 [ V_44 ] = V_52 -> V_64 ;
} else {
memset ( V_3 -> V_65 [ V_44 ] , 0 , 128 ) ;
memcpy ( & V_3 -> V_65 [ V_44 ] [ 128 ] , V_52 -> V_25 ,
V_52 -> V_64 ) ;
V_3 -> V_60 [ V_44 ] = V_52 -> V_64 + 128 ;
}
if ( V_46 == V_47 )
F_17 ( V_52 ) ;
}
V_43 = V_3 -> V_65 [ V_44 ] ;
V_42 = V_3 -> V_60 [ V_44 ] ;
} else if ( V_46 == V_58 ) {
V_43 = V_3 -> V_65 [ V_44 ] ;
V_42 = V_3 -> V_60 [ V_44 ] ;
}
V_9 = F_3 ( V_2 , V_43 , V_42 ) ;
if ( V_9 != TRUE )
goto V_63;
switch ( V_44 ) {
case V_50 :
V_3 -> V_55 = V_67 ;
break;
case V_66 :
V_3 -> V_55 = V_68 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 != TRUE ) {
F_11 ( V_36 ,
L_13 ) ;
goto V_63;
}
V_3 -> V_55 = V_69 ;
break;
case V_59 :
V_3 -> V_55 = V_70 ;
F_13 ( 1 ) ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 != TRUE ) {
F_11 ( V_36 ,
L_14 ,
V_9 ) ;
goto V_63;
}
V_3 -> V_55 = V_57 ;
break;
}
}
F_11 ( V_36 , L_15 ) ;
return V_9 ;
V_63:
F_11 ( V_34 , L_16 , V_39 , V_44 ) ;
V_9 = false ;
return V_9 ;
}
