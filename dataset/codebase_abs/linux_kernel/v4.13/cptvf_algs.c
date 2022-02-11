static void F_1 ( T_1 V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
V_4 -> V_5 ( V_4 , ! V_1 ) ;
}
static inline void F_2 ( struct V_6 * V_7 ,
T_2 * V_8 , T_1 V_9 ,
T_1 * V_10 )
{
V_7 -> V_11 [ * V_10 ] . V_12 = ( void * ) V_8 ;
V_7 -> V_11 [ * V_10 ] . V_13 = V_9 ;
V_7 -> V_4 . V_14 += V_9 ;
++ ( * V_10 ) ;
}
static inline void F_3 ( struct V_6 * V_7 ,
T_2 * V_8 , T_1 V_9 ,
T_1 * V_10 )
{
V_7 -> V_15 [ * V_10 ] . V_12 = ( void * ) V_8 ;
V_7 -> V_15 [ * V_10 ] . V_13 = V_9 ;
V_7 -> V_16 += V_9 ;
++ ( * V_10 ) ;
}
static inline void F_4 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_1 V_19 , T_1 * V_10 )
{
V_7 -> V_4 . V_14 += V_19 ;
while ( V_19 ) {
T_1 V_20 = F_5 ( V_19 , V_18 -> V_21 ) ;
T_2 * V_22 = F_6 ( V_18 ) ;
V_7 -> V_11 [ * V_10 ] . V_12 = ( void * ) V_22 ;
V_7 -> V_11 [ * V_10 ] . V_13 = V_20 ;
V_19 -= V_20 ;
++ ( * V_10 ) ;
++ V_18 ;
}
}
static inline void F_7 ( struct V_6 * V_7 ,
struct V_17 * V_23 ,
T_1 V_19 , T_1 * V_10 )
{
V_7 -> V_16 += V_19 ;
while ( V_19 ) {
T_1 V_20 = F_5 ( V_19 , V_23 -> V_21 ) ;
T_2 * V_22 = F_6 ( V_23 ) ;
V_7 -> V_15 [ * V_10 ] . V_12 = ( void * ) V_22 ;
V_7 -> V_15 [ * V_10 ] . V_13 = V_20 ;
V_19 -= V_20 ;
++ ( * V_10 ) ;
++ V_23 ;
}
}
static inline T_1 F_8 ( struct V_24 * V_4 , T_1 V_25 ,
T_1 * V_10 )
{
struct V_26 * V_27 = F_9 ( V_4 ) ;
struct V_28 * V_29 = F_10 ( V_27 ) ;
struct V_30 * V_31 = F_11 ( V_4 ) ;
struct V_32 * V_33 = & V_31 -> V_33 ;
T_3 * V_34 = & V_31 -> V_35 ;
T_1 V_9 = F_12 ( V_27 ) ;
struct V_6 * V_7 = & V_31 -> V_36 ;
T_3 * V_37 = NULL ;
V_7 -> V_38 . V_39 . V_40 = 0 ;
V_7 -> V_38 . V_39 . V_41 = V_42 ;
V_7 -> V_38 . V_39 . V_43 = V_44 ;
V_7 -> V_4 . V_45 . V_39 . V_46 = V_47 |
F_13 ( V_42 ) ;
if ( V_25 )
V_7 -> V_4 . V_45 . V_39 . V_48 = 2 ;
else
V_7 -> V_4 . V_45 . V_39 . V_48 = 3 ;
V_7 -> V_4 . V_49 = V_4 -> V_19 ;
V_7 -> V_4 . V_50 = 0 ;
V_33 -> V_25 . V_51 . V_52 . V_53 = V_29 -> V_54 ;
V_33 -> V_25 . V_51 . V_52 . V_55 = V_29 -> V_56 ;
V_33 -> V_25 . V_51 . V_52 . V_57 = V_58 ;
if ( V_29 -> V_54 == V_59 )
memcpy ( V_33 -> V_25 . V_60 , V_29 -> V_61 , V_29 -> V_62 * 2 ) ;
else
memcpy ( V_33 -> V_25 . V_60 , V_29 -> V_61 , V_29 -> V_62 ) ;
V_37 = ( T_3 * ) & V_33 -> V_25 . V_51 . V_63 ;
* V_37 = F_14 ( * V_37 ) ;
* V_34 = F_14 ( ( ( T_3 ) ( V_9 ) << 16 ) ) ;
V_7 -> V_11 [ * V_10 ] . V_12 = ( T_2 * ) V_34 ;
V_7 -> V_11 [ * V_10 ] . V_13 = V_64 ;
V_7 -> V_4 . V_14 += V_64 ;
++ ( * V_10 ) ;
V_7 -> V_11 [ * V_10 ] . V_12 = ( T_2 * ) V_33 ;
V_7 -> V_11 [ * V_10 ] . V_13 = sizeof( struct V_32 ) ;
V_7 -> V_4 . V_14 += sizeof( struct V_32 ) ;
++ ( * V_10 ) ;
return 0 ;
}
static inline T_1 F_15 ( struct V_24 * V_4 , T_1 V_25 ,
T_1 V_9 )
{
struct V_30 * V_31 = F_11 ( V_4 ) ;
struct V_6 * V_7 = & V_31 -> V_36 ;
T_1 V_10 = 0 ;
F_8 ( V_4 , V_25 , & V_10 ) ;
F_2 ( V_7 , V_4 -> V_65 , V_9 , & V_10 ) ;
F_4 ( V_7 , V_4 -> V_66 , V_4 -> V_19 , & V_10 ) ;
V_7 -> V_67 = V_10 ;
return 0 ;
}
static inline void F_16 ( struct V_24 * V_4 ,
struct V_6 * V_7 )
{
V_7 -> V_68 = ( void * ) F_1 ;
V_7 -> V_69 = ( void * ) & V_4 -> V_70 ;
}
static inline void F_17 ( struct V_24 * V_4 ,
T_1 V_9 )
{
struct V_30 * V_31 = F_11 ( V_4 ) ;
struct V_6 * V_7 = & V_31 -> V_36 ;
T_1 V_10 = 0 ;
F_3 ( V_7 , V_4 -> V_65 , V_9 , & V_10 ) ;
F_7 ( V_7 , V_4 -> V_71 , V_4 -> V_19 , & V_10 ) ;
V_7 -> V_72 = V_10 ;
}
static inline int F_18 ( struct V_24 * V_4 , T_1 V_25 )
{
struct V_26 * V_27 = F_9 ( V_4 ) ;
struct V_30 * V_31 = F_11 ( V_4 ) ;
T_1 V_9 = F_12 ( V_27 ) ;
struct V_32 * V_33 = & V_31 -> V_33 ;
struct V_6 * V_7 = & V_31 -> V_36 ;
void * V_73 = NULL ;
int V_1 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
memset ( V_33 , 0 , sizeof( struct V_32 ) ) ;
F_15 ( V_4 , V_25 , V_9 ) ;
F_17 ( V_4 , V_9 ) ;
F_16 ( V_4 , V_7 ) ;
V_73 = V_74 . V_73 [ F_19 () ] ;
V_1 = F_20 ( V_73 , V_7 ) ;
if ( V_1 )
return V_1 ;
else
return - V_75 ;
}
static int F_21 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , true ) ;
}
static int F_22 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , false ) ;
}
static int F_23 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 )
{
struct V_79 * V_27 = F_24 ( V_76 ) ;
struct V_28 * V_29 = F_25 ( V_27 ) ;
int V_80 ;
const T_2 * V_81 = V_77 ;
const T_2 * V_82 = V_77 + ( V_78 / 2 ) ;
V_80 = F_26 ( V_27 , V_77 , V_78 ) ;
if ( V_80 )
return V_80 ;
V_29 -> V_62 = V_78 ;
memcpy ( V_29 -> V_61 , V_81 , V_78 / 2 ) ;
memcpy ( V_29 -> V_61 + V_83 , V_82 , V_78 / 2 ) ;
V_29 -> V_54 = V_59 ;
switch ( V_29 -> V_62 ) {
case 32 :
V_29 -> V_56 = V_84 ;
break;
case 64 :
V_29 -> V_56 = V_85 ;
break;
default:
return - V_86 ;
}
return 0 ;
}
static int F_27 ( struct V_28 * V_29 , T_1 V_78 )
{
if ( ( V_78 == 16 ) || ( V_78 == 24 ) || ( V_78 == 32 ) ) {
V_29 -> V_62 = V_78 ;
switch ( V_29 -> V_62 ) {
case 16 :
V_29 -> V_56 = V_84 ;
break;
case 24 :
V_29 -> V_56 = V_87 ;
break;
case 32 :
V_29 -> V_56 = V_85 ;
break;
default:
return - V_86 ;
}
if ( V_29 -> V_54 == V_88 )
V_29 -> V_56 = 0 ;
return 0 ;
}
return - V_86 ;
}
static int F_28 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 , T_2 V_54 )
{
struct V_79 * V_27 = F_24 ( V_76 ) ;
struct V_28 * V_29 = F_25 ( V_27 ) ;
V_29 -> V_54 = V_54 ;
if ( ! F_27 ( V_29 , V_78 ) ) {
memcpy ( V_29 -> V_61 , V_77 , V_78 ) ;
return 0 ;
} else {
F_29 ( V_76 ,
V_89 ) ;
return - V_86 ;
}
}
static int F_30 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 )
{
return F_28 ( V_76 , V_77 , V_78 , V_90 ) ;
}
static int F_31 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 )
{
return F_28 ( V_76 , V_77 , V_78 , V_91 ) ;
}
static int F_32 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 )
{
return F_28 ( V_76 , V_77 , V_78 , V_92 ) ;
}
static int F_33 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 )
{
return F_28 ( V_76 , V_77 , V_78 , V_88 ) ;
}
static int F_34 ( struct V_26 * V_76 , const T_2 * V_77 ,
T_1 V_78 )
{
return F_28 ( V_76 , V_77 , V_78 , V_93 ) ;
}
static int F_35 ( struct V_79 * V_27 )
{
struct V_28 * V_29 = F_25 ( V_27 ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_27 -> V_94 . V_95 = sizeof( struct V_30 ) +
sizeof( struct V_24 ) ;
return 0 ;
}
static inline int F_36 ( void )
{
int V_80 = 0 ;
V_80 = F_37 ( V_96 , F_38 ( V_96 ) ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static inline void F_39 ( void )
{
F_40 ( V_96 , F_38 ( V_96 ) ) ;
}
int F_41 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_100 ;
T_1 V_101 ;
V_101 = V_74 . V_101 ;
V_74 . V_73 [ V_101 ] = V_98 ;
V_74 . V_101 ++ ;
if ( V_101 == 3 ) {
if ( F_36 () ) {
F_42 ( & V_100 -> V_102 , L_1 ) ;
return - V_86 ;
}
}
return 0 ;
}
void F_43 ( void )
{
T_1 V_101 ;
V_101 = -- V_74 . V_101 ;
if ( ! V_101 )
F_39 () ;
}
