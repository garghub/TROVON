static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 = 0 ;
switch ( V_3 & V_5 ) {
case V_6 :
break;
default:
F_2 ( V_7 L_1 , V_8 ) ;
V_4 = - V_9 ;
break;
}
switch ( V_3 & V_10 ) {
case V_11 :
break;
case V_12 :
case V_13 :
case V_14 :
V_4 = - V_9 ;
break;
default:
F_2 ( V_7 L_2 , V_8 ) ;
V_4 = - V_9 ;
break;
}
return V_4 ;
}
static int F_3 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
int V_4 = 0 ;
V_23 -> V_25 &= ~ 0x1f ;
V_23 -> V_26 &= ~ 0x1f ;
switch ( F_5 ( V_18 ) ) {
case V_27 :
V_23 -> V_25 |= 31 ;
V_23 -> V_26 |= 31 ;
V_21 -> V_28 = 4 ;
break;
default:
F_6 ( L_3 ) ;
return - V_9 ;
break;
}
if ( ! V_23 -> V_29 ) {
V_4 = F_7 ( V_21 , V_23 -> V_30 ,
V_23 -> V_26 , 0 , 0 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
return - V_31 ;
}
V_4 = F_8 ( V_21 , V_23 -> V_32 ,
V_23 -> V_25 , 0 , 0 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
return - V_31 ;
}
V_23 -> V_29 = 1 ;
}
return 0 ;
}
static void F_9 ( struct V_15 * V_16 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
if ( ! V_19 -> V_33 )
V_23 -> V_29 = 0 ;
}
static int F_10 ( struct V_1 * V_19 ,
unsigned int V_34 , unsigned int * V_35 ,
unsigned int V_36 , unsigned int * V_37 )
{
struct V_20 * V_21 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
int V_38 ;
unsigned int V_39 ;
unsigned int V_40 = 0 , V_41 = 0 ;
if ( ( V_34 > V_42 ) ||
( V_36 > V_42 ) )
return - V_9 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ ) {
V_39 = V_35 [ V_38 ] ;
if ( ( V_39 < V_42 ) &&
( ! ( V_40 & ( 1 << V_39 ) ) ) ) {
V_23 -> V_43 [ V_38 ] = V_39 ;
V_40 |= 1 << V_39 ;
} else
return - V_9 ;
}
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
V_39 = V_37 [ V_38 ] ;
if ( ( V_39 < V_42 ) &&
( ! ( V_41 & ( 1 << V_39 ) ) ) ) {
V_23 -> V_44 [ V_38 ] = V_39 ;
V_41 |= 1 << V_39 ;
} else
return - V_9 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_19 )
{
struct V_20 * V_45 = F_4 ( V_19 ) ;
if ( V_19 -> V_46 )
F_12 ( V_45 ) ;
if ( V_19 -> V_47 )
F_13 ( V_45 ) ;
F_14 ( V_45 -> V_48 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_19 )
{
int V_4 ;
struct V_20 * V_45 = F_4 ( V_19 ) ;
V_4 = F_16 ( V_45 , 8 , 0xFF , 1 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
V_4 = - V_31 ;
}
V_4 = F_7 ( V_45 , 0 , 0x1F , 0 , 0 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
V_4 = - V_31 ;
}
V_4 = F_8 ( V_45 , 0 , 0x1F , 0 , 0 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
V_4 = - V_31 ;
}
F_17 ( V_45 -> V_48 , L_5 ) ;
return 0 ;
}
static int F_18 ( struct V_49 * V_50 )
{
struct V_20 * V_21 ;
int V_4 ;
V_21 = F_19 ( V_50 , 4 , 8 * sizeof( V_51 ) ,
sizeof( struct V_22 ) ) ;
if ( ! V_21 )
return - V_52 ;
V_4 = F_16 ( V_21 , 8 , 0xFF , 1 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
V_4 = - V_31 ;
goto V_53;
}
V_4 = F_7 ( V_21 , 0 , 0x1F , 0 , 0 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
V_4 = - V_31 ;
goto V_53;
}
V_4 = F_8 ( V_21 , 0 , 0x1F , 0 , 0 ) ;
if ( V_4 ) {
F_6 ( L_4 ) ;
V_4 = - V_31 ;
goto V_53;
}
V_4 = F_20 ( & V_50 -> V_54 , & V_55 ,
& V_56 , 1 ) ;
if ( V_4 ) {
F_6 ( L_6 , V_4 ) ;
goto V_53;
}
return 0 ;
V_53:
F_21 ( V_21 ) ;
return V_4 ;
}
static int F_22 ( struct V_49 * V_50 )
{
struct V_20 * V_21 = F_23 ( V_50 ) ;
F_24 ( & V_50 -> V_54 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
