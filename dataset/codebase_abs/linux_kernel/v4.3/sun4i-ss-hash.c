int F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ,
sizeof( struct V_3 ) ) ;
return 0 ;
}
int F_4 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
struct V_7 * V_2 = F_6 ( V_5 ) ;
struct V_8 * V_9 = F_7 ( V_2 -> V_10 . V_11 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
memset ( V_6 , 0 , sizeof( struct V_3 ) ) ;
V_13 = F_8 ( V_9 , struct V_12 , V_9 . V_16 ) ;
V_15 = V_13 -> V_15 ;
V_6 -> V_15 = V_13 -> V_15 ;
V_6 -> V_17 = V_13 -> V_17 ;
return 0 ;
}
int F_9 ( struct V_4 * V_5 , void * V_18 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
struct V_19 * V_20 = V_18 ;
int V_21 ;
V_20 -> V_22 = V_6 -> V_22 + V_6 -> V_23 ;
memcpy ( V_20 -> V_24 , V_6 -> V_25 , V_6 -> V_23 ) ;
if ( V_6 -> V_22 > 0 ) {
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
V_20 -> V_16 [ V_21 ] = V_6 -> V_16 [ V_21 ] ;
} else {
V_20 -> V_16 [ 0 ] = V_26 ;
V_20 -> V_16 [ 1 ] = V_27 ;
V_20 -> V_16 [ 2 ] = V_28 ;
V_20 -> V_16 [ 3 ] = V_29 ;
}
return 0 ;
}
int F_10 ( struct V_4 * V_5 , const void * V_30 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
const struct V_19 * V_31 = V_30 ;
int V_21 ;
F_4 ( V_5 ) ;
V_6 -> V_22 = V_31 -> V_22 & ~ 0x3F ;
V_6 -> V_23 = V_31 -> V_22 & 0x3F ;
memcpy ( V_6 -> V_25 , V_31 -> V_24 , V_6 -> V_23 ) ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
V_6 -> V_16 [ V_21 ] = V_31 -> V_16 [ V_21 ] ;
return 0 ;
}
int F_11 ( struct V_4 * V_5 , void * V_18 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
struct V_32 * V_20 = V_18 ;
int V_21 ;
V_20 -> V_33 = V_6 -> V_22 + V_6 -> V_23 ;
memcpy ( V_20 -> V_34 , V_6 -> V_25 , V_6 -> V_23 ) ;
if ( V_6 -> V_22 > 0 ) {
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
V_20 -> V_35 [ V_21 ] = V_6 -> V_16 [ V_21 ] ;
} else {
V_20 -> V_35 [ 0 ] = V_26 ;
V_20 -> V_35 [ 1 ] = V_27 ;
V_20 -> V_35 [ 2 ] = V_28 ;
V_20 -> V_35 [ 3 ] = V_29 ;
V_20 -> V_35 [ 4 ] = V_36 ;
}
return 0 ;
}
int F_12 ( struct V_4 * V_5 , const void * V_30 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
const struct V_32 * V_31 = V_30 ;
int V_21 ;
F_4 ( V_5 ) ;
V_6 -> V_22 = V_31 -> V_33 & ~ 0x3F ;
V_6 -> V_23 = V_31 -> V_33 & 0x3F ;
memcpy ( V_6 -> V_25 , V_31 -> V_34 , V_6 -> V_23 ) ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
V_6 -> V_16 [ V_21 ] = V_31 -> V_35 [ V_21 ] ;
return 0 ;
}
int F_13 ( struct V_4 * V_5 )
{
T_1 V_37 , V_38 = 0 ;
unsigned int V_21 = 0 ;
struct V_3 * V_6 = F_5 ( V_5 ) ;
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_7 * V_2 = F_6 ( V_5 ) ;
unsigned int V_39 = 0 ;
unsigned int V_40 ;
int V_41 , V_42 = 0 ;
unsigned int V_43 ;
T_1 V_44 , V_45 = V_46 ;
T_2 V_47 = 0 ;
struct V_48 V_49 ;
F_14 ( V_15 -> V_50 , L_1 ,
V_51 , F_15 ( V_5 -> V_10 . V_2 ) ,
V_6 -> V_22 , V_5 -> V_52 , V_6 -> V_17 ,
V_6 -> V_23 , V_6 -> V_16 [ 0 ] ) ;
if ( V_5 -> V_52 == 0 )
return 0 ;
if ( V_5 -> V_52 > V_53 - V_6 -> V_23 ) {
F_16 ( V_15 -> V_50 , L_2 ) ;
return - V_54 ;
}
if ( V_6 -> V_23 + V_5 -> V_52 < 64 ) {
V_47 = F_17 ( V_5 -> V_55 , F_18 ( V_5 -> V_55 ) ,
V_6 -> V_25 + V_6 -> V_23 , V_5 -> V_52 , 0 ) ;
V_6 -> V_23 += V_47 ;
return 0 ;
}
V_40 = ( ( V_5 -> V_52 + V_6 -> V_23 ) / 64 ) * 64 - V_6 -> V_23 ;
if ( V_40 > V_5 -> V_52 || V_5 -> V_52 - V_40 > 63 ) {
F_16 ( V_15 -> V_50 , L_3 ,
V_40 , V_5 -> V_52 ) ;
return - V_54 ;
}
F_19 ( & V_15 -> V_56 ) ;
if ( V_6 -> V_22 > 0 ) {
V_38 = V_57 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
F_20 ( V_6 -> V_16 [ V_21 ] , V_15 -> V_10 + V_58 + V_21 * 4 ) ;
}
F_20 ( V_6 -> V_17 | V_59 | V_38 , V_15 -> V_10 + V_60 ) ;
V_21 = 0 ;
F_21 ( & V_49 , V_5 -> V_55 , F_18 ( V_5 -> V_55 ) ,
V_61 | V_62 ) ;
F_22 ( & V_49 ) ;
V_39 = 0 ;
do {
if ( V_6 -> V_23 > 0 || ( V_49 . V_63 - V_39 ) < 4 ) {
while ( V_6 -> V_23 < 64 && V_21 < V_40 ) {
V_41 = F_23 ( V_49 . V_63 - V_39 , V_40 - V_21 ,
64 - V_6 -> V_23 ) ;
memcpy ( V_6 -> V_25 + V_6 -> V_23 , V_49 . V_64 + V_39 , V_41 ) ;
V_6 -> V_23 += V_41 ;
V_21 += V_41 ;
V_39 += V_41 ;
if ( V_39 == V_49 . V_63 ) {
F_22 ( & V_49 ) ;
V_39 = 0 ;
}
}
if ( V_6 -> V_23 > 3 && ( V_6 -> V_23 % 4 ) == 0 ) {
F_24 ( V_15 -> V_10 + V_65 , V_6 -> V_25 ,
V_6 -> V_23 / 4 ) ;
V_6 -> V_22 += V_6 -> V_23 ;
V_6 -> V_23 = 0 ;
}
}
if ( V_49 . V_63 - V_39 > 3 && V_21 < V_40 ) {
V_41 = F_23 ( V_49 . V_63 - V_39 , V_5 -> V_52 - V_21 ,
( ( V_49 . V_63 - V_39 ) / 4 ) * 4 ) ;
V_43 = F_23 ( ( T_1 ) ( V_40 - V_21 ) / 4 , V_45 , ( T_1 ) V_41 / 4 ) ;
F_24 ( V_15 -> V_10 + V_65 , V_49 . V_64 + V_39 , V_43 ) ;
V_6 -> V_22 += V_43 * 4 ;
V_21 += V_43 * 4 ;
V_39 += V_43 * 4 ;
V_45 -= V_43 ;
if ( V_45 == 0 ) {
V_44 = F_25 ( V_15 -> V_10 + V_66 ) ;
V_45 = F_26 ( V_44 ) ;
}
if ( V_39 == V_49 . V_63 ) {
F_22 ( & V_49 ) ;
V_39 = 0 ;
}
}
} while ( V_21 < V_40 );
if ( ( V_5 -> V_52 - V_21 ) < 64 ) {
while ( V_21 < V_5 -> V_52 && V_39 < V_49 . V_63 && V_6 -> V_23 < 64 ) {
V_41 = F_23 ( V_49 . V_63 - V_39 , V_5 -> V_52 - V_21 ,
64 - V_6 -> V_23 ) ;
memcpy ( V_6 -> V_25 + V_6 -> V_23 , V_49 . V_64 + V_39 , V_41 ) ;
V_6 -> V_23 += V_41 ;
V_21 += V_41 ;
V_39 += V_41 ;
if ( V_39 == V_49 . V_63 ) {
F_22 ( & V_49 ) ;
V_39 = 0 ;
}
}
}
F_27 ( & V_49 ) ;
F_20 ( V_6 -> V_17 | V_59 | V_67 , V_15 -> V_10 + V_60 ) ;
V_21 = 0 ;
do {
V_37 = F_25 ( V_15 -> V_10 + V_60 ) ;
V_21 ++ ;
} while ( V_21 < V_68 && ( V_37 & V_67 ) > 0 );
if ( V_21 >= V_68 ) {
F_28 ( V_15 -> V_50 ,
L_4 ,
V_21 , V_68 , V_37 , V_5 -> V_52 ) ;
V_42 = - V_69 ;
goto V_70;
}
for ( V_21 = 0 ; V_21 < F_29 ( V_2 ) / 4 ; V_21 ++ )
V_6 -> V_16 [ V_21 ] = F_25 ( V_15 -> V_10 + V_71 + V_21 * 4 ) ;
V_70:
F_20 ( 0 , V_15 -> V_10 + V_60 ) ;
F_30 ( & V_15 -> V_56 ) ;
return V_42 ;
}
int F_31 ( struct V_4 * V_5 )
{
T_1 V_37 , V_38 = 0 ;
unsigned int V_21 ;
unsigned int V_72 = 0 ;
int V_73 , V_42 = 0 ;
unsigned int V_74 , V_75 ;
T_3 V_76 ;
struct V_3 * V_6 = F_5 ( V_5 ) ;
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_7 * V_2 = F_6 ( V_5 ) ;
T_1 V_77 [ 32 ] ;
T_1 V_78 = 0 ;
unsigned int V_79 , V_80 = 0 ;
F_14 ( V_15 -> V_50 , L_5 ,
V_51 , V_6 -> V_22 , V_5 -> V_52 , V_6 -> V_17 ,
V_6 -> V_23 , V_6 -> V_16 [ 0 ] ) ;
F_19 ( & V_15 -> V_56 ) ;
if ( V_6 -> V_22 > 0 ) {
V_38 = V_57 ;
for ( V_21 = 0 ; V_21 < F_29 ( V_2 ) / 4 ; V_21 ++ )
F_20 ( V_6 -> V_16 [ V_21 ] , V_15 -> V_10 + V_58 + V_21 * 4 ) ;
}
F_20 ( V_6 -> V_17 | V_59 | V_38 , V_15 -> V_10 + V_60 ) ;
if ( V_6 -> V_23 > 0 ) {
V_79 = V_6 -> V_23 / 4 ;
if ( V_79 > 0 ) {
F_24 ( V_15 -> V_10 + V_65 , V_6 -> V_25 , V_79 ) ;
V_6 -> V_22 += 4 * V_79 ;
}
V_80 = V_6 -> V_23 - 4 * V_79 ;
V_78 = * ( T_1 * ) ( V_6 -> V_25 + V_79 * 4 ) ;
V_78 &= ( 0xFFFFFFFF >> ( 4 - V_80 ) * 8 ) ;
}
if ( V_80 > 0 ) {
V_78 |= ( ( 1 << 7 ) << ( V_80 * 8 ) ) ;
V_77 [ V_72 ++ ] = V_78 ;
} else {
V_77 [ V_72 ++ ] = 1 << 7 ;
}
if ( V_6 -> V_17 == V_81 ) {
V_74 = ( V_6 -> V_22 + 4 ) & 0x3f ;
V_6 -> V_22 += V_80 ;
if ( V_74 > 56 )
V_73 = ( 120 - V_74 ) / 4 ;
else
V_73 = ( 56 - V_74 ) / 4 ;
} else {
V_6 -> V_22 += V_80 ;
V_74 = V_6 -> V_22 & 0x3f ;
V_75 = ( V_74 < 56 ) ? ( 56 - V_74 ) : ( ( 64 + 56 ) - V_74 ) ;
V_73 = ( V_75 - 1 ) / 4 ;
}
memset ( V_77 + V_72 , 0 , 4 * V_73 ) ;
V_72 += V_73 ;
if ( V_6 -> V_17 == V_82 ) {
V_76 = F_32 ( V_6 -> V_22 << 3 ) ;
V_77 [ V_72 ++ ] = V_76 & 0xffffffff ;
V_77 [ V_72 ++ ] = ( V_76 >> 32 ) & 0xffffffff ;
} else {
V_77 [ V_72 ++ ] = ( V_6 -> V_22 << 3 ) & 0xffffffff ;
V_77 [ V_72 ++ ] = ( V_6 -> V_22 >> 29 ) & 0xffffffff ;
}
F_24 ( V_15 -> V_10 + V_65 , V_77 , V_72 ) ;
F_20 ( V_6 -> V_17 | V_59 | V_67 , V_15 -> V_10 + V_60 ) ;
V_21 = 0 ;
do {
V_37 = F_25 ( V_15 -> V_10 + V_60 ) ;
V_21 ++ ;
} while ( V_21 < V_68 && ( V_37 & V_67 ) > 0 );
if ( V_21 >= V_68 ) {
F_28 ( V_15 -> V_50 ,
L_4 ,
V_21 , V_68 , V_37 , V_5 -> V_52 ) ;
V_42 = - V_69 ;
goto V_70;
}
if ( V_6 -> V_17 == V_82 ) {
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
V_37 = F_33 ( F_25 ( V_15 -> V_10 + V_71 + V_21 * 4 ) ) ;
memcpy ( V_5 -> V_83 + V_21 * 4 , & V_37 , 4 ) ;
}
} else {
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
V_37 = F_25 ( V_15 -> V_10 + V_71 + V_21 * 4 ) ;
memcpy ( V_5 -> V_83 + V_21 * 4 , & V_37 , 4 ) ;
}
}
V_70:
F_20 ( 0 , V_15 -> V_10 + V_60 ) ;
F_30 ( & V_15 -> V_56 ) ;
return V_42 ;
}
int F_34 ( struct V_4 * V_5 )
{
int V_42 ;
V_42 = F_13 ( V_5 ) ;
if ( V_42 != 0 )
return V_42 ;
return F_31 ( V_5 ) ;
}
int F_35 ( struct V_4 * V_5 )
{
int V_42 ;
V_42 = F_4 ( V_5 ) ;
if ( V_42 != 0 )
return V_42 ;
V_42 = F_13 ( V_5 ) ;
if ( V_42 != 0 )
return V_42 ;
return F_31 ( V_5 ) ;
}
