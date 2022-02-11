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
T_5 * V_19 ;
T_2 V_20 ;
T_2 V_21 ;
F_1 ( V_2 ) ;
V_12 = V_5 -> V_7 ;
do {
if ( ( V_10 - V_14 ) > V_12 ) {
V_13 = V_12 ;
V_20 = 0 ;
} else {
V_13 = V_10 - V_14 ;
V_20 = 1 ;
}
V_17 = F_5 ( V_22 + V_13 + 4 ) ;
if ( ! V_17 )
return false ;
memcpy ( ( unsigned char * ) ( V_17 -> V_23 ) , & V_2 , sizeof( V_2 ) ) ;
V_19 = ( T_5 * ) ( V_17 -> V_23 + V_24 ) ;
V_19 -> V_25 = V_26 ;
V_19 -> V_27 = V_28 ;
V_19 -> V_20 = V_20 ;
F_6 ( V_17 , V_22 ) ;
V_18 = V_17 -> V_29 ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 += 4 ) {
* V_18 ++ = ( ( V_15 + 0 ) < V_13 ) ? V_9 [ V_15 + 3 ] : 0 ;
* V_18 ++ = ( ( V_15 + 1 ) < V_13 ) ? V_9 [ V_15 + 2 ] : 0 ;
* V_18 ++ = ( ( V_15 + 2 ) < V_13 ) ? V_9 [ V_15 + 1 ] : 0 ;
* V_18 ++ = ( ( V_15 + 3 ) < V_13 ) ? V_9 [ V_15 + 0 ] : 0 ;
}
V_19 -> V_30 = ( T_4 ) V_15 ;
F_7 ( V_17 , V_15 ) ;
V_21 = V_19 -> V_25 ;
if ( ! V_4 -> V_31 -> V_32 ( V_2 , V_21 ) ||
( ! F_8 ( & V_4 -> V_31 -> V_33 [ V_21 ] ) ) ||
( V_4 -> V_31 -> V_34 ) ) {
F_9 ( V_35 , L_1 ) ;
F_10 ( & V_4 -> V_31 -> V_33 [ V_19 -> V_25 ] , V_17 ) ;
} else {
V_4 -> V_31 -> V_36 ( V_17 , V_2 ) ;
}
V_9 += V_13 ;
V_14 += V_13 ;
} while ( V_14 < V_10 );
return V_11 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_37 = 200000 , V_38 = 200000 ;
T_3 V_39 = 0 ;
do {
F_12 ( V_2 , V_40 , & V_39 ) ;
if ( V_39 & V_41 )
break;
} while ( V_37 -- );
if ( ! ( V_39 & V_41 ) ) {
F_9 ( V_42 , L_2 ) ;
goto V_43;
} else {
F_9 ( V_35 , L_3 ) ;
}
F_12 ( V_2 , V_40 , & V_39 ) ;
F_13 ( V_2 , V_40 , ( T_2 ) ( ( V_39 | V_44 ) & 0xff ) ) ;
F_14 ( 1000 ) ;
do {
F_12 ( V_2 , V_40 , & V_39 ) ;
if ( V_39 & V_45 )
break;
} while ( V_38 -- );
if ( ! ( V_39 & V_45 ) )
goto V_43;
else
F_9 ( V_35 , L_4 ) ;
return V_11 ;
V_43:
F_9 ( V_42 , L_5 , V_46 ) ;
V_11 = false ;
return V_11 ;
}
static bool F_15 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_47 = 200000 ;
T_3 V_39 = 0 ;
do {
F_12 ( V_2 , V_40 , & V_39 ) ;
if ( V_39 & V_48 )
break;
} while ( V_47 -- );
if ( ! ( V_39 & V_48 ) )
goto V_49;
else
F_9 ( V_35 , L_6 ) ;
return V_11 ;
V_49:
F_9 ( V_42 , L_5 , V_46 ) ;
V_11 = false ;
return V_11 ;
}
bool F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_11 = true ;
T_3 V_50 = 0 ;
T_2 * V_51 = NULL ;
T_3 V_52 = 0 ;
T_6 V_53 = V_54 ;
T_7 V_55 = V_56 ;
T_1 * V_5 = V_4 -> V_6 ;
const struct V_57 * V_58 ;
const char * V_59 [ 3 ] = { L_7 ,
L_8 ,
L_9 } ;
int V_60 ;
F_9 ( V_35 , L_10 ) ;
if ( V_5 -> V_61 == V_62 ) {
V_53 = V_54 ;
V_55 = V_56 ;
} else if ( V_5 -> V_61 == V_63 ) {
V_53 = V_64 ;
V_55 = V_65 ;
} else {
F_9 ( V_35 , L_11 ) ;
}
for ( V_52 = V_55 ; V_52 <= V_65 ; V_52 ++ ) {
if ( V_53 == V_54 ) {
V_60 = F_17 ( & V_58 , V_59 [ V_52 ] , & V_4 -> V_66 -> V_2 ) ;
if ( V_60 < 0 ) {
F_9 ( V_42 , L_12 ) ;
goto V_67;
}
if ( V_58 -> V_68 > sizeof( V_5 -> V_69 ) ) {
F_9 ( V_42 , L_13 ) ;
goto V_67;
}
if ( V_52 != V_70 ) {
memcpy ( V_5 -> V_69 , V_58 -> V_29 , V_58 -> V_68 ) ;
V_51 = V_5 -> V_69 ;
V_50 = V_58 -> V_68 ;
} else {
memset ( V_5 -> V_69 , 0 , 128 ) ;
memcpy ( & V_5 -> V_69 [ 128 ] , V_58 -> V_29 , V_58 -> V_68 ) ;
V_51 = V_5 -> V_69 ;
V_50 = V_58 -> V_68 + 128 ;
}
V_5 -> V_71 = V_50 ;
} else if ( V_53 == V_64 ) {
V_51 = V_5 -> V_69 ;
V_50 = V_5 -> V_71 ;
}
V_11 = F_4 ( V_2 , V_51 , V_50 ) ;
if ( V_53 == V_54 )
F_18 ( V_58 ) ;
if ( ! V_11 )
goto V_67;
switch ( V_52 ) {
case V_56 :
V_5 -> V_61 = V_72 ;
break;
case V_70 :
V_5 -> V_61 = V_73 ;
V_11 = F_11 ( V_2 ) ;
if ( ! V_11 ) {
F_9 ( V_42 , L_14 ) ;
goto V_67;
}
V_5 -> V_61 = V_74 ;
break;
case V_65 :
V_5 -> V_61 = V_75 ;
F_14 ( 1 ) ;
V_11 = F_15 ( V_2 ) ;
if ( ! V_11 ) {
F_9 ( V_42 , L_15 , V_11 ) ;
goto V_67;
}
V_5 -> V_61 = V_63 ;
break;
}
}
F_9 ( V_35 , L_16 ) ;
return V_11 ;
V_67:
F_9 ( V_42 , L_5 , V_46 ) ;
V_11 = false ;
return V_11 ;
}
