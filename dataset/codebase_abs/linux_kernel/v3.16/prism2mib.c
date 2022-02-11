int F_1 ( T_1 * V_1 , void * V_2 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_5 , V_6 ;
struct V_7 * V_8 ;
T_3 V_9 ;
struct V_10 * V_11 = V_2 ;
T_4 * V_12 ;
V_11 -> V_13 . V_14 = V_15 ;
V_11 -> V_13 . V_16 = V_17 ;
V_9 = V_18 ;
V_12 = ( T_4 * ) V_11 -> V_19 . V_16 ;
for ( V_8 = V_20 ; V_8 -> V_21 != 0 ; V_8 ++ )
if ( V_8 -> V_21 == V_12 -> V_21 && ( V_8 -> V_22 & V_9 ) )
break;
if ( V_8 -> V_21 == 0 ) {
V_11 -> V_13 . V_16 = V_23 ;
goto V_24;
}
V_6 = ( V_11 -> V_25 == V_26 ) ;
if ( V_6 ) {
if ( ! ( V_8 -> V_22 & V_27 ) ) {
V_11 -> V_13 . V_16 =
V_28 ;
goto V_24;
}
} else {
if ( ! ( V_8 -> V_22 & V_29 ) ) {
V_11 -> V_13 . V_16 =
V_30 ;
goto V_24;
}
}
V_5 = V_8 -> V_31 ( V_8 , V_6 , V_1 , V_3 , V_11 , ( void * ) V_12 -> V_16 ) ;
if ( V_11 -> V_13 . V_16 == V_17 ) {
if ( V_5 != 0 ) {
F_2 ( L_1 , V_5 ) ;
V_11 -> V_13 . V_16 =
V_32 ;
} else {
if ( V_6 ) {
V_11 -> V_19 . V_14 =
V_15 ;
V_12 -> V_14 =
V_15 ;
}
}
}
V_24:
return 0 ;
}
static int F_3 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
int V_5 ;
T_5 * V_33 = ( T_5 * ) V_16 ;
T_6 V_34 [ V_35 ] ;
if ( V_6 ) {
V_5 =
F_4 ( V_3 , V_8 -> V_36 , V_34 , V_8 -> V_37 ) ;
F_5 ( V_34 , V_33 , V_8 -> V_37 ) ;
} else {
memset ( V_34 , 0 , V_8 -> V_37 ) ;
F_6 ( V_34 , V_33 ) ;
V_5 =
F_7 ( V_3 , V_8 -> V_36 , V_34 , V_8 -> V_37 ) ;
}
return V_5 ;
}
static int F_8 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 , void * V_16 )
{
int V_5 ;
T_7 * V_38 = ( T_7 * ) V_16 ;
T_6 V_34 [ V_35 ] ;
T_3 * V_39 = ( T_3 * ) V_34 ;
if ( V_6 ) {
V_5 = F_9 ( V_3 , V_8 -> V_36 , V_39 ) ;
* V_38 = * V_39 ;
} else {
* V_39 = * V_38 ;
V_5 = F_10 ( V_3 , V_8 -> V_36 , * V_39 ) ;
}
return V_5 ;
}
static int F_11 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 , void * V_16 )
{
int V_5 ;
T_7 * V_38 = ( T_7 * ) V_16 ;
T_6 V_34 [ V_35 ] ;
T_3 * V_39 = ( T_3 * ) V_34 ;
T_7 V_40 ;
V_5 = F_9 ( V_3 , V_8 -> V_36 , V_39 ) ;
if ( V_5 == 0 ) {
V_40 = * V_39 ;
if ( V_6 ) {
* V_38 = ( V_40 & V_8 -> V_37 ) ?
V_41 : V_42 ;
} else {
if ( ( * V_38 ) == V_41 )
V_40 |= V_8 -> V_37 ;
else
V_40 &= ~ V_8 -> V_37 ;
* V_39 = V_40 ;
V_5 =
F_10 ( V_3 , V_8 -> V_36 , * V_39 ) ;
}
}
return V_5 ;
}
static int F_12 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
int V_5 ;
T_5 * V_33 = ( T_5 * ) V_16 ;
T_6 V_34 [ V_35 ] ;
T_3 V_43 ;
if ( V_6 ) {
V_5 = 0 ;
} else {
V_43 = ( V_33 -> V_43 > 5 ) ? V_44 :
V_45 ;
memset ( V_34 , 0 , V_43 ) ;
F_6 ( V_34 , V_33 ) ;
V_5 = F_7 ( V_3 , V_8 -> V_36 , V_34 , V_43 ) ;
}
return V_5 ;
}
static int F_13 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
int V_5 ;
if ( V_1 -> V_46 & V_47 ) {
if ( V_1 -> V_46 & V_47 )
V_8 -> V_37 |= V_48 ;
if ( V_1 -> V_46 & V_49 )
V_8 -> V_37 |= V_50 ;
}
V_5 = F_11 ( V_8 , V_6 , V_1 , V_3 , V_11 , V_16 ) ;
return V_5 ;
}
static int F_14 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
int V_5 ;
V_5 = F_11 ( V_8 , V_6 , V_1 , V_3 , V_11 , V_16 ) ;
return V_5 ;
}
static int F_15 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
int V_5 ;
T_7 * V_38 = ( T_7 * ) V_16 ;
if ( ! V_6 )
if ( ( * V_38 ) % 2 ) {
F_16 ( V_1 -> V_51 , L_2
L_3 ) ;
V_11 -> V_13 . V_16 =
V_23 ;
return 0 ;
}
V_5 = F_8 ( V_8 , V_6 , V_1 , V_3 , V_11 , V_16 ) ;
return V_5 ;
}
static int F_17 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 , void * V_16 )
{
T_5 * V_33 = ( T_5 * ) V_16 ;
int V_5 ;
switch ( V_8 -> V_21 ) {
case V_52 : {
T_8 V_53 ;
if ( V_6 ) {
F_4 ( V_3 ,
V_54 ,
( T_6 * ) & V_53 ,
sizeof( V_53 ) ) ;
V_33 -> V_43 = F_18 ( V_53 . V_55 ) ;
memcpy ( V_33 -> V_16 , V_53 . V_16 , V_33 -> V_43 ) ;
} else {
V_53 . V_55 = F_19 ( V_33 -> V_43 ) ;
memcpy ( V_53 . V_16 , V_33 -> V_16 , V_33 -> V_43 ) ;
V_5 =
F_7 ( V_3 ,
V_54 ,
( T_6 * ) & V_53 ,
sizeof( V_53 ) ) ;
}
break;
}
default:
F_20 ( V_1 -> V_51 , L_4 , V_8 -> V_21 ) ;
}
return 0 ;
}
void F_21 ( struct V_56 * V_57 ,
T_5 * V_33 )
{
V_57 -> V_43 = F_19 ( ( T_3 ) ( V_33 -> V_43 ) ) ;
memcpy ( V_57 -> V_16 , V_33 -> V_16 , V_33 -> V_43 ) ;
}
void F_6 ( T_6 * V_58 , T_5 * V_33 )
{
memcpy ( V_58 , V_33 -> V_16 , V_33 -> V_43 ) ;
}
void F_22 ( struct V_56 * V_57 ,
T_5 * V_33 )
{
V_33 -> V_43 = ( T_6 ) ( F_18 ( ( T_3 ) ( V_57 -> V_43 ) ) ) ;
memcpy ( V_33 -> V_16 , V_57 -> V_16 , V_33 -> V_43 ) ;
}
void F_5 ( T_6 * V_58 , T_5 * V_33 , int V_43 )
{
V_33 -> V_43 = ( T_6 ) V_43 ;
memcpy ( V_33 -> V_16 , V_58 , V_43 ) ;
}
