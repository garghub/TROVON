static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_6 = V_1 -> V_9 -> V_10 & V_11 ;
if ( ( V_6 == V_12 || V_6 == V_13 )
&& ! V_4 ) {
V_5 = F_2 ( V_2 , V_1 -> V_14 * 8 , V_1 -> V_8 ) ;
V_7 -> V_15 = ( V_16 ) V_17 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_21 : NULL ;
} else {
V_5 = F_3 ( V_2 , V_1 -> V_14 * 8 , V_1 -> V_8 ) ;
V_7 -> V_15 = ( V_16 ) V_22 ;
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) V_21 ;
else if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_26 ;
else
V_7 -> V_18 . V_19 = NULL ;
}
if ( V_5 < 0 ) {
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
if ( V_31 < V_33 )
return 1 ;
F_7 ( V_30 , V_29 , V_31 , V_1 -> V_8 , V_1 -> V_32 ) ;
return 1 ;
}
static int F_8 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
F_3 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 . V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 , ( V_16 ) V_22 ) ;
V_35 -> V_24 = ( V_25 ) V_26 ;
if ( V_3 == NULL && V_35 -> V_38 )
V_3 = V_35 -> V_3 ;
if ( V_3 ) {
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
}
V_35 -> V_40 = 1 ;
} else {
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
if ( V_2 ) {
if ( V_4 ) {
F_3 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_22 ;
V_42 -> V_18 = V_46 ;
} else {
F_2 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_17 ;
V_42 -> V_18 = V_47 ;
}
F_3 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 . V_36 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_22 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
}
if ( V_3 ) {
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
if ( V_2 ) {
F_3 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 . V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_22 ) ;
V_52 -> V_56 = V_4 ? ( V_57 ) V_58 :
( V_57 ) V_59 ;
V_52 -> V_40 = 1 ;
}
if ( V_3 ) {
memcpy ( V_1 -> V_3 , V_3 , 15 - V_52 -> V_55 ) ;
V_52 -> V_38 = 1 ;
}
return 1 ;
}
static int F_14 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 , V_60 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_6 = V_1 -> V_9 -> V_10 & V_11 ;
V_60 = V_1 -> V_14 * 8 ;
if ( ( V_6 == V_12 || V_6 == V_13 )
&& ! V_4 ) {
V_5 = 0 ;
F_15 ( V_2 , V_60 , V_1 -> V_8 ) ;
V_7 -> V_15 = ( V_16 ) V_61 ;
switch ( V_60 ) {
case 128 :
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_62 : NULL ;
break;
case 192 :
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_63 : NULL ;
break;
case 256 :
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_64 : NULL ;
break;
default:
V_5 = - 1 ;
}
} else {
V_5 = 0 ;
F_16 ( V_2 , V_60 , V_1 -> V_8 ) ;
V_7 -> V_15 = ( V_16 ) V_65 ;
switch ( V_60 ) {
case 128 :
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) V_66 ;
else if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_67 ;
else
V_7 -> V_18 . V_19 = NULL ;
break;
case 192 :
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) V_68 ;
else if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_69 ;
else
V_7 -> V_18 . V_19 = NULL ;
break;
case 256 :
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) V_70 ;
else if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_71 ;
else
V_7 -> V_18 . V_19 = NULL ;
break;
default:
V_5 = - 1 ;
}
}
if ( V_5 < 0 ) {
F_4 ( V_72 , V_28 ) ;
return 0 ;
}
return 1 ;
}
static int F_17 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
int V_60 = V_1 -> V_14 * 8 ;
F_16 ( V_2 , V_60 , & V_35 -> V_36 . V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_65 ) ;
switch ( V_60 ) {
case 128 :
V_35 -> V_24 = ( V_25 ) V_67 ;
break;
case 192 :
V_35 -> V_24 = ( V_25 ) V_69 ;
break;
case 256 :
V_35 -> V_24 = ( V_25 ) V_71 ;
break;
default:
return 0 ;
}
if ( V_3 == NULL && V_35 -> V_38 )
V_3 = V_35 -> V_3 ;
if ( V_3 ) {
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
}
V_35 -> V_40 = 1 ;
} else {
if ( V_35 -> V_40 )
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
else
memcpy ( V_35 -> V_3 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
V_35 -> V_41 = 0 ;
}
return 1 ;
}
static int F_18 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_42 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
int V_60 = V_1 -> V_14 * 4 ;
V_42 -> V_18 = NULL ;
if ( V_4 ) {
F_16 ( V_2 , V_60 , & V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_65 ;
switch ( V_60 ) {
case 128 :
V_42 -> V_18 = V_73 ;
break;
# if 0
case 192:
xctx->stream = aes192_t4_xts_encrypt;
break;
# endif
case 256 :
V_42 -> V_18 = V_74 ;
break;
default:
return 0 ;
}
} else {
F_15 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_61 ;
switch ( V_60 ) {
case 128 :
V_42 -> V_18 = V_75 ;
break;
# if 0
case 192:
xctx->stream = aes192_t4_xts_decrypt;
break;
# endif
case 256 :
V_42 -> V_18 = V_76 ;
break;
default:
return 0 ;
}
}
F_16 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 . V_36 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_65 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
}
if ( V_3 ) {
V_42 -> V_44 . V_51 = & V_42 -> V_48 ;
memcpy ( V_1 -> V_3 , V_3 , 16 ) ;
}
return 1 ;
}
static int F_19 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_52 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
int V_60 = V_1 -> V_14 * 8 ;
F_16 ( V_2 , V_60 , & V_52 -> V_36 . V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_65 ) ;
# if 0
switch (bits) {
case 128:
cctx->str = enc ? (ccm128_f) aes128_t4_ccm64_encrypt :
(ccm128_f) ae128_t4_ccm64_decrypt;
break;
case 192:
cctx->str = enc ? (ccm128_f) aes192_t4_ccm64_encrypt :
(ccm128_f) ae192_t4_ccm64_decrypt;
break;
case 256:
cctx->str = enc ? (ccm128_f) aes256_t4_ccm64_encrypt :
(ccm128_f) ae256_t4_ccm64_decrypt;
break;
default:
return 0;
}
# endif
V_52 -> V_40 = 1 ;
}
if ( V_3 ) {
memcpy ( V_1 -> V_3 , V_3 , 15 - V_52 -> V_55 ) ;
V_52 -> V_38 = 1 ;
}
return 1 ;
}
static int F_20 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
V_6 = V_1 -> V_9 -> V_10 & V_11 ;
if ( ( V_6 == V_12 || V_6 == V_13 )
&& ! V_4 )
# ifdef F_21
if ( F_21 ) {
V_5 = F_22 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_77 ;
V_7 -> V_18 . V_19 = NULL ;
# ifdef F_23
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) F_23 ;
# endif
} else
# endif
# ifdef F_24
if ( F_24 && V_6 == V_13 ) {
V_5 = F_25 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_78 ;
V_7 -> V_18 . V_19 = ( V_20 ) V_79 ;
} else
# endif
# ifdef F_26
if ( F_26 ) {
V_5 = F_27 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_80 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_81 : NULL ;
} else
# endif
{
V_5 = F_25 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_78 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_82 : NULL ;
} else
# ifdef F_21
if ( F_21 ) {
V_5 = F_28 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_83 ;
V_7 -> V_18 . V_19 = NULL ;
# ifdef F_23
if ( V_6 == V_13 )
V_7 -> V_18 . V_19 = ( V_20 ) F_23 ;
else
# endif
# ifdef F_29
if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) F_29 ;
else
# endif
( void ) 0 ;
} else
# endif
# ifdef F_24
if ( F_24 && V_6 == V_23 ) {
V_5 = F_30 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_84 ;
V_7 -> V_18 . V_24 = ( V_25 ) V_85 ;
} else
# endif
# ifdef F_26
if ( F_26 ) {
V_5 = F_31 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_86 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_81 : NULL ;
} else
# endif
{
V_5 = F_30 ( V_2 , V_1 -> V_14 * 8 , & V_7 -> V_36 . V_36 ) ;
V_7 -> V_15 = ( V_16 ) V_84 ;
V_7 -> V_18 . V_19 = V_6 == V_13 ?
( V_20 ) V_82 : NULL ;
# ifdef F_32
if ( V_6 == V_23 )
V_7 -> V_18 . V_24 = ( V_25 ) V_87 ;
# endif
}
if ( V_5 < 0 ) {
F_4 ( V_88 , V_28 ) ;
return 0 ;
}
return 1 ;
}
static int F_33 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_7 -> V_18 . V_19 )
(* V_7 -> V_18 . V_19 ) ( V_30 , V_29 , V_31 , & V_7 -> V_36 , V_1 -> V_3 , V_1 -> V_32 ) ;
else if ( V_1 -> V_32 )
F_34 ( V_30 , V_29 , V_31 , & V_7 -> V_36 , V_1 -> V_3 , V_7 -> V_15 ) ;
else
F_35 ( V_30 , V_29 , V_31 , & V_7 -> V_36 , V_1 -> V_3 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_36 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_3 V_33 = V_1 -> V_9 -> V_34 ;
T_3 V_89 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_31 < V_33 )
return 1 ;
for ( V_89 = 0 , V_31 -= V_33 ; V_89 <= V_31 ; V_89 += V_33 )
(* V_7 -> V_15 ) ( V_30 + V_89 , V_29 + V_89 , & V_7 -> V_36 ) ;
return 1 ;
}
static int F_37 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
F_38 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_90 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_39 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
F_40 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_90 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_41 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
F_42 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_90 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_43 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_1 -> V_10 & V_91 ) {
F_44 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_90 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
while ( V_31 >= V_92 ) {
F_44 ( V_30 , V_29 , V_92 * 8 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_90 , V_1 -> V_32 , V_7 -> V_15 ) ;
V_31 -= V_92 ;
}
if ( V_31 )
F_44 ( V_30 , V_29 , V_31 * 8 , & V_7 -> V_36 ,
V_1 -> V_3 , & V_1 -> V_90 , V_1 -> V_32 , V_7 -> V_15 ) ;
return 1 ;
}
static int F_45 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
unsigned int V_90 = V_1 -> V_90 ;
T_2 * V_7 = ( T_2 * ) V_1 -> V_8 ;
if ( V_7 -> V_18 . V_24 )
F_46 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , V_1 -> V_93 , & V_90 , V_7 -> V_18 . V_24 ) ;
else
F_47 ( V_30 , V_29 , V_31 , & V_7 -> V_36 ,
V_1 -> V_3 , V_1 -> V_93 , & V_90 , V_7 -> V_15 ) ;
V_1 -> V_90 = ( T_3 ) V_90 ;
return 1 ;
}
static int F_48 ( T_1 * V_94 )
{
T_4 * V_35 = V_94 -> V_8 ;
F_49 ( & V_35 -> V_37 , sizeof( V_35 -> V_37 ) ) ;
if ( V_35 -> V_3 != V_94 -> V_3 )
F_50 ( V_35 -> V_3 ) ;
return 1 ;
}
static void F_51 ( unsigned char * V_95 )
{
int V_96 = 8 ;
unsigned char V_94 ;
do {
-- V_96 ;
V_94 = V_95 [ V_96 ] ;
++ V_94 ;
V_95 [ V_96 ] = V_94 ;
if ( V_94 )
return;
} while ( V_96 );
}
static int F_52 ( T_1 * V_94 , int type , int V_97 , void * V_98 )
{
T_4 * V_35 = V_94 -> V_8 ;
switch ( type ) {
case V_99 :
V_35 -> V_40 = 0 ;
V_35 -> V_38 = 0 ;
V_35 -> V_39 = V_94 -> V_9 -> V_100 ;
V_35 -> V_3 = V_94 -> V_3 ;
V_35 -> V_101 = - 1 ;
V_35 -> V_41 = 0 ;
V_35 -> V_102 = - 1 ;
return 1 ;
case V_103 :
if ( V_97 <= 0 )
return 0 ;
if ( ( V_97 > V_104 ) && ( V_97 > V_35 -> V_39 ) ) {
if ( V_35 -> V_3 != V_94 -> V_3 )
F_50 ( V_35 -> V_3 ) ;
V_35 -> V_3 = F_53 ( V_97 ) ;
if ( ! V_35 -> V_3 )
return 0 ;
}
V_35 -> V_39 = V_97 ;
return 1 ;
case V_105 :
if ( V_97 <= 0 || V_97 > 16 || V_94 -> V_32 )
return 0 ;
memcpy ( V_94 -> V_93 , V_98 , V_97 ) ;
V_35 -> V_101 = V_97 ;
return 1 ;
case V_106 :
if ( V_97 <= 0 || V_97 > 16 || ! V_94 -> V_32 || V_35 -> V_101 < 0 )
return 0 ;
memcpy ( V_98 , V_94 -> V_93 , V_97 ) ;
return 1 ;
case V_107 :
if ( V_97 == - 1 ) {
memcpy ( V_35 -> V_3 , V_98 , V_35 -> V_39 ) ;
V_35 -> V_41 = 1 ;
return 1 ;
}
if ( ( V_97 < 4 ) || ( V_35 -> V_39 - V_97 ) < 8 )
return 0 ;
if ( V_97 )
memcpy ( V_35 -> V_3 , V_98 , V_97 ) ;
if ( V_94 -> V_32 && F_54 ( V_35 -> V_3 + V_97 , V_35 -> V_39 - V_97 ) <= 0 )
return 0 ;
V_35 -> V_41 = 1 ;
return 1 ;
case V_108 :
if ( V_35 -> V_41 == 0 || V_35 -> V_40 == 0 )
return 0 ;
F_10 ( & V_35 -> V_37 , V_35 -> V_3 , V_35 -> V_39 ) ;
if ( V_97 <= 0 || V_97 > V_35 -> V_39 )
V_97 = V_35 -> V_39 ;
memcpy ( V_98 , V_35 -> V_3 + V_35 -> V_39 - V_97 , V_97 ) ;
F_51 ( V_35 -> V_3 + V_35 -> V_39 - 8 ) ;
V_35 -> V_38 = 1 ;
return 1 ;
case V_109 :
if ( V_35 -> V_41 == 0 || V_35 -> V_40 == 0 || V_94 -> V_32 )
return 0 ;
memcpy ( V_35 -> V_3 + V_35 -> V_39 - V_97 , V_98 , V_97 ) ;
F_10 ( & V_35 -> V_37 , V_35 -> V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
return 1 ;
case V_110 :
if ( V_97 != 13 )
return 0 ;
memcpy ( V_94 -> V_93 , V_98 , V_97 ) ;
V_35 -> V_102 = V_97 ;
{
unsigned int V_31 = V_94 -> V_93 [ V_97 - 2 ] << 8 | V_94 -> V_93 [ V_97 - 1 ] ;
V_31 -= V_111 ;
if ( ! V_94 -> V_32 )
V_31 -= V_112 ;
V_94 -> V_93 [ V_97 - 2 ] = V_31 >> 8 ;
V_94 -> V_93 [ V_97 - 1 ] = V_31 & 0xff ;
}
return V_112 ;
case V_113 :
{
T_1 * V_29 = V_98 ;
T_4 * V_114 = V_29 -> V_8 ;
if ( V_35 -> V_37 . V_2 ) {
if ( V_35 -> V_37 . V_2 != & V_35 -> V_36 )
return 0 ;
V_114 -> V_37 . V_2 = & V_114 -> V_36 ;
}
if ( V_35 -> V_3 == V_94 -> V_3 )
V_114 -> V_3 = V_29 -> V_3 ;
else {
V_114 -> V_3 = F_53 ( V_35 -> V_39 ) ;
if ( ! V_114 -> V_3 )
return 0 ;
memcpy ( V_114 -> V_3 , V_35 -> V_3 , V_35 -> V_39 ) ;
}
return 1 ;
}
default:
return - 1 ;
}
}
static int F_55 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
do {
# ifdef F_21
if ( F_21 ) {
F_28 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 . V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_83 ) ;
# ifdef F_29
V_35 -> V_24 = ( V_25 ) F_29 ;
# else
V_35 -> V_24 = NULL ;
# endif
break;
} else
# endif
# ifdef F_24
if ( F_24 ) {
F_30 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 . V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_84 ) ;
V_35 -> V_24 = ( V_25 ) V_85 ;
break;
} else
# endif
# ifdef F_26
if ( F_26 ) {
F_31 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 . V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_86 ) ;
V_35 -> V_24 = NULL ;
break;
} else
# endif
( void ) 0 ;
F_30 ( V_2 , V_1 -> V_14 * 8 , & V_35 -> V_36 . V_36 ) ;
F_9 ( & V_35 -> V_37 , & V_35 -> V_36 ,
( V_16 ) V_84 ) ;
# ifdef F_32
V_35 -> V_24 = ( V_25 ) V_87 ;
# else
V_35 -> V_24 = NULL ;
# endif
} while ( 0 );
if ( V_3 == NULL && V_35 -> V_38 )
V_3 = V_35 -> V_3 ;
if ( V_3 ) {
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
}
V_35 -> V_40 = 1 ;
} else {
if ( V_35 -> V_40 )
F_10 ( & V_35 -> V_37 , V_3 , V_35 -> V_39 ) ;
else
memcpy ( V_35 -> V_3 , V_3 , V_35 -> V_39 ) ;
V_35 -> V_38 = 1 ;
V_35 -> V_41 = 0 ;
}
return 1 ;
}
static int F_56 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_4 * V_35 = V_1 -> V_8 ;
int V_115 = - 1 ;
if ( V_29 != V_30
|| V_31 < ( V_111 + V_112 ) )
return - 1 ;
if ( F_57 ( V_1 , V_1 -> V_32 ?
V_108 : V_109 ,
V_111 , V_29 ) <= 0 )
goto V_116;
if ( F_58 ( & V_35 -> V_37 , V_1 -> V_93 , V_35 -> V_102 ) )
goto V_116;
V_30 += V_111 ;
V_29 += V_111 ;
V_31 -= V_111 + V_112 ;
if ( V_1 -> V_32 ) {
if ( V_35 -> V_24 ) {
T_3 V_117 = 0 ;
# if F_59 ( V_118 )
if ( V_31 >= 32 && V_118 ( V_35 ) ) {
if ( F_60 ( & V_35 -> V_37 , NULL , NULL , 0 ) )
return - 1 ;
V_117 = F_61 ( V_30 , V_29 , V_31 ,
V_35 -> V_37 . V_2 ,
V_35 -> V_37 . V_119 . V_94 , V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
}
# endif
if ( F_62 ( & V_35 -> V_37 ,
V_30 + V_117 ,
V_29 + V_117 ,
V_31 - V_117 , V_35 -> V_24 ) )
goto V_116;
} else {
T_3 V_117 = 0 ;
# if F_59 ( V_122 )
if ( V_31 >= 32 && V_122 ( V_35 ) ) {
if ( F_60 ( & V_35 -> V_37 , NULL , NULL , 0 ) )
return - 1 ;
V_117 = F_61 ( V_30 , V_29 , V_31 ,
V_35 -> V_37 . V_2 ,
V_35 -> V_37 . V_119 . V_94 , V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
}
# endif
if ( F_60 ( & V_35 -> V_37 ,
V_30 + V_117 , V_29 + V_117 , V_31 - V_117 ) )
goto V_116;
}
V_29 += V_31 ;
F_63 ( & V_35 -> V_37 , V_29 , V_112 ) ;
V_115 = V_31 + V_111 + V_112 ;
} else {
if ( V_35 -> V_24 ) {
T_3 V_117 = 0 ;
# if F_59 ( V_118 )
if ( V_31 >= 16 && V_118 ( V_35 ) ) {
if ( F_64 ( & V_35 -> V_37 , NULL , NULL , 0 ) )
return - 1 ;
V_117 = F_65 ( V_30 , V_29 , V_31 ,
V_35 -> V_37 . V_2 ,
V_35 -> V_37 . V_119 . V_94 , V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
}
# endif
if ( F_66 ( & V_35 -> V_37 ,
V_30 + V_117 ,
V_29 + V_117 ,
V_31 - V_117 , V_35 -> V_24 ) )
goto V_116;
} else {
T_3 V_117 = 0 ;
# if F_59 ( V_122 )
if ( V_31 >= 16 && V_122 ( V_35 ) ) {
if ( F_64 ( & V_35 -> V_37 , NULL , NULL , 0 ) )
return - 1 ;
V_117 = F_65 ( V_30 , V_29 , V_31 ,
V_35 -> V_37 . V_2 ,
V_35 -> V_37 . V_119 . V_94 , V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
}
# endif
if ( F_64 ( & V_35 -> V_37 ,
V_30 + V_117 , V_29 + V_117 , V_31 - V_117 ) )
goto V_116;
}
F_63 ( & V_35 -> V_37 , V_1 -> V_93 , V_112 ) ;
if ( memcmp ( V_1 -> V_93 , V_30 + V_31 , V_112 ) ) {
F_49 ( V_29 , V_31 ) ;
goto V_116;
}
V_115 = V_31 ;
}
V_116:
V_35 -> V_38 = 0 ;
V_35 -> V_102 = - 1 ;
return V_115 ;
}
static int F_67 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_4 * V_35 = V_1 -> V_8 ;
if ( ! V_35 -> V_40 )
return - 1 ;
if ( V_35 -> V_102 >= 0 )
return F_56 ( V_1 , V_29 , V_30 , V_31 ) ;
if ( ! V_35 -> V_38 )
return - 1 ;
if ( V_30 ) {
if ( V_29 == NULL ) {
if ( F_58 ( & V_35 -> V_37 , V_30 , V_31 ) )
return - 1 ;
} else if ( V_1 -> V_32 ) {
if ( V_35 -> V_24 ) {
T_3 V_117 = 0 ;
# if F_59 ( V_118 )
if ( V_31 >= 32 && V_118 ( V_35 ) ) {
T_3 V_123 = ( 16 - V_35 -> V_37 . V_124 ) % 16 ;
if ( F_60 ( & V_35 -> V_37 , V_30 , V_29 , V_123 ) )
return - 1 ;
V_117 = F_61 ( V_30 + V_123 ,
V_29 + V_123 , V_31 - V_123 ,
V_35 -> V_37 . V_2 , V_35 -> V_37 . V_119 . V_94 ,
V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
V_117 += V_123 ;
}
# endif
if ( F_62 ( & V_35 -> V_37 ,
V_30 + V_117 ,
V_29 + V_117 ,
V_31 - V_117 , V_35 -> V_24 ) )
return - 1 ;
} else {
T_3 V_117 = 0 ;
# if F_59 ( V_122 )
if ( V_31 >= 32 && V_122 ( V_35 ) ) {
T_3 V_123 = ( 16 - V_35 -> V_37 . V_124 ) % 16 ;
if ( F_60 ( & V_35 -> V_37 , V_30 , V_29 , V_123 ) )
return - 1 ;
V_117 = F_61 ( V_30 + V_123 ,
V_29 + V_123 , V_31 - V_123 ,
V_35 -> V_37 . V_2 , V_35 -> V_37 . V_119 . V_94 ,
V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
V_117 += V_123 ;
}
# endif
if ( F_60 ( & V_35 -> V_37 ,
V_30 + V_117 , V_29 + V_117 , V_31 - V_117 ) )
return - 1 ;
}
} else {
if ( V_35 -> V_24 ) {
T_3 V_117 = 0 ;
# if F_59 ( V_118 )
if ( V_31 >= 16 && V_118 ( V_35 ) ) {
T_3 V_123 = ( 16 - V_35 -> V_37 . V_124 ) % 16 ;
if ( F_64 ( & V_35 -> V_37 , V_30 , V_29 , V_123 ) )
return - 1 ;
V_117 = F_65 ( V_30 + V_123 ,
V_29 + V_123 , V_31 - V_123 ,
V_35 -> V_37 . V_2 ,
V_35 -> V_37 . V_119 . V_94 , V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
V_117 += V_123 ;
}
# endif
if ( F_66 ( & V_35 -> V_37 ,
V_30 + V_117 ,
V_29 + V_117 ,
V_31 - V_117 , V_35 -> V_24 ) )
return - 1 ;
} else {
T_3 V_117 = 0 ;
# if F_59 ( V_122 )
if ( V_31 >= 16 && V_122 ( V_35 ) ) {
T_3 V_123 = ( 16 - V_35 -> V_37 . V_124 ) % 16 ;
if ( F_64 ( & V_35 -> V_37 , V_30 , V_29 , V_123 ) )
return - 1 ;
V_117 = F_65 ( V_30 + V_123 ,
V_29 + V_123 , V_31 - V_123 ,
V_35 -> V_37 . V_2 ,
V_35 -> V_37 . V_119 . V_94 , V_35 -> V_37 . V_120 . V_121 ) ;
V_35 -> V_37 . V_31 . V_121 [ 1 ] += V_117 ;
V_117 += V_123 ;
}
# endif
if ( F_64 ( & V_35 -> V_37 ,
V_30 + V_117 , V_29 + V_117 , V_31 - V_117 ) )
return - 1 ;
}
}
return V_31 ;
} else {
if ( ! V_1 -> V_32 ) {
if ( V_35 -> V_101 < 0 )
return - 1 ;
if ( F_68 ( & V_35 -> V_37 , V_1 -> V_93 , V_35 -> V_101 ) != 0 )
return - 1 ;
V_35 -> V_38 = 0 ;
return 0 ;
}
F_63 ( & V_35 -> V_37 , V_1 -> V_93 , 16 ) ;
V_35 -> V_101 = 16 ;
V_35 -> V_38 = 0 ;
return 0 ;
}
}
static int F_69 ( T_1 * V_94 , int type , int V_97 , void * V_98 )
{
T_5 * V_42 = V_94 -> V_8 ;
if ( type == V_113 ) {
T_1 * V_29 = V_98 ;
T_5 * V_125 = V_29 -> V_8 ;
if ( V_42 -> V_44 . V_50 ) {
if ( V_42 -> V_44 . V_50 != & V_42 -> V_43 )
return 0 ;
V_125 -> V_44 . V_50 = & V_125 -> V_43 ;
}
if ( V_42 -> V_44 . V_51 ) {
if ( V_42 -> V_44 . V_51 != & V_42 -> V_48 )
return 0 ;
V_125 -> V_44 . V_51 = & V_125 -> V_48 ;
}
return 1 ;
} else if ( type != V_99 )
return - 1 ;
V_42 -> V_44 . V_50 = NULL ;
V_42 -> V_44 . V_51 = NULL ;
return 1 ;
}
static int F_70 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_5 * V_42 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
do {
# ifdef F_71
V_42 -> V_18 = V_4 ? V_126 : V_127 ;
# else
V_42 -> V_18 = NULL ;
# endif
# ifdef F_21
if ( F_21 ) {
if ( V_4 ) {
F_28 ( V_2 , V_1 -> V_14 * 4 ,
& V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_83 ;
} else {
F_22 ( V_2 , V_1 -> V_14 * 4 ,
& V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_77 ;
}
F_28 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 . V_36 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_83 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
break;
} else
# endif
# ifdef F_24
if ( F_24 )
V_42 -> V_18 = V_4 ? V_128 : V_129 ;
else
# endif
# ifdef F_26
if ( F_26 ) {
if ( V_4 ) {
F_31 ( V_2 , V_1 -> V_14 * 4 ,
& V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_86 ;
} else {
F_27 ( V_2 , V_1 -> V_14 * 4 ,
& V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_80 ;
}
F_31 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 . V_36 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_86 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
break;
} else
# endif
( void ) 0 ;
if ( V_4 ) {
F_30 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_84 ;
} else {
F_25 ( V_2 , V_1 -> V_14 * 4 , & V_42 -> V_43 . V_36 ) ;
V_42 -> V_44 . V_45 = ( V_16 ) V_78 ;
}
F_30 ( V_2 + V_1 -> V_14 / 2 ,
V_1 -> V_14 * 4 , & V_42 -> V_48 . V_36 ) ;
V_42 -> V_44 . V_49 = ( V_16 ) V_84 ;
V_42 -> V_44 . V_50 = & V_42 -> V_43 ;
} while ( 0 );
if ( V_3 ) {
V_42 -> V_44 . V_51 = & V_42 -> V_48 ;
memcpy ( V_1 -> V_3 , V_3 , 16 ) ;
}
return 1 ;
}
static int F_72 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_5 * V_42 = V_1 -> V_8 ;
if ( ! V_42 -> V_44 . V_50 || ! V_42 -> V_44 . V_51 )
return 0 ;
if ( ! V_29 || ! V_30 || V_31 < V_130 )
return 0 ;
if ( V_42 -> V_18 )
(* V_42 -> V_18 ) ( V_30 , V_29 , V_31 ,
V_42 -> V_44 . V_50 , V_42 -> V_44 . V_51 , V_1 -> V_3 ) ;
else if ( F_73 ( & V_42 -> V_44 , V_1 -> V_3 , V_30 , V_29 , V_31 ,
V_1 -> V_32 ) )
return 0 ;
return 1 ;
}
static int F_74 ( T_1 * V_94 , int type , int V_97 , void * V_98 )
{
T_6 * V_52 = V_94 -> V_8 ;
switch ( type ) {
case V_99 :
V_52 -> V_40 = 0 ;
V_52 -> V_38 = 0 ;
V_52 -> V_55 = 8 ;
V_52 -> V_54 = 12 ;
V_52 -> V_131 = 0 ;
V_52 -> V_132 = 0 ;
return 1 ;
case V_133 :
V_97 = 15 - V_97 ;
case V_134 :
if ( V_97 < 2 || V_97 > 8 )
return 0 ;
V_52 -> V_55 = V_97 ;
return 1 ;
case V_135 :
if ( ( V_97 & 1 ) || V_97 < 4 || V_97 > 16 )
return 0 ;
if ( ( V_94 -> V_32 && V_98 ) || ( ! V_94 -> V_32 && ! V_98 ) )
return 0 ;
if ( V_98 ) {
V_52 -> V_131 = 1 ;
memcpy ( V_94 -> V_93 , V_98 , V_97 ) ;
}
V_52 -> V_54 = V_97 ;
return 1 ;
case V_136 :
if ( ! V_94 -> V_32 || ! V_52 -> V_131 )
return 0 ;
if ( ! F_75 ( & V_52 -> V_53 , V_98 , ( T_3 ) V_97 ) )
return 0 ;
V_52 -> V_131 = 0 ;
V_52 -> V_38 = 0 ;
V_52 -> V_132 = 0 ;
return 1 ;
case V_113 :
{
T_1 * V_29 = V_98 ;
T_6 * V_137 = V_29 -> V_8 ;
if ( V_52 -> V_53 . V_2 ) {
if ( V_52 -> V_53 . V_2 != & V_52 -> V_36 )
return 0 ;
V_137 -> V_53 . V_2 = & V_137 -> V_36 ;
}
return 1 ;
}
default:
return - 1 ;
}
}
static int F_76 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_6 * V_52 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 )
do {
# ifdef F_21
if ( F_21 ) {
F_28 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 . V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_83 ) ;
V_52 -> V_56 = NULL ;
V_52 -> V_40 = 1 ;
break;
} else
# endif
# ifdef F_26
if ( F_26 ) {
F_31 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 . V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_86 ) ;
V_52 -> V_56 = NULL ;
V_52 -> V_40 = 1 ;
break;
}
# endif
F_30 ( V_2 , V_1 -> V_14 * 8 , & V_52 -> V_36 . V_36 ) ;
F_13 ( & V_52 -> V_53 , V_52 -> V_54 , V_52 -> V_55 ,
& V_52 -> V_36 , ( V_16 ) V_84 ) ;
V_52 -> V_56 = NULL ;
V_52 -> V_40 = 1 ;
} while ( 0 );
if ( V_3 ) {
memcpy ( V_1 -> V_3 , V_3 , 15 - V_52 -> V_55 ) ;
V_52 -> V_38 = 1 ;
}
return 1 ;
}
static int F_77 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_31 )
{
T_6 * V_52 = V_1 -> V_8 ;
T_7 * V_53 = & V_52 -> V_53 ;
if ( ! V_52 -> V_38 && ! V_52 -> V_40 )
return - 1 ;
if ( ! V_1 -> V_32 && ! V_52 -> V_131 )
return - 1 ;
if ( ! V_29 ) {
if ( ! V_30 ) {
if ( F_78 ( V_53 , V_1 -> V_3 , 15 - V_52 -> V_55 , V_31 ) )
return - 1 ;
V_52 -> V_132 = 1 ;
return V_31 ;
}
if ( ! V_52 -> V_132 && V_31 )
return - 1 ;
F_79 ( V_53 , V_30 , V_31 ) ;
return V_31 ;
}
if ( ! V_30 )
return 0 ;
if ( ! V_52 -> V_132 ) {
if ( F_78 ( V_53 , V_1 -> V_3 , 15 - V_52 -> V_55 , V_31 ) )
return - 1 ;
V_52 -> V_132 = 1 ;
}
if ( V_1 -> V_32 ) {
if ( V_52 -> V_56 ? F_80 ( V_53 , V_30 , V_29 , V_31 ,
V_52 -> V_56 ) :
F_81 ( V_53 , V_30 , V_29 , V_31 ) )
return - 1 ;
V_52 -> V_131 = 1 ;
return V_31 ;
} else {
int V_115 = - 1 ;
if ( V_52 -> V_56 ? ! F_82 ( V_53 , V_30 , V_29 , V_31 ,
V_52 -> V_56 ) :
! F_83 ( V_53 , V_30 , V_29 , V_31 ) ) {
unsigned char V_138 [ 16 ] ;
if ( F_75 ( V_53 , V_138 , V_52 -> V_54 ) ) {
if ( ! memcmp ( V_138 , V_1 -> V_93 , V_52 -> V_54 ) )
V_115 = V_31 ;
}
}
if ( V_115 == - 1 )
F_49 ( V_29 , V_31 ) ;
V_52 -> V_38 = 0 ;
V_52 -> V_131 = 0 ;
V_52 -> V_132 = 0 ;
return V_115 ;
}
}
static int F_84 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_8 * V_139 = V_1 -> V_8 ;
if ( ! V_3 && ! V_2 )
return 1 ;
if ( V_2 ) {
if ( V_1 -> V_32 )
F_30 ( V_2 , V_1 -> V_14 * 8 , & V_139 -> V_36 . V_36 ) ;
else
F_25 ( V_2 , V_1 -> V_14 * 8 , & V_139 -> V_36 . V_36 ) ;
if ( ! V_3 )
V_139 -> V_3 = NULL ;
}
if ( V_3 ) {
memcpy ( V_1 -> V_3 , V_3 , 8 ) ;
V_139 -> V_3 = V_1 -> V_3 ;
}
return 1 ;
}
static int F_85 ( T_1 * V_1 , unsigned char * V_29 ,
const unsigned char * V_30 , T_3 V_140 )
{
T_8 * V_139 = V_1 -> V_8 ;
T_3 V_115 ;
if ( ! V_30 )
return 0 ;
if ( V_140 % 8 )
return - 1 ;
if ( V_1 -> V_32 && V_140 < 8 )
return - 1 ;
if ( ! V_1 -> V_32 && V_140 < 16 )
return - 1 ;
if ( ! V_29 ) {
if ( V_1 -> V_32 )
return V_140 + 8 ;
else
return V_140 - 8 ;
}
if ( V_1 -> V_32 )
V_115 = F_86 ( & V_139 -> V_36 . V_36 , V_139 -> V_3 , V_29 , V_30 , V_140 ,
( V_16 ) V_84 ) ;
else
V_115 = F_87 ( & V_139 -> V_36 . V_36 , V_139 -> V_3 , V_29 , V_30 , V_140 ,
( V_16 ) V_78 ) ;
return V_115 ? ( int ) V_115 : - 1 ;
}
const T_9 * F_88 ( void )
{
return & V_141 ;
}
const T_9 * F_89 ( void )
{
return & V_142 ;
}
const T_9 * F_90 ( void )
{
return & V_143 ;
}
