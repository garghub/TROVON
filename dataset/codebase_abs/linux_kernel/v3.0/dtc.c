static void T_1 F_1 ( char * V_1 , int * V_2 )
{
static int V_3 = 0 ;
int V_4 ;
if ( V_2 [ 0 ] != 2 )
F_2 ( L_1 ) ;
else if ( V_3 < V_5 ) {
V_6 [ V_3 ] . V_7 = V_2 [ 1 ] ;
V_6 [ V_3 ] . V_8 = V_2 [ 2 ] ;
for ( V_4 = 0 ; V_4 < V_9 ; ++ V_4 )
if ( V_10 [ V_4 ] . V_7 == V_2 [ 1 ] ) {
V_10 [ V_4 ] . V_11 = 1 ;
break;
}
++ V_3 ;
}
}
static int T_1 F_3 ( struct V_12 * V_13 )
{
static int V_14 = 0 , V_15 = 0 ;
struct V_16 * V_17 ;
unsigned int V_18 ;
void T_2 * V_19 ;
int V_20 , V_21 ;
V_13 -> V_22 = L_2 ;
V_13 -> V_23 = & V_24 ;
for ( V_21 = 0 ; V_14 < V_5 ; ++ V_14 ) {
V_18 = 0 ;
V_19 = NULL ;
if ( V_6 [ V_14 ] . V_7 ) {
V_18 = V_6 [ V_14 ] . V_7 ;
V_19 = F_4 ( V_18 , 0x2000 ) ;
if ( ! V_19 )
V_18 = 0 ;
} else
for (; ! V_18 && ( V_15 < V_9 ) ; ++ V_15 ) {
#if ( V_25 & V_26 )
F_2 ( V_27 L_3 , V_10 [ V_15 ] . V_7 ) ;
#endif
if ( V_10 [ V_15 ] . V_11 )
continue;
V_19 = F_4 ( V_10 [ V_15 ] . V_7 , 0x2000 ) ;
if ( ! V_19 )
continue;
for ( V_20 = 0 ; V_20 < V_28 ; ++ V_20 ) {
if ( F_5 ( V_19 + V_29 [ V_20 ] . V_30 , V_29 [ V_20 ] . string , strlen ( V_29 [ V_20 ] . string ) ) ) {
V_18 = V_10 [ V_15 ] . V_7 ;
#if ( V_25 & V_26 )
F_2 ( V_27 L_4 ) ;
#endif
goto V_31;
}
}
F_6 ( V_19 ) ;
}
#if F_7 ( V_25 ) && ( V_25 & V_26 )
F_2 ( V_27 L_5 , V_18 ) ;
#endif
if ( ! V_18 )
break;
V_31:
V_17 = F_8 ( V_13 , sizeof( struct V_32 ) ) ;
if ( V_17 == NULL )
break;
V_17 -> V_19 = V_18 ;
( (struct V_32 * ) ( V_17 ) -> V_33 ) -> V_19 = V_19 ;
F_9 ( V_17 , 0 ) ;
F_10 ( V_34 , V_35 ) ;
if ( V_6 [ V_14 ] . V_8 != V_36 )
V_17 -> V_8 = V_6 [ V_14 ] . V_8 ;
else
V_17 -> V_8 = F_11 ( V_17 , V_37 ) ;
#ifndef F_12
if ( V_17 -> V_8 != V_38 )
if ( F_13 ( V_17 -> V_8 , V_39 , V_40 ,
L_6 , V_17 ) ) {
F_2 ( V_41 L_7 , V_17 -> V_42 , V_17 -> V_8 ) ;
V_17 -> V_8 = V_38 ;
}
if ( V_17 -> V_8 == V_38 ) {
F_2 ( V_43 L_8 , V_17 -> V_42 ) ;
F_2 ( V_43 L_9 , V_17 -> V_42 ) ;
}
#else
if ( V_17 -> V_8 != V_38 )
F_2 ( V_43 L_10 , V_17 -> V_42 ) ;
V_17 -> V_8 = V_38 ;
#endif
#if F_7 ( V_25 ) && ( V_25 & V_26 )
F_2 ( L_11 , V_17 -> V_42 , V_17 -> V_8 ) ;
#endif
F_2 ( V_44 L_12 , V_17 -> V_42 , ( int ) V_17 -> V_19 ) ;
if ( V_17 -> V_8 == V_38 )
F_2 ( L_13 ) ;
else
F_2 ( L_14 , V_17 -> V_8 ) ;
F_2 ( L_15 , V_45 , V_46 , V_47 ) ;
F_14 ( V_17 ) ;
F_2 ( L_16 ) ;
++ V_14 ;
++ V_21 ;
}
return V_21 ;
}
static int F_15 ( struct V_48 * V_49 , struct V_50 * V_51 ,
T_3 V_52 , int * V_53 )
{
int V_54 = V_52 ;
V_53 [ 0 ] = 64 ;
V_53 [ 1 ] = 32 ;
V_53 [ 2 ] = V_54 >> 11 ;
return 0 ;
}
static inline int F_16 ( struct V_16 * V_17 , unsigned char * V_55 , int V_56 )
{
unsigned char * V_57 = V_55 ;
int V_4 ;
F_17 () ;
F_18 ( V_17 ) ;
V_4 = 0 ;
F_19 ( V_58 ) ;
F_10 ( V_59 , V_60 | V_61 ) ;
if ( V_17 -> V_8 == V_38 )
F_10 ( V_34 , V_62 ) ;
else
F_10 ( V_34 , V_62 | V_63 ) ;
F_10 ( V_64 , V_56 >> 7 ) ;
F_20 ( 1 ) ;
while ( V_56 > 0 ) {
F_20 ( 2 ) ;
while ( F_19 ( V_34 ) & V_65 )
++ V_4 ;
F_20 ( 3 ) ;
F_21 ( V_57 , V_19 + V_66 , 128 ) ;
V_57 += 128 ;
V_56 -= 128 ;
F_20 ( 7 ) ;
}
F_20 ( 4 ) ;
while ( ! ( F_19 ( V_34 ) & V_67 ) )
++ V_4 ;
F_10 ( V_59 , 0 ) ;
F_20 ( 0 ) ;
F_19 ( V_58 ) ;
if ( V_4 > V_68 )
V_68 = V_4 ;
return ( 0 ) ;
}
static inline int F_22 ( struct V_16 * V_17 , unsigned char * V_69 , int V_56 )
{
int V_4 ;
F_17 () ;
F_18 ( V_17 ) ;
F_19 ( V_58 ) ;
F_10 ( V_59 , V_60 | V_61 ) ;
if ( V_17 -> V_8 == V_38 )
F_10 ( V_34 , 0 ) ;
else
F_10 ( V_34 , V_35 ) ;
F_10 ( V_64 , V_56 >> 7 ) ;
for ( V_4 = 0 ; V_56 > 0 ; ++ V_4 ) {
F_20 ( 5 ) ;
while ( F_19 ( V_34 ) & V_65 )
++ V_4 ;
F_20 ( 3 ) ;
F_23 ( V_19 + V_66 , V_69 , 128 ) ;
V_69 += 128 ;
V_56 -= 128 ;
}
F_20 ( 4 ) ;
while ( ! ( F_19 ( V_34 ) & V_67 ) )
++ V_4 ;
F_20 ( 6 ) ;
while ( ! ( F_19 ( V_70 ) & V_71 ) )
++ V_4 ;
F_20 ( 7 ) ;
F_10 ( V_59 , 0 ) ;
F_20 ( 0 ) ;
if ( V_4 > V_72 )
V_72 = V_4 ;
return ( 0 ) ;
}
static int F_24 ( struct V_16 * V_73 )
{
F_17 () ;
F_18 ( V_73 ) ;
if ( V_73 -> V_8 )
F_25 ( V_73 -> V_8 , V_73 ) ;
F_26 ( V_73 ) ;
if ( V_73 -> V_74 && V_73 -> V_75 )
F_27 ( V_73 -> V_74 , V_73 -> V_75 ) ;
F_28 ( V_73 ) ;
F_6 ( V_19 ) ;
return 0 ;
}
