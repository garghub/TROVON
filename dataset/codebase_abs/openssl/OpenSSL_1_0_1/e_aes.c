static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_6 = V_1 -> V_9 -> V_10 & V_11 ;
if ( ( V_6 == V_12 || V_6 == V_13 )
&& ! V_4 )
{
V_5 = F_2 ( V_2 , V_1 -> V_14 * 8 , V_1 -> V_8 ) ;
V_7 -> V_15 = ( V_16 ) V_17 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_21 :
NULL ;
}
else {
V_5 = F_3 ( V_2 , V_1 -> V_14 * 8 , V_1 -> V_8 ) ;
V_7 -> V_15 = ( V_16 ) V_22 ;
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) V_21 ;
else if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_26 ;
else
V_7 -> V_18 . V_19 = NULL ;
}
if( V_5 < 0 )
{
F_4 ( V_27 , V_28 ) ;
return 0 ;
}
return 1 ;
}
static int F_5 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
V_21 ( V_30 , V_29 , V_31 , V_1 -> V_8 , V_1 -> V_3 , V_1 -> V_32 ) ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_3 V_33 = V_1 -> V_9 -> V_34 ;
if ( V_31 < V_33 ) return 1 ;
F_7 ( V_30 , V_29 , V_31 , V_1 -> V_8 , V_1 -> V_32 ) ;
return 1 ;
}
static int F_8 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
{
F_3 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_22 ) ;
V_35 -> V_24 = ( V_25 ) V_26 ;
if ( V_3 == NULL && V_35 -> V_38 )
V_3 = V_35 -> V_3 ;
if ( V_3 )
{
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
}
V_35 -> V_40 = 1 ;
}
else
{
if ( V_35 -> V_40 )
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
else
memcpy ( V_35 -> V_3 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
V_35 -> V_41 = 0 ;
}
return 1 ;
}
static int F_11 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_42 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
{
if ( V_4 )
{
F_3 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_22 ;
V_42 -> V_18 = V_46 ;
}
else
{
F_2 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_17 ;
V_42 -> V_18 = V_47 ;
}
F_3 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_22 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
}
if ( V_3 )
{
V_42 -> V_44 . V_51 = & V_42 -> V_48 ;
memcpy ( V_1 -> V_3 , V_3 , 16 ) ;
}
return 1 ;
}
static int F_12 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_52 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
{
F_3 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_22 ) ;
V_52 -> V_56 = V_4 ? ( V_57 ) V_58 :
( V_57 ) V_59 ;
V_52 -> V_40 = 1 ;
}
if ( V_3 )
{
memcpy ( V_1 -> V_3 , V_3 , 15 - V_52 -> V_55 ) ;
V_52 -> V_38 = 1 ;
}
return 1 ;
}
static int F_14 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_6 = V_1 -> V_9 -> V_10 & V_11 ;
if ( ( V_6 == V_12 || V_6 == V_13 )
&& ! V_4 )
#ifdef F_15
if ( F_15 && V_6 == V_13 )
{
V_5 = F_16 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_60 ;
V_7 -> V_18 . V_19 = ( V_20 ) V_61 ;
}
else
#endif
#ifdef F_17
if ( F_17 )
{
V_5 = F_18 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_62 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_63 :
NULL ;
}
else
#endif
{
V_5 = F_16 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_60 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_64 :
NULL ;
}
else
#ifdef F_15
if ( F_15 && V_6 == V_23 )
{
V_5 = F_19 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_65 ;
V_7 -> V_18 . V_24 = ( V_25 ) V_66 ;
}
else
#endif
#ifdef F_17
if ( F_17 )
{
V_5 = F_20 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_67 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_63 :
NULL ;
}
else
#endif
{
V_5 = F_19 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_65 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_64 :
NULL ;
#ifdef F_21
if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_68 ;
#endif
}
if( V_5 < 0 )
{
F_4 ( V_69 , V_28 ) ;
return 0 ;
}
return 1 ;
}
static int F_22 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_7 -> V_18 . V_19 )
(* V_7 -> V_18 . V_19 )( V_30 , V_29 , V_31 , & V_7 -> V_36 , V_1 -> V_3 , V_1 -> V_32 ) ;
else if ( V_1 -> V_32 )
F_23 ( V_30 , V_29 , V_31 , & V_7 -> V_36 , V_1 -> V_3 , V_7 -> V_15 ) ;
else
F_23 ( V_30 , V_29 , V_31 , & V_7 -> V_36 , V_1 -> V_3 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_24 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_3 V_33 = V_1 -> V_9 -> V_34 ;
T_3 V_70 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_31 < V_33 ) return 1 ;
for ( V_70 = 0 , V_31 -= V_33 ; V_70 <= V_31 ; V_70 += V_33 )
(* V_7 -> V_15 )( V_30 + V_70 , V_29 + V_70 , & V_7 -> V_36 ) ;
return 1 ;
}
static int F_25 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
F_26 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_71 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_27 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
F_28 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_71 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_29 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
F_30 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_71 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_31 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_1 -> V_10 & V_72 ) {
F_32 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_71 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
while ( V_31 >= V_73 ) {
F_32 ( V_30 , V_29 , V_73 * 8 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_71 , V_1 -> V_32 , V_7 -> V_15 ) ;
V_31 -= V_73 ;
}
if ( V_31 )
F_32 ( V_30 , V_29 , V_31 * 8 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_71 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_33 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
unsigned int V_71 = V_1 -> V_71 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_7 -> V_18 . V_24 )
F_34 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , V_1 -> V_74 , & V_71 , V_7 -> V_18 . V_24 ) ;
else
F_35 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , V_1 -> V_74 , & V_71 , V_7 -> V_15 ) ;
V_1 -> V_71 = ( T_3 ) V_71 ;
return 1 ;
}
static int F_36 ( T_1 * V_75 )
{
T_4 * V_35 = V_75 -> V_8 ;
F_37 ( & V_35 -> V_37 , sizeof( V_35 -> V_37 ) ) ;
if ( V_35 -> V_3 != V_75 -> V_3 )
F_38 ( V_35 -> V_3 ) ;
return 1 ;
}
static void F_39 ( unsigned char * V_76 ) {
int V_77 = 8 ;
unsigned char V_75 ;
do {
-- V_77 ;
V_75 = V_76 [ V_77 ] ;
++ V_75 ;
V_76 [ V_77 ] = V_75 ;
if ( V_75 ) return;
} while ( V_77 );
}
static int F_40 ( T_1 * V_75 , int type , int V_78 , void * V_79 )
{
T_4 * V_35 = V_75 -> V_8 ;
switch ( type )
{
case V_80 :
V_35 -> V_40 = 0 ;
V_35 -> V_38 = 0 ;
V_35 -> V_39 = V_75 -> V_9 -> V_81 ;
V_35 -> V_3 = V_75 -> V_3 ;
V_35 -> V_82 = - 1 ;
V_35 -> V_41 = 0 ;
V_35 -> V_83 = - 1 ;
return 1 ;
case V_84 :
if ( V_78 <= 0 )
return 0 ;
#ifdef F_41
if ( F_42 () && ! ( V_75 -> V_10 & V_85 )
&& V_78 < 12 )
return 0 ;
#endif
if ( ( V_78 > V_86 ) && ( V_78 > V_35 -> V_39 ) )
{
if ( V_35 -> V_3 != V_75 -> V_3 )
F_38 ( V_35 -> V_3 ) ;
V_35 -> V_3 = F_43 ( V_78 ) ;
if ( ! V_35 -> V_3 )
return 0 ;
}
V_35 -> V_39 = V_78 ;
return 1 ;
case V_87 :
if ( V_78 <= 0 || V_78 > 16 || V_75 -> V_32 )
return 0 ;
memcpy ( V_75 -> V_74 , V_79 , V_78 ) ;
V_35 -> V_82 = V_78 ;
return 1 ;
case V_88 :
if ( V_78 <= 0 || V_78 > 16 || ! V_75 -> V_32 || V_35 -> V_82 < 0 )
return 0 ;
memcpy ( V_79 , V_75 -> V_74 , V_78 ) ;
return 1 ;
case V_89 :
if ( V_78 == - 1 )
{
memcpy ( V_35 -> V_3 , V_79 , V_35 -> V_39 ) ;
V_35 -> V_41 = 1 ;
return 1 ;
}
if ( ( V_78 < 4 ) || ( V_35 -> V_39 - V_78 ) < 8 )
return 0 ;
if ( V_78 )
memcpy ( V_35 -> V_3 , V_79 , V_78 ) ;
if ( V_75 -> V_32 &&
F_44 ( V_35 -> V_3 + V_78 , V_35 -> V_39 - V_78 ) <= 0 )
return 0 ;
V_35 -> V_41 = 1 ;
return 1 ;
case V_90 :
if ( V_35 -> V_41 == 0 || V_35 -> V_40 == 0 )
return 0 ;
F_10 ( & V_35 -> V_37 , V_35 -> V_3 , V_35 -> V_39 ) ;
if ( V_78 <= 0 || V_78 > V_35 -> V_39 )
V_78 = V_35 -> V_39 ;
memcpy ( V_79 , V_35 -> V_3 + V_35 -> V_39 - V_78 , V_78 ) ;
F_39 ( V_35 -> V_3 + V_35 -> V_39 - 8 ) ;
V_35 -> V_38 = 1 ;
return 1 ;
case V_91 :
if ( V_35 -> V_41 == 0 || V_35 -> V_40 == 0 || V_75 -> V_32 )
return 0 ;
memcpy ( V_35 -> V_3 + V_35 -> V_39 - V_78 , V_79 , V_78 ) ;
F_10 ( & V_35 -> V_37 , V_35 -> V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
return 1 ;
case V_92 :
if ( V_78 != 13 )
return 0 ;
memcpy ( V_75 -> V_74 , V_79 , V_78 ) ;
V_35 -> V_83 = V_78 ;
{
unsigned int V_31 = V_75 -> V_74 [ V_78 - 2 ] << 8 | V_75 -> V_74 [ V_78 - 1 ] ;
V_31 -= V_93 ;
if ( ! V_75 -> V_32 )
V_31 -= V_94 ;
V_75 -> V_74 [ V_78 - 2 ] = V_31 >> 8 ;
V_75 -> V_74 [ V_78 - 1 ] = V_31 & 0xff ;
}
return V_94 ;
default:
return - 1 ;
}
}
static int F_45 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
{ do {
#ifdef F_15
if ( F_15 )
{
F_19 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_65 ) ;
V_35 -> V_24 = ( V_25 ) V_66 ;
break;
}
else
#endif
#ifdef F_17
if ( F_17 )
{
F_20 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_67 ) ;
V_35 -> V_24 = NULL ;
break;
}
#endif
F_19 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 , ( V_16 ) V_65 ) ;
#ifdef F_21
V_35 -> V_24 = ( V_25 ) V_68 ;
#else
V_35 -> V_24 = NULL ;
#endif
} while ( 0 );
if ( V_3 == NULL && V_35 -> V_38 )
V_3 = V_35 -> V_3 ;
if ( V_3 )
{
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
}
V_35 -> V_40 = 1 ;
}
else
{
if ( V_35 -> V_40 )
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
else
memcpy ( V_35 -> V_3 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
V_35 -> V_41 = 0 ;
}
return 1 ;
}
static int F_46 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_4 * V_35 = V_1 -> V_8 ;
int V_95 = - 1 ;
if ( V_29 != V_30 || V_31 < ( V_93 + V_94 ) )
return - 1 ;
if ( F_47 ( V_1 , V_1 -> V_32 ?
V_90 : V_91 ,
V_93 , V_29 ) <= 0 )
goto V_96;
if ( F_48 ( & V_35 -> V_37 , V_1 -> V_74 , V_35 -> V_83 ) )
goto V_96;
V_30 += V_93 ;
V_29 += V_93 ;
V_31 -= V_93 + V_94 ;
if ( V_1 -> V_32 )
{
if ( V_35 -> V_24 )
{
if ( F_49 ( & V_35 -> V_37 ,
V_30 , V_29 , V_31 ,
V_35 -> V_24 ) )
goto V_96;
}
else {
if ( F_50 ( & V_35 -> V_37 , V_30 , V_29 , V_31 ) )
goto V_96;
}
V_29 += V_31 ;
F_51 ( & V_35 -> V_37 , V_29 , V_94 ) ;
V_95 = V_31 + V_93 + V_94 ;
}
else
{
if ( V_35 -> V_24 )
{
if ( F_52 ( & V_35 -> V_37 ,
V_30 , V_29 , V_31 ,
V_35 -> V_24 ) )
goto V_96;
}
else {
if ( F_53 ( & V_35 -> V_37 , V_30 , V_29 , V_31 ) )
goto V_96;
}
F_51 ( & V_35 -> V_37 , V_1 -> V_74 ,
V_94 ) ;
if ( memcmp ( V_1 -> V_74 , V_30 + V_31 , V_94 ) )
{
F_37 ( V_29 , V_31 ) ;
goto V_96;
}
V_95 = V_31 ;
}
V_96:
V_35 -> V_38 = 0 ;
V_35 -> V_83 = - 1 ;
return V_95 ;
}
static int F_54 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_35 -> V_40 )
return - 1 ;
if ( V_35 -> V_83 >= 0 )
return F_46 ( V_1 , V_29 , V_30 , V_31 ) ;
if ( ! V_35 -> V_38 )
return - 1 ;
if ( ! V_1 -> V_32 && V_35 -> V_82 < 0 )
return - 1 ;
if ( V_30 )
{
if ( V_29 == NULL )
{
if ( F_48 ( & V_35 -> V_37 , V_30 , V_31 ) )
return - 1 ;
}
else if ( V_1 -> V_32 )
{
if ( V_35 -> V_24 )
{
if ( F_49 ( & V_35 -> V_37 ,
V_30 , V_29 , V_31 ,
V_35 -> V_24 ) )
return - 1 ;
}
else {
if ( F_50 ( & V_35 -> V_37 , V_30 , V_29 , V_31 ) )
return - 1 ;
}
}
else
{
if ( V_35 -> V_24 )
{
if ( F_52 ( & V_35 -> V_37 ,
V_30 , V_29 , V_31 ,
V_35 -> V_24 ) )
return - 1 ;
}
else {
if ( F_53 ( & V_35 -> V_37 , V_30 , V_29 , V_31 ) )
return - 1 ;
}
}
return V_31 ;
}
else
{
if ( ! V_1 -> V_32 )
{
if ( F_55 ( & V_35 -> V_37 ,
V_1 -> V_74 , V_35 -> V_82 ) != 0 )
return - 1 ;
V_35 -> V_38 = 0 ;
return 0 ;
}
F_51 ( & V_35 -> V_37 , V_1 -> V_74 , 16 ) ;
V_35 -> V_82 = 16 ;
V_35 -> V_38 = 0 ;
return 0 ;
}
}
static int F_56 ( T_1 * V_75 , int type , int V_78 , void * V_79 )
{
T_5 * V_42 = V_75 -> V_8 ;
if ( type != V_80 )
return - 1 ;
V_42 -> V_44 . V_50 = NULL ;
V_42 -> V_44 . V_51 = NULL ;
return 1 ;
}
static int F_57 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_42 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) do
{
#ifdef F_58
V_42 -> V_18 = V_4 ? V_97 : V_98 ;
#else
V_42 -> V_18 = NULL ;
#endif
#ifdef F_15
if ( F_15 )
V_42 -> V_18 = V_4 ? V_99 : V_100 ;
else
#endif
#ifdef F_17
if ( F_17 )
{
if ( V_4 )
{
F_20 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_67 ;
}
else
{
F_18 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_62 ;
}
F_20 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_67 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
break;
}
#endif
if ( V_4 )
{
F_19 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_65 ;
}
else
{
F_16 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_60 ;
}
F_19 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_65 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
} while ( 0 );
if ( V_3 )
{
V_42 -> V_44 . V_51 = & V_42 -> V_48 ;
memcpy ( V_1 -> V_3 , V_3 , 16 ) ;
}
return 1 ;
}
static int F_59 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_5 * V_42 = V_1 -> V_8 ;
if ( ! V_42 -> V_44 . V_50 || ! V_42 -> V_44 . V_51 )
return 0 ;
if ( ! V_29 || ! V_30 || V_31 < V_101 )
return 0 ;
#ifdef F_41
if ( F_42 () && ! ( V_1 -> V_10 & V_85 ) &&
( V_31 > ( 1UL << 20 ) * 16 ) )
{
F_4 ( V_102 , V_103 ) ;
return 0 ;
}
#endif
if ( V_42 -> V_18 )
(* V_42 -> V_18 )( V_30 , V_29 , V_31 ,
V_42 -> V_44 . V_50 , V_42 -> V_44 . V_51 , V_1 -> V_3 ) ;
else if ( F_60 ( & V_42 -> V_44 , V_1 -> V_3 , V_30 , V_29 , V_31 ,
V_1 -> V_32 ) )
return 0 ;
return 1 ;
}
static int F_61 ( T_1 * V_75 , int type , int V_78 , void * V_79 )
{
T_6 * V_52 = V_75 -> V_8 ;
switch ( type )
{
case V_80 :
V_52 -> V_40 = 0 ;
V_52 -> V_38 = 0 ;
V_52 -> V_55 = 8 ;
V_52 -> V_54 = 12 ;
V_52 -> V_104 = 0 ;
V_52 -> V_105 = 0 ;
return 1 ;
case V_106 :
V_78 = 15 - V_78 ;
case V_107 :
if ( V_78 < 2 || V_78 > 8 )
return 0 ;
V_52 -> V_55 = V_78 ;
return 1 ;
case V_108 :
if ( ( V_78 & 1 ) || V_78 < 4 || V_78 > 16 )
return 0 ;
if ( ( V_75 -> V_32 && V_79 ) || ( ! V_75 -> V_32 && ! V_79 ) )
return 0 ;
if ( V_79 )
{
V_52 -> V_104 = 1 ;
memcpy ( V_75 -> V_74 , V_79 , V_78 ) ;
}
V_52 -> V_54 = V_78 ;
return 1 ;
case V_109 :
if ( ! V_75 -> V_32 || ! V_52 -> V_104 )
return 0 ;
if( ! F_62 ( & V_52 -> V_53 , V_79 , ( T_3 ) V_78 ) )
return 0 ;
V_52 -> V_104 = 0 ;
V_52 -> V_38 = 0 ;
V_52 -> V_105 = 0 ;
return 1 ;
default:
return - 1 ;
}
}
static int F_63 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_52 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) do
{
#ifdef F_17
if ( F_17 )
{
F_20 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_67 ) ;
V_52 -> V_40 = 1 ;
break;
}
#endif
F_19 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_65 ) ;
V_52 -> V_56 = NULL ;
V_52 -> V_40 = 1 ;
} while ( 0 );
if ( V_3 )
{
memcpy ( V_1 -> V_3 , V_3 , 15 - V_52 -> V_55 ) ;
V_52 -> V_38 = 1 ;
}
return 1 ;
}
static int F_64 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_6 * V_52 = V_1 -> V_8 ;
T_7 * V_53 = & V_52 -> V_53 ;
if ( ! V_52 -> V_38 && ! V_52 -> V_40 )
return - 1 ;
if ( ! V_1 -> V_32 && ! V_52 -> V_104 )
return - 1 ;
if ( ! V_29 )
{
if ( ! V_30 )
{
if ( F_65 ( V_53 , V_1 -> V_3 , 15 - V_52 -> V_55 , V_31 ) )
return - 1 ;
V_52 -> V_105 = 1 ;
return V_31 ;
}
if ( ! V_52 -> V_105 && V_31 )
return - 1 ;
F_66 ( V_53 , V_30 , V_31 ) ;
return V_31 ;
}
if ( ! V_30 )
return 0 ;
if ( ! V_52 -> V_105 )
{
if ( F_65 ( V_53 , V_1 -> V_3 , 15 - V_52 -> V_55 , V_31 ) )
return - 1 ;
V_52 -> V_105 = 1 ;
}
if ( V_1 -> V_32 )
{
if ( V_52 -> V_56 ? F_67 ( V_53 , V_30 , V_29 , V_31 ,
V_52 -> V_56 ) :
F_68 ( V_53 , V_30 , V_29 , V_31 ) )
return - 1 ;
V_52 -> V_104 = 1 ;
return V_31 ;
}
else
{
int V_95 = - 1 ;
if ( V_52 -> V_56 ? ! F_69 ( V_53 , V_30 , V_29 , V_31 ,
V_52 -> V_56 ) :
! F_70 ( V_53 , V_30 , V_29 , V_31 ) )
{
unsigned char V_110 [ 16 ] ;
if ( F_62 ( V_53 , V_110 , V_52 -> V_54 ) )
{
if ( ! memcmp ( V_110 , V_1 -> V_74 , V_52 -> V_54 ) )
V_95 = V_31 ;
}
}
if ( V_95 == - 1 )
F_37 ( V_29 , V_31 ) ;
V_52 -> V_38 = 0 ;
V_52 -> V_104 = 0 ;
V_52 -> V_105 = 0 ;
return V_95 ;
}
}
