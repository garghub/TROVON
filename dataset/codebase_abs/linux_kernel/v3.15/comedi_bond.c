static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 , V_12 , V_13 ;
unsigned int V_14 , V_15 ;
struct V_16 * * V_17 ;
V_14 = V_7 [ 0 ] ;
V_15 = V_7 [ 1 ] ;
V_13 = F_2 ( V_6 -> V_18 ) ;
V_11 = V_9 -> V_19 - V_13 ;
if ( V_11 > 32 )
V_11 = 32 ;
V_12 = 0 ;
V_17 = V_9 -> V_17 ;
do {
struct V_16 * V_20 = * V_17 ++ ;
if ( V_13 < V_20 -> V_19 ) {
unsigned int V_21 , V_22 , V_23 , V_24 ;
int V_25 ;
V_21 = V_20 -> V_19 - V_13 ;
if ( V_21 > V_11 )
V_21 = V_11 ;
V_22 = ( 1U << V_21 ) - 1 ;
V_23 = ( V_14 >> V_12 ) & V_22 ;
V_24 = ( V_15 >> V_12 ) & V_22 ;
V_25 = F_3 ( V_20 -> V_2 , V_20 -> V_26 ,
V_23 , & V_24 ,
V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
V_7 [ 1 ] &= ~ ( V_22 << V_12 ) ;
V_7 [ 1 ] |= ( V_24 & V_22 ) << V_12 ;
V_13 = 0 ;
V_12 += V_21 ;
V_11 -= V_21 ;
} else {
V_13 -= V_20 -> V_19 ;
}
} while ( V_11 );
return V_6 -> V_27 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_28 = F_2 ( V_6 -> V_18 ) ;
int V_25 ;
struct V_16 * V_20 ;
struct V_16 * * V_17 ;
V_17 = V_9 -> V_17 ;
for ( V_20 = * V_17 ++ ; V_28 >= V_20 -> V_19 ; V_20 = * V_17 ++ )
V_28 -= V_20 -> V_19 ;
switch ( V_7 [ 0 ] ) {
case V_29 :
case V_30 :
V_25 = F_5 ( V_20 -> V_2 , V_20 -> V_26 , V_28 , V_7 [ 0 ] ) ;
break;
case V_31 :
V_25 = F_6 ( V_20 -> V_2 , V_20 -> V_26 , V_28 ,
& V_7 [ 1 ] ) ;
break;
default:
V_25 = - V_32 ;
break;
}
if ( V_25 >= 0 )
V_25 = V_6 -> V_27 ;
return V_25 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_8 ( V_35 , V_36 ) ;
int V_37 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_9 -> V_38 [ 0 ] = 0 ;
for ( V_37 = 0 ; V_37 < V_39 && ( ! V_37 || V_34 -> V_40 [ V_37 ] ) ; ++ V_37 ) {
char V_41 [ sizeof( L_1 ) ] ;
int V_42 = V_34 -> V_40 [ V_37 ] ;
struct V_1 * V_43 ;
int V_44 = - 1 , V_19 ;
struct V_16 * V_20 ;
struct V_16 * * V_17 ;
if ( V_42 < 0 || V_42 >= V_36 ) {
F_9 ( V_2 -> V_45 ,
L_2 , V_42 ) ;
return - V_32 ;
}
if ( V_42 == V_2 -> V_42 ) {
F_9 ( V_2 -> V_45 ,
L_3 ) ;
return - V_32 ;
}
if ( F_10 ( V_42 , V_35 ) ) {
F_9 ( V_2 -> V_45 ,
L_4 , V_42 ) ;
return - V_32 ;
}
snprintf ( V_41 , sizeof( V_41 ) , L_5 , V_42 ) ;
V_41 [ sizeof( V_41 ) - 1 ] = 0 ;
V_43 = F_11 ( V_41 ) ;
if ( ! V_43 ) {
F_9 ( V_2 -> V_45 ,
L_6 , V_42 ) ;
return - V_46 ;
}
while ( ( V_44 = F_12 ( V_43 , V_47 ,
V_44 + 1 ) ) > - 1 ) {
V_19 = F_13 ( V_43 , V_44 ) ;
if ( V_19 <= 0 ) {
F_9 ( V_2 -> V_45 ,
L_7 ,
V_19 , V_42 , V_44 ) ;
return - V_32 ;
}
V_20 = F_14 ( sizeof( * V_20 ) , V_48 ) ;
if ( ! V_20 )
return - V_49 ;
V_20 -> V_2 = V_43 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_26 = V_44 ;
V_20 -> V_19 = V_19 ;
V_9 -> V_19 += V_19 ;
V_17 = F_15 ( V_9 -> V_17 ,
( V_9 -> V_50 + 1 ) * sizeof( * V_17 ) ,
V_48 ) ;
if ( ! V_17 ) {
F_9 ( V_2 -> V_45 ,
L_8 ) ;
F_16 ( V_20 ) ;
return - V_49 ;
}
V_9 -> V_17 = V_17 ;
V_9 -> V_17 [ V_9 -> V_50 ++ ] = V_20 ;
{
char V_51 [ 20 ] ;
int V_52 =
V_53 - strlen ( V_9 -> V_38 ) - 1 ;
snprintf ( V_51 , sizeof( V_51 ) , L_9 ,
V_20 -> V_42 , V_20 -> V_26 ) ;
V_51 [ sizeof( V_51 ) - 1 ] = 0 ;
strncat ( V_9 -> V_38 , V_51 , V_52 ) ;
}
}
}
if ( ! V_9 -> V_19 ) {
F_9 ( V_2 -> V_45 , L_10 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_25 ;
V_9 = F_18 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_49 ;
V_25 = F_7 ( V_2 , V_34 ) ;
if ( V_25 )
return V_25 ;
V_2 -> V_54 = V_9 -> V_38 ;
V_25 = F_19 ( V_2 , 1 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_55 [ 0 ] ;
V_4 -> type = V_47 ;
V_4 -> V_56 = V_57 | V_58 ;
V_4 -> V_59 = V_9 -> V_19 ;
V_4 -> V_60 = 1 ;
V_4 -> V_61 = & V_62 ;
V_4 -> V_63 = F_1 ;
V_4 -> V_64 = F_4 ;
F_20 ( V_2 -> V_45 ,
L_11 ,
V_2 -> V_65 -> V_66 , V_2 -> V_54 ,
V_9 -> V_19 , V_9 -> V_50 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 && V_9 -> V_17 ) {
F_8 ( V_67 , V_36 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
while ( V_9 -> V_50 -- ) {
struct V_16 * V_20 ;
V_20 = V_9 -> V_17 [ V_9 -> V_50 ] ;
if ( ! V_20 )
continue;
if ( ! F_10 ( V_20 -> V_42 , V_67 ) )
F_22 ( V_20 -> V_2 ) ;
F_16 ( V_20 ) ;
}
F_16 ( V_9 -> V_17 ) ;
V_9 -> V_17 = NULL ;
}
}
