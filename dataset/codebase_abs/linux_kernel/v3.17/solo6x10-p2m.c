int F_1 ( struct V_1 * V_1 , int V_2 ,
void * V_3 , T_1 V_4 , T_1 V_5 ,
int V_6 , T_1 V_7 )
{
T_2 V_8 ;
int V_9 ;
if ( F_2 ( ( unsigned long ) V_3 & 0x03 ) )
return - V_10 ;
if ( F_2 ( ! V_5 ) )
return - V_10 ;
V_8 = F_3 ( V_1 -> V_11 , V_3 , V_5 ,
V_2 ? V_12 : V_13 ) ;
if ( F_4 ( V_1 -> V_11 , V_8 ) )
return - V_14 ;
V_9 = F_5 ( V_1 , V_2 , V_8 , V_4 , V_5 ,
V_6 , V_7 ) ;
F_6 ( V_1 -> V_11 , V_8 , V_5 ,
V_2 ? V_12 : V_13 ) ;
return V_9 ;
}
int F_7 ( struct V_1 * V_1 ,
struct V_15 * V_16 , T_2 V_17 ,
int V_18 )
{
struct V_19 * V_20 ;
unsigned int V_21 ;
unsigned int V_22 = 0 ;
int V_9 = 0 ;
int V_23 = 0 ;
if ( V_1 -> type != V_24 && V_25 ) {
V_23 = F_8 ( & V_1 -> V_26 ) % V_27 ;
if ( V_23 < 0 )
V_23 = - V_23 ;
}
V_20 = & V_1 -> V_20 [ V_23 ] ;
if ( F_9 ( & V_20 -> V_28 ) )
return - V_29 ;
F_10 ( & V_20 -> V_30 ) ;
V_20 -> error = 0 ;
if ( V_18 > 1 && V_1 -> type != V_24 && V_31 ) {
V_20 -> V_32 = V_20 -> V_33 = 0 ;
V_22 = F_11 ( V_1 , F_12 ( V_23 ) ) ;
F_13 ( V_1 , F_14 ( V_23 ) , V_17 ) ;
F_13 ( V_1 , F_15 ( V_23 ) , V_18 ) ;
F_13 ( V_1 , F_12 ( V_23 ) , V_22 |
V_34 ) ;
} else {
V_20 -> V_32 = V_18 ;
V_20 -> V_33 = 1 ;
V_20 -> V_35 = V_16 ;
F_13 ( V_1 , F_16 ( V_23 ) ,
V_16 [ 1 ] . V_8 ) ;
F_13 ( V_1 , F_17 ( V_23 ) ,
V_16 [ 1 ] . V_4 ) ;
F_13 ( V_1 , F_18 ( V_23 ) ,
V_16 [ 1 ] . V_36 ) ;
F_13 ( V_1 , F_19 ( V_23 ) ,
V_16 [ 1 ] . V_37 ) ;
}
V_21 = F_20 ( & V_20 -> V_30 ,
V_1 -> V_38 ) ;
if ( F_2 ( V_20 -> error ) )
V_9 = - V_39 ;
else if ( V_21 == 0 ) {
V_1 -> V_40 ++ ;
V_9 = - V_41 ;
}
F_13 ( V_1 , F_19 ( V_23 ) , 0 ) ;
if ( V_18 > 1 && V_1 -> type != V_24 && V_22 )
F_13 ( V_1 , F_12 ( V_23 ) , V_22 ) ;
F_21 ( & V_20 -> V_28 ) ;
return V_9 ;
}
void F_22 ( struct V_15 * V_16 , int V_2 ,
T_2 V_8 , T_1 V_4 , T_1 V_5 ,
int V_6 , T_1 V_7 )
{
F_2 ( V_8 & 0x03 ) ;
F_2 ( ! V_5 ) ;
V_16 -> V_36 = F_23 ( V_5 >> 2 ) ;
V_16 -> V_37 = F_24 ( V_42 ) |
( V_2 ? V_43 : 0 ) | V_44 ;
if ( V_6 ) {
V_16 -> V_36 |= F_25 ( V_7 >> 2 ) ;
V_16 -> V_37 |= F_26 ( V_5 >> 2 ) |
F_27 ( V_6 ) ;
}
V_16 -> V_8 = V_8 ;
V_16 -> V_4 = V_4 ;
}
int F_5 ( struct V_1 * V_1 , int V_2 ,
T_2 V_8 , T_1 V_4 , T_1 V_5 ,
int V_6 , T_1 V_7 )
{
struct V_15 V_16 [ 2 ] ;
F_22 ( & V_16 [ 1 ] , V_2 , V_8 , V_4 , V_5 , V_6 ,
V_7 ) ;
return F_7 ( V_1 , V_16 , 0 , 1 ) ;
}
void F_28 ( struct V_1 * V_1 , int V_45 )
{
struct V_19 * V_20 = & V_1 -> V_20 [ V_45 ] ;
struct V_15 * V_16 ;
if ( V_20 -> V_32 <= V_20 -> V_33 ) {
F_29 ( & V_20 -> V_30 ) ;
return;
}
V_20 -> V_33 ++ ;
V_16 = & V_20 -> V_35 [ V_20 -> V_33 ] ;
F_13 ( V_1 , F_19 ( V_45 ) , 0 ) ;
F_13 ( V_1 , F_16 ( V_45 ) , V_16 -> V_8 ) ;
F_13 ( V_1 , F_17 ( V_45 ) , V_16 -> V_4 ) ;
F_13 ( V_1 , F_18 ( V_45 ) , V_16 -> V_36 ) ;
F_13 ( V_1 , F_19 ( V_45 ) , V_16 -> V_37 ) ;
}
void F_30 ( struct V_1 * V_1 )
{
unsigned int V_46 = F_11 ( V_1 , V_47 ) ;
struct V_19 * V_20 ;
int V_48 ;
if ( ! ( V_46 & ( V_49 | V_50 ) ) )
return;
for ( V_48 = 0 ; V_48 < V_27 ; V_48 ++ ) {
V_20 = & V_1 -> V_20 [ V_48 ] ;
V_20 -> error = 1 ;
F_13 ( V_1 , F_19 ( V_48 ) , 0 ) ;
F_29 ( & V_20 -> V_30 ) ;
}
}
void F_31 ( struct V_1 * V_1 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_27 ; V_48 ++ )
F_32 ( V_1 , F_33 ( V_48 ) ) ;
}
static int F_34 ( struct V_1 * V_1 , int V_51 , int V_5 )
{
T_1 * V_52 ;
T_1 * V_53 ;
int V_48 ;
int V_9 = - V_39 ;
int V_54 = F_35 ( V_5 ) ;
V_52 = ( T_1 * ) F_36 ( V_55 , V_54 ) ;
if ( V_52 == NULL )
return - 1 ;
V_53 = ( T_1 * ) F_36 ( V_55 , V_54 ) ;
if ( V_53 == NULL ) {
F_37 ( ( unsigned long ) V_52 , V_54 ) ;
return - 1 ;
}
for ( V_48 = 0 ; V_48 < ( V_5 >> 3 ) ; V_48 ++ )
* ( V_52 + V_48 ) = ( V_48 << 16 ) | ( V_48 + 1 ) ;
for ( V_48 = ( V_5 >> 3 ) ; V_48 < ( V_5 >> 2 ) ; V_48 ++ )
* ( V_52 + V_48 ) = ~ ( ( V_48 << 16 ) | ( V_48 + 1 ) ) ;
memset ( V_53 , 0x55 , V_5 ) ;
if ( F_1 ( V_1 , 1 , V_52 , V_51 , V_5 , 0 , 0 ) )
goto V_56;
if ( F_1 ( V_1 , 0 , V_53 , V_51 , V_5 , 0 , 0 ) )
goto V_56;
for ( V_48 = 0 ; V_48 < ( V_5 >> 2 ) ; V_48 ++ ) {
if ( * ( V_52 + V_48 ) != * ( V_53 + V_48 ) )
goto V_56;
}
V_9 = 0 ;
V_56:
F_37 ( ( unsigned long ) V_52 , V_54 ) ;
F_37 ( ( unsigned long ) V_53 , V_54 ) ;
return V_9 ;
}
int F_38 ( struct V_1 * V_1 )
{
struct V_19 * V_20 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_27 ; V_48 ++ ) {
V_20 = & V_1 -> V_20 [ V_48 ] ;
F_39 ( & V_20 -> V_28 ) ;
F_40 ( & V_20 -> V_30 ) ;
F_13 ( V_1 , F_19 ( V_48 ) , 0 ) ;
F_13 ( V_1 , F_12 ( V_48 ) ,
V_57 |
V_58 |
F_41 ( 0 ) |
V_59 ) ;
F_42 ( V_1 , F_33 ( V_48 ) ) ;
}
for ( V_1 -> V_60 = 0 , V_48 = 2 ; V_48 >= 0 ; V_48 -- ) {
F_13 ( V_1 , V_61 ,
F_43 ( 1 ) |
F_44 ( V_48 ) |
V_62 |
V_63 |
F_45 ( 1 ) ) ;
F_13 ( V_1 , V_64 , V_1 -> V_65 |
V_66 ) ;
F_13 ( V_1 , V_64 , V_1 -> V_65 ) ;
switch ( V_48 ) {
case 2 :
if ( F_34 ( V_1 , 0x07ff0000 , 0x00010000 ) ||
F_34 ( V_1 , 0x05ff0000 , 0x00010000 ) )
continue;
break;
case 1 :
if ( F_34 ( V_1 , 0x03ff0000 , 0x00010000 ) )
continue;
break;
default:
if ( F_34 ( V_1 , 0x01ff0000 , 0x00010000 ) )
continue;
}
V_1 -> V_60 = ( 32 << 20 ) << V_48 ;
break;
}
if ( ! V_1 -> V_60 ) {
F_46 ( & V_1 -> V_11 -> V_67 , L_1 ) ;
return - V_39 ;
}
if ( F_47 ( V_1 ) > V_1 -> V_60 ) {
F_46 ( & V_1 -> V_11 -> V_67 ,
L_2 ,
V_1 -> V_60 , F_47 ( V_1 ) ) ;
return - V_39 ;
}
return 0 ;
}
