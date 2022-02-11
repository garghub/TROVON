T_1 F_1 ( struct V_1 * V_2 , const T_2 * V_3 ,
T_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 . V_6 -> V_8 ;
int V_9 = V_2 -> V_7 . V_10 ;
T_1 V_11 = V_4 -> V_12 + V_3 -> V_13 ;
if ( V_3 -> V_13 == 0 && V_4 -> V_14 != 0 ) {
F_2 ( V_4 -> V_14 < ( T_1 ) V_6 || V_4 -> V_14 >= ( T_1 ) & V_6 [ V_9 ] ) ;
return V_4 -> V_14 ;
}
V_2 -> V_7 . V_10 ++ ;
F_2 ( V_2 -> V_7 . V_10 > V_2 -> V_7 . V_15 ) ;
V_6 [ V_9 ] = (struct V_5 ) {
F_3 ( 0x92800010 | ( ( ( ~ V_11 ) & 0xffff ) ) << 5 ) ,
F_3 ( 0xf2a00010 | ( ( ( V_11 >> 16 ) & 0xffff ) ) << 5 ) ,
F_3 ( 0xf2c00010 | ( ( ( V_11 >> 32 ) & 0xffff ) ) << 5 ) ,
F_3 ( 0xd61f0200 )
} ;
if ( V_3 -> V_13 == 0 )
V_4 -> V_14 = ( T_1 ) & V_6 [ V_9 ] ;
return ( T_1 ) & V_6 [ V_9 ] ;
}
static int F_4 ( const void * V_16 , const void * V_17 )
{
const T_2 * V_18 = V_16 , * V_19 = V_17 ;
int V_9 ;
V_9 = F_5 ( F_6 ( V_18 -> V_20 ) , F_6 ( V_19 -> V_20 ) ) ;
if ( V_9 == 0 )
V_9 = F_5 ( F_7 ( V_18 -> V_20 ) , F_7 ( V_19 -> V_20 ) ) ;
if ( V_9 == 0 )
V_9 = F_5 ( V_18 -> V_13 , V_19 -> V_13 ) ;
return V_9 ;
}
static bool F_8 ( const T_2 * V_3 , int V_21 )
{
return V_21 > 0 && F_4 ( V_3 + V_21 , V_3 + V_21 - 1 ) == 0 ;
}
static unsigned int F_9 ( T_3 * V_22 , T_2 * V_3 , int V_21 )
{
unsigned int V_23 = 0 ;
T_3 * V_24 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
switch ( F_6 ( V_3 [ V_9 ] . V_20 ) ) {
case V_25 :
case V_26 :
V_24 = V_22 + F_7 ( V_3 [ V_9 ] . V_20 ) ;
if ( V_24 -> V_27 != V_28 )
break;
if ( V_3 [ V_9 ] . V_13 != 0 || ! F_8 ( V_3 , V_9 ) )
V_23 ++ ;
break;
}
}
return V_23 ;
}
int F_10 ( T_4 * V_29 , T_5 * V_30 ,
char * V_31 , struct V_1 * V_2 )
{
unsigned long V_15 = 0 ;
T_3 * V_22 = NULL ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_29 -> V_32 ; V_9 ++ ) {
if ( strcmp ( L_1 , V_31 + V_30 [ V_9 ] . V_33 ) == 0 )
V_2 -> V_7 . V_6 = V_30 + V_9 ;
else if ( V_30 [ V_9 ] . V_34 == V_35 )
V_22 = ( T_3 * ) V_30 [ V_9 ] . V_8 ;
}
if ( ! V_2 -> V_7 . V_6 ) {
F_11 ( L_2 , V_2 -> V_36 ) ;
return - V_37 ;
}
if ( ! V_22 ) {
F_11 ( L_3 , V_2 -> V_36 ) ;
return - V_37 ;
}
for ( V_9 = 0 ; V_9 < V_29 -> V_32 ; V_9 ++ ) {
T_2 * V_38 = ( void * ) V_29 + V_30 [ V_9 ] . V_39 ;
int V_40 = V_30 [ V_9 ] . V_41 / sizeof( T_2 ) ;
T_6 * V_42 = V_30 + V_30 [ V_9 ] . V_43 ;
if ( V_30 [ V_9 ] . V_34 != V_44 )
continue;
if ( ! ( V_42 -> V_45 & V_46 ) )
continue;
F_12 ( V_38 , V_40 , sizeof( T_2 ) , F_4 , NULL ) ;
V_15 += F_9 ( V_22 , V_38 , V_40 ) ;
}
V_2 -> V_7 . V_6 -> V_34 = V_47 ;
V_2 -> V_7 . V_6 -> V_45 = V_46 | V_48 ;
V_2 -> V_7 . V_6 -> V_49 = V_50 ;
V_2 -> V_7 . V_6 -> V_41 = V_15 * sizeof( struct V_5 ) ;
V_2 -> V_7 . V_10 = 0 ;
V_2 -> V_7 . V_15 = V_15 ;
return 0 ;
}
