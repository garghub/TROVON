static bool F_1 ( T_1 * V_1 , bool V_2 )
{
T_2 V_3 ;
if ( ! V_1 -> V_4 )
return false ;
if ( ! V_2 )
return true ;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] & V_6 )
return true ;
}
return false ;
}
void F_2 ( T_1 * V_1 , T_3 V_7 )
{
int V_8 ;
for ( V_8 = V_7 ; V_8 < V_9 ; V_8 ++ )
V_1 -> V_10 [ V_8 ] = 0 ;
}
bool
F_3 ( T_1 * V_1 ,
const T_1 * V_11 ,
bool V_2 , T_3 V_7 )
{
T_3 V_12 [ V_13 + 1 ] ;
T_3 V_14 ;
T_2 V_4 ;
T_2 V_8 ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_4 = V_1 -> V_4 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
V_14 = ( int ) V_1 -> V_5 [ V_8 ] & V_15 ;
if ( ( V_14 > V_13 ) || ( V_16 [ V_14 ] == 0 ) )
continue;
V_12 [ V_14 ] = V_1 -> V_5 [ V_8 ] ;
}
V_4 = 0 ;
for ( V_8 = 0 ; V_8 < V_11 -> V_4 ; V_8 ++ ) {
V_14 = V_11 -> V_5 [ V_8 ] & V_15 ;
if ( V_12 [ V_14 ] )
V_1 -> V_5 [ V_4 ++ ] = V_12 [ V_14 ] ;
}
V_1 -> V_4 = V_4 ;
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ )
V_1 -> V_10 [ V_8 ] = ( V_1 -> V_10 [ V_8 ] & V_11 -> V_10 [ V_8 ] ) ;
if ( F_1 ( V_1 , V_2 ) )
return true ;
else
return false ;
}
T_4 F_4 ( struct V_18 * V_19 , T_3 * V_20 )
{
int V_21 ;
T_4 V_22 = V_23 << V_24 ;
V_21 =
( ( V_19 -> V_25 & V_26 ) >> V_27 ) ;
if ( ( V_21 == V_28 ) || ( V_21 == V_29 ) ||
( V_21 == V_30 ) || ( V_21 == V_31 ) ) {
switch ( V_19 -> V_32 & V_33 ) {
case V_34 :
V_22 =
F_5 (
( (struct V_35 * ) V_20 ) -> signal ) ;
break;
case V_36 :
V_22 =
F_6 (
( (struct V_37 * ) V_20 ) -> V_38 [ 0 ] ) ;
break;
case V_39 :
V_22 = ( V_20 [ 0 ] & V_40 ) | V_41 ;
if ( V_20 [ 0 ] & V_42 ) {
V_22 &= ~ V_43 ;
V_22 |= ( V_44 << V_24 ) ;
}
break;
case V_45 :
default:
break;
}
if ( F_7 ( V_20 [ 3 ] ) )
V_22 |= V_46 ;
} else
if ( ( V_21 == V_47 ) || ( V_19 -> V_32 & V_36 ) )
V_22 = F_6 (
( (struct V_37 * ) V_20 ) -> V_38 [ 0 ] ) ;
else
V_22 = F_5 (
( (struct V_35 * ) V_20 ) -> signal ) ;
return V_22 ;
}
void F_8 ( const T_1 * V_48 , T_1 * V_49 )
{
memcpy ( V_49 , V_48 , sizeof( T_1 ) ) ;
}
void
F_9 ( T_1 * V_48 , T_1 * V_49 , bool V_50 ,
T_3 V_5 , T_2 V_51 , bool V_52 )
{
T_2 V_8 ;
T_2 V_14 ;
T_2 V_4 ;
V_4 = 0 ;
for ( V_8 = 0 ; V_8 < V_48 -> V_4 ; V_8 ++ ) {
V_14 = V_48 -> V_5 [ V_8 ] ;
if ( V_50 && ! ( V_14 & V_6 ) )
continue;
if ( V_5 == V_53 && F_10 ( ( V_14 & V_15 ) ) )
continue;
if ( V_5 == V_54 && F_11 ( ( V_14 & V_15 ) ) )
continue;
V_49 -> V_5 [ V_4 ++ ] = V_14 & V_51 ;
}
V_49 -> V_4 = V_4 ;
V_49 -> V_55 = V_48 -> V_55 ;
if ( V_52 && V_5 != V_53 )
memcpy ( & V_49 -> V_10 [ 0 ] , & V_48 -> V_10 [ 0 ] , V_17 ) ;
else
F_12 ( V_49 ) ;
}
void
F_13 ( T_1 * V_56 , const T_1 * V_57 ,
T_2 V_21 , int V_58 , bool V_59 , T_2 V_60 ,
bool V_52 , T_3 V_61 , T_3 V_7 )
{
const T_1 * V_62 ;
T_1 V_63 ;
if ( ( F_14 ( V_21 , V_31 ) ) ||
( F_14 ( V_21 , V_28 ) ) ||
( F_14 ( V_21 , V_30 ) ) ||
( F_14 ( V_21 , V_29 ) ) ) {
if ( F_15 ( V_58 ) ) {
V_62 = ( V_61 == V_64 ?
& V_65 : & V_66 ) ;
} else {
V_62 = ( V_61 == V_64 ?
& V_67 :
& V_68 ) ;
}
} else if ( F_14 ( V_21 , V_69 ) ) {
V_62 = ( F_15 ( V_58 ) ) ? & V_70 : & V_71 ;
} else if ( F_14 ( V_21 , V_47 ) ) {
V_62 = & V_70 ;
} else if ( F_14 ( V_21 , V_72 ) ) {
V_62 = & V_71 ;
} else {
V_62 = & V_73 ;
}
if ( ! V_57 )
V_57 = V_62 ;
F_8 ( V_62 , & V_63 ) ;
F_2 ( & V_63 , V_7 ) ;
F_9 ( & V_63 , V_56 , false ,
V_59 ? V_53 : V_74 ,
V_60 , V_52 ) ;
F_3 ( V_56 , V_57 , false ,
V_52 ? V_7 : 1 ) ;
}
T_5 F_16 ( T_2 V_75 )
{
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_76 ; V_8 ++ )
if ( V_75 == V_77 [ V_8 ] . V_78 )
return V_77 [ V_8 ] . V_79 ;
return - 1 ;
}
void F_12 ( T_1 * V_12 )
{
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ )
V_12 -> V_10 [ V_8 ] = 0 ;
}
void F_17 ( T_1 * V_12 , T_3 V_7 )
{
memcpy ( & V_12 -> V_10 [ 0 ] , & V_67 . V_10 [ 0 ] , V_17 ) ;
F_2 ( V_12 , V_7 ) ;
}
void F_18 ( T_1 * V_12 , T_3 V_61 )
{
if ( V_61 == V_80 )
F_19 ( V_12 -> V_10 , 32 ) ;
else
F_20 ( V_12 -> V_10 , 32 ) ;
}
