int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_2 V_6 [ 4 ] ;
T_3 V_7 ;
for ( V_7 = 1 ; V_7 <= 3 ; V_7 ++ ) {
V_6 [ 0 ] = ( ( T_2 * ) & V_4 ) [ V_7 ] ;
V_6 [ 1 ] = V_6 [ 0 ] ;
V_6 [ 2 ] = V_6 [ 0 ] ;
V_6 [ 3 ] = V_6 [ 0 ] ;
V_5 = F_2 ( V_2 ,
V_3 + V_7 ,
V_6 ,
4 ,
V_8 ,
NULL ) ;
if ( V_5 ) {
break;
}
}
if ( V_5 ) {
F_3 ( V_9 , ( L_1 ,
V_4 , V_3 ) ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 ,
V_3 ,
( T_2 * ) ( & V_4 ) ,
4 ,
V_10 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_2 ,
V_4 , V_3 ) ) ;
return V_5 ;
}
return 0 ;
}
int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ,
V_3 + 1 ,
( ( T_2 * ) ( & V_4 ) ) + 1 ,
sizeof( T_1 ) - 1 ,
V_10 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_1 ,
V_3 , V_4 ) ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 ,
V_3 ,
( T_2 * ) ( & V_4 ) ,
sizeof( T_2 ) ,
V_10 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_2 ,
V_3 , V_4 ) ) ;
return V_5 ;
}
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , T_1 * V_11 , T_1 * V_12 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_13 ,
* V_11 ) ;
if ( V_5 ) {
return V_5 ;
}
V_5 = F_2 ( V_2 ,
V_14 ,
( T_2 * ) V_12 ,
sizeof( T_1 ) ,
V_15 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_3 ) ) ;
return V_5 ;
}
return V_5 ;
}
int
F_5 ( struct V_1 * V_2 , T_1 * V_11 , T_1 * V_12 )
{
int V_5 ;
V_5 = F_2 ( V_2 ,
V_14 ,
( T_2 * ) V_12 ,
sizeof( T_1 ) ,
V_10 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_4 , * V_12 ) ) ;
return V_5 ;
}
return F_1 ( V_2 ,
V_16 ,
* V_11 ) ;
}
int
F_6 ( struct V_1 * V_2 , T_1 V_11 ,
T_2 * V_12 , T_1 V_17 )
{
T_1 V_18 ;
int V_5 = 0 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 += 4 , V_11 += 4 ) {
if ( ( V_5 = F_4 ( V_2 , & V_11 ,
( T_1 * ) & V_12 [ V_18 ] ) ) != 0 )
{
break;
}
}
return V_5 ;
}
int
F_7 ( struct V_1 * V_2 , T_1 V_11 ,
T_2 * V_12 , T_1 V_17 )
{
T_1 V_18 ;
int V_5 = 0 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 += 4 , V_11 += 4 ) {
if ( ( V_5 = F_5 ( V_2 , & V_11 ,
( T_1 * ) & V_12 [ V_18 ] ) ) != 0 )
{
break;
}
}
return V_5 ;
}
int
F_8 ( struct V_1 * V_2 , int V_19 , T_1 * V_20 )
{
int V_5 ;
T_2 V_21 [ 4 ] ;
T_2 V_22 [ 4 ] ;
V_22 [ 0 ] = V_22 [ 1 ] = V_22 [ 2 ] = V_22 [ 3 ] = ( V_19 & 0xff ) ;
V_5 = F_2 ( V_2 ,
V_23 ,
V_22 ,
4 ,
V_8 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_5 , V_19 ) ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 ,
V_24 ,
( T_2 * ) V_21 ,
sizeof( V_21 ) ,
V_15 ,
NULL ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_6 ) ) ;
return V_5 ;
}
* V_20 = V_21 [ 0 ] << 0 | V_21 [ 1 ] << 8 | V_21 [ 2 ] << 16 | V_21 [ 3 ] << 24 ;
return V_5 ;
}
void
F_9 ( struct V_1 * V_2 , T_1 * V_25 )
{
int V_7 ;
T_1 V_26 ;
for ( V_7 = 0 ; V_7 < V_27 ; V_7 ++ ) {
V_26 = 0xffffffff ;
( void ) F_8 ( V_2 , V_7 , & V_26 ) ;
V_25 [ V_7 ] = V_26 ;
}
}
int F_10 ( struct V_1 * V_2 , T_1 V_28 , bool V_29 , bool V_30 )
{
int V_5 = 0 ;
T_1 V_11 ;
T_1 V_12 ;
do {
if ( V_30 ) {
V_12 = V_31 ;
}
else {
V_12 = V_32 ;
}
if ( V_28 == V_33 ) {
V_11 = V_34 ;
} else if ( V_28 == V_35 ) {
V_11 = V_36 ;
} else {
F_11 ( 0 ) ;
}
V_5 = F_5 ( V_2 , & V_11 , & V_12 ) ;
if ( V_5 ) {
break;
}
if ( ! V_29 ) {
break;
}
#if 0
(void)_delay_until_target_alive(hifDevice, 2000, TargetType);
if (TargetType == TARGET_TYPE_AR6002) {
address = 0x000040C0;
} else if (TargetType == TARGET_TYPE_AR6003) {
address = 0x000040C0;
} else {
A_ASSERT(0);
}
data = 0;
status = ar6000_ReadRegDiag(hifDevice, &address, &data);
if (status) {
break;
}
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Reset Cause readback: 0x%X \n",data));
data &= RESET_CAUSE_LAST_MASK;
if (data != 2) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Unable to cold reset the target \n"));
}
#endif
} while ( false );
if ( V_5 ) {
F_3 ( V_9 , ( L_7 ) ) ;
}
return 0 ;
}
void
F_12 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_37 ;
T_2 V_38 [ V_39 + 4 ] ;
T_3 V_7 ;
if ( F_13 ( V_2 ,
F_14 ( V_28 , V_40 ) ,
( T_2 * ) & V_37 ,
4 ) != 0 )
{
F_3 ( V_41 , ( L_8 ) ) ;
return;
}
if ( V_28 == V_35 ) {
V_37 += 36 ;
for ( V_7 = 0 ; V_7 < V_39 + 4 ; V_7 += 4 ) {
if ( F_15 ( V_2 , V_37 , ( T_1 * ) & V_38 [ V_7 ] ) != 0 ) {
F_3 ( V_41 , ( L_9 ) ) ;
return ;
}
V_37 += 4 ;
}
memcpy ( V_42 , V_38 + 1 , V_39 ) ;
}
if ( V_28 == V_33 ) {
V_37 += 64 ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 += 4 ) {
if ( F_15 ( V_2 , V_37 , ( T_1 * ) & V_44 [ V_7 ] ) != 0 ) {
F_3 ( V_41 , ( L_9 ) ) ;
return ;
}
V_37 += 4 ;
}
}
return;
}
T_2 * F_16 ( T_1 V_28 )
{
if ( V_28 == V_35 )
return V_42 ;
if ( V_28 == V_33 )
return V_44 ;
return NULL ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_11 ;
T_1 V_45 = 0 ;
int V_5 ;
T_1 V_46 [ V_47 ] ;
T_1 V_48 = 0 ;
T_1 V_7 ;
do {
V_11 = F_14 ( V_28 , V_49 ) ;
V_11 = F_18 ( V_28 , V_11 ) ;
if ( V_28 == V_33 ) {
V_48 = V_50 ;
} else if ( V_28 == V_35 ) {
V_48 = V_51 ;
} else {
F_11 ( 0 ) ;
}
V_5 = F_4 ( V_2 , & V_11 , & V_45 ) ;
if ( V_5 ) {
F_3 ( V_41 , ( L_10 ) ) ;
break;
}
F_3 ( V_41 , ( L_11 , V_45 ) ) ;
if ( V_45 == 0 ) {
break;
}
V_45 = F_18 ( V_28 , V_45 ) ;
V_5 = F_6 ( V_2 ,
V_45 ,
( T_2 * ) & V_46 [ 0 ] ,
V_48 * ( sizeof( T_1 ) ) ) ;
if ( V_5 ) {
F_3 ( V_41 , ( L_12 ) ) ;
break;
}
F_3 ( V_41 , ( L_13 ) ) ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
F_3 ( V_41 , ( L_14 , V_7 , V_46 [ V_7 ] ) ) ;
#ifdef F_19
F_20 ( V_52 , L_15 , V_7 , V_46 [ V_7 ] ) ;
#endif
}
} while ( false );
}
int F_21 ( struct V_1 * V_2 ,
T_1 V_28 ,
T_1 V_53 ,
T_2 V_54 )
{
int V_5 ;
T_1 V_55 [ V_56 ] ;
do {
V_5 = F_22 ( V_2 , V_57 ,
V_55 , sizeof( V_55 ) ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_16 ) ) ;
break;
}
F_11 ( ( V_55 [ 1 ] & ( V_55 [ 1 ] - 1 ) ) == 0 ) ;
if ( V_54 != 0 ) {
V_55 [ 1 ] |= ( ( T_1 ) V_54 ) << 16 ;
}
V_5 = F_23 ( V_2 ,
F_14 ( V_28 , V_58 ) ,
( T_2 * ) & V_55 [ 1 ] ,
4 ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_17 ) ) ;
break;
}
F_3 ( V_59 , ( L_18 ,
V_55 [ 1 ] , F_14 ( V_28 , V_58 ) ) ) ;
if ( V_53 != 0 ) {
V_5 = F_23 ( V_2 ,
F_14 ( V_28 , V_60 ) ,
( T_2 * ) & V_53 ,
4 ) ;
if ( V_5 ) {
F_3 ( V_9 , ( L_19 ) ) ;
break;
}
}
} while ( false );
return V_5 ;
}
void F_24 ( T_2 * V_61 , T_4 V_17 , char * V_62 )
{
char V_63 [ 60 ] ;
char V_64 [ 10 ] ;
T_1 V_7 ;
T_4 V_65 , V_18 , V_66 ;
F_25 ( L_20 , V_17 , V_62 ) ;
V_18 = 0 ;
V_65 = 0 ;
V_66 = 0 ;
for( V_7 = 0 ; V_7 < V_17 ; V_7 ++ ) {
F_26 ( V_63 + V_65 , L_21 , V_61 [ V_7 ] ) ;
V_18 ++ ;
V_65 += 3 ;
if( V_18 == 16 ) {
V_18 = 0 ;
V_65 = 0 ;
F_26 ( V_64 , L_22 , V_66 ) ;
F_25 ( L_23 , V_64 , V_63 ) ;
F_27 ( V_63 , 60 ) ;
V_66 += 16 ;
}
}
if( V_65 != 0 ) {
F_26 ( V_64 , L_22 , V_66 ) ;
F_25 ( L_23 , V_64 , V_63 ) ;
}
F_25 ( L_24 ) ;
}
void F_28 ( T_5 * V_67 )
{
int V_7 ;
struct V_68 * V_69 ;
if ( V_67 == NULL ) {
return;
}
V_69 = V_67 -> V_70 ;
F_25 ( L_25 ) ;
F_25 ( L_26 , V_67 -> V_71 ) ;
F_25 ( L_27 , V_67 -> V_72 ) ;
F_25 ( L_28 , V_67 -> V_73 ) ;
F_25 ( L_29 ) ;
for ( V_7 = 0 ; V_7 < V_67 -> V_74 ; V_7 ++ , V_69 ++ ) {
F_25 ( L_30 , V_69 -> V_75 , V_69 -> V_76 ) ;
}
if ( 0 == V_7 ) {
F_25 ( L_31 ) ;
}
F_25 ( L_32 ) ;
F_25 ( L_33 , V_41 ) ;
F_25 ( L_34 , V_77 ) ;
F_25 ( L_35 , V_78 ) ;
F_25 ( L_36 , V_52 ) ;
F_25 ( L_37 ) ;
}
static T_5 * F_29 ( char * V_79 )
{
T_5 * V_67 = V_80 ;
if ( ! V_81 ) {
return NULL ;
}
while ( V_67 != NULL ) {
if ( memcmp ( V_67 -> V_71 , V_79 , strlen ( V_79 ) ) == 0 ) {
break;
}
V_67 = V_67 -> V_82 ;
}
return V_67 ;
}
void F_30 ( T_5 * V_67 )
{
if ( ! V_81 ) {
return;
}
F_31 ( & V_83 ) ;
if ( ! ( V_67 -> V_84 & V_85 ) ) {
if ( V_80 == NULL ) {
V_80 = V_67 ;
} else {
V_67 -> V_82 = V_80 ;
V_80 = V_67 ;
}
V_67 -> V_84 |= V_85 ;
}
F_32 ( & V_83 ) ;
}
void F_33 ( char * V_79 )
{
T_5 * V_67 = V_80 ;
if ( ! V_81 ) {
return;
}
if ( memcmp ( V_79 , L_38 , 3 ) == 0 ) {
while ( V_67 != NULL ) {
F_28 ( V_67 ) ;
V_67 = V_67 -> V_82 ;
}
return;
}
V_67 = F_29 ( V_79 ) ;
if ( V_67 != NULL ) {
F_28 ( V_67 ) ;
}
}
int F_34 ( char * V_79 , T_1 * V_86 )
{
T_5 * V_67 = F_29 ( V_79 ) ;
if ( NULL == V_67 ) {
return V_87 ;
}
* V_86 = V_67 -> V_73 ;
return 0 ;
}
int F_35 ( char * V_79 , T_1 V_75 )
{
T_5 * V_67 = F_29 ( V_79 ) ;
if ( NULL == V_67 ) {
return V_87 ;
}
V_67 -> V_73 = V_75 ;
F_25 ( L_39 , V_79 , V_67 -> V_73 ) ;
return 0 ;
}
void F_36 ( void )
{
if ( V_81 ) {
return;
}
F_37 ( & V_83 ) ;
V_80 = NULL ;
V_81 = true ;
F_38 ( V_88 ) ;
}
void F_39 ( void )
{
T_5 * V_67 = V_80 ;
T_5 * V_89 ;
if ( ! V_81 ) {
return;
}
V_81 = false ;
F_31 ( & V_83 ) ;
while ( V_67 != NULL ) {
V_89 = V_67 ;
V_67 = V_67 -> V_82 ;
V_89 -> V_82 = NULL ;
V_89 -> V_84 &= ~ V_85 ;
}
F_32 ( & V_83 ) ;
F_40 ( & V_83 ) ;
V_80 = NULL ;
}
int F_41 ( struct V_1 * V_2 ,
T_1 V_28 ,
T_1 V_84 )
{
int V_5 = 0 ;
do {
if ( V_28 != V_35 ) {
F_3 ( V_77 , ( L_40 ,
V_28 ) ) ;
break;
}
V_5 = F_23 ( V_2 ,
F_14 ( V_28 , V_90 ) ,
( T_2 * ) & V_84 ,
4 ) ;
} while ( false );
return V_5 ;
}
