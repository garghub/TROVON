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
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_15 * V_16 , int V_17 )
{
int V_18 , V_12 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_12 = F_1 ( V_2 , V_3 , V_16 [ V_18 ] . V_4 , V_16 [ V_18 ] . V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
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
static int F_6 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_26 , V_12 , V_18 ;
unsigned long V_27 ;
T_1 V_28 ;
T_2 V_29 ;
F_7 ( L_4 , V_24 -> V_30 ) ;
for ( V_26 = 0 ; V_26 < F_8 ( V_31 ) ; V_26 ++ )
if ( V_24 -> V_30 < V_31 [ V_26 ] . V_32 )
break;
V_26 -- ;
if ( V_26 < 0 ) {
V_12 ( L_5 , V_14 ) ;
return - V_33 ;
}
V_28 = V_31 [ V_26 ] . V_34 ;
V_29 = ( ( T_2 ) V_24 -> V_30 ) * 258 ;
F_9 ( V_29 , 6000000 ) ;
V_27 = ( ( unsigned long ) V_29 ) + 2321 ;
V_12 = F_10 ( V_2 , V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0xf2 , ( V_27 >> 8 ) & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0xf3 , V_27 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0xf4 , V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , V_36 ) ;
if ( V_12 < 0 )
return V_12 ;
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ ) {
V_12 = F_12 ( V_2 , 0x80 ) ;
F_7 ( L_6 , V_12 ) ;
}
V_12 = F_11 ( V_2 , 0x01 , 0x40 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_12 ( V_2 , 0x01 ) ;
F_7 ( L_7 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x80 ) ;
F_7 ( L_6 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x80 ) ;
F_7 ( L_6 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x32 ) ;
F_7 ( L_8 , V_12 ) ;
F_7 ( L_9 , V_28 , ( int ) V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_12 ;
F_7 ( L_10 ) ;
V_12 = F_10 ( V_2 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 , T_3 * V_38 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_39 , V_12 ;
* V_38 = 0 ;
V_12 = F_12 ( V_2 , 0x81 ) ;
if ( V_12 < 0 )
return V_12 ;
V_39 = V_12 << 8 ;
V_12 = F_12 ( V_2 , 0x82 ) ;
if ( V_12 < 0 )
return V_12 ;
V_39 |= V_12 ;
F_7 ( L_11 , V_39 ) ;
if ( ( V_39 & 0xff ) == 0x40 ) {
* V_38 = V_40 |
V_41 |
V_42 |
V_43 |
V_44 ;
} else if ( V_39 & 0x40 ) {
* V_38 = V_40 |
V_41 |
V_42 |
V_43 ;
}
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , T_4 * V_45 )
{
T_3 V_38 ;
struct V_1 * V_2 = V_22 -> V_25 ;
int V_12 ;
V_12 = F_14 ( V_22 , & V_38 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_45 = ( V_38 & V_44 ) ? 0xffff : 0 ;
F_7 ( L_12 , * V_45 ) ;
V_12 = F_12 ( V_2 , 0x01 ) ;
F_7 ( L_7 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x80 ) ;
F_7 ( L_6 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x32 ) ;
F_7 ( L_8 , V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
int V_12 ;
F_7 ( L_10 ) ;
V_12 = F_6 ( V_22 , V_24 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_46 = V_24 -> V_30 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
V_24 -> V_30 = V_2 -> V_46 ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
struct V_23 * V_47 ,
unsigned int V_48 ,
unsigned int * V_49 ,
T_3 * V_38 )
{
int V_12 = 0 ;
F_7 ( L_10 ) ;
if ( V_47 != NULL )
V_12 = F_16 ( V_22 , V_47 ) ;
if ( ! ( V_48 & V_50 ) )
F_14 ( V_22 , V_38 ) ;
return V_12 ;
}
static int F_19 ( struct V_21 * V_22 )
{
return 1 ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
F_7 ( L_10 ) ;
F_21 ( V_2 ) ;
}
struct V_21 * F_22 ( const struct V_51 * V_52 ,
struct V_53 * V_13 )
{
struct V_1 * V_2 =
F_23 ( sizeof( struct V_1 ) , V_54 ) ;
F_7 ( L_10 ) ;
if ( V_2 == NULL ) {
V_12 ( L_13 ) ;
goto V_55;
}
V_2 -> V_52 = V_52 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_56 . V_57 , & V_58 ,
sizeof( struct V_59 ) ) ;
V_2 -> V_56 . V_25 = V_2 ;
return & V_2 -> V_56 ;
V_55:
F_21 ( V_2 ) ;
return NULL ;
}
