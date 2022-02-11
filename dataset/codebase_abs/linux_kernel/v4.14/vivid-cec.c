void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
while ( ! F_3 ( & V_2 -> V_4 ) ) {
struct V_5 * V_6 =
F_4 ( & V_2 -> V_4 ,
struct V_5 , V_7 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_6 ( & V_6 -> V_8 ) ;
F_2 ( & V_2 -> V_3 ) ;
F_7 ( & V_6 -> V_7 ) ;
F_8 ( V_6 -> V_9 , V_10 ) ;
F_9 ( V_6 ) ;
}
F_5 ( & V_2 -> V_3 ) ;
}
static bool F_10 ( struct V_1 * V_2 ,
struct V_11 * V_9 , T_1 V_12 )
{
unsigned int V_13 ;
if ( V_12 >= 0xf )
return false ;
if ( V_9 != V_2 -> V_14 && V_2 -> V_14 &&
V_2 -> V_14 -> V_15 &&
F_11 ( V_2 -> V_14 , V_12 ) )
return true ;
for ( V_13 = 0 ; V_13 < V_16 && V_2 -> V_17 [ V_13 ] ; V_13 ++ ) {
if ( V_9 == V_2 -> V_17 [ V_13 ] )
continue;
if ( ! V_2 -> V_17 [ V_13 ] -> V_15 )
continue;
if ( F_11 ( V_2 -> V_17 [ V_13 ] , V_12 ) )
return true ;
}
return false ;
}
static void F_12 ( struct V_11 * V_9 , T_2 V_18 ,
const struct V_19 * V_20 , bool V_21 )
{
unsigned int V_22 = V_21 ? 1 : V_20 -> V_22 ;
unsigned int V_13 ;
bool V_23 ;
if ( V_9 == NULL )
return;
V_18 = F_13 ( V_18 , ( V_24 +
V_22 * 10 * V_25 ) ) ;
F_14 ( V_9 , false , V_18 ) ;
V_18 = F_15 ( V_18 , V_26 ) ;
F_14 ( V_9 , true , V_18 ) ;
V_18 = F_15 ( V_18 , V_27 ) ;
for ( V_13 = 0 ; V_13 < 10 * V_22 ; V_13 ++ ) {
switch ( V_13 % 10 ) {
case 0 ... 7 :
V_23 = V_20 -> V_20 [ V_13 / 10 ] & ( 0x80 >> ( V_13 % 10 ) ) ;
break;
case 8 :
V_23 = V_13 / 10 == V_20 -> V_22 - 1 ;
break;
case 9 :
V_23 = F_16 ( V_20 ) ^ V_21 ;
break;
}
F_14 ( V_9 , false , V_18 ) ;
if ( V_23 )
V_18 = F_15 ( V_18 , V_28 ) ;
else
V_18 = F_15 ( V_18 , V_29 ) ;
F_14 ( V_9 , true , V_18 ) ;
if ( V_23 )
V_18 = F_15 ( V_18 , V_30 ) ;
else
V_18 = F_15 ( V_18 , V_31 ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
const struct V_19 * V_20 , bool V_21 )
{
T_2 V_18 = F_18 () ;
unsigned int V_13 ;
F_12 ( V_2 -> V_14 , V_18 , V_20 , V_21 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ )
F_12 ( V_2 -> V_17 [ V_13 ] , V_18 , V_20 , V_21 ) ;
}
static void F_19 ( struct V_32 * V_8 )
{
struct V_5 * V_6 =
F_20 ( V_8 , struct V_5 , V_8 . V_8 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_11 * V_9 = V_6 -> V_9 ;
T_1 V_12 = F_21 ( & V_6 -> V_20 ) ;
bool V_33 ;
unsigned int V_13 ;
V_33 = F_16 ( & V_6 -> V_20 ) ;
if ( ! V_33 )
V_33 = F_10 ( V_2 , V_9 , V_12 ) ;
V_6 -> V_34 = V_33 ? V_35 : V_36 ;
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
F_7 ( & V_6 -> V_7 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_17 ( V_2 , & V_6 -> V_20 , ! V_33 ) ;
F_8 ( V_6 -> V_9 , V_6 -> V_34 ) ;
if ( V_9 != V_2 -> V_14 )
F_22 ( V_2 -> V_14 , & V_6 -> V_20 ) ;
for ( V_13 = 0 ; V_13 < V_16 && V_2 -> V_17 [ V_13 ] ; V_13 ++ )
if ( V_9 != V_2 -> V_17 [ V_13 ] )
F_22 ( V_2 -> V_17 [ V_13 ] , & V_6 -> V_20 ) ;
F_9 ( V_6 ) ;
}
static void F_23 ( struct V_32 * V_8 )
{
struct V_5 * V_6 =
F_20 ( V_8 , struct V_5 , V_8 . V_8 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_37 ) {
F_7 ( & V_6 -> V_7 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_8 ( V_6 -> V_9 , V_39 ) ;
F_9 ( V_6 ) ;
} else {
F_24 ( & V_6 -> V_8 , F_19 ) ;
V_2 -> V_38 = V_40 ;
V_2 -> V_37 = F_25 ( V_6 -> V_41 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_26 ( & V_6 -> V_8 , V_2 -> V_37 ) ;
}
}
static int F_27 ( struct V_11 * V_9 , bool V_42 )
{
V_9 -> V_43 = true ;
return 0 ;
}
static int F_28 ( struct V_11 * V_9 , T_1 V_44 )
{
return 0 ;
}
static int F_29 ( struct V_11 * V_9 , T_1 V_45 ,
T_3 V_46 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_30 ( V_9 ) ;
struct V_5 * V_6 = F_31 ( sizeof( * V_6 ) , V_47 ) ;
long V_48 = 0 ;
if ( V_6 == NULL )
return - V_49 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_41 = F_32 ( V_46 ) +
V_20 -> V_22 * V_50 ;
V_6 -> V_20 = * V_20 ;
F_2 ( & V_2 -> V_3 ) ;
F_33 ( & V_6 -> V_7 , & V_2 -> V_4 ) ;
if ( V_2 -> V_37 == 0 ) {
F_24 ( & V_6 -> V_8 , F_19 ) ;
V_2 -> V_38 = V_40 ;
V_2 -> V_37 = F_25 ( V_6 -> V_41 ) ;
V_48 = V_2 -> V_37 ;
} else {
F_24 ( & V_6 -> V_8 , F_23 ) ;
V_48 = V_2 -> V_38 +
V_2 -> V_37 - V_40 ;
}
F_5 ( & V_2 -> V_3 ) ;
F_26 ( & V_6 -> V_8 , V_48 < 0 ? 0 : V_48 ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_9 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_30 ( V_9 ) ;
struct V_19 V_51 ;
T_1 V_12 = F_21 ( V_20 ) ;
T_1 V_52 ;
char V_53 [ 14 ] ;
if ( F_16 ( V_20 ) )
V_12 = V_9 -> V_54 . V_44 [ 0 ] ;
F_35 ( & V_51 , V_12 , F_36 ( V_20 ) ) ;
switch ( F_37 ( V_20 ) ) {
case V_55 :
if ( ! F_38 ( V_9 ) )
return - V_56 ;
F_39 ( V_20 , & V_52 , V_53 ) ;
switch ( V_52 ) {
case V_57 :
strcpy ( V_2 -> V_53 , V_53 ) ;
V_2 -> V_58 = V_40 ;
break;
case V_59 :
strcpy ( V_2 -> V_53 , V_53 ) ;
V_2 -> V_58 = 0 ;
break;
case V_60 :
V_2 -> V_53 [ 0 ] = 0 ;
V_2 -> V_58 = 0 ;
break;
default:
F_40 ( & V_51 , F_37 ( V_20 ) ,
V_61 ) ;
F_41 ( V_9 , & V_51 , false ) ;
break;
}
break;
default:
return - V_56 ;
}
return 0 ;
}
struct V_11 * F_42 ( struct V_1 * V_2 ,
unsigned int V_62 ,
bool V_63 )
{
char V_64 [ sizeof( V_2 -> V_65 . V_64 ) + 2 ] ;
T_3 V_66 = V_67 | V_68 | V_69 ;
snprintf ( V_64 , sizeof( V_64 ) , L_1 ,
V_63 ? V_2 -> V_65 . V_64 : V_2 -> V_70 . V_64 ,
V_62 ) ;
return F_43 ( & V_71 , V_2 ,
V_64 , V_66 , 1 ) ;
}
