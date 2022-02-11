static T_1 F_1 (
struct V_1 V_2 ,
struct V_1 V_3 )
{
if ( V_2 . V_4 > V_3 . V_4 ) {
return 1 ;
} else if ( V_2 . V_4 < V_3 . V_4 ) {
return - 1 ;
} else if ( V_2 . V_5 > V_3 . V_5 ) {
return 1 ;
} else if ( V_2 . V_5 < V_3 . V_5 ) {
return - 1 ;
}
return 0 ;
}
static struct V_6 * F_2 (
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 ;
struct V_1 V_12 ;
struct V_1 V_13 ;
struct V_1 V_14 ;
struct V_1 V_15 ;
F_3 ( V_10 , & V_14 ) ;
F_4 ( V_10 , & V_15 ) ;
for ( V_11 = 0 ; V_11 < V_8 -> V_16 ; V_11 ++ ) {
struct V_6 * V_17 = & V_8 -> V_18 [ V_11 ] ;
F_5 ( V_17 , & V_12 ) ;
F_6 ( V_17 , & V_13 ) ;
if ( F_1 ( V_12 , V_14 ) == 0 &&
F_1 ( V_13 , V_15 ) == 0 )
return V_17 ;
}
return NULL ;
}
static enum V_19 F_7 (
struct V_7 * V_8 ,
struct V_20 * V_21 )
{
struct V_1 V_22 ;
struct V_1 V_23 ;
if ( V_21 -> V_24 [ 0 ] . V_25 != 0 ||
V_21 -> V_24 [ 1 ] . V_25 != 1 ||
V_21 -> V_24 [ 2 ] . V_25 != 2 ||
V_21 -> V_24 [ 3 ] . V_25 != 3 )
return V_26 ;
if ( V_21 -> V_24 [ 0 ] . V_27 == 0 &&
V_21 -> V_24 [ 1 ] . V_27 == 0 &&
V_21 -> V_24 [ 2 ] . V_27 == 0 &&
V_21 -> V_24 [ 3 ] . V_27 == 0 )
return V_28 ;
if ( V_21 -> V_24 [ 2 ] . V_27 == 1 ) {
return V_26 ;
}
F_3 ( & V_8 -> V_29 [ 0 ] , & V_22 ) ;
F_3 ( & V_8 -> V_29 [ 3 ] , & V_23 ) ;
if ( F_1 ( V_22 , V_23 ) == 0 ) {
return V_26 ;
}
if ( V_21 -> V_24 [ 0 ] . V_27 == 0 &&
V_21 -> V_24 [ 1 ] . V_27 == 1 ) {
F_3 ( & V_8 -> V_29 [ 0 ] , & V_22 ) ;
F_3 ( & V_8 -> V_29 [ 2 ] , & V_23 ) ;
if ( F_1 ( V_22 , V_23 ) == 0 ) {
return V_26 ;
}
}
if ( V_21 -> V_24 [ 2 ] . V_27 == 2 &&
V_21 -> V_24 [ 3 ] . V_27 == 3 ) {
F_3 ( & V_8 -> V_29 [ 1 ] , & V_22 ) ;
F_3 ( & V_8 -> V_29 [ 3 ] , & V_23 ) ;
if ( F_1 ( V_22 , V_23 ) == 0 ) {
return V_26 ;
}
}
return V_28 ;
}
static enum V_19
F_8 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
T_3 V_30 ;
T_3 V_31 ;
struct V_1 V_32 ;
struct V_1 V_33 ;
T_2 V_34 ;
T_2 V_35 ;
V_31 = 0 ;
V_32 . V_4 = 0 ;
V_32 . V_5 = 0 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
V_30 = V_8 -> V_37 . V_18 [ V_34 ] . V_30 ;
if ( ! V_30 )
continue;
if ( ( V_30 & ~ V_31 ) == 0 ) {
return V_26 ;
}
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
if ( ( V_30 & ( 1 << V_35 ) ) == 0 )
continue;
F_3 ( & V_8 -> V_29 [ V_35 ] ,
& V_32 ) ;
V_21 -> V_24 [ V_35 ] . V_27 = V_34 ;
V_21 -> V_24 [ V_35 ] . V_25 = V_35 ;
if ( V_35 != V_34 ) {
return V_26 ;
}
break;
}
while ( V_35 < V_38 ) {
if ( ( V_30 & ( 1 << V_35 ) ) == 0 )
continue;
F_3 ( & V_8 -> V_29 [ V_35 ] ,
& V_33 ) ;
if ( F_1 ( V_32 , V_33 ) != 0 ) {
return V_26 ;
}
V_21 -> V_24 [ V_35 ] . V_27 = V_34 ;
V_21 -> V_24 [ V_35 ] . V_25 = V_35 ;
F_9 ( & V_8 -> V_18 [ V_34 ] ,
& V_8 -> V_29 [ V_35 ] ) ;
V_31 |= ( 1 << V_35 ) ;
}
V_35 ++ ;
}
return F_7 ( V_8 , V_21 ) ;
}
static void F_10 ( unsigned long V_39 )
{
T_2 V_40 ;
struct V_41 * V_42 = (struct V_41 * ) V_39 ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
unsigned long V_43 ;
T_4 V_44 ;
V_21 = F_11 ( V_42 , F_12 ( * V_21 ) , V_45 ) ;
V_8 = F_11 ( V_21 , F_12 ( * V_8 ) , V_21 ) ;
F_13 ( & V_8 -> V_46 , V_43 ) ;
if ( V_42 -> V_47 )
goto V_48;
V_21 -> V_49 = false ;
V_44 = ~ V_21 -> V_50 & V_21 -> V_51 ;
for ( V_40 = 0 ; V_40 < V_38 ; V_40 ++ ) {
struct V_9 * V_10 = & V_8 -> V_29 [ V_40 ] ;
if ( V_44 & ( 1 << V_40 ) ) {
V_21 -> V_52 ( V_8 , V_21 ,
F_14 ( V_10 ) ,
V_10 ) ;
}
}
V_48:
F_15 ( & V_8 -> V_46 , V_43 ) ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_6 * V_17 ,
struct V_9 * V_10 )
{
if ( ! V_17 )
return;
V_21 -> V_51 |= ( 1 << V_10 -> V_35 ) ;
F_17 ( V_17 , V_10 ) ;
if ( ( V_17 -> V_53 & ( 1 << V_10 -> V_35 ) ) )
V_21 -> V_50 |= ( 1 << V_10 -> V_35 ) ;
}
static void F_18 (
struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_6 * V_17 ,
struct V_9 * V_10 )
{
if ( V_17 != NULL ) {
V_21 -> V_51 &= ~ ( 1 << V_10 -> V_35 ) ;
V_21 -> V_50 &= ~ ( 1 << V_10 -> V_35 ) ;
if ( ( V_21 -> V_50 == 0x0000 ) &&
( V_21 -> V_51 != 0x0000 ) &&
! V_21 -> V_49 ) {
V_21 -> V_49 = true ;
F_19 ( & V_21 -> V_45 ,
V_54 ) ;
}
F_20 ( V_17 , V_10 ) ;
}
}
static enum V_19
F_21 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
T_2 V_35 ;
T_2 V_34 ;
struct V_1 V_32 ;
struct V_1 V_33 ;
V_35 = 0 ;
while ( V_35 < V_38 ) {
V_34 = V_35 ;
F_3 ( & V_8 -> V_29 [ V_35 ] ,
& V_32 ) ;
while ( ++ V_35 < V_38 ) {
F_3 ( & V_8 -> V_29 [ V_35 ] ,
& V_33 ) ;
if ( F_1 ( V_32 , V_33 ) == 0 ) {
V_21 -> V_24 [ V_35 ] . V_27 = V_34 ;
V_21 -> V_24 [ V_35 ] . V_25 = V_35 ;
} else {
V_21 -> V_24 [ V_35 ] . V_27 = V_35 ;
V_21 -> V_24 [ V_35 ] . V_25 = V_35 ;
break;
}
}
}
return F_7 ( V_8 , V_21 ) ;
}
static void F_22 ( struct V_20 * V_21 ,
T_3 V_55 )
{
V_21 -> V_49 = true ;
F_19 ( & V_21 -> V_45 , V_55 ) ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_9 * V_10 ,
bool V_56 )
{
T_2 V_34 ;
enum V_19 V_57 ;
struct V_6 * V_17 ;
enum V_58 V_59 = V_60 ;
V_17 = F_2 ( V_8 , V_10 ) ;
if ( V_17 ) {
if ( F_24 ( V_17 , V_10 -> V_35 ) )
V_59 = V_61 ;
else
V_59 = V_60 ;
} else {
for ( V_34 = V_21 -> V_24 [ V_10 -> V_35 ] . V_27 ;
V_34 <= V_21 -> V_24 [ V_10 -> V_35 ] . V_25 ;
V_34 ++ ) {
V_17 = & V_8 -> V_18 [ V_34 ] ;
if ( F_24 ( V_17 , V_10 -> V_35 ) ) {
if ( V_17 -> V_53 > ( 1 << V_10 -> V_35 ) ) {
V_59 = V_60 ;
break;
}
if ( V_17 -> V_62 == V_10 -> V_35 ) {
if ( V_59 != V_63 ) {
V_59 = V_61 ;
}
break;
}
if ( V_17 -> V_53 == 0 ) {
V_59 = V_63 ;
}
} else if ( V_17 -> V_53 != 0 ) {
V_59 = V_60 ;
}
}
}
if (
( V_56 == false )
&& ( V_59 == V_63 )
) {
V_59 = V_61 ;
}
switch ( V_59 ) {
case V_61 :
V_57 = F_9 ( V_17 , V_10 ) ;
if ( V_57 == V_28 ) {
V_21 -> V_50 |= ( 1 << V_10 -> V_35 ) ;
}
break;
case V_63 :
F_22 ( V_21 ,
V_64 ) ;
break;
case V_60 :
default:
break;
}
}
static void F_25 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_6 * V_17 ,
struct V_9 * V_10 )
{
T_2 V_35 = V_10 -> V_35 ;
if ( ! V_17 ) {
V_21 -> V_51 |= 1 << V_35 ;
F_22 ( V_21 ,
V_64 ) ;
} else {
T_3 V_65 = V_17 -> V_66 . V_67 ;
F_26 ( V_65 != V_68 ) ;
V_21 -> V_51 |= 1 << V_35 ;
F_17 ( V_17 , V_10 ) ;
}
}
static void F_27 (
struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_6 * V_17 ,
struct V_9 * V_10 )
{
V_21 -> V_51 &= ~ ( 1 << V_10 -> V_35 ) ;
if ( ! V_17 )
return;
if ( V_21 -> V_50 & ( 1 << V_10 -> V_35 ) ) {
enum V_19 V_57 ;
V_57 = F_28 ( V_17 , V_10 ) ;
if ( V_57 == V_28 )
V_21 -> V_50 &= ~ ( 1 << V_10 -> V_35 ) ;
}
}
static void F_29 ( unsigned long V_39 )
{
T_3 V_40 ;
struct V_41 * V_42 = (struct V_41 * ) V_39 ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
unsigned long V_43 ;
T_4 V_44 ;
V_21 = F_11 ( V_42 , F_12 ( * V_21 ) , V_45 ) ;
V_8 = F_11 ( V_21 , F_12 ( * V_8 ) , V_21 ) ;
F_13 ( & V_8 -> V_46 , V_43 ) ;
if ( V_42 -> V_47 )
goto V_48;
V_21 -> V_49 = false ;
V_44 = ~ V_21 -> V_50 & V_21 -> V_51 ;
if ( ! V_44 )
goto V_48;
for ( V_40 = 0 ; V_40 < V_38 ; V_40 ++ ) {
if ( ( V_44 & ( 1 << V_40 ) ) == 0 )
continue;
F_23 ( V_8 , V_21 ,
& V_8 -> V_29 [ V_40 ] , false ) ;
}
if ( F_30 ( V_8 ) )
F_31 ( V_8 , V_28 ) ;
V_48:
F_15 ( & V_8 -> V_46 , V_43 ) ;
}
void F_32 (
struct V_20 * V_21 )
{
T_3 V_40 ;
V_21 -> V_50 = 0x00 ;
V_21 -> V_51 = 0x00 ;
V_21 -> V_52 = NULL ;
V_21 -> V_69 = NULL ;
V_21 -> V_49 = false ;
for ( V_40 = 0 ; V_40 < V_36 ; V_40 ++ ) {
V_21 -> V_24 [ V_40 ] . V_27 = 0 ;
V_21 -> V_24 [ V_40 ] . V_25 = 0 ;
}
}
bool F_33 ( struct V_7 * V_8 )
{
return V_8 -> V_21 . V_52 == F_25 ;
}
enum V_19 F_34 (
struct V_7 * V_8 ,
struct V_20 * V_21 )
{
enum V_19 V_57 ;
enum V_70 V_71 ;
V_71 = V_8 -> V_37 . V_72 . V_73 ;
if ( V_71 == V_74 ) {
V_57 = F_8 (
V_8 , V_21 ) ;
V_21 -> V_52 = F_16 ;
V_21 -> V_69 = F_18 ;
F_35 ( & V_21 -> V_45 , F_10 ) ;
} else {
V_57 = F_21 (
V_8 , V_21 ) ;
V_21 -> V_52 = F_25 ;
V_21 -> V_69 = F_27 ;
F_35 ( & V_21 -> V_45 , F_29 ) ;
}
return V_57 ;
}
