static void F_1 ( void * V_1 , int V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = V_1 ;
unsigned long V_6 ;
F_2 ( & V_7 -> V_8 , V_6 ) ;
V_3 = F_3 ( V_5 -> V_9 , V_5 -> V_10 ) & 0xF0 ;
if ( V_2 )
V_3 |= 0x20 ;
else
V_3 &= ~ 0x20 ;
switch ( V_5 -> type ) {
case V_11 :
V_3 |= 0x01 ;
break;
case V_12 :
V_3 |= 0x82 ;
break;
default:
F_4 ( V_13 L_1 ) ;
}
F_5 ( V_5 -> V_9 , V_5 -> V_10 , V_3 ) ;
F_6 ( & V_7 -> V_8 , V_6 ) ;
}
static int F_7 ( void * V_1 )
{
struct V_4 * V_5 = V_1 ;
unsigned long V_6 ;
int V_14 = 0 ;
F_2 ( & V_7 -> V_8 , V_6 ) ;
if ( V_5 -> type == V_12 )
F_8 ( V_5 -> V_9 , V_5 -> V_10 ,
0 , 0x80 ) ;
if ( F_3 ( V_5 -> V_9 , V_5 -> V_10 ) & 0x08 )
V_14 = 1 ;
F_6 ( & V_7 -> V_8 , V_6 ) ;
return V_14 ;
}
static int F_9 ( void * V_1 )
{
struct V_4 * V_5 = V_1 ;
unsigned long V_6 ;
int V_14 = 0 ;
F_2 ( & V_7 -> V_8 , V_6 ) ;
if ( V_5 -> type == V_12 )
F_8 ( V_5 -> V_9 , V_5 -> V_10 ,
0 , 0x40 ) ;
if ( F_3 ( V_5 -> V_9 , V_5 -> V_10 ) & 0x04 )
V_14 = 1 ;
F_6 ( & V_7 -> V_8 , V_6 ) ;
return V_14 ;
}
static void F_10 ( void * V_1 , int V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = V_1 ;
unsigned long V_6 ;
F_2 ( & V_7 -> V_8 , V_6 ) ;
V_3 = F_3 ( V_5 -> V_9 , V_5 -> V_10 ) & 0xF0 ;
if ( V_2 )
V_3 |= 0x10 ;
else
V_3 &= ~ 0x10 ;
switch ( V_5 -> type ) {
case V_11 :
V_3 |= 0x01 ;
break;
case V_12 :
V_3 |= 0x42 ;
break;
default:
F_4 ( V_13 L_1 ) ;
}
F_5 ( V_5 -> V_9 , V_5 -> V_10 , V_3 ) ;
F_6 ( & V_7 -> V_8 , V_6 ) ;
}
int F_11 ( T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 * V_18 )
{
int V_14 ;
T_1 V_19 [] = { 0x00 } ;
struct V_20 V_21 [ 2 ] ;
if ( ! V_22 [ V_15 ] . V_23 )
return - V_24 ;
* V_18 = 0 ;
V_21 [ 0 ] . V_6 = 0 ;
V_21 [ 1 ] . V_6 = V_25 ;
V_21 [ 0 ] . V_26 = V_21 [ 1 ] . V_26 = V_16 / 2 ;
V_19 [ 0 ] = V_17 ;
V_21 [ 0 ] . V_27 = 1 ; V_21 [ 1 ] . V_27 = 1 ;
V_21 [ 0 ] . V_28 = V_19 ; V_21 [ 1 ] . V_28 = V_18 ;
V_14 = F_12 ( & V_22 [ V_15 ] . V_29 , V_21 , 2 ) ;
if ( V_14 == 2 )
V_14 = 0 ;
else if ( V_14 >= 0 )
V_14 = - V_30 ;
return V_14 ;
}
int F_13 ( T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 V_1 )
{
int V_14 ;
T_1 V_31 [ 2 ] = { V_17 , V_1 } ;
struct V_20 V_21 ;
if ( ! V_22 [ V_15 ] . V_23 )
return - V_24 ;
V_21 . V_6 = 0 ;
V_21 . V_26 = V_16 / 2 ;
V_21 . V_27 = 2 ;
V_21 . V_28 = V_31 ;
V_14 = F_12 ( & V_22 [ V_15 ] . V_29 , & V_21 , 1 ) ;
if ( V_14 == 1 )
V_14 = 0 ;
else if ( V_14 >= 0 )
V_14 = - V_30 ;
return V_14 ;
}
int F_14 ( T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 * V_32 , int V_33 )
{
int V_14 ;
T_1 V_19 [] = { 0x00 } ;
struct V_20 V_21 [ 2 ] ;
if ( ! V_22 [ V_15 ] . V_23 )
return - V_24 ;
V_21 [ 0 ] . V_6 = 0 ;
V_21 [ 1 ] . V_6 = V_25 ;
V_21 [ 0 ] . V_26 = V_21 [ 1 ] . V_26 = V_16 / 2 ;
V_19 [ 0 ] = V_17 ;
V_21 [ 0 ] . V_27 = 1 ; V_21 [ 1 ] . V_27 = V_33 ;
V_21 [ 0 ] . V_28 = V_19 ; V_21 [ 1 ] . V_28 = V_32 ;
V_14 = F_12 ( & V_22 [ V_15 ] . V_29 , V_21 , 2 ) ;
if ( V_14 == 2 )
V_14 = 0 ;
else if ( V_14 >= 0 )
V_14 = - V_30 ;
return V_14 ;
}
struct V_34 * F_15 ( enum V_35 V_36 )
{
struct V_37 * V_38 = & V_22 [ V_36 ] ;
return & V_38 -> V_29 ;
}
static int F_16 ( struct V_34 * V_29 ,
struct V_39 * V_40 ,
struct V_4 * V_41 ,
struct V_42 * V_43 )
{
V_40 -> V_44 = F_10 ;
V_40 -> V_45 = F_1 ;
V_40 -> V_46 = F_9 ;
V_40 -> V_47 = F_7 ;
V_40 -> V_48 = 10 ;
V_40 -> V_49 = 2 ;
V_40 -> V_1 = V_41 ;
sprintf ( V_29 -> V_50 , L_2 ,
V_41 -> V_10 ) ;
V_29 -> V_51 = V_52 ;
V_29 -> V_53 = V_54 ;
V_29 -> V_55 = V_40 ;
if ( V_43 )
V_29 -> V_56 . V_57 = & V_43 -> V_56 ;
else
V_29 -> V_56 . V_57 = NULL ;
F_10 ( V_41 , 1 ) ;
F_1 ( V_41 , 1 ) ;
V_48 ( 20 ) ;
return F_17 ( V_29 ) ;
}
static int F_18 ( struct V_58 * V_59 )
{
int V_60 , V_14 ;
struct V_4 * V_61 ;
V_7 = V_59 -> V_56 . V_62 ;
V_61 = V_7 -> V_63 ;
for ( V_60 = 0 ; V_60 < V_64 ; V_60 ++ ) {
struct V_4 * V_41 = V_61 ++ ;
struct V_37 * V_65 = & V_22 [ V_60 ] ;
V_65 -> V_23 = 0 ;
if ( V_41 -> type == 0 || V_41 -> V_66 != V_67 )
continue;
V_14 = F_16 ( & V_65 -> V_29 ,
& V_65 -> V_40 , V_41 ,
NULL ) ;
if ( V_14 < 0 ) {
F_4 ( V_13 L_3 ,
V_60 , V_14 ) ;
continue;
}
V_65 -> V_23 = 1 ;
}
return 0 ;
}
static int F_19 ( struct V_58 * V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_64 ; V_60 ++ ) {
struct V_37 * V_65 = & V_22 [ V_60 ] ;
if ( V_65 -> V_23 )
F_20 ( & V_65 -> V_29 ) ;
}
return 0 ;
}
int F_21 ( void )
{
return F_22 ( & V_68 ) ;
}
void F_23 ( void )
{
F_24 ( & V_68 ) ;
}
