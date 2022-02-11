static int F_1 ( T_1 * V_1 , int V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
if ( V_3 < V_2 )
V_1 [ V_3 ] = V_4 ;
else if ( V_3 == V_6 )
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
V_1 [ V_5 ] = V_4 ;
else
return - 1 ;
return 0 ;
}
int F_2 ( T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_7 , V_8 , V_3 , V_4 ) ;
}
int F_3 ( T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_9 ,
V_10 , V_3 , V_4 ) ;
}
static int F_4 ( char * V_11 , int V_12 , T_1 * V_13 ,
int V_14 , char * V_15 )
{
int V_16 = 0 ;
int V_5 ;
int V_17 ;
for ( V_16 = 0 , V_5 = 0 ; V_16 < V_12 - 2 && V_15 [ V_5 ] != '\0' ; V_5 ++ , V_16 ++ )
V_11 [ V_16 ] = V_15 [ V_5 ] ;
for ( V_5 = 0 ; V_16 < V_12 - 2 && V_5 < V_14 ; V_16 += V_17 , V_5 ++ )
V_17 = snprintf ( & V_11 [ V_16 ] , V_12 - V_16 - 1 , L_1 , V_13 [ V_5 ] ) ;
if ( V_5 < V_14 )
return - 1 ;
return 0 ;
}
void F_5 ( struct V_18 * V_19 , T_1 * V_20 , int V_17 )
{
struct V_21 * V_22 ;
static char V_23 [ V_24 ] ;
V_22 = (struct V_21 * ) V_20 ;
if ( V_17 < sizeof( V_22 -> V_25 ) + sizeof( V_22 -> V_26 . log . V_27 ) ) {
F_6 ( V_19 , V_28 , L_2
L_3 ,
V_17 , sizeof( V_22 -> V_25 ) + sizeof( V_22 -> V_26 . log . V_27 ) ) ;
return;
}
if ( ! ( V_9 [ V_22 -> V_26 . log . V_27 . V_29 ] &
F_7 ( V_22 -> V_26 . log . V_27 . V_30 ) ) ||
! ( V_7 [ V_31 ] & F_7 ( V_22 -> V_26 . log . V_27 . V_30 ) ) )
return;
switch ( V_22 -> V_25 . V_32 ) {
case V_33 :
if ( ! ( V_7 [ V_34 ] &
F_7 ( V_22 -> V_26 . log . V_27 . V_30 ) ) )
return;
if ( F_4 ( V_23 , V_24 , V_20 ,
F_8 ( V_22 -> V_25 . V_35 ) +
sizeof( V_22 -> V_25 ) , L_4 ) )
F_9 ( V_19 , V_36 ,
L_5 ) ;
F_9 ( V_19 , V_36 , L_6 , V_23 ) ;
break;
case V_37 :
if ( V_22 -> V_25 . V_38 == V_39 )
F_10 ( V_19 , V_28 , L_7 , L_8 ,
( ( T_1 * ) V_22 ) + sizeof( V_22 -> V_25 )
+ sizeof( V_22 -> V_26 . log . V_27 ) ) ;
else {
if ( F_4 ( V_23 , V_24 , V_20 ,
F_8 ( V_22 -> V_25 . V_35 )
+ sizeof( V_22 -> V_25 ) ,
L_8 ) )
F_9 ( V_19 , V_28 ,
L_9
L_10 ) ;
F_9 ( V_19 , V_28 , L_6 , V_23 ) ;
}
break;
default:
break;
}
}
static int F_11 ( T_1 * V_1 , int V_40 , char * V_20 , int V_2 )
{
int V_5 , V_16 , V_17 ;
for ( V_5 = 0 , V_16 = 0 ; ( V_16 < V_2 - 1 ) && ( V_5 < V_40 ) ; V_5 ++ ) {
V_17 = snprintf ( & V_20 [ V_16 ] , V_2 - V_16 - 1 , L_11 ,
V_5 , V_1 [ V_5 ] ) ;
V_16 += V_17 ;
}
V_20 [ V_16 - 1 ] = '\n' ;
V_20 [ V_16 ] = '\0' ;
if ( V_5 < V_40 )
return - 1 ;
return 0 ;
}
int F_12 ( char * V_20 , int V_2 )
{
return F_11 ( V_7 , V_8 , V_20 , V_2 ) ;
}
int F_13 ( char * V_20 , int V_2 )
{
return F_11 ( V_9 , V_10 , V_20 , V_2 ) ;
}
T_2 F_14 ( struct V_41 * V_42 ,
struct V_43 * V_44 , char * V_20 )
{
struct V_18 * V_19 = F_15 ( V_42 ) ;
char * V_45 ;
int V_46 ;
T_2 V_47 ;
V_46 = ( V_48 * V_8 ) + 1 ;
V_45 = F_16 ( V_46 , V_49 ) ;
if ( ! V_45 ) {
F_6 ( V_19 , V_50 ,
L_12 , V_46 ) ;
V_47 = - V_51 ;
goto exit;
}
if ( F_12 ( V_45 , V_46 ) < 0 ) {
V_47 = - V_52 ;
goto exit;
}
V_47 = sprintf ( V_20 , L_13 , V_45 ) ;
exit:
F_17 ( V_45 ) ;
return V_47 ;
}
T_2 F_18 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
const char * V_20 , T_3 V_53 )
{
struct V_18 * V_19 = F_15 ( V_42 ) ;
char * V_54 , * V_45 = NULL ;
long V_55 ;
T_2 V_47 = V_53 ;
T_1 V_3 , V_56 ;
if ( ! V_53 )
goto exit;
V_45 = F_16 ( V_53 , V_49 ) ;
if ( ! V_45 ) {
F_6 ( V_19 , V_50 ,
L_14 , V_53 ) ;
V_47 = - V_51 ;
goto exit;
}
memcpy ( V_45 , V_20 , V_53 ) ;
while ( ( V_54 = F_19 ( & V_45 , L_15 ) ) != NULL ) {
while ( isspace ( * V_54 ) )
++ V_54 ;
if ( F_20 ( V_54 , V_57 , & V_55 ) ) {
F_6 ( V_19 , V_50 ,
L_16 ,
V_54 ) ;
V_47 = - V_52 ;
goto exit;
}
V_56 = V_55 & 0xFF ;
V_3 = ( V_55 & 0XFF00 ) >> 8 ;
F_2 ( V_3 , V_56 ) ;
}
exit:
F_17 ( V_45 ) ;
return V_47 ;
}
T_2 F_21 ( struct V_41 * V_42 ,
struct V_43 * V_44 , char * V_20 )
{
struct V_18 * V_19 = F_15 ( V_42 ) ;
char * V_45 ;
int V_46 ;
T_2 V_47 ;
V_46 = ( V_48 * V_10 ) + 2 ;
V_45 = F_16 ( V_46 , V_49 ) ;
if ( ! V_45 ) {
F_6 ( V_19 , V_50 ,
L_12 , V_46 ) ;
V_47 = - V_51 ;
goto exit;
}
if ( F_13 ( V_45 , V_46 ) < 0 ) {
V_47 = - V_52 ;
goto exit;
}
V_47 = sprintf ( V_20 , L_13 , V_45 ) ;
exit:
F_17 ( V_45 ) ;
return V_47 ;
}
T_2 F_22 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
const char * V_20 , T_3 V_53 )
{
struct V_18 * V_19 = F_15 ( V_42 ) ;
struct V_21 V_58 ;
char * V_54 , * V_45 = NULL ;
T_2 V_47 = V_53 ;
T_4 V_59 = 0 ;
int V_5 ;
long V_55 ;
T_1 V_3 , V_56 ;
if ( ! V_53 )
goto exit;
V_45 = F_16 ( V_53 , V_49 ) ;
if ( ! V_45 ) {
F_6 ( V_19 , V_50 ,
L_14 , V_53 ) ;
V_47 = - V_51 ;
goto exit;
}
memcpy ( V_45 , V_20 , V_53 ) ;
V_58 . V_25 . type = V_60 ;
V_58 . V_25 . V_32 = V_37 ;
V_58 . V_25 . V_38 = V_61 ;
for ( V_5 = 0 ; ( ( V_54 = F_19 ( & V_45 , L_15 ) ) != NULL ) &&
( V_5 < V_10 ) ; V_5 ++ ) {
while ( isspace ( * V_54 ) )
++ V_54 ;
if ( F_20 ( V_54 , V_57 , & V_55 ) ) {
F_6 ( V_19 , V_50 ,
L_16 ,
V_54 ) ;
V_47 = - V_52 ;
goto exit;
}
V_56 = V_55 & 0xFF ;
V_3 = ( V_55 & 0XFF00 ) >> 8 ;
F_3 ( V_3 , V_56 ) ;
V_58 . V_26 . V_1 [ V_5 ] . V_29 = V_3 ;
V_58 . V_26 . V_1 [ V_5 ] . V_62 = V_56 ;
}
V_58 . V_25 . V_35 = F_23 ( V_5 * sizeof( V_58 . V_26 . V_1 [ 0 ] ) ) ;
V_59 = ( V_5 * sizeof( V_58 . V_26 . V_1 [ 0 ] ) + sizeof( V_58 . V_25 ) ) ;
V_47 = F_24 ( V_19 , ( T_1 * ) & V_58 , V_59 ) ;
if ( V_47 ) {
F_6 ( V_19 , V_50 ,
L_17 ,
V_59 , V_47 ) ;
goto exit;
} else
F_10 ( V_19 , V_50 , L_18 , V_59 ) ;
V_47 = V_53 ;
exit:
F_17 ( V_45 ) ;
return V_47 ;
}
