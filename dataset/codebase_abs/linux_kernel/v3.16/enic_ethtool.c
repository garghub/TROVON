void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
int V_4 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_5 ; V_3 ++ ) {
V_4 = F_2 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] , V_2 ) ;
}
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_9 -> V_10 = ( V_11 | V_12 ) ;
V_9 -> V_13 = ( V_14 | V_15 ) ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
if ( F_6 ( V_7 ) ) {
F_7 ( V_9 , F_8 ( V_1 -> V_20 ) ) ;
V_9 -> V_21 = V_22 ;
} else {
F_7 ( V_9 , V_23 ) ;
V_9 -> V_21 = V_24 ;
}
V_9 -> V_25 = V_26 ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_29 * V_30 ;
F_10 ( V_1 , & V_30 ) ;
F_11 ( V_28 -> V_31 , V_32 , sizeof( V_28 -> V_31 ) ) ;
F_11 ( V_28 -> V_33 , V_34 , sizeof( V_28 -> V_33 ) ) ;
F_11 ( V_28 -> V_35 , V_30 -> V_35 ,
sizeof( V_28 -> V_35 ) ) ;
F_11 ( V_28 -> V_36 , F_12 ( V_1 -> V_37 ) ,
sizeof( V_28 -> V_36 ) ) ;
}
static void F_13 ( struct V_6 * V_7 , T_1 V_38 ,
T_2 * V_39 )
{
unsigned int V_3 ;
switch ( V_38 ) {
case V_40 :
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ ) {
memcpy ( V_39 , V_42 [ V_3 ] . V_43 , V_44 ) ;
V_39 += V_44 ;
}
for ( V_3 = 0 ; V_3 < V_45 ; V_3 ++ ) {
memcpy ( V_39 , V_46 [ V_3 ] . V_43 , V_44 ) ;
V_39 += V_44 ;
}
break;
}
}
static int F_14 ( struct V_6 * V_7 , int V_47 )
{
switch ( V_47 ) {
case V_40 :
return V_41 + V_45 ;
default:
return - V_48 ;
}
}
static void F_15 ( struct V_6 * V_7 ,
struct V_49 * V_50 , T_3 * V_39 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_51 * V_52 ;
unsigned int V_3 ;
F_16 ( V_1 , & V_52 ) ;
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_52 -> V_53 ) [ V_42 [ V_3 ] . V_54 ] ;
for ( V_3 = 0 ; V_3 < V_45 ; V_3 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_52 -> V_55 ) [ V_46 [ V_3 ] . V_54 ] ;
}
static T_1 F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
return V_1 -> V_56 ;
}
static void F_18 ( struct V_6 * V_7 , T_1 V_57 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_1 -> V_56 = V_57 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_58 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_59 * V_60 = & V_1 -> V_61 ;
V_9 -> V_62 = V_1 -> V_62 ;
V_9 -> V_63 = V_1 -> V_63 ;
if ( V_60 -> V_64 )
V_9 -> V_64 = 1 ;
V_9 -> V_65 = V_60 -> V_66 ;
V_9 -> V_67 = V_60 -> V_68 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_58 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
T_1 V_62 ;
T_1 V_63 ;
T_1 V_65 ;
T_1 V_67 ;
T_1 V_69 ;
unsigned int V_3 , V_4 ;
struct V_59 * V_60 = & V_1 -> V_61 ;
V_69 = F_21 ( V_1 -> V_20 ) ;
V_62 = F_22 ( T_1 , V_9 -> V_62 ,
V_69 ) ;
V_63 = F_22 ( T_1 , V_9 -> V_63 ,
V_69 ) ;
V_65 = F_22 ( T_1 , V_9 -> V_65 ,
V_69 ) ;
V_67 = F_22 ( T_1 , V_9 -> V_67 ,
V_69 ) ;
switch ( F_23 ( V_1 -> V_20 ) ) {
case V_70 :
if ( V_62 != V_63 )
return - V_71 ;
if ( V_9 -> V_64 ||
V_9 -> V_65 ||
V_9 -> V_67 )
return - V_48 ;
V_4 = F_24 () ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_62 ) ;
break;
case V_72 :
if ( V_62 != V_63 )
return - V_71 ;
if ( V_9 -> V_64 ||
V_9 -> V_65 ||
V_9 -> V_67 )
return - V_48 ;
F_3 ( & V_1 -> V_4 [ 0 ] ,
V_62 ) ;
break;
case V_73 :
for ( V_3 = 0 ; V_3 < V_1 -> V_74 ; V_3 ++ ) {
V_4 = F_25 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_62 ) ;
}
if ( V_60 -> V_64 ) {
if ( ! V_9 -> V_64 ) {
V_60 -> V_64 = 0 ;
F_1 ( V_1 , V_63 ) ;
}
} else {
if ( V_9 -> V_64 )
V_60 -> V_64 = 1 ;
else
F_1 ( V_1 , V_63 ) ;
}
if ( V_9 -> V_67 ) {
if ( V_67 <
( V_65 + V_75 ) )
return - V_71 ;
V_60 -> V_68 = V_67 ;
V_60 -> V_66 = V_65 ;
V_60 -> V_76 = V_65 +
V_75 ;
}
break;
default:
break;
}
V_1 -> V_62 = V_62 ;
V_1 -> V_63 = V_63 ;
return 0 ;
}
void F_26 ( struct V_6 * V_7 )
{
V_7 -> V_77 = & V_78 ;
}
