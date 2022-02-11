static int T_1 F_1 ( char * V_1 )
{
static int V_2 ;
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
static int V_14 , V_15 ;
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
F_7 ( V_22 , L_2 ,
( unsigned int ) V_10 [ V_15 ] . V_7 ) ;
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_6 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_23 ; ++ V_20 ) {
if ( F_8 ( V_19 + V_24 [ V_20 ] . V_25 , V_24 [ V_20 ] . string , strlen ( V_24 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
F_7 ( V_22 , L_3 ) ;
goto V_26;
}
}
F_9 ( V_19 ) ;
}
F_7 ( V_22 , L_4 , V_18 ) ;
if ( ! V_18 )
break;
V_26:
V_17 = F_10 ( V_13 , sizeof( struct V_27 ) ) ;
if ( V_17 == NULL )
goto V_28;
V_17 -> V_19 = V_18 ;
( (struct V_27 * ) ( V_17 ) -> V_29 ) -> V_19 = V_19 ;
if ( F_11 ( V_17 , V_30 ) )
goto V_31;
F_12 ( V_17 ) ;
F_13 ( V_32 , V_33 ) ;
if ( V_6 [ V_14 ] . V_8 != V_34 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_14 ( V_17 , V_35 ) ;
if ( V_17 -> V_8 == 255 )
V_17 -> V_8 = V_36 ;
#ifndef F_15
if ( V_17 -> V_8 != V_36 )
if ( F_16 ( V_17 -> V_8 , V_37 , 0 ,
L_5 , V_17 ) ) {
F_4 ( V_38 L_6 , V_17 -> V_39 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_36 ;
}
if ( V_17 -> V_8 == V_36 ) {
F_4 ( V_40 L_7 , V_17 -> V_39 ) ;
F_4 ( V_40 L_8 , V_17 -> V_39 ) ;
}
#else
if ( V_17 -> V_8 != V_36 )
F_4 ( V_40 L_9 , V_17 -> V_39 ) ;
V_17 -> V_8 = V_36 ;
#endif
F_7 ( V_22 , L_10 ,
V_17 -> V_39 , V_17 -> V_8 ) ;
++ V_14 ;
++ V_21 ;
}
return V_21 ;
V_31:
F_17 ( V_17 ) ;
V_28:
F_9 ( V_19 ) ;
return V_21 ;
}
static int F_18 ( struct V_41 * V_42 , struct V_43 * V_44 ,
T_3 V_45 , int * V_46 )
{
int V_47 = V_45 ;
V_46 [ 0 ] = 64 ;
V_46 [ 1 ] = 32 ;
V_46 [ 2 ] = V_47 >> 11 ;
return 0 ;
}
static inline int F_19 ( struct V_16 * V_17 , unsigned char * V_48 , int V_49 )
{
unsigned char * V_50 = V_48 ;
int V_3 ;
struct V_27 * V_29 = F_20 ( V_17 ) ;
V_3 = 0 ;
if ( V_17 -> V_8 == V_36 )
F_13 ( V_32 , V_51 ) ;
else
F_13 ( V_32 , V_51 | V_52 ) ;
F_13 ( V_53 , V_49 >> 7 ) ;
F_21 ( 1 ) ;
while ( V_49 > 0 ) {
F_21 ( 2 ) ;
while ( F_22 ( V_32 ) & V_54 )
++ V_3 ;
F_21 ( 3 ) ;
F_23 ( V_50 , V_29 -> V_19 + V_55 , 128 ) ;
V_50 += 128 ;
V_49 -= 128 ;
F_21 ( 7 ) ;
}
F_21 ( 4 ) ;
while ( ! ( F_22 ( V_32 ) & V_56 ) )
++ V_3 ;
F_21 ( 0 ) ;
if ( V_3 > V_29 -> V_57 )
V_29 -> V_57 = V_3 ;
return ( 0 ) ;
}
static inline int F_24 ( struct V_16 * V_17 , unsigned char * V_58 , int V_49 )
{
int V_3 ;
struct V_27 * V_29 = F_20 ( V_17 ) ;
if ( V_17 -> V_8 == V_36 )
F_13 ( V_32 , 0 ) ;
else
F_13 ( V_32 , V_33 ) ;
F_13 ( V_53 , V_49 >> 7 ) ;
for ( V_3 = 0 ; V_49 > 0 ; ++ V_3 ) {
F_21 ( 5 ) ;
while ( F_22 ( V_32 ) & V_54 )
++ V_3 ;
F_21 ( 3 ) ;
F_25 ( V_29 -> V_19 + V_55 , V_58 , 128 ) ;
V_58 += 128 ;
V_49 -= 128 ;
}
F_21 ( 4 ) ;
while ( ! ( F_22 ( V_32 ) & V_56 ) )
++ V_3 ;
F_21 ( 6 ) ;
while ( ! ( F_22 ( V_59 ) & V_60 ) )
++ V_3 ;
F_21 ( 7 ) ;
F_21 ( 0 ) ;
if ( V_3 > V_29 -> V_61 )
V_29 -> V_61 = V_3 ;
return ( 0 ) ;
}
static int F_26 ( struct V_62 * V_63 )
{
int V_64 = V_63 -> V_64 ;
if ( V_64 > 32 * 1024 && V_63 -> V_65 . V_66 &&
! ( V_63 -> V_65 . V_66 % V_64 ) )
V_64 = 32 * 1024 ;
return V_64 ;
}
static int F_27 ( struct V_16 * V_67 )
{
struct V_27 * V_29 = F_20 ( V_67 ) ;
if ( V_67 -> V_8 != V_36 )
F_28 ( V_67 -> V_8 , V_67 ) ;
F_29 ( V_67 ) ;
F_17 ( V_67 ) ;
F_9 ( V_29 -> V_19 ) ;
return 0 ;
}
