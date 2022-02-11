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
if ( ( V_14 > V_13 ) || ( V_16 [ V_14 ] == 0 ) ) {
continue;
}
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
T_4 F_4 ( T_5 * V_18 , T_3 * V_19 )
{
int V_20 ;
T_4 V_21 = V_22 << V_23 ;
V_20 =
( ( V_18 -> V_24 & V_25 ) >> V_26 ) ;
if ( ( V_20 == V_27 ) || ( V_20 == V_28 ) ||
( V_20 == V_29 ) || ( V_20 == V_30 ) ) {
switch ( V_18 -> V_31 & V_32 ) {
case V_33 :
V_21 =
F_5 ( ( ( V_34 * ) V_19 ) -> signal ) ;
break;
case V_35 :
V_21 =
F_6 ( ( ( V_36 * ) V_19 ) ->
V_37 [ 0 ] ) ;
break;
case V_38 :
V_21 = ( V_19 [ 0 ] & V_39 ) | V_40 ;
if ( V_19 [ 0 ] & V_41 ) {
V_21 &= ~ V_42 ;
V_21 |= ( V_43 << V_23 ) ;
}
break;
case V_44 :
default:
break;
}
if ( F_7 ( V_19 [ 3 ] ) )
V_21 |= V_45 ;
} else
if ( ( V_20 == V_46 ) || ( V_18 -> V_31 & V_35 ) )
V_21 = F_6 ( ( ( V_36 * ) V_19 ) -> V_37 [ 0 ] ) ;
else
V_21 = F_5 ( ( ( V_34 * ) V_19 ) -> signal ) ;
return V_21 ;
}
void F_8 ( const T_1 * V_47 , T_1 * V_48 )
{
memcpy ( V_48 , V_47 , sizeof( T_1 ) ) ;
}
void
F_9 ( T_1 * V_47 , T_1 * V_48 , bool V_49 ,
T_3 V_5 , T_2 V_50 , bool V_51 )
{
T_2 V_8 ;
T_2 V_14 ;
T_2 V_4 ;
V_4 = 0 ;
for ( V_8 = 0 ; V_8 < V_47 -> V_4 ; V_8 ++ ) {
V_14 = V_47 -> V_5 [ V_8 ] ;
if ( V_49 && ! ( V_14 & V_6 ) )
continue;
if ( ( V_5 == V_52 ) && F_10 ( ( V_14 & V_15 ) ) )
continue;
if ( ( V_5 == V_53 ) && F_11 ( ( V_14 & V_15 ) ) )
continue;
V_48 -> V_5 [ V_4 ++ ] = V_14 & V_50 ;
}
V_48 -> V_4 = V_4 ;
V_48 -> V_54 = V_47 -> V_54 ;
if ( V_51 && V_5 != V_52 )
memcpy ( & V_48 -> V_10 [ 0 ] , & V_47 -> V_10 [ 0 ] , V_17 ) ;
else
F_12 ( V_48 ) ;
}
void
F_13 ( T_1 * V_55 , const T_1 * V_56 ,
T_2 V_20 , int V_57 , bool V_58 , T_2 V_59 ,
bool V_51 , T_3 V_60 , T_3 V_7 )
{
const T_1 * V_61 ;
T_1 V_62 ;
if ( ( F_14 ( V_20 , V_30 ) ) ||
( F_14 ( V_20 , V_27 ) ) ||
( F_14 ( V_20 , V_29 ) ) ||
( F_14 ( V_20 , V_28 ) ) ) {
if ( F_15 ( V_57 ) ) {
V_61 = ( V_60 == V_63 ?
& V_64 : & V_65 ) ;
} else {
V_61 = ( V_60 == V_63 ?
& V_66 :
& V_67 ) ;
}
} else if ( F_14 ( V_20 , V_68 ) ) {
V_61 = ( F_15 ( V_57 ) ) ? & V_69 : & V_70 ;
} else if ( F_14 ( V_20 , V_46 ) ) {
V_61 = & V_69 ;
} else if ( F_14 ( V_20 , V_71 ) ) {
V_61 = & V_70 ;
} else {
V_61 = & V_72 ;
}
if ( ! V_56 )
V_56 = V_61 ;
F_8 ( V_61 , & V_62 ) ;
F_2 ( & V_62 , V_7 ) ;
F_9 ( & V_62 , V_55 , false ,
V_58 ? V_52 : V_73 ,
V_59 , V_51 ) ;
F_3 ( V_55 , V_56 , false ,
V_51 ? V_7 : 1 ) ;
}
T_6 F_16 ( T_2 V_74 )
{
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_75 ; V_8 ++ )
if ( V_74 == V_76 [ V_8 ] . V_77 )
return V_76 [ V_8 ] . V_78 ;
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
memcpy ( & V_12 -> V_10 [ 0 ] , & V_66 . V_10 [ 0 ] , V_17 ) ;
F_2 ( V_12 , V_7 ) ;
}
void F_18 ( T_1 * V_12 , T_3 V_60 )
{
if ( V_60 == V_79 )
F_19 ( V_12 -> V_10 , 32 ) ;
else
F_20 ( V_12 -> V_10 , 32 ) ;
}
