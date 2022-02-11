static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( * ( V_4 * ) V_2 -> V_5 == V_6 ) &&
( V_3 == V_2 -> V_7 ) ) {
if ( V_2 -> V_8 & V_9 )
return 0 ;
else {
if ( V_2 -> V_10 == V_11 )
return 0 ;
else
F_2 ( 1 , L_1 ) ;
}
} else {
if ( * ( V_4 * ) V_2 -> V_5 != V_6 )
F_2 ( 1 , L_2 ,
* ( unsigned int * ) V_2 -> V_5 ) ;
if ( V_3 != V_2 -> V_7 )
F_2 ( 1 , L_3 , V_3 ,
V_2 -> V_7 ) ;
}
F_2 ( 1 , L_4 , V_2 -> V_7 ) ;
return 1 ;
}
int
F_3 ( char * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
struct V_14 * V_15 = (struct V_14 * ) V_2 ;
T_1 V_3 = V_2 -> V_7 ;
T_2 V_16 = F_4 ( V_12 ) ;
T_2 V_17 ;
int V_18 ;
F_5 ( 1 , L_5 , V_19 , V_13 , V_16 ) ;
if ( V_13 < sizeof( struct V_14 ) ) {
if ( ( V_13 >= sizeof( struct V_1 ) ) && ( V_2 -> V_20 != 0 ) ) {
V_15 -> V_21 = 0 ;
return 0 ;
} else {
F_2 ( 1 , L_6 ) ;
}
return 1 ;
}
if ( V_16 > V_22 + V_23 - 4 ) {
F_2 ( 1 , L_7 , V_3 ) ;
return 1 ;
}
if ( F_1 ( V_2 , V_3 ) )
return 1 ;
if ( V_2 -> V_24 != V_25 ) {
F_2 ( 1 , L_8 ,
F_6 ( V_2 -> V_24 ) ) ;
return 1 ;
}
V_18 = F_6 ( V_2 -> V_10 ) ;
if ( V_18 >= V_26 ) {
F_2 ( 1 , L_9 , V_18 ) ;
return 1 ;
}
if ( V_27 [ V_18 ] != V_15 -> V_21 ) {
if ( V_2 -> V_20 == 0 ||
V_15 -> V_21 != V_28 ) {
F_2 ( 1 , L_10 ,
F_6 ( V_15 -> V_21 ) , V_18 ) ;
return 1 ;
}
}
if ( 4 + V_16 != V_13 ) {
F_2 ( 1 , L_11 ,
V_13 , 4 + V_16 , V_3 ) ;
return 1 ;
}
V_17 = F_7 ( V_2 ) ;
if ( 4 + V_16 != V_17 ) {
F_5 ( 1 , L_12 ,
V_17 , 4 + V_16 , V_3 ) ;
if ( V_17 == 4 + V_16 + 1 )
return 0 ;
return 1 ;
}
return 0 ;
}
char *
F_8 ( int * V_29 , int * V_16 , struct V_1 * V_2 )
{
* V_29 = 0 ;
* V_16 = 0 ;
if ( V_2 -> V_20 && V_2 -> V_20 != V_30 &&
( ( (struct V_31 * ) V_2 ) -> V_24 ) ==
V_28 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_32 :
* V_29 = F_6 (
( (struct V_33 * ) V_2 ) -> V_34 ) ;
* V_16 = F_6 (
( (struct V_33 * ) V_2 ) -> V_35 ) ;
break;
case V_36 :
* V_29 = F_6 (
( (struct V_37 * ) V_2 ) -> V_34 ) ;
* V_16 = F_6 (
( (struct V_37 * ) V_2 ) -> V_35 ) ;
break;
case V_38 :
* V_29 = F_9 (
( (struct V_39 * ) V_2 ) -> V_40 ) ;
* V_16 = F_9 (
( (struct V_39 * ) V_2 ) -> V_41 ) ;
break;
case V_42 :
* V_29 = F_6 (
( (struct V_43 * ) V_2 ) -> V_44 ) ;
* V_16 = F_9 (
( (struct V_43 * ) V_2 ) -> V_45 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
default:
F_2 ( 1 , L_13 ) ;
break;
}
if ( * V_29 > 4096 ) {
F_2 ( 1 , L_14 , * V_29 ) ;
* V_16 = 0 ;
* V_29 = 0 ;
} else if ( * V_29 < 0 ) {
F_2 ( 1 , L_15 ,
* V_29 ) ;
* V_29 = 0 ;
* V_16 = 0 ;
} else if ( * V_16 < 0 ) {
F_2 ( 1 , L_16 ,
* V_16 ) ;
* V_16 = 0 ;
} else if ( * V_16 > 128 * 1024 ) {
F_2 ( 1 , L_17 , * V_16 ) ;
* V_16 = 0 ;
}
if ( ( * V_29 != 0 ) && ( * V_16 != 0 ) )
return V_2 -> V_5 + * V_29 ;
else
return NULL ;
}
unsigned int
F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = (struct V_14 * ) V_2 ;
int V_50 ;
int V_51 ;
int V_16 = 4 + F_6 ( V_15 -> V_2 . V_24 ) ;
V_16 += F_6 ( V_15 -> V_21 ) ;
if ( V_52 [ F_6 ( V_2 -> V_10 ) ] == false )
goto V_53;
F_8 ( & V_50 , & V_51 , V_2 ) ;
F_5 ( 1 , L_18 , V_51 , V_50 ) ;
if ( V_51 > 0 ) {
if ( V_50 + 4 + 1 < V_16 ) {
F_2 ( 1 , L_19 ,
V_50 + 4 + 1 , V_16 ) ;
V_51 = 0 ;
} else {
V_16 = 4 + V_50 + V_51 ;
}
}
V_53:
F_5 ( 1 , L_20 , V_16 ) ;
return V_16 ;
}
T_3 *
F_10 ( const char * V_54 , struct V_55 * V_56 )
{
int V_16 ;
const char * V_57 ;
T_3 * V_58 ;
if ( V_54 [ 0 ] == '\\' )
V_57 = V_54 + 1 ;
else
V_57 = V_54 ;
V_58 = F_11 ( V_57 , V_59 , & V_16 ,
V_56 -> V_60 ,
V_56 -> V_61 &
V_62 ) ;
return V_58 ;
}
