T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 , V_5 , V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! ( V_2 -> V_9 . V_10 & V_11 ) )
return 0 ;
V_4 = F_2 ( V_3 ) ;
V_5 = V_8 -> V_5 ;
V_6 = V_8 -> V_4 - V_8 -> V_12 + 1 ;
if ( F_3 ( V_8 -> V_4 >= V_8 -> V_12 - 1 ) ) {
if ( F_4 ( V_4 < V_6 ) )
V_5 ++ ;
} else {
if ( F_4 ( V_4 >= V_6 ) )
V_5 -- ;
}
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 V_15 ;
switch ( V_13 ) {
case V_16 :
if ( V_2 -> V_17 &&
( V_2 -> V_18 . V_4 - V_2 -> V_19 . V_4 < V_2 -> V_17 ) &&
( V_2 -> V_18 . V_20 - V_2 -> V_19 . V_20 < V_2 -> V_17 ) ) {
if ( V_2 -> V_21 & V_22 )
V_13 = V_23 ;
else
return;
}
break;
case V_23 :
if ( memcmp ( & V_2 -> V_18 , & V_2 -> V_19 ,
sizeof( struct V_24 ) ) == 0 ) {
V_2 -> V_21 |= V_22 ;
return;
}
break;
}
memcpy ( & V_2 -> V_19 , & V_2 -> V_18 , sizeof( struct V_24 ) ) ;
V_15 . V_13 = V_25 ;
V_15 . V_26 . V_27 = V_13 ;
F_6 ( V_2 , & V_15 ) ;
if ( V_2 -> V_28 &&
! F_7 ( & V_2 -> V_29 , V_30 + V_2 -> V_28 ) )
V_2 -> V_21 &= ~ V_22 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_2 -> V_18 . V_20 ;
if ( F_4 ( V_2 -> V_18 . V_20 == 0 ) ) {
V_2 -> V_18 . V_20 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_38 ;
return V_33 ;
}
if ( F_12 ( V_34 ) )
V_2 -> V_39 -> V_40 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
T_1 V_41 ;
T_1 V_4 = F_2 ( V_3 ) ;
if ( ! V_2 -> V_9 . V_12 )
return 0 ;
if ( F_4 ( V_4 == 0 ) )
goto V_33;
if ( F_3 ( V_4 > V_2 -> V_18 . V_4 ) )
return 0 ;
V_41 = V_2 -> V_18 . V_4 - V_4 ;
if ( V_41 >= F_14 (unsigned int, x->props.replay_window,
sizeof(x->replay.bitmap) * 8 ) ) {
V_2 -> V_42 . V_12 ++ ;
goto V_33;
}
if ( V_2 -> V_18 . V_43 & ( 1U << V_41 ) ) {
V_2 -> V_42 . V_18 ++ ;
goto V_33;
}
return 0 ;
V_33:
F_15 ( V_2 , V_32 , V_3 ) ;
return - V_44 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_41 ;
T_1 V_4 = F_2 ( V_3 ) ;
if ( ! V_2 -> V_9 . V_12 )
return;
if ( V_4 > V_2 -> V_18 . V_4 ) {
V_41 = V_4 - V_2 -> V_18 . V_4 ;
if ( V_41 < V_2 -> V_9 . V_12 )
V_2 -> V_18 . V_43 = ( ( V_2 -> V_18 . V_43 ) << V_41 ) | 1 ;
else
V_2 -> V_18 . V_43 = 1 ;
V_2 -> V_18 . V_4 = V_4 ;
} else {
V_41 = V_2 -> V_18 . V_4 - V_4 ;
V_2 -> V_18 . V_43 |= ( 1U << V_41 ) ;
}
if ( F_12 ( F_9 ( V_2 ) ) )
V_2 -> V_39 -> V_40 ( V_2 , V_16 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_8 -> V_20 ;
if ( F_4 ( V_8 -> V_20 == 0 ) ) {
V_8 -> V_20 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_38 ;
return V_33 ;
}
if ( F_12 ( V_34 ) )
V_2 -> V_39 -> V_40 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
unsigned int V_45 , V_46 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_47 ;
T_1 V_4 = F_2 ( V_3 ) ;
T_1 V_41 = V_8 -> V_4 - V_4 ;
if ( ! V_8 -> V_12 )
return 0 ;
if ( F_4 ( V_4 == 0 ) )
goto V_33;
if ( F_3 ( V_4 > V_8 -> V_4 ) )
return 0 ;
if ( V_41 >= V_8 -> V_12 ) {
V_2 -> V_42 . V_12 ++ ;
goto V_33;
}
V_47 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
if ( V_47 >= V_41 )
V_45 = ( V_47 - V_41 ) % V_8 -> V_12 ;
else
V_45 = V_8 -> V_12 - ( V_41 - V_47 ) ;
V_46 = V_45 >> 5 ;
V_45 = V_45 & 0x1F ;
if ( V_8 -> V_48 [ V_46 ] & ( 1U << V_45 ) )
goto V_49;
return 0 ;
V_49:
V_2 -> V_42 . V_18 ++ ;
V_33:
F_15 ( V_2 , V_32 , V_3 ) ;
return - V_44 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_45 , V_46 , V_50 ;
T_1 V_41 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_4 = F_2 ( V_3 ) ;
T_1 V_47 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
if ( ! V_8 -> V_12 )
return;
if ( V_4 > V_8 -> V_4 ) {
V_41 = V_4 - V_8 -> V_4 ;
if ( V_41 < V_8 -> V_12 ) {
for ( V_50 = 1 ; V_50 < V_41 ; V_50 ++ ) {
V_45 = ( V_47 + V_50 ) % V_8 -> V_12 ;
V_46 = V_45 >> 5 ;
V_45 = V_45 & 0x1F ;
V_8 -> V_48 [ V_46 ] &= ~ ( 1U << V_45 ) ;
}
} else {
V_46 = ( V_8 -> V_12 - 1 ) >> 5 ;
for ( V_50 = 0 ; V_50 <= V_46 ; V_50 ++ )
V_8 -> V_48 [ V_50 ] = 0 ;
}
V_45 = ( V_47 + V_41 ) % V_8 -> V_12 ;
V_8 -> V_4 = V_4 ;
} else {
V_41 = V_8 -> V_4 - V_4 ;
if ( V_47 >= V_41 )
V_45 = ( V_47 - V_41 ) % V_8 -> V_12 ;
else
V_45 = V_8 -> V_12 - ( V_41 - V_47 ) ;
}
V_46 = V_45 >> 5 ;
V_45 = V_45 & 0x1F ;
V_8 -> V_48 [ V_46 ] |= ( 1U << V_45 ) ;
if ( F_12 ( F_9 ( V_2 ) ) )
V_2 -> V_39 -> V_40 ( V_2 , V_16 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 V_15 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_7 * V_51 = V_2 -> V_51 ;
switch ( V_13 ) {
case V_16 :
if ( V_2 -> V_17 &&
( V_8 -> V_4 - V_51 -> V_4 < V_2 -> V_17 ) &&
( V_8 -> V_20 - V_51 -> V_20 < V_2 -> V_17 ) ) {
if ( V_2 -> V_21 & V_22 )
V_13 = V_23 ;
else
return;
}
break;
case V_23 :
if ( memcmp ( V_2 -> V_8 , V_2 -> V_51 ,
F_21 ( V_8 ) ) == 0 ) {
V_2 -> V_21 |= V_22 ;
return;
}
break;
}
memcpy ( V_2 -> V_51 , V_2 -> V_8 ,
F_21 ( V_8 ) ) ;
V_15 . V_13 = V_25 ;
V_15 . V_26 . V_27 = V_13 ;
F_6 ( V_2 , & V_15 ) ;
if ( V_2 -> V_28 &&
! F_7 ( & V_2 -> V_29 , V_30 + V_2 -> V_28 ) )
V_2 -> V_21 &= ~ V_22 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_8 -> V_20 ;
F_10 ( V_32 ) -> V_4 . V_36 . V_52 = V_8 -> V_53 ;
if ( F_4 ( V_8 -> V_20 == 0 ) ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_52 = ++ V_8 -> V_53 ;
if ( V_8 -> V_53 == 0 ) {
V_8 -> V_20 -- ;
V_8 -> V_53 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_38 ;
return V_33 ;
}
}
if ( F_12 ( V_34 ) )
V_2 -> V_39 -> V_40 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
unsigned int V_45 , V_46 ;
T_1 V_41 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_47 ;
T_1 V_4 = F_2 ( V_3 ) ;
T_1 V_54 = V_8 -> V_12 ;
T_1 V_55 = V_8 -> V_4 ;
T_1 V_6 = V_55 - V_54 + 1 ;
if ( ! V_54 )
return 0 ;
if ( F_4 ( V_4 == 0 && V_8 -> V_5 == 0 &&
( V_8 -> V_4 < V_8 -> V_12 - 1 ) ) )
goto V_33;
V_41 = V_55 - V_4 ;
if ( F_3 ( V_55 >= V_54 - 1 ) ) {
if ( F_3 ( V_4 > V_55 ) || V_4 < V_6 )
return 0 ;
} else {
if ( F_3 ( V_4 > V_55 && V_4 < V_6 ) )
return 0 ;
if ( V_4 >= V_6 )
V_41 = ~ V_4 + V_55 + 1 ;
}
if ( V_41 >= V_8 -> V_12 ) {
V_2 -> V_42 . V_12 ++ ;
goto V_33;
}
V_47 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
if ( V_47 >= V_41 )
V_45 = ( V_47 - V_41 ) % V_8 -> V_12 ;
else
V_45 = V_8 -> V_12 - ( V_41 - V_47 ) ;
V_46 = V_45 >> 5 ;
V_45 = V_45 & 0x1F ;
if ( V_8 -> V_48 [ V_46 ] & ( 1U << V_45 ) )
goto V_49;
return 0 ;
V_49:
V_2 -> V_42 . V_18 ++ ;
V_33:
F_15 ( V_2 , V_32 , V_3 ) ;
return - V_44 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_45 , V_46 , V_50 ;
int V_56 ;
T_1 V_41 , V_47 , V_4 , V_5 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_8 -> V_12 )
return;
V_4 = F_2 ( V_3 ) ;
V_47 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
V_5 = F_1 ( V_2 , V_3 ) ;
V_56 = V_5 - V_8 -> V_5 ;
if ( ( ! V_56 && V_4 > V_8 -> V_4 ) || V_56 > 0 ) {
if ( F_3 ( ! V_56 ) )
V_41 = V_4 - V_8 -> V_4 ;
else
V_41 = ~ V_8 -> V_4 + V_4 + 1 ;
if ( V_41 < V_8 -> V_12 ) {
for ( V_50 = 1 ; V_50 < V_41 ; V_50 ++ ) {
V_45 = ( V_47 + V_50 ) % V_8 -> V_12 ;
V_46 = V_45 >> 5 ;
V_45 = V_45 & 0x1F ;
V_8 -> V_48 [ V_46 ] &= ~ ( 1U << V_45 ) ;
}
} else {
V_46 = ( V_8 -> V_12 - 1 ) >> 5 ;
for ( V_50 = 0 ; V_50 <= V_46 ; V_50 ++ )
V_8 -> V_48 [ V_50 ] = 0 ;
}
V_45 = ( V_47 + V_41 ) % V_8 -> V_12 ;
V_8 -> V_4 = V_4 ;
if ( F_4 ( V_56 > 0 ) )
V_8 -> V_5 ++ ;
} else {
V_41 = V_8 -> V_4 - V_4 ;
if ( V_47 >= V_41 )
V_45 = ( V_47 - V_41 ) % V_8 -> V_12 ;
else
V_45 = V_8 -> V_12 - ( V_41 - V_47 ) ;
}
V_46 = V_45 >> 5 ;
V_45 = V_45 & 0x1F ;
V_8 -> V_48 [ V_46 ] |= ( 1U << V_45 ) ;
if ( F_12 ( F_9 ( V_2 ) ) )
V_2 -> V_39 -> V_40 ( V_2 , V_16 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( V_8 ) {
if ( V_8 -> V_12 >
V_8 -> V_57 * sizeof( V_58 ) * 8 )
return - V_44 ;
if ( ( V_2 -> V_9 . V_10 & V_11 ) && V_8 -> V_12 == 0 )
return - V_44 ;
if ( ( V_2 -> V_9 . V_10 & V_11 ) && V_2 -> V_8 )
V_2 -> V_39 = & V_59 ;
else
V_2 -> V_39 = & V_60 ;
} else
V_2 -> V_39 = & V_61 ;
return 0 ;
}
