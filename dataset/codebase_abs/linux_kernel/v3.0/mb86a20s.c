static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 , int V_5 )
{
T_1 V_6 [] = { V_4 , V_5 } ;
struct V_7 V_8 = {
. V_9 = V_3 , . V_10 = 0 , . V_6 = V_6 , . V_11 = 2
} ;
int V_12 ;
V_12 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_12 != 1 ) {
F_3 ( L_1
L_2 , V_14 , V_12 , V_4 , V_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_15 * V_16 , int V_17 )
{
int V_18 , V_12 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_12 = F_1 ( V_2 , V_3 , V_16 [ V_18 ] . V_4 ,
V_16 [ V_18 ] . V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_19 ;
int V_12 ;
struct V_7 V_8 [] = {
{ . V_9 = V_3 , . V_10 = 0 , . V_6 = & V_4 , . V_11 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_20 , . V_6 = & V_19 , . V_11 = 1 }
} ;
V_12 = F_2 ( V_2 -> V_13 , V_8 , 2 ) ;
if ( V_12 != 2 ) {
V_12 ( L_3 , V_14 , V_4 , V_12 ) ;
return V_12 ;
}
return V_19 ;
}
static int F_6 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_12 ;
T_1 V_24 = 1 ;
F_7 ( L_4 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_12 = F_8 ( V_2 , V_27 ) ;
if ( V_12 < 0 )
goto V_28;
if ( ! V_2 -> V_29 -> V_30 ) {
V_24 &= ~ 1 ;
V_12 = F_9 ( V_2 , 0x50 , 0xd5 ) ;
if ( V_12 < 0 )
goto V_28;
V_12 = F_9 ( V_2 , 0x51 , V_24 ) ;
if ( V_12 < 0 )
goto V_28;
}
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
V_28:
if ( V_12 < 0 ) {
V_2 -> V_31 = true ;
F_3 ( V_32 L_5 ) ;
} else {
V_2 -> V_31 = false ;
F_7 ( L_6 ) ;
}
return V_12 ;
}
static int F_10 ( struct V_21 * V_22 , T_2 * V_33 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned V_34 , V_35 , V_36 ;
T_1 V_19 ;
F_7 ( L_4 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_34 = 0xfff ;
V_35 = 0 ;
do {
V_36 = ( V_34 + V_35 ) / 2 ;
F_9 ( V_2 , 0x04 , 0x1f ) ;
F_9 ( V_2 , 0x05 , V_36 >> 8 ) ;
F_9 ( V_2 , 0x04 , 0x20 ) ;
F_9 ( V_2 , 0x04 , V_36 ) ;
V_19 = F_11 ( V_2 , 0x02 ) ;
if ( V_19 & 0x08 )
V_35 = ( V_34 + V_35 ) / 2 ;
else
V_34 = ( V_34 + V_35 ) / 2 ;
if ( V_34 - V_35 < 4 ) {
* V_33 = ( ( ( V_34 + V_35 ) / 2 ) * 65535 ) / 4095 ;
break;
}
} while ( 1 );
F_7 ( L_7 , * V_33 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , T_3 * V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_19 ;
F_7 ( L_4 ) ;
* V_37 = 0 ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_19 = F_11 ( V_2 , 0x0a ) & 0xf ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
if ( V_19 >= 2 )
* V_37 |= V_38 ;
if ( V_19 >= 4 )
* V_37 |= V_39 ;
if ( V_19 >= 5 )
* V_37 |= V_40 ;
if ( V_19 >= 7 )
* V_37 |= V_41 ;
if ( V_19 >= 8 )
* V_37 |= V_42 ;
F_7 ( L_8 , V_19 , * V_37 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_12 ;
F_7 ( L_4 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
F_7 ( L_9 ) ;
V_22 -> V_25 . V_45 . V_46 ( V_22 , V_44 ) ;
if ( V_2 -> V_31 )
F_6 ( V_22 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
V_12 = F_8 ( V_2 , V_47 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
return V_12 ;
}
static int F_14 ( struct V_21 * V_22 ,
struct V_43 * V_44 )
{
V_22 -> V_48 . V_49 = 6000000 ;
V_22 -> V_48 . V_50 = V_51 ;
V_22 -> V_48 . V_52 = V_53 ;
V_22 -> V_48 . V_54 = 0 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 ,
struct V_43 * V_55 ,
unsigned int V_56 ,
unsigned int * V_57 ,
T_3 * V_37 )
{
int V_12 = 0 ;
F_7 ( L_4 ) ;
if ( V_55 != NULL )
V_12 = F_13 ( V_22 , V_55 ) ;
if ( ! ( V_56 & V_58 ) )
F_12 ( V_22 , V_37 ) ;
return V_12 ;
}
static void F_16 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_7 ( L_4 ) ;
F_17 ( V_2 ) ;
}
struct V_21 * F_18 ( const struct V_59 * V_29 ,
struct V_60 * V_13 )
{
T_1 V_61 ;
struct V_1 * V_2 =
F_19 ( sizeof( struct V_1 ) , V_62 ) ;
F_7 ( L_4 ) ;
if ( V_2 == NULL ) {
V_12 ( L_10 ) ;
goto error;
}
V_2 -> V_29 = V_29 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_63 . V_25 , & V_64 ,
sizeof( struct V_65 ) ) ;
V_2 -> V_63 . V_23 = V_2 ;
V_61 = F_11 ( V_2 , 0 ) ;
if ( V_61 == 0x13 ) {
F_3 ( V_32 L_11 ) ;
} else {
F_3 ( V_66 L_12 ,
V_61 ) ;
goto error;
}
return & V_2 -> V_63 ;
error:
F_17 ( V_2 ) ;
return NULL ;
}
