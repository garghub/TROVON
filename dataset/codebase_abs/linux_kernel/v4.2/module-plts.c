static bool F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return V_3 - ( T_1 ) V_2 -> V_4 < V_2 -> V_5 ;
}
T_1 F_2 ( struct V_1 * V_2 , unsigned long V_6 , T_2 V_7 )
{
struct V_8 * V_9 , * V_10 ;
int V_11 , * V_12 ;
if ( F_1 ( V_2 , V_6 ) ) {
V_9 = ( void * ) V_2 -> V_13 . V_14 -> V_15 ;
V_10 = ( void * ) V_9 + V_2 -> V_13 . V_14 -> V_16 ;
V_12 = & V_2 -> V_13 . V_17 ;
} else {
V_9 = ( void * ) V_2 -> V_13 . V_18 -> V_15 ;
V_10 = ( void * ) V_9 + V_2 -> V_13 . V_18 -> V_16 ;
V_12 = & V_2 -> V_13 . V_19 ;
}
for ( V_11 = * V_12 ; V_9 < V_10 ; V_11 -= V_20 , V_9 ++ ) {
int V_21 ;
if ( ! V_11 ) {
* V_9 = (struct V_8 ) {
{ [ 0 ... V_20 - 1 ] = V_22 , } ,
{ V_7 , }
} ;
++ * V_12 ;
return ( T_1 ) V_9 -> V_23 ;
}
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( ! V_9 -> V_24 [ V_21 ] ) {
V_9 -> V_24 [ V_21 ] = V_7 ;
++ * V_12 ;
}
if ( V_9 -> V_24 [ V_21 ] == V_7 )
return ( T_1 ) & V_9 -> V_23 [ V_21 ] ;
}
}
F_3 () ;
}
static int F_4 ( T_2 V_25 , const T_3 * V_26 , int V_27 ,
T_1 V_28 )
{
T_1 * V_29 , * V_30 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_27 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_31 != V_26 [ V_27 ] . V_31 )
continue;
V_29 = ( T_1 * ) ( V_25 + V_26 [ V_21 ] . V_32 ) ;
V_30 = ( T_1 * ) ( V_25 + V_26 [ V_27 ] . V_32 ) ;
if ( ( ( * V_29 ^ * V_30 ) & V_28 ) == 0 )
return 1 ;
}
return 0 ;
}
static unsigned int F_5 ( T_2 V_25 , const T_3 * V_26 , int V_27 )
{
unsigned int V_33 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_27 ; V_21 ++ )
switch ( F_6 ( V_26 [ V_21 ] . V_31 ) ) {
case V_34 :
case V_35 :
case V_36 :
if ( ! F_4 ( V_25 , V_26 , V_21 ,
F_7 ( 0x00ffffff ) ) )
V_33 ++ ;
break;
#ifdef F_8
case V_37 :
case V_38 :
if ( ! F_4 ( V_25 , V_26 , V_21 ,
F_9 ( 0x07ff2fff ) ) )
V_33 ++ ;
#endif
}
return V_33 ;
}
int F_10 ( T_4 * V_39 , T_5 * V_40 ,
char * V_41 , struct V_1 * V_2 )
{
unsigned long V_42 = 0 , V_43 = 0 ;
T_6 * V_44 , * V_45 = V_40 + V_39 -> V_46 ;
for ( V_44 = V_40 ; V_44 < V_45 ; ++ V_44 )
if ( strcmp ( L_1 , V_41 + V_44 -> V_47 ) == 0 )
V_2 -> V_13 . V_18 = V_44 ;
else if ( strcmp ( L_2 , V_41 + V_44 -> V_47 ) == 0 )
V_2 -> V_13 . V_14 = V_44 ;
if ( ! V_2 -> V_13 . V_18 || ! V_2 -> V_13 . V_14 ) {
F_11 ( L_3 , V_2 -> V_48 ) ;
return - V_49 ;
}
for ( V_44 = V_40 + 1 ; V_44 < V_45 ; ++ V_44 ) {
const T_3 * V_50 = ( void * ) V_39 + V_44 -> V_51 ;
int V_52 = V_44 -> V_16 / sizeof( T_3 ) ;
T_6 * V_53 = V_40 + V_44 -> V_54 ;
if ( V_44 -> V_55 != V_56 )
continue;
if ( strstr ( V_41 + V_44 -> V_47 , L_4 ) )
V_43 += F_5 ( V_53 -> V_15 , V_50 , V_52 ) ;
else
V_42 += F_5 ( V_53 -> V_15 , V_50 , V_52 ) ;
}
V_2 -> V_13 . V_18 -> V_55 = V_57 ;
V_2 -> V_13 . V_18 -> V_58 = V_59 | V_60 ;
V_2 -> V_13 . V_18 -> V_61 = V_62 ;
V_2 -> V_13 . V_18 -> V_16 = F_12 ( V_42 * V_63 ,
sizeof( struct V_8 ) ) ;
V_2 -> V_13 . V_19 = 0 ;
V_2 -> V_13 . V_14 -> V_55 = V_57 ;
V_2 -> V_13 . V_14 -> V_58 = V_59 | V_60 ;
V_2 -> V_13 . V_14 -> V_61 = V_62 ;
V_2 -> V_13 . V_14 -> V_16 = F_12 ( V_43 * V_63 ,
sizeof( struct V_8 ) ) ;
V_2 -> V_13 . V_17 = 0 ;
F_13 ( L_5 , V_64 ,
V_2 -> V_13 . V_18 -> V_16 , V_2 -> V_13 . V_14 -> V_16 ) ;
return 0 ;
}
