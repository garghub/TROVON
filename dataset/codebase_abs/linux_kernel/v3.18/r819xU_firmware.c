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
V_17 = F_5 ( V_21 + V_13 + 4 ) ;
if ( ! V_17 )
return false ;
memcpy ( ( unsigned char * ) ( V_17 -> V_22 ) , & V_2 , sizeof( V_2 ) ) ;
V_19 = ( T_5 * ) ( V_17 -> V_22 + V_23 ) ;
V_19 -> V_24 = V_25 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_20 = V_20 ;
F_6 ( V_17 , V_21 ) ;
V_18 = V_17 -> V_28 ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 += 4 ) {
* V_18 ++ = ( ( V_15 + 0 ) < V_13 ) ? V_9 [ V_15 + 3 ] : 0 ;
* V_18 ++ = ( ( V_15 + 1 ) < V_13 ) ? V_9 [ V_15 + 2 ] : 0 ;
* V_18 ++ = ( ( V_15 + 2 ) < V_13 ) ? V_9 [ V_15 + 1 ] : 0 ;
* V_18 ++ = ( ( V_15 + 3 ) < V_13 ) ? V_9 [ V_15 + 0 ] : 0 ;
}
V_19 -> V_29 = ( T_4 ) V_15 ;
F_7 ( V_17 , V_15 ) ;
if ( ! V_4 -> V_30 -> V_31 ( V_2 , V_19 -> V_24 ) ||
( ! F_8 ( & V_4 -> V_30 -> V_32 [ V_19 -> V_24 ] ) ) ||\
( V_4 -> V_30 -> V_33 ) ) {
F_9 ( V_34 , L_1 ) ;
F_10 ( & V_4 -> V_30 -> V_32 [ V_19 -> V_24 ] , V_17 ) ;
} else {
V_4 -> V_30 -> V_35 ( V_17 , V_2 ) ;
}
V_9 += V_13 ;
V_14 += V_13 ;
} while ( V_14 < V_10 );
return V_11 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_36 = 200000 , V_37 = 200000 ;
T_3 V_38 = 0 ;
do {
F_12 ( V_2 , V_39 , & V_38 ) ;
if ( V_38 & V_40 )
break;
} while ( V_36 -- );
if ( ! ( V_38 & V_40 ) ) {
F_9 ( V_41 , L_2 ) ;
goto V_42;
} else {
F_9 ( V_34 , L_3 ) ;
}
F_12 ( V_2 , V_39 , & V_38 ) ;
F_13 ( V_2 , V_39 , ( T_2 ) ( ( V_38 | V_43 ) & 0xff ) ) ;
F_14 ( 1000 ) ;
do {
F_12 ( V_2 , V_39 , & V_38 ) ;
if ( V_38 & V_44 )
break;
} while ( V_37 -- );
if ( ! ( V_38 & V_44 ) )
goto V_42;
else
F_9 ( V_34 , L_4 ) ;
return V_11 ;
V_42:
F_9 ( V_41 , L_5 , V_45 ) ;
V_11 = FALSE ;
return V_11 ;
}
static bool F_15 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_46 = 200000 ;
T_3 V_38 = 0 ;
do {
F_12 ( V_2 , V_39 , & V_38 ) ;
if ( V_38 & V_47 )
break;
} while ( V_46 -- );
if ( ! ( V_38 & V_47 ) )
goto V_48;
else
F_9 ( V_34 , L_6 ) ;
return V_11 ;
V_48:
F_9 ( V_41 , L_5 , V_45 ) ;
V_11 = false ;
return V_11 ;
}
bool F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_11 = TRUE ;
T_3 V_49 = 0 ;
T_2 * V_50 = NULL ;
T_3 V_51 = 0 ;
T_6 V_52 = V_53 ;
T_7 V_54 = V_55 ;
T_1 * V_5 = V_4 -> V_6 ;
const struct V_56 * V_57 ;
const char * V_58 [ 3 ] = { L_7 ,
L_8 ,
L_9 } ;
int V_59 ;
F_9 ( V_34 , L_10 ) ;
if ( V_5 -> V_60 == V_61 ) {
V_52 = V_53 ;
V_54 = V_55 ;
} else if ( V_5 -> V_60 == V_62 ) {
V_52 = V_63 ;
V_54 = V_64 ;
} else {
F_9 ( V_34 , L_11 ) ;
}
for ( V_51 = V_54 ; V_51 <= V_64 ; V_51 ++ ) {
if ( V_52 == V_53 ) {
V_59 = F_17 ( & V_57 , V_58 [ V_51 ] , & V_4 -> V_65 -> V_2 ) ;
if ( V_59 < 0 ) {
F_9 ( V_41 , L_12 ) ;
goto V_66;
}
if ( V_57 -> V_67 > sizeof( V_5 -> V_68 ) ) {
F_9 ( V_41 , L_13 ) ;
goto V_66;
}
if ( V_51 != V_69 ) {
memcpy ( V_5 -> V_68 , V_57 -> V_28 , V_57 -> V_67 ) ;
V_50 = V_5 -> V_68 ;
V_49 = V_57 -> V_67 ;
} else {
memset ( V_5 -> V_68 , 0 , 128 ) ;
memcpy ( & V_5 -> V_68 [ 128 ] , V_57 -> V_28 , V_57 -> V_67 ) ;
V_50 = V_5 -> V_68 ;
V_49 = V_57 -> V_67 + 128 ;
}
V_5 -> V_70 = V_49 ;
} else if ( V_52 == V_63 ) {
V_50 = V_5 -> V_68 ;
V_49 = V_5 -> V_70 ;
}
V_11 = F_4 ( V_2 , V_50 , V_49 ) ;
if ( V_52 == V_53 )
F_18 ( V_57 ) ;
if ( V_11 != TRUE )
goto V_66;
switch ( V_51 ) {
case V_55 :
V_5 -> V_60 = V_71 ;
break;
case V_69 :
V_5 -> V_60 = V_72 ;
V_11 = F_11 ( V_2 ) ;
if ( V_11 != TRUE ) {
F_9 ( V_41 , L_14 ) ;
goto V_66;
}
V_5 -> V_60 = V_73 ;
break;
case V_64 :
V_5 -> V_60 = V_74 ;
F_14 ( 1 ) ;
V_11 = F_15 ( V_2 ) ;
if ( V_11 != TRUE ) {
F_9 ( V_41 , L_15 , V_11 ) ;
goto V_66;
}
V_5 -> V_60 = V_62 ;
break;
}
}
F_9 ( V_34 , L_16 ) ;
return V_11 ;
V_66:
F_9 ( V_41 , L_5 , V_45 ) ;
V_11 = FALSE ;
return V_11 ;
}
