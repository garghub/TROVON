static unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
if ( V_1 & 0x80 )
V_1 = 0x9 + ( V_1 & 0x0f ) ;
else if ( V_1 <= 0x0f ) ;
else if ( V_1 == 0x41 )
V_1 = 0x9 + 0x1 ;
else if ( V_1 == 0xff )
V_1 = 0x00 ;
return ( V_2 & 3 ) * ( 0x9 + 0x9 ) + V_1 ;
}
static void F_2 ( T_1 * V_3 )
{
unsigned V_4 ;
for ( V_3 -> V_5 ++ , V_4 = 1 ; V_4 ; ) {
V_3 -> V_5 ++ ;
switch ( V_6 ) {
case V_7 :
V_4 ++ ;
break;
case V_8 :
V_4 -- ;
break;
}
}
}
static void F_3 ( T_1 * V_3 )
{
for (; V_6 != V_8 ; V_3 -> V_5 ++ ) {
switch ( V_6 ) {
case V_9 :
F_4 ( V_3 -> V_10 + V_3 -> V_11 , V_12 ) ;
V_3 -> V_11 ++ ;
break;
case V_13 :
F_5 ( V_3 -> V_10 + V_3 -> V_11 , V_12 ) ;
V_3 -> V_11 += 2 ;
break;
case V_14 :
F_6 ( V_3 -> V_10 + V_3 -> V_11 , V_12 ) ;
V_3 -> V_11 += 4 ;
break;
case V_15 :
if ( * ( V_16 * * ) V_12 == NULL ) {
* ( V_3 -> V_10 + V_3 -> V_11 ) = '\0' ;
V_3 -> V_11 ++ ;
} else if ( * * ( V_17 * ) V_12 != 0xff ) {
F_7 ( V_3 -> V_10 + V_3 -> V_11 , * ( V_17 * ) V_12 , 1 + * * ( V_17 * ) V_12 ) ;
V_3 -> V_11 += 1 + * * ( V_17 * ) V_12 ;
} else {
V_17 V_18 = * ( V_17 * ) V_12 ;
F_7 ( V_3 -> V_10 + V_3 -> V_11 , V_18 , 3 + * ( V_19 * ) ( V_18 + 1 ) ) ;
V_3 -> V_11 += 3 + * ( V_19 * ) ( V_18 + 1 ) ;
}
break;
case V_7 :
if ( * ( V_20 * ) V_12 == V_21 ) {
* ( V_3 -> V_10 + V_3 -> V_11 ) = '\0' ;
V_3 -> V_11 ++ ;
F_2 ( V_3 ) ;
}
else {
unsigned V_22 = V_3 -> V_11 ;
unsigned V_23 ;
V_3 -> V_11 ++ ;
V_3 -> V_5 ++ ;
F_3 ( V_3 ) ;
V_23 = V_3 -> V_11 - V_22 - 1 ;
if ( V_23 < 255 )
( V_3 -> V_10 + V_22 ) [ 0 ] = ( V_16 ) V_23 ;
else {
F_8 ( V_3 -> V_10 + V_22 + 3 , V_3 -> V_10 + V_22 + 1 , V_23 ) ;
( V_3 -> V_10 + V_22 ) [ 0 ] = 0xff ;
F_5 ( V_3 -> V_10 + V_22 + 1 , & V_23 ) ;
}
}
break;
}
}
}
unsigned F_9 ( T_1 * V_3 , V_16 * V_24 )
{
V_3 -> V_10 = V_24 ;
V_3 -> V_11 = 8 ;
V_3 -> V_5 = 0 ;
V_3 -> V_25 = V_26 [ F_1 ( V_3 -> V_27 , V_3 -> V_28 ) ] ;
F_3 ( V_3 ) ;
F_5 ( V_24 + 0 , & V_3 -> V_11 ) ;
F_4 ( V_3 -> V_10 + 4 , & V_3 -> V_27 ) ;
F_4 ( V_3 -> V_10 + 5 , & V_3 -> V_28 ) ;
F_5 ( V_3 -> V_10 + 2 , & V_3 -> V_29 ) ;
F_5 ( V_3 -> V_10 + 6 , & V_3 -> V_30 ) ;
return 0 ;
}
static void F_10 ( T_1 * V_3 )
{
for (; V_6 != V_8 ; V_3 -> V_5 ++ ) {
switch ( V_6 ) {
case V_9 :
F_11 ( V_3 -> V_10 + V_3 -> V_11 , V_12 ) ;
V_3 -> V_11 ++ ;
break;
case V_13 :
F_12 ( V_3 -> V_10 + V_3 -> V_11 , V_12 ) ;
V_3 -> V_11 += 2 ;
break;
case V_14 :
F_13 ( V_3 -> V_10 + V_3 -> V_11 , V_12 ) ;
V_3 -> V_11 += 4 ;
break;
case V_15 :
* ( V_16 * * ) V_12 = V_3 -> V_10 + V_3 -> V_11 ;
if ( V_3 -> V_10 [ V_3 -> V_11 ] != 0xff )
V_3 -> V_11 += 1 + V_3 -> V_10 [ V_3 -> V_11 ] ;
else
V_3 -> V_11 += 3 + * ( V_19 * ) ( V_3 -> V_10 + V_3 -> V_11 + 1 ) ;
break;
case V_7 :
if ( V_3 -> V_10 [ V_3 -> V_11 ] == '\0' ) {
* ( V_20 * ) V_12 = V_21 ;
V_3 -> V_11 ++ ;
F_2 ( V_3 ) ;
} else {
unsigned V_22 = V_3 -> V_11 ;
* ( V_20 * ) V_12 = V_31 ;
V_3 -> V_11 = ( V_3 -> V_10 + V_22 ) [ 0 ] == 255 ? V_3 -> V_11 + 3 : V_3 -> V_11 + 1 ;
V_3 -> V_5 ++ ;
F_10 ( V_3 ) ;
}
break;
}
}
}
unsigned F_14 ( T_1 * V_3 , V_16 * V_24 )
{
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
V_3 -> V_10 = V_24 ;
V_3 -> V_11 = 8 ;
V_3 -> V_5 = 0 ;
F_11 ( V_3 -> V_10 + 4 , & V_3 -> V_27 ) ;
F_11 ( V_3 -> V_10 + 5 , & V_3 -> V_28 ) ;
V_3 -> V_25 = V_26 [ F_1 ( V_3 -> V_27 , V_3 -> V_28 ) ] ;
F_10 ( V_3 ) ;
F_12 ( V_24 + 0 , & V_3 -> V_11 ) ;
F_12 ( V_3 -> V_10 + 2 , & V_3 -> V_29 ) ;
F_12 ( V_3 -> V_10 + 6 , & V_3 -> V_30 ) ;
return 0 ;
}
unsigned F_15 ( T_1 * V_3 , V_19 V_32 ,
V_16 V_33 , V_16 V_34 ,
V_19 V_35 , T_2 V_36 )
{
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
V_3 -> V_29 = V_32 ;
V_3 -> V_27 = V_33 ;
V_3 -> V_28 = V_34 ;
V_3 -> V_30 = V_35 ;
V_3 -> V_37 . V_38 = V_36 ;
return 0 ;
}
char * F_16 ( V_16 V_39 , V_16 V_40 )
{
return V_41 [ F_1 ( V_39 , V_40 ) ] ;
}
static T_3 * F_17 ( T_3 * V_42 , char * V_43 , ... )
{
T_4 V_44 ;
T_5 V_45 , V_46 ;
if ( ! V_42 )
return NULL ;
va_start ( V_44 , V_43 ) ;
V_46 = V_42 -> V_47 - V_42 -> V_48 ;
V_45 = vsnprintf ( V_42 -> V_5 , V_46 , V_43 , V_44 ) ;
va_end ( V_44 ) ;
if ( V_45 >= V_46 ) {
T_5 V_49 = 2 * V_42 -> V_47 ;
T_6 * V_50 ;
while ( ( V_49 - V_42 -> V_48 ) <= V_45 )
V_49 *= 2 ;
V_50 = F_18 ( V_49 , V_51 ) ;
if ( ! V_50 ) {
F_19 ( V_42 ) ;
return NULL ;
}
memcpy ( V_50 , V_42 -> V_52 , V_42 -> V_48 ) ;
F_20 ( V_42 -> V_52 ) ;
V_50 [ V_42 -> V_48 ] = 0 ;
V_42 -> V_52 = V_50 ;
V_42 -> V_5 = V_42 -> V_52 + V_42 -> V_48 ;
V_42 -> V_47 = V_49 ;
va_start ( V_44 , V_43 ) ;
V_46 = V_42 -> V_47 - V_42 -> V_48 ;
V_45 = vsnprintf ( V_42 -> V_5 , V_46 , V_43 , V_44 ) ;
va_end ( V_44 ) ;
}
V_42 -> V_5 += V_45 ;
V_42 -> V_48 += V_45 ;
return V_42 ;
}
static T_3 * F_21 ( T_3 * V_42 , V_16 * V_10 , unsigned V_53 )
{
unsigned V_54 = 0 ;
if ( ! V_42 )
return NULL ;
for (; V_53 ; V_53 -- , V_10 ++ )
if ( isalnum ( * V_10 ) || * V_10 == ' ' ) {
if ( V_54 )
V_42 = F_17 ( V_42 , L_1 ) ;
V_42 = F_17 ( V_42 , L_2 , * V_10 ) ;
V_54 = 0 ;
} else {
if ( ! V_54 )
V_42 = F_17 ( V_42 , L_3 , * V_10 ) ;
else
V_42 = F_17 ( V_42 , L_4 , * V_10 ) ;
V_54 = 1 ;
}
if ( V_54 )
V_42 = F_17 ( V_42 , L_1 ) ;
return V_42 ;
}
static T_3 * F_22 ( T_3 * V_42 , V_16 * V_10 )
{
unsigned V_53 ;
if ( V_10 [ 0 ] != 0xff ) {
V_53 = V_10 [ 0 ] ;
V_10 += 1 ;
} else {
V_53 = ( ( V_19 * ) ( V_10 + 1 ) ) [ 0 ] ;
V_10 += 3 ;
}
V_42 = F_21 ( V_42 , V_10 , V_53 ) ;
return V_42 ;
}
static T_3 * F_23 ( T_3 * V_42 , T_1 * V_3 , int V_55 )
{
for (; V_6 != V_8 ; V_3 -> V_5 ++ ) {
int V_56 = 29 + 3 - V_55 ;
int V_57 ;
if ( ! V_42 )
return NULL ;
V_42 = F_17 ( V_42 , L_5 ) ;
for ( V_57 = 0 ; V_57 < V_55 - 1 ; V_57 ++ )
V_42 = F_17 ( V_42 , L_6 ) ;
switch ( V_6 ) {
case V_9 :
V_42 = F_17 ( V_42 , L_7 , V_56 , V_58 , * ( V_16 * ) ( V_3 -> V_10 + V_3 -> V_11 ) ) ;
V_3 -> V_11 ++ ;
break;
case V_13 :
V_42 = F_17 ( V_42 , L_7 , V_56 , V_58 , * ( V_19 * ) ( V_3 -> V_10 + V_3 -> V_11 ) ) ;
V_3 -> V_11 += 2 ;
break;
case V_14 :
V_42 = F_17 ( V_42 , L_8 , V_56 , V_58 , * ( T_2 * ) ( V_3 -> V_10 + V_3 -> V_11 ) ) ;
V_3 -> V_11 += 4 ;
break;
case V_15 :
V_42 = F_17 ( V_42 , L_9 , V_56 , V_58 ) ;
if ( V_3 -> V_10 [ V_3 -> V_11 ] == '\0' )
V_42 = F_17 ( V_42 , L_10 ) ;
else
V_42 = F_22 ( V_42 , V_3 -> V_10 + V_3 -> V_11 ) ;
V_42 = F_17 ( V_42 , L_11 ) ;
if ( V_3 -> V_10 [ V_3 -> V_11 ] != 0xff )
V_3 -> V_11 += 1 + V_3 -> V_10 [ V_3 -> V_11 ] ;
else
V_3 -> V_11 += 3 + * ( V_19 * ) ( V_3 -> V_10 + V_3 -> V_11 + 1 ) ;
break;
case V_7 :
if ( V_3 -> V_10 [ V_3 -> V_11 ] == '\0' ) {
V_42 = F_17 ( V_42 , L_12 , V_56 , V_58 ) ;
V_3 -> V_11 ++ ;
F_2 ( V_3 ) ;
} else {
char * V_59 = V_58 ;
unsigned V_22 = V_3 -> V_11 ;
V_42 = F_17 ( V_42 , L_13 , V_56 , V_59 ) ;
V_3 -> V_11 = ( V_3 -> V_10 + V_22 ) [ 0 ] == 255 ? V_3 -> V_11 + 3 : V_3 -> V_11 + 1 ;
V_3 -> V_5 ++ ;
V_42 = F_23 ( V_42 , V_3 , V_55 + 1 ) ;
}
break;
}
}
return V_42 ;
}
static T_3 * F_24 ( void )
{
T_3 * V_42 ;
if ( F_25 ( ! F_26 ( 1 , & V_60 ) ) ) {
V_42 = V_61 ;
goto V_62;
} else
V_42 = F_18 ( sizeof( T_3 ) , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_52 = F_18 ( V_63 , V_51 ) ;
if ( ! V_42 -> V_52 ) {
F_20 ( V_42 ) ;
return NULL ;
}
V_42 -> V_47 = V_63 ;
V_62:
V_42 -> V_52 [ 0 ] = 0 ;
V_42 -> V_5 = V_42 -> V_52 ;
V_42 -> V_48 = 0 ;
return V_42 ;
}
void F_19 ( T_3 * V_42 )
{
if ( F_25 ( V_42 == V_61 ) ) {
F_27 ( 1 , & V_60 ) ;
return;
}
if ( F_25 ( V_42 ) )
F_20 ( V_42 -> V_52 ) ;
F_20 ( V_42 ) ;
}
T_3 * F_28 ( V_16 * V_24 )
{
T_3 * V_42 ;
T_1 * V_3 ;
V_42 = F_24 () ;
if ( F_29 ( ! V_42 ) )
return NULL ;
if ( F_25 ( V_42 == V_61 ) )
V_3 = V_64 ;
else
V_3 = F_18 ( sizeof( T_1 ) , V_51 ) ;
if ( F_29 ( ! V_3 ) ) {
F_19 ( V_42 ) ;
return NULL ;
}
V_3 -> V_10 = V_24 ;
V_3 -> V_11 = 8 ;
V_3 -> V_5 = 0 ;
F_11 ( V_3 -> V_10 + 4 , & V_3 -> V_27 ) ;
F_11 ( V_3 -> V_10 + 5 , & V_3 -> V_28 ) ;
V_3 -> V_25 = V_26 [ F_1 ( V_3 -> V_27 , V_3 -> V_28 ) ] ;
V_42 = F_17 ( V_42 , L_14 ,
V_41 [ F_1 ( V_3 -> V_27 , V_3 -> V_28 ) ] ,
( ( unsigned short * ) V_24 ) [ 1 ] ,
( ( unsigned short * ) V_24 ) [ 3 ] ,
( ( unsigned short * ) V_24 ) [ 0 ] ) ;
V_42 = F_23 ( V_42 , V_3 , 1 ) ;
if ( F_29 ( V_3 != V_64 ) )
F_20 ( V_3 ) ;
return V_42 ;
}
T_3 * F_30 ( T_1 * V_3 )
{
T_3 * V_42 ;
if ( ! V_3 -> V_10 )
return NULL ;
V_42 = F_24 () ;
if ( ! V_42 )
return NULL ;
V_3 -> V_11 = 8 ;
V_3 -> V_5 = 0 ;
V_42 = F_17 ( V_42 , L_15 ,
V_41 [ F_1 ( V_3 -> V_27 , V_3 -> V_28 ) ] ,
( ( V_19 * ) V_3 -> V_10 ) [ 1 ] ,
( ( V_19 * ) V_3 -> V_10 ) [ 3 ] ,
( ( V_19 * ) V_3 -> V_10 ) [ 0 ] ) ;
V_42 = F_23 ( V_42 , V_3 , 1 ) ;
return V_42 ;
}
int T_7 F_31 ( void )
{
V_64 = F_18 ( sizeof( T_1 ) , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_61 = F_18 ( sizeof( T_3 ) , V_65 ) ;
if ( ! V_61 ) {
F_20 ( V_64 ) ;
return - V_66 ;
}
V_61 -> V_52 = F_18 ( V_67 , V_65 ) ;
if ( ! V_61 -> V_52 ) {
F_20 ( V_64 ) ;
F_20 ( V_61 ) ;
return - V_66 ;
}
V_61 -> V_47 = V_67 ;
V_61 -> V_52 [ 0 ] = 0 ;
V_61 -> V_5 = V_61 -> V_52 ;
V_61 -> V_48 = 0 ;
return 0 ;
}
void T_8 F_32 ( void )
{
if ( V_61 )
F_20 ( V_61 -> V_52 ) ;
F_20 ( V_61 ) ;
F_20 ( V_64 ) ;
}
T_3 * F_28 ( V_16 * V_24 )
{
return & V_61 ;
}
T_3 * F_30 ( T_1 * V_3 )
{
return & V_61 ;
}
void F_19 ( T_3 * V_42 )
{
}
int T_7 F_31 ( void )
{
return 0 ;
}
void T_8 F_32 ( void )
{
}
