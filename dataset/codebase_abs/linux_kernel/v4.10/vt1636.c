T_1 F_1 ( struct V_1
* V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
T_1 V_6 ;
F_2 ( V_4 -> V_7 ,
V_4 -> V_8 , V_5 , & V_6 ) ;
return V_6 ;
}
void F_3 ( struct V_1
* V_2 , struct V_3
* V_4 , struct V_9 V_10 )
{
int V_5 , V_6 ;
V_5 = V_10 . V_11 ;
V_6 = F_1 ( V_2 , V_4 ,
V_5 ) ;
V_6 = ( V_6 & ( ~ V_10 . V_12 ) ) | V_10 . V_13 ;
F_4 ( V_4 -> V_7 ,
V_4 -> V_8 , V_5 , V_6 ) ;
}
void F_5 ( struct V_1
* V_2 , struct V_3 * V_4 )
{
int V_14 , V_15 ;
V_14 = F_6 ( V_16 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
F_3 ( V_2 ,
V_4 , V_16 [ V_15 ] ) ;
if ( V_2 -> V_17 )
F_3 ( V_2 ,
V_4 , V_18 ) ;
else
F_3 ( V_2 ,
V_4 , V_19 ) ;
if ( V_2 -> V_20 )
F_3 ( V_2 ,
V_4 , V_21 ) ;
else
F_3 ( V_2 ,
V_4 , V_22 ) ;
}
void F_7 ( struct V_1
* V_2 ,
struct V_3 * V_4 )
{
F_3 ( V_2 , V_4 ,
V_23 ) ;
}
void F_8 ( struct V_1
* V_2 ,
struct V_3 * V_4 )
{
F_3 ( V_2 , V_4 ,
V_24 ) ;
}
bool F_9 ( T_1 V_25 )
{
T_1 V_26 [ 2 ] ;
F_10 ( V_27 L_1 ) ;
V_28 -> V_29 -> V_30 . V_8 =
V_31 ;
if ( F_2 ( V_25 , V_31 ,
0x00 , & V_26 [ 0 ] ) )
return false ;
F_2 ( V_25 , V_31 , 0x01 , & V_26 [ 1 ] ) ;
if ( ! ( ( V_26 [ 0 ] == 0x06 ) && ( V_26 [ 1 ] == 0x11 ) ) )
return false ;
F_2 ( V_25 , V_31 , 0x02 , & V_26 [ 0 ] ) ;
F_2 ( V_25 , V_31 , 0x03 , & V_26 [ 1 ] ) ;
if ( ( V_26 [ 0 ] == 0x45 ) && ( V_26 [ 1 ] == 0x33 ) ) {
V_28 -> V_29 -> V_30 . V_32 =
V_33 ;
return true ;
}
return false ;
}
static int F_11 ( T_2 V_34 )
{
if ( V_34 < V_35 )
return V_36 ;
else if ( V_34 < V_37 )
return V_38 ;
else if ( V_34 < V_39 )
return V_40 ;
else if ( V_34 < V_41 )
return V_42 ;
else if ( V_34 < V_43 )
return V_44 ;
else
return V_45 ;
}
static void F_12 ( struct V_1
* V_2 , struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_9 V_10 ;
V_10 . V_11 = 0x09 ;
V_10 . V_12 = 0x1F ;
V_10 . V_13 = V_47 -> V_48 ;
F_3 ( V_2 ,
V_4 , V_10 ) ;
V_10 . V_11 = 0x08 ;
V_10 . V_12 = 0x0F ;
V_10 . V_13 = V_47 -> V_49 ;
F_3 ( V_2 , V_4 ,
V_10 ) ;
}
void F_13 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_46 V_50 = { 0x00 , 0x00 } , V_51 = { 0x0B , 0x03 } ,
* V_52 ;
int V_5 ;
F_10 ( V_27 L_2 ) ;
V_5 = F_11 ( V_2 -> V_53 ) ;
F_14 ( V_4 -> V_54 ,
& V_55 [ V_5 ] ) ;
if ( V_2 -> V_56 == 1600 &&
V_2 -> V_57 == 1200 )
V_52 = & V_51 ;
else
V_52 = & V_50 ;
F_12 ( V_2 , V_4 , V_52 ) ;
}
void F_15 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_46 V_50 = { 0x00 , 0x00 } ;
int V_5 ;
F_10 ( V_27 L_3 ) ;
V_5 = F_11 ( V_2 -> V_53 ) ;
F_14 ( V_4 -> V_54 ,
& V_58 [ V_5 ] ) ;
F_12 ( V_2 , V_4 , & V_50 ) ;
}
void F_16 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
F_10 ( V_27 L_4 ) ;
V_5 = F_11 ( V_2 -> V_53 ) ;
F_14 ( V_4 -> V_54 ,
& V_59 [ V_5 ] ) ;
}
