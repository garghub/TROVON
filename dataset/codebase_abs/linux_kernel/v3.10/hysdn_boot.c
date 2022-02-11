static void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
}
static void
F_2 ( struct V_1 * V_2 , int V_5 )
{
unsigned char * V_6 = V_2 -> V_7 . V_8 ;
while ( V_5 -- ) {
V_2 -> V_3 = ( V_2 -> V_3 >> 1 ) ^ ( ( V_2 -> V_3 & 1U ) ? V_9 : 0 ) ;
* V_6 ++ ^= ( unsigned char ) V_2 -> V_3 ;
}
}
static int
F_3 ( T_1 * V_10 , int V_11 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
long V_12 ;
unsigned char * V_13 ;
int V_14 ;
switch ( V_2 -> V_15 ) {
case V_16 :
if ( V_10 -> V_17 & V_18 )
F_4 ( V_10 , L_1 , V_2 -> V_7 . V_19 . V_20 ) ;
break;
case V_21 :
F_2 ( V_2 , V_11 ) ;
case V_22 :
if ( V_10 -> V_17 & V_18 )
F_4 ( V_10 , L_2 ,
( V_2 -> V_15 == V_21 ) ? L_3 : L_4 ,
V_11 , V_2 -> V_23 ) ;
if ( V_2 -> V_24 != V_25 ) {
V_2 -> V_26 = V_27 ;
return ( V_2 -> V_26 ) ;
}
V_13 = V_2 -> V_7 . V_8 ;
V_14 = V_11 ;
V_12 = V_28 -
( V_2 -> V_23 & ( V_29 - 1 ) ) ;
if ( V_12 > 0 ) {
V_13 += V_12 ;
V_14 -= V_12 ;
}
if ( V_14 > 0 ) {
if ( ( V_2 -> V_26 =
V_10 -> V_30 ( V_10 , V_13 ,
( V_2 -> V_23 > V_29 ) ? 2 : 0 ) ) < 0 )
return ( V_2 -> V_26 ) ;
}
break;
case V_31 :
F_2 ( V_2 , V_11 ) ;
case V_32 :
if ( V_10 -> V_17 & V_18 )
F_4 ( V_10 , L_2 ,
( V_2 -> V_15 == V_31 ) ? L_5 : L_6 ,
V_11 , V_2 -> V_23 ) ;
if ( ( V_2 -> V_26 = V_10 -> V_33 ( V_10 , V_2 -> V_7 . V_8 , V_11 ) ) < 0 )
return ( V_2 -> V_26 ) ;
if ( V_2 -> V_23 + V_11 >= V_2 -> V_24 )
return ( V_10 -> V_34 ( V_10 ) ) ;
break;
default:
if ( V_10 -> V_17 & V_18 )
F_4 ( V_10 , L_7 , V_2 -> V_15 ,
V_11 , V_2 -> V_23 ) ;
break;
}
return ( 0 ) ;
}
int
F_5 ( T_1 * V_10 , int V_11 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 )
return ( - V_35 ) ;
if ( V_2 -> V_26 < 0 )
return ( V_2 -> V_26 ) ;
if ( V_10 -> V_17 & V_36 )
F_4 ( V_10 , L_8 , V_11 ) ;
switch ( V_2 -> V_37 ) {
case V_38 :
if ( V_10 -> V_17 & V_36 )
F_4 ( V_10 , L_9 ) ;
if ( V_11 != sizeof( V_39 ) ) {
V_2 -> V_26 = - V_40 ;
break;
}
if ( V_2 -> V_7 . V_41 . V_42 != V_43 ) {
V_2 -> V_26 = - V_44 ;
break;
}
V_2 -> V_45 = ( unsigned short ) ( V_2 -> V_7 . V_41 . V_46 ) ;
V_2 -> V_37 = V_47 ;
V_2 -> V_26 = sizeof( V_48 ) ;
break;
case V_47 :
if ( V_10 -> V_17 & V_36 )
F_4 ( V_10 , L_10 ) ;
if ( V_11 != sizeof( V_48 ) ) {
V_2 -> V_26 = - V_40 ;
break;
}
V_2 -> V_15 = V_2 -> V_7 . V_49 . V_50 ;
V_2 -> V_24 = V_2 -> V_7 . V_49 . V_51 ;
V_2 -> V_23 = 0 ;
if ( V_10 -> V_17 & V_18 )
F_4 ( V_10 , L_11 ,
V_2 -> V_15 , V_2 -> V_24 ) ;
V_2 -> V_37 = V_52 ;
if ( V_2 -> V_24 < V_53 )
V_2 -> V_26 = V_2 -> V_24 ;
else
V_2 -> V_26 = V_53 ;
if ( ! V_2 -> V_26 ) {
V_2 -> V_37 = V_47 ;
V_2 -> V_26 = sizeof( V_48 ) ;
}
break;
case V_52 :
if ( V_10 -> V_17 & V_36 )
F_4 ( V_10 , L_12 ) ;
if ( V_11 != V_2 -> V_26 ) {
V_2 -> V_26 = - V_40 ;
break;
}
if ( ( V_2 -> V_26 = F_3 ( V_10 , V_11 ) ) < 0 )
return ( V_2 -> V_26 ) ;
V_2 -> V_23 += V_11 ;
if ( V_2 -> V_23 >= V_2 -> V_24 ) {
V_2 -> V_37 = V_47 ;
V_2 -> V_26 = sizeof( V_48 ) ;
} else {
if ( V_2 -> V_24 - V_2 -> V_23 < V_53 )
V_2 -> V_26 = V_2 -> V_24 - V_2 -> V_23 ;
else
V_2 -> V_26 = V_53 ;
}
break;
default:
V_2 -> V_26 = - V_40 ;
break;
}
return ( V_2 -> V_26 ) ;
}
int
F_6 ( T_1 * V_10 , unsigned char * * V_6 )
{
struct V_1 * V_2 ;
if ( V_10 -> V_2 ) {
if ( V_10 -> V_17 & V_54 )
F_4 ( V_10 , L_13 ) ;
return ( - V_55 ) ;
}
if ( ! ( V_2 = F_7 ( sizeof( struct V_1 ) , V_56 ) ) ) {
if ( V_10 -> V_17 & V_57 )
F_4 ( V_10 , L_14 ) ;
return ( - V_35 ) ;
}
V_10 -> V_2 = V_2 ;
V_10 -> V_58 = V_59 ;
V_10 -> V_60 ( V_10 ) ;
if ( V_10 -> V_61 ( V_10 ) ) {
if ( V_10 -> V_17 & V_54 )
F_4 ( V_10 , L_15 ) ;
V_2 -> V_26 = - V_62 ;
V_10 -> V_58 = V_63 ;
return ( V_2 -> V_26 ) ;
}
V_2 -> V_64 = 0 ;
V_2 -> V_37 = V_38 ;
F_1 ( V_2 ) ;
if ( V_10 -> V_17 & V_54 )
F_4 ( V_10 , L_16 ) ;
* V_6 = V_2 -> V_7 . V_8 ;
return ( sizeof( V_39 ) ) ;
}
int
F_8 ( T_1 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 )
return ( - V_35 ) ;
V_10 -> V_2 = NULL ;
F_9 ( V_2 ) ;
if ( V_10 -> V_58 == V_65 )
V_10 -> V_66 ( V_10 , 1 ) ;
if ( V_10 -> V_17 & V_54 )
F_4 ( V_10 , L_17 ) ;
return ( 0 ) ;
}
int
F_10 ( T_1 * V_10 , unsigned char * V_67 , int V_68 )
{
T_2 * V_69 ;
T_2 V_70 ;
if ( V_10 -> V_17 & V_18 )
F_4 ( V_10 , L_18 , V_68 ) ;
if ( V_68 < 2 ) {
F_4 ( V_10 , L_19 ) ;
return ( 1 ) ;
}
for ( V_69 = V_67 , V_70 = 0 ; V_69 < ( V_67 + V_68 - 2 ) ; V_69 ++ )
if ( ( V_70 & 0x80 ) )
V_70 = ( ( ( T_2 ) ( V_70 << 1 ) ) + 1 ) + * V_69 ;
else
V_70 = ( ( T_2 ) ( V_70 << 1 ) ) + * V_69 ;
V_70 = ~ V_70 ;
if ( V_70 != * ( V_67 + V_68 - 1 ) ) {
F_4 ( V_10 , L_20 ) ;
return ( 1 ) ;
}
V_68 -- ;
while ( V_68 > 0 ) {
if ( * V_67 == V_71 )
return ( 0 ) ;
if ( V_68 < ( * ( V_67 + 1 ) + 2 ) ) {
F_4 ( V_10 , L_21 , * V_67 , * ( V_67 + 1 ) ) ;
return ( 1 ) ;
}
switch ( * V_67 ) {
case V_72 :
if ( * ( V_67 + 1 ) != 1 )
return ( 1 ) ;
V_10 -> V_73 = * ( V_67 + 2 ) ;
break;
case V_74 :
if ( * ( V_67 + 1 ) != 1 )
return ( 1 ) ;
V_10 -> V_75 = * ( V_67 + 2 ) ;
break;
case V_76 :
if ( * ( V_67 + 1 ) != 6 )
return ( 1 ) ;
memcpy ( V_10 -> V_77 , V_67 + 2 , 6 ) ;
break;
default:
F_4 ( V_10 , L_22 , * V_67 , * ( V_67 + 1 ) ) ;
break;
}
V_68 -= ( * ( V_67 + 1 ) + 2 ) ;
V_67 += ( * ( V_67 + 1 ) + 2 ) ;
}
F_4 ( V_10 , L_23 ) ;
return ( 1 ) ;
}
