static bool F_1 ( const struct V_1 * V_2 , void * V_3 )
{
return ( V_4 ) V_3 - ( V_4 ) V_2 -> V_5 . V_6 < V_2 -> V_5 . V_7 ;
}
V_4 F_2 ( struct V_1 * V_2 , void * V_3 , const T_1 * V_8 ,
T_2 * V_9 )
{
struct V_10 * V_11 = ! F_1 ( V_2 , V_3 ) ? & V_2 -> V_12 . V_13 :
& V_2 -> V_12 . V_14 ;
struct V_15 * V_16 = (struct V_15 * ) V_11 -> V_16 -> V_17 ;
int V_18 = V_11 -> V_19 ;
V_4 V_20 = V_9 -> V_21 + V_8 -> V_22 ;
V_16 [ V_18 ] = (struct V_15 ) {
F_3 ( 0x92800010 | ( ( ( ~ V_20 ) & 0xffff ) ) << 5 ) ,
F_3 ( 0xf2a00010 | ( ( ( V_20 >> 16 ) & 0xffff ) ) << 5 ) ,
F_3 ( 0xf2c00010 | ( ( ( V_20 >> 32 ) & 0xffff ) ) << 5 ) ,
F_3 ( 0xd61f0200 )
} ;
if ( V_18 > 0 &&
V_16 [ V_18 ] . V_23 == V_16 [ V_18 - 1 ] . V_23 &&
V_16 [ V_18 ] . V_24 == V_16 [ V_18 - 1 ] . V_24 &&
V_16 [ V_18 ] . V_25 == V_16 [ V_18 - 1 ] . V_25 )
return ( V_4 ) & V_16 [ V_18 - 1 ] ;
V_11 -> V_19 ++ ;
F_4 ( V_11 -> V_19 > V_11 -> V_26 ) ;
return ( V_4 ) & V_16 [ V_18 ] ;
}
static int F_5 ( const void * V_27 , const void * V_28 )
{
const T_1 * V_29 = V_27 , * V_30 = V_28 ;
int V_18 ;
V_18 = F_6 ( F_7 ( V_29 -> V_31 ) , F_7 ( V_30 -> V_31 ) ) ;
if ( V_18 == 0 )
V_18 = F_6 ( F_8 ( V_29 -> V_31 ) , F_8 ( V_30 -> V_31 ) ) ;
if ( V_18 == 0 )
V_18 = F_6 ( V_29 -> V_22 , V_30 -> V_22 ) ;
return V_18 ;
}
static bool F_9 ( const T_1 * V_8 , int V_32 )
{
return V_32 > 0 && F_5 ( V_8 + V_32 , V_8 + V_32 - 1 ) == 0 ;
}
static unsigned int F_10 ( T_2 * V_33 , T_1 * V_8 , int V_32 ,
T_3 V_34 )
{
unsigned int V_35 = 0 ;
T_2 * V_36 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ ) {
switch ( F_7 ( V_8 [ V_18 ] . V_31 ) ) {
case V_37 :
case V_38 :
V_36 = V_33 + F_8 ( V_8 [ V_18 ] . V_31 ) ;
if ( V_36 -> V_39 == V_34 )
break;
if ( V_8 [ V_18 ] . V_22 != 0 || ! F_9 ( V_8 , V_18 ) )
V_35 ++ ;
break;
}
}
return V_35 ;
}
int F_11 ( T_4 * V_40 , T_5 * V_41 ,
char * V_42 , struct V_1 * V_2 )
{
unsigned long V_43 = 0 ;
unsigned long V_44 = 0 ;
T_2 * V_33 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_40 -> V_45 ; V_18 ++ ) {
if ( ! strcmp ( V_42 + V_41 [ V_18 ] . V_46 , L_1 ) )
V_2 -> V_12 . V_13 . V_16 = V_41 + V_18 ;
else if ( ! strcmp ( V_42 + V_41 [ V_18 ] . V_46 , L_2 ) )
V_2 -> V_12 . V_14 . V_16 = V_41 + V_18 ;
else if ( V_41 [ V_18 ] . V_47 == V_48 )
V_33 = ( T_2 * ) V_41 [ V_18 ] . V_17 ;
}
if ( ! V_2 -> V_12 . V_13 . V_16 || ! V_2 -> V_12 . V_14 . V_16 ) {
F_12 ( L_3 , V_2 -> V_49 ) ;
return - V_50 ;
}
if ( ! V_33 ) {
F_12 ( L_4 , V_2 -> V_49 ) ;
return - V_50 ;
}
for ( V_18 = 0 ; V_18 < V_40 -> V_45 ; V_18 ++ ) {
T_1 * V_51 = ( void * ) V_40 + V_41 [ V_18 ] . V_52 ;
int V_53 = V_41 [ V_18 ] . V_54 / sizeof( T_1 ) ;
T_6 * V_55 = V_41 + V_41 [ V_18 ] . V_56 ;
if ( V_41 [ V_18 ] . V_47 != V_57 )
continue;
if ( ! ( V_55 -> V_58 & V_59 ) )
continue;
F_13 ( V_51 , V_53 , sizeof( T_1 ) , F_5 , NULL ) ;
if ( strncmp ( V_42 + V_55 -> V_46 , L_5 , 5 ) != 0 )
V_43 += F_10 ( V_33 , V_51 , V_53 ,
V_41 [ V_18 ] . V_56 ) ;
else
V_44 += F_10 ( V_33 , V_51 , V_53 ,
V_41 [ V_18 ] . V_56 ) ;
}
V_2 -> V_12 . V_13 . V_16 -> V_47 = V_60 ;
V_2 -> V_12 . V_13 . V_16 -> V_58 = V_59 | V_61 ;
V_2 -> V_12 . V_13 . V_16 -> V_62 = V_63 ;
V_2 -> V_12 . V_13 . V_16 -> V_54 = ( V_43 + 1 ) * sizeof( struct V_15 ) ;
V_2 -> V_12 . V_13 . V_19 = 0 ;
V_2 -> V_12 . V_13 . V_26 = V_43 ;
V_2 -> V_12 . V_14 . V_16 -> V_47 = V_60 ;
V_2 -> V_12 . V_14 . V_16 -> V_58 = V_59 | V_61 ;
V_2 -> V_12 . V_14 . V_16 -> V_62 = V_63 ;
V_2 -> V_12 . V_14 . V_16 -> V_54 = ( V_44 + 1 ) * sizeof( struct V_15 ) ;
V_2 -> V_12 . V_14 . V_19 = 0 ;
V_2 -> V_12 . V_14 . V_26 = V_44 ;
return 0 ;
}
