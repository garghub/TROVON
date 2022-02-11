STATIC int
F_1 (
struct V_1 * * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
int V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 ;
T_1 V_11 ;
T_2 V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
int error ;
V_11 = V_5 ;
V_13 = V_6 ;
while ( V_13 > 0 ) {
V_15 = 1 ;
error = F_2 ( V_4 , ( V_16 ) V_11 , V_13 ,
& V_8 , & V_15 , V_17 ) ;
if ( error ) {
return ( error ) ;
}
ASSERT ( V_15 == 1 ) ;
ASSERT ( V_8 . V_18 != V_19 ) ;
if ( V_8 . V_18 != V_20 ) {
V_12 = F_3 ( V_4 -> V_21 ,
V_8 . V_18 ) ;
V_14 = F_4 ( V_4 -> V_21 ,
V_8 . V_22 ) ;
V_10 = F_5 ( * V_2 ,
V_4 -> V_21 -> V_23 ,
V_12 , V_14 , 0 ) ;
if ( ! V_10 )
return V_24 ;
F_6 ( * V_2 , V_10 ) ;
error = F_7 ( V_2 , V_4 ) ;
if ( error )
return ( error ) ;
}
V_11 += V_8 . V_22 ;
V_13 -= V_8 . V_22 ;
}
return ( 0 ) ;
}
STATIC int
F_8 (
struct V_1 * * V_2 ,
struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_25 * V_26 ;
struct V_27 V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_33 * V_35 ;
int error ;
int V_36 ;
int V_37 ;
int V_38 ;
int V_39 ;
V_26 = V_10 -> V_40 ;
F_9 ( & V_28 , V_26 ) ;
V_36 = 0 ;
V_30 = F_10 ( V_26 ) ;
for ( V_39 = 0 ; V_39 < V_28 . V_36 ; V_30 ++ , V_39 ++ ) {
if ( F_11 ( V_30 -> V_41 ) &&
( ( V_30 -> V_42 & V_43 ) == 0 ) ) {
V_32 = F_12 ( V_26 , V_39 ) ;
if ( V_32 -> V_44 )
V_36 ++ ;
}
}
if ( V_36 == 0 ) {
F_13 ( * V_2 , V_10 ) ;
return 0 ;
}
V_37 = V_36 * sizeof( V_45 ) ;
V_34 = F_14 ( V_37 , V_46 ) ;
V_35 = V_34 ;
V_30 = F_10 ( V_26 ) ;
for ( V_39 = 0 ; V_39 < V_28 . V_36 ; V_30 ++ , V_39 ++ ) {
if ( F_11 ( V_30 -> V_41 ) &&
( ( V_30 -> V_42 & V_43 ) == 0 ) ) {
V_32 = F_12 ( V_26 , V_39 ) ;
if ( V_32 -> V_44 ) {
V_35 -> V_44 = F_15 ( V_32 -> V_44 ) ;
V_35 -> V_47 = F_16 ( V_4 -> V_21 ,
F_15 ( V_32 -> V_47 ) ) ;
V_35 ++ ;
}
}
}
F_13 ( * V_2 , V_10 ) ;
error = 0 ;
for ( V_35 = V_34 , V_39 = 0 ; V_39 < V_36 ; V_39 ++ , V_35 ++ ) {
V_38 = F_1 ( V_2 , V_4 ,
V_35 -> V_44 , V_35 -> V_47 ) ;
if ( error == 0 )
error = V_38 ;
}
F_17 ( V_34 ) ;
return error ;
}
STATIC int
F_18 (
struct V_1 * * V_2 ,
struct V_3 * V_4 ,
struct V_9 * V_10 ,
int V_48 )
{
T_3 * V_49 ;
T_4 * V_50 ;
T_1 V_51 ;
T_2 V_52 , V_53 ;
int error , V_39 ;
struct V_9 * V_54 ;
struct V_55 * V_56 ;
struct V_57 V_28 ;
if ( V_48 > V_58 ) {
F_13 ( * V_2 , V_10 ) ;
return F_19 ( V_59 ) ;
}
V_50 = V_10 -> V_40 ;
F_20 ( & V_28 , V_50 ) ;
V_52 = V_10 -> V_60 ;
if ( ! V_28 . V_36 ) {
F_13 ( * V_2 , V_10 ) ;
return 0 ;
}
V_56 = F_21 ( V_50 ) ;
V_51 = F_15 ( V_56 [ 0 ] . V_61 ) ;
F_13 ( * V_2 , V_10 ) ;
for ( V_39 = 0 ; V_39 < V_28 . V_36 ; V_39 ++ ) {
error = F_22 ( * V_2 , V_4 , V_51 , - 2 , & V_54 ,
V_62 ) ;
if ( error )
return ( error ) ;
if ( V_54 ) {
V_53 = F_23 ( V_54 ) ;
V_49 = V_54 -> V_40 ;
switch ( V_49 -> V_63 ) {
case F_24 ( V_64 ) :
case F_24 ( V_65 ) :
error = F_18 ( V_2 , V_4 ,
V_54 , V_48 + 1 ) ;
break;
case F_24 ( V_66 ) :
case F_24 ( V_67 ) :
error = F_8 ( V_2 , V_4 ,
V_54 ) ;
break;
default:
error = F_19 ( V_59 ) ;
F_13 ( * V_2 , V_54 ) ;
break;
}
if ( error )
return error ;
error = F_25 ( * V_2 , V_4 , 0 , V_53 ,
& V_54 , V_62 ) ;
if ( error )
return error ;
F_6 ( * V_2 , V_54 ) ;
}
if ( V_39 + 1 < V_28 . V_36 ) {
error = F_22 ( * V_2 , V_4 , 0 , V_52 ,
& V_10 , V_62 ) ;
if ( error )
return error ;
V_51 = F_15 ( V_56 [ V_39 + 1 ] . V_61 ) ;
F_13 ( * V_2 , V_10 ) ;
}
error = F_7 ( V_2 , V_4 ) ;
if ( error )
return error ;
}
return 0 ;
}
int
F_26 (
struct V_1 * * V_2 ,
struct V_3 * V_4 )
{
struct V_68 * V_49 ;
struct V_9 * V_10 ;
T_2 V_5 ;
int error ;
error = F_22 ( * V_2 , V_4 , 0 , - 1 , & V_10 , V_62 ) ;
if ( error )
return error ;
V_5 = V_10 -> V_60 ;
V_49 = V_10 -> V_40 ;
switch ( V_49 -> V_63 ) {
case F_24 ( V_64 ) :
case F_24 ( V_65 ) :
error = F_18 ( V_2 , V_4 , V_10 , 1 ) ;
break;
case F_24 ( V_66 ) :
case F_24 ( V_67 ) :
error = F_8 ( V_2 , V_4 , V_10 ) ;
break;
default:
error = F_19 ( V_59 ) ;
F_13 ( * V_2 , V_10 ) ;
break;
}
if ( error )
return error ;
error = F_25 ( * V_2 , V_4 , 0 , V_5 , & V_10 , V_62 ) ;
if ( error )
return error ;
F_6 ( * V_2 , V_10 ) ;
error = F_7 ( V_2 , V_4 ) ;
return error ;
}
int
F_27 ( T_5 * V_4 )
{
T_6 * V_2 ;
T_7 * V_69 ;
int error ;
V_69 = V_4 -> V_21 ;
ASSERT ( ! F_28 ( V_69 , V_4 ) ) ;
F_29 ( V_4 , V_70 ) ;
if ( ! F_30 ( V_4 ) ||
V_4 -> V_71 . V_72 == V_73 ) {
F_31 ( V_4 , V_70 ) ;
return 0 ;
}
F_31 ( V_4 , V_70 ) ;
V_2 = F_32 ( V_69 , V_74 ) ;
error = F_33 ( V_2 , & F_34 ( V_69 ) -> V_75 , 0 , 0 ) ;
if ( error ) {
F_35 ( V_2 , 0 ) ;
return ( error ) ;
}
F_29 ( V_4 , V_76 ) ;
F_36 ( V_2 , V_4 , 0 ) ;
if ( ! F_30 ( V_4 ) ||
V_4 -> V_71 . V_72 == V_73 ) {
error = 0 ;
goto V_77;
}
error = F_26 ( & V_2 , V_4 ) ;
if ( error )
goto V_77;
error = F_37 ( & V_2 , V_4 , V_62 , 0 ) ;
if ( error )
goto V_77;
error = F_38 ( V_2 , V_78 ) ;
F_31 ( V_4 , V_76 ) ;
return ( error ) ;
V_77:
F_35 ( V_2 , V_78 | V_79 ) ;
F_31 ( V_4 , V_76 ) ;
return ( error ) ;
}
