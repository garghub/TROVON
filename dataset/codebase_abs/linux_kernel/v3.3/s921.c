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
static int F_6 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_1 * V_2 = V_22 -> V_26 ;
int V_27 , V_12 , V_18 ;
unsigned long V_28 ;
T_1 V_29 ;
T_2 V_30 ;
F_7 ( L_4 , V_24 -> V_31 ) ;
for ( V_27 = 0 ; V_27 < F_8 ( V_32 ) ; V_27 ++ )
if ( V_24 -> V_31 < V_32 [ V_27 ] . V_33 )
break;
V_27 -- ;
if ( V_27 < 0 ) {
V_12 ( L_5 , V_14 ) ;
return - V_34 ;
}
V_29 = V_32 [ V_27 ] . V_35 ;
V_30 = ( ( T_2 ) V_24 -> V_31 ) * 258 ;
F_9 ( V_30 , 6000000 ) ;
V_28 = ( ( unsigned long ) V_30 ) + 2321 ;
V_12 = F_10 ( V_2 , V_36 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0xf2 , ( V_28 >> 8 ) & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0xf3 , V_28 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0xf4 , V_29 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , V_37 ) ;
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
F_7 ( L_9 , V_29 , ( int ) V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_12 ;
F_7 ( L_10 ) ;
V_12 = F_10 ( V_2 , V_38 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 , T_3 * V_39 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_40 , V_12 ;
* V_39 = 0 ;
V_12 = F_12 ( V_2 , 0x81 ) ;
if ( V_12 < 0 )
return V_12 ;
V_40 = V_12 << 8 ;
V_12 = F_12 ( V_2 , 0x82 ) ;
if ( V_12 < 0 )
return V_12 ;
V_40 |= V_12 ;
F_7 ( L_11 , V_40 ) ;
if ( ( V_40 & 0xff ) == 0x40 ) {
* V_39 = V_41 |
V_42 |
V_43 |
V_44 |
V_45 ;
} else if ( V_40 & 0x40 ) {
* V_39 = V_41 |
V_42 |
V_43 |
V_44 ;
}
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , T_4 * V_46 )
{
T_3 V_39 ;
struct V_1 * V_2 = V_22 -> V_26 ;
int V_12 ;
V_12 = F_14 ( V_22 , & V_39 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_46 = ( V_39 & V_45 ) ? 0xffff : 0 ;
F_7 ( L_12 , * V_46 ) ;
V_12 = F_12 ( V_2 , 0x01 ) ;
F_7 ( L_7 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x80 ) ;
F_7 ( L_6 , V_12 ) ;
V_12 = F_12 ( V_2 , 0x32 ) ;
F_7 ( L_8 , V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_1 * V_2 = V_22 -> V_26 ;
int V_12 ;
F_7 ( L_10 ) ;
V_12 = F_6 ( V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_47 = V_24 -> V_31 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_1 * V_2 = V_22 -> V_26 ;
V_24 -> V_31 = V_2 -> V_47 ;
V_24 -> V_48 = V_49 ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
bool V_50 ,
unsigned int V_51 ,
unsigned int * V_52 ,
T_3 * V_39 )
{
int V_12 = 0 ;
F_7 ( L_10 ) ;
if ( V_50 )
V_12 = F_16 ( V_22 ) ;
if ( ! ( V_51 & V_53 ) )
F_14 ( V_22 , V_39 ) ;
return V_12 ;
}
static int F_19 ( struct V_21 * V_22 )
{
return 1 ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_7 ( L_10 ) ;
F_21 ( V_2 ) ;
}
struct V_21 * F_22 ( const struct V_54 * V_55 ,
struct V_56 * V_13 )
{
struct V_1 * V_2 =
F_23 ( sizeof( struct V_1 ) , V_57 ) ;
F_7 ( L_10 ) ;
if ( V_2 == NULL ) {
V_12 ( L_13 ) ;
goto V_58;
}
V_2 -> V_55 = V_55 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_59 . V_60 , & V_61 ,
sizeof( struct V_62 ) ) ;
V_2 -> V_59 . V_26 = V_2 ;
return & V_2 -> V_59 ;
V_58:
F_21 ( V_2 ) ;
return NULL ;
}
