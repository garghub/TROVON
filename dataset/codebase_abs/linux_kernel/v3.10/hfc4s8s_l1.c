static inline void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_2 , ( V_1 -> V_3 ) + 4 ) ;
}
static inline T_2
F_3 ( T_1 * V_1 )
{
return ( F_4 ( ( volatile V_4 ) ( V_1 -> V_3 + 4 ) ) ) ;
}
static inline void
F_5 ( T_1 * V_1 , T_2 V_2 , T_2 V_5 )
{
F_1 ( V_1 , V_2 ) ;
F_2 ( V_5 , V_1 -> V_3 ) ;
}
static inline void
F_6 ( T_1 * V_1 , T_2 V_5 )
{
F_2 ( V_5 , V_1 -> V_3 ) ;
}
static inline void
F_7 ( T_1 * V_1 , T_2 V_2 , T_3 V_5 )
{
F_1 ( V_1 , V_2 ) ;
F_8 ( V_5 , V_1 -> V_3 ) ;
}
static inline void
F_9 ( T_1 * V_1 , T_2 V_2 , T_4 V_5 )
{
F_1 ( V_1 , V_2 ) ;
F_10 ( V_5 , V_1 -> V_3 ) ;
}
static inline void
F_11 ( T_1 * V_1 , T_4 V_5 )
{
F_10 ( V_5 , V_1 -> V_3 ) ;
}
static inline T_2
F_12 ( T_1 * V_1 , T_2 V_2 )
{
F_1 ( V_1 , V_2 ) ;
return ( F_4 ( ( volatile V_4 ) V_1 -> V_3 ) ) ;
}
static inline T_2
F_13 ( T_1 * V_1 )
{
return ( F_4 ( ( volatile V_4 ) V_1 -> V_3 ) ) ;
}
static inline T_3
F_14 ( T_1 * V_1 , T_2 V_2 )
{
F_1 ( V_1 , V_2 ) ;
return ( F_15 ( ( volatile V_4 ) V_1 -> V_3 ) ) ;
}
static inline T_4
F_16 ( T_1 * V_1 , T_2 V_2 )
{
F_1 ( V_1 , V_2 ) ;
return ( F_17 ( ( volatile V_4 ) V_1 -> V_3 ) ) ;
}
static inline T_4
F_18 ( T_1 * V_1 )
{
return ( F_17 ( ( volatile V_4 ) V_1 -> V_3 ) ) ;
}
static inline void
F_19 ( T_1 * V_1 )
{
F_1 ( V_1 , V_6 ) ;
while ( F_4 ( ( volatile V_4 ) V_1 -> V_3 ) & V_7 ) ;
}
static T_2
F_20 ( T_1 * V_8 , int V_9 )
{
T_2 V_10 ;
T_2 V_11 ;
V_10 = F_12 ( V_8 , V_9 ) ;
while ( ( ( V_11 = F_12 ( V_8 , V_9 ) ) != V_10 ) ) {
V_10 = V_11 ;
}
return V_11 ;
}
static int
F_21 ( T_1 * V_8 , int V_9 )
{
int V_12 ;
int V_13 ;
V_12 = F_14 ( V_8 , V_9 ) ;
while ( ( ( V_13 = F_14 ( V_8 , V_9 ) ) != V_12 ) ) {
V_12 = V_13 ;
}
return V_13 ;
}
static void
F_22 ( struct V_14 * V_15 , int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_15 -> V_20 . V_21 ;
struct V_22 * V_23 = (struct V_22 * ) V_17 ;
T_4 V_24 ;
switch ( V_16 ) {
case ( V_25 | V_26 ) :
if ( ! V_19 -> V_27 ) {
F_23 ( V_23 ) ;
break;
}
F_24 ( & V_19 -> V_28 , V_24 ) ;
F_25 ( & V_19 -> V_29 , V_23 ) ;
if ( ( F_26 ( & V_19 -> V_29 ) == 1 ) &&
( V_19 -> V_30 <= 0 ) ) {
V_19 -> V_8 -> V_31 . V_32 [ V_19 -> V_33 ] |=
0x10 ;
F_27 ( & V_19 -> V_28 , V_24 ) ;
F_28 ( & V_19 -> V_8 -> V_34 ) ;
} else
F_27 ( & V_19 -> V_28 , V_24 ) ;
break;
case ( V_35 | V_26 ) :
if ( ! V_19 -> V_27 )
break;
if ( ! V_19 -> V_36 ) {
if ( V_19 -> V_37 < 6 ) {
F_24 ( & V_19 -> V_28 ,
V_24 ) ;
F_5 ( V_19 -> V_8 , V_38 ,
V_19 -> V_33 ) ;
F_5 ( V_19 -> V_8 , V_39 ,
0x60 ) ;
F_29 ( & V_19 -> V_40 ,
V_41 + V_42 ) ;
F_27 ( & V_19 -> V_28 ,
V_24 ) ;
} else if ( V_19 -> V_37 == 7 )
V_19 -> V_43 . V_20 . V_44 ( & V_19 -> V_43 . V_20 ,
V_35 |
V_45 ,
NULL ) ;
} else {
if ( V_19 -> V_37 != 3 ) {
F_24 ( & V_19 -> V_28 ,
V_24 ) ;
F_5 ( V_19 -> V_8 , V_38 ,
V_19 -> V_33 ) ;
F_5 ( V_19 -> V_8 , V_39 ,
0x60 ) ;
F_27 ( & V_19 -> V_28 ,
V_24 ) ;
} else if ( V_19 -> V_37 == 3 )
V_19 -> V_43 . V_20 . V_44 ( & V_19 -> V_43 . V_20 ,
V_35 |
V_45 ,
NULL ) ;
}
break;
default:
F_30 ( V_46
L_1 ,
V_16 ) ;
break;
}
if ( ! V_19 -> V_27 )
V_19 -> V_43 . V_20 . V_44 ( & V_19 -> V_43 . V_20 ,
V_47 | V_45 , NULL ) ;
}
static void
F_31 ( struct V_48 * V_20 , int V_16 , void * V_17 )
{
struct V_49 * V_50 = V_20 -> V_21 ;
struct V_18 * V_19 = V_50 -> V_51 ;
struct V_22 * V_23 = (struct V_22 * ) V_17 ;
long V_52 = ( long ) V_17 ;
T_4 V_24 ;
switch ( V_16 ) {
case ( V_25 | V_26 ) :
if ( ! V_19 -> V_27 || ( V_50 -> V_52 == V_53 ) ) {
F_23 ( V_23 ) ;
break;
}
F_24 ( & V_19 -> V_28 , V_24 ) ;
F_25 ( & V_50 -> V_54 , V_23 ) ;
if ( ! V_50 -> V_55 && ( V_50 -> V_30 <= 0 ) ) {
V_19 -> V_8 -> V_31 . V_32 [ V_19 -> V_33 ] |=
( ( V_50 -> V_56 == 1 ) ? 1 : 4 ) ;
F_27 ( & V_19 -> V_28 , V_24 ) ;
F_28 ( & V_19 -> V_8 -> V_34 ) ;
} else
F_27 ( & V_19 -> V_28 , V_24 ) ;
break;
case ( V_35 | V_26 ) :
case ( V_47 | V_26 ) :
if ( ! V_19 -> V_27 )
break;
if ( V_16 == ( V_47 | V_26 ) )
V_52 = V_53 ;
switch ( V_52 ) {
case V_57 :
F_24 ( & V_19 -> V_28 ,
V_24 ) ;
V_19 -> V_8 -> V_31 . V_58 ++ ;
V_19 -> V_8 -> V_31 .
V_59 [ V_19 ->
V_33 ]
|=
( ( V_50 -> V_56 ==
1 ) ? 0x2 : 0x8 ) ;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 ==
1 ) ? 0 : 2 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_61 , 0xc ) ;
F_5 ( V_19 -> V_8 , V_62 , 0 ) ;
F_5 ( V_19 -> V_8 , V_63 , 1 ) ;
F_5 ( V_19 -> V_8 , V_64 , 2 ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 ==
1 ) ? 1 : 3 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_61 , 0xc ) ;
F_5 ( V_19 -> V_8 , V_62 , 0 ) ;
F_5 ( V_19 -> V_8 , V_63 , 1 ) ;
F_5 ( V_19 -> V_8 , V_64 , 2 ) ;
F_5 ( V_19 -> V_8 , V_38 ,
V_19 -> V_33 ) ;
V_19 -> V_8 -> V_31 . V_65 |=
( V_50 -> V_56 & 3 ) ;
F_5 ( V_19 -> V_8 , V_66 ,
V_19 -> V_8 -> V_31 . V_65 ) ;
V_50 -> V_52 = V_57 ;
F_27 ( & V_19 -> V_28 ,
V_24 ) ;
V_50 -> V_67 . V_20 . V_44 ( & V_50 -> V_67 . V_20 ,
V_35 |
V_45 ,
NULL ) ;
break;
case V_68 :
F_24 ( & V_19 -> V_28 ,
V_24 ) ;
V_19 -> V_8 -> V_31 .
V_69 [ V_19 ->
V_33 ]
|=
( ( V_50 -> V_56 ==
1 ) ? 0x2 : 0x8 ) ;
V_19 -> V_8 -> V_31 . V_58 ++ ;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 ==
1 ) ? 0 : 2 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_61 , 0xf ) ;
F_5 ( V_19 -> V_8 , V_62 , 0 ) ;
F_5 ( V_19 -> V_8 , V_63 , 0 ) ;
F_5 ( V_19 -> V_8 , V_64 , 2 ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 ==
1 ) ? 1 : 3 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_61 , 0xf ) ;
F_5 ( V_19 -> V_8 , V_62 , 0 ) ;
F_5 ( V_19 -> V_8 , V_63 , 0 ) ;
F_5 ( V_19 -> V_8 , V_64 , 2 ) ;
F_5 ( V_19 -> V_8 , V_38 ,
V_19 -> V_33 ) ;
V_19 -> V_8 -> V_31 . V_65 |=
( V_50 -> V_56 & 3 ) ;
F_5 ( V_19 -> V_8 , V_66 ,
V_19 -> V_8 -> V_31 . V_65 ) ;
V_50 -> V_52 = V_68 ;
F_27 ( & V_19 -> V_28 ,
V_24 ) ;
V_50 -> V_67 . V_20 . V_44 ( & V_50 -> V_67 . V_20 ,
V_35 |
V_45 ,
NULL ) ;
break;
default:
if ( V_50 -> V_52 == V_53 )
break;
F_24 ( & V_19 -> V_28 ,
V_24 ) ;
V_19 -> V_8 -> V_31 .
V_59 [ V_19 ->
V_33 ]
&=
~ ( ( V_50 -> V_56 ==
1 ) ? 0x3 : 0xc ) ;
V_19 -> V_8 -> V_31 .
V_69 [ V_19 ->
V_33 ]
&=
~ ( ( V_50 -> V_56 ==
1 ) ? 0x3 : 0xc ) ;
V_19 -> V_8 -> V_31 . V_58 -- ;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 ==
1 ) ? 0 : 2 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_63 , 0 ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 ==
1 ) ? 1 : 3 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
F_5 ( V_19 -> V_8 , V_63 , 0 ) ;
F_5 ( V_19 -> V_8 , V_38 ,
V_19 -> V_33 ) ;
V_19 -> V_8 -> V_31 . V_65 &=
~ ( V_50 -> V_56 & 3 ) ;
F_5 ( V_19 -> V_8 , V_66 ,
V_19 -> V_8 -> V_31 . V_65 ) ;
F_27 ( & V_19 -> V_28 ,
V_24 ) ;
V_50 -> V_52 = V_53 ;
V_50 -> V_67 . V_20 . V_44 ( & V_50 -> V_67 . V_20 ,
V_47 |
V_45 ,
NULL ) ;
if ( V_50 -> V_55 ) {
F_23 ( V_50 -> V_55 ) ;
V_50 -> V_55 = NULL ;
}
if ( V_50 -> V_70 ) {
F_23 ( V_50 -> V_70 ) ;
V_50 -> V_70 = NULL ;
}
F_32 ( & V_50 -> V_54 ) ;
V_50 -> V_30 = 0 ;
V_50 -> V_71 = NULL ;
break;
}
if ( V_19 -> V_8 -> V_31 . V_58 ) {
F_5 ( V_19 -> V_8 , V_72 ,
V_73 ) ;
} else {
F_5 ( V_19 -> V_8 , V_72 , 0 ) ;
}
break;
default:
F_30 ( V_46
L_2 ,
V_16 ) ;
break;
}
if ( ! V_19 -> V_27 )
V_50 -> V_67 . V_20 . V_44 ( & V_50 -> V_67 . V_20 ,
V_47 | V_45 , NULL ) ;
}
static void
F_33 ( struct V_18 * V_19 )
{
T_4 V_24 ;
if ( ! V_19 -> V_27 )
return;
F_24 ( & V_19 -> V_28 , V_24 ) ;
if ( V_19 -> V_36 ) {
V_19 -> V_37 = 1 ;
F_5 ( V_19 -> V_8 , V_38 , V_19 -> V_33 ) ;
F_5 ( V_19 -> V_8 , V_39 , 0x11 ) ;
F_27 ( & V_19 -> V_28 , V_24 ) ;
V_19 -> V_43 . V_20 . V_44 ( & V_19 -> V_43 . V_20 ,
V_47 | V_45 , NULL ) ;
F_24 ( & V_19 -> V_28 , V_24 ) ;
V_19 -> V_37 = 1 ;
F_5 ( V_19 -> V_8 , V_39 , 0x1 ) ;
F_27 ( & V_19 -> V_28 , V_24 ) ;
} else {
F_5 ( V_19 -> V_8 , V_38 , V_19 -> V_33 ) ;
F_5 ( V_19 -> V_8 , V_39 , 0x13 ) ;
F_27 ( & V_19 -> V_28 , V_24 ) ;
V_19 -> V_43 . V_20 . V_44 ( & V_19 -> V_43 . V_20 ,
V_47 | V_45 , NULL ) ;
F_24 ( & V_19 -> V_28 , V_24 ) ;
F_5 ( V_19 -> V_8 , V_38 , V_19 -> V_33 ) ;
F_5 ( V_19 -> V_8 , V_39 , 0x3 ) ;
F_27 ( & V_19 -> V_28 , V_24 ) ;
}
}
static void
F_34 ( struct V_18 * V_51 , int V_74 )
{
int V_75 , V_76 ;
T_2 V_77 , V_78 , V_79 ;
struct V_22 * V_23 ;
T_2 * V_80 ;
if ( ! V_51 -> V_27 )
return;
do {
F_5 ( V_51 -> V_8 , V_60 ,
( V_51 -> V_33 * 8 + ( ( V_74 ) ? 7 : 5 ) ) ) ;
F_19 ( V_51 -> V_8 ) ;
V_77 = F_20 ( V_51 -> V_8 , V_81 ) ;
V_78 = F_12 ( V_51 -> V_8 , V_82 ) ;
V_79 = V_77 - V_78 ;
if ( ( V_77 - V_78 ) < 0 )
V_79 = V_77 - V_78 + V_83 + 1 ;
if ( ! V_79 ) {
return;
}
V_75 = F_21 ( V_51 -> V_8 , V_84 ) ;
V_76 = F_14 ( V_51 -> V_8 , V_85 ) ;
V_75 = V_75 - V_76 + 1 ;
if ( V_75 < 0 )
V_75 += 384 ;
if ( ! ( V_23 = F_35 ( V_86 ) ) ) {
F_30 ( V_46
L_3
L_4 ) ;
F_5 ( V_51 -> V_8 , V_64 , 2 ) ;
F_19 ( V_51 -> V_8 ) ;
return;
}
if ( ( ( V_75 < 4 ) || ( V_75 > V_86 ) ) ) {
if ( V_23 )
F_23 ( V_23 ) ;
if ( V_79 == 1 ) {
F_5 ( V_51 -> V_8 , V_64 , 2 ) ;
F_19 ( V_51 -> V_8 ) ;
return;
} else {
#ifndef F_36
F_1 ( V_51 -> V_8 , V_87 ) ;
#endif
while ( V_75 >= 4 ) {
#ifdef F_36
F_16 ( V_51 -> V_8 , V_87 ) ;
#else
F_18 ( V_51 -> V_8 ) ;
#endif
V_75 -= 4 ;
}
while ( V_75 -- )
#ifdef F_36
F_12 ( V_51 -> V_8 , V_87 ) ;
#else
F_13 ( V_51 -> V_8 ) ;
#endif
F_5 ( V_51 -> V_8 , V_64 , 1 ) ;
F_19 ( V_51 -> V_8 ) ;
return;
}
}
V_80 = V_23 -> V_88 ;
#ifndef F_36
F_1 ( V_51 -> V_8 , V_87 ) ;
#endif
while ( V_75 >= 4 ) {
#ifdef F_36
* ( ( unsigned long * ) V_80 ) =
F_16 ( V_51 -> V_8 , V_87 ) ;
#else
* ( ( unsigned long * ) V_80 ) = F_18 ( V_51 -> V_8 ) ;
#endif
V_80 += 4 ;
V_75 -= 4 ;
}
while ( V_75 -- )
#ifdef F_36
* V_80 ++ = F_12 ( V_51 -> V_8 , V_87 ) ;
#else
* V_80 ++ = F_13 ( V_51 -> V_8 ) ;
#endif
F_5 ( V_51 -> V_8 , V_64 , 1 ) ;
F_19 ( V_51 -> V_8 ) ;
if ( * ( -- V_80 ) ) {
F_23 ( V_23 ) ;
} else {
V_23 -> V_89 = ( V_80 - V_23 -> V_88 ) - 2 ;
if ( V_74 )
V_51 -> V_43 . V_20 . V_44 ( & V_51 -> V_43 . V_20 ,
V_90 | V_45 ,
V_23 ) ;
else
V_51 -> V_43 . V_20 . V_44 ( & V_51 -> V_43 . V_20 ,
V_25 | V_45 ,
V_23 ) ;
}
} while ( 1 );
}
static void
F_37 ( struct V_49 * V_50 )
{
int V_75 , V_76 , V_91 ;
T_2 V_77 , V_78 ;
struct V_18 * V_19 = V_50 -> V_51 ;
struct V_22 * V_23 ;
if ( ! V_19 -> V_27 || ( V_50 -> V_52 == V_53 ) )
return;
do {
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 + ( ( V_50 -> V_56 == 1 ) ? 1 : 3 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
if ( V_50 -> V_52 == V_57 ) {
V_77 = F_20 ( V_19 -> V_8 , V_81 ) ;
V_78 = F_12 ( V_19 -> V_8 , V_82 ) ;
V_91 = ( ( V_77 ^ V_78 ) & V_83 ) ;
} else
V_91 = 0 ;
V_75 = F_21 ( V_19 -> V_8 , V_84 ) ;
V_76 = F_14 ( V_19 -> V_8 , V_85 ) ;
V_75 = ( V_75 - V_76 ) ;
if ( V_91 )
V_75 ++ ;
if ( V_75 < 0 )
V_75 += 384 ;
if ( ! V_75 )
break;
if ( ! ( V_23 = V_50 -> V_70 ) ) {
if ( !
( V_23 =
F_35 ( ( V_50 -> V_52 ==
V_68 ) ? V_75
: ( V_92 + 3 ) ) ) ) {
F_30 ( V_93
L_5
L_4 ) ;
return;
}
V_50 -> V_71 = V_23 -> V_88 ;
V_50 -> V_70 = V_23 ;
}
V_23 -> V_89 = ( V_50 -> V_71 - V_23 -> V_88 ) + V_75 ;
if ( ( V_50 -> V_52 == V_57 ) &&
( ( V_91 && ( V_23 -> V_89 < 4 ) ) ||
( V_23 -> V_89 > ( V_92 + 3 ) ) ) ) {
V_23 -> V_89 = 0 ;
V_50 -> V_71 = V_23 -> V_88 ;
F_5 ( V_19 -> V_8 , V_64 , 2 ) ;
F_19 ( V_19 -> V_8 ) ;
return;
}
#ifndef F_36
F_1 ( V_19 -> V_8 , V_87 ) ;
#endif
while ( V_75 >= 4 ) {
#ifdef F_36
* ( ( unsigned long * ) V_50 -> V_71 ) =
F_16 ( V_19 -> V_8 , V_87 ) ;
#else
* ( ( unsigned long * ) V_50 -> V_71 ) =
F_18 ( V_19 -> V_8 ) ;
#endif
V_50 -> V_71 += 4 ;
V_75 -= 4 ;
}
while ( V_75 -- )
#ifdef F_36
* ( V_50 -> V_71 ++ ) = F_12 ( V_19 -> V_8 , V_87 ) ;
#else
* ( V_50 -> V_71 ++ ) = F_13 ( V_19 -> V_8 ) ;
#endif
if ( V_91 ) {
F_5 ( V_19 -> V_8 , V_64 , 1 ) ;
F_19 ( V_19 -> V_8 ) ;
V_50 -> V_71 -- ;
if ( * V_50 -> V_71 ) {
V_23 -> V_89 = 0 ;
V_50 -> V_71 = V_23 -> V_88 ;
continue;
}
V_23 -> V_89 -= 3 ;
}
if ( V_91 || ( V_50 -> V_52 == V_68 ) ) {
V_50 -> V_70 = NULL ;
V_50 -> V_71 = NULL ;
V_50 -> V_67 . V_20 . V_44 ( & V_50 -> V_67 . V_20 ,
V_25 | V_45 , V_23 ) ;
}
} while ( 1 );
}
static void
F_38 ( struct V_18 * V_51 )
{
struct V_22 * V_23 ;
T_2 V_77 , V_78 ;
T_2 * V_80 ;
long V_94 ;
if ( V_51 -> V_37 != 7 )
return;
F_5 ( V_51 -> V_8 , V_60 , ( V_51 -> V_33 * 8 + 4 ) ) ;
F_19 ( V_51 -> V_8 ) ;
V_77 = F_12 ( V_51 -> V_8 , V_81 ) ;
V_78 = F_20 ( V_51 -> V_8 , V_82 ) ;
if ( ( V_77 ^ V_78 ) & V_83 )
return;
if ( V_51 -> V_30 > 0 ) {
V_94 = V_51 -> V_30 ;
V_51 -> V_30 = 0 ;
V_51 -> V_43 . V_20 . V_44 ( & V_51 -> V_43 . V_20 , V_25 | V_95 ,
( void * ) V_94 ) ;
}
if ( ( V_23 = F_39 ( & V_51 -> V_29 ) ) ) {
V_80 = V_23 -> V_88 ;
V_94 = V_23 -> V_89 ;
#ifndef F_36
F_1 ( V_51 -> V_8 , V_87 ) ;
#endif
while ( V_94 >= 4 ) {
#ifdef F_36
F_11 ( V_51 -> V_8 , V_87 ,
* ( unsigned long * ) V_80 ) ;
#else
F_1 ( V_51 -> V_8 , V_87 ) ;
F_11 ( V_51 -> V_8 , * ( unsigned long * ) V_80 ) ;
#endif
V_80 += 4 ;
V_94 -= 4 ;
}
#ifdef F_36
while ( V_94 -- )
F_6 ( V_51 -> V_8 , V_87 , * V_80 ++ ) ;
#else
while ( V_94 -- )
F_6 ( V_51 -> V_8 , * V_80 ++ ) ;
#endif
V_51 -> V_30 = V_23 -> V_96 ;
F_5 ( V_51 -> V_8 , V_64 , 1 ) ;
F_19 ( V_51 -> V_8 ) ;
F_23 ( V_23 ) ;
}
}
static void
F_40 ( struct V_49 * V_50 )
{
struct V_22 * V_23 ;
struct V_18 * V_19 = V_50 -> V_51 ;
T_2 * V_80 ;
int V_94 , V_97 , V_98 ;
long V_99 = 0 ;
if ( ! V_19 -> V_27 || ( V_50 -> V_52 == V_53 ) )
return;
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 + ( ( V_50 -> V_56 == 1 ) ? 0 : 2 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
do {
if ( V_50 -> V_52 == V_57 ) {
V_98 = F_12 ( V_19 -> V_8 , V_81 ) & V_83 ;
V_98 -=
( F_20 ( V_19 -> V_8 , V_82 ) & V_83 ) ;
if ( V_98 < 0 )
V_98 += 16 ;
if ( V_98 >= 15 )
break;
} else
V_98 = 0 ;
if ( ! ( V_23 = V_50 -> V_55 ) ) {
if ( ! ( V_23 = F_39 ( & V_50 -> V_54 ) ) ) {
V_19 -> V_8 -> V_31 . V_59 [ V_19 ->
V_33 ]
&= ~ ( ( V_50 -> V_56 == 1 ) ? 1 : 4 ) ;
break;
}
V_50 -> V_55 = V_23 ;
V_50 -> V_30 = 0 ;
}
if ( ! V_98 )
V_19 -> V_8 -> V_31 . V_59 [ V_19 -> V_33 ] |=
( ( V_50 -> V_56 == 1 ) ? 1 : 4 ) ;
else
V_19 -> V_8 -> V_31 . V_59 [ V_19 -> V_33 ] &=
~ ( ( V_50 -> V_56 == 1 ) ? 1 : 4 ) ;
V_97 = F_21 ( V_19 -> V_8 , V_85 ) ;
V_97 -= F_14 ( V_19 -> V_8 , V_84 ) ;
if ( V_97 <= 0 )
V_97 += 384 ;
V_97 -- ;
if ( V_97 < 16 )
break;
V_94 = V_23 -> V_89 - V_50 -> V_30 ;
if ( V_94 > V_97 )
V_94 = V_97 ;
V_80 = V_23 -> V_88 + V_50 -> V_30 ;
V_50 -> V_30 += V_94 ;
#ifndef F_36
F_1 ( V_19 -> V_8 , V_87 ) ;
#endif
while ( V_94 >= 4 ) {
#ifdef F_36
F_11 ( V_19 -> V_8 , V_87 ,
* ( unsigned long * ) V_80 ) ;
#else
F_11 ( V_19 -> V_8 , * ( unsigned long * ) V_80 ) ;
#endif
V_80 += 4 ;
V_94 -= 4 ;
}
while ( V_94 -- )
#ifdef F_36
F_6 ( V_19 -> V_8 , V_87 , * V_80 ++ ) ;
#else
F_6 ( V_19 -> V_8 , * V_80 ++ ) ;
#endif
if ( V_50 -> V_30 >= V_23 -> V_89 ) {
if ( V_50 -> V_52 == V_57 ) {
F_5 ( V_19 -> V_8 , V_64 , 1 ) ;
}
V_99 += V_23 -> V_96 ;
V_50 -> V_55 = NULL ;
V_50 -> V_30 = 0 ;
F_23 ( V_23 ) ;
} else
F_5 ( V_19 -> V_8 , V_60 ,
( V_19 -> V_33 * 8 +
( ( V_50 -> V_56 == 1 ) ? 0 : 2 ) ) ) ;
F_19 ( V_19 -> V_8 ) ;
} while ( 1 );
if ( V_99 )
V_50 -> V_67 . V_20 . V_44 ( (struct V_48 * ) & V_50 -> V_67 ,
V_25 | V_95 , ( void * ) V_99 ) ;
}
static void
F_41 ( struct V_100 * V_101 )
{
T_1 * V_8 = F_42 ( V_101 , T_1 , V_34 ) ;
T_2 V_2 ;
struct V_18 * V_51 ;
volatile T_2 * V_102 ;
int V_103 ;
V_2 = 1 ;
V_51 = V_8 -> V_19 ;
while ( V_2 ) {
if ( ( V_2 & V_8 -> V_31 . V_104 ) ) {
V_8 -> V_31 . V_104 &= ~ V_2 ;
if ( V_51 -> V_27 ) {
if ( V_51 -> V_36 ) {
T_2 V_105 = V_51 -> V_37 ;
F_5 ( V_51 -> V_8 , V_38 ,
V_51 -> V_33 ) ;
V_51 -> V_37 =
F_12 ( V_51 -> V_8 ,
V_106 ) & 0xf ;
if ( ( V_105 == 3 )
&& ( V_51 -> V_37 != 3 ) )
V_51 -> V_43 . V_20 . V_44 ( & V_51 ->
V_43 .
V_20 ,
V_47
|
V_45 ,
NULL ) ;
if ( V_51 -> V_37 != 2 ) {
F_43 ( & V_51 -> V_40 ) ;
if ( V_51 -> V_37 == 3 ) {
V_51 -> V_43 . V_20 .
V_44 ( & V_51 ->
V_43 . V_20 ,
V_35
|
V_45 ,
NULL ) ;
}
} else {
F_5 ( V_8 , V_39 ,
V_107 ) ;
F_29 ( & V_51 -> V_40 ,
V_41 +
V_108 ) ;
}
F_30 ( V_46
L_6 ,
V_51 -> V_33 , V_105 ,
V_51 -> V_37 ) ;
} else {
T_2 V_105 = V_51 -> V_37 ;
F_5 ( V_51 -> V_8 , V_38 ,
V_51 -> V_33 ) ;
V_51 -> V_37 =
F_12 ( V_51 -> V_8 ,
V_106 ) & 0xf ;
if ( ( ( V_51 -> V_37 == 3 ) &&
( ( V_105 == 7 ) ||
( V_105 == 8 ) ) ) ||
( ( F_44
( & V_51 -> V_40 ) )
&& ( V_51 -> V_37 == 8 ) ) ) {
F_29 ( & V_51 -> V_40 ,
V_109 +
V_41 ) ;
} else {
if ( V_51 -> V_37 == 7 ) {
F_43 ( & V_51 ->
V_40 ) ;
V_51 -> V_43 . V_20 .
V_44 ( & V_51 ->
V_43 . V_20 ,
V_35
|
V_45 ,
NULL ) ;
F_38 ( V_51 ) ;
}
if ( V_51 -> V_37 == 3 ) {
if ( V_105 != 3 )
V_51 -> V_43 .
V_20 .
V_44
( & V_51 ->
V_43 .
V_20 ,
V_47
|
V_45 ,
NULL ) ;
}
}
F_30 ( V_46
L_7 ,
V_51 -> V_8 -> V_110 ,
V_51 -> V_33 , V_105 ,
V_51 -> V_37 ) ;
}
}
}
V_2 <<= 1 ;
V_51 ++ ;
}
V_103 = 0 ;
V_102 = V_8 -> V_31 . V_32 ;
V_51 = V_8 -> V_19 ;
while ( V_103 < V_8 -> V_111 . V_112 ) {
if ( V_8 -> V_31 . V_113 ) {
* V_102 |= V_8 -> V_31 . V_69 [ V_103 ] ;
if ( V_8 -> V_114 <= 0 ) {
* V_102 |=
V_8 -> V_31 . V_59 [ V_51 ->
V_33 ] ;
}
}
* V_102 &= 0xff - 0x40 ;
while ( * V_102 ) {
if ( ! V_51 -> V_36 ) {
if ( ( * V_102 & 0x20 ) ) {
* V_102 &= ~ 0x20 ;
F_34 ( V_51 , 0 ) ;
}
if ( ( * V_102 & 0x80 ) ) {
* V_102 &= ~ 0x80 ;
F_34 ( V_51 , 1 ) ;
}
if ( ( * V_102 & 0x10 ) ) {
* V_102 &= ~ 0x10 ;
F_38 ( V_51 ) ;
}
}
if ( ( * V_102 & 0x2 ) ) {
* V_102 &= ~ 0x2 ;
F_37 ( V_51 -> V_115 ) ;
}
if ( ( * V_102 & 0x1 ) ) {
* V_102 &= ~ 0x1 ;
F_40 ( V_51 -> V_115 ) ;
}
if ( ( * V_102 & 0x8 ) ) {
* V_102 &= ~ 0x8 ;
F_37 ( V_51 -> V_115 + 1 ) ;
}
if ( ( * V_102 & 0x4 ) ) {
* V_102 &= ~ 0x4 ;
F_40 ( V_51 -> V_115 + 1 ) ;
}
}
V_102 ++ ;
V_51 ++ ;
V_103 ++ ;
}
if ( V_8 -> V_114 <= 0 )
V_8 -> V_114 += ( 1 << ( 7 - V_116 ) ) ;
V_8 -> V_31 . V_113 = 0 ;
}
static T_5
F_45 ( int V_117 , void * V_118 )
{
T_1 * V_8 = V_118 ;
T_2 V_2 , V_119 ;
volatile T_2 * V_120 ;
int V_103 ;
T_2 V_121 ;
if ( ! V_8 || ! ( V_8 -> V_31 . V_122 & V_123 ) )
return V_124 ;
#ifndef F_36
V_121 = F_3 ( V_8 ) ;
#endif
V_8 -> V_31 . V_104 |=
( F_12 ( V_8 , V_125 ) & V_8 -> V_31 . V_126 ) ;
if ( !
( V_2 = ( F_12 ( V_8 , V_6 ) & ( V_127 | V_128 ) ) )
&& ! V_8 -> V_31 . V_104 ) {
#ifndef F_36
F_1 ( V_8 , V_121 ) ;
#endif
return V_124 ;
}
if ( F_12 ( V_8 , V_129 ) & V_130 ) {
V_8 -> V_31 . V_113 = 1 ;
V_8 -> V_114 -- ;
}
if ( ( V_119 = F_12 ( V_8 , V_131 ) ) ) {
V_8 -> V_31 . V_132 |= V_119 ;
V_103 = V_133 ;
V_120 = V_8 -> V_31 . V_32 ;
while ( V_119 ) {
if ( ( V_119 & 1 ) ) {
* V_120 |= F_12 ( V_8 , V_103 ) ;
}
V_120 ++ ;
V_103 ++ ;
V_119 >>= 1 ;
}
}
F_28 ( & V_8 -> V_34 ) ;
#ifndef F_36
F_1 ( V_8 , V_121 ) ;
#endif
return V_134 ;
}
static void
F_46 ( T_1 * V_8 )
{
T_4 V_24 ;
F_24 ( & V_8 -> V_28 , V_24 ) ;
F_5 ( V_8 , V_135 , 0 ) ;
F_5 ( V_8 , V_136 , 0 ) ;
F_5 ( V_8 , V_137 , 0 ) ;
F_5 ( V_8 , V_138 , V_139 ) ;
V_8 -> V_31 . V_122 = 0 ;
F_27 ( & V_8 -> V_28 , V_24 ) ;
F_47 ( 3 ) ;
F_5 ( V_8 , V_138 , 0 ) ;
F_19 ( V_8 ) ;
F_5 ( V_8 , V_140 , V_141 ) ;
F_5 ( V_8 , V_136 , V_142 ) ;
if ( V_8 -> V_111 . V_143 == 1 )
F_5 ( V_8 , V_144 , V_145 ) ;
F_5 ( V_8 , V_146 , V_116 ) ;
memset ( & V_8 -> V_31 , 0 , sizeof( V_8 -> V_31 ) ) ;
}
static void
F_48 ( T_1 * V_8 , int V_147 , int V_36 )
{
T_4 V_24 ;
char V_148 [ 40 ] ;
int V_149 ;
if ( V_147 ) {
V_8 -> V_36 = V_36 ;
V_8 -> V_31 . V_122 = V_150 ;
F_5 ( V_8 , V_151 , V_8 -> V_31 . V_122 ) ;
V_8 -> V_31 . V_126 = 0 ;
F_5 ( V_8 , V_152 , V_8 -> V_31 . V_126 ) ;
F_5 ( V_8 , V_153 , 0x80 ) ;
F_5 ( V_8 , V_154 , 26 ) ;
if ( ! V_36 )
F_5 ( V_8 , V_155 , V_156 ) ;
for ( V_149 = 0 ; V_149 < V_8 -> V_111 . V_112 ; V_149 ++ ) {
V_8 -> V_31 . V_126 |= ( 1 << V_149 ) ;
F_5 ( V_8 , V_152 , V_8 -> V_31 . V_126 ) ;
F_5 ( V_8 , V_38 , V_149 ) ;
F_5 ( V_8 , V_157 ,
( ( V_36 ) ? V_158 : V_159 ) ) ;
V_8 -> V_31 . V_65 = ( ( V_36 ) ? V_160 : V_161 ) ;
F_5 ( V_8 , V_66 , V_8 -> V_31 . V_65 ) ;
F_5 ( V_8 , V_162 , 3 ) ;
F_5 ( V_8 , V_39 , 0 ) ;
V_8 -> V_19 [ V_149 ] . V_27 = 1 ;
V_8 -> V_19 [ V_149 ] . V_36 = V_36 ;
if ( ! V_36 ) {
F_5 ( V_8 , V_60 , V_149 * 8 + 7 ) ;
F_19 ( V_8 ) ;
F_5 ( V_8 , V_61 , 0x11 ) ;
F_5 ( V_8 , V_62 , 2 ) ;
F_5 ( V_8 , V_63 , 1 ) ;
F_5 ( V_8 , V_64 , 2 ) ;
F_19 ( V_8 ) ;
F_5 ( V_8 , V_60 , V_149 * 8 + 5 ) ;
F_19 ( V_8 ) ;
F_5 ( V_8 , V_61 , 0x11 ) ;
F_5 ( V_8 , V_62 , 2 ) ;
F_5 ( V_8 , V_63 , 1 ) ;
F_5 ( V_8 , V_64 , 2 ) ;
F_19 ( V_8 ) ;
F_5 ( V_8 , V_60 , V_149 * 8 + 4 ) ;
F_19 ( V_8 ) ;
F_5 ( V_8 , V_61 , 0x11 ) ;
F_5 ( V_8 , V_62 , 2 ) ;
F_5 ( V_8 , V_63 , 1 ) ;
F_5 ( V_8 , V_64 , 2 ) ;
F_19 ( V_8 ) ;
}
sprintf ( V_148 , L_8 , V_8 -> V_110 , V_149 ) ;
if ( F_49
( & V_8 -> V_19 [ V_149 ] . V_43 , V_8 -> V_19 [ V_149 ] . V_163 , V_148 ,
( ( V_36 ) ? 3 : 2 ) ) ) {
V_8 -> V_19 [ V_149 ] . V_27 = 0 ;
V_8 -> V_31 . V_126 &= ~ ( 1 << V_149 ) ;
F_5 ( V_8 , V_152 ,
V_8 -> V_31 . V_126 ) ;
F_30 ( V_46
L_9 ,
V_148 ) ;
break;
}
}
F_24 ( & V_8 -> V_28 , V_24 ) ;
V_8 -> V_31 . V_122 |= V_123 ;
F_5 ( V_8 , V_151 , V_8 -> V_31 . V_122 ) ;
F_27 ( & V_8 -> V_28 , V_24 ) ;
} else {
F_24 ( & V_8 -> V_28 , V_24 ) ;
V_8 -> V_31 . V_122 &= ~ V_123 ;
F_5 ( V_8 , V_151 , V_8 -> V_31 . V_122 ) ;
F_27 ( & V_8 -> V_28 , V_24 ) ;
for ( V_149 = V_8 -> V_111 . V_112 - 1 ; V_149 >= 0 ; V_149 -- ) {
V_8 -> V_19 [ V_149 ] . V_27 = 0 ;
F_50 ( & V_8 -> V_19 [ V_149 ] . V_43 ) ;
F_43 ( & V_8 -> V_19 [ V_149 ] . V_40 ) ;
F_32 ( & V_8 -> V_19 [ V_149 ] . V_29 ) ;
F_32 ( & V_8 -> V_19 [ V_149 ] . V_115 [ 0 ] . V_54 ) ;
F_32 ( & V_8 -> V_19 [ V_149 ] . V_115 [ 1 ] . V_54 ) ;
}
F_46 ( V_8 ) ;
}
}
static void
F_51 ( T_1 * V_8 )
{
F_52 ( V_8 -> V_164 , V_165 , 0 ) ;
#ifdef F_36
if ( V_8 -> V_166 )
F_53 ( ( void * ) V_8 -> V_166 ) ;
#else
if ( V_8 -> V_3 )
F_54 ( V_8 -> V_3 , 8 ) ;
#endif
}
static void
F_55 ( T_1 * V_8 )
{
#ifdef F_36
F_52 ( V_8 -> V_164 , V_165 , V_167 ) ;
#else
F_52 ( V_8 -> V_164 , V_165 , V_168 ) ;
#endif
}
static int
F_56 ( T_1 * V_8 )
{
int V_169 = - V_170 ;
int V_149 ;
for ( V_149 = 0 ; V_149 < V_171 ; V_149 ++ ) {
struct V_18 * V_51 ;
V_51 = V_8 -> V_19 + V_149 ;
F_57 ( & V_51 -> V_28 ) ;
V_51 -> V_8 = V_8 ;
V_51 -> V_40 . V_172 = ( void * ) F_33 ;
V_51 -> V_40 . V_88 = ( long ) ( V_51 ) ;
F_58 ( & V_51 -> V_40 ) ;
V_51 -> V_33 = V_149 ;
F_59 ( & V_51 -> V_29 ) ;
V_51 -> V_43 . V_20 . V_21 = V_8 -> V_19 + V_149 ;
V_51 -> V_43 . V_20 . V_173 = ( void * ) F_22 ;
F_57 ( & V_51 -> V_115 [ 0 ] . V_28 ) ;
V_51 -> V_115 [ 0 ] . V_67 . V_20 . V_173 = ( void * ) F_31 ;
V_51 -> V_115 [ 0 ] . V_67 . V_20 . V_21 = ( void * ) & V_51 -> V_115 [ 0 ] ;
V_51 -> V_115 [ 0 ] . V_51 = V_8 -> V_19 + V_149 ;
V_51 -> V_115 [ 0 ] . V_56 = 1 ;
V_51 -> V_163 [ 0 ] = & V_51 -> V_115 [ 0 ] . V_67 ;
F_59 ( & V_51 -> V_115 [ 0 ] . V_54 ) ;
F_57 ( & V_51 -> V_115 [ 1 ] . V_28 ) ;
V_51 -> V_115 [ 1 ] . V_67 . V_20 . V_173 = ( void * ) F_31 ;
V_51 -> V_115 [ 1 ] . V_67 . V_20 . V_21 = ( void * ) & V_51 -> V_115 [ 1 ] ;
V_51 -> V_115 [ 1 ] . V_51 = V_8 -> V_19 + V_149 ;
V_51 -> V_115 [ 1 ] . V_56 = 2 ;
V_51 -> V_163 [ 1 ] = & V_51 -> V_115 [ 1 ] . V_67 ;
F_59 ( & V_51 -> V_115 [ 1 ] . V_54 ) ;
}
F_55 ( V_8 ) ;
F_46 ( V_8 ) ;
V_149 = F_12 ( V_8 , V_174 ) >> V_175 ;
if ( V_149 != V_8 -> V_111 . V_176 ) {
F_30 ( V_46
L_10 ,
V_149 , V_8 -> V_111 . V_176 ) ;
goto V_177;
}
V_149 = F_12 ( V_8 , V_178 ) & 0xf ;
if ( ! V_149 ) {
F_30 ( V_46
L_11 ) ;
goto V_177;
}
F_60 ( & V_8 -> V_34 , F_41 ) ;
if ( F_61
( V_8 -> V_179 , F_45 , V_180 , V_8 -> V_181 , V_8 ) ) {
F_30 ( V_46
L_12 ,
V_8 -> V_179 ) ;
goto V_177;
}
#ifdef F_36
F_30 ( V_46
L_13 ,
V_8 -> V_182 , V_8 -> V_179 ) ;
#else
F_30 ( V_46
L_14 ,
V_8 -> V_3 , V_8 -> V_179 ) ;
#endif
F_48 ( V_8 , 1 , 0 ) ;
return ( 0 ) ;
V_177:
V_8 -> V_179 = 0 ;
F_51 ( V_8 ) ;
F_62 ( V_8 ) ;
return ( V_169 ) ;
}
static int
F_63 ( struct V_183 * V_164 , const struct V_184 * V_185 )
{
int V_169 = - V_186 ;
T_6 * V_111 = ( T_6 * ) V_185 -> V_111 ;
T_1 * V_8 ;
if ( ! ( V_8 = F_64 ( sizeof( T_1 ) , V_187 ) ) ) {
F_30 ( V_93 L_15 ) ;
return ( V_169 ) ;
}
V_8 -> V_164 = V_164 ;
V_169 = F_65 ( V_164 ) ;
if ( V_169 )
goto V_177;
V_8 -> V_110 = V_188 ;
sprintf ( V_8 -> V_181 , L_16 , V_8 -> V_110 ) ;
F_30 ( V_46 L_17 ,
V_111 -> V_189 , V_8 -> V_181 , F_66 ( V_164 ) ) ;
F_57 ( & V_8 -> V_28 ) ;
V_8 -> V_111 = * V_111 ;
V_8 -> V_179 = V_164 -> V_179 ;
V_8 -> V_3 = F_67 ( V_164 , 0 ) ;
#ifdef F_36
V_8 -> V_182 = ( T_2 * ) F_67 ( V_164 , 1 ) ;
V_8 -> V_166 = F_68 ( ( V_190 ) V_8 -> V_182 , 256 ) ;
#else
if ( ! F_69 ( V_8 -> V_3 , 8 , V_8 -> V_181 ) ) {
F_30 ( V_46
L_18 ,
V_8 -> V_3 ) ;
goto V_177;
}
#endif
F_70 ( V_164 , V_8 ) ;
V_169 = F_56 ( V_8 ) ;
if ( ! V_169 )
V_188 ++ ;
return ( V_169 ) ;
V_177:
F_62 ( V_8 ) ;
return ( V_169 ) ;
}
static void
F_71 ( struct V_183 * V_164 )
{
T_1 * V_8 = F_72 ( V_164 ) ;
F_30 ( V_46 L_19 , V_8 -> V_110 ) ;
F_48 ( V_8 , 0 , 0 ) ;
if ( V_8 -> V_179 )
F_73 ( V_8 -> V_179 , V_8 ) ;
V_8 -> V_179 = 0 ;
F_51 ( V_8 ) ;
V_188 -- ;
F_74 ( V_164 ) ;
F_62 ( V_8 ) ;
return;
}
static int T_7
F_75 ( void )
{
int V_169 ;
F_30 ( V_46
L_20 ,
V_191 ) ;
F_30 ( V_46
L_21 ) ;
V_188 = 0 ;
V_169 = F_76 ( & V_192 ) ;
if ( V_169 < 0 ) {
goto V_177;
}
F_30 ( V_46 L_22 , V_188 ) ;
return 0 ;
V_177:
return ( V_169 ) ;
}
static void T_8
F_77 ( void )
{
F_78 ( & V_192 ) ;
F_30 ( V_46 L_23 ) ;
}
