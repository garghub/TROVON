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
F_8 ( V_6 -> V_9 , V_10 , 0 , 0 , 1 , 0 ) ;
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
static void F_12 ( struct V_18 * V_8 )
{
struct V_5 * V_6 =
F_13 ( V_8 , struct V_5 , V_8 . V_8 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_11 * V_9 = V_6 -> V_9 ;
T_1 V_12 = F_14 ( & V_6 -> V_19 ) ;
bool V_20 ;
unsigned int V_13 ;
V_20 = F_15 ( & V_6 -> V_19 ) ;
if ( ! V_20 )
V_20 = F_10 ( V_2 , V_9 , V_12 ) ;
V_6 -> V_21 = V_20 ? V_22 : V_23 ;
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
F_7 ( & V_6 -> V_7 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_8 ( V_6 -> V_9 , V_6 -> V_21 , 0 , V_20 ? 0 : 1 , 0 , 0 ) ;
if ( V_9 != V_2 -> V_14 )
F_16 ( V_2 -> V_14 , & V_6 -> V_19 ) ;
for ( V_13 = 0 ; V_13 < V_16 && V_2 -> V_17 [ V_13 ] ; V_13 ++ )
if ( V_9 != V_2 -> V_17 [ V_13 ] )
F_16 ( V_2 -> V_17 [ V_13 ] , & V_6 -> V_19 ) ;
F_9 ( V_6 ) ;
}
static void F_17 ( struct V_18 * V_8 )
{
struct V_5 * V_6 =
F_13 ( V_8 , struct V_5 , V_8 . V_8 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_24 ) {
F_7 ( & V_6 -> V_7 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_8 ( V_6 -> V_9 , V_26 , 1 , 0 , 0 , 0 ) ;
F_9 ( V_6 ) ;
} else {
F_18 ( & V_6 -> V_8 , F_12 ) ;
V_2 -> V_25 = V_27 ;
V_2 -> V_24 = F_19 ( V_6 -> V_28 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_20 ( & V_6 -> V_8 , V_2 -> V_24 ) ;
}
}
static int F_21 ( struct V_11 * V_9 , bool V_29 )
{
return 0 ;
}
static int F_22 ( struct V_11 * V_9 , T_1 V_30 )
{
return 0 ;
}
static int F_23 ( struct V_11 * V_9 , T_1 V_31 ,
T_2 V_32 , struct V_33 * V_19 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_5 * V_6 = F_25 ( sizeof( * V_6 ) , V_34 ) ;
long V_35 = 0 ;
if ( V_6 == NULL )
return - V_36 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_28 = F_26 ( V_32 ) +
V_19 -> V_37 * V_38 ;
V_6 -> V_19 = * V_19 ;
F_2 ( & V_2 -> V_3 ) ;
F_27 ( & V_6 -> V_7 , & V_2 -> V_4 ) ;
if ( V_2 -> V_24 == 0 ) {
F_18 ( & V_6 -> V_8 , F_12 ) ;
V_2 -> V_25 = V_27 ;
V_2 -> V_24 = F_19 ( V_6 -> V_28 ) ;
V_35 = V_2 -> V_24 ;
} else {
F_18 ( & V_6 -> V_8 , F_17 ) ;
V_35 = V_2 -> V_25 +
V_2 -> V_24 - V_27 ;
}
F_5 ( & V_2 -> V_3 ) ;
F_20 ( & V_6 -> V_8 , V_35 < 0 ? 0 : V_35 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_9 , struct V_33 * V_19 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_33 V_39 ;
T_1 V_12 = F_14 ( V_19 ) ;
T_1 V_40 ;
char V_41 [ 14 ] ;
if ( F_15 ( V_19 ) )
V_12 = V_9 -> V_42 . V_30 [ 0 ] ;
F_29 ( & V_39 , V_12 , F_30 ( V_19 ) ) ;
switch ( F_31 ( V_19 ) ) {
case V_43 :
if ( ! F_32 ( V_9 ) )
return - V_44 ;
F_33 ( V_19 , & V_40 , V_41 ) ;
switch ( V_40 ) {
case V_45 :
strcpy ( V_2 -> V_41 , V_41 ) ;
V_2 -> V_46 = V_27 ;
break;
case V_47 :
strcpy ( V_2 -> V_41 , V_41 ) ;
V_2 -> V_46 = 0 ;
break;
case V_48 :
V_2 -> V_41 [ 0 ] = 0 ;
V_2 -> V_46 = 0 ;
break;
default:
F_34 ( & V_39 , F_31 ( V_19 ) ,
V_49 ) ;
F_35 ( V_9 , & V_39 , false ) ;
break;
}
break;
default:
return - V_44 ;
}
return 0 ;
}
struct V_11 * F_36 ( struct V_1 * V_2 ,
unsigned int V_50 ,
bool V_51 )
{
char V_52 [ sizeof( V_2 -> V_53 . V_52 ) + 2 ] ;
T_2 V_54 = V_55 | V_56 |
V_57 | V_58 | V_59 ;
snprintf ( V_52 , sizeof( V_52 ) , L_1 ,
V_51 ? V_2 -> V_53 . V_52 : V_2 -> V_60 . V_52 ,
V_50 ) ;
return F_37 ( & V_61 , V_2 ,
V_52 , V_54 , 1 ) ;
}
