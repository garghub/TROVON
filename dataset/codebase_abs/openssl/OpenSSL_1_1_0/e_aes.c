static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
V_6 = F_3 ( V_1 ) ;
if ( ( V_6 == V_8 || V_6 == V_9 )
&& ! V_4 ) {
V_5 = F_4 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_13 ;
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_17 : NULL ;
} else {
V_5 = F_6 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_18 ;
if ( V_6 == V_9 )
V_7 -> V_14 . V_15 = ( V_16 ) V_17 ;
else if ( V_6 == V_19 )
V_7 -> V_14 . V_20 = ( V_21 ) V_22 ;
else
V_7 -> V_14 . V_15 = NULL ;
}
if ( V_5 < 0 ) {
F_7 ( V_23 , V_24 ) ;
return 0 ;
}
return 1 ;
}
static int F_8 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
V_17 ( V_26 , V_25 , V_27 , & F_2 ( T_2 , V_1 ) -> V_10 . V_10 ,
F_9 ( V_1 ) ,
F_10 ( V_1 ) ) ;
return 1 ;
}
static int F_11 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_3 V_28 = F_12 ( V_1 ) ;
if ( V_27 < V_28 )
return 1 ;
F_13 ( V_26 , V_25 , V_27 , & F_2 ( T_2 , V_1 ) -> V_10 . V_10 ,
F_10 ( V_1 ) ) ;
return 1 ;
}
static int F_14 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_29 = F_2 ( T_4 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
F_6 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_29 -> V_10 . V_10 ) ;
F_15 ( & V_29 -> V_30 , & V_29 -> V_10 , ( V_12 ) V_18 ) ;
V_29 -> V_20 = ( V_21 ) V_22 ;
if ( V_3 == NULL && V_29 -> V_31 )
V_3 = V_29 -> V_3 ;
if ( V_3 ) {
F_16 ( & V_29 -> V_30 , V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
}
V_29 -> V_33 = 1 ;
} else {
if ( V_29 -> V_33 )
F_16 ( & V_29 -> V_30 , V_3 , V_29 -> V_32 ) ;
else
memcpy ( V_29 -> V_3 , V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
V_29 -> V_34 = 0 ;
}
return 1 ;
}
static int F_17 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_35 = F_2 ( T_5 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
if ( V_4 ) {
F_6 ( V_2 , F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_18 ;
V_35 -> V_14 = V_39 ;
} else {
F_4 ( V_2 , F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_13 ;
V_35 -> V_14 = V_40 ;
}
F_6 ( V_2 + F_5 ( V_1 ) / 2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_41 . V_10 ) ;
V_35 -> V_37 . V_42 = ( V_12 ) V_18 ;
V_35 -> V_37 . V_43 = & V_35 -> V_36 ;
}
if ( V_3 ) {
V_35 -> V_37 . V_44 = & V_35 -> V_41 ;
memcpy ( F_9 ( V_1 ) , V_3 , 16 ) ;
}
return 1 ;
}
static int F_18 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_45 = F_2 ( T_6 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
F_6 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_45 -> V_10 . V_10 ) ;
F_19 ( & V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_48 ,
& V_45 -> V_10 , ( V_12 ) V_18 ) ;
V_45 -> V_49 = V_4 ? ( V_50 ) V_51 :
( V_50 ) V_52 ;
V_45 -> V_33 = 1 ;
}
if ( V_3 ) {
memcpy ( F_9 ( V_1 ) , V_3 , 15 - V_45 -> V_48 ) ;
V_45 -> V_31 = 1 ;
}
return 1 ;
}
static int F_20 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_7 * V_53 = F_2 ( T_7 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
do {
F_6 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_54 . V_10 ) ;
F_4 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_55 . V_10 ) ;
if ( ! F_21 ( & V_53 -> V_56 ,
& V_53 -> V_54 . V_10 , & V_53 -> V_55 . V_10 ,
( V_12 ) V_18 ,
( V_12 ) V_13 ,
V_4 ? V_57
: V_58 ) )
return 0 ;
}
while ( 0 );
if ( V_3 == NULL && V_53 -> V_31 )
V_3 = V_53 -> V_3 ;
if ( V_3 ) {
if ( F_22 ( & V_53 -> V_56 , V_3 , V_53 -> V_32 , V_53 -> V_59 )
!= 1 )
return 0 ;
V_53 -> V_31 = 1 ;
}
V_53 -> V_33 = 1 ;
} else {
if ( V_53 -> V_33 )
F_22 ( & V_53 -> V_56 , V_3 , V_53 -> V_32 , V_53 -> V_59 ) ;
else
memcpy ( V_53 -> V_3 , V_3 , V_53 -> V_32 ) ;
V_53 -> V_31 = 1 ;
}
return 1 ;
}
static int F_23 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 , V_60 ;
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
V_6 = F_3 ( V_1 ) ;
V_60 = F_5 ( V_1 ) * 8 ;
if ( ( V_6 == V_8 || V_6 == V_9 )
&& ! V_4 ) {
V_5 = 0 ;
F_24 ( V_2 , V_60 , & V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_61 ;
switch ( V_60 ) {
case 128 :
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_62 : NULL ;
break;
case 192 :
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_63 : NULL ;
break;
case 256 :
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_64 : NULL ;
break;
default:
V_5 = - 1 ;
}
} else {
V_5 = 0 ;
F_25 ( V_2 , V_60 , & V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_65 ;
switch ( V_60 ) {
case 128 :
if ( V_6 == V_9 )
V_7 -> V_14 . V_15 = ( V_16 ) V_66 ;
else if ( V_6 == V_19 )
V_7 -> V_14 . V_20 = ( V_21 ) V_67 ;
else
V_7 -> V_14 . V_15 = NULL ;
break;
case 192 :
if ( V_6 == V_9 )
V_7 -> V_14 . V_15 = ( V_16 ) V_68 ;
else if ( V_6 == V_19 )
V_7 -> V_14 . V_20 = ( V_21 ) V_69 ;
else
V_7 -> V_14 . V_15 = NULL ;
break;
case 256 :
if ( V_6 == V_9 )
V_7 -> V_14 . V_15 = ( V_16 ) V_70 ;
else if ( V_6 == V_19 )
V_7 -> V_14 . V_20 = ( V_21 ) V_71 ;
else
V_7 -> V_14 . V_15 = NULL ;
break;
default:
V_5 = - 1 ;
}
}
if ( V_5 < 0 ) {
F_7 ( V_72 , V_24 ) ;
return 0 ;
}
return 1 ;
}
static int F_26 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_29 = F_2 ( T_4 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
int V_60 = F_5 ( V_1 ) * 8 ;
F_25 ( V_2 , V_60 , & V_29 -> V_10 . V_10 ) ;
F_15 ( & V_29 -> V_30 , & V_29 -> V_10 ,
( V_12 ) V_65 ) ;
switch ( V_60 ) {
case 128 :
V_29 -> V_20 = ( V_21 ) V_67 ;
break;
case 192 :
V_29 -> V_20 = ( V_21 ) V_69 ;
break;
case 256 :
V_29 -> V_20 = ( V_21 ) V_71 ;
break;
default:
return 0 ;
}
if ( V_3 == NULL && V_29 -> V_31 )
V_3 = V_29 -> V_3 ;
if ( V_3 ) {
F_16 ( & V_29 -> V_30 , V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
}
V_29 -> V_33 = 1 ;
} else {
if ( V_29 -> V_33 )
F_16 ( & V_29 -> V_30 , V_3 , V_29 -> V_32 ) ;
else
memcpy ( V_29 -> V_3 , V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
V_29 -> V_34 = 0 ;
}
return 1 ;
}
static int F_27 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_35 = F_2 ( T_5 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
int V_60 = F_5 ( V_1 ) * 4 ;
V_35 -> V_14 = NULL ;
if ( V_4 ) {
F_25 ( V_2 , V_60 , & V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_65 ;
switch ( V_60 ) {
case 128 :
V_35 -> V_14 = V_73 ;
break;
case 256 :
V_35 -> V_14 = V_74 ;
break;
default:
return 0 ;
}
} else {
F_24 ( V_2 , F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_61 ;
switch ( V_60 ) {
case 128 :
V_35 -> V_14 = V_75 ;
break;
case 256 :
V_35 -> V_14 = V_76 ;
break;
default:
return 0 ;
}
}
F_25 ( V_2 + F_5 ( V_1 ) / 2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_41 . V_10 ) ;
V_35 -> V_37 . V_42 = ( V_12 ) V_65 ;
V_35 -> V_37 . V_43 = & V_35 -> V_36 ;
}
if ( V_3 ) {
V_35 -> V_37 . V_44 = & V_35 -> V_41 ;
memcpy ( F_9 ( V_1 ) , V_3 , 16 ) ;
}
return 1 ;
}
static int F_28 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_45 = F_2 ( T_6 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
int V_60 = F_5 ( V_1 ) * 8 ;
F_25 ( V_2 , V_60 , & V_45 -> V_10 . V_10 ) ;
F_19 ( & V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_48 ,
& V_45 -> V_10 , ( V_12 ) V_65 ) ;
V_45 -> V_49 = NULL ;
V_45 -> V_33 = 1 ;
}
if ( V_3 ) {
memcpy ( F_9 ( V_1 ) , V_3 , 15 - V_45 -> V_48 ) ;
V_45 -> V_31 = 1 ;
}
return 1 ;
}
static int F_29 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_7 * V_53 = F_2 ( T_7 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
do {
F_25 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_54 . V_10 ) ;
F_24 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_55 . V_10 ) ;
if ( ! F_21 ( & V_53 -> V_56 ,
& V_53 -> V_54 . V_10 , & V_53 -> V_55 . V_10 ,
( V_12 ) V_65 ,
( V_12 ) V_61 ,
NULL ) )
return 0 ;
}
while ( 0 );
if ( V_3 == NULL && V_53 -> V_31 )
V_3 = V_53 -> V_3 ;
if ( V_3 ) {
if ( F_22 ( & V_53 -> V_56 , V_3 , V_53 -> V_32 , V_53 -> V_59 )
!= 1 )
return 0 ;
V_53 -> V_31 = 1 ;
}
V_53 -> V_33 = 1 ;
} else {
if ( V_53 -> V_33 )
F_22 ( & V_53 -> V_56 , V_3 , V_53 -> V_32 , V_53 -> V_59 ) ;
else
memcpy ( V_53 -> V_3 , V_3 , V_53 -> V_32 ) ;
V_53 -> V_31 = 1 ;
}
return 1 ;
}
static int F_30 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
V_6 = F_3 ( V_1 ) ;
if ( ( V_6 == V_8 || V_6 == V_9 )
&& ! V_4 ) {
#ifdef F_31
if ( F_31 ) {
V_5 = F_32 ( V_2 ,
F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_77 ;
V_7 -> V_14 . V_15 = NULL ;
# ifdef F_33
if ( V_6 == V_9 )
V_7 -> V_14 . V_15 = ( V_16 ) F_33 ;
# endif
} else
#endif
#ifdef F_34
if ( F_34 && V_6 == V_9 ) {
V_5 = F_35 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_78 ;
V_7 -> V_14 . V_15 = ( V_16 ) V_79 ;
} else
#endif
#ifdef F_36
if ( F_36 ) {
V_5 = F_37 ( V_2 ,
F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_80 ;
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_81 : NULL ;
} else
#endif
{
V_5 = F_35 ( V_2 ,
F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_78 ;
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_82 : NULL ;
}
} else
#ifdef F_31
if ( F_31 ) {
V_5 = F_38 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_83 ;
V_7 -> V_14 . V_15 = NULL ;
# ifdef F_33
if ( V_6 == V_9 )
V_7 -> V_14 . V_15 = ( V_16 ) F_33 ;
else
# endif
# ifdef F_39
if ( V_6 == V_19 )
V_7 -> V_14 . V_20 = ( V_21 ) F_39 ;
else
# endif
( void ) 0 ;
} else
#endif
#ifdef F_34
if ( F_34 && V_6 == V_19 ) {
V_5 = F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_84 ;
V_7 -> V_14 . V_20 = ( V_21 ) V_85 ;
} else
#endif
#ifdef F_36
if ( F_36 ) {
V_5 = F_41 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_86 ;
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_81 : NULL ;
} else
#endif
{
V_5 = F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_7 -> V_10 . V_10 ) ;
V_7 -> V_11 = ( V_12 ) V_84 ;
V_7 -> V_14 . V_15 = V_6 == V_9 ?
( V_16 ) V_82 : NULL ;
#ifdef F_42
if ( V_6 == V_19 )
V_7 -> V_14 . V_20 = ( V_21 ) V_87 ;
#endif
}
if ( V_5 < 0 ) {
F_7 ( V_88 , V_24 ) ;
return 0 ;
}
return 1 ;
}
static int F_43 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
if ( V_7 -> V_14 . V_15 )
(* V_7 -> V_14 . V_15 ) ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) ,
F_10 ( V_1 ) ) ;
else if ( F_10 ( V_1 ) )
F_44 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) , V_7 -> V_11 ) ;
else
F_45 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) , V_7 -> V_11 ) ;
return 1 ;
}
static int F_46 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_3 V_28 = F_12 ( V_1 ) ;
T_3 V_89 ;
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
if ( V_27 < V_28 )
return 1 ;
for ( V_89 = 0 , V_27 -= V_28 ; V_89 <= V_27 ; V_89 += V_28 )
(* V_7 -> V_11 ) ( V_26 + V_89 , V_25 + V_89 , & V_7 -> V_10 ) ;
return 1 ;
}
static int F_47 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
int V_90 = F_48 ( V_1 ) ;
F_49 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) , & V_90 , V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
return 1 ;
}
static int F_51 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
int V_90 = F_48 ( V_1 ) ;
F_52 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) , & V_90 ,
F_10 ( V_1 ) , V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
return 1 ;
}
static int F_53 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
int V_90 = F_48 ( V_1 ) ;
F_54 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) , & V_90 ,
F_10 ( V_1 ) , V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
return 1 ;
}
static int F_55 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
if ( F_56 ( V_1 , V_91 ) ) {
int V_90 = F_48 ( V_1 ) ;
F_57 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) , & V_90 ,
F_10 ( V_1 ) , V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
return 1 ;
}
while ( V_27 >= V_92 ) {
int V_90 = F_48 ( V_1 ) ;
F_57 ( V_26 , V_25 , V_92 * 8 , & V_7 -> V_10 ,
F_9 ( V_1 ) , & V_90 ,
F_10 ( V_1 ) , V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
V_27 -= V_92 ;
}
if ( V_27 ) {
int V_90 = F_48 ( V_1 ) ;
F_57 ( V_26 , V_25 , V_27 * 8 , & V_7 -> V_10 ,
F_9 ( V_1 ) , & V_90 ,
F_10 ( V_1 ) , V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
}
return 1 ;
}
static int F_58 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
unsigned int V_90 = F_48 ( V_1 ) ;
T_2 * V_7 = F_2 ( T_2 , V_1 ) ;
if ( V_7 -> V_14 . V_20 )
F_59 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) ,
F_60 ( V_1 ) ,
& V_90 , V_7 -> V_14 . V_20 ) ;
else
F_61 ( V_26 , V_25 , V_27 , & V_7 -> V_10 ,
F_9 ( V_1 ) ,
F_60 ( V_1 ) , & V_90 ,
V_7 -> V_11 ) ;
F_50 ( V_1 , V_90 ) ;
return 1 ;
}
static int F_62 ( T_1 * V_93 )
{
T_4 * V_29 = F_2 ( T_4 , V_93 ) ;
F_63 ( & V_29 -> V_30 , sizeof( V_29 -> V_30 ) ) ;
if ( V_29 -> V_3 != F_9 ( V_93 ) )
F_64 ( V_29 -> V_3 ) ;
return 1 ;
}
static void F_65 ( unsigned char * V_94 )
{
int V_95 = 8 ;
unsigned char V_93 ;
do {
-- V_95 ;
V_93 = V_94 [ V_95 ] ;
++ V_93 ;
V_94 [ V_95 ] = V_93 ;
if ( V_93 )
return;
} while ( V_95 );
}
static int F_66 ( T_1 * V_93 , int type , int V_96 , void * V_97 )
{
T_4 * V_29 = F_2 ( T_4 , V_93 ) ;
switch ( type ) {
case V_98 :
V_29 -> V_33 = 0 ;
V_29 -> V_31 = 0 ;
V_29 -> V_32 = F_67 ( V_93 ) ;
V_29 -> V_3 = F_9 ( V_93 ) ;
V_29 -> V_59 = - 1 ;
V_29 -> V_34 = 0 ;
V_29 -> V_99 = - 1 ;
return 1 ;
case V_100 :
if ( V_96 <= 0 )
return 0 ;
if ( ( V_96 > V_101 ) && ( V_96 > V_29 -> V_32 ) ) {
if ( V_29 -> V_3 != F_9 ( V_93 ) )
F_64 ( V_29 -> V_3 ) ;
V_29 -> V_3 = F_68 ( V_96 ) ;
if ( V_29 -> V_3 == NULL )
return 0 ;
}
V_29 -> V_32 = V_96 ;
return 1 ;
case V_102 :
if ( V_96 <= 0 || V_96 > 16 || F_10 ( V_93 ) )
return 0 ;
memcpy ( F_60 ( V_93 ) , V_97 , V_96 ) ;
V_29 -> V_59 = V_96 ;
return 1 ;
case V_103 :
if ( V_96 <= 0 || V_96 > 16 || ! F_10 ( V_93 )
|| V_29 -> V_59 < 0 )
return 0 ;
memcpy ( V_97 , F_60 ( V_93 ) , V_96 ) ;
return 1 ;
case V_104 :
if ( V_96 == - 1 ) {
memcpy ( V_29 -> V_3 , V_97 , V_29 -> V_32 ) ;
V_29 -> V_34 = 1 ;
return 1 ;
}
if ( ( V_96 < 4 ) || ( V_29 -> V_32 - V_96 ) < 8 )
return 0 ;
if ( V_96 )
memcpy ( V_29 -> V_3 , V_97 , V_96 ) ;
if ( F_10 ( V_93 )
&& F_69 ( V_29 -> V_3 + V_96 , V_29 -> V_32 - V_96 ) <= 0 )
return 0 ;
V_29 -> V_34 = 1 ;
return 1 ;
case V_105 :
if ( V_29 -> V_34 == 0 || V_29 -> V_33 == 0 )
return 0 ;
F_16 ( & V_29 -> V_30 , V_29 -> V_3 , V_29 -> V_32 ) ;
if ( V_96 <= 0 || V_96 > V_29 -> V_32 )
V_96 = V_29 -> V_32 ;
memcpy ( V_97 , V_29 -> V_3 + V_29 -> V_32 - V_96 , V_96 ) ;
F_65 ( V_29 -> V_3 + V_29 -> V_32 - 8 ) ;
V_29 -> V_31 = 1 ;
return 1 ;
case V_106 :
if ( V_29 -> V_34 == 0 || V_29 -> V_33 == 0
|| F_10 ( V_93 ) )
return 0 ;
memcpy ( V_29 -> V_3 + V_29 -> V_32 - V_96 , V_97 , V_96 ) ;
F_16 ( & V_29 -> V_30 , V_29 -> V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
return 1 ;
case V_107 :
if ( V_96 != V_108 )
return 0 ;
memcpy ( F_60 ( V_93 ) , V_97 , V_96 ) ;
V_29 -> V_99 = V_96 ;
{
unsigned int V_27 =
F_60 ( V_93 ) [ V_96 - 2 ] << 8
| F_60 ( V_93 ) [ V_96 - 1 ] ;
V_27 -= V_109 ;
if ( ! F_10 ( V_93 ) )
V_27 -= V_110 ;
F_60 ( V_93 ) [ V_96 - 2 ] = V_27 >> 8 ;
F_60 ( V_93 ) [ V_96 - 1 ] = V_27 & 0xff ;
}
return V_110 ;
case V_111 :
{
T_1 * V_25 = V_97 ;
T_4 * V_112 = F_2 ( T_4 , V_25 ) ;
if ( V_29 -> V_30 . V_2 ) {
if ( V_29 -> V_30 . V_2 != & V_29 -> V_10 )
return 0 ;
V_112 -> V_30 . V_2 = & V_112 -> V_10 ;
}
if ( V_29 -> V_3 == F_9 ( V_93 ) )
V_112 -> V_3 = F_9 ( V_25 ) ;
else {
V_112 -> V_3 = F_68 ( V_29 -> V_32 ) ;
if ( V_112 -> V_3 == NULL )
return 0 ;
memcpy ( V_112 -> V_3 , V_29 -> V_3 , V_29 -> V_32 ) ;
}
return 1 ;
}
default:
return - 1 ;
}
}
static int F_70 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_29 = F_2 ( T_4 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
do {
#ifdef F_31
if ( F_31 ) {
F_38 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_29 -> V_10 . V_10 ) ;
F_15 ( & V_29 -> V_30 , & V_29 -> V_10 ,
( V_12 ) V_83 ) ;
# ifdef F_39
V_29 -> V_20 = ( V_21 ) F_39 ;
# else
V_29 -> V_20 = NULL ;
# endif
break;
} else
#endif
#ifdef F_34
if ( F_34 ) {
F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_29 -> V_10 . V_10 ) ;
F_15 ( & V_29 -> V_30 , & V_29 -> V_10 ,
( V_12 ) V_84 ) ;
V_29 -> V_20 = ( V_21 ) V_85 ;
break;
} else
#endif
#ifdef F_36
if ( F_36 ) {
F_41 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_29 -> V_10 . V_10 ) ;
F_15 ( & V_29 -> V_30 , & V_29 -> V_10 ,
( V_12 ) V_86 ) ;
V_29 -> V_20 = NULL ;
break;
} else
#endif
( void ) 0 ;
F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_29 -> V_10 . V_10 ) ;
F_15 ( & V_29 -> V_30 , & V_29 -> V_10 ,
( V_12 ) V_84 ) ;
#ifdef F_42
V_29 -> V_20 = ( V_21 ) V_87 ;
#else
V_29 -> V_20 = NULL ;
#endif
} while ( 0 );
if ( V_3 == NULL && V_29 -> V_31 )
V_3 = V_29 -> V_3 ;
if ( V_3 ) {
F_16 ( & V_29 -> V_30 , V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
}
V_29 -> V_33 = 1 ;
} else {
if ( V_29 -> V_33 )
F_16 ( & V_29 -> V_30 , V_3 , V_29 -> V_32 ) ;
else
memcpy ( V_29 -> V_3 , V_3 , V_29 -> V_32 ) ;
V_29 -> V_31 = 1 ;
V_29 -> V_34 = 0 ;
}
return 1 ;
}
static int F_71 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_4 * V_29 = F_2 ( T_4 , V_1 ) ;
int V_113 = - 1 ;
if ( V_25 != V_26
|| V_27 < ( V_109 + V_110 ) )
return - 1 ;
if ( F_72 ( V_1 , F_10 ( V_1 ) ?
V_105 : V_106 ,
V_109 , V_25 ) <= 0 )
goto V_114;
if ( F_73 ( & V_29 -> V_30 , F_60 ( V_1 ) ,
V_29 -> V_99 ) )
goto V_114;
V_26 += V_109 ;
V_25 += V_109 ;
V_27 -= V_109 + V_110 ;
if ( F_10 ( V_1 ) ) {
if ( V_29 -> V_20 ) {
T_3 V_115 = 0 ;
#if F_74 ( V_116 )
if ( V_27 >= 32 && V_116 ( V_29 ) ) {
if ( F_75 ( & V_29 -> V_30 , NULL , NULL , 0 ) )
return - 1 ;
V_115 = F_76 ( V_26 , V_25 , V_27 ,
V_29 -> V_30 . V_2 ,
V_29 -> V_30 . V_117 . V_93 , V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
}
#endif
if ( F_77 ( & V_29 -> V_30 ,
V_26 + V_115 ,
V_25 + V_115 ,
V_27 - V_115 , V_29 -> V_20 ) )
goto V_114;
} else {
T_3 V_115 = 0 ;
#if F_74 ( V_120 )
if ( V_27 >= 32 && V_120 ( V_29 ) ) {
if ( F_75 ( & V_29 -> V_30 , NULL , NULL , 0 ) )
return - 1 ;
V_115 = F_76 ( V_26 , V_25 , V_27 ,
V_29 -> V_30 . V_2 ,
V_29 -> V_30 . V_117 . V_93 , V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
}
#endif
if ( F_75 ( & V_29 -> V_30 ,
V_26 + V_115 , V_25 + V_115 , V_27 - V_115 ) )
goto V_114;
}
V_25 += V_27 ;
F_78 ( & V_29 -> V_30 , V_25 , V_110 ) ;
V_113 = V_27 + V_109 + V_110 ;
} else {
if ( V_29 -> V_20 ) {
T_3 V_115 = 0 ;
#if F_74 ( V_116 )
if ( V_27 >= 16 && V_116 ( V_29 ) ) {
if ( F_79 ( & V_29 -> V_30 , NULL , NULL , 0 ) )
return - 1 ;
V_115 = F_80 ( V_26 , V_25 , V_27 ,
V_29 -> V_30 . V_2 ,
V_29 -> V_30 . V_117 . V_93 , V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
}
#endif
if ( F_81 ( & V_29 -> V_30 ,
V_26 + V_115 ,
V_25 + V_115 ,
V_27 - V_115 , V_29 -> V_20 ) )
goto V_114;
} else {
T_3 V_115 = 0 ;
#if F_74 ( V_120 )
if ( V_27 >= 16 && V_120 ( V_29 ) ) {
if ( F_79 ( & V_29 -> V_30 , NULL , NULL , 0 ) )
return - 1 ;
V_115 = F_80 ( V_26 , V_25 , V_27 ,
V_29 -> V_30 . V_2 ,
V_29 -> V_30 . V_117 . V_93 , V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
}
#endif
if ( F_79 ( & V_29 -> V_30 ,
V_26 + V_115 , V_25 + V_115 , V_27 - V_115 ) )
goto V_114;
}
F_78 ( & V_29 -> V_30 , F_60 ( V_1 ) ,
V_110 ) ;
if ( F_82 ( F_60 ( V_1 ) , V_26 + V_27 ,
V_110 ) ) {
F_63 ( V_25 , V_27 ) ;
goto V_114;
}
V_113 = V_27 ;
}
V_114:
V_29 -> V_31 = 0 ;
V_29 -> V_99 = - 1 ;
return V_113 ;
}
static int F_83 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_4 * V_29 = F_2 ( T_4 , V_1 ) ;
if ( ! V_29 -> V_33 )
return - 1 ;
if ( V_29 -> V_99 >= 0 )
return F_71 ( V_1 , V_25 , V_26 , V_27 ) ;
if ( ! V_29 -> V_31 )
return - 1 ;
if ( V_26 ) {
if ( V_25 == NULL ) {
if ( F_73 ( & V_29 -> V_30 , V_26 , V_27 ) )
return - 1 ;
} else if ( F_10 ( V_1 ) ) {
if ( V_29 -> V_20 ) {
T_3 V_115 = 0 ;
#if F_74 ( V_116 )
if ( V_27 >= 32 && V_116 ( V_29 ) ) {
T_3 V_121 = ( 16 - V_29 -> V_30 . V_122 ) % 16 ;
if ( F_75 ( & V_29 -> V_30 , V_26 , V_25 , V_121 ) )
return - 1 ;
V_115 = F_76 ( V_26 + V_121 ,
V_25 + V_121 , V_27 - V_121 ,
V_29 -> V_30 . V_2 , V_29 -> V_30 . V_117 . V_93 ,
V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
V_115 += V_121 ;
}
#endif
if ( F_77 ( & V_29 -> V_30 ,
V_26 + V_115 ,
V_25 + V_115 ,
V_27 - V_115 , V_29 -> V_20 ) )
return - 1 ;
} else {
T_3 V_115 = 0 ;
#if F_74 ( V_120 )
if ( V_27 >= 32 && V_120 ( V_29 ) ) {
T_3 V_121 = ( 16 - V_29 -> V_30 . V_122 ) % 16 ;
if ( F_75 ( & V_29 -> V_30 , V_26 , V_25 , V_121 ) )
return - 1 ;
V_115 = F_76 ( V_26 + V_121 ,
V_25 + V_121 , V_27 - V_121 ,
V_29 -> V_30 . V_2 , V_29 -> V_30 . V_117 . V_93 ,
V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
V_115 += V_121 ;
}
#endif
if ( F_75 ( & V_29 -> V_30 ,
V_26 + V_115 , V_25 + V_115 , V_27 - V_115 ) )
return - 1 ;
}
} else {
if ( V_29 -> V_20 ) {
T_3 V_115 = 0 ;
#if F_74 ( V_116 )
if ( V_27 >= 16 && V_116 ( V_29 ) ) {
T_3 V_121 = ( 16 - V_29 -> V_30 . V_122 ) % 16 ;
if ( F_79 ( & V_29 -> V_30 , V_26 , V_25 , V_121 ) )
return - 1 ;
V_115 = F_80 ( V_26 + V_121 ,
V_25 + V_121 , V_27 - V_121 ,
V_29 -> V_30 . V_2 ,
V_29 -> V_30 . V_117 . V_93 , V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
V_115 += V_121 ;
}
#endif
if ( F_81 ( & V_29 -> V_30 ,
V_26 + V_115 ,
V_25 + V_115 ,
V_27 - V_115 , V_29 -> V_20 ) )
return - 1 ;
} else {
T_3 V_115 = 0 ;
#if F_74 ( V_120 )
if ( V_27 >= 16 && V_120 ( V_29 ) ) {
T_3 V_121 = ( 16 - V_29 -> V_30 . V_122 ) % 16 ;
if ( F_79 ( & V_29 -> V_30 , V_26 , V_25 , V_121 ) )
return - 1 ;
V_115 = F_80 ( V_26 + V_121 ,
V_25 + V_121 , V_27 - V_121 ,
V_29 -> V_30 . V_2 ,
V_29 -> V_30 . V_117 . V_93 , V_29 -> V_30 . V_118 . V_119 ) ;
V_29 -> V_30 . V_27 . V_119 [ 1 ] += V_115 ;
V_115 += V_121 ;
}
#endif
if ( F_79 ( & V_29 -> V_30 ,
V_26 + V_115 , V_25 + V_115 , V_27 - V_115 ) )
return - 1 ;
}
}
return V_27 ;
} else {
if ( ! F_10 ( V_1 ) ) {
if ( V_29 -> V_59 < 0 )
return - 1 ;
if ( F_84 ( & V_29 -> V_30 ,
F_60 ( V_1 ) ,
V_29 -> V_59 ) != 0 )
return - 1 ;
V_29 -> V_31 = 0 ;
return 0 ;
}
F_78 ( & V_29 -> V_30 , F_60 ( V_1 ) , 16 ) ;
V_29 -> V_59 = 16 ;
V_29 -> V_31 = 0 ;
return 0 ;
}
}
static int F_85 ( T_1 * V_93 , int type , int V_96 , void * V_97 )
{
T_5 * V_35 = F_2 ( T_5 , V_93 ) ;
if ( type == V_111 ) {
T_1 * V_25 = V_97 ;
T_5 * V_123 = F_2 ( T_5 , V_25 ) ;
if ( V_35 -> V_37 . V_43 ) {
if ( V_35 -> V_37 . V_43 != & V_35 -> V_36 )
return 0 ;
V_123 -> V_37 . V_43 = & V_123 -> V_36 ;
}
if ( V_35 -> V_37 . V_44 ) {
if ( V_35 -> V_37 . V_44 != & V_35 -> V_41 )
return 0 ;
V_123 -> V_37 . V_44 = & V_123 -> V_41 ;
}
return 1 ;
} else if ( type != V_98 )
return - 1 ;
V_35 -> V_37 . V_43 = NULL ;
V_35 -> V_37 . V_44 = NULL ;
return 1 ;
}
static int F_86 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_35 = F_2 ( T_5 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
do {
#ifdef F_87
V_35 -> V_14 = V_4 ? V_124 : V_125 ;
#else
V_35 -> V_14 = NULL ;
#endif
#ifdef F_31
if ( F_31 ) {
if ( V_4 ) {
F_38 ( V_2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_83 ;
# ifdef F_88
V_35 -> V_14 = F_88 ;
# endif
} else {
F_32 ( V_2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_77 ;
# ifdef F_89
V_35 -> V_14 = F_89 ;
#endif
}
F_38 ( V_2 + F_5 ( V_1 ) / 2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_41 . V_10 ) ;
V_35 -> V_37 . V_42 = ( V_12 ) V_83 ;
V_35 -> V_37 . V_43 = & V_35 -> V_36 ;
break;
} else
#endif
#ifdef F_34
if ( F_34 )
V_35 -> V_14 = V_4 ? V_126 : V_127 ;
else
#endif
#ifdef F_36
if ( F_36 ) {
if ( V_4 ) {
F_41 ( V_2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_86 ;
} else {
F_37 ( V_2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_80 ;
}
F_41 ( V_2 + F_5 ( V_1 ) / 2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_41 . V_10 ) ;
V_35 -> V_37 . V_42 = ( V_12 ) V_86 ;
V_35 -> V_37 . V_43 = & V_35 -> V_36 ;
break;
} else
#endif
( void ) 0 ;
if ( V_4 ) {
F_40 ( V_2 , F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_84 ;
} else {
F_35 ( V_2 , F_5 ( V_1 ) * 4 ,
& V_35 -> V_36 . V_10 ) ;
V_35 -> V_37 . V_38 = ( V_12 ) V_78 ;
}
F_40 ( V_2 + F_5 ( V_1 ) / 2 ,
F_5 ( V_1 ) * 4 ,
& V_35 -> V_41 . V_10 ) ;
V_35 -> V_37 . V_42 = ( V_12 ) V_84 ;
V_35 -> V_37 . V_43 = & V_35 -> V_36 ;
} while ( 0 );
if ( V_3 ) {
V_35 -> V_37 . V_44 = & V_35 -> V_41 ;
memcpy ( F_9 ( V_1 ) , V_3 , 16 ) ;
}
return 1 ;
}
static int F_90 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_5 * V_35 = F_2 ( T_5 , V_1 ) ;
if ( ! V_35 -> V_37 . V_43 || ! V_35 -> V_37 . V_44 )
return 0 ;
if ( ! V_25 || ! V_26 || V_27 < V_128 )
return 0 ;
if ( V_35 -> V_14 )
(* V_35 -> V_14 ) ( V_26 , V_25 , V_27 ,
V_35 -> V_37 . V_43 , V_35 -> V_37 . V_44 ,
F_9 ( V_1 ) ) ;
else if ( F_91 ( & V_35 -> V_37 , F_9 ( V_1 ) ,
V_26 , V_25 , V_27 ,
F_10 ( V_1 ) ) )
return 0 ;
return 1 ;
}
static int F_92 ( T_1 * V_93 , int type , int V_96 , void * V_97 )
{
T_6 * V_45 = F_2 ( T_6 , V_93 ) ;
switch ( type ) {
case V_98 :
V_45 -> V_33 = 0 ;
V_45 -> V_31 = 0 ;
V_45 -> V_48 = 8 ;
V_45 -> V_47 = 12 ;
V_45 -> V_129 = 0 ;
V_45 -> V_130 = 0 ;
V_45 -> V_99 = - 1 ;
return 1 ;
case V_107 :
if ( V_96 != V_108 )
return 0 ;
memcpy ( F_60 ( V_93 ) , V_97 , V_96 ) ;
V_45 -> V_99 = V_96 ;
{
T_8 V_27 =
F_60 ( V_93 ) [ V_96 - 2 ] << 8
| F_60 ( V_93 ) [ V_96 - 1 ] ;
V_27 -= V_131 ;
if ( ! F_10 ( V_93 ) )
V_27 -= V_45 -> V_47 ;
F_60 ( V_93 ) [ V_96 - 2 ] = V_27 >> 8 ;
F_60 ( V_93 ) [ V_96 - 1 ] = V_27 & 0xff ;
}
return V_45 -> V_47 ;
case V_132 :
if ( V_96 != V_133 )
return 0 ;
memcpy ( F_9 ( V_93 ) , V_97 , V_96 ) ;
return 1 ;
case V_100 :
V_96 = 15 - V_96 ;
case V_134 :
if ( V_96 < 2 || V_96 > 8 )
return 0 ;
V_45 -> V_48 = V_96 ;
return 1 ;
case V_102 :
if ( ( V_96 & 1 ) || V_96 < 4 || V_96 > 16 )
return 0 ;
if ( F_10 ( V_93 ) && V_97 )
return 0 ;
if ( V_97 ) {
V_45 -> V_129 = 1 ;
memcpy ( F_60 ( V_93 ) , V_97 , V_96 ) ;
}
V_45 -> V_47 = V_96 ;
return 1 ;
case V_103 :
if ( ! F_10 ( V_93 ) || ! V_45 -> V_129 )
return 0 ;
if ( ! F_93 ( & V_45 -> V_46 , V_97 , ( T_3 ) V_96 ) )
return 0 ;
V_45 -> V_129 = 0 ;
V_45 -> V_31 = 0 ;
V_45 -> V_130 = 0 ;
return 1 ;
case V_111 :
{
T_1 * V_25 = V_97 ;
T_6 * V_135 = F_2 ( T_6 , V_25 ) ;
if ( V_45 -> V_46 . V_2 ) {
if ( V_45 -> V_46 . V_2 != & V_45 -> V_10 )
return 0 ;
V_135 -> V_46 . V_2 = & V_135 -> V_10 ;
}
return 1 ;
}
default:
return - 1 ;
}
}
static int F_94 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_45 = F_2 ( T_6 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
do {
#ifdef F_31
if ( F_31 ) {
F_38 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_45 -> V_10 . V_10 ) ;
F_19 ( & V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_48 ,
& V_45 -> V_10 , ( V_12 ) V_83 ) ;
V_45 -> V_49 = NULL ;
V_45 -> V_33 = 1 ;
break;
} else
#endif
#ifdef F_36
if ( F_36 ) {
F_41 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_45 -> V_10 . V_10 ) ;
F_19 ( & V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_48 ,
& V_45 -> V_10 , ( V_12 ) V_86 ) ;
V_45 -> V_49 = NULL ;
V_45 -> V_33 = 1 ;
break;
}
#endif
F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_45 -> V_10 . V_10 ) ;
F_19 ( & V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_48 ,
& V_45 -> V_10 , ( V_12 ) V_84 ) ;
V_45 -> V_49 = NULL ;
V_45 -> V_33 = 1 ;
} while ( 0 );
if ( V_3 ) {
memcpy ( F_9 ( V_1 ) , V_3 , 15 - V_45 -> V_48 ) ;
V_45 -> V_31 = 1 ;
}
return 1 ;
}
static int F_95 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_6 * V_45 = F_2 ( T_6 , V_1 ) ;
T_9 * V_46 = & V_45 -> V_46 ;
if ( V_25 != V_26 || V_27 < ( V_131 + ( T_3 ) V_45 -> V_47 ) )
return - 1 ;
if ( F_10 ( V_1 ) )
memcpy ( V_25 , F_60 ( V_1 ) ,
V_131 ) ;
memcpy ( F_9 ( V_1 ) + V_133 , V_26 ,
V_131 ) ;
V_27 -= V_131 + V_45 -> V_47 ;
if ( F_96 ( V_46 , F_9 ( V_1 ) , 15 - V_45 -> V_48 ,
V_27 ) )
return - 1 ;
F_97 ( V_46 , F_60 ( V_1 ) , V_45 -> V_99 ) ;
V_26 += V_131 ;
V_25 += V_131 ;
if ( F_10 ( V_1 ) ) {
if ( V_45 -> V_49 ? F_98 ( V_46 , V_26 , V_25 , V_27 ,
V_45 -> V_49 ) :
F_99 ( V_46 , V_26 , V_25 , V_27 ) )
return - 1 ;
if ( ! F_93 ( V_46 , V_25 + V_27 , V_45 -> V_47 ) )
return - 1 ;
return V_27 + V_131 + V_45 -> V_47 ;
} else {
if ( V_45 -> V_49 ? ! F_100 ( V_46 , V_26 , V_25 , V_27 ,
V_45 -> V_49 ) :
! F_101 ( V_46 , V_26 , V_25 , V_27 ) ) {
unsigned char V_136 [ 16 ] ;
if ( F_93 ( V_46 , V_136 , V_45 -> V_47 ) ) {
if ( ! F_82 ( V_136 , V_26 + V_27 , V_45 -> V_47 ) )
return V_27 ;
}
}
F_63 ( V_25 , V_27 ) ;
return - 1 ;
}
}
static int F_102 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
T_6 * V_45 = F_2 ( T_6 , V_1 ) ;
T_9 * V_46 = & V_45 -> V_46 ;
if ( ! V_45 -> V_33 )
return - 1 ;
if ( V_45 -> V_99 >= 0 )
return F_95 ( V_1 , V_25 , V_26 , V_27 ) ;
if ( ! V_45 -> V_31 )
return - 1 ;
if ( ! F_10 ( V_1 ) && ! V_45 -> V_129 )
return - 1 ;
if ( ! V_25 ) {
if ( ! V_26 ) {
if ( F_96 ( V_46 , F_9 ( V_1 ) ,
15 - V_45 -> V_48 , V_27 ) )
return - 1 ;
V_45 -> V_130 = 1 ;
return V_27 ;
}
if ( ! V_45 -> V_130 && V_27 )
return - 1 ;
F_97 ( V_46 , V_26 , V_27 ) ;
return V_27 ;
}
if ( ! V_26 )
return 0 ;
if ( ! V_45 -> V_130 ) {
if ( F_96 ( V_46 , F_9 ( V_1 ) ,
15 - V_45 -> V_48 , V_27 ) )
return - 1 ;
V_45 -> V_130 = 1 ;
}
if ( F_10 ( V_1 ) ) {
if ( V_45 -> V_49 ? F_98 ( V_46 , V_26 , V_25 , V_27 ,
V_45 -> V_49 ) :
F_99 ( V_46 , V_26 , V_25 , V_27 ) )
return - 1 ;
V_45 -> V_129 = 1 ;
return V_27 ;
} else {
int V_113 = - 1 ;
if ( V_45 -> V_49 ? ! F_100 ( V_46 , V_26 , V_25 , V_27 ,
V_45 -> V_49 ) :
! F_101 ( V_46 , V_26 , V_25 , V_27 ) ) {
unsigned char V_136 [ 16 ] ;
if ( F_93 ( V_46 , V_136 , V_45 -> V_47 ) ) {
if ( ! F_82 ( V_136 , F_60 ( V_1 ) ,
V_45 -> V_47 ) )
V_113 = V_27 ;
}
}
if ( V_113 == - 1 )
F_63 ( V_25 , V_27 ) ;
V_45 -> V_31 = 0 ;
V_45 -> V_129 = 0 ;
V_45 -> V_130 = 0 ;
return V_113 ;
}
}
static int F_103 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_10 * V_137 = F_2 ( T_10 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
if ( F_10 ( V_1 ) )
F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_137 -> V_10 . V_10 ) ;
else
F_35 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_137 -> V_10 . V_10 ) ;
if ( ! V_3 )
V_137 -> V_3 = NULL ;
}
if ( V_3 ) {
memcpy ( F_9 ( V_1 ) , V_3 , F_67 ( V_1 ) ) ;
V_137 -> V_3 = F_9 ( V_1 ) ;
}
return 1 ;
}
static int F_104 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_138 )
{
T_10 * V_137 = F_2 ( T_10 , V_1 ) ;
T_3 V_113 ;
int V_139 = F_67 ( V_1 ) == 4 ;
if ( ! V_26 )
return 0 ;
if ( ! V_138 )
return - 1 ;
if ( ! F_10 ( V_1 ) && ( V_138 < 16 || V_138 & 0x7 ) )
return - 1 ;
if ( ! V_139 && V_138 & 0x7 )
return - 1 ;
if ( ! V_25 ) {
if ( F_10 ( V_1 ) ) {
if ( V_139 )
V_138 = ( V_138 + 7 ) / 8 * 8 ;
return V_138 + 8 ;
} else {
return V_138 - 8 ;
}
}
if ( V_139 ) {
if ( F_10 ( V_1 ) )
V_113 = F_105 ( & V_137 -> V_10 . V_10 , V_137 -> V_3 ,
V_25 , V_26 , V_138 ,
( V_12 ) V_84 ) ;
else
V_113 = F_106 ( & V_137 -> V_10 . V_10 , V_137 -> V_3 ,
V_25 , V_26 , V_138 ,
( V_12 ) V_78 ) ;
} else {
if ( F_10 ( V_1 ) )
V_113 = F_107 ( & V_137 -> V_10 . V_10 , V_137 -> V_3 ,
V_25 , V_26 , V_138 , ( V_12 ) V_84 ) ;
else
V_113 = F_108 ( & V_137 -> V_10 . V_10 , V_137 -> V_3 ,
V_25 , V_26 , V_138 , ( V_12 ) V_78 ) ;
}
return V_113 ? ( int ) V_113 : - 1 ;
}
const T_11 * F_109 ( void )
{
return & V_140 ;
}
const T_11 * F_110 ( void )
{
return & V_141 ;
}
const T_11 * F_111 ( void )
{
return & V_142 ;
}
const T_11 * F_112 ( void )
{
return & V_143 ;
}
const T_11 * F_113 ( void )
{
return & V_144 ;
}
const T_11 * F_114 ( void )
{
return & V_145 ;
}
static int F_115 ( T_1 * V_93 , int type , int V_96 , void * V_97 )
{
T_7 * V_53 = F_2 ( T_7 , V_93 ) ;
T_1 * V_146 ;
T_7 * V_147 ;
switch ( type ) {
case V_98 :
V_53 -> V_33 = 0 ;
V_53 -> V_31 = 0 ;
V_53 -> V_32 = F_67 ( V_93 ) ;
V_53 -> V_3 = F_9 ( V_93 ) ;
V_53 -> V_59 = 16 ;
V_53 -> V_148 = 0 ;
V_53 -> V_149 = 0 ;
return 1 ;
case V_100 :
if ( V_96 <= 0 || V_96 > 15 )
return 0 ;
V_53 -> V_32 = V_96 ;
return 1 ;
case V_102 :
if ( ! V_97 ) {
if ( V_96 < 0 || V_96 > 16 )
return 0 ;
V_53 -> V_59 = V_96 ;
return 1 ;
}
if ( V_96 != V_53 -> V_59 || F_10 ( V_93 ) )
return 0 ;
memcpy ( V_53 -> V_136 , V_97 , V_96 ) ;
return 1 ;
case V_103 :
if ( V_96 != V_53 -> V_59 || ! F_10 ( V_93 ) )
return 0 ;
memcpy ( V_97 , V_53 -> V_136 , V_96 ) ;
return 1 ;
case V_111 :
V_146 = ( T_1 * ) V_97 ;
V_147 = F_2 ( T_7 , V_146 ) ;
return F_116 ( & V_147 -> V_56 , & V_53 -> V_56 ,
& V_147 -> V_54 . V_10 ,
& V_147 -> V_55 . V_10 ) ;
default:
return - 1 ;
}
}
static int F_117 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_7 * V_53 = F_2 ( T_7 , V_1 ) ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
do {
# ifdef F_31
if ( F_31 ) {
F_38 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_54 . V_10 ) ;
F_32 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_55 . V_10 ) ;
if ( ! F_21 ( & V_53 -> V_56 ,
& V_53 -> V_54 . V_10 , & V_53 -> V_55 . V_10 ,
( V_12 ) V_83 ,
( V_12 ) V_77 ,
V_4 ? V_150
: V_151 ) )
return 0 ;
break;
}
# endif
# ifdef F_36
if ( F_36 ) {
F_41 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_54 . V_10 ) ;
F_37 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_55 . V_10 ) ;
if ( ! F_21 ( & V_53 -> V_56 ,
& V_53 -> V_54 . V_10 , & V_53 -> V_55 . V_10 ,
( V_12 ) V_86 ,
( V_12 ) V_80 ,
NULL ) )
return 0 ;
break;
}
# endif
F_40 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_54 . V_10 ) ;
F_35 ( V_2 , F_5 ( V_1 ) * 8 ,
& V_53 -> V_55 . V_10 ) ;
if ( ! F_21 ( & V_53 -> V_56 ,
& V_53 -> V_54 . V_10 , & V_53 -> V_55 . V_10 ,
( V_12 ) V_84 ,
( V_12 ) V_78 ,
NULL ) )
return 0 ;
}
while ( 0 );
if ( V_3 == NULL && V_53 -> V_31 )
V_3 = V_53 -> V_3 ;
if ( V_3 ) {
if ( F_22 ( & V_53 -> V_56 , V_3 , V_53 -> V_32 , V_53 -> V_59 )
!= 1 )
return 0 ;
V_53 -> V_31 = 1 ;
}
V_53 -> V_33 = 1 ;
} else {
if ( V_53 -> V_33 )
F_22 ( & V_53 -> V_56 , V_3 , V_53 -> V_32 , V_53 -> V_59 ) ;
else
memcpy ( V_53 -> V_3 , V_3 , V_53 -> V_32 ) ;
V_53 -> V_31 = 1 ;
}
return 1 ;
}
static int F_118 ( T_1 * V_1 , unsigned char * V_25 ,
const unsigned char * V_26 , T_3 V_27 )
{
unsigned char * V_152 ;
int * V_153 ;
int V_154 = 0 ;
T_3 V_155 ;
T_7 * V_53 = F_2 ( T_7 , V_1 ) ;
if ( ! V_53 -> V_31 )
return - 1 ;
if ( ! V_53 -> V_33 )
return - 1 ;
if ( V_26 ) {
if ( V_25 == NULL ) {
V_152 = V_53 -> V_156 ;
V_153 = & ( V_53 -> V_149 ) ;
} else {
V_152 = V_53 -> V_157 ;
V_153 = & ( V_53 -> V_148 ) ;
}
if ( * V_153 ) {
unsigned int V_158 ;
V_158 = 16 - ( * V_153 ) ;
if ( V_158 > V_27 ) {
memcpy ( V_152 + ( * V_153 ) , V_26 , V_27 ) ;
* ( V_153 ) += V_27 ;
return 0 ;
}
memcpy ( V_152 + ( * V_153 ) , V_26 , V_158 ) ;
V_27 -= V_158 ;
V_26 += V_158 ;
if ( V_25 == NULL ) {
if ( ! F_119 ( & V_53 -> V_56 , V_152 , 16 ) )
return - 1 ;
} else if ( F_10 ( V_1 ) ) {
if ( ! F_120 ( & V_53 -> V_56 , V_152 , V_25 , 16 ) )
return - 1 ;
} else {
if ( ! F_121 ( & V_53 -> V_56 , V_152 , V_25 , 16 ) )
return - 1 ;
}
V_154 = 16 ;
* V_153 = 0 ;
}
V_155 = V_27 % 16 ;
if ( V_27 != V_155 ) {
if ( V_25 == NULL ) {
if ( ! F_119 ( & V_53 -> V_56 , V_26 , V_27 - V_155 ) )
return - 1 ;
} else if ( F_10 ( V_1 ) ) {
if ( ! F_120
( & V_53 -> V_56 , V_26 , V_25 , V_27 - V_155 ) )
return - 1 ;
} else {
if ( ! F_121
( & V_53 -> V_56 , V_26 , V_25 , V_27 - V_155 ) )
return - 1 ;
}
V_154 += V_27 - V_155 ;
V_26 += V_27 - V_155 ;
}
if ( V_155 ) {
memcpy ( V_152 , V_26 , V_155 ) ;
* V_153 = V_155 ;
}
return V_154 ;
} else {
if ( V_53 -> V_148 ) {
if ( F_10 ( V_1 ) ) {
if ( ! F_120 ( & V_53 -> V_56 , V_53 -> V_157 , V_25 ,
V_53 -> V_148 ) )
return - 1 ;
} else {
if ( ! F_121 ( & V_53 -> V_56 , V_53 -> V_157 , V_25 ,
V_53 -> V_148 ) )
return - 1 ;
}
V_154 = V_53 -> V_148 ;
V_53 -> V_148 = 0 ;
}
if ( V_53 -> V_149 ) {
if ( ! F_119
( & V_53 -> V_56 , V_53 -> V_156 , V_53 -> V_149 ) )
return - 1 ;
V_53 -> V_149 = 0 ;
}
if ( ! F_10 ( V_1 ) ) {
if ( V_53 -> V_59 < 0 )
return - 1 ;
if ( F_122 ( & V_53 -> V_56 ,
V_53 -> V_136 , V_53 -> V_59 ) != 0 )
return - 1 ;
V_53 -> V_31 = 0 ;
return V_154 ;
}
if ( F_123 ( & V_53 -> V_56 , V_53 -> V_136 , 16 ) != 1 )
return - 1 ;
V_53 -> V_31 = 0 ;
return V_154 ;
}
}
static int F_124 ( T_1 * V_93 )
{
T_7 * V_53 = F_2 ( T_7 , V_93 ) ;
F_125 ( & V_53 -> V_56 ) ;
return 1 ;
}
