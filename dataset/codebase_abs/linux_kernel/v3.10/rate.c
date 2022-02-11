static bool F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( ! V_2 -> V_5 )
return false ;
if ( ! V_3 )
return true ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_2 -> V_6 [ V_4 ] & V_7 )
return true ;
}
return false ;
}
void F_2 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_9 ;
for ( V_9 = V_8 ; V_9 < V_10 ; V_9 ++ )
V_2 -> V_11 [ V_9 ] = 0 ;
}
bool
F_3 ( struct V_1 * V_2 ,
const struct V_1 * V_12 ,
bool V_3 , T_2 V_8 )
{
T_2 V_13 [ V_14 + 1 ] ;
T_2 V_15 ;
T_1 V_5 ;
T_1 V_9 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_5 = V_2 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ ) {
V_15 = ( int ) V_2 -> V_6 [ V_9 ] & V_16 ;
if ( ( V_15 > V_14 ) || ( V_17 [ V_15 ] == 0 ) )
continue;
V_13 [ V_15 ] = V_2 -> V_6 [ V_9 ] ;
}
V_5 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 -> V_5 ; V_9 ++ ) {
V_15 = V_12 -> V_6 [ V_9 ] & V_16 ;
if ( V_13 [ V_15 ] )
V_2 -> V_6 [ V_5 ++ ] = V_13 [ V_15 ] ;
}
V_2 -> V_5 = V_5 ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ )
V_2 -> V_11 [ V_9 ] = ( V_2 -> V_11 [ V_9 ] & V_12 -> V_11 [ V_9 ] ) ;
if ( F_1 ( V_2 , V_3 ) )
return true ;
else
return false ;
}
T_3 F_4 ( struct V_19 * V_20 , T_2 * V_21 )
{
int V_22 ;
T_3 V_23 = V_24 << V_25 ;
V_22 =
( ( V_20 -> V_26 & V_27 ) >> V_28 ) ;
if ( ( V_22 == V_29 ) || ( V_22 == V_30 ) ||
( V_22 == V_31 ) || ( V_22 == V_32 ) ) {
switch ( V_20 -> V_33 & V_34 ) {
case V_35 :
V_23 =
F_5 (
( (struct V_36 * ) V_21 ) -> signal ) ;
break;
case V_37 :
V_23 =
F_6 (
( (struct V_38 * ) V_21 ) -> V_39 [ 0 ] ) ;
break;
case V_40 :
V_23 = ( V_21 [ 0 ] & V_41 ) | V_42 ;
if ( V_21 [ 0 ] & V_43 ) {
V_23 &= ~ V_44 ;
V_23 |= ( V_45 << V_25 ) ;
}
break;
case V_46 :
default:
break;
}
if ( F_7 ( V_21 [ 3 ] ) )
V_23 |= V_47 ;
} else
if ( ( V_22 == V_48 ) || ( V_20 -> V_33 & V_37 ) )
V_23 = F_6 (
( (struct V_38 * ) V_21 ) -> V_39 [ 0 ] ) ;
else
V_23 = F_5 (
( (struct V_36 * ) V_21 ) -> signal ) ;
return V_23 ;
}
void F_8 ( const struct V_1 * V_49 ,
struct V_1 * V_50 )
{
memcpy ( V_50 , V_49 , sizeof( struct V_1 ) ) ;
}
void
F_9 ( struct V_1 * V_49 , struct V_1 * V_50 ,
bool V_51 , T_2 V_6 , T_1 V_52 , bool V_53 )
{
T_1 V_9 ;
T_1 V_15 ;
T_1 V_5 ;
V_5 = 0 ;
for ( V_9 = 0 ; V_9 < V_49 -> V_5 ; V_9 ++ ) {
V_15 = V_49 -> V_6 [ V_9 ] ;
if ( V_51 && ! ( V_15 & V_7 ) )
continue;
if ( V_6 == V_54 &&
F_10 ( ( V_15 & V_16 ) ) )
continue;
if ( V_6 == V_55 &&
F_11 ( ( V_15 & V_16 ) ) )
continue;
V_50 -> V_6 [ V_5 ++ ] = V_15 & V_52 ;
}
V_50 -> V_5 = V_5 ;
V_50 -> V_56 = V_49 -> V_56 ;
if ( V_53 && V_6 != V_54 )
memcpy ( & V_50 -> V_11 [ 0 ] , & V_49 -> V_11 [ 0 ] , V_18 ) ;
else
F_12 ( V_50 ) ;
}
void
F_13 ( struct V_1 * V_57 ,
const struct V_1 * V_58 ,
T_1 V_22 , int V_59 , bool V_60 ,
T_1 V_61 , bool V_53 , T_2 V_62 , T_2 V_8 )
{
const struct V_1 * V_63 ;
struct V_1 V_64 ;
if ( ( F_14 ( V_22 , V_32 ) ) ||
( F_14 ( V_22 , V_29 ) ) ||
( F_14 ( V_22 , V_31 ) ) ||
( F_14 ( V_22 , V_30 ) ) ) {
if ( V_59 == V_65 )
V_63 = ( V_62 == V_66 ?
& V_67 : & V_68 ) ;
else
V_63 = ( V_62 == V_66 ?
& V_69 :
& V_70 ) ;
} else if ( F_14 ( V_22 , V_71 ) ) {
V_63 = ( V_59 == V_65 ) ?
& V_72 : & V_73 ;
} else if ( F_14 ( V_22 , V_48 ) ) {
V_63 = & V_72 ;
} else if ( F_14 ( V_22 , V_74 ) ) {
V_63 = & V_73 ;
} else {
V_63 = & V_75 ;
}
if ( ! V_58 )
V_58 = V_63 ;
F_8 ( V_63 , & V_64 ) ;
F_2 ( & V_64 , V_8 ) ;
F_9 ( & V_64 , V_57 , false ,
V_60 ? V_54 : V_76 ,
V_61 , V_53 ) ;
F_3 ( V_57 , V_58 , false ,
V_53 ? V_8 : 1 ) ;
}
T_4 F_15 ( T_1 V_77 )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ )
if ( V_77 == V_79 [ V_9 ] . V_80 )
return V_79 [ V_9 ] . V_81 ;
return - 1 ;
}
void F_12 ( struct V_1 * V_13 )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ )
V_13 -> V_11 [ V_9 ] = 0 ;
}
void F_16 ( struct V_1 * V_13 , T_2 V_8 )
{
memcpy ( & V_13 -> V_11 [ 0 ] , & V_69 . V_11 [ 0 ] , V_18 ) ;
F_2 ( V_13 , V_8 ) ;
}
void F_17 ( struct V_1 * V_13 , T_2 V_62 )
{
if ( V_62 == V_82 )
F_18 ( V_13 -> V_11 , 32 ) ;
else
F_19 ( V_13 -> V_11 , 32 ) ;
}
