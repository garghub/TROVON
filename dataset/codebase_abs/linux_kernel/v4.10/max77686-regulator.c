static unsigned int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 ... V_4 :
return 0 ;
case V_5 ... V_6 :
return V_7 ;
default:
return V_8 ;
}
}
static unsigned int F_2 ( struct V_9 * V_10 ,
int V_1 )
{
switch ( V_1 ) {
case V_11 :
case V_4 :
case V_12 ... V_13 :
if ( F_3 ( V_1 , V_10 -> V_14 ) )
return V_15 ;
}
return V_16 ;
}
static int F_4 ( struct V_17 * V_18 )
{
unsigned int V_19 , V_20 ;
struct V_9 * V_10 = F_5 ( V_18 ) ;
int V_21 , V_1 = F_6 ( V_18 ) ;
V_20 = F_1 ( V_1 ) ;
V_19 = V_22 ;
V_21 = F_7 ( V_18 -> V_23 , V_18 -> V_24 -> V_25 ,
V_18 -> V_24 -> V_26 , V_19 << V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 -> V_27 [ V_1 ] = V_19 ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
unsigned int V_28 )
{
struct V_9 * V_10 = F_5 ( V_18 ) ;
unsigned int V_19 ;
int V_21 , V_1 = F_6 ( V_18 ) ;
if ( V_1 >= V_3 )
return 0 ;
switch ( V_28 ) {
case V_29 :
V_19 = V_30 ;
break;
case V_31 :
V_19 = F_2 ( V_10 , V_1 ) ;
break;
default:
F_9 ( L_1 ,
V_18 -> V_24 -> V_32 , V_28 ) ;
return - V_33 ;
}
V_21 = F_7 ( V_18 -> V_23 , V_18 -> V_24 -> V_25 ,
V_18 -> V_24 -> V_26 ,
V_19 << V_8 ) ;
if ( V_21 )
return V_21 ;
V_10 -> V_27 [ V_1 ] = V_19 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 ,
unsigned int V_28 )
{
unsigned int V_19 ;
struct V_9 * V_10 = F_5 ( V_18 ) ;
int V_21 , V_1 = F_6 ( V_18 ) ;
switch ( V_28 ) {
case V_34 :
V_19 = V_22 ;
break;
case V_29 :
V_19 = V_30 ;
break;
case V_31 :
V_19 = F_2 ( V_10 , V_1 ) ;
break;
default:
F_9 ( L_1 ,
V_18 -> V_24 -> V_32 , V_28 ) ;
return - V_33 ;
}
V_21 = F_7 ( V_18 -> V_23 , V_18 -> V_24 -> V_25 ,
V_18 -> V_24 -> V_26 ,
V_19 << V_8 ) ;
if ( V_21 )
return V_21 ;
V_10 -> V_27 [ V_1 ] = V_19 ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = F_5 ( V_18 ) ;
unsigned int V_20 ;
int V_1 = F_6 ( V_18 ) ;
V_20 = F_1 ( V_1 ) ;
if ( V_10 -> V_27 [ V_1 ] == V_22 )
V_10 -> V_27 [ V_1 ] = F_2 ( V_10 , V_1 ) ;
return F_7 ( V_18 -> V_23 , V_18 -> V_24 -> V_25 ,
V_18 -> V_24 -> V_26 ,
V_10 -> V_27 [ V_1 ] << V_20 ) ;
}
static int F_12 ( struct V_17 * V_18 , int V_35 )
{
unsigned int V_36 = V_37 ;
switch ( V_35 ) {
case 1 ... 13750 :
V_36 = V_38 ;
break;
case 13751 ... 27500 :
V_36 = V_39 ;
break;
case 27501 ... 55000 :
V_36 = V_40 ;
break;
case 55001 ... 100000 :
break;
default:
F_9 ( L_2 ,
V_18 -> V_24 -> V_32 , V_35 ) ;
}
return F_7 ( V_18 -> V_23 , V_18 -> V_24 -> V_25 ,
V_41 , V_36 << 6 ) ;
}
static int F_13 ( struct V_42 * V_43 ,
const struct V_44 * V_24 ,
struct V_45 * V_46 )
{
struct V_9 * V_10 = V_46 -> V_47 ;
switch ( V_24 -> V_1 ) {
case V_11 :
case V_4 :
case V_12 ... V_13 :
V_46 -> V_48 = F_14 ( V_43 ,
L_3 , 0 ) ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = true ;
break;
default:
return 0 ;
}
if ( F_15 ( V_46 -> V_48 ) ) {
F_16 ( V_24 -> V_1 , V_10 -> V_14 ) ;
return F_7 ( V_46 -> V_23 , V_24 -> V_25 ,
V_24 -> V_26 ,
V_15 ) ;
}
return 0 ;
}
static int F_17 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_18 ( V_53 -> V_56 . V_57 ) ;
struct V_9 * V_10 ;
int V_58 ;
struct V_45 V_46 = { } ;
F_19 ( & V_53 -> V_56 , L_4 , V_59 ) ;
V_10 = F_20 ( & V_53 -> V_56 , sizeof( struct V_9 ) ,
V_60 ) ;
if ( ! V_10 )
return - V_61 ;
V_46 . V_56 = V_55 -> V_56 ;
V_46 . V_23 = V_55 -> V_23 ;
V_46 . V_47 = V_10 ;
F_21 ( V_53 , V_10 ) ;
for ( V_58 = 0 ; V_58 < V_62 ; V_58 ++ ) {
struct V_17 * V_18 ;
int V_1 = V_63 [ V_58 ] . V_1 ;
V_10 -> V_27 [ V_1 ] = V_16 ;
V_18 = F_22 ( & V_53 -> V_56 ,
& V_63 [ V_58 ] , & V_46 ) ;
if ( F_23 ( V_18 ) ) {
int V_21 = F_24 ( V_18 ) ;
F_25 ( & V_53 -> V_56 ,
L_5 , V_58 , V_21 ) ;
return V_21 ;
}
}
return 0 ;
}
