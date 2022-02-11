int F_1 ( void )
{
return sizeof( struct V_1 ) ;
}
int F_2 ( T_1 V_2 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL || V_2 -> V_4 == NULL ) return V_5 ;
V_4 = (struct V_3 * ) V_2 -> V_4 ;
V_2 -> V_6 = V_2 -> V_7 = V_4 -> V_8 = 0 ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = 1 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = 0 ;
V_4 -> V_14 = 0 ;
V_4 -> V_15 = 32768U ;
V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = V_4 -> V_19 = V_4 -> V_20 = V_4 -> V_21 ;
V_4 -> V_22 = 1U << V_4 -> V_23 ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 0 ;
return V_26 ;
}
int F_3 ( T_1 V_2 , int V_27 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL ) return V_5 ;
V_2 -> V_9 = NULL ;
V_4 = & F_4 ( V_2 ) -> V_3 ;
V_2 -> V_4 = (struct V_28 * ) V_4 ;
if ( V_27 < 0 ) {
V_4 -> V_29 = 0 ;
V_27 = - V_27 ;
}
else {
V_4 -> V_29 = ( V_27 >> 4 ) + 1 ;
}
if ( V_27 < 8 || V_27 > 15 ) {
return V_5 ;
}
V_4 -> V_23 = ( unsigned ) V_27 ;
V_4 -> V_30 = & F_4 ( V_2 ) -> V_31 [ 0 ] ;
return F_2 ( V_2 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
# include "inffixed.h"
V_4 -> V_18 = V_32 ;
V_4 -> V_33 = 9 ;
V_4 -> V_19 = V_34 ;
V_4 -> V_35 = 5 ;
}
static void F_6 ( T_1 V_2 , unsigned V_36 )
{
struct V_3 * V_4 ;
unsigned V_37 , V_38 ;
V_4 = (struct V_3 * ) V_2 -> V_4 ;
V_37 = V_36 - V_2 -> V_39 ;
if ( V_37 >= V_4 -> V_22 ) {
memcpy ( V_4 -> V_30 , V_2 -> V_40 - V_4 -> V_22 , V_4 -> V_22 ) ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_4 -> V_22 ;
}
else {
V_38 = V_4 -> V_22 - V_4 -> V_24 ;
if ( V_38 > V_37 ) V_38 = V_37 ;
memcpy ( V_4 -> V_30 + V_4 -> V_24 , V_2 -> V_40 - V_37 , V_38 ) ;
V_37 -= V_38 ;
if ( V_37 ) {
memcpy ( V_4 -> V_30 , V_2 -> V_40 - V_37 , V_37 ) ;
V_4 -> V_24 = V_37 ;
V_4 -> V_25 = V_4 -> V_22 ;
}
else {
V_4 -> V_24 += V_38 ;
if ( V_4 -> V_24 == V_4 -> V_22 ) V_4 -> V_24 = 0 ;
if ( V_4 -> V_25 < V_4 -> V_22 ) V_4 -> V_25 += V_38 ;
}
}
}
static int F_7 ( T_1 V_2 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL || V_2 -> V_4 == NULL ) return V_5 ;
V_4 = (struct V_3 * ) V_2 -> V_4 ;
if ( V_4 -> V_11 == V_41 && V_4 -> V_17 == 0 ) {
V_4 -> V_11 = TYPE ;
return V_26 ;
}
return V_42 ;
}
int F_8 ( T_1 V_2 , int V_43 )
{
struct V_3 * V_4 ;
const unsigned char * V_20 ;
unsigned char * V_44 ;
unsigned V_45 , V_46 ;
unsigned long V_16 ;
unsigned V_17 ;
unsigned V_47 , V_36 ;
unsigned V_37 ;
unsigned char * V_48 ;
T_2 V_49 ;
T_2 V_13 ;
unsigned V_50 ;
int V_51 ;
static const unsigned short V_52 [ 19 ] =
{ 16 , 17 , 18 , 0 , 8 , 7 , 9 , 6 , 10 , 5 , 11 , 4 , 12 , 3 , 13 , 2 , 14 , 1 , 15 } ;
if ( V_2 == NULL || V_2 -> V_4 == NULL ||
( V_2 -> V_53 == NULL && V_2 -> V_54 != 0 ) )
return V_5 ;
V_4 = (struct V_3 * ) V_2 -> V_4 ;
if ( V_4 -> V_11 == TYPE ) V_4 -> V_11 = V_55 ;
F_9 () ;
V_47 = V_45 ;
V_36 = V_46 ;
V_51 = V_26 ;
for (; ; )
switch ( V_4 -> V_11 ) {
case V_12 :
if ( V_4 -> V_29 == 0 ) {
V_4 -> V_11 = V_55 ;
break;
}
F_10 ( 16 ) ;
if (
( ( F_11 ( 8 ) << 8 ) + ( V_16 >> 8 ) ) % 31 ) {
V_2 -> V_9 = ( char * ) L_1 ;
V_4 -> V_11 = V_56 ;
break;
}
if ( F_11 ( 4 ) != V_57 ) {
V_2 -> V_9 = ( char * ) L_2 ;
V_4 -> V_11 = V_56 ;
break;
}
F_12 ( 4 ) ;
V_50 = F_11 ( 4 ) + 8 ;
if ( V_50 > V_4 -> V_23 ) {
V_2 -> V_9 = ( char * ) L_3 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_15 = 1U << V_50 ;
V_2 -> V_10 = V_4 -> V_58 = F_13 ( 0L , NULL , 0 ) ;
V_4 -> V_11 = V_16 & 0x200 ? V_59 : TYPE ;
F_14 () ;
break;
case V_59 :
F_10 ( 32 ) ;
V_2 -> V_10 = V_4 -> V_58 = F_15 ( V_16 ) ;
F_14 () ;
V_4 -> V_11 = V_60 ;
case V_60 :
if ( V_4 -> V_14 == 0 ) {
F_16 () ;
return V_61 ;
}
V_2 -> V_10 = V_4 -> V_58 = F_13 ( 0L , NULL , 0 ) ;
V_4 -> V_11 = TYPE ;
case TYPE :
if ( V_43 == V_62 ) goto V_63;
case V_55 :
if ( V_4 -> V_13 ) {
F_17 () ;
V_4 -> V_11 = V_64 ;
break;
}
F_10 ( 3 ) ;
V_4 -> V_13 = F_11 ( 1 ) ;
F_12 ( 1 ) ;
switch ( F_11 ( 2 ) ) {
case 0 :
V_4 -> V_11 = V_41 ;
break;
case 1 :
F_5 ( V_4 ) ;
V_4 -> V_11 = V_65 ;
break;
case 2 :
V_4 -> V_11 = V_66 ;
break;
case 3 :
V_2 -> V_9 = ( char * ) L_4 ;
V_4 -> V_11 = V_56 ;
}
F_12 ( 2 ) ;
break;
case V_41 :
F_17 () ;
F_10 ( 32 ) ;
if ( ( V_16 & 0xffff ) != ( ( V_16 >> 16 ) ^ 0xffff ) ) {
V_2 -> V_9 = ( char * ) L_5 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_67 = ( unsigned ) V_16 & 0xffff ;
F_14 () ;
V_4 -> V_11 = V_68 ;
case V_68 :
V_37 = V_4 -> V_67 ;
if ( V_37 ) {
if ( V_37 > V_45 ) V_37 = V_45 ;
if ( V_37 > V_46 ) V_37 = V_46 ;
if ( V_37 == 0 ) goto V_63;
memcpy ( V_44 , V_20 , V_37 ) ;
V_45 -= V_37 ;
V_20 += V_37 ;
V_46 -= V_37 ;
V_44 += V_37 ;
V_4 -> V_67 -= V_37 ;
break;
}
V_4 -> V_11 = TYPE ;
break;
case V_66 :
F_10 ( 14 ) ;
V_4 -> V_69 = F_11 ( 5 ) + 257 ;
F_12 ( 5 ) ;
V_4 -> V_70 = F_11 ( 5 ) + 1 ;
F_12 ( 5 ) ;
V_4 -> V_71 = F_11 ( 4 ) + 4 ;
F_12 ( 4 ) ;
#ifndef F_18
if ( V_4 -> V_69 > 286 || V_4 -> V_70 > 30 ) {
V_2 -> V_9 = ( char * ) L_6 ;
V_4 -> V_11 = V_56 ;
break;
}
#endif
V_4 -> V_45 = 0 ;
V_4 -> V_11 = V_72 ;
case V_72 :
while ( V_4 -> V_45 < V_4 -> V_71 ) {
F_10 ( 3 ) ;
V_4 -> V_73 [ V_52 [ V_4 -> V_45 ++ ] ] = ( unsigned short ) F_11 ( 3 ) ;
F_12 ( 3 ) ;
}
while ( V_4 -> V_45 < 19 )
V_4 -> V_73 [ V_52 [ V_4 -> V_45 ++ ] ] = 0 ;
V_4 -> V_20 = V_4 -> V_21 ;
V_4 -> V_18 = ( T_2 const * ) ( V_4 -> V_20 ) ;
V_4 -> V_33 = 7 ;
V_51 = F_19 ( V_74 , V_4 -> V_73 , 19 , & ( V_4 -> V_20 ) ,
& ( V_4 -> V_33 ) , V_4 -> V_75 ) ;
if ( V_51 ) {
V_2 -> V_9 = ( char * ) L_7 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_45 = 0 ;
V_4 -> V_11 = V_76 ;
case V_76 :
while ( V_4 -> V_45 < V_4 -> V_69 + V_4 -> V_70 ) {
for (; ; ) {
V_49 = V_4 -> V_18 [ F_11 ( V_4 -> V_33 ) ] ;
if ( ( unsigned ) ( V_49 . V_17 ) <= V_17 ) break;
F_20 () ;
}
if ( V_49 . V_77 < 16 ) {
F_10 ( V_49 . V_17 ) ;
F_12 ( V_49 . V_17 ) ;
V_4 -> V_73 [ V_4 -> V_45 ++ ] = V_49 . V_77 ;
}
else {
if ( V_49 . V_77 == 16 ) {
F_10 ( V_49 . V_17 + 2 ) ;
F_12 ( V_49 . V_17 ) ;
if ( V_4 -> V_45 == 0 ) {
V_2 -> V_9 = ( char * ) L_8 ;
V_4 -> V_11 = V_56 ;
break;
}
V_50 = V_4 -> V_73 [ V_4 -> V_45 - 1 ] ;
V_37 = 3 + F_11 ( 2 ) ;
F_12 ( 2 ) ;
}
else if ( V_49 . V_77 == 17 ) {
F_10 ( V_49 . V_17 + 3 ) ;
F_12 ( V_49 . V_17 ) ;
V_50 = 0 ;
V_37 = 3 + F_11 ( 3 ) ;
F_12 ( 3 ) ;
}
else {
F_10 ( V_49 . V_17 + 7 ) ;
F_12 ( V_49 . V_17 ) ;
V_50 = 0 ;
V_37 = 11 + F_11 ( 7 ) ;
F_12 ( 7 ) ;
}
if ( V_4 -> V_45 + V_37 > V_4 -> V_69 + V_4 -> V_70 ) {
V_2 -> V_9 = ( char * ) L_8 ;
V_4 -> V_11 = V_56 ;
break;
}
while ( V_37 -- )
V_4 -> V_73 [ V_4 -> V_45 ++ ] = ( unsigned short ) V_50 ;
}
}
if ( V_4 -> V_11 == V_56 ) break;
V_4 -> V_20 = V_4 -> V_21 ;
V_4 -> V_18 = ( T_2 const * ) ( V_4 -> V_20 ) ;
V_4 -> V_33 = 9 ;
V_51 = F_19 ( V_78 , V_4 -> V_73 , V_4 -> V_69 , & ( V_4 -> V_20 ) ,
& ( V_4 -> V_33 ) , V_4 -> V_75 ) ;
if ( V_51 ) {
V_2 -> V_9 = ( char * ) L_9 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_19 = ( T_2 const * ) ( V_4 -> V_20 ) ;
V_4 -> V_35 = 6 ;
V_51 = F_19 ( V_79 , V_4 -> V_73 + V_4 -> V_69 , V_4 -> V_70 ,
& ( V_4 -> V_20 ) , & ( V_4 -> V_35 ) , V_4 -> V_75 ) ;
if ( V_51 ) {
V_2 -> V_9 = ( char * ) L_10 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_11 = V_65 ;
case V_65 :
if ( V_45 >= 6 && V_46 >= 258 ) {
F_16 () ;
F_21 ( V_2 , V_36 ) ;
F_9 () ;
break;
}
for (; ; ) {
V_49 = V_4 -> V_18 [ F_11 ( V_4 -> V_33 ) ] ;
if ( ( unsigned ) ( V_49 . V_17 ) <= V_17 ) break;
F_20 () ;
}
if ( V_49 . V_80 && ( V_49 . V_80 & 0xf0 ) == 0 ) {
V_13 = V_49 ;
for (; ; ) {
V_49 = V_4 -> V_18 [ V_13 . V_77 +
( F_11 ( V_13 . V_17 + V_13 . V_80 ) >> V_13 . V_17 ) ] ;
if ( ( unsigned ) ( V_13 . V_17 + V_49 . V_17 ) <= V_17 ) break;
F_20 () ;
}
F_12 ( V_13 . V_17 ) ;
}
F_12 ( V_49 . V_17 ) ;
V_4 -> V_67 = ( unsigned ) V_49 . V_77 ;
if ( ( int ) ( V_49 . V_80 ) == 0 ) {
V_4 -> V_11 = V_81 ;
break;
}
if ( V_49 . V_80 & 32 ) {
V_4 -> V_11 = TYPE ;
break;
}
if ( V_49 . V_80 & 64 ) {
V_2 -> V_9 = ( char * ) L_11 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_82 = ( unsigned ) ( V_49 . V_80 ) & 15 ;
V_4 -> V_11 = V_83 ;
case V_83 :
if ( V_4 -> V_82 ) {
F_10 ( V_4 -> V_82 ) ;
V_4 -> V_67 += F_11 ( V_4 -> V_82 ) ;
F_12 ( V_4 -> V_82 ) ;
}
V_4 -> V_11 = V_84 ;
case V_84 :
for (; ; ) {
V_49 = V_4 -> V_19 [ F_11 ( V_4 -> V_35 ) ] ;
if ( ( unsigned ) ( V_49 . V_17 ) <= V_17 ) break;
F_20 () ;
}
if ( ( V_49 . V_80 & 0xf0 ) == 0 ) {
V_13 = V_49 ;
for (; ; ) {
V_49 = V_4 -> V_19 [ V_13 . V_77 +
( F_11 ( V_13 . V_17 + V_13 . V_80 ) >> V_13 . V_17 ) ] ;
if ( ( unsigned ) ( V_13 . V_17 + V_49 . V_17 ) <= V_17 ) break;
F_20 () ;
}
F_12 ( V_13 . V_17 ) ;
}
F_12 ( V_49 . V_17 ) ;
if ( V_49 . V_80 & 64 ) {
V_2 -> V_9 = ( char * ) L_12 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_85 = ( unsigned ) V_49 . V_77 ;
V_4 -> V_82 = ( unsigned ) ( V_49 . V_80 ) & 15 ;
V_4 -> V_11 = V_86 ;
case V_86 :
if ( V_4 -> V_82 ) {
F_10 ( V_4 -> V_82 ) ;
V_4 -> V_85 += F_11 ( V_4 -> V_82 ) ;
F_12 ( V_4 -> V_82 ) ;
}
#ifdef F_22
if ( V_4 -> V_85 > V_4 -> V_15 ) {
V_2 -> V_9 = ( char * ) L_13 ;
V_4 -> V_11 = V_56 ;
break;
}
#endif
if ( V_4 -> V_85 > V_4 -> V_25 + V_36 - V_46 ) {
V_2 -> V_9 = ( char * ) L_13 ;
V_4 -> V_11 = V_56 ;
break;
}
V_4 -> V_11 = V_87 ;
case V_87 :
if ( V_46 == 0 ) goto V_63;
V_37 = V_36 - V_46 ;
if ( V_4 -> V_85 > V_37 ) {
V_37 = V_4 -> V_85 - V_37 ;
if ( V_37 > V_4 -> V_24 ) {
V_37 -= V_4 -> V_24 ;
V_48 = V_4 -> V_30 + ( V_4 -> V_22 - V_37 ) ;
}
else
V_48 = V_4 -> V_30 + ( V_4 -> V_24 - V_37 ) ;
if ( V_37 > V_4 -> V_67 ) V_37 = V_4 -> V_67 ;
}
else {
V_48 = V_44 - V_4 -> V_85 ;
V_37 = V_4 -> V_67 ;
}
if ( V_37 > V_46 ) V_37 = V_46 ;
V_46 -= V_37 ;
V_4 -> V_67 -= V_37 ;
do {
* V_44 ++ = * V_48 ++ ;
} while ( -- V_37 );
if ( V_4 -> V_67 == 0 ) V_4 -> V_11 = V_65 ;
break;
case V_81 :
if ( V_46 == 0 ) goto V_63;
* V_44 ++ = ( unsigned char ) ( V_4 -> V_67 ) ;
V_46 -- ;
V_4 -> V_11 = V_65 ;
break;
case V_64 :
if ( V_4 -> V_29 ) {
F_10 ( 32 ) ;
V_36 -= V_46 ;
V_2 -> V_7 += V_36 ;
V_4 -> V_8 += V_36 ;
if ( V_36 )
V_2 -> V_10 = V_4 -> V_58 =
F_23 ( V_4 -> V_58 , V_44 - V_36 , V_36 ) ;
V_36 = V_46 ;
if ( (
F_15 ( V_16 ) ) != V_4 -> V_58 ) {
V_2 -> V_9 = ( char * ) L_14 ;
V_4 -> V_11 = V_56 ;
break;
}
F_14 () ;
}
V_4 -> V_11 = V_88 ;
case V_88 :
V_51 = V_89 ;
goto V_63;
case V_56 :
V_51 = V_42 ;
goto V_63;
case V_90 :
return V_91 ;
case V_92 :
default:
return V_5 ;
}
V_63:
F_16 () ;
if ( V_4 -> V_22 || ( V_4 -> V_11 < V_64 && V_36 != V_2 -> V_39 ) )
F_6 ( V_2 , V_36 ) ;
V_47 -= V_2 -> V_54 ;
V_36 -= V_2 -> V_39 ;
V_2 -> V_6 += V_47 ;
V_2 -> V_7 += V_36 ;
V_4 -> V_8 += V_36 ;
if ( V_4 -> V_29 && V_36 )
V_2 -> V_10 = V_4 -> V_58 =
F_23 ( V_4 -> V_58 , V_2 -> V_40 - V_36 , V_36 ) ;
V_2 -> V_93 = V_4 -> V_17 + ( V_4 -> V_13 ? 64 : 0 ) +
( V_4 -> V_11 == TYPE ? 128 : 0 ) ;
if ( V_43 == V_94 && V_51 == V_26 &&
V_2 -> V_39 != 0 && V_2 -> V_54 == 0 )
return F_7 ( V_2 ) ;
if ( ( ( V_47 == 0 && V_36 == 0 ) || V_43 == V_95 ) && V_51 == V_26 )
V_51 = V_96 ;
return V_51 ;
}
int F_24 ( T_1 V_2 )
{
if ( V_2 == NULL || V_2 -> V_4 == NULL )
return V_5 ;
return V_26 ;
}
int F_25 ( T_3 * V_97 )
{
struct V_3 * V_4 = (struct V_3 * ) V_97 -> V_4 ;
T_4 * V_98 = V_97 -> V_40 ;
T_5 V_99 = V_97 -> V_39 ;
if ( V_4 -> V_11 != TYPE && V_4 -> V_11 != V_12 )
return V_42 ;
V_97 -> V_39 = 0 ;
V_97 -> V_40 = ( unsigned char * ) V_97 -> V_53 + V_97 -> V_54 ;
F_6 ( V_97 , V_97 -> V_54 ) ;
V_97 -> V_39 = V_99 ;
V_97 -> V_40 = V_98 ;
V_97 -> V_10 = V_4 -> V_58 =
F_23 ( V_4 -> V_58 , V_97 -> V_53 , V_97 -> V_54 ) ;
V_97 -> V_7 += V_97 -> V_54 ;
V_97 -> V_6 += V_97 -> V_54 ;
V_97 -> V_53 += V_97 -> V_54 ;
V_4 -> V_8 += V_97 -> V_54 ;
V_97 -> V_54 = 0 ;
return V_26 ;
}
