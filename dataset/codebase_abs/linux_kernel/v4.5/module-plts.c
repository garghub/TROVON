static bool F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return V_3 - ( T_1 ) V_2 -> V_4 . V_5 < V_2 -> V_4 . V_6 ;
}
T_1 F_2 ( struct V_1 * V_2 , unsigned long V_7 , T_2 V_8 )
{
struct V_9 * V_10 , * V_11 ;
int V_12 , * V_13 ;
if ( F_1 ( V_2 , V_7 ) ) {
V_10 = ( void * ) V_2 -> V_14 . V_15 -> V_16 ;
V_11 = ( void * ) V_10 + V_2 -> V_14 . V_15 -> V_17 ;
V_13 = & V_2 -> V_14 . V_18 ;
} else {
V_10 = ( void * ) V_2 -> V_14 . V_19 -> V_16 ;
V_11 = ( void * ) V_10 + V_2 -> V_14 . V_19 -> V_17 ;
V_13 = & V_2 -> V_14 . V_20 ;
}
for ( V_12 = * V_13 ; V_10 < V_11 ; V_12 -= V_21 , V_10 ++ ) {
int V_22 ;
if ( ! V_12 ) {
* V_10 = (struct V_9 ) {
{ [ 0 ... V_21 - 1 ] = V_23 , } ,
{ V_8 , }
} ;
++ * V_13 ;
return ( T_1 ) V_10 -> V_24 ;
}
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
if ( ! V_10 -> V_25 [ V_22 ] ) {
V_10 -> V_25 [ V_22 ] = V_8 ;
++ * V_13 ;
}
if ( V_10 -> V_25 [ V_22 ] == V_8 )
return ( T_1 ) & V_10 -> V_24 [ V_22 ] ;
}
}
F_3 () ;
}
static int F_4 ( T_2 V_5 , const T_3 * V_26 , int V_27 ,
T_1 V_28 )
{
T_1 * V_29 , * V_30 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ ) {
if ( V_26 [ V_22 ] . V_31 != V_26 [ V_27 ] . V_31 )
continue;
V_29 = ( T_1 * ) ( V_5 + V_26 [ V_22 ] . V_32 ) ;
V_30 = ( T_1 * ) ( V_5 + V_26 [ V_27 ] . V_32 ) ;
if ( ( ( * V_29 ^ * V_30 ) & V_28 ) == 0 )
return 1 ;
}
return 0 ;
}
static unsigned int F_5 ( T_2 V_5 , const T_3 * V_26 , int V_27 )
{
unsigned int V_33 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
switch ( F_6 ( V_26 [ V_22 ] . V_31 ) ) {
case V_34 :
case V_35 :
case V_36 :
if ( ! F_4 ( V_5 , V_26 , V_22 ,
F_7 ( 0x00ffffff ) ) )
V_33 ++ ;
break;
#ifdef F_8
case V_37 :
case V_38 :
if ( ! F_4 ( V_5 , V_26 , V_22 ,
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
V_2 -> V_14 . V_19 = V_44 ;
else if ( strcmp ( L_2 , V_41 + V_44 -> V_47 ) == 0 )
V_2 -> V_14 . V_15 = V_44 ;
if ( ! V_2 -> V_14 . V_19 || ! V_2 -> V_14 . V_15 ) {
F_11 ( L_3 , V_2 -> V_48 ) ;
return - V_49 ;
}
for ( V_44 = V_40 + 1 ; V_44 < V_45 ; ++ V_44 ) {
const T_3 * V_50 = ( void * ) V_39 + V_44 -> V_51 ;
int V_52 = V_44 -> V_17 / sizeof( T_3 ) ;
T_6 * V_53 = V_40 + V_44 -> V_54 ;
if ( V_44 -> V_55 != V_56 )
continue;
if ( strstr ( V_41 + V_44 -> V_47 , L_4 ) )
V_43 += F_5 ( V_53 -> V_16 , V_50 , V_52 ) ;
else
V_42 += F_5 ( V_53 -> V_16 , V_50 , V_52 ) ;
}
V_2 -> V_14 . V_19 -> V_55 = V_57 ;
V_2 -> V_14 . V_19 -> V_58 = V_59 | V_60 ;
V_2 -> V_14 . V_19 -> V_61 = V_62 ;
V_2 -> V_14 . V_19 -> V_17 = F_12 ( V_42 * V_63 ,
sizeof( struct V_9 ) ) ;
V_2 -> V_14 . V_20 = 0 ;
V_2 -> V_14 . V_15 -> V_55 = V_57 ;
V_2 -> V_14 . V_15 -> V_58 = V_59 | V_60 ;
V_2 -> V_14 . V_15 -> V_61 = V_62 ;
V_2 -> V_14 . V_15 -> V_17 = F_12 ( V_43 * V_63 ,
sizeof( struct V_9 ) ) ;
V_2 -> V_14 . V_18 = 0 ;
F_13 ( L_5 , V_64 ,
V_2 -> V_14 . V_19 -> V_17 , V_2 -> V_14 . V_15 -> V_17 ) ;
return 0 ;
}
