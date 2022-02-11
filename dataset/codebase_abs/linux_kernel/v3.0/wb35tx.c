unsigned char
F_1 ( struct V_1 * V_2 , T_1 * * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
* V_3 = V_5 -> V_7 [ 0 ] ;
return true ;
}
static void F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_14 * V_15 = & V_11 -> V_16 ;
F_3 ( L_1 ) ;
V_5 -> V_17 = V_18 ;
V_5 -> V_19 = V_9 -> V_20 ;
V_15 -> V_21 [ V_5 -> V_22 ] = 0 ;
V_5 -> V_22 ++ ;
V_5 -> V_22 %= V_23 ;
if ( V_2 -> V_24 )
goto error;
if ( V_5 -> V_25 )
goto error;
if ( V_5 -> V_19 != 0 ) {
F_3 ( L_2 ) ;
V_5 -> V_17 = V_26 ;
goto error;
}
F_4 ( V_11 ) ;
V_6 ( V_11 ) ;
return;
error:
F_5 ( & V_5 -> V_27 ) ;
V_5 -> V_17 = V_26 ;
}
static void V_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 * V_28 ;
struct V_14 * V_15 = & V_11 -> V_16 ;
struct V_8 * V_9 = (struct V_8 * ) V_5 -> V_29 ;
int V_30 ;
T_2 V_31 ;
if ( V_2 -> V_24 )
goto V_32;
if ( V_5 -> V_25 )
goto V_32;
V_31 = V_5 -> V_22 ;
if ( ! V_15 -> V_21 [ V_31 ] )
goto V_32;
V_28 = V_5 -> V_7 [ V_31 ] ;
F_6 ( V_9 , V_2 -> V_33 ,
F_7 ( V_2 -> V_33 , 4 ) ,
V_28 , V_15 -> V_34 [ V_31 ] ,
F_2 , V_11 ) ;
V_5 -> V_17 = V_35 ;
V_30 = F_8 ( V_9 , V_36 ) ;
if ( V_30 < 0 ) {
F_3 ( L_3 ) ;
goto V_32;
}
V_5 -> V_37 += V_15 -> V_38 [ V_31 ] ;
if ( V_5 -> V_37 > 12 )
F_9 ( V_11 ) ;
V_5 -> V_39 += V_15 -> V_34 [ V_31 ] ;
return;
V_32:
V_5 -> V_17 = V_26 ;
F_5 ( & V_5 -> V_27 ) ;
}
void F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( F_11 ( & V_5 -> V_27 ) == 1 ) {
V_5 -> V_17 = V_35 ;
V_6 ( V_11 ) ;
} else
F_5 ( & V_5 -> V_27 ) ;
}
unsigned char F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_5 -> V_29 = F_13 ( 0 , V_36 ) ;
if ( ! V_5 -> V_29 )
return false ;
V_5 -> V_40 = F_13 ( 0 , V_36 ) ;
if ( ! V_5 -> V_40 )
{
F_14 ( V_5 -> V_29 ) ;
return false ;
}
return true ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_41 == V_35 )
F_16 ( V_5 -> V_40 ) ;
F_17 ( L_4 ) ;
if ( V_5 -> V_17 == V_35 )
F_16 ( V_5 -> V_29 ) ;
F_17 ( L_5 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
do {
F_19 ( 10 ) ;
} while( ( V_5 -> V_41 != V_26 ) && ( V_5 -> V_17 != V_26 ) );
F_19 ( 10 ) ;
if ( V_5 -> V_29 )
F_14 ( V_5 -> V_29 ) ;
if ( V_5 -> V_40 )
F_14 ( V_5 -> V_40 ) ;
F_17 ( L_6 ) ;
}
void F_20 ( struct V_10 * V_11 , T_2 V_42 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
unsigned char V_43 = false ;
if ( V_5 -> V_44 > V_42 )
V_43 = true ;
else if ( V_42 > ( V_5 -> V_44 + 500 ) )
V_43 = true ;
if ( V_43 ) {
V_5 -> V_44 = V_42 ;
F_9 ( V_11 ) ;
}
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_45 V_46 , V_47 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
T_2 * V_48 = ( T_2 * ) V_5 -> V_49 ;
T_2 V_50 ;
T_3 V_51 ;
V_5 -> V_41 = V_18 ;
V_5 -> V_52 = V_9 -> V_20 ;
if ( V_2 -> V_24 )
goto error;
if ( V_5 -> V_25 )
goto error;
if ( V_5 -> V_52 != 0 ) {
F_3 ( L_7 ) ;
V_5 -> V_41 = V_26 ;
goto error;
}
V_51 = V_9 -> V_53 ;
V_46 . V_54 = F_22 ( V_48 [ 0 ] ) >> 8 ;
V_51 -= 1 ;
V_51 >>= 2 ;
for ( V_50 = 1 ; V_50 <= V_51 ; V_50 ++ ) {
V_46 . V_54 |= ( ( F_22 ( V_48 [ V_50 ] ) & 0xff ) << 24 ) ;
V_47 . V_54 = V_46 . V_54 ;
F_23 ( V_11 , & V_47 ) ;
V_46 . V_54 = F_22 ( V_48 [ V_50 ] ) >> 8 ;
}
return;
error:
F_5 ( & V_5 -> V_55 ) ;
V_5 -> V_41 = V_26 ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_8 * V_9 = (struct V_8 * ) V_5 -> V_40 ;
T_2 * V_48 = ( T_2 * ) V_5 -> V_49 ;
int V_30 ;
if ( V_2 -> V_24 )
goto error;
if ( V_5 -> V_25 )
goto error;
F_25 ( V_9 , V_2 -> V_33 , F_26 ( V_2 -> V_33 , 2 ) ,
V_48 , V_56 , F_21 , V_11 , 32 ) ;
V_5 -> V_41 = V_35 ;
V_30 = F_8 ( V_9 , V_36 ) ;
if ( V_30 < 0 ) {
F_17 ( L_8 ) ;
goto error;
}
return;
error:
V_5 -> V_41 = V_26 ;
F_5 ( & V_5 -> V_55 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( F_11 ( & V_5 -> V_55 ) == 1 ) {
V_5 -> V_41 = V_35 ;
F_24 ( V_11 ) ;
} else
F_5 ( & V_5 -> V_55 ) ;
}
