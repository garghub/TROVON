T_1 F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 V_6 [ 2 ] ;
T_1 V_7 ;
V_6 [ 0 ] . V_8 = 0 ;
V_6 [ 0 ] . V_3 = V_3 ;
V_6 [ 0 ] . V_9 = 1 ;
V_6 [ 0 ] . V_10 = & V_4 ;
V_6 [ 1 ] . V_8 = V_11 ;
V_6 [ 1 ] . V_3 = V_3 ;
V_6 [ 1 ] . V_9 = 1 ;
V_6 [ 1 ] . V_10 = & V_7 ;
F_2 ( & V_1 -> V_12 [ V_2 ] , V_6 , 2 ) ;
return V_7 ;
}
void F_3 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_7 )
{
struct V_5 V_6 ;
T_1 V_10 [ 2 ] ;
V_10 [ 0 ] = V_4 ;
V_10 [ 1 ] = V_7 ;
V_6 . V_8 = 0 ;
V_6 . V_3 = V_3 ;
V_6 . V_9 = 2 ;
V_6 . V_10 = V_10 ;
F_2 ( & V_1 -> V_12 [ V_2 ] , & V_6 , 1 ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_13 )
{
T_2 V_14 ;
V_14 = F_5 ( V_1 -> V_15 ) ;
if ( V_1 -> V_16 == V_17 )
V_14 |= V_18 ;
if ( V_13 ) {
V_14 |= V_19 ;
} else {
V_14 |= V_20 ;
if ( ! ( V_1 -> V_5 -> V_8 & V_21 ) )
V_14 |= V_22 ;
}
if ( V_1 -> V_23 == V_1 -> V_5 -> V_9 )
V_14 |= V_24 ;
F_6 ( V_1 , V_25 , V_14 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
T_2 V_3 = V_1 -> V_5 -> V_3 << 1 ;
if ( V_1 -> V_5 -> V_8 & V_11 )
V_3 |= 1 ;
V_1 -> V_16 = V_17 ;
F_6 ( V_1 , V_26 , V_3 ) ;
F_4 ( V_1 , 1 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_9 ( V_1 , V_27 ) ;
F_6 ( V_1 , V_25 , 0 ) ;
V_1 -> V_16 = V_28 ;
F_10 ( & V_1 -> V_29 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
V_30:
if ( V_1 -> V_23 != V_1 -> V_5 -> V_9 ) {
F_4 ( V_1 , 0 ) ;
return 0 ;
}
V_1 -> V_23 = 0 ;
V_1 -> V_5 ++ ;
V_1 -> V_31 -- ;
if ( V_1 -> V_31 == 0 ) {
F_8 ( V_1 ) ;
return 0 ;
}
if ( ! ( V_1 -> V_5 -> V_8 & V_32 ) ) {
F_7 ( V_1 ) ;
} else {
if ( V_1 -> V_5 -> V_8 & V_11 )
goto V_30;
else
F_8 ( V_1 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
V_33:
if ( V_1 -> V_23 != V_1 -> V_5 -> V_9 ) {
F_6 ( V_1 , V_26 ,
V_1 -> V_5 -> V_10 [ V_1 -> V_23 ] ) ;
V_1 -> V_23 ++ ;
F_4 ( V_1 , 1 ) ;
return 0 ;
}
V_1 -> V_23 = 0 ;
V_1 -> V_5 ++ ;
V_1 -> V_31 -- ;
if ( V_1 -> V_31 == 0 ) {
F_8 ( V_1 ) ;
return 0 ;
}
if ( ! ( V_1 -> V_5 -> V_8 & V_32 ) ) {
F_7 ( V_1 ) ;
} else {
if ( V_1 -> V_5 -> V_8 & V_11 )
F_8 ( V_1 ) ;
else
goto V_33;
}
return 0 ;
}
int F_13 ( struct V_1 * V_1 )
{
T_2 V_34 = F_14 ( V_1 , V_25 ) ;
int V_35 = - V_36 ;
if ( F_15 ( V_34 , V_37 | V_38 )
|| V_1 -> V_15 < 0 ) {
F_8 ( V_1 ) ;
return - V_39 ;
}
switch ( V_1 -> V_16 ) {
case V_17 :
if ( V_1 -> V_5 -> V_8 & V_11 ) {
V_1 -> V_16 = V_40 ;
V_35 = F_11 ( V_1 ) ;
break;
}
V_1 -> V_16 = V_41 ;
case V_41 :
V_35 = F_12 ( V_1 ) ;
break;
case V_40 :
V_1 -> V_5 -> V_10 [ V_1 -> V_23 ] =
F_14 ( V_1 , V_42 ) ;
V_1 -> V_23 ++ ;
V_35 = F_11 ( V_1 ) ;
break;
default:
F_8 ( V_1 ) ;
}
return V_35 ;
}
static int F_16 ( struct V_43 * V_44 ,
struct V_5 V_6 [] , int V_45 )
{
struct V_1 * V_1 = V_44 -> V_46 ;
unsigned long V_47 ;
int V_35 ;
int V_48 ;
F_17 ( V_49 ) ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
if ( & V_1 -> V_12 [ V_48 ] == V_44 )
break;
}
if ( V_48 == V_50 )
return V_45 ;
F_18 ( & V_1 -> V_51 ) ;
V_1 -> V_15 = V_48 ;
V_1 -> V_5 = V_6 ;
V_1 -> V_31 = V_45 ;
V_1 -> V_23 = 0 ;
F_6 ( V_1 , V_25 , 0 ) ;
F_19 ( V_1 , V_27 ) ;
F_7 ( V_1 ) ;
V_47 = V_52 / 2 ;
for (; ; ) {
F_20 ( & V_1 -> V_29 , & V_49 ,
V_53 ) ;
if ( V_1 -> V_16 == V_28 )
break;
V_47 = F_21 ( V_47 ) ;
if ( ! V_47 )
break;
if ( F_22 ( V_54 ) )
break;
}
F_23 ( & V_1 -> V_29 , & V_49 ) ;
V_35 = V_45 - V_1 -> V_31 ;
V_1 -> V_16 = V_55 ;
V_1 -> V_15 = - 1 ;
F_24 ( & V_1 -> V_51 ) ;
return V_35 ;
}
static T_2 F_25 ( struct V_43 * V_44 )
{
return V_56 ;
}
int F_26 ( struct V_1 * V_1 )
{
int V_48 ;
int V_35 ;
F_6 ( V_1 , V_57 ,
F_27 ( 8 ) | V_58 ) ;
V_1 -> V_15 = - 1 ;
V_1 -> V_16 = V_55 ;
F_28 ( & V_1 -> V_29 ) ;
F_29 ( & V_1 -> V_51 ) ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
struct V_43 * V_44 = & V_1 -> V_12 [ V_48 ] ;
snprintf ( V_44 -> V_59 , V_60 , L_1 ,
V_61 , V_48 ) ;
V_44 -> V_62 = & V_63 ;
V_44 -> V_46 = V_1 ;
V_44 -> V_64 = 1 ;
V_44 -> V_65 . V_66 = & V_1 -> V_67 -> V_65 ;
V_35 = F_30 ( V_44 ) ;
if ( V_35 ) {
V_44 -> V_46 = NULL ;
break;
}
}
if ( V_35 ) {
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
if ( ! V_1 -> V_12 [ V_48 ] . V_46 )
break;
F_31 ( & V_1 -> V_12 [ V_48 ] ) ;
V_1 -> V_12 [ V_48 ] . V_46 = NULL ;
}
return V_35 ;
}
return 0 ;
}
void F_32 ( struct V_1 * V_1 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
if ( ! V_1 -> V_12 [ V_48 ] . V_46 )
continue;
F_31 ( & V_1 -> V_12 [ V_48 ] ) ;
V_1 -> V_12 [ V_48 ] . V_46 = NULL ;
}
}
