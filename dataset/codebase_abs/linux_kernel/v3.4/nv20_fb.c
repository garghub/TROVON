static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_13 = F_2 ( & V_9 -> V_14 ) ;
if ( V_13 )
return NULL ;
F_3 ( & V_6 -> V_15 . V_16 ) ;
V_12 = F_4 ( & V_9 -> V_14 , V_4 , 0 , 0 ) ;
if ( V_12 )
V_12 = F_5 ( V_12 , V_4 , 0 ) ;
F_6 ( & V_6 -> V_15 . V_16 ) ;
return V_12 ;
}
static void
F_7 ( struct V_2 * V_3 , struct V_1 * * V_17 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_12 = * V_17 ;
if ( V_12 ) {
F_3 ( & V_6 -> V_15 . V_16 ) ;
F_8 ( V_12 ) ;
F_6 ( & V_6 -> V_15 . V_16 ) ;
* V_17 = NULL ;
}
}
void
F_9 ( struct V_2 * V_3 , int V_18 , T_1 V_19 ,
T_1 V_4 , T_1 V_20 , T_1 V_21 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_22 * V_15 = & V_6 -> V_15 . V_23 [ V_18 ] ;
int V_24 = ( V_21 & V_25 ? 32 : 16 ) ;
V_15 -> V_19 = 0x00000001 | V_19 ;
V_15 -> V_26 = F_10 ( 1u , V_19 + V_4 ) - 1 ;
V_15 -> V_20 = V_20 ;
if ( V_21 & V_27 ) {
V_15 -> V_28 = F_1 ( V_3 , V_4 / 256 ) ;
if ( V_15 -> V_28 ) {
V_15 -> V_29 = V_15 -> V_28 -> V_30 ;
if ( V_6 -> V_31 >= 0x25 ) {
if ( V_24 == 16 )
V_15 -> V_29 |= V_32 ;
else
V_15 -> V_29 |= V_33 ;
} else {
V_15 -> V_29 |= V_34 ;
if ( V_24 != 16 )
V_15 -> V_29 |= V_35 ;
}
}
V_15 -> V_19 |= 2 ;
}
}
void
F_11 ( struct V_2 * V_3 , int V_18 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_22 * V_15 = & V_6 -> V_15 . V_23 [ V_18 ] ;
V_15 -> V_19 = V_15 -> V_26 = V_15 -> V_20 = V_15 -> V_29 = 0 ;
F_7 ( V_3 , & V_15 -> V_28 ) ;
}
void
F_12 ( struct V_2 * V_3 , int V_18 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_22 * V_15 = & V_6 -> V_15 . V_23 [ V_18 ] ;
F_13 ( V_3 , F_14 ( V_18 ) , V_15 -> V_26 ) ;
F_13 ( V_3 , F_15 ( V_18 ) , V_15 -> V_20 ) ;
F_13 ( V_3 , F_16 ( V_18 ) , V_15 -> V_19 ) ;
F_13 ( V_3 , F_17 ( V_18 ) , V_15 -> V_29 ) ;
}
int
F_18 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
T_2 V_36 = F_19 ( V_3 , 0x10020c ) ;
T_2 V_37 = F_19 ( V_3 , 0x001218 ) ;
V_6 -> V_38 = V_36 & 0xff000000 ;
switch ( V_37 & 0x00000300 ) {
case 0x00000000 : V_6 -> V_39 = V_40 ; break;
case 0x00000100 : V_6 -> V_39 = V_41 ; break;
case 0x00000200 : V_6 -> V_39 = V_42 ; break;
case 0x00000300 : V_6 -> V_39 = V_43 ; break;
}
return 0 ;
}
int
F_20 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
int V_18 ;
if ( V_6 -> V_31 >= 0x25 )
F_21 ( & V_9 -> V_14 , 0 , 64 * 1024 ) ;
else
F_21 ( & V_9 -> V_14 , 0 , 32 * 1024 ) ;
V_9 -> V_44 = V_45 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_44 ; V_18 ++ )
V_9 -> V_46 ( V_3 , V_18 ) ;
return 0 ;
}
void
F_22 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_44 ; V_18 ++ )
V_9 -> V_47 ( V_3 , V_18 ) ;
F_23 ( & V_9 -> V_14 ) ;
}
