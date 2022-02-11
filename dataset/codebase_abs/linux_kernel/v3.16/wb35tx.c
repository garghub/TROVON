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
F_4 ( & V_9 -> V_26 -> V_26 , L_2 ) ;
V_5 -> V_17 = V_27 ;
goto error;
}
F_5 ( V_11 ) ;
V_6 ( V_11 ) ;
return;
error:
F_6 ( & V_5 -> V_28 ) ;
V_5 -> V_17 = V_27 ;
}
static void V_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 * V_29 ;
struct V_14 * V_15 = & V_11 -> V_16 ;
struct V_8 * V_9 = (struct V_8 * ) V_5 -> V_30 ;
int V_31 ;
T_2 V_32 ;
if ( V_2 -> V_24 )
goto V_33;
if ( V_5 -> V_25 )
goto V_33;
V_32 = V_5 -> V_22 ;
if ( ! V_15 -> V_21 [ V_32 ] )
goto V_33;
V_29 = V_5 -> V_7 [ V_32 ] ;
F_7 ( V_9 , V_2 -> V_34 ,
F_8 ( V_2 -> V_34 , 4 ) ,
V_29 , V_15 -> V_35 [ V_32 ] ,
F_2 , V_11 ) ;
V_5 -> V_17 = V_36 ;
V_31 = F_9 ( V_9 , V_37 ) ;
if ( V_31 < 0 ) {
F_4 ( & V_9 -> V_26 -> V_26 , L_3 ) ;
goto V_33;
}
V_5 -> V_38 += V_15 -> V_39 [ V_32 ] ;
if ( V_5 -> V_38 > 12 )
F_10 ( V_11 ) ;
V_5 -> V_40 += V_15 -> V_35 [ V_32 ] ;
return;
V_33:
V_5 -> V_17 = V_27 ;
F_6 ( & V_5 -> V_28 ) ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( F_12 ( & V_5 -> V_28 ) == 1 ) {
V_5 -> V_17 = V_36 ;
V_6 ( V_11 ) ;
} else
F_6 ( & V_5 -> V_28 ) ;
}
unsigned char F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_5 -> V_30 = F_14 ( 0 , V_37 ) ;
if ( ! V_5 -> V_30 )
return false ;
V_5 -> V_41 = F_14 ( 0 , V_37 ) ;
if ( ! V_5 -> V_41 ) {
F_15 ( V_5 -> V_30 ) ;
return false ;
}
return true ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_42 == V_36 )
F_17 ( V_5 -> V_41 ) ;
F_18 ( L_4 ) ;
if ( V_5 -> V_17 == V_36 )
F_17 ( V_5 -> V_30 ) ;
F_18 ( L_5 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
do {
F_20 ( 10 ) ;
} while ( ( V_5 -> V_42 != V_27 ) && ( V_5 -> V_17 != V_27 ) );
F_20 ( 10 ) ;
F_15 ( V_5 -> V_30 ) ;
F_15 ( V_5 -> V_41 ) ;
F_18 ( L_6 ) ;
}
void F_21 ( struct V_10 * V_11 , T_2 V_43 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
bool V_44 = false ;
if ( V_5 -> V_45 > V_43 )
V_44 = true ;
else if ( V_43 > ( V_5 -> V_45 + 500 ) )
V_44 = true ;
if ( V_44 ) {
V_5 -> V_45 = V_43 ;
F_10 ( V_11 ) ;
}
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_46 V_47 , V_48 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
T_2 * V_49 = ( T_2 * ) V_5 -> V_50 ;
T_2 V_51 ;
T_3 V_52 ;
V_5 -> V_42 = V_18 ;
V_5 -> V_53 = V_9 -> V_20 ;
if ( V_2 -> V_24 )
goto error;
if ( V_5 -> V_25 )
goto error;
if ( V_5 -> V_53 != 0 ) {
F_4 ( & V_9 -> V_26 -> V_26 , L_7 ) ;
V_5 -> V_42 = V_27 ;
goto error;
}
V_52 = V_9 -> V_54 ;
V_47 . V_55 = F_23 ( V_49 [ 0 ] ) >> 8 ;
V_52 -= 1 ;
V_52 >>= 2 ;
for ( V_51 = 1 ; V_51 <= V_52 ; V_51 ++ ) {
V_47 . V_55 |= ( ( F_23 ( V_49 [ V_51 ] ) & 0xff ) << 24 ) ;
V_48 . V_55 = V_47 . V_55 ;
F_24 ( V_11 , & V_48 ) ;
V_47 . V_55 = F_23 ( V_49 [ V_51 ] ) >> 8 ;
}
return;
error:
F_6 ( & V_5 -> V_56 ) ;
V_5 -> V_42 = V_27 ;
}
static void F_25 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_8 * V_9 = (struct V_8 * ) V_5 -> V_41 ;
T_2 * V_49 = ( T_2 * ) V_5 -> V_50 ;
int V_31 ;
if ( V_2 -> V_24 )
goto error;
if ( V_5 -> V_25 )
goto error;
F_26 ( V_9 , V_2 -> V_34 , F_27 ( V_2 -> V_34 , 2 ) ,
V_49 , V_57 , F_22 ,
V_11 , 32 ) ;
V_5 -> V_42 = V_36 ;
V_31 = F_9 ( V_9 , V_37 ) ;
if ( V_31 < 0 ) {
F_18 ( L_8 ) ;
goto error;
}
return;
error:
V_5 -> V_42 = V_27 ;
F_6 ( & V_5 -> V_56 ) ;
}
void F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( F_12 ( & V_5 -> V_56 ) == 1 ) {
V_5 -> V_42 = V_36 ;
F_25 ( V_11 ) ;
} else
F_6 ( & V_5 -> V_56 ) ;
}
