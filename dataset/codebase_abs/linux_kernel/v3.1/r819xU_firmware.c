void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_5 = V_4 -> V_6 ;
V_5 -> V_7 = F_3 ( V_8 ) ;
}
bool F_4 ( struct V_1 * V_2 , T_2 * V_9 , T_3 V_10 )
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
if( ( V_10 - V_14 ) > V_12 ) {
V_13 = V_12 ;
V_20 = 0 ;
} else {
V_13 = V_10 - V_14 ;
V_20 = 1 ;
}
#ifdef F_5
V_17 = F_6 ( V_21 + V_13 + 4 ) ;
#else
V_17 = F_6 ( V_13 + 4 ) ;
#endif
memcpy ( ( unsigned char * ) ( V_17 -> V_22 ) , & V_2 , sizeof( V_2 ) ) ;
V_19 = ( T_5 * ) ( V_17 -> V_22 + V_23 ) ;
V_19 -> V_24 = V_25 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_20 = V_20 ;
#ifdef F_5
F_7 ( V_17 , V_21 ) ;
#endif
V_18 = V_17 -> V_28 ;
for( V_15 = 0 ; V_15 < V_13 ; V_15 += 4 ) {
* V_18 ++ = ( ( V_15 + 0 ) < V_13 ) ? V_9 [ V_15 + 3 ] : 0 ;
* V_18 ++ = ( ( V_15 + 1 ) < V_13 ) ? V_9 [ V_15 + 2 ] : 0 ;
* V_18 ++ = ( ( V_15 + 2 ) < V_13 ) ? V_9 [ V_15 + 1 ] : 0 ;
* V_18 ++ = ( ( V_15 + 3 ) < V_13 ) ? V_9 [ V_15 + 0 ] : 0 ;
}
V_19 -> V_29 = ( T_4 ) V_15 ;
F_8 ( V_17 , V_15 ) ;
if( ! V_4 -> V_30 -> V_31 ( V_2 , V_19 -> V_24 ) ||
( ! F_9 ( & V_4 -> V_30 -> V_32 [ V_19 -> V_24 ] ) ) ||\
( V_4 -> V_30 -> V_33 ) ) {
F_10 ( V_34 , L_1 ) ;
F_11 ( & V_4 -> V_30 -> V_32 [ V_19 -> V_24 ] , V_17 ) ;
} else {
V_4 -> V_30 -> V_35 ( V_17 , V_2 ) ;
}
V_9 += V_13 ;
V_14 += V_13 ;
}while( V_14 < V_10 );
return V_11 ;
}
bool
F_12 (
struct V_1 * V_2 ,
T_3 V_36
)
{
bool V_37 = true ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
T_5 * V_19 ;
unsigned char * V_38 ;
bool V_39 = false ;
V_17 = F_6 ( V_36 + 4 ) ;
memcpy ( ( unsigned char * ) ( V_17 -> V_22 ) , & V_2 , sizeof( V_2 ) ) ;
V_19 = ( T_5 * ) ( V_17 -> V_22 + V_23 ) ;
V_19 -> V_24 = V_25 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_20 = V_39 ;
V_38 = F_8 ( V_17 , V_36 ) ;
memset ( V_38 , 0 , V_36 ) ;
V_19 -> V_29 = ( T_4 ) V_36 ;
if( ! V_4 -> V_30 -> V_31 ( V_2 , V_19 -> V_24 ) ||
( ! F_9 ( & V_4 -> V_30 -> V_32 [ V_19 -> V_24 ] ) ) ||\
( V_4 -> V_30 -> V_33 ) ) {
F_10 ( V_34 , L_2 ) ;
F_11 ( & V_4 -> V_30 -> V_32 [ V_19 -> V_24 ] , V_17 ) ;
} else {
V_4 -> V_30 -> V_35 ( V_17 , V_2 ) ;
}
return V_37 ;
}
bool F_13 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_40 = 200000 , V_41 = 200000 ;
T_3 V_42 = 0 ;
do {
V_42 = F_14 ( V_2 , V_43 ) ;
if( V_42 & V_44 )
break;
}while( V_40 -- );
if( ! ( V_42 & V_44 ) ) {
F_10 ( V_45 , L_3 ) ;
goto V_46;
} else {
F_10 ( V_34 , L_4 ) ;
}
V_42 = F_14 ( V_2 , V_43 ) ;
F_15 ( V_2 , V_43 , ( T_2 ) ( ( V_42 | V_47 ) & 0xff ) ) ;
F_16 ( 1000 ) ;
do {
V_42 = F_14 ( V_2 , V_43 ) ;
if( V_42 & V_48 )
break;
}while( V_41 -- );
if( ! ( V_42 & V_48 ) ) {
goto V_46;
} else {
F_10 ( V_34 , L_5 ) ;
}
return V_11 ;
V_46:
F_10 ( V_45 , L_6 , V_49 ) ;
V_11 = FALSE ;
return V_11 ;
}
bool F_17 ( struct V_1 * V_2 )
{
bool V_11 = true ;
int V_50 = 200000 ;
T_3 V_42 = 0 ;
do {
V_42 = F_14 ( V_2 , V_43 ) ;
if( V_42 & V_51 )
break;
}while( V_50 -- );
if( ! ( V_42 & V_51 ) )
goto V_52;
else
F_10 ( V_34 , L_7 ) ;
return V_11 ;
V_52:
F_10 ( V_45 , L_6 , V_49 ) ;
V_11 = false ;
return V_11 ;
}
bool F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_11 = TRUE ;
T_3 V_53 = 0 ;
T_2 * V_54 = NULL ;
T_3 V_55 = 0 ;
T_6 V_56 = V_57 ;
T_7 V_58 = V_59 ;
T_1 * V_5 = V_4 -> V_6 ;
const struct V_60 * V_61 ;
const char * V_62 [ 3 ] = { L_8 ,
L_9 ,
L_10 } ;
int V_63 ;
F_10 ( V_34 , L_11 ) ;
if ( V_5 -> V_64 == V_65 ) {
V_56 = V_57 ;
V_58 = V_59 ;
} else if( V_5 -> V_64 == V_66 ) {
V_56 = V_67 ;
V_58 = V_68 ;
} else {
F_10 ( V_34 , L_12 ) ;
}
for( V_55 = V_58 ; V_55 <= V_68 ; V_55 ++ ) {
if( V_56 == V_57 ) {
V_63 = F_19 ( & V_61 , V_62 [ V_55 ] , & V_4 -> V_69 -> V_2 ) ;
if( V_63 < 0 ) {
F_10 ( V_45 , L_13 ) ;
goto V_70;
}
if( V_61 -> V_71 > sizeof( V_5 -> V_72 ) ) {
F_10 ( V_45 , L_14 ) ;
goto V_70;
}
if( V_55 != V_73 ) {
memcpy ( V_5 -> V_72 , V_61 -> V_28 , V_61 -> V_71 ) ;
V_54 = V_5 -> V_72 ;
V_53 = V_61 -> V_71 ;
} else {
#ifdef F_20
memcpy ( V_5 -> V_72 , V_61 -> V_28 , V_61 -> V_71 ) ;
V_54 = V_5 -> V_72 ;
V_53 = V_61 -> V_71 ;
#else
memset ( V_5 -> V_72 , 0 , 128 ) ;
memcpy ( & V_5 -> V_72 [ 128 ] , V_61 -> V_28 , V_61 -> V_71 ) ;
V_54 = V_5 -> V_72 ;
V_53 = V_61 -> V_71 + 128 ;
#endif
}
V_5 -> V_74 = V_53 ;
} else if( V_56 == V_67 ) {
V_54 = V_5 -> V_72 ;
V_53 = V_5 -> V_74 ;
}
V_11 = F_4 ( V_2 , V_54 , V_53 ) ;
if( V_56 == V_57 ) {
F_21 ( V_61 ) ;
}
if( V_11 != TRUE ) {
goto V_70;
}
switch( V_55 ) {
case V_59 :
V_5 -> V_64 = V_75 ;
#ifdef F_20
V_11 = F_12 ( V_2 , V_76 ) ;
if( V_11 != true )
{
F_10 ( V_77 , L_15 ) ;
goto V_70;
}
#endif
break;
case V_73 :
V_5 -> V_64 = V_78 ;
V_11 = F_13 ( V_2 ) ;
if( V_11 != TRUE ) {
F_10 ( V_45 , L_16 ) ;
goto V_70;
}
V_5 -> V_64 = V_79 ;
break;
case V_68 :
V_5 -> V_64 = V_80 ;
F_16 ( 1 ) ;
V_11 = F_17 ( V_2 ) ;
if( V_11 != TRUE ) {
F_10 ( V_45 , L_17 , V_11 ) ;
goto V_70;
}
V_5 -> V_64 = V_66 ;
break;
}
}
F_10 ( V_34 , L_18 ) ;
return V_11 ;
V_70:
F_10 ( V_45 , L_6 , V_49 ) ;
V_11 = FALSE ;
return V_11 ;
}
