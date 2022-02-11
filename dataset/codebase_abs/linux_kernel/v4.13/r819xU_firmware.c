static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_5 = V_4 -> V_6 ;
V_5 -> V_7 = F_3 ( V_8 ) ;
}
static bool F_4 ( struct V_1 * V_2 , T_2 * V_9 ,
T_3 V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_11 = true ;
T_4 V_12 ;
T_4 V_13 , V_14 = 0 ;
int V_15 ;
T_1 * V_5 = V_4 -> V_6 ;
struct V_16 * V_17 ;
unsigned char * V_18 ;
struct V_19 * V_20 ;
T_2 V_21 ;
T_2 V_22 ;
F_1 ( V_2 ) ;
V_12 = V_5 -> V_7 ;
do {
if ( ( V_10 - V_14 ) > V_12 ) {
V_13 = V_12 ;
V_21 = 0 ;
} else {
V_13 = V_10 - V_14 ;
V_21 = 1 ;
}
V_17 = F_5 ( V_23 + V_13 + 4 ) ;
if ( ! V_17 )
return false ;
memcpy ( ( unsigned char * ) ( V_17 -> V_24 ) , & V_2 , sizeof( V_2 ) ) ;
V_20 = (struct V_19 * ) ( V_17 -> V_24 + V_25 ) ;
V_20 -> V_26 = V_27 ;
V_20 -> V_28 = V_29 ;
V_20 -> V_21 = V_21 ;
F_6 ( V_17 , V_23 ) ;
V_18 = V_17 -> V_30 ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 += 4 ) {
* V_18 ++ = ( ( V_15 + 0 ) < V_13 ) ? V_9 [ V_15 + 3 ] : 0 ;
* V_18 ++ = ( ( V_15 + 1 ) < V_13 ) ? V_9 [ V_15 + 2 ] : 0 ;
* V_18 ++ = ( ( V_15 + 2 ) < V_13 ) ? V_9 [ V_15 + 1 ] : 0 ;
* V_18 ++ = ( ( V_15 + 3 ) < V_13 ) ? V_9 [ V_15 + 0 ] : 0 ;
}
V_20 -> V_31 = ( T_4 ) V_15 ;
F_7 ( V_17 , V_15 ) ;
V_22 = V_20 -> V_26 ;
if ( ! V_4 -> V_32 -> V_33 ( V_2 , V_22 ) ||
( ! F_8 ( & V_4 -> V_32 -> V_34 [ V_22 ] ) ) ||
( V_4 -> V_32 -> V_35 ) ) {
F_9 ( V_36 , L_1 ) ;
F_10 ( & V_4 -> V_32 -> V_34 [ V_20 -> V_26 ] , V_17 ) ;
} else {
V_4 -> V_32 -> V_37 ( V_17 , V_2 ) ;
}
V_9 += V_13 ;
V_14 += V_13 ;
} while ( V_14 < V_10 );
return V_11 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_38 = 200000 , V_39 = 200000 ;
T_3 V_40 = 0 ;
do {
F_12 ( V_2 , V_41 , & V_40 ) ;
if ( V_40 & V_42 )
break;
} while ( V_38 -- );
if ( ! ( V_40 & V_42 ) ) {
F_9 ( V_43 , L_2 ) ;
goto V_44;
} else {
F_9 ( V_36 , L_3 ) ;
}
F_12 ( V_2 , V_41 , & V_40 ) ;
F_13 ( V_2 , V_41 ,
( T_2 ) ( ( V_40 | V_45 ) & 0xff ) ) ;
F_14 ( 1000 ) ;
do {
F_12 ( V_2 , V_41 , & V_40 ) ;
if ( V_40 & V_46 )
break;
} while ( V_39 -- );
if ( ! ( V_40 & V_46 ) )
goto V_44;
else
F_9 ( V_36 , L_4 ) ;
return V_11 ;
V_44:
F_9 ( V_43 , L_5 , V_47 ) ;
V_11 = false ;
return V_11 ;
}
static bool F_15 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_48 = 200000 ;
T_3 V_40 = 0 ;
do {
F_12 ( V_2 , V_41 , & V_40 ) ;
if ( V_40 & V_49 )
break;
} while ( V_48 -- );
if ( ! ( V_40 & V_49 ) )
goto V_50;
else
F_9 ( V_36 , L_6 ) ;
return V_11 ;
V_50:
F_9 ( V_43 , L_5 , V_47 ) ;
V_11 = false ;
return V_11 ;
}
bool F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_11 = true ;
T_3 V_51 = 0 ;
T_2 * V_52 = NULL ;
T_3 V_53 = 0 ;
T_5 V_54 = V_55 ;
T_6 V_56 = V_57 ;
T_1 * V_5 = V_4 -> V_6 ;
const struct V_58 * V_59 ;
const char * V_60 [ 3 ] = { L_7 ,
L_8 ,
L_9 } ;
int V_61 ;
F_9 ( V_36 , L_10 ) ;
if ( V_5 -> V_62 == V_63 ) {
V_54 = V_55 ;
V_56 = V_57 ;
} else if ( V_5 -> V_62 == V_64 ) {
V_54 = V_65 ;
V_56 = V_66 ;
} else {
F_9 ( V_36 , L_11 ) ;
}
for ( V_53 = V_56 ; V_53 <= V_66 ; V_53 ++ ) {
if ( V_54 == V_55 ) {
V_61 = F_17 ( & V_59 , V_60 [ V_53 ] , & V_4 -> V_67 -> V_2 ) ;
if ( V_61 < 0 ) {
F_9 ( V_43 , L_12 ) ;
goto V_68;
}
if ( V_59 -> V_69 > sizeof( V_5 -> V_70 ) ) {
F_9 ( V_43 , L_13 ) ;
goto V_68;
}
if ( V_53 != V_71 ) {
memcpy ( V_5 -> V_70 , V_59 -> V_30 , V_59 -> V_69 ) ;
V_52 = V_5 -> V_70 ;
V_51 = V_59 -> V_69 ;
} else {
memset ( V_5 -> V_70 , 0 , 128 ) ;
memcpy ( & V_5 -> V_70 [ 128 ] , V_59 -> V_30 , V_59 -> V_69 ) ;
V_52 = V_5 -> V_70 ;
V_51 = V_59 -> V_69 + 128 ;
}
V_5 -> V_72 = V_51 ;
} else if ( V_54 == V_65 ) {
V_52 = V_5 -> V_70 ;
V_51 = V_5 -> V_72 ;
}
V_11 = F_4 ( V_2 , V_52 , V_51 ) ;
if ( V_54 == V_55 )
F_18 ( V_59 ) ;
if ( ! V_11 )
goto V_68;
switch ( V_53 ) {
case V_57 :
V_5 -> V_62 = V_73 ;
break;
case V_71 :
V_5 -> V_62 = V_74 ;
V_11 = F_11 ( V_2 ) ;
if ( ! V_11 ) {
F_9 ( V_43 , L_14 ) ;
goto V_68;
}
V_5 -> V_62 = V_75 ;
break;
case V_66 :
V_5 -> V_62 = V_76 ;
F_14 ( 1 ) ;
V_11 = F_15 ( V_2 ) ;
if ( ! V_11 ) {
F_9 ( V_43 , L_15 , V_11 ) ;
goto V_68;
}
V_5 -> V_62 = V_64 ;
break;
}
}
F_9 ( V_36 , L_16 ) ;
return V_11 ;
V_68:
F_9 ( V_43 , L_5 , V_47 ) ;
V_11 = false ;
return V_11 ;
}
