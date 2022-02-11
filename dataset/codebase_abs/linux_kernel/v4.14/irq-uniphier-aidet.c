static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_6 ;
T_1 V_7 ;
F_2 ( & V_2 -> V_8 , V_6 ) ;
V_7 = F_3 ( V_2 -> V_9 + V_3 ) ;
V_7 &= ~ V_4 ;
V_7 |= V_4 & V_5 ;
F_4 ( V_7 , V_2 -> V_9 + V_3 ) ;
F_5 ( & V_2 -> V_8 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned long V_10 , unsigned int V_5 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_11 + V_10 / 32 * 4 ;
V_4 = F_7 ( V_10 % 32 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 ? V_4 : 0 ) ;
}
static int F_8 ( struct V_12 * V_13 , unsigned int type )
{
struct V_1 * V_2 = V_13 -> V_14 ;
unsigned int V_5 ;
switch ( type ) {
case V_15 :
case V_16 :
V_5 = 0 ;
break;
case V_17 :
V_5 = 1 ;
type = V_15 ;
break;
case V_18 :
V_5 = 1 ;
type = V_16 ;
break;
default:
return - V_19 ;
}
F_6 ( V_2 , V_13 -> V_20 , V_5 ) ;
return F_9 ( V_13 , type ) ;
}
static int F_10 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long * V_25 ,
unsigned int * V_26 )
{
if ( F_11 ( V_24 -> V_27 < 2 ) )
return - V_19 ;
* V_25 = V_24 -> V_28 [ 0 ] ;
* V_26 = V_24 -> V_28 [ 1 ] & V_29 ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 ,
unsigned int V_30 , unsigned int V_31 ,
void * V_32 )
{
struct V_23 V_33 ;
T_2 V_20 ;
unsigned int type ;
int V_34 ;
if ( V_31 != 1 )
return - V_19 ;
V_34 = F_10 ( V_22 , V_32 , & V_20 , & type ) ;
if ( V_34 )
return V_34 ;
switch ( type ) {
case V_15 :
case V_16 :
break;
case V_17 :
type = V_15 ;
break;
case V_18 :
type = V_16 ;
break;
default:
return - V_19 ;
}
if ( V_20 >= V_35 )
return - V_36 ;
V_34 = F_13 ( V_22 , V_30 , V_20 ,
& V_37 ,
V_22 -> V_38 ) ;
if ( V_34 )
return V_34 ;
V_33 . V_39 = V_22 -> V_40 -> V_39 ;
V_33 . V_27 = 3 ;
V_33 . V_28 [ 0 ] = 0 ;
V_33 . V_28 [ 1 ] = V_20 ;
V_33 . V_28 [ 2 ] = type ;
return F_14 ( V_22 , V_30 , 1 , & V_33 ) ;
}
static int F_15 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_44 ;
struct V_45 * V_46 ;
struct V_21 * V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
V_46 = F_16 ( V_44 -> V_50 ) ;
if ( ! V_46 )
return - V_36 ;
V_47 = F_17 ( V_46 ) ;
F_18 ( V_46 ) ;
if ( ! V_47 )
return - V_51 ;
V_2 = F_19 ( V_44 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_49 = F_20 ( V_42 , V_54 , 0 ) ;
V_2 -> V_9 = F_21 ( V_44 , V_49 ) ;
if ( F_22 ( V_2 -> V_9 ) )
return F_23 ( V_2 -> V_9 ) ;
F_24 ( & V_2 -> V_8 ) ;
V_2 -> V_22 = F_25 (
V_47 , 0 ,
V_35 ,
F_26 ( V_44 -> V_50 ) ,
& V_55 , V_2 ) ;
if ( ! V_2 -> V_22 )
return - V_53 ;
F_27 ( V_42 , V_2 ) ;
return 0 ;
}
static int T_3 F_28 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_29 ( V_44 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < F_30 ( V_2 -> V_57 ) ; V_56 ++ )
V_2 -> V_57 [ V_56 ] = F_3 (
V_2 -> V_9 + V_11 + V_56 * 4 ) ;
return 0 ;
}
static int T_3 F_31 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_29 ( V_44 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < F_30 ( V_2 -> V_57 ) ; V_56 ++ )
F_4 ( V_2 -> V_57 [ V_56 ] ,
V_2 -> V_9 + V_11 + V_56 * 4 ) ;
return 0 ;
}
