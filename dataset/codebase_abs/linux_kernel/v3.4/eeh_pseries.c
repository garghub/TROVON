static int F_1 ( void )
{
V_1 = F_2 ( L_1 ) ;
V_2 = F_2 ( L_2 ) ;
V_3 = F_2 ( L_3 ) ;
V_4 = F_2 ( L_4 ) ;
V_5 = F_2 ( L_5 ) ;
V_6 = F_2 ( L_6 ) ;
V_7 = F_2 ( L_7 ) ;
V_8 = F_2 ( L_8 ) ;
V_9 = F_2 ( L_9 ) ;
if ( V_1 == V_10 ) {
F_3 ( L_10 ,
V_11 ) ;
return - V_12 ;
} else if ( V_2 == V_10 ) {
F_3 ( L_11 ,
V_11 ) ;
return - V_12 ;
} else if ( V_3 == V_10 &&
V_4 == V_10 ) {
F_3 ( L_12
L_13 ,
V_11 ) ;
return - V_12 ;
} else if ( V_5 == V_10 ) {
F_3 ( L_14 ,
V_11 ) ;
return - V_12 ;
} else if ( V_6 == V_10 &&
V_7 == V_10 ) {
F_3 ( L_15
L_16 ,
V_11 ) ;
return - V_12 ;
} else if ( V_8 == V_10 &&
V_9 == V_10 ) {
F_3 ( L_17
L_18 ,
V_11 ) ;
return - V_12 ;
}
F_4 ( & V_13 ) ;
V_14 = F_2 ( L_19 ) ;
if ( V_14 == V_10 ) {
F_3 ( L_20 ,
V_11 ) ;
V_14 = 1024 ;
} else if ( V_14 > V_15 ) {
F_3 ( L_21 ,
V_11 , V_14 , V_15 ) ;
V_14 = V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_16 * V_17 , int V_18 )
{
int V_19 = 0 ;
struct V_20 * V_21 ;
const T_1 * V_22 ;
int V_23 ;
V_21 = F_6 ( V_17 ) ;
switch ( V_18 ) {
case V_24 :
case V_25 :
V_22 = F_7 ( V_17 , L_22 , NULL ) ;
V_23 = V_22 [ 0 ] ;
break;
case V_26 :
case V_27 :
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_28 )
V_23 = V_21 -> V_28 ;
break;
default:
F_8 ( L_23 ,
V_11 , V_18 ) ;
return - V_12 ;
}
V_19 = F_9 ( V_1 , 4 , 1 , NULL ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) , V_18 ) ;
return V_19 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_20 * V_21 ;
int V_19 = 0 ;
int V_31 [ 3 ] ;
V_21 = F_6 ( V_17 ) ;
if ( V_6 != V_10 ) {
V_19 = F_9 ( V_6 , 4 , 2 , V_31 ,
V_21 -> V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) , 1 ) ;
if ( V_19 || ( V_31 [ 0 ] == 0 ) )
return 0 ;
V_19 = F_9 ( V_6 , 4 , 2 , V_31 ,
V_21 -> V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) , 0 ) ;
if ( V_19 ) {
F_3 ( L_24 ,
V_11 , V_17 -> V_32 ) ;
return 0 ;
}
return V_31 [ 0 ] ;
}
if ( V_7 != V_10 ) {
V_19 = F_9 ( V_7 , 4 , 2 , V_31 ,
V_21 -> V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) , 0 ) ;
if ( V_19 ) {
F_3 ( L_24 ,
V_11 , V_17 -> V_32 ) ;
return 0 ;
}
return V_31 [ 0 ] ;
}
return V_19 ;
}
static int F_13 ( struct V_16 * V_17 , int * V_33 )
{
struct V_20 * V_21 ;
int V_23 ;
int V_19 ;
int V_31 [ 4 ] ;
int V_34 ;
V_21 = F_6 ( V_17 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_28 )
V_23 = V_21 -> V_28 ;
if ( V_3 != V_10 ) {
V_19 = F_9 ( V_3 , 3 , 4 , V_31 ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) ) ;
} else if ( V_4 != V_10 ) {
V_31 [ 2 ] = 0 ;
V_19 = F_9 ( V_4 , 3 , 3 , V_31 ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) ) ;
} else {
return V_35 ;
}
if ( V_19 )
return V_19 ;
V_34 = 0 ;
if ( V_31 [ 1 ] ) {
switch( V_31 [ 0 ] ) {
case 0 :
V_34 &= ~ V_36 ;
V_34 |= V_37 ;
V_34 |= V_38 ;
break;
case 1 :
V_34 |= V_36 ;
V_34 |= V_37 ;
V_34 |= V_38 ;
break;
case 2 :
V_34 &= ~ V_36 ;
V_34 &= ~ V_37 ;
V_34 &= ~ V_38 ;
break;
case 4 :
V_34 &= ~ V_36 ;
V_34 &= ~ V_37 ;
V_34 &= ~ V_38 ;
V_34 |= V_39 ;
break;
case 5 :
if ( V_31 [ 2 ] ) {
if ( V_33 ) * V_33 = V_31 [ 2 ] ;
V_34 = V_40 ;
} else {
V_34 = V_35 ;
}
default:
V_34 = V_35 ;
}
} else {
V_34 = V_35 ;
}
return V_34 ;
}
static int F_14 ( struct V_16 * V_17 , int V_18 )
{
struct V_20 * V_21 ;
int V_23 ;
int V_19 ;
V_21 = F_6 ( V_17 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_28 )
V_23 = V_21 -> V_28 ;
V_19 = F_9 ( V_2 , 4 , 1 , NULL ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) , V_18 ) ;
if ( V_18 == V_41 &&
V_19 == - 8 ) {
V_19 = F_9 ( V_2 , 4 , 1 , NULL ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) , V_42 ) ;
}
return V_19 ;
}
static int F_15 ( struct V_16 * V_17 , int V_43 )
{
int V_19 ;
int V_44 ;
#define F_16 (1000)
#define F_17 (300 * 1000)
while ( 1 ) {
V_19 = F_13 ( V_17 , & V_44 ) ;
if ( V_19 != V_40 )
return V_19 ;
if ( V_43 <= 0 ) {
F_3 ( L_25 ,
V_11 , V_43 ) ;
return V_35 ;
}
if ( V_44 <= 0 ) {
F_3 ( L_26 ,
V_11 , V_44 ) ;
V_44 = F_16 ;
} else if ( V_44 > F_17 ) {
F_3 ( L_27 ,
V_11 , V_44 ) ;
V_44 = F_17 ;
}
V_43 -= V_44 ;
F_18 ( V_44 ) ;
}
return V_35 ;
}
static int F_19 ( struct V_16 * V_17 , int V_45 , char * V_46 , unsigned long V_47 )
{
struct V_20 * V_21 ;
int V_23 ;
unsigned long V_48 ;
int V_19 ;
V_21 = F_6 ( V_17 ) ;
F_20 ( & V_13 , V_48 ) ;
memset ( V_49 , 0 , V_14 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_28 )
V_23 = V_21 -> V_28 ;
V_19 = F_9 ( V_5 , 8 , 1 , NULL , V_23 ,
F_10 ( V_21 -> V_29 -> V_30 ) , F_11 ( V_21 -> V_29 -> V_30 ) ,
F_21 ( V_46 ) , V_47 ,
F_21 ( V_49 ) , V_14 ,
V_45 ) ;
if ( ! V_19 )
F_22 ( V_49 , V_50 , 0 ) ;
F_23 ( & V_13 , V_48 ) ;
return V_19 ;
}
static int F_24 ( struct V_16 * V_17 )
{
struct V_20 * V_21 ;
int V_23 ;
int V_19 ;
V_21 = F_6 ( V_17 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_28 )
V_23 = V_21 -> V_28 ;
if ( V_8 != V_10 ) {
V_19 = F_9 ( V_8 , 3 , 1 , NULL ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) ) ;
} else if ( V_9 != V_10 ) {
V_19 = F_9 ( V_9 , 3 , 1 , NULL ,
V_23 , F_10 ( V_21 -> V_29 -> V_30 ) ,
F_11 ( V_21 -> V_29 -> V_30 ) ) ;
} else {
return - V_51 ;
}
if ( V_19 )
F_3 ( L_28 ,
V_11 , V_19 , V_17 -> V_32 ) ;
return V_19 ;
}
static int F_25 ( struct V_16 * V_17 , int V_52 , int V_53 , T_1 * V_54 )
{
struct V_55 * V_56 ;
V_56 = F_26 ( V_17 ) ;
return F_27 ( V_56 , V_52 , V_53 , V_54 ) ;
}
static int F_28 ( struct V_16 * V_17 , int V_52 , int V_53 , T_1 V_54 )
{
struct V_55 * V_56 ;
V_56 = F_26 ( V_17 ) ;
return F_29 ( V_56 , V_52 , V_53 , V_54 ) ;
}
int T_2 F_30 ( void )
{
return F_31 ( & V_57 ) ;
}
