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
T_1 V_26 , T_1 V_27 ,
T_1 * V_10 )
{
struct V_28 * V_29 = F_9 ( V_4 ) ;
struct V_30 * V_31 = F_10 ( V_29 ) ;
struct V_32 * V_33 = F_11 ( V_4 ) ;
struct V_34 * V_35 = & V_33 -> V_35 ;
T_3 * V_36 = & V_33 -> V_37 ;
T_1 V_9 = F_12 ( V_29 ) ;
struct V_6 * V_7 = & V_33 -> V_38 ;
T_3 * V_39 = NULL ;
V_7 -> V_40 . V_41 . V_42 = 0 ;
V_7 -> V_40 . V_41 . V_43 = V_44 ;
V_7 -> V_40 . V_41 . V_45 = V_46 ;
V_7 -> V_4 . V_47 . V_41 . V_48 = V_49 |
F_13 ( V_44 ) ;
if ( V_25 )
V_7 -> V_4 . V_47 . V_41 . V_50 = 2 ;
else
V_7 -> V_4 . V_47 . V_41 . V_50 = 3 ;
V_7 -> V_4 . V_51 = V_4 -> V_19 ;
V_7 -> V_4 . V_52 = 0 ;
V_35 -> V_25 . V_53 . V_54 . V_55 = V_26 ;
V_35 -> V_25 . V_53 . V_54 . V_56 = V_27 ;
V_35 -> V_25 . V_53 . V_54 . V_57 = V_58 ;
if ( V_26 == V_59 )
memcpy ( V_35 -> V_25 . V_60 , V_31 -> V_61 , V_31 -> V_62 * 2 ) ;
else
memcpy ( V_35 -> V_25 . V_60 , V_31 -> V_61 , V_31 -> V_62 ) ;
V_39 = ( T_3 * ) & V_35 -> V_25 . V_53 . V_63 ;
* V_39 = F_14 ( * V_39 ) ;
* V_36 = F_14 ( ( ( T_3 ) ( V_9 ) << 16 ) ) ;
V_7 -> V_11 [ * V_10 ] . V_12 = ( T_2 * ) V_36 ;
V_7 -> V_11 [ * V_10 ] . V_13 = V_64 ;
V_7 -> V_4 . V_14 += V_64 ;
++ ( * V_10 ) ;
V_7 -> V_11 [ * V_10 ] . V_12 = ( T_2 * ) V_35 ;
V_7 -> V_11 [ * V_10 ] . V_13 = sizeof( struct V_34 ) ;
V_7 -> V_4 . V_14 += sizeof( struct V_34 ) ;
++ ( * V_10 ) ;
return 0 ;
}
static inline T_1 F_15 ( struct V_24 * V_4 , T_1 V_25 ,
T_1 V_26 , T_1 V_27 ,
T_1 V_9 )
{
struct V_32 * V_33 = F_11 ( V_4 ) ;
struct V_6 * V_7 = & V_33 -> V_38 ;
T_1 V_10 = 0 ;
F_8 ( V_4 , V_25 , V_26 , V_27 , & V_10 ) ;
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
T_1 V_26 ,
T_1 V_9 )
{
struct V_32 * V_33 = F_11 ( V_4 ) ;
struct V_6 * V_7 = & V_33 -> V_38 ;
T_1 V_10 = 0 ;
F_3 ( V_7 , V_4 -> V_65 , V_9 , & V_10 ) ;
F_7 ( V_7 , V_4 -> V_71 , V_4 -> V_19 , & V_10 ) ;
V_7 -> V_72 = V_10 ;
}
static inline int F_18 ( struct V_24 * V_4 , T_1 V_25 ,
T_1 V_26 )
{
struct V_28 * V_29 = F_9 ( V_4 ) ;
struct V_30 * V_31 = F_10 ( V_29 ) ;
T_1 V_73 = V_74 ;
struct V_32 * V_33 = F_11 ( V_4 ) ;
T_1 V_9 = F_12 ( V_29 ) ;
struct V_34 * V_35 = & V_33 -> V_35 ;
struct V_6 * V_7 = & V_33 -> V_38 ;
void * V_75 = NULL ;
int V_1 ;
switch ( V_31 -> V_62 ) {
case 16 :
V_73 = V_74 ;
break;
case 24 :
V_73 = V_76 ;
break;
case 32 :
if ( V_26 == V_59 )
V_73 = V_74 ;
else
V_73 = V_77 ;
break;
case 64 :
if ( V_26 == V_59 )
V_73 = V_77 ;
else
return - V_78 ;
break;
default:
return - V_78 ;
}
if ( V_26 == V_79 )
V_73 = 0 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
F_15 ( V_4 , V_25 , V_26 , V_73 , V_9 ) ;
F_17 ( V_4 , V_26 , V_9 ) ;
F_16 ( V_4 , V_7 ) ;
V_75 = V_80 . V_75 [ F_19 () ] ;
V_1 = F_20 ( V_75 , V_7 ) ;
if ( V_1 )
return V_1 ;
else
return - V_81 ;
}
int F_21 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , true , V_79 ) ;
}
int F_22 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , false , V_79 ) ;
}
int F_23 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , true , V_59 ) ;
}
int F_24 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , false , V_59 ) ;
}
int F_25 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , true , V_82 ) ;
}
int F_26 ( struct V_24 * V_4 )
{
return F_18 ( V_4 , false , V_82 ) ;
}
int F_27 ( struct V_28 * V_83 , const T_2 * V_84 ,
T_1 V_85 )
{
struct V_86 * V_29 = F_28 ( V_83 ) ;
struct V_30 * V_31 = F_29 ( V_29 ) ;
int V_87 ;
const T_2 * V_88 = V_84 ;
const T_2 * V_89 = V_84 + ( V_85 / 2 ) ;
V_87 = F_30 ( V_29 , V_84 , V_85 ) ;
if ( V_87 )
return V_87 ;
V_31 -> V_62 = V_85 ;
memcpy ( V_31 -> V_61 , V_88 , V_85 / 2 ) ;
memcpy ( V_31 -> V_61 + V_90 , V_89 , V_85 / 2 ) ;
return 0 ;
}
int F_31 ( struct V_28 * V_83 , const T_2 * V_84 ,
T_1 V_85 )
{
struct V_86 * V_29 = F_28 ( V_83 ) ;
struct V_30 * V_31 = F_29 ( V_29 ) ;
if ( ( V_85 == 16 ) || ( V_85 == 24 ) || ( V_85 == 32 ) ) {
V_31 -> V_62 = V_85 ;
memcpy ( V_31 -> V_61 , V_84 , V_85 ) ;
return 0 ;
}
F_32 ( V_83 , V_91 ) ;
return - V_78 ;
}
int F_33 ( struct V_86 * V_29 )
{
struct V_30 * V_31 = F_29 ( V_29 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_29 -> V_92 . V_93 = sizeof( struct V_32 ) +
sizeof( struct V_24 ) ;
return 0 ;
}
static inline int F_34 ( void )
{
int V_87 = 0 ;
V_87 = F_35 ( V_94 , F_36 ( V_94 ) ) ;
if ( V_87 )
return V_87 ;
return 0 ;
}
static inline void F_37 ( void )
{
F_38 ( V_94 , F_36 ( V_94 ) ) ;
}
int F_39 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_98 ;
T_1 V_99 ;
V_99 = V_80 . V_99 ;
V_80 . V_75 [ V_99 ] = V_96 ;
V_80 . V_99 ++ ;
if ( V_99 == 3 ) {
if ( F_34 () ) {
F_40 ( & V_98 -> V_100 , L_1 ) ;
return - V_78 ;
}
}
return 0 ;
}
void F_41 ( void )
{
T_1 V_99 ;
V_99 = -- V_80 . V_99 ;
if ( ! V_99 )
F_37 () ;
}
