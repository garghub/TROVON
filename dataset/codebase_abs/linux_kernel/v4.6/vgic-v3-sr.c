static T_1 T_2 F_1 ( unsigned int V_1 )
{
switch ( V_1 & 0xf ) {
case 0 :
return F_2 ( V_2 ) ;
case 1 :
return F_2 ( V_3 ) ;
case 2 :
return F_2 ( V_4 ) ;
case 3 :
return F_2 ( V_5 ) ;
case 4 :
return F_2 ( V_6 ) ;
case 5 :
return F_2 ( V_7 ) ;
case 6 :
return F_2 ( V_8 ) ;
case 7 :
return F_2 ( V_9 ) ;
case 8 :
return F_2 ( V_10 ) ;
case 9 :
return F_2 ( V_11 ) ;
case 10 :
return F_2 ( V_12 ) ;
case 11 :
return F_2 ( V_13 ) ;
case 12 :
return F_2 ( V_14 ) ;
case 13 :
return F_2 ( V_15 ) ;
case 14 :
return F_2 ( V_16 ) ;
case 15 :
return F_2 ( V_17 ) ;
}
F_3 () ;
}
static void T_2 F_4 ( T_1 V_18 , int V_1 )
{
switch ( V_1 & 0xf ) {
case 0 :
F_5 ( V_18 , V_2 ) ;
break;
case 1 :
F_5 ( V_18 , V_3 ) ;
break;
case 2 :
F_5 ( V_18 , V_4 ) ;
break;
case 3 :
F_5 ( V_18 , V_5 ) ;
break;
case 4 :
F_5 ( V_18 , V_6 ) ;
break;
case 5 :
F_5 ( V_18 , V_7 ) ;
break;
case 6 :
F_5 ( V_18 , V_8 ) ;
break;
case 7 :
F_5 ( V_18 , V_9 ) ;
break;
case 8 :
F_5 ( V_18 , V_10 ) ;
break;
case 9 :
F_5 ( V_18 , V_11 ) ;
break;
case 10 :
F_5 ( V_18 , V_12 ) ;
break;
case 11 :
F_5 ( V_18 , V_13 ) ;
break;
case 12 :
F_5 ( V_18 , V_14 ) ;
break;
case 13 :
F_5 ( V_18 , V_15 ) ;
break;
case 14 :
F_5 ( V_18 , V_16 ) ;
break;
case 15 :
F_5 ( V_18 , V_17 ) ;
break;
}
}
static void T_2 F_6 ( struct V_19 * V_20 , int V_21 )
{
struct V_22 * V_23 = & V_20 -> V_24 . V_25 . V_26 ;
int V_27 ;
bool V_28 ;
V_28 = ! ! ( V_23 -> V_29 & V_30 ) ;
for ( V_27 = 0 ; V_27 < V_21 ; V_27 ++ ) {
if ( ! ( V_20 -> V_24 . V_25 . V_31 & ( 1UL << V_27 ) ) )
continue;
V_28 |= ( ! ( V_23 -> V_32 [ V_27 ] & V_33 ) &&
( V_23 -> V_32 [ V_27 ] & V_34 ) ) ;
}
if ( V_28 ) {
V_23 -> V_35 = F_2 ( V_36 ) ;
if ( V_23 -> V_35 & V_37 )
V_23 -> V_38 = F_2 ( V_39 ) ;
else
V_23 -> V_38 = 0 ;
} else {
V_23 -> V_35 = 0 ;
V_23 -> V_38 = 0 ;
}
}
void T_2 F_7 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = & V_20 -> V_24 . V_25 . V_26 ;
T_1 V_18 ;
F_8 ( V_40 ) ;
V_23 -> V_41 = F_2 ( V_42 ) ;
if ( V_20 -> V_24 . V_25 . V_31 ) {
int V_27 ;
T_3 V_43 , V_44 ;
V_23 -> V_45 = F_2 ( V_46 ) ;
F_5 ( 0 , V_47 ) ;
V_18 = F_2 ( V_48 ) ;
V_43 = F_9 ( V_18 ) ;
V_44 = F_10 ( V_18 ) ;
F_6 ( V_20 , V_43 + 1 ) ;
for ( V_27 = 0 ; V_27 <= V_43 ; V_27 ++ ) {
if ( ! ( V_20 -> V_24 . V_25 . V_31 & ( 1UL << V_27 ) ) )
continue;
if ( V_23 -> V_45 & ( 1 << V_27 ) ) {
V_23 -> V_32 [ V_27 ] &= ~ V_49 ;
continue;
}
V_23 -> V_32 [ V_27 ] = F_1 ( V_27 ) ;
F_4 ( 0 , V_27 ) ;
}
switch ( V_44 ) {
case 7 :
V_23 -> V_50 [ 3 ] = F_2 ( V_51 ) ;
V_23 -> V_50 [ 2 ] = F_2 ( V_52 ) ;
case 6 :
V_23 -> V_50 [ 1 ] = F_2 ( V_53 ) ;
default:
V_23 -> V_50 [ 0 ] = F_2 ( V_54 ) ;
}
switch ( V_44 ) {
case 7 :
V_23 -> V_55 [ 3 ] = F_2 ( V_56 ) ;
V_23 -> V_55 [ 2 ] = F_2 ( V_57 ) ;
case 6 :
V_23 -> V_55 [ 1 ] = F_2 ( V_58 ) ;
default:
V_23 -> V_55 [ 0 ] = F_2 ( V_59 ) ;
}
V_20 -> V_24 . V_25 . V_31 = 0 ;
} else {
V_23 -> V_35 = 0 ;
V_23 -> V_38 = 0 ;
V_23 -> V_45 = 0xffff ;
V_23 -> V_50 [ 0 ] = 0 ;
V_23 -> V_50 [ 1 ] = 0 ;
V_23 -> V_50 [ 2 ] = 0 ;
V_23 -> V_50 [ 3 ] = 0 ;
V_23 -> V_55 [ 0 ] = 0 ;
V_23 -> V_55 [ 1 ] = 0 ;
V_23 -> V_55 [ 2 ] = 0 ;
V_23 -> V_55 [ 3 ] = 0 ;
}
V_18 = F_2 ( V_60 ) ;
F_5 ( V_18 | V_61 , V_60 ) ;
F_11 () ;
F_5 ( 1 , V_62 ) ;
}
void T_2 F_12 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = & V_20 -> V_24 . V_25 . V_26 ;
T_1 V_18 ;
T_3 V_43 , V_44 ;
T_4 V_31 = 0 ;
int V_27 ;
F_5 ( V_23 -> V_63 , V_62 ) ;
F_11 () ;
V_18 = F_2 ( V_48 ) ;
V_43 = F_9 ( V_18 ) ;
V_44 = F_10 ( V_18 ) ;
for ( V_27 = 0 ; V_27 <= V_43 ; V_27 ++ ) {
if ( V_23 -> V_32 [ V_27 ] & V_49 )
V_31 |= ( 1 << V_27 ) ;
}
F_5 ( V_23 -> V_41 , V_42 ) ;
if ( V_31 ) {
F_5 ( V_23 -> V_29 , V_47 ) ;
switch ( V_44 ) {
case 7 :
F_5 ( V_23 -> V_50 [ 3 ] , V_51 ) ;
F_5 ( V_23 -> V_50 [ 2 ] , V_52 ) ;
case 6 :
F_5 ( V_23 -> V_50 [ 1 ] , V_53 ) ;
default:
F_5 ( V_23 -> V_50 [ 0 ] , V_54 ) ;
}
switch ( V_44 ) {
case 7 :
F_5 ( V_23 -> V_55 [ 3 ] , V_56 ) ;
F_5 ( V_23 -> V_55 [ 2 ] , V_57 ) ;
case 6 :
F_5 ( V_23 -> V_55 [ 1 ] , V_58 ) ;
default:
F_5 ( V_23 -> V_55 [ 0 ] , V_59 ) ;
}
for ( V_27 = 0 ; V_27 <= V_43 ; V_27 ++ ) {
if ( ! ( V_31 & ( 1 << V_27 ) ) )
continue;
F_4 ( V_23 -> V_32 [ V_27 ] , V_27 ) ;
}
}
F_11 () ;
F_8 ( V_64 ) ;
V_20 -> V_24 . V_25 . V_31 = V_31 ;
if ( ! V_23 -> V_63 ) {
F_5 ( F_2 ( V_60 ) & ~ V_61 ,
V_60 ) ;
}
}
void T_2 F_13 ( void )
{
int V_43 = F_9 ( F_2 ( V_48 ) ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 <= V_43 ; V_27 ++ )
F_4 ( 0 , V_27 ) ;
}
static T_1 T_2 F_14 ( void )
{
return F_2 ( V_48 ) ;
}
