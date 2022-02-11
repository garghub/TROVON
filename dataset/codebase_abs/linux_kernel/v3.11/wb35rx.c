static void F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 = { 0 } ;
if ( ! V_6 -> V_11 )
return;
V_8 = F_2 ( V_4 ) ;
if ( ! V_8 ) {
F_3 ( L_1 ) ;
return;
}
memcpy ( F_4 ( V_8 , V_4 ) , V_3 , V_4 ) ;
memcpy ( F_5 ( V_8 ) , & V_10 , sizeof( V_10 ) ) ;
F_6 ( V_2 , V_8 ) ;
}
static void F_7 ( struct V_12 * V_13 )
{
T_1 * V_3 ;
T_1 V_14 ;
T_1 V_15 ;
T_2 V_16 ;
V_14 = V_13 -> V_17 . V_18 ;
V_3 = V_13 -> V_19 [ 0 ] ;
V_16 = V_13 -> V_20 [ 0 ] ;
V_16 -= 4 ;
if ( V_14 )
V_16 -= 4 ;
if ( V_14 == 3 )
V_16 -= 4 ;
if ( V_14 == 1 ) {
for ( V_15 = 6 ; V_15 > 0 ; V_15 -- )
V_3 [ V_15 ] = V_3 [ V_15 - 1 ] ;
V_13 -> V_19 [ 0 ] = V_3 + 1 ;
V_16 -= 4 ;
} else if ( V_14 ) {
for ( V_15 = 7 ; V_15 > 1 ; V_15 -- )
V_3 [ V_15 ] = V_3 [ V_15 - 2 ] ;
V_13 -> V_19 [ 0 ] = V_3 + 2 ;
V_16 -= 8 ;
}
V_13 -> V_20 [ 0 ] = V_16 ;
}
static T_2 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = & V_6 -> V_23 ;
struct V_12 V_24 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
T_3 * V_3 ;
T_2 V_4 ;
T_2 V_28 , V_16 , V_29 = 0 ;
T_1 V_30 ;
do {
V_30 = V_26 -> V_31 ;
if ( V_26 -> V_32 [ V_30 ] )
break;
V_26 -> V_31 ++ ;
V_26 -> V_31 %= V_33 ;
V_3 = V_26 -> V_34 ;
V_16 = V_26 -> V_35 [ V_30 ] ;
while ( V_16 >= 4 ) {
if ( ( F_9 ( * ( T_1 * ) V_3 ) & 0x0fffffff ) == V_36 )
break;
V_24 . V_37 . V_38 = F_10 ( * ( T_1 * ) V_3 ) ;
V_4 = ( T_2 ) V_24 . V_37 . V_39 ;
V_24 . V_17 . V_38 = F_10 ( * ( ( T_1 * ) ( V_3 + 4 ) ) ) ;
if ( ( V_4 & 0x03 ) > 0 )
V_4 -= 4 ;
if ( V_4 > V_40 ) {
F_11 ( L_2 , V_4 ) ;
V_26 -> V_41 = V_42 ;
V_26 -> V_43 ++ ;
break;
}
V_16 -= 8 ;
V_3 += 8 ;
V_24 . V_19 [ 0 ] = V_3 ;
V_24 . V_20 [ 0 ] = V_4 ;
V_24 . V_44 = 1 ;
V_24 . V_45 = 0 ;
V_24 . V_46 = V_24 . V_20 [ 0 ] ;
F_7 ( & V_24 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_28 = V_4 + 3 ;
V_28 &= ~ 0x03 ;
V_3 += V_28 ;
V_16 -= V_28 ;
V_29 += V_28 ;
}
V_26 -> V_32 [ V_30 ] = 1 ;
} while ( true );
return V_29 ;
}
static void F_12 ( struct V_47 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = & V_6 -> V_23 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
T_3 * V_3 ;
T_1 V_49 ;
T_2 V_50 ;
T_1 V_30 ;
struct V_51 V_37 ;
V_26 -> V_41 = V_52 ;
V_26 -> V_53 = V_47 -> V_54 ;
V_30 = V_26 -> V_55 ;
V_3 = V_26 -> V_34 ;
V_50 = ( T_2 ) V_47 -> V_56 ;
V_26 -> V_41 = V_52 ;
if ( V_22 -> V_57 )
goto error;
if ( V_26 -> V_58 )
goto error;
V_26 -> V_32 [ V_30 ] = 0 ;
V_37 . V_38 = F_10 ( * ( T_1 * ) V_3 ) ;
if ( V_26 -> V_53 != 0 ) {
F_11 ( L_3 ) ;
V_26 -> V_41 = V_42 ;
goto error;
}
if ( ! F_13 ( V_22 ) ) {
V_49 = V_37 . V_39 ;
if ( ( V_49 & 0x03 ) > 0 )
V_49 -= 4 ;
V_49 = ( V_49 + 3 ) & ~ 0x03 ;
V_49 += 12 ;
if ( ( V_50 > 1600 ) ||
( V_49 > 1600 ) ||
( V_50 != V_49 ) ||
( V_50 == 0 ) ) {
V_26 -> V_41 = V_42 ;
V_26 -> V_43 ++ ;
}
}
V_26 -> V_59 += V_50 ;
V_26 -> V_35 [ V_30 ] = V_50 ;
if ( ! V_26 -> V_32 [ V_30 ] )
F_8 ( V_2 ) ;
F_14 ( V_26 -> V_34 ) ;
V_27 ( V_2 ) ;
return;
error:
V_26 -> V_32 [ V_30 ] = 1 ;
F_15 ( & V_26 -> V_60 ) ;
V_26 -> V_41 = V_42 ;
}
static void V_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = & V_6 -> V_23 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
T_3 * V_3 ;
struct V_47 * V_47 = V_26 -> V_61 ;
int V_62 ;
T_1 V_30 ;
if ( V_22 -> V_57 )
goto error;
if ( V_26 -> V_58 )
goto error;
V_30 = V_26 -> V_30 ;
if ( ! V_26 -> V_32 [ V_30 ] ) {
F_11 ( L_4 ) ;
goto error;
}
V_26 -> V_30 ++ ;
V_26 -> V_30 %= V_33 ;
V_26 -> V_55 = V_30 ;
V_26 -> V_34 = F_16 ( V_63 , V_64 ) ;
if ( ! V_26 -> V_34 ) {
F_3 ( L_5 ) ;
goto error;
}
V_3 = V_26 -> V_34 ;
F_17 ( V_47 , V_22 -> V_65 ,
F_18 ( V_22 -> V_65 , 3 ) ,
V_3 , V_63 ,
F_12 , V_2 ) ;
V_26 -> V_41 = V_66 ;
V_62 = F_19 ( V_47 , V_64 ) ;
if ( V_62 != 0 ) {
F_3 ( L_6 ) ;
goto error;
}
return;
error:
V_26 -> V_41 = V_42 ;
F_15 ( & V_26 -> V_60 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = & V_6 -> V_23 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
if ( F_21 ( & V_26 -> V_60 ) == 1 ) {
V_26 -> V_41 = V_66 ;
V_27 ( V_2 ) ;
} else
F_15 ( & V_26 -> V_60 ) ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
T_1 V_15 ;
V_26 -> V_59 = 0 ;
V_26 -> V_31 = 0 ;
V_26 -> V_30 = 0 ;
V_26 -> V_41 = V_42 ;
V_26 -> V_58 = 0 ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ )
V_26 -> V_32 [ V_15 ] = 1 ;
}
unsigned char F_23 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
F_22 ( V_22 ) ;
V_26 -> V_61 = F_24 ( 0 , V_64 ) ;
return ! ! V_26 -> V_61 ;
}
void F_25 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
if ( V_26 -> V_41 == V_66 ) {
F_26 ( V_26 -> V_61 ) ;
F_11 ( L_7 ) ;
}
}
void F_27 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
do {
F_28 ( 10 ) ;
} while ( V_26 -> V_41 != V_42 );
F_28 ( 10 ) ;
F_29 ( V_26 -> V_61 ) ;
F_11 ( L_8 ) ;
}
