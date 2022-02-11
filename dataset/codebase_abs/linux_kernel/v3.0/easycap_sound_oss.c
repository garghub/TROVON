void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 * V_7 , * V_8 ;
T_2 V_9 ;
int V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
#ifdef F_2
int V_16 ;
T_2 V_17 , V_18 , V_19 ;
#endif
F_3 ( 16 , L_1 ) ;
if ( ! V_2 ) {
F_4 ( L_2 ) ;
return;
}
V_4 = V_2 -> V_20 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_4 ) ;
return;
}
V_13 = 0 ;
if ( V_4 -> V_23 ) {
F_5 ( 16 , L_5 ,
V_4 -> V_23 , V_4 -> V_24 ) ;
if ( V_4 -> V_24 ) {
V_15 = F_6 ( V_2 , V_25 ) ;
if ( V_15 ) {
if ( - V_26 != V_15 && - V_27 != V_15 ) {
F_7 ( L_6
L_7 ,
V_4 -> V_23 ,
strerror ( V_15 ) , V_15 ) ;
}
}
}
return;
}
if ( V_2 -> V_28 ) {
if ( ( - V_29 == V_2 -> V_28 ) || ( - V_27 == V_2 -> V_28 ) ) {
F_5 ( 16 , L_8 ) ;
return;
}
F_7 ( L_9 ,
strerror ( V_2 -> V_28 ) , V_2 -> V_28 ) ;
goto V_30;
}
#ifdef F_2
V_17 = V_4 -> V_17 ;
#endif
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ ) {
if ( ! V_2 -> V_32 [ V_10 ] . V_28 ) {
F_7 ( L_10 , strerror ( V_2 -> V_32 [ V_10 ] . V_28 ) ) ;
V_12 = V_2 -> V_32 [ V_10 ] . V_33 ;
if ( ! V_12 )
V_4 -> V_34 ++ ;
else {
if ( V_4 -> V_34 ) {
F_5 ( 12 , L_11 ,
V_4 -> V_34 ) ;
V_4 -> V_34 = 0 ;
}
V_7 = ( T_1 * ) ( V_2 -> V_35 + V_2 -> V_32 [ V_10 ] . V_36 ) ;
V_14 = 0 ;
V_7 += V_14 ;
V_12 -= V_14 ;
while ( V_12 ) {
if ( 0 > V_12 ) {
F_7 ( L_12 ) ;
return;
}
if ( V_4 -> V_37 <= V_4 -> V_38 ) {
F_7 ( L_13 ) ;
return;
}
V_6 = & V_4 -> V_39 [ V_4 -> V_38 ] ;
if ( V_40 < ( V_6 -> V_41 - V_6 -> V_42 ) ) {
F_7 ( L_14 ) ;
return;
}
if ( V_40 == ( V_6 -> V_41 - V_6 -> V_42 ) ) {
V_6 -> V_41 = V_6 -> V_42 ;
( V_4 -> V_38 ) ++ ;
if ( V_4 -> V_37 <= V_4 -> V_38 )
V_4 -> V_38 = 0 ;
F_5 ( 8 , L_15
L_16 ,
V_4 -> V_38 ) ;
V_6 = & V_4 -> V_39 [ V_4 -> V_38 ] ;
V_6 -> V_41 = V_6 -> V_42 ;
if ( ! ( V_4 -> V_38 % V_4 -> V_43 ) ) {
F_5 ( 12 , L_17 ,
( V_4 -> V_44 / V_4 -> V_43 ) ,
( V_4 -> V_38 / V_4 -> V_43 ) ) ;
F_8 ( & ( V_4 -> V_45 ) ) ;
}
}
V_13 = V_40 - ( int ) ( V_6 -> V_41 - V_6 -> V_42 ) ;
if ( ! V_4 -> V_46 ) {
if ( V_13 > V_12 )
V_13 = V_12 ;
memcpy ( V_6 -> V_41 , V_7 , V_13 ) ;
V_7 += V_13 ;
V_12 -= V_13 ;
} else {
#ifdef F_2
if ( V_13 % 16 )
F_5 ( 8 , L_18
L_19 ) ;
if ( V_13 > ( 16 * V_12 ) )
V_13 = 16 * V_12 ;
V_8 = ( T_1 * ) V_6 -> V_41 ;
for ( V_11 = 0 ; V_11 < ( V_13 / 16 ) ; V_11 ++ ) {
V_18 = ( ( int ) * V_7 ) - 128 ;
V_18 = 128 * V_18 ;
V_19 = ( V_18 - V_17 ) / 4 ;
V_9 = V_17 + V_19 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
* V_8 = ( 0x00FF & V_9 ) ;
* ( V_8 + 1 ) = ( 0xFF00 & V_9 ) >> 8 ;
V_8 += 2 ;
* V_8 = ( 0x00FF & V_9 ) ;
* ( V_8 + 1 ) = ( 0xFF00 & V_9 ) >> 8 ;
V_8 += 2 ;
V_9 += V_19 ;
}
V_7 ++ ;
V_12 -- ;
V_17 = V_9 ;
}
#else
if ( V_13 > ( 2 * V_12 ) )
V_13 = 2 * V_12 ;
V_8 = ( T_1 * ) V_6 -> V_41 ;
for ( V_11 = 0 ; V_11 < ( V_13 / 2 ) ; V_11 ++ ) {
V_9 = ( ( int ) * V_7 ) - 128 ;
V_9 = 128 * V_9 ;
* V_8 = ( 0x00FF & V_9 ) ;
* ( V_8 + 1 ) = ( 0xFF00 & V_9 ) >> 8 ;
V_7 ++ ;
V_8 += 2 ;
V_12 -- ;
}
#endif
}
( V_6 -> V_41 ) += V_13 ;
}
}
} else {
F_5 ( 12 , L_20
L_21 ,
V_2 -> V_32 [ V_10 ] . V_28 ) ;
}
#ifdef F_2
V_4 -> V_17 = V_17 ;
#endif
}
V_30:
if ( V_4 -> V_24 ) {
V_15 = F_6 ( V_2 , V_25 ) ;
if ( V_15 ) {
if ( - V_26 != V_15 && - V_27 != V_15 ) {
F_7 ( L_6
L_22
L_23 , V_4 -> V_23 ,
strerror ( V_15 ) , V_15 ) ;
}
}
}
return;
}
static int F_9 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
struct V_49 * V_50 ;
struct V_3 * V_4 ;
int V_51 ;
struct V_52 * V_53 ;
F_3 ( 4 , L_24 ) ;
V_51 = F_10 ( V_47 ) ;
V_50 = F_11 ( & V_54 , V_51 ) ;
if ( ! V_50 ) {
F_4 ( L_25 ) ;
F_4 ( L_26 ) ;
return - 1 ;
}
V_4 = F_12 ( V_50 ) ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
F_4 ( L_26 ) ;
return - 1 ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
V_53 = F_12 ( V_50 ) ;
if ( ! V_53 ) {
F_4 ( L_27 ) ;
return - V_55 ;
}
V_4 = F_13 ( V_53 ,
struct V_3 , V_52 ) ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_28 , V_4 ) ;
return - V_55 ;
}
V_48 -> V_56 = V_4 ;
if ( 0 != F_14 ( V_4 ) ) {
;
;
}
return 0 ;
}
static int F_15 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
struct V_3 * V_4 ;
F_3 ( 4 , L_24 ) ;
V_4 = V_48 -> V_56 ;
if ( ! V_4 ) {
F_4 ( L_29 ) ;
return - V_55 ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_28 , V_4 ) ;
return - V_55 ;
}
if ( 0 != F_16 ( V_4 ) ) {
F_7 ( L_30 ) ;
return - V_55 ;
}
F_5 ( 4 , L_31 ) ;
return 0 ;
}
static T_3 F_17 ( struct V_48 * V_48 , char T_4 * V_57 ,
T_5 V_58 , T_6 * V_59 )
{
struct V_60 V_60 ;
long long int V_61 , V_62 , V_63 ;
struct V_64 V_65 ;
unsigned char * V_66 ;
long int V_67 , V_12 , V_15 , V_68 , V_69 ;
int V_70 , V_71 ;
struct V_3 * V_4 ;
struct V_5 * V_72 ;
T_5 V_73 ;
F_3 ( 8 , L_32 , V_58 , * V_59 ) ;
if ( ! V_48 ) {
F_4 ( L_33 ) ;
return - V_74 ;
}
V_4 = V_48 -> V_56 ;
if ( ! V_4 ) {
F_4 ( L_34 ) ;
return - V_55 ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_28 , V_4 ) ;
return - V_55 ;
}
if ( ! V_4 -> V_75 ) {
F_4 ( L_35 ) ;
return - V_55 ;
}
V_71 = F_18 ( V_4 ) ;
if ( 0 <= V_71 && V_76 > V_71 ) {
if ( F_19 ( & ( V_77 [ V_71 ] . V_78 ) ) ) {
F_4 ( L_36
L_37 , V_71 ) ;
return - V_74 ;
}
F_5 ( 4 , L_38 , V_71 ) ;
if ( V_71 != F_18 ( V_4 ) )
return - V_74 ;
if ( ! V_48 ) {
F_4 ( L_33 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
V_4 = V_48 -> V_56 ;
if ( ! V_4 ) {
F_4 ( L_39 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_28 , V_4 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
if ( ! V_4 -> V_75 ) {
F_7 ( L_35 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
} else {
return - V_74 ;
}
F_3 ( 16 , L_40 ,
( V_48 -> V_79 & V_80 ) ? L_41 : L_42 , V_58 , * V_59 ) ;
if ( ( 0 > V_4 -> V_44 ) ||
( V_4 -> V_37 <= V_4 -> V_44 ) ) {
F_7 ( L_43 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
V_72 = & V_4 -> V_39 [ V_4 -> V_44 ] ;
if ( ! V_72 ) {
F_7 ( L_44 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 12 , L_45 ,
( V_4 -> V_44 / V_4 -> V_43 ) ,
( V_4 -> V_38 / V_4 -> V_43 ) ) ;
V_70 = ( V_4 -> V_44 / V_4 -> V_43 ) ;
while ( ( V_70 == ( V_4 -> V_38 / V_4 -> V_43 ) ) ||
( 0 == ( V_40 - ( V_72 -> V_41 - V_72 -> V_42 ) ) ) ) {
if ( V_48 -> V_79 & V_80 ) {
F_5 ( 16 , L_46 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_81 ;
}
V_15 = F_21 ( V_4 -> V_45 ,
( V_4 -> V_23 || V_4 -> V_82 ||
( ( V_70 !=
( V_4 -> V_38 / V_4 -> V_43 ) ) &&
( 0 < ( V_40 - ( V_72 -> V_41 - V_72 -> V_42 ) ) ) ) ) ) ;
if ( V_15 ) {
F_7 ( L_47 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
if ( V_4 -> V_82 ) {
F_5 ( 8 , L_48 ,
V_4 -> V_82 ) ;
F_16 ( V_4 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return 0 ;
}
if ( V_4 -> V_23 ) {
F_5 ( 16 , L_49 ,
V_4 -> V_23 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return 0 ;
}
if ( ! V_4 -> V_24 ) {
F_5 ( 16 , L_50 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return 0 ;
}
}
F_5 ( 12 , L_51 ,
( V_4 -> V_44 / V_4 -> V_43 ) ,
( V_4 -> V_38 / V_4 -> V_43 ) ) ;
V_73 = ( T_5 ) 0 ;
V_70 = ( V_4 -> V_44 / V_4 -> V_43 ) ;
while ( V_70 == ( V_4 -> V_44 / V_4 -> V_43 ) ) {
if ( ! V_72 -> V_42 ) {
F_7 ( L_52 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
if ( ! V_72 -> V_41 ) {
F_7 ( L_53 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
V_67 = V_40 - ( V_72 -> V_41 - V_72 -> V_42 ) ;
if ( 0 > V_67 ) {
F_7 ( L_54 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
if ( ! V_67 ) {
V_4 -> V_44 ++ ;
if ( V_4 -> V_37 <= V_4 -> V_44 )
V_4 -> V_44 = 0 ;
F_5 ( 12 , L_55 ,
V_4 -> V_44 ) ;
if ( V_70 != ( V_4 -> V_44 / V_4 -> V_43 ) )
break;
if ( ( 0 > V_4 -> V_44 ) ||
( V_4 -> V_37 <= V_4 -> V_44 ) ) {
F_7 ( L_43 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
V_72 = & V_4 -> V_39 [ V_4 -> V_44 ] ;
if ( ! V_72 ) {
F_7 ( L_44 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
if ( ! V_72 -> V_42 ) {
F_7 ( L_52 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
if ( ! V_72 -> V_41 ) {
F_7 ( L_53 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
V_67 = V_40 - ( V_72 -> V_41 - V_72 -> V_42 ) ;
}
F_5 ( 12 , L_56 , V_67 ) ;
F_5 ( 12 , L_57 , ( long int ) V_58 ) ;
V_12 = V_67 ;
if ( V_12 > V_58 )
V_12 = V_58 ;
F_5 ( 12 , L_58 ,
V_12 , V_4 -> V_44 ) ;
if ( ! V_12 )
break;
V_66 = ( unsigned char * ) V_72 -> V_42 ;
V_68 = 0 ;
V_69 = V_12 / 2 ;
while ( V_68 < V_69 ) {
F_22 ( V_66 , & V_4 -> V_83 ,
& V_4 -> V_84 ,
& V_4 -> V_85 ) ;
V_68 ++ ;
V_66 += 2 ;
}
V_15 = F_23 ( V_57 , V_72 -> V_41 , V_12 ) ;
if ( V_15 ) {
F_7 ( L_59 , V_15 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
* V_59 += ( T_6 ) V_12 ;
V_73 += ( T_5 ) V_12 ;
V_72 -> V_41 += V_12 ;
V_57 += V_12 ;
V_58 -= ( T_5 ) V_12 ;
}
F_5 ( 12 , L_60 ,
( V_4 -> V_44 / V_4 -> V_43 ) ,
( V_4 -> V_38 / V_4 -> V_43 ) ) ;
if ( V_58 < 0 ) {
F_7 ( L_61 ,
( long int ) V_58 , ( long int ) V_73 ) ;
}
if ( V_4 -> V_83 ) {
V_62 = V_4 -> V_83 ;
V_61 = V_4 -> V_85 ;
V_65 = F_24 ( V_61 , V_62 ) ;
V_61 = V_65 . V_86 ;
V_63 = V_4 -> V_84 ;
V_65 = F_24 ( V_63 , V_4 -> V_83 ) ;
F_5 ( 8 , L_62 ,
V_65 . V_86 , V_61 , V_4 -> V_83 ) ;
V_65 = F_24 ( V_61 , 32768 ) ;
F_5 ( 8 , L_63 , V_65 . V_86 ) ;
}
F_25 ( & V_60 ) ;
if ( ! V_4 -> V_87 . V_88 ) {
V_4 -> V_89 = 0 ;
V_4 -> V_90 = V_60 ;
V_4 -> V_87 = V_4 -> V_90 ;
V_65 . V_86 = 192000 ;
} else {
V_4 -> V_89 += ( long long int ) V_73 ;
V_62 = ( ( long long int ) ( 1000000 ) ) *
( ( long long int ) ( V_60 . V_88 - V_4 -> V_90 . V_88 ) ) +
( long long int ) ( V_60 . V_91 - V_4 -> V_90 . V_91 ) ;
V_61 = 1000000 * ( ( long long int ) V_4 -> V_89 ) ;
if ( V_62 )
V_65 = F_24 ( V_61 , V_62 ) ;
else
V_65 . V_86 = 192000 ;
}
F_5 ( 8 , L_64 , V_65 . V_86 ) ;
V_4 -> V_92 = V_65 . V_86 ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
F_5 ( 4 , L_65 , V_71 ) ;
F_5 ( 8 , L_66 , ( long int ) V_73 ) ;
return V_73 ;
}
static long F_26 ( struct V_48 * V_48 ,
unsigned int V_93 , unsigned long V_94 )
{
struct V_3 * V_4 ;
struct V_95 * V_96 ;
int V_71 ;
if ( ! V_48 ) {
F_4 ( L_33 ) ;
return - V_74 ;
}
V_4 = V_48 -> V_56 ;
if ( ! V_4 ) {
F_4 ( L_29 ) ;
return - V_55 ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_4 ) ;
return - V_55 ;
}
V_96 = V_4 -> V_75 ;
if ( ! V_96 ) {
F_7 ( L_35 ) ;
return - V_55 ;
}
V_71 = F_18 ( V_4 ) ;
if ( 0 <= V_71 && V_76 > V_71 ) {
if ( F_19 ( & V_77 [ V_71 ] . V_78 ) ) {
F_4 ( L_67
L_68 , V_71 ) ;
return - V_74 ;
}
F_5 ( 4 , L_69 , V_71 ) ;
if ( V_71 != F_18 ( V_4 ) )
return - V_74 ;
if ( ! V_48 ) {
F_4 ( L_33 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
V_4 = V_48 -> V_56 ;
if ( ! V_4 ) {
F_4 ( L_39 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
if ( memcmp ( & V_4 -> V_21 [ 0 ] , V_22 , strlen ( V_22 ) ) ) {
F_4 ( L_4 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
V_96 = V_4 -> V_75 ;
if ( ! V_4 -> V_75 ) {
F_7 ( L_35 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_74 ;
}
} else {
return - V_74 ;
}
switch ( V_93 ) {
case V_97 : {
int V_98 ;
F_5 ( 8 , L_70 ) ;
#ifdef F_2
if ( V_4 -> V_46 )
V_98 = 0x04400000 ;
else
V_98 = 0x04400000 ;
#else
if ( V_4 -> V_46 )
V_98 = 0x02400000 ;
else
V_98 = 0x04400000 ;
#endif
if ( F_23 ( ( void T_4 * ) V_94 , & V_98 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case V_99 : {
int V_100 ;
F_5 ( 8 , L_71 ) ;
#ifdef F_2
if ( V_4 -> V_46 )
V_100 = V_101 ;
else
V_100 = V_101 ;
#else
if ( V_4 -> V_46 )
V_100 = V_101 ;
else
V_100 = V_101 ;
#endif
if ( F_23 ( ( void T_4 * ) V_94 , & V_100 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case V_102 : {
int V_100 , V_103 ;
F_5 ( 8 , L_72 ) ;
if ( F_27 ( & V_100 , ( void T_4 * ) V_94 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 8 , L_73 , V_100 ) ;
#ifdef F_2
if ( V_4 -> V_46 )
V_103 = V_101 ;
else
V_103 = V_101 ;
#else
if ( V_4 -> V_46 )
V_103 = V_101 ;
else
V_103 = V_101 ;
#endif
if ( V_100 != V_103 ) {
F_5 ( 8 , L_74 , V_103 ) ;
F_5 ( 8 , L_75 , V_101 ) ;
F_5 ( 8 , L_76 , V_104 ) ;
if ( F_23 ( ( void T_4 * ) V_94 , & V_103 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_105 ;
}
break;
}
case V_106 : {
int V_100 ;
F_5 ( 8 , L_77 ) ;
if ( F_27 ( & V_100 , ( void T_4 * ) V_94 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 8 , L_73 , V_100 ) ;
#ifdef F_2
if ( V_4 -> V_46 )
V_100 = 1 ;
else
V_100 = 1 ;
#else
if ( V_4 -> V_46 )
V_100 = 0 ;
else
V_100 = 1 ;
#endif
if ( F_23 ( ( void T_4 * ) V_94 , & V_100 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case V_107 : {
int V_100 ;
F_5 ( 8 , L_78 ) ;
if ( F_27 ( & V_100 , ( void T_4 * ) V_94 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 8 , L_73 , V_100 ) ;
#ifdef F_2
if ( V_4 -> V_46 )
V_100 = 32000 ;
else
V_100 = 48000 ;
#else
if ( V_4 -> V_46 )
V_100 = 8000 ;
else
V_100 = 48000 ;
#endif
if ( F_23 ( ( void T_4 * ) V_94 , & V_100 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case V_108 : {
int V_100 ;
F_5 ( 8 , L_79 ) ;
if ( F_27 ( & V_100 , ( void T_4 * ) V_94 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 8 , L_73 , V_100 ) ;
V_100 = V_109 ;
if ( F_23 ( ( void T_4 * ) V_94 , & V_100 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case V_110 : {
int V_100 ;
F_5 ( 8 , L_80 ) ;
if ( F_27 ( & V_100 , ( void T_4 * ) V_94 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 8 , L_73 , V_100 ) ;
F_5 ( 8 , L_81
L_82 ,
V_109 , V_111 ) ;
;
;
;
;
break;
}
case V_112 : {
int V_100 ;
F_5 ( 8 , L_83 ) ;
if ( F_27 ( & V_100 , ( void T_4 * ) V_94 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
F_5 ( 8 , L_73 , V_100 ) ;
V_100 = V_4 -> V_113 ;
if ( F_23 ( ( void T_4 * ) V_94 , & V_100 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case V_114 : {
struct V_115 V_115 ;
F_5 ( 8 , L_84 ) ;
V_115 . V_116 = V_4 -> V_113 ;
V_115 . V_117 = 1 ;
V_115 . V_118 = 0 ;
V_115 . V_119 = 0 ;
if ( F_23 ( ( void T_4 * ) V_94 , & V_115 , sizeof( int ) ) ) {
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_55 ;
}
break;
}
case 0x00005401 :
case 0x00005402 :
case 0x00005403 :
case 0x00005404 :
case 0x00005405 :
case 0x00005406 : {
F_5 ( 8 , L_85 , V_93 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_120 ;
}
default: {
F_5 ( 8 , L_86 , V_93 ) ;
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return - V_120 ;
}
}
F_20 ( & V_77 [ V_71 ] . V_78 ) ;
return 0 ;
}
