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
if ( ! V_2 -> V_17 ||
( ( V_2 -> V_18 . V_4 - V_2 -> V_19 . V_4 < V_2 -> V_17 ) &&
( V_2 -> V_18 . V_20 - V_2 -> V_19 . V_20 < V_2 -> V_17 ) ) ) {
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
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = 0 ;
if ( F_4 ( V_2 -> V_18 . V_20 == 0 ) ) {
V_2 -> V_18 . V_20 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_39 ;
return V_33 ;
}
if ( F_12 ( V_34 ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
T_1 V_42 ;
T_1 V_4 = F_2 ( V_3 ) ;
if ( ! V_2 -> V_9 . V_12 )
return 0 ;
if ( F_4 ( V_4 == 0 ) )
goto V_33;
if ( F_3 ( V_4 > V_2 -> V_18 . V_4 ) )
return 0 ;
V_42 = V_2 -> V_18 . V_4 - V_4 ;
if ( V_42 >= V_2 -> V_9 . V_12 ) {
V_2 -> V_43 . V_12 ++ ;
goto V_33;
}
if ( V_2 -> V_18 . V_44 & ( 1U << V_42 ) ) {
V_2 -> V_43 . V_18 ++ ;
goto V_33;
}
return 0 ;
V_33:
F_14 ( V_2 , V_32 , V_3 ) ;
return - V_45 ;
}
static void F_15 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_42 ;
T_1 V_4 = F_2 ( V_3 ) ;
if ( ! V_2 -> V_9 . V_12 )
return;
if ( V_4 > V_2 -> V_18 . V_4 ) {
V_42 = V_4 - V_2 -> V_18 . V_4 ;
if ( V_42 < V_2 -> V_9 . V_12 )
V_2 -> V_18 . V_44 = ( ( V_2 -> V_18 . V_44 ) << V_42 ) | 1 ;
else
V_2 -> V_18 . V_44 = 1 ;
V_2 -> V_18 . V_4 = V_4 ;
} else {
V_42 = V_2 -> V_18 . V_4 - V_4 ;
V_2 -> V_18 . V_44 |= ( 1U << V_42 ) ;
}
if ( F_12 ( F_9 ( V_2 ) ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_8 -> V_20 ;
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = 0 ;
if ( F_4 ( V_8 -> V_20 == 0 ) ) {
V_8 -> V_20 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_39 ;
return V_33 ;
}
if ( F_12 ( V_34 ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
unsigned int V_46 , V_47 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_48 ;
T_1 V_4 = F_2 ( V_3 ) ;
T_1 V_42 = V_8 -> V_4 - V_4 ;
if ( ! V_8 -> V_12 )
return 0 ;
if ( F_4 ( V_4 == 0 ) )
goto V_33;
if ( F_3 ( V_4 > V_8 -> V_4 ) )
return 0 ;
if ( V_42 >= V_8 -> V_12 ) {
V_2 -> V_43 . V_12 ++ ;
goto V_33;
}
V_48 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
if ( V_48 >= V_42 )
V_46 = ( V_48 - V_42 ) % V_8 -> V_12 ;
else
V_46 = V_8 -> V_12 - ( V_42 - V_48 ) ;
V_47 = V_46 >> 5 ;
V_46 = V_46 & 0x1F ;
if ( V_8 -> V_49 [ V_47 ] & ( 1U << V_46 ) )
goto V_50;
return 0 ;
V_50:
V_2 -> V_43 . V_18 ++ ;
V_33:
F_14 ( V_2 , V_32 , V_3 ) ;
return - V_45 ;
}
static void F_18 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_46 , V_47 , V_51 ;
T_1 V_42 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_4 = F_2 ( V_3 ) ;
T_1 V_48 ;
if ( ! V_8 -> V_12 )
return;
V_48 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
if ( V_4 > V_8 -> V_4 ) {
V_42 = V_4 - V_8 -> V_4 ;
if ( V_42 < V_8 -> V_12 ) {
for ( V_51 = 1 ; V_51 < V_42 ; V_51 ++ ) {
V_46 = ( V_48 + V_51 ) % V_8 -> V_12 ;
V_47 = V_46 >> 5 ;
V_46 = V_46 & 0x1F ;
V_8 -> V_49 [ V_47 ] &= ~ ( 1U << V_46 ) ;
}
} else {
V_47 = ( V_8 -> V_12 - 1 ) >> 5 ;
for ( V_51 = 0 ; V_51 <= V_47 ; V_51 ++ )
V_8 -> V_49 [ V_51 ] = 0 ;
}
V_46 = ( V_48 + V_42 ) % V_8 -> V_12 ;
V_8 -> V_4 = V_4 ;
} else {
V_42 = V_8 -> V_4 - V_4 ;
if ( V_48 >= V_42 )
V_46 = ( V_48 - V_42 ) % V_8 -> V_12 ;
else
V_46 = V_8 -> V_12 - ( V_42 - V_48 ) ;
}
V_47 = V_46 >> 5 ;
V_46 = V_46 & 0x1F ;
V_8 -> V_49 [ V_47 ] |= ( 1U << V_46 ) ;
if ( F_12 ( F_9 ( V_2 ) ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 V_15 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_7 * V_52 = V_2 -> V_52 ;
switch ( V_13 ) {
case V_16 :
if ( ! V_2 -> V_17 ||
( ( V_8 -> V_4 - V_52 -> V_4 < V_2 -> V_17 ) &&
( V_8 -> V_20 - V_52 -> V_20
< V_2 -> V_17 ) ) ) {
if ( V_2 -> V_21 & V_22 )
V_13 = V_23 ;
else
return;
}
break;
case V_23 :
if ( memcmp ( V_2 -> V_8 , V_2 -> V_52 ,
F_20 ( V_8 ) ) == 0 ) {
V_2 -> V_21 |= V_22 ;
return;
}
break;
}
memcpy ( V_2 -> V_52 , V_2 -> V_8 ,
F_20 ( V_8 ) ) ;
V_15 . V_13 = V_25 ;
V_15 . V_26 . V_27 = V_13 ;
F_6 ( V_2 , & V_15 ) ;
if ( V_2 -> V_28 &&
! F_7 ( & V_2 -> V_29 , V_30 + V_2 -> V_28 ) )
V_2 -> V_21 &= ~ V_22 ;
}
static void F_21 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_53 , V_54 ;
struct V_14 V_15 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_7 * V_52 = V_2 -> V_52 ;
switch ( V_13 ) {
case V_16 :
if ( V_2 -> V_17 ) {
if ( V_8 -> V_5 == V_52 -> V_5 )
V_53 = V_8 -> V_4 - V_52 -> V_4 ;
else
V_53 = ~ V_52 -> V_4 + V_8 -> V_4
+ 1 ;
if ( V_8 -> V_55 == V_52 -> V_55 )
V_54 = V_8 -> V_20
- V_52 -> V_20 ;
else
V_54 = ~ V_52 -> V_20
+ V_8 -> V_20 + 1 ;
if ( V_53 >= V_2 -> V_17 ||
V_54 >= V_2 -> V_17 )
break;
}
if ( V_2 -> V_21 & V_22 )
V_13 = V_23 ;
else
return;
break;
case V_23 :
if ( memcmp ( V_2 -> V_8 , V_2 -> V_52 ,
F_20 ( V_8 ) ) == 0 ) {
V_2 -> V_21 |= V_22 ;
return;
}
break;
}
memcpy ( V_2 -> V_52 , V_2 -> V_8 ,
F_20 ( V_8 ) ) ;
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
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = V_8 -> V_55 ;
if ( F_4 ( V_8 -> V_20 == 0 ) ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = ++ V_8 -> V_55 ;
if ( V_8 -> V_55 == 0 ) {
V_8 -> V_20 -- ;
V_8 -> V_55 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_39 ;
return V_33 ;
}
}
if ( F_12 ( V_34 ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
unsigned int V_46 , V_47 ;
T_1 V_42 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_48 ;
T_1 V_4 = F_2 ( V_3 ) ;
T_1 V_56 = V_8 -> V_12 ;
T_1 V_57 = V_8 -> V_4 ;
T_1 V_6 = V_57 - V_56 + 1 ;
if ( ! V_56 )
return 0 ;
if ( F_4 ( V_4 == 0 && V_8 -> V_5 == 0 &&
( V_8 -> V_4 < V_8 -> V_12 - 1 ) ) )
goto V_33;
V_42 = V_57 - V_4 ;
if ( F_3 ( V_57 >= V_56 - 1 ) ) {
if ( F_3 ( V_4 > V_57 ) || V_4 < V_6 )
return 0 ;
} else {
if ( F_3 ( V_4 > V_57 && V_4 < V_6 ) )
return 0 ;
if ( V_4 >= V_6 )
V_42 = ~ V_4 + V_57 + 1 ;
}
if ( V_42 >= V_8 -> V_12 ) {
V_2 -> V_43 . V_12 ++ ;
goto V_33;
}
V_48 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
if ( V_48 >= V_42 )
V_46 = ( V_48 - V_42 ) % V_8 -> V_12 ;
else
V_46 = V_8 -> V_12 - ( V_42 - V_48 ) ;
V_47 = V_46 >> 5 ;
V_46 = V_46 & 0x1F ;
if ( V_8 -> V_49 [ V_47 ] & ( 1U << V_46 ) )
goto V_50;
return 0 ;
V_50:
V_2 -> V_43 . V_18 ++ ;
V_33:
F_14 ( V_2 , V_32 , V_3 ) ;
return - V_45 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_3 )
{
if ( F_4 ( F_10 ( V_32 ) -> V_4 . V_58 . V_38 !=
F_25 ( F_1 ( V_2 , V_3 ) ) ) ) {
V_2 -> V_43 . V_12 ++ ;
return - V_45 ;
}
return F_23 ( V_2 , V_32 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_46 , V_47 , V_51 ;
int V_59 ;
T_1 V_42 , V_48 , V_4 , V_5 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_8 -> V_12 )
return;
V_4 = F_2 ( V_3 ) ;
V_48 = ( V_8 -> V_4 - 1 ) % V_8 -> V_12 ;
V_5 = F_1 ( V_2 , V_3 ) ;
V_59 = V_5 - V_8 -> V_5 ;
if ( ( ! V_59 && V_4 > V_8 -> V_4 ) || V_59 > 0 ) {
if ( F_3 ( ! V_59 ) )
V_42 = V_4 - V_8 -> V_4 ;
else
V_42 = ~ V_8 -> V_4 + V_4 + 1 ;
if ( V_42 < V_8 -> V_12 ) {
for ( V_51 = 1 ; V_51 < V_42 ; V_51 ++ ) {
V_46 = ( V_48 + V_51 ) % V_8 -> V_12 ;
V_47 = V_46 >> 5 ;
V_46 = V_46 & 0x1F ;
V_8 -> V_49 [ V_47 ] &= ~ ( 1U << V_46 ) ;
}
} else {
V_47 = ( V_8 -> V_12 - 1 ) >> 5 ;
for ( V_51 = 0 ; V_51 <= V_47 ; V_51 ++ )
V_8 -> V_49 [ V_51 ] = 0 ;
}
V_46 = ( V_48 + V_42 ) % V_8 -> V_12 ;
V_8 -> V_4 = V_4 ;
if ( F_4 ( V_59 > 0 ) )
V_8 -> V_5 ++ ;
} else {
V_42 = V_8 -> V_4 - V_4 ;
if ( V_48 >= V_42 )
V_46 = ( V_48 - V_42 ) % V_8 -> V_12 ;
else
V_46 = V_8 -> V_12 - ( V_42 - V_48 ) ;
}
V_47 = V_46 >> 5 ;
V_46 = V_46 & 0x1F ;
V_8 -> V_49 [ V_47 ] |= ( 1U << V_46 ) ;
if ( F_12 ( F_9 ( V_2 ) ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
struct V_60 * V_61 = V_60 ( V_32 ) ;
T_3 V_20 = V_2 -> V_18 . V_20 ;
if ( ! V_61 )
return F_8 ( V_2 , V_32 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
if ( ! F_28 ( V_32 ) ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_20 ;
V_61 -> V_4 . V_37 = V_20 ;
} else {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = V_20 + 1 ;
V_61 -> V_4 . V_37 = V_20 + 1 ;
V_20 += F_29 ( V_32 ) -> V_62 ;
}
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = 0 ;
V_61 -> V_4 . V_38 = 0 ;
if ( F_4 ( V_20 < V_2 -> V_18 . V_20 ) ) {
F_11 ( V_2 , V_32 ) ;
V_33 = - V_39 ;
return V_33 ;
}
V_2 -> V_18 . V_20 = V_20 ;
if ( F_12 ( V_34 ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_60 * V_61 = V_60 ( V_32 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
T_3 V_20 = V_8 -> V_20 ;
if ( ! V_61 )
return F_16 ( V_2 , V_32 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
if ( ! F_28 ( V_32 ) ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_20 ;
V_61 -> V_4 . V_37 = V_20 ;
} else {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = V_20 + 1 ;
V_61 -> V_4 . V_37 = V_20 + 1 ;
V_20 += F_29 ( V_32 ) -> V_62 ;
}
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = 0 ;
V_61 -> V_4 . V_38 = 0 ;
if ( F_4 ( V_20 < V_8 -> V_20 ) ) {
F_11 ( V_2 , V_32 ) ;
V_33 = - V_39 ;
return V_33 ;
} else {
V_8 -> V_20 = V_20 ;
}
if ( F_12 ( V_34 ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
return V_33 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_60 * V_61 = V_60 ( V_32 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_34 * V_34 = F_9 ( V_2 ) ;
T_3 V_20 = V_8 -> V_20 ;
T_3 V_55 = V_8 -> V_55 ;
if ( ! V_61 )
return F_22 ( V_2 , V_32 ) ;
if ( V_2 -> type -> V_10 & V_35 ) {
if ( ! F_28 ( V_32 ) ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = ++ V_20 ;
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = V_55 ;
V_61 -> V_4 . V_37 = V_20 ;
V_61 -> V_4 . V_38 = V_55 ;
} else {
F_10 ( V_32 ) -> V_4 . V_36 . V_37 = V_20 + 1 ;
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = V_55 ;
V_61 -> V_4 . V_37 = V_20 = V_20 + 1 ;
V_61 -> V_4 . V_38 = V_55 ;
V_20 += F_29 ( V_32 ) -> V_62 ;
}
if ( F_4 ( V_20 < V_8 -> V_20 ) ) {
F_10 ( V_32 ) -> V_4 . V_36 . V_38 = ++ V_55 ;
V_61 -> V_4 . V_38 = V_55 ;
if ( V_8 -> V_55 == 0 ) {
V_8 -> V_20 -- ;
V_8 -> V_55 -- ;
F_11 ( V_2 , V_32 ) ;
V_33 = - V_39 ;
return V_33 ;
}
}
V_8 -> V_20 = V_20 ;
V_8 -> V_55 = V_55 ;
if ( F_12 ( V_34 ) )
V_2 -> V_40 -> V_41 ( V_2 , V_16 ) ;
}
return V_33 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( V_8 ) {
if ( V_8 -> V_12 >
V_8 -> V_63 * sizeof( T_3 ) * 8 )
return - V_45 ;
if ( V_2 -> V_9 . V_10 & V_11 ) {
if ( V_8 -> V_12 == 0 )
return - V_45 ;
V_2 -> V_40 = & V_64 ;
} else {
V_2 -> V_40 = & V_65 ;
}
} else {
V_2 -> V_40 = & V_66 ;
}
return 0 ;
}
