static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 , V_6 ;
unsigned char * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned char V_10 ;
for ( V_3 = V_9 -> V_11 . V_12 ; V_3 < V_13 ; V_3 += V_9 -> V_11 . V_14 ) {
V_5 = V_9 -> V_11 . V_15 ;
V_6 = V_9 -> V_11 . V_16 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
if ( V_7 [ V_3 * V_17 + V_4 ] == 0 ) {
if ( V_5 > 0 ) {
V_5 -- ;
V_10 = V_18 ;
} else if ( V_6 > 0 ) {
V_6 -- ;
V_10 = V_19 ;
} else {
break;
}
V_7 [ V_3 * V_17 + V_4 ] = V_10 ;
}
}
}
}
static void F_2 ( struct V_1 * V_2 )
{
int V_4 , V_3 , V_20 ;
unsigned char * V_7 = V_2 -> V_7 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
unsigned char V_10 ;
V_20 = 1 ;
V_10 = V_18 ;
for ( V_4 = V_17 - 1 ; V_4 >= 0 ; V_4 -- ) {
if ( V_22 -> V_23 [ V_4 ] == 1 ) {
if ( V_20 > V_22 -> V_24 ) {
break;
} else if ( V_20 > 7 ) {
V_10 = V_19 ;
}
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
if ( V_7 [ V_3 * V_13 + V_4 ] != V_25 ) {
V_7 [ V_3 * V_13 + V_4 ] = V_10 ;
if( V_10 == V_18 )
V_2 -> V_26 ++ ;
else
V_2 -> V_27 ++ ;
}
}
V_20 ++ ;
}
}
V_2 -> V_28 = V_2 -> V_26 + V_2 -> V_27 ;
}
static int F_3 ( struct V_1 * V_2 , int V_14 ,
int V_29 , int V_30 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_31 * V_11 = & V_9 -> V_11 ;
struct V_31 V_32 ;
int V_33 , V_34 , V_3 , V_35 , V_36 ;
int V_12 , V_37 , V_38 ;
int V_39 ;
int V_40 = V_41 ;
V_32 . V_12 = 0 ;
V_35 = V_14 ;
V_39 = V_30 + V_29 ;
for ( V_33 = 0 ; ( ( V_14 >> V_33 ) & 0x1 ) == 0 ; V_33 ++ ) {
V_35 /= 2 ;
V_36 = 0 ;
V_38 = V_17 ;
for ( V_34 = 1 ; V_34 <= ( 1 << V_33 ) ; V_34 ++ ) {
V_37 = 0 ;
V_12 = V_35 + V_36 ;
for ( V_3 = V_12 ; V_3 < V_13 ; V_3 += V_14 ) {
if ( V_9 [ V_3 ] . V_42 >= V_29 &&
V_9 [ V_3 ] . V_43 >= V_39 ) {
if ( V_9 [ V_3 ] . V_44 [ V_39 ] > V_37 )
V_37 = V_9 [ V_3 ] . V_44 [ V_39 ] ;
} else {
V_37 = 0 ;
break;
}
}
if ( ( V_38 > V_37 ) && V_37 ) {
V_38 = V_37 ;
V_32 . V_12 = V_12 ;
}
V_36 += ( V_14 >> V_33 ) ;
}
if ( V_38 < 8 ) {
V_11 -> V_12 = V_32 . V_12 ;
V_40 = V_45 ;
break;
} else if ( ( V_38 > 8 ) &&
( V_38 != V_17 ) &&
( V_40 == V_41 ) ) {
V_11 -> V_12 = V_32 . V_12 ;
V_40 = V_45 ;
}
}
if ( V_40 == V_45 ) {
V_11 -> V_14 = V_14 ;
V_11 -> V_15 = V_29 ;
V_11 -> V_16 = V_30 ;
V_2 -> V_26 = ( V_13 / V_14 ) * V_29 ;
V_2 -> V_27 = ( V_13 / V_14 ) * V_30 ;
V_2 -> V_28 = V_2 -> V_26 + V_2 -> V_27 ;
V_2 -> V_14 = V_14 ;
}
return V_40 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned char * V_7 = V_2 -> V_7 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
int V_3 , V_4 ;
V_22 -> V_46 = 16 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
V_22 -> V_23 [ V_4 ] = 1 ;
for ( V_3 = 1 ; V_3 < V_13 ; V_3 ++ ) {
if ( V_7 [ V_3 * V_13 + V_4 ] == V_25 ) {
V_22 -> V_46 -- ;
V_22 -> V_23 [ V_4 ] = 0 ;
break;
}
}
}
}
static void F_5 ( unsigned char * V_7 , int V_47 , struct V_8 * V_48 )
{
int V_4 ;
int V_49 = 0 , V_50 = 0 ;
int V_51 = 0 ;
int V_52 = 0 ;
int V_53 [ V_17 ] = {
8 , 7 , 6 , 5 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 3 , 2 , 1 ,
} ;
V_48 -> V_42 = 0 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
if ( ! V_7 [ V_47 * V_13 + V_4 ] ) {
V_52 ++ ;
V_48 -> V_43 = V_52 ;
V_48 -> V_44 [ V_52 ] = V_4 ;
if ( V_51 ) {
V_49 ++ ;
if ( ( V_49 > V_53 [ V_50 ] ) &&
( ! V_48 -> V_42 ) )
V_48 -> V_42 = V_52 - 1 ;
} else {
V_51 = 1 ;
V_50 = V_4 ;
V_49 = 1 ;
}
} else {
V_51 = 0 ;
}
}
if ( ! V_48 -> V_42 )
V_48 -> V_42 = V_48 -> V_43 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned char * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_3 ;
for ( V_3 = 1 ; V_3 < V_13 ; V_3 ++ ) {
F_5 ( V_7 , V_3 , & V_9 [ V_3 ] ) ;
}
}
static int F_7 ( struct V_1 * V_2 )
{
int V_54 ;
int V_55 = V_2 -> V_56 / V_57 ;
int V_58 = V_2 -> V_59 / V_57 ;
if ( V_2 -> V_59 % V_57 )
V_58 ++ ;
for ( V_54 = V_55 ; V_54 >= V_58 ; V_54 -- ) {
if ( V_54 <= V_2 -> V_22 . V_46 ) {
V_2 -> V_22 . V_24 = V_54 ;
V_2 -> V_14 = 1 ;
F_2 ( V_2 ) ;
return V_45 ;
}
}
return V_41 ;
}
static int F_8 ( struct V_1 * V_2 , int V_14 )
{
int V_60 , V_61 , V_39 ;
int V_62 = V_13 / V_14 ;
int V_63 = V_2 -> V_56 / V_62 ;
int V_64 = V_2 -> V_59 / V_62 ;
if ( V_2 -> V_59 % V_62 )
V_64 ++ ;
if ( V_64 > V_17 ) {
return V_41 ;
}
if ( V_63 > V_17 ) {
V_63 = V_17 ;
}
for ( V_39 = V_63 ; V_39 >= V_64 ; V_39 -- ) {
if ( F_3 ( V_2 , V_14 , 0 , V_39 ) == V_41 )
continue;
for ( V_60 = V_39 ; V_60 >= 0 ; V_60 -- ) {
V_61 = V_39 - V_60 ;
if ( F_3 ( V_2 , V_14 , V_60 , V_61 ) == V_45 ) {
F_1 ( V_2 ) ;
return V_45 ;
}
}
}
return V_41 ;
}
int F_9 ( struct V_65 * V_66 , struct V_67 * V_52 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 ;
int V_14 ;
int V_69 ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 )
return V_41 ;
V_2 -> V_59 = V_66 -> V_59 ;
V_2 -> V_56 = V_66 -> V_56 ;
V_2 -> V_71 = V_66 -> V_71 ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
if ( ! F_11 ( V_69 , V_52 -> V_7 ) )
V_2 -> V_7 [ V_69 ] = V_25 ;
}
if ( V_2 -> V_71 == 1 ) {
F_4 ( V_2 ) ;
if ( F_7 ( V_2 ) == V_45 )
goto V_73;
else
goto V_74;
}
F_6 ( V_2 ) ;
for ( V_14 = 16 ; V_14 >= 2 ; V_14 >>= 1 ) {
if ( V_14 > V_2 -> V_71 )
continue;
if ( F_8 ( V_2 , V_14 ) == V_45 )
goto V_73;
}
F_4 ( V_2 ) ;
if ( F_7 ( V_2 ) == V_45 )
goto V_73;
else
goto V_74;
V_73:
F_12 ( V_68 -> V_7 , V_72 ) ;
F_12 ( V_68 -> V_75 , V_72 ) ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
if ( V_2 -> V_7 [ V_69 ] == V_18 )
F_13 ( V_69 , V_68 -> V_7 ) ;
else if ( V_2 -> V_7 [ V_69 ] == V_19 )
F_13 ( V_69 , V_68 -> V_75 ) ;
}
F_14 ( V_68 -> V_7 , V_68 -> V_7 , V_68 -> V_75 , V_72 ) ;
V_68 -> V_76 = V_2 -> V_26 ;
V_68 -> V_77 = V_2 -> V_27 ;
F_15 ( V_2 ) ;
return V_45 ;
V_74:
F_15 ( V_2 ) ;
return V_41 ;
}
