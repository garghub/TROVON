STATIC void
F_1 (
T_1 * V_1 ,
T_1 * V_2 ,
T_1 * V_3 ,
T_1 * V_4 ,
T_1 * * V_5 ,
int * V_6 )
{
T_1 * V_7 ;
int V_8 , V_9 ;
V_5 [ 0 ] = V_1 ;
V_5 [ 1 ] = V_2 ;
V_5 [ 2 ] = V_3 ;
if ( V_4 ) {
* V_6 = 4 ;
V_5 [ 3 ] = V_4 ;
} else {
* V_6 = 3 ;
V_5 [ 3 ] = NULL ;
}
for ( V_8 = 0 ; V_8 < * V_6 ; V_8 ++ ) {
for ( V_9 = 1 ; V_9 < * V_6 ; V_9 ++ ) {
if ( V_5 [ V_9 ] -> V_10 < V_5 [ V_9 - 1 ] -> V_10 ) {
V_7 = V_5 [ V_9 ] ;
V_5 [ V_9 ] = V_5 [ V_9 - 1 ] ;
V_5 [ V_9 - 1 ] = V_7 ;
}
}
}
}
int
F_2 (
T_1 * V_11 ,
struct V_12 * V_13 ,
T_1 * V_14 ,
T_1 * V_15 ,
struct V_12 * V_16 ,
T_1 * V_17 )
{
T_2 * V_18 = NULL ;
T_3 * V_19 = V_11 -> V_20 ;
int V_21 ;
int V_22 ;
int error ;
T_4 V_23 ;
T_5 V_24 ;
int V_25 ;
int V_26 ;
T_1 * V_27 [ 4 ] ;
int V_28 ;
int V_6 ;
F_3 ( V_11 , V_15 , V_13 , V_16 ) ;
V_21 = ( V_11 != V_15 ) ;
V_22 = F_4 ( V_14 -> V_29 . V_30 ) ;
F_1 ( V_11 , V_15 , V_14 , V_17 ,
V_27 , & V_6 ) ;
F_5 ( & V_23 , & V_24 ) ;
V_18 = F_6 ( V_19 , V_31 ) ;
V_25 = V_32 ;
V_28 = F_7 ( V_19 , V_16 -> V_33 ) ;
error = F_8 ( V_18 , V_28 , F_9 ( V_19 ) , 0 ,
V_34 , V_35 ) ;
if ( error == V_36 ) {
V_28 = 0 ;
error = F_8 ( V_18 , 0 , F_9 ( V_19 ) , 0 ,
V_34 , V_35 ) ;
}
if ( error ) {
F_10 ( V_18 , 0 ) ;
goto V_37;
}
error = F_11 ( V_27 ) ;
if ( error ) {
F_10 ( V_18 , V_25 ) ;
goto V_37;
}
F_12 ( V_27 , V_6 , V_38 ) ;
F_13 ( V_18 , V_11 , V_38 ) ;
if ( V_21 )
F_13 ( V_18 , V_15 , V_38 ) ;
F_13 ( V_18 , V_14 , V_38 ) ;
if ( V_17 )
F_13 ( V_18 , V_17 , V_38 ) ;
if ( F_14 ( ( V_15 -> V_29 . V_39 & V_40 ) &&
( F_15 ( V_15 ) != F_15 ( V_14 ) ) ) ) {
error = F_16 ( V_41 ) ;
goto V_42;
}
if ( V_17 == NULL ) {
error = F_17 ( V_18 , V_15 , V_16 , V_28 ) ;
if ( error )
goto V_42;
error = F_18 ( V_18 , V_15 , V_16 ,
V_14 -> V_10 , & V_24 ,
& V_23 , V_28 ) ;
if ( error == V_36 )
goto V_42;
if ( error )
goto V_43;
F_19 ( V_18 , V_15 ,
V_44 | V_45 ) ;
if ( V_21 && V_22 ) {
error = F_20 ( V_18 , V_15 ) ;
if ( error )
goto V_43;
}
} else {
if ( F_4 ( V_17 -> V_29 . V_30 ) ) {
if ( ! ( F_21 ( V_17 ) ) ||
( V_17 -> V_29 . V_46 > 2 ) ) {
error = F_16 ( V_47 ) ;
goto V_42;
}
}
error = F_22 ( V_18 , V_15 , V_16 ,
V_14 -> V_10 ,
& V_24 , & V_23 , V_28 ) ;
if ( error )
goto V_43;
F_19 ( V_18 , V_15 ,
V_44 | V_45 ) ;
error = F_23 ( V_18 , V_17 ) ;
if ( error )
goto V_43;
if ( V_22 ) {
error = F_23 ( V_18 , V_17 ) ;
if ( error )
goto V_43;
}
}
if ( V_21 && V_22 ) {
error = F_22 ( V_18 , V_14 , & V_48 ,
V_15 -> V_10 ,
& V_24 , & V_23 , V_28 ) ;
ASSERT ( error != V_47 ) ;
if ( error )
goto V_43;
}
F_19 ( V_18 , V_14 , V_45 ) ;
F_24 ( V_18 , V_14 , V_49 ) ;
if ( V_22 && ( V_21 || V_17 != NULL ) ) {
error = F_23 ( V_18 , V_11 ) ;
if ( error )
goto V_43;
}
error = F_25 ( V_18 , V_11 , V_13 , V_14 -> V_10 ,
& V_24 , & V_23 , V_28 ) ;
if ( error )
goto V_43;
F_19 ( V_18 , V_11 , V_44 | V_45 ) ;
F_24 ( V_18 , V_11 , V_49 ) ;
if ( V_21 )
F_24 ( V_18 , V_15 , V_49 ) ;
if ( V_19 -> V_50 & ( V_51 | V_52 ) ) {
F_26 ( V_18 ) ;
}
error = F_27 ( & V_18 , & V_23 , & V_26 ) ;
if ( error ) {
F_28 ( & V_23 ) ;
F_10 ( V_18 , ( V_32 |
V_53 ) ) ;
goto V_37;
}
return F_29 ( V_18 , V_32 ) ;
V_43:
V_25 |= V_53 ;
V_42:
F_28 ( & V_23 ) ;
F_10 ( V_18 , V_25 ) ;
V_37:
return error ;
}
