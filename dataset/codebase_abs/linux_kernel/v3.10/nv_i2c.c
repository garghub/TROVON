static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_6 , V_4 -> V_8 + 1 ) & 0xf0 ;
if ( V_2 )
V_7 |= 0x20 ;
else
V_7 &= ~ 0x20 ;
F_3 ( V_6 , V_4 -> V_8 + 1 , V_7 | 0x01 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_6 , V_4 -> V_8 + 1 ) & 0xf0 ;
if ( V_2 )
V_7 |= 0x10 ;
else
V_7 &= ~ 0x10 ;
F_3 ( V_6 , V_4 -> V_8 + 1 , V_7 | 0x01 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 = 0 ;
if ( F_2 ( V_6 , V_4 -> V_8 ) & 0x04 )
V_7 = 1 ;
return V_7 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 = 0 ;
if ( F_2 ( V_6 , V_4 -> V_8 ) & 0x08 )
V_7 = 1 ;
return V_7 ;
}
static int F_7 ( struct V_3 * V_4 , const char * V_9 ,
unsigned int V_10 )
{
int V_11 ;
strcpy ( V_4 -> V_12 . V_9 , V_9 ) ;
V_4 -> V_12 . V_13 = V_14 ;
V_4 -> V_12 . V_15 = V_10 ;
V_4 -> V_12 . V_16 = & V_4 -> V_17 ;
V_4 -> V_12 . V_18 . V_19 = & V_4 -> V_6 -> V_20 -> V_18 ;
V_4 -> V_17 . V_21 = F_4 ;
V_4 -> V_17 . V_22 = F_1 ;
V_4 -> V_17 . V_23 = F_6 ;
V_4 -> V_17 . V_24 = F_5 ;
V_4 -> V_17 . V_25 = 40 ;
V_4 -> V_17 . V_26 = F_8 ( 2 ) ;
V_4 -> V_17 . V_1 = V_4 ;
F_9 ( & V_4 -> V_12 , V_4 ) ;
F_4 ( V_4 , 1 ) ;
F_1 ( V_4 , 1 ) ;
V_25 ( 20 ) ;
V_11 = F_10 ( & V_4 -> V_12 ) ;
if ( V_11 == 0 )
F_11 ( & V_4 -> V_6 -> V_20 -> V_18 ,
L_1 , V_9 ) ;
else {
F_12 ( & V_4 -> V_6 -> V_20 -> V_18 ,
L_2 , V_9 ) ;
V_4 -> V_6 = NULL ;
}
return V_11 ;
}
void F_13 ( struct V_5 * V_6 )
{
V_6 -> V_4 [ 0 ] . V_6 = V_6 ;
V_6 -> V_4 [ 1 ] . V_6 = V_6 ;
V_6 -> V_4 [ 2 ] . V_6 = V_6 ;
V_6 -> V_4 [ 0 ] . V_8 = ( V_6 -> V_27 ) ? 0x36 : 0x3e ;
F_7 ( & V_6 -> V_4 [ 0 ] , L_3 ,
( V_6 -> V_27 ) ? V_28 : 0 ) ;
V_6 -> V_4 [ 1 ] . V_8 = ( V_6 -> V_27 ) ? 0x3e : 0x36 ;
F_7 ( & V_6 -> V_4 [ 1 ] , L_4 ,
( V_6 -> V_27 ) ? 0 : V_28 ) ;
V_6 -> V_4 [ 2 ] . V_8 = 0x50 ;
F_7 ( & V_6 -> V_4 [ 2 ] , L_5 , 0 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 3 ; V_29 ++ ) {
if ( ! V_6 -> V_4 [ V_29 ] . V_6 )
continue;
F_15 ( & V_6 -> V_4 [ V_29 ] . V_12 ) ;
V_6 -> V_4 [ V_29 ] . V_6 = NULL ;
}
}
int F_16 ( struct V_30 * V_31 , int V_32 , T_2 * * V_33 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
T_2 * V_34 = NULL ;
if ( V_6 -> V_4 [ V_32 - 1 ] . V_6 )
V_34 = F_17 ( & V_6 -> V_4 [ V_32 - 1 ] . V_12 ) ;
if ( ! V_34 && V_32 == 1 ) {
const T_2 * V_35 = F_18 ( V_31 -> V_36 ) ;
if ( V_35 != NULL )
V_34 = F_19 ( V_35 , V_37 , V_38 ) ;
}
* V_33 = V_34 ;
return ( V_34 ) ? 0 : 1 ;
}
