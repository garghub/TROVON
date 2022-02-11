static unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
if ( V_1 & 0x80 )
V_1 = 0x9 + ( V_1 & 0x0f ) ;
else if ( V_1 == 0x41 )
V_1 = 0x9 + 0x1 ;
if ( V_1 > 0x18 )
V_1 = 0x00 ;
return ( V_2 & 3 ) * ( 0x9 + 0x9 ) + V_1 ;
}
static unsigned char * F_2 ( T_1 V_3 , T_1 V_4 )
{
return V_5 [ F_1 ( V_3 , V_4 ) ] ;
}
static void F_3 ( T_2 * V_6 )
{
unsigned V_7 ;
for ( V_6 -> V_8 ++ , V_7 = 1 ; V_7 ; ) {
V_6 -> V_8 ++ ;
switch ( V_9 ) {
case V_10 :
V_7 ++ ;
break;
case V_11 :
V_7 -- ;
break;
}
}
}
static void F_4 ( T_2 * V_6 )
{
for (; V_9 != V_11 ; V_6 -> V_8 ++ ) {
switch ( V_9 ) {
case V_12 :
F_5 ( V_6 -> V_13 + V_6 -> V_14 , V_15 ) ;
V_6 -> V_14 ++ ;
break;
case V_16 :
F_6 ( V_6 -> V_13 + V_6 -> V_14 , V_15 ) ;
V_6 -> V_14 += 2 ;
break;
case V_17 :
F_7 ( V_6 -> V_13 + V_6 -> V_14 , V_15 ) ;
V_6 -> V_14 += 4 ;
break;
case V_18 :
if ( * ( T_1 * * ) V_15 == NULL ) {
* ( V_6 -> V_13 + V_6 -> V_14 ) = '\0' ;
V_6 -> V_14 ++ ;
} else if ( * * ( V_19 * ) V_15 != 0xff ) {
F_8 ( V_6 -> V_13 + V_6 -> V_14 , * ( V_19 * ) V_15 , 1 + * * ( V_19 * ) V_15 ) ;
V_6 -> V_14 += 1 + * * ( V_19 * ) V_15 ;
} else {
V_19 V_20 = * ( V_19 * ) V_15 ;
F_8 ( V_6 -> V_13 + V_6 -> V_14 , V_20 , 3 + * ( V_21 * ) ( V_20 + 1 ) ) ;
V_6 -> V_14 += 3 + * ( V_21 * ) ( V_20 + 1 ) ;
}
break;
case V_10 :
if ( * ( V_22 * ) V_15 == V_23 ) {
* ( V_6 -> V_13 + V_6 -> V_14 ) = '\0' ;
V_6 -> V_14 ++ ;
F_3 ( V_6 ) ;
}
else {
unsigned V_24 = V_6 -> V_14 ;
unsigned V_25 ;
V_6 -> V_14 ++ ;
V_6 -> V_8 ++ ;
F_4 ( V_6 ) ;
V_25 = V_6 -> V_14 - V_24 - 1 ;
if ( V_25 < 255 )
( V_6 -> V_13 + V_24 ) [ 0 ] = ( T_1 ) V_25 ;
else {
F_9 ( V_6 -> V_13 + V_24 + 3 , V_6 -> V_13 + V_24 + 1 , V_25 ) ;
( V_6 -> V_13 + V_24 ) [ 0 ] = 0xff ;
F_6 ( V_6 -> V_13 + V_24 + 1 , & V_25 ) ;
}
}
break;
}
}
}
unsigned F_10 ( T_2 * V_6 , T_1 * V_26 )
{
V_6 -> V_13 = V_26 ;
V_6 -> V_14 = 8 ;
V_6 -> V_8 = 0 ;
V_6 -> V_27 = F_2 ( V_6 -> V_28 , V_6 -> V_29 ) ;
if ( ! V_6 -> V_27 )
return 1 ;
F_4 ( V_6 ) ;
F_6 ( V_26 + 0 , & V_6 -> V_14 ) ;
F_5 ( V_6 -> V_13 + 4 , & V_6 -> V_28 ) ;
F_5 ( V_6 -> V_13 + 5 , & V_6 -> V_29 ) ;
F_6 ( V_6 -> V_13 + 2 , & V_6 -> V_30 ) ;
F_6 ( V_6 -> V_13 + 6 , & V_6 -> V_31 ) ;
return 0 ;
}
static void F_11 ( T_2 * V_6 )
{
for (; V_9 != V_11 ; V_6 -> V_8 ++ ) {
switch ( V_9 ) {
case V_12 :
F_12 ( V_6 -> V_13 + V_6 -> V_14 , V_15 ) ;
V_6 -> V_14 ++ ;
break;
case V_16 :
F_13 ( V_6 -> V_13 + V_6 -> V_14 , V_15 ) ;
V_6 -> V_14 += 2 ;
break;
case V_17 :
F_14 ( V_6 -> V_13 + V_6 -> V_14 , V_15 ) ;
V_6 -> V_14 += 4 ;
break;
case V_18 :
* ( T_1 * * ) V_15 = V_6 -> V_13 + V_6 -> V_14 ;
if ( V_6 -> V_13 [ V_6 -> V_14 ] != 0xff )
V_6 -> V_14 += 1 + V_6 -> V_13 [ V_6 -> V_14 ] ;
else
V_6 -> V_14 += 3 + * ( V_21 * ) ( V_6 -> V_13 + V_6 -> V_14 + 1 ) ;
break;
case V_10 :
if ( V_6 -> V_13 [ V_6 -> V_14 ] == '\0' ) {
* ( V_22 * ) V_15 = V_23 ;
V_6 -> V_14 ++ ;
F_3 ( V_6 ) ;
} else {
unsigned V_24 = V_6 -> V_14 ;
* ( V_22 * ) V_15 = V_32 ;
V_6 -> V_14 = ( V_6 -> V_13 + V_24 ) [ 0 ] == 255 ? V_6 -> V_14 + 3 : V_6 -> V_14 + 1 ;
V_6 -> V_8 ++ ;
F_11 ( V_6 ) ;
}
break;
}
}
}
unsigned F_15 ( T_2 * V_6 , T_1 * V_26 )
{
memset ( V_6 , 0 , sizeof( T_2 ) ) ;
V_6 -> V_13 = V_26 ;
V_6 -> V_14 = 8 ;
V_6 -> V_8 = 0 ;
F_12 ( V_6 -> V_13 + 4 , & V_6 -> V_28 ) ;
F_12 ( V_6 -> V_13 + 5 , & V_6 -> V_29 ) ;
V_6 -> V_27 = F_2 ( V_6 -> V_28 , V_6 -> V_29 ) ;
if ( ! V_6 -> V_27 )
return 1 ;
F_11 ( V_6 ) ;
F_13 ( V_26 + 0 , & V_6 -> V_14 ) ;
F_13 ( V_6 -> V_13 + 2 , & V_6 -> V_30 ) ;
F_13 ( V_6 -> V_13 + 6 , & V_6 -> V_31 ) ;
return 0 ;
}
unsigned F_16 ( T_2 * V_6 , V_21 V_33 ,
T_1 V_34 , T_1 V_35 ,
V_21 V_36 , T_3 V_37 )
{
memset ( V_6 , 0 , sizeof( T_2 ) ) ;
V_6 -> V_30 = V_33 ;
V_6 -> V_28 = V_34 ;
V_6 -> V_29 = V_35 ;
V_6 -> V_31 = V_36 ;
V_6 -> V_38 . V_39 = V_37 ;
return 0 ;
}
char * F_17 ( T_1 V_3 , T_1 V_4 )
{
char * V_40 ;
V_40 = V_41 [ F_1 ( V_3 , V_4 ) ] ;
if ( V_40 == NULL )
V_40 = L_1 ;
return V_40 ;
}
static T_4 * F_18 ( T_4 * V_42 , char * V_43 , ... )
{
T_5 V_44 ;
T_6 V_45 , V_46 ;
if ( ! V_42 )
return NULL ;
va_start ( V_44 , V_43 ) ;
V_46 = V_42 -> V_47 - V_42 -> V_48 ;
V_45 = vsnprintf ( V_42 -> V_8 , V_46 , V_43 , V_44 ) ;
va_end ( V_44 ) ;
if ( V_45 >= V_46 ) {
T_6 V_49 = 2 * V_42 -> V_47 ;
T_7 * V_50 ;
while ( ( V_49 - V_42 -> V_48 ) <= V_45 )
V_49 *= 2 ;
V_50 = F_19 ( V_49 , V_51 ) ;
if ( ! V_50 ) {
F_20 ( V_42 ) ;
return NULL ;
}
memcpy ( V_50 , V_42 -> V_52 , V_42 -> V_48 ) ;
F_21 ( V_42 -> V_52 ) ;
V_50 [ V_42 -> V_48 ] = 0 ;
V_42 -> V_52 = V_50 ;
V_42 -> V_8 = V_42 -> V_52 + V_42 -> V_48 ;
V_42 -> V_47 = V_49 ;
va_start ( V_44 , V_43 ) ;
V_46 = V_42 -> V_47 - V_42 -> V_48 ;
V_45 = vsnprintf ( V_42 -> V_8 , V_46 , V_43 , V_44 ) ;
va_end ( V_44 ) ;
}
V_42 -> V_8 += V_45 ;
V_42 -> V_48 += V_45 ;
return V_42 ;
}
static T_4 * F_22 ( T_4 * V_42 , T_1 * V_13 , unsigned V_53 )
{
unsigned V_54 = 0 ;
if ( ! V_42 )
return NULL ;
for (; V_53 ; V_53 -- , V_13 ++ )
if ( isalnum ( * V_13 ) || * V_13 == ' ' ) {
if ( V_54 )
V_42 = F_18 ( V_42 , L_2 ) ;
V_42 = F_18 ( V_42 , L_3 , * V_13 ) ;
V_54 = 0 ;
} else {
if ( ! V_54 )
V_42 = F_18 ( V_42 , L_4 , * V_13 ) ;
else
V_42 = F_18 ( V_42 , L_5 , * V_13 ) ;
V_54 = 1 ;
}
if ( V_54 )
V_42 = F_18 ( V_42 , L_2 ) ;
return V_42 ;
}
static T_4 * F_23 ( T_4 * V_42 , T_1 * V_13 )
{
unsigned V_53 ;
if ( V_13 [ 0 ] != 0xff ) {
V_53 = V_13 [ 0 ] ;
V_13 += 1 ;
} else {
V_53 = ( ( V_21 * ) ( V_13 + 1 ) ) [ 0 ] ;
V_13 += 3 ;
}
V_42 = F_22 ( V_42 , V_13 , V_53 ) ;
return V_42 ;
}
static T_4 * F_24 ( T_4 * V_42 , T_2 * V_6 , int V_55 )
{
if ( ! V_6 -> V_27 )
return NULL ;
for (; V_9 != V_11 ; V_6 -> V_8 ++ ) {
int V_56 = 29 + 3 - V_55 ;
int V_57 ;
if ( ! V_42 )
return NULL ;
V_42 = F_18 ( V_42 , L_6 ) ;
for ( V_57 = 0 ; V_57 < V_55 - 1 ; V_57 ++ )
V_42 = F_18 ( V_42 , L_7 ) ;
switch ( V_9 ) {
case V_12 :
V_42 = F_18 ( V_42 , L_8 , V_56 , V_58 , * ( T_1 * ) ( V_6 -> V_13 + V_6 -> V_14 ) ) ;
V_6 -> V_14 ++ ;
break;
case V_16 :
V_42 = F_18 ( V_42 , L_8 , V_56 , V_58 , * ( V_21 * ) ( V_6 -> V_13 + V_6 -> V_14 ) ) ;
V_6 -> V_14 += 2 ;
break;
case V_17 :
V_42 = F_18 ( V_42 , L_9 , V_56 , V_58 , * ( T_3 * ) ( V_6 -> V_13 + V_6 -> V_14 ) ) ;
V_6 -> V_14 += 4 ;
break;
case V_18 :
V_42 = F_18 ( V_42 , L_10 , V_56 , V_58 ) ;
if ( V_6 -> V_13 [ V_6 -> V_14 ] == '\0' )
V_42 = F_18 ( V_42 , L_11 ) ;
else
V_42 = F_23 ( V_42 , V_6 -> V_13 + V_6 -> V_14 ) ;
V_42 = F_18 ( V_42 , L_12 ) ;
if ( V_6 -> V_13 [ V_6 -> V_14 ] != 0xff )
V_6 -> V_14 += 1 + V_6 -> V_13 [ V_6 -> V_14 ] ;
else
V_6 -> V_14 += 3 + * ( V_21 * ) ( V_6 -> V_13 + V_6 -> V_14 + 1 ) ;
break;
case V_10 :
if ( V_6 -> V_13 [ V_6 -> V_14 ] == '\0' ) {
V_42 = F_18 ( V_42 , L_13 , V_56 , V_58 ) ;
V_6 -> V_14 ++ ;
F_3 ( V_6 ) ;
} else {
char * V_59 = V_58 ;
unsigned V_24 = V_6 -> V_14 ;
V_42 = F_18 ( V_42 , L_14 , V_56 , V_59 ) ;
V_6 -> V_14 = ( V_6 -> V_13 + V_24 ) [ 0 ] == 255 ? V_6 -> V_14 + 3 : V_6 -> V_14 + 1 ;
V_6 -> V_8 ++ ;
V_42 = F_24 ( V_42 , V_6 , V_55 + 1 ) ;
}
break;
}
}
return V_42 ;
}
static T_4 * F_25 ( void )
{
T_4 * V_42 ;
if ( F_26 ( ! F_27 ( 1 , & V_60 ) ) ) {
V_42 = V_61 ;
goto V_62;
} else
V_42 = F_19 ( sizeof( T_4 ) , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_52 = F_19 ( V_63 , V_51 ) ;
if ( ! V_42 -> V_52 ) {
F_21 ( V_42 ) ;
return NULL ;
}
V_42 -> V_47 = V_63 ;
V_62:
V_42 -> V_52 [ 0 ] = 0 ;
V_42 -> V_8 = V_42 -> V_52 ;
V_42 -> V_48 = 0 ;
return V_42 ;
}
void F_20 ( T_4 * V_42 )
{
if ( F_26 ( V_42 == V_61 ) ) {
F_28 ( 1 , & V_60 ) ;
return;
}
if ( F_26 ( V_42 ) )
F_21 ( V_42 -> V_52 ) ;
F_21 ( V_42 ) ;
}
T_4 * F_29 ( T_1 * V_26 )
{
T_4 * V_42 ;
T_2 * V_6 ;
V_42 = F_25 () ;
if ( F_30 ( ! V_42 ) )
return NULL ;
if ( F_26 ( V_42 == V_61 ) )
V_6 = V_64 ;
else
V_6 = F_19 ( sizeof( T_2 ) , V_51 ) ;
if ( F_30 ( ! V_6 ) ) {
F_20 ( V_42 ) ;
return NULL ;
}
V_6 -> V_13 = V_26 ;
V_6 -> V_14 = 8 ;
V_6 -> V_8 = 0 ;
F_12 ( V_6 -> V_13 + 4 , & V_6 -> V_28 ) ;
F_12 ( V_6 -> V_13 + 5 , & V_6 -> V_29 ) ;
V_6 -> V_27 = F_2 ( V_6 -> V_28 , V_6 -> V_29 ) ;
V_42 = F_18 ( V_42 , L_15 ,
F_17 ( V_6 -> V_28 , V_6 -> V_29 ) ,
( ( unsigned short * ) V_26 ) [ 1 ] ,
( ( unsigned short * ) V_26 ) [ 3 ] ,
( ( unsigned short * ) V_26 ) [ 0 ] ) ;
V_42 = F_24 ( V_42 , V_6 , 1 ) ;
if ( F_30 ( V_6 != V_64 ) )
F_21 ( V_6 ) ;
return V_42 ;
}
T_4 * F_31 ( T_2 * V_6 )
{
T_4 * V_42 ;
if ( ! V_6 -> V_13 )
return NULL ;
V_42 = F_25 () ;
if ( ! V_42 )
return NULL ;
V_6 -> V_14 = 8 ;
V_6 -> V_8 = 0 ;
V_42 = F_18 ( V_42 , L_16 ,
F_17 ( V_6 -> V_28 , V_6 -> V_29 ) ,
( ( V_21 * ) V_6 -> V_13 ) [ 1 ] ,
( ( V_21 * ) V_6 -> V_13 ) [ 3 ] ,
( ( V_21 * ) V_6 -> V_13 ) [ 0 ] ) ;
V_42 = F_24 ( V_42 , V_6 , 1 ) ;
return V_42 ;
}
int T_8 F_32 ( void )
{
V_64 = F_19 ( sizeof( T_2 ) , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_61 = F_19 ( sizeof( T_4 ) , V_65 ) ;
if ( ! V_61 ) {
F_21 ( V_64 ) ;
return - V_66 ;
}
V_61 -> V_52 = F_19 ( V_67 , V_65 ) ;
if ( ! V_61 -> V_52 ) {
F_21 ( V_64 ) ;
F_21 ( V_61 ) ;
return - V_66 ;
}
V_61 -> V_47 = V_67 ;
V_61 -> V_52 [ 0 ] = 0 ;
V_61 -> V_8 = V_61 -> V_52 ;
V_61 -> V_48 = 0 ;
return 0 ;
}
void T_9 F_33 ( void )
{
if ( V_61 )
F_21 ( V_61 -> V_52 ) ;
F_21 ( V_61 ) ;
F_21 ( V_64 ) ;
}
T_4 * F_29 ( T_1 * V_26 )
{
return & V_61 ;
}
T_4 * F_31 ( T_2 * V_6 )
{
return & V_61 ;
}
void F_20 ( T_4 * V_42 )
{
}
int T_8 F_32 ( void )
{
return 0 ;
}
void T_9 F_33 ( void )
{
}
