static void * F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
goto V_5;
V_3 -> V_1 = V_1 ;
V_3 -> V_6 = F_3 ( L_1 , 0 ,
V_7 ) ;
if ( F_4 ( V_3 -> V_6 ) ) {
F_5 ( L_2 ) ;
V_3 -> V_6 = NULL ;
goto V_5;
}
V_3 -> V_8 = F_6 ( L_3 , 0 ,
V_7 ) ;
if ( F_4 ( V_3 -> V_8 ) ) {
F_5 ( L_4 ) ;
V_3 -> V_8 = NULL ;
goto V_5;
}
V_3 -> V_9 = F_3 ( L_1 , 0 ,
V_7 ) ;
if ( F_4 ( V_3 -> V_9 ) ) {
F_5 ( L_2 ) ;
V_3 -> V_9 = NULL ;
goto V_5;
}
V_3 -> V_10 = F_6 ( L_3 , 0 ,
V_7 ) ;
if ( F_4 ( V_3 -> V_10 ) ) {
F_5 ( L_4 ) ;
V_3 -> V_10 = NULL ;
goto V_5;
}
return V_3 ;
V_5:
if ( V_3 ) {
if ( V_3 -> V_8 )
F_7 ( V_3 -> V_8 ) ;
if ( V_3 -> V_6 )
F_8 ( V_3 -> V_6 ) ;
if ( V_3 -> V_10 )
F_7 ( V_3 -> V_10 ) ;
if ( V_3 -> V_9 )
F_8 ( V_3 -> V_9 ) ;
F_9 ( V_3 ) ;
}
return NULL ;
}
static void F_10 ( void * V_3 )
{
struct V_2 * V_11 = V_3 ;
if ( V_11 ) {
if ( V_11 -> V_8 )
F_7 ( V_11 -> V_8 ) ;
if ( V_11 -> V_6 )
F_8 ( V_11 -> V_6 ) ;
if ( V_11 -> V_10 )
F_7 ( V_11 -> V_10 ) ;
if ( V_11 -> V_9 )
F_8 ( V_11 -> V_9 ) ;
}
F_9 ( V_3 ) ;
}
static inline T_1 F_11 ( T_1 V_12 )
{
return ( V_12 >> 1 ) | ( V_12 << 15 ) ;
}
static inline T_2 F_12 ( T_1 V_12 )
{
return V_12 & 0xff ;
}
static inline T_2 F_13 ( T_1 V_12 )
{
return V_12 >> 8 ;
}
static inline T_1 F_14 ( T_3 V_12 )
{
return V_12 & 0xffff ;
}
static inline T_1 F_15 ( T_3 V_12 )
{
return V_12 >> 16 ;
}
static inline T_1 F_16 ( T_2 V_13 , T_2 V_14 )
{
return V_14 | ( ( ( T_1 ) V_13 ) << 8 ) ;
}
static inline T_1 F_17 ( T_1 * V_15 )
{
return * V_15 ;
}
static inline T_1 F_18 ( T_1 V_15 )
{
T_1 V_16 = V_17 [ F_13 ( V_15 ) ] ;
return V_17 [ F_12 ( V_15 ) ] ^ ( ( V_16 << 8 ) | ( V_16 >> 8 ) ) ;
}
static void F_19 ( T_1 * V_18 , const T_2 * V_19 , const T_2 * V_20 , T_3 V_21 )
{
int V_22 , V_23 ;
V_18 [ 0 ] = F_14 ( V_21 ) ;
V_18 [ 1 ] = F_15 ( V_21 ) ;
V_18 [ 2 ] = F_16 ( V_20 [ 1 ] , V_20 [ 0 ] ) ;
V_18 [ 3 ] = F_16 ( V_20 [ 3 ] , V_20 [ 2 ] ) ;
V_18 [ 4 ] = F_16 ( V_20 [ 5 ] , V_20 [ 4 ] ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
V_23 = 2 * ( V_22 & 1 ) ;
V_18 [ 0 ] += F_18 ( V_18 [ 4 ] ^ F_16 ( V_19 [ 1 + V_23 ] , V_19 [ 0 + V_23 ] ) ) ;
V_18 [ 1 ] += F_18 ( V_18 [ 0 ] ^ F_16 ( V_19 [ 5 + V_23 ] , V_19 [ 4 + V_23 ] ) ) ;
V_18 [ 2 ] += F_18 ( V_18 [ 1 ] ^ F_16 ( V_19 [ 9 + V_23 ] , V_19 [ 8 + V_23 ] ) ) ;
V_18 [ 3 ] += F_18 ( V_18 [ 2 ] ^ F_16 ( V_19 [ 13 + V_23 ] , V_19 [ 12 + V_23 ] ) ) ;
V_18 [ 4 ] += F_18 ( V_18 [ 3 ] ^ F_16 ( V_19 [ 1 + V_23 ] , V_19 [ 0 + V_23 ] ) ) + V_22 ;
}
}
static void F_20 ( T_2 * V_25 , const T_2 * V_19 , const T_1 * V_18 ,
T_1 V_26 )
{
T_1 * V_27 = ( T_1 * ) & V_25 [ 4 ] ;
V_27 [ 0 ] = V_18 [ 0 ] ;
V_27 [ 1 ] = V_18 [ 1 ] ;
V_27 [ 2 ] = V_18 [ 2 ] ;
V_27 [ 3 ] = V_18 [ 3 ] ;
V_27 [ 4 ] = V_18 [ 4 ] ;
V_27 [ 5 ] = V_18 [ 4 ] + V_26 ;
V_27 [ 0 ] += F_18 ( V_27 [ 5 ] ^ F_17 ( ( T_1 * ) & V_19 [ 0 ] ) ) ;
V_27 [ 1 ] += F_18 ( V_27 [ 0 ] ^ F_17 ( ( T_1 * ) & V_19 [ 2 ] ) ) ;
V_27 [ 2 ] += F_18 ( V_27 [ 1 ] ^ F_17 ( ( T_1 * ) & V_19 [ 4 ] ) ) ;
V_27 [ 3 ] += F_18 ( V_27 [ 2 ] ^ F_17 ( ( T_1 * ) & V_19 [ 6 ] ) ) ;
V_27 [ 4 ] += F_18 ( V_27 [ 3 ] ^ F_17 ( ( T_1 * ) & V_19 [ 8 ] ) ) ;
V_27 [ 5 ] += F_18 ( V_27 [ 4 ] ^ F_17 ( ( T_1 * ) & V_19 [ 10 ] ) ) ;
V_27 [ 0 ] += F_11 ( V_27 [ 5 ] ^ F_17 ( ( T_1 * ) & V_19 [ 12 ] ) ) ;
V_27 [ 1 ] += F_11 ( V_27 [ 0 ] ^ F_17 ( ( T_1 * ) & V_19 [ 14 ] ) ) ;
V_27 [ 2 ] += F_11 ( V_27 [ 1 ] ) ;
V_27 [ 3 ] += F_11 ( V_27 [ 2 ] ) ;
V_27 [ 4 ] += F_11 ( V_27 [ 3 ] ) ;
V_27 [ 5 ] += F_11 ( V_27 [ 4 ] ) ;
V_25 [ 0 ] = F_13 ( V_26 ) ;
V_25 [ 1 ] = ( F_13 ( V_26 ) | 0x20 ) & 0x7F ;
V_25 [ 2 ] = F_12 ( V_26 ) ;
V_25 [ 3 ] = F_12 ( ( V_27 [ 5 ] ^ F_17 ( ( T_1 * ) & V_19 [ 0 ] ) ) >> 1 ) ;
#ifdef F_21
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 6 ; V_22 ++ )
V_27 [ V_22 ] = ( V_27 [ V_22 ] << 8 ) | ( V_27 [ V_22 ] >> 8 ) ;
}
#endif
}
static int F_22 ( struct V_28 * V_29 , int V_30 , void * V_3 )
{
struct V_2 * V_31 = V_3 ;
int V_32 ;
T_2 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_29 -> V_38 +
V_39 ) ;
struct V_40 V_41 = { . V_42 = V_31 -> V_6 } ;
int V_43 = 0 ;
T_2 V_44 [ 16 ] , * V_45 ;
T_3 V_46 ;
struct V_47 V_48 ;
if ( F_23 ( V_29 ) < 8 || F_24 ( V_29 ) < 4 ||
V_29 -> V_32 < V_30 )
return - 1 ;
V_35 = (struct V_34 * ) V_29 -> V_49 ;
if ( ! V_37 -> V_50 ) {
if ( ! V_31 -> V_51 ) {
F_19 ( V_31 -> V_52 , V_31 -> V_53 , V_35 -> V_54 ,
V_31 -> V_55 ) ;
V_31 -> V_51 = 1 ;
}
F_20 ( V_44 , V_31 -> V_53 , V_31 -> V_52 ,
V_31 -> V_56 ) ;
} else
V_31 -> V_51 = 1 ;
V_32 = V_29 -> V_32 - V_30 ;
V_33 = F_25 ( V_29 , 8 ) ;
memmove ( V_33 , V_33 + 8 , V_30 ) ;
V_33 += V_30 ;
if ( V_37 -> V_50 ) {
* V_33 ++ = F_13 ( V_31 -> V_56 ) ;
* V_33 ++ = ( F_13 ( V_31 -> V_56 ) | 0x20 ) & 0x7F ;
* V_33 ++ = F_12 ( V_31 -> V_56 ) ;
} else {
* V_33 ++ = V_44 [ 0 ] ;
* V_33 ++ = V_44 [ 1 ] ;
* V_33 ++ = V_44 [ 2 ] ;
}
* V_33 ++ = ( V_31 -> V_1 << 6 ) | ( 1 << 5 ) ;
* V_33 ++ = V_31 -> V_55 & 0xff ;
* V_33 ++ = ( V_31 -> V_55 >> 8 ) & 0xff ;
* V_33 ++ = ( V_31 -> V_55 >> 16 ) & 0xff ;
* V_33 ++ = ( V_31 -> V_55 >> 24 ) & 0xff ;
if ( ! V_37 -> V_50 ) {
V_45 = F_26 ( V_29 , 4 ) ;
V_46 = ~ F_27 ( ~ 0 , V_33 , V_32 ) ;
V_45 [ 0 ] = V_46 ;
V_45 [ 1 ] = V_46 >> 8 ;
V_45 [ 2 ] = V_46 >> 16 ;
V_45 [ 3 ] = V_46 >> 24 ;
F_28 ( & V_48 , V_33 , V_32 + 4 ) ;
F_29 ( V_31 -> V_6 , V_44 , 16 ) ;
V_43 = F_30 ( & V_41 , & V_48 , & V_48 , V_32 + 4 ) ;
}
V_31 -> V_56 ++ ;
if ( V_31 -> V_56 == 0 ) {
V_31 -> V_51 = 0 ;
V_31 -> V_55 ++ ;
}
if ( ! V_37 -> V_50 )
return V_43 ;
else
return 0 ;
}
static int F_31 ( struct V_28 * V_29 , int V_30 , void * V_3 )
{
struct V_2 * V_31 = V_3 ;
T_2 V_57 , * V_33 ;
T_3 V_58 ;
T_1 V_59 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_29 -> V_38 +
V_39 ) ;
struct V_40 V_41 = { . V_42 = V_31 -> V_9 } ;
T_2 V_44 [ 16 ] ;
T_2 V_45 [ 4 ] ;
T_3 V_46 ;
struct V_47 V_48 ;
int V_60 ;
if ( V_29 -> V_32 < V_30 + 8 + 4 )
return - 1 ;
V_35 = (struct V_34 * ) V_29 -> V_49 ;
V_33 = V_29 -> V_49 + V_30 ;
V_57 = V_33 [ 3 ] ;
if ( ! ( V_57 & ( 1 << 5 ) ) ) {
if ( F_32 () ) {
F_33 ( V_29 -> V_61 ,
L_5 ,
V_35 -> V_54 ) ;
}
return - 2 ;
}
V_57 >>= 6 ;
if ( V_31 -> V_1 != V_57 ) {
F_33 ( V_29 -> V_61 ,
L_6 ,
V_31 -> V_1 , V_57 , V_3 ) ;
return - 6 ;
}
if ( ! V_31 -> V_62 ) {
if ( F_32 () ) {
F_33 ( V_29 -> V_61 ,
L_7 ,
V_35 -> V_54 , V_57 ) ;
}
return - 3 ;
}
V_59 = ( V_33 [ 0 ] << 8 ) | V_33 [ 2 ] ;
V_58 = V_33 [ 4 ] | ( V_33 [ 5 ] << 8 ) | ( V_33 [ 6 ] << 16 ) | ( V_33 [ 7 ] << 24 ) ;
V_33 += 8 ;
if ( ! V_37 -> V_50 || ( V_29 -> V_38 [ 0 ] == 1 ) ) {
if ( ( V_58 < V_31 -> V_63 ||
( V_58 == V_31 -> V_63 && V_59 <= V_31 -> V_64 ) ) &&
V_31 -> V_65 ) {
if ( F_32 () ) {
F_33 ( V_29 -> V_61 ,
L_8 ,
V_35 -> V_54 , V_31 -> V_63 ,
V_31 -> V_64 , V_58 , V_59 ) ;
}
V_31 -> V_66 ++ ;
return - 4 ;
}
V_31 -> V_65 = true ;
if ( V_58 != V_31 -> V_63 || ! V_31 -> V_67 ) {
F_19 ( V_31 -> V_68 , V_31 -> V_53 ,
V_35 -> V_54 , V_58 ) ;
V_31 -> V_67 = 1 ;
}
F_20 ( V_44 , V_31 -> V_53 , V_31 -> V_68 , V_59 ) ;
V_60 = V_29 -> V_32 - V_30 - 12 ;
F_28 ( & V_48 , V_33 , V_60 + 4 ) ;
F_29 ( V_31 -> V_9 , V_44 , 16 ) ;
if ( F_34 ( & V_41 , & V_48 , & V_48 , V_60 + 4 ) ) {
if ( F_32 () ) {
F_33 ( V_29 -> V_61 ,
L_9 ,
V_35 -> V_54 ) ;
}
return - 7 ;
}
V_46 = ~ F_27 ( ~ 0 , V_33 , V_60 ) ;
V_45 [ 0 ] = V_46 ;
V_45 [ 1 ] = V_46 >> 8 ;
V_45 [ 2 ] = V_46 >> 16 ;
V_45 [ 3 ] = V_46 >> 24 ;
if ( memcmp ( V_45 , V_33 + V_60 , 4 ) != 0 ) {
if ( V_58 != V_31 -> V_63 ) {
V_31 -> V_67 = 0 ;
}
if ( F_32 () ) {
F_33 ( V_29 -> V_61 ,
L_10 ,
V_35 -> V_54 ) ;
}
V_31 -> V_69 ++ ;
return - 5 ;
}
}
V_31 -> V_70 = V_58 ;
V_31 -> V_71 = V_59 ;
memmove ( V_29 -> V_49 + 8 , V_29 -> V_49 , V_30 ) ;
F_35 ( V_29 , 8 ) ;
F_36 ( V_29 , V_29 -> V_32 - 4 ) ;
return V_57 ;
}
static int F_37 ( struct V_72 * V_73 , T_2 * V_53 , T_2 * V_35 ,
T_2 * V_49 , T_4 V_74 , T_2 * V_75 )
{
struct V_76 V_41 ;
struct V_47 V_48 [ 2 ] ;
if ( V_73 == NULL ) {
F_38 ( L_11 ) ;
return - 1 ;
}
F_39 ( V_48 , 2 ) ;
F_40 ( & V_48 [ 0 ] , V_35 , 16 ) ;
F_40 ( & V_48 [ 1 ] , V_49 , V_74 ) ;
if ( F_41 ( V_73 , V_53 , 8 ) )
return - 1 ;
V_41 . V_42 = V_73 ;
V_41 . V_77 = 0 ;
return F_42 ( & V_41 , V_48 , V_74 + 16 , V_75 ) ;
}
static void F_43 ( struct V_28 * V_29 , T_2 * V_35 )
{
struct V_34 * V_78 ;
V_78 = (struct V_34 * ) V_29 -> V_49 ;
switch ( F_44 ( V_78 -> V_79 ) &
( V_80 | V_81 ) ) {
case V_81 :
F_45 ( V_35 , V_78 -> V_82 ) ;
F_45 ( V_35 + V_83 , V_78 -> V_54 ) ;
break;
case V_80 :
F_45 ( V_35 , V_78 -> V_84 ) ;
F_45 ( V_35 + V_83 , V_78 -> V_82 ) ;
break;
case V_80 | V_81 :
F_45 ( V_35 , V_78 -> V_82 ) ;
F_45 ( V_35 + V_83 , V_78 -> V_85 ) ;
break;
case 0 :
F_45 ( V_35 , V_78 -> V_84 ) ;
F_45 ( V_35 + V_83 , V_78 -> V_54 ) ;
break;
}
V_35 [ 12 ] = 0 ;
V_35 [ 13 ] = V_35 [ 14 ] = V_35 [ 15 ] = 0 ;
}
static int F_46 ( struct V_28 * V_29 , int V_30 , void * V_3 )
{
struct V_2 * V_31 = V_3 ;
T_2 * V_33 ;
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_29 -> V_49 ;
if ( F_24 ( V_29 ) < 8 || V_29 -> V_32 < V_30 ) {
F_33 ( V_29 -> V_61 ,
L_12 ,
F_24 ( V_29 ) , V_30 , V_29 -> V_32 ) ;
return - 1 ;
}
F_43 ( V_29 , V_31 -> V_86 ) ;
if ( F_47 ( F_44 ( V_35 -> V_79 ) ) )
V_31 -> V_86 [ 12 ] = * ( V_29 -> V_49 + V_30 - 2 ) & 0x07 ;
V_33 = F_26 ( V_29 , 8 ) ;
if ( F_37 ( V_31 -> V_8 , & V_31 -> V_53 [ 16 ] , V_31 -> V_86 ,
V_29 -> V_49 + V_30 , V_29 -> V_32 - 8 - V_30 , V_33 ) )
return - 1 ;
return 0 ;
}
static void F_48 ( struct V_87 * V_61 ,
struct V_34 * V_35 ,
int V_57 )
{
union V_88 V_89 ;
struct V_90 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_77 = V_57 & V_92 ;
if ( V_35 -> V_84 [ 0 ] & 0x01 )
V_91 . V_77 |= V_93 ;
else
V_91 . V_77 |= V_94 ;
V_91 . V_95 . V_96 = V_97 ;
F_45 ( V_91 . V_95 . V_98 , V_35 -> V_54 ) ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_49 . V_99 = sizeof( V_91 ) ;
F_49 ( V_61 , V_100 , & V_89 , ( char * ) & V_91 ) ;
}
static int F_50 ( struct V_28 * V_29 , int V_57 ,
int V_30 , void * V_3 )
{
struct V_2 * V_31 = V_3 ;
T_2 V_75 [ 8 ] ;
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_29 -> V_49 ;
if ( ! V_31 -> V_62 )
return - 1 ;
F_43 ( V_29 , V_31 -> V_101 ) ;
if ( F_47 ( F_44 ( V_35 -> V_79 ) ) )
V_31 -> V_101 [ 12 ] = * ( V_29 -> V_49 + V_30 - 2 ) & 0x07 ;
if ( F_37 ( V_31 -> V_10 , & V_31 -> V_53 [ 24 ] , V_31 -> V_101 ,
V_29 -> V_49 + V_30 , V_29 -> V_32 - 8 - V_30 , V_75 ) )
return - 1 ;
if ( memcmp ( V_75 , V_29 -> V_49 + V_29 -> V_32 - 8 , 8 ) != 0 ) {
struct V_34 * V_35 ;
V_35 = (struct V_34 * ) V_29 -> V_49 ;
F_33 ( V_29 -> V_61 ,
L_13 ,
V_35 -> V_54 , V_57 ) ;
F_33 ( V_29 -> V_61 , L_14 ,
memcmp ( V_75 , V_29 -> V_49 + V_29 -> V_32 - 8 , 8 ) != 0 ) ;
if ( V_29 -> V_61 ) {
F_51 ( L_15 ) ;
F_48 ( V_29 -> V_61 , V_35 , V_57 ) ;
}
V_31 -> V_102 ++ ;
return - 1 ;
}
V_31 -> V_63 = V_31 -> V_70 ;
V_31 -> V_64 = V_31 -> V_71 ;
F_36 ( V_29 , V_29 -> V_32 - 8 ) ;
return 0 ;
}
static int F_52 ( void * V_53 , int V_32 , T_2 * V_103 , void * V_3 )
{
struct V_2 * V_31 = V_3 ;
int V_57 ;
struct V_72 * V_42 = V_31 -> V_8 ;
struct V_104 * V_105 = V_31 -> V_6 ;
struct V_72 * V_106 = V_31 -> V_10 ;
struct V_104 * V_107 = V_31 -> V_9 ;
V_57 = V_31 -> V_1 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_1 = V_57 ;
V_31 -> V_8 = V_42 ;
V_31 -> V_6 = V_105 ;
V_31 -> V_10 = V_106 ;
V_31 -> V_9 = V_107 ;
if ( V_32 == V_108 ) {
memcpy ( V_31 -> V_53 , V_53 , V_108 ) ;
V_31 -> V_62 = 1 ;
V_31 -> V_56 = 1 ;
if ( V_103 ) {
V_31 -> V_63 = ( V_103 [ 5 ] << 24 ) | ( V_103 [ 4 ] << 16 ) |
( V_103 [ 3 ] << 8 ) | V_103 [ 2 ] ;
V_31 -> V_64 = ( V_103 [ 1 ] << 8 ) | V_103 [ 0 ] ;
}
} else if ( V_32 == 0 )
V_31 -> V_62 = 0 ;
else
return - 1 ;
return 0 ;
}
static int F_53 ( void * V_53 , int V_32 , T_2 * V_103 , void * V_3 )
{
struct V_2 * V_31 = V_3 ;
if ( V_32 < V_108 )
return - 1 ;
if ( ! V_31 -> V_62 )
return 0 ;
memcpy ( V_53 , V_31 -> V_53 , V_108 ) ;
if ( V_103 ) {
T_1 V_59 = V_31 -> V_56 ;
T_3 V_58 = V_31 -> V_55 ;
if ( V_59 == 0 )
V_58 -- ;
V_59 -- ;
V_103 [ 0 ] = V_31 -> V_56 ;
V_103 [ 1 ] = V_31 -> V_56 >> 8 ;
V_103 [ 2 ] = V_31 -> V_55 ;
V_103 [ 3 ] = V_31 -> V_55 >> 8 ;
V_103 [ 4 ] = V_31 -> V_55 >> 16 ;
V_103 [ 5 ] = V_31 -> V_55 >> 24 ;
}
return V_108 ;
}
static void F_54 ( struct V_109 * V_110 , void * V_3 )
{
struct V_2 * V_111 = V_3 ;
F_55 ( V_110 ,
L_16 ,
V_111 -> V_1 , V_111 -> V_62 ,
( V_111 -> V_55 >> 24 ) & 0xff ,
( V_111 -> V_55 >> 16 ) & 0xff ,
( V_111 -> V_55 >> 8 ) & 0xff ,
V_111 -> V_55 & 0xff ,
( V_111 -> V_56 >> 8 ) & 0xff ,
V_111 -> V_56 & 0xff ,
( V_111 -> V_63 >> 24 ) & 0xff ,
( V_111 -> V_63 >> 16 ) & 0xff ,
( V_111 -> V_63 >> 8 ) & 0xff ,
V_111 -> V_63 & 0xff ,
( V_111 -> V_64 >> 8 ) & 0xff ,
V_111 -> V_64 & 0xff ,
V_111 -> V_66 ,
V_111 -> V_69 ,
V_111 -> V_102 ) ;
}
static int T_5 F_56 ( void )
{
return F_57 ( & V_112 ) ;
}
static void T_6 F_58 ( void )
{
F_59 ( & V_112 ) ;
}
