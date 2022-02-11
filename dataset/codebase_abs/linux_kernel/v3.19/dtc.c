static int T_1 F_1 ( char * V_1 )
{
static int V_2 = 0 ;
int V_3 ;
int V_4 [ 10 ] ;
F_2 ( V_1 , F_3 ( V_4 ) , V_4 ) ;
if ( V_4 [ 0 ] != 2 )
F_4 ( L_1 ) ;
else if ( V_2 < V_5 ) {
V_6 [ V_2 ] . V_7 = V_4 [ 1 ] ;
V_6 [ V_2 ] . V_8 = V_4 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_9 ; ++ V_3 )
if ( V_10 [ V_3 ] . V_7 == V_4 [ 1 ] ) {
V_10 [ V_3 ] . V_11 = 1 ;
break;
}
++ V_2 ;
}
return 1 ;
}
static int T_1 F_5 ( struct V_12 * V_13 )
{
static int V_14 = 0 , V_15 = 0 ;
struct V_16 * V_17 ;
unsigned int V_18 ;
void T_2 * V_19 ;
int V_20 , V_21 ;
for ( V_21 = 0 ; V_14 < V_5 ; ++ V_14 ) {
V_18 = 0 ;
V_19 = NULL ;
if ( V_6 [ V_14 ] . V_7 ) {
V_18 = V_6 [ V_14 ] . V_7 ;
V_19 = F_6 ( V_18 , 0x2000 ) ;
if ( ! V_19 )
V_18 = 0 ;
} else
for (; ! V_18 && ( V_15 < V_9 ) ; ++ V_15 ) {
#if ( V_22 & V_23 )
F_4 ( V_24 L_2 , V_10 [ V_15 ] . V_7 ) ;
#endif
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_6 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_25 ; ++ V_20 ) {
if ( F_7 ( V_19 + V_26 [ V_20 ] . V_27 , V_26 [ V_20 ] . string , strlen ( V_26 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
#if ( V_22 & V_23 )
F_4 ( V_24 L_3 ) ;
#endif
goto V_28;
}
}
F_8 ( V_19 ) ;
}
#if F_9 ( V_22 ) && ( V_22 & V_23 )
F_4 ( V_24 L_4 , V_18 ) ;
#endif
if ( ! V_18 )
break;
V_28:
V_17 = F_10 ( V_13 , sizeof( struct V_29 ) ) ;
if ( V_17 == NULL )
break;
V_17 -> V_19 = V_18 ;
( (struct V_29 * ) ( V_17 ) -> V_30 ) -> V_19 = V_19 ;
F_11 ( V_17 , 0 ) ;
F_12 ( V_31 , V_32 ) ;
if ( V_6 [ V_14 ] . V_8 != V_33 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_13 ( V_17 , V_34 ) ;
if ( V_17 -> V_8 == 255 )
V_17 -> V_8 = V_35 ;
#ifndef F_14
if ( V_17 -> V_8 != V_35 )
if ( F_15 ( V_17 -> V_8 , V_36 , 0 ,
L_5 , V_17 ) ) {
F_4 ( V_37 L_6 , V_17 -> V_38 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_35 ;
}
if ( V_17 -> V_8 == V_35 ) {
F_4 ( V_39 L_7 , V_17 -> V_38 ) ;
F_4 ( V_39 L_8 , V_17 -> V_38 ) ;
}
#else
if ( V_17 -> V_8 != V_35 )
F_4 ( V_39 L_9 , V_17 -> V_38 ) ;
V_17 -> V_8 = V_35 ;
#endif
#if F_9 ( V_22 ) && ( V_22 & V_23 )
F_4 ( L_10 , V_17 -> V_38 , V_17 -> V_8 ) ;
#endif
++ V_14 ;
++ V_21 ;
}
return V_21 ;
}
static int F_16 ( struct V_40 * V_41 , struct V_42 * V_43 ,
T_3 V_44 , int * V_45 )
{
int V_46 = V_44 ;
V_45 [ 0 ] = 64 ;
V_45 [ 1 ] = 32 ;
V_45 [ 2 ] = V_46 >> 11 ;
return 0 ;
}
static inline int F_17 ( struct V_16 * V_17 , unsigned char * V_47 , int V_48 )
{
unsigned char * V_49 = V_47 ;
int V_3 ;
struct V_29 * V_30 = F_18 ( V_17 ) ;
F_19 () ;
F_20 ( V_17 ) ;
V_3 = 0 ;
F_21 ( V_50 ) ;
F_12 ( V_51 , V_52 | V_53 ) ;
if ( V_17 -> V_8 == V_35 )
F_12 ( V_31 , V_54 ) ;
else
F_12 ( V_31 , V_54 | V_55 ) ;
F_12 ( V_56 , V_48 >> 7 ) ;
F_22 ( 1 ) ;
while ( V_48 > 0 ) {
F_22 ( 2 ) ;
while ( F_21 ( V_31 ) & V_57 )
++ V_3 ;
F_22 ( 3 ) ;
F_23 ( V_49 , V_19 + V_58 , 128 ) ;
V_49 += 128 ;
V_48 -= 128 ;
F_22 ( 7 ) ;
}
F_22 ( 4 ) ;
while ( ! ( F_21 ( V_31 ) & V_59 ) )
++ V_3 ;
F_12 ( V_51 , 0 ) ;
F_22 ( 0 ) ;
F_21 ( V_50 ) ;
if ( V_3 > V_30 -> V_60 )
V_30 -> V_60 = V_3 ;
return ( 0 ) ;
}
static inline int F_24 ( struct V_16 * V_17 , unsigned char * V_61 , int V_48 )
{
int V_3 ;
struct V_29 * V_30 = F_18 ( V_17 ) ;
F_19 () ;
F_20 ( V_17 ) ;
F_21 ( V_50 ) ;
F_12 ( V_51 , V_52 | V_53 ) ;
if ( V_17 -> V_8 == V_35 )
F_12 ( V_31 , 0 ) ;
else
F_12 ( V_31 , V_32 ) ;
F_12 ( V_56 , V_48 >> 7 ) ;
for ( V_3 = 0 ; V_48 > 0 ; ++ V_3 ) {
F_22 ( 5 ) ;
while ( F_21 ( V_31 ) & V_57 )
++ V_3 ;
F_22 ( 3 ) ;
F_25 ( V_19 + V_58 , V_61 , 128 ) ;
V_61 += 128 ;
V_48 -= 128 ;
}
F_22 ( 4 ) ;
while ( ! ( F_21 ( V_31 ) & V_59 ) )
++ V_3 ;
F_22 ( 6 ) ;
while ( ! ( F_21 ( V_62 ) & V_63 ) )
++ V_3 ;
F_22 ( 7 ) ;
F_12 ( V_51 , 0 ) ;
F_22 ( 0 ) ;
if ( V_3 > V_30 -> V_64 )
V_30 -> V_64 = V_3 ;
return ( 0 ) ;
}
static int F_26 ( struct V_16 * V_65 )
{
F_19 () ;
F_20 ( V_65 ) ;
if ( V_65 -> V_8 != V_35 )
F_27 ( V_65 -> V_8 , V_65 ) ;
F_28 ( V_65 ) ;
if ( V_65 -> V_66 && V_65 -> V_67 )
F_29 ( V_65 -> V_66 , V_65 -> V_67 ) ;
F_30 ( V_65 ) ;
F_8 ( V_19 ) ;
return 0 ;
}
