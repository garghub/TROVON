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
T_5 * V_33 = V_16 ;
T_6 V_34 [ V_35 ] ;
if ( V_6 ) {
V_5 =
F_4 ( V_3 , V_8 -> V_36 , V_34 , V_8 -> V_37 ) ;
F_5 ( V_34 , V_33 , V_8 -> V_37 ) ;
} else {
memset ( V_34 , 0 , V_8 -> V_37 ) ;
memcpy ( V_34 , V_33 -> V_16 , V_33 -> V_38 ) ;
V_5 =
F_6 ( V_3 , V_8 -> V_36 , V_34 , V_8 -> V_37 ) ;
}
return V_5 ;
}
static int F_7 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 , void * V_16 )
{
int V_5 ;
T_7 * V_39 = V_16 ;
T_6 V_34 [ V_35 ] ;
T_3 * V_40 = ( T_3 * ) V_34 ;
if ( V_6 ) {
V_5 = F_8 ( V_3 , V_8 -> V_36 , V_40 ) ;
* V_39 = * V_40 ;
} else {
* V_40 = * V_39 ;
V_5 = F_9 ( V_3 , V_8 -> V_36 , * V_40 ) ;
}
return V_5 ;
}
static int F_10 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 , void * V_16 )
{
int V_5 ;
T_7 * V_39 = V_16 ;
T_6 V_34 [ V_35 ] ;
T_3 * V_40 = ( T_3 * ) V_34 ;
T_7 V_41 ;
V_5 = F_8 ( V_3 , V_8 -> V_36 , V_40 ) ;
if ( V_5 == 0 ) {
V_41 = * V_40 ;
if ( V_6 ) {
* V_39 = ( V_41 & V_8 -> V_37 ) ?
V_42 : V_43 ;
} else {
if ( ( * V_39 ) == V_42 )
V_41 |= V_8 -> V_37 ;
else
V_41 &= ~ V_8 -> V_37 ;
* V_40 = V_41 ;
V_5 =
F_9 ( V_3 , V_8 -> V_36 , * V_40 ) ;
}
}
return V_5 ;
}
static int F_11 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
int V_5 ;
T_5 * V_33 = V_16 ;
T_6 V_34 [ V_35 ] ;
T_3 V_38 ;
if ( V_6 ) {
V_5 = 0 ;
} else {
V_38 = ( V_33 -> V_38 > 5 ) ? V_44 :
V_45 ;
memset ( V_34 , 0 , V_38 ) ;
memcpy ( V_34 , V_33 -> V_16 , V_33 -> V_38 ) ;
V_5 = F_6 ( V_3 , V_8 -> V_36 , V_34 , V_38 ) ;
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
if ( V_1 -> V_46 & V_47 ) {
if ( V_1 -> V_46 & V_47 )
V_8 -> V_37 |= V_48 ;
if ( V_1 -> V_46 & V_49 )
V_8 -> V_37 |= V_50 ;
}
return F_10 ( V_8 , V_6 , V_1 , V_3 , V_11 , V_16 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
return F_10 ( V_8 , V_6 , V_1 , V_3 , V_11 , V_16 ) ;
}
static int F_14 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 ,
void * V_16 )
{
T_7 * V_39 = V_16 ;
if ( ! V_6 )
if ( ( * V_39 ) % 2 ) {
F_15 ( V_1 -> V_51 ,
L_2 ) ;
V_11 -> V_13 . V_16 =
V_23 ;
return 0 ;
}
return F_7 ( V_8 , V_6 , V_1 , V_3 , V_11 , V_16 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
int V_6 ,
T_1 * V_1 ,
T_2 * V_3 ,
struct V_10 * V_11 , void * V_16 )
{
T_5 * V_33 = V_16 ;
switch ( V_8 -> V_21 ) {
case V_52 : {
T_8 V_53 ;
if ( V_6 ) {
F_4 ( V_3 ,
V_54 ,
( T_6 * ) & V_53 ,
sizeof( V_53 ) ) ;
V_33 -> V_38 = F_17 ( V_53 . V_55 ) ;
memcpy ( V_33 -> V_16 , V_53 . V_16 , V_33 -> V_38 ) ;
} else {
V_53 . V_55 = F_18 ( V_33 -> V_38 ) ;
memcpy ( V_53 . V_16 , V_33 -> V_16 , V_33 -> V_38 ) ;
F_6 ( V_3 ,
V_54 ,
( T_6 * ) & V_53 ,
sizeof( V_53 ) ) ;
}
break;
}
default:
F_19 ( V_1 -> V_51 , L_3 , V_8 -> V_21 ) ;
}
return 0 ;
}
void F_20 ( struct V_56 * V_57 ,
T_5 * V_33 )
{
V_57 -> V_38 = F_18 ( ( T_3 ) ( V_33 -> V_38 ) ) ;
memcpy ( V_57 -> V_16 , V_33 -> V_16 , V_33 -> V_38 ) ;
}
void F_21 ( struct V_56 * V_57 ,
T_5 * V_33 )
{
V_33 -> V_38 = ( T_6 ) ( F_17 ( ( T_3 ) ( V_57 -> V_38 ) ) ) ;
memcpy ( V_33 -> V_16 , V_57 -> V_16 , V_33 -> V_38 ) ;
}
void F_5 ( T_6 * V_58 , T_5 * V_33 , int V_38 )
{
V_33 -> V_38 = ( T_6 ) V_38 ;
memcpy ( V_33 -> V_16 , V_58 , V_38 ) ;
}
