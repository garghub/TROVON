static void F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 V_3 , const T_1 V_4 )
{
register T_1 V_5 , V_6 , V_7 ;
T_1 V_8 [ 4 ] , V_9 = V_3 >> 7 ;
register T_1 V_10 , V_11 ;
V_10 = V_3 & ( 0x7F ) ; V_11 = V_10 << 1 ;
V_8 [ 0 ] = 0 ; V_8 [ 1 ] = V_10 ; V_8 [ 2 ] = V_11 ; V_8 [ 3 ] = V_10 ^ V_11 ;
V_7 = V_8 [ V_4 & 0x3 ] ; V_6 = V_7 ;
V_7 = V_8 [ V_4 >> 2 & 0x3 ] ; V_6 ^= V_7 << 2 ; V_5 = V_7 >> 6 ;
V_7 = V_8 [ V_4 >> 4 & 0x3 ] ; V_6 ^= V_7 << 4 ; V_5 ^= V_7 >> 4 ;
V_7 = V_8 [ V_4 >> 6 ] ; V_6 ^= V_7 << 6 ; V_5 ^= V_7 >> 2 ;
if ( V_9 & 01 ) { V_6 ^= V_4 << 7 ; V_5 ^= V_4 >> 1 ; }
* V_1 = V_5 ; * V_2 = V_6 ;
}
static void F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 V_3 , const T_1 V_4 )
{
register T_1 V_5 , V_6 , V_7 ;
T_1 V_8 [ 4 ] , V_9 = V_3 >> 15 ;
register T_1 V_10 , V_11 ;
V_10 = V_3 & ( 0x7FFF ) ; V_11 = V_10 << 1 ;
V_8 [ 0 ] = 0 ; V_8 [ 1 ] = V_10 ; V_8 [ 2 ] = V_11 ; V_8 [ 3 ] = V_10 ^ V_11 ;
V_7 = V_8 [ V_4 & 0x3 ] ; V_6 = V_7 ;
V_7 = V_8 [ V_4 >> 2 & 0x3 ] ; V_6 ^= V_7 << 2 ; V_5 = V_7 >> 14 ;
V_7 = V_8 [ V_4 >> 4 & 0x3 ] ; V_6 ^= V_7 << 4 ; V_5 ^= V_7 >> 12 ;
V_7 = V_8 [ V_4 >> 6 & 0x3 ] ; V_6 ^= V_7 << 6 ; V_5 ^= V_7 >> 10 ;
V_7 = V_8 [ V_4 >> 8 & 0x3 ] ; V_6 ^= V_7 << 8 ; V_5 ^= V_7 >> 8 ;
V_7 = V_8 [ V_4 >> 10 & 0x3 ] ; V_6 ^= V_7 << 10 ; V_5 ^= V_7 >> 6 ;
V_7 = V_8 [ V_4 >> 12 & 0x3 ] ; V_6 ^= V_7 << 12 ; V_5 ^= V_7 >> 4 ;
V_7 = V_8 [ V_4 >> 14 ] ; V_6 ^= V_7 << 14 ; V_5 ^= V_7 >> 2 ;
if ( V_9 & 01 ) { V_6 ^= V_4 << 15 ; V_5 ^= V_4 >> 1 ; }
* V_1 = V_5 ; * V_2 = V_6 ;
}
static void F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 V_3 , const T_1 V_4 )
{
register T_1 V_5 , V_6 , V_7 ;
T_1 V_8 [ 8 ] , V_12 = V_3 >> 30 ;
register T_1 V_10 , V_11 , V_13 ;
V_10 = V_3 & ( 0x3FFFFFFF ) ; V_11 = V_10 << 1 ; V_13 = V_11 << 1 ;
V_8 [ 0 ] = 0 ; V_8 [ 1 ] = V_10 ; V_8 [ 2 ] = V_11 ; V_8 [ 3 ] = V_10 ^ V_11 ;
V_8 [ 4 ] = V_13 ; V_8 [ 5 ] = V_10 ^ V_13 ; V_8 [ 6 ] = V_11 ^ V_13 ; V_8 [ 7 ] = V_10 ^ V_11 ^ V_13 ;
V_7 = V_8 [ V_4 & 0x7 ] ; V_6 = V_7 ;
V_7 = V_8 [ V_4 >> 3 & 0x7 ] ; V_6 ^= V_7 << 3 ; V_5 = V_7 >> 29 ;
V_7 = V_8 [ V_4 >> 6 & 0x7 ] ; V_6 ^= V_7 << 6 ; V_5 ^= V_7 >> 26 ;
V_7 = V_8 [ V_4 >> 9 & 0x7 ] ; V_6 ^= V_7 << 9 ; V_5 ^= V_7 >> 23 ;
V_7 = V_8 [ V_4 >> 12 & 0x7 ] ; V_6 ^= V_7 << 12 ; V_5 ^= V_7 >> 20 ;
V_7 = V_8 [ V_4 >> 15 & 0x7 ] ; V_6 ^= V_7 << 15 ; V_5 ^= V_7 >> 17 ;
V_7 = V_8 [ V_4 >> 18 & 0x7 ] ; V_6 ^= V_7 << 18 ; V_5 ^= V_7 >> 14 ;
V_7 = V_8 [ V_4 >> 21 & 0x7 ] ; V_6 ^= V_7 << 21 ; V_5 ^= V_7 >> 11 ;
V_7 = V_8 [ V_4 >> 24 & 0x7 ] ; V_6 ^= V_7 << 24 ; V_5 ^= V_7 >> 8 ;
V_7 = V_8 [ V_4 >> 27 & 0x7 ] ; V_6 ^= V_7 << 27 ; V_5 ^= V_7 >> 5 ;
V_7 = V_8 [ V_4 >> 30 ] ; V_6 ^= V_7 << 30 ; V_5 ^= V_7 >> 2 ;
if ( V_12 & 01 ) { V_6 ^= V_4 << 30 ; V_5 ^= V_4 >> 2 ; }
if ( V_12 & 02 ) { V_6 ^= V_4 << 31 ; V_5 ^= V_4 >> 1 ; }
* V_1 = V_5 ; * V_2 = V_6 ;
}
static void F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 V_3 , const T_1 V_4 )
{
register T_1 V_5 , V_6 , V_7 ;
T_1 V_8 [ 16 ] , V_14 = V_3 >> 61 ;
register T_1 V_10 , V_11 , V_13 , V_15 ;
V_10 = V_3 & ( 0x1FFFFFFFFFFFFFFFULL ) ; V_11 = V_10 << 1 ; V_13 = V_11 << 1 ; V_15 = V_13 << 1 ;
V_8 [ 0 ] = 0 ; V_8 [ 1 ] = V_10 ; V_8 [ 2 ] = V_11 ; V_8 [ 3 ] = V_10 ^ V_11 ;
V_8 [ 4 ] = V_13 ; V_8 [ 5 ] = V_10 ^ V_13 ; V_8 [ 6 ] = V_11 ^ V_13 ; V_8 [ 7 ] = V_10 ^ V_11 ^ V_13 ;
V_8 [ 8 ] = V_15 ; V_8 [ 9 ] = V_10 ^ V_15 ; V_8 [ 10 ] = V_11 ^ V_15 ; V_8 [ 11 ] = V_10 ^ V_11 ^ V_15 ;
V_8 [ 12 ] = V_13 ^ V_15 ; V_8 [ 13 ] = V_10 ^ V_13 ^ V_15 ; V_8 [ 14 ] = V_11 ^ V_13 ^ V_15 ; V_8 [ 15 ] = V_10 ^ V_11 ^ V_13 ^ V_15 ;
V_7 = V_8 [ V_4 & 0xF ] ; V_6 = V_7 ;
V_7 = V_8 [ V_4 >> 4 & 0xF ] ; V_6 ^= V_7 << 4 ; V_5 = V_7 >> 60 ;
V_7 = V_8 [ V_4 >> 8 & 0xF ] ; V_6 ^= V_7 << 8 ; V_5 ^= V_7 >> 56 ;
V_7 = V_8 [ V_4 >> 12 & 0xF ] ; V_6 ^= V_7 << 12 ; V_5 ^= V_7 >> 52 ;
V_7 = V_8 [ V_4 >> 16 & 0xF ] ; V_6 ^= V_7 << 16 ; V_5 ^= V_7 >> 48 ;
V_7 = V_8 [ V_4 >> 20 & 0xF ] ; V_6 ^= V_7 << 20 ; V_5 ^= V_7 >> 44 ;
V_7 = V_8 [ V_4 >> 24 & 0xF ] ; V_6 ^= V_7 << 24 ; V_5 ^= V_7 >> 40 ;
V_7 = V_8 [ V_4 >> 28 & 0xF ] ; V_6 ^= V_7 << 28 ; V_5 ^= V_7 >> 36 ;
V_7 = V_8 [ V_4 >> 32 & 0xF ] ; V_6 ^= V_7 << 32 ; V_5 ^= V_7 >> 32 ;
V_7 = V_8 [ V_4 >> 36 & 0xF ] ; V_6 ^= V_7 << 36 ; V_5 ^= V_7 >> 28 ;
V_7 = V_8 [ V_4 >> 40 & 0xF ] ; V_6 ^= V_7 << 40 ; V_5 ^= V_7 >> 24 ;
V_7 = V_8 [ V_4 >> 44 & 0xF ] ; V_6 ^= V_7 << 44 ; V_5 ^= V_7 >> 20 ;
V_7 = V_8 [ V_4 >> 48 & 0xF ] ; V_6 ^= V_7 << 48 ; V_5 ^= V_7 >> 16 ;
V_7 = V_8 [ V_4 >> 52 & 0xF ] ; V_6 ^= V_7 << 52 ; V_5 ^= V_7 >> 12 ;
V_7 = V_8 [ V_4 >> 56 & 0xF ] ; V_6 ^= V_7 << 56 ; V_5 ^= V_7 >> 8 ;
V_7 = V_8 [ V_4 >> 60 ] ; V_6 ^= V_7 << 60 ; V_5 ^= V_7 >> 4 ;
if ( V_14 & 01 ) { V_6 ^= V_4 << 61 ; V_5 ^= V_4 >> 3 ; }
if ( V_14 & 02 ) { V_6 ^= V_4 << 62 ; V_5 ^= V_4 >> 2 ; }
if ( V_14 & 04 ) { V_6 ^= V_4 << 63 ; V_5 ^= V_4 >> 1 ; }
* V_1 = V_5 ; * V_2 = V_6 ;
}
static void F_2 ( T_1 * V_16 , const T_1 V_10 , const T_1 V_17 , const T_1 V_18 , const T_1 V_19 )
{
T_1 V_20 , V_21 ;
F_1 ( V_16 + 3 , V_16 + 2 , V_10 , V_18 ) ;
F_1 ( V_16 + 1 , V_16 , V_17 , V_19 ) ;
F_1 ( & V_20 , & V_21 , V_17 ^ V_10 , V_19 ^ V_18 ) ;
V_16 [ 2 ] ^= V_20 ^ V_16 [ 1 ] ^ V_16 [ 3 ] ;
V_16 [ 1 ] = V_16 [ 3 ] ^ V_16 [ 2 ] ^ V_16 [ 0 ] ^ V_20 ^ V_21 ;
}
int F_3 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_4 )
{
int V_22 ;
const T_2 * V_23 , * V_24 ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
if ( V_3 -> V_25 < V_4 -> V_25 ) { V_23 = V_4 ; V_24 = V_3 ; }
else { V_23 = V_3 ; V_24 = V_4 ; }
F_5 ( V_16 , V_23 -> V_25 ) ;
for ( V_22 = 0 ; V_22 < V_24 -> V_25 ; V_22 ++ )
{
V_16 -> V_26 [ V_22 ] = V_23 -> V_26 [ V_22 ] ^ V_24 -> V_26 [ V_22 ] ;
}
for (; V_22 < V_23 -> V_25 ; V_22 ++ )
{
V_16 -> V_26 [ V_22 ] = V_23 -> V_26 [ V_22 ] ;
}
V_16 -> V_25 = V_23 -> V_25 ;
F_6 ( V_16 ) ;
return 1 ;
}
int F_7 ( T_2 * V_16 , const T_2 * V_3 , const unsigned int V_27 [] )
{
int V_28 , V_29 ;
int V_30 , V_31 , V_32 , V_33 ;
T_1 V_34 , * V_35 ;
F_4 ( V_3 ) ;
if ( ! V_27 [ 0 ] )
{
F_8 ( V_16 ) ;
return 1 ;
}
if ( V_3 != V_16 )
{
if ( ! F_5 ( V_16 , V_3 -> V_25 ) ) return 0 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_25 ; V_28 ++ )
{
V_16 -> V_26 [ V_28 ] = V_3 -> V_26 [ V_28 ] ;
}
V_16 -> V_25 = V_3 -> V_25 ;
}
V_35 = V_16 -> V_26 ;
V_31 = V_27 [ 0 ] / V_36 ;
for ( V_28 = V_16 -> V_25 - 1 ; V_28 > V_31 ; )
{
V_34 = V_35 [ V_28 ] ;
if ( V_35 [ V_28 ] == 0 ) { V_28 -- ; continue; }
V_35 [ V_28 ] = 0 ;
for ( V_29 = 1 ; V_27 [ V_29 ] != 0 ; V_29 ++ )
{
V_30 = V_27 [ 0 ] - V_27 [ V_29 ] ;
V_32 = V_30 % V_36 ; V_33 = V_36 - V_32 ;
V_30 /= V_36 ;
V_35 [ V_28 - V_30 ] ^= ( V_34 >> V_32 ) ;
if ( V_32 ) V_35 [ V_28 - V_30 - 1 ] ^= ( V_34 << V_33 ) ;
}
V_30 = V_31 ;
V_32 = V_27 [ 0 ] % V_36 ;
V_33 = V_36 - V_32 ;
V_35 [ V_28 - V_30 ] ^= ( V_34 >> V_32 ) ;
if ( V_32 ) V_35 [ V_28 - V_30 - 1 ] ^= ( V_34 << V_33 ) ;
}
while ( V_28 == V_31 )
{
V_32 = V_27 [ 0 ] % V_36 ;
V_34 = V_35 [ V_31 ] >> V_32 ;
if ( V_34 == 0 ) break;
V_33 = V_36 - V_32 ;
if ( V_32 ) V_35 [ V_31 ] = ( V_35 [ V_31 ] << V_33 ) >> V_33 ;
V_35 [ 0 ] ^= V_34 ;
for ( V_29 = 1 ; V_27 [ V_29 ] != 0 ; V_29 ++ )
{
T_1 V_37 ;
V_30 = V_27 [ V_29 ] / V_36 ;
V_32 = V_27 [ V_29 ] % V_36 ;
V_33 = V_36 - V_32 ;
V_35 [ V_30 ] ^= ( V_34 << V_32 ) ;
V_37 = V_34 >> V_33 ;
if ( V_32 && V_37 )
V_35 [ V_30 + 1 ] ^= V_37 ;
}
}
F_6 ( V_16 ) ;
return 1 ;
}
int F_9 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_27 )
{
int V_38 = 0 ;
const int V_39 = F_10 ( V_27 ) ;
unsigned int * V_40 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_27 ) ;
if ( ( V_40 = ( unsigned int * ) F_11 ( sizeof( unsigned int ) * V_39 ) ) == NULL ) goto V_41;
V_38 = F_12 ( V_27 , V_40 , V_39 ) ;
if ( ! V_38 || V_38 > V_39 )
{
F_13 ( V_42 , V_43 ) ;
goto V_41;
}
V_38 = F_7 ( V_16 , V_3 , V_40 ) ;
F_4 ( V_16 ) ;
V_41:
if ( V_40 ) F_14 ( V_40 ) ;
return V_38 ;
}
int F_15 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_4 , const unsigned int V_27 [] , T_3 * V_44 )
{
int V_45 , V_22 , V_28 , V_29 , V_38 = 0 ;
T_2 * V_7 ;
T_1 V_46 , V_47 , y1 , y0 , V_34 [ 4 ] ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
if ( V_3 == V_4 )
{
return F_16 ( V_16 , V_3 , V_27 , V_44 ) ;
}
F_17 ( V_44 ) ;
if ( ( V_7 = F_18 ( V_44 ) ) == NULL ) goto V_41;
V_45 = V_3 -> V_25 + V_4 -> V_25 + 4 ;
if ( ! F_5 ( V_7 , V_45 ) ) goto V_41;
V_7 -> V_25 = V_45 ;
for ( V_22 = 0 ; V_22 < V_45 ; V_22 ++ ) V_7 -> V_26 [ V_22 ] = 0 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_25 ; V_28 += 2 )
{
y0 = V_4 -> V_26 [ V_28 ] ;
y1 = ( ( V_28 + 1 ) == V_4 -> V_25 ) ? 0 : V_4 -> V_26 [ V_28 + 1 ] ;
for ( V_22 = 0 ; V_22 < V_3 -> V_25 ; V_22 += 2 )
{
V_47 = V_3 -> V_26 [ V_22 ] ;
V_46 = ( ( V_22 + 1 ) == V_3 -> V_25 ) ? 0 : V_3 -> V_26 [ V_22 + 1 ] ;
F_2 ( V_34 , V_46 , V_47 , y1 , y0 ) ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) V_7 -> V_26 [ V_22 + V_28 + V_29 ] ^= V_34 [ V_29 ] ;
}
}
F_6 ( V_7 ) ;
if ( F_7 ( V_16 , V_7 , V_27 ) )
V_38 = 1 ;
F_4 ( V_16 ) ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_20 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_4 , const T_2 * V_27 , T_3 * V_44 )
{
int V_38 = 0 ;
const int V_39 = F_10 ( V_27 ) ;
unsigned int * V_40 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_4 ( V_27 ) ;
if ( ( V_40 = ( unsigned int * ) F_11 ( sizeof( unsigned int ) * V_39 ) ) == NULL ) goto V_41;
V_38 = F_12 ( V_27 , V_40 , V_39 ) ;
if ( ! V_38 || V_38 > V_39 )
{
F_13 ( V_48 , V_43 ) ;
goto V_41;
}
V_38 = F_15 ( V_16 , V_3 , V_4 , V_40 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
if ( V_40 ) F_14 ( V_40 ) ;
return V_38 ;
}
int F_16 ( T_2 * V_16 , const T_2 * V_3 , const unsigned int V_27 [] , T_3 * V_44 )
{
int V_22 , V_38 = 0 ;
T_2 * V_7 ;
F_4 ( V_3 ) ;
F_17 ( V_44 ) ;
if ( ( V_7 = F_18 ( V_44 ) ) == NULL ) return 0 ;
if ( ! F_5 ( V_7 , 2 * V_3 -> V_25 ) ) goto V_41;
for ( V_22 = V_3 -> V_25 - 1 ; V_22 >= 0 ; V_22 -- )
{
V_7 -> V_26 [ 2 * V_22 + 1 ] = F_21 ( V_3 -> V_26 [ V_22 ] ) ;
V_7 -> V_26 [ 2 * V_22 ] = F_22 ( V_3 -> V_26 [ V_22 ] ) ;
}
V_7 -> V_25 = 2 * V_3 -> V_25 ;
F_6 ( V_7 ) ;
if ( ! F_7 ( V_16 , V_7 , V_27 ) ) goto V_41;
F_4 ( V_16 ) ;
V_38 = 1 ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_23 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_27 , T_3 * V_44 )
{
int V_38 = 0 ;
const int V_39 = F_10 ( V_27 ) ;
unsigned int * V_40 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_27 ) ;
if ( ( V_40 = ( unsigned int * ) F_11 ( sizeof( unsigned int ) * V_39 ) ) == NULL ) goto V_41;
V_38 = F_12 ( V_27 , V_40 , V_39 ) ;
if ( ! V_38 || V_38 > V_39 )
{
F_13 ( V_49 , V_43 ) ;
goto V_41;
}
V_38 = F_16 ( V_16 , V_3 , V_40 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
if ( V_40 ) F_14 ( V_40 ) ;
return V_38 ;
}
int F_24 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_27 , T_3 * V_44 )
{
T_2 * V_4 , * V_50 , * V_51 , * V_52 , * V_53 ;
int V_38 = 0 ;
F_4 ( V_3 ) ;
F_4 ( V_27 ) ;
F_17 ( V_44 ) ;
V_4 = F_18 ( V_44 ) ;
V_50 = F_18 ( V_44 ) ;
V_51 = F_18 ( V_44 ) ;
V_52 = F_18 ( V_44 ) ;
if ( V_52 == NULL ) goto V_41;
if ( ! F_25 ( V_4 ) ) goto V_41;
if ( ! F_9 ( V_51 , V_3 , V_27 ) ) goto V_41;
if ( ! F_26 ( V_52 , V_27 ) ) goto V_41;
if ( F_27 ( V_51 ) ) goto V_41;
while ( 1 )
{
while ( ! F_28 ( V_51 ) )
{
if ( ! F_29 ( V_51 , V_51 ) ) goto V_41;
if ( F_28 ( V_4 ) )
{
if ( ! F_3 ( V_4 , V_4 , V_27 ) ) goto V_41;
}
if ( ! F_29 ( V_4 , V_4 ) ) goto V_41;
}
if ( F_30 ( V_51 , 1 ) ) break;
if ( F_10 ( V_51 ) < F_10 ( V_52 ) )
{
V_53 = V_51 ; V_51 = V_52 ; V_52 = V_53 ;
V_53 = V_4 ; V_4 = V_50 ; V_50 = V_53 ;
}
if ( ! F_3 ( V_51 , V_51 , V_52 ) ) goto V_41;
if ( ! F_3 ( V_4 , V_4 , V_50 ) ) goto V_41;
}
if ( ! F_26 ( V_16 , V_4 ) ) goto V_41;
F_4 ( V_16 ) ;
V_38 = 1 ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_31 ( T_2 * V_16 , const T_2 * V_54 , const unsigned int V_27 [] , T_3 * V_44 )
{
T_2 * V_55 ;
int V_38 = 0 ;
F_4 ( V_54 ) ;
F_17 ( V_44 ) ;
if ( ( V_55 = F_18 ( V_44 ) ) == NULL ) goto V_41;
if ( ! F_32 ( V_27 , V_55 ) ) goto V_41;
V_38 = F_24 ( V_16 , V_54 , V_55 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_33 ( T_2 * V_16 , const T_2 * V_56 , const T_2 * V_57 , const T_2 * V_27 , T_3 * V_44 )
{
T_2 * V_58 = NULL ;
int V_38 = 0 ;
F_4 ( V_56 ) ;
F_4 ( V_57 ) ;
F_4 ( V_27 ) ;
F_17 ( V_44 ) ;
V_58 = F_18 ( V_44 ) ;
if ( V_58 == NULL ) goto V_41;
if ( ! F_24 ( V_58 , V_57 , V_27 , V_44 ) ) goto V_41;
if ( ! F_20 ( V_16 , V_56 , V_58 , V_27 , V_44 ) ) goto V_41;
F_4 ( V_16 ) ;
V_38 = 1 ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_33 ( T_2 * V_16 , const T_2 * V_56 , const T_2 * V_57 , const T_2 * V_27 , T_3 * V_44 )
{
T_2 * V_3 , * V_4 , * V_51 , * V_52 ;
int V_38 = 0 ;
F_4 ( V_56 ) ;
F_4 ( V_57 ) ;
F_4 ( V_27 ) ;
F_17 ( V_44 ) ;
V_3 = F_18 ( V_44 ) ;
V_4 = F_18 ( V_44 ) ;
V_51 = F_18 ( V_44 ) ;
V_52 = F_18 ( V_44 ) ;
if ( V_52 == NULL ) goto V_41;
if ( ! F_9 ( V_51 , V_56 , V_27 ) ) goto V_41;
if ( ! F_9 ( V_3 , V_57 , V_27 ) ) goto V_41;
if ( ! F_26 ( V_4 , V_27 ) ) goto V_41;
while ( ! F_28 ( V_3 ) )
{
if ( ! F_29 ( V_3 , V_3 ) ) goto V_41;
if ( F_28 ( V_51 ) ) if ( ! F_3 ( V_51 , V_51 , V_27 ) ) goto V_41;
if ( ! F_29 ( V_51 , V_51 ) ) goto V_41;
}
do
{
if ( F_34 ( V_4 , V_3 ) > 0 )
{
if ( ! F_3 ( V_4 , V_4 , V_3 ) ) goto V_41;
if ( ! F_3 ( V_52 , V_52 , V_51 ) ) goto V_41;
do
{
if ( ! F_29 ( V_4 , V_4 ) ) goto V_41;
if ( F_28 ( V_52 ) ) if ( ! F_3 ( V_52 , V_52 , V_27 ) ) goto V_41;
if ( ! F_29 ( V_52 , V_52 ) ) goto V_41;
} while ( ! F_28 ( V_4 ) );
}
else if ( F_30 ( V_3 , 1 ) )
break;
else
{
if ( ! F_3 ( V_3 , V_3 , V_4 ) ) goto V_41;
if ( ! F_3 ( V_51 , V_51 , V_52 ) ) goto V_41;
do
{
if ( ! F_29 ( V_3 , V_3 ) ) goto V_41;
if ( F_28 ( V_51 ) ) if ( ! F_3 ( V_51 , V_51 , V_27 ) ) goto V_41;
if ( ! F_29 ( V_51 , V_51 ) ) goto V_41;
} while ( ! F_28 ( V_3 ) );
}
} while ( 1 );
if ( ! F_26 ( V_16 , V_51 ) ) goto V_41;
F_4 ( V_16 ) ;
V_38 = 1 ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_35 ( T_2 * V_16 , const T_2 * V_59 , const T_2 * V_54 , const unsigned int V_27 [] , T_3 * V_44 )
{
T_2 * V_55 ;
int V_38 = 0 ;
F_4 ( V_59 ) ;
F_4 ( V_54 ) ;
F_17 ( V_44 ) ;
if ( ( V_55 = F_18 ( V_44 ) ) == NULL ) goto V_41;
if ( ! F_32 ( V_27 , V_55 ) ) goto V_41;
V_38 = F_33 ( V_16 , V_59 , V_54 , V_55 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_36 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_4 , const unsigned int V_27 [] , T_3 * V_44 )
{
int V_38 = 0 , V_22 , V_30 ;
T_2 * V_51 ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
if ( F_27 ( V_4 ) )
return ( F_25 ( V_16 ) ) ;
if ( F_30 ( V_4 , 1 ) )
return ( F_26 ( V_16 , V_3 ) != NULL ) ;
F_17 ( V_44 ) ;
if ( ( V_51 = F_18 ( V_44 ) ) == NULL ) goto V_41;
if ( ! F_7 ( V_51 , V_3 , V_27 ) ) goto V_41;
V_30 = F_10 ( V_4 ) - 1 ;
for ( V_22 = V_30 - 1 ; V_22 >= 0 ; V_22 -- )
{
if ( ! F_16 ( V_51 , V_51 , V_27 , V_44 ) ) goto V_41;
if ( F_37 ( V_4 , V_22 ) )
{
if ( ! F_15 ( V_51 , V_51 , V_3 , V_27 , V_44 ) ) goto V_41;
}
}
if ( ! F_26 ( V_16 , V_51 ) ) goto V_41;
F_4 ( V_16 ) ;
V_38 = 1 ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_38 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_4 , const T_2 * V_27 , T_3 * V_44 )
{
int V_38 = 0 ;
const int V_39 = F_10 ( V_27 ) ;
unsigned int * V_40 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_4 ( V_27 ) ;
if ( ( V_40 = ( unsigned int * ) F_11 ( sizeof( unsigned int ) * V_39 ) ) == NULL ) goto V_41;
V_38 = F_12 ( V_27 , V_40 , V_39 ) ;
if ( ! V_38 || V_38 > V_39 )
{
F_13 ( V_60 , V_43 ) ;
goto V_41;
}
V_38 = F_36 ( V_16 , V_3 , V_4 , V_40 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
if ( V_40 ) F_14 ( V_40 ) ;
return V_38 ;
}
int F_39 ( T_2 * V_16 , const T_2 * V_3 , const unsigned int V_27 [] , T_3 * V_44 )
{
int V_38 = 0 ;
T_2 * V_51 ;
F_4 ( V_3 ) ;
if ( ! V_27 [ 0 ] )
{
F_8 ( V_16 ) ;
return 1 ;
}
F_17 ( V_44 ) ;
if ( ( V_51 = F_18 ( V_44 ) ) == NULL ) goto V_41;
if ( ! F_40 ( V_51 , V_27 [ 0 ] - 1 ) ) goto V_41;
V_38 = F_36 ( V_16 , V_3 , V_51 , V_27 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_41 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_27 , T_3 * V_44 )
{
int V_38 = 0 ;
const int V_39 = F_10 ( V_27 ) ;
unsigned int * V_40 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_27 ) ;
if ( ( V_40 = ( unsigned int * ) F_11 ( sizeof( unsigned int ) * V_39 ) ) == NULL ) goto V_41;
V_38 = F_12 ( V_27 , V_40 , V_39 ) ;
if ( ! V_38 || V_38 > V_39 )
{
F_13 ( V_61 , V_43 ) ;
goto V_41;
}
V_38 = F_39 ( V_16 , V_3 , V_40 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
if ( V_40 ) F_14 ( V_40 ) ;
return V_38 ;
}
int F_42 ( T_2 * V_16 , const T_2 * V_62 , const unsigned int V_27 [] , T_3 * V_44 )
{
int V_38 = 0 , V_63 = 0 ;
unsigned int V_28 ;
T_2 * V_3 , * V_35 , * V_64 , * V_65 , * V_66 , * V_53 ;
F_4 ( V_62 ) ;
if ( ! V_27 [ 0 ] )
{
F_8 ( V_16 ) ;
return 1 ;
}
F_17 ( V_44 ) ;
V_3 = F_18 ( V_44 ) ;
V_35 = F_18 ( V_44 ) ;
V_65 = F_18 ( V_44 ) ;
if ( V_65 == NULL ) goto V_41;
if ( ! F_7 ( V_3 , V_62 , V_27 ) ) goto V_41;
if ( F_27 ( V_3 ) )
{
F_8 ( V_16 ) ;
V_38 = 1 ;
goto V_41;
}
if ( V_27 [ 0 ] & 0x1 )
{
if ( ! F_26 ( V_35 , V_3 ) ) goto V_41;
for ( V_28 = 1 ; V_28 <= ( V_27 [ 0 ] - 1 ) / 2 ; V_28 ++ )
{
if ( ! F_16 ( V_35 , V_35 , V_27 , V_44 ) ) goto V_41;
if ( ! F_16 ( V_35 , V_35 , V_27 , V_44 ) ) goto V_41;
if ( ! F_3 ( V_35 , V_35 , V_3 ) ) goto V_41;
}
}
else
{
V_64 = F_18 ( V_44 ) ;
V_66 = F_18 ( V_44 ) ;
V_53 = F_18 ( V_44 ) ;
if ( V_53 == NULL ) goto V_41;
do
{
if ( ! F_43 ( V_64 , V_27 [ 0 ] , 0 , 0 ) ) goto V_41;
if ( ! F_7 ( V_64 , V_64 , V_27 ) ) goto V_41;
F_8 ( V_35 ) ;
if ( ! F_26 ( V_65 , V_64 ) ) goto V_41;
for ( V_28 = 1 ; V_28 <= V_27 [ 0 ] - 1 ; V_28 ++ )
{
if ( ! F_16 ( V_35 , V_35 , V_27 , V_44 ) ) goto V_41;
if ( ! F_16 ( V_66 , V_65 , V_27 , V_44 ) ) goto V_41;
if ( ! F_15 ( V_53 , V_66 , V_3 , V_27 , V_44 ) ) goto V_41;
if ( ! F_3 ( V_35 , V_35 , V_53 ) ) goto V_41;
if ( ! F_3 ( V_65 , V_66 , V_64 ) ) goto V_41;
}
V_63 ++ ;
} while ( F_27 ( V_65 ) && ( V_63 < V_67 ) );
if ( F_27 ( V_65 ) )
{
F_13 ( V_68 , V_69 ) ;
goto V_41;
}
}
if ( ! F_16 ( V_65 , V_35 , V_27 , V_44 ) ) goto V_41;
if ( ! F_3 ( V_65 , V_35 , V_65 ) ) goto V_41;
if ( F_34 ( V_65 , V_3 ) )
{
F_13 ( V_68 , V_70 ) ;
goto V_41;
}
if ( ! F_26 ( V_16 , V_35 ) ) goto V_41;
F_4 ( V_16 ) ;
V_38 = 1 ;
V_41:
F_19 ( V_44 ) ;
return V_38 ;
}
int F_44 ( T_2 * V_16 , const T_2 * V_3 , const T_2 * V_27 , T_3 * V_44 )
{
int V_38 = 0 ;
const int V_39 = F_10 ( V_27 ) ;
unsigned int * V_40 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_27 ) ;
if ( ( V_40 = ( unsigned int * ) F_11 ( sizeof( unsigned int ) *
V_39 ) ) == NULL ) goto V_41;
V_38 = F_12 ( V_27 , V_40 , V_39 ) ;
if ( ! V_38 || V_38 > V_39 )
{
F_13 ( V_71 , V_43 ) ;
goto V_41;
}
V_38 = F_42 ( V_16 , V_3 , V_40 , V_44 ) ;
F_4 ( V_16 ) ;
V_41:
if ( V_40 ) F_14 ( V_40 ) ;
return V_38 ;
}
int F_12 ( const T_2 * V_3 , unsigned int V_27 [] , int V_39 )
{
int V_22 , V_28 , V_29 = 0 ;
T_1 V_72 ;
if ( F_27 ( V_3 ) || ! F_37 ( V_3 , 0 ) )
return 0 ;
for ( V_22 = V_3 -> V_25 - 1 ; V_22 >= 0 ; V_22 -- )
{
if ( ! V_3 -> V_26 [ V_22 ] )
continue;
V_72 = V_73 ;
for ( V_28 = V_36 - 1 ; V_28 >= 0 ; V_28 -- )
{
if ( V_3 -> V_26 [ V_22 ] & V_72 )
{
if ( V_29 < V_39 ) V_27 [ V_29 ] = V_36 * V_22 + V_28 ;
V_29 ++ ;
}
V_72 >>= 1 ;
}
}
return V_29 ;
}
int F_32 ( const unsigned int V_27 [] , T_2 * V_3 )
{
int V_22 ;
F_4 ( V_3 ) ;
F_8 ( V_3 ) ;
for ( V_22 = 0 ; V_27 [ V_22 ] != 0 ; V_22 ++ )
{
F_40 ( V_3 , V_27 [ V_22 ] ) ;
}
F_40 ( V_3 , 0 ) ;
F_4 ( V_3 ) ;
return 1 ;
}
